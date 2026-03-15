/******************************************************************************
*
* project name:    FAT-SDK
* file name:       fatload.c
* initial date:    03/05/2002
* author:          thomas.nussbaumer@gmx.net
* description:     start utility for exepacked FAT-Demos
*
* (based on the code of ttstart from the TIGCC Tools Suite)
*
* $Id: fatload.c,v 1.2 2002/05/22 09:41:55 tnussb Exp $
*
******************************************************************************/

#define USE_TI89       // compile for TI89
#define USE_TI92P      // compile for TI92p
#define USE_V200       // compile for V200

#define NO_EXIT_SUPPORT     // the launcher doesn't need exit support
#define OPTIMIZE_ROM_CALLS  // generates smaller code by reserving a5

//-----------------------------------------------------------------------------
// DIRTY: This is needed to get everything to work with "complex main"s
//        (Kevin Kofler)
//-----------------------------------------------------------------------------
asm("/* Include Patch: save_the_sp */");
extern void *__save__sp__;

#include <statline.h>
#include <alloc.h>
#include <vat.h>
#include <string.h>
#include <system.h>
#include <graph.h>
#include <menus.h>
#include <kbd.h>
#include <compat.h>

#define fatal(s) {ST_showHelp(s); return;}


#define C89_92(x,y) ((TI89)?(x):(y))


typedef struct {
    unsigned char  osize_lo;   // original size lowbyte
    unsigned char  osize_hi;   // original size highbyte
    unsigned char  magic1;     // must be equal to TTUNPACK_MAGIC1
    unsigned char  magic2;     // must be equal to TTUNPACK_MAGIC2
    unsigned char  csize_lo;   // compressed size lowbyte
    unsigned char  csize_hi;   // compressed size lowbyte
    unsigned char  esc1;       // escape >> (8-escBits)
    unsigned char  notused3;
    unsigned char  notused4;
    unsigned char  esc2;       // escBits
    unsigned char  gamma1;     // maxGamma + 1
    unsigned char  gamma2;     // (1<<maxGamma)
    unsigned char  extralz;    // extraLZPosBits
    unsigned char  notused1;
    unsigned char  notused2;
    unsigned char  rleentries; // rleUsed
} TTUNPACK_HEADER;

#define TTUNPACK_MAGIC1 0x54
#define TTUNPACK_MAGIC2 0x50

#define ttunpack_size(_p_)  ((unsigned short)(((TTUNPACK_HEADER*)(_p_))->osize_lo | (((TTUNPACK_HEADER*)(_p_))->osize_hi << 8)))
#define ttunpack_valid(_p_) (((TTUNPACK_HEADER*)(_p_))->magic1 == TTUNPACK_MAGIC1 && ((TTUNPACK_HEADER*)(_p_))->magic2 == TTUNPACK_MAGIC2)

#define TTUNPACK_OKAY             0
#define TTUNPACK_NOESCFOUND     248
#define TTUNPACK_ESCBITS        249
#define TTUNPACK_MAXGAMMA       250
#define TTUNPACK_EXTRALZP       251
#define TTUNPACK_NOMAGIC        252
#define TTUNPACK_OUTBUFOVERRUN  253
#define TTUNPACK_LZPOSUNDERRUN  254

