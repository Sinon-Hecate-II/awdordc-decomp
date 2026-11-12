/* 8 functions from 0x021A0624 to 0x021A11B0 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
#include "ov000_ai.h"
#include "battle_map.h"
extern u8 data_ov000_021e00ae[];
extern u8 gUnitKindFlags[];
extern void **gCurrentMap;

u8 func_ov000_021a0624(s32 a,s32 b) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 IsFootUnitKind(void);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
if(entry->unk0!=0 && i!=a && IsFootUnitKind()!=0 && b==entry->unkB_4) count++;
}
return count;
}

s32 func_ov000_021a06e4(M2C_UNK arg0) {
s32 IsFootUnitKind(); s32 GetUnitAttackClass(M2C_UNK); s32 func_ov000_021a9904(M2C_UNK);
extern u16 gMapConfig; extern void **gCurrentMap; extern void *gAiState;
void *p;
if(IsFootUnitKind()!=0 || func_ov000_021a9904(arg0)==2)return 0;
if(!(((u32)(gMapConfig<<29)>>29)&255)) {
p=*gCurrentMap;
switch(M2C_FIELD(p,u16*,0x5142)) {case 0xae: if(M2C_FIELD(p,u16*,0x52a4)==3)return 10; break;default:break;}
}
if(M2C_FIELD(gAiState,u8*,2)==12)return 5;
p=*gCurrentMap;
if(M2C_FIELD(p,u8*,0x5156)!=0 || M2C_FIELD(p,u8*,0x5158)==2) {
if(GetUnitAttackClass(arg0)==1)return 4;
}
return 0;
}

void CommitAiAction(s32 arg0) {
s32 func_ov000_021a43e8(); s32 GetUnitAttackClass(M2C_UNK);
extern u8 gAiCommand[]; extern void *gAiState; extern u8 *gAiCommandState;
extern u8 data_ov000_021e00af[],data_ov000_021dfd98[],data_ov000_021dfd99[],data_ov000_021dfd9a[];
extern s8 data_ov000_021e00b0[];
s32 offset; s32 index;
gAiCommand[7]=func_ov000_021a06e4(gAiCommand[6]);
offset=arg0*12;
data_ov000_021e00af[offset]=252;
M2C_FIELD(gAiState,u8*,7)++;
M2C_FIELD(gAiState,u8*,4)=arg0;
if((gUnitKindFlags[(s16)gAiCommand[6]*(s16)112]&7) && func_ov000_021a43e8()==0){
if(GetUnitAttackClass(gAiCommand[6])==0){index=data_ov000_021e00b0[offset];data_ov000_021dfd98[index*8]++;}
if(GetUnitAttackClass(gAiCommand[6])==1){index=data_ov000_021e00b0[offset];data_ov000_021dfd99[index*8]++;}
if(gAiCommand[6]==26){index=data_ov000_021e00b0[offset];data_ov000_021dfd9a[index*8]++;}
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

s32 func_ov000_021a0aec(s32 a,s32 unused,s32 c) {
s32 func_020a7bbc(s32);
s32 func_020a886c(s32,s32);
s32 Divide(s32,s32);
s32 n=func_020a7bbc(c);
return Divide(n*(func_020a886c(a,0)+100),100);
}

s32 GetAiUnitValue(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
s32 Divide(s32,M2C_UNK);
s32 func_020a2668(void *,u8,u8);
s32 func_020a7558(void *);
s32 func_ov000_021a0aec(M2C_UNK,M2C_UNK,s32);
s32 IsCaptureTargetAt(void *,u8,u8);
s32 max,v,total;u32 n;
if(((u32)(M2C_FIELD(arg2,u16 *,6)<<25)>>25)>=91)return 0;
total=0;
if(!(M2C_FIELD(arg2,u16 *,4)&8))total+=func_020a2668(arg2,M2C_FIELD(arg2,u8 *,1),M2C_FIELD(arg2,u8 *,2));
if(IsCaptureTargetAt(arg2,M2C_FIELD(arg2,u8 *,1),M2C_FIELD(arg2,u8 *,2)))total+=func_020a7558(arg2);
if(total==0)return 0;
n=(u32)(M2C_FIELD(arg2,u16 *,6)<<25)>>25;
if(n==0)v=0;else v=Divide(n-1,10)+1;
max=10-v;
if(total>max)total=max;
return total*func_ov000_021a0aec(arg0,arg1,(u32)(M2C_FIELD(arg2,u8 *,0)<<26)>>26);
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
    s32 func_ov000_021a4a98(s32,s32);
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
        terrainValue=func_ov000_021a4a98(candidate[0],candidate[1]);
        if ((terrainValue&0x100) || !(terrainValue&255)) group[3]&=~4;
        else group[3]|=4;
        func_ov000_021a11b0(groupCount);
        groupCount++; group+=8;
    }
    return groupCount;
}
#pragma pop
s32 func_ov000_021a10e4(s32 arg0,void *arg1) {
u32 type=data_ov000_021e00ae[arg0*12];
if(type==1){
u32 flags=gUnitKindFlags[((u32)(M2C_FIELD(arg1,u8 *,0)<<26)>>26)*112];
if(flags&7){
void *base=*gCurrentMap;
s8 *row=((s8 **)((u8 *)base+0x52e8))[M2C_FIELD(arg1,u8 *,2)];
if(row[M2C_FIELD(arg1,u8 *,1)]<0)return 0;
}
if((flags&32) && M2C_FIELD(arg1,u8 *,12)==0)return 0;
}
if(type==3){
if(gUnitKindFlags[((u32)(M2C_FIELD(arg1,u8 *,0)<<26)>>26)*112]&7)return 0;
}
return 1;
}

