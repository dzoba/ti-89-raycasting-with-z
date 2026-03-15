/******************************************************************************
*
* project name:   FAT-Engine
* file name:      genscalers.c
* initial date:   05/03/2001
* author:         thomas.nussbaumer@gmx.net
*
* description:    generates 68kASM scaling routines for vertical texture
*                 scaling
*
* NOTE: this program should be compilable with any ANSI C compiler
*
* since FAT-Engine version 0.60 a new scaling method inspired by a technique
* of ID-Software (Wolfenstein3D) is used.
* Instead of using a table with indices like explained in tutorial S2P1 I use
* now multiple precompiled scalers. The minimum number of scalers generate-able
* by this tool is 16 (I think), but then the picture quality is very awkfully.
* At least 48 scalers should be used for a pleasant result.
* Due to the fact that each strip is centered vertically, only scalers for
* even heights make sense.
*
* The output of this tool is a textfile containing the assembler code of the
* pregenerated scalers.
*
* The new approach is faster in general. If the average strip height is small
* the speed improvement is not high, but if the average strip height is large
* (for example all near or above 96) the speed improvement is very significant.
* The rendering speed seems to be constant with this approach as far as I can
* see now from my measurements. There seems to be no dependance on the average
* wall height left ...
*
* The "necessary memory to quality" relationship can be controlled with:
* END_HEIGHT, DOUBLE_STEP_HEIGHT, TRIPLE_STEP_HEIGHT
*
* If you reduce the END_HEIGHT the scalers will need less memory, but you
* get distortion effects when you come near walls.
* If you reduce DOUBLE_STEP_HEIGHT and TRIPLE_STEP_HEIGHT the scalers will
* also need less memory, but you will get noticable steps in the textures
* when looking along a wall.
*
* The only drawback I see with this method is that all textures have to be
* turned 90 degrees to the right, but this can be easily performed by a
* simple tool like fixtex64 (folder src\tools). And there is of course the
* drawback of memory demand ...
*
* $Id: genscalers.c,v 1.4 2002/04/19 08:41:00 tnussb Exp $
*
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//-----------------------------------------------------------------------------
// just used internally to output the CVS revision number and the date/time of
// build
//-----------------------------------------------------------------------------
#define CVS_TRUNC_PREFIX    ((strlen((CVS_FILE_REVISION))<=11) ? 0 : (CVS_FILE_REVISION+11))
#define CVS_FIND_COMMA      (strchr(CVS_TRUNC_PREFIX,'.'))
#define CVSREV_MAIN         (int)(!(CVS_TRUNC_PREFIX) ? 0 : atoi(CVS_TRUNC_PREFIX))
#define CVSREV_SUB          (int)(!(CVS_TRUNC_PREFIX) ? 0 : (!(CVS_FIND_COMMA) ? 0 : atoi(CVS_FIND_COMMA+1)))
#define CVSREV_PRINTPARAMS  "v%d.%02d",CVSREV_MAIN,CVSREV_SUB
#define PRINT_ID(name)      printf("// "name" ");printf(CVSREV_PRINTPARAMS);\
                            printf(" - Part of FAT-Engine\n" \
                                   "// (c) thomas.nussbaumer@gmx.net\n");
#ifdef CVS_FILE_REVISION
#undef CVS_FILE_REVISION
#endif
#define CVS_FILE_REVISION "$Revision: 1.4 $"


//-----------------------------------------------------------------------------
// modifyable constants
//-----------------------------------------------------------------------------
#define END_HEIGHT              170         // >= VISIBLE_HEIGHT and even
#define DOUBLE_STEP_HEIGHT      110         // >= START_HEIGHT
#define TRIPLE_STEP_HEIGHT      130         // >= START_HEIGHT


//-----------------------------------------------------------------------------
// constants - don't change !!
//-----------------------------------------------------------------------------
#define START_HEIGHT              2
#define TEX_HEIGHT               64
#define VISIBLE_HEIGHT           96
#define DEST_BYTE_WIDTH           2

//-----------------------------------------------------------------------------
// C++ like casting ;-)
//-----------------------------------------------------------------------------
#define DOUBLE(a)  ((double)(a))
#define SHORT(a)   ((short)(a))


/*=============================================================================
 helper function to generate unique numbers for scaler labels
=============================================================================*/
int label_nr = 0;
int GetNextLabelNr() {
    return label_nr++;
}


