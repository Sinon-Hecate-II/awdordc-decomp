/* 19 functions from 0x02216C94 to 0x02217C80 (ov007), found by ds-decomp. */
#include "common.h"

typedef struct MapPoint { s16 x, y; } MapPoint;
typedef struct MapScan { u8 pad0[0xa10]; u16 cells[0x16a4]; u16 rows[0xcf6]; u16 width, height; } MapScan;

/* Pick two well-separated interior locations for the two sides (first and second headquarters/spawn points). */
void func_ov007_02216c94(M2C_UNK *first, M2C_UNK *second) {
    s32 func_ov007_02214d88(s32 low, s32 high);
    s32 Map_PickRandomInteriorTile(s32 *x, s32 *y, s32 tileValue, void *avoidPoint);
    MapPoint func_ov007_022157fc(s32 x, s32 y, s32 side, s32 radius, s32 distance);
    MapPoint func_ov007_02215a0c(s32 side, s32 radius, s32 distance);

    s32 x, y;
    s32 radius = func_ov007_02214d88(2, 4);
    s32 distance = func_ov007_02214d88(1, 3);

    if (Map_PickRandomInteriorTile(&x, &y, 1, 0) == 1) {
        MapPoint placed = func_ov007_022157fc(x, y, 1, radius, distance);
        ((MapPoint *)first)->x = placed.x; ((MapPoint *)first)->y = placed.y;
    } else {
        MapPoint placed = func_ov007_02215a0c(1, radius, distance);
        ((MapPoint *)first)->x = placed.x; ((MapPoint *)first)->y = placed.y;
    }
    if (Map_PickRandomInteriorTile(&x, &y, 1, first) == 1) {
        MapPoint placed = func_ov007_022157fc(x, y, 2, radius, distance);
        ((MapPoint *)second)->x = placed.x; ((MapPoint *)second)->y = placed.y;
    } else {
        MapPoint placed = func_ov007_02215a0c(2, radius, distance);
        ((MapPoint *)second)->x = placed.x; ((MapPoint *)second)->y = placed.y;
    }
}

M2C_UNK func_ov007_02216e08(M2C_UNK *arg0, M2C_UNK *arg1, M2C_UNK *out_a, M2C_UNK *out_b, M2C_UNK *out_c) {
    s32 func_ov007_02214d88(s32, s32);
    s32 func_ov007_02215e94(s32 *, s32 *, s32, void *, s32);
    s32 func_ov007_02215f6c(s32 *, s32 *, s32, s16 *, s16 *, s32);
    M2C_UNK func_ov007_02215254(s32, s32, s32);

    s32 x = 0, y = 0;
    s32 count;
    s32 saved;
    s32 mode;

    for (mode = 0; mode < 5; mode++) {
        switch (mode) {
            case 0: count = func_ov007_02214d88(0, 5); break;
            case 1: count = func_ov007_02214d88(3, 5); break;
            case 2: count = func_ov007_02214d88(3, 7); break;
            case 3: count = func_ov007_02214d88(0, 5); break;
            case 4: count = func_ov007_02214d88(0, 3); break;
        }
        saved = 0;
        if (count <= 0) continue;
        while (saved < count) {
            switch (mode) {
            case 0:
                if (!func_ov007_02215e94(&x, &y, 1, arg0, 10)) goto done_inner;
                func_ov007_02215254(x, y, 0x1c7);
                if (!func_ov007_02215e94(&x, &y, 1, arg1, 10)) goto done_inner;
                func_ov007_02215254(x, y, 0x1cc);
                break;
            case 1:
                if (!func_ov007_02215e94(&x, &y, 1, arg0, 8)) goto done_inner;
                func_ov007_02215254(x, y, 0x1c2);
                ((s16 *)out_a)[0] = (s16)x; ((s16 *)out_a)[1] = (s16)y;
                if (!func_ov007_02215e94(&x, &y, 1, arg1, 8)) goto done_inner;
                func_ov007_02215254(x, y, 0x1c2);
                ((s16 *)out_b)[0] = (s16)x; ((s16 *)out_b)[1] = (s16)y;
                break;
            case 2:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 10)) goto done_inner;
                func_ov007_02215254(x, y, 0x1c2);
                ((s16 *)out_c)[0] = (s16)x; ((s16 *)out_c)[1] = (s16)y;
                break;
            case 3:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 5)) goto done_inner;
                func_ov007_02215254(x, y, 0x1b9);
                ((s16 *)out_c)[0] = (s16)x; ((s16 *)out_c)[1] = (s16)y;
                break;
            case 4:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 5)) goto done_inner;
                func_ov007_02215254(x, y, 0x1d9);
                break;
            }
            saved++;
        }
        done_inner:
        ;
    }
}

