/******************************************************************************
*
* project name:   FAT-Engine
* file name:      fat.h
* initial date:   04/03/2001
* author:         thomas.nussbaumer@gmx.net
*
* description:    FAT-Engine - Generic Definitions and Access Functionalities
*
*
*
* ENGINE VERSION: 1.11
*
*
* Additional Credits:
* -------------------
*
* Scott Noveck <noveck@pluto.njcc.com> for the 8-directional sprite support
* (TEX_xxxxx defines and FAT_SPRITE modifications), function arctan_xy and the
* doors support
*
* $Id: fat.h,v 1.33 2002/05/22 09:28:48 tnussb Exp $
*
******************************************************************************/

//-----------------------------------------------------------------------------
// to enable DEBUGGING please define FAT_USEDEBUG before you include file fat.h
// into your program!
//-----------------------------------------------------------------------------

//#define FAT_USEDEBUG

#ifndef __FAT_H__
#define __FAT_H__

//-----------------------------------------------------------------------------
// DON'T TURN ON THE FOLLOWING COMPILER-DIRECTIVE IN YOUR PROGRAM -
// OTHERWISE YOUR PROGRAM MAY CRASH !!!
//-----------------------------------------------------------------------------
//#define OPTIMIZE_ROM_CALLS   FAT-Engine is smaller when not used !!!

//-----------------------------------------------------------------------------
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!! IMPORTANT: FAT-Programs cannot use exit() !!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//-----------------------------------------------------------------------------
#define NO_EXIT_SUPPORT

#include <tigcclib.h>


//-----------------------------------------------------------------------------
// keypad defines and -type
//
// in general the keypad layout mimics the keypad layout of genlib
//-----------------------------------------------------------------------------
                                  // TI89  TI-92p
                                  // --------------
#define PADSTATE_ESC     0x0001   // ESC     ESC
#define PADSTATE_UP      0x0002   // up      up
#define PADSTATE_DOWN    0x0004   // down    down
#define PADSTATE_LEFT    0x0008   // left    left
#define PADSTATE_RIGHT   0x0010   // right   right
#define PADSTATE_APPS    0x0020   // APPS    APPS
#define PADSTATE_PLUS    0x0040   // +       +
#define PADSTATE_MINUS   0x0080   // -       -
#define PADSTATE_KA      0x0100   // 2nd     F1
#define PADSTATE_KB      0x0200   // Diamond F2
#define PADSTATE_KC      0x0400   // Home    F3
#define PADSTATE_KD      0x0800   // X       F4
#define PADSTATE_KE      0x1000   // Shift   F5
#define PADSTATE_KF      0x2000   // Alpha   F6
#define PADSTATE_KG      0x4000   // Mode    F7
#define PADSTATE_KH      0x8000   // Y       F8

#define PADSTATE_UPDOWN     (PADSTATE_UP|PADSTATE_DOWN)
#define PADSTATE_LEFTRIGHT  (PADSTATE_LEFT|PADSTATE_RIGHT)


typedef unsigned short PADSTATES;

//-----------------------------------------------------------------------------
// orientation defines
//-----------------------------------------------------------------------------
#define ANGLE_000    0
#define ANGLE_015   24
#define ANGLE_030   48
#define ANGLE_045   72
#define ANGLE_060   96
#define ANGLE_090  144
#define ANGLE_180  288
#define ANGLE_270  432
#define ANGLE_360  576 // don't use this value, use ANGLE_000 instead

#define MAX_DISTANCE 32000

#define SCREEN_WIDTH       ANGLE_060
#define SCREEN_WIDTH_HALF  ANGLE_030


//-----------------------------------------------------------------------------
// Order of textures in TEX_DIR8 (8 textures forming an 8-directional sprite)
//-----------------------------------------------------------------------------
#define TEX_AWAY          0
#define TEX_RIGHT_AWAY    1
#define TEX_RIGHT         2
#define TEX_RIGHT_TOWARD  3
#define TEX_TOWARD        4
#define TEX_LEFT_TOWARD   5
#define TEX_LEFT          6
#define TEX_LEFT_AWAY     7


//-----------------------------------------------------------------------------
// the following value is used to calculate the height from the distance
//
// height = SCALE_VALUE / distance
//-----------------------------------------------------------------------------

#define SCALE_VALUE (96L*56L)   // used to calculate height from distance


//-----------------------------------------------------------------------------
// angles when you look on the map as it is coded ...
//-----------------------------------------------------------------------------
#define ANGLE_NORTH  ANGLE_270
#define ANGLE_EAST   ANGLE_000
#define ANGLE_SOUTH  ANGLE_090
#define ANGLE_WEST   ANGLE_180


