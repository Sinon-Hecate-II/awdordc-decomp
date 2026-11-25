/* 16 functions from 0x020A0964 to 0x020A1944 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

typedef struct { u8 kind : 6; u8 owner : 2; } MapUnitBits;
typedef struct { u16 unk0 : 13; u16 enabled : 1; u16 unk14 : 2; } MapRuleBits;
typedef struct { u32 value : 8; u32 rest : 24; } MapPlayerBits;

typedef struct { s8 unk0[0x36]; s8 x[12]; s8 y[12]; s8 fuel[12]; } MapPathCoords;

static inline s32 GetPathX(s8 *ctx, s32 index) { return (ctx + index)[0x36]; }
static inline s32 GetPathY(s8 *ctx, s32 index) { return (ctx + index)[0x42]; }

#pragma push
#pragma opt_strength_reduction off
/* Picks the tile the selected unit attacks from when the cursor is put on the
 * target tile (targetX,targetY): a direct or mobile indirect unit chooses the
 * best reachable tile within its attack range (highest ScoreMoveCell, random
 * tie-break), while a static indirect unit attacks from where it stands. The
 * pending move path's last step is used when it is already in range, otherwise
 * the range is flood-filled from it (or taken from the movement preview layer). */
void ChooseAttackPosition(s16 targetX, s16 targetY, s16 *out)
{
    s32 GetUnitAttackRangeMax(BattleMapUnitHead *);
    s32 IsMobileIndirectUnitKind(s32);
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK BuildMoveRangeFromPathEnd(void);
    s32 NextRandomValue(void);
    s32 ScoreMoveCell(s32, s32);
    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u8 gUnitMinAttackRange[];
    BattleMapUnitHead *unit;
    u8 *map;
    s8 *path = (s8 *)gUnitMovePath;
    s32 pathIndex = path[UNIT_PATH_LENGTH];
    s32 bestScore, x, y;
    s32 scanX, scanY;
    s8 endX, endY;
    u8 minRange;
    const u8 *rangeTable;
    s32 rangeOffset;
    u16 maxRange;
    s32 dx, dy, distance;
    s32 negDySecond;
    s32 negDyFirst;

    unit = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT);
    rangeTable = gUnitMinAttackRange;
    rangeOffset = unit->kind * 112;
    endX = GetPathX(path, pathIndex);
    endY = GetPathY(path, pathIndex);
    minRange = rangeTable[rangeOffset];
    maxRange = GetUnitAttackRangeMax(unit);
    if (maxRange > 1 && !IsMobileIndirectUnitKind(M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->kind)) {
        out[0] = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->x;
        out[1] = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->y;
        return;
    }

    dy = endY - targetY;
    distance = dy < 0 ? -dy : dy;
    dx = endX - targetX;
    dx = dx < 0 ? -dx : dx;
    dx += distance;
    distance = dx;
    if (distance >= minRange && distance <= maxRange) {
        map = (u8 *)*gCurrentMap;
        if (!map[endX + M2C_FIELD(map + endY * 2, u16 *, MAP_ROW_OFFSETS)]) {
            out[0] = endX;
            out[1] = endY;
            return;
        }
    }

    SelectMapLayer((M2C_UNK)((u8 *)*gCurrentMap + MAP_CELL_SCORE));
    BuildMoveRangeFromPathEnd();
    bestScore = 0;
    map = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(map, u16 *, MAP_HEIGHT); y++) {
        x = 0;
        if (x < M2C_FIELD(map, u16 *, MAP_WIDTH)) {
            s32 dy = targetY - y;
            negDyFirst = -dy;
            do {
                s32 dx, distance, score;
                s8 cost = M2C_FIELD(map + y * 4, s8 **, MAP_GRID)[x];
                if (cost < 0)
                    continue;
                distance = dy < 0 ? negDyFirst : dy;
                dx = targetX - x;
                dx = dx < 0 ? -dx : dx;
                dx += distance;
                distance = dx;
                if (distance < minRange || distance > maxRange)
                    continue;
                score = ScoreMoveCell(x, y);
                if (!score)
                    continue;
                if (score > bestScore) {
                    out[0] = x;
                    bestScore = score;
                    out[1] = y;
                } else if (score == bestScore) {
                    if (NextRandomValue() & 1) {
                        out[0] = x;
                        out[1] = y;
                    }
                }
            } while (++x, map = (u8 *)*gCurrentMap, x < M2C_FIELD(map, u16 *, MAP_WIDTH));
        }
    }
    SelectMapLayer((M2C_UNK)(map + MAP_CELL_ORDER));
    if (bestScore)
        return;

    SelectMapLayer((M2C_UNK)((u8 *)*gCurrentMap + MAP_CELL_ORDER));
    bestScore = 0;
    map = (u8 *)*gCurrentMap;
    for (scanY = 0; scanY < M2C_FIELD(map, u16 *, MAP_HEIGHT); scanY++) {
        scanX = 0;
        if (scanX < M2C_FIELD(map, u16 *, MAP_WIDTH)) {
            s32 dy = targetY - scanY;
            negDySecond = -dy;
            do {
                s32 dx, distance, score;
                s8 cost = M2C_FIELD(map + scanY * 4, s8 **, MAP_GRID)[scanX];
                if (cost < 0 || cost > MAP_GRID_NO_UNIT_MAX)
                    continue;
                distance = dy < 0 ? negDySecond : dy;
                dx = targetX - scanX;
                dx = dx < 0 ? -dx : dx;
                dx += distance;
                distance = dx;
                if (distance < minRange || distance > maxRange)
                    continue;
                score = ScoreMoveCell(scanX, scanY);
                if (!score)
                    continue;
                if (score > bestScore) {
                    out[0] = scanX;
                    bestScore = score;
                    out[1] = scanY;
                } else if (score == bestScore) {
                    if (NextRandomValue() & 1) {
                        out[0] = scanX;
                        out[1] = scanY;
                    }
                }
            } while (++scanX, map = (u8 *)*gCurrentMap, scanX < M2C_FIELD(map, u16 *, MAP_WIDTH));
        }
    }
}

