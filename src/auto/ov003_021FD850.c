/* 4 functions from 0x021FD850 to 0x021FE780 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021fd850(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = func_02082028(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = func_02082028(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
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
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = func_02082028(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 2);
}

void func_ov003_021fdc1c(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = func_02082028(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = func_02082028(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
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
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = func_02082028(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 3);
}

void func_ov003_021fdfe8(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = func_02082028(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = func_02082028(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
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
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = func_02082028(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 4);
}

void func_ov003_021fe3b4(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **gCurrentMap;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = func_02082028(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = func_02082028(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
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
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = func_02082028(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 6);
}

