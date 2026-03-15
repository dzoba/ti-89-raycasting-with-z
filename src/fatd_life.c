/* fatd_life.c - Conway's Game of Life in grayscale for TI-89 Titanium HW4
 *
 * Runs on a 160x100 grid (full LCD). Grayscale shows cell age:
 *   newborn = light gray, young = dark gray, old = black
 * Press ESC to exit. Press any arrow to seed random cells.
 *
 * Optimized: bitwise parallel neighbor counting processes 16 cells at once
 * using a vertical full-adder tree instead of per-cell function calls.
 */
#define USE_TI89
#define OPTIMIZE_ROM_CALLS
#include <tigcclib.h>

#define W 160
#define H 100
#define WPR 10  /* words per row: 160/16 */
#define TOTAL (WPR * H)  /* 1000 */

static unsigned short cells[TOTAL];
static unsigned short ncells[TOTAL];
/* Age stored as two bit planes for fast rendering */
static unsigned short age_lo[TOTAL];  /* age bit 0 -> light plane */
static unsigned short age_hi[TOTAL];  /* age bit 1 -> dark plane */

static unsigned long rng = 123456789UL;
static unsigned short rng16(void) {
    rng = rng * 1664525UL + 1013904223UL;
    return (unsigned short)(rng >> 16);
}

static void seed_random(void) {
    short i;
    short cx = rng16() % (W - 20) + 10;
    short cy = rng16() % (H - 20) + 10;
    for (i = 0; i < 80; i++) {
        short x = cx + (rng16() % 20) - 10;
        short y = cy + (rng16() % 20) - 10;
        if (x >= 0 && x < W && y >= 0 && y < H) {
            short idx = y * WPR + (x >> 4);
            unsigned short mask = 1 << (15 - (x & 15));
            cells[idx] |= mask;
            age_lo[idx] &= ~mask;
            age_hi[idx] &= ~mask;
        }
    }
}