#define ttunpack_decompress ((unsigned short(*)(unsigned char*,unsigned char*))(unsigned short[]){\
0x48e7,0x7ffa,0x4fef,0xffe8,0x206f,0x0050,0x0c28,0x0054,0x0002,0x6608,\
0x0c28,0x0050,0x0003,0x6708,0x303c,0x00fc,0x6000,0x0264,0x4286,0x1c28,\
0x0006,0x4247,0x1e28,0x0009,0x4245,0x1a28,0x000a,0x5345,0x4240,0x1028,\
0x000c,0x3c40,0x7201,0xeb69,0x3f41,0x000e,0x7002,0xeb68,0x3f40,0x000c,\
0x7208,0x9245,0x3f41,0x000a,0x7008,0x9047,0x3840,0x303c,0x00f9,0x0c47,\
0x0008,0x6200,0x021e,0x4240,0x1028,0x000b,0xb06f,0x000e,0x660c,0x0c45,\
0x0004,0x6306,0x0c45,0x0007,0x6308,0x303c,0x00fa,0x6000,0x01fe,0x7204,\
0xb24e,0x6408,0x303c,0x00fb,0x6000,0x01f0,0x43e8,0x000f,0x2f49,0x0010,\
0x266f,0x0054,0x43fa,0x01ea,0x2f49,0x0006,0x226f,0x0010,0x4280,0x1011,\
0x41f0,0x0810,0x226f,0x0006,0x2288,0x41fa,0x01d4,0x2f48,0x0002,0x30bc,\
0x0080,0x3606,0x4a47,0x670c,0x3f07,0x41fa,0x0274,0x4e90,0x3600,0x548f,\
0x3043,0xbc88,0x6600,0x018c,0x3f05,0x45fa,0x021a,0x4e92,0x3800,0x426f,\
0x0002,0x548f,0x0c44,0x0001,0x6754,0x3f05,0x4e92,0x3600,0x5343,0x302f,\
0x000e,0x5540,0x548f,0xb043,0x6618,0x0c44,0x0003,0x6300,0x0170,0x45fa,\
0x017e,0x4e92,0x3f40,0x0000,0x4e92,0x6000,0x0120,0x300e,0x6710,0x3f0e,\
0x41fa,0x021a,0x4e90,0x320e,0xe36b,0x8640,0x548f,0x41fa,0x015a,0x4e90,\
0x0a40,0x00ff,0x3203,0xe149,0x8240,0x6000,0x00fe,0x226f,0x0006,0x2051,\
0x4240,0x1010,0x206f,0x0002,0x3210,0xc041,0x6700,0x00ca,0xe219,0x6402,\
0x5291,0x3081,0x2051,0x4240,0x1010,0xc041,0x6630,0x3001,0xe218,0x6402,\
0x5291,0x226f,0x0002,0x3280,0x3f07,0x45fa,0x01c0,0x4e92,0x3600,0x3f0c,\
0x4e92,0x320c,0x48c1,0xe3ae,0x8c00,0x16c6,0x4286,0x3c03,0x588f,0x6000,\
0xff26,0x3001,0xe218,0x6402,0x5291,0x206f,0x0002,0x3080,0x3f05,0x4e92,\
0x3600,0x548f,0xb66f,0x000e,0x6522,0x3f2f,0x000a,0x41fa,0x0180,0x4e90,\
0x966f,0x0010,0x322f,0x000c,0xe36b,0x8640,0x3f05,0x4e92,0x5340,0xe148,\
0x8640,0x588f,0x3f05,0x4e92,0x3800,0x548f,0x0c44,0x001f,0x6210,0x4280,\
0x3004,0x206f,0x0010,0x1230,0x0800,0x4881,0x6016,0x3f3c,0x0003,0x41fa,\
0x0140,0x4e90,0x3204,0x0641,0xffe0,0xe749,0x8240,0x548f,0x4242,0xb642,\
0x6500,0xfeac,0x16c1,0x5242,0xb642,0x64f8,0x6000,0xfea0,0x3001,0x226f,\
0x0006,0xe218,0x6402,0x5291,0x206f,0x0002,0x3080,0x41fa,0x0056,0x4e90,\
0x3200,0x0a41,0x00ff,0x4242,0xb842,0x6500,0xfe7a,0x4280,0x3001,0x204b,\
0x91c0,0x102f,0x0001,0xd028,0xffff,0x16c0,0x5242,0xb842,0x64e8,0x6000,\
0xfe5e,0x3f0c,0x41fa,0x00d6,0x4e90,0x320c,0xe36b,0x8600,0x16c3,0x548f,\
0x6000,0xfe48,0x4240,0x4fef,0x0018,0x4cdf,0x5ffe,0x4e75,0x0000,0x0000,\
0x0000,0x41fa,0xfff8,0x2250,0x4240,0x1019,0x2089,0x323a,0xfff0,0x0c01,\
0x0080,0x6602,0x4e75,0xe148,0x1011,0x0c01,0x0008,0x6212,0x6630,0x0240,\
0x0fff,0xe848,0x4e75,0x0240,0x7fff,0xee48,0x4e75,0x0c01,0x0020,0x62f2,\
0x6508,0x0240,0x3fff,0xec48,0x4e75,0x0240,0x1fff,0xea48,0x4e75,0x0240,\
0x07ff,0xe648,0x4e75,0x0c01,0x0002,0x62f2,0x6608,0x0240,0x03ff,0xe448,\
0x4e75,0x0240,0x01ff,0xe248,0x4e75,0x2f03,0x4281,0x302f,0x0008,0x207a,\
0xff84,0x343a,0xff84,0xb041,0x6312,0x3602,0xc610,0xe21a,0x6402,0x5288,\
0x4a03,0x6704,0x5241,0x60ea,0x2608,0x41fa,0xff64,0x2083,0x41fa,0xff62,\
0x3082,0x2043,0x7601,0xe36b,0x3f01,0x6108,0x544f,0x8043,0x261f,0x4e75,\
0x4240,0x322f,0x0004,0x6730,0x207a,0xff3e,0x2243,0x343a,0xff3c,0x5341,\
0xe348,0x3602,0xc610,0x6702,0x5200,0xe21a,0x6402,0x5288,0x51c9,0xffee,\
0x2609,0x43fa,0xff20,0x3282,0x43fa,0xff16,0x2288,0x2243,0x4e75})



