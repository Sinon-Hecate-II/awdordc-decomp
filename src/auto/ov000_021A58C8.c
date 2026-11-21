/* 19 functions from 0x021A58C8 to 0x021A686C (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 pad[3]; u8 used:1; u8 rest:7; } Candidate1F14;
typedef struct { u8 x,y; u8 unk[10]; } UnkA66Entry;

#pragma opt_strength_reduction off
/* Folds the reachable cells of every type-22 indirect unit of `player` into the
 * map's score layer, keeping the lowest distance per cell; a unit is skipped when
 * one of the acting player's healthy type-23 units already stands in its reach. */
void MarkPlayerIndirectThreat(u8 player) {
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    s32 IsCurrentPlayerUnit(u8);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 id, x, y, v, unitOffset;
    s32 x2, y2;
    u8 *tile;
    s32 oldValue;
    void *base;
    u8 *unit;

    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = player;
    id = gPlayerUnitIdBase[player] + 1;
    if (id >= gPlayerUnitIdBase[player] + 51) return;
    unitOffset = id * MAP_UNIT_STRIDE;
    do {
        base = *gCurrentMap;
        unit = (u8 *)(base + MAP_UNIT_RECORDS) + unitOffset;
        if (((u32)(unit[0] << 26) >> 26) == 0) goto next;
        if (((u32)(unit[0] << 26) >> 26) != 22) goto next;
        if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) <= 20) goto next;
        FloodFillUnitRange(unit[1], unit[2], 23, 110, 32);
        base = *gCurrentMap;
        for (y = 0; y < M2C_FIELD(base, u16 *, MAP_HEIGHT); y++) {
            for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++, base = *gCurrentMap) {
                if (M2C_FIELD(base + y * 4, s8 **, MAP_GRID)[x] < 0) continue;
                if (!IsCurrentPlayerUnit(M2C_FIELD(M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, MAP_CELL_UNIT_ID))) continue;
                base = *gCurrentMap;
                unit = (u8 *)(base + MAP_UNIT_RECORDS) + M2C_FIELD(M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS) + (base + x), u8 *, 0) * MAP_UNIT_STRIDE;
                if (((u32)(unit[0] << 26) >> 26) != 23) continue;
                if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) >= 40) goto next;
            }
        }
        for (y2 = 0; y2 < M2C_FIELD(base, u16 *, MAP_HEIGHT); y2++) {
            for (x2 = 0; x2 < M2C_FIELD(base, u16 *, MAP_WIDTH); x2++, base = *gCurrentMap) {
                v = M2C_FIELD(base + y2 * 4, s8 **, MAP_GRID)[x2];
                if (v < 0) continue;
                tile = (u8 *)(base + x2 + M2C_FIELD(base + y2 * 2, u16 *, MAP_ROW_OFFSETS));
                oldValue = M2C_FIELD(tile, s8 *, MAP_CELL_SCORE);
                if (v <= oldValue) M2C_FIELD(tile + 0x2000, s8 *, 0x338) = v;
            }
        }
    next:;
        id++;
        unitOffset += MAP_UNIT_STRIDE;
    } while (id < gPlayerUnitIdBase[player] + 51);
}
#pragma opt_strength_reduction reset
/* Rebuilds the map's indirect-threat score layer: clear the score layer, select
 * the layer the range fills work in, mark the indirect-attack threat of every
 * other player, then restore the player whose units are being processed. */
