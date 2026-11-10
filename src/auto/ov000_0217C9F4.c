/* 7 functions from 0x0217C9F4 to 0x0217D86C (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
static inline s32 UnitIndexC9f4(void *p) { s32 n; if(p)n=((u8 *)p-((u8 *)*gCurrentMap+0x59a4))/14;else n=0;return n; }
static inline s32 UnitOwnerC9f4(void *p) { if(p)return (UnitIndexC9f4(p)>>6)+1;return 0; }
typedef struct {
unsigned char kind:6, flags0:2;
u8 x,y,pad3[5];
unsigned short targetX:6,targetY:6,field12:2,mode:2;
u8 pad10;
unsigned char field11:5, active:1,field11hi:2;
u8 pad12[2];
} Unit0217d428;
static inline s32 DistanceC9f4(Unit0217d428 *p,s32 x,s32 y) {s32 d=0,t; t=p->x-x;if(t<=0)t=x-p->x;d+=t;t=p->y-y;if(t<=0)t=y-p->y;return d+t;}
typedef struct { u8 pad[3];u8 count;u8 pad4[2]; } Record0217d428;
static inline void SetTarget0217d428(Unit0217d428 *unit,u16 x,u16 y) {
unit->targetX=x;unit->targetY=y;
}

#pragma opt_strength_reduction off
s32 func_ov000_0217c9f4(Unit0217d428 *unit) {
s32 func_ov000_021a98e4(u32);
s32 func_ov000_0217c4c8(void *);
s32 GetUnitMoveRange(s32,u32);
s32 func_ov000_0217c420(void *,void *);
s32 IsUnitOnCurrentTeam(s32);
extern u8 data_ov000_021b5bfc[],data_ov000_021b5c0f[];
s32 count=0,maxY,minY,maxX,minX,x,y,dx,dy,dist;
u8 *map,*record,*units; s32 id; void *dimensions;
if(func_ov000_021a98e4(unit->kind)==1)return func_ov000_0217c4c8(unit);
if(func_ov000_021a98e4(unit->kind)!=0)return count;
if(unit->kind==25 && ((u32)(M2C_FIELD(unit,u16*,6)<<21)>>28)==0)return count;
minX=unit->x-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
if(minX<0)minX=0;
else minX=unit->x-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
minY=unit->y-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
if(minY<0)minY=0;
else minY=unit->y-GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
dimensions=(u8 *)*gCurrentMap+0x5120;
if(unit->x+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind)>=M2C_FIELD(dimensions,u16*,0x24)-1)
maxX=M2C_FIELD(*gCurrentMap,u16*,0x5144)-1;
else maxX=unit->x+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
dimensions=(u8 *)*gCurrentMap+0x5120;
if(unit->y+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind)>=M2C_FIELD(dimensions,u16*,0x26)-1)
maxY=M2C_FIELD(*gCurrentMap,u16*,0x5146)-1;
else maxY=unit->y+GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind);
for(y=minY;y<=maxY;y++){
for(x=minX;x<=maxX;x++){
dx=unit->x-x;if(dx<=0)dx=x-unit->x;
dist=0;
dist=dx+dist;
dy=unit->y-y;if(dy<=0)dy=y-unit->y;
dist+=dy;
if(dist>=0){ if(dist>GetUnitMoveRange(UnitOwnerC9f4(unit),unit->kind))continue;
map=*gCurrentMap;
id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
if(id && IsUnitOnCurrentTeam(id)){
map=*gCurrentMap;
units=map+0x59a4;
id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
record=units+id*14;
if(func_ov000_0217c420(record,unit)){
count++;
if(data_ov000_021b5bfc[((Unit0217d428 *)record)->kind*112+19]&16)count++;
}
}
}
}
}
if(func_ov000_0217c420(M2C_FIELD(*gCurrentMap,void**,0x52d0),unit)==1){
count++;
if(data_ov000_021b5c0f[((Unit0217d428 *)M2C_FIELD(*gCurrentMap,void**,0x52d0))->kind*112]&16)count++;
}
return count;
}
#pragma opt_propagation on
#pragma opt_strength_reduction on
int func_ov000_0217d000(int r0, int r1) {
    r1 &= 0x1F;
    if (r1 == 0x11) {
        if ((unsigned int)r0 > 0x1A) {
            return 0;
        }
        switch (r0) {
        case 5: case 7: case 8: case 10: case 11:
        case 12: case 16: case 18: case 19: case 21:
        case 22: case 26:
            return 1;
        default:
            return 0;
        }
    }
    if (r1 == 0x12) {
        if (r0 >= 0 && r0 <= 0x11) {
            switch (r0) {
            case 6: case 12: case 14: case 16: case 17:
                return 1;
            default:
                goto case13;
            }
        } else if (r0 == 0x15) {
            return 1;
        } else {
            goto case13;
        }
    } else if (r1 != 0x13) {
        return 0;
    }
case13:
    r0 -= 0x0F;
    if ((unsigned int)r0 > 8) {
        return 0;
    }
    switch (r0) {
    case 0: case 2: case 3: case 5: case 6:
    case 7: case 8:
        return 1;
    default:
        return 0;
    }
}

#pragma opt_strength_reduction off
s32 func_ov000_0217d150(s32 a,s32 b,u8 *other){
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern u8 *data_ov000_021df644;
void SelectMapLayer(void *);
void func_01ffada0(s32,s32,u32,s32,s32);
u8 *unit;
s32 y,x,map,index;
u8 *base;
s32 row;
u32 minimum;
SelectMapLayer((u8 *)*gCurrentMap+0x2338);
func_01ffada0(a,b,((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8 **,0x52d0),u8 *,0)<<26)>>26),M2C_FIELD(data_ov000_021df580,u8 *,5),0);
map=(s32)*gCurrentMap;
y=0;
if(y<M2C_FIELD(map,u16 *,0x5146))do {
x=0;
if(x<M2C_FIELD(map,u16 *,0x5144))do {
if(M2C_FIELD(M2C_FIELD(map+y*4,s8 **,0x52e8),s8 *,x)<0)goto next;
base=(u8 *)map+0x59a4;
row=M2C_FIELD(map+y*2,u16 *,0x3758);
unit=base+M2C_FIELD(row,u8 *,map+x)*14;
if(!((u32)(unit[0]<<26)>>26)||unit==M2C_FIELD(map,u8 **,0x52d0))goto next;
index=unit ? (unit-base)/14:0;
if(!func_020d27a4(M2C_FIELD(map,u8 *,0x52d4),index))goto next;
if(!GetUnitDamagePercent((u32)(unit[0]<<26)>>26,(u32)(other[0]<<26)>>26))goto next;
if(func_ov000_021a9904((u32)(unit[0]<<26)>>26))goto next;
if(IsFootUnitKind((u32)(unit[0]<<26)>>26))goto next;
if(((u32)(unit[0]<<26)>>26)==4)goto next;
if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)<60)goto next;
if(M2C_FIELD(unit,u16 *,4)&1){
map=(s32)*gCurrentMap;
minimum=data_ov000_021df644[2];
row=M2C_FIELD(map+y*2,u16 *,0x3758);
if(M2C_FIELD(row+(map+x),u8 *,0x2d48)<minimum)goto next;
}
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
return 1;
next:
map=(s32)*gCurrentMap;
x++;
}while(x<M2C_FIELD(map,u16 *,0x5144));
y++;
}while(y<M2C_FIELD(map,u16 *,0x5146));
SelectMapLayer((u8 *)map+0x1e30);
return 0;
}
#pragma opt_strength_reduction on
void func_ov000_0217d3b8(s32 arg0) {
    s32 func_ov000_021a8ac8(void *);
    extern void **gCurrentMap;
    void *unit;
    if (arg0 != 3) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) < 0x3DU) return;
    if (func_ov000_021a8ac8(unit) != 1) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u8 *, 0xB) << 28) >> 28) == 0) {
        M2C_FIELD(unit, u8 *, 0xB) |= 0x20;
    }
}

#pragma push
#pragma opt_strength_reduction off
/* AI: for each active unit of the current player, finds the reachable tile with
 * the lowest influence value, records how many units target it and sets the unit's
 * move target; clears the unit's active flag when the target is within its budget. */