//-----------------------------------------------------------------------------
// equates used by doors
//-----------------------------------------------------------------------------
#define DOOR_HORIZONTAL    0
#define DOOR_VERTICAL      1

#define PWALL_NORTH        2  // DON'T USE! (not implemented yet)
#define PWALL_SOUTH        4  // DON'T USE! (not implemented yet)
#define PWALL_WEST         8  // DON'T USE! (not implemented yet)
#define PWALL_EAST        16  // DON'T USE! (not implemented yet)

#define DOOR_CLOSED        0
#define DOOR_CLOSING       1
#define DOOR_OPENING       2
#define DOOR_OPEN          3

#define CLOSED_DOOR_TILE   127
#define OPEN_DOOR_TILE    -127

#define MAX_NR_DOORS      64


//-----------------------------------------------------------------------------
// values for the mirrored field of structure TEXSTRIP
//-----------------------------------------------------------------------------
#define STRIP_NORMAL 0   // render strip normally
#define STRIP_MIRROR 1   // render strip mirrored
#define STRIP_IGNORE 2   // don't render this strip (only for sprites yet!)


//-----------------------------------------------------------------------------
// single texture strip 16 pixel "wide" and 64 pixel "tall"
// (in real it's 64 pixel "wide" and 16 pixel "tall" due to 90 degree rotation)
//-----------------------------------------------------------------------------
typedef struct {
    unsigned short* lightdata;   // pointer to a 16 "columns" wide strip (light plane data)
    unsigned short* darkdata;    // pointer to a 16 "columns" wide strip (dark  plane data)
    unsigned short* maskdata;    // a possible mask for it or NULL (ignored for walls!!)
    short           mirrored;    // if ==STRIP_NORMAL this strip is rendered normal
                                 // if ==STRIP_MIRRORED this strip is rendered mirrored
                                 // if ==STRIP_IGNORE this strip will be ignored (not rendered)
}
TEXSTRIP;


//-----------------------------------------------------------------------------
// texture description (64x64 pixels)
//-----------------------------------------------------------------------------
typedef struct {
    TEXSTRIP strips[4]; // each 64x64 pixel texture consists of 4 texture strips
} TEXCONFIG;


//-----------------------------------------------------------------------------
// animated texture (preliminary - DON'T use!)
//-----------------------------------------------------------------------------
typedef struct {
    TEXCONFIG*     dest;            // TEXCONFIG entry which should be animated
    unsigned char  anim_steps;      // number of TEXCONFIG frames
    unsigned char  anim_idx;        // actual displayed frame
    TEXCONFIG*     sources;
} TEXANIMATION;


//-----------------------------------------------------------------------------
// definitions for drawmodes of a sprite
//-----------------------------------------------------------------------------
#define SPRITEMODE_UNUSED    0    // don't render
#define SPRITEMODE_SIZE64    1    // render full 64-bit height of sprite
#define SPRITEMODE_UPPER32   2    // render only 32-bit upper part of sprite
#define SPRITEMODE_LOWER32   4    // render only 32-bit lower part of sprite


//-----------------------------------------------------------------------------
// sprite description
//-----------------------------------------------------------------------------
typedef struct _FATSPRITE {
    short              xpos;        // x position of sprite
    short              ypos;        // y position of sprite
    short              orientation; // orientation of sprite
    short              nr_textures; // number of textures used for this sprite
                                    // should be 8 for 8 directional sprites
    TEXCONFIG*         textures;    // pointer to start of texture array
    short              height;      // filled by FAT engine (-1 not visible)
    short              centerx;     // filled by FAT engine (-1 not visible)

    struct _FATSPRITE* prev;        // --- used by FAT engine for reversed Z drawing
                                    // (if this is NULL, than the actual sprite is the
                                    // farthest away sprite which is still visible)

    struct _FATSPRITE* next;        // --- used by FAT engine for reversed Z drawing
                                    // (starting from the farthest away sprite this
                                    //  points to the next nearest sprite OR NULL if
                                    //  there are no more visible sprites)

                                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void*              clientdata;  // maybe used freely by the client program to
                                    // store any data it wants (NOT USED BY ENGINE)
                                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    unsigned short     drawmode;    // sprite drawing mode to use
    short              dist;        // ONLY for FAT engine's internal use!
    short              angle;       // filled by FAT engine (angle between player and sprite)
                                    // (OR: -1 if sprite not visible!)
    unsigned short     reserved1;   // --- reserved for FAT engine's internals
    unsigned long      reserved2;   // --- reserved for FAT engine's internals
    unsigned long      reserved3;   // --- reserved for FAT engine's internals
} FATSPRITE;


