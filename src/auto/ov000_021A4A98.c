/* 5 functions from 0x021A4A98 to 0x021A58C8 (ov000), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_strength_reduction off
s32 func_ov000_021a4a98(u8 arg0, u8 arg1) {
    void func_01ffada0(s32, s32, s32, s32, s32);
    void func_01ffb9c4(s8);
    s32 func_020d27c0(s32);
    s32 func_020ba924(s32, s32);
    s32 func_ov000_021a43c4(void);
    s32 func_ov000_021a8784(s32);
    s32 func_ov000_021a8fc0(s32);
    u8 func_ov000_021a9084(s32);
    s32 func_ov000_021a90a8(s32, s32, s32);
    u8 func_ov000_021a98a8(s32);
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 data_ov000_021b5bfc[];

    register s32 count asm("r6") = 0;
    register s32 flag asm("r7") = 0;
    register s32 outer asm("r8") = 0;
    register s32 idx asm("r9") = 0;
    register s32 unit asm("r10") = 0;
    register s32 special asm("r11") = 0;
    register void *inner asm("r1") = (void *)0;

    u16 rowOff;
    u8 terrain;
    u8 kind;
    s32 ret;

    func_01ffada0(arg0, arg1, 7, 0x6e, 0);
    func_01ffb9c4(0x6f);

    inner = *gCurrentMap;
    if (*(s16 *)((u8 *)inner + 0x5146) <= 0) goto tail;
    if (*(s16 *)((u8 *)inner + 0x5144) <= 0) goto tail;

    for (outer = 0; outer < *(s16 *)((u8 *)inner + 0x5146); outer++) {
        for (idx = 0; idx < *(s16 *)((u8 *)inner + 0x5144); idx++) {
            void *grid = *(void **)((u8 *)inner + outer * 4 + 0x52e8);
            s8 cellVal = ((s8 *)grid)[idx];
            if (cellVal < 0) continue;
            rowOff = *(u16 *)((u8 *)inner + outer * 2 + 0x3758);
            terrain = ((u8 *)inner + idx + rowOff)[0x1420] & 0x1f;
            if (terrain == 0x1c) return 0;
            if (cellVal > 0x6e) {
                if (((u8 *)inner + idx + rowOff)[0] == 0) continue;
                func_020d27c0(((u8 *)inner + idx + rowOff)[0]);
                continue;
            }
            if (terrain == 0x11) {
                s16 sv = *(s16 *)((u8 *)inner + 0x52a8);
                if (func_ov000_021a90a8(sv, idx, outer) == 1) return 0;
            }
            if (flag == 0) {
                inner = *gCurrentMap;
                rowOff = *(u16 *)((u8 *)inner + outer * 2 + 0x3758);
                terrain = ((u8 *)inner + idx + rowOff)[0x1420] & 0x1f;
                if (terrain == 0x13) {
                    if (func_ov000_021a8784(0x18) != 0) flag = 1;
                    else if (func_ov000_021a43c4() == 1) flag = 1;
                }
                if (flag == 0) {
                    rowOff = *(u16 *)((u8 *)inner + outer * 2 + 0x3758);
                    terrain = ((u8 *)inner + idx + rowOff)[0x1420] & 0x1f;
                    if (func_ov000_021a9084(terrain) != 0) {
                        rowOff = *(u16 *)((u8 *)inner + outer * 2 + 0x3758);
                        terrain = ((u8 *)inner + idx + rowOff)[0x1420] & 0x1f;
                        if (terrain != 0x13 && func_ov000_021a8784(0x18) != 0) flag = 1;
                        if (flag == 0) {
                            void *gp = data_ov000_021df580;
                            u16 t = ((u16 *)gp)[5];
                            if ((((t >> 9) & 7) & 4) && func_ov000_021a43c4() == 1) flag = 1;
                        }
                    }
                }
            }
            inner = *gCurrentMap;
            rowOff = *(u16 *)((u8 *)inner + outer * 2 + 0x3758);
            unit = ((u8 *)inner + idx)[rowOff];
            if (unit == 0) continue;
            if (func_020ba924(idx, outer) == 1) special = 1;
            if (func_020d27c0(unit) == 0) {
                kind = *(u8 *)((u8 *)inner + 0x59a4 + unit * 0xe) & 0x3f;
                {
                    u8 *info = data_ov000_021b5bfc + kind * 0x70;
                    if ((info[0x13] & 7) != 0 && func_ov000_021a98a8(kind) != 0) return 0;
                }
            } else {
                if (func_ov000_021a8fc0(unit) == 1) {
                    kind = *(u8 *)((u8 *)inner + 0x59a4 + unit * 0xe) & 0x3f;
                    if (func_ov000_021a98a8(kind) != 0) count++;
                }
            }
        }
    }

tail:
    if (special == 0) {
        if (flag != 0) return 0x101;
        return 1;
    }
    ret = count + 1;
    if (flag != 0) ret |= 0x100;
    return ret;
}
#pragma pop

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

void func_ov000_021a4e08(void) {
    return;
}

void func_ov000_021a5564(u8 x) { return; }

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

