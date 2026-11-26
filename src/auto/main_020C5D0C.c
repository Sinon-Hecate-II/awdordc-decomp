/* 54 functions from 0x020C5D0C to 0x020C6CF8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1[5];
    u16 unk6 : 7;
    u16 unk6_7 : 4;
    u16 unk6_11 : 5;
    u8 unk8[3];
    u8 unkB : 4;
    u8 unkB_4 : 4;
    u8 unkC[2];
} UnkStruct_020C5D0C;

/* Availability of a campaign-only battle command (one the other battle modes do
 * not offer): 0 while the battle is still running and the map's rules select the
 * campaign mode (mode 0), 2 once it has ended or in any other mode. */
s32 CanUseCampaignOnlyCommand(void) {
    s32 IsCampaignBattleRules(void);
    extern u8 gBattleEndState;

    if (gBattleEndState == 0 && IsCampaignBattleRules() != 0) {
        return 0;
    }
    return 2;
}

/* Availability of a battle-menu entry that only free-play battles offer: 0
 * (available) while a free-play battle is still running, 2 (hidden) once it has
 * ended or in any other battle mode. */
s32 CanUseFreePlayBattleCommand(void) {
    s32 IsFreePlayBattleMode();
    extern u8 gBattleEndState;
    if ((gBattleEndState == 0) && (IsFreePlayBattleMode() != 0)) {
        return 0;
    }
    return 2;
}

/* Continue-command availability: hidden (2) once the battle has ended, disabled
 * (1) when the current save kind has no battle record to resume, and available
 * (0) when it does. */
u8 CanContinueBattle(void) {
    s32 IsUnitAvailable(s32);
    M2C_UNK GetCurrentSaveType(void);
    extern u8 gBattleEndState;
    u8 available;

    if (gBattleEndState != 0) {
        return 2;
    }
    if (IsUnitAvailable(GetCurrentSaveType()) == 0) {
        available = 1;
    } else {
        available = 0;
    }
    return available;
}

void func_020c5da4(void) {
    M2C_UNK RunMapMenuEvent();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    RunMapMenuEvent();
}

void func_020c5db4(void) {
    M2C_UNK func_ov000_02171214();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_ov000_02171214();
}

void func_020c5dc4(void) {
    M2C_UNK CreateMenuList(M2C_UNK);
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    ResumeMapInputMode();
    CreateMenuList(0);
}

/* Map-menu command: close the menu's sprites and switch the battle map to the
 * unit-selection cursor, which lets the player pick one of their units. */
void MapMenu_SelectUnit(void) {
    extern void **gCurrentMap;
    DeleteMapMenuSprites();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_MODE) = MAP_MODE_UNIT_SELECT;
}

/* Availability of the map-menu command that runs the map's MAP_EVENT_MAP_MENU
 * script: available (0) in a campaign battle whose event conditions are met,
 * hidden (2) otherwise. */
s32 CanUseMapMenuEventCommand(void) {
    s32 IsCampaignBattleRules();
    s32 IsMapEventConditionMet();
    if ((IsCampaignBattleRules() != 0) && (IsMapEventConditionMet() != 0)) {
        return 0;
    }
    return 2;
}

/* Map-menu availability of the map's win-rule entry: available (0) when the
 * current map defines a win-rule text, hidden (2) when it does not. */
