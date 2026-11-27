/* 39 functions from 0x020CF69C to 0x020D068C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
extern u8 data_0212bd5c[];
extern s8 gTerrainDefenseStars[];
extern s8 gProductionSiteTerrain[];
extern s8 gProductionSiteTerrain[];
extern s32 *gCurrentMap;
extern s32 gMapData;

/* Advance the map cursor's smoothed position toward the tile it is aimed at
 * (MAP_CURSOR_TARGET_X/Y; both the target and the result are in 1/16-cell units)
 * and hand that position to the map view's cursor callback, once for each of two
 * cursor selectors: arg0, then arg1.  Both placements report the same point. */
void StepMapCursorAndNotify(s32 arg0, s32 arg1) {
    M2C_UNK StepMapCursorPosition(s16,s16,s16,s16 *,s16 *);
    extern s32 *gCurrentMap;
    s16 posX; s16 posY;
    void (*cb)(s16,s16,s32);
    void *p = (void *)*gCurrentMap;
    s16 *target = (s16 *)((u8 *)p + MAP_CURSOR_TARGET_X);
    StepMapCursorPosition((s16)(target[0]*16), (s16)(target[1]*16), (s16)arg0, &posX, &posY);
    cb = M2C_FIELD((void *)gCurrentMap[1], void (**)(s16,s16,s32), MAPVIEW_CURSOR_CB);
    if (cb != NULL) cb(posX, posY, arg0);
    cb = M2C_FIELD((void *)gCurrentMap[1], void (**)(s16,s16,s32), MAPVIEW_CURSOR_CB);
    if (cb == NULL) return;
    cb(posX, posY, arg1);
}

/* Advance the map cursor's smoothed position toward the tile it is aimed at
 * (MAP_CURSOR_TARGET_X/Y; both the target and the result are in 1/16-cell units)
 * and hand that position to the map view's cursor callback, once for each of two
 * cursor selectors: arg0, then arg1 + 8.  Both placements report the same point. */
void StepMapCursorAndNotifyOffset(s32 arg0, s32 arg1) {
    M2C_UNK StepMapCursorPosition(s16,s16,s16,s16 *,s16 *);
    extern s32 *gCurrentMap;
    s16 sp6; s16 sp4;
    void (*cb)(s16,s16,s32);
    void *p = (void *)*gCurrentMap;
    s16 *pp = (s16 *)((u8 *)p + MAP_CURSOR_TARGET_X);
    StepMapCursorPosition((s16)(pp[0]*16), (s16)(pp[1]*16), (s16)arg0, &sp6, &sp4);
    cb = M2C_FIELD((void *)gCurrentMap[1], void (**)(s16,s16,s32), MAPVIEW_CURSOR_CB);
    if (cb != NULL) cb(sp6, sp4, arg0);
    cb = M2C_FIELD((void *)gCurrentMap[1], void (**)(s16,s16,s32), MAPVIEW_CURSOR_CB);
    if (cb == NULL) return;
    cb(sp6, sp4, arg1 + 8);
}

/* Per-frame map cursor input: while the cursor is idle, move its target tile by
 * the held D-pad direction and then by the stylus position. */
void UpdateMapCursorInput(void) {
    M2C_UNK MoveMapCursorWithKeys();
    M2C_UNK UpdateMapCursorFromTouch();
    s32 IsMapCursorIdle();
    if (IsMapCursorIdle() == 0) {
        return;
    }
    MoveMapCursorWithKeys();
    UpdateMapCursorFromTouch();
}

/* One input step of the battle map cursor: move the cursor's target tile by the
 * held D-pad direction and onto the touch position, playing `sound` each time
 * the target moves.  Does nothing while the cursor is not idle. */
void StepMapCursorTargetFromInput(s32 sound) {
    M2C_UNK func_020bc610(M2C_UNK);
    M2C_UNK func_020bd220(M2C_UNK);
    if (IsMapCursorIdle() == 0) {
        return;
    }
    func_020bc610(sound);
    func_020bd220(sound);
}

