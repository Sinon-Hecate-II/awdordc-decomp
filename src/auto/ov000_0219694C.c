/* 9 functions from 0x0219694C to 0x02197814 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct MapScan96 { u8 pad[0x24]; u16 width, height; } MapScan96;
typedef struct KindScan96 { u8 pad[12]; u8 minRange; u8 rest[99]; } KindScan96;
typedef struct UnitScan96 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 health:7; u16 status:4; u16 rest:5; } UnitScan96;

typedef struct Map972e0 { u8 pad[0x5144]; volatile u16 width; u16 height; } Map972e0;

#pragma opt_strength_reduction off
#pragma opt_strength_reduction off
u32 func_ov000_0219694c(s32 xOrig, s32 yOrig) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021dfcf0[];
    s32 func_020ce0ec(s32);

    u32 result;
    s32 hasFlag;
    void *base;
    u16 width, height;
    s32 xMin, xMax, yMin, yMax;
    s32 row, col;
    s32 dx, dy, dist;
    u16 rowOffset;
    u16 vIndex;
    s8 *rowPtr;
    s8 terrainVal;
    u8 prop;
    s32 funcRes;
    u16 linear;
    u16 rowOffsetOrig;
    u32 finalIdx;
    s8 *rowPtr0;
    s8 terrain0;

    result = 0;
    hasFlag = 0;

    base = *gCurrentMap;
    width = M2C_FIELD(base, u16 *, 0x5144);
    height = M2C_FIELD(base, u16 *, 0x5146);

    xMin = xOrig - 2;
    if (xMin < 0) xMin = 0;
    xMax = xOrig + 2;
    if (xMax > width - 1) xMax = width - 1;
    yMin = yOrig - 2;
    if (yMin < 0) yMin = 0;
    yMax = yOrig + 2;
    if (yMax > height - 1) yMax = height - 1;

    for (row = yMin; row <= yMax; row++) {
        for (col = xMin; col <= xMax; col++) {
            dx = xOrig - col;
            if (dx < 0) dx = -dx;
            dy = yOrig - row;
            if (dy < 0) dy = -dy;
            dist = dx + dy;
            if (dist > 2) continue;

            rowOffset = M2C_FIELD((u8 *)*gCurrentMap + row * 2, u16 *, 0x3758);
            vIndex = rowOffset + col;
            base = *gCurrentMap;
            if (M2C_FIELD(base, u8 *, (vIndex >> 3) + 0x5160) & (1 << (vIndex & 7))) continue;

            rowPtr = M2C_FIELD(base + row * 4, s8 **, 0x52e8);
            terrainVal = rowPtr[col];
            prop = M2C_FIELD((u8 *)base + col + rowOffset, u8 *, 0x1420);

            if (terrainVal != 0) {
                if (prop & 0xe0) hasFlag = 1;
                funcRes = func_020ce0ec((s32)(M2C_FIELD(base, u16 *, 0x52a4) & 0xff));
                if (funcRes != 0) result += 0x1000000; else result += 0x100000;
                linear = (u16)(row * width + col);
                if (data_ov000_021dfcf0[linear >> 3] & (1 << (linear & 7))) result += 0x10000;
            } else {
                if (prop & 0xe0) result += 0x100; else result += 0x10;
                linear = (u16)(row * width + col);
                if (data_ov000_021dfcf0[linear >> 3] & (1 << (linear & 7))) result += 1;
            }
        }
    }

    base = *gCurrentMap;
    if (!hasFlag) return 0;

    rowOffsetOrig = M2C_FIELD((u8 *)base + yOrig * 2, u16 *, 0x3758);
    finalIdx = xOrig + rowOffsetOrig;
    result <<= 2;
    if (!(M2C_FIELD(base, u8 *, (finalIdx >> 3) + 0x5160) & (1 << (finalIdx & 7)))) {
        funcRes = func_020ce0ec((s32)(M2C_FIELD(base, u16 *, 0x52a4) & 0xff));
        if (funcRes == 0) {
            result += 1;
        } else {
            rowPtr0 = M2C_FIELD((u8 *)base + yOrig * 4, s8 **, 0x52e8);
            terrain0 = rowPtr0[xOrig];
            if (terrain0 != 0) result += 3; else result += 2;
        }
    }
    return result;
}
#pragma opt_strength_reduction reset

void func_ov000_02196bd8(void) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern KindScan96 data_ov000_021b5bfc[];
extern u8 *data_ov000_021df580;
s32 func_ov000_02178e84(s32,s32);
void func_01ffb3d0(s32);
s32 func_ov000_021a98e4(u32);
s32 func_ov000_021a97d0(s32,s32);
s32 func_020a76d4(void *);
u32 func_ov000_0219694c(s32,s32);
void func_ov000_02199d74(s32,s32,s32,s32,s32);
u8 *m,*u; MapScan96 *bounds; s32 bx,by,i,off,l,b,l2,b2,l3,x,y,t,r,d,z; u32 best,v;
m=*gCurrentMap; u=M2C_FIELD(m,u8 **,0x52d0);
if(!((UnitScan96 *)u)->status)return;
if(!func_ov000_02178e84(u[1],u[2]))return;
func_01ffb3d0(0);
i=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;
if(i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51){off=i*14;do{
u=(u8 *)*gCurrentMap+0x59a4+off;
if(!((u32)(u[0]<<26)>>26)||((UnitScan96 *)u)->health<=70||!((UnitScan96 *)u)->status||(M2C_FIELD(u,u16 *,4)&8)||func_ov000_021a98e4((u32)(u[0]<<26)>>26)!=1)goto nextUnit;
if(func_ov000_021a97d0((u32)(u[0]<<26)>>26,7)){
l=u[1]-func_020a76d4(u)<0?0:u[1]-func_020a76d4(u);
t=u[2]-func_020a76d4(u)<0?0:u[2]-func_020a76d4(u);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+0x5120);r=u[1]+func_020a76d4(u)>=bounds->width-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,0x5144)-1:u[1]+func_020a76d4(u);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+0x5120);b=u[2]+func_020a76d4(u)>=bounds->height-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,0x5146)-1:u[2]+func_020a76d4(u);
z=0;for(y=t;y<=b;y++)for(x=l;x<=r;x++){
d=0; if(u[1]-x>0)d+=u[1]-x;else d+=x-u[1]; if(u[2]-y>0)d+=u[2]-y;else d+=y-u[2];
if(d<data_ov000_021b5bfc[(u32)(u[0]<<26)>>26].minRange||d>func_020a76d4(u))continue;
m=*gCurrentMap; v=M2C_FIELD((u32)m+(y<<1),u16 *,0x3758)+x;
if((u8)(m[0x5160+(v>>3)]&(1<<(v&7))))continue;

M2C_FIELD((u32)m+(y<<2),u8 **,0x52e8)[x]=1;
}}if(func_ov000_021a97d0((u32)(u[0]<<26)>>26,14)){
l2=u[1]-func_020a76d4(u)<0?0:u[1]-func_020a76d4(u);
t=u[2]-func_020a76d4(u)<0?0:u[2]-func_020a76d4(u);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+0x5120);r=u[1]+func_020a76d4(u)>=bounds->width-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,0x5144)-1:u[1]+func_020a76d4(u);
bounds=(MapScan96 *)((u8 *)*gCurrentMap+0x5120);b2=u[2]+func_020a76d4(u)>=bounds->height-1?M2C_FIELD(*(u8 * volatile *)gCurrentMap,u16 *,0x5146)-1:u[2]+func_020a76d4(u);
z=0;for(y=t;y<=b2;y++)for(x=l2;x<=r;x++){
d=0; if(u[1]-x>0)d+=u[1]-x;else d+=x-u[1]; if(u[2]-y>0)d+=u[2]-y;else d+=y-u[2];
if(d<data_ov000_021b5bfc[(u32)(u[0]<<26)>>26].minRange||d>func_020a76d4(u))continue;
m=*gCurrentMap; v=M2C_FIELD((u32)m+(y<<1),u16 *,0x3758)+x;
if((u8)(m[0x5160+(v>>3)]&(1<<(v&7))))continue;
if((M2C_FIELD((u32)m+x+M2C_FIELD((u32)m+(y<<1),u16 *,0x3758),u8 *,0x1420)&31)!=18||!(M2C_FIELD((u32)m+x+M2C_FIELD((u32)m+(y<<1),u16 *,0x3758),u8 *,0x1420)&224))continue;
M2C_FIELD((u32)m+(y<<2),u8 **,0x52e8)[x]=1;
}}nextUnit: i++;off+=14;}while(i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51);}
{ s32 l3,t3,b3; u32 best3; s32 x3,y3,r3,d3; u8 *u3;
m=*gCurrentMap; u3=M2C_FIELD(m,u8 **,0x52d0);
best3=0;l3=u3[1]-5<0?0:u3[1]-5;t3=u3[2]-5;if(t3<0)t3=0;r3=M2C_FIELD(m,u16 *,0x5144)-1;if(u3[1]+5<r3)r3=u3[1]+5;b3=M2C_FIELD(m,u16 *,0x5146)-1;if(u3[2]+5<b3)b3=u3[2]+5;
z=0;for(y3=t3;y3<=b3;y3++)for(x3=l3;x3<=r3;x3++){u3=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);d3=0; if(u3[1]-x3>0)d3+=u3[1]-x3;else d3+=x3-u3[1]; if(u3[2]-y3>0)d3+=u3[2]-y3;else d3+=y3-u3[2];if(d3<0||d3>5)continue;v=func_ov000_0219694c(x3,y3);if(!v||best3>v)continue;if(best3==v&&data_ov000_021df580[3]<50)continue;best3=v;bx=x3;by=y3;}
if(!best3)return;u3=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);func_ov000_02199d74(u3[1],u3[2],21,(u8)bx,(u8)by);
}}
#pragma opt_strength_reduction reset
void func_ov000_021972e0(void) {
extern void **gCurrentMap;
void func_01ffada0(s32,s32,s32,s32,s32);
void func_ov000_0218a9ac(s32,s32);
Map972e0 *base; u8 *unit; s32 x, y, bestX, bestY, best;
base=*gCurrentMap;
unit=M2C_FIELD(base,u8 **,0x52d0);
func_01ffada0(unit[1],unit[2],(u32)(unit[0]<<26)>>26,110,0);
base=*gCurrentMap;
if (M2C_FIELD(M2C_FIELD(base,void **,0x52f8),s8 *,0)>=0) {func_ov000_0218a9ac(0,4); return;}
bestX=-1; best=32767;
for(x=0;x<base->width;x++){
for(y=0;y<base->height;y++){
s32 v=*(s8 *)((u32)x+(u32)M2C_FIELD((void *)((u32)base+(u32)y*4),s8 **,0x52e8));
if(v>=0 && v<=best){best=v;bestX=x;bestY=y;}
}
if(bestX!=-1)break;
}
if(bestX==-1)return;
func_ov000_0218a9ac(bestX,bestY);
}

u8 func_ov000_021973f8(void) {
    extern void **gCurrentMap;
    void *temp_r3;
    u32 index;
    u8 result;
    temp_r3 = *gCurrentMap;
    index = M2C_FIELD(temp_r3, u16 *, 0x52A4);
    result = M2C_FIELD((s32)temp_r3 + index * 0x8C, u8 *, 0x67CE) != 0;
    return result;
}

s32 func_ov000_02197434(s32 arg0, s32 arg1) {
    s32 func_ov000_021a97d0();
    s32 var_r0;

    var_r0 = func_ov000_021a97d0();
    if ((arg1 == 0xE) && (arg0 == 0xE)) {
        var_r0 = (s32) (var_r0 * 3) >> 1;
    }
    if ((arg1 == 0xE) && (arg0 == 6)) {
        var_r0 *= 2;
    }
    if ((arg1 == 6) && (arg0 == 0xF)) {
        var_r0 = var_r0 >> 1;
    }
    return var_r0;
}

s32 func_ov000_02197470(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0207c8ec(s32, s32);
    s32 func_020a8774(M2C_UNK);
    s32 func_020a87b0(M2C_UNK);
    s32 temp_r1;
    s32 temp_r4;
    s32 var_r6;

    var_r6 = arg0;
    temp_r4 = func_020a8774(arg2);
    temp_r1 = func_020a87b0(arg1);
    if ((temp_r4 == 0) && (temp_r1 == 0)) {

    } else {
        var_r6 = func_0207c8ec(var_r6 * (temp_r4 + 0x64), temp_r1 + 0x64);
    }
    return var_r6;
}

/* Scales a base value by percentage modifiers derived from up to two optional unit pointers; returns the base unchanged when neither modifier applies. */
s32 func_ov000_021974bc(s32 base, void *firstUnit, void *secondUnit) {
    s32 func_020a2868(u32, s32, s32);
    s32 func_020a28f4(u32, s32, s32);
    s32 func_020a334c(u16);
    s32 func_020a7cfc(void *);
    s32 func_0207c8ec(s32, s32);
    extern void **gCurrentMap;
    s32 n, idx, a, b;
    if (secondUnit && func_020a7cfc(secondUnit)) {
        if (secondUnit) { if (!secondUnit) n = 0; else n = (s32)((u8 *)secondUnit - ((u8 *)*gCurrentMap + 0x59a4)) / 14; idx = (n >> 6) + 1; } else idx = 0;
        a = func_020a2868((u32)(M2C_FIELD(secondUnit, u8 *, 0) << 26) >> 26, idx, 0);
    } else a = 0;
    if (firstUnit && (func_020a7cfc(firstUnit) || func_020a334c(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)))) {
        if (firstUnit) { if (!firstUnit) n = 0; else n = (s32)((u8 *)firstUnit - ((u8 *)*gCurrentMap + 0x59a4)) / 14; idx = (n >> 6) + 1; } else idx = 0;
        b = func_020a28f4((u32)(M2C_FIELD(firstUnit, u8 *, 0) << 26) >> 26, idx, func_020a334c(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)));
    } else b = 0;
    if (a == 0 && b == 0) { } else base = func_0207c8ec(base * (a + 100), b + 100);
    return base;
}

