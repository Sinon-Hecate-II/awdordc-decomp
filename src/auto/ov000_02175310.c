/* 7 functions from 0x02175310 to 0x02175FB0 (ov000), found by ds-decomp. */
#include "common.h"

/* Initializes a unit entry's nested battle state from a character template and stat table. */
void func_ov000_021755b4(void *entry, s32 templateIndex, s32 statIndex) {
    s32 func_020a7b0c(s32);
    s32 func_020a7b24(s32);
    s32 func_020a7bec(s32);
    s32 func_020a7bf8(s32);
    s32 func_020a7c50(s32);
    s32 func_020a7c68(s32);
    s32 func_020a7c98(s32);
    M2C_UNK func_ov000_02176af8(void *, s32);
    extern s32 *gCurrentMap;
    void *state;

    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 8) = statIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x50) = templateIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0) = (s32) M2C_FIELD(((templateIndex * 0x8C) + *gCurrentMap), u8 *, 0x67CD);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x10) = func_020a7c68(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x14) = func_020a7c68(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x18) = func_020a7c50(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x1C) = func_020a7c50(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x28) = func_020a7b24(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x30) = func_020a7bf8(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x34) = func_020a7bec(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x40) = func_020a7b0c(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x54) = func_020a7c98(statIndex);
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s8 *, 0x48) = 0;
    state = M2C_FIELD(entry, void **, 0x10);
    M2C_FIELD(state, s32 *, 0x60) = (s32) M2C_FIELD(((M2C_FIELD(state, s32 *, 0x50) * 0x8C) + *gCurrentMap), u8 *, 0x67C1);
    func_ov000_02176af8(entry, statIndex);
    if (M2C_FIELD(entry, s32 *, 4) == 0) {
        M2C_FIELD(entry, s32 *, 4) = 1;
    }
}

void func_ov000_02175740(void *arg0) {
    M2C_UNK func_01ff85b8(s32, s32, s32);
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    M2C_UNK func_02080860(s32, s32, s32, u16, s32);
    M2C_UNK func_020808dc(s32, s32, s32, s32);
    u32 func_ov000_02175074();
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021ae2d0;
    extern M2C_UNK data_ov000_021c2158;
    extern M2C_UNK data_ov000_021c23ec;
    extern M2C_UNK data_ov000_021c2680;
    extern M2C_UNK data_ov000_021c2918;
    extern M2C_UNK data_ov000_021c2bb0;
    extern M2C_UNK data_ov000_021c2e50;
    void *saved;
    s32 gfx;
    M2C_UNK *gfxTable;

    gfx = M2C_FIELD(data_027e00c4, s32 *, 0x28);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    switch (func_ov000_02175074()) {
    case 0:
        gfxTable = &data_ov000_021c2e50;
        break;
    case 1:
        gfxTable = &data_ov000_021c2bb0;
        break;
    case 2:
        gfxTable = &data_ov000_021c2680;
        break;
    case 3:
        gfxTable = &data_ov000_021c23ec;
        break;
    case 4:
        gfxTable = &data_ov000_021c2918;
        break;
    case 5:
        gfxTable = &data_ov000_021c2158;
        break;
    default:
        gfxTable = &data_ov000_021c2e50;
        break;
    }
    func_0207c780(gfxTable, gfx);
    func_01ff85b8(gfx, 0x800, 0x180);
    func_020808dc(gfx, 0x20, 0x18, 0xB);
    if (M2C_FIELD(&data_ov000_021ae2d0, u32 *, M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) * 0xC) == 1) {
        func_02080860(gfx + 0x220, 4, 1, 0x304, 0xB);
        func_02080860(gfx + 0x260, 4, 1, 0x324, 0xB);
    }
    gCur3DSpriteEngine = saved;
}

void func_ov000_02175878(void *arg0) {
    void func_01ff9e44(void *, s32, s32);
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    void func_0209b26c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    extern u8 data_ov000_021ae2a0[];
    extern u8 *data_ov000_021dec34[][4];
    extern s32 data_ov000_021debc8[];
    u8 local[6];
    u8 flag;
    u8 idx;
    s32 fld;
    void *saved;
    s32 color;
    s32 base;

    local[0] = data_ov000_021ae2a0[0];
    local[1] = data_ov000_021ae2a0[1];
    local[2] = data_ov000_021ae2a0[2];
    local[3] = data_ov000_021ae2a0[3];
    local[4] = data_ov000_021ae2a0[4];
    local[5] = data_ov000_021ae2a0[5];
    fld = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x60);
    idx = (u8)(local[fld] << 5);
    color = M2C_FIELD(arg0, s32 *, 0) ? 0xA3 : 0x103;
    flag = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0) != 0;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    base = M2C_FIELD(data_027e00c4, s32 *, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0)) {
        base += 0x20;
    } else {
        base += 0xA40;
    }
    func_0207c780((M2C_UNK *)data_ov000_021dec34[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)][flag + 2], base);
    func_01ff9e44(data_ov000_021dec34[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)][flag] + idx, 0x180, 0x20);
    func_0209b26c(2, 0xD, 1, data_ov000_021debc8[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4)], 0xF000, color);
    gCur3DSpriteEngine = saved;
}

void func_ov000_021759b8(s32 *arg0) {
    M2C_UNK func_02080860(s32, s32, s32, u16, s32);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *saved;
    s32 base;
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    base = M2C_FIELD(data_027e00c4, s32 *, 0x24);
    func_02080860(base + 0xC6, 9, 9, (u16)(*arg0 ? 0x52 : 1), 0xC);
    gCur3DSpriteEngine = saved;
}

void func_ov000_02175ed8(void *arg0) {
    M2C_UNK func_02007ef4(s32, s32);
    s32 func_020e3438(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    extern s16 data_ov000_021deb46[];
    void *temp_r4;
    s16 temp_r6;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    temp_r6 = data_ov000_021deb46[M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x4)];
    if (temp_r6 != -1) {
        func_02007ef4(func_020e3438(3) + 0x4E0 * temp_r6, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2880);
    }
    func_02007ef4(func_020e3438(4) + 0x1C0 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x58), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2D60);
    func_02007ef4(func_020e3438(4) + 0x1C0 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x5C), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2F20);
    gCur3DSpriteEngine = temp_r4;
}

