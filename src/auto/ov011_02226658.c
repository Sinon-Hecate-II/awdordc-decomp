/* 2 functions from 0x02226658 to 0x022273C8 (ov011), found by ds-decomp. */
#include "common.h"

u8 func_ov011_02226658(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ffa574();
    u8 func_01ffa6fc(void *);
    u8 func_0207ca38(s32, s32, M2C_UNK, u8, s32);
    M2C_UNK func_ov011_022257b4(void *);
    M2C_UNK func_ov011_022257c4(void *);
    M2C_UNK func_ov011_0222588c(void *);
    s32 func_ov011_02225a18(void *);
    M2C_UNK func_ov011_02225a24(void *, u16, u16);
    M2C_UNK func_ov011_02225a9c(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    extern u16 **data_027e01d8;
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
    u16 *spC;
    u16 *sp8;
    u16 **sp4;
    s32 temp_r0_3;
    s32 var_r5;
    s32 var_r9;
    u16 **temp_r1_8;
    u16 **temp_r4;
    u16 **var_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_15;
    u16 *temp_r0_17;
    u16 *temp_r0_5;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u16 *temp_r1_2;
    u16 *temp_r1_3;
    u16 *temp_r1_4;
    u16 *temp_r1_5;
    u16 *temp_r1_6;
    u16 *temp_r1_7;
    u16 *temp_r2;
    u16 *temp_r2_2;
    u16 *temp_r2_3;
    u16 *temp_r2_4;
    u16 *temp_r2_5;
    u16 *temp_r2_6;
    u16 *temp_r2_7;
    u16 *temp_r3;
    u16 *temp_r3_2;
    u16 *temp_r3_3;
    u16 *temp_r3_4;
    u16 *temp_r3_5;
    u16 *temp_r6;
    u16 *temp_r6_2;
    u16 *temp_r7;
    u16 *temp_r7_2;
    u16 *temp_r7_3;
    u16 *temp_r7_4;
    u32 temp_r0;
    u8 temp_r0_14;
    u8 temp_r0_16;
    u8 temp_r0_2;
    u8 temp_r0_4;
    u8 temp_r0_6;
    u8 temp_r1;
    u8 temp_r2_8;

    temp_r4 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) < 0x29CCU) {
        if ((u32) M2C_FIELD(arg0, u8 *, 0x37) >= 0xC8U) {
            M2C_FIELD(arg0, u8 *, 0x37) = 0U;
        }
        if (M2C_FIELD(arg0, u8 *, 0x37) == 0) {
            M2C_FIELD(arg0, u8 *, 0x35) = (u8) (M2C_FIELD(arg0, u8 *, 0x35) & ~0xF);
            M2C_FIELD(arg0, u8 *, 0x34) = (u8) ((u8) (M2C_FIELD(arg0, u8 *, 0x34) & ~4) & ~8);
            temp_r0_3 = func_ov011_02225a18(arg0);
            switch (temp_r0_3) {                    /* irregular */
            case 1:
                func_ov011_022257b4(arg0);
                temp_r1 = M2C_FIELD(arg0, u8 *, 0x34);
                M2C_FIELD(arg0, u8 *, 0x34) = (u8) ((temp_r1 & ~0xF0) | (u8) ((u8) (((u32) (temp_r1 << 0x18) >> 0x1C) + 1) * 0x10));
                M2C_FIELD(arg0, s32 *, 0x4C) = (s32) (M2C_FIELD(arg0, s32 *, 0x4C) + 0x10);
                M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 4);
                /* fallthrough */
            case 2:
                func_ov011_0222588c(arg0);
                if (func_ov011_02225a18(arg0) != 2) {
                    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 8);
                }
                break;
            case 0:
                M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) & ~2);
                temp_r2 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp7C = temp_r2;
                *temp_r2 = *sp7C | 0x10;
                temp_r2_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp78 = temp_r2_2;
                *temp_r2_2 = *sp78 & ~0x20;
                temp_r2_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp74 = temp_r2_3;
                *temp_r2_3 = *sp74 & ~0x40;
                temp_r2_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp70 = temp_r2_4;
                *temp_r2_4 = *sp70 | 0x80;
                temp_r1_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp6C = temp_r1_2;
                *temp_r1_2 = *sp6C | 0x100;
                func_01ff9ce8(1);
                func_01ff9ce8(2);
                break;
            }
        }
        if ((M2C_FIELD(arg0, s32 *, 0x50) != 0) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1E) >> 0x1F) != 0)) {
            func_ov011_022257c4(arg0);
        }
        temp_r0_4 = M2C_FIELD(arg0, u8 *, 0x37);
        if ((u32) temp_r0_4 <= 0x1EU) {
            temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp68 = temp_r0_5 + 0x12;
            M2C_FIELD(temp_r0_5, u16 *, 0x12) = (u16) (M2C_FIELD(temp_r0_5, u16 *, 0x12) & ~1);
            temp_r2_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp64 = temp_r2_5 + 0x12;
            *sp64 = M2C_FIELD(temp_r2_5, u16 *, 0x12) & ~2;
            temp_r7 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp60 = temp_r7 + 0x12;
            M2C_FIELD(temp_r7, s16 *, 0x12) = (s16) (*sp60 & ~4);
            temp_r7_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp5C = temp_r7_2 + 0x12;
            M2C_FIELD(temp_r7_2, s16 *, 0x12) = (s16) (*sp5C & ~8);
            temp_r3 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp58 = temp_r3 + 0x12;
            M2C_FIELD(temp_r3, s16 *, 0x12) = (s16) ((*sp58 & ~0x10) | ((u32) (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1D) >> 0x1F) << 0x1F) >> 0x1B));
            temp_r0_6 = func_0207ca38(4, 0, 0x10, M2C_FIELD(arg0, u8 *, 0x37), 0x1E);
            M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_6;
            temp_r3_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
            sp54 = temp_r3_2 + 0x12;
            M2C_FIELD(temp_r3_2, s16 *, 0x12) = (s16) ((*sp54 & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_6;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_6);
        } else if ((u32) temp_r0_4 >= 0xAAU) {
            if (func_ov011_02225a18(arg0) == 0) {
                temp_r1_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
                M2C_FIELD(temp_r1_3, u16 *, 6) = (u16) ((M2C_FIELD(temp_r1_3, u16 *, 6) & ~3) | 1);
                temp_r1_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
                M2C_FIELD(temp_r1_4, u16 *, 8) = (u16) ((M2C_FIELD(temp_r1_4, u16 *, 8) & ~3) | 2);
                temp_r1_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
                M2C_FIELD(temp_r1_5, u16 *, 0xA) = (u16) ((M2C_FIELD(temp_r1_5, u16 *, 0xA) & ~3) | 3);
                temp_r1_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
                M2C_FIELD(temp_r1_6, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_6, u16 *, 0xC) & ~3);
                temp_r0_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp50 = temp_r0_7 + 0x12;
                M2C_FIELD(temp_r0_7, s16 *, 0x12) = (s16) (*sp50 & ~1);
                temp_r0_8 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp4C = temp_r0_8 + 0x12;
                M2C_FIELD(temp_r0_8, s16 *, 0x12) = (s16) (*sp4C & ~2);
                temp_r0_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp48 = temp_r0_9 + 0x12;
                M2C_FIELD(temp_r0_9, s16 *, 0x12) = (s16) (*sp48 & ~4);
                temp_r0_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp44 = temp_r0_10 + 0x12;
                M2C_FIELD(temp_r0_10, s16 *, 0x12) = (s16) (*sp44 | 8);
                temp_r0_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp40 = temp_r0_11 + 0x12;
                M2C_FIELD(temp_r0_11, s16 *, 0x12) = (s16) (*sp40 & ~0x10);
                temp_r0_12 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp3C = temp_r0_12 + 0x12;
                M2C_FIELD(temp_r0_12, s16 *, 0x12) = (s16) (*sp3C & ~0x100);
                temp_r0_13 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp38 = temp_r0_13 + 0x12;
                M2C_FIELD(temp_r0_13, s16 *, 0x12) = (s16) (*sp38 & ~0x200);
                temp_r1_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp34 = temp_r1_7 + 0x12;
                *sp34 = M2C_FIELD(temp_r1_7, u16 *, 0x12) | 0x400;
                temp_r6 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp30 = temp_r6 + 0x12;
                M2C_FIELD(temp_r6, s16 *, 0x12) = (s16) (*sp30 & ~0x800);
                temp_r6_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp2C = temp_r6_2 + 0x12;
                M2C_FIELD(temp_r6_2, s16 *, 0x12) = (s16) (*sp2C | 0x1000);
                temp_r3_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp28 = temp_r3_3 + 0x12;
                M2C_FIELD(temp_r3_3, s16 *, 0x12) = (s16) (*sp28 & ~0x2000);
                temp_r0_14 = func_0207ca38(4, 0x10, 0, M2C_FIELD(arg0, u8 *, 0x37) - 0xAA, 0x1E);
                M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_14;
                temp_r2_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp24 = temp_r2_6 + 0x12;
                M2C_FIELD(temp_r2_6, s16 *, 0x12) = (s16) ((*sp24 & ~0xC0) | 0x40);
                M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x51) = (s8) (0x10 - temp_r0_14);
                M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x52) = temp_r0_14;
            } else {
                temp_r0_15 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp20 = temp_r0_15 + 0x12;
                M2C_FIELD(temp_r0_15, u16 *, 0x12) = (u16) (M2C_FIELD(temp_r0_15, u16 *, 0x12) & ~1);
                temp_r2_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp1C = temp_r2_7 + 0x12;
                *sp1C = M2C_FIELD(temp_r2_7, u16 *, 0x12) & ~2;
                temp_r7_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp18 = temp_r7_3 + 0x12;
                M2C_FIELD(temp_r7_3, s16 *, 0x12) = (s16) (*sp18 & ~4);
                temp_r7_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp14 = temp_r7_4 + 0x12;
                M2C_FIELD(temp_r7_4, s16 *, 0x12) = (s16) (*sp14 & ~8);
                temp_r3_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
                sp10 = temp_r3_4 + 0x12;
                M2C_FIELD(temp_r3_4, s16 *, 0x12) = (s16) ((*sp10 & ~0x10) | ((u32) (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1C) >> 0x1F) << 0x1F) >> 0x1B));
                temp_r0_16 = func_0207ca38(4, 0x10, 0, M2C_FIELD(arg0, u8 *, 0x37) - 0xAA, 0x1E);
                M2C_FIELD(arg0, u8 *, 0x36) = temp_r0_16;
                temp_r3_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
                spC = temp_r3_5 + 0x12;
                M2C_FIELD(temp_r3_5, s16 *, 0x12) = (s16) ((*spC & ~0xC0) | 0x40);
                M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x51) = temp_r0_16;
                M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r0_16);
            }
        }
    }
    data_027e01d8 = data_027e00c4;
    func_ov011_02225a9c(arg0, -0x68, 0, 0);
    func_ov011_02225a9c(arg0, 0, 0, 1);
    func_ov011_02225a9c(arg0, -0x68, 0, 2);
    func_ov011_02225a9c(arg0, 0, 0, 3);
    func_ov011_02225a9c(arg0, -0x68, 0, 4);
    func_ov011_02225a9c(arg0, 0, 0, 5);
    func_ov011_02225a9c(arg0, -0x68, 0, 6);
    func_ov011_02225a9c(arg0, 0, 0, 7);
    func_ov011_02225a9c(arg0, -0x68, 0, 8);
    func_ov011_02225a9c(arg0, 0, 0, 9);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 4);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    data_027e01d8 = temp_r4;
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        data_027e01d8 = data_027e00c8;
        func_ov011_02225a24(arg0, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2));
        data_027e01d8 = temp_r4;
    }
    if ((u32) M2C_FIELD(arg0, u16 *, 0x3A) >= 0x28FAU) {
        func_01ffa6fc(arg0);
    }
    if (*data_02101e84 & 8) {
        temp_r2_8 = M2C_FIELD(arg0, u8 *, 0x34);
        if ((((u32) (temp_r2_8 << 0x1F) >> 0x1F) == 0) && ((u32) M2C_FIELD(arg0, u16 *, 0x3A) < 0x28DCU)) {
            M2C_FIELD(arg0, u8 *, 0x34) = (u8) ((temp_r2_8 & ~1) | 1);
        }
    }
    if (((u32) M2C_FIELD(arg0, u8 *, 0x38) < 0x1EU) && (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) != 0)) {
        var_r9 = 0;
        sp4 = data_027e01d8;
        do {
            if (var_r9 == 0) {
                var_r0 = data_027e00c8;
            } else {
                var_r0 = data_027e00c4;
            }
            data_027e01d8 = var_r0;
            var_r9 += 1;
            M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u8 *, 0x50) = func_0207ca38(0, 0, -0x10, M2C_FIELD(arg0, u8 *, 0x38), 0x1E);
        } while (var_r9 < 2);
        data_027e01d8 = sp4;
    }
    temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x38);
    if ((u32) temp_r0_2 < 0x1EU) {
        return temp_r0_2;
    }
    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F;
    if (temp_r0 == 0) {
        return (u8) temp_r0;
    }
    var_r5 = 0;
    M2C_FIELD(arg0, u16 *, 0x3A) = 0x29CBU;
    do {
        if (M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x40) != 0) {
            func_01ffa574();
            M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x40) = 0;
        }
        var_r5 += 1;
    } while (var_r5 < 3);
    temp_r1_8 = data_027e01d8;
    data_027e01d8 = data_027e00c4;
    temp_r0_17 = *data_027e00c4;
    sp8 = temp_r0_17 + 0x12;
    *sp8 = (M2C_FIELD(temp_r0_17, u16 *, 0x12) & ~0xC0) | 0x40;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x51) = 0x10;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = 0;
    data_027e01d8 = temp_r1_8;
    return func_01ffa6fc(arg0);
}

