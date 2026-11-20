/* 6 functions from 0x02177CE0 to 0x02178778 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

/* Scores a tile as a movement destination for the AI unit under the cursor:
 * remaining movement, nearby-own-unit and terrain-movement bonuses, the
 * direct/indirect threat on the tile, and a few positional preferences. */
s32 ScoreMoveDestination(s32 x,s32 y){
extern u8 gUnitKindFlags[], gAiRangeBitmap[];
extern void **gCurrentMap;extern void *gAiCommandState;extern s8 gTerrainPropertyType[];
s32 IsAllyUnitAtCell(s16,s16);s32 IsTerrainOnUnitTeam(s32,s32,s32);
s32 GetTerrainMoveCost(s32,s32,s32);s32 Divide(s32,s32);
s32 IsCellInPlayerMoveRange(s32,s32,s32);s32 IsCaptureTargetAt(void *,s32,s32);s32 func_ov000_021a93a8(void *,s32,s32);
void *base,*cell; s32 moveCost,score,terrain,threat;
if(x<0||y<0||x>=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)||y>=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT))return -1;
if(IsAllyUnitAtCell((s16)x,(s16)y))return -1;
base=*gCurrentMap;
moveCost=M2C_FIELD(M2C_FIELD(base+y*4,s8 **,MAP_GRID),s8 *,x);
if(moveCost<0||moveCost>M2C_FIELD(gAiCommandState,u8 *,5))return -1;
cell=base+(x+M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS));
score=15-moveCost;
terrain=M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN)&31;
threat=M2C_FIELD(cell,u8 *,MAP_CELL_THREAT_DIRECT)+M2C_FIELD(cell,u8 *,MAP_CELL_THREAT_INDIRECT)*2;
if(score<0)score=0;
if(gUnitKindFlags[((u32)(*M2C_FIELD(base,u8 **,MAP_CURSOR_UNIT)<<26)>>26)*112]&7){
u32 index=y*M2C_FIELD(base,u16 *,MAP_WIDTH)+x;
if((u8)((1<<(index&7))&gAiRangeBitmap[index>>3]))score+=16;
}
if(!gTerrainPropertyType[terrain]||!IsTerrainOnUnitTeam(M2C_FIELD(base,u8 *,MAP_CURSOR_UNIT_ID),M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN),gTerrainPropertyType[terrain])){
base=*gCurrentMap;
score+=(Divide(GetTerrainMoveCost(M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER),(u32)(*M2C_FIELD(base,u8 **,MAP_CURSOR_UNIT)<<26)>>26,terrain),10)+1)<<5;
}
if(IsCellInPlayerMoveRange(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),x,y))score+=0x200;
score+=(0x300-threat)<<10;
if(!gTerrainPropertyType[terrain]&&IsCaptureTargetAt(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),x,y)==1)score+=0x100000;
if(func_ov000_021a93a8(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),x,y)==1)score+=0x200000;
if(threat<20)score+=0x400000;
return score;
}

/* Finds the highest-scoring tile orthogonally adjacent to (originX,originY),
 * writing it to out.  Unlike FindBestAdjacentDestination it does not require the
 * cursor unit to be able to stand on the tile, so callers use it to pick a tile
 * to attack from.  Returns 1 if a tile was found, 0 otherwise. */
s32 FindBestAdjacentTile(s32 originX, s32 originY, s16 *outBuf) {
    s32 ScoreMoveDestination(s32, s32);
    extern void **gCurrentMap;
    extern s32 gFrameCounter;
    s32 noResult = MAP_DESTINATION_NONE;
    s32 x = originX;
    s32 y = originY;
    s16 *out = outBuf;
    s32 minX;
    s32 maxY;
    register s32 bestScore = 0, tx, dy0, dy1, ty, maxX, tyS16;
    void *base;
    s32 score;
    s32 adx;
    s32 dist;

    *out = (s16) noResult;
    minX = x - 1;
    if (minX < 0) minX = 0;
    ty = y - 1;
    if (ty < 0) ty = 0;
    base = *gCurrentMap;
    maxX = M2C_FIELD(base, u16 *, MAP_WIDTH) - 1;
    if (x + 1 < maxX) maxX = x + 1;
    maxY = M2C_FIELD(base, u16 *, MAP_HEIGHT) - 1;
    if (y + 1 < maxY) maxY = y + 1;
    if (ty <= maxY) {
        do {
            tx = minX;
            if (tx <= maxX) {
                do {
                    dy0 = y - ty;
                    dy1 = ty - y;
                    tyS16 = ty;
                    adx = x - tx;
                    if (adx <= 0) adx = tx - x;
                    dist = 0;
                    dist = adx + dist;
                    if (dy0 > 0) dist = dist + dy0;
                    else dist = dist + dy1;
                    if (dist >= 1 && dist <= 1  ) {
                        score = ScoreMoveDestination(tx, ty);
                        if (score >= bestScore && (score != bestScore || !(gFrameCounter & 1))) {
                            bestScore = score;
                            out[0] = (s16) tx;
                            out[1] = (s16) tyS16;
                        }
                    }
                    tx++;
                } while (tx <= maxX);
            }
            ty++;
        } while (ty <= maxY);
    }
    if (out[0] == (s16) noResult) return 0;
    return 1;
}