//-----------------------------------------------------------------------------
// we use an own implementation of enter_ghost_space, because due to the
// arrangements within TIGCCLIB (comes as real compile-time library since 2.4)
// otherwise we cannot generate a compatible pstarter.o anymore
// (the launcher generated with TIGCC option -pack will not be linked against
// tigcc.a)
//-----------------------------------------------------------------------------
void own_enter_ghost_space(void);
asm("own_enter_ghost_space:\n"
"	bsr.w 0f\n"
"0:\n"
"	move.l (%sp)+,%d0\n"
"	cmpi.l #0x40000,%d0\n"
"	bcc.s 2f\n"
"	movea.l 0xC8,%a0\n"
"	cmpi.l #1000,(%a0,-4)\n"
"	bcs.s 2f\n"
"	movem.l %a2-%a6/%d3-%d7,-(%sp)\n"
"	lea (%sp,-20),%sp\n"
"	move.l #0x3E000,%a3\n"
"	move.l %a0,%d0\n"
"	andi.l #0x600000,%d0\n"
"	addi.l #0x20000,%d0\n"
"	move.l %d0,(%sp,12)\n"
"	move.l %d0,(%sp,16)\n"
"	trap #0xC\n"
"	move.w #0x2700,%sr\n"
"	move.l #0xF,%d3\n"
"	pea 1f(%pc)\n"
"	bset.b #2,(%sp,1)\n"
"	clr.w  -(%sp)\n"
"	move.l 0xAC,%a0\n"
"	jmp (%a0)\n"
"1:\n"
"	lea (%sp,20),%sp\n"
"	movem.l (%sp)+,%a2-%a6/%d3-%d7\n"
"2:\n"
"	move.l (%sp)+,%d0\n"
"	bset.l #18,%d0\n"
"	movea.l %d0,%a0\n"
"	jmp (%a0)");


//-----------------------------------------------------------------------------
// The following macro calls function fptr and treats a possible RETURN_VALUE
// correctly. If a return value is available mode is set to 0, otherwise 1
//
// NOTE: the NOPs are very important due to a dirty hack in the TIGCCLIB with
//       define RETURN_VALUE (they must be exactly after the call!!)
//-----------------------------------------------------------------------------

#define ASM_CALL_WITH_RETURN_VALUE_HANDLING(fptr,mode) ({\
        asm volatile ("movem.l %%d1-%%d7/%%a0-%%a6,-(%%sp);"\
            "jsr (%1);"\
            "bra.s 0f;"\
            "nop;nop;"\
            "clr.b %%d0;"\
            "bra.s 1f;"\
            "0: st.b %%d0;"\
            "1: movem.l (%%sp)+,%%d1-%%d7/%%a0-%%a6;"\
            "move.b %%d0,%0"\
            : "=d" (mode) : "a" ((void *)(fptr)) : "d0","cc","memory");})



//-----------------------------------------------------------------------------
// embedded version string -- EDITED BY HAND!
//
// NOTE: this version string is embedded in ALL variants and its should !!NOT!!
//       be removed by anyone
//
// to force the compiler to embed the string in all case this variable is
// volatile by intention!
//-----------------------------------------------------------------------------
volatile const char embedded_ttstart_version[]="[tts114]";

short last_loaded = 0;

//=============================================================================
// handle selection of a demo
//=============================================================================
SYM_ENTRY* HandleDemoSelection() {
    short          previous_font = FontGetSys();
    short          index   = 1;
    short          found   = 0;
    short          i;
    unsigned short length;
    unsigned char* src;
    unsigned char* dest;
    short          popup  = PopupNew((char*)"SELECT a FAT-Demo",C89_92(53,69));
    SYM_ENTRY*     symptr  = SymFindFirst($(main),1);
    char           name[9];
    LCD_BUFFER     screen;

    LCD_save(screen);
    name[8] = 0;

    ClearScreen();
    DrawClipRect(ScrToWin(ScrRect),ScrRect,A_NORMAL);
    DrawStrXY(C89_92(16,35),3,"FAT-Engine Demo Loader",A_NORMAL);
    FontSetSys(F_4x6);
    DrawStrXY(C89_92(8,51),C89_92(85,110),"(c) 2001-2002 TICT (http://tict.ticalc.org)",A_NORMAL);

    while (symptr) {
        if (!strncmp(symptr->name,"fatd",4)) {
            if ((src = HeapDeref(symptr->handle))) {
                length = *(unsigned short*)src+3;
                dest   = src+length-2;

                src += 2;
                if (*dest     == 0xF8 &&
                    *(dest-4) == 'p'  &&
                    *(dest-3) == 'p'  &&
                    *(dest-2) == 'g'  &&
                    ttunpack_valid(src))
                {
                    strncpy(name,symptr->name,8);
                    found++;
                    PopupAddText(popup,-1,name,index);
                }
            }
        }
        symptr=SymFindNext();
        index++;
    }

    if (found<(last_loaded-1)) last_loaded = 0;
    if (found) last_loaded = PopupDo(popup,CENTER,CENTER,last_loaded);
    else {
        DrawStr(C89_92(40,80),30,"No FAT-Demos found !!!",A_REPLACE);
        last_loaded = 0;
        ngetchx();
    }
    ClearScreen();
    HeapFree(popup);
    LCD_restore(screen);
    FontSetSys(previous_font);

    if (!last_loaded) return NULL;

    symptr=SymFindFirst($(main),1);
    for(i=1;i<last_loaded;i++) symptr=SymFindNext();
    return symptr;
}

