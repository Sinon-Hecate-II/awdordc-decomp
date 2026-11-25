/* 24 functions from 0x0221B56C to 0x0221C534 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

typedef struct { u8 pad[11]; u8 low : 4; u8 high : 4; } Unk_0221BC18;

s32 Map_GetCellTerrainKind();
s32 Map_GetCellTerrainOwner(s32,s32);
void Map_RefreshCellTile(s32,s32);
/* Map editor: tries to paint the selected tile `newTile`/`newDir` at cell
 * (x, y).  It only succeeds when Map_CanPlaceTile allows it, the tile kind is
 * placeable and the flood fill of the connected same-terrain region works; on
 * success every cell is refreshed and 1 is returned. */
s32 Map_TryPaintTile(s32 x,s32 y,s32 newTile,s32 newDir) {
extern s32 *gCurrentMap;
s32 Map_CanPlaceTile(s32,s32,s32,s32);
s32 IsDestroyedPipeTile(s32);
s32 func_ov007_0221b2cc(s32,s32,s32,s32,s32,s32);
s32 oldTile=Map_GetCellTerrainKind(x,y),oldDir=Map_GetCellTerrainOwner(x,y);
s32 r=Map_CanPlaceTile(x,y,newTile,newDir); s32 cellX,cellY;
if(r!=1)return r;
if(IsDestroyedPipeTile(newTile))return 0;
if(func_ov007_0221b2cc(x,y,newTile,newDir,oldTile,oldDir)){
for(cellY=0;cellY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);cellY++)
for(cellX=0;cellX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);cellX++)Map_RefreshCellTile(cellX,cellY);
return 1;
}
return 0;
}

/* Map editor: repair one cell.  When its terrain kind is no longer placeable
 * (e.g. rubble whose neighbours changed) the cell becomes wasteland ground. */
void Map_RefreshCellTile(s32 x, s32 y) {
    M2C_UNK Map_SetTileAndRefresh(s32, s32, u16, u16);
    s32 Map_IsTerrainKindPlaceable(s32, s32, s32);

    if (Map_IsTerrainKindPlaceable(x, y, Map_GetCellTerrainKind()) != 0) {
        return;
    }
    Map_SetTileAndRefresh(x, y, MAP_TERRAIN_WASTELAND, MAP_TILE_WASTELAND);
}

/* The terrain kind of map cell (x, y): a bridge drawn over wasteland (kind 0xE)
 * is reported as the ordinary bridge (0xD), the kind the editor's brush paints. */
