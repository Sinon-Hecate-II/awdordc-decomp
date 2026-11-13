/* 10 functions from 0x021A2FE8 to 0x021A3DAC (ov000), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 pad[8];
    u16 low : 14;
    u16 state : 2;
    u8 tail[4];
} UnkState_021a36e4;
#include "ov000_unit_entry.h"
#include "battle_map.h"
#include "ov000_ai.h"

#pragma push
#pragma opt_strength_reduction off
/* Plan a transport (unit kind 19) action: pick a target, reject the map when an
 * enemy threatens it, and commit once enough capture units are waiting for the
 * empty transports. */
s32 PlanTransportAction(void) {
 extern void **gCurrentMap;
 extern u8 gAiTargetCandidates[];
 extern M2C_UNK gAiCommand;
 void CommitAiAction(s32);
 s32 FindAiTargetByCost(s32);
 s32 IsCurrentPlayerUnit(s16);
 s32 candidateIndex;
 u32 unitId;
 UnkStruct_ov000_021A860C *unit;
 u8 emptyTransports, captureUnits;
 s32 x,y;
 u8 *candidate;
 void *map;
 if(HasAiTargetOfType(3)==1)return 0;
retry:
 candidateIndex=FindAiTargetByCost(2);
 if(candidateIndex==-1){ResetAiTargetCandidates();return 0;}
 candidate=gAiTargetCandidates+candidateIndex*12;
 {
 s32 unused=0;
 FloodFillUnitRange(candidate[0],candidate[1],2,110,0);
 }
 captureUnits=0;emptyTransports=0;
 map=*gCurrentMap;
 for(y=0;y<M2C_FIELD(map,u16*,MAP_HEIGHT);y++){
 for(x=0;x<M2C_FIELD(map,u16*,MAP_WIDTH);x++){
 if(M2C_FIELD((u8*)map+y*4,s8**,MAP_GRID)[x]>=0){
 unitId=M2C_FIELD((u8*)map+x+M2C_FIELD((u8*)map+y*2,u16*,MAP_ROW_OFFSETS),u8*,0);
 if(unitId){
 if(GetTerrainPropertyFlagsAt(x,y)==1)goto reject;
 unit=(UnkStruct_ov000_021A860C *)((u8*)*gCurrentMap+MAP_UNIT_RECORDS)+unitId;
 if(!IsUnitOnCurrentTeam(unitId)){
 if(!IsFootUnitKind(unit->unk0)){
 if(!GetUnitKindMaxAttackRange(unit->unk0))goto next;
 goto reject;
 }
 }else if(IsCurrentPlayerUnit((s16)unitId)==1){
 if(unit->unk0==19 && unit->unkC[0]==0)emptyTransports++;
 if(IsCaptureKind(unit->unk0))captureUnits++;
 }
 }
 }
next:
 map=*gCurrentMap;
 }
 }
 if((emptyTransports+1)*3>captureUnits)goto reject;
 M2C_FIELD(&gAiCommand,u8*,6)=19;
 CommitAiAction(candidateIndex);
 ResetAiTargetCandidates();return 1;
reject:
 candidate[3]=253;
 goto retry;
}
#pragma pop

/* Decide whether the AI builds a transport now: the unit must be affordable and
   before the tuning block's last transport turn, an existing transport move wins,
   and otherwise the transport count must be below its share of the infantry. */
s32 TryBuildTransport(void){
s32 Divide(s32,s32);s32 func_020d2d18(u16,s32);
void CommitAiAction(s32);s32 PlanTransportAction(void);s32 FindAiTargetByCost(s32);s32 FindAiTargetOfType(s32);s32 CountPlayerUnitsOfKind(s32);
extern void **gCurrentMap;extern void *gAiCommandState;extern void *gAiState;extern void *gAiSettings;extern M2C_UNK gAiCommand;
void *map=*gCurrentMap;u16 playerId=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);s32 targetIndex,unused,transportCount;u8 unitCount;
if(func_020d2d18(playerId,UNIT_KIND_TRANSPORT)*10>M2C_FIELD((u8 *)map+playerId*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF))return 0;
if(M2C_FIELD(gAiCommandState,u8 *,AI_COMMAND_STATE_TARGET_AREAS)==1){unitCount=M2C_FIELD(gAiSettings,u8 *,AI_SETTING_TRANSPORT_LAST_TURN);if(unitCount && M2C_FIELD(*gCurrentMap,u16 *,MAP_TURN)>unitCount)return 0;}
if(PlanTransportAction()==1)return 1;targetIndex=FindAiTargetByCost(2);if(targetIndex==-1){targetIndex=FindAiTargetOfType(2);if(targetIndex==-1)return 0;}
transportCount=CountPlayerUnitsOfKind(UNIT_KIND_TRANSPORT);
unitCount=M2C_FIELD(gAiState,u8 *,AI_STATE_INFANTRY_MECH);if(!unitCount)return 0;
if(Divide(transportCount*100,unitCount)<M2C_FIELD(gAiSettings,u8 *,AI_SETTING_TRANSPORT_PERCENT)){
M2C_FIELD(&gAiCommand,u8 *,AI_COMMAND_UNIT)=UNIT_KIND_TRANSPORT;
}else{return 0;}
CommitAiAction(targetIndex);return 1;
}

