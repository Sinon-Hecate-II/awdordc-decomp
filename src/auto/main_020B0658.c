/* 13 functions from 0x020B0658 to 0x020B160C (main), found by ds-decomp. */
#include "common.h"

void func_020b0658(void) {
    M2C_UNK func_020b0154();
    void Reset3DSpriteEngineState(void);
    extern void *gCur3DSpriteEngine;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;
    register u8 v10 asm("r3") = 0x10;
    register u8 v0 asm("r2") = 0;

    func_020b0154();
    sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp30 = (*sp30 & ~0xc0) | 0x40;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = v10;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = v10;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = v0;
    sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp2C = (*sp2C & ~1) | 1;
    sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp28 = *sp28 & ~2;
    sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp24 = *sp24 & ~4;
    sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp20 = *sp20 & ~8;
    sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp1C = *sp1C & ~0x10;
    sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp18 = *sp18 & ~0x20;
    sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp14 = *sp14 & ~0x100;
    sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp10 = *sp10 & ~0x200;
    spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *spC = *spC | 0x400;
    sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp8 = *sp8 | 0x800;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 & ~0x1000;
    sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp0 = *sp0 | 0x2000;
    Reset3DSpriteEngineState();
}

void func_020b0880(void) {
    M2C_UNK func_020b00ec();
    func_020b00ec();
}

void func_020b088c(void) {
    M2C_UNK func_020b00ec();
    void Reset3DSpriteEngineState(void);
    extern void *gCur3DSpriteEngine;
    u8 v12 = 0x6;
    u8 v10 = 0x10;
    u8 v0 = 0;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    func_020b00ec();
    sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp30 = (*sp30 & ~0xc0) | 0x40;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = v12;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = v10;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = v0;
    sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp2C = *sp2C & ~1;
    sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp28 = *sp28 | 2;
    sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp24 = *sp24 & ~4;
    sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp20 = *sp20 & ~8;
    sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp1C = *sp1C & ~0x10;
    sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp18 = *sp18 & ~0x20;
    sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp14 = *sp14 & ~0x100;
    sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp10 = *sp10 & ~0x200;
    spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *spC = *spC | 0x400;
    sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp8 = *sp8 | 0x800;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 | 0x1000;
    sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp0 = *sp0 | 0x2000;
    Reset3DSpriteEngineState();
}

void func_020b0ab4(void) {
    M2C_UNK func_02082770();
    M2C_UNK func_020b00ec();
    func_020b00ec();
    func_02082770();
}

void func_020b0ac4(void *arg0) {
    M2C_UNK func_02077480();
    if (M2C_FIELD(arg0, s16 *, 0x6C) == 0) {
        return;
    }
    func_02077480();
}

void func_020b0adc(void *arg0) {
    M2C_UNK func_020774b0();
    if (M2C_FIELD(arg0, s16 *, 0x6C) == 0) {
        return;
    }
    func_020774b0();
}

void func_020b0af4(void *arg0) {
    M2C_UNK func_0207749c();
    if (M2C_FIELD(arg0, s16 *, 0x6C) == 0) {
        return;
    }
    func_0207749c();
}

#pragma opt_strength_reduction off
void func_020b0b0c(void *arg0) {
M2C_UNK func_01ff9ce8(M2C_UNK);
M2C_UNK func_0207a66c(s16,s16);
M2C_UNK func_0207c3dc(M2C_UNK *,s32,M2C_UNK,M2C_UNK);
extern M2C_UNK data_020f3d60; extern void **gCurrentMap; extern void *gCur3DSpriteEngine;
s16 y,x,row; s32 count,j,i; void *p;
p=*gCurrentMap; y=M2C_FIELD(p,s16 *,0x514a); x=M2C_FIELD(p,s16 *,0x5148);
if(M2C_FIELD(p,u16 *,0x5146)-(y>>4)>12)count=13;else count=12;
func_01ff9ce8(1);
i=0; if(count>0) do { j=0; loop: func_0207a66c((s16)(j+(x>>4)),(s16)(i+(y>>4))); j++; if(j<16) goto loop; i++; }while(i<count);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
func_0207c3dc(&data_020f3d60,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24)+0x4900,0x80,0);
M2C_FIELD(arg0,s16 *,0x6e)=2;
}

void func_020b0bdc(void *arg0) {
M2C_UNK func_01ff9e78(void *,M2C_UNK,M2C_UNK);
M2C_UNK func_0207c3dc(M2C_UNK *,s32,M2C_UNK,M2C_UNK);
extern M2C_UNK data_020f3d60; extern M2C_UNK data_020f4160; extern M2C_UNK data_020f41a0;
extern void *gCur3DSpriteEngine; extern u32 data_027e15bc;
s16 n=M2C_FIELD(arg0,s16 *,0x6e);
if(n<8){
func_0207c3dc((char *)&data_020f3d60+(n<<7),M2C_FIELD(gCur3DSpriteEngine,s32 *,12)+0x2480,128,0);
M2C_FIELD(arg0,s16 *,0x6e)++;
}
if(M2C_FIELD(arg0,s16 *,0x6c)==0){
func_01ff9e78((char *)&data_020f41a0+((data_027e15bc>>2)%15)*2+2,2,30);
return;
}
func_01ff9e78((char *)&data_020f4160+((data_027e15bc>>2)%15)*2+2,2,30);
}

