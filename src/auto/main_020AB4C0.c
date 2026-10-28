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

void func_020ab664(void *arg0, s16 arg1, s32 flag, s32 arg3) {
    s32 func_0207c8ec(s16, s16);
    s32 func_0207c928(s16, s16);
    u8 func_020a8c3c(s32, s32, s32);
    void func_020ab884(void *);

    s32 x = (s32)arg1 + (s32)(s16)M2C_FIELD(arg0, s32 *, 0x14);
    s32 c0 = func_0207c8ec((s16)M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s16 *, 0x8));

    {
        s32 field18 = M2C_FIELD(arg0, s32 *, 0x18);
        if (field18 < x) {
            s32 saved = func_0207c8ec((s16)field18, M2C_FIELD(arg0, s16 *, 0x8));
            s32 sec = func_0207c8ec((s16)(x - (s32)arg1), M2C_FIELD(arg0, s16 *, 0x8));
            if (sec < saved) {
                x = field18;
            }
        }
    }

    if (flag == 0) {
        u8 inrange = func_020a8c3c(x, M2C_FIELD(arg0, s32 *, 0x1c), M2C_FIELD(arg0, s32 *, 0x18));
        if (inrange == 0) {
            x = (s32)(s16)M2C_FIELD(arg0, s32 *, 0x14);
        }
    }

    {
        s32 field18 = M2C_FIELD(arg0, s32 *, 0x18);
        s32 tmp = func_0207c928((s16)field18, M2C_FIELD(arg0, s16 *, 0x8));
        if (tmp != (M2C_FIELD(arg0, s16 *, 0x8) - 1)) {
            if (x < 0) {
                s32 nx = x + field18 + 1;
                s32 t1 = func_0207c8ec((s16)field18, M2C_FIELD(arg0, s16 *, 0x8));
                s32 t2 = func_0207c8ec((s16)nx, M2C_FIELD(arg0, s16 *, 0x8));
                if (t2 != t1) {
                    x = field18;
                } else {
                    x = nx;
                }
            }
        }
    }

    {
        s32 field18 = M2C_FIELD(arg0, s32 *, 0x18);
        if (x > field18) {
            x = 0;
        }
        M2C_FIELD(arg0, s32 *, 0x14) = x;
    }

    if (M2C_FIELD(arg0, u8 *, 0x24) != 0) {
        s32 field18 = M2C_FIELD(arg0, s32 *, 0x18);
        s32 f14 = M2C_FIELD(arg0, s32 *, 0x14);
        s32 f1c;
        while (f14 > field18) {
            f1c = M2C_FIELD(arg0, s32 *, 0x1c);
            f14 = f14 - (field18 - f1c + 1);
            M2C_FIELD(arg0, s32 *, 0x14) = f14;
        }
        f1c = M2C_FIELD(arg0, s32 *, 0x1c);
        if (f14 < f1c) {
            while (f14 < f1c) {
                f1c = M2C_FIELD(arg0, s32 *, 0x1c);
                f14 = f14 + (field18 - f1c + 1);
                M2C_FIELD(arg0, s32 *, 0x14) = f14;
            }
        }
    } else {
        s32 f14 = M2C_FIELD(arg0, s32 *, 0x14);
        s32 field18 = M2C_FIELD(arg0, s32 *, 0x18);
        if (f14 <= field18) {
            s32 f1c = M2C_FIELD(arg0, s32 *, 0x1c);
            if (f14 < f1c) {
                f14 = f1c;
            }
            M2C_FIELD(arg0, s32 *, 0x14) = f14;
        }
    }

    if (c0 != func_0207c8ec((s16)M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s16 *, 0x8))) {
        M2C_FIELD(arg0, u8 *, 0x4) = (u8)arg3;
    }
    func_020ab884(arg0);
}

