/* 7 functions from 0x02175FB0 to 0x02176E28 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021769dc(void *arg0) {
    M2C_UNK func_ov000_02175878(void *);
    M2C_UNK func_ov000_02175ed8(void *);
    void *temp_r2;
    temp_r2 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(temp_r2, s32 *, 4) = M2C_FIELD(temp_r2, s32 *, 8);
    func_ov000_02175ed8(arg0);
    func_ov000_02175878(arg0);
    M2C_FIELD(arg0, s32 *, 0) = 1 - M2C_FIELD(arg0, s32 *, 0);
}

void func_ov000_02176a0c(M2C_UNK arg0) {
    M2C_UNK func_ov000_02175740(M2C_UNK);
    M2C_UNK func_ov000_021759b8(M2C_UNK);
    M2C_UNK func_ov000_02175a20(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x38) = 2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x40) = 1;
    func_ov000_02175740(arg0);
    func_ov000_021759b8(arg0);
    func_ov000_02175a20(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02176a9c(M2C_UNK arg0) {
    M2C_UNK func_ov000_02175740();
    M2C_UNK func_ov000_02175a20(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_ov000_02175740();
    func_ov000_02175a20(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = temp_r4;
}

u8 func_ov000_02176dcc(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0xC) == 0) {
        return 0U;
    }
    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02176e08(s32 arg0) {
    switch (arg0) {
    case 0xE:
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 0;
    }
}

