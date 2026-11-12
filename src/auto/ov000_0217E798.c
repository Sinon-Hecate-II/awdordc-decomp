/* 4 functions from 0x0217E798 to 0x0217F754 (ov000), found by ds-decomp. */
#include "common.h"
static inline s32 mapWidth(void) { extern void **gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x5144); }
static inline s32 mapHeight(void) { extern void **gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x5146); }
static inline s32 tileMin(s32 a,s32 b) { if(b<a)a=b;return a; }
static inline s32 tileMax(s32 a,s32 b) { if(a<b)a=b;return a; }
static inline s32 tileDistance(s32 x,s32 y,s32 xx,s32 yy) { s32 sum=0; if(x-xx>0)sum+=x-xx;else sum+=xx-x; if(y-yy>0)sum+=y-yy;else sum+=yy-y; return sum; }

/* Ticks a unit state: handles 0x40 pending-swap, early-outs on 0x80/0x100 flags, dispatches cases 2/9. */
void func_ov000_0217e798(M2C_UNK arg0, M2C_UNK arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    void func_ov000_0217e8c4(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    M2C_UNK func_ov000_0217f754(M2C_UNK, M2C_UNK, u8 *, u8 *);
    M2C_UNK func_ov000_02180268(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    u16 temp_r1_2;
    u8 temp_r0;
    u8 temp_r1;
    u8 temp_r2;
    void *temp_r3;

    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 0x40) {
        temp_r3 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
        temp_r2 = M2C_FIELD(temp_r3, u8 *, 0xC);
        M2C_FIELD(temp_r3, u8 *, 0xC) = (u8) M2C_FIELD(temp_r3, u8 *, 0xD);
        M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xD) = temp_r2;
        if (*arg2 == 8) {
            temp_r1 = *arg3;
            *arg3 = *arg4;
            *arg4 = temp_r1;
        }
        M2C_FIELD(gAiCommandState, u16 *, 8) = (u16) (M2C_FIELD(gAiCommandState, u16 *, 8) & ~0x40);
    }
    temp_r1_2 = M2C_FIELD(gAiCommandState, u16 *, 8);
    if (temp_r1_2 & 0x80) {
        return;
    }
    if (temp_r1_2 & 0x100) {
        *arg2 = 0xE;
        return;
    }
    temp_r0 = *arg2;
    switch (temp_r0) {                              /* irregular */
    case 2:
        if (!(temp_r1_2 & 1)) {
            func_ov000_0217f754(arg0, arg1, arg2, arg3);
        }
        break;
    case 9:
        func_ov000_02180268(arg0, arg1);
        break;
    }
    func_ov000_0217e8c4(arg0, arg1, arg2, arg3, arg4);
}