s32 CanShowMapWinRule(void) {
    s32 MapData_GetWinRuleTextId(u16);
    extern void **gCurrentMap;

    if (MapData_GetWinRuleTextId(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) {
        return 0;
    }
    return 2;
}

/* Whether any player taking part in the battle has an army (nation) assigned:
 * returns 0 when one does, 2 when none does, the map's rule bit 1 blocks it or
 * the battle has already ended. */
s32 AnyPlayerHasArmy(void) {
    struct bits8 {
        u32 value : 8;
    };
    s32 func_020a88e8(u16);
    s32 IsPlayerPresent(s32);
    extern u8 gBattleEndState;
    extern void **gCurrentMap;
    s32 player;
    s32 playerOffset;
    u32 armyId;

    if (func_020a88e8(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) {
        return 2;
    }
    if (gBattleEndState != 0) {
        return 2;
    }
    player = 1;
    playerOffset = MAP_PLAYER_STRIDE;
    do {
        if (IsPlayerPresent(player) != 0) {
            armyId = ((struct bits8 *) ((s8 *) *gCurrentMap + playerOffset + (MAP_PLAYER_STATES + PLAYER_REC_SPRITE)))->value;
            if (armyId != 0) {
                return 0;
            }
        }
        player += 1;
        playerOffset += MAP_PLAYER_STRIDE;
    } while (player < 5);
    return 2;
}

/* Whether the current player's own unit group is empty: 1 when every record of
 * the group (ids gPlayerUnitIdBase[player]+1 .. +0x32) is unoccupied, 0 when at
 * least one unit is left.  Unlike IsCurrentPlayerOutOfUnits this ignores the
 * map-data rule that can suppress the rout test. */
s32 CurrentPlayerHasNoUnits(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];

    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + MAP_UNIT_RECORDS))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c5f94(void) {
    s32 func_020c5cd4();
    s32 CurrentPlayerHasNoUnits();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return CurrentPlayerHasNoUnits();
}

/* Whether the current player has no units left: 1 when none of the player's
 * unit-group records is occupied, 0 when at least one is. Returns 2 up front
 * when the map data's +4 flag bit 3 is set. */
s32 IsCurrentPlayerOutOfUnits(void) {
    s32 func_020a8910(u16);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    void *base;
    u16 start;

    if (func_020a8910(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];
    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        UnkStruct_020C5D0C *entry = &((UnkStruct_020C5D0C *)((u8 *)base + MAP_UNIT_RECORDS))[i];
        if (entry->unk0 != 0) { count += 1; }
    }
    if (count == 0) { return 1; }
    return 0;
}

s32 func_020c606c(void) {
    s32 IsCurrentPlayerOutOfUnits();
    if (func_020c5cd4() == 2) {
        return 2;
    }
    return IsCurrentPlayerOutOfUnits();
}

/* Map action menu predicate: 0 when the tile under the cursor holds no visible
 * unit, 2 when it holds one. */
s32 IsCursorCellEmpty(void) {
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    s16 cursorY = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
    s16 cursorX = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
    u16 rowOffset = M2C_FIELD((u8 *)map + cursorY * 2, u16 *, MAP_ROW_OFFSETS);
    if (M2C_FIELD(map, u8 *, MAP_CELL_VISIBLE_UNIT + cursorX + rowOffset) == 0) { return 0; }
    return 2;
}

/* Whether the unit under the cursor can join (merge with) the unit on the cell it
 * points at: 0 when it can, 2 when the cell is empty or the two cannot join. */
s32 CanJoinUnitAtCursor(void) {
    s32 CanUnitsJoin(s32, s32);
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    s16 cursorY = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
    s16 cursorX = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
    u16 rowOffset = M2C_FIELD((u8 *)map + cursorY * 2, u16 *, MAP_ROW_OFFSETS);
    u8 unitId = M2C_FIELD(map, u8 *, cursorX + rowOffset);

    if (unitId == 0) {
        return 2;
    }
    if (CanUnitsJoin(M2C_FIELD(map, s32 *, MAP_CURSOR_UNIT), (s8 *)map + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE) == 0) {
        return 2;
    }
    return 0;
}

/* Whether a unit load is being aimed at the cursor, in the 0 = yes, 2 = no
 * convention the command checks use: the cursor's unit can be loaded into the
 * transport on the tile the cursor points at. */
s32 CanLoadUnitAtCursor(void) {
    s32 CanLoadUnitAt(s16, s16);
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    s16 x = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
    s16 y = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);

    if (CanLoadUnitAt(x, y) == 1) {
        return 0;
    }
    return 2;
}

