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
s32 func_ov000_02195b80(s16 *out) {
    s32 IsPropertyTerrain(s32);
    s32 GetUnitAttackClass(u32);
    s32 func_ov000_0217bc34(s32, s32, s32, s32);
    s32 FloodFillUnitRange(u8, u8, u32, s32, s32);
    void SelectMapLayer(void *);
    void BuildUnitMoveRange(void *);
    s32 IsAllyUnitAtCell(s16, s16);
    s32 IsValidMoveCell(s16, s16);
    s32 func_ov000_021959cc(s32, s32, s32, s32);
    s32 GetUnitAttackRangeMax(void *);

    extern void **gCurrentMap;
    extern u8 gUnitKindFlags[];
    extern void *gAiUnitTypeTuning;
    extern u8 gTerrainPropertyType[];

    void *up;
    s32 unitKind;
    u8 attr;
    void *map;
    s32 resX = -1;
    s32 resY = -1;
    s32 best = 0x7fff;
    s32 flag = 0;
    s32 y, x;
    s32 height, width;

    up = *(void **)((u8 *)*gCurrentMap + 0x52d0);
    unitKind = ((u8 *)up)[0] & 0x3f;
    attr = gUnitKindFlags[unitKind * 0x70];
    if (attr & 0x20) {
        return 0;
    }
    FloodFillUnitRange(((u8 *)up)[1], ((u8 *)up)[2], (u32)unitKind, 110, 0);

    map = *gCurrentMap;
    SelectMapLayer((u8 *)map + 0x2338);
    BuildUnitMoveRange((u8 *)map + 0x52d0);
    SelectMapLayer((u8 *)map + 0x1e30);

    height = *(u16 *)((u8 *)*gCurrentMap + 0x5146);
    for (y = 0; y < height; y++) {
        width = *(u16 *)((u8 *)*gCurrentMap + 0x5144);
        for (x = 0; x < width; x++) {
            s8 cand;
            void *rows;
            u8 *m;
            u16 rowOff;
            u8 grid0;

            rows = *(void **)((u8 *)*gCurrentMap + 0x52e8 + y * 4);
            cand = ((s8 *)rows)[x];
            if (cand < 0) continue;

            m = (u8 *)*gCurrentMap;
            rowOff = *(u16 *)(m + 0x3758 + y * 2);
            grid0 = *(u8 *)(m + x + rowOff + 0x1420);
            if (IsPropertyTerrain(grid0 & 0x1f) == 0) continue;

            m = (u8 *)*gCurrentMap;
            rowOff = *(u16 *)(m + 0x3758 + y * 2);
            grid0 = *(u8 *)(m + x + rowOff + 0x1420);
            if (*(u16 *)(m + 0x52a6) != (grid0 & 0xe0)) continue;

            rows = *(void **)((u8 *)*gCurrentMap + 0x52e8 + y * 4);
            cand = ((s8 *)rows)[x];
            if (best < cand) continue;

            {
                u8 thr;
                u8 grid1;
                m = (u8 *)*gCurrentMap;
                rowOff = *(u16 *)(m + 0x3758 + y * 2);
                grid1 = *(u8 *)(m + x + rowOff + 0x2d48);
                thr = ((u8 *)gAiUnitTypeTuning)[2];
                if (grid1 >= thr) continue;

                if (gTerrainPropertyType[grid0 & 0x1f] != 0) continue;

                {
                    s32 mask;
                    mask = GetUnitAttackRangeMax(*(void **)((u8 *)*gCurrentMap + 0x52d0));
                    if (func_ov000_021959cc(x, y, unitKind, mask & 0xff) == 0) continue;
                }

                {
                    u8 *m2 = (u8 *)*gCurrentMap;
                    u16 r2off = *(u16 *)(m2 + 0x3758 + y * 2);
                    u8 g1 = *(u8 *)(m2 + x + r2off + 0x2d48);
                    u8 thr2 = ((u8 *)gAiUnitTypeTuning)[2];
                    if (g1 >= thr2) continue;
                }

                {
                    u8 *m2 = (u8 *)*gCurrentMap;
                    u16 r2off = *(u16 *)(m2 + 0x3758 + y * 2);
                    s8 *p = (s8 *)(m2 + x + r2off + 0x2338);
                    if (*p < 0) continue;
                }

                if (IsAllyUnitAtCell((s16)x, (s16)y) != 0) continue;
                if (IsValidMoveCell((s16)x, (s16)y) == 0) continue;

                if (flag != 0) {
                    rows = *(void **)((u8 *)*gCurrentMap + 0x52e8 + y * 4);
                    cand = ((s8 *)rows)[x];
                    if (best < cand) continue;
                    flag = 1;
                } else {
                    resX = x;
                    resY = y;
                    rows = *(void **)((u8 *)*gCurrentMap + 0x52e8 + y * 4);
                    best = ((s8 *)rows)[x];
                }
            }
        }
    }

    if (best == 0x7fff) return 0;
    out[0] = (s16)resX;
    out[1] = (s16)resY;
    return 1;
}

