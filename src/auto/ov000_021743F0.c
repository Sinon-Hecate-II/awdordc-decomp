/* 24 functions from 0x021743F0 to 0x02175310 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021749b4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 1;
}

void func_ov000_021749d8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 0;
}

void func_ov000_021749fc(void *arg0, s32 arg1, s32 arg2) {
    void func_ov000_02174a84(void *, s32);
    M2C_UNK func_ov000_02175310(s32);
    extern M2C_UNK data_0215d9b8;
    extern void *data_ov000_021df5fc;
    if (arg1 == 0) {
        func_ov000_02174a84(data_ov000_021df5fc, arg2);
        return;
    }
    if (((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 16) >> 31) == 1) {
        func_ov000_02174a84(data_ov000_021df5fc, arg2);
        return;
    }
    func_ov000_02175310(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void func_ov000_02174a68(void *arg0) {
    M2C_UNK func_ov000_021755b4(s32);
    func_ov000_021755b4(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void func_ov000_02174a84(void *arg0, s32 arg1) {
    M2C_UNK func_ov000_0217272c(s32);
    if (arg1 == -1) {
        M2C_FIELD(arg0, s32 *, 0xC) = 3;
        return;
    }
    func_ov000_0217272c(M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
}

void func_ov000_02174be8(void) {
    M2C_UNK func_ov000_02173f78(void *);
    extern void *data_ov000_021df5fc;
    func_ov000_02173f78(data_ov000_021df5fc);
}

void func_ov000_02174c00(void) {
    M2C_UNK func_020af1e4();
    func_020af1e4();
}

u8 func_ov000_02174c0c(void) {
    extern void *data_ov000_021df5fc;
    u8 var_r0;
    if (data_ov000_021df5fc != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_02174c2c(void) {
    s32 *func_02082028(M2C_UNK);
    void *func_ov000_02173ea8(void *);
    M2C_UNK func_01ffa3dc(void *, s32);
    extern M2C_UNK data_ov000_021b8e5c;
    extern void *data_ov000_021df5fc;
    void *var_r0;
    var_r0 = func_02082028(0x20);
    if (var_r0 != 0) {
        var_r0 = func_ov000_02173ea8(var_r0);
    }
    data_ov000_021df5fc = var_r0;
    func_01ffa3dc(&data_ov000_021b8e5c, 8);
}

void func_ov000_02174c64(void) {
    void func_ov000_021743f0(void *);
    extern void *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    func_ov000_021743f0(data_ov000_021df5fc);
}

void func_ov000_02174c88(void) {
    void func_ov000_021743ec(void *);
    void func_ov000_02173f30(void *);
    M2C_UNK func_02082040(s32);
    void func_01ffa9e4(void *);
    void func_020c127c(void);
    extern void *data_ov000_021df5fc;
    extern M2C_UNK data_ov000_021b8e5c;
    void *temp;
    if (func_ov000_02174c0c() == 0) return;
    func_ov000_021743ec(data_ov000_021df5fc);
    temp = data_ov000_021df5fc;
    if (temp != 0) {
        func_ov000_02173f30(temp);
        func_02082040((s32)temp);
    }
    data_ov000_021df5fc = 0;
    func_01ffa9e4(&data_ov000_021b8e5c);
    func_020c127c();
}

void func_ov000_02174ce8(void) {
    extern void *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(data_ov000_021df5fc, u8 *, 0x11) = 1;
}

void func_ov000_02174d10(s32 arg0, s32 arg1) {
    extern void *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(data_ov000_021df5fc, u8 *, 0x11) = 1;
    ((void (*)())func_ov000_02174a68)(data_ov000_021df5fc, arg0, arg1);
}

s32 func_ov000_02174d50(void) {
    extern void *data_ov000_021df5fc;
    s32 result;
    if (func_ov000_02174c0c() != 0) {
        result = M2C_FIELD(data_ov000_021df5fc, u8 *, 0x13);
    } else {
        result = 0;
    }
    return result;
}

s32 func_ov000_02174d78(void) {
    void func_ov000_02174ab4(void *);
    extern void *data_ov000_021df5fc;
    if (func_ov000_02174c0c() == 0) return 0;
    func_ov000_02174ab4(data_ov000_021df5fc);
    return 1;
}

s32 func_ov000_02175074(void) {
    extern void *data_ov000_021df5fc;
    return M2C_FIELD(data_ov000_021df5fc, s32 *, 0x1C);
}

/* Initialize the 0x14-byte sub-object stored at entry+0x10 (allocating it
 * and its 0x104-byte descriptor) and clear the leading fields of entry. */
void *func_ov000_02175088(void *entry) {
    s32 *func_02082028(M2C_UNK);
    s32 *alloc;

    M2C_FIELD(entry, s32 *, 0) = 0;
    M2C_FIELD(entry, s32 *, 4) = 0;
    M2C_FIELD(entry, s32 *, 8) = 0;
    M2C_FIELD(entry, s8 *, 0xC) = 0;
    alloc = func_02082028(0x104);
    M2C_FIELD(entry, s32 **, 0x10) = alloc;
    *alloc = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x18) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x1C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x58) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x5C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x48) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x50) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x54) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x60) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xFC) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x100) = 0;
    return entry;
}

void *func_ov000_0217519c(void *arg0) {
    M2C_UNK func_02082040(s32);
    func_02082040(M2C_FIELD(arg0, s32 *, 0x10));
    return arg0;
}

void func_ov000_021751b4(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02175230(void) {

}

void func_ov000_02175234(void *arg0){
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    void *saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 16), s32 *, 8) <= 0) {
        return;
    }

    switch (M2C_FIELD(arg0, s32 *, 4)) {
        case 1:
            func_020809c0(M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), 32, 32);
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 2:
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 0:
            M2C_FIELD(arg0, s32 *, 8)++;
            if (M2C_FIELD(arg0, s32 *, 8) >= 80) {
                M2C_FIELD(arg0, s32 *, 8) = 0;
            }
            if (M2C_FIELD(arg0, s32 *, 8) == 0 || M2C_FIELD(arg0, s32 *, 8) == 40) {
                func_ov000_02176a9c(arg0);
            }
            break;
    }

    func_ov000_02175fb0(arg0);
    gCur3DSpriteEngine = saved;
}

