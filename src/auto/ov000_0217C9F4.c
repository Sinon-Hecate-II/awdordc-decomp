/* 7 functions from 0x0217C9F4 to 0x0217D86C (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0217d3b8(s32 arg0) {
    s32 func_ov000_021a8ac8(void *);
    extern void **data_027e0058;
    void *unit;
    if (arg0 != 3) return;
    unit = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) < 0x3DU) return;
    if (func_ov000_021a8ac8(unit) != 1) return;
    unit = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u8 *, 0xB) << 28) >> 28) == 0) {
        M2C_FIELD(unit, u8 *, 0xB) |= 0x20;
    }
}

void func_ov000_0217d850(void) {
    extern void *data_ov000_021df580;
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) & ~8);
}
