/* 6 functions from 0x020E5080 to 0x020E5824 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_cse off
void func_020e5080(void *arg0) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub,gMicTestIpc;
extern u8 data_0212da70[],data_0212da40[],data_0212db88[],data_0212db38[],data_0212db78[],data_0212da4c[],data_0212da7c[],data_0212da34[],data_0212db28[],data_0212db68[],data_0212db58[],data_0212da58[],data_0212db48[],data_0212da64[];
void Set3DSpriteVramBanks(void);void func_02003560(void);void GX_SetBankForObjExtPalette(s32);
void Apply3DSpriteLayout(void*);void CreateMainWallpaperSprite(s32,s32,s32);void CreateSubWallpaperSprite(s32,s32,s32);
void SetFileDirectory(void*);void *GetLocalizedFileName(void*);
void OpenNarcArchive(void);void Clear3DSpriteLayer(s32);
void LoadNarcFileDecompressed(void*,void*);void LoadFileToSpriteBuffer(void*,s32,s32);
void SetTileRectPalette(void*,s32,s32,s32);void CloseNarcArchive(void);
void *CreateUnitSprite(void*);void InitUnitSprite(void*,s32,s32,s32,s32);
void Set3DSpriteSlideTargetAndStart(void*,s32,s32,s32,s32);s32 GetUnitSpriteWidth(void*);s32 GetUnitSpriteHeight(void*);
void func_02087d84(void*,s32,s32,s32,u16,u16);void func_020aad18(void*);
void *Create3DSprite(void*);void LoadSpriteResource(s32,s32,s32,void*);s32 func_020aaf74(void*);
void Apply3DSpriteBanks(void);M2C_UNK SetMusicVolumeLevel(M2C_UNK,M2C_UNK);
void Arm7TransferInit(void);void Arm7CommandInit(void);M2C_UNK Arm7SetAmpParam2(M2C_UNK);void func_0200e880(s32);
s32 saved;void *obj;s32 y,x,w,h;u16 *volatile p0, *volatile p1, *volatile p2, *volatile p3, *volatile p4, *volatile p5, *volatile p6, *volatile p7, *volatile p8, *volatile p9, *volatile p10, *volatile p11;
Set3DSpriteVramBanks();func_02003560();GX_SetBankForObjExtPalette(0x40);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Apply3DSpriteLayout(data_0212da70);
p0=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p0=*p0 | 16;
p1=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p1=*p1 & ~32;
p2=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p2=*p2 | 64;
p3=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p3=*p3 & ~128;
p4=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p4=*p4 | 256;
p5=((u16 *)((u8 *)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0)+0x12)); *p5=*p5 & ~192;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,81)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,82)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,83)=0;
CreateMainWallpaperSprite(2,15,5);SetFileDirectory(data_0212da40);
GetLocalizedFileName(data_0212db88);OpenNarcArchive();Clear3DSpriteLayer(0);
LoadNarcFileDecompressed(GetLocalizedFileName(data_0212db38),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0xc));
LoadNarcFileDecompressed(GetLocalizedFileName(data_0212db78),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20));
LoadFileToSpriteBuffer(data_0212da4c,0xa0,0x20);
SetTileRectPalette(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20),0x20,0x18,5);
M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=1;CloseNarcArchive();
M2C_FIELD(arg0,void **,0x38)=CreateUnitSprite(arg0);
InitUnitSprite(M2C_FIELD(arg0,void **,0x38),2,0x140,3,1);
obj=M2C_FIELD(arg0,void **,0x38);Set3DSpriteSlideTargetAndStart(obj,0xe0,0xa0,0xe0,0xa0);
if((u8)(M2C_FIELD(M2C_FIELD(obj,void **,0x64),u8 *,0x12)!=0)){
y=M2C_FIELD(obj,s16 *,0x52);x=M2C_FIELD(obj,s16 *,0x50);
w=GetUnitSpriteWidth(obj);h=GetUnitSpriteHeight(obj);
func_02087d84(M2C_FIELD(obj,void **,0x64),1,x,y,(u16)w,(u16)h);
}
M2C_FIELD(obj,s16 *,0x34)=0xe0;M2C_FIELD(obj,s16 *,0x36)=0xa0;
if((u8)(M2C_FIELD(M2C_FIELD(obj,void **,0x64),u8 *,0x12)!=0)){
y=M2C_FIELD(obj,s16 *,0x52);x=M2C_FIELD(obj,s16 *,0x50);
w=GetUnitSpriteWidth(obj);h=GetUnitSpriteHeight(obj);
func_02087d84(M2C_FIELD(obj,void **,0x64),1,x,y,(u16)w,(u16)h);
}
func_020aad18(M2C_FIELD(arg0,void **,0x38));
gCur3DSpriteEngine=g3DSpriteEngineSub;Apply3DSpriteLayout(data_0212da7c);
p6=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p6=*p6 | 16;
p7=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p7=*p7 & ~32;
p8=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p8=*p8 | 64;
p9=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p9=*p9 & ~128;
p10=(M2C_FIELD((void*)gCur3DSpriteEngine,u16 **,0)); *p10=*p10 | 256;
p11=((u16 *)((u8 *)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0)+0x12)); *p11=*p11 & ~192;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,81)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,82)=0;
M2C_FIELD(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0),u8 *,83)=0;
CreateSubWallpaperSprite(2,15,5);SetFileDirectory(data_0212da34);
GetLocalizedFileName(data_0212db28);OpenNarcArchive();Clear3DSpriteLayer(0);
LoadNarcFileDecompressed(GetLocalizedFileName(data_0212db68),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0xc));
LoadNarcFileDecompressed(GetLocalizedFileName(data_0212db58),M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20));
LoadFileToSpriteBuffer(data_0212da58,0xa0,0x20);
SetTileRectPalette(M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x20),0x20,0x18,5);
M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=1;
LoadNarcFileDecompressed(GetLocalizedFileName(data_0212db48),(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(data_0212da64,0x2c0,0x20);CloseNarcArchive();
M2C_FIELD(arg0,void **,0x34)=Create3DSprite(arg0);obj=M2C_FIELD(arg0,void **,0x34);
M2C_FIELD(obj,u8 *,0x58)=15;
LoadSpriteResource(2,0,15,(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x1c)+0x2a00);
LoadSpriteResource(2,2,15,(u8*)M2C_FIELD((void*)gCur3DSpriteEngine,void **,0x30)+0x2e0);
M2C_FIELD(obj,s32 *,0x44)=func_020aaf74(obj);
M2C_FIELD(obj,s16 *,0x3e)=0x150;
M2C_FIELD(obj,u32 *,0x40)=(M2C_FIELD(obj,u32 *,0x40)&~0x3fc0000)|0x5c0000;
M2C_FIELD(obj,s16 *,0x3c)=0xc00;
gCur3DSpriteEngine=saved;Apply3DSpriteBanks();SetMusicVolumeLevel(2,0x20);Arm7TransferInit();Arm7CommandInit();Arm7SetAmpParam2(1);func_0200e880(3);
M2C_FIELD(&gMicTestIpc,s32 *,4)=0;
M2C_FIELD(&gMicTestIpc,s32 *,8)=gMicTestIpc;
M2C_FIELD(&gMicTestIpc,s32 *,0xc)=0x20;
M2C_FIELD(&gMicTestIpc,s32 *,0x10)=0x105d;
M2C_FIELD(&gMicTestIpc,s32 *,0x14)=1;
M2C_FIELD(&gMicTestIpc,s32 *,0x18)=0;
M2C_FIELD(&gMicTestIpc,s32 *,0x1c)=0;
}
#pragma opt_cse reset
void func_020e5678(void) {
    M2C_UNK Arm7TransferEndWait();
    M2C_UNK Arm7SetAmpParam2(M2C_UNK);
    M2C_UNK SetMusicVolumeLevel(M2C_UNK, M2C_UNK);
    M2C_UNK func_020af1e4();
    func_020af1e4();
    SetMusicVolumeLevel(2, 0x7F);
    Arm7TransferEndWait();
    Arm7SetAmpParam2(0);
}

/* Create the mic test screen's object on the main engine: install its vtable,
 * clear its sprites and level history, start its measurement timer and
 * allocate the microphone sample buffer.  owner is the sprite layer (or parent
 * sprite) it is created under. */
