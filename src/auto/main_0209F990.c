/* 17 functions from 0x0209F990 to 0x020A0964 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct PathPlayerId { u32 id:8; u32 rest:24; } PathPlayerId;
typedef struct UnkCellBits { u8 pad[5]; u8 bits:3; u8 rest:5; } UnkCellBits;
extern u16 gMapConfig;
extern u8 data_021261d0[];
extern u8 gMovementTypeTable[];

#pragma opt_strength_reduction off
s32 func_0209f990(void) {
    void func_0209f8c0(void);
    void func_0209f8f8(s32, s32, s32, s32);
    s32 func_020a4828(s32, s32);
    void *FindMapOrderAtTile(s32, s32);
    u8 func_020d27a4(s32, s32);
    void func_020d166c(s32, s32, void *);
    u8 IsSameTeam(s32, s32);
    void func_020d1690(s32, s32, void *);
    extern s32 *gCurrentMap;
    extern void *data_0215be00;

    s32 id;
    s32 visible;
    s32 x;
    s32 y;
    u8 *obj;
    void *dim;
    s32 bits;

    func_0209f8c0();
    obj = (u8 *)*gCurrentMap;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
                do {
                    if (M2C_FIELD(M2C_FIELD(obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0) {
                        id = M2C_FIELD(obj, u8 *, x + M2C_FIELD(obj + y * 2, u16 *, 0x3758));
                        visible = func_020a4828(x, y);
                        if (id != 0) {
                            if (func_020d27a4(M2C_FIELD((u8 *)*gCurrentMap, u8 *, 0x52d4), id) == 0) {
                                func_020d166c(M2C_FIELD((u8 *)*gCurrentMap, u8 *, 0x52d4), id, (void *)((u8 *)*gCurrentMap + 0x52dc));
                                if (M2C_FIELD((u8 *)*gCurrentMap, s16 *, 0x6ed6) != 0) {
                                    func_0209f8f8(x, y, id, 0);
                                }
                            }
                        } else {
                            if (visible != 0) {
                                dim = FindMapOrderAtTile(x, y);
                                if (dim != 0) {
                                    bits = (s32)((UnkCellBits *)dim)->bits;
                                    if (bits != 0) {
                                        if (IsSameTeam((M2C_FIELD((u8 *)*gCurrentMap, u8 *, 0x52d4) >> 6) + 1, bits) != 0) {
                                            goto next_cell;
                                        }
                                    }
                                }
                                func_020d1690(M2C_FIELD((u8 *)*gCurrentMap, u8 *, 0x52d4), visible, (void *)((u8 *)*gCurrentMap + 0x52dc));
                                if (M2C_FIELD((u8 *)*gCurrentMap, s16 *, 0x6ed6) != 0) {
                                    func_0209f8f8(x, y, 0, (s32)(u16)visible);
                                }
                            }
                        }
                    }
next_cell:
                    x++;
                    obj = (u8 *)*gCurrentMap;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    return M2C_FIELD(&data_0215be00, s32 *, 8);
}
#pragma opt_common_subs off
s32 func_0209fb70(void) {
    void func_0209f8c0(void);
    void func_0209f8f8(s32, s32, s32, s32);
    s32 func_020a4828(s32, s32);
    void *FindMapOrderAtTile(s32, s32);
    u8 func_020d27a4(s32, s32);
    s32 func_020d0a08(M2C_UNK, void *);
    s32 func_020d0a88(u8 *, M2C_UNK);
    u8 IsSameTeam(s32, s32);
    extern s32 *gCurrentMap;
    extern void *data_0215be00;

    s32 id;
    s32 visible;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    void *dim;
    s32 bits;

    func_0209f8c0();
    obj = (M2C_UNK *)*gCurrentMap;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) <= 0) goto done;
    do {
        x = 0;
        if ((s32)M2C_FIELD(obj, u16 *, 0x5144) <= 0) goto next_row;
        do {
            if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) < 0) goto next_cell;
            id = M2C_FIELD(obj, u8 *, x + M2C_FIELD((u8 *)obj + y * 2, u16 *, 0x3758));
            visible = func_020a4828(x, y);
            if (id != 0) {
                if (func_020d27a4(M2C_FIELD((M2C_UNK *)*gCurrentMap, u8 *, 0x52d4), id) == 0) {
                    if (func_020d0a08(M2C_FIELD((M2C_UNK *)*gCurrentMap, M2C_UNK *, 0x52d0), (u8 *)(M2C_UNK *)*gCurrentMap + 0x59a4 + id * 14) != 0) {
                        func_0209f8f8(x, y, id, 0);
                    }
                }
            } else {
                if (visible != 0) {
                    dim = FindMapOrderAtTile(x, y);
                    if (dim != 0) {
                        bits = (s32)((UnkCellBits *)dim)->bits;
                        if (bits != 0) {
                            if (IsSameTeam((M2C_FIELD((M2C_UNK *)*gCurrentMap, u8 *, 0x52d4) >> 6) + 1, bits) != 0) {
                                goto next_cell;
                            }
                        }
                    }
                    if (func_020d0a88((u8 *)M2C_FIELD((M2C_UNK *)*gCurrentMap, M2C_UNK *, 0x52d0), visible) != 0) {
                        func_0209f8f8(x, y, 0, (s32)(u16)visible);
                    }
                }
            }
next_cell:
            x++;
            obj = (M2C_UNK *)*gCurrentMap;
        } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
next_row:
        y++;
    } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
done:
    return M2C_FIELD(&data_0215be00, s32 *, 8);
}
#pragma opt_common_subs reset
s32 func_0209fd2c(void) {
    /* Walk the map grid; for every cell whose stored value is >= 0 and
       whose passability test succeeds, append (x, y, value) to the output
       list. Terminate the list with a -1 sentinel and return the count. */
    s32 GetTerrainPropertyFlagsAt(s32, s32);
    extern void *data_0215be00;
    extern s32 *gCurrentMap;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*gCurrentMap;
    count = 0;
    type = (u32)(M2C_FIELD(M2C_FIELD(obj, u8 **, 0x52D0), u8 *, 0) << 26) >> 26;
    if (type != 1 && type != 2 && type != 3) return 0;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
                do {
                    if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0 && GetTerrainPropertyFlagsAt(x, y) == 1) {
                        M2C_FIELD(out, u8 *, 0) = (u8)x;
                        M2C_FIELD(out, u8 *, 1) = (u8)y;
                        count++;
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*gCurrentMap;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    M2C_FIELD(out, s16 *, 2) = -1;
    return count;
}

