/* 37 functions from 0x020D7BC8 to 0x020D8BB4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
extern s32 gMapCategory;
static inline u16 TerrainSpriteY(s32 y) { return (u16)y; }
/* The OBJ boundary value, bits 13..14 of the current sprite bank's flags word
 * (DS3D_BANK_OBJ_BOUNDARY_MASK >> 13): the shift the terrain and unit sprites
 * scale their tile numbers by. */
#define DS3D_BOUNDARY_SHIFT ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)

#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws a unit's status panel at (x,y): kind icon, health bars, ammo, attack and
 * movement icons plus the owning player's colour strip. */
void DrawUnitStatus(s32 x,s32 y,s32 side,void *unit) {
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine;
extern u8 gSpriteDesc8x8[],gSpriteDesc32x16[],gSpriteDesc16x16[];
s32 GetUnitKind(void *);
s32 GetUnitHealthBarCount(void *);
s32 func_ov000_0216cd2c(void *);
s32 GetUnitAmmo(void *);
s32 GetUnitStatusTileBase(s32);
s32 GetUnitIconTiles(s32,s32);
s32 GetArmyPalette(s32);
void QueueMemoryCopy(s32,s32,s32,s32);
void CopyToObjPaletteShadow(s32,s32,s32);
s32 UnitKindCanSupply(s32);
s32 GetUnitKindMaxAmmo(s32);
void DrawDecimalNumber(s32,s32,s32);
void AddSprite(u16,u16,u16,void *,s32);
s32 unitKind=GetUnitKind(unit);
s32 colorIndex,variantIndex,screenY;
s32 unitId;
u8 *playerData;
if(unit==0)unitId=0;else unitId=((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
playerData=(u8 *)*gCurrentMap+0x67a4+((unitId>>6)+1)*140;
colorIndex=playerData[0x1d];variantIndex=playerData[0x29];
screenY=(y+16)&255;
AddSprite((u16)((x+23)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (22 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+39)&511,screenY,GetUnitHealthBarCount(unit));
AddSprite((u16)((x+47)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (24 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+63)&511,screenY,func_ov000_0216cd2c(unit));
if(UnitKindCanSupply((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)) {
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (58 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (26 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}
if(GetUnitKindMaxAmmo((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0) {
AddSprite((u16)((x+79)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (20 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
DrawDecimalNumber((x+79)&511,screenY,GetUnitAmmo(unit));
}
QueueMemoryCopy(GetUnitStatusTileBase(unitKind),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4480,256,0);
AddSprite((u16)((x+20)&511),(u16)((y+2)&255),(u16)((0x3ff & (0x224 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x9000),gSpriteDesc32x16,8);
CopyToObjPaletteShadow(GetArmyPalette(colorIndex),0x300,32);
QueueMemoryCopy(GetUnitIconTiles(unitKind,variantIndex),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4300,128,0);
AddSprite((u16)((x+4)&511),(u16)((y+4)&255),(u16)((0x3ff & (0x218 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x8000),gSpriteDesc16x16,9);
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws the terrain panel of the map's unit-info window for the tile at
 * (tx,ty), positioned at screen (x,y): the terrain's defense stars, the
 * capture points left on a property (or the HP left of a destructible
 * terrain), and the terrain's tile graphics and owner-army palette. */
void DrawTerrainStatus(s32 x,s32 y,s32 tx,s32 ty,s32 side,void *unit) {
extern void **gCurrentMap;extern void *gCur3DSpriteEngine;
extern u8 gSpriteDesc32x8[],gSpriteDesc16x16[],gSpriteDesc8x8[],gSpriteDesc64x16[],gSpriteDesc16x32[];extern s8 gTerrainPropertyFlags[];
s32 GetCellTerrainKind(s32,s32);s32 GetCellTerrainId(s32,s32);s32 GetCellPropertyArmy(s32,s32);s32 GetCellTerrainDefense(s32,s32);
void *FindMapFeatureAtTile(s32,s32);s32 GetTerrainTileBase(s32);s32 GetTerrainTileData(s32);s32 GetTerrainPalette(s32,s32);
s32 value; u8 screenY; s32 terrainId,armyVariant,defense;void *feature;void *map;u32 cellIndex;s32 terrainKind;
terrainKind=GetCellTerrainKind(tx,ty);terrainId=GetCellTerrainId(tx,ty);armyVariant=GetCellPropertyArmy(tx,ty);defense=GetCellTerrainDefense(tx,ty);screenY=y+40;
AddSprite((u16)((x+23)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (defense*6+64 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc32x8,8);
if(gTerrainPropertyFlags[terrainKind&31]){
value=20;if(unit)value-=((u32)(M2C_FIELD(unit,u16*,6)<<16)>>27);
AddSprite((u16)((x+56)&511),(u16)((y+32)&255),(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (28 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc16x16,8);
DrawDecimalNumber((x+78)&511,screenY,value);
}else{
value=0;feature=FindMapFeatureAtTile(tx,ty);if(feature)value=M2C_FIELD(feature,u8*,4);
map=*gCurrentMap;
{s32 hp=M2C_FIELD((u8*)map+(tx+M2C_FIELD((u8*)map+ty*2,u16*,MAP_ROW_OFFSETS)),u8*,MAP_CELL_TERRAIN_HP)&127;if(hp)value=hp;}
if(value){
AddSprite((u16)((x+60)&511),TerrainSpriteY(screenY),(u16)(((0x3ff & (0x150 >> DS3D_BOUNDARY_SHIFT)) | 0x9000) + (0x3ff & (22 >> DS3D_BOUNDARY_SHIFT))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+78)&511,screenY,value);
}}
QueueMemoryCopy(GetTerrainTileBase(terrainId),M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x4580,512,0);
AddSprite((u16)((x+20)&511),(u16)((y+26)&255),(u16)((0x3ff&(0x22c>>DS3D_BOUNDARY_SHIFT))+0x9000),gSpriteDesc64x16,8);
map=*gCurrentMap;cellIndex=tx+M2C_FIELD((u8*)map+ty*2,u16*,MAP_ROW_OFFSETS);
if(!((u8)(M2C_FIELD((u8*)map+(cellIndex>>3),u8*,MAP_CELL_BITMAP)&(1<<(cellIndex&7)))))if(terrainKind!=MAP_TERRAIN_HQ)armyVariant=0;
QueueMemoryCopy(GetTerrainTileData(terrainId),M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x4200,256,0);
CopyToObjPaletteShadow(GetTerrainPalette(terrainId,armyVariant),0x2e0,32);
AddSprite((u16)((x+4)&511),(u16)((y+12)&255),(u16)((0x3ff&(0x210>>DS3D_BOUNDARY_SHIFT))+0x7000),gSpriteDesc16x32,8);
}
#pragma pop
/* Classifies the unit-info panel a map unit needs: 0 for no unit (the terrain
   panel), 2 when the unit is a transport whose carried units are shown, and 1 for
   an ordinary unit's status panel. */
s32 GetUnitPanelKind(void *unit) {
    s32 Map_ShowsCargoForUnit(u32, u16, u8);
    extern void **gCurrentMap;
    s32 unitId;
    if (unit == NULL) return 0;
    if (unit == NULL) unitId = 0;
    else unitId = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
    if (Map_ShowsCargoForUnit((u32)(M2C_FIELD(unit,u8 *,0) << 26) >> 26, M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER), (u8)((unitId >> 6)+1)) != 0) return 2;
    if ((M2C_FIELD(unit,u8 *,MAP_UNIT_FIRST_CARRIED) | M2C_FIELD(unit,u8 *,MAP_UNIT_NEXT_CARRIED)) != 0) return 2;
    return 1;
}

/* Refreshes the cached cursor-cell coordinates (X and Y) from the cursor's target
 * tile, leaving the cache's flag bits alone. */
void RefreshMapCursorCellCacheCoords(void) {
    extern void **gCurrentMap;
    void *map;

    map = *gCurrentMap;
    M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) =
        (M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) & ~MAP_CURSOR_CELL_COORD_MASK) |
        ((u32)(M2C_FIELD(map, u16 *, MAP_CURSOR_TARGET_X) << 25) >> 23);
    map = *gCurrentMap;
    M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) =
        (M2C_FIELD(map, u16 *, MAP_CURSOR_CELL_CACHE) & ~MAP_CURSOR_CELL_COORD_Y_MASK) |
        ((u32)(M2C_FIELD(map, u16 *, MAP_CURSOR_TARGET_Y) << 25) >> 16);
}

void StepCursorCellDisplayModeToLower(void) {
    /* Ease the camera height towards its target (168), using the hardware divider. */
    extern void **gCurrentMap;
    s32 Divide(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 0) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3) | 1;
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= -99) M2C_FIELD(mapData, s16 *, 0x52E4) = 262;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) + 100, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) > 168) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 169) M2C_FIELD(mapData, s16 *, 0x52E4) = 168;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) - 168, 2);
        RefreshMapCursorCellCacheCoords();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 168) RefreshMapCursorCellCacheCoords();
}

void StepCursorCellDisplayModeToUpper(void) {
    /* Ease the camera height across the 0/268 wrap boundary, using the hardware divider. */
    extern void **gCurrentMap;
    s32 Divide(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 168) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3);
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 267) M2C_FIELD(mapData, s16 *, 0x52E4) = -94;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4) - 268, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) < 0) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= -1) M2C_FIELD(mapData, s16 *, 0x52E4) = 0;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= Divide(M2C_FIELD(mapData, s16 *, 0x52E4), 2);
        RefreshMapCursorCellCacheCoords();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 0) RefreshMapCursorCellCacheCoords();
}

/* Returns the cursor-cell display mode the cursor's target tile needs: which of
 * the two screens the tile is projected onto (1 for the lower screen, 0 for the
 * upper), or the mode already cached when the tile is not in the lower part of
 * the view. */
s32 GetCursorCellDisplayMode(void) {
    void MapTileToScreen(s16, s16, s32 *);
    extern void **gCurrentMap;
    s32 screenPos[3];
    void *map;

    map = *gCurrentMap;
    MapTileToScreen(M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y), screenPos);
    if (screenPos[1] > 128) return screenPos[0] < 128 ? 1 : 0;
    return (u32)(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_CELL_CACHE) << 30) >> 30;
}

