/* 28 functions from 0x02058CA4 to 0x02059BBC (main), found by ds-decomp. */
#include "common.h"

void func_02058df4(s8 *arg0, s32 arg1) {
    extern M2C_UNK data_020ff43c;
    s32 i;
    s8 *p;
    p = M2C_FIELD(&data_020ff43c, s8 **, 8);
    for (i = 0; i < arg1; i++) {
        arg0[i] ^= *p;
        if (*++p == 0) p = M2C_FIELD(&data_020ff43c, s8 **, 8);
    }
}

M2C_UNK *func_02058f10(void *arg0, M2C_UNK *arg1) {
    M2C_UNK *func_02058e3c();
    extern M2C_UNK data_020ff4a8;
    M2C_UNK *var_r0;

    var_r0 = func_02058e3c();
    if (var_r0 == NULL) {
        var_r0 = &data_020ff4a8;
    }
    return var_r0;
}

void func_02058f28(void) {
    M2C_UNK func_02049534();
    func_02049534();
}

s8 *func_02058f34(s8 *arg0, s32 arg1) {
    s32 length = arg1 - 6;
    s8 *p = arg0;
    while (p - arg0 < length) {
        if (p[0] == 0x5c && p[1] == 'f' && p[2] == 'i' && p[3] == 'n' && p[4] == 'a' && p[5] == 'l' && p[6] == 0x5c) return p;
        p++;
    }
    return NULL;
}

s32 func_02058f9c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_02048688(s32);
    s32 *func_02048690();
    extern M2C_UNK data_0213dce0;
    s32 i;
    s32 *p;
    if (M2C_FIELD(&data_0213dce0, s32 *, 4) == 0) return -1;
    for (i = 0; i < func_02048688(M2C_FIELD(&data_0213dce0, s32 *, 4)); i++) {
        p = func_02048690(M2C_FIELD(&data_0213dce0, s32 *, 4), i);
        if (p[0] == arg0 && p[1] == arg1 && p[2] == arg2) return i;
    }
    return -1;
}

