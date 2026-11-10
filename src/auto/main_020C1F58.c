/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 flag0:1, flag1:1, flags:6; } FlagsC253c;
typedef struct { u16 pad:13, shift:2, last:1; } ModeC253c;
extern void *gCur3DSpriteEngine;
extern u8 gSinCosTable[];
extern u8 gSpriteDesc32x16[];
extern u8 data_027e00b4[];
extern u8 data_02129780[];
extern u8 data_027e007c[];

/* Initialise the CO "occupation" cut-in: open the /occupation archive, set up the
 * 3D sprite object, load the CO's .narc/.cg/.sc/.cl portrait and frame textures,
 * then restore the sprite engine and mark the screen as ready. */
M2C_UNK InitOccupationScreen(u8 *screen){
extern u8 sOccupationPath[];   /* "/occupation" */
extern u8 data_02129778[];   /* sprite animation descriptor */
extern u8 sOccupationObjectName[];   /* "res_occupation_obj" */
extern u8 sOccupationPlateFile[];   /* "plate.cg" */
extern u8 sOccupationCommonFile[];   /* "obj_common.cl" */
extern u8 sNarcExt[];   /* ".narc" */
extern u8 sCgExt[];   /* ".cg" */
extern u8 sScExt[];   /* ".sc" */
extern u8 sClExt[];   /* ".cl" */
extern u8 sFrameNarcFile[];   /* "frame.narc" */
extern u8 sFrameCgFile[];   /* "frame.cg" */
extern u8 sFrameScFile[];   /* "frame.sc" */
extern u8 sFrameClFile[];   /* "frame.cl" */
extern void *g3DSpriteEngineMain,*gCurrentMap;
void SetFileDirectory(void *);void func_020a92bc(void *,s32);void *GetLocalizedFileName(void *);void *func_02080e30(void *,s32);void func_0207c780(void *,void *);void func_020e35cc(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);M2C_UNK func_01ff9ce8(s32);void *GetCOAssetName(s32);void StringCopy(void *,void *);void func_02068d68(void *,void *);void func_020814e4(void *);void func_02081590(void *,void *);void func_020815d4(void *,void *,s32,s32);void func_02081528(void);void func_01ff85b8(void *,s32,s32);void func_020815fc(void *,s32,s32);void func_020808dc(void *,s32,s32,s32);void func_0207b764(s32,s32);
u8 path[64];
u8 *objectRes;
void *savedEngine;
u16 *volatile statReg0;
u16 *volatile statReg1;
u16 *volatile statReg2;
u16 *volatile statReg3;
u16 *volatile statReg4;
u16 *volatile statReg5;
u16 *volatile statReg6;
u16 *volatile statReg7;
u16 *volatile statReg8;
u16 *volatile statReg9;
u16 *volatile statReg10;
u16 *volatile statReg11;
u16 *volatile statReg12;
u16 *volatile statReg13;
u16 *volatile statReg14;
u16 *volatile statReg15;

SetFileDirectory(sOccupationPath);
M2C_FIELD(*(void **)(screen+60),u16*,18)=860;
M2C_FIELD(*(void **)(screen+60),u8*,22)=16;
M2C_FIELD(*(void **)(screen+60),u8*,20)=32;
M2C_FIELD(*(void **)(screen+60),u8*,23)=24;
func_020a92bc(*(void **)(screen+60),20);
M2C_FIELD(*(void **)(screen+60),u8*,33)=11;
M2C_FIELD(*(void **)(screen+60),u8*,32)=(M2C_FIELD(*(void **)(screen+60),u8*,32)&~224)|32;
M2C_FIELD(*(void **)(screen+60),void **,36)=data_02129778;
M2C_FIELD(*(void **)(screen+60),u8*,40)&=~224;

/* switch to the CO sprite engine and configure its first display register */
savedEngine=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
statReg0=*(u16 **)gCur3DSpriteEngine;*statReg0=*statReg0|16;
statReg1=*(u16 **)gCur3DSpriteEngine;*statReg1=*statReg1|32;
statReg2=*(u16 **)gCur3DSpriteEngine;*statReg2=*statReg2|64;
statReg3=*(u16 **)gCur3DSpriteEngine;*statReg3=*statReg3&~128;
statReg4=*(u16 **)gCur3DSpriteEngine;*statReg4=*statReg4|256;
*(volatile u16 *)0x4000060=(*(volatile u16 *)0x4000060&~0x3000)|8;
statReg5=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg5=(*statReg5&~192)|64;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8*,81)=16;M2C_FIELD(*(void **)gCur3DSpriteEngine,u8*,82)=0;statReg6=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg6=*statReg6&~1;statReg7=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg7=*statReg7&~2;statReg8=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg8=*statReg8&~4;statReg9=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg9=*statReg9&~8;statReg10=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg10=*statReg10&~16;statReg11=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg11=*statReg11|256;statReg12=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg12=*statReg12&~512;statReg13=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg13=*statReg13&~1024;statReg14=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg14=*statReg14&~2048;statReg15=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*statReg15=*statReg15&~4096;

