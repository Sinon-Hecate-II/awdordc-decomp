/* 15 functions from 0x021959CC to 0x0219694C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind959;

#pragma opt_propagation off
s32 func_ov000_021959cc(s32 x,s32 y,s32 data,s32 radius){
s32 func_ov000_021a93b0(s32,s32,s32);s32 IsUnitOnCurrentTeam(s32);s32 GetAttackDamage(M2C_UNK,M2C_UNK,s32);
extern void **gCurrentMap;
s32 sy;
s32 left;
s32 bottom;
s32 i,dy,top,right,ny;
void *base;
s32 d;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;if(y+radius<bottom)bottom=y+radius;
for(;top<=bottom;top++)for(i=left;i<=right;i++){
dy=y-top;ny=top-y;sy=top;
d=0;if(x-i>0)d+=x-i;else d+=i-x;
if(dy>0)d+=dy;else d+=ny;
if(d>=0&&d<=radius){
base=*gCurrentMap;
if(func_ov000_021a93b0(M2C_FIELD(base,u16 *,0x52a4),(s16)i,(s16)sy)!=0)continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)top<<1),u16 *,0x3758));
if(!d)continue;
if(IsUnitOnCurrentTeam(d)!=0)continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)top<<1),u16 *,0x3758));
if(GetAttackDamage(data,((UnitKind959 *)((u8 *)base+d*14+0x59a4))->kind,0)>=30)return 1;
}
}
return 0;
}
#pragma opt_propagation reset
#pragma opt_strength_reduction off
s32 func_ov000_02195b80(s16 *out) {
    s32 IsPropertyTerrain(s32);
    s32 FloodFillUnitRange(u8, u8, u32, s32, s32);
    void SelectMapLayer(void *);
    void BuildUnitMoveRange(void *);
    s32 IsAllyUnitAtCell(s16, s16);
    s32 IsValidMoveCell(s16, s16);
    s32 GetUnitAttackRangeMax(void *);
    extern void **gCurrentMap;
    extern u8 gUnitKindFlags[];
    extern s8 gTerrainPropertyType[];
    extern void *gAiUnitTypeTuning;
    UnitKind959 *acting;
    s32 kind;
    u8 kindFlags;
    s32 y, x, targetX = -1, bestCost = 0x7fff, occupied = 0, targetY = -1;
    u8 *map;
    acting = M2C_FIELD(*gCurrentMap, UnitKind959 **, MAP_CURSOR_UNIT);
    kind = acting->kind;
    kindFlags = gUnitKindFlags[kind * 0x70];
    if (kindFlags & 0x20) return 0;
    FloodFillUnitRange(M2C_FIELD(acting, u8 *, MAP_UNIT_X), M2C_FIELD(acting, u8 *, MAP_UNIT_Y), kind, 110, 0);
    SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
    BuildUnitMoveRange(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT));
    SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            u16 rowOffset;
            u8 terrain;
            s32 range;
            u8 *cell;
            if (M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID)[x] < 0) continue;
            map = (u8 *)*gCurrentMap;
            rowOffset = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            terrain = M2C_FIELD(map + x + rowOffset, u8 *, MAP_CELL_TERRAIN);
            if (!IsPropertyTerrain(terrain & MAP_TERRAIN_KIND_MASK)) continue;
            map = (u8 *)*gCurrentMap;
            rowOffset = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            terrain = M2C_FIELD(map + x + rowOffset, u8 *, MAP_CELL_TERRAIN);
            if (gTerrainPropertyType[terrain & MAP_TERRAIN_KIND_MASK] != 0) continue;
            if (M2C_FIELD(map, u16 *, MAP_CURRENT_OWNER) != (terrain & MAP_TERRAIN_OWNER_MASK)) continue;
            range = GetUnitAttackRangeMax(M2C_FIELD(map, void **, MAP_CURSOR_UNIT));
            if (!func_ov000_021959cc((s16)x, (s16)y, M2C_FIELD(*gCurrentMap, UnitKind959 **, MAP_CURSOR_UNIT)->kind, (u8)range)) continue;
            map = (u8 *)*gCurrentMap;
            rowOffset = M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS);
            cell = map + x + rowOffset;
            if (M2C_FIELD(cell, u8 *, 0x2d48) >= ((u8 *)gAiUnitTypeTuning)[2]) continue;
            if (M2C_FIELD(cell, s8 *, 0x2338) >= 0) {
                if (IsAllyUnitAtCell((s16)x, (s16)y)) continue;
                if (!IsValidMoveCell((s16)x, (s16)y)) continue;
                if (occupied && bestCost < M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID)[x]) continue;
                occupied = 1;
            } else {
                if (occupied || bestCost < M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x]) continue;
            }
            targetX = x;
            targetY = y;
            bestCost = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID)[x];
        }
    }
    if (bestCost == 0x7fff) return 0;
    out[0] = targetX;
    out[1] = targetY;
    return 1;
}
#pragma opt_strength_reduction reset

/* Chooses the selected AI unit's step-4 destination: an indirect unit looks for a
 * tile to attack from (func_ov000_02195b80), anything else for a property to head
 * to; a destination the unit may not end its move on is dropped, otherwise the
 * move is planned to it. */
