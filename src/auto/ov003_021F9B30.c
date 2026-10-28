/* 2 functions from 0x021F9B30 to 0x021F9FE0 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f9b30(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ab344(void *, u8, M2C_UNK);
    M2C_UNK func_020ab3b0(void *, u8, M2C_UNK);
    u32 func_020d886c();
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    extern u16 **data_027e01d8;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 var_r1;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    u32 temp_r0_2;
    u32 temp_r0_3;
    void *temp_r0;

    func_02007f8c(M2C_FIELD(arg0, s32 *, 0x44) + 0x186C, 0, 0xD);
    func_01ff9ce8(0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    temp_r0 = M2C_FIELD(arg0, void **, 0x4C);
    M2C_FIELD(temp_r0, s32 *, 0x18) = (s32) (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x44) + ((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4) << 9)), u8 *, 0x22D) - 1);
    if (M2C_FIELD(temp_r0, u8 *, 0x24) != 0) {
        var_r1 = M2C_FIELD(temp_r0, s32 *, 0x14);
        if ((s32) M2C_FIELD(temp_r0, s32 *, 0x18) < var_r1) {
            do {
                var_r1 = M2C_FIELD(temp_r0, s32 *, 0x14) - ((M2C_FIELD(temp_r0, s32 *, 0x18) - M2C_FIELD(temp_r0, s32 *, 0x1C)) + 1);
                M2C_FIELD(temp_r0, s32 *, 0x14) = var_r1;
            } while (var_r1 > (s32) M2C_FIELD(temp_r0, s32 *, 0x18));
        }
        if (var_r1 < (s32) M2C_FIELD(temp_r0, s32 *, 0x1C)) {
            do {
                temp_r1 = M2C_FIELD(temp_r0, s32 *, 0x14) + ((M2C_FIELD(temp_r0, s32 *, 0x18) - M2C_FIELD(temp_r0, s32 *, 0x1C)) + 1);
                M2C_FIELD(temp_r0, s32 *, 0x14) = temp_r1;
            } while (temp_r1 < (s32) M2C_FIELD(temp_r0, s32 *, 0x1C));
        }
    } else {
        var_r2 = M2C_FIELD(temp_r0, s32 *, 0x18);
        temp_r1_2 = M2C_FIELD(temp_r0, s32 *, 0x14);
        if (temp_r1_2 <= var_r2) {
            var_r2 = M2C_FIELD(temp_r0, s32 *, 0x1C);
            if (temp_r1_2 >= var_r2) {
                var_r2 = temp_r1_2;
            }
        }
        M2C_FIELD(temp_r0, s32 *, 0x14) = var_r2;
    }
    temp_r0_2 = func_020d886c();
    switch (temp_r0_2) {
    case 28:
        var_r2_2 = 7;
        break;
    case 6:
        var_r2_2 = 1;
        break;
    case 22:
    case 23:
        var_r2_2 = 3;
        break;
    case 12:
        var_r2_2 = 5;
        break;
    case 5:
    case 7:
        var_r2_2 = 0;
        break;
    case 24:
        var_r2_2 = 2;
        break;
    case 8:
        var_r2_2 = 6;
        break;
    case 14:
        var_r2_2 = 9;
        break;
    case 15:
        var_r2_2 = 0xA;
        break;
    case 16:
        var_r2_2 = 0xB;
        break;
    case 17:
        var_r2_2 = 0xC;
        break;
    default:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 9:
    case 10:
    case 11:
    case 13:
    case 18:
    case 19:
    case 20:
    case 21:
    case 25:
    case 26:
    case 27:
        var_r2_2 = 4;
        break;
    }
    func_020ab3b0(M2C_FIELD(arg0, void **, 0x4C), M2C_FIELD(((var_r2_2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xA9), 1);
    temp_r0_3 = func_020d886c();
    switch (temp_r0_3) {
    case 28:
        var_r2_3 = 7;
        break;
    case 6:
        var_r2_3 = 1;
        break;
    case 22:
    case 23:
        var_r2_3 = 3;
        break;
    case 12:
        var_r2_3 = 5;
        break;
    case 5:
    case 7:
        var_r2_3 = 0;
        break;
    case 24:
        var_r2_3 = 2;
        break;
    case 8:
        var_r2_3 = 6;
        break;
    case 14:
        var_r2_3 = 9;
        break;
    case 15:
        var_r2_3 = 0xA;
        break;
    case 16:
        var_r2_3 = 0xB;
        break;
    case 17:
        var_r2_3 = 0xC;
        break;
    default:
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 9:
    case 10:
    case 11:
    case 13:
    case 18:
    case 19:
    case 20:
    case 21:
    case 25:
    case 26:
    case 27:
        var_r2_3 = 4;
        break;
    }
    func_020ab344(M2C_FIELD(arg0, void **, 0x4C), M2C_FIELD(((var_r2_3 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xD), 1);
    func_ov003_021f92f4(arg0, 0);
}

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
