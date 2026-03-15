/******************************************************************************
*
* project name:   Descend - Standalone Dungeon Crawler
* file name:      fatd_hw4.c
* description:    Self-contained raycaster + procedural dungeon for TI-89
*                 Titanium HW4. No FAT engine dependency. Flat-shaded walls.
*
******************************************************************************/

#define USE_TI89
#define OPTIMIZE_ROM_CALLS
#include <tigcclib.h>

/*=============================================================================
 * Constants (from fat.h)
 *=============================================================================*/

#define ANGLE_000    0
#define ANGLE_015   24
#define ANGLE_030   48
#define ANGLE_045   72
#define ANGLE_060   96
#define ANGLE_090  144
#define ANGLE_180  288
#define ANGLE_270  432
#define ANGLE_360  576

#define MAX_DISTANCE 32000

#define ANGLE_NORTH  ANGLE_270
#define ANGLE_EAST   ANGLE_000
#define ANGLE_SOUTH  ANGLE_090
#define ANGLE_WEST   ANGLE_180

typedef unsigned short PADSTATES;

#define PADSTATE_ESC     0x0001
#define PADSTATE_UP      0x0002
#define PADSTATE_DOWN    0x0004
#define PADSTATE_LEFT    0x0008
#define PADSTATE_RIGHT   0x0010
#define PADSTATE_PLUS    0x0040
#define PADSTATE_MINUS   0x0080
#define PADSTATE_KA      0x0100   /* 2ND */
#define PADSTATE_KB      0x0200   /* DIAMOND */

#define PADSTATE_UPDOWN     (PADSTATE_UP|PADSTATE_DOWN)
#define PADSTATE_LEFTRIGHT  (PADSTATE_LEFT|PADSTATE_RIGHT)

#define ClampAngle(a) ({short t=(a);while(t<ANGLE_000) t+=ANGLE_360;while(t>=ANGLE_360) t-=ANGLE_360;t;})

/* Map dimensions */
#define MAP_W 16
#define MAP_H 16

/* Tile types */
#define TILE_EMPTY 0
#define TILE_WALL  1
#define TILE_ENEMY 2
#define TILE_EXIT  3

/* Game states */
#define STATE_PLAYING  0
#define STATE_NEXTLVL  1
#define STATE_GAMEOVER 2

/* Rendering constants */
#define VIEW_WIDTH  96
#define VIEW_HEIGHT 96
#define VIEW_HALF   48
#define WALL_SCALE  7680

#define MAX_ENEMIES 3
#define MAX_ROOMS   4


/*=============================================================================
 * Sin/cos table: sin(i * 0.625 degrees) * 16384, for i = 0..144
 *=============================================================================*/

static const short sin_tab[145] = {
        0,   179,   357,   536,   715,   893,  1072,  1250,  1428,  1606,
     1784,  1961,  2139,  2316,  2492,  2669,  2845,  3021,  3196,  3371,
     3546,  3720,  3894,  4068,  4240,  4413,  4585,  4756,  4927,  5097,
     5266,  5435,  5604,  5771,  5938,  6104,  6270,  6435,  6599,  6762,
     6924,  7086,  7246,  7406,  7565,  7723,  7881,  8037,  8192,  8346,
     8500,  8652,  8803,  8953,  9102,  9251,  9397,  9543,  9688,  9832,
     9974, 10115, 10255, 10394, 10531, 10668, 10803, 10936, 11069, 11200,
    11330, 11458, 11585, 11711, 11835, 11958, 12080, 12200, 12318, 12435,
    12551, 12665, 12778, 12889, 12998, 13106, 13213, 13318, 13421, 13523,
    13623, 13721, 13818, 13913, 14007, 14099, 14189, 14277, 14364, 14449,
    14533, 14614, 14694, 14773, 14849, 14924, 14996, 15068, 15137, 15204,
    15270, 15334, 15396, 15456, 15515, 15571, 15626, 15679, 15729, 15779,
    15826, 15871, 15914, 15956, 15996, 16033, 16069, 16103, 16135, 16165,
    16193, 16220, 16244, 16266, 16287, 16305, 16322, 16336, 16349, 16360,
    16368, 16375, 16380, 16383, 16384
};