/* Whether a transport's first carried unit may be dropped right now: returns 2
 * when a direction is held for it, when the cursor unit has nothing to drop, or
 * when it is the two-slot Carrier; 0 while the drop direction is still missing. */
s32 CanConfirmFirstCargoDrop(void) {
 s32 GetHeldDirection(s32);
 s32 IsCarrierUnitKind(s32);
 s32 CanDropFirstCarriedUnit(void *, s32, s32);
 extern void **gCurrentMap;
 void *base;
 if (GetHeldDirection(0) != 0) return 2;
 if (CanLoadUnitAtCursor() == 0) return 2;
 if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) != 0) return 2;
 base = *gCurrentMap;
 if (CanDropFirstCarriedUnit(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y)) != 0) return 0;
 return 2;
}

/* Whether a transport's second carried unit may be dropped right now: returns 2
 * when a direction is held for it, when the cursor unit has nothing to drop, or
 * when it is the two-slot Carrier; 0 while the drop direction is still missing. */
s32 CanConfirmSecondCargoDrop(void) {
 s32 GetHeldDirection(s32);
 s32 IsCarrierUnitKind(s32);
 s32 CanDropSecondCarriedUnit(void *, s32, s32);
 extern void **gCurrentMap;
 void *base;
 if (GetHeldDirection(1) != 0) return 2;
 if (CanLoadUnitAtCursor() == 0) return 2;
 if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) != 0) return 2;
 base = *gCurrentMap;
 if (CanDropSecondCarriedUnit(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y)) != 0) return 0;
 return 2;
}

/* Whether the carrier under the cursor may drop the unit in its first cargo
   slot: the unit must be a carrier that has not moved this turn, the slot must
   hold a unit that has not acted yet, and the cursor must still be on the
   carrier.  Returns 0 when the action is available, 2 when it is not. */
s32 CanDropFirstCargo(void) {
    s32 IsCarrierUnitKind(s32);
    extern void **gCurrentMap;
    void *base;
    u32 cargoId;

    if (CanLoadUnitAtCursor() == 0) return 2;
    if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) == 0) return 2;
    base = *gCurrentMap;
    cargoId = M2C_FIELD(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_FIRST_CARRIED);
    if (cargoId == 0) return 2;
    if (M2C_FIELD((u8 *)base + cargoId * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & UNIT_FLAG_ACTED) return 2;
    if (M2C_FIELD(base, s16 *, MAP_CURSOR_X) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_X) || M2C_FIELD(base, s16 *, MAP_CURSOR_Y) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_Y)) return 2;
    return 0;
}

/* Whether the carrier under the cursor may drop the unit in its second cargo
   slot: the unit must be a carrier that has not moved this turn, the slot must
   hold a unit that has not acted yet, and the cursor must still be on the
   carrier.  Returns 0 when the action is available, 2 when it is not. */
s32 CanDropSecondCargo(void) {
    s32 IsCarrierUnitKind(s32);
    extern void **gCurrentMap;
    void *base;
    u32 cargoId;

    if (CanLoadUnitAtCursor() == 0) return 2;
    if (IsCarrierUnitKind(((BattleMapUnitHead *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT))->kind) == 0) return 2;
    base = *gCurrentMap;
    cargoId = M2C_FIELD(M2C_FIELD(base, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED);
    if (cargoId == 0) return 2;
    if (M2C_FIELD((u8 *)base + cargoId * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & UNIT_FLAG_ACTED) return 2;
    if (M2C_FIELD(base, s16 *, MAP_CURSOR_X) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_X) || M2C_FIELD(base, s16 *, MAP_CURSOR_Y) != M2C_FIELD(base, s16 *, MAP_CURSOR_OLD_Y)) return 2;
    return 0;
}

/* Whether the unit under the cursor may deploy a unit: the unit must be a carrier
   that has not moved and has no second carried unit, must have ammo if its kind
   uses any, and its player must be able to afford the deployed unit's cost and
   have a free unit record.  Returns 0 when the action is available, 2 when not. */
s32 CanCarrierDeployUnit(void){
extern void **gCurrentMap;
extern u8 gUnitKindMaxAmmo[];
void *map; UnkStruct_020C5D0C *unit; u16 player;
if(IsUnitKindCarrier(((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))->unk0)==0)return 2;
map=*gCurrentMap;
unit=M2C_FIELD(map,UnkStruct_020C5D0C **,MAP_CURSOR_UNIT);
if(M2C_FIELD(unit,u8 *,13))return 2;
if(M2C_FIELD(map,s16 *,MAP_CURSOR_X)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_X)||M2C_FIELD(map,s16 *,MAP_CURSOR_Y)!=M2C_FIELD(map,s16 *,MAP_CURSOR_OLD_Y))return 2;
if(gUnitKindMaxAmmo[unit->unk0*0x70] && unit->unk6_7==0)return 2;
player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
if(GetUnitBuildCostTimes10(player,17)>M2C_FIELD(map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF))return 2;
if(FindFreeUnitRecord(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER))==0)return 2;
return 0;
}

