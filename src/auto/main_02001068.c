/* 15 functions from 0x02001068 to 0x02002060 (main), found by ds-decomp. */
#include "common.h"

typedef struct UnkVec3 { s32 x,y,z; } UnkVec3;

void func_02001068(s32 *arg0,s32 *arg1,s32 arg2,s32 arg3,s32 arg4) {
void func_02007f4c(void *,void *);
if(arg0!=arg1) func_02007f4c(arg0,arg1);
arg1[9]=arg0[9]+(s32)(((long long)arg2*arg0[0]+(long long)arg3*arg0[3]+(long long)arg4*arg0[6])>>12);
arg1[10]=arg0[10]+(s32)(((long long)arg2*arg0[1]+(long long)arg3*arg0[4]+(long long)arg4*arg0[7])>>12);
arg1[11]=arg0[11]+(s32)(((long long)arg2*arg0[2]+(long long)arg3*arg0[5]+(long long)arg4*arg0[8])>>12);
}

s32 func_02001114(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;

    M2C_FIELD(arg0, s32 *, 0) = arg1;
    temp_r0_2 = arg0 + 4;
    M2C_FIELD(temp_r0_2, s32 *, 0x1C) = arg3;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(temp_r0_2, s32 *, 4) = 0;
    temp_r0_3 = temp_r0_2 + 8;
    M2C_FIELD(temp_r0_2, s32 *, 8) = 0;
    M2C_FIELD(temp_r0_3, s32 *, 4) = arg2;
    M2C_FIELD(temp_r0_3, s32 *, 8) = 0;
    temp_r0_4 = temp_r0_3 + 0xC;
    M2C_FIELD(temp_r0_3, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r0_4, s32 *, 4) = 0;
    temp_r0_5 = temp_r0_4 + 8;
    temp_r0 = temp_r0_5 + 4;
    M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
    M2C_FIELD(temp_r0, s32 *, 4) = 0;
    M2C_FIELD(temp_r0, s32 *, 8) = 0;
    return temp_r0 + 0xC;
}

void func_0200112c(s32 *arg0,s32 arg1,s32 arg2) {
arg0[0]=arg2; arg0[1]=arg1; arg0[2]=0; arg0[3]=-arg1; arg0[4]=arg2; arg0[5]=0; arg0[6]=0; arg0[7]=0; arg0[8]=4096; arg0[9]=0; arg0[10]=0; arg0[11]=0;
}

void func_02001524(void *arg0,UnkVec3 *arg1) {
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0; arg0=(u8 *)arg0+16;
*arg1++=*(UnkVec3 *)arg0;
}

void func_02001fb4(void) {
    M2C_UNK func_02001ff8();
    M2C_UNK func_02002060();
    func_02002060();
    func_02001ff8();
}

void func_02001fc4(void) {
    M2C_UNK func_02002030();
    func_02002030();
    func_02001ff8();
}

u64 func_02001fd4(void) {
while (*(volatile u16 *)0x04000280 & 0x8000) {}
return *(u64 *)0x040002a0;
}

s32 func_02001ff8(void) {
while (*(volatile u16 *)0x04000280 & 0x8000) {}
return (*(volatile u64 *)0x040002a0 + 0x80000) >> 20;
}

s32 func_02002030(s32 arg0) {
*(volatile u16 *)0x04000280=1;
*(volatile s32 *)0x04000290=0;
*(volatile s32 *)0x04000294=0x1000;
*(volatile s32 *)0x04000298=arg0;
arg0=0;
*(volatile s32 *)0x0400029c=arg0;
return arg0;
}

