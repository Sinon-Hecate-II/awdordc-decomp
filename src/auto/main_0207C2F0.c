/* 43 functions from 0x0207C2F0 to 0x0207D130 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 x,y,z; } Vec0207;
extern Vec0207 data_020ebdb8;

typedef struct Unk0207Color { u32 words[4]; } Unk0207Color;
Unk0207Color func_0207cbd0(s32);
typedef struct { u16 mode:3; u16 rest:13; } Mode0207;
extern Mode0207 data_02168f14;
extern Unk0207Color data_021017f4[4];
extern void **gCurrentMap;
s32 func_0207ca38(s32, s32, s32, s32, s32);

s32 func_0207c2f0(void) {
    s32 func_0207c8ec(s32, M2C_UNK);
    extern s32 data_0214bfa8;
    s32 temp_r2;
    s32 temp_r4;
    temp_r2 = (data_0214bfa8 * 4) + 2;
    temp_r4 = temp_r2 * (temp_r2 + 1);
    return data_0214bfa8 = (temp_r4 + func_0207c8ec(temp_r4 & ~0x80000000, 7)) & ~0x80000000;
}

s32 RandomIntRange(s32 arg0, s32 arg1) {
    s32 func_0207c928(s32, s32);
    s32 temp;
    if (arg0 == arg1) return arg0;
    if (arg0 > arg1) {
        temp = arg0;
        arg0 = arg1;
        arg1 = temp;
    }
    return arg0 + func_0207c928(func_0207c2f0() & 0x7fffffff, arg1 - arg0 + 1);
}

s32 func_0207c368(u8 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < arg1; i++, arg0++) {
        if (*arg0 == 0) return 1;
    }
    return 0;
}

void func_0207c39c(void *arg0) {
    M2C_UNK func_02007ef4(s32, s32, s32);
    M2C_UNK func_02008048(s32, s32, s32);
    s32 flags = M2C_FIELD(arg0, s32 *, 0x40);
    s32 src = M2C_FIELD(arg0, s32 *, 0x38);
    s32 dst = M2C_FIELD(arg0, s32 *, 0x3C);
    if (flags & 3) {
        func_02008048(src, dst, flags);
    } else {
        func_02007ef4(src, dst, flags);
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) return;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c3dc(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_01ffa8bc(void *, s32);
    void *func_0209ccb8(M2C_UNK *, M2C_UNK);
    void func_0207c39c(void *);
    void *temp_r0;

    temp_r0 = func_0209ccb8((M2C_UNK *)&func_0207c39c, 2);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x50) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    func_01ffa8bc(temp_r0, 0xFF02);
}

void func_0207c42c(void *arg0) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004bb0(s32, s32, s32);
    M2C_UNK func_02004cf0();
    M2C_UNK func_020e35cc(s32);
    func_02004b54();
    func_02004bb0(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
    func_02004cf0();
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        return;
    }
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c464(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_r0;

    temp_r0 = func_0209ccb8(&func_0207c42c, 0);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x50) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    func_01ffa8bc(temp_r0, 0xFF02);
}

void func_0207c4b4(void *arg0) {
    M2C_UNK func_02004d3c();
    M2C_UNK func_02004d70(s32, s32, s32);
    M2C_UNK func_02004ddc();
    func_02004d3c();
    func_02004d70(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
    func_02004ddc();
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        return;
    }
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c4ec(void *arg0) {
    s32 func_020033cc(void);
    M2C_UNK func_02002e3c(s32);
    extern u16 data_02101438[];
    s32 base;
    s32 count;
    s32 offset;
    s32 mode;
    count = M2C_FIELD(arg0, s32 *, 0x40);
    offset = M2C_FIELD(arg0, s32 *, 0x44);
    mode = func_020033cc();
    base = data_02101438[mode >> 4] << 12;
    if (base == 0) return;
    if (count > 0) {
        do {
            count -= 2;
            *(u16 *)(base + offset) = *M2C_FIELD(arg0, u16 **, 0x38);
            offset += 2;
        } while (count > 0);
    }
    func_02002e3c(mode);
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) return;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c55c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_0207c4ec(void *);
    void *var_r0;

    if (!(arg2 & 3) && !(arg1 & 3)) {
        var_r0 = func_0209ccb8(&func_0207c4b4, 0);
    } else {
        var_r0 = func_0209ccb8(&func_0207c4ec, 0);
    }
    M2C_FIELD(var_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(var_r0, s32 *, 0x44) = arg1;
    M2C_FIELD(var_r0, s32 *, 0x40) = arg2;
    M2C_FIELD(var_r0, s32 *, 0x50) = arg3;
    M2C_FIELD(var_r0, s32 *, 0x48) = 0;
    M2C_FIELD(var_r0, s32 *, 0x4C) = 0;
    func_01ffa8bc(var_r0, 0xFF02);
}

void func_0207c5d0(void *arg0) {
    M2C_UNK func_0200478c(void);
    M2C_UNK func_0200482c(s32, s32, s32);
    M2C_UNK func_0200489c(void);
    M2C_UNK func_020049dc(void);
    M2C_UNK func_020049f4(s32, s32, s32);
    M2C_UNK func_02004a58(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    if ((u8)(gCur3DSpriteEngine == data_027e00c8)) {
        func_0200478c();
        func_0200482c(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
        func_0200489c();
    } else {
        func_020049dc();
        func_020049f4(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
        func_02004a58();
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) return;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c650(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    void func_0207c5d0(void *);
    void *temp_r0;

    temp_r0 = func_0209ccb8(&func_0207c5d0, 0);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = (s32) (arg2 + (arg1 << 0xD));
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x50) = (s32) arg4;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    func_01ffa8bc(temp_r0, 0xFF02);
}

void func_0207c6a8(void *arg0) {
    M2C_UNK func_020048e4(void);
    M2C_UNK func_0200492c(s32, s32, s32);
    M2C_UNK func_02004998(void);
    M2C_UNK func_02004a98(void);
    M2C_UNK func_02004ab0(s32, s32, s32);
    M2C_UNK func_02004b14(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    if ((u8)(gCur3DSpriteEngine == data_027e00c8)) {
        func_020048e4();
        func_0200492c(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
        func_02004998();
    } else {
        func_02004a98();
        func_02004ab0(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x44), M2C_FIELD(arg0, s32 *, 0x40));
        func_02004b14();
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) return;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_0207c728(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    void func_0207c6a8(void *);
    void *temp_r0;

    temp_r0 = func_0209ccb8(&func_0207c6a8, 0);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = (s32) (arg2 + (arg1 << 0xD));
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x50) = (s32) arg4;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    func_01ffa8bc(temp_r0, 0xFF02);
}

void func_0207c780(void *arg0, u32 arg1) {
    M2C_UNK func_02007ef4(s32, s32, s32);
    extern void (*data_02101448[])();
    void (*func)();
    u8 index = (s32)(M2C_FIELD(arg0, u8 *, 0) & 0xF0) >> 3;
    if (arg1 < 0x04000000U) index++;
    func = data_02101448[index];
    if (func == NULL) {
        func_02007ef4((s32)arg0, arg1, M2C_FIELD(arg0, u32 *, 0) >> 8);
        return;
    }
    func(arg0, arg1);
}

u32 func_0207c7cc(u32 *arg0) {
    return (u32) *arg0 >> 8;
}

u32 func_0207c7d8(void *arg0, u32 *arg1, u32 arg2) {
    M2C_UNK func_020085ac(void *, u32, u32 *);
    M2C_UNK func_020085d4(void *, u32, u32 *);
    M2C_UNK func_02008604(void *, u32, u32 *);
    s8 var_r1;
    u8 temp_r1;

    M2C_FIELD(arg0, u8 *, 0) = (u8) (*arg1 & 0xF0);
    if (arg2 >= 0x04000000U) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    M2C_FIELD(arg0, s8 *, 1) = var_r1;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0);
    switch (temp_r1) {                              /* irregular */
    case 16:
        func_020085d4(arg0 + 4, arg2, arg1);
        break;
    case 32:
        func_02008604(arg0 + 4, arg2, arg1);
        break;
    case 48:
        func_020085ac(arg0 + 4, arg2, arg1);
        break;
    }
    return (u32) *arg1 >> 8;
}

