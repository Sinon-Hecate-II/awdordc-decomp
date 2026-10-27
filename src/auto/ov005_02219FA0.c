/* 18 functions from 0x02219FA0 to 0x0221ABF8 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct { u16 mode:3; u16 rest:13; } Ov005ModeBits;

#pragma opt_strength_reduction off
void func_ov005_02219fa0(s32 a, s32 b, s32 c) {
void *func_01ffa770(void *);
void *func_01ffa3dc(void *,void *);
s32 func_02090e0c(s32,u8,s32,s32,s32,s32,s32,void *);
void func_ov005_02219e58(void *);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
extern M2C_UNK data_ov005_02220d50,data_ov005_02220fa4,data_0211e058;
void *obj;
s32 i;
void *parent;
s32 saved,engine;
parent=func_01ffa770(&data_ov005_02220d50);
obj=func_01ffa3dc(&data_0211e058,parent);
if(!obj)return;
M2C_FIELD(obj,void **,0)=&data_ov005_02220fa4;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)engine=data_027e00c8;else engine=data_027e00c4;
gCur3DSpriteEngine=engine;
M2C_FIELD((char *)obj+4*i,s32 *,0x34)=func_02090e0c(M2C_FIELD(parent,s32 *,0x34),(u8)c,0,0,(u16)((0x3ff & (0x178 >> ((u32)(**(u16 **)engine <<17)>>30)))|0xf000),0,0,obj);
}
gCur3DSpriteEngine=saved;
M2C_FIELD(obj,s32 *,0x3c)=a;
M2C_FIELD(obj,s32 *,0x40)=b;
M2C_FIELD(obj,s32 *,0x44)=c;
func_ov005_02219e58(obj);
}

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
s32 RandomIntRange(s32, s32);
M2C_UNK func_01ffa6fc(void *);
M2C_FIELD(arg0,s32 *,0x40)++;
if (M2C_FIELD(arg0,s32 *,0x40)==1) {
M2C_FIELD(arg0,u8 *,0x46)=1;
func_0208fe30(0x132);
}
M2C_FIELD(arg0,u16 *,0x50)=RandomIntRange(-4,4)&0x1ff;
M2C_FIELD(arg0,u16 *,0x52)=RandomIntRange(-4,4)&0xff;
if(M2C_FIELD(arg0,s32 *,0x40)!=0x10) return;
M2C_FIELD(arg0,u16 *,0x50)=0;
M2C_FIELD(arg0,u16 *,0x52)=0;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

void func_ov005_0221a498(void *arg0) {
M2C_UNK func_0208fe30(s32);
s32 RandomIntRange(s32, s32);
M2C_UNK func_01ffa6fc(void *);
M2C_FIELD(arg0,s32 *,0x40)++;
if (M2C_FIELD(arg0,s32 *,0x40)==1) {
M2C_FIELD(arg0,u8 *,0x47)=1;
func_0208fe30(0x132);
}
M2C_FIELD(arg0,u16 *,0x54)=RandomIntRange(-4,4)&0x1ff;
M2C_FIELD(arg0,u16 *,0x56)=RandomIntRange(-4,4)&0xff;
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

/* Create two sprite objects for a hit effect and play the appropriate sound. */
void func_ov005_0221a688(void *arg) {
    M2C_UNK func_0208fe30(s32);
    void *func_01ffa42c(void *, void *);
    void func_02007ef4(void *, void *, s32);
    extern Ov005ModeBits data_02168f14;
    extern u8 data_0215c334[];
    extern s32 gCur3DSpriteEngine, data_027e00c4;
    extern M2C_UNK data_ov005_02220aa8, data_ov005_02220fcc;
    s32 sound = 0xe9;
    s32 saved;
    void *obj;
    if ((u8)(data_02168f14.mode != 1)) {
        switch (data_0215c334[3]) {
        case 4: sound = 0xea; break;
        case 3: sound = 0xeb; break;
        case 2: sound = 0xec; break;
        case 1: sound = 0xed; break;
        }
    }
    func_0208fe30(sound);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    obj = func_01ffa42c(&data_ov005_02220aa8, arg);
    if (obj) {
        M2C_FIELD(obj, void **, 0) = &data_ov005_02220fcc;
        M2C_FIELD(obj, s32 *, 0x58) = 0x7fff;
        M2C_FIELD(obj, s32 *, 0x60) = 2;
        M2C_FIELD(obj, s32 *, 0x64) = 16;
        M2C_FIELD(obj, void **, 0x54) = (char *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x30) + 0x340;
        func_02007ef4(M2C_FIELD(obj, void **, 0x54), (char *)obj + 0x34, 32);
        M2C_FIELD(obj, s32 *, 0x5c) = 0;
    }
    obj = func_01ffa42c(&data_ov005_02220aa8, arg);
    if (obj) {
        M2C_FIELD(obj, void **, 0) = &data_ov005_02220fcc;
        M2C_FIELD(obj, s32 *, 0x58) = 0x7fff;
        M2C_FIELD(obj, s32 *, 0x60) = 2;
        M2C_FIELD(obj, s32 *, 0x64) = 16;
        M2C_FIELD(obj, void **, 0x54) = (char *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x30) + 0x380;
        func_02007ef4(M2C_FIELD(obj, void **, 0x54), (char *)obj + 0x34, 32);
        M2C_FIELD(obj, s32 *, 0x5c) = 0;
    }
    gCur3DSpriteEngine = saved;
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
    void func_ov005_0221a688();
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

