/* 31 functions from 0x021A860C to 0x021A947C (ov000), found by ds-decomp. */
#include "common.h"
extern s8 *data_ov000_021b5c54[];

#include "ov000_unit_entry.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 pad[10]; u8 value:7; u8 flag:1; } UnkValue_021a89a4;

#pragma pool_constants off
s32 func_ov000_021a860c(void){
s32 IsPlayerActive(s32);s32 IsSameTeam(u16,s32);extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];extern u8 gUnitKindStats[];
s32 p=1,i,end;
while(p<5){
if(IsPlayerActive(p) && !IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),p)){
u16 start=gPlayerUnitIdBase[p];i=start+1;end=start+0x33;while(i<end){UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];u32 kind=(u32)(entry->unk0 & 0x3f);if(kind && (gUnitKindStats[kind*112+0x13]&16))return 1;i++;}} p=p+1;}
return 0;}
#pragma pool_constants reset
s32 func_ov000_021a86dc(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 i;

void *base = *gCurrentMap;
u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == 0xE && entry->unk6 >= 0x32U) { return 1; }
}
return 0;
}

s32 func_ov000_021a8784(s32 arg0) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 count = 0;
s32 i;
void *base = *gCurrentMap;
u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == arg0) { count += 1; }
}
return count;
}

s32 func_ov000_021a881c(s32 arg0, s32 arg1) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 count = 0;
s32 i;
void *base = *gCurrentMap;
u16 start = gPlayerUnitIdBase[M2C_FIELD(base, u16 *, 0x52A4)];
for (i = start + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)] + 0x33; i++) {
UnkStruct_ov000_021A860C *entry = &((UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4))[i];
u32 type = entry->unk0;
if (type != 0 && type == arg0 && entry->unkB != arg1) { count += 1; }
}
return count;
}

/* How many units the current player has of one kind that are not busy with an
 * action (IsMidActionStep): the AI's "do I still have a unit of kind X free?". */