void func_ov000_0217e8c4(s32 x, s32 y, u8 *state, u8 *dir1, u8 *dir2) {
    extern void **gCurrentMap;
    extern u8 gUnitKindStats[];
    extern u8 data_ov000_021b5c0a[];
    extern u8 gMovementCostTable[];
    s32 func_020ba510(s32, s32);
    s32 GetTerrainPropertyFlagsAt(s32, s32);
    s32 func_020d27a4(s32, s32);
    s32 IsCaptureTargetAt(void *, s32, s32);
    s32 func_ov000_021a93a8(void *, s32, s32);
    s32 GetUnitDamagePercent(s32, s32);
    s32 GetUnitMoveRange(s32, s32);
    s32 GetUnitMaxAttackRange(s32, s32);
    s32 IsAllyUnitAtCell(s16, s16);
    void BuildThreatMapAgainstKind14(void);
    void func_01ffc2e8(void *);
    void MarkAdjacentCells(s32);
    u8 *map;
    u8 *sel;
    u8 *p;
    s32 kind;
    s32 minX, minY, maxX, maxY;
    s32 xx, yy;
    s32 dist;
    s32 count = 0;
    s32 n;
    s32 id, off, owner;
    s32 range;
    s8 val;

    if (*state != 2) return;
    map = *gCurrentMap;
    sel = M2C_FIELD(map, u8 **, 0x52d0);
    kind = (s32)((u32)(sel[0] << 26) >> 26);
    switch (kind) {
    case 2:
    case 3:
        if (GetTerrainPropertyFlagsAt(x, y) == 1) {
            *state = 3;
        }
        return;
    case 22:
        if (IsCaptureTargetAt(sel, x, y) == 1
            || func_ov000_021a93a8(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), x, y) == 1) {
            if (!(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u16 *, 4) & 0x20)) {
                *state = 0xa;
            }
            return;
        }
        minX = x - 16; if (minX < 0) minX = 0;
        minY = y - 16; if (minY < 0) minY = 0;
        maxX = M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1;
        if (x + 16 < maxX) maxX = x + 16;
        maxY = M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1;
        if (y + 16 < maxY) maxY = y + 16;
        for (yy = minY; yy <= maxY; yy++) {
            for (xx = minX; xx <= maxX; xx++) {
                dist = tileDistance(x, y, xx, yy);
                if (dist < 1 || dist > 0x10) continue;
                map = *gCurrentMap;
                id = M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0);
                if (id == 0) continue;
                if (func_020d27a4(M2C_FIELD(map, u8 *, 0x52d4), id) != 0) continue;
                map = *gCurrentMap;
                p = (u8 *)map + 0x59a4 + M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0) * 14;
                if (p) {
                    if (!p) off = 0;
                    else off = ((s32)p - (s32)((u8 *)*gCurrentMap + 0x59a4)) / 14;
                    owner = (off >> 6) + 1;
                } else {
                    owner = 0;
                }
                range = GetUnitMaxAttackRange(owner, (s32)((u32)(p[0] << 26) >> 26));
                if (range > 1) {
                    if (gUnitKindStats[((s32)((u32)(p[0] << 26) >> 26)) * 112 + 0x13] & 0x20) range++;
                    if (range + 6 < dist) continue;
                } else {
                    if (p) {
                        if (!p) off = 0;
                        else off = ((s32)p - (s32)((u8 *)*gCurrentMap + 0x59a4)) / 14;
                        owner = (off >> 6) + 1;
                    } else {
                        owner = 0;
                    }
                    range = GetUnitMoveRange(owner, (s32)((u32)(p[0] << 26) >> 26)) + 7;
                    if (range < dist) continue;
                    if (gUnitKindStats[((s32)((u32)(p[0] << 26) >> 26)) * 112 + 0x13] & 7) {
                        func_01ffc2e8(p);
                        MarkAdjacentCells(0x6f);
                        if (M2C_FIELD(M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8), s8 *, x) < 0) continue;
                    }
                }
                if (GetUnitDamagePercent((s32)((u32)(p[0] << 26) >> 26), 0x16) >= 0xa) count++;
            }
        }
        if (count != 0) {
            if (!(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u16 *, 4) & 0x20)) *state = 0xa;
        } else {
            if (M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u16 *, 4) & 0x20) *state = 0xb;
        }
        return;
    case 13:
        if (x == sel[1] && y == sel[2]) return;
        minX = x - 1; if (minX < 0) minX = 0;
        n = 0;
        minY = y - 1; if (minY < 0) minY = 0;
        maxX = M2C_FIELD(map, u16 *, 0x5144) - 1;
        if (x + 1 < maxX) maxX = x + 1;
        maxY = M2C_FIELD(map, u16 *, 0x5146) - 1;
        if (y + 1 < maxY) maxY = y + 1;
        for (yy = minY; yy <= maxY; yy++) {
            for (xx = minX; xx <= maxX; xx++) {
                if (tileDistance(x, y, xx, yy) != 1) continue;
                if (func_020ba510(xx, yy) != 0) n++;
            }
        }
        if (n == 0) return;
        *state = 6;
        return;
    case 23:
        if (sel[0xc] == 0) return;
        p = (u8 *)map + 0x59a4 + sel[0xc] * 14;
        if (data_ov000_021b5c0a[((s32)((u32)(p[0] << 26) >> 26)) * 112] != ((u32)(p[0xa] << 25) >> 25)) return;
        BuildThreatMapAgainstKind14();
        map = *gCurrentMap;
        minX = x - 1; if (minX < 0) minX = 0;
        minY = y - 1; if (minY < 0) minY = 0;
        maxX = M2C_FIELD(map, u16 *, 0x5144) - 1;
        if (x + 1 < maxX) maxX = x + 1;
        maxY = M2C_FIELD(map, u16 *, 0x5146) - 1;
        if (y + 1 < maxY) maxY = y + 1;
        for (yy = minY; yy <= maxY; yy++) {
            for (xx = minX; xx <= maxX; xx++) {
                if (tileDistance(x, y, xx, yy) != 1) continue;
                map = *gCurrentMap;
                val = M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[((s32)((u32)(p[0] << 26) >> 26)) * 112 + 0x12] * 32, s8 *,
                        M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x1420) & 0x1f);
                if (val == -1) continue;
                if (IsAllyUnitAtCell((s16)xx, (s16)yy) != 0) continue;
                map = *gCurrentMap;
                if (M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x2840)
                    + M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x2d48) > 0x28) continue;
                *state = 8;
                if (xx != x) *dir1 = 3 - (xx - x);
                if (yy != y) *dir1 = (yy - y) + 2;
                goto phase2;
            }
        }
    phase2:
        map = *gCurrentMap;
        sel = M2C_FIELD(map, u8 **, 0x52d0);
        if (sel[0xd] == 0) return;
        p = (u8 *)map + 0x59a4 + sel[0xd] * 14;
        if (data_ov000_021b5c0a[((s32)((u32)(p[0] << 26) >> 26)) * 112] != ((u32)(p[0xa] << 25) >> 25)) return;
        minX = x - 1; if (minX < 0) minX = 0;
        minY = y - 1; if (minY < 0) minY = 0;
        maxX = M2C_FIELD(map, u16 *, 0x5144) - 1;
        if (x + 1 < maxX) maxX = x + 1;
        maxY = M2C_FIELD(map, u16 *, 0x5146) - 1;
        if (y + 1 < maxY) maxY = y + 1;
        for (yy = minY; yy <= maxY; yy++) {
            for (xx = minX; xx <= maxX; xx++) {
                if (tileDistance(x, y, xx, yy) != 1) continue;
                map = *gCurrentMap;
                val = M2C_FIELD(M2C_FIELD(gMovementCostTable, s8 **, 0x64) + gUnitKindStats[((s32)((u32)(p[0] << 26) >> 26)) * 112 + 0x12] * 32, s8 *,
                        M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x1420) & 0x1f);
                if (val == -1) continue;
                if (IsAllyUnitAtCell((s16)xx, (s16)yy) != 0) continue;
                map = *gCurrentMap;
                if (M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x2840)
                    + M2C_FIELD(map + xx + M2C_FIELD(map + yy * 2, u16 *, 0x3758), u8 *, 0x2d48) > 0x28) continue;
                *state = 8;
                if (xx != x) *dir2 = 3 - (xx - x);
                if (yy != y) *dir2 = (yy - y) + 2;
                if (*dir1 != *dir2) return;
                *dir2 = 0;
            }
        }
        return;
    default:
        return;
    }
}

