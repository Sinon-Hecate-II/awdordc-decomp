/* 25 functions from 0x0216C7F0 to 0x0216D2B4 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_ui.h"
#include "battle_map.h"
#include "ds3dsprite.h"

/* Deleting destructor of the army info window: restore its base vtable, destroy
 * the stat panel through its own vtable, free each of the seven icon animations
 * (its frame table first) and then the window itself. */
void *DeleteArmyInfoWindow(void *window){
extern M2C_UNK gArmyInfoWindowVTable;
void MemFree(void *);
void *icon;
M2C_FIELD(window,void **,0)=&gArmyInfoWindowVTable;
icon=M2C_FIELD(window,void **,ARMY_INFO_PANEL);
if(icon)M2C_FIELD(M2C_FIELD(icon,void **,0),void (**)(void *),4)(icon);
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x00);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x04);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x08);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x0c);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x10);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x14);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x18);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
MemFree(window);
return window;
}

/* Non-deleting destructor of the army info window: restores the base vtable,
 * destroys the stat panel through its own vtable and frees each of the seven
 * icon animations (its frame table first), leaving the window itself allocated. */
void *ArmyInfoWindow_Destruct(void *window){
extern M2C_UNK gArmyInfoWindowVTable;
void MemFree(void *);
void *icon;
M2C_FIELD(window,void **,0)=&gArmyInfoWindowVTable;
icon=M2C_FIELD(window,void **,ARMY_INFO_PANEL);
if(icon)M2C_FIELD(M2C_FIELD(icon,void **,0),void (**)(void *),4)(icon);
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x00);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x04);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x08);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x0c);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x10);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x14);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
icon=M2C_FIELD(window,void **,ARMY_INFO_ICONS+0x18);if(icon){if(M2C_FIELD(icon,void **,0))MemFree(M2C_FIELD(icon,void **,0));MemFree(icon);}
return window;
}

/* Terrain kind (the low five bits of the cell's terrain byte) of the map cell at
 * (x, y). */
s32 GetCellTerrainKind(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map;

    map = *gCurrentMap;
    return M2C_FIELD((map + (x + M2C_FIELD((map + (y * 2)), u16 *, MAP_ROW_OFFSETS))), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
}

/* Maps the cell at (x,y) to the detailed terrain id the info window shows: certain
   tilesets turn impact/plain tiles into their own ids (32..41), otherwise the raw
   terrain kind is returned. */
s32 GetCellTerrainId(s32 x,s32 y){
extern s32 *gCurrentMap;
void *FindMapOrderAtTile(s32,s32);
s32 terrainKind,cellIndex,map; void *feature; map=*gCurrentMap;
cellIndex=x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS);
terrainKind=M2C_FIELD(map+cellIndex,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK;
switch(M2C_FIELD(map,u8 *,MAP_TILESET)){
case 0:if(terrainKind==29)return 32;break;
case 4:if(terrainKind==29)return 38;if(terrainKind==4)return 39;break;
case 8:if(terrainKind==29)return 37;if(terrainKind==2)return 36;break;
case 9:if(terrainKind!=29)break;feature=FindMapOrderAtTile(x,y);if(feature){u32 kind=((u32)M2C_FIELD(feature,u16 *,2)<<22)>>28;if(kind==6)return 34;if(kind==7)return 35;}return 33;
}
if(terrainKind==1){switch(M2C_FIELD(map+cellIndex*2,u16 *,MAP_CELL_TILE_ID)){case 4:return 40;case 5:return 41;}}
return terrainKind;
}

/* Maps a detailed terrain id back to the map's terrain kind: the ids 32..41 that
 * GetCellTerrainId hands out for tilesets drawing their own graphics of a tile
 * collapse onto the kind they stand for, and every other id is a terrain kind
 * already and is returned unchanged. */
s32 GetTerrainKindFromInfoId(s32 terrainId) {
    switch (terrainId) {
    case 32: terrainId = 29; break; /* plain tile of tileset 0 */
    case 38: terrainId = 29; break; /* plain tile of tileset 4 */
    case 39: terrainId = 4; break;  /* wooded tile of tileset 4 */
    case 37: terrainId = 29; break; /* plain tile of tileset 8 */
    case 36: terrainId = 2; break;  /* kind 2 tile of tileset 8 */
    case 34: terrainId = 29; break; /* plain tile of tileset 9 */
    case 35: terrainId = 29; break; /* plain tile of tileset 9 */
    case 33: terrainId = 29; break; /* plain tile of tileset 9 */
    case 40: terrainId = 1; break;  /* plain ground, tile 4 */
    case 41: terrainId = 1; break;  /* plain ground, tile 5 */
    }
    return terrainId;
}

/* The army that owns the property standing on the cell at (x, y): look the cell's
 * terrain byte up through the map's row offsets and ask which army owns it. */
s32 GetCellPropertyArmy(s32 x, s32 y) {
    s32 Map_GetPropertyOwnerArmy(s32);
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;

    return Map_GetPropertyOwnerArmy(M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN));
}