s32 ScoreMoveTile(s32 x,s32 y){
extern void **gCurrentMap;extern void *gAiCommandState;extern s8 gTerrainPropertyType[];
s32 IsAllyUnitAtCell(s16,s16);s32 IsTerrainOnUnitTeam(s32,s32,s32);
s32 GetTerrainMoveCost(s32,s32,s32);s32 Divide(s32,s32);
s32 IsCellInPlayerMoveRange(s32,s32,s32);s32 IsCaptureTargetAt(void *,s32,s32);s32 func_ov000_021a93a8(void *,s32,s32);
void *base,*cell; s32 moveCost,score,terrain,threat;
/* Score a tile as a movement destination for the AI unit under the cursor:
   remaining movement, terrain value, threat and positional preferences. */
if(x<0||y<0||x>=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)||y>=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT))return -1;
if(IsAllyUnitAtCell((s16)x,(s16)y))return -1;
base=*gCurrentMap;
moveCost=M2C_FIELD(M2C_FIELD(base+y*4,s8 **,MAP_GRID),s8 *,x);
if(moveCost<0||moveCost>M2C_FIELD(gAiCommandState,u8 *,5))return -1;
cell=base+(x+M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS));
score=15-moveCost;
terrain=M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK;
threat=M2C_FIELD(cell,u8 *,MAP_CELL_THREAT_DIRECT)+M2C_FIELD(cell,u8 *,MAP_CELL_THREAT_INDIRECT)*2;
if(score<0)score=0;
if(!gTerrainPropertyType[terrain]||!IsTerrainOnUnitTeam(M2C_FIELD(base,u8 *,MAP_CURSOR_UNIT_ID),M2C_FIELD(cell,u8 *,MAP_CELL_TERRAIN),gTerrainPropertyType[terrain])){
base=*gCurrentMap;
score+=(Divide(GetTerrainMoveCost(M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER),(u32)(*M2C_FIELD(base,u8 **,MAP_CURSOR_UNIT)<<26)>>26,terrain),10)+1)<<5;
}
if(IsCellInPlayerMoveRange(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),x,y))score+=0x200;
score+=(0x300-threat)<<10;
if(!gTerrainPropertyType[terrain]&&IsCaptureTargetAt(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),x,y)==1)score+=0x100000;
if(func_ov000_021a93a8(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),x,y)==1)score+=0x200000;
if(threat<20)score+=0x400000;
return score;
}

/* Find the best movement destination within unit's range. Returns 1 and stores
 * position in out[0..1] if found, returns 0 if no valid destination. */
s32 func_ov000_02178268(s32 x, s32 y, s16 *out) {
    extern void **gCurrentMap;
    extern u8 gUnitKindStats[];
    extern s32 gFrameCounter;
    s32 GetUnitAttackRangeMax(u8 *);
    s32 ScoreMoveTile(s32, s32);

    s32 best; s32 inner; s32 dist; s32 r7;
    s32 magic;
    s32 spC;
    s32 r8;
    s32 r9;
    s32 sp8;
    s32 ret;
    s32 ret2;
    s32 r2v;
    s32 wlim;
    s32 r1v;
    s32 hlim;
    u8 *up;void *map;
    u32 kind;
    s32 tableVal;
    s32 cap;
    s32 cost;
    s32 outerY;
    s32 r11;
    s32 outerS16;
    s32 adx;

    magic = 0x270F;
    best = 0;

    *out = (s16)magic;

    up = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0);
    ret = GetUnitAttackRangeMax(up);
    if (x - ret < 0) {
        spC = 0;
    } else {
        ret2 = GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
        spC = x - ret2;
    }

    up = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0);
    ret = GetUnitAttackRangeMax(up);
    if (y - ret < 0) {
        r8 = 0;
    } else {
        ret2 = GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
        r8 = y - ret2;
    }

    map=*gCurrentMap;
    ret=GetUnitAttackRangeMax(M2C_FIELD(map,u8 **,0x52d0));
    if(x+ret>=M2C_FIELD(map,u16 *,0x5144)-1)
        r9=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
    else r9=x+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
    map=*gCurrentMap;
    ret=GetUnitAttackRangeMax(M2C_FIELD(map,u8 **,0x52d0));
    if(y+ret>=M2C_FIELD(map,u16 *,0x5146)-1)
        sp8=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
    else sp8=y+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));

    if (r8 <= sp8) {
        do {
            inner = spC;
            if (inner <= r9) {
                do {
                    outerY = r8;
                    r7 = y - outerY;
                    r11 = outerY - y;
                    adx = x - inner;
                    if (adx <= 0) adx = inner - x;
                    dist = 0;
                    if(x-inner>0)dist+=x-inner;else dist+=inner-x;
                    if(r7>0)dist+=r7;else dist+=r11;

                    up = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0);
                    kind = (((u32)(up[0] << 26)) >> 26);
                    tableVal = gUnitKindStats[kind * 0x70 + 0x0c];

                    if (dist >= tableVal) {
                        cap = GetUnitAttackRangeMax(up);
                        if (dist <= cap) {
                            cost = ScoreMoveTile(inner, outerY);
                            if (cost >= best) {
                                if (cost != best || !(gFrameCounter & 1)) {
                                    best = cost;
                                    out[0] = (s16)inner;
                                    out[1] = (s16)r8;
                                }
                            }
                        }
                    }
                    inner++;
                } while (inner <= r9);
            }
            r8++;
        } while (r8 <= sp8);
    }

    if (out[0] == (s16)magic) return 0;
    return 1;
}

