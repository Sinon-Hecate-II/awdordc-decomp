/* 11 functions from 0x021E997C to 0x021EA674 (ov002), found by ds-decomp. */
#include "common.h"
#include "ov002_effects.h"
static inline void *init_021ea71c(void *p) {
extern u8 data_ov002_021ea704[],data_ov002_021ea71c[];
M2C_FIELD(p,void **,0)=data_ov002_021ea704;
M2C_FIELD(p,s32 *,8)=0;M2C_FIELD(p,s32 *,12)=0;
M2C_FIELD(p,void **,0)=data_ov002_021ea71c;
return p;
}
static inline void *init_021ea37c(void *p) {
extern u8 data_ov002_021ea704[];
M2C_FIELD(p,void **,0)=data_ov002_021ea704;
M2C_FIELD(p,s32 *,8)=0;M2C_FIELD(p,s32 *,12)=0;return p;
}

void func_ov002_021e997c(void *arg0) {
void func_ov002_021e16dc(void *,s32,u16,u8,s32);
extern u8 data_ov002_021f3018[];
extern u8 data_ov002_021f3030[];
extern u8 data_ov002_021f3045[];
extern u8 gEffectTable[];
u8 index = M2C_FIELD(arg0,u8 *,0x8C);
s32 offset = index*0x64;
s32 value = M2C_FIELD(data_ov002_021f3018,s32 *,offset);
if (!value) return;
func_ov002_021e16dc(arg0,value,M2C_FIELD(data_ov002_021f3030,u16 *,offset),M2C_FIELD(data_ov002_021f3045+offset,u8 *,M2C_FIELD(arg0,u8 *,0x8D)*8),M2C_FIELD(M2C_FIELD(gEffectTable,void **,index*0x18),u8 *,0x38));
}

