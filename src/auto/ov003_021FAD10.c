/* 2 functions from 0x021FAD10 to 0x021FBCF8 (ov003), found by ds-decomp. */
#include "common.h"

u16 func_ov003_021fbcd8(void *arg0, s32 arg1) {
    s32 func_ov003_02200bd0(u8);
    return (u16) (func_ov003_02200bd0(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x44) + (arg1 << 9)), u8 *, 0x22C)) * 0x10);
}
