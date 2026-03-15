/******************************************************************************
*
* project name:  FAT-Engine
* file name:     fixtex64.c
* initial date:  06/03/2001
* author:        thomas.nussbaumer@gmx.net
* description:   tool to rotate a 64x64 grayscale or monochrome binary file
*                generated with ImageStudio 90 degrees to the right
*                (necessary for the FAT-Engine)
*
* $Id: fixtex64.c,v 1.2 2002/03/29 14:20:53 tnussb Exp $
*
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CVS_TRUNC_PREFIX    ((strlen((CVS_FILE_REVISION))<=11) ? 0 : (CVS_FILE_REVISION+11))
#define CVS_FIND_COMMA      (strchr(CVS_TRUNC_PREFIX,'.'))
#define CVSREV_MAIN         (int)(!(CVS_TRUNC_PREFIX) ? 0 : atoi(CVS_TRUNC_PREFIX))
#define CVSREV_SUB          (int)(!(CVS_TRUNC_PREFIX) ? 0 : (!(CVS_FIND_COMMA) ? 0 : atoi(CVS_FIND_COMMA+1)))
#define CVSREV_PRINTPARAMS  "v%d.%02d",CVSREV_MAIN,CVSREV_SUB
#define PRINT_ID(name)      printf(""name" ");printf(CVSREV_PRINTPARAMS);\
                            printf(" - Part of FAT-Engine\n" \
                                   "(c) thomas.nussbaumer@gmx.net "__DATE__" "__TIME__"\n");
#ifdef CVS_FILE_REVISION
#undef CVS_FILE_REVISION
#endif
#define CVS_FILE_REVISION "$Revision: 1.2 $"


//=============================================================================
// outputs usage information of this tool
//=============================================================================
void PrintUsage() {
    fprintf(stderr, "Usage: FixTex64 <infile> <outfile> [hcount vcount]\n\n"                 \
                    "       rotates 64x64 monochrome or 4-grayscale binary export file\n"    \
                    "       of ImageStudio 90 degrees to the left. If more than one tile\n" \
                    "       is in the input file you have to specify the number of vertical\n"\
                    "       and horizontal counts using hcount and vcount.\n" \
                    "       IMPORTANT NOTE: If more than 1 tile are in the input file the\n"\
                    "       tiles in the output file are REARRANGED. The width of the output\n"\
                    "       file will be 64 pixels (8 bytes) and the tiles are arranged below\n"\
                    "       each other in the following way:\n\n"\
                    "       [tile row 1 column 1 - plane 0 data]\n"\
                    "       [tile row 1 column 1 - plane 1 data]\n"\
                    "       [tile row 1 column 2 - plane 0 data]\n"\
                    "       [tile row 1 column 2 - plane 1 data]\n"\
                    "       ... and so on ...\n\n");
}


unsigned char plane[64][64];


// extracts the single bits of the input buffer
// into the char[64][64] array
void ReadPlaneFromBuffer(unsigned char* buffer) {
    unsigned char input;
    int mask = 0;
    int x,y;

    // fillorder = [0][0], [1][0], [2][0], [3][0] ...
    //             [0][1], [1][1], [2][1], [3][1] ...

    for (y=0;y<64;y++) {
        for (x=0;x<64;x++) {
            if (!mask) {
                input = *buffer++;
                mask  = 0x80;
            }
            plane[x][y] = (input & mask) ? 1 : 0;
            mask >>= 1;
        }
    }
}

// collects the single bits of the char [64][64] array and
// writes it to the given output buffer
void WritePlaneToBuffer(unsigned char* buffer) {
    unsigned char output = 0;
    int x,y;
    int mask = 0x80;

    // we want to rotate the input 90 degrees to the left
    // so the read order is the following:
    //
    // readorder = [63][0], [63][1], [63][2], [63][3] ...
    //             [62][0], [62][1], [62][2], [62][3] ...


    for (x=63;x>=0;x--) {
        for (y=0;y<64;y++) {
            if (mask == 0) {
                *buffer++ = output;
                output    = 0;
                mask      = 0x80;
            }
            if (plane[x][y]) output |= mask;
            mask >>=1;
        }
    }
}

void FetchPlaneOfTileIntoBuffer(FILE* infp,unsigned char* buffer,int actx,int maxx,int acty,int maxy,int plane) {
    int lines;
    int chars_per_line;


    rewind(infp);

    for (lines=0;lines<64;lines++) {
        int poffset    = plane*8*64*maxx*maxy;
        int yoffset    = acty*8*64*maxx;
        int lineoffset = 8*maxx*lines;
        int xoffset    = 8*actx;

        if (fseek(infp,poffset+yoffset+lineoffset+xoffset,SEEK_SET)) {
            fprintf(stderr,"FATAL: cannot seek to position while reading\n");
            exit(0);
        }

        for (chars_per_line=0;chars_per_line<64/8;chars_per_line++) {
             *buffer++ = fgetc(infp);
        }
    }
}

void SavePlaneOfTileFromBuffer(FILE* outfp,unsigned char* buffer,int actx,int maxx,int acty,int maxy,int plane,int maxplanes) {
    int lines;
    int chars_per_line;

    rewind(outfp);

    for (lines=0;lines<64;lines++) {
        if (fseek(outfp,(maxx*acty+actx)*512*maxplanes+plane*512+lines*8,SEEK_SET)) {
            fprintf(stderr,"FATAL: cannot seek to position while writing\n");
            exit(0);
        }

        for (chars_per_line=0;chars_per_line<64/8;chars_per_line++) {
            fputc(*buffer,outfp); buffer++;
        }
    }
}



//=============================================================================
// its a main ...
//=============================================================================
int main(int argc,char *argv[]) {
    char*          infile    = NULL;
    char*          outfile   = NULL;
    FILE*          ifp;
    FILE*          ofp;
    int            length;
    int            hcount = 1;
    int            vcount = 1;
    int            planes;
    int            nr_planes;
    int            ycount;
    int            xcount;
    unsigned char  buffer[1024];

    PRINT_ID("FixTex64");

    // check for too less arguments
    if (argc != 3 && argc != 5) {
        PrintUsage();
        return 1;
    }

    infile  = argv[1];
    outfile = argv[2];

    if (argc == 5) {
        if (sscanf(argv[3],"%d",&hcount)!=1) {
            PrintUsage();
            return 1;
        }
        if (sscanf(argv[4],"%d",&vcount)!=1) {
            PrintUsage();
            return 1;
        }
    }

    if (hcount < 1 || vcount < 1) {
        PrintUsage();
        return 1;
    }

    if (!(ifp = fopen(infile,"rb"))) {
        fprintf(stderr,"ERROR: cannot open inputfile %s\n",infile);
        PrintUsage();
        return 1;
    }

    fseek(ifp,0,SEEK_END);
    length = ftell(ifp);
    rewind(ifp);

    if (length == hcount*vcount*1024) {
        nr_planes = 2;
    }
    else if (length == hcount*vcount*512) {
        nr_planes = 1;
    }
    else {
        fprintf(stderr,"ERROR: only multiples of 64x64 images in B/W or 4 grayscales can be processed\n");
        PrintUsage();
        fclose(ifp);
        return 1;
    }

    if (!(ofp = fopen(outfile,"wb"))) {
        fprintf(stderr,"ERROR: cannot open outputfile %s\n",outfile);
        fclose(ifp);
        PrintUsage();
        return 1;
    }

    for (ycount=0;ycount<vcount;ycount++) {
        for (xcount=0;xcount<hcount;xcount++) {
            for (planes=0;planes<nr_planes;planes++) {
                FetchPlaneOfTileIntoBuffer(ifp,buffer,xcount,hcount,ycount,vcount,planes);
                ReadPlaneFromBuffer(buffer);
                WritePlaneToBuffer(buffer);
                SavePlaneOfTileFromBuffer(ofp,buffer,xcount,hcount,ycount,vcount,planes,nr_planes);
            }
        }
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

//=============================================================================
// Revision History
//=============================================================================
//
// $Log: fixtex64.c,v $
// Revision 1.2  2002/03/29 14:20:53  tnussb
// (1) support for multiple 64 tiles in one input file added
// (2) rotating to the left causes mirroring previously -> fixed now
//
// Revision 1.1  2001/03/11 19:14:51  Thomas Nussbaumer
// initial version
//
//
