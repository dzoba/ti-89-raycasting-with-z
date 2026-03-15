/******************************************************************************
*
* project name:  FAT-Engine
* file name:     scale_it.c
* initial date:  05/03/2001
* author:        thomas.nussbaumer@gmx.net
* description:   contains strip scaling routines
*
* multidirectional sprite support in OutputSprites added by Scott Noveck
* (noveck@pluto.njcc.com)
*
* $Id: scale_it.c,v 1.17 2002/05/02 09:31:43 tnussb Exp $
*
******************************************************************************/

#include "scalers.c"
#include "transscalers.c"

//-----------------------------------------------------------------------------
// SCALE_IT - input parameters:
//
// dest       .... pointer to destination buffer (%0)
// height     .... height to scale to            (%1)
// texture    .... pointer to texture            (%2)
// screenmask .... mask to use for output        (%3)
//
// modified input:
//
// NONE
//
// clobbered regs: d0,d1,d2,d3,a0,a1
//-----------------------------------------------------------------------------
//
// m memory operand with any kind of address
// g Any register, memory or immediate integer operand,
//   except for registers that are not general registers
// a Address register
// d Data register
// I Integer in the range 1 to 8
// J 16 bit signed number
// K Signed number whose magnitude is greater than 0x80
// L Integer in the range -8 to -1
// M Signed number whose magnitude is greater than 0x100
//
//-----------------------------------------------------------------------------

#define SCALE_IT(dest,height,texture,mask)  \
asm volatile (\
    "moveq   #0,%%d3\n"\
    "move.w  %1,%%d3\n"\
    "and.b   #0xfe,%%d3\n"\
    "lsl.w   #3,%%d3\n"\
    "lea     ScalerJumpTable,%%a1\n"\
    "adda.w  %%d3,%%a1\n"\
    "move.l  (%2),%%d0\n" /* fetch texture */\
    "move.l  %0,%%a0\n"\
    "move.w  %3,%%d1\n"\
    "move.l  %%d1,%%d2\n"\
    "not.w   %%d2\n"\
    "move.l  %%a0,%%d3\n"\
    "jsr     (%%a1)\n"\
    "move.l  4(%2),%%d0\n" /* fetch 2nd texture*/\
    "move.l  %%d3,%%a0\n"\
    "adda.w  #2*48,%%a0\n"\
    "adda.w  #8,%%a1\n"\
    "jsr     (%%a1)\n"\
: /* no output */ \
: "a" (dest), "d" (height), "a"(texture), "d" (mask) \
: "d0", "d1", "d2", "d3", "a0", "a1", "cc")

//-----------------------------------------------------------------------------
// DUAL_SCALE_IT - renders both light and dark planes with shared setup.
// The scaler preserves d1 (mask) and d2 (~mask), so we compute them once.
// Saves ~52 cycles per column vs two separate SCALE_IT calls.
//-----------------------------------------------------------------------------
#define DUAL_SCALE_IT(dest_light,dest_dark,height,tex_light,tex_dark,mask)  \
asm volatile (\
    "moveq   #0,%%d3\n"\
    "move.w  %2,%%d3\n"\
    "and.b   #0xfe,%%d3\n"\
    "lsl.w   #3,%%d3\n"\
    "lea     ScalerJumpTable,%%a1\n"\
    "adda.w  %%d3,%%a1\n"\
    "move.w  %5,%%d1\n"\
    "move.l  %%d1,%%d2\n"\
    "not.w   %%d2\n"\
    /* Light plane - first half */\
    "move.l  (%3),%%d0\n"\
    "move.l  %0,%%a0\n"\
    "move.l  %%a0,%%d3\n"\
    "jsr     (%%a1)\n"\
    /* Light plane - second half */\
    "move.l  4(%3),%%d0\n"\
    "move.l  %%d3,%%a0\n"\
    "adda.w  #2*48,%%a0\n"\
    "adda.w  #8,%%a1\n"\
    "jsr     (%%a1)\n"\
    /* Dark plane - first half (d1,d2 preserved by scaler!) */\
    "suba.w  #8,%%a1\n"\
    "move.l  (%4),%%d0\n"\
    "move.l  %1,%%a0\n"\
    "move.l  %%a0,%%d3\n"\
    "jsr     (%%a1)\n"\
    /* Dark plane - second half */\
    "move.l  4(%4),%%d0\n"\
    "move.l  %%d3,%%a0\n"\
    "adda.w  #2*48,%%a0\n"\
    "adda.w  #8,%%a1\n"\
    "jsr     (%%a1)\n"\
: /* no output */ \
: "a" (dest_light), "a" (dest_dark), "d" (height), "a"(tex_light), "a"(tex_dark), "d" (mask) \
: "d0", "d1", "d2", "d3", "a0", "a1", "cc")


