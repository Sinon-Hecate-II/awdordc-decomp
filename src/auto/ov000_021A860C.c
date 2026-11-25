/* 31 functions from 0x021A860C to 0x021A947C (ov000), found by ds-decomp. */
#include "common.h"
extern s8 *data_ov000_021b5c54[];

#include "ov000_unit_entry.h"
#include "battle_map.h"
#include "ov000_ai.h"

#pragma pool_constants off
s32 EnemyHasSeaUnit(void){
s32 func_020d1938(s32);s32 func_020d273c(u16,s32);extern void **gCurrentMap;extern u16 data_ov000_021aeef4[];extern u8 data_ov000_021b5bfc[];
s32 p=1,i,end;
while(p<5){
if(func_020d1938(p) && !func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)){
u16 start=data_ov000_021aeef4[p];i=start+1;end=start+0x33;
while(i<end){
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 kind=(u32)(entry->unk0 & 0x3f);
if(kind && (data_ov000_021b5bfc[kind*112+0x13]&16))return 1;
i++;}} p++;}
return 0;}
#pragma pool_constants reset
/* Whether the current player's unit block already holds a unit of the AI's
 * counter kind that still has at least half its health. */
s32 PlayerHasHealthyCounterUnit(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 i;

void *base = *gCurrentMap;
u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];
for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
BattleMapUnitHead *entry = &((BattleMapUnitHead *)((u8 *)base + MAP_UNIT_RECORDS))[i];
u32 type = entry->kind;
if (type != 0 && type == AI_COUNTER_UNIT_KIND && entry->health >= AI_COUNTER_UNIT_MIN_HEALTH) { return 1; }
}
return 0;
}

/* Count the current player's units of the given kind, whatever AI state they
 * are in (units busy with an action included). */
s32 CountPlayerUnitsOfKindTotal(s32 kind) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 count = 0;
s32 i;
void *base = *gCurrentMap;
u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];
for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
BattleMapUnitHead *entry = &((BattleMapUnitHead *)((u8 *)base + MAP_UNIT_RECORDS))[i];
u32 type = entry->kind;
if (type != 0 && type == kind) { count += 1; }
}
return count;
}

/* How many of the current player's units of `kind` have an AI action state
 * other than `aiState`: the AI asks this to find a unit of the kind that is
 * still free (the build code passes 5, the step a freshly built unit waits in). */
s32 CountPlayerUnitsOfKindNotInAiState(s32 kind, s32 aiState) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count = 0;
    s32 i;
    void *base = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER)];
    for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        BattleMapUnitHead *entry = &((BattleMapUnitHead *)((u8 *)base + MAP_UNIT_RECORDS))[i];
        u32 type = entry->kind;
        if (type != 0 && type == kind && entry->aiState != aiState) { count += 1; }
    }
    return count;
}

/* How many units the current player has of one kind that are not busy with an
 * action (IsMidActionStep): the AI's "do I still have a unit of kind X free?". */
