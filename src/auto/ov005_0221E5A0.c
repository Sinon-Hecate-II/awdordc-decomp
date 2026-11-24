/* 9 functions from 0x0221E5A0 to 0x0221F4F8 (ov005), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
extern u8 data_ov005_02220b70[];
extern u8 data_ov005_02220f54[];
extern u8 data_ov005_02220a34[];
extern u8 data_ov005_02220f3c[];
extern u8 data_ov005_02220eac[];
extern u8 data_ov005_02220ecc[];
extern u8 data_ov005_02220f0c[];
extern u8 data_ov005_02220e8c[];
extern u8 data_ov005_02220e3c[];
extern u8 data_ov005_02220e6c[];
extern u8 data_ov005_02220e4c[];
extern u8 data_ov005_02220edc[];
extern u8 data_ov005_02220a1c[];
extern u8 data_ov005_02220f1c[];
extern u8 data_ov005_02220e5c[];
extern u8 data_ov005_02220eec[];

/* Music tracks handed to PlayMusicTrack. */
#define MUSIC_MAP_BATTLE          0x10017 /* the standard map battle theme */
#define MUSIC_MAP_BATTLE_SPECIAL  0x10018 /* the theme of maps 0xAA, 0xB0, 0xB5 and 0xBA */

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_lifetimes off
void func_ov005_0221e5a0(M2C_UNK parent) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    s32 func_020cfb94(void);
    extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    extern M2C_UNK data_ov005_02220c88[], data_ov005_02220f68[], data_ov005_02220a3c[];
    extern M2C_UNK data_ov005_02220f2c[], data_ov005_02220e7c[], data_ov005_02220a84[];
    extern M2C_UNK data_ov005_02220e9c[], data_ov005_02220efc[], data_ov005_02220a54[], data_ov005_02220a60[];
    extern u8 gCoState[], gBattleResults[];
    void *sprite;
    void **saved;
    u16 *volatile bank;
    s32 i;
    u32 longest;
    s32 slot;
    void **engine;

    sprite = CreateSpriteObject(data_ov005_02220c88, parent);
    if (!sprite) return;
    M2C_FIELD(sprite, void **, 0) = data_ov005_02220f68;
    SetFileDirectory(data_ov005_02220a3c);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    SetLayerSize(1, 2);
    SetLayerSize(0, 2);
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(0);
    OpenNarcArchive(GetLocalizedFileName(data_ov005_02220f2c));
    LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220e7c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    if (IsBattleDraw()) {
        LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220a84), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
        Clear3DSpriteLayer(1);
    } else {
        LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220e9c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
        if (DidPlayerWin()) {
            LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220efc), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        } else {
            Clear3DSpriteLayer(1);
        }
    }
    CloseNarcArchive();
    AddToU16Array(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x800, 0x2000);
    AddToU16Array(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x800, 0x2000);
    DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= DS3D_DIRTY_LAYER2;
    DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= DS3D_DIRTY_LAYER1;
    DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= DS3D_DIRTY_LAYER0;
    bank = *(u16 **)gCur3DSpriteEngine;
    *bank = *bank & ~0x20;
    LoadSpriteResource(1, 2, 0, (u8 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamBuffer + 0x2c0);
    LoadDecompressedFileTo(data_ov005_02220a54, DS3D_ENGINE(gCur3DSpriteEngine)->textureAddr + 0x3b00);
    LoadFileToSpriteBuffer(data_ov005_02220a60, 0x2e0, 0x20);
    engine = gCur3DSpriteEngine;
    LoadSpriteResource(4, 0, 0, DS3D_ENGINE(engine)->textureAddr + 0x4400);
    engine = gCur3DSpriteEngine;
    LoadSpriteResource(5, 2, 0, (u8 *)DS3D_ENGINE(engine)->oamBuffer + 0x300);
    i = 0;
    if (func_020cfb94() > 0) {
        s32 tile = 0x270;
        u8 *co = gCoState;
        do {
            LoadFaceTextureAndPaletteAt(M2C_FIELD(co, u16 *, 0x18), 0, tile << 5, (u16)i);
            i++;
            tile += 0x18;
            co += 0xc;
        } while (i < func_020cfb94());
    }
    gCur3DSpriteEngine = saved;
    slot = 0;
    M2C_FIELD(sprite, s32 *, 0x34) = slot;
    M2C_FIELD(sprite, s32 *, 0x44) = slot;
    M2C_FIELD(sprite, s16 *, 0x38) = slot - 160;
    goto checkCount;
    nextSlot:
    M2C_FIELD((u8 *)sprite + slot * 2, s16 *, 0x3a) = 160;
    slot++;
    checkCount:
    longest = gBattleResults[13];
    if (gBattleResults[12] > longest) longest = gBattleResults[12];
    if ((s32)longest <= gBattleResults[14]) longest = gBattleResults[14];
    if (slot < (s32)longest) goto nextSlot;
}
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
#pragma opt_lifetimes reset
#pragma opt_propagation reset
void func_ov005_0221e88c(void *arg0) {
void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
void *MemAlloc(s32);
void *HeapAllocBlock(s32);
s32 GetLocalizedFileName(M2C_UNK *);
s32 func_020cfb94(void);
s32 GetCurrentMapName(void);
s32 IsCampaignBattleRules(void);
s32 GetLanguage(void);
s32 func_020a7290(void);
s32 func_020a7278(void);
s32 func_020a72e8(s32);
s32 func_020a8a84(s32);
s32 GetDigitCount(s32);
s32 GetArmyStateTiles(s32);
s32 GetArmyIconPalette(s32);
s32 GetTerrainTileData(s32);
s32 GetTerrainPalette(s32,s32);
extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain, **g3DSpriteEngineSub, **gCurrentMap;
void *p, *q; void **saved, **saved2;
u8 *dst; s32 n; u8 *b; s32 i,j,k,v,t;
p=CreateSpriteObject(data_ov005_02220b70,arg0);
if (!p) return;
M2C_FIELD(p,void **,0)=data_ov005_02220f54;
SetFileDirectory(data_ov005_02220a34);
OpenNarcArchive(GetLocalizedFileName(data_ov005_02220f3c));
saved=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220eac),M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220ecc),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220f0c),M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+1280);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+0x500,0x100,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
LoadDecompressedFileTo(data_ov005_02220e8c,M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+0x7300);
LoadFileToSpriteBuffer(data_ov005_02220e3c,0x380,0x20);
gCur3DSpriteEngine=g3DSpriteEngineSub;
SetLayerSize(2,2); Clear3DSpriteLayer(2);
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220e6c),M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220e4c),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220edc),M2C_FIELD(gCur3DSpriteEngine,s32 *,36));
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,36),0x100,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved; CloseNarcArchive();
M2C_FIELD(p,s32 *,0x3c)=0; M2C_FIELD(p,s32 *,0x50)=0; M2C_FIELD(p,s32 *,0x54)=0;
q=MemAlloc(0x24);
if(q) {
M2C_FIELD(q,u16 *,16)=8; M2C_FIELD(q,u8 *,18)=0;
M2C_FIELD(q,s32 *,0)=0; M2C_FIELD(q,s32 *,4)=0;
M2C_FIELD(q,s8 *,8)=-1; M2C_FIELD(q,s8 *,9)=-1;
M2C_FIELD(q,s8 *,10)=-1; M2C_FIELD(q,s8 *,11)=-1;
M2C_FIELD(q,u8 *,13)=255; M2C_FIELD(q,s8 *,12)=-1;
M2C_FIELD(q,u8 *,14)=0; M2C_FIELD(q,u8 *,15)=255;
M2C_FIELD(q,void **,20)=HeapAllocBlock(0x60);
MI_CpuFill8(M2C_FIELD(q,void **,20),0,0x60);
}
M2C_FIELD(p,void **,0x34)=q;
M2C_FIELD(p,s32 *,0x40)=192; M2C_FIELD(p,s32 *,0x48)=192;
M2C_FIELD(p,s32 *,0x44)=-32; M2C_FIELD(p,s32 *,0x4c)=-32;
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
i=0;
if(func_020cfb94()>0) { j=0x388; k=0; do {
dst=M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+((volatile s32)j<<5);
MI_CpuCopy32(GetArmyStateTiles(M2C_FIELD((u8 *)*gCurrentMap+k,u8 *,0x6857)),dst,0x80);
CopyToObjPaletteShadow(GetArmyIconPalette(M2C_FIELD((u8 *)*gCurrentMap+k,u8 *,0x684d)),(i+24)<<5,32);
i++; j+=4; k+=0x8c;
} while(i<func_020cfb94()); }
gCur3DSpriteEngine=*(void ***)&g3DSpriteEngineMain;
k=func_020a7290()<<5; saved=(void **) (M2C_FIELD(gCur3DSpriteEngine,u8 *volatile *,28)+0x3580);
MI_CpuCopy32(func_020a7278(),(u8 *)saved+0x4000,k);
CopyToObjPaletteShadow(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap+(M2C_FIELD(p,s32 *,0x50)+1)*140,u8 *,0x67c1)),0x3c0,32);
b=data_ov005_02220a1c; gCur3DSpriteEngine=g3DSpriteEngineSub;
k=0; if(*b) { saved=(void **)0x3ac; do {
dst=M2C_FIELD(gCur3DSpriteEngine,u8 *volatile *,28)+((s32)saved<<5);
MI_CpuCopy32(GetTerrainTileData(*b),dst,256);
b++; saved=(void **)((s32)saved+8); k++; } while(*b); }
CopyToObjPaletteShadow(GetTerrainPalette(16,M2C_FIELD((u8 *)*gCurrentMap+(M2C_FIELD(p,s32 *,0x50)+1)*140,u8 *,0x67c1)),0x3c0,32);
gCur3DSpriteEngine=g3DSpriteEngineSub; InitTextTiles(0,0,0);
v=GetCurrentMapName(); t=M2C_FIELD(*gCurrentMap,u16 *,0x52a2);
if(IsCampaignBattleRules()) {
DrawTilemapNumber(6,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),func_020a8a84(M2C_FIELD(*gCurrentMap,u16 *,0x5142)),0,0);
DrawTextToTilemap(8,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),v,0,0);
} else DrawTextToTilemap(5,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),v,0,0);
if(!GetLanguage()) DrawTilemapNumber(23,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),t,0,0);
else DrawTilemapNumber((s16)(GetDigitCount(t)+24),1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),t,0,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=saved2; v=M2C_FIELD(p,s32 *,0x54);
OpenNarcArchive(GetLocalizedFileName(data_ov005_02220f1c));
if(v==0) { LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220e5c),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
 } else { LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_02220eec),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
 }
