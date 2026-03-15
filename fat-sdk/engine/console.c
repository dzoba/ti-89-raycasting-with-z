/******************************************************************************
*
* project name:  FAT-Engine
* file name:     console.c
* initial date:  25/04/2002
* author:        thomas.nussbaumer@gmx.net
* description:   debug console handling
*
******************************************************************************/

//-----------------------------------------------------------------------------
// if the FAT-Engine gets compiled without integrated debugging console
// calls the FAT_DebugConsole() will call a "DO-NOTHING" function
//-----------------------------------------------------------------------------
#if !defined(FAT_WITHCONSOLE)

#define ACTIVATE_CONSOLE_IF_WANTED(f)
#define SIZE_MEMCONSOLE 0

void DebugConsole(FATCONFIG* fc) {
    fc=fc;
}
void DebugUseSlot(short slotnr,const char* name, void* ptr,unsigned short type) {
    slotnr=slotnr;name=name;ptr=ptr;type=type;
}
void DebugFreeSlot(short slotnr) {
   slotnr=slotnr;
}

#else

extern short nr_skipwords;

//=============================================================================
// modify this function if you want another hotkey to be used for console
// activating (yet the hotkey is holding down '4','5','6' on the numeric keypad)
//=============================================================================
static inline void ACTIVATE_CONSOLE_IF_WANTED(FATCONFIG* fc) {
    if (TI89) {
        if ((_rowread(~(1<<4)) & 0x4) &&
            (_rowread(~(1<<3)) & 0x4) &&
            (_rowread(~(1<<4)) & 0x4))
        {
            DebugConsole(fc);
        }
    }
    else {
        if ((_rowread(~(1<<2)) & 0b11100000) == 0b11100000) DebugConsole(fc);
    }
}



//=============================================================================
// modify this macro if you want another hotkey to be used for console
// activating ...
//=============================================================================
//#define ACTIVATE_CONSOLE_IF_WANTED()  ({if (GetPadState() == PADSTATE_APPS) DebugConsole(fc);})

typedef struct {
    unsigned short type;
    const char*    name;
    void*          addr;
} DEBUGSLOT;

#define DEBUG_NR_USERPAGES     5
#define DEBUG_NR_LINES        14
#define DEBUG_NR_CLIENTSLOTS  (DEBUG_NR_USERPAGES*DEBUG_NR_LINES)


#define SIZE_CHARSET       (256*5)
#define SIZE_CHARWIDTH     (256*2)
#define SIZE_MEMCONSOLE    (SIZE_CHARSET+SIZE_CHARWIDTH+DEBUG_NR_CLIENTSLOTS*sizeof(DEBUGSLOT))

short*         charwidth   = NULL;
unsigned char* charset     = NULL;
DEBUGSLOT*     clientslots = NULL;
short          section     = 0;
short          clientpage  = 0;
short          spritepage  = 0;


//=============================================================================
// registers a user variable
//=============================================================================
void DebugUseSlot(short slotnr,const char* name, void* ptr,unsigned short type) {
    slotnr%=(DEBUG_NR_CLIENTSLOTS);
    clientslots[slotnr].type = type;
    clientslots[slotnr].name = name;
    clientslots[slotnr].addr = ptr;
}


//=============================================================================
// registers a user variable
//=============================================================================
void DebugFreeSlot(short slotnr) {
    clientslots[slotnr%DEBUG_NR_CLIENTSLOTS].type = FAT_DBG_NOTUSED;
}


//=============================================================================
// rips character set into given buffer for fast string drawing
//=============================================================================
static inline void DebugInitConsole(unsigned char* ptr) {
    short i;
    short oldfont = FontSetSys(F_4x6);

    charset     = ptr;
    charwidth   = (short*)(ptr+SIZE_CHARSET);
    clientslots = (DEBUGSLOT*)(ptr+SIZE_CHARSET+SIZE_CHARWIDTH);
    section     = 0;
    clientpage  = 0;
    spritepage  = 0;

    PortSet(charset,7,5*256-1);

    // now draw all characters into the buffer so that we can use it later
    for (i=0;i<256;i++) {
        charwidth[i] = FontCharWidth(i);
        DrawChar(0,i*5,i,A_REPLACE);
    }
    PortRestore();
    FontSetSys(oldfont);

    for (i=0;i<DEBUG_NR_CLIENTSLOTS;i++) clientslots[i].type = FAT_DBG_NOTUSED;
}


