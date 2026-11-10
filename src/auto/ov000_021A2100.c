/* 3 functions from 0x021A2100 to 0x021A2FE8 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 *gAiState;
extern u8 gAiTargetCandidates;
extern s8 data_ov000_021b5580[], data_ov000_021b55a0[], data_ov000_021e0f60[];
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021df590[], data_ov000_021df594[];
extern u8 gAiCommand[];

/* Among candidate entries, return index of the one with highest score that is visible/passable. */
s16 func_ov000_021a2100(s32 areaX, s32 areaY) {
    void SelectMapLayer(void *);
    void FloodFillUnitRange(s32, s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 *gAiState;
    extern u8 gAiTargetCandidates;
    extern s8 data_ov000_021e0f60[];
    u8 *entry;
    s32 i;
    s32 bestScore;
    s16 bestIndex;
    u8 score;

    bestScore = 0;
    bestIndex = -1;
    entry = &gAiTargetCandidates;
    SelectMapLayer(data_ov000_021e0f60);
    FloodFillUnitRange(areaX, areaY, 1, 3, 0);
    SelectMapLayer((u8 *)*gCurrentMap + 0x1E30);
    for (i = 0; i < *gAiState; i++, entry += 12) {
        if (entry[3] < 252U && entry[2] == 1 &&
            data_ov000_021e0f60[entry[0] + entry[1] * M2C_FIELD(*gCurrentMap, u16 *, 0x5144)] >= 0) {
            score = entry[8];
            if (bestScore <= score) {
                bestScore = score;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}

s32 func_ov000_021a21f8(s32 arg0) {
s32 func_020a8a14(u16,u16); s32 func_020d27ec(s16,u8);
s32 func_ov000_021a8d7c(s32,s32,s32);
s32 IsSameTeam(u16,s32); s32 IsPlayerActive(s32);
s32 IsFootUnitKind(s32); s32 func_ov000_021a8984(s32);
void SelectMapLayer(void *); void FloodFillUnitRange(s32,s32,s32,s32,s32);
u8 *out=&gAiTargetCandidates+*gAiState*12;
u8 *entry; u8 *unit; u8 *enemyUnit; s32 enemyPlayer,enemyIndex; u8 *candidate,*scan,*best; void *map; s32 player,index,count=0,pass,i,cost,oldpass,bestcost,price,allow,relation,delta,bestdelta; s32 row; u8 funds; unsigned int penalty; u32 kind;
s32 func_ov000_0217a59c(s32,s32,s32,s32); s32 func_020d2d18(u16,u8); s32 func_ov000_021a911c(s16,s32,s32); void CommitAiAction(s32);
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&4)return 0;
if(!arg0 && (func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&8))return 0;
entry=(u8 *)*gCurrentMap+0x6c60;
while(entry[0]!=255){
if(arg0){
if(entry[0]==15){
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&2)goto nextEntry;
map=*gCurrentMap;
if(func_020d27ec(M2C_FIELD(map,s16 *,0x52a8),M2C_FIELD(map+entry[1]+M2C_FIELD(map+entry[2]*2,u16 *,0x3758),u8 *,0x1420)))goto nextEntry;
}else{
if(!data_ov000_021b5580[entry[0]&31])goto nextEntry;
map=*gCurrentMap;
if(M2C_FIELD(map+entry[1]+M2C_FIELD(map+entry[2]*2,u16 *,0x3758),u8 *,0x1420)&224)goto nextEntry;
}
}else{
map=*gCurrentMap;
if(M2C_FIELD(map+entry[1]+M2C_FIELD(map+entry[2]*2,u16 *,0x3758),u8 *,0x1420)&224)goto nextEntry;
if(data_ov000_021b5580[entry[0]&31])goto nextEntry;
}
if(func_ov000_021a8d7c(entry[1],entry[2],5))goto nextEntry;
for(player=1;player<5;player++){
if(IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),player)&&IsPlayerActive(player)&&M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67c2)==2){
for(index=gPlayerUnitIdBase[player]+1;index<gPlayerUnitIdBase[player]+51;index++){
unit=(u8 *)*gCurrentMap+0x59a4+index*14;
kind=(u32)(unit[0]<<26)>>26;
if(!kind||!IsFootUnitKind(kind)||func_ov000_021a8984((u32)(unit[11]<<28)>>28))continue;
if(unit[1]==entry[1]&&unit[2]==entry[2]&&((u32)(M2C_FIELD(unit,u16 *,6)<<16)>>27))goto nextEntry;
if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)>60&&((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26)==entry[1]&&((u32)(M2C_FIELD(unit,u16 *,8)<<20)>>26)==entry[2])goto nextEntry;
if(((u32)(unit[11]<<28)>>28)&&((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26)!=63){
SelectMapLayer(data_ov000_021e0f60);
FloodFillUnitRange(((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26),((u32)(M2C_FIELD(unit,u16 *,8)<<20)>>26),1,arg0?3:6,0);
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
if(data_ov000_021e0f60[entry[1]+entry[2]*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]>=0)goto nextEntry;
}
}
}
}
out[0]=entry[1];out[1]=entry[2];out[2]=data_ov000_021b55a0[entry[0]];out[3]=0;out[5]=255;out[4]=255;
for(pass=0;pass<4;pass++){
func_ov000_0217a59c(entry[1],entry[2],data_ov000_021df590[pass],110);
allow=1;
if(data_ov000_021df590[pass]==19){
if(gAiState[7]+1>=50)allow=0;
price=func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),data_ov000_021df590[pass]);
price=(price+func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1))*10;
}else price=func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),data_ov000_021df590[pass])*10;
map=*gCurrentMap;
candidate=map+0x67a4+M2C_FIELD(map,u16 *,0x52a4)*140;
funds=M2C_FIELD(candidate,s32 *,0)>=price;
if(!funds&&M2C_FIELD(candidate,s32 *,8)<price)allow=0;
if(allow){
bestcost=111;oldpass=-1;
scan=&gAiTargetCandidates;
for(i=0;i<*gAiState;i=(scan-&gAiTargetCandidates)/12){
if(scan[2]==data_ov000_021df594[pass]){
map=*gCurrentMap;
row=M2C_FIELD(map+scan[1]*2,u16 *,0x3758);cost=M2C_FIELD(map+scan[0]+row,s8 *,0x2338);
if(cost>=0){
if(scan[3]<252U){if(!funds)penalty=1;else penalty=0;}else penalty=0;
penalty=(u8)(penalty+1);
if(out[4]>=cost+penalty&&(out[4]!=cost+penalty||(pass==oldpass&&bestcost>M2C_FIELD(M2C_FIELD(map+scan[1]*4,s8 **,0x52e8),s8 *,scan[0])))){
if(data_ov000_021df590[pass]==19){
index=func_ov000_021a2100(scan[0],scan[1]);if(index==-1)goto nextCandidate;
out[6]=index;out[7]=i;
}else out[6]=i;
map=*gCurrentMap;
out[4]=penalty+M2C_FIELD(map+scan[0]+M2C_FIELD(map+scan[1]*2,u16 *,0x3758),s8 *,0x2338);
if(scan[3]<252U){if(!funds){out[3]=0;goto scored;}}
out[3]=data_ov000_021df590[pass];scored:;
bestcost=M2C_FIELD(M2C_FIELD(*gCurrentMap+scan[1]*4,s8 **,0x52e8),s8 *,scan[0]);oldpass=pass;
}
}
}
nextCandidate:scan+=12;
}
}
candidate=(u8 *)*gCurrentMap+0x6c60;
while(candidate[0]!=255){
if(data_ov000_021b55a0[candidate[0]]==data_ov000_021df594[pass]){
map=*gCurrentMap;
index=M2C_FIELD(map+candidate[2]*2,u16 *,0x3758)+candidate[1];
kind=M2C_FIELD(map+index,u8 *,0x1420)&224;
if(kind!=0&&kind==M2C_FIELD(map,u16 *,0x52a6))goto nextProperty;
{
cost=M2C_FIELD(map+index,s8 *,0x2338);
if(cost>=0&&out[5]>=cost+1){
out[5]=cost+1;relation=func_ov000_021a911c(M2C_FIELD(*gCurrentMap,s16 *,0x52a8),candidate[1],candidate[2]);
}
}
}
nextProperty:candidate+=6;
}
for(enemyPlayer=1;enemyPlayer<5;enemyPlayer++){
if(!IsPlayerActive(enemyPlayer)||enemyPlayer==M2C_FIELD(*gCurrentMap,u16 *,0x52a4))continue;
for(enemyIndex=gPlayerUnitIdBase[enemyPlayer]+1;enemyIndex<gPlayerUnitIdBase[enemyPlayer]+51;enemyIndex++){
map=*gCurrentMap;enemyUnit=map+0x59a4+enemyIndex*14;
kind=(u32)(enemyUnit[0]<<26)>>26;
if(!kind||kind!=data_ov000_021df590[pass])continue;
cost=M2C_FIELD(map+enemyUnit[1]+M2C_FIELD(map+enemyUnit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(cost<0||(M2C_FIELD(enemyUnit,u16 *,4)&8))continue;
if(kind==19){
if(!enemyUnit[12]&&func_ov000_021a8984(19))continue;
map=*gCurrentMap;cost=1+M2C_FIELD(map+enemyUnit[1]+M2C_FIELD(map+enemyUnit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(out[5]<cost)continue;out[5]=cost;
}else {if(out[5]<cost)continue;out[5]=cost;}
relation=IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),enemyPlayer);
}
}
}
if(out[3]&&out[4]!=255){
if(arg0){if(relation){if(out[4]>(u32)out[5])goto nextEntry;}else if(out[4]>out[5]+1)goto nextEntry;}
else {if(relation){if(out[4]>out[5]-2)goto nextEntry;}else if(out[4]>out[5]-1)goto nextEntry;}
count++;out+=12;
}
nextEntry:entry+=6;
}
if(!count)return 0;
out=&gAiTargetCandidates+*gAiState*12;
best=0;bestdelta=255;
for(i=0;i<count;i++,out+=12){
if(best){
delta=(s32)out[4]-out[5];
if(bestdelta<(delta<0?-delta:delta))continue;
if(delta<0)delta=-delta;
if(bestdelta==delta){
if(best[2]<out[2])continue;
if(best[2]==out[2]&&best[4]<=out[4])continue;
}
}
best=out;bestdelta=(s32)out[4]-out[5];if(bestdelta<0)bestdelta=-bestdelta;
}
if(!best)return 0;
if(best[3]==19){
gAiCommand[6]=1;CommitAiAction((s8)best[6]);
gAiCommand[7]=2;gAiState[12]=19;gAiState[13]=(s8)best[7];
}else{
gAiCommand[6]=best[3];CommitAiAction((s8)best[6]);gAiCommand[7]=1;
}
gAiState[14]=best[0];gAiState[15]=best[1];return 1;
}

