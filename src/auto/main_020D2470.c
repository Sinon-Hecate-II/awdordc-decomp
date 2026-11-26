/* 48 functions from 0x020D2470 to 0x020D3464 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 kind:6; u8 flags:2; } SelectionKind;
typedef struct { SelectionKind kind; u8 pad[3]; u16 flags; u8 tail[8]; } SelectionUnit;

#pragma optimization_level 3
void func_020d2470(void) {
    extern s32 *gCurrentMap;
    s32 GetPropertyIncome(s32, s32);
    u8 *p;
    u8 *rec;
    s32 i;
    s32 off;
    s32 y;
    s32 x;
    u8 byte;
    s32 idx;

    i = 0;
    off = 0;
    y = 0;
    do {
        i++;
        *(s32 *)((u8 *)*gCurrentMap + off + 0x67ac) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b4) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b5) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b6) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b7) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b8) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67b9) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67ba) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67bb) = 0;
        *(u8 *)((u8 *)*gCurrentMap + off + 0x67cf) |= 0x80;
        off += 0x8c;
    } while (i < 5);

    p = (u8 *)*gCurrentMap;
    if ((s32)M2C_FIELD(p, u16 *, 0x5146) <= 0) {
        return;
    }
    do {
        x = 0;
        if ((s32)M2C_FIELD(p, u16 *, 0x5144) > 0) {
            do {
                byte = *(u8 *)(p + M2C_FIELD(p + y * 2, u16 *, 0x3758) + x + 0x1420);
                if (byte & 0xe0) {
                    idx = (byte & 0xe0) >> 5;
                    rec = (u8 *)(p + 0x67a4 + idx * 0x8c);
                    switch (byte & 0x1f) {
                    case 15:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x2b] = x;
                        rec[0x2c] = y;
                        break;
                    case 17:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x10]++;
                        break;
                    case 16:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x11]++;
                        break;
                    case 22:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x14]++;
                        break;
                    case 23:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x15]++;
                        break;
                    case 18:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x12]++;
                        break;
                    case 19:
                        *(s32 *)(rec + 8) += GetPropertyIncome(idx, byte & 0x1f);
                        rec[0x13]++;
                        break;
                    case 20:
                        rec[0x16]++;
                        break;
                    case 21:
                        rec[0x17]++;
                        break;
                    }
                }
                p = (u8 *)*gCurrentMap;
                x++;
            } while (x < (s32)M2C_FIELD(p, u16 *, 0x5144));
        }
        y++;
    } while (y < (s32)M2C_FIELD(p, u16 *, 0x5146));
}
#pragma optimization_level reset
/* Whether the player records of a and b share an army, i.e. are on the same team. */
u8 IsSameTeam(s32 a, s32 b) {
    extern s32 *gCurrentMap;
    s32 base;
    s32 work;
    u8 *p1;
    u8 *p2;

    base = *gCurrentMap + 0x3A4;
    work = base + 0x6400;
    p1 = (u8 *)(work + a * MAP_PLAYER_STRIDE);
    p2 = (u8 *)(work + b * MAP_PLAYER_STRIDE);
    return p1[PLAYER_REC_ARMY] == p2[PLAYER_REC_ARMY];
}

/* Whether two map unit records belong to the same team: their owners share an
 * army. */
u8 AreUnitsOnSameTeam(s32 unit, s32 other) {
    u8 IsSameTeam(s32, s32);
    s32 GetUnitOwner(s32);
    s32 owner;

    owner = GetUnitOwner(unit);
    return IsSameTeam(owner, GetUnitOwner(other));
}

void func_020d27a4(s32 arg0, s32 arg1) {
    u8 IsSameTeam(s32, s32);
    IsSameTeam((arg0 >> 6) + 1, (arg1 >> 6) + 1);
}

/* Whether unit `unitId` belongs to the map's current player's team: the player
 * its owner group names (1-based) is on the same side as the current player. */
