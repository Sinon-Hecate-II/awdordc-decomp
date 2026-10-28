/* 3 functions from 0x021EE8B8 to 0x021EF758 (ov003), found by ds-decomp. */
#include "common.h"
extern void ***gCur3DSpriteEngine;
extern u8 data_ov003_0220f89e[],data_027e00b4[];
void func_01ffaacc(u16,u16,u16,void *,int);
void func_02098dc0(s16,int,u16,int);
void func_02088e84(void *,s16,s32,s16,s32);
void func_02087d84(void *,int,s16,s16,u16,u16);
u32 func_020aae10(void *);u32 func_020aae44(void *);
int func_020846a4(void);
s16 func_ov003_022004a8(u8);
int func_ov003_022008b8(u8);
int func_ov003_021e6cc4(s16,int,int,int);
int func_ov003_021e6e5c(void);


void func_ov003_021ee8b8(void *arg0) { }

void func_ov003_021ef1e8(void *arg0) {
    void func_01ffa6fc(void *);
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0xC) {
        func_01ffa6fc(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38)++;
}

#pragma opt_strength_reduction off
void func_ov003_021ef210(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    u32 sp8;
    s16 temp_r0;
    s16 temp_r11;
    s16 temp_r11_2;
    s32 temp_r2;
    s16 temp_r4_2;
    s16 temp_r4_4;
    s16 temp_r5_3;
    s16 temp_r6;
    s16 temp_r6_2;
    s16 temp_r6_3;
    s16 temp_r6_4;
    s16 temp_r7;
    s16 temp_r7_3;
    s16 temp_r9;
    s32 temp_r0_2;
    s32 temp_r2_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    u32 temp_r4;
    u32 temp_r4_3;
    u16 temp_r4_5;
    u32 temp_r7_2;
    u32 temp_r7_4;
    u16 var_r2;
    u8 var_r1;
    u8 var_r8;
    void *temp_r5;
    void *temp_r5_2;

    sp8 = arg1;
    spC = arg2;
    var_r8 = 0;
    if (sp8 > 0U) {
    temp_r2 = (s16)(arg3 + 0x48);
    if (sp8 > 0U) {
    temp_r0 = (s16)temp_r2;
    sp14 = (s32)(s16)temp_r0;
    sp18 = (s32)(s16)temp_r0;
    sp1C = (s32) (u16) (u8) temp_r2;
    sp20 = (s32) (u16) (u8) (temp_r2 - 0x18);
    sp28 = 0x3FF;
    sp2C = 0x3FF;
    sp30 = 0x3FF;
    sp24 = 0x3FF;
    do {
        temp_r9 = spC + func_ov003_022004a8(var_r8);
        temp_r2_2 = (func_ov003_022008b8(M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0xA)) * 0x10) + 0x1F0;
        temp_r0_2 = temp_r9 - 4;
        sp10 = temp_r0_2;
        func_02098dc0((s16) temp_r0_2, 0, (u16) ((sp24 & (temp_r2_2 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7400), 0xA);
        temp_r5 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 8);
        temp_r7 = temp_r9 - 1;
        func_02088e84(temp_r5, temp_r7, sp14, temp_r7, sp14);
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            temp_r11 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6, temp_r11, (u16) temp_r4, (s32) func_020aae44(temp_r5));
        }
        M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5, s16 *, 0x36) = (s16) sp18;
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            temp_r4_2 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6_2 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r7_2 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6_2, temp_r4_2, (u16) temp_r7_2, (s32) func_020aae44(temp_r5));
        }
        temp_r5_2 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x18);
        temp_r7_3 = temp_r9 + 0x28;
        func_02088e84(temp_r5_2, temp_r7_3, sp14, temp_r7_3, sp14);
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            temp_r11_2 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_3 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r4_3 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_3, temp_r11_2, (u16) temp_r4_3, (s32) func_020aae44(temp_r5_2));
        }
        M2C_FIELD(temp_r5_2, s16 *, 0x34) = temp_r7_3;
        M2C_FIELD(temp_r5_2, s16 *, 0x36) = (s16) sp18;
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r4_4 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_4 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r7_4 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_4, temp_r4_4, (u16) temp_r7_4, (s32) func_020aae44(temp_r5_2));
        }
        if (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0xE) == 2) {
            var_r2 = 0x1E0;
        } else if (func_ov003_021e6e5c() != 0) {
            var_r2 = (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0x74) * 0x10) + 0x1A0;
        } else {
            var_r2 = (var_r8 * 0x10) + 0x1A0;
        }
        temp_r4_5 = sp10 & 0x1FF;
        func_01ffaacc(temp_r4_5, sp1C, (u16) ((sp28 & ((s32) var_r2 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6400), data_ov003_0220f89e, 0xA);
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 1) {
            var_r0_5 = 1;
        } else {
            var_r0_5 = 0;
        }
        if ((var_r0_5 & 0xFF) && (var_r8 == M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7))) {
            temp_r5_3 = temp_r9 - 2;
            if (func_ov003_021e6cc4(temp_r5_3, 0x48, 0x40, 0x20) != 0) {
                func_01ffaacc((u16) (temp_r5_3 & 0x1FF), 0x48, (u16) ((sp2C & (0x680 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x9800), data_027e00b4, 0xB);
            }
        }
        if (func_020846a4() != 0) {
            var_r1 = var_r8;
            if (M2C_FIELD((M2C_FIELD(arg0, void **, 0x6C) + var_r8), u8 *, 0x74) == 0xFF) {
                var_r0_6 = 1;
            } else {
                var_r0_6 = 0;
            }
            if (var_r0_6 & 0xFF) {
                var_r1 = 0;
            }
            if (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x68) + var_r1), u8 *, 0x7C) != 0) {
                func_01ffaacc(temp_r4_5, sp20, (u16) ((sp30 & (0x520 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x8000), data_027e00b4, 0xB);
            }
        }
        var_r8 += 1;
    } while ((u32) var_r8 < sp8);
}}
}
