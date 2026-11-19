/* 13 functions from 0x02219ACC to 0x0221A59C (ov007), found by ds-decomp. */
#include "common.h"

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

void func_ov007_02219bd8(void) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
void *func_ov000_0216ce84(s32);
void CopyToObjPaletteShadow(void *,s32,s32);
s32 MapEditor_PlayerHasTeam(s32);
void func_020ae528(void *);
s32 old=gCur3DSpriteEngine;
s32 i,offset;
gCur3DSpriteEngine=g3DSpriteEngineSub;
for(i=0;i<4;i++){
offset=(i+0x15)<<5;
CopyToObjPaletteShadow(func_ov000_0216ce84(i+1),offset,0x20);
if(!MapEditor_PlayerHasTeam(i+1))
func_020ae528(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x30)+(offset&~1));
}
gCur3DSpriteEngine=old;
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
    void func_020ae528(void *);
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
        func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x340));
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
    void func_020ae528(void *);
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
        func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x320));
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

void func_ov007_0221a160(void) {
    M2C_UNK Clear3DSpriteLayer(s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK SetFileDirectory();
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    void OpenNarcArchive(M2C_UNK);
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK, M2C_UNK);
    void LoadFileToSpriteBuffer(M2C_UNK, s32, s32);
    s32 Get3DSpriteLayerSize(s32);
    void AddToU16Array(M2C_UNK, u16, s32);
    void DrawMapPreview(M2C_UNK, M2C_UNK);
    void func_020af04c(s32, s32, s32);
    void InitTextTiles(s32, s32, s32);
    void LoadScenePanelPalette(s32);
    void func_020a9a30(s32, s32, s32, M2C_UNK);
    M2C_UNK func_ov000_0216ce10(s32);
    void MI_CpuCopy32(M2C_UNK, M2C_UNK, s32);
    void SetFrameRectPattern(s32, s32);
    void func_020ae528(void *);
    void MapEditor_FitPreviewToMap(void);

    extern u16 data_ov007_0221f508[];
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
    u16 arr[6];
    u8 i;
    s32 base;

    arr[0] = data_ov007_0221f508[0];
    arr[1] = data_ov007_0221f508[1];
    arr[2] = data_ov007_0221f508[2];
    arr[3] = data_ov007_0221f508[3];
    arr[4] = data_ov007_0221f508[4];
    arr[5] = data_ov007_0221f508[5];

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    Clear3DSpriteLayer(0);
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    Clear3DSpriteLayer(3);

    p0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p0 &= ~7;
    func_020822b8(arr);

    p1 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p1 |= 0x10;
    p2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p2 |= 0x20;
    p3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p3 |= 0x40;
    p4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p4 |= 0x80;
    p5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    *p5 |= 0x100;

    SetFileDirectory(&data_ov007_022200d8);

    OpenNarcArchive(GetLocalizedFileName(&data_ov007_022200e4));

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_022200f0), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));

    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_022200fc), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));

    CloseNarcArchive();

    LoadFileToSpriteBuffer(&data_ov007_02220108, 0x40, 0x180);

    {
        u16 w = *M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
        s32 sh = Get3DSpriteLayerSize(w & 7);
        AddToU16Array(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), (u16)sh, 0x2000);
    }

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3A) = 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x42) = 0;
    DrawMapPreview(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));

    func_020af04c(3, 0xF, 6);
    InitTextTiles(0, 0, 1);
    LoadScenePanelPalette(1);

    func_020a9a30(1, 0, 2, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2800);
    func_020a9a30(1, 0, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2980);
    func_020a9a30(1, 2, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x260);

    base = 0x158;
    for (i = 0; i < 4; i++) {
        M2C_UNK ret = func_ov000_0216ce10(i + 1);
        MI_CpuCopy32(ret, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + ((base + i * 4) << 5), 0x80);
    }

    SetFrameRectPattern(0x80, 1);

    SetFileDirectory(&data_ov007_02220114);

    LoadFileToSpriteBuffer(&data_ov007_02220120, 0x360, 0x20);
    LoadFileToSpriteBuffer(&data_ov007_02220130, 0x380, 0x20);

    func_020ae528((void *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x380));

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
    M2C_UNK func_020c127c();
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_020c127c();
    func_020af1e4();
    gCur3DSpriteEngine = temp_r4;
}

