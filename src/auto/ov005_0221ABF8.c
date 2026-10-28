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

