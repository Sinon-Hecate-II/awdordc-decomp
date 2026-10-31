/* 4 functions from 0x0220DE5C to 0x0220ED80 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_0220de5c(void *a) { }

void func_ov003_0220ea28(void *arg0) {
    extern u8 data_ov003_02211060[];
    extern u8 data_0215d9b8[];
    M2C_UNK func_02082040();
    M2C_UNK func_0208204c();
    M2C_UNK func_020e35cc();
    M2C_UNK func_01ffa574();
    M2C_UNK func_020af71c();

    u8 *r6 = (u8 *)arg0;
    u8 v;
    u8 b1;
    u8 b2;
    u8 *p40, *p4c, *p48;
    s32 r4;
    s32 r5;
    void **vt;
    u8 **arr;
    s32 i;
    u8 *p;
    u8 *p60, *p64, *p5c;

    *(void **)r6 = (void *)data_ov003_02211060;

    v = r6[0x36];
    v = (v >> 4) & 0x0f;
    b1 = (v == 1);
    if (b1) {
        u16 *g = (u16 *)data_0215d9b8;
        u32 *pp = *(u32 **)(r6 + 0x40);
        u32 a = pp[1];
        u32 c = pp[7];
        u32 d = pp[13];
        u16 t = g[3];
        t = (u16)((t & ~0x3000) | ((a & 0x3) << 12));
        g[3] = t;
        t = g[3];
        t = (u16)((t & ~0x0c00) | ((c & 0x3) << 10));
        g[3] = t;
        t = g[3];
        t = (u16)((t & ~0x4000) | ((d & 0x1) << 14));
        g[3] = t;
    }

    v = (r6[0x36] >> 4) & 0x0f;
    b1 = (v == 1);
    if (b1) {
    } else {
        b2 = (v == 2);
        if (b2) {
            u8 mode = r6[0x39];
            u8 *dst = *(u8 **)(r6 + 0x3c);
            u8 idx;
            u8 val;
            dst[0x0f] = mode;
            idx = dst[0x0f];
            val = r6[0x3a];
            dst[idx] = val;
        }
    }

    p4c = *(u8 **)(r6 + 0x4c);
    if (p4c != 0) {
        p = *(u8 **)(p4c + 0x18);
        if (p != 0) {
            u8 *q = *(u8 **)(p + 0x00);
            if (q != 0) func_02082040((M2C_UNK)q);
            func_02082040((M2C_UNK)p);
        }
        p = *(u8 **)(p4c + 0x1c);
        if (p != 0) {
            u8 *q = *(u8 **)(p + 0x00);
            if (q != 0) func_02082040((M2C_UNK)q);
            func_02082040((M2C_UNK)p);
        }
        func_02082040((M2C_UNK)p4c);
    }

    p48 = *(u8 **)(r6 + 0x48);
    r5 = 0;
    r4 = 0;
    for (; r4 < 6; r4++, r5 += 0x24) {
        u8 *slot = p48 + r5;
        p = *(u8 **)(slot + 0x18);
        if (p != 0) {
            u8 *q = *(u8 **)(p + 0x00);
            if (q != 0) func_02082040((M2C_UNK)q);
            func_02082040((M2C_UNK)p);
        }
        p = *(u8 **)(slot + 0x1c);
        if (p != 0) {
            u8 *q = *(u8 **)(p + 0x00);
            if (q != 0) func_02082040((M2C_UNK)q);
            func_02082040((M2C_UNK)p);
        }
        p = *(u8 **)(slot + 0x20);
        if (p != 0) {
            u8 *q = *(u8 **)(p + 0x00);
            if (q != 0) func_02082040((M2C_UNK)q);
            func_02082040((M2C_UNK)p);
        }
    }

    p48 = *(u8 **)(r6 + 0x48);
    if (p48 != 0) func_0208204c((M2C_UNK)p48);

    p = *(u8 **)(r6 + 0x50);
    if (p != 0) func_02082040((M2C_UNK)p);
    p = *(u8 **)(r6 + 0x54);
    if (p != 0) func_02082040((M2C_UNK)p);
    p = *(u8 **)(r6 + 0x58);
    if (p != 0) func_02082040((M2C_UNK)p);

    p5c = *(u8 **)(r6 + 0x5c);
    if (p5c != 0) {
        u8 *p14 = *(u8 **)(p5c + 0x14);
        if (p14 != 0) func_020e35cc((M2C_UNK)p14);
        func_02082040((M2C_UNK)p5c);
    }

    p60 = *(u8 **)(r6 + 0x60);
    if (p60 != 0) {
        vt = (void **)p60;
        if (vt[0] != 0 && ((void (**)())vt[0])[1] != 0) {
            void (*fn)(void *) = ((void (**)())vt[0])[1];
            fn(p60);
        }
    }

    p64 = *(u8 **)(r6 + 0x64);
    if (p64 != 0) {
        vt = (void **)p64;
        if (vt[0] != 0 && ((void (**)())vt[0])[1] != 0) {
            void (*fn)(void *) = ((void (**)())vt[0])[1];
            fn(p64);
        }
    }

    {
        u8 *p68 = *(u8 **)(r6 + 0x68);
        if (p68 != 0) {
            arr = (u8 **)p68;
            for (i = 0; i < 6; i++) {
                u8 *q = arr[i];
                if (q != 0) func_01ffa574((M2C_UNK)q);
            }
            func_02082040((M2C_UNK)p68);
        }
    }

    p40 = *(u8 **)(r6 + 0x40);
    if (p40 != 0) func_02082040((M2C_UNK)p40);

    func_020af71c();
    func_02082040((M2C_UNK)r6);
}

void *func_ov003_0220ed30(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    M2C_UNK func_02082040();
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    func_02082040(arg0);
    return arg0;
}

s32 func_ov003_0220ed6c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}