s32 Map_GetCellTerrainKind(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map;
    s32 terrainKind;

    map = *gCurrentMap;
    terrainKind = M2C_FIELD((map + (x + M2C_FIELD((map + (y * 2)), u16 *, MAP_ROW_OFFSETS))), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
    if (terrainKind == MAP_TERRAIN_BRIDGE_WASTELAND) {
        terrainKind = MAP_TERRAIN_BRIDGE;
    }
    return terrainKind;
}

/* Return the owning player for a property at (x, y), or zero for non-property terrain. */
s32 Map_GetCellTerrainOwner(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    extern s8 gTerrainPropertyFlags[];
    s32 mapData = *gCurrentMap;
    s32 terrainValue = M2C_FIELD(mapData + (x + M2C_FIELD(mapData + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN);

    if (gTerrainPropertyFlags[terrainValue & MAP_TERRAIN_KIND_MASK]) {
        return (terrainValue & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT;
    }
    return 0;
}

/* Whether the map generator treats cell (x, y) as wasteland: the barren ground
 * a destroyed property leaves behind.  Tiles of every terrain tileset that show
 * such ground count as wasteland, and so does every cell off the map, so the
 * generator never grows terrain into the border. */
s32 Map_IsWastelandTile(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map;
    u16 tile;
    if (x < 0 || y < 0) {
        goto off_map;
    }
    map = *gCurrentMap;
    if (x < M2C_FIELD(map, u16 *, MAP_WIDTH) && y < M2C_FIELD(map, u16 *, MAP_HEIGHT)) {
        goto on_map;
    }
off_map:
    return 1;
on_map:
    tile = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)) * 2, u16 *, MAP_CELL_TILE_ID);
    switch (tile) {
        case 0x3:   /* wasteland and rubble tiles of the tilesets */
        case 0x7:
        case 0x22:
        case 0x24:
        case 0x27:
        case 0x146:
        case 0x166:
        case 0x168:
        /* unowned, neutral and owned-destroyed property ruins */
        case 0x199: case 0x19A: case 0x19B: case 0x19C: case 0x19D:
        case 0x1C4:
        case 0x1C9:
        case 0x1CE:
        case 0x1D3:
        case 0x1D8:
            return 1;
        default:
            return 0;
    }
}

/* Returns 1 if the map cell (x, y) holds a property tile -- a capturable
 * building (terrain kinds 0x0f..0x17, of any owner) -- and 0 otherwise. */
s32 Map_IsPropertyTile(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 tile;
    register s32 map;
    if (x < 0 || y < 0) {
        goto bounds_fail;
    }
    map = *gCurrentMap;
    if (x < M2C_FIELD(map, u16 *, MAP_WIDTH) && y < M2C_FIELD(map, u16 *, MAP_HEIGHT)) {
        goto in_bounds;
    }
bounds_fail:
    return 0;
in_bounds:
    tile = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)) * 2, u16 *, MAP_CELL_TILE_ID);
    switch (tile) {
        /* property of kind 0x14, owners 0..4 */
        case 0x179: case 0x17A: case 0x17B: case 0x17C: case 0x17D:
        /* property of kind 0x15, owners 0..4 */
        case 0x199: case 0x19A: case 0x19B: case 0x19C: case 0x19D:
        /* property of kind 0x16, owners 0..4 */
        case 0x1B9: case 0x1BA: case 0x1BB: case 0x1BC: case 0x1BD:
        /* the remaining property kinds (0x0f..0x13) for owners 1..4, plus
         * the neutral kinds 0x10..0x13; 0x1C0 (kind 0x0f, owner 0) is unused */
        case 0x1C1: case 0x1C2: case 0x1C3: case 0x1C4:
        case 0x1C5: case 0x1C6: case 0x1C7: case 0x1C8: case 0x1C9:
        case 0x1CA: case 0x1CB: case 0x1CC: case 0x1CD: case 0x1CE:
        case 0x1CF: case 0x1D0: case 0x1D1: case 0x1D2: case 0x1D3:
        case 0x1D4: case 0x1D5: case 0x1D6: case 0x1D7: case 0x1D8:
        case 0x1D9: case 0x1DA: case 0x1DB: case 0x1DC: case 0x1DD:
            return 1;
        default:
            goto fail;
    }
fail:
    return 0;
}

/* Map editor: whether the tile at (x, y) is one of the river/bridge tiles
 * (0x23, 0x25) that the bridge brush (terrain kinds 13/14) may be painted over. */
s32 Map_IsBridgeableTile(s32 x,s32 y) {
 extern s32 *gCurrentMap; s32 map; u16 tile;
 if(x<0||y<0)goto fail;
 map=*gCurrentMap;
 if(x>=M2C_FIELD(map,u16 *,MAP_WIDTH)||y>=M2C_FIELD(map,u16 *,MAP_HEIGHT))goto fail;
 goto valid;
 fail:return 0;
 valid:
 tile=M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS))*2,u16 *,MAP_CELL_TILE_ID);
 switch(tile) { case 0x23: case 0x25: return 1; default: return 0; }
}

/* Check whether the map editor's current unit brush may be placed on cell (x, y):
 * the terrain must let a unit of `unitKind` stand there and the player must still
 * have a free unit slot.  Returns 0 when the placement is refused, 2 when the very
 * same unit (owner, kind and AI state) already stands on the cell, else 1. */