//=============================================================================
// draws string using own sprites (about 4 times faster than DrawStrXY)
//=============================================================================
void DebugOut(FATCONFIG* fc,short x,short y,const unsigned char* s) {
    unsigned char* sprite;
    long           addr0;
    long           addr1;
    unsigned short cnt;
    unsigned short line_len = 12+(nr_skipwords<<1);

    while (*s) {
        sprite = &charset[(short)(*s)*5];
        cnt    = (y*line_len+(x>>3)) & 0xfffe;
        addr0  = ((long)(fc->dest_plane0))+cnt;
        addr1  = ((long)(fc->dest_plane1))+cnt;

        cnt  = 24-(x&15);
        x+=charwidth[*s++];
        if (x>95) return;

        // unrolled loop for more speed ....
        // NOTE: We are using XOR here, so this function can also be used
        // for the "white on black" strings
        *(long*)addr0^=(long)(*sprite)<<cnt;  addr0+=line_len;
        *(long*)addr1^=(long)(*sprite++)<<cnt;addr1+=line_len;
        *(long*)addr0^=(long)(*sprite)<<cnt;  addr0+=line_len;
        *(long*)addr1^=(long)(*sprite++)<<cnt;addr1+=line_len;
        *(long*)addr0^=(long)(*sprite)<<cnt;  addr0+=line_len;
        *(long*)addr1^=(long)(*sprite++)<<cnt;addr1+=line_len;
        *(long*)addr0^=(long)(*sprite)<<cnt;  addr0+=line_len;
        *(long*)addr1^=(long)(*sprite++)<<cnt;addr1+=line_len;
        *(long*)addr0^=(long)(*sprite)<<cnt;
        *(long*)addr1^=(long)(*sprite)<<cnt;
    }
}


//=============================================================================
// helper function: fills n lines at vertical pos. y with black (both planes)
//=============================================================================
static void DebugHLines(FATCONFIG* fc,short y,short n) {
    unsigned short* dest0 = fc->dest_plane0 + (nr_skipwords+6)*y;
    unsigned short* dest1 = fc->dest_plane1 + (nr_skipwords+6)*y;

    while (n--) {
        *dest0++ = 0xffff,*dest0++ = 0xffff,*dest0++ = 0xffff,
        *dest0++ = 0xffff,*dest0++ = 0xffff,*dest0++ = 0xffff;
        *dest1++ = 0xffff,*dest1++ = 0xffff,*dest1++ = 0xffff,
        *dest1++ = 0xffff,*dest1++ = 0xffff,*dest1++ = 0xffff;
        dest0+=nr_skipwords,dest1+=nr_skipwords;
    }
}


//=============================================================================
// output text on a specified line of the console
//
// the valid range for line is 0 .. DEBUG_NR_LINES-1 (other values will be
// clamped)
//=============================================================================
static void DebugOutLine(FATCONFIG* fc,short x,short line,const char* s) {
    DebugOut(fc,x,9+6*(line%DEBUG_NR_LINES),s);
}


//=============================================================================
// Initializes the console by clearing both planes, writing the header and
// the footer
//=============================================================================
static void DebugClearScreen(FATCONFIG* fc) {
    unsigned short* dest0 = fc->dest_plane0;
    unsigned short* dest1 = fc->dest_plane1;
    short i;

    for (i=0;i<96;i++,dest0+=nr_skipwords,dest1+=nr_skipwords) {
        if (!i || i==95) {
            *dest0++ = 0xffff,*dest0++ = 0xffff,*dest0++ = 0xffff,
            *dest0++ = 0xffff,*dest0++ = 0xffff,*dest0++ = 0xffff;
            *dest1++ = 0xffff,*dest1++ = 0xffff,*dest1++ = 0xffff,
            *dest1++ = 0xffff,*dest1++ = 0xffff,*dest1++ = 0xffff;
        }
        else {
            *dest0++ = 0x8000,*dest0++ = 0,*dest0++ = 0,*dest0++ = 0,*dest0++ = 0,*dest0++ = 1;
            *dest1++ = 0x8000,*dest1++ = 0,*dest1++ = 0,*dest1++ = 0,*dest1++ = 0,*dest1++ = 1;
        }
    }
    DebugHLines(fc,1,6);
    DebugHLines(fc,95,1);
}


