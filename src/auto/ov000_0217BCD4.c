/* 9 functions from 0x0217BCD4 to 0x0217C9F4 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0217bcd4(void) {
    void func_ov000_0217b3bc(void);
    extern s32 (*data_ov000_021df650)(s32, s32, s32);
    extern s32 func_ov000_0217ab5c(s32, s32, s32);
    s32 (*fp)(s32, s32, s32) = func_ov000_0217ab5c;
    data_ov000_021df650 = fp;
    func_ov000_0217b3bc();
}

s32 func_ov000_0217bcf4(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov000_0217abd8(s32, s32, s32);
    s32 func_ov000_0217b8f0(s32, s32, s32, s32);
    extern s32 (*data_ov000_021df650)(s32, s32, s32);

    data_ov000_021df650 = func_ov000_0217abd8;
    if (data_ov000_021df650(arg0, arg1, 0) == 1) {
        return 1;
    }
    return func_ov000_0217b8f0(arg0, arg1, 0, arg2);
}

s32 func_ov000_0217bd44(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern void **gCurrentMap;
    u8 temp_lr;
    void *temp_r4;

    temp_r4 = *gCurrentMap;
    temp_lr = M2C_FIELD((temp_r4 + (arg2 + M2C_FIELD((temp_r4 + (arg3 * 2)), u16 *, 0x3758))), u8 *, 0x508);
    if ((temp_lr != 0) && (M2C_FIELD(temp_r4, u8 *, 0x52D4) != temp_lr)) {
        return 5;
    }
    if (arg0 > arg2) {
        return 4;
    }
    if (arg0 < arg2) {
        return 2;
    }
    if (arg1 > arg3) {
        return 1;
    }
    if (arg1 < arg3) {
        return 3;
    }
    return 0;
}

s32 func_ov000_0217bdb4(s32 arg0, s32 arg1) {
    void func_01ffb554(void *);
    s32 func_01ffada0(s32, s32, s32, s32, s32);
    s32 func_ov000_021a8fc0(s16);
    s32 func_ov000_021a98a8(void);
    s32 ManhattanDistance(s32, s32, s32, s32);
    extern void **gCurrentMap;

    s32 x = arg0;
    s32 y = arg1;
    void *base;

    base = *gCurrentMap;
    func_01ffb554((u8 *)base + 0x338 + 0x2000);
    func_01ffada0(x, y, 3, 6, 1);
    base = *gCurrentMap;
    {
        u16 rowOff = M2C_FIELD((u8 *)base + (y << 1), u16 *, 0x3758);
        u8 id = *((u8 *)base + x + rowOff);
        if (id != 0) {
            if (func_ov000_021a8fc0((s16)id) == 1) {
                u8 *entry = (u8 *)base + ((u32)id * 14) + 0x59A4;
                u16 raw = M2C_FIELD(entry, u16 *, 0x6);
                if (((u32)(raw << 16) >> 27) != 0U) {
                    func_01ffb554((u8 *)base + 0xE30 + 0x1000);
                    return 1;
                }
            }
        }
    }

    {
        s32 xmin;
        s32 ymin;
        s32 xmax;
        s32 ymax;
        s32 right;
        s32 bottom;
        s32 xx;
        s32 yy;
        s16 xs;
        s16 ys;

        xmin = x - 6;
        if (xmin < 0) {
            xmin = 0;
        }
        ymin = y - 6;
        if (ymin < 0) {
            ymin = 0;
        }
        base = *gCurrentMap;
        xmax = x + 6;
        right = M2C_FIELD(base, u16 *, 0x5144) - 1;
        if (xmax < right) {
            right = xmax;
        }
        ymax = y + 6;
        bottom = M2C_FIELD(base, u16 *, 0x5146) - 1;
        if (ymax < bottom) {
            bottom = ymax;
        }

        for (yy = ymin; yy <= bottom; yy++) {
            for (xx = xmin; xx <= right; xx++) {
                s32 dist;
                s32 dxd;
                u8 id2;
                u16 rowOff2;
                u8 *entry;
                u16 raw2;
                s16 kind;

                xs = (s16)x;
                ys = (s16)y;

                dxd = x - xx;
                if (dxd <= 0) {
                    dxd = xx - x;
                }
                dist = dxd;
                if (y - yy > 0) {
                    dist += y - yy;
                } else {
                    dist += yy - y;
                }

                if (dist < 0) {
                    continue;
                }
                if (dist > 6) {
                    continue;
                }

                base = *gCurrentMap;
                if (((s8 **)((u8 *)base + 0x52E8))[yy][xx] < 0) {
                    continue;
                }

                rowOff2 = M2C_FIELD((u8 *)base + (yy << 1), u16 *, 0x3758);
                id2 = *((u8 *)base + xx + rowOff2);

                entry = (u8 *)base + ((u32)id2 * 14) + 0x59A4;
                kind = (s16)(((u32)(entry[0] << 26) >> 26));

                if (kind == 0) {
                    continue;
                }

                if (func_ov000_021a98a8() == 0) {
                    continue;
                }

                raw2 = M2C_FIELD(entry, u16 *, 0x8);
                if (x != (s32)(((u32)(raw2 << 26)) >> 26)) {
                    continue;
                }
                if (y != (s32)(((u32)(raw2 << 14)) >> 26)) {
                    continue;
                }

                if (kind == 1) {
                    if (ManhattanDistance(entry[1], entry[2], xs, ys) > 3) {
                        continue;
                    }
                }
                if (kind == 2) {
                    if (ManhattanDistance(entry[1], entry[2], xs, ys) > 2) {
                        continue;
                    }
                }

                base = *gCurrentMap;
                func_01ffb554((u8 *)base + 0xE30 + 0x1000);
                return 1;
            }
        }
    }

    base = *gCurrentMap;
    func_01ffb554((u8 *)base + 0xE30 + 0x1000);
    return 0;
}

void func_ov000_0217c08c(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) { (void)a0; (void)a1; (void)a2; (void)a3; (void)a4; }

s32 func_ov000_0217c2d4(u8 *arg0) {
    s32 func_01ffada0(s32, s32, s32, s32, s32);
    s32 func_ov000_021a9860(s32, s32);
    extern void **gCurrentMap;
    s32 x;
    s32 y;
    void *base;

    func_01ffada0(arg0[1], arg0[2], (arg0[0] << 26) >> 26, 0x6e, 0);

    base = *gCurrentMap;
    for (y = 0; y < M2C_FIELD(base, u16 *, 0x5146); y++) {
        for (x = y; x < M2C_FIELD(base, u16 *, 0x5144); x++) {
            if ((((s8 **)((u8 *)base + 0x52e8))[y])[x] >= 0) {
                if (func_ov000_021a9860(x, y) == 1) {
                    return 1;
                }
            }
            base = *gCurrentMap;
        }
        base = *gCurrentMap;
    }
    return 0;
}

void func_ov000_0217c3a4(void) {
extern void **gCurrentMap;
s32 func_ov000_021a98a8();
void *p;
if(!func_ov000_021a98a8((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52D0),u8 *,0)<<26)>>26))return;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,8)=(M2C_FIELD(p,u16 *,8)&~0x3F)|0x3F;
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,8)=(M2C_FIELD(p,u16 *,8)&~0xFC0)|0xFC0;
}

void func_ov000_0217c4c8(void *arg0) {
    (void)arg0;
}

