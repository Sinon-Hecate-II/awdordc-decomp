/* 2 functions from 0x0218F468 to 0x02190094 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern s8 data_ov000_021b5500[];
extern void *gAiCommandState;
extern u16 gPlayerUnitIdBase[];
typedef struct UnitF468Data {u8 bytes[14];} UnitF468Data;
typedef struct ByteF468 {u8 kind:6;u8 team:2;} ByteF468;
typedef struct ActionF468 {u8 action:4;u8 rest:4;} ActionF468;
typedef struct HealthF468 {u16 health:7;u16 pad:4;u16 flags:5;} HealthF468;
typedef struct DestF468 {u16 x:6;u16 y:6;u16 pad:4;} DestF468;
typedef struct FlagF468 {u8 pad:3;u8 flag:1;u8 rest:4;} FlagF468;
static inline void *MapF468(void){return *gCurrentMap;}
static inline void *SelectedF468(void){return M2C_FIELD(MapF468(),void **,0x52d0);}
static inline u8 KindF468(void *u){return M2C_FIELD(u,ByteF468 *,0).kind;}
static inline u8 ActionGetF468(void *u){return M2C_FIELD(u,ActionF468 *,11).action;}
static inline void ClearF468(void){void *u=SelectedF468();M2C_FIELD(u,u8 *,11)&=~15;}
static inline u8 *TileF468(s32 x,s32 y){u8 *m=MapF468();return m+x+M2C_FIELD(m+y*2,u16 *,0x3758);}
static inline s32 PassF468(s32 x,s32 y){return M2C_FIELD(M2C_FIELD((u8 *)MapF468()+y*4,s8 **,0x52e8),s8 *,x);}
static inline s32 DistanceF468(s32 x,s32 y,s32 xx,s32 yy){s32 n=0; s32 d=x-xx;if(d>0)n+=d;else n+=xx-x;d=y-yy;if(d>0)n+=d;else n+=yy-y;return n;}
static inline s32 MinF468(s32 a,s32 b){if(a<b)b=a;return b;}
static inline s32 MaxF468(s32 a){if(a<0)a=0;return a;}
static inline s32 IdF468(void *u){if(u==0)return 0;return ((u8 *)u-((u8 *)MapF468()+0x59a4))/14;}
static inline void *UnitF468(s16 id){return (u8 *)MapF468()+0x59a4+id*14;}
static inline void *UnitAtF468(s32 x,s32 y){u8 *m=MapF468();u8 *p=m+x;u16 row=M2C_FIELD(m+y*2,u16 *,0x3758);s16 id=M2C_FIELD(p+row,u8 *,0x508);return m+0x59a4+id*14;}

#pragma opt_strength_reduction off
void func_ov000_0218f468(void){
s32 Divide(s32,s32);s32 IsAllyUnitAtCell(s16,s16);s32 IsCurrentPlayerUnit(s16);
void func_ov000_0217c3a4(void);void func_ov000_02199f38(void);void BuildUnitMoveRange(void *);
s32 func_020d27a4(s32,s32);s32 GetUnitDamagePercent(s32,s32);
s32 func_ov000_021aa820(s16 *,u16,s32,s32);void SetMapCursor(s16,s16,s32,u8,u8);
s32 CanUnitAttackKind(void *,s32);void FloodFillUnitRange(u8,u8,u8,s32,s32);void PlanMoveDestination(s32,s32);
u8 *u,*m,*v,*tile; s32 x,y,health,action; s16 pos[2];
u=SelectedF468();x=M2C_FIELD(u,DestF468 *,8).x;y=M2C_FIELD(u,DestF468 *,8).y;
health=M2C_FIELD(u,HealthF468 *,6).health;
if(health==0)health=0;else health=Divide(health-1,10)+1;
if(health>=7){
u8 terrain=M2C_FIELD(TileF468(x,y),u8 *,0x1420);
if((terrain&0xe0)==0 || (terrain&31)==15){
if(IsAllyUnitAtCell((s16)x,(s16)y)==0 || IsCurrentPlayerUnit(M2C_FIELD(TileF468(x,y),u8 *,0x508))!=0)goto prepared;
}}
ClearF468();func_ov000_0217c3a4();func_ov000_02199f38();
prepared:
BuildUnitMoveRange(SelectedF468());
if(PassF468(x,y)<0){
s32 left,top,right,bottom,xx,yy;
left=MaxF468(x-2);top=MaxF468(y-2);m=MapF468();
right=MinF468(x+2,M2C_FIELD(m,u16 *,0x5144)-1);bottom=MinF468(y+2,M2C_FIELD(m,u16 *,0x5146)-1);
for(yy=top;yy<=bottom;yy++)for(xx=left;xx<=right;xx++){
s32 dist=DistanceF468(x,y,xx,yy);if(dist<0)continue;if(dist>2)continue;
v=UnitAtF468(xx,yy);
if(KindF468(v)!=0 && func_020d27a4(M2C_FIELD(MapF468(),u8 *,0x52d4),IdF468(v))==0 && M2C_FIELD(v,HealthF468 *,6).health>=50 && GetUnitDamagePercent(KindF468(v),KindF468(SelectedF468()))!=0){ClearF468();func_ov000_0217c3a4();func_ov000_02199f38();}
}}
if(PassF468(x,y)>=0){
if(data_ov000_021b5500[M2C_FIELD(TileF468(x,y),u8 *,0x1420)&31]==0){ClearF468();func_ov000_02199f38();}
if(IsAllyUnitAtCell((s16)x,(s16)y)!=0){
if(M2C_FIELD(gAiCommandState,FlagF468 *,7).flag)func_ov000_02199f38();return;
}
m=MapF468();tile=TileF468(x,y);
if((M2C_FIELD(tile,u8 *,0x1420)&31)==24){
pos[0]=x;pos[1]=y;
if(func_ov000_021aa820(pos,M2C_FIELD(MapF468(),u16 *,0x52a4),1,0)==1){
ClearF468();func_ov000_0217c3a4();SetMapCursor((s16)x,(s16)y,19,(u8)pos[0],(u8)pos[1]);return;
}
m=MapF468();tile=TileF468(x,y);v=(u8 *)m+0x6c60+M2C_FIELD(tile,s8 *,0x1928)*6;
M2C_FIELD(v,u8 *,3)++;SetMapCursor((s16)x,(s16)y,2,0,0);return;
}
v=(u8 *)m+0x6c60+M2C_FIELD(tile,s8 *,0x1928)*6;M2C_FIELD(v,u8 *,3)++;
ClearF468();func_ov000_0217c3a4();SetMapCursor((s16)x,(s16)y,3,0,0);return;
}
if(ActionGetF468(SelectedF468())==2){
s32 i,offset;
i=gPlayerUnitIdBase[M2C_FIELD(MapF468(),u16 *,0x52a4)]+1;
if(i<gPlayerUnitIdBase[M2C_FIELD(MapF468(),u16 *,0x52a4)]+51){offset=i*14;do {
v=(u8 *)MapF468()+0x59a4+offset;
if(KindF468(v)!=0 && (KindF468(v)==13 || KindF468(v)==19) && ActionGetF468(v)!=6 && PassF468(M2C_FIELD(v,u8 *,1),M2C_FIELD(v,u8 *,2))>=0 && x==M2C_FIELD(v,DestF468 *,8).x && y==M2C_FIELD(v,DestF468 *,8).y && CanUnitAttackKind(v,KindF468(SelectedF468()))!=0 && M2C_FIELD(v,HealthF468 *,6).flags==0){
SetMapCursor(M2C_FIELD(v,u8 *,1),M2C_FIELD(v,u8 *,2),7,0,0);
}
i++;offset+=14;
}while(i<gPlayerUnitIdBase[M2C_FIELD(MapF468(),u16 *,0x52a4)]+51);}
ClearF468();func_ov000_0217c3a4();func_ov000_02199f38();
}
u=SelectedF468();FloodFillUnitRange(M2C_FIELD(u,u8 *,1),M2C_FIELD(u,u8 *,2),KindF468(u),110,1);
if(PassF468(x,y)<0){ClearF468();func_ov000_0217c3a4();func_ov000_02199f38();}
PlanMoveDestination(x,y);
}
#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Picks the best destination tile for the selected AI unit: scores reachable
 * cells by terrain kind (towns, HQ, transport), prefers the least threatened
 * cell on ties, and places the cursor on the chosen tile. */