u8 IsUnitOnCurrentTeam(s32 unitId) {
    extern s32 *gCurrentMap;
    u8 IsSameTeam(s32, s32);

    return IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER),
                      (unitId >> MAP_UNIT_OWNER_SHIFT) + 1);
}

s32 IsTerrainOnUnitTeam(s32 arg0, s32 arg1) {
    s32 temp = arg0 >> 6;
    if ((arg1 >> 5) == 0) {
        return 0;
    }
    return IsSameTeam(temp + 1, arg1 >> 5);
}

/* Whether the property at tile (x, y) belongs to a player on `player`'s team:
 * the cell's terrain owner bits (owner << MAP_PROPERTY_TILE_OWNER_SHIFT) are 0
 * when the property is unowned, otherwise the owner is compared with `player`
 * through IsSameTeam. */
s32 IsPropertyOwnedByTeam(s32 player, s32 x, s32 y) {
    extern s32 *gCurrentMap;
    u8 IsSameTeam(s32, s32);
    s32 map;
    u16 rowOffset;
    u8 terrain;
    s32 cellIndex;

    map = *gCurrentMap;
    rowOffset = *(u16 *)(map + y * 2 + MAP_ROW_OFFSETS);
    cellIndex = x + rowOffset;
    terrain = *(u8 *)(map + cellIndex + MAP_CELL_TERRAIN);
    if ((terrain >> 5) == 0) {
        return 0;
    }
    return IsSameTeam(player, terrain >> 5);
}

/* Whether a map unit of `kind` that carries units should show its cargo marker:
 * only while fog of war is on or the weather is snow, and only for a unit whose
 * owner's side does not carry the SIDE_TEAM_B bit, when the kind has cargo slots. */
s32 Map_ShowsCargoForUnit(s32 kind, s32 currentPlayer, s32 player) {
    extern s32 *gCurrentMap;
    extern u8 gUnitKindCargoCount[];
    void *base = *gCurrentMap;

    if (M2C_FIELD(base, u8 *, MAP_FOG) != 0 || M2C_FIELD(base, u8 *, MAP_WEATHER) == MAP_WEATHER_SNOW) {
        if (!(M2C_FIELD((u8 *)base + player * MAP_PLAYER_STRIDE, u8 *, PLAYER_SIDE_OFF) & SIDE_TEAM_B)) {
            if (gUnitKindCargoCount[kind * UNIT_KIND_STATS_SIZE] != 0) return 1;
        }
    }
    return 0;
}

/* After a player is defeated, give every other player of an army that still has
 * an active player back their turn: clear the defeat turn of any player sharing
 * an active player's army. */
void RestorePlayersOfActiveArmies(void) {
    extern s32 *gCurrentMap;
    s32 IsPlayerActive(s32);
    s32 j, joff, ioff, i;
    u8 *self, *other, *base;

    i = 1;
    ioff = MAP_PLAYER_STRIDE;
    do {
        if (IsPlayerActive(i)) {
            j = 1;
            joff = MAP_PLAYER_STRIDE;
            do {
                if (j != i) {
                    base = (u8 *)*gCurrentMap;
                    other = base + joff;
                    if (other[MAP_PLAYER_STATES + PLAYER_REC_CTRL]) {
                        self = base + ioff;
                        if (other[MAP_PLAYER_STATES + PLAYER_REC_ARMY] == self[MAP_PLAYER_STATES + PLAYER_REC_ARMY]) {
                            *(u16 *)(other + MAP_PLAYER_STATES + PLAYER_REC_DEFEAT_TURN) = 0;
                        }
                    }
                }
                j++;
                joff += MAP_PLAYER_STRIDE;
            } while (j < MAX_PLAYERS);
        }
        i++;
        ioff += MAP_PLAYER_STRIDE;
    } while (i < MAX_PLAYERS);
}

/* Clear the defeat turn (PLAYER_REC_DEFEAT_TURN) of every player that has a
 * controller, so all present players count as still in the battle. */
