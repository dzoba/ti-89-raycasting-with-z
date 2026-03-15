/******************************************************************************
*
* project name:   FAT-Engine
* file name:      tablemaker.c
* initial date:   25/02/2001
* author:         thomas.nussbaumer@gmx.net
*
* description:    generates all necessary tables
*
* NOTE: this program should be compilable with any ANSI C compiler
*
* Usage: tablemaker > tables.c
*
* $Id: tablemaker.c,v 1.7 2002/04/29 10:02:01 tnussb Exp $
*
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//-----------------------------------------------------------------------------
// just used internally
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
#define CVS_FILE_REVISION "$Revision: 1.7 $"


#define MINVAL -32767.0
#define MAXVAL 32767.0

#define MINVAL128   -127.0
#define MAXVAL128    127.0


// Define some useful angles
#define ANGLE_000     0
#define ANGLE_030     (576/(360/30))
#define ANGLE_060     (576/(360/60))
#define ANGLE_090     (ANGLE_030+ANGLE_060)
#define ANGLE_180     (ANGLE_090 << 1)
#define ANGLE_270     (ANGLE_180+ANGLE_090)
#define ANGLE_360     (ANGLE_270+ANGLE_090)

#ifndef M_PI
	#define M_PI      3.14159265358979
#endif
#define A2R(angle)    ((((double)angle)*M_PI)/(double)ANGLE_180)
#define ROUND(angle)  (long)((angle)<0 ? (angle)-.5 : (angle)+.5)

//------------------------------------------------------
// clamps a value in the range of min <= val <= max
//------------------------------------------------------
double Clamp2Range(double val,short min,short max) {
    if (val > max)      return max;
    else if (val < min) return min;

    return val;
}


#define ClampValue128(a) Clamp2Range((a),MINVAL128,MAXVAL128)


double xstep_tab(short angle) {
    double val;

    if (angle == ANGLE_000) {
        val = MAXVAL;
    }
    else if (angle == ANGLE_090) {
        val = 0.0;
    }
    else if (angle == ANGLE_180) {
        val = MINVAL;
    }
    else if (angle == ANGLE_270) {
        val = 0.0;
    }
    else {
        val = 64.0 / tan(A2R(angle));
    }

    if ( angle >= ANGLE_090 && angle < ANGLE_270 ) {
        if ( val > 0 ) val = -val;
    }
    else {
        if ( val < 0 ) val = -val;
    }
    return Clamp2Range(val,MINVAL,MAXVAL);
}


double ystep_tab(short angle) {
    double val;

    if (angle == ANGLE_000) {
        val = 0.0;
    }
    else if (angle == ANGLE_090) {
        val = MAXVAL/2;
    }
    else if (angle == ANGLE_180) {
        val = 0.0;
    }
    else if (angle == ANGLE_270) {
        val = MAXVAL/2;
    }
    else {
        val = 64.0 * tan(A2R(angle));
    }

    if ( angle >= ANGLE_000 && angle < ANGLE_180 ) {
        if ( val < 0 )  val = -val;
    }
    else {
        if ( val > 0 ) val = -val;
    }
    return Clamp2Range(val,MINVAL,MAXVAL);
}


double DivCos(int value) {
    if (value == ANGLE_090 || value == ANGLE_270) return MAXVAL;
    else return Clamp2Range(128.0/cos(A2R(value)),MINVAL,MAXVAL);
}

double DivSin(int value) {
    if (value == ANGLE_000 || value == ANGLE_180) return MAXVAL;
    else return Clamp2Range(128.0/sin(A2R(value)),MINVAL,MAXVAL);
}

double TanTable(int value) {
    if (value == ANGLE_090 || value == ANGLE_270) return MAXVAL;
    else return Clamp2Range(256.0*tan(A2R(value)),MINVAL,MAXVAL);
}

double ATanTable(int value) {
    if (value == ANGLE_000 || value == ANGLE_180) return MAXVAL;
    else return Clamp2Range(256.0/tan(A2R(value)),MINVAL,MAXVAL);
}



int main(int argc,char* argv[]) {
    int i,j;

    int max_angle = ANGLE_090;

    puts("//=============================================================================");
    puts("// this file was automatically generated with:\n//");
    PRINT_ID("TableMaker");
    puts("//=============================================================================\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// this table is used for the fisheye effect correction");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_fisheye[%d]={\n",96);
    for (i=-ANGLE_030,j=0;i<ANGLE_030;i++,j++) {
        short data = 256.0*cos(A2R(i));

        if (data > 256) data = 256;

        printf("%6d",(short)ROUND(data));
        if (i<ANGLE_030-1) {
            fputc(',',stdout);
            if (j%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 64/tan(x) - step sizes of x coordinate for horizontal intersections");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_xstep[%d]={\n",max_angle);
    for (i=0;i<max_angle;i++) {
        printf("%6d",(short)ROUND(xstep_tab(i)));
        if (i<max_angle-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 64*tan(x) - step sizes of y coordinate for vertical intersections");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_ystep[%d]={\n",max_angle);
    for (i=0;i<max_angle;i++) {
        printf("%6d",(short)ROUND(ystep_tab(i)));
        if (i<max_angle-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 128/sin(x) - used to calculate distance (also used as 128/cos(x) table)");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_div_sin[%d]={\n",max_angle);
    for (i=0;i<max_angle;i++) {
        printf("%6d",(short)ROUND(DivSin(i)));
        if (i<max_angle-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 256*tan(x) - used to calculate first vertical intersection");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_tan[%d]={\n",max_angle);
    for (i=0;i<max_angle;i++) {
        printf("%6d",(short)ROUND(TanTable(i)));
        if (i<max_angle-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 256/tan(x) - used to calculate first horizontal intersection");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_div_tan[%d]={\n",max_angle);
    for (i=0;i<max_angle;i++) {
        printf("%6d",(short)ROUND(ATanTable(i)));
        if (i<max_angle-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 16384*sin(x) - but only the first 90 degrees");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED short tab_sincos16384[%d]={\n",ANGLE_090+1);
    for (i=0;i<ANGLE_090+1;i++) {
        printf("%6d",(short)ROUND(Clamp2Range(16384.0*sin(A2R(i)),-16384,16384)));
        if (i<ANGLE_090) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");

    puts("//-----------------------------------------------------------------------------");
    puts("// 512*tan(x) - used to calculate arctangent");
    puts("//-----------------------------------------------------------------------------");
    printf("EXTERNAL_REFERENCED unsigned short tab_tan512[%d]={\n",ANGLE_090);
    for (i=0;i<ANGLE_090;i++) {
        printf("%6d", (unsigned short)ROUND(512.0*tan(A2R(i))));
        if (i<ANGLE_090-1) {
            fputc(',',stdout);
            if (i%10==9) fputc('\n',stdout);
        }
    }
    puts("};\n");


    return 0;
}

//#############################################################################
// Revision History
//#############################################################################
//
// $Log: tablemaker.c,v $
// Revision 1.7  2002/04/29 10:02:01  tnussb
// table tab_tan512 gots now attribute EXTERNAL_REFERENCED, too
//
// Revision 1.6  2002/04/17 16:37:34  tnussb
// sin table truncated to 145 entries / cos table removed
//
// Revision 1.5  2002/04/15 10:01:47  tnussb
// modifications by Scott Noveck (for example: better rounding of values)
//
// Revision 1.4  2002/03/28 12:26:38  tnussb
// timestamp in generated output removed so CVS will not get "confused" anymore
//
// Revision 1.3  2002/03/05 20:44:39  tnussb
// minor fix of comment output (additionally linebreaks removed)
//
// Revision 1.2  2002/03/01 11:06:03  tnussb
// generic commit for sourcecode release v0.81
//
// Revision 1.1  2001/03/04 20:15:30  Thomas Nussbaumer
// initial version
//
//
//
//