/******************************************************************************
* the generated scalers use the following input parameters:
*
* %d0   ... one half of the texture (note: texture rotated 90 degree right)
* %d1   ... or mask to set pixel in destination word
* %d2   ... and mask to clear pixel in destination word
* %a0   ... destination address
******************************************************************************/
void GenerateSingleScaler(int destination_height) {
     double delta  = DOUBLE(TEX_HEIGHT-1)/DOUBLE(destination_height-1);
     double h      = 0.0;
     double tmp_h;
     int    i,j;
     int    tmp_h2;
     int    nrs;

     int    lnr;
     int    endloop;

     if (destination_height <= VISIBLE_HEIGHT) {
         delta     = DOUBLE(TEX_HEIGHT-1)/DOUBLE(destination_height-1);
         endloop   = destination_height;
         h         = 0.0;
     }
     else {
         int lines_to_skip = (destination_height - VISIBLE_HEIGHT)/2;
         delta             = DOUBLE(TEX_HEIGHT-1)/DOUBLE(destination_height-1);
         h                 = floor(lines_to_skip * delta);
         endloop           = VISIBLE_HEIGHT;
     }

     for (i=0;i<endloop/2;) {
         nrs   = 1;
         tmp_h = h;
         lnr   = GetNextLabelNr();

         while (SHORT(h) == SHORT(tmp_h+delta)) {
             tmp_h+=delta;
             nrs++;
         }

         tmp_h2 = 31-SHORT(h);
         if (tmp_h2<0 || tmp_h2 > 31) printf("\n!!! error h= %d !!!\n",tmp_h2);
         else {
             //-------------------------------------------------------------------------------------
             // use TST when possible and check against sign flag !!! (2 bytes shorter and faster!!)
             //-------------------------------------------------------------------------------------
             if (tmp_h2==7) {
                 printf("tst.b %%d0\n");
                 printf("bpl.s ___a%04x\n",lnr);
             }
             else if (tmp_h2 == 15) {
                 printf("tst.w %%d0\n");
                 printf("bpl.s ___a%04x\n",lnr);
             }
             else if (tmp_h2 == 31) {
                 printf("tst.l %%d0\n");
                 printf("bpl.s ___a%04x\n",lnr);
             }
             else {
                 printf("btst #%d,%%d0\n",tmp_h2);
                 printf("beq.s ___a%04x\n",lnr);
             }
         }
         for (j=0;j<nrs;j++) {
             if (i+j >= VISIBLE_HEIGHT/2) break;
             printf("or.w %%d1,(%%a0)+\n");
         }

         if (i+nrs>=VISIBLE_HEIGHT || i+nrs>=endloop/2) {
             printf("rts\n");
         }
         else {
             printf("bra.s ___c%04x\n",lnr);
         }
         printf("___a%04x:\n",lnr);

         for (j=0;j<nrs;j++) {
             if (i+j >= VISIBLE_HEIGHT/2) break;
             printf("and.w %%d2,(%%a0)+\n");
         }
         if (i+nrs<VISIBLE_HEIGHT && i+nrs<endloop/2) {
             printf("___c%04x:\n",lnr);
         }

         i+=nrs;
         h+=nrs*delta;
         if (i >= VISIBLE_HEIGHT/2) break;
     }
     printf("rts\n");
}


/*=============================================================================
 helper function to generate jumptable entries
=============================================================================*/
void WriteEntry(int height, int lsr) {
    //--------------------------------------------------------------------
    // entry for first half ...
    //--------------------------------------------------------------------
    if (height>VISIBLE_HEIGHT) printf("nop;nop\n");        // no offset from top
    else                       printf("adda.w #%d,%%a0\n",
                                 (VISIBLE_HEIGHT/2-height/2)*DEST_BYTE_WIDTH); // calc offset from top
    printf("jmp __scale%03d(%%pc)\n",height);                                  // jump to scaler code

    //--------------------------------------------------------------------
    // entry for second half ...
    //--------------------------------------------------------------------
    // shift texture if necessary (new code of Scott Noveck)
    if (lsr>0 && lsr<9)         printf("lsr.l #%d,%%d0;nop /* lsr = %d */\n",lsr,lsr);
    else if (lsr>8 && lsr<16)   printf("swap %%d0;rol.l #%d,%%d0 /* lsr = %d */\n",16-lsr,lsr);
    else if (lsr==16)           printf("swap %%d0;nop /* lsr = %d */\n",16-lsr,lsr);
    else if (lsr>16 && lsr <24) printf("swap %%d0;ror.l #%d,%%d0 /* lsr = %d */\n",lsr-16,lsr);
    else if (lsr>23 && lsr <32) printf("rol.l #%d,%%d0;nop /* lsr = %d */\n",32-lsr,lsr);
    else                        printf("nop;nop /* lsr = %d */\n",lsr);

    // shift texture if necessary (old code)
    //if (lsr>1 && lsr<9)       printf("lsr.l #%d,%%d0;nop /* lsr = %d */\n",lsr,lsr);
    //else if (lsr>8 && lsr<32) printf("lsr.l #8,%%d0;lsr.l #%d,%%d0 /* lsr = %d */\n",lsr-8,lsr);
    //else                      printf("nop;nop /* lsr = %d */\n",lsr);

    printf("jmp __scale%03d(%%pc)\n",height);
}


