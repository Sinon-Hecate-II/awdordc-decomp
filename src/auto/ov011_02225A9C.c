/* 5 functions from 0x02225A9C to 0x02226658 (ov011), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "intro_menu.h"
extern s32 gCur3DSpriteEngine;
extern s32 g3DSpriteEngineMain,g3DSpriteEngineSub;
extern u8 data_ov011_02228a3c[],data_ov011_02228b54[],data_ov011_02228b5c[],data_ov011_02228b68[],data_ov011_02228b74[],data_ov011_02228b80[],data_ov011_02228a30[],data_ov011_02228b8c[],data_ov011_02228b94[],data_ov011_02228ba0[],data_ov011_02228bac[],data_ov011_02228bb8[],data_ov011_02228bc4[],data_ov011_02228bcc[],data_ov011_02228bd8[],data_ov011_02228be4[],data_ov011_02228bf0[],data_ov011_02228bfc[],data_ov011_02228c04[],data_ov011_02228c0c[];
static inline void Clear25d(s32 offset,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p= *p & ~mask;}
static inline void Set25d(s32 offset,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p= *p | mask;}
static inline void Priority25d(s32 offset,s32 n){u16 *p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p=(*p&~3)|n;}
static inline void Set25dBlendMode(s32 mode) {
    u16 *volatile p = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0) + 0x12);
    *p = (*p & ~0xC0) | (mode << 6);
}
typedef struct Mode25d {u16 mode:3;u16 rest:13;} Mode25d;

/* Per-frame update of one ending background panel (effect layer name "ed_bg%02d"
   loaded onto layer 2): on the panel's start frame record its x/y and load the
   layer, then for 620 frames slide the layer's offset and fade it in over the
   first 120 frames and out from frame 500, on the current 3D sprite screen. */
void UpdateOv011BackgroundPanel(void *panel,s32 startX,s32 startY,s32 index){
void StringFormat(void *,void *,...);
void LoadOv011EffectLayer(s32,s32);
s32 EaseInterpolate(s32,s32,s32,s32,s32);
extern u8 sOv011EffectNameFormat[];
char name[8];s32 startFrame;u8 alpha;
u16 offsetY;
StringFormat(name,sOv011EffectNameFormat,index);
switch(index){case 0:startFrame=600;break;case 1:startFrame=1600;break;case 2:startFrame=2600;break;case 3:startFrame=3600;break;case 4:startFrame=4600;break;case 5:startFrame=5600;break;case 6:startFrame=6600;break;case 7:startFrame=7600;break;case 8:startFrame=8600;break;case 9:startFrame=9600;break;}
if(M2C_FIELD(panel,u16 *,0x3a)==startFrame){
M2C_FIELD(panel,u16 *,0x3c)=startX;
M2C_FIELD(panel,u16 *,0x3e)=startY;
LoadOv011EffectLayer((s32)name,2);
}
if(M2C_FIELD(panel,u16 *,0x3a)<startFrame)return;
if(M2C_FIELD(panel,u16 *,0x3a)>startFrame+620)return;
Set25d(0,16);Clear25d(0,32);Set25d(0,64);Set25d(0,128);Clear25d(0,256);
M2C_FIELD(panel,u16 *,0x3e)=EaseInterpolate(0,0,64,M2C_FIELD(panel,u16 *,0x3a)-startFrame,740);
offsetY = M2C_FIELD(panel, u16 *, 0x3e);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3c)=M2C_FIELD(panel,u16 *,0x3c);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x44)=offsetY;
if(M2C_FIELD(panel,u16 *,0x3a)<=startFrame+120){
M2C_FIELD(panel,u8 *,0x36)=EaseInterpolate(4,0,16,M2C_FIELD(panel,u16 *,0x3a)-startFrame,120);
alpha=M2C_FIELD(panel,u8 *,0x36);
Set25dBlendMode(1);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=alpha;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16-alpha;
}else if(M2C_FIELD(panel,u16 *,0x3a)>=startFrame+500){
M2C_FIELD(panel,u8 *,0x36)=EaseInterpolate(1,0,16,M2C_FIELD(panel,u16 *,0x3a)-(startFrame+500),120);
alpha=M2C_FIELD(panel,u8 *,0x36);
Set25dBlendMode(1);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=16-alpha;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=alpha;
}
}