s32 func_ov000_0217f318(s16 x,s16 y) {
extern void **data_027e0058;
s32 func_020d27a4();s32 func_ov000_021a93ec();s32 func_ov000_02176e28();
s32 result,best,minx,miny,maxx,maxy; register s32 xx,yy; s32 d,unit,score;void *p;s16 pos[2];
result=0;best=0;minx=x-1;if(minx<0)minx=0;
p=*data_027e0058; miny=y-1;if(miny<0)miny=0;
maxx=M2C_FIELD(p,u16*,0x5144)-1;
maxy=M2C_FIELD(p,u16*,0x5146)-1;
if(x+1<maxx)maxx=x+1;if(y+1<maxy)maxy=y+1;
for(yy=miny;yy<=maxy;yy++)for(xx=minx;xx<=maxx;xx++){
d=tileDistance(x,y,xx,yy);
if(d<1 || d>1)continue;
p=*data_027e0058;
unit=M2C_FIELD((u8*)p+xx+M2C_FIELD((u8*)p+((u32)yy<<1),u16*,0x3758),u8*,0);
if(unit==0)continue;
if(func_020d27a4(M2C_FIELD(p,u8*,0x52d4),unit)==1)continue;
if(!func_ov000_021a93ec((s16)xx,(s16)yy))continue;
pos[0]=x;pos[1]=y;
score=func_ov000_02176e28(unit|0x20000,pos);
if(best<score){result=unit;best=score;}
}
return result;
}

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
s32 func_ov000_0217f494(s16 x,s16 y){
extern void **gCurrentMap;extern u8 gUnitKindStats[];
s32 GetUnitAttackRangeMax(u8 *);s32 func_020d27a4(s32,s32);s32 func_ov000_021a93ec(s32,s32);s32 func_ov000_02176e28(u32,void *);
s32 result=0,best=result,minx,maxy,maxx,inner,dist,dy,rev,ret,score,cand; register s32 outer; s16 pos[2];u8 *up;void *map;
ret=GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
if(x-ret<0)minx=0;else minx=x-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
ret=GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
if(y-ret<0)outer=0;else outer=y-GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
map=*gCurrentMap;ret=GetUnitAttackRangeMax(M2C_FIELD(map,u8 **,0x52d0));
if(x+ret>=M2C_FIELD(map,u16 *,0x5144)-1)maxx=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
else maxx=x+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
map=*gCurrentMap;ret=GetUnitAttackRangeMax(M2C_FIELD(map,u8 **,0x52d0));
if(y+ret>=M2C_FIELD(map,u16 *,0x5146)-1)maxy=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
else maxy=y+GetUnitAttackRangeMax(M2C_FIELD(*gCurrentMap,u8 **,0x52d0));
for(;outer<=maxy;outer++){for(inner=minx;inner<=maxx;inner++){
dist=tileDistance(x,y,inner,outer);
up=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
if(dist<gUnitKindStats[((u32)(up[0]<<26)>>26)*112+12])continue;
if(dist>GetUnitAttackRangeMax(up))continue;
map=*gCurrentMap;cand=M2C_FIELD((u8 *)map+inner+M2C_FIELD((u8 *)map+outer*2,u16 *,0x3758),u8 *,0);
if(!cand)continue;
if(func_020d27a4(M2C_FIELD(map,u8 *,0x52d4),cand)==1)continue;
if(!func_ov000_021a93ec((s16)inner,(s16)outer))continue;
pos[0]=x;pos[1]=y;
score=func_ov000_02176e28(cand|0x20000,pos);
if(best<score){result=cand;best=score;}
}}
return result;
}
