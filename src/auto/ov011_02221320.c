/* 9 functions from 0x02221320 to 0x02222204 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_02221320(void *arg0, s32 arg1) {
    extern M2C_UNK data_ov011_02228294;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov011_02228294;
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
}

void func_ov011_02221334(void) {

}

s32 func_ov011_02221338(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov011_0222134c(void) {
    M2C_UNK func_020822b8(u16 *);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov011_02227f08;
    typedef struct { u16 a, b, c, d, e, f; } T;
    T first;
    T second;
    s32 temp_r4;
    first = M2C_FIELD(&data_ov011_02227f08, T *, 0x12);
    temp_r4 = gCur3DSpriteEngine;
    second = M2C_FIELD(&data_ov011_02227f08, T *, 6);
    gCur3DSpriteEngine = data_027e00c8;
    func_020822b8((u16 *)&first);
    gCur3DSpriteEngine = data_027e00c4;
    func_020822b8((u16 *)&second);
    gCur3DSpriteEngine = temp_r4;
}

void func_ov011_0222161c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0) {
        M2C_FIELD(arg0, s16 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x39) = 0;
        M2C_FIELD(arg0, s8 *, 0x36) = 0;
        M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
        M2C_FIELD(arg0, u8 *, 0x38) = 1U;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x34) = 0x20;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
    M2C_FIELD(arg0, u8 *, 0x38) = 2U;
}

void func_ov011_0222166c(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 temp_r1;
    if (M2C_FIELD(arg0, u8 *, 0x39) == 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_r1 == 1) {
            M2C_FIELD(arg0, u8 *, 0x38) = 2;
            M2C_FIELD(arg0, s16 *, 0x34) = 0x10;
            func_01ffa8c4(arg0, 2);
            return;
        }
        if (temp_r1 != 2) {
            M2C_FIELD(arg0, u8 *, 0x38) = 1;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x38) = 3;
        func_01ffa8c4(arg0, 6);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 2) return;
    func_01ffa8c4(arg0, 4);
}

