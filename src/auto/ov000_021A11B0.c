/* 12 functions from 0x021A11B0 to 0x021A2100 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6;u8 flags:2;u8 pad[7];u16 bits:14;u16 state:2;u8 tail[4]; } Unit16E8;
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 pad[3];u8 used:1;u8 rest:7; } Candidate1F14;

#pragma opt_strength_reduction off
void func_ov000_021a11b0(s32 arg0){
extern void **gCurrentMap;
extern void *gAiState,*gAiSettings;
extern u8 gAiTargetCandidates[],gUnitKindStats[];
s32 IsUnitOnCurrentTeam(s32);s32 AiCandidateIncludesUnit(s32,void *);
s32 ManhattanDistance(s32,s32,s16,s16);void SelectMapLayer(void *);
void FloodFillUnitRange(u8,u8,s32,s32,s32);
s32 func_ov000_021a99dc(void *);s32 IsFootUnitKind(s32);
s32 IsPropertyTerrain(s32);s32 IsTerrainOnUnitTeam(s16,s32);
register u8 *p asm("r8");
s32 y,i,id,d,xmin,xmax,ymin,ymax,r,dx,dy,cx,cy,w,h;
s32 x;
u8 *map,*unit;
p=gAiTargetCandidates;
{s32 x;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x];
if(id){
unit=map+0x59a4+id*14;
if(IsUnitOnCurrentTeam(id)!=1){
p=gAiTargetCandidates;
for(i=0;i<M2C_FIELD(gAiState,u8 *,0);i++,p+=12){
if(M2C_FIELD(p,s8 *,4)==arg0 && AiCandidateIncludesUnit(i,unit)){
d=ManhattanDistance(p[0],p[1],(s16)x,(s16)y);
if(p[7]>d)p[7]=d;
}
}
}
}
}
}}
p=gAiTargetCandidates;
for(i=0;i<M2C_FIELD(gAiState,u8 *,0);i++,p+=12){
if(M2C_FIELD(p,s8 *,4)!=arg0)continue;
SelectMapLayer((u8 *)*gCurrentMap+0x2338);
FloodFillUnitRange(p[0],p[1],7,M2C_FIELD(gAiSettings,u8 *,16),0);
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
map=*gCurrentMap;cx=p[0];r=M2C_FIELD(gAiSettings,u8 *,16);w=M2C_FIELD(map,u16 *,0x5144);
xmin=cx-r;
xmax=w-1;
if(xmin<0)xmin=0;
cy=p[1];h=M2C_FIELD(map,u16 *,0x5146);ymin=cy-r;
ymax=h-1;
if(ymin<0)ymin=0;
if(cx+r<xmax)xmax=cx+r;
if(cy+r<ymax)ymax=cy+r;
{s32 x,y;
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
dx=p[0]-x;if(dx<=0)dx=x-p[0];
d=0;d+=dx;dy=p[1]-y;if(dy<=0)dy=y-p[1];d+=dy;
if(d<0 || d>M2C_FIELD(gAiSettings,u8 *,16))continue;
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x];
if(!id)continue;
unit=map+0x59a4+id*14;
if(!AiCandidateIncludesUnit(i,unit))continue;
if(func_ov000_021a99dc(unit)==1)continue;
if(gUnitKindStats[((u32)(unit[0]<<26)>>26)*112+19]&7){
map=*gCurrentMap;if(M2C_FIELD(map+((Map16E8 *)map)->rows[y]+x,s8 *,0x2338)<0)continue;
}
if(IsUnitOnCurrentTeam(id)==1)M2C_FIELD(p,s8 *,5)--;
else{
if(p[2]==3 || IsFootUnitKind((u32)(unit[0]<<26)>>26))M2C_FIELD(p,s8 *,5)++;
else M2C_FIELD(p,s8 *,5)+=2;
p[6]++;
}
}}
if(p[8]==255){
FloodFillUnitRange(p[0],p[1],1,110,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++)for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(((Map16E8 *)map)->grid[y][x]<0)continue;
id=map[((Map16E8 *)map)->rows[y]+x+0x1420];
if(IsPropertyTerrain(id)!=1)continue;
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x+0x1420];
if(IsTerrainOnUnitTeam(M2C_FIELD(map,s16 *,0x52a8),id)!=0)continue;
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[8]>d)p[8]=d;
}
}
}
}
void UpdateAiCandidateCosts(void){
extern void *gAiState;extern u8 gAiTargetCandidates[];extern void **gCurrentMap;
void FloodFillUnitRange(u8,u8,s32,s32,s32);
s32 IsCurrentPlayerUnit(s16);s32 IsCaptureKind(s32);s32 CanKindAttack(s32,s32);
s32 i;u8 *p; s32 id,d;Map16E8 *map;Unit16E8 *unit;s32 x,y;
/* For every AI target candidate, flood-fill its movement range and record the
   cheapest current-player capture unit (candidate[9]) and the cheapest unit
   that kind 24 can attack while in state 2 (candidate[10]). */
