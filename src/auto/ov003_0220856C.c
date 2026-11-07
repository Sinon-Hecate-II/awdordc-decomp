/* 5 functions from 0x0220856C to 0x02209310 (ov003), found by ds-decomp. */
#include "common.h"

s16 func_020a8ff4(void *);
void func_02086e9c(void);
void func_ov003_0220856c(void *arg0, s32 arg1, s32 arg2) {
    void *data;
    void *entries;
    void *entry;
    void *desc;
    void *anim0;
    void *anim1;
    void *anim2;
    s32 count;
    s32 i;
    s32 offset;
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    s32 drawColor;
    s32 alpha;
    s32 sx;
    s32 sy;
    s32 t;
    s32 u;
    s32 base;

    func_02086dfc((s16)arg2);
    data = M2C_FIELD(arg0, void **, 0x44);
    count = M2C_FIELD(data, u8 *, 0);
    if ((s8)count <= 0) {
        return;
    }
    base = 0x8ec0;
    i = 0;
    offset = 0;
    do {
        entry = (u8 *)M2C_FIELD(arg0, void **, 0x48) + offset;
        desc = M2C_FIELD(entry, void **, 0);
        w = M2C_FIELD(data, u8 *, 1);
        h = M2C_FIELD(data, u8 *, 2);
        x = (s16)(arg1 + M2C_FIELD(entry, s16 *, 6) + (w >> 1));
        y = (s16)(arg2 + M2C_FIELD(entry, s16 *, 8) + (h >> 1));
        drawColor = M2C_FIELD(entry, u8 *, 0x11) == 1 ? 0x6bef : 0;
        t = w >> 1;
        anim0 = M2C_FIELD(entry, void **, 0x20);
        if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
            if (M2C_FIELD(anim0, u8 *, 0x0e) != 0) {
                alpha = M2C_FIELD(entry, s8 *, 0x13);
            } else {
                alpha = func_020a8ff4(M2C_FIELD(anim0, void **, 0));
            }
            drawColor = 0x1a;
            anim1 = M2C_FIELD(entry, void **, 0x18);
            anim2 = M2C_FIELD(entry, void **, 0x1c);
            if (M2C_FIELD(anim1, u8 *, 0x0e) == 0) {
                sx = func_020a8ff4(M2C_FIELD(anim1, void **, 0));
                sy = func_020a8ff4(M2C_FIELD(anim2, void **, 0));
                sx = (M2C_FIELD(entry, u16 *, 0x0c) * sx) >> 8;
                sy = (M2C_FIELD(entry, u16 *, 0x0c) * sy) >> 8;
                u = func_020a8ff4(M2C_FIELD(anim1, void **, 0));
                t = func_020a8ff4(M2C_FIELD(anim2, void **, 0));
                if (sx == 0 && sy == 0) {
                    arg2 = (s16)(arg2 + M2C_FIELD(data, u8 *, 4));
                    i++;
                    offset += 0x24;
                    continue;
                }
            }
        } else {
            alpha = M2C_FIELD(entry, s8 *, 0x13);
        }
        (void)desc;
        (void)drawColor;
        (void)alpha;
        (void)u;
        (void)t;
        i++;
        offset += 0x24;
    } while (i < count);
    func_02086e9c();
}

u8 func_ov003_02209258(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 9) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02209274(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 2) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092a8(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 3) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092dc(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 4) result = 1;
 else result = 0;
 return result;
}

