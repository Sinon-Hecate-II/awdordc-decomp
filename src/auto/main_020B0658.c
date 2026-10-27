/* 13 functions from 0x020B0658 to 0x020B160C (main), found by ds-decomp. */
#include "common.h"

void func_020b0880(void) {
    M2C_UNK func_020b00ec();
    func_020b00ec();
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