/* The terrain defense stars of the cell at (x, y): the terrain kind's star count plus
 * the current player's defense bonus, in tenths of a star, divided into whole stars
 * and clamped to 0..4. */
s32 GetCellTerrainDefense(s32 x, s32 y) {
    s32 GetTerrainDefenseScore(s32, s32, s32);
    s32 Divide(s32, s32);
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    s32 defense = Divide(GetTerrainDefenseScore(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER), 0, M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK), 10);

    if (defense > 4) return 4;
    if (defense < 0) return 0;
    return defense;
}

u32 GetUnitKind(u8 *arg0) {
    return (u32) (*arg0 << 0x1A) >> 0x1A;
}

/* Number of ten-HP segments a unit's health bar shows: none at 0 HP, otherwise
 * one per started group of ten (100 HP draws ten segments). */
s32 GetUnitHealthBarCount(void *unit) {
    s32 Divide(s32, M2C_UNK);
    u32 health;

    health = (u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 0x19) >> 0x19;
    if (health == 0) {
        return 0;
    }
    return Divide(health - 1, 10) + 1;
}

u32 func_ov000_0216cd2c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19;
}

u32 GetUnitAmmo(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C;
}

/* Base address of the status-panel tiles for unit `kind`: the start of the name
 * graphics file (block set 1) plus the kind's UNIT_KIND_STATS_STATUS_TILE block
 * index times 0x100 bytes.  The caller copies 256 bytes of panel from here. */
s32 GetUnitStatusTileBase(s32 kind) {
s32 GetNameGraphicFile(s32);extern u8 gUnitKindStatusTile;
return GetNameGraphicFile(1)+((&gUnitKindStatusTile)[kind*0x70]<<8);
}

/* Base of the 0x80-byte unit icon tile block for the current unit variant in the
 * unit icon tile table data_02121e08. */
void *GetUnitIconTiles(void) {
    s32 GetUnitVariantIndex();
    extern M2C_UNK data_02121e08;
    return (u8 *)&data_02121e08 + (GetUnitVariantIndex() << 7);
}

void *GetArmyPalette(s32 arg0) {
    extern M2C_UNK gArmyPalettes;
    return (u8 *)&gArmyPalettes + ((arg0 - 1) << 5);
}

/* Address of the terrain tile graphics for terrain `terrainId` in the loaded name
 * graphics file (block set 0): the terrain's three-byte index record gives, at +1,
 * the 0x200-byte tile block to add. The caller copies 512 bytes from here. */
s32 GetTerrainTileBase(s32 terrainId) {
    s32 GetNameGraphicFile(s32);
    extern u8 gTerrainTileBaseBlock;
    return GetNameGraphicFile(0) + (((&gTerrainTileBaseBlock)[terrainId * 3]) << 9);
}

/* Address of the 256-byte terrain tile data block for terrain `terrainId`: the
 * terrain's three-byte index record gives the block index into the loaded terrain
 * tile data buffer.  The caller copies 256 bytes from here. */
void *GetTerrainTileData(s32 terrainId) {
extern u8 gTerrainTileData;extern u8 gTerrainTileDataBlock;
return &gTerrainTileData+((&gTerrainTileDataBlock)[terrainId*3]<<8);
}

/* Address of the 32-byte palette for terrain `terrainId`'s `variant` (0 or 1) in
 * the loaded palette buffer: the terrain's three-byte record gives the palette
 * block, and each block holds the terrain's two palettes. The caller copies 32
 * bytes from here. */
