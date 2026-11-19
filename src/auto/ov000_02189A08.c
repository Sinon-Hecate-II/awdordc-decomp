/* 12 functions from 0x02189A08 to 0x0218A9AC (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u16 low:14, high:2; } SelectedUnitFlagsA520;

typedef struct {
    u8 unk0 : 6;
    u8 unk0_6 : 2;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6[8];
} UnkStruct_ov000_02189A08;

#pragma opt_strength_reduction off
/* Fallback move choice for the AI's acting unit when it cannot attack: flood-fill
 * its movement range, take the cheapest reachable property tile (kind 19 or 21)
 * that belongs to the other army as the capture target, then rescan the tiles
 * reachable from there and hand the best one to PlanMoveDestination. */
void ChooseCaptureDestination(void) {
    s32 GetPlayerArmyVariant(s32);
    s32 ComputeUnitMoveRange(s32, s32, s32, s32, s32);
    void FloodFillUnitRange(s32, s32, u8, s32, s32);
    void SelectMapLayer(void *);
    s32 func_ov000_021a8eb0(s32, s32, s32);
    s32 IsUnitProductionTerrain(s32);
    void PlanMoveDestination(s32, s32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    extern u8 gUnitKindStats[];

    s32 bestX = -1;
    s32 bestY = -1;
    s32 bestCost = 0x7fff;
    u8 *map = *gCurrentMap;
    s32 army = GetPlayerArmyVariant(M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER));
    s32 moveRange = ComputeUnitMoveRange(M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind,
        M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_ATTACKER), M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER), army, 0);
    BattleMapUnitHead *unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    s32 x, y;
    s32 rowY, columnX;
    s32 candidateCost;
    FloodFillUnitRange(unit->x, unit->y, unit->kind, MAP_GRID_NO_UNIT_MAX, 0);

    for (y = 0; y < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            u8 *current = *gCurrentMap;
            candidateCost = M2C_FIELD(current + y * 4, s8 **, MAP_GRID)[x];
            if (candidateCost >= 0) {
                u16 row = M2C_FIELD(current + y * 2, u16 *, MAP_ROW_OFFSETS);
                u8 terrain = current[x + row + MAP_CELL_TERRAIN];
                s32 kind = terrain & MAP_TERRAIN_KIND_MASK;
                if ((kind == 0x13 || kind == 0x15) &&
                    M2C_FIELD(current, u16 *, MAP_CURRENT_OWNER) == (terrain & MAP_TERRAIN_OWNER_MASK)) {
                    if (func_ov000_021a8eb0(x, y, 5) == 0) candidateCost += 0x100;
                    if (bestCost >= candidateCost) {
                        bestX = x;
                        bestY = y;
                        bestCost = candidateCost;
                    }
                }
            }
        }
    }

    if (bestX == -1) return;
    SelectMapLayer((u8 *)*gCurrentMap + MAP_CELL_SCORE);
    army = GetPlayerArmyVariant(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER));
    FloodFillUnitRange(bestX, bestY, 7, ComputeUnitMoveRange(7,
        M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_ATTACKER), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), army, 0), 0);
    SelectMapLayer((u8 *)*gCurrentMap + MAP_CELL_ORDER);

    candidateCost = 0x7fff;
    for (rowY = 0; rowY < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); rowY++) {
        for (columnX = 0; columnX < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); columnX++) {
            u8 *current = *gCurrentMap;
            s32 cost = M2C_FIELD(current + rowY * 4, s8 **, MAP_GRID)[columnX];
            if (cost >= 0) {
                u16 row = M2C_FIELD(current + rowY * 2, u16 *, MAP_ROW_OFFSETS);
                u8 *cell = current + columnX + row;
                if (M2C_FIELD(cell, s8 *, MAP_CELL_SCORE) >= 0 && *cell == 0) {
                    u8 terrain = cell[MAP_CELL_TERRAIN];
                    if ((terrain & MAP_TERRAIN_KIND_MASK) == 0x13) {
                        BattleMapUnitHead *selected = M2C_FIELD(current, BattleMapUnitHead **, MAP_CURSOR_UNIT);
                        if (gUnitKindStats[selected->kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_FUEL] > selected->fuel + 20) {
                            if (candidateCost >= cost) {
                                bestX = columnX;
                                bestY = rowY;
                                candidateCost = cost;
                            }
                            continue;
                        }
                    }
                    if (IsUnitProductionTerrain(terrain) != 0) {
                        current = *gCurrentMap;
                        row = M2C_FIELD(current + rowY * 2, u16 *, MAP_ROW_OFFSETS);
                        if ((current[columnX + row + MAP_CELL_TERRAIN] & MAP_TERRAIN_KIND_MASK) != 0x13) {
                            cost = moveRange + M2C_FIELD(current + rowY * 4, s8 **, MAP_GRID)[columnX];
                            if (candidateCost >= cost) {
                                bestX = columnX;
                                bestY = rowY;
                                candidateCost = cost;
                            }
                        }
                    }
                }
            }
        }
    }

    if (candidateCost == 0x7fff &&
        M2C_FIELD((u8 *)*gCurrentMap + bestY * 4, s8 **, MAP_GRID)[bestX] <=
            M2C_FIELD(gAiCommandState, u8 *, AI_COMMAND_STATE_MOVE_RANGE)) return;
    PlanMoveDestination(bestX, bestY);
}
#pragma opt_strength_reduction reset
void func_ov000_02189df4(void) {
    M2C_UNK SelectCarriedUnitAction();
    M2C_UNK func_ov000_021895bc();
    extern void **gCurrentMap;
    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) != 0) {
        SelectCarriedUnitAction();
        return;
    }
    func_ov000_021895bc();
}

