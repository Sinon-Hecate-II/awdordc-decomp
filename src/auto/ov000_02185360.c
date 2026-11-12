/* 7 functions from 0x02185360 to 0x021862E8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline void ScanVisibilityRow(s32 ty,s32 player) {
extern void **gCurrentMap; extern s8 gTerrainPropertyFlags[];
s32 GetTerrainThreatRadius(s32,s32); void func_ov000_0218500c(s32,s32,s32,s32); s32 func_ov000_021a90a8(s16,s16,s16);
s32 tx,t,kind;u8 *map;
for(tx=0;tx<M2C_FIELD(*gCurrentMap,u16*,0x5144);tx++){
map=*gCurrentMap;t=M2C_FIELD(map+tx+M2C_FIELD(map+(u32)ty*2,u16*,0x3758),u8*,0x1420);kind=t&31;
if(kind==26)func_ov000_0218500c(tx,ty,t,GetTerrainThreatRadius(t,player));
if(gTerrainPropertyFlags[kind] && func_ov000_021a90a8(M2C_FIELD(*gCurrentMap,s16*,0x52a8),(s16)tx,(s16)ty))func_ov000_0218500c(tx,ty,t,GetTerrainThreatRadius(t,player));
}
}
#pragma optimization_level 0
static inline s32 TerrainMarkable(s32 kind) { extern s8 gTerrainPropertyFlags[]; return gTerrainPropertyFlags[kind]; }
static inline void RevealTerrain(s32 x,s32 y,s32 terrain,s32 player) { s32 GetTerrainThreatRadius(s32,s32); void func_ov000_0218500c(s32,s32,s32,s32); s32 value=GetTerrainThreatRadius(terrain,player); func_ov000_0218500c(x,y,terrain,value); }
#pragma optimization_level reset
extern void **gCurrentMap;
extern u8 data_ov000_021e0550[];
extern s8 gAiRangeLayer[];

void func_ov000_02185360(s32 x,s32 y,s32 unit,s32 radius){
s32 left,xx,yy,right,bottom,top,dist;
s32 func_020ce0ec(u8,u8);
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(y+radius<bottom)bottom=y+radius;
for(yy=top;yy<=bottom;yy++){
xx=left; while(xx<=right){
dist=0;
if(x-xx>0)dist+=x-xx;else dist+=xx-x;
if(y-yy>0)dist+=y-yy;else dist+=yy-y;
if(dist>=0 && dist<=radius){
if(dist<=1 || !func_020ce0ec(unit,M2C_FIELD((u8 *)*gCurrentMap+xx+((u16 *)*gCurrentMap)[yy+0x1bac],u8 *,0x1420)))gAiRangeLayer[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=1;
}
xx++;
}
}
}

void func_ov000_021854e0(s32 x,s32 y,s32 radius,s32 offset){
extern void **gCurrentMap; extern u8 data_ov000_021e0550[];
s32 left,right,xx,yy,bottom,top,dist,width,height;
left=offset+(x-radius); if(left<0) left=0;
top=offset+(y-radius); if(top<0) top=0;
width=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
right=offset+(x+radius);
if(right>width) right=width;
height=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
bottom=height;
if(offset+(y+radius)<bottom) bottom=offset+(y+radius);
for(yy=top;yy<=bottom;yy++){
for(xx=left;xx<=right;xx++){
dist=0;
if(x-xx>0) dist+=x-xx; else dist+=xx-x;
if(y-yy>0) dist+=y-yy; else dist+=yy-y;
if(dist>=0 && dist<=radius+offset) data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
}
}

#pragma optimization_level 3
void func_ov000_021855e4(void) {
extern u8 *gAiCommandState; extern s8 gTerrainPropertyFlags[];
void MI_CpuFill8(void*,s32,s32); s32 GetTerrainThreatRadius(s32,s32);
void func_ov000_0218500c(s32,s32,s32,s32); s32 func_ov000_021a90a8(s16,s16,s16);
s32 IsUnitOnCurrentTeam(s32); s32 IsCarrierUnitKind(u32); s32 func_020a7738(void*,s32,s32,s32);
void func_ov000_021851b8(s32,s32,s32,s32); s32 GetUnitMoveRange(s32,u32);
void func_01ffc294(u16,s32,s32,u32,s32,s32);
s32 t;
s32 player=gAiCommandState[13];
s32 sx,sy,x,y;
u8 *unit;
s32 radius,n;
s32 tx,ty,kind,i,offset;
u8 *map;
if(!M2C_FIELD(*gCurrentMap,u8*,0x5156) && player!=2){MI_CpuFill8(data_ov000_021e0550,255,1288);return;}
MI_CpuFill8(data_ov000_021e0550,0,1288);
{
for(ty=0;ty<M2C_FIELD(*gCurrentMap,u16*,0x5146);ty++)for(tx=0;tx<M2C_FIELD(*gCurrentMap,u16*,0x5144);tx++){
map=*gCurrentMap;
t=M2C_FIELD(map+tx+M2C_FIELD((short)map+(u32)ty*2,u16*,0x3758),u8*,0x1420);kind=t&31;
if(kind==26)func_ov000_0218500c(tx,ty,t,GetTerrainThreatRadius(t,player));
if(gTerrainPropertyFlags[kind]){
if(func_ov000_021a90a8(M2C_FIELD(*gCurrentMap,s16*,0x52a8),(s16)tx,(s16)ty)){
s32 r=GetTerrainThreatRadius(t,player);
func_ov000_0218500c(tx,ty,t,r);
}
}
}
}
for(i=1,offset=14;i<256;i++,offset+=14){
unit=(u8*)*gCurrentMap+0x59a4+offset;
if(!((u32)(unit[0]<<26)>>26))continue;
if(IsUnitOnCurrentTeam(i)==1)continue;
if(M2C_FIELD(unit,u16*,4)&8){
map=*gCurrentMap;
if(!IsCarrierUnitKind((u32)(M2C_FIELD(map+14*M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16*,0x3758),u8*,0x508),u8*,0x59a4)<<26)>>26))continue;
}
if(unit){if(!unit)n=0;else n=(unit-((u8*)*gCurrentMap+(unsigned short)0x59a4))/14;n=(n>>6)+1;}else n=0;
radius=func_020a7738(unit,unit[1],unit[2],player);
func_ov000_021851b8(unit[1],unit[2],n,radius);
MI_CpuFill8(gAiRangeLayer,0,1288);
func_01ffc294((u16)n,unit[1],unit[2],(u32)(unit[0]<<26)>>26,GetUnitMoveRange(n,(u32)(unit[0]<<26)>>26),4);
M2C_FIELD((u8*)*gCurrentMap+unit[2]*4,s8**,0x52e8)[unit[1]]=-1;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
if(M2C_FIELD((u8*)*gCurrentMap+(u32)y*4,s8**,0x52e8)[x]>=0)func_ov000_02185360(x,y,n,radius);
}
for(sy=0;sy<M2C_FIELD(*gCurrentMap,u16*,0x5146);sy++)for(sx=0;sx<M2C_FIELD(*gCurrentMap,u16*,0x5144);sx++){
if((s8)gAiRangeLayer[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)] && (data_ov000_021e0550[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)]&127)!=127)
data_ov000_021e0550[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)]++;
}
if(((u32)(unit[0]<<26)>>26)==5)func_ov000_021854e0(unit[1],unit[2],5,2);
}
}
#pragma optimization_level reset
/* Expand one node of the movement-range search: start from the current node's
   tile, step one cell in direction dir (0/1 = stay, 2/3 = down/up, 4/5 =
   left/right), reject off-map tiles, impassable cells (grid value < 0 or > 110)
   and cells whose range layer is already at most this cell's cost, then store
   the cost and enqueue (x, y, dir) as the next search node while the queue has
   room (349 nodes). */