objectRes=func_02080e30(GetLocalizedFileName(sOccupationObjectName),1);
func_0207c780(objectRes,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x6b80);
func_0207c780(objectRes+0x3c0,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x7f80);
if(screen[54]==0)func_0207c780(objectRes+0x478,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);else func_0207c780(objectRes+0x690,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);
func_0207c780(objectRes+0x92c,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8480);
func_020e35cc(objectRes);
LoadDecompressedFileTo(sOccupationPlateFile,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x9d80);
LoadFileToSpriteBuffer(sOccupationCommonFile,0x360,64);
func_01ff9ce8(2);

/* build "<CO name>.narc" and load the CO's portrait archive */
StringCopy(path,GetCOAssetName((*(u8 **)(screen+64))[1]));
func_02068d68(path,sNarcExt);
func_020814e4(path);

/* "<CO name>.cg" -> background frame slot */
StringCopy(path,GetCOAssetName((*(u8 **)(screen+64))[1]));
func_02068d68(path,sCgExt);
func_02081590(path,M2C_FIELD(gCur3DSpriteEngine,void **,20));

/* "<CO name>.sc" -> portrait slot */
StringCopy(path,GetCOAssetName((*(u8 **)(screen+64))[1]));
func_02068d68(path,sScExt);
func_02081590(path,M2C_FIELD(gCur3DSpriteEngine,void **,40));

/* "<CO name>.cl" -> palette data */
StringCopy(path,GetCOAssetName((*(u8 **)(screen+64))[1]));
func_02068d68(path,sClExt);
func_020815d4(path,*(void **)(screen+76),0,128);
func_02081528();
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,40),1024,8192);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;
func_01ff9ce8(1);

/* load the shared frame.narc and its .cg/.sc/.cl parts */
func_020814e4(sFrameNarcFile);
func_02081590(sFrameCgFile,M2C_FIELD(gCur3DSpriteEngine,void **,16));
func_02081590(sFrameScFile,M2C_FIELD(gCur3DSpriteEngine,void **,36));
func_020815fc(sFrameClFile,32,32);
func_02081528();
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void **,36),32,32,1);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;
gCur3DSpriteEngine=savedEngine;
screen[53]=1;
func_0207b764(M2C_FIELD(*(void **)gCurrentMap,s16*,0x52dc),M2C_FIELD(*(void **)gCurrentMap,s16*,0x52de));
}

/* Draws the CO occupation cut-in for one frame: tints the panel palette toward
 * the CO's colour, stamps the portrait animation, sets the cut-in quad and
 * queues the panel, gauge and ability sprites. */