static short MySin16384(short angle) {
    while (angle < 0)          angle += ANGLE_360;
    while (angle >= ANGLE_360) angle -= ANGLE_360;
    if (angle <= ANGLE_090)    return  sin_tab[angle];
    if (angle <= ANGLE_180)    return  sin_tab[ANGLE_180 - angle];
    if (angle <= ANGLE_270)    return -sin_tab[angle - ANGLE_180];
    return -sin_tab[ANGLE_360 - angle];
}

#define MyCos16384(a) MySin16384(ANGLE_090 + (a))


/*=============================================================================
 * Trig lookup tables (computed at init from sin_tab)
 *=============================================================================*/

static short tab_xstep[ANGLE_090];    /* 64 * cos / sin */
static short tab_ystep[ANGLE_090];    /* 64 * sin / cos */
static short tab_div_tan[ANGLE_090];  /* 256 * cos / sin */
static short tab_tan[ANGLE_090];      /* 256 * sin / cos */
static short tab_div_sin[ANGLE_090];  /* 128 * 16384 / sin */

static void InitTrigTables(void) {
    short i;
    for (i = 0; i < ANGLE_090; i++) {
        long s = sin_tab[i];
        long c = sin_tab[ANGLE_090 - i];

        if (s == 0) {
            tab_xstep[i]   = 32000;
            tab_div_tan[i] = 32000;
            tab_div_sin[i] = 32000;
            tab_ystep[i]   = 0;
            tab_tan[i]     = 0;
        } else {
            tab_xstep[i]   = (short)((64L * c) / s);
            tab_div_tan[i] = (short)((256L * c) / s);
            tab_div_sin[i] = (short)((128L * 16384L) / s);
            if (c == 0) {
                tab_ystep[i] = 32000;
                tab_tan[i]   = 32000;
            } else {
                tab_ystep[i] = (short)((64L * s) / c);
                tab_tan[i]   = (short)((256L * s) / c);
            }
        }
    }
}


/*=============================================================================
 * Keyboard input (direct _rowread for TI-89)
 *=============================================================================*/

static PADSTATES MyGetPadState(void) {
    PADSTATES state = 0;
    unsigned short r0, r1, r6;

    r0 = _rowread(0xFFFE);   /* Row 0: arrows + modifiers */
    r1 = _rowread(0xFFFD);   /* Row 1: +, - */
    r6 = _rowread(0xFFBF);   /* Row 6: ESC */

    if (r0 & 0x01) state |= PADSTATE_UP;
    if (r0 & 0x02) state |= PADSTATE_LEFT;
    if (r0 & 0x04) state |= PADSTATE_DOWN;
    if (r0 & 0x08) state |= PADSTATE_RIGHT;
    if (r0 & 0x10) state |= PADSTATE_KA;     /* 2ND */
    if (r0 & 0x40) state |= PADSTATE_KB;     /* DIAMOND */
    if (r1 & 0x02) state |= PADSTATE_PLUS;
    if (r1 & 0x04) state |= PADSTATE_MINUS;
    if (r6 & 0x01) state |= PADSTATE_ESC;

    return state;
}


/*=============================================================================
 * Counter/digit display (from utils.c, for HUD)
 *=============================================================================*/

static unsigned char numbers_data[90] = {
0x70,0xd8,0xd8,0xd8,0xd8,0xd8,0xd8,0xd8,0x70,
0x30,0x70,0xf0,0x30,0x30,0x30,0x30,0x30,0xf8,
0x70,0xd8,0xd8,0x18,0x30,0x30,0x60,0x60,0xf8,
0x70,0xd8,0xd8,0x18,0x30,0x18,0xd8,0xd8,0x70,
0x70,0x70,0x70,0xb0,0xb0,0xf8,0xf8,0x30,0x30,
0xf8,0xc0,0xf8,0xd8,0x18,0xd8,0xd8,0xd8,0x70,
0x70,0xd8,0xc0,0xf0,0xd8,0xd8,0xd8,0xd8,0x70,
0xf8,0x18,0x18,0x30,0x30,0x30,0x60,0x60,0x60,
0x70,0xd8,0xd8,0xd8,0x70,0xd8,0xd8,0xd8,0x70,
0x70,0xd8,0xd8,0xd8,0xd8,0x78,0x18,0xd8,0x70};

