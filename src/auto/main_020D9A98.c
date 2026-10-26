/* 19 functions from 0x020D9A98 to 0x020DAA90 (main), found by ds-decomp. */
#include "common.h"

void func_020d9d5c(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, u8);
    s32 func_020d4810();
    if (func_020d4810() != 0) {
        return;
    }
    func_01ffa8c4(arg0, M2C_FIELD(arg0, u8 *, 0x40));
}

void func_020d9d80(void *arg0) {
    M2C_UNK func_020808dc(u16 *, s32, s32, u32);
    M2C_UNK func_0208fe30(s32);
    extern void **gCur3DSpriteEngine;
    extern void **data_027e00c8;
    void *temp_r7;
    void **saved;
    s32 i;
    s32 r8;
    s32 r9;

    temp_r7 = M2C_FIELD(arg0, void **, 0x10);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;

    r8 = 1;
    r9 = 5;
    i = 0;
    do {
        func_020808dc((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 2 + (r8 << 6)),
                      0x1e,
                      (s32)(u16)(r9 - r8),
                      (u32)(u16)(M2C_FIELD(arg0, u8 *, 0) != i ? 5 : 6));
        { s32 nx = r8 + 5; s32 ny = r9 + 5; i++; r8 = (s16)nx; r9 = (s16)ny; }
    } while (i < 4);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = saved;

    if ((s8)M2C_FIELD(temp_r7, s8 *, 0x43) != M2C_FIELD(arg0, u8 *, 0)) {
        M2C_FIELD(temp_r7, s8 *, 0x43) = M2C_FIELD(arg0, u8 *, 0);
        func_0208fe30(0x10019);
    }
}

void func_020d9e7c(void *arg0){extern s32 data_02168f7c[]; s32 temp_r2; u16 temp_r3; void *temp_r4;
temp_r4=M2C_FIELD(arg0,void**,0x10); temp_r3=M2C_FIELD(temp_r4,u16*,0x48);
if(temp_r3&0x20)return; temp_r2=temp_r3&2; if(temp_r2!=0)return;
if(data_02168f7c[M2C_FIELD(arg0,u8*,0)]<0)return; if(temp_r2!=0)return;
M2C_FIELD(temp_r4,u16*,0x48)=temp_r3&~1;
M2C_FIELD(temp_r4,u16*,0x48)=M2C_FIELD(temp_r4,u16*,0x48)|2;
func_0208fe30(0x1000D); func_01ffa6fc(temp_r4);}

void func_020d9ee4(u8 *arg0){M2C_UNK func_020b1c60(); extern void *data_02101e84; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(data_02101e84,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(data_02101e84,u16*,0); if(temp_r1&0x40){if(temp_r3==0){if(temp_r2&0x40)var_r0=4;}else var_r0=temp_r3-1;}else if(temp_r1&0x80) var_r0=temp_r3+1; if(var_r0==temp_r3) return; func_020b1c60(var_r0); }

void func_020d9f40(void *arg0) {
    M2C_UNK func_020808dc(u16 *, s32, s32, u32);
    M2C_UNK func_0208fe30(s32);
    extern void **gCur3DSpriteEngine;
    extern void **data_027e00c8;
    void *temp_r7;
    void **saved;
    s32 i;
    s32 r9;
    s32 r10;
    s32 r8;
    s32 first_byte;
    s32 nr9;
    s32 nr10;

    temp_r7 = M2C_FIELD(arg0, void **, 0x10);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;

    r9 = 1;
    r10 = 5;
    r8 = 0;
    for (i = 0; i < 4; i++) {
        func_020808dc((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 2 + (r9 << 6)), 0x1e, (s32)(u16)(r10 - r9), 5);
        nr9 = r9 + 5;
        nr10 = r10 + 5;
        r8 = r8 + 1;
        r9 = (s16)(nr9);
        r10 = (s16)(nr10);
    }

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = saved;

    first_byte = M2C_FIELD(arg0, u8 *, 0x0);
    if ((s8)M2C_FIELD(temp_r7, s8 *, 0x43) != (u8)first_byte) {
        M2C_FIELD(temp_r7, s8 *, 0x43) = (u8)first_byte;
        func_0208fe30(0x10019);
    }
}

void func_020da008(void *arg0) {
    u16 temp_r0;
    u16 temp_r0_3;
    void *temp_r0_2;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0 & 0x20) {
        return;
    }
    if (temp_r0 & 2) {
        return;
    }
    temp_r0_2 = M2C_FIELD(temp_r4, void **, 0x5C);
    if ((s32) M2C_FIELD(temp_r0_2, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0_2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0xC;
    }
    temp_r0_3 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0_3 & 2) {
        return;
    }
    M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (temp_r0_3 | 1);
    M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x48) | 2);
    func_0208fe30(0x1000D);
    func_01ffa6fc(temp_r4);
}

