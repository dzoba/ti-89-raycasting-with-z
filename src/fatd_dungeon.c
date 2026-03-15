/******************************************************************************
*
* project name:   FAT-Engine Dungeon Crawler - "Descend"
* file name:      fatd_dungeon.c
* description:    Procedurally generated dungeon with height-mapped raycaster,
*                 billboard enemy sprites, and bump combat.
*
******************************************************************************/

#define USE_TI89
#include "includes/fat.h"

#define MAP_W 16
#define MAP_H 16

#define TILE_EMPTY 0
#define TILE_WALL  1
#define TILE_ENEMY 2
#define TILE_EXIT  3

#define STATE_PLAYING  0
#define STATE_NEXTLVL  1
#define STATE_GAMEOVER 2

#define VIEW_WIDTH  96
#define VIEW_HEIGHT 96
#define VIEW_HALF   48
#define STAIR_SCALE 7680

#define MAX_ENEMIES 3
#define MAX_ROOMS   4

#define EYE_HEIGHT 32
#define MAX_STEP_HEIGHT 30
#define MAX_SEGMENTS 6

#define NO_PLAYER_MOVE
#include "utils.c"
#include "indices.h"

/*=============================================================================
 * Data
 *=============================================================================*/

unsigned char dungeon[MAP_W * MAP_H];
unsigned char floor_heights[MAP_W * MAP_H];

short player_z = 0;
short target_z = 0;

typedef struct {
    short distance;
    short screen_top;
    short screen_bot;
    unsigned char shade;
    unsigned short *tex_light;
    unsigned short *tex_dark;
    unsigned char *tex_shade;
} WALL_SEGMENT;

typedef struct {
    short tile_x, tile_y;
    short hp;
    short alive;
} ENEMY;

ENEMY enemies[MAX_ENEMIES];

typedef struct {
    short x, y, w, h;
} ROOM;

short cam_xpos, cam_ypos, cam_orientation;
short current_level;
short player_hp;
short enemies_alive;
short game_state;

short display_offsetx = 0;
short display_offsety = 0;

#define SIDEBAR_X 100
#define MMAP_X SIDEBAR_X
#define MMAP_Y 42
#define MMAP_SCALE 3
static short mmap_prev_ptx = -1, mmap_prev_pty = -1;

unsigned long rng_state;

unsigned short rng_next(void) {
    rng_state = rng_state * 1664525UL + 1013904223UL;
    return (unsigned short)(rng_state >> 16);
}

/*=============================================================================
 * Rendering infrastructure
 *=============================================================================*/

TEXCONFIG wall_textures[2];
TEXCONFIG sprite_tex;   /* soldier "facing toward" texture */

unsigned short render_light[576];
unsigned short render_dark[576];

#define RECIP_SIZE 1024
short recip_wall[RECIP_SIZE];
short recip_tex[256];

void InitRecipTables(void) {
    short i;
    recip_wall[0] = STAIR_SCALE;
    for (i = 1; i < RECIP_SIZE; i++)
        recip_wall[i] = STAIR_SCALE / i;
    recip_tex[0] = 16384;
    for (i = 1; i < 256; i++)
        recip_tex[i] = 16384 / i;
}

unsigned char tex_shades[4096];

void InitTexShades(void) {
    short col, row;
    for (col = 0; col < 64; col++) {
        TEXSTRIP *ts = &wall_textures[0].strips[col >> 4];
        short tex_off = (col & 15) << 2;
        unsigned short *tl, *td;
        unsigned char *dst;
        if (ts->mirrored) tex_off = (15 << 2) - tex_off;
        tl = ts->lightdata + tex_off;
        td = ts->darkdata + tex_off;
        dst = &tex_shades[col << 6];
        for (row = 0; row < 64; row++) {
            short word = row >> 4;
            short bit = 15 - (row & 15);
            dst[row] = (((tl[word] >> bit) & 1) << 1) | ((td[word] >> bit) & 1);
        }
    }
}

unsigned char tex_shades_door[4096];

void InitTexShadesDoor(void) {
    short col, row;
    for (col = 0; col < 64; col++) {
        TEXSTRIP *ts = &wall_textures[1].strips[col >> 4];
        short tex_off = (col & 15) << 2;
        unsigned short *tl, *td;
        unsigned char *dst;
        if (ts->mirrored) tex_off = (15 << 2) - tex_off;
        tl = ts->lightdata + tex_off;
        td = ts->darkdata + tex_off;
        dst = &tex_shades_door[col << 6];
        for (row = 0; row < 64; row++) {
            short word = row >> 4;
            short bit = 15 - (row & 15);
            dst[row] = (((tl[word] >> bit) & 1) << 1) | ((td[word] >> bit) & 1);
        }
    }
}

unsigned char tex_shades_sprite[4096];

void InitTexShadesSprite(void) {
    short col, row;
    for (col = 0; col < 64; col++) {
        TEXSTRIP *ts = &sprite_tex.strips[col >> 4];
        unsigned char *dst = &tex_shades_sprite[col << 6];

        /* No mask or STRIP_IGNORE → entire strip is transparent */
        if (!ts->maskdata || ts->mirrored == 2) {
            for (row = 0; row < 64; row++) dst[row] = 0x80;
        } else {
            short tex_off = (col & 15) << 2;
            unsigned short *tl, *td, *tm;
            if (ts->mirrored == 1) tex_off = (15 << 2) - tex_off;
            tl = ts->lightdata + tex_off;
            td = ts->darkdata + tex_off;
            tm = ts->maskdata + tex_off;
            for (row = 0; row < 64; row++) {
                short word = row >> 4;
                short bit = 15 - (row & 15);
                if (!((tm[word] >> bit) & 1)) {
                    dst[row] = 0x80; /* mask bit clear = transparent */
                } else {
                    unsigned char s = (unsigned char)((((tl[word] >> bit) & 1) << 1) | ((td[word] >> bit) & 1));
                    dst[row] = s ? s : 0x80; /* also treat white as transparent */
                }
            }
        }
    }
}

short col_dist[48];

/* Forward declarations */
short PlayerTurn_dungeon(short orientation, short right, short increment);
static void DrawMinimapTile(short tx, short ty, unsigned short *p0, unsigned short *p1);


/*=============================================================================
 * DrawColumnFast — M68K ASM column renderer
 *=============================================================================*/
