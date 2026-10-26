/* 9 functions from 0x0216FC60 to 0x021707D8 (ov000), found by ds-decomp. */
#include "common.h"

extern u8 data_ov000_021b8a00[40];
extern u8 data_ov000_021b89d8[40];
extern u8 data_ov000_021b8a28[40];
extern u8 data_ov000_021b8a50[40];
extern u8 data_ov000_021b89b0[40];

void func_ov000_0216fc60(u8 *arg0) {
    void *func_ov000_021700fc(void);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov000_0216ecc8(s16, s16);
    M2C_UNK func_ov000_0216f8c4(s16);
    M2C_UNK func_ov000_0216f9b4(void *);
    void *p = func_ov000_021700fc();
    if (p == NULL) return;
    switch (*arg0) {
    case 0xFB: M2C_FIELD(p, s16 *, 0x34) = 0; break;
    case 0xFA: M2C_FIELD(p, s16 *, 0x34) = 1; break;
    case 0xF9: M2C_FIELD(p, s16 *, 0x34) = 2; break;
    case 0xF8: M2C_FIELD(p, s16 *, 0x34) = 3; break;
    default: return;
    }
    func_0208fe30(0x10020);
    func_ov000_0216ecc8(M2C_FIELD(p,s16 *,0x34), M2C_FIELD(p,s16 *,0x36));
    func_ov000_0216f9b4(p);
    func_ov000_0216f8c4(M2C_FIELD(p,s16 *,0x38));
}

void func_ov000_0217000c(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov000_02170020(void) {
    void *func_ov000_021700fc(void);
    M2C_UNK func_020b1bf4(s32, s32, s32, s32);
    M2C_UNK func_020b1c78(s32);
    M2C_UNK func_020b22a4(s32, s32, void *, s32);
    
    void *p;
    s32 r7;
    s16 limit;
    s32 r8;
    s32 r5;
    
    p = func_ov000_021700fc();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a00, 0xfb);
    func_020b22a4(0, 0, (void*)&data_ov000_021b89d8, 0xfa);
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a28, 0xf9);
    func_020b22a4(0, 0, (void*)&data_ov000_021b8a50, 0xf8);
    
    r7 = 0;
    limit = M2C_FIELD(p, s16 *, 0x3c);
    if (limit > 0) {
        r8 = 0x27;
        r5 = 4;
        do {
            if (r7 != 6) {
                func_020b22a4(r5, r8, (void*)&data_ov000_021b89b0, r7);
            }
            r7++;
            r8 += 0x10;
        } while (r7 < limit);
    }
    func_020b1c78(0);
}

void *func_ov000_021700fc(void) {
    void *func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov000_021b8a78;
    return func_01ffa770(&data_ov000_021b8a78);
}

void func_ov000_0217074c(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    M2C_UNK func_020e35cc(s32);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021df5e4;
    void *temp_r4;
    s32 value;
    void *next;
    next = data_027e00c8;
    temp_r4 = gCur3DSpriteEngine;
    value = M2C_FIELD(&data_ov000_021df5e4, s32 *, 4);
    gCur3DSpriteEngine = next;
    func_020e35cc(value);
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020cfd28();
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_021707c0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8a78;
    func_01ffa3dc(&data_ov000_021b8a78, 7);
}

