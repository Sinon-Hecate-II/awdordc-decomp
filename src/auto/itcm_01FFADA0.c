/* 12 functions from 0x01FFADA0 to 0x01FFBD90 (itcm), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

static inline s16 SearchMovementFlags(s8 *state) { return M2C_FIELD(state,s16*,0x22); }
static inline u8 *SearchPlayerRecords(void *map) { return (u8*)map+0x67a4; }
static inline s32 RejectSearchCell(s8 *state,u8 *map,s32 x,s32 y) {
s32 index;u32 cell;s32 owner;u8 *unit;u16 unitFlags;
if(M2C_FIELD(state,s16*,0x22)&13){
index=x+M2C_FIELD(map+y*2,u16*,0x3758);cell=map[index];
if(cell){
if(M2C_FIELD(state,s16*,0x22)&2){if(!((u8)(M2C_FIELD(map+((u32)index>>3),u8*,0x5160)&(1<<(index&7))))){
if(!((u32)(M2C_FIELD(map+cell*14,u8*,0x59af)<<25)>>31))return 0;
}}
owner=((s32)cell>>6)+1;
if((u8)state[0x26]==M2C_FIELD(SearchPlayerRecords(map)+owner*140,u8*,0x26))return 0;
unit=map+0x59a4+cell*14;unitFlags=M2C_FIELD(unit,u16*,4);
if(unitFlags&32){
if((unitFlags&128)&&(M2C_FIELD(SearchPlayerRecords(map)+M2C_FIELD(map,u16*,0x52b6)*140,u8*,0x1f)&2))goto unit_checks;
if(!(unitFlags&64))return 0;
if(!(M2C_FIELD(SearchPlayerRecords(map)+M2C_FIELD(map,u16*,0x52b6)*140,u8*,0x1f)&1))return 0;
}
unit_checks:
if((M2C_FIELD(state,s16*,0x22)&1)||M2C_FIELD(map,u16*,0x52a4)!=owner)return 1;
if((M2C_FIELD(state,s16*,0x22)&4)&&(unitFlags&1))return 1;
if((M2C_FIELD(state,s16*,0x22)&8)&&((u32)(unit[10]<<24)>>31))return 1;
}}

return 0;
}
typedef struct PlayerArmyBits { u32 army : 8; u32 rest : 24; } PlayerArmyBits;

/* Flood-fill the tiles a unit of `kind` at (x,y) can reach within the cost
 * budget `value`: seed the two ping-pong search queues, write the accumulated
 * cost into the map's per-cell score layer and expand each node into its
 * neighbours. `moveRange` carries the search's behaviour flags. */
