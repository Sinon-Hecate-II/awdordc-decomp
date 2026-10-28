/* 7 functions from 0x0208D408 to 0x0208E18C (main), found by ds-decomp. */
#include "common.h"

void func_0208d408(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)arg4;
}

void func_0208d8e4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)arg4; (void)arg5; (void)arg6;
}

void func_0208dd7c(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_UNK func_0208cadc(s16, s16, s16, s32, s32);
    M2C_UNK func_0208cf94(s16, s16, s16, s32, s32);
    extern void *gCur3DSpriteEngine;

    switch (arg6) {
        case 1:
            func_0208cadc(arg0, arg1, arg2, arg4, arg5);
            func_0208cadc(arg0, (s16)(arg1 + arg3 - 1), arg2, arg4, arg5);
            func_0208cf94(arg0, arg1, (s16)(arg3 - 1),
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            func_0208cf94((s16)(arg0 + arg2 - 1), arg1, (s16)(arg3 - 1),
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            break;
        case 2:
            func_0208cadc((s16)(arg0 - 1), (s16)(arg1 - 1), (s16)(arg2 + 2), arg4, arg5);
            func_0208cadc((s16)(arg0 - 1), (s16)(arg1 + arg3 - 1), (s16)(arg2 + 2), arg4, arg5);
            func_0208cf94((s16)(arg0 - 1), arg1, arg3,
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            func_0208cf94((s16)(arg0 + arg2 - 1), arg1, arg3,
                (s32)(u16)(arg4 + (0x3FF & (10 >> (((u32)*(u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) << 17) >> 30)))),
                arg5);
            break;
    }
}

void func_0208df84(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5) {
 s32 func_0207ca38(s32,s32,s32,s32,s32);
 void func_0208dd7c(s16,s16,s16,s16,s32,s32,s32);
 extern volatile u32 data_027e15bc;
 s32 n;
 n=((data_027e15bc>>1)&15)<8U ? func_0207ca38(4,0,2,(data_027e15bc>>1)&15,8):func_0207ca38(1,2,0,((data_027e15bc>>1)&15)-8,8);
 n--;
 func_0208dd7c((s16)(arg0-n),(s16)(arg1-n),(s16)(arg2+n*2),(s16)(arg3+n*2),arg4,arg5,2);
}

void func_0208e054(s32 arg0, s32 arg1, s16 arg2) {
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    extern M2C_UNK data_0211e0e4;
    extern void *gCur3DSpriteEngine;
    func_0207c780(&data_0211e0e4, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
    M2C_FIELD((M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + (((arg1 + 0x10) << 5) & ~1)), s16 *, 0x1E) = arg2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

void func_0208e0b8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_0208cf94(s16, s16, s16, s32, s32);
    func_0208cf94((s16)(arg0 - 1), (s16)(arg1 - 1), (s16)(arg2 + 2), arg3, arg4);
}

void func_0208e0f0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    M2C_UNK func_0207c780(M2C_UNK *, s32);
    extern M2C_UNK data_0211e394;
    extern void *gCur3DSpriteEngine;
    s32 temp_r3;
    func_0207c780(&data_0211e394, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg0);
    temp_r3 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + (((arg1 + 0x10) << 5) & ~1);
    M2C_FIELD(temp_r3, s16 *, 6) = arg2;
    M2C_FIELD(temp_r3, s16 *, 8) = arg3;
    M2C_FIELD(temp_r3, s16 *, 0xA) = 0x5AD6;
    M2C_FIELD(temp_r3, s16 *, 0xC) = 0x35AD;
    M2C_FIELD(temp_r3, s16 *, 0xE) = 0x4E73;
    M2C_FIELD(temp_r3, s16 *, 0x10) = 0x6F7B;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

