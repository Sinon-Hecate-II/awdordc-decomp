/* 14 functions from 0x0221ABF8 to 0x0221BB70 (ov005), found by ds-decomp. */
#include "common.h"

M2C_UNK func_ov005_0221abf8(void *arg0) { (void)arg0; return 0; }

void func_ov005_0221b000(void) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_020aad18(s32);
    extern M2C_UNK data_ov005_02220d50;
    func_020aad18(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38));
}

void func_ov005_0221b01c(void *arg0) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_02087db8(void *, s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    extern M2C_UNK data_ov005_02220d50;
    void *object;
    u8 active;
    if (!(*data_02101e84 & 1)) return;
    func_0208fe30(0x1000D);
    object = M2C_FIELD(M2C_FIELD(func_01ffa770(&data_ov005_02220d50), void **, 0x38), void **, 0x64);
    active = M2C_FIELD(object, u8 *, 0x12) != 0;
    if (active) func_02087db8(object, 1);
    func_01ffa6fc(arg0);
}

void func_ov005_0221b088(void *arg0) {
    M2C_UNK func_01ff9ce8(s32);
    M2C_UNK func_01ffa574(void *);
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(arg0, s32 *, 0x34) += 1;
    M2C_FIELD(arg0, s32 *, 0x38) = func_0207ca38(1, 0, 0x100, M2C_FIELD(arg0, s32 *, 0x34), 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x20) return;
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa574(arg0);
}

M2C_UNK func_ov005_0221b114(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern u8 data_027e0084[];
    M2C_UNK func_0207c964(s32, s32, s32 *, s32 *);
    M2C_UNK func_01ffaacc(u16, u16, u16, void *, s32);

    s32 sp24, sp20;
    s32 sp1c, sp18;
    s32 sp14, sp10;
    s32 spc, sp8;
    s32 xbase;
    u16 engine0;
    s32 shift, adjust, tile;

    M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x3C) = (u16)(-M2C_FIELD(arg0, s32 *, 0x38));

    xbase = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    sp24 = M2C_FIELD(arg0, s32 *, 0x3C);
    sp20 = 0;
    func_0207c964(sp24, 10, &sp24, &sp20);
    engine0 = M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x0);
    shift = ((u32)(engine0 << 17)) >> 30;
    adjust = 0x3ff & (0x140 >> shift);
    tile = ((sp20 & 0x3ff) + adjust) | 0x6000;
    func_01ffaacc((u16)xbase, (u16)0x12, (u16)tile, data_027e0084, 0);

    xbase = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    sp1c = M2C_FIELD(arg0, s32 *, 0x40);
    sp18 = 0;
    func_0207c964(sp1c, 10, &sp1c, &sp18);
    engine0 = M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x0);
    shift = ((u32)(engine0 << 17)) >> 30;
    adjust = 0x3ff & (0x140 >> shift);
    tile = ((sp18 & 0x3ff) + adjust) | 0x7000;
    func_01ffaacc((u16)xbase, (u16)0x26, (u16)tile, data_027e0084, 0);

    xbase = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    sp14 = M2C_FIELD(arg0, s32 *, 0x44);
    sp10 = 0;
    func_0207c964(sp14, 10, &sp14, &sp10);
    engine0 = M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x0);
    shift = ((u32)(engine0 << 17)) >> 30;
    adjust = 0x3ff & (0x140 >> shift);
    tile = ((sp10 & 0x3ff) + adjust) | 0x8000;
    func_01ffaacc((u16)xbase, (u16)0x3a, (u16)tile, data_027e0084, 0);

    xbase = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    spc = M2C_FIELD(arg0, s32 *, 0x3C) + M2C_FIELD(arg0, s32 *, 0x40) + M2C_FIELD(arg0, s32 *, 0x44);
    sp8 = 0;
    func_0207c964(spc, 10, &spc, &sp8);
    engine0 = M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x0);
    shift = ((u32)(engine0 << 17)) >> 30;
    adjust = 0x3ff & (0x140 >> shift);
    tile = ((sp8 & 0x3ff) + adjust) | 0x9000;
    func_01ffaacc((u16)xbase, (u16)0x50, (u16)tile, data_027e0084, 0);
}

void func_ov005_0221b424(void) {
    M2C_UNK func_ov005_0221ab98();
    func_ov005_0221ab98();
}

void func_ov005_0221b430(void) {
    M2C_UNK func_ov005_0221abf8();
    func_ov005_0221abf8();
}

void func_ov005_0221b43c(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_01ffaa5c(s32);
    s32 func_01ffaa7c();
    extern M2C_UNK data_ov005_02220b00;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fb8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov005_02220b00, func_01ffaa7c());
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    func_01ffaa5c(arg0);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0x20;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) M2C_FIELD(func_01ffa770(&data_ov005_02220d50), s32 *, 0x38);
}

void func_ov005_0221b4a8(void) {
    void func_ov005_0221b000(void);
    func_ov005_0221b000();
}

void func_ov005_0221b4b4(void) {
    void func_ov005_0221b01c();
    func_ov005_0221b01c();
}

