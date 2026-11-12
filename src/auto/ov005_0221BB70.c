/* 14 functions from 0x0221BB70 to 0x0221CAA0 (ov005), found by ds-decomp. */
#include "common.h"
static inline void SetBlendAlpha(u8 a,u8 b) {
extern void *gCur3DSpriteEngine;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=a;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=b;
}
static inline s32 MaxPairU8(u8 a,u8 b) {if(a>b)return a;return b;}
static inline s32 MaxCount(s32 a,s32 b) {if(a>b)return a;return b;}
static inline s32 MaxU8(u8 a, u8 b, u8 c) {
    s32 m;
    if (a > b) m = a; else m = b;
    if (m <= c) m = c;
    return m;
}

void func_ov005_0221bb70(M2C_UNK arg0) {
    M2C_UNK func_01ffa730(M2C_UNK);
    s32 func_02097e84();
    void *func_0209bccc(s32, s32, s32, s32, s32, s32);
    s32 DidPlayerWin();
    M2C_UNK func_ov005_02218e54();
    s32 func_ov005_02218f50();
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_0215c340;
    s32 enabled;
    void *object;
    if (DidPlayerWin() == 0) enabled = 0;
    else if (M2C_FIELD(&data_0215c340, u16 *, M2C_FIELD(&data_0215c334, u8 *, 4) * 12) == 0) enabled = 0;
    else enabled = 1;
    if (enabled == 0) {
        func_01ffa730(arg0);
        return;
    }
    object = func_0209bccc(2, 0x14, 0, func_ov005_02218f50(), 0, 1);
    M2C_FIELD(object, u16 *, 0x46) = 12;
    M2C_FIELD(object, u8 *, 0x55) = 2;
    func_ov005_02218e54();
    M2C_FIELD(object, s32 *, 0x60) = func_02097e84();
    M2C_FIELD(object, u8 *, 0x5C) |= 4;
}

M2C_UNK func_ov005_0221bc28(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK func_020aad18(s32);
    extern M2C_UNK data_ov005_02220d50;
    func_020aad18(M2C_FIELD(FindObjectByClass(&data_ov005_02220d50), s32 *, 0x38));
}

void func_ov005_0221bc44(M2C_UNK arg0) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK func_02087db8(void *, s32);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_01ffa6fc(M2C_UNK);
    extern u16 *gKeyState;
    extern M2C_UNK data_ov005_02220d50;
    void *object;
    u8 active;
    if (!(*gKeyState & 1)) return;
    PlaySoundEffect(0x1000D);
    object = M2C_FIELD(M2C_FIELD(FindObjectByClass(&data_ov005_02220d50), void **, 0x38), void **, 0x64);
    active = M2C_FIELD(object, u8 *, 0x12) != 0;
    if (active) func_02087db8(object, 1);
    func_01ffa6fc(arg0);
}

#pragma scheduling on
void func_ov005_0221bcb0(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gSpriteAnimConfig;
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void *FindObjectByClass(M2C_UNK *);
void SetSpriteAnimation(void *,s32);
void Clear3DSpriteLayer(s32);
void DeleteSpriteObject(void *);
extern M2C_UNK data_ov005_02220db8;void *object;
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
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    s32 v;
    s32 n;
    s32 i;

    if(M2C_FIELD(arg0,s32 *,0x34)==(MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14))-1)*2){object=FindObjectByClass(&data_ov005_02220db8);if(object)SetSpriteAnimation(object,0);}
M2C_FIELD(arg0, s32 *, 0x34) += 1;
    if (M2C_FIELD(arg0, s32 *, 0x34) == 1) {
        sp38 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp38 = (*sp38 & ~0xc0) | 0x40;
        sp34 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp34 = *sp34 & ~1;
        sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp30 = *sp30 & ~2;
        sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp2C = *sp2C | 4;
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
        spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *spC = *spC & ~0x1000;
        sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp8 = *sp8 & ~0x2000;
*(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine+0x51)=16;
*(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine+0x52)=0;
    }

    v = M2C_FIELD(arg0,s32 *,0x34);