void FloodFillUnitRange(s32 x, s32 y, s32 kind, s32 value, s32 moveRange) {
    extern void **gCurrentMap;
    extern s8 *gMoveSearchState;
    extern s32 gMoveSearchCount;
    extern s8 gMoveSearchBuffer;
    extern void *gMoveSearchWrite;
    extern void *gMoveSearchCurrent;
    extern u8 gMovementTypeTable[];
    void FillMapLayer(s8);
    void LoadUnitMovementCosts(s32);
    void func_01ffb50c(s32);
    void func_01ffb114(s32, s32, s32);
    s32 func_020a85b8(s32);
    s8 *base;
    MoveSearchNode *node;

    base = gMoveSearchState;
    gMoveSearchCount = 0;
    gMoveSearchBuffer = 0;
    gMoveSearchWrite = base + MOVE_SEARCH_QUEUE_A;
    gMoveSearchCurrent = base + MOVE_SEARCH_QUEUE_B;
    M2C_FIELD(base, u16 *, MOVE_SEARCH_COST_LIMIT) = (u16)value;
    M2C_FIELD(gMoveSearchState, u16 *, MOVE_SEARCH_MOVE_RANGE) = (u16)moveRange;

    M2C_FIELD((u8 *)gMoveSearchState, u8 *, MOVE_SEARCH_MOVEMENT_TYPE) =
        M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, 0x52b6) * 0x8c, u8 *, 0x67ca);

    if (kind < 0x1b) {
        if (func_020a85b8(kind)) {
            M2C_FIELD(gMoveSearchState, s16 *, MOVE_SEARCH_MOVE_RANGE) &= ~0xd;
        }
        if (gMovementTypeTable[kind * 0x70] == 6) {
            if (!(M2C_FIELD(gMoveSearchState, s16 *, MOVE_SEARCH_MOVE_RANGE) & 0x20)) {
                M2C_FIELD(gMoveSearchState, s16 *, MOVE_SEARCH_MOVE_RANGE) |= 0x10;
            }
        }
        FillMapLayer(-1);
        LoadUnitMovementCosts(kind);
    } else {
        FillMapLayer(-1);
        func_01ffb50c(kind);
    }

    ((MoveSearchNode *)gMoveSearchWrite)->x = (u8)x;
    ((MoveSearchNode *)gMoveSearchWrite)->y = (u8)y;
    ((MoveSearchNode *)gMoveSearchWrite)->dir = MOVE_SEARCH_DIR_START;
    ((MoveSearchNode *)gMoveSearchWrite)->cost = 0;
    M2C_FIELD(*(u8 **)((u8 *)*gCurrentMap + 0x52e8 + y * 4), u8 *, x) = 0;
    gMoveSearchWrite = (u8 *)gMoveSearchWrite + 4;
    ((MoveSearchNode *)gMoveSearchWrite)->dir = 0;

    for (;;) {
        if (!gMoveSearchBuffer) {
            base = gMoveSearchState;
            gMoveSearchWrite = (u8 *)base + MOVE_SEARCH_QUEUE_B;
            gMoveSearchCurrent = (u8 *)base + MOVE_SEARCH_QUEUE_A;
            gMoveSearchBuffer = 1;
            gMoveSearchCount = 0;
        } else {
            base = gMoveSearchState;
            gMoveSearchWrite = (u8 *)base + MOVE_SEARCH_QUEUE_A;
            gMoveSearchCurrent = (u8 *)base + MOVE_SEARCH_QUEUE_B;
            gMoveSearchBuffer = 0;
            gMoveSearchCount = 0;
        }
        node = gMoveSearchCurrent;
        if (node->dir == 0) break;
        while (node->dir != 0) {
            switch (node->dir) {
            case MOVE_SEARCH_DIR_START:
                func_01ffb114(MOVE_SEARCH_DIR_UP, 0, 0xff); func_01ffb114(MOVE_SEARCH_DIR_DOWN, 0, 1);
                func_01ffb114(MOVE_SEARCH_DIR_LEFT, 0xff, 0); func_01ffb114(MOVE_SEARCH_DIR_RIGHT, 1, 0);
                break;
            case MOVE_SEARCH_DIR_UP:
                func_01ffb114(MOVE_SEARCH_DIR_UP, 0, 0xff); func_01ffb114(MOVE_SEARCH_DIR_LEFT, 0xff, 0);
                func_01ffb114(MOVE_SEARCH_DIR_RIGHT, 1, 0);
                break;
            case MOVE_SEARCH_DIR_DOWN:
                func_01ffb114(MOVE_SEARCH_DIR_DOWN, 0, 1); func_01ffb114(MOVE_SEARCH_DIR_LEFT, 0xff, 0);
                func_01ffb114(MOVE_SEARCH_DIR_RIGHT, 1, 0);
                break;
            case MOVE_SEARCH_DIR_LEFT:
                func_01ffb114(MOVE_SEARCH_DIR_UP, 0, 0xff); func_01ffb114(MOVE_SEARCH_DIR_DOWN, 0, 1);
                func_01ffb114(MOVE_SEARCH_DIR_LEFT, 0xff, 0);
                break;
            case MOVE_SEARCH_DIR_RIGHT:
                func_01ffb114(MOVE_SEARCH_DIR_UP, 0, 0xff); func_01ffb114(MOVE_SEARCH_DIR_DOWN, 0, 1);
                func_01ffb114(MOVE_SEARCH_DIR_RIGHT, 1, 0);
                break;
            }
            ((MoveSearchNode *)gMoveSearchWrite)->dir = 0;
            gMoveSearchCurrent = (u8 *)gMoveSearchCurrent + 4;
            node = gMoveSearchCurrent;
        }
    }
}

