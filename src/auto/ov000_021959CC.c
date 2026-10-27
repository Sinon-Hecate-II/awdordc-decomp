/* 15 functions from 0x021959CC to 0x0219694C (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_02195ea4(void) {
    s32 func_ov000_021a98e4(u32);
    s32 func_ov000_02195b80(s16 *);
    s32 func_ov000_02195788(s16 *);
    s32 func_ov000_0217e6bc(s16,s16);
    void func_ov000_0218a9ac(s16,s16);
    extern void **gCurrentMap;
    s16 sp0[2];
    if (func_ov000_021a98e4((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26)==1) {
        if (func_ov000_02195b80(sp0)==0) return;
    } else {
        if (func_ov000_02195788(sp0)==0) return;
    }
    if (func_ov000_0217e6bc(sp0[0],sp0[1])==0) return;
    func_ov000_0218a9ac(sp0[0],sp0[1]);
}

s32 func_ov000_02195f1c(s16 *arg0) {
    s32 func_020d243c(u16);
    s32 func_01ffada0(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];

    u8 *map;
    u8 *unit8;
    u16 player;
    u8 *entry;
    s8 *grid;
    s8 cell;

    map = (u8 *)*gCurrentMap;
    unit8 = (u8 *)*(void **)(map + 0x52d0);
    if (data_ov000_021b5c0f[((u32)(unit8[0] << 26) >> 26) * 0x70] & 0x20) {
        return 0;
    }
    if (func_020d243c(*(u16 *)(map + 0x52a4)) == 0) {
        return 0;
    }

    map = (u8 *)*gCurrentMap;
    unit8 = (u8 *)*(void **)(map + 0x52d0);
    func_01ffada0(unit8[1], unit8[2], (u32)(unit8[0] << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + 0x52a4);
    entry = map + 0x67a4 + player * 0x8c;
    grid = *(s8 **)(map + ((u32)(entry[0x2c] << 25) >> 23) + 0x52e8);
    cell = grid[entry[0x2b] & 0x7f];
    if (cell < 0) {
        return 0;
    }
    arg0[0] = (s16)(entry[0x2b] & 0x7f);

    map = (u8 *)*gCurrentMap;
    player = *(u16 *)(map + 0x52a4);
    entry = map + 0x67a4 + player * 0x8c;
    arg0[1] = (s16)(entry[0x2c] & 0x7f);

    return 1;
}

void func_ov000_0219604c(void) {
    s32 func_ov000_02195f1c(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195f1c(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_02196084(s16 *arg0) {
    void func_ov000_02179be0(void);
    void func_ov000_02179d3c(void);
    s32 func_ov000_02179e48(s16 *);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 0x01);
        f8 = (f8 & ~0x3f) | (v & 0x3f);
        *(u16 *)((u8 *)unit + 0x08) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    {
        u8 v = *(u8 *)((u8 *)unit + 0x02);
        f8 = (f8 & ~0xfc0) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 0x08) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    cell = ((s8 **)(map + 0x52e8))[((u32)(f8 << 20) >> 26)][((u32)(f8 << 26) >> 26)];
    if (cell < 0) {
        return 0;
    }

    sp0[0] = (s16)(((u32)(f8 << 26) >> 26));
    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 0x08);
    sp0[1] = (s16)(((u32)(f8 << 20) >> 26));

    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219619c(void) {
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196084(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_021961d4(s16 *arg0) {
    s32 func_01ffada0(u8, u8, u32, s32, s32);
    extern void **gCurrentMap;

    u8 *map;
    void *unit;
    u16 f8;
    s8 cell;
    u32 low;
    u32 kind;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    func_01ffada0(*(u8 *)((u8 *)unit + 1), *(u8 *)((u8 *)unit + 2),
                   (u32)(*(u8 *)((u8 *)unit) << 26) >> 26, 0x6e, 0);

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    if (((u32)(f8 << 26) >> 26) == 0x3f) {
        u8 v = *(u8 *)((u8 *)unit + 1);
        f8 = (f8 & ~0x3fu) | (v & 0x3fu);
        *(u16 *)((u8 *)unit + 8) = f8;
    }

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    {
        u8 v = *(u8 *)((u8 *)unit + 2);
        f8 = (f8 & ~0xfc0u) | (((u32)v << 26) >> 20);
    }
    *(u16 *)((u8 *)unit + 8) = f8;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    low = ((u32)f8 << 26) >> 26;
    kind = ((u32)f8 << 20) >> 26;
    cell = *(s8 *)((u8 *)*(void **)(map + 0x52e8 + kind * 4) + low);
    if (cell < 0) {
        return 0;
    }

    arg0[0] = (s16)low;

    map = (u8 *)*gCurrentMap;
    unit = *(void **)(map + 0x52d0);
    f8 = *(u16 *)((u8 *)unit + 8);
    arg0[1] = (s16)(((u32)f8 << 20) >> 26);

    return 1;
}

void func_ov000_021962f8(void) {
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_021961d4(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

s32 func_ov000_02196330(void) {
    s32 func_020a32f4(s32);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    extern void **gCurrentMap;
    s32 var_r5;

    var_r5 = 1;
loop_1:
    if ((func_020d1938(var_r5) != 0) && (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), var_r5) == 0) && (func_020a32f4(var_r5) != 0)) {
        return 1;
    }
    var_r5 += 1;
    if (var_r5 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 func_ov000_02196398(s16 *arg0) {
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

void func_ov000_021963f8(void) {
    s32 func_ov000_02196398(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    s16 sp0[2];

    if (func_ov000_02196398(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    func_ov000_0218a9ac(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02196430(s16 *arg0) {
    s32 func_ov000_02194ab8(s16 *);
    s32 func_ov000_021a9c28(void);
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_02195574(s16 *);
    s32 func_ov000_02195788(s16 *);
    s32 func_020d243c(u16);
    s32 func_ov000_02195f1c(s16 *);
    s32 func_ov000_02196084(s16 *);
    s32 func_ov000_021961d4(s16 *);
    s32 func_ov000_02196330(void);
    s32 func_ov000_02196398(s16 *);
    extern void **gCurrentMap;

    u8 *map;
    u8 *unit;
    u32 key;

    map = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(map + 0x52d0);
    key = (u32)(unit[0x0b] << 28) >> 28;

    switch (key) {
    case 0:
    case 1:
        if (func_ov000_02194ab8(arg0) == 0) {
            return 0;
        }
        break;
    case 2:
        if (func_ov000_021a9c28() == 1) {
            if (func_ov000_021954dc(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(arg0) == 0) {
                return 0;
            }
        }
        break;
    case 3:
        if (func_ov000_02195574(arg0) == 0) {
            return 0;
        }
        break;
    case 4:
        if (func_ov000_02195788(arg0) == 0) {
            return 0;
        }
        break;
    case 5: {
        u16 player = *(u16 *)(map + 0x52a4);
        if (func_020d243c(player) == 1) {
            if (func_ov000_02195f1c(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02195788(arg0) == 0) {
                return 0;
            }
        }
        break;
    }
    case 6:
        if (func_ov000_02195788(arg0) == 0) {
            return 0;
        }
        break;
    case 7:
    case 9:
        if (func_ov000_02196084(arg0) == 0) {
            return 0;
        }
        break;
    case 8:
        if (func_ov000_021961d4(arg0) == 0) {
            return 0;
        }
        break;
    case 10: {
        arg0[0] = (s16)unit[1];
        arg0[1] = (s16)(((u8 *)*(void **)(((u8 *)*gCurrentMap) + 0x52d0))[2]);
        break;
    }
    default:
        if (func_ov000_02196330() == 1) {
            if (func_ov000_02196398(arg0) == 0) {
                return 0;
            }
        } else {
            if (func_ov000_02194ab8(arg0) == 0) {
                return 0;
            }
        }
        break;
    }
    return 1;
}
#pragma opt_strength_reduction reset
void func_ov000_021967fc(void) {
    s32 func_ov000_021a9934(u32, u32);
    void func_ov000_02179be0(void);
    void func_ov000_02179d3c(void);
    s32 func_ov000_0217e6bc(s16, s16);
    void func_ov000_0218a9ac(s16, s16);
    extern void **gCurrentMap;
    extern u8 **data_ov000_021df580;

    u8 *ptr;
    u8 *base;
    u8 *unit;
    u32 kind;
    s32 result;
    s16 savedCol;
    s16 savedRow;
    s32 i;
    s32 rows;
    s32 cols;
    s32 j;
    s8 *grid;
    s8 *p;
    u16 rowTile;
    u8 tileByte;

    ptr = (u8 *)*data_ov000_021df580;
    if (!(*(u16 *)(ptr + 0xa) & 0x04)) {
        return;
    }

    base = (u8 *)*gCurrentMap;
    unit = (u8 *)*(void **)(base + 0x52d0);
    kind = (u32)(unit[0] << 26) >> 26;
    if (func_ov000_021a9934(0x18, kind) == 0) {
        return;
    }

    func_ov000_02179be0();
    func_ov000_02179d3c();

    result = 0x7fff;
    base = (u8 *)*gCurrentMap;
    rows = *(u16 *)(base + 0x5146);
    if (rows > 0) {
        cols = *(u16 *)(base + 0x5144);
        for (i = 0; i < rows; i++) {
            if (cols > 0) {
                grid = (s8 *)*(void **)(base + 0x52e8 + i * 4);
                rowTile = *(u16 *)(base + i * 2 + 0x3758);
                p = grid;
                j = i;
                do {
                    if (*p < 0) {
                        break;
                    }
                    tileByte = base[rowTile + j + 0x1420];
                    if (tileByte & 0xe0) {
                        break;
                    }
                    tileByte &= 0x1f;
                    if (tileByte != 0x13) {
                        break;
                    }
                    result = grid[j];
                    savedCol = (s16)j;
                    savedRow = (s16)i;
                    j = j + 1;
                    p = p + 1;
                } while (j < cols);
            }
        }
    }

    if (result == 0x7fff) {
        return;
    }
    if (func_ov000_0217e6bc(savedCol, savedRow) == 0) {
        return;
    }
    func_ov000_0218a9ac(savedCol, savedRow);
}

