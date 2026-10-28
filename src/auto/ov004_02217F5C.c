/* 6 functions from 0x02217F5C to 0x02218BAC (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_022188b8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov004_022188c4(void *a){extern void **gCurrentMap;extern u32 data_0215d8a0[2];func_0208fe30(0x10014);data_0215d8a0[1]=(data_0215d8a0[1]&~0xffff)|(u16)(M2C_FIELD(*gCurrentMap,u16 *,0x5142)-0xa1);if(func_020a8958(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))func_01ffa8c4(a,7);M2C_FIELD(a,u8 *,0x38)=2;M2C_FIELD(a,u8 *,0x36)=0;}

void func_ov004_02218950(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, u8, s32);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
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
    s8 temp_r0;
    void **temp_r1;
    void *temp_r0_10;
    void *temp_r0_11;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r0_8;
    void *temp_r0_9;
    void *temp_r2;

    M2C_FIELD(arg0, u8 *, 0x36) = (u8) (M2C_FIELD(arg0, u8 *, 0x36) + 1);
    temp_r0 = func_0207ca38(0, 0, 8, M2C_FIELD(arg0, u8 *, 0x36), 0x10);
    temp_r1 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    temp_r2 = *data_027e00c8;
    sp2C = temp_r2 + 0x12;
    *sp2C = (s16) ((*sp2C & ~0xC0) | 0xC0);
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x51) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x52) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x53) = temp_r0;
    temp_r0_2 = *gCur3DSpriteEngine;
    sp28 = temp_r0_2 + 0x12;
    *sp28 = (s16) ((*sp28 & ~1) | 1);
    temp_r0_3 = *gCur3DSpriteEngine;
    sp24 = temp_r0_3 + 0x12;
    *sp24 = (s16) (*sp24 | 2);
    temp_r0_4 = *gCur3DSpriteEngine;
    sp20 = temp_r0_4 + 0x12;
    *sp20 = (s16) (*sp20 | 4);
    temp_r0_5 = *gCur3DSpriteEngine;
    sp1C = temp_r0_5 + 0x12;
    *sp1C = (s16) (*sp1C | 8);
    temp_r0_6 = *gCur3DSpriteEngine;
    sp18 = temp_r0_6 + 0x12;
    *sp18 = (s16) (*sp18 | 0x10);
    temp_r0_7 = *gCur3DSpriteEngine;
    sp14 = temp_r0_7 + 0x12;
    *sp14 = (s16) (*sp14 & ~0x100);
    temp_r0_8 = *gCur3DSpriteEngine;
    sp10 = temp_r0_8 + 0x12;
    *sp10 = (s16) (*sp10 & ~0x200);
    temp_r0_9 = *gCur3DSpriteEngine;
    spC = temp_r0_9 + 0x12;
    *spC = (s16) (*spC & ~0x400);
    temp_r0_10 = *gCur3DSpriteEngine;
    sp8 = temp_r0_10 + 0x12;
    *sp8 = (s16) (*sp8 & ~0x800);
    temp_r0_11 = *gCur3DSpriteEngine;
    sp4 = temp_r0_11 + 0x12;
    *sp4 = (s16) (*sp4 & ~0x1000);
    gCur3DSpriteEngine = temp_r1;
    if ((u32) M2C_FIELD(arg0, u8 *, 0x36) < 0x10U) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov004_02218b7c(M2C_UNK arg0) {
    M2C_UNK func_ov003_021ff3ac();
    M2C_UNK func_ov004_02213124(M2C_UNK);
    func_ov003_021ff3ac();
    func_ov004_02213124(arg0);
}

void func_ov004_02218b94(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_0223c684;
    func_01ffa42c(&data_ov004_0223c684, arg0);
}

