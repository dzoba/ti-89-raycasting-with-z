//=============================================================================
// this file was automatically generated with:
//
// GenScalers v1.04 - Part of FAT-Engine
// (c) thomas.nussbaumer@gmx.net
//=============================================================================

#define CLIP_HEIGHT 168 // max. height usable without crashing

asm(".data
__scale002:
tst.l %d0
bpl.s ___a0000
or.w %d1,(%a0)+
rts
___a0000:
and.w %d2,(%a0)+
rts
__scale004:
tst.l %d0
bpl.s ___a0001
or.w %d1,(%a0)+
bra.s ___c0001
___a0001:
and.w %d2,(%a0)+
___c0001:
btst #10,%d0
beq.s ___a0002
or.w %d1,(%a0)+
rts
___a0002:
and.w %d2,(%a0)+
rts
__scale006:
tst.l %d0
bpl.s ___a0003
or.w %d1,(%a0)+
bra.s ___c0003
___a0003:
and.w %d2,(%a0)+
___c0003:
btst #19,%d0
beq.s ___a0004
or.w %d1,(%a0)+
bra.s ___c0004
___a0004:
and.w %d2,(%a0)+
___c0004:
btst #6,%d0
beq.s ___a0005
or.w %d1,(%a0)+
rts
___a0005:
and.w %d2,(%a0)+
rts
__scale008:
tst.l %d0
bpl.s ___a0006
or.w %d1,(%a0)+
bra.s ___c0006
___a0006:
and.w %d2,(%a0)+
___c0006:
btst #22,%d0
beq.s ___a0007
or.w %d1,(%a0)+
bra.s ___c0007
___a0007:
and.w %d2,(%a0)+
___c0007:
btst #13,%d0
beq.s ___a0008
or.w %d1,(%a0)+
bra.s ___c0008
___a0008:
and.w %d2,(%a0)+
___c0008:
btst #4,%d0
beq.s ___a0009
or.w %d1,(%a0)+
rts
___a0009:
and.w %d2,(%a0)+
rts
__scale010:
tst.l %d0
bpl.s ___a000a
or.w %d1,(%a0)+
bra.s ___c000a
___a000a:
and.w %d2,(%a0)+
___c000a:
btst #24,%d0
beq.s ___a000b
or.w %d1,(%a0)+
bra.s ___c000b
___a000b:
and.w %d2,(%a0)+
___c000b:
btst #17,%d0
beq.s ___a000c
or.w %d1,(%a0)+
bra.s ___c000c
___a000c:
and.w %d2,(%a0)+
___c000c:
btst #10,%d0
beq.s ___a000d
or.w %d1,(%a0)+
bra.s ___c000d
___a000d:
and.w %d2,(%a0)+
___c000d:
btst #3,%d0
beq.s ___a000e
or.w %d1,(%a0)+
rts
___a000e:
and.w %d2,(%a0)+
rts
__scale012:
tst.l %d0
bpl.s ___a000f
or.w %d1,(%a0)+
bra.s ___c000f
___a000f:
and.w %d2,(%a0)+
___c000f:
btst #26,%d0
beq.s ___a0010
or.w %d1,(%a0)+
bra.s ___c0010
___a0010:
and.w %d2,(%a0)+
___c0010:
btst #20,%d0
beq.s ___a0011
or.w %d1,(%a0)+
bra.s ___c0011
___a0011:
and.w %d2,(%a0)+
___c0011:
btst #14,%d0
beq.s ___a0012
or.w %d1,(%a0)+
bra.s ___c0012
___a0012:
and.w %d2,(%a0)+
___c0012:
btst #9,%d0
beq.s ___a0013
or.w %d1,(%a0)+
bra.s ___c0013
___a0013:
and.w %d2,(%a0)+
___c0013:
btst #3,%d0
beq.s ___a0014
or.w %d1,(%a0)+
rts
___a0014:
and.w %d2,(%a0)+
rts
__scale014:
tst.l %d0
bpl.s ___a0015
or.w %d1,(%a0)+
bra.s ___c0015
___a0015:
and.w %d2,(%a0)+
___c0015:
btst #27,%d0
beq.s ___a0016
or.w %d1,(%a0)+
bra.s ___c0016
___a0016:
and.w %d2,(%a0)+
___c0016:
btst #22,%d0
beq.s ___a0017
or.w %d1,(%a0)+
bra.s ___c0017
___a0017:
and.w %d2,(%a0)+
___c0017:
btst #17,%d0
beq.s ___a0018
or.w %d1,(%a0)+
bra.s ___c0018
___a0018:
and.w %d2,(%a0)+
___c0018:
btst #12,%d0
beq.s ___a0019
or.w %d1,(%a0)+
bra.s ___c0019
___a0019:
and.w %d2,(%a0)+
___c0019:
tst.b %d0
bpl.s ___a001a
or.w %d1,(%a0)+
bra.s ___c001a
___a001a:
and.w %d2,(%a0)+
___c001a:
btst #2,%d0
beq.s ___a001b
or.w %d1,(%a0)+
rts
___a001b:
and.w %d2,(%a0)+
rts
__scale016:
tst.l %d0
bpl.s ___a001c
or.w %d1,(%a0)+
bra.s ___c001c
___a001c:
and.w %d2,(%a0)+
___c001c:
btst #27,%d0
beq.s ___a001d
or.w %d1,(%a0)+
bra.s ___c001d
___a001d:
and.w %d2,(%a0)+
___c001d:
btst #23,%d0
beq.s ___a001e
or.w %d1,(%a0)+
bra.s ___c001e
___a001e:
and.w %d2,(%a0)+
___c001e:
btst #19,%d0
beq.s ___a001f
or.w %d1,(%a0)+
bra.s ___c001f
___a001f:
and.w %d2,(%a0)+
___c001f:
tst.w %d0
bpl.s ___a0020
or.w %d1,(%a0)+
bra.s ___c0020
___a0020:
and.w %d2,(%a0)+
___c0020:
btst #10,%d0
beq.s ___a0021
or.w %d1,(%a0)+
bra.s ___c0021
___a0021:
and.w %d2,(%a0)+
___c0021:
btst #6,%d0
beq.s ___a0022
or.w %d1,(%a0)+
bra.s ___c0022
___a0022:
and.w %d2,(%a0)+
___c0022:
btst #2,%d0
beq.s ___a0023
or.w %d1,(%a0)+
rts
___a0023:
and.w %d2,(%a0)+
rts
__scale018:
tst.l %d0
bpl.s ___a0024
or.w %d1,(%a0)+
bra.s ___c0024
___a0024:
and.w %d2,(%a0)+
___c0024:
btst #28,%d0
beq.s ___a0025
or.w %d1,(%a0)+
bra.s ___c0025
___a0025:
and.w %d2,(%a0)+
___c0025:
btst #24,%d0
beq.s ___a0026
or.w %d1,(%a0)+
bra.s ___c0026
___a0026:
and.w %d2,(%a0)+
___c0026:
btst #20,%d0
beq.s ___a0027
or.w %d1,(%a0)+
bra.s ___c0027
___a0027:
and.w %d2,(%a0)+
___c0027:
btst #17,%d0
beq.s ___a0028
or.w %d1,(%a0)+
bra.s ___c0028
___a0028:
and.w %d2,(%a0)+
___c0028:
btst #13,%d0
beq.s ___a0029
or.w %d1,(%a0)+
bra.s ___c0029
___a0029:
and.w %d2,(%a0)+
___c0029:
btst #9,%d0
beq.s ___a002a
or.w %d1,(%a0)+
bra.s ___c002a
___a002a:
and.w %d2,(%a0)+
___c002a:
btst #6,%d0
beq.s ___a002b
or.w %d1,(%a0)+
bra.s ___c002b
___a002b:
and.w %d2,(%a0)+
___c002b:
btst #2,%d0
beq.s ___a002c
or.w %d1,(%a0)+
rts
___a002c:
and.w %d2,(%a0)+
rts
__scale020:
tst.l %d0
bpl.s ___a002d
or.w %d1,(%a0)+
bra.s ___c002d
___a002d:
and.w %d2,(%a0)+
___c002d:
btst #28,%d0
beq.s ___a002e
or.w %d1,(%a0)+
bra.s ___c002e
___a002e:
and.w %d2,(%a0)+
___c002e:
btst #25,%d0
beq.s ___a002f
or.w %d1,(%a0)+
bra.s ___c002f
___a002f:
and.w %d2,(%a0)+
___c002f:
btst #22,%d0
beq.s ___a0030
or.w %d1,(%a0)+
bra.s ___c0030
___a0030:
and.w %d2,(%a0)+
___c0030:
btst #18,%d0
beq.s ___a0031
or.w %d1,(%a0)+
bra.s ___c0031
___a0031:
and.w %d2,(%a0)+
___c0031:
tst.w %d0
bpl.s ___a0032
or.w %d1,(%a0)+
bra.s ___c0032
___a0032:
and.w %d2,(%a0)+
___c0032:
btst #12,%d0
beq.s ___a0033
or.w %d1,(%a0)+
bra.s ___c0033
___a0033:
and.w %d2,(%a0)+
___c0033:
btst #8,%d0
beq.s ___a0034
or.w %d1,(%a0)+
bra.s ___c0034
___a0034:
and.w %d2,(%a0)+
___c0034:
btst #5,%d0
beq.s ___a0035
or.w %d1,(%a0)+
bra.s ___c0035
___a0035:
and.w %d2,(%a0)+
___c0035:
btst #2,%d0
beq.s ___a0036
or.w %d1,(%a0)+
rts
___a0036:
and.w %d2,(%a0)+
rts
__scale022:
tst.l %d0
bpl.s ___a0037
or.w %d1,(%a0)+
bra.s ___c0037
___a0037:
and.w %d2,(%a0)+
___c0037:
btst #28,%d0
beq.s ___a0038
or.w %d1,(%a0)+
bra.s ___c0038
___a0038:
and.w %d2,(%a0)+
___c0038:
btst #25,%d0
beq.s ___a0039
or.w %d1,(%a0)+
bra.s ___c0039
___a0039:
and.w %d2,(%a0)+
___c0039:
btst #22,%d0
beq.s ___a003a
or.w %d1,(%a0)+
bra.s ___c003a
___a003a:
and.w %d2,(%a0)+
___c003a:
btst #19,%d0
beq.s ___a003b
or.w %d1,(%a0)+
bra.s ___c003b
___a003b:
and.w %d2,(%a0)+
___c003b:
btst #16,%d0
beq.s ___a003c
or.w %d1,(%a0)+
bra.s ___c003c
___a003c:
and.w %d2,(%a0)+
___c003c:
btst #13,%d0
beq.s ___a003d
or.w %d1,(%a0)+
bra.s ___c003d
___a003d:
and.w %d2,(%a0)+
___c003d:
btst #10,%d0
beq.s ___a003e
or.w %d1,(%a0)+
bra.s ___c003e
___a003e:
and.w %d2,(%a0)+
___c003e:
tst.b %d0
bpl.s ___a003f
or.w %d1,(%a0)+
bra.s ___c003f
___a003f:
and.w %d2,(%a0)+
___c003f:
btst #4,%d0
beq.s ___a0040
or.w %d1,(%a0)+
bra.s ___c0040
___a0040:
and.w %d2,(%a0)+
___c0040:
btst #1,%d0
beq.s ___a0041
or.w %d1,(%a0)+
rts
___a0041:
and.w %d2,(%a0)+
rts
__scale024:
tst.l %d0
bpl.s ___a0042
or.w %d1,(%a0)+
bra.s ___c0042
___a0042:
and.w %d2,(%a0)+
___c0042:
btst #29,%d0
beq.s ___a0043
or.w %d1,(%a0)+
bra.s ___c0043
___a0043:
and.w %d2,(%a0)+
___c0043:
btst #26,%d0
beq.s ___a0044
or.w %d1,(%a0)+
bra.s ___c0044
___a0044:
and.w %d2,(%a0)+
___c0044:
btst #23,%d0
beq.s ___a0045
or.w %d1,(%a0)+
bra.s ___c0045
___a0045:
and.w %d2,(%a0)+
___c0045:
btst #21,%d0
beq.s ___a0046
or.w %d1,(%a0)+
bra.s ___c0046
___a0046:
and.w %d2,(%a0)+
___c0046:
btst #18,%d0
beq.s ___a0047
or.w %d1,(%a0)+
bra.s ___c0047
___a0047:
and.w %d2,(%a0)+
___c0047:
tst.w %d0
bpl.s ___a0048
or.w %d1,(%a0)+
bra.s ___c0048
___a0048:
and.w %d2,(%a0)+
___c0048:
btst #12,%d0
beq.s ___a0049
or.w %d1,(%a0)+
bra.s ___c0049
___a0049:
and.w %d2,(%a0)+
___c0049:
btst #10,%d0
beq.s ___a004a
or.w %d1,(%a0)+
bra.s ___c004a
___a004a:
and.w %d2,(%a0)+
___c004a:
tst.b %d0
bpl.s ___a004b
or.w %d1,(%a0)+
bra.s ___c004b
___a004b:
and.w %d2,(%a0)+
___c004b:
btst #4,%d0
beq.s ___a004c
or.w %d1,(%a0)+
bra.s ___c004c
___a004c:
and.w %d2,(%a0)+
___c004c:
btst #1,%d0
beq.s ___a004d
or.w %d1,(%a0)+
rts
___a004d:
and.w %d2,(%a0)+
rts
__scale026:
tst.l %d0
bpl.s ___a004e
or.w %d1,(%a0)+
bra.s ___c004e
___a004e:
and.w %d2,(%a0)+
___c004e:
btst #29,%d0
beq.s ___a004f
or.w %d1,(%a0)+
bra.s ___c004f
___a004f:
and.w %d2,(%a0)+
___c004f:
btst #26,%d0
beq.s ___a0050
or.w %d1,(%a0)+
bra.s ___c0050
___a0050:
and.w %d2,(%a0)+
___c0050:
btst #24,%d0
beq.s ___a0051
or.w %d1,(%a0)+
bra.s ___c0051
___a0051:
and.w %d2,(%a0)+
___c0051:
btst #21,%d0
beq.s ___a0052
or.w %d1,(%a0)+
bra.s ___c0052
___a0052:
and.w %d2,(%a0)+
___c0052:
btst #19,%d0
beq.s ___a0053
or.w %d1,(%a0)+
bra.s ___c0053
___a0053:
and.w %d2,(%a0)+
___c0053:
btst #16,%d0
beq.s ___a0054
or.w %d1,(%a0)+
bra.s ___c0054
___a0054:
and.w %d2,(%a0)+
___c0054:
btst #14,%d0
beq.s ___a0055
or.w %d1,(%a0)+
bra.s ___c0055
___a0055:
and.w %d2,(%a0)+
___c0055:
btst #11,%d0
beq.s ___a0056
or.w %d1,(%a0)+
bra.s ___c0056
___a0056:
and.w %d2,(%a0)+
___c0056:
btst #9,%d0
beq.s ___a0057
or.w %d1,(%a0)+
bra.s ___c0057
___a0057:
and.w %d2,(%a0)+
___c0057:
btst #6,%d0
beq.s ___a0058
or.w %d1,(%a0)+
bra.s ___c0058
___a0058:
and.w %d2,(%a0)+
___c0058:
btst #4,%d0
beq.s ___a0059
or.w %d1,(%a0)+
bra.s ___c0059
___a0059:
and.w %d2,(%a0)+
___c0059:
btst #1,%d0
beq.s ___a005a
or.w %d1,(%a0)+
rts
___a005a:
and.w %d2,(%a0)+
rts
__scale028:
tst.l %d0
bpl.s ___a005b
or.w %d1,(%a0)+
bra.s ___c005b
___a005b:
and.w %d2,(%a0)+
___c005b:
btst #29,%d0
beq.s ___a005c
or.w %d1,(%a0)+
bra.s ___c005c
___a005c:
and.w %d2,(%a0)+
___c005c:
btst #27,%d0
beq.s ___a005d
or.w %d1,(%a0)+
bra.s ___c005d
___a005d:
and.w %d2,(%a0)+
___c005d:
btst #24,%d0
beq.s ___a005e
or.w %d1,(%a0)+
bra.s ___c005e
___a005e:
and.w %d2,(%a0)+
___c005e:
btst #22,%d0
beq.s ___a005f
or.w %d1,(%a0)+
bra.s ___c005f
___a005f:
and.w %d2,(%a0)+
___c005f:
btst #20,%d0
beq.s ___a0060
or.w %d1,(%a0)+
bra.s ___c0060
___a0060:
and.w %d2,(%a0)+
___c0060:
btst #17,%d0
beq.s ___a0061
or.w %d1,(%a0)+
bra.s ___c0061
___a0061:
and.w %d2,(%a0)+
___c0061:
tst.w %d0
bpl.s ___a0062
or.w %d1,(%a0)+
bra.s ___c0062
___a0062:
and.w %d2,(%a0)+
___c0062:
btst #13,%d0
beq.s ___a0063
or.w %d1,(%a0)+
bra.s ___c0063
___a0063:
and.w %d2,(%a0)+
___c0063:
btst #10,%d0
beq.s ___a0064
or.w %d1,(%a0)+
bra.s ___c0064
___a0064:
and.w %d2,(%a0)+
___c0064:
btst #8,%d0
beq.s ___a0065
or.w %d1,(%a0)+
bra.s ___c0065
___a0065:
and.w %d2,(%a0)+
___c0065:
btst #6,%d0
beq.s ___a0066
or.w %d1,(%a0)+
bra.s ___c0066
___a0066:
and.w %d2,(%a0)+
___c0066:
btst #4,%d0
beq.s ___a0067
or.w %d1,(%a0)+
bra.s ___c0067
___a0067:
and.w %d2,(%a0)+
___c0067:
btst #1,%d0
beq.s ___a0068
or.w %d1,(%a0)+
rts
___a0068:
and.w %d2,(%a0)+
rts
__scale030:
tst.l %d0
bpl.s ___a0069
or.w %d1,(%a0)+
bra.s ___c0069
___a0069:
and.w %d2,(%a0)+
___c0069:
btst #29,%d0
beq.s ___a006a
or.w %d1,(%a0)+
bra.s ___c006a
___a006a:
and.w %d2,(%a0)+
___c006a:
btst #27,%d0
beq.s ___a006b
or.w %d1,(%a0)+
bra.s ___c006b
___a006b:
and.w %d2,(%a0)+
___c006b:
btst #25,%d0
beq.s ___a006c
or.w %d1,(%a0)+
bra.s ___c006c
___a006c:
and.w %d2,(%a0)+
___c006c:
btst #23,%d0
beq.s ___a006d
or.w %d1,(%a0)+
bra.s ___c006d
___a006d:
and.w %d2,(%a0)+
___c006d:
btst #21,%d0
beq.s ___a006e
or.w %d1,(%a0)+
bra.s ___c006e
___a006e:
and.w %d2,(%a0)+
___c006e:
btst #18,%d0
beq.s ___a006f
or.w %d1,(%a0)+
bra.s ___c006f
___a006f:
and.w %d2,(%a0)+
___c006f:
btst #16,%d0
beq.s ___a0070
or.w %d1,(%a0)+
bra.s ___c0070
___a0070:
and.w %d2,(%a0)+
___c0070:
btst #14,%d0
beq.s ___a0071
or.w %d1,(%a0)+
bra.s ___c0071
___a0071:
and.w %d2,(%a0)+
___c0071:
btst #12,%d0
beq.s ___a0072
or.w %d1,(%a0)+
bra.s ___c0072
___a0072:
and.w %d2,(%a0)+
___c0072:
btst #10,%d0
beq.s ___a0073
or.w %d1,(%a0)+
bra.s ___c0073
___a0073:
and.w %d2,(%a0)+
___c0073:
btst #8,%d0
beq.s ___a0074
or.w %d1,(%a0)+
bra.s ___c0074
___a0074:
and.w %d2,(%a0)+
___c0074:
btst #5,%d0
beq.s ___a0075
or.w %d1,(%a0)+
bra.s ___c0075
___a0075:
and.w %d2,(%a0)+
___c0075:
btst #3,%d0
beq.s ___a0076
or.w %d1,(%a0)+
bra.s ___c0076
___a0076:
and.w %d2,(%a0)+
___c0076:
btst #1,%d0
beq.s ___a0077
or.w %d1,(%a0)+
rts
___a0077:
and.w %d2,(%a0)+
rts
__scale032:
tst.l %d0
bpl.s ___a0078
or.w %d1,(%a0)+
bra.s ___c0078
___a0078:
and.w %d2,(%a0)+
___c0078:
btst #29,%d0
beq.s ___a0079
or.w %d1,(%a0)+
bra.s ___c0079
___a0079:
and.w %d2,(%a0)+
___c0079:
btst #27,%d0
beq.s ___a007a
or.w %d1,(%a0)+
bra.s ___c007a
___a007a:
and.w %d2,(%a0)+
___c007a:
btst #25,%d0
beq.s ___a007b
or.w %d1,(%a0)+
bra.s ___c007b
___a007b:
and.w %d2,(%a0)+
___c007b:
btst #23,%d0
beq.s ___a007c
or.w %d1,(%a0)+
bra.s ___c007c
___a007c:
and.w %d2,(%a0)+
___c007c:
btst #21,%d0
beq.s ___a007d
or.w %d1,(%a0)+
bra.s ___c007d
___a007d:
and.w %d2,(%a0)+
___c007d:
btst #19,%d0
beq.s ___a007e
or.w %d1,(%a0)+
bra.s ___c007e
___a007e:
and.w %d2,(%a0)+
___c007e:
btst #17,%d0
beq.s ___a007f
or.w %d1,(%a0)+
bra.s ___c007f
___a007f:
and.w %d2,(%a0)+
___c007f:
tst.w %d0
bpl.s ___a0080
or.w %d1,(%a0)+
bra.s ___c0080
___a0080:
and.w %d2,(%a0)+
___c0080:
btst #13,%d0
beq.s ___a0081
or.w %d1,(%a0)+
bra.s ___c0081
___a0081:
and.w %d2,(%a0)+
___c0081:
btst #11,%d0
beq.s ___a0082
or.w %d1,(%a0)+
bra.s ___c0082
___a0082:
and.w %d2,(%a0)+
___c0082:
btst #9,%d0
beq.s ___a0083
or.w %d1,(%a0)+
bra.s ___c0083
___a0083:
and.w %d2,(%a0)+
___c0083:
tst.b %d0
bpl.s ___a0084
or.w %d1,(%a0)+
bra.s ___c0084
___a0084:
and.w %d2,(%a0)+
___c0084:
btst #5,%d0
beq.s ___a0085
or.w %d1,(%a0)+
bra.s ___c0085
___a0085:
and.w %d2,(%a0)+
___c0085:
btst #3,%d0
beq.s ___a0086
or.w %d1,(%a0)+
bra.s ___c0086
___a0086:
and.w %d2,(%a0)+
___c0086:
btst #1,%d0
beq.s ___a0087
or.w %d1,(%a0)+
rts
___a0087:
and.w %d2,(%a0)+
rts
__scale034:
tst.l %d0
bpl.s ___a0088
or.w %d1,(%a0)+
bra.s ___c0088
___a0088:
and.w %d2,(%a0)+
___c0088:
btst #30,%d0
beq.s ___a0089
or.w %d1,(%a0)+
bra.s ___c0089
___a0089:
and.w %d2,(%a0)+
___c0089:
btst #28,%d0
beq.s ___a008a
or.w %d1,(%a0)+
bra.s ___c008a
___a008a:
and.w %d2,(%a0)+
___c008a:
btst #26,%d0
beq.s ___a008b
or.w %d1,(%a0)+
bra.s ___c008b
___a008b:
and.w %d2,(%a0)+
___c008b:
btst #24,%d0
beq.s ___a008c
or.w %d1,(%a0)+
bra.s ___c008c
___a008c:
and.w %d2,(%a0)+
___c008c:
btst #22,%d0
beq.s ___a008d
or.w %d1,(%a0)+
bra.s ___c008d
___a008d:
and.w %d2,(%a0)+
___c008d:
btst #20,%d0
beq.s ___a008e
or.w %d1,(%a0)+
bra.s ___c008e
___a008e:
and.w %d2,(%a0)+
___c008e:
btst #18,%d0
beq.s ___a008f
or.w %d1,(%a0)+
bra.s ___c008f
___a008f:
and.w %d2,(%a0)+
___c008f:
btst #16,%d0
beq.s ___a0090
or.w %d1,(%a0)+
bra.s ___c0090
___a0090:
and.w %d2,(%a0)+
___c0090:
btst #14,%d0
beq.s ___a0091
or.w %d1,(%a0)+
bra.s ___c0091
___a0091:
and.w %d2,(%a0)+
___c0091:
btst #12,%d0
beq.s ___a0092
or.w %d1,(%a0)+
bra.s ___c0092
___a0092:
and.w %d2,(%a0)+
___c0092:
btst #10,%d0
beq.s ___a0093
or.w %d1,(%a0)+
bra.s ___c0093
___a0093:
and.w %d2,(%a0)+
___c0093:
btst #9,%d0
beq.s ___a0094
or.w %d1,(%a0)+
bra.s ___c0094
___a0094:
and.w %d2,(%a0)+
___c0094:
tst.b %d0
bpl.s ___a0095
or.w %d1,(%a0)+
bra.s ___c0095
___a0095:
and.w %d2,(%a0)+
___c0095:
btst #5,%d0
beq.s ___a0096
or.w %d1,(%a0)+
bra.s ___c0096
___a0096:
and.w %d2,(%a0)+
___c0096:
btst #3,%d0
beq.s ___a0097
or.w %d1,(%a0)+
bra.s ___c0097
___a0097:
and.w %d2,(%a0)+
___c0097:
btst #1,%d0
beq.s ___a0098
or.w %d1,(%a0)+
rts
___a0098:
and.w %d2,(%a0)+
rts
__scale036:
tst.l %d0
bpl.s ___a0099
or.w %d1,(%a0)+
bra.s ___c0099
___a0099:
and.w %d2,(%a0)+
___c0099:
btst #30,%d0
beq.s ___a009a
or.w %d1,(%a0)+
bra.s ___c009a
___a009a:
and.w %d2,(%a0)+
___c009a:
btst #28,%d0
beq.s ___a009b
or.w %d1,(%a0)+
bra.s ___c009b
___a009b:
and.w %d2,(%a0)+
___c009b:
btst #26,%d0
beq.s ___a009c
or.w %d1,(%a0)+
bra.s ___c009c
___a009c:
and.w %d2,(%a0)+
___c009c:
btst #24,%d0
beq.s ___a009d
or.w %d1,(%a0)+
bra.s ___c009d
___a009d:
and.w %d2,(%a0)+
___c009d:
btst #22,%d0
beq.s ___a009e
or.w %d1,(%a0)+
bra.s ___c009e
___a009e:
and.w %d2,(%a0)+
___c009e:
btst #21,%d0
beq.s ___a009f
or.w %d1,(%a0)+
bra.s ___c009f
___a009f:
and.w %d2,(%a0)+
___c009f:
btst #19,%d0
beq.s ___a00a0
or.w %d1,(%a0)+
bra.s ___c00a0
___a00a0:
and.w %d2,(%a0)+
___c00a0:
btst #17,%d0
beq.s ___a00a1
or.w %d1,(%a0)+
bra.s ___c00a1
___a00a1:
and.w %d2,(%a0)+
___c00a1:
tst.w %d0
bpl.s ___a00a2
or.w %d1,(%a0)+
bra.s ___c00a2
___a00a2:
and.w %d2,(%a0)+
___c00a2:
btst #13,%d0
beq.s ___a00a3
or.w %d1,(%a0)+
bra.s ___c00a3
___a00a3:
and.w %d2,(%a0)+
___c00a3:
btst #12,%d0
beq.s ___a00a4
or.w %d1,(%a0)+
bra.s ___c00a4
___a00a4:
and.w %d2,(%a0)+
___c00a4:
btst #10,%d0
beq.s ___a00a5
or.w %d1,(%a0)+
bra.s ___c00a5
___a00a5:
and.w %d2,(%a0)+
___c00a5:
btst #8,%d0
beq.s ___a00a6
or.w %d1,(%a0)+
bra.s ___c00a6
___a00a6:
and.w %d2,(%a0)+
___c00a6:
btst #6,%d0
beq.s ___a00a7
or.w %d1,(%a0)+
bra.s ___c00a7
___a00a7:
and.w %d2,(%a0)+
___c00a7:
btst #4,%d0
beq.s ___a00a8
or.w %d1,(%a0)+
bra.s ___c00a8
___a00a8:
and.w %d2,(%a0)+
___c00a8:
btst #3,%d0
beq.s ___a00a9
or.w %d1,(%a0)+
bra.s ___c00a9
___a00a9:
and.w %d2,(%a0)+
___c00a9:
btst #1,%d0
beq.s ___a00aa
or.w %d1,(%a0)+
rts
___a00aa:
and.w %d2,(%a0)+
rts
__scale038:
tst.l %d0
bpl.s ___a00ab
or.w %d1,(%a0)+
bra.s ___c00ab
___a00ab:
and.w %d2,(%a0)+
___c00ab:
btst #30,%d0
beq.s ___a00ac
or.w %d1,(%a0)+
bra.s ___c00ac
___a00ac:
and.w %d2,(%a0)+
___c00ac:
btst #28,%d0
beq.s ___a00ad
or.w %d1,(%a0)+
bra.s ___c00ad
___a00ad:
and.w %d2,(%a0)+
___c00ad:
btst #26,%d0
beq.s ___a00ae
or.w %d1,(%a0)+
bra.s ___c00ae
___a00ae:
and.w %d2,(%a0)+
___c00ae:
btst #25,%d0
beq.s ___a00af
or.w %d1,(%a0)+
bra.s ___c00af
___a00af:
and.w %d2,(%a0)+
___c00af:
btst #23,%d0
beq.s ___a00b0
or.w %d1,(%a0)+
bra.s ___c00b0
___a00b0:
and.w %d2,(%a0)+
___c00b0:
btst #21,%d0
beq.s ___a00b1
or.w %d1,(%a0)+
bra.s ___c00b1
___a00b1:
and.w %d2,(%a0)+
___c00b1:
btst #20,%d0
beq.s ___a00b2
or.w %d1,(%a0)+
bra.s ___c00b2
___a00b2:
and.w %d2,(%a0)+
___c00b2:
btst #18,%d0
beq.s ___a00b3
or.w %d1,(%a0)+
bra.s ___c00b3
___a00b3:
and.w %d2,(%a0)+
___c00b3:
btst #16,%d0
beq.s ___a00b4
or.w %d1,(%a0)+
bra.s ___c00b4
___a00b4:
and.w %d2,(%a0)+
___c00b4:
btst #14,%d0
beq.s ___a00b5
or.w %d1,(%a0)+
bra.s ___c00b5
___a00b5:
and.w %d2,(%a0)+
___c00b5:
btst #13,%d0
beq.s ___a00b6
or.w %d1,(%a0)+
bra.s ___c00b6
___a00b6:
and.w %d2,(%a0)+
___c00b6:
btst #11,%d0
beq.s ___a00b7
or.w %d1,(%a0)+
bra.s ___c00b7
___a00b7:
and.w %d2,(%a0)+
___c00b7:
btst #9,%d0
beq.s ___a00b8
or.w %d1,(%a0)+
bra.s ___c00b8
___a00b8:
and.w %d2,(%a0)+
___c00b8:
btst #8,%d0
beq.s ___a00b9
or.w %d1,(%a0)+
bra.s ___c00b9
___a00b9:
and.w %d2,(%a0)+
___c00b9:
btst #6,%d0
beq.s ___a00ba
or.w %d1,(%a0)+
bra.s ___c00ba
___a00ba:
and.w %d2,(%a0)+
___c00ba:
btst #4,%d0
beq.s ___a00bb
or.w %d1,(%a0)+
bra.s ___c00bb
___a00bb:
and.w %d2,(%a0)+
___c00bb:
btst #3,%d0
beq.s ___a00bc
or.w %d1,(%a0)+
bra.s ___c00bc
___a00bc:
and.w %d2,(%a0)+
___c00bc:
btst #1,%d0
beq.s ___a00bd
or.w %d1,(%a0)+
rts
___a00bd:
and.w %d2,(%a0)+
rts
__scale040:
tst.l %d0
bpl.s ___a00be
or.w %d1,(%a0)+
bra.s ___c00be
___a00be:
and.w %d2,(%a0)+
___c00be:
btst #30,%d0
beq.s ___a00bf
or.w %d1,(%a0)+
bra.s ___c00bf
___a00bf:
and.w %d2,(%a0)+
___c00bf:
btst #28,%d0
beq.s ___a00c0
or.w %d1,(%a0)+
bra.s ___c00c0
___a00c0:
and.w %d2,(%a0)+
___c00c0:
btst #27,%d0
beq.s ___a00c1
or.w %d1,(%a0)+
bra.s ___c00c1
___a00c1:
and.w %d2,(%a0)+
___c00c1:
btst #25,%d0
beq.s ___a00c2
or.w %d1,(%a0)+
bra.s ___c00c2
___a00c2:
and.w %d2,(%a0)+
___c00c2:
btst #23,%d0
beq.s ___a00c3
or.w %d1,(%a0)+
bra.s ___c00c3
___a00c3:
and.w %d2,(%a0)+
___c00c3:
btst #22,%d0
beq.s ___a00c4
or.w %d1,(%a0)+
bra.s ___c00c4
___a00c4:
and.w %d2,(%a0)+
___c00c4:
btst #20,%d0
beq.s ___a00c5
or.w %d1,(%a0)+
bra.s ___c00c5
___a00c5:
and.w %d2,(%a0)+
___c00c5:
btst #19,%d0
beq.s ___a00c6
or.w %d1,(%a0)+
bra.s ___c00c6
___a00c6:
and.w %d2,(%a0)+
___c00c6:
btst #17,%d0
beq.s ___a00c7
or.w %d1,(%a0)+
bra.s ___c00c7
___a00c7:
and.w %d2,(%a0)+
___c00c7:
tst.w %d0
bpl.s ___a00c8
or.w %d1,(%a0)+
bra.s ___c00c8
___a00c8:
and.w %d2,(%a0)+
___c00c8:
btst #14,%d0
beq.s ___a00c9
or.w %d1,(%a0)+
bra.s ___c00c9
___a00c9:
and.w %d2,(%a0)+
___c00c9:
btst #12,%d0
beq.s ___a00ca
or.w %d1,(%a0)+
bra.s ___c00ca
___a00ca:
and.w %d2,(%a0)+
___c00ca:
btst #10,%d0
beq.s ___a00cb
or.w %d1,(%a0)+
bra.s ___c00cb
___a00cb:
and.w %d2,(%a0)+
___c00cb:
btst #9,%d0
beq.s ___a00cc
or.w %d1,(%a0)+
bra.s ___c00cc
___a00cc:
and.w %d2,(%a0)+
___c00cc:
tst.b %d0
bpl.s ___a00cd
or.w %d1,(%a0)+
bra.s ___c00cd
___a00cd:
and.w %d2,(%a0)+
___c00cd:
btst #6,%d0
beq.s ___a00ce
or.w %d1,(%a0)+
bra.s ___c00ce
___a00ce:
and.w %d2,(%a0)+
___c00ce:
btst #4,%d0
beq.s ___a00cf
or.w %d1,(%a0)+
bra.s ___c00cf
___a00cf:
and.w %d2,(%a0)+
___c00cf:
btst #2,%d0
beq.s ___a00d0
or.w %d1,(%a0)+
bra.s ___c00d0
___a00d0:
and.w %d2,(%a0)+
___c00d0:
btst #1,%d0
beq.s ___a00d1
or.w %d1,(%a0)+
rts
___a00d1:
and.w %d2,(%a0)+
rts
__scale042:
tst.l %d0
bpl.s ___a00d2
or.w %d1,(%a0)+
bra.s ___c00d2
___a00d2:
and.w %d2,(%a0)+
___c00d2:
btst #30,%d0
beq.s ___a00d3
or.w %d1,(%a0)+
bra.s ___c00d3
___a00d3:
and.w %d2,(%a0)+
___c00d3:
btst #28,%d0
beq.s ___a00d4
or.w %d1,(%a0)+
bra.s ___c00d4
___a00d4:
and.w %d2,(%a0)+
___c00d4:
btst #27,%d0
beq.s ___a00d5
or.w %d1,(%a0)+
bra.s ___c00d5
___a00d5:
and.w %d2,(%a0)+
___c00d5:
btst #25,%d0
beq.s ___a00d6
or.w %d1,(%a0)+
bra.s ___c00d6
___a00d6:
and.w %d2,(%a0)+
___c00d6:
btst #24,%d0
beq.s ___a00d7
or.w %d1,(%a0)+
bra.s ___c00d7
___a00d7:
and.w %d2,(%a0)+
___c00d7:
btst #22,%d0
beq.s ___a00d8
or.w %d1,(%a0)+
bra.s ___c00d8
___a00d8:
and.w %d2,(%a0)+
___c00d8:
btst #21,%d0
beq.s ___a00d9
or.w %d1,(%a0)+
bra.s ___c00d9
___a00d9:
and.w %d2,(%a0)+
___c00d9:
btst #19,%d0
beq.s ___a00da
or.w %d1,(%a0)+
bra.s ___c00da
___a00da:
and.w %d2,(%a0)+
___c00da:
btst #18,%d0
beq.s ___a00db
or.w %d1,(%a0)+
bra.s ___c00db
___a00db:
and.w %d2,(%a0)+
___c00db:
btst #16,%d0
beq.s ___a00dc
or.w %d1,(%a0)+
bra.s ___c00dc
___a00dc:
and.w %d2,(%a0)+
___c00dc:
tst.w %d0
bpl.s ___a00dd
or.w %d1,(%a0)+
bra.s ___c00dd
___a00dd:
and.w %d2,(%a0)+
___c00dd:
btst #13,%d0
beq.s ___a00de
or.w %d1,(%a0)+
bra.s ___c00de
___a00de:
and.w %d2,(%a0)+
___c00de:
btst #12,%d0
beq.s ___a00df
or.w %d1,(%a0)+
bra.s ___c00df
___a00df:
and.w %d2,(%a0)+
___c00df:
btst #10,%d0
beq.s ___a00e0
or.w %d1,(%a0)+
bra.s ___c00e0
___a00e0:
and.w %d2,(%a0)+
___c00e0:
btst #8,%d0
beq.s ___a00e1
or.w %d1,(%a0)+
bra.s ___c00e1
___a00e1:
and.w %d2,(%a0)+
___c00e1:
tst.b %d0
bpl.s ___a00e2
or.w %d1,(%a0)+
bra.s ___c00e2
___a00e2:
and.w %d2,(%a0)+
___c00e2:
btst #5,%d0
beq.s ___a00e3
or.w %d1,(%a0)+
bra.s ___c00e3
___a00e3:
and.w %d2,(%a0)+
___c00e3:
btst #4,%d0
beq.s ___a00e4
or.w %d1,(%a0)+
bra.s ___c00e4
___a00e4:
and.w %d2,(%a0)+
___c00e4:
btst #2,%d0
beq.s ___a00e5
or.w %d1,(%a0)+
bra.s ___c00e5
___a00e5:
and.w %d2,(%a0)+
___c00e5:
btst #1,%d0
beq.s ___a00e6
or.w %d1,(%a0)+
rts
___a00e6:
and.w %d2,(%a0)+
rts
__scale044:
tst.l %d0
bpl.s ___a00e7
or.w %d1,(%a0)+
bra.s ___c00e7
___a00e7:
and.w %d2,(%a0)+
___c00e7:
btst #30,%d0
beq.s ___a00e8
or.w %d1,(%a0)+
bra.s ___c00e8
___a00e8:
and.w %d2,(%a0)+
___c00e8:
btst #29,%d0
beq.s ___a00e9
or.w %d1,(%a0)+
bra.s ___c00e9
___a00e9:
and.w %d2,(%a0)+
___c00e9:
btst #27,%d0
beq.s ___a00ea
or.w %d1,(%a0)+
bra.s ___c00ea
___a00ea:
and.w %d2,(%a0)+
___c00ea:
btst #26,%d0
beq.s ___a00eb
or.w %d1,(%a0)+
bra.s ___c00eb
___a00eb:
and.w %d2,(%a0)+
___c00eb:
btst #24,%d0
beq.s ___a00ec
or.w %d1,(%a0)+
bra.s ___c00ec
___a00ec:
and.w %d2,(%a0)+
___c00ec:
btst #23,%d0
beq.s ___a00ed
or.w %d1,(%a0)+
bra.s ___c00ed
___a00ed:
and.w %d2,(%a0)+
___c00ed:
btst #21,%d0
beq.s ___a00ee
or.w %d1,(%a0)+
bra.s ___c00ee
___a00ee:
and.w %d2,(%a0)+
___c00ee:
btst #20,%d0
beq.s ___a00ef
or.w %d1,(%a0)+
bra.s ___c00ef
___a00ef:
and.w %d2,(%a0)+
___c00ef:
btst #18,%d0
beq.s ___a00f0
or.w %d1,(%a0)+
bra.s ___c00f0
___a00f0:
and.w %d2,(%a0)+
___c00f0:
btst #17,%d0
beq.s ___a00f1
or.w %d1,(%a0)+
bra.s ___c00f1
___a00f1:
and.w %d2,(%a0)+
___c00f1:
tst.w %d0
bpl.s ___a00f2
or.w %d1,(%a0)+
bra.s ___c00f2
___a00f2:
and.w %d2,(%a0)+
___c00f2:
btst #14,%d0
beq.s ___a00f3
or.w %d1,(%a0)+
bra.s ___c00f3
___a00f3:
and.w %d2,(%a0)+
___c00f3:
btst #12,%d0
beq.s ___a00f4
or.w %d1,(%a0)+
bra.s ___c00f4
___a00f4:
and.w %d2,(%a0)+
___c00f4:
btst #11,%d0
beq.s ___a00f5
or.w %d1,(%a0)+
bra.s ___c00f5
___a00f5:
and.w %d2,(%a0)+
___c00f5:
btst #10,%d0
beq.s ___a00f6
or.w %d1,(%a0)+
bra.s ___c00f6
___a00f6:
and.w %d2,(%a0)+
___c00f6:
btst #8,%d0
beq.s ___a00f7
or.w %d1,(%a0)+
bra.s ___c00f7
___a00f7:
and.w %d2,(%a0)+
___c00f7:
tst.b %d0
bpl.s ___a00f8
or.w %d1,(%a0)+
bra.s ___c00f8
___a00f8:
and.w %d2,(%a0)+
___c00f8:
btst #5,%d0
beq.s ___a00f9
or.w %d1,(%a0)+
bra.s ___c00f9
___a00f9:
and.w %d2,(%a0)+
___c00f9:
btst #4,%d0
beq.s ___a00fa
or.w %d1,(%a0)+
bra.s ___c00fa
___a00fa:
and.w %d2,(%a0)+
___c00fa:
btst #2,%d0
beq.s ___a00fb
or.w %d1,(%a0)+
bra.s ___c00fb
___a00fb:
and.w %d2,(%a0)+
___c00fb:
btst #1,%d0
beq.s ___a00fc
or.w %d1,(%a0)+
rts
___a00fc:
and.w %d2,(%a0)+
rts
__scale046:
tst.l %d0
bpl.s ___a00fd
or.w %d1,(%a0)+
bra.s ___c00fd
___a00fd:
and.w %d2,(%a0)+
___c00fd:
btst #30,%d0
beq.s ___a00fe
or.w %d1,(%a0)+
bra.s ___c00fe
___a00fe:
and.w %d2,(%a0)+
___c00fe:
btst #29,%d0
beq.s ___a00ff
or.w %d1,(%a0)+
bra.s ___c00ff
___a00ff:
and.w %d2,(%a0)+
___c00ff:
btst #27,%d0
beq.s ___a0100
or.w %d1,(%a0)+
bra.s ___c0100
___a0100:
and.w %d2,(%a0)+
___c0100:
btst #26,%d0
beq.s ___a0101
or.w %d1,(%a0)+
bra.s ___c0101
___a0101:
and.w %d2,(%a0)+
___c0101:
btst #24,%d0
beq.s ___a0102
or.w %d1,(%a0)+
bra.s ___c0102
___a0102:
and.w %d2,(%a0)+
___c0102:
btst #23,%d0
beq.s ___a0103
or.w %d1,(%a0)+
bra.s ___c0103
___a0103:
and.w %d2,(%a0)+
___c0103:
btst #22,%d0
beq.s ___a0104
or.w %d1,(%a0)+
bra.s ___c0104
___a0104:
and.w %d2,(%a0)+
___c0104:
btst #20,%d0
beq.s ___a0105
or.w %d1,(%a0)+
bra.s ___c0105
___a0105:
and.w %d2,(%a0)+
___c0105:
btst #19,%d0
beq.s ___a0106
or.w %d1,(%a0)+
bra.s ___c0106
___a0106:
and.w %d2,(%a0)+
___c0106:
btst #17,%d0
beq.s ___a0107
or.w %d1,(%a0)+
bra.s ___c0107
___a0107:
and.w %d2,(%a0)+
___c0107:
btst #16,%d0
beq.s ___a0108
or.w %d1,(%a0)+
bra.s ___c0108
___a0108:
and.w %d2,(%a0)+
___c0108:
tst.w %d0
bpl.s ___a0109
or.w %d1,(%a0)+
bra.s ___c0109
___a0109:
and.w %d2,(%a0)+
___c0109:
btst #13,%d0
beq.s ___a010a
or.w %d1,(%a0)+
bra.s ___c010a
___a010a:
and.w %d2,(%a0)+
___c010a:
btst #12,%d0
beq.s ___a010b
or.w %d1,(%a0)+
bra.s ___c010b
___a010b:
and.w %d2,(%a0)+
___c010b:
btst #11,%d0
beq.s ___a010c
or.w %d1,(%a0)+
bra.s ___c010c
___a010c:
and.w %d2,(%a0)+
___c010c:
btst #9,%d0
beq.s ___a010d
or.w %d1,(%a0)+
bra.s ___c010d
___a010d:
and.w %d2,(%a0)+
___c010d:
btst #8,%d0
beq.s ___a010e
or.w %d1,(%a0)+
bra.s ___c010e
___a010e:
and.w %d2,(%a0)+
___c010e:
btst #6,%d0
beq.s ___a010f
or.w %d1,(%a0)+
bra.s ___c010f
___a010f:
and.w %d2,(%a0)+
___c010f:
btst #5,%d0
beq.s ___a0110
or.w %d1,(%a0)+
bra.s ___c0110
___a0110:
and.w %d2,(%a0)+
___c0110:
btst #4,%d0
beq.s ___a0111
or.w %d1,(%a0)+
bra.s ___c0111
___a0111:
and.w %d2,(%a0)+
___c0111:
btst #2,%d0
beq.s ___a0112
or.w %d1,(%a0)+
bra.s ___c0112
___a0112:
and.w %d2,(%a0)+
___c0112:
btst #1,%d0
beq.s ___a0113
or.w %d1,(%a0)+
rts
___a0113:
and.w %d2,(%a0)+
rts
__scale048:
tst.l %d0
bpl.s ___a0114
or.w %d1,(%a0)+
bra.s ___c0114
___a0114:
and.w %d2,(%a0)+
___c0114:
btst #30,%d0
beq.s ___a0115
or.w %d1,(%a0)+
bra.s ___c0115
___a0115:
and.w %d2,(%a0)+
___c0115:
btst #29,%d0
beq.s ___a0116
or.w %d1,(%a0)+
bra.s ___c0116
___a0116:
and.w %d2,(%a0)+
___c0116:
btst #27,%d0
beq.s ___a0117
or.w %d1,(%a0)+
bra.s ___c0117
___a0117:
and.w %d2,(%a0)+
___c0117:
btst #26,%d0
beq.s ___a0118
or.w %d1,(%a0)+
bra.s ___c0118
___a0118:
and.w %d2,(%a0)+
___c0118:
btst #25,%d0
beq.s ___a0119
or.w %d1,(%a0)+
bra.s ___c0119
___a0119:
and.w %d2,(%a0)+
___c0119:
btst #23,%d0
beq.s ___a011a
or.w %d1,(%a0)+
bra.s ___c011a
___a011a:
and.w %d2,(%a0)+
___c011a:
btst #22,%d0
beq.s ___a011b
or.w %d1,(%a0)+
bra.s ___c011b
___a011b:
and.w %d2,(%a0)+
___c011b:
btst #21,%d0
beq.s ___a011c
or.w %d1,(%a0)+
bra.s ___c011c
___a011c:
and.w %d2,(%a0)+
___c011c:
btst #19,%d0
beq.s ___a011d
or.w %d1,(%a0)+
bra.s ___c011d
___a011d:
and.w %d2,(%a0)+
___c011d:
btst #18,%d0
beq.s ___a011e
or.w %d1,(%a0)+
bra.s ___c011e
___a011e:
and.w %d2,(%a0)+
___c011e:
btst #17,%d0
beq.s ___a011f
or.w %d1,(%a0)+
bra.s ___c011f
___a011f:
and.w %d2,(%a0)+
___c011f:
tst.w %d0
bpl.s ___a0120
or.w %d1,(%a0)+
bra.s ___c0120
___a0120:
and.w %d2,(%a0)+
___c0120:
btst #14,%d0
beq.s ___a0121
or.w %d1,(%a0)+
bra.s ___c0121
___a0121:
and.w %d2,(%a0)+
___c0121:
btst #13,%d0
beq.s ___a0122
or.w %d1,(%a0)+
bra.s ___c0122
___a0122:
and.w %d2,(%a0)+
___c0122:
btst #11,%d0
beq.s ___a0123
or.w %d1,(%a0)+
bra.s ___c0123
___a0123:
and.w %d2,(%a0)+
___c0123:
btst #10,%d0
beq.s ___a0124
or.w %d1,(%a0)+
bra.s ___c0124
___a0124:
and.w %d2,(%a0)+
___c0124:
btst #9,%d0
beq.s ___a0125
or.w %d1,(%a0)+
bra.s ___c0125
___a0125:
and.w %d2,(%a0)+
___c0125:
tst.b %d0
bpl.s ___a0126
or.w %d1,(%a0)+
bra.s ___c0126
___a0126:
and.w %d2,(%a0)+
___c0126:
btst #6,%d0
beq.s ___a0127
or.w %d1,(%a0)+
bra.s ___c0127
___a0127:
and.w %d2,(%a0)+
___c0127:
btst #5,%d0
beq.s ___a0128
or.w %d1,(%a0)+
bra.s ___c0128
___a0128:
and.w %d2,(%a0)+
___c0128:
btst #3,%d0
beq.s ___a0129
or.w %d1,(%a0)+
bra.s ___c0129
___a0129:
and.w %d2,(%a0)+
___c0129:
btst #2,%d0
beq.s ___a012a
or.w %d1,(%a0)+
bra.s ___c012a
___a012a:
and.w %d2,(%a0)+
___c012a:
btst #1,%d0
beq.s ___a012b
or.w %d1,(%a0)+
rts
___a012b:
and.w %d2,(%a0)+
rts
__scale050:
tst.l %d0
bpl.s ___a012c
or.w %d1,(%a0)+
bra.s ___c012c
___a012c:
and.w %d2,(%a0)+
___c012c:
btst #30,%d0
beq.s ___a012d
or.w %d1,(%a0)+
bra.s ___c012d
___a012d:
and.w %d2,(%a0)+
___c012d:
btst #29,%d0
beq.s ___a012e
or.w %d1,(%a0)+
bra.s ___c012e
___a012e:
and.w %d2,(%a0)+
___c012e:
btst #28,%d0
beq.s ___a012f
or.w %d1,(%a0)+
bra.s ___c012f
___a012f:
and.w %d2,(%a0)+
___c012f:
btst #26,%d0
beq.s ___a0130
or.w %d1,(%a0)+
bra.s ___c0130
___a0130:
and.w %d2,(%a0)+
___c0130:
btst #25,%d0
beq.s ___a0131
or.w %d1,(%a0)+
bra.s ___c0131
___a0131:
and.w %d2,(%a0)+
___c0131:
btst #24,%d0
beq.s ___a0132
or.w %d1,(%a0)+
bra.s ___c0132
___a0132:
and.w %d2,(%a0)+
___c0132:
btst #22,%d0
beq.s ___a0133
or.w %d1,(%a0)+
bra.s ___c0133
___a0133:
and.w %d2,(%a0)+
___c0133:
btst #21,%d0
beq.s ___a0134
or.w %d1,(%a0)+
bra.s ___c0134
___a0134:
and.w %d2,(%a0)+
___c0134:
btst #20,%d0
beq.s ___a0135
or.w %d1,(%a0)+
bra.s ___c0135
___a0135:
and.w %d2,(%a0)+
___c0135:
btst #19,%d0
beq.s ___a0136
or.w %d1,(%a0)+
bra.s ___c0136
___a0136:
and.w %d2,(%a0)+
___c0136:
btst #17,%d0
beq.s ___a0137
or.w %d1,(%a0)+
bra.s ___c0137
___a0137:
and.w %d2,(%a0)+
___c0137:
btst #16,%d0
beq.s ___a0138
or.w %d1,(%a0)+
bra.s ___c0138
___a0138:
and.w %d2,(%a0)+
___c0138:
tst.w %d0
bpl.s ___a0139
or.w %d1,(%a0)+
bra.s ___c0139
___a0139:
and.w %d2,(%a0)+
___c0139:
btst #13,%d0
beq.s ___a013a
or.w %d1,(%a0)+
bra.s ___c013a
___a013a:
and.w %d2,(%a0)+
___c013a:
btst #12,%d0
beq.s ___a013b
or.w %d1,(%a0)+
bra.s ___c013b
___a013b:
and.w %d2,(%a0)+
___c013b:
btst #11,%d0
beq.s ___a013c
or.w %d1,(%a0)+
bra.s ___c013c
___a013c:
and.w %d2,(%a0)+
___c013c:
btst #10,%d0
beq.s ___a013d
or.w %d1,(%a0)+
bra.s ___c013d
___a013d:
and.w %d2,(%a0)+
___c013d:
btst #8,%d0
beq.s ___a013e
or.w %d1,(%a0)+
bra.s ___c013e
___a013e:
and.w %d2,(%a0)+
___c013e:
tst.b %d0
bpl.s ___a013f
or.w %d1,(%a0)+
bra.s ___c013f
___a013f:
and.w %d2,(%a0)+
___c013f:
btst #6,%d0
beq.s ___a0140
or.w %d1,(%a0)+
bra.s ___c0140
___a0140:
and.w %d2,(%a0)+
___c0140:
btst #5,%d0
beq.s ___a0141
or.w %d1,(%a0)+
bra.s ___c0141
___a0141:
and.w %d2,(%a0)+
___c0141:
btst #3,%d0
beq.s ___a0142
or.w %d1,(%a0)+
bra.s ___c0142
___a0142:
and.w %d2,(%a0)+
___c0142:
btst #2,%d0
beq.s ___a0143
or.w %d1,(%a0)+
bra.s ___c0143
___a0143:
and.w %d2,(%a0)+
___c0143:
btst #1,%d0
beq.s ___a0144
or.w %d1,(%a0)+
rts
___a0144:
and.w %d2,(%a0)+
rts
__scale052:
tst.l %d0
bpl.s ___a0145
or.w %d1,(%a0)+
bra.s ___c0145
___a0145:
and.w %d2,(%a0)+
___c0145:
btst #30,%d0
beq.s ___a0146
or.w %d1,(%a0)+
bra.s ___c0146
___a0146:
and.w %d2,(%a0)+
___c0146:
btst #29,%d0
beq.s ___a0147
or.w %d1,(%a0)+
bra.s ___c0147
___a0147:
and.w %d2,(%a0)+
___c0147:
btst #28,%d0
beq.s ___a0148
or.w %d1,(%a0)+
bra.s ___c0148
___a0148:
and.w %d2,(%a0)+
___c0148:
btst #27,%d0
beq.s ___a0149
or.w %d1,(%a0)+
bra.s ___c0149
___a0149:
and.w %d2,(%a0)+
___c0149:
btst #25,%d0
beq.s ___a014a
or.w %d1,(%a0)+
bra.s ___c014a
___a014a:
and.w %d2,(%a0)+
___c014a:
btst #24,%d0
beq.s ___a014b
or.w %d1,(%a0)+
bra.s ___c014b
___a014b:
and.w %d2,(%a0)+
___c014b:
btst #23,%d0
beq.s ___a014c
or.w %d1,(%a0)+
bra.s ___c014c
___a014c:
and.w %d2,(%a0)+
___c014c:
btst #22,%d0
beq.s ___a014d
or.w %d1,(%a0)+
bra.s ___c014d
___a014d:
and.w %d2,(%a0)+
___c014d:
btst #20,%d0
beq.s ___a014e
or.w %d1,(%a0)+
bra.s ___c014e
___a014e:
and.w %d2,(%a0)+
___c014e:
btst #19,%d0
beq.s ___a014f
or.w %d1,(%a0)+
bra.s ___c014f
___a014f:
and.w %d2,(%a0)+
___c014f:
btst #18,%d0
beq.s ___a0150
or.w %d1,(%a0)+
bra.s ___c0150
___a0150:
and.w %d2,(%a0)+
___c0150:
btst #17,%d0
beq.s ___a0151
or.w %d1,(%a0)+
bra.s ___c0151
___a0151:
and.w %d2,(%a0)+
___c0151:
tst.w %d0
bpl.s ___a0152
or.w %d1,(%a0)+
bra.s ___c0152
___a0152:
and.w %d2,(%a0)+
___c0152:
btst #14,%d0
beq.s ___a0153
or.w %d1,(%a0)+
bra.s ___c0153
___a0153:
and.w %d2,(%a0)+
___c0153:
btst #13,%d0
beq.s ___a0154
or.w %d1,(%a0)+
bra.s ___c0154
___a0154:
and.w %d2,(%a0)+
___c0154:
btst #12,%d0
beq.s ___a0155
or.w %d1,(%a0)+
bra.s ___c0155
___a0155:
and.w %d2,(%a0)+
___c0155:
btst #11,%d0
beq.s ___a0156
or.w %d1,(%a0)+
bra.s ___c0156
___a0156:
and.w %d2,(%a0)+
___c0156:
btst #9,%d0
beq.s ___a0157
or.w %d1,(%a0)+
bra.s ___c0157
___a0157:
and.w %d2,(%a0)+
___c0157:
btst #8,%d0
beq.s ___a0158
or.w %d1,(%a0)+
bra.s ___c0158
___a0158:
and.w %d2,(%a0)+
___c0158:
tst.b %d0
bpl.s ___a0159
or.w %d1,(%a0)+
bra.s ___c0159
___a0159:
and.w %d2,(%a0)+
___c0159:
btst #6,%d0
beq.s ___a015a
or.w %d1,(%a0)+
bra.s ___c015a
___a015a:
and.w %d2,(%a0)+
___c015a:
btst #4,%d0
beq.s ___a015b
or.w %d1,(%a0)+
bra.s ___c015b
___a015b:
and.w %d2,(%a0)+
___c015b:
btst #3,%d0
beq.s ___a015c
or.w %d1,(%a0)+
bra.s ___c015c
___a015c:
and.w %d2,(%a0)+
___c015c:
btst #2,%d0
beq.s ___a015d
or.w %d1,(%a0)+
bra.s ___c015d
___a015d:
and.w %d2,(%a0)+
___c015d:
btst #1,%d0
beq.s ___a015e
or.w %d1,(%a0)+
rts
___a015e:
and.w %d2,(%a0)+
rts
__scale054:
tst.l %d0
bpl.s ___a015f
or.w %d1,(%a0)+
bra.s ___c015f
___a015f:
and.w %d2,(%a0)+
___c015f:
btst #30,%d0
beq.s ___a0160
or.w %d1,(%a0)+
bra.s ___c0160
___a0160:
and.w %d2,(%a0)+
___c0160:
btst #29,%d0
beq.s ___a0161
or.w %d1,(%a0)+
bra.s ___c0161
___a0161:
and.w %d2,(%a0)+
___c0161:
btst #28,%d0
beq.s ___a0162
or.w %d1,(%a0)+
bra.s ___c0162
___a0162:
and.w %d2,(%a0)+
___c0162:
btst #27,%d0
beq.s ___a0163
or.w %d1,(%a0)+
bra.s ___c0163
___a0163:
and.w %d2,(%a0)+
___c0163:
btst #26,%d0
beq.s ___a0164
or.w %d1,(%a0)+
bra.s ___c0164
___a0164:
and.w %d2,(%a0)+
___c0164:
btst #24,%d0
beq.s ___a0165
or.w %d1,(%a0)+
bra.s ___c0165
___a0165:
and.w %d2,(%a0)+
___c0165:
btst #23,%d0
beq.s ___a0166
or.w %d1,(%a0)+
bra.s ___c0166
___a0166:
and.w %d2,(%a0)+
___c0166:
btst #22,%d0
beq.s ___a0167
or.w %d1,(%a0)+
bra.s ___c0167
___a0167:
and.w %d2,(%a0)+
___c0167:
btst #21,%d0
beq.s ___a0168
or.w %d1,(%a0)+
bra.s ___c0168
___a0168:
and.w %d2,(%a0)+
___c0168:
btst #20,%d0
beq.s ___a0169
or.w %d1,(%a0)+
bra.s ___c0169
___a0169:
and.w %d2,(%a0)+
___c0169:
btst #18,%d0
beq.s ___a016a
or.w %d1,(%a0)+
bra.s ___c016a
___a016a:
and.w %d2,(%a0)+
___c016a:
btst #17,%d0
beq.s ___a016b
or.w %d1,(%a0)+
bra.s ___c016b
___a016b:
and.w %d2,(%a0)+
___c016b:
btst #16,%d0
beq.s ___a016c
or.w %d1,(%a0)+
bra.s ___c016c
___a016c:
and.w %d2,(%a0)+
___c016c:
tst.w %d0
bpl.s ___a016d
or.w %d1,(%a0)+
bra.s ___c016d
___a016d:
and.w %d2,(%a0)+
___c016d:
btst #14,%d0
beq.s ___a016e
or.w %d1,(%a0)+
bra.s ___c016e
___a016e:
and.w %d2,(%a0)+
___c016e:
btst #12,%d0
beq.s ___a016f
or.w %d1,(%a0)+
bra.s ___c016f
___a016f:
and.w %d2,(%a0)+
___c016f:
btst #11,%d0
beq.s ___a0170
or.w %d1,(%a0)+
bra.s ___c0170
___a0170:
and.w %d2,(%a0)+
___c0170:
btst #10,%d0
beq.s ___a0171
or.w %d1,(%a0)+
bra.s ___c0171
___a0171:
and.w %d2,(%a0)+
___c0171:
btst #9,%d0
beq.s ___a0172
or.w %d1,(%a0)+
bra.s ___c0172
___a0172:
and.w %d2,(%a0)+
___c0172:
btst #8,%d0
beq.s ___a0173
or.w %d1,(%a0)+
bra.s ___c0173
___a0173:
and.w %d2,(%a0)+
___c0173:
tst.b %d0
bpl.s ___a0174
or.w %d1,(%a0)+
bra.s ___c0174
___a0174:
and.w %d2,(%a0)+
___c0174:
btst #5,%d0
beq.s ___a0175
or.w %d1,(%a0)+
bra.s ___c0175
___a0175:
and.w %d2,(%a0)+
___c0175:
btst #4,%d0
beq.s ___a0176
or.w %d1,(%a0)+
bra.s ___c0176
___a0176:
and.w %d2,(%a0)+
___c0176:
btst #3,%d0
beq.s ___a0177
or.w %d1,(%a0)+
bra.s ___c0177
___a0177:
and.w %d2,(%a0)+
___c0177:
btst #2,%d0
beq.s ___a0178
or.w %d1,(%a0)+
bra.s ___c0178
___a0178:
and.w %d2,(%a0)+
___c0178:
btst #1,%d0
beq.s ___a0179
or.w %d1,(%a0)+
rts
___a0179:
and.w %d2,(%a0)+
rts
__scale056:
tst.l %d0
bpl.s ___a017a
or.w %d1,(%a0)+
bra.s ___c017a
___a017a:
and.w %d2,(%a0)+
___c017a:
btst #30,%d0
beq.s ___a017b
or.w %d1,(%a0)+
bra.s ___c017b
___a017b:
and.w %d2,(%a0)+
___c017b:
btst #29,%d0
beq.s ___a017c
or.w %d1,(%a0)+
bra.s ___c017c
___a017c:
and.w %d2,(%a0)+
___c017c:
btst #28,%d0
beq.s ___a017d
or.w %d1,(%a0)+
bra.s ___c017d
___a017d:
and.w %d2,(%a0)+
___c017d:
btst #27,%d0
beq.s ___a017e
or.w %d1,(%a0)+
bra.s ___c017e
___a017e:
and.w %d2,(%a0)+
___c017e:
btst #26,%d0
beq.s ___a017f
or.w %d1,(%a0)+
bra.s ___c017f
___a017f:
and.w %d2,(%a0)+
___c017f:
btst #25,%d0
beq.s ___a0180
or.w %d1,(%a0)+
bra.s ___c0180
___a0180:
and.w %d2,(%a0)+
___c0180:
btst #23,%d0
beq.s ___a0181
or.w %d1,(%a0)+
bra.s ___c0181
___a0181:
and.w %d2,(%a0)+
___c0181:
btst #22,%d0
beq.s ___a0182
or.w %d1,(%a0)+
bra.s ___c0182
___a0182:
and.w %d2,(%a0)+
___c0182:
btst #21,%d0
beq.s ___a0183
or.w %d1,(%a0)+
bra.s ___c0183
___a0183:
and.w %d2,(%a0)+
___c0183:
btst #20,%d0
beq.s ___a0184
or.w %d1,(%a0)+
bra.s ___c0184
___a0184:
and.w %d2,(%a0)+
___c0184:
btst #19,%d0
beq.s ___a0185
or.w %d1,(%a0)+
bra.s ___c0185
___a0185:
and.w %d2,(%a0)+
___c0185:
btst #18,%d0
beq.s ___a0186
or.w %d1,(%a0)+
bra.s ___c0186
___a0186:
and.w %d2,(%a0)+
___c0186:
btst #17,%d0
beq.s ___a0187
or.w %d1,(%a0)+
bra.s ___c0187
___a0187:
and.w %d2,(%a0)+
___c0187:
tst.w %d0
bpl.s ___a0188
or.w %d1,(%a0)+
bra.s ___c0188
___a0188:
and.w %d2,(%a0)+
___c0188:
btst #14,%d0
beq.s ___a0189
or.w %d1,(%a0)+
bra.s ___c0189
___a0189:
and.w %d2,(%a0)+
___c0189:
btst #13,%d0
beq.s ___a018a
or.w %d1,(%a0)+
bra.s ___c018a
___a018a:
and.w %d2,(%a0)+
___c018a:
btst #12,%d0
beq.s ___a018b
or.w %d1,(%a0)+
bra.s ___c018b
___a018b:
and.w %d2,(%a0)+
___c018b:
btst #11,%d0
beq.s ___a018c
or.w %d1,(%a0)+
bra.s ___c018c
___a018c:
and.w %d2,(%a0)+
___c018c:
btst #10,%d0
beq.s ___a018d
or.w %d1,(%a0)+
bra.s ___c018d
___a018d:
and.w %d2,(%a0)+
___c018d:
btst #9,%d0
beq.s ___a018e
or.w %d1,(%a0)+
bra.s ___c018e
___a018e:
and.w %d2,(%a0)+
___c018e:
tst.b %d0
bpl.s ___a018f
or.w %d1,(%a0)+
bra.s ___c018f
___a018f:
and.w %d2,(%a0)+
___c018f:
btst #6,%d0
beq.s ___a0190
or.w %d1,(%a0)+
bra.s ___c0190
___a0190:
and.w %d2,(%a0)+
___c0190:
btst #5,%d0
beq.s ___a0191
or.w %d1,(%a0)+
bra.s ___c0191
___a0191:
and.w %d2,(%a0)+
___c0191:
btst #4,%d0
beq.s ___a0192
or.w %d1,(%a0)+
bra.s ___c0192
___a0192:
and.w %d2,(%a0)+
___c0192:
btst #3,%d0
beq.s ___a0193
or.w %d1,(%a0)+
bra.s ___c0193
___a0193:
and.w %d2,(%a0)+
___c0193:
btst #2,%d0
beq.s ___a0194
or.w %d1,(%a0)+
bra.s ___c0194
___a0194:
and.w %d2,(%a0)+
___c0194:
btst #1,%d0
beq.s ___a0195
or.w %d1,(%a0)+
rts
___a0195:
and.w %d2,(%a0)+
rts
__scale058:
tst.l %d0
bpl.s ___a0196
or.w %d1,(%a0)+
bra.s ___c0196
___a0196:
and.w %d2,(%a0)+
___c0196:
btst #30,%d0
beq.s ___a0197
or.w %d1,(%a0)+
bra.s ___c0197
___a0197:
and.w %d2,(%a0)+
___c0197:
btst #29,%d0
beq.s ___a0198
or.w %d1,(%a0)+
bra.s ___c0198
___a0198:
and.w %d2,(%a0)+
___c0198:
btst #28,%d0
beq.s ___a0199
or.w %d1,(%a0)+
bra.s ___c0199
___a0199:
and.w %d2,(%a0)+
___c0199:
btst #27,%d0
beq.s ___a019a
or.w %d1,(%a0)+
bra.s ___c019a
___a019a:
and.w %d2,(%a0)+
___c019a:
btst #26,%d0
beq.s ___a019b
or.w %d1,(%a0)+
bra.s ___c019b
___a019b:
and.w %d2,(%a0)+
___c019b:
btst #25,%d0
beq.s ___a019c
or.w %d1,(%a0)+
bra.s ___c019c
___a019c:
and.w %d2,(%a0)+
___c019c:
btst #24,%d0
beq.s ___a019d
or.w %d1,(%a0)+
bra.s ___c019d
___a019d:
and.w %d2,(%a0)+
___c019d:
btst #23,%d0
beq.s ___a019e
or.w %d1,(%a0)+
bra.s ___c019e
___a019e:
and.w %d2,(%a0)+
___c019e:
btst #22,%d0
beq.s ___a019f
or.w %d1,(%a0)+
bra.s ___c019f
___a019f:
and.w %d2,(%a0)+
___c019f:
btst #20,%d0
beq.s ___a01a0
or.w %d1,(%a0)+
bra.s ___c01a0
___a01a0:
and.w %d2,(%a0)+
___c01a0:
btst #19,%d0
beq.s ___a01a1
or.w %d1,(%a0)+
bra.s ___c01a1
___a01a1:
and.w %d2,(%a0)+
___c01a1:
btst #18,%d0
beq.s ___a01a2
or.w %d1,(%a0)+
bra.s ___c01a2
___a01a2:
and.w %d2,(%a0)+
___c01a2:
btst #17,%d0
beq.s ___a01a3
or.w %d1,(%a0)+
bra.s ___c01a3
___a01a3:
and.w %d2,(%a0)+
___c01a3:
btst #16,%d0
beq.s ___a01a4
or.w %d1,(%a0)+
bra.s ___c01a4
___a01a4:
and.w %d2,(%a0)+
___c01a4:
tst.w %d0
bpl.s ___a01a5
or.w %d1,(%a0)+
bra.s ___c01a5
___a01a5:
and.w %d2,(%a0)+
___c01a5:
btst #14,%d0
beq.s ___a01a6
or.w %d1,(%a0)+
bra.s ___c01a6
___a01a6:
and.w %d2,(%a0)+
___c01a6:
btst #13,%d0
beq.s ___a01a7
or.w %d1,(%a0)+
bra.s ___c01a7
___a01a7:
and.w %d2,(%a0)+
___c01a7:
btst #12,%d0
beq.s ___a01a8
or.w %d1,(%a0)+
bra.s ___c01a8
___a01a8:
and.w %d2,(%a0)+
___c01a8:
btst #11,%d0
beq.s ___a01a9
or.w %d1,(%a0)+
bra.s ___c01a9
___a01a9:
and.w %d2,(%a0)+
___c01a9:
btst #9,%d0
beq.s ___a01aa
or.w %d1,(%a0)+
bra.s ___c01aa
___a01aa:
and.w %d2,(%a0)+
___c01aa:
btst #8,%d0
beq.s ___a01ab
or.w %d1,(%a0)+
bra.s ___c01ab
___a01ab:
and.w %d2,(%a0)+
___c01ab:
tst.b %d0
bpl.s ___a01ac
or.w %d1,(%a0)+
bra.s ___c01ac
___a01ac:
and.w %d2,(%a0)+
___c01ac:
btst #6,%d0
beq.s ___a01ad
or.w %d1,(%a0)+
bra.s ___c01ad
___a01ad:
and.w %d2,(%a0)+
___c01ad:
btst #5,%d0
beq.s ___a01ae
or.w %d1,(%a0)+
bra.s ___c01ae
___a01ae:
and.w %d2,(%a0)+
___c01ae:
btst #4,%d0
beq.s ___a01af
or.w %d1,(%a0)+
bra.s ___c01af
___a01af:
and.w %d2,(%a0)+
___c01af:
btst #3,%d0
beq.s ___a01b0
or.w %d1,(%a0)+
bra.s ___c01b0
___a01b0:
and.w %d2,(%a0)+
___c01b0:
btst #2,%d0
beq.s ___a01b1
or.w %d1,(%a0)+
bra.s ___c01b1
___a01b1:
and.w %d2,(%a0)+
___c01b1:
btst #1,%d0
beq.s ___a01b2
or.w %d1,(%a0)+
rts
___a01b2:
and.w %d2,(%a0)+
rts
__scale060:
tst.l %d0
bpl.s ___a01b3
or.w %d1,(%a0)+
bra.s ___c01b3
___a01b3:
and.w %d2,(%a0)+
___c01b3:
btst #30,%d0
beq.s ___a01b4
or.w %d1,(%a0)+
bra.s ___c01b4
___a01b4:
and.w %d2,(%a0)+
___c01b4:
btst #29,%d0
beq.s ___a01b5
or.w %d1,(%a0)+
bra.s ___c01b5
___a01b5:
and.w %d2,(%a0)+
___c01b5:
btst #28,%d0
beq.s ___a01b6
or.w %d1,(%a0)+
bra.s ___c01b6
___a01b6:
and.w %d2,(%a0)+
___c01b6:
btst #27,%d0
beq.s ___a01b7
or.w %d1,(%a0)+
bra.s ___c01b7
___a01b7:
and.w %d2,(%a0)+
___c01b7:
btst #26,%d0
beq.s ___a01b8
or.w %d1,(%a0)+
bra.s ___c01b8
___a01b8:
and.w %d2,(%a0)+
___c01b8:
btst #25,%d0
beq.s ___a01b9
or.w %d1,(%a0)+
bra.s ___c01b9
___a01b9:
and.w %d2,(%a0)+
___c01b9:
btst #24,%d0
beq.s ___a01ba
or.w %d1,(%a0)+
bra.s ___c01ba
___a01ba:
and.w %d2,(%a0)+
___c01ba:
btst #23,%d0
beq.s ___a01bb
or.w %d1,(%a0)+
bra.s ___c01bb
___a01bb:
and.w %d2,(%a0)+
___c01bb:
btst #22,%d0
beq.s ___a01bc
or.w %d1,(%a0)+
bra.s ___c01bc
___a01bc:
and.w %d2,(%a0)+
___c01bc:
btst #21,%d0
beq.s ___a01bd
or.w %d1,(%a0)+
bra.s ___c01bd
___a01bd:
and.w %d2,(%a0)+
___c01bd:
btst #20,%d0
beq.s ___a01be
or.w %d1,(%a0)+
bra.s ___c01be
___a01be:
and.w %d2,(%a0)+
___c01be:
btst #19,%d0
beq.s ___a01bf
or.w %d1,(%a0)+
bra.s ___c01bf
___a01bf:
and.w %d2,(%a0)+
___c01bf:
btst #18,%d0
beq.s ___a01c0
or.w %d1,(%a0)+
bra.s ___c01c0
___a01c0:
and.w %d2,(%a0)+
___c01c0:
btst #17,%d0
beq.s ___a01c1
or.w %d1,(%a0)+
bra.s ___c01c1
___a01c1:
and.w %d2,(%a0)+
___c01c1:
tst.w %d0
bpl.s ___a01c2
or.w %d1,(%a0)+
bra.s ___c01c2
___a01c2:
and.w %d2,(%a0)+
___c01c2:
btst #14,%d0
beq.s ___a01c3
or.w %d1,(%a0)+
bra.s ___c01c3
___a01c3:
and.w %d2,(%a0)+
___c01c3:
btst #13,%d0
beq.s ___a01c4
or.w %d1,(%a0)+
bra.s ___c01c4
___a01c4:
and.w %d2,(%a0)+
___c01c4:
btst #12,%d0
beq.s ___a01c5
or.w %d1,(%a0)+
bra.s ___c01c5
___a01c5:
and.w %d2,(%a0)+
___c01c5:
btst #11,%d0
beq.s ___a01c6
or.w %d1,(%a0)+
bra.s ___c01c6
___a01c6:
and.w %d2,(%a0)+
___c01c6:
btst #10,%d0
beq.s ___a01c7
or.w %d1,(%a0)+
bra.s ___c01c7
___a01c7:
and.w %d2,(%a0)+
___c01c7:
btst #9,%d0
beq.s ___a01c8
or.w %d1,(%a0)+
bra.s ___c01c8
___a01c8:
and.w %d2,(%a0)+
___c01c8:
btst #8,%d0
beq.s ___a01c9
or.w %d1,(%a0)+
bra.s ___c01c9
___a01c9:
and.w %d2,(%a0)+
___c01c9:
tst.b %d0
bpl.s ___a01ca
or.w %d1,(%a0)+
bra.s ___c01ca
___a01ca:
and.w %d2,(%a0)+
___c01ca:
btst #6,%d0
beq.s ___a01cb
or.w %d1,(%a0)+
bra.s ___c01cb
___a01cb:
and.w %d2,(%a0)+
___c01cb:
btst #5,%d0
beq.s ___a01cc
or.w %d1,(%a0)+
bra.s ___c01cc
___a01cc:
and.w %d2,(%a0)+
___c01cc:
btst #4,%d0
beq.s ___a01cd
or.w %d1,(%a0)+
bra.s ___c01cd
___a01cd:
and.w %d2,(%a0)+
___c01cd:
btst #3,%d0
beq.s ___a01ce
or.w %d1,(%a0)+
bra.s ___c01ce
___a01ce:
and.w %d2,(%a0)+
___c01ce:
btst #2,%d0
beq.s ___a01cf
or.w %d1,(%a0)+
bra.s ___c01cf
___a01cf:
and.w %d2,(%a0)+
___c01cf:
btst #1,%d0
beq.s ___a01d0
or.w %d1,(%a0)+
rts
___a01d0:
and.w %d2,(%a0)+
rts
__scale062:
tst.l %d0
bpl.s ___a01d1
or.w %d1,(%a0)+
bra.s ___c01d1
___a01d1:
and.w %d2,(%a0)+
___c01d1:
btst #30,%d0
beq.s ___a01d2
or.w %d1,(%a0)+
bra.s ___c01d2
___a01d2:
and.w %d2,(%a0)+
___c01d2:
btst #29,%d0
beq.s ___a01d3
or.w %d1,(%a0)+
bra.s ___c01d3
___a01d3:
and.w %d2,(%a0)+
___c01d3:
btst #28,%d0
beq.s ___a01d4
or.w %d1,(%a0)+
bra.s ___c01d4
___a01d4:
and.w %d2,(%a0)+
___c01d4:
btst #27,%d0
beq.s ___a01d5
or.w %d1,(%a0)+
bra.s ___c01d5
___a01d5:
and.w %d2,(%a0)+
___c01d5:
btst #26,%d0
beq.s ___a01d6
or.w %d1,(%a0)+
bra.s ___c01d6
___a01d6:
and.w %d2,(%a0)+
___c01d6:
btst #25,%d0
beq.s ___a01d7
or.w %d1,(%a0)+
bra.s ___c01d7
___a01d7:
and.w %d2,(%a0)+
___c01d7:
btst #24,%d0
beq.s ___a01d8
or.w %d1,(%a0)+
bra.s ___c01d8
___a01d8:
and.w %d2,(%a0)+
___c01d8:
btst #23,%d0
beq.s ___a01d9
or.w %d1,(%a0)+
bra.s ___c01d9
___a01d9:
and.w %d2,(%a0)+
___c01d9:
btst #22,%d0
beq.s ___a01da
or.w %d1,(%a0)+
bra.s ___c01da
___a01da:
and.w %d2,(%a0)+
___c01da:
btst #21,%d0
beq.s ___a01db
or.w %d1,(%a0)+
bra.s ___c01db
___a01db:
and.w %d2,(%a0)+
___c01db:
btst #20,%d0
beq.s ___a01dc
or.w %d1,(%a0)+
bra.s ___c01dc
___a01dc:
and.w %d2,(%a0)+
___c01dc:
btst #19,%d0
beq.s ___a01dd
or.w %d1,(%a0)+
bra.s ___c01dd
___a01dd:
and.w %d2,(%a0)+
___c01dd:
btst #18,%d0
beq.s ___a01de
or.w %d1,(%a0)+
bra.s ___c01de
___a01de:
and.w %d2,(%a0)+
___c01de:
btst #17,%d0
beq.s ___a01df
or.w %d1,(%a0)+
bra.s ___c01df
___a01df:
and.w %d2,(%a0)+
___c01df:
btst #16,%d0
beq.s ___a01e0
or.w %d1,(%a0)+
bra.s ___c01e0
___a01e0:
and.w %d2,(%a0)+
___c01e0:
tst.w %d0
bpl.s ___a01e1
or.w %d1,(%a0)+
bra.s ___c01e1
___a01e1:
and.w %d2,(%a0)+
___c01e1:
btst #14,%d0
beq.s ___a01e2
or.w %d1,(%a0)+
bra.s ___c01e2
___a01e2:
and.w %d2,(%a0)+
___c01e2:
btst #13,%d0
beq.s ___a01e3
or.w %d1,(%a0)+
bra.s ___c01e3
___a01e3:
and.w %d2,(%a0)+
___c01e3:
btst #12,%d0
beq.s ___a01e4
or.w %d1,(%a0)+
bra.s ___c01e4
___a01e4:
and.w %d2,(%a0)+
___c01e4:
btst #11,%d0
beq.s ___a01e5
or.w %d1,(%a0)+
bra.s ___c01e5
___a01e5:
and.w %d2,(%a0)+
___c01e5:
btst #10,%d0
beq.s ___a01e6
or.w %d1,(%a0)+
bra.s ___c01e6
___a01e6:
and.w %d2,(%a0)+
___c01e6:
btst #9,%d0
beq.s ___a01e7
or.w %d1,(%a0)+
bra.s ___c01e7
___a01e7:
and.w %d2,(%a0)+
___c01e7:
btst #8,%d0
beq.s ___a01e8
or.w %d1,(%a0)+
bra.s ___c01e8
___a01e8:
and.w %d2,(%a0)+
___c01e8:
tst.b %d0
bpl.s ___a01e9
or.w %d1,(%a0)+
bra.s ___c01e9
___a01e9:
and.w %d2,(%a0)+
___c01e9:
btst #6,%d0
beq.s ___a01ea
or.w %d1,(%a0)+
bra.s ___c01ea
___a01ea:
and.w %d2,(%a0)+
___c01ea:
btst #5,%d0
beq.s ___a01eb
or.w %d1,(%a0)+
bra.s ___c01eb
___a01eb:
and.w %d2,(%a0)+
___c01eb:
btst #4,%d0
beq.s ___a01ec
or.w %d1,(%a0)+
bra.s ___c01ec
___a01ec:
and.w %d2,(%a0)+
___c01ec:
btst #3,%d0
beq.s ___a01ed
or.w %d1,(%a0)+
bra.s ___c01ed
___a01ed:
and.w %d2,(%a0)+
___c01ed:
btst #2,%d0
beq.s ___a01ee
or.w %d1,(%a0)+
bra.s ___c01ee
___a01ee:
and.w %d2,(%a0)+
___c01ee:
btst #1,%d0
beq.s ___a01ef
or.w %d1,(%a0)+
rts
___a01ef:
and.w %d2,(%a0)+
rts
__scale064:
tst.l %d0
bpl.s ___a01f0
or.w %d1,(%a0)+
bra.s ___c01f0
___a01f0:
and.w %d2,(%a0)+
___c01f0:
btst #30,%d0
beq.s ___a01f1
or.w %d1,(%a0)+
bra.s ___c01f1
___a01f1:
and.w %d2,(%a0)+
___c01f1:
btst #29,%d0
beq.s ___a01f2
or.w %d1,(%a0)+
bra.s ___c01f2
___a01f2:
and.w %d2,(%a0)+
___c01f2:
btst #28,%d0
beq.s ___a01f3
or.w %d1,(%a0)+
bra.s ___c01f3
___a01f3:
and.w %d2,(%a0)+
___c01f3:
btst #27,%d0
beq.s ___a01f4
or.w %d1,(%a0)+
bra.s ___c01f4
___a01f4:
and.w %d2,(%a0)+
___c01f4:
btst #26,%d0
beq.s ___a01f5
or.w %d1,(%a0)+
bra.s ___c01f5
___a01f5:
and.w %d2,(%a0)+
___c01f5:
btst #25,%d0
beq.s ___a01f6
or.w %d1,(%a0)+
bra.s ___c01f6
___a01f6:
and.w %d2,(%a0)+
___c01f6:
btst #24,%d0
beq.s ___a01f7
or.w %d1,(%a0)+
bra.s ___c01f7
___a01f7:
and.w %d2,(%a0)+
___c01f7:
btst #23,%d0
beq.s ___a01f8
or.w %d1,(%a0)+
bra.s ___c01f8
___a01f8:
and.w %d2,(%a0)+
___c01f8:
btst #22,%d0
beq.s ___a01f9
or.w %d1,(%a0)+
bra.s ___c01f9
___a01f9:
and.w %d2,(%a0)+
___c01f9:
btst #21,%d0
beq.s ___a01fa
or.w %d1,(%a0)+
bra.s ___c01fa
___a01fa:
and.w %d2,(%a0)+
___c01fa:
btst #20,%d0
beq.s ___a01fb
or.w %d1,(%a0)+
bra.s ___c01fb
___a01fb:
and.w %d2,(%a0)+
___c01fb:
btst #19,%d0
beq.s ___a01fc
or.w %d1,(%a0)+
bra.s ___c01fc
___a01fc:
and.w %d2,(%a0)+
___c01fc:
btst #18,%d0
beq.s ___a01fd
or.w %d1,(%a0)+
bra.s ___c01fd
___a01fd:
and.w %d2,(%a0)+
___c01fd:
btst #17,%d0
beq.s ___a01fe
or.w %d1,(%a0)+
bra.s ___c01fe
___a01fe:
and.w %d2,(%a0)+
___c01fe:
btst #16,%d0
beq.s ___a01ff
or.w %d1,(%a0)+
bra.s ___c01ff
___a01ff:
and.w %d2,(%a0)+
___c01ff:
tst.w %d0
bpl.s ___a0200
or.w %d1,(%a0)+
bra.s ___c0200
___a0200:
and.w %d2,(%a0)+
___c0200:
btst #14,%d0
beq.s ___a0201
or.w %d1,(%a0)+
bra.s ___c0201
___a0201:
and.w %d2,(%a0)+
___c0201:
btst #13,%d0
beq.s ___a0202
or.w %d1,(%a0)+
bra.s ___c0202
___a0202:
and.w %d2,(%a0)+
___c0202:
btst #12,%d0
beq.s ___a0203
or.w %d1,(%a0)+
bra.s ___c0203
___a0203:
and.w %d2,(%a0)+
___c0203:
btst #11,%d0
beq.s ___a0204
or.w %d1,(%a0)+
bra.s ___c0204
___a0204:
and.w %d2,(%a0)+
___c0204:
btst #10,%d0
beq.s ___a0205
or.w %d1,(%a0)+
bra.s ___c0205
___a0205:
and.w %d2,(%a0)+
___c0205:
btst #9,%d0
beq.s ___a0206
or.w %d1,(%a0)+
bra.s ___c0206
___a0206:
and.w %d2,(%a0)+
___c0206:
btst #8,%d0
beq.s ___a0207
or.w %d1,(%a0)+
bra.s ___c0207
___a0207:
and.w %d2,(%a0)+
___c0207:
tst.b %d0
bpl.s ___a0208
or.w %d1,(%a0)+
bra.s ___c0208
___a0208:
and.w %d2,(%a0)+
___c0208:
btst #6,%d0
beq.s ___a0209
or.w %d1,(%a0)+
bra.s ___c0209
___a0209:
and.w %d2,(%a0)+
___c0209:
btst #5,%d0
beq.s ___a020a
or.w %d1,(%a0)+
bra.s ___c020a
___a020a:
and.w %d2,(%a0)+
___c020a:
btst #4,%d0
beq.s ___a020b
or.w %d1,(%a0)+
bra.s ___c020b
___a020b:
and.w %d2,(%a0)+
___c020b:
btst #3,%d0
beq.s ___a020c
or.w %d1,(%a0)+
bra.s ___c020c
___a020c:
and.w %d2,(%a0)+
___c020c:
btst #2,%d0
beq.s ___a020d
or.w %d1,(%a0)+
bra.s ___c020d
___a020d:
and.w %d2,(%a0)+
___c020d:
btst #1,%d0
beq.s ___a020e
or.w %d1,(%a0)+
bra.s ___c020e
___a020e:
and.w %d2,(%a0)+
___c020e:
btst #0,%d0
beq.s ___a020f
or.w %d1,(%a0)+
rts
___a020f:
and.w %d2,(%a0)+
rts
__scale066:
tst.l %d0
bpl.s ___a0210
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0210
___a0210:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0210:
btst #30,%d0
beq.s ___a0211
or.w %d1,(%a0)+
bra.s ___c0211
___a0211:
and.w %d2,(%a0)+
___c0211:
btst #29,%d0
beq.s ___a0212
or.w %d1,(%a0)+
bra.s ___c0212
___a0212:
and.w %d2,(%a0)+
___c0212:
btst #28,%d0
beq.s ___a0213
or.w %d1,(%a0)+
bra.s ___c0213
___a0213:
and.w %d2,(%a0)+
___c0213:
btst #27,%d0
beq.s ___a0214
or.w %d1,(%a0)+
bra.s ___c0214
___a0214:
and.w %d2,(%a0)+
___c0214:
btst #26,%d0
beq.s ___a0215
or.w %d1,(%a0)+
bra.s ___c0215
___a0215:
and.w %d2,(%a0)+
___c0215:
btst #25,%d0
beq.s ___a0216
or.w %d1,(%a0)+
bra.s ___c0216
___a0216:
and.w %d2,(%a0)+
___c0216:
btst #24,%d0
beq.s ___a0217
or.w %d1,(%a0)+
bra.s ___c0217
___a0217:
and.w %d2,(%a0)+
___c0217:
btst #23,%d0
beq.s ___a0218
or.w %d1,(%a0)+
bra.s ___c0218
___a0218:
and.w %d2,(%a0)+
___c0218:
btst #22,%d0
beq.s ___a0219
or.w %d1,(%a0)+
bra.s ___c0219
___a0219:
and.w %d2,(%a0)+
___c0219:
btst #21,%d0
beq.s ___a021a
or.w %d1,(%a0)+
bra.s ___c021a
___a021a:
and.w %d2,(%a0)+
___c021a:
btst #20,%d0
beq.s ___a021b
or.w %d1,(%a0)+
bra.s ___c021b
___a021b:
and.w %d2,(%a0)+
___c021b:
btst #19,%d0
beq.s ___a021c
or.w %d1,(%a0)+
bra.s ___c021c
___a021c:
and.w %d2,(%a0)+
___c021c:
btst #18,%d0
beq.s ___a021d
or.w %d1,(%a0)+
bra.s ___c021d
___a021d:
and.w %d2,(%a0)+
___c021d:
btst #17,%d0
beq.s ___a021e
or.w %d1,(%a0)+
bra.s ___c021e
___a021e:
and.w %d2,(%a0)+
___c021e:
btst #16,%d0
beq.s ___a021f
or.w %d1,(%a0)+
bra.s ___c021f
___a021f:
and.w %d2,(%a0)+
___c021f:
tst.w %d0
bpl.s ___a0220
or.w %d1,(%a0)+
bra.s ___c0220
___a0220:
and.w %d2,(%a0)+
___c0220:
btst #14,%d0
beq.s ___a0221
or.w %d1,(%a0)+
bra.s ___c0221
___a0221:
and.w %d2,(%a0)+
___c0221:
btst #13,%d0
beq.s ___a0222
or.w %d1,(%a0)+
bra.s ___c0222
___a0222:
and.w %d2,(%a0)+
___c0222:
btst #12,%d0
beq.s ___a0223
or.w %d1,(%a0)+
bra.s ___c0223
___a0223:
and.w %d2,(%a0)+
___c0223:
btst #11,%d0
beq.s ___a0224
or.w %d1,(%a0)+
bra.s ___c0224
___a0224:
and.w %d2,(%a0)+
___c0224:
btst #10,%d0
beq.s ___a0225
or.w %d1,(%a0)+
bra.s ___c0225
___a0225:
and.w %d2,(%a0)+
___c0225:
btst #9,%d0
beq.s ___a0226
or.w %d1,(%a0)+
bra.s ___c0226
___a0226:
and.w %d2,(%a0)+
___c0226:
btst #8,%d0
beq.s ___a0227
or.w %d1,(%a0)+
bra.s ___c0227
___a0227:
and.w %d2,(%a0)+
___c0227:
tst.b %d0
bpl.s ___a0228
or.w %d1,(%a0)+
bra.s ___c0228
___a0228:
and.w %d2,(%a0)+
___c0228:
btst #6,%d0
beq.s ___a0229
or.w %d1,(%a0)+
bra.s ___c0229
___a0229:
and.w %d2,(%a0)+
___c0229:
btst #5,%d0
beq.s ___a022a
or.w %d1,(%a0)+
bra.s ___c022a
___a022a:
and.w %d2,(%a0)+
___c022a:
btst #4,%d0
beq.s ___a022b
or.w %d1,(%a0)+
bra.s ___c022b
___a022b:
and.w %d2,(%a0)+
___c022b:
btst #3,%d0
beq.s ___a022c
or.w %d1,(%a0)+
bra.s ___c022c
___a022c:
and.w %d2,(%a0)+
___c022c:
btst #2,%d0
beq.s ___a022d
or.w %d1,(%a0)+
bra.s ___c022d
___a022d:
and.w %d2,(%a0)+
___c022d:
btst #1,%d0
beq.s ___a022e
or.w %d1,(%a0)+
bra.s ___c022e
___a022e:
and.w %d2,(%a0)+
___c022e:
btst #0,%d0
beq.s ___a022f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a022f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale068:
tst.l %d0
bpl.s ___a0230
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0230
___a0230:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0230:
btst #30,%d0
beq.s ___a0231
or.w %d1,(%a0)+
bra.s ___c0231
___a0231:
and.w %d2,(%a0)+
___c0231:
btst #29,%d0
beq.s ___a0232
or.w %d1,(%a0)+
bra.s ___c0232
___a0232:
and.w %d2,(%a0)+
___c0232:
btst #28,%d0
beq.s ___a0233
or.w %d1,(%a0)+
bra.s ___c0233
___a0233:
and.w %d2,(%a0)+
___c0233:
btst #27,%d0
beq.s ___a0234
or.w %d1,(%a0)+
bra.s ___c0234
___a0234:
and.w %d2,(%a0)+
___c0234:
btst #26,%d0
beq.s ___a0235
or.w %d1,(%a0)+
bra.s ___c0235
___a0235:
and.w %d2,(%a0)+
___c0235:
btst #25,%d0
beq.s ___a0236
or.w %d1,(%a0)+
bra.s ___c0236
___a0236:
and.w %d2,(%a0)+
___c0236:
btst #24,%d0
beq.s ___a0237
or.w %d1,(%a0)+
bra.s ___c0237
___a0237:
and.w %d2,(%a0)+
___c0237:
btst #23,%d0
beq.s ___a0238
or.w %d1,(%a0)+
bra.s ___c0238
___a0238:
and.w %d2,(%a0)+
___c0238:
btst #22,%d0
beq.s ___a0239
or.w %d1,(%a0)+
bra.s ___c0239
___a0239:
and.w %d2,(%a0)+
___c0239:
btst #21,%d0
beq.s ___a023a
or.w %d1,(%a0)+
bra.s ___c023a
___a023a:
and.w %d2,(%a0)+
___c023a:
btst #20,%d0
beq.s ___a023b
or.w %d1,(%a0)+
bra.s ___c023b
___a023b:
and.w %d2,(%a0)+
___c023b:
btst #19,%d0
beq.s ___a023c
or.w %d1,(%a0)+
bra.s ___c023c
___a023c:
and.w %d2,(%a0)+
___c023c:
btst #18,%d0
beq.s ___a023d
or.w %d1,(%a0)+
bra.s ___c023d
___a023d:
and.w %d2,(%a0)+
___c023d:
btst #17,%d0
beq.s ___a023e
or.w %d1,(%a0)+
bra.s ___c023e
___a023e:
and.w %d2,(%a0)+
___c023e:
btst #16,%d0
beq.s ___a023f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c023f
___a023f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c023f:
tst.w %d0
bpl.s ___a0240
or.w %d1,(%a0)+
bra.s ___c0240
___a0240:
and.w %d2,(%a0)+
___c0240:
btst #14,%d0
beq.s ___a0241
or.w %d1,(%a0)+
bra.s ___c0241
___a0241:
and.w %d2,(%a0)+
___c0241:
btst #13,%d0
beq.s ___a0242
or.w %d1,(%a0)+
bra.s ___c0242
___a0242:
and.w %d2,(%a0)+
___c0242:
btst #12,%d0
beq.s ___a0243
or.w %d1,(%a0)+
bra.s ___c0243
___a0243:
and.w %d2,(%a0)+
___c0243:
btst #11,%d0
beq.s ___a0244
or.w %d1,(%a0)+
bra.s ___c0244
___a0244:
and.w %d2,(%a0)+
___c0244:
btst #10,%d0
beq.s ___a0245
or.w %d1,(%a0)+
bra.s ___c0245
___a0245:
and.w %d2,(%a0)+
___c0245:
btst #9,%d0
beq.s ___a0246
or.w %d1,(%a0)+
bra.s ___c0246
___a0246:
and.w %d2,(%a0)+
___c0246:
btst #8,%d0
beq.s ___a0247
or.w %d1,(%a0)+
bra.s ___c0247
___a0247:
and.w %d2,(%a0)+
___c0247:
tst.b %d0
bpl.s ___a0248
or.w %d1,(%a0)+
bra.s ___c0248
___a0248:
and.w %d2,(%a0)+
___c0248:
btst #6,%d0
beq.s ___a0249
or.w %d1,(%a0)+
bra.s ___c0249
___a0249:
and.w %d2,(%a0)+
___c0249:
btst #5,%d0
beq.s ___a024a
or.w %d1,(%a0)+
bra.s ___c024a
___a024a:
and.w %d2,(%a0)+
___c024a:
btst #4,%d0
beq.s ___a024b
or.w %d1,(%a0)+
bra.s ___c024b
___a024b:
and.w %d2,(%a0)+
___c024b:
btst #3,%d0
beq.s ___a024c
or.w %d1,(%a0)+
bra.s ___c024c
___a024c:
and.w %d2,(%a0)+
___c024c:
btst #2,%d0
beq.s ___a024d
or.w %d1,(%a0)+
bra.s ___c024d
___a024d:
and.w %d2,(%a0)+
___c024d:
btst #1,%d0
beq.s ___a024e
or.w %d1,(%a0)+
bra.s ___c024e
___a024e:
and.w %d2,(%a0)+
___c024e:
btst #0,%d0
beq.s ___a024f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a024f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale070:
tst.l %d0
bpl.s ___a0250
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0250
___a0250:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0250:
btst #30,%d0
beq.s ___a0251
or.w %d1,(%a0)+
bra.s ___c0251
___a0251:
and.w %d2,(%a0)+
___c0251:
btst #29,%d0
beq.s ___a0252
or.w %d1,(%a0)+
bra.s ___c0252
___a0252:
and.w %d2,(%a0)+
___c0252:
btst #28,%d0
beq.s ___a0253
or.w %d1,(%a0)+
bra.s ___c0253
___a0253:
and.w %d2,(%a0)+
___c0253:
btst #27,%d0
beq.s ___a0254
or.w %d1,(%a0)+
bra.s ___c0254
___a0254:
and.w %d2,(%a0)+
___c0254:
btst #26,%d0
beq.s ___a0255
or.w %d1,(%a0)+
bra.s ___c0255
___a0255:
and.w %d2,(%a0)+
___c0255:
btst #25,%d0
beq.s ___a0256
or.w %d1,(%a0)+
bra.s ___c0256
___a0256:
and.w %d2,(%a0)+
___c0256:
btst #24,%d0
beq.s ___a0257
or.w %d1,(%a0)+
bra.s ___c0257
___a0257:
and.w %d2,(%a0)+
___c0257:
btst #23,%d0
beq.s ___a0258
or.w %d1,(%a0)+
bra.s ___c0258
___a0258:
and.w %d2,(%a0)+
___c0258:
btst #22,%d0
beq.s ___a0259
or.w %d1,(%a0)+
bra.s ___c0259
___a0259:
and.w %d2,(%a0)+
___c0259:
btst #21,%d0
beq.s ___a025a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c025a
___a025a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c025a:
btst #20,%d0
beq.s ___a025b
or.w %d1,(%a0)+
bra.s ___c025b
___a025b:
and.w %d2,(%a0)+
___c025b:
btst #19,%d0
beq.s ___a025c
or.w %d1,(%a0)+
bra.s ___c025c
___a025c:
and.w %d2,(%a0)+
___c025c:
btst #18,%d0
beq.s ___a025d
or.w %d1,(%a0)+
bra.s ___c025d
___a025d:
and.w %d2,(%a0)+
___c025d:
btst #17,%d0
beq.s ___a025e
or.w %d1,(%a0)+
bra.s ___c025e
___a025e:
and.w %d2,(%a0)+
___c025e:
btst #16,%d0
beq.s ___a025f
or.w %d1,(%a0)+
bra.s ___c025f
___a025f:
and.w %d2,(%a0)+
___c025f:
tst.w %d0
bpl.s ___a0260
or.w %d1,(%a0)+
bra.s ___c0260
___a0260:
and.w %d2,(%a0)+
___c0260:
btst #14,%d0
beq.s ___a0261
or.w %d1,(%a0)+
bra.s ___c0261
___a0261:
and.w %d2,(%a0)+
___c0261:
btst #13,%d0
beq.s ___a0262
or.w %d1,(%a0)+
bra.s ___c0262
___a0262:
and.w %d2,(%a0)+
___c0262:
btst #12,%d0
beq.s ___a0263
or.w %d1,(%a0)+
bra.s ___c0263
___a0263:
and.w %d2,(%a0)+
___c0263:
btst #11,%d0
beq.s ___a0264
or.w %d1,(%a0)+
bra.s ___c0264
___a0264:
and.w %d2,(%a0)+
___c0264:
btst #10,%d0
beq.s ___a0265
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0265
___a0265:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0265:
btst #9,%d0
beq.s ___a0266
or.w %d1,(%a0)+
bra.s ___c0266
___a0266:
and.w %d2,(%a0)+
___c0266:
btst #8,%d0
beq.s ___a0267
or.w %d1,(%a0)+
bra.s ___c0267
___a0267:
and.w %d2,(%a0)+
___c0267:
tst.b %d0
bpl.s ___a0268
or.w %d1,(%a0)+
bra.s ___c0268
___a0268:
and.w %d2,(%a0)+
___c0268:
btst #6,%d0
beq.s ___a0269
or.w %d1,(%a0)+
bra.s ___c0269
___a0269:
and.w %d2,(%a0)+
___c0269:
btst #5,%d0
beq.s ___a026a
or.w %d1,(%a0)+
bra.s ___c026a
___a026a:
and.w %d2,(%a0)+
___c026a:
btst #4,%d0
beq.s ___a026b
or.w %d1,(%a0)+
bra.s ___c026b
___a026b:
and.w %d2,(%a0)+
___c026b:
btst #3,%d0
beq.s ___a026c
or.w %d1,(%a0)+
bra.s ___c026c
___a026c:
and.w %d2,(%a0)+
___c026c:
btst #2,%d0
beq.s ___a026d
or.w %d1,(%a0)+
bra.s ___c026d
___a026d:
and.w %d2,(%a0)+
___c026d:
btst #1,%d0
beq.s ___a026e
or.w %d1,(%a0)+
bra.s ___c026e
___a026e:
and.w %d2,(%a0)+
___c026e:
btst #0,%d0
beq.s ___a026f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a026f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale072:
tst.l %d0
bpl.s ___a0270
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0270
___a0270:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0270:
btst #30,%d0
beq.s ___a0271
or.w %d1,(%a0)+
bra.s ___c0271
___a0271:
and.w %d2,(%a0)+
___c0271:
btst #29,%d0
beq.s ___a0272
or.w %d1,(%a0)+
bra.s ___c0272
___a0272:
and.w %d2,(%a0)+
___c0272:
btst #28,%d0
beq.s ___a0273
or.w %d1,(%a0)+
bra.s ___c0273
___a0273:
and.w %d2,(%a0)+
___c0273:
btst #27,%d0
beq.s ___a0274
or.w %d1,(%a0)+
bra.s ___c0274
___a0274:
and.w %d2,(%a0)+
___c0274:
btst #26,%d0
beq.s ___a0275
or.w %d1,(%a0)+
bra.s ___c0275
___a0275:
and.w %d2,(%a0)+
___c0275:
btst #25,%d0
beq.s ___a0276
or.w %d1,(%a0)+
bra.s ___c0276
___a0276:
and.w %d2,(%a0)+
___c0276:
btst #24,%d0
beq.s ___a0277
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0277
___a0277:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0277:
btst #23,%d0
beq.s ___a0278
or.w %d1,(%a0)+
bra.s ___c0278
___a0278:
and.w %d2,(%a0)+
___c0278:
btst #22,%d0
beq.s ___a0279
or.w %d1,(%a0)+
bra.s ___c0279
___a0279:
and.w %d2,(%a0)+
___c0279:
btst #21,%d0
beq.s ___a027a
or.w %d1,(%a0)+
bra.s ___c027a
___a027a:
and.w %d2,(%a0)+
___c027a:
btst #20,%d0
beq.s ___a027b
or.w %d1,(%a0)+
bra.s ___c027b
___a027b:
and.w %d2,(%a0)+
___c027b:
btst #19,%d0
beq.s ___a027c
or.w %d1,(%a0)+
bra.s ___c027c
___a027c:
and.w %d2,(%a0)+
___c027c:
btst #18,%d0
beq.s ___a027d
or.w %d1,(%a0)+
bra.s ___c027d
___a027d:
and.w %d2,(%a0)+
___c027d:
btst #17,%d0
beq.s ___a027e
or.w %d1,(%a0)+
bra.s ___c027e
___a027e:
and.w %d2,(%a0)+
___c027e:
btst #16,%d0
beq.s ___a027f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c027f
___a027f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c027f:
tst.w %d0
bpl.s ___a0280
or.w %d1,(%a0)+
bra.s ___c0280
___a0280:
and.w %d2,(%a0)+
___c0280:
btst #14,%d0
beq.s ___a0281
or.w %d1,(%a0)+
bra.s ___c0281
___a0281:
and.w %d2,(%a0)+
___c0281:
btst #13,%d0
beq.s ___a0282
or.w %d1,(%a0)+
bra.s ___c0282
___a0282:
and.w %d2,(%a0)+
___c0282:
btst #12,%d0
beq.s ___a0283
or.w %d1,(%a0)+
bra.s ___c0283
___a0283:
and.w %d2,(%a0)+
___c0283:
btst #11,%d0
beq.s ___a0284
or.w %d1,(%a0)+
bra.s ___c0284
___a0284:
and.w %d2,(%a0)+
___c0284:
btst #10,%d0
beq.s ___a0285
or.w %d1,(%a0)+
bra.s ___c0285
___a0285:
and.w %d2,(%a0)+
___c0285:
btst #9,%d0
beq.s ___a0286
or.w %d1,(%a0)+
bra.s ___c0286
___a0286:
and.w %d2,(%a0)+
___c0286:
btst #8,%d0
beq.s ___a0287
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0287
___a0287:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0287:
tst.b %d0
bpl.s ___a0288
or.w %d1,(%a0)+
bra.s ___c0288
___a0288:
and.w %d2,(%a0)+
___c0288:
btst #6,%d0
beq.s ___a0289
or.w %d1,(%a0)+
bra.s ___c0289
___a0289:
and.w %d2,(%a0)+
___c0289:
btst #5,%d0
beq.s ___a028a
or.w %d1,(%a0)+
bra.s ___c028a
___a028a:
and.w %d2,(%a0)+
___c028a:
btst #4,%d0
beq.s ___a028b
or.w %d1,(%a0)+
bra.s ___c028b
___a028b:
and.w %d2,(%a0)+
___c028b:
btst #3,%d0
beq.s ___a028c
or.w %d1,(%a0)+
bra.s ___c028c
___a028c:
and.w %d2,(%a0)+
___c028c:
btst #2,%d0
beq.s ___a028d
or.w %d1,(%a0)+
bra.s ___c028d
___a028d:
and.w %d2,(%a0)+
___c028d:
btst #1,%d0
beq.s ___a028e
or.w %d1,(%a0)+
bra.s ___c028e
___a028e:
and.w %d2,(%a0)+
___c028e:
btst #0,%d0
beq.s ___a028f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a028f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale074:
tst.l %d0
bpl.s ___a0290
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0290
___a0290:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0290:
btst #30,%d0
beq.s ___a0291
or.w %d1,(%a0)+
bra.s ___c0291
___a0291:
and.w %d2,(%a0)+
___c0291:
btst #29,%d0
beq.s ___a0292
or.w %d1,(%a0)+
bra.s ___c0292
___a0292:
and.w %d2,(%a0)+
___c0292:
btst #28,%d0
beq.s ___a0293
or.w %d1,(%a0)+
bra.s ___c0293
___a0293:
and.w %d2,(%a0)+
___c0293:
btst #27,%d0
beq.s ___a0294
or.w %d1,(%a0)+
bra.s ___c0294
___a0294:
and.w %d2,(%a0)+
___c0294:
btst #26,%d0
beq.s ___a0295
or.w %d1,(%a0)+
bra.s ___c0295
___a0295:
and.w %d2,(%a0)+
___c0295:
btst #25,%d0
beq.s ___a0296
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0296
___a0296:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0296:
btst #24,%d0
beq.s ___a0297
or.w %d1,(%a0)+
bra.s ___c0297
___a0297:
and.w %d2,(%a0)+
___c0297:
btst #23,%d0
beq.s ___a0298
or.w %d1,(%a0)+
bra.s ___c0298
___a0298:
and.w %d2,(%a0)+
___c0298:
btst #22,%d0
beq.s ___a0299
or.w %d1,(%a0)+
bra.s ___c0299
___a0299:
and.w %d2,(%a0)+
___c0299:
btst #21,%d0
beq.s ___a029a
or.w %d1,(%a0)+
bra.s ___c029a
___a029a:
and.w %d2,(%a0)+
___c029a:
btst #20,%d0
beq.s ___a029b
or.w %d1,(%a0)+
bra.s ___c029b
___a029b:
and.w %d2,(%a0)+
___c029b:
btst #19,%d0
beq.s ___a029c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c029c
___a029c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c029c:
btst #18,%d0
beq.s ___a029d
or.w %d1,(%a0)+
bra.s ___c029d
___a029d:
and.w %d2,(%a0)+
___c029d:
btst #17,%d0
beq.s ___a029e
or.w %d1,(%a0)+
bra.s ___c029e
___a029e:
and.w %d2,(%a0)+
___c029e:
btst #16,%d0
beq.s ___a029f
or.w %d1,(%a0)+
bra.s ___c029f
___a029f:
and.w %d2,(%a0)+
___c029f:
tst.w %d0
bpl.s ___a02a0
or.w %d1,(%a0)+
bra.s ___c02a0
___a02a0:
and.w %d2,(%a0)+
___c02a0:
btst #14,%d0
beq.s ___a02a1
or.w %d1,(%a0)+
bra.s ___c02a1
___a02a1:
and.w %d2,(%a0)+
___c02a1:
btst #13,%d0
beq.s ___a02a2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02a2
___a02a2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02a2:
btst #12,%d0
beq.s ___a02a3
or.w %d1,(%a0)+
bra.s ___c02a3
___a02a3:
and.w %d2,(%a0)+
___c02a3:
btst #11,%d0
beq.s ___a02a4
or.w %d1,(%a0)+
bra.s ___c02a4
___a02a4:
and.w %d2,(%a0)+
___c02a4:
btst #10,%d0
beq.s ___a02a5
or.w %d1,(%a0)+
bra.s ___c02a5
___a02a5:
and.w %d2,(%a0)+
___c02a5:
btst #9,%d0
beq.s ___a02a6
or.w %d1,(%a0)+
bra.s ___c02a6
___a02a6:
and.w %d2,(%a0)+
___c02a6:
btst #8,%d0
beq.s ___a02a7
or.w %d1,(%a0)+
bra.s ___c02a7
___a02a7:
and.w %d2,(%a0)+
___c02a7:
tst.b %d0
bpl.s ___a02a8
or.w %d1,(%a0)+
bra.s ___c02a8
___a02a8:
and.w %d2,(%a0)+
___c02a8:
btst #6,%d0
beq.s ___a02a9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02a9
___a02a9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02a9:
btst #5,%d0
beq.s ___a02aa
or.w %d1,(%a0)+
bra.s ___c02aa
___a02aa:
and.w %d2,(%a0)+
___c02aa:
btst #4,%d0
beq.s ___a02ab
or.w %d1,(%a0)+
bra.s ___c02ab
___a02ab:
and.w %d2,(%a0)+
___c02ab:
btst #3,%d0
beq.s ___a02ac
or.w %d1,(%a0)+
bra.s ___c02ac
___a02ac:
and.w %d2,(%a0)+
___c02ac:
btst #2,%d0
beq.s ___a02ad
or.w %d1,(%a0)+
bra.s ___c02ad
___a02ad:
and.w %d2,(%a0)+
___c02ad:
btst #1,%d0
beq.s ___a02ae
or.w %d1,(%a0)+
bra.s ___c02ae
___a02ae:
and.w %d2,(%a0)+
___c02ae:
btst #0,%d0
beq.s ___a02af
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a02af:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale076:
tst.l %d0
bpl.s ___a02b0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02b0
___a02b0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02b0:
btst #30,%d0
beq.s ___a02b1
or.w %d1,(%a0)+
bra.s ___c02b1
___a02b1:
and.w %d2,(%a0)+
___c02b1:
btst #29,%d0
beq.s ___a02b2
or.w %d1,(%a0)+
bra.s ___c02b2
___a02b2:
and.w %d2,(%a0)+
___c02b2:
btst #28,%d0
beq.s ___a02b3
or.w %d1,(%a0)+
bra.s ___c02b3
___a02b3:
and.w %d2,(%a0)+
___c02b3:
btst #27,%d0
beq.s ___a02b4
or.w %d1,(%a0)+
bra.s ___c02b4
___a02b4:
and.w %d2,(%a0)+
___c02b4:
btst #26,%d0
beq.s ___a02b5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02b5
___a02b5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02b5:
btst #25,%d0
beq.s ___a02b6
or.w %d1,(%a0)+
bra.s ___c02b6
___a02b6:
and.w %d2,(%a0)+
___c02b6:
btst #24,%d0
beq.s ___a02b7
or.w %d1,(%a0)+
bra.s ___c02b7
___a02b7:
and.w %d2,(%a0)+
___c02b7:
btst #23,%d0
beq.s ___a02b8
or.w %d1,(%a0)+
bra.s ___c02b8
___a02b8:
and.w %d2,(%a0)+
___c02b8:
btst #22,%d0
beq.s ___a02b9
or.w %d1,(%a0)+
bra.s ___c02b9
___a02b9:
and.w %d2,(%a0)+
___c02b9:
btst #21,%d0
beq.s ___a02ba
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02ba
___a02ba:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02ba:
btst #20,%d0
beq.s ___a02bb
or.w %d1,(%a0)+
bra.s ___c02bb
___a02bb:
and.w %d2,(%a0)+
___c02bb:
btst #19,%d0
beq.s ___a02bc
or.w %d1,(%a0)+
bra.s ___c02bc
___a02bc:
and.w %d2,(%a0)+
___c02bc:
btst #18,%d0
beq.s ___a02bd
or.w %d1,(%a0)+
bra.s ___c02bd
___a02bd:
and.w %d2,(%a0)+
___c02bd:
btst #17,%d0
beq.s ___a02be
or.w %d1,(%a0)+
bra.s ___c02be
___a02be:
and.w %d2,(%a0)+
___c02be:
btst #16,%d0
beq.s ___a02bf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02bf
___a02bf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02bf:
tst.w %d0
bpl.s ___a02c0
or.w %d1,(%a0)+
bra.s ___c02c0
___a02c0:
and.w %d2,(%a0)+
___c02c0:
btst #14,%d0
beq.s ___a02c1
or.w %d1,(%a0)+
bra.s ___c02c1
___a02c1:
and.w %d2,(%a0)+
___c02c1:
btst #13,%d0
beq.s ___a02c2
or.w %d1,(%a0)+
bra.s ___c02c2
___a02c2:
and.w %d2,(%a0)+
___c02c2:
btst #12,%d0
beq.s ___a02c3
or.w %d1,(%a0)+
bra.s ___c02c3
___a02c3:
and.w %d2,(%a0)+
___c02c3:
btst #11,%d0
beq.s ___a02c4
or.w %d1,(%a0)+
bra.s ___c02c4
___a02c4:
and.w %d2,(%a0)+
___c02c4:
btst #10,%d0
beq.s ___a02c5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02c5
___a02c5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02c5:
btst #9,%d0
beq.s ___a02c6
or.w %d1,(%a0)+
bra.s ___c02c6
___a02c6:
and.w %d2,(%a0)+
___c02c6:
btst #8,%d0
beq.s ___a02c7
or.w %d1,(%a0)+
bra.s ___c02c7
___a02c7:
and.w %d2,(%a0)+
___c02c7:
tst.b %d0
bpl.s ___a02c8
or.w %d1,(%a0)+
bra.s ___c02c8
___a02c8:
and.w %d2,(%a0)+
___c02c8:
btst #6,%d0
beq.s ___a02c9
or.w %d1,(%a0)+
bra.s ___c02c9
___a02c9:
and.w %d2,(%a0)+
___c02c9:
btst #5,%d0
beq.s ___a02ca
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02ca
___a02ca:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02ca:
btst #4,%d0
beq.s ___a02cb
or.w %d1,(%a0)+
bra.s ___c02cb
___a02cb:
and.w %d2,(%a0)+
___c02cb:
btst #3,%d0
beq.s ___a02cc
or.w %d1,(%a0)+
bra.s ___c02cc
___a02cc:
and.w %d2,(%a0)+
___c02cc:
btst #2,%d0
beq.s ___a02cd
or.w %d1,(%a0)+
bra.s ___c02cd
___a02cd:
and.w %d2,(%a0)+
___c02cd:
btst #1,%d0
beq.s ___a02ce
or.w %d1,(%a0)+
bra.s ___c02ce
___a02ce:
and.w %d2,(%a0)+
___c02ce:
btst #0,%d0
beq.s ___a02cf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a02cf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale078:
tst.l %d0
bpl.s ___a02d0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02d0
___a02d0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02d0:
btst #30,%d0
beq.s ___a02d1
or.w %d1,(%a0)+
bra.s ___c02d1
___a02d1:
and.w %d2,(%a0)+
___c02d1:
btst #29,%d0
beq.s ___a02d2
or.w %d1,(%a0)+
bra.s ___c02d2
___a02d2:
and.w %d2,(%a0)+
___c02d2:
btst #28,%d0
beq.s ___a02d3
or.w %d1,(%a0)+
bra.s ___c02d3
___a02d3:
and.w %d2,(%a0)+
___c02d3:
btst #27,%d0
beq.s ___a02d4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02d4
___a02d4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02d4:
btst #26,%d0
beq.s ___a02d5
or.w %d1,(%a0)+
bra.s ___c02d5
___a02d5:
and.w %d2,(%a0)+
___c02d5:
btst #25,%d0
beq.s ___a02d6
or.w %d1,(%a0)+
bra.s ___c02d6
___a02d6:
and.w %d2,(%a0)+
___c02d6:
btst #24,%d0
beq.s ___a02d7
or.w %d1,(%a0)+
bra.s ___c02d7
___a02d7:
and.w %d2,(%a0)+
___c02d7:
btst #23,%d0
beq.s ___a02d8
or.w %d1,(%a0)+
bra.s ___c02d8
___a02d8:
and.w %d2,(%a0)+
___c02d8:
btst #22,%d0
beq.s ___a02d9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02d9
___a02d9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02d9:
btst #21,%d0
beq.s ___a02da
or.w %d1,(%a0)+
bra.s ___c02da
___a02da:
and.w %d2,(%a0)+
___c02da:
btst #20,%d0
beq.s ___a02db
or.w %d1,(%a0)+
bra.s ___c02db
___a02db:
and.w %d2,(%a0)+
___c02db:
btst #19,%d0
beq.s ___a02dc
or.w %d1,(%a0)+
bra.s ___c02dc
___a02dc:
and.w %d2,(%a0)+
___c02dc:
btst #18,%d0
beq.s ___a02dd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02dd
___a02dd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02dd:
btst #17,%d0
beq.s ___a02de
or.w %d1,(%a0)+
bra.s ___c02de
___a02de:
and.w %d2,(%a0)+
___c02de:
btst #16,%d0
beq.s ___a02df
or.w %d1,(%a0)+
bra.s ___c02df
___a02df:
and.w %d2,(%a0)+
___c02df:
tst.w %d0
bpl.s ___a02e0
or.w %d1,(%a0)+
bra.s ___c02e0
___a02e0:
and.w %d2,(%a0)+
___c02e0:
btst #14,%d0
beq.s ___a02e1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02e1
___a02e1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02e1:
btst #13,%d0
beq.s ___a02e2
or.w %d1,(%a0)+
bra.s ___c02e2
___a02e2:
and.w %d2,(%a0)+
___c02e2:
btst #12,%d0
beq.s ___a02e3
or.w %d1,(%a0)+
bra.s ___c02e3
___a02e3:
and.w %d2,(%a0)+
___c02e3:
btst #11,%d0
beq.s ___a02e4
or.w %d1,(%a0)+
bra.s ___c02e4
___a02e4:
and.w %d2,(%a0)+
___c02e4:
btst #10,%d0
beq.s ___a02e5
or.w %d1,(%a0)+
bra.s ___c02e5
___a02e5:
and.w %d2,(%a0)+
___c02e5:
btst #9,%d0
beq.s ___a02e6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02e6
___a02e6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02e6:
btst #8,%d0
beq.s ___a02e7
or.w %d1,(%a0)+
bra.s ___c02e7
___a02e7:
and.w %d2,(%a0)+
___c02e7:
tst.b %d0
bpl.s ___a02e8
or.w %d1,(%a0)+
bra.s ___c02e8
___a02e8:
and.w %d2,(%a0)+
___c02e8:
btst #6,%d0
beq.s ___a02e9
or.w %d1,(%a0)+
bra.s ___c02e9
___a02e9:
and.w %d2,(%a0)+
___c02e9:
btst #5,%d0
beq.s ___a02ea
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02ea
___a02ea:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02ea:
btst #4,%d0
beq.s ___a02eb
or.w %d1,(%a0)+
bra.s ___c02eb
___a02eb:
and.w %d2,(%a0)+
___c02eb:
btst #3,%d0
beq.s ___a02ec
or.w %d1,(%a0)+
bra.s ___c02ec
___a02ec:
and.w %d2,(%a0)+
___c02ec:
btst #2,%d0
beq.s ___a02ed
or.w %d1,(%a0)+
bra.s ___c02ed
___a02ed:
and.w %d2,(%a0)+
___c02ed:
btst #1,%d0
beq.s ___a02ee
or.w %d1,(%a0)+
bra.s ___c02ee
___a02ee:
and.w %d2,(%a0)+
___c02ee:
btst #0,%d0
beq.s ___a02ef
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a02ef:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale080:
tst.l %d0
bpl.s ___a02f0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02f0
___a02f0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02f0:
btst #30,%d0
beq.s ___a02f1
or.w %d1,(%a0)+
bra.s ___c02f1
___a02f1:
and.w %d2,(%a0)+
___c02f1:
btst #29,%d0
beq.s ___a02f2
or.w %d1,(%a0)+
bra.s ___c02f2
___a02f2:
and.w %d2,(%a0)+
___c02f2:
btst #28,%d0
beq.s ___a02f3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02f3
___a02f3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02f3:
btst #27,%d0
beq.s ___a02f4
or.w %d1,(%a0)+
bra.s ___c02f4
___a02f4:
and.w %d2,(%a0)+
___c02f4:
btst #26,%d0
beq.s ___a02f5
or.w %d1,(%a0)+
bra.s ___c02f5
___a02f5:
and.w %d2,(%a0)+
___c02f5:
btst #25,%d0
beq.s ___a02f6
or.w %d1,(%a0)+
bra.s ___c02f6
___a02f6:
and.w %d2,(%a0)+
___c02f6:
btst #24,%d0
beq.s ___a02f7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02f7
___a02f7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02f7:
btst #23,%d0
beq.s ___a02f8
or.w %d1,(%a0)+
bra.s ___c02f8
___a02f8:
and.w %d2,(%a0)+
___c02f8:
btst #22,%d0
beq.s ___a02f9
or.w %d1,(%a0)+
bra.s ___c02f9
___a02f9:
and.w %d2,(%a0)+
___c02f9:
btst #21,%d0
beq.s ___a02fa
or.w %d1,(%a0)+
bra.s ___c02fa
___a02fa:
and.w %d2,(%a0)+
___c02fa:
btst #20,%d0
beq.s ___a02fb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02fb
___a02fb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02fb:
btst #19,%d0
beq.s ___a02fc
or.w %d1,(%a0)+
bra.s ___c02fc
___a02fc:
and.w %d2,(%a0)+
___c02fc:
btst #18,%d0
beq.s ___a02fd
or.w %d1,(%a0)+
bra.s ___c02fd
___a02fd:
and.w %d2,(%a0)+
___c02fd:
btst #17,%d0
beq.s ___a02fe
or.w %d1,(%a0)+
bra.s ___c02fe
___a02fe:
and.w %d2,(%a0)+
___c02fe:
btst #16,%d0
beq.s ___a02ff
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c02ff
___a02ff:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c02ff:
tst.w %d0
bpl.s ___a0300
or.w %d1,(%a0)+
bra.s ___c0300
___a0300:
and.w %d2,(%a0)+
___c0300:
btst #14,%d0
beq.s ___a0301
or.w %d1,(%a0)+
bra.s ___c0301
___a0301:
and.w %d2,(%a0)+
___c0301:
btst #13,%d0
beq.s ___a0302
or.w %d1,(%a0)+
bra.s ___c0302
___a0302:
and.w %d2,(%a0)+
___c0302:
btst #12,%d0
beq.s ___a0303
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0303
___a0303:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0303:
btst #11,%d0
beq.s ___a0304
or.w %d1,(%a0)+
bra.s ___c0304
___a0304:
and.w %d2,(%a0)+
___c0304:
btst #10,%d0
beq.s ___a0305
or.w %d1,(%a0)+
bra.s ___c0305
___a0305:
and.w %d2,(%a0)+
___c0305:
btst #9,%d0
beq.s ___a0306
or.w %d1,(%a0)+
bra.s ___c0306
___a0306:
and.w %d2,(%a0)+
___c0306:
btst #8,%d0
beq.s ___a0307
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0307
___a0307:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0307:
tst.b %d0
bpl.s ___a0308
or.w %d1,(%a0)+
bra.s ___c0308
___a0308:
and.w %d2,(%a0)+
___c0308:
btst #6,%d0
beq.s ___a0309
or.w %d1,(%a0)+
bra.s ___c0309
___a0309:
and.w %d2,(%a0)+
___c0309:
btst #5,%d0
beq.s ___a030a
or.w %d1,(%a0)+
bra.s ___c030a
___a030a:
and.w %d2,(%a0)+
___c030a:
btst #4,%d0
beq.s ___a030b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c030b
___a030b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c030b:
btst #3,%d0
beq.s ___a030c
or.w %d1,(%a0)+
bra.s ___c030c
___a030c:
and.w %d2,(%a0)+
___c030c:
btst #2,%d0
beq.s ___a030d
or.w %d1,(%a0)+
bra.s ___c030d
___a030d:
and.w %d2,(%a0)+
___c030d:
btst #1,%d0
beq.s ___a030e
or.w %d1,(%a0)+
bra.s ___c030e
___a030e:
and.w %d2,(%a0)+
___c030e:
btst #0,%d0
beq.s ___a030f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a030f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale082:
tst.l %d0
bpl.s ___a0310
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0310
___a0310:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0310:
btst #30,%d0
beq.s ___a0311
or.w %d1,(%a0)+
bra.s ___c0311
___a0311:
and.w %d2,(%a0)+
___c0311:
btst #29,%d0
beq.s ___a0312
or.w %d1,(%a0)+
bra.s ___c0312
___a0312:
and.w %d2,(%a0)+
___c0312:
btst #28,%d0
beq.s ___a0313
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0313
___a0313:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0313:
btst #27,%d0
beq.s ___a0314
or.w %d1,(%a0)+
bra.s ___c0314
___a0314:
and.w %d2,(%a0)+
___c0314:
btst #26,%d0
beq.s ___a0315
or.w %d1,(%a0)+
bra.s ___c0315
___a0315:
and.w %d2,(%a0)+
___c0315:
btst #25,%d0
beq.s ___a0316
or.w %d1,(%a0)+
bra.s ___c0316
___a0316:
and.w %d2,(%a0)+
___c0316:
btst #24,%d0
beq.s ___a0317
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0317
___a0317:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0317:
btst #23,%d0
beq.s ___a0318
or.w %d1,(%a0)+
bra.s ___c0318
___a0318:
and.w %d2,(%a0)+
___c0318:
btst #22,%d0
beq.s ___a0319
or.w %d1,(%a0)+
bra.s ___c0319
___a0319:
and.w %d2,(%a0)+
___c0319:
btst #21,%d0
beq.s ___a031a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c031a
___a031a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c031a:
btst #20,%d0
beq.s ___a031b
or.w %d1,(%a0)+
bra.s ___c031b
___a031b:
and.w %d2,(%a0)+
___c031b:
btst #19,%d0
beq.s ___a031c
or.w %d1,(%a0)+
bra.s ___c031c
___a031c:
and.w %d2,(%a0)+
___c031c:
btst #18,%d0
beq.s ___a031d
or.w %d1,(%a0)+
bra.s ___c031d
___a031d:
and.w %d2,(%a0)+
___c031d:
btst #17,%d0
beq.s ___a031e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c031e
___a031e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c031e:
btst #16,%d0
beq.s ___a031f
or.w %d1,(%a0)+
bra.s ___c031f
___a031f:
and.w %d2,(%a0)+
___c031f:
tst.w %d0
bpl.s ___a0320
or.w %d1,(%a0)+
bra.s ___c0320
___a0320:
and.w %d2,(%a0)+
___c0320:
btst #14,%d0
beq.s ___a0321
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0321
___a0321:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0321:
btst #13,%d0
beq.s ___a0322
or.w %d1,(%a0)+
bra.s ___c0322
___a0322:
and.w %d2,(%a0)+
___c0322:
btst #12,%d0
beq.s ___a0323
or.w %d1,(%a0)+
bra.s ___c0323
___a0323:
and.w %d2,(%a0)+
___c0323:
btst #11,%d0
beq.s ___a0324
or.w %d1,(%a0)+
bra.s ___c0324
___a0324:
and.w %d2,(%a0)+
___c0324:
btst #10,%d0
beq.s ___a0325
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0325
___a0325:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0325:
btst #9,%d0
beq.s ___a0326
or.w %d1,(%a0)+
bra.s ___c0326
___a0326:
and.w %d2,(%a0)+
___c0326:
btst #8,%d0
beq.s ___a0327
or.w %d1,(%a0)+
bra.s ___c0327
___a0327:
and.w %d2,(%a0)+
___c0327:
tst.b %d0
bpl.s ___a0328
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0328
___a0328:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0328:
btst #6,%d0
beq.s ___a0329
or.w %d1,(%a0)+
bra.s ___c0329
___a0329:
and.w %d2,(%a0)+
___c0329:
btst #5,%d0
beq.s ___a032a
or.w %d1,(%a0)+
bra.s ___c032a
___a032a:
and.w %d2,(%a0)+
___c032a:
btst #4,%d0
beq.s ___a032b
or.w %d1,(%a0)+
bra.s ___c032b
___a032b:
and.w %d2,(%a0)+
___c032b:
btst #3,%d0
beq.s ___a032c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c032c
___a032c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c032c:
btst #2,%d0
beq.s ___a032d
or.w %d1,(%a0)+
bra.s ___c032d
___a032d:
and.w %d2,(%a0)+
___c032d:
btst #1,%d0
beq.s ___a032e
or.w %d1,(%a0)+
bra.s ___c032e
___a032e:
and.w %d2,(%a0)+
___c032e:
btst #0,%d0
beq.s ___a032f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a032f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale084:
tst.l %d0
bpl.s ___a0330
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0330
___a0330:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0330:
btst #30,%d0
beq.s ___a0331
or.w %d1,(%a0)+
bra.s ___c0331
___a0331:
and.w %d2,(%a0)+
___c0331:
btst #29,%d0
beq.s ___a0332
or.w %d1,(%a0)+
bra.s ___c0332
___a0332:
and.w %d2,(%a0)+
___c0332:
btst #28,%d0
beq.s ___a0333
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0333
___a0333:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0333:
btst #27,%d0
beq.s ___a0334
or.w %d1,(%a0)+
bra.s ___c0334
___a0334:
and.w %d2,(%a0)+
___c0334:
btst #26,%d0
beq.s ___a0335
or.w %d1,(%a0)+
bra.s ___c0335
___a0335:
and.w %d2,(%a0)+
___c0335:
btst #25,%d0
beq.s ___a0336
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0336
___a0336:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0336:
btst #24,%d0
beq.s ___a0337
or.w %d1,(%a0)+
bra.s ___c0337
___a0337:
and.w %d2,(%a0)+
___c0337:
btst #23,%d0
beq.s ___a0338
or.w %d1,(%a0)+
bra.s ___c0338
___a0338:
and.w %d2,(%a0)+
___c0338:
btst #22,%d0
beq.s ___a0339
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0339
___a0339:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0339:
btst #21,%d0
beq.s ___a033a
or.w %d1,(%a0)+
bra.s ___c033a
___a033a:
and.w %d2,(%a0)+
___c033a:
btst #20,%d0
beq.s ___a033b
or.w %d1,(%a0)+
bra.s ___c033b
___a033b:
and.w %d2,(%a0)+
___c033b:
btst #19,%d0
beq.s ___a033c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c033c
___a033c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c033c:
btst #18,%d0
beq.s ___a033d
or.w %d1,(%a0)+
bra.s ___c033d
___a033d:
and.w %d2,(%a0)+
___c033d:
btst #17,%d0
beq.s ___a033e
or.w %d1,(%a0)+
bra.s ___c033e
___a033e:
and.w %d2,(%a0)+
___c033e:
btst #16,%d0
beq.s ___a033f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c033f
___a033f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c033f:
tst.w %d0
bpl.s ___a0340
or.w %d1,(%a0)+
bra.s ___c0340
___a0340:
and.w %d2,(%a0)+
___c0340:
btst #14,%d0
beq.s ___a0341
or.w %d1,(%a0)+
bra.s ___c0341
___a0341:
and.w %d2,(%a0)+
___c0341:
btst #13,%d0
beq.s ___a0342
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0342
___a0342:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0342:
btst #12,%d0
beq.s ___a0343
or.w %d1,(%a0)+
bra.s ___c0343
___a0343:
and.w %d2,(%a0)+
___c0343:
btst #11,%d0
beq.s ___a0344
or.w %d1,(%a0)+
bra.s ___c0344
___a0344:
and.w %d2,(%a0)+
___c0344:
btst #10,%d0
beq.s ___a0345
or.w %d1,(%a0)+
bra.s ___c0345
___a0345:
and.w %d2,(%a0)+
___c0345:
btst #9,%d0
beq.s ___a0346
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0346
___a0346:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0346:
btst #8,%d0
beq.s ___a0347
or.w %d1,(%a0)+
bra.s ___c0347
___a0347:
and.w %d2,(%a0)+
___c0347:
tst.b %d0
bpl.s ___a0348
or.w %d1,(%a0)+
bra.s ___c0348
___a0348:
and.w %d2,(%a0)+
___c0348:
btst #6,%d0
beq.s ___a0349
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0349
___a0349:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0349:
btst #5,%d0
beq.s ___a034a
or.w %d1,(%a0)+
bra.s ___c034a
___a034a:
and.w %d2,(%a0)+
___c034a:
btst #4,%d0
beq.s ___a034b
or.w %d1,(%a0)+
bra.s ___c034b
___a034b:
and.w %d2,(%a0)+
___c034b:
btst #3,%d0
beq.s ___a034c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c034c
___a034c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c034c:
btst #2,%d0
beq.s ___a034d
or.w %d1,(%a0)+
bra.s ___c034d
___a034d:
and.w %d2,(%a0)+
___c034d:
btst #1,%d0
beq.s ___a034e
or.w %d1,(%a0)+
bra.s ___c034e
___a034e:
and.w %d2,(%a0)+
___c034e:
btst #0,%d0
beq.s ___a034f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a034f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale086:
tst.l %d0
bpl.s ___a0350
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0350
___a0350:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0350:
btst #30,%d0
beq.s ___a0351
or.w %d1,(%a0)+
bra.s ___c0351
___a0351:
and.w %d2,(%a0)+
___c0351:
btst #29,%d0
beq.s ___a0352
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0352
___a0352:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0352:
btst #28,%d0
beq.s ___a0353
or.w %d1,(%a0)+
bra.s ___c0353
___a0353:
and.w %d2,(%a0)+
___c0353:
btst #27,%d0
beq.s ___a0354
or.w %d1,(%a0)+
bra.s ___c0354
___a0354:
and.w %d2,(%a0)+
___c0354:
btst #26,%d0
beq.s ___a0355
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0355
___a0355:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0355:
btst #25,%d0
beq.s ___a0356
or.w %d1,(%a0)+
bra.s ___c0356
___a0356:
and.w %d2,(%a0)+
___c0356:
btst #24,%d0
beq.s ___a0357
or.w %d1,(%a0)+
bra.s ___c0357
___a0357:
and.w %d2,(%a0)+
___c0357:
btst #23,%d0
beq.s ___a0358
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0358
___a0358:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0358:
btst #22,%d0
beq.s ___a0359
or.w %d1,(%a0)+
bra.s ___c0359
___a0359:
and.w %d2,(%a0)+
___c0359:
btst #21,%d0
beq.s ___a035a
or.w %d1,(%a0)+
bra.s ___c035a
___a035a:
and.w %d2,(%a0)+
___c035a:
btst #20,%d0
beq.s ___a035b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c035b
___a035b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c035b:
btst #19,%d0
beq.s ___a035c
or.w %d1,(%a0)+
bra.s ___c035c
___a035c:
and.w %d2,(%a0)+
___c035c:
btst #18,%d0
beq.s ___a035d
or.w %d1,(%a0)+
bra.s ___c035d
___a035d:
and.w %d2,(%a0)+
___c035d:
btst #17,%d0
beq.s ___a035e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c035e
___a035e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c035e:
btst #16,%d0
beq.s ___a035f
or.w %d1,(%a0)+
bra.s ___c035f
___a035f:
and.w %d2,(%a0)+
___c035f:
tst.w %d0
bpl.s ___a0360
or.w %d1,(%a0)+
bra.s ___c0360
___a0360:
and.w %d2,(%a0)+
___c0360:
btst #14,%d0
beq.s ___a0361
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0361
___a0361:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0361:
btst #13,%d0
beq.s ___a0362
or.w %d1,(%a0)+
bra.s ___c0362
___a0362:
and.w %d2,(%a0)+
___c0362:
btst #12,%d0
beq.s ___a0363
or.w %d1,(%a0)+
bra.s ___c0363
___a0363:
and.w %d2,(%a0)+
___c0363:
btst #11,%d0
beq.s ___a0364
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0364
___a0364:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0364:
btst #10,%d0
beq.s ___a0365
or.w %d1,(%a0)+
bra.s ___c0365
___a0365:
and.w %d2,(%a0)+
___c0365:
btst #9,%d0
beq.s ___a0366
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0366
___a0366:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0366:
btst #8,%d0
beq.s ___a0367
or.w %d1,(%a0)+
bra.s ___c0367
___a0367:
and.w %d2,(%a0)+
___c0367:
tst.b %d0
bpl.s ___a0368
or.w %d1,(%a0)+
bra.s ___c0368
___a0368:
and.w %d2,(%a0)+
___c0368:
btst #6,%d0
beq.s ___a0369
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0369
___a0369:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0369:
btst #5,%d0
beq.s ___a036a
or.w %d1,(%a0)+
bra.s ___c036a
___a036a:
and.w %d2,(%a0)+
___c036a:
btst #4,%d0
beq.s ___a036b
or.w %d1,(%a0)+
bra.s ___c036b
___a036b:
and.w %d2,(%a0)+
___c036b:
btst #3,%d0
beq.s ___a036c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c036c
___a036c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c036c:
btst #2,%d0
beq.s ___a036d
or.w %d1,(%a0)+
bra.s ___c036d
___a036d:
and.w %d2,(%a0)+
___c036d:
btst #1,%d0
beq.s ___a036e
or.w %d1,(%a0)+
bra.s ___c036e
___a036e:
and.w %d2,(%a0)+
___c036e:
btst #0,%d0
beq.s ___a036f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a036f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale088:
tst.l %d0
bpl.s ___a0370
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0370
___a0370:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0370:
btst #30,%d0
beq.s ___a0371
or.w %d1,(%a0)+
bra.s ___c0371
___a0371:
and.w %d2,(%a0)+
___c0371:
btst #29,%d0
beq.s ___a0372
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0372
___a0372:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0372:
btst #28,%d0
beq.s ___a0373
or.w %d1,(%a0)+
bra.s ___c0373
___a0373:
and.w %d2,(%a0)+
___c0373:
btst #27,%d0
beq.s ___a0374
or.w %d1,(%a0)+
bra.s ___c0374
___a0374:
and.w %d2,(%a0)+
___c0374:
btst #26,%d0
beq.s ___a0375
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0375
___a0375:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0375:
btst #25,%d0
beq.s ___a0376
or.w %d1,(%a0)+
bra.s ___c0376
___a0376:
and.w %d2,(%a0)+
___c0376:
btst #24,%d0
beq.s ___a0377
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0377
___a0377:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0377:
btst #23,%d0
beq.s ___a0378
or.w %d1,(%a0)+
bra.s ___c0378
___a0378:
and.w %d2,(%a0)+
___c0378:
btst #22,%d0
beq.s ___a0379
or.w %d1,(%a0)+
bra.s ___c0379
___a0379:
and.w %d2,(%a0)+
___c0379:
btst #21,%d0
beq.s ___a037a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c037a
___a037a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c037a:
btst #20,%d0
beq.s ___a037b
or.w %d1,(%a0)+
bra.s ___c037b
___a037b:
and.w %d2,(%a0)+
___c037b:
btst #19,%d0
beq.s ___a037c
or.w %d1,(%a0)+
bra.s ___c037c
___a037c:
and.w %d2,(%a0)+
___c037c:
btst #18,%d0
beq.s ___a037d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c037d
___a037d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c037d:
btst #17,%d0
beq.s ___a037e
or.w %d1,(%a0)+
bra.s ___c037e
___a037e:
and.w %d2,(%a0)+
___c037e:
btst #16,%d0
beq.s ___a037f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c037f
___a037f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c037f:
tst.w %d0
bpl.s ___a0380
or.w %d1,(%a0)+
bra.s ___c0380
___a0380:
and.w %d2,(%a0)+
___c0380:
btst #14,%d0
beq.s ___a0381
or.w %d1,(%a0)+
bra.s ___c0381
___a0381:
and.w %d2,(%a0)+
___c0381:
btst #13,%d0
beq.s ___a0382
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0382
___a0382:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0382:
btst #12,%d0
beq.s ___a0383
or.w %d1,(%a0)+
bra.s ___c0383
___a0383:
and.w %d2,(%a0)+
___c0383:
btst #11,%d0
beq.s ___a0384
or.w %d1,(%a0)+
bra.s ___c0384
___a0384:
and.w %d2,(%a0)+
___c0384:
btst #10,%d0
beq.s ___a0385
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0385
___a0385:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0385:
btst #9,%d0
beq.s ___a0386
or.w %d1,(%a0)+
bra.s ___c0386
___a0386:
and.w %d2,(%a0)+
___c0386:
btst #8,%d0
beq.s ___a0387
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0387
___a0387:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0387:
tst.b %d0
bpl.s ___a0388
or.w %d1,(%a0)+
bra.s ___c0388
___a0388:
and.w %d2,(%a0)+
___c0388:
btst #6,%d0
beq.s ___a0389
or.w %d1,(%a0)+
bra.s ___c0389
___a0389:
and.w %d2,(%a0)+
___c0389:
btst #5,%d0
beq.s ___a038a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c038a
___a038a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c038a:
btst #4,%d0
beq.s ___a038b
or.w %d1,(%a0)+
bra.s ___c038b
___a038b:
and.w %d2,(%a0)+
___c038b:
btst #3,%d0
beq.s ___a038c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c038c
___a038c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c038c:
btst #2,%d0
beq.s ___a038d
or.w %d1,(%a0)+
bra.s ___c038d
___a038d:
and.w %d2,(%a0)+
___c038d:
btst #1,%d0
beq.s ___a038e
or.w %d1,(%a0)+
bra.s ___c038e
___a038e:
and.w %d2,(%a0)+
___c038e:
btst #0,%d0
beq.s ___a038f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a038f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale090:
tst.l %d0
bpl.s ___a0390
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0390
___a0390:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0390:
btst #30,%d0
beq.s ___a0391
or.w %d1,(%a0)+
bra.s ___c0391
___a0391:
and.w %d2,(%a0)+
___c0391:
btst #29,%d0
beq.s ___a0392
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0392
___a0392:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0392:
btst #28,%d0
beq.s ___a0393
or.w %d1,(%a0)+
bra.s ___c0393
___a0393:
and.w %d2,(%a0)+
___c0393:
btst #27,%d0
beq.s ___a0394
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0394
___a0394:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0394:
btst #26,%d0
beq.s ___a0395
or.w %d1,(%a0)+
bra.s ___c0395
___a0395:
and.w %d2,(%a0)+
___c0395:
btst #25,%d0
beq.s ___a0396
or.w %d1,(%a0)+
bra.s ___c0396
___a0396:
and.w %d2,(%a0)+
___c0396:
btst #24,%d0
beq.s ___a0397
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0397
___a0397:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0397:
btst #23,%d0
beq.s ___a0398
or.w %d1,(%a0)+
bra.s ___c0398
___a0398:
and.w %d2,(%a0)+
___c0398:
btst #22,%d0
beq.s ___a0399
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0399
___a0399:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0399:
btst #21,%d0
beq.s ___a039a
or.w %d1,(%a0)+
bra.s ___c039a
___a039a:
and.w %d2,(%a0)+
___c039a:
btst #20,%d0
beq.s ___a039b
or.w %d1,(%a0)+
bra.s ___c039b
___a039b:
and.w %d2,(%a0)+
___c039b:
btst #19,%d0
beq.s ___a039c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c039c
___a039c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c039c:
btst #18,%d0
beq.s ___a039d
or.w %d1,(%a0)+
bra.s ___c039d
___a039d:
and.w %d2,(%a0)+
___c039d:
btst #17,%d0
beq.s ___a039e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c039e
___a039e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c039e:
btst #16,%d0
beq.s ___a039f
or.w %d1,(%a0)+
bra.s ___c039f
___a039f:
and.w %d2,(%a0)+
___c039f:
tst.w %d0
bpl.s ___a03a0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03a0
___a03a0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03a0:
btst #14,%d0
beq.s ___a03a1
or.w %d1,(%a0)+
bra.s ___c03a1
___a03a1:
and.w %d2,(%a0)+
___c03a1:
btst #13,%d0
beq.s ___a03a2
or.w %d1,(%a0)+
bra.s ___c03a2
___a03a2:
and.w %d2,(%a0)+
___c03a2:
btst #12,%d0
beq.s ___a03a3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03a3
___a03a3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03a3:
btst #11,%d0
beq.s ___a03a4
or.w %d1,(%a0)+
bra.s ___c03a4
___a03a4:
and.w %d2,(%a0)+
___c03a4:
btst #10,%d0
beq.s ___a03a5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03a5
___a03a5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03a5:
btst #9,%d0
beq.s ___a03a6
or.w %d1,(%a0)+
bra.s ___c03a6
___a03a6:
and.w %d2,(%a0)+
___c03a6:
btst #8,%d0
beq.s ___a03a7
or.w %d1,(%a0)+
bra.s ___c03a7
___a03a7:
and.w %d2,(%a0)+
___c03a7:
tst.b %d0
bpl.s ___a03a8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03a8
___a03a8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03a8:
btst #6,%d0
beq.s ___a03a9
or.w %d1,(%a0)+
bra.s ___c03a9
___a03a9:
and.w %d2,(%a0)+
___c03a9:
btst #5,%d0
beq.s ___a03aa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03aa
___a03aa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03aa:
btst #4,%d0
beq.s ___a03ab
or.w %d1,(%a0)+
bra.s ___c03ab
___a03ab:
and.w %d2,(%a0)+
___c03ab:
btst #3,%d0
beq.s ___a03ac
or.w %d1,(%a0)+
bra.s ___c03ac
___a03ac:
and.w %d2,(%a0)+
___c03ac:
btst #2,%d0
beq.s ___a03ad
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03ad
___a03ad:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03ad:
btst #1,%d0
beq.s ___a03ae
or.w %d1,(%a0)+
bra.s ___c03ae
___a03ae:
and.w %d2,(%a0)+
___c03ae:
btst #0,%d0
beq.s ___a03af
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a03af:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale092:
tst.l %d0
bpl.s ___a03b0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03b0
___a03b0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03b0:
btst #30,%d0
beq.s ___a03b1
or.w %d1,(%a0)+
bra.s ___c03b1
___a03b1:
and.w %d2,(%a0)+
___c03b1:
btst #29,%d0
beq.s ___a03b2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03b2
___a03b2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03b2:
btst #28,%d0
beq.s ___a03b3
or.w %d1,(%a0)+
bra.s ___c03b3
___a03b3:
and.w %d2,(%a0)+
___c03b3:
btst #27,%d0
beq.s ___a03b4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03b4
___a03b4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03b4:
btst #26,%d0
beq.s ___a03b5
or.w %d1,(%a0)+
bra.s ___c03b5
___a03b5:
and.w %d2,(%a0)+
___c03b5:
btst #25,%d0
beq.s ___a03b6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03b6
___a03b6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03b6:
btst #24,%d0
beq.s ___a03b7
or.w %d1,(%a0)+
bra.s ___c03b7
___a03b7:
and.w %d2,(%a0)+
___c03b7:
btst #23,%d0
beq.s ___a03b8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03b8
___a03b8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03b8:
btst #22,%d0
beq.s ___a03b9
or.w %d1,(%a0)+
bra.s ___c03b9
___a03b9:
and.w %d2,(%a0)+
___c03b9:
btst #21,%d0
beq.s ___a03ba
or.w %d1,(%a0)+
bra.s ___c03ba
___a03ba:
and.w %d2,(%a0)+
___c03ba:
btst #20,%d0
beq.s ___a03bb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03bb
___a03bb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03bb:
btst #19,%d0
beq.s ___a03bc
or.w %d1,(%a0)+
bra.s ___c03bc
___a03bc:
and.w %d2,(%a0)+
___c03bc:
btst #18,%d0
beq.s ___a03bd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03bd
___a03bd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03bd:
btst #17,%d0
beq.s ___a03be
or.w %d1,(%a0)+
bra.s ___c03be
___a03be:
and.w %d2,(%a0)+
___c03be:
btst #16,%d0
beq.s ___a03bf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03bf
___a03bf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03bf:
tst.w %d0
bpl.s ___a03c0
or.w %d1,(%a0)+
bra.s ___c03c0
___a03c0:
and.w %d2,(%a0)+
___c03c0:
btst #14,%d0
beq.s ___a03c1
or.w %d1,(%a0)+
bra.s ___c03c1
___a03c1:
and.w %d2,(%a0)+
___c03c1:
btst #13,%d0
beq.s ___a03c2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03c2
___a03c2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03c2:
btst #12,%d0
beq.s ___a03c3
or.w %d1,(%a0)+
bra.s ___c03c3
___a03c3:
and.w %d2,(%a0)+
___c03c3:
btst #11,%d0
beq.s ___a03c4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03c4
___a03c4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03c4:
btst #10,%d0
beq.s ___a03c5
or.w %d1,(%a0)+
bra.s ___c03c5
___a03c5:
and.w %d2,(%a0)+
___c03c5:
btst #9,%d0
beq.s ___a03c6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03c6
___a03c6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03c6:
btst #8,%d0
beq.s ___a03c7
or.w %d1,(%a0)+
bra.s ___c03c7
___a03c7:
and.w %d2,(%a0)+
___c03c7:
tst.b %d0
bpl.s ___a03c8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03c8
___a03c8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03c8:
btst #6,%d0
beq.s ___a03c9
or.w %d1,(%a0)+
bra.s ___c03c9
___a03c9:
and.w %d2,(%a0)+
___c03c9:
btst #5,%d0
beq.s ___a03ca
or.w %d1,(%a0)+
bra.s ___c03ca
___a03ca:
and.w %d2,(%a0)+
___c03ca:
btst #4,%d0
beq.s ___a03cb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03cb
___a03cb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03cb:
btst #3,%d0
beq.s ___a03cc
or.w %d1,(%a0)+
bra.s ___c03cc
___a03cc:
and.w %d2,(%a0)+
___c03cc:
btst #2,%d0
beq.s ___a03cd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03cd
___a03cd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03cd:
btst #1,%d0
beq.s ___a03ce
or.w %d1,(%a0)+
bra.s ___c03ce
___a03ce:
and.w %d2,(%a0)+
___c03ce:
btst #0,%d0
beq.s ___a03cf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a03cf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale094:
tst.l %d0
bpl.s ___a03d0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03d0
___a03d0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03d0:
btst #30,%d0
beq.s ___a03d1
or.w %d1,(%a0)+
bra.s ___c03d1
___a03d1:
and.w %d2,(%a0)+
___c03d1:
btst #29,%d0
beq.s ___a03d2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03d2
___a03d2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03d2:
btst #28,%d0
beq.s ___a03d3
or.w %d1,(%a0)+
bra.s ___c03d3
___a03d3:
and.w %d2,(%a0)+
___c03d3:
btst #27,%d0
beq.s ___a03d4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03d4
___a03d4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03d4:
btst #26,%d0
beq.s ___a03d5
or.w %d1,(%a0)+
bra.s ___c03d5
___a03d5:
and.w %d2,(%a0)+
___c03d5:
btst #25,%d0
beq.s ___a03d6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03d6
___a03d6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03d6:
btst #24,%d0
beq.s ___a03d7
or.w %d1,(%a0)+
bra.s ___c03d7
___a03d7:
and.w %d2,(%a0)+
___c03d7:
btst #23,%d0
beq.s ___a03d8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03d8
___a03d8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03d8:
btst #22,%d0
beq.s ___a03d9
or.w %d1,(%a0)+
bra.s ___c03d9
___a03d9:
and.w %d2,(%a0)+
___c03d9:
btst #21,%d0
beq.s ___a03da
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03da
___a03da:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03da:
btst #20,%d0
beq.s ___a03db
or.w %d1,(%a0)+
bra.s ___c03db
___a03db:
and.w %d2,(%a0)+
___c03db:
btst #19,%d0
beq.s ___a03dc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03dc
___a03dc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03dc:
btst #18,%d0
beq.s ___a03dd
or.w %d1,(%a0)+
bra.s ___c03dd
___a03dd:
and.w %d2,(%a0)+
___c03dd:
btst #17,%d0
beq.s ___a03de
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03de
___a03de:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03de:
btst #16,%d0
beq.s ___a03df
or.w %d1,(%a0)+
bra.s ___c03df
___a03df:
and.w %d2,(%a0)+
___c03df:
tst.w %d0
bpl.s ___a03e0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03e0
___a03e0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03e0:
btst #14,%d0
beq.s ___a03e1
or.w %d1,(%a0)+
bra.s ___c03e1
___a03e1:
and.w %d2,(%a0)+
___c03e1:
btst #13,%d0
beq.s ___a03e2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03e2
___a03e2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03e2:
btst #12,%d0
beq.s ___a03e3
or.w %d1,(%a0)+
bra.s ___c03e3
___a03e3:
and.w %d2,(%a0)+
___c03e3:
btst #11,%d0
beq.s ___a03e4
or.w %d1,(%a0)+
bra.s ___c03e4
___a03e4:
and.w %d2,(%a0)+
___c03e4:
btst #10,%d0
beq.s ___a03e5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03e5
___a03e5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03e5:
btst #9,%d0
beq.s ___a03e6
or.w %d1,(%a0)+
bra.s ___c03e6
___a03e6:
and.w %d2,(%a0)+
___c03e6:
btst #8,%d0
beq.s ___a03e7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03e7
___a03e7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03e7:
tst.b %d0
bpl.s ___a03e8
or.w %d1,(%a0)+
bra.s ___c03e8
___a03e8:
and.w %d2,(%a0)+
___c03e8:
btst #6,%d0
beq.s ___a03e9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03e9
___a03e9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03e9:
btst #5,%d0
beq.s ___a03ea
or.w %d1,(%a0)+
bra.s ___c03ea
___a03ea:
and.w %d2,(%a0)+
___c03ea:
btst #4,%d0
beq.s ___a03eb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03eb
___a03eb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03eb:
btst #3,%d0
beq.s ___a03ec
or.w %d1,(%a0)+
bra.s ___c03ec
___a03ec:
and.w %d2,(%a0)+
___c03ec:
btst #2,%d0
beq.s ___a03ed
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03ed
___a03ed:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03ed:
btst #1,%d0
beq.s ___a03ee
or.w %d1,(%a0)+
bra.s ___c03ee
___a03ee:
and.w %d2,(%a0)+
___c03ee:
btst #0,%d0
beq.s ___a03ef
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a03ef:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale096:
tst.l %d0
bpl.s ___a03f0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f0
___a03f0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f0:
btst #30,%d0
beq.s ___a03f1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f1
___a03f1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f1:
btst #29,%d0
beq.s ___a03f2
or.w %d1,(%a0)+
bra.s ___c03f2
___a03f2:
and.w %d2,(%a0)+
___c03f2:
btst #28,%d0
beq.s ___a03f3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f3
___a03f3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f3:
btst #27,%d0
beq.s ___a03f4
or.w %d1,(%a0)+
bra.s ___c03f4
___a03f4:
and.w %d2,(%a0)+
___c03f4:
btst #26,%d0
beq.s ___a03f5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f5
___a03f5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f5:
btst #25,%d0
beq.s ___a03f6
or.w %d1,(%a0)+
bra.s ___c03f6
___a03f6:
and.w %d2,(%a0)+
___c03f6:
btst #24,%d0
beq.s ___a03f7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f7
___a03f7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f7:
btst #23,%d0
beq.s ___a03f8
or.w %d1,(%a0)+
bra.s ___c03f8
___a03f8:
and.w %d2,(%a0)+
___c03f8:
btst #22,%d0
beq.s ___a03f9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03f9
___a03f9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03f9:
btst #21,%d0
beq.s ___a03fa
or.w %d1,(%a0)+
bra.s ___c03fa
___a03fa:
and.w %d2,(%a0)+
___c03fa:
btst #20,%d0
beq.s ___a03fb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03fb
___a03fb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03fb:
btst #19,%d0
beq.s ___a03fc
or.w %d1,(%a0)+
bra.s ___c03fc
___a03fc:
and.w %d2,(%a0)+
___c03fc:
btst #18,%d0
beq.s ___a03fd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03fd
___a03fd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03fd:
btst #17,%d0
beq.s ___a03fe
or.w %d1,(%a0)+
bra.s ___c03fe
___a03fe:
and.w %d2,(%a0)+
___c03fe:
btst #16,%d0
beq.s ___a03ff
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c03ff
___a03ff:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c03ff:
tst.w %d0
bpl.s ___a0400
or.w %d1,(%a0)+
bra.s ___c0400
___a0400:
and.w %d2,(%a0)+
___c0400:
btst #14,%d0
beq.s ___a0401
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0401
___a0401:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0401:
btst #13,%d0
beq.s ___a0402
or.w %d1,(%a0)+
bra.s ___c0402
___a0402:
and.w %d2,(%a0)+
___c0402:
btst #12,%d0
beq.s ___a0403
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0403
___a0403:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0403:
btst #11,%d0
beq.s ___a0404
or.w %d1,(%a0)+
bra.s ___c0404
___a0404:
and.w %d2,(%a0)+
___c0404:
btst #10,%d0
beq.s ___a0405
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0405
___a0405:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0405:
btst #9,%d0
beq.s ___a0406
or.w %d1,(%a0)+
bra.s ___c0406
___a0406:
and.w %d2,(%a0)+
___c0406:
btst #8,%d0
beq.s ___a0407
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0407
___a0407:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0407:
tst.b %d0
bpl.s ___a0408
or.w %d1,(%a0)+
bra.s ___c0408
___a0408:
and.w %d2,(%a0)+
___c0408:
btst #6,%d0
beq.s ___a0409
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0409
___a0409:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0409:
btst #5,%d0
beq.s ___a040a
or.w %d1,(%a0)+
bra.s ___c040a
___a040a:
and.w %d2,(%a0)+
___c040a:
btst #4,%d0
beq.s ___a040b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c040b
___a040b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c040b:
btst #3,%d0
beq.s ___a040c
or.w %d1,(%a0)+
bra.s ___c040c
___a040c:
and.w %d2,(%a0)+
___c040c:
btst #2,%d0
beq.s ___a040d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c040d
___a040d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c040d:
btst #1,%d0
beq.s ___a040e
or.w %d1,(%a0)+
bra.s ___c040e
___a040e:
and.w %d2,(%a0)+
___c040e:
btst #0,%d0
beq.s ___a040f
or.w %d1,(%a0)+
rts
___a040f:
and.w %d2,(%a0)+
rts
__scale098:
tst.l %d0
bpl.s ___a0410
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0410
___a0410:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0410:
btst #30,%d0
beq.s ___a0411
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0411
___a0411:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0411:
btst #29,%d0
beq.s ___a0412
or.w %d1,(%a0)+
bra.s ___c0412
___a0412:
and.w %d2,(%a0)+
___c0412:
btst #28,%d0
beq.s ___a0413
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0413
___a0413:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0413:
btst #27,%d0
beq.s ___a0414
or.w %d1,(%a0)+
bra.s ___c0414
___a0414:
and.w %d2,(%a0)+
___c0414:
btst #26,%d0
beq.s ___a0415
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0415
___a0415:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0415:
btst #25,%d0
beq.s ___a0416
or.w %d1,(%a0)+
bra.s ___c0416
___a0416:
and.w %d2,(%a0)+
___c0416:
btst #24,%d0
beq.s ___a0417
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0417
___a0417:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0417:
btst #23,%d0
beq.s ___a0418
or.w %d1,(%a0)+
bra.s ___c0418
___a0418:
and.w %d2,(%a0)+
___c0418:
btst #22,%d0
beq.s ___a0419
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0419
___a0419:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0419:
btst #21,%d0
beq.s ___a041a
or.w %d1,(%a0)+
bra.s ___c041a
___a041a:
and.w %d2,(%a0)+
___c041a:
btst #20,%d0
beq.s ___a041b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c041b
___a041b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c041b:
btst #19,%d0
beq.s ___a041c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c041c
___a041c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c041c:
btst #18,%d0
beq.s ___a041d
or.w %d1,(%a0)+
bra.s ___c041d
___a041d:
and.w %d2,(%a0)+
___c041d:
btst #17,%d0
beq.s ___a041e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c041e
___a041e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c041e:
btst #16,%d0
beq.s ___a041f
or.w %d1,(%a0)+
bra.s ___c041f
___a041f:
and.w %d2,(%a0)+
___c041f:
tst.w %d0
bpl.s ___a0420
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0420
___a0420:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0420:
btst #14,%d0
beq.s ___a0421
or.w %d1,(%a0)+
bra.s ___c0421
___a0421:
and.w %d2,(%a0)+
___c0421:
btst #13,%d0
beq.s ___a0422
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0422
___a0422:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0422:
btst #12,%d0
beq.s ___a0423
or.w %d1,(%a0)+
bra.s ___c0423
___a0423:
and.w %d2,(%a0)+
___c0423:
btst #11,%d0
beq.s ___a0424
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0424
___a0424:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0424:
btst #10,%d0
beq.s ___a0425
or.w %d1,(%a0)+
bra.s ___c0425
___a0425:
and.w %d2,(%a0)+
___c0425:
btst #9,%d0
beq.s ___a0426
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0426
___a0426:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0426:
btst #8,%d0
beq.s ___a0427
or.w %d1,(%a0)+
bra.s ___c0427
___a0427:
and.w %d2,(%a0)+
___c0427:
tst.b %d0
bpl.s ___a0428
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0428
___a0428:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0428:
btst #6,%d0
beq.s ___a0429
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0429
___a0429:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0429:
btst #5,%d0
beq.s ___a042a
or.w %d1,(%a0)+
bra.s ___c042a
___a042a:
and.w %d2,(%a0)+
___c042a:
btst #4,%d0
beq.s ___a042b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c042b
___a042b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c042b:
btst #3,%d0
beq.s ___a042c
or.w %d1,(%a0)+
bra.s ___c042c
___a042c:
and.w %d2,(%a0)+
___c042c:
btst #2,%d0
beq.s ___a042d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c042d
___a042d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c042d:
btst #1,%d0
beq.s ___a042e
or.w %d1,(%a0)+
rts
___a042e:
and.w %d2,(%a0)+
rts
__scale100:
btst #30,%d0
beq.s ___a042f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c042f
___a042f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c042f:
btst #29,%d0
beq.s ___a0430
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0430
___a0430:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0430:
btst #28,%d0
beq.s ___a0431
or.w %d1,(%a0)+
bra.s ___c0431
___a0431:
and.w %d2,(%a0)+
___c0431:
btst #27,%d0
beq.s ___a0432
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0432
___a0432:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0432:
btst #26,%d0
beq.s ___a0433
or.w %d1,(%a0)+
bra.s ___c0433
___a0433:
and.w %d2,(%a0)+
___c0433:
btst #25,%d0
beq.s ___a0434
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0434
___a0434:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0434:
btst #24,%d0
beq.s ___a0435
or.w %d1,(%a0)+
bra.s ___c0435
___a0435:
and.w %d2,(%a0)+
___c0435:
btst #23,%d0
beq.s ___a0436
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0436
___a0436:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0436:
btst #22,%d0
beq.s ___a0437
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0437
___a0437:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0437:
btst #21,%d0
beq.s ___a0438
or.w %d1,(%a0)+
bra.s ___c0438
___a0438:
and.w %d2,(%a0)+
___c0438:
btst #20,%d0
beq.s ___a0439
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0439
___a0439:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0439:
btst #19,%d0
beq.s ___a043a
or.w %d1,(%a0)+
bra.s ___c043a
___a043a:
and.w %d2,(%a0)+
___c043a:
btst #18,%d0
beq.s ___a043b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c043b
___a043b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c043b:
btst #17,%d0
beq.s ___a043c
or.w %d1,(%a0)+
bra.s ___c043c
___a043c:
and.w %d2,(%a0)+
___c043c:
btst #16,%d0
beq.s ___a043d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c043d
___a043d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c043d:
tst.w %d0
bpl.s ___a043e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c043e
___a043e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c043e:
btst #14,%d0
beq.s ___a043f
or.w %d1,(%a0)+
bra.s ___c043f
___a043f:
and.w %d2,(%a0)+
___c043f:
btst #13,%d0
beq.s ___a0440
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0440
___a0440:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0440:
btst #12,%d0
beq.s ___a0441
or.w %d1,(%a0)+
bra.s ___c0441
___a0441:
and.w %d2,(%a0)+
___c0441:
btst #11,%d0
beq.s ___a0442
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0442
___a0442:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0442:
btst #10,%d0
beq.s ___a0443
or.w %d1,(%a0)+
bra.s ___c0443
___a0443:
and.w %d2,(%a0)+
___c0443:
btst #9,%d0
beq.s ___a0444
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0444
___a0444:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0444:
btst #8,%d0
beq.s ___a0445
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0445
___a0445:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0445:
tst.b %d0
bpl.s ___a0446
or.w %d1,(%a0)+
bra.s ___c0446
___a0446:
and.w %d2,(%a0)+
___c0446:
btst #6,%d0
beq.s ___a0447
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0447
___a0447:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0447:
btst #5,%d0
beq.s ___a0448
or.w %d1,(%a0)+
bra.s ___c0448
___a0448:
and.w %d2,(%a0)+
___c0448:
btst #4,%d0
beq.s ___a0449
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0449
___a0449:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0449:
btst #3,%d0
beq.s ___a044a
or.w %d1,(%a0)+
bra.s ___c044a
___a044a:
and.w %d2,(%a0)+
___c044a:
btst #2,%d0
beq.s ___a044b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c044b
___a044b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c044b:
btst #1,%d0
beq.s ___a044c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a044c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale102:
btst #30,%d0
beq.s ___a044d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c044d
___a044d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c044d:
btst #29,%d0
beq.s ___a044e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c044e
___a044e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c044e:
btst #28,%d0
beq.s ___a044f
or.w %d1,(%a0)+
bra.s ___c044f
___a044f:
and.w %d2,(%a0)+
___c044f:
btst #27,%d0
beq.s ___a0450
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0450
___a0450:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0450:
btst #26,%d0
beq.s ___a0451
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0451
___a0451:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0451:
btst #25,%d0
beq.s ___a0452
or.w %d1,(%a0)+
bra.s ___c0452
___a0452:
and.w %d2,(%a0)+
___c0452:
btst #24,%d0
beq.s ___a0453
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0453
___a0453:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0453:
btst #23,%d0
beq.s ___a0454
or.w %d1,(%a0)+
bra.s ___c0454
___a0454:
and.w %d2,(%a0)+
___c0454:
btst #22,%d0
beq.s ___a0455
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0455
___a0455:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0455:
btst #21,%d0
beq.s ___a0456
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0456
___a0456:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0456:
btst #20,%d0
beq.s ___a0457
or.w %d1,(%a0)+
bra.s ___c0457
___a0457:
and.w %d2,(%a0)+
___c0457:
btst #19,%d0
beq.s ___a0458
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0458
___a0458:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0458:
btst #18,%d0
beq.s ___a0459
or.w %d1,(%a0)+
bra.s ___c0459
___a0459:
and.w %d2,(%a0)+
___c0459:
btst #17,%d0
beq.s ___a045a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c045a
___a045a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c045a:
btst #16,%d0
beq.s ___a045b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c045b
___a045b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c045b:
tst.w %d0
bpl.s ___a045c
or.w %d1,(%a0)+
bra.s ___c045c
___a045c:
and.w %d2,(%a0)+
___c045c:
btst #14,%d0
beq.s ___a045d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c045d
___a045d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c045d:
btst #13,%d0
beq.s ___a045e
or.w %d1,(%a0)+
bra.s ___c045e
___a045e:
and.w %d2,(%a0)+
___c045e:
btst #12,%d0
beq.s ___a045f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c045f
___a045f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c045f:
btst #11,%d0
beq.s ___a0460
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0460
___a0460:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0460:
btst #10,%d0
beq.s ___a0461
or.w %d1,(%a0)+
bra.s ___c0461
___a0461:
and.w %d2,(%a0)+
___c0461:
btst #9,%d0
beq.s ___a0462
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0462
___a0462:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0462:
btst #8,%d0
beq.s ___a0463
or.w %d1,(%a0)+
bra.s ___c0463
___a0463:
and.w %d2,(%a0)+
___c0463:
tst.b %d0
bpl.s ___a0464
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0464
___a0464:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0464:
btst #6,%d0
beq.s ___a0465
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0465
___a0465:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0465:
btst #5,%d0
beq.s ___a0466
or.w %d1,(%a0)+
bra.s ___c0466
___a0466:
and.w %d2,(%a0)+
___c0466:
btst #4,%d0
beq.s ___a0467
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0467
___a0467:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0467:
btst #3,%d0
beq.s ___a0468
or.w %d1,(%a0)+
bra.s ___c0468
___a0468:
and.w %d2,(%a0)+
___c0468:
btst #2,%d0
beq.s ___a0469
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0469
___a0469:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0469:
btst #1,%d0
beq.s ___a046a
or.w %d1,(%a0)+
rts
___a046a:
and.w %d2,(%a0)+
rts
__scale104:
btst #29,%d0
beq.s ___a046b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c046b
___a046b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c046b:
btst #28,%d0
beq.s ___a046c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c046c
___a046c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c046c:
btst #27,%d0
beq.s ___a046d
or.w %d1,(%a0)+
bra.s ___c046d
___a046d:
and.w %d2,(%a0)+
___c046d:
btst #26,%d0
beq.s ___a046e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c046e
___a046e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c046e:
btst #25,%d0
beq.s ___a046f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c046f
___a046f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c046f:
btst #24,%d0
beq.s ___a0470
or.w %d1,(%a0)+
bra.s ___c0470
___a0470:
and.w %d2,(%a0)+
___c0470:
btst #23,%d0
beq.s ___a0471
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0471
___a0471:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0471:
btst #22,%d0
beq.s ___a0472
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0472
___a0472:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0472:
btst #21,%d0
beq.s ___a0473
or.w %d1,(%a0)+
bra.s ___c0473
___a0473:
and.w %d2,(%a0)+
___c0473:
btst #20,%d0
beq.s ___a0474
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0474
___a0474:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0474:
btst #19,%d0
beq.s ___a0475
or.w %d1,(%a0)+
bra.s ___c0475
___a0475:
and.w %d2,(%a0)+
___c0475:
btst #18,%d0
beq.s ___a0476
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0476
___a0476:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0476:
btst #17,%d0
beq.s ___a0477
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0477
___a0477:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0477:
btst #16,%d0
beq.s ___a0478
or.w %d1,(%a0)+
bra.s ___c0478
___a0478:
and.w %d2,(%a0)+
___c0478:
tst.w %d0
bpl.s ___a0479
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0479
___a0479:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0479:
btst #14,%d0
beq.s ___a047a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c047a
___a047a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c047a:
btst #13,%d0
beq.s ___a047b
or.w %d1,(%a0)+
bra.s ___c047b
___a047b:
and.w %d2,(%a0)+
___c047b:
btst #12,%d0
beq.s ___a047c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c047c
___a047c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c047c:
btst #11,%d0
beq.s ___a047d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c047d
___a047d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c047d:
btst #10,%d0
beq.s ___a047e
or.w %d1,(%a0)+
bra.s ___c047e
___a047e:
and.w %d2,(%a0)+
___c047e:
btst #9,%d0
beq.s ___a047f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c047f
___a047f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c047f:
btst #8,%d0
beq.s ___a0480
or.w %d1,(%a0)+
bra.s ___c0480
___a0480:
and.w %d2,(%a0)+
___c0480:
tst.b %d0
bpl.s ___a0481
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0481
___a0481:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0481:
btst #6,%d0
beq.s ___a0482
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0482
___a0482:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0482:
btst #5,%d0
beq.s ___a0483
or.w %d1,(%a0)+
bra.s ___c0483
___a0483:
and.w %d2,(%a0)+
___c0483:
btst #4,%d0
beq.s ___a0484
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0484
___a0484:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0484:
btst #3,%d0
beq.s ___a0485
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0485
___a0485:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0485:
btst #2,%d0
beq.s ___a0486
or.w %d1,(%a0)+
bra.s ___c0486
___a0486:
and.w %d2,(%a0)+
___c0486:
btst #1,%d0
beq.s ___a0487
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a0487:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale106:
btst #28,%d0
beq.s ___a0488
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0488
___a0488:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0488:
btst #27,%d0
beq.s ___a0489
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0489
___a0489:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0489:
btst #26,%d0
beq.s ___a048a
or.w %d1,(%a0)+
bra.s ___c048a
___a048a:
and.w %d2,(%a0)+
___c048a:
btst #25,%d0
beq.s ___a048b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c048b
___a048b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c048b:
btst #24,%d0
beq.s ___a048c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c048c
___a048c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c048c:
btst #23,%d0
beq.s ___a048d
or.w %d1,(%a0)+
bra.s ___c048d
___a048d:
and.w %d2,(%a0)+
___c048d:
btst #22,%d0
beq.s ___a048e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c048e
___a048e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c048e:
btst #21,%d0
beq.s ___a048f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c048f
___a048f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c048f:
btst #20,%d0
beq.s ___a0490
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0490
___a0490:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0490:
btst #19,%d0
beq.s ___a0491
or.w %d1,(%a0)+
bra.s ___c0491
___a0491:
and.w %d2,(%a0)+
___c0491:
btst #18,%d0
beq.s ___a0492
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0492
___a0492:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0492:
btst #17,%d0
beq.s ___a0493
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0493
___a0493:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0493:
btst #16,%d0
beq.s ___a0494
or.w %d1,(%a0)+
bra.s ___c0494
___a0494:
and.w %d2,(%a0)+
___c0494:
tst.w %d0
bpl.s ___a0495
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0495
___a0495:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0495:
btst #14,%d0
beq.s ___a0496
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0496
___a0496:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0496:
btst #13,%d0
beq.s ___a0497
or.w %d1,(%a0)+
bra.s ___c0497
___a0497:
and.w %d2,(%a0)+
___c0497:
btst #12,%d0
beq.s ___a0498
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0498
___a0498:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0498:
btst #11,%d0
beq.s ___a0499
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0499
___a0499:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0499:
btst #10,%d0
beq.s ___a049a
or.w %d1,(%a0)+
bra.s ___c049a
___a049a:
and.w %d2,(%a0)+
___c049a:
btst #9,%d0
beq.s ___a049b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c049b
___a049b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c049b:
btst #8,%d0
beq.s ___a049c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c049c
___a049c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c049c:
tst.b %d0
bpl.s ___a049d
or.w %d1,(%a0)+
bra.s ___c049d
___a049d:
and.w %d2,(%a0)+
___c049d:
btst #6,%d0
beq.s ___a049e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c049e
___a049e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c049e:
btst #5,%d0
beq.s ___a049f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c049f
___a049f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c049f:
btst #4,%d0
beq.s ___a04a0
or.w %d1,(%a0)+
bra.s ___c04a0
___a04a0:
and.w %d2,(%a0)+
___c04a0:
btst #3,%d0
beq.s ___a04a1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a1
___a04a1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a1:
btst #2,%d0
beq.s ___a04a2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a2
___a04a2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a2:
btst #1,%d0
beq.s ___a04a3
or.w %d1,(%a0)+
bra.s ___c04a3
___a04a3:
and.w %d2,(%a0)+
___c04a3:
btst #0,%d0
beq.s ___a04a4
or.w %d1,(%a0)+
rts
___a04a4:
and.w %d2,(%a0)+
rts
__scale108:
btst #28,%d0
beq.s ___a04a5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a5
___a04a5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a5:
btst #27,%d0
beq.s ___a04a6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a6
___a04a6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a6:
btst #26,%d0
beq.s ___a04a7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a7
___a04a7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a7:
btst #25,%d0
beq.s ___a04a8
or.w %d1,(%a0)+
bra.s ___c04a8
___a04a8:
and.w %d2,(%a0)+
___c04a8:
btst #24,%d0
beq.s ___a04a9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04a9
___a04a9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04a9:
btst #23,%d0
beq.s ___a04aa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04aa
___a04aa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04aa:
btst #22,%d0
beq.s ___a04ab
or.w %d1,(%a0)+
bra.s ___c04ab
___a04ab:
and.w %d2,(%a0)+
___c04ab:
btst #21,%d0
beq.s ___a04ac
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ac
___a04ac:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ac:
btst #20,%d0
beq.s ___a04ad
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ad
___a04ad:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ad:
btst #19,%d0
beq.s ___a04ae
or.w %d1,(%a0)+
bra.s ___c04ae
___a04ae:
and.w %d2,(%a0)+
___c04ae:
btst #18,%d0
beq.s ___a04af
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04af
___a04af:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04af:
btst #17,%d0
beq.s ___a04b0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b0
___a04b0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b0:
btst #16,%d0
beq.s ___a04b1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b1
___a04b1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b1:
tst.w %d0
bpl.s ___a04b2
or.w %d1,(%a0)+
bra.s ___c04b2
___a04b2:
and.w %d2,(%a0)+
___c04b2:
btst #14,%d0
beq.s ___a04b3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b3
___a04b3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b3:
btst #13,%d0
beq.s ___a04b4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b4
___a04b4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b4:
btst #12,%d0
beq.s ___a04b5
or.w %d1,(%a0)+
bra.s ___c04b5
___a04b5:
and.w %d2,(%a0)+
___c04b5:
btst #11,%d0
beq.s ___a04b6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b6
___a04b6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b6:
btst #10,%d0
beq.s ___a04b7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b7
___a04b7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b7:
btst #9,%d0
beq.s ___a04b8
or.w %d1,(%a0)+
bra.s ___c04b8
___a04b8:
and.w %d2,(%a0)+
___c04b8:
btst #8,%d0
beq.s ___a04b9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04b9
___a04b9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04b9:
tst.b %d0
bpl.s ___a04ba
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ba
___a04ba:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ba:
btst #6,%d0
beq.s ___a04bb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04bb
___a04bb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04bb:
btst #5,%d0
beq.s ___a04bc
or.w %d1,(%a0)+
bra.s ___c04bc
___a04bc:
and.w %d2,(%a0)+
___c04bc:
btst #4,%d0
beq.s ___a04bd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04bd
___a04bd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04bd:
btst #3,%d0
beq.s ___a04be
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04be
___a04be:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04be:
btst #2,%d0
beq.s ___a04bf
or.w %d1,(%a0)+
bra.s ___c04bf
___a04bf:
and.w %d2,(%a0)+
___c04bf:
btst #1,%d0
beq.s ___a04c0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a04c0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale110:
btst #27,%d0
beq.s ___a04c1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c1
___a04c1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c1:
btst #26,%d0
beq.s ___a04c2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c2
___a04c2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c2:
btst #25,%d0
beq.s ___a04c3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c3
___a04c3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c3:
btst #24,%d0
beq.s ___a04c4
or.w %d1,(%a0)+
bra.s ___c04c4
___a04c4:
and.w %d2,(%a0)+
___c04c4:
btst #23,%d0
beq.s ___a04c5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c5
___a04c5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c5:
btst #22,%d0
beq.s ___a04c6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c6
___a04c6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c6:
btst #21,%d0
beq.s ___a04c7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c7
___a04c7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c7:
btst #20,%d0
beq.s ___a04c8
or.w %d1,(%a0)+
bra.s ___c04c8
___a04c8:
and.w %d2,(%a0)+
___c04c8:
btst #19,%d0
beq.s ___a04c9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04c9
___a04c9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04c9:
btst #18,%d0
beq.s ___a04ca
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ca
___a04ca:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ca:
btst #17,%d0
beq.s ___a04cb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04cb
___a04cb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04cb:
btst #16,%d0
beq.s ___a04cc
or.w %d1,(%a0)+
bra.s ___c04cc
___a04cc:
and.w %d2,(%a0)+
___c04cc:
tst.w %d0
bpl.s ___a04cd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04cd
___a04cd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04cd:
btst #14,%d0
beq.s ___a04ce
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ce
___a04ce:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ce:
btst #13,%d0
beq.s ___a04cf
or.w %d1,(%a0)+
bra.s ___c04cf
___a04cf:
and.w %d2,(%a0)+
___c04cf:
btst #12,%d0
beq.s ___a04d0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d0
___a04d0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d0:
btst #11,%d0
beq.s ___a04d1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d1
___a04d1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d1:
btst #10,%d0
beq.s ___a04d2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d2
___a04d2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d2:
btst #9,%d0
beq.s ___a04d3
or.w %d1,(%a0)+
bra.s ___c04d3
___a04d3:
and.w %d2,(%a0)+
___c04d3:
btst #8,%d0
beq.s ___a04d4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d4
___a04d4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d4:
tst.b %d0
bpl.s ___a04d5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d5
___a04d5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d5:
btst #6,%d0
beq.s ___a04d6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d6
___a04d6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d6:
btst #5,%d0
beq.s ___a04d7
or.w %d1,(%a0)+
bra.s ___c04d7
___a04d7:
and.w %d2,(%a0)+
___c04d7:
btst #4,%d0
beq.s ___a04d8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d8
___a04d8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d8:
btst #3,%d0
beq.s ___a04d9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04d9
___a04d9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04d9:
btst #2,%d0
beq.s ___a04da
or.w %d1,(%a0)+
bra.s ___c04da
___a04da:
and.w %d2,(%a0)+
___c04da:
btst #1,%d0
beq.s ___a04db
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04db
___a04db:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04db:
btst #0,%d0
beq.s ___a04dc
or.w %d1,(%a0)+
rts
___a04dc:
and.w %d2,(%a0)+
rts
__scale114:
btst #26,%d0
beq.s ___a04dd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04dd
___a04dd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04dd:
btst #25,%d0
beq.s ___a04de
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04de
___a04de:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04de:
btst #24,%d0
beq.s ___a04df
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04df
___a04df:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04df:
btst #23,%d0
beq.s ___a04e0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e0
___a04e0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e0:
btst #22,%d0
beq.s ___a04e1
or.w %d1,(%a0)+
bra.s ___c04e1
___a04e1:
and.w %d2,(%a0)+
___c04e1:
btst #21,%d0
beq.s ___a04e2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e2
___a04e2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e2:
btst #20,%d0
beq.s ___a04e3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e3
___a04e3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e3:
btst #19,%d0
beq.s ___a04e4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e4
___a04e4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e4:
btst #18,%d0
beq.s ___a04e5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e5
___a04e5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e5:
btst #17,%d0
beq.s ___a04e6
or.w %d1,(%a0)+
bra.s ___c04e6
___a04e6:
and.w %d2,(%a0)+
___c04e6:
btst #16,%d0
beq.s ___a04e7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e7
___a04e7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e7:
tst.w %d0
bpl.s ___a04e8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e8
___a04e8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e8:
btst #14,%d0
beq.s ___a04e9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04e9
___a04e9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04e9:
btst #13,%d0
beq.s ___a04ea
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ea
___a04ea:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ea:
btst #12,%d0
beq.s ___a04eb
or.w %d1,(%a0)+
bra.s ___c04eb
___a04eb:
and.w %d2,(%a0)+
___c04eb:
btst #11,%d0
beq.s ___a04ec
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ec
___a04ec:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ec:
btst #10,%d0
beq.s ___a04ed
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ed
___a04ed:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ed:
btst #9,%d0
beq.s ___a04ee
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ee
___a04ee:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ee:
btst #8,%d0
beq.s ___a04ef
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04ef
___a04ef:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04ef:
tst.b %d0
bpl.s ___a04f0
or.w %d1,(%a0)+
bra.s ___c04f0
___a04f0:
and.w %d2,(%a0)+
___c04f0:
btst #6,%d0
beq.s ___a04f1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f1
___a04f1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f1:
btst #5,%d0
beq.s ___a04f2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f2
___a04f2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f2:
btst #4,%d0
beq.s ___a04f3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f3
___a04f3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f3:
btst #3,%d0
beq.s ___a04f4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f4
___a04f4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f4:
btst #2,%d0
beq.s ___a04f5
or.w %d1,(%a0)+
bra.s ___c04f5
___a04f5:
and.w %d2,(%a0)+
___c04f5:
btst #1,%d0
beq.s ___a04f6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f6
___a04f6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f6:
btst #0,%d0
beq.s ___a04f7
or.w %d1,(%a0)+
rts
___a04f7:
and.w %d2,(%a0)+
rts
__scale118:
btst #26,%d0
beq.s ___a04f8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f8
___a04f8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f8:
btst #25,%d0
beq.s ___a04f9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04f9
___a04f9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04f9:
btst #24,%d0
beq.s ___a04fa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04fa
___a04fa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04fa:
btst #23,%d0
beq.s ___a04fb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04fb
___a04fb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04fb:
btst #22,%d0
beq.s ___a04fc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04fc
___a04fc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04fc:
btst #21,%d0
beq.s ___a04fd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04fd
___a04fd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04fd:
btst #20,%d0
beq.s ___a04fe
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c04fe
___a04fe:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c04fe:
btst #19,%d0
beq.s ___a04ff
or.w %d1,(%a0)+
bra.s ___c04ff
___a04ff:
and.w %d2,(%a0)+
___c04ff:
btst #18,%d0
beq.s ___a0500
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0500
___a0500:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0500:
btst #17,%d0
beq.s ___a0501
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0501
___a0501:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0501:
btst #16,%d0
beq.s ___a0502
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0502
___a0502:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0502:
tst.w %d0
bpl.s ___a0503
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0503
___a0503:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0503:
btst #14,%d0
beq.s ___a0504
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0504
___a0504:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0504:
btst #13,%d0
beq.s ___a0505
or.w %d1,(%a0)+
bra.s ___c0505
___a0505:
and.w %d2,(%a0)+
___c0505:
btst #12,%d0
beq.s ___a0506
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0506
___a0506:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0506:
btst #11,%d0
beq.s ___a0507
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0507
___a0507:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0507:
btst #10,%d0
beq.s ___a0508
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0508
___a0508:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0508:
btst #9,%d0
beq.s ___a0509
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0509
___a0509:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0509:
btst #8,%d0
beq.s ___a050a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c050a
___a050a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c050a:
tst.b %d0
bpl.s ___a050b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c050b
___a050b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c050b:
btst #6,%d0
beq.s ___a050c
or.w %d1,(%a0)+
bra.s ___c050c
___a050c:
and.w %d2,(%a0)+
___c050c:
btst #5,%d0
beq.s ___a050d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c050d
___a050d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c050d:
btst #4,%d0
beq.s ___a050e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c050e
___a050e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c050e:
btst #3,%d0
beq.s ___a050f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c050f
___a050f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c050f:
btst #2,%d0
beq.s ___a0510
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0510
___a0510:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0510:
btst #1,%d0
beq.s ___a0511
or.w %d1,(%a0)+
rts
___a0511:
and.w %d2,(%a0)+
rts
__scale122:
btst #25,%d0
beq.s ___a0512
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0512
___a0512:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0512:
btst #24,%d0
beq.s ___a0513
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0513
___a0513:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0513:
btst #23,%d0
beq.s ___a0514
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0514
___a0514:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0514:
btst #22,%d0
beq.s ___a0515
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0515
___a0515:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0515:
btst #21,%d0
beq.s ___a0516
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0516
___a0516:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0516:
btst #20,%d0
beq.s ___a0517
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0517
___a0517:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0517:
btst #19,%d0
beq.s ___a0518
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0518
___a0518:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0518:
btst #18,%d0
beq.s ___a0519
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0519
___a0519:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0519:
btst #17,%d0
beq.s ___a051a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c051a
___a051a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c051a:
btst #16,%d0
beq.s ___a051b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c051b
___a051b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c051b:
tst.w %d0
bpl.s ___a051c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c051c
___a051c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c051c:
btst #14,%d0
beq.s ___a051d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c051d
___a051d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c051d:
btst #13,%d0
beq.s ___a051e
or.w %d1,(%a0)+
bra.s ___c051e
___a051e:
and.w %d2,(%a0)+
___c051e:
btst #12,%d0
beq.s ___a051f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c051f
___a051f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c051f:
btst #11,%d0
beq.s ___a0520
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0520
___a0520:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0520:
btst #10,%d0
beq.s ___a0521
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0521
___a0521:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0521:
btst #9,%d0
beq.s ___a0522
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0522
___a0522:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0522:
btst #8,%d0
beq.s ___a0523
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0523
___a0523:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0523:
tst.b %d0
bpl.s ___a0524
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0524
___a0524:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0524:
btst #6,%d0
beq.s ___a0525
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0525
___a0525:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0525:
btst #5,%d0
beq.s ___a0526
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0526
___a0526:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0526:
btst #4,%d0
beq.s ___a0527
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0527
___a0527:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0527:
btst #3,%d0
beq.s ___a0528
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0528
___a0528:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0528:
btst #2,%d0
beq.s ___a0529
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0529
___a0529:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0529:
btst #1,%d0
beq.s ___a052a
or.w %d1,(%a0)+
rts
___a052a:
and.w %d2,(%a0)+
rts
__scale126:
btst #24,%d0
beq.s ___a052b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c052b
___a052b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c052b:
btst #23,%d0
beq.s ___a052c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c052c
___a052c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c052c:
btst #22,%d0
beq.s ___a052d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c052d
___a052d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c052d:
btst #21,%d0
beq.s ___a052e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c052e
___a052e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c052e:
btst #20,%d0
beq.s ___a052f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c052f
___a052f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c052f:
btst #19,%d0
beq.s ___a0530
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0530
___a0530:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0530:
btst #18,%d0
beq.s ___a0531
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0531
___a0531:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0531:
btst #17,%d0
beq.s ___a0532
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0532
___a0532:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0532:
btst #16,%d0
beq.s ___a0533
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0533
___a0533:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0533:
tst.w %d0
bpl.s ___a0534
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0534
___a0534:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0534:
btst #14,%d0
beq.s ___a0535
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0535
___a0535:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0535:
btst #13,%d0
beq.s ___a0536
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0536
___a0536:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0536:
btst #12,%d0
beq.s ___a0537
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0537
___a0537:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0537:
btst #11,%d0
beq.s ___a0538
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0538
___a0538:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0538:
btst #10,%d0
beq.s ___a0539
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0539
___a0539:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0539:
btst #9,%d0
beq.s ___a053a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053a
___a053a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053a:
btst #8,%d0
beq.s ___a053b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053b
___a053b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053b:
tst.b %d0
bpl.s ___a053c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053c
___a053c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053c:
btst #6,%d0
beq.s ___a053d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053d
___a053d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053d:
btst #5,%d0
beq.s ___a053e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053e
___a053e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053e:
btst #4,%d0
beq.s ___a053f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c053f
___a053f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c053f:
btst #3,%d0
beq.s ___a0540
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0540
___a0540:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0540:
btst #2,%d0
beq.s ___a0541
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0541
___a0541:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0541:
btst #1,%d0
beq.s ___a0542
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a0542:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale130:
btst #23,%d0
beq.s ___a0543
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0543
___a0543:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0543:
btst #22,%d0
beq.s ___a0544
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0544
___a0544:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0544:
btst #21,%d0
beq.s ___a0545
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0545
___a0545:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0545:
btst #20,%d0
beq.s ___a0546
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0546
___a0546:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0546:
btst #19,%d0
beq.s ___a0547
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0547
___a0547:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0547:
btst #18,%d0
beq.s ___a0548
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0548
___a0548:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0548:
btst #17,%d0
beq.s ___a0549
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0549
___a0549:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0549:
btst #16,%d0
beq.s ___a054a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054a
___a054a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054a:
tst.w %d0
bpl.s ___a054b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054b
___a054b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054b:
btst #14,%d0
beq.s ___a054c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054c
___a054c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054c:
btst #13,%d0
beq.s ___a054d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054d
___a054d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054d:
btst #12,%d0
beq.s ___a054e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054e
___a054e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054e:
btst #11,%d0
beq.s ___a054f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c054f
___a054f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c054f:
btst #10,%d0
beq.s ___a0550
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0550
___a0550:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0550:
btst #9,%d0
beq.s ___a0551
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0551
___a0551:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0551:
btst #8,%d0
beq.s ___a0552
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0552
___a0552:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0552:
tst.b %d0
bpl.s ___a0553
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0553
___a0553:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0553:
btst #6,%d0
beq.s ___a0554
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0554
___a0554:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0554:
btst #5,%d0
beq.s ___a0555
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0555
___a0555:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0555:
btst #4,%d0
beq.s ___a0556
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0556
___a0556:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0556:
btst #3,%d0
beq.s ___a0557
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0557
___a0557:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0557:
btst #2,%d0
beq.s ___a0558
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0558
___a0558:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0558:
btst #1,%d0
beq.s ___a0559
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a0559:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale136:
btst #22,%d0
beq.s ___a055a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055a
___a055a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055a:
btst #21,%d0
beq.s ___a055b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055b
___a055b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055b:
btst #20,%d0
beq.s ___a055c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055c
___a055c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055c:
btst #19,%d0
beq.s ___a055d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055d
___a055d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055d:
btst #18,%d0
beq.s ___a055e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055e
___a055e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055e:
btst #17,%d0
beq.s ___a055f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c055f
___a055f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c055f:
btst #16,%d0
beq.s ___a0560
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0560
___a0560:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0560:
tst.w %d0
bpl.s ___a0561
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0561
___a0561:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0561:
btst #14,%d0
beq.s ___a0562
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0562
___a0562:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0562:
btst #13,%d0
beq.s ___a0563
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0563
___a0563:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0563:
btst #12,%d0
beq.s ___a0564
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0564
___a0564:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0564:
btst #11,%d0
beq.s ___a0565
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0565
___a0565:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0565:
btst #10,%d0
beq.s ___a0566
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0566
___a0566:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0566:
btst #9,%d0
beq.s ___a0567
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0567
___a0567:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0567:
btst #8,%d0
beq.s ___a0568
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0568
___a0568:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0568:
tst.b %d0
bpl.s ___a0569
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0569
___a0569:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0569:
btst #6,%d0
beq.s ___a056a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c056a
___a056a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c056a:
btst #5,%d0
beq.s ___a056b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c056b
___a056b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c056b:
btst #4,%d0
beq.s ___a056c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c056c
___a056c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c056c:
btst #3,%d0
beq.s ___a056d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c056d
___a056d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c056d:
btst #2,%d0
beq.s ___a056e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c056e
___a056e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c056e:
btst #1,%d0
beq.s ___a056f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a056f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale142:
btst #21,%d0
beq.s ___a0570
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0570
___a0570:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0570:
btst #20,%d0
beq.s ___a0571
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0571
___a0571:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0571:
btst #19,%d0
beq.s ___a0572
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0572
___a0572:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0572:
btst #18,%d0
beq.s ___a0573
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0573
___a0573:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0573:
btst #17,%d0
beq.s ___a0574
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0574
___a0574:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0574:
btst #16,%d0
beq.s ___a0575
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0575
___a0575:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0575:
tst.w %d0
bpl.s ___a0576
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0576
___a0576:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0576:
btst #14,%d0
beq.s ___a0577
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0577
___a0577:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0577:
btst #13,%d0
beq.s ___a0578
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0578
___a0578:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0578:
btst #12,%d0
beq.s ___a0579
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0579
___a0579:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0579:
btst #11,%d0
beq.s ___a057a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057a
___a057a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057a:
btst #10,%d0
beq.s ___a057b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057b
___a057b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057b:
btst #9,%d0
beq.s ___a057c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057c
___a057c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057c:
btst #8,%d0
beq.s ___a057d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057d
___a057d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057d:
tst.b %d0
bpl.s ___a057e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057e
___a057e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057e:
btst #6,%d0
beq.s ___a057f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c057f
___a057f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c057f:
btst #5,%d0
beq.s ___a0580
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0580
___a0580:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0580:
btst #4,%d0
beq.s ___a0581
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0581
___a0581:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0581:
btst #3,%d0
beq.s ___a0582
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0582
___a0582:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0582:
btst #2,%d0
beq.s ___a0583
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0583
___a0583:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0583:
btst #1,%d0
beq.s ___a0584
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0584
___a0584:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0584:
btst #0,%d0
beq.s ___a0585
or.w %d1,(%a0)+
rts
___a0585:
and.w %d2,(%a0)+
rts
__scale148:
btst #20,%d0
beq.s ___a0586
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0586
___a0586:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0586:
btst #19,%d0
beq.s ___a0587
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0587
___a0587:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0587:
btst #18,%d0
beq.s ___a0588
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0588
___a0588:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0588:
btst #17,%d0
beq.s ___a0589
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0589
___a0589:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0589:
btst #16,%d0
beq.s ___a058a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058a
___a058a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058a:
tst.w %d0
bpl.s ___a058b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058b
___a058b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058b:
btst #14,%d0
beq.s ___a058c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058c
___a058c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058c:
btst #13,%d0
beq.s ___a058d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058d
___a058d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058d:
btst #12,%d0
beq.s ___a058e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058e
___a058e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058e:
btst #11,%d0
beq.s ___a058f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c058f
___a058f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c058f:
btst #10,%d0
beq.s ___a0590
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0590
___a0590:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0590:
btst #9,%d0
beq.s ___a0591
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0591
___a0591:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0591:
btst #8,%d0
beq.s ___a0592
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0592
___a0592:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0592:
tst.b %d0
bpl.s ___a0593
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0593
___a0593:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0593:
btst #6,%d0
beq.s ___a0594
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0594
___a0594:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0594:
btst #5,%d0
beq.s ___a0595
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0595
___a0595:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0595:
btst #4,%d0
beq.s ___a0596
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0596
___a0596:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0596:
btst #3,%d0
beq.s ___a0597
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0597
___a0597:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0597:
btst #2,%d0
beq.s ___a0598
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0598
___a0598:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0598:
btst #1,%d0
beq.s ___a0599
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c0599
___a0599:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c0599:
btst #0,%d0
beq.s ___a059a
or.w %d1,(%a0)+
rts
___a059a:
and.w %d2,(%a0)+
rts
__scale154:
btst #20,%d0
beq.s ___a059b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c059b
___a059b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c059b:
btst #19,%d0
beq.s ___a059c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c059c
___a059c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c059c:
btst #18,%d0
beq.s ___a059d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c059d
___a059d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c059d:
btst #17,%d0
beq.s ___a059e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c059e
___a059e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c059e:
btst #16,%d0
beq.s ___a059f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c059f
___a059f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c059f:
tst.w %d0
bpl.s ___a05a0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a0
___a05a0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a0:
btst #14,%d0
beq.s ___a05a1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a1
___a05a1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a1:
btst #13,%d0
beq.s ___a05a2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a2
___a05a2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a2:
btst #12,%d0
beq.s ___a05a3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a3
___a05a3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a3:
btst #11,%d0
beq.s ___a05a4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a4
___a05a4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a4:
btst #10,%d0
beq.s ___a05a5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a5
___a05a5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a5:
btst #9,%d0
beq.s ___a05a6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a6
___a05a6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a6:
btst #8,%d0
beq.s ___a05a7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a7
___a05a7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a7:
tst.b %d0
bpl.s ___a05a8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a8
___a05a8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a8:
btst #6,%d0
beq.s ___a05a9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05a9
___a05a9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05a9:
btst #5,%d0
beq.s ___a05aa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05aa
___a05aa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05aa:
btst #4,%d0
beq.s ___a05ab
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ab
___a05ab:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ab:
btst #3,%d0
beq.s ___a05ac
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ac
___a05ac:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ac:
btst #2,%d0
beq.s ___a05ad
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ad
___a05ad:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ad:
btst #1,%d0
beq.s ___a05ae
or.w %d1,(%a0)+
rts
___a05ae:
and.w %d2,(%a0)+
rts
__scale160:
btst #19,%d0
beq.s ___a05af
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05af
___a05af:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05af:
btst #18,%d0
beq.s ___a05b0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b0
___a05b0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b0:
btst #17,%d0
beq.s ___a05b1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b1
___a05b1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b1:
btst #16,%d0
beq.s ___a05b2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b2
___a05b2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b2:
tst.w %d0
bpl.s ___a05b3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b3
___a05b3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b3:
btst #14,%d0
beq.s ___a05b4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b4
___a05b4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b4:
btst #13,%d0
beq.s ___a05b5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b5
___a05b5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b5:
btst #12,%d0
beq.s ___a05b6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b6
___a05b6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b6:
btst #11,%d0
beq.s ___a05b7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b7
___a05b7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b7:
btst #10,%d0
beq.s ___a05b8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b8
___a05b8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b8:
btst #9,%d0
beq.s ___a05b9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05b9
___a05b9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05b9:
btst #8,%d0
beq.s ___a05ba
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ba
___a05ba:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ba:
tst.b %d0
bpl.s ___a05bb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05bb
___a05bb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05bb:
btst #6,%d0
beq.s ___a05bc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05bc
___a05bc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05bc:
btst #5,%d0
beq.s ___a05bd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05bd
___a05bd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05bd:
btst #4,%d0
beq.s ___a05be
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05be
___a05be:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05be:
btst #3,%d0
beq.s ___a05bf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05bf
___a05bf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05bf:
btst #2,%d0
beq.s ___a05c0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c0
___a05c0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c0:
btst #1,%d0
beq.s ___a05c1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a05c1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__scale166:
btst #18,%d0
beq.s ___a05c2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c2
___a05c2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c2:
btst #17,%d0
beq.s ___a05c3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c3
___a05c3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c3:
btst #16,%d0
beq.s ___a05c4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c4
___a05c4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c4:
tst.w %d0
bpl.s ___a05c5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c5
___a05c5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c5:
btst #14,%d0
beq.s ___a05c6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c6
___a05c6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c6:
btst #13,%d0
beq.s ___a05c7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c7
___a05c7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c7:
btst #12,%d0
beq.s ___a05c8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c8
___a05c8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c8:
btst #11,%d0
beq.s ___a05c9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05c9
___a05c9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05c9:
btst #10,%d0
beq.s ___a05ca
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ca
___a05ca:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ca:
btst #9,%d0
beq.s ___a05cb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05cb
___a05cb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05cb:
btst #8,%d0
beq.s ___a05cc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05cc
___a05cc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05cc:
tst.b %d0
bpl.s ___a05cd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05cd
___a05cd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05cd:
btst #6,%d0
beq.s ___a05ce
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05ce
___a05ce:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05ce:
btst #5,%d0
beq.s ___a05cf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05cf
___a05cf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05cf:
btst #4,%d0
beq.s ___a05d0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05d0
___a05d0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05d0:
btst #3,%d0
beq.s ___a05d1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05d1
___a05d1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05d1:
btst #2,%d0
beq.s ___a05d2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___c05d2
___a05d2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___c05d2:
btst #1,%d0
beq.s ___a05d3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___a05d3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
ScalerJumpTable:
adda.w #94,%a0
jmp __scale002(%pc)
nop;nop /* lsr = -2961 */
jmp __scale002(%pc)
adda.w #92,%a0
jmp __scale004(%pc)
nop;nop /* lsr = -966 */
jmp __scale004(%pc)
adda.w #90,%a0
jmp __scale006(%pc)
nop;nop /* lsr = -567 */
jmp __scale006(%pc)
adda.w #88,%a0
jmp __scale008(%pc)
nop;nop /* lsr = -396 */
jmp __scale008(%pc)
adda.w #86,%a0
jmp __scale010(%pc)
nop;nop /* lsr = -301 */
jmp __scale010(%pc)
adda.w #84,%a0
jmp __scale012(%pc)
nop;nop /* lsr = -240 */
jmp __scale012(%pc)
adda.w #82,%a0
jmp __scale014(%pc)
nop;nop /* lsr = -198 */
jmp __scale014(%pc)
adda.w #80,%a0
jmp __scale016(%pc)
nop;nop /* lsr = -168 */
jmp __scale016(%pc)
adda.w #78,%a0
jmp __scale018(%pc)
nop;nop /* lsr = -144 */
jmp __scale018(%pc)
adda.w #76,%a0
jmp __scale020(%pc)
nop;nop /* lsr = -126 */
jmp __scale020(%pc)
adda.w #74,%a0
jmp __scale022(%pc)
nop;nop /* lsr = -111 */
jmp __scale022(%pc)
adda.w #72,%a0
jmp __scale024(%pc)
nop;nop /* lsr = -98 */
jmp __scale024(%pc)
adda.w #70,%a0
jmp __scale026(%pc)
nop;nop /* lsr = -88 */
jmp __scale026(%pc)
adda.w #68,%a0
jmp __scale028(%pc)
nop;nop /* lsr = -79 */
jmp __scale028(%pc)
adda.w #66,%a0
jmp __scale030(%pc)
nop;nop /* lsr = -71 */
jmp __scale030(%pc)
adda.w #64,%a0
jmp __scale032(%pc)
nop;nop /* lsr = -65 */
jmp __scale032(%pc)
adda.w #62,%a0
jmp __scale034(%pc)
nop;nop /* lsr = -59 */
jmp __scale034(%pc)
adda.w #60,%a0
jmp __scale036(%pc)
nop;nop /* lsr = -54 */
jmp __scale036(%pc)
adda.w #58,%a0
jmp __scale038(%pc)
nop;nop /* lsr = -49 */
jmp __scale038(%pc)
adda.w #56,%a0
jmp __scale040(%pc)
nop;nop /* lsr = -45 */
jmp __scale040(%pc)
adda.w #54,%a0
jmp __scale042(%pc)
nop;nop /* lsr = -41 */
jmp __scale042(%pc)
adda.w #52,%a0
jmp __scale044(%pc)
nop;nop /* lsr = -38 */
jmp __scale044(%pc)
adda.w #50,%a0
jmp __scale046(%pc)
nop;nop /* lsr = -35 */
jmp __scale046(%pc)
adda.w #48,%a0
jmp __scale048(%pc)
nop;nop /* lsr = -32 */
jmp __scale048(%pc)
adda.w #46,%a0
jmp __scale050(%pc)
nop;nop /* lsr = -29 */
jmp __scale050(%pc)
adda.w #44,%a0
jmp __scale052(%pc)
nop;nop /* lsr = -27 */
jmp __scale052(%pc)
adda.w #42,%a0
jmp __scale054(%pc)
nop;nop /* lsr = -24 */
jmp __scale054(%pc)
adda.w #40,%a0
jmp __scale056(%pc)
nop;nop /* lsr = -22 */
jmp __scale056(%pc)
adda.w #38,%a0
jmp __scale058(%pc)
nop;nop /* lsr = -21 */
jmp __scale058(%pc)
adda.w #36,%a0
jmp __scale060(%pc)
nop;nop /* lsr = -19 */
jmp __scale060(%pc)
adda.w #34,%a0
jmp __scale062(%pc)
nop;nop /* lsr = -17 */
jmp __scale062(%pc)
adda.w #32,%a0
jmp __scale064(%pc)
nop;nop /* lsr = -16 */
jmp __scale064(%pc)
adda.w #30,%a0
jmp __scale066(%pc)
nop;nop /* lsr = -14 */
jmp __scale066(%pc)
adda.w #28,%a0
jmp __scale068(%pc)
nop;nop /* lsr = -13 */
jmp __scale068(%pc)
adda.w #26,%a0
jmp __scale070(%pc)
nop;nop /* lsr = -11 */
jmp __scale070(%pc)
adda.w #24,%a0
jmp __scale072(%pc)
nop;nop /* lsr = -10 */
jmp __scale072(%pc)
adda.w #22,%a0
jmp __scale074(%pc)
nop;nop /* lsr = -9 */
jmp __scale074(%pc)
adda.w #20,%a0
jmp __scale076(%pc)
nop;nop /* lsr = -8 */
jmp __scale076(%pc)
adda.w #18,%a0
jmp __scale078(%pc)
nop;nop /* lsr = -7 */
jmp __scale078(%pc)
adda.w #16,%a0
jmp __scale080(%pc)
nop;nop /* lsr = -6 */
jmp __scale080(%pc)
adda.w #14,%a0
jmp __scale082(%pc)
nop;nop /* lsr = -5 */
jmp __scale082(%pc)
adda.w #12,%a0
jmp __scale084(%pc)
nop;nop /* lsr = -4 */
jmp __scale084(%pc)
adda.w #10,%a0
jmp __scale086(%pc)
nop;nop /* lsr = -3 */
jmp __scale086(%pc)
adda.w #8,%a0
jmp __scale088(%pc)
nop;nop /* lsr = -2 */
jmp __scale088(%pc)
adda.w #6,%a0
jmp __scale090(%pc)
nop;nop /* lsr = -2 */
jmp __scale090(%pc)
adda.w #4,%a0
jmp __scale092(%pc)
nop;nop /* lsr = -1 */
jmp __scale092(%pc)
adda.w #2,%a0
jmp __scale094(%pc)
nop;nop /* lsr = 0 */
jmp __scale094(%pc)
adda.w #0,%a0
jmp __scale096(%pc)
nop;nop /* lsr = 0 */
jmp __scale096(%pc)
nop;nop
jmp __scale098(%pc)
nop;nop /* lsr = 0 */
jmp __scale098(%pc)
nop;nop
jmp __scale100(%pc)
lsr.l #1,%d0;nop /* lsr = 1 */
jmp __scale100(%pc)
nop;nop
jmp __scale102(%pc)
lsr.l #1,%d0;nop /* lsr = 1 */
jmp __scale102(%pc)
nop;nop
jmp __scale104(%pc)
lsr.l #2,%d0;nop /* lsr = 2 */
jmp __scale104(%pc)
nop;nop
jmp __scale106(%pc)
lsr.l #3,%d0;nop /* lsr = 3 */
jmp __scale106(%pc)
nop;nop
jmp __scale108(%pc)
lsr.l #3,%d0;nop /* lsr = 3 */
jmp __scale108(%pc)
nop;nop
jmp __scale110(%pc)
lsr.l #4,%d0;nop /* lsr = 4 */
jmp __scale110(%pc)
nop;nop
jmp __scale110(%pc)
lsr.l #4,%d0;nop /* lsr = 4 */
jmp __scale110(%pc)
nop;nop
jmp __scale114(%pc)
lsr.l #5,%d0;nop /* lsr = 5 */
jmp __scale114(%pc)
nop;nop
jmp __scale114(%pc)
lsr.l #5,%d0;nop /* lsr = 5 */
jmp __scale114(%pc)
nop;nop
jmp __scale118(%pc)
lsr.l #5,%d0;nop /* lsr = 5 */
jmp __scale118(%pc)
nop;nop
jmp __scale118(%pc)
lsr.l #5,%d0;nop /* lsr = 5 */
jmp __scale118(%pc)
nop;nop
jmp __scale122(%pc)
lsr.l #6,%d0;nop /* lsr = 6 */
jmp __scale122(%pc)
nop;nop
jmp __scale122(%pc)
lsr.l #6,%d0;nop /* lsr = 6 */
jmp __scale122(%pc)
nop;nop
jmp __scale126(%pc)
lsr.l #7,%d0;nop /* lsr = 7 */
jmp __scale126(%pc)
nop;nop
jmp __scale126(%pc)
lsr.l #7,%d0;nop /* lsr = 7 */
jmp __scale126(%pc)
nop;nop
jmp __scale130(%pc)
lsr.l #8,%d0;nop /* lsr = 8 */
jmp __scale130(%pc)
nop;nop
jmp __scale130(%pc)
lsr.l #8,%d0;nop /* lsr = 8 */
jmp __scale130(%pc)
nop;nop
jmp __scale130(%pc)
lsr.l #8,%d0;nop /* lsr = 8 */
jmp __scale130(%pc)
nop;nop
jmp __scale136(%pc)
swap %d0;rol.l #7,%d0 /* lsr = 9 */
jmp __scale136(%pc)
nop;nop
jmp __scale136(%pc)
swap %d0;rol.l #7,%d0 /* lsr = 9 */
jmp __scale136(%pc)
nop;nop
jmp __scale136(%pc)
swap %d0;rol.l #7,%d0 /* lsr = 9 */
jmp __scale136(%pc)
nop;nop
jmp __scale142(%pc)
swap %d0;rol.l #6,%d0 /* lsr = 10 */
jmp __scale142(%pc)
nop;nop
jmp __scale142(%pc)
swap %d0;rol.l #6,%d0 /* lsr = 10 */
jmp __scale142(%pc)
nop;nop
jmp __scale142(%pc)
swap %d0;rol.l #6,%d0 /* lsr = 10 */
jmp __scale142(%pc)
nop;nop
jmp __scale148(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale148(%pc)
nop;nop
jmp __scale148(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale148(%pc)
nop;nop
jmp __scale148(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale148(%pc)
nop;nop
jmp __scale154(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale154(%pc)
nop;nop
jmp __scale154(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale154(%pc)
nop;nop
jmp __scale154(%pc)
swap %d0;rol.l #5,%d0 /* lsr = 11 */
jmp __scale154(%pc)
nop;nop
jmp __scale160(%pc)
swap %d0;rol.l #4,%d0 /* lsr = 12 */
jmp __scale160(%pc)
nop;nop
jmp __scale160(%pc)
swap %d0;rol.l #4,%d0 /* lsr = 12 */
jmp __scale160(%pc)
nop;nop
jmp __scale160(%pc)
swap %d0;rol.l #4,%d0 /* lsr = 12 */
jmp __scale160(%pc)
nop;nop
jmp __scale166(%pc)
swap %d0;rol.l #3,%d0 /* lsr = 13 */
jmp __scale166(%pc)
nop;nop
jmp __scale166(%pc)
swap %d0;rol.l #3,%d0 /* lsr = 13 */
jmp __scale166(%pc)
nop;nop
jmp __scale166(%pc)
swap %d0;rol.l #3,%d0 /* lsr = 13 */
jmp __scale166(%pc)
");
