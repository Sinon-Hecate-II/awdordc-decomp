/* 29 functions from 0x020AA93C to 0x020AB884 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } UnkAAFields;

void func_020ab4c0(void *arg0) {
    s32 func_0207c8ec(s16, s16);
    M2C_UNK func_020ab664(void *, s16, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ab884(void *);
    s16 temp_r4;
    s16 temp_r6;
    s32 temp_r0;
    s32 var_r4;

    var_r4 = 0;
    if ((s16)func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8)) > 0) {
        if (M2C_FIELD(arg0, s16 *, 6) <= (s16)func_0207c8ec((s16)M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg0, s16 *, 8))) {
            var_r4 = 1;
        }
    }
    if (!(var_r4 & 0xFF)) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16)(M2C_FIELD(arg0, s16 *, 0xC) - M2C_FIELD(arg0, s16 *, 8));
    func_020ab664(arg0, (s16)(0 - M2C_FIELD(arg0, s16 *, 8)), 0, 0);
    func_020ab884(arg0);
    temp_r0 = M2C_FIELD(arg0, u8 *, 0xA) * (s16)func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8));
    M2C_FIELD(arg0, s16 *, 0x28) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16)(0 - temp_r0);
    temp_r4 = M2C_FIELD(arg0, s16 *, 0x2A);
    temp_r6 = M2C_FIELD(arg0, s16 *, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x3E) = func_020a8ff4(arg0 + 0x30);
    M2C_FIELD(arg0, s16 *, 0x40) = temp_r4;
    M2C_FIELD(arg0, s16 *, 0x3C) = temp_r6;
    M2C_FIELD(arg0, u16 *, 0x32) = (u16)M2C_FIELD(arg0, u16 *, 0x34);
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
