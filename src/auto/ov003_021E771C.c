/* 5 functions from 0x021E771C to 0x021E8654 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e771c(void *arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

void func_ov003_021e82f0(s32 arg0, s32 arg1, s8 arg2) {
    M2C_FIELD((arg0 + arg1), s8 *, 0xA) = arg2;
}

u8 func_ov003_021e82fc(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0xA);
}

s32 func_ov003_021e8308(void *arg0) {
    u8 i;
    s32 entry;
    s32 count;
    i = 0;
    count = M2C_FIELD(arg0, s8 *, 4) - 1;
    for (; i < count; i++) {
        entry = (s32)arg0 + i * 0x18;
        if (M2C_FIELD(entry, s32 *, 0x18) != M2C_FIELD(entry, s32 *, 0x30)) return 1;
    }
    return 0;
}

void func_ov003_021e8354(s32 arg0, s32 arg1, s32 arg2) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
}