void CreateMicTestObject(s32 owner) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    s16 Divide(s32, M2C_UNK);
    s32 func_020e3580(M2C_UNK, M2C_UNK);
    extern M2C_UNK gMicTestClass;
    extern M2C_UNK gMicTestVtbl;
    extern s32 gMicTestIpc, g3DSpriteEngineMain, gCur3DSpriteEngine;
    s32 saved;
    MicTestScreen *screen;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    screen = (MicTestScreen *)CreateSpriteForOwner(&gMicTestClass, owner);
    if (screen != NULL) {
        screen->vtable = &gMicTestVtbl;
        screen->levelSprite = NULL;
        screen->menuSprite = NULL;
        screen->flags = 0;
        screen->timer = Divide(0x2BF20, 0x3E8);
        screen->levelIndex = 0;
        gMicTestIpc = func_020e3580(MIC_TEST_SAMPLE_COUNT, MIC_TEST_SAMPLE_COUNT);
        MI_CpuFill8(screen->levels, 0, sizeof(screen->levels));
    }
    gCur3DSpriteEngine = saved;
}

/* Mic test screen update: once a measurement is requested (or one is already
 * running) arm the 180-frame timer, clear the request and enter the running
 * state, starting the meter animation the first time round. */
void StartMicTestMeasurement(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    s16 Divide(s32, M2C_UNK);
    extern M2C_UNK gMicTestClass;
    MicTestScreen *screen;
    u8 flags;

    screen = (MicTestScreen *)FindObjectByClass(&gMicTestClass);
    if (screen == NULL) return;
    flags = screen->flags;
    if (!(flags & MIC_TEST_FLAG_RUNNING)) {
        if (!(flags & MIC_TEST_FLAG_START)) return;
    }
    screen->timer = Divide(0x2BF20, 0x3E8);
    if ((screen->flags &= ~MIC_TEST_FLAG_START) & MIC_TEST_FLAG_RUNNING) return;
    screen->flags |= MIC_TEST_FLAG_RUNNING;
    GotoSpriteAnimationLabel(screen, 1);
}

/* Destroy the mic test screen object: install the base vtable, free the
 * microphone sample buffer, then free the object itself. */
MicTestScreen *DestroyMicTestObject(MicTestScreen *screen) {
    extern M2C_UNK gMicTestVtbl;
    extern s32 gMicTestIpc;
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK MemFree(M2C_UNK **);

    screen->vtable = &gMicTestVtbl;
    if (gMicTestIpc != 0) HeapFreeBlock(gMicTestIpc);
    MemFree((M2C_UNK **) screen);
    return (MicTestScreen *)screen;
}

M2C_UNK **func_020e57f0(M2C_UNK **arg0) {
    M2C_UNK HeapFreeBlock();
    extern M2C_UNK gMicTestVtbl;
    extern s32 gMicTestIpc;
    *arg0 = &gMicTestVtbl;
    if (gMicTestIpc != 0) {
        HeapFreeBlock();
    }
    return arg0;
}

