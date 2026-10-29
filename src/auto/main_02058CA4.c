/* 28 functions from 0x02058CA4 to 0x02059BBC (main), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
s32 func_02058ca4(void){
extern M2C_UNK data_020ff43c,data_0213dce0;
void *func_020377a8(void *,s32);s32 func_020497cc(s32,void *,s32,s32);
void func_02058c14(void);s32 func_020593c0(s8 *,s32);void func_020651c4(void *,void *,s32);
s32 n,used,cap;void *h,*g;
if(M2C_FIELD(&data_020ff43c,s32 *,0)==-1)return 0;
if(M2C_FIELD(&data_0213dce0,s32 *,16)!=5)return 0;
if(func_02058f28(M2C_FIELD(&data_020ff43c,s32 *,0)))do{g=&data_0213dce0;h=&data_020ff43c;
if(M2C_FIELD(g,s32 *,44)-M2C_FIELD(g,s32 *,0)<128){
cap=M2C_FIELD(g,s32 *,44);if(cap<256)M2C_FIELD(g,s32 *,44)=256;else M2C_FIELD(g,s32 *,44)=cap*2;
M2C_FIELD(g,void **,12)=func_020377a8(M2C_FIELD(g,void **,12),M2C_FIELD(g,s32 *,44)+1);
if(!M2C_FIELD(g,void **,12))return 0;
}
used=M2C_FIELD(g,s32 *,0);
n=func_020497cc(M2C_FIELD(h,s32 *,0),M2C_FIELD(g,u8 **,12)+used,M2C_FIELD(g,s32 *,44)-used,0);
if(n<=0){func_02058c14();return 0;}
M2C_FIELD(g,s32 *,0)+=n;
M2C_FIELD(g,u8 **,12)[M2C_FIELD(g,s32 *,0)]=0;
used=func_020593c0(M2C_FIELD(g,s8 **,12),M2C_FIELD(g,s32 *,0));
if(used==M2C_FIELD(g,s32 *,0))M2C_FIELD(g,s32 *,0)=0;
else{func_020651c4(M2C_FIELD(g,void **,12),M2C_FIELD(g,u8 **,12)+used,M2C_FIELD(g,s32 *,0)-used);M2C_FIELD(g,s32 *,0)-=used;}
}while(func_02058f28(M2C_FIELD(h,s32 *,0)));
if(M2C_FIELD(&data_020ff43c,s32 *,0)==-1)return 0;else return 1;
}
#pragma opt_common_subs reset
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

M2C_UNK *func_02058e3c(void *arg0, s8 *arg1) {
    s8 *func_02068d68(s8 *, s8 *);
    s8 *func_02068fdc(s8 *, s8 *);
    s32 func_02068c34(s8 *);
    extern const u8 data_020eab2f[];
    extern s8 data_020ff4ac[];
    extern M2C_UNK data_0213dce0;
    extern u8 data_0213dd10[];
    s8 sp0[0x100];
    u32 count;
    s8 *dst;
    const u8 *src;
    s8 *str;
    s8 *base;
    s8 *p;
    s32 n;
    M2C_UNK *g;

    src = data_020eab2f;
    dst = sp0;
    count = 0x80;
    do { u8 a = src[0]; u8 b = src[1]; src += 2; dst[0] = a; dst[1] = b; dst += 2; count -= 1; } while (count != 0);
    g = &data_0213dce0;
    M2C_FIELD(g, s32 *, 0x24) ^= 1;
    func_02068d68(sp0, arg1);
    func_02068d68(sp0, data_020ff4ac);
    p = func_02068fdc((s8 *)arg0, sp0);
    if (p == 0) return 0;
    n = func_02068c34(sp0);
    str = p + n;
    base = (s8 *)data_0213dd10 + (M2C_FIELD(&data_0213dce0, s32 *, 0x24) << 8);
    dst = base;
    while (*str != 0 && *str != 0x5c) *dst++ = *str++;
    *dst = 0;
    return (M2C_UNK *)base;
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

s32 func_02058f28(s32 a) {
    s32 func_02049534(s32);
    return func_02049534(a);
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

void func_0205915c(void *arg0) {
    s32 func_0206ad38(M2C_UNK);
    s8 *func_02068fdc(s8 *, s8 *);
    s32 func_02058f9c(s32, s32, s32);
    M2C_UNK func_02059448(s32, s32, s32, s32, s32);
    M2C_UNK *func_02058f10(void *, M2C_UNK *);
    extern M2C_UNK data_020ff4cc;
    extern M2C_UNK data_020ff4b8;
    extern M2C_UNK data_020ff4d4;
    extern M2C_UNK data_020ff4d8;
    extern M2C_UNK data_020ff4dc;
    extern M2C_UNK data_020ff4e4;
    extern M2C_UNK data_020ff4a8;
    s32 temp_r7;
    s32 temp_r6;
    s32 temp_r5;
    s32 temp_r8;
    s8 *temp_r0;
    s8 *temp_r3;

    temp_r7 = func_0206ad38(func_02058f10(arg0, &data_020ff4cc));
    temp_r6 = func_0206ad38(func_02058f10(arg0, &data_020ff4b8));
    temp_r5 = func_0206ad38(func_02058f10(arg0, &data_020ff4d4));
    temp_r8 = func_0206ad38(func_02058f10(arg0, &data_020ff4d8));
    temp_r5 = func_02058f9c(1, temp_r6, temp_r5);
    if (temp_r5 == -1) {
        return;
    }
    temp_r6 = func_0206ad38(func_02058f10(arg0, &data_020ff4dc));
    temp_r0 = func_02068fdc((s8 *)arg0, (s8 *)&data_020ff4e4);
    if (temp_r0 == 0) {
        temp_r3 = (s8 *)&data_020ff4a8;
        temp_r6 = 0;
    } else {
        temp_r3 = temp_r0 + 6;
    }
    func_02059448(temp_r5, temp_r7, temp_r8, (s32)temp_r3, temp_r6);
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

void func_020592d8(s8 *arg0, s32 arg1) {
    s32 func_02068eac(void *, void *, s32);
    void func_02059020();
    void func_020590d0();
    void func_0205915c();
    void func_02059240();
    extern u8 data_020ff4f4[];
    extern u8 data_020ff500[];
    extern u8 data_020ff50c[];
    extern u8 data_020ff518[];

    arg0[arg1] = 0;
    if (func_02068eac(arg0, data_020ff4f4, 8) == 0) { func_02059020(arg0, arg1); return; }
    if (func_02068eac(arg0, data_020ff500, 9) == 0) { func_020590d0(arg0, arg1); return; }
    if (func_02068eac(arg0, data_020ff500, 9) == 0) { func_020590d0(arg0, arg1); return; }
    if (func_02068eac(arg0, data_020ff50c, 8) == 0) { func_0205915c(arg0, arg1); return; }
    if (func_02068eac(arg0, data_020ff518, 8) != 0) return;
    func_02059240(arg0, arg1);
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

s32 func_02059448(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_02048688(s32);
    s32 *func_02048690(s32, s32);
    void func_0204890c(s32 *, s32);
    extern M2C_UNK data_0213dce0;
    s32 *p;
    s32 *cb;

    if (arg0 < 0) {
    }
    else if (arg0 < func_02048688(M2C_FIELD(&data_0213dce0, s32 *, 4))) {
        p = func_02048690(M2C_FIELD(&data_0213dce0, s32 *, 4), arg0);
        cb = M2C_FIELD(p, s32 *, 0x18);
        if (cb != NULL) {
            s32 type = M2C_FIELD(p, s32 *, 0);
            switch (type) {
                case 0:
                    ((void (*)(s32, s32, s32, s32, s32))cb)(
                        M2C_FIELD(p, s32 *, 4), M2C_FIELD(p, s32 *, 0x8),
                        arg1, arg3, M2C_FIELD(p, s32 *, 0x14));
                    break;
                case 1:
                    ((void (*)(s32, s32, s32, s32, s32, s32, s32, s32, s32))cb)(
                        M2C_FIELD(p, s32 *, 4), M2C_FIELD(p, s32 *, 0x8),
                        M2C_FIELD(p, s32 *, 0xC), M2C_FIELD(p, s32 *, 0x10),
                        arg1, arg2, arg3, arg4, M2C_FIELD(p, s32 *, 0x14));
                    break;
                case 2:
                    ((void (*)(s32, s32, s32, s32, s32, s32, s32))cb)(
                        M2C_FIELD(p, s32 *, 4), M2C_FIELD(p, s32 *, 0x8),
                        M2C_FIELD(p, s32 *, 0xC), M2C_FIELD(p, s32 *, 0x10),
                        arg1, arg2, M2C_FIELD(p, s32 *, 0x14));
                    break;
                case 3:
                    ((void (*)(s32, s32, s32, s32))cb)(
                        M2C_FIELD(p, s32 *, 4), M2C_FIELD(p, s32 *, 0x8),
                        arg1, M2C_FIELD(p, s32 *, 0x14));
                    break;
                default:
                    break;
            }
        }
        func_0204890c(M2C_FIELD(&data_0213dce0, s32 *, 4), arg0);
    }
}

void func_0205954c(void) {
    s32 func_02048688(s32);
    void func_0204861c(s32);
    void func_02058df4(s8 *, s32);
    M2C_UNK func_02059448(s32, s32, s32, s32, s32);
    extern M2C_UNK data_0213dce0;
    extern const u8 data_020ea9ac[];
    extern M2C_UNK data_020ff498;
    extern M2C_UNK data_020ff43c;
    u8 buf1[16];
    u8 buf0[16];
    s32 i;

    if (M2C_FIELD(&data_0213dce0, s32 *, 4) == 0) return;
    i = func_02048688(M2C_FIELD(&data_0213dce0, s32 *, 4)) - 1;
    if (i >= 0) {
        {
            const u8 *src = data_020ea9ac;
            u8 *dst = buf0;
            u32 count = 8;
            do { u8 a = src[0]; u8 b = src[1]; src += 2; dst[0] = a; dst[1] = b; dst += 2; count -= 1; } while (count != 0);
        }
        do {
            {
                const u8 *src = buf0;
                u8 *dst = buf1;
                u32 count = 8;
                do { u8 a = src[0]; u8 b = src[1]; src += 2; dst[0] = a; dst[1] = b; dst += 2; count -= 1; } while (count != 0);
            }
            M2C_FIELD(&data_020ff43c, M2C_UNK **, 8) = &data_020ff498;
            func_02058df4((s8 *)buf1, 15);
            func_02059448(i, 0, 0, (s32)buf1, 0);
            i -= 1;
        } while (i >= 0);
    }
    func_0204861c(M2C_FIELD(&data_0213dce0, s32 *, 4));
    M2C_FIELD(&data_0213dce0, s32 *, 4) = 0;
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

s64 func_02059708(void *arg0, void *arg1, M2C_UNK arg2, s64 arg3, s32 arg4) {
 s32 *func_02058658(s32, void *, s32, M2C_UNK *);
 extern M2C_UNK data_0213dce0;
 s32 *result;
 void *obj = arg0;
 if (obj == NULL) obj = M2C_FIELD(&data_0213dce0, void **, 0x28);
 if (obj == NULL) result = (s32 *)&arg3;
 else {
 result = ((s32 *(*)(s32, void *, M2C_UNK *))arg2)(M2C_FIELD(obj, s32 *, 0xc), arg1, (s32 *)&arg3);
 if (result == NULL) result = func_02058658(M2C_FIELD(obj, s32 *, 0xc), arg1, 1, (s32 *)&arg3);
 }
 return *(s64 *)result;
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

void func_02059830(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s64 arg3, s32 arg4) {
    s64 func_02059708(void *, void *, M2C_UNK, s64, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff524;
    char sp8[64];
    func_020675e4(sp8, &data_020ff524, arg1, func_02059640(arg0, arg4));
    func_02059708(arg0, sp8, arg2, arg3, arg4);
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

void func_02059948(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s64 arg3, s32 arg4) {
    s64 func_02059708(void *, void *, M2C_UNK, s64, s32);
    M2C_UNK func_020675e4(void *, M2C_UNK *, M2C_UNK, s32);
    extern M2C_UNK data_020ff52c;
    char sp8[64];
    func_020675e4(sp8, &data_020ff52c, arg1, func_02059670(arg0, arg4));
    func_02059708(arg0, sp8, arg2, arg3, arg4);
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

u8 *func_02059aa0(u8 *arg0) {
 M2C_UNK func_020640a8();
 s32 func_02067774(void);
 void func_02049208(void);
 void func_020677a8(void);
 extern M2C_UNK data_020ff534;
 extern M2C_UNK data_020ff56c;
 extern M2C_UNK data_020ff574;
 s32 i; u32 parity; u8 *p; u32 a,b;
 if (arg0 == NULL) func_020640a8(&data_020ff56c, &data_020ff574, &data_020ff534, 0x2b);
 func_02049208();
 func_020677a8();
 arg0[0] = func_02067774() % 93 + 33;
 parity = 0;
 i = 1; do {
  p = arg0 + i;
  a = p[-1]; b = arg0[0];
  { u32 x,y; if(a<b)x=1;else x=0; if(b<79)y=1;else y=0; parity=(b&1)^(parity^((i^a)&1)); parity^=y; parity^=x; }
  p[0] = func_02067774() % 93 + 33;
  if ((parity && !(p[0]&1)) || (!parity && (p[0]&1)==1)) p[0]++;
  i++; } while(i<0x20);
 return arg0;
}