void func_01ffb114(s32 arg0,s32 arg1,s32 arg2) {
extern void *gMoveSearchCurrent,*gMoveSearchWrite;extern s8 *gMoveSearchState;extern void **gCurrentMap;extern s8 data_ov000_021b55c0[];extern s32 gMoveSearchCount;
s32 IsPropertyOwnedByTeam(s32,s32,s32);
s16 cost;
u32 qx=((MoveSearchNode*)gMoveSearchCurrent)->x,qy=((MoveSearchNode*)gMoveSearchCurrent)->y;
s8 *initState=gMoveSearchState; s8 *state;u8 *map,*unit;s32 index;u32 cell;s32 owner,kind; s32 flags;u16 unitFlags;
arg1=(u8)(arg1+qx);arg2=(u8)(arg2+qy);
if((u32)arg1>=(u8)initState[0x24]||(u32)arg2>=(u8)initState[0x25])return;
map=*gCurrentMap;flags=M2C_FIELD(initState,s16*,0x22);
kind=M2C_FIELD(map+(arg1+M2C_FIELD(map+arg2*2,u16*,0x3758)),u8*,0x1420)&31;
cost=(s16)(M2C_FIELD(map+qy*4,s8**,0x52e8)[qx]+(u8)initState[kind]);
if((flags&16)&&data_ov000_021b55c0[kind] && !IsPropertyOwnedByTeam(M2C_FIELD(map,u16*,0x52b6),arg1,arg2))cost=255;
map=*gCurrentMap;
if(cost>=M2C_FIELD(map+arg2*4,u8**,0x52e8)[arg1])return;
state=gMoveSearchState;
if(M2C_FIELD(state,s16*,0x22)&13){
index=arg1+M2C_FIELD(map+arg2*2,u16*,0x3758);cell=map[index];
if(cell){
if(M2C_FIELD(state,s16*,0x22)&2){if(!((u8)(M2C_FIELD(map+((u32)index>>3),u8*,0x5160)&(1<<(index&7))))){
if(!((u32)(M2C_FIELD(map+cell*14,u8*,0x59af)<<25)>>31))goto enqueue;
}}
owner=((s32)cell>>6)+1;
if((u8)state[0x26]==M2C_FIELD(SearchPlayerRecords(map)+owner*140,u8*,0x26))goto enqueue;
unit=map+0x59a4+cell*14;unitFlags=M2C_FIELD(unit,u16*,4);
if(unitFlags&32){
if((unitFlags&128)&&(M2C_FIELD(SearchPlayerRecords(map)+M2C_FIELD(map,u16*,0x52b6)*140,u8*,0x1f)&2))goto unit_checks;
if(!(unitFlags&64))goto enqueue;
if(!(M2C_FIELD(SearchPlayerRecords(map)+M2C_FIELD(map,u16*,0x52b6)*140,u8*,0x1f)&1))goto enqueue;
}
unit_checks:
if((M2C_FIELD(state,s16*,0x22)&1)||M2C_FIELD(map,u16*,0x52a4)!=owner)return;
if((M2C_FIELD(state,s16*,0x22)&4)&&(unitFlags&1))return;
if((M2C_FIELD(state,s16*,0x22)&8)&&((u32)(unit[10]<<24)>>31))return;
}}
enqueue:
if(cost>M2C_FIELD(state,s16*,0x20)||gMoveSearchCount>=349)return;
gMoveSearchCount++;
((MoveSearchNode*)gMoveSearchWrite)->x=arg1;((MoveSearchNode*)gMoveSearchWrite)->y=arg2;((MoveSearchNode*)gMoveSearchWrite)->dir=arg0;M2C_FIELD(gMoveSearchWrite,s8*,3)=cost;
gMoveSearchWrite=(u8*)gMoveSearchWrite+4;
M2C_FIELD((u8*)*gCurrentMap+arg2*4,u8**,0x52e8)[arg1]=cost;
}

/* Fill every cell of the map's grid value layer (MAP_GRID) with `value`. */
void FillMapLayer(s8 value) {
    extern void **gCurrentMap;
    s32 y = 0, x;
    void *base = *gCurrentMap;
    for (; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++) {
            ((s8 **)base)[y + MAP_GRID_ROW_INDEX][x] = value;
            base = *gCurrentMap;
        }
    }
}

/* Copy the 32 per-terrain movement costs unit kind `kind` pays under the
 * active player's army and weather into the movement search's cost table.
 * Maps that leave army-specific movement off use army 0's table. */
void LoadUnitMovementCosts(s32 kind) {
extern u8 gUnitKindStats[]; extern u8 gMovementCostTable[]; extern s8 *gMoveSearchState; extern void **gCurrentMap; extern u8 gMapData[];
s32 GetPlayerArmyVariant(s32);
s32 i; u8 *stats=gUnitKindStats+kind*UNIT_KIND_STATS_SIZE;
for(i=0;i<32;i++) {
void *map=*gCurrentMap;
s32 player=M2C_FIELD(map,u16 *,MAP_ACTIVE_PLAYER);
u8 *record=(u8 *)map+MAP_PLAYER_STATES+player*MAP_PLAYER_STRIDE;
u32 armyId;
s32 variant;
s8 *costs;
if (((u32)(M2C_FIELD(gMapData,u16 *,MAPDATA_RULES)<<18)>>31) == 0) {
    armyId = 0;
} else {
    armyId = ((PlayerArmyBits *)(record+PLAYER_REC_SPRITE))->army;
}
variant=GetPlayerArmyVariant(player);
costs=M2C_FIELD(gMovementCostTable+armyId*ARMY_DATA_SIZE+variant*ARMY_DATA_VARIANT_STRIDE+record[PLAYER_REC_MOVE_COST_ROW]*ARMY_DATA_ROW_STRIDE,s8 **,ARMY_DATA_MOVE_COSTS);
gMoveSearchState[i]=(costs+stats[UNIT_KIND_STATS_MOVETYPE]*32)[i];
}
}

