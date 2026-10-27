/* 2 functions from 0x021F9B30 to 0x021F9FE0 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f9e50(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_01ffaacc(u16, u8, u16, M2C_UNK *, s32);
    s32 func_0207c8ec(u8, M2C_UNK);
    s32 func_0207c928(u8, M2C_UNK);
    M2C_UNK func_020a92bc(void *, s16);
    M2C_UNK func_020a94fc(void *);
    s16 func_020c1980(s32, s32, s32);
    s32 func_ov003_02200ae8(u8);
    extern M2C_UNK data_027e0074;
    extern u16 **data_027e00c4;
    extern u16 **data_027e01d8;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;
    s16 temp_r5;
    s16 temp_r6;
    s16 temp_r7_2;
    s32 temp_r7;
    s32 var_r2;
    s32 var_r9;
    u16 **temp_r11;
    u8 var_r8;
    void *temp_r1;

    sp4 = arg1;
    M2C_FIELD(*data_027e01d8, s16 *, 0x3A) = (s16) (0 - arg1);
    var_r8 = 0;
    var_r9 = 0x210;
    sp8 = arg2;
    M2C_FIELD(*data_027e01d8, s16 *, 0x42) = 0;
    spC = -1;
    sp14 = 0x1FF;
    sp10 = 0x3FF;
    do {
        temp_r5 = (func_0207c928(var_r8, 3) * 0x16) + sp4;
        temp_r6 = (func_0207c8ec(var_r8, 3) * 0x1C) + sp8;
        temp_r7 = M2C_FIELD(arg0, s32 *, 0x44);
        temp_r7_2 = func_020c1980(temp_r7 + 0x1830, func_ov003_02200ae8(var_r8), spC);
        if (temp_r7_2 != 0) {
            temp_r11 = data_027e01d8;
            data_027e01d8 = data_027e00c4;
            func_020a92bc(M2C_FIELD(arg0, void **, 0x54), temp_r7_2);
            temp_r1 = M2C_FIELD(arg0, void **, 0x54);
            M2C_FIELD(temp_r1, s16 *, 6) = (s16) (temp_r5 + 0x14);
            M2C_FIELD(temp_r1, s16 *, 8) = (s16) (temp_r6 + 0x66);
            func_020a94fc(M2C_FIELD(arg0, void **, 0x54));
            data_027e01d8 = temp_r11;
        }
        if (temp_r7_2 != 0) {
            var_r2 = 7;
        } else {
            var_r2 = 8;
        }
        func_01ffaacc((u16) ((temp_r5 + 4) & sp14), (u8) (temp_r6 + 0x4E), (u16) ((sp10 & (var_r9 >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))) | (u16) (var_r2 << 0xC) | 0x400), &data_027e0074, 0x11);
        var_r8 += 1;
        var_r9 += 8;
    } while ((s32) var_r8 < 8);
}