CloseNarcArchive();
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(p,u8 *,0x58)=1;
}
#pragma opt_strength_reduction on
/* Per-frame update of the results-screen object: on every fourth frame it scrolls
 * both 3D sprite screens down one pixel, and when START is pressed it creates the
 * object described by data_ov005_02220ad0 (unless a screen fade is running). */
void UpdateResultsScreen(void *parent) {
    s32 CreateSpriteFromClass(s32 *, void *);
    u8 IsScreenFadeActive(void);
    extern u32 gFrameCounter;
    extern void **g3DSpriteEngineSub, **g3DSpriteEngineMain, **gCur3DSpriteEngine;
    extern u16 *gKeyState;
    extern s32 data_ov005_02220ad0[];
    volatile u16 *volatile offsetY;
    void **savedEngine;
    s32 screen;
    void **engine;

    if (!(gFrameCounter & 3)) {
        savedEngine = gCur3DSpriteEngine;
        screen = 0;
        do {
            if (screen == 0) engine = g3DSpriteEngineMain;
            else engine = g3DSpriteEngineSub;
            screen++;
            gCur3DSpriteEngine = engine;
            offsetY = (u16 *)((u8 *)*engine + DS3D_OFFSET_Y);
            *offsetY = *offsetY + 1;
        } while (screen < 2);
        gCur3DSpriteEngine = savedEngine;
    }
    if (*gKeyState & KEY_START) {
        if (!IsScreenFadeActive()) CreateSpriteFromClass(data_ov005_02220ad0, parent);
    }
}

