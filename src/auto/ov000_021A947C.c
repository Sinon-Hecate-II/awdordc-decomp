/* 29 functions from 0x021A947C to 0x021AA3FC (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
static inline s32 unit_blocks_action(s32 unit) {
 extern void **gCurrentMap;
 s32 GetPlayerArmyVariant(s32);
 if (((u32)(M2C_FIELD((u8 *)*gCurrentMap + unit*0x8c, s32 *, 0x6810)<<24)>>24)==3 && GetPlayerArmyVariant(unit)) return 1;
 return 0;
}

#pragma push
#pragma opt_propagation off
/* Fog-of-war visibility test used by targeting and threat marking: tells whether a
 * unit of the given kind, belonging to the given player, standing at (x,y) is visible.
 * Units are visible with fog off, when the cell holds a friendly unit, or when an
 * orthogonal neighbour does; the unit kind and the cell's terrain can also hide it. */
s32 IsUnitVisibleAtCell(s32 player, s32 unitKind, s32 x, s32 y) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 gUnitKindFlags[];
    extern s8 data_ov000_021b5680[];
    s32 GetPlayerArmyVariant(s32);
    u8 IsCellUnitOnSameArmy(u8, s32, s32);
    s32 IsCellTerrainExcludedForPlayer(s32, s32, s32);

    s32 cellY = y;
    s32 cellX = x;
    s32 kind = unitKind;
    s32 side = player;
    u16 neighbours = 0;

    if (M2C_FIELD(*gCurrentMap, u8 *, 0x5156) == 0) {
        if (M2C_FIELD(gAiCommandState, u8 *, 0xD) != 2) {
            return 1;
        }
    }
        if (!IsCellTerrainExcludedForPlayer(side, cellX, cellY)) {
            return 1;
        }
    if (unit_blocks_action(side)) return 1;

    if (IsCellUnitOnSameArmy(side, cellX, cellY) == 1) {
        return 1;
    }

    if (gUnitKindFlags[kind * 0x70] == 0x10) {
        u16 row = M2C_FIELD((u8 *)*gCurrentMap + cellY * 2, u16 *, MAP_ROW_OFFSETS);
        u8 terrain = M2C_FIELD((u8 *)*gCurrentMap + (cellX + row), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
        if (data_ov000_021b5680[terrain] == 0) {
            return 1;
        }
    }

    if (cellX > 0) {
        neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, (s16)(cellX - 1), cellY));
    }
    if (cellY > 0) {
        neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, cellX, (s16)(cellY - 1)));
    }
    {
        u16 width = M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH);
        if (cellX < (s32)width - 1) {
            neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, (s16)(cellX + 1), cellY));
        }
    }
    {
        u16 height = M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT);
        if (cellY < (s32)height - 1) {
            neighbours = (u16)(neighbours + IsCellUnitOnSameArmy(side, cellX, (s16)(cellY + 1)));
        }
    }

    return neighbours != 0;
}
#pragma pop
/* Estimated damage an attack of `attackerKind` deals to `targetKind` under the
 * map's current weather for the current player; `applyBonus` also counts the
 * CO-zone bonus.  func_ov000_021a96f4 is the same estimate for the alternate
 * damage row. */
s32 GetAttackDamage(s32 attackerKind, s32 targetKind, s32 applyBonus) {
    M2C_UNK GetEstimatedDamage(M2C_UNK, M2C_UNK, s32, u8, s32, s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    GetEstimatedDamage(attackerKind, targetKind, 0,
        M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_WEATHER),
        M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), 0, applyBonus);
}

/* Damage estimate of `attackerKind` against a submerged target of `targetKind`:
 * the same estimate as GetAttackDamage but with the damage row used for a
 * submerged target. */
void GetSubmergedAttackDamage(M2C_UNK attackerKind, M2C_UNK targetKind, s32 applyBonus) {
    M2C_UNK GetEstimatedDamage(M2C_UNK, M2C_UNK, s32, u8, s32, s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    GetEstimatedDamage(attackerKind, targetKind, 1, M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_WEATHER), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), 0, applyBonus);
}