static void DrawColumnFast(short col, WALL_SEGMENT *segs, short num_segs)
{
    unsigned short *lp, *dp;
    short byte_col;
    unsigned short mask, nmask;
    short row, s, end;

    byte_col = col >> 4;
    mask  = (unsigned short)3 << (14 - (col & 14));
    nmask = ~mask;

    if (num_segs > 1) {
        short i, j;
        for (i = 1; i < num_segs; i++) {
            WALL_SEGMENT tmp = segs[i];
            j = i - 1;
            while (j >= 0 && segs[j].screen_top > tmp.screen_top) {
                segs[j + 1] = segs[j];
                j--;
            }
            segs[j + 1] = tmp;
        }
    }

    lp = render_light + byte_col;
    dp = render_dark  + byte_col;

    row = 0;
    for (s = 0; s <= num_segs; s++) {
        end = (s < num_segs) ? segs[s].screen_top : VIEW_HEIGHT;
        if (end < 0) end = 0;
        if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;
        {
            short mid = (end < VIEW_HALF) ? end : VIEW_HALF;
            short cnt;
            cnt = mid - row - 1;
            if (cnt >= 0) {
                asm volatile (
                    ".Lsky_%=:\n"
                    "or.w  %2, (%0)\n"
                    "or.w  %2, (%1)\n"
                    "lea   12(%0), %0\n"
                    "lea   12(%1), %1\n"
                    "dbf   %3, .Lsky_%=\n"
                    : "+a"(lp), "+a"(dp)
                    : "d"(mask), "d"(cnt)
                    : "cc", "memory"
                );
                row = mid;
            }
            cnt = end - row - 1;
            if (cnt >= 0) {
                asm volatile (
                    ".Lflr_%=:\n"
                    "and.w %2, (%0)\n"
                    "or.w  %3, (%1)\n"
                    "lea   12(%0), %0\n"
                    "lea   12(%1), %1\n"
                    "dbf   %4, .Lflr_%=\n"
                    : "+a"(lp), "+a"(dp)
                    : "d"(nmask), "d"(mask), "d"(cnt)
                    : "cc", "memory"
                );
                row = end;
            }
        }

        if (s < num_segs) {
            end = segs[s].screen_bot + 1;
            if (end < 0) end = 0;
            if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;

            if (segs[s].tex_light) {
                unsigned char *sp = segs[s].tex_shade;
                short seg_height = segs[s].screen_bot - segs[s].screen_top + 1;
                short tex_v_step;
                short clip_top;
                long tv, tvs;
                short cnt;

                if (seg_height < 1) seg_height = 1;
                tex_v_step = (seg_height < 256) ? recip_tex[seg_height] : (16384 / seg_height);

                clip_top = row - segs[s].screen_top;
                if (clip_top < 0) clip_top = 0;

                tvs = (long)tex_v_step << 8;
                tv = (long)clip_top * tvs;
                cnt = end - row - 1;

                if (cnt >= 0) {
                    asm volatile (
                        "moveq   #1, %%d1\n"
                        ".Ltxlp_%=:\n"
                        "move.l  %2, %%d0\n"
                        "swap    %%d0\n"
                        "and.w   #63, %%d0\n"
                        "move.b  (%4, %%d0.w), %%d0\n"
                        "btst    %%d1, %%d0\n"
                        "beq.s   .Lcl_%=\n"
                        "or.w    %5, (%0)\n"
                        "bra.s   .Ldl_%=\n"
                        ".Lcl_%=:\n"
                        "and.w   %7, (%0)\n"
                        ".Ldl_%=:\n"
                        "btst    #0, %%d0\n"
                        "beq.s   .Lcd_%=\n"
                        "or.w    %5, (%1)\n"
                        "bra.s   .Ldd_%=\n"
                        ".Lcd_%=:\n"
                        "and.w   %7, (%1)\n"
                        ".Ldd_%=:\n"
                        "add.l   %6, %2\n"
                        "lea     12(%0), %0\n"
                        "lea     12(%1), %1\n"
                        "dbf     %3, .Ltxlp_%=\n"
                        : "+a"(lp), "+a"(dp), "+d"(tv), "+d"(cnt)
                        : "a"(sp), "d"(mask), "d"(tvs), "d"(nmask)
                        : "d0", "d1", "cc", "memory"
                    );
                    row = end;
                }
            } else {
                short fcnt = end - row - 1;
                if (fcnt >= 0) {
                    switch (segs[s].shade) {
                    case 0:
                        asm volatile (
                            ".Lfw_%=:\n"
                            "and.w %2, (%0)\n"
                            "and.w %2, (%1)\n"
                            "lea   12(%0), %0\n"
                            "lea   12(%1), %1\n"
                            "dbf   %3, .Lfw_%=\n"
                            : "+a"(lp), "+a"(dp) : "d"(nmask), "d"(fcnt)
                            : "cc", "memory"
                        );
                        break;
                    case 1:
                        asm volatile (
                            ".Lfg_%=:\n"
                            "or.w  %2, (%0)\n"
                            "and.w %3, (%1)\n"
                            "lea   12(%0), %0\n"
                            "lea   12(%1), %1\n"
                            "dbf   %4, .Lfg_%=\n"
                            : "+a"(lp), "+a"(dp) : "d"(mask), "d"(nmask), "d"(fcnt)
                            : "cc", "memory"
                        );
                        break;
                    case 2:
                        asm volatile (
                            ".Lfd_%=:\n"
                            "and.w %2, (%0)\n"
                            "or.w  %3, (%1)\n"
                            "lea   12(%0), %0\n"
                            "lea   12(%1), %1\n"
                            "dbf   %4, .Lfd_%=\n"
                            : "+a"(lp), "+a"(dp) : "d"(nmask), "d"(mask), "d"(fcnt)
                            : "cc", "memory"
                        );
                        break;
                    default:
                        asm volatile (
                            ".Lfb_%=:\n"
                            "or.w  %2, (%0)\n"
                            "or.w  %2, (%1)\n"
                            "lea   12(%0), %0\n"
                            "lea   12(%1), %1\n"
                            "dbf   %3, .Lfb_%=\n"
                            : "+a"(lp), "+a"(dp) : "d"(mask), "d"(fcnt)
                            : "cc", "memory"
                        );
                        break;
                    }
                    row = end;
                }
            }
        }
    }
}


/*=============================================================================
 * RenderDungeon — height-mapped DDA raycaster
 *=============================================================================*/