s32 func_ov000_021a3364(void){
s32 Divide(s32,s32);s32 func_020d2d18(u16,s32);
void CommitAiAction(s32);s32 func_ov000_021a61cc(s32);s32 CountPlayerUnitsOfKind(s32);
extern void **gCurrentMap;extern void *gAiState;extern void *gAiSettings;extern M2C_UNK gAiCommand;
void *p=*gCurrentMap;u16 id=M2C_FIELD(p,u16 *,0x52a4);s32 r,t,v;u8 n;
if(func_020d2d18(id,13)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
n=M2C_FIELD(gAiSettings,u8 *,18);
if(n && M2C_FIELD(*gCurrentMap,u16 *,0x52a2)>n)return 0;
r=func_ov000_021a61cc(1);if(r==-1)return 0;
t=CountPlayerUnitsOfKind(13);v=t+CountPlayerUnitsOfKind(19);
n=M2C_FIELD(gAiState,u8 *,8);if(!n)return 0;
if(Divide(v*100,n)<M2C_FIELD(gAiSettings,u8 *,12)){
M2C_FIELD(&gAiCommand,u8 *,6)=13;
}else{return 0;}
CommitAiAction(r);return 1;
}

u8 IsKind24TerrainPassable(s32 a) {
extern M2C_UNK gUnitKindStats;
extern M2C_UNK gMovementCostTable;
u8 result;
u32 row = M2C_FIELD(&gUnitKindStats,u8 *,0xa92);
s8 *table = M2C_FIELD(&gMovementCostTable, s8 **, 0x64) + row*32;
if (table[a&31] > 0) result=1; else result=0;
return result;
}

#pragma push
#pragma opt_strength_reduction off
/* Walks the movement grid of the current map and, for every reachable cell whose
 * terrain unit kind 24 can cross, gives its still-negative (out-of-range)
 * orthogonal neighbours the given grid marker. */
void MarkAdjacentCellsForKind24(s32 marker) {
    extern void **gCurrentMap;
    u8 IsKind24TerrainPassable(s32);
    s32 y, x;
    s8 value;
    void *base = *gCurrentMap;

    y = 0;
    if (y >= M2C_FIELD(base, u16 *, MAP_HEIGHT)) return;
    value = marker;
    do {
        for (x = 0; x < M2C_FIELD(base, u16 *, MAP_WIDTH); x++) {
            s8 *cell = M2C_FIELD((u8 *)base + y * 4, s8 **, MAP_GRID) + x;
            if (*cell >= 0 && marker != *cell &&
                IsKind24TerrainPassable(M2C_FIELD((u8 *)base + x + M2C_FIELD((u8 *)base + y * 2, u16 *, MAP_ROW_OFFSETS), u8 *, MAP_CELL_TERRAIN))) {
                if (x != 0) {
                    cell = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID) + x;
                    if (cell[-1] < 0) cell[-1] = value;
                }
                base = *gCurrentMap;
                if (x != M2C_FIELD(base, u16 *, MAP_WIDTH) - 1) {
                    cell = M2C_FIELD((u8 *)base + y * 4, s8 **, MAP_GRID) + x;
                    if (cell[1] < 0) cell[1] = value;
                }
                if (y != 0) {
                    cell = M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, MAP_GRID - 4);
                    if (cell[x] < 0) cell[x] = value;
                }
                base = *gCurrentMap;
                if (y != M2C_FIELD(base, u16 *, MAP_HEIGHT) - 1) {
                    cell = M2C_FIELD((u8 *)base + y * 4, s8 **, MAP_GRID + 4);
                    if (cell[x] < 0) cell[x] = value;
                }
            }
            base = *gCurrentMap;
        }
        y++;
    } while (y < M2C_FIELD(base, u16 *, MAP_HEIGHT));
}
#pragma pop
s32 func_ov000_021a3644(s32 arg0) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)base+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && type==arg0 && entry->unkC[0]==0) count++;
}
return count;
}