s32 MapEditor_CanPlaceUnit(s32 x, s32 y, s32 unitKind, s32 player, s32 unitState) {
u8 Map_CanUnitKindStandOnCell(s32,s32,s32);s32 GetCachedPlayerUnitCount(s32);extern s32 *gCurrentMap;
s32 map,id;u8 *unit;
if(!Map_CanUnitKindStandOnCell(x,y,unitKind))return 0;
map=*gCurrentMap;id=M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_VISIBLE_UNIT);
if(id){unit=(u8 *)(map+MAP_UNIT_RECORDS)+id*MAP_UNIT_STRIDE;
if(((id&MAP_UNIT_OWNER_MASK)>>MAP_UNIT_OWNER_SHIFT)+1==player){
if(unitKind==((u32)(unit[MAP_UNIT_KIND]<<26)>>26)&&((u32)(unit[MAP_UNIT_AI_STATE]<<28)>>28)==(unsigned)unitState)return 2;
}else{if(GetCachedPlayerUnitCount(player)>=MAP_UNIT_LIMIT)return 0;}
}else{if(GetCachedPlayerUnitCount(player)>=MAP_UNIT_LIMIT)return 0;}
return 1;
}

/* Map editor unit brush: place a unit of `unitKind` owned by `player` with AI
 * state `unitState` on cell (x, y).  MapEditor_CanPlaceUnit's verdict is passed
 * through (0 refused, 2 the same unit already stands there); otherwise the unit
 * on the cell is destroyed and the new record created, its AI state stamped in.
 * Returns 0 when no free unit record was left. */
s32 MapEditor_PlaceUnit(s32 x,s32 y,s32 unitKind,s32 player,s32 unitState) {
 extern s32 *gCurrentMap;
 s32 MapEditor_CanPlaceUnit(s32,s32,s32,s32,s32);
 M2C_UNK DestroyUnit(s32);
 void *CreateMapUnit(s16,s16,s16,s32);
 s32 map,r; u8 id; BattleMapUnitHead *unit;
 r=MapEditor_CanPlaceUnit(x,y,unitKind,player,unitState);
 if(r!=1)return r;
 map=*gCurrentMap;
 id=M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_VISIBLE_UNIT);
 if(id)DestroyUnit(id);
 unit=CreateMapUnit((s16)x,(s16)y,(s16)unitKind,player);
 if(!unit)return 0;
 unit->aiState=(u8)unitState;
 return 1;
}

/* Map editor: destroy the unit standing on cell (x, y) if one is visible there.
 * Returns 1 when a unit was destroyed, 0 when the cell was empty. */
s32 MapEditor_DestroyUnitAt(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    M2C_UNK DestroyUnit(s32);
    s32 map = *gCurrentMap;
    u8 unitId = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_VISIBLE_UNIT);
    if (!unitId) return 0;
    DestroyUnit(unitId);
    return 1;
}

/* True when a unit of `unitKind` may stand on the cell at (x, y): the terrain
 * cost the kind's movement type gives that cell's terrain kind is not -1. */
u8 Map_CanUnitKindStandOnCell(s32 x, s32 y, s32 unitKind) {
    extern s32 *gCurrentMap;
    extern u8 gMovementCostTable[];
    extern u8 gMovementTypeTable[];
    s32 map = *gCurrentMap;

    return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, ARMY_DATA_MOVE_COSTS) +
                     gMovementTypeTable[unitKind * UNIT_KIND_STATS_SIZE] * 32, s8 *,
                     M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) != -1;
}

/* Map editor: the kind of unit standing on cell (x, y), or -1 when no unit is
 * visible there.  The kind is the low six bits of the unit record's kind byte. */
s32 MapEditor_GetUnitKindAt(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    u8 id = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_VISIBLE_UNIT);
    if (!id) return -1;
    return (u32) (M2C_FIELD(map + id * MAP_UNIT_STRIDE, u8 *, MAP_UNIT_RECORDS + MAP_UNIT_KIND) << 26) >> 26;
}

#pragma push
#pragma optimizewithasm off
#pragma peephole off
/* Map editor: return the owner player (1-based) of the unit standing on cell
 * (x, y), or -1 when that cell holds no visible unit. */
s32 MapEditor_GetUnitOwnerAt(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    s32 unitId = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_VISIBLE_UNIT);

    if (!unitId) return -1;
    return ((unitId & MAP_UNIT_OWNER_MASK) >> MAP_UNIT_OWNER_SHIFT) + 1;
}
#pragma pop
/* Map editor: the AI state (the low nibble of MAP_UNIT_AI_STATE) of the unit on
 * cell (x, y), or -1 when the cell holds no unit. */