/* The higher of the unit's two weapon damage percentages against a target kind:
 * the primary weapon only while the unit still has ammo, the secondary always. */
s32 GetUnitMaxWeaponDamagePercent(void *unit, M2C_UNK targetKind) {
    s32 GetDamageTargetIndex(M2C_UNK);
    s32 CalculateUnitDamage(void *, s32, M2C_UNK, M2C_UNK);
    extern u8 gUnitKindMaxAmmo;
    s32 secondaryDamage;
    s32 primaryDamage;
    if ((*(&gUnitKindMaxAmmo + (((u32) (M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 0x1A) >> 0x1A) * 0x70)) != 0) && (((u32) (M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 0x15) >> 0x1C) == 0)) {
        primaryDamage = 0;
    } else {
        primaryDamage = CalculateUnitDamage(unit, GetDamageTargetIndex(targetKind), 0, 0);
    }
    secondaryDamage = CalculateUnitDamage(unit, GetDamageTargetIndex(targetKind), 1, 0);
    if (primaryDamage > secondaryDamage) secondaryDamage = primaryDamage;
    return secondaryDamage;
}

void GetUnitDamagePercent(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK GetBestWeaponDamagePercent(M2C_UNK, M2C_UNK, M2C_UNK);
    GetBestWeaponDamagePercent(arg0, arg1, 0);
}

/* Movement range of a unit of `unitKind` for the player the map view belongs
 * to, using the weather the AI plans movement with; no CO-zone bonus. */
s32 GetUnitMoveRange(u16 player, s32 unitKind) {
    s32 ComputeUnitMoveRange(s32, u8, u16, s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    (void)player;
    return ComputeUnitMoveRange(unitKind, M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_PLAN_WEATHER), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), 0, 0);
}

/* Highest attack range of a unit of `unitKind` for the player the map view
 * belongs to, using the weather the AI plans with; no CO-zone bonus. */
s32 GetUnitMaxAttackRange(u16 player, s32 unitKind) {
    s32 ComputeUnitMaxAttackRange(s32, s32, s32, s32, u8);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    (void)player;
    return ComputeUnitMaxAttackRange(unitKind, M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_PLAN_WEATHER), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), 0, 0);
}

/* Whether the map cell at (x, y) is a capturable property: its terrain kind is a
 * property kind (silos count too, though their property-flag table entry is 0). */
