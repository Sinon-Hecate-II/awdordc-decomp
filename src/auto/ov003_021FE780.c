/* 9 functions from 0x021FE780 to 0x021FF3D4 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021fef18(void) {
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    extern M2C_UNK data_ov003_0220ff2c;
    void *temp_r0;

    temp_r0 = func_01ffa770(&data_ov003_0220ff2c);
    if (temp_r0 == NULL) {
        return;
    }
    func_02007f8c(M2C_FIELD(temp_r0, s32 *, 0x44) + 0x186C, 0, 0xD);
    func_ov003_021f92f4(temp_r0, 0);
}

s32 func_ov003_021ff330(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_021ff344(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_021ff358(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_021ff36c(void) {
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220fe1c;
    void *temp_r0;

    temp_r0 = func_01ffa770(&data_ov003_0220fe1c);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
    func_ov003_021f92f4(temp_r0, 0);
}

void func_ov003_021ff3ac(void) {
    extern M2C_UNK data_ov003_0220fe1c;
    void *temp_r0;
    temp_r0 = func_01ffa770(&data_ov003_0220fe1c);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(*(void **)temp_r0, void (**)(void *), 0x10)(temp_r0);
}

