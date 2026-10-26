/* 5 functions from 0x0220856C to 0x02209310 (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_02209258(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 9) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02209274(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 2) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092a8(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 3) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092dc(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 4) result = 1;
 else result = 0;
 return result;
}

