/* 71 functions from 0x020A7738 to 0x020A86F8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_entry.h"
static inline s32 A8240InBounds(s32 x, s32 y) {
extern void **gCurrentMap;
if (x>=0 && y>=0 && x<M2C_FIELD(*gCurrentMap,u16 *,0x5144) && y<M2C_FIELD(*gCurrentMap,u16 *,0x5146)) return 1;
return 0;
}
extern const DisplayUnitKindList gUnitKindMenuList;

/* Score of a unit that moves from its own tile to (a,b): the power of its kind, the
 * player's terrain effect and the terrain penalty of the destination.  A player
 * without a terrain category (weather-type 2) only gets the destination penalty. */
s32 GetUnitMoveScore(s32 arg0,s32 a,s32 b,u8 mode) {
M2C_UNK GetUnitOwner(); u8 GetUnitKindByte0(s32); s32 GetUnitTerrainBonus(void *,u8,u8);
extern void **gCurrentMap;
u8 *p=(u8 *)arg0;
s32 power,terrain,result,player;
GetUnitOwner(p);
power=GetUnitKindByte0((u32)(p[0]<<26)>>26);
terrain=GetUnitTerrainBonus(p,p[1],p[2]);
result=GetUnitTerrainPenalty(p,a,b);
result+=power+terrain;
if(p){if(!p)player=0;else player=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;player=(player>>6)+1;}else player=0;
if (((u32)(M2C_FIELD((u8 *)*gCurrentMap+player*0x8c,s32 *,0x6810)<<24)>>24)!=10 && mode==2) result=terrain+1;
if(result<1)result=1;
return result;
}

/* GetUnitMoveScore with the weather as the terrain-effect mode. */
void GetUnitMoveScoreWeather(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK GetUnitMoveScore(M2C_UNK, M2C_UNK, M2C_UNK, u8);
    extern void **gCurrentMap;
    GetUnitMoveScore(arg0, arg1, arg2, M2C_FIELD(*gCurrentMap, u8 *, 0x5158));
}

/* Damage-free move penalty of entering the destination terrain: infantry and mech
 * (kinds 1 and 2) lose 3 points when the destination takes their movement type 4. */
s32 GetUnitTerrainPenalty(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 IsTerrainKindAtTile(M2C_UNK, M2C_UNK, M2C_UNK);
 s32 penalty;
 u32 kind;
 penalty = 0;
 if (IsTerrainKindAtTile(arg1, arg2, 4) != 0) {
  kind = (u32)(*arg0 << 26) >> 26;
  switch (kind) {
  case 1:
  case 2: penalty += 3; break;
  }
 }
 return penalty;
}

u32 func_020a788c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
}

u32 func_020a789c(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C;
}