s32 IsPropertyCell(s32 x, s32 y) {
    extern void **data_027e0058;
    s32 GetTerrainPropertyFlagsAt(s32, s32);
    s32 map = (s32)*data_027e0058;
    if ((M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_SILO) return 1;
    return GetTerrainPropertyFlagsAt(x, y);
}

/* Whether `kind` is one of the infantry-class foot kinds: Infantry, Mech or Bike. */
s32 IsFootUnitKind(s32 kind) {
 switch(kind){case UNIT_KIND_INFANTRY:case UNIT_KIND_MECH:case UNIT_KIND_BIKE:return 1;default:return 0;}
}

/* Whether `kind` is a kind that can capture a property: Infantry or Mech. */
s32 IsCaptureKind(s32 kind) {
 switch(kind){case UNIT_KIND_INFANTRY:case UNIT_KIND_MECH:return 1;default:return 0;}
}

/* Attack class (UNIT_ATTACK_*) of unit kind `kind`, from the kind's maximum
 * attack range: direct for range 1, indirect for longer ranges, none for range 0. */
s32 GetUnitAttackClass(s32 kind) {
    s32 GetUnitKindMaxAttackRange(s32);
    s32 maxRange;

    maxRange = GetUnitKindMaxAttackRange(kind);
    if (maxRange > 1) {
        return UNIT_ATTACK_INDIRECT;
    }
    if (maxRange == 1) {
        return UNIT_ATTACK_DIRECT;
    }
    return UNIT_ATTACK_NONE;
}

/* Attack class (UNIT_ATTACK_*) of a unit kind: UNIT_KIND_UNARMED always counts as
 * unarmed; otherwise the kind's maximum attack range decides - 1 is direct, more
 * is indirect and 0 cannot attack. */
s32 GetKindAttackClass(s32 unitKind) {
    s32 maxRange;

    maxRange = GetUnitKindMaxAttackRange(unitKind);
    if (unitKind == UNIT_KIND_UNARMED) {
        return UNIT_ATTACK_NONE;
    }
    if (maxRange > 1) {
        return UNIT_ATTACK_INDIRECT;
    }
    if (maxRange == 1) {
        return UNIT_ATTACK_DIRECT;
    }
    return UNIT_ATTACK_NONE;
}

/* Whether a unit of kind `carrierKind` may load (carry) a unit of kind `cargoKind`:
 * look up the carrier kind's load class, then the cargo kind's row of the load mask
 * at that class. */
s32 CanKindCarryKind(s32 carrierKind, s32 cargoKind) {
    extern u8 gUnitKindLoadMask[];
    extern u8 gUnitKindLoadClass[];
    u8 *row = &gUnitKindLoadMask[cargoKind * UNIT_KIND_STATS_SIZE];

    return row[gUnitKindLoadClass[carrierKind * UNIT_KIND_STATS_SIZE]];
}

/* Whether `unit` can attack a unit of `targetKind`: its kind must have cargo
 * slots, must be able to hit that kind, and its last cargo slot must be empty. */
u8 CanUnitAttackKind(u8 *unit, s32 targetKind) {
    extern u8 gUnitKindCargoCount[];
    u32 unitKind = (u32)(*unit << 26) >> 26;
    u8 result;

    if (!gUnitKindCargoCount[unitKind * 0x70]) return 0;
    if (!CanKindCarryKind(unitKind, targetKind)) return 0;
    if (M2C_FIELD(unit + (gUnitKindCargoCount[((u32)(*unit << 26) >> 26) * 0x70] - 1), u8 *, MAP_UNIT_FIRST_CARRIED) == 0) result = 1;
    else result = 0;
    return result;
}

/* Returns 1 for a unit the AI can ignore as a threat: it cannot attack (kind 25
 * is treated as unarmed) and carries no unit in its first cargo slot. */
s32 IsUnitUnarmedAndEmpty(u8 *unit) {
    if (GetUnitAttackClass((u32)(*unit << 26) >> 26) == UNIT_ATTACK_NONE || ((u32)(*unit << 26) >> 26) == 25) {
        if (unit[MAP_UNIT_FIRST_CARRIED] == 0) return 1;
    }
    return 0;
}

/* Returns 1 if the unit's terrain unit table permits passing through the given map cell. */
u8 CanUnitKindStandAt(s32 unitKind, s32 mapX, s32 mapY) {
    extern void **gCurrentMap;
    extern u8 gUnitKindStats[];
    extern u8 gMovementTypeTable[];
    extern s8 gUnitProductionTerrain[];
    extern u8 gMovementCostTable[];
    void *map = *gCurrentMap;
    s32 terrain = M2C_FIELD(map + (mapX + M2C_FIELD(map + mapY * 2, u16 *, 0x3758)), u8 *, 0x1420) & 31;
    switch (unitKind) {
    case 13:
    case 19:
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[0x82] * 32, s8 *, terrain) != -1;
    case 24:
    case 25:
        if (gUnitProductionTerrain[terrain] == 0) {
            return 0;
        }
        if (M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[0x82] * 32, s8 *, terrain) == -1) {
            return 0;
        }
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gMovementTypeTable[unitKind * 112] * 32, s8 *, terrain) != -1;
    case 21:
    case 23:
        return M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gMovementTypeTable[unitKind * 112] * 32, s8 *, terrain) != -1;
    default:
        return 0;
    }
}

/* Whether the AI may treat destructible map features (properties and terrain) as
   attack targets: true while bit 0 of the current player's per-map player flags is
   clear.  The AI turn start stores the result in its action flags bit 0x04, which
   lets the attack-target scan accept destructible features. */
