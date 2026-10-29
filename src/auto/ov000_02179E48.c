/* 10 functions from 0x02179E48 to 0x0217ACD4 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_02179e48(void *arg0) {
    (void)arg0;
    return 0;
}

s32 func_ov000_0217a0a8(void *arg0) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5bfc[];
    s32 func_ov000_021a98e4(s32);
    s32 func_ov000_021a8fc0(s32);
    s32 func_ov000_021a96a8(s32, s32, s32);
    u8 *p;
    void *map;
    void *mapData;
    u8 *sel;
    u8 attr;
    u8 id;
    s32 unitKind;
    s16 fieldE6;
    s16 fieldF2;
    s32 baseX;
    s32 baseY;
    s32 minX;
    s32 minY;
    s32 maxX;
    s32 maxY;
    s32 x;
    s32 y;
    s32 d;
    u16 rowOffset;
    u8 *unitSpec;
    u8 candKind;
    u8 attrs2;
    u16 field4;
    u16 field6;
    s32 selX;
    s32 selY;
    s32 selKind;
    u8 p0kind;
    s32 firstRes;
    s32 secondRes;
    u16 selField6;
    u16 candField6;
    p = (u8 *)arg0;
    map = *gCurrentMap;
    sel = *(u8 **)((u8 *)map + 0x52D0);
    unitKind = (s32)(((u32)(sel[0] << 26)) >> 26);
    attr = data_ov000_021b5bfc[unitKind * 0x70];
    if (!(attr & 0x27)) return 0;
    if (func_ov000_021a98e4(unitKind) != 0) return 0;
    map = *gCurrentMap;
    mapData = *(void **)map;
    fieldE6 = *(s16 *)((u8 *)mapData + 0x6EE6);
    if (fieldE6 == 0) return 0;
    fieldF2 = *(s16 *)((u8 *)mapData + 0x6EF2);
    if (fieldF2 >= 0x1E) return 0;
    baseX = p[1];
    baseY = p[2];
    minX = baseX - 4;
    if (minX < 0) minX = 0;
    minY = baseY - 4;
    if (minY < 0) minY = 0;
    maxX = baseX + 4;
    maxY = baseY + 4;
    if (maxX > ((s32)*(u16 *)((u8 *)mapData + 0x5144) - 1)) maxX = (s32)*(u16 *)((u8 *)mapData + 0x5144) - 1;
    if (maxY > ((s32)*(u16 *)((u8 *)mapData + 0x5146) - 1)) maxY = (s32)*(u16 *)((u8 *)mapData + 0x5146) - 1;
    for (y = minY; y <= maxY; y++) {
        for (x = minX; x <= maxX; x++) {
            d = baseX - x;
            if (d < 0) d = -d;
            d += (baseY > y ? baseY - y : y - baseY);
            if (d > 4) continue;
            rowOffset = *(u16 *)((u8 *)mapData + 0x3758 + y * 2);
            id = *((u8 *)mapData + x + rowOffset);
            if (id == 0) continue;
            if (func_ov000_021a8fc0((s32)id) == 0) continue;
            sel = *(u8 **)((u8 *)mapData + 0x52D0);
            selX = sel[1];
            selY = sel[2];
            if (x == selX && y == selY) continue;
            unitSpec = (u8 *)mapData + 0x59A4 + (s32)id * 14;
            candKind = unitSpec[0] & 0x3F;
            if (func_ov000_021a98e4((s32)candKind) == 1) continue;
            if (candKind == 0) continue;
            attrs2 = data_ov000_021b5bfc[(s32)candKind * 0x70 + 0x13];
            if (attrs2 & 0x10) continue;
            field4 = *(u16 *)(unitSpec + 4);
            if (field4 & 0x01) continue;
            field6 = *(u16 *)(unitSpec + 6);
            if ((field6 >> 11) != 0) continue;
            selKind = sel[0] & 0x3F;
            p0kind = p[0] & 0x3F;
            firstRes = func_ov000_021a96a8(selKind, (s32)p0kind, 0);
            secondRes = func_ov000_021a96a8((s32)candKind, (s32)p0kind, 0);
            candField6 = field6 & 0x1FFF;
            selField6 = *(u16 *)(((u8 *)mapData + 0x59A4 + (s32)(sel[0] & 0x3F) * 14) + 6) & 0x1FFF;
            if (selField6 * firstRes + 0x7D0 < candField6 * secondRes) return 1;
        }
    }
    return 0;
}

M2C_UNK func_ov000_0217a378(M2C_UNK a) {
    return 0;
}

void func_ov000_0217a59c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_01ffb554(void *);
    void func_01ffb3d0(s32);
    u16 func_ov000_021a97e0(u16, s32);
    void func_01ffb454(s32);
    s32 func_ov000_0217a378(s32);

    extern void **gCurrentMap;
    extern u8 data_027e0a8c;
    extern void *data_027e00cc;
    extern void *data_027e0a94;
    extern void *data_027e0a98;
    extern void *data_027e0a90;

    void *map;
    void *mapData;
    void *base;
    u8 *p;
    u8 *q;
    s8 flag;

    map = *gCurrentMap;
    mapData = *(void **)map;
    func_01ffb554((u8 *)mapData + 0x2338);
    func_01ffb3d0(-1);

    map = *gCurrentMap;
    mapData = *(void **)map;
    func_01ffb554((u8 *)mapData + 0x1E30);
    func_01ffb3d0(-1);

    data_027e0a8c = 0;
    base = data_027e00cc;
    data_027e0a94 = (void *)0;
    data_027e0a98 = (u8 *)base + 0x28;
    data_027e0a90 = (u8 *)base + 0x5A0;

    *(u16 *)((u8 *)base + 0x20) = (u16)arg3;

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u16 v = *(u16 *)((u8 *)mapData + 0x52A4);
        u16 r = func_ov000_021a97e0(v, arg2);
        base = data_027e00cc;
        *(u16 *)((u8 *)base + 0x22) = r;
    }
    func_01ffb454(arg2);

    p = data_027e0a98;
    p[0] = (u8)arg0;
    p[1] = (u8)arg1;
    p[2] = 1;
    p[3] = 0;

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u8 **arr = (u8 **)((u8 *)mapData + 0x52E8);
        u8 *ptr = arr[arg1];
        ptr[arg0] = 0;
    }

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u16 rowOff = *(u16 *)((u8 *)mapData + 0x3758 + arg1 * 2);
        u8 *cell = (u8 *)mapData + arg0 + rowOff;
        cell[0x2338] = 0;
    }

    p = data_027e0a98;
    p += 4;
    data_027e0a98 = p;
    p[2] = 0;

    flag = data_027e0a8c;
    base = data_027e00cc;
    if (flag == 0) {
        data_027e0a98 = (u8 *)base + 0x5A0;
        data_027e0a90 = (u8 *)base + 0x28;
        data_027e0a8c = 1;
    } else {
        data_027e0a98 = (u8 *)base + 0x28;
        data_027e0a90 = (u8 *)base + 0x5A0;
        data_027e0a8c = 0;
        data_027e0a94 = (void *)0;
    }

    while (1) {
        u8 t;
        u8 *p2;
        u8 *p3;
        u8 nt;
        u8 subcase;
        q = data_027e0a90;
        t = q[2];
        if (t == 0) {
            break;
        }
        switch (t) {
        case 1:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 2:
            func_ov000_0217a378(2);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 3:
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 4:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            break;
        case 5:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(5);
            break;
        default:
            break;
        }
        p2 = data_027e0a98;
        p2[2] = 0;
        p3 = data_027e0a90;
        p3 += 4;
        data_027e0a90 = p3;
        nt = p3[2];
        if (nt != 0) {
            continue;
        }
        break;
    }

    p = data_027e0a90;
    map = *gCurrentMap;
    mapData = *(void **)map;
    p[0x24] = (u8)*(u16 *)((u8 *)mapData + 0x5144);
    base = data_027e00cc;
    map = *gCurrentMap;
    mapData = *(void **)map;
    ((u8 *)base)[0x25] = (u8)*(u16 *)((u8 *)mapData + 0x5146);
}

u8 func_ov000_0217a8a0(s32 x, s32 y, s32 arg2) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern s32 func_0207c8ec(s32, s32);
    extern s32 func_020a86f0(s32);
    extern s32 func_020a86bc(s32, s32);
    void *base;
    u8 *sel;
    u8 attr;
    s8 *row;
    s8 cell;
    s32 kind;
    s32 t;
    s32 w;
    s32 A, B;
    s8 cell2;
    u8 unitByte;
    s32 lhs, rhs;

    base = *gCurrentMap;
    sel = *(u8 **)(base + 0x52D0);
    kind = (s32)(((u32)(sel[0] << 26)) >> 26);
    attr = data_ov000_021b5c0f[kind * 0x70];
    if (!(attr & 0x30)) return 1;
    row = ((s8 **)(base + 0x52E8))[y];
    cell = row[x];
    if (cell == 0) return 1;
    t = func_0207c8ec(cell - 1, arg2);

    base = *gCurrentMap;
    sel = *(u8 **)(base + 0x52D0);
    kind = (s32)(((u32)(sel[0] << 26)) >> 26);
    attr = data_ov000_021b5c0f[kind * 0x70];

    if (attr & 0x10) {
        w = *(u16 *)(base + 0x52A4);
        A = func_020a86f0(w);
        B = func_020a86bc(w, kind);
        B = B + 1;
        row = ((s8 **)(base + 0x52E8))[y];
        cell2 = row[x];
        unitByte = sel[0x0A];
        lhs = (s32)((((u32)(unitByte << 25)) >> 25) - (cell2 * A));
        rhs = t * B;
        if (lhs < rhs) return 0;
        return 1;
    } else if (kind == 0x16) {
        w = *(u16 *)(base + 0x52A4);
        A = func_020a86f0(w);
        B = func_020a86bc(w, kind);
        B = B + 5;
        row = ((s8 **)(base + 0x52E8))[y];
        cell2 = row[x];
        unitByte = sel[0x0A];
        lhs = (s32)((((u32)(unitByte << 25)) >> 25) - (cell2 * A));
        rhs = t * B;
        if (lhs < rhs) return 0;
        return 1;
    } else {
        return 0;
    }
}

s32 func_ov000_0217aa2c(s32 x,s32 y) {
extern void **data_027e0058;
void **state=data_027e0058;
void *base=*state;
register s32 left,top,right,bottom; s32 i,result,d,v;
left=x-1;
if(left<0)left=0;
top=y-1;
if(top<0)top=0;
right=M2C_FIELD(base,u16 *,0x5144)-1;
right=right>x+1?x+1:right;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
bottom=bottom>y+1?y+1:bottom;
result=111;
for(;top<=bottom;top++){
for(i=left;i<=right;i++){
d=0;
if(x-i>0)d+=x-i;else d+=i-x;
if(y-top>0)d+=y-top;else d+=top-y;
if(d<1)continue;
if(d>1)continue;
v=M2C_FIELD(((s8 **)((u8 *)*state+0x52e8))[top],s8 *,i);
if(v<0)continue;
if(v<result)result=v;
}}
return result;
}

u8 func_ov000_0217ab10(s32 arg0, s32 arg1, s32 arg2) {
 extern void **gCurrentMap;
 s32 func_020d27c0(s32);
 void *base = *gCurrentMap;
 u8 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 0;
 return func_020d27c0(id) != 1;
}

u8 func_ov000_0217ab5c(s32 arg0, s32 arg1, s32 arg2) {
 extern void **gCurrentMap;
 s32 func_ov000_021a97d0(s32, s32);
 void *base;
 u8 id;
 if (func_ov000_0217ab10(arg0,arg1,0) == 0) return 0;
 base = *gCurrentMap;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 return func_ov000_021a97d0(arg2, ((u32)(M2C_FIELD(base + id * 14, u8 *, 0x59A4) << 26) >> 26)) > 1;
}

u8 func_ov000_0217abd8(s32 arg0, s32 arg1) {
 extern void **gCurrentMap;
 s32 func_ov000_021a9860(s32,s32);
 s32 func_ov000_021a8fc0(s32);
 s32 func_ov000_021a98a8(s32);
 void *base;
 s32 id;
 if (func_ov000_021a9860(arg0,arg1) == 0) return 0;
 base = *gCurrentMap;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 1;
 if (func_ov000_021a8fc0((s16)id) == 0) return 0;
 return func_ov000_021a98a8(((u32)(M2C_FIELD(*gCurrentMap + id * 14, u8 *, 0x59A4) << 26) >> 26)) == 0;
}

u8 func_ov000_0217ac78(s32 arg0, s32 arg1) {
    extern void **gCurrentMap;
    u8 temp_r2;
    u8 var_r0;
    void *temp_r3;

    temp_r3 = *gCurrentMap;
    temp_r2 = M2C_FIELD((temp_r3 + (arg0 + M2C_FIELD((temp_r3 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420);
    if ((temp_r2 & 0x1F) != 0x11) {
        return 0U;
    }
    if (M2C_FIELD(temp_r3, u16 *, 0x52A6) == (temp_r2 & 0xE0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