#pragma opt_propagation off
/* Plan a special-unit action if no conflicting units exist, a target is available, and the player can afford it. */
s32 func_ov000_021a2db8(void) {
 void FloodFillUnitRange(s32,s32,s32,s32,s32);
 s32 func_020d243c(u16); s32 func_020d2d18(u16,u8);
 s32 func_ov000_0217bc84(s32,s32,s32);
 void CommitAiAction(s32); s32 func_ov000_021a6d4c(void);
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 extern void *data_ov000_021df580; extern u8 gAiCommand[];
 s32 unitIndex,choice; u32 unitKind; u8 *unit; void *map; void *lastMap; u16 player;
 if(!func_020d243c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))return 0;
 map=*gCurrentMap;
 unitIndex=gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+1;
 if(unitIndex<gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+51){
 unit=map+0x59a4+unitIndex*14;
 do{
 unitKind=(u32)(unit[0]<<26)>>26;
 if(unitKind==0)goto nextUnit;
 if(unitKind!=9 && unitKind!=7 && unitKind!=6)goto nextUnit;
 {
 if(((u32)(unit[11]<<28)>>28)==5)return 0;
 }
 nextUnit:unitIndex++;unit+=14;
 }while(unitIndex<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51);
 }
 unit=map+0x67a4+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*140;
 if(func_ov000_0217bc84(unit[43]&127,unit[44]&127,4)!=0 && (s32)M2C_FIELD(*gCurrentMap,u16 *,0x52a2)<10)return 0;
 map=*gCurrentMap;unit=map+0x67a4+M2C_FIELD(map,u16 *,0x52a4)*140;
 FloodFillUnitRange(unit[43]&127,unit[44]&127,7,110,0);
 choice=func_ov000_021a6d4c();if(choice==-1)return 0;
 if(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<23)>>29)&2)gAiCommand[6]=6;
 else gAiCommand[6]=7;
 lastMap=*gCurrentMap;player=M2C_FIELD(lastMap,u16 *,0x52a4);
 if(func_020d2d18(player,gAiCommand[6])*10>M2C_FIELD(lastMap+player*140,s32 *,0x67a4))return 0;
 CommitAiAction(choice);return 1;
}
