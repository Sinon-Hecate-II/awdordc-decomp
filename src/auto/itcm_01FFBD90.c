/* 10 functions from 0x01FFBD90 to 0x01FFC778 (itcm), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* Fill a diamond (Manhattan circle) of the given radius centered at (x,y)
   in the map occupancy grid with value. */
#pragma opt_strength_reduction off
/* Mark, for the unit arg0, every cell its attack can reach: for each cell holding
   no unit (or the cursor's 0x40 marker) the cells within the kind's attack range
   (and at least its minimum range) get their grid value incremented and flagged
   0x40 (taken); every unflagged cell is then reset to -1 (unreachable). */
void MarkUnitAttackRangeCells(u8 *arg0) {
 extern void **gCurrentMap;
 extern u8 gUnitKindStats[];
 s32 GetUnitAttackRangeMax(u8 *);
 s16 x,y;
 s32 left,top,right,bottom,xx,yy,d,range;
 u16 *bounds;
 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++) {
  for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++) {
   s32 v=M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x];
   if(v<0 || v==0x40) continue;
   if(v!=0 && ((u8 *)*gCurrentMap+x)[M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758)]!=0) continue;
   left=x-GetUnitAttackRangeMax(arg0)<0?0:x-GetUnitAttackRangeMax(arg0);
   top=y-GetUnitAttackRangeMax(arg0)<0?0:y-GetUnitAttackRangeMax(arg0);
   bounds=(u16 *)(*gCurrentMap+0x5120); range=GetUnitAttackRangeMax(arg0);
  if(x+range>=bounds[0x12]-1) right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1; else right=x+GetUnitAttackRangeMax(arg0);
   bounds=(u16 *)(*gCurrentMap+0x5120); range=GetUnitAttackRangeMax(arg0);
  if(y+range>=bounds[0x13]-1) bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1; else bottom=y+GetUnitAttackRangeMax(arg0);
   for(yy=top;yy<=bottom;yy++) for(xx=left;xx<=right;xx++) {
    d=0;
    if(x-xx>0) d+=x-xx; else d+=xx-x;
    if(y-yy>0) d+=y-yy; else d+=yy-y;
    if(d<gUnitKindStats[((u32)(arg0[0]<<26)>>26)*0x70+0xc] || d>GetUnitAttackRangeMax(arg0)) continue;
    if(M2C_FIELD(*gCurrentMap+yy*4,s8 **,0x52e8)[xx]>=0 && (M2C_FIELD(*gCurrentMap+yy*4,s8 **,0x52e8)[xx]&0x40)) continue;
    M2C_FIELD(*gCurrentMap+yy*4,s8 **,0x52e8)[xx]++;
    M2C_FIELD(*gCurrentMap+yy*4,s8 **,0x52e8)[xx]|=0x40;
   }
  }
 }
 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++) for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++)
 if(!(M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x]&0x40)) M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x]=-1;
}
#pragma opt_strength_reduction on
void FillMapGridDiamond(s16 x, s16 y, s16 radius, s32 value) {
    extern void **gCurrentMap;
    s16 dy, row, col;
    for (dy = -radius, row = y - radius; row <= y + radius; row++, dy++) {
        if (row >= 0 && row < M2C_FIELD(*gCurrentMap, u16 *, 0x5146)) {
            for (col = x - radius + (dy < 0 ? -dy : dy); col <= x + radius - (dy < 0 ? -dy : dy); col++) {
                if (col >= 0 && col < M2C_FIELD(*gCurrentMap, u16 *, 0x5144)) {
                    ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[row][col] = (s8) value;
                }
            }
        }
    }
}

/* Marks the cells a unit at (x,y) can attack: fill its maximum attack range in
 * the map grid with the taken bit, then clear everything closer than its minimum
 * range so only the ring between the two ranges stays marked. */
void MarkUnitAttackRing(s32 x, s32 y, u8 *unit) {
    void FillMapGridDiamond(s16, s16, s16, s32);
    s32 GetUnitAttackRangeMax(u8 *);
    extern u8 gUnitMinAttackRange;
    FillMapGridDiamond((s16)x, (s16)y, (s16)GetUnitAttackRangeMax(unit), MAP_GRID_TAKEN);
    if (GetUnitAttackRangeMax(unit) == 1) return;
    FillMapGridDiamond((s16)x, (s16)y, (s16)(*(&gUnitMinAttackRange + (((u32)(*unit << 26) >> 26) * 0x70)) - 1), -1);
}

void FloodFillUnitRangeForPlayer(s16 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern void **gCurrentMap;
    void *temp_r0;

    M2C_FIELD(*gCurrentMap, s16 *, 0x52B6) = arg0;
    FloodFillUnitRange(arg1, arg2, arg3, arg4, arg5);
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0, u16 *, 0x52B6) = (u16) M2C_FIELD(temp_r0, u16 *, 0x52A4);
}

void func_01ffc2e8(void *arg0) {
s32 GetUnitRemainingMoveRange(void);
M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
s16 value=GetUnitRemainingMoveRange();
FloodFillUnitRange(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26,value,1);
}

void BuildUnitMoveRange(void *arg0) {
s32 GetUnitRemainingMoveRange(void);
M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
s16 value=GetUnitRemainingMoveRange();
FloodFillUnitRange(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26,value,3);
}

