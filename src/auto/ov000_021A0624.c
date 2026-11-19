/* 8 functions from 0x021A0624 to 0x021A11B0 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
#include "ov000_ai.h"
#include "battle_map.h"
extern u8 gAiTargetCandidateType[];
extern u8 gUnitKindFlags[];
extern void **gCurrentMap;

/* Count the current player's foot units whose AI role flag (bit 4 of the unit's
 * AI state byte) equals holdFlag, skipping unit excludedUnitId. */
u8 CountFootUnitsWithAiFlag(s32 excludedUnitId, s32 holdFlag) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 IsFootUnitKind(void);
    s32 count = 0;
    s32 unitId;
    void *map = *gCurrentMap;
    u16 start = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    for (unitId = start + 1; unitId < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; unitId++) {
        UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS))[unitId];
        if (entry->unk0 != 0 && unitId != excludedUnitId && IsFootUnitKind() != 0 && holdFlag == entry->unkB_4) count++;
    }
    return count;
}

/* Returns the AI state (MAP_UNIT_AI_STATE) a unit of kind `kind` starts with:
 * 0 for foot units and kinds that cannot attack (and by default), 10 on the
 * special map 0xae for player 3, 5 while the AI is in phase 12, and 4 for an
 * indirect unit when fog of war or snow is up. */
s32 SelectAiUnitState(M2C_UNK kind) {
s32 IsFootUnitKind(); s32 GetUnitAttackClass(M2C_UNK); s32 GetKindAttackClass(M2C_UNK);
extern u16 gMapConfig; extern void **gCurrentMap; extern void *gAiState;
void *map;
if(IsFootUnitKind()!=0 || GetKindAttackClass(kind)==UNIT_ATTACK_NONE)return 0;
if(!(((u32)(gMapConfig<<29)>>29)&255)) { /* gMapConfig low three bits: battle mode, 0 = team mode */
map=*gCurrentMap;
switch(M2C_FIELD(map,u16*,MAP_ID)) {case 0xae: if(M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)==3)return 10; break;default:break;}
}
if(M2C_FIELD(gAiState,u8*,AI_STATE_PHASE)==12)return 5;
map=*gCurrentMap;
if(M2C_FIELD(map,u8*,MAP_FOG)!=0 || M2C_FIELD(map,u8*,MAP_WEATHER)==WEATHER_SNOW) {
if(GetUnitAttackClass(kind)==UNIT_ATTACK_INDIRECT)return 4;
}
return 0;
}

void CommitAiAction(s32 arg0) {
s32 func_ov000_021a43e8(); s32 GetUnitAttackClass(M2C_UNK);
extern u8 gAiCommand[]; extern void *gAiState; extern u8 *gAiCommandState;
extern u8 data_ov000_021e00af[],data_ov000_021dfd98[],data_ov000_021dfd99[],data_ov000_021dfd9a[];
extern s8 gAiTargetCandidateGroup[];
s32 offset; s32 index;
gAiCommand[7]=SelectAiUnitState(gAiCommand[6]);
offset=arg0*12;
data_ov000_021e00af[offset]=252;
M2C_FIELD(gAiState,u8*,7)++;
M2C_FIELD(gAiState,u8*,4)=arg0;
if((gUnitKindFlags[(s16)gAiCommand[6]*(s16)112]&7) && func_ov000_021a43e8()==0){
if(GetUnitAttackClass(gAiCommand[6])==0){index=gAiTargetCandidateGroup[offset];data_ov000_021dfd98[index*8]++;}
if(GetUnitAttackClass(gAiCommand[6])==1){index=gAiTargetCandidateGroup[offset];data_ov000_021dfd99[index*8]++;}
if(gAiCommand[6]==26){index=gAiTargetCandidateGroup[offset];data_ov000_021dfd9a[index*8]++;}
}
M2C_FIELD(gAiState,u8*,3)=1;
*gAiCommandState=5;
}

/* Initialise the AI for the current player's turn: collect the target
 * candidates and groups, count the player's units, add up the value of the army
 * (including the units a carrier holds) and turn that into the turn's army
 * budget, then reset the reserve and action state. */