p=gAiTargetCandidates;
for(i=0;i<M2C_FIELD(gAiState,u8 *,0);i++,p+=12){
if(p[3]==252)continue;
FloodFillUnitRange(p[0],p[1],1,110,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);x++){
map=*gCurrentMap;
if(map->grid[y][x]<0)continue;
id=((u8 *)map)[x+map->rows[y]];
if(!id)continue;
if(IsCurrentPlayerUnit((s16)id)!=1)continue;
unit=(Unit16E8 *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS)+id;
if(IsCaptureKind(unit->kind)){
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[9]>d)p[9]=d;
}
if(CanKindAttack(24,unit->kind)&&unit->state==2){
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[10]>d)p[10]=d;
}
}
}
}
}

/* Fill gAiTargetCandidates from the map's property-cell list: one candidate
 * per capturable property cell, with its type taken from the terrain and its
 * status marked fresh and its group unset.  Returns how many were collected. */
s32 CollectAiTargetCandidates(void) {
s32 func_020cf878(u8,u8);
extern void **gCurrentMap;
extern s8 gTerrainPropertyType[];
extern u8 gAiTargetCandidates[];
s32 n=0;u8 *p;u8 *dst; u8 *base;
dst=gAiTargetCandidates; base=*gCurrentMap; p=base+MAP_PROPERTY_CELLS;
if(base[MAP_PROPERTY_CELLS]!=MAP_PROPERTY_END) do {
if(func_020cf878(p[MAP_PROPERTY_X],p[MAP_PROPERTY_Y])==1) {
n++;
dst[AI_CANDIDATE_X]=p[MAP_PROPERTY_X];
dst[AI_CANDIDATE_Y]=p[MAP_PROPERTY_Y];
dst[AI_CANDIDATE_TYPE]=gTerrainPropertyType[p[MAP_PROPERTY_KIND]];
if((p[MAP_PROPERTY_KIND]&MAP_TERRAIN_KIND_MASK)==16)dst[AI_CANDIDATE_TYPE]=1;
dst[AI_CANDIDATE_STATUS]=AI_CANDIDATE_FRESH;M2C_FIELD(dst,s8 *,4)=-1;dst[5]=0;dst[6]=0;dst[7]=255;dst[8]=255;dst[9]=255;dst[10]=255;dst+=AI_CANDIDATE_STRIDE;
}p+=MAP_PROPERTY_STRIDE;
}while(*p!=MAP_PROPERTY_END);
return n;
}

/* Opening build step of the AI turn: when the AI may act, its unit set wants
 * unit kind 6, the map lets the player produce that kind and it is affordable,
 * build one into a target group that has an enemy sea unit and no ready
 * kind-6/14 unit of its own.  Clears the group's sea-threat flag and commits
 * the build command. */
s32 BuildAiKind6Unit(void) {
    s32 CanBuildUnitKind(u16, M2C_UNK);
    s32 GetUnitBuildCost(u16, M2C_UNK);
    s32 FindNavalThreatBuildCandidate();
    M2C_UNK CommitAiAction();
    extern void **gCurrentMap;
    extern void *gAiSettings;
    extern void *gAiCommandState;
    extern M2C_UNK gAiCommand, gAiTargetGroups, gAiTargetCandidateGroup;
    void *map, *group;
    u16 player;
    s32 candidate;
    u8 flags;
    if (!(((u32) (M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_MODE) << 26) >> 29) & 4)) return 0;
    if (M2C_FIELD(gAiSettings, u8 *, AI_SETTING_UNIT(6)) == 0) return 0;
    if (CanBuildUnitKind(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER), 6) == 0) return 0;
    map = *gCurrentMap;
    player = M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER);
    if ((s32) (GetUnitBuildCost(player, 6) * 10) > M2C_FIELD(player * MAP_PLAYER_STRIDE + (s32) map, s32 *, MAP_PLAYER_STATES)) return 0;
    candidate = FindNavalThreatBuildCandidate();
    if (candidate == -1) return 0;
    group = (u8 *) &gAiTargetGroups + M2C_FIELD(&gAiTargetCandidateGroup, s8 *, candidate * AI_CANDIDATE_STRIDE) * AI_GROUP_STRIDE;
    flags = M2C_FIELD(group, u8 *, AI_GROUP_FLAGS);
    M2C_FIELD(&gAiCommand, u8 *, AI_COMMAND_UNIT) = 6;
    M2C_FIELD(group, u8 *, AI_GROUP_FLAGS) = flags & ~AI_GROUP_FLAG_SEA_THREAT;
    CommitAiAction(candidate);
    return 1;
}

