/******************************************************************************
*
* project name:  FAT-Engine
* file name:     texmaker.c
* initial date:  17/04/2002
* author:        thomas.nussbaumer@gmx.net
* description:   tool to convert textfiles containing FAT texture definitions
*                into FAT textures files
*
* $Id: texmaker.c,v 1.10 2002/05/22 09:30:50 tnussb Exp $
*
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//-----------------------------------------------------------------------------
// utility macros for CVS version and builddate printing
//-----------------------------------------------------------------------------
#define CVS_TRUNC_PREFIX    ((strlen((CVS_FILE_REVISION))<=11) ? 0 : (CVS_FILE_REVISION+11))
#define CVS_FIND_COMMA      (strchr(CVS_TRUNC_PREFIX,'.'))
#define CVSREV_MAIN         (int)(!(CVS_TRUNC_PREFIX) ? 0 : atoi(CVS_TRUNC_PREFIX))
#define CVSREV_SUB          (int)(!(CVS_TRUNC_PREFIX) ? 0 : (!(CVS_FIND_COMMA) ? 0 : atoi(CVS_FIND_COMMA+1)))
#define CVSREV_PRINTPARAMS  "v%d.%02d",CVSREV_MAIN,CVSREV_SUB
#define PRINT_ID(name)      fprintf(stderr,""name" ");fprintf(stderr,CVSREV_PRINTPARAMS);\
                              fprintf(stderr," - Part of FAT-Engine\n" \
                                   "(c) thomas.nussbaumer@gmx.net "__DATE__" "__TIME__"\n");
#ifdef CVS_FILE_REVISION
#undef CVS_FILE_REVISION
#endif
#define CVS_FILE_REVISION "$Revision: 1.10 $"


#define TT_MAX_OTHDATA  (65520 - 2 - 7)  // maximum number of bytes in an OTH variable


//-----------------------------------------------------------------------------
// I'm lazy. Arrays are not allocated dynamically, but statically.
//-----------------------------------------------------------------------------
#define MAX_LABELS      2048   // maximum number of labels
#define MAX_LABELSIZE   50     // maximum label size
#define MAX_STRIPS    (512*4)  // maximum number of TEXSTRIP configurations
#define MAX_GENDATA     2024   // maximum number of GENERICDATA definitions
#define MAX_BINDATA    65536   // maximum number of BINDATA bytes

// structure for a label
typedef struct {
    unsigned char name[MAX_LABELSIZE+1]; // name of label
    int           offset;                // offset of label
} LABEL_T;


// structure for a TEXSTRIP
typedef struct {
    int lightdata; // offset into BINDATA of lightplane data
    int darkdata;  // offset into BINDATA of darkplane data
    int maskdata;  // offset into BINDATA of mask data
    int mirror;    // mirror value
} TEXSTRIP;


// name of a TEXCONFIG block, if there is any supplied
typedef struct {
    unsigned char name[MAX_LABELSIZE+1];
} TEXCONFIG;


// structure for GENERICDATA
typedef struct {
    int offset;  // offset into BINDATA for GENERICDATA block
    int length;  // length of GENERICDATA block
    unsigned char name[MAX_LABELSIZE+1]; // name of GENERICDATA block, if there is any supplied
} GENDATA;


//-----------------------------------------------------------------------------
// Valid values for the mirror field of a TEXSTRIP configuration
//-----------------------------------------------------------------------------
#define FLAG_NORMAL 0   // strip should be rendered normally
#define FLAG_MIRROR 1   // strip should be rendered mirrored
#define FLAG_IGNORE 2   // strip should be ignored (not rendered)


//-----------------------------------------------------------------------------
// global arrays and counters
//-----------------------------------------------------------------------------
LABEL_T       all_labels[MAX_LABELS];     // labels array
int           used_labels  = 0;           // number of used labels
TEXSTRIP      all_texstrips[MAX_STRIPS];  // TEXSTRIP configurations array
TEXCONFIG     texconfig_names[MAX_STRIPS/4]; // name of TEXCONFIGs
int           used_strips  = 0;           // number of used TEXSTRIPs
GENDATA       all_gendata[MAX_GENDATA];   // GENERICDATA configuration array
int           used_gendata = 0;           // number of used GENERICDATAs
unsigned char bindata[MAX_BINDATA];       // BINDATA array
int           bindata_offset = 0;         // number of BINDATA bytes

int           debug = 0;                  // debug flag

//=============================================================================
// outputs usage information of this tool
//=============================================================================
void PrintUsage() {
    fprintf(stderr, "Usage: TexMaker [options] <infile> <varname> [foldername]\n\n"\
                    "       -d        ... print debug outputs\n"\
                    "       -q        ... suppress any standard message\n"\
                    "       -i <file> ... name of headerfile to generate\n\n"\
                    "       converts texmaker inputfile into FAT texture file.\n"\
                    "       NOTE: this tools generates files for the TI89 and TI92p\n"\
                    "             in one step (varname.89y/varname.9xy). The foldername\n"\
                    "             is optional (default folder: main).\n\n");
}


//=============================================================================
// returns pointer to first character which is neither a space nor a TAB
//=============================================================================
char* SkipSpacesAndTabs(char* token) {
   while (*token != 0 && (*token == ' ' || *token == '\t')) token++;
   return token;
}

//=============================================================================
// returns pointer to first character which is neither a whitespace nor a comma
//=============================================================================
char* SkipWhiteSpaces(char* token,int *skip) {
   while (*token != 0 && (*token == ' ' || *token == '\t' || *token == '\r' || *token == '\n')) {(*skip)++;token++;};
   return token;
}

//=============================================================================
// returns pointer to first character which is neither a whitespace nor a comma
//=============================================================================
char* SkipWhiteSpacesAndCommas(char* token) {
   while (*token != 0 && (*token == ' ' || *token == '\t' || *token == '\r' || *token == '\n' || *token == ',')) token++;
   return token;
}

//-----------------------------------------------------------------------------
// special values returned by ParseOffset
//-----------------------------------------------------------------------------
#define PARSE_ERROR  -100000   // error occured
#define NULL_OFFSET  -200000   // offset is a NULL offset

#define MUST_BE_EVEN 1         // tells ParseOffset that offsets must be even
#define CAN_BE_ODD   0         // tells ParseOffset that offset can be odd


#define OP_END    -1
#define OP_NOSIGN  0
#define OP_PLUS    1
#define OP_MINUS   2

//=============================================================================
//
//=============================================================================

int GetNextToken(char* source,char* dest,int* skip) {
     int ret = OP_END;

     *dest = 0;
     *skip = 0;

     source = SkipWhiteSpaces(source,skip);
     if (*source == 0) return OP_END;

     if (*source =='+') {
         ret = OP_PLUS;
         source++;
         (*skip)++;
     }
     else if (*source == '-') {
         ret = OP_MINUS;
         source++;
         (*skip)++;
     }
     else {
         ret = OP_NOSIGN;
     }

     source = SkipWhiteSpaces(source,skip);
     if (*source == 0) return OP_END;

     while (*source != 0    &&
            *source != ' '  &&
            *source != '\t' &&
            *source != '\n' &&
            *source != '\r' &&
            *source != '+'  &&
            *source != '-')
     {
        *dest = *source;
        dest++;
        source++;
        (*skip)++;
     }
     *dest = 0;
     return ret;
}


//=============================================================================
// parses an offset. an offset can consists of any number of labels and
// integers separated by '+' signs
//=============================================================================
int ParseOffset(unsigned char* buffer,int linenumber, int must_be_even) {
    int   retval = 0;
    int   i;
    int   flag;
    int   null_found = 0;
    char  tokenbuf[1024];
    int   operation;
    int   skip;
    char* token = tokenbuf;

    operation = GetNextToken(buffer,tokenbuf,&skip);
    buffer+=skip;

    while (operation != OP_END) {
        token = SkipSpacesAndTabs(token);
        if (*token) {
            //-----------------------------------------------------------------
            // check if token is an integer
            //-----------------------------------------------------------------
            if (token[0] >= '0' && token[0] <= '9')
            {
                int tmp;
                if (sscanf(token,"%d",&tmp) != 1) {
                    fprintf(stderr,"ERROR at line %d: cannot parse integer (%s)\n",linenumber,token);
                    return PARSE_ERROR;
                }
                if (operation == OP_MINUS) retval -= tmp;
                else                       retval += tmp;
            }
            else {
                // no integer -> treat it as label

                // first we remove trailing spaces and TABS ...
                char* etmp = token+strlen(token);
                while (etmp != token && (*etmp == ' ' || *etmp == '\t')) {
                    *etmp=0;
                    etmp--;
                }

                flag=0;
                for (i=0;i<used_labels;i++) {
                    if (!strcmp(token,all_labels[i].name)) {
                        if (operation == OP_MINUS) retval -= all_labels[i].offset;
                        else                       retval += all_labels[i].offset;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    // check for special "NULL"
                    if (strcmp(token,"NULL")) {
                        fprintf(stderr,"ERROR at line %d: invalid label (%s)\n",linenumber,token);
                        return PARSE_ERROR;
                    }
                    else {
                        // if "NULL" is anywhere found in an offset, the rest gets IGNORED!!
                        return NULL_OFFSET;
                    }
                }
            }
        }
        operation = GetNextToken(buffer,tokenbuf,&skip);
        buffer+=skip;
        token = tokenbuf;
    }


    //-------------------------------------------------------------------------
    // check if offset is in range
    //-------------------------------------------------------------------------
    if (retval >= bindata_offset ||retval < 0) {
        fprintf(stderr,"ERROR at line %d: offset not in range 0 ... %d (%d)\n",linenumber,bindata_offset-1,retval);
        return PARSE_ERROR;
    }

    //-------------------------------------------------------------------------
    // if wanted, check if offset is even
    //-------------------------------------------------------------------------
    if (must_be_even == MUST_BE_EVEN) {
        if (retval % 2) {
            fprintf(stderr,"ERROR at line %d: odd offset detected. GENDATA Offsets MUST be even numbers!\n",linenumber);
            return PARSE_ERROR;
        }
    }
    return retval;
}


//=============================================================================
// parses a GENERICDATA line ("GENERICDATA offset, length")
//
// the length value is treated like an offset during parsing (can contain
// any number of labels and integers separated by '+' signs)
//=============================================================================
int ParseGenericDataDefinition(unsigned char* buffer,int linenumber) {
    char* token1 = strtok(buffer,",");
    char* token2 = strtok(NULL,",");
    int   offset,length;

    //-------------------------------------------------------------------------
    // check for valid format (we need 2 tokens for offset and length)
    //-------------------------------------------------------------------------
    if (!token1 || !token2) {
        fprintf(stderr,"ERROR at line %d: invalid GENERICDATA definition\n",linenumber);
        return 0;
    }

    //-------------------------------------------------------------------------
    // parse offset
    //-------------------------------------------------------------------------
    offset = ParseOffset(token1,linenumber,CAN_BE_ODD);
    if (offset == PARSE_ERROR) return 0;
    if (offset == NULL_OFFSET) {
        fprintf(stderr,"ERROR at line %d: NULL not valid for offset of GENERICDATA definition\n",linenumber);
        return 0;
    }

    //-------------------------------------------------------------------------
    // parse length
    //-------------------------------------------------------------------------
    length = ParseOffset(token2,linenumber,CAN_BE_ODD);
    if (length == PARSE_ERROR) return 0;
    if (length == NULL_OFFSET) {
        fprintf(stderr,"ERROR at line %d: NULL not valid for length of GENERICDATA definition\n",linenumber);
        return 0;
    }

    //-------------------------------------------------------------------------
    // check if offset+length is beyond BINDATA length
    //-------------------------------------------------------------------------
    if (offset+length > bindata_offset) {
        fprintf(stderr,"ERROR at line %d: invalid GENERICDATA. Offset+Length beyond bindata length\n",linenumber);
        return 0;
    }

    //-------------------------------------------------------------------------
    // check if file contains too much GENERICDATA definitions
    //-------------------------------------------------------------------------
    if (used_gendata >= (MAX_GENDATA-1)) {
        fprintf(stderr,"ERROR at line %d: too much GENERICDATA definitions (max=%d)\n",linenumber,MAX_GENDATA);
        return 0;
    }

    //-------------------------------------------------------------------------
    // add parsed GENERICDATA definition to list
    //-------------------------------------------------------------------------
    all_gendata[used_gendata].offset = offset;
    all_gendata[used_gendata].length = length;
    used_gendata++;

    return 1;
}

//=============================================================================
// parses strip definition (STRIPn lightoffset,darkoffset,maskoffset,mirror)
//=============================================================================
int ParseStripDefinition(unsigned char* buffer,int linenumber) {
    int   token_nr = 0;
    int   val;
    int   i;
    char* tokenlist[4];
    char* token;

    //---------------------------------------------------------------------
    // check if maximum number of strip configs reached
    //---------------------------------------------------------------------
    if (used_strips >= MAX_STRIPS) {
        fprintf(stderr,"ERROR at line %d: too much TEXCONFIGs (max: %d)\n",linenumber,MAX_STRIPS/4);
        return 0;
    }

    //-------------------------------------------------------------------------
    // fetch all four required tokens
    //-------------------------------------------------------------------------
    tokenlist[0] = strtok(buffer,",");
    for (i=1;i<4;i++) tokenlist[i] = strtok(NULL,",");
    token = tokenlist[0];

    //-------------------------------------------------------------------------
    // loop through all four tokens and try to parse them
    //-------------------------------------------------------------------------
    while (token && token_nr < 4) {
        if (token_nr == 0) token+=6; // skip STRIPn
        token = SkipSpacesAndTabs(token);

        // empty token? very bad ...
        if (!*token) {
            fprintf(stderr,"ERROR at line %d: empty field found at position %d\n",linenumber,token_nr+1);
            return 0;
        }

        //---------------------------------------------------------------------
        // treatment of lightdata offset
        //---------------------------------------------------------------------
        if (token_nr == 0) {
            val = ParseOffset(token,linenumber,MUST_BE_EVEN);
            if (val == PARSE_ERROR) {
                fprintf(stderr,"ERROR at line %d: parsing lightdata offset failed\n",linenumber);
                return 0;
            }
            all_texstrips[used_strips].lightdata = val;
        }
        //---------------------------------------------------------------------
        // treatment of darkdata offset
        //---------------------------------------------------------------------
        else if (token_nr == 1) {
            val = ParseOffset(token,linenumber,MUST_BE_EVEN);
            if (val == PARSE_ERROR) {
                fprintf(stderr,"ERROR at line %d: parsing darkdata offset failed\n",linenumber);
                return 0;
            }
            all_texstrips[used_strips].darkdata = val;
        }
        //---------------------------------------------------------------------
        // treatment of maskdata offset
        //---------------------------------------------------------------------
        else if (token_nr == 2) {
            val = ParseOffset(token,linenumber,MUST_BE_EVEN);
            if (val == PARSE_ERROR) {
                fprintf(stderr,"ERROR at line %d: parsing maskdata offset failed\n",linenumber);
                return 0;
            }
            all_texstrips[used_strips].maskdata = val;
        }
        //---------------------------------------------------------------------
        // treatment of mirror field (NORMAL,MIRROR and IGNORE are valid)
        //---------------------------------------------------------------------
        else {
            if (!strncmp(token,"NORMAL",6)) {
                all_texstrips[used_strips].mirror = FLAG_NORMAL;
            }
            else if (!strncmp(token,"MIRROR",6)) {
                all_texstrips[used_strips].mirror = FLAG_MIRROR;
            }
            else if (!strncmp(token,"IGNORE",6)) {
                all_texstrips[used_strips].mirror = FLAG_IGNORE;
            }
            else {
                fprintf(stderr,"ERROR at line %d: mirror value neither NORMAL nor MIRROR, nor IGNORE\n",linenumber);
                return 0;
            }
        }
        token_nr++;
        token = tokenlist[token_nr];
    }

    if (token_nr != 4) {
        fprintf(stderr,"ERROR at line %d: invalid strip line (not enough fields)\n",linenumber);
        return 0;
    }

    used_strips++;
    return 1;
}


//=============================================================================
// returns hexvalue of given characters
//=============================================================================
unsigned char Hex2Byte(unsigned char up,unsigned char low) {
    unsigned char c;

    if (up>='0' && up<='9')      c = (up-'0')<<4;
    else if (up>='A' && up<='F') c = (up-'A'+10)<<4;
    else                         c = (up-'a'+10)<<4;

    if (low>='0' && low<='9')      c += (low-'0');
    else if (low>='A' && low<='F') c += (low-'A'+10);
    else                           c += (low-'a'+10);

    return c;
}


//=============================================================================
// returns hexvalue of given characters
//=============================================================================
unsigned char Bin2Byte(unsigned char* in) {
    int i;
    unsigned char result=0;

    if (*in     == '1') result += 128;
    if (*(in+1) == '1') result +=  64;
    if (*(in+2) == '1') result +=  32;
    if (*(in+3) == '1') result +=  16;
    if (*(in+4) == '1') result +=   8;
    if (*(in+5) == '1') result +=   4;
    if (*(in+6) == '1') result +=   2;
    if (*(in+7) == '1') result +=   1;

    return result;
}

//-----------------------------------------------------------------------------
// utility macros to check if given character is a hex/binary character
//-----------------------------------------------------------------------------
#define ISHEX(c) (((c)>='0' && (c)<='9') || ((c)>='a' && (c)<='f') || ((c)>='A' && (c)<='F'))
#define ISBIN(c) ((c)=='0' || (c)=='1')


//=============================================================================
// parses a string from the BINDATA
//
// Strings must start with a doublequote (") must end with a doublequote (").
// To embed a double quote within a string use (\"). Other treated combinations
// are "\n", "\t", "\\","\"" and "\xhh" where hh are hexdigits. At the end of a
// String a 0-byte is automatically appended.
//
// returns 1 if successfully parsed or 0 if there was an error
//=============================================================================
char* ParseString(char* token,int linenumber) {
     int slash = 0;

     if (!*token || *token != '"') {
         fprintf(stderr,"ERROR at line %d: string doesn't start with a doublequote\n",linenumber);
         return NULL;
     }
     token++;


     while (1) {
        if (!*token) {
            fprintf(stderr,"ERROR at line %d: unexpected end of line in string\n",linenumber);
            return NULL;
        }
        if (slash) {
            if (*token=='n') {
                bindata[bindata_offset++] = '\n';
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                token++;
                continue;
            }

            if (*token=='t') {
                bindata[bindata_offset++] = '\t';
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                token++;
                continue;
            }

            if (*token=='0') {
                bindata[bindata_offset++] = 0;
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                token++;
                continue;
            }

            if (*token=='\\') {
                bindata[bindata_offset++] = '\\';
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                token++;
                continue;
            }

            if (*token=='"') {
                bindata[bindata_offset++] = '"';
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                token++;
                continue;
            }

            if (*token=='x' || *token=='X') {
                unsigned char v1,v2;
                token++;
                if (!*token) {fprintf(stderr,"ERROR at line %d: unexpected end of line in string\n",linenumber); return NULL;}
                v1 = *token++;
                if (!*token) {fprintf(stderr,"ERROR at line %d: unexpected end of line in string\n",linenumber); return NULL;}
                v2 = *token++;
                if (!ISHEX(v1) || !ISHEX(v2)) {
                    fprintf(stderr,"ERROR at line %d: invalid hex escape sequence (\\x%c%c)\n",linenumber,v1,v2);
                    return 0;
                }

                //printf("hex escape sequence (\\x%c%c)\n",v1,v2);

                bindata[bindata_offset++] = Hex2Byte(v1,v2);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
                slash=0;
                continue;
            }

            fprintf(stderr,"ERROR at line %d: unexpected escape sequence (\\%c)",linenumber,*token);
            return 0;
        }

        // found a "\" ... -> set flag and continue
        if (*token == '\\') {
            slash = 1;
            token++;
            continue;
        }

        // check for end of string
        if (*token == '"') {
            bindata[bindata_offset++] = 0;
            if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return NULL;}
            return token+1;
        }

        bindata[bindata_offset++] = *token++;
    }

    return token; // we will never come here ... just to make the compiler happy
}

//=============================================================================
// parses a bindata line (data values separated by commas, spaces are ignored)
//
// valid formats:
//
// 0xhh                               (2-digit hexnumber - h = 0-f)
// 0xhhhh                             (4-digit hexnumber - h = 0-f)
// 0xhhhhhhhh                         (8-digit hexnumber - h = 0-f)
// 0bdddddddd                         (8-digit binary number - d = 0/1)
// 0bdddddddddddddddd                 (16-digit binary number - d = 0/1)
// 0bdddddddddddddddddddddddddddddddd (32-digit binary number - d = 0/1)
//
//=============================================================================
int ParseBinDataLine(unsigned char* buffer,int linenumber) {
    char* token = buffer;

    while (token) {
        token = SkipWhiteSpacesAndCommas(token);
        if (!*token) return 1;

        //---------------------------------------------------------------------
        // looks like the start of a string ...
        //---------------------------------------------------------------------
        if (*token == '"') {
            if (!(token = ParseString(token,linenumber))) return 0;
            continue;
        }

        //---------------------------------------------------------------------
        // hexcode treatment (2/4/8 digits)
        //---------------------------------------------------------------------
        else if (*token=='0' && *(token+1)=='x') {
            int count = 0;
            while (ISHEX(token[2+count])) count++;
            if (count == 2) {
                bindata[bindata_offset++] = Hex2Byte(token[2],token[3]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=4;
            }
            if (count == 4) {
                bindata[bindata_offset++] = Hex2Byte(token[2],token[3]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Hex2Byte(token[4],token[5]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=6;
            }
            else if (count == 8) {
                bindata[bindata_offset++] = Hex2Byte(token[2],token[3]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Hex2Byte(token[4],token[5]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Hex2Byte(token[6],token[7]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Hex2Byte(token[8],token[9]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=10;
            }
            else {
                fprintf(stderr,"ERROR at line %d: invalid hexcode length (%d) - only 2, 4 and 8 digits are supported\n",linenumber,count);
                return 0;
            }
        }
        //---------------------------------------------------------------------
        // binary number treatment  (8/16/32 digits)
        //---------------------------------------------------------------------
        else if (*token=='0' && *(token+1)=='b') {
            int count = 0;
            while (ISBIN(token[2+count])) count++;
            if (count == 8) {
                bindata[bindata_offset++] = Bin2Byte(&token[2]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=10;
            }
            else if (count == 16) {
                bindata[bindata_offset++] = Bin2Byte(&token[2]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Bin2Byte(&token[2+8]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=18;
            }
            else if (count == 32) {
                bindata[bindata_offset++] = Bin2Byte(&token[2]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Bin2Byte(&token[2+8]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Bin2Byte(&token[2+16]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                bindata[bindata_offset++] = Bin2Byte(&token[2+24]);
                if (bindata_offset>=MAX_BINDATA) {fprintf(stderr,"ERROR at line %d: too much BINDATA (>65535)\n",linenumber); return 0;}
                token+=34;
            }
            else {
                fprintf(stderr,"ERROR at line %d: invalid bincode length (%d) - only 8, 16 and 32 digits are supported\n",linenumber,count);
                return 0;
            }
        }
        //---------------------------------------------------------------------
        // SORRY - that value is unparseable!
        //---------------------------------------------------------------------
        else {
            fprintf(stderr,"ERROR at line %d: unparseable BINDATA value (value=%s)\n",linenumber,token);
            return 0;
        }
    }

    return 1;
}


#define CALC_TI89    0
#define CALC_TI92P   1
#define DEFAULT_FOLDER   "main"
unsigned char* GenerateOutput(int calctype,char* folder,char* varname,unsigned int*  outlen);


//=============================================================================
// its a main ...
//=============================================================================
int main(int argc,char *argv[]) {
    FILE*          ifp;
    FILE*          ofp;
    char           buffer[1024];
    char*          headerfile = NULL;
    char*          ifn        = NULL;
    char*          varname    = NULL;
    char*          folder     = NULL;
    int            bindata_line;
    int            line;
    int            flag;
    int            stripcount;
    unsigned char* outbuf;
    unsigned int   outlen;
    int            n;
    int            quiet = 0;
    int            parse_genericdata = 0;

    // parse arguments
    for (n=1; n<argc; n++) {
        if (!strcmp(argv[n], "-d"))      debug   = 1;
        else if (!strcmp(argv[n], "-q")) quiet   = 1;
        else if (!strcmp(argv[n], "-i")) {
            if (n == argc -1) {
                PrintUsage();
                return 1;
            }
            else {
                n++;
                headerfile = argv[n];
            }
        }
        else if (!ifn)     ifn     = argv[n];
        else if (!varname) varname = argv[n];
        else if (!folder)  folder  = argv[n];
        else {
            PrintUsage();
            return 1;
        }
    }

    if (folder == NULL) folder = DEFAULT_FOLDER;

    if (!varname || !ifn) {
        PrintUsage();
        return 1;
    }

    if (quiet) debug = 0;

    if (!quiet) {
        PRINT_ID("TexMaker");
    }


    //-------------------------------------------------------------------------
    // open input file
    //-------------------------------------------------------------------------
    if (!(ifp = fopen(ifn,"r"))) {
        fprintf(stderr,"ERROR: cannot open inputfile %s\n",ifn);
        return 1;
    }

    //-------------------------------------------------------------------------
    // try to find the bindata block (we have to parse the labels first)
    //-------------------------------------------------------------------------
    bindata_line = 0;
    line = 0;
    flag = 0;
    while (1) {
        if (!fgets(buffer, 1023,ifp)) break;
        bindata_line++;
        line++;
        if (!strncmp(buffer,"BINDATA",6)) {
            if (debug) printf("[DBG] BINDATA starting at line %d\n",bindata_line);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        fprintf(stderr,"ERROR: cannot find tag BINDATA on a single line\n");
        fclose(ifp);
        return 1;
    }

    //-------------------------------------------------------------------------
    // read in all bindata and parse all labels
    //-------------------------------------------------------------------------
    bindata_offset = 0;
    while (1) {
        if (!fgets(buffer, 1023,ifp)) break;
        line++;
        // skip comment lines
        if ((buffer[0] == '/' && buffer[1] == '/') || buffer[0] == '#') continue;

        if (!strncmp(buffer,"LABEL ",6)) {
            // parse a label
            char label[1024];
            int  i = 0;
            int  len;

            while (buffer[i+6] != 0    && buffer[i+6] != ' '  &&
                   buffer[i+6] != '\t' && buffer[i+6] != '\r' &&
                   buffer[i+6] != '\n' && buffer[i+6] != 0)
            {
                label[i] = buffer[i+6];
                i++;
            }
            label[i] = 0;
            if (debug) printf("[DBG] label=[%s] offset=[%d]\n",label,bindata_offset);

            // check for valid label length
            len = strlen(label);
            if (len == 0 || len > MAX_LABELSIZE) {
                fprintf(stderr,"ERROR at line %d: cannot handle labels of length %d (min=1/max=%d)\n",line,len,MAX_LABELSIZE);
                fclose(ifp);
                return 1;
            }

            // check for maximum number of labels
            if (used_labels==MAX_LABELS-1) {
                fprintf(stderr,"ERROR at line %d: cannot handle more than %d labels\n",line,MAX_LABELS);
                fclose(ifp);
                return 1;
            }

            // check for a duplicate label
            for (i=0;i<used_labels;i++) {
                if (!strcmp(label,all_labels[i].name)) {
                     fprintf(stderr,"ERROR at line %d: duplicate label (%s) found\n",line,label);
                     fclose(ifp);
                     return 1;
                }
            }

            // at label data to label list
            strcpy(all_labels[used_labels].name,label);
            all_labels[used_labels].offset = bindata_offset;
            used_labels++;
        }
        else {
            // parse a dataline
            if (!ParseBinDataLine(buffer,line)) {
                fclose(ifp);
                return 1;
            }
        }
    }

    //-------------------------------------------------------------------------
    // go back and parse now the TEXCONFIGs and GENERICDATA setups
    //-------------------------------------------------------------------------
    rewind(ifp);
    stripcount = -1;
    for (line = 1; line < bindata_line; line++) {
        fgets(buffer, 1023,ifp); // no EOF checking, because these lines ARE available!

        // skip comment lines
        if ((buffer[0] == '/' && buffer[1] == '/') || buffer[0] == '#') continue;

        if (!strncmp(buffer,"TEXCONFIG",9)) {
            if (stripcount!=-1) {
                fprintf(stderr,"ERROR at line %d: start of new TEXCONFIG without completing old one!\n",line);
                fclose(ifp);
                return 1;
            }
            stripcount=0;

            {
                char* name = &(buffer[10]);
                while (*name != 0 && (*name == ' '  || *name == '\t')) name++;
                if (*name == 0 || *name == '\r' ||  *name == '\n') {
                    texconfig_names[used_strips/4].name[0] = 0;
                }
                else {
                    char tmpbuffer[1024];
                    int  i_idx = 0;

                    while (*name && *name != ' ' && *name != '\t' && *name != '\r' && *name != '\n') {
                        tmpbuffer[i_idx++] = *name++;
                    }
                    tmpbuffer[i_idx] = 0;

                    if (strlen(tmpbuffer)>MAX_LABELSIZE) {
                        fprintf(stderr,"ERROR at line %d: TEXCONFIG name longer than %d\n",line,MAX_LABELSIZE);
                        fclose(ifp);
                        return 1;
                    }
                    else if (strlen(tmpbuffer)>0) {
                        strcpy(texconfig_names[used_strips/4].name,tmpbuffer);
                    }
                }
            }

            if (debug) {
                if (texconfig_names[used_strips/4].name[0]) {
                    printf("[DBG] TEXCONFIG with name [%s] found at line %d\n",texconfig_names[used_strips/4].name,line);
                }
                else {
                    printf("[DBG] TEXCONFIG found at line %d\n",line);
                }
            }
            continue;
        }
        else if (stripcount != -1) {
            if (!strncmp(buffer,"STRIP",5) && (buffer[5] == ('1'+stripcount))) {
                if (!ParseStripDefinition(buffer,line)) {
                    fclose(ifp);
                    return 1;
                }
                stripcount++;

                if (debug) {
                  int val = all_texstrips[used_strips-1].lightdata;
                  printf("[DBG] STRIP%d: light=",stripcount);
                  if (val == NULL_OFFSET) printf("NULL");
                  else                    printf("%d",val);
                  val = all_texstrips[used_strips-1].darkdata;
                  printf(" dark=");
                  if (val == NULL_OFFSET) printf("NULL");
                  else                    printf("%d",val);
                  val = all_texstrips[used_strips-1].maskdata;
                  printf(" mask=");
                  if (val == NULL_OFFSET) printf("NULL");
                  else                    printf("%d",val);
                  val = all_texstrips[used_strips-1].mirror;
                  if (val == FLAG_NORMAL)      printf(" mirror=NORMAL\n");
                  else if (val == FLAG_MIRROR) printf(" mirror=MIRROR\n");
                  else                         printf(" mirror=IGNORE\n");
                }

                if (stripcount == 4) stripcount = -1;

                continue;
            }
            else {
                fprintf(stderr,"ERROR at line %d: missing or invalid STRIPx tag\n",line);
                fclose(ifp);
                return 1;
            }
        }
        else {
            if (parse_genericdata) {
                if (!ParseGenericDataDefinition(buffer,line)) {
                    fclose(ifp);
                    return 1;
                }
                if (debug) printf("[DBG] offset=%d length=%d\n",all_gendata[used_gendata-1].offset,all_gendata[used_gendata-1].length);
                parse_genericdata = 0;
            }
            else if (!strncmp(buffer,"GENERICDATA",11)) {
                char* name = &(buffer[12]);
                while (*name != 0 && (*name == ' '  || *name == '\t')) name++;
                if (*name == 0 || *name == '\r' ||  *name == '\n') {
                    all_gendata[used_gendata].name[0] = 0;
                }
                else {
                    char tmpbuffer[1024];
                    int  i_idx = 0;

                    while (*name && *name != ' ' && *name != '\t' && *name != '\r' && *name != '\n' && *name != ',') {
                        tmpbuffer[i_idx++] = *name++;
                    }
                    tmpbuffer[i_idx] = 0;

                    if (strlen(tmpbuffer)>MAX_LABELSIZE) {
                        fprintf(stderr,"ERROR at line %d: TEXCONFIG name longer than %d\n",line,MAX_LABELSIZE);
                        fclose(ifp);
                        return 1;
                    }
                    else if (strlen(tmpbuffer)>0) {
                        strcpy(all_gendata[used_gendata].name,tmpbuffer);
                    }
                }

                if (debug) {
                    if (all_gendata[used_gendata].name[0]) {
                        printf("[DBG] GENERICDATA with name [%s] found at line %d\n",all_gendata[used_gendata].name,line);
                    }
                    else {
                        printf("[DBG] GENERICDATA found at line %d\n",line);
                    }
                }

                parse_genericdata = 1;
                continue;
            }
            else {
                int j;
                for (j=0;j<strlen(buffer);j++) {
                    if (buffer[j] != ' ' && buffer[j] != '\t' && buffer[j] != '\n' && buffer[j] != '\r') {
                        fprintf(stderr,"ERROR at line %d: unexpected character (%c) found\n",line,buffer[j]);
                        fclose(ifp);
                        return 1;
                    }
                }
            }
        }
    }

    //-------------------------------------------------------------------------
    // everything read - print some results
    //-------------------------------------------------------------------------
    fclose(ifp);
    if (!quiet) {
        printf("bindata length       = %d\n",bindata_offset);
        printf("labels parsed        = %d\n",used_labels);
        printf("texconfig's parsed   = %d\n",used_strips/4);
        printf("genericdata's parsed = %d\n",used_gendata);
        printf("complete data size   = %d\n",used_strips * 14 + used_gendata * 4 + 4 + 4 + bindata_offset);
    }

    //-------------------------------------------------------------------------
    // write TI89 file
    //-------------------------------------------------------------------------
    if (!(outbuf = GenerateOutput(CALC_TI89,folder,varname,&outlen))) return 1;
    sprintf(buffer,"%s.89y",varname);
    if (!(ofp = fopen(buffer,"wb"))) {
        fprintf(stderr,"ERROR: cannot open outputfile %s\n",buffer);
        free(outbuf);
        return 1;
    }
    if (fwrite(outbuf,outlen,1,ofp) != 1) {
        fprintf(stderr,"ERROR: writing of outputfile %s failed\n",buffer);
        fclose(ofp);
        free(outbuf);
        return 1;
    }

    fclose(ofp);
    free(outbuf);
    if (!quiet) printf("%u bytes successfully written to %s\n",outlen,buffer);

    //-------------------------------------------------------------------------
    // write TI92p file
    //-------------------------------------------------------------------------
    if (!(outbuf = GenerateOutput(CALC_TI92P,folder,varname,&outlen))) return 1;
    sprintf(buffer,"%s.9xy",varname);
    if (!(ofp = fopen(buffer,"wb"))) {
        fprintf(stderr,"ERROR: cannot open outputfile %s\n",buffer);
        free(outbuf);
        return 1;
    }
    if (fwrite(outbuf,outlen,1,ofp) != 1) {
        fprintf(stderr,"ERROR: writing of outputfile %s failed\n",buffer);
        fclose(ofp);
        free(outbuf);
        return 1;
    }
    fclose(ofp);
    free(outbuf);
    if (!quiet) printf("%u bytes successfully written to %s\n",outlen,buffer);

    if (headerfile) {
        int t_lines = 0;
        int g_lines = 0;
        if (!(ofp = fopen(headerfile,"w"))) {
            fprintf(stderr,"ERROR: cannot open headerfile %s for writing\n",headerfile);
            return 1;
        }

        fprintf(ofp,"/* generated automatically by TexMaker ");
        fprintf(ofp,CVSREV_PRINTPARAMS);
        fprintf(ofp," - Part of FAT-Engine (c) thomas.nussbaumer@gmx.net */\n\n");

        for (n=0;n<used_strips/4;n++) {
            if (texconfig_names[n].name[0]) {
                if (!t_lines) fputs("\n/* TEXCONFIG indices */\n\n",ofp);
                fprintf(ofp,"#define %-50s %d\n",texconfig_names[n].name,n);
                t_lines++;
            }
        }

        for (n=0;n<used_gendata;n++) {
            if (all_gendata[n].name[0]) {
                if (!g_lines) fputs("\n/* GENERICDATA indices */\n\n",ofp);
                fprintf(ofp,"#define %-50s %d\n",all_gendata[n].name,n);
                g_lines++;
            }
        }

        if (t_lines == 0 && g_lines == 0) {
            fprintf(ofp,"\n/* no names for TEXCONFIGs and GENERICDATAs defined in %s */\n\n",ifn);
        }
        else {
            fputs("\n",ofp);
        }

        fclose(ofp);
        if (!quiet) printf("headerfile %s generated\n",headerfile);
    }



    //-------------------------------------------------------------------------
    // over and out - nice to meet you ;-)
    //-------------------------------------------------------------------------
    return 0;
}

