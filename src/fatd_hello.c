/* fatd_hello.c - Simple test program for TI-89 Titanium */
#define USE_TI89
#define OPTIMIZE_ROM_CALLS
#include <tigcclib.h>

void _main(void) {
    ClrScr();
    DrawStr(10, 40, "Hello from USB!", A_NORMAL);
    DrawStr(10, 55, "Press any key...", A_NORMAL);
    ngetchx();
}
