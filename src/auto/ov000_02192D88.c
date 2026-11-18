/* 4 functions from 0x02192D88 to 0x02193D6C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
#include "ov000_unit_entry.h"

#pragma opt_strength_reduction off
#pragma opt_if-conversion off
int func_ov000_02192d88(void){
extern void **gCurrentMap;
extern u16 *gAiCommandState;
extern s8 gTerrainPropertyType[32];
void BuildUnitMoveRange(void); void MarkAdjacentCells(s32);
s32 IsAllyUnitAtCell(s16,s16); u8 IsPropertyTerrain(s32);
s32 IsPropertyCell(s32,s32); s32 FindBestAdjacentDestination(s32,s32,s16 *);
s32 func_ov000_0217bdb4(s32,s32);s32 func_ov000_0217bd44(s32,s32,s32,s32);
s32 SetMapCursor(s16,s16,s32,s32,s32);
s32 func_ov000_0217c08c(s32,s32,s32,s16 *);s32 IsTerrainOnUnitTeam(s32,s32);
s32 x,y,bx,by,px,py,tx,ty,best,tie,score,value,id,kind;
s32 sx,sy,ux,uy;
s16 dest[2],pos[2];
u8 *unit;
id=M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,12);
unit=(u8 *)*gCurrentMap+0x59a4+id*14;
bx=-1;by=bx;px=bx;py=bx;tx=bx;ty=bx;best=bx;tie=0x7fff;
if(!id)return;
BuildUnitMoveRange();MarkAdjacentCells(0x6f);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
if(IsAllyUnitAtCell((s16)x,(s16)y))continue;
if(IsPropertyTerrain(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)) && M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x508))continue;
if(!IsPropertyCell(x,y))continue;
if(!FindBestAdjacentDestination(x,y,pos))continue;
if(M2C_FIELD(*gCurrentMap,u8 *,0x6c63+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),s8 *,0x1928)*6) && !(gAiCommandState[4]&0x20)){
if(func_ov000_0217bdb4(x,y)==1)continue;
}
score=M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x);
value=M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2840)+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2d48);
switch(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31){case 15:score+=100;break;case 17:score+=80;break;case 24:score+=60;break;case 18:score+=40;break;case 19:score+=20;break;case 22:score+=20;break;}
if(best>score)continue;
if(best==score && tie<value)continue;
best=score;tie=value;bx=x;by=y;px=pos[0];py=pos[1];
}}
if(best!=-1){M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|((u16)bx&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|(((u32)(u16)by<<26)>>20);
{u8 *rec=(u8 *)*gCurrentMap+0x6c60+M2C_FIELD(*gCurrentMap+(bx+M2C_FIELD(*gCurrentMap+by*2,u16 *,0x3758)),s8 *,0x1928)*6;rec[3]++;}
value=func_ov000_0217bd44(px,py,bx,by);
SetMapCursor((s16)px,(s16)py,8,(u8)value,0);}
sy=-1;sx=sy;uy=sy;ux=sy;best=sy;tie=best+0x8000;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
if(IsAllyUnitAtCell((s16)x,(s16)y))continue;
if(IsPropertyTerrain(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)) && M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x508))continue;
if(!FindBestAdjacentDestination(x,y,pos))continue;
kind=(u32)(unit[0]<<26)>>26;
switch(kind){
case 1:if(!(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x3250)&0x80))continue;
if(!(gAiCommandState[4]&0x20)){if(!func_ov000_0217c08c(x,y,3,dest))continue;}
else{if(!IsPropertyCell(x,y))continue;dest[0]=x;dest[1]=(s16)y;}break;
case 2:if(!(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x3250)&0x40))continue;
if(!(gAiCommandState[4]&0x20)){if(!func_ov000_0217c08c(x,y,2,dest))continue;}
else{if(!IsPropertyCell(x,y))continue;dest[0]=x;dest[1]=(s16)y;}break;
default:continue;}
if(gTerrainPropertyType[M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31] && IsTerrainOnUnitTeam(M2C_FIELD(*gCurrentMap,u8 *,0x52d4),M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)))score=0;
else score=M2C_FIELD(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8),s8 *,x);
value=M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2840)+M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x2d48);
switch(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),u8 *,0x1420)&31){case 15:score+=100;break;case 17:score+=80;break;case 24:score+=60;break;case 18:score+=40;break;case 19:score+=20;break;case 22:score+=20;break;}
if(best>score)continue;
if(best==score && tie<value)continue;
best=score;tie=value;sx=x;sy=y;ux=pos[0];uy=pos[1];tx=dest[0];ty=dest[1];
}}
if(best==-1)return;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|((u16)tx&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|(((u32)(u16)ty<<26)>>20);
{u8 *rec=(u8 *)*gCurrentMap+0x6c60+M2C_FIELD(*gCurrentMap+(tx+M2C_FIELD(*gCurrentMap+ty*2,u16 *,0x3758)),s8 *,0x1928)*6;rec[3]++;}
value=func_ov000_0217bd44(ux,uy,sx,sy);
SetMapCursor((s16)ux,(s16)uy,8,(u8)value,0);
}
#pragma opt_strength_reduction off
void func_ov000_021935c4(void *arg0) {
    extern void **gCurrentMap;
    extern u16 *gAiCommandState;
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    s32 IsPropertyCell(s32, s32);
    s32 IsAllyUnitAtCell(s16, s16);
    void PlanMoveDestination(s32, s32);
#define CURSOR_UNIT M2C_FIELD(((u8 *)*gCurrentMap), u8 **, MAP_CURSOR_UNIT)
#define CELL_MOVE(map, x, y) M2C_FIELD(M2C_FIELD((map) + (y)*4, s8 **, MAP_GRID), s8 *, (x))
#define CELL_INDEX(map, x, y) ((x) + M2C_FIELD((map) + (y)*2, u16 *, MAP_ROW_OFFSETS))
#define PROPERTY_INDEX(map, cell) M2C_FIELD((map) + (cell), s8 *, MAP_CELL_PROPERTY_INDEX)
#define PROPERTY_USE(map, index) M2C_FIELD((map) + (index)*MAP_PROPERTY_STRIDE, u8 *, MAP_PROPERTY_CELLS + MAP_PROPERTY_COUNT)
#define AI_FLAGS M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_ACTION_FLAGS)
    u8 *map, *unit, *useCount;
    u16 target;
    s32 x, y, score, cell, index;
    register s32 bestCost, bestX, bestY;

    (void)arg0;
    unit = CURSOR_UNIT;
    FloodFillUnitRange(unit[MAP_UNIT_X], unit[MAP_UNIT_Y], (u32)(unit[MAP_UNIT_KIND] << 26) >> 26, 0x6e, 0);
    map = ((u8 *)*gCurrentMap);
    target = M2C_FIELD(M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT), u16 *, MAP_UNIT_TARGET);
    x = (u32)(target << 26) >> 26;
    if (x != 63) {
        y = (u32)(target << 20) >> 26;
        if (CELL_MOVE(map, x, y) >= 0 && IsPropertyCell(x, y)) {
            map = ((u8 *)*gCurrentMap);
            index = PROPERTY_INDEX(map, CELL_INDEX(map, x, y));
            if (!PROPERTY_USE(map, index) ||
                (AI_FLAGS & AI_ACTION_SKIP_REPLAN)) {
                if (!IsAllyUnitAtCell((s16)x, (s16)y)) {
                map = ((u8 *)*gCurrentMap);
                index = PROPERTY_INDEX(map, CELL_INDEX(map, x, y));
                useCount = map + MAP_PROPERTY_CELLS + index*MAP_PROPERTY_STRIDE;
                useCount[MAP_PROPERTY_COUNT]++;
                PlanMoveDestination(x, y);
                }
            }
        }
    }

    bestX = -1;
    bestY = bestX;
    bestCost = bestX + 0x8000;
    unit = CURSOR_UNIT;
    M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) = (M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) & ~0x3f) | 0x3f;
    unit = CURSOR_UNIT;
    M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) = (M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) & ~0xfc0) | 0xfc0;

    for (y = 0; y < M2C_FIELD(((u8 *)*gCurrentMap), u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(((u8 *)*gCurrentMap), u16 *, MAP_WIDTH); x++) {
            if (CELL_MOVE(((u8 *)*gCurrentMap), x, y) < 0 || !IsPropertyCell(x, y))
                continue;
            map = ((u8 *)*gCurrentMap);
            cell = CELL_INDEX(map, x, y);
            index = PROPERTY_INDEX(map, cell);
            if (PROPERTY_USE(map, index) && !(AI_FLAGS & AI_ACTION_SKIP_REPLAN))
                continue;
            score = CELL_MOVE(map, x, y);
            switch (M2C_FIELD(map + cell, u8 *, MAP_CELL_TERRAIN) & 31) {
            case 15: break;
            case 17: score += 2; break;
            case 24: score += 2; break;
            case 18: score += 3; break;
            case 19: score += 4; break;
            case 22: score += 4; break;
            default: score += 6; break;
            }
            if (bestCost >= score) {
                bestX = x;
                bestY = y;
                bestCost = score;
            }
        }
    }
    if (bestCost == 0x7fff)
        return;
    map = ((u8 *)*gCurrentMap);
    index = PROPERTY_INDEX(map, CELL_INDEX(map, bestX, bestY));
    useCount = map + MAP_PROPERTY_CELLS + index*MAP_PROPERTY_STRIDE;
    useCount[MAP_PROPERTY_COUNT]++;
    unit = CURSOR_UNIT;
    M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) = (M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) & ~0x3f) | ((u16)bestX & 0x3f);
    unit = CURSOR_UNIT;
    M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) = (M2C_FIELD(unit, u16 *, MAP_UNIT_TARGET) & ~0xfc0) | (((u32)(u16)bestY << 26) >> 20);
    PlanMoveDestination(bestX, bestY);
#undef AI_FLAGS
#undef PROPERTY_USE
#undef PROPERTY_INDEX
#undef CELL_INDEX
#undef CELL_MOVE
#undef CURSOR_UNIT
}
#pragma opt_strength_reduction reset
/* Per-unit AI action for a kind-13 unit (the Rig) that is partway through
 * building a temporary airfield or port: the Rig must still have ammo and the
 * map must still be saveable, and its build command (24) is only issued while
 * the build is at most two turns from finishing; anything else is returned. */
