/* 8 functions from 0x0217ACD4 to 0x0217BCD4 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

#pragma scheduling off
/* Expands one neighbour (in direction dir) of the current node of the
 * terrain-cost reachability flood fill: reject the tile when it is off-map or
 * its accumulated terrain cost would exceed the movement limit, return 1 when
 * the goal predicate matches it, otherwise enqueue the new node. */
s32 ExpandCostSearchNode(s32 dir) {
extern void *gMoveSearchCurrent,*gMoveSearchState,*gMoveSearchWrite;extern s32 gMoveSearchCount;extern void **gCurrentMap;extern s32 (*gMoveSearchGoal)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)=M2C_FIELD(gMoveSearchCurrent,u8 *,0);
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)=M2C_FIELD(gMoveSearchCurrent,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)--;break;case 3:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)++;break;case 4:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)--;break;case 5:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)++;break;default:break;}
if(gMoveSearchCount>=MOVE_SEARCH_QUEUE_MAX)return 0;
map=*gCurrentMap;p=gMoveSearchState;
x=p[MOVE_SEARCH_WIDTH];w=M2C_FIELD(map,u16 *,MAP_WIDTH);if(x<w){y=p[MOVE_SEARCH_HEIGHT];h=M2C_FIELD(map,u16 *,MAP_HEIGHT);if(y<h)goto valid;}return 0;valid:;
limit=M2C_FIELD(p,s16 *,MOVE_SEARCH_COST_LIMIT);c=M2C_FIELD(gMoveSearchCurrent,u8 *,3)+p[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&31];
if(c>limit)return 0;
if(gMoveSearchGoal(x,y,p[MOVE_SEARCH_MOVEMENT_TYPE])==1)return 1;
M2C_FIELD(gMoveSearchWrite,u8 *,0)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH);
M2C_FIELD(gMoveSearchWrite,u8 *,1)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT);
M2C_FIELD(gMoveSearchWrite,u8 *,2)=dir;
M2C_FIELD(gMoveSearchWrite,u8 *,3)=c;
gMoveSearchWrite+=4;gMoveSearchCount++;return 0;
}