void func_ov000_02185a74(u32 dir) {
extern u8 *gMoveSearchCurrent; extern u8 *gMoveSearchState; extern s32 gMoveSearchCount; extern u8 *gMoveSearchWrite;
u8 *state; void *map; s32 width,x,y,height,cost,oldCost;
gMoveSearchState[36]=gMoveSearchCurrent[0];
gMoveSearchState[37]=gMoveSearchCurrent[1];
switch(dir){case 0:case 1:break;case 2:gMoveSearchState[37]--;break;case 3:gMoveSearchState[37]++;break;case 4:gMoveSearchState[36]--;break;case 5:gMoveSearchState[36]++;break;default:break;}
if(gMoveSearchCount>=349)return;
map=*gCurrentMap;state=gMoveSearchState;
width=M2C_FIELD(map,u16 *,MAP_WIDTH);x=state[36];
if(x>=width)return;
y=state[37];height=M2C_FIELD(map,u16 *,MAP_HEIGHT);
if(y>=height)return;
cost=M2C_FIELD(((s8 **)((u8 *)map+MAP_GRID))[y],s8 *,x);
if(cost<0)return;if(cost>110)return;
if((s8)gAiRangeLayer[gMoveSearchCurrent[0]+gMoveSearchCurrent[1]*width]<=cost)return;
oldCost=(s8)gAiRangeLayer[x+y*width];
if(oldCost<=cost && oldCost>=0)return;
gAiRangeLayer[x+y*width]=cost;
gMoveSearchWrite[0]=state[36];
gMoveSearchWrite[1]=gMoveSearchState[37];
gMoveSearchWrite[2]=dir;
gMoveSearchWrite+=4;gMoveSearchCount++;
}