//-----------------------------------------------------------------------------
// door description
//-----------------------------------------------------------------------------
typedef struct {
    short              xtile;       // x position of door (field MUST be HERE!!)
    short              ytile;       // y position of door (field MUST be HERE!!)
    unsigned char      type;        // DOOR_HORIZONTAL or DOOR_VERTICAL (NOT yet: PWALL_NORTH ...)
    unsigned char      state;       // DOOR_OPEN, DOOR_OPENING, DOOR_CLOSED, or DOOR_CLOSING
                                    // Note: state is not evaluated by the engine, its only
                                    //       for the client to keep track of the state of a door
    short              position;    // 0 = closed, 64 or higher = open, between = partially open
    TEXCONFIG*         doortexture; // pointer to door texture
    TEXCONFIG*         sidetexture; // pointer to side texture

                                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void*              clientdata;  // maybe used freely by the client program to
                                    // store any data it wants (NOT USED BY ENGINE)
                                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
} FATDOOR;


//-----------------------------------------------------------------------------
// the main config structure for the FAT-Engine
//-----------------------------------------------------------------------------
typedef struct {
    short           map_width;       // width of the map
    short           map_height;      // height of the map
    char*           map_data;        // pointer to the map data itself
    TEXCONFIG*      textures;        // pointer to the used textures
    short           nr_sprites;      // number of sprites
    FATSPRITE*      sprites;         // the sprite array
    short           cam_xpos;        // camera position x
    short           cam_ypos;        // camera position y
    short           cam_orientation; // camera orientation (0 .. 575)
    unsigned short* dest_plane0;     // destination plane0 to copy result into
    unsigned short* dest_plane1;     // destination plane1 to copy result into
    unsigned short* background;      // pointer to image with 96x96 pixels and 2 planes
    unsigned long   frame_counter;   // frame counter (gets incremented by engine)
} FATCONFIG;


//-----------------------------------------------------------------------------
// the depth buffer which can be retrieved by GetDepthBuffer()
//
// NOTE that you have to retrieve this buffer only once with
// FAT_GetDepthBuffer().
// After each call to FAT_Render() it will be filled with the actual data
//-----------------------------------------------------------------------------
typedef struct {
    short           height[ANGLE_060];       // used rendering heights (clipped)
    unsigned long   lightdata[ANGLE_060*2];  // used textures for light plane
    unsigned long   darkdata[ANGLE_060*2];   // used textures for dark  plane
    short           distance[ANGLE_060];     // distances (unclipped)
} DEPTHDATA;


//-----------------------------------------------------------------------------
// ACCESS FUNCTIONALITIES (JUST INTERNALS - PLEASE IGNORE)
//
// PLEASE DON'T USE THE DEFINES FOR THE VERSION IN YOUR PROGRAM, BUT USE
// the FAT_GetMainVersion(), FAT_GetSubVersion(), FAT_GetVersionString() or
// FAT_GetPoweredByString()
//-----------------------------------------------------------------------------
#define FAT_MAGIC        0x46415465L   // "FATe"
#define FAT_MAINVERSION   1            // must match engine main number
//#define PREFIX_ZERO
#define FAT_SUBVERSION   11            // may differ from engine sub number
#define FAT_NRENTRIES    46            // may be <= nr_entries of engine

