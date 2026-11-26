/* 13 functions from 0x020BAC24 to 0x020BBBBC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct UnitBac24 { u8 kind,x,y,unk3; u16 flags; u16 health:7;u16 rest:9;u8 unk8[4];u8 cargo1,cargo2; } UnitBac24;

/* Per-frame update of the battle cursor and of the unit under it: the unit and the units it
   carries follow the cursor, a carried unit the cursor is on is unloaded, the movement path
   is refreshed and a unit that died is taken off the map. */
void BattleUpdateUnitCursor(void){
extern void **gCurrentMap;
M2C_UNK ClearCursorUnitCapture();M2C_UNK func_020bf858();s32 IsPlayerLocallyControlled(s32);void ChargeUnitMoveFuel(void *,s32);M2C_UNK DeleteAllUnitMoveObjects();void UpdateCursorUnitAiKnown(void);M2C_UNK RevealUnitsAroundCursor(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK MarkPathThreatRange(M2C_UNK,M2C_UNK,M2C_UNK);void MarkUnitMovePath(void *,void *,void *,void *);void RemoveUnit(s32);M2C_UNK RefreshMapView();s32 MovePathIsAttack(void *);void RunCursorUnitEventWithValue(void *,s32);void RunCursorUnitEvent(void *);void RefreshMapCursorCellCache(void);
BattleMapUnit *unit;u8 *map;s32 carrierId;u32 tileIndex;
ClearCursorUnitCapture();func_020bf858();
/* the unit under the cursor and the units it carries stand on the cursor's tile */
M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
if(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)){
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)*14,u8*,MAP_UNIT_RECORDS+1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)*14,u8*,MAP_UNIT_RECORDS+2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
}
if(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)){
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)*14,u8*,MAP_UNIT_RECORDS+1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)*14,u8*,MAP_UNIT_RECORDS+2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
}
/* the cursor keeps its direction only while the player may still choose one */
if(IsPlayerLocallyControlled(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER))){ChargeUnitMoveFuel(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_DIR));
M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_DIR)=0;}DeleteAllUnitMoveObjects();
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);unit->flags|=1;
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);if(unit->flags&8)unit->flags|=2;
map=*gCurrentMap;carrierId=M2C_FIELD(map,u8*,MAP_CURSOR_CARRIER);
if(carrierId){
/* the cursor is on the unit the carrier holds: unload it and step the carry chain on */
if(M2C_FIELD(map,u8*,MAP_CURSOR_UNIT_ID)==M2C_FIELD(map+carrierId*14,u8*,MAP_UNIT_RECORDS+12)){unit=(BattleMapUnit*)(map+MAP_UNIT_RECORDS)+carrierId;unit->firstCarried=unit->nextCarried;}
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_CARRIER)*14,u8*,MAP_UNIT_RECORDS+13)=0;
unit=(BattleMapUnit*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS)+M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_CARRIER);if(!unit->firstCarried)unit->flags&=~16;
}else{
unit=M2C_FIELD(map,BattleMapUnit**,MAP_CURSOR_UNIT);
if(unit->health && !(unit->flags&32)){
tileIndex=unit->x+M2C_FIELD(map+unit->y*2,u16*,MAP_ROW_OFFSETS);
if((u8)(M2C_FIELD(map+(tileIndex>>3),u8*,MAP_CELL_BITMAP)&(1<<(tileIndex&7))) && !(M2C_FIELD(map+M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)*140,u8*,0x67c3)&2))unit->flags|=128;
}}
UpdateCursorUnitAiKnown();
/* highlight the path the unit would walk to the cursor */
RevealUnitsAroundCursor(M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_X),M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_Y),(u8*)*gCurrentMap+MAP_CURSOR_PATH);
MarkPathThreatRange(M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_X),M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_Y),(u8*)*gCurrentMap+MAP_CURSOR_PATH);
MarkUnitMovePath(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),(u8*)*gCurrentMap+MAP_PATH_X,(u8*)*gCurrentMap+MAP_CURSOR_X,(u8*)*gCurrentMap+MAP_CURSOR_PATH);
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);
/* a unit without health is taken off the map */
if(!unit->health){if(unit)carrierId=unit-(BattleMapUnit*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS);else carrierId=0;RemoveUnit(carrierId);}
RefreshMapView();
if(MovePathIsAttack((u8*)*gCurrentMap+MAP_CURSOR_PATH))RunCursorUnitEventWithValue(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),11);
else RunCursorUnitEvent(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT));
RefreshMapCursorCellCache();
}