#pragma push
#pragma opt_strength_reduction off
/* Score the property cells the AI's unit could capture: every reachable cell
 * with property terrain whose owner is not on the unit's team counts 1, except
 * headquarters, which count 30. */
s32 CountCapturableProperties(void){
extern void **gCurrentMap;extern s8 gTerrainIsProperty[];s32 IsTerrainOnUnitTeam(u8,u8);
s32 score=0,x,y;void *base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,MAP_HEIGHT);y++){
for(x=0;x<M2C_FIELD(base,u16 *,MAP_WIDTH);x++){
if(M2C_FIELD(M2C_FIELD(base+(y<<2),s8 **,MAP_GRID),s8 *,x)>=0){
if(gTerrainIsProperty[M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,MAP_ROW_OFFSETS)+(base+x),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK]!=0){
if(IsTerrainOnUnitTeam(M2C_FIELD(base,u8 *,MAP_CURSOR_UNIT_ID),M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,MAP_ROW_OFFSETS)+(base+x),u8 *,MAP_CELL_TERRAIN))==0){
if((M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,MAP_ROW_OFFSETS)+(*gCurrentMap+x),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)==MAP_TERRAIN_HQ)score+=30;else score++;
}}}
base=*gCurrentMap;
}}
return score;
}

#pragma push
#pragma opt_strength_reduction off
/* Scores the property cells the AI could still capture. It walks every map
 * cell that is reachable (movement grid >= 0) and holds a property terrain
 * kind (15..24), not owned by the unit's team. A cell counts when its property
 * record has not been used yet (MAP_PROPERTY_COUNT == 0) or it is an HQ
 * (kind 15). An HQ is worth 30 points, every other property 1. */