s32 func_0207c860(void *arg0, u32 arg1, u32 arg2) {
    s32 func_0200864c(void *, u32, u32);
    s32 func_02008700(void *, u32, u32);
    s32 func_020087ec(void *, u32, u32);
    s32 func_020088ec(void *, u32, u32);
    s32 func_02008a60(void *, u32, u32);
    s32 (*func)(void *, u32, u32);
    s32 result = 0;
    switch (M2C_FIELD(arg0, u8 *, 0)) {
    case 16:
        func = M2C_FIELD(arg0, u8 *, 1) == 0 ? func_020087ec : func_020088ec;
        result = func(arg0 + 4, arg1, arg2);
        break;
    case 32:
        result = func_02008a60(arg0 + 4, arg1, arg2);
        break;
    case 48:
        func = M2C_FIELD(arg0, u8 *, 1) == 0 ? func_0200864c : func_02008700;
        result = func(arg0 + 4, arg1, arg2);
        break;
    }
    return result;
}

s32 func_0207c8ec(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 func_0207c928(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A8;
}

void func_0207c964(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    *arg2 = *(volatile s32 *)0x040002A0;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    *arg3 = *(volatile s32 *)0x040002A8;
}

s32 func_0207c9c8(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 2;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s32 *)0x04000294 = 0;
    *(volatile s32 *)0x04000298 = arg1;
    *(volatile s32 *)0x0400029C = 0;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 func_0207ca08(s32 arg0) {
    *(volatile u16 *)0x040002B0 = 0;
    *(volatile s32 *)0x040002B8 = arg0;
    while (*(volatile u16 *)0x040002B0 & 0x8000) {}
    return *(volatile s32 *)0x040002B4;
}

s32 func_0207ca38(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
s32 t;
if(arg4==0)return arg2;
switch(arg0){
case 0:return arg1+func_0207c8ec(arg3*(arg2-arg1),arg4);
case 1:return arg1+func_0207c8ec((arg2-arg1)*(arg3*arg3),arg4*arg4);
case 2:return arg1+func_0207c8ec((arg2-arg1)*(arg3*(arg3*arg3)),arg4*(arg4*arg4));
case 3:return arg1+func_0207c8ec((arg2-arg1)*(arg3*(arg3*(arg3*arg3))),arg4*(arg4*(arg4*arg4)));
case 4:t=arg4-arg3;return arg2-func_0207c8ec((arg2-arg1)*(t*t),arg4*arg4);
case 5:t=arg4-arg3;return arg2-func_0207c8ec((arg2-arg1)*(t*(t*t)),arg4*(arg4*arg4));
default:return 0;
}}

s32 func_0207cb5c(s32 arg0, s32 arg1) {
    if (arg1 < 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 1;
    }
    return arg0 * func_0207cb5c(arg0, arg1 - 1);
}

s32 func_0207cb88(s32 arg0) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 var_r0;
    s32 var_r5;

    var_r0 = arg0;
    var_r5 = 0;
    do {
        var_r0 = func_0207c8ec(var_r0, 0xA);
        var_r5 += 1;
    } while (var_r0 != 0);
    return var_r5;
}