u8 AiMayAttackMapFeatures(void) {
    extern void **gCurrentMap;
    s32 GetMapPlayerFlags(u16, u16);
    u8 result;
    if (!(GetMapPlayerFlags(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) & 1)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether a map order belongs to a player on the enemy team: it must be in effect
 * (nonzero value) and no player on the current team may be its owner. */
s32 MapOrder_IsEnemyOwned(void *arg0) {
    extern void **gCurrentMap;
    s32 IsSameTeam(u16, s32);
    MapOrder *order = arg0;
    u32 owner = (u32)(M2C_FIELD(order, u8 *, 5) << 29);
    s32 player;
    if (order->value == 0) return 0;
    for (player = 1; player < 5; player++) {
        if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) != 0 && player == (owner >> 29)) return 0;
    }
    return 1;
}

/* True when a player of another team is in the game and owns an HQ: the AI's
 * enemy-directed steps only run against such a player. */
s32 HasEnemyPlayer(void) {
    extern void **gCurrentMap;
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 PlayerHasHq(s32);
    s32 player = 1;
loop:
    if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0 && PlayerHasHq(player) == 1) return 1;
    player++;
    if (player >= MAX_PLAYERS) return 0;
    goto loop;
}

s32 func_ov000_021a9c90(s32 x,s32 y) {
 extern void **data_027e0058; extern void *gAiCommandState;
 s32 count=0,i,xmin=x-1,d,v; register s32 ymin,xmax,ymax;
 if(xmin<0)xmin=0;
 ymin=y-1;
 if(ymin<0)ymin=0;
 xmax=M2C_FIELD(*data_027e0058,u16 *,0x5144)-1;
 if(x+1<xmax)xmax=x+1;
 ymax=M2C_FIELD(*data_027e0058,u16 *,0x5146)-1;
 if(y+1<ymax)ymax=y+1;
 for(;ymin<=ymax;ymin++)for(i=xmin;i<=xmax;i++){
 d=0; if(x-i>0)d+=x-i;else d+=i-x; if(y-ymin>0)d+=y-ymin;else d+=ymin-y;
 if(d<1||d>1)continue;
 v=M2C_FIELD(((s8 **)((u8 *)*data_027e0058+0x52e8))[ymin],s8 *,i);
 if(v>=0 && v<=M2C_FIELD(gAiCommandState,u8 *,5))count++;
 }
 return count;
}

/* Whether the cell (x, y) holds a unit of the current team that the player can
 * see: the cell must be set in the first team's sight bitmap and hold a visible
 * unit id, and IsUnitInSight then rules out a submerged submarine the player
 * cannot spot. */
u8 IsAllyUnitAtCell(u32 x, s32 y) {
    extern void **gCurrentMap;
    s32 IsUnitInSight(u16);
    void *map = *gCurrentMap;
    u32 cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
    s32 unitId;
    if ((u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP_TEAM_A) & (1 << (cell & 7))) == 0) return 0;
    unitId = M2C_FIELD(map + cell, u8 *, MAP_CELL_VISIBLE_UNIT);
    if (unitId != 0) return IsUnitInSight((u16)(unitId & 0xFFFF)) != 0;
    return 0;
}

/* Score moving the selected unit onto tile (x, y): the cell's AI influence plus the
 * weighted direct and indirect threat there, with bonus bits for a cell no ally's
 * direct (bit 0) or indirect (bit 1) attack range covers. */
