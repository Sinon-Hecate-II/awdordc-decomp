/* 13 functions from 0x02219ACC to 0x0221A59C (ov007), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "ov007_map_editor.h"

void func_ov007_02219acc(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
    PlaySoundEffect(0x10020);
}

void func_ov007_02219ae8(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s16 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s16, s32);
    void *GetPanelObject();
    void *temp_r4;

    temp_r4 = GetPanelObject();
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    M2C_FIELD(temp_r4, s16 *, 0x3E) = EaseInterpolate(4, 0x100, 0, M2C_FIELD(arg0, s16 *, 0x54), 4);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < 4) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_ov007_02219b38(void *arg0) {
M2C_UNK func_ov007_0221863c(void *);
void *p=GetPanelObject();
M2C_FIELD(p+M2C_FIELD(p,u8 *,0x37),u8 *,0x38)=M2C_FIELD(arg0,s32 *,0x5c);
func_ov007_0221863c(p);
M2C_FIELD(arg0,s16 *,0x54)=0;
}

void func_ov007_02219b64(void *arg0) {
    void *temp_r4;

    temp_r4 = GetPanelObject();
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (M2C_FIELD(arg0, s16 *, 0x54) + 1);
    M2C_FIELD(temp_r4, s16 *, 0x3E) = EaseInterpolate(4, 0, 0x100, M2C_FIELD(arg0, s16 *, 0x54), 4);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x54) < 4) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_ov007_02219bb4(M2C_UNK arg0, s32 arg1) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fe48;
    M2C_FIELD(CreateSpriteObject(&data_ov007_0221fe48, arg0), s32 *, 0x5C) = arg1;
}

/* Loads each of the four players' army-colour palettes from the player palette
 * table into the sub engine's OBJ palette shadow, and dims the row of a player
 * that has no team so its units read as inactive. */
void MapEditor_LoadPlayerPalettes(void) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub;
    void *GetArmyIconPalette(s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    s32 MapEditor_PlayerHasTeam(s32);
    void DimPalette(void *);
    s32 savedEngine = gCur3DSpriteEngine;
    s32 i, paletteOffset;

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    for (i = 0; i < 4; i++) {
        paletteOffset = (i + MAP_EDITOR_PLAYER_PALETTE_ROW) << 5;
        CopyToObjPaletteShadow(GetArmyIconPalette(i + 1), paletteOffset, DS3D_PALETTE_BYTES);
        if (!MapEditor_PlayerHasTeam(i + 1)) {
            DimPalette((u8 *)DS3D_ENGINE(gCur3DSpriteEngine)->oamBuffer + (paletteOffset & ~1));
        }
    }
    gCur3DSpriteEngine = savedEngine;
}

/* Draw one cell of the map editor's unit catalogue: clear the two tiles under the
 * icon, write the number of units of that kind there when there are any, and give
 * the icon tiles their palette row (the row after the plain one, +5, when the icon
 * is shown together with a count). */
void MapEditor_DrawCatalogueCell(s32 x, s32 y, s32 paletteRow, s32 count) {
extern s32 gCur3DSpriteEngine;
void ClearTileRect(void *,s32,s32);
void DrawTilemapNumber(s16,s16,void *,s32,s32,s32);
void SetTileRectPalette(void *,s32,s32,u16);
s32 row=paletteRow+4;
ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x20)+x*2+(y+1)*64,2,2);
if(count>0) {
DrawTilemapNumber(x+1,y+1,M2C_FIELD(gCur3DSpriteEngine,void **,0x20),count,0x1000,0);
row+=5;
}
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+x*2+y*64,2,3,(u16)row);
}

#pragma opt_strength_reduction off
void func_ov007_02219d10(void){
 /* Stage the B-layer grid: 10 columns x 5 rows of 2x2 cells, each cell cleared,
    given its digits (tile-sum table) and stamped into the tile buffer, then two
    8x4 palette blocks placed per the row-0 table byte; flags the layer engine's
    DMA dirty bits (0x46 |= 2,2,1) before restoring the current engine. */
 extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
 s32 GetEditorUnitCategoryCount(s32,s32);u8 GetMapEditorMode(void);
 void SetTileRectPalette(void *,s32,s32,u16);
 s32 savedEngine,row,rowStart;
 savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
 row=0;rowStart=2;do{
 if(row==0)MapEditor_DrawCatalogueCell(17,rowStart,row,GetEditorUnitCategoryCount(8,row));
 else MapEditor_DrawCatalogueCell(17,rowStart,row,GetEditorUnitCategoryCount(0,row));
 MapEditor_DrawCatalogueCell(19,rowStart,row,GetEditorUnitCategoryCount(1,row));
 MapEditor_DrawCatalogueCell(21,rowStart,row,GetEditorUnitCategoryCount(2,row));
 MapEditor_DrawCatalogueCell(23,rowStart,row,GetEditorUnitCategoryCount(3,row));
 MapEditor_DrawCatalogueCell(25,rowStart,row,GetEditorUnitCategoryCount(4,row));
 MapEditor_DrawCatalogueCell(27,rowStart,row,GetEditorUnitCategoryCount(7,row));
 MapEditor_DrawCatalogueCell(29,rowStart,row,GetEditorUnitCategoryCount(9,row));
 rowStart+=3;row++;
 }while(row<5);
 switch(GetMapEditorMode()){
 case 0:
 SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x480,8,4,3);
 SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x490,8,4,2);
 break;
 case 1:
 SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x480,8,4,2);
 SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x24)+0x490,8,4,3);
 break;
 }
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
 gCur3DSpriteEngine=savedEngine;
}
/* Prepare the selected terrain brush's tile graphics for the sub-engine sprite
 * bank: queue the brush's tiles and tile base into the back-buffer banks and copy
 * its palette in, then blend the palette unless the terrain palette page shows. */
