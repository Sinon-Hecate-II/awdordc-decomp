/* 7 functions from 0x02175FB0 to 0x02176E28 (ov000), found by ds-decomp. */
#include "common.h"

#pragma opt_strength_reduction off
void func_ov000_02175fb0(void *a) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;
void AddSprite(u16,u16,u16,void *,s32);
s32 Divide(s32,s32);
extern u8 data_ov000_021deb7c[],data_ov000_021deb20[],gSpriteDesc8x8[],data_ov000_021deb10[],data_ov000_021deb18[],gSpriteDesc16x16[],data_02101f0c[];extern s32 data_ov000_021df600;extern s16 gSinCosTable[];
s32 func_020a72b0(s32,s32);u8 func_ov000_02176dcc(void *);
void SetSpriteQuad(s32,s16,s16,s16,s16);
s32 level,n,d,i,ratio,den,sn,cs,aa,bb,cc,dd,x; void *old=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineSub;
AddSprite(4,1,0xc144,data_ov000_021deb7c,0);AddSprite(135,20,0xe16b,data_ov000_021deb20,0);AddSprite(196,20,0xe179,data_ov000_021deb20,0);
level=0;if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,76))level=Divide(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,76)-1,10)+1;
if(level>9){level=10;AddSprite(158,40,0x8081,gSpriteDesc8x8,0);AddSprite(166,40,0x8080,gSpriteDesc8x8,0);}else AddSprite(166,40,(u16)(((level+128)&1023)|0x8000),gSpriteDesc8x8,0);
AddSprite(179,40,0x9081,gSpriteDesc8x8,0);AddSprite(187,40,0x9080,gSpriteDesc8x8,0);
{s32 index0,position0;
for(index0=10-level;index0<10;index0++)AddSprite((u16)((9-index0)*4+158),37,0x60b1,gSpriteDesc8x8,0);}

if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28)){
n=Divide(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24),10);d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)-n*10;if(n>0){AddSprite(158,53,(u16)(((n+128)&1023)|32768),gSpriteDesc8x8,0);
}
AddSprite(166,53,(u16)(((d+128)&1023)|32768),gSpriteDesc8x8,0);

n=Divide(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28),10);d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28)-n*10;if(n>0){AddSprite(179,53,(u16)(((n+128)&1023)|36864),gSpriteDesc8x8,0);
}
AddSprite(187,53,(u16)(((d+128)&1023)|36864),gSpriteDesc8x8,0);

if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)>0){
if(!(data_ov000_021df600&1)){M2C_FIELD(data_ov000_021deb10,u16 *,12)=0x4400;data_ov000_021df600|=1;}
ratio=Divide(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,24)*312,M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,28));x=126+(ratio>>4);cs=gSinCosTable[1];
if((ratio<0?-ratio:ratio)>=2)den=ratio;else if(ratio>2)den=2;else{den=-2;if(ratio>=den)den=ratio;}
sn=gSinCosTable[0];
n=ratio;
if((ratio<0?-ratio:ratio)<2){if(ratio>2)n=2;else if(ratio< -2)n=-2;}
aa=Divide(cs<<4,n);bb=Divide((-sn)<<4,256);cc=Divide(sn<<4,den);dd=Divide(cs<<4,256);
SetSpriteQuad(2,(s16)aa,(s16)bb,(s16)cc,(s16)dd);
AddSprite((u16)x,46,0x60a8,data_ov000_021deb18,0);

}
}else {AddSprite(162,53,0x808a,gSpriteDesc8x8,0);
AddSprite(183,53,0x908a,gSpriteDesc8x8,0);
}
if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,20)){AddSprite(166,66,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,16)+128)&1023)|32768),gSpriteDesc8x8,0);
AddSprite(179,66,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,20)+128)&1023)|36864),gSpriteDesc8x8,0);
}
else {AddSprite(166,66,0x808a,gSpriteDesc8x8,0);
AddSprite(179,66,0x908a,gSpriteDesc8x8,0);
}
AddSprite(166,79,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,40)+128)&1023)|32768),gSpriteDesc8x8,0);