static void Number_XOR_DarkPlane(short x, short y, unsigned char number) {
    register long           addr   = (long)GetPlane(DARK_PLANE)+(y<<5)-(y<<1)+((x>>3)&0xfffe);
    register unsigned short cnt    = 24-(x&15);
    register unsigned char* sprite = numbers_data+(number<<3)+number;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt;
}

#define COUNTER_MAX_LEN 10

typedef struct {
    short x, y, length, already_used;
    unsigned char oldcount[COUNTER_MAX_LEN];
    unsigned char newcount[COUNTER_MAX_LEN];
} COUNTER;

static void InitCounter(COUNTER* c, short x, short y, short length, unsigned long value) {
    short i;
    c->length = length; c->already_used = 0; c->x = x; c->y = y;
    for (i = length - 1; i >= 0; i--) {
        unsigned char v = value % 10;
        c->oldcount[i] = v; c->newcount[i] = v; value /= 10;
    }
}

static void DrawCounter(COUNTER* c) {
    unsigned char *oc = c->oldcount, *nc = c->newcount;
    short i, x = c->x;
    if (c->already_used) {
        for (i = 0; i < c->length; i++, x += 6) {
            if (*oc != *nc) {
                Number_XOR_DarkPlane(x, c->y, *oc);
                Number_XOR_DarkPlane(x, c->y, *nc);
            }
            *oc++ = *nc++;
        }
    } else {
        for (i = 0; i < c->length; i++, x += 6) {
            Number_XOR_DarkPlane(x, c->y, *nc);
            *oc++ = *nc++;
        }
        c->already_used = 1;
    }
}


/*=============================================================================
 * Timer interrupt handlers
 *=============================================================================*/

INT_HANDLER _old_int1_ = 0;
INT_HANDLER _old_int5_ = 0;
unsigned long int1_counter = 0;
unsigned long int5_counter = 0;

DEFINE_INT_HANDLER(int1_handler) { int1_counter++; }
DEFINE_INT_HANDLER(int5_handler) { int5_counter++; }

#define InstallDummyHandlerForINTs() ({\
    int1_counter = 0; int5_counter = 0;\
    _old_int1_ = GetIntVec(AUTO_INT_1); SetIntVec(AUTO_INT_1, int1_handler);\
    _old_int5_ = GetIntVec(AUTO_INT_5); SetIntVec(AUTO_INT_5, int5_handler);\
})

#define RestoreHandlerForINTs() ({\
    SetIntVec(AUTO_INT_1, _old_int1_); SetIntVec(AUTO_INT_5, _old_int5_);})


/*=============================================================================
 * Game data
 *=============================================================================*/

unsigned char dungeon[MAP_W * MAP_H];

typedef struct { short tile_x, tile_y, hp, alive; } ENEMY;
ENEMY enemies[MAX_ENEMIES];

typedef struct { short x, y, w, h; } ROOM;

short cam_xpos, cam_ypos, cam_orientation;
short current_level;
short player_hp;
short enemies_alive;
short game_state;

/* RNG */
unsigned long rng_state;
unsigned short rng_next(void) {
    rng_state = rng_state * 1664525UL + 1013904223UL;
    return (unsigned short)(rng_state >> 16);
}


/*=============================================================================
 * Rendering engine
 *=============================================================================*/

/* Offscreen render buffers (96 pixels wide × 96 rows = 6 shorts × 96) */
unsigned short render_light[576];
unsigned short render_dark[576];

/* Reciprocal lookup */
#define RECIP_SIZE 512
short recip_wall[RECIP_SIZE];