void BuildIndirectThreatMap(void) {
    void FillMapLayer(s32);
    void SelectMapLayer(void *);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void MarkPlayerIndirectThreat(u8);
    extern void **gCurrentMap;
    u16 savedPlayer;
    s32 player;
    void *map;
    map = *gCurrentMap;
    savedPlayer = M2C_FIELD(map, u16 *, MAP_ACTIVE_PLAYER);
    SelectMapLayer(map + MAP_CELL_SCORE);
    FillMapLayer(MAP_CELL_UNSET);
    SelectMapLayer(*gCurrentMap + MAP_CELL_ORDER);
    for (player = 1; player < 5; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0)
            MarkPlayerIndirectThreat(player);
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

#pragma opt_strength_reduction off
void MarkPlayerRangeThreat(u8 arg0) {
    void FloodFillUnitRange(s32,s32,s32,s32,s32);
    void MI_CpuFill8(void*,s32,s32);
    s32 IsUnitOnCurrentTeam(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gAiRangeLayer[];
    void *base;
    u8 *unit, *tile;
    s8 *p;
    s32 id, unitOffset, count;
    s32 x, y, x2, y2;
    s32 index;
    s32 v, old;
    M2C_FIELD(*gCurrentMap,u16*,0x52B6)=arg0;
    id=gPlayerUnitIdBase[arg0]+1;
    if(id>=gPlayerUnitIdBase[arg0]+51)return;
    unitOffset=id*14;
    do {
        unit=(u8 *)(*gCurrentMap+0x59A4)+unitOffset;
        if(((u32)(unit[0]<<26)>>26)==0)goto next;
        if(((u32)(unit[0]<<26)>>26)!=20 && ((u32)(unit[0]<<26)>>26)!=21)goto next;
        if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)<=20)goto next;
        FloodFillUnitRange(unit[1],unit[2],22,110,32);
        count=0;
        MI_CpuFill8(gAiRangeLayer,0x7F,0x508);
        for(y=0,base=*gCurrentMap;y<M2C_FIELD(base,u16 *,0x5146);y++){
            for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++,base=*gCurrentMap){
                if(M2C_FIELD(base+y*4,s8 **,0x52E8)[x]<0)continue;
                unit=(u8 *)(base+0x59A4)+M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16 *,0x3758),u8 *,0)*14;
                index=unit?((s32)(unit-(u8 *)(base+0x59A4)))/14:0;
                if(IsUnitOnCurrentTeam(index)==0){
                    if(((u32)(unit[0]<<26)>>26)!=20 && ((u32)(unit[0]<<26)>>26)!=21)continue;
                    if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)<=20)continue;
                    count++;
                    base=*gCurrentMap;
                    for(y2=0;y2<M2C_FIELD(base,u16 *,0x5146);y2++){
                        p=(s8 *)gAiRangeLayer;
                        for(x2=0;x2<M2C_FIELD(base,u16 *,0x5144);x2++,base=*gCurrentMap,p++){
                            v=M2C_FIELD(base+y2*4,s8 **,0x52E8)[x2];
                            if(v<0)continue;
                            if(v<M2C_FIELD(p,s8 *,y2*M2C_FIELD(base,u16 *,0x5144)))
                                M2C_FIELD(p,s8 *,y2*M2C_FIELD(base,u16 *,0x5144))=v;
                        }
                    }
                } else {
                    if(((u32)(unit[0]<<26)>>26)!=22)continue;
                    if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)>=60)goto next;
                }
            }
        }
        if(count<1)goto next;
        for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
            p=(s8 *)gAiRangeLayer;
            for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++,base=*gCurrentMap,p++){
                v=M2C_FIELD(p,s8 *,y*M2C_FIELD(base,u16 *,0x5144));
                tile=(u8 *)(base+x+M2C_FIELD(base+y*2,u16 *,0x3758));
                old=M2C_FIELD(tile,s8 *,0x2338);
                if(v<old)M2C_FIELD(tile+0x2000,s8 *,0x338)=v;
            }
        }
        next:;
        id++;unitOffset+=14;
    } while(id<gPlayerUnitIdBase[arg0]+51);
}
#pragma opt_strength_reduction reset
/* Rebuilds the map's score layer from the range fills of every other player's
 * units, folding each into gAiRangeLayer: clear the score layer, select the
 * layer the fills work in, mark each other player, then restore the player whose
 * units are being processed.  The counterpart of BuildIndirectThreatMap. */
void BuildRangeThreatMap(void) {
    void FillMapLayer(s32);
    void SelectMapLayer(void *);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    void MarkPlayerRangeThreat(u8);
    extern void **gCurrentMap;
    u16 savedPlayer;
    s32 player;
    void *map;
    map = *gCurrentMap;
    savedPlayer = M2C_FIELD(map, u16 *, MAP_ACTIVE_PLAYER);
    SelectMapLayer(map + MAP_CELL_SCORE);
    FillMapLayer(MAP_CELL_UNSET);
    SelectMapLayer(*gCurrentMap + MAP_CELL_ORDER);
    for (player = 1; player < 5; player++) {
        if (IsPlayerActive(player) != 0 && IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), player) == 0)
            MarkPlayerRangeThreat(player);
    }
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ACTIVE_PLAYER) = savedPlayer;
}

