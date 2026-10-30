/* 11 functions from 0x02216518 to 0x022174F4 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_02216518(u32 arg0) {
}

void func_ov005_0221720c(void) {
s32 func_020b2714(void);
void func_020b2738(void);
void func_020842d4(void);
void func_020b2178(void);
void func_020e35cc(void *);
void func_02086658(s32);
void func_02082014(void);
void func_020901e0(s32);
extern M2C_UNK data_ov005_02221304;
if (func_020b2714()) func_020b2738();
func_020842d4();
func_020b2178();
if (M2C_FIELD(&data_ov005_02221304, void **, 8)) {
func_020e35cc(M2C_FIELD(&data_ov005_02221304, void **, 8));
M2C_FIELD(&data_ov005_02221304, void **, 8) = 0;
}
func_02086658(7);
func_02082014();
func_020901e0(4);
}

void func_ov005_02217264(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220510;
    func_01ffa42c(&data_ov005_02220510, arg0);
}

void func_ov005_0221727c(void) {
    M2C_UNK func_02090248(M2C_UNK);
    extern M2C_UNK data_ov005_02221304;
    func_02090248(0xF);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x8E) = -1;
}

void func_ov005_022172a0(void) {
    void func_ov005_02214f80(s16);
    void func_ov005_02214a84(u8);
    extern M2C_UNK data_ov005_02221304;
    s16 val = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x90);
    func_ov005_02214f80(val);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x90) = -1;
    func_ov005_02214a84((u8) M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), u8 *, 0x8A));
}

void func_ov005_022172d8(s16 arg0, s8 arg1) {
void func_01ffa3dc(void *, s32);
s32 func_ov005_02215650(void);
extern M2C_UNK data_ov005_02221304;
extern M2C_UNK data_ov005_022204e0;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x90) = arg0;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s8 *, 0x8a) = arg1;
func_01ffa3dc(&data_ov005_022204e0, func_ov005_02215650());
}

void func_ov005_0221730c(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_ov005_022208e0;
    func_0200bc5c(&data_ov005_022208e0);
}

u8 func_ov005_02217320(void) {
    extern u8 *data_ov005_02221310;
    return *data_ov005_02221310;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov005_02217334(s16 arg0) { extern u8 *data_ov005_02221310; s32 i=0; void *p; u32 f,word; M2C_FIELD(data_ov005_02221310,s16 *,0x12)=arg0; do { if(i==arg0){p=M2C_FIELD(data_ov005_02221310,void **,0x2c+i*4); f=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28); word=M2C_FIELD(p,u32 *,0x40); f++; } else { p=M2C_FIELD(data_ov005_02221310,void **,0x2c+i*4); f=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28); word=M2C_FIELD(p,u32 *,0x40); } M2C_FIELD(p,u32 *,0x40)=(word&~0x3fc0000)|((u32)(((u16)f)<<24)>>6); i++; } while(i<4); }
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov005_022173b4(void) {
    void func_02098ac0(s32, s32, s32, s32);
    void func_02098a34(s32, s32, s32, s32, u8);
    extern u8 *data_ov005_02221310;
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00c4;
    void *saved = gCur3DSpriteEngine;
    s32 value = M2C_FIELD(data_ov005_02221310, s16 *, 0x10);

    gCur3DSpriteEngine = data_027e00c8;
    func_02098ac0(value, 0, (u16)(M2C_FIELD(data_ov005_02221310, s16 *, 0x10) - 1), 0);
    gCur3DSpriteEngine = data_027e00c4;
    func_02098a34(value, 8, 2, 0, 0);
    gCur3DSpriteEngine = saved;
    func_ov005_0221730c();
}

void func_ov005_02217440(void) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    void func_020e3004();
    void *func_020e3018(s32);
    s32 func_020e3218(M2C_UNK *);
    u32 func_020bf894(s32);
    void func_ov005_0221730c(void);
    extern u8 *data_ov005_02221310;
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    extern M2C_UNK data_ov005_022208f4;
    void *temp_r5;
    void *saved;

    temp_r5 = func_020e3018(M2C_FIELD(data_ov005_02221310, s16 *, 0x10));
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (func_020bf894(M2C_FIELD(data_ov005_02221310, s16 *, 0x10))) {
        func_020e3004();
        func_020e3218(&data_ov005_022208f4);
        func_020814e4();
        func_02081590(func_020e3218(temp_r5), M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2800);
        func_02081528();
        func_ov005_0221730c();
    } else {
        func_02007e98(0, M2C_FIELD(data_027e00c4, s32 *, 0x1C) + 0x2800, 0x800);
    }
    gCur3DSpriteEngine = saved;
}