void RenderDungeon(void)
{
    short column;
    short angle;
    short eye_z, eye_z_top;
    volatile short *tab_xstep;
    volatile short *tab_ystep;
    volatile short *tab_div_tan;
    volatile short *tab_tan;
    volatile short *tab_div_sin;
    short xpos_grid, ypos_grid;
    short player_fh;
    short maxwidth, maxheight;
    WALL_SEGMENT segments[MAX_SEGMENTS];
    short c;

    tab_xstep   = FAT_Get64DivTanTab();
    tab_ystep   = FAT_Get64TanTab();
    tab_div_tan = FAT_Get256DivTanTab();
    tab_tan     = FAT_Get256TanTab();
    tab_div_sin = FAT_Get128DivSinTab();

    eye_z = player_z + EYE_HEIGHT;
    eye_z_top = eye_z - 64;

    xpos_grid = cam_xpos & 0xFFC0;
    ypos_grid = cam_ypos & 0xFFC0;
    maxwidth  = MAP_W << 6;
    maxheight = MAP_H << 6;
    {
        short ptx = cam_xpos >> 6;
        short pty = cam_ypos >> 6;
        if (ptx >= 0 && ptx < MAP_W && pty >= 0 && pty < MAP_H)
            player_fh = (short)floor_heights[(pty << 4) + ptx];
        else
            player_fh = 0;
    }

    for (c = 0; c < 48; c++) col_dist[c] = MAX_DISTANCE;

    angle = cam_orientation - ANGLE_030;
    if (angle < ANGLE_000) angle += ANGLE_360;

    for (column = 0; column < VIEW_WIDTH; column += 2) {
        short h_x, h_y, h_sx, h_sy;
        short v_x, v_y, v_sx, v_sy;
        short use_cos, divsin_val, divcos_val;
        long first_hit;
        short ray_angle;
        short num_segments;
        short top_drawn;

        num_segments = 0;
        top_drawn = VIEW_HEIGHT;
        ray_angle = angle;

        if (ray_angle < 0) ray_angle += ANGLE_360;
        if (ray_angle >= ANGLE_360) ray_angle -= ANGLE_360;

        /* Horizontal intersection setup */
        if (ray_angle == ANGLE_000 || ray_angle == ANGLE_180) {
            h_x = cam_xpos; h_y = cam_ypos; h_sx = 0; h_sy = 0;
        }
        else if (ray_angle < ANGLE_090) {
            h_y = ypos_grid + 64;
            first_hit = (long)(short)tab_div_tan[ray_angle] * (short)(h_y - cam_ypos);
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = tab_xstep[ray_angle];
            h_sy = 64;
        }
        else if (ray_angle < ANGLE_180) {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_090);
            h_y = ypos_grid + 64;
            first_hit = -((long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos));
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = -tab_xstep[idx];
            h_sy = 64;
        }
        else if (ray_angle < ANGLE_270) {
            short idx = ray_angle - ANGLE_180;
            h_y = ypos_grid - 1;
            first_hit = (long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos);
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = -tab_xstep[idx];
            h_sy = -64;
        }
        else {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_270);
            h_y = ypos_grid - 1;
            first_hit = -((long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos));
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = tab_xstep[idx];
            h_sy = -64;
        }

        /* Vertical intersection setup */
        if (ray_angle == ANGLE_090 || ray_angle == ANGLE_270) {
            v_x = cam_xpos; v_y = cam_ypos; v_sx = 0; v_sy = 0;
        }
        else if (ray_angle < ANGLE_090) {
            v_x = xpos_grid + 64;
            first_hit = (long)(short)tab_tan[ray_angle] * (short)(v_x - cam_xpos);
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = 64;
            v_sy = tab_ystep[ray_angle];
        }
        else if (ray_angle < ANGLE_180) {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_090);
            v_x = xpos_grid - 1;
            first_hit = -((long)(short)tab_tan[idx] * (short)(v_x - cam_xpos));
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = -64;
            v_sy = tab_ystep[idx];
        }
        else if (ray_angle < ANGLE_270) {
            short idx = ray_angle - ANGLE_180;
            v_x = xpos_grid - 1;
            first_hit = (long)(short)tab_tan[idx] * (short)(v_x - cam_xpos);
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = -64;
            v_sy = -tab_ystep[idx];
        }
        else {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_270);
            v_x = xpos_grid + 64;
            first_hit = -((long)(short)tab_tan[idx] * (short)(v_x - cam_xpos));
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = 64;
            v_sy = -tab_ystep[idx];
        }

        /* Distance calculation setup */
        if (ray_angle < ANGLE_090) {
            use_cos = (ray_angle < ANGLE_045) ? 1 : 0;
            divsin_val = tab_div_sin[ray_angle];
            divcos_val = tab_div_sin[ANGLE_090 - 1 - ray_angle];
        }
        else if (ray_angle < ANGLE_180) {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_090);
            use_cos = (ray_angle < ANGLE_045 + ANGLE_090) ? 0 : 1;
            divsin_val = tab_div_sin[idx];
            divcos_val = -tab_div_sin[ray_angle - ANGLE_090];
        }
        else if (ray_angle < ANGLE_270) {
            short idx = ray_angle - ANGLE_180;
            use_cos = (ray_angle < ANGLE_045 + ANGLE_180) ? 1 : 0;
            divsin_val = -tab_div_sin[idx];
            divcos_val = -tab_div_sin[ANGLE_090 - 1 - idx];
        }
        else {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_270);
            use_cos = (ray_angle < ANGLE_045 + ANGLE_270) ? 0 : 1;
            divsin_val = -tab_div_sin[idx];
            divcos_val = tab_div_sin[ray_angle - ANGLE_270];
        }

        /* DDA march */
        {
            short h_dist, v_dist;
            short h_valid = 1, v_valid = 1;
            short prev_fh;
            short max_iters = 10;

            prev_fh = player_fh;

            if (ray_angle == ANGLE_000 || ray_angle == ANGLE_180) h_valid = 0;
            if (ray_angle == ANGLE_090 || ray_angle == ANGLE_270) v_valid = 0;

            h_dist = MAX_DISTANCE;
            v_dist = MAX_DISTANCE;
            if (h_valid) {
                if ((unsigned short)h_x < (unsigned short)maxwidth &&
                    (unsigned short)h_y < (unsigned short)maxheight) {
                    if (use_cos) h_dist = (short)((((long)(h_x - cam_xpos)) * (long)divcos_val) >> 7L);
                    else         h_dist = (short)((((long)(h_y - cam_ypos)) * (long)divsin_val) >> 7L);
                    if (h_dist < 0) h_dist = -h_dist;
                } else {
                    h_valid = 0;
                }
            }
            if (v_valid) {
                if ((unsigned short)v_x < (unsigned short)maxwidth &&
                    (unsigned short)v_y < (unsigned short)maxheight) {
                    if (use_cos) v_dist = (short)((((long)(v_x - cam_xpos)) * (long)divcos_val) >> 7L);
                    else         v_dist = (short)((((long)(v_y - cam_ypos)) * (long)divsin_val) >> 7L);
                    if (v_dist < 0) v_dist = -v_dist;
                } else {
                    v_valid = 0;
                }
            }

            while (num_segments < MAX_SEGMENTS && top_drawn > 0 && max_iters-- > 0) {
                short hit_x, hit_y, hit_dist;
                short hit_h;
                short tile_x, tile_y;
                unsigned char tile_type;
                short tile_fh;

                if (!h_valid && !v_valid) break;

                if (h_dist <= v_dist && h_valid) {
                    hit_x = h_x; hit_y = h_y; hit_dist = h_dist;
                    hit_h = 1;
                    tile_x = hit_x >> 6;
                    tile_y = hit_y >> 6;
                    h_x += h_sx;
                    h_y += h_sy;
                    if ((unsigned short)h_x < (unsigned short)maxwidth &&
                        (unsigned short)h_y < (unsigned short)maxheight) {
                        if (use_cos) h_dist = (short)((((long)(h_x - cam_xpos)) * (long)divcos_val) >> 7L);
                        else         h_dist = (short)((((long)(h_y - cam_ypos)) * (long)divsin_val) >> 7L);
                        if (h_dist < 0) h_dist = -h_dist;
                    } else {
                        h_valid = 0;
                        h_dist = MAX_DISTANCE;
                    }
                } else if (v_valid) {
                    hit_x = v_x; hit_y = v_y; hit_dist = v_dist;
                    hit_h = 0;
                    tile_x = hit_x >> 6;
                    tile_y = hit_y >> 6;
                    v_x += v_sx;
                    v_y += v_sy;
                    if ((unsigned short)v_x < (unsigned short)maxwidth &&
                        (unsigned short)v_y < (unsigned short)maxheight) {
                        if (use_cos) v_dist = (short)((((long)(v_x - cam_xpos)) * (long)divcos_val) >> 7L);
                        else         v_dist = (short)((((long)(v_y - cam_ypos)) * (long)divsin_val) >> 7L);
                        if (v_dist < 0) v_dist = -v_dist;
                    } else {
                        v_valid = 0;
                        v_dist = MAX_DISTANCE;
                    }
                } else {
                    break;
                }

                if ((unsigned short)tile_x >= MAP_W ||
                    (unsigned short)tile_y >= MAP_H)
                    continue;

                {
                    short tile_idx = (tile_y << 4) + tile_x;
                    tile_type = dungeon[tile_idx];
                    tile_fh   = (short)floor_heights[tile_idx];
                }

                if (tile_type == TILE_WALL || tile_type == TILE_EXIT) {
                    /* Full wall — stop ray */
                    short wall_height;
                    short screen_top_w, screen_bot_w;

                    if (hit_dist <= 0) hit_dist = 1;
                    wall_height = (hit_dist < RECIP_SIZE) ? recip_wall[hit_dist] : (STAIR_SCALE / hit_dist);

                    screen_top_w = VIEW_HALF - (wall_height >> 1);
                    screen_bot_w = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * (long)wall_height) >> 6);

                    if (screen_bot_w >= top_drawn) screen_bot_w = top_drawn - 1;

                    if (screen_top_w < screen_bot_w && num_segments < MAX_SEGMENTS) {
                        segments[num_segments].distance   = hit_dist;
                        segments[num_segments].screen_top = screen_top_w;
                        segments[num_segments].screen_bot = screen_bot_w;

                        if (tile_type == TILE_WALL) {
                            short texidx;
                            TEXSTRIP *ts;
                            short tex_off;

                            if (hit_dist < 150)       segments[num_segments].shade = 0;
                            else if (hit_dist < 400)  segments[num_segments].shade = 1;
                            else                      segments[num_segments].shade = 3;

                            if (hit_h) {
                                texidx = hit_x & 0x3F;
                                if (h_sy < 0) texidx = 63 - texidx;
                            } else {
                                texidx = hit_y & 0x3F;
                                if (v_sx >= 0) texidx = 63 - texidx;
                            }
                            ts = &wall_textures[0].strips[texidx >> 4];
                            tex_off = (texidx & 15) << 2;
                            if (ts->mirrored) tex_off = (15 << 2) - tex_off;

                            segments[num_segments].tex_light = ts->lightdata + tex_off;
                            segments[num_segments].tex_dark  = ts->darkdata + tex_off;
                            segments[num_segments].tex_shade = &tex_shades[texidx << 6];
                        } else {
                            /* TILE_EXIT: textured door */
                            short texidx_d;
                            TEXSTRIP *ts_d;
                            short tex_off_d;

                            if (hit_dist < 150)       segments[num_segments].shade = 0;
                            else if (hit_dist < 400)  segments[num_segments].shade = 1;
                            else                      segments[num_segments].shade = 3;

                            if (hit_h) {
                                texidx_d = hit_x & 0x3F;
                                if (h_sy < 0) texidx_d = 63 - texidx_d;
                            } else {
                                texidx_d = hit_y & 0x3F;
                                if (v_sx >= 0) texidx_d = 63 - texidx_d;
                            }
                            ts_d = &wall_textures[1].strips[texidx_d >> 4];
                            tex_off_d = (texidx_d & 15) << 2;
                            if (ts_d->mirrored) tex_off_d = (15 << 2) - tex_off_d;

                            segments[num_segments].tex_light = ts_d->lightdata + tex_off_d;
                            segments[num_segments].tex_dark  = ts_d->darkdata + tex_off_d;
                            segments[num_segments].tex_shade = &tex_shades_door[texidx_d << 6];
                        }

                        num_segments++;
                        if (screen_top_w < top_drawn) top_drawn = screen_top_w;
                    }

                    col_dist[column >> 1] = hit_dist;
                    break;
                }
                else if (tile_fh != prev_fh) {
                    /* Floor height change — render step wall */
                    short wall_height;
                    short screen_top_s, screen_bot_s;

                    if (hit_dist <= 0) hit_dist = 1;
                    wall_height = (hit_dist < RECIP_SIZE) ? recip_wall[hit_dist] : (STAIR_SCALE / hit_dist);

                    if (tile_fh > prev_fh) {
                        screen_top_s = VIEW_HALF + (short)(((long)(eye_z - tile_fh) * wall_height) >> 6);
                        screen_bot_s = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * wall_height) >> 6);
                    } else {
                        screen_top_s = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * wall_height) >> 6);
                        screen_bot_s = VIEW_HALF + (short)(((long)(eye_z - tile_fh) * wall_height) >> 6);
                    }

                    if (screen_bot_s >= top_drawn) screen_bot_s = top_drawn - 1;

                    if (screen_top_s < screen_bot_s && num_segments < MAX_SEGMENTS) {
                        segments[num_segments].distance   = hit_dist;
                        segments[num_segments].screen_top = screen_top_s;
                        segments[num_segments].screen_bot = screen_bot_s;
                        segments[num_segments].shade      = 1;
                        segments[num_segments].tex_light  = 0;
                        segments[num_segments].tex_dark   = 0;
                        segments[num_segments].tex_shade  = 0;
                        num_segments++;
                        if (screen_top_s < top_drawn) top_drawn = screen_top_s;
                    }

                    prev_fh = tile_fh;
                }
                else {
                    prev_fh = tile_fh;
                }
            }
        }

        DrawColumnFast(column, segments, num_segments);

        angle += 2;
        if (angle >= ANGLE_360) angle -= ANGLE_360;
    }
}


