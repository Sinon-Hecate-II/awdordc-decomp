/* 4 functions from 0x02192D88 to 0x02193D6C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

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
u32 func_ov000_02193998(void) {
extern void **data_027e0058;
u16 flags;
u32 x;
u8 *p;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
x=(u32)(p[0]<<26)>>26; if(x!=13)return x;
flags=*(u16 *)(p+6);
x=(u32)(flags<<21)>>28;
if(x==0)return flags;
x=(u32)(flags<<16)>>27;
if(x==0)return x;
x=CanSaveHiddenTerrainMap(); if(!x)return x;
{s32 v=GetCaptureTurnsLeft(M2C_FIELD(*data_027e0058,void **,0x52d0));if(v>=3)return v;}
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
return SetMapCursor(p[1],p[2],24,0,0);
}

s32 func_ov000_02193a40(s32 arg0, s32 arg1, s32 arg2) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    u8 IsPropertyTerrain(s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    u8 SelectEnemyHqDestination(s16 *);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s16 x, y;
    s32 i, best = 0x7fff;
    u8 *base, *rec, *rec7;
    u16 start;
    s16 coords[2];
    x = (s16)arg0;
    y = (s16)arg1;
    base = (u8 *)*gCurrentMap;
    start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < start + 0x33; i++) {
        rec = base + 0x59a4 + i * 14;
        {
            u8 kind = rec[0] & 0x3f;
            u16 flags;
            u8 t;
            u16 row;
            if (kind == 0) continue;
            if (kind != 0xd) continue;
            flags = M2C_FIELD(rec, u16 *, 6);
            if (!((flags >> 11) & 0x1f)) continue;
            row = M2C_FIELD(base + arg1 * 2, u16 *, 0x3758);
            t = M2C_FIELD(base, u8 *, 0x1420 + arg0 + row) & 0x1f;
            if (t == 1) {
                if (arg2 == 0) continue;
            } else if (t == 9) {
                if (arg2 != 0) continue;
            }
            {
                s32 d = ManhattanDistance(x, y, rec[1], rec[2]);
                if (d < best) best = d;
            }
        }
    }
    rec = base + 0x6c60;
    rec7 = rec;
    while (rec[0] != 0xff) {
        u8 kind = rec[0];
        u8 rx = rec[1];
        u8 ry = rec[2];
        u16 row;
        u8 t;
        row = M2C_FIELD(base + ry * 2, u16 *, 0x3758);
        t = M2C_FIELD(base, u8 *, 0x1420 + rx + row) & 0x1f;
        (void)t;
        if (!IsPropertyTerrain(M2C_FIELD(base, u8 *, 0x1420 + rx + row))) {
            s32 d;
            if (arg2 != 0) {
                if (kind != 0x12 && kind != 0x14) {
                    rec += 6;
                    continue;
                }
            } else {
                if (kind != 0x13 && kind != 0x15) {
                    rec += 6;
                    continue;
                }
            }
            d = ManhattanDistance(x, y, rx, ry);
            if (d < best) best = d;
        }
        rec += 6;
    }
    rec7 = rec;
    if (best != 0x7fff) {
        goto done_func;
    }
    {
        s16 c0, c1;
        if (SelectEnemyHqDestination(coords)) {
            best = 0x7fff - ManhattanDistance(x, y, coords[0], coords[1]);
        } else {
            s32 player;
            for (player = 1; player < 5; player++) {
                if (!IsPlayerActive(player)) continue;
                if (IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), player) != 0) continue;
                {
                    u16 start2 = gPlayerUnitIdBase[player];
                    s32 i2;
                    for (i2 = start2 + 1; i2 < start2 + 0x33; i2++) {
                        u8 *rec2 = base + 0x59a4 + i2 * 14;
                        u8 kind2 = rec2[0] & 0x3f;
                        if (kind2 == 0) continue;
                        {
                            s32 d = ManhattanDistance(x, y, rec2[1], rec2[2]);
                            if (d < best) best = d;
                        }
                    }
                }
            }
        }
    }
done_func:
    return best;
}

