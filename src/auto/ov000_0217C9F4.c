/* 7 functions from 0x0217C9F4 to 0x0217D86C (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_0217c9f4(void *arg0) {
    s32 func_ov000_021a98e4(u32);
    s32 func_ov000_0217c4c8(void *);
    s32 func_ov000_021a97e0(s32, u32);
    s32 func_ov000_0217c420(void *, void *);
    s32 func_020d27c0(s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5bfc[];
    extern u8 data_ov000_021b5c0f[];

    u8 *unit;
    u32 kind;
    u8 selX, selY;
    void *map;
    void *base;
    s32 n;
    s32 radius;
    s32 minX, minY, maxX, maxY;
    s32 x, y;
    s32 r7;
    s32 width, height;
    u8 *selectedUnit;
    u16 hf;
    s32 dx, dy, dist;
    s32 terrainCost;
    u16 rowOff;
    u8 terrainKind;
    u8 *record;
    u32 k;

    unit = (u8 *)arg0;

    kind = ((u32)unit[0] << 26) >> 26;
    if (func_ov000_021a98e4(kind) == 1) {
        return func_ov000_0217c4c8(arg0);
    }
    if (func_ov000_021a98e4(kind) != 0) {
        return 0;
    }
    if (kind == 0x19) {
        hf = *(u16 *)(unit + 6);
        if (((u32)(hf << 21) >> 28) == 0) {
            return 0;
        }
    }

    map = *gCurrentMap;
    base = *(void **)map;
    selX = unit[1];
    selY = unit[2];

    if (unit == 0) {
        n = 0;
    } else {
        n = (((s32)unit - ((s32)base + 0x59a4)) / 14) >> 6;
        n = n + 1;
    }
    radius = func_ov000_021a97e0(n, kind);

    minX = (s32)selX - radius;
    if (minX < 0) minX = 0;
    minY = (s32)selY - radius;
    if (minY < 0) minY = 0;

    width = M2C_FIELD(map, u16 *, 0x5144);
    maxX = (s32)selX + radius;
    if (maxX > width - 1) maxX = width - 1;

    height = M2C_FIELD(map, u16 *, 0x5146);
    maxY = (s32)selY + radius;
    if (maxY > height - 1) maxY = height - 1;

    r7 = 0;

    for (y = minY; y <= maxY; y++) {
        for (x = minX; x <= maxX; x++) {
            dx = (s32)selX - x;
            if (dx <= 0) dx = x - (s32)selX;
            dist = dx;
            dy = (s32)selY - y;
            if (dy <= 0) dy = y - (s32)selY;
            dist += dy;
            if (dist < 0) continue;
            if (dist > radius) continue;

            if ((((signed char **)((u8 *)base + 0x52E8))[y])[x] < 0) continue;

            rowOff = M2C_FIELD((u8 *)base + (y << 1), u16 *, 0x3758);
            terrainKind = *((u8 *)base + x + rowOff);
            if (terrainKind == 0) continue;
            if (func_020d27c0((s32)terrainKind) == 0) continue;

            record = (u8 *)base + 0x59a4 + (s32)terrainKind * 14;
            if (func_ov000_0217c420(record, (void *)unit) == 0) continue;

            r7++;
            k = ((u32)record[0] << 26) >> 26;
            if (data_ov000_021b5bfc[k * 112 + 0x13] & 0x10) r7++;
        }
    }

    selectedUnit = *(u8 **)((u8 *)base + 0x52D0);
    if (func_ov000_0217c420(selectedUnit, (void *)unit) == 1) {
        r7++;
        k = ((u32)selectedUnit[0] << 26) >> 26;
        if (data_ov000_021b5c0f[k * 112] & 0x10) r7++;
    }

    return r7;
}

int func_ov000_0217d000(int r0, int r1) {
    r1 &= 0x1F;
    if (r1 == 0x11) {
        if ((unsigned int)r0 > 0x1A) {
            return 0;
        }
        switch (r0) {
        case 5: case 7: case 8: case 10: case 11:
        case 12: case 16: case 18: case 19: case 21:
        case 22: case 26:
            return 1;
        default:
            return 0;
        }
    }
    if (r1 == 0x12) {
        if (r0 >= 0 && r0 <= 0x11) {
            switch (r0) {
            case 6: case 12: case 14: case 16: case 17:
                return 1;
            default:
                goto case13;
            }
        } else if (r0 == 0x15) {
            return 1;
        } else {
            goto case13;
        }
    } else if (r1 != 0x13) {
        return 0;
    }
case13:
    r0 -= 0x0F;
    if ((unsigned int)r0 > 8) {
        return 0;
    }
    switch (r0) {
    case 0: case 2: case 3: case 5: case 6:
    case 7: case 8:
        return 1;
    default:
        return 0;
    }
}

s32 func_ov000_0217d150(s32 arg0, s32 arg1, void *arg2) {
    void func_01ffb554(void *);
    s32 func_01ffada0(s32, s32, s32, s32);
    s32 func_020d27a4(s32, s32);
    s32 func_ov000_021a97d0(s32, s32);
    s32 func_ov000_021a98a8(u32);
    s32 func_ov000_021a9904(u32);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;

    s32 sp0;
    void *map;
    void *base;
    void *dataBase;
    u8 dataField5;
    s32 selectedKind;
    s32 outerLimit;
    s32 r8;
    s32 r9;
    s32 innerLimit;
    s32 *unitArray;
    signed char terrainCost;
    u16 rowOff;
    s32 kindIndex;
    u8 *record;
    u8 kind;
    void *selectedUnit;
    u8 arg2kind;
    u16 recField6;
    s32 checkByte;
    u16 recField4;
    s32 terrainValue;
    u8 dataField2;

    sp0 = 0;
    map = *gCurrentMap;
    base = *(void **)map;
    dataBase = *(void **)data_ov000_021df580;
    dataField5 = ((u8 *)dataBase)[5];
    selectedKind = (s32)(((u8 *)*(void **)((u8 *)base + 0x52d0))[0]);
    selectedKind = (selectedKind << 26) >> 26;
    outerLimit = (s32)(*((s16 *)((u8 *)base + 0x5146)));
    arg2kind = (u8)(((u8 *)arg2)[0] << 26 >> 26);
    dataField2 = ((u8 *)dataBase)[2];

    (void)sp0;

    func_01ffb554((void *)((u8 *)base + 0x2338));
    func_01ffada0(arg0, arg1, selectedKind, (s32)dataField5);

    r8 = 0;
    if (outerLimit <= 0) {
        goto final;
    }

outerLoop:
    unitArray = *(s32 **)((u8 *)base + r8 * 4 + 0x52e8);
    innerLimit = (s32)(*((s16 *)((u8 *)base + 0x5144)));
    r9 = 0;
    if (innerLimit <= 0) {
        goto outerInc;
    }
    while (r9 < innerLimit) {
        terrainCost = (signed char)unitArray[r9];
        if (terrainCost < 0) {
            goto innerNext;
        }
        rowOff = *((u16 *)((u8 *)base + r8 * 2 + 0x3758));
        kindIndex = (s32)(*((u8 *)base + (s32)rowOff + r9));
        record = (u8 *)base + 0x59a4 + kindIndex * 0x0e;
        kind = (u8)((record[0] << 26) >> 26);
        selectedUnit = *(void **)((u8 *)base + 0x52d0);
        if (kind != 0) {
            if ((void *)record == selectedUnit) {
                goto innerNext;
            }
        }
        if (record == (u8 *)0) {
            if (!func_020d27a4((s32)*((u8 *)base + 0x52d4), 0)) {
                goto innerNext;
            }
        } else {
            if (!func_020d27a4((s32)*((u8 *)base + 0x52d4), kindIndex)) {
                goto innerNext;
            }
        }
        if (!func_ov000_021a97d0((s32)kind, (s32)arg2kind)) {
            goto innerNext;
        }
        if (func_ov000_021a9904((u32)kind) != 0) {
            goto innerNext;
        }
        if (func_ov000_021a98a8((u32)kind) != 0) {
            goto innerNext;
        }
        if (kind == 4) {
            goto innerNext;
        }
        recField6 = *((u16 *)(record + 6));
        if ((recField6 & 0x7f) < 0x3c) {
            goto innerNext;
        }
        recField4 = *((u16 *)(record + 4));
        if (recField4 & 0x1) {
            checkByte = (s32)*((u8 *)base + 0x52d4);
            (void)checkByte;
            terrainValue = (s32)*((u8 *)base + (s32)rowOff + r9 + 0x2d48);
            if (terrainValue < (s32)dataField2) {
                goto innerNext;
            }
        }
        func_01ffb554((void *)((u8 *)base + 0x1e30));
        return 1;

innerNext:
        r9++;
        if (r9 < innerLimit) {
            continue;
        }
        break;
    }

outerInc:
    outerLimit = (s32)(*((s16 *)((u8 *)base + 0x5146)));
    r8++;
    if (r8 < outerLimit) {
        goto outerLoop;
    }

final:
    func_01ffb554((void *)((u8 *)base + 0x1e30));
    return 0;
}

void func_ov000_0217d3b8(s32 arg0) {
    s32 func_ov000_021a8ac8(void *);
    extern void **gCurrentMap;
    void *unit;
    if (arg0 != 3) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u16 *, 6) << 25) >> 25) < 0x3DU) return;
    if (func_ov000_021a8ac8(unit) != 1) return;
    unit = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
    if (((u32)(M2C_FIELD(unit, u8 *, 0xB) << 28) >> 28) == 0) {
        M2C_FIELD(unit, u8 *, 0xB) |= 0x20;
    }
}

void func_ov000_0217d428(void) { }

#pragma opt_strength_reduction off
void func_ov000_0217d6dc(void) {
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    s32 func_ov000_021a98a8(u32);

    void ***mapSlot = &data_027e0058;
    u16 *tblBase = data_ov000_021aeef4;

    void *map;
    void *m0;
    s32 i;
    u16 tbl;
    s32 off;
    u8 *rec;
    u32 kind;

    map = *mapSlot;
    m0 = *(void **)map;
    tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
    i = (s32)tbl + 1;
    if (i >= (s32)tbl + 0x33) return;

    off = i * 14;

    for (;;) {
        map = *mapSlot;
        m0 = *(void **)map;
        rec = (u8 *)m0 + 0x59A4 + off;

        kind = ((u32)rec[0] << 26) >> 26;
        if (kind == 0) goto loopinc;
        if (func_ov000_021a98a8(kind) == 0) goto loopinc;
        if ((((u32)rec[11] << 26) >> 31) == 0) goto loopinc;

        {
            u16 hw = *(u16 *)(rec + 8);
            u32 low = ((u32)hw << 26) >> 26;
            map = *mapSlot;
            m0 = *(void **)map;
            if (low != 0x3F) {
                u32 idx = ((u32)hw << 20) >> 26;
                u16 rowval = *(u16 *)((u8 *)m0 + idx * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + low + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            } else {
                u8 rec2 = rec[2];
                u8 rec1 = rec[1];
                u16 rowval = *(u16 *)((u8 *)m0 + (u32)rec2 * 2 + 0x3758);
                signed char attrib = *(signed char *)((u8 *)m0 + (u32)rec1 + rowval + 0x1928);
                u8 *p = (u8 *)m0 + 0x6C60 + (s32)attrib * 6;
                if (p[3] != 0) p[3] = (u8)(p[3] - 1);
            }
        }

        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0x3F) | 0x3F);
            *(u16 *)(rec + 8) = t;
        }
        {
            u16 t = *(u16 *)(rec + 8);
            t = (u16)((t & ~0xFC0) | 0xFC0);
            *(u16 *)(rec + 8) = t;
        }
        rec[11] = (u8)(rec[11] & ~0x20);

loopinc:
        map = *mapSlot;
        m0 = *(void **)map;
        i++;
        off = off + 14;
        tbl = tblBase[M2C_FIELD(m0, u16 *, 0x52A4)];
        if (i < (s32)tbl + 0x33) continue;
        break;
    }
}
#pragma opt_strength_reduction on
void func_ov000_0217d850(void) {
    extern void *data_ov000_021df580;
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) & ~8);
}