/*=============================================================================
 * RenderBillboards — draw enemy sprites over render buffers
 *=============================================================================*/
void RenderBillboards(void)
{
    short i;
    short eye_z = player_z + EYE_HEIGHT;
    short cos_a = FAT_Cos16384(cam_orientation);
    short sin_a = FAT_Sin16384(cam_orientation);

    for (i = 0; i < MAX_ENEMIES; i++) {
        short dx, dy, screen_x, sprite_h, sprite_half, sprite_w;
        long fwd, side;
        short j, col_start, col_start_raw, col_end;
        short enemy_fh, sprite_center_y, sprite_top, sprite_bot;
        short sprite_top_raw, sprite_bot_raw, raw_height;
        short fwd_s, side_s;

        if (!enemies[i].alive) continue;

        dx = (enemies[i].tile_x * 64 + 32) - cam_xpos;
        dy = (enemies[i].tile_y * 64 + 32) - cam_ypos;

        fwd  = (long)dx * cos_a + (long)dy * sin_a;
        side = (long)dy * cos_a - (long)dx * sin_a;
        fwd_s  = (short)(fwd >> 14);
        side_s = (short)(side >> 14);

        if (fwd_s <= 4) continue;

        screen_x = VIEW_HALF + (short)((long)side_s * VIEW_HALF / fwd_s);
        sprite_h = (short)(STAIR_SCALE / fwd_s);

        enemy_fh = (short)floor_heights[(enemies[i].tile_y << 4) + enemies[i].tile_x];
        sprite_center_y = VIEW_HALF + (short)(((long)(eye_z - enemy_fh - 32) * sprite_h) >> 6);
        sprite_half = sprite_h >> 1;
        sprite_top_raw = sprite_center_y - sprite_half;
        sprite_bot_raw = sprite_center_y + sprite_half;
        sprite_top = sprite_top_raw;
        sprite_bot = sprite_bot_raw;

        if (sprite_top < 0) sprite_top = 0;
        if (sprite_bot >= VIEW_HEIGHT) sprite_bot = VIEW_HEIGHT - 1;
        if (sprite_top >= sprite_bot) continue;

        raw_height = sprite_bot_raw - sprite_top_raw + 1;
        if (raw_height < 1) raw_height = 1;

        /* Width matches height (square sprite), even-aligned */
        sprite_w = sprite_h;
        if (sprite_w < 4) sprite_w = 4;
        sprite_w = (sprite_w + 1) & ~1;

        col_start_raw = (screen_x - sprite_w / 2) & ~1;
        col_start = col_start_raw;
        col_end = col_start_raw + sprite_w;
        if (col_start < 0) col_start = 0;
        if (col_end > VIEW_WIDTH) col_end = VIEW_WIDTH;

        for (j = col_start; j < col_end; j += 2) {
            short ci = j >> 1;
            short byte_col, row;
            short tex_col, clip_top, tex_v_step;
            unsigned short mask, nmask;
            unsigned short *lp, *dp;
            unsigned char *sp;
            long tvs, tv;

            if (ci < 48 && col_dist[ci] < fwd_s) continue;

            /* Texture column from horizontal position in sprite (use raw for correct UV when clipped) */
            tex_col = (short)(((long)(j - col_start_raw) * 64) / sprite_w);
            if (tex_col > 63) tex_col = 63;
            sp = &tex_shades_sprite[tex_col << 6];

            /* Texture V stepping with top-clip offset */
            tex_v_step = (raw_height < 256) ? recip_tex[raw_height] : (16384 / raw_height);
            tvs = (long)tex_v_step << 8;
            clip_top = sprite_top - sprite_top_raw;
            if (clip_top < 0) clip_top = 0;
            tv = (long)clip_top * tvs;

            byte_col = j >> 4;
            mask = (unsigned short)3 << (14 - (j & 14));
            nmask = ~mask;

            lp = render_light + byte_col + sprite_top * 6;
            dp = render_dark  + byte_col + sprite_top * 6;

            for (row = sprite_top; row <= sprite_bot; row++) {
                unsigned char shade = sp[(tv >> 16) & 63];
                if (shade && !(shade & 0x80)) {
                    /* Visible pixel: skip transparent (0x80) and white (0) */
                    if (shade & 2) *lp |= mask; else *lp &= nmask;
                    if (shade & 1) *dp |= mask; else *dp &= nmask;
                }
                tv += tvs;
                lp += 6;
                dp += 6;
            }
        }
    }
}