s32 MapEditor_GetUnitStateAt(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 map = *gCurrentMap;
    u8 unitId = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_VISIBLE_UNIT);
    if (!unitId) return -1;
    return (u32)(M2C_FIELD(map + unitId * MAP_UNIT_STRIDE, u8 *, MAP_UNIT_RECORDS + MAP_UNIT_AI_STATE) << 28) >> 28;
}

/* Copies the 64 unit records of a stashed unit group back into the map's group
 * `group` (1..4), field by field apart from the record's +0x03 byte. */
void CopyUnitGroup(u8 *source, s32 group) {
    extern s32 *gCurrentMap;
    u8 *dest = (u8 *)(*gCurrentMap + MAP_UNIT_RECORDS + ((group - 1) << 6) * MAP_UNIT_STRIDE);
    s32 i = 0;

    do {
        u8 *s = source;
        u8 *t = dest;
        u32 first, next;

        *dest = *source;
        source += MAP_UNIT_STRIDE;
        dest += MAP_UNIT_STRIDE;
        i++;
        t[MAP_UNIT_X] = s[MAP_UNIT_X];
        t[MAP_UNIT_Y] = s[MAP_UNIT_Y];
        M2C_FIELD(t, u16 *, MAP_UNIT_FLAGS) = M2C_FIELD(s, u16 *, MAP_UNIT_FLAGS);
        M2C_FIELD(t, u16 *, MAP_UNIT_HEALTH) = M2C_FIELD(s, u16 *, MAP_UNIT_HEALTH);
        M2C_FIELD(t, u16 *, MAP_UNIT_TARGET) = M2C_FIELD(s, u16 *, MAP_UNIT_TARGET);
        t[MAP_UNIT_FUEL] = s[MAP_UNIT_FUEL];
        t[MAP_UNIT_AI_STATE] = s[MAP_UNIT_AI_STATE];
        first = ((volatile u8 *)s)[MAP_UNIT_FIRST_CARRIED];
        next = ((volatile u8 *)s)[MAP_UNIT_NEXT_CARRIED];
        t[MAP_UNIT_FIRST_CARRIED] = first;
        t[MAP_UNIT_NEXT_CARRIED] = next;
    } while (i < 64);
}

/* Rearrange the map's four groups of 64 unit records: the group each parameter
 * names is copied into the player slot its position denotes (group1 -> slot 1,
 * group2 -> slot 2, ...). All records are stashed in a heap buffer first so a
 * group can be moved onto one still needed; a group already in place stays. */
