/******************************************************************************
*
* project name:  FAT-Engine
* file name:     fat.c
* initial date:  25/02/2001
* author:        thomas.nussbaumer@gmx.net
* description:   FAT engine runtime
*
* NOTE: the FAT engine Runtime comes in the form of a NOSTUB Library to
*       provide programs which are based on it with the complete 64kB
*       executable size for their own.
*       This file is wrapped into an OTH variable with extension "dll" to make
*       sure that it is not started from the commandline directly.
*       Actually it is not compressed, but used AS-IS.
*
* STEPS TO BUILD THE NOSTUB LIBRARY:
* ----------------------------------
*
* (1) compile library with:
*     tigcc -O3 fat.c
*
* (2) strip pc-variable-header to get pure executable:
*     ttstrip fat.89z fat.bin
*
* (3) wrap pure executable in OTH variable with extension "dll":
*     ttbin2oth -89 dll fat.bin ttslib
*
* NOTE: for the TI-92p version use .9xz in step 2 and -92 in step 3
*
* $Id: fat.c,v 1.27 2002/05/08 15:38:00 tnussb Exp $
*
******************************************************************************/

//#define  FAT_WITHCONSOLE   // used to build engine version with console
                             // don't uncomment it here, but specify
                             // -DFAT_WITHCONSOLE at the commandline!

#define  FATENGINE_ITSELF

#define USE_TI89
// TI-92+ and V200 disabled: the engine DLL has no startup code, so
// __calculator is uninitialized and runtime detection fails.
// #define USE_TI92P
// #define USE_V200

#include "../includes/fat.h"

#define INTERNAL_REFERENCED  static
#define EXTERNAL_REFERENCED  volatile


//-----------------------------------------------------------------------------
// pre-declaration necessary, because we want to have the jumptable at the
// beginning
//-----------------------------------------------------------------------------
extern EXTERNAL_REFERENCED short          tab_fisheye[96];
extern EXTERNAL_REFERENCED short          tab_xstep[144];
extern EXTERNAL_REFERENCED short          tab_ystep[144];
extern EXTERNAL_REFERENCED short          tab_div_sin[144];
extern EXTERNAL_REFERENCED short          tab_tan[144];
extern EXTERNAL_REFERENCED short          tab_div_tan[144];
extern EXTERNAL_REFERENCED short          tab_sincos16384[145];
extern EXTERNAL_REFERENCED unsigned short tab_tan512[144];

short         InitEngine(void);
void          CleanupEngine(void);
void          Render(FATCONFIG*);
DEPTHDATA*    GetDepthBuffer(void);
short         GetClipHeight(void);
void          SetPredrawCallback(void(*)(FATCONFIG*,DEPTHDATA*));
void          SetPreHUDCallback(void(*)(FATCONFIG*,unsigned short*,unsigned short*));
short         UnpackBuffer(unsigned char *src, unsigned char *dest);
void          SetSkipWords(short nr_words_to_skip);
void          SetHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask);
void          SetUpperHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask);
void          SetLowerHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask);
short         GetArcTanYX(short y, short x);
short         GetSin16384(short angle);
HANDLE        GetHandleOfFile(const char* filename);
short         GetNumberOfTextures(unsigned char* ptr);
short         LoadTextures(TEXCONFIG* dest, unsigned char* src, short start_idx, short nr_textures);
short         GetNumberOfGenericData(unsigned char* ptr);
void*         GetGenericData(unsigned char* src, short idx, unsigned short length);
unsigned short GetGenericDataLength(unsigned char* src, short idx);
long          GetTan512(short angle);
unsigned long fastsqrt(unsigned long x);
PADSTATES     GetPadState(void);
void          DebugConsole(FATCONFIG* fc);
void          DebugUseSlot(short slotnr,const char* name, void* ptr,unsigned short type);
void          DebugFreeSlot(short slotnr);
short         AddDoor(short xtile,short ytile,unsigned char type,unsigned char state,short position,TEXCONFIG* doortexture,TEXCONFIG* sidetexture,void* clientdata);
inline FATDOOR* GetDoor(short xtile, short ytile);
FATDOOR*      GetDoorsArray(void);
short         GetNrDoors(void);
void          RemoveAllDoors(void);
short         DisplayLogo(unsigned char* plane0, unsigned char* plane1,volatile long* switchcount,short delay);

extern EXTERNAL_REFERENCED unsigned long tiny_logo[];


#define xstr(s) str(s)
#define str(s) #s

#if defined(PREFIX_ZERO)
EXTERNAL_REFERENCED char fatversionstring[]   = "FAT-Engine v" xstr(FAT_MAINVERSION) ".0" xstr(FAT_SUBVERSION);
EXTERNAL_REFERENCED char fatpoweredstring[]   = "powered by " "FAT-Engine v" xstr(FAT_MAINVERSION) ".0" xstr(FAT_SUBVERSION);
#else
EXTERNAL_REFERENCED char fatversionstring[]   = "FAT-Engine v" xstr(FAT_MAINVERSION) "." xstr(FAT_SUBVERSION);
EXTERNAL_REFERENCED char fatpoweredstring[]   = "powered by " "FAT-Engine v" xstr(FAT_MAINVERSION) "." xstr(FAT_SUBVERSION);
#endif
EXTERNAL_REFERENCED char fatcopyrightstring[] = "(c) 2001,2002 TiCT";
EXTERNAL_REFERENCED char fatbuilddatestring[] = __DATE__;
EXTERNAL_REFERENCED char fatbuildtimestring[] = __TIME__;

