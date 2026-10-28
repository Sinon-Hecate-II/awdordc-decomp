/* 3 functions from 0x0218A9AC to 0x0218B0D8 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind0218;
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern void (*data_ov000_021df654)(void);
void func_ov000_0217c3a4(void);
void func_ov000_0218d040(int);
void func_ov000_0218d908(void);
void func_ov000_02198c08(void);
void func_ov000_02199d74(int, int, int, int, int);

#pragma opt_strength_reduction off
void func_ov000_0218ae58(void) {
    s32 func_ov000_021a9740(void *, s32);
    void func_01ffada0(u8, u8, u8, s32, s32);
    void func_01ffb9c4(s8);
    s32 func_020a47e0(s32, s32);
    s32 func_ov000_021a9bc0(void);
    s32 func_ov000_0217aa2c(s32, s32);
    s32 func_ov000_02179e48(void *);
    s32 func_ov000_0217e6bc(s32, s32);
    void func_ov000_0218a9ac(s32, s32);

    extern void **gCurrentMap;
    extern void *data_ov000_021df580;

    register s32 best asm("r7") = 0x7fff;
    s16 cand[2];
    s32 x;
    s32 y;

    {
        void *unit;
        unit = *(void **)(((u8 *)*gCurrentMap) + 0x52d0);
        if (func_ov000_021a9740(unit, 1) < 10) return;

        unit = *(void **)(((u8 *)*gCurrentMap) + 0x52d0);
        func_01ffada0(
            ((u8 *)unit)[1],
            ((u8 *)unit)[2],
            ((UnitKind0218 *)unit)->kind,
            0x6e,
            1);
        func_01ffb9c4(0x6f);
    }

    for (y = 0; y < *(u16 *)((u8 *)*gCurrentMap + 0x5146); y++) {
        for (x = 0; x < *(u16 *)((u8 *)*gCurrentMap + 0x5144); x++) {
            s8 *row;
            s8 cell;
            u16 rowOff;
            u8 flags;

            row = *(s8 **)(((u8 *)*gCurrentMap) + 0x52e8 + y * 4);
            cell = row[x];
            if (cell < 0) continue;

            rowOff = *(u16 *)((u8 *)*gCurrentMap + 0x3758 + y * 2);
            flags = *(u8 *)((u8 *)*gCurrentMap + x + rowOff + 0x539c);

            if ((flags & 0x7f) != 0) {
                if ((((u32)((u8 *)data_ov000_021df580)[7]) << 29 >> 31)) goto evaluate;
                goto next;
            }
            if (!func_020a47e0(x, y)) goto next;
            if (!func_ov000_021a9bc0()) goto next;
evaluate:
            {
                s32 score = func_ov000_0217aa2c(x, y);
                if (score < best) {
                    best = score;
                    cand[0] = (s16)x;
                    cand[1] = (s16)y;
                }
            }
next:;
        }
    }

    if (best == 0x7fff) return;

    if (!func_ov000_02179e48(cand)) return;
    if (!func_ov000_0217e6bc(cand[0], cand[1])) return;
    func_ov000_0218a9ac(cand[0], cand[1]);
    return;
}
#pragma opt_strength_reduction reset
void func_ov000_0218b02c(void) {
    u16 flags;
    u8 *p;
    if (*(u8 *)((u8 *)*gCurrentMap + 0x52d6)) return;
    *(u16 *)((u8 *)data_ov000_021df580 + 8) |= 0x10;
    func_ov000_0218d908();
    func_ov000_0218d040(1);
    flags = *(u16 *)((u8 *)data_ov000_021df580 + 8);
    if (!(flags & 0x20)) {
        *(u16 *)((u8 *)data_ov000_021df580 + 8) = flags | 0x20;
        func_ov000_02198c08();
        data_ov000_021df654();
    }
    func_ov000_0217c3a4();
    p = *(u8 **)((u8 *)*gCurrentMap + 0x52d0);
    func_ov000_02199d74(p[1], p[2], 2, 0, 0);
}
void func_ov000_0218a9ac(s32 arg0, s32 arg1) {
}