/* Per-frame map cursor movement for the map modes that drive it by hand: step the
   aimed tile along the held D-pad direction (auto-repeat) and update it from the
   stylus, playing moveSound for each move. */
void UpdateMapCursorByDirectionAndTouch(s32 moveSound) {
    M2C_UNK MoveMapCursorByDirection(M2C_UNK);
    M2C_UNK func_020bd3c0(M2C_UNK);
    if (IsMapCursorIdle() == 0) {
        return;
    }
    MoveMapCursorByDirection(moveSound);
    func_020bd3c0(moveSound);
}

/* Whether (x, y) is a production property the current player owns: the cell must
 * carry one of the player's production terrains (base, port or airport), have no
 * unit standing on it, and the map data's rule flag 2 must be clear. */
u8 IsOwnedProductionSite(s32 x, s32 y) {
 s32 func_020a88fc(u16); s32 IsProductionSiteOwnedByPlayer(u8, s32);
 extern s32 *gCurrentMap;
 u8 result; void *map; s32 index; u8 terrain;
 map=(void *)*gCurrentMap;
 index=x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS);
 terrain=M2C_FIELD(map+index,u8 *,MAP_CELL_TERRAIN);
 if(M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)==0) return 0;
 index=((u8 *)map)[index];
 if(index!=0) return 0;
 if(IsProductionSiteOwnedByPlayer(terrain, M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER))==0) return 0;
 if(func_020a88fc(M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_ID))==0) result=1; else result=0;
 return result;
}

/* Check whether the terrain tile at (arg0, arg1) can be entered by unit kind arg3:
 * the tile's movement class must be arg2, and the kind must either be an air kind
 * (15) or be able to enter the tile's own terrain class (17) or, for kinds with
 * the tracked/booted flags, a road/bridge class (18, 19). */
u8 func_020cf908(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
void GetTerrainOwner(void);
u8 IsTerrainKind(s32,s32);
extern u8 gUnitKindFlags[];
void *p=(void *)*gCurrentMap;
s32 index=arg0+M2C_FIELD(p+arg1*2,u16*,0x3758);
u8 value=M2C_FIELD(p+index,u8*,0x1420);
s32 offset;
if(arg2!=((s32 (*)(s32))GetTerrainOwner)(value))return 0;
if(IsTerrainKind(value,15))return 1;
offset=arg3*0x70;
if(gUnitKindFlags[offset]&7) {if(IsTerrainKind(value,17))return 1;}
if(gUnitKindFlags[offset]&16) {if(IsTerrainKind(value,18))return 1;}
if(gUnitKindFlags[offset]&32) {if(IsTerrainKind(value,19))return 1;}
return 0;
}

/* Whether the map cell at (x, y) is plain ground or shoal. */
u8 IsPlainOrShoalTerrain(s32 x, s32 y) {
    u8 IsTerrainKind(s32, s32);
    extern s32 *gCurrentMap;
    void *map = (void *)*gCurrentMap;
    s32 cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
    u8 terrain = M2C_FIELD(map + cell, u8 *, MAP_CELL_TERRAIN);
    u8 result;
    if (IsTerrainKind(terrain, MAP_TERRAIN_PLAIN) != 0) return 1;
    if (IsTerrainKind(terrain, MAP_TERRAIN_SHOAL) != 0) result = 1; else result = 0;
    return result;
}

/* Load the decoded tile-graphics block for id into gMapData.  Ids in
   0xE1..0x1A8 come from a fixed 0x6F8-byte tile-set record (byte 4 = width,
   byte 5 = height, then the per-tile ids at +0x54 mapped through TerrainByteToTileId);
   any other id is expanded from a resource by the generic loader. */