s32 func_ov000_021a1ab8(void) {
 s32 func_ov000_021a64c4(); M2C_UNK func_ov000_021a7ac0(s32); s32 SelectUnitForTargetCandidate(s32); M2C_UNK CommitAiAction(s32);
 extern u8 data_ov000_021e00af[];
 s32 x=func_ov000_021a64c4();
 if(x==-1) return 0;
 func_ov000_021a7ac0(x);
 if(SelectUnitForTargetCandidate(x)!=-1) {CommitAiAction(x); return 1;}
 data_ov000_021e00af[x*12]=253;
 return 0;
}

s32 func_ov000_021a1b1c(void){
s32 CanBuildUnitKind(u16,M2C_UNK);s32 GetUnitBuildCost(u16,M2C_UNK);M2C_UNK func_ov000_02199330();s32 FindPropertyTargetCandidate();s32 PlayerHasHealthyCounterUnit();s32 func_ov000_021a860c();M2C_UNK CommitAiAction();
extern void **gCurrentMap;extern void *gAiSettings,*gAiCommandState;extern M2C_UNK gAiCommand;
void *base;u16 id;s32 result;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,0xa)<<20)>>29)&2))return 0;
if(M2C_FIELD(gAiSettings,u8 *,0xb0)==0)return 0;
if(CanBuildUnitKind(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),14)==0)return 0;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if(GetUnitBuildCost(id,14)*10>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
if(PlayerHasHealthyCounterUnit()==1)return 0;
if(func_ov000_021a860c()==0)return 0;
func_ov000_02199330();
result=FindPropertyTargetCandidate();if(result==-1)return 0;
M2C_FIELD(&gAiCommand,s8 *,6)=14;
CommitAiAction(result);return 1;
}