#pragma opt_peephole off
void func_01ffb50c(s32 arg0) {
extern s8 data_ov000_021b54e0[];
extern s8 *gMoveSearchState;
s32 i;
for(i=0;i<32;i++) {
 s32 value=data_ov000_021b54e0[i];
 if(value) gMoveSearchState[i]=1; else ((u8*)gMoveSearchState)[i]=255;
}
}
#pragma opt_peephole reset
/* Point the movement search at a per-cell byte layer of the map: MAP_GRID's row
 * pointers (+0x52e8, one s32 per row) are set to `layer` plus the map's per-row
 * offsets (MAP_ROW_OFFSETS, +0x3758, one u16 per row), and the search state
 * records the map's width and height. */
void SelectMapLayer(s32 layer) {
    extern void **gCurrentMap;
    extern s8 *gMoveSearchState;
    s32 i = 0;
    void *map = *gCurrentMap;

    for (; i < M2C_FIELD(map, u16 *, MAP_HEIGHT); i++) {
        ((s32 *)map)[i + 0x14ba] = layer + ((u16 *)map)[i + 0x1bac];
        map = *gCurrentMap;
    }
    gMoveSearchState[MOVE_SEARCH_WIDTH] = M2C_FIELD(map, u16 *, MAP_WIDTH);
    gMoveSearchState[MOVE_SEARCH_HEIGHT] = M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT);
}

void FillMapGridDiamondByRows(s32 cx,s32 cy,s32 radius,s8 value){
extern void **gCurrentMap;
s32 y,x,end,d,w;void *base;
d=radius;
for(y=cy;y<=cy+radius;y++,d--){
base=*gCurrentMap;if(y>=M2C_FIELD(base,u16 *,0x5146))break;
w=d*2+1;x=cx-d;if(x<0){w+=x;x=0;}
end=x+w;if(end>M2C_FIELD(base,u16 *,0x5144))end=M2C_FIELD(base,u16 *,0x5144);
for(;x<end;x++)((s8 **)*gCurrentMap)[y+0x14ba][x]=value;
}
d=radius-1;
for(y=cy-1;y>=cy-radius;y--,d--){
if(y<0)break;
base=*gCurrentMap;w=d*2+1;x=cx-d;if(x<0){w+=x;x=0;}
w=x+w;if(w>M2C_FIELD(base,u16 *,0x5144))w=M2C_FIELD(base,u16 *,0x5144);
for(;x<w;x++)((s8 **)*gCurrentMap)[y+0x14ba][x]=value;
}
}

#pragma common_subs off
void func_01ffb734(int cx,int cy,int radius,s8 value) {
 extern void **data_027e0058;
 int x,d,right,bottom,left,top; void *base=*data_027e0058;
 left=cx-radius;if(left<0)left=0;top=cy-radius;if(top<0)top=0;
 right=M2C_FIELD(base,u16 *,0x5144)-1;if(cx+radius<right)right=cx+radius;
 bottom=M2C_FIELD(base,u16 *,0x5146)-1;if(cy+radius<bottom)bottom=cy+radius;
 for(;top<=bottom;top++)for(x=left;x<=right;x++){
 d=0;
 if(cx-x>0)d+=cx-x;else d+=x-cx;
 if(cy-top>0)d+=cy-top;else d+=top-cy;
 if(d>=0 && d<=radius)((s8 **)*data_027e0058)[top+0x14ba][x]=value;
 }
}
#pragma common_subs reset
/* Write `value` along the line an order covers, downward from (x, y) in the map's
 * selected cell layer: direction 0 steps down-left, 2 down-right, 1 and 3 straight
 * down; it stops at the map's left/right or bottom edge. */
