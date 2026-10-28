/* 7 functions from 0x0216ABA8 to 0x0216B898 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_0216aba8(s32 a, M2C_UNK b, M2C_UNK c, M2C_UNK d, s32 e) {
    (void)a;(void)b;(void)c;(void)d;(void)e;
    return 0;
}

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

void func_ov000_0216b194(void *arg0) {
    M2C_UNK func_01ff9e44(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02080cfc(M2C_UNK *, s32);
    s32 func_02080e30(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_0209b59c(s32, M2C_UNK);
    M2C_UNK func_0209b5e4(s32, s32);
    s16 func_0209c268();
    s8 func_020a8ff4(s32);
    M2C_UNK func_020a92bc(void *, u16);
    s32 func_020cfb78();
    s32 func_020e31e0();
    s32 func_020e3218(M2C_UNK *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_02168f14;
    extern void **data_027e0058;
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov000_021b83b0;
    extern M2C_UNK data_ov000_021b83c4;
    extern M2C_UNK data_ov000_021b869c;
    extern M2C_UNK data_ov000_021b86a8;
    extern M2C_UNK data_ov000_021b86b0;
    extern M2C_UNK data_ov000_021b86b8;
    extern M2C_UNK data_ov000_021b86c4;
    extern M2C_UNK data_ov000_021b86cc;
    extern M2C_UNK data_ov000_021b86d4;
    extern M2C_UNK data_ov000_021b86e0;
    extern M2C_UNK data_ov000_021b86e8;
    extern M2C_UNK data_ov000_021b86f8;
    extern M2C_UNK data_ov000_021b8708;
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
    s16 temp_r0_19;
    s32 temp_r0_18;
    s32 temp_r0_23;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r6_4;
    s32 temp_r6_5;
    s32 var_r0;
    s32 var_r3;
    s32 var_r3_2;
    s8 temp_r0_6;
    s8 temp_r6;
    u16 *temp_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_14;
    u16 *temp_r0_15;
    u16 *temp_r0_16;
    u16 *temp_r0_17;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    u16 *temp_r2;
    u16 *temp_r3;
    u16 var_r1;
    u8 temp_r0_20;
    u8 temp_r0_21;
    u8 temp_r0_22;
    void *temp_r4;
    void *temp_r4_2;

    func_0200bc5c(&data_ov000_021b869c);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x16) = 0x10;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x14) = 0x1A;
    if (M2C_FIELD(arg0, u8 *, 0x3D) != 0) {
        var_r1 = (M2C_FIELD(&data_02168f14, u8 *, 3) - M2C_FIELD(*data_027e0058, u16 *, 0x52A2)) + 1;
    } else {
        var_r1 = M2C_FIELD(*data_027e0058, u16 *, 0x52A2);
    }
    func_020a92bc(M2C_FIELD(arg0, void **, 0x40), var_r1);
    temp_r4 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r4, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r4, u8 *, 0x20) & ~0xE0) | 0x20);
    temp_r4_2 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    temp_r0 = M2C_FIELD(data_027e00c8, u16 **, 0);
    sp44 = temp_r0;
    *temp_r0 = *sp44 | 0x10;
    temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp40 = temp_r0_2;
    *temp_r0_2 = *sp40 | 0x20;
    temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp3C = temp_r0_3;
    *temp_r0_3 = *sp3C & ~0x40;
    temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp38 = temp_r0_4;
    *temp_r0_4 = *sp38 | 0x80;
    temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp34 = temp_r0_5;
    *temp_r0_5 = *sp34 | 0x100;
    *(u16 *)0x04000060 = (*(u16 *)0x04000060 & ~0x3000) | 8;
    temp_r6 = func_020a8ff4(*M2C_FIELD(arg0, s32 **, 0x44));
    temp_r0_6 = func_020a8ff4(*M2C_FIELD(arg0, s32 **, 0x44));
    temp_r3 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp30 = temp_r3 + 0x12;
    M2C_FIELD(temp_r3, s16 *, 0x12) = (s16) ((*sp30 & ~0xC0) | 0x40);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x51) = temp_r0_6;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = (s8) (0x10 - temp_r6);
    temp_r0_7 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp2C = temp_r0_7 + 0x12;
    M2C_FIELD(temp_r0_7, s16 *, 0x12) = (s16) (*sp2C & ~1);
    temp_r0_8 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp28 = temp_r0_8 + 0x12;
    M2C_FIELD(temp_r0_8, s16 *, 0x12) = (s16) (*sp28 & ~2);
    temp_r0_9 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp24 = temp_r0_9 + 0x12;
    M2C_FIELD(temp_r0_9, s16 *, 0x12) = (s16) (*sp24 & ~4);
    temp_r0_10 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp20 = temp_r0_10 + 0x12;
    M2C_FIELD(temp_r0_10, s16 *, 0x12) = (s16) (*sp20 | 8);
    temp_r0_11 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp1C = temp_r0_11 + 0x12;
    M2C_FIELD(temp_r0_11, s16 *, 0x12) = (s16) (*sp1C & ~0x10);
    temp_r0_12 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp18 = temp_r0_12 + 0x12;
    M2C_FIELD(temp_r0_12, s16 *, 0x12) = (s16) (*sp18 & ~0x20);
    temp_r0_13 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp14 = temp_r0_13 + 0x12;
    M2C_FIELD(temp_r0_13, s16 *, 0x12) = (s16) (*sp14 | 0x100);
    temp_r0_14 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp10 = temp_r0_14 + 0x12;
    M2C_FIELD(temp_r0_14, s16 *, 0x12) = (s16) (*sp10 | 0x200);
    temp_r0_15 = M2C_FIELD(data_027e01d8, u16 **, 0);
    spC = temp_r0_15 + 0x12;
    M2C_FIELD(temp_r0_15, s16 *, 0x12) = (s16) (*spC & ~0x400);
    temp_r0_16 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp8 = temp_r0_16 + 0x12;
    M2C_FIELD(temp_r0_16, s16 *, 0x12) = (s16) (*sp8 & ~0x800);
    temp_r0_17 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp4 = temp_r0_17 + 0x12;
    M2C_FIELD(temp_r0_17, s16 *, 0x12) = (s16) (*sp4 | 0x1000);
    temp_r2 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp0 = temp_r2 + 0x12;
    M2C_FIELD(temp_r2, s16 *, 0x12) = (s16) (*sp0 | 0x2000);
    func_02080cfc(&data_ov000_021b86a8, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x6E80);
    func_02080cfc(&data_ov000_021b86b0, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x8280);
    func_020e3218(&data_ov000_021b86b8);
    func_020814e4();
    temp_r6_2 = M2C_FIELD(data_027e01d8, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86c4), temp_r6_2 + 0x6B80);
    temp_r6_3 = M2C_FIELD(data_027e01d8, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86cc), temp_r6_3 + 0x8640);
    temp_r6_4 = M2C_FIELD(data_027e01d8, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86d4), temp_r6_4 + 0x87C0);
    func_02081528();
    temp_r0_18 = func_02080e30(&data_ov000_021b86e0, 1);
    func_01ff9e44(temp_r0_18 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0x360, 0x20);
    func_020e35cc(temp_r0_18);
    func_0209b59c(M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x8FC0, 0x60);
    temp_r6_5 = M2C_FIELD(data_027e01d8, s32 *, 0x1C);
    func_0209b5e4(temp_r6_5 + 0x8FC0, func_020cfb78());
    func_02091d4c(0x12);
    M2C_FIELD(arg0, s16 *, 0x3E) = 0x20;
    func_020cfb78();
    temp_r0_19 = func_0209c268();
    if ((s32) temp_r0_19 > 0x40) {
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (M2C_FIELD(arg0, s16 *, 0x3E) - (temp_r0_19 - 0x40));
    }
    if (func_020e31e0() == 2) {
        temp_r0_20 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_20) {                       /* switch 1 */
        default:                                    /* switch 1 */
            var_r0 = 0;
            break;
        case 1:                                     /* switch 1 */
            var_r0 = 0;
            break;
        case 2:                                     /* switch 1 */
            var_r0 = 1;
            break;
        case 3:                                     /* switch 1 */
            var_r0 = 2;
            break;
        case 4:                                     /* switch 1 */
            var_r0 = 3;
            break;
        case 5:                                     /* switch 1 */
            var_r0 = 4;
            break;
        case 0:                                     /* switch 1 */
            var_r0 = 4;
            break;
        }
        if (var_r0 == 0) {
            func_02080cfc(&data_ov000_021b86e8, M2C_FIELD(data_027e00c8, s32 *, 0x18));
            func_02080cfc(&data_ov000_021b86f8, M2C_FIELD(data_027e00c8, s32 *, 0x2C));
        } else {
            goto block_24;
        }
    } else {
block_24:
        temp_r0_21 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_21) {                       /* switch 2 */
        default:                                    /* switch 2 */
            var_r3 = 0;
            break;
        case 1:                                     /* switch 2 */
            var_r3 = 0;
            break;
        case 2:                                     /* switch 2 */
            var_r3 = 1;
            break;
        case 3:                                     /* switch 2 */
            var_r3 = 2;
            break;
        case 4:                                     /* switch 2 */
            var_r3 = 3;
            break;
        case 5:                                     /* switch 2 */
            var_r3 = 4;
            break;
        case 0:                                     /* switch 2 */
            var_r3 = 4;
            break;
        }
        func_02080cfc(*(&data_ov000_021b83b0 + (var_r3 * 4)), M2C_FIELD(data_027e00c8, s32 *, 0x18));
        temp_r0_22 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_22) {                       /* switch 3 */
        default:                                    /* switch 3 */
            var_r3_2 = 0;
            break;
        case 1:                                     /* switch 3 */
            var_r3_2 = 0;
            break;
        case 2:                                     /* switch 3 */
            var_r3_2 = 1;
            break;
        case 3:                                     /* switch 3 */
            var_r3_2 = 2;
            break;
        case 4:                                     /* switch 3 */
            var_r3_2 = 3;
            break;
        case 5:                                     /* switch 3 */
            var_r3_2 = 4;
            break;
        case 0:                                     /* switch 3 */
            var_r3_2 = 4;
            break;
        }
        func_02080cfc(*(&data_ov000_021b83c4 + (var_r3_2 * 4)), M2C_FIELD(data_027e00c8, s32 *, 0x2C));
    }
    func_020808dc(M2C_FIELD(data_027e00c8, s32 *, 0x2C), 0x20, 0x20, 6);
    temp_r0_23 = func_02080e30(&data_ov000_021b8708, 1);
    func_01ff9e44(temp_r0_23 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0xC0, 0x20);
    func_020e35cc(temp_r0_23);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3E) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x46) = 0;
    data_027e01d8 = temp_r4_2;
    M2C_FIELD(arg0, s8 *, 0x36) = 1;
}

