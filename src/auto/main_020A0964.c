/* 16 functions from 0x020A0964 to 0x020A1944 (main), found by ds-decomp. */
#include "common.h"

void func_020a0964(s32 a, s32 b, u16 *out) {
    (void)a; (void)b; (void)out;
}

M2C_UNK func_020a0d18(void) {
    M2C_UNK func_020a004c(M2C_UNK, M2C_UNK);
    M2C_UNK func_01ffb554(M2C_UNK);
    M2C_UNK func_020a0560(void);
    M2C_UNK func_020a086c(M2C_UNK, M2C_UNK);
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020a0360(void);
    M2C_UNK func_020a061c(void);
    M2C_UNK func_020a05d8(M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    extern s32 data_0211fb5c;
    extern u8 data_ov000_021b5c09[];

    u8 *base;
    s8 *ctx;
    s16 selY;
    u16 selXu;
    s16 selX;
    u8 *row;
    s8 terrain;
    u8 *unit;
    u8 kind;
    s8 idx;
    s8 *pe;
    s8 f42;
    s8 f36;
    s32 manX;
    s32 manY;
    s16 sp_x;
    s16 sp_y;
    u16 off;
    u8 byte;

    base = (u8 *)*gCurrentMap;
    if (*(u16 *)(base + 0x52b4) != 2) return 0;

    ctx = (s8 *)data_0211fb5c;
    selY = *(s16 *)(base + 0x52c2);
    if (ctx[0x34] == (s8)selY && ctx[0x35] == (s8)*(s16 *)(base + 0x52c4)) return 0;

    selXu = *(u16 *)(base + 0x52c4);
    func_020a004c((M2C_UNK)selY, (M2C_UNK)selXu);

    base = (u8 *)*gCurrentMap;
    selX = *(s16 *)(base + 0x52c4);
    selY = *(s16 *)(base + 0x52c2);
    row = *(u8 **)(base + selX * 4 + 0x52e8);
    terrain = (s8)row[selY];
    if (terrain > 110) {
        unit = *(u8 **)(base + 0x52d0);
        kind = unit[0] & 0x3F;
        if (data_ov000_021b5c09[kind * 112] > 1) return 0;
    }

    ctx = (s8 *)data_0211fb5c;
    idx = ctx[0x5b];
    pe = ctx + idx;
    f42 = pe[0x42];
    f36 = pe[0x36];
    manX = f42 - selX;
    if (manX < 0) manX = -manX;
    manY = f36 - selY;
    if (manY < 0) manY = -manY;

    sp_x = selX;
    sp_y = selY;

    if (manX + manY == 1) {
        off = *(u16 *)(base + (f42 << 1) + 0x3758);
        byte = base[f36 + off];
        if (byte == 0) return 0;

        func_01ffb554(base + 0x2338);
        func_020a0560();
        if (func_020a086c(&sp_y, &sp_x)) {
            func_01ffc4b8(sp_y, sp_x, base + 0x5388);
            func_020a0360();
            if (!func_020a061c()) func_020a05d8(sp_y, sp_x);
        } else {
            func_01ffb554(base + 0x1e30);
            sp_y = selY;
            sp_x = selX;
            if (func_020a086c(&sp_y, &sp_x)) {
                func_01ffb554(base + 0x2338);
                func_020a05d8(sp_y, sp_x);
            } else {
                func_01ffb554(base + 0x1e30);
            }
        }
        func_01ffb554(base + 0x1e30);
    } else {
        func_01ffb554(base + 0x1e30);
    }
    return 0;
}

s32 func_020a11fc(s32 arg0) {
    extern s32 data_0211fb5c;
    s8 temp_r0;
    s8 temp_r0_2;
    s8 temp_r1;
    s8 temp_r1_2;
    void *temp_r2;
    void *temp_r3;

    if (arg0 == 0) {
        return 0;
    }
    temp_r3 = data_0211fb5c + arg0;
    temp_r2 = data_0211fb5c + (arg0 - 1);
    temp_r1 = M2C_FIELD(temp_r3, s8 *, 0x36);
    temp_r0 = M2C_FIELD(temp_r2, s8 *, 0x36);
    if ((s32) temp_r0 < (s32) temp_r1) {
        return 3;
    }
    if ((s32) temp_r0 > (s32) temp_r1) {
        return 1;
    }
    temp_r1_2 = M2C_FIELD(temp_r3, s8 *, 0x42);
    temp_r0_2 = M2C_FIELD(temp_r2, s8 *, 0x42);
    if ((s32) temp_r0_2 < (s32) temp_r1_2) {
        return 4;
    }
    if ((s32) temp_r0_2 > (s32) temp_r1_2) {
        return 2;
    }
    return 0;
}

s32 func_020a125c(s32 arg0) {
    extern s32 data_0211fb5c;
    void *temp_r2;
    void *temp_r3;
    s8 a, b;
    temp_r2 = data_0211fb5c;
    if (arg0 == M2C_FIELD(temp_r2, s8 *, 0x5B)) return 0;
    temp_r3 = (s32)temp_r2 + (arg0 + 1);
    temp_r2 = (s32)temp_r2 + arg0;
    b = M2C_FIELD(temp_r3, s8 *, 0x36);
    a = M2C_FIELD(temp_r2, s8 *, 0x36);
    if (a < b) return 1;
    if (a > b) return 3;
    b = M2C_FIELD(temp_r3, s8 *, 0x42);
    a = M2C_FIELD(temp_r2, s8 *, 0x42);
    if (a < b) return 2;
    if (a > b) return 4;
    return 0;
}

void func_020a12c0(void *arg0) {
    M2C_UNK func_02077480();
    func_02077480();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void func_020a12d8(void) {
    M2C_UNK func_020774b0();
    M2C_UNK func_020a0d18();
    M2C_UNK func_020a1300(M2C_UNK, M2C_UNK);
    func_020774b0();
    func_020a0d18();
    func_020a1300(0, 0);
}

void func_020a12f4(void) {
    M2C_UNK func_0207749c();
    func_0207749c();
}

s32 func_020a1300(s32 arg0, s32 arg1) {
    M2C_UNK func_0207d130(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    s32 func_020a125c(s32);
    s32 func_020a11fc(s32);
    extern s32 *gCurrentMap;
    extern s32 data_0211fb5c;
    extern u16 data_0211fb88[];
    extern M2C_UNK data_027e0064;

    s8 *ctx;
    void *map;
    void *selected;
    s32 pl;
    s8 i;
    s32 dir;
    s32 s;
    u16 val;
    s8 *pe;
    s32 vec[3];

    ctx = (s8 *)data_0211fb5c;
    if (ctx[0x5b] == 0) {
        return 0;
    }
    map = (void *)*gCurrentMap;
    selected = *(void **)((u8 *)map + 0x52d0);
    if (selected == NULL) {
        pl = 0;
    } else {
        pl = (((s8 *)selected - ((s8 *)map + 0x59a4)) / 14) >> 6;
        pl = pl + 1;
    }
    if (*(u16 *)((u8 *)map + 0x52a4) != pl) {
        return 0;
    }
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    *(volatile s32 *)0x04000444 = 0;
    ctx = (s8 *)data_0211fb5c;
    i = ctx[0x5b];
    if (i < 0) {
        *(volatile s32 *)0x04000448 = 1;
        return 0;
    }
    for (; i >= 0; i--) {
        dir = func_020a125c((u8)i);
        s = func_020a11fc((u8)i);
        val = data_0211fb88[dir * 5 + s];
        pe = ctx + (s32)i;
        vec[0] = (s32)pe[0x36] << 4;
        vec[1] = (s32)pe[0x42] << 4;
        vec[2] = 0x851;
        switch ((s32)val - 0xC0) {
        case 0:
            vec[1] += 4;
            break;
        case 2:
            vec[0] -= 4;
            break;
        case 4:
            vec[1] -= 4;
            break;
        case 6:
            vec[0] += 4;
            break;
        default:
            break;
        }
        vec[0] = vec[0] * 0x30;
        vec[1] = vec[1] * 0x30;
        func_0207d130(&data_027e0064, vec, 0x22F20, 0x1460, 0x30000, 0, 0, 0x80, 0x80, 0x1800, val);
    }
    *(volatile s32 *)0x04000448 = 1;
    return 0;
}

void func_020a1508(void) {

}

void func_020a150c(void *arg0) {
    M2C_UNK func_0207d130(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    extern M2C_UNK data_027e0064;
    s32 vec[3];
    s32 temp = M2C_FIELD(arg0, s16 *, 0x6C) * 2;
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    vec[0] = (M2C_FIELD(arg0, s32 *, 0x34) << 4) * 0x30;
    vec[1] = (M2C_FIELD(arg0, s32 *, 0x38) << 4) * 0x30;
    vec[2] = 0x891;
    func_0207d130(&data_027e0064, vec, 0x22F20, 0x1480, 0x30000, 0, 0, 0x80, 0x80, 0x1800, temp + 0x100);
}

void func_020a15b4(s32 arg0, s32 arg1, s16 arg2) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_0211fb60;
    void *temp_r0;
    temp_r0 = func_01ffa3dc(&data_0211fb60, 7);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg2;
}

void func_020a15e4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_0211fb60;
    func_01ffa9e4(&data_0211fb60);
}

#pragma opt_strength_reduction off
void func_020a15f8(void) {
    extern s32 *gCurrentMap;
    s32 x, y;
    u8 *base;
    u8 *p;
    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            base = base + x + M2C_FIELD(base + y * 2, u16 *, 0x3758);
            p = base;
            if ((p[0x1420] & 0x1F) == 0x1C) p[0x539C] = 0xE3;
            else p[0x539C] = 0;
            base = (u8 *)*gCurrentMap;
        }
    }
}
#pragma opt_strength_reduction reset
void func_020a16a8(u8 *arg0) {
    extern s32 *gCurrentMap;
    s32 var_ip;
    u8 *var_lr;
    u8 *var_r0;
    u8 temp_r1;

    var_r0 = arg0;
    var_lr = *gCurrentMap + 0x539C;
    if (*var_r0 == 0xFF) {
        return;
    }
    do {
        temp_r1 = *var_r0;
        if (temp_r1 & 0x80) {
            var_r0 += 1;
            *var_lr = temp_r1;
            var_lr += 1;
        } else {
            var_ip = 0;
            if ((s32) temp_r1 > 0) {
                do {
                    *var_lr = 0;
                    var_lr += 1;
                    var_ip += 1;
                } while (var_ip < (s32) *var_r0);
            }
            var_r0 += 1;
        }
    } while (*var_r0 != 0xFF);
}