s32 CollectSupplyTargets(void) {
    s32 IsSupplyTargetAt(s32, s32);
    extern void *data_0215be00;
    extern M2C_UNK *gCurrentMap;

    u16 *out;
    s32 y;
    s32 x;

    out = (u16 *)data_0215be00 + 2;
    y = 0;

    if (M2C_FIELD(gCurrentMap, u16 *, 0x5146) == 0) goto done;

    do {
        x = 0;

        if (M2C_FIELD(gCurrentMap, u16 *, 0x5144) == 0) goto next_row;

        do {
            if (M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x) < 0) goto next_cell;
            if (IsSupplyTargetAt(x, y) == 0) goto next_cell;

            *out = *(u8 *)((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + y * 2) + x);
            out += 4;

next_cell:
            x++;
        } while (x < M2C_FIELD(gCurrentMap, u16 *, 0x5144));

next_row:
        y++;
    } while (y < M2C_FIELD(gCurrentMap, u16 *, 0x5146));

done:
    *out = 0;
    return (out - ((u16 *)data_0215be00 + 2)) / 16;
}

s32 func_0209ff34(void) {
    /* Same as func_0209fd2c but using the secondary passability test
       (func_020baa1c). */
    s32 func_020baa1c(s32, s32);
    extern void *data_0215be00;
    extern s32 *gCurrentMap;
    s32 count;
    u8 *out;
    s32 x;
    s32 y;
    M2C_UNK *obj;
    u32 type;

    out = data_0215be00;
    obj = (M2C_UNK *)*gCurrentMap;
    count = 0;
    type = (u32)(M2C_FIELD(M2C_FIELD(obj, u8 **, 0x52D0), u8 *, 0) << 26) >> 26;
    if (type != 1 && type != 2 && type != 3) return 0;
    y = 0;
    if ((s32)M2C_FIELD(obj, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32)M2C_FIELD(obj, u16 *, 0x5144) > 0) {
                do {
                    if (M2C_FIELD(M2C_FIELD((u8 *)obj + y * 4, s8 **, 0x52E8), s8 *, x) >= 0 && func_020baa1c(x, y) == 1) {
                        M2C_FIELD(out, u8 *, 0) = (u8)x;
                        M2C_FIELD(out, u8 *, 1) = (u8)y;
                        count++;
                        M2C_FIELD(out, s16 *, 2) = M2C_FIELD(M2C_FIELD((u8 *)(void *)*gCurrentMap + y * 4, s8 **, 0x52E8), s8 *, x);
                        out = (u8 *)out + 4;
                    }
                    x++;
                    obj = (M2C_UNK *)*gCurrentMap;
                } while (x < (s32)M2C_FIELD(obj, u16 *, 0x5144));
            }
            y++;
        } while (y < (s32)M2C_FIELD(obj, u16 *, 0x5146));
    }
    M2C_FIELD(out, s16 *, 2) = -1;
    return count;
}