//-----------------------------------------------------------------------------
// the following FATINTERFACE instance can be seen as kind of index which
// is used by a client program to retrieve the function pointers
// (similar to a jumptable)
//-----------------------------------------------------------------------------
EXTERNAL_REFERENCED FATINTERFACE fatinterface = {
     0L,
     FAT_MAGIC,
     FAT_MAINVERSION,
     FAT_SUBVERSION,
     FAT_NRENTRIES,
     GetSin16384,
     tab_sincos16384,
     InitEngine,
     CleanupEngine,
     Render,
     GetDepthBuffer,
     GetClipHeight,
     SetPredrawCallback,
     tab_fisheye,
     tab_xstep,
     tab_ystep,
     tab_div_sin,
     tab_tan,
     tab_div_tan,
     UnpackBuffer,
     (char*)fatversionstring,
     (char*)fatpoweredstring,
     (char*)fatcopyrightstring,
     (char*)fatbuilddatestring,
     (char*)fatbuildtimestring,
     SetSkipWords,
     SetHUD,
     SetPreHUDCallback,
     SetUpperHUD,
     SetLowerHUD,
     GetArcTanYX,
     tab_tan512,
     GetTan512,
     GetHandleOfFile,
     GetNumberOfTextures,
     LoadTextures,
     GetNumberOfGenericData,
     GetGenericData,
     fastsqrt,
     GetGenericDataLength,
     GetPadState,
     DebugConsole,
     DebugUseSlot,
     DebugFreeSlot,
     AddDoor,
     GetDoor,
     GetDoorsArray,
     GetNrDoors,
     RemoveAllDoors,
     DisplayLogo,
     (unsigned long*)tiny_logo
};


#include "tables.c"    // trigonometrical lookup tables
#include "fastsqrt.c"  // fast inter square root function
#include "unpack.c"    // exepack decompression functionality
#include "load.c"      // standard texture format loading
#include "input.c"     // keyboard reading stuff
#include "console.c"   // console related stuff
#include "logo.c"      // FAT-Engine's logo screen

DEPTHDATA*      depthinfo      = NULL;
short           nr_skipwords   = 9;
short           nr_doors       = 0;
FATDOOR*        doors          = NULL;
FATDOOR*        last_door      = NULL;
unsigned short* hudplane0_high = NULL;
unsigned short* hudplane0_low  = NULL;
unsigned short* hudplane1_high = NULL;
unsigned short* hudplane1_low  = NULL;
unsigned short* hudmask_high   = NULL;
unsigned short* hudmask_low    = NULL;
void(*predraw_callback)(FATCONFIG*,DEPTHDATA*) = NULL;
void(*prehud_callback)(FATCONFIG*,unsigned short*,unsigned short*) = NULL;
short*          tab_col_scale  = NULL;  // precomputed SCALE_VALUE*256/fisheye per column

#include "scale_it.c"


/******************************************************************************
* This function may be used to set the graphics of a HUD (Headup Display) which
* is drawn above the rendered view
******************************************************************************/
void SetHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask) {
    hudplane0_high = plane0;
    hudplane0_low  = (plane0) ? plane0 + 3*96 : NULL;
    hudplane1_high = plane1;
    hudplane1_low  = (plane1) ? plane1 + 3*96 : NULL;
    hudmask_high   = mask;
    hudmask_low    = (mask) ? mask + 3*96 : NULL;
}


/******************************************************************************
* This function may be used to set the graphics of the upper part of a HUD
* (Headup Display) which is drawn above the rendered view
******************************************************************************/
void SetUpperHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask) {
    hudplane0_high = plane0;
    hudplane1_high = plane1;
    hudmask_high   = mask;
}


/******************************************************************************
* This function may be used to set the graphics of the upper part of a HUD
* (Headup Display) which is drawn above the rendered view
******************************************************************************/
void SetLowerHUD(unsigned short* plane0,unsigned short* plane1,unsigned short* mask) {
    hudplane0_low = plane0;
    hudplane1_low = plane1;
    hudmask_low   = mask;
}


/******************************************************************************
* This function may be used to modify the width of the destination buffer.
* After 6 words (96 pixels) are drawn the given number of words are skipped
* (default = 9). For example: if you want the FAT-Engine to render to a
* 96 pixels wide buffer just use 0 as parameter to this function.
******************************************************************************/
void SetSkipWords(short nr_words_to_skip) {
    nr_skipwords = nr_words_to_skip;
}


/******************************************************************************
* This function may be used to set a callback function which is called
* after the depth buffer is filled and before the strip drawing is executed.
* The callback function can be used to modify the content of the DEPTHDATA
* structure (for example: for lighting effects).
******************************************************************************/
void SetPredrawCallback(void(*cb)(FATCONFIG*,DEPTHDATA*)) {
    predraw_callback = cb;
}


/******************************************************************************
* This function may be used to set a callback function which is called
* BEFORE the rendered view is written to the destination buffers.
******************************************************************************/
void SetPreHUDCallback(void(*cb)(FATCONFIG*,unsigned short*,unsigned short*)) {
    prehud_callback = cb;
}


/******************************************************************************
* this function returns the depth buffer to the caller.
* the informations from the depth buffer maybe useful if a postprocess should
******************************************************************************/
DEPTHDATA* GetDepthBuffer(void) {
    return depthinfo;
}


/******************************************************************************
* this function returns the maximum possible height within the DEPTHDATA.
* larger strips get clipped to this value.
******************************************************************************/
short GetClipHeight(void) {
    return CLIP_HEIGHT;
}

/******************************************************************************
* this function tells the engine to create a door
* it returns 1 if door is added successfully
******************************************************************************/
short AddDoor(short xtile, short ytile, unsigned char type, unsigned char state,
              short position, TEXCONFIG* doortexture, TEXCONFIG* sidetexture,
              void* clientdata)
{
    short i;

    if (nr_doors==(MAX_NR_DOORS-1)) return 0;

    // make sure we keep doors sorted from lowest coords to highest
    for (i=0; i<nr_doors; i++) {
        if (ytile<(doors[i].ytile) || (ytile==(doors[i].ytile) && xtile<(doors[i].xtile))) {
            memmove(&doors[i+1], &doors[i], sizeof(FATDOOR)*(nr_doors-i));
            break;
        }
    }

    nr_doors++;
    doors[i].xtile       = xtile;
    doors[i].ytile       = ytile;
    doors[i].type        = type;
    doors[i].doortexture = doortexture;
    doors[i].sidetexture = sidetexture;
    doors[i].position    = position;
    doors[i].state       = state;
    doors[i].clientdata  = clientdata;
    return 1;
}


