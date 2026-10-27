/* 1 function from 0x02181C88 to 0x02183874 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_01ffada0(u8, u8, u32, s32, s32);
s32 func_01ffb3d0();
s32 func_01ffb9c4(s8);
void func_02007f8c(void *, s32, s32);
s32 func_0207c8ec(s32, s32);
s32 func_020a85c8(u32);
s32 func_020a85dc(u32);
s32 func_020d0164(s32, s32);
s32 func_020d27c0(s32);
s32 func_020d280c(u16, u8, s32);
s32 func_020d2d18(u16, s32);
s32 func_ov000_0219c508(s32, s32);
s32 func_ov000_021a97d0(u32, s32);
s32 func_ov000_021a97e0(u16, u32);
s32 func_ov000_021a9820(s32, u32);
s32 func_ov000_021a98e4(u32);
extern s32 *gCurrentMap;
extern s8 data_ov000_021dee08;
extern s8 data_ov000_021dee10;
extern u8 data_ov000_021df918;
extern u8 data_ov000_021df9bc;
extern u8 data_ov000_021dfa60;
extern u8 data_ov000_021dfb04;
extern u8 data_ov000_021dfba8;
extern u8 data_ov000_021dfc4c;
extern u8 data_ov000_021dfcf0;
extern u8 data_ov000_021e0f60;
void func_ov000_02181c88(void) {
    s8 *sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 *sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 var_r2_5;
    s32 temp_r0;
    s32 temp_r0_11;
    s32 temp_r0_12;
    s32 temp_r0_13;
    s32 temp_r0_14;
    s32 temp_r0_16;
    s32 temp_r0_18;
    s32 temp_r0_19;
    s32 temp_r0_20;
    s32 temp_r0_21;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_5;
    s32 temp_r0_7;
    s32 temp_r0_9;
    s32 temp_r1_3;
    s32 temp_r1_4;
    s32 temp_r1_5;
    s32 temp_r1_6;
    s32 temp_r1_7;
    s32 temp_r2_18;
    s32 temp_r2_19;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6_7;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r7_3;
    s32 temp_r7_4;
    s32 temp_r7_5;
    s32 temp_r8_2;
    s32 temp_r8_3;
    s32 temp_r8_4;
    s32 temp_r8_5;
    s32 temp_r8_6;
    s32 temp_r8_7;
    s32 temp_r8_8;
    s32 temp_r9;
    s32 temp_ret;
    s32 temp_ret_2;
    s32 temp_ret_3;
    s32 temp_ret_4;
    s32 var_lr;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_12;
    s32 var_r0_13;
    s32 var_r0_14;
    s32 var_r0_15;
    s32 var_r0_16;
    s32 var_r0_17;
    s32 var_r0_18;
    s32 var_r0_19;
    s32 var_r0_20;
    s32 var_r0_21;
    s32 var_r0_22;
    s32 var_r0_23;
    s32 var_r0_24;
    s32 var_r0_25;
    s32 var_r0_26;
    s32 var_r0_27;
    s32 var_r0_28;
    s32 var_r0_29;
    s32 var_r0_30;
    s32 var_r0_31;
    s32 var_r0_32;
    s32 var_r0_33;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r10_3;
    s32 var_r10_4;
    s32 var_r10_5;
    s32 var_r11;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r1_4;
    s32 var_r1_5;
    s32 var_r1_6;
    s32 var_r1_8;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s32 var_r2_4;
    s32 var_r2_6;
    s32 var_r2_8;
    s32 var_r2_9;
    s32 var_r3;
    s32 var_r3_10;
    s32 var_r3_11;
    s32 var_r3_12;
    s32 var_r3_13;
    s32 var_r3_14;
    s32 var_r3_15;
    s32 var_r3_16;
    s32 var_r3_17;
    s32 var_r3_18;
    s32 var_r3_19;
    s32 var_r3_20;
    s32 var_r3_21;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r3_6;
    s32 var_r3_7;
    s32 var_r3_8;
    s32 var_r3_9;
    s32 var_r4_2;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r6_4;
    s32 var_r6_6;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r7_3;
    s32 var_r7_4;
    s32 var_r7_5;
    s32 var_r7_6;
    s32 var_r7_7;
    s32 var_r7_8;
    s32 var_r8_3;
    s32 var_r8_4;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;
    s32 var_r9_6;
    s32 var_r9_7;
    s8 *var_r3_22;
    s8 *var_r4_3;
    s8 temp_r6_9;
    s8 temp_r7_8;
    u16 temp_r4_2;
    u16 var_r0;
    u16 var_r0_2;
    u16 var_r0_3;
    u16 var_r0_4;
    u16 var_r1_7;
    u16 var_r2_7;
    u16 var_r5_3;
    u16 var_r8;
    u16 var_r8_2;
    u16 var_r9_5;
    u32 temp_ip;
    u32 temp_r0_15;
    u32 temp_r1;
    u32 temp_r1_2;
    u32 temp_r2;
    u32 temp_r2_11;
    u32 temp_r2_12;
    u32 temp_r2_13;
    u32 temp_r2_14;
    u32 temp_r2_15;
    u32 temp_r2_16;
    u32 temp_r2_17;
    u32 temp_r2_2;
    u32 temp_r2_3;
    u32 temp_r2_4;
    u32 temp_r2_5;
    u32 temp_r2_6;
    u32 temp_r2_7;
    u32 temp_r2_8;
    u32 temp_r2_9;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 temp_r3_6;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u32 temp_r4_3;
    u32 temp_r4_4;
    u32 var_ip;
    u32 var_r10_6;
    u32 var_r11_2;
    u32 var_r1;
    u32 var_r6_3;
    u32 var_r6_5;
    u32 var_r6_7;
    u32 var_r9_8;
    u8 temp_r0_22;
    u8 temp_r0_24;
    u8 temp_r0_4;
    u8 temp_r0_6;
    u8 temp_r1_8;
    u8 temp_r1_9;
    u8 temp_r7_7;
    u8 var_r4;
    s8 *temp_r0_10;
    s8 *temp_r0_17;
    s8 *temp_r0_23;
    s8 *temp_r0_8;
    s8 *temp_r10;
    s8 *temp_r10_2;
    s8 *temp_r10_3;
    s8 *temp_r2_10;
    s8 *temp_r6;
    s8 *temp_r6_2;
    s8 *temp_r6_3;
    s8 *temp_r6_4;
    s8 *temp_r6_5;
    s8 *temp_r6_6;
    s8 *temp_r6_8;
    s8 *temp_r7_6;
    s8 *temp_r8;
    s8 *var_r9_4;
    
    func_02007f8c(&data_ov000_021dfcf0, 0, 0xA1);
    func_02007f8c(&data_ov000_021dfba8, 0, 0xA1);
    func_02007f8c(&data_ov000_021df918, 0, 0xA1);
    func_02007f8c(&data_ov000_021dfb04, 0, 0xA1);
    func_02007f8c(&data_ov000_021dfa60, 0, 0xA1);
    func_02007f8c(&data_ov000_021df9bc, 0, 0xA1);
    func_02007f8c(&data_ov000_021dfc4c, 0, 0xA1);
    func_02007f8c(&data_ov000_021e0f60, 0, 0x508);
    func_020d0164(*gCurrentMap + 0x2338, 0);
    func_ov000_0219c508(*gCurrentMap + 0x2840, 0);
    func_ov000_0219c508(*gCurrentMap + 0x2D48, 0);
    sp3C = 1;
    sp2C = 0xE;
    do {
        temp_r0_2 = *gCurrentMap;
        temp_r3 = temp_r0_2 + 0x59A4;
        temp_r8 = temp_r3 + sp2C;
        var_r1 = (u32) (M2C_FIELD((temp_r3 + sp2C), u8 *, 0) << 0x1A) >> 0x1A;
        if ((var_r1 != 0) && (!(M2C_FIELD(temp_r8, u16 *, 0x4) & 8) || (temp_ret = func_020a85dc((u32) (M2C_FIELD(((M2C_FIELD((M2C_FIELD((temp_r0_2 + (M2C_FIELD(temp_r8, u8 *, 0x2) * 2)), u16 *, 0x3758) + (temp_r0_2 + M2C_FIELD(temp_r8, u8 *, 0x1))), u8 *, 0x508) * 0xE) + temp_r0_2), u8 *, 0x59A4) << 0x1A) >> 0x1A), (temp_ret != 0)))) {
            temp_r4 = func_0207c8ec(((u32) (M2C_FIELD(temp_r8, u16 *, 0x6) << 0x19) >> 0x19) * func_ov000_021a97d0((u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A, 7), 0x64);
            temp_ret_2 = func_0207c8ec(((u32) (M2C_FIELD(temp_r8, u16 *, 0x6) << 0x19) >> 0x19) * func_ov000_021a97d0((u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A, 0xE), 0x64);
            temp_r0_3 = temp_ret_2;
            
            if ((temp_r4 < 0x28) && (temp_r0_3 < 0x28)) {
                
            } else if (func_ov000_021a98e4((u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A) == 0) {
                if (func_020d27c0(sp3C) != 0) {
                    temp_r3_2 = *gCurrentMap;
                    if (M2C_FIELD(((M2C_FIELD(temp_r3_2, u16 *, 0x52A4) * 0x8C) + temp_r3_2), u8 *, 0x67CE) == 3) {
                        if (temp_r8 != 0) {
                            if (temp_r8 == 0) {
                                var_r6 = 0;
                            } else {
                                temp_r3_3 = temp_r8 - (temp_r3_2 + 0x59A4);
                                var_r6 = (s32)temp_r3_3 / 14;
                            }
                            var_r0 = (var_r6 >> 6) + 1;
                        } else {
                            var_r0 = 0;
                        }
                        var_r3 = func_ov000_021a97e0(var_r0, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                    } else {
                        if (temp_r8 != 0) {
                            if (temp_r8 == 0) {
                                var_r6_2 = 0;
                            } else {
                                temp_r3_4 = temp_r8 - (temp_r3_2 + 0x59A4);
                                var_r6_2 = (s32)temp_r3_4 / 14;
                            }
                            var_r0_2 = (var_r6_2 >> 6) + 1;
                        } else {
                            var_r0_2 = 0;
                        }
                        var_r3 = (s32) (func_ov000_021a97e0(var_r0_2, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A) * 3) >> 1;
                    }
                    func_01ffada0(M2C_FIELD(temp_r8, u8 *, 0x1), M2C_FIELD(temp_r8, u8 *, 0x2), (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A, var_r3, 0);
                    var_r3_2 = 0;
                    var_r7 = *gCurrentMap;
                    var_r1 = (u32) M2C_FIELD(var_r7, u16 *, 0x5146);
                    if ((s32) var_r1 > 0) {
                        var_r1 = (u32) &data_ov000_021e0f60;
                        do {
                            var_r8 = M2C_FIELD(var_r7, u16 *, 0x5144);
                            var_r9 = 0;
                            if ((s32) var_r8 > 0) {
                                var_r6_3 = (u32) &data_ov000_021e0f60;
                                do {
                                    if ((s32) M2C_FIELD((M2C_FIELD((var_r7 + (var_r3_2 * 4)), s32 *, 0x52E8) + var_r9), s8 *, 0) >= 0) {
                                        if (temp_r4 >= 0x28) {
                                            temp_r8_2 = var_r3_2 * var_r8;
                                            M2C_FIELD((var_r6_3 + temp_r8_2), s8 *, 0) = M2C_FIELD((var_r6_3 + temp_r8_2), s8 *, 0) + 1;
                                        }
                                        if (temp_r4 >= 0x4B) {
                                            temp_r8_3 = var_r3_2 * M2C_FIELD((*gCurrentMap), u16 *, 0x5144);
                                            M2C_FIELD((var_r6_3 + temp_r8_3), s8 *, 0) = M2C_FIELD((var_r6_3 + temp_r8_3), s8 *, 0) + 1;
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r8_4 = *gCurrentMap;
                                            temp_r10 = temp_r8_4 + var_r9 + M2C_FIELD((temp_r8_4 + (var_r3_2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r10, s8 *, 0x2338) = (s8) (M2C_FIELD(temp_r10, s8 *, 0x2338) + 1);
                                        }
                                        if (temp_r0_3 >= 0x4B) {
                                            temp_r8_5 = *gCurrentMap;
                                            temp_r10_2 = temp_r8_5 + var_r9 + M2C_FIELD((temp_r8_5 + (var_r3_2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r10_2, s8 *, 0x2338) = (s8) (M2C_FIELD(temp_r10_2, s8 *, 0x2338) + 1);
                                        }
                                    }
                                    var_r9 += 1;
                                    var_r7 = *gCurrentMap;
                                    var_r6_3 += 1;
                                    var_r8 = M2C_FIELD(var_r7, u16 *, 0x5144);
                                } while (var_r9 < (s32) var_r8);
                            }
                            var_r3_2 += 1;
                        } while (var_r3_2 < (s32) M2C_FIELD(var_r7, u16 *, 0x5146));
                    }
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_3 = 0;
                        } else {
                            temp_r2 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_3 = (s32)temp_r2 / 14;
                        }
                        var_r0_3 = (var_r3_3 >> 6) + 1;
                    } else {
                        var_r0_3 = 0;
                    }
                    func_01ffada0(M2C_FIELD(temp_r8, u8 *, 0x1), M2C_FIELD(temp_r8, u8 *, 0x2), (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A, func_ov000_021a97e0(var_r0_3, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A), 0);
                    func_01ffb9c4(0x6F);
                    var_r2 = 0;
                    var_r6_4 = *gCurrentMap;
                    var_r1 = (u32) M2C_FIELD(var_r6_4, u16 *, 0x5146);
                    if ((s32) var_r1 > 0) {
                        var_r1 = 0;
                        do {
                            var_r3_4 = 0;
                            if ((s32) M2C_FIELD(var_r6_4, u16 *, 0x5144) > 0) {
                                do {
                                    if ((s32) M2C_FIELD((M2C_FIELD((var_r6_4 + (var_r2 * 4)), s32 *, 0x52E8) + var_r3_4), s8 *, 0) >= 0) {
                                        if (temp_r4 >= 0x28) {
                                            temp_r6 = var_r6_4 + var_r3_4 + M2C_FIELD((var_r6_4 + (var_r2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6, u8 *, 0x2840) = (u8) (M2C_FIELD(temp_r6, u8 *, 0x2840) + 1);
                                        }
                                        if (temp_r4 >= 0x4B) {
                                            temp_r7 = *gCurrentMap;
                                            temp_r6_2 = temp_r7 + var_r3_4 + M2C_FIELD((temp_r7 + (var_r2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6_2, u8 *, 0x2840) = (u8) (M2C_FIELD(temp_r6_2, u8 *, 0x2840) + 1);
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r7_2 = *gCurrentMap;
                                            temp_r6_3 = temp_r7_2 + var_r3_4 + M2C_FIELD((temp_r7_2 + (var_r2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6_3, u8 *, 0x2D48) = (u8) (M2C_FIELD(temp_r6_3, u8 *, 0x2D48) + 1);
                                        }
                                        if (temp_r0_3 >= 0x4B) {
                                            temp_r7_3 = *gCurrentMap;
                                            temp_r6_4 = temp_r7_3 + var_r3_4 + M2C_FIELD((temp_r7_3 + (var_r2 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6_4, u8 *, 0x2D48) = (u8) (M2C_FIELD(temp_r6_4, u8 *, 0x2D48) + 1);
                                        }
                                    }
                                    var_r3_4 += 1;
                                    var_r6_4 = *gCurrentMap;
                                } while (var_r3_4 < (s32) M2C_FIELD(var_r6_4, u16 *, 0x5144));
                            }
                            var_r2 += 1;
                        } while (var_r2 < (s32) M2C_FIELD(var_r6_4, u16 *, 0x5146));
                    }
                }
            } else if (func_020a85c8((u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A) != 0) {
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r3_5 = 0;
                    } else {
                        temp_r2_2 = temp_r8 - (*gCurrentMap + 0x59A4);
                        var_r3_5 = (s32)temp_r2_2 / 14;
                    }
                    var_r0_4 = (var_r3_5 >> 6) + 1;
                } else {
                    var_r0_4 = 0;
                }
                func_01ffada0(M2C_FIELD(temp_r8, u8 *, 0x1), M2C_FIELD(temp_r8, u8 *, 0x2), (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A, func_ov000_021a97e0(var_r0_4, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A), 1);
                var_r9_2 = 0;
                if (func_020d27c0(sp3C) != 0) {
                    if (temp_r8 == 0) {
                        var_r10 = 1;
                    } else {
                        var_r10 = 0;
                    }
                    loop_74:
                    if (var_r10 != 0) {
                        var_r0_5 = 0;
                    } else {
                        if (temp_r8 == 0) {
                            var_r2_2 = 0;
                        } else {
                            temp_r1 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r2_2 = (s32)temp_r1 / 14;
                        }
                        var_r0_5 = (var_r2_2 >> 6) + 1;
                    }
                    if (var_r9_2 < (s32) (func_ov000_021a9820(var_r0_5, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A) - 1)) {
                        func_01ffb9c4((s8) (var_r9_2 + 0x6F));
                        var_r9_2 += 1;
                        goto loop_74;
                    }
                    var_r3_6 = 0;
                    var_r7_2 = *gCurrentMap;
                    var_r1 = (u32) M2C_FIELD(var_r7_2, u16 *, 0x5146);
                    if ((s32) var_r1 > 0) {
                        var_r1 = (u32) &data_ov000_021e0f60;
                        do {
                            var_r8_2 = M2C_FIELD(var_r7_2, u16 *, 0x5144);
                            var_r9_3 = 0;
                            if ((s32) var_r8_2 > 0) {
                                var_r6_5 = (u32) &data_ov000_021e0f60;
                                do {
                                    if ((s32) M2C_FIELD((M2C_FIELD((var_r7_2 + (var_r3_6 * 4)), s32 *, 0x52E8) + var_r9_3), s8 *, 0) >= 0) {
                                        if (temp_r4 >= 0x28) {
                                            temp_r8_6 = var_r3_6 * var_r8_2;
                                            M2C_FIELD((var_r6_5 + temp_r8_6), s8 *, 0) = M2C_FIELD((var_r6_5 + temp_r8_6), s8 *, 0) + 1;
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r8_7 = *gCurrentMap;
                                            temp_r10_3 = temp_r8_7 + var_r9_3 + M2C_FIELD((temp_r8_7 + (var_r3_6 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r10_3, s8 *, 0x2338) = (s8) (M2C_FIELD(temp_r10_3, s8 *, 0x2338) + 1);
                                        }
                                    }
                                    var_r9_3 += 1;
                                    var_r7_2 = *gCurrentMap;
                                    var_r6_5 += 1;
                                    var_r8_2 = M2C_FIELD(var_r7_2, u16 *, 0x5144);
                                } while (var_r9_3 < (s32) var_r8_2);
                            }
                            var_r3_6 += 1;
                        } while (var_r3_6 < (s32) M2C_FIELD(var_r7_2, u16 *, 0x5146));
                    }
                } else {
                    if (temp_r8 == 0) {
                        var_r10_2 = 1;
                    } else {
                        var_r10_2 = 0;
                    }
                    loop_98:
                    if (var_r10_2 != 0) {
                        var_r0_6 = 0;
                    } else {
                        if (temp_r8 == 0) {
                            var_r2_3 = 0;
                        } else {
                            temp_r1_2 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r2_3 = (s32)temp_r1_2 / 14;
                        }
                        var_r0_6 = (var_r2_3 >> 6) + 1;
                    }
                    if (var_r9_2 < func_ov000_021a9820(var_r0_6, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) {
                        func_01ffb9c4((s8) (var_r9_2 + 0x6F));
                        var_r9_2 += 1;
                        goto loop_98;
                    }
                    var_r2_4 = 0;
                    var_r6_6 = *gCurrentMap;
                    var_r1 = (u32) M2C_FIELD(var_r6_6, u16 *, 0x5146);
                    if ((s32) var_r1 > 0) {
                        var_r1 = 0;
                        do {
                            var_r3_7 = 0;
                            if ((s32) M2C_FIELD(var_r6_6, u16 *, 0x5144) > 0) {
                                do {
                                    if ((s32) M2C_FIELD((M2C_FIELD((var_r6_6 + (var_r2_4 * 4)), s32 *, 0x52E8) + var_r3_7), s8 *, 0) >= 0) {
                                        if (temp_r4 >= 0x28) {
                                            temp_r6_5 = var_r6_6 + var_r3_7 + M2C_FIELD((var_r6_6 + (var_r2_4 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6_5, u8 *, 0x2840) = (u8) (M2C_FIELD(temp_r6_5, u8 *, 0x2840) + 1);
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r7_4 = *gCurrentMap;
                                            temp_r6_6 = temp_r7_4 + var_r3_7 + M2C_FIELD((temp_r7_4 + (var_r2_4 * 2)), u16 *, 0x3758);
                                            M2C_FIELD(temp_r6_6, u8 *, 0x2D48) = (u8) (M2C_FIELD(temp_r6_6, u8 *, 0x2D48) + 1);
                                        }
                                    }
                                    var_r3_7 += 1;
                                    var_r6_6 = *gCurrentMap;
                                } while (var_r3_7 < (s32) M2C_FIELD(var_r6_6, u16 *, 0x5144));
                            }
                            var_r2_4 += 1;
                        } while (var_r2_4 < (s32) M2C_FIELD(var_r6_6, u16 *, 0x5146));
                    }
                }
            } else if (func_020d27c0(sp3C) != 0) {
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r3_8 = 0;
                    } else {
                        temp_r2_3 = temp_r8 - (*gCurrentMap + 0x59A4);
                        var_r3_8 = (s32)temp_r2_3 / 14;
                    }
                    var_r0_7 = (var_r3_8 >> 6) + 1;
                } else {
                    var_r0_7 = 0;
                }
                if ((s32) ((M2C_FIELD(temp_r8, u8 *, 0x1) - func_ov000_021a9820(var_r0_7, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1) < 0) {
                    sp24 = 0;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_9 = 0;
                        } else {
                            temp_r2_4 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_9 = (s32)temp_r2_4 / 14;
                        }
                        var_r0_8 = (var_r3_9 >> 6) + 1;
                    } else {
                        var_r0_8 = 0;
                    }
                    sp24 = (M2C_FIELD(temp_r8, u8 *, 0x1) - func_ov000_021a9820(var_r0_8, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1;
                }
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r3_10 = 0;
                    } else {
                        temp_r2_5 = temp_r8 - (*gCurrentMap + 0x59A4);
                        var_r3_10 = (s32)temp_r2_5 / 14;
                    }
                    var_r0_9 = (var_r3_10 >> 6) + 1;
                } else {
                    var_r0_9 = 0;
                }
                if ((s32) ((M2C_FIELD(temp_r8, u8 *, 0x2) - func_ov000_021a9820(var_r0_9, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1) < 0) {
                    var_r10_3 = 0;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_11 = 0;
                        } else {
                            temp_r2_6 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_11 = (s32)temp_r2_6 / 14;
                        }
                        var_r0_10 = (var_r3_11 >> 6) + 1;
                    } else {
                        var_r0_10 = 0;
                    }
                    var_r10_3 = (M2C_FIELD(temp_r8, u8 *, 0x2) - func_ov000_021a9820(var_r0_10, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1;
                }
                temp_r1_3 = *gCurrentMap;
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r7_3 = 0;
                    } else {
                        temp_r3_5 = temp_r8 - (temp_r1_3 + 0x59A4);
                        var_r7_3 = (s32)temp_r3_5 / 14;
                    }
                    var_r0_11 = (var_r7_3 >> 6) + 1;
                } else {
                    var_r0_11 = 0;
                }
                if ((s32) ((M2C_FIELD(temp_r8, u8 *, 0x1) + func_ov000_021a9820(var_r0_11, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1) >= (s32) (M2C_FIELD((temp_r1_3 + 0x5120), u16 *, 0x24) - 1)) {
                    sp20 = M2C_FIELD((*gCurrentMap), u16 *, 0x5144) - 1;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_12 = 0;
                        } else {
                            temp_r2_7 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_12 = (s32)temp_r2_7 / 14;
                        }
                        var_r0_12 = (var_r3_12 >> 6) + 1;
                    } else {
                        var_r0_12 = 0;
                    }
                    sp20 = (M2C_FIELD(temp_r8, u8 *, 0x1) + func_ov000_021a9820(var_r0_12, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1;
                }
                temp_r1_4 = *gCurrentMap;
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r7_4 = 0;
                    } else {
                        temp_r3_6 = temp_r8 - (temp_r1_4 + 0x59A4);
                        var_r7_4 = (s32)temp_r3_6 / 14;
                    }
                    var_r0_13 = (var_r7_4 >> 6) + 1;
                } else {
                    var_r0_13 = 0;
                }
                var_r1 = (u32) M2C_FIELD((temp_r1_4 + 0x5120), u16 *, 0x26);
                if ((s32) ((M2C_FIELD(temp_r8, u8 *, 0x2) + func_ov000_021a9820(var_r0_13, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1) >= (s32) (var_r1 - 1)) {
                    sp1C = M2C_FIELD((*gCurrentMap), u16 *, 0x5146) - 1;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_13 = 0;
                        } else {
                            temp_r2_8 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_13 = (s32)temp_r2_8 / 14;
                        }
                        var_r0_14 = (var_r3_13 >> 6) + 1;
                    } else {
                        var_r0_14 = 0;
                    }
                    var_r1 = (u32) M2C_FIELD(temp_r8, u8 *, 0x2);
                    sp1C = (var_r1 + func_ov000_021a9820(var_r0_14, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) - 1;
                }
                if (var_r10_3 <= sp1C) {
                    do {
                        var_r1 = (u32) sp24;
                        var_r6_7 = var_r1;
                        if ((s32) var_r1 <= sp20) {
                            var_r9_4 = &data_ov000_021e0f60 + var_r6_7;
                            do {
                                temp_r0_4 = M2C_FIELD(temp_r8, u8 *, 0x1);
                                var_r1_2 = temp_r0_4 - var_r6_7;
                                if (var_r1_2 <= 0) {
                                    var_r1_2 = var_r6_7 - temp_r0_4;
                                }
                                var_r1 = (u32) M2C_FIELD(temp_r8, u8 *, 0x2);
                                var_r0_15 = var_r1 - var_r10_3;
                                if (var_r0_15 <= 0) {
                                    var_r0_15 = var_r10_3 - var_r1;
                                }
                                temp_r7_5 = var_r1_2 + var_r0_15;
                                if (temp_r7_5 >= 0) {
                                    if (temp_r8 != 0) {
                                        if (temp_r8 == 0) {
                                            var_r3_14 = 0;
                                        } else {
                                            temp_r2_9 = temp_r8 - (*gCurrentMap + 0x59A4);
                                            var_r3_14 = (s32)temp_r2_9 / 14;
                                        }
                                        var_r0_16 = (var_r3_14 >> 6) + 1;
                                    } else {
                                        var_r0_16 = 0;
                                    }
                                    temp_ret_3 = func_ov000_021a9820(var_r0_16, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                                    
                                    if (temp_r7_5 <= (s32) (temp_ret_3 - 1)) {
                                        if (temp_r4 >= 0x28) {
                                            var_r1 = var_r10_3 * M2C_FIELD((*gCurrentMap), u16 *, 0x5144);
                                            M2C_FIELD((var_r9_4 + var_r1), s8 *, 0) = M2C_FIELD((var_r9_4 + var_r1), s8 *, 0) + 1;
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r0_5 = *gCurrentMap;
                                            temp_r2_10 = temp_r0_5 + var_r6_7 + M2C_FIELD((temp_r0_5 + (var_r10_3 * 2)), u16 *, 0x3758);
                                            var_r1 = M2C_FIELD(temp_r2_10, s8 *, 0x2338) + 1;
                                            M2C_FIELD(temp_r2_10, s8 *, 0x2338) = (s8) var_r1;
                                        }
                                    }
                                }
                                var_r6_7 += 1;
                                var_r9_4 += 1;
                            } while ((s32) var_r6_7 <= sp20);
                        }
                        var_r10_3 += 1;
                    } while (var_r10_3 <= sp1C);
                }
            } else {
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r3_15 = 0;
                    } else {
                        temp_r2_11 = temp_r8 - (*gCurrentMap + 0x59A4);
                        var_r3_15 = (s32)temp_r2_11 / 14;
                    }
                    var_r0_17 = (var_r3_15 >> 6) + 1;
                } else {
                    var_r0_17 = 0;
                }
                if ((s32) (M2C_FIELD(temp_r8, u8 *, 0x1) - func_ov000_021a9820(var_r0_17, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) < 0) {
                    sp18 = 0;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_16 = 0;
                        } else {
                            temp_r2_12 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_16 = (s32)temp_r2_12 / 14;
                        }
                        var_r0_18 = (var_r3_16 >> 6) + 1;
                    } else {
                        var_r0_18 = 0;
                    }
                    sp18 = M2C_FIELD(temp_r8, u8 *, 0x1) - func_ov000_021a9820(var_r0_18, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                }
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r3_17 = 0;
                    } else {
                        temp_r2_13 = temp_r8 - (*gCurrentMap + 0x59A4);
                        var_r3_17 = (s32)temp_r2_13 / 14;
                    }
                    var_r0_19 = (var_r3_17 >> 6) + 1;
                } else {
                    var_r0_19 = 0;
                }
                if ((s32) (M2C_FIELD(temp_r8, u8 *, 0x2) - func_ov000_021a9820(var_r0_19, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) < 0) {
                    var_r10_4 = 0;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_18 = 0;
                        } else {
                            temp_r2_14 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_18 = (s32)temp_r2_14 / 14;
                        }
                        var_r0_20 = (var_r3_18 >> 6) + 1;
                    } else {
                        var_r0_20 = 0;
                    }
                    var_r10_4 = M2C_FIELD(temp_r8, u8 *, 0x2) - func_ov000_021a9820(var_r0_20, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                }
                temp_r1_5 = *gCurrentMap;
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r7_5 = 0;
                    } else {
                        temp_r3_7 = temp_r8 - (temp_r1_5 + 0x59A4);
                        var_r7_5 = (s32)temp_r3_7 / 14;
                    }
                    var_r0_21 = (var_r7_5 >> 6) + 1;
                } else {
                    var_r0_21 = 0;
                }
                if ((s32) (M2C_FIELD(temp_r8, u8 *, 0x1) + func_ov000_021a9820(var_r0_21, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) >= (s32) (M2C_FIELD((temp_r1_5 + 0x5120), u16 *, 0x24) - 1)) {
                    var_r11 = M2C_FIELD((*gCurrentMap), u16 *, 0x5144) - 1;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_19 = 0;
                        } else {
                            temp_r2_15 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_19 = (s32)temp_r2_15 / 14;
                        }
                        var_r0_22 = (var_r3_19 >> 6) + 1;
                    } else {
                        var_r0_22 = 0;
                    }
                    var_r11 = M2C_FIELD(temp_r8, u8 *, 0x1) + func_ov000_021a9820(var_r0_22, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                }
                temp_r1_6 = *gCurrentMap;
                if (temp_r8 != 0) {
                    if (temp_r8 == 0) {
                        var_r7_6 = 0;
                    } else {
                        temp_r3_8 = temp_r8 - (temp_r1_6 + 0x59A4);
                        var_r7_6 = (s32)temp_r3_8 / 14;
                    }
                    var_r0_23 = (var_r7_6 >> 6) + 1;
                } else {
                    var_r0_23 = 0;
                }
                var_r1 = (u32) M2C_FIELD((temp_r1_6 + 0x5120), u16 *, 0x26);
                if ((s32) (M2C_FIELD(temp_r8, u8 *, 0x2) + func_ov000_021a9820(var_r0_23, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A)) >= (s32) (var_r1 - 1)) {
                    sp14 = M2C_FIELD((*gCurrentMap), u16 *, 0x5146) - 1;
                } else {
                    if (temp_r8 != 0) {
                        if (temp_r8 == 0) {
                            var_r3_20 = 0;
                        } else {
                            temp_r2_16 = temp_r8 - (*gCurrentMap + 0x59A4);
                            var_r3_20 = (s32)temp_r2_16 / 14;
                        }
                        var_r0_24 = (var_r3_20 >> 6) + 1;
                    } else {
                        var_r0_24 = 0;
                    }
                    var_r1 = (u32) M2C_FIELD(temp_r8, u8 *, 0x2);
                    sp14 = var_r1 + func_ov000_021a9820(var_r0_24, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                }
                if (var_r10_4 <= sp14) {
                    do {
                        var_r7_7 = sp18;
                        if (sp18 <= var_r11) {
                            do {
                                temp_r0_6 = M2C_FIELD(temp_r8, u8 *, 0x1);
                                var_r1_3 = temp_r0_6 - var_r7_7;
                                if (var_r1_3 <= 0) {
                                    var_r1_3 = var_r7_7 - temp_r0_6;
                                }
                                var_r1 = (u32) M2C_FIELD(temp_r8, u8 *, 0x2);
                                var_r0_25 = var_r1 - var_r10_4;
                                if (var_r0_25 <= 0) {
                                    var_r0_25 = var_r10_4 - var_r1;
                                }
                                temp_r9 = var_r1_3 + var_r0_25;
                                if (temp_r9 >= 0) {
                                    if (temp_r8 != 0) {
                                        if (temp_r8 == 0) {
                                            var_r3_21 = 0;
                                        } else {
                                            temp_r2_17 = temp_r8 - (*gCurrentMap + 0x59A4);
                                            var_r3_21 = (s32)temp_r2_17 / 14;
                                        }
                                        var_r0_26 = (var_r3_21 >> 6) + 1;
                                    } else {
                                        var_r0_26 = 0;
                                    }
                                    temp_ret_4 = func_ov000_021a9820(var_r0_26, (u32) (M2C_FIELD(temp_r8, u8 *, 0x0) << 0x1A) >> 0x1A);
                                    
                                    if (temp_r9 <= temp_ret_4) {
                                        if (temp_r4 >= 0x28) {
                                            temp_r0_7 = *gCurrentMap;
                                            temp_r0_8 = temp_r0_7 + var_r7_7 + M2C_FIELD((temp_r0_7 + (var_r10_4 * 2)), u16 *, 0x3758);
                                            var_r1 = M2C_FIELD(temp_r0_8, u8 *, 0x2840) + 1;
                                            M2C_FIELD(temp_r0_8, u8 *, 0x2840) = (u8) var_r1;
                                        }
                                        if (temp_r0_3 >= 0x28) {
                                            temp_r0_9 = *gCurrentMap;
                                            temp_r0_10 = temp_r0_9 + var_r7_7 + M2C_FIELD((temp_r0_9 + (var_r10_4 * 2)), u16 *, 0x3758);
                                            var_r1 = M2C_FIELD(temp_r0_10, u8 *, 0x2D48) + 2;
                                            M2C_FIELD(temp_r0_10, u8 *, 0x2D48) = (u8) var_r1;
                                        }
                                    }
                                }
                                var_r7_7 += 1;
                            } while (var_r7_7 <= var_r11);
                        }
                        var_r10_4 += 1;
                    } while (var_r10_4 <= sp14);
                }
            }
        }
        temp_r0 = sp3C + 1;
        sp3C = temp_r0;
        sp2C += 0xE;
    } while (temp_r0 < 0x100);
    func_01ffb3d0(0, (u8) var_r1);
    sp38 = 0;
    var_r7_8 = *gCurrentMap;
    if ((s32) M2C_FIELD(var_r7_8, u16 *, 0x5146) > 0) {
        do {
            var_r4 = 0;
            if ((s32) M2C_FIELD(var_r7_8, u16 *, 0x5144) > 0) {
                sp40 = sp38 - 5;
                sp44 = sp38 + 5;
                do {
                    if (((M2C_FIELD((M2C_FIELD((var_r7_8 + (sp38 * 2)), u16 *, 0x3758) + (var_r7_8 + var_r4)), u8 *, 0x1420) & 0x1F) == 0x11) && (func_020d280c(M2C_FIELD(var_r7_8, u16 *, 0x52A4), var_r4, sp38) != 0)) {
                        func_01ffada0(var_r4, (u8) sp38, 7U, func_ov000_021a97e0(M2C_FIELD((*gCurrentMap), u16 *, 0x52A4), 7U), 0);
                        var_r1_4 = 0;
                        if ((s32) M2C_FIELD((*gCurrentMap), u16 *, 0x5146) > 0) {
                            do {
                                var_r0_27 = 0;
                                var_r9_5 = M2C_FIELD((*gCurrentMap), u16 *, 0x5144);
                                if ((s32) var_r9_5 > 0) {
                                    var_r2_5 = &data_ov000_021e0f60;
                                    do {
                                        if ((s32) M2C_FIELD((M2C_FIELD((*gCurrentMap + (var_r1_4 * 4)), s32 *, 0x52E8) + var_r0_27), s8 *, 0) >= 0) {
                                            temp_r8_8 = var_r1_4 * var_r9_5;
                                            M2C_FIELD((var_r2_5 + temp_r8_8), s8 *, 0) = M2C_FIELD((var_r2_5 + temp_r8_8), s8 *, 0) + 4;
                                        }
                                        var_r2_5 += 1;
                                        var_r0_27 += 1;
                                        var_r9_5 = M2C_FIELD((*gCurrentMap), u16 *, 0x5144);
                                    } while (var_r0_27 < (s32) var_r9_5);
                                }
                                var_r1_4 += 1;
                            } while (var_r1_4 < (s32) M2C_FIELD(((void *) *gCurrentMap), u16 *, 0x5146));
                        }
                        var_r2_6 = *gCurrentMap;
                        if (M2C_FIELD(var_r2_6, u16 *, 0x52A4) == ((s32) M2C_FIELD((M2C_FIELD((var_r2_6 + (sp38 * 2)), u16 *, 0x3758) + (var_r2_6 + var_r4)), u8 *, 0x1420) >> 5)) {
                            var_r1_5 = 0;
                            if ((s32) M2C_FIELD(var_r2_6, u16 *, 0x5146) > 0) {
                                do {
                                    var_r0_28 = 0;
                                    if ((s32) M2C_FIELD(var_r2_6, u16 *, 0x5144) > 0) {
                                        do {
                                            if ((s32) M2C_FIELD((M2C_FIELD((var_r2_6 + (var_r1_5 * 4)), s32 *, 0x52E8) + var_r0_28), s8 *, 0) >= 0) {
                                                temp_r7_6 = var_r2_6 + var_r0_28 + M2C_FIELD((var_r2_6 + (var_r1_5 * 2)), u16 *, 0x3758);
                                                M2C_FIELD(temp_r7_6, s8 *, 0x2338) = (s8) (M2C_FIELD(temp_r7_6, s8 *, 0x2338) + 2);
                                            }
                                            var_r0_28 += 1;
                                            var_r2_6 = *gCurrentMap;
                                        } while (var_r0_28 < (s32) M2C_FIELD(var_r2_6, u16 *, 0x5144));
                                    }
                                    var_r1_5 += 1;
                                } while (var_r1_5 < (s32) M2C_FIELD(var_r2_6, u16 *, 0x5146));
                            }
                        }
                        temp_r0_12 = var_r4 - 5;
                        sp10 = temp_r0_12;
                        if (temp_r0_12 < 0) {
                            sp10 = 0;
                        }
                        if (sp40 < 0) {
                            var_r8_3 = 0;
                        } else {
                            var_r8_3 = sp40;
                        }
                        temp_r0_13 = var_r4 + 5;
                        var_r9_6 = M2C_FIELD(var_r2_6, u16 *, 0x5144) - 1;
                        if (temp_r0_13 < var_r9_6) {
                            var_r9_6 = temp_r0_13;
                        }
                        temp_r0_14 = M2C_FIELD(var_r2_6, u16 *, 0x5146) - 1;
                        spC = temp_r0_14;
                        if (sp44 < temp_r0_14) {
                            spC = sp44;
                        }
                        if (var_r8_3 <= spC) {
                            do {
                                var_r1_6 = sp10;
                                if (sp10 <= var_r9_6) {
                                    temp_r2_18 = sp38 - var_r8_3;
                                    do {
                                        var_r0_29 = var_r4 - var_r1_6;
                                        if (var_r0_29 <= 0) {
                                            var_r0_29 = var_r1_6 - var_r4;
                                        }
                                        if (temp_r2_18 > 0) {
                                            var_r0_30 = var_r0_29 + temp_r2_18;
                                        } else {
                                            var_r0_30 = var_r0_29 + (var_r8_3 - sp38);
                                        }
                                        if ((var_r0_30 >= 0) && (var_r0_30 <= 5)) {
                                            temp_r0_15 = (var_r8_3 * M2C_FIELD((*gCurrentMap), u16 *, 0x5144)) + var_r1_6;
                                            M2C_FIELD((&data_ov000_021df918 + (temp_r0_15 >> 3)), u8 *, 0) = M2C_FIELD((&data_ov000_021df918 + (temp_r0_15 >> 3)), u8 *, 0) | (1 << (temp_r0_15 & 7));
                                        }
                                        var_r1_6 += 1;
                                    } while (var_r1_6 <= var_r9_6);
                                }
                                var_r8_3 += 1;
                            } while (var_r8_3 <= spC);
                        }
                    }
                    var_r4 += 1;
                    var_r7_8 = *gCurrentMap;
                } while ((s32) var_r4 < (s32) M2C_FIELD(var_r7_8, u16 *, 0x5144));
            }
            temp_r0_11 = sp38 + 1;
            sp38 = temp_r0_11;
        } while (temp_r0_11 < (s32) M2C_FIELD(var_r7_8, u16 *, 0x5146));
    }
    temp_r4_2 = M2C_FIELD(var_r7_8, u16 *, 0x52A4);
    if ((s32) (func_020d2d18(temp_r4_2, 0xE) * 0xA) <= (s32) M2C_FIELD(((temp_r4_2 * 0x8C) + var_r7_8), s32 *, 0x67A4)) {
        func_01ffb3d0(0);
        sp34 = 0;
        var_r5 = *gCurrentMap;
        var_r1_7 = M2C_FIELD(var_r5, u16 *, 0x5146);
        if ((s32) var_r1_7 > 0) {
            do {
                var_r2_7 = M2C_FIELD(var_r5, u16 *, 0x5144);
                var_r4_2 = 0;
                if ((s32) var_r2_7 > 0) {
                    sp48 = sp34 - 5;
                    sp4C = sp34 + 5;
                    do {
                        temp_r0_17 = *gCurrentMap;
                        temp_r7_7 = M2C_FIELD((M2C_FIELD((temp_r0_17 + (sp34 * 2)), u16 *, 0x3758) + (temp_r0_17 + var_r4_2)), u8 *, 0x1420);
                        if (((temp_r7_7 & 0x1F) == 0x12) && (M2C_FIELD(temp_r0_17, u16 *, 0x52A4) == ((s32) temp_r7_7 >> 5))) {
                            temp_r0_18 = var_r4_2 - 5;
                            sp8 = temp_r0_18;
                            if (temp_r0_18 < 0) {
                                sp8 = 0;
                            }
                            var_r10_5 = var_r2_7 - 1;
                            if (sp48 < 0) {
                                var_r9_7 = 0;
                            } else {
                                var_r9_7 = sp48;
                            }
                            temp_r0_19 = var_r4_2 + 5;
                            if (temp_r0_19 < var_r10_5) {
                                var_r10_5 = temp_r0_19;
                            }
                            temp_r0_20 = M2C_FIELD(var_r5, u16 *, 0x5146) - 1;
                            sp4 = temp_r0_20;
                            if (sp4C < temp_r0_20) {
                                sp4 = sp4C;
                            }
                            if (var_r9_7 <= sp4) {
                                do {
                                    var_r5_2 = sp8;
                                    if (sp8 <= var_r10_5) {
                                        temp_r6_7 = sp34 - var_r9_7;
                                        do {
                                            var_r0_31 = var_r4_2 - var_r5_2;
                                            if (var_r0_31 <= 0) {
                                                var_r0_31 = var_r5_2 - var_r4_2;
                                            }
                                            if (temp_r6_7 > 0) {
                                                var_r0_32 = var_r0_31 + temp_r6_7;
                                            } else {
                                                var_r0_32 = var_r0_31 + (var_r9_7 - sp34);
                                            }
                                            if ((var_r0_32 >= 0) && (var_r0_32 <= 5)) {
                                                temp_r2_19 = M2C_FIELD((*gCurrentMap + (var_r9_7 * 4)), s32 *, 0x52E8);
                                                M2C_FIELD((temp_r2_19 + var_r5_2), s8 *, 0) = M2C_FIELD((temp_r2_19 + var_r5_2), s8 *, 0) + 1;
                                                temp_ip = (var_r9_7 * M2C_FIELD((*gCurrentMap), u16 *, 0x5144)) + var_r5_2;
                                                M2C_FIELD((&data_ov000_021df918 + (temp_ip >> 3)), u8 *, 0) = M2C_FIELD((&data_ov000_021df918 + (temp_ip >> 3)), u8 *, 0) | (1 << (temp_ip & 7));
                                            }
                                            var_r5_2 += 1;
                                        } while (var_r5_2 <= var_r10_5);
                                    }
                                    var_r9_7 += 1;
                                } while (var_r9_7 <= sp4);
                            }
                        }
                        var_r5 = (s32) *gCurrentMap;
                        var_r4_2 += 1;
                        var_r2_7 = M2C_FIELD(var_r5, u16 *, 0x5144);
                    } while (var_r4_2 < (s32) var_r2_7);
                }
                var_r1_7 = M2C_FIELD(var_r5, u16 *, 0x5146);
                temp_r0_16 = sp34 + 1;
                sp34 = temp_r0_16;
            } while (temp_r0_16 < (s32) var_r1_7);
        }
        var_r2_8 = 0;
        if ((s32) var_r1_7 > 0) {
            do {
                var_r1_8 = 0;
                if ((s32) M2C_FIELD(var_r5, u16 *, 0x5144) > 0) {
                    do {
                        if (M2C_FIELD((M2C_FIELD((var_r5 + (var_r2_8 * 4)), s32 *, 0x52E8) + var_r1_8), u8 *, 0) != 0) {
                            temp_r5 = *gCurrentMap;
                            temp_r6_8 = temp_r5 + var_r1_8 + M2C_FIELD((temp_r5 + (var_r2_8 * 2)), u16 *, 0x3758);
                            M2C_FIELD(temp_r6_8, s8 *, 0x2338) = (s8) (M2C_FIELD(temp_r6_8, s8 *, 0x2338) + 1);
                        }
                        var_r1_8 += 1;
                        var_r5 = *gCurrentMap;
                    } while (var_r1_8 < (s32) M2C_FIELD(var_r5, u16 *, 0x5144));
                }
                var_r2_8 += 1;
            } while (var_r2_8 < (s32) M2C_FIELD(var_r5, u16 *, 0x5146));
        }
    }
    var_lr = 0;
    sp28 = gCurrentMap;
    if ((s32) M2C_FIELD((*gCurrentMap), u16 *, 0x5146) <= 0) {
        return;
    }
    do {
        var_r2_9 = 0;
        var_r0_33 = *sp28;
        var_r5_3 = M2C_FIELD(var_r0_33, u16 *, 0x5144);
        if ((s32) var_r5_3 > 0) {
            sp30 = &data_ov000_021e0f60;
            do {
                var_r9_8 = 0;
                sp50 = var_r0_33 + var_r2_9;
                var_r3_22 = &data_ov000_021dee08;
                var_r4_3 = &data_ov000_021dee10;
                var_r11_2 = 0;
                var_r10_6 = 0;
                var_ip = 0;
                var_r8_4 = 0;
                sp54 = var_r0_33 + (var_lr * 2);
                sp58 = var_r0_33 + 0x5100;
                loop_370:
                temp_r7_8 = *var_r3_22;
                temp_r0_21 = var_r2_9 + temp_r7_8;
                if ((temp_r0_21 >= 0) && (temp_r0_21 < (s32) var_r5_3)) {
                    temp_r6_9 = *var_r4_3;
                    temp_r1_7 = var_lr + temp_r6_9;
                    if ((temp_r1_7 >= 0) && (temp_r1_7 < (s32) M2C_FIELD(sp58, u16 *, 0x46))) {
                        temp_r0_22 = M2C_FIELD(((temp_r1_7 * var_r5_3) + (sp30 + temp_r7_8)), u8 *, 0);
                        if (var_r9_8 <= (u32) temp_r0_22) {
                            var_r9_8 = (u32) temp_r0_22;
                        }
                        temp_r0_23 = sp50 + temp_r7_8 + M2C_FIELD((sp54 + (temp_r6_9 * 2)), u16 *, 0x3758);
                        temp_r1_8 = M2C_FIELD(temp_r0_23, u8 *, 0x2338);
                        if (var_r10_6 <= (u32) temp_r1_8) {
                            var_r10_6 = (u32) temp_r1_8;
                        }
                        temp_r1_9 = M2C_FIELD(temp_r0_23, u8 *, 0x2840);
                        temp_r0_24 = M2C_FIELD(temp_r0_23, u8 *, 0x2D48);
                        if (var_r11_2 <= (u32) temp_r1_9) {
                            var_r11_2 = (u32) temp_r1_9;
                        }
                        if (var_ip <= (u32) temp_r0_24) {
                            var_ip = (u32) temp_r0_24;
                        }
                    }
                }
                var_r3_22 += 1;
                var_r4_3 += 1;
                var_r8_4 += 1;
                if (var_r8_4 < 5) {
                    goto loop_370;
                }
                if (var_r9_8 >= var_r11_2) {
                    temp_r4_3 = (var_lr * var_r5_3) + var_r2_9;
                    M2C_FIELD((&data_ov000_021dfcf0 + (temp_r4_3 >> 3)), u8 *, 0) = M2C_FIELD((&data_ov000_021dfcf0 + (temp_r4_3 >> 3)), u8 *, 0) | (1 << (temp_r4_3 & 7));
                }
                if (var_r10_6 >= var_ip) {
                    temp_r4_4 = (var_lr * M2C_FIELD((*sp28), u16 *, 0x5144)) + var_r2_9;
                    M2C_FIELD((&data_ov000_021dfba8 + (temp_r4_4 >> 3)), u8 *, 0) = M2C_FIELD((&data_ov000_021dfba8 + (temp_r4_4 >> 3)), u8 *, 0) | (1 << (temp_r4_4 & 7));
                }
                var_r2_9 += 1;
                var_r0_33 = *sp28;
                var_r5_3 = M2C_FIELD(var_r0_33, u16 *, 0x5144);
                sp30 += 1;
            } while (var_r2_9 < (s32) var_r5_3);
        }
        var_lr += 1;
    } while (var_lr < (s32) M2C_FIELD(var_r0_33, u16 *, 0x5146));
}