void SetUnitPathCursor(u16 arg0, u16 arg1) {
    extern void *gUnitMovePath;
    M2C_FIELD(gUnitMovePath, s8 *, 0x34) = arg0;
    M2C_FIELD(gUnitMovePath, s8 *, 0x35) = arg1;
}

#pragma optimization_level 3
void func_020a0068(s32 arg0) {
extern void *gUnitMovePath;extern s32 *gCurrentMap;
extern u16 gMapConfig;extern u8 gMovementCostTable[];extern u8 gUnitKindStats[];
void *map,*player,*path; s8 i;u32 id; s32 weather,kind,terrain,owner; s8 *cost;
if(M2C_FIELD(gUnitMovePath,s8 *,0x5b)<arg0)return;
M2C_FIELD(gUnitMovePath,s8 *,0x5b)=arg0-1;
M2C_FIELD(gUnitMovePath+M2C_FIELD(gUnitMovePath,s8 *,0x5b),s8 *,0x4e)=M2C_FIELD(gUnitMovePath,s8 *,0x5a);
for(i=1;i<=M2C_FIELD(gUnitMovePath,s8 *,0x5b);i++){
map=(void *)*gCurrentMap;
owner=(M2C_FIELD(map,u8 *,0x52d4)>>6)+1;
player=map+0x67a4+owner*140;
id=((u32)(gMapConfig<<18)>>31)?(u8)M2C_FIELD(player,u32 *,0x6c):0;
path=gUnitMovePath+i;
weather=GetPlayerArmyVariant(owner);
{
    u8 *costRecord = gMovementCostTable + id * 156 + weather * 40;
    u8 *current = (void *)*gCurrentMap;
    u8 faction = M2C_FIELD(player, u8 *, 0x25);
    u8 *unit;
    s32 previous = M2C_FIELD(path, s8 *, 0x4d);
    s32 x = M2C_FIELD(path, s8 *, 0x36);
    s32 y = M2C_FIELD(path, s8 *, 0x42);
    const u8 *type;
    u16 row;
    costRecord += 4 * faction;
    unit = M2C_FIELD(current, u8 **, 0x52d0);
    kind = (u32)(unit[0] << 26) >> 26;
    type = gUnitKindStats + kind * 0x70;
    {
        u8 movementType = type[0x12];
        row = M2C_FIELD(map + 2 * y, u16 *, 0x3758);
        cost = M2C_FIELD(costRecord, s8 **, 0x64) + movementType * 32;
    }
    terrain = M2C_FIELD(map + x + row, u8 *, 0x1420) & 31;
    M2C_FIELD(path, s8 *, 0x4e) = previous - cost[terrain];
}
}
}
#pragma optimization_level reset
void func_020a01c0(s32 x,s32 y){
extern void *gUnitMovePath;extern s32 *gCurrentMap;
void *map; void *player;void *path;s8 i;u32 id;s32 weather;s32 kind;s32 terrain;s8 *cost;u8 *unit;void *table;u16 row;u8 faction;
M2C_FIELD(gUnitMovePath,s8 *,0x5b)++;
M2C_FIELD(gUnitMovePath+M2C_FIELD(gUnitMovePath,s8 *,0x5b),s8 *,0x36)=x;
M2C_FIELD(gUnitMovePath+M2C_FIELD(gUnitMovePath,s8 *,0x5b),s8 *,0x42)=y;
map=(void *)*gCurrentMap;
player=map+0x67a4+((M2C_FIELD(map,u8 *,0x52d4)>>6)+1)*140;
id=((u32)(gMapConfig<<18)>>31)?((PathPlayerId *)(player+0x6c))->id:0;
path=gUnitMovePath;i=M2C_FIELD(path,s8 *,0x5b);
table = data_021261d0 + id * 156;
weather=GetPlayerArmyVariant();
unit = M2C_FIELD((void *)*gCurrentMap,u8 **,0x52d0);
row = M2C_FIELD(map+y*2,u16 *,0x3758);
kind = (u32)(unit[0] << 26) >> 26;
faction = M2C_FIELD(player,u8 *,0x25);
terrain = M2C_FIELD(map+x+row,u8 *,0x1420)&31;
cost = ((s8 **)(table+weather*40))[faction];
M2C_FIELD(path+i,s8 *,0x4e)=M2C_FIELD(path+i-1,s8 *,0x4e)-cost[gMovementTypeTable[kind*112]*32+terrain];
}
#pragma optimization_level reset
s32 func_020a0300(s32 x,s32 y) {
 extern void *gUnitMovePath;
 s8 i; void *p=gUnitMovePath; char *q;
 i=0; if(i<=M2C_FIELD(p,volatile s8 *,0x5b)) { q=p; do {
 if(x==M2C_FIELD(q,s8 *,0x36)&&y==M2C_FIELD(q,s8 *,0x42)) return i;
 q++; i++; } while(i<=M2C_FIELD(p,volatile s8 *,0x5b)); }
 return -1;
}

