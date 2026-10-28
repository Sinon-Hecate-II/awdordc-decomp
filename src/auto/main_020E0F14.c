/* 2 functions from 0x020E0F14 to 0x020E19E8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0x40]; u32 tile:9; u32 palette:9; u32 priority:8; u32 other:6; } SpriteE0F14;


#pragma opt_common_subs off
void func_020e0f14(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *func_0208931c(void *);
    M2C_UNK func_0208b698(void *, M2C_UNK *);
    void *func_0208bc24(void *);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void *func_020ab1c4(void *);
    M2C_UNK func_020e4c64();
    extern M2C_UNK data_0212c5c4;
    extern M2C_UNK data_0212c6a8;
    extern M2C_UNK data_0212d1e8;
    extern M2C_UNK data_027e00b4;
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r5;
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    s16 temp_r7;
    s16 temp_r7_2;
    s16 temp_r7_3;
    s16 temp_r7_4;
    s16 temp_r8;
    s16 temp_r8_2;
    s16 temp_r8_3;
    s16 temp_r8_4;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;
    s32 temp_r9_4;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r1_5;
    void *temp_r1_6;
    void *temp_r1_7;
    void *temp_r2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    temp_r0 = func_01ffa42c(&data_0212c6a8, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_0212d1e8;
    M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x41) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x42) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x43) = 4;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = 0x3A8;
    M2C_FIELD(temp_r0, s16 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x4A) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x4C) = 0x708;
    M2C_FIELD(temp_r0, void **, 0x50) = NULL;
    M2C_FIELD(temp_r0, void **, 0x54) = NULL;
    M2C_FIELD(temp_r0, void **, 0x58) = NULL;
    M2C_FIELD(temp_r0, void **, 0x5C) = NULL;
    M2C_FIELD(temp_r0, void **, 0x60) = NULL;
    M2C_FIELD(temp_r0, void **, 0x64) = NULL;
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
    M2C_FIELD(temp_r0, void **, 0x68) = temp_r0_2;
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(temp_r0, void **, 0x50) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x50), 0, 0x340, 3, 1);
    temp_r6 = M2C_FIELD(temp_r0, void **, 0x50);
    func_02088e84(temp_r6, 0xC0, 0xA0, 0xC0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
    }
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x50);
    M2C_FIELD(temp_r1, s16 *, 0x34) = 0xC0;
    M2C_FIELD(temp_r1, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x50));
    temp_r1_2 = M2C_FIELD(temp_r0, void **, 0x50);
    M2C_FIELD(temp_r1_2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r1_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r1_2, s8 *, 0x5A) = 0;
    M2C_FIELD(temp_r0, void **, 0x54) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x54), 1, 0x350, 3, 0);
    temp_r6_2 = M2C_FIELD(temp_r0, void **, 0x54);
    func_02088e84(temp_r6_2, 0xC0, 0xA0, 0xC0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r7_2 = M2C_FIELD(temp_r6_2, s16 *, 0x52);
        temp_r8_2 = M2C_FIELD(temp_r6_2, s16 *, 0x50);
        temp_r9_2 = func_020aae10(temp_r6_2);
        func_02087d84(M2C_FIELD(temp_r6_2, void **, 0x64), 1, temp_r8_2, temp_r7_2, (u16) temp_r9_2, (u16) func_020aae44(temp_r6_2));
    }
    temp_r1_3 = M2C_FIELD(temp_r0, void **, 0x54);
    M2C_FIELD(temp_r1_3, s16 *, 0x34) = 0xC0;
    M2C_FIELD(temp_r1_3, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x54));
    temp_r1_4 = M2C_FIELD(temp_r0, void **, 0x54);
    M2C_FIELD(temp_r1_4, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_4, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r1_4, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r1_4, s8 *, 0x5A) = 0;
    M2C_FIELD(temp_r0, void **, 0x58) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x58), 2, 0x360, 3, 0);
    temp_r6_3 = M2C_FIELD(temp_r0, void **, 0x58);
    func_02088e84(temp_r6_3, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r7_3 = M2C_FIELD(temp_r6_3, s16 *, 0x52);
        temp_r8_3 = M2C_FIELD(temp_r6_3, s16 *, 0x50);
        temp_r9_3 = func_020aae10(temp_r6_3);
        func_02087d84(M2C_FIELD(temp_r6_3, void **, 0x64), 1, temp_r8_3, temp_r7_3, (u16) temp_r9_3, (u16) func_020aae44(temp_r6_3));
    }
    temp_r1_5 = M2C_FIELD(temp_r0, void **, 0x58);
    M2C_FIELD(temp_r1_5, s16 *, 0x34) = 0xE0;
    M2C_FIELD(temp_r1_5, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x58));
    M2C_FIELD(temp_r0, void **, 0x5C) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x5C), 0x2A, 0x370, 3, 0);
    temp_r6_4 = M2C_FIELD(temp_r0, void **, 0x5C);
    func_02088e84(temp_r6_4, 0x60, 0xA4, -0x9F, 0xA4);
    if (M2C_FIELD(M2C_FIELD(temp_r6_4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (var_r0_4 & 0xFF) {
        temp_r7_4 = M2C_FIELD(temp_r6_4, s16 *, 0x52);
        temp_r8_4 = M2C_FIELD(temp_r6_4, s16 *, 0x50);
        temp_r9_4 = func_020aae10(temp_r6_4);
        func_02087d84(M2C_FIELD(temp_r6_4, void **, 0x64), 1, temp_r8_4, temp_r7_4, (u16) temp_r9_4, (u16) func_020aae44(temp_r6_4));
    }
    temp_r1_6 = M2C_FIELD(temp_r0, void **, 0x5C);
    M2C_FIELD(temp_r1_6, s16 *, 0x34) = -0x9F;
    M2C_FIELD(temp_r1_6, s16 *, 0x36) = 0xA4;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x5C));
    temp_r0_3 = func_0208931c(temp_r0);
    M2C_FIELD(temp_r0, void **, 0x60) = temp_r0_3;
    M2C_FIELD(temp_r0_3, s16 *, 0x34) = 0x9C;
    M2C_FIELD(temp_r0_3, s16 *, 0x36) = 0xC0;
    ((SpriteE0F14 *)temp_r0_3)->tile=64;
    ((SpriteE0F14 *)temp_r0_3)->palette=32;
    func_02088e84(M2C_FIELD(temp_r0, void **, 0x60), 0x9C, 0xA0, 0x9C, 0xC0);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), s16 *, 0x3C) = 0;
    temp_r1_7 = M2C_FIELD(temp_r0, void **, 0x60);
    M2C_FIELD(temp_r1_7, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_7, s32 *, 0x40) & ~0x03FC0000) | 0x180000);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), s16 *, 0x3E) = 0x388;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), M2C_UNK **, 0x44) = &data_027e00b4;
    gCur3DSpriteEngine = data_027e00c4;
    temp_r0_4 = func_0208bc24(temp_r0);
    M2C_FIELD(temp_r0, void **, 0x64) = temp_r0_4;
    M2C_FIELD(temp_r0_4, s16 *, 0x3E) = 0x140;
    temp_r2 = M2C_FIELD(temp_r0, void **, 0x64);
    M2C_FIELD(temp_r2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r2, s32 *, 0x40) & ~0x03FC0000) | 0x180000);
    func_0208b698(M2C_FIELD(temp_r0, void **, 0x64), &data_0212c5c4);
    func_02088da8(M2C_FIELD(temp_r0, void **, 0x64));
    gCur3DSpriteEngine = temp_r5;
    func_020e4c64();
}

#pragma opt_common_subs off
void func_020e147c(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *func_0208931c(void *);
    M2C_UNK func_0208b698(void *, M2C_UNK *);
    void *func_0208bc24(void *);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void *func_020ab1c4(void *);
    M2C_UNK func_020e4c64();
    extern M2C_UNK data_0212c5c4;
    extern M2C_UNK data_0212c6a8;
    extern M2C_UNK data_0212d1e8;
    extern M2C_UNK data_027e00b4;
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r0;
    void *temp_r5;
    void *temp_r6;
    void *temp_r6_2;
    void *temp_r6_3;
    void *temp_r6_4;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    s16 temp_r7;
    s16 temp_r7_2;
    s16 temp_r7_3;
    s16 temp_r7_4;
    s16 temp_r8;
    s16 temp_r8_2;
    s16 temp_r8_3;
    s16 temp_r8_4;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r9_3;
    s32 temp_r9_4;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r1_5;
    void *temp_r1_6;
    void *temp_r1_7;
    void *temp_r2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    temp_r0 = func_01ffa42c(&data_0212c6a8, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_0212d1e8;
    M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x41) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x42) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x43) = 4;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = 0x3A8;
    M2C_FIELD(temp_r0, s16 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x4A) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x4C) = 0x708;
    M2C_FIELD(temp_r0, void **, 0x50) = NULL;
    M2C_FIELD(temp_r0, void **, 0x54) = NULL;
    M2C_FIELD(temp_r0, void **, 0x58) = NULL;
    M2C_FIELD(temp_r0, void **, 0x5C) = NULL;
    M2C_FIELD(temp_r0, void **, 0x60) = NULL;
    M2C_FIELD(temp_r0, void **, 0x64) = NULL;
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
    M2C_FIELD(temp_r0, void **, 0x68) = temp_r0_2;
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(temp_r0, void **, 0x50) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x50), 0, 0x340, 3, 1);
    temp_r6 = M2C_FIELD(temp_r0, void **, 0x50);
    func_02088e84(temp_r6, 0xC0, 0xA0, 0xC0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = func_020aae10(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
    }
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x50);
    M2C_FIELD(temp_r1, s16 *, 0x34) = 0xC0;
    M2C_FIELD(temp_r1, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x50));
    temp_r1_2 = M2C_FIELD(temp_r0, void **, 0x50);
    M2C_FIELD(temp_r1_2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r1_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r1_2, s8 *, 0x5A) = 0;
    M2C_FIELD(temp_r0, void **, 0x54) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x54), 1, 0x350, 3, 0);
    temp_r6_2 = M2C_FIELD(temp_r0, void **, 0x54);
    func_02088e84(temp_r6_2, 0xC0, 0xA0, 0xC0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r7_2 = M2C_FIELD(temp_r6_2, s16 *, 0x52);
        temp_r8_2 = M2C_FIELD(temp_r6_2, s16 *, 0x50);
        temp_r9_2 = func_020aae10(temp_r6_2);
        func_02087d84(M2C_FIELD(temp_r6_2, void **, 0x64), 1, temp_r8_2, temp_r7_2, (u16) temp_r9_2, (u16) func_020aae44(temp_r6_2));
    }
    temp_r1_3 = M2C_FIELD(temp_r0, void **, 0x54);
    M2C_FIELD(temp_r1_3, s16 *, 0x34) = 0xC0;
    M2C_FIELD(temp_r1_3, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x54));
    temp_r1_4 = M2C_FIELD(temp_r0, void **, 0x54);
    M2C_FIELD(temp_r1_4, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_4, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r1_4, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r1_4, s8 *, 0x5A) = 0;
    M2C_FIELD(temp_r0, void **, 0x58) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x58), 2, 0x360, 3, 0);
    temp_r6_3 = M2C_FIELD(temp_r0, void **, 0x58);
    func_02088e84(temp_r6_3, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r6_3, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r7_3 = M2C_FIELD(temp_r6_3, s16 *, 0x52);
        temp_r8_3 = M2C_FIELD(temp_r6_3, s16 *, 0x50);
        temp_r9_3 = func_020aae10(temp_r6_3);
        func_02087d84(M2C_FIELD(temp_r6_3, void **, 0x64), 1, temp_r8_3, temp_r7_3, (u16) temp_r9_3, (u16) func_020aae44(temp_r6_3));
    }
    temp_r1_5 = M2C_FIELD(temp_r0, void **, 0x58);
    M2C_FIELD(temp_r1_5, s16 *, 0x34) = 0xE0;
    M2C_FIELD(temp_r1_5, s16 *, 0x36) = 0xC0;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x58));
    M2C_FIELD(temp_r0, void **, 0x5C) = func_020ab1c4(temp_r0);
    func_020aab24(M2C_FIELD(temp_r0, void **, 0x5C), 0x2A, 0x370, 3, 0);
    temp_r6_4 = M2C_FIELD(temp_r0, void **, 0x5C);
    func_02088e84(temp_r6_4, 0x60, 0xA4, -0x9F, 0xA4);
    if (M2C_FIELD(M2C_FIELD(temp_r6_4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (var_r0_4 & 0xFF) {
        temp_r7_4 = M2C_FIELD(temp_r6_4, s16 *, 0x52);
        temp_r8_4 = M2C_FIELD(temp_r6_4, s16 *, 0x50);
        temp_r9_4 = func_020aae10(temp_r6_4);
        func_02087d84(M2C_FIELD(temp_r6_4, void **, 0x64), 1, temp_r8_4, temp_r7_4, (u16) temp_r9_4, (u16) func_020aae44(temp_r6_4));
    }
    temp_r1_6 = M2C_FIELD(temp_r0, void **, 0x5C);
    M2C_FIELD(temp_r1_6, s16 *, 0x34) = -0x9F;
    M2C_FIELD(temp_r1_6, s16 *, 0x36) = 0xA4;
    func_020aad18(M2C_FIELD(temp_r0, void **, 0x5C));
    temp_r0_3 = func_0208931c(temp_r0);
    M2C_FIELD(temp_r0, void **, 0x60) = temp_r0_3;
    M2C_FIELD(temp_r0_3, s16 *, 0x34) = 0x9C;
    M2C_FIELD(temp_r0_3, s16 *, 0x36) = 0xC0;
    {
        s32 _v = M2C_FIELD(temp_r0_3, s32 *, 0x40);
        _v = (_v & ~0x1FF) | 0x40;
        _v = (_v & 0xFFFC01FF) | 0x4000;
        M2C_FIELD(temp_r0_3, s32 *, 0x40) = _v;
    }
    func_02088e84(M2C_FIELD(temp_r0, void **, 0x60), 0x9C, 0xA0, 0x9C, 0xC0);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), s16 *, 0x3C) = 0;
    temp_r1_7 = M2C_FIELD(temp_r0, void **, 0x60);
    M2C_FIELD(temp_r1_7, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r1_7, s32 *, 0x40) & ~0x03FC0000) | 0x180000);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), s16 *, 0x3E) = 0x388;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x60), M2C_UNK **, 0x44) = &data_027e00b4;
    gCur3DSpriteEngine = data_027e00c4;
    temp_r0_4 = func_0208bc24(temp_r0);
    M2C_FIELD(temp_r0, void **, 0x64) = temp_r0_4;
    M2C_FIELD(temp_r0_4, s16 *, 0x3E) = 0x140;
    temp_r2 = M2C_FIELD(temp_r0, void **, 0x64);
    M2C_FIELD(temp_r2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r2, s32 *, 0x40) & ~0x03FC0000) | 0x180000);
    func_0208b698(M2C_FIELD(temp_r0, void **, 0x64), &data_0212c5c4);
    func_02088da8(M2C_FIELD(temp_r0, void **, 0x64));
    gCur3DSpriteEngine = temp_r5;
    func_020e4c64();
}
#pragma opt_common_subs reset

#pragma opt_common_subs reset