s32 func_ov000_0219763c(s32 arg0, void *arg1, s32 arg2) {
    s32 func_020a7558(void *);
    s32 func_ov000_021a9214(void *, u8, u8);
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 var_r0;
    s32 var_r4;

    var_r4 = arg2;
    if (func_ov000_021a93a8(arg1, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2)) == 1) {
        var_r4 += 0x14;
    }
    if (func_ov000_021a9214(arg1, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2)) == 1) {
        var_r4 += func_020a7558(arg1) * 0xA;
    }
    if (var_r4 >= 0x64) {
        var_r4 = 0x64;
    }
    var_r0 = func_0207c8ec(arg0 * var_r4, 0x64);
    if (var_r0 >= 0xFF) {
        var_r0 = 0xFF;
    }
    return var_r0;
}

/* Returns the terrain damage rating for tile (x, y); for most unit kinds it blends the unit's stats through func_ov000_021974bc and clamps to the existing tile rating. */
s32 func_ov000_021976ac(s32 x, s32 y, void *unit, u32 hp) {
    s32 func_ov000_021974bc(s32, void *, void *);
    s32 func_ov000_02197434(s32, s32);
    s32 func_ov000_02197470(s32, M2C_UNK, M2C_UNK);
    s32 func_ov000_0219763c(s32, void *, s32);
    s32 func_ov000_021a98e4(u32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021e0a58[];
    void *base;
    s32 v, result, old;
    if (func_ov000_021a98e4((u32)(M2C_FIELD(unit, u8 *, 0) << 26) >> 26)) {
        base = *gCurrentMap;
        return M2C_FIELD((u8 *)base + (x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)), u8 *, 0x2840);
    }
    v = func_ov000_02197434((u32)(M2C_FIELD(unit, u8 *, 0) << 26) >> 26, (u32)(*M2C_FIELD(*gCurrentMap, u8 **, 0x52d0) << 26) >> 26);
    v = func_ov000_02197470(v, (u32)(*M2C_FIELD(*gCurrentMap, u8 **, 0x52d0) << 24) >> 30, (u32)(M2C_FIELD(unit, u8 *, 0) << 24) >> 30);
    v = func_ov000_021974bc(v, M2C_FIELD(*gCurrentMap, void **, 0x52d0), unit);
    result = func_ov000_0219763c(v, unit, (u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25);
    base = *gCurrentMap;
    old = M2C_FIELD((u8 *)base + (x + M2C_FIELD((u8 *)base + y * 2, u16 *, 0x3758)), u8 *, 0x2840);
    if (result == old) {
        result = func_ov000_0219763c(v, unit, hp);
        old = data_ov000_021e0a58[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
        if (result <= old) result = old;
        return result;
    }
    return old;
}