s32 CountPlayerUnitsOfKind(s32 kind) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
u8 IsMidActionStep(s32);
s32 count=0,i;
void *base=*gCurrentMap;
/* the player's units are the ids after its base id up to the per-player limit */
u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,MAP_CURRENT_PLAYER)];
for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_LIMIT+1;i++){
BattleMapUnitHead *unit=&((BattleMapUnitHead *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[i];
u32 unitKind=unit->kind;
if(unitKind!=0&&unitKind==kind&&IsMidActionStep(unit->aiState)==0)count++;
}
return count;
}

/* True while a unit is in an AI step that carries out its chosen action, i.e.
 * the unit is busy with the attack or the capture it started. */
u8 IsMidActionStep(s32 aiStep) {
    u8 var_r0;

    if (aiStep == AI_STEP_ATTACK) {
        return 1U;
    }
    if (aiStep == AI_STEP_CAPTURE) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 GetAiUnitMoveRange(UnkValue_021a89a4 *a) {
extern void **gCurrentMap;
s32 func_020a86f0(s32);s32 Divide(s32,s32);s32 GetUnitMovement(void *);
s32 n=Divide(a->value,func_020a86f0(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)));
if(GetUnitMovement(a)<=n)n=GetUnitMovement(a);
return n;
}

s32 ManhattanDistance(s32 a,s32 b,s32 c,s32 d) {
s32 total=0;
if(a-c>0)total+=a-c;else total+=c-a;
if(b-d>0)total+=b-d;else total+=d-b;
return total;
}

s32 func_ov000_021a8a38(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_ip;
    s32 var_r0;
    s32 var_r2;

    var_ip = arg0 - arg2;
    if (var_ip <= 0) {
        var_ip = arg2 - arg0;
    }
    var_r2 = arg1 - arg3;
    if (var_r2 <= 0) {
        var_r2 = arg3 - arg1;
    }
    var_r0 = var_ip - var_r2;
    if (var_r0 <= 0) {
        var_r0 = var_r2 - var_ip;
    }
    return var_r0;
}

s32 GetUnitCaptureRateAtOwnTile(void *arg0) {
    M2C_UNK GetUnitCaptureRate(void *, u8, u8);
    GetUnitCaptureRate(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

s32 GetUnitCaptureRateHere(void *arg0) {
    M2C_UNK GetUnitCaptureRate(void *, u8, u8);
    GetUnitCaptureRate(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 WillCaptureCompleteThisTurn(void *a){u8 r;if(!((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27))return 0;if(GetUnitCaptureRateHere(a)+(s32)((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27)>=20)r=1;else r=0;return r;}

s32 func_ov000_021a8ac8(void *a){extern void **gCurrentMap;s32 n;if(a){if(!a)n=0;else n=((s32)a-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;if(M2C_FIELD(*gCurrentMap,u16 *,0x52a8)!=n){if(!((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27))return 0;}return GetUnitCaptureRateAtOwnTile(a)+(s32)((u32)(M2C_FIELD(a,u16 *,6)<<16)>>27)>=20;}

s32 GetCaptureTurnsLeft(void *a){s32 Divide(s32,s32);u32 v;s32 n,i,x;v=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>25;if(!v)n=0;else n=Divide(v-1,10)+1;i=0;x=(u32)(M2C_FIELD(a,u16 *,6)<<16)>>27;if(n<=0)return 20;n=GetUnitCaptureRateAtOwnTile(a);while(x<20){x+=n;i++;}return i;}

#pragma opt_strength_reduction off
s32 func_ov000_021a8be8(s32 x,s32 y,s32 radius){
extern void **gCurrentMap;
s32 IsUnitOnCurrentTeam(s32);
s32 IsUnitVisibleAtCell(u16,s32,s16,s16);
s32 IsUnitInSight(u16);
s32 i; s32 right; s32 ny; s32 j; s32 dy; s32 left; s32 top; s32 bottom; s32 d;void *base;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;
right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
if(y+radius<bottom)bottom=y+radius;
j=top;for(;j<=bottom;j++)for(i=left;i<=right;i++){
d=0;if(x-i>0)d+=x-i;else d+=i-x;dy=y-j;ny=j-y;if(dy>0)d+=dy;else d+=ny;
if(d>=0&&d<=radius){base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(!d)continue;
if(IsUnitOnCurrentTeam(d)==1)continue;
if(!IsUnitVisibleAtCell(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1,(s16)i,(s16)j))continue;
base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(IsUnitInSight(d))return 1;
}}
return 0;
}
#pragma opt_strength_reduction reset
s32 func_ov000_021a8d7c(s32 x,s32 y,s32 radius){
extern void **gCurrentMap;u8 IsCurrentPlayerUnit(s32);
s32 i,j,right,left,top,bottom,d;void *base;
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
base=*gCurrentMap;
right=M2C_FIELD(base,u16 *,0x5144)-1;
if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
if(y+radius<bottom)bottom=y+radius;
for(j=top;j<=bottom;j++)for(i=left;i<=right;i++){
d=0;if(x-i>0)d+=x-i;else d+=i-x;if(y-j>0)d+=y-j;else d+=j-y;
if(d>=0&&d<=radius){base=*gCurrentMap;
d=*((u8 *)base+i+M2C_FIELD((u8 *)base+((u32)j<<1),u16 *,0x3758));
if(d&&IsCurrentPlayerUnit(d)!=1)return 1;
}}
return 0;
}

s32 func_ov000_021a8eb0(s32 a,s32 b,s32 c){
extern void **gCurrentMap;
s32 minx=a-c,x,dy1,dy2,y,maxx,maxy,d;u8 *p;u32 v;
if(minx<0)minx=0;
y=b-c;if(y<0)y=0;
maxx=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(a+c<maxx)maxx=a+c;
maxy=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(b+c<maxy)maxy=b+c;
for(;y<=maxy;y++)for(x=minx;x<=maxx;x++){
d=0;if(a-x>0)d+=a-x;else d+=x-a;
if(b-y>0)d+=b-y;else d+=y-b;
if(d>=0&&d<=c){
p=*gCurrentMap;
v=M2C_FIELD((u8 *)((u32)x+(u32)(p+M2C_FIELD(p+((u32)y<<1),u16 *,0x3758))),u8 *,0x1420);
if((v&31)==17&&M2C_FIELD(p,u16 *,0x52a6)==(v&224))return 1;
}}
return 0;
}

u8 IsCurrentPlayerUnit(s32 arg0) {
    extern void **gCurrentMap;
    u8 var_r0;

    if ((arg0 & 0xC0) == M2C_FIELD(*gCurrentMap, u16 *, 0x52A8)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 IsPropertyTerrain(s32 arg0) {
    extern s8 gTerrainIsProperty[];
    u8 var_r0;
    if (gTerrainIsProperty[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a9014(s32 a) {
extern s8 gTerrainIsProperty[];
s32 i=a&31;u8 v;
if(i==24)return 0;
if(gTerrainIsProperty[i])v=1;else v=0;
return v;
}

u8 IsTerrainPassable(s32 a,s32 b){
extern u8 gMovementTypeTable[];
extern M2C_UNK gMovementCostTable;
u32 row=gMovementTypeTable[a*0x70];
s8 *table=M2C_FIELD(&gMovementCostTable,s8 **,0x64)+row*32;
u8 r;if(table[b&31]>0)r=1;else r=0;return r;
}

u8 func_ov000_021a9084(s32 arg0) {
    extern s8 data_ov000_021b54a0[];
    u8 var_r0;
    if (data_ov000_021b54a0[arg0 & 0x1F] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov000_021a90a8(s32 a,s32 b,s32 c){
extern void **gCurrentMap;u8 *p=*gCurrentMap;
u8 v=M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x1420)>>5;
u8 r;if(!v)return 0;
if(M2C_FIELD(p+((a>>6)+1)*0x8c,u8 *,0x67ca)!=M2C_FIELD(p+v*0x8c,u8 *,0x67ca))r=1;else r=0;return r;}

u8 func_ov000_021a911c(s32 a,s32 b,s32 c){
extern void **gCurrentMap;u8 *p=*gCurrentMap;s32 n=(a>>6)+1;u8 r;
if(n==(M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x1420)>>5))r=1;else r=0;return r;}

u8 IsCellUnitOnSameArmy(s32 a,s32 b,s32 c){
extern void **gCurrentMap;u8 *p=*gCurrentMap;
s32 v=M2C_FIELD(p+(b+M2C_FIELD(p+c*2,u16 *,0x3758)),u8 *,0x508);u8 r;if(!v)return 0;
if(M2C_FIELD(p+a*0x8c,u8 *,0x67ca)==M2C_FIELD(p+((v>>6)+1)*0x8c,u8 *,0x67ca))r=1;else r=0;return r;}

s32 func_ov000_021a91d0(s32 a){switch(a&31){case 15:case 17:case 18:case 19:case 22:return 1;default:return 0;}}

/* Returns 1 when tile (x, y) holds a property the unit could capture: a capturable
   cell owned by another army, and the unit's kind may capture that terrain. */
s32 IsCaptureTargetAt(void *unit,s32 x,s32 y){
extern void **gCurrentMap;s32 IsPropertyOwnedByTeam();
u8 *p=*gCurrentMap;s32 n;
if(IsPropertyTerrain(M2C_FIELD(p+(x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN))==1){
if(!unit)n=0;else n=((s32)unit-(s32)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/14;
if(IsPropertyOwnedByTeam((n>>6)+1,x,y)){
p=*gCurrentMap;
if(M2C_FIELD(data_ov000_021b5c54,s8 **,((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)*UNIT_KIND_STATS_SIZE)[M2C_FIELD(p+(x+M2C_FIELD(p+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK])return 1;
}}return 0;}

u8 func_ov000_021a9318(s32 a,s32 b,s32 c){extern void **gCurrentMap;s32 IsPropertyOwnedByTeam(s32);void *p;if(!IsPropertyOwnedByTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))return 0;p=*gCurrentMap;return M2C_FIELD(data_ov000_021b5c54,s8 **,a*112)[M2C_FIELD((u8 *)p+(b+M2C_FIELD((u8 *)p+c*2,u16 *,0x3758)),u8 *,0x1420)&31]!=0;}

s32 func_ov000_021a93a8(void) {
    return 0;
}

s32 func_ov000_021a93b0(s32 a,s32 b,s32 c){extern void **gCurrentMap;s32 func_020ce0ec(u8,u8);void *p=*gCurrentMap;return func_020ce0ec(a,M2C_FIELD((u8 *)p+(b+M2C_FIELD((u8 *)p+c*2,u16 *,0x3758)),u8 *,0x1420));}

s32 func_ov000_021a93ec(s32 a,s32 b){extern void **gCurrentMap;s32 IsUnitInSight(u16);void *p=*gCurrentMap;u32 n;u32 id=M2C_FIELD((u8 *)p+(a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758)),u8 *,0);if(id&&!IsUnitInSight((u16)id))return 0;p=*gCurrentMap;n=a+M2C_FIELD((u8 *)p+b*2,u16 *,0x3758);return (u8)(M2C_FIELD((u8 *)p+(n>>3),u8 *,0x5160)&(1<<(n&7)))!=0;}