/******************************************************************************
* use a binary search to find a door's index based on coords
******************************************************************************/

// runtime issues: the usage of GetDoor() will hit the performs with a
// 3.8% slowdown compared to the approach of storing a door index in the map.
// Storing the door index in the map will cut down the number of textures which
// can be used by walls to 64 which is too much limiting IMO.
inline FATDOOR* GetDoor(short xtile, short ytile) {
    unsigned short low, high, mid;

    // VERY DIRTY TRICK! We suppose that last door is always set. It will be
    // be set to &door[0] initially and if there are no doors added yet
    // InitEngine will set the xtile of door[0] to -1 so it will not be returned

    // By using this dirty trick we have not to compare last_door against NULL
    // which gives us a 0.2% speed increase in the initial position of demo 10
    // where we face directly a door. In more complicated scenes the speed increase
    // can be much more ...

    if (last_door->xtile == xtile && last_door->ytile == ytile) return last_door;
    low  = 0;
    high = nr_doors-1;

    while (low <= high) {
        mid = (low+high)>>1;
        if (doors[mid].ytile==ytile) {
            if (doors[mid].xtile==xtile) {
                last_door = &doors[mid];
                return last_door;
            }

            if (doors[mid].xtile>xtile) high = mid-1;
            else                        low  = mid+1;
        }
        else if (doors[mid].ytile>ytile) high = mid-1;
        else                             low  = mid+1;
    }

    return NULL;
}


/******************************************************************************
* returns doors array
******************************************************************************/
FATDOOR* GetDoorsArray(void) {
    return doors;
}


/******************************************************************************
* returns number of doors
******************************************************************************/
short GetNrDoors(void) {
    return nr_doors;
}


/******************************************************************************
* returns number of doors
******************************************************************************/
void RemoveAllDoors(void) {
    nr_doors       = 0;
    last_door      = &doors[0]; // last GetDoor() result ...
    doors[0].xtile = -1;        // set xtile to -1 so GetDoor() will not return it as last result
}


/******************************************************************************
* this function returns the arctangent of y/x, which can be used to find
* the angle between two objects (Scott Noveck)
******************************************************************************/
short GetArcTanYX(short y, short x) {
    short angle = ANGLE_090;

    if (y==0)  return (x<0 ? ANGLE_180 : ANGLE_000);

    if (x!=0) {
        long tangent = (long)((512*(long)y)/x);
        unsigned short low, high, mid, diff=65535, newdiff;
        short sign = 1;

        if (tangent < 0) {
            sign = -1;
            tangent = abs(tangent);
        }

        // now we perform a binary search to find index of closest value
        low = 0;
        high = ANGLE_090-1;
        while (low <= high) {
            mid = (low+high)/2;
            newdiff = abs(tangent-(long)tab_tan512[mid]);
            if (newdiff < diff) {
                angle = mid;
                diff = newdiff;
                if (diff <= 2)  break;
            }

            if ((long)tab_tan512[mid] < tangent) low  = mid+1;
            else                                 high = mid-1;
        }

        if (sign==-1)  angle = ANGLE_180-angle;
    }

    if (y<0)  angle += ANGLE_180;
    if (angle >= ANGLE_360)  angle -= ANGLE_360;
    return angle;
}


/******************************************************************************
* this function returns the sin(angle) * 16384
******************************************************************************/
short GetSin16384(short angle) {
    short sign = 1;

    while (angle < ANGLE_000)  angle += ANGLE_360;
    while (angle >= ANGLE_360) angle -= ANGLE_360;

    if (angle > ANGLE_180) {
        sign = -1;
        angle -= ANGLE_180;
    }

    if (angle > ANGLE_090)  angle = ANGLE_180-angle;

    if (sign == -1) return -tab_sincos16384[angle];
    else            return tab_sincos16384[angle];
}


/******************************************************************************
* this function returns tan(angle)*512
*
* NOTE: it returns a long because -/+ infinity is encoded as -/+ 65535
******************************************************************************/
long GetTan512(short angle) {
    short sign = 1, abstan;

    while (angle < ANGLE_000)  angle += ANGLE_360;
    while (angle >= ANGLE_360) angle -= ANGLE_360;

    if (angle >= ANGLE_180)  angle -= ANGLE_180;
    if (angle > ANGLE_090) {
        sign = -1;
        angle = ANGLE_180-angle;
    }

    if (angle == ANGLE_090)  abstan = 65535;    // actually equals infinity, so we'll return the largest value we can
    else                    abstan = tab_tan512[angle];

    if (sign==-1) return -(long)abstan;
    else          return (long)abstan;
}