void func_ov002_021e99f0(void *arg0, s32 arg1) {
    void *MemAlloc(s32);
    void func_ov002_021e16bc(void *, u8, u8);
    void func_ov002_021e16dc(void *, s32, u16, u8, s32);
    void SetEffectNodeTranslation(void *, s16, s16, s16);
    void SetEffectScale(void *, u32);
    extern u8 data_ov002_021ea704[];
    extern u8 data_ov002_021f301c[];
    extern u8 data_ov002_021f3032[];
    extern u8 data_ov002_021f3047[];
    extern u8 gEffectTable[];
    extern u8 gEffectDefaultVariant[];
    extern u8 data_ov002_021f3108[];
    extern u8 data_ov002_021f314e[];
    s16 temp_r7;
    s16 var_r5;
    s16 var_r6;
    s32 temp_r2;
    s32 temp_r5;
    u32 temp_r9;
    u8 temp_r1;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r2_2;
    void *var_r0;
    void *var_r3;

    if (M2C_FIELD(data_ov002_021f301c, s32 *, M2C_FIELD(arg0, u8 *, 0x8C) * 0x64) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, void **, 0x54) != NULL) {
        temp_r0 = MemAlloc(8);
        if (temp_r0 != NULL) {
            M2C_FIELD(temp_r0, void **, 0) = NULL;
            M2C_FIELD(temp_r0, void **, 4) = NULL;
        }
        M2C_FIELD(temp_r0, void **, 0) = (void *) M2C_FIELD(arg0, void **, 0x54);
        M2C_FIELD(temp_r0, void **, 4) = (void *) M2C_FIELD(arg0, void **, 0x58);
        M2C_FIELD(arg0, void **, 0x58) = temp_r0;
    }
    temp_r0_2 = MemAlloc(0x54);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, void **, 0) = (void *)data_ov002_021ea704;
        M2C_FIELD(temp_r0_2, s32 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s32 *, 0xC) = 0;
    }
    M2C_FIELD(arg0, void **, 0x54) = temp_r0_2;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x8C);
    temp_r2 = temp_r1 * 0x18;
    if (M2C_FIELD(data_ov002_021f314e + (temp_r1 * 0x2C), u8 *, 0) != 0) {
        var_r0 = M2C_FIELD(M2C_FIELD(gEffectTable, void **, temp_r2), void **, 0x28);
        var_r3 = var_r0 + (arg1 * 8);
    } else {
        var_r0 = M2C_FIELD(M2C_FIELD(gEffectTable, void **, temp_r2), void **, 0x28);
        var_r3 = var_r0 + (M2C_FIELD(gEffectDefaultVariant + temp_r2, u8 *, 0) * 8);
    }
    var_r5 = M2C_FIELD(var_r3, s16 *, 0x28);
    var_r6 = M2C_FIELD(var_r3, s16 *, 0x2A);
    temp_r7 = M2C_FIELD(var_r3, s16 *, 0x2C);
    if (M2C_FIELD(data_ov002_021f3108 + temp_r2, u8 *, 0) != 0) {
        temp_r2_2 = (void *)((u8 *)M2C_FIELD(M2C_FIELD(gEffectTable, void **, temp_r2), void **, 0x28) + (M2C_FIELD(gEffectDefaultVariant + temp_r2, u8 *, 0) * 4));
        var_r5 += M2C_FIELD(temp_r2_2, s16 *, 0xC4);
        var_r6 += M2C_FIELD(temp_r2_2, s16 *, 0xC6);
    }
    temp_r9 = (u32) ((M2C_FIELD(var_r3, u16 *, 0x2E) * M2C_FIELD(var_r0, u16 *, 0xCC)) << 8) >> 0x10;
    func_ov002_021e16bc(temp_r0_2, temp_r1, M2C_FIELD(arg0, u8 *, 0x8D));
    SetEffectNodeTranslation(temp_r0_2, var_r5, var_r6, temp_r7);
    SetEffectScale(temp_r0_2, temp_r9);
    temp_r5 = M2C_FIELD(arg0, u8 *, 0x8C) * 0x64;
    func_ov002_021e16dc(temp_r0_2, M2C_FIELD(data_ov002_021f301c, s32 *, temp_r5), M2C_FIELD(data_ov002_021f3032, u16 *, temp_r5), M2C_FIELD(data_ov002_021f3047 + temp_r5, u8 *, M2C_FIELD(arg0, u8 *, 0x8D) * 8), 0);
}