void func_020a78ac(u8 *arg0) {
    M2C_UNK GetUnitKindMaxAmmo(u32);
    GetUnitKindMaxAmmo((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78c4(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19;
}

void func_020a78d4(u8 *arg0) {
    M2C_UNK GetUnitKindMaxFuel(u32);
    GetUnitKindMaxFuel((u32) (*arg0 << 0x1A) >> 0x1A);
}

u32 func_020a78ec(u8 *arg0) {
    return (u32) (*arg0 << 0x18) >> 0x1E;
}

s32 GetUnitMaxLuck(void *arg0) {
    s32 GetUnitMaxLuckBonus(void *, u8, u8);
    return GetUnitMaxLuckBonus(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2)) + 0xA;
}

s32 GetUnitMinLuck(void *arg0) {
 s32 GetUnitDamageVarianceMin(void *, u8, u8);
 s32 result = 0;
 result += GetUnitDamageVarianceMin(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
 return result;
}

/* Damage percentage one weapon of attacker kind `attackerKind` deals to a target:
 * the `weaponIndex` (0 primary, 1 secondary) block of the kind's damage table,
 * indexed by the target's kind/row.  When the target is a submerged submarine
 * (`targetFlags` nonzero) its dedicated damage row is used instead. */
s32 GetWeaponDamagePercent(s32 attackerKind, s32 targetKind, s32 weaponIndex, s32 targetFlags) {
 s32 GetSubmergedDamageRow(s32, s32);
 extern u8 gUnitKindDamageTable[];
 s32 damageRow;
 damageRow = targetKind;
 if (targetFlags != 0) damageRow = GetSubmergedDamageRow(damageRow, (u8)targetFlags);
 return *(damageRow + (gUnitKindDamageTable + attackerKind * 0x70 + (weaponIndex << 5)));
}

/* Damage percentage of one weapon of attacker kind `attackerKind` against
 * `target`, a map-order target id mapped to its damage-table row: the
 * `weaponIndex` (0 primary, 1 secondary) block of the kind's damage table. */
u8 GetKindWeaponDamagePercent(s32 attackerKind, s32 target, s32 weaponIndex) {
 s32 GetDamageTargetIndex(s32);
 extern u8 gUnitKindDamageTable[];
 return *(GetDamageTargetIndex(target) + (gUnitKindDamageTable + attackerKind * 0x70 + (weaponIndex << 5)));
}

/* The damage percent of the better of a unit kind's two weapons against a target
 * kind, for the given target flags. */
s32 GetBestWeaponDamagePercent(s32 attackerKind, s32 targetKind, s32 targetFlags) {
    s32 GetWeaponDamagePercent(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 secondaryPercent;
    s32 bestPercent;

    bestPercent = GetWeaponDamagePercent(attackerKind, targetKind, 0, targetFlags);
    secondaryPercent = GetWeaponDamagePercent(attackerKind, targetKind, 1, targetFlags);
    if (bestPercent <= secondaryPercent) {
        bestPercent = secondaryPercent;
    }
    return bestPercent;
}

/* Estimate the damage a unit kind deals: the higher of its two weapons' damage
 * percentages, scaled by 100 + the kind's damage bonus, never below 1.  Returns
 * 0 when neither weapon can damage the target. */
s32 GetEstimatedDamage(s32 kind, s32 row, s32 altRow, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
 s32 Divide(s32, s32);
 s32 GetKindDamageBonus(s32, s32, s32, s32, u8);
 register s32 temp_r0;
 s32 damage;
 s32 base;
 s32 percent;
 percent = GetWeaponDamagePercent(kind, row, 0, altRow);
 temp_r0 = GetWeaponDamagePercent(kind, row, 1, altRow);
 base = 100;
 if (percent <= temp_r0) percent = temp_r0;
 if ((int)percent == 0) return 0;
 temp_r0 = GetKindDamageBonus(kind, weather, player, bonusType, applyBonus);
 base += temp_r0;
 damage = Divide(percent * base, 100);
 if (damage <= 1) damage = 1;
 return damage;
}
/* Percentage bonus a unit kind's damage estimate gets: the owner's attack
 * properties (5 percent each), the sandstorm penalty that every army but the
 * weather-immune one takes, and the army's CO-zone attack bonus for the kind. */
s32 GetKindDamageBonus(s32 kind, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
    u8 IsUnitKindClass6();
    s32 GetPlayerAttackPropertyBonus(s32);
    s32 GetCoZoneAttackBonus(s32, s32, s32);
    extern void **gCurrentMap;
    s32 bonus = 0;

    if (IsUnitKindClass6(kind) != 0) return bonus;
    bonus += GetPlayerAttackPropertyBonus(player);
    if (((u32)(M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + ARMY_REC_ARMY_ID) << 24) >> 24) != ARMY_WEATHER_IMMUNE && weather == WEATHER_SANDSTORM) bonus -= 30;
    if (applyBonus != 0 || bonusType != 0) bonus += GetCoZoneAttackBonus(kind, player, bonusType);
    return bonus;
}

/* Byte 0 of a unit kind entry: the kind's first stat byte (gUnitKindTable). */
u8 GetUnitKindByte0(s32 arg0) {
 extern u8 gUnitKindTable[];
 return gUnitKindTable[arg0 * 0x70];
}

u8 GetUnitKindMoveRange(s32 arg0) {
 extern u8 gUnitKindMoveRange[];
 return gUnitKindMoveRange[arg0 * 0x70];
}

/* Movement range of a unit of `kind` for player `player`: the kind's base range,
 * plus its CO-zone movement bonus when one applies, less one in rain for an army
 * that the weather does not spare. */
s32 ComputeUnitMoveRange(s32 kind, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
 s32 GetCoZoneMoveBonus(s32, s32, s32);
 extern u8 gUnitKindMoveRange[];
 extern void **gCurrentMap;
 s32 range;
 range = gUnitKindMoveRange[kind * 0x70];
 if (bonusType != 0 || applyBonus != 0) range += GetCoZoneMoveBonus(kind, player, bonusType);
 if ((u32)(M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + ARMY_REC_ARMY_ID) << 24) >> 24 != ARMY_WEATHER_IMMUNE && weather == WEATHER_RAIN) range--;
 return range;
}

u16 GetUnitKindBuildCost(s32 arg0) {
 extern u8 gUnitKindBuildCosts[];
 return *(u16 *)(gUnitKindBuildCosts + arg0 * 0x70);
}

u8 GetUnitKindMaxAttackRange(s32 arg0) {
 extern u8 gUnitMaxAttackRange[];
 return gUnitMaxAttackRange[arg0 * 0x70];
}

void func_020a7bec(void) {
    u8 GetUnitKindMaxAttackRange();
    GetUnitKindMaxAttackRange();
}

u8 func_020a7bf8(s32 arg0) {
 extern u8 data_ov000_021b5c0c[];
 return data_ov000_021b5c0c[arg0 * 0x70];
}

/* Highest attack range of a unit of `kind` for player `player`: the kind's base
 * range, plus its CO-zone range bonus when one applies.  `weather` is unused here
 * (unlike the move range). */
s32 ComputeUnitMaxAttackRange(s32 kind, s32 weather, s32 player, s32 bonusType, u8 applyBonus) {
 s32 GetCoZoneRangeBonus(s32, s32, s32);
 extern u8 gUnitMaxAttackRange[];
 s32 range;
 range = gUnitMaxAttackRange[kind * 0x70];
 if (bonusType != 0 || applyBonus != 0) range += GetCoZoneRangeBonus(kind, player, bonusType);
 return range;
}

s32 GetUnitKindMaxFuel(u32 arg0) {
 extern u8 gUnitKindMaxFuel[];
 return gUnitKindMaxFuel[arg0 * 0x70];
}

s32 GetUnitKindMaxAmmo(u32 arg0) {
 extern u8 gUnitKindMaxAmmo[];
 return gUnitKindMaxAmmo[arg0 * 0x70];
}

/* The class byte (a unit-kind record's +0x10 field, UNIT_KIND_STATS_CLASS) of
 * unit kind `kind`.  The callers raise or lower it through the wrappers below. */
s32 GetUnitKindClass(kind)
s32 kind;
{
 extern u8 gUnitKindClass[];
 return gUnitKindClass[kind * 0x70];
}

u8 func_020a7c98(s32 arg0) {
 extern u8 gMovementTypeTable[];
 return gMovementTypeTable[arg0 * 0x70];
}

u8 HasUnitActed(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Nonzero when the unit has capture points: it is part-way through capturing the
 * property it stands on (MAP_UNIT_CAPTURE; 20 points completes the capture). */
u8 UnitHasCapturePoints(void *unit) {
    u8 hasPoints;

    if (((u32) (M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 0x10) >> 0x1B) != 0) {
        hasPoints = 1;
    } else {
        hasPoints = 0;
    }
    return hasPoints;
}

u8 UnitHasCargo(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Whether `unit` is the unit the player that owns it has currently selected. */
u8 IsUnitSelected(u8 *unit) {
    s32 GetUnitOwner(u8 *);
    u8 *GetPlayerSelectedUnit(s32);
    u8 selected;

    if (unit == GetPlayerSelectedUnit(GetUnitOwner(unit))) {
        selected = 1;
    } else {
        selected = 0;
    }
    return selected;
}

u8 func_020a7d20(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitSubmerged(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x20) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitMarkedForRepair(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x100) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020a7d68(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u16 *, 4) & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Whether a unit's fuel has fallen to half its kind's maximum or below; a kind
 * with no fuel (maximum 0) is never low. */
u8 IsUnitLowOnFuel(void *unit) {
 s32 GetUnitKindMaxFuel(u32);
 s32 maxFuel;
 s32 lowFuel;
 maxFuel = GetUnitKindMaxFuel((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26);
 if (maxFuel > 0 && (maxFuel >> 1) >= (s32)((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_FUEL) << 25) >> 25)) lowFuel = 1;
 else lowFuel = 0;
 return lowFuel;
}

/* Status check: the unit's kind carries ammo at all and the unit has spent its
 * way down to at most half of its kind's maximum, so the low-ammo icon shows. */
u8 IsUnitLowOnAmmo(void *unit) {
 s32 maxAmmo;
 s32 result;
 maxAmmo = GetUnitKindMaxAmmo((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26);
 if (maxAmmo > 0 && (maxAmmo >> 1) >= (s32)((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 21) >> 28)) result = 1;
 else result = 0;
 return result;
}

/* Whether `unit`'s kind is a supply unit (a rig or carrier, the kinds whose
 * Supply command resupplies and repairs its neighbours). */
u8 IsSupplyUnitKind(u8 *unit) {
    extern u8 gUnitKindSupplyUnit[];
    u8 result;

    if (gUnitKindSupplyUnit[((u32)(*unit << 26) >> 26) * 0x70]) result = 1;
    else result = 0;
    return result;
}

/* If `unit` is the unit its player has selected, drops that selection: the
 * selected-unit slot is cleared and, when `clearState` is set, the selection
 * state is cleared too; a human player's selection is counted in the records. */
void ClearPlayerSelectedUnit(s32 unit,s32 clearState){
s32 SetCoPowerMeterPoints(s32,s32);void DisablePlayerSelection(s32);s32 IsPlayerHuman(s32);void AddRecordValue(s32,s32);
extern void **gCurrentMap;
s32 player;u8 *map,*record;
if(!unit)return;
if(!unit)player=0;else player=(unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;
player=(player>>6)+1;
map=(u8 *)*gCurrentMap;
record=map+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE;
if(!((u32)(*(s32 *)(record+PLAYER_REC_SPRITE)<<24)>>24))return;
if(unit!=(s32)(map+MAP_UNIT_RECORDS+record[PLAYER_REC_SELECTED_UNIT]*MAP_UNIT_STRIDE))return;
record[PLAYER_REC_SELECTED_UNIT]=0;
if(clearState){
SetCoPowerMeterPoints(player,0);DisablePlayerSelection(player);
}
if(!IsPlayerHuman(player))return;
AddRecordValue(28,1);
}

/* Set a unit's capture points to `points` (0 stops its capture): replace the
 * five MAP_UNIT_CAPTURE bits with the low five bits of `points`. */
void SetUnitCapturePoints(void *unit, u32 points) {
    u16 value = M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE);
    points = (u16) points;
    M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) = (value & ~MAP_UNIT_CAPTURE_MASK) | ((points << 27) >> 16);
}

u32 GetUnitCapturePoints(void *arg0) {
    return (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x10) >> 0x1B;
}

/* Mark enemy units in the scanned area, and mark the moving unit when
 * a scanned unit belongs to an opposing team. */
void MarkEnemyUnitsInArea(void *unit, s32 x, s32 y, s32 mode) {
    extern void **gCurrentMap;
    void InitAreaScan(void *, s32, s32, s32, s32, s32);
    s32 NextAreaTile(void *);
    u8 IsCellUnitOccupied(s32, s32);
    u8 IsEnemyUnit(s32, s32);
    u8 AreUnitsEnemies(s32, s32);
    void SetUnitCapturePoints(void *, u32);
    s32 iter[8];
    void *map;
    void *units;
    s32 unitIndex;

    map = *gCurrentMap;
    InitAreaScan(iter, mode, x, y, M2C_FIELD(map, u16 *, 0x5144),
        M2C_FIELD(map, u16 *, 0x5146));
    for (;;) {
        if (!NextAreaTile(iter)) {
            return;
        }
        if (IsCellUnitOccupied(iter[4], iter[5])) {
            map = *gCurrentMap;
            unitIndex = M2C_FIELD(M2C_FIELD(map + 2 * iter[5], u16 *, MAP_ROW_OFFSETS) +
                (map + iter[4]), u8 *, MAP_CELL_UNIT_ID);
            units = map + MAP_UNIT_RECORDS;
            if (IsEnemyUnit((s32)unit, (s32)(units + unitIndex * MAP_UNIT_STRIDE))) {
                SetUnitCapturePoints(units + unitIndex * MAP_UNIT_STRIDE, 1);
            }
            if (AreUnitsEnemies((s32)unit, (s32)(units + unitIndex * MAP_UNIT_STRIDE))) {
                SetUnitCapturePoints(unit, 1);
            }
        }
    }
}

#pragma push
#pragma peephole on
void MarkUnitMovePath(void *p,s16 *xy,s32 unused,s8 *dir){void MarkEnemyUnitsInArea(void *,s32,s32,s32);s32 x=xy[0],y=xy[1];MarkEnemyUnitsInArea(p,x,y,1);for(;;){switch(*dir++){case 0:x--;break;case 1:x++;break;case 3:y--;break;case 2:y++;break;case -1:case 4:case 10:return;}MarkEnemyUnitsInArea(p,x,y,1);}}
#pragma pop
/* Whether `other` is a unit that `unit` may affect (an enemy): 0 when there is no
 * other unit, otherwise 1 when the two belong to different teams.  A null `unit`
 * counts as affecting any valid other unit. */
u8 IsEnemyUnit(s32 unit, s32 other) {
    s32 owner;
    u8 result;

    if ((other == 0) || (IsUnitPresent(other) == 0)) {
        return 0U;
    }
    if (unit == 0) {
        return 1U;
    }
    owner = GetUnitOwner(unit);
    if (IsSameTeam(owner, GetUnitOwner(other)) == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether `unit` and `other` both exist and belong to different teams.  Unlike
 * IsEnemyUnit, a null `unit` does not count as affecting any unit. */
u8 AreUnitsEnemies(s32 unit, s32 other) {
    s32 owner;
    u8 result;

    if ((unit == 0) || (IsUnitPresent(unit) == 0)) {
        return 0U;
    }
    if (other == 0) {
        return 0U;
    }
    owner = GetUnitOwner(unit);
    if (IsSameTeam(owner, GetUnitOwner(other)) == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

s32 IsUnitPresent(void) {
    return 0;
}

/* Nonzero when the unit is present (the guard IsUnitPresent, stubbed to false in
 * this build) and has accumulated capture points. */
u8 IsUnitCapturing(void *unit) {
    u8 result;

    if (IsUnitPresent() == 0) {
        return 0U;
    }
    if (GetUnitCapturePoints(unit) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* True when `unit` still has primary-weapon ammo and its kind carries a primary
 * weapon at all (the Flare, Rig and Carrier do not). */
u8 CanUnitUsePrimaryWeapon(void *unit) {
    s32 UnitKindLacksPrimaryWeapon(u32);
    u8 usable;

    if (((u32) (M2C_FIELD(unit, u16 *, MAP_UNIT_AMMO) << 21) >> 28) == 0) {
        return 0U;
    }
    if (UnitKindLacksPrimaryWeapon((u32) (M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 0x1A) >> 0x1A) == 0) {
        usable = 1;
    } else {
        usable = 0;
    }
    return usable;
}

/* Builds the MOVE_DIR_* step list that slides a unit from its current tile by
 * (dx, dy) tiles, horizontally first and then vertically, stopping at the map
 * edge or at an occupied cell.  The list ends with MOVE_DIR_NONE. */
void BuildMovePath(u8 *unit, s32 dx, s32 dy, u8 *out) {
extern void **gCurrentMap;
s32 y; s32 x; s32 step; s32 n;
x=unit[1];y=unit[2];
n=dx<0?-dx:dx; step=dx>0?1:-(dx<0);
while(n>0){
x+=step;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD((u8 *)*gCurrentMap+x+M2C_FIELD((u8 *)*gCurrentMap+((u32)y<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_UNIT_ID)!=0)break;
n--; if(step>0)*out++=MOVE_DIR_RIGHT; if(step<0)*out++=MOVE_DIR_LEFT;
}
n=dy<0?-dy:dy; step=dy>0?1:-(dy<0);
while(n>0){
y+=step;
if(!A8240InBounds(x,y))break;
if(M2C_FIELD((u8 *)(x+(u32)*gCurrentMap)+M2C_FIELD((u8 *)*gCurrentMap+((u32)y<<1),u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_UNIT_ID)!=0)break;
n--; if(step>0)*out++=MOVE_DIR_DOWN; if(step<0)*out++=MOVE_DIR_UP;
}
*(s8 *)out=MOVE_DIR_NONE;
}

#pragma optimize_for_size on
void ApplyMovePath(u8 *p,s8 *dir){do{switch(*dir++){case 9:dir++;break;case -1:case 4:return;case 0:p[1]--;break;case 1:p[1]++;break;case 3:p[2]--;break;case 2:p[2]++;break;case 10:default:break;}}while(1);}
#pragma optimize_for_size reset
void func_020a8474(void) {

}

/* Whether a unit stands on the map cell (x, y): the cell's unit id is nonzero. */
u8 IsCellUnitOccupied(s32 x, s32 y) {
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    return M2C_FIELD((u8 *)map + (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID) != 0;
}

/* Whether the map tile (x, y) has no unit on it: the tile's unit id is zero. */
u8 IsCellUnitEmpty(s32 x, s32 y) {
    extern void **gCurrentMap;
    void *map = *gCurrentMap;
    return M2C_FIELD((u8 *)map + (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID) == 0;
}

/* Whether the unit kind has class 3.  The kind arrives in r0 from the caller's
 * old-style call, so the accessor takes it implicitly. */
u8 IsUnitKindClass3(void) {
    s32 GetUnitKindClass();
    u8 result;

    if (GetUnitKindClass() == 3) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether the unit kind has class 4.  Like IsUnitKindClass3, the kind arrives in
 * r0 from the caller's old-style call. */
u8 IsUnitKindClass4(void) {
    s32 GetUnitKindClass();
    u8 result;

    if (GetUnitKindClass() == 4) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether the unit kind given is of class 3 or 4.  The class accessors take the
 * kind word implicitly (it is still in r0), so it is passed through unchanged. */
s32 IsUnitKindClass3Or4(void *kind) {
    u8 IsUnitKindClass3();
    u8 IsUnitKindClass4();
    s32 isClass;

    if (IsUnitKindClass3(kind) || IsUnitKindClass4(kind)) isClass = 1;
    else isClass = 0;
    return (u8) isClass;
}

/* Whether the unit kind has class 6: the kinds exempt from the attack/damage
 * bonuses and passed over by scripted damage (DamageUnitAtTile).  Like the other
 * class checks, the kind arrives in r0 from the caller's old-style call. */
u8 IsUnitKindClass6(void) {
    s32 GetUnitKindClass();
    u8 result;

    if (GetUnitKindClass() == 6) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether a unit kind gets no terrain defense from the tile it stands on:
 * unit-kind classes 3, 4 and 6 are exempt, every other kind takes cover. */
s32 UnitKindTakesNoTerrainDefense(s32 kind) {
    s32 IsUnitKindClass3Or4(void *);
    u8 IsUnitKindClass6();

    if (!kind) return 0;
    if (IsUnitKindClass3Or4((void *)kind) || IsUnitKindClass6(kind)) return 1;
    return 0;
}

s32 func_020a85b8(void) {
    return 0;
}

s32 func_020a85c0(void) {
    return 0;
}

u8 IsMobileIndirectUnitKind(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x14) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsCarrierUnitKind(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsUnitKindCarrier(s32 arg0) {
    u8 var_r0;

    if (arg0 == 0x15) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* True for the unit kinds that resupply adjacent units: the Rig and the Carrier. */
s32 UnitKindCanSupply(s32 unitKind) {
    switch (unitKind) {
    case UNIT_KIND_RIG:
        return 1;
    case UNIT_KIND_CARRIER:
        return 1;
    default:
        return 0;
    }
}

/* True for the unit kinds that carry no primary weapon: the Flare, Rig and Carrier. */
s32 UnitKindLacksPrimaryWeapon(u32 unitKind) {
 switch (unitKind) {
 case UNIT_KIND_FLARE: return 1;
 case UNIT_KIND_RIG: return 1;
 case UNIT_KIND_CARRIER: return 1;
 default: return 0;
 }
}

/* Unit kind at display slot `index` of gUnitKindMenuList, in the order the unit
 * list and the CO-zone panel draw them; 0 for the entry that ends the list. */
u8 GetDisplayUnitKind(u32 index) {
    DisplayUnitKindList list = gUnitKindMenuList;
    return list.values[index];
}

s32 func_020a86bc(void) {
    return 0;
}

/* Funds one property pays its owner per turn: the map's income setting when the
 * property's terrain kind is one the income table marks (city, base, HQ, port and
 * the other kinds that pay), otherwise nothing.  Every property kind pays the
 * same, whatever the owner. */
s32 GetPropertyIncome(s32 owner, s32 kind) {
    extern s8 gPropertyIncomeKinds[];
    extern u16 gMapConfig[];
    s32 income = 0;
    if (gPropertyIncomeKinds[kind & 0x1F]) income += M2C_FIELD(gMapConfig, u16 *, MAPCONFIG_INCOME);
    return income;
}

s32 GetPlayerFuelRate(void) {
    return 1;
}

