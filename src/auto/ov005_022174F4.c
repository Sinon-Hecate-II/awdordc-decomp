/* 9 functions from 0x022174F4 to 0x02218008 (ov005), found by ds-decomp. */
#include "common.h"
extern void *gOv005MenuState, *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
extern u8 data_02101f0c[];
#define STATE gOv005MenuState
#define ENGINE M2C_FIELD(gCur3DSpriteEngine,void**,0)
#define SIZE ((u32)(M2C_FIELD(ENGINE,u16*,0)<<17)>>30)
#define ATTR(tile,pal) ((u16)(((tile)>>SIZE & 0x3ff)|(pal)))

void func_ov005_022174f4(void) {
extern void *gOv005MenuState,*gCur3DSpriteEngine,*g3DSpriteEngineSub;
s32 value=M2C_FIELD(gOv005MenuState,s16 *,0x10);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineSub;
if(func_020bf894(M2C_FIELD(gOv005MenuState,s16 *,0x10))) {
MI_CpuFill32(0,M2C_FIELD(gCur3DSpriteEngine,s32 *,0xc),0x40);
func_020985b0(value,8,M2C_FIELD(gCur3DSpriteEngine,s32 *,0xc)+0x40);
func_02098a34(value,8,2,0,0);
func_02098844(8,12,0,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20),1,0,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
SetOv005FileDirectory();
}else{
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20)+0x18,0x14,0x18);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
}
gCur3DSpriteEngine=saved;
}

void Ov005RefreshEntryLabel(void) {
extern void *gOv005MenuState,*gCur3DSpriteEngine,*g3DSpriteEngineMain;
s32 value=M2C_FIELD(gOv005MenuState,s16 *,0x10);
void *saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
if(func_020bf894(M2C_FIELD(gOv005MenuState,s16 *,0x10)))
func_02098d78(value,0x8380,6);
else MI_CpuFill32(0,M2C_FIELD(g3DSpriteEngineMain,s32 *,0x1c)+0x8380,0x20);
gCur3DSpriteEngine=saved;
M2C_FIELD(gOv005MenuState,s16 *,0x18)=-1;
}

#pragma opt_strength_reduction off
void func_ov005_022176a0(void){
s32 func_020bf894(s32);void AddSprite(u16,u16,u16,void*,s32);
void func_02098cb8(s32,s16,s16,u16,s32,s32);void func_02098dc0(s16,s16,u16,s32);
void func_02088e84(void*,s32,s32,s32,s32);u32 func_020aae10(void*);u32 func_020aae44(void*);
void func_02087d84(void*,s32,s16,s16,u16,u16);void func_ov005_02217440(void);
s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 i; s16 x,y;void *saved;
M2C_FIELD(STATE,s16*,0x16)+=M2C_FIELD(STATE,s16*,0x18);
if(M2C_FIELD(STATE,s16*,0x16)<0)M2C_FIELD(STATE,s16*,0x16)=0;
if(M2C_FIELD(STATE,s16*,0x16)>12)M2C_FIELD(STATE,s16*,0x16)=12;
{ void *saved=gCur3DSpriteEngine; s32 tile=0x49c;
for(i=0;i<12;tile+=24,i++){
x=M2C_FIELD(STATE,s16*,8)+((i%4)*50+30);y=(i/4)*18+87;
gCur3DSpriteEngine=g3DSpriteEngineMain;
AddSprite((u16)((x+2)&511),(u8)(y+1),ATTR(0x40c,0x7800),data_02101f0c,0);
AddSprite((u16)((x+2)&511),(u8)(y+9),ATTR(0x414,0x7800),data_02101f0c,0);
if(func_020bf894(i+1))func_02098cb8(0,x,y,(u16)(((i<<12)&0xffff)|0x400|((tile)>>SIZE&0x3ff)),0,0);
gCur3DSpriteEngine=saved;
}
}
{s32 delta; s16 px; void *p; i=0;delta=14;
for(;i<4;i++,delta+=60){
px=M2C_FIELD(STATE,s16*,10)+delta;
p=M2C_FIELD(STATE+i*4,void**,0x2c);
func_02088e84(p,px,90,px,90);
if((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)){s16 y=M2C_FIELD(p,s16*,0x52);s16 x=M2C_FIELD(p,s16*,0x50);u32 w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
M2C_FIELD(p,s16*,0x34)=px;M2C_FIELD(p,s16*,0x36)=90;
if((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)){s16 y=M2C_FIELD(p,s16*,0x52);s16 x=M2C_FIELD(p,s16*,0x50);u32 w=func_020aae10(p);func_02087d84(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p));}
}
}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
if(func_020bf894(M2C_FIELD(STATE,s16*,14)+1))func_02098dc0(98,32,ATTR(0x41c,0x6000),0);
gCur3DSpriteEngine=g3DSpriteEngineSub;
if(M2C_FIELD(STATE,s16*,0x16)<=0)func_ov005_02217440();
{
s16 pos=EaseInterpolate(4,-240,8,M2C_FIELD(STATE,s16*,0x16),12);
u32 left=pos&511; u32 right;
AddSprite((u16)left,24,ATTR(320,0x6000),data_02101f0c,0);
right=(pos+64)&511;
AddSprite((u16)right,24,ATTR(328,0x6000),data_02101f0c,0);
AddSprite((u16)left,32,ATTR(336,0x6000),data_02101f0c,0);
AddSprite((u16)right,32,ATTR(344,0x6000),data_02101f0c,0);
AddSprite((u16)left,40,ATTR(352,0x6000),data_02101f0c,0);
AddSprite((u16)right,40,ATTR(360,0x6000),data_02101f0c,0);
AddSprite((u16)left,48,ATTR(368,0x6000),data_02101f0c,0);
AddSprite((u16)right,48,ATTR(376,0x6000),data_02101f0c,0);
}
gCur3DSpriteEngine=saved;
if(M2C_FIELD(STATE,s16*,0x16)<=0){M2C_FIELD(STATE,s16*,0x18)=1;func_ov005_022174f4();}
if(M2C_FIELD(STATE,s16*,0x16)>=12&&M2C_FIELD(STATE,s16*,0x18)==1)M2C_FIELD(STATE,s16*,0x18)=0;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
{s32 offset=EaseInterpolate(4,-240,0,M2C_FIELD(STATE,s16*,0x16),12);M2C_FIELD(ENGINE,s16*,0x38)=offset;}
M2C_FIELD(ENGINE,s16*,0x40)=0;
gCur3DSpriteEngine=saved;
}
#pragma opt_strength_reduction reset
void func_ov005_02217dc0(u8 *arg0) {
extern void *gKeyState,*gOv005MenuState;
u32 old=*arg0; u16 keys=M2C_FIELD(gKeyState,u16 *,2);s32 value=old;
if(keys&0x40)value=old-4;
else if(keys&0x80)value=old+4;
else if(keys&0x20)value=old-1;
else if(keys&0x10)value=old+1;
if(value<0)value+=12;
if(value>11)value-=12;
if(value!=old)FocusSpriteSlotById(value);
M2C_FIELD(gOv005MenuState,s16 *,0xe)=value;
M2C_FIELD(gOv005MenuState,s16 *,0x10)=M2C_FIELD(gOv005MenuState,s16 *,0xe)+1;
}

