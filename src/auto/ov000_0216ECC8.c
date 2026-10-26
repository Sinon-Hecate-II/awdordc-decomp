/* 12 functions from 0x0216ECC8 to 0x0216FC60 (ov000), found by ds-decomp. */
#include "common.h"

/* Switch gCur3DSpriteEngine to data_027e00c8 and rebuild its display lists; bit 0 of mode selects one of two layouts. */
void func_ov000_0216f8c4(s32 mode) {
    M2C_UNK func_020809c0(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov000_0216f3d0(s32, s32);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;
    s32 var_r7_2;
    void *savedPtr;

    savedPtr = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_020809c0(M2C_FIELD(data_027e00c8, s32 *, 0x24) + 0x140, 0x20, 0xC);
    if (mode & 1) {
        var_r6 = 0;
        var_r5 = mode >> 1;
        var_r7 = -1;
        do {
            func_ov000_0216f3d0(var_r7, var_r5);
            var_r6 += 1;
            var_r5 += 1;
            var_r7 += 2;
        } while (var_r6 < 7);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x100, 0x20, 1);
        func_020809c0(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24) + 0x440, 0x20, 1);
    } else {
        var_r7_2 = 0;
        var_r6_2 = 0;
        var_r5_2 = mode >> 1;
        do {
            func_ov000_0216f3d0(var_r6_2, var_r5_2);
            var_r7_2 += 1;
            var_r5_2 += 1;
            var_r6_2 += 2;
        } while (var_r7_2 < 6);
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    gCur3DSpriteEngine = savedPtr;
}

s32 func_ov000_0216facc(void *arg0) {
    s16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x3A);
    if (temp_r1 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x3A) = (s16) (temp_r1 - 1);
    func_0208fe30(0x10019);
    return 1;
}

s16 func_ov000_0216fafc(void *a) {
s16 old=M2C_FIELD(a,s16 *,0x3a);
M2C_FIELD(a,s16 *,0x3a)=old-6;
if(M2C_FIELD(a,s16 *,0x3a)<0) M2C_FIELD(a,s16 *,0x3a)=0;
return M2C_FIELD(a,s16 *,0x3a)-old;
}

s32 func_ov000_0216fb2c(void *arg0) {
    s16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s16 *, 0x3A);
    if ((s32) (temp_r2 + 6) >= (s32) M2C_FIELD(arg0, s16 *, 0x3C)) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x3A) = (s16) (temp_r2 + 1);
    func_0208fe30(0x10019);
    return 1;
}

s16 func_ov000_0216fb64(void *a) {
s16 old=M2C_FIELD(a,s16 *,0x3a);
s32 max;
M2C_FIELD(a,s16 *,0x3a)=old+6;
max=M2C_FIELD(a,s16 *,0x3c)-6;
if(M2C_FIELD(a,s16 *,0x3a)>max) M2C_FIELD(a,s16 *,0x3a)=max;
return M2C_FIELD(a,s16 *,0x3a)-old;
}

void func_ov000_0216fb98(void *arg0) {
    M2C_UNK func_0207b764(u8, u8);
    extern void **data_027e0058;
    s16 temp_ip;
    s32 temp_r1;
    void *temp_r3;

    temp_ip = M2C_FIELD(arg0, s16 *, 0x40);
    if (temp_ip == 0) {
        return;
    }
    temp_r3 = *data_027e0058;
    temp_r1 = ((M2C_FIELD(temp_r3, u16 *, 0x52A8) + temp_ip) * 0xE) + (s32) (temp_r3 + 0x59A4);
    func_0207b764(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2));
}

void func_ov000_0216fbe4(u8 *a) {
extern M2C_UNK data_ov000_021df5e4;
s32 p=func_ov000_021700fc();
M2C_FIELD(p,s16 *,0x40)=M2C_FIELD(&data_ov000_021df5e4,u8 **,4)[M2C_FIELD(p,s16 *,0x3a)+*a];
func_0208fe30(0x10016);
func_01ffa6fc(p);
func_020b21a0();
func_020b2268();
}

void func_ov000_0216fc34(void) {
    M2C_UNK func_01ffa6fc(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b21a0();
    M2C_UNK func_020b2268();
    s32 func_ov000_021700fc();
    s32 temp_r4;

    temp_r4 = func_ov000_021700fc();
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
    func_020b21a0();
    func_020b2268();
}
