/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
typedef struct { u8 flag0:1, flag1:1, flags:6; } FlagsC253c;
typedef struct { u16 pad:13, shift:2, last:1; } ModeC253c;
extern void *gCur3DSpriteEngine;
extern u8 gSinCosTable[];
extern u8 gSpriteDesc32x16[];
extern u8 gSpriteDesc64x32[];
extern u8 data_02129780[];
extern u8 gSpriteDesc32x8[];

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
void SetFileDirectory(void *);void SetTextSpriteValue(void *,s32);void *GetLocalizedFileName(void *);void *LoadFileToBuffer(void *,s32);void LoadGraphicsBlock(void *,void *);void HeapFreeBlock(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);M2C_UNK Clear3DSpriteLayer(s32);void *GetOccupationBackgroundName(s32);void StringCopy(void *,void *);void StringAppend(void *,void *);void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void LoadNarcFileSection(void *,void *,s32,s32);void CloseNarcArchive(void);void OffsetTileIndices(void *,s32,s32);void LoadNarcFileToSpriteBuffer(void *,s32,s32);void SetTileRectPalette(void *,s32,s32,s32);void StepMapViewToTile(s32,s32);
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
SetTextSpriteValue(*(void **)(screen+60),20);
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

objectRes=LoadFileToBuffer(GetLocalizedFileName(sOccupationObjectName),1);
LoadGraphicsBlock(objectRes,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x6b80);
LoadGraphicsBlock(objectRes+0x3c0,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x7f80);
if(screen[54]==0)LoadGraphicsBlock(objectRes+0x478,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);else LoadGraphicsBlock(objectRes+0x690,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8080);
LoadGraphicsBlock(objectRes+0x92c,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x8480);
HeapFreeBlock(objectRes);
LoadDecompressedFileTo(sOccupationPlateFile,M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+0x9d80);
LoadFileToSpriteBuffer(sOccupationCommonFile,0x360,64);
Clear3DSpriteLayer(2);

/* Load the property's occupation background graphics, screen map and palette. */
 StringCopy(path,GetOccupationBackgroundName((*(u8 **)(screen+64))[1]));
 StringAppend(path,sNarcExt);
 OpenNarcArchive(path);

 StringCopy(path,GetOccupationBackgroundName((*(u8 **)(screen+64))[1]));
 StringAppend(path,sCgExt);
 LoadNarcFileDecompressed(path,M2C_FIELD(gCur3DSpriteEngine,void **,20));

 StringCopy(path,GetOccupationBackgroundName((*(u8 **)(screen+64))[1]));
 StringAppend(path,sScExt);
 LoadNarcFileDecompressed(path,M2C_FIELD(gCur3DSpriteEngine,void **,40));
StringCopy(path,GetOccupationBackgroundName((*(u8 **)(screen+64))[1]));
StringAppend(path,sClExt);
LoadNarcFileSection(path,*(void **)(screen+76),0,128);
CloseNarcArchive();
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine,void **,40),1024,8192);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;
Clear3DSpriteLayer(1);

/* load the shared frame.narc and its .cg/.sc/.cl parts */
OpenNarcArchive(sFrameNarcFile);
LoadNarcFileDecompressed(sFrameCgFile,M2C_FIELD(gCur3DSpriteEngine,void **,16));
LoadNarcFileDecompressed(sFrameScFile,M2C_FIELD(gCur3DSpriteEngine,void **,36));
LoadNarcFileToSpriteBuffer(sFrameClFile,32,32);
CloseNarcArchive();
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,void **,36),32,32,1);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;
gCur3DSpriteEngine=savedEngine;
screen[53]=1;
StepMapViewToTile(M2C_FIELD(*(void **)gCurrentMap,s16*,0x52dc),M2C_FIELD(*(void **)gCurrentMap,s16*,0x52de));
}

/* Draws the CO occupation cut-in for one frame: tints the panel palette toward
 * the CO's colour, stamps the portrait animation, sets the cut-in quad and
 * queues the panel, gauge and ability sprites. */