void func_020da0a0(u8 *arg0){M2C_UNK func_020b1c60(); extern void *data_02101e84; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(data_02101e84,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(data_02101e84,u16*,0); if(temp_r1&0x40)var_r0=temp_r3-1;else if((temp_r1&0x80)&&(temp_r2&0x80))var_r0=0; if(var_r0==temp_r3) return; func_020b1c60(var_r0); }

// Draws two 5-step progress bars (levels x/y growing by 5) onto a UI screen, then marks it dirty.
void func_020da0ec(void *a) {
    M2C_UNK func_020808dc(u16 *, s32, s32, u32);
    M2C_UNK func_0208fe30(s32);
    extern void **gCur3DSpriteEngine, **data_027e00c8;
    void *p = M2C_FIELD(a, void **, 0x10);
    void **saved = gCur3DSpriteEngine;
    s32 i, x, y;
    gCur3DSpriteEngine = data_027e00c8;
    x = 10;
    y = 14;
    i = 0;
    do {
        func_020808dc((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 8 + (x << 6)),
                      24,
                      (u16)(y - x),
                      (u16)(M2C_FIELD(a, u8 *, 0) != i ? 7 : 8));
        { s32 nx = x + 5; s32 ny = y + 5; i++; x = (s16)nx; y = (s16)ny; }
    } while (i < 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = saved;
    if (M2C_FIELD(a, u8 *, 0) != M2C_FIELD(p, s32 *, 0x3c)) {
        M2C_FIELD(p, s32 *, 0x3c) = M2C_FIELD(a, u8 *, 0);
        func_0208fe30(0x10019);
    }
}

void func_020da1e8(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    s32 temp_r0_2;
    u16 temp_r0;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0 & 0x20) {
        return;
    }
    temp_r0_2 = temp_r0 & 4;
    if ((temp_r0_2 == 0) && (temp_r0_2 == 0)) {
        func_0208fe30(0x1000E);
        M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x48) | 4);
        func_01ffa6fc(temp_r4);
    }
}

void func_020da22c(u8 *arg0){M2C_UNK func_020b1c60(); extern void *data_02101e84; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(data_02101e84,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(data_02101e84,u16*,0); if(temp_r1&0x40){ if(temp_r3==0){if(temp_r2&0x40)var_r0=1;}else var_r0=temp_r3-1;}else if(temp_r1&0x80){if(temp_r3==1){if(temp_r2&0x80)var_r0=0;}else var_r0=temp_r3+1;} if(var_r0==temp_r3) return; func_020b1c60(var_r0); }

void func_020da3c8(void *arg0) {
    s32 temp_r0_2;
    u16 temp_r0;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0 & 0x20) {
        return;
    }
    temp_r0_2 = temp_r0 & 8;
    if ((temp_r0_2 == 0) && (temp_r0_2 == 0)) {
        func_0208fe30(0x1000E);
        M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x48) | 8);
        func_01ffa6fc(temp_r4);
    }
}