void func_020bb028(void) {
    M2C_UNK func_020bf858();
    M2C_UNK RefreshMapView();
    M2C_UNK DeleteAllUnitMoveObjects();
    func_020bf858();
    DeleteAllUnitMoveObjects();
    RefreshMapView();
}

/* Place the unit under the cursor on the cursor's tile and refresh the map's
 * path preview: clear its capture points when the cursor moved, reveal the units
 * around the cursor, mark the path's threat range and redraw the view. */
void MoveUnitToCursor(void) {
    M2C_UNK ClearCursorUnitCapture();
    M2C_UNK RevealUnitsAroundCursor(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MarkPathThreatRange(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK RefreshMapView();
    extern void **gCurrentMap;

    ClearCursorUnitCapture();
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_X) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X);
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_Y) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y);
    RevealUnitsAroundCursor(
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X),
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y),
        (M2C_UNK)((u8 *)*gCurrentMap + MAP_CURSOR_PATH));
    MarkPathThreatRange(
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X),
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y),
        (M2C_UNK)((u8 *)*gCurrentMap + MAP_CURSOR_PATH));
    RefreshMapView();
}

/* Move the cursor's unit onto the cursor tile, then show the battle preview of
 * its attack on the unit at map unit index `targetUnit`. */
void StartBattlePreviewOnTargetUnit(s32 targetUnit) {
    M2C_UNK func_0209ecf0(M2C_UNK, M2C_UNK);
    void MoveUnitToCursor(void);
    MoveUnitToCursor();
    func_0209ecf0(targetUnit, 0);
}

/* Move the cursor's unit to the cursor tile, then show the battle preview of
 * its attack on the target tile (x, y). */
void StartBattlePreviewOnTile(s32 x, s32 y) {
    M2C_UNK StartBattlePreviewOnFeature(M2C_UNK, M2C_UNK, M2C_UNK);
    void MoveUnitToCursor(void);

    MoveUnitToCursor();
    StartBattlePreviewOnFeature(x, y, 0);
}

void func_020bb110(void) {
    extern void **gCurrentMap;
    s32 GetUnitCaptureRate(void *, s16, s16);
    M2C_UNK ClearCursorUnitCapture();
    void SyncCursorOldPosition(void);
    s32 IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(s32, s32);
    s32 func_020cd5d8(void);
    void CreateBattleEffectPending(u8, u8, u8, u8, u8, u8);
    void PlayCaptureSoundForPlayer(s32);
    void CompletePropertyCapture(s16, s16);
    void ScheduleBattleEndCheck(void);
    u8 *map;
    BattleMapUnitHead *unit;
    s32 capture, unitId;
    u32 tile;
    u8 terrain;
    u16 previous;

    capture = GetUnitCaptureRate(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT),
                                 M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X),
                                 M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y));
    map = *gCurrentMap;
    tile = M2C_FIELD(map, s16 *, MAP_CURSOR_X) +
           M2C_FIELD(map + M2C_FIELD(map, s16 *, MAP_CURSOR_Y) * 2, u16 *, MAP_ROW_OFFSETS);
    terrain = M2C_FIELD(map + tile, u8 *, MAP_CELL_TERRAIN);
    unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    if (unit)
        unitId = (s32)((u8 *)unit - (map + MAP_UNIT_RECORDS)) / 14;
    else
        unitId = 0;
    ClearCursorUnitCapture();
    SyncCursorOldPosition();

    map = *gCurrentMap;
    previous = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT)->facing;
    capture += previous;
    if (capture >= 20)
        capture = 20;
    if (previous == 0 && IsPlayerHuman(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)))
        AddRecordValue(9, 1);
    if (capture == 20 && IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)))
        AddRecordValue(10, 1);

    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) || M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW) {
        u8 visible;
        u32 index;
        u16 player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
        s32 y = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
        u8 side = M2C_FIELD(map + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_SIDE);
        s32 x = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
        if (!(side & 2)) {
            index = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            visible = 1;
            if (!(u8)(M2C_FIELD(map + (index >> 3), u8 *, MAP_CELL_BITMAP) & (1 << (index & 7))))
                visible = 0;
        } else
            visible = 1;
        if (!visible)
            goto storeCapture;
    }

    if (func_020cd5d8() || (u8)(terrain & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_HQ) {
        {
            u8 *players;
            s32 owner, capturingPlayer;
            u8 previousCapture;
            map = *gCurrentMap;
            capturingPlayer = (unitId & 0xc0) >> 6;
            owner = (terrain & MAP_TERRAIN_OWNER_MASK) >> 5;
            unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
            players = map + 0x67a4;
            previousCapture = unit->facing;
            capturingPlayer++;
            CreateBattleEffectPending(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER),
                                      terrain & MAP_TERRAIN_KIND_MASK,
                                      M2C_FIELD(players + owner * 0x8c, u8 *, 0x1d),
                                      M2C_FIELD(players + capturingPlayer * 0x8c, u8 *, 0x1d),
                                      previousCapture, capture);
        }
    } else if (capture >= 20) {
        PlayCaptureSoundForPlayer(((unitId & 0xc0) >> 6) + 1);
    }

