/* 15 functions from 0x021E6E18 to 0x021E771C (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021e6e18(void) {
    void *func_ov003_021e6d6c();
    return M2C_FIELD(func_ov003_021e6d6c(), u8 *, 1);
}

u8 func_ov003_021e6e28(s32 arg0) {
    s32 func_ov003_021e6e08();
    return (u8) (arg0 - func_ov003_021e6e08());
}

u8 func_ov003_021e6e40(void) {
    s32 func_ov003_021f1490();
    u8 var_r0;

    if (func_ov003_021f1490() == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov003_021e6e5c(void) {
    if ((func_ov003_021f1490() == 3) || (func_ov003_021f1490() == 1) || (func_ov003_021f1490() == 5)) {
        return 1;
    }
    return 0;
}

s32 func_ov003_021e6e94(s32 arg0) {
    M2C_UNK func_ov003_021e6cac(s32, M2C_UNK, M2C_UNK);
    extern s32 data_ov003_0220f0c8[][2];
    func_ov003_021e6cac(arg0, 0, 0xD);
    return data_ov003_0220f0c8[arg0][0];
}

s32 func_ov003_021e6eb8(s32 arg0) {
    s32 func_020bf894();
    M2C_UNK func_ov003_022008b8(s32);
    if (arg0 == 0xC) {
        return 1;
    }
    if ((func_ov003_021e6e40() != 0) && (arg0 == 0xB)) {
        return 0;
    }
    func_ov003_022008b8(arg0);
    return func_020bf894();
}

u8 func_ov003_021e73bc(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0x74);
}

u8 func_ov003_021e73c8(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD((arg0 + arg1), u8 *, 0x74) == 0xFF) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021e73e4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 7);
}

s32 func_ov003_021e73ec(s32 arg0, s32 arg1) {
    s32 func_020846a4();
    s32 func_020848c4();
    s32 func_ov003_021e6cfc();
    u8 *temp_r4;
    u8 temp_r5;
    s32 var_r0;
    if (func_020846a4() == 0) return 0;
    temp_r4 = (u8 *)(arg0 + 0x74);
    temp_r5 = temp_r4[arg1];
    if (temp_r5 == func_020848c4()) return 1;
    if (func_ov003_021e6cfc() != 0) {
        if (temp_r4[arg1] == 0xFF) var_r0 = 1;
        else var_r0 = 0;
        if (var_r0 & 0xFF) return 1;
    }
    return 0;
}

u8 func_ov003_021e7450(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 8);
}

void func_ov003_021e7458(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02087db8(void *, M2C_UNK);
    M2C_UNK func_020aad18(void *);
    s32 var_r1;
    s32 count;
    void *temp_r0;
    count = M2C_FIELD(arg0, s8 *, 4);
    temp_r0 = M2C_FIELD(arg0 + arg1 * 4, void **, 0x78);
    if (arg1 < arg2 + count) {
        func_020aad18(temp_r0);
        return;
    }
    temp_r0 = M2C_FIELD(temp_r0, void **, 0x64);
    if (M2C_FIELD(temp_r0, u8 *, 0x12) != 0) var_r1 = 1;
    else var_r1 = 0;
    if (!(var_r1 & 0xFF)) return;
    func_02087db8(temp_r0, 1);
}

s8 func_ov003_021e74a4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 4);
}