//=============================================================================
// prints a complete console page using DEBUG_NR_LINES slots
//=============================================================================
static void DebugShowPage(FATCONFIG* fc,const char* title,DEBUGSLOT* slots) {
    static const char* format[9] = {"%d","%u","%d","%u","%ld","%lu",
                                    "0x%02x","0x%04x","0x%08lx"};
    char  buffer[100];
    short i;
    short j;
    char* s;

    DebugClearScreen(fc);

    DebugOut(fc,2,1,title);

    for (i=0;i<DEBUG_NR_LINES;i++) {
        if (slots[i].type>9 || !slots[i].addr || !slots[i].name) continue;

        DebugOutLine(fc,1,i,slots[i].name);

        switch(slots[i].type) {
            case FAT_DBG_CHAR_DEC:   sprintf(buffer,format[slots[i].type],*(char*)(slots[i].addr)); break;
            case FAT_DBG_UCHAR_DEC:  sprintf(buffer,format[slots[i].type],*(unsigned char*)(slots[i].addr)); break;
            case FAT_DBG_SHORT_DEC:  sprintf(buffer,format[slots[i].type],*(short*)(slots[i].addr)); break;
            case FAT_DBG_USHORT_DEC: sprintf(buffer,format[slots[i].type],*(unsigned short*)(slots[i].addr)); break;
            case FAT_DBG_LONG_DEC:   sprintf(buffer,format[slots[i].type],*(long*)(slots[i].addr)); break;
            case FAT_DBG_ULONG_DEC:  sprintf(buffer,format[slots[i].type],*(unsigned long*)(slots[i].addr)); break;
            case FAT_DBG_CHAR_HEX:   sprintf(buffer,format[slots[i].type],*(unsigned char*)(slots[i].addr)); break;
            case FAT_DBG_SHORT_HEX:  sprintf(buffer,format[slots[i].type],*(unsigned short*)(slots[i].addr)); break;
            case FAT_DBG_LONG_HEX:   sprintf(buffer,format[slots[i].type],*(unsigned long*)(slots[i].addr)); break;
            case FAT_DBG_STRING:     s = *(char**)(slots[i].addr);
                                     for (j=0;j<30 && *s != 0;j++) buffer[j]=*s++;
                                     buffer[j]=0;
                                     break;
        }

        DebugOutLine(fc,45,i,buffer);
    }
}


//=============================================================================
// prints engine internals
//=============================================================================
extern DEPTHDATA*      depthinfo;
extern short           nr_skipwords;
extern unsigned short* hudplane0_high;
extern unsigned short* hudplane0_low;
extern unsigned short* hudplane1_high;
extern unsigned short* hudplane1_low;
extern unsigned short* hudmask_high;
extern unsigned short* hudmask_low;