void RemapUnitGroups(s32 group1,s32 group2,s32 group3,s32 group4){
extern s32 *gCurrentMap;
void *HeapAllocBlock(u32); void HeapFreeBlock(void *);
u8 *backup; s32 i,off; u8 *t;
if(group1==1&&group2==2&&group3==3&&group4==4)return;
backup=HeapAllocBlock(MAP_UNIT_COUNT*MAP_UNIT_STRIDE);i=0;off=0;t=backup;
do{u8 *s=(u8 *)(*gCurrentMap+MAP_UNIT_RECORDS);u8 *p=s+off;u32 x,y;
i++;
t[0]=s[off];t[1]=p[1];t[2]=p[2];
M2C_FIELD(t,u16 *,4)=M2C_FIELD(p,u16 *,4);
M2C_FIELD(t,u16 *,6)=M2C_FIELD(p,u16 *,6);
M2C_FIELD(t,u16 *,8)=M2C_FIELD(p,u16 *,8);
t[10]=p[10];t[11]=p[11];x=((volatile u8 *)p)[12];y=((volatile u8 *)p)[13];t[12]=x;t[13]=y;t+=MAP_UNIT_STRIDE;off+=MAP_UNIT_STRIDE;
}while(i<MAP_UNIT_COUNT);
if(group1!=1)CopyUnitGroup(backup+((group1-1)<<6)*MAP_UNIT_STRIDE,1);
if(group2!=2)CopyUnitGroup(backup+((group2-1)<<6)*MAP_UNIT_STRIDE,2);
if(group3!=3)CopyUnitGroup(backup+((group3-1)<<6)*MAP_UNIT_STRIDE,3);
if(group4!=4)CopyUnitGroup(backup+((group4-1)<<6)*MAP_UNIT_STRIDE,4);
HeapFreeBlock(backup);
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
/* Reassign every property cell to the player slot (slot1..slot4) that owns it,
 * then refresh the cell's tile graphic from the new terrain byte. */
void Map_ReassignPropertyOwners(s32 slot1,s32 slot2,s32 slot3,s32 slot4){
extern s32 *gCurrentMap;extern s8 gTerrainPropertyFlags[];
s32 TerrainByteToTileId(s32);
s32 y,x,map,cell,terrain,kind;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);x++){
map=*gCurrentMap;
cell=(map+x)+M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS);
terrain=M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN);kind=terrain&MAP_TERRAIN_KIND_MASK;
if(gTerrainPropertyFlags[kind]){
if(slot1==((terrain&MAP_TERRAIN_OWNER_MASK)>>5))M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN)=kind|0x20;
if(slot2==((terrain&MAP_TERRAIN_OWNER_MASK)>>5)){map=*gCurrentMap;M2C_FIELD(M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS)+(map+x),u8 *,MAP_CELL_TERRAIN)=kind|64;}
if(slot3==((terrain&MAP_TERRAIN_OWNER_MASK)>>5)){map=*gCurrentMap;M2C_FIELD(M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS)+(map+x),u8 *,MAP_CELL_TERRAIN)=kind|96;}
if(slot4==((terrain&MAP_TERRAIN_OWNER_MASK)>>5)){map=*gCurrentMap;M2C_FIELD(M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS)+(map+x),u8 *,MAP_CELL_TERRAIN)=kind|128;}
map=*gCurrentMap;
M2C_FIELD(map+(x+M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS))*2,u16 *,MAP_CELL_TILE_ID)=TerrainByteToTileId(M2C_FIELD(M2C_FIELD(map+(y<<1),u16 *,MAP_ROW_OFFSETS)+(map+x),u8 *,MAP_CELL_TERRAIN));
}}}}
/* Renumber the player ids so the players taking part (team != 0) sit in the
 * lowest slots with no gaps: reset each slot to its own id, then swap every
 * active slot's id into the next free slot. */
void CompactPlayerSlots(void) {
    s32 GetPlayerTeam(s32);
    s32 swapped;
    s32 slot;
    s32 nextSlot;
    s32 sourceSlot;

    nextSlot = 1;
    slot = 0;
    do {
        SetPlayerIdForSlot(slot, slot);
        slot += 1;
    } while (slot < 5);
    sourceSlot = 1;
    do {
        if (GetPlayerTeam(sourceSlot) != 0) {
            swapped = GetPlayerIdForSlot(nextSlot);
            SetPlayerIdForSlot(nextSlot, GetPlayerIdForSlot(sourceSlot));
            SetPlayerIdForSlot(sourceSlot, swapped);
            nextSlot = (s32) (u8) (nextSlot + 1);
        }
        sourceSlot += 1;
    } while (sourceSlot < 5);
}

/* Reset the player order to the identity: every slot keeps its own player id, and
 * the players' battle state is then rebuilt from the map. */
void ResetPlayerOrder(void) {
    M2C_UNK SetPlayerIdForSlot(s32, s32);
    M2C_UNK InitMapPlayers();
    M2C_UNK InitPlayerStates();
    s32 slot;

    slot = 0;
    do {
        SetPlayerIdForSlot(slot, slot);
        slot += 1;
    } while (slot < MAX_PLAYERS);
    InitPlayerStates();
    InitMapPlayers();
}

/* Return the player slot whose player id is `playerId`, or slot 0 when no slot
 * holds that id. */
s32 GetSlotForPlayerId(s32 playerId) {
    s32 GetPlayerIdForSlot(s32);
    s32 slot;

    slot = 0;
loop_1:
    if (playerId == GetPlayerIdForSlot(slot)) {
        return slot;
    }
    slot += 1;
    if (slot >= 5) {
        return 0;
    }
    goto loop_1;
}

/* Initialises the map-start panel for the map about to be played: shows the
 * status message for a replay of the last campaign map (0x4600000C), for a map
 * with two or more players (0x46000008) or for a single-player map (0x46000009),
 * then records the current map id in the panel and clears its campaign flag. */