/* Ease the cursor cell's display mode toward the screen its target tile is on:
 * down to the lower screen or up to the upper one. */
void StepCursorCellDisplayMode(void) {
    void StepCursorCellDisplayModeToLower();
    void StepCursorCellDisplayModeToUpper(void);
    s32 displayMode;

    displayMode = GetCursorCellDisplayMode();
    switch (displayMode) {                              /* irregular */
    case 0:
        StepCursorCellDisplayModeToUpper();
        return;
    case 1:
        StepCursorCellDisplayModeToLower();
        return;
    }
}

/* Set the cursor cell's display mode to the screen its target tile is on: the
 * upper screen (0) or the lower one (0xA8). */
void UpdateCursorCellDisplayMode(void) {
    extern void **gCurrentMap;
    s32 displayMode;

    displayMode = GetCursorCellDisplayMode();
    switch (displayMode) {
    case 0:
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_CELL_DISPLAY_MODE) = MAP_CURSOR_CELL_UPPER;
        return;
    case 1:
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_CELL_DISPLAY_MODE) = MAP_CURSOR_CELL_LOWER;
        return;
    }
}

/* Set the category of map the map-select list is browsing (read back with
 * GetMapCategory; it picks the list mode and setup callback). */
void SetMapCategory(s32 category) {
    extern s32 gMapCategory;
    gMapCategory = category;
}