static inline void DebugShowEngine(FATCONFIG* fc) {
#if defined(PREFIX_ZERO)
    static const char* version = "v" xstr(FAT_MAINVERSION) ".0" xstr(FAT_SUBVERSION);
#else
    static const char* version = "v" xstr(FAT_MAINVERSION) "." xstr(FAT_SUBVERSION);
#endif
    static const char* bdate   = (char*)fatbuilddatestring;
    static const char* btime   = (char*)fatbuildtimestring;
    static const void* iptr    = (void*)&fatinterface;
    DEBUGSLOT slots[DEBUG_NR_LINES] = {
        {FAT_DBG_STRING,    "version",&version},
        {FAT_DBG_STRING,    "builddate",&bdate},
        {FAT_DBG_STRING,    "buildtime",&btime},
        {FAT_DBG_LONG_HEX,  "INTERFACE",&iptr},
        {FAT_DBG_LONG_HEX,  "magic",(unsigned long*)&(fatinterface.magic)},
        {FAT_DBG_USHORT_DEC,"#entries",(unsigned short*)&(fatinterface.nrentries)},
        {FAT_DBG_LONG_HEX,  "DEPTHDATA",&(depthinfo)},
        {FAT_DBG_SHORT_DEC, "skipwords",&(nr_skipwords)},
        {FAT_DBG_LONG_HEX,  "HUD_0_HIGH",&(hudplane0_high)},
        {FAT_DBG_LONG_HEX,  "HUD_0_LOW",&(hudplane0_low)},
        {FAT_DBG_LONG_HEX,  "HUD_1_HIGH",&(hudplane1_high)},
        {FAT_DBG_LONG_HEX,  "HUD_1_LOW",&(hudplane1_low)},
        {FAT_DBG_LONG_HEX,  "HUDMASK_HI",&(hudmask_high)},
        {FAT_DBG_LONG_HEX,  "HUDMASK_LO",&(hudmask_low)}
   };
   DebugShowPage(fc,"ENGINE - Details",slots);
}


//=============================================================================
// prints FATCONFIG
//=============================================================================
static inline void DebugShowFATCONFIG(FATCONFIG* fc) {
    DEBUGSLOT slots[DEBUG_NR_LINES] = {
        {FAT_DBG_LONG_HEX, "PTR",&fc},
        {FAT_DBG_SHORT_DEC,"map[w]",&(fc->map_width)},
        {FAT_DBG_SHORT_DEC,"map[h]",&(fc->map_height)},
        {FAT_DBG_LONG_HEX,"MAPDATA",&(fc->map_data)},
        {FAT_DBG_SHORT_DEC,"cam[x]",&(fc->cam_xpos)},
        {FAT_DBG_SHORT_DEC,"cam[y]",&(fc->cam_ypos)},
        {FAT_DBG_SHORT_DEC,"cam[angle]",&(fc->cam_orientation)},
        {FAT_DBG_ULONG_DEC,"framecount",&(fc->frame_counter)},
        {FAT_DBG_SHORT_DEC,"#sprites",&(fc->nr_sprites)},
        {FAT_DBG_LONG_HEX,"BACKGROUND",&(fc->background)},
        {FAT_DBG_LONG_HEX,"TEXTURES",&(fc->textures)},
        {FAT_DBG_LONG_HEX,"DESTPLANE0",&(fc->dest_plane0)},
        {FAT_DBG_LONG_HEX,"DESTPLANE1",&(fc->dest_plane1)},
        {FAT_DBG_NOTUSED,NULL,NULL}
   };
   DebugShowPage(fc,"FATCONFIG",slots);
}


//=============================================================================
// prints FATCONFIG
//=============================================================================
static inline void DebugShowFATSPRITE(FATCONFIG* fc,short spritenr) {
    void* p = &(fc->sprites[spritenr]);
    DEBUGSLOT slots[DEBUG_NR_LINES] = {
        {FAT_DBG_LONG_HEX,  "PTR",&p},
        {FAT_DBG_USHORT_DEC,"mode",&(fc->sprites[spritenr].drawmode)},
        {FAT_DBG_SHORT_DEC, "pos[x]",&(fc->sprites[spritenr].xpos)},
        {FAT_DBG_SHORT_DEC, "pos[y]",&(fc->sprites[spritenr].ypos)},
        {FAT_DBG_SHORT_DEC, "orientation",&(fc->sprites[spritenr].orientation)},
        {FAT_DBG_SHORT_DEC, "#textures",&(fc->sprites[spritenr].orientation)},
        {FAT_DBG_LONG_HEX,  "TEXPTR",&(fc->sprites[spritenr].textures)},
        {FAT_DBG_SHORT_DEC, "height",&(fc->sprites[spritenr].height)},
        {FAT_DBG_SHORT_DEC, "centerx",&(fc->sprites[spritenr].centerx)},
        {FAT_DBG_SHORT_DEC, "angle",&(fc->sprites[spritenr].angle)},
        {FAT_DBG_SHORT_DEC, "dist",&(fc->sprites[spritenr].dist)},
        {FAT_DBG_LONG_HEX,  "PREV",&(fc->sprites[spritenr].prev)},
        {FAT_DBG_LONG_HEX,  "NEXT",&(fc->sprites[spritenr].next)},
        {FAT_DBG_NOTUSED,NULL,NULL}
   };
   char buffer[100];
   sprintf(buffer,"FATSPRITE (%d of %d)",spritenr+1,fc->nr_sprites);

   DebugShowPage(fc,buffer,slots);
}