void func_0207cbb0(void) {
    M2C_UNK func_0207cc9c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0214bfac;
    func_0207cc9c(&data_0214bfac, 0, 0, 0);
}

Unk0207Color func_0207cbd0(s32 index) {
    Unk0207Color v = data_021017f4[(u8)data_02168f14.mode != 2 ? index : (index + 2)];
    u8 *base;
    s32 limit;

    base = *gCurrentMap;
    limit = *(u16 *)(base + 0x5144);
    if (((u8 *)&v)[12] > limit) {
        ((u8 *)&v)[12] = limit;
        v.words[0] = (((u8 *)&v)[12] - 1) * 0x180;
    }
    limit = *(u16 *)(base + 0x5146);
    if (((u8 *)&v)[13] > limit) {
        ((u8 *)&v)[13] = limit;
        v.words[1] = (((u8 *)&v)[13] - 1) * 0x180;
    }
    return v;
}

M2C_UNK func_0207cc9c(M2C_UNK *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    struct Unk3 { s32 a; s32 b; s32 c; };
    extern struct Unk3 data_020ebdc4;
    extern struct Unk3 data_020ebdd0;
    struct Unk3 zero = { 0, 0, 0 };
    *(struct Unk3 *)((u8 *)arg0 + 0xF0) = data_020ebdc4;
    *(struct Unk3 *)((u8 *)arg0 + 0xFC) = zero;
    *(struct Unk3 *)((u8 *)arg0 + 0x108) = data_020ebdd0;
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
    M2C_FIELD(arg0, s32 *, 0x18) = arg3;
}

void func_0207cd0c(void *arg0) {
void func_0200402c(void *,void *,void *,s32,void *);
void func_02007f4c(void *,void *);
M2C_UNK func_02000ca0(void *,s32);
Vec0207 a = {0,0,0};
Vec0207 b = {0,0,0};
Vec0207 c = data_020ebdb8;
s32 matrix[9];
a.x = M2C_FIELD(arg0,s32 *,0x10);
a.y = M2C_FIELD(arg0,s32 *,0x14);
a.z = M2C_FIELD(arg0,s32 *,0x18);
b.x = M2C_FIELD(arg0,s32 *,0x10);
b.y = M2C_FIELD(arg0,s32 *,0x14);
b.z = 0;
*(Vec0207 *)((u8 *)arg0+0xf0)=a;
*(Vec0207 *)((u8 *)arg0+0xfc)=b;
*(Vec0207 *)((u8 *)arg0+0x108)=c;
func_0200402c(&a,&c,&b,1,(u8 *)arg0+0x1c);
func_02007f4c((u8 *)arg0+0x1c,matrix);
func_02000ca0(matrix,(s32)arg0+0x4c);
}

