/* 6 functions from 0x021A7610 to 0x021A860C (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_ai.h"
#include "battle_map.h"
#pragma optimization_level 0
static inline s32 AiWeightedCount(s32 value,s32 kind) { extern u16 data_ov000_021e14aa[]; return data_ov000_021e14aa[kind]*value; }
#pragma optimization_level reset
#pragma optimization_level 0
static inline s32 AiProduct(s32 factor, s32 value) { return factor * value; }
#pragma optimization_level reset
#pragma optimization_level 0
static inline s32 AiScale(s32 value,s32 kind) {
 extern u16 data_ov000_021e14aa[];
 s32 func_ov000_021a6f24(s32,s32,s32);
 value=AiProduct(data_ov000_021e14aa[kind],value);
 return func_ov000_021a6f24(value,kind,0);
}
#pragma optimization_level reset
#pragma push
#pragma optimization_level 0
static inline s32 AiBoundMin(s32 a,s32 b) { if(a<b)return a;return b; }
static inline s32 AiPointDistance(s32 x,s32 y,s32 x2,s32 y2) {
s32 d=0;
s32 dx=x2-x,dy=y2-y;
if(dx<=0)dx=x-x2;
if(dy<=0)dy=y-y2;
d+=dx;d+=dy;
return d;
}
#pragma pop
typedef struct { s32 money; s32 unk4; s32 income; u8 pad[128]; } AiPlayer;

void func_ov000_021a7d08(void) {
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    extern u16 data_ov000_021e1474[];
    extern u16 data_ov000_021e14aa[];
    extern u16 gPlayerUnitIdBase[];
    void func_ov000_021a7610(void);

    register s32 r5 asm("r5");

    for (r5 = 0; r5 < 0x1B; r5++) {
        data_ov000_021e1474[r5] = 0;
        data_ov000_021e14aa[r5] = data_ov000_021e1474[r5];
    }

    for (r5 = 1; r5 < 5; r5++) {
        u16 field;
        s32 start;
        register s32 limit;
        register s32 inner;
        u8 *p;
        void *map;

        if (!IsPlayerActive(r5)) {
            continue;
        }
        map = *gCurrentMap;
        field = *(u16 *)((u8 *)*gCurrentMap + 0x52A4);
        if (IsSameTeam(field, r5) == 1) {
            start = gPlayerUnitIdBase[r5] + 1;
            limit = gPlayerUnitIdBase[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u32 kind, value;
                p = (u8 *)*gCurrentMap + 0x59A4 + inner * 0xE;
                kind = (u32)p[0] << 26;
kind >>= 26;
                if (kind == 0) {
                    continue;
                }
                if ((((unsigned int)p[0x0B]) << 24) >> 31) {
                    continue;
                }
                value = (u32)*(u16 *)(p + 6) << 25;
data_ov000_021e14aa[kind] += value >> 25;
            }
        } else {
            start = gPlayerUnitIdBase[r5] + 1;
            limit = gPlayerUnitIdBase[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u32 kind, value;
                p = (u8 *)*gCurrentMap + 0x59A4 + inner * 0xE;
                kind = (u32)p[0] << 26;
kind >>= 26;
                if (kind == 0) {
                    continue;
                }
                value = (u32)*(u16 *)(p + 6) << 25;
data_ov000_021e1474[kind] += value >> 25;
            }
        }
    }
    func_ov000_021a7610();
}

s32 func_ov000_021a7e98(s32 arg0) {
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6c8c();
    s32 func_ov000_021a72c0(M2C_UNK);
    s32 func_ov000_021a8784(M2C_UNK);
    extern void **gCurrentMap;
    register void *temp_r4;
    u16 temp_r5;

    if (arg0) {
        temp_r4 = *gCurrentMap;
        temp_r5 = M2C_FIELD(temp_r4, u16 *, 0x52A4);
        if ((s32) (func_020d2d18(temp_r5, 0x15) * 0xA) > M2C_FIELD(((temp_r5 * 0x8C) + temp_r4), s32 *, 0x67A4)) {
            return -1;
        }
    }
    if (func_ov000_021a72c0(0x15) == 0) {
        return -1;
    }
    if (func_ov000_021a8784(0x15) != 0) {
        return -1;
    }
    return func_ov000_021a6c8c();
}

s32 func_ov000_021a7f1c(s32 arg0) {
s32 FindAiTargetOfType(s32);s32 func_ov000_021a4dc4(void);s32 IsFootUnitKind(u8);s32 GetUnitAttackClass(u8);
s32 func_ov000_021a484c(s32,s32);s32 func_ov000_021a67f0(u8);s32 func_ov000_021a4980(s8,s32);
void func_ov000_021a0250(void);s32 func_ov000_021a4e08(u32,u32,s32);s32 func_020d2d18(u16,s32);
s32 func_ov000_021a49e0(s32);s32 func_ov000_021a881c(s32,s32);
extern u8 gUnitKindInfo[],gUnitKindStats[],gUnitKindTargetClass[],gAiTargetCandidates[],gAiCommand[];
extern u32 gUnitKindScores[];extern void **gCurrentMap;extern u8 *gAiState;
s32 mode,flag,low,best,i,index,other,cost,limit;u8 chosen;u32 score,v; s32 shortfall;u8 *attr,*entry,*map,*state;u16 price,player;
if(FindAiTargetOfType(4)==-1)return -1;
mode=func_ov000_021a4dc4();flag=mode&256;
retry:
low=(u8)mode;best=0;score=0;limit=low-1;
for(i=1,attr=gUnitKindInfo;i<27;i++,attr+=112){
if(score>=gUnitKindScores[i])continue;
if(flag){
if(IsFootUnitKind((u8)i)){if(limit<5)goto regular;}else goto regular;goto next;
}else if(low && (attr[19]&7)){
if(!GetUnitAttackClass((u8)i) && !IsFootUnitKind((u8)i) && i!=6)continue;
if(i==10 || i==26)continue;
if(IsFootUnitKind((u8)i) && limit>=5)continue;
v=gUnitKindScores[i];
if(score<=v>>1){best=i;score=v>>1;}
continue;
}
regular:
if(GetUnitAttackClass((u8)i)==1 && (attr[19]&7) && func_ov000_021a484c(mode,i)==1)continue;
score=gUnitKindScores[i];best=i;
next:;
}
if(!best)return -1;
attr=gUnitKindStats+best*112;chosen=best;
again:
index=func_ov000_021a67f0(gUnitKindTargetClass[best]);
if(index==-1)goto reject;
if((attr[19]&7) && GetUnitAttackClass(chosen)==1){
entry=gAiTargetCandidates+index*12;
if(func_ov000_021a4980((s8)entry[4],best)){entry[3]=254;goto again;}
func_ov000_021a0250();
}else if((u8)(gUnitKindTargetClass[best]+254)<=1){
entry=gAiTargetCandidates+index*12;
if(func_ov000_021a4e08(entry[0],entry[1],best)>=90){entry[3]=255;goto again;}
func_ov000_021a0250();
}
cost=func_020d2d18(*(u16 *)((u8 *)*gCurrentMap+0x52a4),best)*10;
map=*gCurrentMap;price=(u16)cost;
if(((AiPlayer *)(map+0x67a4)+*(u16 *)(map+0x52a4))->money<price){
if(arg0==1 && func_ov000_021a49e0(price)==1){
map=*gCurrentMap;state=gAiState;
*(s32 *)(state+20)=price-(((AiPlayer *)(map+0x67a4)+*(u16 *)(map+0x52a4))->income-*(s32 *)(state+16));
}
goto reject;
}
if(func_ov000_021a881c(best,5)){
other=func_ov000_021a7e98((u8)(*(s32 *)(gAiState+20)!=0));
if(other!=-1){
if(!*(s32 *)(gAiState+20)){
map=*gCurrentMap;player=*(u16 *)(map+0x52a4);
if(func_020d2d18(player,21)*10>((AiPlayer *)(map+0x67a4)+player)->money){
if(arg0==1 && func_ov000_021a49e0(func_020d2d18(*(u16 *)((u8 *)*gCurrentMap+0x52a4),21)*10)==1){
map=*gCurrentMap;state=gAiState;player=*(u16 *)(map+0x52a4);
*(s32 *)(state+20)=func_020d2d18(player,21)*10-(((AiPlayer *)(map+0x67a4)+player)->income-*(s32 *)(state+16));goto retry;
}
goto reserve;
}}
gAiCommand[6]=21;return other;
}}
reserve:
shortfall=*(s32 *)(gAiState+20);
if(shortfall && gAiState[5]){
gAiState[5]--;
if(func_ov000_021a881c(best,5)){
map=*gCurrentMap;
if(price>((AiPlayer *)(map+0x67a4)+*(u16 *)(map+0x52a4))->money-*(s32 *)(gAiState+20))goto reject;
}
gAiState[5]=0;
}else{
map=*gCurrentMap;
if(price>((AiPlayer *)(map+0x67a4)+*(u16 *)(map+0x52a4))->money-shortfall)goto reject;
}
gAiCommand[6]=best;return index;
reject:
gUnitKindScores[best]=0;func_ov000_021a0250();goto retry;
}

/* Picks the best affordable unit kind to build against one AI target candidate:
 * scans the per-kind scores, rejects unaffordable kinds, then retries once with
 * the affordable half of the army's income; on success records the kind in
 * gAiCommand and returns the candidate index, otherwise -1. */