s32 func_ov000_0217ae9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_01ffb454(s32);
    s32 ExpandCostSearchNode(s32);
    s32 GetUnitMoveRange(u16, s32);
    extern s8 gMoveSearchBuffer;
    extern void *gMoveSearchCurrent;
    extern s32 gMoveSearchCount;
    extern void *gMoveSearchWrite;
    extern void *gMoveSearchState;
    extern void **gCurrentMap;
    void *p;
    u8 state;
    gMoveSearchCount = 0;
    gMoveSearchWrite = gMoveSearchState + 0x28;
    gMoveSearchBuffer = 0;
    gMoveSearchCurrent = gMoveSearchState + 0x5A0;
    M2C_FIELD(gMoveSearchState, s16 *, 0x20) = arg3;
    M2C_FIELD(gMoveSearchState, s16 *, 0x22) = GetUnitMoveRange(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), arg2);
    M2C_FIELD(gMoveSearchState, s8 *, 0x26) = arg2;
    func_01ffb454(arg2);
    M2C_FIELD(gMoveSearchWrite, s8 *, 0) = arg0;
    M2C_FIELD(gMoveSearchWrite, s8 *, 1) = arg1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 3) = 0;
    p = gMoveSearchWrite + 4;
    gMoveSearchWrite = p;
    M2C_FIELD(p, s8 *, 2) = 0;
    for (;;) {
        if (gMoveSearchBuffer == 0) {
            gMoveSearchWrite = gMoveSearchState + 0x5A0;
            gMoveSearchCurrent = gMoveSearchState + 0x28;
            gMoveSearchBuffer = 1;
        } else {
            gMoveSearchWrite = gMoveSearchState + 0x28;
            gMoveSearchCurrent = gMoveSearchState + 0x5A0;
            gMoveSearchBuffer = 0;
            gMoveSearchCount = 0;
        }
        state = M2C_FIELD(gMoveSearchCurrent, u8 *, 2);
        if (state == 0) {
            M2C_FIELD(gMoveSearchState, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
            M2C_FIELD(gMoveSearchState, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
            return 0;
        }
        while (state != 0) {
            switch (state) {
            case 1:
                if (ExpandCostSearchNode(2) == 1) goto found;
                if (ExpandCostSearchNode(3) == 1) goto found;
                if (ExpandCostSearchNode(4) == 1) goto found;
                if (ExpandCostSearchNode(5) == 1) goto found;
                break;
            case 2:
                if (ExpandCostSearchNode(2) == 1) goto found;
                if (ExpandCostSearchNode(4) == 1) goto found;
                if (ExpandCostSearchNode(5) == 1) goto found;
                break;
            case 3:
                if (ExpandCostSearchNode(3) == 1) goto found;
                if (ExpandCostSearchNode(4) == 1) goto found;
                if (ExpandCostSearchNode(5) == 1) goto found;
                break;
            case 4:
                if (ExpandCostSearchNode(2) == 1) goto found;
                if (ExpandCostSearchNode(3) == 1) goto found;
                if (ExpandCostSearchNode(4) == 1) goto found;
                break;
            case 5:
                if (ExpandCostSearchNode(2) == 1) goto found;
                if (ExpandCostSearchNode(3) == 1) goto found;
                if (ExpandCostSearchNode(5) == 1) goto found;
                break;
            }
            M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 0;
            p = gMoveSearchCurrent + 4;
            gMoveSearchCurrent = p;
            state = M2C_FIELD(p, u8 *, 2);
        }
    }
found:
    M2C_FIELD(gMoveSearchState, s8 *, 0x24) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
    M2C_FIELD(gMoveSearchState, s8 *, 0x25) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
    return 1;
}

/* Expands one neighbour (in direction dir) of the current node of the
 * goal-directed movement search: reject it when the accumulated cost is already
 * over the limit or the tile is off-map, clamp the new cost to 255, and return 1
 * when the goal predicate matches; otherwise enqueue the node. */
s32 ExpandGoalSearchNode(s32 dir) {
extern void *gMoveSearchCurrent,*gMoveSearchState,*gMoveSearchWrite;extern s32 gMoveSearchCount;extern void **gCurrentMap;extern s32 (*gMoveSearchGoal)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
if(M2C_FIELD(gMoveSearchCurrent,u8 *,3)>M2C_FIELD(gMoveSearchState,s16 *,MOVE_SEARCH_COST_LIMIT))return 0;
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)=M2C_FIELD(gMoveSearchCurrent,u8 *,0);
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)=M2C_FIELD(gMoveSearchCurrent,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)--;break;case 3:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)++;break;case 4:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)--;break;case 5:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)++;break;default:break;}
if(gMoveSearchCount>=MOVE_SEARCH_QUEUE_MAX)return 0;
map=*gCurrentMap;p=gMoveSearchState;
x=p[MOVE_SEARCH_WIDTH];w=M2C_FIELD(map,u16 *,MAP_WIDTH);if(x<w){y=p[MOVE_SEARCH_HEIGHT];h=M2C_FIELD(map,u16 *,MAP_HEIGHT);if(y<h)goto valid;}return 0;valid:;
c=M2C_FIELD(gMoveSearchCurrent,u8 *,3)+p[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&31];
if(c>255)c=255;
if(gMoveSearchGoal(x,y,p[MOVE_SEARCH_MOVEMENT_TYPE])==1)return 1;
M2C_FIELD(gMoveSearchWrite,u8 *,0)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH);
M2C_FIELD(gMoveSearchWrite,u8 *,1)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT);
M2C_FIELD(gMoveSearchWrite,u8 *,2)=dir;
M2C_FIELD(gMoveSearchWrite,u8 *,3)=c;
gMoveSearchWrite+=4;gMoveSearchCount++;return 0;
}

#pragma opt_common_subs off
s32 func_ov000_0217b3bc(s8 arg0, s8 arg1, s8 arg2, s16 arg3) {
    void func_01ffb454(s32);
    s32 ExpandGoalSearchNode(M2C_UNK);
    s32 GetUnitMoveRange(u16, s32);
    extern void **gCurrentMap;
    extern void *gMoveSearchState;
    extern s8 gMoveSearchBuffer;
    extern void *gMoveSearchCurrent;
    extern s32 gMoveSearchCount;
    extern void *gMoveSearchWrite;
    u8 var_r0;
    void *temp_r0;
    void *temp_r1;

    gMoveSearchCurrent = gMoveSearchState + 0x5A0;
    gMoveSearchBuffer = 0;
    gMoveSearchWrite = gMoveSearchState + 0x28;
    gMoveSearchCount = 0;
    M2C_FIELD(gMoveSearchState, s16 *, 0x20) = arg3;
    M2C_FIELD(gMoveSearchState, s16 *, 0x22) = GetUnitMoveRange(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), arg2);
    M2C_FIELD(gMoveSearchState, s8 *, 0x26) = arg2;
    func_01ffb454(arg2);
    M2C_FIELD(gMoveSearchWrite, s8 *, 0) = arg0;
    M2C_FIELD(gMoveSearchWrite, s8 *, 1) = arg1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 3) = 0;
    temp_r1 = gMoveSearchWrite + 4;
    gMoveSearchWrite = temp_r1;
    M2C_FIELD(temp_r1, s8 *, 2) = 0;
