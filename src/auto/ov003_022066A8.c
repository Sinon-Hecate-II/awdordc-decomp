/* 2 functions from 0x022066A8 to 0x022066D8 (ov003), found by ds-decomp. */
#include "common.h"

void *func_ov003_022066a8(s32 arg0) {
    extern u8 data_ov003_0220f21d;
    extern u8 data_ov003_0220f238;
    return &data_ov003_0220f21d + (&data_ov003_0220f238)[arg0 * 0x10] * 5;
}

u8 func_ov003_022066c8(s32 arg0) {
    extern u8 data_ov003_0220f239;
    return (&data_ov003_0220f239)[arg0 * 0x10];
}