s32 CountUnusedCapturableProperties(void) {
    extern void **gCurrentMap;
    extern s8 gTerrainIsProperty[];
    s32 IsTerrainOnUnitTeam(u8, u8);
    s32 score = 0, x, y;
    void *base = *gCurrentMap;

    for (y = 0; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++) {
            if (M2C_FIELD(M2C_FIELD(base + (y << 2), s8 **, MAP_GRID), s8 *, x) >= 0) {
                if (gTerrainIsProperty[M2C_FIELD(M2C_FIELD(base + (y << 1), u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK] != 0) {
                    if (IsTerrainOnUnitTeam(M2C_FIELD(base, u8 *, MAP_CURSOR_UNIT_ID), M2C_FIELD(M2C_FIELD(base + (y << 1), u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, MAP_CELL_TERRAIN)) == 0) {
                        void *b = *gCurrentMap;
                        void *cell = (b + x) + M2C_FIELD(b + (y << 1), u16 *, MAP_ROW_OFFSETS);
                        if (M2C_FIELD(b + M2C_FIELD(cell, s8 *, MAP_CELL_PROPERTY_INDEX) * MAP_PROPERTY_STRIDE, u8 *, MAP_PROPERTY_CELLS + MAP_PROPERTY_COUNT) == 0
                            || (M2C_FIELD(cell, u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) == 15) {
                            if ((M2C_FIELD(cell, u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK) == 15) score += 30;
                            else score++;
                        }
                    }
                }
            }
            base = *gCurrentMap;
        }
    }
    return score;
}
#pragma pop

#pragma pop
/* Counts a player's deployed foot units: unloaded infantry/mech records in the
 * player's unit-id group that stand on a cell the movement grid marks passable. */
s32 CountPlayerFootUnits(u8 player) {
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    u16 start = gPlayerUnitIdBase[player];

    for (i = start + 1; i < gPlayerUnitIdBase[player] + MAP_UNIT_GROUP_SCAN; i++) {
        BattleMapUnitHead *entry = &((BattleMapUnitHead *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS))[i];
        u32 kind = entry->kind;
        if (kind != 0 && !(entry->flags & UNIT_FLAG_LOADED) && IsFootUnitKind(kind) != 0 && ((s8 **)((u8 *)*gCurrentMap + MAP_GRID))[entry->y][entry->x] != -1) {
            count += 1;
        }
    }
    return count;
}

/* Counts units of an enemy player whose map position is visible (-1 would mark blocked) and whose unit info has nonzero field at +0xC and bit0-2 of +0x13. */
s32 CountPlayerAttackUnits(u8 arg0) {
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 count = 0;
    s32 i;
    u16 start = gPlayerUnitIdBase[arg0];

    for (i = start + 1; i < gPlayerUnitIdBase[arg0] + 0x33; i++) {
        UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + 0x59A4))[i];
        u32 type = entry->unk0;
        if (type != 0 && !(entry->unk4 & 8) && IsFootUnitKind(type) == 0) {
            u8 *info = gUnitKindStats + entry->unk0 * 0x70;
            if ((info[0x13] & 7) && info[0xc] != 0 && ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[entry->unk2][entry->unk1] != -1) {
                count++;
            }
        }
    }
    return count;
}

s32 CountActiveTeamFootUnits(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 CountPlayerFootUnits(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && IsPlayerActive(i) != 0) {
            count += CountPlayerFootUnits(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

s32 CountTeamAttackUnits(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 CountPlayerAttackUnits(u8);
    extern void **gCurrentMap;
    s32 count = 0;
    s32 i;

    i = 1;
    do {
        if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) != 0 && IsPlayerActive(i) != 0) {
            count += CountPlayerAttackUnits(i);
        }
        i += 1;
    } while (i < 5);
    return count;
}

/* Counts the units of the other army that the AI can attack: an active player
   whose units are not on the current player's team, of a kind that can attack,
   not loaded in a transport and standing on a passable grid cell. */
s32 CountAiAttackTargetUnits(void){
s32 IsPlayerActive(s32);s32 IsSameTeam(u16,s32);
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 gUnitKindStats[];
s32 count=0,p,end,i;
for(p=1;p<5;p++){
if(IsPlayerActive(p)!=0 && IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),p)!=1){
u16 start=gPlayerUnitIdBase[p];
i=start+1;end=start+0x33;
for(;i<end;i++){
UnkStruct_ov000_02189A08 *entry=&((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[i];
u32 type=entry->unk0;
if(type!=0 && !(entry->unk4&UNIT_FLAG_LOADED) && (gUnitKindStats[type*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_FLAGS]&7) && ((s8 **)((u8 *)*gCurrentMap+MAP_GRID))[entry->unk2][entry->unk1]!=-1)count++;
}}}return count;}

/* Whether some active player has a movable unit the AI cares about: an enemy
 * non-foot unit (an attack target) or a friendly foot unit (a capture unit). */
s32 AiHasAttackTargetOrFootUnit(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 p, i;

    for (p = 1; p < 5; p++) {
        if (IsPlayerActive(p) != 0) {
            for (i = gPlayerUnitIdBase[p] + 1; i < gPlayerUnitIdBase[p] + 0x33; i++) {
                UnkStruct_ov000_02189A08 *entry = &((UnkStruct_ov000_02189A08 *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS))[i];
                u32 type = entry->unk0;
                if (type != 0 && (gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_FLAGS] & 7) && ((s8 **)((u8 *)*gCurrentMap + MAP_GRID))[entry->unk2][entry->unk1] != -1) {
                    if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), p) == 0) {
                        if (IsFootUnitKind(entry->unk0) == 0) goto success;
                        goto next;
                    } else {
                        if (IsFootUnitKind(entry->unk0) == 0) goto next;
                    }
                success:
                    return 1;
                }
            next:;
            }
        }
    }
    return 0;
}

