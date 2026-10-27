/* 9 functions from 0x0221E004 to 0x0221EDA8 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221e004(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221e568(u8 *arg0) {
    M2C_UNK func_0207c8ec(u8, M2C_UNK);
    M2C_UNK func_0207c928(u8, M2C_UNK);
    M2C_UNK func_020b1c60(u8);
    extern u16 *data_02101e84;
    M2C_UNK func_ov007_0221e010(void);
    extern u8 data_ov007_0221f5a4[];
    u8 var_r7;
    u16 temp_r5;
    u16 temp_r6;

    var_r7 = *arg0;
    temp_r5 = data_02101e84[0];
    temp_r6 = data_02101e84[1];
    if (temp_r5 & 1) {
        func_ov007_0221e010();
        return;
    }
    if (temp_r6 & 0x40) {
        if (func_0207c8ec(var_r7, 0xF) == 0) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[func_0207c928(var_r7, 0xF)];
            }
        } else {
            var_r7 -= 0xF;
        }
        if (0x4BU > var_r7) {
            goto block_15;
        }
    } else if (temp_r6 & 0x80) {
        if (func_0207c8ec(var_r7, 0xF) == 4) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[func_0207c928(var_r7, 0xF)];
            }
        } else {
            var_r7 += 0xF;
        }
        if ((u32) var_r7 < 0x4BU) {
            goto block_15;
        }
    } else {
block_15:
        if (temp_r6 & 0x20) {
            if (func_0207c928(var_r7, 0xF) == 0) {
                if (temp_r6 == temp_r5) {
                    var_r7 += 0xE;
                }
            } else {
                var_r7 -= 1;
            }
        } else if (temp_r6 & 0x10) {
            if (func_0207c928(var_r7, 0xF) == 0xE) {
                if (temp_r6 == (int)temp_r5) {
                    var_r7 -= 0xE;
                }
            } else {
                ++var_r7;
            }
        }
    }
    if (*arg0 == var_r7) {
        return;
    }
    func_020b1c60(var_r7);
}

void func_ov007_0221e6bc(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221e85c(void *arg0) {
    M2C_UNK func_02087e34(s32);
    M2C_UNK func_020b2140();
    M2C_UNK func_020b2178();
    func_020b2178();
    func_02087e34(M2C_FIELD(arg0, s32 *, 0x38));
    func_020b2140();
}

void func_ov007_0221ec34(void) {
    M2C_UNK func_020af1f8();
    func_020af1f8();
}

extern u16 **data_027e00c8;
extern u16 **data_027e01d8;
extern u16 **gCur3DSpriteEngine;
void func_ov007_0221ec40(void *arg0) {
    M2C_UNK func_0208df84(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    u16 func_0209b5e4(s32, M2C_UNK *);
    M2C_UNK func_0209b67c(u16, M2C_UNK, u16, u16, s32);
    s32 func_0209c268(M2C_UNK *);
    extern M2C_UNK data_ov007_02221e0c;
    extern M2C_UNK data_ov007_02221e10;
    u16 **sp8;
    M2C_UNK *var_r10;
    s16 var_r6;
    s32 var_r8;
    s32 var_r9;
    u16 temp_r5;

    sp8 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    func_0208df84(M2C_FIELD(arg0, s16 *, 0x3E), M2C_FIELD(arg0, s16 *, 0x40), 8, 0x10, (s32) (u16) ((0x3FF & (0x80 >> ((u32) (**data_027e00c8 << 0x11) >> 0x1E))) | 0x1000), 0);
    var_r6 = 0x10;
    var_r8 = 0x4D00;
    var_r9 = 0;
    if (M2C_FIELD(&data_ov007_02221e0c, s32 *, 4) != 0) {
        var_r10 = &data_ov007_02221e10;
        do {
            temp_r5 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + var_r8, var_r10);
            func_0209b67c((u16) (var_r6 + ((u32) (8 - func_0209c268(var_r10)) >> 1)), 0x10, temp_r5, (u16) ((0x3FF & ((s32) (var_r8 >> 5) >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x7000), 0);
            var_r8 = (s32) (u16) (var_r8 + (((u32) (((u32) (temp_r5 + 7) >> 3) + 3) >> 2) << 8));
            var_r9 += 1;
            var_r6 += 8;
            var_r10 += 4;
        } while (*(&data_ov007_02221e10 + (var_r9 * 4)) != 0);
    }
    data_027e01d8 = sp8;
}