u32 CellMoveScore(s32 x, s32 y, s32 directWeight, s32 indirectWeight) {
    extern void **gCurrentMap;
    extern u8 gAiInfluenceMap[], gUnitKindFlags[], data_ov000_021dfb04[], gAiRangeBitmap[], data_ov000_021dfa60[], gAiIndirectRangeBitmap[];
    void *base = *gCurrentMap;
    u32 row = M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS);
    u8 *cell = (u8 *) base + (x + row);
    s32 indirectThreat = M2C_FIELD(cell, u8 *, MAP_CELL_THREAT_INDIRECT);
    void *unit = M2C_FIELD(base, void **, MAP_CURSOR_UNIT);
    s32 unitByte = M2C_FIELD(unit, u8 *, MAP_UNIT_KIND);
    s32 kind = (u32) (unitByte << 26) >> 26;
    s32 width = M2C_FIELD(base, u16 *, MAP_WIDTH);
    u32 index = y * width + x;
    u8 flags = gUnitKindFlags[kind * 112];
    u32 score = (gAiInfluenceMap[index] + ((directWeight * M2C_FIELD(cell, u8 *, MAP_CELL_THREAT_DIRECT) + indirectWeight * indirectThreat) << 8)) << 2;
    if (flags & 7) {
        s32 notCovered = (u8) (data_ov000_021dfb04[index >> 3] & (1 << (index & 7))) == 0 ? 1 : 0;
        s32 outOfRange = (u8) ((1 << (index & 7)) & gAiRangeBitmap[index >> 3]) != 0 ? 0 : 2;
        score |= outOfRange | notCovered;
    }
    if (flags & 16) {
        s32 notCovered = (u8) (data_ov000_021dfa60[index >> 3] & (1 << (index & 7))) == 0 ? 1 : 0;
        s32 outOfRange = (u8) ((1 << (index & 7)) & gAiIndirectRangeBitmap[index >> 3]) != 0 ? 0 : 2;
        score |= outOfRange | notCovered;
    }
    return score;
}

/* Returns the id of the best unit the current player can still be ordered to
 * move: the highest-valued unit that has not acted, is at full health, is not
 * the unit already selected, and passes the terrain, commander and cost checks.
 * Returns 0 when there is none. */
s32 FindBestSelectableUnit(void) {
 extern void **gCurrentMap; extern u16 gMapConfig; extern u16 gPlayerUnitIdBase[]; extern s32 (**gAiSettings)(s32,s32);
 s32 GetPlayerCoZoneBonusIndex(u16); s32 IsPlayerSelectionEnabled(u16); void *GetPlayerSelectedUnit(u16); s32 IsUnitSelected(void *); s32 func_020cf908(s32,s32,s32,s32); s32 IsCoZoneKindSelectable(s32,s32); s32 GetUnitActionCost(s32,s32); s32 GetUnitKindBuildCost(s32); s32 AiSettings_DefaultUnitFilter(s32,s32);
 s32 commander; u8 *best; s32 id; u8 *unit; s32 offset;
 GetPlayerCoZoneBonusIndex(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER));
 best=0;
 if(((u32)(gMapConfig<<18)>>31)==0)return 0;
 if(((u32)(M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*140,s32 *,0x6810)<<24)>>24)==0)return 0;
 if(!IsPlayerSelectionEnabled(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return 0;
 if(GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))return 0;
 commander=GetPlayerCoZoneBonusIndex(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER));
 id=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;
 if(id<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+51){
 offset=id*14; do {
 unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+offset;
 if(((u32)(unit[0]<<26)>>26)==0)goto next;
 if(M2C_FIELD(unit,u16 *,4)&9)continue;
 if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)!=100)continue;
 if(IsUnitSelected(unit))continue;
 if(((u32)(unit[11]<<28)>>28)==5 || ((u32)(unit[11]<<28)>>28)==6 || ((u32)(unit[11]<<28)>>28)==8)continue;
 if(!func_020cf908(unit[1],unit[2],M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),(u32)(unit[0]<<26)>>26))continue;
 if(!IsCoZoneKindSelectable(commander,(u32)(unit[0]<<26)>>26))continue;
 {u8 *map=*gCurrentMap; s32 player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
 if(GetUnitActionCost(player,(u32)(unit[0]<<26)>>26)>M2C_FIELD(map+player*140,s32 *,0x67a4))continue;}
 if(*gAiSettings==0){if(AiSettings_DefaultUnitFilter(commander,(u32)(unit[0]<<26)>>26)){goto select;}goto next;}
 else {if((*gAiSettings)(commander,(u32)(unit[0]<<26)>>26))goto select;goto next;}
 select:
 if(best && GetUnitKindBuildCost((u32)(best[0]<<26)>>26)>=GetUnitKindBuildCost((u32)(unit[0]<<26)>>26))continue;
 best=unit;
 next:;
 }while((++id,offset+=14,id)<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+51);
 }
 if(best){if(!best)return 0;return ((s32)best-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/14;}
 return 0;
}

