/******************************************************************************
*
* project name:   FAT-Engine Stairs Demo
* file name:      fatd_stairs.c
* description:    Height-mapped raycaster with stairs/ramps
*
* Uses the FAT Engine for infrastructure (grayscale LCD, input, trig tables,
* texture loading, timer interrupts) but implements its own raycaster that
* supports per-tile floor heights.
*
******************************************************************************/

#define USE_TI89
#include "includes/fat.h"

#define MAP_WIDTH  16
#define MAP_HEIGHT 16

/* Wall map: 0=empty, 1-N=wall texture ID
 *
 * Tight 3-tile-wide corridor (cols 6-8) with walls on both sides.
 * Stairs lead north from ground level up to a cross corridor with side rooms.
 */
char stair_map[MAP_WIDTH * MAP_HEIGHT] = {
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

/*
 * Floor height map: 0-63 (units of 1/64 tile height)
 * 0 = ground level. Higher values = elevated floor.
 *
 * 4 stair steps (rows 10-7) lead from ground to height 40.
 * Cross corridor at rows 1-3 is also at height 40.
 */
unsigned char floor_height[MAP_WIDTH * MAP_HEIGHT] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0,40,40,40,40, 0,40,40,40, 0,40,40,40,40,40, 0,
     0,40,40,40,40, 0,40,40,40, 0,40,40,40,40,40, 0,
     0,40,40,40,40,40,40,40,40,40,40,40,40,40,40, 0,
     0, 0, 0, 0, 0, 0,40,40,40, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,40,40,40, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,40,40,40, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,40,40,40, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,30,30,30, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,20,20,20, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0,10,10,10, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

short player_z = 0;   /* player's current rendered height (interpolated) */
short target_z = 0;   /* target floor height (snaps on tile change) */

/* Max step the player can climb in one move (prevents walking up walls) */
#define MAX_STEP_HEIGHT 12

/* Segments per column for multi-height rendering */
#define MAX_SEGMENTS 6

typedef struct {
    short distance;
    short screen_top;
    short screen_bot;
    unsigned char shade;     /* 0=white, 1=light gray, 2=dark gray, 3=black */
    unsigned short *tex_light;  /* texture column data (4 shorts), NULL=flat */
    unsigned short *tex_dark;
    unsigned char *tex_shade;   /* precomputed shade table (64 bytes), NULL=flat */
} WALL_SEGMENT;

/* Eye height above current floor (in same units as floor_height).
 * 32 = half wall height = centered horizon, like the standard FAT raycaster. */
#define EYE_HEIGHT 32

/* Screen dimensions for the raycaster viewport */
#define VIEW_WIDTH  96
#define VIEW_HEIGHT 96
#define VIEW_HALF   48
#define STAIR_SCALE 7680  /* taller walls than SCALE_VALUE (5376) */

/* Include utility routines (counter, player movement, interrupts) */
#define NO_PLAYER_MOVE  /* we provide our own height-aware movement */
#include "utils.c"
#include "indices.h"

short display_offsetx = 0;
short display_offsety = 0;

TEXCONFIG wall_textures[2];  /* loaded wall textures */

/* Bit mask lookup: avoids expensive variable shift on M68K */
static const unsigned short tex_bit[16] = {
    0x8000,0x4000,0x2000,0x1000,0x0800,0x0400,0x0200,0x0100,
    0x0080,0x0040,0x0020,0x0010,0x0008,0x0004,0x0002,0x0001
};

/* Offscreen render buffers for double buffering (96 rows × 6 words per row) */
unsigned short render_light[576];
unsigned short render_dark[576];

/* Reciprocal lookup tables to eliminate divs.w (158 cycles -> ~12 cycles) */
#define RECIP_SIZE 1024
short recip_wall[RECIP_SIZE];    /* recip_wall[d] = STAIR_SCALE / d */
short recip_tex[256];            /* recip_tex[h]  = 16384 / h */

void InitRecipTables(void) {
    short i;
    recip_wall[0] = STAIR_SCALE;
    for (i = 1; i < RECIP_SIZE; i++)
        recip_wall[i] = STAIR_SCALE / i;
    recip_tex[0] = 16384;
    for (i = 1; i < 256; i++)
        recip_tex[i] = 16384 / i;
}

/* Precomputed shade table: tex_shades[col*64 + row] = shade byte
 * bit 1 = light plane value, bit 0 = dark plane value
 * Eliminates per-pixel bit extraction (78 cycles → 14 cycles per pixel) */
unsigned char tex_shades[4096];  /* 64 columns × 64 rows */

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

/* Forward declaration */
short PlayerTurn_stairs(short orientation, short right, short increment);

/*=============================================================================
 * Height-aware player movement
 *
 * Like the original PlayerMove but checks floor heights and snaps player_z
 * to the destination tile's floor height if the step is climbable.
 *=============================================================================*/
void PlayerMoveStairs(short cam_orientation, short *cam_xpos, short *cam_ypos,
                      short forward_right, short strafe)
{
    short tmp_angle, stepx, stepy, newxpos, newypos, newxmod, newymod;
    short old_tile_x, old_tile_y;
    unsigned char new_fh, old_fh;
    short height_diff;

    tmp_angle = cam_orientation + (strafe ? ANGLE_090 : 0);
    stepx = FAT_Cos16384(tmp_angle) >> 11;
    stepy = FAT_Sin16384(tmp_angle) >> 11;
    newxpos = *cam_xpos + (forward_right ? stepx : -stepx);
    newypos = *cam_ypos + (forward_right ? stepy : -stepy);
    newxmod = newxpos >> 6;
    newymod = newypos >> 6;

    /* bounds check */
    if (newxmod >= MAP_WIDTH || newymod >= MAP_HEIGHT || newxmod < 0 || newymod < 0)
        return;

    /* wall check */
    if (stair_map[(newymod << 4) + newxmod] > 0)
        return;

    /* height check: can we step up/down? */
    old_tile_x = *cam_xpos >> 6;
    old_tile_y = *cam_ypos >> 6;
    old_fh = floor_height[(old_tile_y << 4) + old_tile_x];
    new_fh = floor_height[(newymod << 4) + newxmod];
    height_diff = (short)new_fh - (short)old_fh;
    if (height_diff > MAX_STEP_HEIGHT)
        return;  /* step too high */

    *cam_xpos = newxpos;
    *cam_ypos = newypos;
    target_z = (short)new_fh;
}


/*=============================================================================
 * Draw an entire column in one pass: background + wall segments.
 * No separate clear needed — every pixel written exactly once.
 * Uses pointer stride (no multiply), shade-specialized inner loops.
 *
 * Segments are sorted by screen_top so we can walk top-to-bottom.
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

    /* Sort segments by screen_top ascending (skip if 0 or 1) */
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
        /* Background before this segment (or after last) */
        /* Split into sky (black) and floor (dark gray) to avoid per-pixel branch */
        end = (s < num_segs) ? segs[s].screen_top : VIEW_HEIGHT;
        if (end < 0) end = 0;
        if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;
        {
            short mid = (end < VIEW_HALF) ? end : VIEW_HALF;
            short cnt;
            /* Sky: black (light=1, dark=1) */
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
            /* Floor: dark gray (light=0, dark=1) */
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

        /* Wall segment */
        if (s < num_segs) {
            end = segs[s].screen_bot + 1;
            if (end < 0) end = 0;
            if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;

            if (segs[s].tex_light) {
                /* Textured wall: shade-table M68K asm inner loop */
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
                /* Flat-shaded segment (step walls) — asm fill */
                short fcnt = end - row - 1;
                if (fcnt >= 0) {
                    switch (segs[s].shade) {
                    case 0: /* white: light=0, dark=0 */
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
                    case 1: /* light gray: light=1, dark=0 */
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
                    case 2: /* dark gray: light=0, dark=1 */
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
                    default: /* black: light=1, dark=1 */
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
 * Custom height-mapped raycaster
 *
 * For each of 96 columns:
 * 1. Cast ray via DDA using FAT's trig tables
 * 2. At each tile boundary: check for wall (stop) or height change (add segment)
 * 3. Compute screen Y for each segment based on heights
 * 4. Draw vertical bands with distance-based shading
 *=============================================================================*/
void RenderStairs(short cam_xpos, short cam_ypos, short cam_orientation)
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

    /* Get trig tables from the FAT engine */
    tab_xstep   = FAT_Get64DivTanTab();
    tab_ystep   = FAT_Get64TanTab();
    tab_div_tan = FAT_Get256DivTanTab();
    tab_tan     = FAT_Get256TanTab();
    tab_div_sin = FAT_Get128DivSinTab();

    /* Player eye position in height units */
    eye_z = player_z + EYE_HEIGHT;
    eye_z_top = eye_z - 64;

    /* Precompute values constant across all columns */
    xpos_grid = cam_xpos & 0xFFC0;
    ypos_grid = cam_ypos & 0xFFC0;
    maxwidth  = MAP_WIDTH << 6;
    maxheight = MAP_HEIGHT << 6;
    {
        short ptx = cam_xpos >> 6;
        short pty = cam_ypos >> 6;
        if (ptx >= 0 && ptx < MAP_WIDTH && pty >= 0 && pty < MAP_HEIGHT)
            player_fh = (short)floor_height[(pty << 4) + ptx];
        else
            player_fh = 0;
    }

    angle = cam_orientation - ANGLE_030;
    if (angle < ANGLE_000) angle += ANGLE_360;

    for (column = 0; column < VIEW_WIDTH; column += 2) {
        /* DDA variables */
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

        /* Clamp ray_angle */
        if (ray_angle < 0) ray_angle += ANGLE_360;
        if (ray_angle >= ANGLE_360) ray_angle -= ANGLE_360;

        /*
         * Setup DDA parameters per quadrant (same as FAT engine)
         * We only use the horizontal DDA for simplicity in the MVP,
         * checking both horizontal and vertical intersections.
         */

        /* --- Quadrant setup for horizontal and vertical intersections --- */
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

        /*
         * Combined DDA: step both horizontal and vertical rays,
         * always advancing whichever is closer. At each tile we
         * check for walls and floor height changes.
         */
        {
            short h_dist, v_dist;
            short h_valid = 1, v_valid = 1;
            short prev_fh;
            short max_iters = 10;

            prev_fh = player_fh;

            /* Check if horizontal/vertical DDA is active */
            if (ray_angle == ANGLE_000 || ray_angle == ANGLE_180) h_valid = 0;
            if (ray_angle == ANGLE_090 || ray_angle == ANGLE_270) v_valid = 0;

            /* Compute initial distances before loop (cache for reuse) */
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
                unsigned char tile_wall;
                short tile_fh;

                if (!h_valid && !v_valid) break;

                /* Pick the closer intersection, advance it, recompute only that distance */
                if (h_dist <= v_dist && h_valid) {
                    hit_x = h_x; hit_y = h_y; hit_dist = h_dist;
                    hit_h = 1;
                    tile_x = hit_x >> 6;
                    tile_y = hit_y >> 6;
                    h_x += h_sx;
                    h_y += h_sy;
                    /* Recompute h_dist only (v_dist unchanged) */
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
                    /* Recompute v_dist only (h_dist unchanged) */
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

                /* Clamp tile coordinates (unsigned trick: negative wraps to large) */
                if ((unsigned short)tile_x >= MAP_WIDTH ||
                    (unsigned short)tile_y >= MAP_HEIGHT)
                    continue;

                {
                    short tile_idx = (tile_y << 4) + tile_x;
                    tile_wall = stair_map[tile_idx];
                    tile_fh   = (short)floor_height[tile_idx];
                }

                if (tile_wall > 0) {
                    /* Full wall hit — render from floor to ceiling */
                    short wall_height;
                    short screen_top_w, screen_bot_w;
                    unsigned char shade;
                    short texidx;
                    TEXSTRIP *ts;
                    short tex_off;

                    if (hit_dist <= 0) hit_dist = 1;

                    wall_height = (hit_dist < RECIP_SIZE) ? recip_wall[hit_dist] : (STAIR_SCALE / hit_dist);

                    /* Wall top = ceiling (always 32 units above eye).
                     * Wall bottom = prev_fh floor level. When viewing from
                     * an elevated position, walls extend further down —
                     * creating a two-story effect for lower areas. */
                    screen_top_w = VIEW_HALF - (wall_height >> 1);
                    screen_bot_w = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * (long)wall_height) >> 6);

                    if (hit_dist < 150)       shade = 0;
                    else if (hit_dist < 400)  shade = 1;
                    else                      shade = 3;

                    /* Compute texture coordinate from hit position */
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

                    /* Clip to occlusion */
                    if (screen_bot_w >= top_drawn) screen_bot_w = top_drawn - 1;

                    if (screen_top_w < screen_bot_w && num_segments < MAX_SEGMENTS) {
                        segments[num_segments].distance   = hit_dist;
                        segments[num_segments].screen_top = screen_top_w;
                        segments[num_segments].screen_bot = screen_bot_w;
                        segments[num_segments].shade      = shade;
                        segments[num_segments].tex_light  = ts->lightdata + tex_off;
                        segments[num_segments].tex_dark   = ts->darkdata + tex_off;
                        segments[num_segments].tex_shade  = &tex_shades[texidx << 6];
                        num_segments++;
                        if (screen_top_w < top_drawn) top_drawn = screen_top_w;
                    }
                    break;  /* full wall = stop ray */
                }
                else if (tile_fh != prev_fh) {
                    /* Floor height change — render step wall */
                    short wall_height;
                    short screen_top_s, screen_bot_s;
                    unsigned char shade;

                    if (hit_dist <= 0) hit_dist = 1;

                    wall_height = (hit_dist < RECIP_SIZE) ? recip_wall[hit_dist] : (STAIR_SCALE / hit_dist);

                    if (tile_fh > prev_fh) {
                        screen_top_s = VIEW_HALF + (short)(((long)(eye_z - tile_fh) * wall_height) >> 6);
                        screen_bot_s = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * wall_height) >> 6);
                    } else {
                        screen_top_s = VIEW_HALF + (short)(((long)(eye_z - prev_fh) * wall_height) >> 6);
                        screen_bot_s = VIEW_HALF + (short)(((long)(eye_z - tile_fh) * wall_height) >> 6);
                    }

                    shade = 1;  /* steps always light gray */

                    /* Clip to occlusion */
                    if (screen_bot_s >= top_drawn) screen_bot_s = top_drawn - 1;

                    if (screen_top_s < screen_bot_s && num_segments < MAX_SEGMENTS) {
                        segments[num_segments].distance   = hit_dist;
                        segments[num_segments].screen_top = screen_top_s;
                        segments[num_segments].screen_bot = screen_bot_s;
                        segments[num_segments].shade      = shade;
                        segments[num_segments].tex_light  = 0;
                        segments[num_segments].tex_dark   = 0;
                        segments[num_segments].tex_shade  = 0;
                        num_segments++;
                        if (screen_top_s < top_drawn) top_drawn = screen_top_s;
                    }

                    prev_fh = tile_fh;
                    /* Continue ray — don't break, step walls are passable */
                }
                else {
                    prev_fh = tile_fh;
                    /* Same height, keep going */
                }
            } /* end while DDA */
        }

        /* Draw entire column: background + wall segments */
        DrawColumnFast(column, segments, num_segments);

        /* Advance angle (2 per column for half-res) */
        angle += 2;
        if (angle >= ANGLE_360) angle -= ANGLE_360;
    }
}


/*=============================================================================
 * Copy render buffers to LCD planes (double buffering).
 * Copies both planes per-row to minimize inter-plane tearing.
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
 * Initialize GUI: dark gray background, FPM counter
 *=============================================================================*/
void InitStairsGUI(COUNTER *counter) {
    short row;
    unsigned short *lp, *dp;

    memset(GetPlane(LIGHT_PLANE), 0, LCD_SIZE);
    memset(GetPlane(DARK_PLANE), 0xFF, LCD_SIZE);

    /* Draw 2px-wide black vertical separator at right edge of viewport (col 96-97) */
    /* Col 96 is bit 14-13 of word 6 (byte_col = 96/16 = 6), mask = 0xC000 >> 0 = 0xC000 */
    lp = (unsigned short*)GetPlane(LIGHT_PLANE) + 6;
    dp = (unsigned short*)GetPlane(DARK_PLANE)  + 6;
    for (row = 0; row < 100; row++) {
        *lp |= 0xC000;
        *dp |= 0xC000;
        lp += 15; dp += 15;
    }

    InitCounter(counter, 158 - 6 * 5, 99 - 10, 5, 0);
    DrawCounter(counter);
}


/*=============================================================================
 * FPM calculation (simplified from fatd1.c)
 *=============================================================================*/
void UpdateFPM(COUNTER *counter, unsigned long *start_int5,
               unsigned long *start_frame, unsigned long frame_counter)
{
    unsigned long elapsed = int5_counter - *start_int5;
    if (elapsed >= 20) {
        unsigned long frames = frame_counter - *start_frame;
        unsigned long fpm = frames * 1200 / elapsed;
        short i;
        for (i = 4; i >= 0; i--) {
            counter->newcount[i] = fpm % 10;
            fpm /= 10;
        }
        DrawCounter(counter);
        *start_int5  = int5_counter;
        *start_frame = frame_counter;
    }
}


/*=============================================================================
 * Main function
 *=============================================================================*/
void _main(void) {
    PADSTATES      key = 0;
    short          result;
    LCD_BUFFER     lcd;
    COUNTER        fpm_display;
    unsigned long  frame_counter = 0;
    unsigned long  fpm_start_int5 = 0;
    unsigned long  fpm_start_frame = 0;
    HANDLE         texfile = H_NULL;
    unsigned char *texsrc = 0;
    short          turn_hold = 0;

    short cam_xpos = 480;        /* start position: tile (7,12), center of corridor */
    short cam_ypos = 800;        /* in tight corridor, facing north toward stairs */
    short cam_orientation = ANGLE_NORTH;  /* face north toward the stairs */

    /* Load the FAT Engine (we need it for trig tables, input, grayscale) */
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
    InitStairsGUI(&fpm_display);

    /* Load wall textures from the texture file */
    if ((texfile = FAT_GetHandleOfFile("fatdtx"))) {
        if ((texsrc = FAT_LockHandleOfFile(texfile))) {
            FAT_LoadTextures(wall_textures, texsrc + 2, TEXIDX_DEMO3WALL, 2);
            InitTexShades();
        }
    }

    fpm_start_int5  = int5_counter;
    fpm_start_frame = frame_counter;

    /* Main loop */
    do {
        /* Smooth Z interpolation: move player_z toward target_z */
        if (player_z < target_z) {
            player_z += 5;
            if (player_z > target_z) player_z = target_z;
        } else if (player_z > target_z) {
            player_z -= 5;
            if (player_z < target_z) player_z = target_z;
        }

        RenderStairs(cam_xpos, cam_ypos, cam_orientation);
        CopyToLCD();

        frame_counter++;
        UpdateFPM(&fpm_display, &fpm_start_int5, &fpm_start_frame, frame_counter);

        key = FAT_GetPadState();
        if (key & PADSTATE_ESC) break;

        if (key & PADSTATE_UPDOWN) {
            PlayerMoveStairs(cam_orientation, &cam_xpos, &cam_ypos,
                             key & PADSTATE_UP, 0);
        }
        if (key & PADSTATE_LEFTRIGHT) {
            if (key & PADSTATE_KA) {
                /* Strafe */
                PlayerMoveStairs(cam_orientation, &cam_xpos, &cam_ypos,
                                 key & PADSTATE_RIGHT, 1);
                turn_hold = 0;
            } else {
                /* Turn: start smooth (3), accelerate while held (up to 8) */
                short turn_amt = 3 + turn_hold;
                if (turn_amt > 8) turn_amt = 8;
                cam_orientation = PlayerTurn_stairs(cam_orientation,
                                                    key & PADSTATE_RIGHT,
                                                    turn_amt);
                turn_hold++;
            }
        } else {
            turn_hold = 0;
        }
    } while (1);

    /* Cleanup */
    FAT_AllKeysReleased();
    GrayOff();
    LCD_restore(lcd);
    if (texfile) FAT_UnlockHandleOfFile(texfile);
    ST_helpMsg("Stairs Demo - Powered by FAT Engine");
    FAT_UnloadEngine();
    RestoreHandlerForINTs();
    OSqclear(kbd_queue());
}


/*=============================================================================
 * PlayerTurn for stairs (standalone, doesn't need FATCONFIG)
 *=============================================================================*/
short PlayerTurn_stairs(short orientation, short right, short increment) {
    orientation += right ? increment : -increment;
    return FAT_ClampAngle(orientation);
}