void func_02059020(void *arg0) {
    s32 func_0206ad38(M2C_UNK);
    s32 *func_02048690(s32, s32);
    M2C_UNK func_02059448(s32, s32, s32, s32, s32);
    extern M2C_UNK data_020ff4b0;
    extern M2C_UNK data_020ff4b8;
    extern M2C_UNK data_020ff4bc;
    extern M2C_UNK data_0213dce0;
    s32 var_r1;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    temp_r5 = func_0206ad38(func_02058f10(arg0, &data_020ff4b0));
    temp_r4 = func_0206ad38(func_02058f10(arg0, &data_020ff4b8));
    temp_r6 = func_02058f10(arg0, &data_020ff4bc);
    temp_r0 = func_02058f9c(0, temp_r4, 0);
    if (temp_r0 == -1) {
        return;
    }
    M2C_FIELD(func_02048690(M2C_FIELD(&data_0213dce0, s32 *, 4), temp_r0), s32 *, 8) = temp_r5;
    if (temp_r5 > 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    func_02059448(temp_r0, var_r1, 0, temp_r6, 0);
}

void func_020590d0(void *arg0) {
    s32 func_0206ad38(M2C_UNK);
    s32 *func_02048690(s32, s32);
    M2C_UNK func_02059448(s32, s32, s32, s32, s32);
    extern M2C_UNK data_020ff4c4;
    extern M2C_UNK data_020ff4b8;
    extern M2C_UNK data_0213dce0;
    s32 var_r1;
    s32 temp_r0;
    s32 temp_r4;

    temp_r4 = func_0206ad38(func_02058f10(arg0, &data_020ff4c4));
    temp_r0 = func_02058f9c(3, func_0206ad38(func_02058f10(arg0, &data_020ff4b8)), 0);
    if (temp_r0 == -1) {
        return;
    }
    M2C_FIELD(func_02048690(M2C_FIELD(&data_0213dce0, s32 *, 4), temp_r0), s32 *, 8) = temp_r4;
    if (temp_r4 > 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    func_02059448(temp_r0, var_r1, 0, 0, 0);
}

void func_02059240(void *arg0) {
    s32 func_0206ad38(M2C_UNK);
    M2C_UNK func_02059448(s32, s32, s32, s32, s32);
    extern M2C_UNK data_020ff4ec;
    extern M2C_UNK data_020ff4d4;
    extern M2C_UNK data_020ff4b8;
    extern M2C_UNK data_020ff4d8;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r5;
    s32 temp_r6;

    temp_r6 = func_0206ad38(func_02058f10(arg0, &data_020ff4ec));
    temp_r5 = func_0206ad38(func_02058f10(arg0, &data_020ff4d4));
    temp_r4 = func_0206ad38(func_02058f10(arg0, &data_020ff4b8));
    temp_r4_2 = func_0206ad38(func_02058f10(arg0, &data_020ff4d8));
    temp_r0 = func_02058f9c(2, temp_r4, temp_r5);
    if (temp_r0 == -1) {
        return;
    }
    func_02059448(temp_r0, temp_r6, temp_r4_2, 0, 0);
}

s32 func_020593c0(s8 *arg0, s32 arg1) {
 void func_020592d8(s8 *, s32);
 extern M2C_UNK data_020ff43c, data_020ff488;
 s8 *end;
 s32 original;
 s32 length;
 original = arg1;
 end = func_02058f34(arg0, arg1);
 while (arg1 > 0 && end != NULL) {
 length = end - arg0;
 M2C_FIELD(&data_020ff43c, M2C_UNK **, 8) = &data_020ff488;
 func_02058df4(arg0, length);
 func_020592d8(arg0, length);
 arg1 -= length + 7;
 arg0 = end + 7;
 if (arg1 > 0) end = func_02058f34(arg0, arg1);
 }
 return original - arg1;
}

s32 func_02059640(void *arg0, s32 arg1) {
    s32 *func_02048690(s32, s32);
    extern M2C_UNK data_0213dce0;
    void *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = M2C_FIELD(&data_0213dce0, void **, 0x28);
    }
    if (var_r0 == NULL) {
        return arg1;
    }
    return *func_02048690(M2C_FIELD(var_r0, s32 *, 0x20), arg1);
}

s32 func_02059670(void *arg0, s32 arg1) {
 s32 *func_02048690(s32, s32);
 extern M2C_UNK data_0213dce0;
 void *var_r0;
 var_r0 = arg0;
 if (var_r0 == NULL) var_r0 = M2C_FIELD(&data_0213dce0, void **, 0x28);
 if (var_r0 == NULL) return arg1;
 return *func_02048690(M2C_FIELD(var_r0, s32 *, 0x1c), arg1);
}

M2C_UNK func_020596a0(void *arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
 s32 *func_02058658(s32, void *, s32, M2C_UNK *);
 extern M2C_UNK data_0213dce0;
 s32 *result;
 void *obj = arg0;
 if (obj == NULL) obj = M2C_FIELD(&data_0213dce0, void **, 0x28);
 if (obj == NULL) result = &arg3;
 else {
 result = ((s32 *(*)(s32, void *, M2C_UNK *))arg2)(M2C_FIELD(obj, s32 *, 0xc), arg1, &arg3);
 if (result == NULL) result = func_02058658(M2C_FIELD(obj, s32 *, 0xc), arg1, 0, &arg3);
 }
 return *result;
}

s32 func_02059778(void *arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    s32 *func_02058658(s32, void *, s32, M2C_UNK *);
    extern M2C_UNK data_0213dce0;
    s32 result;
    void *obj = arg0;
    if (obj == NULL) obj = M2C_FIELD(&data_0213dce0, void **, 0x28);
    if (obj == NULL) return arg3;
    result = ((s32 (*)(s32, void *, M2C_UNK))arg2)(M2C_FIELD(obj, s32 *, 0xc), arg1, arg3);
    if (result != 0) return result;
    return (s32)func_02058658(M2C_FIELD(obj, s32 *, 0xc), arg1, 2, (M2C_UNK *)arg3);
}

void func_020597d4(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_020596a0(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp4[64];
    func_020675e4(sp4, &data_020ff524, arg1, func_02059640(arg0, arg4));
    func_020596a0(arg0, sp4, arg2, arg3, arg4);
}

void func_02059830(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s64 arg4) {
    s64 func_02059708(void *, void *, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp8[64];
    func_020675e4(sp8, &data_020ff524, arg1, func_02059640(arg0, (s32)(arg4 >> 32)));
    func_02059708(arg0, sp8, arg2, arg3, (s32)arg4, (s32)(arg4 >> 32));
}

void func_02059890(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02059778(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp4[64];
    func_020675e4(sp4, &data_020ff524, arg1, func_02059640(arg0, arg4));
    func_02059778(arg0, sp4, arg2, arg3, arg4);
}

void func_020598ec(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_020596a0(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff52c;
    char sp4[64];
    func_020675e4(sp4, &data_020ff52c, arg1, func_02059670(arg0, arg4));
    func_020596a0(arg0, sp4, arg2, arg3, arg4);
}

void func_020599a8(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02059778(void *, void *, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff52c;
    char sp4[64];
    func_020675e4(sp4, &data_020ff52c, arg1, func_02059670(arg0, arg4));
    func_02059778(arg0, sp4, arg2, arg3, arg4);
}

s32 func_02059a04(u8 *arg0) {
    s32 i;
    s32 parity;
    u8 first = arg0[0];
    parity = 0;
    for (i = 1; i < 0x20; i++) {
        u8 prev = arg0[i - 1];
        parity = (first & 1) ^ (parity ^ ((i ^ prev) & 1)) ^ ((u32)first < 0x4F) ^ (prev < first);
        if (parity == 0 && (arg0[i] & 1) == 1) return 0;
    }
    return 1;
}