//=============================================================================
// displays user variables
//=============================================================================
static inline void DebugShowUserVar(FATCONFIG* fc,short page) {
    char buffer[50];
    sprintf(buffer,"CLIENTSLOTS (%d to %d)",page*DEBUG_NR_LINES,(page+1)*DEBUG_NR_LINES-1);
    DebugShowPage(fc,buffer,&(clientslots[page*DEBUG_NR_LINES]));
}

#define SECTION_ENGINE     0
#define SECTION_FATCONFIG  1
#define SECTION_SPRITE     2
#define SECTION_CLIENT     3
#define NR_SECTIONS        4

//=============================================================================
// handles the debugging console
//=============================================================================
void DebugConsole(FATCONFIG* fc) {
    short     oldfont = FontSetSys(F_4x6);
    PADSTATES state;
    short     nr_sprites = fc->nr_sprites;

    if (section==SECTION_SPRITE) {
        if (nr_sprites <= 0) section=SECTION_FATCONFIG;
        else if (spritepage >= nr_sprites) spritepage = 0;
    }

    do {
        switch(section) {
           case SECTION_ENGINE:    DebugShowEngine(fc);    break;
           case SECTION_FATCONFIG: DebugShowFATCONFIG(fc); break;
           case SECTION_SPRITE:    DebugShowFATSPRITE(fc,spritepage); break;
           case SECTION_CLIENT:    DebugShowUserVar(fc,clientpage);   break;
        }
        while (_rowread(0) & 0xff);
        while (!(state=GetPadState()));
        while (_rowread(0) & 0xff);

        if (state & PADSTATE_ESC) break;
        else if (state & PADSTATE_UP) {
            section--;
            if (section==SECTION_SPRITE && nr_sprites<=0) section--;
            if (section<0) section = NR_SECTIONS-1;
        }
        else if (state & PADSTATE_DOWN) {
            section = (section + 1) % NR_SECTIONS;
            if (section==SECTION_SPRITE && nr_sprites<=0) section = (section + 1) % NR_SECTIONS;
        }
        else if (state & PADSTATE_LEFT) {
            if (section==SECTION_SPRITE) {
                spritepage--;
                if (spritepage<0) spritepage=nr_sprites-1;
            }
            else if (section==SECTION_CLIENT) {
                clientpage--;
                if (clientpage<0) clientpage=DEBUG_NR_USERPAGES-1;
            }
        }
        else if (state & PADSTATE_RIGHT) {
            if (section==SECTION_SPRITE) {
                spritepage = (spritepage + 1) % (nr_sprites);
            }
            else if (section==SECTION_CLIENT) {
                clientpage = (clientpage + 1) % DEBUG_NR_USERPAGES;
            }
        }
    }
    while (1);

    FontSetSys(oldfont);
}

#endif


//#############################################################################
// Revision History
//#############################################################################
//
// $Log: console.c,v $
// Revision 1.5  2002/05/03 11:39:50  tnussb
// prefix zero in subversion is now handled correctly
//
// Revision 1.4  2002/04/30 17:42:49  tnussb
// console hotkey changed to simultaneously pressing [4],[5] and [6]
//
// Revision 1.3  2002/04/29 10:00:50  tnussb
// console display completely revised
//
// Revision 1.2  2002/04/25 20:03:05  tnussb
// (1) number display of sprites fixed
// (2) initialization of CLIENTSLOTs added
//
// Revision 1.1  2002/04/25 19:46:43  tnussb
// initial version
//
//