s32 SelectUnitForTargetCandidate(s32 candidateIndex) {
 extern u8 gAiTargetCandidates[],gUnitKindInfo[],gUnitKindTargetClass[],gUnitKindStats[],gAiCommand[];
 extern u8 *gAiCommandState; extern u32 gUnitKindScores[];extern void **gCurrentMap;
 s32 GetUnitAttackClass(u8);s32 func_020d2d18(u16,s32);s32 func_ov000_021a4e08(u32,u32,s32);
 u8 *candidate=gAiTargetCandidates+candidateIndex*12;
 u32 bestScore; s32 retried=0; s32 bestKind,kind;u8 *kindInfo;u8 *map;AiPlayer *player;s32 buildCost;u32 indirect;s32 cost,money,offset;
 if(candidate[2]==3 && (((u32)(*(u16 *)(gAiCommandState+10)<<29)>>29)&2))return -1;
 for(;;) {
 bestKind=0;bestScore=0;
 for(kind=1,kindInfo=gUnitKindInfo;kind<27;kind++,kindInfo+=112) {
 if(bestScore<gUnitKindScores[kind]) {
 if(GetUnitAttackClass((u8)kind)==1 && (kindInfo[19]&7))continue;
 bestScore=gUnitKindScores[kind];bestKind=kind;
 }}
 if(bestKind==0)return -1;
 if(candidate[2]!=gUnitKindTargetClass[bestKind])goto reject;
 cost=func_020d2d18(*(u16 *)((u8 *)*gCurrentMap+MAP_CURRENT_PLAYER),bestKind)*10;
 buildCost=(u16)cost;map=*gCurrentMap;player=(AiPlayer *)(map+MAP_PLAYER_STATES)+*(u16 *)(map+MAP_CURRENT_PLAYER);
 money=player->money;
 if(money<buildCost)goto reject;
 if(!retried || (indirect=gUnitKindStats[bestKind*112+19]&16)!=0) {
 if(func_ov000_021a4e08(candidate[0],candidate[1],bestKind)<70)goto accept;
 if(gUnitKindStats[bestKind*112+19]&16)goto reject;
 if(bestKind==22)goto reject;
 retried=1;continue;
 } else {
 if(indirect!=0)goto reject;
 if(buildCost>(player->income>>1) && buildCost>(money>>1))goto reject;
 }
 accept:gAiCommand[AI_COMMAND_UNIT]=bestKind;return candidateIndex;
 reject:gUnitKindScores[bestKind]=0;
 }
}
void func_ov000_021a7610(void) {
u8 func_ov000_021a7348(void); s32 func_ov000_021a6e5c(u8); s32 func_ov000_021a72c0(s32);
s32 func_ov000_021a96f4(s32,s32,s32); s32 GetAttackDamage(s32,s32,s32);
s32 func_ov000_021a6f24(s32,s32,s32); s32 Divide(s32,s32);
s32 func_ov000_021a7084(u8,u8); s32 func_ov000_021a881c(s32,s32); s32 func_020d2d18(u16,s32);
extern u8 *gAiState; extern u32 gUnitKindScores[27];
extern u16 data_ov000_021e1474[27],data_ov000_021e14aa[27]; extern u8 *gAiCommandState;
extern u8 data_ov000_021df598[]; extern u8 gUnitKindStats[]; extern void **gCurrentMap;
s32 values[9]; s32 minimum;
s32 b,a,i,j,k,t,v;
s32 kind;
gAiState[6]=func_ov000_021a7348();
for(a=0;a<27;a++)gUnitKindScores[a]=0;
for(b=0;b<9;b++)values[b]=0;
for(i=1;i<27;i++){j=func_ov000_021a6e5c((u8)i);if(j!=10)values[j]+=data_ov000_021e1474[i];}
t=(u32)(M2C_FIELD(gAiCommandState,u16*,10)<<29)>>29;
if((t&4) && !(t&2))values[7]*=2;
for(kind=1;kind<27;kind++){
if(!func_ov000_021a72c0((u8)kind))continue;
for(j=0;j<9;j++){
if(values[j]==0)continue;
if(data_ov000_021df598[j]==22)v=func_ov000_021a96f4(kind,data_ov000_021df598[j],0);
else v=GetAttackDamage(kind,data_ov000_021df598[j],0);
v=func_ov000_021a6f24(AiProduct(v,data_ov000_021e14aa[kind]),kind,0);
if(gUnitKindStats[data_ov000_021df598[j]*112+19]&16){
if(kind==6 && (gAiState[6]==2 || gAiState[6]==4))v>>=1;
if(kind==23 && (gAiState[6]==1 || gAiState[6]==3))v>>=1;
}
values[j]-=Divide(v,100);
}
}
for(j=0;j<9;j++)if(values[j]>0)goto positive;
goto nonpositive;
positive: {
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(gAiCommandState,u16*,10)<<29)>>29)&10))continue;
for(j=0;j<9;j++)if(values[j]>0)gUnitKindScores[i]+=AiProduct(func_ov000_021a7084((u8)i,data_ov000_021df598[j]),values[j]);
for(k=0;k<func_ov000_021a881c(i,5);k++)gUnitKindScores[i]-=(u32)gUnitKindScores[i]>>3;
}
return;
}
nonpositive:
minimum=0;for(j=0;j<9;j++)if(minimum>values[j])minimum=values[j];
if(minimum!=0){
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(gAiCommandState,u16*,10)<<29)>>29)&10))continue;
for(j=0;j<9;j++)if(values[j]!=0)gUnitKindScores[i]+=AiProduct(func_ov000_021a7084((u8)i,data_ov000_021df598[j]),(values[j]-(minimum-1)));
for(k=0;k<func_ov000_021a881c(i,5);k++)gUnitKindScores[i]-=(u32)gUnitKindScores[i]>>2;
}
return;
}
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(gAiCommandState,u16*,10)<<29)>>29)&10))continue;
if(!GetAttackDamage(i,1,0))continue;
gUnitKindScores[i]=func_020d2d18(M2C_FIELD(*gCurrentMap,u16*,0x52a4),i);
for(k=0;k<func_ov000_021a881c(i,5);k++)gUnitKindScores[i]-=(u32)gUnitKindScores[i]>>2;
}
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_021a7ac0(s32 index) {
extern u16 data_ov000_021e1474[],data_ov000_021e14aa[];
extern u8 *gAiSettings;
extern u8 gAiTargetCandidates[],data_ov000_021e00ad[],gUnitKindStats[];
extern void **gCurrentMap;
void FloodFillUnitRange(s32,s32,s32,s32,s32); s32 IsUnitOnCurrentTeam(s32); void func_ov000_021a7610(void);
s32 minx,maxy,r,cx,cy; s32 maxx,y,x,i,off,miny; u8 *unit,*map,*entry;
for(i=0;i<27;i++) {data_ov000_021e1474[i]=0;data_ov000_021e14aa[i]=data_ov000_021e1474[i];}
off=index*12;
FloodFillUnitRange(gAiTargetCandidates[off],data_ov000_021e00ad[off],7,gAiSettings[16],0);
cx=gAiTargetCandidates[off]; cy=data_ov000_021e00ad[off]; r=gAiSettings[16];
minx=cx-r; if(minx<0)minx=0;
miny=cy-r; if(miny<0)miny=0;
map=*gCurrentMap;
maxx=AiBoundMin(r+cx,*(u16 *)(map+0x5144)-1);
maxy=AiBoundMin(r+cy,*(u16 *)(map+0x5146)-1);
entry=gAiTargetCandidates+off;
for(y=miny;y<=maxy;y++)for(x=minx;x<=maxx;x++){
s32 d=AiPointDistance(x,y,entry[0],entry[1]);
if(d<0||d>gAiSettings[16])continue;
map=*gCurrentMap;
i=map[*(u16 *)(map+0x3758+y*2)+x]; if(!i)continue;
unit=map+0x59a4+i*14;
if((gUnitKindStats[(((u32)(unit[0]<<26)>>26))*112+19]&7)&&((s8 **)(map+0x52e8))[y][x]<0)continue;
if(IsUnitOnCurrentTeam(i)==1)data_ov000_021e14aa[((u32)(unit[0]<<26)>>26)]+=((u32)(*(u16 *)(unit+6)<<25)>>25);
else data_ov000_021e1474[((u32)(unit[0]<<26)>>26)]+=((u32)(*(u16 *)(unit+6)<<25)>>25);
}
func_ov000_021a7610();
}
#pragma pop