/******************************************************************************
* the raycasting routine
*
* the routine may look like complicated, but this are just optimizations ....
******************************************************************************/
void Render(FATCONFIG* fc) {
    short      orientation = fc->cam_orientation;
    short      xpos        = fc->cam_xpos;
    short      ypos        = fc->cam_ypos;
    short      map_h       = fc->map_height;
    short      map_w       = fc->map_width;
    char*      map         = fc->map_data;
    short      maxwidth    = map_w << 6;
    short      maxheight   = map_h << 6;
    short      xpos_grid   = xpos & 0xffc0;
    short      ypos_grid   = ypos & 0xffc0;
    TEXCONFIG* textures    = fc->textures;
    short      act_strip   = 0;
    short      angle       = orientation - ANGLE_030;
    short      column;
    short      use_cos;
    short      divsin_val;
    short      divcos_val;

    //-------------------------------------------------------------------------
    // variables for intersections with horizontal lines
    //-------------------------------------------------------------------------
    short      horizontal_x;
    short      horizontal_y;
    short      horizontal_step_x;
    short      horizontal_step_y;
    short      horizontal_hit_dist;
    char       horizontal_map_content = 0; // to make the compiler happy ...
    FATDOOR*   horizontal_door;
    TEXCONFIG* horizontal_texture = NULL;  // to make the compiler happy ...

    //-------------------------------------------------------------------------
    // variables for intersections with vertical lines
    //-------------------------------------------------------------------------
    short      vertical_x;
    short      vertical_y;
    short      vertical_step_x;
    short      vertical_step_y;
    short      vertical_hit_dist;
    char       vertical_map_content = 0; // to make the compiler happy ...
    FATDOOR*   vertical_door;
    TEXCONFIG* vertical_texture = NULL;  // to make the compiler happy ...

    long       first_hit;

    unsigned long* lightdata = depthinfo->lightdata;
    unsigned long* darkdata  = depthinfo->darkdata;

    char     tmp_content;
    char*    tile_row;

    short     texidx;
    short     offset;
    TEXSTRIP* used_ts;

    // clamp angle once before the loop; inside we just increment and wrap
    if (angle < ANGLE_000)  angle += ANGLE_360;

    //=========================================================================
    // loop from the left to the right of the screen
    // (field of view == 60 degrees)
    //=========================================================================
    for (column = 0; column < 96; column++)  {
        horizontal_door = NULL;
        vertical_door   = NULL;

        //=====================================================================
        // angle 0 to 89 degrees - parameter setup ...
        //=====================================================================
        if (angle < ANGLE_090) {
            //-----------------------------------------------------------------
            // setup parameters for intersections with horizontal lines
            //-----------------------------------------------------------------
            horizontal_y = ypos_grid + 64;
            first_hit    = (long)(short)tab_div_tan[angle] * (short)(horizontal_y - ypos); // 256/tan(angle)
            first_hit   >>= 8L;
            first_hit   += (long)xpos;
            horizontal_x = (short)first_hit;
            horizontal_step_x = tab_xstep[angle];  // 64/tan(angle)
            horizontal_step_y = 64;

            //-----------------------------------------------------------------
            // setup parameters for intersections with vertical lines
            //-----------------------------------------------------------------
            vertical_x  = xpos_grid + 64;
            first_hit   = (long)(short)tab_tan[angle] * (short)(vertical_x - xpos); // 256*tan(angle)
            first_hit   >>= 8L;
            first_hit  += (long)ypos;
            vertical_y =  (short)first_hit;
            vertical_step_x = 64;
            vertical_step_y = tab_ystep[angle];  // 64*tan(angle)

            //-----------------------------------------------------------------
            // use cos() for distance calculations in the first 45 degrees
            // otherwise use sin()
            //-----------------------------------------------------------------
            if (angle < ANGLE_045)   use_cos = 1;
            else                     use_cos = 0;

            //-----------------------------------------------------------------
            // setup cos() and sin() values
            //-----------------------------------------------------------------
            divsin_val = tab_div_sin[angle];
            divcos_val = tab_div_sin[ANGLE_090-1-angle];
        }

        //=====================================================================
        // angle 90 to 179 degrees - parameter setup ...
        //=====================================================================
        else if (angle < ANGLE_180) {
            //-----------------------------------------------------------------
            // setup parameters for intersections with horizontal lines
            //-----------------------------------------------------------------
            horizontal_y = ypos_grid + 64;
            first_hit    = -((long)(short)tab_div_tan[ANGLE_090-1-(angle-ANGLE_090)] * (short)(horizontal_y-ypos)); // 256/tan(angle)
            first_hit  >>= 8L;
            first_hit   += (long)xpos;
            horizontal_x = (short)first_hit;
            horizontal_step_x = -tab_xstep[ANGLE_090-1-(angle-ANGLE_090)];  // 64/tan(angle)
            horizontal_step_y = 64;

            //-----------------------------------------------------------------
            // setup parameters for intersections with vertical lines
            //-----------------------------------------------------------------
            vertical_x  =  xpos_grid - 1;
            first_hit   = -((long)(short)tab_tan[ANGLE_090-1-(angle-ANGLE_090)] * (short)(vertical_x - xpos)); // 256*tan(angle)
            first_hit >>=  8L;
            first_hit  +=  ypos;
            vertical_y =   (short)first_hit;
            vertical_step_x = -64;
            vertical_step_y = tab_ystep[ANGLE_090-1-(angle-ANGLE_090)];  // 64*tan(angle)

            //-----------------------------------------------------------------
            // use cos() for distance calculations in the first 45 degrees
            // otherwise use sin()
            //-----------------------------------------------------------------
            if (angle < ANGLE_045 + ANGLE_090) use_cos = 0;
            else                               use_cos = 1;

            //-----------------------------------------------------------------
            // setup cos() and sin() values
            //-----------------------------------------------------------------
            divsin_val =  tab_div_sin[ANGLE_090-1-(angle-ANGLE_090)];
            divcos_val = -tab_div_sin[angle-ANGLE_090];
        }

        //=====================================================================
        // angle 180 to 269 degrees - parameter setup ...
        //=====================================================================
        else if (angle < ANGLE_270) {
            //-----------------------------------------------------------------
            // setup parameters for intersections with horizontal lines
            //-----------------------------------------------------------------
            horizontal_y = ypos_grid - 1;
            first_hit    = (long)(short)tab_div_tan[angle - ANGLE_180] * (short)(horizontal_y-ypos); // 256/tan(angle)
            first_hit  >>= 8L;
            first_hit   += (long)xpos;
            horizontal_x = (short)first_hit;
            horizontal_step_x = -tab_xstep[angle - ANGLE_180];  // 64/tan(angle)
            horizontal_step_y = -64;

            //-----------------------------------------------------------------
            // setup parameters for intersections with vertical lines
            //-----------------------------------------------------------------
            vertical_x = xpos_grid - 1;
            first_hit  = (long)(short)tab_tan[angle - ANGLE_180] * (short)(vertical_x-xpos); // 256*tan(angle)
            first_hit >>= 8L;
            first_hit += (long)ypos;
            vertical_y = (short)first_hit;
            vertical_step_x = -64;
            vertical_step_y = -tab_ystep[angle - ANGLE_180];  // 64*tan(angle)

            //-----------------------------------------------------------------
            // use cos() for distance calculations in the first 45 degrees
            // otherwise use sin()
            //-----------------------------------------------------------------
            if (angle < ANGLE_045 + ANGLE_180) use_cos = 1;
            else                               use_cos = 0;

            //-----------------------------------------------------------------
            // setup cos() and sin() values
            //-----------------------------------------------------------------
            divsin_val = -tab_div_sin[angle - ANGLE_180];
            divcos_val = -tab_div_sin[ANGLE_090-1-(angle - ANGLE_180)];
        }

        //=====================================================================
        // angle 270 to 359 degrees - parameter setup ...
        //=====================================================================
        else  {
            //-----------------------------------------------------------------
            // setup parameters for intersections with horizontal lines
            //-----------------------------------------------------------------
            horizontal_y  =  ypos_grid - 1;
            first_hit     = -((long)(short)tab_div_tan[ANGLE_090-1-(angle-ANGLE_270)] * (short)(horizontal_y-ypos)); // 256/tan(angle)
            first_hit    >>= 8L;
            first_hit    +=  (long)xpos;
            horizontal_x =   (short)first_hit;
            horizontal_step_x = tab_xstep[ANGLE_090-1-(angle-ANGLE_270)];  // 64/tan(angle)
            horizontal_step_y = -64;

            //-----------------------------------------------------------------
            // setup parameters for intersections with vertical lines
            //-----------------------------------------------------------------
            vertical_x =  xpos_grid + 64;
            first_hit  = -((long)(short)tab_tan[ANGLE_090-1-(angle-ANGLE_270)] * (short)(vertical_x-xpos)); // 256*tan(angle)
            first_hit >>= 8L;
            first_hit +=  (long)ypos;
            vertical_y =  (short)first_hit;
            vertical_step_x = 64;
            vertical_step_y = -tab_ystep[ANGLE_090-1-(angle-ANGLE_270)];  // 64*tan(angle)

            //-----------------------------------------------------------------
            // use cos() for distance calculations in the first 45 degrees
            // otherwise use sin()
            //-----------------------------------------------------------------
            if (angle < ANGLE_045 + ANGLE_270) use_cos = 0;
            else                               use_cos = 1;

            //-----------------------------------------------------------------
            // setup cos() and sin() values
            //-----------------------------------------------------------------
            divsin_val = -tab_div_sin[ANGLE_090-1-(angle-ANGLE_270)];
            divcos_val =  tab_div_sin[angle-ANGLE_270];
        }

        horizontal_hit_dist = MAX_DISTANCE;
        vertical_hit_dist   = MAX_DISTANCE;

        //=====================================================================
        // find intersection with horizontal lines
        //=====================================================================
        if (angle == ANGLE_000 || angle == ANGLE_180) {
            horizontal_hit_dist = MAX_DISTANCE;
        }
        else {
            short h_tile_step = (horizontal_step_y > 0) ? map_w : -map_w;
            tile_row = map + (horizontal_y >> 6) * map_w;
            {
                short h_hit;
                void* _h_sa;
                unsigned short h_maxw = (unsigned short)maxwidth;
                unsigned short h_maxh = (unsigned short)maxheight;
                do {
                    asm volatile (
                        "1:\n"
                        "cmp.w %[maxw],%[hx]\n"
                        "bcc.s 2f\n"
                        "cmp.w %[maxh],%[hy]\n"
                        "bcc.s 2f\n"
                        "move.w %[hx],%[out]\n"
                        "asr.w #6,%[out]\n"
                        "movea.w %[out],%[sa]\n"
                        "move.b (%[trow],%[sa].l),%[out]\n"
                        "bgt.s 3f\n"
                        "add.w %[sx],%[hx]\n"
                        "add.w %[sy],%[hy]\n"
                        "adda.w %[ts],%[trow]\n"
                        "bra.s 1b\n"
                        "2:\n"
                        "moveq #0,%[out]\n"
                        "bra.s 4f\n"
                        "3:\n"
                        "ext.w %[out]\n"
                        "4:\n"
                        : [hx] "+d"(horizontal_x), [hy] "+d"(horizontal_y),
                          [trow] "+a"(tile_row), [out] "=&d"(h_hit),
                          [sa] "=&a"(_h_sa)
                        : [maxw] "d"(h_maxw), [maxh] "d"(h_maxh),
                          [sx] "d"(horizontal_step_x), [sy] "d"(horizontal_step_y),
                          [ts] "d"(h_tile_step)
                        : "cc"
                    );

                    if (h_hit <= 0) {
                        horizontal_hit_dist = MAX_DISTANCE;
                        break;
                    }

                    horizontal_map_content = h_hit;
                    {
                        short tile_x = horizontal_x >> 6;

                        if (horizontal_map_content == CLOSED_DOOR_TILE) {
                            short tile_y = horizontal_y >> 6;
                            short half_step_x;
                            short new_horizontal_x;

                            if (!(horizontal_door = GetDoor(tile_x, tile_y))) {
                                horizontal_x += horizontal_step_x;
                                horizontal_y += horizontal_step_y;
                                tile_row += h_tile_step;
                                continue;
                            }

                            half_step_x      = horizontal_step_x>>1;
                            new_horizontal_x = horizontal_x+half_step_x;
                            if ((new_horizontal_x&0xffc0)==(horizontal_x&0xffc0)) {
                                if ((signed short)((new_horizontal_x)&~0xffc0)>=horizontal_door->position) {
                                    horizontal_x = new_horizontal_x;
                                    horizontal_y += horizontal_step_y>>1;
                                    if (use_cos) horizontal_hit_dist = (short)((((long)(horizontal_x-xpos)) * (long)divcos_val) >> 7L);
                                    else         horizontal_hit_dist = (short)((((long)(horizontal_y-ypos)) * (long)divsin_val) >> 7L);
                                    if (horizontal_hit_dist<0) horizontal_hit_dist = -horizontal_hit_dist;
                                    break;
                                }
                            }
                            horizontal_door = NULL;
                            horizontal_x += horizontal_step_x;
                            horizontal_y += horizontal_step_y;
                            tile_row += h_tile_step;
                            continue;
                        }
                        else {
                            char* prev_row = tile_row - h_tile_step;
                            horizontal_texture = textures+horizontal_map_content-1;
                            tmp_content        = prev_row[tile_x];
                            if (tmp_content == CLOSED_DOOR_TILE || tmp_content == OPEN_DOOR_TILE) {
                                short tile_y = (horizontal_y-horizontal_step_y)>>6;
                                if ((horizontal_door = GetDoor(tile_x, tile_y))) {
                                    if (horizontal_door->sidetexture) {
                                        horizontal_texture = horizontal_door->sidetexture;
                                    }
                                    horizontal_door = NULL;
                                }
                            }
                            if (use_cos) horizontal_hit_dist = (short)((((long)(horizontal_x-xpos)) * (long)divcos_val) >> 7L);
                            else         horizontal_hit_dist = (short)((((long)(horizontal_y-ypos)) * (long)divsin_val) >> 7L);
                            if (horizontal_hit_dist<0) horizontal_hit_dist = -horizontal_hit_dist;
                            break;
                        }
                    }
                } while (1);
            }
        }

        //=====================================================================
        // find intersection with vertical lines
        //=====================================================================
        if (angle == ANGLE_090 || angle == ANGLE_270) {
            vertical_hit_dist = MAX_DISTANCE;
        }
        else {
            short prev_v_tile_y = vertical_y >> 6;
            tile_row = map + prev_v_tile_y * map_w;
            {
                short v_hit;
                short _v_ty;
                void* _v_sa;
                unsigned short v_maxw = (unsigned short)maxwidth;
                unsigned short v_maxh = (unsigned short)maxheight;
                long _v_sx = vertical_step_x;
                long _v_sy = vertical_step_y;
                do {
                    asm volatile (
                        "1:\n"
                        "cmp.w %[maxw],%[vx]\n"
                        "bcc.s 2f\n"
                        "cmp.w %[maxh],%[vy]\n"
                        "bcc.s 2f\n"
                        "move.w %[vx],%[out]\n"
                        "asr.w #6,%[out]\n"
                        "move.w %[vy],%[ty]\n"
                        "asr.w #6,%[ty]\n"
                        "cmp.w %[pty],%[ty]\n"
                        "beq.s 5f\n"
                        "move.w %[ty],%[pty]\n"
                        "muls.w %[mw],%[ty]\n"
                        "movea.l %[mapbase],%[trow]\n"
                        "adda.l %[ty],%[trow]\n"
                        "5:\n"
                        "movea.w %[out],%[sa]\n"
                        "move.b (%[trow],%[sa].l),%[out]\n"
                        "bgt.s 3f\n"
                        "add.w %[sx],%[vx]\n"
                        "add.w %[sy],%[vy]\n"
                        "bra.s 1b\n"
                        "2:\n"
                        "moveq #0,%[out]\n"
                        "bra.s 4f\n"
                        "3:\n"
                        "ext.w %[out]\n"
                        "4:\n"
                        : [vx] "+d"(vertical_x), [vy] "+d"(vertical_y),
                          [trow] "+a"(tile_row), [out] "=&d"(v_hit),
                          [pty] "+d"(prev_v_tile_y), [ty] "=&d"(_v_ty),
                          [sa] "=&a"(_v_sa)
                        : [maxw] "d"(v_maxw), [maxh] "d"(v_maxh),
                          [mw] "d"(map_w),
                          [mapbase] "a"(map), [sx] "a"(_v_sx), [sy] "a"(_v_sy)
                        : "cc"
                    );

                    if (v_hit <= 0) {
                        vertical_hit_dist = MAX_DISTANCE;
                        break;
                    }

                    vertical_map_content = v_hit;
                    {
                        short tile_x_v = vertical_x >> 6;
                        short tile_y_v = vertical_y >> 6;

                        if (vertical_map_content == CLOSED_DOOR_TILE) {
                            short half_step_y;
                            short new_vertical_y;

                            if (!(vertical_door = GetDoor(tile_x_v, tile_y_v))) {
                                vertical_x += vertical_step_x;
                                vertical_y += vertical_step_y;
                                continue;
                            }

                            half_step_y    = vertical_step_y>>1;
                            new_vertical_y = vertical_y+half_step_y;
                            if ((new_vertical_y&0xffc0)==(vertical_y&0xffc0)) {
                                if ((signed short)(new_vertical_y&~0xffc0)>=vertical_door->position) {
                                    vertical_y =  new_vertical_y;
                                    vertical_x += vertical_step_x>>1;
                                    if (use_cos) vertical_hit_dist = (short)((((long)(vertical_x-xpos)) * (long)divcos_val) >> 7L);
                                    else         vertical_hit_dist = (short)((((long)(vertical_y-ypos)) * (long)divsin_val) >> 7L);
                                    if (vertical_hit_dist<0) vertical_hit_dist = -vertical_hit_dist;
                                    break;
                                }
                            }
                            vertical_door = NULL;
                            vertical_x += vertical_step_x;
                            vertical_y += vertical_step_y;
                            continue;
                        }
                        else {
                            tile_x_v         = (vertical_x-vertical_step_x)>>6;
                            vertical_texture = textures+vertical_map_content-1;
                            tmp_content      = tile_row[tile_x_v];

                            if (tmp_content == CLOSED_DOOR_TILE || tmp_content == OPEN_DOOR_TILE) {
                                if ((vertical_door = GetDoor(tile_x_v, tile_y_v))) {
                                    if (vertical_door->sidetexture) {
                                        vertical_texture = vertical_door->sidetexture;
                                    }
                                    vertical_door = NULL;
                                }
                            }
                            if (use_cos) vertical_hit_dist = (short)((((long)(vertical_x-xpos)) * (long)divcos_val) >> 7L);
                            else         vertical_hit_dist = (short)((((long)(vertical_y-ypos)) * (long)divsin_val) >> 7L);
                            if (vertical_hit_dist<0) vertical_hit_dist = -vertical_hit_dist;
                            break;
                        }
                    }
                } while (1);
            }
        }

        //=====================================================================
        // now check which intersection is nearer ...
        //=====================================================================
        if (horizontal_hit_dist <= vertical_hit_dist) {
            if (horizontal_hit_dist == MAX_DISTANCE) {
                depthinfo->height[act_strip] = 0;
                depthinfo->distance[act_strip++] = MAX_DISTANCE;
                lightdata += 2;
                darkdata  += 2;
            }
            else {
                short wallheight;
                if (!horizontal_hit_dist) wallheight=CLIP_HEIGHT;
                else wallheight = tab_col_scale[column] / horizontal_hit_dist;

                if (wallheight > CLIP_HEIGHT) wallheight = CLIP_HEIGHT;

                if (horizontal_door) {
                    texidx  = (horizontal_x & 0x3f) - horizontal_door->position;
                    offset  = (texidx & 15)<<2;
                    used_ts = horizontal_door->doortexture->strips+(texidx>>4);
                }
                else {
                    texidx = horizontal_x & 0x3f;
                    if (horizontal_step_y<0) texidx=0x3f-texidx; // fix: invert texture if necessary
                    offset  = (texidx & 15)<<2;
                    used_ts = horizontal_texture->strips+(texidx>>4);
                }

                if (used_ts->mirrored) offset = (0x0f<<2) - offset;

                depthinfo->height[act_strip]     = wallheight;
                depthinfo->distance[act_strip++] = horizontal_hit_dist;

                *lightdata++ = *(unsigned long*)(used_ts->lightdata + offset);
                *lightdata++ = *(unsigned long*)(used_ts->lightdata + offset + 2);
                *darkdata++  = *(unsigned long*)(used_ts->darkdata  + offset);
                *darkdata++  = *(unsigned long*)(used_ts->darkdata  + offset + 2);
            }
        }
        else {
            short wallheight;

            if (!vertical_hit_dist) wallheight=CLIP_HEIGHT;
            else wallheight = tab_col_scale[column] / vertical_hit_dist;

            if (wallheight > CLIP_HEIGHT) wallheight = CLIP_HEIGHT;

            if (vertical_door) {
                texidx  = (vertical_y & 0x3f) - vertical_door->position;
                offset  = (texidx & 15)<<2;
                used_ts = vertical_door->doortexture->strips+(texidx>>4);
            }
            else {
                texidx  = vertical_y & 0x3f;
                if (vertical_step_x>=0) texidx=0x3f-texidx; // fix: invert texture if necessary
                offset  = (texidx & 15)<<2;
                used_ts = vertical_texture->strips+(texidx>>4);
            }

            if (used_ts->mirrored) offset = (0x0f<<2) - offset;

            depthinfo->height[act_strip]     = wallheight;
            depthinfo->distance[act_strip++] = vertical_hit_dist;
            *lightdata++ = *(unsigned long*)(used_ts->lightdata + offset);
            *lightdata++ = *(unsigned long*)(used_ts->lightdata + offset+2);
            *darkdata++  = *(unsigned long*)(used_ts->darkdata + offset);
            *darkdata++  = *(unsigned long*)(used_ts->darkdata + offset+2);
        }

        // ... then start again
        angle++;
        if (angle == ANGLE_360) angle = ANGLE_000;
    }

    //-------------------------------------------------------------------------
    // call predraw callback function if one is set ...
    //-------------------------------------------------------------------------
    if (predraw_callback) predraw_callback(fc,depthinfo);

    RenderStrips(fc);
    fc->frame_counter++;

    ACTIVATE_CONSOLE_IF_WANTED(fc);
}