/* Return the index of the first usable AI target candidate of `type`
 * (AI_CANDIDATE_TYPE_ANY matches every type), or -1 when there is none. */
s32 FindAiTargetOfType(s32 type) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *candidate;
s32 i;
candidate = (u8 *)&gAiTargetCandidates;
for (i = 0; i < *gAiState; i++, candidate += AI_CANDIDATE_STRIDE) {
if ((u32)candidate[AI_CANDIDATE_STATUS] < AI_CANDIDATE_REJECTED && (type == AI_CANDIDATE_TYPE_ANY || candidate[AI_CANDIDATE_TYPE] == type)) return i;
}
return -1;
}

/* Return the index of the usable target candidate of the given type with the most
 * enemy units that can reach it (type AI_CANDIDATE_TYPE_ANY matches every type),
 * or -1 when there is none. */
s32 FindTargetCandidateByEnemyCount(s32 type) {
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetCandidates;
    u8 *candidate;
    s32 i;
    s32 best;
    s32 result;
    u8 count;

    best = 0;
    result = -1;
    candidate = (u8 *)&gAiTargetCandidates;
    for (i = 0; i < gAiState[AI_STATE_TARGET_COUNT]; i++, candidate += AI_CANDIDATE_STRIDE) {
        if (((u32)candidate[AI_CANDIDATE_STATUS] < AI_CANDIDATE_REJECTED) &&
            ((type == AI_CANDIDATE_TYPE_ANY) || (candidate[AI_CANDIDATE_TYPE] == type))) {
            count = candidate[AI_PROPERTY_CANDIDATE_ENEMY_COUNT];
            if (best < (s32)count) {
                best = count;
                result = i;
            }
        }
    }
    return result;
}

/* Picks the AI target candidate of targetType (AI_CANDIDATE_TYPE_ANY for any
 * type) that is nearest to a capturable property (AI_CANDIDATE_PROPERTY_DISTANCE),
 * the first candidate winning a tie.  A candidate whose status is
 * AI_CANDIDATE_REJECTED or beyond has been given up on and is skipped.
 * Returns the candidate index, or -1 when there is none. */
s32 FindAiTargetByPropertyDistance(s32 targetType) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *candidate;
s32 index;
s32 bestDistance;
s32 bestIndex;
u8 propertyDistance;
bestDistance=0x7FFF;
bestIndex=-1;
candidate=(u8 *)&gAiTargetCandidates;
for(index=0;index<*gAiState;index++,candidate+=AI_CANDIDATE_STRIDE) {
if ((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED && (targetType==AI_CANDIDATE_TYPE_ANY || candidate[AI_CANDIDATE_TYPE]==targetType)) {
propertyDistance=candidate[AI_CANDIDATE_PROPERTY_DISTANCE];
if(bestDistance > (s32)propertyDistance) {bestDistance=propertyDistance;bestIndex=index;}
}
}
return bestIndex;
}

/* Picks the AI target candidate of targetType (AI_CANDIDATE_TYPE_ANY for any
 * type) whose AI_CANDIDATE_CAPTURE_DISTANCE is smallest, the first candidate
 * winning a tie.  A candidate whose status is AI_CANDIDATE_REJECTED or beyond
 * has been given up on and is skipped.  Returns the candidate index, or -1 when
 * there is none. */
s32 FindAiTargetByCaptureDistance(s32 targetType) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates;
u8 *candidate;
s32 index;
s32 bestDistance;
s32 bestIndex;
u8 captureDistance;
bestDistance=0x7FFF;
bestIndex=-1;
candidate=(u8 *)&gAiTargetCandidates;
for(index=0;index<*gAiState;index++,candidate+=AI_CANDIDATE_STRIDE) {
if ((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED && (targetType==AI_CANDIDATE_TYPE_ANY || candidate[AI_CANDIDATE_TYPE]==targetType)) {
captureDistance=candidate[AI_CANDIDATE_CAPTURE_DISTANCE];
if(bestDistance > (s32)captureDistance) {bestDistance=captureDistance;bestIndex=index;}
}
}
return bestIndex;
}

/* Picks the AI target candidate of `type` (4 = any type) in the group the AI
 * can capture soonest: the smallest AI_CANDIDATE_CAPTURE_DISTANCE (distance from
 * the candidate tile to the closest capture unit of the acting player), looking
 * only at candidates whose target group still holds properties.  The first
 * candidate wins a tie.  Returns the candidate index, or -1 when there is none. */
