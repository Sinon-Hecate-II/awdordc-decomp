/* 6 functions from 0x021ECCD4 to 0x021ED8F0 (ov003), found by ds-decomp. */
#include "common.h"

static inline s8 GetPanelCount(void *p) {
    return M2C_FIELD(p, s8 *, 4);
}

static inline void CallPanelUpdate(void *p) {
    M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 0x1c)(p);
}

#pragma opt_common_subs off
void func_ov003_021eccd4(void *arg0) {
    s32 func_020846a4();
    s32 func_02084d3c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02084d88(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088f1c(s32);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_0208b758(s32, s32);
    M2C_UNK func_0208fe30(s32);
    s16 func_020a8ff4(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 func_ov003_021e6cac(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6d28();
    M2C_UNK func_ov003_021e74ac(void *, M2C_UNK);
    s16 func_ov003_022004a8(u8);
    s32 sp0[9];
    s32 temp_r3_2;
    s32 temp_r4_8;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r1;
    s32 var_r1_2;
    u8 temp_r0_3;
    u32 temp_r0;
    u32 temp_r0_4;
    u32 var_r6;
    u8 temp_r1;
    u8 temp_r7;
    u8 var_r4;
    void *temp_r0_2;
    void *temp_r1_2;
    void *temp_r3;
    void *temp_r3_3;
    
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    void *temp_r4_7;
    void *temp_r6;
    void *temp_r6_2;

    func_0208fe30(0x1000D);
    if (func_020846a4() != 0) {
        if (func_02084d3c(sp0, 0x24) == 0) {
            return;
        }
        temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
        if (temp_r0 == 0) {
            var_r1 = 1;
        } else {
            var_r1 = 0;
        }
        if (var_r1 & 0xFF) {
            sp0[6] = 1;
            func_02084d88(sp0, 0x24);
            temp_r3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), void **, 4);
            if ((s32) M2C_FIELD(temp_r3, s8 *, 0x5A) < 0) {
                return;
            }
            M2C_FIELD(temp_r3, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r3, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r3, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r3, s8 *, 0x5A) = 0xC;
            return;
        }
        if (temp_r0 == 1) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (!(var_r0 & 0xFF)) {
            return;
        }
        if (func_ov003_021e6cfc() == 0) {
            return;
        }
        temp_r0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), void **, 4);
        if ((s32) M2C_FIELD(temp_r0_2, s8 *, 0x5A) >= 0) {
            M2C_FIELD(temp_r0_2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0xC;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), void (**)(void *), 0x1C)(arg0);
        return;
    }
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 1) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void (**)(void *), 0x1C)(arg0);
        } else {
            temp_r1 = (M2C_FIELD(arg0, u8 *, 0x39) & ~0xC) | 4;
            if (((u32) (temp_r1 << 0x1C) >> 0x1E) == 0) {
                var_r0_4 = 1;
            } else {
                var_r0_4 = 0;
            }
            M2C_FIELD(arg0, u8 *, 0x39) = temp_r1;
            if ((var_r0_4 & 0xFF) && (func_ov003_021e6d28() != 0)) {
                func_02088d94(M2C_FIELD(arg0, void **, 0x58));
                func_02088f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s32 *, 0));
            }
            temp_r4_2 = M2C_FIELD(arg0, void **, 0x64);
            temp_r7 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4);
            if (func_020846a4() == 0) {
                var_r6 = 0;
                do {
                    if (var_r6 < (u32) temp_r7) {
                        func_02088d94(M2C_FIELD((temp_r4_2 + (var_r6 * 4)), void **, 8));
                        func_02088d94(M2C_FIELD((temp_r4_2 + (var_r6 * 4)), void **, 0x18));
                    }
                    var_r6 = (u32) (u8) (var_r6 + 1);
                } while (var_r6 < 4U);
            }
            temp_r4_2 = M2C_FIELD(arg0, void **, 0x48);
            M2C_FIELD(temp_r4_2, s16 *, 0xE) = func_020a8ff4(temp_r4_2);
            M2C_FIELD(temp_r4_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r4_2, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_2, u16 *, 2) = (u16) M2C_FIELD(temp_r4_2, u16 *, 4);
            temp_r4_3 = M2C_FIELD(arg0, void **, 0x50);
            M2C_FIELD(temp_r4_3, s16 *, 0xE) = func_020a8ff4(temp_r4_3);
            M2C_FIELD(temp_r4_3, s16 *, 0x10) = 0x100;
            M2C_FIELD(temp_r4_3, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_3, u16 *, 2) = (u16) M2C_FIELD(temp_r4_3, u16 *, 4);
            temp_r4_4 = M2C_FIELD(arg0, void **, 0x4C);
            M2C_FIELD(temp_r4_4, s16 *, 0xE) = func_020a8ff4(temp_r4_4);
            M2C_FIELD(temp_r4_4, s16 *, 0x10) = 0xC0;
            M2C_FIELD(temp_r4_4, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_4, u16 *, 2) = (u16) M2C_FIELD(temp_r4_4, u16 *, 4);
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
                var_r0_5 = 1;
            } else {
                var_r0_5 = 0;
            }
            if (var_r0_5 & 0xFF) {
                if (func_ov003_021e6d28() != 0) {
                    func_02088da8(M2C_FIELD(arg0, void **, 0x58));
                    func_02088ff4(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s32 *, 0));
                }
                temp_r6 = M2C_FIELD(arg0, void **, 0x64);
                var_r4 = 0;
                do {
                    func_02088da8(M2C_FIELD((temp_r6 + (var_r4 * 4)), void **, 8));
                    func_02088da8(M2C_FIELD((temp_r6 + (var_r4 * 4)), void **, 0x18));
                    var_r4 += 1;
                } while ((u32) var_r4 < 4U);
                temp_r4_5 = M2C_FIELD(arg0, void **, 0x48);
                M2C_FIELD(temp_r4_5, s16 *, 0xE) = func_020a8ff4(temp_r4_5);
                M2C_FIELD(temp_r4_5, s16 *, 0x10) = -0x100;
                M2C_FIELD(temp_r4_5, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_5, u16 *, 2) = (u16) M2C_FIELD(temp_r4_5, u16 *, 4);
                temp_r4_6 = M2C_FIELD(arg0, void **, 0x50);
                M2C_FIELD(temp_r4_6, s16 *, 0xE) = func_020a8ff4(temp_r4_6);
                M2C_FIELD(temp_r4_6, s16 *, 0x10) = 0;
                M2C_FIELD(temp_r4_6, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_6, u16 *, 2) = (u16) M2C_FIELD(temp_r4_6, u16 *, 4);
                temp_r4_7 = M2C_FIELD(arg0, void **, 0x4C);
                M2C_FIELD(temp_r4_7, s16 *, 0xE) = func_020a8ff4(temp_r4_7);
                M2C_FIELD(temp_r4_7, s16 *, 0x10) = 0x5E;
                M2C_FIELD(temp_r4_7, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_7, u16 *, 2) = (u16) M2C_FIELD(temp_r4_7, u16 *, 4);
            }
            func_ov003_021e74ac(M2C_FIELD(arg0, void **, 0x6C), 1);
            temp_r6_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
            temp_r4_8 = func_020aae44(temp_r6_2);
            temp_r3_2 = func_020aae10(temp_r6_2) & (-0x200U >> 0x17);
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x58);
            M2C_FIELD(temp_r1_2, s16 *, 0x34) = (s16) M2C_FIELD(temp_r6_2, s16 *, 0x34);
            M2C_FIELD(temp_r1_2, s16 *, 0x36) = (s16) M2C_FIELD(temp_r6_2, s16 *, 0x36);
            M2C_FIELD(temp_r1_2, s32 *, 0x40) = (s32) ((((M2C_FIELD(temp_r1_2, s32 *, 0x40) & ~0x1FF) | temp_r3_2) & 0xFFFC01FF) | ((u32) (temp_r4_8 << 0x17) >> 0xE));
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
                temp_r0_3 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
                if (func_ov003_021e6cac((u8) temp_r0_3, 0, 3) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (func_ov003_021e6cac((u8) temp_r0_3, 4, 7) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
                } else if (func_ov003_021e6cac((u8) temp_r0_3, 8, 0x14) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (func_ov003_021e6cac((u8) temp_r0_3, 0x15, 0x18) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000010);
                } else if ((u8) temp_r0_3 == 0x19) {
                    temp_r0_4 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
                    if (temp_r0_4 == 0) {
                        var_r1_2 = 1;
                    } else {
                        var_r1_2 = 0;
                    }
                    if (var_r1_2 & 0xFF) {
                        func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000016);
                    } else {
                        if (temp_r0_4 == 1) {
                            var_r0_6 = 1;
                        } else {
                            var_r0_6 = 0;
                        }
                        if (var_r0_6 & 0xFF) {
                            func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000017);
                        }
                    }
                }
            }
        }
        temp_r3_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), void **, 4);
        if ((s32) M2C_FIELD(temp_r3_3, s8 *, 0x5A) < 0) {
            return;
        }
        M2C_FIELD(temp_r3_3, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r3_3, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r3_3, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r3_3, s8 *, 0x5A) = 0xC;
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), void (**)(void *), 0x1C)(arg0);
}
#pragma opt_common_subs reset

u8 func_ov003_021ed8a8(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 5) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021ed8c4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 5);
}

u8 func_ov003_021ed8cc(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 6) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021ed8e8(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 6);
}

