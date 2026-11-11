/* 7 functions from 0x0218E584 to 0x0218F468 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct UnitKind18e584 { u8 kind:6; u8 flags:2; } UnitKind18e584;


#pragma opt_strength_reduction off
void func_ov000_0218e584(void) {
M2C_UNK FloodFillUnitRange(s32,s32,s32,s32,s32);
void SetMapCursor(u32,u32,u32,u32,u32);
u8 CanUnitAttackKind();
s32 func_ov000_021a9214(void*,s32,s32);
s32 func_ov000_021a93a8(void*,s32,s32);
u8 func_ov000_0217a8a0(s16,s16,s32);
void PlanMoveDestination(s32,s32);
void func_ov000_0217c3a4(void);
extern void **gCurrentMap;
extern void *gAiCommandState,*gAiUnitTypeTuning;
extern s8 gTerrainPropertyType[];
s32 bestX,bestY,x,y,best,score,cost;
u8 *selected,*unit;
u16 row;
u8 id;
func_ov000_0218df00();

selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
FloodFillUnitRange(selected[1],selected[2],((UnitKind18e584*)selected)->kind,0x6e,1);
bestY=-1;bestX=bestY;best=bestY+0x8000;

for(y=0;y<M2C_FIELD(((u8*)*gCurrentMap),u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(((u8*)*gCurrentMap),u16*,0x5144);x++){
cost=M2C_FIELD(((u8*)*gCurrentMap)+y*4,s8**,0x52e8)[x];
if(cost<0)goto next;
row=M2C_FIELD(((u8*)*gCurrentMap)+y*2,u16*,0x3758);
id=(((u8*)*gCurrentMap)+x)[row];
if(id){
if(M2C_FIELD(((u8*)*gCurrentMap),u16*,0x52a8)!=(id&0xc0))goto next;
unit=((u8*)*gCurrentMap)+0x59a4+id*14;
if((((UnitKind18e584*)unit)->kind)!=0x15)goto next;
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
if((((UnitKind18e584*)selected)->kind)==0x11)
if(cost<=best){bestX=x;bestY=y;best=score;}
if(cost>((u8*)gAiCommandState)[5])goto next;
if(!CanUnitAttackKind(unit))goto next;
SetMapCursor((s16)x,(s16)y,7,0,0);
}else{
if(!func_ov000_021a9214(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,y)){

if(!func_ov000_021a93a8(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,y))goto next;
}
if(!func_ov000_0217a8a0(x,y,((u8*)gAiCommandState)[5]))goto next;

row=M2C_FIELD(((u8*)*gCurrentMap)+y*2,u16*,0x3758);
if(M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x2d48)>=((u8*)gAiUnitTypeTuning)[2])goto next;
cost=M2C_FIELD(((u8*)*gCurrentMap)+y*4,s8**,0x52e8)[x];
score=cost;
if(gTerrainPropertyType[M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x1420)&31])score=cost+((u8*)gAiCommandState)[5];
if(cost<=((u8*)gAiCommandState)[5]){
if(func_ov000_02178778((s16)x,(s16)y)==1)goto next;

row=M2C_FIELD(((u8*)*gCurrentMap)+y*2,u16*,0x3758);
if(M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x2840)>((u8*)gAiUnitTypeTuning)[1] || M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x2d48)>((u8*)gAiUnitTypeTuning)[2])goto next;
if(func_ov000_021a93a8(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,y)==1)score=0;
}
if(score<=best){bestX=x;bestY=y;best=score;}
}
next:
}
}
if(bestX==-1)return;
func_ov000_0217c3a4();

if(M2C_FIELD(((u8*)*gCurrentMap)+bestY*4,s8**,0x52e8)[bestX]<=((u8*)gAiCommandState)[5] && ((u8*)*gCurrentMap)[M2C_FIELD(((u8*)*gCurrentMap)+bestY*2,u16*,0x3758)+bestX]==0){
SetMapCursor((s16)bestX,(s16)bestY,2,0,0);return;
}
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
if(func_ov000_021a9214(selected,selected[1],selected[2])==1 && (M2C_FIELD(gAiCommandState,u16*,8)&0x80)){
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
SetMapCursor(selected[1],selected[2],2,0,0);return;
}
PlanMoveDestination(bestX,bestY);
}
#pragma opt_strength_reduction off
void func_ov000_0218e9ac(void) {
M2C_UNK FloodFillUnitRange(s32,s32,s32,s32,s32);
void SetMapCursor(u32,u32,u32,u32,u32);
u8 CanUnitAttackKind();
s32 func_ov000_021a9214(void*,s32,s32);
s32 func_ov000_021a93a8(void*,s32,s32);
u8 func_ov000_0217a8a0(s16,s16,s32);
void PlanMoveDestination(s32,s32);
void func_ov000_0217c3a4(void);
extern void **gCurrentMap;
extern void *gAiCommandState,*gAiUnitTypeTuning;
extern s8 gTerrainPropertyType[];
s32 bestY,y,best,score,x,cost,bestX;
s16 buf[2];
u8 *selected,*unit;
u16 row;
u8 id;
s32 func_ov000_02177f24(s32,s32,s16 *);
void func_01ffb9c4(s8);
extern u8 gUnitKindStats[];

bestX=-1;bestY=bestX;best=bestX+0x8000;
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
FloodFillUnitRange(selected[1],selected[2],((UnitKind18e584*)selected)->kind,0x6e,1);
func_01ffb9c4(0x6f);

for(y=0;y<M2C_FIELD(((u8*)*gCurrentMap),u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(((u8*)*gCurrentMap),u16*,0x5144);x++){
cost=M2C_FIELD(((u8*)*gCurrentMap)+y*4,s8**,0x52e8)[x];
if(cost<0)goto next;
row=M2C_FIELD(((u8*)*gCurrentMap)+y*2,u16*,0x3758);
id=(((u8*)*gCurrentMap)+x)[row];
if(id){
if(M2C_FIELD(((u8*)*gCurrentMap),u16*,0x52a8)!=(id&0xc0))goto next;
unit=((u8*)*gCurrentMap)+0x59a4+id*14;
switch(((UnitKind18e584*)unit)->kind){
case 13:
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
if(!gUnitKindStats[((UnitKind18e584*)selected)->kind*112+0x6a])goto next;
if(!(M2C_FIELD(unit,u16*,4)&1))goto next;
if(!func_ov000_02177f24(x,y,buf))goto next;
if(M2C_FIELD(((u8*)*gCurrentMap)+buf[0]+M2C_FIELD(((u8*)*gCurrentMap)+buf[1]*2,u16*,0x3758),u8*,0x2d48)>=((u8*)gAiUnitTypeTuning)[2])goto next;
SetMapCursor(buf[0],buf[1],2,0,0);goto next;
case 21:break;case 23:goto case23;default:goto next;
}
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
if((((UnitKind18e584*)selected)->kind)==0x11)
if(cost<=best){bestX=x;bestY=y;best=score;}
case23:
if(cost>((u8*)gAiCommandState)[5])goto next;
selected=M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0);
if(!CanUnitAttackKind(unit,((UnitKind18e584*)selected)->kind))goto next;
SetMapCursor((s16)x,(s16)y,7,0,0);
}else{
if(!func_ov000_021a9214(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,y)){

if(!func_ov000_021a93a8(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,y))goto next;
}
if(!func_ov000_0217a8a0(x,y,((u8*)gAiCommandState)[5]))goto next;

row=M2C_FIELD(((u8*)*gCurrentMap)+y*2,u16*,0x3758);
if(M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x2d48)>=((u8*)gAiUnitTypeTuning)[2])goto next;
cost=M2C_FIELD(((u8*)*gCurrentMap)+y*4,s8**,0x52e8)[x];
score=cost;
if(gTerrainPropertyType[M2C_FIELD(((u8*)*gCurrentMap)+x+row,u8*,0x1420)&31])score=cost+((u8*)gAiCommandState)[5];
if(func_ov000_021a93a8(M2C_FIELD(((u8*)*gCurrentMap),u8**,0x52d0),x,(short)y)==1)score=0;
if(score<=best){bestX=x;bestY=y;best=score;}
}
next:
}
}
if(best==0x7fff)return;
func_ov000_0217c3a4();

if(M2C_FIELD(((u8*)*gCurrentMap)+bestY*4,s8**,0x52e8)[bestX]<=((u8*)gAiCommandState)[5] && ((u8*)*gCurrentMap)[M2C_FIELD(((u8*)*gCurrentMap)+bestY*2,u16*,0x3758)+bestX]==0){
SetMapCursor((s16)bestX,(s16)bestY,2,0,0);return;
}
PlanMoveDestination(bestX,bestY);
}
#pragma opt_strength_reduction reset
void func_ov000_0218edd8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK SelectJoinTarget();
    void func_ov000_0218e9ac();
    void func_ov000_0218e584();
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    void *temp_r0;
    void *temp_r1;
    temp_r0 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        SelectJoinTarget();
    }
    temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) == 0) return;
    if (IsFootUnitKind((u32)(M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) func_ov000_0218dda4();
    M2C_FIELD(gAiCommandState, u8 *, 7) = (u8)(M2C_FIELD(gAiCommandState, u8 *, 7) | 2);
    switch ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u16 *, 8) << 0x12) >> 0x1E) {
    case 1: func_ov000_0218e9ac(); break;
    case 2: func_ov000_0218e584(); break;
    }
}

void func_ov000_0218eea8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK SelectJoinTarget();
    void func_ov000_0218e9ac();
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 IsFootUnitKind(u32);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    void *temp_r0;
    void *temp_r1;

    temp_r0 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        SelectJoinTarget();
    }
    temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32) (M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) != 1) {
        return;
    }
    if (IsFootUnitKind((u32) (M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) {
        func_ov000_0218dda4();
    }
    M2C_FIELD(gAiCommandState, u8 *, 7) = (u8) (M2C_FIELD(gAiCommandState, u8 *, 7) | 2);
    func_ov000_0218e9ac();
}

/* AI: builds the cursor unit's move range, scans the map for the reachable
 * enemy it should attack (validated by func_020ba510, target flag set, lowest
 * health), resolves a firing tile with func_ov000_02177f24, then clears the
 * target flag and moves the cursor onto that tile (mode 6). */
