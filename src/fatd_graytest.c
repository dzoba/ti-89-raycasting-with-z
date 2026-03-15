/* fatd_graytest.c - Test grayscale on real TI-89 Titanium HW4 */
#define USE_TI89
#define OPTIMIZE_ROM_CALLS
#include <tigcclib.h>

void _main(void) {
    if (!GrayOn()) {
        ClrScr();
        DrawStr(10, 40, "GrayOn FAILED!", A_NORMAL);
        DrawStr(10, 55, "Press any key...", A_NORMAL);
        ngetchx();
        return;
    }

    /* Draw something on each plane to confirm grayscale works */
    /* Light plane: filled rectangle */
    memset(GetPlane(LIGHT_PLANE) + 30*30, 0xFF, 30*4);
    /* Dark plane: filled rectangle offset */
    memset(GetPlane(DARK_PLANE) + 30*30 + 30*2, 0xFF, 30*4);

    /* Also draw text on light plane */
    GraySetAMSPlane(LIGHT_PLANE);
    DrawStr(10, 10, "Gray OK! Light", A_NORMAL);
    GraySetAMSPlane(DARK_PLANE);
    DrawStr(10, 20, "Gray OK! Dark", A_NORMAL);

    ngetchx();
    GrayOff();
}