void ClearPresentPlayerDefeatTurns(void) {
    extern s32 *gCurrentMap;
    s32 IsPlayerPresent(s32);
    s32 player = 1;
    s32 playerOffset = MAP_PLAYER_STRIDE;

    do {
        if (IsPlayerPresent(player) != 0) {
            M2C_FIELD(*gCurrentMap + playerOffset, u16 *, MAP_PLAYER_STATES + PLAYER_REC_DEFEAT_TURN) = 0;
        }
        player++;
        playerOffset += MAP_PLAYER_STRIDE;
    } while (player < MAX_PLAYERS);
}

/* Whether a player has been routed by losing its units: 1 when the player is not
 * active, or when it has no units left while either it still owns units in its
 * per-kind counts or none of the marked unit kinds are left on the field. */
s32 IsPlayerRouted(M2C_UNK player) {
 s32 PlayerHasNoUnits(M2C_UNK); s32 func_020d2a6c(M2C_UNK); s32 CountPlayerUnitsBuilt(M2C_UNK);
 if (!IsPlayerActive()) return 1;
 if (PlayerHasNoUnits(player)) {
  if (CountPlayerUnitsBuilt(player)) return 1;
  if (func_020d2a6c(player)) return 1;
 }
 return 0;
}

/* Whether `player` has no units left on the map: 1 when every record of the
 * player's unit group (ids base+1 .. base+MAP_UNIT_GROUP_SCAN) has kind 0, 0 as
 * soon as one slot holds a unit. */
s32 PlayerHasNoUnits(s32 player) {
    extern u16 gPlayerUnitIdBase[];
    extern s32 *gCurrentMap;
    s32 end;
    s32 i;

    i = gPlayerUnitIdBase[player] + 1;
    end = gPlayerUnitIdBase[player] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        u8 *slot = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            if (((u32)(*slot << 26) >> 26) != 0) {
                return 0;
            }
            i++;
            slot += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    return 1;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_020d2a6c(s32 arg0) {
extern s32 *gCurrentMap;extern s8 gProductionSiteTerrain[];
s32 y=0;u8 *dims; s32 x,width;u8 *p;s32 byte;u8 *base=(u8*)*gCurrentMap; dims=base+0x5100;
if(y<M2C_FIELD(dims,u16 *,0x46)){
width=M2C_FIELD(dims,u16 *,0x44);{s32 zero=0;
do {
x=zero;
if(x<width){
p=base+M2C_FIELD(base+(y<<1),u16 *,0x3758);
do {
byte=M2C_FIELD(p,u8 *,0x1420);
if(arg0==((byte&0xe0)>>5) && gProductionSiteTerrain[byte&31]!=0)return 0;
x++;p++;
}while(x<width);
}
y++;
}while(y<M2C_FIELD(base,u16 *,0x5146));
}
}return 1;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
/* Pay `cost` out of a player's funds: count it in the human player's battle
 * records, subtract it from the player's funds and add it to the cumulative
 * funds-spent stat (capped at PLAYER_FUNDS_SPENT_MAX). */
void PayPlayerFunds(s32 player,s32 cost) {
extern s32 *gCurrentMap; s32 IsPlayerHuman(s32); void AddRecordFunds(s32,s32);
if(IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))AddRecordFunds(11,cost);
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE))-=cost;
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)+=cost;
if(*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)>PLAYER_FUNDS_SPENT_MAX)
*((s32 *)((u8 *)*gCurrentMap+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE)+1)=PLAYER_FUNDS_SPENT_MAX;
}

/* Add `amount` to `player`'s funds, saturating at PLAYER_FUNDS_MAX. */
void AddPlayerFunds(s32 player, s32 amount) {
    extern s32 *gCurrentMap;
    s32 off;
    s32 *base;
    s32 *funds;

    off = player * MAP_PLAYER_STRIDE;
    base = *gCurrentMap;
    funds = (s32 *)((u8 *)base + PLAYER_FUNDS_OFF + off);
    *funds += amount;
    base = *gCurrentMap;
    funds = (s32 *)((u8 *)base + PLAYER_FUNDS_OFF + off);
    if (*funds > PLAYER_FUNDS_MAX) {
        *funds = PLAYER_FUNDS_MAX;
    }
}