storeCapture:
    M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->facing = (u16)capture;
    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    if (unit->facing >= 20) {
        unit->facing = 0;
        if ((terrain & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_HQ) {
            s32 ownerOffset = ((terrain & MAP_TERRAIN_OWNER_MASK) >> 5) * 0x8c;
            M2C_FIELD((u8 *)*gCurrentMap + ownerOffset, u8 *, 0x67d4) = 1;
            map = *gCurrentMap;
            {
                u8 *players = map + 0x67a4;
                u16 player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
                u8 value = M2C_FIELD(players + ownerOffset, u8 *, 0x31);
                M2C_FIELD(players + player * 0x8c, u16 *, 0x22) += value;
            }
        }
        CompletePropertyCapture(M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X),
                      M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y));
    }
    ScheduleBattleEndCheck();
}

/* Load the cursor's unit into the transport visible on the cursor's tile: record
 * the human action, append the unit to the transport's carry chain, mark the
 * transport as carrying and the unit as loaded, refresh the movement-path
 * preview, and play the load sound when the unit is infantry or a mech. */
void LoadUnitIntoTransport(void) {
    s32 IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK ClearCursorUnitCapture(void);
    M2C_UNK RevealUnitsAroundCursor(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK MarkPathThreatRange(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK PlaySoundAtTile(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;

    u8 *transport;

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) != 0) {
        AddRecordValue(0x13, 1);
    }
    transport = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS +
        ((u8 *)*gCurrentMap)[
            M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X) +
            M2C_FIELD((u16 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y), u16 *, MAP_ROW_OFFSETS)
        ] * MAP_UNIT_STRIDE;
    ClearCursorUnitCapture();
    if (transport[MAP_UNIT_FIRST_CARRIED] != 0) {
        transport[MAP_UNIT_NEXT_CARRIED] = M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID);
    } else {
        transport[MAP_UNIT_FIRST_CARRIED] = M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID);
    }
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_FLAGS) =
        (u16)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_FLAGS) | UNIT_FLAG_LOADED);
    {
        u16 h = * (u16 *)(transport + MAP_UNIT_FLAGS);
        * (u16 *)(transport + MAP_UNIT_FLAGS) = (u16)(h | UNIT_FLAG_CARRYING);
    }
    RevealUnitsAroundCursor(
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X),
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y),
        (M2C_UNK)((u8 *)*gCurrentMap + MAP_CURSOR_PATH));
    MarkPathThreatRange(
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_X),
        M2C_FIELD(*gCurrentMap, s16 *, MAP_PATH_Y),
        (M2C_UNK)((u8 *)*gCurrentMap + MAP_CURSOR_PATH));
    {
        BattleMapUnitHead *selected = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
        u32 k = selected->kind;
        if (k != UNIT_KIND_INFANTRY && k != UNIT_KIND_MECH) return;
    }
    PlaySoundAtTile(
        0x7B,
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X),
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y));
}