void _main(void) {
    unsigned short *p0, *p1;
    short y;

    if (!GrayOn()) {
        ClrScr();
        DrawStr(10, 40, "GrayOn FAILED!", A_NORMAL);
        ngetchx();
        return;
    }

    memset(cells, 0, sizeof(cells));
    memset(ncells, 0, sizeof(ncells));
    memset(age_lo, 0, sizeof(age_lo));
    memset(age_hi, 0, sizeof(age_hi));

    p0 = (unsigned short *)GetPlane(LIGHT_PLANE);
    p1 = (unsigned short *)GetPlane(DARK_PLANE);
    memset(p0, 0, LCD_SIZE);
    memset(p1, 0, LCD_SIZE);

    rng = *(volatile unsigned long*)0x600016;
    seed_random();
    seed_random();
    seed_random();

    while (!(_rowread(0xFFBF) & 0x01)) {
        if (_rowread(0xFFFE) & 0x0F)
            seed_random();

        /* === Bitwise parallel simulation ===
         * For each word (16 cells), compute all 8 neighbors simultaneously
         * using shifted row data, then sum with a full-adder tree to get
         * a 4-bit population count per cell position.
         */
        for (y = 0; y < H; y++) {
            short ya = (y > 0) ? y - 1 : H - 1;
            short yb = (y < H - 1) ? y + 1 : 0;
            unsigned short *ra = &cells[ya * WPR];  /* row above */
            unsigned short *rc = &cells[y * WPR];   /* current row */
            unsigned short *rb = &cells[yb * WPR];  /* row below */
            short wx;

            for (wx = 0; wx < WPR; wx++) {
                short pw = (wx > 0) ? wx - 1 : WPR - 1;
                short nw = (wx < WPR - 1) ? wx + 1 : 0;
                unsigned short n0,n1,n2,n3,n4,n5,n6,n7;
                unsigned short h0s,h0c,h1s,h1c,h2s,h2c,h3s,h3c;
                unsigned short h4s,h4c,h5s,h5c,h6c;
                unsigned short f0s,f0c,f1s,f1c,f2c;
                unsigned short bit0,bit1,bit2,bit3;
                unsigned short alive, old, survived, born, ol, oh;
                short idx = y * WPR + wx;

                /* 8 neighbor words via bit-shifting with toroidal wrap */
                n0 = (ra[wx] >> 1) | ((ra[pw] & 1) << 15);  /* above-left */
                n1 = ra[wx];                                  /* above-center */
                n2 = (ra[wx] << 1) | (ra[nw] >> 15);         /* above-right */
                n3 = (rc[wx] >> 1) | ((rc[pw] & 1) << 15);   /* left */
                n4 = (rc[wx] << 1) | (rc[nw] >> 15);         /* right */
                n5 = (rb[wx] >> 1) | ((rb[pw] & 1) << 15);   /* below-left */
                n6 = rb[wx];                                  /* below-center */
                n7 = (rb[wx] << 1) | (rb[nw] >> 15);         /* below-right */

                /* Vertical full-adder tree: sum 8 single-bit inputs per position
                 * to get 4-bit count (bit3:bit2:bit1:bit0) */

                /* Level 1: 4 half-adders -> 4 weight-1 sums, 4 weight-2 carries */
                h0s=n0^n1; h0c=n0&n1;
                h1s=n2^n3; h1c=n2&n3;
                h2s=n4^n5; h2c=n4&n5;
                h3s=n6^n7; h3c=n6&n7;

                /* Level 2-3: reduce weight-1 sums */
                h4s=h0s^h1s; h4c=h0s&h1s;
                h5s=h2s^h3s; h5c=h2s&h3s;
                bit0=h4s^h5s; h6c=h4s&h5s;

                /* Level 4-5: reduce weight-2 carries (7 bits) */
                f0s=h0c^h1c^h2c; f0c=(h0c&h1c)|((h0c^h1c)&h2c);
                f1s=h3c^h4c^h5c; f1c=(h3c&h4c)|((h3c^h4c)&h5c);
                bit1=f0s^f1s^h6c; f2c=(f0s&f1s)|((f0s^f1s)&h6c);

                /* Level 6: reduce weight-4 carries (3 bits) */
                bit2=f0c^f1c^f2c;
                bit3=(f0c&f1c)|((f0c^f1c)&f2c);

                /* Life rule: alive if count==3 OR (count==2 AND was_alive)
                 * count 2 = 0010, count 3 = 0011
                 * Both have bit3=0, bit2=0, bit1=1
                 * So: alive = ~bit3 & ~bit2 & bit1 & (bit0 | old_cell) */
                old = rc[wx];
                alive = ~bit3 & ~bit2 & bit1 & (bit0 | old);
                ncells[idx] = alive;

                /* Update ages: survived cells age+1 (saturate at 3),
                 * born cells start at age 1 (light gray, immediately visible) */
                survived = old & alive;
                born = alive & ~old;
                ol = age_lo[idx]; oh = age_hi[idx];
                /* Increment with saturation: 00->01, 01->10, 10->11, 11->11
                 * new_hi = (hi|lo), new_lo = (~lo|hi) */
                age_hi[idx] = (oh | ol) & survived;
                age_lo[idx] = ((~ol | oh) & survived) | born;

                /* Render: age_lo -> light plane, age_hi -> dark plane
                 * age 1: light gray, age 2: dark gray, age 3: black */
                p0[y * 15 + wx] = alive & age_lo[idx];
                p1[y * 15 + wx] = alive & age_hi[idx];
            }
        }

        memcpy(cells, ncells, sizeof(cells));

        /* Auto-reseed if population dies out */
        {
            short i, pop = 0;
            for (i = 0; i < TOTAL; i++) {
                unsigned short v = cells[i];
                v = (v & 0x5555) + ((v >> 1) & 0x5555);
                v = (v & 0x3333) + ((v >> 2) & 0x3333);
                v = (v + (v >> 4)) & 0x0F0F;
                pop += (v + (v >> 8)) & 0xFF;
            }
            if (pop < 5) {
                seed_random();
                seed_random();
            }
        }
    }

    GrayOff();
}
