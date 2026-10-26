/* 9 functions from 0x02226214 to 0x022262EC (ov009), found by ds-decomp. */
#include "common.h"

void func_ov009_02226214(M2C_UNK arg0) {
    s32 func_0206527c(s32, s32, M2C_UNK);
    s32 func_ov009_02224064();
    s32 func_ov009_022240ac();
    s32 func_ov009_02224194();
    M2C_UNK func_ov009_02225450();
    M2C_UNK func_ov009_022257ac(M2C_UNK);
    s32 temp_r4;

    if ((func_ov009_02224194() != 4) && (func_ov009_02224194() != 5)) {
        return;
    }
    temp_r4 = func_ov009_02224064();
    func_ov009_02225450();
    if (func_0206527c(temp_r4, func_ov009_022240ac(), 0x60) == 0) {
        return;
    }
    func_ov009_022257ac(arg0);
}

void func_ov009_02226268(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_02226728;
    extern M2C_UNK data_ov009_0222675c;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov009_0222675c, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_02226728;
    }
}

void func_ov009_02226290(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov009_0222675c;
    func_01ffa9e4(&data_ov009_0222675c);
}

s32 func_ov009_022262a4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_022262b8(void) {

}

s32 func_ov009_022262bc(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov009_022262d0(void) {

}

void func_ov009_022262d4(void) {

}

s32 func_ov009_022262d8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