/*=============================================================================
 * CopyToLCD — ASM double-buffer blit
 *=============================================================================*/
void CopyToLCD(void) {
    unsigned long *lcd_l = (unsigned long*)((unsigned short*)GetPlane(LIGHT_PLANE) + 15);
    unsigned long *lcd_d = (unsigned long*)((unsigned short*)GetPlane(DARK_PLANE)  + 15);
    unsigned long *bl = (unsigned long*)render_light;
    unsigned long *bd = (unsigned long*)render_dark;
    short cnt = 95;
    asm volatile (
        ".Lcopy_%=:\n"
        "move.l  (%2)+, (%0)\n"
        "move.l  (%2)+, 4(%0)\n"
        "move.l  (%2)+, 8(%0)\n"
        "move.l  (%3)+, (%1)\n"
        "move.l  (%3)+, 4(%1)\n"
        "move.l  (%3)+, 8(%1)\n"
        "lea     30(%0), %0\n"
        "lea     30(%1), %1\n"
        "dbf     %4, .Lcopy_%=\n"
        : "+a"(lcd_l), "+a"(lcd_d), "+a"(bl), "+a"(bd), "+d"(cnt)
        :
        : "cc", "memory"
    );
}


/*=============================================================================
 * Dungeon generation with height variation
 *=============================================================================*/
