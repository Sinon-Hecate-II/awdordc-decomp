/* 6 functions from 0x02200EE4 to 0x02201E88 (ov003), found by ds-decomp. */
#include "common.h"
extern u16 **gCur3DSpriteEngine;

void func_ov003_02200ee4(s32 arg0) { (void)arg0; }

u8 func_ov003_02201500(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_0220151c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Set bits 4-8 of the word pointed to by *gCur3DSpriteEngine from five boolean flags. */
void func_ov003_0220153c(s32 flag0, s32 flag1, s32 flag2, s32 flag3, u8 flag4) {
u16 * volatile reg0;
u16 * volatile reg1;
u16 * volatile reg2;
u16 * volatile reg3;
u16 * volatile reg4;
reg0 = *gCur3DSpriteEngine; *reg0 = (*reg0 & ~16) | ((u32)(flag0 << 31) >> 27);
reg1 = *gCur3DSpriteEngine; *reg1 = (*reg1 & ~32) | ((u32)(flag1 << 31) >> 26);
reg2 = *gCur3DSpriteEngine; *reg2 = (*reg2 & ~64) | ((u32)(flag2 << 31) >> 25);
reg3 = *gCur3DSpriteEngine; *reg3 = (*reg3 & ~128) | ((u32)(flag3 << 31) >> 24);
reg4 = *gCur3DSpriteEngine; *reg4 = (*reg4 & ~256) | ((u32)(flag4 << 31) >> 23);
}

void func_ov003_02201620(void *arg0, s32 arg1) { (void)arg0; (void)arg1; }

void func_ov003_02201c78(void *arg0, s32 arg1) {
    void *func_02087d84(void *, s32, s16, s16, s32, s32);
    void func_02088da8(void *);
    void func_02088e84(void *, s32, s32, s32, s32);
    void func_020aab24(void *, s32, s32, s32, s32);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    void *func_020ab1c4(s32);
    void *temp_r4;
    s16 temp_r5;
    s16 temp_r6;
    u16 temp_r7;
    s32 temp_r0;
    s32 var_r0;
    void *temp_r4_2;
    s16 temp_r5_2;
    s16 temp_r6_2;
    u16 temp_r7_2;
    s32 temp_r0_2;
    s32 var_r0_2;
    u8 var_r8;
    s32 zero7;
    s32 eight;
    s32 val15c;
    s32 three;
    s32 zero4;
    void *temp_r1;
    void *temp_r0ptr;

    M2C_FIELD(arg0, void **, 0) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 0), 2, 0x14C, 3, 1);
    temp_r4 = M2C_FIELD(arg0, void **, 0);
    func_02088e84(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = func_020aae10(temp_r4);
        temp_r0 = func_020aae44(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5,
                      (s32)((u32)temp_r7 << 16 >> 16), (s32)((u32)temp_r0 << 16 >> 16));
    }
    func_02088da8(M2C_FIELD(arg0, void **, 0));
    M2C_FIELD(arg0, void **, 4) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 4), 0x20, 0x140, 3, 0);
    temp_r4_2 = M2C_FIELD(arg0, void **, 4);
    func_02088e84(temp_r4_2, 0x70, 0xA4, 0x70, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r5_2 = M2C_FIELD(temp_r4_2, s16 *, 0x52);
        temp_r6_2 = M2C_FIELD(temp_r4_2, s16 *, 0x50);
        temp_r7_2 = func_020aae10(temp_r4_2);
        temp_r0_2 = func_020aae44(temp_r4_2);
        func_02087d84(M2C_FIELD(temp_r4_2, void **, 0x64), 1, temp_r6_2, temp_r5_2,
                      (s32)((u32)temp_r7_2 << 16 >> 16), (s32)((u32)temp_r0_2 << 16 >> 16));
    }
    func_02088da8(M2C_FIELD(arg0, void **, 4));

    var_r8 = 0;
    zero7 = var_r8;
    eight = 8;
    val15c = 0x15C;
    three = 3;
    zero4 = var_r8;
    do {
        temp_r0ptr = func_020ab1c4(arg1);
        temp_r1 = (void *)((u8 *)arg0 + (var_r8 * 4));
        M2C_FIELD(temp_r1, void **, 8) = temp_r0ptr;
        func_020aab24(M2C_FIELD(temp_r1, void **, 8), eight, val15c, three, zero7);
        func_02088da8(M2C_FIELD(temp_r1, void **, 8));
        temp_r0ptr = func_020ab1c4(arg1);
        M2C_FIELD(temp_r1, void **, 0x28) = temp_r0ptr;
        func_020aab24(M2C_FIELD(temp_r1, void **, 0x28), 9, 0x164, 3, zero4);
        func_02088da8(M2C_FIELD(temp_r1, void **, 0x28));
        var_r8 += 1;
    } while ((u32)var_r8 < 8U);
}

