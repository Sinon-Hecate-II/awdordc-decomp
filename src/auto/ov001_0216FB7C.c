/* 7 functions from 0x0216FB7C to 0x02170830 (ov001), found by ds-decomp. */
#include "common.h"

s32 func_ov001_0216fb7c(void *arg0, void *arg1, s32 arg2) {
    extern s32 data_ov001_0218ca50;
    extern M2C_UNK data_ov001_0218e678;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;
    s32 *var_r5;
    s32 *var_r5_2;
    s32 *var_r5_3;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 temp_r1_5;
    s32 temp_r1_7;
    s32 temp_r1_8;
    s32 temp_r2;
    s32 temp_r2_10;
    s32 temp_r2_2;
    s32 temp_r2_3;
    s32 temp_r2_4;
    s32 temp_r2_5;
    s32 temp_r2_6;
    s32 temp_r2_7;
    s32 temp_r2_8;
    s32 temp_r2_9;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r6;
    s32 temp_r6_2;
    u32 temp_r4;
    u32 temp_r4_2;
    u32 temp_r4_3;
    u32 temp_r6_3;
    u8 temp_r1;
    u8 temp_r1_4;
    u8 temp_r1_6;
    void *var_r0;

    var_r0 = arg0;
    sp0 = 0;
    M2C_FIELD(var_r0, s32 *, 0) = (s32) ((M2C_FIELD(arg1, u8 *, 0) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 1) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 2) << 8) ^ M2C_FIELD(arg1, u8 *, 3));
    M2C_FIELD(var_r0, s32 *, 4) = (s32) ((M2C_FIELD(arg1, u8 *, 4) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 5) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 6) << 8) ^ M2C_FIELD(arg1, u8 *, 7));
    M2C_FIELD(var_r0, s32 *, 8) = (s32) ((M2C_FIELD(arg1, u8 *, 8) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 9) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0xA) << 8) ^ M2C_FIELD(arg1, u8 *, 0xB));
    M2C_FIELD(var_r0, s32 *, 0xC) = (s32) ((M2C_FIELD(arg1, u8 *, 0xC) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 0xD) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0xE) << 8) ^ M2C_FIELD(arg1, u8 *, 0xF));
    if (arg2 == 0x80) {
        var_r5 = (s32 *)&data_ov001_0218ca50;
loop_2:
        temp_r4 = M2C_FIELD(var_r0, u32 *, 0xC);
        temp_r3 = *var_r5;
        var_r5 += 4;
        temp_r1 = (u8) *(&data_ov001_0218e678 + ((temp_r4 >> 0x18) * 4));
        sp8 = (s32) temp_r1;
        temp_r1_2 = M2C_FIELD(var_r0, s32 *, 0);
        sp4 = temp_r1_2;
        temp_r3_2 = temp_r3 ^ (temp_r1 ^ ((*(&data_ov001_0218e678 + ((u32) (temp_r4 << 0x18) >> 0x16)) & 0xFF00) ^ (temp_r1_2 ^ (*(&data_ov001_0218e678 + ((u32) ((temp_r4 >> 0x10) << 0x18) >> 0x16)) & 0xFF000000) ^ (0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((temp_r4 >> 8) << 0x18) >> 0x16))))));
        M2C_FIELD(var_r0, s32 *, 0x10) = temp_r3_2;
        temp_r3_3 = temp_r3_2 ^ M2C_FIELD(var_r0, s32 *, 4);
        M2C_FIELD(var_r0, s32 *, 0x14) = temp_r3_3;
        temp_r3_4 = temp_r3_3 ^ M2C_FIELD(var_r0, s32 *, 8);
        M2C_FIELD(var_r0, s32 *, 0x18) = temp_r3_4;
        M2C_FIELD(var_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(var_r0, u32 *, 0xC) ^ temp_r3_4);
        temp_r1_3 = sp0 + 1;
        sp0 = temp_r1_3;
        if (temp_r1_3 < 0xA) {
            var_r0 += 0x10;
            goto loop_2;
        }
        return 0xA;
    }
    M2C_FIELD(var_r0, s32 *, 0x10) = (s32) ((M2C_FIELD(arg1, u8 *, 0x10) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 0x11) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0x12) << 8) ^ M2C_FIELD(arg1, u8 *, 0x13));
    M2C_FIELD(var_r0, s32 *, 0x14) = (s32) ((M2C_FIELD(arg1, u8 *, 0x14) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 0x15) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0x16) << 8) ^ M2C_FIELD(arg1, u8 *, 0x17));
    if (arg2 == 0xC0) {
        var_r5_2 = (s32 *)&data_ov001_0218ca50;
loop_7:
        temp_r4_2 = M2C_FIELD(var_r0, u32 *, 0x14);
        temp_r6 = *var_r5_2;
        var_r5_2 += 4;
        temp_r1_4 = (u8) *(&data_ov001_0218e678 + ((temp_r4_2 >> 0x18) * 4));
        spC = (s32) temp_r1_4;
        temp_r2 = temp_r6 ^ (temp_r1_4 ^ ((*(&data_ov001_0218e678 + ((u32) (temp_r4_2 << 0x18) >> 0x16)) & 0xFF00) ^ ((0xFF000000 & *(&data_ov001_0218e678 + ((u32) ((temp_r4_2 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(var_r0, s32 *, 0) ^ (0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((temp_r4_2 >> 8) << 0x18) >> 0x16))))));
        M2C_FIELD(var_r0, s32 *, 0x18) = temp_r2;
        temp_r2_2 = temp_r2 ^ M2C_FIELD(var_r0, s32 *, 4);
        M2C_FIELD(var_r0, s32 *, 0x1C) = temp_r2_2;
        temp_r2_3 = temp_r2_2 ^ M2C_FIELD(var_r0, s32 *, 8);
        M2C_FIELD(var_r0, s32 *, 0x20) = temp_r2_3;
        M2C_FIELD(var_r0, s32 *, 0x24) = (s32) (M2C_FIELD(var_r0, s32 *, 0xC) ^ temp_r2_3);
        temp_r1_5 = sp0 + 1;
        sp0 = temp_r1_5;
        if (temp_r1_5 < 8) {
            temp_r2_4 = M2C_FIELD(var_r0, s32 *, 0x10) ^ M2C_FIELD(var_r0, s32 *, 0x24);
            M2C_FIELD(var_r0, s32 *, 0x28) = temp_r2_4;
            M2C_FIELD(var_r0, s32 *, 0x2C) = (s32) (M2C_FIELD(var_r0, u32 *, 0x14) ^ temp_r2_4);
            var_r0 += 0x18;
            goto loop_7;
        }
        return 0xC;
    }
    M2C_FIELD(var_r0, s32 *, 0x18) = (s32) ((M2C_FIELD(arg1, u8 *, 0x18) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 0x19) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0x1A) << 8) ^ M2C_FIELD(arg1, u8 *, 0x1B));
    M2C_FIELD(var_r0, s32 *, 0x1C) = (s32) ((M2C_FIELD(arg1, u8 *, 0x1C) << 0x18) ^ (M2C_FIELD(arg1, u8 *, 0x1D) << 0x10) ^ (M2C_FIELD(arg1, u8 *, 0x1E) << 8) ^ M2C_FIELD(arg1, u8 *, 0x1F));
    if (arg2 == 0x100) {
        var_r5_3 = (s32 *)&data_ov001_0218ca50;
loop_12:
        temp_r4_3 = M2C_FIELD(var_r0, u32 *, 0x1C);
        temp_r6_2 = *var_r5_3;
        var_r5_3 += 4;
        temp_r1_6 = (u8) *(&data_ov001_0218e678 + ((temp_r4_3 >> 0x18) * 4));
        sp10 = (s32) temp_r1_6;
        temp_r2_5 = temp_r6_2 ^ (temp_r1_6 ^ ((*(&data_ov001_0218e678 + ((u32) (temp_r4_3 << 0x18) >> 0x16)) & 0xFF00) ^ ((0xFF000000 & *(&data_ov001_0218e678 + ((u32) ((temp_r4_3 >> 0x10) << 0x18) >> 0x16))) ^ M2C_FIELD(var_r0, s32 *, 0) ^ (0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((temp_r4_3 >> 8) << 0x18) >> 0x16))))));
        M2C_FIELD(var_r0, s32 *, 0x20) = temp_r2_5;
        temp_r2_6 = temp_r2_5 ^ M2C_FIELD(var_r0, s32 *, 4);
        M2C_FIELD(var_r0, s32 *, 0x24) = temp_r2_6;
        temp_r2_7 = temp_r2_6 ^ M2C_FIELD(var_r0, s32 *, 8);
        M2C_FIELD(var_r0, s32 *, 0x28) = temp_r2_7;
        M2C_FIELD(var_r0, u32 *, 0x2C) = (u32) (M2C_FIELD(var_r0, s32 *, 0xC) ^ temp_r2_7);
        temp_r1_7 = sp0 + 1;
        sp0 = temp_r1_7;
        if (temp_r1_7 < 7) {
            temp_r6_3 = M2C_FIELD(var_r0, u32 *, 0x2C);
            temp_r1_8 = 0xFF00 & *(&data_ov001_0218e678 + ((u32) ((temp_r6_3 >> 8) << 0x18) >> 0x16));
            sp14 = temp_r1_8;
            temp_r2_8 = (u8) *(&data_ov001_0218e678 + ((u32) (temp_r6_3 << 0x18) >> 0x16)) ^ (temp_r1_8 ^ ((0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((temp_r6_3 >> 0x10) << 0x18) >> 0x16))) ^ ((0xFF000000 & *(&data_ov001_0218e678 + ((temp_r6_3 >> 0x18) * 4))) ^ M2C_FIELD(var_r0, s32 *, 0x10))));
            M2C_FIELD(var_r0, s32 *, 0x30) = temp_r2_8;
            temp_r2_9 = temp_r2_8 ^ M2C_FIELD(var_r0, s32 *, 0x14);
            M2C_FIELD(var_r0, s32 *, 0x34) = temp_r2_9;
            temp_r2_10 = temp_r2_9 ^ M2C_FIELD(var_r0, s32 *, 0x18);
            M2C_FIELD(var_r0, s32 *, 0x38) = temp_r2_10;
            M2C_FIELD(var_r0, s32 *, 0x3C) = (s32) (M2C_FIELD(var_r0, u32 *, 0x1C) ^ temp_r2_10);
            var_r0 += 0x20;
            goto loop_12;
        }
        return 0xE;
    }
    return sp0;
}

