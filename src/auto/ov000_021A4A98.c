/* 5 functions from 0x021A4A98 to 0x021A58C8 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_021a4dc4(void) {
    s32 func_ov000_021a4a98(u8, u8);
    s32 func_ov000_021a67f0(s32);
    extern u8 data_ov000_021e00ac;
    extern u8 data_ov000_021e00ad;
    s32 index = func_ov000_021a67f0(1);
    s32 offset;
    if (index == -1) return 0;
    offset = index * 12;
    return func_ov000_021a4a98((&data_ov000_021e00ac)[offset], (&data_ov000_021e00ad)[offset]);
}

void func_ov000_021a581c(void) {
    void func_01ffb3d0(s32);
    void func_01ffb554(void *);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_021a5564(u8);
    extern void **gCurrentMap;
    u16 saved;
    s32 i;
    void *base;
    base = *gCurrentMap;
    saved = M2C_FIELD(base, u16 *, 0x52B6);
    func_01ffb554(base + 0x2338);
    func_01ffb3d0(0);
    func_01ffb554(*gCurrentMap + 0x1E30);
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0)
            func_ov000_021a5564(i);
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

