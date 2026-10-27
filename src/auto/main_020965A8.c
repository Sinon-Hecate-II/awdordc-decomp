/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 unk0, unk2, unk4, unk6; } Unk0209Rect;
typedef struct { u8 kind:6; u8 owner:2; u8 rest[13]; } Unit964;
extern u8 data_02102ee4[];
extern u16 data_02168f14[];

s32 func_020965a8(void *arg0, s16 *arg1, s32 arg2) {
    M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *gCurrentMap;
    extern s32 data_027e15bc;

    u8 *node = (u8 *)arg0;
    s32 gen = data_027e15bc;
    s32 found = 0;
    s32 threshold = 0x7fff;
    s16 *out = arg1;

    if (node[3] & 8) {
    node_search:
        if (node[8] == arg2 || node[9] == arg2) goto node_check;
        node += 0x10;
        goto node_search;
    node_check:
        if (node[3] & 8) goto node_search;
    }

    func_01ffada0(node[0], node[1], node[2], 0x6e, 0);

    {
        void *base = (void *)*gCurrentMap;
        s32 row = 0;
        s32 col;
        s32 inner_count;
        u16 outer_count = *(u16 *)((u8 *)base + 0x5146);

        if (outer_count <= 0) goto done;

    outer_loop:
        if (row >= (s32)*(u16 *)((u8 *)base + 0x5146)) goto done;
        base = (void *)*gCurrentMap;
        inner_count = *(s32 *)((u8 *)base + 0x5144) & 0xffff;
        /* ensure load as u16 below */
        inner_count = (s32)*(u16 *)((u8 *)base + 0x5144);
        col = 0;
        if (inner_count <= 0) goto outer_next;

    inner_loop:
        if (col >= inner_count) goto outer_next;
        {
            s8 cand = ((s8 **)((u8 *)base + (row << 2) + 0x52e8))[0][col];
            if (cand < 0) goto skip_col;
            {
                u16 rtab = *(u16 *)((u8 *)base + (row << 1) + 0x3758);
                u8 cond = *((u8 *)base + col + rtab + 0x508);
                if (cond != 0) goto skip_col;
                if (threshold < cand) goto skip_col;
                if (threshold == cand) {
                    gen += 1;
                    if (gen & 1) goto skip_col;
                }
                out[0] = (s16)col;
                out[1] = (s16)row;
                found = 1;
                base = (void *)*gCurrentMap;
                threshold = ((s8 **)((u8 *)base + (row << 2) + 0x52e8))[0][col];
                inner_count = (s32)*(u16 *)((u8 *)base + 0x5144);
                col += 1;
                goto inner_loop;
            }
        }
    skip_col:
        col += 1;
        goto inner_loop;

    outer_next:
        row += 1;
        base = (void *)*gCurrentMap;
        goto outer_loop;
    }

done:
    return found;
}

void func_02096b24(void) {
    M2C_UNK func_02086720();
    extern M2C_UNK data_02102e14;
    func_02086720();
    func_020948c4(&data_02102e14);
}

void func_02096b3c(void) {
    M2C_UNK func_02094704(M2C_UNK *);
    extern M2C_UNK data_02102e14;
    func_02094704(&data_02102e14);
}

void func_02096b50(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102dbc;
    func_02086720();
    func_01ffa3dc(&data_02102dbc, 7);
}

void func_02096b6c(void) {
    extern M2C_UNK data_02102d4c;
    func_02086720();
    func_01ffa3dc(&data_02102d4c, 7);
}

void func_02096b88(void) {
    extern M2C_UNK data_02102d84;
    func_02086720();
    func_01ffa3dc(&data_02102d84, 7);
}

void func_02096ba4(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
    s32 func_020d1938(s32);
    s32 func_020d273c(s32, s32);
    extern s32 *gCurrentMap;
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    void *temp_r1;

    var_r5 = -1;
    var_r4 = 1;
loop_1:
    if ((func_020d1938(var_r4) != 0) && (func_020d273c(arg0, var_r4) == 0)) {
        var_r5 = var_r4;
    } else {
        var_r4 += 1;
        if (var_r4 < 5) {
            goto loop_1;
        }
    }
    var_r7 = 0x8C;
    var_r6 = 1;
    var_r8 = var_r5 * 0x8C;
    do {
        if ((func_020d273c(arg0, var_r6) != 0) && (func_020d1938(var_r6) != 0)) {
            if (var_r5 != -1) {
                temp_r0 = *gCurrentMap;
                temp_r1 = var_r8 + temp_r0;
                M2C_FIELD(temp_r1, u16 *, 0x67C6) = (u16) (M2C_FIELD(temp_r1, u16 *, 0x67C6) + M2C_FIELD((temp_r0 + var_r7), u8 *, 0x67D5));
            }
            func_020c9ebc(var_r6, arg1);
        }
        var_r6 += 1;
        var_r7 += 0x8C;
    } while (var_r6 < 5);
    func_020c9b70();
}