/* Whether the unit under the cursor can resupply: the map must not be in the mode
 * that blocks the action, joining and loading must be unavailable, the cursor unit
 * must be a supply kind, and at least one adjacent friendly unit must need
 * resupply.  Returns 0 when the action is available, 2 when it is not. */
s32 CanSupplyAtCursor(void) {
 extern void **gCurrentMap;
 s32 IsSupplyUnitKind(void *); s32 FillMapLayer(s32); s32 ClearAdjacentMoveDirs(s32,s32); s32 CollectSupplyTargets(s32);
 void *base;
 if(M2C_FIELD(*gCurrentMap,u16 *,MAP_MODE)==7)return 2;
 if(CanJoinUnitAtCursor()==0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 if(IsSupplyUnitKind(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))==0)return 2;
 FillMapLayer(-1);
 base=*gCurrentMap;
 if(CollectSupplyTargets(ClearAdjacentMoveDirs(M2C_FIELD(base,s16 *,MAP_CURSOR_X),M2C_FIELD(base,s16 *,MAP_CURSOR_Y)))!=0)return 0;
 return 2;
}

/* Availability of the Dive command for the submarine under the cursor: the unit
 * must be surfaced (UNIT_FLAG_SUBMERGED clear) and have no join or load pending.
 * Returns 0 when the command is available, 2 when it is not. */