void PlanAiStep4Destination(void) {
    s32 GetUnitAttackClass(u32);
    s32 func_ov000_02195b80(s16 *);
    s32 SelectPropertyDestination(s16 *);
    s32 func_ov000_0217e6bc(s16,s16);
    void PlanMoveDestination(s16,s16);
    extern void **gCurrentMap;
    s16 destination[2];
    if (GetUnitAttackClass((u32)(*M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT)<<26)>>26)==UNIT_ATTACK_INDIRECT) {
        if (func_ov000_02195b80(destination)==0) return;
    } else {
        if (SelectPropertyDestination(destination)==0) return;
    }
    if (func_ov000_0217e6bc(destination[0],destination[1])==0) return;
    PlanMoveDestination(destination[0],destination[1]);
}

/* Return-to-HQ destination for the selected AI unit (AI state 5): marks the unit's
   movement range and, when the current player has an HQ and the unit can reach it,
   writes the HQ tile to `out` and returns 1; otherwise returns 0.  Kinds whose flag
   0x20 is set are excluded. */
s32 SelectHqDestination(s16 *out) {
    s32 PlayerHasHq(u16);
    s32 FloodFillUnitRange(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;
    extern u8 gUnitKindFlags[];

    u8 *map;
    u8 *unit;
    u16 player;
    u8 *entry;
    s8 *grid;
    s8 gridValue;

    map = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(map + MAP_CURSOR_UNIT);
    if (gUnitKindFlags[((u32)(unit[MAP_UNIT_KIND] << 26) >> 26) * UNIT_KIND_STATS_SIZE] & 0x20) {
        return 0;
    }
    if (PlayerHasHq(*(u16 *)(map + MAP_CURRENT_PLAYER)) == 0) {
        return 0;
    }

    map = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(map + MAP_CURSOR_UNIT);
    FloodFillUnitRange(unit[MAP_UNIT_X], unit[MAP_UNIT_Y], (u32)(unit[MAP_UNIT_KIND] << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + MAP_CURRENT_PLAYER);
    entry = map + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    grid = *(s8 **)(map + ((u32)(entry[PLAYER_REC_HQ_Y] << 25) >> 23) + MAP_GRID);
    gridValue = grid[entry[PLAYER_REC_HQ_X] & 0x7f];
    if (gridValue < 0) {
        return 0;
    }
    out[0] = (s16)(entry[PLAYER_REC_HQ_X] & 0x7f);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + MAP_CURRENT_PLAYER);
    entry = map + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;
    out[1] = (s16)(entry[PLAYER_REC_HQ_Y] & 0x7f);

    return 1;
}

void PlanHqDestination(void) {
    s32 SelectHqDestination(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (SelectHqDestination(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

/* Resolve the selected AI unit's attack destination (AI steps 7 and 9): take the
 * unit's assigned AI move target, or its own tile when it has none, and, once the
 * tile is confirmed on the grid, move the position to a firing tile within range
 * of it (FindAttackPosition); write the result to outPos and return 0 when no
 * tile is found. */
s32 SelectAttackDestination(s16 *outPos) {
    void GetAiUnitRange(void);
    void BuildAiUnitThreatRange(void);
    s32 FindAttackPosition(s16 *);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 target;
    s8 gridValue;
    s16 position[2];

    GetAiUnitRange();
    BuildAiUnitThreatRange();

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    if (((u32)(target << 26) >> 26) == MAP_UNIT_TARGET_NONE) {
        u8 value = *(u8 *)((u8 *)unit + MAP_UNIT_X);
        target = (target & ~MAP_UNIT_TARGET_X_MASK) | (value & MAP_UNIT_TARGET_X_MASK);
        *(u16 *)((u8 *)unit + MAP_UNIT_TARGET) = target;

        map = (u8 *)*gCurrentMap;
        unit = *(void **)(map + MAP_CURSOR_UNIT);
        target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
        {
            u8 value = *(u8 *)((u8 *)unit + MAP_UNIT_Y);
            target = (target & ~MAP_UNIT_TARGET_Y_MASK) | (((u32)value << 26) >> 20);
        }
        *(u16 *)((u8 *)unit + MAP_UNIT_TARGET) = target;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    gridValue = ((s8 **)(map + MAP_GRID))[((u32)(target << 20) >> 26)][((u32)(target << 26) >> 26)];
    if (gridValue < 0) {
        return 0;
    }

    position[0] = (s16)(((u32)(target << 26) >> 26));
    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    position[1] = (s16)(((u32)(target << 20) >> 26));

    if (FindAttackPosition(position) == 0) {
        return 0;
    }
    outPos[0] = position[0];
    outPos[1] = position[1];
    return 1;
}

void PlanReachableAttackDestination(void) {
    s32 SelectAttackDestination(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (SelectAttackDestination(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

/* For the selected AI unit (state 8): fill in its movement range, set its packed
   MAP_UNIT_TARGET word to its own cell when it holds no target yet, and return the
   target cell - x in bits 0..5, y in bits 6..11 - through outPos when the unit can
   reach it.  Returns 0 when the target cell is unreachable. */
s32 SelectAssignedMoveDestination(s16 *outPos) {
    s32 FloodFillUnitRange(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 target;
    s8 gridValue;
    u32 targetX;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    FloodFillUnitRange(*(u8 *)((u8 *)unit + MAP_UNIT_X), *(u8 *)((u8 *)unit + MAP_UNIT_Y),
                   (u32)(*(u8 *)((u8 *)unit + MAP_UNIT_KIND) << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    if (((u32)(target << 26) >> 26) == MAP_UNIT_TARGET_NONE) {
        u8 v = *(u8 *)((u8 *)unit + MAP_UNIT_X);
        target = (target & ~MAP_UNIT_TARGET_X_MASK) | (v & MAP_UNIT_TARGET_X_MASK);
        *(u16 *)((u8 *)unit + MAP_UNIT_TARGET) = target;

        map = (u8 *)*gCurrentMap;
        unit = *(void **)(map + MAP_CURSOR_UNIT);
        target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
        {
            u8 v = *(u8 *)((u8 *)unit + MAP_UNIT_Y);
            target = (target & ~MAP_UNIT_TARGET_Y_MASK) | (((u32)v << 26) >> 20);
        }
        *(u16 *)((u8 *)unit + MAP_UNIT_TARGET) = target;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    gridValue = ((s8 **)(map + MAP_GRID))[((u32)(target << 20) >> 26)][((u32)(target << 26) >> 26)];
    targetX = (u32)(target << 26) >> 26;
    if (gridValue < 0) {
        return 0;
    }

    outPos[0] = (s16)targetX;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + MAP_CURSOR_UNIT);
    target = *(u16 *)((u8 *)unit + MAP_UNIT_TARGET);
    outPos[1] = (s16)(((u32)target << 20) >> 26);

    return 1;
}

void PlanCaptureMoveDestination(void) {
    s32 SelectAssignedMoveDestination(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (SelectAssignedMoveDestination(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

/* Returns 1 when an active player on the opposing team has a unit selected. */
s32 HasEnemySelectedUnit(void) {
    s32 GetPlayerSelectedUnit(s32);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    s32 player;

    player = 1;
loop_1:
    if ((IsPlayerActive(player) != 0) && (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0) && (GetPlayerSelectedUnit(player) != 0)) {
        return 1;
    }
    player += 1;
    if (player >= MAX_PLAYERS) {
        return 0;
    }
    goto loop_1;
}

/* Plan an attack on the enemy HQ: refresh the current unit's move range and
 * threat map, pick a destination next to the enemy HQ, and confirm the unit can
 * attack from there; on success writes the position to outPos and returns 1. */
s32 FindEnemyHqAttackPosition(s16 *outPos) {
    void GetAiUnitRange();
    void BuildAiUnitThreatRange();
    s32 SelectEnemyHqDestination(s16 *);
    s32 FindAttackPosition(s16 *);
    s16 pos[2];

    GetAiUnitRange();
    BuildAiUnitThreatRange();
    if (SelectEnemyHqDestination(pos) == 0) {
        return 0;
    }
    if (FindAttackPosition(pos) == 0) {
        return 0;
    }
    outPos[0] = pos[0];
    outPos[1] = pos[1];
    return 1;
}

void PlanEnemyHqAttackDestination(void) {
    s32 FindEnemyHqAttackPosition(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (FindEnemyHqAttackPosition(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
/* Picks the destination the selected AI unit moves to, dispatched on the unit's
   AI state (MAP_UNIT_AI_STATE low nibble); writes the target tile to outPos and
   returns 0 when no destination could be chosen. */
s32 func_ov000_02196430(s16 *outPos) {
    s32 func_ov000_02194ab8(s16 *);
    s32 HasEnemyPlayer(void);
    s32 FindEnemyHqAttackPositionAlt(s16 *);
    s32 func_ov000_02195574(s16 *);
    s32 SelectPropertyDestination(s16 *);
    s32 PlayerHasHq(u16);
    s32 SelectHqDestination(s16 *);
    s32 SelectAttackDestination(s16 *);
    s32 SelectAssignedMoveDestination(s16 *);
    s32 HasEnemySelectedUnit(void);
    s32 FindEnemyHqAttackPosition(s16 *);
    extern void **gCurrentMap;
    struct Nib { unsigned char lo : 4; unsigned char hi : 4; };

    u8 *map;
    u8 *unit;
    u32 aiState;

    map = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(map + MAP_CURSOR_UNIT);
    aiState = ((struct Nib *)(unit + MAP_UNIT_AI_STATE))->lo;

    switch (aiState) {
    case 0:
    case 1:
        if (func_ov000_02194ab8(outPos) == 0) {
            return 0;
        }
        break;
    case 2:
        if (HasEnemyPlayer() == 1) {
            if (FindEnemyHqAttackPositionAlt(outPos) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(outPos) == 0) {
                return 0;
            }
        }
        break;
    case 3:
        if (func_ov000_02195574(outPos) == 0) {
            return 0;
        }
        break;
    case 4:
        if (SelectPropertyDestination(outPos) == 0) {
            return 0;
        }
        break;
    case 5: {
        u16 player = *(u16 *)(map + MAP_CURRENT_PLAYER);
        if (PlayerHasHq(player) == 1) {
            if (SelectHqDestination(outPos) == 0) {
                return 0;
            }
        } else {
            if (SelectPropertyDestination(outPos) == 0) {
                return 0;
            }
        }
        break;
    }
    case 7:
    case 9:
        if (SelectAttackDestination(outPos) == 0) {
            return 0;
        }
        break;
    case 8:
        if (SelectAssignedMoveDestination(outPos) == 0) {
            return 0;
        }
        break;
    case 6:
        outPos[0] = (s16)unit[MAP_UNIT_X];
        outPos[1] = (s16)(((u8 *)*(void **)(((u8 *)*gCurrentMap) + MAP_CURSOR_UNIT))[MAP_UNIT_Y]);
        break;
    case 10:
        if (HasEnemySelectedUnit() == 1) {
            if (FindEnemyHqAttackPosition(outPos) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(outPos) == 0) {
                return 0;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma opt_strength_reduction off
/* AI: pick the cheapest enemy-owned property the selected unit can attack, find
 * a firing position next to it and plan the move there. */
void SelectPropertyAttackDestination(void) {
extern void **gCurrentMap; extern u8 **gAiCommandState;
s32 GetUnitAttackClass(u32); s32 GetUnitAttackRangeMax(void *);
void GetAiUnitRange(void); void BuildAiUnitThreatRange(void);
s32 IsTerrainOnUnitTeam(s32,u8); s32 func_ov000_0217d000(u32,s32);
s32 FindAttackPosition(s16 *); s32 func_ov000_0217e6bc(s16,s16); void PlanMoveDestination(s16,s16);
s32 attackLimit; s32 terrain; s32 bestCost=0x7fff; s32 y,x; s16 target[2];
if(GetUnitAttackClass(((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))->kind)==1)
attackLimit=GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))+M2C_FIELD(gAiCommandState,u8 *,5);
else attackLimit=0;
GetAiUnitRange(); BuildAiUnitThreatRange();
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);x++){
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,MAP_GRID)[x]<0)continue;
terrain=M2C_FIELD((u8 *)*gCurrentMap+x+M2C_FIELD((u8 *)*gCurrentMap+y*2,u16 *,MAP_ROW_OFFSETS),u8 *,MAP_CELL_TERRAIN);
if(!(terrain&MAP_TERRAIN_OWNER_MASK))continue;
if(IsTerrainOnUnitTeam(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_OWNER),(u8)terrain)==1)continue;
if(!func_ov000_0217d000(((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))->kind,terrain))continue;
if(bestCost<=attackLimit){
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,MAP_GRID)[x]>attackLimit)continue;
if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,MAP_GRID)[x]>=bestCost)goto accept;
continue;
}else if(M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,MAP_GRID)[x]>bestCost)continue;
accept:
target[0]=x;target[1]=y;
bestCost=M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,MAP_GRID)[x];
}}
if(bestCost==0x7fff)return;
if(!FindAttackPosition(target))return;
if(!func_ov000_0217e6bc(target[0],target[1]))return;
PlanMoveDestination(target[0],target[1]);
}
#pragma opt_strength_reduction reset
void SelectPortDestination(void) {
s32 CanKindLoad(u32,u32); void GetAiUnitRange(void);void BuildAiUnitThreatRange(void);s32 func_ov000_0217e6bc(s16,s16);void PlanMoveDestination(s16,s16);
extern void **gCurrentMap;extern u8 **gAiCommandState;
s32 best=0x7fff; s16 sx,sy; s32 cols,t,x,y; s16 row;u8 *base; s8 *grid,*p;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,10)<<29)>>29)&4))return;
if(!CanKindLoad(24,((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->kind))return;
GetAiUnitRange();BuildAiUnitThreatRange();
base=*gCurrentMap;
y=0; if((s32)M2C_FIELD(base,u16 *,0x5146)>0) do {
cols=M2C_FIELD(base,u16 *,0x5144);
if(cols<=0)goto rowend;
grid=M2C_FIELD(base+y*4,s8 **,0x52e8);p=grid;
row=y;x=0; do {
if(*p<0)goto next;
t=M2C_FIELD(M2C_FIELD(base+y*2,u16 *,0x3758)+base+x,u8 *,0x1420);
if((t&0xe0)==0 && (t&31)==19) {
best=grid[x];sx=x;sy=row;
}
next: x++;p++;
}while(x<cols); rowend:y++; }while(y<(s32)M2C_FIELD(base,u16 *,0x5146));
if(best==0x7fff)return;
if(!func_ov000_0217e6bc(sx,sy))return;
PlanMoveDestination(sx,sy);
}