void SelectAIDestination(void) {
s32 IsFootUnitKind(s32);
void BuildUnitMoveRange(void *);
s32 func_ov000_021a8b78(void *);
s32 IsAllyUnitAtCell(s16,s16);
s32 IsCurrentPlayerUnit(s16);
s32 func_ov000_021a9860(s32,s32);
void func_ov000_02199f38(void);
s32 func_ov000_021aa820(s16 *,u16,s32,s32);
void func_ov000_0217c3a4(void);
void SetMapCursor(s16,s16,s32,u8,u8);
s16 pos[2];
s32 bestX,bestY,transportX,transportY;
s32 healthyUnit;
s32 bestScore,bestTransportScore,bestThreat;
s32 terrainKind,cellY,cellX,cellScore,threatValue;
u8 *map,*cellPtr,*record;
if(!IsFootUnitKind(KindF468(SelectedF468())))return;
BuildUnitMoveRange(SelectedF468());
bestY=9999;bestX=bestY;transportY=bestY;transportX=bestY;bestScore=-1;bestTransportScore=-1;bestThreat=32767;
healthyUnit=(u8)(func_ov000_021a8b78(SelectedF468())>=5);
for(cellY=0;cellY<M2C_FIELD(MapF468(),u16 *,0x5146);cellY++){
for(cellX=0;cellX<M2C_FIELD(MapF468(),u16 *,0x5144);cellX++){
if(PassF468(cellX,cellY)<0)continue;
if(IsAllyUnitAtCell((s16)cellX,(s16)cellY)){
if(!IsCurrentPlayerUnit(M2C_FIELD(TileF468(cellX,cellY),u8 *,0)))continue;
map=MapF468();
if(M2C_FIELD(map+M2C_FIELD(TileF468(cellX,cellY),u8 *,0)*14,u16 *,0x59a8)&1)continue;
if(!M2C_FIELD(gAiCommandState,FlagF468 *,7).flag)continue;
}
terrainKind=M2C_FIELD(TileF468(cellX,cellY),u8 *,0x1420)&31;
if(healthyUnit==1&&terrainKind!=24)continue;
if(!func_ov000_021a9860(cellX,cellY))continue;
map=MapF468();
if(cellX==M2C_FIELD(SelectedF468(),DestF468 *,8).x&&cellY==M2C_FIELD(SelectedF468(),DestF468 *,8).y)cellScore=M2C_FIELD(gAiCommandState,u8 *,5)+1;
else cellScore=M2C_FIELD(M2C_FIELD(map+cellY*4,s8 **,0x52e8),s8 *,cellX);
switch(terrainKind){
case 15:cellScore+=25;break;
case 17:cellScore+=20;break;
case 24:cellScore+=15;break;
case 18:cellScore+=10;break;
case 19:cellScore+=5;break;
case 22:cellScore+=5;break;
}
if(terrainKind!=24){
if(bestScore>cellScore)continue;
cellPtr=map+cellX+M2C_FIELD(map+cellY*2,u16 *,0x3758);
threatValue=M2C_FIELD(cellPtr,u8 *,0x2840)+M2C_FIELD(cellPtr,u8 *,0x2d48);
if(bestScore==cellScore){
if(bestThreat<threatValue)continue;
if(bestThreat==threatValue&&M2C_FIELD(gAiCommandState,u8 *,3)<50)continue;
}
bestX=cellX;bestY=cellY;bestScore=cellScore;bestThreat=threatValue;
}else{
if(bestTransportScore<=cellScore){transportX=cellX;transportY=cellY;bestTransportScore=cellScore;}
}
}
}
if(bestTransportScore>bestScore){
if(IsAllyUnitAtCell((s16)transportX,(s16)transportY))func_ov000_02199f38();
pos[0]=transportX;pos[1]=transportY;
if(func_ov000_021aa820(pos,M2C_FIELD(MapF468(),u16 *,0x52a4),1,0)==1){
SetMapCursor((s16)transportX,(s16)transportY,19,(u8)pos[0],(u8)pos[1]);return;
}
}
if(bestScore==-1)return;
if(IsAllyUnitAtCell((s16)bestX,(s16)bestY))func_ov000_02199f38();
if(func_ov000_021a8b78(SelectedF468())>=2){
map=MapF468();
record=map+0x6c60+M2C_FIELD(map+(bestX+M2C_FIELD(map+bestY*2,u16 *,0x3758)),s8 *,0x1928)*6;
M2C_FIELD(record,u8 *,3)++;
}
func_ov000_0217c3a4();
SetMapCursor((s16)bestX,(s16)bestY,3,0,0);
}
#pragma pop