#pragma push
#pragma opt_propagation off
/* Index of `player`'s CO-zone bonus record in the power state it is in now: the
 * player's army id and whether its CO power is active, as GetCoZoneBonusIndex
 * takes them. */
s32 GetPlayerCoZoneBonusIndex(s32 player) {
    extern s32 *gCurrentMap;
    s32 GetCoZoneBonusIndex(s32, s32);
    PlayerRecordSprite *rec;

    rec = (PlayerRecordSprite *)(*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE);
    return GetCoZoneBonusIndex(rec->sprite.armyId, rec->sprite.powerActive);
}
#pragma pop
/* Returns how many of a player's CO power meters are fully charged: 0 when CO
 * powers are disabled, the player has no CO power, or the meter is not full; 1
 * when the single CO power is ready; 2 when the dual power is ready too. */
s32 GetCoPowerMeterLevel(s32 player) {
    extern M2C_UNK gMapData;
    s32 GetPlayerArmyVariantIfSet(s32);
    s32 GetCoPowerMeterCost(s32, s32);
    s32 GetCoPowerMeterPoints(s32);
    s32 meter;
    s32 level = 0;

    if ((((u32)M2C_FIELD(&gMapData, u16 *, MAPDATA_RULES) << 19) >> 31) == 0) return 0;
    if (GetPlayerArmyVariantIfSet(player)) return 0;
    if (!GetCoPowerMeterCost(player, 2)) return 0;
    meter = GetCoPowerMeterPoints(player);
    if (meter >= GetCoPowerMeterCost(player, 1)) level++;
    meter = GetCoPowerMeterPoints(player);
    if (meter >= GetCoPowerMeterCost(player, 2)) level++;
    return level;
}

/* The move range the player's CO zone grants their units: the base move range of
   the player's commander plus the number of charged CO power meters. */
s32 GetPlayerCoZoneMoveRange(s32 player) {
    M2C_UNK GetCommanderMoveRange(s32, s32);
    s32 commander;

    commander = GetPlayerCoZoneBonusIndex(player);
    return GetCommanderMoveRange(commander, GetCoPowerMeterLevel(player));
}

s32 GetUnitBuildCost(arg0, arg1)
    u16 arg0;
    s32 arg1;
{
    s32 GetUnitKindBuildCost(s32);
    s32 Divide(s32, s32);
    s32 t;

    t = GetUnitKindBuildCost(arg1);
    return Divide(t * 0x64, 0x64);
}

s32 GetUnitBuildCostTimes10(void) {
    return GetUnitBuildCost() * 0xA;
}

s32 GetUnitActionCost(void) {
    s32 GetUnitBuildCost();
    return GetUnitBuildCost() * 5;
}

/* Re-enable `player`'s unit selection while it has no unit selected; if one is
 * already selected, leave it alone. */
void EnablePlayerSelectionIfNoneSelected(s32 player) {
    s32 HasPlayerSelectedUnit();
    void EnablePlayerSelection(s32);
    if (HasPlayerSelectedUnit(player) != 0) {
        return;
    }
    EnablePlayerSelection(player);
}

void func_020d2d80(M2C_UNK arg0) {
    M2C_UNK SetPlayerSpriteAuxBits(M2C_UNK, M2C_UNK);
    SetPlayerSpriteAuxBits(arg0, 0);
}

/* Pay `player` its per-turn property income, once the battle has started. */
void PayPlayerIncome(s32 player) {
    extern s32 *gCurrentMap;
    void AddPlayerFunds(s32, s32);
    s32 base = *gCurrentMap;
    s32 turn = M2C_FIELD(base, u16 *, MAP_TURN);

    if (turn <= 0) {
        return;
    }
    AddPlayerFunds(player, M2C_FIELD(base + player * MAP_PLAYER_STRIDE, s32 *, PLAYER_INCOME_OFF));
}