#pragma opt_strength_reduction reset
void func_020b0cbc(void) {
    func_020c0a1c(3);
}

void func_020b0ccc(void) {

}

/* Configures the audio/channel mix for a sound playback: picks amplitude and delegates to the audio driver helpers. */
void func_020b0cd0(M2C_UNK channel, M2C_UNK sound, s32 duration, u32 mode) {
    M2C_UNK func_0207c55c(s32, M2C_UNK, s32, M2C_UNK);
    s32 func_020815bc(M2C_UNK, s32);
    M2C_UNK func_0208166c();
    M2C_UNK func_020ae548(s32, s32, M2C_UNK, M2C_UNK, s32);
    s32 handle;

    switch (mode) {
    case 0:
        func_0208166c(channel, sound, duration);
        return;
    case 1:
        handle = func_020815bc(channel, duration);
        func_020ae548(handle, 0x7fff, 14, 2, duration);
        func_0207c55c(handle, sound, duration, 1);
        return;
    case 2:
        handle = func_020815bc(channel, duration);
        func_020ae548(handle, 0x4000, 14, 2, duration);
        func_0207c55c(handle, sound, duration, 1);
        return;
    case 3:
        handle = func_020815bc(channel, duration);
        func_020ae548(handle, 0x3ff, 14, 2, duration);
        func_0207c55c(handle, sound, duration, 1);
        return;
    }
}