//-----------------------------------------------------------------------------
// structure to access functions of FAT engine
//
// NOTE: using the exact function declarations enables the compiler to check
//       the parameter types
//
// IMPORTANT: if you don't change FAT_MAGIC or FAT_MAINVERSION than new entries
//            should be only appendent to the end of the following structure.
//            This way older programs still run with a newer engine version.
//-----------------------------------------------------------------------------
typedef struct {
    unsigned char*  buffer;  // used by the client to hold copy to allocated memory for engine
    unsigned long   magic;
    unsigned short  main_version;
    unsigned short  sub_version;
    unsigned short  nrentries;
    short           (*_get_sin16384)(short);
    volatile short*  _fat_sincos16384;     // 16384*sin(x) - 144 entries
    short           (*_fat_initengine)(void);
    void            (*_fat_cleanupengine)(void);
    void            (*_fat_render)(FATCONFIG*);
    DEPTHDATA*      (*_get_depthbuf)(void);
    short           (*_get_clipheight)(void);
    void            (*_set_predraw_callback)(void(*)(FATCONFIG*,DEPTHDATA*));
    volatile short* _tab_fisheye;      // --------   -  96 entries
    volatile short* _tab_xstep;        // 64/tan(x)  - 144 entries
    volatile short* _tab_ystep;        // 64*tan(x)  - 144 entries
    volatile short* _tab_div_sin;      // 128/sin(x) - 144 entries
    volatile short* _tab_tan;          // 256*tan(x) - 144 entries
    volatile short* _tab_div_tan;      // 256/tan(x) - 144 entries
    short           (*_fat_unpackbuffer)(unsigned char*, unsigned char*);
    char*           _version_string;
    char*           _poweredby_string;
    char*           _copyright_string;
    char*           _builddate_string;
    char*           _buildtime_string;
    void            (*_setskipwords)(short);
    void            (*_sethud)(unsigned short*,unsigned short*,unsigned short*);
    void            (*_set_prehud_callback)(void(*)(FATCONFIG*,unsigned short*,unsigned short*));
    void            (*_setupperhud)(unsigned short*,unsigned short*,unsigned short*);
    void            (*_setlowerhud)(unsigned short*,unsigned short*,unsigned short*);
    short           (*_get_arctan_yx)(short,short);
    volatile unsigned short* _tab_tan512;  // tan(x)*512 - 144 entries
    long            (*_get_tan512)(short);
    HANDLE          (*_gethandleoffile)(const char*);
    short           (*_getnumberoftextures)(unsigned char*);
    short           (*_loadtextures)(TEXCONFIG*,unsigned char*,short,short);
    short           (*_getnumberofgenericdata)(unsigned char*);
    void*           (*_getgenericdata)(unsigned char*, short, unsigned short);
    unsigned long   (*_fastsqrt)(unsigned long);
    unsigned short  (*_getgenericdatalength)(unsigned char*,short);
    PADSTATES       (*_getpadstate)(void);
    void            (*_debugconsole)(FATCONFIG*);
    void            (*_debuguseslot)(short,const char*, void*,unsigned short);
    void            (*_debugfreeslot)(short);
    short           (*_adddoor)(short,short,unsigned char,unsigned char,short,TEXCONFIG*,TEXCONFIG*,void*);
    FATDOOR*        (*_getdoor)(short, short);
    FATDOOR*        (*_getdoorsarray)(void);
    short           (*_getnrdoors)(void);
    void            (*_removealldoors)(void);
    short           (*_displaylogo)(unsigned char*,unsigned char*,volatile long*,short);
    unsigned long*  _tiny_logo;
} FATINTERFACE;


//-----------------------------------------------------------------------------
// FAT debugging related stuff
//-----------------------------------------------------------------------------

#define FAT_DBG_CHAR_DEC        0
#define FAT_DBG_UCHAR_DEC       1
#define FAT_DBG_SHORT_DEC       2
#define FAT_DBG_USHORT_DEC      3
#define FAT_DBG_LONG_DEC        4
#define FAT_DBG_ULONG_DEC       5
#define FAT_DBG_CHAR_HEX        6
#define FAT_DBG_UCHAR_HEX       6
#define FAT_DBG_SHORT_HEX       7
#define FAT_DBG_USHORT_HEX      7
#define FAT_DBG_LONG_HEX        8
#define FAT_DBG_ULONG_HEX       8
#define FAT_DBG_STRING          9
#define FAT_DBG_NOTUSED    0xffff

#define FAT_DBG_NR_CLIENTSLOTS 70


//-----------------------------------------------------------------------------
// EXEPACK related stuff
//-----------------------------------------------------------------------------
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
} FAT_TTUNPACK_HEADER;

#define FAT_TTUNPACK_MAGIC1 0x54
#define FAT_TTUNPACK_MAGIC2 0x50

#define FAT_UnpackSize(_p_)  ((unsigned short)(((FAT_TTUNPACK_HEADER*)(_p_))->osize_lo | (((FAT_TTUNPACK_HEADER*)(_p_))->osize_hi << 8)))
#define FAT_ValidEXEPACK(_p_) (((FAT_TTUNPACK_HEADER*)(_p_))->magic1 == FAT_TTUNPACK_MAGIC1 && ((FAT_TTUNPACK_HEADER*)(_p_))->magic2 == FAT_TTUNPACK_MAGIC2)

#define FAT_UNPACK_OKAY             0
#define FAT_UNPACK_NOESCFOUND     248
#define FAT_UNPACK_ESCBITS        249
#define FAT_UNPACK_MAXGAMMA       250
#define FAT_UNPACK_EXTRALZP       251
#define FAT_UNPACK_NOMAGIC        252
#define FAT_UNPACK_OUTBUFOVERRUN  253
#define FAT_UNPACK_LZPOSUNDERRUN  254



#if !defined(FATENGINE_ITSELF)

static volatile char FAT_NOTLINKED_STR[]="FATAL: FAT-Engine not loaded";

