/* 18 functions from 0x02219FA0 to 0x0221ABF8 (ov005), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_ov005_0221a38c(void **arg0) {
    M2C_UNK func_02090810(s32, M2C_UNK, s16);
    extern s32 data_027e00c4, data_027e00c8, gCur3DSpriteEngine;
    s32 temp_r0, temp_r8, var_r0, var_r1, var_r9;
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) var_r0 = data_027e00c8;
        else var_r0 = data_027e00c4;
        gCur3DSpriteEngine = var_r0;
        var_r1 = M2C_FIELD(arg0, s32 *, 0x3C);
        temp_r0 = M2C_FIELD(M2C_FIELD((arg0 + var_r9), void **, 0x34), s32 *, 0x38);
        if (var_r9 == 0) var_r1 -= 0xC0;
        if (temp_r0 != 0) func_02090810(temp_r0, 0x80, (s16)var_r1);
        var_r9++;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
}
#pragma opt_strength_reduction reset
void func_ov005_0221a410(void *arg0) {
M2C_UNK func_0208fe30(s32);
s32 func_0207c330(s32, s32);
M2C_UNK func_01ffa6fc(void *);
M2C_FIELD(arg0,s32 *,0x40)++;
if (M2C_FIELD(arg0,s32 *,0x40)==1) {
M2C_FIELD(arg0,u8 *,0x46)=1;
func_0208fe30(0x132);
}
M2C_FIELD(arg0,u16 *,0x50)=func_0207c330(-4,4)&0x1ff;
M2C_FIELD(arg0,u16 *,0x52)=func_0207c330(-4,4)&0xff;
if(M2C_FIELD(arg0,s32 *,0x40)!=0x10) return;
M2C_FIELD(arg0,u16 *,0x50)=0;
M2C_FIELD(arg0,u16 *,0x52)=0;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

void func_ov005_0221a498(void *arg0) {
M2C_UNK func_0208fe30(s32);
s32 func_0207c330(s32, s32);
M2C_UNK func_01ffa6fc(void *);
M2C_FIELD(arg0,s32 *,0x40)++;
if (M2C_FIELD(arg0,s32 *,0x40)==1) {
M2C_FIELD(arg0,u8 *,0x47)=1;
func_0208fe30(0x132);
}
M2C_FIELD(arg0,u16 *,0x54)=func_0207c330(-4,4)&0x1ff;
M2C_FIELD(arg0,u16 *,0x56)=func_0207c330(-4,4)&0xff;
if(M2C_FIELD(arg0,s32 *,0x40)!=0x10) return;
M2C_FIELD(arg0,u16 *,0x54)=0;
M2C_FIELD(arg0,u16 *,0x56)=0;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

void func_ov005_0221a520(void *arg0) {
M2C_UNK func_0208fe30(s32);
s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
M2C_UNK func_01ffa6fc(void *);
void func_ov005_0221a38c(void **);
M2C_FIELD(arg0,s32 *,0x40)++;
if(M2C_FIELD(arg0,s32 *,0x40)==1) func_0208fe30(0xe8);
M2C_FIELD(arg0,s32 *,0x3c)=func_0207ca38(0,0x1b0,0x58,M2C_FIELD(arg0,s32 *,0x40),0x20);
func_ov005_0221a38c(arg0);
if(M2C_FIELD(arg0,s32 *,0x40)!=0x20) return;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

#pragma opt_strength_reduction off
void func_ov005_0221a598(void *arg0) {
    M2C_UNK func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    void func_ov005_0221a38c(void **);
    M2C_UNK func_01ffa574(M2C_UNK);
    M2C_UNK func_01ffa6fc(void *);
    extern s32 data_027e00c4, data_027e00c8, gCur3DSpriteEngine;

    s32 saved;
    s32 i;

    M2C_FIELD(arg0, s32 *, 0x40) = M2C_FIELD(arg0, s32 *, 0x40) + 1;
    M2C_FIELD(arg0, s32 *, 0x3C) = func_0207ca38(0, 0x58, 0x60, M2C_FIELD(arg0, s32 *, 0x40), 0x10);
    func_ov005_0221a38c(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x40) == 1) {
        M2C_FIELD(arg0, u8 *, 0x45) = 1;
    }
    M2C_FIELD(arg0, u16 *, 0x4C) = (u16)(func_0207ca38(0, -0x80, 0, M2C_FIELD(arg0, s32 *, 0x40), 0x10) & 0x1FF);
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0x10) {
        return;
    }
    saved = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        if (i == 0) gCur3DSpriteEngine = data_027e00c8;
        else gCur3DSpriteEngine = data_027e00c4;
        func_01ffa574(M2C_FIELD((char *)arg0 + i * 4, s32 *, 0x34));
    }
    gCur3DSpriteEngine = saved;
    M2C_FIELD(arg0, u8 *, 0x44) = 1;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    func_01ffa6fc(arg0);
}
#pragma opt_strength_reduction reset
void func_ov005_0221ab38(void) {
    M2C_UNK func_ov005_0221a0c0();
    func_ov005_0221a0c0();
}

void func_ov005_0221ab44(void) {
    void func_ov005_0221a410();
    func_ov005_0221a410();
}

void func_ov005_0221ab50(void) {
    void func_ov005_0221a498();
    func_ov005_0221a498();
}

void func_ov005_0221ab5c(void) {
    void func_ov005_0221a520();
    func_ov005_0221a520();
}

void func_ov005_0221ab68(void) {
    void func_ov005_0221a598();
    func_ov005_0221a598();
}

void func_ov005_0221ab74(void) {
    M2C_UNK func_ov005_0221a688();
    func_ov005_0221a688();
}

void func_ov005_0221ab80(void) {
    M2C_UNK func_01ffaa8c();
    func_01ffaa8c();
}

void func_ov005_0221ab8c(void) {
    M2C_UNK func_ov005_0221a7f4();
    func_ov005_0221a7f4();
}

void func_ov005_0221ab98(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
    M2C_FIELD(arg0, s32 *, 0x38) = func_0207ca38(4, -0x100, 0, M2C_FIELD(arg0, s32 *, 0x34), 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x20) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa6fc(arg0);
}