void LoadMapTileData(u32 id) {
s32 HeapAllocBlock(s32); void *HeapAllocBlockTail(s32); s32 LoadMapRecord(u32,void *); s32 TerrainByteToTileId(s32); M2C_UNK HeapFreeBlock(s32); void *func_020a8b1c(u32); void SetFileDirectory(void *); void LoadDecompressedFileTo(void *,s32);
s32 i; u8 *tileSet; u8 *tileIds; void *resource;
gMapData=HeapAllocBlock(0xA12);
if(id>=0xE1 && id<0x1A9){
tileSet=HeapAllocBlockTail(0x6F8);
if(LoadMapRecord(id,tileSet)){
M2C_FIELD(gMapData,u8 *,0)=tileSet[4];
M2C_FIELD(gMapData,u8 *,1)=tileSet[5];
tileIds=tileSet+0x54;
for(i=0;i<(s16)tileSet[4]*(s16)tileSet[5];i++){
resource=(void *)gMapData;
((u16 *)resource)[i+1]=TerrainByteToTileId(tileIds[i]);
}
}
HeapFreeBlock((s32)tileSet);return;
}
resource=func_020a8b1c(id);if(!resource)return;
SetFileDirectory(data_0212bd5c);LoadDecompressedFileTo(resource,gMapData);
}

/* Free the decoded tile-graphics block that LoadMapTileData allocated into gMapData
 * and clear the pointer. */
void FreeMapTileData(void) {
    M2C_UNK HeapFreeBlock(s32);
    extern s32 gMapData;
    HeapFreeBlock(gMapData);
    gMapData = 0;
}

/* The current map's display name (MAP_NAME), the text used on the battle map
 * and in its save record. */
char *GetCurrentMapName(void) {
    extern s32 *gCurrentMap;

    return (char *)(*gCurrentMap + MAP_NAME);
}

/* The number of players the current map is set up for (MAP_PLAYER_COUNT). */
u8 GetCurrentMapPlayerCount(void) {
    extern s32 *gCurrentMap;
    return M2C_FIELD((void *)*gCurrentMap, u8 *, MAP_PLAYER_COUNT);
}

/* The number of armies the map `mapId` is played with: campaign maps take it
 * from their campaign record, every other map from its map-data record. */
s32 GetMapPlayerCount(u32 mapId) {
    u8 MapData_GetPlayerCount(s32);
    s32 GetCampaignMapPlayerCount(s32);

    if ((mapId >= MAP_ID_CAMPAIGN_FIRST) && (mapId < MAP_ID_CAMPAIGN_END)) {
        return GetCampaignMapPlayerCount(mapId);
    }
    return MapData_GetPlayerCount(mapId);
}

/* The localized display name of the map with the given id: campaign maps
 * ([MAP_ID_CAMPAIGN_FIRST, MAP_ID_CAMPAIGN_END)) take it from their own record,
 * every other map from the name text id in its map-data record. */
void GetMapName(u32 mapId) {
    M2C_UNK GetLocalizedText();
    M2C_UNK MapData_GetNameTextId();
    M2C_UNK GetCampaignMapName();
    if ((mapId >= MAP_ID_CAMPAIGN_FIRST) && (mapId < MAP_ID_CAMPAIGN_END)) {
        GetCampaignMapName();
        return;
    }
    MapData_GetNameTextId();
    GetLocalizedText();
}

/* The 1-based army that owns the property with the given terrain byte, or 0 when
 * the terrain is not an owned property (property terrain carries its owner in the
 * top three bits, see PLAYER_REC_PROPERTY_ARMY). */
u8 Map_GetPropertyOwnerArmy(s32 terrain) {
 extern s32 *gCurrentMap;
 extern s8 gTerrainPropertyFlags[];
 s32 owner=terrain & 0xE0;
 if(owner==0) return 0;
 if(gTerrainPropertyFlags[terrain & 0x1F]==0) return 0;
 return M2C_FIELD((void *)*gCurrentMap+(owner>>5)*MAP_PLAYER_STRIDE,u8 *,0x67C1);
}

/* Keep the map cursor's target tile inside the map: clamp x to 0..width-1 and y
 * to 0..height-1. */
void ClampCursorToMap(void) {
 extern s32 *gCurrentMap;
 if(M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)<0)
 M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=0;
 if(M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)>=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_WIDTH))
 M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_WIDTH)-1;
 if(M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)<0)
 M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=0;
 if(M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)>=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_HEIGHT))
 M2C_FIELD((void *)*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_HEIGHT)-1;
}

