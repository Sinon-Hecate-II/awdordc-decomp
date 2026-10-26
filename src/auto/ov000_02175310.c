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
    extern s32 *data_027e0058;
    void *state;

    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 8) = statIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0x50) = templateIndex;
    M2C_FIELD(M2C_FIELD(entry, void **, 0x10), s32 *, 0) = (s32) M2C_FIELD(((templateIndex * 0x8C) + *data_027e0058), u8 *, 0x67CD);
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
    M2C_FIELD(state, s32 *, 0x60) = (s32) M2C_FIELD(((M2C_FIELD(state, s32 *, 0x50) * 0x8C) + *data_027e0058), u8 *, 0x67C1);
    func_ov000_02176af8(entry, statIndex);
    if (M2C_FIELD(entry, s32 *, 4) == 0) {
        M2C_FIELD(entry, s32 *, 4) = 1;
    }
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