s32 CanSubmergeUnitAtCursor(void) {
 extern void **gCurrentMap;
 if(M2C_FIELD(M2C_FIELD(*gCurrentMap,BattleMapUnitHead **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_SUBMERGED)return 2;
 if(CanJoinUnitAtCursor()==0)return 2;
 if(CanLoadUnitAtCursor()==0)return 2;
 return 0;
}

/* Battle-command availability for Capture: 0 when the unit under the cursor can
 * capture a property, 2 when it cannot.  Joining or loading another unit blocks
 * the command; otherwise the move-range grid is cleared and the unit's own cell
 * made passable, then the reachable enemy and neutral properties are counted. */
s32 CanCapturePropertyAtCursor(void) {
    s32 CanJoinUnitAtCursor();
    s32 CanLoadUnitAtCursor();
    M2C_UNK FillMapLayer(s32);
    s32 CollectCapturableProperties();
    extern void **gCurrentMap;
    void *base;
    s16 cursorY;
    s16 cursorX;

    if (CanJoinUnitAtCursor() == 0) {
        return 2;
    }
    if (CanLoadUnitAtCursor() == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    cursorY = M2C_FIELD(base, s16 *, MAP_CURSOR_Y);
    cursorX = M2C_FIELD(base, s16 *, MAP_CURSOR_X);
    M2C_FIELD(M2C_FIELD((s8 *)base + cursorY * 4, u8 **, MAP_GRID), u8 *, cursorX) = 0;
    if (CollectCapturableProperties() != 0) {
        return 0;
    }
    return 2;
}

/* Availability of the Missile command: 0 when the unit under the cursor can
 * reach a loaded missile silo this turn, 2 when it cannot.  Joining or loading
 * another unit blocks the command; otherwise the move-range grid is cleared and
 * the unit's own cell made passable, then the reachable silos are counted. */
s32 CanLaunchMissileAtCursor(void) {
    s32 CanJoinUnitAtCursor();
    s32 CanLoadUnitAtCursor();
    M2C_UNK FillMapLayer(s32);
    s32 CollectReachableMissileSilos();
    extern void **gCurrentMap;
    void *base;
    s16 cursorY;
    s16 cursorX;

    if (CanJoinUnitAtCursor() == 0) {
        return 2;
    }
    if (CanLoadUnitAtCursor() == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    cursorY = M2C_FIELD(base, s16 *, MAP_CURSOR_Y);
    cursorX = M2C_FIELD(base, s16 *, MAP_CURSOR_X);
    M2C_FIELD(M2C_FIELD((s8 *)base + cursorY * 4, u8 **, MAP_GRID), u8 *, cursorX) = 0;
    if (CollectReachableMissileSilos() != 0) {
        return 0;
    }
    return 2;
}

/* Returns 0 on success, 2 if the attempted move/attack is blocked. */
s32 func_020c6214(void) {
    extern void **gCurrentMap;
    extern u8 gUnitMaxAttackRange[], gUnitMinAttackRange[];
    s32 GetHeldDirection(s32);
    s32 IsMobileIndirectUnitKind(s32);
    s32 func_0209f990(void);
    s32 FillMapLayer(s32);
    void MarkUnitAttackRingCells(s32, s32, void *);
    void *base;
    s32 x, y;

    if (GetHeldDirection(0) != 0 || GetHeldDirection(1) != 0) {
        return 2;
    }
    base = *gCurrentMap;
    y = M2C_FIELD(base, s16 *, 0x52DE);
    x = M2C_FIELD(base, s16 *, 0x52DC);
    if (M2C_FIELD(base, u8 *, x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)) != 0) {
        return 2;
    }
    if (x != M2C_FIELD(base, s16 *, 0x52D8) || y != M2C_FIELD(base, s16 *, 0x52DA)) {
        s32 id = ((UnkStruct_020C5D0C *)M2C_FIELD(base, void **, 0x52D0))->unk0;
        if (gUnitMaxAttackRange[id * 0x70] != 1 && IsMobileIndirectUnitKind(id) == 0) {
            return 2;
        }
    }
    if (gUnitMinAttackRange[((UnkStruct_020C5D0C *)M2C_FIELD(*gCurrentMap, void **, 0x52D0))->unk0 * 0x70] == 0) {
        return 2;
    }
    FillMapLayer(-1);
    base = *gCurrentMap;
    MarkUnitAttackRingCells(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), M2C_FIELD(base, void **, 0x52D0));
    if (func_0209f990() != 0) {
        return 0;
    }
    return 2;
}

/* Availability of the Dive command: offered only while the unit under the
 * cursor is a submarine (kind UNIT_KIND_SUBMARINE); CanSubmergeUnitAtCursor
 * checks the rest. Returns 0 when the command is available, 2 when it is not. */
s32 CanSubmergeCommand(void) {
    s32 CanSubmergeUnitAtCursor();
    extern void **gCurrentMap;

    switch (M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind) {
    case UNIT_KIND_SUBMARINE:
        return CanSubmergeUnitAtCursor();
    }
    return 2;
}

/* Availability of the Surface command for the submarine under the cursor: the
 * unit must have no join or load pending and be submerged (UNIT_FLAG_SUBMERGED
 * set).  Returns 0 when the command is available, 2 when it is not. */
s32 CanSurfaceUnitAtCursor(void) {
 s32 CanLoadUnitAtCursor(); extern void **gCurrentMap;
 if (!CanJoinUnitAtCursor()) return 2;
 if (!CanLoadUnitAtCursor()) return 2;
 if (M2C_FIELD(M2C_FIELD(*gCurrentMap,BattleMapUnitHead **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_SUBMERGED) return 0;
 return 2;
}

/* Availability of the Surface command: offered only while the unit under the
 * cursor is a submarine (kind 0x16); CanSurfaceUnitAtCursor checks the rest.
 * Returns 0 when the command is available, 2 when it is not. */
s32 CanSurfaceCommand(void) {
    s32 CanSurfaceUnitAtCursor();
    extern void **gCurrentMap;

    switch (M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind) {
    case UNIT_KIND_SUBMARINE:
        return CanSurfaceUnitAtCursor();
    }
    return 2;
}

/* Availability check for the Flare command: the map must be in fog or snow, the
 * cursor unit must be an unmoved kind-5 Flare, and it must have ammo left.
 * Returns 0 when the command is available, 2 when it is not. */
s32 CanFireFlare(void) {
 extern void **gCurrentMap;
 void *base=*gCurrentMap;
 BattleMapUnitHead *unit;
 if (M2C_FIELD(base,u8 *,MAP_FOG)==0 && M2C_FIELD(base,u8 *,MAP_WEATHER)!=WEATHER_SNOW) return 2;
 unit=M2C_FIELD(base,BattleMapUnitHead **,MAP_CURSOR_UNIT);
 if(unit->kind!=UNIT_KIND_FLARE) return 2;
 if(M2C_FIELD(base,s16 *,MAP_CURSOR_X)!=M2C_FIELD(base,s16 *,MAP_CURSOR_OLD_X) || M2C_FIELD(base,s16 *,MAP_CURSOR_Y)!=M2C_FIELD(base,s16 *,MAP_CURSOR_OLD_Y)) return 2;
 if (unit->ammo) return 0;
 return 2;
}

void func_020c6968(void) {
    M2C_UNK PushCarriedUnitMenuState();
    M2C_UNK OpenCarriedUnitMenu();
    M2C_UNK DeleteMapMenuSprites();
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    OpenCarriedUnitMenu();
}

/* Map-menu command "Army Info": save the carried-unit list menu, close the map
 * menu, return the map to its input mode and run the army-info script in layer 7,
 * whose callbacks open the army info window and release the map-view hold again. */
void OpenArmyInfoCommand(void) {
    extern M2C_UNK gArmyInfoOpenScript;

    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    ResumeMapInputMode();
    CreateSpriteFromClass(&gArmyInfoOpenScript, 7);
}

void func_020c69a0(void) {
    M2C_UNK ResumeMapInputMode();
    M2C_UNK func_ov000_02171028();
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    ResumeMapInputMode();
    func_ov000_02171028();
}

void func_020c69b8(void) {
    M2C_UNK func_ov000_0217242c();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_ov000_0217242c();
}

void func_020c69c8(void) {
    M2C_UNK func_ov000_02171750();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_ov000_02171750();
}

void func_020c69d8(void) {
    M2C_UNK func_020cbfe4();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_020cbfe4();
}

void func_020c69e8(void) {
    M2C_UNK func_020cc08c();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_020cc08c();
}

void func_020c69f8(void) {
    M2C_UNK func_ov000_021707c0();
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    ResumeMapInputMode();
    func_ov000_021707c0();
}

/* End Turn menu command: close the map menu and end the current player's turn;
 * once the battle has finished, tell the other players the turn is over. */
void ConfirmEndTurnCommand(void) {
    M2C_UNK SendTurnEndPacket();
    M2C_UNK EndPlayerTurn();
    extern u8 gBattleEndState;
    DeleteMapMenuSprites();
    EndPlayerTurn();
    if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED) == 0) {
        return;
    }
    SendTurnEndPacket();
}

void func_020c6a38(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a714;
    DeleteMapMenuSprites();
    CreateSpriteFromClass(&data_0212a714, 7);
}

void func_020c6a54(void) {
    M2C_UNK func_020b4cf4();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_020b4cf4();
}

void func_020c6a64(void) {
    M2C_UNK func_020b4d24();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_020b4d24();
}

/* Confirm the pending directional action: drop the cursor UI, and when no cursor
 * direction is held send battle command 2; otherwise send command 8 with each
 * held direction resolved against the cursor tile. */
void ConfirmHeldDirectionCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK DeleteDirectionMarkerSprites();
    s32 GetHeldDirection(s32);
    s32 ResolveHeldDirection(s32, s32, s32);
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;
    void *base;
    s32 dir0, dir1;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    if (!GetHeldDirection(0) && !GetHeldDirection(1)) {
        SetBattleCommand(2, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
        return;
    }
    DeleteDirectionMarkerSprites();
    base = *gCurrentMap;
    dir0 = ResolveHeldDirection(M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y), 0);
    dir1 = ResolveHeldDirection(M2C_FIELD(base, s16 *, MAP_CURSOR_X), M2C_FIELD(base, s16 *, MAP_CURSOR_Y), 1);
    SetBattleCommand(8, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), (u8)dir0, (u8)dir1);
}