#pragma opt_propagation off
s32 IsValidMoveCell(s32 x, s32 y) {
    s32 GetUnitAttackClass(s32);
    s32 IsUnitSelected(void *);
    s32 func_ov000_02178e84(s32, s32);
    s32 GetKindAttackClass(s32);
    s32 IsCellOwnedByOtherTeam(s32, s32, s32);
    s32 func_ov000_02178778(s32, s32);
    s32 IsUnitProductionTerrain(s32);
    extern void **gCurrentMap;
    extern u8 gUnitKindFlags[];
    extern u8 data_ov000_021df9bc[];
    extern u8 data_ov000_021dfc4c[];
    extern u8 *gAiUnitTypeTuning;

    if (!GetUnitAttackClass(((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0) && !IsUnitSelected(*(void **)((u8 *)*gCurrentMap+0x52d0))) {
u8 attr=gUnitKindFlags[((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0*0x70];
if(attr&7) {u32 idx=y*(*(u16 *)((u8 *)*gCurrentMap+0x5144))+x;
if((u8)((1<<(idx&7)) & data_ov000_021df9bc[idx>>3])) goto valid;
}
if(attr&0x10) {u32 idx=y*(*(u16 *)((u8 *)*gCurrentMap+0x5144))+x;
if((u8)((1<<(idx&7)) & data_ov000_021dfc4c[idx>>3])) goto valid;
}
}
    {
        s32 cell; u8 *ptr; u8 *map;
        u8 limit;
        u16 rowOffset;
        map=(u8 *)*gCurrentMap; ptr=gAiUnitTypeTuning;
        rowOffset=*(u16 *)(map+y*2+0x3758);
        cell = (s32)(map + (x + rowOffset) + 0x2000);
        limit=ptr[1];
        if (M2C_FIELD(cell,u8 *,0x840) >= limit) {
            return 0;
        }
        if (M2C_FIELD(cell,u8 *,0xd48) >= ptr[2]) {
            return 0;
        }
    }
valid:
    if (!func_ov000_02178e84(x, y)) {
        return 0;
    }
    {
u32 unitKind2=((UnkStruct_ov000_02189A08 *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0;
if(gUnitKindFlags[unitKind2*0x70]!=0x20 && GetKindAttackClass(unitKind2)!=2) {
u8 *m=(u8 *)*gCurrentMap;
u16 rowOffset=*(u16 *)(m+y*2+0x3758);
u8 terrain=(m+(x+rowOffset)+0x1000)[0x420]&0x1f;
if(terrain==0x13 || terrain==0x15) {
if(!IsCellOwnedByOtherTeam(m[0x52d4],x,y))return 0;
}
}
}
    if (func_ov000_02178778(x, y) == 1) {
        return 0;
    }
    if((((SelectedUnitFlagsA520 *)((u8 *)*(void **)((u8 *)*gCurrentMap+0x52d0)+8))->high)==2) {
        u16 rowOffset = *(u16 *)((u8 *)*gCurrentMap + y * 2 + 0x3758);
        u8 finalByte = ((u8 *)*gCurrentMap + (x + rowOffset) + 0x1000)[0x420];
        if (IsUnitProductionTerrain(finalByte) != 0) {
            return 0;
        }
    }
    return 1;
}
#pragma opt_propagation reset
s32 DestinationScore(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_021a8a38(s32, s32, s32, s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 gUnitKindFlags[];
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    s32 val;
    s32 d1;
    u32 type;
    UnkStruct_ov000_02189A08 *entry;
    s32 y;
    u32 x;
    s32 end;
    s32 i;
    s32 bestOther = 0x7FFFFFFF;
    s32 bestVisible = 0x7FFFFFFF;
    s32 savedAttr;
    void *selected;
    void *map;

    map = *gCurrentMap;
    selected = M2C_FIELD(map, void **, 0x52D0);
    savedAttr = gUnitKindFlags[((UnkStruct_ov000_02189A08 *)selected)->unk0 * 0x70];
    if (savedAttr & 0x7) { savedAttr = 0x7; }

    map = *gCurrentMap;
    i = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 1;
    end = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
    if (i < end) {
        x = (s16)arg0;
        y = (s16)arg1;
        do {
            entry = &((UnkStruct_ov000_02189A08 *)((u8 *)map + 0x59A4))[i];
            type = entry->unk0;
            if (type != 0 && entry != (UnkStruct_ov000_02189A08 *)M2C_FIELD(map, void **, 0x52D0) && !(entry->unk4 & 0x8)) {
                u8 *info = gUnitKindStats + type * 0x70;
                u8 attr = info[0x13];
                if ((savedAttr & attr) && !(entry->unk4 & 0x1)) {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestVisible >= val) { bestVisible = val; }
                } else {
                    d1 = ManhattanDistance(x, y, entry->unk1, entry->unk2);
                    val = func_ov000_021a8a38(x, y, entry->unk1, entry->unk2) + (d1 << 8);
                    if (bestOther >= val) { bestOther = val; }
                }
            }
            i += 1;
            map = *gCurrentMap;
            end = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, 0x52A4)] + 0x33;
        } while (i < end);
    }

    if (bestVisible != 0x7FFFFFFF) {
        return bestVisible;
    }
    if (bestOther != 0x7FFFFFFF) {
        return bestOther;
    }
    return func_ov000_021a8a38((s16)arg0, (s16)arg1, (s16)arg2, (s16)arg3);
}