void InitAiTurn(void) {
s32 CollectAiTargetCandidates(void);s32 BuildAiTargetGroups(void);
extern void *gAiState;extern u16 gPlayerUnitIdBase[];
s32 unitId;UnkStruct_ov000_021A860C *unit;
M2C_FIELD(gAiState,u8 *,AI_STATE_TARGET_COUNT)=CollectAiTargetCandidates();
M2C_FIELD(gAiState,u8 *,AI_STATE_GROUP_COUNT)=BuildAiTargetGroups();
M2C_FIELD(gAiState,u8 *,AI_STATE_UNIT_COUNT)=0;
M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)=0;
/* The player's usable unit slots are 1..0x32 after its id base. */
for(unitId=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;unitId<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+0x33;unitId++){
unit=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[unitId];
if(unit->unk0){
M2C_FIELD(gAiState,u8 *,AI_STATE_UNIT_COUNT)++;
if(unit->unk0==UNIT_KIND_CARRIER){
if(M2C_FIELD(unit,u8 *,12))M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)+=GetAiUnitValue(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),0,(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+M2C_FIELD(unit,u8 *,12)*MAP_UNIT_STRIDE);
if(M2C_FIELD(unit,u8 *,13))M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)+=GetAiUnitValue(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),0,(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+M2C_FIELD(unit,u8 *,13)*MAP_UNIT_STRIDE);
}
M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)+=GetAiUnitValue(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER),0,unit);
}
}
M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)=M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)*3>>1;
if(M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)<AI_ARMY_VALUE_MIN)M2C_FIELD(gAiState,s32 *,AI_STATE_ARMY_VALUE)=AI_ARMY_VALUE_MIN;
M2C_FIELD(gAiState,s32 *,AI_STATE_SHORTFALL)=0;
M2C_FIELD(gAiState,u8 *,AI_STATE_RESERVE_RETRY)=2;
M2C_FIELD(gAiState,u8 *,AI_STATE_ACTION)=0;
}

s32 GetAiUnitKindValue(s32 a,s32 unused,s32 c) {
s32 func_020a7bbc(s32);
s32 func_020a886c(s32,s32);
s32 Divide(s32,s32);
s32 n=func_020a7bbc(c);
return Divide(n*(func_020a886c(a,0)+100),100);
}

/* Value the AI assigns to a map unit: the unit's stat-block value plus the
 * capture value when it stands on a capture target, capped by its health (every
 * ten health above zero lowers the cap by one), times the unit kind's
 * player-adjusted value.  Units at 91 health or more are worth nothing. */
s32 GetAiUnitValue(M2C_UNK player, M2C_UNK unused, void *unit) {
s32 Divide(s32,M2C_UNK);
s32 func_020a2668(void *,u8,u8);
s32 func_020a7558(void *);
s32 GetAiUnitKindValue(M2C_UNK,M2C_UNK,s32);
s32 IsCaptureTargetAt(void *,u8,u8);
s32 valueCap,hpPenalty,value;u32 health;
if(((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH)<<25)>>25)>=91)return 0;
value=0;
if(!(M2C_FIELD(unit,u16 *,MAP_UNIT_FLAGS)&8))value+=func_020a2668(unit,M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y));
if(IsCaptureTargetAt(unit,M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y)))value+=func_020a7558(unit);
if(value==0)return 0;
health=(u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH)<<25)>>25;
if(health==0)hpPenalty=0;else hpPenalty=Divide(health-1,10)+1;
valueCap=10-hpPenalty;
if(value>valueCap)value=valueCap;
return value*GetAiUnitKindValue(player,unused,(u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26);
}

#pragma push
#pragma opt_strength_reduction off
/* Groups the AI target candidates into islands that share a movement-reachable
   area, then scores each island: enemy/friendly unit counts, terrain flags and
   the best target tile value. Stores one 8-byte record per group in gAiTargetGroups. */
