/* 9 functions from 0x0217BCD4 to 0x0217C9F4 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
static inline s32 DistanceUnitC4c8(u8 *p,s32 x,s32 y){s32 v=0;s32 a=p[1],b;s32 dx=a-x;if(dx<=0)dx=x-a;v+=dx;b=p[2];dx=b-y;if(dx<=0)dx=y-b;v+=dx;return v;}
static inline s32 DistanceC4c8(s32 a,s32 b,s32 c,s32 d){s32 v=0;s32 dx=a-c;s32 dy;if(dx<=0)dx=c-a;v+=dx;dy=b-d;if(dy<=0)dy=d-b;v+=dy;return v;}
extern void **gCurrentMap;
extern u8 data_ov000_021b5bfc[];
static inline s32 UnitIndexC4c8(u8 *p){if(p)return (p-((u8 *)*gCurrentMap+0x59a4))/14;return 0;}
static inline s32 UnitOwnerC4c8(u8 *p){if(p)return (UnitIndexC4c8(p)>>6)+1;return 0;}

#pragma scheduling off
s32 func_ov000_0217bcd4(s8 a, s8 b, s8 c, s16 d) {
s32 func_ov000_0217b3bc(s8,s8,s8,s16);
extern s32 (*data_ov000_021df650)(s32,s32,s32);
extern s32 func_ov000_0217ab5c(s32,s32,s32);
data_ov000_021df650=func_ov000_0217ab5c;
return func_ov000_0217b3bc(a,b,c,d);
}
s32 func_ov000_0217bcf4(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217abd8(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)(s32, s32, s32);

    data_ov000_021df650 = func_ov000_0217abd8;
    if (data_ov000_021df650(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}

s32 func_ov000_0217bd44(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern void **gCurrentMap;
    u8 temp_lr;
    void *temp_r4;

    temp_r4 = *gCurrentMap;
    temp_lr = M2C_FIELD((temp_r4 + (arg2 + M2C_FIELD((temp_r4 + (arg3 * 2)), u16 *, 0x3758))), u8 *, 0x508);
    if ((temp_lr != 0) && (M2C_FIELD(temp_r4, u8 *, 0x52D4) != temp_lr)) {
        return 5;
    }
    if (arg0 > arg2) {
        return 4;
    }
    if (arg0 < arg2) {
        return 2;
    }
    if (arg1 > arg3) {
        return 1;
    }
    if (arg1 < arg3) {
        return 3;
    }
    return 0;
}

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_ov000_0217bdb4(s32 arg0, s32 arg1) {
    void SelectMapLayer(void *);
    s32 FloodFillUnitRange(s32, s32, s32, s32, s32);
    s32 IsCurrentPlayerUnit(s16);
    s32 IsFootUnitKind(void);
    s32 ManhattanDistance(s32, s32, s32, s32);
    extern void **gCurrentMap;

    s32 x = arg0;
    s32 y = arg1;
    void *base;

    base = *gCurrentMap;
    SelectMapLayer((u8 *)base + 0x338 + 0x2000);
    FloodFillUnitRange(x, y, 3, 6, 1);
    base = *gCurrentMap;
    {
        u16 rowOff = M2C_FIELD((u8 *)base + (y << 1), u16 *, 0x3758);
        s32 id = ((u8 *)base)[x + rowOff];
        if (id != 0) {
            if (IsCurrentPlayerUnit((s16)id) == 1) {
                u8 *entry;
                u16 raw;
                base = *gCurrentMap;
                entry = (u8 *)base + ((u32)id * 14) + 0x59A4;
                raw = M2C_FIELD((u8 *)base + id * 14, u16 *, 0x59AA);
                if (((u32)(raw << 16) >> 27) != 0U) {
                    SelectMapLayer((u8 *)base + 0xE30 + 0x1000);
                    return 1;
                }
            }
        }
    }

    {
        s32 bottom;
        s32 right;
        s32 xmin;
        s32 ymin;
        s32 xmax;
        s32 ymax;
        s16 ys;
        s16 xs;
        UnkStruct_ov000_021A860C *entry;
        s32 xx;
        s32 dy;
        s32 yy;

        xmin = x - 6;
        if (xmin < 0) {
            xmin = 0;
        }
        ymin = y - 6;
        if (ymin < 0) {
            ymin = 0;
        }
        base = *gCurrentMap;
        xmax = x + 6;
        right = M2C_FIELD(base, u16 *, 0x5144) - 1;
        if (xmax < right) {
            right = xmax;
        }
        ymax = y + 6;
        bottom = M2C_FIELD(base, u16 *, 0x5146) - 1;
        if (ymax < bottom) {
            bottom = ymax;
        }

        for (yy = ymin; yy <= bottom; yy++) {
            for (xx = xmin; xx <= right; xx++) {
                s32 dist;
                s32 dxd;
                s32 id2;
                u16 rowOff2;
                u16 raw2;
                s32 kind;

                xs = (s16)x;
                ys = (s16)y;

                dxd = x - xx;
                if (dxd <= 0) {
                    dxd = xx - x;
                }
                dist = 0;
                dxd += dist;
                dy = y - yy;
                if (dy > 0) {
                    dxd += dy;
                } else {
                    dxd += yy-y;
                }

                if (dxd < 0) {
                    continue;
                }
                if (dxd > 6) {
                    continue;
                }

                base = *gCurrentMap;
                if (((s8 **)((u8 *)base + 0x52E8))[yy][xx] < 0) {
                    continue;
                }

                rowOff2 = M2C_FIELD((u8 *)base + (yy << 1), u16 *, 0x3758);
                id2 = ((u8 *)base + xx)[rowOff2];

                entry = (UnkStruct_ov000_021A860C *)((u8 *)base + 0x59A4) + (s16)id2;
                kind = (s16)(entry->unk0);

                if (kind == 0) {
                    continue;
                }

                if (IsFootUnitKind() == 0) {
                    continue;
                }

                raw2 = *(u16 *)((u8 *)entry + 8);
                if (x != (s32)(((u32)(raw2 << 26)) >> 26) || y != (s32)(((u32)(raw2 << 20)) >> 26)) {
                    continue;
                }

                if (entry->unk0 == 1) {
                    if (ManhattanDistance(((u8 *)entry)[1], ((u8 *)entry)[2], xs, ys) > 3) {
                        continue;
                    }
                }
                if (entry->unk0 == 2) {
                    if (ManhattanDistance(((u8 *)entry)[1], ((u8 *)entry)[2], xs, ys) > 2) {
                        continue;
                    }
                }

                base = *gCurrentMap;
                SelectMapLayer((u8 *)base + 0xE30 + 0x1000);
                return 1;
            }
        }
    }

    base = *gCurrentMap;
    SelectMapLayer((u8 *)base + 0xE30 + 0x1000);
    return 0;
}
#pragma opt_propagation off
s32 func_ov000_0217c08c(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) {
    s32 func_ov000_021a9860(s32, s32);
    s32 func_ov000_0217bdb4(s32, s32);
    extern void **gCurrentMap;

    s32 bestScore = -1;
    s32 bestX;
    s32 bestY = -1;
    s32 lowX;
    register s32 lowY;
    void *map;
    register s32 highX;
    s32 highY;
    s32 x;
    s32 y;

    (void)a4;

    bestX=-1;
    lowX = a0 - a2;
    if (lowX < 0) lowX = 0;
    lowY = a1 - a2;
    if (lowY < 0) lowY = 0;

    map = *gCurrentMap;

    highX = *((u16 *)((u8 *)map + 0x5144)) - 1;
    if (a0+a2 < highX) highX=a0+a2;
    highY = *((u16 *)((u8 *)map + 0x5146)) - 1;
    if (a1+a2 < highY) highY=a1+a2;

    for (y = lowY; y <= highY; y++) {
        x=lowX;
        if(x<=highX) do {
            s32 dx = a0 - x;
            s32 dy;
            s32 dist;

            if (dx <= 0) dx = x - a0;
            dy = a1 - y;
            dist = 0;
            dist = dx + dist;
            if (dy > 0) dist += dy; else dist += y - a1;
            if (dist < 0) goto next;
            if (dist > a2) goto next;

            if (!func_ov000_021a9860(x, y)) goto next;

            map = *gCurrentMap;
            {
                u16 rowOff = *((u16 *)((u8 *)map + (y << 1) + 0x3758));
                s8 terrain = *((s8 *)((u8 *)map + x + rowOff + 0x1928));
                u8 attr = *((u8 *)((u8 *)map + terrain * 6 + 0x6c63));
                if (attr != 0) {
                    if (func_ov000_0217bdb4(x, y) != 0) goto next;
                }
            }

            map = *gCurrentMap;
            {
                u16 rowOff = *((u16 *)((u8 *)map + (y << 1) + 0x3758));
                u8 tileByte = *((u8 *)((u8 *)map + x + rowOff + 0x1420));
                s32 idx = (tileByte & 0x1f) - 15;
                s32 score = 0;

                switch (idx) {
                    case 0: score = 5; break;
                    case 2: score = 4; break;
                    case 9: score = 3; break;
                    case 3: score = 2; break;
                    case 4: score = 1; break;
                    case 7: score = 1; break;
                    default: score = 0; break;
                }

                if (score >= bestScore) {
                    bestScore = score;
                    bestX = x;
                    bestY = y;
                }
            }
        next:
        x++;
        }while(x<=highX);
    }

 done:
    if (bestX == -1) return 0;
    a3[0] = (s16)bestX;
    a3[1] = (s16)bestY;
    return 1;
}
#pragma opt_propagation on
s32 func_ov000_0217c2d4(u8 *arg0) {
s32 FloodFillUnitRange(s32,s32,s32,s32,s32); s32 func_ov000_021a9860(s32,s32); extern void **gCurrentMap;
s32 x,y; void *base;
FloodFillUnitRange(arg0[1],arg0[2],(u32)(arg0[0]<<26)>>26,0x6e,0);
base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if((((s8 **)((u8 *)base+0x52e8))[y])[x]>=0)
if(func_ov000_021a9860(x,y)==1)return 1;
base=*gCurrentMap;
}
}
return 0;
}

void func_ov000_0217c3a4(void) {
extern void **gCurrentMap;
s32 IsFootUnitKind();
void *p;
if(!IsFootUnitKind((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u8 *,0)<<26)>>26))return;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,8)=(M2C_FIELD(p,u16 *,8)&~0x3F)|0x3F;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,8)=(M2C_FIELD(p,u16 *,8)&~0xFC0)|0xFC0;
}

u8 func_ov000_0217c420(u8 *arg0,u8 *arg1) {
extern M2C_UNK data_ov000_021b5c11,data_ov000_021b5c12;
u32 kind=(u32)(*arg0<<26)>>26; u8 result;
switch((s32)kind) {
case 1:case 2:case 3:case 25:case 24:case 19:case 13:return 0;
default:
if(M2C_FIELD(&data_ov000_021b5c12,u8 *,kind*112)&M2C_FIELD(&data_ov000_021b5c11,u8 *,((u32)(*arg1<<26)>>26)*112)) result=1; else result=0;
return result;
}}

#pragma opt_propagation off
s32 func_ov000_0217c4c8(u8 *p){
s32 GetUnitMaxAttackRange(s32,u32);s32 IsUnitOnCurrentTeam(s32);
s32 count=0; s32 minX,minY,maxX,maxY; u8 *bounds; s32 dx,dy,x,dist,y;u8 *map;
minX=p[1]-GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26)<0?0:p[1]-GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26);
minY=p[2]-GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26)<0?0:p[2]-GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26);
bounds=(u8 *)*gCurrentMap+0x5120;
maxX=p[1]+GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26)>=M2C_FIELD(bounds,u16 *,36)-1?M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1:p[1]+GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26);
bounds=(u8 *)*gCurrentMap+0x5120;
maxY=p[2]+GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26)>=M2C_FIELD(bounds,u16 *,38)-1?M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1:p[2]+GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26);
for(y=minY;y<=maxY;y++)for(x=minX;x<=maxX;x++){
dx=p[1]-x;
if(dx<=0)dx=x-p[1];dist=0;dist+=dx;
dy=p[2]-y;if(dy<=0)dy=y-p[2];dist+=dy;
if(dist<(data_ov000_021b5bfc[((u32)(p[0]<<26)>>26)*112+12]<=2?2:data_ov000_021b5bfc[((u32)(p[0]<<26)>>26)*112+12]))continue;
if(dist>GetUnitMaxAttackRange(UnitOwnerC4c8(p),(u32)(p[0]<<26)>>26))continue;
map=*gCurrentMap;
{u16 row=M2C_FIELD(map+y*2,u16 *,0x3758);u8 id=map[x+row];if(!id)continue;if(!IsUnitOnCurrentTeam(id))continue;}
map=*gCurrentMap;
if(func_ov000_0217c420(map+0x59a4+map[x+M2C_FIELD(map+y*2,u16 *,0x3758)]*14,p))count++;
}
return count*3;
}
#pragma opt_propagation on