void DrawOccupationScreen(u8 *panel){
void UpdateSpriteAnimation(void *); s32 GetSpriteAnimValue(void *); void func_01ff9e44(void *,s32,s32);
s32 GetCOFaceIndex(s32); s32 func_020ae354(s32,s32,u8,u8);
void BlendPalette(void *,s32,u8,u8,s32); s32 func_0207c8ec(s32,s32);
void SetSpriteQuad(s32,s16,s16,s16,s16); void func_020a92bc(void *,s32); void func_020a94fc(void *);
void AddSprite(s32,u16,u16,void *,s32); s32 GetCOPaletteOffset(s32); s32 GetCOPortraitOffset(s32);
s32 scratch,scaleB,scaleC,scaleD,sine,cosine,q0,q1,q2,q3; u8 fade,row; s16 spriteY;
if(!panel[0x35])return;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3c)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x44)=0xffcb;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=0xffcb;
UpdateSpriteAnimation(*(void **)(panel+68)); fade=GetSpriteAnimValue(*(void **)(panel+68));
func_01ff9e44(*(void **)(panel+76),64,128);
scratch=GetCOFaceIndex((*(u8 **)(panel+64))[3]);
if((*(u8 **)(panel+64))[2]==0)BlendPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,scratch,16-fade,fade,128);
else{q0=GetCOFaceIndex((*(u8 **)(panel+64))[2]);q0=func_020ae354(q0,scratch,16-fade*2,fade*2);BlendPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,q0,11,5,128);}
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;
UpdateSpriteAnimation(*(void **)(panel+72));
scratch=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); cosine=((s16 *)gSinCosTable)[1];
scaleB=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); sine=((s16 *)gSinCosTable)[0];
scaleC=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); scaleD=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72)))));
q0=func_0207c8ec(cosine<<4,scaleD);q1=func_0207c8ec((-sine)<<4,scaleC);q2=func_0207c8ec(sine<<4,scaleB);q3=func_0207c8ec(cosine<<4,scratch);
SetSpriteQuad(0,q0,q1,q2,q3);
if(((FlagsC253c *)(panel+80))->flag0){func_020a92bc(*(void **)(panel+60),(*(u8 **)(panel+64))[5]);{u16 *q=*(u16 **)(panel+60);q[3]=102;q[4]=59;}func_020a94fc(*(void **)(panel+60));}
if(((FlagsC253c *)(panel+80))->flag1)AddSprite(104,857,((0x3fc>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,gSpriteDesc32x16,11);
if(((FlagsC253c *)(panel+80))->flags)AddSprite(54,821,((0x404>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_027e00b4,11);
scratch=GetCOPaletteOffset((*(u8 **)(panel+64))[1]);
AddSprite(76,117,((scratch>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_02129780,11);
for(row=0;row<20;row++){spriteY=row*-4+130;
if(row<panel[57])scratch=GetCOPortraitOffset((*(u8 **)(panel+64))[3]);else scratch=GetCOPortraitOffset((*(u8 **)(panel+64))[2]);
if(scratch!=65535)AddSprite(156,(spriteY&255)|1024,((scratch>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xc000,data_027e007c,11);
}
}

/* Advances the CO occupation cut-in by one frame: lets A/Start or a touch
 * skip it, plays the per-row voice sounds, arms the sprite effects when the
 * portrait starts, plays the closing voice and bumps the frame counter. */
void UpdateOccupationScreen(OccupationEffect *effect){
void func_01ffa6fc(void *);
void func_020c32bc(s32,s32);
void PlaySoundEffect(s32);
u32 Modulo(u32,u32);
s32 IsPlayerHuman(s32);
extern u16 *gKeyState;
extern u8 *gTouchState;
u8 *co;
u16 *sprite;
if(effect->frame==effect->endFrame){func_01ffa6fc(effect);return;}
if((*gKeyState&(KEY_A|KEY_START))||gTouchState[TOUCH_STARTED]){
co=effect->co;
if(co[5]==20 && effect->frame<effect->startFrame+7)func_020c32bc(co[0],0);
func_01ffa6fc(effect);return;
}
if(effect->frame==6){
PlaySoundEffect((effect->progress+42)|0x10000);effect->progress++;
}else if(effect->frame>6 && effect->progress<effect->co[5] && Modulo(effect->frame-6,3)==0){
PlaySoundEffect((effect->progress+42)|0x10000);effect->progress++;
}
if(effect->frame==effect->startFrame){
if(effect->co[5]==20){
effect->flags=(effect->flags&~0xfc)|4;
sprite=effect->spriteA;sprite[7]=0;sprite[8]=5;sprite[6]=8;sprite[1]=sprite[2];
}else{
effect->flags=(effect->flags&~1)|1;effect->flags|=2;
}
sprite=effect->spriteB;sprite[7]=0x1c0;sprite[8]=0x100;sprite[6]=5;sprite[1]=sprite[2];
}
co=effect->co;
if(co[5]==20){
if(effect->frame==effect->startFrame+8)func_020c32bc(co[0],0);
}else if(effect->frame==effect->startFrame+5){
if(IsPlayerHuman(co[0]))PlaySoundEffect(0xe0);else PlaySoundEffect(0xe2);
}
effect->frame++;
}

void func_020c2ca0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, u8 *, 0x35) = 0;
}

void func_020c2cec(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_020c2e10(void) {
    M2C_UNK InitOccupationScreen();
    InitOccupationScreen();
}

void func_020c2e1c(void) {
    void func_020c2cec(void);
    func_020c2cec();
}

void func_020c2e28(void) {
    void func_020c2ca0();
    func_020c2ca0();
}

void func_020c2e34(void) {
    void DrawOccupationScreen();
    DrawOccupationScreen();
}

void func_020c2e40(void) {
    void UpdateOccupationScreen();
    UpdateOccupationScreen();
}