static void InitRecipTables(void) {
    short i;
    recip_wall[0] = WALL_SCALE;
    for (i = 1; i < RECIP_SIZE; i++)
        recip_wall[i] = WALL_SCALE / i;
}

typedef struct {
    short distance, screen_top, screen_bot;
    unsigned char shade;
} WALL_SEGMENT;


/*=============================================================================
 * DrawColumnFast — flat-shaded column renderer (2 pixels wide per column)
 *=============================================================================*/

static void DrawColumnFast(short col, WALL_SEGMENT *seg, short has_seg)
{
    unsigned short *lp, *dp;
    short byte_col;
    unsigned short mask, nmask;
    short row, end;

    byte_col = col >> 4;
    mask  = (unsigned short)3 << (14 - (col & 14));
    nmask = ~mask;

    lp = render_light + byte_col;
    dp = render_dark  + byte_col;

    row = 0;

    /* Before wall: sky (top half) + floor (bottom half) */
    end = has_seg ? seg->screen_top : VIEW_HEIGHT;
    if (end < 0) end = 0;
    if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;
    {
        short mid = (end < VIEW_HALF) ? end : VIEW_HALF;
        short cnt;
        /* Sky: black (L=1, D=1) */
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
        /* Floor: dark gray (L=0, D=1) */
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

    /* Wall segment (flat-shaded) */
    if (has_seg) {
        end = seg->screen_bot + 1;
        if (end < 0) end = 0;
        if (end > VIEW_HEIGHT) end = VIEW_HEIGHT;

        {
            short fcnt = end - row - 1;
            if (fcnt >= 0) {
                switch (seg->shade) {
                case 0: /* white */
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
                case 1: /* light gray */
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
                case 2: /* dark gray */
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
                default: /* black */
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

        /* After wall: floor continuation */
        end = VIEW_HEIGHT;
        {
            short mid = (end < VIEW_HALF) ? end : VIEW_HALF;
            short cnt;
            /* Sky portion if wall ended above midline */
            if (row < mid) {
                cnt = mid - row - 1;
                if (cnt >= 0) {
                    asm volatile (
                        ".Lsky2_%=:\n"
                        "or.w  %2, (%0)\n"
                        "or.w  %2, (%1)\n"
                        "lea   12(%0), %0\n"
                        "lea   12(%1), %1\n"
                        "dbf   %3, .Lsky2_%=\n"
                        : "+a"(lp), "+a"(dp)
                        : "d"(mask), "d"(cnt)
                        : "cc", "memory"
                    );
                    row = mid;
                }
            }
            /* Floor: dark gray */
            cnt = end - row - 1;
            if (cnt >= 0) {
                asm volatile (
                    ".Lflr2_%=:\n"
                    "and.w %2, (%0)\n"
                    "or.w  %3, (%1)\n"
                    "lea   12(%0), %0\n"
                    "lea   12(%1), %1\n"
                    "dbf   %4, .Lflr2_%=\n"
                    : "+a"(lp), "+a"(dp)
                    : "d"(nmask), "d"(mask), "d"(cnt)
                    : "cc", "memory"
                );
            }
        }
    }
}


/*=============================================================================
 * CopyToLCD — copy render buffers to LCD planes (row 1 offset)
 *=============================================================================*/

static void CopyToLCD(void) {
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
 * Dungeon generation
 *=============================================================================*/

static void GenerateLevel(short level) {
    ROOM rooms[MAX_ROOMS];
    short num_rooms, i, x, y, ex, ey;

    memset(dungeon, TILE_WALL, MAP_W * MAP_H);
    for (i = 0; i < MAX_ENEMIES; i++) enemies[i].alive = 0;
    enemies_alive = 0;

    num_rooms = 3 + (rng_next() % 2);
    for (i = 0; i < num_rooms; i++) {
        short rw = 2 + (rng_next() % 3);
        short rh = 2 + (rng_next() % 3);
        short rx = 1 + (rng_next() % (MAP_W - rw - 2));
        short ry = 1 + (rng_next() % (MAP_H - rh - 2));
        rooms[i].x = rx; rooms[i].y = ry;
        rooms[i].w = rw; rooms[i].h = rh;
        for (y = ry; y < ry + rh; y++)
            for (x = rx; x < rx + rw; x++)
                dungeon[(y << 4) + x] = TILE_EMPTY;
    }

    /* L-shaped corridors between rooms */
    for (i = 0; i < num_rooms - 1; i++) {
        short cx1 = rooms[i].x + rooms[i].w / 2;
        short cy1 = rooms[i].y + rooms[i].h / 2;
        short cx2 = rooms[i+1].x + rooms[i+1].w / 2;
        short cy2 = rooms[i+1].y + rooms[i+1].h / 2;
        short xs = (cx1 < cx2) ? cx1 : cx2;
        short xe = (cx1 < cx2) ? cx2 : cx1;
        short ys = (cy1 < cy2) ? cy1 : cy2;
        short ye = (cy1 < cy2) ? cy2 : cy1;
        for (x = xs; x <= xe; x++) dungeon[(cy1 << 4) + x] = TILE_EMPTY;
        for (y = ys; y <= ye; y++) dungeon[(y << 4) + cx2] = TILE_EMPTY;
    }

    cam_xpos = (rooms[0].x + rooms[0].w / 2) * 64 + 32;
    cam_ypos = (rooms[0].y + rooms[0].h / 2) * 64 + 32;
    cam_orientation = ANGLE_NORTH;

    ex = rooms[num_rooms - 1].x + rooms[num_rooms - 1].w / 2;
    ey = rooms[num_rooms - 1].y + rooms[num_rooms - 1].h / 2;
    dungeon[(ey << 4) + ex] = TILE_EXIT;

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
                    enemies[i].tile_x = tx; enemies[i].tile_y = ty;
                    enemies[i].hp = 2; enemies[i].alive = 1;
                    enemies_alive++;
                    break;
                }
            }
        }
    }

    current_level = level;
}


/*=============================================================================
 * Player movement with bump combat
 *=============================================================================*/

static void PlayerMoveDungeon(short forward_right, short strafe) {
    short tmp_angle, stepx, stepy, newxpos, newypos, newxmod, newymod;
    unsigned char tile;
    short idx;

    tmp_angle = cam_orientation + (strafe ? ANGLE_090 : 0);
    stepx = MyCos16384(tmp_angle) >> 11;
    stepy = MySin16384(tmp_angle) >> 11;
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
                enemies[i].tile_y == newymod) {
                enemies[i].hp--;
                player_hp--;
                if (enemies[i].hp <= 0) {
                    enemies[i].alive = 0;
                    dungeon[idx] = TILE_EMPTY;
                    enemies_alive--;
                    cam_xpos = newxpos; cam_ypos = newypos;
                }
                if (player_hp <= 0) game_state = STATE_GAMEOVER;
                return;
            }
        }
        return;
    }

    if (tile == TILE_EXIT) { game_state = STATE_NEXTLVL; return; }

    cam_xpos = newxpos;
    cam_ypos = newypos;
}


