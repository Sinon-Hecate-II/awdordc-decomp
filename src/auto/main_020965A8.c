/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u16 unk0, unk2, unk4, unk6; } Unk0209Rect;
typedef struct { u8 kind:6; u8 owner:2; u8 rest[13]; } Unit964;
extern u8 data_02102ee4[];
extern u16 gMapConfig[];

s32 func_020965a8(void *arg0, s16 *arg1, s32 arg2) {
    M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *data_027e0058;
    extern s32 gFrameCounter;

    u8 *node = (u8 *)arg0;
    s32 gen = gFrameCounter;
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

    FloodFillUnitRange(node[0], node[1], node[2], 0x6e, 0);

    {
        void *base = (void *)*data_027e0058;
        s32 row = 0;
        s32 col;
        s32 inner_count;
        u16 outer_count = *(u16 *)((u8 *)base + 0x5146);

        if (outer_count <= 0) goto done;

    outer_loop:
        if (row >= (s32)*(u16 *)((u8 *)base + 0x5146)) goto done;
        base = (void *)*data_027e0058;
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
                base = (void *)*data_027e0058;
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
        base = (void *)*data_027e0058;
        goto outer_loop;
    }

done:
    return found;
}

void func_0209670c(void *arg0, s32 arg1) { (void)arg0; (void)arg1; }

void func_02096b24(void) {
    M2C_UNK SetUiMessageText();
    extern M2C_UNK data_02102e14;
    SetUiMessageText();
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
    SetUiMessageText();
    func_01ffa3dc(&data_02102dbc, 7);
}

void func_02096b6c(void) {
    extern M2C_UNK data_02102d4c;
    SetUiMessageText();
    func_01ffa3dc(&data_02102d4c, 7);
}

void func_02096b88(void) {
    extern M2C_UNK data_02102d84;
    SetUiMessageText();
    func_01ffa3dc(&data_02102d84, 7);
}

/* Refresh the map records for `player`'s team when the view switches to it: count
 * every active teammate's units into the first active opponent's opposing-unit
 * total, refresh each teammate's record, then finish the view update. */
void UpdateTeamRecords(s32 player, M2C_UNK flags) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    extern s32 *gCurrentMap;
    s32 temp_r0;
    s32 opponent;
    s32 scan;
    s32 mate;
    s32 offset;
    s32 opponentOffset;
    void *temp_r1;

    opponent = -1;
    scan = 1;
loop_1:
    if ((IsPlayerActive(scan) != 0) && (IsSameTeam(player, scan) == 0)) {
        opponent = scan;
    } else {
        scan += 1;
        if (scan < 5) {
            goto loop_1;
        }
    }
    offset = MAP_PLAYER_STRIDE;
    mate = 1;
    opponentOffset = opponent * MAP_PLAYER_STRIDE;
    do {
        if ((IsSameTeam(player, mate) != 0) && (IsPlayerActive(mate) != 0)) {
            if (opponent != -1) {
                temp_r0 = *gCurrentMap;
                temp_r1 = opponentOffset + temp_r0;
                M2C_FIELD(temp_r1, u16 *, PLAYER_ENEMY_UNITS_OFF) = (u16) (M2C_FIELD(temp_r1, u16 *, PLAYER_ENEMY_UNITS_OFF) + M2C_FIELD((temp_r0 + offset), u8 *, PLAYER_UNIT_COUNT_OFF));
            }
            func_020c9ebc(mate, flags);
        }
        mate += 1;
        offset += MAP_PLAYER_STRIDE;
    } while (mate < 5);
    func_020c9b70();
}