if(v>(MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14))-1)*2){
v=M2C_FIELD(arg0,s32 *,0x34)-(MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14))-1)*2;
n=EaseInterpolate(0,0,16,v,32);
*(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine+0x51)=16-n;
*(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine+0x52)=n;
M2C_FIELD(arg0,u16 *,0x38)=EaseInterpolate(1,0,-160,v,32);
M2C_FIELD(arg0,s32 *,0x44)=EaseInterpolate(1,0,64,v,32);
}
    for (i = 0; i < MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14)); i++) {
        v = M2C_FIELD(arg0, s32 *, 0x34) - i * 2;
        if (v > 0 && v <= 0x20)
            ((u16 *)((u8 *)arg0+0x38))[MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14))-i]=(u16)EaseInterpolate(1,0,160,v,32);
    }

    if (M2C_FIELD(arg0, s32 *, 0x34) != (MaxCount(MaxPairU8(M2C_FIELD(&gSpriteAnimConfig,u8 *,12),M2C_FIELD(&gSpriteAnimConfig,u8 *,13)),M2C_FIELD(&gSpriteAnimConfig,u8 *,14)) - 1) * 2 + 0x20)
        return;

Clear3DSpriteLayer(2);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 & ~0xc0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = 0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=0;
Clear3DSpriteLayer(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
M2C_FIELD(arg0,s32 *,0x34)=0;
DeleteSpriteObject(arg0);
}
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
int func_ov005_0221c150(void *arg0) {
s32 DidPlayerWin(void);
void func_02098cb8(s32,s16,s16,u16,s32,s32);
void AddSprite(u16,u8,u16,void *,s32);
extern M2C_UNK data_0215c334,data_0215c340,gSpriteAnimConfig,data_02101f4c,data_02101f1c;
extern void *gCur3DSpriteEngine;
extern void **gCurrentMap;
s32 enabled,i,y,id,offset,x,x2,k;
u8 *p;
if(!DidPlayerWin())enabled=0;
else if(M2C_FIELD(&data_0215c340,u16 *,M2C_FIELD(&data_0215c334,u8 *,4)*12)==0)enabled=0;
else enabled=1;
if(!enabled) return;
x=M2C_FIELD(arg0,s16 *,0x38)&511;
func_02098cb8(9,(s16)((x&0xfe00)|((x-1)&511)),0,(u16)(0x4800|((0x388 >> (((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),1,5);
p=(u8 *)&gSpriteAnimConfig;
y=0;
for(i=0;i<M2C_FIELD(&gSpriteAnimConfig,u8 *,12);i++,p++,y+=18){
id=M2C_FIELD(p,s8 *,0)-1;
offset=id*140;
x=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+143)&511;
AddSprite((u16)x,(u8)((u8)(y+18)+1),(u16)(0x7000|(((M2C_FIELD(*gCurrentMap,u8 *,offset+0x684d)*12+0x1d8)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
if(M2C_FIELD(*gCurrentMap,u8 *,offset+0x684e)==2)id=4;
AddSprite((u16)((x&0xfe00)|((x-10)&511)),(u8)((u8)(y+18)+1),(u16)(0x8000|(((id*16+0x220)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f1c,5);
id=M2C_FIELD(p,s8 *,0)-1;
x2=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+183)&511;
func_02098cb8(0,(s16)x2,(s16)(u8)(y+18),(u16)((((u32)id<<28)>>16)|(((id*24+0x270)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),0,5);
AddSprite((u16)((x2&0xfe00)|((x2+1)&511)),(u8)((u8)(y+18)+1),(u16)(0x7000|((0x1d8>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
}
p=(u8 *)&gSpriteAnimConfig;
y=0;
for(i=0;i<M2C_FIELD(&gSpriteAnimConfig,u8 *,14);i++,p++,y+=18){
id=M2C_FIELD(p,s8 *,8)-1;
offset=id*140;
x=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+143)&511;
AddSprite((u16)x,(u8)((u8)(y+18)+1),(u16)(0x7000|(((M2C_FIELD(*gCurrentMap,u8 *,offset+0x684d)*12+0x1d8)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
if(M2C_FIELD(*gCurrentMap,u8 *,offset+0x684e)==2)id=4;
AddSprite((u16)((x&0xfe00)|((x-10)&511)),(u8)((u8)(y+18)+1),(u16)(0x8000|(((id*16+0x220)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f1c,5);
id=M2C_FIELD(p,s8 *,8)-1;
x2=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+183)&511;
func_02098cb8(0,(s16)x2,(s16)(u8)(y+18),(u16)((((u32)id<<28)>>16)|(((id*24+0x270)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),0,5);
AddSprite((u16)((x2&0xfe00)|((x2+1)&511)),(u8)((u8)(y+18)+1),(u16)(0x7000|((0x1d8>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
}
p=(u8 *)&gSpriteAnimConfig;
y=98;
for(i=0;i<M2C_FIELD(&gSpriteAnimConfig,u8 *,13);i++,p++,y+=18){
id=M2C_FIELD(p,s8 *,4)-1;
offset=id*140;
x=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+143)&511;
AddSprite((u16)x,(u8)((u8)y+1),(u16)(0x7000|(((M2C_FIELD(*gCurrentMap,u8 *,offset+0x684d)*12+0x1d8)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
if(M2C_FIELD(*gCurrentMap,u8 *,offset+0x684e)==2)id=4;
AddSprite((u16)((x&0xfe00)|((x-10)&511)),(u8)((u8)y+1),(u16)(0x8000|(((id*16+0x220)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f1c,5);
id=M2C_FIELD(p,s8 *,4)-1;
x2=(M2C_FIELD(arg0+i*2,s16 *,0x3a)+183)&511;
func_02098cb8(0,(s16)x2,(s16)(u8)y,(u16)((((u32)id<<28)>>16)|(((id*24+0x270)>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),0,5);
AddSprite((u16)((x2&0xfe00)|((x2+1)&511)),(u8)((u8)y+1),(u16)(0x7000|((0x1d8>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&1023)),&data_02101f4c,6);
}
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=-M2C_FIELD(arg0,s32 *,0x44);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x40)=-M2C_FIELD(arg0,s32 *,0x44);
done: ;
}
#pragma opt_lifetimes reset
#pragma opt_strength_reduction reset
void func_ov005_0221c9c0(void) {
    M2C_UNK Tick3DSpriteAnimation();
    Tick3DSpriteAnimation();
}

void func_ov005_0221c9cc(void) {
    M2C_UNK func_ov005_0221b854();
    func_ov005_0221b854();
}

void func_ov005_0221c9d8(void) {
    void func_ov005_0221bb70();
    func_ov005_0221bb70();
}

void func_ov005_0221c9e4(M2C_UNK arg0) {
    s32 func_0209bf28();
    M2C_UNK func_01ffa6fc(M2C_UNK);
    if (func_0209bf28() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov005_0221ca04(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, s32);
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK func_01ffaa5c(s32);
    s32 func_01ffaa7c();
    extern M2C_UNK data_ov005_02220b00;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fb8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov005_02220b00, func_01ffaa7c());
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    func_01ffaa5c(arg0);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0x20;
    M2C_FIELD(temp_r0, s8 *, 0x44) = 1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) M2C_FIELD(FindObjectByClass(&data_ov005_02220d50), s32 *, 0x38);
}

void func_ov005_0221ca70(void) {
    M2C_UNK func_ov005_0221bc28();
    func_ov005_0221bc28();
}

void func_ov005_0221ca7c(void) {
    void func_ov005_0221bc44();
    func_ov005_0221bc44();
}

void func_ov005_0221ca88(void *arg0) {
    func_ov005_0221bcb0(arg0);
}

void func_ov005_0221ca94(void) {
    M2C_UNK func_ov005_0221c150();
    func_ov005_0221c150();
}