//-----------------------------------------------------------------------------
// TRANS_SCALE_IT - input parameters:
//
// dest       .... pointer to destination buffer (%0)
// height     .... height to scale to            (%1)
// texture    .... pointer to texture            (%2)
// screenmask .... mask to use for output        (%3)
// trans      .... pointer to transparency mask  (%4)
//
// modified input:
//
// NONE
//
// clobbered regs: d0,d1,d2,d3,d4,a0,a1
//-----------------------------------------------------------------------------

// m memory operand with any kind of address
// g Any register, memory or immediate integer operand,
//   except for registers that are not general registers
// a Address register
// d Data register
// I Integer in the range 1 to 8
// J 16 bit signed number
// K Signed number whose magnitude is greater than 0x80
// L Integer in the range -8 to -1
// M Signed number whose magnitude is greater than 0x100

//-----------------------------------------------------------------------------
// render upper and lower part of sprite at once
//-----------------------------------------------------------------------------
#define TRANS_SCALE_IT(dest,height,texture,trans,mask)  \
asm volatile (\
    "moveq   #0,%%d4\n"\
    "move.w  %1,%%d4\n"\
    "and.b   #0xfe,%%d4\n"\
    "lsl.w   #3,%%d4\n"\
    "lea     TransScalerJumpTable,%%a1\n"\
    "adda.w  %%d4,%%a1\n"\
    "move.l  (%2),%%d0\n" /* fetch texture */\
    "move.l  (%3),%%d3\n" /* fetch transparency */\
    "move.l  %0,%%a0\n"\
    "move.w  %4,%%d1\n"\
    "move.l  %%d1,%%d2\n"\
    "not.w   %%d2\n"\
    "move.l  %%a0,%%d4\n"\
    "jsr     (%%a1)\n"\
    "move.l  4(%2),%%d0\n" /* fetch 2nd texture */\
    "move.l  4(%3),%%d3\n" /* fetch 2nd transparency */\
    "move.l  %%d4,%%a0\n"\
    "adda.w  #2*48,%%a0\n"\
    "adda.w  #8,%%a1\n"\
    "jsr     (%%a1)\n"\
: /* no output */ \
: "a" (dest), "g" (height), "a" (texture), "a" (trans), "g" (mask) \
: "d0", "d1", "d2", "d3", "d4", "a0", "a1", "cc", "memory")


//-----------------------------------------------------------------------------
// render ONLY upper part of sprite
//-----------------------------------------------------------------------------
#define TRANS_SCALE_IT_UPPERPART(dest,height,texture,trans,mask)  \
asm volatile (\
    "moveq   #0,%%d4\n"\
    "move.w  %1,%%d4\n"\
    "and.b   #0xfe,%%d4\n"\
    "lsl.w   #3,%%d4\n"\
    "lea     TransScalerJumpTable,%%a1\n"\
    "adda.w  %%d4,%%a1\n"\
    "move.l  (%2),%%d0\n" /* fetch texture */\
    "move.l  (%3),%%d3\n" /* fetch transparency */\
    "move.l  %0,%%a0\n"\
    "move.w  %4,%%d1\n"\
    "move.l  %%d1,%%d2\n"\
    "not.w   %%d2\n"\
    "move.l  %%a0,%%d4\n"\
    "jsr     (%%a1)\n"\
: /* no output */ \
: "a" (dest), "g" (height), "a" (texture), "a" (trans), "g" (mask) \
: "d0", "d1", "d2", "d3", "d4", "a0", "a1", "cc", "memory")

