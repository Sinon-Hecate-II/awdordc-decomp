/* 23 functions from 0x020A5878 to 0x020A67FC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef BattleMapUnitHead Unit5B; /* the battle-map unit record as these routines read it */
extern u8 gUnitKindMaxFuel[], gUnitKindMaxAmmo[];
extern s8 *gUnitKindFuelCost[];
extern u8 gUnitKindFlags[];
extern s16 gPlayerUnitIdBase[];typedef struct { u8 unk0[12]; s32 money; u8 unk10[0x7c]; } UnkStruct_020A6328;

/* Advances the unit-move animation: when a move entry is queued it eases the
 * unit's sub-tile offset toward the next facing, and at the end restores the
 * map cursor to the moving player's position. */
void UpdateUnitMove(void *ctrl) {
s32 IsMapViewScrolling(void);s32 GetFacingOffset(s32);
void PlaySoundAtTile(s32,u8,u8);s32 EaseInterpolate(s32,s32,s32,s32,s32);
s32 IsMapOrderActive(void *);void PanMapViewToTile(u8,u8);void StepMapViewToTile(u8,u8);void Sprite_ResumeAnimation(void *);
extern s32 *gCurrentMap;
s32 startOffset,endOffset,facing,turnCount; u8 *unit; void *map; u8 *player;
if(IsMapViewScrolling())return;
unit=M2C_FIELD(ctrl,u8 **,0x38);
if(unit){
facing=((u32)(M2C_FIELD(unit,u16 *,2)<<16)>>30);
startOffset=GetFacingOffset(facing%3)/256;
facing=((u32)(M2C_FIELD(unit,u16 *,2)<<16)>>30)+1;
endOffset=GetFacingOffset(facing%3)/256;
if(M2C_FIELD(ctrl,s32 *,0x3C)==0){
M2C_FIELD(ctrl,s32 *,0x40)=unit[4];
M2C_FIELD(unit,u16 *,2)=(M2C_FIELD(unit,u16 *,2)&~0x3C0)|0x200;
PlaySoundAtTile(0x10C,unit[0],unit[1]);
}
M2C_FIELD(ctrl,s32 *,0x3C)++;
unit[4]=EaseInterpolate(4,startOffset,endOffset,M2C_FIELD(ctrl,s32 *,0x3C),60);
if(M2C_FIELD(ctrl,s32 *,0x3C)<60)return;
M2C_FIELD(unit,u16 *,2)=(M2C_FIELD(unit,u16 *,2)&~0x3C0)|0x1C0;
unit[4]=M2C_FIELD(ctrl,s32 *,0x40);
endOffset=((u32)(M2C_FIELD(unit,u16 *,2)<<16)>>30)+1;
facing=endOffset%3;
M2C_FIELD(unit,u16 *,2)=(M2C_FIELD(unit,u16 *,2)&~0xC000)|((u32)((u16)facing<<30)>>16);
M2C_FIELD(ctrl,void **,0x38)=0;
return;
}
unit=M2C_FIELD(ctrl,u8 **,0x34);
while(((u32)(M2C_FIELD(unit,u16 *,2)<<22)>>28)!=0){
map=(void *)*gCurrentMap;
if(M2C_FIELD(map,u16 *,0x52A4)==1 && (turnCount=M2C_FIELD(map,u16 *,0x52A2))>1 && ((u32)(M2C_FIELD(unit,u16 *,2)<<22)>>28)==7 && IsMapOrderActive(unit)){
M2C_FIELD(ctrl,void **,0x38)=M2C_FIELD(ctrl,void **,0x34);
M2C_FIELD(ctrl,s32 *,0x3C)=0;
unit=M2C_FIELD(ctrl,u8 **,0x38);
PanMapViewToTile(unit[0],unit[1]);
M2C_FIELD(ctrl,u8 **,0x34)+=8;
M2C_FIELD(ctrl,u8 *,0x44)=1;
return;
}
M2C_FIELD(ctrl,u8 **,0x34)+=8;
unit=M2C_FIELD(ctrl,u8 **,0x34);
}
if(M2C_FIELD(ctrl,u8 *,0x44)){
map=(void *)*gCurrentMap;
player=(u8 *)map+0x67A4+M2C_FIELD(map,u16 *,0x52A4)*140;
StepMapViewToTile(player[0x2D],player[0x2E]);
}
Sprite_ResumeAnimation(ctrl);
}

