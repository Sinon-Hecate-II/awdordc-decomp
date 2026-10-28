/* 2 functions from 0x02215664 to 0x02216518 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_02215664(void *arg0) {
}

void func_ov005_02216498(void) {
    M2C_UNK func_020b1bf4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020b1c78(M2C_UNK);
    M2C_UNK func_020b2224();
    M2C_UNK func_020b22a4(M2C_UNK, s32, M2C_UNK *, s32);
    extern M2C_UNK data_ov005_02220490;
    extern M2C_UNK data_ov005_022204b8;
    s32 var_r8;
    s32 var_r9;

    func_020b2224();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    var_r8 = 0;
    var_r9 = 0x18;
    do {
        func_020b22a4(4, var_r9, &data_ov005_02220490, var_r8);
        func_020b22a4(0xE0, var_r9, &data_ov005_022204b8, var_r8);
        var_r8 += 1;
        var_r9 += 0x10;
    } while (var_r8 < 6);
    func_020b1c78(0);
}