s32 BuildAiTargetGroups(void) {
    void FloodFillUnitRange(s32,s32,s32,s32,s32);
    s32 IsUnitOnCurrentTeam(s32);
    s32 GetUnitKindMaxAttackRange(s32);
    s32 IsFootUnitKind();
    s32 IsCurrentPlayerUnit(s16);
    s32 func_ov000_021a43e8();
    s32 GetUnitAttackClass(s32);
    s32 func_ov000_021a99dc(void *);
    s32 IsPropertyTerrain(s32);
    s32 IsTerrainOnUnitTeam(s32,s32);
    s32 EvaluateAiTargetGroupForCapture(s32,s32);
    void func_ov000_021a11b0(s32);
    extern void *gAiState;
    extern u8 gAiTargetCandidates[], gAiTargetGroups[], gUnitKindStats[];
    u8 *group;
    UnkStruct_ov000_021A860C *unit;
    s32 unitId;
    u8 statusFlags, typeFlags;
    s32 y, x;
    u8 *candidate;
    u8 *peer;
    s32 index, groupCount, peerIndex, terrainId, terrainValue;
    u8 *base;
    groupCount=0; index=0;
    candidate=gAiTargetCandidates;
    group=gAiTargetGroups;
    for (; index < M2C_FIELD(gAiState,u8 *,0); index++,candidate+=12) {
        if ((s8)candidate[4] != -1) continue;
        FloodFillUnitRange(candidate[0],candidate[1],1,110,0);
        statusFlags=0; typeFlags=0;
        group[0]=0;
        group[3]&=~1;
        group[3]&=~2;
        group[2]=0; group[1]=0; group[4]=0; group[5]=0; group[6]=0;
        for(peerIndex=0,peer=gAiTargetCandidates;peerIndex<M2C_FIELD(gAiState,u8 *,0);peerIndex++,peer+=12) {
            base=*gCurrentMap;
            if ((*(s8 **)(base+peer[1]*4+0x52e8))[peer[0]]>=0) ((s8 *)peer)[4]=(s8)groupCount;
        }
        base=*gCurrentMap;
        for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++) {
            for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++) {
                if ((*(s8 **)(base+y*4+0x52e8))[x]>=0) {
                    unitId=base[x+*(u16 *)(base+y*2+0x3758)];
                    if(unitId) {
                        unit=(UnkStruct_ov000_021A860C *)(base+0x59a4+unitId*14);
                        if(IsUnitOnCurrentTeam(unitId)==1) {
                            if(GetUnitKindMaxAttackRange(unit->unk0)) group[0]--;
                            if(IsFootUnitKind(unit->unk0) && unit->unk6>=61) group[3]=(group[3]&~1)|1;
                            if ((unit->unk0==6 && unit->unkB!=5) || unit->unk0==14) {
                                if(unit->unk6>=61) typeFlags|=1;
                            }
                            if(IsCurrentPlayerUnit((s16)unitId) && (gUnitKindStats[unit->unk0*112+0x13]&7) && !func_ov000_021a43e8(unit->unk0)) {
                                if(GetUnitAttackClass(unit->unk0)==0) group[4]++;
                                if(GetUnitAttackClass(unit->unk0)==1) group[5]++;
                                if(unit->unk0==26) group[6]++;
                            }
                        } else if(!func_ov000_021a99dc(unit)) {
                            group[0]+=2;
                            if ((gUnitKindStats[unit->unk0*112+0x13]&7) && !IsFootUnitKind(unit->unk0)) statusFlags|=1;
                            if ((gUnitKindStats[unit->unk0*112+0x13]&16) && unit->unk0!=19) typeFlags|=2;
                        }
                    }
                    base=*gCurrentMap;
                    terrainId=base[0x1420+x+*(u16 *)(base+y*2+0x3758)];
                    if(IsPropertyTerrain(terrainId)==1) {
                        base=*gCurrentMap;
                        if(!IsTerrainOnUnitTeam(M2C_FIELD(base,s16 *,0x52a8),base[0x1420+x+*(u16 *)(base+y*2+0x3758)])) {
                            base=*gCurrentMap;
                            terrainValue=(*(s8 **)(base+y*4+0x52e8))[x];
                            if(candidate[8]>terrainValue)candidate[8]=terrainValue;
                            statusFlags|=2;
                            group[2]++;
                        }
                    }
                }
                base=*gCurrentMap;
            }
        }
        if ((statusFlags&1) || !(statusFlags&2)) group[3]=(group[3]&~1)|1;
        if (!(typeFlags&1) && (typeFlags&2)) group[3]|=2;
        terrainValue=EvaluateAiTargetGroupForCapture(candidate[0],candidate[1]);
        if ((terrainValue&0x100) || !(terrainValue&255)) group[3]&=~4;
        else group[3]|=4;
        func_ov000_021a11b0(groupCount);
        groupCount++; group+=8;
    }
    return groupCount;
}
#pragma pop
/* Whether an enemy unit counts toward AI target candidate `candidateIndex`:
 * a type-1 candidate wants a visible unit (an empty air unit never counts),
 * a type-3 candidate wants only a kind that cannot attack; other types
 * count nothing. */
s32 AiCandidateIncludesUnit(s32 candidateIndex,void *unit) {
u32 type=gAiTargetCandidateType[candidateIndex*12];
if(type==1){
u32 flags=gUnitKindFlags[((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*112];
if(flags&7){
void *base=*gCurrentMap;
s8 *row=((s8 **)((u8 *)base+0x52e8))[M2C_FIELD(unit,u8 *,MAP_UNIT_Y)];
if(row[M2C_FIELD(unit,u8 *,MAP_UNIT_X)]<0)return 0;
}
if((flags&32) && M2C_FIELD(unit,u8 *,12)==0)return 0;
}
if(type==3){
if(gUnitKindFlags[((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)*112]&7)return 0;
}
return 1;
}