M2C_UNK func_020a0360(void) {
    void func_020a01c0(s32, s32);
    extern s32 *gCurrentMap;
    extern void *gUnitMovePath;
    M2C_UNK *map;
    volatile s8 *stream;
    s8 cmd;
    s8 *base;
    s8 *q;

    map = (M2C_UNK *)*gCurrentMap;
    stream = (volatile s8 *)*((s32 *)map) + 0x388 + 0x5000;
    cmd = *stream++;
    base = (s8 *)gUnitMovePath;

    switch (cmd + 1) {
        case 0:
        case 4:
        case 7:
        case 8:
        case 9:
        case 10:
        default:
            break;
        case 1:
        case 6:
            q = base + base[0x5b];
            func_020a01c0((s8)(q[0x36] - 1), (s8)q[0x42]);
            break;
        case 2:
            q = base + base[0x5b];
            func_020a01c0((s8)(q[0x36] + 1), (s8)q[0x42]);
            break;
        case 3:
            q = base + base[0x5b];
            func_020a01c0((s8)q[0x36], (s8)(q[0x42] - 1));
            break;
        case 5:
            q = base + base[0x5b];
            func_020a01c0((s8)q[0x36], (s8)(q[0x42] + 1));
            break;
    }
    return 0;
}

/* Turns the pending move path (gUnitMovePath) into the map's cursor path arrows:
 * each step gets the direction it takes from the step before, and the last arrow
 * is the stop marker. */