loop_1:
    if (gMoveSearchBuffer == 0) {
        gMoveSearchWrite = gMoveSearchState + 0x5A0;
        gMoveSearchCurrent = gMoveSearchState + 0x28;
        gMoveSearchBuffer = 1;
    } else {
        gMoveSearchWrite = gMoveSearchState + 0x28;
        gMoveSearchCurrent = gMoveSearchState + 0x5A0;
        gMoveSearchBuffer = 0;
    }
    gMoveSearchCount = 0;
    var_r0 = M2C_FIELD(gMoveSearchCurrent, u8 *, 2);
    if (var_r0 != 0) {
        if (var_r0 != 0) {
loop_7:
            switch (var_r0) {
            case 1:
                if ((ExpandGoalSearchNode(2) != 1) && (ExpandGoalSearchNode(3) != 1) && (ExpandGoalSearchNode(4) != 1) && (ExpandGoalSearchNode(5) != 1)) {
                    goto block_36;
                }
                goto success;
            case 2:
                if ((ExpandGoalSearchNode(2) != 1) && (ExpandGoalSearchNode(4) != 1) && (ExpandGoalSearchNode(5) != 1)) {
                    goto block_36;
                }
                goto success;
            case 3:
                if ((ExpandGoalSearchNode(3) != 1) && (ExpandGoalSearchNode(4) != 1) && (ExpandGoalSearchNode(5) != 1)) {
                    goto block_36;
                }
                goto success;
            case 4:
                if ((ExpandGoalSearchNode(2) != 1) && (ExpandGoalSearchNode(3) != 1) && (ExpandGoalSearchNode(4) != 1)) {
                    goto block_36;
                }
                goto success;
            case 5:
                if ((ExpandGoalSearchNode(2) != 1) && (ExpandGoalSearchNode(3) != 1) && (ExpandGoalSearchNode(5) != 1)) {
                    goto block_36;
                }
                goto success;
            default:
            case 0:
block_36:
                M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 0;
                gMoveSearchCurrent+=4;
                var_r0=M2C_FIELD(gMoveSearchCurrent,u8 *,2);
                if (var_r0 == 0) {
                    goto loop_1;
                }
                goto loop_7;
            }
        } else {
            goto loop_1;
        }
    } else {
        M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
        M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
        return 0;
    }
success:
M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
                return 1;
}
#pragma opt_common_subs on
/* Expands one neighbour (in direction dir) of the current node of the uniform
   step range search: enqueue the tile when it is on the map, its terrain is
   passable for the search's movement type, the step count is within the limit
   and it is not the goal tile (which returns 1). */
s32 ExpandRangeSearchNode(s32 dir) {
extern void *gMoveSearchCurrent,*gMoveSearchState,*gMoveSearchWrite;extern s32 gMoveSearchCount;extern void **gCurrentMap;extern s32 (*gMoveSearchGoal)();
u8 *p;void *map;s32 x,y,w,h,c,limit;
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)=M2C_FIELD(gMoveSearchCurrent,u8 *,0);
M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)=M2C_FIELD(gMoveSearchCurrent,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)--;break;case 3:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT)++;break;case 4:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)--;break;case 5:M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH)++;break;default:break;}
if(gMoveSearchCount>=MOVE_SEARCH_QUEUE_MAX)return 0;
map=*gCurrentMap;p=gMoveSearchState;
x=p[MOVE_SEARCH_WIDTH];w=M2C_FIELD(map,u16 *,MAP_WIDTH);if(x<w){y=p[MOVE_SEARCH_HEIGHT];h=M2C_FIELD(map,u16 *,MAP_HEIGHT);if(y<h)goto valid;}return 0;valid:;
if(!IsTerrainPassable(2,M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&31))return 0;
c=M2C_FIELD(gMoveSearchCurrent,u8 *,3)+1;p=gMoveSearchState;limit=M2C_FIELD(p,s16 *,MOVE_SEARCH_COST_LIMIT);
if(c>limit)return 0;
if(gMoveSearchGoal(p[MOVE_SEARCH_WIDTH],p[MOVE_SEARCH_HEIGHT],p[MOVE_SEARCH_MOVEMENT_TYPE])==1)return 1;
M2C_FIELD(gMoveSearchWrite,u8 *,0)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_WIDTH);
M2C_FIELD(gMoveSearchWrite,u8 *,1)=M2C_FIELD(gMoveSearchState,u8 *,MOVE_SEARCH_HEIGHT);
M2C_FIELD(gMoveSearchWrite,u8 *,2)=dir;
M2C_FIELD(gMoveSearchWrite,u8 *,3)=c;
gMoveSearchWrite+=4;gMoveSearchCount++;return 0;
}

