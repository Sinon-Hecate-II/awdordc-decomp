/* 6 functions from 0x020E5080 to 0x020E5824 (main), found by ds-decomp. */
#include "common.h"

void func_020e5080(M2C_UNK arg0) {
}

void func_020e5678(void) {
    M2C_UNK func_0200df70();
    M2C_UNK func_0200e868(M2C_UNK);
    M2C_UNK func_02090640(M2C_UNK, M2C_UNK);
    M2C_UNK func_020af1e4();
    func_020af1e4();
    func_02090640(2, 0x7F);
    func_0200df70();
    func_0200e868(0);
}

void func_020e569c(M2C_UNK arg0) {
 void *func_01ffa444(M2C_UNK *, M2C_UNK);
 M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
 s16 func_0207c8ec(s32, M2C_UNK);
 s32 func_020e3580(M2C_UNK, M2C_UNK);
 extern M2C_UNK data_0212da88;
 extern M2C_UNK data_0212dba0;
 extern s32 data_02168ff4, data_027e00c8, gCur3DSpriteEngine;
 s32 saved;
 void *obj;
 saved = gCur3DSpriteEngine;
 gCur3DSpriteEngine = data_027e00c8;
 obj = func_01ffa444(&data_0212da88, arg0);
 if (obj != NULL) {
 M2C_FIELD(obj, void **, 0) = &data_0212dba0;
 M2C_FIELD(obj, s32 *, 0x34) = 0;
 M2C_FIELD(obj, s32 *, 0x38) = 0;
 M2C_FIELD(obj, u8 *, 0x3C) = 0;
 M2C_FIELD(obj, s16 *, 0x3E) = func_0207c8ec(0x2BF20, 0x3E8);
 M2C_FIELD(obj, u8 *, 0x40) = 0;
 data_02168ff4 = func_020e3580(0x20, 0x20);
 func_02007f8c((u8 *)obj + 0x41, 0, 0xA);
 }
 gCur3DSpriteEngine = saved;
}

void func_020e5740(void) {
 void *func_01ffa770(M2C_UNK *);
 M2C_UNK func_01ffa8c4(void *, M2C_UNK);
 s16 func_0207c8ec(s32, M2C_UNK);
 extern M2C_UNK data_0212da88;
 u8 flags;
 void *obj;
 obj = func_01ffa770(&data_0212da88);
 if (obj == NULL) return;
 flags = M2C_FIELD(obj, u8 *, 0x3C);
 if (!(flags & 2)) {
 if (!(flags & 1)) return;
 }
 M2C_FIELD(obj, s16 *, 0x3E) = func_0207c8ec(0x2BF20, 0x3E8);
 if ((M2C_FIELD(obj, u8 *, 0x3C) &= ~1) & 2) return;
 M2C_FIELD(obj, u8 *, 0x3C) |= 2;
 func_01ffa8c4(obj, 1);
}

M2C_UNK **func_020e57b4(M2C_UNK **arg0) {
 M2C_UNK func_020e35cc();
 M2C_UNK func_02082040(M2C_UNK **);
 extern M2C_UNK data_0212dba0;
 extern s32 data_02168ff4;
 *arg0 = &data_0212dba0;
 if (data_02168ff4 != 0) func_020e35cc();
 func_02082040(arg0);
 return arg0;
}

M2C_UNK **func_020e57f0(M2C_UNK **arg0) {
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_0212dba0;
    extern s32 data_02168ff4;
    *arg0 = &data_0212dba0;
    if (data_02168ff4 != 0) {
        func_020e35cc();
    }
    return arg0;
}