void BuildMovePathDirections(void) {
    extern void *gUnitMovePath;
    extern s32 *gCurrentMap;

    s8 i;
    u8 *step;

    i = 1;
    if (((s8 *)gUnitMovePath)[0x5b] >= 1) {
    do {
        step = (u8 *)gUnitMovePath + i;
        if ((s8)step[0x36] < (s8)step[0x35]) {
            *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = MOVE_DIR_LEFT;
        } else if ((s8)step[0x36] > (s8)step[0x35]) {
            *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = MOVE_DIR_RIGHT;
        } else {
            if ((s8)step[0x42] < (s8)step[0x41]) {
                *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = MOVE_DIR_UP;
            } else {
                *((u8 *)((u8 *)*gCurrentMap + i + 0x5387)) = MOVE_DIR_DOWN;
            }
        }
        i++;
    } while (i <= (s8)((u8 *)gUnitMovePath)[0x5b]);

    }
    *((u8 *)((u8 *)*gCurrentMap + (i - 1) + 0x5388)) = MOVE_DIR_STOP;
    return;
}

M2C_UNK BuildMoveRangeFromPathEnd(void) {
    extern void *gUnitMovePath; extern s32 *gCurrentMap;
    void func_01ffc294(u16, s32, s32, u32, s32, s32);
    s8 *p;
    s8 *q;
    u8 *map;

    p = gUnitMovePath;
    q = p + p[0x5b];
    map = (u8 *)*gCurrentMap;
    func_01ffc294((u16)((map[0x52d4] >> 6) + 1), q[0x36], q[0x42], (u32)(M2C_FIELD(M2C_FIELD(map, u8 **, 0x52d0), u8 *, 0) << 26) >> 26, q[0x4e], 1);
}

void func_020a05d8(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    M2C_UNK BuildMoveRangeFromPathEnd();
extern s32 *gCurrentMap;
    func_020a0068(1);
    BuildMoveRangeFromPathEnd();
    func_01ffc4b8(arg0, arg1, *gCurrentMap + 0x5388);
    func_020a0360();
}

/* Checks the pending move path for a repeated cell: returns 0 if any two steps
 * land on the same tile, 1 when every step is on a different tile. */
s32 IsMovePathCellUnique(void) {
    extern void *gUnitMovePath;
    void *path = gUnitMovePath;
    s8 i, j;
    s8 *step, *other;
    s32 x;

    i = M2C_FIELD(path, s8 *, UNIT_PATH_LENGTH);
    if (i > 0) {
        step = path + i;
        do {
            j = i - 1;
            if (j >= 0) do {
                x = step[UNIT_PATH_X];
                other = path + j;
                if (x == other[UNIT_PATH_X] && step[UNIT_PATH_Y] == other[UNIT_PATH_Y]) return 0;
                j--;
            } while (j >= 0);
            i--;
            step--;
        } while (i > 0);
    }
    return 1;
}

/* Starts a fresh move path for the unit under the cursor: resets the path to the
   unit's remaining movement, makes the unit's own tile step 0, optionally adds
   the step the movement input has already queued, clears the drawn cursor path
   and updates the path to the cursor. */