void func_ov011_02227048(void *arg0) {
    M2C_UNK func_ov011_02226550(M2C_UNK *, M2C_UNK);
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_ov011_02228c30;
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
    u16 *spC;
    u16 *sp8;
    u16 *sp4;
    u16 *sp0;
    u16 **temp_r4;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u16 *temp_r1;
    u16 *temp_r1_10;
    u16 *temp_r1_11;
    u16 *temp_r1_12;
    u16 *temp_r1_13;
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

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x34) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(arg0, s8 *, 0x38) = 0;
    }
    temp_r4 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    temp_r1 = *data_027e00c8;
    M2C_FIELD(temp_r1, u16 *, 6) = (u16) (M2C_FIELD(temp_r1, u16 *, 6) & ~3);
    temp_r1_2 = *data_027e01d8;
    M2C_FIELD(temp_r1_2, u16 *, 8) = (u16) ((M2C_FIELD(temp_r1_2, u16 *, 8) & ~3) | 1);
    temp_r1_3 = *data_027e01d8;
    M2C_FIELD(temp_r1_3, u16 *, 0xA) = (u16) ((M2C_FIELD(temp_r1_3, u16 *, 0xA) & ~3) | 2);
    temp_r1_4 = *data_027e01d8;
    M2C_FIELD(temp_r1_4, u16 *, 0xC) = (u16) ((M2C_FIELD(temp_r1_4, u16 *, 0xC) & ~3) | 3);
    temp_r0 = *data_027e01d8;
    sp4C = temp_r0;
    *temp_r0 = *sp4C & ~0x10;
    temp_r0_2 = *data_027e01d8;
    sp48 = temp_r0_2;
    *temp_r0_2 = *sp48 & ~0x20;
    temp_r0_3 = *data_027e01d8;
    sp44 = temp_r0_3;
    *temp_r0_3 = *sp44 & ~0x40;
    temp_r0_4 = *data_027e01d8;
    sp40 = temp_r0_4;
    *temp_r0_4 = *sp40 | 0x80;
    temp_r0_5 = *data_027e01d8;
    sp3C = temp_r0_5;
    *temp_r0_5 = *sp3C & ~0x100;
    temp_r0_6 = *data_027e01d8;
    sp38 = temp_r0_6 + 0x12;
    M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16) (*sp38 & ~1);
    temp_r0_7 = *data_027e01d8;
    sp34 = temp_r0_7 + 0x12;
    M2C_FIELD(temp_r0_7, s16 *, 0x12) = (s16) (*sp34 & ~2);
    temp_r1_5 = *data_027e01d8;
    sp30 = temp_r1_5 + 0x12;
    M2C_FIELD(temp_r1_5, s16 *, 0x12) = (s16) (*sp30 & ~4);
    temp_r1_6 = *data_027e01d8;
    sp2C = temp_r1_6 + 0x12;
    M2C_FIELD(temp_r1_6, s16 *, 0x12) = (s16) (*sp2C & ~8);
    temp_r1_7 = *data_027e01d8;
    sp28 = temp_r1_7 + 0x12;
    M2C_FIELD(temp_r1_7, s16 *, 0x12) = (s16) (*sp28 | 0x10);
    temp_r1_8 = *data_027e01d8;
    sp24 = temp_r1_8 + 0x12;
    M2C_FIELD(temp_r1_8, s16 *, 0x12) = (s16) (*sp24 & ~0x100);
    temp_r1_9 = *data_027e01d8;
    sp20 = temp_r1_9 + 0x12;
    M2C_FIELD(temp_r1_9, s16 *, 0x12) = (s16) (*sp20 & ~0x200);
    temp_r1_10 = *data_027e01d8;
    sp1C = temp_r1_10 + 0x12;
    M2C_FIELD(temp_r1_10, s16 *, 0x12) = (s16) (*sp1C & ~0x400);
    temp_r1_11 = *data_027e01d8;
    sp18 = temp_r1_11 + 0x12;
    M2C_FIELD(temp_r1_11, s16 *, 0x12) = (s16) (*sp18 | 0x800);
    temp_r1_12 = *data_027e01d8;
    sp14 = temp_r1_12 + 0x12;
    M2C_FIELD(temp_r1_12, s16 *, 0x12) = (s16) (*sp14 & ~0x1000);
    data_027e01d8 = data_027e00c4;
    temp_r0_8 = *data_027e00c4;
    sp10 = temp_r0_8;
    *temp_r0_8 = *sp10 | 0x10;
    temp_r0_9 = *data_027e01d8;
    spC = temp_r0_9;
    *temp_r0_9 = *spC & ~0x20;
    temp_r1_13 = *data_027e01d8;
    sp8 = temp_r1_13;
    *sp8 = *temp_r1_13 | 0x40;
    temp_r3 = *data_027e01d8;
    sp4 = temp_r3;
    *temp_r3 = *sp4 | 0x80;
    temp_r3_2 = *data_027e01d8;
    sp0 = temp_r3_2;
    *temp_r3_2 = *sp0 & ~0x100;
    M2C_FIELD(*data_027e01d8, s16 *, 0x3C) = 0;
    M2C_FIELD(*data_027e01d8, s16 *, 0x44) = 0;
    func_ov011_02226550(&data_ov011_02228c30, 2);
    data_027e01d8 = temp_r4;
}