void MapStart_InitState(void *state) {
 extern s32 *gCurrentMap;
 s32 IsLastCampaignMap(s32); s32 MapEditor_PlayerHasTeam(s32); void SetUiMessageText(u32);
 if(IsLastCampaignMap(M2C_FIELD(*gCurrentMap,u16 *,MAP_ID)))SetUiMessageText(0x4600000C);
 else if(MapEditor_PlayerHasTeam(-1))SetUiMessageText(0x46000008);
 else SetUiMessageText(0x46000009);
 M2C_FIELD(state,s32 *,0x5C)=M2C_FIELD(*gCurrentMap,u16 *,MAP_ID);
 M2C_FIELD(state,u16 *,0x6C)=0;
}

/* Prepare the next map once any menu/transition object is gone: compact the
 * player slots, remap the unit groups and property owners to the new player
 * order, select the map record (the next campaign map, or the current map),
 * remap back, then reset the player order and release the map object when the
 * campaign map list is exhausted. */
void StartNextMap(void *p) {
    extern s32 *gCurrentMap;
    s32 IsSaveInProgress(void);
    s32 GetPlayerIdForSlot(s32);
    s32 GetSlotForPlayerId(s32);
    void Map_ReassignPropertyOwners(s32,s32,s32,s32);
    void StoreCurrentMapAsCampaignMap(s32);
    void ResetPlayerOrder(void);
    void AssignPlayerTeams(void);
    void MapEditor_SetMapModified(s32);
    void Sprite_ResumeAnimation(void *);
    s32 id1,id2,id3,id4;
    if(IsSaveInProgress())return;
    CompactPlayerSlots();
    id1=GetPlayerIdForSlot(1);id2=GetPlayerIdForSlot(2);id3=GetPlayerIdForSlot(3);id4=GetPlayerIdForSlot(4);
    RemapUnitGroups(id1,id2,id3,id4);
    id1=GetPlayerIdForSlot(1);id2=GetPlayerIdForSlot(2);id3=GetPlayerIdForSlot(3);id4=GetPlayerIdForSlot(4);
    Map_ReassignPropertyOwners(id1,id2,id3,id4);
    if(M2C_FIELD(p,s16 *,0x6c)){s32 mapIndex=M2C_FIELD(p,s32 *,0x5c);M2C_FIELD(p,s32 *,0x5c)=mapIndex+1;StoreCurrentMapAsCampaignMap(mapIndex+0xe1);}else StoreCurrentMapAsCampaignMap(M2C_FIELD(*gCurrentMap,u16 *,MAP_ID));
    id1=GetSlotForPlayerId(1);id2=GetSlotForPlayerId(2);id3=GetSlotForPlayerId(3);id4=GetSlotForPlayerId(4);
    RemapUnitGroups(id1,id2,id3,id4);
    id1=GetSlotForPlayerId(1);id2=GetSlotForPlayerId(2);id3=GetSlotForPlayerId(3);id4=GetSlotForPlayerId(4);
    Map_ReassignPropertyOwners(id1,id2,id3,id4);
    ResetPlayerOrder();AssignPlayerTeams();MapEditor_SetMapModified(0);
    if(M2C_FIELD(p,s16 *,0x6c)){if(M2C_FIELD(p,s32 *,0x5c)<50)return;Sprite_ResumeAnimation(p);return;}Sprite_ResumeAnimation(p);
}

/* Show the "no save data" message when the current campaign map has no save of
 * its save type, otherwise clear the message. */
void UpdateCampaignSaveMessage(void) {
    extern s32 *gCurrentMap;
    s32 GetCampaignMapSaveType(s32); s32 SaveRecordExistsForType(s32); void SetUiMessageText(u32);
    if (SaveRecordExistsForType(GetCampaignMapSaveType(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID))) == 0) {
        SetUiMessageText(TEXT_ID_NO_SAVE_DATA);
        return;
    }
    SetUiMessageText(0);
}

#pragma push
#pragma optimization_level 3
void func_ov007_0221c51c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_022201d8;
    CreateSpriteFromClass(&data_ov007_022201d8, 7);
}
