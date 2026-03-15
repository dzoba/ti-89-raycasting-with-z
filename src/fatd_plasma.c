/* fatd_plasma.c - Fast grayscale plasma demo for TI-89 Titanium HW4 */
#define USE_TI89
#define OPTIMIZE_ROM_CALLS
#include <tigcclib.h>

/* 256-entry sin table: values -64..63 */
static signed char stab[256];

static void init_stab(void) {
    short i;
    /* Build sin table from parabolic approximation */
    for (i = 0; i < 256; i++) {
        short x = i;
        short v;
        if (x < 64)       v = (short)((x * (128 - x * 2)) >> 6);
        else if (x < 128)  v = (short)(((128 - x) * (128 - (128 - x) * 2)) >> 6);
        else if (x < 192)  { x -= 128; v = (short)(-((x * (128 - x * 2)) >> 6)); }
        else               { x -= 128; v = (short)(-((128 - x) * (128 - (128 - x) * 2)) >> 6); }
        stab[i] = (signed char)v;
    }
}

void _main(void) {
    unsigned short *p0, *p1;
    unsigned char frame = 0;
    short y;
    /* Precomputed row contribution: sin1[x] for x=0..159 */
    signed char sin1[160];

    if (!GrayOn()) {
        ClrScr();
        DrawStr(10, 40, "GrayOn FAILED!", A_NORMAL);
        ngetchx();
        return;
    }

    init_stab();
    p0 = (unsigned short *)GetPlane(LIGHT_PLANE);
    p1 = (unsigned short *)GetPlane(DARK_PLANE);

    while (!(_rowread(0xFFBF) & 0x01)) {  /* ESC */
        unsigned short *lp = p0;
        unsigned short *dp = p1;
        short x;

        /* Precompute X-dependent sine for this frame */
        for (x = 0; x < 160; x++)
            sin1[x] = stab[(unsigned char)(x + frame)];

        for (y = 0; y < 100; y++) {
            signed char ysin = stab[(unsigned char)(y + (frame >> 1))];
            unsigned char yframe = (unsigned char)((y + frame) >> 1);
            short wx;

            for (wx = 0; wx < 10; wx++) {
                unsigned short lw = 0, dw = 0;
                short bit;
                short bx = wx << 4;

                for (bit = 15; bit >= 0; bit--) {
                    short px = bx + (15 - bit);
                    short v;
                    /* Two table lookups instead of four function calls */
                    v = sin1[px] + ysin + stab[(unsigned char)(px + yframe)];
                    /* v ranges roughly -192..189, map to 0..3 */
                    v = (v >> 5) + 2;
                    if (v < 0) v = 0;
                    if (v > 3) v = 3;
                    if (v & 2) lw |= (1 << bit);
                    if (v & 1) dw |= (1 << bit);
                }
                *lp++ = lw;
                *dp++ = dw;
            }
            lp += 5; dp += 5;
        }

        frame += 2;
    }

    GrayOff();
}
