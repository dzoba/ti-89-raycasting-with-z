/******************************************************************************
*
* project name:   FAT-Engine
* file name:      utils.c
* initial date:   30/03/2001
* author:         thomas.nussbaumer@gmx.net
*
* description:    utility functions used within the demos
*
* $Id: utils.c,v 1.14 2002/05/08 15:34:21 tnussb Exp $
*
******************************************************************************/

#if !defined(NO_COUNTER_SUPPORT)

//-----------------------------------------------------------------------------
// images for numbers (90 bytes - it doesn't make sense to put this into the
// texture file)
//-----------------------------------------------------------------------------
static unsigned char numbers_data[90] = {
0x70,0xd8,0xd8,0xd8,0xd8,0xd8,0xd8,0xd8,0x70,
0x30,0x70,0xf0,0x30,0x30,0x30,0x30,0x30,0xf8,
0x70,0xd8,0xd8,0x18,0x30,0x30,0x60,0x60,0xf8,
0x70,0xd8,0xd8,0x18,0x30,0x18,0xd8,0xd8,0x70,
0x70,0x70,0x70,0xb0,0xb0,0xf8,0xf8,0x30,0x30,
0xf8,0xc0,0xf8,0xd8,0x18,0xd8,0xd8,0xd8,0x70,
0x70,0xd8,0xc0,0xf0,0xd8,0xd8,0xd8,0xd8,0x70,
0xf8,0x18,0x18,0x30,0x30,0x30,0x60,0x60,0x60,
0x70,0xd8,0xd8,0xd8,0x70,0xd8,0xd8,0xd8,0x70,
0x70,0xd8,0xd8,0xd8,0xd8,0x78,0x18,0xd8,0x70};

//=============================================================================
// XORs a number sprite with dark plane (white numbers on darkgray background)
// [only used internally]
//=============================================================================
void Number_XOR_DarkPlane(short x,short y,unsigned char number) {
    register long           addr   = (long)GetPlane(DARK_PLANE)+(y<<5)-(y<<1)+((x>>3)&0xfffe);
    register unsigned short cnt    = 24-(x&15);
    register unsigned char* sprite = numbers_data+(number<<3)+number;

    // un-rolled loop (number sprites are 9 lines high)
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt; addr+=30;
    *(long*)addr^=(long)(*sprite++)<<cnt;
}


#define COUNTER_MAX_LEN 10

typedef struct {
    short x;
    short y;
    short length;
    short already_used; // marker if counter was already XOR'ed once to plane
    unsigned char oldcount[COUNTER_MAX_LEN];
    unsigned char newcount[COUNTER_MAX_LEN];
}
COUNTER;


//=============================================================================
// initializes a counter with given length and value
//=============================================================================
void InitCounter(COUNTER* counter,short x,short y,short length,unsigned long value) {
    short i;
    counter->length       = length;
    counter->already_used = 0;
    counter->x            = x;
    counter->y            = y;

    for (i=length-1;i>=0;i--) {
        unsigned char v = value % 10;
        counter->oldcount[i] = v;
        counter->newcount[i] = v;
        value /= 10;
    }
}


//=============================================================================
// XORs a counter with dark plane (white numbers on darkgray background !!!)
//
// NOTE: if previous counter array is NULL this routine will suppose that the
//       background is completely dark gray
//
// (6 pixels is used as digit width)
//
// numbers are 9 lines high
//=============================================================================
void DrawCounter(COUNTER* counter) {
    unsigned char* oldcounter = counter->oldcount;
    unsigned char* newcounter = counter->newcount;
    short i;
    short x = counter->x;

    if (counter->already_used) {
        for (i=0;i<counter->length;i++,x+=6) {
            if (*oldcounter != *newcounter) {
                Number_XOR_DarkPlane(x,counter->y,*oldcounter);
                Number_XOR_DarkPlane(x,counter->y,*newcounter);
            }
            *oldcounter++ = *newcounter++;
        }
    }
    else {
        for (i=0;i<counter->length;i++,x+=6) {
            Number_XOR_DarkPlane(x,counter->y,*newcounter);
            *oldcounter++ = *newcounter++;
        }
        counter->already_used = 1;
    }
}

#endif