//#############################################################################
// the following block is copied from the TIGCC Tools Suite
// it handles the writing of an OTH file
//#############################################################################

#define CALC_TI89    0
#define CALC_TI92P   1
#define DEFAULT_FOLDER   "main"

#define SIGNATURE_TI89   "**TI89**"
#define SIGNATURE_TI92P  "**TI92P*"


typedef struct {
    char          signature[8]; // "**TI92P*" or "**TI89**"
    unsigned char fill1[2];     // 01 00
    char          folder[8];    // folder name
    char          desc[40];     // ---- not used ----
    unsigned char fill2[6];     // 01 00 52 00 00 00
    char          name[8];      // varname
    unsigned char type[4];      // 0C 00 00 00
    unsigned char size[4];      // complete file size (including checksum)
    unsigned char fill3[6];     // A5 5A 00 00 00 00
    unsigned char datasize[2];  // data size
}
StrHeader;


//=============================================================================
// returns a pointer to a newly allocated memory block which holds the
// OTH file contents ready to flush into a file
//
// the length of the newly allocated memory block will be stored in outlength
//
// NOTE: the length of the extension may vary between 1 and 4 characters
//       (no checks are performed on the type of the character)
//=============================================================================
unsigned char* DataBuffer2OTHBuffer(int            calctype,
                                    char*          folder,
                                    char*          varname,
                                    unsigned int   inlength,
                                    unsigned char* indata,
                                    unsigned int*  outlength)
{
    StrHeader*     psh;
    unsigned int   checksum;
    unsigned char* ptr;
    unsigned int   size;
    unsigned char* output;
    int            ext_len   = 4;
    char*          extension = "ftex";

    if (inlength > TT_MAX_OTHDATA) {
        fprintf(stderr,"ERROR: length (%u) exceeds max. user data size (%u)\n",inlength,TT_MAX_OTHDATA);
        return 0;
    }

    size = sizeof(StrHeader)+inlength+2+3+ext_len; // 6 == OTH bytes , 2 == checksum

    if (!(output = (unsigned char*)malloc(size))) {
        fprintf(stderr,"ERROR: cannot allocate %u bytes of memory\n",size);
        return 0;
    }

    *outlength = size;
    psh = (StrHeader*)output;
    memset(psh,0,sizeof(StrHeader));

    //-------------------------------------------------------------------
    // fill up all the static fields
    //-------------------------------------------------------------------
    psh->fill1[0]=1;psh->fill1[1]=0;
    psh->fill2[0]=0x01;psh->fill2[1]=0x00;psh->fill2[2]=0x52;
    psh->fill2[3]=0x00;psh->fill2[4]=0x00;psh->fill2[5]=0x00;
    psh->fill3[0]=0xA5;psh->fill3[1]=0x5A;psh->fill3[2]=0x00;
    psh->fill3[3]=0x00;psh->fill3[4]=0x00;psh->fill3[5]=0x00;
    psh->type[0]=0x1c;psh->type[1]=0x00;psh->type[2]=0x00;psh->type[3]=0x00;

    //-------------------------------------------------------------------
    // fill in the magic marker string depending on given calc type
    //-------------------------------------------------------------------
    if (calctype == CALC_TI89) strncpy(psh->signature,SIGNATURE_TI89,8);
    else                       strncpy(psh->signature,SIGNATURE_TI92P,8);

    //-------------------------------------------------------------------
    // fill in folder and variable name
    // if folder name pointer is NULL, use DEFAULT_FOLDER ("main")
    //-------------------------------------------------------------------
    if (!folder) strncpy(psh->folder,DEFAULT_FOLDER,8);
    else         strncpy(psh->folder,folder,8);

    strncpy(psh->name,varname,8);

    //-------------------------------------------------------------------
    // size holds the complete output size == filelength including header
    //-------------------------------------------------------------------
    psh->size[0] = (unsigned char)(size & 0xff);
    psh->size[1] = (unsigned char)((size >> 8)  & 0xff);
    psh->size[2] = (unsigned char)((size >> 16) & 0xff);
    psh->size[3] = (unsigned char)((size >> 24) & 0xff);

    //-------------------------------------------------------------------
    // data size will hold user data size + OTH tag related bytes
    //-------------------------------------------------------------------
    size -= sizeof(StrHeader);
    size -= 2;
    psh->datasize[0] = (unsigned char)((size >> 8) & 0xff);
    psh->datasize[1] = (unsigned char)(size & 0xff);

    //-------------------------------------------------------------------
    // copy complete indata
    //-------------------------------------------------------------------
    memcpy(output + sizeof(StrHeader),indata,inlength);

    //-------------------------------------------------------------------
    // append OTH bytes
    //-------------------------------------------------------------------
    ptr    = output + sizeof(StrHeader) + inlength;
    *ptr++ = 0;

    switch (ext_len) {
        case 1:
            *ptr++ = *extension;
            *ptr++ = 0;
            break;
        case 2:
            *ptr++ = *extension++;
            *ptr++ = *extension;
            *ptr++ = 0;
            break;
        case 3:
            *ptr++ = *extension++;
            *ptr++ = *extension++;
            *ptr++ = *extension;
            *ptr++ = 0;
            break;
        case 4:
            *ptr++ = *extension++;
            *ptr++ = *extension++;
            *ptr++ = *extension++;
            *ptr++ = *extension;
            *ptr++ = 0;
            break;
    }
    *ptr++ = 0xF8;

    size = *outlength - sizeof(StrHeader);
    ptr  = psh->datasize;

    checksum = 0;
    while (size--) checksum += *ptr++;

    output[*outlength-2] = (unsigned char)(checksum & 0xff);
    output[*outlength-1] = (unsigned char)((checksum >> 8) & 0xff);

    return output;
}

