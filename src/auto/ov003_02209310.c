/* 3 functions from 0x02209310 to 0x02209D0C (ov003), found by ds-decomp. */
#include "common.h"

s32 func_ov003_02209cc8(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), u8 *, 6) | M2C_FIELD(arg0, u8 *, 6);
}

u32 func_ov003_02209cdc(void *arg0) {
    M2C_UNK func_ov003_0220adb4(void *);
    u32 func_ov003_0220c10c(void *);
    M2C_UNK func_ov003_0220c43c();
    u32 temp_r0;

    func_ov003_0220c43c();
    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x38) << 0x1B) >> 0x1F;
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_ov003_0220adb4(arg0);
    return func_ov003_0220c10c(arg0);
}