void func_ov005_0221b4c0(void) {
    void func_ov005_0221b088();
    func_ov005_0221b088();
}

void func_ov005_0221b4cc(void) {
    M2C_UNK func_ov005_0221b114();
    func_ov005_0221b114();
}

s32 func_ov005_0221b4d8(void *arg0) {
    (void)arg0;
    return 0;
}

void func_ov005_0221b854(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_01ffa730(void *);
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_020cd1e4();
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_0215c340;
    extern u16 **data_027e01d8;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    u16 *sp4;
    s32 temp_r0;
    s32 var_r0;
    s32 temp_r0_3;
    u16 *temp_r0_2;
    u16 *temp_r1;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    u16 *temp_r1_9;
    u16 *temp_r2;

    if (func_020cd1e4() == 0) {
        var_r0 = 0;
    } else if (*(&data_0215c340 + (M2C_FIELD(&data_0215c334, u8 *, 4) * 0xC)) == 0) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
    }
    if (var_r0 == 0) {
        func_01ffa730(arg0);
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x34) + 1;
    M2C_FIELD(arg0, s32 *, 0x34) = temp_r0;
    if (temp_r0 == 1) {
        temp_r1 = *data_027e01d8;
        sp3C = temp_r1;
        *temp_r1 = *sp3C | 0x20;
        temp_r1_2 = *data_027e01d8;
        sp38 = temp_r1_2 + 0x12;
        M2C_FIELD(temp_r1_2, s16 *, 0x12) = (s16) ((*sp38 & ~0xC0) | 0x40);
        temp_r1_3 = *data_027e01d8;
        sp34 = temp_r1_3 + 0x12;
        M2C_FIELD(temp_r1_3, s16 *, 0x12) = (s16) (*sp34 & ~1);
        temp_r1_4 = *data_027e01d8;
        sp30 = temp_r1_4 + 0x12;
        M2C_FIELD(temp_r1_4, s16 *, 0x12) = (s16) (*sp30 | 2);
        temp_r1_5 = *data_027e01d8;
        sp2C = temp_r1_5 + 0x12;
        M2C_FIELD(temp_r1_5, s16 *, 0x12) = (s16) (*sp2C & ~4);
        temp_r1_6 = *data_027e01d8;
        sp28 = temp_r1_6 + 0x12;
        M2C_FIELD(temp_r1_6, s16 *, 0x12) = (s16) (*sp28 & ~8);
        temp_r1_7 = *data_027e01d8;
        sp24 = temp_r1_7 + 0x12;
        M2C_FIELD(temp_r1_7, s16 *, 0x12) = (s16) (*sp24 & ~0x10);
        temp_r1_8 = *data_027e01d8;
        sp20 = temp_r1_8 + 0x12;
        M2C_FIELD(temp_r1_8, s16 *, 0x12) = (s16) (*sp20 & ~0x20);
        temp_r1_9 = *data_027e01d8;
        sp1C = temp_r1_9 + 0x12;
        M2C_FIELD(temp_r1_9, s16 *, 0x12) = (s16) (*sp1C & ~0x100);
        temp_r1_10 = *data_027e01d8;
        sp18 = temp_r1_10 + 0x12;
        M2C_FIELD(temp_r1_10, s16 *, 0x12) = (s16) (*sp18 & ~0x200);
        temp_r1_11 = *data_027e01d8;
        sp14 = temp_r1_11 + 0x12;
        M2C_FIELD(temp_r1_11, s16 *, 0x12) = (s16) (*sp14 & ~0x400);
        temp_r1_12 = *data_027e01d8;
        sp10 = temp_r1_12 + 0x12;
        M2C_FIELD(temp_r1_12, s16 *, 0x12) = (s16) (*sp10 | 0x800);
        temp_r1_13 = *data_027e01d8;
        spC = temp_r1_13 + 0x12;
        M2C_FIELD(temp_r1_13, s16 *, 0x12) = (s16) (*spC | 0x1000);
        temp_r0_2 = *data_027e01d8;
        sp8 = temp_r0_2 + 0x12;
        M2C_FIELD(temp_r0_2, s16 *, 0x12) = (s16) (*sp8 & ~0x2000);
    }
    temp_r0_3 = func_0207ca38(0, 0, 0x10, M2C_FIELD(arg0, s32 *, 0x34), 0x10);
    M2C_FIELD(*data_027e01d8, s8 *, 0x51) = (s8)temp_r0_3;
    M2C_FIELD(*data_027e01d8, s8 *, 0x52) = (s8) (0x10 - temp_r0_3);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x10) {
        return;
    }
    temp_r2 = *data_027e01d8;
    sp4 = temp_r2 + 0x12;
    M2C_FIELD(temp_r2, s16 *, 0x12) = (s16) (*sp4 & ~0xC0);
    M2C_FIELD(*data_027e01d8, s8 *, 0x51) = 0;
    M2C_FIELD(*data_027e01d8, s8 *, 0x52) = 0;
    M2C_FIELD(*data_027e01d8, s8 *, 0x53) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa6fc(arg0);
}

