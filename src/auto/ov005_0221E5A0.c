/* 9 functions from 0x0221E5A0 to 0x0221F4F8 (ov005), found by ds-decomp. */
#include "common.h"

s32 func_ov005_0221eef4(void *arg0) {
    s32 func_020ad3f0(void);
    s32 func_01ffa3dc(s32 *, void *);
    extern u32 data_027e15bc;
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    extern u16 *data_02101e84;
    extern s32 data_ov005_02220ad0[];
    volatile u16 *volatile p;
    void **saved;
    void **chosen;
    s32 i;
    if (!(data_027e15bc & 3)) {
        saved = gCur3DSpriteEngine;
        i = 0;
        do {
            if (i == 0) chosen = data_027e00c8;
            else chosen = data_027e00c4;
            i++;
            gCur3DSpriteEngine = chosen;
            p = (u16 *)((u8 *)*chosen + 0x3E);
            *p = *p + 1;
        } while (i < 2);
        gCur3DSpriteEngine = saved;
    }
    if (*data_02101e84 & 8) {
        if (!func_020ad3f0()) func_01ffa3dc(data_ov005_02220ad0, arg0);
    }
}

void func_ov005_0221efac(void) {
    M2C_UNK func_ov005_0221eef4();
    func_ov005_0221eef4();
}

void func_ov005_0221efb8(void) {
    M2C_UNK func_0208f780(s32);
    extern u16 data_02168f14;
    extern void **data_027e0058;
    s32 var_r0;
    u16 temp_r1;

    var_r0 = 0x10017;
    if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF)) {
        temp_r1 = M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        if ((s32) temp_r1 <= 0xB0) {
            if (((s32) temp_r1 < 0xB0) && (temp_r1 != 0xAA)) {

            } else {
                goto block_9;
            }
        } else if ((s32) temp_r1 <= 0xB5) {
            if (temp_r1 != 0xB5) {

            } else {
                goto block_9;
            }
        } else if (temp_r1 == 0xBA) {
block_9:
            var_r0 = 0x10018;
        }
    }
    func_0208f780(var_r0);
}

void func_ov005_0221f038(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220a44;
    extern M2C_UNK data_ov005_02220a6c;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fe0;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov005_02220d50, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    func_0200bc5c(&data_ov005_02220a44);
    M2C_FIELD(temp_r0, s32 *, 0x34) = func_02081070(&data_ov005_02220a6c, 1);
}

void func_ov005_0221f3e8(void *arg0) {
    M2C_UNK func_01ffa6fc();
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    s32 temp_r1;

    if (*data_02101e84 & 0xC0B) {
        func_01ffa6fc();
        return;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        func_01ffa6fc();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r1 < 0x84) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_r1 + 1);
    }
}

void func_ov005_0221f448(void *arg0) {
    s32 func_020e35cc(s32);
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    u16 *volatile p;
    void **saved;
    s32 i;
    void **chosen;
    i = 0;
    saved = gCur3DSpriteEngine;
    do {
        if (i == 0) chosen = data_027e00c8;
        else chosen = data_027e00c4;
        i++;
        gCur3DSpriteEngine = chosen;
        p = (u16 *)((u8 *)*chosen + 0x12);
        *p = *p & ~0xC0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x53) = 0;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x40));
}