/* Returns the id of the current player's selected unit when the battle enables
   CO abilities and the player's CO power is charged and that unit has not yet
   acted or been loaded; 0 when there is no such unit. */
s32 GetCoPowerUnitId(void) {
    extern u16 gMapConfig;
    extern void **gCurrentMap;
    s32 IsPlayerCoPowerReady(u16);
    void *GetPlayerSelectedUnit(u16);
    void *unit;

    if (((u32)(gMapConfig << 18) >> 31) == 0) return 0;
    if (!IsPlayerCoPowerReady(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) return 0;
    unit = GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    if (M2C_FIELD(unit, u16 *, 4) & (UNIT_FLAG_ACTED | UNIT_FLAG_LOADED)) return 0;
    if (!unit) return 0;
    return ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
}

/* Default AI unit-set filter, used when the AI settings block has no unit picker
   of its own: a unit kind is picked only when the commander's damage row can hit
   it, and only some kinds qualify - 9, 14 and 16 when that row has one weapon,
   7 and 8 as well when it has two, and only 11, 20 and 26 when the row cannot hit
   kind 9 or 14. */
s32 AiSettings_DefaultUnitFilter(s32 commander,s32 unitKind) {
 s32 IsCoZoneKindEnabled(s32,s32); s32 GetCommanderMoveRange(s32,s32);
 if(!IsCoZoneKindEnabled(commander,unitKind))return 0;
 if(IsCoZoneKindEnabled(commander,9)||IsCoZoneKindEnabled(commander,14)){
 if(GetCommanderMoveRange(commander,0)<=1){if(unitKind!=9 && unitKind!=14 && unitKind!=16)return 0;}
 else {if(unitKind!=9 && unitKind!=8 && unitKind!=7 && unitKind!=14 && unitKind!=16)return 0;}
 }else {if(unitKind!=26 && unitKind!=11 && unitKind!=20)return 0;}
 return 1;
}

/* AI settings unit filter: only the fixed unit kinds 7, 8, 9, 11, 14, 16 and 26
 * may be picked.  `commander` is unused (the sibling filter with the same set
 * minus the Tank, kind 7, is AiUnitFilter_ArmorSetNoTank). */
s32 AiUnitFilter_ArmorSet(s32 commander, s32 unitKind) {
    if (unitKind != 9 && unitKind != 8 && unitKind != 7 && unitKind != 14 &&
        unitKind != 16 && unitKind != 26 && unitKind != 11) return 0;
    return 1;
}

/* AI settings unit filter: only the fixed unit kinds 8, 9, 11, 14, 16 and 26 may
 * be picked.  `commander` is unused (the sibling filter with the same set plus
 * the Tank, kind 7, is AiUnitFilter_ArmorSet). */
s32 AiUnitFilter_ArmorSetNoTank(s32 commander, s32 unitKind) {
    if (unitKind != 9 && unitKind != 8 && unitKind != 14 && unitKind != 16 &&
        unitKind != 26 && unitKind != 11) return 0;
    return 1;
}

/* Whether the unit under the cursor is hurt: its health (the low seven bits of
 * MAP_UNIT_HEALTH) is below 50. */
u8 AiCoPowerUnitIsHurt(void) {
    extern void **gCurrentMap;
    u8 result;

    if ((u32) ((u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_HEALTH) << 0x19) >> 0x19) < 0x32U) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

s32 func_ov000_021aa3f4(void) {
    return 1;
}
