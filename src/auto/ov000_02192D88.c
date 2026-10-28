/* 4 functions from 0x02192D88 to 0x02193D6C (ov000), found by ds-decomp. */
#include "common.h"

int func_ov000_02192d88(void) { return 0; }

void func_ov000_021935c4(void *arg0) {
}

u32 func_ov000_02193998(void) {
extern void **data_027e0058;
u16 flags;
u32 x;
u8 *p;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
x=(u32)(p[0]<<26)>>26; if(x!=13)return x;
flags=*(u16 *)(p+6);
x=(u32)(flags<<21)>>28;
if(x==0)return flags;
x=(u32)(flags<<16)>>27;
if(x==0)return x;
x=func_020cccdc(); if(!x)return x;
{s32 v=func_ov000_021a8b78(M2C_FIELD(*data_027e0058,void **,0x52d0));if(v>=3)return v;}
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
return func_ov000_02199d74(p[1],p[2],24,0,0);
}

s32 func_ov000_02193a40(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_020d1938(s32);
    s32 func_020d273c(s32, s32);
    u8 func_ov000_021a8ff0(s32);
    s32 ManhattanDistance(s32, s32, s32, s32);
    u8 func_ov000_021786a8(s16 *);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s16 x, y;
    s32 i, best = 0x7fff;
    u8 *base, *rec, *rec7;
    u16 start;
    s16 coords[2];
    x = (s16)arg0;
    y = (s16)arg1;
    base = (u8 *)*gCurrentMap;
    start = data_ov000_021aeef4[M2C_FIELD(base, u16 *, 0x52a4)];
    for (i = start + 1; i < start + 0x33; i++) {
        rec = base + 0x59a4 + i * 14;
        {
            u8 kind = rec[0] & 0x3f;
            u16 flags;
            u8 t;
            u16 row;
            if (kind == 0) continue;
            if (kind != 0xd) continue;
            flags = M2C_FIELD(rec, u16 *, 6);
            if (((flags >> 11) & 0x1f) == 0) continue;
            row = M2C_FIELD(base + (s32)arg1 * 2, u16 *, 0x3758);
            t = M2C_FIELD(base, u8 *, 0x1420 + (s32)arg0 + row) & 0x1f;
            if (t == 1) {
                if (arg2 == 0) continue;
            } else if (t == 9) {
                if (arg2 != 0) continue;
            }
            {
                s32 d = ManhattanDistance(x, y, rec[1], rec[2]);
                if (d < best) best = d;
            }
        }
    }
    rec = base + 0x6c60;
    rec7 = rec;
    while (rec[0] != 0xff) {
        u8 kind = rec[0];
        u8 rx = rec[1];
        u8 ry = rec[2];
        u16 row;
        u8 t;
        row = M2C_FIELD(base + (s32)(ry) * 2? 0 : ry, u16 *, 0);
        (void)row;
        if (!func_ov000_021a8ff0(M2C_FIELD(base, u8 *, 0x1420 + rx + M2C_FIELD(base + ry * 2, u16 *, 0x3758)))) {
            s32 d;
            if (arg2 != 0) {
                if (kind != 0x12 && kind != 0x14) {
                    rec += 6;
                    continue;
                }
            } else {
                if (kind != 0x13 && kind != 0x15) {
                    rec += 6;
                    continue;
                }
            }
            d = ManhattanDistance(x, y, rx, ry);
            if (d < best) best = d;
        }
        rec += 6;
    }
    rec7 = rec;
    if (best != 0x7fff) goto done_func;
    if (func_ov000_021786a8(coords)) {
        best = 0x7fff - ManhattanDistance(x, y, coords[0], coords[1]);
    } else {
        s32 player;
        for (player = 1; player < 5; player++) {
            if (!func_020d1938(player)) continue;
            if (func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), player) != 0) continue;
            {
                u16 start2 = data_ov000_021aeef4[player];
                for (i = start2 + 1; i < start2 + 0x33; i++) {
                    u8 *rec2 = base + 0x59a4 + i * 14;
                    u8 kind = rec2[0] & 0x3f;
                    if (kind == 0) continue;
                    {
                        s32 d = ManhattanDistance(x, y, rec7[1], rec7[2]);
                        if (d < best) best = d;
                    }
                }
            }
        }
    }
done_func:
    return best;
}