//-----------------------------------------------------------------------------
// render ONLY lower part of sprite
//-----------------------------------------------------------------------------
#define TRANS_SCALE_IT_LOWERPART(dest,height,texture,trans,mask)  \
asm volatile (\
    "moveq   #0,%%d4\n"\
    "move.w  %1,%%d4\n"\
    "and.b   #0xfe,%%d4\n"\
    "lsl.w   #3,%%d4\n"\
    "lea     TransScalerJumpTable,%%a1\n"\
    "adda.w  %%d4,%%a1\n"\
    "move.l  %0,%%a0\n"\
    "move.w  %4,%%d1\n"\
    "move.l  %%d1,%%d2\n"\
    "not.w   %%d2\n"\
    "move.l  4(%2),%%d0\n" /* fetch 2nd texture */\
    "move.l  4(%3),%%d3\n" /* fetch 2nd transparency */\
    "adda.w  #2*48,%%a0\n"\
    "adda.w  #8,%%a1\n"\
    "jsr     (%%a1)\n"\
: /* no output */ \
: "a" (dest), "g" (height), "a" (texture), "a" (trans), "g" (mask) \
: "d0", "d1", "d2", "d3", "d4", "a0", "a1", "cc", "memory")

//-----------------------------------------------------------------------------
// both render buffers have 96*3 word entries and are allocated in
// one piece (render_buf0 comes first!)
//-----------------------------------------------------------------------------
unsigned short* render_buf0 = NULL;
unsigned short* render_buf1 = NULL;
unsigned short* sprite_dest_offsets = NULL;
unsigned short* sprite_screen_masks = NULL;


#define ACTORSIZE ((long)(64L<<7L))
#define MINDIST   ((long)(10L<<7L))

