/* 2 functions from 0x021EA57C to 0x021EAED0 (ov003), found by ds-decomp. */
#include "common.h"

u32 func_ov003_021ea57c(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ffaacc(M2C_UNK, u8, u16, M2C_UNK *, s32);
    s32 func_0207c8ec(u32, M2C_UNK);
    s32 func_0207c928(u32, M2C_UNK);
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    s32 func_020846a4();
    s32 func_02086680();
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02098844(M2C_UNK, s32, M2C_UNK, s32, u32, u32, s32);
    M2C_UNK func_02098a34(s8, M2C_UNK, u8, u32, s32);
    M2C_UNK func_020990fc(void *, s8, M2C_UNK, M2C_UNK);
    M2C_UNK func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_020a8f8c(s32);
    s16 func_020a8ff4(s32);
    M2C_UNK func_020abbfc(void *);
    s32 func_ov003_021e6cc4(M2C_UNK, s16, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6d28();
    s32 func_ov003_021e6e40();
    M2C_UNK func_ov003_021e6e94(s8);
    M2C_UNK func_ov003_021ef210(void *, u8, s16, M2C_UNK);
    M2C_UNK func_ov003_021ef758(void *, u8);
    s32 func_ov003_022004d0();
    s32 func_ov003_022004f0(M2C_UNK);
    s8 func_ov003_022008b8(u8);
    extern M2C_UNK data_027e00b4;
    extern u16 **data_027e00c4;
    extern u16 **data_027e00c8;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_ov003_0220f8ac;
    u16 **sp14;
    u16 **sp10;
    u16 **spC;
    s16 temp_r1;
    s16 temp_r2;
    s16 temp_r2_2;
    s16 temp_r3;
    s16 temp_r6_2;
    s16 temp_r8_2;
    s16 temp_r9;
    s32 temp_r1_3;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r4_2;
    s32 temp_r5_2;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r7;
    s8 temp_r0_2;
    s8 temp_r0_3;
    s8 temp_r0_4;
    s8 temp_r4;
    s8 temp_r5;
    u16 **temp_r6;
    u16 **temp_r8;
    u16 temp_r4_3;
    u32 temp_r0;
    u32 var_r7_2;
    u32 var_r8;
    u32 var_r9;
    u32 var_r9_2;
    u8 var_r0;
    u8 var_r0_2;
    u8 var_r0_3;
    u8 var_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r1_2;
    void *temp_r1_4;
    void *temp_r3_2;
    void *temp_r5_3;

    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), u8 *, 0x13) != 0) {
        temp_r6 = data_027e01d8;
        data_027e01d8 = data_027e00c4;
        func_01ff9ce8(3);
        temp_r5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0xF);
        temp_r4 = func_ov003_022008b8((u8) temp_r5);
        if (temp_r4 == 0) {
            func_02088da8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x78));
        } else {
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
                func_02088d94(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x78));
            }
            func_020990fc(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x78), temp_r4, 8, 0);
            func_ov003_021e6e94(temp_r5);
            func_0209b2b4(1, 8, 3, func_02086680(), 0x2000, (s32) (u16) ((((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1E) >> 0x1F) * 0xE0) + 1));
        }
        M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
        data_027e01d8 = temp_r6;
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1E) >> 0x1F) == 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) ((M2C_FIELD(arg0, u8 *, 0x3A) & ~2) | ((u32) (var_r0 << 0x1F) >> 0x1E));
    }
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1C) >> 0x1F) != 0) {
        var_r9 = 0;
        if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4) > 0) {
            temp_r8 = data_027e01d8;
            do {
                data_027e01d8 = data_027e00c8;
                if (func_0207c928(var_r9, 2) != 0) {
                    var_r0_2 = 1;
                } else {
                    var_r0_2 = 0;
                }
                if (var_r9 < 2U) {
                    var_r7 = 0;
                } else {
                    var_r7 = (s32) ((u32) (func_ov003_022004f0(2) << 0x10) >> 3) >> 0x10;
                }
                temp_r0_2 = func_ov003_022008b8(M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r9), u8 *, 0xA));
                if (temp_r0_2 == 0) {
                    func_020809c0(M2C_FIELD(&data_027e01d8[var_r0_2], s32 *, 0x20) + ((var_r7 + 1) * 2), 7, 7);
                } else {
                    func_02098844(1, var_r7, 0, M2C_FIELD(&data_027e01d8[var_r0_2], s32 *, 0x20) + 2, (u32) ((((s32) ((temp_r0_2 - 1) << 0x18) >> 0x11) + 2) << 0xF) >> 0x10, var_r9, 0);
                }
                var_r9 = (u32) (u8) (var_r9 + 1);
                M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | (1 << var_r0_2));
                data_027e01d8 = temp_r8;
            } while ((s32) var_r9 < (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4));
        }
        var_r9_2 = 0;
        sp10 = data_027e01d8;
        data_027e01d8 = data_027e00c8;
        if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4) > 0) {
            do {
                if (func_0207c928(var_r9_2, 2) != 0) {
                    var_r0_3 = 1;
                } else {
                    var_r0_3 = 0;
                }
                if (var_r9_2 >= 2U) {
                    func_ov003_022004f0(2);
                }
                temp_r0_3 = func_ov003_022008b8(M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r9_2), u8 *, 0xA));
                if (var_r9_2 != M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7)) {
                    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
                        var_r1 = 1;
                    } else {
                        var_r1 = 0;
                    }
                    if (!(var_r1 & 0xFF)) {
                        goto block_37;
                    }
                    if (temp_r0_3 != 0) {
                        func_02098a34(temp_r0_3, 1, var_r0_3, var_r9_2, 1);
                    }
                } else {
block_37:
                    if (temp_r0_3 != 0) {
                        func_02098a34(temp_r0_3, 1, var_r0_3, var_r9_2, 0);
                    }
                }
                var_r9_2 = (u32) (u8) (var_r9_2 + 1);
            } while ((s32) var_r9_2 < (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4));
        }
        M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
        M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
        data_027e01d8 = sp10;
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(arg0, u8 *, 0x3A) & ~0x70) & ~8);
    }
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x19) >> 0x1D) != 0) {
        var_r8 = 0;
        spC = data_027e01d8;
        data_027e01d8 = data_027e00c8;
        if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4) > 0) {
            do {
                if (func_0207c928(var_r8, 2) != 0) {
                    var_r0_4 = 1;
                } else {
                    var_r0_4 = 0;
                }
                if (var_r8 >= 2U) {
                    func_ov003_022004f0(2);
                }
                temp_r0_4 = func_ov003_022008b8(M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0xA));
                if (var_r8 != M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7)) {
                    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
                        var_r1_2 = 1;
                    } else {
                        var_r1_2 = 0;
                    }
                    if (!(var_r1_2 & 0xFF)) {
                        goto block_56;
                    }
                    if (temp_r0_4 != 0) {
                        func_02098a34(temp_r0_4, 1, var_r0_4, var_r8, 1);
                    }
                } else {
block_56:
                    if (temp_r0_4 != 0) {
                        func_02098a34(temp_r0_4, 1, var_r0_4, var_r8, 0);
                    }
                }
                var_r8 = (u32) (u8) (var_r8 + 1);
            } while ((s32) var_r8 < (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4));
        }
        M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
        M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
        data_027e01d8 = spC;
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) & ~0x70);
    }
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x3C));
    func_020abbfc(M2C_FIELD(arg0, void **, 0x40));
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x44));
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x48));
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x4C));
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x50));
    temp_r9 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x3C));
    temp_r3 = 0 - temp_r9;
    sp14 = data_027e01d8;
    data_027e01d8 = data_027e00c8;
    temp_r4_2 = temp_r9 - 8;
    M2C_FIELD(*data_027e00c8, s16 *, 0x3E) = temp_r3;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x46) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x38) = (s16) (0 - (temp_r4_2 + func_ov003_022004d0()));
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x40) = 0xFFF0;
    temp_r5_2 = func_ov003_022004d0();
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3A) = (s16) (0 - (temp_r4_2 + temp_r5_2 + func_ov003_022004f0(1)));
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x42) = 0xFFF0;
    temp_r5_3 = M2C_FIELD(arg0, void **, 0x68);
    temp_r8_2 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x48));
    var_r7_2 = 0;
    do {
        temp_r6_2 = temp_r8_2 + ((func_0207c928(var_r7_2, 4) * 0x31) + 0x1D);
        temp_r2 = temp_r6_2;
        temp_r3_2 = temp_r5_3 + (var_r7_2 * 4);
        temp_r1 = (func_0207c8ec(var_r7_2, 4) * 0x12) + 0x59;
        temp_r0_5 = M2C_FIELD(temp_r3_2, void **, 0x14);
        var_r7_2 += 1;
        M2C_FIELD(temp_r0_5, s16 *, 0x34) = temp_r2;
        M2C_FIELD(temp_r0_5, s16 *, 0x36) = temp_r1;
        temp_r0_6 = M2C_FIELD(temp_r3_2, void **, 0x44);
        M2C_FIELD(temp_r0_6, s16 *, 0x34) = temp_r2;
        M2C_FIELD(temp_r0_6, s16 *, 0x36) = temp_r1;
    } while ((s32) var_r7_2 < 0xC);
    temp_r1_2 = M2C_FIELD(temp_r5_3, void **, 0x74);
    M2C_FIELD(temp_r1_2, s16 *, 0x34) = (s16) (temp_r8_2 + 0xB0);
    M2C_FIELD(temp_r1_2, s16 *, 0x36) = 0x8F;
    func_ov003_021ef210(arg0, (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4), temp_r9, 0);
    temp_r2_2 = temp_r9;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x38) = temp_r2_2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x38) = temp_r2_2;
    func_01ffaacc(0, (u8) func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x4C)), (u16) ((0x3FF & (0x5C0 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x8C00), &data_ov003_0220f8ac, 0xB);
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 1) {
        var_r0_5 = 1;
    } else {
        var_r0_5 = 0;
    }
    if (!(var_r0_5 & 0xFF)) {
        func_ov003_021ef758(arg0, (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4));
    }
    if (func_ov003_021e6d28() != 0) {
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
            var_r0_6 = 1;
        } else {
            var_r0_6 = 0;
        }
        if (var_r0_6 & 0xFF) {
            temp_r3_3 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x4C)) - 0x5E;
            func_01ffaacc(0xC0, (u8) (s16) (((u32) (temp_r3_3 << 5) >> 0x1F) + ((temp_r3_3 << 5) / 98) + 0xA0), (u16) ((0x3FF & (0x660 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x8000), &data_027e00b4, 0xB);
        }
    }
    if ((func_ov003_021e6e40() != 0) && (func_020846a4() != 0)) {
        temp_r1_3 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x4C)) - 0x5E;
        temp_r3_4 = ((u32) (temp_r1_3 * 0xA) >> 0x1F) + ((temp_r1_3 * 0xA) / 98);
        temp_r1_4 = M2C_FIELD(arg0, void **, 0x60);
        M2C_FIELD(temp_r1_4, s16 *, 0x34) = 0;
        M2C_FIELD(temp_r1_4, s16 *, 0x36) = (s16) (0xC0 - temp_r3_4);
    }
    data_027e01d8 = data_027e00c4;
    temp_r4_3 = 0 - temp_r9;
    M2C_FIELD(*data_027e00c4, u16 *, 0x38) = temp_r4_3;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x40) = 4;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), u16 *, 0x3E) = temp_r4_3;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x46) = 7;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x78), s16 *, 0x34) = (s16) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s16 *, 0xA) + 0x60);
    if (func_ov003_021e6cc4(0, func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x44)), 0x100, 0x20) != 0) {
        func_01ffaacc(0, (u8) func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x44)), (u16) ((0x3FF & (0x140 >> ((u32) (*M2C_FIELD(data_027e01d8, u16 **, 0) << 0x11) >> 0x1E))) | 0x6C00), &data_ov003_0220f8ac, 0xB);
    }
    data_027e01d8 = sp14;
    return (u32) sp14;
}

u8 func_ov003_021eaeb0(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