void GenerateLevel(short level) {
    ROOM rooms[MAX_ROOMS];
    short num_rooms;
    short i, x, y;
    short ex, ey;

    memset(dungeon, TILE_WALL, MAP_W * MAP_H);
    memset(floor_heights, 0, MAP_W * MAP_H);

    for (i = 0; i < MAX_ENEMIES; i++)
        enemies[i].alive = 0;
    enemies_alive = 0;

    /* Place 3-4 rooms (all at height 0) */
    num_rooms = 3 + (rng_next() % 2);
    for (i = 0; i < num_rooms; i++) {
        short rw = 2 + (rng_next() % 3);
        short rh = 2 + (rng_next() % 3);
        short rx = 1 + (rng_next() % (MAP_W - rw - 2));
        short ry = 1 + (rng_next() % (MAP_H - rh - 2));
        rooms[i].x = rx;
        rooms[i].y = ry;
        rooms[i].w = rw;
        rooms[i].h = rh;

        for (y = ry; y < ry + rh; y++)
            for (x = rx; x < rx + rw; x++)
                dungeon[(y << 4) + x] = TILE_EMPTY;
    }

    /* Connect rooms with L-shaped corridors (all at height 0) */
    for (i = 0; i < num_rooms - 1; i++) {
        short cx1 = rooms[i].x + rooms[i].w / 2;
        short cy1 = rooms[i].y + rooms[i].h / 2;
        short cx2 = rooms[i+1].x + rooms[i+1].w / 2;
        short cy2 = rooms[i+1].y + rooms[i+1].h / 2;
        short xs = (cx1 < cx2) ? cx1 : cx2;
        short xe = (cx1 < cx2) ? cx2 : cx1;
        short ys = (cy1 < cy2) ? cy1 : cy2;
        short ye = (cy1 < cy2) ? cy2 : cy1;

        for (x = xs; x <= xe; x++)
            dungeon[(cy1 << 4) + x] = TILE_EMPTY;
        for (y = ys; y <= ye; y++)
            dungeon[(y << 4) + cx2] = TILE_EMPTY;
    }

    /* Add stairs to 1-2 corridors (triangle wave: ramp up to 15, back down) */
    {
        short num_stairs = 1 + (rng_next() % 2);
        short stair_start = rng_next() % (num_rooms - 1);
        short s;
        for (s = 0; s < num_stairs && s < num_rooms - 1; s++) {
            short ci = (stair_start + s) % (num_rooms - 1);
            short cx1 = rooms[ci].x + rooms[ci].w / 2;
            short cy1 = rooms[ci].y + rooms[ci].h / 2;
            short cx2 = rooms[ci+1].x + rooms[ci+1].w / 2;
            short cy2 = rooms[ci+1].y + rooms[ci+1].h / 2;
            short xs = (cx1 < cx2) ? cx1 : cx2;
            short xe = (cx1 < cx2) ? cx2 : cx1;
            short ys = (cy1 < cy2) ? cy1 : cy2;
            short ye = (cy1 < cy2) ? cy2 : cy1;
            short total_len = (xe - xs) + (ye - ys) + 1;
            short k = 0;

            if (total_len < 4) continue;

            for (x = xs; x <= xe; x++) {
                short dist = k;
                short h;
                if (total_len - k < dist) dist = total_len - k;
                if (dist < 0) dist = 0;
                h = dist * 5;
                if (h > 15) h = 15;
                floor_heights[(cy1 << 4) + x] = (unsigned char)h;
                k++;
            }
            for (y = ys; y <= ye; y++) {
                short dist = k;
                short h;
                if (total_len - k < dist) dist = total_len - k;
                if (dist < 0) dist = 0;
                h = dist * 5;
                if (h > 15) h = 15;
                floor_heights[(y << 4) + cx2] = (unsigned char)h;
                k++;
            }
        }

        /* Force room tiles back to height 0 (stairs only in corridors) */
        for (i = 0; i < num_rooms; i++)
            for (y = rooms[i].y; y < rooms[i].y + rooms[i].h; y++)
                for (x = rooms[i].x; x < rooms[i].x + rooms[i].w; x++)
                    floor_heights[(y << 4) + x] = 0;
    }

    /* Player spawn in first room center */
    cam_xpos = (rooms[0].x + rooms[0].w / 2) * 64 + 32;
    cam_ypos = (rooms[0].y + rooms[0].h / 2) * 64 + 32;
    cam_orientation = ANGLE_NORTH;
    player_z = 0;
    target_z = 0;

    /* Exit in last room center */
    ex = rooms[num_rooms - 1].x + rooms[num_rooms - 1].w / 2;
    ey = rooms[num_rooms - 1].y + rooms[num_rooms - 1].h / 2;
    dungeon[(ey << 4) + ex] = TILE_EXIT;

    /* Place 2-3 enemies in non-spawn rooms */
    {
        short num_enemies = 2 + (rng_next() % 2);
        for (i = 0; i < num_enemies && i < MAX_ENEMIES; i++) {
            short attempts = 50;
            while (attempts-- > 0) {
                short ri = 1 + (rng_next() % (num_rooms - 1));
                short tx = rooms[ri].x + (rng_next() % rooms[ri].w);
                short ty = rooms[ri].y + (rng_next() % rooms[ri].h);
                short idx = (ty << 4) + tx;
                if (dungeon[idx] == TILE_EMPTY) {
                    dungeon[idx] = TILE_ENEMY;
                    enemies[i].tile_x = tx;
                    enemies[i].tile_y = ty;
                    enemies[i].hp = 2;
                    enemies[i].alive = 1;
                    enemies_alive++;
                    break;
                }
            }
        }
    }

    current_level = level;
}


/*=============================================================================
 * Player movement with bump combat and height checking
 *=============================================================================*/
