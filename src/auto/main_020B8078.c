/* 20 functions from 0x020B8078 to 0x020B8CCC (main), found by ds-decomp. */
#include "common.h"

extern u8 data_021290b4[40];

void func_020b8208(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=4;
}

void func_020b821c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    M2C_UNK func_02082770();
    extern void *data_027e00bc;
    s8 temp_r4;

    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    temp_r4 = func_0207ca38(0, 0, 4, M2C_FIELD(arg0, s16 *, 0x54), (s32) M2C_FIELD(arg0, s16 *, 0x52));
    func_02082770();
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0xC0) | 0xC0);
    M2C_FIELD(data_027e00bc, s8 *, 0x53) = temp_r4;
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) ((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~1) | 1);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~2);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~4);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~8);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x10);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x100);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x200);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x400);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x800);
    M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16) (M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0x1000);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < (s32) M2C_FIELD(arg0, s16 *, 0x52)) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020b8338(void *arg0) {
s16 *p=(s16 *)arg0;
p[42]=0; p[41]=2;
}

u8 func_020b846c(M2C_UNK arg0) {
    void *func_020b895c(void);
    s32 func_02086a00(M2C_UNK);
    void *temp_r4;
    temp_r4 = func_020b895c();
    return (func_02086a00(arg0) != 0) || (M2C_FIELD(temp_r4, u8 *, 0x34) != 0);
}

void func_020b8594(s32 arg0) {
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_020b84a0(s32, s32);
    extern s32 data_0215d84c;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    data_0215d84c = 0x124;
    func_020809c0(M2C_FIELD(data_027e00c8, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (arg0 & 1) {
        var_r5 = 0;
        var_r6 = arg0 >> 1;
        var_r7 = -1;
        do {
            func_020b84a0(var_r7, var_r6);
            var_r5 += 1;
            var_r6 += 1;
            var_r7 += 2;
        } while (var_r5 < 7);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x19, 1);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x19, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = arg0 >> 1;
        do {
            func_020b84a0(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = temp_r4;
}

s32 func_020b8694(void *arg0) {
s32 n=M2C_FIELD(arg0,s16 *,0x40);
switch(n) { case 0: return 0; default: M2C_FIELD(arg0,s16 *,0x40)=n-1; return 1; }
}
#pragma optimization_level 4
s16 func_020b86b4(void *arg0) {
    s16 temp_r2;
    temp_r2 = M2C_FIELD(arg0, s16 *, 0x40);
    M2C_FIELD(arg0, s16 *, 0x40) = (s16)(temp_r2 - 6);
    if (M2C_FIELD(arg0, s16 *, 0x40) < 0) {
        M2C_FIELD(arg0, s16 *, 0x40) = 0;
    }
    return (s16)(M2C_FIELD(arg0, s16 *, 0x40) - temp_r2);
}

s32 func_020b86e4(void *arg0) {
    s16 old = M2C_FIELD(arg0, s16 *, 0x40);
    if (old + 6 >= M2C_FIELD(arg0, s16 *, 0x42)) return 0;
    M2C_FIELD(arg0, s16 *, 0x40)++;
    return 1;
}

s16 func_020b870c(void *arg0){
s16 old=M2C_FIELD(arg0,s16*,0x40);s32 max;
M2C_FIELD(arg0,volatile s16*,0x40)=old+6;
max=M2C_FIELD(arg0,volatile s16*,0x42)-6;
if(M2C_FIELD(arg0,s16*,0x40)>max)M2C_FIELD(arg0,s16*,0x40)=max;
return M2C_FIELD(arg0,s16*,0x40)-old;
}

M2C_UNK func_020b8740(void) {
    void *func_020b895c(void);
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b21a0();
    M2C_UNK func_020b2268();
    void *temp_r4;
    temp_r4 = func_020b895c();
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
    func_020b21a0();
    func_020b2268();
}

void func_020b876c(void) {
    M2C_UNK func_020b8740();
    func_020b8740();
}

void func_020b8778(void) {
    M2C_UNK func_020b8740();
    M2C_UNK func_020ae068();
    func_020ae068();
    func_020b8740();
}

void func_020b88f8(u8 *arg0) {
    void *func_020b895c(void);
    M2C_FIELD(func_020b895c(), s16 *, 0x3a) = *arg0;
}

void func_020b8910(void) {
    void *func_020b895c(void);
    s32 i;
    s32 y;
    func_020b895c();
    i = 0;
    y = 0x27;
    do {
        func_020b22a4(4, y, data_021290b4, i);
        i++;
        y += 0x10;
    } while (i < 6);
    func_020b1c78(0);
}

#pragma optimization_level 2
void *func_020b895c(void) {
void *func_01ffa770();extern M2C_UNK data_021290dc;
return func_01ffa770(&data_021290dc);
}
#pragma optimization_level 4
