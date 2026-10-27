/* 9 functions from 0x02187188 to 0x02187F7C (ov000), found by ds-decomp. */
#include "common.h"
extern void (*data_ov000_021df648)(void);
void func_ov000_02188338(void);
extern void **gCurrentMap;

s32 func_ov000_02187188(s32 x, s32 y, u8 *unit) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0e[];
    extern s8 data_ov000_021b55a0[];
    extern M2C_UNK data_0212616c;
    s32 func_ov000_021a9d8c(s16, s16);
    s32 func_020d27ec(s32, s32);
    s32 func_020d0654(s32, s32, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_ov000_021a9214(void *, s32, s32);
    s32 func_ov000_021a93a8(void *, s32, s32);
    void *base;
    s32 tile;
    s32 kind;
    s32 flag;
    s32 w;
    s32 costTerrain;
    s32 result = 0;

    if (x < 0 || y < 0) {
        return -1;
    }
    base = *gCurrentMap;
    if (x >= M2C_FIELD(base, u16 *, 0x5144) || y >= M2C_FIELD(base, u16 *, 0x5146)) {
        return -1;
    }
    if (func_ov000_021a9d8c((s16)x, (s16)y)) {
        return -1;
    }

    base = *gCurrentMap;
    kind = (unit[0] << 26) >> 26;
    tile = M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x1420) & 0x1f;
    costTerrain = M2C_FIELD((s8 *)M2C_FIELD(&data_0212616c, void **, 0x64) + data_ov000_021b5c0e[kind * 0x70] * 32, s8 *, tile);
    if (costTerrain < 0) {
        return -1;
    }
    w = M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x2d48);
    flag = data_ov000_021b55a0[tile];

    if (flag == 0 || func_020d27ec(M2C_FIELD(base, u8 *, 0x52d4), M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), u8 *, 0x1420)) == 0) {
        base = *gCurrentMap;
        result += (func_0207c8ec(func_020d0654(M2C_FIELD(base, u16 *, 0x52a4), 1, tile), 10) + 1) << 4;
    }
    result += (0x100 - w) << 8;

    if (flag == 0) {
        if (func_ov000_021a9214(unit, x, y) == 1) {
            result += 0x10000;
        }
    }
    if (func_ov000_021a93a8(M2C_FIELD(*gCurrentMap, void **, 0x52d0), x, y) == 1) {
        result += 0x20000;
    }
    return result;
}

void func_ov000_02187e20(void) {
func_ov000_02187820();
if(data_ov000_021df648==func_ov000_02188338) func_ov000_021879f4();
func_ov000_02187c3c();
}

u8 func_ov000_02187e50(void) {
    s32 base = *gCurrentMap;
    s32 v;
    u32 x;
    u32 y;
    u8 result;

    {
        void *ptr = M2C_FIELD(base, void **, 0x52d0);
        v = M2C_FIELD(ptr, u16 *, 8);
    }

    x = (u32)(v << 26) >> 26;

    if (x == 63)
        return 0;

    y = (u32)(v << 20) >> 26;

    if (((s8 **)((u8 *)base + 0x52e8))[y][x] >= 0)
        result = 1;
    else
        result = 0;

    return result;
}

u8 func_ov000_021a9084(s32);
s32 func_ov000_02187eac(u16 *arg0) {
    extern void **gCurrentMap;
    void *base;
    s32 height;
    s32 width;
    s32 y = 0;
    s32 x;
    u16 rowoff;
    u8 v;

    base = *gCurrentMap;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height <= 0) return 0;
outer:
    width = *(u16 *)((u8 *)base + 0x5144);
    x = y;
    if (width > 0) {
        do {
            if (((s8 **)((u8 *)base + 0x52e8))[y][x] >= 0) {
                rowoff = *(u16 *)((u8 *)base + 0x3758 + y * 2);
                v = *(u8 *)((u8 *)base + 0x1420 + rowoff + x);
                if (func_ov000_021a9084(v)) {
                    arg0[0] = (u16)x;
                    arg0[1] = (u16)y;
                    return 1;
                }
            }
            base = *gCurrentMap;
            x = x + 1;
            width = *(u16 *)((u8 *)base + 0x5144);
        } while (x < width);
    }
    height = *(u16 *)((u8 *)base + 0x5146);
    y = y + 1;
    if (y < height) goto outer;
    return 0;
}

