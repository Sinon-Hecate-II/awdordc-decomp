/* 8 functions from 0x021FBCF8 to 0x021FCB70 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021fbcf8(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020ab664(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    s16 temp_r4;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x4C);
    temp_r4 = (s16) M2C_FIELD(temp_r0, s32 *, 0x14);
    func_020ab664(temp_r0, arg1, arg2, 1);
    if (temp_r4 == (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14)) {
        return;
    }
    func_ov003_021f92f4(arg0, 0);
    func_0208fe30(0x10019);
}

void func_ov003_021fc820(void) {
    s32 func_02084d3c(s32 *, M2C_UNK);
    M2C_UNK func_02084d88(s32 *, M2C_UNK);
    M2C_UNK func_02084e74();
    s32 buffer[9];

    if (func_02084d3c(buffer, 0x24) == 0) {
        return;
    }
    buffer[0] = 1;
    func_02084d88(buffer, 0x24);
    func_02084e74();
}

void func_ov003_021fc860(void *arg0) {
    M2C_UNK func_ov003_021f1be8(M2C_UNK);
    void func_ov003_021fc95c(void *);
    s32 func_02084644(void);
    s32 func_020846a4(void);
    M2C_UNK func_0208fe30(s32);
    void func_020d47f0(void);

    void *p;
    s8 sb;
    u8 ub;
    u32 x;
    s32 a;
    s32 b;
    s32 c;
    s32 special;
    s32 result;

    p = M2C_FIELD(arg0, void **, 0x68);
    p = M2C_FIELD(p, void **, 0xC);
    sb = M2C_FIELD(p, s8 *, 0x5A);
    if (sb >= 0) {
        ub = M2C_FIELD(p, u8 *, 0x59);
        M2C_FIELD(p, s32 *, 0x40) = (s32) ((M2C_FIELD(p, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (ub << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(p, u8 *, 0x5A) = 0xC;
        func_ov003_021f1be8(p);
        func_ov003_021fc95c(arg0);
    }

    x = (u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C;
    result = 1;
    special = 1;
    if ((s32) x == 6) {
        a = 1;
    } else {
        a = 0;
    }
    if (!(a & 0xFF)) {
        if ((s32) x == 7) {
            b = 1;
        } else {
            b = 0;
        }
        if (!(b & 0xFF)) {
            special = 0;
        }
    }
    if (special == 0) {
        if ((s32) x == 8) {
            c = 1;
        } else {
            c = 0;
        }
        if (!(c & 0xFF)) {
            result = 0;
        }
    }

    if (result == 0) {
        if ((s32) x == 4) {
            result = (func_02084644() == 2) ? 1 : 0;
        } else {
            result = 0;
        }
    }

    if (result != 0) {
        if (func_020846a4() != 0) {
            return;
        }
    }
    func_0208fe30(0x1000F);
    func_020d47f0();
}

void func_ov003_021fc95c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    func_02088da8(*M2C_FIELD(arg0, s32 **, 0x6C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021fc98c(void *arg0, u32 arg1) {
    void *func_0208b564(void *);
    void func_020899cc(void *, s32, s32, u32);
    u8 byte;
    u32 low;
    u32 tmp;
    u32 sw;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;

    byte = M2C_FIELD(arg0, u8 *, 0x3E);
    low = arg1 & 0xFFu;
    low = low << 0x1Du;
    tmp = (u32)byte | 0x40u;
    tmp = tmp & ~0x38u;
    M2C_FIELD(arg0, u8 *, 0x3E) = (u8)(tmp | (low >> 0x1Au));
    sw = arg1;
    switch (sw) {
    default:
    case 0:
    case 1:
    case 2:
        return;
    case 3:
        temp_r0 = func_0208b564(arg0);
        func_020899cc(temp_r0, 3, 0xDC00, 0x4200001D);
        M2C_FIELD(temp_r0, s32 *, 0x58) = M2C_FIELD(temp_r0, s32 *, 0x58) | 0x400;
        return;
    case 4:
        temp_r0_2 = func_0208b564(arg0);
        func_020899cc(temp_r0_2, 2, 0xDC00, 0x4700001E);
        M2C_FIELD(temp_r0_2, s32 *, 0x58) = M2C_FIELD(temp_r0_2, s32 *, 0x58) | 0x400;
        return;
    case 5:
        temp_r0_3 = func_0208b564(arg0);
        func_020899cc(temp_r0_3, 2, 0xDC00, 0x47000020);
        M2C_FIELD(temp_r0_3, s32 *, 0x58) = M2C_FIELD(temp_r0_3, s32 *, 0x58) | 0x400;
        return;
    case 6:
        temp_r0_4 = func_0208b564(arg0);
        func_020899cc(temp_r0_4, 2, 0xDC00, 0x47000021);
        M2C_FIELD(temp_r0_4, s32 *, 0x58) = M2C_FIELD(temp_r0_4, s32 *, 0x58) | 0x400;
        return;
    }
}

void func_ov003_021fca84(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_020c8e40();
    s32 func_020d4810();
    extern void *gCur3DSpriteEngine;
    u32 temp_r0_2;
    u8 temp_r0;
    u8 temp_r1;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x3E);
    if (((u32) (temp_r0 << 0x19) >> 0x1F) == 0) {
        return;
    }
    temp_r1 = temp_r0 & ~0x40;
    temp_r0_2 = (u32) (temp_r1 << 0x1A) >> 0x1D;
    M2C_FIELD(arg0, u8 *, 0x3E) = temp_r1;
    switch (temp_r0_2) {
    default:
        return;
    case 0:
        if (func_020d4810() == 0) {
            return;
        }
        func_01ff9ce8(0);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
        func_02007f8c(M2C_FIELD(arg0, s32 *, 0x44) + 0x186C, 0, 0xD);
        func_020c8e40();
        func_ov003_021f92f4(arg0, 0);
        return;
    case 1:
    case 2:
        if (func_020d4810() == 0) {
            return;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(), 0x1C)();
        return;
    case 3:
        if (func_020d4810() == 0) {
            return;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(), 0x20)();
        return;
        return;
    }
}