void func_ov005_0221efac(void) {
    void UpdateResultsScreen();
    UpdateResultsScreen();
}

/* Play the current map's battle music: the standard theme, except on the special
 * maps 0xAA, 0xB0, 0xB5 and 0xBA while the battle mode (the low three bits of
 * gMapConfig) is 0, which use the alternate theme. */
void PlayMapBattleMusic(void) {
    M2C_UNK PlayMusicTrack(s32);
    extern u16 gMapConfig;
    extern void **gCurrentMap;
    s32 track;
    u16 mapId;

    track = MUSIC_MAP_BATTLE;
    if (!(((u32) (gMapConfig << 0x1D) >> 0x1D) & 0xFF)) {
        mapId = M2C_FIELD(*gCurrentMap, u16 *, MAP_ID);
        if ((s32) mapId <= 0xB0) {
            if (((s32) mapId < 0xB0) && (mapId != 0xAA)) {

            } else {
                goto useSpecialTheme;
            }
        } else if ((s32) mapId <= 0xB5) {
            if (mapId != 0xB5) {

            } else {
                goto useSpecialTheme;
            }
        } else if (mapId == 0xBA) {
useSpecialTheme:
            track = MUSIC_MAP_BATTLE_SPECIAL;
        }
    }
    PlayMusicTrack(track);
}

