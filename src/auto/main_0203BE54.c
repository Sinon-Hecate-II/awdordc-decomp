/* 10 functions from 0x0203BE54 to 0x0203CB38 (main), found by ds-decomp. */
#include "common.h"

s32 func_0203c0b0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0203761c();
    void *func_02044268();
    s32 func_02060b68(s32, M2C_UNK, s32);
    s32 func_02061784(s32, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = arg2;
    if ((func_02044268() == NULL) || (func_0203761c() != 0)) {
        return var_r4;
    }
    temp_r0 = func_02061784(M2C_FIELD(func_02044268(), s32 *, 0xE4), arg0);
    if (temp_r0 != 0) {
        var_r4 = func_02060b68(temp_r0, arg1, var_r4);
    }
    return var_r4;
}

void func_0203c878(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_0203c28c(s32);
    M2C_UNK func_0203e410();
    M2C_UNK func_0203e908(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02042f94();
    M2C_UNK func_02044278(M2C_UNK);
    extern M2C_UNK data_0213d39c;
    void *temp_r4;

    func_0203e908(2, arg0, arg1, arg2);
    M2C_FIELD(func_02044268(), s32 *, 0x46C) = arg3;
    M2C_FIELD(func_02044268(), s32 *, 0x470) = arg4;
    temp_r4 = func_02044268();
    M2C_FIELD(temp_r4, s32 *, 0xF4) = (s32) M2C_FIELD(func_02044268(), s32 *, 0x200);
    M2C_FIELD(func_02044268(), s32 *, 0x2F0) = 1;
    M2C_FIELD(func_02044268(), s8 *, 0xE) = 0;
    M2C_FIELD(&data_0213d39c, s8 *, 0x1D) = 0;
    func_02044278(0xA);
    func_0203e410();
    if (func_02042f94() != 0) {
        return;
    }
    if (M2C_FIELD(func_02044268(), s32 *, 0x10) != 0) {
        return;
    }
    func_0203c28c(M2C_FIELD(func_02044268(), s32 *, 0x200));
}

void func_0203ca88(void *arg0) {
    M2C_UNK func_0205e87c();
    M2C_UNK func_0205ea70(s32);
    u32 temp_r0_2;
    u8 temp_r0;

    if (arg0 == NULL) {
        return;
    }
    func_0205e87c();
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(func_02044268(), u8 *, 0x15);
    switch (temp_r0) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
        temp_r0_2 = M2C_FIELD(func_02044268(), u32 *, 0x1A0);
        switch (temp_r0_2) {                        /* switch 2 */
        default:                                    /* switch 2 */
            return;
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
        case 11:                                    /* switch 2 */
            func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
            return;
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        if (M2C_FIELD(func_02044268(), s32 *, 0x1A0) != 0xB) {
            return;
        }
        func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
        return;
    }
}