void PlayerMoveDungeon(short forward_right, short strafe) {
    short tmp_angle, stepx, stepy, newxpos, newypos, newxmod, newymod;
    unsigned char tile;
    short idx;
    unsigned char new_fh, old_fh;
    short height_diff;

    tmp_angle = cam_orientation + (strafe ? ANGLE_090 : 0);
    stepx = FAT_Cos16384(tmp_angle) >> 11;
    stepy = FAT_Sin16384(tmp_angle) >> 11;
    newxpos = cam_xpos + (forward_right ? stepx : -stepx);
    newypos = cam_ypos + (forward_right ? stepy : -stepy);
    newxmod = newxpos >> 6;
    newymod = newypos >> 6;

    if ((unsigned short)newxmod >= (unsigned short)MAP_W ||
        (unsigned short)newymod >= (unsigned short)MAP_H)
        return;

    idx = (newymod << 4) + newxmod;
    tile = dungeon[idx];

    if (tile == TILE_WALL) return;

    if (tile == TILE_ENEMY) {
        short i;
        for (i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].alive &&
                enemies[i].tile_x == newxmod &&
                enemies[i].tile_y == newymod)
            {
                enemies[i].hp--;
                player_hp--;
                if (enemies[i].hp <= 0) {
                    enemies[i].alive = 0;
                    dungeon[idx] = TILE_EMPTY;
                    enemies_alive--;
                    {
                        unsigned short *mp0 = (unsigned short *)GetPlane(LIGHT_PLANE);
                        unsigned short *mp1 = (unsigned short *)GetPlane(DARK_PLANE);
                        DrawMinimapTile(newxmod, newymod, mp0, mp1);
                    }
                    /* Move into cleared tile */
                    old_fh = floor_heights[((cam_ypos >> 6) << 4) + (cam_xpos >> 6)];
                    new_fh = floor_heights[idx];
                    height_diff = (short)new_fh - (short)old_fh;
                    if (height_diff <= MAX_STEP_HEIGHT) {
                        cam_xpos = newxpos;
                        cam_ypos = newypos;
                        target_z = (short)new_fh;
                    }
                }
                if (player_hp <= 0) {
                    game_state = STATE_GAMEOVER;
                }
                return;
            }
        }
        return;
    }

    if (tile == TILE_EXIT) {
        game_state = STATE_NEXTLVL;
        return;
    }

    /* TILE_EMPTY: height check then move */
    old_fh = floor_heights[((cam_ypos >> 6) << 4) + (cam_xpos >> 6)];
    new_fh = floor_heights[idx];
    height_diff = (short)new_fh - (short)old_fh;
    if (height_diff > MAX_STEP_HEIGHT)
        return;

    cam_xpos = newxpos;
    cam_ypos = newypos;
    target_z = (short)new_fh;
}

short PlayerTurn_dungeon(short orientation, short right, short increment) {
    orientation += right ? increment : -increment;
    return FAT_ClampAngle(orientation);
}


/*=============================================================================
 * Sidebar label rendering (5x7 pixel characters, XOR'd onto dark plane)
 *=============================================================================*/
static const unsigned char label_L[7] = {0x80,0x80,0x80,0x80,0x80,0x80,0xF8};
static const unsigned char label_V[7] = {0x88,0x88,0x88,0x50,0x50,0x20,0x20};
static const unsigned char label_H[7] = {0x88,0x88,0x88,0xF8,0x88,0x88,0x88};
static const unsigned char label_P[7] = {0xF0,0x88,0x88,0xF0,0x80,0x80,0x80};

static void DrawLabelChar(short x, short y, const unsigned char *data) {
    long addr = (long)GetPlane(DARK_PLANE) + (y << 5) - (y << 1) + ((x >> 3) & 0xfffe);
    unsigned short cnt = 24 - (x & 15);
    short i;
    for (i = 0; i < 7; i++) {
        *(long*)addr ^= (long)data[i] << cnt;
        addr += 30;
    }
}

/*=============================================================================
 * GUI initialization and update
 *=============================================================================*/
void InitDungeonGUI(COUNTER *lvl_ctr, COUNTER *hp_ctr) {
    short row;
    unsigned short *lp, *dp;

    memset(GetPlane(LIGHT_PLANE), 0, LCD_SIZE);
    memset(GetPlane(DARK_PLANE), 0xFF, LCD_SIZE);

    lp = (unsigned short*)GetPlane(LIGHT_PLANE) + 6;
    dp = (unsigned short*)GetPlane(DARK_PLANE)  + 6;
    for (row = 0; row < 100; row++) {
        *lp |= 0xC000;
        *dp |= 0xC000;
        lp += 15; dp += 15;
    }

    /* "LVL" label */
    DrawLabelChar(SIDEBAR_X, 2, label_L);
    DrawLabelChar(SIDEBAR_X + 6, 2, label_V);
    DrawLabelChar(SIDEBAR_X + 12, 2, label_L);

    InitCounter(lvl_ctr, SIDEBAR_X, 10, 3, 1);
    DrawCounter(lvl_ctr);

    /* "HP" label */
    DrawLabelChar(SIDEBAR_X, 20, label_H);
    DrawLabelChar(SIDEBAR_X + 6, 20, label_P);

    InitCounter(hp_ctr, SIDEBAR_X, 28, 2, 10);
    DrawCounter(hp_ctr);
}

void UpdateLevelCounter(COUNTER *ctr, short level) {
    short i;
    unsigned long val = (unsigned long)level;
    for (i = 2; i >= 0; i--) {
        ctr->newcount[i] = val % 10;
        val /= 10;
    }
    DrawCounter(ctr);
}

void UpdateHPCounter(COUNTER *ctr, short hp) {
    short i;
    unsigned long val = (hp > 0) ? (unsigned long)hp : 0;
    for (i = 1; i >= 0; i--) {
        ctr->newcount[i] = val % 10;
        val /= 10;
    }
    DrawCounter(ctr);
}

/*=============================================================================
 * Minimap
 *=============================================================================*/
static void DrawMinimapTile(short tx, short ty, unsigned short *p0, unsigned short *p1) {
    unsigned char tile = dungeon[(ty << 4) + tx];
    short lv, dv, px, py;
    switch (tile) {
        case TILE_WALL:  lv = 1; dv = 1; break;
        case TILE_EXIT:  lv = 1; dv = 0; break;
        case TILE_ENEMY: lv = 0; dv = 1; break;
        default:         lv = 0; dv = 0; break;
    }
    for (py = 0; py < MMAP_SCALE; py++) {
        for (px = 0; px < MMAP_SCALE; px++) {
            short sx = MMAP_X + tx * MMAP_SCALE + px;
            short sy = MMAP_Y + ty * MMAP_SCALE + py;
            short word = sy * 15 + (sx >> 4);
            unsigned short mask = (unsigned short)1 << (15 - (sx & 15));
            if (lv) p0[word] |= mask; else p0[word] &= ~mask;
            if (dv) p1[word] |= mask; else p1[word] &= ~mask;
        }
    }
}