/* Find the first free unit record in `player`'s group of the battle map: the
 * records after the group's base id up to MAP_UNIT_GROUP_SCAN, whose kind byte
 * is 0.  Returns the record, or 0 when the group has no free record left. */
s32 FindFreeUnitRecord(s32 player) {
    extern u16 gPlayerUnitIdBase[];
    extern s32 *gCurrentMap;
    s32 val;
    s32 end;
    s32 i;
    u8 *base;
    u8 *p;

    val = gPlayerUnitIdBase[player];
    i = val + 1;
    end = val + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        base = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS;
        p = base + i * MAP_UNIT_STRIDE;
        do {
            if (((u32)(*p << 26) >> 26) == 0) {
                return (s32)(base + i * MAP_UNIT_STRIDE);
            }
            i++;
            p += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    return 0;
}

#pragma opt_common_subs on
void *func_020d2e3c(u16 arg0) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
register s32 start;
u32 teamOffset;
s32 *map;
u32 offset;
u8 *base;
u32 team;
s16 *current;
u16 x;
SelectionUnit *units;
map=gCurrentMap;
base=(u8 *)*map;
team=gPlayerUnitIdBase[arg0];
start=*(s16 *)(base+0x52c0)+1;
current=(s16 *)(base+0x52c0);
x=start;
if(x<51) {
teamOffset=team*14;
units=(SelectionUnit *)(base+0x59a4);
do {
offset=(x+team)*14;
if (((SelectionKind *)((u8 *)units+offset))->kind &&
!(M2C_FIELD((u8 *)((u32)base+teamOffset)+x*14,u16 *,0x59a8)&1)) {
*current=x;
base=(u8 *)*gCurrentMap;
current=(s16 *)(base+0x52c0);
if(*(s16 *)(base+0x52c0)>=50) *current=0;
return (u8 *)*gCurrentMap+0x59a4+offset;
}
} while(++x<51);
}
x=1;
if(start>1) {
base=(u8 *)*map;
units=(SelectionUnit *)(base+0x59a4);
do {
offset=(x+team)*14;
if (((SelectionKind *)((u8 *)units+offset))->kind &&
!(M2C_FIELD(base+team*14+x*14,u16 *,0x59a8)&1)) {
*current=x;
base=(u8 *)*gCurrentMap;
current=(s16 *)(base+0x52c0);
if(*(s16 *)(base+0x52c0)>=50) *current=0;
return (u8 *)*gCurrentMap+0x59a4+offset;
}
} while (++x < *(s16 *)(base+0x52c0)+1);
}
return 0;
}
#pragma opt_common_subs reset
/* Number of units the given player has alive, from its player record. */
u8 GetPlayerUnitCount(s32 player) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(((player * MAP_PLAYER_STRIDE) + *gCurrentMap), u8 *, PLAYER_UNIT_COUNT_OFF);
}

/* How many units of kind `unitKind` player `player` has built so far (the
 * per-kind tallies at PLAYER_REC_UNITS_BUILT, which the results screen shows
 * instead of the loss tallies). */
u8 GetPlayerUnitKindBuiltCount(s32 player, s32 unitKind) {
    extern s32 *gCurrentMap;
    u8 *p = (u8 *)(player * MAP_PLAYER_STRIDE + *gCurrentMap);
    p += unitKind;
    return p[MAP_PLAYER_STATES + PLAYER_REC_UNITS_BUILT];
}