//=============================================================================
// nothing special, just a huge main routine ...
//=============================================================================
void _main(void) {
    unsigned char*         src;
    unsigned char*         dest;
    unsigned short         length;
    HANDLE                 h,uncomp_h=0;
    volatile unsigned char mode;
    SYM_ENTRY*             symptr;

    if (!(symptr=HandleDemoSelection())) return;

    //-------------------------------------------------------------------------
    // IMPORTANT: only use handle (symptr may become invalid !!!)
    //-------------------------------------------------------------------------
    h = symptr->handle;

    //-------------------------------------------------------------------------
    // if file is already locked, don't lock it again ...
    //-------------------------------------------------------------------------
    if (HeapGetLock(h)) {
        src = HeapDeref(h);
        h   = 0;
    }
    else {
        src = HLock(h);
    }

    if (!src) fatal("locking failed"); // will return!

    length = *(unsigned short*)src+3;
    dest   = src+length-2;


    //---------------------------------------------------------------------
    // skip "length of variable" bytes
    //---------------------------------------------------------------------
    src += 2;
    //---------------------------------------------------------------------
    // get the original size and allocate memory for it
    //---------------------------------------------------------------------
    length = ttunpack_size(src);

    // NOTE: we don't use malloc, but the low level routines
    //       otherwise compressed kernel-dependent progs will crash
    if (!(uncomp_h=HeapAllocHigh(length))) {
        if (h) HeapUnlock(h);
        fatal("out of memory");
    }

    dest = HeapDeref(uncomp_h);

    ST_showHelp("decompressing ...");

    if (ttunpack_decompress(src,dest)) {
        //-------------------------------------------------------------
        // "houston we got problems ..."
        //-------------------------------------------------------------
        HeapFree(uncomp_h);
        if (h) HeapUnlock(h);
        fatal("failed");
    }
    ST_eraseHelp();

    //-------------------------------------------------------------------------
    // relocate the executable, enter the ghostspace and start it ...
    //-------------------------------------------------------------------------
    // Detect TI-89 Titanium: bit 23 of ROM base is set on Titanium
    if ((unsigned long)(*(void**)0xC8) & 0x800000) {
        // Titanium (HW3+): no ghost space, use regular addresses.
        // TiEmu must be launched with -hwprot=0 to disable RAM
        // execution protection for this to work.
        EX_patch(dest+2,dest+length-1);
        ASM_CALL_WITH_RETURN_VALUE_HANDLING(dest+2,mode);
    } else {
        // Standard TI-89/TI-92+ (HW1/HW2): use ghost space
        EX_patch(dest+0x40002,dest+length+0x3FFFF);
        own_enter_ghost_space();
        {(*(unsigned long *)__save__sp__)|=0x40000;}
        ASM_CALL_WITH_RETURN_VALUE_HANDLING(dest+0x40002,mode);
    }

    HeapFree(uncomp_h);

    if (h) HeapUnlock(h);

    if (!mode) {
        //---------------------------------------------------------------------
        // launched program uses RETURN_VALUE - handle it correctly
        // (VERY dirty trick implemented Kevin Kofler
        //---------------------------------------------------------------------
        {
            if (*(((unsigned short **)__save__sp__)[2])==0x21ee) ((unsigned short **)__save__sp__)[2]+=3;
            else                                                 ((unsigned short **)__save__sp__)[2]+=2;
        }
    }
}

//#############################################################################
//###################### NO MORE FAKES BEYOND THIS LINE #######################
//#############################################################################
//
//=============================================================================
// Revision History
//=============================================================================
//
// $Log: fatload.c,v $
// Revision 1.2  2002/05/22 09:41:55  tnussb
// stepped back to old version of unpacking function to fix "random" triggers
// of ERR_Throw
//
// Revision 1.1  2002/05/03 11:32:17  tnussb
// initial version
//
//
//