//=============================================================================
// returns allocated buffer which contains finally OTH type variable
//=============================================================================
unsigned char* GenerateOutput(int calctype,char* folder,char* varname,unsigned int*  outlen) {
    unsigned char ob[65536];
    int ptr = 0;
    int i;
    int offset_to_add;


    int size = used_strips * 14 + used_gendata * 4 + 4 + 4 + bindata_offset;

    if (size>TT_MAX_OTHDATA) {
        fprintf(stderr,"ERROR: output will not fit into OTH variable (maxsize=%d)\n",TT_MAX_OTHDATA);
        return NULL;
    }

    // write magic
    ob[ptr++] = 0x46;
    ob[ptr++] = 0x54;
    ob[ptr++] = 0x58;
    ob[ptr++] = 0x30;

    // write number of texconfig's
    i = used_strips/4;
    ob[ptr++] = (i >> 8) & 0xff;
    ob[ptr++] = i & 0xff;

    // write number of genericdata's
    ob[ptr++] = (used_gendata >> 8) & 0xff;
    ob[ptr++] = used_gendata & 0xff;

    offset_to_add = 4+2+2+14*used_strips+4*used_gendata;

    // write strip lines
    for (i=0;i<used_strips;i++) {
        int data = all_texstrips[i].lightdata;
        if (data == NULL_OFFSET) data=0;
        else                     data+=offset_to_add;

        ob[ptr++]=0;
        ob[ptr++]=0;
        ob[ptr++]=(data >> 8) & 0xff;
        ob[ptr++]=data & 0xff;

        data = all_texstrips[i].darkdata;
        if (data == NULL_OFFSET) data=0;
        else                     data+=offset_to_add;

        ob[ptr++]=0;
        ob[ptr++]=0;
        ob[ptr++]=(data >> 8) & 0xff;
        ob[ptr++]=data & 0xff;

        data = all_texstrips[i].maskdata;
        if (data == NULL_OFFSET) data=0;
        else                     data+=offset_to_add;

        ob[ptr++]=0;
        ob[ptr++]=0;
        ob[ptr++]=(data >> 8) & 0xff;
        ob[ptr++]=data & 0xff;

        data = all_texstrips[i].mirror;

        ob[ptr++] = (data >> 8) & 0xff;
        ob[ptr++] = data & 0xff;
    }

    // write genericdata lines
    for (i=0;i<used_gendata;i++) {
        int offset = all_gendata[i].offset + offset_to_add;
        ob[ptr++] = (offset >> 8) & 0xff;
        ob[ptr++] = offset & 0xff;
        ob[ptr++] = (all_gendata[i].length >> 8) & 0xff;
        ob[ptr++] = all_gendata[i].length & 0xff;
    }

    // write bindata
    memcpy(&ob[ptr],bindata,bindata_offset);

    return DataBuffer2OTHBuffer(calctype,folder,varname,size,ob,outlen);
}






