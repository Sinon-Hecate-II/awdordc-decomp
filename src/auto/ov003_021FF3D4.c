/* 7 functions from 0x021FF3D4 to 0x022001EC (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021ff3d4(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220fe64;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    extern M2C_UNK data_ov003_02210158;
    extern M2C_UNK data_ov003_02210184;
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

    temp_r0 = func_01ffa3dc(&data_ov003_0220fe64, arg0);
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
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
                var_r0 += 1;
            } while (var_r0 < 5U);
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
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210158;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210184;
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 5);
}

void func_ov003_021ff7ac(void) {
    extern M2C_UNK data_ov003_0220fe64;
    void *temp_r0;
    temp_r0 = func_01ffa770(&data_ov003_0220fe64);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(*(void **)temp_r0, void (**)(void *), 0x10)(temp_r0);
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff7d4(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_ov003_021f1920(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_02210158, data_ov003_02210184;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210158;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210184;
    func_ov003_021f1920();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff9dc(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_ov003_021f1920(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_02210158, data_ov003_02210184;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210158;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210184;
    func_ov003_021f1920();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    func_02082040(obj);
    return obj;
}

/* Releases all owned sub-objects but does not free this object (vtable reset to base first). */
void *func_ov003_021ffbec(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_022101ac;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_022101d8;
    func_020af1e4();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ffdf4(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_022101ac;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_022101d8;
    func_020af1e4();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    func_02082040(obj);
    return obj;
}

void *func_ov003_02200004(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

