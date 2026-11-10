/* 6 functions from 0x02173468 to 0x021743F0 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct EngineFlags_02173f78 { u8 unk_0[0x46]; u8 bg0:1,bg1:1,bg2:1,unk:5; } EngineFlags_02173f78;
typedef struct SpriteEngine_02173f78 { u8 unk_0[0x1c]; u8 *tiles; u8 unk_20[0x10]; u8 *sprites; } SpriteEngine_02173f78;
typedef struct PlayerUI_02173f78 { u8 unk_0[0x6c]; u32 sprite:8; u32 unk_6c:24; } PlayerUI_02173f78;
typedef struct { s32 values[8]; } StatsOrder1734;
typedef struct { s32 values[6]; } StatsDigits1734;
typedef struct { s32 first, second, hp, ammo; StatsDigits1734 digits; s32 count, other; u8 flags[5]; } StatsRecord1734;

#pragma opt_if-conversion off
void func_ov000_02173468(void *arg0) {
s32 func_ov000_0217244c(void *);
s32 func_ov000_021724b8(s32,s32);
s32 func_ov000_0216cbc4(s32);
void AddSprite(u16,u16,u16,void *,s32);
u8 func_ov000_02173e6c(void *);
s32 func_02086420(u8);
s32 func_0207c8ec(s32,s32);
s32 func_020a88e8(s32);
void func_0208df84(s16,s16,s32,s32,u16,s32);
void func_ov000_02174da4(s32,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;
extern void **gCurrentMap;
extern u8 gMapConfig[];
extern u8 data_ov000_021b8dfc[],data_027e007c[],gSpriteDesc8x8[],data_02101f0c[],gSpriteDesc16x16[],data_02101f3c[],gSpriteDesc16x8[];
extern s8 data_ov000_021b56a0[],data_ov000_021b5600[],data_ov000_021b5680[],data_ov000_021b56e0[];

StatsOrder1734 order;
StatsRecord1734 r,*src;
void *saved;
s32 temp,a,b,c,digit,tens,ones,i,j,hidden,y4,n,show,base;
s32 recordOffset,y1,y2,y3,mapOffset,y5,y6,y7,counter;
s32 line,xDigit;
extern StatsOrder1734 data_ov000_021ae280;
u8 *map;
temp=func_ov000_0217244c(arg0);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
if(!M2C_FIELD(arg0,u8 *,0x15)){
if(func_ov000_021724b8(temp,M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0))!=-1)AddSprite(4,1,0xc144,data_ov000_021b8dfc,0);
AddSprite(135,25,(u16)(((164-M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,4))&1023)|0x6000),data_027e007c,1);
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,8)){
AddSprite(135,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,24)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(143,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,20)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(151,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,16)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(159,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,12)+128)&1023)|0x8000),gSpriteDesc8x8,1);
}else AddSprite(147,38,0x808a,gSpriteDesc8x8,1);
a=func_ov000_0216cbc4(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
b=func_ov000_0216cbc4(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
c=func_ov000_0216cbc4(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
base=(data_ov000_021b56a0[a]+2*data_ov000_021b5600[b]+3*data_ov000_021b5680[c])*4;
AddSprite(136,45,(u16)(((base+192)&1023)|0x6000),data_027e007c,1);
AddSprite(136,53,(u16)(((base+224)&1023)|0x6000),data_027e007c,1);
{order=data_ov000_021ae280;
for(line=73,i=0;i<8;i++,line+=10){
a=func_ov000_0216cbc4(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
digit=M2C_FIELD(data_ov000_021b56e0+order.values[i]*32,s8 *,a);if(digit<0)digit=10;
AddSprite(147,(u16)line,(u16)(((digit+128)&1023)|0x8000),gSpriteDesc8x8,1);
}
}
if(func_ov000_02173e6c(arg0)){
AddSprite(128,176,0x6100,data_02101f0c,1);
AddSprite(192,176,0x6108,data_02101f0c,1);
AddSprite(128,184,0x6110,data_02101f0c,1);
AddSprite(192,184,0x6118,data_02101f0c,1);
AddSprite(114,178,0xb140,gSpriteDesc16x16,1);
}}
counter=0;recordOffset=0;mapOffset=0;
y1=17;y2=25;y3=19;y4=35;y5=44;y6=34;y7=16;
for(;counter<4;counter++,recordOffset+=56,mapOffset+=140){
src=(StatsRecord1734 *)((u8 *)M2C_FIELD(arg0,void **,0x18)+0x3c+recordOffset);
r.first=src->first;r.second=src->second;r.hp=src->hp;r.ammo=src->ammo;
r.digits=src->digits;r.count=src->count;r.other=src->other;
r.flags[0]=src->flags[0];r.flags[1]=src->flags[1];r.flags[2]=src->flags[2];r.flags[3]=src->flags[3];r.flags[4]=src->flags[4];
if(!r.flags[3])goto next;
if(r.flags[4])a=1;else a=0;
hidden=a&255;
if(M2C_FIELD(arg0,s32 *,8)<60&&func_02086420((u8)counter)){
AddSprite(241,(u16)y1,0x60be,gSpriteDesc16x8,1);
AddSprite(241,(u16)y2,0x60de,gSpriteDesc16x8,1);
}
tens=hidden?10:func_0207c8ec(r.hp,10);ones=hidden?10:r.hp-tens*10;
if(tens)AddSprite(193,(u16)y3,(u16)(((tens+140)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(201,(u16)y3,(u16)(((ones+140)&1023)|0x8000),gSpriteDesc8x8,1);
map=*gCurrentMap;show=1;
if(map[0x5156]==0&&map[0x5158]!=2)show=1;
else if(!(M2C_FIELD(map+mapOffset,u8 *,0x684f)&2)&&!gMapConfig[2])show=0;
if(show){
tens=hidden?10:func_0207c8ec(r.ammo,10);ones=hidden?10:r.ammo-tens*10;
if(tens)AddSprite(193,(u16)y4,(u16)(((tens+140)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(201,(u16)y4,(u16)(((ones+140)&1023)|0x8000),gSpriteDesc8x8,1);
for(j=0,n=r.count;j<n;j++){xDigit=(5-j)*8+206;digit=hidden?10:r.digits.values[j];AddSprite((u16)xDigit,(u16)y5,(u16)(((digit+140)&1023)|0x8000),gSpriteDesc8x8,1);}
}else{
AddSprite(193,(u16)y4,0x8096,gSpriteDesc8x8,1);
AddSprite(201,(u16)y4,0x8096,gSpriteDesc8x8,1);
for(j=0;j<6;j++)AddSprite((u16)((5-j)*8+206),(u16)y5,0x8096,gSpriteDesc8x8,1);
}
if(r.flags[2]&&!func_020a88e8(M2C_FIELD(*gCurrentMap,u16 *,0x5142))){
a=r.second;b=a-6;if(b<0)b=0;
c=a;if(a>6)a=6;
AddSprite(212,(u16)y6,(u16)((((b%4)*3+(b/4)*32+208)&1023)|0x6000),data_02101f3c,1);
AddSprite(234,(u16)y6,(u16)((((a%4)*3+(a/4)*32+208)&1023)|0x6000),data_02101f3c,1);

}
if(counter+1==M2C_FIELD(*gCurrentMap,u16 *,0x52a4))func_0208df84(175,(s16)y7,84,38,(u16)(((0x40>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0x1000),0);
next:
y1+=40;y2+=40;y3+=40;y4+=40;y5+=40;y6+=40;y7+=40;
}
func_ov000_02174da4(0,182);
gCur3DSpriteEngine=saved;
M2C_FIELD(arg0,s32 *,8)++;
if(M2C_FIELD(arg0,s32 *,8)>90)M2C_FIELD(arg0,s32 *,8)=0;
}
#pragma opt_if-conversion reset
u8 func_ov000_02173e6c(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x14) == 0) {
        return 0U;
    }
    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void *func_ov000_02173ea8(void *a){s32 p;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,8)=1;M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,u8 *,16)=0;M2C_FIELD(a,u8 *,17)=1;M2C_FIELD(a,u8 *,18)=0;M2C_FIELD(a,u8 *,19)=0;M2C_FIELD(a,u8 *,20)=0;M2C_FIELD(a,s16 *,22)=-1;M2C_FIELD(a,s16 *,24)=-1;M2C_FIELD(a,u8 *,26)=255;p=MemAlloc(20);if(p)p=func_ov000_02175088(p);M2C_FIELD(a,s32 *,0)=p;p=MemAlloc(28);if(p)p=func_ov000_021724dc(p);M2C_FIELD(a,s32 *,4)=p;M2C_FIELD(a,s32 *,28)=func_020e31e0();return a;}

void *func_ov000_02173f30(void *arg0) {
    M2C_UNK MemFree(s32);
    M2C_UNK func_ov000_021725c8(s32);
    M2C_UNK func_ov000_0217519c(s32);
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r4 != 0) {
        func_ov000_0217519c(temp_r4);
        MemFree(temp_r4);
    }
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r4_2 != 0) {
        func_ov000_021725c8(temp_r4_2);
        MemFree(temp_r4_2);
    }
    return arg0;
}

#pragma opt_if-conversion on
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_02173f78(void *arg0) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007ef4(s32, s32, s32);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080c50(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_020985b0(u8, s32, s32);
    M2C_UNK func_02098a34(u8, M2C_UNK, M2C_UNK, u16, s32);
    s32 func_020a7278();
    s32 func_020a7290();
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020ad150(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_020af19c(M2C_UNK, M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern void **gCurrentMap;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021b8e48;
    extern M2C_UNK data_ov000_021b8e50;
    extern M2C_UNK data_ov000_021b8e8c;
    extern M2C_UNK data_ov000_021b8ea0;
    extern M2C_UNK data_ov000_021b8eb0;
    extern M2C_UNK data_ov000_021b8ebc;
    extern M2C_UNK data_ov000_021b8ec8;
    extern M2C_UNK data_ov000_021b8ed4;
    extern M2C_UNK data_ov000_021b8ee8;
    extern M2C_UNK data_ov000_021b8ef4;
    extern M2C_UNK data_ov000_021b8f00;
    extern M2C_UNK data_ov000_021b8f0c;
    extern M2C_UNK data_ov000_021b8f1c;
    extern M2C_UNK data_ov000_021b8f2c;
    extern M2C_UNK data_ov000_021b8f3c;
    extern M2C_UNK data_ov000_021b8f4c;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    void *sp4;
    register s32 temp_r4;
    register s32 temp_r5;
        u16 *temp_r2;
    u16 *temp_r2_2;
    u16 *temp_r2_3;
    u16 *temp_r2_4;
    u16 *temp_r2_5;
    u16 *temp_r2_6;
    register s32 var_r8;
register s32 temp_r9;
    register u8 temp_r1;
    u8 var_r0;
    register s32 tiles;
    register s32 palette;

    M2C_FIELD(arg0, s32 *, 8) = 1;
    sp4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_020822b8(&data_ov000_021b8e50);
    temp_r2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp1C = temp_r2;
    *sp1C = *sp1C & ~0x10;
    temp_r2_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp18 = temp_r2_2;
    *sp18 = *sp18 & ~0x20;
    temp_r2_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp14 = temp_r2_3;
    *sp14 = *sp14 & ~0x40;
    temp_r2_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp10 = temp_r2_4;
    *sp10 = *sp10 | 0x80;
    temp_r2_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    spC = temp_r2_5;
    *spC = *spC & ~0x100;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x44) = 0;
    temp_r2_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp8 = (u16 *)((u8 *)temp_r2_6 + 0x12);
    *sp8 = *sp8 & ~0xC0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x53) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    ((EngineFlags_02173f78 *)gCur3DSpriteEngine)->bg1 = 1;
    ((EngineFlags_02173f78 *)gCur3DSpriteEngine)->bg2 = 1;
    func_020af19c(3, 0xE);
    func_02007e98(0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC), 0x40);
    var_r8 = 0;
    do {
        temp_r9 = ((var_r8 + 1) * 0x8C) + ((s32)*gCurrentMap + 0x67A4);
        if (M2C_FIELD(temp_r9, u8 *, 0x1E) != 0) {
            temp_r1 = ((PlayerUI_02173f78 *)temp_r9)->sprite;
            func_020985b0(temp_r1, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC) + (M2C_FIELD(&data_ov000_021b8e48,u16 *,var_r8*2) << 6));
            if (M2C_FIELD(temp_r9, u8 *, 0x1C) != 0) {
                var_r0 = 8;
            } else {
                var_r0 = 0;
            }
            func_02098a34(temp_r1, 0, 2, var_r8, (var_r0 & 0xFF));
        }
        var_r8 += 1;
    } while ((s32) var_r8 < 4);
    func_0200bc5c(&data_ov000_021b8e8c);
    func_020e3218(&data_ov000_021b8ea0);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov000_021b8eb0), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x14));
    func_02081590(func_020e3218(&data_ov000_021b8ebc), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x14) + 0x3000);
    func_0208ca2c(0x800, 1, func_020ae22c(9), 2);
    tiles = (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles;
    func_020a9a30(1, 0, 0, tiles + 0x1000);
    tiles = (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles;
    func_020a9a30(1, 0, 2, tiles + 0x1180);
    func_02081590(func_020e3218(&data_ov000_021b8ec8), (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles + 0x1400);
    func_02080c50(&data_ov000_021b8ed4, (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles + 0x2800);
    temp_r5 = func_020a7290() << 5;
    temp_r4 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0xE0;
    tiles = func_020a7278();
    func_02007ef4(tiles, temp_r4 + 0x3000, temp_r5);
    func_02081528();
    func_0208116c(&data_ov000_021b8ee8, 0, 0x80);
    func_0208116c(&data_ov000_021b8ef4, 0x160, 0x20);
    func_02091d4c(0xF);
    func_0208116c(&data_ov000_021b8f00, 0x2C0, 0x20);
    palette = (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->sprites;
    func_020a9a30(1, 2, 1, palette + 0x300);
    tiles = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30);
    func_020a9a30(1, 2, 2, palette + 0x340);
    func_0208116c(&data_ov000_021b8f0c, 0x360, 0x20);
    func_0208116c(&data_ov000_021b8f1c, 0x380, 0x20);
    func_0208116c(&data_ov000_021b8f2c, 0x3A0, 0x20);
    func_0208116c(&data_ov000_021b8f3c, 0x3C0, 0x20);
    func_0208116c(&data_ov000_021b8f4c, 0x3E0, 0x20);
    gCur3DSpriteEngine = sp4;
    func_020ad150(0, 0x10, 1, 7);
}
void func_ov000_021743ec(void) {

}