void func_ov005_02217e4c(u8 *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    extern void *gOv005MenuState;
    M2C_FIELD(gOv005MenuState, s16 *, 0xE) = (s16) *arg0;
    M2C_FIELD(gOv005MenuState, s16 *, 0x10) = (s16) (M2C_FIELD(gOv005MenuState, s16 *, 0xE) + 1);
    PlaySoundEffect(0x10019);
}

void func_ov005_02217e84(u8 *arg0) {
extern void *gKeyState;
u16 keys;s32 old; s32 value;
old=*arg0;keys=M2C_FIELD(gKeyState,u16 *,2);value=old;
if(keys&0x20) {if(old<=0) {if(M2C_FIELD(gKeyState,u16 *,0)&0x20)value=old-1;}else value=old-1;}
else if(keys&0x10) {if(old>=3) {if(M2C_FIELD(gKeyState,u16 *,0)&0x10)value=old+1;}else value=old+1;}
if(value<0)value=3;
if(value>3)value=0;
if(value!=old)FocusSpriteSlotById(value);
func_ov005_02217334(value);
}

void func_ov005_02217f18(u8 *arg0) {
extern void *gOv005MenuState;
M2C_FIELD(gOv005MenuState,s16 *,0x12)=*arg0;
func_ov005_02217334(*arg0);
func_020bf8fc(M2C_FIELD(gOv005MenuState,s16 *,0x10),M2C_FIELD(gOv005MenuState,s16 *,0x12));
Ov005DrawEntryList(M2C_FIELD(gOv005MenuState,s16 *,0x10));
PlaySoundEffect(0x10019);
}

void func_ov005_02217f6c(void) {
M2C_UNK func_020b22a4(s32,s32,M2C_UNK *,s32);
extern M2C_UNK data_ov005_02220800;
s32 i=0;
do {
func_020b22a4((i%4)*50+30,(i/4)*18+87,&data_ov005_02220800,i);
i++;
}while(i<12);
}

void Ov005AddDetailSprites(void) {
    M2C_UNK func_020b22a4(s32, M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK data_ov005_02220828;
    s32 var_r6;
    s32 var_r7;

    var_r6 = 0;
    var_r7 = 0xE;
    do {
        func_020b22a4(var_r7, 0x5A, &data_ov005_02220828, var_r6);
        var_r6 += 1;
        var_r7 += 0x3C;
    } while (var_r6 < 4);
}

