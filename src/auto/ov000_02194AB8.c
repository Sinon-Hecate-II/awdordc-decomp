/* 7 functions from 0x02194AB8 to 0x021959CC (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind1955;

void func_ov000_021954a4(void) {
    s32 func_ov000_02194ab8(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02194ab8(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_021954dc(s16 *arg0) {
    void func_ov000_02179be0();
    void func_ov000_02179d3c();
    s32 func_ov000_021786a8(s16 *);
    s32 func_ov000_02179e48(s16 *);
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();
    if (func_ov000_021786a8(sp0) == 0) {
        return 0;
    }
    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219553c(void) {
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_021954dc(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02195574(s16 *out) {
s32 func_ov000_021a98e4(s32);
void func_ov000_02179be0(void);
void func_ov000_02179d3c(void);
s32 func_020ba924(s32,s32);
s32 func_ov000_0217bc34(s32,s32,s32,s32);
s32 func_ov000_02179e48(s16 *);
extern void **gCurrentMap;
extern void *data_ov000_021df57c;
s32 best=0x7fff;
s16 cand[2];
s32 x,y,kind;
kind=func_ov000_021a98e4((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind)==1?2:1;
func_ov000_02179be0();
func_ov000_02179d3c();
for(y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++){
for(x=0;x<*(u16 *)((u8 *)*gCurrentMap+0x5144);x++){
u8 *map;
s32 cell;
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x]<0)continue;
if(!func_020ba924(x,y))continue;
map=(u8 *)*gCurrentMap;
cell=*(s8 *)(*(u16 *)(map+0x3758+y*2)+(map+x)+0x1928);
map += cell*6;
if((map+kind)[0x6c63]>=((u8 *)data_ov000_021df57c)[13])continue;
if(best<(*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x])continue;
if(!func_ov000_0217bc34(x,y,2,5))continue;
cand[0]=x;cand[1]=y;
best=(*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x];
}}
if(best==0x7fff)return 0;
if(!func_ov000_02179e48(cand))return 0;
out[0]=cand[0];out[1]=cand[1];return 1;
}
#pragma opt_strength_reduction reset
void func_ov000_02195750(void) {
    s32 func_ov000_02195574(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195574(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02195788(s16 *out) {
    void func_01ffada0(u8, u8, s32, s32, s32);
    s32 func_ov000_021a8ff0(s32);
    s32 func_ov000_021a98e4(s32);
    s32 func_ov000_0217bc34(s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern void *data_ov000_021df644;
    UnitKind1955 *up;
    s8 **rows;
    s32 kind;
    u8 attr;
    s32 resX, resY, best, y, x;
    u16 height, width;
    s32 ok;

    up = *(UnitKind1955 **)((u8 *)*gCurrentMap + 0x52d0);
    kind = up->kind;
    attr = data_ov000_021b5c0f[kind * 0x70];
    if (attr & 0x20) {
        return 0;
    }

    func_01ffada0(((u8 *)up)[1], ((u8 *)up)[2], kind, 0x6e, 0);

    resX = -1;
    resY = -1;
    best = 0x7fff;

    rows = (s8 **)((u8 *)*gCurrentMap + 0x52e8);

    height = *(u16 *)((u8 *)*gCurrentMap + 0x5146);
    if (height <= 0) {
        goto finish;
    }
    width = *(u16 *)((u8 *)*gCurrentMap + 0x5144);
    if (width <= 0) {
        goto finish;
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            u8 *map;
            u16 rowOff;
            u8 grid0;
            s8 cand;
            u8 grid1;
            u8 thr;

            if (rows[y][x] < 0) {
                continue;
            }
            map = (u8 *)*gCurrentMap;
            rowOff = *(u16 *)(map + 0x3758 + y * 2);
            grid0 = *(u8 *)(map + rowOff + x + 0x1420);
            if (func_ov000_021a8ff0(grid0 & 0x1f) == 0) {
                continue;
            }
            if (*(u16 *)(map + 0x52a6) != (grid0 & 0xe0)) {
                continue;
            }
            cand = rows[y][x];
            if (best < cand) {
                continue;
            }
            if (!func_ov000_0217bc34(x, y, 2, 5)) {
                continue;
            }
            ok = func_ov000_021a98e4(kind);
            if (ok == 1) {
                thr = ((u8 *)data_ov000_021df644)[2];
                grid1 = *(u8 *)(map + rowOff + x + 0x2d48);
                if (grid1 >= thr) {
                    continue;
                }
            }
            resX = x;
            resY = y;
            best = cand;
        }
    }

finish:
    if (best == 0x7fff) {
        return 0;
    }
    out[0] = (s16)resX;
    out[1] = (s16)resY;
    return 1;
}
#pragma opt_strength_reduction reset

