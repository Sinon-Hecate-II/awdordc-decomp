/* 29 functions from 0x020AA93C to 0x020AB884 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } UnkAAFields;

void func_020aacf0(void *arg0) {
    M2C_UNK func_02088044(s32);
    s32 func_02089064();
    void func_020aaeb0(void *);
    if (func_02089064() != 0) {
        func_02088044(M2C_FIELD(arg0, s32 *, 0x64));
    }
    func_020aaeb0(arg0);
}

u32 func_020aae10(void *arg0) {
    void *func_020aa93c(u32);
    u32 idx = (u32)(M2C_FIELD(arg0, u8 *, 0x58) << 25) >> 25;
    void *ptr = func_020aa93c(idx);
    u32 value = M2C_FIELD(ptr, u8 *, 0);
    if (value == 0) {
        return M2C_FIELD(arg0, UnkAAFields *, 0x40).x;
    }
    return value;
}

u32 func_020aae44(void *arg0) {
    void *func_020aa93c(u32);
    u32 idx = (u32)(M2C_FIELD(arg0, u8 *, 0x58) << 25) >> 25;
    void *ptr = func_020aa93c(idx);
    u32 value = M2C_FIELD(ptr, u8 *, 1);
    if (value == 0) {
        u32 fallback = M2C_FIELD(arg0, u32 *, 0x40);
        return (fallback << 14) >> 23;
    }
    return value;
}

s32 func_020aae78(void *arg0) {
    void *func_020aa93c(u32);
    return M2C_FIELD(func_020aa93c((u32) (M2C_FIELD(arg0, u8 *, 0x58) << 0x19) >> 0x19), s32 *, 4);
}

s32 func_020aae94(void *arg0) {
    return M2C_FIELD(func_020aa93c((u32) (M2C_FIELD(arg0, u8 *, 0x58) << 0x19) >> 0x19), s32 *, 8);
}

void func_020aaeb0(void *arg0) {
    s8 v5a;
    u8 byte59;
    u8 nibble;
    u32 rest;
    void *p64;
    s8 t;
    u32 q;
    u32 v;
    u32 f;

    v5a = *(s8 *)((u8 *)arg0 + 0x5a);
    if (v5a < 0) {
        return;
    }
    byte59 = *(u8 *)((u8 *)arg0 + 0x59);
    nibble = byte59 & 0x0f;
    rest = *(u32 *)((u8 *)arg0 + 0x40) >> 18;
    if ((u32)(nibble + 2) != rest) {
        p64 = *(void **)((u8 *)arg0 + 0x64);
        t = *(s8 *)((u8 *)p64 + 0x0c);
        if (t != 1) {
            q = *(u32 *)p64;
            if (q == 0) {
                v = (u32)-1;
            } else {
                v = *(u16 *)((u8 *)q + 0x08);
            }
            if (v != 1) {
                if (v5a == 0) {
                    f = *(u32 *)((u8 *)arg0 + 0x40);
                    f = (f & ~0x03FC0000u) | ((u32)nibble << 18);
                    *(u32 *)((u8 *)arg0 + 0x40) = f;
                }
                goto done_block;
            }
        }
        f = *(u32 *)((u8 *)arg0 + 0x40);
        f = (f & ~0x03FC0000u) | ((u32)(nibble + 1) << 18);
        *(u32 *)((u8 *)arg0 + 0x40) = f;
        (void) f;
done_block:
        ;
    }
    v5a = *(s8 *)((u8 *)arg0 + 0x5a);
    if (v5a > 0) {
        v5a = v5a - 1;
        *(s8 *)((u8 *)arg0 + 0x5a) = v5a;
    }
    return;
}

M2C_UNK *func_020aaf74(void) {
    extern M2C_UNK data_02126b0c;
    return &data_02126b0c;
}

void func_020ab150(void *arg0, s16 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02126b28;
    extern M2C_UNK data_02126bd0;
    void *temp_r0;

    func_01ffa574(M2C_FIELD(arg0, void **, 0x60));
    temp_r0 = func_01ffa3dc(&data_02126b28, 4);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02126bd0;
    }
    M2C_FIELD(temp_r0, void **, 0x34) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x38) = arg1;
    M2C_FIELD(arg0, void **, 0x60) = temp_r0;
}

u16 func_020ab194(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x60);
    if (temp_r0 != NULL) {
        return M2C_FIELD(temp_r0, u16 *, 0x38);
    }
    return 0U;
}

void func_020ab1a8(void *arg0) {
    M2C_UNK func_01ffa574(s32);
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x60));
}

void func_020ab1b8(void) {
    M2C_UNK func_020892f0();
    func_020892f0();
}

void *func_020ab1c4(s32 arg0) {
 extern M2C_UNK data_02126b94, data_02126be4;
 void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
 void func_02089108(void *);
 void *result = func_01ffa3dc(&data_02126b94,arg0);
 if (result != NULL) {
 func_02089108(result);
 M2C_FIELD(result,M2C_UNK **,0)=&data_02126be4;
 M2C_FIELD(result,s32 *,0x64)=0;
 }
 return result;
}

void func_020ab200(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02126b94;
    func_01ffa9e4(&data_02126b94);
}

void func_020ab214(void *arg0) {
 extern u8 data_0215c3a0;
 u32 test = M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s8 *,12)==1;
 if ((u8)test) *(&data_0215c3a0+1)=1;
}

u32 func_020ab240(void) {
 extern u8 data_0215c3a0;
 extern M2C_UNK data_02126b94;
 void func_01ffa928(M2C_UNK *,void (*)(void *));
 *(&data_0215c3a0+1)=0;
 func_01ffa928(&data_02126b94,func_020ab214);
 return *(&data_0215c3a0+1);
}

void func_020ab274(void) {
    extern u8 data_0215c3a0;
    data_0215c3a0 += 1;
}

void func_020ab28c(void) {
 extern u8 data_0215c3a0;
 data_0215c3a0 -= 1;
}

u8 func_020ab2a4(void) {
    extern u8 data_0215c3a0;
    return data_0215c3a0 != 0;
}

void func_020ab2c4(void *arg0) {
    M2C_UNK func_020a8f8c(void *);
    s32 func_020a8ff4(void *);
    s16 temp_r4;
    s32 var_r0;

    temp_r4 = M2C_FIELD(arg0, s16 *, 0x2A);
    if (temp_r4 != func_020a8ff4(arg0 + 0x30)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        M2C_FIELD(arg0, s8 *, 0x54) = 4;
    }
    func_020a8f8c(arg0 + 0x30);
    func_020a8f8c(arg0 + 0x42);
    func_020a8f8c(arg0 + 0x54);
}

s16 func_020ab30c(void *arg0) {
    s16 temp_r0;
    s16 var_r0;
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_r0 = (M2C_FIELD(arg0, s16 *, 0xC) + (s16) (M2C_FIELD(arg0, s16 *, 6) * M2C_FIELD(arg0, s16 *, 8))) - 1;
    var_r0 = temp_r0;
    if (temp_r1 < (s32) temp_r0) {
        var_r0 = (s16) temp_r1;
    }
    return var_r0;
}

void func_020ab344(void *arg0, s16 arg1, s32 arg2) {
    s32 func_0207c8ec(s16, s16);
    s16 temp_r0_2;
    s16 temp_r6;
    s16 temp_r7;
    s32 temp_r0;

    M2C_FIELD(arg0, s16 *, 0xC) = arg1;
    temp_r0 = M2C_FIELD(arg0, u8 *, 0xA) * (s16)func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8));
    M2C_FIELD(arg0, s16 *, 0x28) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16)(0 - temp_r0);
    temp_r6 = M2C_FIELD(arg0, s16 *, 0x2A);
    temp_r7 = M2C_FIELD(arg0, s16 *, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x3E) = func_020a8ff4(arg0 + 0x30);
    M2C_FIELD(arg0, s16 *, 0x40) = temp_r6;
    M2C_FIELD(arg0, s16 *, 0x3C) = temp_r7;
    M2C_FIELD(arg0, u16 *, 0x32) = (u16)M2C_FIELD(arg0, u16 *, 0x34);
    if (arg2 == 1) {
        temp_r0_2 = M2C_FIELD(arg0, s16 *, 0x2A);
        M2C_FIELD(arg0, s16 *, 0x40) = temp_r0_2;
        M2C_FIELD(arg0, s16 *, 0x3E) = temp_r0_2;
    }
}

void func_020ab598(void *arg0) {
    s32 func_0207c8ec(s16, s16);
    M2C_UNK func_020ab664(void *, s16, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ab884(void *);
    s16 temp_r5_2;
    s16 temp_r6;
    s16 temp_r6_2;
    s32 temp_r0;
    s32 temp_r5;
    s32 var_r0;

    temp_r6 = M2C_FIELD(arg0, s16 *, 6);
    temp_r5 = func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8)) << 0x10;
    if ((s32) (temp_r6 + (temp_r5 >> 0x10)) < (s32) (func_0207c8ec((s16) M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg0, s16 *, 8)) + 1)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (M2C_FIELD(arg0, s16 *, 0xC) + M2C_FIELD(arg0, s16 *, 8));
    func_020ab664(arg0, M2C_FIELD(arg0, s16 *, 8), 0, 0);
    func_020ab884(arg0);
    temp_r0 = M2C_FIELD(arg0, u8 *, 0xA) * func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8));
    M2C_FIELD(arg0, s16 *, 0x28) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16) (0 - temp_r0);
    temp_r5_2 = M2C_FIELD(arg0, s16 *, 0x2A);
    temp_r6_2 = M2C_FIELD(arg0, s16 *, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x3E) = func_020a8ff4(arg0 + 0x30);
    M2C_FIELD(arg0, s16 *, 0x40) = temp_r5_2;
    M2C_FIELD(arg0, s16 *, 0x3C) = temp_r6_2;
    M2C_FIELD(arg0, u16 *, 0x32) = (u16) M2C_FIELD(arg0, u16 *, 0x34);
}

