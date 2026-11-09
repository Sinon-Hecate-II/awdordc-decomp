/* 10 functions from 0x0221EDA8 to 0x0221F500 (ov007), found by ds-decomp. */
#include "common.h"
typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;
static inline void *InitOv007Text(void *child) {
 s32 func_020e34bc(M2C_UNK); M2C_UNK func_02007f8c(s32,M2C_UNK,M2C_UNK);
    if (child != NULL) {
        M2C_FIELD(child, s16 *, 0x10) = 0x11;
        M2C_FIELD(child, s8 *, 0x12) = 0;
        M2C_FIELD(child, s32 *, 0) = 0;
        M2C_FIELD(child, s32 *, 4) = 0;
        M2C_FIELD(child, s8 *, 8) = -1;
        M2C_FIELD(child, s8 *, 9) = -1;
        M2C_FIELD(child, s8 *, 0xA) = -1;
        M2C_FIELD(child, s8 *, 0xB) = -1;
        M2C_FIELD(child, u8 *, 0xD) = 0xFF;
        M2C_FIELD(child, s8 *, 0xC) = -1;
        M2C_FIELD(child, s8 *, 0xE) = 0;
        M2C_FIELD(child, u8 *, 0xF) = 0xFF;
        M2C_FIELD(child, s32 *, 0x14) = func_020e34bc(0xCC);
        func_02007f8c(M2C_FIELD(child, void **, 0x14), 0, 0xCC);
    }

return child;
}


