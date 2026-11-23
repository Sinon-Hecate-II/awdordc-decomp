/* 9 functions from 0x02198848 to 0x02199614 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct Unit98 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 health:7; u16 rest:9; u8 tail[6]; } Unit98;

/* Adds the influence of every unit of `player` that can engage the unit under the
 * cursor: each such unit's threat value is the damage it would deal to that unit,
 * written into the AI influence maps by AddUnitThreatInfluence. */
void AddPlayerThreatInfluence(u8 player) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 value;
    s32 flag;
    s32 i;
    Unit98 *unit;
    s32 bonus;

    flag = 0;
    bonus = 0;
    if (!func_ov000_021973f8(((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind)) {
        return;
    }
    if (GetUnitAttackClass(((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind) == 0) {
        bonus = GetDamageBonus((s32)(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) & 0xff));
    }
    if (*(u8 *)((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) * 140 + 0x67ce) == 1) {
        if (GetUnitAttackClass(((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind) == 0 ||
            GetUnitAttackClass(((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind) == 2) {
            flag = 1;
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = player;
    for (i = gPlayerUnitIdBase[player] + 1; i < gPlayerUnitIdBase[player] + 51; i++) {
        unit = (Unit98 *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * 14);
        if (unit->kind == 0) {
            continue;
        }
        if (unit->flags & 8) {
            s32 m = *gCurrentMap;
            s32 yy = unit->y;
            s32 xx = unit->x;
            s32 idx;
            s32 row = *(u16 *)((u8 *)m + yy * 2 + MAP_ROW_OFFSETS);
            idx = *(u8 *)((u8 *)m + xx + row + 0x508);
            if (!IsCarrierUnitKind(((Unit98 *)((u8 *)m + idx * 14 + MAP_UNIT_RECORDS))->kind)) {
                continue;
            }
        }
        value = GetModifiedDamagePercent(unit->kind, ((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind);
        if (value < 25) {
            continue;
        }
        if (!func_ov000_02197814(M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT), (void *)unit, 0)) {
            continue;
        }
        if (((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->flags & 0x20) {
            if (!GetSubmergedAttackDamage(unit->kind, ((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind, 0)) {
                continue;
            }
        }
        if (unit->kind == 0x16 && !(((u32)unit->tail[3] << 25) >> 31)) {
            if (!IsUnitInSight((u16)i)) {
                continue;
            }
        }
        if (!(((u32)unit->tail[3] << 25) >> 31)) {
            if (!IsUnitVisibleAtCell(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), unit->kind, unit->x, unit->y)) {
                continue;
            }
        }
        value = ApplyAttackBonus(value, ((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->owner, unit->owner);
        value = ApplyCoZoneBonus(value, M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT), (void *)unit);
        value = ApplyHealthBonus(value, (void *)unit, (s32)unit->health);
        {
            register s32 b asm("r3") = IsUnitSelected(M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT)) != 0;
            AddUnitThreatInfluence((void *)unit, value, ((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->kind,
                                (u8)((Unit98 *)M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT))->health, (u8)b, flag, bonus);
        }
    }
}

/* Clear the AI influence maps: both per-cell threat layers and the scoring
 * buffer the AI builds for the map. */
void ClearAiInfluenceMaps(void) {
    M2C_UNK MI_CpuFill8(M2C_UNK *, M2C_UNK, s32);
    M2C_UNK FillMapCellLayer(s32, M2C_UNK);
    extern s32 *gCurrentMap;
    extern M2C_UNK gAiInfluenceMap;

    FillMapCellLayer(*gCurrentMap + MAP_CELL_THREAT_DIRECT, 0);
    FillMapCellLayer(*gCurrentMap + MAP_CELL_THREAT_INDIRECT, 0);
    MI_CpuFill8(&gAiInfluenceMap, 0, MAP_CELL_LAYER_BYTES);
}

/* Build the AI influence maps for the current cursor position: once per pass,
   clear the maps and add the threat of every player hostile to the current one,
   then clear the cell of a carried unit so its transport is not scored. */
void BuildAiInfluenceMaps(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void ClearAiInfluenceMaps(void);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void AddPlayerThreatInfluence(u8);
    extern s32 *gCurrentMap;
    extern void *gAiCommandState;
    extern M2C_UNK gAiInfluenceMap;
    void *command;
    struct { u8 ready : 1; } *flags;   /* +0x07 bit 0: the maps are built for this pass */
    u16 savedActivePlayer;
    s32 player;
    u8 carrierId;
    Unit98 *carrier;
    s32 map;
    s32 *mapRef;
    s32 carrierY;
    s32 carrierX;
    u16 cellRow;
    u16 mapWidth;

    mapRef = *(s32 *volatile *)&gCurrentMap;
    command = gAiCommandState;
    flags = (void *)((u8 *)command + AI_COMMAND_STATE_FLAGS);
    savedActivePlayer = M2C_FIELD(*(volatile s32 *)mapRef, u16 *, MAP_ACTIVE_PLAYER);
    if (flags->ready)
        return;
    flags->ready = 1;
    ClearAiInfluenceMaps();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (player = 1; player < 5; player++) {
        if (IsPlayerActive(player) != 0 &&
            IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) {
            AddPlayerThreatInfluence((u8)player);
        }
    }

    mapRef = gCurrentMap;
    map = *mapRef;
    carrierId = M2C_FIELD(map, u8 *, MAP_CURSOR_CARRIER);
    if (carrierId != 0) {
        carrier = (Unit98 *)((u8 *)map + MAP_UNIT_RECORDS) + carrierId;
        carrierX = carrier->x;
        carrierY = carrier->y;
        cellRow = M2C_FIELD(map + carrierY * 2, u16 *, MAP_ROW_OFFSETS);
        M2C_FIELD(map + (carrierX + cellRow), u8 *, MAP_CELL_THREAT_DIRECT) = 0;
        map = *gCurrentMap;
        cellRow = M2C_FIELD(map + carrierY * 2, u16 *, MAP_ROW_OFFSETS);
        M2C_FIELD(map + (carrierX + cellRow), u8 *, MAP_CELL_THREAT_INDIRECT) = 0;
        mapRef = gCurrentMap;
        mapWidth = M2C_FIELD(*mapRef, u16 *, MAP_WIDTH);
        carrierX += carrierY * mapWidth;   /* the linear cell index in gAiInfluenceMap */
        M2C_FIELD(&gAiInfluenceMap, u8 *, carrierX) = 0;
    }

    M2C_FIELD(*mapRef, u16 *, MAP_ACTIVE_PLAYER) = savedActivePlayer;
}

/* Add the AI influence of one player's units against a kind-14 unit: score the
 * damage each unit could deal and write it into the influence maps. */
void AddThreatAgainstKind14(u8 player) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
s32 i, damage; Unit98 *unit; s32 kind;
if(!func_ov000_021973f8(14))return;
M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=player;
for(i=gPlayerUnitIdBase[player]+1;i<gPlayerUnitIdBase[player]+51;i++){
unit=(Unit98 *)(*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE);
if(!(unit->kind))continue;
if(M2C_FIELD(unit,u16 *,4)&8){
s32 map=*gCurrentMap; s32 y=unit->y; s32 x=unit->x; s32 idx; s32 row=M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS); x=(s32)((u8 *)map+x); row+=x; idx=M2C_FIELD(row,u8 *,MAP_CELL_UNIT_ID);
if(!IsCarrierUnitKind(((Unit98 *)(map+idx*MAP_UNIT_STRIDE+MAP_UNIT_RECORDS))->kind))continue;
}
kind=unit->kind;
if(gUnitKindStats[kind*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_FLAGS]&16)continue;
damage=GetModifiedDamagePercent(kind,14);
if(damage<25)continue;
if(!func_ov000_02197814(M2C_FIELD(*gCurrentMap,s32 *,MAP_CURSOR_UNIT),unit,1))continue;
damage=ApplyAttackBonus(damage,0,unit->owner);
damage=ApplyCoZoneBonus(damage,0,unit);
damage=ApplyHealthBonus(damage,unit,unit->health);
AddUnitThreatInfluence(unit,damage,14,100,0,1,0);
}
}

/* Build the AI influence maps for a hypothetical kind-14 target: clear the maps,
 * refresh the order overlays, then add every player's threat against such a unit
 * for the players hostile to the current one, restoring the active player. */
void BuildThreatMapAgainstKind14(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void AddThreatAgainstKind14(u8);
    extern s32 *gCurrentMap;
    u16 savedPlayer;
    s32 player;
    savedPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER);
    ClearAiInfluenceMaps();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (player = 1; player < MAX_PLAYERS; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) {
            AddThreatAgainstKind14(player);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

#pragma opt_strength_reduction on
/* Threat pass against a hypothetical kind-14 target: for every unit of `player`
 * able to hurt that kind without taking too much counter-damage, add the damage
 * it would deal.  A direct attacker's damage is written onto every cell it can
 * move to (the direct-threat layer); an indirect attacker's goes through
 * AddUnitThreatInfluence. */
void AddMoveRangeThreatAgainstKind14(u8 player) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 func_ov000_021973f8(s32);
s32 GetModifiedDamagePercent(s32,s32);
s32 ApplyAttackBonus(s32,s32,s32);
s32 ApplyCoZoneBonus(s32,s32,void*);
s32 ApplyHealthBonus(s32,void*,s32);
s32 IsCarrierUnitKind(s32);
s32 GetUnitAttackClass(s32);
s32 GetUnitMoveRange(s32,s32);
s32 FloodFillUnitRange(s32,s32,s32,s32,s32);
void MarkAdjacentCells(s32);
s32 GetDamageBonus(s32);
s32 GetUnitDamagePercent(s32,s32);
s32 tileX,tileY,bonus;
s32 unitId,damage;
Unit98 *unit;
u8 *map,*cell;
s32 owner,id,amount;
if(!func_ov000_021973f8(14))return;
bonus=GetDamageBonus(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)&255);
M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=player;
for(unitId=gPlayerUnitIdBase[player]+1;unitId<gPlayerUnitIdBase[player]+MAP_UNIT_GROUP_SCAN;unitId++){
map=(u8 *)*gCurrentMap;
unit=(Unit98 *)(map+MAP_UNIT_RECORDS+unitId*MAP_UNIT_STRIDE);
if(!unit->kind)continue;
if(M2C_FIELD(unit,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED){
s32 unitY=((u8 *)unit)[2];s32 unitX=((u8 *)unit)[1];s32 row=M2C_FIELD(map+unitY*2,u16 *,MAP_ROW_OFFSETS);
id=M2C_FIELD(map+unitX+row,u8 *,MAP_CELL_UNIT_ID);
if(!IsCarrierUnitKind(((Unit98 *)(map+id*MAP_UNIT_STRIDE+MAP_UNIT_RECORDS))->kind))continue;
}
damage=GetModifiedDamagePercent(unit->kind,14);
if(damage<25)continue;
if(GetUnitDamagePercent(14,unit->kind)>=50)continue;
damage=ApplyAttackBonus(damage,0,unit->owner);
damage=ApplyCoZoneBonus(damage,0,unit);
damage=ApplyHealthBonus(damage,unit,unit->health);
if(!GetUnitAttackClass(unit->kind)){
if(bonus==1 && GetUnitDamagePercent(14,unit->kind)>=45)continue;
if(unit){if(!unit)id=0;else id=unit-(Unit98 *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS);owner=(id>>6)+1;}else owner=0;
owner=GetUnitMoveRange(owner,unit->kind);
FloodFillUnitRange(((u8 *)unit)[1],((u8 *)unit)[2],unit->kind,owner,1);
MarkAdjacentCells(111);
for(tileY=0;tileY<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);tileY++){
for(tileX=0;tileX<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);tileX++){
map=(u8 *)*gCurrentMap;
if(((s8 **)(map+MAP_GRID))[tileY][tileX]>=0){
cell=map+tileX+((u16 *)map)[tileY+MAP_ROW_OFFSETS_WORD];
amount=damage+((u8 *)(cell+0x2000))[0x840];
if(amount>=255)amount=255;
M2C_FIELD(cell,u8 *,MAP_CELL_THREAT_DIRECT)=amount;
}
}
}
}else AddUnitThreatInfluence(unit,damage,14,100,0,1,bonus);
}
}

/* Same kind-14 threat pass as BuildThreatMapAgainstKind14, but from the cells
 * each hostile player's units can move to rather than their current cells. */
void BuildMoveRangeThreatMapAgainstKind14(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void AddMoveRangeThreatAgainstKind14(u8);
    extern s32 *gCurrentMap;
    u16 savedPlayer;
    s32 player;
    savedPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER);
    ClearAiInfluenceMaps();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (player = 1; player < MAX_PLAYERS; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) {
            AddMoveRangeThreatAgainstKind14(player);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

/* Add the AI influence of one player's units against a full-health kind-6
 * unit: score the damage each unit could deal and write it into the maps. */
void AddThreatAgainstKind6(u8 player) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 damage;
    s32 bonus;
    s32 i;
    Unit98 *unit;
    s32 kind;

    if (!func_ov000_021973f8(6)) {
        return;
    }
    bonus = GetDamageBonus((u8)M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = player;
    for (i = gPlayerUnitIdBase[player] + 1; i < gPlayerUnitIdBase[player] + 51; i++) {
        unit = (Unit98 *)(*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE);
        if (!unit->kind) {
            continue;
        }
        if (unit->flags & 8) {
            s32 map = *gCurrentMap;
            s32 y = unit->y;
            s32 x = unit->x;
            s32 idx;
            s32 row = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            x = (s32)((u8 *)map + x);
            row += x;
            idx = M2C_FIELD(row, u8 *, MAP_CELL_UNIT_ID);
            if (!IsCarrierUnitKind(((Unit98 *)(map + idx * MAP_UNIT_STRIDE + MAP_UNIT_RECORDS))->kind)) {
                continue;
            }
        }
        kind = unit->kind;
        damage = GetModifiedDamagePercent(kind, 6);
        if (damage < 25) {
            continue;
        }
        if (!GetUnitAttackClass(unit->kind) && GetUnitDamagePercent(6, unit->kind) >= 50) {
            continue;
        }
        damage = ApplyAttackBonus(damage, 0, unit->owner);
        damage = ApplyCoZoneBonus(damage, 0, unit);
        damage = ApplyHealthBonus(damage, unit, unit->health);
        AddUnitThreatInfluence(unit, damage, 6, 100, 0, 0, bonus);
    }
}

/* Build the AI influence maps for a hypothetical kind-6 target: clear the maps,
 * refresh the order overlays, then add every hostile player's threat against such
 * a unit, restoring the map's active player afterwards. */
void BuildThreatMapAgainstKind6(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void AddThreatAgainstKind6(u8);
    extern s32 *gCurrentMap;
    u16 savedPlayer;
    s32 player;
    savedPlayer = M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER);
    ClearAiInfluenceMaps();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (player = 1; player < MAX_PLAYERS; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) {
            AddThreatAgainstKind6(player);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