/* Tries to activate candidate 0x17: checks flags, availability and resources, then records it. */
s32 func_ov000_021a1c24(void) {
    s32 CanBuildUnitKind(u16, M2C_UNK);
    s32 GetUnitBuildCost(u16, M2C_UNK);
    s32 func_ov000_021a6940();
    M2C_UNK CommitAiAction();
    extern void **gCurrentMap;
    extern void *gAiSettings;
    extern void *gAiCommandState;
    extern M2C_UNK gAiCommand;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(gAiCommandState, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(gAiSettings, u8 *, 0x11C) == 0) return 0;
    if (CanBuildUnitKind(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *gCurrentMap;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (GetUnitBuildCost(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6940();
    if (result == -1) return 0;
    M2C_FIELD(&gAiCommand, s8 *, 6) = 0x17;
    CommitAiAction(result);
    return 1;
}

/* Tries to activate candidate 0x17, using a stricter resource threshold (func_ov000_021a6a00). */
s32 func_ov000_021a1d08(void) {
    s32 CanBuildUnitKind(u16, M2C_UNK);
    s32 GetUnitBuildCost(u16, M2C_UNK);
    s32 func_ov000_021a6a00();
    M2C_UNK CommitAiAction();
    extern void **gCurrentMap;
    extern void *gAiSettings;
    extern void *gAiCommandState;
    extern M2C_UNK gAiCommand;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(gAiCommandState, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(gAiSettings, u8 *, 0x11C) == 0) return 0;
    if (CanBuildUnitKind(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *gCurrentMap;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (GetUnitBuildCost(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6a00();
    if (result == -1) return 0;
    M2C_FIELD(&gAiCommand, s8 *, 6) = 0x17;
    CommitAiAction(result);
    return 1;
}

/* Builds a unit kind 22 (submarine) when the AI's command mode allows it, its
 * unit set wants kind 22 and the player can afford one, aiming it at the best
 * remaining target candidate. */
s32 func_ov000_021a1dec(void) {
s32 CanBuildUnitKind(u16,M2C_UNK);s32 GetUnitBuildCost(u16,M2C_UNK);s32 FindBestTargetCandidate();M2C_UNK CommitAiAction();
extern void **gCurrentMap;extern void *gAiSettings,*gAiCommandState;extern M2C_UNK gAiCommand;
void *base;u16 id;s32 result;
if(!(((u32)(M2C_FIELD(gAiCommandState,u16 *,AI_COMMAND_STATE_MODE)<<20)>>29)&4))return 0;
if(M2C_FIELD(gAiSettings,u8 *,AI_SETTING_UNIT(22))==0)return 0;
if(CanBuildUnitKind(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),0x16)==0)return 0;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if((s32)(GetUnitBuildCost(id,0x16)*10)>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
result=FindBestTargetCandidate();if(result==-1)return 0;
M2C_FIELD(&gAiCommand,s8 *,6)=0x16;
CommitAiAction(result);return 1;
}

s32 GetAiRandomChance(void) {
 extern void **gCurrentMap; extern void *gAiSettings;
 s32 r=0; u16 x;
 x=M2C_FIELD(*gCurrentMap,u16 *,0x52a2);
 if((s32)x>3) {r=M2C_FIELD(gAiSettings,u8 *,10)*x; if(r>80) r=80;}
 return r;
}

/* Tries to build a basic (tier 1 or 2) unit for the AI: checks the player can
 * afford tier 1, picks a build-target candidate, reserves its target group (or
 * rejects the attempt when the player already has its budget of basic units),
 * then commits a build command for tier 2 when a random roll passes and the
 * player can afford it, otherwise tier 1. */
s32 BuildAiBasicUnit(void){
s32 NextRandomValue(void);s32 Modulo(s32,s32);s32 GetUnitBuildCost(u16,M2C_UNK);
s32 FindBasicUnitTargetCandidate(void);s32 func_ov000_021a60d4(s32);s32 FindAiTargetOfType(s32);
u8 CountPlayerUnitsOfKind(s32);M2C_UNK CommitAiAction(s32);
extern void **gCurrentMap;extern void *gAiState,*gAiSettings;
extern M2C_UNK gAiCommand,gAiTargetGroups,gAiTargetCandidateGroup;
void *map,*group;u16 playerId;s32 candidate,r,cost;u8 flags,t;
map=*gCurrentMap;playerId=M2C_FIELD(map,u16 *,0x52a4);
if(GetUnitBuildCost(playerId,1)*10>M2C_FIELD(playerId*MAP_PLAYER_STRIDE+(s32)map,s32 *,MAP_PLAYER_STATES))return 0;
candidate=FindBasicUnitTargetCandidate();
if(candidate==-1)candidate=func_ov000_021a60d4(1);
if(candidate==-1)candidate=FindAiTargetOfType(1);
if(candidate==-1)return 0;
group=(u8 *)&gAiTargetGroups+M2C_FIELD(&gAiTargetCandidateGroup,s8 *,candidate*12)*8;
if(!((Candidate1F14 *)group)->used){((Candidate1F14 *)group)->used=1;}
else {
M2C_FIELD(gAiState,u8 *,8)=CountPlayerUnitsOfKind(1);
t=CountPlayerUnitsOfKind(2);
M2C_FIELD(gAiState,u8 *,8)+=t;
if(M2C_FIELD(gAiState,u8 *,8)>=M2C_FIELD(gAiSettings,u8 *,8)+M2C_FIELD(gAiSettings,u8 *,9))return 0;
}
r=Modulo(NextRandomValue(),100);
if(r<GetAiRandomChance() && (map=*gCurrentMap,playerId=M2C_FIELD(map,u16 *,0x52a4),M2C_FIELD(playerId*MAP_PLAYER_STRIDE+(s32)map,s32 *,MAP_PLAYER_STATES)>=GetUnitBuildCost(playerId,2)*20))M2C_FIELD(&gAiCommand,u8 *,AI_COMMAND_UNIT)=2;
else M2C_FIELD(&gAiCommand,u8 *,AI_COMMAND_UNIT)=1;
CommitAiAction(candidate);return 1;
}

s32 func_ov000_021a20d4(void) {
    M2C_UNK CommitAiAction();
    M2C_UNK func_ov000_021a7d08();
    s32 func_ov000_021a7f1c(M2C_UNK);
    func_ov000_021a7d08();
    if (func_ov000_021a7f1c(1) == -1) {
        return 0;
    }
    CommitAiAction();
    return 1;
}