void FillMapLine(s32 x, s32 y, s32 direction, s8 value) {
    extern void **gCurrentMap;
    switch (direction) {
    case 0:
        --x;
        ++y;
        goto check_left;
    left:
        ((s8 **)*gCurrentMap)[y++ + MAP_GRID_ROW_INDEX][x] = value;
        --x;
    check_left:
        if (x < 0) return;
        if (y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) goto left;
        return;
    case 1:
    case 3:
        for (++y; y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT);)
            *(x + ((s8 **)*gCurrentMap)[y++ + MAP_GRID_ROW_INDEX]) = value;
        return;
    case 2:
        ++x;
        ++y;
        goto check_right;
    right:
        ((s8 **)*gCurrentMap)[y++ + MAP_GRID_ROW_INDEX][x] = value;
        ++x;
    check_right:
        if (x < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) &&
            y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT)) goto right;
        return;
    default:
        return;
    }
}

/* Paint `value` down every row of the map's selected cell layer in the column
 * band centred on x: three columns wide, five when `wide` is set, clamped to the
 * map's width.  y and right are ignored. */
void FillMapColumn(s32 x,s32 y,s32 right,s8 value,u8 wide) {
extern void **gCurrentMap;
s32 radius=1,left,column; void *base;
if(wide) radius+=2;
left=x-radius; right=x+radius;
if(left<0) left=0;
base=*gCurrentMap;
if(right>M2C_FIELD(base,u16 *,MAP_WIDTH)-1) right=M2C_FIELD(base,u16 *,MAP_WIDTH)-1;
for(x=0;x<M2C_FIELD(base,u16 *,MAP_HEIGHT);x++) {
for(column=left;column<=right;column++) {
((s8 **)*gCurrentMap)[x+MAP_GRID_ROW_INDEX][column]=value;
}
base=*gCurrentMap;
}
}

/* Paint `mark` onto every still-unvisited (negative) orthogonal neighbour of a
   cell that already holds a non-negative value other than `mark` itself. */
void MarkAdjacentCells(s8 mark){
extern void **gCurrentMap;
s32 y,x;void *map=*gCurrentMap;
for(y=0;y<M2C_FIELD(map,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(map,u16*,0x5144);x++){
s8 *cell=((s8**)map)[y+0x14ba]+x;
if(*cell>=0 && mark!=*cell){
if(x!=0 && cell[-1]<0)cell[-1]=mark;
map=*gCurrentMap;
if(x!=M2C_FIELD(map,u16*,0x5144)-1){
cell=((s8**)map)[y+0x14ba]+x;
if(cell[1]<0)cell[1]=mark;
}
if(y!=0){cell=((s8**)*gCurrentMap)[y+0x14b9];if(cell[x]<0)cell[x]=mark;}
map=*gCurrentMap;
if(y!=M2C_FIELD(map,u16*,0x5146)-1){cell=((s8**)map)[y+0x14bb];if(cell[x]<0)cell[x]=mark;}
}
map=*gCurrentMap;
}
}
}

/* Extend the movement-range overlay: for every cell the flood fill reached, bump
 * its four neighbours into the range and flag them taken; then drop every cell
 * that was not flagged (set it to -1, impassable). */
void MarkUnitMoveRangeCells(void) {
    extern void **gCurrentMap;
    u8 y, x;

    for (y = 0; y < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            u8 *map = *gCurrentMap;
            s8 *cell = M2C_FIELD(map + y * 4, s8 **, MAP_GRID) + x;
            s8 cost = *cell;

            if (cost < 0 || cost == MAP_GRID_TAKEN) continue;
            if (cost != 0 && map[MAP_CELL_VISIBLE_UNIT + x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)] != 0) continue;

            if (x != 0 && cell[-1] != MAP_GRID_TAKEN) {
                cell[-1]++;
                (M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID) + x)[-1] |= MAP_GRID_TAKEN;
            }
            if (x != M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) - 1) {
                s8 *right = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID) + x;
                if (right[1] != MAP_GRID_TAKEN) {
                    right[1]++;
                    (M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID) + x)[1] |= MAP_GRID_TAKEN;
                }
            }
            if (y != 0) {
                s8 *above = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID - 4);
                if (above[x] != MAP_GRID_TAKEN) {
                    above[x]++;
                    M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID - 4)[x] |= MAP_GRID_TAKEN;
                }
            }
            if (y != M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT) - 1) {
                s8 *below = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID + 4);
                if (below[x] != MAP_GRID_TAKEN) {
                    below[x]++;
                    M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID + 4)[x] |= MAP_GRID_TAKEN;
                }
            }
        }
    }
    for (y = 0; y < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < (s32)M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH); x++) {
            s8 *row = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID);
            if (!(row[x] & MAP_GRID_TAKEN)) row[x] = -1;
        }
    }
}