d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,44);if(d){if(d>0)n=11;else{n=10;d*=n-11;}
AddSprite(174,79,(u16)(((n+128)&1023)|40960),gSpriteDesc8x8,0);
AddSprite(181,79,(u16)(((d+128)&1023)|40960),gSpriteDesc8x8,0);
}
AddSprite(166,92,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,64)+128)&1023)|32768),gSpriteDesc8x8,0);
d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,68);if(d){if(d>0)n=11;else{n=10;d*=n-11;}
AddSprite(174,92,(u16)(((n+128)&1023)|40960),gSpriteDesc8x8,0);
AddSprite(181,92,(u16)(((d+128)&1023)|40960),gSpriteDesc8x8,0);
}
if(M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)==M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,52)){AddSprite(166,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)+128)&1023)|32768),gSpriteDesc8x8,0);
}else{
AddSprite(158,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,48)+128)&1023)|32768),gSpriteDesc8x8,0);
AddSprite(166,105,0x808a,gSpriteDesc8x8,0);
AddSprite(174,105,(u16)(((M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,52)+128)&1023)|32768),gSpriteDesc8x8,0);

}
d=M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,56);if(d){if(d>0)n=11;else{n=10;d*=n-11;}AddSprite(182,105,(u16)(((n+128)&1023)|40960),gSpriteDesc8x8,0);
AddSprite(189,105,(u16)(((d+128)&1023)|40960),gSpriteDesc8x8,0);
}
{s32 index1,position1;
for(index1=0,position1=39;index1<6;index1++,position1+=13){AddSprite(240,(u16)position1,(u16)(((176-M2C_FIELD(M2C_FIELD(a,void **,16)+index1*4,s32 *,100))&1023)|0x6000),gSpriteDesc8x8,0);
}
}
{s32 index2,position2;
for(index2=0,position2=145;index2<M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,252);index2++,position2+=15){n=M2C_FIELD(M2C_FIELD(a,void **,16)+index2*4,s32 *,124);if(n){n=func_020a72b0(0,n);AddSprite((u16)position2,121,(u16)(((n+391)&1023)|0xf000),gSpriteDesc16x16,index2);
}}
}
{s32 index3,position3;
for(index3=0,position3=145;index3<M2C_FIELD(M2C_FIELD(a,void **,16),s32 *,256);index3++,position3+=15){if(index3>=7)break;n=M2C_FIELD(M2C_FIELD(a,void **,16)+index3*4,s32 *,156);if(n){n=func_020a72b0(0,n);AddSprite((u16)position3,140,(u16)(((n+391)&1023)|0xf000),gSpriteDesc16x16,index3);
}}}

if(func_ov000_02176dcc(a)){
AddSprite(128,176,0x6120,data_02101f0c,1);
AddSprite(192,176,0x6128,data_02101f0c,1);
AddSprite(128,184,0x6130,data_02101f0c,1);
AddSprite(192,184,0x6138,data_02101f0c,1);
AddSprite(114,178,0xb140,gSpriteDesc16x16,1);

func_ov000_02174da4(0,182);
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
void func_ov000_021769dc(void *arg0) {
    M2C_UNK func_ov000_02175878(void *);
    M2C_UNK func_ov000_02175ed8(void *);
    void *temp_r2;
    temp_r2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_r2, s32 *, 4) = M2C_FIELD(temp_r2, s32 *, 8);
    func_ov000_02175ed8(arg0);
    func_ov000_02175878(arg0);
    M2C_FIELD(arg0, s32 *, 0) = 1 - M2C_FIELD(arg0, s32 *, 0);
}

