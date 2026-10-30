/* 4 functions from 0x02050C24 to 0x0205180C (main), found by ds-decomp. */
#include "common.h"

s32 func_02050c24(void **arg0, void *arg1) {
    void *func_02021768(M2C_UNK *);
    s32 func_020492ec(s32, M2C_UNK);
    s32 func_020496a4(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020496e0(s32, M2C_UNK *, M2C_UNK);
    s32 func_02049740(s32, M2C_UNK *, M2C_UNK);
    s32 func_0204978c(s32);
    s32 func_020498b8(s32, M2C_UNK *, s32 *);
    s32 func_02049900(s32);
    M2C_UNK func_02050744(void **, M2C_UNK, M2C_UNK);
    M2C_UNK func_02058620(void **, M2C_UNK, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe1f0;
    extern M2C_UNK data_020fe210;
    extern M2C_UNK data_020fe290;
    extern M2C_UNK data_020fe2b8;
    extern M2C_UNK data_020fe2ec;
    extern M2C_UNK data_020fe314;
    extern M2C_UNK data_020fe340;
    extern M2C_UNK data_020fe370;
    extern M2C_UNK data_020fe3a4;
    extern M2C_UNK data_020fe3c4;
    extern M2C_UNK data_020fe3d4;
    s32 sp8;
    u16 sp6;
    s8 sp5;
    M2C_UNK sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_4;
    s32 temp_r0_5;
    void *temp_r0_3;
    void *temp_r4;

    temp_r4 = *arg0;
    if (M2C_FIELD(temp_r4, s32 *, 0x10C) == 0) {
        temp_r0 = func_020496a4(2, 1, 0);
        M2C_FIELD(temp_r4, s32 *, 0x204) = temp_r0;
        if (temp_r0 == -1) {
            func_02058620(arg0, 5, &data_020fe290);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        if (func_020492ec(temp_r0, 0) == 0) {
            func_02058620(arg0, 5, &data_020fe2b8);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        M2C_FIELD(&sp4, s32 *, 0) = 0;
        M2C_FIELD(&sp4, s32 *, 4) = 0;
        sp5 = 2;
        if (func_020496e0(M2C_FIELD(temp_r4, s32 *, 0x204), &sp4, 8) == -1) {
            func_02058620(arg0, 5, &data_020fe2ec);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        if (func_0204978c(M2C_FIELD(temp_r4, s32 *, 0x204)) == -1) {
            func_02058620(arg0, 5, &data_020fe314);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        sp0 = 8;
        if (func_020498b8(M2C_FIELD(temp_r4, s32 *, 0x204), &sp4, &sp0) == -1) {
            func_02058620(arg0, 5, &data_020fe340);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        M2C_FIELD(temp_r4, s32 *, 0x208) = (s32) sp6;
        goto block_13;
    }
    M2C_FIELD(temp_r4, s32 *, 0x204) = -1;
    M2C_FIELD(temp_r4, s32 *, 0x208) = 0;
block_13:
    temp_r0_2 = func_020496a4(2, 1, 0);
    M2C_FIELD(temp_r4, s32 *, 0x1D4) = temp_r0_2;
    if (temp_r0_2 == -1) {
        func_02058620(arg0, 5, &data_020fe290);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    if (func_020492ec(temp_r0_2, 0) == 0) {
        func_02058620(arg0, 5, &data_020fe2b8);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    temp_r0_3 = func_02021768(&data_020fe210);
    if (temp_r0_3 == NULL) {
        func_02058620(arg0, 5, &data_020fe370);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    M2C_FIELD(&sp4, s32 *, 0) = 0;
    M2C_FIELD(&sp4, s32 *, 4) = 0;
    sp5 = 2;
    temp_r0_4 = **M2C_FIELD(temp_r0_3, s32 ***, 0xC);
    sp8 = temp_r0_4;
    if (temp_r0_4 == 0) {
        func_020640a8(&data_020fe3a4, &data_020fe3c4, &data_020fe1f0, 0x90);
    }
    sp6 = 0xCC74;
    if (func_02049740(M2C_FIELD(temp_r4, s32 *, 0x1D4), &sp4, 8) == -1) {
        temp_r0_5 = func_02049900(M2C_FIELD(temp_r4, s32 *, 0x1D4));
        if ((temp_r0_5 != -6) && (temp_r0_5 != -0x1A) && (temp_r0_5 != -0x4C)) {
            func_02058620(arg0, 5, &data_020fe3d4);
            func_02050744(arg0, 3, 1);
            return 3;
        }
        /* Duplicate return node #28. Try simplifying control flow for better match */
        M2C_FIELD(arg1, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r4, s32 *, 0x1D8) = 1;
        return 0;
    }
    M2C_FIELD(arg1, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r4, s32 *, 0x1D8) = 1;
    return 0;
}

s32 func_02050f98(void **arg0, s8 *arg1, s8 *arg2, s8 *arg3, s8 *arg4, s8 *arg5, s8 *arg6, s8 *arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {
    void *func_02037794(M2C_UNK);
    M2C_UNK func_020492a8(void *);
    s32 func_0204e84c(void **);
    s32 func_0204ec8c(void **, s32);
    s32 func_02050c24(void **, void *);
    M2C_UNK func_02052038(void **, M2C_UNK);
    M2C_UNK func_02053fe4(void **, void *);
    s32 func_02054330(void **, M2C_UNK, void *, void **, s32, s32, s32);
    M2C_UNK func_020580fc(void *, s8 *, M2C_UNK);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    M2C_UNK func_02065210(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_020fe3fc;
    extern M2C_UNK data_020fe410;
    extern M2C_UNK data_020fe424;
    void *spC;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    void *temp_r0_5;
    void *temp_r4;

    temp_r4 = *arg0;
    if (M2C_FIELD(temp_r4, s32 *, 0x1D8) == 4) {
        temp_r0_4 = func_0204e84c(arg0);
        if (temp_r0_4 != 0) {
            return temp_r0_4;
        }
    }
    if (M2C_FIELD(temp_r4, s32 *, 0x1D8) != 0) {
        func_02058644(arg0, &data_020fe3fc);
        return 2;
    }
    switch(arg8) {
    case 1: M2C_FIELD(temp_r4, volatile s32 *, 0x10C) = 1; break;
    case 0: M2C_FIELD(temp_r4, volatile s32 *, 0x10C) = 0; break;
    default: func_02058644(arg0, &data_020fe410); return 2;
    }
    M2C_FIELD(temp_r4, s32 *, 0x10C) = 1;
    func_020580fc(temp_r4 + 0x110, arg1, 0x1F);
    func_020580fc(temp_r4 + 0x12F, arg2, 0x15);
    func_020580fc(temp_r4 + 0x144, arg3, 0x33);
    func_020580fc(temp_r4 + 0x177, arg4, 0x1F);
    func_020492a8(temp_r4 + 0x144);
    temp_r0_5 = func_02037794(0x308);
    if (temp_r0_5 == NULL) {
        func_02058644(arg0, &data_020fe424);
        return 1;
    }
    func_02065210(temp_r0_5, 0, 0x308);
    M2C_FIELD(temp_r0_5, s32 *, 0x304) = arg9;
    if ((*arg5 != 0) && (*arg6 != 0)) {
        func_020580fc(temp_r0_5 + 0xC2, arg5, 0x100);
        func_020580fc(temp_r0_5 + 0x1C2, arg6, 0x100);
    }
    if (arg7 != NULL) {
        func_020580fc(temp_r0_5 + 0x2C2, arg7, 0x41);
    }
    temp_r0_3 = func_02054330(arg0, 0, temp_r0_5, &spC, argA, argB, argC);
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = func_02050c24(arg0, spC);
    if (temp_r0_2 != 0) {
        M2C_FIELD(spC, s32 *, 0x1C) = temp_r0_2;
        func_02053fe4(arg0, spC);
        func_02052038(arg0, 0);
        return temp_r0_2;
    }
    if (M2C_FIELD(spC, s32 *, 8) != 0) {
        temp_r0 = func_0204ec8c(arg0, M2C_FIELD(spC, s32 *, 0x18));
        if (temp_r0 != 0) {
            return temp_r0;
        }
    }
    return 0;
}

void func_020511dc(void *a, void *b) {
}

s32 func_02051580(void **arg0, void *arg1) {
    M2C_UNK func_020499e0(s32);
    s8 func_020499fc(M2C_UNK, M2C_UNK);
    M2C_UNK func_02049ab8(s8 *, M2C_UNK *, u32, M2C_UNK);
    M2C_UNK func_0204fea0(void **, void *, M2C_UNK *);
    M2C_UNK func_0204fed0(void **, void *, s32);
    u32 func_02068c34(void *);
    extern M2C_UNK data_020fe4a0;
    extern M2C_UNK data_020fe4f4;
    extern M2C_UNK data_020fe500;
    extern M2C_UNK data_020fe50c;
    extern M2C_UNK data_020fe51c;
    extern M2C_UNK data_020fe524;
    extern M2C_UNK data_020fe52c;
    extern M2C_UNK data_020fe538;
    extern M2C_UNK data_020fe540;
    extern M2C_UNK data_020fe548;
    extern M2C_UNK data_020fe558;
    extern M2C_UNK data_0213dc20;
    s8 spA6;
    M2C_UNK sp4C;
    s8 sp2D;
    M2C_UNK sp0;
    s8 *var_r7;
    s8 *var_r8;
    u32 temp_r6;
    u32 temp_r7;
    u32 var_r6;
    u32 var_r8_2;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r5;

    temp_r5 = *arg0;
    temp_r7 = func_02068c34(temp_r5 + 0x177);
    func_020499e0(0x79707367);
    var_r6 = 0;
    if (temp_r7 > 0U) {
        var_r8 = &sp2D;
        do {
            temp_r1 = temp_r5 + var_r6 + 0x100;
            var_r6 += 1;
            *var_r8 = M2C_FIELD(temp_r1, s8 *, 0x77) ^ func_020499fc(0, 0xFF);
            var_r8 += 1;
        } while (var_r6 < temp_r7);
    }
    (&sp2D)[var_r6] = 0;
    func_02049ab8(&sp2D, &sp0, temp_r7, 1);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe52c);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe538);
    func_0204fea0(arg0, temp_r5 + 0x1F4, temp_r5 + 0x144);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe540);
    func_0204fea0(arg0, temp_r5 + 0x1F4, temp_r5 + 0x110);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe548);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &sp0);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe4f4);
    func_0204fed0(arg0, temp_r5 + 0x1F4, M2C_FIELD(temp_r5, s32 *, 0x46C));
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe500);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_0213dc20);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe50c);
    func_0204fed0(arg0, temp_r5 + 0x1F4, M2C_FIELD(temp_r5, s32 *, 0x470));
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe4a0);
    func_0204fea0(arg0, temp_r5 + 0x1F4, temp_r5 + 0x12F);
    if (M2C_FIELD(arg1, s8 *, 0x2C2) != 0) {
        temp_r6 = func_02068c34(arg1 + 0x2C2);
        func_020499e0(0x79707367);
        var_r8_2 = 0;
        if (temp_r6 > 0U) {
            var_r7 = &spA6;
            do {
                temp_r1_2 = arg1 + var_r8_2 + 0x200;
                var_r8_2 += 1;
                *var_r7 = M2C_FIELD(temp_r1_2, s8 *, 0xC2) ^ func_020499fc(0, 0xFF);
                var_r7 += 1;
            } while (var_r8_2 < temp_r6);
        }
        (&spA6)[var_r8_2] = 0;
        func_02049ab8(&spA6, &sp4C, temp_r6, 1);
        func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe558);
        func_0204fea0(arg0, temp_r5 + 0x1F4, &sp4C);
    }
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe51c);
    func_0204fea0(arg0, temp_r5 + 0x1F4, &data_020fe524);
    return 0;
}