M2C_UNK func_ov000_02185c20(M2C_UNK arg0, M2C_UNK arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

s32 IsWithinAttackRange(u8 *a,u8 *b,s32 c){
 s32 Abs(s32); s32 GetUnitMoveRange(s32,u32); extern void **gCurrentMap;
 s32 dist,n;
 dist=Abs(a[1]-b[1]);
 dist+=Abs(a[2]-b[2]);
 if(b){if(!b)n=0;else n=((s32)b-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
 if(dist>c+(GetUnitMoveRange(n,(u32)(b[0]<<26)>>26)+1))return 0;return 1;
}

/* Mark the units of `player` that can attack `target`: for each eligible unit
 * draw its attack marker, then fold that unit's range map into the current
 * map's danger/score layer (keeping the smallest value per cell). */
void MarkPlayerThreatsToUnit(u8 player, s32 target) {
 extern u16 gPlayerUnitIdBase[];
 s32 GetUnitAttackClass(s32);
 s32 IsUnitSelected(void *);
 s32 GetUnitDamagePercent(u32,u32);
 s32 GetUnitMoveRange(s32,u32);
 void FloodFillUnitRange(s32,s32,s32,s32,s32);
 void MarkAdjacentCells(s32);
 s32 slot,value,x,y,existing;
 u8 *unit, *q=(u8 *)target;
 M2C_FIELD(*gCurrentMap,u16 *,MAP_ACTIVE_PLAYER)=player;
 for(slot=gPlayerUnitIdBase[player]+1;slot<gPlayerUnitIdBase[player]+0x33;slot++){
 unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+slot*14;
 if(!((u32)(unit[0]<<26)>>26))continue;
 if(GetUnitAttackClass((u32)(unit[0]<<26)>>26))continue;
 if(M2C_FIELD(unit,u16 *,4)&8)continue;
 if(IsUnitSelected(unit))continue;
 if(!GetUnitDamagePercent((u32)(unit[0]<<26)>>26,(u32)(q[0]<<26)>>26))continue;
 if(!IsWithinAttackRange(q,unit,0))continue;
 if(unit){if(unit == 0)value=0;else value=((s32)unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/14;value=(value>>6)+1;}else value=0;
 value=GetUnitMoveRange(value,(u32)(unit[0]<<26)>>26);
 FloodFillUnitRange(unit[1],unit[2],(u32)(unit[0]<<26)>>26,value,12);
 MarkAdjacentCells(0x6f);
 if(M2C_FIELD(((s8 **)((u8 *)*gCurrentMap+MAP_GRID))[q[2]],s8 *,q[1])<0)continue;
 func_ov000_02185c20(q[1],q[2]);
 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);y++){
 for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);x++){
 value=(s8)gAiRangeLayer[x+y*M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)];
 if(value>=0){
 unit=(u8 *)*gCurrentMap+x+((u16 *)*gCurrentMap)[y+0x1bac];
 existing=M2C_FIELD(unit,s8 *,MAP_CELL_SCORE);
 if(existing<0 || value<existing)M2C_FIELD(unit,s8 *,(unsigned)MAP_CELL_SCORE)=value;
 }
 }
 }
 }
}

