/* 3 functions from 0x02193D6C to 0x02194AB8 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02193d6c(void *arg0) {
    (void)arg0;
}

void func_ov000_02194090(void) {
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b5bfc;
    void *map;
    void *base;
    void *unit;
    s32 height, width;
    s32 xx, yy;
    s32 rx = -1, ry = -1, state = 0;

    map = *gCurrentMap;
    base = *(void **)map;
    unit = *(void **)((u8 *)base + 0x5000 + 0x2D0);
    func_01ffc328(unit);

    map = *gCurrentMap;
    base = *(void **)map;
    height = *(u16 *)((u8 *)base + 0x5146);
    if (height > 0) {
        width = *(u16 *)((u8 *)base + 0x5144);
        if (width > 0) {
            for (yy = 0; yy < height; yy++) {
                for (xx = 0; xx < width; xx++) {
                    void *path;
                    signed char pval;
                    u16 rowOff;
                    u8 terrain;
                    void *cell;
                    u8 *attr;
                    u8 owner;
                    u8 low4;
                    u8 tableVal;
                    u8 selOwner;

                    path = *(void **)((u8 *)base + yy * 4 + 0x52E8);
                    pval = *((signed char *)path + xx);
                    if (pval < 0) continue;
                    rowOff = *(u16 *)((u8 *)base + yy * 2 + 0x3758);
                    terrain = *((u8 *)base + xx + rowOff);
                    cell = (u8 *)base + xx + rowOff;
                    if (terrain == 0) continue;
                    if (!func_ov000_021a8fc0(((u8 *)cell)[0x508])) continue;

                    rowOff = *(u16 *)((u8 *)base + yy * 2 + 0x3758);
                    terrain = *((u8 *)base + xx + rowOff);
                    attr = (u8 *)base + 0x59A4 + terrain * 0x0E;
                    owner = attr[0] & 0x3F;
                    low4 = attr[0x0B] & 0x0F;
                    tableVal = ((u8 *)&data_ov000_021b5bfc)[owner * 0x70 + 0x13];
                    if (!(tableVal & 0x20)) continue;
                    if (func_ov000_021a8984(low4)) continue;
                    selOwner = (*((u8 *)unit)) & 0x3F;
                    if (!func_ov000_021a995c(attr, selOwner)) continue;

                    if (state != 0 && state != 0x18) {
                        if (state != 0x19) continue;
                        if (owner == 0x18) continue;
                    }
                    rx = xx;
                    ry = yy;
                    state = owner;
                }
            }
        }
    }

    if (rx == -1) return;

    {
        void **m = *gCurrentMap;
        void *b = *m;
        void *selUnit = *(void **)((u8 *)b + 0x5000 + 0x2D0);
        u16 v;

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v &= ~0xC000;
        *(u16 *)((u8 *)selUnit + 0x08) = v;

        if ((((u8 *)selUnit)[0x0B] & 0x0F) == 2 || ((((u8 *)selUnit)[0x0B] & 0x0F) == 5)) {
            ((u8 *)selUnit)[0x0B] &= 0xF0;
        }

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v = (v & ~0x003F) | 0x003F;
        *(u16 *)((u8 *)selUnit + 0x08) = v;

        v = *(u16 *)((u8 *)selUnit + 0x08);
        v = (v & ~0x0FC0) | 0x0FC0;
        *(u16 *)((u8 *)selUnit + 0x08) = v;
    }

    func_ov000_0217c3a4();
    func_ov000_02199d74(rx, ry, 7, 0);
}

void func_ov000_02194370(void) {
    return;
}