//=============================================================================
// InitEngine()
//=============================================================================
short InitEngine(void) {
    #define necessary_mem  (sizeof(DEPTHDATA)+96*12*sizeof(unsigned short)+96*2*sizeof(unsigned short)+96*2*sizeof(unsigned short)+96*sizeof(short)+SIZE_MEMCONSOLE+sizeof(FATDOOR)*MAX_NR_DOORS)
    //-------------------------------------------------------------------------
    // allocate memory for depthinfo and backbuffer
    //-------------------------------------------------------------------------
    if (!(depthinfo = (DEPTHDATA*)malloc(necessary_mem))) return 0;

    render_buf0         = (unsigned short*)(depthinfo+1);
    render_buf1         = render_buf0+96*6;
    sprite_dest_offsets = render_buf1+96*6;
    sprite_screen_masks = sprite_dest_offsets+96;
    tab_col_scale       = (short*)(sprite_screen_masks+96);
    doors               = (FATDOOR*)(tab_col_scale+96);
    memset(depthinfo,0,necessary_mem);

#if defined(FAT_WITHCONSOLE)
    // initialize debug console (generates only code if FAT_WITHCONSOLE is defined!)
    DebugInitConsole(((unsigned char*)depthinfo)+necessary_mem-SIZE_MEMCONSOLE);
#endif

    // make sure the predraw callback is not set !!
    predraw_callback = NULL;

    // make sure the prehud callback is not set !!
    prehud_callback = NULL;

    // make sure the number of doors is initialized to zero
    nr_doors       = 0;
    last_door      = &doors[0]; // last GetDoor() result ...
    doors[0].xtile = -1;   // set xtile to -1 so GetDoor() will not return it as last result

    // make sure the number of used skipped words is 9 which defaults to a
    //240 pixel wide destination buffer
    nr_skipwords = 9;

    // make sure we are not rendering a HUD
    SetHUD(NULL,NULL,NULL);

    // precompute sprite dest offsets and screen masks
    {
        short i;
        for (i = 0; i < 96; i++) {
            short strip = i >> 4;
            sprite_dest_offsets[i] = (strip << 6) + (strip << 5);
            sprite_screen_masks[i] = 0x8000 >> (i & 15);
            tab_col_scale[i] = (short)(SCALE_VALUE*256L / (long)tab_fisheye[i]);
        }
    }

    // initialize pointer for keypad reading function
    InitReadKeyFunction();
    return 1;
}