#pragma opt_common_subs off
void func_ov011_02225d98(void *state){
s32 Set3DSpriteVramBanks(void *);s32 Apply3DSpriteLayout(void *);s32 Clear3DSpriteLayer(u8);s32 SetFileDirectory(void *);s32 OpenNarcArchive(void *);s32 LoadNarcFileDecompressed(void *,s32);s32 LoadNarcFileToSpriteBuffer(void *,s32,s32);s32 CloseNarcArchive(void);s32 Get3DSpriteLayerSize(u8,s32);s32 OffsetTileIndices(s32,u16,s32);s32 LoadScenePanelPalette(s32);s32 func_02088774(s32);s32 CreateMainWallpaperSprite(s32,s32,s32);s32 FadePaletteTowardsBlack(s32,s32,s32,s32);s32 LoadNarcFileToBGExtPltt(void *,s32,s32,s32);s32 GetLocalizedFileName(void *);s32 LoadDecompressedFileTo(s32,s32);s32 LoadFileToSpriteBuffer(void *,s32,s32);s32 CreateFrameCallbackTask(void *,s32);s32 PlayMusicTrack(s32);
extern M2C_UNK func_ov011_0222513c;extern M2C_UNK func_ov011_02225224;
s32 saved;
M2C_FIELD(state,u8 *,0x34)&=~1;Set3DSpriteVramBanks(state);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Apply3DSpriteLayout(data_ov011_02228a3c);
Priority25d(6,0);Priority25d(8,1);Priority25d(10,2);Priority25d(12,3);
Set25d(0,16);Clear25d(0,32);Set25d(0,64);Set25d(0,128);Set25d(0,256);
Clear25d(18,256);Clear25d(18,512);Set25d(18,1024);Set25d(18,2048);Clear25d(18,4096);
Clear3DSpriteLayer(2);SetFileDirectory(data_ov011_02228b54);OpenNarcArchive(data_ov011_02228b5c);
LoadNarcFileDecompressed(data_ov011_02228b68,M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
LoadNarcFileDecompressed(data_ov011_02228b74,M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
LoadNarcFileToSpriteBuffer(data_ov011_02228b80,32,32);CloseNarcArchive();
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),(u16)Get3DSpriteLayerSize((u8)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),Mode25d *,0).mode,2),4096);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;
Set25d(0,4096);Clear25d(0,0x6000);
LoadScenePanelPalette(31);func_02088774(30);CreateMainWallpaperSprite(3,15,7);
FadePaletteTowardsBlack(M2C_FIELD(gCur3DSpriteEngine,s32 *,48)+480,0,8,8);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;
gCur3DSpriteEngine=g3DSpriteEngineSub;Apply3DSpriteLayout(data_ov011_02228a30);
Priority25d(6,3);Priority25d(8,0);Priority25d(10,1);Priority25d(12,2);
Set25d(0,16);Clear25d(0,32);Clear25d(0,64);Set25d(0,128);Clear25d(0,256);
Clear3DSpriteLayer(0);SetFileDirectory(data_ov011_02228b8c);OpenNarcArchive(data_ov011_02228b94);
LoadNarcFileDecompressed(data_ov011_02228ba0,M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
LoadNarcFileDecompressed(data_ov011_02228bac,M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
LoadNarcFileToSpriteBuffer(data_ov011_02228bb8,0,32);CloseNarcArchive();
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;
Clear3DSpriteLayer(3);SetFileDirectory(data_ov011_02228bc4);OpenNarcArchive(data_ov011_02228bcc);
LoadNarcFileDecompressed(data_ov011_02228bd8,M2C_FIELD(gCur3DSpriteEngine,s32 *,24));
LoadNarcFileDecompressed(data_ov011_02228be4,M2C_FIELD(gCur3DSpriteEngine,s32 *,44));
LoadNarcFileToBGExtPltt(data_ov011_02228bf0,3,0,512);CloseNarcArchive();
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;
SetFileDirectory(data_ov011_02228bfc);
LoadDecompressedFileTo(GetLocalizedFileName(data_ov011_02228c04),M2C_FIELD(gCur3DSpriteEngine,s32 *,28));
LoadFileToSpriteBuffer(data_ov011_02228c0c,512,32);
Clear25d(18,1);Clear25d(18,2);Set25d(18,4);Clear25d(18,8);Clear25d(18,16);
Set25d(18,256);Clear25d(18,512);Clear25d(18,1024);Set25d(18,2048);Clear25d(18,4096);
gCur3DSpriteEngine=saved;CreateFrameCallbackTask(&func_ov011_0222513c,4);CreateFrameCallbackTask(&func_ov011_02225224,10);PlayMusicTrack(0x10011);
}
#pragma opt_common_subs reset
void func_ov011_022264e4(void) {
    M2C_UNK DeleteFrameCallbackTask(M2C_UNK *);
    M2C_UNK DeleteWallpaperSpritesOnAllEngines();
    extern M2C_UNK func_ov011_0222513c;
    extern M2C_UNK func_ov011_02225224;
    DeleteFrameCallbackTask(&func_ov011_0222513c);
    DeleteFrameCallbackTask(&func_ov011_02225224);
    DeleteWallpaperSpritesOnAllEngines();
}

/* Advance the ov011 intro-menu object's per-frame timers: bump its frame timer
 * and fade timer, and, once the sequence has started (flags bit 0), bump the
 * appear timer that drives the panel fade.  The volatile self-assignment of
 * gCur3DSpriteEngine is the load-and-store the original emitted here. */
void IntroMenu_AdvanceTimers(IntroMenu011 *menu) {
    menu->timer++;
    menu->fadeTimer++;
    if (((u32)(menu->flags << 31) >> 31) == 0) return;
    *(volatile s32 *)&gCur3DSpriteEngine = *(volatile s32 *)&gCur3DSpriteEngine;
    menu->appearTimer++;
}

/* Load an effect's archive, graphics, screen map and palette into the selected layer. */
void LoadOv011EffectLayer(s32 effectName, s32 layer) {
    s32 Clear3DSpriteLayer(u8);
    s32 SetFileDirectory(void *);
    s32 StringCopy(void *, s32);
    s32 StringAppend(void *, void *);
    s32 OpenNarcArchive(void *);
    s32 CloseNarcArchive(void);
    s32 LoadNarcFileDecompressed(void *, s32);
    s32 QueueNarcFileToBGExtPltt(void *, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK sOv011EffectArchiveExtension, sOv011EffectGraphicsExtension, sOv011EffectScreenExtension, sOv011EffectPaletteExtension, sOv011EffectDirectory;
    u32 archiveName[8], graphicsName[8], screenName[8], paletteName[8];

    StringCopy(archiveName, effectName);
    StringAppend(archiveName, &sOv011EffectArchiveExtension);
    StringCopy(graphicsName, effectName);
    StringAppend(graphicsName, &sOv011EffectGraphicsExtension);
    StringCopy(screenName, effectName);
    StringAppend(screenName, &sOv011EffectScreenExtension);
    StringCopy(paletteName, effectName);
    StringAppend(paletteName, &sOv011EffectPaletteExtension);
    Clear3DSpriteLayer((u8)layer);
    SetFileDirectory(&sOv011EffectDirectory);
    OpenNarcArchive(archiveName);
    LoadNarcFileDecompressed(graphicsName, DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[layer]);
    LoadNarcFileDecompressed(screenName, (s32)DS3D_ENGINE(gCur3DSpriteEngine)->layerTiles[layer]);
    QueueNarcFileToBGExtPltt(paletteName, layer, 0, DS3D_LAYER_PALETTE_BYTES);
    CloseNarcArchive();
    DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= 1 << layer;
}

