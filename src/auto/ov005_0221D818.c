/* 10 functions from 0x0221D818 to 0x0221E5A0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221e1b8(void) {
    M2C_UNK func_ov005_0221caa0();
    func_ov005_0221caa0();
}

void func_ov005_0221e1c4(void) {
    M2C_UNK func_ov005_0221cff8();
    func_ov005_0221cff8();
}

void func_ov005_0221e1d0(void) {
    M2C_UNK func_ov005_0221d160();
    func_ov005_0221d160();
}

void func_ov005_0221e1dc(void) {
    M2C_UNK func_01ffaa8c();
    func_01ffaa8c();
}

void func_ov005_0221e1e8(void) {
    M2C_UNK func_ov005_0221d818();
    func_ov005_0221d818();
}

void func_ov005_0221e1f4(M2C_UNK arg0) {
    M2C_UNK func_02086344();
    M2C_UNK func_02095ff8(M2C_UNK);
    M2C_UNK func_ov005_02218fd0(M2C_UNK);
    func_02095ff8(3);
    func_02086344();
    func_ov005_02218fd0(arg0);
}

void func_ov005_0221e214(void) {
    M2C_UNK func_02095fd4();
    M2C_UNK func_02086370();
    func_020ab200();
    func_0209bf7c();
    func_02095fd4();
    func_02086370();
}

/* Initializes ov005's scene state when the system is ready and the global mode is not state 1. */
void func_ov005_0221e468(M2C_UNK arg0) {
    M2C_UNK func_01ff85b8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff9ce8(M2C_UNK);
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02082134(M2C_UNK, M2C_UNK);
    s32 func_020cd1e4();
    s32 func_020e3218(M2C_UNK *);
    extern u16 data_02168f14;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220a2c;
    extern M2C_UNK data_ov005_02220a90;
    extern M2C_UNK data_ov005_02220bf0;
    extern M2C_UNK data_ov005_02220e30;
    extern M2C_UNK data_ov005_02220ebc;
    extern M2C_UNK data_ov005_02220f7c;
    s32 flag;
    void *result;
    void *savedPtr;

    if (func_020cd1e4() == 0) {
        return;
    }
    if (((u32) (data_02168f14 << 0x1D) >> 0x1D) != 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (!(flag & 0xFF)) {
        return;
    }
    result = func_01ffa42c(&data_ov005_02220bf0, arg0);
    if (result == NULL) {
        return;
    }
    M2C_FIELD(result, M2C_UNK **, 0) = &data_ov005_02220f7c;
    func_0200bc5c(&data_ov005_02220a2c);
    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_02082134(2, 1);
    func_01ff9ce8(2);
    func_020e3218(&data_ov005_02220ebc);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov005_02220a90), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    func_02081590(func_020e3218(&data_ov005_02220e30), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
    func_02081528();
    func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x800, 0x2000);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    gCur3DSpriteEngine = savedPtr;
    M2C_FIELD(result, s32 *, 0x34) = 0;
    M2C_FIELD(result, s32 *, 0x3C) = 0;
    M2C_FIELD(result, s32 *, 0x40) = 0;
    M2C_FIELD(result, s32 *, 0x44) = 0;
    M2C_FIELD(result, s32 *, 0x38) = -0x100;
}