void func_0207cddc(s32 arg0, M2C_UNK arg1) {
 M2C_UNK func_02000ca0(void *, s32);
 M2C_UNK func_02001034(s32, void *);
 M2C_UNK func_02001524(s32, void *);
 M2C_UNK func_02001748(void *, M2C_UNK, s32);
 s32 sp24[16];
 s32 sp0[9];
 func_02001034(arg0 + 0x1C, sp24);
 func_02001748(sp24, arg1, arg0 + 0x70);
 func_02001524(arg0 + 0x70, sp0);
 func_02000ca0(sp0, arg0 + 0xB0);
}

void func_0207ce28(M2C_UNK arg0) {
    M2C_UNK func_0207cfc0(M2C_UNK);
    M2C_UNK func_020bf930(M2C_UNK);
    func_0207cc9c(arg0, 0, 0, 0);
    func_020bf930(arg0);
    func_0207cfc0(arg0);
}

void func_0207ce54(void) {
    M2C_UNK func_0207ce60();
    func_0207ce60();
}

M2C_UNK func_0207ce60(void *arg0) {
 extern void **gCurrentMap;
 M2C_FIELD(arg0,s32 *,0x10) = M2C_FIELD(arg0,s32 *,0) + ((M2C_FIELD(*gCurrentMap,s16 *,0x5148) * (s16)0x300) >> 4) + 0x180;
 M2C_FIELD(arg0,s32 *,0x14) = M2C_FIELD(arg0,s32 *,4) + ((M2C_FIELD(*gCurrentMap,s16 *,0x514a) * (s16)0x300) >> 4) + 0x180;
 M2C_FIELD(arg0,s32 *,0x18) = M2C_FIELD(arg0,s32 *,8);
}

void func_0207cec0(void *arg0, s16 arg1) {
    void func_0207cfb0(void *, s16);
    M2C_UNK func_0207cfc0(M2C_UNK);
    void func_020bf97c(void *);
    func_0207cfb0(arg0, arg1);
    func_0207cfc0((M2C_UNK)arg0);
    func_020bf97c(arg0);
}

void func_0207cee0(s32 arg0) {
 Unk0207Color a = func_0207cbd0(0);
 Unk0207Color b = func_0207cbd0(1);
 func_0207ca38(0,((u8 *)&a)[13],((u8 *)&b)[13],arg0,0x80);
}

void func_0207cf48(s32 arg0) {
 Unk0207Color a = func_0207cbd0(0);
 Unk0207Color b = func_0207cbd0(1);
 func_0207ca38(0,((u8 *)&a)[12],((u8 *)&b)[12],arg0,0x80);
}

void func_0207cfb0(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xE) = arg1;
}

s16 func_0207cfb8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xE);
}

/* Interpolate the two preset colors (indices 0 and 1) by t/128 and store the result in p. */
M2C_UNK func_0207cfc0(M2C_UNK arg) {
    void *p = (void *)arg;
    Unk0207Color colorA = func_0207cbd0(0);
    Unk0207Color colorB = func_0207cbd0(1);
    s32 t = func_0207cfb8(p);

    M2C_FIELD(p, s32 *, 0) = func_0207ca38(0, colorA.words[0], colorB.words[0], t, 128);
    M2C_FIELD(p, s32 *, 4) = func_0207ca38(0, colorA.words[1], colorB.words[1], t, 128);
    M2C_FIELD(p, s32 *, 8) = func_0207ca38(0, colorA.words[2], colorB.words[2], t, 128);
    M2C_FIELD(p, u8 *, 12) = func_0207ca38(0, ((u8 *)&colorA)[12], ((u8 *)&colorB)[12], t, 128);
    M2C_FIELD(p, u8 *, 13) = func_0207ca38(0, ((u8 *)&colorA)[13], ((u8 *)&colorB)[13], t, 128);
}

u8 func_0207d0b8(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x6F04);
}

u8 func_0207d0d4(void) {
 extern void **gCurrentMap;
 return M2C_FIELD(*gCurrentMap, u8 *, 0x6F05);
}

void func_0207d0f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6) {
 M2C_UNK func_0207d130(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 func_0207d130(arg0,arg1,arg2,arg3,arg4,arg5,arg6,0,0,0,0);
}