void DrawOccupationScreen(u8 *panel){
void UpdateSpriteAnimation(void *); s32 GetSpriteAnimValue(void *); void CopyToObjPaletteShadow(void *,s32,s32);
s32 GetArmyColor(s32); s32 BlendRgb555_16(s32,s32,u8,u8);
void BlendPalette(void *,s32,u8,u8,s32); s32 Divide(s32,s32);
void SetSpriteQuad(s32,s16,s16,s16,s16); void SetTextSpriteValue(void *,s32); void DrawTextSprite(void *);
void AddSprite(s32,u16,u16,void *,s32); s32 GetOccupationPaletteOffset(s32); s32 GetCOPortraitOffset(s32);
s32 scratch,scaleB,scaleC,scaleD,sine,cosine,q0,q1,q2,q3; u8 fade,row; s16 spriteY;
if(!panel[0x35])return;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3c)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x44)=0xffcb;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0xffb4;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=0xffcb;
UpdateSpriteAnimation(*(void **)(panel+68)); fade=GetSpriteAnimValue(*(void **)(panel+68));
CopyToObjPaletteShadow(*(void **)(panel+76),64,128);
scratch=GetArmyColor((*(u8 **)(panel+64))[3]);
if((*(u8 **)(panel+64))[2]==0)BlendPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,scratch,16-fade,fade,128);
else{q0=GetArmyColor((*(u8 **)(panel+64))[2]);q0=BlendRgb555_16(q0,scratch,16-fade*2,fade*2);BlendPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,48)+64,q0,11,5,128);}
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;
UpdateSpriteAnimation(*(void **)(panel+72));
scratch=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); cosine=((s16 *)gSinCosTable)[1];
scaleB=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); sine=((s16 *)gSinCosTable)[0];
scaleC=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72))))); scaleD=((GetSpriteAnimValue(*(void **)(panel+72))<0?-GetSpriteAnimValue(*(void **)(panel+72)):GetSpriteAnimValue(*(void **)(panel+72)))>=2?GetSpriteAnimValue(*(void **)(panel+72)):(GetSpriteAnimValue(*(void **)(panel+72))>2?2:(GetSpriteAnimValue(*(void **)(panel+72))<-2?-2:GetSpriteAnimValue(*(void **)(panel+72)))));
q0=Divide(cosine<<4,scaleD);q1=Divide((-sine)<<4,scaleC);q2=Divide(sine<<4,scaleB);q3=Divide(cosine<<4,scratch);
SetSpriteQuad(0,q0,q1,q2,q3);
if(((FlagsC253c *)(panel+80))->flag0){SetTextSpriteValue(*(void **)(panel+60),(*(u8 **)(panel+64))[5]);{u16 *q=*(u16 **)(panel+60);q[3]=102;q[4]=59;}DrawTextSprite(*(void **)(panel+60));}
if(((FlagsC253c *)(panel+80))->flag1)AddSprite(104,857,((0x3fc>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,gSpriteDesc32x16,11);
if(((FlagsC253c *)(panel+80))->flags)AddSprite(54,821,((0x404>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,gSpriteDesc64x32,11);
scratch=GetOccupationPaletteOffset((*(u8 **)(panel+64))[1]);
AddSprite(76,117,((scratch>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xb000,data_02129780,11);
for(row=0;row<20;row++){spriteY=row*-4+130;
if(row<panel[57])scratch=GetCOPortraitOffset((*(u8 **)(panel+64))[3]);else scratch=GetCOPortraitOffset((*(u8 **)(panel+64))[2]);
if(scratch!=65535)AddSprite(156,(spriteY&255)|1024,((scratch>>((*(ModeC253c **)gCur3DSpriteEngine)->shift))&1023)|0xc000,gSpriteDesc32x8,11);
}
}

/* Advances the CO occupation cut-in by one frame: lets A/Start or a touch
 * skip it, plays the per-row voice sounds, arms the sprite effects when the
 * portrait starts, plays the closing voice and bumps the frame counter. */
void UpdateOccupationScreen(OccupationEffect *effect){
void Sprite_ResumeAnimation(void *);
void func_020c32bc(s32,s32);
void PlaySoundEffect(s32);
u32 Modulo(u32,u32);
s32 IsPlayerHuman(s32);
extern u16 *gKeyState;
extern u8 *gTouchState;
u8 *co;
u16 *sprite;
if(effect->frame==effect->endFrame){Sprite_ResumeAnimation(effect);return;}
if((*gKeyState&(KEY_A|KEY_START))||gTouchState[TOUCH_STARTED]){
co=effect->co;
if(co[5]==20 && effect->frame<effect->startFrame+7)func_020c32bc(co[0],0);
Sprite_ResumeAnimation(effect);return;
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

/* Hide the CO occupation cut-in: clear its two 3D sprite layers and their dirty
 * bits, and mark the effect inactive so DrawOccupationScreen skips it. */
void HideOccupationScreen(OccupationEffect *effect) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(2);
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
    effect->active = 0;
}

/* Enters the CO occupation cut-in's view of the map: runs the map view's setup
 * callback, then clears the 3D sprite bank's split windows and blend level and
 * sets the bank's view flag bits for the cut-in layout. */
void EnterOccupationView(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*mapCallback)(void);u16 *volatile attr;u16 *volatile flag0;u16 *volatile flag1;u16 *volatile flag2;u16 *volatile flag3;u16 *volatile flag4;
mapCallback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(mapCallback)mapCallback();
attr=(u16 *)((u8 *)DS3D_BANK(gCur3DSpriteEngine)+DS3D_BANK_OAMATTR);*attr=*attr&~0xc0;
M2C_FIELD(DS3D_BANK(gCur3DSpriteEngine),u8 *,DS3D_BANK_ROWS_ABOVE)=0;
M2C_FIELD(DS3D_BANK(gCur3DSpriteEngine),u8 *,DS3D_BANK_ROWS_BELOW)=0;
M2C_FIELD(DS3D_BANK(gCur3DSpriteEngine),u8 *,DS3D_BANK_BLEND)=0;
flag0=(u16 *)DS3D_BANK(gCur3DSpriteEngine);*flag0=*flag0|DS3D_BANK_MODE0;
flag1=(u16 *)DS3D_BANK(gCur3DSpriteEngine);*flag1=*flag1|DS3D_BANK_MODE1;
flag2=(u16 *)DS3D_BANK(gCur3DSpriteEngine);*flag2=*flag2|DS3D_BANK_MODE2;
flag3=(u16 *)DS3D_BANK(gCur3DSpriteEngine);*flag3=*flag3|DS3D_BANK_MODE3;
flag4=(u16 *)DS3D_BANK(gCur3DSpriteEngine);*flag4=*flag4|DS3D_BANK_MODE4;
}

void func_020c2e10(void) {
    M2C_UNK InitOccupationScreen();
    InitOccupationScreen();
}

void func_020c2e1c(void) {
    void EnterOccupationView(void);
    EnterOccupationView();
}

void func_020c2e28(void) {
    void HideOccupationScreen();
    HideOccupationScreen();
}

void func_020c2e34(void) {
    void DrawOccupationScreen();
    DrawOccupationScreen();
}

void func_020c2e40(void) {
    void UpdateOccupationScreen();
    UpdateOccupationScreen();
}