void func_020cfd14(void) {
    M2C_UNK RebuildMapPropertyCells();
    M2C_UNK UpdateAiCapabilityFlags();
    M2C_UNK func_020d2470();
    RebuildMapPropertyCells();
    func_020d2470();
    UpdateAiCapabilityFlags();
}

void RefreshMapView(void) {
    M2C_UNK func_020cfd38();
    M2C_UNK RefreshMapUnitDisplay();
    RefreshMapUnitDisplay();
    func_020cfd38();
}

/* Sets up the screen render target and dispatches the map/render callbacks. */
M2C_UNK func_020cfd38(void) {
    void (*callback)(void);
    void func_0207a668(void);
    void func_02076980(s32, s32, s32, s32);
    void func_0207843c(s32, s32, s32, s32);
    extern M2C_UNK *gCurrentMap;

    callback = NULL;
    M2C_FIELD((void *)*gCurrentMap, s16 *, 0x5150) = (s16)(M2C_FIELD((void *)*gCurrentMap, s16 *, 0x5148) / 16);
    M2C_FIELD((void *)*gCurrentMap, s16 *, 0x5152) = (s16)(M2C_FIELD((void *)*gCurrentMap, s16 *, 0x514A) / 16);
    M2C_FIELD((void *)*gCurrentMap, s16 *, 0x514C) = M2C_FIELD((void *)*gCurrentMap, s16 *, 0x5148);
    M2C_FIELD((void *)*gCurrentMap, s16 *, 0x514E) = M2C_FIELD((void *)*gCurrentMap, s16 *, 0x514A);
    callback = M2C_FIELD((void *)gCurrentMap[1], void (**)(void), 0x1C);
    if (callback != NULL) {
        callback();
    }
    callback = M2C_FIELD((void *)gCurrentMap[1], void (**)(void), 0);
    if (callback != NULL) {
        callback();
    }
    callback = M2C_FIELD((void *)gCurrentMap[1], void (**)(void), 4);
    if (callback != NULL) {
        callback();
    }
    func_0207a668();
    func_02076980(0, 0, 48, 40);
    func_0207843c(0, 0, 48, 40);
}

/* Rebuild the map's per-cell unit layers from the unit records: first clear the
 * visible-unit byte (offset 0) and the unit id byte (MAP_CELL_UNIT_ID) of every
 * cell, then write each placed unit's index into both.  A human player only sees
 * a unit written to the visible layer when its cell is in the first team's sight
 * bitmap, and the last pass removes from that layer the hidden units that are
 * not in sight (a CPU player sees everything).  Units that are moving
 * (flag 0x02) are not shown until they stop. */
