/* 6 functions from 0x0216D2B4 to 0x0216E178 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[6]; } UnitPaletteLookup;
static inline void ArmyInfo_LoadTile(s32 tile, u32 resource, s32 palette) {
 void func_0209b26c(s32,s32,s32,u32,s32,s32);
 func_0209b26c(3,tile,1,resource,0x1000,palette);
}
static inline void *ArmyInfo_UseEngine(void **current, void *engine) {
 *current=engine;
 return engine;
}
static inline void ArmyInfo_SelectEngine(void *engine) {
 extern void *gCur3DSpriteEngine;
 gCur3DSpriteEngine=engine;
}

#pragma opt_strength_reduction off
#pragma opt_instruction_scheduling off
void func_ov000_0216d2b4(void *arg0) {
extern void *gArmyInfoState;extern void **gCurrentMap;
extern const u8 data_ov000_021adcfc[];
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
extern u8 gSpriteDesc16x16[],gSpriteDesc8x8[],gSpriteDesc16x8[],data_02101f0c[];
s32 func_020a334c(s32);void AddSprite(u16,u16,u16,void *,s32);
s32 y,v,topIndex,topX,x,unit,owner,i,palette,tile,t,colorIndex;void *old,*p; u8 colors[6]; u8 c0,c1,c2,c3,c4,c5;
p=gArmyInfoState;unit=M2C_FIELD(p,u8 *,M2C_FIELD(p,u8 *,13));owner=func_020a334c(unit);
c0=data_ov000_021adcfc[0];c1=data_ov000_021adcfc[1];c2=data_ov000_021adcfc[2];c3=data_ov000_021adcfc[3];c4=data_ov000_021adcfc[4];c5=data_ov000_021adcfc[5];colors[1]=c1;colors[3]=c3;colors[5]=c5;
p=*gCurrentMap;colorIndex=M2C_FIELD(p+unit*140,u8 *,0x67c1);

p=gArmyInfoState;M2C_FIELD(p,s16 *,18)+=M2C_FIELD(p,s16 *,20);
colors[0]=c0;colors[2]=c2;colors[4]=c4;palette=colors[colorIndex];
p=gArmyInfoState;if(M2C_FIELD(p,s16 *,18)<0)M2C_FIELD(p,s16 *,18)=0;
p=gArmyInfoState;if(M2C_FIELD(p,s16 *,18)>12)M2C_FIELD(p,s16 *,18)=12;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
for(topIndex=0,topX=80,tile=352;topIndex<M2C_FIELD(gArmyInfoState,u8 *,12);topIndex++,topX+=24,tile+=4){
t=M2C_FIELD(*((void **)gCur3DSpriteEngine),u16 *,0);
AddSprite((u16)(topX&511),168,(u16)(((tile>>((u32)(t<<17)>>30))&1023)|((u32)((topIndex+7)<<28)>>16)),gSpriteDesc16x16,0);
}
if(M2C_FIELD(gArmyInfoState,u8 *,16)==1){
s32 mx1=511,mt1=1023,mx2=511,mt2=1023,mx3=511,mt3=1023,mx4=511,mt4=1023,mx5=511,mt5=1023,mx6=511,mt6=1023,mx7=511,mt7=1023;
for(i=0;i<27;i++){
x=i%4*64;y=i/4*20;v=func_020a866c(i);if(!v)continue;
tile=func_020a72b0(0,v)+437;
AddSprite((u16)((x+2)&mx1),(u8)(y+18),(u16)(((tile)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt1)|((u32)((palette+11)<<28)>>16)),gSpriteDesc16x16,0);

if((s8)func_020a2868(v,unit,owner)>0){AddSprite((u16)((x+28)&mx2),(u8)(y+19),(u16)(((432)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt2)|0x6000),gSpriteDesc8x8,0);
}
if((s8)func_020a28f4(v,unit,owner)>0){AddSprite((u16)((x+28)&mx3),(u8)(y+28),(u16)(((432)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt3)|0x6000),gSpriteDesc8x8,0);
}
t=(s8)func_020a296c(v,unit,owner);
if(t==1){AddSprite((u16)((x+47)&mx4),(u8)(y+19),(u16)(((433)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt4)|0x6000),gSpriteDesc16x8,0);
}
else if(t==2){AddSprite((u16)((x+47)&mx5),(u8)(y+19),(u16)(((435)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt5)|0x6000),gSpriteDesc16x8,0);
}
t=(s8)func_020a29e4(v,unit,owner);
if(t==1){AddSprite((u16)((x+47)&mx6),(u8)(y+28),(u16)(((433)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt6)|0x6000),gSpriteDesc16x8,0);
}
else if(t==2){AddSprite((u16)((x+47)&mx7),(u8)(y+28),(u16)(((435)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&mt7)|0x6000),gSpriteDesc16x8,0);
}
}
}
gCur3DSpriteEngine=g3DSpriteEngineSub;
if(M2C_FIELD(gArmyInfoState,s16 *,18)<=0)func_ov000_0216d1c8();
x=EaseInterpolate(4,-235,13,M2C_FIELD(gArmyInfoState,s16 *,18),12);
AddSprite((u16)((x)&511),(u8)(8),(u16)(((384)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x7000),gSpriteDesc16x16,0);

if(M2C_FIELD(gArmyInfoState,s16 *,18)<=0)func_ov000_0216d23c();
x=EaseInterpolate(4,-214,34,M2C_FIELD(gArmyInfoState,s16 *,18),12);
DrawTileRow((u16)(x&511),8,128,(u16)(((388>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&1023)|0x2000),0);
if(M2C_FIELD(gArmyInfoState,s16 *,18)<=0)func_ov000_0216d130();
x=EaseInterpolate(4,-240,8,M2C_FIELD(gArmyInfoState,s16 *,18),12);
AddSprite((u16)((x)&511),(u8)(24),(u16)(((320)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x+64)&511),(u8)(24),(u16)(((328)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x)&511),(u8)(32),(u16)(((336)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x+64)&511),(u8)(32),(u16)(((344)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x)&511),(u8)(40),(u16)(((352)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x+64)&511),(u8)(40),(u16)(((360)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x)&511),(u8)(48),(u16)(((368)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);
AddSprite((u16)((x+64)&511),(u8)(48),(u16)(((376)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0x6000),data_02101f0c,0);

gCur3DSpriteEngine=old;
p=gArmyInfoState;if(M2C_FIELD(p,s16 *,18)<=0){M2C_FIELD(p,s16 *,20)=1;ArmyInfo_DrawFaceSub();}
p=gArmyInfoState;if(M2C_FIELD(p,s16 *,18)>=12&&M2C_FIELD(p,s16 *,20)==1)M2C_FIELD(p,s16 *,20)=0;
p=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
x=EaseInterpolate(4,-240,0,M2C_FIELD(gArmyInfoState,s16 *,18),12);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,56)=x;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,64)=0;
gCur3DSpriteEngine=p;
}
#pragma opt_instruction_scheduling off
void func_ov000_0216dd0c(void) {
 extern void *gArmyInfoState;
 extern u8 gMovementCostTable[];
 extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
 extern u8 data_ov000_021b8860[],data_ov000_021b8874[],data_ov000_021b888c[],data_ov000_021b88a4[],data_ov000_021b88b8[],data_ov000_021b88d0[];
 M2C_UNK SetArmyInfoFileDirectory(void);
 void func_0209bfa8(void);
 void *GetLocalizedFileName(void *);
 void OpenNarcArchive(void *);void CloseNarcArchive(void);
 void LoadNarcFileDecompressed(void *,void *);
 void func_01ff9d38(s32);void func_01ff9d88(s32);
 void func_0209bbd0(s32,s32,s32,s32,s32,s32);
 void func_0209b26c(s32,s32,s32,u32,s32,s32);
 u8 *state=gArmyInfoState;
 void *record=gMovementCostTable+M2C_FIELD(state+state[13],u8 *,4)*0x9c;
 void *saved,*engine;
 SetArmyInfoFileDirectory();func_0209bfa8();
 if(M2C_FIELD(gArmyInfoState,u8 *,16)==0) {
 OpenNarcArchive(GetLocalizedFileName(data_ov000_021b8860));
 saved=gCur3DSpriteEngine;engine=g3DSpriteEngineMain;gCur3DSpriteEngine=engine;
 LoadNarcFileDecompressed(GetLocalizedFileName(data_ov000_021b8874),M2C_FIELD(engine,void **,0x28));
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 func_01ff9d38(1);
 M2C_FIELD(g3DSpriteEngineMain,u8 *,0x46)|=2;
 func_0209bbd0(2,2,1,M2C_FIELD(record,s32 *,8),0x1000,1);
 func_0209bbd0(2,12,1,M2C_FIELD(record,s32 *,12),0x1000,0xa1);
 M2C_FIELD(g3DSpriteEngineMain,u8 *,0x46)|=2;
 gCur3DSpriteEngine=g3DSpriteEngineSub;engine=g3DSpriteEngineSub;
 LoadNarcFileDecompressed(GetLocalizedFileName(data_ov000_021b888c),M2C_FIELD(engine,void **,0x28));
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 func_01ff9d88(1);
 M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;
 func_0209bbd0(2,8,1,M2C_FIELD(record,s32 *,4),0x1000,0x81);
 M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;
 gCur3DSpriteEngine=saved;CloseNarcArchive();
 }
 if(M2C_FIELD(gArmyInfoState,u8 *,16)==1) {
 OpenNarcArchive(GetLocalizedFileName(data_ov000_021b88a4));
 saved=gCur3DSpriteEngine;engine=g3DSpriteEngineMain;gCur3DSpriteEngine=engine;
 LoadNarcFileDecompressed(GetLocalizedFileName(data_ov000_021b88b8),M2C_FIELD(engine,void **,0x28));
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
 func_01ff9d38(1);
 M2C_FIELD(g3DSpriteEngineMain,u8 *,0x46)|=2;
 engine=g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
 LoadNarcFileDecompressed(GetLocalizedFileName(data_ov000_021b88d0),M2C_FIELD(engine,void **,0x28));
 M2C_FIELD(gCur3DSpriteEngine,u8 *,(s32)0x46)|=4;
 func_01ff9d88(1);
 M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;
 func_0209b26c(3,14,1,0xf0000097,0x1000,1);
 func_0209b26c(3,16,1,0xf0000098,0x1000,0x21);
 func_0209b26c(3,18,1,0xf0000099,0x1000,0x41);
 func_0209b26c(3,20,1,0xf000009a,0x1000,0x61);
 M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;
 gCur3DSpriteEngine=saved;CloseNarcArchive();
 }
}
void func_ov000_0216e054(void) {
    extern void *gArmyInfoState;
    M2C_UNK SetArmyInfoFileDirectory(void);
    M2C_UNK FocusSpriteSlotById(u8);
    M2C_UNK ArmyInfo_DrawFaceMain(void);
    void func_ov000_0216dd0c(void);
    SetArmyInfoFileDirectory();
    FocusSpriteSlotById(M2C_FIELD(gArmyInfoState, u8 *, 0xD));
    ArmyInfo_DrawFaceMain();
    M2C_FIELD(gArmyInfoState, u8 *, 0x11) = 1 - M2C_FIELD(gArmyInfoState, u8 *, 0x11);
    M2C_FIELD(gArmyInfoState, s16 *, 0x14) = -1;
    func_ov000_0216dd0c();
}

void func_ov000_0216e09c(u8 arg0) {
    extern void *gArmyInfoState;
    M2C_FIELD(gArmyInfoState, u8 *, 0xD) = arg0;
    M2C_FIELD(gArmyInfoState, u8 *, 0xE) = (u8) M2C_FIELD((gArmyInfoState + M2C_FIELD(gArmyInfoState, u8 *, 0xD)), u8 *, 4);
    M2C_FIELD(gArmyInfoState, u8 *, 0xF) = (u8) M2C_FIELD(gArmyInfoState, u8 *, 0xE);
}

void func_ov000_0216e0d0(u8 *arg0) {
    extern void *gArmyInfoState;
    M2C_UNK PlaySoundEffect(s32);
    void func_ov000_0216e054(void);
    if (M2C_FIELD(gArmyInfoState, u8 *, 0xD) == *arg0) return;
    PlaySoundEffect(0x10019);
    func_ov000_0216e09c(*arg0);
    func_ov000_0216e054();
}

void func_ov000_0216e110(void) {
    extern void *gArmyInfoState;
    extern M2C_UNK data_ov000_021b8790;
    M2C_UNK func_020b22a4(s32, M2C_UNK, M2C_UNK *, s32);
    M2C_UNK func_020b1c78(u8);
    s32 i;
    s32 x;
    i = 0;
    if (i < M2C_FIELD(gArmyInfoState, u8 *, 0xC)) {
        x = 0x50;
        do {
            func_020b22a4(x, 0xA8, &data_ov000_021b8790, i);
            i++;
            x += 0x18;
        } while (i < M2C_FIELD(gArmyInfoState, u8 *, 0xC));
    }
    func_020b1c78(M2C_FIELD(gArmyInfoState, u8 *, 0xD));
}