#pragma thumb on
void func_ov001_0216ffc4(void *arg0, s32 arg1, void *arg2, void *arg3) {
    extern M2C_UNK data_ov001_0218d678;
    extern M2C_UNK data_ov001_0218da78;
    extern M2C_UNK data_ov001_0218de78;
    extern M2C_UNK data_ov001_0218e278;
    extern M2C_UNK data_ov001_0218e678;
    s32 sp48;
    u32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    s32 sp4;
    void *sp0;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4_2;
    s32 temp_r4_4;
    s32 temp_r4_6;
    s32 temp_r4_8;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r7;
    u32 temp_r1_4;
    u32 temp_r2;
    u32 var_r5;
    u32 var_r6;
    u8 temp_r0;
    u8 temp_r4;
    u8 temp_r4_3;
    u8 temp_r4_5;
    u8 temp_r4_7;
    u8 temp_r4_9;
    void *var_r0;

    var_r0 = arg0;
    sp0 = arg3;
    spC = (M2C_FIELD(arg2, u8 *, 0) << 0x18) ^ (M2C_FIELD(arg2, u8 *, 1) << 0x10) ^ (M2C_FIELD(arg2, u8 *, 2) << 8) ^ M2C_FIELD(arg2, u8 *, 3) ^ M2C_FIELD(var_r0, s32 *, 0);
    sp8 = (M2C_FIELD(arg2, u8 *, 4) << 0x18) ^ (M2C_FIELD(arg2, u8 *, 5) << 0x10) ^ (M2C_FIELD(arg2, u8 *, 6) << 8) ^ M2C_FIELD(arg2, u8 *, 7) ^ M2C_FIELD(var_r0, s32 *, 4);
    var_r5 = M2C_FIELD(var_r0, s32 *, 8) ^ ((M2C_FIELD(arg2, u8 *, 8) << 0x18) ^ (M2C_FIELD(arg2, u8 *, 9) << 0x10) ^ (M2C_FIELD(arg2, u8 *, 0xA) << 8) ^ M2C_FIELD(arg2, u8 *, 0xB));
    var_r6 = M2C_FIELD(var_r0, s32 *, 0xC) ^ ((M2C_FIELD(arg2, u8 *, 0xD) << 0x10) ^ (M2C_FIELD(arg2, u8 *, 0xC) << 0x18) ^ (M2C_FIELD(arg2, u8 *, 0xE) << 8) ^ M2C_FIELD(arg2, u8 *, 0xF));
    sp4 = arg1 >> 1;
loop_1:
    temp_r1 = *(&data_ov001_0218de78 + ((u32) ((var_r5 >> 8) << 0x18) >> 0x16));
    sp40 = temp_r1;
    sp10 = temp_r1 ^ (*(&data_ov001_0218d678 + ((spC >> 0x18) * 4)) ^ *(&data_ov001_0218da78 + ((u32) ((sp8 >> 0x10) << 0x18) >> 0x16))) ^ *(&data_ov001_0218e278 + ((u32) (var_r6 << 0x18) >> 0x16)) ^ M2C_FIELD(var_r0, s32 *, 0x10);
    temp_r1_2 = *(&data_ov001_0218de78 + ((u32) ((var_r6 >> 8) << 0x18) >> 0x16));
    sp48 = temp_r1_2;
    sp44 = temp_r1_2 ^ (*(&data_ov001_0218d678 + ((sp8 >> 0x18) * 4)) ^ *(&data_ov001_0218da78 + ((u32) ((var_r5 >> 0x10) << 0x18) >> 0x16))) ^ *(&data_ov001_0218e278 + ((u32) (spC << 0x18) >> 0x16)) ^ M2C_FIELD(var_r0, s32 *, 0x14);
    temp_r1_3 = *(&data_ov001_0218de78 + ((u32) ((spC >> 8) << 0x18) >> 0x16));
    sp14 = temp_r1_3;
    temp_r7 = M2C_FIELD(var_r0, s32 *, 0x1C);
    temp_r2 = M2C_FIELD(var_r0, s32 *, 0x18) ^ (temp_r1_3 ^ (*(&data_ov001_0218d678 + ((var_r5 >> 0x18) * 4)) ^ *(&data_ov001_0218da78 + ((u32) ((var_r6 >> 0x10) << 0x18) >> 0x16))) ^ *(&data_ov001_0218e278 + ((u32) (sp8 << 0x18) >> 0x16)));
    var_r0 += 0x20;
    temp_r1_4 = *(&data_ov001_0218de78 + ((u32) ((sp8 >> 8) << 0x18) >> 0x16)) ^ (*(&data_ov001_0218da78 + ((u32) ((spC >> 0x10) << 0x18) >> 0x16)) ^ *(&data_ov001_0218d678 + ((var_r6 >> 0x18) * 4))) ^ *(&data_ov001_0218e278 + ((u32) (var_r5 << 0x18) >> 0x16)) ^ temp_r7;
    temp_r3 = sp4 - 1;
    sp4 = temp_r3;
    if (temp_r3 != 0) {
        temp_r5 = *(&data_ov001_0218d678 + ((sp10 >> 0x18) * 4));
        sp18 = temp_r5;
        spC = *(&data_ov001_0218e278 + ((u32) (temp_r1_4 << 0x18) >> 0x16)) ^ (temp_r5 ^ *(&data_ov001_0218da78 + ((u32) ((sp44 >> 0x10) << 0x18) >> 0x16)) ^ *(&data_ov001_0218de78 + ((u32) ((temp_r2 >> 8) << 0x18) >> 0x16))) ^ M2C_FIELD(var_r0, s32 *, 0);
        temp_r5_2 = *(&data_ov001_0218d678 + ((sp44 >> 0x18) * 4));
        sp1C = temp_r5_2;
        sp8 = *(&data_ov001_0218e278 + ((u32) (sp10 << 0x18) >> 0x16)) ^ (temp_r5_2 ^ *(&data_ov001_0218da78 + ((u32) ((temp_r2 >> 0x10) << 0x18) >> 0x16)) ^ *(&data_ov001_0218de78 + ((u32) ((temp_r1_4 >> 8) << 0x18) >> 0x16))) ^ M2C_FIELD(var_r0, s32 *, 4);
        temp_r3_2 = *(&data_ov001_0218de78 + ((u32) ((sp10 >> 8) << 0x18) >> 0x16));
        sp20 = temp_r3_2;
        var_r5 = M2C_FIELD(var_r0, s32 *, 8) ^ (temp_r3_2 ^ (*(&data_ov001_0218d678 + ((temp_r2 >> 0x18) * 4)) ^ *(&data_ov001_0218da78 + ((u32) ((temp_r1_4 >> 0x10) << 0x18) >> 0x16))) ^ *(&data_ov001_0218e278 + ((u32) (sp44 << 0x18) >> 0x16)));
        var_r6 = M2C_FIELD(var_r0, s32 *, 0xC) ^ (*(&data_ov001_0218da78 + ((u32) ((sp10 >> 0x10) << 0x18) >> 0x16)) ^ *(&data_ov001_0218d678 + ((temp_r1_4 >> 0x18) * 4)) ^ *(&data_ov001_0218de78 + ((u32) ((sp44 >> 8) << 0x18) >> 0x16)) ^ *(&data_ov001_0218e278 + ((u32) (temp_r2 << 0x18) >> 0x16)));
        goto loop_1;
    }
    sp24 = M2C_FIELD(var_r0, s32 *, 0);
    temp_r4 = (u8) *(&data_ov001_0218e678 + ((u32) (temp_r1_4 << 0x18) >> 0x16));
    sp28 = (s32) temp_r4;
    temp_r4_2 = 0xFF00 & *(&data_ov001_0218e678 + ((u32) ((temp_r2 >> 8) << 0x18) >> 0x16));
    sp2C = temp_r4_2;
    temp_r4_3 = sp24 ^ ((*(&data_ov001_0218e678 + ((sp10 >> 0x18) * 4)) & 0xFF000000) ^ (*(&data_ov001_0218e678 + ((u32) ((sp44 >> 0x10) << 0x18) >> 0x16)) & 0xFF0000) ^ temp_r4_2 ^ temp_r4);
    M2C_FIELD(sp0, s8 *, 0) = (s8) (temp_r4_3 >> 0x18);
    M2C_FIELD(sp0, s8 *, 1) = (s8) (temp_r4_3 >> 0x10);
    M2C_FIELD(sp0, s8 *, 2) = (s8) (temp_r4_3 >> 8);
    M2C_FIELD(sp0, u8 *, 3) = temp_r4_3;
    temp_r4_4 = M2C_FIELD(var_r0, s32 *, 4);
    sp30 = temp_r4_4;
    temp_r4_5 = (u8) *(&data_ov001_0218e678 + ((u32) (sp10 << 0x18) >> 0x16));
    sp34 = (s32) temp_r4_5;
    temp_r4_6 = 0xFF00 & *(&data_ov001_0218e678 + ((u32) ((temp_r1_4 >> 8) << 0x18) >> 0x16));
    sp38 = temp_r4_6;
    temp_r4_7 = temp_r4_4 ^ ((*(&data_ov001_0218e678 + ((sp44 >> 0x18) * 4)) & 0xFF000000) ^ (*(&data_ov001_0218e678 + ((u32) ((temp_r2 >> 0x10) << 0x18) >> 0x16)) & 0xFF0000) ^ temp_r4_6 ^ temp_r4_5);
    M2C_FIELD(sp0, s8 *, 4) = (s8) (temp_r4_7 >> 0x18);
    M2C_FIELD(sp0, s8 *, 5) = (s8) (temp_r4_7 >> 0x10);
    M2C_FIELD(sp0, s8 *, 6) = (s8) (temp_r4_7 >> 8);
    M2C_FIELD(sp0, u8 *, 7) = temp_r4_7;
    temp_r4_8 = M2C_FIELD(var_r0, s32 *, 8);
    sp3C = temp_r4_8;
    temp_r4_9 = temp_r4_8 ^ ((0xFF00 & *(&data_ov001_0218e678 + ((u32) ((sp10 >> 8) << 0x18) >> 0x16))) ^ ((0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((temp_r1_4 >> 0x10) << 0x18) >> 0x16))) ^ (*(&data_ov001_0218e678 + ((temp_r2 >> 0x18) * 4)) & 0xFF000000)) ^ (u8) *(&data_ov001_0218e678 + ((u32) (sp44 << 0x18) >> 0x16)));
    M2C_FIELD(sp0, s8 *, 8) = (s8) (temp_r4_9 >> 0x18);
    M2C_FIELD(sp0, s8 *, 9) = (s8) (temp_r4_9 >> 0x10);
    M2C_FIELD(sp0, s8 *, 0xA) = (s8) (temp_r4_9 >> 8);
    M2C_FIELD(sp0, u8 *, 0xB) = temp_r4_9;
    temp_r0 = (0xFF000000 & *(&data_ov001_0218e678 + ((temp_r1_4 >> 0x18) * 4))) ^ (0xFF0000 & *(&data_ov001_0218e678 + ((u32) ((sp10 >> 0x10) << 0x18) >> 0x16))) ^ (*(&data_ov001_0218e678 + ((u32) ((sp44 >> 8) << 0x18) >> 0x16)) & 0xFF00) ^ (u8) *(&data_ov001_0218e678 + ((u32) (temp_r2 << 0x18) >> 0x16)) ^ M2C_FIELD(var_r0, s32 *, 0xC);
    M2C_FIELD(sp0, s8 *, 0xC) = (s8) (temp_r0 >> 0x18);
    M2C_FIELD(sp0, s8 *, 0xD) = (s8) (temp_r0 >> 0x10);
    M2C_FIELD(sp0, s8 *, 0xE) = (s8) (temp_r0 >> 8);
    M2C_FIELD(sp0, u8 *, 0xF) = temp_r0;
}

