/* 7 functions from 0x021E3500 to 0x021E4448 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e3500(void *arg0) {
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    M2C_UNK func_0208ae88(void *, M2C_UNK);
    void *func_0208b564(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020c9100(void *);
    M2C_UNK func_020c9120(u16, s32);
    M2C_UNK func_ov003_021f1894();
    u32 func_ov003_021f2574();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    void func_01ffa6fc(void *);

    register void *r5 asm("r5");
    register s32 r6 asm("r6");
    register u8 r4 asm("r4");

    u32 x;
    u8 cnt;
    u8 i;
    u8 j;
    unsigned long base;
    void *temp_r6;
    u8 temp_r1;

    r5 = arg0;
    x = func_ov003_021f2574();
    cnt = 0;
    i = 0;
    base = M2C_FIELD(r5, s32 *, 0x6C);
    r6 = base;
    r4 = 0;
    do {
        if (M2C_FIELD(r6 + ((s32)r4 * 0x6F8), u8 *, 0x27) != 0) {
            cnt = (u8)(cnt + 1);
        }
        r4 = (u8)(r4 + 1);
    } while (r4 < 5);
    if (x >= (u32)cnt) {
        x = (u32)cnt;
    }
    if (x != 0) {
        func_020c9100(r5);
        i = 0;
        do {
            func_020c9120(
                M2C_FIELD(M2C_FIELD(r5, s32 *, 0x5C) + ((s32)i * 2), u16 *, 0x12),
                base + ((s32)i * 0x6F8));
            temp_r1 = (u8)(((M2C_FIELD(r5, u8 *, 0x60) | 0x40) & ~0x30) | 0x20);
            M2C_FIELD(r5, u8 *, 0x60) = temp_r1;
            switch ((u32)((u32)temp_r1 << 0x1A) >> 0x1E) {
            case 0:
                temp_r6 = func_0208b564(r5);
                func_020899cc(temp_r6, 3, func_ov003_021f1894() << 5, 0x47000023);
                M2C_FIELD(temp_r6, s32 *, 0x58) = M2C_FIELD(temp_r6, s32 *, 0x58) | 0x400;
                func_0208ae88(temp_r6, 0);
                break;
            case 1:
                temp_r6 = func_0208b564(r5);
                func_020899cc(temp_r6, 3, func_ov003_021f1894() << 5, 0x47000024);
                M2C_FIELD(temp_r6, s32 *, 0x58) = M2C_FIELD(temp_r6, s32 *, 0x58) | 0x400;
                func_0208ae88(temp_r6, 1);
                break;
            }
            i = (u8)(i + 1);
            x = func_ov003_021f2574();
            cnt = 0;
            j = 0;
            base = M2C_FIELD(r5, s32 *, 0x6C);
            r6 = base;
            r4 = 0;
            do {
                if (M2C_FIELD(r6 + ((s32)r4 * 0x6F8), u8 *, 0x27) != 0) {
                    cnt = (u8)(cnt + 1);
                }
                r4 = (u8)(r4 + 1);
            } while (r4 < 5);
            if (x >= (u32)cnt) {
                x = (u32)cnt;
            }
        } while (i < (u8)x);
        return;
    }
    func_0208fe30(0x1000E);
    if (M2C_FIELD(r5, u8 *, 0x39) != 0) {
        func_02088da8(M2C_FIELD(r5, s32 *, 0x4C));
    }
    func_ov003_021f140c(2);
    M2C_FIELD(r5, s8 *, 0x38) = 0;
    func_01ffa6fc(r5);
    func_ov003_021f1bd4();
}

void func_ov003_021e36cc(void *arg0) {
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    func_ov003_021f1bd4();
    if (M2C_FIELD(arg0, u8 *, 0x39) != 0) {
        func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e3708(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}

void func_ov003_021e3714(void *arg0) {
    u8 func_ov003_021e1500(s32, s32, s32);
    s32 func_0207c928(s32, s32);
    void *func_020be120(void);
    void func_02007ef4(void *, void *, u32);
    void func_020ceb48(void);
    void func_020cf278(s32);
    void func_020cf0a8(s32);
    void func_020809c0(u16 *, s32, s32);
    void func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    void func_01ff9ce8(void);
    void func_020c12f8(s32, M2C_UNK, s32, s32);
    s32 func_020c1878(void *);

    extern void **gCurrentMap;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;

    s32 id;
    u16 value;
    u8 kind;
    void *dest;
    u16 *savedEngine;
    u8 *eng;
    void *ptr;
    u8 b0;
    u16 arg5;
    u8 b1;
    s32 mul;
    u8 bb;
    u8 cond;
    void *p5c;

    id = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x06);
    value = (u16)0;

    if (func_ov003_021e1500(id, 0, 4)) {
        value = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + id * 2 + 0x08);
        return;
    }
    if (!func_ov003_021e1500(id, 5, 9)) {
        return;
    }

    value = (u16)(id + 0x10E);
    kind = (u8)func_0207c928(id, 5);
    if (id < 5) {
        dest = (void *)((u8 *)arg0 + 0x68 + kind * 0x6F8);
    } else {
        dest = (void *)((u8 *)arg0 + 0x6C + kind * 0x6F8);
    }
    func_02007ef4(dest, func_020be120(), 0x6F8);

    func_020ceb48();
    func_020cf278(value);
    func_020cf0a8(value);

    *(u16 *)((u8 *)arg0 + 0x62) = (u16)(*(u16 *)((u8 *)*gCurrentMap + 0x5144) << 2);
    *(u16 *)((u8 *)arg0 + 0x64) = (u16)(*(u16 *)((u8 *)*gCurrentMap + 0x5146) << 2);

    savedEngine = *gCur3DSpriteEngine;
    *gCur3DSpriteEngine = *data_027e00c4;

    func_020809c0((u16 *)((u8 *)*gCur3DSpriteEngine + 0x2C), 9, 2);

    b0 = *(u8 *)((u8 *)arg0 + 0x60);
    arg5 = (u16)(((b0 >> 2) & 3) << 4) + 1;

    ptr = (void *)((u8 *)((id < 5) ? ((u8 *)arg0 + 0x68) : ((u8 *)arg0 + 0x6C)) + kind * 0x6F8 + 6);
    func_0209b2b4(0, 0, 3, ptr, 0x9000, arg5);
    func_01ff9ce8();

    eng = (u8 *)*gCur3DSpriteEngine;
    *(eng + 0x46) |= 0x08;

    b1 = *(u8 *)((u8 *)arg0 + 0x60);
    mul = (((b1 >> 2) & 3) * 0x142) + 1;
    func_020c12f8((s32)(eng + 0x0C), (s32)(eng + 0x20), mul, 5);

    bb = *(u8 *)((u8 *)arg0 + 0x60);
    cond = (((bb >> 2) & 3) == 0) ? 1 : 0;
    *(u8 *)((u8 *)arg0 + 0x60) = (u8)((bb & ~0x0C) | (cond << 2));

    eng = (u8 *)*gCur3DSpriteEngine;
    *(eng + 0x46) |= 0x01;

    *gCur3DSpriteEngine = savedEngine;

    p5c = *(void **)((u8 *)arg0 + 0x5C);
    func_020c1878((u8 *)p5c + 0x1C);
}

void func_ov003_021e3960(void *arg0, s16 arg1, s16 arg2) {
    s32 func_0207c8ec(s32, s32);
    s32 func_0207c928(s32, s32);
    void func_020a92bc(void *, s16);
    void func_020a94fc(void *);
    s32 func_020c1980(void *, s32, s32);
    s32 func_ov003_02200ae8(u8);
    void func_01ffaacc(u16, u8, u16, void *, s32);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;
    extern u8 data_027e0074[];
    s32 sp14, sp10, spC, sp8, sp4;
    s16 x, y, value;
    void *p;
    s32 i, palette, tile;
    u16 **old;

    sp4 = arg1;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = (s16)(0 - arg1);
    i = 0;
    tile = 0x210;
    sp8 = arg2;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    spC = -1;
    sp14 = 0x1FF;
    sp10 = 0x3FF;
    do {
        x = (s16)(func_0207c928(i, 3) * 0x16 + sp4);
        y = (s16)(func_0207c8ec(i, 3) * 0x1C + sp8);
        p = M2C_FIELD(arg0, void **, 0x5C);
        value = (s16)func_020c1980((void *)((char *)p + 0x1C), func_ov003_02200ae8((u8)i), spC);
        if (value != 0) {
            old = gCur3DSpriteEngine;
            gCur3DSpriteEngine = data_027e00c4;
            func_020a92bc(M2C_FIELD(arg0, void **, 0x54), value);
            p = M2C_FIELD(arg0, void **, 0x54);
            M2C_FIELD(p, s16 *, 6) = (s16)(x + 0x14);
            M2C_FIELD(p, s16 *, 8) = (s16)(y + 0x66);
            func_020a94fc(M2C_FIELD(arg0, void **, 0x54));
            gCur3DSpriteEngine = old;
        }
        palette = (value != 0) ? 7 : 8;
        func_01ffaacc((u16)((x + 4) & sp14),
                      (u8)(y + 0x4E),
                      (u16)(((sp10 & (tile >> ((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1E))) |
                             (u16)(palette << 0xC)) | 0x400),
                      data_027e0074,
                      0x11);
        tile += 8;
        i++;
    } while (i < 8);
}

void func_ov003_021e3aec(void *arg0) {
    (void)arg0;
}

