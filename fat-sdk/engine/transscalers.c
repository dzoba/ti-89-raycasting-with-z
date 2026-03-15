//=============================================================================
// this file was automatically generated with:
//
// GenTransScalers v1.04 - Part of FAT-Engine
// (c) thomas.nussbaumer@gmx.net
//=============================================================================

#define TRANS_CLIP_HEIGHT 118 // max. height usable without crashing

asm(".data
__tr_scale002:
tst.l %d3
bmi.s ___drtr0000
rts
___drtr0000:
tst.l %d0
bpl.s ___atr0000
or.w %d1,(%a0)+
rts
___atr0000:
and.w %d2,(%a0)+
rts
__tr_scale004:
tst.l %d3
bmi.s ___drtr0001
adda.w #2,%a0
bra.s  ___ctr0001
___drtr0001:
tst.l %d0
bpl.s ___atr0001
or.w %d1,(%a0)+
bra.s ___ctr0001
___atr0001:
and.w %d2,(%a0)+
___ctr0001:
btst #10,%d3
bne.s ___drtr0002
rts
___drtr0002:
btst #10,%d0
beq.s ___atr0002
or.w %d1,(%a0)+
rts
___atr0002:
and.w %d2,(%a0)+
rts
__tr_scale006:
tst.l %d3
bmi.s ___drtr0003
adda.w #2,%a0
bra.s  ___ctr0003
___drtr0003:
tst.l %d0
bpl.s ___atr0003
or.w %d1,(%a0)+
bra.s ___ctr0003
___atr0003:
and.w %d2,(%a0)+
___ctr0003:
btst #19,%d3
bne.s ___drtr0004
adda.w #2,%a0
bra.s  ___ctr0004
___drtr0004:
btst #19,%d0
beq.s ___atr0004
or.w %d1,(%a0)+
bra.s ___ctr0004
___atr0004:
and.w %d2,(%a0)+
___ctr0004:
btst #6,%d3
bne.s ___drtr0005
rts
___drtr0005:
btst #6,%d0
beq.s ___atr0005
or.w %d1,(%a0)+
rts
___atr0005:
and.w %d2,(%a0)+
rts
__tr_scale008:
tst.l %d3
bmi.s ___drtr0006
adda.w #2,%a0
bra.s  ___ctr0006
___drtr0006:
tst.l %d0
bpl.s ___atr0006
or.w %d1,(%a0)+
bra.s ___ctr0006
___atr0006:
and.w %d2,(%a0)+
___ctr0006:
btst #22,%d3
bne.s ___drtr0007
adda.w #2,%a0
bra.s  ___ctr0007
___drtr0007:
btst #22,%d0
beq.s ___atr0007
or.w %d1,(%a0)+
bra.s ___ctr0007
___atr0007:
and.w %d2,(%a0)+
___ctr0007:
btst #13,%d3
bne.s ___drtr0008
adda.w #2,%a0
bra.s  ___ctr0008
___drtr0008:
btst #13,%d0
beq.s ___atr0008
or.w %d1,(%a0)+
bra.s ___ctr0008
___atr0008:
and.w %d2,(%a0)+
___ctr0008:
btst #4,%d3
bne.s ___drtr0009
rts
___drtr0009:
btst #4,%d0
beq.s ___atr0009
or.w %d1,(%a0)+
rts
___atr0009:
and.w %d2,(%a0)+
rts
__tr_scale010:
tst.l %d3
bmi.s ___drtr000a
adda.w #2,%a0
bra.s  ___ctr000a
___drtr000a:
tst.l %d0
bpl.s ___atr000a
or.w %d1,(%a0)+
bra.s ___ctr000a
___atr000a:
and.w %d2,(%a0)+
___ctr000a:
btst #24,%d3
bne.s ___drtr000b
adda.w #2,%a0
bra.s  ___ctr000b
___drtr000b:
btst #24,%d0
beq.s ___atr000b
or.w %d1,(%a0)+
bra.s ___ctr000b
___atr000b:
and.w %d2,(%a0)+
___ctr000b:
btst #17,%d3
bne.s ___drtr000c
adda.w #2,%a0
bra.s  ___ctr000c
___drtr000c:
btst #17,%d0
beq.s ___atr000c
or.w %d1,(%a0)+
bra.s ___ctr000c
___atr000c:
and.w %d2,(%a0)+
___ctr000c:
btst #10,%d3
bne.s ___drtr000d
adda.w #2,%a0
bra.s  ___ctr000d
___drtr000d:
btst #10,%d0
beq.s ___atr000d
or.w %d1,(%a0)+
bra.s ___ctr000d
___atr000d:
and.w %d2,(%a0)+
___ctr000d:
btst #3,%d3
bne.s ___drtr000e
rts
___drtr000e:
btst #3,%d0
beq.s ___atr000e
or.w %d1,(%a0)+
rts
___atr000e:
and.w %d2,(%a0)+
rts
__tr_scale012:
tst.l %d3
bmi.s ___drtr000f
adda.w #2,%a0
bra.s  ___ctr000f
___drtr000f:
tst.l %d0
bpl.s ___atr000f
or.w %d1,(%a0)+
bra.s ___ctr000f
___atr000f:
and.w %d2,(%a0)+
___ctr000f:
btst #26,%d3
bne.s ___drtr0010
adda.w #2,%a0
bra.s  ___ctr0010
___drtr0010:
btst #26,%d0
beq.s ___atr0010
or.w %d1,(%a0)+
bra.s ___ctr0010
___atr0010:
and.w %d2,(%a0)+
___ctr0010:
btst #20,%d3
bne.s ___drtr0011
adda.w #2,%a0
bra.s  ___ctr0011
___drtr0011:
btst #20,%d0
beq.s ___atr0011
or.w %d1,(%a0)+
bra.s ___ctr0011
___atr0011:
and.w %d2,(%a0)+
___ctr0011:
btst #14,%d3
bne.s ___drtr0012
adda.w #2,%a0
bra.s  ___ctr0012
___drtr0012:
btst #14,%d0
beq.s ___atr0012
or.w %d1,(%a0)+
bra.s ___ctr0012
___atr0012:
and.w %d2,(%a0)+
___ctr0012:
btst #9,%d3
bne.s ___drtr0013
adda.w #2,%a0
bra.s  ___ctr0013
___drtr0013:
btst #9,%d0
beq.s ___atr0013
or.w %d1,(%a0)+
bra.s ___ctr0013
___atr0013:
and.w %d2,(%a0)+
___ctr0013:
btst #3,%d3
bne.s ___drtr0014
rts
___drtr0014:
btst #3,%d0
beq.s ___atr0014
or.w %d1,(%a0)+
rts
___atr0014:
and.w %d2,(%a0)+
rts
__tr_scale014:
tst.l %d3
bmi.s ___drtr0015
adda.w #2,%a0
bra.s  ___ctr0015
___drtr0015:
tst.l %d0
bpl.s ___atr0015
or.w %d1,(%a0)+
bra.s ___ctr0015
___atr0015:
and.w %d2,(%a0)+
___ctr0015:
btst #27,%d3
bne.s ___drtr0016
adda.w #2,%a0
bra.s  ___ctr0016
___drtr0016:
btst #27,%d0
beq.s ___atr0016
or.w %d1,(%a0)+
bra.s ___ctr0016
___atr0016:
and.w %d2,(%a0)+
___ctr0016:
btst #22,%d3
bne.s ___drtr0017
adda.w #2,%a0
bra.s  ___ctr0017
___drtr0017:
btst #22,%d0
beq.s ___atr0017
or.w %d1,(%a0)+
bra.s ___ctr0017
___atr0017:
and.w %d2,(%a0)+
___ctr0017:
btst #17,%d3
bne.s ___drtr0018
adda.w #2,%a0
bra.s  ___ctr0018
___drtr0018:
btst #17,%d0
beq.s ___atr0018
or.w %d1,(%a0)+
bra.s ___ctr0018
___atr0018:
and.w %d2,(%a0)+
___ctr0018:
btst #12,%d3
bne.s ___drtr0019
adda.w #2,%a0
bra.s  ___ctr0019
___drtr0019:
btst #12,%d0
beq.s ___atr0019
or.w %d1,(%a0)+
bra.s ___ctr0019
___atr0019:
and.w %d2,(%a0)+
___ctr0019:
tst.b %d3
bmi.s ___drtr001a
adda.w #2,%a0
bra.s  ___ctr001a
___drtr001a:
tst.b %d0
bpl.s ___atr001a
or.w %d1,(%a0)+
bra.s ___ctr001a
___atr001a:
and.w %d2,(%a0)+
___ctr001a:
btst #2,%d3
bne.s ___drtr001b
rts
___drtr001b:
btst #2,%d0
beq.s ___atr001b
or.w %d1,(%a0)+
rts
___atr001b:
and.w %d2,(%a0)+
rts
__tr_scale016:
tst.l %d3
bmi.s ___drtr001c
adda.w #2,%a0
bra.s  ___ctr001c
___drtr001c:
tst.l %d0
bpl.s ___atr001c
or.w %d1,(%a0)+
bra.s ___ctr001c
___atr001c:
and.w %d2,(%a0)+
___ctr001c:
btst #27,%d3
bne.s ___drtr001d
adda.w #2,%a0
bra.s  ___ctr001d
___drtr001d:
btst #27,%d0
beq.s ___atr001d
or.w %d1,(%a0)+
bra.s ___ctr001d
___atr001d:
and.w %d2,(%a0)+
___ctr001d:
btst #23,%d3
bne.s ___drtr001e
adda.w #2,%a0
bra.s  ___ctr001e
___drtr001e:
btst #23,%d0
beq.s ___atr001e
or.w %d1,(%a0)+
bra.s ___ctr001e
___atr001e:
and.w %d2,(%a0)+
___ctr001e:
btst #19,%d3
bne.s ___drtr001f
adda.w #2,%a0
bra.s  ___ctr001f
___drtr001f:
btst #19,%d0
beq.s ___atr001f
or.w %d1,(%a0)+
bra.s ___ctr001f
___atr001f:
and.w %d2,(%a0)+
___ctr001f:
tst.w %d3
bmi.s ___drtr0020
adda.w #2,%a0
bra.s  ___ctr0020
___drtr0020:
tst.w %d0
bpl.s ___atr0020
or.w %d1,(%a0)+
bra.s ___ctr0020
___atr0020:
and.w %d2,(%a0)+
___ctr0020:
btst #10,%d3
bne.s ___drtr0021
adda.w #2,%a0
bra.s  ___ctr0021
___drtr0021:
btst #10,%d0
beq.s ___atr0021
or.w %d1,(%a0)+
bra.s ___ctr0021
___atr0021:
and.w %d2,(%a0)+
___ctr0021:
btst #6,%d3
bne.s ___drtr0022
adda.w #2,%a0
bra.s  ___ctr0022
___drtr0022:
btst #6,%d0
beq.s ___atr0022
or.w %d1,(%a0)+
bra.s ___ctr0022
___atr0022:
and.w %d2,(%a0)+
___ctr0022:
btst #2,%d3
bne.s ___drtr0023
rts
___drtr0023:
btst #2,%d0
beq.s ___atr0023
or.w %d1,(%a0)+
rts
___atr0023:
and.w %d2,(%a0)+
rts
__tr_scale018:
tst.l %d3
bmi.s ___drtr0024
adda.w #2,%a0
bra.s  ___ctr0024
___drtr0024:
tst.l %d0
bpl.s ___atr0024
or.w %d1,(%a0)+
bra.s ___ctr0024
___atr0024:
and.w %d2,(%a0)+
___ctr0024:
btst #28,%d3
bne.s ___drtr0025
adda.w #2,%a0
bra.s  ___ctr0025
___drtr0025:
btst #28,%d0
beq.s ___atr0025
or.w %d1,(%a0)+
bra.s ___ctr0025
___atr0025:
and.w %d2,(%a0)+
___ctr0025:
btst #24,%d3
bne.s ___drtr0026
adda.w #2,%a0
bra.s  ___ctr0026
___drtr0026:
btst #24,%d0
beq.s ___atr0026
or.w %d1,(%a0)+
bra.s ___ctr0026
___atr0026:
and.w %d2,(%a0)+
___ctr0026:
btst #20,%d3
bne.s ___drtr0027
adda.w #2,%a0
bra.s  ___ctr0027
___drtr0027:
btst #20,%d0
beq.s ___atr0027
or.w %d1,(%a0)+
bra.s ___ctr0027
___atr0027:
and.w %d2,(%a0)+
___ctr0027:
btst #17,%d3
bne.s ___drtr0028
adda.w #2,%a0
bra.s  ___ctr0028
___drtr0028:
btst #17,%d0
beq.s ___atr0028
or.w %d1,(%a0)+
bra.s ___ctr0028
___atr0028:
and.w %d2,(%a0)+
___ctr0028:
btst #13,%d3
bne.s ___drtr0029
adda.w #2,%a0
bra.s  ___ctr0029
___drtr0029:
btst #13,%d0
beq.s ___atr0029
or.w %d1,(%a0)+
bra.s ___ctr0029
___atr0029:
and.w %d2,(%a0)+
___ctr0029:
btst #9,%d3
bne.s ___drtr002a
adda.w #2,%a0
bra.s  ___ctr002a
___drtr002a:
btst #9,%d0
beq.s ___atr002a
or.w %d1,(%a0)+
bra.s ___ctr002a
___atr002a:
and.w %d2,(%a0)+
___ctr002a:
btst #6,%d3
bne.s ___drtr002b
adda.w #2,%a0
bra.s  ___ctr002b
___drtr002b:
btst #6,%d0
beq.s ___atr002b
or.w %d1,(%a0)+
bra.s ___ctr002b
___atr002b:
and.w %d2,(%a0)+
___ctr002b:
btst #2,%d3
bne.s ___drtr002c
rts
___drtr002c:
btst #2,%d0
beq.s ___atr002c
or.w %d1,(%a0)+
rts
___atr002c:
and.w %d2,(%a0)+
rts
__tr_scale020:
tst.l %d3
bmi.s ___drtr002d
adda.w #2,%a0
bra.s  ___ctr002d
___drtr002d:
tst.l %d0
bpl.s ___atr002d
or.w %d1,(%a0)+
bra.s ___ctr002d
___atr002d:
and.w %d2,(%a0)+
___ctr002d:
btst #28,%d3
bne.s ___drtr002e
adda.w #2,%a0
bra.s  ___ctr002e
___drtr002e:
btst #28,%d0
beq.s ___atr002e
or.w %d1,(%a0)+
bra.s ___ctr002e
___atr002e:
and.w %d2,(%a0)+
___ctr002e:
btst #25,%d3
bne.s ___drtr002f
adda.w #2,%a0
bra.s  ___ctr002f
___drtr002f:
btst #25,%d0
beq.s ___atr002f
or.w %d1,(%a0)+
bra.s ___ctr002f
___atr002f:
and.w %d2,(%a0)+
___ctr002f:
btst #22,%d3
bne.s ___drtr0030
adda.w #2,%a0
bra.s  ___ctr0030
___drtr0030:
btst #22,%d0
beq.s ___atr0030
or.w %d1,(%a0)+
bra.s ___ctr0030
___atr0030:
and.w %d2,(%a0)+
___ctr0030:
btst #18,%d3
bne.s ___drtr0031
adda.w #2,%a0
bra.s  ___ctr0031
___drtr0031:
btst #18,%d0
beq.s ___atr0031
or.w %d1,(%a0)+
bra.s ___ctr0031
___atr0031:
and.w %d2,(%a0)+
___ctr0031:
tst.w %d3
bmi.s ___drtr0032
adda.w #2,%a0
bra.s  ___ctr0032
___drtr0032:
tst.w %d0
bpl.s ___atr0032
or.w %d1,(%a0)+
bra.s ___ctr0032
___atr0032:
and.w %d2,(%a0)+
___ctr0032:
btst #12,%d3
bne.s ___drtr0033
adda.w #2,%a0
bra.s  ___ctr0033
___drtr0033:
btst #12,%d0
beq.s ___atr0033
or.w %d1,(%a0)+
bra.s ___ctr0033
___atr0033:
and.w %d2,(%a0)+
___ctr0033:
btst #8,%d3
bne.s ___drtr0034
adda.w #2,%a0
bra.s  ___ctr0034
___drtr0034:
btst #8,%d0
beq.s ___atr0034
or.w %d1,(%a0)+
bra.s ___ctr0034
___atr0034:
and.w %d2,(%a0)+
___ctr0034:
btst #5,%d3
bne.s ___drtr0035
adda.w #2,%a0
bra.s  ___ctr0035
___drtr0035:
btst #5,%d0
beq.s ___atr0035
or.w %d1,(%a0)+
bra.s ___ctr0035
___atr0035:
and.w %d2,(%a0)+
___ctr0035:
btst #2,%d3
bne.s ___drtr0036
rts
___drtr0036:
btst #2,%d0
beq.s ___atr0036
or.w %d1,(%a0)+
rts
___atr0036:
and.w %d2,(%a0)+
rts
__tr_scale022:
tst.l %d3
bmi.s ___drtr0037
adda.w #2,%a0
bra.s  ___ctr0037
___drtr0037:
tst.l %d0
bpl.s ___atr0037
or.w %d1,(%a0)+
bra.s ___ctr0037
___atr0037:
and.w %d2,(%a0)+
___ctr0037:
btst #28,%d3
bne.s ___drtr0038
adda.w #2,%a0
bra.s  ___ctr0038
___drtr0038:
btst #28,%d0
beq.s ___atr0038
or.w %d1,(%a0)+
bra.s ___ctr0038
___atr0038:
and.w %d2,(%a0)+
___ctr0038:
btst #25,%d3
bne.s ___drtr0039
adda.w #2,%a0
bra.s  ___ctr0039
___drtr0039:
btst #25,%d0
beq.s ___atr0039
or.w %d1,(%a0)+
bra.s ___ctr0039
___atr0039:
and.w %d2,(%a0)+
___ctr0039:
btst #22,%d3
bne.s ___drtr003a
adda.w #2,%a0
bra.s  ___ctr003a
___drtr003a:
btst #22,%d0
beq.s ___atr003a
or.w %d1,(%a0)+
bra.s ___ctr003a
___atr003a:
and.w %d2,(%a0)+
___ctr003a:
btst #19,%d3
bne.s ___drtr003b
adda.w #2,%a0
bra.s  ___ctr003b
___drtr003b:
btst #19,%d0
beq.s ___atr003b
or.w %d1,(%a0)+
bra.s ___ctr003b
___atr003b:
and.w %d2,(%a0)+
___ctr003b:
btst #16,%d3
bne.s ___drtr003c
adda.w #2,%a0
bra.s  ___ctr003c
___drtr003c:
btst #16,%d0
beq.s ___atr003c
or.w %d1,(%a0)+
bra.s ___ctr003c
___atr003c:
and.w %d2,(%a0)+
___ctr003c:
btst #13,%d3
bne.s ___drtr003d
adda.w #2,%a0
bra.s  ___ctr003d
___drtr003d:
btst #13,%d0
beq.s ___atr003d
or.w %d1,(%a0)+
bra.s ___ctr003d
___atr003d:
and.w %d2,(%a0)+
___ctr003d:
btst #10,%d3
bne.s ___drtr003e
adda.w #2,%a0
bra.s  ___ctr003e
___drtr003e:
btst #10,%d0
beq.s ___atr003e
or.w %d1,(%a0)+
bra.s ___ctr003e
___atr003e:
and.w %d2,(%a0)+
___ctr003e:
tst.b %d3
bmi.s ___drtr003f
adda.w #2,%a0
bra.s  ___ctr003f
___drtr003f:
tst.b %d0
bpl.s ___atr003f
or.w %d1,(%a0)+
bra.s ___ctr003f
___atr003f:
and.w %d2,(%a0)+
___ctr003f:
btst #4,%d3
bne.s ___drtr0040
adda.w #2,%a0
bra.s  ___ctr0040
___drtr0040:
btst #4,%d0
beq.s ___atr0040
or.w %d1,(%a0)+
bra.s ___ctr0040
___atr0040:
and.w %d2,(%a0)+
___ctr0040:
btst #1,%d3
bne.s ___drtr0041
rts
___drtr0041:
btst #1,%d0
beq.s ___atr0041
or.w %d1,(%a0)+
rts
___atr0041:
and.w %d2,(%a0)+
rts
__tr_scale024:
tst.l %d3
bmi.s ___drtr0042
adda.w #2,%a0
bra.s  ___ctr0042
___drtr0042:
tst.l %d0
bpl.s ___atr0042
or.w %d1,(%a0)+
bra.s ___ctr0042
___atr0042:
and.w %d2,(%a0)+
___ctr0042:
btst #29,%d3
bne.s ___drtr0043
adda.w #2,%a0
bra.s  ___ctr0043
___drtr0043:
btst #29,%d0
beq.s ___atr0043
or.w %d1,(%a0)+
bra.s ___ctr0043
___atr0043:
and.w %d2,(%a0)+
___ctr0043:
btst #26,%d3
bne.s ___drtr0044
adda.w #2,%a0
bra.s  ___ctr0044
___drtr0044:
btst #26,%d0
beq.s ___atr0044
or.w %d1,(%a0)+
bra.s ___ctr0044
___atr0044:
and.w %d2,(%a0)+
___ctr0044:
btst #23,%d3
bne.s ___drtr0045
adda.w #2,%a0
bra.s  ___ctr0045
___drtr0045:
btst #23,%d0
beq.s ___atr0045
or.w %d1,(%a0)+
bra.s ___ctr0045
___atr0045:
and.w %d2,(%a0)+
___ctr0045:
btst #21,%d3
bne.s ___drtr0046
adda.w #2,%a0
bra.s  ___ctr0046
___drtr0046:
btst #21,%d0
beq.s ___atr0046
or.w %d1,(%a0)+
bra.s ___ctr0046
___atr0046:
and.w %d2,(%a0)+
___ctr0046:
btst #18,%d3
bne.s ___drtr0047
adda.w #2,%a0
bra.s  ___ctr0047
___drtr0047:
btst #18,%d0
beq.s ___atr0047
or.w %d1,(%a0)+
bra.s ___ctr0047
___atr0047:
and.w %d2,(%a0)+
___ctr0047:
tst.w %d3
bmi.s ___drtr0048
adda.w #2,%a0
bra.s  ___ctr0048
___drtr0048:
tst.w %d0
bpl.s ___atr0048
or.w %d1,(%a0)+
bra.s ___ctr0048
___atr0048:
and.w %d2,(%a0)+
___ctr0048:
btst #12,%d3
bne.s ___drtr0049
adda.w #2,%a0
bra.s  ___ctr0049
___drtr0049:
btst #12,%d0
beq.s ___atr0049
or.w %d1,(%a0)+
bra.s ___ctr0049
___atr0049:
and.w %d2,(%a0)+
___ctr0049:
btst #10,%d3
bne.s ___drtr004a
adda.w #2,%a0
bra.s  ___ctr004a
___drtr004a:
btst #10,%d0
beq.s ___atr004a
or.w %d1,(%a0)+
bra.s ___ctr004a
___atr004a:
and.w %d2,(%a0)+
___ctr004a:
tst.b %d3
bmi.s ___drtr004b
adda.w #2,%a0
bra.s  ___ctr004b
___drtr004b:
tst.b %d0
bpl.s ___atr004b
or.w %d1,(%a0)+
bra.s ___ctr004b
___atr004b:
and.w %d2,(%a0)+
___ctr004b:
btst #4,%d3
bne.s ___drtr004c
adda.w #2,%a0
bra.s  ___ctr004c
___drtr004c:
btst #4,%d0
beq.s ___atr004c
or.w %d1,(%a0)+
bra.s ___ctr004c
___atr004c:
and.w %d2,(%a0)+
___ctr004c:
btst #1,%d3
bne.s ___drtr004d
rts
___drtr004d:
btst #1,%d0
beq.s ___atr004d
or.w %d1,(%a0)+
rts
___atr004d:
and.w %d2,(%a0)+
rts
__tr_scale026:
tst.l %d3
bmi.s ___drtr004e
adda.w #2,%a0
bra.s  ___ctr004e
___drtr004e:
tst.l %d0
bpl.s ___atr004e
or.w %d1,(%a0)+
bra.s ___ctr004e
___atr004e:
and.w %d2,(%a0)+
___ctr004e:
btst #29,%d3
bne.s ___drtr004f
adda.w #2,%a0
bra.s  ___ctr004f
___drtr004f:
btst #29,%d0
beq.s ___atr004f
or.w %d1,(%a0)+
bra.s ___ctr004f
___atr004f:
and.w %d2,(%a0)+
___ctr004f:
btst #26,%d3
bne.s ___drtr0050
adda.w #2,%a0
bra.s  ___ctr0050
___drtr0050:
btst #26,%d0
beq.s ___atr0050
or.w %d1,(%a0)+
bra.s ___ctr0050
___atr0050:
and.w %d2,(%a0)+
___ctr0050:
btst #24,%d3
bne.s ___drtr0051
adda.w #2,%a0
bra.s  ___ctr0051
___drtr0051:
btst #24,%d0
beq.s ___atr0051
or.w %d1,(%a0)+
bra.s ___ctr0051
___atr0051:
and.w %d2,(%a0)+
___ctr0051:
btst #21,%d3
bne.s ___drtr0052
adda.w #2,%a0
bra.s  ___ctr0052
___drtr0052:
btst #21,%d0
beq.s ___atr0052
or.w %d1,(%a0)+
bra.s ___ctr0052
___atr0052:
and.w %d2,(%a0)+
___ctr0052:
btst #19,%d3
bne.s ___drtr0053
adda.w #2,%a0
bra.s  ___ctr0053
___drtr0053:
btst #19,%d0
beq.s ___atr0053
or.w %d1,(%a0)+
bra.s ___ctr0053
___atr0053:
and.w %d2,(%a0)+
___ctr0053:
btst #16,%d3
bne.s ___drtr0054
adda.w #2,%a0
bra.s  ___ctr0054
___drtr0054:
btst #16,%d0
beq.s ___atr0054
or.w %d1,(%a0)+
bra.s ___ctr0054
___atr0054:
and.w %d2,(%a0)+
___ctr0054:
btst #14,%d3
bne.s ___drtr0055
adda.w #2,%a0
bra.s  ___ctr0055
___drtr0055:
btst #14,%d0
beq.s ___atr0055
or.w %d1,(%a0)+
bra.s ___ctr0055
___atr0055:
and.w %d2,(%a0)+
___ctr0055:
btst #11,%d3
bne.s ___drtr0056
adda.w #2,%a0
bra.s  ___ctr0056
___drtr0056:
btst #11,%d0
beq.s ___atr0056
or.w %d1,(%a0)+
bra.s ___ctr0056
___atr0056:
and.w %d2,(%a0)+
___ctr0056:
btst #9,%d3
bne.s ___drtr0057
adda.w #2,%a0
bra.s  ___ctr0057
___drtr0057:
btst #9,%d0
beq.s ___atr0057
or.w %d1,(%a0)+
bra.s ___ctr0057
___atr0057:
and.w %d2,(%a0)+
___ctr0057:
btst #6,%d3
bne.s ___drtr0058
adda.w #2,%a0
bra.s  ___ctr0058
___drtr0058:
btst #6,%d0
beq.s ___atr0058
or.w %d1,(%a0)+
bra.s ___ctr0058
___atr0058:
and.w %d2,(%a0)+
___ctr0058:
btst #4,%d3
bne.s ___drtr0059
adda.w #2,%a0
bra.s  ___ctr0059
___drtr0059:
btst #4,%d0
beq.s ___atr0059
or.w %d1,(%a0)+
bra.s ___ctr0059
___atr0059:
and.w %d2,(%a0)+
___ctr0059:
btst #1,%d3
bne.s ___drtr005a
rts
___drtr005a:
btst #1,%d0
beq.s ___atr005a
or.w %d1,(%a0)+
rts
___atr005a:
and.w %d2,(%a0)+
rts
__tr_scale028:
tst.l %d3
bmi.s ___drtr005b
adda.w #2,%a0
bra.s  ___ctr005b
___drtr005b:
tst.l %d0
bpl.s ___atr005b
or.w %d1,(%a0)+
bra.s ___ctr005b
___atr005b:
and.w %d2,(%a0)+
___ctr005b:
btst #29,%d3
bne.s ___drtr005c
adda.w #2,%a0
bra.s  ___ctr005c
___drtr005c:
btst #29,%d0
beq.s ___atr005c
or.w %d1,(%a0)+
bra.s ___ctr005c
___atr005c:
and.w %d2,(%a0)+
___ctr005c:
btst #27,%d3
bne.s ___drtr005d
adda.w #2,%a0
bra.s  ___ctr005d
___drtr005d:
btst #27,%d0
beq.s ___atr005d
or.w %d1,(%a0)+
bra.s ___ctr005d
___atr005d:
and.w %d2,(%a0)+
___ctr005d:
btst #24,%d3
bne.s ___drtr005e
adda.w #2,%a0
bra.s  ___ctr005e
___drtr005e:
btst #24,%d0
beq.s ___atr005e
or.w %d1,(%a0)+
bra.s ___ctr005e
___atr005e:
and.w %d2,(%a0)+
___ctr005e:
btst #22,%d3
bne.s ___drtr005f
adda.w #2,%a0
bra.s  ___ctr005f
___drtr005f:
btst #22,%d0
beq.s ___atr005f
or.w %d1,(%a0)+
bra.s ___ctr005f
___atr005f:
and.w %d2,(%a0)+
___ctr005f:
btst #20,%d3
bne.s ___drtr0060
adda.w #2,%a0
bra.s  ___ctr0060
___drtr0060:
btst #20,%d0
beq.s ___atr0060
or.w %d1,(%a0)+
bra.s ___ctr0060
___atr0060:
and.w %d2,(%a0)+
___ctr0060:
btst #17,%d3
bne.s ___drtr0061
adda.w #2,%a0
bra.s  ___ctr0061
___drtr0061:
btst #17,%d0
beq.s ___atr0061
or.w %d1,(%a0)+
bra.s ___ctr0061
___atr0061:
and.w %d2,(%a0)+
___ctr0061:
tst.w %d3
bmi.s ___drtr0062
adda.w #2,%a0
bra.s  ___ctr0062
___drtr0062:
tst.w %d0
bpl.s ___atr0062
or.w %d1,(%a0)+
bra.s ___ctr0062
___atr0062:
and.w %d2,(%a0)+
___ctr0062:
btst #13,%d3
bne.s ___drtr0063
adda.w #2,%a0
bra.s  ___ctr0063
___drtr0063:
btst #13,%d0
beq.s ___atr0063
or.w %d1,(%a0)+
bra.s ___ctr0063
___atr0063:
and.w %d2,(%a0)+
___ctr0063:
btst #10,%d3
bne.s ___drtr0064
adda.w #2,%a0
bra.s  ___ctr0064
___drtr0064:
btst #10,%d0
beq.s ___atr0064
or.w %d1,(%a0)+
bra.s ___ctr0064
___atr0064:
and.w %d2,(%a0)+
___ctr0064:
btst #8,%d3
bne.s ___drtr0065
adda.w #2,%a0
bra.s  ___ctr0065
___drtr0065:
btst #8,%d0
beq.s ___atr0065
or.w %d1,(%a0)+
bra.s ___ctr0065
___atr0065:
and.w %d2,(%a0)+
___ctr0065:
btst #6,%d3
bne.s ___drtr0066
adda.w #2,%a0
bra.s  ___ctr0066
___drtr0066:
btst #6,%d0
beq.s ___atr0066
or.w %d1,(%a0)+
bra.s ___ctr0066
___atr0066:
and.w %d2,(%a0)+
___ctr0066:
btst #4,%d3
bne.s ___drtr0067
adda.w #2,%a0
bra.s  ___ctr0067
___drtr0067:
btst #4,%d0
beq.s ___atr0067
or.w %d1,(%a0)+
bra.s ___ctr0067
___atr0067:
and.w %d2,(%a0)+
___ctr0067:
btst #1,%d3
bne.s ___drtr0068
rts
___drtr0068:
btst #1,%d0
beq.s ___atr0068
or.w %d1,(%a0)+
rts
___atr0068:
and.w %d2,(%a0)+
rts
__tr_scale030:
tst.l %d3
bmi.s ___drtr0069
adda.w #2,%a0
bra.s  ___ctr0069
___drtr0069:
tst.l %d0
bpl.s ___atr0069
or.w %d1,(%a0)+
bra.s ___ctr0069
___atr0069:
and.w %d2,(%a0)+
___ctr0069:
btst #29,%d3
bne.s ___drtr006a
adda.w #2,%a0
bra.s  ___ctr006a
___drtr006a:
btst #29,%d0
beq.s ___atr006a
or.w %d1,(%a0)+
bra.s ___ctr006a
___atr006a:
and.w %d2,(%a0)+
___ctr006a:
btst #27,%d3
bne.s ___drtr006b
adda.w #2,%a0
bra.s  ___ctr006b
___drtr006b:
btst #27,%d0
beq.s ___atr006b
or.w %d1,(%a0)+
bra.s ___ctr006b
___atr006b:
and.w %d2,(%a0)+
___ctr006b:
btst #25,%d3
bne.s ___drtr006c
adda.w #2,%a0
bra.s  ___ctr006c
___drtr006c:
btst #25,%d0
beq.s ___atr006c
or.w %d1,(%a0)+
bra.s ___ctr006c
___atr006c:
and.w %d2,(%a0)+
___ctr006c:
btst #23,%d3
bne.s ___drtr006d
adda.w #2,%a0
bra.s  ___ctr006d
___drtr006d:
btst #23,%d0
beq.s ___atr006d
or.w %d1,(%a0)+
bra.s ___ctr006d
___atr006d:
and.w %d2,(%a0)+
___ctr006d:
btst #21,%d3
bne.s ___drtr006e
adda.w #2,%a0
bra.s  ___ctr006e
___drtr006e:
btst #21,%d0
beq.s ___atr006e
or.w %d1,(%a0)+
bra.s ___ctr006e
___atr006e:
and.w %d2,(%a0)+
___ctr006e:
btst #18,%d3
bne.s ___drtr006f
adda.w #2,%a0
bra.s  ___ctr006f
___drtr006f:
btst #18,%d0
beq.s ___atr006f
or.w %d1,(%a0)+
bra.s ___ctr006f
___atr006f:
and.w %d2,(%a0)+
___ctr006f:
btst #16,%d3
bne.s ___drtr0070
adda.w #2,%a0
bra.s  ___ctr0070
___drtr0070:
btst #16,%d0
beq.s ___atr0070
or.w %d1,(%a0)+
bra.s ___ctr0070
___atr0070:
and.w %d2,(%a0)+
___ctr0070:
btst #14,%d3
bne.s ___drtr0071
adda.w #2,%a0
bra.s  ___ctr0071
___drtr0071:
btst #14,%d0
beq.s ___atr0071
or.w %d1,(%a0)+
bra.s ___ctr0071
___atr0071:
and.w %d2,(%a0)+
___ctr0071:
btst #12,%d3
bne.s ___drtr0072
adda.w #2,%a0
bra.s  ___ctr0072
___drtr0072:
btst #12,%d0
beq.s ___atr0072
or.w %d1,(%a0)+
bra.s ___ctr0072
___atr0072:
and.w %d2,(%a0)+
___ctr0072:
btst #10,%d3
bne.s ___drtr0073
adda.w #2,%a0
bra.s  ___ctr0073
___drtr0073:
btst #10,%d0
beq.s ___atr0073
or.w %d1,(%a0)+
bra.s ___ctr0073
___atr0073:
and.w %d2,(%a0)+
___ctr0073:
btst #8,%d3
bne.s ___drtr0074
adda.w #2,%a0
bra.s  ___ctr0074
___drtr0074:
btst #8,%d0
beq.s ___atr0074
or.w %d1,(%a0)+
bra.s ___ctr0074
___atr0074:
and.w %d2,(%a0)+
___ctr0074:
btst #5,%d3
bne.s ___drtr0075
adda.w #2,%a0
bra.s  ___ctr0075
___drtr0075:
btst #5,%d0
beq.s ___atr0075
or.w %d1,(%a0)+
bra.s ___ctr0075
___atr0075:
and.w %d2,(%a0)+
___ctr0075:
btst #3,%d3
bne.s ___drtr0076
adda.w #2,%a0
bra.s  ___ctr0076
___drtr0076:
btst #3,%d0
beq.s ___atr0076
or.w %d1,(%a0)+
bra.s ___ctr0076
___atr0076:
and.w %d2,(%a0)+
___ctr0076:
btst #1,%d3
bne.s ___drtr0077
rts
___drtr0077:
btst #1,%d0
beq.s ___atr0077
or.w %d1,(%a0)+
rts
___atr0077:
and.w %d2,(%a0)+
rts
__tr_scale034:
tst.l %d3
bmi.s ___drtr0078
adda.w #2,%a0
bra.s  ___ctr0078
___drtr0078:
tst.l %d0
bpl.s ___atr0078
or.w %d1,(%a0)+
bra.s ___ctr0078
___atr0078:
and.w %d2,(%a0)+
___ctr0078:
btst #30,%d3
bne.s ___drtr0079
adda.w #2,%a0
bra.s  ___ctr0079
___drtr0079:
btst #30,%d0
beq.s ___atr0079
or.w %d1,(%a0)+
bra.s ___ctr0079
___atr0079:
and.w %d2,(%a0)+
___ctr0079:
btst #28,%d3
bne.s ___drtr007a
adda.w #2,%a0
bra.s  ___ctr007a
___drtr007a:
btst #28,%d0
beq.s ___atr007a
or.w %d1,(%a0)+
bra.s ___ctr007a
___atr007a:
and.w %d2,(%a0)+
___ctr007a:
btst #26,%d3
bne.s ___drtr007b
adda.w #2,%a0
bra.s  ___ctr007b
___drtr007b:
btst #26,%d0
beq.s ___atr007b
or.w %d1,(%a0)+
bra.s ___ctr007b
___atr007b:
and.w %d2,(%a0)+
___ctr007b:
btst #24,%d3
bne.s ___drtr007c
adda.w #2,%a0
bra.s  ___ctr007c
___drtr007c:
btst #24,%d0
beq.s ___atr007c
or.w %d1,(%a0)+
bra.s ___ctr007c
___atr007c:
and.w %d2,(%a0)+
___ctr007c:
btst #22,%d3
bne.s ___drtr007d
adda.w #2,%a0
bra.s  ___ctr007d
___drtr007d:
btst #22,%d0
beq.s ___atr007d
or.w %d1,(%a0)+
bra.s ___ctr007d
___atr007d:
and.w %d2,(%a0)+
___ctr007d:
btst #20,%d3
bne.s ___drtr007e
adda.w #2,%a0
bra.s  ___ctr007e
___drtr007e:
btst #20,%d0
beq.s ___atr007e
or.w %d1,(%a0)+
bra.s ___ctr007e
___atr007e:
and.w %d2,(%a0)+
___ctr007e:
btst #18,%d3
bne.s ___drtr007f
adda.w #2,%a0
bra.s  ___ctr007f
___drtr007f:
btst #18,%d0
beq.s ___atr007f
or.w %d1,(%a0)+
bra.s ___ctr007f
___atr007f:
and.w %d2,(%a0)+
___ctr007f:
btst #16,%d3
bne.s ___drtr0080
adda.w #2,%a0
bra.s  ___ctr0080
___drtr0080:
btst #16,%d0
beq.s ___atr0080
or.w %d1,(%a0)+
bra.s ___ctr0080
___atr0080:
and.w %d2,(%a0)+
___ctr0080:
btst #14,%d3
bne.s ___drtr0081
adda.w #2,%a0
bra.s  ___ctr0081
___drtr0081:
btst #14,%d0
beq.s ___atr0081
or.w %d1,(%a0)+
bra.s ___ctr0081
___atr0081:
and.w %d2,(%a0)+
___ctr0081:
btst #12,%d3
bne.s ___drtr0082
adda.w #2,%a0
bra.s  ___ctr0082
___drtr0082:
btst #12,%d0
beq.s ___atr0082
or.w %d1,(%a0)+
bra.s ___ctr0082
___atr0082:
and.w %d2,(%a0)+
___ctr0082:
btst #10,%d3
bne.s ___drtr0083
adda.w #2,%a0
bra.s  ___ctr0083
___drtr0083:
btst #10,%d0
beq.s ___atr0083
or.w %d1,(%a0)+
bra.s ___ctr0083
___atr0083:
and.w %d2,(%a0)+
___ctr0083:
btst #9,%d3
bne.s ___drtr0084
adda.w #2,%a0
bra.s  ___ctr0084
___drtr0084:
btst #9,%d0
beq.s ___atr0084
or.w %d1,(%a0)+
bra.s ___ctr0084
___atr0084:
and.w %d2,(%a0)+
___ctr0084:
tst.b %d3
bmi.s ___drtr0085
adda.w #2,%a0
bra.s  ___ctr0085
___drtr0085:
tst.b %d0
bpl.s ___atr0085
or.w %d1,(%a0)+
bra.s ___ctr0085
___atr0085:
and.w %d2,(%a0)+
___ctr0085:
btst #5,%d3
bne.s ___drtr0086
adda.w #2,%a0
bra.s  ___ctr0086
___drtr0086:
btst #5,%d0
beq.s ___atr0086
or.w %d1,(%a0)+
bra.s ___ctr0086
___atr0086:
and.w %d2,(%a0)+
___ctr0086:
btst #3,%d3
bne.s ___drtr0087
adda.w #2,%a0
bra.s  ___ctr0087
___drtr0087:
btst #3,%d0
beq.s ___atr0087
or.w %d1,(%a0)+
bra.s ___ctr0087
___atr0087:
and.w %d2,(%a0)+
___ctr0087:
btst #1,%d3
bne.s ___drtr0088
rts
___drtr0088:
btst #1,%d0
beq.s ___atr0088
or.w %d1,(%a0)+
rts
___atr0088:
and.w %d2,(%a0)+
rts
__tr_scale038:
tst.l %d3
bmi.s ___drtr0089
adda.w #2,%a0
bra.s  ___ctr0089
___drtr0089:
tst.l %d0
bpl.s ___atr0089
or.w %d1,(%a0)+
bra.s ___ctr0089
___atr0089:
and.w %d2,(%a0)+
___ctr0089:
btst #30,%d3
bne.s ___drtr008a
adda.w #2,%a0
bra.s  ___ctr008a
___drtr008a:
btst #30,%d0
beq.s ___atr008a
or.w %d1,(%a0)+
bra.s ___ctr008a
___atr008a:
and.w %d2,(%a0)+
___ctr008a:
btst #28,%d3
bne.s ___drtr008b
adda.w #2,%a0
bra.s  ___ctr008b
___drtr008b:
btst #28,%d0
beq.s ___atr008b
or.w %d1,(%a0)+
bra.s ___ctr008b
___atr008b:
and.w %d2,(%a0)+
___ctr008b:
btst #26,%d3
bne.s ___drtr008c
adda.w #2,%a0
bra.s  ___ctr008c
___drtr008c:
btst #26,%d0
beq.s ___atr008c
or.w %d1,(%a0)+
bra.s ___ctr008c
___atr008c:
and.w %d2,(%a0)+
___ctr008c:
btst #25,%d3
bne.s ___drtr008d
adda.w #2,%a0
bra.s  ___ctr008d
___drtr008d:
btst #25,%d0
beq.s ___atr008d
or.w %d1,(%a0)+
bra.s ___ctr008d
___atr008d:
and.w %d2,(%a0)+
___ctr008d:
btst #23,%d3
bne.s ___drtr008e
adda.w #2,%a0
bra.s  ___ctr008e
___drtr008e:
btst #23,%d0
beq.s ___atr008e
or.w %d1,(%a0)+
bra.s ___ctr008e
___atr008e:
and.w %d2,(%a0)+
___ctr008e:
btst #21,%d3
bne.s ___drtr008f
adda.w #2,%a0
bra.s  ___ctr008f
___drtr008f:
btst #21,%d0
beq.s ___atr008f
or.w %d1,(%a0)+
bra.s ___ctr008f
___atr008f:
and.w %d2,(%a0)+
___ctr008f:
btst #20,%d3
bne.s ___drtr0090
adda.w #2,%a0
bra.s  ___ctr0090
___drtr0090:
btst #20,%d0
beq.s ___atr0090
or.w %d1,(%a0)+
bra.s ___ctr0090
___atr0090:
and.w %d2,(%a0)+
___ctr0090:
btst #18,%d3
bne.s ___drtr0091
adda.w #2,%a0
bra.s  ___ctr0091
___drtr0091:
btst #18,%d0
beq.s ___atr0091
or.w %d1,(%a0)+
bra.s ___ctr0091
___atr0091:
and.w %d2,(%a0)+
___ctr0091:
btst #16,%d3
bne.s ___drtr0092
adda.w #2,%a0
bra.s  ___ctr0092
___drtr0092:
btst #16,%d0
beq.s ___atr0092
or.w %d1,(%a0)+
bra.s ___ctr0092
___atr0092:
and.w %d2,(%a0)+
___ctr0092:
btst #14,%d3
bne.s ___drtr0093
adda.w #2,%a0
bra.s  ___ctr0093
___drtr0093:
btst #14,%d0
beq.s ___atr0093
or.w %d1,(%a0)+
bra.s ___ctr0093
___atr0093:
and.w %d2,(%a0)+
___ctr0093:
btst #13,%d3
bne.s ___drtr0094
adda.w #2,%a0
bra.s  ___ctr0094
___drtr0094:
btst #13,%d0
beq.s ___atr0094
or.w %d1,(%a0)+
bra.s ___ctr0094
___atr0094:
and.w %d2,(%a0)+
___ctr0094:
btst #11,%d3
bne.s ___drtr0095
adda.w #2,%a0
bra.s  ___ctr0095
___drtr0095:
btst #11,%d0
beq.s ___atr0095
or.w %d1,(%a0)+
bra.s ___ctr0095
___atr0095:
and.w %d2,(%a0)+
___ctr0095:
btst #9,%d3
bne.s ___drtr0096
adda.w #2,%a0
bra.s  ___ctr0096
___drtr0096:
btst #9,%d0
beq.s ___atr0096
or.w %d1,(%a0)+
bra.s ___ctr0096
___atr0096:
and.w %d2,(%a0)+
___ctr0096:
btst #8,%d3
bne.s ___drtr0097
adda.w #2,%a0
bra.s  ___ctr0097
___drtr0097:
btst #8,%d0
beq.s ___atr0097
or.w %d1,(%a0)+
bra.s ___ctr0097
___atr0097:
and.w %d2,(%a0)+
___ctr0097:
btst #6,%d3
bne.s ___drtr0098
adda.w #2,%a0
bra.s  ___ctr0098
___drtr0098:
btst #6,%d0
beq.s ___atr0098
or.w %d1,(%a0)+
bra.s ___ctr0098
___atr0098:
and.w %d2,(%a0)+
___ctr0098:
btst #4,%d3
bne.s ___drtr0099
adda.w #2,%a0
bra.s  ___ctr0099
___drtr0099:
btst #4,%d0
beq.s ___atr0099
or.w %d1,(%a0)+
bra.s ___ctr0099
___atr0099:
and.w %d2,(%a0)+
___ctr0099:
btst #3,%d3
bne.s ___drtr009a
adda.w #2,%a0
bra.s  ___ctr009a
___drtr009a:
btst #3,%d0
beq.s ___atr009a
or.w %d1,(%a0)+
bra.s ___ctr009a
___atr009a:
and.w %d2,(%a0)+
___ctr009a:
btst #1,%d3
bne.s ___drtr009b
rts
___drtr009b:
btst #1,%d0
beq.s ___atr009b
or.w %d1,(%a0)+
rts
___atr009b:
and.w %d2,(%a0)+
rts
__tr_scale042:
tst.l %d3
bmi.s ___drtr009c
adda.w #2,%a0
bra.s  ___ctr009c
___drtr009c:
tst.l %d0
bpl.s ___atr009c
or.w %d1,(%a0)+
bra.s ___ctr009c
___atr009c:
and.w %d2,(%a0)+
___ctr009c:
btst #30,%d3
bne.s ___drtr009d
adda.w #2,%a0
bra.s  ___ctr009d
___drtr009d:
btst #30,%d0
beq.s ___atr009d
or.w %d1,(%a0)+
bra.s ___ctr009d
___atr009d:
and.w %d2,(%a0)+
___ctr009d:
btst #28,%d3
bne.s ___drtr009e
adda.w #2,%a0
bra.s  ___ctr009e
___drtr009e:
btst #28,%d0
beq.s ___atr009e
or.w %d1,(%a0)+
bra.s ___ctr009e
___atr009e:
and.w %d2,(%a0)+
___ctr009e:
btst #27,%d3
bne.s ___drtr009f
adda.w #2,%a0
bra.s  ___ctr009f
___drtr009f:
btst #27,%d0
beq.s ___atr009f
or.w %d1,(%a0)+
bra.s ___ctr009f
___atr009f:
and.w %d2,(%a0)+
___ctr009f:
btst #25,%d3
bne.s ___drtr00a0
adda.w #2,%a0
bra.s  ___ctr00a0
___drtr00a0:
btst #25,%d0
beq.s ___atr00a0
or.w %d1,(%a0)+
bra.s ___ctr00a0
___atr00a0:
and.w %d2,(%a0)+
___ctr00a0:
btst #24,%d3
bne.s ___drtr00a1
adda.w #2,%a0
bra.s  ___ctr00a1
___drtr00a1:
btst #24,%d0
beq.s ___atr00a1
or.w %d1,(%a0)+
bra.s ___ctr00a1
___atr00a1:
and.w %d2,(%a0)+
___ctr00a1:
btst #22,%d3
bne.s ___drtr00a2
adda.w #2,%a0
bra.s  ___ctr00a2
___drtr00a2:
btst #22,%d0
beq.s ___atr00a2
or.w %d1,(%a0)+
bra.s ___ctr00a2
___atr00a2:
and.w %d2,(%a0)+
___ctr00a2:
btst #21,%d3
bne.s ___drtr00a3
adda.w #2,%a0
bra.s  ___ctr00a3
___drtr00a3:
btst #21,%d0
beq.s ___atr00a3
or.w %d1,(%a0)+
bra.s ___ctr00a3
___atr00a3:
and.w %d2,(%a0)+
___ctr00a3:
btst #19,%d3
bne.s ___drtr00a4
adda.w #2,%a0
bra.s  ___ctr00a4
___drtr00a4:
btst #19,%d0
beq.s ___atr00a4
or.w %d1,(%a0)+
bra.s ___ctr00a4
___atr00a4:
and.w %d2,(%a0)+
___ctr00a4:
btst #18,%d3
bne.s ___drtr00a5
adda.w #2,%a0
bra.s  ___ctr00a5
___drtr00a5:
btst #18,%d0
beq.s ___atr00a5
or.w %d1,(%a0)+
bra.s ___ctr00a5
___atr00a5:
and.w %d2,(%a0)+
___ctr00a5:
btst #16,%d3
bne.s ___drtr00a6
adda.w #2,%a0
bra.s  ___ctr00a6
___drtr00a6:
btst #16,%d0
beq.s ___atr00a6
or.w %d1,(%a0)+
bra.s ___ctr00a6
___atr00a6:
and.w %d2,(%a0)+
___ctr00a6:
tst.w %d3
bmi.s ___drtr00a7
adda.w #2,%a0
bra.s  ___ctr00a7
___drtr00a7:
tst.w %d0
bpl.s ___atr00a7
or.w %d1,(%a0)+
bra.s ___ctr00a7
___atr00a7:
and.w %d2,(%a0)+
___ctr00a7:
btst #13,%d3
bne.s ___drtr00a8
adda.w #2,%a0
bra.s  ___ctr00a8
___drtr00a8:
btst #13,%d0
beq.s ___atr00a8
or.w %d1,(%a0)+
bra.s ___ctr00a8
___atr00a8:
and.w %d2,(%a0)+
___ctr00a8:
btst #12,%d3
bne.s ___drtr00a9
adda.w #2,%a0
bra.s  ___ctr00a9
___drtr00a9:
btst #12,%d0
beq.s ___atr00a9
or.w %d1,(%a0)+
bra.s ___ctr00a9
___atr00a9:
and.w %d2,(%a0)+
___ctr00a9:
btst #10,%d3
bne.s ___drtr00aa
adda.w #2,%a0
bra.s  ___ctr00aa
___drtr00aa:
btst #10,%d0
beq.s ___atr00aa
or.w %d1,(%a0)+
bra.s ___ctr00aa
___atr00aa:
and.w %d2,(%a0)+
___ctr00aa:
btst #8,%d3
bne.s ___drtr00ab
adda.w #2,%a0
bra.s  ___ctr00ab
___drtr00ab:
btst #8,%d0
beq.s ___atr00ab
or.w %d1,(%a0)+
bra.s ___ctr00ab
___atr00ab:
and.w %d2,(%a0)+
___ctr00ab:
tst.b %d3
bmi.s ___drtr00ac
adda.w #2,%a0
bra.s  ___ctr00ac
___drtr00ac:
tst.b %d0
bpl.s ___atr00ac
or.w %d1,(%a0)+
bra.s ___ctr00ac
___atr00ac:
and.w %d2,(%a0)+
___ctr00ac:
btst #5,%d3
bne.s ___drtr00ad
adda.w #2,%a0
bra.s  ___ctr00ad
___drtr00ad:
btst #5,%d0
beq.s ___atr00ad
or.w %d1,(%a0)+
bra.s ___ctr00ad
___atr00ad:
and.w %d2,(%a0)+
___ctr00ad:
btst #4,%d3
bne.s ___drtr00ae
adda.w #2,%a0
bra.s  ___ctr00ae
___drtr00ae:
btst #4,%d0
beq.s ___atr00ae
or.w %d1,(%a0)+
bra.s ___ctr00ae
___atr00ae:
and.w %d2,(%a0)+
___ctr00ae:
btst #2,%d3
bne.s ___drtr00af
adda.w #2,%a0
bra.s  ___ctr00af
___drtr00af:
btst #2,%d0
beq.s ___atr00af
or.w %d1,(%a0)+
bra.s ___ctr00af
___atr00af:
and.w %d2,(%a0)+
___ctr00af:
btst #1,%d3
bne.s ___drtr00b0
rts
___drtr00b0:
btst #1,%d0
beq.s ___atr00b0
or.w %d1,(%a0)+
rts
___atr00b0:
and.w %d2,(%a0)+
rts
__tr_scale046:
tst.l %d3
bmi.s ___drtr00b1
adda.w #2,%a0
bra.s  ___ctr00b1
___drtr00b1:
tst.l %d0
bpl.s ___atr00b1
or.w %d1,(%a0)+
bra.s ___ctr00b1
___atr00b1:
and.w %d2,(%a0)+
___ctr00b1:
btst #30,%d3
bne.s ___drtr00b2
adda.w #2,%a0
bra.s  ___ctr00b2
___drtr00b2:
btst #30,%d0
beq.s ___atr00b2
or.w %d1,(%a0)+
bra.s ___ctr00b2
___atr00b2:
and.w %d2,(%a0)+
___ctr00b2:
btst #29,%d3
bne.s ___drtr00b3
adda.w #2,%a0
bra.s  ___ctr00b3
___drtr00b3:
btst #29,%d0
beq.s ___atr00b3
or.w %d1,(%a0)+
bra.s ___ctr00b3
___atr00b3:
and.w %d2,(%a0)+
___ctr00b3:
btst #27,%d3
bne.s ___drtr00b4
adda.w #2,%a0
bra.s  ___ctr00b4
___drtr00b4:
btst #27,%d0
beq.s ___atr00b4
or.w %d1,(%a0)+
bra.s ___ctr00b4
___atr00b4:
and.w %d2,(%a0)+
___ctr00b4:
btst #26,%d3
bne.s ___drtr00b5
adda.w #2,%a0
bra.s  ___ctr00b5
___drtr00b5:
btst #26,%d0
beq.s ___atr00b5
or.w %d1,(%a0)+
bra.s ___ctr00b5
___atr00b5:
and.w %d2,(%a0)+
___ctr00b5:
btst #24,%d3
bne.s ___drtr00b6
adda.w #2,%a0
bra.s  ___ctr00b6
___drtr00b6:
btst #24,%d0
beq.s ___atr00b6
or.w %d1,(%a0)+
bra.s ___ctr00b6
___atr00b6:
and.w %d2,(%a0)+
___ctr00b6:
btst #23,%d3
bne.s ___drtr00b7
adda.w #2,%a0
bra.s  ___ctr00b7
___drtr00b7:
btst #23,%d0
beq.s ___atr00b7
or.w %d1,(%a0)+
bra.s ___ctr00b7
___atr00b7:
and.w %d2,(%a0)+
___ctr00b7:
btst #22,%d3
bne.s ___drtr00b8
adda.w #2,%a0
bra.s  ___ctr00b8
___drtr00b8:
btst #22,%d0
beq.s ___atr00b8
or.w %d1,(%a0)+
bra.s ___ctr00b8
___atr00b8:
and.w %d2,(%a0)+
___ctr00b8:
btst #20,%d3
bne.s ___drtr00b9
adda.w #2,%a0
bra.s  ___ctr00b9
___drtr00b9:
btst #20,%d0
beq.s ___atr00b9
or.w %d1,(%a0)+
bra.s ___ctr00b9
___atr00b9:
and.w %d2,(%a0)+
___ctr00b9:
btst #19,%d3
bne.s ___drtr00ba
adda.w #2,%a0
bra.s  ___ctr00ba
___drtr00ba:
btst #19,%d0
beq.s ___atr00ba
or.w %d1,(%a0)+
bra.s ___ctr00ba
___atr00ba:
and.w %d2,(%a0)+
___ctr00ba:
btst #17,%d3
bne.s ___drtr00bb
adda.w #2,%a0
bra.s  ___ctr00bb
___drtr00bb:
btst #17,%d0
beq.s ___atr00bb
or.w %d1,(%a0)+
bra.s ___ctr00bb
___atr00bb:
and.w %d2,(%a0)+
___ctr00bb:
btst #16,%d3
bne.s ___drtr00bc
adda.w #2,%a0
bra.s  ___ctr00bc
___drtr00bc:
btst #16,%d0
beq.s ___atr00bc
or.w %d1,(%a0)+
bra.s ___ctr00bc
___atr00bc:
and.w %d2,(%a0)+
___ctr00bc:
tst.w %d3
bmi.s ___drtr00bd
adda.w #2,%a0
bra.s  ___ctr00bd
___drtr00bd:
tst.w %d0
bpl.s ___atr00bd
or.w %d1,(%a0)+
bra.s ___ctr00bd
___atr00bd:
and.w %d2,(%a0)+
___ctr00bd:
btst #13,%d3
bne.s ___drtr00be
adda.w #2,%a0
bra.s  ___ctr00be
___drtr00be:
btst #13,%d0
beq.s ___atr00be
or.w %d1,(%a0)+
bra.s ___ctr00be
___atr00be:
and.w %d2,(%a0)+
___ctr00be:
btst #12,%d3
bne.s ___drtr00bf
adda.w #2,%a0
bra.s  ___ctr00bf
___drtr00bf:
btst #12,%d0
beq.s ___atr00bf
or.w %d1,(%a0)+
bra.s ___ctr00bf
___atr00bf:
and.w %d2,(%a0)+
___ctr00bf:
btst #11,%d3
bne.s ___drtr00c0
adda.w #2,%a0
bra.s  ___ctr00c0
___drtr00c0:
btst #11,%d0
beq.s ___atr00c0
or.w %d1,(%a0)+
bra.s ___ctr00c0
___atr00c0:
and.w %d2,(%a0)+
___ctr00c0:
btst #9,%d3
bne.s ___drtr00c1
adda.w #2,%a0
bra.s  ___ctr00c1
___drtr00c1:
btst #9,%d0
beq.s ___atr00c1
or.w %d1,(%a0)+
bra.s ___ctr00c1
___atr00c1:
and.w %d2,(%a0)+
___ctr00c1:
btst #8,%d3
bne.s ___drtr00c2
adda.w #2,%a0
bra.s  ___ctr00c2
___drtr00c2:
btst #8,%d0
beq.s ___atr00c2
or.w %d1,(%a0)+
bra.s ___ctr00c2
___atr00c2:
and.w %d2,(%a0)+
___ctr00c2:
btst #6,%d3
bne.s ___drtr00c3
adda.w #2,%a0
bra.s  ___ctr00c3
___drtr00c3:
btst #6,%d0
beq.s ___atr00c3
or.w %d1,(%a0)+
bra.s ___ctr00c3
___atr00c3:
and.w %d2,(%a0)+
___ctr00c3:
btst #5,%d3
bne.s ___drtr00c4
adda.w #2,%a0
bra.s  ___ctr00c4
___drtr00c4:
btst #5,%d0
beq.s ___atr00c4
or.w %d1,(%a0)+
bra.s ___ctr00c4
___atr00c4:
and.w %d2,(%a0)+
___ctr00c4:
btst #4,%d3
bne.s ___drtr00c5
adda.w #2,%a0
bra.s  ___ctr00c5
___drtr00c5:
btst #4,%d0
beq.s ___atr00c5
or.w %d1,(%a0)+
bra.s ___ctr00c5
___atr00c5:
and.w %d2,(%a0)+
___ctr00c5:
btst #2,%d3
bne.s ___drtr00c6
adda.w #2,%a0
bra.s  ___ctr00c6
___drtr00c6:
btst #2,%d0
beq.s ___atr00c6
or.w %d1,(%a0)+
bra.s ___ctr00c6
___atr00c6:
and.w %d2,(%a0)+
___ctr00c6:
btst #1,%d3
bne.s ___drtr00c7
rts
___drtr00c7:
btst #1,%d0
beq.s ___atr00c7
or.w %d1,(%a0)+
rts
___atr00c7:
and.w %d2,(%a0)+
rts
__tr_scale050:
tst.l %d3
bmi.s ___drtr00c8
adda.w #2,%a0
bra.s  ___ctr00c8
___drtr00c8:
tst.l %d0
bpl.s ___atr00c8
or.w %d1,(%a0)+
bra.s ___ctr00c8
___atr00c8:
and.w %d2,(%a0)+
___ctr00c8:
btst #30,%d3
bne.s ___drtr00c9
adda.w #2,%a0
bra.s  ___ctr00c9
___drtr00c9:
btst #30,%d0
beq.s ___atr00c9
or.w %d1,(%a0)+
bra.s ___ctr00c9
___atr00c9:
and.w %d2,(%a0)+
___ctr00c9:
btst #29,%d3
bne.s ___drtr00ca
adda.w #2,%a0
bra.s  ___ctr00ca
___drtr00ca:
btst #29,%d0
beq.s ___atr00ca
or.w %d1,(%a0)+
bra.s ___ctr00ca
___atr00ca:
and.w %d2,(%a0)+
___ctr00ca:
btst #28,%d3
bne.s ___drtr00cb
adda.w #2,%a0
bra.s  ___ctr00cb
___drtr00cb:
btst #28,%d0
beq.s ___atr00cb
or.w %d1,(%a0)+
bra.s ___ctr00cb
___atr00cb:
and.w %d2,(%a0)+
___ctr00cb:
btst #26,%d3
bne.s ___drtr00cc
adda.w #2,%a0
bra.s  ___ctr00cc
___drtr00cc:
btst #26,%d0
beq.s ___atr00cc
or.w %d1,(%a0)+
bra.s ___ctr00cc
___atr00cc:
and.w %d2,(%a0)+
___ctr00cc:
btst #25,%d3
bne.s ___drtr00cd
adda.w #2,%a0
bra.s  ___ctr00cd
___drtr00cd:
btst #25,%d0
beq.s ___atr00cd
or.w %d1,(%a0)+
bra.s ___ctr00cd
___atr00cd:
and.w %d2,(%a0)+
___ctr00cd:
btst #24,%d3
bne.s ___drtr00ce
adda.w #2,%a0
bra.s  ___ctr00ce
___drtr00ce:
btst #24,%d0
beq.s ___atr00ce
or.w %d1,(%a0)+
bra.s ___ctr00ce
___atr00ce:
and.w %d2,(%a0)+
___ctr00ce:
btst #22,%d3
bne.s ___drtr00cf
adda.w #2,%a0
bra.s  ___ctr00cf
___drtr00cf:
btst #22,%d0
beq.s ___atr00cf
or.w %d1,(%a0)+
bra.s ___ctr00cf
___atr00cf:
and.w %d2,(%a0)+
___ctr00cf:
btst #21,%d3
bne.s ___drtr00d0
adda.w #2,%a0
bra.s  ___ctr00d0
___drtr00d0:
btst #21,%d0
beq.s ___atr00d0
or.w %d1,(%a0)+
bra.s ___ctr00d0
___atr00d0:
and.w %d2,(%a0)+
___ctr00d0:
btst #20,%d3
bne.s ___drtr00d1
adda.w #2,%a0
bra.s  ___ctr00d1
___drtr00d1:
btst #20,%d0
beq.s ___atr00d1
or.w %d1,(%a0)+
bra.s ___ctr00d1
___atr00d1:
and.w %d2,(%a0)+
___ctr00d1:
btst #19,%d3
bne.s ___drtr00d2
adda.w #2,%a0
bra.s  ___ctr00d2
___drtr00d2:
btst #19,%d0
beq.s ___atr00d2
or.w %d1,(%a0)+
bra.s ___ctr00d2
___atr00d2:
and.w %d2,(%a0)+
___ctr00d2:
btst #17,%d3
bne.s ___drtr00d3
adda.w #2,%a0
bra.s  ___ctr00d3
___drtr00d3:
btst #17,%d0
beq.s ___atr00d3
or.w %d1,(%a0)+
bra.s ___ctr00d3
___atr00d3:
and.w %d2,(%a0)+
___ctr00d3:
btst #16,%d3
bne.s ___drtr00d4
adda.w #2,%a0
bra.s  ___ctr00d4
___drtr00d4:
btst #16,%d0
beq.s ___atr00d4
or.w %d1,(%a0)+
bra.s ___ctr00d4
___atr00d4:
and.w %d2,(%a0)+
___ctr00d4:
tst.w %d3
bmi.s ___drtr00d5
adda.w #2,%a0
bra.s  ___ctr00d5
___drtr00d5:
tst.w %d0
bpl.s ___atr00d5
or.w %d1,(%a0)+
bra.s ___ctr00d5
___atr00d5:
and.w %d2,(%a0)+
___ctr00d5:
btst #13,%d3
bne.s ___drtr00d6
adda.w #2,%a0
bra.s  ___ctr00d6
___drtr00d6:
btst #13,%d0
beq.s ___atr00d6
or.w %d1,(%a0)+
bra.s ___ctr00d6
___atr00d6:
and.w %d2,(%a0)+
___ctr00d6:
btst #12,%d3
bne.s ___drtr00d7
adda.w #2,%a0
bra.s  ___ctr00d7
___drtr00d7:
btst #12,%d0
beq.s ___atr00d7
or.w %d1,(%a0)+
bra.s ___ctr00d7
___atr00d7:
and.w %d2,(%a0)+
___ctr00d7:
btst #11,%d3
bne.s ___drtr00d8
adda.w #2,%a0
bra.s  ___ctr00d8
___drtr00d8:
btst #11,%d0
beq.s ___atr00d8
or.w %d1,(%a0)+
bra.s ___ctr00d8
___atr00d8:
and.w %d2,(%a0)+
___ctr00d8:
btst #10,%d3
bne.s ___drtr00d9
adda.w #2,%a0
bra.s  ___ctr00d9
___drtr00d9:
btst #10,%d0
beq.s ___atr00d9
or.w %d1,(%a0)+
bra.s ___ctr00d9
___atr00d9:
and.w %d2,(%a0)+
___ctr00d9:
btst #8,%d3
bne.s ___drtr00da
adda.w #2,%a0
bra.s  ___ctr00da
___drtr00da:
btst #8,%d0
beq.s ___atr00da
or.w %d1,(%a0)+
bra.s ___ctr00da
___atr00da:
and.w %d2,(%a0)+
___ctr00da:
tst.b %d3
bmi.s ___drtr00db
adda.w #2,%a0
bra.s  ___ctr00db
___drtr00db:
tst.b %d0
bpl.s ___atr00db
or.w %d1,(%a0)+
bra.s ___ctr00db
___atr00db:
and.w %d2,(%a0)+
___ctr00db:
btst #6,%d3
bne.s ___drtr00dc
adda.w #2,%a0
bra.s  ___ctr00dc
___drtr00dc:
btst #6,%d0
beq.s ___atr00dc
or.w %d1,(%a0)+
bra.s ___ctr00dc
___atr00dc:
and.w %d2,(%a0)+
___ctr00dc:
btst #5,%d3
bne.s ___drtr00dd
adda.w #2,%a0
bra.s  ___ctr00dd
___drtr00dd:
btst #5,%d0
beq.s ___atr00dd
or.w %d1,(%a0)+
bra.s ___ctr00dd
___atr00dd:
and.w %d2,(%a0)+
___ctr00dd:
btst #3,%d3
bne.s ___drtr00de
adda.w #2,%a0
bra.s  ___ctr00de
___drtr00de:
btst #3,%d0
beq.s ___atr00de
or.w %d1,(%a0)+
bra.s ___ctr00de
___atr00de:
and.w %d2,(%a0)+
___ctr00de:
btst #2,%d3
bne.s ___drtr00df
adda.w #2,%a0
bra.s  ___ctr00df
___drtr00df:
btst #2,%d0
beq.s ___atr00df
or.w %d1,(%a0)+
bra.s ___ctr00df
___atr00df:
and.w %d2,(%a0)+
___ctr00df:
btst #1,%d3
bne.s ___drtr00e0
rts
___drtr00e0:
btst #1,%d0
beq.s ___atr00e0
or.w %d1,(%a0)+
rts
___atr00e0:
and.w %d2,(%a0)+
rts
__tr_scale054:
tst.l %d3
bmi.s ___drtr00e1
adda.w #2,%a0
bra.s  ___ctr00e1
___drtr00e1:
tst.l %d0
bpl.s ___atr00e1
or.w %d1,(%a0)+
bra.s ___ctr00e1
___atr00e1:
and.w %d2,(%a0)+
___ctr00e1:
btst #30,%d3
bne.s ___drtr00e2
adda.w #2,%a0
bra.s  ___ctr00e2
___drtr00e2:
btst #30,%d0
beq.s ___atr00e2
or.w %d1,(%a0)+
bra.s ___ctr00e2
___atr00e2:
and.w %d2,(%a0)+
___ctr00e2:
btst #29,%d3
bne.s ___drtr00e3
adda.w #2,%a0
bra.s  ___ctr00e3
___drtr00e3:
btst #29,%d0
beq.s ___atr00e3
or.w %d1,(%a0)+
bra.s ___ctr00e3
___atr00e3:
and.w %d2,(%a0)+
___ctr00e3:
btst #28,%d3
bne.s ___drtr00e4
adda.w #2,%a0
bra.s  ___ctr00e4
___drtr00e4:
btst #28,%d0
beq.s ___atr00e4
or.w %d1,(%a0)+
bra.s ___ctr00e4
___atr00e4:
and.w %d2,(%a0)+
___ctr00e4:
btst #27,%d3
bne.s ___drtr00e5
adda.w #2,%a0
bra.s  ___ctr00e5
___drtr00e5:
btst #27,%d0
beq.s ___atr00e5
or.w %d1,(%a0)+
bra.s ___ctr00e5
___atr00e5:
and.w %d2,(%a0)+
___ctr00e5:
btst #26,%d3
bne.s ___drtr00e6
adda.w #2,%a0
bra.s  ___ctr00e6
___drtr00e6:
btst #26,%d0
beq.s ___atr00e6
or.w %d1,(%a0)+
bra.s ___ctr00e6
___atr00e6:
and.w %d2,(%a0)+
___ctr00e6:
btst #24,%d3
bne.s ___drtr00e7
adda.w #2,%a0
bra.s  ___ctr00e7
___drtr00e7:
btst #24,%d0
beq.s ___atr00e7
or.w %d1,(%a0)+
bra.s ___ctr00e7
___atr00e7:
and.w %d2,(%a0)+
___ctr00e7:
btst #23,%d3
bne.s ___drtr00e8
adda.w #2,%a0
bra.s  ___ctr00e8
___drtr00e8:
btst #23,%d0
beq.s ___atr00e8
or.w %d1,(%a0)+
bra.s ___ctr00e8
___atr00e8:
and.w %d2,(%a0)+
___ctr00e8:
btst #22,%d3
bne.s ___drtr00e9
adda.w #2,%a0
bra.s  ___ctr00e9
___drtr00e9:
btst #22,%d0
beq.s ___atr00e9
or.w %d1,(%a0)+
bra.s ___ctr00e9
___atr00e9:
and.w %d2,(%a0)+
___ctr00e9:
btst #21,%d3
bne.s ___drtr00ea
adda.w #2,%a0
bra.s  ___ctr00ea
___drtr00ea:
btst #21,%d0
beq.s ___atr00ea
or.w %d1,(%a0)+
bra.s ___ctr00ea
___atr00ea:
and.w %d2,(%a0)+
___ctr00ea:
btst #20,%d3
bne.s ___drtr00eb
adda.w #2,%a0
bra.s  ___ctr00eb
___drtr00eb:
btst #20,%d0
beq.s ___atr00eb
or.w %d1,(%a0)+
bra.s ___ctr00eb
___atr00eb:
and.w %d2,(%a0)+
___ctr00eb:
btst #18,%d3
bne.s ___drtr00ec
adda.w #2,%a0
bra.s  ___ctr00ec
___drtr00ec:
btst #18,%d0
beq.s ___atr00ec
or.w %d1,(%a0)+
bra.s ___ctr00ec
___atr00ec:
and.w %d2,(%a0)+
___ctr00ec:
btst #17,%d3
bne.s ___drtr00ed
adda.w #2,%a0
bra.s  ___ctr00ed
___drtr00ed:
btst #17,%d0
beq.s ___atr00ed
or.w %d1,(%a0)+
bra.s ___ctr00ed
___atr00ed:
and.w %d2,(%a0)+
___ctr00ed:
btst #16,%d3
bne.s ___drtr00ee
adda.w #2,%a0
bra.s  ___ctr00ee
___drtr00ee:
btst #16,%d0
beq.s ___atr00ee
or.w %d1,(%a0)+
bra.s ___ctr00ee
___atr00ee:
and.w %d2,(%a0)+
___ctr00ee:
tst.w %d3
bmi.s ___drtr00ef
adda.w #2,%a0
bra.s  ___ctr00ef
___drtr00ef:
tst.w %d0
bpl.s ___atr00ef
or.w %d1,(%a0)+
bra.s ___ctr00ef
___atr00ef:
and.w %d2,(%a0)+
___ctr00ef:
btst #14,%d3
bne.s ___drtr00f0
adda.w #2,%a0
bra.s  ___ctr00f0
___drtr00f0:
btst #14,%d0
beq.s ___atr00f0
or.w %d1,(%a0)+
bra.s ___ctr00f0
___atr00f0:
and.w %d2,(%a0)+
___ctr00f0:
btst #12,%d3
bne.s ___drtr00f1
adda.w #2,%a0
bra.s  ___ctr00f1
___drtr00f1:
btst #12,%d0
beq.s ___atr00f1
or.w %d1,(%a0)+
bra.s ___ctr00f1
___atr00f1:
and.w %d2,(%a0)+
___ctr00f1:
btst #11,%d3
bne.s ___drtr00f2
adda.w #2,%a0
bra.s  ___ctr00f2
___drtr00f2:
btst #11,%d0
beq.s ___atr00f2
or.w %d1,(%a0)+
bra.s ___ctr00f2
___atr00f2:
and.w %d2,(%a0)+
___ctr00f2:
btst #10,%d3
bne.s ___drtr00f3
adda.w #2,%a0
bra.s  ___ctr00f3
___drtr00f3:
btst #10,%d0
beq.s ___atr00f3
or.w %d1,(%a0)+
bra.s ___ctr00f3
___atr00f3:
and.w %d2,(%a0)+
___ctr00f3:
btst #9,%d3
bne.s ___drtr00f4
adda.w #2,%a0
bra.s  ___ctr00f4
___drtr00f4:
btst #9,%d0
beq.s ___atr00f4
or.w %d1,(%a0)+
bra.s ___ctr00f4
___atr00f4:
and.w %d2,(%a0)+
___ctr00f4:
btst #8,%d3
bne.s ___drtr00f5
adda.w #2,%a0
bra.s  ___ctr00f5
___drtr00f5:
btst #8,%d0
beq.s ___atr00f5
or.w %d1,(%a0)+
bra.s ___ctr00f5
___atr00f5:
and.w %d2,(%a0)+
___ctr00f5:
tst.b %d3
bmi.s ___drtr00f6
adda.w #2,%a0
bra.s  ___ctr00f6
___drtr00f6:
tst.b %d0
bpl.s ___atr00f6
or.w %d1,(%a0)+
bra.s ___ctr00f6
___atr00f6:
and.w %d2,(%a0)+
___ctr00f6:
btst #5,%d3
bne.s ___drtr00f7
adda.w #2,%a0
bra.s  ___ctr00f7
___drtr00f7:
btst #5,%d0
beq.s ___atr00f7
or.w %d1,(%a0)+
bra.s ___ctr00f7
___atr00f7:
and.w %d2,(%a0)+
___ctr00f7:
btst #4,%d3
bne.s ___drtr00f8
adda.w #2,%a0
bra.s  ___ctr00f8
___drtr00f8:
btst #4,%d0
beq.s ___atr00f8
or.w %d1,(%a0)+
bra.s ___ctr00f8
___atr00f8:
and.w %d2,(%a0)+
___ctr00f8:
btst #3,%d3
bne.s ___drtr00f9
adda.w #2,%a0
bra.s  ___ctr00f9
___drtr00f9:
btst #3,%d0
beq.s ___atr00f9
or.w %d1,(%a0)+
bra.s ___ctr00f9
___atr00f9:
and.w %d2,(%a0)+
___ctr00f9:
btst #2,%d3
bne.s ___drtr00fa
adda.w #2,%a0
bra.s  ___ctr00fa
___drtr00fa:
btst #2,%d0
beq.s ___atr00fa
or.w %d1,(%a0)+
bra.s ___ctr00fa
___atr00fa:
and.w %d2,(%a0)+
___ctr00fa:
btst #1,%d3
bne.s ___drtr00fb
rts
___drtr00fb:
btst #1,%d0
beq.s ___atr00fb
or.w %d1,(%a0)+
rts
___atr00fb:
and.w %d2,(%a0)+
rts
__tr_scale058:
tst.l %d3
bmi.s ___drtr00fc
adda.w #2,%a0
bra.s  ___ctr00fc
___drtr00fc:
tst.l %d0
bpl.s ___atr00fc
or.w %d1,(%a0)+
bra.s ___ctr00fc
___atr00fc:
and.w %d2,(%a0)+
___ctr00fc:
btst #30,%d3
bne.s ___drtr00fd
adda.w #2,%a0
bra.s  ___ctr00fd
___drtr00fd:
btst #30,%d0
beq.s ___atr00fd
or.w %d1,(%a0)+
bra.s ___ctr00fd
___atr00fd:
and.w %d2,(%a0)+
___ctr00fd:
btst #29,%d3
bne.s ___drtr00fe
adda.w #2,%a0
bra.s  ___ctr00fe
___drtr00fe:
btst #29,%d0
beq.s ___atr00fe
or.w %d1,(%a0)+
bra.s ___ctr00fe
___atr00fe:
and.w %d2,(%a0)+
___ctr00fe:
btst #28,%d3
bne.s ___drtr00ff
adda.w #2,%a0
bra.s  ___ctr00ff
___drtr00ff:
btst #28,%d0
beq.s ___atr00ff
or.w %d1,(%a0)+
bra.s ___ctr00ff
___atr00ff:
and.w %d2,(%a0)+
___ctr00ff:
btst #27,%d3
bne.s ___drtr0100
adda.w #2,%a0
bra.s  ___ctr0100
___drtr0100:
btst #27,%d0
beq.s ___atr0100
or.w %d1,(%a0)+
bra.s ___ctr0100
___atr0100:
and.w %d2,(%a0)+
___ctr0100:
btst #26,%d3
bne.s ___drtr0101
adda.w #2,%a0
bra.s  ___ctr0101
___drtr0101:
btst #26,%d0
beq.s ___atr0101
or.w %d1,(%a0)+
bra.s ___ctr0101
___atr0101:
and.w %d2,(%a0)+
___ctr0101:
btst #25,%d3
bne.s ___drtr0102
adda.w #2,%a0
bra.s  ___ctr0102
___drtr0102:
btst #25,%d0
beq.s ___atr0102
or.w %d1,(%a0)+
bra.s ___ctr0102
___atr0102:
and.w %d2,(%a0)+
___ctr0102:
btst #24,%d3
bne.s ___drtr0103
adda.w #2,%a0
bra.s  ___ctr0103
___drtr0103:
btst #24,%d0
beq.s ___atr0103
or.w %d1,(%a0)+
bra.s ___ctr0103
___atr0103:
and.w %d2,(%a0)+
___ctr0103:
btst #23,%d3
bne.s ___drtr0104
adda.w #2,%a0
bra.s  ___ctr0104
___drtr0104:
btst #23,%d0
beq.s ___atr0104
or.w %d1,(%a0)+
bra.s ___ctr0104
___atr0104:
and.w %d2,(%a0)+
___ctr0104:
btst #22,%d3
bne.s ___drtr0105
adda.w #2,%a0
bra.s  ___ctr0105
___drtr0105:
btst #22,%d0
beq.s ___atr0105
or.w %d1,(%a0)+
bra.s ___ctr0105
___atr0105:
and.w %d2,(%a0)+
___ctr0105:
btst #20,%d3
bne.s ___drtr0106
adda.w #2,%a0
bra.s  ___ctr0106
___drtr0106:
btst #20,%d0
beq.s ___atr0106
or.w %d1,(%a0)+
bra.s ___ctr0106
___atr0106:
and.w %d2,(%a0)+
___ctr0106:
btst #19,%d3
bne.s ___drtr0107
adda.w #2,%a0
bra.s  ___ctr0107
___drtr0107:
btst #19,%d0
beq.s ___atr0107
or.w %d1,(%a0)+
bra.s ___ctr0107
___atr0107:
and.w %d2,(%a0)+
___ctr0107:
btst #18,%d3
bne.s ___drtr0108
adda.w #2,%a0
bra.s  ___ctr0108
___drtr0108:
btst #18,%d0
beq.s ___atr0108
or.w %d1,(%a0)+
bra.s ___ctr0108
___atr0108:
and.w %d2,(%a0)+
___ctr0108:
btst #17,%d3
bne.s ___drtr0109
adda.w #2,%a0
bra.s  ___ctr0109
___drtr0109:
btst #17,%d0
beq.s ___atr0109
or.w %d1,(%a0)+
bra.s ___ctr0109
___atr0109:
and.w %d2,(%a0)+
___ctr0109:
btst #16,%d3
bne.s ___drtr010a
adda.w #2,%a0
bra.s  ___ctr010a
___drtr010a:
btst #16,%d0
beq.s ___atr010a
or.w %d1,(%a0)+
bra.s ___ctr010a
___atr010a:
and.w %d2,(%a0)+
___ctr010a:
tst.w %d3
bmi.s ___drtr010b
adda.w #2,%a0
bra.s  ___ctr010b
___drtr010b:
tst.w %d0
bpl.s ___atr010b
or.w %d1,(%a0)+
bra.s ___ctr010b
___atr010b:
and.w %d2,(%a0)+
___ctr010b:
btst #14,%d3
bne.s ___drtr010c
adda.w #2,%a0
bra.s  ___ctr010c
___drtr010c:
btst #14,%d0
beq.s ___atr010c
or.w %d1,(%a0)+
bra.s ___ctr010c
___atr010c:
and.w %d2,(%a0)+
___ctr010c:
btst #13,%d3
bne.s ___drtr010d
adda.w #2,%a0
bra.s  ___ctr010d
___drtr010d:
btst #13,%d0
beq.s ___atr010d
or.w %d1,(%a0)+
bra.s ___ctr010d
___atr010d:
and.w %d2,(%a0)+
___ctr010d:
btst #12,%d3
bne.s ___drtr010e
adda.w #2,%a0
bra.s  ___ctr010e
___drtr010e:
btst #12,%d0
beq.s ___atr010e
or.w %d1,(%a0)+
bra.s ___ctr010e
___atr010e:
and.w %d2,(%a0)+
___ctr010e:
btst #11,%d3
bne.s ___drtr010f
adda.w #2,%a0
bra.s  ___ctr010f
___drtr010f:
btst #11,%d0
beq.s ___atr010f
or.w %d1,(%a0)+
bra.s ___ctr010f
___atr010f:
and.w %d2,(%a0)+
___ctr010f:
btst #9,%d3
bne.s ___drtr0110
adda.w #2,%a0
bra.s  ___ctr0110
___drtr0110:
btst #9,%d0
beq.s ___atr0110
or.w %d1,(%a0)+
bra.s ___ctr0110
___atr0110:
and.w %d2,(%a0)+
___ctr0110:
btst #8,%d3
bne.s ___drtr0111
adda.w #2,%a0
bra.s  ___ctr0111
___drtr0111:
btst #8,%d0
beq.s ___atr0111
or.w %d1,(%a0)+
bra.s ___ctr0111
___atr0111:
and.w %d2,(%a0)+
___ctr0111:
tst.b %d3
bmi.s ___drtr0112
adda.w #2,%a0
bra.s  ___ctr0112
___drtr0112:
tst.b %d0
bpl.s ___atr0112
or.w %d1,(%a0)+
bra.s ___ctr0112
___atr0112:
and.w %d2,(%a0)+
___ctr0112:
btst #6,%d3
bne.s ___drtr0113
adda.w #2,%a0
bra.s  ___ctr0113
___drtr0113:
btst #6,%d0
beq.s ___atr0113
or.w %d1,(%a0)+
bra.s ___ctr0113
___atr0113:
and.w %d2,(%a0)+
___ctr0113:
btst #5,%d3
bne.s ___drtr0114
adda.w #2,%a0
bra.s  ___ctr0114
___drtr0114:
btst #5,%d0
beq.s ___atr0114
or.w %d1,(%a0)+
bra.s ___ctr0114
___atr0114:
and.w %d2,(%a0)+
___ctr0114:
btst #4,%d3
bne.s ___drtr0115
adda.w #2,%a0
bra.s  ___ctr0115
___drtr0115:
btst #4,%d0
beq.s ___atr0115
or.w %d1,(%a0)+
bra.s ___ctr0115
___atr0115:
and.w %d2,(%a0)+
___ctr0115:
btst #3,%d3
bne.s ___drtr0116
adda.w #2,%a0
bra.s  ___ctr0116
___drtr0116:
btst #3,%d0
beq.s ___atr0116
or.w %d1,(%a0)+
bra.s ___ctr0116
___atr0116:
and.w %d2,(%a0)+
___ctr0116:
btst #2,%d3
bne.s ___drtr0117
adda.w #2,%a0
bra.s  ___ctr0117
___drtr0117:
btst #2,%d0
beq.s ___atr0117
or.w %d1,(%a0)+
bra.s ___ctr0117
___atr0117:
and.w %d2,(%a0)+
___ctr0117:
btst #1,%d3
bne.s ___drtr0118
rts
___drtr0118:
btst #1,%d0
beq.s ___atr0118
or.w %d1,(%a0)+
rts
___atr0118:
and.w %d2,(%a0)+
rts
__tr_scale062:
tst.l %d3
bmi.s ___drtr0119
adda.w #2,%a0
bra.s  ___ctr0119
___drtr0119:
tst.l %d0
bpl.s ___atr0119
or.w %d1,(%a0)+
bra.s ___ctr0119
___atr0119:
and.w %d2,(%a0)+
___ctr0119:
btst #30,%d3
bne.s ___drtr011a
adda.w #2,%a0
bra.s  ___ctr011a
___drtr011a:
btst #30,%d0
beq.s ___atr011a
or.w %d1,(%a0)+
bra.s ___ctr011a
___atr011a:
and.w %d2,(%a0)+
___ctr011a:
btst #29,%d3
bne.s ___drtr011b
adda.w #2,%a0
bra.s  ___ctr011b
___drtr011b:
btst #29,%d0
beq.s ___atr011b
or.w %d1,(%a0)+
bra.s ___ctr011b
___atr011b:
and.w %d2,(%a0)+
___ctr011b:
btst #28,%d3
bne.s ___drtr011c
adda.w #2,%a0
bra.s  ___ctr011c
___drtr011c:
btst #28,%d0
beq.s ___atr011c
or.w %d1,(%a0)+
bra.s ___ctr011c
___atr011c:
and.w %d2,(%a0)+
___ctr011c:
btst #27,%d3
bne.s ___drtr011d
adda.w #2,%a0
bra.s  ___ctr011d
___drtr011d:
btst #27,%d0
beq.s ___atr011d
or.w %d1,(%a0)+
bra.s ___ctr011d
___atr011d:
and.w %d2,(%a0)+
___ctr011d:
btst #26,%d3
bne.s ___drtr011e
adda.w #2,%a0
bra.s  ___ctr011e
___drtr011e:
btst #26,%d0
beq.s ___atr011e
or.w %d1,(%a0)+
bra.s ___ctr011e
___atr011e:
and.w %d2,(%a0)+
___ctr011e:
btst #25,%d3
bne.s ___drtr011f
adda.w #2,%a0
bra.s  ___ctr011f
___drtr011f:
btst #25,%d0
beq.s ___atr011f
or.w %d1,(%a0)+
bra.s ___ctr011f
___atr011f:
and.w %d2,(%a0)+
___ctr011f:
btst #24,%d3
bne.s ___drtr0120
adda.w #2,%a0
bra.s  ___ctr0120
___drtr0120:
btst #24,%d0
beq.s ___atr0120
or.w %d1,(%a0)+
bra.s ___ctr0120
___atr0120:
and.w %d2,(%a0)+
___ctr0120:
btst #23,%d3
bne.s ___drtr0121
adda.w #2,%a0
bra.s  ___ctr0121
___drtr0121:
btst #23,%d0
beq.s ___atr0121
or.w %d1,(%a0)+
bra.s ___ctr0121
___atr0121:
and.w %d2,(%a0)+
___ctr0121:
btst #22,%d3
bne.s ___drtr0122
adda.w #2,%a0
bra.s  ___ctr0122
___drtr0122:
btst #22,%d0
beq.s ___atr0122
or.w %d1,(%a0)+
bra.s ___ctr0122
___atr0122:
and.w %d2,(%a0)+
___ctr0122:
btst #21,%d3
bne.s ___drtr0123
adda.w #2,%a0
bra.s  ___ctr0123
___drtr0123:
btst #21,%d0
beq.s ___atr0123
or.w %d1,(%a0)+
bra.s ___ctr0123
___atr0123:
and.w %d2,(%a0)+
___ctr0123:
btst #20,%d3
bne.s ___drtr0124
adda.w #2,%a0
bra.s  ___ctr0124
___drtr0124:
btst #20,%d0
beq.s ___atr0124
or.w %d1,(%a0)+
bra.s ___ctr0124
___atr0124:
and.w %d2,(%a0)+
___ctr0124:
btst #19,%d3
bne.s ___drtr0125
adda.w #2,%a0
bra.s  ___ctr0125
___drtr0125:
btst #19,%d0
beq.s ___atr0125
or.w %d1,(%a0)+
bra.s ___ctr0125
___atr0125:
and.w %d2,(%a0)+
___ctr0125:
btst #18,%d3
bne.s ___drtr0126
adda.w #2,%a0
bra.s  ___ctr0126
___drtr0126:
btst #18,%d0
beq.s ___atr0126
or.w %d1,(%a0)+
bra.s ___ctr0126
___atr0126:
and.w %d2,(%a0)+
___ctr0126:
btst #17,%d3
bne.s ___drtr0127
adda.w #2,%a0
bra.s  ___ctr0127
___drtr0127:
btst #17,%d0
beq.s ___atr0127
or.w %d1,(%a0)+
bra.s ___ctr0127
___atr0127:
and.w %d2,(%a0)+
___ctr0127:
btst #16,%d3
bne.s ___drtr0128
adda.w #2,%a0
bra.s  ___ctr0128
___drtr0128:
btst #16,%d0
beq.s ___atr0128
or.w %d1,(%a0)+
bra.s ___ctr0128
___atr0128:
and.w %d2,(%a0)+
___ctr0128:
tst.w %d3
bmi.s ___drtr0129
adda.w #2,%a0
bra.s  ___ctr0129
___drtr0129:
tst.w %d0
bpl.s ___atr0129
or.w %d1,(%a0)+
bra.s ___ctr0129
___atr0129:
and.w %d2,(%a0)+
___ctr0129:
btst #14,%d3
bne.s ___drtr012a
adda.w #2,%a0
bra.s  ___ctr012a
___drtr012a:
btst #14,%d0
beq.s ___atr012a
or.w %d1,(%a0)+
bra.s ___ctr012a
___atr012a:
and.w %d2,(%a0)+
___ctr012a:
btst #13,%d3
bne.s ___drtr012b
adda.w #2,%a0
bra.s  ___ctr012b
___drtr012b:
btst #13,%d0
beq.s ___atr012b
or.w %d1,(%a0)+
bra.s ___ctr012b
___atr012b:
and.w %d2,(%a0)+
___ctr012b:
btst #12,%d3
bne.s ___drtr012c
adda.w #2,%a0
bra.s  ___ctr012c
___drtr012c:
btst #12,%d0
beq.s ___atr012c
or.w %d1,(%a0)+
bra.s ___ctr012c
___atr012c:
and.w %d2,(%a0)+
___ctr012c:
btst #11,%d3
bne.s ___drtr012d
adda.w #2,%a0
bra.s  ___ctr012d
___drtr012d:
btst #11,%d0
beq.s ___atr012d
or.w %d1,(%a0)+
bra.s ___ctr012d
___atr012d:
and.w %d2,(%a0)+
___ctr012d:
btst #10,%d3
bne.s ___drtr012e
adda.w #2,%a0
bra.s  ___ctr012e
___drtr012e:
btst #10,%d0
beq.s ___atr012e
or.w %d1,(%a0)+
bra.s ___ctr012e
___atr012e:
and.w %d2,(%a0)+
___ctr012e:
btst #9,%d3
bne.s ___drtr012f
adda.w #2,%a0
bra.s  ___ctr012f
___drtr012f:
btst #9,%d0
beq.s ___atr012f
or.w %d1,(%a0)+
bra.s ___ctr012f
___atr012f:
and.w %d2,(%a0)+
___ctr012f:
btst #8,%d3
bne.s ___drtr0130
adda.w #2,%a0
bra.s  ___ctr0130
___drtr0130:
btst #8,%d0
beq.s ___atr0130
or.w %d1,(%a0)+
bra.s ___ctr0130
___atr0130:
and.w %d2,(%a0)+
___ctr0130:
tst.b %d3
bmi.s ___drtr0131
adda.w #2,%a0
bra.s  ___ctr0131
___drtr0131:
tst.b %d0
bpl.s ___atr0131
or.w %d1,(%a0)+
bra.s ___ctr0131
___atr0131:
and.w %d2,(%a0)+
___ctr0131:
btst #6,%d3
bne.s ___drtr0132
adda.w #2,%a0
bra.s  ___ctr0132
___drtr0132:
btst #6,%d0
beq.s ___atr0132
or.w %d1,(%a0)+
bra.s ___ctr0132
___atr0132:
and.w %d2,(%a0)+
___ctr0132:
btst #5,%d3
bne.s ___drtr0133
adda.w #2,%a0
bra.s  ___ctr0133
___drtr0133:
btst #5,%d0
beq.s ___atr0133
or.w %d1,(%a0)+
bra.s ___ctr0133
___atr0133:
and.w %d2,(%a0)+
___ctr0133:
btst #4,%d3
bne.s ___drtr0134
adda.w #2,%a0
bra.s  ___ctr0134
___drtr0134:
btst #4,%d0
beq.s ___atr0134
or.w %d1,(%a0)+
bra.s ___ctr0134
___atr0134:
and.w %d2,(%a0)+
___ctr0134:
btst #3,%d3
bne.s ___drtr0135
adda.w #2,%a0
bra.s  ___ctr0135
___drtr0135:
btst #3,%d0
beq.s ___atr0135
or.w %d1,(%a0)+
bra.s ___ctr0135
___atr0135:
and.w %d2,(%a0)+
___ctr0135:
btst #2,%d3
bne.s ___drtr0136
adda.w #2,%a0
bra.s  ___ctr0136
___drtr0136:
btst #2,%d0
beq.s ___atr0136
or.w %d1,(%a0)+
bra.s ___ctr0136
___atr0136:
and.w %d2,(%a0)+
___ctr0136:
btst #1,%d3
bne.s ___drtr0137
rts
___drtr0137:
btst #1,%d0
beq.s ___atr0137
or.w %d1,(%a0)+
rts
___atr0137:
and.w %d2,(%a0)+
rts
__tr_scale066:
tst.l %d3
bmi.s ___drtr0138
adda.w #4,%a0
bra.s  ___ctr0138
___drtr0138:
tst.l %d0
bpl.s ___atr0138
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0138
___atr0138:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0138:
btst #30,%d3
bne.s ___drtr0139
adda.w #2,%a0
bra.s  ___ctr0139
___drtr0139:
btst #30,%d0
beq.s ___atr0139
or.w %d1,(%a0)+
bra.s ___ctr0139
___atr0139:
and.w %d2,(%a0)+
___ctr0139:
btst #29,%d3
bne.s ___drtr013a
adda.w #2,%a0
bra.s  ___ctr013a
___drtr013a:
btst #29,%d0
beq.s ___atr013a
or.w %d1,(%a0)+
bra.s ___ctr013a
___atr013a:
and.w %d2,(%a0)+
___ctr013a:
btst #28,%d3
bne.s ___drtr013b
adda.w #2,%a0
bra.s  ___ctr013b
___drtr013b:
btst #28,%d0
beq.s ___atr013b
or.w %d1,(%a0)+
bra.s ___ctr013b
___atr013b:
and.w %d2,(%a0)+
___ctr013b:
btst #27,%d3
bne.s ___drtr013c
adda.w #2,%a0
bra.s  ___ctr013c
___drtr013c:
btst #27,%d0
beq.s ___atr013c
or.w %d1,(%a0)+
bra.s ___ctr013c
___atr013c:
and.w %d2,(%a0)+
___ctr013c:
btst #26,%d3
bne.s ___drtr013d
adda.w #2,%a0
bra.s  ___ctr013d
___drtr013d:
btst #26,%d0
beq.s ___atr013d
or.w %d1,(%a0)+
bra.s ___ctr013d
___atr013d:
and.w %d2,(%a0)+
___ctr013d:
btst #25,%d3
bne.s ___drtr013e
adda.w #2,%a0
bra.s  ___ctr013e
___drtr013e:
btst #25,%d0
beq.s ___atr013e
or.w %d1,(%a0)+
bra.s ___ctr013e
___atr013e:
and.w %d2,(%a0)+
___ctr013e:
btst #24,%d3
bne.s ___drtr013f
adda.w #2,%a0
bra.s  ___ctr013f
___drtr013f:
btst #24,%d0
beq.s ___atr013f
or.w %d1,(%a0)+
bra.s ___ctr013f
___atr013f:
and.w %d2,(%a0)+
___ctr013f:
btst #23,%d3
bne.s ___drtr0140
adda.w #2,%a0
bra.s  ___ctr0140
___drtr0140:
btst #23,%d0
beq.s ___atr0140
or.w %d1,(%a0)+
bra.s ___ctr0140
___atr0140:
and.w %d2,(%a0)+
___ctr0140:
btst #22,%d3
bne.s ___drtr0141
adda.w #2,%a0
bra.s  ___ctr0141
___drtr0141:
btst #22,%d0
beq.s ___atr0141
or.w %d1,(%a0)+
bra.s ___ctr0141
___atr0141:
and.w %d2,(%a0)+
___ctr0141:
btst #21,%d3
bne.s ___drtr0142
adda.w #2,%a0
bra.s  ___ctr0142
___drtr0142:
btst #21,%d0
beq.s ___atr0142
or.w %d1,(%a0)+
bra.s ___ctr0142
___atr0142:
and.w %d2,(%a0)+
___ctr0142:
btst #20,%d3
bne.s ___drtr0143
adda.w #2,%a0
bra.s  ___ctr0143
___drtr0143:
btst #20,%d0
beq.s ___atr0143
or.w %d1,(%a0)+
bra.s ___ctr0143
___atr0143:
and.w %d2,(%a0)+
___ctr0143:
btst #19,%d3
bne.s ___drtr0144
adda.w #2,%a0
bra.s  ___ctr0144
___drtr0144:
btst #19,%d0
beq.s ___atr0144
or.w %d1,(%a0)+
bra.s ___ctr0144
___atr0144:
and.w %d2,(%a0)+
___ctr0144:
btst #18,%d3
bne.s ___drtr0145
adda.w #2,%a0
bra.s  ___ctr0145
___drtr0145:
btst #18,%d0
beq.s ___atr0145
or.w %d1,(%a0)+
bra.s ___ctr0145
___atr0145:
and.w %d2,(%a0)+
___ctr0145:
btst #17,%d3
bne.s ___drtr0146
adda.w #2,%a0
bra.s  ___ctr0146
___drtr0146:
btst #17,%d0
beq.s ___atr0146
or.w %d1,(%a0)+
bra.s ___ctr0146
___atr0146:
and.w %d2,(%a0)+
___ctr0146:
btst #16,%d3
bne.s ___drtr0147
adda.w #2,%a0
bra.s  ___ctr0147
___drtr0147:
btst #16,%d0
beq.s ___atr0147
or.w %d1,(%a0)+
bra.s ___ctr0147
___atr0147:
and.w %d2,(%a0)+
___ctr0147:
tst.w %d3
bmi.s ___drtr0148
adda.w #2,%a0
bra.s  ___ctr0148
___drtr0148:
tst.w %d0
bpl.s ___atr0148
or.w %d1,(%a0)+
bra.s ___ctr0148
___atr0148:
and.w %d2,(%a0)+
___ctr0148:
btst #14,%d3
bne.s ___drtr0149
adda.w #2,%a0
bra.s  ___ctr0149
___drtr0149:
btst #14,%d0
beq.s ___atr0149
or.w %d1,(%a0)+
bra.s ___ctr0149
___atr0149:
and.w %d2,(%a0)+
___ctr0149:
btst #13,%d3
bne.s ___drtr014a
adda.w #2,%a0
bra.s  ___ctr014a
___drtr014a:
btst #13,%d0
beq.s ___atr014a
or.w %d1,(%a0)+
bra.s ___ctr014a
___atr014a:
and.w %d2,(%a0)+
___ctr014a:
btst #12,%d3
bne.s ___drtr014b
adda.w #2,%a0
bra.s  ___ctr014b
___drtr014b:
btst #12,%d0
beq.s ___atr014b
or.w %d1,(%a0)+
bra.s ___ctr014b
___atr014b:
and.w %d2,(%a0)+
___ctr014b:
btst #11,%d3
bne.s ___drtr014c
adda.w #2,%a0
bra.s  ___ctr014c
___drtr014c:
btst #11,%d0
beq.s ___atr014c
or.w %d1,(%a0)+
bra.s ___ctr014c
___atr014c:
and.w %d2,(%a0)+
___ctr014c:
btst #10,%d3
bne.s ___drtr014d
adda.w #2,%a0
bra.s  ___ctr014d
___drtr014d:
btst #10,%d0
beq.s ___atr014d
or.w %d1,(%a0)+
bra.s ___ctr014d
___atr014d:
and.w %d2,(%a0)+
___ctr014d:
btst #9,%d3
bne.s ___drtr014e
adda.w #2,%a0
bra.s  ___ctr014e
___drtr014e:
btst #9,%d0
beq.s ___atr014e
or.w %d1,(%a0)+
bra.s ___ctr014e
___atr014e:
and.w %d2,(%a0)+
___ctr014e:
btst #8,%d3
bne.s ___drtr014f
adda.w #2,%a0
bra.s  ___ctr014f
___drtr014f:
btst #8,%d0
beq.s ___atr014f
or.w %d1,(%a0)+
bra.s ___ctr014f
___atr014f:
and.w %d2,(%a0)+
___ctr014f:
tst.b %d3
bmi.s ___drtr0150
adda.w #2,%a0
bra.s  ___ctr0150
___drtr0150:
tst.b %d0
bpl.s ___atr0150
or.w %d1,(%a0)+
bra.s ___ctr0150
___atr0150:
and.w %d2,(%a0)+
___ctr0150:
btst #6,%d3
bne.s ___drtr0151
adda.w #2,%a0
bra.s  ___ctr0151
___drtr0151:
btst #6,%d0
beq.s ___atr0151
or.w %d1,(%a0)+
bra.s ___ctr0151
___atr0151:
and.w %d2,(%a0)+
___ctr0151:
btst #5,%d3
bne.s ___drtr0152
adda.w #2,%a0
bra.s  ___ctr0152
___drtr0152:
btst #5,%d0
beq.s ___atr0152
or.w %d1,(%a0)+
bra.s ___ctr0152
___atr0152:
and.w %d2,(%a0)+
___ctr0152:
btst #4,%d3
bne.s ___drtr0153
adda.w #2,%a0
bra.s  ___ctr0153
___drtr0153:
btst #4,%d0
beq.s ___atr0153
or.w %d1,(%a0)+
bra.s ___ctr0153
___atr0153:
and.w %d2,(%a0)+
___ctr0153:
btst #3,%d3
bne.s ___drtr0154
adda.w #2,%a0
bra.s  ___ctr0154
___drtr0154:
btst #3,%d0
beq.s ___atr0154
or.w %d1,(%a0)+
bra.s ___ctr0154
___atr0154:
and.w %d2,(%a0)+
___ctr0154:
btst #2,%d3
bne.s ___drtr0155
adda.w #2,%a0
bra.s  ___ctr0155
___drtr0155:
btst #2,%d0
beq.s ___atr0155
or.w %d1,(%a0)+
bra.s ___ctr0155
___atr0155:
and.w %d2,(%a0)+
___ctr0155:
btst #1,%d3
bne.s ___drtr0156
adda.w #2,%a0
bra.s  ___ctr0156
___drtr0156:
btst #1,%d0
beq.s ___atr0156
or.w %d1,(%a0)+
bra.s ___ctr0156
___atr0156:
and.w %d2,(%a0)+
___ctr0156:
btst #0,%d3
bne.s ___drtr0157
rts
___drtr0157:
btst #0,%d0
beq.s ___atr0157
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr0157:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale070:
tst.l %d3
bmi.s ___drtr0158
adda.w #4,%a0
bra.s  ___ctr0158
___drtr0158:
tst.l %d0
bpl.s ___atr0158
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0158
___atr0158:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0158:
btst #30,%d3
bne.s ___drtr0159
adda.w #2,%a0
bra.s  ___ctr0159
___drtr0159:
btst #30,%d0
beq.s ___atr0159
or.w %d1,(%a0)+
bra.s ___ctr0159
___atr0159:
and.w %d2,(%a0)+
___ctr0159:
btst #29,%d3
bne.s ___drtr015a
adda.w #2,%a0
bra.s  ___ctr015a
___drtr015a:
btst #29,%d0
beq.s ___atr015a
or.w %d1,(%a0)+
bra.s ___ctr015a
___atr015a:
and.w %d2,(%a0)+
___ctr015a:
btst #28,%d3
bne.s ___drtr015b
adda.w #2,%a0
bra.s  ___ctr015b
___drtr015b:
btst #28,%d0
beq.s ___atr015b
or.w %d1,(%a0)+
bra.s ___ctr015b
___atr015b:
and.w %d2,(%a0)+
___ctr015b:
btst #27,%d3
bne.s ___drtr015c
adda.w #2,%a0
bra.s  ___ctr015c
___drtr015c:
btst #27,%d0
beq.s ___atr015c
or.w %d1,(%a0)+
bra.s ___ctr015c
___atr015c:
and.w %d2,(%a0)+
___ctr015c:
btst #26,%d3
bne.s ___drtr015d
adda.w #2,%a0
bra.s  ___ctr015d
___drtr015d:
btst #26,%d0
beq.s ___atr015d
or.w %d1,(%a0)+
bra.s ___ctr015d
___atr015d:
and.w %d2,(%a0)+
___ctr015d:
btst #25,%d3
bne.s ___drtr015e
adda.w #2,%a0
bra.s  ___ctr015e
___drtr015e:
btst #25,%d0
beq.s ___atr015e
or.w %d1,(%a0)+
bra.s ___ctr015e
___atr015e:
and.w %d2,(%a0)+
___ctr015e:
btst #24,%d3
bne.s ___drtr015f
adda.w #2,%a0
bra.s  ___ctr015f
___drtr015f:
btst #24,%d0
beq.s ___atr015f
or.w %d1,(%a0)+
bra.s ___ctr015f
___atr015f:
and.w %d2,(%a0)+
___ctr015f:
btst #23,%d3
bne.s ___drtr0160
adda.w #2,%a0
bra.s  ___ctr0160
___drtr0160:
btst #23,%d0
beq.s ___atr0160
or.w %d1,(%a0)+
bra.s ___ctr0160
___atr0160:
and.w %d2,(%a0)+
___ctr0160:
btst #22,%d3
bne.s ___drtr0161
adda.w #2,%a0
bra.s  ___ctr0161
___drtr0161:
btst #22,%d0
beq.s ___atr0161
or.w %d1,(%a0)+
bra.s ___ctr0161
___atr0161:
and.w %d2,(%a0)+
___ctr0161:
btst #21,%d3
bne.s ___drtr0162
adda.w #4,%a0
bra.s  ___ctr0162
___drtr0162:
btst #21,%d0
beq.s ___atr0162
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0162
___atr0162:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0162:
btst #20,%d3
bne.s ___drtr0163
adda.w #2,%a0
bra.s  ___ctr0163
___drtr0163:
btst #20,%d0
beq.s ___atr0163
or.w %d1,(%a0)+
bra.s ___ctr0163
___atr0163:
and.w %d2,(%a0)+
___ctr0163:
btst #19,%d3
bne.s ___drtr0164
adda.w #2,%a0
bra.s  ___ctr0164
___drtr0164:
btst #19,%d0
beq.s ___atr0164
or.w %d1,(%a0)+
bra.s ___ctr0164
___atr0164:
and.w %d2,(%a0)+
___ctr0164:
btst #18,%d3
bne.s ___drtr0165
adda.w #2,%a0
bra.s  ___ctr0165
___drtr0165:
btst #18,%d0
beq.s ___atr0165
or.w %d1,(%a0)+
bra.s ___ctr0165
___atr0165:
and.w %d2,(%a0)+
___ctr0165:
btst #17,%d3
bne.s ___drtr0166
adda.w #2,%a0
bra.s  ___ctr0166
___drtr0166:
btst #17,%d0
beq.s ___atr0166
or.w %d1,(%a0)+
bra.s ___ctr0166
___atr0166:
and.w %d2,(%a0)+
___ctr0166:
btst #16,%d3
bne.s ___drtr0167
adda.w #2,%a0
bra.s  ___ctr0167
___drtr0167:
btst #16,%d0
beq.s ___atr0167
or.w %d1,(%a0)+
bra.s ___ctr0167
___atr0167:
and.w %d2,(%a0)+
___ctr0167:
tst.w %d3
bmi.s ___drtr0168
adda.w #2,%a0
bra.s  ___ctr0168
___drtr0168:
tst.w %d0
bpl.s ___atr0168
or.w %d1,(%a0)+
bra.s ___ctr0168
___atr0168:
and.w %d2,(%a0)+
___ctr0168:
btst #14,%d3
bne.s ___drtr0169
adda.w #2,%a0
bra.s  ___ctr0169
___drtr0169:
btst #14,%d0
beq.s ___atr0169
or.w %d1,(%a0)+
bra.s ___ctr0169
___atr0169:
and.w %d2,(%a0)+
___ctr0169:
btst #13,%d3
bne.s ___drtr016a
adda.w #2,%a0
bra.s  ___ctr016a
___drtr016a:
btst #13,%d0
beq.s ___atr016a
or.w %d1,(%a0)+
bra.s ___ctr016a
___atr016a:
and.w %d2,(%a0)+
___ctr016a:
btst #12,%d3
bne.s ___drtr016b
adda.w #2,%a0
bra.s  ___ctr016b
___drtr016b:
btst #12,%d0
beq.s ___atr016b
or.w %d1,(%a0)+
bra.s ___ctr016b
___atr016b:
and.w %d2,(%a0)+
___ctr016b:
btst #11,%d3
bne.s ___drtr016c
adda.w #2,%a0
bra.s  ___ctr016c
___drtr016c:
btst #11,%d0
beq.s ___atr016c
or.w %d1,(%a0)+
bra.s ___ctr016c
___atr016c:
and.w %d2,(%a0)+
___ctr016c:
btst #10,%d3
bne.s ___drtr016d
adda.w #4,%a0
bra.s  ___ctr016d
___drtr016d:
btst #10,%d0
beq.s ___atr016d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr016d
___atr016d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr016d:
btst #9,%d3
bne.s ___drtr016e
adda.w #2,%a0
bra.s  ___ctr016e
___drtr016e:
btst #9,%d0
beq.s ___atr016e
or.w %d1,(%a0)+
bra.s ___ctr016e
___atr016e:
and.w %d2,(%a0)+
___ctr016e:
btst #8,%d3
bne.s ___drtr016f
adda.w #2,%a0
bra.s  ___ctr016f
___drtr016f:
btst #8,%d0
beq.s ___atr016f
or.w %d1,(%a0)+
bra.s ___ctr016f
___atr016f:
and.w %d2,(%a0)+
___ctr016f:
tst.b %d3
bmi.s ___drtr0170
adda.w #2,%a0
bra.s  ___ctr0170
___drtr0170:
tst.b %d0
bpl.s ___atr0170
or.w %d1,(%a0)+
bra.s ___ctr0170
___atr0170:
and.w %d2,(%a0)+
___ctr0170:
btst #6,%d3
bne.s ___drtr0171
adda.w #2,%a0
bra.s  ___ctr0171
___drtr0171:
btst #6,%d0
beq.s ___atr0171
or.w %d1,(%a0)+
bra.s ___ctr0171
___atr0171:
and.w %d2,(%a0)+
___ctr0171:
btst #5,%d3
bne.s ___drtr0172
adda.w #2,%a0
bra.s  ___ctr0172
___drtr0172:
btst #5,%d0
beq.s ___atr0172
or.w %d1,(%a0)+
bra.s ___ctr0172
___atr0172:
and.w %d2,(%a0)+
___ctr0172:
btst #4,%d3
bne.s ___drtr0173
adda.w #2,%a0
bra.s  ___ctr0173
___drtr0173:
btst #4,%d0
beq.s ___atr0173
or.w %d1,(%a0)+
bra.s ___ctr0173
___atr0173:
and.w %d2,(%a0)+
___ctr0173:
btst #3,%d3
bne.s ___drtr0174
adda.w #2,%a0
bra.s  ___ctr0174
___drtr0174:
btst #3,%d0
beq.s ___atr0174
or.w %d1,(%a0)+
bra.s ___ctr0174
___atr0174:
and.w %d2,(%a0)+
___ctr0174:
btst #2,%d3
bne.s ___drtr0175
adda.w #2,%a0
bra.s  ___ctr0175
___drtr0175:
btst #2,%d0
beq.s ___atr0175
or.w %d1,(%a0)+
bra.s ___ctr0175
___atr0175:
and.w %d2,(%a0)+
___ctr0175:
btst #1,%d3
bne.s ___drtr0176
adda.w #2,%a0
bra.s  ___ctr0176
___drtr0176:
btst #1,%d0
beq.s ___atr0176
or.w %d1,(%a0)+
bra.s ___ctr0176
___atr0176:
and.w %d2,(%a0)+
___ctr0176:
btst #0,%d3
bne.s ___drtr0177
rts
___drtr0177:
btst #0,%d0
beq.s ___atr0177
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr0177:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale074:
tst.l %d3
bmi.s ___drtr0178
adda.w #4,%a0
bra.s  ___ctr0178
___drtr0178:
tst.l %d0
bpl.s ___atr0178
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0178
___atr0178:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0178:
btst #30,%d3
bne.s ___drtr0179
adda.w #2,%a0
bra.s  ___ctr0179
___drtr0179:
btst #30,%d0
beq.s ___atr0179
or.w %d1,(%a0)+
bra.s ___ctr0179
___atr0179:
and.w %d2,(%a0)+
___ctr0179:
btst #29,%d3
bne.s ___drtr017a
adda.w #2,%a0
bra.s  ___ctr017a
___drtr017a:
btst #29,%d0
beq.s ___atr017a
or.w %d1,(%a0)+
bra.s ___ctr017a
___atr017a:
and.w %d2,(%a0)+
___ctr017a:
btst #28,%d3
bne.s ___drtr017b
adda.w #2,%a0
bra.s  ___ctr017b
___drtr017b:
btst #28,%d0
beq.s ___atr017b
or.w %d1,(%a0)+
bra.s ___ctr017b
___atr017b:
and.w %d2,(%a0)+
___ctr017b:
btst #27,%d3
bne.s ___drtr017c
adda.w #2,%a0
bra.s  ___ctr017c
___drtr017c:
btst #27,%d0
beq.s ___atr017c
or.w %d1,(%a0)+
bra.s ___ctr017c
___atr017c:
and.w %d2,(%a0)+
___ctr017c:
btst #26,%d3
bne.s ___drtr017d
adda.w #2,%a0
bra.s  ___ctr017d
___drtr017d:
btst #26,%d0
beq.s ___atr017d
or.w %d1,(%a0)+
bra.s ___ctr017d
___atr017d:
and.w %d2,(%a0)+
___ctr017d:
btst #25,%d3
bne.s ___drtr017e
adda.w #4,%a0
bra.s  ___ctr017e
___drtr017e:
btst #25,%d0
beq.s ___atr017e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr017e
___atr017e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr017e:
btst #24,%d3
bne.s ___drtr017f
adda.w #2,%a0
bra.s  ___ctr017f
___drtr017f:
btst #24,%d0
beq.s ___atr017f
or.w %d1,(%a0)+
bra.s ___ctr017f
___atr017f:
and.w %d2,(%a0)+
___ctr017f:
btst #23,%d3
bne.s ___drtr0180
adda.w #2,%a0
bra.s  ___ctr0180
___drtr0180:
btst #23,%d0
beq.s ___atr0180
or.w %d1,(%a0)+
bra.s ___ctr0180
___atr0180:
and.w %d2,(%a0)+
___ctr0180:
btst #22,%d3
bne.s ___drtr0181
adda.w #2,%a0
bra.s  ___ctr0181
___drtr0181:
btst #22,%d0
beq.s ___atr0181
or.w %d1,(%a0)+
bra.s ___ctr0181
___atr0181:
and.w %d2,(%a0)+
___ctr0181:
btst #21,%d3
bne.s ___drtr0182
adda.w #2,%a0
bra.s  ___ctr0182
___drtr0182:
btst #21,%d0
beq.s ___atr0182
or.w %d1,(%a0)+
bra.s ___ctr0182
___atr0182:
and.w %d2,(%a0)+
___ctr0182:
btst #20,%d3
bne.s ___drtr0183
adda.w #2,%a0
bra.s  ___ctr0183
___drtr0183:
btst #20,%d0
beq.s ___atr0183
or.w %d1,(%a0)+
bra.s ___ctr0183
___atr0183:
and.w %d2,(%a0)+
___ctr0183:
btst #19,%d3
bne.s ___drtr0184
adda.w #4,%a0
bra.s  ___ctr0184
___drtr0184:
btst #19,%d0
beq.s ___atr0184
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0184
___atr0184:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0184:
btst #18,%d3
bne.s ___drtr0185
adda.w #2,%a0
bra.s  ___ctr0185
___drtr0185:
btst #18,%d0
beq.s ___atr0185
or.w %d1,(%a0)+
bra.s ___ctr0185
___atr0185:
and.w %d2,(%a0)+
___ctr0185:
btst #17,%d3
bne.s ___drtr0186
adda.w #2,%a0
bra.s  ___ctr0186
___drtr0186:
btst #17,%d0
beq.s ___atr0186
or.w %d1,(%a0)+
bra.s ___ctr0186
___atr0186:
and.w %d2,(%a0)+
___ctr0186:
btst #16,%d3
bne.s ___drtr0187
adda.w #2,%a0
bra.s  ___ctr0187
___drtr0187:
btst #16,%d0
beq.s ___atr0187
or.w %d1,(%a0)+
bra.s ___ctr0187
___atr0187:
and.w %d2,(%a0)+
___ctr0187:
tst.w %d3
bmi.s ___drtr0188
adda.w #2,%a0
bra.s  ___ctr0188
___drtr0188:
tst.w %d0
bpl.s ___atr0188
or.w %d1,(%a0)+
bra.s ___ctr0188
___atr0188:
and.w %d2,(%a0)+
___ctr0188:
btst #14,%d3
bne.s ___drtr0189
adda.w #2,%a0
bra.s  ___ctr0189
___drtr0189:
btst #14,%d0
beq.s ___atr0189
or.w %d1,(%a0)+
bra.s ___ctr0189
___atr0189:
and.w %d2,(%a0)+
___ctr0189:
btst #13,%d3
bne.s ___drtr018a
adda.w #4,%a0
bra.s  ___ctr018a
___drtr018a:
btst #13,%d0
beq.s ___atr018a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr018a
___atr018a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr018a:
btst #12,%d3
bne.s ___drtr018b
adda.w #2,%a0
bra.s  ___ctr018b
___drtr018b:
btst #12,%d0
beq.s ___atr018b
or.w %d1,(%a0)+
bra.s ___ctr018b
___atr018b:
and.w %d2,(%a0)+
___ctr018b:
btst #11,%d3
bne.s ___drtr018c
adda.w #2,%a0
bra.s  ___ctr018c
___drtr018c:
btst #11,%d0
beq.s ___atr018c
or.w %d1,(%a0)+
bra.s ___ctr018c
___atr018c:
and.w %d2,(%a0)+
___ctr018c:
btst #10,%d3
bne.s ___drtr018d
adda.w #2,%a0
bra.s  ___ctr018d
___drtr018d:
btst #10,%d0
beq.s ___atr018d
or.w %d1,(%a0)+
bra.s ___ctr018d
___atr018d:
and.w %d2,(%a0)+
___ctr018d:
btst #9,%d3
bne.s ___drtr018e
adda.w #2,%a0
bra.s  ___ctr018e
___drtr018e:
btst #9,%d0
beq.s ___atr018e
or.w %d1,(%a0)+
bra.s ___ctr018e
___atr018e:
and.w %d2,(%a0)+
___ctr018e:
btst #8,%d3
bne.s ___drtr018f
adda.w #2,%a0
bra.s  ___ctr018f
___drtr018f:
btst #8,%d0
beq.s ___atr018f
or.w %d1,(%a0)+
bra.s ___ctr018f
___atr018f:
and.w %d2,(%a0)+
___ctr018f:
tst.b %d3
bmi.s ___drtr0190
adda.w #2,%a0
bra.s  ___ctr0190
___drtr0190:
tst.b %d0
bpl.s ___atr0190
or.w %d1,(%a0)+
bra.s ___ctr0190
___atr0190:
and.w %d2,(%a0)+
___ctr0190:
btst #6,%d3
bne.s ___drtr0191
adda.w #4,%a0
bra.s  ___ctr0191
___drtr0191:
btst #6,%d0
beq.s ___atr0191
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0191
___atr0191:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0191:
btst #5,%d3
bne.s ___drtr0192
adda.w #2,%a0
bra.s  ___ctr0192
___drtr0192:
btst #5,%d0
beq.s ___atr0192
or.w %d1,(%a0)+
bra.s ___ctr0192
___atr0192:
and.w %d2,(%a0)+
___ctr0192:
btst #4,%d3
bne.s ___drtr0193
adda.w #2,%a0
bra.s  ___ctr0193
___drtr0193:
btst #4,%d0
beq.s ___atr0193
or.w %d1,(%a0)+
bra.s ___ctr0193
___atr0193:
and.w %d2,(%a0)+
___ctr0193:
btst #3,%d3
bne.s ___drtr0194
adda.w #2,%a0
bra.s  ___ctr0194
___drtr0194:
btst #3,%d0
beq.s ___atr0194
or.w %d1,(%a0)+
bra.s ___ctr0194
___atr0194:
and.w %d2,(%a0)+
___ctr0194:
btst #2,%d3
bne.s ___drtr0195
adda.w #2,%a0
bra.s  ___ctr0195
___drtr0195:
btst #2,%d0
beq.s ___atr0195
or.w %d1,(%a0)+
bra.s ___ctr0195
___atr0195:
and.w %d2,(%a0)+
___ctr0195:
btst #1,%d3
bne.s ___drtr0196
adda.w #2,%a0
bra.s  ___ctr0196
___drtr0196:
btst #1,%d0
beq.s ___atr0196
or.w %d1,(%a0)+
bra.s ___ctr0196
___atr0196:
and.w %d2,(%a0)+
___ctr0196:
btst #0,%d3
bne.s ___drtr0197
rts
___drtr0197:
btst #0,%d0
beq.s ___atr0197
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr0197:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale078:
tst.l %d3
bmi.s ___drtr0198
adda.w #4,%a0
bra.s  ___ctr0198
___drtr0198:
tst.l %d0
bpl.s ___atr0198
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0198
___atr0198:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0198:
btst #30,%d3
bne.s ___drtr0199
adda.w #2,%a0
bra.s  ___ctr0199
___drtr0199:
btst #30,%d0
beq.s ___atr0199
or.w %d1,(%a0)+
bra.s ___ctr0199
___atr0199:
and.w %d2,(%a0)+
___ctr0199:
btst #29,%d3
bne.s ___drtr019a
adda.w #2,%a0
bra.s  ___ctr019a
___drtr019a:
btst #29,%d0
beq.s ___atr019a
or.w %d1,(%a0)+
bra.s ___ctr019a
___atr019a:
and.w %d2,(%a0)+
___ctr019a:
btst #28,%d3
bne.s ___drtr019b
adda.w #2,%a0
bra.s  ___ctr019b
___drtr019b:
btst #28,%d0
beq.s ___atr019b
or.w %d1,(%a0)+
bra.s ___ctr019b
___atr019b:
and.w %d2,(%a0)+
___ctr019b:
btst #27,%d3
bne.s ___drtr019c
adda.w #4,%a0
bra.s  ___ctr019c
___drtr019c:
btst #27,%d0
beq.s ___atr019c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr019c
___atr019c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr019c:
btst #26,%d3
bne.s ___drtr019d
adda.w #2,%a0
bra.s  ___ctr019d
___drtr019d:
btst #26,%d0
beq.s ___atr019d
or.w %d1,(%a0)+
bra.s ___ctr019d
___atr019d:
and.w %d2,(%a0)+
___ctr019d:
btst #25,%d3
bne.s ___drtr019e
adda.w #2,%a0
bra.s  ___ctr019e
___drtr019e:
btst #25,%d0
beq.s ___atr019e
or.w %d1,(%a0)+
bra.s ___ctr019e
___atr019e:
and.w %d2,(%a0)+
___ctr019e:
btst #24,%d3
bne.s ___drtr019f
adda.w #2,%a0
bra.s  ___ctr019f
___drtr019f:
btst #24,%d0
beq.s ___atr019f
or.w %d1,(%a0)+
bra.s ___ctr019f
___atr019f:
and.w %d2,(%a0)+
___ctr019f:
btst #23,%d3
bne.s ___drtr01a0
adda.w #2,%a0
bra.s  ___ctr01a0
___drtr01a0:
btst #23,%d0
beq.s ___atr01a0
or.w %d1,(%a0)+
bra.s ___ctr01a0
___atr01a0:
and.w %d2,(%a0)+
___ctr01a0:
btst #22,%d3
bne.s ___drtr01a1
adda.w #4,%a0
bra.s  ___ctr01a1
___drtr01a1:
btst #22,%d0
beq.s ___atr01a1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01a1
___atr01a1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01a1:
btst #21,%d3
bne.s ___drtr01a2
adda.w #2,%a0
bra.s  ___ctr01a2
___drtr01a2:
btst #21,%d0
beq.s ___atr01a2
or.w %d1,(%a0)+
bra.s ___ctr01a2
___atr01a2:
and.w %d2,(%a0)+
___ctr01a2:
btst #20,%d3
bne.s ___drtr01a3
adda.w #2,%a0
bra.s  ___ctr01a3
___drtr01a3:
btst #20,%d0
beq.s ___atr01a3
or.w %d1,(%a0)+
bra.s ___ctr01a3
___atr01a3:
and.w %d2,(%a0)+
___ctr01a3:
btst #19,%d3
bne.s ___drtr01a4
adda.w #2,%a0
bra.s  ___ctr01a4
___drtr01a4:
btst #19,%d0
beq.s ___atr01a4
or.w %d1,(%a0)+
bra.s ___ctr01a4
___atr01a4:
and.w %d2,(%a0)+
___ctr01a4:
btst #18,%d3
bne.s ___drtr01a5
adda.w #4,%a0
bra.s  ___ctr01a5
___drtr01a5:
btst #18,%d0
beq.s ___atr01a5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01a5
___atr01a5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01a5:
btst #17,%d3
bne.s ___drtr01a6
adda.w #2,%a0
bra.s  ___ctr01a6
___drtr01a6:
btst #17,%d0
beq.s ___atr01a6
or.w %d1,(%a0)+
bra.s ___ctr01a6
___atr01a6:
and.w %d2,(%a0)+
___ctr01a6:
btst #16,%d3
bne.s ___drtr01a7
adda.w #2,%a0
bra.s  ___ctr01a7
___drtr01a7:
btst #16,%d0
beq.s ___atr01a7
or.w %d1,(%a0)+
bra.s ___ctr01a7
___atr01a7:
and.w %d2,(%a0)+
___ctr01a7:
tst.w %d3
bmi.s ___drtr01a8
adda.w #2,%a0
bra.s  ___ctr01a8
___drtr01a8:
tst.w %d0
bpl.s ___atr01a8
or.w %d1,(%a0)+
bra.s ___ctr01a8
___atr01a8:
and.w %d2,(%a0)+
___ctr01a8:
btst #14,%d3
bne.s ___drtr01a9
adda.w #4,%a0
bra.s  ___ctr01a9
___drtr01a9:
btst #14,%d0
beq.s ___atr01a9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01a9
___atr01a9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01a9:
btst #13,%d3
bne.s ___drtr01aa
adda.w #2,%a0
bra.s  ___ctr01aa
___drtr01aa:
btst #13,%d0
beq.s ___atr01aa
or.w %d1,(%a0)+
bra.s ___ctr01aa
___atr01aa:
and.w %d2,(%a0)+
___ctr01aa:
btst #12,%d3
bne.s ___drtr01ab
adda.w #2,%a0
bra.s  ___ctr01ab
___drtr01ab:
btst #12,%d0
beq.s ___atr01ab
or.w %d1,(%a0)+
bra.s ___ctr01ab
___atr01ab:
and.w %d2,(%a0)+
___ctr01ab:
btst #11,%d3
bne.s ___drtr01ac
adda.w #2,%a0
bra.s  ___ctr01ac
___drtr01ac:
btst #11,%d0
beq.s ___atr01ac
or.w %d1,(%a0)+
bra.s ___ctr01ac
___atr01ac:
and.w %d2,(%a0)+
___ctr01ac:
btst #10,%d3
bne.s ___drtr01ad
adda.w #2,%a0
bra.s  ___ctr01ad
___drtr01ad:
btst #10,%d0
beq.s ___atr01ad
or.w %d1,(%a0)+
bra.s ___ctr01ad
___atr01ad:
and.w %d2,(%a0)+
___ctr01ad:
btst #9,%d3
bne.s ___drtr01ae
adda.w #4,%a0
bra.s  ___ctr01ae
___drtr01ae:
btst #9,%d0
beq.s ___atr01ae
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01ae
___atr01ae:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01ae:
btst #8,%d3
bne.s ___drtr01af
adda.w #2,%a0
bra.s  ___ctr01af
___drtr01af:
btst #8,%d0
beq.s ___atr01af
or.w %d1,(%a0)+
bra.s ___ctr01af
___atr01af:
and.w %d2,(%a0)+
___ctr01af:
tst.b %d3
bmi.s ___drtr01b0
adda.w #2,%a0
bra.s  ___ctr01b0
___drtr01b0:
tst.b %d0
bpl.s ___atr01b0
or.w %d1,(%a0)+
bra.s ___ctr01b0
___atr01b0:
and.w %d2,(%a0)+
___ctr01b0:
btst #6,%d3
bne.s ___drtr01b1
adda.w #2,%a0
bra.s  ___ctr01b1
___drtr01b1:
btst #6,%d0
beq.s ___atr01b1
or.w %d1,(%a0)+
bra.s ___ctr01b1
___atr01b1:
and.w %d2,(%a0)+
___ctr01b1:
btst #5,%d3
bne.s ___drtr01b2
adda.w #4,%a0
bra.s  ___ctr01b2
___drtr01b2:
btst #5,%d0
beq.s ___atr01b2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01b2
___atr01b2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01b2:
btst #4,%d3
bne.s ___drtr01b3
adda.w #2,%a0
bra.s  ___ctr01b3
___drtr01b3:
btst #4,%d0
beq.s ___atr01b3
or.w %d1,(%a0)+
bra.s ___ctr01b3
___atr01b3:
and.w %d2,(%a0)+
___ctr01b3:
btst #3,%d3
bne.s ___drtr01b4
adda.w #2,%a0
bra.s  ___ctr01b4
___drtr01b4:
btst #3,%d0
beq.s ___atr01b4
or.w %d1,(%a0)+
bra.s ___ctr01b4
___atr01b4:
and.w %d2,(%a0)+
___ctr01b4:
btst #2,%d3
bne.s ___drtr01b5
adda.w #2,%a0
bra.s  ___ctr01b5
___drtr01b5:
btst #2,%d0
beq.s ___atr01b5
or.w %d1,(%a0)+
bra.s ___ctr01b5
___atr01b5:
and.w %d2,(%a0)+
___ctr01b5:
btst #1,%d3
bne.s ___drtr01b6
adda.w #2,%a0
bra.s  ___ctr01b6
___drtr01b6:
btst #1,%d0
beq.s ___atr01b6
or.w %d1,(%a0)+
bra.s ___ctr01b6
___atr01b6:
and.w %d2,(%a0)+
___ctr01b6:
btst #0,%d3
bne.s ___drtr01b7
rts
___drtr01b7:
btst #0,%d0
beq.s ___atr01b7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr01b7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale082:
tst.l %d3
bmi.s ___drtr01b8
adda.w #4,%a0
bra.s  ___ctr01b8
___drtr01b8:
tst.l %d0
bpl.s ___atr01b8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01b8
___atr01b8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01b8:
btst #30,%d3
bne.s ___drtr01b9
adda.w #2,%a0
bra.s  ___ctr01b9
___drtr01b9:
btst #30,%d0
beq.s ___atr01b9
or.w %d1,(%a0)+
bra.s ___ctr01b9
___atr01b9:
and.w %d2,(%a0)+
___ctr01b9:
btst #29,%d3
bne.s ___drtr01ba
adda.w #2,%a0
bra.s  ___ctr01ba
___drtr01ba:
btst #29,%d0
beq.s ___atr01ba
or.w %d1,(%a0)+
bra.s ___ctr01ba
___atr01ba:
and.w %d2,(%a0)+
___ctr01ba:
btst #28,%d3
bne.s ___drtr01bb
adda.w #4,%a0
bra.s  ___ctr01bb
___drtr01bb:
btst #28,%d0
beq.s ___atr01bb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01bb
___atr01bb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01bb:
btst #27,%d3
bne.s ___drtr01bc
adda.w #2,%a0
bra.s  ___ctr01bc
___drtr01bc:
btst #27,%d0
beq.s ___atr01bc
or.w %d1,(%a0)+
bra.s ___ctr01bc
___atr01bc:
and.w %d2,(%a0)+
___ctr01bc:
btst #26,%d3
bne.s ___drtr01bd
adda.w #2,%a0
bra.s  ___ctr01bd
___drtr01bd:
btst #26,%d0
beq.s ___atr01bd
or.w %d1,(%a0)+
bra.s ___ctr01bd
___atr01bd:
and.w %d2,(%a0)+
___ctr01bd:
btst #25,%d3
bne.s ___drtr01be
adda.w #2,%a0
bra.s  ___ctr01be
___drtr01be:
btst #25,%d0
beq.s ___atr01be
or.w %d1,(%a0)+
bra.s ___ctr01be
___atr01be:
and.w %d2,(%a0)+
___ctr01be:
btst #24,%d3
bne.s ___drtr01bf
adda.w #4,%a0
bra.s  ___ctr01bf
___drtr01bf:
btst #24,%d0
beq.s ___atr01bf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01bf
___atr01bf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01bf:
btst #23,%d3
bne.s ___drtr01c0
adda.w #2,%a0
bra.s  ___ctr01c0
___drtr01c0:
btst #23,%d0
beq.s ___atr01c0
or.w %d1,(%a0)+
bra.s ___ctr01c0
___atr01c0:
and.w %d2,(%a0)+
___ctr01c0:
btst #22,%d3
bne.s ___drtr01c1
adda.w #2,%a0
bra.s  ___ctr01c1
___drtr01c1:
btst #22,%d0
beq.s ___atr01c1
or.w %d1,(%a0)+
bra.s ___ctr01c1
___atr01c1:
and.w %d2,(%a0)+
___ctr01c1:
btst #21,%d3
bne.s ___drtr01c2
adda.w #4,%a0
bra.s  ___ctr01c2
___drtr01c2:
btst #21,%d0
beq.s ___atr01c2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01c2
___atr01c2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01c2:
btst #20,%d3
bne.s ___drtr01c3
adda.w #2,%a0
bra.s  ___ctr01c3
___drtr01c3:
btst #20,%d0
beq.s ___atr01c3
or.w %d1,(%a0)+
bra.s ___ctr01c3
___atr01c3:
and.w %d2,(%a0)+
___ctr01c3:
btst #19,%d3
bne.s ___drtr01c4
adda.w #2,%a0
bra.s  ___ctr01c4
___drtr01c4:
btst #19,%d0
beq.s ___atr01c4
or.w %d1,(%a0)+
bra.s ___ctr01c4
___atr01c4:
and.w %d2,(%a0)+
___ctr01c4:
btst #18,%d3
bne.s ___drtr01c5
adda.w #2,%a0
bra.s  ___ctr01c5
___drtr01c5:
btst #18,%d0
beq.s ___atr01c5
or.w %d1,(%a0)+
bra.s ___ctr01c5
___atr01c5:
and.w %d2,(%a0)+
___ctr01c5:
btst #17,%d3
bne.s ___drtr01c6
adda.w #4,%a0
bra.s  ___ctr01c6
___drtr01c6:
btst #17,%d0
beq.s ___atr01c6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01c6
___atr01c6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01c6:
btst #16,%d3
bne.s ___drtr01c7
adda.w #2,%a0
bra.s  ___ctr01c7
___drtr01c7:
btst #16,%d0
beq.s ___atr01c7
or.w %d1,(%a0)+
bra.s ___ctr01c7
___atr01c7:
and.w %d2,(%a0)+
___ctr01c7:
tst.w %d3
bmi.s ___drtr01c8
adda.w #2,%a0
bra.s  ___ctr01c8
___drtr01c8:
tst.w %d0
bpl.s ___atr01c8
or.w %d1,(%a0)+
bra.s ___ctr01c8
___atr01c8:
and.w %d2,(%a0)+
___ctr01c8:
btst #14,%d3
bne.s ___drtr01c9
adda.w #4,%a0
bra.s  ___ctr01c9
___drtr01c9:
btst #14,%d0
beq.s ___atr01c9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01c9
___atr01c9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01c9:
btst #13,%d3
bne.s ___drtr01ca
adda.w #2,%a0
bra.s  ___ctr01ca
___drtr01ca:
btst #13,%d0
beq.s ___atr01ca
or.w %d1,(%a0)+
bra.s ___ctr01ca
___atr01ca:
and.w %d2,(%a0)+
___ctr01ca:
btst #12,%d3
bne.s ___drtr01cb
adda.w #2,%a0
bra.s  ___ctr01cb
___drtr01cb:
btst #12,%d0
beq.s ___atr01cb
or.w %d1,(%a0)+
bra.s ___ctr01cb
___atr01cb:
and.w %d2,(%a0)+
___ctr01cb:
btst #11,%d3
bne.s ___drtr01cc
adda.w #2,%a0
bra.s  ___ctr01cc
___drtr01cc:
btst #11,%d0
beq.s ___atr01cc
or.w %d1,(%a0)+
bra.s ___ctr01cc
___atr01cc:
and.w %d2,(%a0)+
___ctr01cc:
btst #10,%d3
bne.s ___drtr01cd
adda.w #4,%a0
bra.s  ___ctr01cd
___drtr01cd:
btst #10,%d0
beq.s ___atr01cd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01cd
___atr01cd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01cd:
btst #9,%d3
bne.s ___drtr01ce
adda.w #2,%a0
bra.s  ___ctr01ce
___drtr01ce:
btst #9,%d0
beq.s ___atr01ce
or.w %d1,(%a0)+
bra.s ___ctr01ce
___atr01ce:
and.w %d2,(%a0)+
___ctr01ce:
btst #8,%d3
bne.s ___drtr01cf
adda.w #2,%a0
bra.s  ___ctr01cf
___drtr01cf:
btst #8,%d0
beq.s ___atr01cf
or.w %d1,(%a0)+
bra.s ___ctr01cf
___atr01cf:
and.w %d2,(%a0)+
___ctr01cf:
tst.b %d3
bmi.s ___drtr01d0
adda.w #4,%a0
bra.s  ___ctr01d0
___drtr01d0:
tst.b %d0
bpl.s ___atr01d0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01d0
___atr01d0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01d0:
btst #6,%d3
bne.s ___drtr01d1
adda.w #2,%a0
bra.s  ___ctr01d1
___drtr01d1:
btst #6,%d0
beq.s ___atr01d1
or.w %d1,(%a0)+
bra.s ___ctr01d1
___atr01d1:
and.w %d2,(%a0)+
___ctr01d1:
btst #5,%d3
bne.s ___drtr01d2
adda.w #2,%a0
bra.s  ___ctr01d2
___drtr01d2:
btst #5,%d0
beq.s ___atr01d2
or.w %d1,(%a0)+
bra.s ___ctr01d2
___atr01d2:
and.w %d2,(%a0)+
___ctr01d2:
btst #4,%d3
bne.s ___drtr01d3
adda.w #2,%a0
bra.s  ___ctr01d3
___drtr01d3:
btst #4,%d0
beq.s ___atr01d3
or.w %d1,(%a0)+
bra.s ___ctr01d3
___atr01d3:
and.w %d2,(%a0)+
___ctr01d3:
btst #3,%d3
bne.s ___drtr01d4
adda.w #4,%a0
bra.s  ___ctr01d4
___drtr01d4:
btst #3,%d0
beq.s ___atr01d4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01d4
___atr01d4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01d4:
btst #2,%d3
bne.s ___drtr01d5
adda.w #2,%a0
bra.s  ___ctr01d5
___drtr01d5:
btst #2,%d0
beq.s ___atr01d5
or.w %d1,(%a0)+
bra.s ___ctr01d5
___atr01d5:
and.w %d2,(%a0)+
___ctr01d5:
btst #1,%d3
bne.s ___drtr01d6
adda.w #2,%a0
bra.s  ___ctr01d6
___drtr01d6:
btst #1,%d0
beq.s ___atr01d6
or.w %d1,(%a0)+
bra.s ___ctr01d6
___atr01d6:
and.w %d2,(%a0)+
___ctr01d6:
btst #0,%d3
bne.s ___drtr01d7
rts
___drtr01d7:
btst #0,%d0
beq.s ___atr01d7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr01d7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale086:
tst.l %d3
bmi.s ___drtr01d8
adda.w #4,%a0
bra.s  ___ctr01d8
___drtr01d8:
tst.l %d0
bpl.s ___atr01d8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01d8
___atr01d8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01d8:
btst #30,%d3
bne.s ___drtr01d9
adda.w #2,%a0
bra.s  ___ctr01d9
___drtr01d9:
btst #30,%d0
beq.s ___atr01d9
or.w %d1,(%a0)+
bra.s ___ctr01d9
___atr01d9:
and.w %d2,(%a0)+
___ctr01d9:
btst #29,%d3
bne.s ___drtr01da
adda.w #4,%a0
bra.s  ___ctr01da
___drtr01da:
btst #29,%d0
beq.s ___atr01da
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01da
___atr01da:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01da:
btst #28,%d3
bne.s ___drtr01db
adda.w #2,%a0
bra.s  ___ctr01db
___drtr01db:
btst #28,%d0
beq.s ___atr01db
or.w %d1,(%a0)+
bra.s ___ctr01db
___atr01db:
and.w %d2,(%a0)+
___ctr01db:
btst #27,%d3
bne.s ___drtr01dc
adda.w #2,%a0
bra.s  ___ctr01dc
___drtr01dc:
btst #27,%d0
beq.s ___atr01dc
or.w %d1,(%a0)+
bra.s ___ctr01dc
___atr01dc:
and.w %d2,(%a0)+
___ctr01dc:
btst #26,%d3
bne.s ___drtr01dd
adda.w #4,%a0
bra.s  ___ctr01dd
___drtr01dd:
btst #26,%d0
beq.s ___atr01dd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01dd
___atr01dd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01dd:
btst #25,%d3
bne.s ___drtr01de
adda.w #2,%a0
bra.s  ___ctr01de
___drtr01de:
btst #25,%d0
beq.s ___atr01de
or.w %d1,(%a0)+
bra.s ___ctr01de
___atr01de:
and.w %d2,(%a0)+
___ctr01de:
btst #24,%d3
bne.s ___drtr01df
adda.w #2,%a0
bra.s  ___ctr01df
___drtr01df:
btst #24,%d0
beq.s ___atr01df
or.w %d1,(%a0)+
bra.s ___ctr01df
___atr01df:
and.w %d2,(%a0)+
___ctr01df:
btst #23,%d3
bne.s ___drtr01e0
adda.w #4,%a0
bra.s  ___ctr01e0
___drtr01e0:
btst #23,%d0
beq.s ___atr01e0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01e0
___atr01e0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01e0:
btst #22,%d3
bne.s ___drtr01e1
adda.w #2,%a0
bra.s  ___ctr01e1
___drtr01e1:
btst #22,%d0
beq.s ___atr01e1
or.w %d1,(%a0)+
bra.s ___ctr01e1
___atr01e1:
and.w %d2,(%a0)+
___ctr01e1:
btst #21,%d3
bne.s ___drtr01e2
adda.w #2,%a0
bra.s  ___ctr01e2
___drtr01e2:
btst #21,%d0
beq.s ___atr01e2
or.w %d1,(%a0)+
bra.s ___ctr01e2
___atr01e2:
and.w %d2,(%a0)+
___ctr01e2:
btst #20,%d3
bne.s ___drtr01e3
adda.w #4,%a0
bra.s  ___ctr01e3
___drtr01e3:
btst #20,%d0
beq.s ___atr01e3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01e3
___atr01e3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01e3:
btst #19,%d3
bne.s ___drtr01e4
adda.w #2,%a0
bra.s  ___ctr01e4
___drtr01e4:
btst #19,%d0
beq.s ___atr01e4
or.w %d1,(%a0)+
bra.s ___ctr01e4
___atr01e4:
and.w %d2,(%a0)+
___ctr01e4:
btst #18,%d3
bne.s ___drtr01e5
adda.w #2,%a0
bra.s  ___ctr01e5
___drtr01e5:
btst #18,%d0
beq.s ___atr01e5
or.w %d1,(%a0)+
bra.s ___ctr01e5
___atr01e5:
and.w %d2,(%a0)+
___ctr01e5:
btst #17,%d3
bne.s ___drtr01e6
adda.w #4,%a0
bra.s  ___ctr01e6
___drtr01e6:
btst #17,%d0
beq.s ___atr01e6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01e6
___atr01e6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01e6:
btst #16,%d3
bne.s ___drtr01e7
adda.w #2,%a0
bra.s  ___ctr01e7
___drtr01e7:
btst #16,%d0
beq.s ___atr01e7
or.w %d1,(%a0)+
bra.s ___ctr01e7
___atr01e7:
and.w %d2,(%a0)+
___ctr01e7:
tst.w %d3
bmi.s ___drtr01e8
adda.w #2,%a0
bra.s  ___ctr01e8
___drtr01e8:
tst.w %d0
bpl.s ___atr01e8
or.w %d1,(%a0)+
bra.s ___ctr01e8
___atr01e8:
and.w %d2,(%a0)+
___ctr01e8:
btst #14,%d3
bne.s ___drtr01e9
adda.w #4,%a0
bra.s  ___ctr01e9
___drtr01e9:
btst #14,%d0
beq.s ___atr01e9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01e9
___atr01e9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01e9:
btst #13,%d3
bne.s ___drtr01ea
adda.w #2,%a0
bra.s  ___ctr01ea
___drtr01ea:
btst #13,%d0
beq.s ___atr01ea
or.w %d1,(%a0)+
bra.s ___ctr01ea
___atr01ea:
and.w %d2,(%a0)+
___ctr01ea:
btst #12,%d3
bne.s ___drtr01eb
adda.w #2,%a0
bra.s  ___ctr01eb
___drtr01eb:
btst #12,%d0
beq.s ___atr01eb
or.w %d1,(%a0)+
bra.s ___ctr01eb
___atr01eb:
and.w %d2,(%a0)+
___ctr01eb:
btst #11,%d3
bne.s ___drtr01ec
adda.w #4,%a0
bra.s  ___ctr01ec
___drtr01ec:
btst #11,%d0
beq.s ___atr01ec
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01ec
___atr01ec:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01ec:
btst #10,%d3
bne.s ___drtr01ed
adda.w #2,%a0
bra.s  ___ctr01ed
___drtr01ed:
btst #10,%d0
beq.s ___atr01ed
or.w %d1,(%a0)+
bra.s ___ctr01ed
___atr01ed:
and.w %d2,(%a0)+
___ctr01ed:
btst #9,%d3
bne.s ___drtr01ee
adda.w #4,%a0
bra.s  ___ctr01ee
___drtr01ee:
btst #9,%d0
beq.s ___atr01ee
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01ee
___atr01ee:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01ee:
btst #8,%d3
bne.s ___drtr01ef
adda.w #2,%a0
bra.s  ___ctr01ef
___drtr01ef:
btst #8,%d0
beq.s ___atr01ef
or.w %d1,(%a0)+
bra.s ___ctr01ef
___atr01ef:
and.w %d2,(%a0)+
___ctr01ef:
tst.b %d3
bmi.s ___drtr01f0
adda.w #2,%a0
bra.s  ___ctr01f0
___drtr01f0:
tst.b %d0
bpl.s ___atr01f0
or.w %d1,(%a0)+
bra.s ___ctr01f0
___atr01f0:
and.w %d2,(%a0)+
___ctr01f0:
btst #6,%d3
bne.s ___drtr01f1
adda.w #4,%a0
bra.s  ___ctr01f1
___drtr01f1:
btst #6,%d0
beq.s ___atr01f1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01f1
___atr01f1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01f1:
btst #5,%d3
bne.s ___drtr01f2
adda.w #2,%a0
bra.s  ___ctr01f2
___drtr01f2:
btst #5,%d0
beq.s ___atr01f2
or.w %d1,(%a0)+
bra.s ___ctr01f2
___atr01f2:
and.w %d2,(%a0)+
___ctr01f2:
btst #4,%d3
bne.s ___drtr01f3
adda.w #2,%a0
bra.s  ___ctr01f3
___drtr01f3:
btst #4,%d0
beq.s ___atr01f3
or.w %d1,(%a0)+
bra.s ___ctr01f3
___atr01f3:
and.w %d2,(%a0)+
___ctr01f3:
btst #3,%d3
bne.s ___drtr01f4
adda.w #4,%a0
bra.s  ___ctr01f4
___drtr01f4:
btst #3,%d0
beq.s ___atr01f4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01f4
___atr01f4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01f4:
btst #2,%d3
bne.s ___drtr01f5
adda.w #2,%a0
bra.s  ___ctr01f5
___drtr01f5:
btst #2,%d0
beq.s ___atr01f5
or.w %d1,(%a0)+
bra.s ___ctr01f5
___atr01f5:
and.w %d2,(%a0)+
___ctr01f5:
btst #1,%d3
bne.s ___drtr01f6
adda.w #2,%a0
bra.s  ___ctr01f6
___drtr01f6:
btst #1,%d0
beq.s ___atr01f6
or.w %d1,(%a0)+
bra.s ___ctr01f6
___atr01f6:
and.w %d2,(%a0)+
___ctr01f6:
btst #0,%d3
bne.s ___drtr01f7
rts
___drtr01f7:
btst #0,%d0
beq.s ___atr01f7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr01f7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale090:
tst.l %d3
bmi.s ___drtr01f8
adda.w #4,%a0
bra.s  ___ctr01f8
___drtr01f8:
tst.l %d0
bpl.s ___atr01f8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01f8
___atr01f8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01f8:
btst #30,%d3
bne.s ___drtr01f9
adda.w #2,%a0
bra.s  ___ctr01f9
___drtr01f9:
btst #30,%d0
beq.s ___atr01f9
or.w %d1,(%a0)+
bra.s ___ctr01f9
___atr01f9:
and.w %d2,(%a0)+
___ctr01f9:
btst #29,%d3
bne.s ___drtr01fa
adda.w #4,%a0
bra.s  ___ctr01fa
___drtr01fa:
btst #29,%d0
beq.s ___atr01fa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01fa
___atr01fa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01fa:
btst #28,%d3
bne.s ___drtr01fb
adda.w #2,%a0
bra.s  ___ctr01fb
___drtr01fb:
btst #28,%d0
beq.s ___atr01fb
or.w %d1,(%a0)+
bra.s ___ctr01fb
___atr01fb:
and.w %d2,(%a0)+
___ctr01fb:
btst #27,%d3
bne.s ___drtr01fc
adda.w #4,%a0
bra.s  ___ctr01fc
___drtr01fc:
btst #27,%d0
beq.s ___atr01fc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01fc
___atr01fc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01fc:
btst #26,%d3
bne.s ___drtr01fd
adda.w #2,%a0
bra.s  ___ctr01fd
___drtr01fd:
btst #26,%d0
beq.s ___atr01fd
or.w %d1,(%a0)+
bra.s ___ctr01fd
___atr01fd:
and.w %d2,(%a0)+
___ctr01fd:
btst #25,%d3
bne.s ___drtr01fe
adda.w #2,%a0
bra.s  ___ctr01fe
___drtr01fe:
btst #25,%d0
beq.s ___atr01fe
or.w %d1,(%a0)+
bra.s ___ctr01fe
___atr01fe:
and.w %d2,(%a0)+
___ctr01fe:
btst #24,%d3
bne.s ___drtr01ff
adda.w #4,%a0
bra.s  ___ctr01ff
___drtr01ff:
btst #24,%d0
beq.s ___atr01ff
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr01ff
___atr01ff:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr01ff:
btst #23,%d3
bne.s ___drtr0200
adda.w #2,%a0
bra.s  ___ctr0200
___drtr0200:
btst #23,%d0
beq.s ___atr0200
or.w %d1,(%a0)+
bra.s ___ctr0200
___atr0200:
and.w %d2,(%a0)+
___ctr0200:
btst #22,%d3
bne.s ___drtr0201
adda.w #4,%a0
bra.s  ___ctr0201
___drtr0201:
btst #22,%d0
beq.s ___atr0201
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0201
___atr0201:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0201:
btst #21,%d3
bne.s ___drtr0202
adda.w #2,%a0
bra.s  ___ctr0202
___drtr0202:
btst #21,%d0
beq.s ___atr0202
or.w %d1,(%a0)+
bra.s ___ctr0202
___atr0202:
and.w %d2,(%a0)+
___ctr0202:
btst #20,%d3
bne.s ___drtr0203
adda.w #2,%a0
bra.s  ___ctr0203
___drtr0203:
btst #20,%d0
beq.s ___atr0203
or.w %d1,(%a0)+
bra.s ___ctr0203
___atr0203:
and.w %d2,(%a0)+
___ctr0203:
btst #19,%d3
bne.s ___drtr0204
adda.w #4,%a0
bra.s  ___ctr0204
___drtr0204:
btst #19,%d0
beq.s ___atr0204
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0204
___atr0204:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0204:
btst #18,%d3
bne.s ___drtr0205
adda.w #2,%a0
bra.s  ___ctr0205
___drtr0205:
btst #18,%d0
beq.s ___atr0205
or.w %d1,(%a0)+
bra.s ___ctr0205
___atr0205:
and.w %d2,(%a0)+
___ctr0205:
btst #17,%d3
bne.s ___drtr0206
adda.w #4,%a0
bra.s  ___ctr0206
___drtr0206:
btst #17,%d0
beq.s ___atr0206
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0206
___atr0206:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0206:
btst #16,%d3
bne.s ___drtr0207
adda.w #2,%a0
bra.s  ___ctr0207
___drtr0207:
btst #16,%d0
beq.s ___atr0207
or.w %d1,(%a0)+
bra.s ___ctr0207
___atr0207:
and.w %d2,(%a0)+
___ctr0207:
tst.w %d3
bmi.s ___drtr0208
adda.w #4,%a0
bra.s  ___ctr0208
___drtr0208:
tst.w %d0
bpl.s ___atr0208
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0208
___atr0208:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0208:
btst #14,%d3
bne.s ___drtr0209
adda.w #2,%a0
bra.s  ___ctr0209
___drtr0209:
btst #14,%d0
beq.s ___atr0209
or.w %d1,(%a0)+
bra.s ___ctr0209
___atr0209:
and.w %d2,(%a0)+
___ctr0209:
btst #13,%d3
bne.s ___drtr020a
adda.w #2,%a0
bra.s  ___ctr020a
___drtr020a:
btst #13,%d0
beq.s ___atr020a
or.w %d1,(%a0)+
bra.s ___ctr020a
___atr020a:
and.w %d2,(%a0)+
___ctr020a:
btst #12,%d3
bne.s ___drtr020b
adda.w #4,%a0
bra.s  ___ctr020b
___drtr020b:
btst #12,%d0
beq.s ___atr020b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr020b
___atr020b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr020b:
btst #11,%d3
bne.s ___drtr020c
adda.w #2,%a0
bra.s  ___ctr020c
___drtr020c:
btst #11,%d0
beq.s ___atr020c
or.w %d1,(%a0)+
bra.s ___ctr020c
___atr020c:
and.w %d2,(%a0)+
___ctr020c:
btst #10,%d3
bne.s ___drtr020d
adda.w #4,%a0
bra.s  ___ctr020d
___drtr020d:
btst #10,%d0
beq.s ___atr020d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr020d
___atr020d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr020d:
btst #9,%d3
bne.s ___drtr020e
adda.w #2,%a0
bra.s  ___ctr020e
___drtr020e:
btst #9,%d0
beq.s ___atr020e
or.w %d1,(%a0)+
bra.s ___ctr020e
___atr020e:
and.w %d2,(%a0)+
___ctr020e:
btst #8,%d3
bne.s ___drtr020f
adda.w #2,%a0
bra.s  ___ctr020f
___drtr020f:
btst #8,%d0
beq.s ___atr020f
or.w %d1,(%a0)+
bra.s ___ctr020f
___atr020f:
and.w %d2,(%a0)+
___ctr020f:
tst.b %d3
bmi.s ___drtr0210
adda.w #4,%a0
bra.s  ___ctr0210
___drtr0210:
tst.b %d0
bpl.s ___atr0210
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0210
___atr0210:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0210:
btst #6,%d3
bne.s ___drtr0211
adda.w #2,%a0
bra.s  ___ctr0211
___drtr0211:
btst #6,%d0
beq.s ___atr0211
or.w %d1,(%a0)+
bra.s ___ctr0211
___atr0211:
and.w %d2,(%a0)+
___ctr0211:
btst #5,%d3
bne.s ___drtr0212
adda.w #4,%a0
bra.s  ___ctr0212
___drtr0212:
btst #5,%d0
beq.s ___atr0212
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0212
___atr0212:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0212:
btst #4,%d3
bne.s ___drtr0213
adda.w #2,%a0
bra.s  ___ctr0213
___drtr0213:
btst #4,%d0
beq.s ___atr0213
or.w %d1,(%a0)+
bra.s ___ctr0213
___atr0213:
and.w %d2,(%a0)+
___ctr0213:
btst #3,%d3
bne.s ___drtr0214
adda.w #2,%a0
bra.s  ___ctr0214
___drtr0214:
btst #3,%d0
beq.s ___atr0214
or.w %d1,(%a0)+
bra.s ___ctr0214
___atr0214:
and.w %d2,(%a0)+
___ctr0214:
btst #2,%d3
bne.s ___drtr0215
adda.w #4,%a0
bra.s  ___ctr0215
___drtr0215:
btst #2,%d0
beq.s ___atr0215
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0215
___atr0215:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0215:
btst #1,%d3
bne.s ___drtr0216
adda.w #2,%a0
bra.s  ___ctr0216
___drtr0216:
btst #1,%d0
beq.s ___atr0216
or.w %d1,(%a0)+
bra.s ___ctr0216
___atr0216:
and.w %d2,(%a0)+
___ctr0216:
btst #0,%d3
bne.s ___drtr0217
rts
___drtr0217:
btst #0,%d0
beq.s ___atr0217
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr0217:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale094:
tst.l %d3
bmi.s ___drtr0218
adda.w #4,%a0
bra.s  ___ctr0218
___drtr0218:
tst.l %d0
bpl.s ___atr0218
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0218
___atr0218:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0218:
btst #30,%d3
bne.s ___drtr0219
adda.w #2,%a0
bra.s  ___ctr0219
___drtr0219:
btst #30,%d0
beq.s ___atr0219
or.w %d1,(%a0)+
bra.s ___ctr0219
___atr0219:
and.w %d2,(%a0)+
___ctr0219:
btst #29,%d3
bne.s ___drtr021a
adda.w #4,%a0
bra.s  ___ctr021a
___drtr021a:
btst #29,%d0
beq.s ___atr021a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr021a
___atr021a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr021a:
btst #28,%d3
bne.s ___drtr021b
adda.w #2,%a0
bra.s  ___ctr021b
___drtr021b:
btst #28,%d0
beq.s ___atr021b
or.w %d1,(%a0)+
bra.s ___ctr021b
___atr021b:
and.w %d2,(%a0)+
___ctr021b:
btst #27,%d3
bne.s ___drtr021c
adda.w #4,%a0
bra.s  ___ctr021c
___drtr021c:
btst #27,%d0
beq.s ___atr021c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr021c
___atr021c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr021c:
btst #26,%d3
bne.s ___drtr021d
adda.w #2,%a0
bra.s  ___ctr021d
___drtr021d:
btst #26,%d0
beq.s ___atr021d
or.w %d1,(%a0)+
bra.s ___ctr021d
___atr021d:
and.w %d2,(%a0)+
___ctr021d:
btst #25,%d3
bne.s ___drtr021e
adda.w #4,%a0
bra.s  ___ctr021e
___drtr021e:
btst #25,%d0
beq.s ___atr021e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr021e
___atr021e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr021e:
btst #24,%d3
bne.s ___drtr021f
adda.w #2,%a0
bra.s  ___ctr021f
___drtr021f:
btst #24,%d0
beq.s ___atr021f
or.w %d1,(%a0)+
bra.s ___ctr021f
___atr021f:
and.w %d2,(%a0)+
___ctr021f:
btst #23,%d3
bne.s ___drtr0220
adda.w #4,%a0
bra.s  ___ctr0220
___drtr0220:
btst #23,%d0
beq.s ___atr0220
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0220
___atr0220:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0220:
btst #22,%d3
bne.s ___drtr0221
adda.w #2,%a0
bra.s  ___ctr0221
___drtr0221:
btst #22,%d0
beq.s ___atr0221
or.w %d1,(%a0)+
bra.s ___ctr0221
___atr0221:
and.w %d2,(%a0)+
___ctr0221:
btst #21,%d3
bne.s ___drtr0222
adda.w #4,%a0
bra.s  ___ctr0222
___drtr0222:
btst #21,%d0
beq.s ___atr0222
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0222
___atr0222:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0222:
btst #20,%d3
bne.s ___drtr0223
adda.w #2,%a0
bra.s  ___ctr0223
___drtr0223:
btst #20,%d0
beq.s ___atr0223
or.w %d1,(%a0)+
bra.s ___ctr0223
___atr0223:
and.w %d2,(%a0)+
___ctr0223:
btst #19,%d3
bne.s ___drtr0224
adda.w #4,%a0
bra.s  ___ctr0224
___drtr0224:
btst #19,%d0
beq.s ___atr0224
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0224
___atr0224:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0224:
btst #18,%d3
bne.s ___drtr0225
adda.w #2,%a0
bra.s  ___ctr0225
___drtr0225:
btst #18,%d0
beq.s ___atr0225
or.w %d1,(%a0)+
bra.s ___ctr0225
___atr0225:
and.w %d2,(%a0)+
___ctr0225:
btst #17,%d3
bne.s ___drtr0226
adda.w #4,%a0
bra.s  ___ctr0226
___drtr0226:
btst #17,%d0
beq.s ___atr0226
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0226
___atr0226:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0226:
btst #16,%d3
bne.s ___drtr0227
adda.w #2,%a0
bra.s  ___ctr0227
___drtr0227:
btst #16,%d0
beq.s ___atr0227
or.w %d1,(%a0)+
bra.s ___ctr0227
___atr0227:
and.w %d2,(%a0)+
___ctr0227:
tst.w %d3
bmi.s ___drtr0228
adda.w #4,%a0
bra.s  ___ctr0228
___drtr0228:
tst.w %d0
bpl.s ___atr0228
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0228
___atr0228:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0228:
btst #14,%d3
bne.s ___drtr0229
adda.w #2,%a0
bra.s  ___ctr0229
___drtr0229:
btst #14,%d0
beq.s ___atr0229
or.w %d1,(%a0)+
bra.s ___ctr0229
___atr0229:
and.w %d2,(%a0)+
___ctr0229:
btst #13,%d3
bne.s ___drtr022a
adda.w #4,%a0
bra.s  ___ctr022a
___drtr022a:
btst #13,%d0
beq.s ___atr022a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr022a
___atr022a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr022a:
btst #12,%d3
bne.s ___drtr022b
adda.w #2,%a0
bra.s  ___ctr022b
___drtr022b:
btst #12,%d0
beq.s ___atr022b
or.w %d1,(%a0)+
bra.s ___ctr022b
___atr022b:
and.w %d2,(%a0)+
___ctr022b:
btst #11,%d3
bne.s ___drtr022c
adda.w #2,%a0
bra.s  ___ctr022c
___drtr022c:
btst #11,%d0
beq.s ___atr022c
or.w %d1,(%a0)+
bra.s ___ctr022c
___atr022c:
and.w %d2,(%a0)+
___ctr022c:
btst #10,%d3
bne.s ___drtr022d
adda.w #4,%a0
bra.s  ___ctr022d
___drtr022d:
btst #10,%d0
beq.s ___atr022d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr022d
___atr022d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr022d:
btst #9,%d3
bne.s ___drtr022e
adda.w #2,%a0
bra.s  ___ctr022e
___drtr022e:
btst #9,%d0
beq.s ___atr022e
or.w %d1,(%a0)+
bra.s ___ctr022e
___atr022e:
and.w %d2,(%a0)+
___ctr022e:
btst #8,%d3
bne.s ___drtr022f
adda.w #4,%a0
bra.s  ___ctr022f
___drtr022f:
btst #8,%d0
beq.s ___atr022f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr022f
___atr022f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr022f:
tst.b %d3
bmi.s ___drtr0230
adda.w #2,%a0
bra.s  ___ctr0230
___drtr0230:
tst.b %d0
bpl.s ___atr0230
or.w %d1,(%a0)+
bra.s ___ctr0230
___atr0230:
and.w %d2,(%a0)+
___ctr0230:
btst #6,%d3
bne.s ___drtr0231
adda.w #4,%a0
bra.s  ___ctr0231
___drtr0231:
btst #6,%d0
beq.s ___atr0231
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0231
___atr0231:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0231:
btst #5,%d3
bne.s ___drtr0232
adda.w #2,%a0
bra.s  ___ctr0232
___drtr0232:
btst #5,%d0
beq.s ___atr0232
or.w %d1,(%a0)+
bra.s ___ctr0232
___atr0232:
and.w %d2,(%a0)+
___ctr0232:
btst #4,%d3
bne.s ___drtr0233
adda.w #4,%a0
bra.s  ___ctr0233
___drtr0233:
btst #4,%d0
beq.s ___atr0233
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0233
___atr0233:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0233:
btst #3,%d3
bne.s ___drtr0234
adda.w #2,%a0
bra.s  ___ctr0234
___drtr0234:
btst #3,%d0
beq.s ___atr0234
or.w %d1,(%a0)+
bra.s ___ctr0234
___atr0234:
and.w %d2,(%a0)+
___ctr0234:
btst #2,%d3
bne.s ___drtr0235
adda.w #4,%a0
bra.s  ___ctr0235
___drtr0235:
btst #2,%d0
beq.s ___atr0235
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0235
___atr0235:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0235:
btst #1,%d3
bne.s ___drtr0236
adda.w #2,%a0
bra.s  ___ctr0236
___drtr0236:
btst #1,%d0
beq.s ___atr0236
or.w %d1,(%a0)+
bra.s ___ctr0236
___atr0236:
and.w %d2,(%a0)+
___ctr0236:
btst #0,%d3
bne.s ___drtr0237
rts
___drtr0237:
btst #0,%d0
beq.s ___atr0237
or.w %d1,(%a0)+
or.w %d1,(%a0)+
rts
___atr0237:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
rts
__tr_scale098:
tst.l %d3
bmi.s ___drtr0238
adda.w #4,%a0
bra.s  ___ctr0238
___drtr0238:
tst.l %d0
bpl.s ___atr0238
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0238
___atr0238:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0238:
btst #30,%d3
bne.s ___drtr0239
adda.w #4,%a0
bra.s  ___ctr0239
___drtr0239:
btst #30,%d0
beq.s ___atr0239
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0239
___atr0239:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0239:
btst #29,%d3
bne.s ___drtr023a
adda.w #2,%a0
bra.s  ___ctr023a
___drtr023a:
btst #29,%d0
beq.s ___atr023a
or.w %d1,(%a0)+
bra.s ___ctr023a
___atr023a:
and.w %d2,(%a0)+
___ctr023a:
btst #28,%d3
bne.s ___drtr023b
adda.w #4,%a0
bra.s  ___ctr023b
___drtr023b:
btst #28,%d0
beq.s ___atr023b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr023b
___atr023b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr023b:
btst #27,%d3
bne.s ___drtr023c
adda.w #2,%a0
bra.s  ___ctr023c
___drtr023c:
btst #27,%d0
beq.s ___atr023c
or.w %d1,(%a0)+
bra.s ___ctr023c
___atr023c:
and.w %d2,(%a0)+
___ctr023c:
btst #26,%d3
bne.s ___drtr023d
adda.w #4,%a0
bra.s  ___ctr023d
___drtr023d:
btst #26,%d0
beq.s ___atr023d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr023d
___atr023d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr023d:
btst #25,%d3
bne.s ___drtr023e
adda.w #2,%a0
bra.s  ___ctr023e
___drtr023e:
btst #25,%d0
beq.s ___atr023e
or.w %d1,(%a0)+
bra.s ___ctr023e
___atr023e:
and.w %d2,(%a0)+
___ctr023e:
btst #24,%d3
bne.s ___drtr023f
adda.w #4,%a0
bra.s  ___ctr023f
___drtr023f:
btst #24,%d0
beq.s ___atr023f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr023f
___atr023f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr023f:
btst #23,%d3
bne.s ___drtr0240
adda.w #2,%a0
bra.s  ___ctr0240
___drtr0240:
btst #23,%d0
beq.s ___atr0240
or.w %d1,(%a0)+
bra.s ___ctr0240
___atr0240:
and.w %d2,(%a0)+
___ctr0240:
btst #22,%d3
bne.s ___drtr0241
adda.w #4,%a0
bra.s  ___ctr0241
___drtr0241:
btst #22,%d0
beq.s ___atr0241
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0241
___atr0241:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0241:
btst #21,%d3
bne.s ___drtr0242
adda.w #2,%a0
bra.s  ___ctr0242
___drtr0242:
btst #21,%d0
beq.s ___atr0242
or.w %d1,(%a0)+
bra.s ___ctr0242
___atr0242:
and.w %d2,(%a0)+
___ctr0242:
btst #20,%d3
bne.s ___drtr0243
adda.w #4,%a0
bra.s  ___ctr0243
___drtr0243:
btst #20,%d0
beq.s ___atr0243
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0243
___atr0243:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0243:
btst #19,%d3
bne.s ___drtr0244
adda.w #4,%a0
bra.s  ___ctr0244
___drtr0244:
btst #19,%d0
beq.s ___atr0244
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0244
___atr0244:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0244:
btst #18,%d3
bne.s ___drtr0245
adda.w #2,%a0
bra.s  ___ctr0245
___drtr0245:
btst #18,%d0
beq.s ___atr0245
or.w %d1,(%a0)+
bra.s ___ctr0245
___atr0245:
and.w %d2,(%a0)+
___ctr0245:
btst #17,%d3
bne.s ___drtr0246
adda.w #4,%a0
bra.s  ___ctr0246
___drtr0246:
btst #17,%d0
beq.s ___atr0246
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0246
___atr0246:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0246:
btst #16,%d3
bne.s ___drtr0247
adda.w #2,%a0
bra.s  ___ctr0247
___drtr0247:
btst #16,%d0
beq.s ___atr0247
or.w %d1,(%a0)+
bra.s ___ctr0247
___atr0247:
and.w %d2,(%a0)+
___ctr0247:
tst.w %d3
bmi.s ___drtr0248
adda.w #4,%a0
bra.s  ___ctr0248
___drtr0248:
tst.w %d0
bpl.s ___atr0248
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0248
___atr0248:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0248:
btst #14,%d3
bne.s ___drtr0249
adda.w #2,%a0
bra.s  ___ctr0249
___drtr0249:
btst #14,%d0
beq.s ___atr0249
or.w %d1,(%a0)+
bra.s ___ctr0249
___atr0249:
and.w %d2,(%a0)+
___ctr0249:
btst #13,%d3
bne.s ___drtr024a
adda.w #4,%a0
bra.s  ___ctr024a
___drtr024a:
btst #13,%d0
beq.s ___atr024a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr024a
___atr024a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr024a:
btst #12,%d3
bne.s ___drtr024b
adda.w #2,%a0
bra.s  ___ctr024b
___drtr024b:
btst #12,%d0
beq.s ___atr024b
or.w %d1,(%a0)+
bra.s ___ctr024b
___atr024b:
and.w %d2,(%a0)+
___ctr024b:
btst #11,%d3
bne.s ___drtr024c
adda.w #4,%a0
bra.s  ___ctr024c
___drtr024c:
btst #11,%d0
beq.s ___atr024c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr024c
___atr024c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr024c:
btst #10,%d3
bne.s ___drtr024d
adda.w #2,%a0
bra.s  ___ctr024d
___drtr024d:
btst #10,%d0
beq.s ___atr024d
or.w %d1,(%a0)+
bra.s ___ctr024d
___atr024d:
and.w %d2,(%a0)+
___ctr024d:
btst #9,%d3
bne.s ___drtr024e
adda.w #4,%a0
bra.s  ___ctr024e
___drtr024e:
btst #9,%d0
beq.s ___atr024e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr024e
___atr024e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr024e:
btst #8,%d3
bne.s ___drtr024f
adda.w #2,%a0
bra.s  ___ctr024f
___drtr024f:
btst #8,%d0
beq.s ___atr024f
or.w %d1,(%a0)+
bra.s ___ctr024f
___atr024f:
and.w %d2,(%a0)+
___ctr024f:
tst.b %d3
bmi.s ___drtr0250
adda.w #4,%a0
bra.s  ___ctr0250
___drtr0250:
tst.b %d0
bpl.s ___atr0250
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0250
___atr0250:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0250:
btst #6,%d3
bne.s ___drtr0251
adda.w #4,%a0
bra.s  ___ctr0251
___drtr0251:
btst #6,%d0
beq.s ___atr0251
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0251
___atr0251:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0251:
btst #5,%d3
bne.s ___drtr0252
adda.w #2,%a0
bra.s  ___ctr0252
___drtr0252:
btst #5,%d0
beq.s ___atr0252
or.w %d1,(%a0)+
bra.s ___ctr0252
___atr0252:
and.w %d2,(%a0)+
___ctr0252:
btst #4,%d3
bne.s ___drtr0253
adda.w #4,%a0
bra.s  ___ctr0253
___drtr0253:
btst #4,%d0
beq.s ___atr0253
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0253
___atr0253:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0253:
btst #3,%d3
bne.s ___drtr0254
adda.w #2,%a0
bra.s  ___ctr0254
___drtr0254:
btst #3,%d0
beq.s ___atr0254
or.w %d1,(%a0)+
bra.s ___ctr0254
___atr0254:
and.w %d2,(%a0)+
___ctr0254:
btst #2,%d3
bne.s ___drtr0255
adda.w #4,%a0
bra.s  ___ctr0255
___drtr0255:
btst #2,%d0
beq.s ___atr0255
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0255
___atr0255:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0255:
btst #1,%d3
bne.s ___drtr0256
rts
___drtr0256:
btst #1,%d0
beq.s ___atr0256
or.w %d1,(%a0)+
rts
___atr0256:
and.w %d2,(%a0)+
rts
__tr_scale102:
btst #30,%d3
bne.s ___drtr0257
adda.w #4,%a0
bra.s  ___ctr0257
___drtr0257:
btst #30,%d0
beq.s ___atr0257
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0257
___atr0257:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0257:
btst #29,%d3
bne.s ___drtr0258
adda.w #4,%a0
bra.s  ___ctr0258
___drtr0258:
btst #29,%d0
beq.s ___atr0258
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0258
___atr0258:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0258:
btst #28,%d3
bne.s ___drtr0259
adda.w #2,%a0
bra.s  ___ctr0259
___drtr0259:
btst #28,%d0
beq.s ___atr0259
or.w %d1,(%a0)+
bra.s ___ctr0259
___atr0259:
and.w %d2,(%a0)+
___ctr0259:
btst #27,%d3
bne.s ___drtr025a
adda.w #4,%a0
bra.s  ___ctr025a
___drtr025a:
btst #27,%d0
beq.s ___atr025a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr025a
___atr025a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr025a:
btst #26,%d3
bne.s ___drtr025b
adda.w #4,%a0
bra.s  ___ctr025b
___drtr025b:
btst #26,%d0
beq.s ___atr025b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr025b
___atr025b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr025b:
btst #25,%d3
bne.s ___drtr025c
adda.w #2,%a0
bra.s  ___ctr025c
___drtr025c:
btst #25,%d0
beq.s ___atr025c
or.w %d1,(%a0)+
bra.s ___ctr025c
___atr025c:
and.w %d2,(%a0)+
___ctr025c:
btst #24,%d3
bne.s ___drtr025d
adda.w #4,%a0
bra.s  ___ctr025d
___drtr025d:
btst #24,%d0
beq.s ___atr025d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr025d
___atr025d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr025d:
btst #23,%d3
bne.s ___drtr025e
adda.w #2,%a0
bra.s  ___ctr025e
___drtr025e:
btst #23,%d0
beq.s ___atr025e
or.w %d1,(%a0)+
bra.s ___ctr025e
___atr025e:
and.w %d2,(%a0)+
___ctr025e:
btst #22,%d3
bne.s ___drtr025f
adda.w #4,%a0
bra.s  ___ctr025f
___drtr025f:
btst #22,%d0
beq.s ___atr025f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr025f
___atr025f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr025f:
btst #21,%d3
bne.s ___drtr0260
adda.w #4,%a0
bra.s  ___ctr0260
___drtr0260:
btst #21,%d0
beq.s ___atr0260
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0260
___atr0260:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0260:
btst #20,%d3
bne.s ___drtr0261
adda.w #2,%a0
bra.s  ___ctr0261
___drtr0261:
btst #20,%d0
beq.s ___atr0261
or.w %d1,(%a0)+
bra.s ___ctr0261
___atr0261:
and.w %d2,(%a0)+
___ctr0261:
btst #19,%d3
bne.s ___drtr0262
adda.w #4,%a0
bra.s  ___ctr0262
___drtr0262:
btst #19,%d0
beq.s ___atr0262
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0262
___atr0262:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0262:
btst #18,%d3
bne.s ___drtr0263
adda.w #2,%a0
bra.s  ___ctr0263
___drtr0263:
btst #18,%d0
beq.s ___atr0263
or.w %d1,(%a0)+
bra.s ___ctr0263
___atr0263:
and.w %d2,(%a0)+
___ctr0263:
btst #17,%d3
bne.s ___drtr0264
adda.w #4,%a0
bra.s  ___ctr0264
___drtr0264:
btst #17,%d0
beq.s ___atr0264
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0264
___atr0264:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0264:
btst #16,%d3
bne.s ___drtr0265
adda.w #4,%a0
bra.s  ___ctr0265
___drtr0265:
btst #16,%d0
beq.s ___atr0265
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0265
___atr0265:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0265:
tst.w %d3
bmi.s ___drtr0266
adda.w #2,%a0
bra.s  ___ctr0266
___drtr0266:
tst.w %d0
bpl.s ___atr0266
or.w %d1,(%a0)+
bra.s ___ctr0266
___atr0266:
and.w %d2,(%a0)+
___ctr0266:
btst #14,%d3
bne.s ___drtr0267
adda.w #4,%a0
bra.s  ___ctr0267
___drtr0267:
btst #14,%d0
beq.s ___atr0267
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0267
___atr0267:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0267:
btst #13,%d3
bne.s ___drtr0268
adda.w #2,%a0
bra.s  ___ctr0268
___drtr0268:
btst #13,%d0
beq.s ___atr0268
or.w %d1,(%a0)+
bra.s ___ctr0268
___atr0268:
and.w %d2,(%a0)+
___ctr0268:
btst #12,%d3
bne.s ___drtr0269
adda.w #4,%a0
bra.s  ___ctr0269
___drtr0269:
btst #12,%d0
beq.s ___atr0269
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0269
___atr0269:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0269:
btst #11,%d3
bne.s ___drtr026a
adda.w #4,%a0
bra.s  ___ctr026a
___drtr026a:
btst #11,%d0
beq.s ___atr026a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr026a
___atr026a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr026a:
btst #10,%d3
bne.s ___drtr026b
adda.w #2,%a0
bra.s  ___ctr026b
___drtr026b:
btst #10,%d0
beq.s ___atr026b
or.w %d1,(%a0)+
bra.s ___ctr026b
___atr026b:
and.w %d2,(%a0)+
___ctr026b:
btst #9,%d3
bne.s ___drtr026c
adda.w #4,%a0
bra.s  ___ctr026c
___drtr026c:
btst #9,%d0
beq.s ___atr026c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr026c
___atr026c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr026c:
btst #8,%d3
bne.s ___drtr026d
adda.w #2,%a0
bra.s  ___ctr026d
___drtr026d:
btst #8,%d0
beq.s ___atr026d
or.w %d1,(%a0)+
bra.s ___ctr026d
___atr026d:
and.w %d2,(%a0)+
___ctr026d:
tst.b %d3
bmi.s ___drtr026e
adda.w #4,%a0
bra.s  ___ctr026e
___drtr026e:
tst.b %d0
bpl.s ___atr026e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr026e
___atr026e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr026e:
btst #6,%d3
bne.s ___drtr026f
adda.w #4,%a0
bra.s  ___ctr026f
___drtr026f:
btst #6,%d0
beq.s ___atr026f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr026f
___atr026f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr026f:
btst #5,%d3
bne.s ___drtr0270
adda.w #2,%a0
bra.s  ___ctr0270
___drtr0270:
btst #5,%d0
beq.s ___atr0270
or.w %d1,(%a0)+
bra.s ___ctr0270
___atr0270:
and.w %d2,(%a0)+
___ctr0270:
btst #4,%d3
bne.s ___drtr0271
adda.w #4,%a0
bra.s  ___ctr0271
___drtr0271:
btst #4,%d0
beq.s ___atr0271
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0271
___atr0271:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0271:
btst #3,%d3
bne.s ___drtr0272
adda.w #2,%a0
bra.s  ___ctr0272
___drtr0272:
btst #3,%d0
beq.s ___atr0272
or.w %d1,(%a0)+
bra.s ___ctr0272
___atr0272:
and.w %d2,(%a0)+
___ctr0272:
btst #2,%d3
bne.s ___drtr0273
adda.w #4,%a0
bra.s  ___ctr0273
___drtr0273:
btst #2,%d0
beq.s ___atr0273
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0273
___atr0273:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0273:
btst #1,%d3
bne.s ___drtr0274
rts
___drtr0274:
btst #1,%d0
beq.s ___atr0274
or.w %d1,(%a0)+
rts
___atr0274:
and.w %d2,(%a0)+
rts
__tr_scale106:
btst #28,%d3
bne.s ___drtr0275
adda.w #4,%a0
bra.s  ___ctr0275
___drtr0275:
btst #28,%d0
beq.s ___atr0275
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0275
___atr0275:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0275:
btst #27,%d3
bne.s ___drtr0276
adda.w #4,%a0
bra.s  ___ctr0276
___drtr0276:
btst #27,%d0
beq.s ___atr0276
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0276
___atr0276:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0276:
btst #26,%d3
bne.s ___drtr0277
adda.w #2,%a0
bra.s  ___ctr0277
___drtr0277:
btst #26,%d0
beq.s ___atr0277
or.w %d1,(%a0)+
bra.s ___ctr0277
___atr0277:
and.w %d2,(%a0)+
___ctr0277:
btst #25,%d3
bne.s ___drtr0278
adda.w #4,%a0
bra.s  ___ctr0278
___drtr0278:
btst #25,%d0
beq.s ___atr0278
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0278
___atr0278:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0278:
btst #24,%d3
bne.s ___drtr0279
adda.w #4,%a0
bra.s  ___ctr0279
___drtr0279:
btst #24,%d0
beq.s ___atr0279
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0279
___atr0279:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0279:
btst #23,%d3
bne.s ___drtr027a
adda.w #2,%a0
bra.s  ___ctr027a
___drtr027a:
btst #23,%d0
beq.s ___atr027a
or.w %d1,(%a0)+
bra.s ___ctr027a
___atr027a:
and.w %d2,(%a0)+
___ctr027a:
btst #22,%d3
bne.s ___drtr027b
adda.w #4,%a0
bra.s  ___ctr027b
___drtr027b:
btst #22,%d0
beq.s ___atr027b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr027b
___atr027b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr027b:
btst #21,%d3
bne.s ___drtr027c
adda.w #4,%a0
bra.s  ___ctr027c
___drtr027c:
btst #21,%d0
beq.s ___atr027c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr027c
___atr027c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr027c:
btst #20,%d3
bne.s ___drtr027d
adda.w #4,%a0
bra.s  ___ctr027d
___drtr027d:
btst #20,%d0
beq.s ___atr027d
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr027d
___atr027d:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr027d:
btst #19,%d3
bne.s ___drtr027e
adda.w #2,%a0
bra.s  ___ctr027e
___drtr027e:
btst #19,%d0
beq.s ___atr027e
or.w %d1,(%a0)+
bra.s ___ctr027e
___atr027e:
and.w %d2,(%a0)+
___ctr027e:
btst #18,%d3
bne.s ___drtr027f
adda.w #4,%a0
bra.s  ___ctr027f
___drtr027f:
btst #18,%d0
beq.s ___atr027f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr027f
___atr027f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr027f:
btst #17,%d3
bne.s ___drtr0280
adda.w #4,%a0
bra.s  ___ctr0280
___drtr0280:
btst #17,%d0
beq.s ___atr0280
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0280
___atr0280:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0280:
btst #16,%d3
bne.s ___drtr0281
adda.w #2,%a0
bra.s  ___ctr0281
___drtr0281:
btst #16,%d0
beq.s ___atr0281
or.w %d1,(%a0)+
bra.s ___ctr0281
___atr0281:
and.w %d2,(%a0)+
___ctr0281:
tst.w %d3
bmi.s ___drtr0282
adda.w #4,%a0
bra.s  ___ctr0282
___drtr0282:
tst.w %d0
bpl.s ___atr0282
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0282
___atr0282:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0282:
btst #14,%d3
bne.s ___drtr0283
adda.w #4,%a0
bra.s  ___ctr0283
___drtr0283:
btst #14,%d0
beq.s ___atr0283
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0283
___atr0283:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0283:
btst #13,%d3
bne.s ___drtr0284
adda.w #2,%a0
bra.s  ___ctr0284
___drtr0284:
btst #13,%d0
beq.s ___atr0284
or.w %d1,(%a0)+
bra.s ___ctr0284
___atr0284:
and.w %d2,(%a0)+
___ctr0284:
btst #12,%d3
bne.s ___drtr0285
adda.w #4,%a0
bra.s  ___ctr0285
___drtr0285:
btst #12,%d0
beq.s ___atr0285
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0285
___atr0285:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0285:
btst #11,%d3
bne.s ___drtr0286
adda.w #4,%a0
bra.s  ___ctr0286
___drtr0286:
btst #11,%d0
beq.s ___atr0286
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0286
___atr0286:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0286:
btst #10,%d3
bne.s ___drtr0287
adda.w #2,%a0
bra.s  ___ctr0287
___drtr0287:
btst #10,%d0
beq.s ___atr0287
or.w %d1,(%a0)+
bra.s ___ctr0287
___atr0287:
and.w %d2,(%a0)+
___ctr0287:
btst #9,%d3
bne.s ___drtr0288
adda.w #4,%a0
bra.s  ___ctr0288
___drtr0288:
btst #9,%d0
beq.s ___atr0288
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0288
___atr0288:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0288:
btst #8,%d3
bne.s ___drtr0289
adda.w #4,%a0
bra.s  ___ctr0289
___drtr0289:
btst #8,%d0
beq.s ___atr0289
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0289
___atr0289:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0289:
tst.b %d3
bmi.s ___drtr028a
adda.w #2,%a0
bra.s  ___ctr028a
___drtr028a:
tst.b %d0
bpl.s ___atr028a
or.w %d1,(%a0)+
bra.s ___ctr028a
___atr028a:
and.w %d2,(%a0)+
___ctr028a:
btst #6,%d3
bne.s ___drtr028b
adda.w #4,%a0
bra.s  ___ctr028b
___drtr028b:
btst #6,%d0
beq.s ___atr028b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr028b
___atr028b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr028b:
btst #5,%d3
bne.s ___drtr028c
adda.w #4,%a0
bra.s  ___ctr028c
___drtr028c:
btst #5,%d0
beq.s ___atr028c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr028c
___atr028c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr028c:
btst #4,%d3
bne.s ___drtr028d
adda.w #2,%a0
bra.s  ___ctr028d
___drtr028d:
btst #4,%d0
beq.s ___atr028d
or.w %d1,(%a0)+
bra.s ___ctr028d
___atr028d:
and.w %d2,(%a0)+
___ctr028d:
btst #3,%d3
bne.s ___drtr028e
adda.w #4,%a0
bra.s  ___ctr028e
___drtr028e:
btst #3,%d0
beq.s ___atr028e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr028e
___atr028e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr028e:
btst #2,%d3
bne.s ___drtr028f
adda.w #4,%a0
bra.s  ___ctr028f
___drtr028f:
btst #2,%d0
beq.s ___atr028f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr028f
___atr028f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr028f:
btst #1,%d3
bne.s ___drtr0290
adda.w #2,%a0
bra.s  ___ctr0290
___drtr0290:
btst #1,%d0
beq.s ___atr0290
or.w %d1,(%a0)+
bra.s ___ctr0290
___atr0290:
and.w %d2,(%a0)+
___ctr0290:
btst #0,%d3
bne.s ___drtr0291
rts
___drtr0291:
btst #0,%d0
beq.s ___atr0291
or.w %d1,(%a0)+
rts
___atr0291:
and.w %d2,(%a0)+
rts
__tr_scale110:
btst #27,%d3
bne.s ___drtr0292
adda.w #4,%a0
bra.s  ___ctr0292
___drtr0292:
btst #27,%d0
beq.s ___atr0292
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0292
___atr0292:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0292:
btst #26,%d3
bne.s ___drtr0293
adda.w #4,%a0
bra.s  ___ctr0293
___drtr0293:
btst #26,%d0
beq.s ___atr0293
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0293
___atr0293:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0293:
btst #25,%d3
bne.s ___drtr0294
adda.w #4,%a0
bra.s  ___ctr0294
___drtr0294:
btst #25,%d0
beq.s ___atr0294
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0294
___atr0294:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0294:
btst #24,%d3
bne.s ___drtr0295
adda.w #2,%a0
bra.s  ___ctr0295
___drtr0295:
btst #24,%d0
beq.s ___atr0295
or.w %d1,(%a0)+
bra.s ___ctr0295
___atr0295:
and.w %d2,(%a0)+
___ctr0295:
btst #23,%d3
bne.s ___drtr0296
adda.w #4,%a0
bra.s  ___ctr0296
___drtr0296:
btst #23,%d0
beq.s ___atr0296
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0296
___atr0296:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0296:
btst #22,%d3
bne.s ___drtr0297
adda.w #4,%a0
bra.s  ___ctr0297
___drtr0297:
btst #22,%d0
beq.s ___atr0297
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0297
___atr0297:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0297:
btst #21,%d3
bne.s ___drtr0298
adda.w #4,%a0
bra.s  ___ctr0298
___drtr0298:
btst #21,%d0
beq.s ___atr0298
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr0298
___atr0298:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr0298:
btst #20,%d3
bne.s ___drtr0299
adda.w #2,%a0
bra.s  ___ctr0299
___drtr0299:
btst #20,%d0
beq.s ___atr0299
or.w %d1,(%a0)+
bra.s ___ctr0299
___atr0299:
and.w %d2,(%a0)+
___ctr0299:
btst #19,%d3
bne.s ___drtr029a
adda.w #4,%a0
bra.s  ___ctr029a
___drtr029a:
btst #19,%d0
beq.s ___atr029a
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr029a
___atr029a:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr029a:
btst #18,%d3
bne.s ___drtr029b
adda.w #4,%a0
bra.s  ___ctr029b
___drtr029b:
btst #18,%d0
beq.s ___atr029b
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr029b
___atr029b:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr029b:
btst #17,%d3
bne.s ___drtr029c
adda.w #4,%a0
bra.s  ___ctr029c
___drtr029c:
btst #17,%d0
beq.s ___atr029c
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr029c
___atr029c:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr029c:
btst #16,%d3
bne.s ___drtr029d
adda.w #2,%a0
bra.s  ___ctr029d
___drtr029d:
btst #16,%d0
beq.s ___atr029d
or.w %d1,(%a0)+
bra.s ___ctr029d
___atr029d:
and.w %d2,(%a0)+
___ctr029d:
tst.w %d3
bmi.s ___drtr029e
adda.w #4,%a0
bra.s  ___ctr029e
___drtr029e:
tst.w %d0
bpl.s ___atr029e
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr029e
___atr029e:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr029e:
btst #14,%d3
bne.s ___drtr029f
adda.w #4,%a0
bra.s  ___ctr029f
___drtr029f:
btst #14,%d0
beq.s ___atr029f
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr029f
___atr029f:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr029f:
btst #13,%d3
bne.s ___drtr02a0
adda.w #2,%a0
bra.s  ___ctr02a0
___drtr02a0:
btst #13,%d0
beq.s ___atr02a0
or.w %d1,(%a0)+
bra.s ___ctr02a0
___atr02a0:
and.w %d2,(%a0)+
___ctr02a0:
btst #12,%d3
bne.s ___drtr02a1
adda.w #4,%a0
bra.s  ___ctr02a1
___drtr02a1:
btst #12,%d0
beq.s ___atr02a1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a1
___atr02a1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a1:
btst #11,%d3
bne.s ___drtr02a2
adda.w #4,%a0
bra.s  ___ctr02a2
___drtr02a2:
btst #11,%d0
beq.s ___atr02a2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a2
___atr02a2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a2:
btst #10,%d3
bne.s ___drtr02a3
adda.w #4,%a0
bra.s  ___ctr02a3
___drtr02a3:
btst #10,%d0
beq.s ___atr02a3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a3
___atr02a3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a3:
btst #9,%d3
bne.s ___drtr02a4
adda.w #2,%a0
bra.s  ___ctr02a4
___drtr02a4:
btst #9,%d0
beq.s ___atr02a4
or.w %d1,(%a0)+
bra.s ___ctr02a4
___atr02a4:
and.w %d2,(%a0)+
___ctr02a4:
btst #8,%d3
bne.s ___drtr02a5
adda.w #4,%a0
bra.s  ___ctr02a5
___drtr02a5:
btst #8,%d0
beq.s ___atr02a5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a5
___atr02a5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a5:
tst.b %d3
bmi.s ___drtr02a6
adda.w #4,%a0
bra.s  ___ctr02a6
___drtr02a6:
tst.b %d0
bpl.s ___atr02a6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a6
___atr02a6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a6:
btst #6,%d3
bne.s ___drtr02a7
adda.w #4,%a0
bra.s  ___ctr02a7
___drtr02a7:
btst #6,%d0
beq.s ___atr02a7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a7
___atr02a7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a7:
btst #5,%d3
bne.s ___drtr02a8
adda.w #2,%a0
bra.s  ___ctr02a8
___drtr02a8:
btst #5,%d0
beq.s ___atr02a8
or.w %d1,(%a0)+
bra.s ___ctr02a8
___atr02a8:
and.w %d2,(%a0)+
___ctr02a8:
btst #4,%d3
bne.s ___drtr02a9
adda.w #4,%a0
bra.s  ___ctr02a9
___drtr02a9:
btst #4,%d0
beq.s ___atr02a9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02a9
___atr02a9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02a9:
btst #3,%d3
bne.s ___drtr02aa
adda.w #4,%a0
bra.s  ___ctr02aa
___drtr02aa:
btst #3,%d0
beq.s ___atr02aa
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02aa
___atr02aa:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02aa:
btst #2,%d3
bne.s ___drtr02ab
adda.w #2,%a0
bra.s  ___ctr02ab
___drtr02ab:
btst #2,%d0
beq.s ___atr02ab
or.w %d1,(%a0)+
bra.s ___ctr02ab
___atr02ab:
and.w %d2,(%a0)+
___ctr02ab:
btst #1,%d3
bne.s ___drtr02ac
adda.w #4,%a0
bra.s  ___ctr02ac
___drtr02ac:
btst #1,%d0
beq.s ___atr02ac
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02ac
___atr02ac:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02ac:
btst #0,%d3
bne.s ___drtr02ad
rts
___drtr02ad:
btst #0,%d0
beq.s ___atr02ad
or.w %d1,(%a0)+
rts
___atr02ad:
and.w %d2,(%a0)+
rts
__tr_scale114:
btst #26,%d3
bne.s ___drtr02ae
adda.w #4,%a0
bra.s  ___ctr02ae
___drtr02ae:
btst #26,%d0
beq.s ___atr02ae
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02ae
___atr02ae:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02ae:
btst #25,%d3
bne.s ___drtr02af
adda.w #4,%a0
bra.s  ___ctr02af
___drtr02af:
btst #25,%d0
beq.s ___atr02af
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02af
___atr02af:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02af:
btst #24,%d3
bne.s ___drtr02b0
adda.w #4,%a0
bra.s  ___ctr02b0
___drtr02b0:
btst #24,%d0
beq.s ___atr02b0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b0
___atr02b0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b0:
btst #23,%d3
bne.s ___drtr02b1
adda.w #4,%a0
bra.s  ___ctr02b1
___drtr02b1:
btst #23,%d0
beq.s ___atr02b1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b1
___atr02b1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b1:
btst #22,%d3
bne.s ___drtr02b2
adda.w #2,%a0
bra.s  ___ctr02b2
___drtr02b2:
btst #22,%d0
beq.s ___atr02b2
or.w %d1,(%a0)+
bra.s ___ctr02b2
___atr02b2:
and.w %d2,(%a0)+
___ctr02b2:
btst #21,%d3
bne.s ___drtr02b3
adda.w #4,%a0
bra.s  ___ctr02b3
___drtr02b3:
btst #21,%d0
beq.s ___atr02b3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b3
___atr02b3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b3:
btst #20,%d3
bne.s ___drtr02b4
adda.w #4,%a0
bra.s  ___ctr02b4
___drtr02b4:
btst #20,%d0
beq.s ___atr02b4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b4
___atr02b4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b4:
btst #19,%d3
bne.s ___drtr02b5
adda.w #4,%a0
bra.s  ___ctr02b5
___drtr02b5:
btst #19,%d0
beq.s ___atr02b5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b5
___atr02b5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b5:
btst #18,%d3
bne.s ___drtr02b6
adda.w #4,%a0
bra.s  ___ctr02b6
___drtr02b6:
btst #18,%d0
beq.s ___atr02b6
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b6
___atr02b6:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b6:
btst #17,%d3
bne.s ___drtr02b7
adda.w #2,%a0
bra.s  ___ctr02b7
___drtr02b7:
btst #17,%d0
beq.s ___atr02b7
or.w %d1,(%a0)+
bra.s ___ctr02b7
___atr02b7:
and.w %d2,(%a0)+
___ctr02b7:
btst #16,%d3
bne.s ___drtr02b8
adda.w #4,%a0
bra.s  ___ctr02b8
___drtr02b8:
btst #16,%d0
beq.s ___atr02b8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b8
___atr02b8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b8:
tst.w %d3
bmi.s ___drtr02b9
adda.w #4,%a0
bra.s  ___ctr02b9
___drtr02b9:
tst.w %d0
bpl.s ___atr02b9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02b9
___atr02b9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02b9:
btst #14,%d3
bne.s ___drtr02ba
adda.w #4,%a0
bra.s  ___ctr02ba
___drtr02ba:
btst #14,%d0
beq.s ___atr02ba
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02ba
___atr02ba:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02ba:
btst #13,%d3
bne.s ___drtr02bb
adda.w #4,%a0
bra.s  ___ctr02bb
___drtr02bb:
btst #13,%d0
beq.s ___atr02bb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02bb
___atr02bb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02bb:
btst #12,%d3
bne.s ___drtr02bc
adda.w #2,%a0
bra.s  ___ctr02bc
___drtr02bc:
btst #12,%d0
beq.s ___atr02bc
or.w %d1,(%a0)+
bra.s ___ctr02bc
___atr02bc:
and.w %d2,(%a0)+
___ctr02bc:
btst #11,%d3
bne.s ___drtr02bd
adda.w #4,%a0
bra.s  ___ctr02bd
___drtr02bd:
btst #11,%d0
beq.s ___atr02bd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02bd
___atr02bd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02bd:
btst #10,%d3
bne.s ___drtr02be
adda.w #4,%a0
bra.s  ___ctr02be
___drtr02be:
btst #10,%d0
beq.s ___atr02be
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02be
___atr02be:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02be:
btst #9,%d3
bne.s ___drtr02bf
adda.w #4,%a0
bra.s  ___ctr02bf
___drtr02bf:
btst #9,%d0
beq.s ___atr02bf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02bf
___atr02bf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02bf:
btst #8,%d3
bne.s ___drtr02c0
adda.w #4,%a0
bra.s  ___ctr02c0
___drtr02c0:
btst #8,%d0
beq.s ___atr02c0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c0
___atr02c0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c0:
tst.b %d3
bmi.s ___drtr02c1
adda.w #2,%a0
bra.s  ___ctr02c1
___drtr02c1:
tst.b %d0
bpl.s ___atr02c1
or.w %d1,(%a0)+
bra.s ___ctr02c1
___atr02c1:
and.w %d2,(%a0)+
___ctr02c1:
btst #6,%d3
bne.s ___drtr02c2
adda.w #4,%a0
bra.s  ___ctr02c2
___drtr02c2:
btst #6,%d0
beq.s ___atr02c2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c2
___atr02c2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c2:
btst #5,%d3
bne.s ___drtr02c3
adda.w #4,%a0
bra.s  ___ctr02c3
___drtr02c3:
btst #5,%d0
beq.s ___atr02c3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c3
___atr02c3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c3:
btst #4,%d3
bne.s ___drtr02c4
adda.w #4,%a0
bra.s  ___ctr02c4
___drtr02c4:
btst #4,%d0
beq.s ___atr02c4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c4
___atr02c4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c4:
btst #3,%d3
bne.s ___drtr02c5
adda.w #4,%a0
bra.s  ___ctr02c5
___drtr02c5:
btst #3,%d0
beq.s ___atr02c5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c5
___atr02c5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c5:
btst #2,%d3
bne.s ___drtr02c6
adda.w #2,%a0
bra.s  ___ctr02c6
___drtr02c6:
btst #2,%d0
beq.s ___atr02c6
or.w %d1,(%a0)+
bra.s ___ctr02c6
___atr02c6:
and.w %d2,(%a0)+
___ctr02c6:
btst #1,%d3
bne.s ___drtr02c7
adda.w #4,%a0
bra.s  ___ctr02c7
___drtr02c7:
btst #1,%d0
beq.s ___atr02c7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c7
___atr02c7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c7:
btst #0,%d3
bne.s ___drtr02c8
rts
___drtr02c8:
btst #0,%d0
beq.s ___atr02c8
or.w %d1,(%a0)+
rts
___atr02c8:
and.w %d2,(%a0)+
rts
__tr_scale118:
btst #26,%d3
bne.s ___drtr02c9
adda.w #4,%a0
bra.s  ___ctr02c9
___drtr02c9:
btst #26,%d0
beq.s ___atr02c9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02c9
___atr02c9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02c9:
btst #25,%d3
bne.s ___drtr02ca
adda.w #4,%a0
bra.s  ___ctr02ca
___drtr02ca:
btst #25,%d0
beq.s ___atr02ca
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02ca
___atr02ca:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02ca:
btst #24,%d3
bne.s ___drtr02cb
adda.w #4,%a0
bra.s  ___ctr02cb
___drtr02cb:
btst #24,%d0
beq.s ___atr02cb
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02cb
___atr02cb:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02cb:
btst #23,%d3
bne.s ___drtr02cc
adda.w #4,%a0
bra.s  ___ctr02cc
___drtr02cc:
btst #23,%d0
beq.s ___atr02cc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02cc
___atr02cc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02cc:
btst #22,%d3
bne.s ___drtr02cd
adda.w #4,%a0
bra.s  ___ctr02cd
___drtr02cd:
btst #22,%d0
beq.s ___atr02cd
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02cd
___atr02cd:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02cd:
btst #21,%d3
bne.s ___drtr02ce
adda.w #4,%a0
bra.s  ___ctr02ce
___drtr02ce:
btst #21,%d0
beq.s ___atr02ce
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02ce
___atr02ce:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02ce:
btst #20,%d3
bne.s ___drtr02cf
adda.w #4,%a0
bra.s  ___ctr02cf
___drtr02cf:
btst #20,%d0
beq.s ___atr02cf
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02cf
___atr02cf:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02cf:
btst #19,%d3
bne.s ___drtr02d0
adda.w #2,%a0
bra.s  ___ctr02d0
___drtr02d0:
btst #19,%d0
beq.s ___atr02d0
or.w %d1,(%a0)+
bra.s ___ctr02d0
___atr02d0:
and.w %d2,(%a0)+
___ctr02d0:
btst #18,%d3
bne.s ___drtr02d1
adda.w #4,%a0
bra.s  ___ctr02d1
___drtr02d1:
btst #18,%d0
beq.s ___atr02d1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d1
___atr02d1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d1:
btst #17,%d3
bne.s ___drtr02d2
adda.w #4,%a0
bra.s  ___ctr02d2
___drtr02d2:
btst #17,%d0
beq.s ___atr02d2
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d2
___atr02d2:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d2:
btst #16,%d3
bne.s ___drtr02d3
adda.w #4,%a0
bra.s  ___ctr02d3
___drtr02d3:
btst #16,%d0
beq.s ___atr02d3
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d3
___atr02d3:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d3:
tst.w %d3
bmi.s ___drtr02d4
adda.w #4,%a0
bra.s  ___ctr02d4
___drtr02d4:
tst.w %d0
bpl.s ___atr02d4
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d4
___atr02d4:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d4:
btst #14,%d3
bne.s ___drtr02d5
adda.w #4,%a0
bra.s  ___ctr02d5
___drtr02d5:
btst #14,%d0
beq.s ___atr02d5
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d5
___atr02d5:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d5:
btst #13,%d3
bne.s ___drtr02d6
adda.w #2,%a0
bra.s  ___ctr02d6
___drtr02d6:
btst #13,%d0
beq.s ___atr02d6
or.w %d1,(%a0)+
bra.s ___ctr02d6
___atr02d6:
and.w %d2,(%a0)+
___ctr02d6:
btst #12,%d3
bne.s ___drtr02d7
adda.w #4,%a0
bra.s  ___ctr02d7
___drtr02d7:
btst #12,%d0
beq.s ___atr02d7
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d7
___atr02d7:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d7:
btst #11,%d3
bne.s ___drtr02d8
adda.w #4,%a0
bra.s  ___ctr02d8
___drtr02d8:
btst #11,%d0
beq.s ___atr02d8
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d8
___atr02d8:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d8:
btst #10,%d3
bne.s ___drtr02d9
adda.w #4,%a0
bra.s  ___ctr02d9
___drtr02d9:
btst #10,%d0
beq.s ___atr02d9
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02d9
___atr02d9:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02d9:
btst #9,%d3
bne.s ___drtr02da
adda.w #4,%a0
bra.s  ___ctr02da
___drtr02da:
btst #9,%d0
beq.s ___atr02da
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02da
___atr02da:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02da:
btst #8,%d3
bne.s ___drtr02db
adda.w #4,%a0
bra.s  ___ctr02db
___drtr02db:
btst #8,%d0
beq.s ___atr02db
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02db
___atr02db:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02db:
tst.b %d3
bmi.s ___drtr02dc
adda.w #4,%a0
bra.s  ___ctr02dc
___drtr02dc:
tst.b %d0
bpl.s ___atr02dc
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02dc
___atr02dc:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02dc:
btst #6,%d3
bne.s ___drtr02dd
adda.w #2,%a0
bra.s  ___ctr02dd
___drtr02dd:
btst #6,%d0
beq.s ___atr02dd
or.w %d1,(%a0)+
bra.s ___ctr02dd
___atr02dd:
and.w %d2,(%a0)+
___ctr02dd:
btst #5,%d3
bne.s ___drtr02de
adda.w #4,%a0
bra.s  ___ctr02de
___drtr02de:
btst #5,%d0
beq.s ___atr02de
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02de
___atr02de:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02de:
btst #4,%d3
bne.s ___drtr02df
adda.w #4,%a0
bra.s  ___ctr02df
___drtr02df:
btst #4,%d0
beq.s ___atr02df
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02df
___atr02df:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02df:
btst #3,%d3
bne.s ___drtr02e0
adda.w #4,%a0
bra.s  ___ctr02e0
___drtr02e0:
btst #3,%d0
beq.s ___atr02e0
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02e0
___atr02e0:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02e0:
btst #2,%d3
bne.s ___drtr02e1
adda.w #4,%a0
bra.s  ___ctr02e1
___drtr02e1:
btst #2,%d0
beq.s ___atr02e1
or.w %d1,(%a0)+
or.w %d1,(%a0)+
bra.s ___ctr02e1
___atr02e1:
and.w %d2,(%a0)+
and.w %d2,(%a0)+
___ctr02e1:
btst #1,%d3
bne.s ___drtr02e2
rts
___drtr02e2:
btst #1,%d0
beq.s ___atr02e2
or.w %d1,(%a0)+
rts
___atr02e2:
and.w %d2,(%a0)+
rts
TransScalerJumpTable:
adda.w #94,%a0
jmp __tr_scale002(%pc)
nop;nop
jmp __tr_scale002(%pc)
adda.w #92,%a0
jmp __tr_scale004(%pc)
nop;nop
jmp __tr_scale004(%pc)
adda.w #90,%a0
jmp __tr_scale006(%pc)
nop;nop
jmp __tr_scale006(%pc)
adda.w #88,%a0
jmp __tr_scale008(%pc)
nop;nop
jmp __tr_scale008(%pc)
adda.w #86,%a0
jmp __tr_scale010(%pc)
nop;nop
jmp __tr_scale010(%pc)
adda.w #84,%a0
jmp __tr_scale012(%pc)
nop;nop
jmp __tr_scale012(%pc)
adda.w #82,%a0
jmp __tr_scale014(%pc)
nop;nop
jmp __tr_scale014(%pc)
adda.w #80,%a0
jmp __tr_scale016(%pc)
nop;nop
jmp __tr_scale016(%pc)
adda.w #78,%a0
jmp __tr_scale018(%pc)
nop;nop
jmp __tr_scale018(%pc)
adda.w #76,%a0
jmp __tr_scale020(%pc)
nop;nop
jmp __tr_scale020(%pc)
adda.w #74,%a0
jmp __tr_scale022(%pc)
nop;nop
jmp __tr_scale022(%pc)
adda.w #72,%a0
jmp __tr_scale024(%pc)
nop;nop
jmp __tr_scale024(%pc)
adda.w #70,%a0
jmp __tr_scale026(%pc)
nop;nop
jmp __tr_scale026(%pc)
adda.w #68,%a0
jmp __tr_scale028(%pc)
nop;nop
jmp __tr_scale028(%pc)
adda.w #66,%a0
jmp __tr_scale030(%pc)
nop;nop
jmp __tr_scale030(%pc)
adda.w #66,%a0
jmp __tr_scale030(%pc)
nop;nop
jmp __tr_scale030(%pc)
adda.w #62,%a0
jmp __tr_scale034(%pc)
nop;nop
jmp __tr_scale034(%pc)
adda.w #62,%a0
jmp __tr_scale034(%pc)
nop;nop
jmp __tr_scale034(%pc)
adda.w #58,%a0
jmp __tr_scale038(%pc)
nop;nop
jmp __tr_scale038(%pc)
adda.w #58,%a0
jmp __tr_scale038(%pc)
nop;nop
jmp __tr_scale038(%pc)
adda.w #54,%a0
jmp __tr_scale042(%pc)
nop;nop
jmp __tr_scale042(%pc)
adda.w #54,%a0
jmp __tr_scale042(%pc)
nop;nop
jmp __tr_scale042(%pc)
adda.w #50,%a0
jmp __tr_scale046(%pc)
nop;nop
jmp __tr_scale046(%pc)
adda.w #50,%a0
jmp __tr_scale046(%pc)
nop;nop
jmp __tr_scale046(%pc)
adda.w #46,%a0
jmp __tr_scale050(%pc)
nop;nop
jmp __tr_scale050(%pc)
adda.w #46,%a0
jmp __tr_scale050(%pc)
nop;nop
jmp __tr_scale050(%pc)
adda.w #42,%a0
jmp __tr_scale054(%pc)
nop;nop
jmp __tr_scale054(%pc)
adda.w #42,%a0
jmp __tr_scale054(%pc)
nop;nop
jmp __tr_scale054(%pc)
adda.w #38,%a0
jmp __tr_scale058(%pc)
nop;nop
jmp __tr_scale058(%pc)
adda.w #38,%a0
jmp __tr_scale058(%pc)
nop;nop
jmp __tr_scale058(%pc)
adda.w #34,%a0
jmp __tr_scale062(%pc)
nop;nop
jmp __tr_scale062(%pc)
adda.w #34,%a0
jmp __tr_scale062(%pc)
nop;nop
jmp __tr_scale062(%pc)
adda.w #30,%a0
jmp __tr_scale066(%pc)
nop;nop
jmp __tr_scale066(%pc)
adda.w #30,%a0
jmp __tr_scale066(%pc)
nop;nop
jmp __tr_scale066(%pc)
adda.w #26,%a0
jmp __tr_scale070(%pc)
nop;nop
jmp __tr_scale070(%pc)
adda.w #26,%a0
jmp __tr_scale070(%pc)
nop;nop
jmp __tr_scale070(%pc)
adda.w #22,%a0
jmp __tr_scale074(%pc)
nop;nop
jmp __tr_scale074(%pc)
adda.w #22,%a0
jmp __tr_scale074(%pc)
nop;nop
jmp __tr_scale074(%pc)
adda.w #18,%a0
jmp __tr_scale078(%pc)
nop;nop
jmp __tr_scale078(%pc)
adda.w #18,%a0
jmp __tr_scale078(%pc)
nop;nop
jmp __tr_scale078(%pc)
adda.w #14,%a0
jmp __tr_scale082(%pc)
nop;nop
jmp __tr_scale082(%pc)
adda.w #14,%a0
jmp __tr_scale082(%pc)
nop;nop
jmp __tr_scale082(%pc)
adda.w #10,%a0
jmp __tr_scale086(%pc)
nop;nop
jmp __tr_scale086(%pc)
adda.w #10,%a0
jmp __tr_scale086(%pc)
nop;nop
jmp __tr_scale086(%pc)
adda.w #6,%a0
jmp __tr_scale090(%pc)
nop;nop
jmp __tr_scale090(%pc)
adda.w #6,%a0
jmp __tr_scale090(%pc)
nop;nop
jmp __tr_scale090(%pc)
adda.w #2,%a0
jmp __tr_scale094(%pc)
nop;nop
jmp __tr_scale094(%pc)
adda.w #2,%a0
jmp __tr_scale094(%pc)
nop;nop
jmp __tr_scale094(%pc)
nop;nop
jmp __tr_scale098(%pc)
nop;nop
jmp __tr_scale098(%pc)
nop;nop
jmp __tr_scale098(%pc)
nop;nop
jmp __tr_scale098(%pc)
nop;nop
jmp __tr_scale102(%pc)
lsr.l #1,%d0;lsr.l #1,%d3
jmp __tr_scale102(%pc)
nop;nop
jmp __tr_scale102(%pc)
lsr.l #1,%d0;lsr.l #1,%d3
jmp __tr_scale102(%pc)
nop;nop
jmp __tr_scale106(%pc)
lsr.l #3,%d0;lsr.l #3,%d3
jmp __tr_scale106(%pc)
nop;nop
jmp __tr_scale106(%pc)
lsr.l #3,%d0;lsr.l #3,%d3
jmp __tr_scale106(%pc)
nop;nop
jmp __tr_scale110(%pc)
lsr.l #4,%d0;lsr.l #4,%d3
jmp __tr_scale110(%pc)
nop;nop
jmp __tr_scale110(%pc)
lsr.l #4,%d0;lsr.l #4,%d3
jmp __tr_scale110(%pc)
nop;nop
jmp __tr_scale114(%pc)
lsr.l #5,%d0;lsr.l #5,%d3
jmp __tr_scale114(%pc)
nop;nop
jmp __tr_scale114(%pc)
lsr.l #5,%d0;lsr.l #5,%d3
jmp __tr_scale114(%pc)
nop;nop
jmp __tr_scale118(%pc)
lsr.l #5,%d0;lsr.l #5,%d3
jmp __tr_scale118(%pc)
nop;nop
jmp __tr_scale118(%pc)
lsr.l #5,%d0;lsr.l #5,%d3
jmp __tr_scale118(%pc)
");
INTERNAL_REFERENCED unsigned short sprite_delta[120/2]={
(63<<8)/2,(63<<8)/4,(63<<8)/6,(63<<8)/8,(63<<8)/10,
(63<<8)/12,(63<<8)/14,(63<<8)/16,(63<<8)/18,(63<<8)/20,
(63<<8)/22,(63<<8)/24,(63<<8)/26,(63<<8)/28,(63<<8)/30,
(63<<8)/32,(63<<8)/34,(63<<8)/36,(63<<8)/38,(63<<8)/40,
(63<<8)/42,(63<<8)/44,(63<<8)/46,(63<<8)/48,(63<<8)/50,
(63<<8)/52,(63<<8)/54,(63<<8)/56,(63<<8)/58,(63<<8)/60,
(63<<8)/62,(63<<8)/64,(63<<8)/66,(63<<8)/68,(63<<8)/70,
(63<<8)/72,(63<<8)/74,(63<<8)/76,(63<<8)/78,(63<<8)/80,
(63<<8)/82,(63<<8)/84,(63<<8)/86,(63<<8)/88,(63<<8)/90,
(63<<8)/92,(63<<8)/94,(63<<8)/96,(63<<8)/98,(63<<8)/100,
(63<<8)/102,(63<<8)/104,(63<<8)/106,(63<<8)/108,(63<<8)/110,
(63<<8)/112,(63<<8)/114,(63<<8)/116,(63<<8)/118,(63<<8)/120};