void func_ov000_02195ea4(void) {
    s32 GetUnitAttackClass(u32);
    s32 func_ov000_02195b80(s16 *);
    s32 SelectPropertyDestination(s16 *);
    s32 func_ov000_0217e6bc(s16,s16);
    void PlanMoveDestination(s16,s16);
    extern void **gCurrentMap;
    s16 sp0[2];
    if (GetUnitAttackClass((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26)==1) {
        if (func_ov000_02195b80(sp0)==0) return;
    } else {
        if (SelectPropertyDestination(sp0)==0) return;
    }
    if (func_ov000_0217e6bc(sp0[0],sp0[1])==0) return;
    PlanMoveDestination(sp0[0],sp0[1]);
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

void func_ov000_0219604c(void) {
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

s32 func_ov000_02196084(s16 *arg0) {
    void GetAiUnitRange(void);
    void func_ov000_02179d3c(void);
    s32 FindAttackPosition(s16 *);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    s16 sp0[2];

    GetAiUnitRange();
    func_ov000_02179d3c();

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 0x01);
        f8 = (f8 & ~0x3f) | (v & 0x3f);
        *(u16 *)((u8 *)unit + 0x08) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    {
        u8 v = *(u8 *)((u8 *)unit + 0x02);
        f8 = (f8 & ~0xfc0) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 0x08) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    cell = ((s8 **)(map + 0x52e8))[((u32)(f8 << 20) >> 26)][((u32)(f8 << 26) >> 26)];
    if (cell < 0) {
        return 0;
    }

    sp0[0] = (s16)(((u32)(f8 << 26) >> 26));
    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    sp0[1] = (s16)(((u32)(f8 << 20) >> 26));

    if (FindAttackPosition(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219619c(void) {
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196084(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

s32 func_ov000_021961d4(s16 *arg0) {
    s32 FloodFillUnitRange(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    u32 low;
    u32 kind;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    FloodFillUnitRange(*(u8 *)((u8 *)unit + 1), *(u8 *)((u8 *)unit + 2),
                   (u32)(*(u8 *)((u8 *)unit) << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 1);
        f8 = (f8 & ~0x3fu) | (v & 0x3fu);
        *(u16 *)((u8 *)unit + 8) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    {
        u8 v = *(u8 *)((u8 *)unit + 2);
        f8 = (f8 & ~0xfc0u) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 8) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    low = ((u32)f8 << 26) >> 26;
    kind = ((u32)f8 << 20) >> 26;
    cell = *(s8 *)((u8 *)*(void **)(map + 0x52e8 + kind * 4) + low);
    if (cell < 0) {
        return 0;
    }

    arg0[0] = (s16)low;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    arg0[1] = (s16)(((u32)f8 << 20) >> 26);

    return 1;
}

void func_ov000_021962f8(void) {
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_021961d4(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

s32 func_ov000_02196330(void) {
    s32 GetPlayerSelectedUnit(s32);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    s32 var_r5;

    var_r5 = 1;
loop_1:
    if ((IsPlayerActive(var_r5) != 0) && (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), var_r5) == 0) && (GetPlayerSelectedUnit(var_r5) != 0)) {
        return 1;
    }
    var_r5 += 1;
    if (var_r5 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 func_ov000_02196398(s16 *arg0) {
    void GetAiUnitRange();
    void func_ov000_02179d3c();
    s32 func_ov000_021786a8(s16 *);
    s32 FindAttackPosition(s16 *);
    s16 sp0[2];

    GetAiUnitRange();
    func_ov000_02179d3c();
    if (func_ov000_021786a8(sp0) == 0) {
        return 0;
    }
    if (FindAttackPosition(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_021963f8(void) {
    s32 func_ov000_02196398(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196398(sp0) == 0) {
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
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_02195574(s16 *);
    s32 SelectPropertyDestination(s16 *);
    s32 PlayerHasHq(u16);
    s32 SelectHqDestination(s16 *);
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_02196330(void);
    s32 func_ov000_02196398(s16 *);
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
            if (func_ov000_021954dc(outPos) == 0) {
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
        if (func_ov000_02196084(outPos) == 0) {
            return 0;
        }
        break;
    case 8:
        if (func_ov000_021961d4(outPos) == 0) {
            return 0;
        }
        break;
    case 6:
        outPos[0] = (s16)unit[MAP_UNIT_X];
        outPos[1] = (s16)(((u8 *)*(void **)(((u8 *)*gCurrentMap) + MAP_CURSOR_UNIT))[MAP_UNIT_Y]);
        break;
    case 10:
        if (func_ov000_02196330() == 1) {
            if (func_ov000_02196398(outPos) == 0) {
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
void GetAiUnitRange(void); void func_ov000_02179d3c(void);
s32 IsTerrainOnUnitTeam(s32,u8); s32 func_ov000_0217d000(u32,s32);
s32 FindAttackPosition(s16 *); s32 func_ov000_0217e6bc(s16,s16); void PlanMoveDestination(s16,s16);
s32 attackLimit; s32 terrain; s32 bestCost=0x7fff; s32 y,x; s16 target[2];
if(GetUnitAttackClass(((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))->kind)==1)
attackLimit=GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT))+M2C_FIELD(gAiCommandState,u8 *,5);
else attackLimit=0;
GetAiUnitRange(); func_ov000_02179d3c();
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
void func_ov000_021967fc(void) {
s32 CanKindAttack(u32,u32); void GetAiUnitRange(void);void func_ov000_02179d3c(void);s32 func_ov000_0217e6bc(s16,s16);void PlanMoveDestination(s16,s16);
extern void **gCurrentMap;extern u8 **gAiCommandState;
s32 best=0x7fff; s16 sx,sy; s32 cols,t,x,y; s16 row;u8 *base; s8 *grid,*p;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,10)<<29)>>29)&4))return;
if(!CanKindAttack(24,((UnitKind959 *)M2C_FIELD(*gCurrentMap,void **,0x52d0))->kind))return;
GetAiUnitRange();func_ov000_02179d3c();
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