void func_ov001_0217073c(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)(arg0) = 0x67452301;
    *(s32 *)((u8 *)arg0 + 0x4) = 0xEFCDAB89;
    *(s32 *)((u8 *)arg0 + 0x8) = 0x98BADCFE;
    *(s32 *)((u8 *)arg0 + 0xC) = 0x10325476;
}

#pragma thumb on
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov001_02170764(void *arg0,s32 arg1,u32 arg2){
M2C_UNK func_ov001_02170830(void *,void *);
M2C_UNK func_ov001_021710d0(void *,s32,u32);
u32 offset,old,bits,total,used;
offset=(M2C_FIELD(arg0,u32 *,0x10)>>3)&63;
old=M2C_FIELD(arg0,u32 *,0x10);
bits=arg2<<3;total=old+bits;
M2C_FIELD(arg0,u32 *,0x10)=total;
if(total<bits)M2C_FIELD(arg0,u32 *,0x14)++;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
used=64-offset;
if(arg2>=used){
func_ov001_021710d0(arg0+24+offset,arg1,used);
func_ov001_02170830(arg0,arg0+24);
while(used+63<arg2){func_ov001_02170830(arg0,(void *)(arg1+used));used+=64;}
offset=0;
}else used=0;
func_ov001_021710d0(arg0+24+offset,arg1+used,arg2-used);
}

#pragma thumb on
void func_ov001_021707dc(void *arg0, void *arg1) {
    void func_ov001_02170764(void *, s32, u32);
    void func_ov001_02171078(u8 *, volatile u32 *, u32);
    void func_ov001_021710e8(s8 *, s32, u32);
    extern M2C_UNK data_ov001_0218fe68;
    u8 sp0[8];
    u32 temp_r1;

    func_ov001_02171078(sp0, (volatile u32 *)((u8 *)arg1 + 0x10), 8);
    temp_r1 = (*(u32 *)((u8 *)arg1 + 0x10) >> 3) & 0x3F;
    {
        s32 var_r2;
        if (temp_r1 < 0x38) {
            var_r2 = 0x38 - temp_r1;
        } else {
            var_r2 = 0x78 - temp_r1;
        }
        func_ov001_02170764(arg1, (s32)&data_ov001_0218fe68, (u32)var_r2);
    }
    func_ov001_02170764(arg1, (s32)sp0, 8);
    func_ov001_02171078((u8 *)arg0, (volatile u32 *)arg1, 0x10);
    func_ov001_021710e8((s8 *)arg1, 0, 0x58);
}
#pragma thumb off

#pragma pop
#pragma thumb off

#pragma thumb off