void StartUnitMovePath(s32 followInput) {
    extern void *gUnitMovePath;
    extern s32 *gCurrentMap;
    s32 GetUnitRemainingMoveRange(s32);
    void func_020a01c0(s32, s32);
    M2C_UNK func_020a0360(void);
    M2C_UNK func_020a0d18();
    void SetUnitPathCursor(u16, u16);
    void *unit;
    M2C_FIELD(gUnitMovePath, s8 *, UNIT_PATH_START_COST) = GetUnitRemainingMoveRange(M2C_FIELD((void *)*gCurrentMap, s32 *, MAP_CURSOR_UNIT));
    M2C_FIELD(gUnitMovePath, s8 *, UNIT_PATH_LENGTH) = 0;
    func_020a0068(0);
    unit = M2C_FIELD((void *)*gCurrentMap, void **, MAP_CURSOR_UNIT);
    func_020a01c0(M2C_FIELD(unit, s8 *, MAP_UNIT_X), M2C_FIELD(unit, s8 *, MAP_UNIT_Y));
    M2C_FIELD(gUnitMovePath, s8 *, UNIT_PATH_STEP_COST) = M2C_FIELD(gUnitMovePath, s8 *, UNIT_PATH_START_COST);
    if (followInput != 0) func_020a0360();
    M2C_FIELD((void *)*gCurrentMap, u8 *, MAP_CURSOR_PATH) = MOVE_DIR_STOP;
    SetUnitPathCursor(0xffff, 0xffff); func_020a0d18();
}

/* Score a cell as an AI move destination: 0 when the cell is invalid or has a unit,
 * otherwise more for cells reached with less movement (and inside the player's move
 * range), plus the terrain's defense score for the cursor unit. */
s32 ScoreMoveCell(s32 x,s32 y){
extern s32 *gCurrentMap;
void *map; s32 moveCost; u8 *cursorUnit; s32 cellOffset; s32 player; s32 kind; s32 terrain; s32 score=0;
if(x<0||y<0||x>=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_WIDTH)||y>=M2C_FIELD((void *)*gCurrentMap,u16 *,MAP_HEIGHT))return 0;
map=(void *)*gCurrentMap;
moveCost=M2C_FIELD(M2C_FIELD(map+y*4,s8 **,MAP_GRID),s8 *,x);
if(moveCost<0||moveCost>MAP_GRID_NO_UNIT_MAX)return 0;
if(M2C_FIELD(map,u8 *,x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)))return score;
score+=(MAP_GRID_NO_UNIT_MAX-moveCost)<<8;
score+=IsCellInPlayerMoveRange((M2C_FIELD(map,u8 *,MAP_CURSOR_UNIT_ID)>>6)+1,x,y)?64:0;
map=(void *)*gCurrentMap;
cellOffset=x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS);
cursorUnit=M2C_FIELD(map,u8 **,MAP_CURSOR_UNIT);
player=(M2C_FIELD(map,u8 *,MAP_CURSOR_UNIT_ID)>>6)+1;
kind=(u32)(cursorUnit[0]<<26)>>26;
terrain=M2C_FIELD(map+cellOffset,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK;
return score+GetTerrainDefenseScore(player,kind,terrain);
}

s32 func_020a086c(s16 *arg0, s16 *arg1) {
    s32 ScoreMoveCell(s32, s32);
    s32 NextRandomValue(void);
    unsigned long long RuntimeIntDivMod(s32, s32);
    extern s8 data_0211fbbc[];
    s32 xv = *arg0;
    s32 yv = *arg1;
    s32 best = 0;
    s32 tiecount = 0;
    s32 i;
    s32 off = 0;
    s32 scores[4];
    for (i = 0; i < 4; i++) {
        s32 sc = ScoreMoveCell(xv + (s32)data_0211fbbc[off], yv + (s32)data_0211fbbc[off + 1]);
        scores[i] = sc;
        if (sc > best) { best = sc; tiecount = 0; }
        else if (sc == best) { tiecount++; }
        off += 2;
    }
    if (best == 0) return 0;
    {
        unsigned long long q = RuntimeIntDivMod(NextRandomValue(), tiecount + 1);
        s32 ticket = (s32)(q >> 32);
        s32 idx = 0;
        for (idx = 0; idx < 4; idx++) {
            if (scores[idx] == best) {
                if (ticket == 0) break;
                ticket--;
            }
        }
        *arg0 = (s16)(xv + (s32)data_0211fbbc[idx * 2]);
        *arg1 = (s16)(yv + (s32)data_0211fbbc[idx * 2 + 1]);
    }
    return 1;
}