void func_ov000_02176a0c(M2C_UNK arg0) {
    M2C_UNK DrawInfoPanelBackdrop(M2C_UNK);
    M2C_UNK func_ov000_021759b8(M2C_UNK);
    M2C_UNK Ov000Info_DrawUnitPanel(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x38) = 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x40) = 1;
    DrawInfoPanelBackdrop(arg0);
    func_ov000_021759b8(arg0);
    Ov000Info_DrawUnitPanel(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02176a9c(M2C_UNK arg0) {
    M2C_UNK DrawInfoPanelBackdrop();
    M2C_UNK Ov000Info_DrawUnitPanel(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    DrawInfoPanelBackdrop();
    Ov000Info_DrawUnitPanel(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = temp_r4;
}

#pragma opt_strength_reduction off
/* Fills a unit info entry's recommendation lists: six stat words from the
 * per-kind stats table, then up to eight unit kinds this kind is strong
 * against (score >= 90) and eight it is good against (score >= 70), each list
 * sorted by score, plus the two totals at +0x58/+0x5c. */
void BuildUnitRecommendations(s32 entry, s32 unitKind) {
extern s32 data_ov000_021ae40c[];extern u8 data_ov000_021ae2c8[];extern u8 data_ov000_021ae2cc[];
s32 func_020a799c(s32,s32,s32);
s32 otherKind,compare,score,tier,temp; s32 *statTable=(s32 *)((u8 *)data_ov000_021ae40c+unitKind*48);void *panel;
for(otherKind=0;otherKind<6;otherKind++){panel=M2C_FIELD(entry,void **,16);M2C_FIELD((u8 *)panel+otherKind*4,s32 *,0x64)=statTable[otherKind+(M2C_FIELD(panel,s32 *,16)>0?0:6)];}
for(otherKind=0;otherKind<8;otherKind++){M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0x7c)=0;M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0x9c)=0;}
M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)=0;
M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)=0;
for(otherKind=1;otherKind<27;otherKind++){
score=func_020a799c(otherKind,unitKind,0);
if(score>=90)tier=3;else if(score>=70)tier=2;else if(score>0)tier=1;else tier=0;
switch(tier){
case 3:
if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)<8){
M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)*4,s32 *,0x7c)=otherKind;
M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)*4,s32 *,0xbc)=score;
M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)++;
}break;
case 2:
if(M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)<8){
M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)*4,s32 *,0x9c)=otherKind;
M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)*4,s32 *,0xdc)=score;
M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)++;
}break;
}
}
for(otherKind=0;otherKind<M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc)-1;otherKind++)for(compare=otherKind+1;compare<M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0xfc);compare++){void *left=(u8 *)M2C_FIELD(entry,void **,16)+otherKind*4;void *right=(u8 *)M2C_FIELD(entry,void **,16)+compare*4;if(M2C_FIELD(left,s32 *,0xbc)<M2C_FIELD(right,s32 *,0xbc)){temp=M2C_FIELD(left,s32 *,0x7c);M2C_FIELD(left,s32 *,0x7c)=M2C_FIELD(right,s32 *,0x7c);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0x7c)=temp;temp=M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0xbc);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0xbc)=M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0xbc);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0xbc)=temp;}}
for(otherKind=0;otherKind<M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100)-1;otherKind++)for(compare=otherKind+1;compare<M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x100);compare++){void *left=(u8 *)M2C_FIELD(entry,void **,16)+otherKind*4;void *right=(u8 *)M2C_FIELD(entry,void **,16)+compare*4;if(M2C_FIELD(left,s32 *,0xdc)<M2C_FIELD(right,s32 *,0xdc)){temp=M2C_FIELD(left,s32 *,0x9c);M2C_FIELD(left,s32 *,0x9c)=M2C_FIELD(right,s32 *,0x9c);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0x9c)=temp;temp=M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0xdc);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+otherKind*4,s32 *,0xdc)=M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0xdc);M2C_FIELD((u8 *)M2C_FIELD(entry,void **,16)+compare*4,s32 *,0xdc)=temp;}}
{s32 offset=unitKind*12; s32 a,b; a=*(volatile s32 *)(data_ov000_021ae2c8+offset);b=*(volatile s32 *)(data_ov000_021ae2cc+offset);M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x58)=a;M2C_FIELD(M2C_FIELD(entry,void **,16),s32 *,0x5c)=b;}
}
u8 func_ov000_02176dcc(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) == 0) {
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

s32 func_ov000_02176e08(s32 arg0) {
    switch (arg0) {
    case 0xE:
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 0;
    }
}