#pragma pop

#pragma push
#pragma opt_common_subs off
void func_020a0d18(void) {
    M2C_UNK SetUnitPathCursor(M2C_UNK, M2C_UNK);
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK BuildMoveRangeFromPathEnd(void);
    M2C_UNK func_020a086c(M2C_UNK, M2C_UNK);
    M2C_UNK BuildMovePathForTile(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK ReplayCursorPathSteps(void);
    M2C_UNK IsMovePathCellUnique(void);
    M2C_UNK RebuildMovePathToTile(M2C_UNK, M2C_UNK);
    s32 FindMovePathStep(s8, s8);
    void func_020a0068(s8);
    void AppendMovePathStep(s8, s8);
    s32 GetPlayerArmyVariant(s32);
    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u8 gUnitMaxAttackRange[];
    extern u16 gMapConfig[];
    extern u8 data_021261d0[];
    extern u8 gMovementTypeTable[];
    s32 cx, cy, dx, dy;
    s8 *ctx;
    u8 *player;
    s32 y, idx, fuel, x;
    u8 *base;
    u32 mode;
    s32 startX;
    u8 *initialBase;
    u32 kind;
    s32 rowOffset;
    s8 index;
    s32 owner, result;
    s8 *costTable;
    s32 terrain;
    u32 moveType;
    s16 sx, sy;
    initialBase = (u8 *)*gCurrentMap;
    if (*(u16 *)(initialBase + 0x52b4) != 2) return;
    ctx = (s8 *)gUnitMovePath;
    startX = *(s16 *)(initialBase + 0x52c2);
    if (ctx[0x34] == startX && ctx[0x35] == *(s16 *)(initialBase + 0x52c4)) return;
    SetUnitPathCursor((u16)startX, *(u16 *)(initialBase + 0x52c4));
    base = (u8 *)*gCurrentMap;
    y = *(s16 *)(base + 0x52c4);
    x = *(s16 *)(base + 0x52c2);
    if ((*(s8 **)(base + y * 4 + 0x52e8))[x] > 110) {
        kind = (*(MapUnitBits **)(base + 0x52d0))->kind;
        if (gUnitMaxAttackRange[kind * 112] > 1) return;
        ctx = (s8 *)gUnitMovePath;
        index = ctx[0x5b];
        cy = ctx[0x42 + index];
        cx = ctx[0x36 + index];
        dy = cy - y; if (dy < 0) dy = -dy;
        dx = cx - x; if (dx < 0) dx = -dx;
        if (dx + dy == 1 && base[cx + *(u16 *)(base + cy * 2 + 0x3758)] == 0) return;
        SelectMapLayer(base + 0x2338);
        BuildMoveRangeFromPathEnd();
        sx = x; sy = y;
        if (func_020a086c(&sx, &sy)) {
            BuildMovePathForTile(sx, sy, (u8 *)*gCurrentMap + 0x5388);
            ReplayCursorPathSteps();
            if (!IsMovePathCellUnique()) RebuildMovePathToTile(sx, sy);
        } else {
            SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
            sx = x; sy = y;
            if (func_020a086c(&sx, &sy)) {
                SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
                RebuildMovePathToTile(sx, sy);
            } else {
                SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
                return;
            }
        }
        SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
        x = sx; y = sy;
    }
    if ((*(s8 **)((u8 *)*gCurrentMap + y * 4 + 0x52e8))[x] == -1) return;
    result = FindMovePathStep((s8)x, (s8)y);
    if (result != -1) {
        func_020a0068((s8)(result + 1));
        ctx = (s8 *)gUnitMovePath;
        ((u8 *)*gCurrentMap)[0x52d5] = ctx[0x5a] - (ctx + ctx[0x5b])[0x4e];
        return;
    }
    base = (u8 *)*gCurrentMap;
    owner = (base[0x52d4] >> 6) + 1;
    player = base + 0x67a4 + owner * 0x8c;
    if (((MapRuleBits *)gMapConfig)->enabled == 0) mode = 0;
    else mode = ((MapPlayerBits *)(player + 0x6c))->value;
    ctx = (s8 *)gUnitMovePath;
    idx = ctx[0x5b];
    fuel = (ctx + idx)[0x4e];
    result = GetPlayerArmyVariant(owner);
    kind = (*(MapUnitBits **)((u8 *)*gCurrentMap + 0x52d0))->kind;
    rowOffset = *(u16 *)(base + y * 2 + 0x3758);
    terrain = (base + (x + rowOffset))[0x1420];
    moveType = gMovementTypeTable[kind * 112];
    costTable = *(s8 **)(data_021261d0 + mode * 0x9c + result * 0x28 + player[0x25] * 4);
    if (fuel >= (costTable + moveType * 32)[terrain & 31]) {
        ctx = (s8 *)gUnitMovePath;
        dy = (ctx + idx)[0x42] - y; if (dy < 0) dy = -dy;
        dx = (ctx + idx)[0x36] - x; if (dx < 0) dx = -dx;
        if (dx + dy == 1) {
            AppendMovePathStep((s8)x, (s8)y);
            ctx = (s8 *)gUnitMovePath;
            ((u8 *)*gCurrentMap)[0x52d5] = ctx[0x5a] - (ctx + ctx[0x5b])[0x4e];
            return;
        }
    }
    if (fuel == 0) func_020a0068(1);
    SelectMapLayer((u8 *)*gCurrentMap + 0x2338);
    BuildMoveRangeFromPathEnd();
    base = (u8 *)*gCurrentMap;
    if ((*(s8 **)(base + y * 4 + 0x52e8))[x] == -1) {
        RebuildMovePathToTile(x, y);
    } else {
        BuildMovePathForTile(x, y, base + 0x5388);
        ReplayCursorPathSteps();
        if (!IsMovePathCellUnique()) RebuildMovePathToTile(x, y);
    }
    SelectMapLayer((u8 *)*gCurrentMap + 0x1e30);
}
#pragma pop
/* The side the move path enters step `step` through: compare the step's cell to
 * the previous step's and return a PATH_EDGE_* index into gPathArrowTiles, or 0
 * for step 0 or when the two cells do not differ. */
s32 UnitPath_GetIncomingDir(s32 step) {
    extern s32 gUnitMovePath;
    void *cur;
    void *prev;
    s8 curPos;
    s8 prevPos;

    if (step == 0) {
        return 0;
    }
    cur = gUnitMovePath + step;
    prev = gUnitMovePath + (step - 1);
    curPos = M2C_FIELD(cur, s8 *, UNIT_PATH_X);
    prevPos = M2C_FIELD(prev, s8 *, UNIT_PATH_X);
    if ((s32) prevPos < (s32) curPos) {
        return PATH_EDGE_LEFT;
    }
    if ((s32) prevPos > (s32) curPos) {
        return PATH_EDGE_RIGHT;
    }
    curPos = M2C_FIELD(cur, s8 *, UNIT_PATH_Y);
    prevPos = M2C_FIELD(prev, s8 *, UNIT_PATH_Y);
    if ((s32) prevPos < (s32) curPos) {
        return PATH_EDGE_TOP;
    }
    if ((s32) prevPos > (s32) curPos) {
        return PATH_EDGE_BOTTOM;
    }
    return 0;
}

/* The side the move path leaves step `step` through: compare the step's cell to
 * the next step's and return a PATH_EDGE_* index into gPathArrowTiles, or 0 when
 * step is the last one or the two cells do not differ. */
s32 UnitPath_GetOutgoingDir(s32 step) {
    extern s32 gUnitMovePath;
    void *cur;
    void *next;
    s8 curPos, nextPos;
    cur = gUnitMovePath;
    if (step == M2C_FIELD(cur, s8 *, UNIT_PATH_LENGTH)) return 0;
    next = (s32)cur + (step + 1);
    cur = (s32)cur + step;
    nextPos = M2C_FIELD(next, s8 *, UNIT_PATH_X);
    curPos = M2C_FIELD(cur, s8 *, UNIT_PATH_X);
    if (curPos < nextPos) return PATH_EDGE_RIGHT;
    if (curPos > nextPos) return PATH_EDGE_LEFT;
    nextPos = M2C_FIELD(next, s8 *, UNIT_PATH_Y);
    curPos = M2C_FIELD(cur, s8 *, UNIT_PATH_Y);
    if (curPos < nextPos) return PATH_EDGE_BOTTOM;
    if (curPos > nextPos) return PATH_EDGE_TOP;
    return 0;
}

void func_020a12c0(void *arg0) {
    M2C_UNK func_02077480();
    func_02077480();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void func_020a12d8(void) {
    M2C_UNK func_020774b0();
    void DrawUnitMovePath(M2C_UNK, M2C_UNK);
      func_020774b0();
      func_020a0d18();
      DrawUnitMovePath(0, 0);
  }

  void func_020a12f4(void) {
      M2C_UNK ResetMapViewRaiseTimer();
      ResetMapViewRaiseTimer();
  }

#pragma push
#pragma opt_strength_reduction off
/* Draws the pending move path of the unit under the cursor: for every path
 * step it picks the arrow tile from gPathArrowTiles by the directions of the
 * segments entering and leaving the step and draws it as a 16x16 sprite at
 * the cell's world position. Nothing is drawn for an empty path or when the
 * path belongs to a unit of another player. */
void DrawUnitMovePath(s32 arg0, s32 arg1) {
    M2C_UNK DrawSpriteFrameQuads(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    s32 UnitPath_GetOutgoingDir(s32);
    s32 UnitPath_GetIncomingDir(s32);
    extern s32 *gCurrentMap;
    extern s32 gUnitMovePath;
    extern u16 gPathArrowTiles[];
    extern M2C_UNK gSpriteDesc16x16;

    register void *map;
    register s32 index;
    s8 *path;
    u8 *unit;
    s32 owner;
    s8 step;
    s32 outDir;
    s32 inDir;
    u16 arrow;
    s8 *stepPtr;
    s32 pos[3];

    path = (s8 *)gUnitMovePath;
    if (path[UNIT_PATH_LENGTH] == 0) {
        return;
    }
    map = (void *)*gCurrentMap;
    unit = *(u8 **)((u8 *)map + MAP_CURSOR_UNIT);
    if (unit != NULL) {
        index = unit ? ((s8 *)unit - ((s8 *)map + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        owner = (index >> 6) + 1;
    } else {
        owner = 0;
    }
    if (*(u16 *)((u8 *)map + MAP_CURRENT_PLAYER) != owner) {
        return;
    }
    /* polygon attribute, then save the 3D matrix stack around the arrows */
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    *(volatile s32 *)0x04000444 = 0;
    path = (s8 *)gUnitMovePath;
    step = path[UNIT_PATH_LENGTH];
    for (; step >= 0; step--) {
        outDir = UnitPath_GetOutgoingDir((u8)step);
        inDir = UnitPath_GetIncomingDir((u8)step);
        arrow = ((u16 (*)[5])gPathArrowTiles)[outDir][inDir];
        stepPtr = (s8 *)gUnitMovePath + (s32)step;
        pos[0] = (s32)stepPtr[UNIT_PATH_X] << 4;
        pos[1] = (s32)stepPtr[UNIT_PATH_Y] << 4;
        pos[2] = 0x851;
        /* nudge an arrowhead half an arrow width toward the direction it shows */
        switch ((s32)arrow - 0xC0) {
        case 2:
            pos[0] -= 4;
            break;
        case 4:
            pos[1] -= 4;
            break;
        case 6:
            pos[0] += 4;
            break;
        case 0:
            pos[1] += 4;
            break;
        default:
            break;
        }
        pos[0] = pos[0] * 0x30;
        pos[1] = pos[1] * 0x30;
        DrawSpriteFrameQuads(&gSpriteDesc16x16, pos, 0x22F20, 0x1460, 0x30000, 0, 0, 0x80, 0x80, 0x1800, arrow);
    }
    *(volatile s32 *)0x04000448 = 1;
    return;
}
#pragma pop
void func_020a1508(void) {

}

/* Draw callback of a cursor direction marker: draws the arrow tile that shows
 * the marker's direction (0x100 + 2 * direction) at the world position of the
 * tile the marker sits on. */
void DrawDirectionMarker(DirectionMarker *marker) {
    M2C_UNK DrawSpriteFrameQuads(M2C_UNK *, s32 *, s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32);
    extern M2C_UNK gSpriteDesc16x16;
    s32 pos[3];
    s32 arrowIndex = marker->direction * 2;
    *(volatile s32 *)0x040004A4 = 0x1F0080;
    pos[0] = (marker->x << 4) * 0x30;
    pos[1] = (marker->y << 4) * 0x30;
    pos[2] = 0x891;
    DrawSpriteFrameQuads(&gSpriteDesc16x16, pos, 0x22F20, 0x1480, 0x30000, 0, 0, 0x80, 0x80, 0x1800, arrowIndex + 0x100);
}

/* Create the direction marker sprite on map tile (x, y) showing the given
 * `direction`; returns the new marker. */
DirectionMarker *CreateDirectionMarker(s32 x, s32 y, s16 direction) {
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern M2C_UNK gDirectionMarkerSpriteClass;
    DirectionMarker *marker;

    marker = CreateSpriteFromClass(&gDirectionMarkerSpriteClass, 7);
    marker->x = x;
    marker->y = y;
    marker->direction = direction;
}

void DeleteDirectionMarkerSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gDirectionMarkerSpriteClass;
    DeleteSpriteObjectsOfClass(&gDirectionMarkerSpriteClass);
}

#pragma opt_strength_reduction off
/* Battle start: give every impact-feature cell its full destructible-terrain
   HP and clear the HP of every other cell. */
void ResetTerrainHitPoints(void) {
    extern s32 *gCurrentMap;
    s32 x, y;
    u8 *base;
    u8 *p;
    base = (u8 *)*gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
        for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++) {
            base = base + x + M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS);
            p = base;
            if ((p[MAP_CELL_TERRAIN] & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_IMPACT) p[MAP_CELL_TERRAIN_HP] = MAP_CELL_TERRAIN_HP_PRESENT | MAP_TERRAIN_IMPACT_HP_FULL;
            else p[MAP_CELL_TERRAIN_HP] = 0;
            base = (u8 *)*gCurrentMap;
        }
    }
}
#pragma opt_strength_reduction reset
/* Decode the run-length terrain hit points of a saved map record into the map's
 * per-cell table: a byte with MAP_CELL_TERRAIN_HP_PRESENT set is one cell's
 * value, a byte below 0x80 is that many cells with no hit points, and
 * MAP_TERRAIN_HP_RLE_END closes the data. */
void DecodeTerrainHitPoints(u8 *data) {
    extern s32 *gCurrentMap;
    s32 zeroCount;
    u8 *out;
    u8 *in;
    u8 cell;

    in = data;
    out = *gCurrentMap + MAP_CELL_TERRAIN_HP;
    if (*in == MAP_TERRAIN_HP_RLE_END) {
        return;
    }
    do {
        cell = *in;
        if (cell & MAP_CELL_TERRAIN_HP_PRESENT) {
            in += 1;
            *out = cell;
            out += 1;
        } else {
            zeroCount = 0;
            if ((s32)cell > 0) {
                do {
                    *out = 0;
                    out += 1;
                    zeroCount += 1;
                } while (zeroCount < (s32)*in);
            }
            in += 1;
        }
    } while (*in != MAP_TERRAIN_HP_RLE_END);
}

/* Run-length encode the battle map's per-cell terrain-HP grid into dst: a run of
 * zero cells becomes its count byte, a nonzero cell is written as itself (its
 * MAP_CELL_TERRAIN_HP_PRESENT bit keeps it apart from a count) and
 * MAP_TERRAIN_HP_RLE_END closes the data. */
void EncodeTerrainHitPoints(u8 *dst) {
extern s32 *gCurrentMap;
s32 i;
u8 zeroRun;
u8 *cell;
s32 cellCount;
void *base;
zeroRun = 0;
i = zeroRun;
base=(void *)*gCurrentMap;
cellCount=M2C_FIELD(base,u16 *,MAP_WIDTH)*M2C_FIELD(base,u16 *,MAP_HEIGHT);
cell=(u8 *)base+MAP_CELL_TERRAIN_HP;
for(;i<cellCount;i++,cell++) {
if(*cell) {
if(zeroRun){*dst++=zeroRun;zeroRun=0;}
*dst++=*cell;
}else {
zeroRun++;
if(zeroRun==MAP_TERRAIN_HP_RLE_MAX){*dst++=zeroRun;zeroRun=0;}
}
}
if(zeroRun)*dst++=zeroRun;
*dst=MAP_TERRAIN_HP_RLE_END;
}

#pragma opt_strength_reduction off
/* Applies the terrain change of an impact blast centred on tile (x, y): every
 * cell within the blast's reach becomes plain ground, an owned property caught
 * in it becomes wasteland, and an impact-feature cell becomes a crater.  The
 * reach is the movement range of the impact's pseudo unit kind; a map record
 * that contains an impact tile replays the same blast when the map is loaded. */
void ApplyTerrainBlast(s32 x, s32 y) {
    M2C_UNK SelectMapLayer(M2C_UNK);
    M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    s32 row;
    s32 col;
    u8 *map;

    map = (u8 *)*gCurrentMap;
    SelectMapLayer(map + MAP_CELL_ORDER);
    FloodFillUnitRange(x, y, IMPACT_BLAST_MOVE_KIND, IMPACT_BLAST_MOVE_BUDGET, 0);

    map = (u8 *)*gCurrentMap;
    for (row = 0; row < M2C_FIELD(map, u16 *, MAP_HEIGHT); row++) {
        map = (u8 *)*gCurrentMap;
        for (col = 0; col < M2C_FIELD(map, u16 *, MAP_WIDTH); col++) {
            if (M2C_FIELD(M2C_FIELD(map + (row << 2), s8 **, MAP_GRID), s8 *, col) >= 0) {
                u16 rowOffset = M2C_FIELD(map + (row << 1), u16 *, MAP_ROW_OFFSETS);
                u8 terrain = M2C_FIELD(rowOffset + (map + col), u8 *, MAP_CELL_TERRAIN);
                if (((terrain & MAP_TERRAIN_OWNER_MASK) >> 5) != 0) {
                    M2C_FIELD(map + (col + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID) = MAP_TILE_WASTELAND;
                    map = (u8 *)*gCurrentMap;
                    M2C_FIELD(M2C_FIELD(map + (row << 1), u16 *, MAP_ROW_OFFSETS) + (map + col), u8 *, MAP_CELL_TERRAIN) = MAP_TERRAIN_WASTELAND;
                } else {
                    if (terrain == MAP_TERRAIN_IMPACT) {
                        M2C_FIELD(map + (col + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID) = MAP_TILE_BLAST_CRATER;
                    } else {
                        M2C_FIELD(map + (col + rowOffset) * 2, u16 *, MAP_CELL_TILE_ID) = MAP_TILE_BLAST_GROUND;
                    }
                    map = (u8 *)*gCurrentMap;
                    M2C_FIELD(M2C_FIELD(map + (row << 1), u16 *, MAP_ROW_OFFSETS) + (map + col), u8 *, MAP_CELL_TERRAIN) = MAP_TERRAIN_PLAIN;
                }
            }
            map = (u8 *)*gCurrentMap;
        }
    }
}
#pragma opt_strength_reduction reset