#pragma scheduling off
void func_020b0dc4(M2C_UNK arg0, u32 arg1) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_0208168c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020a40c0();
    extern M2C_UNK data_02128064;
    extern M2C_UNK data_02128070;
    extern M2C_UNK data_02128080;
    extern M2C_UNK data_02128090;
    extern M2C_UNK data_021280a0;
    extern M2C_UNK data_021280b4;
    extern M2C_UNK data_021280c8;
    extern M2C_UNK data_021280dc;
    extern M2C_UNK data_021280f0;
    extern M2C_UNK data_02128104;
    extern M2C_UNK data_02128118;
    extern M2C_UNK data_02128128;
    extern M2C_UNK data_02128138;
    extern M2C_UNK data_02128148;
    extern M2C_UNK data_0212815c;
    extern M2C_UNK data_02128170;
    extern M2C_UNK data_02128184;
    extern M2C_UNK data_02128198;
    extern M2C_UNK data_021281ac;
    extern M2C_UNK data_021281c0;
    extern M2C_UNK data_021281d0;
    extern M2C_UNK data_021281e0;
    extern M2C_UNK data_021281ec;
    extern M2C_UNK data_021281fc;
    extern M2C_UNK data_0212820c;
    extern M2C_UNK data_02128220;
    extern M2C_UNK data_02128234;
    extern M2C_UNK data_02128244;
    extern M2C_UNK data_02128258;
    extern M2C_UNK data_02128268;
    extern M2C_UNK data_02128278;
    extern M2C_UNK data_02128288;
    extern M2C_UNK data_0212829c;
    extern M2C_UNK data_021282b0;
    extern M2C_UNK data_021282c4;
    extern M2C_UNK data_021282d8;
    extern M2C_UNK data_021282ec;
    extern M2C_UNK data_02128300;
    extern M2C_UNK data_02128310;
    extern M2C_UNK data_02128320;
    extern M2C_UNK data_0212832c;
    extern M2C_UNK data_0212833c;
    extern M2C_UNK data_0212834c;
    extern M2C_UNK data_02128360;
    extern M2C_UNK data_02128374;
    extern M2C_UNK data_02128384;
    extern M2C_UNK data_02128398;
    extern M2C_UNK data_021283a8;
    extern M2C_UNK data_021283b8;
    extern M2C_UNK data_021283c8;
    extern M2C_UNK data_021283dc;
    extern M2C_UNK data_021283f0;
    extern M2C_UNK data_02128404;
    extern M2C_UNK data_02128418;
    extern M2C_UNK data_0212842c;
    extern M2C_UNK data_02128440;
    extern M2C_UNK data_02128450;
    extern M2C_UNK data_02128460;
    extern M2C_UNK data_0212846c;
    extern M2C_UNK data_0212847c;
    extern M2C_UNK data_0212848c;
    extern M2C_UNK data_021284a0;
    extern M2C_UNK data_021284b4;
    extern M2C_UNK data_021284c4;
    extern M2C_UNK data_021284d8;
    extern M2C_UNK data_021284e8;
    extern M2C_UNK data_021284f8;
    extern M2C_UNK data_02128508;
    extern M2C_UNK data_0212851c;
    extern M2C_UNK data_02128530;
    extern M2C_UNK data_02128544;
    extern M2C_UNK data_02128558;
    extern M2C_UNK data_0212856c;
    extern M2C_UNK data_02128580;
    extern M2C_UNK data_02128590;
    extern M2C_UNK data_0212859c;
    extern M2C_UNK data_021285a8;
    extern M2C_UNK data_021285b8;
    extern M2C_UNK data_021285c8;
    extern M2C_UNK data_021285d8;
    extern M2C_UNK data_021285e8;
    extern M2C_UNK data_021285f8;
    extern M2C_UNK data_02128608;
    extern M2C_UNK data_02128618;
    extern M2C_UNK data_02128624;
    extern M2C_UNK data_02128630;
    extern M2C_UNK data_02128640;
    extern M2C_UNK data_02128650;
    extern M2C_UNK data_02128660;
    extern M2C_UNK data_02128670;
    extern M2C_UNK data_02128680;
    u32 mode = arg0;
    func_020a40c0();
    func_0200bc5c(&data_02128064);
    switch (arg1) {
    case 0:
        func_020814e4(&data_02128070);
        func_0208168c(&data_02128080, 0);
        func_020b0cd0((s32)&data_02128090, 0, 0x400, mode);
        func_020b0cd0((s32)&data_021280a0, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_021280b4, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_021280c8, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_021280dc, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_021280f0, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_02128104, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 3:
        func_020814e4(&data_02128118);
        func_0208168c(&data_02128128, 0);
        func_020b0cd0((s32)&data_02128138, 0, 0x400, mode);
        func_020b0cd0((s32)&data_02128148, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_0212815c, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_02128170, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128184, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128198, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_021281ac, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 1:
        func_020814e4(&data_021281c0);
        func_0208168c(&data_021281d0, 0);
        func_020b0cd0((s32)&data_021281e0, 0, 0x400, mode);
        func_020b0cd0((s32)&data_021281ec, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_021281fc, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_0212820c, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128220, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128234, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_02128244, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 2:
        func_020814e4(&data_02128258);
        func_0208168c(&data_02128268, 0);
        func_020b0cd0((s32)&data_02128278, 0, 0x400, mode);
        func_020b0cd0((s32)&data_02128288, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_0212829c, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_021282b0, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_021282c4, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_021282d8, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_021282ec, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 4:
        func_020814e4(&data_02128300);
        func_0208168c(&data_02128310, 0);
        func_020b0cd0((s32)&data_02128320, 0, 0x400, mode);
        func_020b0cd0((s32)&data_0212832c, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_0212833c, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_0212834c, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128360, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128374, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_02128384, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 5:
        func_020814e4(&data_02128398);
        func_0208168c(&data_021283a8, 0);
        func_020b0cd0((s32)&data_021283b8, 0, 0x400, mode);
        func_020b0cd0((s32)&data_021283c8, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_021283dc, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_021283f0, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128404, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128418, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_0212842c, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 6:
        func_020814e4(&data_02128440);
        func_0208168c(&data_02128450, 0);
        func_020b0cd0((s32)&data_02128460, 0, 0x400, mode);
        func_020b0cd0((s32)&data_0212846c, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_0212847c, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_0212848c, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_021284a0, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_021284b4, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_021284c4, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 7:
        func_020814e4(&data_021284d8);
        func_0208168c(&data_021284e8, 0);
        func_020b0cd0((s32)&data_021284f8, 0, 0x400, mode);
        func_020b0cd0((s32)&data_02128508, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_0212851c, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_02128530, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128544, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128558, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_0212856c, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 8:
        func_020814e4(&data_02128580);
        func_0208168c(&data_02128590, 0);
        func_020b0cd0((s32)&data_0212859c, 0, 0x400, mode);
        func_020b0cd0((s32)&data_021285a8, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_021285b8, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_021285c8, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_021285d8, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_021285e8, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_021285f8, 0x1000, 0x200, mode);
        func_02081528();
        return;
    case 9:
        func_020814e4(&data_02128608);
        func_0208168c(&data_02128618, 0);
        func_020b0cd0((s32)&data_02128624, 0, 0x400, mode);
        func_020b0cd0((s32)&data_02128630, 0x400, 0x200, mode);
        func_020b0cd0((s32)&data_02128640, 0x600, 0x200, mode);
        func_020b0cd0((s32)&data_02128650, 0x800, 0x200, mode);
        func_020b0cd0((s32)&data_02128660, 0xA00, 0x200, mode);
        func_020b0cd0((s32)&data_02128670, 0xC00, 0x400, mode);
        func_020b0cd0((s32)&data_02128680, 0x1000, 0x200, mode);
        func_02081528();
        return;
    default: return;
    }
}
#pragma scheduling reset
