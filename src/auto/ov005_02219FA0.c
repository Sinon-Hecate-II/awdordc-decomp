/* 18 functions from 0x02219FA0 to 0x0221ABF8 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct { u16 mode:3; u16 rest:13; } Ov005ModeBits;

#pragma opt_strength_reduction off
void func_ov005_02219fa0(s32 a, s32 b, s32 c) {
void *func_01ffa770(void *);
void *func_01ffa3dc(void *,void *);
s32 func_02090e0c(s32,u8,s32,s32,s32,s32,s32,void *);
void func_ov005_02219e58(void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
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
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
M2C_FIELD((char *)obj+4*i,s32 *,0x34)=func_02090e0c(M2C_FIELD(parent,s32 *,0x34),(u8)c,0,0,(u16)((0x3ff & (0x178 >> ((u32)(**(u16 **)engine <<17)>>30)))|0xf000),0,0,obj);
}
gCur3DSpriteEngine=saved;
M2C_FIELD(obj,s32 *,0x3c)=a;
M2C_FIELD(obj,s32 *,0x40)=b;
M2C_FIELD(obj,s32 *,0x44)=c;
func_ov005_02219e58(obj);
}

void func_ov005_0221a0c0(void *x) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
extern M2C_UNK data_ov005_02221008,data_ov005_02220fec,data_02101f78;
void AddSprite(u16,u16,u16,void *,s32);void func_01ffad0c(u16,u16,u16,void *,s32);
s32 saved;u16 px,py;u32 px2; s32 saved2;u32 ycoord;u16 py2;
if(M2C_FIELD(x,u8 *,0x44)){
py=M2C_FIELD(x,u16 *,0x4a);px=M2C_FIELD(x,u16 *,0x48);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite((px&0xfe00)|((px+128)&511),(py&0xff00)|((py+96)&255),(((0x1d8>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0xa000),&data_ov005_02221008,5);
gCur3DSpriteEngine=saved;
}
if(M2C_FIELD(x,u8 *,0x45)){
py2=M2C_FIELD(x,u16 *,0x4e);px2=M2C_FIELD(x,u16 *,0x4c);
saved2=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
ycoord=(py2&0xff00)|((py2+96)&255);
AddSprite((px2&0xfe00)|((px2+64)&511),ycoord,(((0x488>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0xc000),&data_ov005_02220fec,6);
func_01ffad0c((px2&0xfe00)|((192-px2)&511),ycoord,(((0x488>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0xc000),&data_ov005_02220fec,6);
gCur3DSpriteEngine=saved2;
}
if(M2C_FIELD(x,u8 *,0x46)){
py=M2C_FIELD(x,u16 *,0x52);px=M2C_FIELD(x,u16 *,0x50);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite(px,py,(((0x388>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0xb000),&data_02101f78,5);
gCur3DSpriteEngine=saved;
}
if(M2C_FIELD(x,u8 *,0x47)){
py=M2C_FIELD(x,u16 *,0x56);px=M2C_FIELD(x,u16 *,0x54);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite(px,(py&0xff00)|((py+156)&255),(((0x408>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0xb000),&data_02101f78,5);
gCur3DSpriteEngine=saved;
}
}

void func_ov005_0221a38c(void **arg0) {
    M2C_UNK func_02090810(s32, M2C_UNK, s16);
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    s32 temp_r0, temp_r8, var_r0, var_r1, var_r9;
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) var_r0 = g3DSpriteEngineMain;
        else var_r0 = g3DSpriteEngineSub;
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
s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
M2C_UNK func_01ffa6fc(void *);
void func_ov005_0221a38c(void **);
M2C_FIELD(arg0,s32 *,0x40)++;
if(M2C_FIELD(arg0,s32 *,0x40)==1) func_0208fe30(0xe8);
M2C_FIELD(arg0,s32 *,0x3c)=EaseInterpolate(0,0x1b0,0x58,M2C_FIELD(arg0,s32 *,0x40),0x20);
func_ov005_0221a38c(arg0);
if(M2C_FIELD(arg0,s32 *,0x40)!=0x20) return;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

#pragma opt_strength_reduction off
void func_ov005_0221a598(void *arg0) {
    M2C_UNK EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    void func_ov005_0221a38c(void **);
    M2C_UNK func_01ffa574(M2C_UNK);
    M2C_UNK func_01ffa6fc(void *);
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;

    s32 saved;
    s32 i;

    M2C_FIELD(arg0, s32 *, 0x40) = (M2C_FIELD(arg0, s32 *, 0x40) + 1);
    M2C_FIELD(arg0, s32 *, 0x3C) = EaseInterpolate(0, 0x58, 0x60, M2C_FIELD(arg0, s32 *, 0x40), 0x10);
    func_ov005_0221a38c(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x40) == 1) {
        M2C_FIELD(arg0, u8 *, 0x45) = 1;
    }
    M2C_FIELD(arg0, u16 *, 0x4C) = (u16)(EaseInterpolate(0, -0x80, 0, M2C_FIELD(arg0, s32 *, 0x40), 0x10) & 0x1FF);
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0x10) {
        return;
    }
    saved = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        gCur3DSpriteEngine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
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
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub;
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
    gCur3DSpriteEngine = g3DSpriteEngineSub;
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

M2C_UNK func_ov005_0221a7f4(M2C_UNK self) {
    M2C_UNK EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK func_01ffa574(M2C_UNK);
    extern s32 g3DSpriteEngineSub, gCur3DSpriteEngine;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile sp0C;
    u16 *volatile sp08;
    s32 saved;
    s32 tmp;

    M2C_FIELD(self, s32 *, 0x40) = M2C_FIELD(self, s32 *, 0x40) + 1;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    if (M2C_FIELD(self, s32 *, 0x40) == 1) {
        s32 v0;
        M2C_FIELD(self, s16 *, 0x4A) = 0x400;
        sp38 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp38 = (*sp38 & ~0xC0) | 0x40;
        sp34 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp34 = *sp34 & ~1;
        sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp30 = *sp30 & ~2;
        sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp2C = *sp2C & ~4;
        sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp28 = *sp28 & ~8;
        sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp24 = *sp24 & ~0x10;
        sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp20 = *sp20 & ~0x20;
        sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp1C = *sp1C & ~0x100;
        sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp18 = *sp18 & ~0x200;
        sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp14 = *sp14 & ~0x400;
        sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp10 = *sp10 | 0x800;
        sp0C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp0C = *sp0C & ~0x1000;
        sp08 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp08 = *sp08 & ~0x2000;

        v0 = EaseInterpolate(0, 0, 0x10, M2C_FIELD(self, s32 *, 0x40), 0x20);
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = (u8)(0x10 - v0);
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = (u8)v0;
        gCur3DSpriteEngine = saved;
        M2C_FIELD(self, s16 *, 0x4C) = (s16)(-EaseInterpolate(0, 0, 0x80, M2C_FIELD(self, s32 *, 0x40), 0x20) & 0x1FF);
        tmp = EaseInterpolate(0, 0, 0x30, M2C_FIELD(self, s32 *, 0x40), 0x20);
        M2C_FIELD(self, s16 *, 0x52) = (s16)(-tmp & 0xFF);
        M2C_FIELD(self, s16 *, 0x56) = (s16)(tmp & 0xFF);
    }

    if (M2C_FIELD(self, s32 *, 0x40) == 0x20) {
        u16 *ptr;
        s32 old = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineSub;
        ptr = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *ptr = *ptr & ~0xC0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = 0;
        gCur3DSpriteEngine = old;
        M2C_FIELD(self, s32 *, 0x40) = 0;
        func_01ffa574(self);
    }
    return 0;
}

#pragma opt_strength_reduction reset
void func_ov005_0221ab38(void) {
    void func_ov005_0221a0c0();
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
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
    M2C_FIELD(arg0, s32 *, 0x38) = EaseInterpolate(4, -0x100, 0, M2C_FIELD(arg0, s32 *, 0x34), 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x34) != 0x20) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    func_01ffa6fc(arg0);
}