void func_020a5ac8(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02120608;
    CreateSpriteFromClass(&data_02120608, 7);
}

s32 GetDamageTargetIndex(u32 arg0) {
    s32 var_r1;

    var_r1 = 0;
    switch (arg0) {
    default:
        break;
    case 4:
        var_r1 = 0x1E;
        break;
    case 6:
    case 7:
        var_r1 = 0x1F;
        break;
    case 1:
        var_r1 = 0x1D;
        break;
    }
    return var_r1;
}

/* Spend a unit's turn-start fuel: the per-terrain cost of its kind, five for a
 * submerged submarine, and report when a sea or air kind has just run dry. */
s32 ChargeUnitTurnFuel(BattleMapUnitHead *unit) {
    extern s32 *gCurrentMap;
    s32 IsUnitSubmerged(Unit5B *);
    u8 *map = (u8 *)*gCurrentMap;
    s32 kind = unit->kind;
    s32 terrain = M2C_FIELD(map + (unit->x + M2C_FIELD(map + unit->y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
    s32 cost = (s8)(*(s8 **)((u8 *)gUnitKindFuelCost + kind * UNIT_KIND_STATS_SIZE))[terrain];
    if (!CanUnitSpendTurnFuel((u8 *)unit)) return 0;
    if (IsUnitSubmerged(unit) && unit->kind == UNIT_KIND_SUBMARINE) cost = UNIT_KIND_SUBMARINE_FUEL;
    if (cost < 0) cost = 0;
    {
        u8 fuel = unit->fuel;
        if (fuel <= cost) unit->fuel = 0;
        else unit->fuel = (u8)(fuel - cost);
    }
    if (!unit->fuel && (gUnitKindFlags[unit->kind * UNIT_KIND_STATS_SIZE] & UNIT_KIND_FLAGS_FUEL_CRITICAL)) return 1;
    return 0;
}

/* Whether a unit with its current fuel can take the turn-start fuel charge of the
 * ground it stands on: a loaded unit pays nothing, and a unit on ground owned by
 * its own team pays nothing when its kind neither pays on that ground (kind 18/20)
 * nor is grounded there (kind 19/21). */
s32 CanUnitSpendTurnFuel(u8 *p){
extern s32 *gCurrentMap;
extern u8 gUnitKindTable[];
s32 IsSameTeam(u16,s32);
u8 *base=(u8 *)*gCurrentMap;
u16 flags=M2C_FIELD(p,u16 *,4);
u8 tile=M2C_FIELD(base+(p[1]+M2C_FIELD(base+p[2]*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN);
if(flags&8)return 0;
if(IsSameTeam(M2C_FIELD(base,u16 *,0x52a4),(tile&0xe0)>>5)){
switch(tile&MAP_TERRAIN_KIND_MASK){
case 18:case 20:
if(gUnitKindTable[((u32)(p[0]<<26)>>26)*0x70]==18)return 0;
break;
case 19:case 21:
if(gUnitKindTable[((u32)(p[0]<<26)>>26)*0x70]==19)return 0;
break;
}
}
return 1;
}

#pragma opt_dead_code off
u8 func_020a5d2c(s32 a,s32 b){extern s32 *gCurrentMap;u8 *p=(u8 *)*gCurrentMap;s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x508);u8 r;if(!v)return 0;if(M2C_FIELD(p+((v>>6)+1)*0x8c,u8 *,0x67c3)&2)r=1;else r=0;return r;}
#pragma opt_dead_code reset
s32 func_020a5d8c(s32 arg0, u8 arg1, u8 arg2) {
    extern s32 *gCurrentMap;
    s32 IsUnitSubmerged(Unit5B *);
    u8 func_020a5d2c(s32, s32);
    s32 r4;
    s32 r6 = arg1;
    s32 r5 = arg2;
    s32 r7;

    r4 = 0;
    if (arg0 == 0) {
        r7 = r4;
    } else {
        r7 = (u16)((arg0 - ((s32)*gCurrentMap + 0x59a4)) / 14);
    }
    if (arg0 == 0) {
        return 1;
    }
    if (!IsUnitSubmerged((Unit5B *)arg0)) {
        return 1;
    }
    if (*((u8 *)*gCurrentMap + ((r7 >> 6) + 1) * 0x8c + 0x67c3) & 0x2) {
        return 1;
    }
    {
        s32 row = *(u16 *)((u8 *)*gCurrentMap + r5 * 2 + 0x3758);
        u8 tile = *((u8 *)*gCurrentMap + (r6 + row) + 0x1420);
        s32 k = (tile & 0xe0) >> 5;
        if (*((u8 *)*gCurrentMap + k * 0x8c + 0x67c3) & 0x2) {
            return 1;
        }
    }

    if (r6 > 0) {
        r4 = (u16)(r4 + func_020a5d2c((s16)(r6 - 1), r5));
    }
    if (r5 > 0) {
        r4 = (u16)(r4 + func_020a5d2c(r6, (s16)(r5 - 1)));
    }
    {
        s32 maxw = *(u16 *)((u8 *)*gCurrentMap + 0x5144);
        if (r6 < maxw - 1) {
            r4 = (u16)(r4 + func_020a5d2c((s16)(r6 + 1), r5));
        }
    }
    {
        s32 maxh = *(u16 *)((u8 *)*gCurrentMap + 0x5146);
        if (r5 < maxh - 1) {
            r4 = (u16)(r4 + func_020a5d2c(r6, (s16)(r5 + 1)));
        }
    }

    if (r4 != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
void IsMapUnitRevealed(s32 arg0) {
    M2C_UNK func_020a5d8c(s32, u8, u8);
    extern s32 *gCurrentMap;
    s32 mul = 14;
    u8 *base = (u8 *)(*gCurrentMap + 0x1a4);
    u8 *entry = base + 0x5800 + mul * arg0;
    func_020a5d8c((s32)entry, entry[1], entry[2]);
}
#pragma opt_propagation reset
/* Whether map cell (x, y) holds a unit of the current team that the player can
 * see: the cell must be in the first team's sight bitmap, and either its
 * visible-unit entry must be set or the unit must be moving (a moving unit is
 * always drawn). IsUnitInSight checks the four neighbours of a submerged
 * submarine with this. */
s32 IsCellUnitOnCurrentTeamVisible(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 IsUnitOnCurrentTeam(s32);
    u8 *map = (u8 *)*gCurrentMap;
    register u32 cell = x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
    u8 unitId = M2C_FIELD(map + cell, u8 *, MAP_CELL_UNIT_ID);
    if (!unitId || !(u8)(M2C_FIELD(map + (cell >> 3), u8 *, MAP_CELL_BITMAP_TEAM_A) & (1 << (cell & 7)))) return 0;
    if (!M2C_FIELD(map, u8 *, cell + MAP_CELL_VISIBLE_UNIT) && !(M2C_FIELD(map + unitId * MAP_UNIT_STRIDE, u16 *, MAP_UNIT_RECORDS + MAP_UNIT_FLAGS) & UNIT_FLAG_MOVING)) return 0;
    return IsUnitOnCurrentTeam(unitId);
}

s32 IsUnitInSight(s32 arg0) {
    extern s32 *gCurrentMap;
    extern s16 gPlayerUnitIdBase[];
    s32 IsUnitSubmerged(Unit5B *);
    s32 IsUnitOnCurrentTeam(s32);
    s32 IsTerrainOnUnitTeam(s32, s32);
    s32 IsCellUnitOnCurrentTeamVisible(s32, s32);

    u8 x;
    Unit5B *unit = (Unit5B *)((u8 *)*gCurrentMap + 0x59a4 + arg0 * 14);
    u16 acc = 0;
    u8 y;

    if (unit == 0) {
        return 1;
    }
    if (!IsUnitSubmerged(unit)) {
        return 1;
    }
    if (unit->flags & 0x40) {
        return 1;
    }

    x = unit->x;
    y = unit->y;

    if (unit != 0) {
        u8 *base = (u8 *)*gCurrentMap;
        s32 idx = (s32)((u8 *)unit - (base + 0x59a4)) / 14;
        if (IsUnitOnCurrentTeam(idx)) {
            return 1;
        }
    }

    {
        u8 *base = (u8 *)*gCurrentMap;
        u16 rowOff = *(u16 *)(base + y * 2 + 0x3758);
        u16 w = *(u16 *)(base + 0x52a4);
        u8 tile = *(u8 *)(x + rowOff + base + 0x1420);
        s16 val = gPlayerUnitIdBase[w];
        if (IsTerrainOnUnitTeam(val, tile)) {
            return 1;
        }
    }

    if (x > 0) {
        acc = (u16)(acc + IsCellUnitOnCurrentTeamVisible((s16)(x - 1), y));
    }
    if (y > 0) {
        acc = (u16)(acc + IsCellUnitOnCurrentTeamVisible(x, (s16)(y - 1)));
    }
    {
        u8 *base = (u8 *)*gCurrentMap;
        s32 maxw = *(u16 *)(base + 0x5144);
        if (x < maxw - 1) {
            acc = (u16)(acc + IsCellUnitOnCurrentTeamVisible((s16)(x + 1), y));
        }
    }
    {
        u8 *base = (u8 *)*gCurrentMap;
        s32 maxh = *(u16 *)(base + 0x5146);
        if (y < maxh - 1) {
            acc = (u16)(acc + IsCellUnitOnCurrentTeamVisible(x, (s16)(y + 1)));
        }
    }

    if (acc != 0) {
        return 1;
    }
    return 0;
}

#pragma scheduling off
/* Whether the unit is drawn on the map at all: a unit playing its move
 * animation is skipped (flags bit 0x04); otherwise a unit on a cell of the
 * second team's sight bitmap counts when it is really in sight, and so does one
 * whose flags bit 0x80 is set; a unit of the human side counts while its
 * visible flag is still set. */
s32 IsUnitVisible(void *arg0){
s32 func_020a5d8c(s32,u8,u8);extern s32 *gCurrentMap;
u8 *p=arg0;u16 flags;u8 y,x;u8 *base;u32 idx;u8 seen;u16 player;u8 side;
flags=*(u16 *)(p+MAP_UNIT_FLAGS);if(flags&4)return 0;
y=p[MAP_UNIT_Y];base=(u8 *)*gCurrentMap;x=p[MAP_UNIT_X];
idx=x+M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS);
seen=M2C_FIELD(base+(idx>>3),u8 *,MAP_CELL_BITMAP)&(1u<<(idx&7));
if(seen){if(func_020a5d8c((s32)p,x,y)!=0)goto ret1;}
flags=*(u16 *)(p+MAP_UNIT_FLAGS);if(flags&128)return 1;
base=*gCurrentMap;
player=M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER);
side=M2C_FIELD(base+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_SIDE_OFF);
if(side==SIDE_HUMAN){if(flags&UNIT_FLAG_VISIBLE)return 1;}
return 0;
ret1:return 1;
}
#pragma scheduling reset
/* Whether the unit standing on the map cell (x, y) is visible: 0 when the cell
 * is off the map or holds no unit, otherwise the unit record's visibility. */
s32 IsUnitVisibleAt(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 IsUnitVisible(void *);
    u8 *map;
    u8 unitId;
    if (x < 0 || y < 0) goto fail;
    map = (u8 *)*gCurrentMap;
    if (x >= M2C_FIELD(map, u16 *, MAP_WIDTH) || y >= M2C_FIELD(map, u16 *, MAP_HEIGHT)) goto fail;
    goto valid;
fail:
    return 0;
valid:
    unitId = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID);
    if (!unitId) return 0;
    return IsUnitVisible(map + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE);
}

/* Adds `amount`-scaled income to the funds of the player/commander that owns terrain entry `entry`, capped at 999999999, and notifies the funds display if applicable. */
s32 AddPlayerUnitValue(u8 *entry, s32 amount) {
extern s32 *gCurrentMap;
s32 GetUnitBuildCost(s32,u32);
s32 IsPlayerHuman(s32);
s32 func_020cd728(void);
void AddRecordFunds(s32,s32);
s32 id, income;
if(entry){if(!entry)id=0;else id=((s32)entry-(s32)((u8 *)*gCurrentMap+0x1a4+0x5800))/14;id=(id>>6)+1;}else id=0;
income=amount*GetUnitBuildCost(id,(u32)(entry[0]<<26)>>26);
((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x3a4+0x6400))[id].money+=income;
if(((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x3a4+0x6400))[id].money>999999999)((UnkStruct_020A6328 *)((u8 *)*gCurrentMap+0x3a4+0x6400))[id].money=999999999;
if(IsPlayerHuman(id)&&!func_020cd728())AddRecordFunds(12,income);
}

/* The fuel a unit spends for a move of `cost` steps: the cost scaled by the owning
 * player's fuel rate, but never more than the unit's remaining fuel.  Returns 0
 * for unit kinds that do not pay fuel. */
s32 GetUnitMoveFuelCost(u8 *unit, s32 cost) {
    extern s32 *gCurrentMap;
    s32 func_020a85c0(u32);
    s32 func_020a86f0(s32);
    s32 player, fuel;
    if (unit) {
        if (!unit) player = 0;
        else player = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / 14;
        player = (player >> MAP_UNIT_OWNER_SHIFT) + 1;
    } else player = 0;
    if (func_020a85c0((u32)(unit[MAP_UNIT_KIND] << 26) >> 26)) return 0;
    fuel = func_020a86f0(player) * cost;
    player = (u32)(unit[MAP_UNIT_FUEL] << 25) >> 25;
    if (fuel > player) fuel = player;
    return fuel;
}

void func_020a64bc(void *p){
s32 n=((s32 (*)(void *))GetUnitMoveFuelCost)(p);
u8 b=M2C_FIELD(p,u8 *,10);
s32 low=(u32)(b<<25)>>25;
n=(u8)(low-n);
n=n&127;
M2C_FIELD(p,u8 *,10)=(u8)((b&~127)|n);
}

void func_020a64ec(void) {
    M2C_UNK BeginUnitMove();
    BeginUnitMove();
}

#pragma scheduling off
/* Initialise a freshly allocated map unit record: clear its flags, AI targets
 * and carried-unit chain, give it full health and fill its fuel and ammo from
 * the unit-kind tables. */
void InitUnitRecord(void *arg0, u8 kind) {
    BattleMapUnitHead *unit = (BattleMapUnitHead *)arg0;
    unit->kind = kind; unit->owner = 0;
    unit->flags = 0; unit->health = 100;
    unit->fuel = gUnitKindMaxFuel[kind * UNIT_KIND_STATS_SIZE];
    unit->ammo = gUnitKindMaxAmmo[kind * UNIT_KIND_STATS_SIZE];
    unit->facing = 0; unit->firstCarried = 0; unit->nextCarried = 0; unit->aiState = 0;
    unit->targetX = MAP_UNIT_TARGET_NONE; unit->targetY = MAP_UNIT_TARGET_NONE;
    unit->unkB4 = 1; unit->unk8_12 = 0; unit->unk8_14 = 0;
    unit->unkA_7 = 0; unit->unkB5 = 0; unit->unkB6 = 0; unit->unkB7 = 0;
}
#pragma scheduling reset
void *CreateMapUnit(s32 a,s32 b,s32 c,s32 d){void *FindFreeUnitRecord(s32);void InitUnitRecord(void *,u8);void func_020d3154(s32,s32);void *p=FindFreeUnitRecord(d);if(!p)return 0;InitUnitRecord(p,(u8)c);M2C_FIELD(p,u8 *,1)=a;M2C_FIELD(p,u8 *,2)=b;func_020d3154(d,c);return p;}

/* Create a map unit of `kind` for `player` at tile (x, y): stamp it with the
 * player's owner group, mark it as having already acted this turn, and start a
 * new submarine submerged. */
void *CreateOwnedMapUnit(s32 x, s32 y, s32 kind, s32 player) {
    extern s32 *gCurrentMap;
    void *CreateMapUnit(s32, s32, s32, s32);
    u8 *unit = CreateMapUnit((s16)x, (s16)y, (s16)kind, player);
    u8 ownerGroup;
    if (!unit) return 0;
    ownerGroup = M2C_FIELD((u8 *)*gCurrentMap + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_UNIT_OWNER);
    unit[MAP_UNIT_KIND] = (unit[MAP_UNIT_KIND] & ~MAP_UNIT_OWNER_MASK) | ((u32)(ownerGroup << 30) >> 24);
    M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) |= UNIT_FLAG_ACTED;
    if (kind == UNIT_KIND_SUBMARINE) M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) |= UNIT_FLAG_SUBMERGED;
    return unit;
}

void *func_020a66e0(s32 a,s32 b,s32 c,s32 d){void *CreateMapUnit(s32,s32,s32,s32);void RefreshMapView(void *);void *p=CreateMapUnit((s16)a,(s16)b,(s16)c,d);if(!p)return 0;RefreshMapView(p);return p;}

void RemoveUnit(M2C_UNK arg0) {
    void RemoveMapUnit(M2C_UNK, M2C_UNK);
    RemoveMapUnit(arg0, 0);
}

void DestroyUnit(M2C_UNK arg0) {
    void RemoveMapUnit(M2C_UNK, M2C_UNK);
    RemoveMapUnit(arg0, 1);
}

/* Remove the unit with id `unitId` (and every unit it carries) from the battle
 * map.  When `destroyed` is set its owner's per-kind loss count and unit value
 * are recorded; the player's selected-unit slot is cleared in either case. */
void RemoveMapUnit(s32 unitId, s32 destroyed) {
    extern s32 *gCurrentMap;
    s32 Divide(s32, s32);
    u8 *unit = (u8 *)*gCurrentMap + 0x1a4 + 0x5800 + unitId * 14;
    if (destroyed) {
        u32 health;
        func_020d319c((unitId >> MAP_UNIT_OWNER_SHIFT) + 1, (u32)(unit[MAP_UNIT_KIND] << 26) >> 26);
        health = (u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25;
        AddPlayerUnitValue(unit, health == 0 ? 0 : Divide(health - 1, 10) + 1);
    } else DecrementPlayerUnitCount((unitId >> MAP_UNIT_OWNER_SHIFT) + 1);
    if (unit[MAP_UNIT_CARRIED]) RemoveMapUnit(unit[MAP_UNIT_CARRIED], destroyed);
    if (unit[MAP_UNIT_NEXT_CARRIED]) RemoveMapUnit(unit[MAP_UNIT_NEXT_CARRIED], destroyed);
    ClearPlayerSelectedUnit(unit, 1);
    unit[MAP_UNIT_KIND] &= ~MAP_UNIT_KIND_MASK;
}

