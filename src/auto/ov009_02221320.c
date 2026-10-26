/* 15 functions from 0x02221320 to 0x022222D0 (ov009), found by ds-decomp. */
#include "common.h"

void func_ov009_02221320(void) {
    M2C_UNK func_ov009_02224184();
    func_ov009_02224184();
}

void func_ov009_0222132c(void) {
    M2C_UNK func_020e3580();
    func_020e3580();
}

void func_ov009_02221338(s32 arg0, s32 arg1) {
    M2C_UNK func_020e35cc();
    if (arg0 == 0) {
        return;
    }
    func_020e35cc();
}

void func_ov009_0222134c(void *arg0) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x16);
    M2C_FIELD(arg0, s8 *, 0x16) = 0;
    M2C_FIELD(arg0, s8 *, 0x17) = -1;
    M2C_FIELD(arg0, s8 *, 0x18) = -1;
    M2C_FIELD(arg0, s8 *, 0x19) = -2;
    M2C_FIELD(arg0, s8 *, 0x1A) = -2;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = -1;
    func_02007f8c(arg0 + 0x20, 0, 0x40);
}

void *func_ov009_0222139c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x16) = 0;
    M2C_FIELD(arg0, s8 *, 0x17) = -1;
    M2C_FIELD(arg0, s8 *, 0x18) = -1;
    M2C_FIELD(arg0, s8 *, 0x19) = -2;
    M2C_FIELD(arg0, s8 *, 0x1A) = -2;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1D) = -1;
    func_02007f8c(arg0, 0, 0x16);
    func_02007f8c(arg0 + 0x20, 0, 0x40);
    return arg0;
}

void func_ov009_022213f0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007e20(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007e20(arg1, arg0, 0x14);
}

void func_ov009_0222140c(s32 arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_02008048();
    func_02008048(arg1, arg0 + 0x20, arg2);
}

void func_ov009_02221538(void *arg0) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_ov009_02223a90(void *);
    extern M2C_UNK data_ov009_02226638;
    void *temp_r0;

    temp_r0 = func_01ffa770(&data_ov009_02226638);
    if (temp_r0 != NULL) {
        if ((M2C_FIELD(arg0, u16 *, 0xA) == 4) && (M2C_FIELD(arg0, u16 *, 2) == 0xF)) {
            M2C_FIELD(temp_r0, u16 *, 0x46) = 0U;
        } else {
            M2C_FIELD(temp_r0, u16 *, 0x46) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
        }
    }
    func_ov009_02223a90(arg0);
}

void func_ov009_02221580(void *arg0) {
    func_ov009_02221338(M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

void func_ov009_02221a94(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_ov009_02224d1c(s32);
    s32 var_r2;

    var_r2 = 0;
loop_1:
    if ((M2C_FIELD(arg0, u16 *, 0x44) & (1 << var_r2)) && (M2C_FIELD(arg0, u16 *, 0x46) & (1 << var_r2))) {
        return;
    }
    var_r2 += 1;
    if (var_r2 >= 4) {
        func_ov009_02224d1c(M2C_FIELD(arg0, s32 *, 0x3C));
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x40) = 0;
        func_01ffa6fc(arg0);
        return;
    }
    goto loop_1;
}

void func_ov009_02222278(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(M2C_UNK, s32);
    extern M2C_UNK data_ov009_02226b40;
    func_02008048(arg1, (arg0 * 0x60) + (s32) &data_ov009_02226b40);
}

s32 func_ov009_0222229c(s32 arg0, s32 arg1) {
    s32 func_ov009_02224194();
    switch (func_ov009_02224194()) {
    case 8:
    case 9:
        return 0;
    default:
        return arg1 != func_ov009_02224194();
    }
}

