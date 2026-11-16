/* 8 functions from 0x021862E8 to 0x02187188 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021862e8(s32 arg0) {
void FillMapLayer(s32); void SelectMapLayer(void *);
s32 IsPlayerActive(s32); s32 IsSameTeam(u16,s32); void MarkPlayerThreatsToUnit(u8,s32);
extern void **gCurrentMap;
u16 saved; s32 i; void *base;
base=*gCurrentMap; saved=M2C_FIELD(base,u16 *,0x52b6);
SelectMapLayer(base+0x2338); FillMapLayer(-1); SelectMapLayer(*gCurrentMap+0x1e30);
for(i=1;i<5;i++){if(IsPlayerActive(i)!=0 && IsSameTeam(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),i)==0)MarkPlayerThreatsToUnit(i,arg0);}
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=saved;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_0218639c(void) {
extern s32 gMoveSearchCount;extern u8 *gMoveSearchCurrent,*gMoveSearchWrite;extern void **gCurrentMap;extern s8 gAiRangeLayer[];
s32 count,x0,y0,x1,y1,cx,cy,w; s32 x,y,dist,v,index; s16 nx,ny; u8 *node,*tail;void **map;void *base;
if(gMoveSearchCount>=349)return;
node=gMoveSearchCurrent;count=0;
cx=node[0];x0=cx-1;if(x0<0)x0=0;
cy=node[1];y0=cy-1;if(y0<0)y0=0;
map=gCurrentMap;base=*map;w=M2C_FIELD(base,u16*,0x5144);
x1=w-1;if(cx+1<x1)x1=cx+1;
y1=M2C_FIELD(base,u16*,0x5146)-1;if(cy+1<y1)y1=cy+1;
for(y=y0;y<=y1;y++){for(x=x0;x<=x1;x++){
dist=0;v=node[0]-x;if(v<=0)v=x-node[0];dist+=v;v=cy-y;if(v>0)dist+=v;else dist+=y-cy;
if(dist>=1 && dist<=1){
v=M2C_FIELD((u8*)*map+M2C_FIELD((u8*)*map+y*2,u16*,0x3758)+x,s8*,0x2338);
if(v>=0){if(!(v&64) || (v&63)>node[3]){
nx=x;ny=(s16)y;count++;}}
}
}}
if(count>1)return;
index=cy*w+cx;
gAiRangeLayer[index]&=~128;
if(count==0)return;
index=ny*M2C_FIELD(*map,u16*,0x5144)+nx;
if(gAiRangeLayer[index]!=0)gAiRangeLayer[index]&=~64;
else gAiRangeLayer[index]=(node[3]+1)|64;
gMoveSearchWrite[0]=nx;gMoveSearchWrite[1]=ny;gMoveSearchWrite[2]=1;gMoveSearchWrite[3]=gMoveSearchCurrent[3]+1;
tail=gMoveSearchWrite;
M2C_FIELD((u8*)*gCurrentMap+tail[0]+M2C_FIELD((u8*)*gCurrentMap+tail[1]*2,u16*,0x3758),u8*,0x2338)=tail[3]|64;
gMoveSearchWrite+=4;gMoveSearchCount++;
}
#pragma pop
void func_ov000_02186624(u8 arg0,u8 arg1) {
 extern s8 gAiRangeLayer[];
 extern u8 *gMoveSearchState;
 extern s32 gMoveSearchCount;
 extern s8 gMoveSearchBuffer;
 extern u8 *gMoveSearchWrite,*gMoveSearchCurrent;
 extern void **gCurrentMap;
 void MI_CpuFill8(void *,s32,u32);
 void func_ov000_0218639c(void);
 s32 left,top,right,bottom,x,y,d,v;
 u8 *base,*node;
 MI_CpuFill8(gAiRangeLayer,0,0x508);
 base=gMoveSearchState;
 gMoveSearchCount=0;gMoveSearchBuffer=0;
 gMoveSearchWrite=base+0x28;gMoveSearchCurrent=base+0x5a0;
 left=0;if(arg0-1>=0)left=arg0-1;
 top=arg1-1;if(top<0)top=0;
 right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(arg0+1<right)right=arg0+1;
 bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(arg1+1<bottom)bottom=arg1+1;
 for(y=top;y<=bottom;y++)for(x=left;x<=right;x++) {
 d=0;v=arg0-x;if(v<=0)v=x-arg0;d+=v;
 if(arg1-y>0)d+=arg1-y;else d+=y-arg1;
 if(d>=1 && d<=1) {
 if(M2C_FIELD(*gCurrentMap+x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758),s8 *,0x2338)>=0) {
 gMoveSearchWrite[0]=x;gMoveSearchWrite[1]=y;gMoveSearchWrite[2]=1;gMoveSearchWrite[3]=1;
 node=gMoveSearchWrite;
 M2C_FIELD(*gCurrentMap+node[0]+M2C_FIELD(*gCurrentMap+node[1]*2,u16 *,0x3758),u8 *,0x2338)=node[3]|0x40;
 gAiRangeLayer[y*M2C_FIELD(*gCurrentMap,u16 *,0x5144)+x]=gMoveSearchWrite[3]|0xc0;
 gMoveSearchWrite+=4;
 }
 }
 }
 gMoveSearchWrite[2]=0;
 while(1) {
 if(gMoveSearchBuffer==0) {
 gMoveSearchWrite=gMoveSearchState+0x5a0;gMoveSearchCurrent=gMoveSearchState+0x28;gMoveSearchBuffer=1;gMoveSearchCount=0;
 } else {
 gMoveSearchWrite=gMoveSearchState+0x28;gMoveSearchCurrent=gMoveSearchState+0x5a0;gMoveSearchBuffer=0;gMoveSearchCount=0;
 }
 if(gMoveSearchCurrent[2]==0)break;
 while(gMoveSearchCurrent[2]!=0) {
 func_ov000_0218639c();gMoveSearchWrite[2]=0;gMoveSearchCurrent+=4;
 }
 }
 gMoveSearchState[0x24]=M2C_FIELD(*gCurrentMap,u16 *,0x5144);
 gMoveSearchState[0x25]=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
}

#pragma opt_strength_reduction on
void func_ov000_02186940(void *arg0) {
    void func_ov000_021862e8();
    void func_ov000_02186624(u8, u8);
    func_ov000_021862e8();
    func_ov000_02186624(M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 func_ov000_0218695c(void *arg0) {
s32 IsUnitSelected(void *); s32 func_ov000_021a8a88(void *); s32 GetUnitAttackClass(u32);
extern u8 gUnitKindFlags;
u16 flags; u8 result;
flags=M2C_FIELD(arg0,u16 *,4);
if(flags&8)return 0;
if(!(flags&1) && ((u32)(M2C_FIELD(arg0,u8 *,10)<<24)>>31)==0)return 0;
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<16)>>27)!=0 && func_ov000_021a8a88(arg0)==1)return 1;
if(IsUnitSelected(arg0)!=0)return 1;
if(GetUnitAttackClass((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)!=1)return 0;
result= !(*(&gUnitKindFlags+(((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70))&32);
return result;
}

void func_ov000_02186a18(void) {
    extern void **gCurrentMap;
    extern u8 gUnitKindFlags;
    extern u8 gUnitKindStats[];
    extern u16 gPlayerUnitIdBase[];
    extern u8 *gAiUnitTypeTuning;
    extern s8 gAiRangeLayer[];
    s32 GetUnitAttackClass(u32);
    u8 func_ov000_0218695c(void *);
    s32 IsWithinAttackRange(void *, void *, s32);
    void func_ov000_02186940(void *);
    void BuildUnitMoveRange(void *);
    u8 IsAllyUnitAtCell(u32, s32);
    s32 func_020cf878(s32, s32);
    void SetMapCursor(s32, s32, s32, s32, s32);
    s32 fy, i;
    register s32 y, x;
    s32 best, cell, fx, n;
    u8 *unit;

    if (GetUnitAttackClass((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) == 1
        && ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) != 0x1a)
        return;
    if ((&gUnitKindFlags)[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) * 0x70] & 0x20)
        return;
    n = gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)];
    i = n + 1;
    if (i >= n + 0x33) return;
    for (; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)] + 0x33; i++) {
        unit = (u8 *)*gCurrentMap + 0x59a4;
        if (((u32)(unit[i * 0xe] << 26) >> 26) == 0) continue;
        if (!func_ov000_0218695c(unit + i * 0xe)) continue;
        if (!IsWithinAttackRange(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), unit + i * 0xe, 0)) continue;
        func_ov000_02186940(unit + i * 0xe);
        BuildUnitMoveRange(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
        fy = -1;
        fx = -1;
        best = 0xff;
        for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
            for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
                if (((s8 **)((u8 *)*gCurrentMap + 0x52e8))[y][x] < 0) continue;
                cell = ((u8 *)gAiRangeLayer)[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
                if (cell == 0) continue;
                if (cell >= best) continue;
                if (IsAllyUnitAtCell((s16)x, (s16)y)) continue;
                if (func_020cf878(x, y)) continue;
                if ((gUnitKindStats[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) * 0x70 + 0x13] & 7) == 0) {
                    if (M2C_FIELD((u8 *)*gCurrentMap + x + ((u16 *)*gCurrentMap)[y + 0x1bac], u8 *, 0x2840) >= gAiUnitTypeTuning[1]) continue;
                }
                if (M2C_FIELD((u8 *)*gCurrentMap + x + ((u16 *)*gCurrentMap)[y + 0x1bac], u8 *, 0x2d48) >= gAiUnitTypeTuning[2]) continue;
                fx = x;
                fy = y;
                best = ((u8 *)gAiRangeLayer)[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
            }
        }
        if (fx == -1) continue;
        SetMapCursor((s16)fx, (s16)fy, 2, 0, 0);
        return;
    }
}

s32 func_ov000_02186d94(s32 a,s32 b,s32 c){
extern void **gCurrentMap; u8 IsAllyUnitAtCell(u32,s32);
extern u8 gMovementTypeTable[];extern M2C_UNK gMovementCostTable;
void *p; s32 off; s32 n; s32 idxByte,dataByte; s8 *table;
if(a<0 || b<0)goto fail;
p=*gCurrentMap;
if(a<M2C_FIELD(p,u16 *,0x5144)&&b<M2C_FIELD(p,u16 *,0x5146))goto valid;
fail:return 0;
valid:
if(IsAllyUnitAtCell((s16)a,(s16)b))return 0;
off=c*0x70;
p=*gCurrentMap;
n=M2C_FIELD(p+b*2,u16 *,0x3758);
table=M2C_FIELD(&gMovementCostTable,s8 **,0x64);
idxByte=M2C_FIELD(p+(a+n),u8 *,0x1420);
dataByte=gMovementTypeTable[off];
return ((table+(dataByte<<5))[idxByte&31]>=0)?1:0;
}

s32 CountAdjacentAccessibleCells(s32 x, s32 y) {
    extern void **gCurrentMap;
    extern u8 gMovementTypeTable[];
    extern M2C_UNK gMovementCostTable;
    s32 func_ov000_02186d94(s32, s32, s32);
    void *base;
    u8 *units;
    s8 *tbl;
    s32 off, kind;
    s32 res;

    base = *gCurrentMap;
    units = (u8 *)base + 0x59a4;
    off = M2C_FIELD(M2C_FIELD(base, u8 **, 0x52d0), u8 *, 0xc) * 0xe;
    kind = (u32)(M2C_FIELD((u8 *)base + M2C_FIELD(M2C_FIELD(base, u8 **, 0x52d0), u8 *, 0xd) * 0xe, u8 *, 0x59a4) << 26) >> 26;

    if (kind == 0) {
        res = func_ov000_02186d94(x - 1, y, (u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26);
        res += func_ov000_02186d94(x + 1, y, (u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26);
        res += func_ov000_02186d94(x, y - 1, (u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26);
        res += func_ov000_02186d94(x, y + 1, (u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26);
        return res;
    }

    tbl = M2C_FIELD(&gMovementCostTable, s8 **, 0x64);
    if (M2C_FIELD(tbl + gMovementTypeTable[kind * 0x70] * 32, s8 *, 4) < 0) {
        s32 res2;
        if (M2C_FIELD(tbl + gMovementTypeTable[((u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26) * 0x70] * 32, s8 *, 4) < 0) {
            res = func_ov000_02186d94(x - 1, y, 7);
            res += func_ov000_02186d94(x + 1, y, 7);
            res += func_ov000_02186d94(x, y - 1, 7);
            res += func_ov000_02186d94(x, y + 1, 7);
            return res;
        }
        res = func_ov000_02186d94(x - 1, y, 7);
        res += func_ov000_02186d94(x + 1, y, 7);
        res += func_ov000_02186d94(x, y - 1, 7);
        res += func_ov000_02186d94(x, y + 1, 7);
        if (res != 0) return res;
        res = func_ov000_02186d94(x - 1, y, 1);
        res += func_ov000_02186d94(x + 1, y, 1);
        res += func_ov000_02186d94(x, y - 1, 1);
        res += func_ov000_02186d94(x, y + 1, 1);
        return res != 0;
    } else {
        s32 res2;
        if (M2C_FIELD(tbl + gMovementTypeTable[((u32)(M2C_FIELD(units + off, u8 *, 0) << 26) >> 26) * 0x70] * 32, s8 *, 4) < 0) {
            res = func_ov000_02186d94(x - 1, y, 7);
            res += func_ov000_02186d94(x + 1, y, 7);
            res += func_ov000_02186d94(x, y - 1, 7);
            res += func_ov000_02186d94(x, y + 1, 7);
            if (res >= 2) return res;
            res = func_ov000_02186d94(x - 1, y, 1);
            res += func_ov000_02186d94(x + 1, y, 1);
            res += func_ov000_02186d94(x, y - 1, 1);
            res += func_ov000_02186d94(x, y + 1, 1);
            return res != 0;
        }
        res = func_ov000_02186d94(x - 1, y, 1);
        res += func_ov000_02186d94(x + 1, y, 1);
        res += func_ov000_02186d94(x, y - 1, 1);
        res += func_ov000_02186d94(x, y + 1, 1);
        return res;
    }
}