void *GetTerrainPalette(s32 terrainId,s32 variant) {
extern u8 gTerrainPaletteData;extern u8 gTerrainPaletteBlock;
return &gTerrainPaletteData+((variant+(&gTerrainPaletteBlock)[terrainId*3])<<5);
}

/* Return the 0x80-byte face-icon tile graphic for an army state: states 1..5 use
 * the first five blocks, state 0 (no army) the sixth, anything else has none. */
void *GetArmyStateTiles(u32 armyState) {
    extern M2C_UNK gArmyStateTiles;
    switch (armyState) {
    case 1: return (u8 *)&gArmyStateTiles;
    case 2: return (u8 *)&gArmyStateTiles + ARMY_TILE_BYTES * 1;
    case 3: return (u8 *)&gArmyStateTiles + ARMY_TILE_BYTES * 2;
    case 4: return (u8 *)&gArmyStateTiles + ARMY_TILE_BYTES * 3;
    case 5: return (u8 *)&gArmyStateTiles + ARMY_TILE_BYTES * 4;
    case 0: return (u8 *)&gArmyStateTiles + ARMY_TILE_BYTES * 5;
    default: return 0;
    }
}

/* Return the army icon palette for an army id: ids 1..4 use the first four
 * 16-colour palettes, id 0 (no army) the last one, anything else has none. */
void *GetArmyIconPalette(u32 armyId) {
 extern M2C_UNK gArmyIconPalettes;
 switch(armyId) {
 case 1:return (u8 *)&gArmyIconPalettes;
 case 2:return (u8 *)&gArmyIconPalettes+DS3D_PALETTE_BYTES*1;
 case 3:return (u8 *)&gArmyIconPalettes+DS3D_PALETTE_BYTES*2;
 case 4:return (u8 *)&gArmyIconPalettes+DS3D_PALETTE_BYTES*3;
 case 0:return (u8 *)&gArmyIconPalettes+DS3D_PALETTE_BYTES*4;
 default:return 0;
 }
}

/* Point the resource loader back at the army info archive directory
 * ("/info/syogun_info") after loading a CO face or name file from elsewhere. */
void SetArmyInfoFileDirectory(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    extern M2C_UNK sArmyInfoDir;
    SetFileDirectory(&sArmyInfoDir);
}

/* Reloads the selected army's CO face on the bottom screen: clears its VRAM
 * area, loads the face texture and palette into the alternate face page, fills
 * the 2x2 face tile map, positions the sprite bank and marks the layer dirty.
 * The battle UI's file directory is restored before the engine pointer is put
 * back. */
void ArmyInfo_DrawFaceMain(void){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*gArmyInfoState;
void *saved=gCur3DSpriteEngine;s32 tile;
gCur3DSpriteEngine=g3DSpriteEngineMain;
tile=M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_FACE_PAGE)?1:13;
MI_CpuFill32(0,DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[0],64);
LoadFaceTexture(M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_FACE_MAIN),0,DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[0]+(tile<<6));
LoadFacePalette(M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_FACE_MAIN),0,2,M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_FACE_PAGE),0);
FillFaceTileMap(0,1,21,(s32)DS3D_ENGINE(gCur3DSpriteEngine)->layerTiles[0],(u16)tile,M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_FACE_PAGE),1);
*(u16 *)&DS3D_BANK(gCur3DSpriteEngine)->corner[0]=0xffff;
DS3D_BANK(gCur3DSpriteEngine)->corner[4]=1;
DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty|=1;
SetArmyInfoFileDirectory();
gCur3DSpriteEngine=saved;
}

/* Draw the selected CO portrait on the sub screen, or clear its panel when absent. */
void ArmyInfo_DrawFaceSub(void) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *gArmyInfoState;
    void *savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (M2C_FIELD(gArmyInfoState, u8 *, ARMY_INFO_FACE_SUB)) {
        MI_CpuFill32(0, DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[0], 64);
        LoadFaceTexture(M2C_FIELD(gArmyInfoState, u8 *, ARMY_INFO_FACE_MAIN), 8, DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[0] + 64);
        LoadFacePalette(M2C_FIELD(gArmyInfoState, u8 *, ARMY_INFO_FACE_MAIN), 8, 2, 0, 0);
        FillFaceTileMap(8, 12, 0, (s32)DS3D_ENGINE(gCur3DSpriteEngine)->layerTiles[0], 1, 0, 0);
        DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= 1;
        SetArmyInfoFileDirectory();
    } else {
        ClearTileRect((s32)DS3D_ENGINE(gCur3DSpriteEngine)->layerTiles[0] + 24, 20, 24);
        DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= 1;
    }
    gCur3DSpriteEngine = savedEngine;
}

