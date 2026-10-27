/* 9 functions from 0x0219694C to 0x02197814 (ov000), found by ds-decomp. */
#include "common.h"

typedef struct Map972e0 { u8 pad[0x5144]; volatile u16 width; u16 height; } Map972e0;

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