/* Return the category of map the map-select list is browsing (set by
 * SetMapCategory when the list opens). */
s32 GetMapCategory(void) {
    return gMapCategory;
}

/* Create the map-select screen object: its script resets the dialog and text
 * UI, refreshes the save-slot records and then runs the map-list screen, which
 * is where the game returns after a battle or the campaign ending. */
void OpenMapSelectScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapSelectScreenClass;
    CreateSpriteFromClass(&gMapSelectScreenClass, 7);
}

/* Open the map-select screen after the map list runs, keeping the text input:
 * its class resets the dialog UI and refreshes the save-slot records, then runs
 * the shared map-list screen (unlike OpenMapSelectScreen it does not clear the
 * text input). */
M2C_UNK OpenMapSelectScreenKeepingText(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMapSelectScreenKeepingTextClass;
    CreateSpriteFromClass(&gMapSelectScreenKeepingTextClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Create the ending screen: the sprite whose class loads the ending resource
 * (archive slot 0xB) and plays the campaign's final-map ending. */
void CreateEndingScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gEndingScreenClass;
    CreateSpriteFromClass(&gEndingScreenClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Select battle mode 4 in the map configuration and open the map-list screen
 * sprite for that map category (class data_0212bfb8). */
M2C_UNK OpenMode4MapList(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_0212bfb8;
    gMapConfig = (gMapConfig & ~MAPCONFIG_MODE_MASK) | 4;
    CreateSpriteFromClass(&data_0212bfb8, 7);
}

/* Open the map-list screen in battle mode 1 (free play/versus): run the mode's
 * scene hook (an empty stub in this build) and then select mode 1.  Its twin
 * SetMapConfigMode1WithNoOpCallback is byte-identical. */
void OpenMode1MapList(void) {
    M2C_UNK NoOpMapConfigCallback();
    M2C_UNK SetMapConfigMode1();
    NoOpMapConfigCallback();
    SetMapConfigMode1();
}

/* Run the no-op map-config callback, then select config mode 1 and create its UI sprite. */
void SetMapConfigMode1WithNoOpCallback(void) {
    M2C_UNK SetMapConfigMode1();
    M2C_UNK NoOpMapConfigCallback();
    NoOpMapConfigCallback();
    SetMapConfigMode1();
}

/* Reset the map config to its free-play defaults and apply the resulting map
 * settings (no explicit settings block, so the current defaults) to the players. */
void ResetMapConfigAndApplyPlayerSettings(void) {
    M2C_UNK ResetMapConfig();
    M2C_UNK ApplyMapSettingsToPlayers(M2C_UNK);
    ResetMapConfig();
    ApplyMapSettingsToPlayers(0);
}

/* Marks the battle as ended (with no end condition recorded, so the outcome is
 * decided by the players still in it) when a link or online session is active;
 * a no-op otherwise. */
void SetBattleEndedForSession(void) {
    s32 IsLinkSessionActive();
    extern M2C_UNK gBattleEndState;
    if (IsLinkSessionActive() == 0) {
        return;
    }
    M2C_FIELD(&gBattleEndState, s8 *, BATTLE_END_ENDED) = 1;
    M2C_FIELD(&gBattleEndState, s8 *, BATTLE_END_FLAG1) = 0;
    M2C_FIELD(&gBattleEndState, s8 *, BATTLE_END_FLAG2) = 0;
    M2C_FIELD(&gBattleEndState, s8 *, BATTLE_END_FLAG3) = 1;
}

/* Set the map config's battle-mode field (the low three bits of MAPCONFIG_FLAGS)
 * to 1 and create the map sprite class of that mode. */
M2C_UNK SetMapConfigMode1(void) {
 M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c1a0;
 gMapConfig=(gMapConfig&~MAPCONFIG_MODE_MASK)|1;
 CreateSpriteFromClass(&data_0212c1a0,7);
}

/* Enter the versus battle: resume the saved versus battle when its save record
 * exists, otherwise open the map mode 1 (free-play/versus) setup screen. */
void EnterVersusBattle(void) {
    M2C_UNK CreateSavedBattleView(M2C_UNK);
    extern M2C_UNK gSaveRecordExists;

    if (M2C_FIELD(&gSaveRecordExists, s8 *, SAVE_RECORD_TYPE_VERSUS) != 0) {
        CreateSavedBattleView(SAVE_RECORD_TYPE_VERSUS);
        return;
    }
    SetMapConfigMode1();
}

/* Enter the map editor's screen: switch the battle config to map mode 2 (the
 * map editor's mode) and create the map editor screen object. */
void EnterMapEditorScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK gMapEditorScreenAnim;

    gMapConfig = (gMapConfig & ~MAPCONFIG_MODE_MASK) | 2;
    CreateSpriteFromClass(&gMapEditorScreenAnim, 7);
}

/* Spawn the scripted screen sprite for the battle's stage title: its class first
 * makes sure archive resource slot 5 is loaded, then hands over to the ov004
 * battle overlay, which shows the stage's name graphic (name_%02d.cg). */
void CreateStageTitleScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gStageTitleScreenClass;
    CreateSpriteFromClass(&gStageTitleScreenClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Spawn the scripted sprite that loads and opens the Records menu. */
void CreateRecordsMenuSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gRecordsMenuSpriteClass;
    CreateSpriteFromClass(&gRecordsMenuSpriteClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Campaign menu entry: start the campaign in save slot 0, or resume the campaign
 * already saved there. */
void StartCampaignSlot0(void) {
    M2C_UNK StartCampaignFromSlot(M2C_UNK);
    StartCampaignFromSlot(0);
}

/* Campaign menu entry: start the campaign in save slot 1, or resume the campaign
 * already saved there. */
void StartCampaignSlot1(void) {
    StartCampaignFromSlot(1);
}

/* Campaign menu entry: start the campaign in save slot 2, or resume the campaign
 * already saved there. */
void StartCampaignSlot2(void) {
    StartCampaignFromSlot(2);
}

/* Spawn the scripted sprite that loads and opens the History menu. */
void CreateHistoryMenuSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gHistoryMenuSpriteClass;
    CreateSpriteFromClass(&gHistoryMenuSpriteClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Whether the battle mode in the low three bits of the map configuration is 7
 * (the mode-7 map list that OpenMode7MapList selects). */
u8 IsMapConfigMode7(void) {
    extern u16 gMapConfig;
    u8 result;

    if ((u8)((u32)(gMapConfig << 0x1D) >> 0x1D) == 7) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Set the map config's battle mode to 6 (the low bits of MAPCONFIG_FLAGS) and
 * create the map-list screen of that mode. */
M2C_UNK SetMapConfigMode6(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_0212c0d8;

    gMapConfig = (gMapConfig & ~MAPCONFIG_MODE_MASK) | 6;
    CreateSpriteFromClass(&data_0212c0d8, 7);
}

void func_020d8abc(void) {
    M2C_UNK SetMapConfigMode6();
    SetMapConfigMode6();
}

/* Create the front-end sequence screen: its class runs the front-end sequence
 * sprite and then starts the battle map. */
void CreateFrontEndSequenceScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gFrontEndSequenceScreenClass;
    CreateSpriteFromClass(&gFrontEndSequenceScreenClass, DS3D_SPRITE_DEFAULT_LAYER);
}

/* Select battle mode 7 in the map configuration and open the map-list screen
 * sprite for that map category (class data_0212c0d8, shared with mode 6). */
M2C_UNK OpenMode7MapList(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_0212c0d8;
    gMapConfig = (gMapConfig & ~MAPCONFIG_MODE_MASK) | 7;
    CreateSpriteFromClass(&data_0212c0d8, 7);
}

/* Spawn the scripted sprite (class gMicTestScreenClass) that creates the mic test
 * object and then opens its dialog box. */
void OpenMicTestScreen(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMicTestScreenClass;
    CreateSpriteFromClass(&gMicTestScreenClass, DS3D_SPRITE_DEFAULT_LAYER);
}

void func_020d8b28(void) {
    M2C_UNK OpenMapSelectScreenKeepingText();
    OpenMapSelectScreenKeepingText();
}

/* Select the category-specific map-list mode, then run that category's setup callback. */
void ApplyMapCategorySelection(void) {
    extern M2C_UNK gMapCategorySelectionCallbacks;
    extern M2C_UNK gMapCategorySelectionModes;
    extern M2C_UNK gOptionBits;
    s32 GetMapCategory(void);
    void (*setupCallback)(void);
    u16 mapListMode;

    setupCallback = M2C_FIELD((u8 *)&gMapCategorySelectionCallbacks + GetMapCategory() * 8, void (**)(void), 0);
    mapListMode = M2C_FIELD((u8 *)&gMapCategorySelectionModes + GetMapCategory() * 8, u32 *, 0);
    M2C_FIELD(&gOptionBits, u16 *, 6) = (M2C_FIELD(&gOptionBits, u16 *, 6) & ~15) | (mapListMode & 15);
    setupCallback();
}

/* For the versus save-list entry (kind 1) load the newest versus battle save
 * (SAVE_RECORD_TYPE_VERSUS) into the shared save buffer so its record can be read;
 * the entry is always reported present. */
s32 CheckVersusSaveSlot(s32 kind) {
    s32 GetSaveRecordBuffer();
    M2C_UNK LoadNewestSaveRecord(M2C_UNK, s32);
    GetSaveRecordBuffer();
    if (kind != 1) {
        return 1;
    }
    LoadNewestSaveRecord(SAVE_RECORD_TYPE_VERSUS, GetSaveRecordBuffer());
    return 1;
}