u32 RunAiKind13BuildAction(void) {
extern void **gCurrentMap;
u16 flags;
u32 value;
u8 *unit;
unit=M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT);
value=(u32)(unit[MAP_UNIT_KIND]<<26)>>26; if(value!=UNIT_KIND_RIG)return value;
flags=M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH);
value=(u32)(flags<<21)>>28;
if(value==0)return flags;
value=(u32)(flags<<16)>>27;
if(value==0)return value;
value=CanSaveHiddenTerrainMap(); if(!value)return value;
{s32 turns=GetCaptureTurnsLeft(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT));if(turns>=3)return turns;}
unit=M2C_FIELD(*gCurrentMap,u8 **,MAP_CURSOR_UNIT);
return SetMapCursor(unit[MAP_UNIT_X],unit[MAP_UNIT_Y],24,0,0);
}

s32 func_ov000_02193a40(s32 inputX, s32 inputY, s32 shoalMode) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    u8 IsPropertyTerrain(s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    u8 SelectEnemyHqDestination(s16 *);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 i, offset, player, best = 0x7fff;
    u8 *map = *gCurrentMap;
    u8 *property;
    s16 coords[2];
    volatile s32 x = inputX, y = inputY;
    s16 tileX, tileY;

    i = gPlayerUnitIdBase[M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)] + 1;
    if (i < gPlayerUnitIdBase[M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)] + 0x33) {
        offset = i * MAP_UNIT_STRIDE;
        tileX = (s16)x; tileY = (s16)y;
        do {
        BattleMapUnitHead *unit = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS + offset);
        u32 kind = unit->kind;
        u16 row;
        u32 terrain;
        s32 distance;
        if (kind == 0 || kind != UNIT_KIND_RIG)
            continue;
        if (unit->facing == 0)
            continue;
        row = M2C_FIELD(map + y * 2,u16 *,MAP_ROW_OFFSETS);
        terrain = M2C_FIELD(map + x + row,u8 *,MAP_CELL_TERRAIN) & MAP_TERRAIN_KIND_MASK;
        if ((terrain == 1 && shoalMode == 0) || (terrain == 9 && shoalMode != 0))
            continue;
        distance = ManhattanDistance(tileX, tileY, unit->x, unit->y);
        if (best > distance)
            best = distance;
        } while (++i, offset += MAP_UNIT_STRIDE, map = *gCurrentMap,
                 i < gPlayerUnitIdBase[M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)] + 0x33);
    }

    property = map + MAP_PROPERTY_CELLS;
    if (property[0] != 0xff) {
      tileX = (s16)x; tileY = (s16)y;
      do {
        u16 row;
        s32 distance;
        map = *gCurrentMap;
        row = M2C_FIELD(map + property[2] * 2,u16 *,MAP_ROW_OFFSETS);
        if (IsPropertyTerrain(M2C_FIELD(map + property[1] + row,u8 *,MAP_CELL_TERRAIN)))
            continue;
        if ((shoalMode != 0 && (property[0] == 0x12 || property[0] == 0x14)) ||
            (shoalMode == 0 && (property[0] == 0x13 || property[0] == 0x15))) {
            distance = ManhattanDistance(tileX, tileY, property[1], property[2]);
            if (best > distance)
                best = distance;
        }
      } while ((property += 6)[0] != 0xff);
    }

    if (best == 0x7fff) {
        if (SelectEnemyHqDestination(coords)) {
            best = 0x7fff - ManhattanDistance((s16)x, (s16)y, coords[0], coords[1]);
        } else {
            for (player = 1; player < 5; player++) {
                if (!IsPlayerActive(player) || IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER), player))
                    continue;
                tileX = (s16)x; tileY = (s16)y;
                for (i = gPlayerUnitIdBase[player] + 1, offset = i * MAP_UNIT_STRIDE;
                     i < gPlayerUnitIdBase[player] + 0x33; i++, offset += MAP_UNIT_STRIDE) {
                    BattleMapUnitHead *unit = (BattleMapUnitHead *)((u8 *)*gCurrentMap + offset + MAP_UNIT_RECORDS);
                    if (unit->kind != 0) {
                        s32 distance = ManhattanDistance((s16)x, (s16)y, property[1], property[2]);
                        if (best > distance)
                            best = distance;
                    }
                }
            }
        }
    }
    return best;
}