void MapEditor_LoadTerrainBrushGraphics(void) {
    u8 GetMapEditorTerrainKind(void);
    u8 GetMapEditorTerrainOwner(void);
    s32 GetTerrainTileBase(s32);
    void *GetTerrainTileData(s32);
    void *GetTerrainPalette(s32, s32);
    void QueueMemoryCopy(s32, s32, s32, s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    void DimPalette(void *);
    u8 GetMapEditorMode(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    u8 kind;
    u8 owner;
    s32 tileBase;
    void *tileData;
    void *palette;
    s32 savedEngine;

    kind = GetMapEditorTerrainKind();
    owner = GetMapEditorTerrainOwner();
    tileBase = GetTerrainTileBase(kind);
    tileData = GetTerrainTileData(kind);
    palette = GetTerrainPalette(kind, owner);
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    QueueMemoryCopy((s32)tileData, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2D80, 0x100, 0);
    QueueMemoryCopy(tileBase, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F80, 0x200, 0);
    CopyToObjPaletteShadow(palette, 0x340, 0x20);
    if (GetMapEditorMode() != 0) {
        DimPalette((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x340));
    }
    gCur3DSpriteEngine = savedEngine;
}

void func_ov007_0221a018(void) {
    /* Prepare the tile graphics and schedule DMA transfers into the back buffer bank. */
    u8 GetMapEditorUnitKind(void);
    u8 GetMapEditorUnitOwner(void);
    s32 func_ov000_0216cd4c(s32);
    void *GetUnitIconTiles(s32, s32);
    void *GetArmyPalette(s32);
    void QueueMemoryCopy(s32, s32, s32, s32);
    void CopyToObjPaletteShadow(void *, s32, s32);
    void DimPalette(void *);
    u8 GetMapEditorMode(void);
    extern void *gCurrentMap;
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    u8 tileGroup;
    u8 slot;
    u8 tileAttr;
    s32 baseAddr;
    void *srcPtr;
    void *dstPtr;
    s32 savedBank;

    tileGroup = GetMapEditorUnitKind();
    slot = GetMapEditorUnitOwner();
    tileAttr = (u8) M2C_FIELD((M2C_FIELD(gCurrentMap, s32 *, 0) + slot * 0x8C + 0x6000), u8 *, 0x7CD);
    baseAddr = func_ov000_0216cd4c(tileGroup);
    srcPtr = GetUnitIconTiles(tileGroup, tileAttr);
    dstPtr = GetArmyPalette(slot);
    savedBank = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    QueueMemoryCopy((s32)srcPtr, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2D00, 0x80, 0);
    QueueMemoryCopy(baseAddr, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2E80, 0x100, 0);
    CopyToObjPaletteShadow(dstPtr, 0x320, 0x20);
    if (GetMapEditorMode() != 1) {
        DimPalette((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x320));
    }
    gCur3DSpriteEngine = savedBank;
}

void func_ov007_0221a104(void) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
extern void *gCurrentMap;
extern s32 data_ov007_02221e08;
s32 RenderTextToTiles(void *,void *);
s32 old=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineSub;
data_ov007_02221e08=RenderTextToTiles(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x1c)+0x3980,M2C_FIELD(gCurrentMap,u8 **,0)+0x5120);
gCur3DSpriteEngine=old;
}

typedef struct MapEditorBankFlags {
    u16 mode : 3;
    u16 flags : 13;
} MapEditorBankFlags;

typedef struct MapEditorPreviewPreset {
    u16 mode;
    u16 layerSetup;
    u16 layers[4];
} MapEditorPreviewPreset;

