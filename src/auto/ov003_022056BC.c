/* 81 functions from 0x022056BC to 0x022066A8 (ov003), found by ds-decomp. */
#include "common.h"

extern void **gCurrentMap;

void func_ov003_022056bc(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02074114(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **func_02082028(M2C_UNK);
    M2C_UNK func_02084d88(M2C_UNK **, M2C_UNK);
    M2C_UNK func_02084dcc(M2C_UNK, M2C_UNK **, M2C_UNK);
    M2C_UNK func_02084e74();
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    s32 func_ov003_02200c7c();
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_02210544;
    extern M2C_UNK data_ov003_02210754;
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    extern M2C_UNK func_ov003_021f05cc;
    extern M2C_UNK func_ov003_021f05f8;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    M2C_UNK **temp_r1;
    M2C_UNK **temp_r1_2;
    M2C_UNK **temp_r1_3;
    M2C_UNK **temp_r2;
    s32 var_r3;
    u8 temp_r3;
    u8 var_r1;
    u8 var_r2;
    u8 var_r3_2;
    void *temp_r0;

    func_ov003_021f13ec(&data_ov003_02210544);
    temp_r0 = func_01ffa3dc(&data_ov003_02210544, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_022108b4;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x39) = 0;
    temp_r3 = M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x3F;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_r3;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (temp_r3 & ~0x40) & ~0x80);
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = NULL;
    M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
    temp_r0_3 = func_02082028(0x12);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(temp_r0_3, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_3, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_3, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_3, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = (u16) M2C_FIELD(temp_r0_3, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_3;
    temp_r0_4 = func_02082028(0x48);
    if (temp_r0_4 != NULL) {
        var_r1 = 0;
        M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = NULL;
        M2C_FIELD(temp_r0_4, s32 *, 4) = 0;
        do {
            temp_r2 = &temp_r0_4[var_r1];
            M2C_FIELD(temp_r2, s32 *, 8) = 0;
            var_r1 += 1;
            M2C_FIELD(temp_r2, s32 *, 0x28) = 0;
        } while ((u32) var_r1 < 8U);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_4;
    temp_r0_5 = func_02082028(0x34);
    if (temp_r0_5 != NULL) {
        var_r3 = 0;
        *temp_r0_5 = &data_ov003_02210754;
        do {
            temp_r1 = &temp_r0_5[var_r3];
            M2C_FIELD(temp_r1, s32 *, 0x14) = 0;
            var_r3 += 1;
            M2C_FIELD(temp_r1, s32 *, 0x24) = 0;
        } while (var_r3 < 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_5;
    temp_r0_6 = func_02082028(0x134);
    if (temp_r0_6 != NULL) {
        M2C_FIELD(temp_r0_6, M2C_UNK **, 0) = &data_ov003_02210764;
        M2C_FIELD(temp_r0_6, s8 *, 4) = -1;
        M2C_FIELD(temp_r0_6, s8 *, 5) = -1;
        M2C_FIELD(temp_r0_6, s8 *, 6) = 0;
        func_02074114(temp_r0_6 + 8, 8, 0x18, &func_ov003_021f05cc, &func_ov003_021f05f8);
        var_r2 = 0;
        M2C_FIELD(temp_r0_6, s32 *, 0x10C) = 0;
        var_r3_2 = 0;
        do {
            temp_r1_2 = &temp_r0_6[var_r2];
            var_r2 += 1;
            M2C_FIELD(temp_r1_2, s32 *, 0xC8) = 0;
        } while ((u32) var_r2 < 8U);
        do {
            temp_r1_3 = &temp_r0_6[var_r3_2];
            var_r3_2 += 1;
            M2C_FIELD(temp_r1_3, s32 *, 0xE8) = 0;
        } while ((u32) var_r3_2 < 9U);
        if (func_ov003_02200c7c() != 0) {
            func_02084dcc(0, temp_r0_6 + 0x110, 0x24);
            M2C_FIELD(temp_r0_6, s32 *, 0x110) = 0;
            func_02084d88(temp_r0_6 + 0x110, 0x24);
            func_02084e74();
        }
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_6;
    temp_r0_7 = func_02082028(0x2C);
    if (temp_r0_7 != NULL) {
        M2C_FIELD(temp_r0_7, M2C_UNK **, 0) = &data_02129870;
        M2C_FIELD(temp_r0_7, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_7, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_7, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_7, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_7, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
        M2C_FIELD(temp_r0_7, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_7, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_7, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_7, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_7, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = temp_r0_7;
}

void func_ov003_022059d0(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_02074114(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **func_02082028(M2C_UNK);
    M2C_UNK func_02084d88(M2C_UNK **, M2C_UNK);
    M2C_UNK func_02084dcc(M2C_UNK, M2C_UNK **, M2C_UNK);
    M2C_UNK func_02084e74();
    s32 func_ov003_02200c7c();
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_02210544;
    extern M2C_UNK data_ov003_02210754;
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    extern M2C_UNK func_ov003_021f05cc;
    extern M2C_UNK func_ov003_021f05f8;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    M2C_UNK **temp_r1;
    M2C_UNK **temp_r1_2;
    M2C_UNK **temp_r1_3;
    M2C_UNK **temp_r2;
    s32 var_r3;
    u8 temp_r3;
    u8 var_r1;
    u8 var_r2;
    u8 var_r3_2;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov003_02210544, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_022108b4;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x39) = 0;
        temp_r3 = M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x3F;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_r3;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (temp_r3 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        temp_r0_2 = func_02082028(0x12);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
        temp_r0_3 = func_02082028(0x12);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_3, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_3, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_3, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_3, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_3, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_3, u16 *, 2) = (u16) M2C_FIELD(temp_r0_3, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_3;
        temp_r0_4 = func_02082028(0x48);
        if (temp_r0_4 != NULL) {
            var_r1 = 0;
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = NULL;
            M2C_FIELD(temp_r0_4, s32 *, 4) = 0;
            do {
                temp_r2 = &temp_r0_4[var_r1];
                M2C_FIELD(temp_r2, s32 *, 8) = 0;
                var_r1 += 1;
                M2C_FIELD(temp_r2, s32 *, 0x28) = 0;
            } while ((u32) var_r1 < 8U);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_4;
        temp_r0_5 = func_02082028(0x34);
        if (temp_r0_5 != NULL) {
            var_r3 = 0;
            *temp_r0_5 = &data_ov003_02210754;
            do {
                temp_r1 = &temp_r0_5[var_r3];
                M2C_FIELD(temp_r1, s32 *, 0x14) = 0;
                var_r3 += 1;
                M2C_FIELD(temp_r1, s32 *, 0x24) = 0;
            } while (var_r3 < 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_5;
        temp_r0_6 = func_02082028(0x134);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, M2C_UNK **, 0) = &data_ov003_02210764;
            M2C_FIELD(temp_r0_6, s8 *, 4) = -1;
            M2C_FIELD(temp_r0_6, s8 *, 5) = -1;
            M2C_FIELD(temp_r0_6, s8 *, 6) = 0;
            func_02074114(temp_r0_6 + 8, 8, 0x18, &func_ov003_021f05cc, &func_ov003_021f05f8);
            var_r2 = 0;
            M2C_FIELD(temp_r0_6, s32 *, 0x10C) = 0;
            var_r3_2 = 0;
            do {
                temp_r1_2 = &temp_r0_6[var_r2];
                var_r2 += 1;
                M2C_FIELD(temp_r1_2, s32 *, 0xC8) = 0;
            } while ((u32) var_r2 < 8U);
            do {
                temp_r1_3 = &temp_r0_6[var_r3_2];
                var_r3_2 += 1;
                M2C_FIELD(temp_r1_3, s32 *, 0xE8) = 0;
            } while ((u32) var_r3_2 < 9U);
            if (func_ov003_02200c7c() != 0) {
                func_02084dcc(0, temp_r0_6 + 0x110, 0x24);
                M2C_FIELD(temp_r0_6, s32 *, 0x110) = 0;
                func_02084d88(temp_r0_6 + 0x110, 0x24);
                func_02084e74();
            }
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_6;
        temp_r0_7 = func_02082028(0x2C);
        if (temp_r0_7 != NULL) {
            M2C_FIELD(temp_r0_7, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_7, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_7, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_7, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_7, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_7, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_7, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_7, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_7, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_7, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_7, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_7, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = temp_r0_7;
    }
    M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x3F) | 1);
}

void *func_ov003_02205ce8(void *arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020af1f8();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    s32 var_r0;
    void *temp_r5;
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;
    u8 var_r6;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_022108b4;
    M2C_FIELD(arg0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02082040();
    }
    if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
        func_02082040();
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x40);
    if (temp_r5 != NULL) {
        if (M2C_FIELD(temp_r5, s32 *, 0) != 0) {
            func_01ffa574();
        }
        if (M2C_FIELD(temp_r5, s32 *, 4) != 0) {
            func_01ffa574();
        }
        var_r6 = 0;
        do {
            if (M2C_FIELD((temp_r5 + (var_r6 * 4)), s32 *, 8) != 0) {
                func_01ffa574();
            }
            if (M2C_FIELD((temp_r5 + (var_r6 * 4)), s32 *, 0x28) != 0) {
                func_01ffa574();
            }
            var_r6 += 1;
        } while ((u32) var_r6 < 8U);
        func_02082040(temp_r5);
    }
    temp_r0 = M2C_FIELD(arg0, void ***, 0x50);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, M2C_UNK (**)(), 4)();
    }
    temp_r0_2 = M2C_FIELD(arg0, void ***, 0x44);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, M2C_UNK (**)(), 4)();
    }
    temp_r0_3 = M2C_FIELD(arg0, void ***, 0x54);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, M2C_UNK (**)(), 4)();
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        func_01ffa574();
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_01ffa574();
    }
    func_ov003_021f140c(4);
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        func_020af1f8();
    }
    return arg0;
}

M2C_UNK **func_ov003_02205e34(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_02210754;
    register s32 var_r4;

    *arg0 = &data_ov003_02210754;
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 5] != 0) {
            func_01ffa574();
        }
        if (arg0[var_r4 + 9] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 4);
    func_02082040(arg0);
    return arg0;
}

M2C_UNK **func_ov003_02205e94(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    M2C_UNK func_02082040();
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK func_ov003_021f05f8;
    register u8 var_r5;
    M2C_UNK *temp_r0;

    *arg0 = &data_ov003_02210764;
    var_r5 = 0;
    do {
        temp_r0 = arg0[var_r5 + 0x32];
        if (temp_r0 != NULL) {
            M2C_FIELD(*temp_r0, M2C_UNK (**)(), 0x4)();
        }
        var_r5 += 1;
    } while (var_r5 < 8);
    var_r5 = 0;
    do {
        if (arg0[var_r5 + 0x3A] != 0) {
            func_01ffa574();
        }
        var_r5 += 1;
    } while (var_r5 < 9);
    func_020741c4((u8 *)arg0 + 8, 8, 0x18, &func_ov003_021f05f8);
    func_02082040(arg0);
    return arg0;
}

#pragma opt_common_subs off
void *func_ov003_02205f28(void *arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020af1f8();
    M2C_UNK func_02082040();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    extern M2C_UNK data_ov003_022108b4;
    extern M2C_UNK data_ov003_022108e0;
    void *temp_r5;
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;
    u8 var_r6;
    s32 var_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0x0) = &data_ov003_022108b4;
    M2C_FIELD(arg0, M2C_UNK **, 0x34) = &data_ov003_022108e0;
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_02082040(M2C_FIELD(arg0, s32 *, 0x3C));
    }
    if (M2C_FIELD(arg0, s32 *, 0x48) != 0) {
        func_02082040(M2C_FIELD(arg0, s32 *, 0x48));
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x40);
    if (temp_r5 != NULL) {
        if (M2C_FIELD(temp_r5, s32 *, 0) != 0) {
            func_01ffa574(M2C_FIELD(temp_r5, s32 *, 0));
        }
        if (M2C_FIELD(temp_r5, s32 *, 4) != 0) {
            func_01ffa574(M2C_FIELD(temp_r5, s32 *, 4));
        }
        var_r6 = 0;
        do {
            if (M2C_FIELD(temp_r5 + (var_r6 * 4), s32 *, 8) != 0) {
                func_01ffa574(M2C_FIELD(temp_r5 + (var_r6 * 4), s32 *, 8));
            }
            if (M2C_FIELD(temp_r5 + (var_r6 * 4), s32 *, 0x28) != 0) {
                func_01ffa574(M2C_FIELD(temp_r5 + (var_r6 * 4), s32 *, 0x28));
            }
            ++var_r6;
        } while (var_r6 < 8U);
        func_02082040(temp_r5);
    }
    temp_r0 = M2C_FIELD(arg0, void ***, 0x50);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    temp_r0_2 = M2C_FIELD(arg0, void ***, 0x44);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, void (**)(void *), 4)(temp_r0_2);
    }
    temp_r0_3 = M2C_FIELD(arg0, void ***, 0x54);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, void (**)(void *), 4)(temp_r0_3);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) {
        func_01ffa574(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_01ffa574(M2C_FIELD(arg0, s32 *, 0x58));
    }
    func_ov003_021f140c(4);
    if (((u32)(M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        func_020af1f8();
    }
    func_02082040(arg0);
    return arg0;
}
#pragma opt_common_subs reset
M2C_UNK **func_ov003_0220607c(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020990c0();
    extern M2C_UNK data_ov003_02210754;
    register s32 var_r4;

    *arg0 = &data_ov003_02210754;
    func_020990c0();
    var_r4 = 0;
    do {
        if (arg0[var_r4 + 5] != 0) {
            func_01ffa574();
        }
        if (arg0[var_r4 + 9] != 0) {
            func_01ffa574();
        }
        var_r4 += 1;
    } while (var_r4 < 4);
    return arg0;
}

M2C_UNK **func_ov003_022060d4(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020741c4(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_02210764;
    extern M2C_UNK func_ov003_021f05f8;
    register u8 var_r5;
    M2C_UNK *temp_r0;
    M2C_UNK (**temp_vt)(void);

    *arg0 = &data_ov003_02210764;
    var_r5 = 0;
    do {
        temp_r0 = arg0[var_r5 + 0x32];
        if (temp_r0 != 0) {
            temp_vt = *temp_r0;
            temp_vt[1]();
        }
        var_r5 += 1;
    } while (var_r5 < 8);
    var_r5 = 0;
    do {
        if (arg0[var_r5 + 0x3A] != 0) {
            func_01ffa574();
        }
        var_r5 += 1;
    } while (var_r5 < 9);
    func_020741c4((u8 *)arg0 + 8, 8, 0x18, &func_ov003_021f05f8);
    return arg0;
}

s32 func_ov003_02206160(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_02206174(M2C_UNK arg0, s32 arg1) {
    extern M2C_UNK data_02168f14;
    u16 v;
    v = M2C_FIELD(&data_02168f14, u16 *, 0);
    v = (u16)((v & ~0x100) | ((arg1 & 1) << 8));
    M2C_FIELD(&data_02168f14, u16 *, 0) = v;
}

s32 func_ov003_0220619c(void) {
    extern M2C_UNK data_02168f14;
    u16 v;
    v = (u16)M2C_FIELD(&data_02168f14, u16 *, 0);
    return (s32)((v >> 8) & 1);
}

s32 func_ov003_022061b4(void) {
    return 1;
}

s32 func_ov003_022061bc(void) {
    return 1;
}

s32 func_ov003_022061c4(void) {
    return 1;
}

s32 func_ov003_022061cc(void) {
    return 0;
}

void func_ov003_022061d4(void) {

}

s32 func_ov003_022061d8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_ov003_02206270(void) {
    return 1;
}

s32 func_ov003_02206278(void) {
    return 1;
}

s32 func_ov003_02206280(void) {
    return 3;
}

s32 func_ov003_02206288(void) {
    return 0;
}

void func_ov003_02206290(void) {

}

s32 func_ov003_02206294(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022062a8(s32 arg0, s16 arg1) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s16 *, 0x6) = arg1;
}

u16 func_ov003_022062b8(void) {
    extern M2C_UNK data_02168f14;
    return M2C_FIELD(&data_02168f14, u16 *, 6);
}

s32 func_ov003_022062c8(void) {
    return 0;
}

s32 func_ov003_022062d0(void) {
    return 0x1F4;
}

s32 func_ov003_022062d8(void) {
    return 0x251C;
}

s32 func_ov003_022062e4(void) {
    return 0;
}

void func_ov003_022062ec(void) {

}

s32 func_ov003_022062f0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_02206304(M2C_UNK arg0, s32 arg1) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s32 *, 0x8) = arg1;
}

s32 func_ov003_02206314(void) {
    extern M2C_UNK data_02168f14;
    return M2C_FIELD(&data_02168f14, s32 *, 8);
}

s32 func_ov003_02206324(void) {
    return 0;
}

s32 func_ov003_0220632c(void) {
    return 0x3E8;
}

s32 func_ov003_02206334(void) {
    return 0x182B8;
}

s32 func_ov003_02206340(void) {
    return 0;
}

void func_ov003_02206348(void) {

}

s32 func_ov003_0220634c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_02206360(s32 arg0, s32 arg1) {
    extern s32 data_02168f14;
    if (arg1 == 4) arg1 = 0;
    ((u8 *)&data_02168f14)[3] = (u8)arg1;
}

s32 func_ov003_02206378(void) {
    extern s32 data_02168f14;
    u8 v = * (u8 *)((char *)&data_02168f14 + 3);
    if (v == 0) return 4;
    return v;
}

s32 func_ov003_02206390(void) {
    return 0;
}

s32 func_ov003_02206398(void) {
    return 1;
}

s32 func_ov003_022063a0(void) {
    return 0x63;
}

s32 func_ov003_022063a8(void) {
    return 4;
}

void func_ov003_022063b0(void) {

}

s32 func_ov003_022063b4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022063c8(s32 arg0, u8 arg1) {
    extern void **gCurrentMap;
    s8 var_r1;

    switch (arg1 & 0xff) {
    case 0:
        var_r1 = 0;
        break;
    case 1:
        var_r1 = 3;
        break;
    case 2:
        var_r1 = 1;
        break;
    case 3:
        var_r1 = 2;
        break;
    default:
        var_r1 = 0;
        break;
    }
    M2C_FIELD(*gCurrentMap, s8 *, 0x5157) = var_r1;
}

s32 func_ov003_02206428(void) {
    extern void **gCurrentMap;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(*gCurrentMap, u8 *, 0x5157);
    switch (temp_r0) {
    case 0:
        return 0;
    case 3:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}

s32 func_ov003_02206484(void) {
    return 1;
}

s32 func_ov003_0220648c(void) {
    return 1;
}

s32 func_ov003_02206494(void) {
    return 3;
}

s32 func_ov003_0220649c(void) {
    return 0;
}

void func_ov003_022064a4(void) {

}

s32 func_ov003_022064a8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022064bc(s32 arg0_unused, s32 arg1) {
    extern void **gCurrentMap;
    u16 var_r3;

    if (arg1 == 4) {
        var_r3 = 0;
        M2C_FIELD(*gCurrentMap, s8 *, 0x5159) = 1;
    } else {
        var_r3 = arg1;
        M2C_FIELD(*gCurrentMap, s8 *, 0x5159) = 0;
    }
    M2C_FIELD(*gCurrentMap, u8 *, 0x5158) = (u8) var_r3;
    M2C_FIELD(*gCurrentMap, u8 *, 0x515A) = (u8) var_r3;
    M2C_FIELD(*gCurrentMap, u8 *, 0x515B) = (u8) var_r3;
}

u8 func_ov003_02206544(void **arg0) {
    void *temp_r1 = *gCurrentMap;
    if (M2C_FIELD(temp_r1, u8 *, 0x5159) != 1) {
        return M2C_FIELD(temp_r1, u8 *, 0x515B);
    }
    return M2C_FIELD(arg0[0], u8 (**)(void **), 0xC)(arg0);
}

s32 func_ov003_0220657c(void) {
    return 4;
}

s32 func_ov003_02206584(void) {
    return 1;
}

s32 func_ov003_0220658c(void) {
    return 1;
}

s32 func_ov003_02206594(void) {
    return 0;
}

void func_ov003_0220659c(void) {

}

s32 func_ov003_022065a0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov003_022065b4(s32 arg0_unused, s8 arg1) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s8 *, 0x5156) = arg1;
}

u8 func_ov003_022065d0(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x5156);
}

s32 func_ov003_022065ec(void) {
    return 1;
}

s32 func_ov003_022065f4(void) {
    return 1;
}

s32 func_ov003_022065fc(void) {
    return 1;
}

s32 func_ov003_02206604(void) {
    return 0;
}

void func_ov003_0220660c(void) {

}

u8 func_ov003_02206690(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