void RefreshMapCellUnits(void) {
    s32 IsMapUnitRevealed(s32);
    s32 x, y;
    u8 *map;
    u8 *cell;
    u8 occupant;
    u32 cellIndex;
    u8 sightBits;

    s32 noUnit = 0;

    for (y = 0; y < M2C_FIELD((void *)*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD((void *)*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            map = (u8 *)*gCurrentMap;
            (map + x)[((Map16E8 *)map)->rows[y]] = noUnit;
            map = (u8 *)*gCurrentMap;
            (map + x)[((Map16E8 *)map)->rows[y] + MAP_CELL_UNIT_ID] = noUnit;
        }
    }
    {
        s32 i;
        BattleMapUnitHead *unit;
        s32 unitOffset;
        BattleMapUnitHead *units;
        for (i = 1, unitOffset = MAP_UNIT_STRIDE; i < MAP_UNIT_COUNT; i++, unitOffset += MAP_UNIT_STRIDE) {
            map = (u8 *)*gCurrentMap;
            units = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS);
            unit = (BattleMapUnitHead *)((u8 *)units + unitOffset);
            if (!unit->kind) continue;
            if ((unit->flags & 2) && !(unit->flags & 4)) continue;
            cell = map + unit->x + M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS);
            occupant = cell[MAP_CELL_UNIT_ID];
            if (occupant && !(M2C_FIELD(map + occupant * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & 4)) continue;
            cell[MAP_CELL_UNIT_ID] = (u8)(unit ? unit - units : noUnit);
            if (unit->flags & 2) continue;
            map = (u8 *)*gCurrentMap;
            if (map[PLAYER_CONTROL_OFF + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE] != PLAYER_CONTROL_CPU) {
                cellIndex = unit->x + M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS);
                sightBits = map[MAP_CELL_BITMAP_TEAM_A + (cellIndex >> 3)];
                if (!(u8)((1 << (cellIndex & 7)) & sightBits)) continue;
            }
            occupant = (u8)(unit ? unit - (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS) : noUnit);
            (map + unit->x)[M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS)] = occupant;
        }
    }
    {
        s32 i;
        BattleMapUnitHead *unit;
        BattleMapUnitHead *units;
        s32 unitOffset;
        for (i = 1, unitOffset = MAP_UNIT_STRIDE; i < MAP_UNIT_COUNT; i++, unitOffset += MAP_UNIT_STRIDE) {
            map = (u8 *)*gCurrentMap;
            units = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS);
            unit = (BattleMapUnitHead *)((u8 *)units + unitOffset);
            if (!unit->kind) continue;
            if (unit->flags & 2) continue;
            if (unit->flags & UNIT_FLAG_VISIBLE) continue;
            if (map[PLAYER_CONTROL_OFF + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE] == PLAYER_CONTROL_CPU) continue;
            if (IsMapUnitRevealed((u16)(unit ? unit - units : noUnit))) {
                map = (u8 *)*gCurrentMap;
                cellIndex = unit->x + M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS);
                sightBits = map[MAP_CELL_BITMAP_TEAM_A + (cellIndex >> 3)];
                if ((u8)((1 << (cellIndex & 7)) & sightBits)) continue;
            }
            map = (u8 *)*gCurrentMap;
            (map + unit->x)[M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS)] = noUnit;
        }
    }
}

void func_020d0164(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, s32);
    MI_CpuFill8(arg0, arg1, 0x508);
}

/* For each active player, flood-fill and mark the tiles reachable by its current unit's movement range. */
M2C_UNK RefreshMovementRanges(void) {
void InitAreaScan(void *,s32,s32,s32,s32,s32); void SetPlayerMoveRangeCell(s32,s32,s32,s32); s32 GetPlayerMoveRangeGrid(s32);
s32 IsPlayerActive(s32); void *GetPlayerSelectedUnit(s32); s32 IsUnitCarried(void); s32 GetPlayerCoZoneMoveRange(s32); s32 GetPlayerArmyVariantIfSet(s32); s32 NextAreaTile(void *); void BuildMoveRangeFlags(void);
s32 player; s32 pathState[8]; void *unit; s32 moveRange;
for(player=1;player<5;player++){
if(!IsPlayerActive(player))continue;
func_020d0164(GetPlayerMoveRangeGrid(player),0);
unit=GetPlayerSelectedUnit(player); if(!unit)continue;
if(IsUnitCarried() && !(M2C_FIELD(unit,u16 *,4)&4))continue;
moveRange=GetPlayerCoZoneMoveRange(player); if(GetPlayerArmyVariantIfSet(player))moveRange=6;
InitAreaScan(pathState,moveRange,M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2),M2C_FIELD((void *)*gCurrentMap,u16 *,0x5144),M2C_FIELD((void *)*gCurrentMap,u16 *,0x5146));
for(;;){if(!NextAreaTile(pathState))break;SetPlayerMoveRangeCell(player,pathState[4],pathState[5],1);}
}
BuildMoveRangeFlags();
}

/* Rebuild the battle map's unit display after the units or their owners changed:
 * recompute the team sight bitmaps, the per-cell unit layers and each player's
 * movement ranges, then refresh the info window's cell. */
M2C_UNK RefreshMapUnitDisplay(void) {
 M2C_UNK RefreshTeamVisibility(); M2C_UNK RefreshMovementRanges(); M2C_UNK Ov000_InfoWindow_RequestCellRefresh();
 RefreshTeamVisibility(); RefreshMapCellUnits(); RefreshMovementRanges(); Ov000_InfoWindow_RequestCellRefresh();
}

/* Initialise an area scan: the map size, the scan's origin and mode, and reset
 * its index to the first tile. */
