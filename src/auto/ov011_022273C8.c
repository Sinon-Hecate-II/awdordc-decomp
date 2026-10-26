/* 6 functions from 0x022273C8 to 0x02227F08 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_02227e88(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) <= 0x2A80U) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov011_02227ea4(M2C_UNK arg0) {
    extern M2C_UNK data_ov011_02228b1c;
    extern M2C_UNK data_ov011_02228a48;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov011_02228a48, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov011_02228b1c;
    }
}

void func_ov011_02227ecc(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov011_02225684();
    extern M2C_UNK data_ov011_02228a78;
    if (func_01ffa42c(&data_ov011_02228a78, arg0) == 0) {
        return;
    }
    func_ov011_02225684();
}

void func_ov011_02227ef0(void) {

}

s32 func_ov011_02227ef4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

