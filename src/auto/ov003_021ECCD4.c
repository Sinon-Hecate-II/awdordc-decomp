/* 6 functions from 0x021ECCD4 to 0x021ED8F0 (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021ed8a8(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 5) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021ed8c4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 5);
}

u8 func_ov003_021ed8cc(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 6) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021ed8e8(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 6);
}

