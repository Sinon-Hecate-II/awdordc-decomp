/* 8 functions from 0x020A94FC to 0x020A9A30 (main), found by ds-decomp. */
#include "common.h"

void func_020a9774(void *arg0, s16 arg1, s16 arg2, s8 arg3, s32 arg4) {
    M2C_UNK func_020a92bc(void *, s32);
    M2C_UNK func_020a94fc(void *);
    M2C_FIELD(arg0, s16 *, 6) = arg1;
    M2C_FIELD(arg0, s16 *, 8) = arg2;
    M2C_FIELD(arg0, s8 *, 0x21) = arg3;
    func_020a92bc(arg0, arg4);
    func_020a94fc(arg0);
}

M2C_UNK func_020a979c(void *arg0, s16 arg1, s16 arg2) {
    s32 x;
    s32 y;
    x = M2C_FIELD(arg0, s16 *, 0x14);
    if (arg1 <= x) {
        x = M2C_FIELD(arg0, s16 *, 0x12);
        if (arg1 >= x) x = arg1;
    }
    M2C_FIELD(arg0, s16 *, 8) = x;
    y = M2C_FIELD(arg0, s16 *, 0x18);
    if (arg2 <= y) {
        y = M2C_FIELD(arg0, s16 *, 0x16);
        if (arg2 >= y) y = arg2;
    }
    M2C_FIELD(arg0, s16 *, 0xA) = y;
    M2C_FIELD(arg0, s16 *, 0xC) = M2C_FIELD(arg0, s16 *, 8) - M2C_FIELD(arg0, s16 *, 0x12);
    M2C_FIELD(arg0, s16 *, 0xE) = M2C_FIELD(arg0, s16 *, 0xA) - M2C_FIELD(arg0, s16 *, 0x16);
}

void func_020a97f8(void *arg0) {
    s32 func_020a8c8c(s16, s16, s16, s16, s32, s32);
    M2C_UNK func_020a979c(void *, s16, s16);
    extern void *data_02101e88;
    s16 temp_r4;
    s16 temp_r5;
    u8 temp_ip;
    u8 temp_lr;

    if (M2C_FIELD(arg0, u8 *, 5) == 0) {
        return;
    }
    temp_r4 = M2C_FIELD(data_02101e88, s16 *, 0);
    temp_r5 = M2C_FIELD(data_02101e88, s16 *, 2);
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        temp_lr = M2C_FIELD(arg0, u8 *, 0x11);
        temp_ip = M2C_FIELD(arg0, u8 *, 0x10);
        if (func_020a8c8c(temp_r4, temp_r5, (s16) (M2C_FIELD(arg0, s16 *, 8) - ((s32) temp_ip >> 1)), (s16) (M2C_FIELD(arg0, s16 *, 0xA) - ((s32) temp_lr >> 1)), (s32) temp_ip, (s32) temp_lr) != 0) {
            M2C_FIELD(arg0, u8 *, 6) = 1U;
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 6) != 0) && (M2C_FIELD(data_02101e88, u8 *, 0x16) != 0)) {
        M2C_FIELD(arg0, u8 *, 6) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 6) == 0) {
        return;
    }
    func_020a979c(arg0, temp_r4, temp_r5);
}

void func_020a98c4(void *arg0) {
extern void *data_02101e88;
s32 func_0207c8ec(s32,s32);
s32 func_020a8c8c(s16,s16,s16,s16,s32,s32);
void *child; s16 x,y; s32 n,d,k;
if(M2C_FIELD(arg0,u8 *,5)==0)return;
func_020a97f8(M2C_FIELD(arg0,void **,0x1c));
child=M2C_FIELD(arg0,void **,0x1c);
if(M2C_FIELD(child,u8 *,6)!=0){k=M2C_FIELD(child,s16 *,0xc); n=M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x14); d=(s16)(M2C_FIELD(child,s16 *,0x14)-M2C_FIELD(child,s16 *,0x12)); M2C_FIELD(arg0,s16 *,0x12)=func_0207c8ec(n*k,d); return;}
x=M2C_FIELD(data_02101e88,s16 *,0);y=M2C_FIELD(data_02101e88,s16 *,2);
if(M2C_FIELD(data_02101e88,u8 *,0x14)!=0){
if(func_020a8c8c(x,y,M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,s16 *,0xa),M2C_FIELD(arg0,u8 *,0xc),M2C_FIELD(arg0,u8 *,0xd))!=0)M2C_FIELD(arg0,u8 *,6)=1;
}
if(M2C_FIELD(arg0,u8 *,6)==0)return;
func_020a979c(M2C_FIELD(arg0,void **,0x1c),x,y);
child=M2C_FIELD(arg0,void **,0x1c);
k=M2C_FIELD(child,s16 *,0xc); n=M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x14); d=(s16)(M2C_FIELD(child,s16 *,0x14)-M2C_FIELD(child,s16 *,0x12)); M2C_FIELD(arg0,s16 *,0x12)=func_0207c8ec(n*k,d);
if(M2C_FIELD(data_02101e88,u8 *,0x16)!=0)M2C_FIELD(arg0,u8 *,6)=0;
}

void func_020a99f4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 5) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s8 *, 5) = 1;
}

void func_020a9a08(void *arg0) {
    M2C_FIELD(arg0, s8 *, 5) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s8 *, 5) = 0;
}

void func_020a9a1c(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x14) = arg1;
    M2C_FIELD(arg0, s16 *, 0x16) = arg2;
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) (arg2 - arg1);
}