void InitAreaScan(void *scanState, s32 mode, s32 originX, s32 originY, s32 width, s32 height) {
    AreaScan *scan = (AreaScan *)scanState;

    scan->width = width;
    scan->height = height;
    scan->originX = originX;
    scan->originY = originY;
    scan->mode = mode;
    scan->index = 0;
}

/* Advance to the next in-bounds area offset, or the next tile of a full-map scan. */
s32 NextAreaTile(void *state) {
    s32 Modulo(s32, s32); s32 Divide(s32, s32);
    s16 *offsets;
    if (((AreaScan *)state)->mode >= AREA_SCAN_FULL_MAP) {
        if (((AreaScan *)state)->index >= ((AreaScan *)state)->width * ((AreaScan *)state)->height) return 0;
        ((AreaScan *)state)->x = Modulo(((AreaScan *)state)->index, ((AreaScan *)state)->width);
        ((AreaScan *)state)->y = Divide(((AreaScan *)state)->index, ((AreaScan *)state)->width);
        ((AreaScan *)state)->index++; return 1;
    }
    offsets = gAreaScanOffsetTables[((AreaScan *)state)->mode]; if (!offsets) return 0;
    while (offsets[((AreaScan *)state)->index * 2] != AREA_SCAN_END) {
        ((AreaScan *)state)->x = ((AreaScan *)state)->originX + offsets[((AreaScan *)state)->index * 2];
        ((AreaScan *)state)->y = ((AreaScan *)state)->originY + offsets[((AreaScan *)state)->index * 2 + 1];
        ((AreaScan *)state)->index++;
        if (((AreaScan *)state)->x >= 0 && ((AreaScan *)state)->y >= 0 && ((AreaScan *)state)->x < M2C_FIELD((void *)*gCurrentMap, u16 *, MAP_WIDTH) && ((AreaScan *)state)->y < M2C_FIELD((void *)*gCurrentMap, u16 *, MAP_HEIGHT)) return 1;
    }
    return 0;
}

/* Return the base of player `player`'s move-range grid: the MAP_PLAYER_MOVE_RANGE
 * byte layer of gCurrentMap, one MAP_PLAYER_MOVE_RANGE_STRIDE-byte grid per player. */
s32 GetPlayerMoveRangeGrid(s32 player) {
    extern s32 *gCurrentMap;
    s32 temp = *gCurrentMap;
    temp = temp + MAP_PLAYER_MOVE_RANGE;
    return player * MAP_PLAYER_MOVE_RANGE_STRIDE + temp;
}

/* Return the move-range flag for map cell (x, y) in player `player`'s grid, which
 * marks the cells that player's selected unit can reach. */
s32 IsCellInPlayerMoveRange(s32 player, s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    return M2C_FIELD((map + player * MAP_PLAYER_MOVE_RANGE_STRIDE) + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_PLAYER_MOVE_RANGE);
}

/* Mark the cell (x, y) in `player`'s movement-range grid with `value`, used by the reachability flood fill. */
void SetPlayerMoveRangeCell(s32 player, s32 x, s32 y, s32 value) {
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    s32 rowOffset = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
    s32 range = map + player * MAP_PLAYER_MOVE_RANGE_STRIDE;
    M2C_FIELD(range + (x + rowOffset), u8 *, MAP_PLAYER_MOVE_RANGE) = value;
}

/* The CO (commanding officer) whose zone bonus applies at map cell (x, y) for
 * player: that player's bonus index when the cell is inside the player's
 * movement range, or -1 when no unit of theirs can reach it. */
s32 GetMoveRangeCommanderId(s32 player, s32 x, s32 y) {
    if (IsCellInPlayerMoveRange(player, x, y) == 0) {
        return -1;
    }
    return GetPlayerCoZoneBonusIndex(player);
}

/* Whether `terrain` is a production property (base, airport or port) whose owner
 * field names `player`: the tile's owner (GetTerrainOwner) must equal `player`
 * and its kind must be flagged in gProductionSiteTerrain. */