void func_ov000_0218ef40(void) {
    s32 func_020ba510(s32, s32);
    s32 func_ov000_02177f24(s32, s32, s16 *);
    void SetMapCursor(u32, u32, u32, u32, u32);
    void BuildUnitMoveRange(void *);
    void func_01ffb9c4(s8);
    extern void **gCurrentMap;

    s8 *gridRow;
    void *map;
    void *unit;
    void *bestUnit = 0;
    s32 cursorX = (s32)bestUnit - 1;
    s32 cursorY = cursorX;
    s32 bestHealth = 0x64;
    s32 x;
    s32 y;
    s16 pos[2];
    u16 rowOffset;
    u8 unitId;
    u32 kind;
    u16 flags;
    u8 health;
    s32 ok;

    map=*gCurrentMap;
    BuildUnitMoveRange(*(void **)((u8 *)map + 0x52D0));
    func_01ffb9c4(0x6f);

    map=*gCurrentMap;
    y=0;
    if ((s32)*(u16 *)((u8 *)map + 0x5146) <= 0) goto outer_done;
outer_top:
    x = 0;
    if ((s32)*(u16 *)((u8 *)map + 0x5144) <= 0) goto width_done;
inner_top:
    gridRow = *(s8 **)((void **)((u8 *)map + 0x52E8) + y);
    if (gridRow[x] < 0) goto next_cell;
    rowOffset = *(u16 *)((u8 *)map + 0x3758 + y * 2);
    unitId = *((u8 *)map + x + rowOffset);
    unit = (void *)((u8 *)map + 0x59A4 + unitId * 14);
    kind = (u32)(*((u8 *)unit)<<26)>>26;
    if (kind == 0) goto next_cell;
    if (unit == *(void **)((u8 *)map + 0x52D0)) goto next_cell;
    ok = func_020ba510(x, y);
    if (ok == 0) goto next_cell;
    flags = *(u16 *)((u8 *)unit + 8);
    if ((((u32)flags << 18) >> 30) != 1) goto next_cell;
    health = *((u8 *)unit + 10);
    if (bestHealth < (s32)((u32)(health<<25)>>25)) goto next_cell;
    ok = func_ov000_02177f24(x, y, pos);
    if (ok == 0) goto next_cell;
    cursorX = pos[0];
    cursorY = pos[1];
    bestUnit = unit;
    bestHealth = (u32)(*((u8 *)unit+10)<<25)>>25;
next_cell:
    map=*gCurrentMap;
    x++;
    if (x < *(u16 *)((u8 *)map + 0x5144)) goto inner_top;
width_done:
    y++;
    if (y < *(u16 *)((u8 *)map + 0x5146)) goto outer_top;
outer_done:
    if (cursorX == -1) return;
    {
        u16 tmp = *(u16 *)((u8 *)bestUnit + 8);
        tmp = tmp & ~0x3000;
        *(u16 *)((u8 *)bestUnit + 8) = tmp;
        SetMapCursor((s16)cursorX, (s16)cursorY, 6, 0, 0);
    }
}