INTERNAL_REFERENCED inline void OutputSprites(FATCONFIG* fc) {
    short  i;
    short  x0;
    short  size;
    short  x;
    short  start_x;
    short  end_x;
    short  distance;
    unsigned short  delta;
    unsigned short  line;
    short  spritedir;
    short  cam_sin = GetSin16384(fc->cam_orientation);
    short  cam_cos = GetSin16384(ANGLE_090+fc->cam_orientation);
    short* distances = depthinfo->distance;
    unsigned short* dest1;
    unsigned short* dest2;
    unsigned short  screen_mask;   // bitmask for display
    unsigned short* trans;
    unsigned short* src1;
    unsigned short* src2;
    TEXCONFIG*      sprite_texture;
    long            dx,dy,nx;
    unsigned short  texture_index;
    TEXSTRIP*       ts;
    unsigned short  offset;
    unsigned short  dest_off;
    FATSPRITE*      farthest = 0;
    FATSPRITE*      tmp;
    FATSPRITE*      fs;

    for (i=0;i<fc->nr_sprites;i++) {
        fs = fc->sprites + i;

        // sprite should not be drawn (drawmode == SPRITEMODE_UNUSED)
        if (!fs->drawmode) continue;

        // clip the sprite orientation to the valid range!!
        while (fs->orientation<ANGLE_000)  fs->orientation+=ANGLE_360;
        while (fs->orientation>=ANGLE_360) fs->orientation-=ANGLE_360;

        //---------------------------------------------------------------------
        // dx = sprite_x-cam_x
        // dy = sprite_y-cam_y
        // nx = dx*cos(cam_angle)+dy*sin(cam_angle)-ACTORSIZE
        //---------------------------------------------------------------------
        dx  = (long)(fs->xpos - fc->cam_xpos);
        dy  = (long)(fs->ypos - fc->cam_ypos);

        nx = dx*(long)cam_cos + dy*(long)cam_sin;

        if (nx < (MINDIST+ACTORSIZE)) {
            fs->height  = -1;
            fs->centerx = -1;
            fs->angle   = -1;
            fs->dist    = -1;
            continue;
        }
        size = (SCALE_VALUE<<14L)/nx;

        if (size <= 2) {
            fs->height  = -1;
            fs->centerx = -1;
            fs->angle   = -1;
            fs->dist    = -1;
            continue;
        }

        if (size > TRANS_CLIP_HEIGHT) size = TRANS_CLIP_HEIGHT;

        distance   = (nx >> 14L);
        fs->dist   = distance;
        fs->angle  = GetArcTanYX(dy,dx);
        fs->height = size;

        // calculate the center of sprite related to the 96 pixels wide screen.

        // new calculation by Scott Noveck (the angle need to be clamped to
        // a certain range otherwise we are in troubles when the cam_orientation
        // wraps around from 0 to 575)
        fs->centerx = fs->angle - fc->cam_orientation;
        if (fs->centerx >= ANGLE_180)       fs->centerx -= ANGLE_360;
        else if (fs->centerx < -ANGLE_180)  fs->centerx += ANGLE_360;
        fs->centerx += SCREEN_WIDTH_HALF;


        // no farthest sprite yet ...
        if (!farthest) {
            farthest = fs;
            fs->next = 0;
            fs->prev = 0;
            continue;
        }

        // farther than farthest sprite ...
        if (farthest->dist <= distance) {
            // new farthest!
            fs->next       = farthest;
            farthest->prev = fs;
            farthest       = fs;
            fs->prev       = 0;
            continue;
        }

        // farthest sprite has no next sprite set ...
        if (!farthest->next) {
            fs->next       = 0;
            fs->prev       = farthest;
            farthest->next = fs;
            continue;
        }

        tmp = farthest->next;
        while (1) {
            // active sprite is farther away than actual entry in list
            if (tmp->dist < distance) {
                fs->prev  = tmp->prev;
                fs->next  = tmp;
                tmp->prev = fs;
                fs->prev->next = fs;
                break;
            }

            // we have reached the end of the list
            if (!tmp->next) {
                tmp->next = fs;
                fs->next  = 0;
                fs->prev  = tmp;
                break;
            }

            tmp = tmp->next;
        }
    }

    fs = farthest;
    while (fs) {
        // now we're sure we're going to draw the sprite so calculate what
        // direction texture to use here (Scott Noveck)

        // sprites with 8 directions are prefered ... so check this cases first
        if (fs->nr_textures == 8) {
            spritedir = (fs->orientation - fs->angle);
            if (spritedir < 0) spritedir += ANGLE_360;
            spritedir = ((spritedir+ANGLE_045/2)/ANGLE_045);
            if (spritedir == 8) spritedir = 0;
            sprite_texture = fs->textures + spritedir;
        }
        else if (fs->nr_textures == 1) {
            sprite_texture = fs->textures;
        }
        else {
            short divangle;
            switch (fs->nr_textures) {
                case 2:  divangle = ANGLE_360>>1; break;
                case 4:  divangle = ANGLE_360>>2; break;
                case 16: divangle = ANGLE_360>>4; break;
                default: divangle = ANGLE_360/fs->nr_textures;
            }
            spritedir = (fs->orientation - fs->angle);
            if (spritedir < 0) spritedir += ANGLE_360;
            spritedir = ((spritedir+divangle/2)/divangle);
            if (spritedir == fs->nr_textures)  spritedir = 0;
            sprite_texture = fs->textures + spritedir;
        }

        size  = fs->height;
        line  = 0x3f<<8;
    	delta = sprite_delta[(size-2)>>1];
        x0    = fs->centerx - (size>>1);

        size &= 0xfffe;  // IMPORTANT FIX! Otherwise the loop below
                         // may run too long which results in an invalid
                         // texture strip index of >3

        distance = fs->dist;

        // early clip to screen bounds
        start_x = x0;
        end_x   = x0 + size;
        if (start_x < 0) {
            line   -= (unsigned short)((unsigned long)delta * (unsigned short)(-start_x));
            start_x = 0;
        }
        if (end_x > 96) end_x = 96;
        if (start_x >= end_x) {
            fs = fs->next;
            continue;
        }

        //---------------------------------------------------------------------
        // draw full-sized sprite
        //---------------------------------------------------------------------
        if (fs->drawmode & SPRITEMODE_SIZE64) {
	        for (x=start_x;x<end_x;x++,line-=delta) {
                if (distance < distances[x]) {
                    texture_index = line >> 8;
                    ts            = sprite_texture->strips + (texture_index >> 4);

                    if (ts->mirrored & STRIP_IGNORE) continue; // addition for ignored strips!
                    else if (ts->mirrored) {
                        offset = (0x0f<<2) - ((texture_index & 0x0f)<<2);
                    }
                    else {
                        offset = (texture_index & 0x0f)<<2;
                    }

                    dest_off    = sprite_dest_offsets[x];
                    screen_mask = sprite_screen_masks[x];
                    trans       = ts->maskdata  + offset;
                    src1        = ts->lightdata + offset;
                    src2        = ts->darkdata  + offset;
                    dest1       = render_buf0   + dest_off;
                    dest2       = render_buf1   + dest_off;

                    TRANS_SCALE_IT(dest1,size,src1,trans,screen_mask);
                    TRANS_SCALE_IT(dest2,size,src2,trans,screen_mask);
                }
            }
        }
        //---------------------------------------------------------------------
        // draw only lower part of sprite
        //---------------------------------------------------------------------
        else if (fs->drawmode & SPRITEMODE_LOWER32) {
	        for (x=start_x;x<end_x;x++,line-=delta) {
                if (distance < distances[x]) {
                    texture_index = line >> 8;
                    ts            = sprite_texture->strips + (texture_index >> 4);

                    if (ts->mirrored & STRIP_IGNORE) continue; // addition for ignored strips!
                    else if (ts->mirrored) {
                        offset = (0x0f<<2) - ((texture_index & 0x0f)<<2);
                    }
                    else {
                        offset = (texture_index & 0x0f)<<2;
                    }

                    dest_off    = sprite_dest_offsets[x];
                    screen_mask = sprite_screen_masks[x];
                    trans       = ts->maskdata  + offset;
                    src1        = ts->lightdata + offset;
                    src2        = ts->darkdata  + offset;
                    dest1       = render_buf0   + dest_off;
                    dest2       = render_buf1   + dest_off;

                    TRANS_SCALE_IT_LOWERPART(dest1,size,src1,trans,screen_mask);
                    TRANS_SCALE_IT_LOWERPART(dest2,size,src2,trans,screen_mask);
                }
            }
        }
        //---------------------------------------------------------------------
        // draw only upper part of sprite
        //---------------------------------------------------------------------
        else if (fs->drawmode & SPRITEMODE_UPPER32) {
	        for (x=start_x;x<end_x;x++,line-=delta) {
                if (distance < distances[x]) {
                    texture_index = line >> 8;
                    ts            = sprite_texture->strips + (texture_index >> 4);

                    if (ts->mirrored & STRIP_IGNORE) continue; // addition for ignored strips!
                    else if (ts->mirrored) {
                        offset = (0x0f<<2) - ((texture_index & 0x0f)<<2);
                    }
                    else {
                        offset = (texture_index & 0x0f)<<2;
                    }

                    dest_off    = sprite_dest_offsets[x];
                    screen_mask = sprite_screen_masks[x];
                    trans       = ts->maskdata  + offset;
                    src1        = ts->lightdata + offset;
                    src2        = ts->darkdata  + offset;
                    dest1       = render_buf0   + dest_off;
                    dest2       = render_buf1   + dest_off;

                    TRANS_SCALE_IT_UPPERPART(dest1,size,src1,trans,screen_mask);
                    TRANS_SCALE_IT_UPPERPART(dest2,size,src2,trans,screen_mask);
                }
            }
        }
        //---------------------------------------------------------------------
        // sprite draw mode not recognized ...
        //---------------------------------------------------------------------
        //else {
             //printf_xy(0,0,"INVALID MODE !!!");
             //__HALT;
        //}


        fs=fs->next;
    }
}