//=============================================================================
// frees allocated memory
//=============================================================================
void CleanupEngine(void) {
    if (depthinfo) free(depthinfo);
    depthinfo   = NULL;
    render_buf0 = NULL;
    render_buf1 = NULL;
}


//=============================================================================
// dummy main to make the compiler happy ...
// (will not be used at all!)
//=============================================================================
void _main(void) {}


//#############################################################################
// Revision History
//#############################################################################
//
// $Log: fat.c,v $
// Revision 1.27  2002/05/08 15:38:00  tnussb
// export of tiny logo added
//
// Revision 1.26  2002/05/08 11:54:42  tnussb
// function DisplayLogo (logo.c) integrated
//
// Revision 1.25  2002/05/03 11:39:34  tnussb
// prefix zero in subversion is now handled correctly
//
// Revision 1.24  2002/05/02 09:29:41  tnussb
// wall texture drawing inverted (was wrong previously)
//
// Revision 1.23  2002/04/30 17:44:39  tnussb
// (1) caching within GetDoor() added
// (2) minor speed improvements and code beautifying
//
// Revision 1.22  2002/04/29 10:03:59  tnussb
// (1) doors support added (Great work, Scott!)
// (2) wall textures get now displayed always correctly. Previously depending
// on the camera location the wall textures were displayed mirrored.
//
// Revision 1.21  2002/04/25 19:48:26  tnussb
// console integrated
//
// Revision 1.20  2002/04/24 17:35:53  tnussb
// (1) GetPadState() added to export list
// (2) InitReadKeyFunction() call added to initialization
//
// Revision 1.19  2002/04/22 07:25:16  tnussb
// Cos16384(): clips now input angle to be < ANGLE_360
//
// Revision 1.18  2002/04/19 15:22:35  tnussb
// GetGenericDataLength added to exports
//
// Revision 1.17  2002/04/18 20:28:47  tnussb
// GetNumberOfGenericData and GetGenericData added to export list
//
// Revision 1.16  2002/04/18 16:12:02  tnussb
// (1) GetTan512() added
// (2) GetSin16384() performs now clipping to valid angle range
// (3) includes now load.c / functions from load.c added to exports table
// (4) includes now fastsqrt.c / function fastsqrt added to exports table
//
// Revision 1.15  2002/04/17 16:38:45  tnussb
// (1) GetSin16384() function added
// (2) cos table removed from export list
//
// Revision 1.14  2002/04/17 10:00:33  tnussb
// exporting now the tan512 table, too
//
// Revision 1.13  2002/04/15 10:02:36  tnussb
// function GetArcTanYX() added (thanx, Scott!)
//
// Revision 1.11  2002/03/29 15:45:11  tnussb
// (1) rendering of inverted textures for walls fixed
// (2) due to a bugfix in the fixtex64 tool a modification
// of the texture drawing was necessary. This modification
// causes previously converted textures to be displayed
// inverted. If a texture contains text or similar inversion
// critical stuff you have to reconvert it using fixtex64.
// Sorry for that.
//
// Revision 1.10  2002/03/29 09:10:51  tnussb
// SetUpperHUD()/SetLowerHUD() functionality added
//
// Revision 1.9  2002/03/28 12:22:44  tnussb
// treatment of FAT_SetPreHUDCallback() added
//
// Revision 1.8  2002/03/28 10:24:26  tnussb
// treatment of function SetHUD() added
//
// Revision 1.7  2002/03/25 10:02:35  tnussb
// distance array content now treated correctly when horizontal_hit_distance
// equals to MAX_DISTANCE (Scott Noveck)
//
// Revision 1.6  2002/03/11 09:09:34  tnussb
// USE_V200 added (its not really necessary for the engine)
//
// Revision 1.5  2002/03/08 14:01:52  tnussb
// (1) removed all outcommented code
// (2) minor sourcecode beautifying
//
// Revision 1.4  2002/03/06 11:45:19  tnussb
// (1) "exports" now all internal tables
// (2) includes now unpack.c and "exports" the ExePack decompression routine
// (3) "exports" now various compiled-in strings like the version string
//
// Revision 1.3  2002/03/01 11:07:33  tnussb
// generic commit for sourcecode release v0.81
//
// Revision 1.2  2001/03/11 19:17:56  Thomas Nussbaumer
// changes due to v0.63
//
// Revision 1.1  2001/03/04 20:14:41  Thomas Nussbaumer
// initial version
//