/* Finds the highest-scoring move destination among the tiles orthogonally
 * adjacent to (x,y) that the cursor unit can stand on, writing it to out;
 * returns 1 if a destination was found, 0 otherwise. */
s32 FindBestAdjacentDestination(s32 arg0, s32 arg1, s16 *arg2) {
    s32 ScoreMoveDestination(s32, s32);
    s32 CanUnitKindStandAt(u32, s32, s32);
    extern void **gCurrentMap;
    extern s32 gFrameCounter;
    s32 noResult = 0x270F;
    s32 x = arg0;
    s32 y = arg1;
    s16 *out = arg2;
    s32 minX;
    s32 maxY;
    register s32 bestScore = 0, tx, dy0, dy1, ty, maxX, tyS16;
    void *base;
    s32 score;
    s32 adx;
    s32 dist;

    *out = (s16) noResult;
    minX = x - 1;
    if (minX < 0) minX = 0;
    ty = y - 1;
    if (ty < 0) ty = 0;
    base = *gCurrentMap;
    maxX = M2C_FIELD(base, u16 *, MAP_WIDTH) - 1;
    if (x + 1 < maxX) maxX = x + 1;
    maxY = M2C_FIELD(base, u16 *, MAP_HEIGHT) - 1;
    if (y + 1 < maxY) maxY = y + 1;
    if (ty <= maxY) {
        do {
            tx = minX;
            if (tx <= maxX) {
                do {
                    dy0 = y - ty;
                    dy1 = ty - y;
                    tyS16 = ty;
                    adx = x - tx;
                    if (adx <= 0) adx = tx - x;
                    dist = 0;
                    dist = adx + dist;
                    if (dy0 > 0) dist = dist + dy0;
                    else dist = dist + dy1;
                    if (dist >= 1 && dist <= 1 && CanUnitKindStandAt((u32)(*M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT)<<26)>>26,tx,ty)) {
                        score = ScoreMoveDestination(tx, ty);
                        if (score >= bestScore && (score != bestScore || !(gFrameCounter & 1))) {
                            bestScore = score;
                            out[0] = (s16) tx;
                            out[1] = (s16) tyS16;
                        }
                    }
                    tx++;
                } while (tx <= maxX);
            }
            ty++;
        } while (ty <= maxY);
    }
    if (out[0] == (s16) noResult) return 0;
    return 1;
}

/* Pick the enemy player's headquarters tile nearest by the move-cost grid: scan
 * players 1..4 for an active opponent with a headquarters and keep the HQ whose
 * tile has the lowest grid value.  Writes the tile to out[0] (x) and out[1] (y);
 * returns nonzero when one was found. */
u8 SelectEnemyHqDestination(s16 *out) {
    s32 IsPlayerActive(s32);
    s32 PlayerHasHq(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    s32 best = 0x7fff, player, playerOffset, hqX, hqY, gridValue;
    void *map, *playerRec;

    for (player = 1, playerOffset = MAP_PLAYER_STRIDE; player < 5; player++, playerOffset += MAP_PLAYER_STRIDE) {
        if (IsPlayerActive(player) && !IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) && PlayerHasHq(player)) {
            map = *gCurrentMap;
            playerRec = (u8 *)map + playerOffset;
            hqX = M2C_FIELD(playerRec, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_X) & 127;
            hqY = M2C_FIELD(playerRec, u8 *, MAP_PLAYER_STATES + PLAYER_REC_HQ_Y) & 127;
            gridValue = M2C_FIELD(M2C_FIELD((u8 *)map + hqY * 4, s8 **, MAP_GRID), s8 *, hqX);
            if (gridValue >= 0) {
                if (gridValue <= best) {
                    out[0] = hqX;
                    best = gridValue;
                    out[1] = hqY;
                }
            }
        }
    }
    return best != 0x7fff;
}