//-----------------------------------------------------------------------------
// simple "protection" to guess immediately if a FAT function gets called
// without a call to FAT_LoadEngine() first
//-----------------------------------------------------------------------------
void FAT_NotLinked(void) {
    unsigned long  toggles = 0;
    unsigned short i;
    unsigned long* addr;
    ST_helpMsg((char*)FAT_NOTLINKED_STR);
    while (!(_rowread(0) & 0xff)) {
        addr = LCD_MEM;
        for (i=0;i<LCD_SIZE/8;i++,addr++) *addr = ~*addr;
        toggles++;
    }
    while (_rowread(0) & 0xff) {
        addr = LCD_MEM;
        for (i=0;i<LCD_SIZE/8;i++,addr++) *addr = ~*addr;
        toggles++;
    }
    if (toggles%2) {
        addr = LCD_MEM;
        for (i=0;i<LCD_SIZE/8;i++,addr++) *addr = ~*addr;
    }
}

//-----------------------------------------------------------------------------
// generates an instance of the FATINTERFACE and sets up the necessary fields
//-----------------------------------------------------------------------------
FATINTERFACE fatinterface = {
     0L,                       // will hold buffer with code of the FAT-Engine
     FAT_MAGIC,                // magic marker for FAT
     FAT_MAINVERSION,          // main version (NOTE: main versions must match!)
     FAT_SUBVERSION,           // sub version (NOTE: sub versions may be different)
     FAT_NRENTRIES,            // number of entries in pointer table below

     // NOTE: function pointer should be initialized with "(void*)FAT_NotLinked"
     //       normal pointer should be initialized with NULL
     //       and char pointers (strings) should be initialized with "(char*)FAT_NOTLINKED_STR"

     (void*)FAT_NotLinked,NULL,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     (void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,NULL,NULL,
     NULL,NULL,NULL,NULL,(void*)FAT_NotLinked,
     (char*)FAT_NOTLINKED_STR,(char*)FAT_NOTLINKED_STR,(char*)FAT_NOTLINKED_STR,(char*)FAT_NOTLINKED_STR,(char*)FAT_NOTLINKED_STR,
     (void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     (void*)FAT_NotLinked,NULL,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     (void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     (void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     (void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,(void*)FAT_NotLinked,
     NULL
};


//-----------------------------------------------------------------------------
// errorcodes returned by LinkFAT function
//-----------------------------------------------------------------------------
#define FAT_LOADOKAY        1    // linking successfully completed
#define FAT_NOTGHOSTSPACE  -1    // NOT IN GHOSTSPACE !!!
#define FAT_NOTFOUND       -2    // no matching fat engine found
#define FAT_LOCKFAILED     -3    // locking of variable failed
#define FAT_OUTOFMEM       -4    // malloc of buffer failed


//-----------------------------------------------------------------------------
// load the fat engine
//
// this routine performs the following steps:
//
// (1) find the FAT engine file (fatlib.dll)
// (2) allocate RAM and copy file into it
// (3) relocate engine to the ghostspace
// (4) call the InitEngine function
//-----------------------------------------------------------------------------
short FAT_LoadEngine(void) {
    SYM_ENTRY*      tmp_entry;
    unsigned char*  tmp_src;
    unsigned short  tmp_len;
    HANDLE          h;
    unsigned short* interface_start;
    unsigned long   program_counter;
    unsigned short  interface_offset = 0; // to make compiler happy

    asm volatile("bsr 0f; 0:move.l (%%sp)+,%0":"=g"(program_counter));

    fatinterface.buffer = 0L;   // initialize buffer variable to zero

    //-------------------------------------------------------------------------
    // program must be already in ghostspace (or on Titanium, just in RAM)
    //-------------------------------------------------------------------------
    if (program_counter < 0x40000 &&
        !((unsigned long)(*(void**)0xC8) & 0x800000))
        return FAT_NOTGHOSTSPACE;

    //-------------------------------------------------------------------------
    // traverse complete FAT to find fatlib.dll
    //-------------------------------------------------------------------------
    tmp_entry = SymFindFirst(NULL,2);
    while (tmp_entry) {
        // compare only the first 6 bytes! this makes it possible to release
        // major versions with different names like fatlib10.dll, fatlib20.dll
        // and minor version numbers can go instead of the zero !!
        // this way more than one fatlib file may be in one directory
        // (normal users and programmers are lazy, almost all files are located in
        // the "big-trashcan-main" folder
        if (!strncmp(tmp_entry->name,"fatlib",6)) {
            if (tmp_entry->handle && !tmp_entry->flags.bits.twin) {
                if (!(!tmp_entry->flags.bits.archived && HeapGetLock(tmp_entry->handle))) {
                    tmp_src         = HeapDeref(tmp_entry->handle);
                    tmp_len         = *(unsigned short*)(tmp_src)+2;
                    interface_start =  (unsigned short*)(tmp_src+2);
                    tmp_src        += tmp_len-1;

                    if (!memcmp(tmp_src-4,"dll\x00\xF8",5)) {
                        interface_offset = 0;
                        do {
                            if (*interface_start     == (unsigned short)(fatinterface.magic >> 16L) &&
                                *(interface_start+1) == (unsigned short)(fatinterface.magic & 0xffffL))
                            {
                                FATINTERFACE* tmpinterface = (FATINTERFACE*)(interface_start-2);

                                if (tmpinterface->main_version == fatinterface.main_version &&
                                    tmpinterface->sub_version  >= fatinterface.sub_version  &&
                                    tmpinterface->nrentries    >= fatinterface.nrentries)
                                {
                                     interface_offset = (unsigned char*)(interface_start) - (unsigned char*)HeapDeref(tmp_entry->handle);
                                     interface_offset += 6;
                                     break;
                                }
                            }
                            interface_start++;
                        }
                        while ((unsigned char*)interface_start < tmp_src);
                        if (interface_offset) break;
                    }
                }
            }
        }
        tmp_entry = SymFindNext();
    }


    if (!tmp_entry) return FAT_NOTFOUND;

    h = tmp_entry->handle;
    if (HeapLock(h)==H_NULL) return FAT_LOCKFAILED;

    // due to the OTH type variable of the FAT-Engine we have
    // to correct the pointer and the length !!!
    tmp_src  = HeapDeref(h);
    tmp_src += 2;
    tmp_len  = *(unsigned short*)(tmp_src)+2;
    interface_offset-=2;

    if (!(fatinterface.buffer = malloc(tmp_len))) {
        HeapUnlock(h);
        return FAT_OUTOFMEM;
    }

    memcpy(fatinterface.buffer,tmp_src,tmp_len);
    if ((unsigned long)(*(void**)0xC8) & 0x800000)
        EX_patch(fatinterface.buffer+2,fatinterface.buffer+tmp_len-1);
    else
        EX_patch(fatinterface.buffer+0x40002,fatinterface.buffer+tmp_len+0x3FFFF);
    memcpy(&(fatinterface.sub_version),
           fatinterface.buffer+interface_offset,fatinterface.nrentries*4+4);

    HeapUnlock(h);

    if (!(fatinterface._fat_initengine())) {
         free(fatinterface.buffer);
         return FAT_OUTOFMEM;
    }

    return FAT_LOADOKAY;
}

#define FAT_UnloadEngine()  if (fatinterface.buffer) {fatinterface._fat_cleanupengine();\
                                                      free(fatinterface.buffer);\
                                                      fatinterface.buffer = 0L;}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
// functions (and similar) exported by FAT engine - USE ONLY THESE DEFINES !!!
//
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#define FAT_GetMainVersion()     (fatinterface.main_version)
#define FAT_GetSubVersion()      (fatinterface.sub_version)
#define FAT_GetSinCos16384Tab()  (fatinterface._fat_sincos16384) // 145 entries
#define FAT_Sin16384             (fatinterface._get_sin16384)
#define FAT_Cos16384(a)          FAT_Sin16384(ANGLE_090+(a))
#define FAT_Render               (fatinterface._fat_render)
#define FAT_GetDepthBuffer       (fatinterface._get_depthbuf)
#define FAT_GetClipHeight        (fatinterface._get_clipheight)
#define FAT_SetPredrawCallback   (fatinterface._set_predraw_callback)
#define FAT_GetFisheyeTab()      (fatinterface._tab_fisheye) // --------   -  96 entries
#define FAT_Get64DivTanTab()     (fatinterface._tab_xstep)   // 64/tan(x)  - 144 entries
#define FAT_Get64TanTab()        (fatinterface._tab_ystep)   // 64*tan(x)  - 144 entries
#define FAT_Get128DivSinTab()    (fatinterface._tab_div_sin) // 128/sin(x) - 144 entries
#define FAT_Get256TanTab()       (fatinterface._tab_tan)     // 256*tan(x) - 144 entries
#define FAT_Get256DivTanTab()    (fatinterface._tab_div_tan) // 256/tan(x) - 144 entries
#define FAT_Get512TanTab()       (fatinterface._tab_tan512)  // 512*tan(x) - 144 entries (UNSIGNED SHORT!!)
#define FAT_UnpackBuffer         (fatinterface._fat_unpackbuffer) // unpack routine for exepacked stuff
#define FAT_GetVersionString()   (fatinterface._version_string)
#define FAT_GetPoweredByString() (fatinterface._poweredby_string)
#define FAT_GetCopyrightString() (fatinterface._copyright_string)
#define FAT_GetBuildDateString() (fatinterface._builddate_string)
#define FAT_GetBuildTimeString() (fatinterface._buildtime_string)
#define FAT_InitSprite(ptr)      memset(ptr,0,sizeof(FATSPRITE))
#define FAT_SetSkipWords         (fatinterface._setskipwords)
#define FAT_SetHUD               (fatinterface._sethud)
#define FAT_SetUpperHUD          (fatinterface._setupperhud)
#define FAT_SetLowerHUD          (fatinterface._setlowerhud)
#define FAT_SetPreHUDCallback    (fatinterface._set_prehud_callback)
#define FAT_GetArcTanYX          (fatinterface._get_arctan_yx)
#define FAT_Tan512               (fatinterface._get_tan512)
#define FAT_GetHandleOfFile      (fatinterface._gethandleoffile)
#define FAT_LockHandleOfFile     HLock
#define FAT_UnlockHandleOfFile   HeapUnlock
#define FAT_GetNumberOfTextures  (fatinterface._getnumberoftextures)
#define FAT_LoadTextures         (fatinterface._loadtextures)
#define FAT_GetNumberOfGenericData (fatinterface._getnumberofgenericdata)
#define FAT_GetGenericData       (fatinterface._getgenericdata)
#define FAT_GetGenericDataLength (fatinterface._getgenericdatalength)
#define FAT_DONTCHECKLENGTH      65535
#define FAT_NOLENGTH             65535
#define FAT_FastSqrt             (fatinterface._fastsqrt)
#define FAT_GetPadState          (fatinterface._getpadstate)
#define FAT_AllKeysReleased()    ({while (_rowread(0) & 0xff);})
#define FAT_WaitKeyPressed()     ({while (!(_rowread(0) & 0xff));})
#define FAT_ClampAngle(a)        ({short t=(a);while(t<ANGLE_000) t+=ANGLE_360;while(t>=ANGLE_360) t-=ANGLE_360;t;})
#define FAT_CopyTEXCONFIG(d,s)   ({unsigned long* pd = (unsigned long*)(d);\
                                   unsigned long* ps = (unsigned long*)(s);\
                                   *pd++=*ps++;*pd++=*ps++;*pd++=*ps++;\
                                   *pd++=*ps++;*pd++=*ps++;*pd++=*ps++;\
                                   *pd++=*ps++;*pd++=*ps++;*pd++=*ps++;\
                                   *pd++=*ps++;*pd++=*ps++;*pd++=*ps++;\
                                   *pd++=*ps++;*pd++=*ps++;})
#define FAT_DebugConsole         (fatinterface._debugconsole)

#if defined(FAT_USEDEBUG)
#define FAT_DebugUseSlot         (fatinterface._debuguseslot)
#define FAT_DebugFreeSlot        (fatinterface._debugfreeslot)
#else
#define FAT_DebugUseSlot(a,b,c,d)
#define FAT_DebugFreeSlot(a)
#endif

#define FAT_AddDoor              (fatinterface._adddoor)
#define FAT_GetDoor              (fatinterface._getdoor)
#define FAT_GetDoorsArray        (fatinterface._getdoorsarray)
#define FAT_GetNrDoors           (fatinterface._getnrdoors)
#define FAT_RemoveAllDoors       (fatinterface._removealldoors)

#define FAT_UpdateAnimation(fa)  ({unsigned char tmpidx = (++(fa)->anim_idx) % (fa)->anim_steps;\
                                  FAT_CopyTEXCONFIG((fa)->dest,&((fa)->sources[tmpidx]));(fa)->anim_idx=tmpidx;})

