/******************************************************************************
*
* project name:   FAT-Engine
* file name:      input.c
* initial date:   22/04/2002
* author:         thomas.nussbaumer@gmx.net
*
* description:    keypad input functions for TI-89/TI-92p
*
* $Id: input.c,v 1.2 2002/04/25 19:47:17 tnussb Exp $
*
******************************************************************************/

// ============================================================================
// ============================================================================
// ==  keyboard handling                                                     ==
// ============================================================================
// ============================================================================

//-----------------------------------------------------------------------------
// the keyboard reading functions mimics the keyboard routine of genlib in
// mean of which keys are used on which calculator.
//
// In detail the following keys are queried (depending on the calc type):
//
// flag set                TI-89     TI-92p
// -------------------------------------------
// PADSTATE_ESC            ESC       ESC
// PADSTATE_UP             up        up
// PADSTATE_DOWN           down      down
// PADSTATE_LEFT           left      left
// PADSTATE_RIGHT          right     right
// PADSTATE_APPS           APPS      APPS
// PADSTATE_PLUS           +         +
// PADSTATE_MINUS          -         -
// PADSTATE_KA             2nd       F1
// PADSTATE_KB             Diamond   F2
// PADSTATE_KC             Home      F3
// PADSTATE_KD             X         F4
// PADSTATE_KE             Shift     F5
// PADSTATE_KF             Alpha     F6
// PADSTATE_KG             Mode      F7
// PADSTATE_KH             Y         F8
//
//-----------------------------------------------------------------------------

/*===========================================================================*/
/* returns PADSTATES with key flags set or 0 (TI-89 VERSION)                 */
/*===========================================================================*/
PADSTATES GetPossibleKeys89(void) {
    register unsigned char val;
    register PADSTATES     key = 0;

    val = _rowread(~(1<<0));
    if (val & 0x01) key |= PADSTATE_UP;     // up
    if (val & 0x02) key |= PADSTATE_LEFT;   // down
    if (val & 0x04) key |= PADSTATE_DOWN;   // left
    if (val & 0x08) key |= PADSTATE_RIGHT;  // right
    if (val & 0x10) key |= PADSTATE_KA;     // 2nd
    if (val & 0x40) key |= PADSTATE_KB;     // Diamond
    if (val & 0x20) key |= PADSTATE_KE;     // Shift
    if (val & 0x80) key |= PADSTATE_KF;     // Alpha
    val = _rowread(~(1<<1));
    if (val & 0x02) key |= PADSTATE_PLUS;   // +
    if (val & 0x04) key |= PADSTATE_MINUS;  // -
    val = _rowread(~(1<<4));
    if (val & 0x40) key |= PADSTATE_KG;     // Mode
    if (val & 0x20) key |= PADSTATE_KH;     // Y
    val = _rowread(~(1<<5));
    if (val & 0x01) key |= PADSTATE_APPS;   // APPS
    if (val & 0x40) key |= PADSTATE_KC;     // Home
    if (val & 0x20) key |= PADSTATE_KD;     // X
    if (_rowread(~(1<<6)) & 0x01) key |= PADSTATE_ESC;    // ESC

    return key;
}


/*===========================================================================*/
/* returns PADSTATES with key flags set or 0 (TI-92p VERSION)                 */
/*===========================================================================*/
PADSTATES GetPossibleKeys92p(void) {
    register unsigned char val;
    register PADSTATES     key = 0;

    val = _rowread(~(1<<0));
    if (val & 0x10) key |= PADSTATE_LEFT;             //up
    if (val & 0x20) key |= PADSTATE_UP;               //down
    if (val & 0x40) key |= PADSTATE_RIGHT;            //left
    if (val & 0x80) key |= PADSTATE_DOWN;             //right
    if (_rowread(~(1<<1)) & 0x10) key |= PADSTATE_KH; //F8
    if (_rowread(~(1<<2)) & 0x10) key |= PADSTATE_KC; //F3
    if (_rowread(~(1<<3)) & 0x10) key |= PADSTATE_KG; //F7
    if (_rowread(~(1<<4)) & 0x10) key |= PADSTATE_KB; //F2
    if (_rowread(~(1<<5)) & 0x10) key |= PADSTATE_KF; //F6
    if (_rowread(~(1<<6)) & 0x10) key |= PADSTATE_KA; //F1
    val = _rowread(~(1<<7));
    if (val & 0x40) key |= PADSTATE_APPS;             //APPS
    if (val & 0x10) key |= PADSTATE_KE;               //F5
    val = _rowread(~(1<<8));
    if (val & 0x40) key |= PADSTATE_ESC;              //ESC
    if (val & 0x10) key |= PADSTATE_PLUS;             //+
    val = _rowread(~(1<<9));
    if (val & 0x01) key |= PADSTATE_MINUS;            //-
    if (val & 0x10) key |= PADSTATE_KD;               //F4

    return key;
}


PADSTATES (*__readkeys__)(void)   = NULL;   // will hold key function for active
                                          // calculator type

/*===========================================================================*/
/* initializes readkey function pointer depending on calctype                */
/*===========================================================================*/
static inline void InitReadKeyFunction(void) {
    if (TI89)  __readkeys__      = GetPossibleKeys89;
    else       __readkeys__      = GetPossibleKeys92p;
}

/*===========================================================================*/
/* returns PAD state                                                         */
/*===========================================================================*/
PADSTATES GetPadState(void) {
    return __readkeys__();
}



//#############################################################################
// Revision History
//#############################################################################
//
// $Log: input.c,v $
// Revision 1.2  2002/04/25 19:47:17  tnussb
// generic commit for engine version v1.05
//
// Revision 1.1  2002/04/24 17:34:36  tnussb
// initial version extracted from Game Construction Kit (GCK)
//
//