/* Sum the player's per-kind units-built tallies across all unit kinds. */
s32 CountPlayerUnitsBuilt(s32 player) {
    extern s32 *gCurrentMap;
    s32 unitKind;
    s32 totalBuilt;
    u8 *playerRecord;

    totalBuilt = 0;
    unitKind = 0;
    playerRecord = (u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE;
    do {
        totalBuilt += playerRecord[MAP_PLAYER_STATES + PLAYER_REC_UNITS_BUILT];
        playerRecord++;
        unitKind++;
    } while (unitKind < PLAYER_REC_UNIT_KIND_COUNT);
    return totalBuilt;
}

/* How many of player `player`'s units of kind `unitKind` have been destroyed
 * (the per-kind tallies at PLAYER_REC_UNITS_LOST). */
u8 GetPlayerUnitKindLossCount(s32 player, s32 unitKind) {
    extern s32 *gCurrentMap;
    u8 *p = (u8 *) (player * MAP_PLAYER_STRIDE + *gCurrentMap);
    p += unitKind;
    return p[MAP_PLAYER_STATES + PLAYER_REC_UNITS_LOST];
}

/* Sum the player's destroyed-unit tallies across all unit kinds. */
s32 CountPlayerUnitsLost(s32 player) {
    extern s32 *gCurrentMap;
    s32 unitKind;
    s32 totalLost;
    u8 *playerRecord;

    totalLost = 0;
    playerRecord = (u8 *)(player * MAP_PLAYER_STRIDE + *gCurrentMap);
    for (unitKind = 0; unitKind < PLAYER_REC_UNIT_KIND_COUNT; unitKind++, playerRecord++) {
        totalLost += M2C_FIELD(playerRecord, u8 *, MAP_PLAYER_STATES + PLAYER_REC_UNITS_LOST);
    }
    return totalLost;
}

/* Bump `player`'s live unit count, saturating at 255. */
void IncrementPlayerUnitCount(s32 player) {
extern s32 *gCurrentMap;
u8 *p = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
if ((u32)p[PLAYER_REC_UNIT_COUNT] < 255) p[PLAYER_REC_UNIT_COUNT]++;
}

/* Drop `player`'s live unit count, stopping at 0; returns the new count. */
s32 DecrementPlayerUnitCount(s32 player) {
extern s32 *gCurrentMap;
u8 *p = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
s32 count = p[PLAYER_REC_UNIT_COUNT];
if (count != 0) { count--; p[PLAYER_REC_UNIT_COUNT] = count; }
return count;
}

/* Add a newly created unit of `kind` to `player`'s tallies: bump the player's
 * live unit count and the per-kind built count. */
void AddPlayerUnitKind(s32 player, s32 kind) {
    extern s32 *gCurrentMap;
    u8 *p;

    IncrementPlayerUnitCount(player);
    p = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    p += PLAYER_REC_UNITS_BUILT;
    if (p[kind] != 255) p[kind]++;
}

/* Record that `player` has lost a unit of `kind`: drop the player's live unit
 * count and bump the per-kind loss tally (the counterpart of AddPlayerUnitKind,
 * called from RemoveMapUnit when a unit is destroyed rather than withdrawn). */
void AddPlayerUnitLost(s32 player, s32 kind) {
    extern s32 *gCurrentMap;
    u8 *p;

    DecrementPlayerUnitCount(player);
    p = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    p += PLAYER_REC_UNITS_LOST;
    if (p[kind] != 255) p[kind]++;
}

void func_020d31e4(void) {
    M2C_UNK DecrementPlayerUnitCount();
    DecrementPlayerUnitCount();
}

/* Set whether `player` gave up: the AI resigned, or a team-mate was defeated
 * first (PLAYER_REC_GAVE_UP of the player record). */
void SetPlayerGaveUp(s32 player, u8 gaveUp) {
    extern s32 *gCurrentMap;
    M2C_FIELD(player * MAP_PLAYER_STRIDE + *gCurrentMap, u8 *, MAP_PLAYER_STATES + PLAYER_REC_GAVE_UP) = gaveUp;
}

/* Whether `player` has given up (its record's PLAYER_REC_GAVE_UP flag is set). */
u8 HasPlayerGivenUp(s32 player) {
    extern s32 *gCurrentMap;
    return ((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE)[MAP_PLAYER_STATES + PLAYER_REC_GAVE_UP] != 0;
}

/* Whether `player` is still in the battle but has given up. */
u8 HasActivePlayerGivenUp(s32 player) {
    u8 givenUp;

    if (IsPlayerActive(player) == 0) {
        return 0U;
    }
    if (HasPlayerGivenUp(player) != 0) {
        givenUp = 1;
    } else {
        givenUp = 0;
    }
    return givenUp;
}

/* Set whether `player` is lost: its HQ was captured (PLAYER_REC_LOST of the
 * player record). */
void SetPlayerLost(s32 player, u8 lost) {
    extern s32 *gCurrentMap;
    M2C_FIELD(player * MAP_PLAYER_STRIDE + *gCurrentMap, u8 *, MAP_PLAYER_STATES + PLAYER_REC_LOST) = lost;
}

/* Whether the player's HQ has been captured: its record's lost flag is set. */
u8 HasPlayerLost(s32 player) {
    extern s32 *gCurrentMap;
    u8 *record = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;

    return record[PLAYER_REC_LOST] != 0;
}

/* Return whether the player remains undefeated under the map's HQ-loss rule. */
u8 IsPlayerHqIntact(s32 player) {
    extern s32 *gCurrentMap;
    s32 IsPlayerActive(s32);
    u8 HasPlayerLost(s32);
    u8 result;

    if (!(((u8 *)*gCurrentMap)[MAP_BATTLE_RULES] & MAP_RULE_DEFEAT_BY_HQ)) return 1;
    if (IsPlayerActive(player) == 0) return 0;
    if (HasPlayerLost(player) == 0) result = 1;
    else result = 0;
    return result;
}

/* Return whether the player is still fighting under the map's unit-loss
 * (rout) rule; without that rule, every player always is. */
u8 IsPlayerStillFighting(s32 player) {
    extern s32 *gCurrentMap;
    u8 result;

    if (!(((u8 *)*gCurrentMap)[MAP_BATTLE_RULES] & MAP_RULE_DEFEAT_BY_ROUT)) return 1;
    if (IsPlayerRouted(player) == 0) result = 1; else result = 0;
    return result;
}

/* Whether a human player `player` is still fighting: a non-human player always
 * is, and a human one is unless the battle rules make the unit-loss defeat apply
 * to humans (bit 0x10 of MAP_BATTLE_RULES) and their army has been routed. */
u8 IsHumanPlayerStillFighting(s32 player){
extern s32 *gCurrentMap; s32 IsPlayerHuman(s32); u8 result;
if(IsPlayerHuman(player)==0)return 1;
if(!(((u8 *)*gCurrentMap)[MAP_BATTLE_RULES]&16))return 1;
if(IsPlayerRouted(player)==0)result=1;else result=0;
return result;
}

void func_020d33c4(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 0;
}

void EnableBattleTurnTimer(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 1;
}

void DisableBattleTurnTimer(void) {
    extern M2C_UNK gMapData;
    M2C_FIELD(&gMapData, s32 *, 8) = 0;
}

/* Adds one frame to the current player's accumulated battle time while the
 * battle's turn timer is running and the player can act: pausing for a menu or
 * touch lock, or while a battle effect plays, does not count.  The counter
 * saturates instead of wrapping. */
void UpdatePlayerBattleTime(void) {
    extern M2C_UNK gMapData; extern s32 *gCurrentMap;
    s32 IsTouchInputDisabled(void); s32 IsBattleEffectActive(void); void IncrementCounter(void *);
    u8 *map; s32 rec;
    if (M2C_FIELD(&gMapData, u32 *, MAPDATA_TURN_TIMER) == 0) return;
    if (IsTouchInputDisabled() != 0) return;
    if (IsBattleEffectActive() != 0) return;
    map = (u8 *)*gCurrentMap;
    rec = (s32)map + MAP_PLAYER_STATES + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE;
    IncrementCounter((u8 *)rec + PLAYER_REC_TOTAL_TIME);
}

