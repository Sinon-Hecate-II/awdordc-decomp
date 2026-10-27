/* 5 functions from 0x02221320 to 0x022221B8 (ov010), found by ds-decomp. */
#include "common.h"

void func_ov010_02221320(u8 *arg0, void *arg1, u32 arg2, void *arg3) {
    extern s8 data_ov010_0222bd68[];
    extern s16 data_ov010_0222bd78[];
    s16 temp_r11;
    s16 temp_r11_2;
    s16 temp_r8;
    s16 temp_r8_2;
    s16 temp_r8_3;
    s16 temp_r8_4;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r9;
    s32 var_r9_2;
    u32 var_r6;
    u8 *var_r0;
    u8 temp_r7;
    u8 temp_r7_2;
    void *var_r1;

    var_r0 = arg0;
    var_r1 = arg1;
    var_r6 = 0;
    if (arg2 <= 0U) {
        return;
    }
    do {
        temp_r7 = M2C_FIELD(arg3, u8 *, 2);
        temp_r8 = M2C_FIELD(arg3, s16 *, 0);
        temp_r11 = data_ov010_0222bd78[temp_r7];
        temp_r10 = *var_r0 & 0xF;
        var_r9 = temp_r11 >> 3;
        if (temp_r10 & 4) {
            var_r9 += temp_r11;
        }
        if (temp_r10 & 2) {
            var_r9 += temp_r11 >> 1;
        }
        if (temp_r10 & 1) {
            var_r9 += temp_r11 >> 2;
        }
        if (temp_r10 & 8) {
            var_r8 = temp_r8 - var_r9;
            if (var_r8 < -0x8000) {
                var_r8 = -0x8000;
            }
        } else {
            var_r8 = temp_r8 + var_r9;
            if (var_r8 > 0x7FFF) {
                var_r8 = 0x7FFF;
            }
        }
        var_r7 = temp_r7 + data_ov010_0222bd68[temp_r10];
        if (var_r7 < 0) {
            var_r7 = 0;
        } else if (var_r7 > 0x58) {
            var_r7 = 0x58;
        }
        temp_r8_2 = (s16) var_r8;
        M2C_FIELD(arg3, s16 *, 0) = temp_r8_2;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r7;
        M2C_FIELD(var_r1, s16 *, 0) = temp_r8_2;
        temp_r7_2 = M2C_FIELD(arg3, u8 *, 2);
        temp_r8_3 = M2C_FIELD(arg3, s16 *, 0);
        temp_r11_2 = data_ov010_0222bd78[temp_r7_2];
        temp_r10_2 = ((s32) *var_r0 >> 4) & 0xF;
        var_r9_2 = temp_r11_2 >> 3;
        if (temp_r10_2 & 4) {
            var_r9_2 += temp_r11_2;
        }
        if (temp_r10_2 & 2) {
            var_r9_2 += temp_r11_2 >> 1;
        }
        if (temp_r10_2 & 1) {
            var_r9_2 += temp_r11_2 >> 2;
        }
        if (temp_r10_2 & 8) {
            var_r8_2 = temp_r8_3 - var_r9_2;
            if (var_r8_2 < -0x8000) {
                var_r8_2 = -0x8000;
            }
        } else {
            var_r8_2 = temp_r8_3 + var_r9_2;
            if (var_r8_2 > 0x7FFF) {
                var_r8_2 = 0x7FFF;
            }
        }
        var_r7_2 = temp_r7_2 + data_ov010_0222bd68[temp_r10_2];
        if (var_r7_2 < 0) {
            var_r7_2 = 0;
        } else if (var_r7_2 > 0x58) {
            var_r7_2 = 0x58;
        }
        temp_r8_4 = (s16) var_r8_2;
        M2C_FIELD(arg3, s16 *, 0) = temp_r8_4;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r7_2;
        var_r6 += 1;
        M2C_FIELD(var_r1, s16 *, 2) = temp_r8_4;
        var_r1 += 4;
        var_r0 += 1;
    } while (var_r6 < arg2);
}
