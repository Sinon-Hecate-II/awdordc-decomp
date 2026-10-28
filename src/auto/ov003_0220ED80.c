/* 3 functions from 0x0220ED80 to 0x0220F0B8 (ov003), found by ds-decomp. */
#include "common.h"

void func_02082040(void *arg0);
void func_0208204c(void *arg0);
void func_020e35cc(void *arg0);
void func_01ffa574(void *arg0);
void func_020af71c(void);
typedef void (*VFn)(void *);
void *func_ov003_0220ed80(void *arg0) {
    extern M2C_UNK data_ov003_02211060;
    extern u8 data_0215d9b8[8];
    void *r6 = arg0;
    u8 h;
    u8 cond;
    s32 i;
    void *p;

    M2C_FIELD(r6, M2C_UNK **, 0) = &data_ov003_02211060;

    h = (u8)(((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (cond) {
        void *s = M2C_FIELD(r6, void **, 0x40);
        u32 x;
        x = M2C_FIELD(s, u32 *, 0x4);
        x = (x << 16) >> 16;
        x = x << 30;
        x = x >> 18;
        x = (M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x3000U) | x;
        M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16)x;

        x = M2C_FIELD(s, u32 *, 0x1C);
        x = (x << 16) >> 16;
        x = x << 30;
        x = x >> 20;
        x = (M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x0C00U) | x;
        M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16)x;

        x = M2C_FIELD(s, u32 *, 0x34);
        x = (x << 16) >> 16;
        x = x << 31;
        x = x >> 17;
        x = (M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x4000U) | x;
        M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16)x;
    }

    h = (u8)(((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (!cond) {
        cond = (h == 2);
        if (cond) {
            void *s = M2C_FIELD(r6, void **, 0x3C);
            u8 v;
            M2C_FIELD(s, u8 *, 0xF) = M2C_FIELD(r6, u8 *, 0x39);
            v = M2C_FIELD(s, u8 *, 0xF);
            M2C_FIELD(s, u8 *, v) = M2C_FIELD(r6, u8 *, 0x3A);
        }
    }

    p = M2C_FIELD(r6, void **, 0x4C);
    if (p != NULL) {
        void *q = M2C_FIELD(p, void **, 0x18);
        if (q != NULL) {
            if (M2C_FIELD(q, M2C_UNK *, 0) != 0) {
                func_02082040(M2C_FIELD(q, void **, 0));
            }
            func_02082040(q);
        }
        q = M2C_FIELD(p, void **, 0x1C);
        if (q != NULL) {
            if (M2C_FIELD(q, M2C_UNK *, 0) != 0) {
                func_02082040(M2C_FIELD(q, void **, 0));
            }
            func_02082040(q);
        }
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x48);
    if (p != NULL) {
        u8 *base = (u8 *)p;
        for (i = 0; i < 6; i++) {
            u8 *entry = base + i * 0x24;
            void *q;
            q = M2C_FIELD(entry, void **, 0x18);
            if (q != NULL) {
                if (M2C_FIELD(q, M2C_UNK *, 0) != 0) {
                    func_02082040(M2C_FIELD(q, void **, 0));
                }
                func_02082040(q);
            }
            q = M2C_FIELD(entry, void **, 0x1C);
            if (q != NULL) {
                if (M2C_FIELD(q, M2C_UNK *, 0) != 0) {
                    func_02082040(M2C_FIELD(q, void **, 0));
                }
                func_02082040(q);
            }
            q = M2C_FIELD(entry, void **, 0x20);
            if (q != NULL) {
                if (M2C_FIELD(q, M2C_UNK *, 0) != 0) {
                    func_02082040(M2C_FIELD(q, void **, 0));
                }
                func_02082040(q);
            }
        }
        func_0208204c(p);
    }

    p = M2C_FIELD(r6, void **, 0x50);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x54);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x58);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x5C);
    if (p != NULL) {
        void *q = M2C_FIELD(p, void **, 0x14);
        if (q != NULL) func_020e35cc(q);
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x60);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x64);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x68);
    if (p != NULL) {
        s32 off;
        for (off = 0; off <= 0x14; off += 4) {
            void *q = M2C_FIELD(p, void **, off);
            if (q != NULL) func_01ffa574(q);
        }
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x40);
    if (p != NULL) func_02082040(p);

    func_020af71c();
    return r6;
}

void *func_ov003_0220f080(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    return arg0;
}

void func_ov003_0220f0b4(void) {

}