void func_ov007_0221a160(void) {
    M2C_UNK Clear3DSpriteLayer(s32);
    M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
    M2C_UNK SetFileDirectory();
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    void OpenNarcArchive(M2C_UNK);
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK, M2C_UNK);
    void LoadFileToSpriteBuffer(M2C_UNK, s32, s32);
    s32 Get3DSpriteLayerSize(u8, s32);
    void AddToU16Array(M2C_UNK, u16, s32);
    void DrawMapPreview(s32, s32, s32, s32);
    void CreateWallpaperSprite(s32, s32, s32);
    void InitTextTiles(s32, s32, s32);
    void LoadScenePanelPalette(s32);
    void LoadSpriteResource(s32, s32, s32, M2C_UNK);
    M2C_UNK GetArmyStateTiles(s32);
    void MI_CpuCopy32(M2C_UNK, M2C_UNK, s32);
    void SetFrameRectPattern(s32, s32);
    void DimPalette(void *);
    void MapEditor_FitPreviewToMap(void);

    extern const MapEditorPreviewPreset data_ov007_0221f508;
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern M2C_UNK data_ov007_022200d8;
    extern M2C_UNK data_ov007_022200e4;
    extern M2C_UNK data_ov007_022200f0;
    extern M2C_UNK data_ov007_022200fc;
    extern M2C_UNK data_ov007_02220108;
    extern M2C_UNK data_ov007_02220114;
    extern M2C_UNK data_ov007_02220120;
    extern M2C_UNK data_ov007_02220130;
    extern M2C_UNK data_ov007_02220140;
    extern M2C_UNK data_ov007_0222014c;
    extern M2C_UNK data_ov007_02220158;
    extern M2C_UNK data_ov007_02220164;
    extern M2C_UNK data_ov007_02220170;

    u16 *volatile p0;
    u16 *volatile p1;
    u16 *volatile p2;
    u16 *volatile p3;
    u16 *volatile p4;
    u16 *volatile p5;
    s32 savedEngine;
    MapEditorPreviewPreset preset;
    s32 base;
    s32 zero, two;
    s32 i;

    preset = data_ov007_0221f508;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    Clear3DSpriteLayer(0);
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    Clear3DSpriteLayer(3);

    p0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p0 = (u16)(*p0 & ~7);
    Apply3DSpriteLayout((M2C_UNK *)&preset);

    p1 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p1 = (u16)(*p1 | 0x10);
    p2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p2 = (u16)(*p2 | 0x20);
    p3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p3 = (u16)(*p3 | 0x40);
    p4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p4 = (u16)(*p4 | 0x80);
    p5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p5 = (u16)(*p5 | 0x100);

    SetFileDirectory(&data_ov007_022200d8);

    OpenNarcArchive(GetLocalizedFileName(&data_ov007_022200e4));

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_022200f0), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_022200fc), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));

    CloseNarcArchive();

    LoadFileToSpriteBuffer(&data_ov007_02220108, 0x40, 0x180);

    {
        MapEditorBankFlags *flags = M2C_FIELD(gCur3DSpriteEngine, MapEditorBankFlags **, 0);
        s32 sh = Get3DSpriteLayerSize(flags->mode, 1);
        AddToU16Array(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), (u16)sh, 0x2000);
    }

    two = 2;
    zero = 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3A) = two;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x42) = zero;
    DrawMapPreview(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 1, 14);

    CreateWallpaperSprite(3, 0xF, 6);
    InitTextTiles(zero, zero, 1);
    LoadScenePanelPalette(1);

    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x38) = two;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x40) = 1;
    {
        char *tiles = M2C_FIELD(gCur3DSpriteEngine, char **, 0x1C);
        LoadSpriteResource(1, zero, two, tiles + 0x2800);
    }
    LoadSpriteResource(1, zero, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2980);
    LoadSpriteResource(1, two, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x260);

    i = zero;
    base = 0x158;
    do {
        s32 dest = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + (base << 5);
        M2C_UNK ret = GetArmyStateTiles(i + 1);
        MI_CpuCopy32(ret, dest, 0x80);
        i++;
        base += 4;
    } while (i < 4);

    SetFrameRectPattern(0x80, 1);

    SetFileDirectory(&data_ov007_02220114);

    LoadFileToSpriteBuffer(&data_ov007_02220120, 0x360, 0x20);
    LoadFileToSpriteBuffer(&data_ov007_02220130, 0x380, 0x20);

    DimPalette((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x380));

    SetFileDirectory(&data_ov007_02220140);

    OpenNarcArchive(GetLocalizedFileName(&data_ov007_0222014c));

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_02220158), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3180);

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_02220164), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x3580);

    CloseNarcArchive();

    LoadFileToSpriteBuffer(&data_ov007_02220170, 0x3A0, 0x20);

    LoadScenePanelPalette(0x1E);

    gCur3DSpriteEngine = savedEngine;

    MapEditor_FitPreviewToMap();
}

void func_ov007_0221a568(void) {
    M2C_UNK func_020af1e4();
    M2C_UNK RemoveMapViewSprites();
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    RemoveMapViewSprites();
    func_020af1e4();
    gCur3DSpriteEngine = temp_r4;
}

