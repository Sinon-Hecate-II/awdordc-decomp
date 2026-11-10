/* 8 functions from 0x020A94FC to 0x020A9A30 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
#pragma opt_propagation off
void func_020a94fc(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern u8 gSpriteDesc16x16[], gSpriteDesc8x8[];
    s16 func_020a93e4(void *, s32);
    s32 func_020a8c54(s32, s32, s32, s32);
    M2C_UNK func_020a92bc(void *, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    register s32 saved, i;
    register u8 *p = arg0;
    register s32 y, x;
    u16 tile;
    switch (p[4]) {
    default: return;
    case 1: return;
    case 0: break;
    }
    if ((u32)(p[0x20] << 31) >> 31) {
        saved = *(s32 *)(p + 0x1c);
        func_020a92bc(p, 0);
        x = func_020a93e4(p, 0);
        AddSprite((u16)(x & 0x1ff), *(s16 *)(p+8) & 0xff,
            (u16)((0x3ff & (((s32)((u32)(p[0x20]<<27)>>28)*p[0x16]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17)>>30))) |
            ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
            (s32)gSpriteDesc16x16, (u32)(p[0x28]<<27)>>27);
        func_020a92bc(p, saved);
        return;
    }
    if (p[0x29]) p[0xa] = p[0x29];
    for (i=0; i<p[0xa]; i++) {
        x=func_020a93e4(p,(u8)i);
        y=*(s16 *)(p+8);
        if (func_020a8c54(x,y,p[0x14],p[0x15])) {
            if (*(s32 *)(p+0x24)) {
                AddSprite((u16)(x & 0x1ff), y & 0xff,
                    (u16)((0x3ff & ((s32)(u16)(p[0x16]*p[0xb+(u8)i]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))) |
                    ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
                    *(s32 *)(p+0x24), (u32)(p[0x28]<<27)>>27);
            } else {
                AddSprite((u16)(x & 0x1ff), y & 0xff,
                    (u16)((0x3ff & ((s32)(u16)(p[0x16]*p[0xb+(u8)i]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))) |
                    ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
                    (s32)gSpriteDesc8x8, (u32)(p[0x28]<<27)>>27);
            }
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_020a9774(void *arg0, s16 arg1, s16 arg2, s8 arg3, s32 arg4) {
    M2C_UNK func_020a92bc(void *, s32);
    void func_020a94fc(void *);
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
    extern void *gTouchState;
    s16 temp_r4;
    s16 temp_r5;
    u8 temp_ip;
    u8 temp_lr;

    if (M2C_FIELD(arg0, u8 *, 5) == 0) {
        return;
    }
    temp_r4 = M2C_FIELD(gTouchState, s16 *, 0);
    temp_r5 = M2C_FIELD(gTouchState, s16 *, 2);
    if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
        temp_lr = M2C_FIELD(arg0, u8 *, 0x11);
        temp_ip = M2C_FIELD(arg0, u8 *, 0x10);
        if (func_020a8c8c(temp_r4, temp_r5, (s16) (M2C_FIELD(arg0, s16 *, 8) - ((s32) temp_ip >> 1)), (s16) (M2C_FIELD(arg0, s16 *, 0xA) - ((s32) temp_lr >> 1)), (s32) temp_ip, (s32) temp_lr) != 0) {
            M2C_FIELD(arg0, u8 *, 6) = 1U;
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 6) != 0) && (M2C_FIELD(gTouchState, u8 *, 0x16) != 0)) {
        M2C_FIELD(arg0, u8 *, 6) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 6) == 0) {
        return;
    }
    func_020a979c(arg0, temp_r4, temp_r5);
}

void func_020a98c4(void *arg0) {
extern void *gTouchState;
s32 Divide(s32,s32);
s32 func_020a8c8c(s16,s16,s16,s16,s32,s32);
void *child; s16 x,y; s32 n,d,k;
if(M2C_FIELD(arg0,u8 *,5)==0)return;
func_020a97f8(M2C_FIELD(arg0,void **,0x1c));
child=M2C_FIELD(arg0,void **,0x1c);
if(M2C_FIELD(child,u8 *,6)!=0){k=M2C_FIELD(child,s16 *,0xc); n=M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x14); d=(s16)(M2C_FIELD(child,s16 *,0x14)-M2C_FIELD(child,s16 *,0x12)); M2C_FIELD(arg0,s16 *,0x12)=Divide(n*k,d); return;}
x=M2C_FIELD(gTouchState,s16 *,0);y=M2C_FIELD(gTouchState,s16 *,2);
if(M2C_FIELD(gTouchState,u8 *,0x14)!=0){
if(func_020a8c8c(x,y,M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,s16 *,0xa),M2C_FIELD(arg0,u8 *,0xc),M2C_FIELD(arg0,u8 *,0xd))!=0)M2C_FIELD(arg0,u8 *,6)=1;
}
if(M2C_FIELD(arg0,u8 *,6)==0)return;
func_020a979c(M2C_FIELD(arg0,void **,0x1c),x,y);
child=M2C_FIELD(arg0,void **,0x1c);
k=M2C_FIELD(child,s16 *,0xc); n=M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x14); d=(s16)(M2C_FIELD(child,s16 *,0x14)-M2C_FIELD(child,s16 *,0x12)); M2C_FIELD(arg0,s16 *,0x12)=Divide(n*k,d);
if(M2C_FIELD(gTouchState,u8 *,0x16)!=0)M2C_FIELD(arg0,u8 *,6)=0;
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