#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
void func_ov007_0221eda8(void *arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02088044(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b1c60(M2C_UNK);
    s32 func_020e32e8(M2C_UNK *);
    extern void *data_02101e84;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_02220d34;
    extern M2C_UNK data_ov007_02220d40;
    extern M2C_UNK data_ov007_0222192c;
    extern M2C_UNK data_ov007_0222193c;
    extern M2C_UNK data_ov007_0222194c;
    extern M2C_UNK data_ov007_0222195c;
    extern u8 *data_ov007_02221e0c;
    extern M2C_UNK data_ov007_02221e10;
    s16 temp_r3_5;
    s16 temp_r5;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r2_2;
    s32 temp_r3;
    void *temp_r4;
    s32 temp_r1_2;
    s8 temp_r2_2;
    s8 temp_r3_2;
    s8 temp_r3_3;
    s8 temp_r3_4;
    s32 var_r0;
    s32 var_r2;
    u16 temp_r1;
    u16 temp_r2;
    register s32 var_r5;

    func_02088044(M2C_FIELD(arg0, void **, 0x38));
    var_r0 = M2C_FIELD(arg0, s8 *, 0x3C);
    temp_r1 = M2C_FIELD(data_02101e84, u16 *, 0);
    temp_r2 = M2C_FIELD(data_02101e84, u16 *, 2);
    if (temp_r1 & 2) {
        func_020b1c60(0x69);
        return;
    }
    if (temp_r1 & 8) {
        func_020b1c60(0x6A);
        return;
    }
    if (temp_r1 & 0x400) {
        if (var_r0 > 0) {
            temp_r2_2 = var_r0 - 1;
            if (((s32) temp_r2_2 >= 0) && ((s32) temp_r2_2 < 0x11) && ((((s32) temp_r2_2 < 0x11) && (*(s32 *)((u8 *)&data_ov007_02221e10 + (temp_r2_2 * 4)) != 0)) || (((s32) temp_r2_2 > 0) && (*(s32 *)((u8 *)&data_ov007_02221e10 + ((temp_r2_2 - 1) * 4)) != 0)))) {
                M2C_FIELD(arg0, s8 *, 0x3C) = temp_r2_2;
            }
            var_r2 = M2C_FIELD(arg0, s8 *, 0x3C);
            if ((s32) var_r2 < 0x10) {
                do {
                    *(s32 *)((u8 *)&data_ov007_02221e10 + (var_r2 * 4)) = M2C_FIELD(((u8 *)&data_ov007_02221e10 + (var_r2 * 4)), s32 *, 4);
                    var_r2 += 1;
                } while ((s32) var_r2 < 0x10);
            }
            M2C_FIELD(&data_ov007_02221e0c, s32 *, 0x44) = 0;
            func_0208fe30(0x1000D);
            return;
        }
        if ((var_r0 == 0) && (*(s32 *)((u8 *)&data_ov007_02221e10 + (var_r0 * 4)) != 0)) {
            if ((s32) var_r0 < 0x10) {
                do {
                    *(s32 *)((u8 *)&data_ov007_02221e10 + (var_r0 * 4)) = M2C_FIELD(((u8 *)&data_ov007_02221e10 + (var_r0 * 4)), s32 *, 4);
                    var_r0 += 1;
                } while ((s32) var_r0 < 0x10);
            }
            M2C_FIELD(&data_ov007_02221e0c, s32 *, 0x44) = 0;
            func_0208fe30(0x1000D);
            return;
        }
        func_0208fe30(0x1001D);
        return;
    }
    if (temp_r1 & 0x800) {
        temp_r3 = M2C_FIELD(arg0, s32 *, 0x34);
        var_r2_2 = 0;
loop_25:
        if (temp_r3 == *(s32 *)((u8 *)&data_ov007_02220d40 + (var_r2_2 * 4))) {
            var_r5 = var_r2_2 + 0x64;
        } else {
            var_r2_2 += 1;
            if (var_r2_2 >= 3) {
                var_r5 = 0x64;
            } else {
                goto loop_25;
            }
        }
        switch (var_r5) {                           /* switch 1; irregular */
        case 0x66:                                  /* switch 1 */
            var_r5 = 0x64;
            break;
        case 0x64:                                  /* switch 1 */
            var_r5 = 0x65;
            break;
        case 0x65:                                  /* switch 1 */
            var_r5 = 0x66;
            break;
        }
        if ((var_r5 >= 0x64) && (var_r5 < 0x67)) {
            M2C_FIELD(arg0, s32 *, 0x34) = (s32) *(s32 *)((u8 *)&data_ov007_02220d40 + ((var_r5 - 0x64) * 4));
        }
        if (temp_r3 == M2C_FIELD(arg0, s32 *, 0x34)) {
            return;
        }
        func_0200bc5c(&data_ov007_02220d34);
        temp_r4 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        func_020e32e8(&data_ov007_0222192c);
        func_020814e4();
        switch (var_r5) {                           /* switch 2; irregular */
        case 0x66:                                  /* switch 2 */
            func_02081590(func_020e32e8(&data_ov007_0222195c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        case 0x64:                                  /* switch 2 */
            func_02081590(func_020e32e8(&data_ov007_0222194c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        case 0x65:                                  /* switch 2 */
            func_02081590(func_020e32e8(&data_ov007_0222193c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        }
        func_02081528();
        func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 0x18, 5);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        gCur3DSpriteEngine = temp_r4;
        func_0208fe30(0x10011);
        return;
    }
    if (temp_r2 & 0x200) {
        temp_r3_2 = var_r0 - 1;
        if (((s32) temp_r3_2 >= 0) && ((s32) temp_r3_2 < 0x11) && ((((s32) temp_r3_2 < 0x11) && (*(s32 *)((u8 *)&data_ov007_02221e10 + (temp_r3_2 * 4)) != 0)) || (((s32) temp_r3_2 > 0) && (*(s32 *)((u8 *)&data_ov007_02221e10 + ((temp_r3_2 - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = temp_r3_2;
        }
    } else if (temp_r2 & 0x100) {
        temp_r3_3 = var_r0 + 1;
        if (((s32) temp_r3_3 >= 0) && ((s32) temp_r3_3 < 0x11) && ((((s32) temp_r3_3 < 0x11) && (*(s32 *)((u8 *)&data_ov007_02221e10 + (temp_r3_3 * 4)) != 0)) || (((s32) temp_r3_3 > 0) && (*(s32 *)((u8 *)&data_ov007_02221e10 + ((temp_r3_3 - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = temp_r3_3;
        }
    }
    temp_r1_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s8 *, 0xC);
    if ((s32) temp_r1_2 >= 0) {
        temp_r3_4 = (s8)temp_r1_2;
        if (((s32) temp_r3_4 >= 0) && ((s32) temp_r3_4 < 0x11) && ((((s32) temp_r3_4 < 0x11) && (*(s32 *)((u8 *)&data_ov007_02221e10 + (temp_r3_4 * 4)) != 0)) || (((s32) temp_r3_4 > 0) && (*(s32 *)((u8 *)&data_ov007_02221e10 + ((temp_r3_4 - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = temp_r3_4;
        }
    }
    temp_r3_5 = M2C_FIELD(arg0, s16 *, 0x3E);
    temp_r5 = (M2C_FIELD(arg0, s8 *, 0x3C) * 8) + 0x10;
    if ((temp_r3_5 == -0x8000) && (M2C_FIELD(arg0, s16 *, 0x40) == -0x8000)) {
        goto block_81;
    }
    var_r1 = temp_r3_5 - temp_r5;
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    if (var_r1 <= 1) {
        var_r1_2 = M2C_FIELD(arg0, s16 *, 0x40) - 0x10;
        if (var_r1_2 < 0) {
            var_r1_2 = 0 - var_r1_2;
        }
        if (var_r1_2 <= 1) {
block_81:
            M2C_FIELD(arg0, s16 *, 0x3E) = temp_r5;
            M2C_FIELD(arg0, s16 *, 0x40) = 0x10;
        } else {
            goto block_82;
        }
    } else {
block_82:
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) ((s32) (temp_r5 + temp_r3_5 + 1) >> 1);
        M2C_FIELD(arg0, s16 *, 0x40) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x40) + 0x11) >> 1);
    }
    if (var_r0 == M2C_FIELD(arg0, s8 *, 0x3C)) {
        return;
    }
    func_0208fe30(0x10019);
}
#pragma pop
void func_ov007_0221f220(void) {
    M2C_UNK func_ov007_0221ec40();
    func_ov007_0221ec40();
}

void func_ov007_0221f22c(void) {
    M2C_UNK func_ov007_0221e878();
    func_ov007_0221e878();
}

void func_ov007_0221f238(void) {
    M2C_UNK func_ov007_0221e6d0();
    func_ov007_0221e6d0();
}

void func_ov007_0221f244(void) {
    M2C_UNK func_ov007_0221e85c();
    func_ov007_0221e85c();
}

void func_ov007_0221f250(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov007_0221f264(void) {
    M2C_UNK func_ov007_0221ec34();
    func_ov007_0221ec34();
}

void func_ov007_0221f270(u8 *arg0) {
    void *func_01ffa42c(M2C_UNK *);
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_02008048(u8 *, M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    s32 func_02099ae8(u8 *);
    s32 func_02099b00(u8 *);
    s32 func_020e31e0();
    s32 func_020e34bc(M2C_UNK);
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_ov007_02220df8;
    extern M2C_UNK data_ov007_02220ea0;
    extern M2C_UNK data_ov007_02221224;
    extern M2C_UNK data_ov007_02221974;
    extern u8 *data_ov007_02221e0c;
    extern M2C_UNK data_ov007_02221e10;
    M2C_UNK *var_r1;
    u32 var_r8;
    s32 temp_r0_3;
    M2C_UNK *var_r9;
    u8 *var_r5;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_4;

    var_r5 = arg0;
    temp_r0 = func_01ffa42c(&data_ov007_02220df8);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov007_02221974;
    if (func_020e31e0() == 0) {
        var_r1 = &data_ov007_02221224;
    } else {
        var_r1 = &data_ov007_02220ea0;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = var_r1;
    M2C_FIELD(temp_r0, void **, 0x38) = NULL;
    M2C_FIELD(temp_r0, s8 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x3E) = -0x8000;
    M2C_FIELD(temp_r0, s16 *, 0x40) = -0x8000;
    M2C_FIELD(temp_r0, void **, 0x44) = NULL;
    data_ov007_02221e0c = var_r5;
    func_02007e98(0, &data_ov007_02221e10, 0x44);
    var_r9 = &data_ov007_02221e10;
    var_r8 = 0;
    while ((*var_r5 != 0) && (var_r8 < 0x10U)) {
        if ((func_02099ae8(var_r5) != 0) || (func_02099b00(var_r5) != 0)) {
            func_02008048(var_r5, var_r9, 2);
            var_r5 += 2;
        } else {
            func_02008048(var_r5, var_r9, 1);
            var_r5 += 1;
        }
        var_r8 += 1;
        var_r9 = (M2C_UNK *)((u8 *)var_r9 + 4);

    }
    temp_r0_2 = InitOv007Text(func_02082028(0x24));
    M2C_FIELD(temp_r0, void **, 0x38) = temp_r0_2;
    temp_r0_4 = func_02082028(0x2C);
    if (temp_r0_4 != NULL) {
        M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &data_02129870;
        M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).active = 0;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).mode = 0;
        M2C_FIELD(temp_r0_4, Ov006C24Flags *, 0x20).kind = 2;
        M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_4;
}

void *func_ov007_0221f458(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_ov007_02221974;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &data_ov007_02221974;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    func_02082040(arg0);
    return arg0;
}

void *func_ov007_0221f4b0(void *arg0) {
    M2C_UNK func_02082040(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_ov007_02221974;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &data_ov007_02221974;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    
    return arg0;
}