void AssignUnitMoveTargets(void) {
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];
s32 IsFootUnitKind(u32);s32 func_ov000_02179b08(void *);void func_01ffada0(s32,s32,u32,s32,s32);
s32 func_ov000_021a9860(s32,s32);s32 func_ov000_021a89a4(void *);
s32 unitId,unitOffset,bestX,bestY,bestScore,x,y,value,tileId;Unit0217d428 *unit;u8 *rec;void *p;
unitId=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+1;
if(unitId>=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+51)return;
unitOffset=unitId*14;do{
unit=(Unit0217d428*)((u8*)*gCurrentMap+0x59a4+unitOffset);
if(unit->kind==0)goto nextUnit;
if(!IsFootUnitKind(unit->kind))goto nextUnit;
if(unit->active==0)goto nextUnit;
value=func_ov000_02179b08(unit);
func_01ffada0(unit->x,unit->y,unit->kind,value,0);
bestY=-1;bestX=-1;bestScore=32767;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
p=*gCurrentMap;
if(M2C_FIELD((u8*)p+y*4,s8 **,0x52e8)[x]<0)continue;
if(!func_ov000_021a9860(x,y))continue;
p=*gCurrentMap;tileId=M2C_FIELD((u8*)p+x+M2C_FIELD((u8*)p+y*2,u16*,0x3758),s8*,0x1928);
if(M2C_FIELD((u8*)p+tileId*6,u8*,0x6c63)!=0)continue;
value=M2C_FIELD((u8*)p+y*4,s8 **,0x52e8)[x];
if(bestScore>=value){bestX=x;bestY=y;bestScore=value;}
}}
if(bestScore==32767)goto nextUnit;
p=*gCurrentMap;tileId=M2C_FIELD((u8*)p+bestX+M2C_FIELD((u8*)p+bestY*2,u16*,0x3758),s8*,0x1928);
((Record0217d428*)((u8*)p+0x6c60))[tileId].count++;
SetTarget0217d428(unit,bestX,bestY);
if(bestScore<=func_ov000_021a89a4(unit))unit->active=0;
else unit->mode=1;
nextUnit: unitId++;unitOffset+=14;
}while(unitId<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16*,0x52a4)]+51);
}
#pragma opt_strength_reduction off
void func_ov000_0217d6dc(void) {
    extern u16 gPlayerUnitIdBase[];
    s32 IsFootUnitKind(u32);

    void ***mapSlot = (void ***)&gCurrentMap;
    u16 *tblBase = gPlayerUnitIdBase;

    void *map;
    void *m0;
    s32 i;
    u16 tbl;
    s32 off;
    u8 *rec;
    u32 kind;

    map = *mapSlot;
    m0 = *(void **)map;
    tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
    i = (s32)tbl + 1;
    if (i >= (s32)tbl + 0x33) return;

    off = i * 14;

    for (;;) {
        map = *mapSlot;
        m0 = *(void **)map;
        rec = (u8 *)m0 + 0x59A4 + off;

        kind = ((u32)rec[0] << 26) >> 26;
        if (kind == 0) goto loopinc;
        if (IsFootUnitKind(kind) == 0) goto loopinc;
        if ((((u32)rec[11] << 26) >> 31) == 0) goto loopinc;

        {
            u16 hw = *(u16 *)(rec + 8);
            u32 low = ((u32)hw << 26) >> 26;
            map = *mapSlot;
            m0 = *(void **)map;
            if (low != 0x3F) {
                u32 idx = ((u32)hw << 20) >> 26;
                u16 rowval = *(u16 *)((u8 *)m0 + idx * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + low + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            } else {
                u8 rec2 = rec[2];
                u8 rec1 = rec[1];
                u16 rowval = *(u16 *)((u8 *)m0 + (u32)rec2 * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + (u32)rec1 + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            }
        }

        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0x3F) | 0x3F);
            *(u16 *)(rec + 8) = t;
        }
        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0xFC0) | 0xFC0);
            *(u16 *)(rec + 8) = t;
        }
        rec[11] = (u8)(rec[11] & ~0x20);

loopinc:
        map = *mapSlot;
        m0 = *(void **)map;
        i++;
        off = off + 14;
        tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
        if (i < (s32)tbl + 0x33) continue;
        break;
    }
}
#pragma opt_strength_reduction on
void func_ov000_0217d850(void) {
    extern void *data_ov000_021df580;
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) & ~8);
}