/* Load the selected CO's name graphic from shogun_name.narc into the sub screen
 * engine's texture VRAM, or clear that range while the CO has no name file. */
void ArmyInfo_RefreshNameGraphic(void) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK SetShogunInfoFileDirectory();
    M2C_UNK *GetNameFileForFace(u8);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK sShogunNameNarc;
    extern void *gArmyInfoState;
    M2C_UNK *nameFile;
    s32 noNameFile;
    void *savedEngine;

    nameFile = GetNameFileForFace(M2C_FIELD(gArmyInfoState, u8 *, ARMY_INFO_FACE_SUB));
    noNameFile = nameFile == NULL;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (!noNameFile) {
        SetShogunInfoFileDirectory();
        GetLocalizedFileName(&sShogunNameNarc);
        OpenNarcArchive();
        LoadNarcFileDecompressed(GetLocalizedFileName(nameFile), M2C_FIELD(g3DSpriteEngineSub, s32 *, DS3D_ENGINE_TEXTURE) + ARMY_INFO_NAME_TEXTURE_OFFSET);
        CloseNarcArchive();
        SetArmyInfoFileDirectory();
    } else {
        MI_CpuFill32(0, M2C_FIELD(g3DSpriteEngineSub, s32 *, DS3D_ENGINE_TEXTURE) + ARMY_INFO_NAME_TEXTURE_OFFSET, ARMY_INFO_NAME_TEXTURE_SIZE);
    }
    gCur3DSpriteEngine = savedEngine;
}

/* Load the selected player's army-state icon graphic (from its record's army
 * state byte) and that army's palette into the sub screen's texture VRAM, so the
 * army info window shows the player's state icon. */
void ArmyInfo_RefreshStateIcon(void) {
 void MI_CpuCopy32(void *,s32,s32);
 void CopyToObjPaletteShadow(void *,s32,s32);
 extern void *gArmyInfoState;
 extern s32 *gCurrentMap;
 extern void *g3DSpriteEngineSub;
 s32 record = *gCurrentMap + MAP_PLAYER_STATES + M2C_FIELD(gArmyInfoState,u8 *,M2C_FIELD(gArmyInfoState,u8 *,ARMY_INFO_SELECTED))*MAP_PLAYER_STRIDE;
 s32 dest = M2C_FIELD(g3DSpriteEngineSub,volatile s32 *,DS3D_ENGINE_TEXTURE);
 MI_CpuCopy32(GetArmyStateTiles(M2C_FIELD(record,u8 *,PLAYER_REC_ARMY_STATE)),dest+0x3000,128);
 CopyToObjPaletteShadow(GetArmyIconPalette(M2C_FIELD(record,u8 *,PLAYER_REC_ARMY_INDEX)),0x2e0,32);
}

/* Draw the selected player's army state label into the sub screen texture. */
void ArmyInfo_RefreshStateLabel(void) {
    s32 GetArmyStateLabel(s32);
    void ClearTextBitmap(s32, s32);
    s32 RenderTextToTiles(s32, s32);
    extern void *gArmyInfoState;
    extern s32 *gCurrentMap;
    extern void *g3DSpriteEngineSub;
    ArmyInfoSelection *selection = gArmyInfoState;
    s32 label = GetArmyStateLabel(M2C_FIELD(
        *gCurrentMap + selection->playerRecords[selection->selected] * MAP_PLAYER_STRIDE,
        u8 *, PLAYER_ARMY_STATE_OFF));

    ClearTextBitmap(DS3D_ENGINE(g3DSpriteEngineSub)->textureAddr + ARMY_INFO_STATE_LABEL_OFFSET,
                    ARMY_INFO_STATE_LABEL_WIDTH);
    RenderTextToTiles(DS3D_ENGINE(g3DSpriteEngineSub)->textureAddr + ARMY_INFO_STATE_LABEL_OFFSET,
                      label);
}