/******************************************************************************
* render all strips using the pre-generated scalers
*
* the rendering of the complete 3D view is performed in six big strips each 16
* pixels wide, because this way the pre-generated scalers can simply use (%a0)+
* to proceed to the next destination address and use word arithmetics for speed.
*
* This routine could be further optimized by converting it to assembler.
* this way the parameter push's and pop's per strip could be left out.
* But unless the "logic" is not complete it make no sense to me to convert it
* to assembler, because changes are much harder to perform in assembler than
* in C.
******************************************************************************/
INTERNAL_REFERENCED inline void RenderStrips(FATCONFIG* fc) {
    short           i,j;
    unsigned short  screen_mask;   // bitmask for display
    unsigned short* dest1;
    unsigned short* dest2;
    unsigned short* dest3;
    unsigned short* dest4;
    unsigned short* dest5;
    unsigned short* dest6;
    unsigned short* hud_mask;
    unsigned short* hud_data;

    unsigned short* src;
    unsigned short* height;
    unsigned long*  lightdata;
    unsigned long*  darkdata;

    unsigned long*  longsrc1;
    unsigned long*  longsrc2;
    unsigned long*  longdest1;
    unsigned long*  longdest2;

    if (!fc->background) {
        // no background set, clear buffers in one rush using long writes (8x unrolled) ...
        longdest1=(unsigned long*)render_buf0;
        for (i=0;i<576/8;i++) {
            *longdest1++=0L; *longdest1++=0L; *longdest1++=0L; *longdest1++=0L;
            *longdest1++=0L; *longdest1++=0L; *longdest1++=0L; *longdest1++=0L;
        }
    }
    else {
        // otherwise fill backbuffers with background image using long read/writes ...
        longdest1 = (unsigned long*)render_buf0;
        longdest2 = longdest1+576/2;
        longsrc1  = (unsigned long*)fc->background;
        longsrc2  = longsrc1+576/2;

        for (i=0;i<576/2;i++,*longdest1++=*longsrc1++,*longdest2++=*longsrc2++);
    }

    //-------------------------------------------------------------------------
    // render the 6 strips (full asm loop — zero C overhead)
    //-------------------------------------------------------------------------
    {
        unsigned short* _dest1 = render_buf0;
        unsigned short* _dest2 = render_buf1;
        unsigned long*  _light = depthinfo->lightdata;
        unsigned long*  _dark  = depthinfo->darkdata;
        unsigned short* _height = depthinfo->height;

        asm volatile (
            "moveq   #5,%%d5\n"
            "move.w  #192,%%d7\n"

            ".Lstrip_%=:\n"
            "move.w  #0x8000,%%d4\n"
            "moveq   #15,%%d6\n"

            ".Lcol_%=:\n"
            "move.w  (%4)+,%%d3\n"
            "beq.s   .Lskip_%=\n"

            "and.b   #0xfe,%%d3\n"
            "lsl.w   #3,%%d3\n"
            "lea     ScalerJumpTable,%%a1\n"
            "adda.w  %%d3,%%a1\n"
            "move.w  %%d4,%%d1\n"
            "move.l  %%d1,%%d2\n"
            "not.w   %%d2\n"

            "move.l  (%2),%%d0\n"
            "move.l  %0,%%a0\n"
            "move.l  %%a0,%%d3\n"
            "jsr     (%%a1)\n"

            "move.l  4(%2),%%d0\n"
            "move.l  %%d3,%%a0\n"
            "adda.w  #96,%%a0\n"
            "adda.w  #8,%%a1\n"
            "jsr     (%%a1)\n"

            "suba.w  #8,%%a1\n"
            "move.l  (%3),%%d0\n"
            "move.l  %1,%%a0\n"
            "move.l  %%a0,%%d3\n"
            "jsr     (%%a1)\n"

            "move.l  4(%3),%%d0\n"
            "move.l  %%d3,%%a0\n"
            "adda.w  #96,%%a0\n"
            "adda.w  #8,%%a1\n"
            "jsr     (%%a1)\n"

            ".Lskip_%=:\n"
            "addq.l  #8,%2\n"
            "addq.l  #8,%3\n"
            "lsr.w   #1,%%d4\n"
            "dbf     %%d6,.Lcol_%=\n"

            "adda.w  %%d7,%0\n"
            "adda.w  %%d7,%1\n"
            "dbf     %%d5,.Lstrip_%=\n"

        : "+a"(_dest1), "+a"(_dest2), "+a"(_light), "+a"(_dark), "+a"(_height)
        :
        : "d0","d1","d2","d3","d4","d5","d6","d7","a0","a1","cc","memory"
        );
    }

    //-------------------------------------------------------------------------
    // now outputs sprites ...
    //-------------------------------------------------------------------------
    OutputSprites(fc);

    //-------------------------------------------------------------------------
    // if a PreHUD callback is set call it now ...
    //-------------------------------------------------------------------------
    if (prehud_callback) prehud_callback(fc,render_buf0,render_buf1);

    //-------------------------------------------------------------------------
    // now its time to copy the content of the six strips to the given
    // destination planes
    //
    // IMPORTANT: the destination plane ADDRESSES have to EVEN !!!!!
    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    // treatment of grayplane0
    //-------------------------------------------------------------------------
    src      = fc->dest_plane0;
    dest1    = render_buf0;
    dest2    = dest1+96;
    dest3    = dest2+96;
    dest4    = dest3+96;
    dest5    = dest4+96;
    dest6    = dest5+96;
    hud_mask = hudmask_high;
    hud_data = hudplane0_high;

    if (!hud_mask || !hud_data) {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = *dest1++;
            *src++ = *dest2++;
            *src++ = *dest3++;
            *src++ = *dest4++;
            *src++ = *dest5++;
            *src++ = *dest6++;
        }
    }
    else {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = (*dest1++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest2++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest3++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest4++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest5++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest6++ & *hud_mask++) | *hud_data++;
        }
    }

    hud_mask = hudmask_low;
    hud_data = hudplane0_low;

    if (!hud_mask || !hud_data) {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = *dest1++;
            *src++ = *dest2++;
            *src++ = *dest3++;
            *src++ = *dest4++;
            *src++ = *dest5++;
            *src++ = *dest6++;
        }
    }
    else {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = (*dest1++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest2++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest3++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest4++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest5++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest6++ & *hud_mask++) | *hud_data++;
        }
    }

    //-------------------------------------------------------------------------
    // treatment of grayplane1
    //-------------------------------------------------------------------------
    src      = fc->dest_plane1;
    dest1    = render_buf1;
    dest2    = dest1+96;
    dest3    = dest2+96;
    dest4    = dest3+96;
    dest5    = dest4+96;
    dest6    = dest5+96;
    hud_mask = hudmask_high;
    hud_data = hudplane1_high;

    if (!hud_mask || ! hud_data) {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = *dest1++;
            *src++ = *dest2++;
            *src++ = *dest3++;
            *src++ = *dest4++;
            *src++ = *dest5++;
            *src++ = *dest6++;
        }
    }
    else {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = (*dest1++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest2++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest3++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest4++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest5++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest6++ & *hud_mask++) | *hud_data++;
        }
    }

    hud_mask = hudmask_low;
    hud_data = hudplane1_low;

    if (!hud_mask || !hud_data) {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = *dest1++;
            *src++ = *dest2++;
            *src++ = *dest3++;
            *src++ = *dest4++;
            *src++ = *dest5++;
            *src++ = *dest6++;
        }
    }
    else {
        for (i=0;i<48;i++,src+=nr_skipwords) {
            *src++ = (*dest1++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest2++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest3++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest4++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest5++ & *hud_mask++) | *hud_data++;
            *src++ = (*dest6++ & *hud_mask++) | *hud_data++;
        }
    }
}