s32 CountPlayerUnitsOfKind(s32 kind) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
u8 IsMidActionStep(s32);
s32 count=0,i;
void *base=*gCurrentMap;
/* the player's units are the ids after its base id up to the per-player limit */
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_LIMIT+1;i++){
BattleMapUnitHead *unit=&((BattleMapUnitHead *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[i];
u32 unitKind=unit->kind;
if(unitKind!=0&&unitKind==kind&&IsMidActionStep(unit->aiState)==0)count++;
}
return count;
}

/* True while a unit is in an AI step that carries out its chosen action, i.e.
 * the unit is busy with the attack or the capture it started. */
u8 IsMidActionStep(s32 aiStep) {
    u8 var_r0;

    if (aiStep == AI_STEP_ATTACK) {
        return 1U;
    }
    if (aiStep == AI_STEP_CAPTURE) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* How far the AI's unit can still travel this turn: its remaining fuel divided by
 * the player's movement fuel rate, capped by the unit kind's movement range. */
s32 GetAiUnitMoveRange(BattleMapUnitHead *a) {
    extern void **gCurrentMap;
    s32 GetPlayerFuelRate(s32);
    s32 Divide(s32, s32);
    s32 GetUnitMovement(void *);
    s32 range = Divide(a->fuel, GetPlayerFuelRate(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)));
    if (GetUnitMovement(a) <= range) range = GetUnitMovement(a);
    return range;
}

/* Distance between two map cells, counted in grid steps along x plus grid
 * steps along y (the map's four-way distance). */
s32 ManhattanDistance(s32 x1, s32 y1, s32 x2, s32 y2) {
    s32 total = 0;
    if (x1 - x2 > 0) total += x1 - x2; else total += x2 - x1;
    if (y1 - y2 > 0) total += y1 - y2; else total += y2 - y1;
    return total;
}

s32 func_ov000_021a8a38(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_ip;
    s32 var_r0;
    s32 var_r2;

    var_ip = arg0 - arg2;
    if (var_ip <= 0) {
        var_ip = arg2 - arg0;
    }
    var_r2 = arg1 - arg3;
    if (var_r2 <= 0) {
        var_r2 = arg3 - arg1;
    }
    var_r0 = var_ip - var_r2;
    if (var_r0 <= 0) {
        var_r0 = var_r2 - var_ip;
    }
    return var_r0;
}

s32 GetUnitCaptureRateAtOwnTile(void *arg0) {
    M2C_UNK GetUnitCaptureRate(void *, u8, u8);
    GetUnitCaptureRate(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

s32 GetUnitCaptureRateHere(void *arg0) {
    M2C_UNK GetUnitCaptureRate(void *, u8, u8);
    GetUnitCaptureRate(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

/* Whether `unit` finishes capturing the property it stands on this turn: it must
 * already have capture points, and those plus the capture rate at its tile must
 * reach MAP_UNIT_CAPTURE_COMPLETE. */
u8 WillCaptureCompleteThisTurn(void *unit) {
    u8 result;

    if (!((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27)) return 0;
    if (GetUnitCaptureRateHere(unit) + (s32)((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27) >= MAP_UNIT_CAPTURE_COMPLETE) result = 1;
    else result = 0;
    return result;
}

/* Whether the unit finishes capturing the property it stands on this turn: its
 * capture points plus the capture rate at its tile reach MAP_UNIT_CAPTURE_COMPLETE.
 * A unit with no capture progress is rejected first, unless it belongs to the
 * map's recorded current-player unit block (MAP_CURSOR_OWNER). */
s32 WillFinishCaptureThisTurn(void *unit) {
    extern void **gCurrentMap;
    s32 owner;

    if (unit) {
        if (!unit) owner = 0;
        else owner = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        owner = (owner >> 6) + 1;
    } else owner = 0;
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_CURSOR_OWNER) != owner) {
        if (!((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27)) return 0;
    }
    return GetUnitCaptureRateAtOwnTile(unit) + (s32)((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27) >= MAP_UNIT_CAPTURE_COMPLETE;
}

/* Turns left for `unit` to capture the property it stands on: the unit's HP (the
 * low seven bits of its MAP_UNIT_CAPTURE word) must be nonzero, then its capture
 * points are advanced by its capture rate each turn until they reach
 * MAP_UNIT_CAPTURE_COMPLETE. */
s32 GetCaptureTurnsLeft(void *unit){s32 Divide(s32,s32);u32 health;s32 rate,turns,points;health=(u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_CAPTURE)<<25)>>25;if(!health)rate=0;else rate=Divide(health-1,10)+1;turns=0;points=(u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_CAPTURE)<<16)>>27;if(rate<=0)return MAP_UNIT_CAPTURE_COMPLETE;rate=GetUnitCaptureRateAtOwnTile(unit);while(points<MAP_UNIT_CAPTURE_COMPLETE){points+=rate;turns++;}return turns;}

#pragma opt_strength_reduction off
s32 func_ov000_021a8be8(s32 x,s32 y,s32 radius){
extern void **gCurrentMap;
s32 IsUnitOnCurrentTeam(s32);
s32 IsUnitVisibleAtCell(u16,s32,s16,s16);
s32 IsUnitInSight(u16);
s32 i; s32 right; s32 ny; s32 j; s32 dy; s32 left; s32 top; s32 bottom; s32 d;void *base;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;
right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
if(y+radius<bottom)bottom=y+radius;
j=top;for(;j<=bottom;j++)for(i=left;i<=right;i++){
d=0;if(x-i>0)d+=x-i;else d+=i-x;dy=y-j;ny=j-y;if(dy>0)d+=dy;else d+=ny;
if(d>=0&&d<=radius){base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(!d)continue;
if(IsUnitOnCurrentTeam(d)==1)continue;
if(!IsUnitVisibleAtCell(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1,(s16)i,(s16)j))continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(IsUnitInSight(d))return 1;
}}
return 0;
}
#pragma opt_strength_reduction reset
s32 func_ov000_021a8d7c(s32 x,s32 y,s32 radius){
extern void **gCurrentMap;u8 IsCurrentPlayerUnit(s32);
s32 i,j,right,left,top,bottom,d,dy,negDy;void *base;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;
right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
if(y+radius<bottom)bottom=y+radius;
j=top;
if(j<=bottom)do {
i=left;
if(i<=right){dy=y-j;negDy=j-y;do {
d=0;if(x-i>0)d+=x-i;else d+=i-x;if(dy>0)d+=dy;else d+=negDy;
if(d>=0&&d<=radius){base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(d&&IsCurrentPlayerUnit(d)!=1)return 1;
}
i++;
}while(i<=right);}
j++;
}while(j<=bottom);
return 0;
}

s32 func_ov000_021a8eb0(s32 a,s32 b,s32 c){
extern void **gCurrentMap;
s32 minx=a-c,x,dy1,dy2,y,maxx,maxy,d;u8 *p;u32 v;
if(minx<0)minx=0;
y=b-c;if(y<0)y=0;
maxx=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(a+c<maxx)maxx=a+c;
maxy=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(b+c<maxy)maxy=b+c;
if (y<=maxy) do {
x=minx;
if (x<=maxx) {
dy1=b-y; dy2=y-b;
do {
d=0;if(a-x>0)d+=a-x;else d+=x-a;
if(dy1>0)d+=dy1;else d+=dy2;
if(d>=0&&d<=c){
p=*gCurrentMap;
v=M2C_FIELD((u8 *)((u32)x+(u32)(p+M2C_FIELD(p+((u32)y<<1),u16 *,0x3758))),u8 *,0x1420);
if((v&31)==17&&M2C_FIELD(p,u16 *,0x52a6)==(v&224))return 1;
}
x++;
} while(x<=maxx);
}
} while (++y<=maxy);
return 0;
}

/* Whether a unit id (a unit's slot index) belongs to the current player's unit
 * group: its owner-group bits match the base id the map keeps at
 * MAP_UNIT_GROUP_BASE. */
u8 IsCurrentPlayerUnit(s32 unitId) {
    extern void **gCurrentMap;
    u8 var_r0;

    if ((unitId & MAP_UNIT_ID_OWNER_MASK) == M2C_FIELD(*gCurrentMap, u16 *, MAP_UNIT_GROUP_BASE)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsPropertyTerrain(s32 arg0) {
    extern s8 gTerrainIsProperty[];
    u8 var_r0;
    if (gTerrainIsProperty[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Whether terrain byte `terrain` is a property a unit can capture: a property
 * terrain kind other than the missile silo, which is never captured. */
u8 IsCapturablePropertyTerrain(s32 terrain) {
    extern s8 gTerrainIsProperty[];
    s32 kind = terrain & MAP_TERRAIN_KIND_MASK;
    u8 capturable;

    if (kind == MAP_TERRAIN_SILO) return 0;
    if (gTerrainIsProperty[kind]) capturable = 1; else capturable = 0;
    return capturable;
}

/* Whether terrain kind `terrain` is passable for a unit of kind `unitKind`: look
 * up the unit kind's movement type, then that type's row in the army's movement-
 * cost table, and require a positive cost. */
u8 IsTerrainPassableForUnitKind(s32 unitKind, s32 terrain) {
    extern u8 gMovementTypeTable[];
    extern M2C_UNK gMovementCostTable;
    u32 row = gMovementTypeTable[unitKind * UNIT_KIND_STATS_SIZE];
    s8 *table = M2C_FIELD(&gMovementCostTable, s8 **, ARMY_DATA_MOVE_COSTS) + row * 32;
    u8 passable;
    if (table[terrain & MAP_TERRAIN_KIND_MASK] > 0) passable = 1; else passable = 0;
    return passable;
}

u8 IsUnitProductionTerrain(s32 arg0) {
    extern s8 gUnitProductionTerrain[];
    u8 var_r0;
    if (gUnitProductionTerrain[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Whether the player owning cell (x,y) is from another army than the player
 * that owns unit `unitId`.  The cell's terrain owner (the high 3 bits of its
 * terrain byte) is looked up first; an unowned cell is never another army. */
u8 IsCellOwnedByOtherArmy(s32 unitId, s32 x, s32 y) {
 extern void **gCurrentMap;
 u8 *map = *gCurrentMap;
 u8 owner = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) >> 5;
 u8 other;
 if (!owner) return 0;
 if (M2C_FIELD(map + (((unitId >> 6) + 1) * MAP_PLAYER_STRIDE), u8 *, PLAYER_ARMY_OFF) != M2C_FIELD(map + (owner * MAP_PLAYER_STRIDE), u8 *, PLAYER_ARMY_OFF)) other = 1; else other = 0;
 return other;
}

/* Whether the property on cell (x, y) is owned by the player that owns unit
 * `unitId`: the unit's player number ((unitId >> MAP_UNIT_OWNER_SHIFT) + 1) against
 * the terrain byte's owner bits. */
u8 IsCellOwnedByUnitPlayer(s32 unitId, s32 x, s32 y) {
    extern void **gCurrentMap;
    u8 *map = *gCurrentMap;
    s32 player = (unitId >> MAP_UNIT_OWNER_SHIFT) + 1;
    u8 same;
    if (player == (M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) >> MAP_PROPERTY_TILE_OWNER_SHIFT)) same = 1; else same = 0;
    return same;
}

/* Whether the unit standing on cell (x, y) belongs to player `player`: both are
 * compared by their army (nation) id, so allied players count as the same army.
 * False when the cell is empty. */
u8 IsCellUnitOnSameArmy(s32 player,s32 x,s32 y){
extern void **gCurrentMap;u8 *map=*gCurrentMap;
s32 unitId=M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_UNIT_ID);u8 same;if(!unitId)return 0;
if(M2C_FIELD(map+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_OFF)==M2C_FIELD(map+((unitId>>6)+1)*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_OFF))same=1;else same=0;return same;}

/* True for the terrain kinds of the properties the AI treats as repair and
 * resupply points: headquarters, base, airport, port and communications tower.
 * A city (MAP_TERRAIN_CITY, 0x10) does not count. */
s32 IsRepairPropertyKind(s32 terrain) {
    switch (terrain & MAP_TERRAIN_KIND_MASK) {
    case MAP_TERRAIN_HQ:
    case MAP_TERRAIN_BASE:
    case MAP_TERRAIN_AIRPORT:
    case MAP_TERRAIN_PORT:
    case MAP_TERRAIN_COM_TOWER:
        return 1;
    default:
        return 0;
    }
}

/* Returns 1 when tile (x, y) holds a property the unit could capture: a capturable
   cell owned by another army, and the unit's kind may capture that terrain. */
s32 IsCaptureTargetAt(void *unit,s32 x,s32 y){
extern void **gCurrentMap;s32 IsPropertyOwnedByTeam();
u8 *p=*gCurrentMap;s32 n;
if(IsPropertyTerrain(M2C_FIELD(p+(x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN))==1){
if(!unit)n=0;else n=((s32)unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/14;
if(IsPropertyOwnedByTeam((n>>6)+1,x,y)){
p=*gCurrentMap;
if(M2C_FIELD(data_ov000_021b5c54,s8 **,((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)*UNIT_KIND_STATS_SIZE)[M2C_FIELD(p+(x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK])return 1;
}}return 0;}

/* Whether tile (x, y) is a property the current team holds and a unit of `kind`
 * may use it: the current team must own the property and the kind's per-terrain
 * capture mask must allow the tile's terrain kind. */
u8 IsPropertyAllowedForKind(s32 kind, s32 x, s32 y) {
    extern void **gCurrentMap;
    s32 IsPropertyOwnedByTeam(s32, s32, s32);
    void *map;

    if (!IsPropertyOwnedByTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), x, y)) return 0;
    map = *gCurrentMap;
    return M2C_FIELD(data_ov000_021b5c54, s8 **, kind * UNIT_KIND_STATS_SIZE)[M2C_FIELD((u8 *)map + (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK] != 0;
}

s32 func_ov000_021a93a8(void) {
    return 0;
}

/* Check whether the terrain at (x, y) is excluded for the specified player. */
s32 IsCellTerrainExcludedForPlayer(s32 player, s32 x, s32 y) {
    extern void **gCurrentMap;
    s32 IsTerrainExcludedForPlayer(u8, u8);
    void *map = *gCurrentMap;
    return IsTerrainExcludedForPlayer(player, M2C_FIELD((u8 *)map + (x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN));
}

/* Whether the current team can see tile (x, y): a unit standing there must be in
 * sight, and the tile must be marked in the first team's sight bitmap. */
s32 IsCellVisibleToCurrentTeam(s32 x,s32 y){
extern void **gCurrentMap;s32 IsUnitInSight(u16);void *p=*gCurrentMap;u32 n;
u32 id=M2C_FIELD((u8 *)p+(x+M2C_FIELD((u8 *)p+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_VISIBLE_UNIT);
if(id&&!IsUnitInSight((u16)id))return 0;
p=*gCurrentMap;n=x+M2C_FIELD((u8 *)p+y*2,u16 *,MAP_ROW_OFFSETS);
return (u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,MAP_CELL_BITMAP_TEAM_A)&(1<<(n&7)))!=0;
}