s32 FindBestCaptureTargetCandidate(s32 type) {
 extern u8 *gAiState;
 extern M2C_UNK gAiTargetCandidates,gAiTargetGroups;
 u8 *candidate; s32 i,bestDistance,bestIndex,distance;
 bestDistance=0x7fff;bestIndex=-1;candidate=(u8 *)&gAiTargetCandidates;
 for(i=0;i<*gAiState;i++,candidate+=AI_CANDIDATE_STRIDE){
 if((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED && ((u8 *)&gAiTargetGroups)[(s8)candidate[AI_CANDIDATE_GROUP]*AI_GROUP_STRIDE+AI_GROUP_PROPERTIES] && (type==4 || candidate[AI_CANDIDATE_TYPE]==type)){
 distance=candidate[AI_CANDIDATE_CAPTURE_DISTANCE];
 if(bestDistance>(s32)distance){bestDistance=distance;bestIndex=i;}
 }
 }
 return bestIndex;
}

/* Picks the build target for `player` (4 = any player) from the AI's candidate
 * records: the one with the smallest combat distance whose capture distance is
 * not above the best score, preferring the earlier record on an equal combat
 * distance when that record's combat target was not nearer than its capture
 * target. Returns the record index, -1 when there is none. */
s32 FindAiBuildTargetCandidate(s32 player) {
extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates;
u8 *candidate; s32 index,bestScore,bestIndex,keepOnTie; u8 captureDistance,combatDistance; s32 count;
bestScore=0x7fff; bestIndex=bestScore-0x8000; keepOnTie=0; index=0; count=*gAiState; candidate=(u8 *)&gAiTargetCandidates;
if(count>0) { for(;index<*gAiState;index++,candidate+=AI_CANDIDATE_STRIDE) { if((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED && (player==4 || candidate[AI_CANDIDATE_TYPE]==player)) {
captureDistance=candidate[AI_CANDIDATE_CAPTURE_DISTANCE]; if(bestScore>=captureDistance) { combatDistance=candidate[AI_CANDIDATE_COMBAT_DISTANCE]; if(!(bestScore==combatDistance && keepOnTie==1)) {bestScore=combatDistance;bestIndex=index;if((u32)combatDistance>=(u32)captureDistance) keepOnTie=1;else keepOnTie=0;} }
} } }return bestIndex; }

/* Picks the AI target candidate of `type` (4 = any type) whose closest enemy is
 * nearest (AI_PROPERTY_CANDIDATE_ENEMY_DISTANCE), the first one on a tie.  A base
 * candidate (type 1) that sits in a target group flagged AI_GROUP_FLAG_PROPERTY
 * has 255 added to its distance, so it is only used as a last resort. */
s32 FindNearestTargetCandidateOfType(s32 type) {
extern u8 *gAiState;
extern M2C_UNK gAiTargetCandidates,gAiTargetGroups;
u8 *candidate; s32 i,bestDistance,bestIndex,distance;
bestDistance=0x7fff;bestIndex=-1;candidate=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,candidate+=AI_CANDIDATE_STRIDE){
if((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED && (type==4 || candidate[AI_CANDIDATE_TYPE]==type)){
distance=candidate[AI_PROPERTY_CANDIDATE_ENEMY_DISTANCE];
if(candidate[AI_CANDIDATE_TYPE]==1 && (((u32)((u8 *)&gAiTargetGroups)[(s8)candidate[AI_CANDIDATE_GROUP]*AI_GROUP_STRIDE+AI_GROUP_FLAGS]<<29)>>31))distance+=255;
if(bestDistance>distance){bestDistance=distance;bestIndex=i;}
}
}
return bestIndex;
}

/* Select the active candidate in a target group whose tile is nearest to its closest enemy. */
s32 FindAiTargetCandidateByEnemyDistanceAndGroup(s32 targetType, s32 targetGroup) {
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetCandidates;
    u8 *candidate;
    s32 i;
    s32 bestDistance;
    s32 bestIndex;
    u8 enemyDistance;

    bestDistance = 0x7fff;
    bestIndex = -1;
    candidate = (u8 *)&gAiTargetCandidates;
    for (i = 0; i < *gAiState; i++, candidate += AI_CANDIDATE_STRIDE) {
        if ((u32)candidate[AI_CANDIDATE_STATUS] < 0xFCU &&
            (targetType == 4 || candidate[AI_CANDIDATE_TYPE] == targetType) &&
            (s8)candidate[AI_CANDIDATE_GROUP] == targetGroup) {
            enemyDistance = candidate[AI_CANDIDATE_ENEMY_GROUP_DISTANCE];
            if (bestDistance > enemyDistance) {
                bestDistance = enemyDistance;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}

/* Pick the eligible target in this group with the most counted enemies, or return -1 if none has any. */
s32 FindBestCandidateInGroup(s32 targetType, s32 targetGroup) {
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetCandidates;
    u8 *candidate;
    s32 i, bestEnemyCount, bestIndex;
    u8 enemyCount;

    bestEnemyCount = 0;
    bestIndex = -1;
    candidate = (u8 *)&gAiTargetCandidates;
    for (i = 0; i < gAiState[AI_STATE_TARGET_COUNT]; i++, candidate += AI_CANDIDATE_STRIDE) {
        if ((u32)candidate[AI_CANDIDATE_STATUS] < AI_CANDIDATE_REJECTED &&
            (targetType == AI_CANDIDATE_TYPE_ANY || candidate[AI_CANDIDATE_TYPE] == targetType) &&
            (s8)candidate[AI_CANDIDATE_GROUP] == targetGroup) {
            enemyCount = candidate[AI_PROPERTY_CANDIDATE_ENEMY_COUNT];
            if (bestEnemyCount < enemyCount) {
                bestEnemyCount = enemyCount;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}

/* Return the index of the usable AI target candidate with the highest
   AI_CANDIDATE_UNIT_BALANCE (friendly minus enemy units that can reach its tile),
   or -1 when no candidate has a positive balance. */
s32 FindTargetCandidateByUnitBalance(void) { extern u8 *gAiState; extern M2C_UNK gAiTargetCandidates;
u8 *candidate; s32 i; s32 best; s32 result; s8 balance;
best=0; result=-1; candidate=(u8 *)&gAiTargetCandidates;
for(i=0;i<*gAiState;i++,candidate+=AI_CANDIDATE_STRIDE) { if((u32)candidate[AI_CANDIDATE_STATUS]<AI_CANDIDATE_REJECTED) { balance=(s8)candidate[AI_CANDIDATE_UNIT_BALANCE]; if(best < (s32)balance) {best=balance;result=i;} } } return result; }

#pragma opt_lifetimes off
/* Pick a target candidate of `type` (4 = any type) from the AI's best-scoring
 * unclaimed target group: take the highest-scoring group, ask
 * FindBestCandidateInGroup for its best candidate, and claim the group when it
 * has none.  Returns the candidate index, or -1 when no group is left. */
s32 FindTargetInBestGroup(s32 type) {
 void ReleaseAiTargetGroups(void); s32 FindBestCandidateInGroup(s32,s32);
 extern u8 *gAiState; extern M2C_UNK gAiTargetGroups;
 u8 *group; s32 result; s32 i; s32 candidate; s32 best;
 group=(u8 *)&gAiTargetGroups; best=0; ReleaseAiTargetGroups();
 for(;;) { result=-1; for(i=0;i<(s32)gAiState[AI_STATE_GROUP_COUNT];i++,group+=AI_GROUP_STRIDE) { if(group[AI_GROUP_CLAIMED]!=255 && best<(s32)group[AI_GROUP_SCORE]) { best=group[AI_GROUP_SCORE];result=i; } } if(result==-1)return -1; candidate=FindBestCandidateInGroup(type,result); if(candidate!=-1)return candidate; group[AI_GROUP_CLAIMED]=255; }
}
#pragma opt_lifetimes reset
/* Index of the nearest (smallest AI_CANDIDATE_PROPERTY_DISTANCE) target
 * candidate of `targetType` (4 = any type) in `targetGroup`; -1 when the group
 * has none.  The counterpart of FindAiTargetCandidateByEnemyDistanceAndGroup,
 * which ranks candidates by their distance to the closest enemy. */
s32 FindNearestPropertyCandidateInGroup(s32 targetType, s32 targetGroup) {
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetCandidates;
    u8 *candidate;
    s32 i;
    s32 bestDistance;
    s32 bestIndex;
    u8 propertyDistance;

    bestDistance = 0x7fff;
    bestIndex = -1;
    candidate = (u8 *)&gAiTargetCandidates;
    for (i = 0; i < *gAiState; i++, candidate += AI_CANDIDATE_STRIDE) {
        if ((u32)candidate[AI_CANDIDATE_STATUS] < AI_CANDIDATE_REJECTED &&
            (targetType == 4 || candidate[AI_CANDIDATE_TYPE] == targetType) &&
            (s8)candidate[AI_CANDIDATE_GROUP] == targetGroup) {
            propertyDistance = candidate[AI_CANDIDATE_PROPERTY_DISTANCE];
            if (bestDistance > (s32)propertyDistance) {
                bestDistance = propertyDistance;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}

/* Picks the AI's build target for a basic unit: the nearest property (type 1)
 * candidate inside the first target group that no build has claimed yet. Groups
 * without such a candidate are marked claimed and skipped. Returns the candidate
 * index, or -1 when no group is left. */
s32 FindBasicUnitTargetCandidate(void) {
    void ReleaseAiTargetGroups(void);
    s32 FindNearestPropertyCandidateInGroup(s32, s32);
    extern u8 *gAiState;
    extern M2C_UNK gAiTargetGroups;
    s32 groupIndex;
    s32 i;
    s32 candidate;
    u8 *group;

    group = (u8 *)&gAiTargetGroups;
    ReleaseAiTargetGroups();
    for (;;) {
        groupIndex = -1;
        for (i = 0; i < (s32)gAiState[AI_STATE_GROUP_COUNT]; i++, group += AI_GROUP_STRIDE) {
            if (group[AI_GROUP_CLAIMED] != 255 && ((Candidate1F14 *)group)->used == 0) {
                groupIndex = i;
                break;
            }
        }
        if (groupIndex == -1) return -1;
        candidate = FindNearestPropertyCandidateInGroup(1, groupIndex);
        if (candidate != -1) return candidate;
        group[AI_GROUP_CLAIMED] = 255;
    }
}

#pragma optimization_level 3
s32 FindNavalThreatBuildCandidate(void) {
void ReleaseAiTargetGroups(void);
extern M2C_UNK gAiTargetGroups,gAiTargetCandidates;extern u8 *gAiState;extern void **data_027e0058;
u8 *p=(u8 *)&gAiTargetGroups; s32 found,i,r;u8 *entry;void *map;u8 *base;s32 offset;
ReleaseAiTargetGroups();
for(;;){
found=-1;
for(i=0;i<gAiState[1];i++,p+=8){
if(p[1]!=255 && ((u32)(p[3]<<30)>>31)){found=i;break;}
}
if(found==-1)return -1;
r=FindBestCandidateInGroup(1,found);
if(r!=-1)r=FindAiTargetCandidateByEnemyDistanceAndGroup(1,found);
if(r==-1)break;
offset = r * 12;
base = (u8 *)&gAiTargetCandidates;
map = *data_027e0058;
entry = base + offset;
{u16 row = M2C_FIELD(map + entry[1] * 2, u16 *, 0x3758);map = map + base[offset] + row;}
map = map + 0x2000;
if(M2C_FIELD(map,u8 *,0x840)<50 && M2C_FIELD(map,u8 *,0xd48)<50)return r;
p[1]=255;
}
return r;
}
#pragma optimization_level 4
/* Picks the AI's target candidate of `targetType` (AI_CANDIDATE_TYPE_ANY for any
 * type) for one of its units: from the best-scoring target group when the AI has
 * more than one, otherwise the candidate with the most reachable enemies, then the
 * nearest candidate of the type, then the first one of the type.  Returns the
 * candidate index, or -1 when there is none. */
s32 FindAiTargetCandidate(s32 targetType) {
    extern u8 *gAiState;
    s32 FindTargetInBestGroup(s32);
    s32 FindTargetCandidateByEnemyCount(s32);
    s32 FindNearestTargetCandidateOfType(s32);
    s32 FindAiTargetOfType(s32);
    s32 result = -1;

    if (gAiState[AI_STATE_GROUP_COUNT] >= 2) result = FindTargetInBestGroup(targetType);
    if (result == -1) result = FindTargetCandidateByEnemyCount(targetType);
    if (result == -1) result = FindNearestTargetCandidateOfType(targetType);
    if (result == -1) result = FindAiTargetOfType(targetType);
    return result;
}