/*=============================================================================
 * Raycaster (flat-shaded, no textures)
 *=============================================================================*/

static void RenderDungeon(void) {
    short column, angle;
    short xpos_grid, ypos_grid, maxwidth, maxheight;
    WALL_SEGMENT seg;

    xpos_grid = cam_xpos & 0xFFC0;
    ypos_grid = cam_ypos & 0xFFC0;
    maxwidth  = MAP_W << 6;
    maxheight = MAP_H << 6;

    angle = cam_orientation - ANGLE_030;
    if (angle < ANGLE_000) angle += ANGLE_360;

    for (column = 0; column < VIEW_WIDTH; column += 2) {
        short h_x, h_y, h_sx, h_sy;
        short v_x, v_y, v_sx, v_sy;
        short use_cos, divsin_val, divcos_val;
        long first_hit;
        short ray_angle;
        short has_seg;

        has_seg = 0;
        ray_angle = angle;

        if (ray_angle < 0) ray_angle += ANGLE_360;
        if (ray_angle >= ANGLE_360) ray_angle -= ANGLE_360;

        /*--- Horizontal intersection setup ---*/
        if (ray_angle == ANGLE_000 || ray_angle == ANGLE_180) {
            h_x = cam_xpos; h_y = cam_ypos; h_sx = 0; h_sy = 0;
        }
        else if (ray_angle < ANGLE_090) {
            h_y = ypos_grid + 64;
            first_hit = (long)(short)tab_div_tan[ray_angle] * (short)(h_y - cam_ypos);
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = tab_xstep[ray_angle]; h_sy = 64;
        }
        else if (ray_angle < ANGLE_180) {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_090);
            h_y = ypos_grid + 64;
            first_hit = -((long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos));
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = -tab_xstep[idx]; h_sy = 64;
        }
        else if (ray_angle < ANGLE_270) {
            short idx = ray_angle - ANGLE_180;
            h_y = ypos_grid - 1;
            first_hit = (long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos);
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = -tab_xstep[idx]; h_sy = -64;
        }
        else {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_270);
            h_y = ypos_grid - 1;
            first_hit = -((long)(short)tab_div_tan[idx] * (short)(h_y - cam_ypos));
            first_hit >>= 8L;
            h_x = (short)(first_hit + (long)cam_xpos);
            h_sx = tab_xstep[idx]; h_sy = -64;
        }

        /*--- Vertical intersection setup ---*/
        if (ray_angle == ANGLE_090 || ray_angle == ANGLE_270) {
            v_x = cam_xpos; v_y = cam_ypos; v_sx = 0; v_sy = 0;
        }
        else if (ray_angle < ANGLE_090) {
            v_x = xpos_grid + 64;
            first_hit = (long)(short)tab_tan[ray_angle] * (short)(v_x - cam_xpos);
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = 64; v_sy = tab_ystep[ray_angle];
        }
        else if (ray_angle < ANGLE_180) {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_090);
            v_x = xpos_grid - 1;
            first_hit = -((long)(short)tab_tan[idx] * (short)(v_x - cam_xpos));
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = -64; v_sy = tab_ystep[idx];
        }
        else if (ray_angle < ANGLE_270) {
            short idx = ray_angle - ANGLE_180;
            v_x = xpos_grid - 1;
            first_hit = (long)(short)tab_tan[idx] * (short)(v_x - cam_xpos);
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = -64; v_sy = -tab_ystep[idx];
        }
        else {
            short idx = ANGLE_090 - 1 - (ray_angle - ANGLE_270);
            v_x = xpos_grid + 64;
            first_hit = -((long)(short)tab_tan[idx] * (short)(v_x - cam_xpos));
            first_hit >>= 8L;
            v_y = (short)(first_hit + (long)cam_ypos);
            v_sx = 64; v_sy = -tab_ystep[idx];
        }

        /*--- Distance calculation setup ---*/
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

        /*--- DDA march ---*/
        {
            short h_dist, v_dist;
            short h_valid = 1, v_valid = 1;
            short max_iters = 16;

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
                } else h_valid = 0;
            }
            if (v_valid) {
                if ((unsigned short)v_x < (unsigned short)maxwidth &&
                    (unsigned short)v_y < (unsigned short)maxheight) {
                    if (use_cos) v_dist = (short)((((long)(v_x - cam_xpos)) * (long)divcos_val) >> 7L);
                    else         v_dist = (short)((((long)(v_y - cam_ypos)) * (long)divsin_val) >> 7L);
                    if (v_dist < 0) v_dist = -v_dist;
                } else v_valid = 0;
            }

            while (max_iters-- > 0) {
                short hit_x, hit_y, hit_dist;
                short hit_h;
                short tile_x, tile_y;

                if (!h_valid && !v_valid) break;

                if (h_dist <= v_dist && h_valid) {
                    hit_x = h_x; hit_y = h_y; hit_dist = h_dist; hit_h = 1;
                    tile_x = hit_x >> 6; tile_y = hit_y >> 6;
                    h_x += h_sx; h_y += h_sy;
                    if ((unsigned short)h_x < (unsigned short)maxwidth &&
                        (unsigned short)h_y < (unsigned short)maxheight) {
                        if (use_cos) h_dist = (short)((((long)(h_x - cam_xpos)) * (long)divcos_val) >> 7L);
                        else         h_dist = (short)((((long)(h_y - cam_ypos)) * (long)divsin_val) >> 7L);
                        if (h_dist < 0) h_dist = -h_dist;
                    } else { h_valid = 0; h_dist = MAX_DISTANCE; }
                } else if (v_valid) {
                    hit_x = v_x; hit_y = v_y; hit_dist = v_dist; hit_h = 0;
                    tile_x = hit_x >> 6; tile_y = hit_y >> 6;
                    v_x += v_sx; v_y += v_sy;
                    if ((unsigned short)v_x < (unsigned short)maxwidth &&
                        (unsigned short)v_y < (unsigned short)maxheight) {
                        if (use_cos) v_dist = (short)((((long)(v_x - cam_xpos)) * (long)divcos_val) >> 7L);
                        else         v_dist = (short)((((long)(v_y - cam_ypos)) * (long)divsin_val) >> 7L);
                        if (v_dist < 0) v_dist = -v_dist;
                    } else { v_valid = 0; v_dist = MAX_DISTANCE; }
                } else break;

                if ((unsigned short)tile_x >= (unsigned short)MAP_W ||
                    (unsigned short)tile_y >= (unsigned short)MAP_H)
                    continue;

                {
                    unsigned char tile = dungeon[(tile_y << 4) + tile_x];
                    if (tile != TILE_EMPTY) {
                        short wall_height;

                        if (hit_dist <= 0) hit_dist = 1;
                        wall_height = (hit_dist < RECIP_SIZE)
                            ? recip_wall[hit_dist]
                            : (WALL_SCALE / hit_dist);

                        seg.screen_top = VIEW_HALF - (wall_height >> 1);
                        seg.screen_bot = VIEW_HALF + (wall_height >> 1);
                        seg.distance   = hit_dist;

                        if (tile == TILE_WALL) {
                            /* Side-based shading: horizontal=light, vertical=dark */
                            seg.shade = hit_h ? 1 : 2;
                        } else if (tile == TILE_EXIT) {
                            seg.shade = 0;  /* White — exit door */
                        } else {
                            seg.shade = 3;  /* Black — enemy */
                        }

                        has_seg = 1;
                        break;
                    }
                }
            }
        }

        DrawColumnFast(column, &seg, has_seg);

        angle += 2;
        if (angle >= ANGLE_360) angle -= ANGLE_360;
    }
}


