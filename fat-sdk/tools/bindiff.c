/******************************************************************************
*
* project name:  FAT-Engine
* file name:     bindiff.c
* initial date:  03/05/2002
* author:        thomas.nussbaumer@gmx.net
* description:   tool to compare binary files
*
* $Id: bindiff.c,v 1.1 2002/05/03 11:38:44 tnussb Exp $
*
******************************************************************************/
#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* fp1;
    FILE* fp2;
    int   val1;
    int   val2;
    long  count = 0;

    if (argc != 3) {
        printf("usage: bindiff file1 file2\n");
        return 1;
    }

    if (!(fp1 = fopen(argv[1],"rb"))) {
        printf("usage: bindiff file1 file2\n");
        return 1;
    }

    if (!(fp2 = fopen(argv[2],"rb"))) {
        printf("usage: bindiff file1 file2\n");
        fclose(fp1);
        return 1;
    }

    do {
        val1 = fgetc(fp1);
        val2 = fgetc(fp2);

        if (val1 == EOF || val2 == EOF) {
            if (val1 != val2) {
                if (val1==EOF) {
                    printf("%s shorter than %s\n",argv[1],argv[2]);
                }
                else {
                    printf("%s shorter than %s\n",argv[1],argv[2]);
                }
            }
        }
        else if (val1 != val2) {
            printf("pos[0x%08lX]: 0x%02X != 0x%02X\n",count,val1,val2);
        }
        count++;
    }
    while (val1 != EOF && val2 != EOF);

    fclose(fp1);
    fclose(fp2);
    return 0;
}

//=============================================================================
// Revision History
//=============================================================================
//
// $Log: bindiff.c,v $
// Revision 1.1  2002/05/03 11:38:44  tnussb
// initial version (I haven't found such a tool on my computer and I was too
// lazy to search for it)
//
//