s32 func_ov000_021a36e4(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 IsCaptureKind(s32);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && IsCaptureKind(type)!=0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

s32 func_ov000_021a379c(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 IsCaptureKind(s32);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && IsCaptureKind(type)==0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
s32 func_ov000_021a3854(void) {
extern void **gCurrentMap;
extern u8 gAiTargetCandidates[];
extern M2C_UNK gUnitKindStats;
extern M2C_UNK gAiCommand;
s32 FindAiTargetByCost(s32);
s32 IsCurrentPlayerUnit(s16);
void CommitAiAction(s32);
UnkStruct_ov000_021A860C *unit;
u32 uid;
s32 c7,c8,y,x,c18,c14,initial,flag,id,i;
s8 c11;
void *base;
u8 *record;
initial=(u8)(CountPlayerUnitsOfKind(24)+CountPlayerUnitsOfKind(25));
retry:
id=FindAiTargetByCost(3);
if(id==-1){ResetAiTargetCandidates();return 0;}
record=gAiTargetCandidates+12*id;
FloodFillUnitRange(record[0],record[1],2,110,0);
for(i=0;i<GetUnitMoveRange(M2C_FIELD(*gCurrentMap,u16*,0x52a4),24);i++)
MarkAdjacentCellsForKind24((u8)(i+111));
c7=0;c8=0;c11=0;c18=0;y=0;c14=0;flag=0;
base=*gCurrentMap;
{ s32 h=M2C_FIELD(base,u16*,0x5146); }
for(;y<M2C_FIELD(base,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16*,0x5144);){
if(M2C_FIELD(base+y*4,s8**,0x52e8)[x]<0)goto next;
if(M2C_FIELD(base+y*4,s8**,0x52e8)[x]<=110){
if(GetTerrainPropertyFlagsAt(x,y)==1)goto mark;
{
base=*gCurrentMap;
i=M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16*,0x3758),u8*,0x1420);
if((i&31)!=18 || M2C_FIELD(base,u16*,0x52a6)!=(i&224))goto no_mark;
mark: flag=1;
}}
no_mark:
base=*gCurrentMap;
uid=M2C_FIELD(base+x+M2C_FIELD(base+y*2,u16*,0x3758),u8*,0);
if(!uid)goto next;
unit=(UnkStruct_ov000_021A860C *)(base+0x59a4)+uid;
if(!IsUnitOnCurrentTeam(uid)){
if(!IsFootUnitKind(unit->unk0))goto next;
if(!(M2C_FIELD((u8*)&gUnitKindStats+unit->unk0*112,u8*,19)&7))goto next;
base=*gCurrentMap;
if(M2C_FIELD(base+y*4,s8**,0x52e8)[x]>110)goto next;
goto reject;
}else if(IsCurrentPlayerUnit((s16)uid)==1){
base=*gCurrentMap;
if(M2C_FIELD(base+y*4,s8**,0x52e8)[x]<=110){
if(((UnkState_021a36e4*)unit)->state==2){
if(IsCaptureKind(unit->unk0))c8=(s8)(c8+1);
else c7=(s8)(c7+1);
}else if(IsCaptureKind(unit->unk0))c18=(s8)(c18+1);
}
if(unit->unk0==24 && unit->unkC[0]==0)c11=(s8)(c11+1);
if(unit->unk0==25 && unit->unkC[0]==0)c14=(s8)(c14+1);
}
next:
x++;
base=*gCurrentMap;
}}
if(!flag)c8=(s8)(c8+c18);
c11=(s8)(c11-(c7>>2));
if(c11<0)c11=0;
if(c8>=((c14+1+c11)<<2)){
M2C_FIELD(&gAiCommand,u8*,6)=25;
CommitAiAction(id);return 1;
}
if(c8 && !initial){
M2C_FIELD(&gAiCommand,u8*,6)=25;
CommitAiAction(id);ResetAiTargetCandidates();return 1;
}
reject:
record[3]=253;goto retry;
}
#pragma pop
s32 func_ov000_021a3c84(void){
s32 func_020d2d18(u16,s32);s32 func_ov000_021a43a0(s32);s32 func_ov000_021a3854(void);
s32 FindAiTargetByCost(s32);s32 FindAiTargetOfType(s32);s32 CountPlayerUnitsOfKind(s32);void CommitAiAction(s32);
extern void **gCurrentMap;extern M2C_UNK gAiCommand;
void *p;u16 id;s32 r,a,b,n,x,y,z;
if(!func_ov000_021a43a0(1))return 0;
p=*gCurrentMap;id=M2C_FIELD(p,u16 *,0x52a4);
if(func_020d2d18(id,25)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
if(func_ov000_021a3854()==1)return 1;
r=FindAiTargetByCost(3);if(r==-1){r=FindAiTargetOfType(3);if(r==-1)return 0;}
a=CountPlayerUnitsOfKind(24);b=CountPlayerUnitsOfKind(25);
n=func_ov000_021a36e4();if(!n)return 0;
if(a+b){x=func_ov000_021a3644(24);y=func_ov000_021a3644(25)+1;z=x-(func_ov000_021a379c()>>2);if(z<0)z=0;if(n<(y+z)*4)return 0;}
M2C_FIELD(&gAiCommand,u8 *,6)=25;CommitAiAction(r);return 1;
}