/* Marker action for the unit it points at: refill the unit's ammo and fuel for
 * free, repair one level (ten health points) at the owning player's expense, then
 * show the refill effect popup on the marker's tile. */
void ResupplyMarkedUnit(void *marker) {
    M2C_UNK func_020c98d8(s32, s32, M2C_UNK);
    M2C_UNK RefillUnitAmmo(s32, M2C_UNK);
    M2C_UNK RefillUnitFuel(s32, M2C_UNK);
    M2C_UNK LevelUpUnit(s32, M2C_UNK, M2C_UNK);
    s32 unit;

    unit = M2C_FIELD(marker, s32 *, 0x54);
    RefillUnitAmmo(unit, 0);
    RefillUnitFuel(unit, 0);
    LevelUpUnit(unit, 1, 1);
    func_020c98d8(M2C_FIELD(marker, s32 *, 0x34), M2C_FIELD(marker, s32 *, 0x38), 1);
}

/* Drop the unit carried in `cargoSlot` (0 = first carried unit, 1 = second) from
 * the transport under the cursor: mark it unloaded and stand it on the neighbour
 * tile the cursor points at, unlink it from the transport's carry chain (promoting
 * the second carried unit when the first was dropped) and clear the transport's
 * carrying flag once no cargo is left. */
void DropCarriedUnit(s32 cargoSlot) {
    M2C_UNK IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    extern s32 gMapCursorOptionValue;
    extern s16 gMapCursorOptionStep[];

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) != 0) {
        AddRecordValue(0x14, 1);
    }
    {
        u8 *transport;
        u8 cargoId;
        u8 *cargo;
        u16 flags;
        u8 nextCargoId;
        transport = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
        cargoId = (transport + cargoSlot)[MAP_UNIT_FIRST_CARRIED];
        cargo = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + cargoId * MAP_UNIT_STRIDE;
        flags = M2C_FIELD(cargo, u16 *, MAP_UNIT_FLAGS);
        flags = (u16)(flags & ~UNIT_FLAG_LOADED);
        M2C_FIELD(cargo, u16 *, MAP_UNIT_FLAGS) = flags;
        flags = M2C_FIELD(cargo, u16 *, MAP_UNIT_FLAGS);
        flags = (u16)(flags & ~UNIT_FLAG_CARRIED);
        M2C_FIELD(cargo, u16 *, MAP_UNIT_FLAGS) = flags;
        cargo[MAP_UNIT_X] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_X) + gMapCursorOptionStep[gMapCursorOptionValue * MAP_CURSOR_OPTION_STRIDE]);
        cargo[MAP_UNIT_Y] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_Y) + gMapCursorOptionStep[gMapCursorOptionValue * MAP_CURSOR_OPTION_STRIDE + 1]);
        transport = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
            (transport + cargoSlot)[MAP_UNIT_FIRST_CARRIED] = 0;
        if (cargoSlot == 0) {
            transport = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
            nextCargoId = transport[MAP_UNIT_NEXT_CARRIED];
            if (nextCargoId != 0) {
                transport[MAP_UNIT_FIRST_CARRIED] = nextCargoId;
                transport = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
                transport[MAP_UNIT_NEXT_CARRIED] = 0;
            }
        }
    }
    {
        u8 *transport = M2C_FIELD(*gCurrentMap, u8 **, MAP_CURSOR_UNIT);
        u8 cargoId = transport[MAP_UNIT_FIRST_CARRIED];
        if (cargoId == 0) {
        u16 flags = M2C_FIELD(transport, u16 *, MAP_UNIT_FLAGS);
            flags = (u16)(flags & ~UNIT_FLAG_CARRYING);
        M2C_FIELD(transport, u16 *, MAP_UNIT_FLAGS) = flags;
        }
    }
}