/*=============================================================================
 * GUI
 *=============================================================================*/

static void InitDungeonGUI(COUNTER *lvl_ctr, COUNTER *hp_ctr, COUNTER *fpm_ctr) {
    short row;
    unsigned short *lp, *dp;

    memset(GetPlane(LIGHT_PLANE), 0, LCD_SIZE);
    memset(GetPlane(DARK_PLANE), 0xFF, LCD_SIZE);

    /* 2px black vertical separator at cols 96-97 */
    lp = (unsigned short*)GetPlane(LIGHT_PLANE) + 6;
    dp = (unsigned short*)GetPlane(DARK_PLANE)  + 6;
    for (row = 0; row < 100; row++) {
        *lp |= 0xC000; *dp |= 0xC000;
        lp += 15; dp += 15;
    }

    InitCounter(lvl_ctr, 110, 8, 3, 1);
    DrawCounter(lvl_ctr);
    InitCounter(hp_ctr, 116, 35, 2, 10);
    DrawCounter(hp_ctr);
    InitCounter(fpm_ctr, 158 - 6 * 5, 99 - 10, 5, 0);
    DrawCounter(fpm_ctr);
}

static void UpdateCounter3(COUNTER *ctr, short val) {
    short i; unsigned long v = (val > 0) ? (unsigned long)val : 0;
    for (i = 2; i >= 0; i--) { ctr->newcount[i] = v % 10; v /= 10; }
    DrawCounter(ctr);
}

