/* 2 functions from 0x021EA57C to 0x021EAED0 (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021eaeb0(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