M2C_UNK func_ov007_02217110(M2C_UNK *arg0, M2C_UNK *arg1, M2C_UNK *arg2, M2C_UNK *arg3, M2C_UNK *arg4) {
    s32 func_ov007_02214e24(void);
    s32 func_ov007_02216234(s16, s16, s16, s16, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov007_022167b8(s16, s16, s16, s16, M2C_UNK);
    M2C_UNK func_ov007_0221b8c0(s32, s32);
    M2C_UNK func_ov007_02215704(s32, s32);
    M2C_UNK func_ov007_02215254(s32, s32, s32);
    extern void **gCurrentMap;
    extern s8 data_ov007_02221a84[];
    MapPoint sp18, sp14;
    s32 sp10;
    s8 *data;
    s32 x;
    s32 y;
    MapScan *map;

    func_ov007_02214e24();
    if (func_ov007_02216234(((MapPoint *)arg0)->x, ((MapPoint *)arg0)->y, ((MapPoint *)arg1)->x, ((MapPoint *)arg1)->y, 4, (M2C_UNK *)&sp18, (M2C_UNK *)&sp14, (M2C_UNK *)&sp10)) {
        func_ov007_022167b8(sp18.x, sp18.y, sp14.x, sp14.y, (M2C_UNK)sp10);
    }
    if (((MapPoint *)arg2)->x != 0xFF && ((MapPoint *)arg3)->x != 0xFF && ((MapPoint *)arg4)->x != 0xFF) {
        if (func_ov007_02216234(((MapPoint *)arg2)->x, ((MapPoint *)arg2)->y, ((MapPoint *)arg4)->x, ((MapPoint *)arg4)->y, 2, (M2C_UNK *)&sp18, (M2C_UNK *)&sp14, (M2C_UNK *)&sp10)) {
            func_ov007_022167b8(sp18.x, sp18.y, sp14.x, sp14.y, (M2C_UNK)sp10);
        }
        if (func_ov007_02216234(((MapPoint *)arg3)->x, ((MapPoint *)arg3)->y, ((MapPoint *)arg4)->x, ((MapPoint *)arg4)->y, 2, (M2C_UNK *)&sp18, (M2C_UNK *)&sp14, (M2C_UNK *)&sp10)) {
            func_ov007_022167b8(sp18.x, sp18.y, sp14.x, sp14.y, (M2C_UNK)sp10);
        }
    }

    map = (MapScan *)*gCurrentMap;
    if ((s32)map->height <= 0) return;
    data = data_ov007_02221a84;
    y = 0;
    do {
        map = (MapScan *)*gCurrentMap;
        x = y;
        if ((s32)map->width > 0) {
            do {
                if (data[x] == 2) {
                    if (func_ov007_0221b8c0(x, y) != 1) {
                        if (func_ov007_02215704(x, y) != 1) {
                            func_ov007_02215254(x, y, 6);
                        }
                    }
                }
                x += 1;
                map = (MapScan *)*gCurrentMap;
            } while (x < (s32)map->width);
        }
        y += 1;
        data += 0x1E;
        map = (MapScan *)*gCurrentMap;
    } while (y < (s32)map->height);

    return;
}

s32 func_ov007_02217318(void *arg0, void *arg1, s16 *arg2) {
    extern void **gCurrentMap;
    s32 func_ov007_022152bc(s32, s32);
    s32 RandomIntRange(s32, s32);
    MapPoint *pa, *pb;
    s32 cx, cy, count;
    s32 ax, bx, by, ly, d;
    s32 lx;
    s32 pick;
    s32 found;
    s32 ay;
    MapScan *map;

    pa = arg0;
    pb = arg1;
    found = 0;
    bx = pb->x;
    ax = pa->x;
    d = ax - bx;
    if (d < 0) d = -d;
    if ((u32) d < 5U) {
        if (ax < bx) { lx = bx - 10; ax += 10; }
        else { lx = ax - 10; ax = bx + 10; }
    } else {
        if (ax < bx) { lx = ax; ax += 10; }
        else { lx = ax - 10; }
    }
    by = pb->y, ay = pa->y;
    d = ay - by;
    if (d < 0) d = -d;
    if ((u32) d < 5U) {
        if (ay < by) { ly = by - 10; ay += 10; }
        else { ly = ay - 10; ay = by + 10; }
    } else {
        if (ay < by) { ly = ay; ay += 10; }
        else { ly = ay - 10; }
    }
    if (lx < 0) lx = 0;
    if (ly < 0) ly = 0;
    map = *gCurrentMap;
    if (ax >= (s32) map->width) ax = (s32) map->width - 1;
    if (ay >= (s32) map->height) ay = (s32) map->height - 1;
    count = 0;
    for (cy = ly; cy < ay; cy++) {
        for (cx = lx; cx < ax; cx++) {
            map = *gCurrentMap;
            if (map->cells[cx + map->rows[cy]] == 3) {
                if (func_ov007_022152bc(cx, cy) != -1) {
                    arg2[0] = cx;
                    found = 1;
                    arg2[1] = (s16) cy;
                    count++;
                }
            }
        }
    }
    if (count >= 2) {
        pick = RandomIntRange(0, count - 1);
        count = 0;
        for (cy = ly; cy <= ay; cy++) {
            for (cx = lx; cx <= ax; cx++) {
                map = *gCurrentMap;
                if (map->cells[cx + map->rows[cy]] == 3) {
                    if (func_ov007_022152bc(cx, cy) != -1) {
                        if (count < pick) {
                            count++;
                        } else {
                            arg2[0] = cx;
                            arg2[1] = cy;
                            break;
                        }
                    }
                }
            }
        }
    }
    return found;
}

M2C_UNK func_ov007_02217598(M2C_UNK *a,M2C_UNK *b){
 s32 func_ov007_02217318(void *,void *,s16 *);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s16 sp4[2],sp0[2];
 if(!func_ov007_02217318(a,b,sp4))return;
 if(!func_ov007_02217318(b,a,sp0))return;
 func_ov007_02215254(sp4[0],sp4[1],0x1c9);
 func_ov007_02215254(sp0[0],sp0[1],0x1ce);
}

M2C_UNK func_ov007_02217608(void) {
 s32 func_ov007_02214d88(s32,s32);
 s32 func_ov007_02215bc4(s32 *,s32 *,s32);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s32 sp4; s32 sp0; s32 i; s32 n;
 n=func_ov007_02214d88(20,40);
 for(i=0;i<n;i++){
 if(func_ov007_02215bc4(&sp4,&sp0,1)==0)return;
 func_ov007_02215254(sp4,sp0,33);
 }
}

M2C_UNK func_ov007_02217680(void) {
 s32 func_ov007_02214d88(s32,s32);
 s32 func_ov007_02215bc4(s32 *,s32 *,s32);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s32 sp4; s32 sp0; s32 i; s32 n;
 n=func_ov007_02214d88(5,20);
 for(i=0;i<n;i++){
 if(func_ov007_02215bc4(&sp4,&sp0,1)==0)return;
 func_ov007_02215254(sp4,sp0,385);
 }
}

M2C_UNK func_ov007_022176fc(void) {
 s32 func_ov007_02214d88(s32,s32);
 s32 func_ov007_02215bc4(s32 *,s32 *,s32);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s32 sp4; s32 sp0; s32 i; s32 n;
 n=func_ov007_02214d88(20,40);
 for(i=0;i<n;i++){
 if(func_ov007_02215bc4(&sp4,&sp0,1)==0)return;
 func_ov007_02215254(sp4,sp0,2);
 }
}

/* On every passable type-3 cell, randomly place tile 34 with a chance based on how many of its neighbors are open; then in a second pass place tile 34 on type-3 cells with exactly two open neighbors. */
void func_ov007_02217774(void) {
    extern void **gCurrentMap;
    s32 func_ov007_022152bc(s32 x, s32 y);
    s32 func_ov007_02215128(s32 count, s32 mode);
    M2C_UNK func_ov007_02215254(s32 x, s32 y, s32 value);
    s32 x, y, openNeighborCount;
    MapScan *map;
    map = *gCurrentMap;
    for (y = 0; y < (s32)map->height; y++) {
        for (x = 0; x < (s32)map->width; x++) {
            if (map->cells[x + map->rows[y]] == 3) {
                openNeighborCount = func_ov007_022152bc(x, y);
                if (openNeighborCount != -1 && func_ov007_02215128(openNeighborCount, 34))
                    func_ov007_02215254(x, y, 34);
            }
            map = *gCurrentMap;
        }
    }
    for (y = 0; y < (s32)map->height; y++) {
        for (x = 0; x < (s32)map->width; x++) {
            if (map->cells[x + map->rows[y]] == 3) {
                if (func_ov007_022152bc(x, y) == 2)
                    func_ov007_02215254(x, y, 34);
            }
            map = *gCurrentMap;
        }
    }
}

M2C_UNK func_ov007_022178f4(void) {
 s32 func_ov007_02214d88(s32,s32);
 s32 func_ov007_02215dd8(s32 *,s32 *,s32);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s32 sp4; s32 sp0; s32 i; s32 n;
 n=func_ov007_02214d88(5,10);
 for(i=0;i<n;i++){
 if(func_ov007_02215dd8(&sp4,&sp0,3)==0)return;
 func_ov007_02215254(sp4,sp0,360);
 }
}

M2C_UNK func_ov007_0221796c(void) {
 s32 func_ov007_02214d88(s32,s32);
 s32 func_ov007_02215dd8(s32 *,s32 *,s32);
 M2C_UNK func_ov007_02215254(s32,s32,s32);
 s32 sp4; s32 sp0; s32 i; s32 n;
 n=func_ov007_02214d88(5,10);
 for(i=0;i<n;i++){
 if(func_ov007_02215dd8(&sp4,&sp0,3)==0)return;
 func_ov007_02215254(sp4,sp0,39);
 }
}

M2C_UNK func_ov007_022179e4(void){s32 func_ov007_02214d88(s32,s32);s32 func_ov007_02215dd8(s32 *,s32 *,s32);M2C_UNK func_ov007_02215254(s32,s32,s32);s32 sp4,sp0,i,n;n=func_ov007_02214d88(8,15);for(i=0;i<n;i++){if(!func_ov007_02215dd8(&sp4,&sp0,3))return;func_ov007_02215254(sp4,sp0,7);}}

/* Fill every tile of the current map with type 1, then populate enemies, items and other map content. */
void func_ov007_02217a5c(void) {
    M2C_UNK func_0207c240();
    M2C_UNK func_ov007_02215254(s32, s32, M2C_UNK);
    M2C_UNK func_ov007_02216a74();
    M2C_UNK func_ov007_02216bf4();
    M2C_UNK func_ov007_02216e08(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov007_02217110(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov007_02217598(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov007_02217608(void);
    M2C_UNK func_ov007_02217680();
    M2C_UNK func_ov007_022176fc(void);
    M2C_UNK func_ov007_022178f4(void);
    M2C_UNK func_ov007_0221796c();
    M2C_UNK func_ov007_022179e4();
    extern void **gCurrentMap;
    M2C_UNK sp14;
    M2C_UNK sp10;
    M2C_UNK spC;
    M2C_UNK sp8;
    M2C_UNK sp4;
    s32 x;
    s32 y;
    void *map;

    func_0207c240();
    y = 0;
    map = *gCurrentMap;
    if ((s32) M2C_FIELD(map, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32) M2C_FIELD(map, u16 *, 0x5144) > 0) {
                do {
                    func_ov007_02215254(x, y, 1);
                    x += 1;
                    map = *gCurrentMap;
                } while (x < (s32) M2C_FIELD(map, u16 *, 0x5144));
            }
            y += 1;
        } while (y < (s32) M2C_FIELD(map, u16 *, 0x5146));
    }
    func_ov007_02216a74();
    func_ov007_02216bf4();
    func_ov007_02216c94(&sp14, &sp10);
    func_ov007_02216e08(&sp14, &sp10, &spC, &sp8, &sp4);
    func_ov007_02217110(&sp14, &sp10, &spC, &sp8, &sp4);
    func_ov007_02217598(&sp14, &sp10);
    func_ov007_02217608();
    func_ov007_02217680();
    func_ov007_022176fc();
    func_ov007_02217774();
    func_ov007_022178f4();
    func_ov007_0221796c();
    func_ov007_022179e4();
}

s8 *func_ov007_02217b64(s32 arg0) {
 extern s8 *data_ov007_0221f500[2];
 s8 *arr[2];
 arr[0]=data_ov007_0221f500[0];arr[1]=data_ov007_0221f500[1];
 return arr[arg0];
}

s32 func_ov007_02217b90(s32 a,s32 b){s8 *p=func_ov007_02217b64(a);s32 i=0;while(*p>=0){if(*p==b)return i;p+=5;i++;}return -1;}

s32 func_ov007_02217bd0(s32 a,s32 b){
 s8 *func_ov007_02217b64(s32);
 return func_ov007_02217b64(a)[b*5];
}

u8 func_ov007_02217be8(s32 a,s32 b,s32 c){extern u8 data_ov007_0221fdf0;u8 *p=(u8 *)func_ov007_02217b64(a)+b*5;if(p[4]==1)return (&data_ov007_0221fdf0)[c];return 0;}

s32 func_ov007_02217c1c(s32 arg0) {
    extern u8 data_ov007_0221fdf0;
    s32 var_r2;
    u8 *var_r3;

    var_r3 = &data_ov007_0221fdf0;
    var_r2 = 0;
loop_1:
    if (*var_r3 == arg0) {
        return var_r2;
    }
    var_r2 += 1;
    var_r3 += 1;
    if (var_r2 >= 5) {
        return -1;
    }
    goto loop_1;
}

s32 func_ov007_02217c50(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x37);
    switch (temp_r0) {                              /* irregular */
    case 0:
        return 5;
    case 1:
        return 4;
    default:
        return 0;
    }
}