s32 func_ov000_0217b8f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ExpandRangeSearchNode(M2C_UNK);
    s32 GetUnitMoveRange(u16, s32);
    extern void **data_027e0058;
    extern void *gMoveSearchState;
    extern s8 gMoveSearchBuffer;
    extern void *gMoveSearchCurrent;
    extern s32 gMoveSearchCount;
    extern void *gMoveSearchWrite;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;

    gMoveSearchCurrent = gMoveSearchState + 0x5A0;
    gMoveSearchBuffer = 0;
    gMoveSearchWrite = gMoveSearchState + 0x28;
    gMoveSearchCount = 0;
    M2C_FIELD(gMoveSearchState, s16 *, 0x20) = (s16)arg3;
    M2C_FIELD(gMoveSearchState, s16 *, 0x22) = (s16)GetUnitMoveRange(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), arg2);
    M2C_FIELD(gMoveSearchState, s8 *, 0x26) = (s8)arg2;
    M2C_FIELD(gMoveSearchWrite, s8 *, 0) = (s8)arg0;
    M2C_FIELD(gMoveSearchWrite, s8 *, 1) = (s8)arg1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 1;
    M2C_FIELD(gMoveSearchWrite, s8 *, 3) = 0;
    temp_r0 = (void *)((u8 *)gMoveSearchWrite + 4);
    gMoveSearchWrite = temp_r0;
    M2C_FIELD(temp_r0, s8 *, 2) = 0;
loop_1:
    if (gMoveSearchBuffer == 0) {
        gMoveSearchWrite = gMoveSearchState + 0x5A0;
        gMoveSearchCurrent = gMoveSearchState + 0x28;
        gMoveSearchBuffer = 1;
    } else {
        gMoveSearchWrite = gMoveSearchState + 0x28;
        gMoveSearchCurrent = gMoveSearchState + 0x5A0;
        gMoveSearchBuffer = 0;
    }
    gMoveSearchCount = 0;
    var_r0 = M2C_FIELD(gMoveSearchCurrent, u8 *, 2);
    if (var_r0 != 0) {
        if (var_r0 != 0) {
loop_7:
            switch (var_r0) {
            default:
            case 0:
block_36:
                M2C_FIELD(gMoveSearchWrite, s8 *, 2) = 0;
                temp_r0_2 = (void *)((u8 *)gMoveSearchCurrent + 4);
                gMoveSearchCurrent = temp_r0_2;
                var_r0 = M2C_FIELD(temp_r0_2, u8 *, 2);
                if (var_r0 == 0) {
                    goto loop_1;
                }
                goto loop_7;
            case 1:
                if ((ExpandRangeSearchNode(2) != 1) && (ExpandRangeSearchNode(3) != 1) && (ExpandRangeSearchNode(4) != 1) && (ExpandRangeSearchNode(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 2:
                if ((ExpandRangeSearchNode(2) != 1) && (ExpandRangeSearchNode(4) != 1) && (ExpandRangeSearchNode(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 3:
                if ((ExpandRangeSearchNode(3) != 1) && (ExpandRangeSearchNode(4) != 1) && (ExpandRangeSearchNode(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 4:
                if ((ExpandRangeSearchNode(2) != 1) && (ExpandRangeSearchNode(3) != 1) && (ExpandRangeSearchNode(4) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            case 5:
                if ((ExpandRangeSearchNode(2) != 1) && (ExpandRangeSearchNode(3) != 1) && (ExpandRangeSearchNode(5) != 1)) {
                    goto block_36;
                }
                M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
                M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
                return 1;
            }
        } else {
            goto loop_1;
        }
    } else {
        M2C_FIELD(gMoveSearchState, s8 *, 0x24) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5144);
        M2C_FIELD(gMoveSearchState, s8 *, 0x25) = (s8) M2C_FIELD(*data_027e0058, u16 *, 0x5146);
        return 0;
    }
}

#pragma scheduling reset
s32 func_ov000_0217bc34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov000_0217ab10();
    s32 func_ov000_0217ae9c(s32, s32, s32, s32);
    extern s32 (*gMoveSearchGoal)();

    gMoveSearchGoal = func_ov000_0217ab10;
    if (gMoveSearchGoal() == 1) {
        return 1;
    }
    return func_ov000_0217ae9c(arg0, arg1, arg2, arg3);
}

s32 func_ov000_0217bc84(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217ac78(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*gMoveSearchGoal)();

    gMoveSearchGoal = func_ov000_0217ac78;
    if (gMoveSearchGoal(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}