void func_ov000_0218f0ec(void) {
extern void **gCurrentMap; extern void *gAiCommandState;
s32 IsFootUnitKind(u32); void BuildUnitMoveRange(void *); void func_01ffb9c4(s8); s32 func_020d280c(s32,s32,s32); s32 func_020d27a4(s32,s32); s32 func_ov000_021a8a88(void *); s32 func_ov000_021a93ec(s16,s16); s32 func_ov000_02177f24(s32,s32,s16 *); void func_ov000_02199f38(void); void func_ov000_0217c3a4(void); void SetMapCursor(u32,u32,u32,u32,u32);
u8 *unit; s32 x; s16 out[2]; s32 y;
if(!IsFootUnitKind((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,0)<<26)>>26))return;
BuildUnitMoveRange(M2C_FIELD(*gCurrentMap,void **,0x52d0));
func_01ffb9c4(111);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
u8 *map=*gCurrentMap; s32 tile;
if(M2C_FIELD(M2C_FIELD(map+y*4,s8 **,0x52e8)+x,s8 *,0)<0)continue;
tile=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420);
if((tile&31)!=15 && (tile&31)!=17 && (tile&31)!=18)continue;
if((tile>>5)!=0){if(!func_020d280c(M2C_FIELD(map,u16 *,0x52a4),x,y))continue;}
map=*gCurrentMap;
unit=map+0x59a4+14*M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
if(!IsFootUnitKind((u32)(unit[0]<<26)>>26))continue;
if(func_020d27a4(M2C_FIELD(*gCurrentMap,u8 *,0x52d4),unit?((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14:0)==1)continue;
if(!func_ov000_021a8a88(unit))continue;
if(!func_ov000_021a93ec((s16)x,(s16)y))continue;
if(!func_ov000_02177f24(x,y,out))continue;
if((u32)(M2C_FIELD(gAiCommandState,u8 *,7)<<28)>>31){func_ov000_02199f38();return;}
func_ov000_0217c3a4();
{u8 *base=*gCurrentMap; SetMapCursor(out[0],out[1],4,base[x+M2C_FIELD(base+y*2,u16 *,0x3758)],0);}
return;
}
}
}

void func_ov000_0218f37c(void) {
extern void **gCurrentMap;
s32 IsFootUnitKind(u32);
s32 func_ov000_021a8b78(void *);
void func_ov000_0217c3a4(void);
void SetMapCursor(u32,u32,u32,u32,u32);
u8 *p;
u8 *base;
u8 *q;
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(!IsFootUnitKind((u32)(p[0]<<26)>>26))return;
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(!((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27))return;
if(func_ov000_021a8b78(p)>=2) {
base=*gCurrentMap;
p=M2C_FIELD(base,u8 **,0x52d0);
q=base+0x6c60+6*M2C_FIELD(base+(p[1]+M2C_FIELD(base+2*p[2],u16 *,0x3758)),s8 *,0x1928);
q[3]++;
}
func_ov000_0217c3a4();
p=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
SetMapCursor(p[1],p[2],3,0,0);
}