static void UpdateCounter2(COUNTER *ctr, short val) {
    short i; unsigned long v = (val > 0) ? (unsigned long)val : 0;
    for (i = 1; i >= 0; i--) { ctr->newcount[i] = v % 10; v /= 10; }
    DrawCounter(ctr);
}

static void UpdateFPM(COUNTER *ctr, unsigned long *start_int5,
                      unsigned long *start_frame, unsigned long frame_counter) {
    unsigned long elapsed = int5_counter - *start_int5;
    if (elapsed >= 20) {
        unsigned long frames = frame_counter - *start_frame;
        unsigned long fpm = frames * 1200 / elapsed;
        short i;
        for (i = 4; i >= 0; i--) { ctr->newcount[i] = fpm % 10; fpm /= 10; }
        DrawCounter(ctr);
        *start_int5  = int5_counter;
        *start_frame = frame_counter;
    }
}


/*=============================================================================
 * Main
 *=============================================================================*/

void _main(void) {
    PADSTATES      key = 0;
    LCD_BUFFER     lcd;
    COUNTER        lvl_display, hp_display, fpm_display;
    unsigned long  frame_counter = 0;
    unsigned long  fpm_start_int5 = 0;
    unsigned long  fpm_start_frame = 0;
    short          turn_hold = 0;

    LCD_save(lcd);
    InstallDummyHandlerForINTs();

    /* Compute trig tables */
    InitTrigTables();
    InitRecipTables();

    if (!GrayOn()) {
        RestoreHandlerForINTs();
        LCD_restore(lcd);
        ST_helpMsg("ERROR: grayscale failed");
        return;
    }

    /* Seed RNG */
    rng_state = int5_counter ^ (int1_counter << 16);
    if (rng_state == 0) rng_state = 12345;

    player_hp = 10;
    game_state = STATE_PLAYING;
    GenerateLevel(1);

    InitDungeonGUI(&lvl_display, &hp_display, &fpm_display);

    fpm_start_int5  = int5_counter;
    fpm_start_frame = frame_counter;

    /* Main loop */
    do {
        RenderDungeon();
        CopyToLCD();

        frame_counter++;
        UpdateFPM(&fpm_display, &fpm_start_int5, &fpm_start_frame, frame_counter);

        key = MyGetPadState();
        if (key & PADSTATE_ESC) break;

        if (key & PADSTATE_UPDOWN)
            PlayerMoveDungeon(key & PADSTATE_UP, 0);
        if (key & PADSTATE_LEFTRIGHT) {
            if (key & PADSTATE_KA) {
                PlayerMoveDungeon(key & PADSTATE_RIGHT, 1);
                turn_hold = 0;
            } else {
                short turn_amt = 3 + turn_hold;
                if (turn_amt > 8) turn_amt = 8;
                cam_orientation = ClampAngle(cam_orientation +
                    ((key & PADSTATE_RIGHT) ? turn_amt : -turn_amt));
                turn_hold++;
            }
        } else {
            turn_hold = 0;
        }

        if (game_state == STATE_NEXTLVL) {
            player_hp += 3;
            if (player_hp > 10) player_hp = 10;
            GenerateLevel(current_level + 1);
            UpdateCounter3(&lvl_display, current_level);
            UpdateCounter2(&hp_display, player_hp);
            game_state = STATE_PLAYING;
        }
        else if (game_state == STATE_GAMEOVER) break;
        else UpdateCounter2(&hp_display, player_hp);
    } while (1);

    /* Wait for keys released */
    while (_rowread(0) & 0xff);

    GrayOff();
    LCD_restore(lcd);

    if (game_state == STATE_GAMEOVER)
        ST_helpMsg("GAME OVER! Descend HW4 Edition");
    else
        ST_helpMsg("Descend HW4 - Standalone Raycaster");

    RestoreHandlerForINTs();
    OSqclear(kbd_queue());
}