#if !defined(NO_PLAYER_MOVE)
//=============================================================================
// move player forward or backward depending on player's angle ...
//
// if strafe != 0 the player is moved left or right depending on forward_right
//=============================================================================
void PlayerMove(FATCONFIG* fc,short forward_right,short strafe) {
    short tmp     = (strafe)? +ANGLE_090 : 0;
    short stepx   = FAT_Cos16384(fc->cam_orientation+tmp) >> 11;
    short stepy   = FAT_Sin16384(fc->cam_orientation+tmp) >> 11;
    short newxpos = fc->cam_xpos + ((forward_right) ? stepx : -stepx);
    short newypos = fc->cam_ypos + ((forward_right) ? stepy : -stepy);
    short newxmod = newxpos >> 6;
    short newymod = newypos >> 6;

    //-------------------------------------------------------------------------
    // check if we are still within the map
    //-------------------------------------------------------------------------
    if (newxmod > fc->map_width-1  ||
        newymod > fc->map_height-1 ||
        newxmod < 0 || newymod < 0)
    {
        return;
    }

    //-------------------------------------------------------------------------
    // check if we would move into a solid square
    //-------------------------------------------------------------------------
    if (*(map+newymod*fc->map_width+newxmod)>0) return;

    //-------------------------------------------------------------------------
    // everything okay -> let's set the new position
    //-------------------------------------------------------------------------
    fc->cam_xpos = newxpos;
    fc->cam_ypos = newypos;
}

#endif

//=============================================================================
// turn player left or right ...
//=============================================================================
void PlayerTurn(FATCONFIG* fc,short right,short increment) {
    fc->cam_orientation += (right) ? increment : -increment;
    // now clamp the camera orientation to the valid range of 0 ... 575
    fc->cam_orientation = FAT_ClampAngle(fc->cam_orientation);
}



INT_HANDLER _old_int1_=0;
INT_HANDLER _old_int5_=0;

unsigned long int1_counter = 0;
unsigned long int5_counter = 0;

DEFINE_INT_HANDLER (int1_handler) {
    int1_counter++;
}

DEFINE_INT_HANDLER (int5_handler) {
    int5_counter++;
}


//=============================================================================
// sets dummy handler for INT1
//=============================================================================
#define InstallDummyHandlerForINTs() ({\
    int1_counter = 0;\
    int5_counter = 0;\
    _old_int1_ = GetIntVec(AUTO_INT_1);SetIntVec(AUTO_INT_1,int1_handler);\
    _old_int5_ = GetIntVec(AUTO_INT_5);SetIntVec(AUTO_INT_5,int5_handler);\
})


//=============================================================================
// restore old handler for INT1
//=============================================================================
#define RestoreHandlerForINTs() ({\
    SetIntVec(AUTO_INT_1,_old_int1_);SetIntVec(AUTO_INT_5,_old_int5_);})




//#############################################################################
// Revision History
//#############################################################################
//
// $Log: utils.c,v $
// Revision 1.14  2002/05/08 15:34:21  tnussb
// number drawing and counter handling functions added
//
// Revision 1.13  2002/04/29 10:07:28  tnussb
// installs now counters instead of DUMMY_HANDLERS
//
// Revision 1.12  2002/04/25 19:40:43  tnussb
// macro WaitTillAllKeysReleased() removed. Use now FAT_AllKeysReleased().
//
// Revision 1.11  2002/04/24 18:51:04  tnussb
// using now FAT_ClampAngle() in PlayerTurn() [instead of own clamping]
//
// Revision 1.10  2002/04/24 17:40:38  tnussb
// (1) key reading functions removed (demos use now FAT_GetPadState() from engine)
// (2) PlayerTurn() function takes now the additionally argument "increment"
// (3) PlayerMove() can handle now strafing, too
//
// Revision 1.9  2002/04/18 12:14:48  tnussb
// using now fatdtx texture file instead of embedded textures
//
// Revision 1.8  2002/04/17 10:04:39  tnussb
// using now macros FAT_Cos16384/FAT_Sin16384
//
// Revision 1.7  2002/04/15 09:59:39  tnussb
// (1) GetPossibleKeys92p() fixed (thanx, Scott, for the report!)
// (2) using now STRIP_NORMAL instead of 0 for mirrored field structure TEXSTRIP
//
// Revision 1.6  2002/04/08 20:17:35  tnussb
// movement code modified to ignore negative map entries
//
// Revision 1.5  2002/04/03 10:08:38  tnussb
// GetPossibleKeys89() and GetPossibleKeys92p() optimized. Using now just 2
// rowread calls anymore.
//
// Revision 1.4  2002/03/11 09:17:43  tnussb
// USE_V200 added
//
// Revision 1.3  2002/03/07 11:17:34  tnussb
// including of PlayerMove function can be disabled with define NO_PLAYER_MOVE
//
// Revision 1.2  2002/03/06 12:11:48  tnussb
// redirects now AUTO_INT5 to a dummy handler, too
//
// Revision 1.1  2002/03/01 11:09:55  tnussb
// generic commit for sourcecode release v0.81
//
//