//#############################################################################
// Revision History
//#############################################################################
//
// $Log: scale_it.c,v $
// Revision 1.17  2002/05/02 09:31:43  tnussb
// sprites were drawn inverted previously (I haven't guessed that). Now sprite
// textures are handled as supposed in the docs. All textures are rotated
// 90 degrees to the left. There for sprite column 1 is at the bottom of the
// rotated texture.
//
// Revision 1.16  2002/04/24 17:37:28  tnussb
// (1) clamping of sprite orientation while rendering added
// (2) ACTORSIZE substraction removed from nx calculation
//
// Revision 1.15  2002/04/17 16:36:28  tnussb
// uses now GetSin16384() function instead of sin/cos tables
//
// Revision 1.14  2002/04/17 10:01:31  tnussb
// (1) disappearing sprites bug fixed
// (2) minor speedup by removing unnecessary calculations
//
// Revision 1.13  2002/04/15 10:04:56  tnussb
// (1) using new function GetArcTanYX() now to calculate angle between sprite
//     and camera (thanx, Scott!)
// (2) handling of STRIP_IGNORE added
//
// Revision 1.12  2002/04/08 20:20:09  tnussb
// (1) sorting of sprites before drawing added
// (2) centerx, distance and height of FATSPRITE structures get updated now
//     correctly (or set to -1 if sprite is not visible on the screen)
//
// Revision 1.11  2002/03/29 09:10:51  tnussb
// SetUpperHUD()/SetLowerHUD() functionality added
//
// Revision 1.10  2002/03/28 12:22:45  tnussb
// treatment of FAT_SetPreHUDCallback() added
//
// Revision 1.9  2002/03/28 10:24:26  tnussb
// treatment of function SetHUD() added
//
// Revision 1.8  2002/03/26 11:58:19  tnussb
// (1) some comments added
// (2) using now long instead of short reads/writes to copy background image (Speedup!)
//
// Revision 1.7  2002/03/25 10:03:48  tnussb
// mirror flag of sprites now treated correctly (offset calculation was
// incorrect)
//
// Revision 1.6  2002/03/12 11:57:13  tnussb
// (1) SPRITEMODE_SIZE64/UPPER32/LOWER32 treatment added
// (2) multidirectional sprite support for number of directions other than 1 and
//     8 fixed (Scott Noveck)
//
// Revision 1.5  2002/03/11 09:10:38  tnussb
// Scott's code for directional sprites with a direction number of a power of 2 added
//
// Revision 1.4  2002/03/08 14:05:14  tnussb
// (1) multidirectional sprite support in OutputSprites added by
//     Scott Noveck (noveck@pluto.njcc.com)
// (2) multidirectional support modified to a pointer to TEXCONFIG list
//     instead of embedded TEXCONFIG array
// (3) define NO_SPRITE_SUPPORT and its usage removed
// (4) functions declared inline for speedup
// (5) use of nr_sprites within sprite structure added so not every sprite
//     needs a TEXCONFIG list of 8 entries
//
// Revision 1.3  2002/03/06 11:50:36  tnussb
// important bug fix in OutputSprites() function. Previously it was possible
// that an invalid texture strip index was calculated (>3) and depending on
// the "random" data there an address error was triggered.
//
// Revision 1.2  2002/03/01 11:07:33  tnussb
// generic commit for sourcecode release v0.81
//
// Revision 1.1  2001/03/11 19:17:31  Thomas Nussbaumer
// initial version
//
//