void func_020da40c(u8 *arg0){M2C_UNK func_020b1c60(); extern void *data_02101e84; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(data_02101e84,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(data_02101e84,u16*,0); if(temp_r1&0x40){ if(temp_r3==0){if(temp_r2&0x40)var_r0=1;}else var_r0=temp_r3-1;}else if(temp_r1&0x80){if(temp_r3==1){if(temp_r2&0x80)var_r0=0;}else var_r0=temp_r3+1;} if(var_r0==temp_r3) return; func_020b1c60(var_r0); }

void func_020da8e4(s32,void *);
void func_020da948(s32,M2C_UNK,u32,void *);
/* Dispatch an entity's driver based on its type field (+0x34) and sub-state (+0x38). */
void func_020da7e8(void *entity) {
    void func_020da8e4(s32, void *);
    void func_020da948(s32, M2C_UNK, u32, void *);

    switch (M2C_FIELD(entity, s32 *, 0x34)) {
    case 0:
        func_ov009_02225d88(func_020da8e4, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: func_01ffa8c4(entity, 6); break;
        case 1: func_01ffa8c4(entity, 7); break;
        }
        break;
    case 1:
        func_ov010_0222a20c(func_020da948, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: func_01ffa8c4(entity, 2); break;
        case 1: func_01ffa8c4(entity, 17); break;
        }
        break;
    case 2:
        func_ov010_0222a20c(func_020da948, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: func_01ffa8c4(entity, 12); break;
        case 1: func_01ffa8c4(entity, 13); break;
        }
        break;
    }
}

void func_020da8e4(s32 arg0, void *arg1) {
    s32 func_020abe90(u8);
    s32 func_020ad3f0();
    M2C_UNK func_020d47f0();
    M2C_UNK func_ov009_02225fb4(s8, u16, s32, void *);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    if ((func_020abe90(M2C_FIELD(arg1, u8 *, 0x44)) == 1) || (func_020ad3f0() != 0)) {
        func_ov010_022282d4(6);
        return;
    }
    if (arg0 == 0) {
        return;
    }
    func_ov009_02225fb4((s8) M2C_FIELD(arg1, u8 *, 0x44), M2C_FIELD(arg1, u16 *, 0x46), arg0, arg1);
    func_020d47f0();
    func_01ffa8c4(arg1, 1);
}

void func_020da948(s32 arg0, M2C_UNK arg1, u32 arg2, void *arg3) {
    s32 func_020abe90(u8);
    s32 func_020ad3f0(void);
    M2C_UNK func_ov009_02224528(M2C_UNK);
    void func_ov010_02228320(void);
    M2C_UNK func_ov010_0222a808(s8, u16, s32, M2C_UNK, u32, void *);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    M2C_UNK func_020d47f0(void);
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);

    if (func_020abe90(M2C_FIELD(arg3, u8 *, 0x44)) != 1) {
        if (func_020ad3f0() != 0) {
            func_ov009_02224528(1);
            return;
        }
    }
    if (arg0 == 0) {
        return;
    }
    func_ov010_0222a808((s8) M2C_FIELD(arg3, u8 *, 0x44), M2C_FIELD(arg3, u16 *, 0x46), arg0, arg1, arg2, arg3);
    func_ov010_02228320();
    switch (arg2) {
    case 0:
    case 1:
    case 2:
        func_ov010_022282d4(6);
        return;
    case 3:
    case 4:
    case 5:
    case 6:
        func_020d47f0();
        func_01ffa8c4(arg3, 1);
        return;
    default:
        return;
    }
}

void func_020daa0c(void *arg0) {
    M2C_UNK func_020a8f8c(s32);
    s32 func_020a8ff4(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
    s32 temp_r0;
    u16 temp_r3;
    void **temp_ip;

    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x68));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp_r0, 0);
    temp_ip = gCur3DSpriteEngine;
    temp_r3 = 0 - temp_r0;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(*data_027e00c8, u16 *, 0x3A) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    gCur3DSpriteEngine = temp_ip;
}

