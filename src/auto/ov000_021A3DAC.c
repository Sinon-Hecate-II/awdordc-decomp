/* 17 functions from 0x021A3DAC to 0x021A4A98 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_021a4320(void) {
    s32 func_ov000_021a3210();
    s32 func_ov000_021a3364();
    s32 func_ov000_021a3c84();
    s32 func_ov000_021a41f8();
    u8 func_ov000_021a88c8(s32);
    extern void *data_ov000_021df578;
    u8 var_r0;
    u8 temp;

    M2C_FIELD(data_ov000_021df578, u8 *, 8) = func_ov000_021a88c8(1);
    temp = func_ov000_021a88c8(2);
    M2C_FIELD(data_ov000_021df578, u8 *, 8) += temp;
    if (func_ov000_021a3210() == 1) {
        return 1U;
    }
    if (func_ov000_021a41f8() == 1) {
        return 1U;
    }
    if (func_ov000_021a3c84() == 1) {
        return 1U;
    }
    if (func_ov000_021a3364() == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a43a0(s32 arg0) {
    extern void *data_ov000_021df57c;
    u8 var_r0;

    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11) & arg0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a43c4(void) {
    extern void *data_ov000_021df57c;
    u8 var_r0;

    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11) & 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a43e8(s32 arg0) {
    s32 func_ov000_021a98a8();
    if ((func_ov000_021a98a8() != 0) || (arg0 == 4)) {
        return 1;
    }
    return 0;
}

s32 func_ov000_021a4414(void) {
    s32 func_ov000_021a43e8(s32);
    s32 func_ov000_021a98e4(s32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    s32 count7 = 0;
    s32 count8 = 0;
    void *base = *data_027e0058;
    u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
    s32 i;
    s32 idx;
    u8 *entries;

    i = start + 1;
    if (i < (s32)(start + 0x33)) {
        idx = i * 0xE;
        entries = (u8 *)base + 0x59A4;
        do {
            if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0) {
                if (func_ov000_021a43e8(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                    if (data_ov000_021b5bfc[((u32)((entries[idx]) << 0x1A) >> 0x1A) * 0x70 + 0x13] & 7) {
                        if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                            count7 += 1;
                        }
                        if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 1) {
                            count8 += 1;
                        }
                    }
                }
            }
            i += 1;
            base = *data_027e0058;
            idx += 0xE;
        } while (i < (s32)(data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)] + 0x33));
    }
    if (count7 > count8 * 3) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a4510(void) {
    s32 func_ov000_021a43e8(s32);
    s32 func_ov000_021a98e4(s32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    s32 count7 = 0;
    s32 count8 = 0;
    void *base = *data_027e0058;
    u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
    s32 i;
    s32 idx;
    u8 *entries;

    i = start + 1;
    if (i < (s32)(start + 0x33)) {
        idx = i * 0xE;
        entries = (u8 *)base + 0x59A4;
        do {
            if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0) {
                if (func_ov000_021a43e8(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                    if (data_ov000_021b5bfc[((u32)((entries[idx]) << 0x1A) >> 0x1A) * 0x70 + 0x13] & 7) {
                        if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                            count7 += 1;
                        }
                        if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 1) {
                            count8 += 1;
                        }
                    }
                }
            }
            i += 1;
            base = *data_027e0058;
            idx += 0xE;
        } while (i < (s32)(data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)] + 0x33));
    }
    if (count7 > count8) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a4608(void) {
    s32 func_ov000_021a43e8(s32);
    s32 func_ov000_021a98e4(s32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    s32 count7 = 0;
    s32 count8 = 0;
    void *base = *data_027e0058;
    u16 start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)];
    s32 i;
    s32 idx;
    u8 *entries;

    i = start + 1;
    if (i < (s32)(start + 0x33)) {
        idx = i * 0xE;
        entries = (u8 *)base + 0x59A4;
        do {
            if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0) {
                if (func_ov000_021a43e8(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                    if (data_ov000_021b5bfc[((u32)((entries[idx]) << 0x1A) >> 0x1A) * 0x70 + 0x13] & 7) {
                        if (((u32)((entries[idx]) << 0x1A) >> 0x1A) != 0x1A) {
                            if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 0) {
                                count7 += 1;
                            }
                            if (func_ov000_021a98e4(((u32)((entries[idx]) << 0x1A) >> 0x1A)) == 1) {
                                count8 += 1;
                            }
                        }
                    }
                }
            }
            i += 1;
            base = *data_027e0058;
            idx += 0xE;
        } while (i < (s32)(data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52A4)] + 0x33));
    }
    if (count7 > (count8 << 1)) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a484c(s32 arg0, s32 arg1) {
    s32 func_ov000_021a4414();
    s32 func_ov000_021a4510();
    s32 func_ov000_021a4608();
    s32 func_ov000_021a4704();

    switch (arg1) {
    case 10:
        return func_ov000_021a4414();
    case 26:
        return func_ov000_021a4510();
    case 11:
        return func_ov000_021a4608();
    case 12:
        return func_ov000_021a4704();
    }
    return 1;
}

u8 func_ov000_021a48ac(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    u8 var_r0;

    if (data_ov000_021dfd98[arg0 * 8] <= data_ov000_021dfd99[arg0 * 8] * 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a48dc(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    s32 temp_r0;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = data_ov000_021dfd98[arg0 * 8];
    temp_r0 = data_ov000_021dfd99[arg0 * 8];
    if (temp_r2 <= temp_r0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_021a4908(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    extern u8 data_ov000_021dfd9a[];
    u8 *p98;
    s32 var_r3;
    s32 temp_r1;

    var_r3 = data_ov000_021dfd99[arg0 * 8];
    temp_r1 = var_r3 - data_ov000_021dfd9a[arg0 * 8];
    p98 = data_ov000_021dfd98;
    if (temp_r1 != 0) {
        var_r3 = temp_r1;
    }
    if (p98[arg0 * 8] > (var_r3 << 1)) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a4944(s32 arg0) {
    extern u8 data_ov000_021dfd98[];
    extern u8 data_ov000_021dfd99[];
    extern u8 data_ov000_021dfd9a[];
    u8 *p98;
    s32 temp_r2;
    s32 temp_r1;
    s32 var_ip;

    var_ip = data_ov000_021dfd99[arg0 * 8];
    temp_r1 = data_ov000_021dfd9a[arg0 * 8];
    p98 = data_ov000_021dfd98;
    temp_r2 = var_ip - temp_r1;
    if (temp_r2 != 0) {
        var_ip = temp_r2 + (temp_r1 >> 1);
    }
    if (p98[arg0 * 8] > (var_ip << 1)) {
        return 0;
    }
    return 1;
}

s32 func_ov000_021a4980(s32 arg0, s32 arg1) {
    u8 func_ov000_021a48ac(s32);
    u8 func_ov000_021a48dc(s32);
    s32 func_ov000_021a4908(s32);
    s32 func_ov000_021a4944(s32);

    switch (arg1) {
    case 10:
        return func_ov000_021a48ac(arg0);
    case 26:
        return func_ov000_021a48dc(arg0);
    case 11:
        return func_ov000_021a4908(arg0);
    case 12:
        return func_ov000_021a4944(arg0);
    }
    return 1;
}

u8 func_ov000_021a49e0(s32 arg0) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 func_020a886c(u16, M2C_UNK);
    extern void **data_027e0058;
    extern void *data_ov000_021df578;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp_r5;
    u16 temp_r0;
    u8 var_r0;
    void *temp_r1;

    if (M2C_FIELD(data_ov000_021df578, s32 *, 0x14) != 0) {
        return 0U;
    }
    temp_r4 = M2C_FIELD(data_ov000_021df578, s32 *, 0x10);
    temp_r1 = *data_027e0058;
    temp_r0 = M2C_FIELD(temp_r1, u16 *, 0x52A4);
    temp_r5 = (temp_r0 * 0x8C) + (s32) (temp_r1 + 0x67A4);
    temp_r2 = M2C_FIELD(temp_r5, s32 *, 8);
    if (arg0 <= (s32) (temp_r2 - temp_r4)) {
        return 0U;
    }
    if (arg0 > (s32) ((temp_r2 * 2) - temp_r4)) {
        return 0U;
    }
    if ((s32) (arg0 + func_0207c8ec((func_020a886c(temp_r0, 0) + 0x64) * 0x7D0, 0x64)) < (s32) ((M2C_FIELD(temp_r5, s32 *, 0) + M2C_FIELD(temp_r5, s32 *, 8)) - temp_r4)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

