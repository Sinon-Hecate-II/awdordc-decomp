/* 4 functions from 0x02099B18 to 0x02099E6C (main), found by ds-decomp. */
#include "common.h"

u8 func_02099dcc(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 var_r0;

    if (func_02099b18(arg0, 5, 1) != 0) {
        return 0U;
    }
    if (func_02099b18(arg0, 6, 1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02099e10(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 value;
    temp_r0 = (void *)func_02099b18(arg0, 0x15, 1);
    if (temp_r0 != NULL) {
        value = M2C_FIELD(temp_r0, u8 *, 1);
        if (value == 0x80) return 0;
        if (value == 0x81) return 1;
        if (value == 0x82) return 2;
    }
    return 1;
}

void func_02099e58(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x55) = 0;
    M2C_FIELD(arg0, s8 *, 0x54) = -2;
}