/* Create the results screen object under `parent`: give it the results screen's
 * vtable and load the bird animation it shows from the /result directory. */
void CreateResultsScreen(M2C_UNK parent) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    s32 LoadDecompressedFile(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gResultsDirectory;
    extern M2C_UNK gResultsBirdAnimation;
    extern M2C_UNK gResultsScreenClass;
    extern M2C_UNK gResultsScreenVtbl;
    void *screen;

    screen = CreateSpriteObject(&gResultsScreenClass, parent);
    if (screen == NULL) {
        return;
    }
    M2C_FIELD(screen, M2C_UNK **, 0) = &gResultsScreenVtbl;
    SetFileDirectory(&gResultsDirectory);
    M2C_FIELD(screen, s32 *, 0x34) = LoadDecompressedFile(&gResultsBirdAnimation, 1);
}

#pragma peephole off
void func_ov005_0221f084(void *arg0) {
    M2C_UNK QueueBGExtPaletteUpload(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, s32);
    s32 func_020815bc(M2C_UNK *, M2C_UNK);
    M2C_UNK Apply3DSpriteDisplayConfig();
    M2C_UNK Configure3DSpriteLayer(M2C_UNK, u16 *);
    M2C_UNK Set3DSpriteVramBanks();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK Hide3DSprite(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK LoadScenePanelGraphicsOnBothEngines();
    M2C_UNK InitUnitSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    M2C_UNK CreateUnitSpriteButtonTask(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern void **g3DSpriteEngineSub;
    extern void **g3DSpriteEngineMain;
    extern void *data_027e01d8;
    extern u16 data_ov005_02220078;
    extern M2C_UNK data_ov005_02221230;
    extern M2C_UNK data_ov005_02221238;
    extern M2C_UNK data_ov005_0222124c;
    extern M2C_UNK data_ov005_02221260;
    extern M2C_UNK data_ov005_02221274;
    extern M2C_UNK data_ov005_02221288;
    extern M2C_UNK data_ov005_0222129c;
    extern M2C_UNK data_ov005_022212b0;
    extern M2C_UNK data_ov005_022212c4;
    extern M2C_UNK data_ov005_022212d4;
    extern M2C_UNK data_ov005_022212e4;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 sp8;
    s32 var_r0_2;
    s32 var_r9;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    s32 temp_r7;
    void *temp_r11;
    void *var_r0;

    sp8 = data_ov005_02220078;
    Set3DSpriteVramBanks();
    LoadScenePanelGraphicsOnBothEngines();
    SetFileDirectory(&data_ov005_02221230);
    temp_r11 = data_027e01d8;
    var_r9 = 0;
    do {
        if (var_r9 == 0) {
            var_r0 = (void*)g3DSpriteEngineMain;
        } else {
            var_r0 = (void*)g3DSpriteEngineSub;
        }
        data_027e01d8 = var_r0;
        Apply3DSpriteDisplayConfig();
        Configure3DSpriteLayer(3, &sp8);
        var_r9 += 1;
        temp_r0 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r0;
        *sp1C = *sp1C & ~0x10;
        temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp18 = temp_r0_2;
        *sp18 = *sp18 & ~0x20;
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp14 = temp_r0_3;
        *sp14 = *sp14 & ~0x40;
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp10 = temp_r0_4;
        *sp10 = *sp10 | 0x80;
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        spC = temp_r0_5;
        *spC = *spC | 0x100;
    } while (var_r9 < 2);
    data_027e01d8 = (void*)g3DSpriteEngineMain;
    OpenNarcArchive(&data_ov005_02221238);
    LoadNarcFileDecompressed(&data_ov005_0222124c, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    LoadNarcFileDecompressed(&data_ov005_02221260, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x3C) = func_020815bc(&data_ov005_02221274, 0x200);
    QueueBGExtPaletteUpload(M2C_FIELD(arg0, s32 *, 0x3C), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    CloseNarcArchive();
    LoadDecompressedFileTo(GetLocalizedFileName(&data_ov005_02221288), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    LoadFileToSpriteBuffer(&data_ov005_0222129c, 0x2C0, 0x20);
    OpenNarcArchive((data_027e01d8 = (void*)g3DSpriteEngineSub, &data_ov005_022212b0));
    LoadNarcFileDecompressed(&data_ov005_022212c4, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    LoadNarcFileDecompressed(&data_ov005_022212d4, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x40) = func_020815bc(&data_ov005_022212e4, 0x200);
    QueueBGExtPaletteUpload(M2C_FIELD(arg0, s32 *, 0x40), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    CloseNarcArchive();
    data_027e01d8 = (void*)g3DSpriteEngineMain;
    M2C_FIELD(arg0, void **, 0x34) = func_020ab1c4(arg0);
    InitUnitSprite(M2C_FIELD(arg0, void **, 0x34), 1, 0x120, 3, 1);
    {
    void *temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    Set3DSpriteSlideTargetAndStart(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        s16 temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        s16 temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = GetUnitSpriteWidth(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5, (u16) temp_r7, (u16) GetUnitSpriteHeight(temp_r4));
    }
    }
    CreateUnitSpriteButtonTask(M2C_FIELD(arg0, void **, 0x34), 1);
    func_020aad18(M2C_FIELD(arg0, void **, 0x34));
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x34));
    data_027e01d8 = temp_r11;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
}
#pragma peephole reset
/* Per-frame handler of the results screen: once the player presses an action
 * key (A/B/START/X/Y) or starts a touch, hand the sprite back to its animation;
 * until then count the waiting frames at +0x38, capped at 0x84. */
void WaitForResultsInput(void *sprite) {
    M2C_UNK Sprite_ResumeAnimation();
    extern u16 *gKeyState;
    extern void *gTouchState;
    s32 waitFrames;

    if (*gKeyState & (KEY_A | KEY_B | KEY_START | KEY_X | KEY_Y)) {
        Sprite_ResumeAnimation();
        return;
    }
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) != 0) {
        Sprite_ResumeAnimation();
        return;
    }
    waitFrames = M2C_FIELD(sprite, s32 *, 0x38);
    if (waitFrames < 0x84) {
        M2C_FIELD(sprite, s32 *, 0x38) = (s32) (waitFrames + 1);
    }
}

/* Tear down the results screen's 3D sprite: hide it on both screens (clear the
 * sprite bank's OBJ priority and split) and free the two 0x200-byte graphic
 * buffers it loaded for the main and sub screens. */
void FreeResultsScreenGraphics(void *object) {
    s32 HeapFreeBlock(s32);
    extern void **g3DSpriteEngineSub, **g3DSpriteEngineMain, **gCur3DSpriteEngine;
    u16 *volatile oamAttr;
    void **savedEngine;
    s32 screen;
    void **engine;

    screen = 0;
    savedEngine = gCur3DSpriteEngine;
    do {
        if (screen == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        screen++;
        gCur3DSpriteEngine = engine;
        oamAttr = (u16 *)((u8 *)*engine + DS3D_BANK_OAMATTR);
        *oamAttr = *oamAttr & ~DS3D_BANK_OAMATTR_PRIORITY;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, DS3D_BANK_ROWS_ABOVE) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, DS3D_BANK_ROWS_BELOW) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, DS3D_BANK_BLEND) = 0;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
    HeapFreeBlock(M2C_FIELD(object, s32 *, 0x3C));
    HeapFreeBlock(M2C_FIELD(object, s32 *, 0x40));
}