s32 IsProductionSiteOwnedByPlayer(u8 terrain, s32 player) {
    void GetTerrainOwner(void);
    extern s8 gProductionSiteTerrain[];
    u8 kind = terrain & MAP_TERRAIN_KIND_MASK;
    s32 expectedOwner = player;

    if (expectedOwner != ((s32 (*)(void))GetTerrainOwner)()) return 0;
    if (kind != MAP_TERRAIN_CITY) {
        if (gProductionSiteTerrain[kind & MAP_TERRAIN_KIND_MASK]) return 1;
    }
    return 0;
}

/* Whether a map cell's terrain byte is of the given kind: compares its low five
 * bits (MAP_TERRAIN_KIND_MASK), ignoring the property owner bits. */
u8 IsTerrainKind(s32 terrain, s32 kind) {
    u8 result;

    if ((terrain & MAP_TERRAIN_KIND_MASK) == kind) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether the terrain of the map cell at (x, y) is of kind `terrainKind`. */
u8 IsTerrainKindAtTile(s32 x, s32 y, s32 terrainKind) {
 void *map=(void *)*gCurrentMap;
 return IsTerrainKind(M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN),terrainKind);
}

s32 func_020d0528(s32 arg0) {
    return arg0 >> 5;
}

s32 func_020d0530(s32 arg0) {
    return arg0 & 0xE0;
}

void GetTerrainOwner(void) {
    M2C_UNK func_020d0528();
    M2C_UNK func_020d0530();
    func_020d0530();
    func_020d0528();
}

/* Whether (x, y) lie inside the screen rectangle 0..256 across by 0..192 down.
 * The tile-to-screen projection of (x, y) is computed first, but its result is not
 * what the bounds are checked against. */
s32 IsWithinScreenBounds(s32 x, s32 y) {
 void MapTileToScreen(s32,s32,void *);
 s32 screenPos[3];
 MapTileToScreen(x, y, screenPos);
 if (x < 0 || y < 0 || x > 256 || y > 192) return 0;
 return 1;
}

/* Whether the local console places this player's map cursor: always for a human
 * player, never for anyone else in a link battle (their own console draws it),
 * and otherwise when the player's side carries SIDE_TEAM_B. */
u8 IsPlayerCursorOwner(s32 player) {
  s32 IsPlayerHuman(s32);
  u8 result;
  if(IsPlayerHuman(player)!=0) return 1;
  if(M2C_FIELD(&gMapData,u8 *,MAPDATA_LINK_BATTLE)!=0) return 0;
  if(M2C_FIELD((void *)*gCurrentMap+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_SIDE_OFF)&SIDE_TEAM_B) result=1; else result=0;
  return result;
}

/* Terrain defense a unit gains from standing on `terrain`: the terrain's defense
 * stars times ten plus the owning player's per-turn defense bonus, floored at zero.
 * Kinds that take no terrain defense (UnitKindTakesNoTerrainDefense) score zero. */
s32 GetTerrainDefenseScore(s32 player, s32 kind, s32 terrain) {
    s32 UnitKindTakesNoTerrainDefense(s32);
    s32 score;
    if (UnitKindTakesNoTerrainDefense(kind)) return 0;
    score = (s16)gTerrainDefenseStars[terrain] * (s16)10 + M2C_FIELD((void *)*gCurrentMap + player * MAP_PLAYER_STRIDE, s8 *, PLAYER_DEFENSE_BONUS_OFF);
    if (score < 0) score = 0;
    return score;
}

/* Terrain defense a unit gains from standing on `terrain`, from the terrain's
 * defense stars alone (no player bonus; GetTerrainDefenseScore adds that):
 * stars times ten, floored at zero.  Kinds that take no terrain defense
 * (UnitKindTakesNoTerrainDefense) score zero.  `player` is unused. */
s32 GetTerrainDefenseFromStars(s32 player, s32 unitKind, s32 terrain) {
    s32 UnitKindTakesNoTerrainDefense(s32);
    s32 score;

    if (UnitKindTakesNoTerrainDefense(unitKind) != 0) return 0;
    score = gTerrainDefenseStars[terrain] * 10;
    if (score < 0) score = 0;
    return score;
}