static void DrawMinimap(void) {
    unsigned short *p0 = (unsigned short *)GetPlane(LIGHT_PLANE);
    unsigned short *p1 = (unsigned short *)GetPlane(DARK_PLANE);
    short tx, ty;
    for (ty = 0; ty < MAP_H; ty++)
        for (tx = 0; tx < MAP_W; tx++)
            DrawMinimapTile(tx, ty, p0, p1);
    mmap_prev_ptx = -1;
    mmap_prev_pty = -1;
}

static void UpdateMinimapPlayer(void) {
    unsigned short *p0 = (unsigned short *)GetPlane(LIGHT_PLANE);
    unsigned short *p1 = (unsigned short *)GetPlane(DARK_PLANE);
    short ptx = cam_xpos >> 6;
    short pty = cam_ypos >> 6;
    short px, py;

    /* Always restore old tile (needed for blink-off phase) */
    if (mmap_prev_ptx >= 0)
        DrawMinimapTile(mmap_prev_ptx, mmap_prev_pty, p0, p1);

    /* Fast blink: black dot on even phases, tile color on odd */
    if (int5_counter & 2) {
        for (py = 0; py < MMAP_SCALE; py++) {
            for (px = 0; px < MMAP_SCALE; px++) {
                short sx = MMAP_X + ptx * MMAP_SCALE + px;
                short sy = MMAP_Y + pty * MMAP_SCALE + py;
                short word = sy * 15 + (sx >> 4);
                unsigned short mask = (unsigned short)1 << (15 - (sx & 15));
                p0[word] |= mask;
                p1[word] |= mask;
            }
        }
    }

    mmap_prev_ptx = ptx;
    mmap_prev_pty = pty;
}


/*=============================================================================
 * Main function
 *=============================================================================*/
void _main(void) {
    PADSTATES      key = 0;
    short          result;
    LCD_BUFFER     lcd;
    COUNTER        lvl_display, hp_display;
    HANDLE         texfile = H_NULL;
    unsigned char *texsrc = 0;
    short          turn_hold = 0;

    if ((result = FAT_LoadEngine()) != FAT_LOADOKAY) {
        switch (result) {
            case FAT_NOTGHOSTSPACE: ST_helpMsg("ERROR: not ghostspace!"); break;
            case FAT_NOTFOUND:      ST_helpMsg("ERROR: engine not found"); break;
            case FAT_LOCKFAILED:    ST_helpMsg("ERROR: lock failed"); break;
            case FAT_OUTOFMEM:      ST_helpMsg("ERROR: out of memory"); break;
            default:                ST_helpMsg("ERROR: unknown"); break;
        }
        return;
    }

    LCD_save(lcd);
    InstallDummyHandlerForINTs();

    if (!GrayOn()) {
        RestoreHandlerForINTs();
        FAT_UnloadEngine();
        ST_helpMsg("ERROR: grayscale failed");
        return;
    }

    FAT_DisplayLogo(60);

    InitRecipTables();

    /* Load wall, door, and sprite textures + build shade tables */
    if ((texfile = FAT_GetHandleOfFile("fatdtx"))) {
        if ((texsrc = FAT_LockHandleOfFile(texfile))) {
            FAT_LoadTextures(wall_textures, texsrc + 2, TEXIDX_DEMO3WALL, 1);
            FAT_LoadTextures(&wall_textures[1], texsrc + 2, TEXIDX_DEMO3DOOR, 1);
            FAT_LoadTextures(&sprite_tex, texsrc + 2, TEXIDX_SOLDIER1 + TEX_TOWARD, 1);
            InitTexShades();
            InitTexShadesDoor();
            InitTexShadesSprite();
        }
    }
    if (!texfile || !texsrc) {
        GrayOff();
        LCD_restore(lcd);
        RestoreHandlerForINTs();
        FAT_UnloadEngine();
        ST_helpMsg("ERROR: cannot load textures");
        return;
    }

    /* Seed RNG */
    rng_state = int5_counter ^ (int1_counter << 16);
    if (rng_state == 0) rng_state = 12345;

    /* Init game state */
    player_hp = 10;
    game_state = STATE_PLAYING;
    GenerateLevel(1);

    /* Init GUI */
    InitDungeonGUI(&lvl_display, &hp_display);
    DrawMinimap();
    UpdateMinimapPlayer();

    /* Main loop */
    do {
        /* Smooth Z interpolation */
        if (player_z < target_z) {
            player_z += 5;
            if (player_z > target_z) player_z = target_z;
        } else if (player_z > target_z) {
            player_z -= 5;
            if (player_z < target_z) player_z = target_z;
        }

        RenderDungeon();
        RenderBillboards();
        CopyToLCD();

        key = FAT_GetPadState();
        if (key & PADSTATE_ESC) break;

        if (key & PADSTATE_UPDOWN) {
            PlayerMoveDungeon(key & PADSTATE_UP, 0);
        }
        if (key & PADSTATE_LEFTRIGHT) {
            if (key & PADSTATE_KA) {
                PlayerMoveDungeon(key & PADSTATE_RIGHT, 1);
                turn_hold = 0;
            } else {
                short turn_amt = 3 + turn_hold;
                if (turn_amt > 8) turn_amt = 8;
                cam_orientation = PlayerTurn_dungeon(cam_orientation,
                                                     key & PADSTATE_RIGHT,
                                                     turn_amt);
                turn_hold++;
            }
        } else {
            turn_hold = 0;
        }

        UpdateMinimapPlayer();

        /* Game state transitions */
        if (game_state == STATE_NEXTLVL) {
            player_hp += 3;
            if (player_hp > 10) player_hp = 10;
            GenerateLevel(current_level + 1);
            DrawMinimap();
            UpdateMinimapPlayer();
            UpdateLevelCounter(&lvl_display, current_level);
            UpdateHPCounter(&hp_display, player_hp);
            game_state = STATE_PLAYING;
        }
        else if (game_state == STATE_GAMEOVER) {
            break;
        }
        else {
            UpdateHPCounter(&hp_display, player_hp);
        }
    } while (1);

    /* Cleanup */
    FAT_AllKeysReleased();
    GrayOff();
    LCD_restore(lcd);
    FAT_UnlockHandleOfFile(texfile);

    if (game_state == STATE_GAMEOVER) {
        ST_helpMsg("GAME OVER! Descend by FAT Engine");
    } else {
        ST_helpMsg("Descend - Powered by FAT Engine");
    }

    FAT_UnloadEngine();
    RestoreHandlerForINTs();
    OSqclear(kbd_queue());
}