void func_020a1720(u8 *dst) {
extern s32 *gCurrentMap;
u8 count=0; s32 i=0; s32 n; u8 *p; void *base;
base=(void *)*gCurrentMap;
n=M2C_FIELD(base,u16 *,0x5144)*M2C_FIELD(base,u16 *,0x5146);
p=(u8 *)base+0x539c;
for(;i<n;i++,p++) {
if(*p) {
if(count){*dst++=count;count=0;}
*dst++=*p;
}else {
count++;
if(count==127){*dst++=count;count=0;}
}
}
if(count)*dst++=count;
*dst=255;
}

#pragma opt_strength_reduction off
void func_020a17c0(s32 arg0, s32 arg1) {
    M2C_UNK func_01ffb554(M2C_UNK);
    M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 x, y;
    u8 *base = (u8 *)*gCurrentMap;
    func_01ffb554(base + 0x1e30);
    func_01ffada0(arg0, arg1, 0x1d, 0x6e, 0);
    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        base = (u8 *)*gCurrentMap;
        for (x = 0; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            if (M2C_FIELD(M2C_FIELD(base + (y << 2), s8 **, 0x52e8), s8 *, x) < 0) {
                base = (u8 *)*gCurrentMap;
                continue;
            }
            {
                u16 off = M2C_FIELD(base + (y << 1), u16 *, 0x3758);
                u8 cell = M2C_FIELD(base + off + x, u8 *, 0x1420);
                if (((cell & 0xe0) >> 5) != 0) {
                    M2C_FIELD(base + (off + x) * 2 + 0xa00, u16 *, 0x10) = 3;
                    base = (u8 *)*gCurrentMap;
                    M2C_FIELD(base + off + x, u8 *, 0x1420) = 8;
                } else {
                    if (cell == 0x1c) {
                        M2C_FIELD(base + (off + x) * 2 + 0xa00, u16 *, 0x10) = 5;
                    } else {
                        M2C_FIELD(base + (off + x) * 2 + 0xa00, u16 *, 0x10) = 4;
                    }
                    base = (u8 *)*gCurrentMap;
                    M2C_FIELD(base + off + x, u8 *, 0x1420) = 1;
                }
                base = (u8 *)*gCurrentMap;
            }
        }
        base = (u8 *)*gCurrentMap;
    }
}
#pragma opt_strength_reduction reset