/* Marks the cells the unit at (x, y) can attack in the map grid: fills its whole
   maximum-range diamond with 0, then sets the cells inside its minimum range
   back to -1 so only the ring between the two ranges stays marked. */
void MarkUnitAttackRingCells(s32 x, s32 y, u8 *unit) {
    void FillMapGridDiamondByRows(u16, u16, u16, s32);
    s32 GetUnitAttackRangeMax(u8 *);
    extern u8 gUnitMinAttackRange;
    FillMapGridDiamondByRows((u16)x, (u16)y, (u16)GetUnitAttackRangeMax(unit), 0);
    FillMapGridDiamondByRows((u16)x, (u16)y, (u16)(*(&gUnitMinAttackRange + (((u32)(*unit << 26) >> 26) * UNIT_KIND_STATS_SIZE)) - 1), -1);
}

/* Clears the movement-direction marker of each of the four tiles beside (x, y)
 * in the map's per-row direction grid, skipping the ones that fall off the map. */
void ClearAdjacentMoveDirs(s32 x, s32 y) {
    extern void **gCurrentMap;
    if (x > 0) M2C_FIELD(*gCurrentMap + y * 4, u8 **, MAP_GRID)[x - 1] = 0;
    if (x < M2C_FIELD(*gCurrentMap, u16 *, MAP_WIDTH) - 1) M2C_FIELD(*gCurrentMap + y * 4, u8 **, MAP_GRID)[x + 1] = 0;
    if (y > 0) M2C_FIELD(*gCurrentMap + (y - 1) * 4, u8 **, MAP_GRID)[x] = 0;
    if (y < M2C_FIELD(*gCurrentMap, u16 *, MAP_HEIGHT) - 1) M2C_FIELD(*gCurrentMap + (y + 1) * 4, u8 **, MAP_GRID)[x] = 0;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
/* Trace a path of movement directions from tile (x,y). At each step it reads the
 * direction stored in the map's per-row direction grids (0x52e8 for the current
 * row, 0x52e4/0x52ec for the row above/below, plus the neighbour cells for
 * left/right), picks the direction with the lowest cost and breaks ties with a
 * random pick, records it in dirPath, and advances. Stops when the current cell's
 * direction is 0; then reverses the recorded turn list and caps it with 4
 * (ReverseMovePath). The starting cell's direction is also copied to map+0x52d5. */
void func_01ffc4b8(s32 x, s32 y, s8 *dirPath) {
    void ReverseMovePath(s8 *, s8 *);
    extern void **gCurrentMap;
    s32 NextRandomValue(void);
    s8 *start;
    s16 dirs[4];
    s16 costs[4];
    s32 i;
    s32 min;
    s32 dir;
    s16 count;
    s32 map;
    s8 *row;
    start = dirPath;
    M2C_FIELD(*gCurrentMap, s8 *, 0x52d5) = M2C_FIELD(*gCurrentMap + y * 4, s8 **, 0x52e8)[x];
    dir = 0;
    map = (s32)*gCurrentMap;
    row = M2C_FIELD(map + (y << 2), s8 **, 0x52e8) + x;
    while (*row != 0) {
        if (x + 1 == M2C_FIELD(map, u16 *, 0x5144)) costs[0] = 255;
        else costs[0] = (u8)row[1];
        if (x == 0) costs[1] = 255;
        else costs[1] = (u8)row[-1];
        if (y + 1 == M2C_FIELD(map, u16 *, 0x5146)) costs[3] = 255;
        else costs[3] = M2C_FIELD(map + y * 4, u8 **, 0x52ec)[x];
        if (y == 0) costs[2] = 255;
        else costs[2] = M2C_FIELD(map + y * 4, u8 **, 0x52e4)[x];
        count = 0;
        min = 256;
        for (i = 0; i < 4; i++) {
            if (min > costs[i]) min = costs[i];
        }
        for (i = 0; i < 4; i++) {
            if (min == costs[i]) dirs[count++] = i;
        }
        switch (count) {
        case 1: dir = dirs[0]; break;
        case 2: dir = dirs[(NextRandomValue() >> 14) & 1]; break;
        case 3: dir = dirs[NextRandomValue() % 3]; break;
        case 4: dir = dirs[NextRandomValue() % 4]; break;
        }
        *dirPath++ = dir;
        switch (dir) { case 0: x++; break; case 1: x--; break; case 3: y++; break; case 2: y--; break; }
        map = (s32)*gCurrentMap;
        row = M2C_FIELD(map + (y << 2), s8 **, 0x52e8) + x;
    }
    ReverseMovePath(start, dirPath);
}
/* Reverse the MOVE_DIR_* step list [path, end) in place and terminate it with a
 * MOVE_DIR_STOP (the path tracer builds the list back-to-front). */
void ReverseMovePath(s8 *path, s8 *end) {
 s8 buf[20]; s32 i=0,j; s8 c;
 if(end!=path) {do {buf[i++]=*--end;} while(end!=path);}
 buf[i]=MOVE_DIR_STOP; j=0;
loop:
 c=buf[j++]; *path=c; if(c!=MOVE_DIR_STOP) {path++; goto loop;}
}