#define FAT_DisplayLogoParams    (fatinterface._displaylogo)
#define FAT_DisplayLogo(delay)   FAT_DisplayLogoParams(GetPlane(0),GetPlane(1),&GetGraySwitchCount(),delay)

// returns tiny FAT logo (32x16 pixels in grayscales)
#define FAT_GetTinyLogo()        (fatinterface._tiny_logo)

#endif
#endif

//#############################################################################
// Revision History
//#############################################################################
//
// $Log: fat.h,v $
// Revision 1.33  2002/05/22 09:28:48  tnussb
// version number in header fixed
//
// Revision 1.32  2002/05/22 09:27:53  tnussb
// version raised to reflect change in unpack function (stepped back to old version)
//
// Revision 1.31  2002/05/08 15:39:05  tnussb
// FAT_GetTinyLogo() added
//
// Revision 1.30  2002/05/08 11:56:45  tnussb
// (1) simple warning mechanism if FAT_LoadEngine call is missing before other
//     FAT function is called integrated
// (2) FAT_WaitKeyPressed() added
// (3) FAT_DisplayLogo added
// (4) version raised to v1.10 finally
//
// Revision 1.29  2002/05/06 09:16:06  tnussb
// defines for UNPACK function return codes (FAT_UNPACK_xxxx) added
//
// Revision 1.28  2002/05/03 11:35:18  tnussb
// preliminary structure TEXANIMATION and macro FAT_UpdateAnimation() added
//
// Revision 1.27  2002/04/30 17:46:31  tnussb
// (1) FATDOOR.orientation renamed to FATDOOR.type
// (2) FATDOOR.type and FATDOOR.state are now unsigned
//
// Revision 1.26  2002/04/29 10:06:04  tnussb
// changes due to new doors support
//
// Revision 1.25  2002/04/25 19:49:42  tnussb
// console functions and macros added
//
// Revision 1.24  2002/04/24 18:46:35  tnussb
// misstyping in macro FAT_ClampAngle() fixed
//
// Revision 1.23  2002/04/24 17:38:42  tnussb
// (1) FAT_GetPadState() added
// (2) KEYPAD_xxx macros added
// (3) FAT_ClampAngle() added
//
// Revision 1.22  2002/04/22 07:26:26  tnussb
// FAT_Cos16384(): redefined to its previous form
//
// Revision 1.21  2002/04/19 15:20:48  tnussb
// (1) FAT_GetGenericDataLength() added
// (2) define FAT_NOLENGTH added
//
// Revision 1.20  2002/04/19 14:14:01  tnussb
// FAT_DONTCHECKLENGTH added (used in combination with GetGenericData())
//
// Revision 1.19  2002/04/18 20:30:47  tnussb
// (1) file access and standard texture format functions added
// (2) function FAT_FastSqrt() added
//
// Revision 1.18  2002/04/17 16:42:12  tnussb
// (1) cosinus table removed from export list
// (2) sinus table renamed, because it is truncated to 90 degrees
// (3) function FAT_Sin16384() added to export list
//
// Revision 1.17  2002/04/17 10:17:34  tnussb
// (1) macros FAT_Sin16384/FAT_Cos16384 added
// (2) FAT_Get512TanTab() added
// (3) distance field in FATSPRITE structure renamed (shouldn't be used
// by a client program)
//
// Revision 1.16  2002/04/15 09:58:11  tnussb
// (1) new function FAT_GetArcTanYX added
// (2) field angle added to FATSPRITE structure
// (3) defines STRIP_NORMAL, STRIP_MIRROR and STRIP_IGNORE added
//
// Revision 1.15  2002/04/08 20:21:51  tnussb
// (1) using now signed char instead of unsigned char for map
// (2) distance added to FATSPRITE structure (using one of the reserved fields)
//
// Revision 1.14  2002/03/29 16:04:25  tnussb
// version number raised
//
// Revision 1.13  2002/03/29 09:11:27  tnussb
// FAT_SetUpperHUD()/FAT_SetLowerHUD() added
//
// Revision 1.12  2002/03/28 12:23:16  tnussb
// FAT_SetPreHUDCallback() added
//
// Revision 1.11  2002/03/28 10:25:27  tnussb
// FAT_SetHUD() function added
//
// Revision 1.10  2002/03/25 10:07:41  tnussb
// version number raised to 0.92
//
// Revision 1.9  2002/03/12 14:40:03  tnussb
// (1) version raised to 0.91
// (2) field drawmode added to FATSPRITE
// (3) SPRITEMODE_xxxxx defines added
// (4) FAT_InitSprite() macro added
//
// Revision 1.8  2002/03/11 09:23:07  tnussb
// engine version changed to 0.90 for release
//
// Revision 1.7  2002/03/08 14:18:50  tnussb
// (1) multidirectional sprite support added by Scott Noveck
// (2) changes to Scott's first draft (now using a pointer to a list and
//     entry nr_sprites)
// (3) pointer clientdata added to sprite structure which can be used freely
//     by the client program
//
// Revision 1.6  2002/03/07 12:58:34  tnussb
// macros FAT_UnpackSize() and FAT_ValidEXEPACK() added
//
// Revision 1.5  2002/03/06 12:51:48  tnussb
// minor spelling typo fixed
//
// Revision 1.4  2002/03/06 12:49:38  tnussb
// (1) "export through fatinterface" of internal FAT-Engine tables added
// (2) "export through fatinterface" of some version and build date/time strings added
// (3) "export through fatinterface" of Exepack-decompression function
// (4) NO_EXIT_SUPPORT turned on (Programs which uses the FAT-Engine are NOT
//     allowed to use exit()!)
// (5) NOTE: programs which are compiled for an older version of the engine
//     will still run with the new engine. There is no compile necessary, only
//     if you want to make use of the new exported "functions".
//
// Revision 1.3  2002/03/01 11:04:44  tnussb
// EX_patch call fixed for upcoming new AMS 2.06
//
// Revision 1.2  2001/03/11 19:20:15  Thomas Nussbaumer
// changes for SDK 0.63
//
// Revision 1.1  2001/03/04 20:13:54  Thomas Nussbaumer
// initial version
//