/* Start building the unit the cursor's factory produces: close the map menu and
 * send battle command AI_COMMAND_PRODUCE_UNIT for the unit under the cursor. */
void ConfirmProduceUnitCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    SetBattleCommand(AI_COMMAND_PRODUCE_UNIT, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
}

void func_020c6b68(void) {
    M2C_UNK func_020bbba4();
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
    func_020bbba4();
}

/* Capture the property the unit under the cursor stands on: refresh the battle
 * menu state, drop the menu sprites and post battle command AI_COMMAND_CAPTURE
 * for that unit, with no extra arguments. */
void ConfirmCaptureCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    SetBattleCommand(AI_COMMAND_CAPTURE, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
}

/* Map action menu, command 9: refresh the battle menu state, close the menu and
 * post battle command 9 for the unit under the cursor; the command carries no
 * extra arguments (its handler is AiMoveCursorToCommandPoint). */
void func_020c6bb0(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    SetBattleCommand(9, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
}

/* Wait: end the action of the unit under the cursor without doing anything.
 * Refresh the battle menu state, drop the menu sprites and post battle command
 * AI_COMMAND_WAIT for that unit, which marks it as having acted this turn. */
void ConfirmWaitCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    SetBattleCommand(AI_COMMAND_WAIT, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
}

void func_020c6c20(void) {
    M2C_UNK CreateMapCursorOption(M2C_UNK);
    M2C_UNK AcquireMapViewHold();
    CreateMapCursorOption(0);
    DeleteMapMenuSprites();
    AcquireMapViewHold();
}

void func_020c6c38(void) {
    CreateMapCursorOption(1);
    DeleteMapMenuSprites();
    AcquireMapViewHold();
}

/* Carried-unit menu action for the first cargo slot: leave the target/command
 * state, close the map menu, cancel any unit-move preview and begin moving the
 * unit the cursor's carrier holds in its first slot. */
void SelectFirstCarriedUnit(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK DeleteAllUnitMoveObjects();
    M2C_UNK SelectCarriedUnit(void *, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    DeleteAllUnitMoveObjects();
    SelectCarriedUnit(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), 0, 0);
}

/* Carried-unit menu action for the second cargo slot: leave the target/command
 * state, close the map menu, cancel any unit-move preview and begin moving the
 * unit the cursor's carrier holds in its second slot. */
void SelectSecondCarriedUnit(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK DeleteAllUnitMoveObjects();
    M2C_UNK SelectCarriedUnit(void *, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    DeleteAllUnitMoveObjects();
    SelectCarriedUnit(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), 1, 0);
}

/* Map action menu: refresh the battle menu state, close the menu and post battle
 * command 0x17 for the unit under the cursor, which runs the property capture
 * update (func_020bc0e0) on the tile it stands on. */
void ConfirmCapturePropertyCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK SetBattleCommand(s32, u8, s32, s32);
    extern void **gCurrentMap;

    SetMapCommandPending();
    DeleteMapMenuSprites();
    SetBattleCommand(0x17, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), 0, 0);
}

