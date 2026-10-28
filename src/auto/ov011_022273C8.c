/* 6 functions from 0x022273C8 to 0x02227F08 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_022273c8(void *arg0) {
    M2C_UNK func_01ffaacc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    u8 func_0207ca38(s32, M2C_UNK, s32, u8, s32);
    u16 func_0209b5e4(s32, M2C_UNK *);
    M2C_UNK func_0209b67c(u16, s32, u16, u16, s32);
    extern M2C_UNK data_02101f78;
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_ov011_02228c38;
    extern M2C_UNK data_ov011_02228c50;
    extern M2C_UNK data_ov011_02228c88;
    extern M2C_UNK data_ov011_02228ca4;
    u16 *sp90;
    u16 *sp8C;
    u16 *sp88;
    u16 *sp84;
    u16 *sp80;
    u16 *sp7C;
    u16 *sp78;
    u16 *sp74;
    u16 *sp70;
    u16 *sp6C;
    u16 *sp68;
    u16 *sp64;
    u16 *sp60;
    u16 *sp5C;
    u16 *sp58;
    u16 *sp54;
    u16 *sp50;
    u16 *sp4C;
    u16 *sp48;
    u16 *sp44;
    u16 *sp40;
    u16 *sp3C;
    u16 *sp38;
    u16 *sp34;
    u16 *sp30;
    u16 *sp2C;
    u16 *sp28;
    u16 *sp24;
    u16 *sp20;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 **spC;
    u16 **sp8;
    u32 sp4;
    s32 var_r9;
    u16 **var_r0;
    u16 *temp_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_14;
    u16 *temp_r0_15;
    u16 *temp_r0_16;
    u16 *temp_r0_17;
    u16 *temp_r0_19;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
    u16 *temp_r1_14;
    u16 *temp_r1_15;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r1_8;
    u16 *temp_r1_9;
    u16 *temp_r3;
    u16 *temp_r3_2;
    u16 *temp_r3_3;
    u16 temp_r11;
    u16 temp_r1;
    u16 temp_r1_16;
    u16 temp_r2;
    u16 temp_r4;
    u16 temp_r5;
    u16 temp_r6;
    u32 temp_r0_6;
    u32 temp_r7;
    u32 temp_r8;
    u32 temp_r9;
    u8 temp_r0_18;
    u8 temp_r0_20;
    u8 temp_r0_7;

    if (((u32) M2C_FIELD(arg0, u8 *, 0x38) <= 0x1EU) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) != 0)) {
        var_r9 = 0;
        spC = data_027e01d8;
        do {
            if (var_r9 == 0) {
                var_r0 = data_027e00c8;
            } else {
                var_r0 = data_027e00c4;
            }
            data_027e01d8 = var_r0;
            var_r9 += 1;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x50) = func_0207ca38(0, -0x10, 0, M2C_FIELD(arg0, u8 *, 0x38), 0x1E);
        } while (var_r9 < 2);
        data_027e01d8 = spC;
        M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) + 1);
    }
    sp8 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) >= 0x29CCU) {
        temp_r0 = *data_027e00c8;
        sp90 = temp_r0;
        *temp_r0 = *sp90 & ~0x10;
        temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp8C = temp_r0_2;
        *temp_r0_2 = *sp8C & ~0x20;
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp88 = temp_r0_3;
        *temp_r0_3 = *sp88 & ~0x40;
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp84 = temp_r0_4;
        *temp_r0_4 = *sp84 | 0x80;
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp80 = temp_r0_5;
        *temp_r0_5 = *sp80 | 0x100;
        temp_r11 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2000, &data_ov011_02228c38);
        temp_r4 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800, &data_ov011_02228c50);
        temp_r5 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3000, &data_ov011_02228c88);
        temp_r6 = func_0209b5e4(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x3800, &data_ov011_02228ca4);
        temp_r7 = temp_r11 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r7) & 0x1FF), 0x440, temp_r11, (u16) ((0x3FF & (0x100 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        temp_r8 = temp_r4 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r8) & 0x1FF), 0x480, temp_r4, (u16) ((0x3FF & (0x140 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        temp_r0_6 = temp_r5 >> 1;
        sp4 = temp_r0_6;
        func_0209b67c((u16) ((0x80 - temp_r0_6) & 0x1FF), 0x48E, temp_r5, (u16) ((0x3FF & (0x180 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        temp_r9 = temp_r6 >> 1;
        func_0209b67c((u16) ((0x80 - temp_r9) & 0x1FF), 0x49C, temp_r6, (u16) ((0x3FF & (0x1C0 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xF800), 0xB);
        func_0209b67c((u16) ((0x82 - temp_r7) & 0x1FF), 0x442, temp_r11, (u16) ((0x3FF & (0x100 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - temp_r8) & 0x1FF), 0x482, temp_r4, (u16) ((0x3FF & (0x140 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - temp_r0_6) & 0x1FF), 0x490, temp_r5, (u16) ((0x3FF & (0x180 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        func_0209b67c((u16) ((0x82 - temp_r9) & 0x1FF), 0x49E, temp_r6, (u16) ((0x3FF & (0x1C0 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0xE800), 0x11);
        temp_r1 = M2C_FIELD(arg0, u16 *, 0x3A);
        if ((u32) temp_r1 <= 0x2A08U) {
            temp_r0_7 = func_0207ca38(4, 0, 0x10, temp_r1 - 0x29CC, 0x3C);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_7;
            temp_r3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp7C = temp_r3 + 0x12;
            M2C_FIELD(temp_r3, s16 *, 0x12) = (s16) ((*sp7C & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_7;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_7);
        }
    }
    data_027e01d8 = data_027e00c4;
    if (M2C_FIELD(arg0, u16 *, 0x3A) == 0x2918) {
        temp_r0_8 = *data_027e00c4;
        sp78 = temp_r0_8 + 0x12;
        M2C_FIELD(temp_r0_8, s16 *, 0x12) = (s16) (*sp78 & ~1);
        temp_r0_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp74 = temp_r0_9 + 0x12;
        M2C_FIELD(temp_r0_9, s16 *, 0x12) = (s16) (*sp74 & ~2);
        temp_r0_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp70 = temp_r0_10 + 0x12;
        M2C_FIELD(temp_r0_10, s16 *, 0x12) = (s16) (*sp70 | 4);
        temp_r0_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp6C = temp_r0_11 + 0x12;
        M2C_FIELD(temp_r0_11, s16 *, 0x12) = (s16) (*sp6C & ~8);
        temp_r0_12 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp68 = temp_r0_12 + 0x12;
        M2C_FIELD(temp_r0_12, s16 *, 0x12) = (s16) (*sp68 & ~0x10);
        temp_r0_13 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp64 = temp_r0_13 + 0x12;
        M2C_FIELD(temp_r0_13, s16 *, 0x12) = (s16) (*sp64 | 0x100);
        temp_r0_14 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp60 = temp_r0_14 + 0x12;
        M2C_FIELD(temp_r0_14, s16 *, 0x12) = (s16) (*sp60 | 0x200);
        temp_r0_15 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp5C = temp_r0_15 + 0x12;
        M2C_FIELD(temp_r0_15, s16 *, 0x12) = (s16) (*sp5C & ~0x400);
        temp_r0_16 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp58 = temp_r0_16 + 0x12;
        M2C_FIELD(temp_r0_16, s16 *, 0x12) = (s16) (*sp58 | 0x800);
        temp_r0_17 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp54 = temp_r0_17 + 0x12;
        M2C_FIELD(temp_r0_17, s16 *, 0x12) = (s16) (*sp54 | 0x1000);
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3C) = 0;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x44) = 0;
    }
    temp_r2 = M2C_FIELD(arg0, u16 *, 0x3A);
    if (((u32) temp_r2 >= 0x2918U) && ((u32) temp_r2 <= 0x2990U)) {
        temp_r0_18 = func_0207ca38(4, 0, 0x10, temp_r2 - 0x2918, 0x78);
        M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_18;
        temp_r3_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp50 = temp_r3_2 + 0x12;
        M2C_FIELD(temp_r3_2, s16 *, 0x12) = (s16) ((*sp50 & ~0xC0) | 0x40);
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_18;
        M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_18);
    }
    if (M2C_FIELD(arg0, u16 *, 0x3A) == 0x29CC) {
        temp_r1_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp4C = temp_r1_2;
        *temp_r1_2 = *sp4C | 0x10;
        temp_r1_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp48 = temp_r1_3;
        *temp_r1_3 = *sp48 & ~0x20;
        temp_r1_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp44 = temp_r1_4;
        *temp_r1_4 = *sp44 | 0x40;
        temp_r1_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp40 = temp_r1_5;
        *temp_r1_5 = *sp40 & ~0x80;
        temp_r1_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp3C = temp_r1_6;
        *temp_r1_6 = *sp3C | 0x100;
        temp_r1_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp38 = temp_r1_7 + 0x12;
        M2C_FIELD(temp_r1_7, s16 *, 0x12) = (s16) (*sp38 & ~1);
        temp_r1_8 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp34 = temp_r1_8 + 0x12;
        M2C_FIELD(temp_r1_8, s16 *, 0x12) = (s16) (*sp34 & ~2);
        temp_r1_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp30 = temp_r1_9 + 0x12;
        M2C_FIELD(temp_r1_9, s16 *, 0x12) = (s16) (*sp30 & ~4);
        temp_r1_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp2C = temp_r1_10 + 0x12;
        M2C_FIELD(temp_r1_10, s16 *, 0x12) = (s16) (*sp2C & ~8);
        temp_r1_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp28 = temp_r1_11 + 0x12;
        M2C_FIELD(temp_r1_11, s16 *, 0x12) = (s16) (*sp28 | 0x10);
        temp_r1_12 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp24 = temp_r1_12 + 0x12;
        M2C_FIELD(temp_r1_12, s16 *, 0x12) = (s16) (*sp24 | 0x100);
        temp_r1_13 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp20 = temp_r1_13 + 0x12;
        M2C_FIELD(temp_r1_13, s16 *, 0x12) = (s16) (*sp20 | 0x200);
        temp_r1_14 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r1_14 + 0x12;
        M2C_FIELD(temp_r1_14, s16 *, 0x12) = (s16) (*sp1C | 0x400);
        temp_r1_15 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp18 = temp_r1_15 + 0x12;
        M2C_FIELD(temp_r1_15, s16 *, 0x12) = (s16) (*sp18 | 0x800);
        temp_r0_19 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp14 = temp_r0_19 + 0x12;
        M2C_FIELD(temp_r0_19, s16 *, 0x12) = (s16) (*sp14 & ~0x1000);
    }
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) > 0x29CCU) {
        func_01ffaacc(0, 0x50, 0, &data_02101f78, 0);
        temp_r1_16 = M2C_FIELD(arg0, u16 *, 0x3A);
        if ((u32) temp_r1_16 < 0x2A44U) {
            temp_r0_20 = func_0207ca38(4, 0, 0x10, temp_r1_16 - 0x29CC, 0x78);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_20;
            temp_r3_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp10 = temp_r3_3 + 0x12;
            M2C_FIELD(temp_r3_3, s16 *, 0x12) = (s16) ((*sp10 & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_20;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_20);
        }
    }
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 4);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    data_027e01d8 = sp8;
    M2C_FIELD(arg0, u16 *, 0x3A) = (u16) (M2C_FIELD(arg0, u16 *, 0x3A) + 1);
}

void func_ov011_02227e88(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) <= 0x2A80U) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov011_02227ea4(M2C_UNK arg0) {
    extern M2C_UNK data_ov011_02228b1c;
    extern M2C_UNK data_ov011_02228a48;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov011_02228a48, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov011_02228b1c;
    }
}

void func_ov011_02227ecc(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov011_02225684();
    extern M2C_UNK data_ov011_02228a78;
    if (func_01ffa42c(&data_ov011_02228a78, arg0) == 0) {
        return;
    }
    func_ov011_02225684();
}

void func_ov011_02227ef0(void) {

}

s32 func_ov011_02227ef4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