extern u8 gUnitKindMaxAmmo[], gUnitKindMaxFuel[];
M2C_UNK AddRecordValue(s32, s32);
s32 GetUnitBuildCost(s32, s32);
void AddPlayerFunds(s32, s32);
s32 IsPlayerLocallyControlled(s32);
void ChargeUnitMoveFuel(void *, s32);
s32 IsUnitSelected(BattleMapUnitHead *);
void ReplacePlayerSelectedUnit(BattleMapUnitHead *, BattleMapUnitHead *);
void func_020d31e4(s32, s32);
s32 Divide(s32, s32);
void func_020bb768(void) {
    M2C_UNK IsPlayerHuman(u16);
    extern void **gCurrentMap;
    BattleMapUnitHead *unit;
    BattleMapUnitHead *other;
    u8 *map;
    s16 x, y;
    u16 row;
    register s32 hp;
    s32 otherHp;
    u8 amount, limit;
    register u8 total;
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) {
        AddRecordValue(18, 1);
    }
    map = *gCurrentMap;
    y = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
    unit = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    x = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
    row = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
    other = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS) + M2C_FIELD(map + (x + row), u8 *, MAP_CELL_UNIT_ID);
    hp = unit->health;
    hp = hp ? Divide(hp - 1, 10) + 1 : 0;
    otherHp = other->health;
    otherHp = otherHp ? Divide(otherHp - 1, 10) + 1 : 0;
    total = otherHp + hp;
    if (total > 10) {
        s32 cost = GetUnitBuildCost(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER),
            M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind);
        AddPlayerFunds(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), (total - 10) * cost);
        total = 10;
    }
    M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->health = (u16)(total * 10);
    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    unit->owner = unit->owner > other->owner ? unit->owner : other->owner;
    M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->facing = other->facing;
    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    amount = unit->ammo + other->ammo;
    limit = gUnitKindMaxAmmo[unit->kind * 0x70];
    if (amount > limit) unit->ammo = limit;
    else unit->ammo = amount;
    if (IsPlayerLocallyControlled(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) {
        ChargeUnitMoveFuel(M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT), M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_DIR));
        M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_DIR) = 0;
    }
    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    amount = unit->fuel + other->fuel;
    limit = gUnitKindMaxFuel[unit->kind * 0x70];
    if (amount > limit) unit->fuel = limit;
    else unit->fuel = amount;
    if (IsUnitSelected(other)) {
        ReplacePlayerSelectedUnit(other, M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT));
    }
    other->kind = 0;
    SyncCursorOldPosition();
    func_020d31e4(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER),
        M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind);
}

/* Supply order (battle command 13): record the human player's supply action, then
 * open the supply overlay that marks and refills the adjacent friendly units the
 * supply unit can top up. */
void SupplyCommand(void) {
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK CreateSupplyOverlay(M2C_UNK);
    s32 IsPlayerHuman(u16);
    extern void **gCurrentMap;
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) != 0) {
        AddRecordValue(0x10, 1);
    }
    CreateSupplyOverlay(0);
}

/* End the current player's turn: pick and store the weather the next turn
 * starts with, capture a fresh battle-command seed, remember where the player
 * left the cursor, and move the map state machine to its end-of-turn step. */
void EndPlayerTurn(void) {
 M2C_UNK RollNextWeather(); M2C_UNK GetRandomSeed(); M2C_UNK func_020a6fcc();
 extern void **gCurrentMap; extern u8 gBattleCommand[];
 u8 *p = (u8 *)*gCurrentMap + MAP_NAME;
 p[MAP_WEATHER_START - MAP_NAME] = RollNextWeather();
 *(u32 *)(gBattleCommand + BATTLE_COMMAND_SEED) = GetRandomSeed();
 M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_CURSOR_X)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X);
 M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_CURSOR_Y)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y);
 func_020a6fcc(); M2C_FIELD(*gCurrentMap,u16 *,MAP_STATE)=1;
}

void func_020bbba4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212afac;
    CreateSpriteFromClass(&data_0212afac, 7);
}