//=============================================================================
// Revision History
//=============================================================================
//
// $Log: texmaker.c,v $
// Revision 1.10  2002/05/22 09:30:50  tnussb
// fixed TT_MAX_OTHDATA and header of OTH file (thanx to Sebastian Reichelt)
//
// Revision 1.9  2002/05/03 11:37:52  tnussb
// bug fix which had produced corrupted TI92p GENERICDATA offsets
//
// Revision 1.8  2002/04/30 17:39:20  tnussb
// (1) handling of names for GENERICDATA and TEXCONFIG added
// (2) commandline parameter -i functionality (headerfile generation) added
//
// Revision 1.7  2002/04/19 15:19:39  tnussb
// now also the "-" sign can be used in offset calculations
//
// Revision 1.6  2002/04/19 14:09:27  tnussb
// (1) BINDATA values can now be 2-digit hexnumbers, binary numbers or strings
// (2) texmaker generates now automatically OTH files for the TI89 and the TI92p
// (3) debugging can be turned on with commandline switch
// (4) -q commandline flag added to suppress any standard message
//
// Revision 1.5  2002/04/18 20:23:28  tnussb
// support for GENERICDATA blocks added
//
// Revision 1.4  2002/04/18 15:46:39  tnussb
// checking now for odd offsets (all offsets have to be even numbers!)
//
// Revision 1.3  2002/04/18 12:18:37  tnussb
// debug mode turned off
//
// Revision 1.2  2002/04/17 16:48:10  tnussb
// converter works now as wanted
//
// Revision 1.1  2002/04/17 14:05:27  tnussb
// initial version
//
//