#pragma opt_common_subs off
void func_ov002_021e9bc0(void *arg0,s32 arg1) {
void *MemAlloc(s32);
void SetEffectScale(void *,u32);void InitEffectNode(void *,u8,u8);
void SetEffectNodeResource(void *,s32,u16,u8,s32);
void SetEffectNodePosition(void *,s16,s16,s16);
void func_ov002_021e2d2c(void *,s16,s16,s16,s32,s32,s32,s32,s32);
void SetEffectNodeScreenPosition(void *,s16,s16,u16);
extern u8 data_ov002_021ea704[],data_ov002_021ea71c[],gEffectNodeResource[],data_ov002_021f3034[],data_ov002_021f3048[],gEffectTable[],gEffectDefaultVariant[],data_ov002_021f3108[],data_ov002_021f314e[];
void *settings; s16 x,y,z; void *q; u16 pointScale; s32 offset,finalOff; u32 scale; u8 index;void *p,*extra; u16 *point;
if(M2C_FIELD(gEffectNodeResource,s32 *,M2C_FIELD(arg0,u8 *,0x8C)*100)==0)return;
if(M2C_FIELD(arg0,void **,0x5C)){
p=MemAlloc(8);
if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(arg0,void **,0x5C);M2C_FIELD(p,void **,4)=M2C_FIELD(arg0,void **,0x60);M2C_FIELD(arg0,void **,0x60)=p;
}
M2C_FIELD(arg0,void **,0x5C)=((p=MemAlloc(0x88)) ? init_021ea71c(p):p);
q=M2C_FIELD(arg0,void **,0x5C);
index=M2C_FIELD(arg0,u8 *,0x8C); offset=(u32)index*24U;
if(data_ov002_021f314e[index*44])point=(u16 *)(M2C_FIELD(M2C_FIELD(gEffectTable,void **,offset),void **,40)+arg1*8);
else point=(u16 *)(M2C_FIELD(M2C_FIELD(gEffectTable,void **,offset),void **,40)+gEffectDefaultVariant[offset]*8);
x=M2C_FIELD(point,s16 *,0x50);y=M2C_FIELD(point,s16 *,0x52);z=M2C_FIELD(point,s16 *,0x54);pointScale=M2C_FIELD(point,u16 *,0x56);
if(data_ov002_021f3108[offset]){
extra=M2C_FIELD(M2C_FIELD(gEffectTable,void **,offset),void **,40)+gEffectDefaultVariant[offset]*4;
x+=M2C_FIELD(extra,s16 *,0xC4);y+=M2C_FIELD(extra,s16 *,0xC6);
}
settings=M2C_FIELD(M2C_FIELD(gEffectTable,void **,index*24),void **,40);
scale=(u32)((pointScale*M2C_FIELD(settings,u16 *,0xCC))<<8)>>16;
InitEffectNode(q,index,M2C_FIELD(arg0,u8 *,0x8D));
SetEffectNodePosition(q,x,y,z);
SetEffectScale(q,scale);
func_ov002_021e2d2c(q,M2C_FIELD(settings,s16 *,0x88),M2C_FIELD(settings,s16 *,0x8A),M2C_FIELD(settings,s16 *,0x8C),M2C_FIELD(settings,s16 *,0x8E),M2C_FIELD(settings,s16 *,0x90),M2C_FIELD(settings,s16 *,0x92),M2C_FIELD(settings,s16 *,0x94),M2C_FIELD(settings,s16 *,0x96));
SetEffectNodeScreenPosition(q,M2C_FIELD(arg0,s16 *,0x6C),M2C_FIELD(arg0,s16 *,0x6E),M2C_FIELD(arg0,u16 *,0x72));
finalOff=M2C_FIELD(arg0,u8 *,0x8C)*100;
SetEffectNodeResource(q,M2C_FIELD(gEffectNodeResource,s32 *,finalOff),M2C_FIELD(data_ov002_021f3034,u16 *,finalOff),(data_ov002_021f3048+finalOff)[M2C_FIELD(arg0,u8 *,0x8D)*8],0);
}
#pragma opt_common_subs reset
/* Rebuilds the unit's move-pose sprite node: moves the old node onto a free
   list, allocates a fresh 0x54-byte node, then configures its translation,
   scale and resource from the current effect's pose and 100-byte record. */