/******************************************************************************
* generated scalers for different heights and generate the jumptable
*
* a complete 64 bit texture strip is scaled with 2 calls to the corresponding
* scaler. The jumptable contains maxheight/2 entries
*
* -----------------------------------------------------------------------------
* parameters equal for both calls:
* -----------------------------------------------------------------------------
* d1 .... screenmask (which pixel should be set)  word
* d2 .... inverted screenmask (used with AND to clear pixel)
*
* -----------------------------------------------------------------------------
* parameters special for CALL 1 (NOTE: content of a0 gets destroyed)
* -----------------------------------------------------------------------------
* a0 .... points to first word of word destination array of height 96
* d0 .... 32 bits of the texture which should be drawn in the upper part
*
* -----------------------------------------------------------------------------
* parameters special for CALL 2 (NOTE: content of a0/d0 gets destroyed)
* -----------------------------------------------------------------------------
* a0 .... points to the 48th word of word destination array of height 96
* d0 .... 32 bits of the texture which should be drawn in the lower part
*
*
* =============================================================================
* jumptable format
* =============================================================================
* The jumptable contains 2 entries per height (one for each of the two calls)
*
* the first call have to be addressed this way:
* ---------------------------------------------
*
* jumptable_start + 16 * height/2
*
*
* the second call have to be addressed this way:
* ----------------------------------------------
*
* jumptable_start + 16 * height/2 + 8
*
*
******************************************************************************/
void GenerateScalers() {
    int i;

    //-------------------------------------------------------------------------
    // generate header and code of scalers
    //-------------------------------------------------------------------------
    printf("#define CLIP_HEIGHT %d // max. height usable without crashing\n",END_HEIGHT-2); // -2 to make sure not to run out

    //-------------------------------------------------------------------------
    // NOTE: It's IMPORTANT that the scalers becomes located also in the
    //       .text section !!! Otherwise the program will crash, because the
    //       the linker will produce an entry in the relocation table when
    //       the engine tries to access the table with lea xxx(%pc),%ax
    //       By putting the scalers also in the .text section the assembler
    //       can already resolve the correct offset and the linker will not
    //       be forced to generate an relocation table entry.
    //
    // !!! IMPORTANT: TIGCC 0.91 maps everything into segment ".data" !!!!
    //-------------------------------------------------------------------------
    //printf("\nasm(\".text\n");
    printf("\nasm(\".data\n");

    for (i=START_HEIGHT;i<=END_HEIGHT;i+=2) {
        printf("__scale%03d:\n",i);
        GenerateSingleScaler(i);
        if (i>=TRIPLE_STEP_HEIGHT) i+=4;
        else if (i>=DOUBLE_STEP_HEIGHT) i += 2;
    }

    //-------------------------------------------------------------------------
    // generate jumptable
    //-------------------------------------------------------------------------
    printf("ScalerJumpTable:\n");
    for (i=START_HEIGHT;i<=END_HEIGHT;i+=2) {
         short lsr = SHORT(DOUBLE((i - VISIBLE_HEIGHT)/2)*(DOUBLE(TEX_HEIGHT-1)/DOUBLE(i-1)));

         WriteEntry(i,lsr);

         //--------------------------------------------------------------------
         // triple entry to save space ...
         //--------------------------------------------------------------------
         if (i>=TRIPLE_STEP_HEIGHT) {
            WriteEntry(i,lsr);
            WriteEntry(i,lsr);
            i+=4;
         }
         //--------------------------------------------------------------------
         // double entry to save space ...
         //--------------------------------------------------------------------
         else if (i>=DOUBLE_STEP_HEIGHT) {
            WriteEntry(i,lsr);
            i+=2;
         }
    }

    printf("\");\n");  // end of asm part
}


/******************************************************************************
* just a simple main ...
******************************************************************************/
int main(int argc,char* argv[]) {
    printf("//=============================================================================\n");
    printf("// this file was automatically generated with:\n//\n");
    PRINT_ID("GenScalers");
    printf("//=============================================================================\n\n");
    GenerateScalers();
    return 0;
}

//#############################################################################
// Revision History
//#############################################################################
//
// $Log: genscalers.c,v $
// Revision 1.4  2002/04/19 08:41:00  tnussb
// (1) speed optimization (double shifts replaced) - Scott Noveck
// (2) missing shift by 1 fixed - Scott Noveck
//
// Revision 1.3  2002/03/28 12:26:38  tnussb
// timestamp in generated output removed so CVS will not get "confused" anymore
//
// Revision 1.2  2002/03/01 11:06:03  tnussb
// generic commit for sourcecode release v0.81
//
// Revision 1.1  2001/03/11 19:18:44  Thomas Nussbaumer
// initial version
//
//

