/* 7 functions from 0x0216ABA8 to 0x0216B898 (ov000), found by ds-decomp. */
#include "common.h"

u8 *func_ov000_0216b074(u8 *arg0) {
    while (*arg0 != 0x17 && *arg0 != 0x18 && *arg0 != 0x19) {
        if (*arg0 == 0x22) {
            return arg0;
        }
        arg0 += 8;
    }
    return arg0;
}

#pragma optimize_ifs off
void *func_ov000_0216b0c8(void) {
    void *func_020a8b0c(u16);
    s32 func_020cd6d4();
    extern s32 *gCurrentMap;
    void *result;
    switch (func_020cd6d4()) {
    case 0: result = NULL; break;
    default: result = func_020a8b0c(M2C_FIELD((*gCurrentMap + 0x5120), u16 *, 0x22)); break;
    }
    return result;
}
s32 func_ov000_0216b104(void) {
    s32 func_ov000_0216aba8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *temp_r0 = func_ov000_0216b0c8();
    if (temp_r0 == NULL) return 0;
    switch (M2C_FIELD(temp_r0, s32 *, 0x28)) {
    case 0: return 0;
    default: return func_ov000_0216aba8(M2C_FIELD(temp_r0, s32 *, 0x28), 0, 0, 0, 0);
    }
}
#pragma optimize_ifs reset
s32 func_ov000_0216b154(void) {
    return 0;
}

s32 func_ov000_0216b15c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