void SetupUnitMoveNode(void *unit,s32 variant) {
void *MemAlloc(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void SetEffectNodeTranslation(void *,s16,s16,s16);void SetEffectScale(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f3024[],data_ov002_021f3036[],data_ov002_021f3049[],gEffectTable[];
void *p,*q,*cfg,*pose;u32 scale;s32 resOfs;s16 x,y;
if(!M2C_FIELD(data_ov002_021f3024,s32 *,M2C_FIELD(unit,u8 *,140)*100))return;
if(M2C_FIELD(unit,void **,84)){
p=MemAlloc(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(unit,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(unit,void **,88);M2C_FIELD(unit,void **,88)=p;}
M2C_FIELD(unit,void **,84)=((p=MemAlloc(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(unit,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(unit,u8 *,140),M2C_FIELD(unit,u8 *,141));
cfg=M2C_FIELD(M2C_FIELD(gEffectTable,void **,M2C_FIELD(unit,u8 *,140)*24),void **,40);
x=M2C_FIELD(cfg,s16 *,120);y=M2C_FIELD(cfg,s16 *,122);
if(variant!=-1){pose=cfg+variant*4;x+=M2C_FIELD(pose,s16 *,176);y+=M2C_FIELD(pose,s16 *,178);}
scale=(u32)((M2C_FIELD(cfg,u16 *,126)*M2C_FIELD(cfg,u16 *,204))<<8)>>16;
SetEffectNodeTranslation(q,x,y,M2C_FIELD(cfg,s16 *,124));
SetEffectScale(q,scale);
resOfs=M2C_FIELD(unit,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f3024,s32 *,resOfs),M2C_FIELD(data_ov002_021f3036,u16 *,resOfs),M2C_FIELD(data_ov002_021f3049+resOfs,u8 *,M2C_FIELD(unit,u8 *,141)*8),0);
}

#pragma opt_propagation off
#pragma opt_common_subs off
/* Replaces an object's effect node (if any) with a fresh one built from the
 * effect table: position, optional variant offset, scale, transform, screen
 * position and resource.  The "alt" indices are !index, the table's other
 * entry. */
void SpawnEffectNode(void *obj, s32 frames, s32 variant) {
void *MemAlloc(s32);
void InitEffectNode(void *,u8,u8);
void SetEffectNodePosition(void *,s16,s16,s16);
void SetEffectScale(void *,u32);
void SetEffectNodeTransform(void *,s16,s16,s16,s32,s32,s32,s32);
void SetEffectNodeScreenPosition(void *,s16,s16,u16);
void SetEffectNodeResource(void *,s32,u16,u8,s32);
extern u8 gEffectNodeResource[],gEffectTable[],gEffectDefaultVariant[],data_ov002_021f304a[],data_ov002_021f3034[];
void *p,*settings,*other,*t;
s16 x,y;
u32 scale;
void *node;
u8 index;
s32 altInit,alt1,alt2,alt3,alt4,alt5;
altInit = !M2C_FIELD(obj,u8 *,0x8c);
if(!M2C_FIELD(gEffectNodeResource,s32 *,altInit*100))return;
if(M2C_FIELD(obj,void **,0x5c)){
p=MemAlloc(8);
if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(obj,void **,0x5c);
M2C_FIELD(p,void **,4)=M2C_FIELD(obj,void **,0x60);
M2C_FIELD(obj,void **,0x60)=p;
}
M2C_FIELD(obj,void **,0x5c)=((p=MemAlloc(0x88)) ? init_021ea71c(p):p);
node=M2C_FIELD(obj,void **,0x5c);
index=M2C_FIELD(obj,u8 *,0x8c);
settings=((EffectSet *)M2C_FIELD(gEffectTable,void **,index*24))->config;
x=((EffectConfig *)settings)->posX;y=((EffectConfig *)settings)->posY;
if(variant!=-1){t=(u8 *)settings+variant*4;x+=M2C_FIELD(t,s16 *,0xb0);y+=M2C_FIELD(t,s16 *,0xb2);}
settings=((EffectSet *)M2C_FIELD(gEffectTable,void **,index*24))->config;
scale=(u32)((((EffectConfig *)settings)->scale*((EffectConfig *)settings)->textureScale)<<8)>>16;
alt1 = !index;
alt2 = !index;
frames+=M2C_FIELD(M2C_FIELD((u8 *)M2C_FIELD(gEffectTable,void **,alt2*24)+gEffectDefaultVariant[alt1*24]*4,void **,0x2c),u8 *,2);
alt3 = !index;
other=((EffectSet *)M2C_FIELD(gEffectTable,void **,alt3*24))->config;
InitEffectNode(node,index,M2C_FIELD(obj,u8 *,0x8d));
SetEffectNodePosition(node,x,y,M2C_FIELD(M2C_FIELD(M2C_FIELD(gEffectTable,void **,M2C_FIELD(obj,u8 *,0x8c)*24),void **,40),s16 *,0x7c));
SetEffectScale(node,scale);
SetEffectNodeTransform(node,((EffectConfig *)other)->transform[0],((EffectConfig *)other)->transform[1],((EffectConfig *)other)->transform[2],((EffectConfig *)other)->transform[3],frames,((EffectConfig *)other)->transform[4],((EffectConfig *)other)->transform[5]);
SetEffectNodeScreenPosition(node,M2C_FIELD(obj,s16 *,0x6c),M2C_FIELD(obj,s16 *,0x6e),M2C_FIELD(obj,u16 *,0x72));
index=M2C_FIELD(obj,u8 *,0x8c);
alt4 = !index;
alt5 = !index;
SetEffectNodeResource(node,M2C_FIELD(gEffectNodeResource,s32 *,alt5*100),M2C_FIELD(data_ov002_021f3034,u16 *,alt4*100),(data_ov002_021f304a+index*100)[M2C_FIELD(obj,u8 *,0x8d)*8],1);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* Sets up the unit's action (attack) effect node from the effect's second
 * position set, shifting it by the chosen variant's x/y offset, and links the
 * new node in front of the one it replaces. */
void SetupUnitActionNode(void *unit,s32 variant) {
void *MemAlloc(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void SetEffectNodeTranslation(void *,s16,s16,s16);void SetEffectScale(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f3028[],data_ov002_021f3038[],data_ov002_021f304b[],gEffectTable[];
void *p,*q,*pose;EffectConfig *cfg;u32 scale;s32 resOfs;s16 x,y;
if(!M2C_FIELD(data_ov002_021f3028,s32 *,M2C_FIELD(unit,u8 *,140)*100))return;
if(M2C_FIELD(unit,void **,84)){
p=MemAlloc(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(unit,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(unit,void **,88);M2C_FIELD(unit,void **,88)=p;}
M2C_FIELD(unit,void **,84)=((p=MemAlloc(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(unit,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(unit,u8 *,140),M2C_FIELD(unit,u8 *,141));
cfg=((EffectSet *)M2C_FIELD(gEffectTable,void **,M2C_FIELD(unit,u8 *,140)*24))->config;
x=cfg->pos2X;y=cfg->pos2Y;
if(variant!=-1){pose=(u8 *)cfg+variant*4;x+=M2C_FIELD(pose,s16 *,176);y+=M2C_FIELD(pose,s16 *,178);}
scale=(u32)((cfg->scale2*cfg->textureScale)<<8)>>16;
SetEffectNodeTranslation(q,x,y,cfg->pos2Z);
SetEffectScale(q,scale);
resOfs=M2C_FIELD(unit,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f3028,s32 *,resOfs),M2C_FIELD(data_ov002_021f3038,u16 *,resOfs),M2C_FIELD(data_ov002_021f304b+resOfs,u8 *,M2C_FIELD(unit,u8 *,141)*8),0);
}

void func_ov002_021ea37c(void *arg0) {
void *MemAlloc(s32);void func_ov002_021e16bc(void *,u8,u8);void func_ov002_021e16dc(void *,s32,u16,u8,s32);void SetEffectNodeTranslation(void *,s16,s16,s16);void SetEffectScale(void *,u32);
extern u8 data_ov002_021ea704[],data_ov002_021f302c[],data_ov002_021f303a[],data_ov002_021f304c[],gEffectTable[];
void *p,*q,*lr;u32 v;s32 off;
if(!M2C_FIELD(data_ov002_021f302c,s32 *,M2C_FIELD(arg0,u8 *,140)*100))return;
if(M2C_FIELD(arg0,void **,84)){
p=MemAlloc(8);if(p){M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(arg0,void **,84);M2C_FIELD(p,void **,4)=M2C_FIELD(arg0,void **,88);M2C_FIELD(arg0,void **,88)=p;}
M2C_FIELD(arg0,void **,84)=((p=MemAlloc(84)) ? init_021ea37c(p):p);
q=M2C_FIELD(arg0,void **,84);
func_ov002_021e16bc(q,M2C_FIELD(arg0,u8 *,140),M2C_FIELD(arg0,u8 *,141));
lr=M2C_FIELD(M2C_FIELD(gEffectTable,void **,M2C_FIELD(arg0,u8 *,140)*24),void **,40);
v=(u32)((M2C_FIELD(lr,u16 *,134)*M2C_FIELD(lr,u16 *,204))<<8)>>16;
SetEffectNodeTranslation(q,M2C_FIELD(lr,s16 *,128),M2C_FIELD(lr,s16 *,130),M2C_FIELD(lr,s16 *,132));
SetEffectScale(q,v);
off=M2C_FIELD(arg0,u8 *,140)*100;
func_ov002_021e16dc(q,M2C_FIELD(data_ov002_021f302c,s32 *,off),M2C_FIELD(data_ov002_021f303a,u16 *,off),M2C_FIELD(data_ov002_021f304c+off,u8 *,M2C_FIELD(arg0,u8 *,141)*8),0);
}

void func_ov002_021ea4bc(void *arg0, s32 arg1, s32 arg2) {
    void *MemAlloc(s32);
    void func_ov002_021e3e0c(void *, s16, s16, s16, u16, u16, u16, u16, u8, u8, u8, u8);
    extern u8 gEffectTable[];
    extern u8 data_ov002_021f306e[];
    void *tmp, *p, *base2;
    s32 idx, idx2;u8 e;
    u16 a, b, c, d;
    s16 x, y, z;

    if (M2C_FIELD(arg0, void **, 0x64) != 0) {
        tmp = MemAlloc(8);
        if (tmp != 0) {
            M2C_FIELD(tmp, s32 *, 0) = 0;
            M2C_FIELD(tmp, s32 *, 4) = 0;
        }
        M2C_FIELD(tmp, void **, 0) = M2C_FIELD(arg0, void **, 0x64);
        M2C_FIELD(tmp, void **, 4) = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(arg0, void **, 0x68) = tmp;
        M2C_FIELD(arg0, void **, 0x64) = MemAlloc(0x14);
    }

    idx = M2C_FIELD(arg0, u8 *, 0x8c);
    p = M2C_FIELD(gEffectTable, void **, idx * 0x18);
    idx2 = M2C_FIELD(arg0, u8 *, 0x8d);
    p = M2C_FIELD(p, void **, 0x28);
    a = M2C_FIELD(p, u16 *, 0xaa);
    b = M2C_FIELD(p, u16 *, 0xac);
    base2 = data_ov002_021f306e;
    base2=(u8 *)base2+idx*0x64;
    c=M2C_FIELD(base2,u16 *,idx2*2);
    d = M2C_FIELD(p, u16 *, 0xae);
    e = (u8)((s32)idx2 + 1);
    x = (s16)(arg1 + M2C_FIELD(p, s16 *, 0xa4));
    y = (s16)(arg2 + M2C_FIELD(p, s16 *, 0xa6));
    z = M2C_FIELD(p, s16 *, 0xa8);
    func_ov002_021e3e0c(M2C_FIELD(arg0, void **, 0x64), x, y, z, a, b, c, d, e, 0x1f, idx, idx2);
}

void func_ov002_021ea5b8(void) {
    M2C_UNK FreeModelNode();
    FreeModelNode();
}

void func_ov002_021ea5c4(void *arg0) {
    void func_ov002_021e99f0(void *,s32);
    void func_ov002_021e9bc0(void *,s32);
    extern u8 data_ov002_021f314e[];
    if (data_ov002_021f314e[M2C_FIELD(arg0,u8 *,0x8C)*0x2C]) {
        func_ov002_021e99f0(arg0,M2C_FIELD(arg0,s32 *,0x84));
        func_ov002_021e9bc0(arg0,M2C_FIELD(arg0,s32 *,0x84));
        M2C_FIELD(arg0,s32 *,0x84)++;
    } else {
        func_ov002_021e99f0(arg0,-1);
        func_ov002_021e9bc0(arg0,-1);
    }
}

s32 func_ov002_021ea628(void *arg0) {
extern u8 data_ov002_021f314e[];
extern u8 data_ov002_021f2f44[];
u8 index = M2C_FIELD(arg0,u8 *,0x8C);
if (data_ov002_021f314e[index*0x2C] != 0 && M2C_FIELD(data_ov002_021f2f44 + index*0x68,u8 *,0x66) <= M2C_FIELD(arg0,s32 *,0x84)) return 1;
return 0;
}

