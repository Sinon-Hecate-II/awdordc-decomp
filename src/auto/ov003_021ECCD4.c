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
    s32 IsLinkSessionActive();
    s32 func_02084d3c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02084d88(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088f1c(s32);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_0208b758(s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s16 GetSpriteAnimValue(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 InRange(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6d28();
    M2C_UNK func_ov003_021e74ac(void *, M2C_UNK);
    s16 func_ov003_022004a8(u8);
    s32 sp0[9];
    s32 temp_r3_2;
    s16 x, y;
    void *temp_r4_7;
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
    u32 spriteFlags;
    u32 temp_r1;
    u32 temp_r7;
    u8 var_r4;
    void *temp_r0_2;
    void *temp_r1_2;
    void *temp_r3;
    void *temp_r3_3;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;
    void *temp_r4_6;
    s32 temp_r4_8;
    void *temp_r6;
    void *temp_r6_2;

    PlaySoundEffect(0x1000D);
    if (IsLinkSessionActive() != 0) {
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
            if (((u32) ((u8)temp_r1 << 0x1C) >> 0x1E) == 0) {
                var_r0_4 = 1;
            } else {
                var_r0_4 = 0;
            }
            M2C_FIELD(arg0, u8 *, 0x39) = temp_r1;
            if ((var_r0_4 & 0xFF) && (func_ov003_021e6d28() != 0)) {
                func_02088d94(M2C_FIELD(arg0, void **, 0x58));
                func_02088f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s32 *, 0));
            }
            temp_r4 = M2C_FIELD(arg0, void **, 0x64);
            temp_r7 = (u8)GetPanelCount(M2C_FIELD(arg0, void **, 0x6C));
            if (IsLinkSessionActive() == 0) {
                var_r6 = 0;
                do {
                    if (var_r6 < temp_r7) {
                        func_02088d94(M2C_FIELD((temp_r4 + (var_r6 * 4)), void **, 8));
                        func_02088d94(M2C_FIELD((temp_r4 + (var_r6 * 4)), void **, 0x18));
                    }
                    var_r6 = (u32) (u8) (var_r6 + 1);
                } while (var_r6 < 4U);
            }
            temp_r4_2 = M2C_FIELD(arg0, void **, 0x48);
            M2C_FIELD(temp_r4_2, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_2);
            M2C_FIELD(temp_r4_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r4_2, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_2, u16 *, 2) = (u16) M2C_FIELD(temp_r4_2, u16 *, 4);
            temp_r4_3 = M2C_FIELD(arg0, void **, 0x50);
            M2C_FIELD(temp_r4_3, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_3);
            M2C_FIELD(temp_r4_3, s16 *, 0x10) = 0x100;
            M2C_FIELD(temp_r4_3, s16 *, 0xC) = 0xC;
            M2C_FIELD(temp_r4_3, u16 *, 2) = (u16) M2C_FIELD(temp_r4_3, u16 *, 4);
            temp_r4_4 = M2C_FIELD(arg0, void **, 0x4C);
            M2C_FIELD(temp_r4_4, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_4);
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
                M2C_FIELD(temp_r4_5, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_5);
                M2C_FIELD(temp_r4_5, s16 *, 0x10) = -0x100;
                M2C_FIELD(temp_r4_5, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_5, u16 *, 2) = (u16) M2C_FIELD(temp_r4_5, u16 *, 4);
                temp_r4_6 = M2C_FIELD(arg0, void **, 0x50);
                M2C_FIELD(temp_r4_6, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_6);
                M2C_FIELD(temp_r4_6, s16 *, 0x10) = 0;
                M2C_FIELD(temp_r4_6, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_6, u16 *, 2) = (u16) M2C_FIELD(temp_r4_6, u16 *, 4);
                temp_r4_7 = M2C_FIELD(arg0, void **, 0x4C);
                M2C_FIELD(temp_r4_7, s16 *, 0xE) = GetSpriteAnimValue(temp_r4_7);
                M2C_FIELD(temp_r4_7, s16 *, 0x10) = 0x5E;
                M2C_FIELD(temp_r4_7, s16 *, 0xC) = 0xC;
                M2C_FIELD(temp_r4_7, u16 *, 2) = (u16) M2C_FIELD(temp_r4_7, u16 *, 4);
            }
            func_ov003_021e74ac(M2C_FIELD(arg0, void **, 0x6C), 1);
            temp_r6_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
            temp_r4_8 = func_020aae44(temp_r6_2);
            temp_r3_2 = func_020aae10(temp_r6_2) & (-0x200U >> 0x17);
            y = M2C_FIELD(temp_r6_2, s16 *, 0x36);
            x = M2C_FIELD(temp_r6_2, s16 *, 0x34);
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x58);
            M2C_FIELD(temp_r1_2, s16 *, 0x34) = x;
            M2C_FIELD(temp_r1_2, s16 *, 0x36) = y;
            spriteFlags = (M2C_FIELD(temp_r1_2, u32 *, 0x40) & ~0x1FF) | temp_r3_2;
            spriteFlags &= ~(0x1FFU << 9);
            M2C_FIELD(temp_r1_2, u32 *, 0x40) = spriteFlags | ((u32)(temp_r4_8 << 0x17) >> 0xE);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
                temp_r0_3 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
                if (InRange((u8) temp_r0_3, 0, 3) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (InRange((u8) temp_r0_3, 4, 7) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
                } else if (InRange((u8) temp_r0_3, 8, 0x14) != 0) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
                } else if (InRange((u8) temp_r0_3, 0x15, 0x18) != 0) {
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

#pragma opt_propagation off
void func_ov003_021ed27c(void *arg0, u32 arg1) {
    s32 IsLinkSessionActive();
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02089438(void *);
    M2C_UNK func_0208b758(s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 InRange(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6e08(u32);
    M2C_UNK func_ov003_021e6e18(u32);
    M2C_UNK HandleWaypointInput(void *, u32);
    s16 func_ov003_022004a8(u8);
    M2C_UNK func_ov003_022006b0(M2C_UNK, u8);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *temp_r7;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r5_3;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r1_4;
    u8 temp_r0_2;s16 xpos,ypos;u8 byte7,byte8;u32 mask;
    u32 temp_r0_3;
    u32 temp_r0_5;
    u32 temp_r0_6;
    u32 temp_r0_7;
    u8 temp_r5_2;
    void *temp_r0;
    void *temp_r0_4;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r1_5;
    void *temp_r5_4;
    void *temp_r5_5;
    void *temp_r5_6;


    if (IsLinkSessionActive() == 0) {
        var_r0 = 1;
    } else {
        temp_r5 = func_ov003_021e6e08(arg1);
        func_ov003_021e6e18(arg1);
        if(temp_r5==0||temp_r5==25||temp_r5==8)var_r0=1;
        else if(temp_r5==4)var_r0=0;
        else if(func_ov003_021e6cfc()!=0 && temp_r5==21)var_r0=1;else var_r0=0;
    }
    if (var_r0 == 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_r5_2 = (u8) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0xE0), u16 *, 0x2E);
    HandleWaypointInput(temp_r0, arg1);
    if (temp_r5_2 != (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E)) {
        PlaySoundEffect(0x10019);
        temp_r7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
        temp_r5_3 = func_020aae44(temp_r7);
        temp_r3=func_020aae10(temp_r7);mask=-512U;temp_r3&=mask>>23;ypos=M2C_FIELD(temp_r7,s16*,0x36);xpos=M2C_FIELD(temp_r7,s16*,0x34);
        temp_r1 = M2C_FIELD(arg0, void **, 0x58);
        M2C_FIELD(temp_r1, s16 *, 0x34) = xpos;
        M2C_FIELD(temp_r1, s16 *, 0x36) = ypos;
        M2C_FIELD(temp_r1, s32 *, 0x40) = (s32) ((((M2C_FIELD(temp_r1, s32 *, 0x40) & mask) | temp_r3) & 0xFFFC01FF) | ((u32) (temp_r5_3 << 0x17) >> 0xE));
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
            temp_r0_2 = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
            if (InRange((u8) temp_r0_2, 0, 3) != 0) {
                func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
            } else if (InRange((u8) temp_r0_2, 4, 7) != 0) {
                func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
            } else if (InRange((u8) temp_r0_2, 8, 0x14) != 0) {
                func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
            } else if (InRange((u8) temp_r0_2, 0x15, 0x18) != 0) {
                func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000010);
            } else if ((u8) temp_r0_2 == 0x19) {
                temp_r0_3 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
                if (temp_r0_3 == 0) {
                    var_r1 = 1;
                } else {
                    var_r1 = 0;
                }
                if (var_r1 & 0xFF) {
                    func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000016);
                } else {
                    if (temp_r0_3 == 1) {
                        var_r0_2 = 1;
                    } else {
                        var_r0_2 = 0;
                    }
                    if (var_r0_2 & 0xFF) {
                        func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000017);
                    }
                }
            }
        }
        temp_r0_4 = M2C_FIELD(arg0, void **, 0x6C);
        temp_r1_2 = M2C_FIELD(arg0, void **, 0x40);
        byte8=M2C_FIELD(temp_r0_4,u8*,8);byte7=M2C_FIELD(temp_r0_4,u8*,7);M2C_FIELD(temp_r1_2,u8*,16)=byte7;
        M2C_FIELD(temp_r1_2, u8 *, 0x11) = byte8;
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) | 8);
    }
    switch (arg1) {                                 /* switch 2 */
    default:                                        /* switch 2 */
        return;
    case 0:                                         /* switch 2 */
    case 1:                                         /* switch 2 */
    case 2:                                         /* switch 2 */
    case 3:                                         /* switch 2 */
    case 4:                                         /* switch 2 */
    case 5:                                         /* switch 2 */
    case 6:                                         /* switch 2 */
    case 7:                                         /* switch 2 */
    case 25:                                        /* switch 2 */
        M2C_FIELD(arg0, u8 *, 0x39) = (u8) (M2C_FIELD(arg0, u8 *, 0x39) & ~0xF0);
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) ((M2C_FIELD(arg0, u8 *, 0x3A) & ~0x70) | 0x10);
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 1) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            temp_r5_4 = gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineMain;
            func_ov003_022006b0(0x19, M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
            gCur3DSpriteEngine = temp_r5_4;
        }
        temp_r0_5 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C;
        if (temp_r0_5 == 1) {
            var_r1_2 = 1;
        } else {
            var_r1_2 = 0;
        }
        if (!(var_r1_2 & 0xFF)) {
            if (temp_r0_5 == 3) {
                var_r0_4 = 1;
            } else {
                var_r0_4 = 0;
            }
            if (var_r0_4 & 0xFF) {
                goto block_79;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 1;
        } else {
block_79:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 0;
        }
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
            var_r0_5 = 1;
        } else {
            var_r0_5 = 0;
        }
        if (var_r0_5 & 0xFF) {
            temp_r1_3 = M2C_FIELD(arg0, void **, 0x6C);
            M2C_FIELD(temp_r1_3, u8 *, 9) = (u8) M2C_FIELD(temp_r1_3, u8 *, 8);
            func_02089438(M2C_FIELD(arg0, void **, 0x5C));
            func_02088d94(M2C_FIELD(arg0, void **, 0x5C));
            return;
        }
        func_02088da8(M2C_FIELD(arg0, void **, 0x5C));
        return;
    case 8:                                         /* switch 2 */
    case 9:                                         /* switch 2 */
    case 10:                                        /* switch 2 */
    case 11:                                        /* switch 2 */
    case 12:                                        /* switch 2 */
    case 13:                                        /* switch 2 */
    case 14:                                        /* switch 2 */
    case 15:                                        /* switch 2 */
    case 16:                                        /* switch 2 */
    case 17:                                        /* switch 2 */
    case 18:                                        /* switch 2 */
    case 19:                                        /* switch 2 */
    case 20:                                        /* switch 2 */
        M2C_FIELD(arg0, u8 *, 0x39) = (u8) ((M2C_FIELD(arg0, u8 *, 0x39) & ~0xF0) | 0x20);
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) ((M2C_FIELD(arg0, u8 *, 0x3A) & ~0x70) | 0x10);
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 1) {
            var_r0_6 = 1;
        } else {
            var_r0_6 = 0;
        }
        if (var_r0_6 & 0xFF) {
            temp_r5_5 = gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineMain;
            func_ov003_022006b0(0x19, M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
            gCur3DSpriteEngine = temp_r5_5;
        }
        temp_r0_6 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C;
        if (temp_r0_6 == 1) {
            var_r1_3 = 1;
        } else {
            var_r1_3 = 0;
        }
        if (!(var_r1_3 & 0xFF)) {
            if (temp_r0_6 == 3) {
                var_r0_7 = 1;
            } else {
                var_r0_7 = 0;
            }
            if (var_r0_7 & 0xFF) {
                goto block_100;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 1;
        } else {
block_100:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 0;
        }
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
            var_r0_8 = 1;
        } else {
            var_r0_8 = 0;
        }
        if (var_r0_8 & 0xFF) {
            temp_r1_4 = M2C_FIELD(arg0, void **, 0x6C);
            M2C_FIELD(temp_r1_4, u8 *, 9) = (u8) M2C_FIELD(temp_r1_4, u8 *, 8);
            func_02089438(M2C_FIELD(arg0, void **, 0x5C));
            func_02088d94(M2C_FIELD(arg0, void **, 0x5C));
            return;
        }
        func_02088da8(M2C_FIELD(arg0, void **, 0x5C));
        return;
    case 21:                                        /* switch 2 */
    case 22:                                        /* switch 2 */
    case 23:                                        /* switch 2 */
    case 24:                                        /* switch 2 */
        M2C_FIELD(arg0, u8 *, 0x39) = (u8) (M2C_FIELD(arg0, u8 *, 0x39) & ~0xF0);
        M2C_FIELD(arg0, u8 *, 0x3A) = (u8) ((M2C_FIELD(arg0, u8 *, 0x3A) & ~0x70) | 0x10);
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 1) {
            var_r0_9 = 1;
        } else {
            var_r0_9 = 0;
        }
        if (var_r0_9 & 0xFF) {
            temp_r5_6 = gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineMain;
            func_ov003_022006b0(0x19, M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
            gCur3DSpriteEngine = temp_r5_6;
        }
        temp_r0_7 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C;
        if (temp_r0_7 == 1) {
            var_r1_4 = 1;
        } else {
            var_r1_4 = 0;
        }
        if (!(var_r1_4 & 0xFF)) {
            if (temp_r0_7 == 3) {
                var_r0_10 = 1;
            } else {
                var_r0_10 = 0;
            }
            if (var_r0_10 & 0xFF) {
                goto block_121;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 1;
        } else {
block_121:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s8 *, 0x59) = 0;
        }
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
            var_r0_11 = 1;
        } else {
            var_r0_11 = 0;
        }
        if (var_r0_11 & 0xFF) {
            temp_r1_5 = M2C_FIELD(arg0, void **, 0x6C);
            M2C_FIELD(temp_r1_5, u8 *, 9) = (u8) M2C_FIELD(temp_r1_5, u8 *, 8);
            func_02089438(M2C_FIELD(arg0, void **, 0x5C));
            func_02088d94(M2C_FIELD(arg0, void **, 0x5C));
            return;
        }
        func_02088da8(M2C_FIELD(arg0, void **, 0x5C));
        return;
    }
}
#pragma opt_propagation reset

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

