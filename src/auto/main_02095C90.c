/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"

void func_02095eb4(void) {
    M2C_UNK func_020af230();
    M2C_UNK func_0208232c();
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    u16 *volatile v0;
    u16 *volatile v1;
    u16 *volatile v2;
    u16 *volatile v3;
    u16 *volatile v4;
    void *saved;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020af230();
    func_0208232c();
    v0 = *(u16 **)gCur3DSpriteEngine;
    *v0 = *v0 | 0x10;
    v1 = *(u16 **)gCur3DSpriteEngine;
    *v1 = *v1 | 0x20;
    v2 = *(u16 **)gCur3DSpriteEngine;
    *v2 = *v2 | 0x40;
    v3 = *(u16 **)gCur3DSpriteEngine;
    *v3 = *v3 | 0x80;
    v4 = *(u16 **)gCur3DSpriteEngine;
    *v4 = *v4 | 0x100;
    gCur3DSpriteEngine = saved;
}

void func_02095f90(void) {

}

void func_02095f94(s32 arg0) {
void func_02095fc0(void);
M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
void func_02068c50(void *,s32);
extern M2C_UNK data_02102b18;
s32 p;
func_02095fc0();
p=func_01ffa3dc(&data_02102b18,7);
func_02068c50((u8 *)p+0x36,arg0);
}

void func_02095fc0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102b18;
    func_01ffa9e4(&data_02102b18);
}

void func_02095fd4(void) {
void *func_02091da8(void);
M2C_FIELD(func_02091da8(),s8 *,0x46)=0;
}

u8 func_02095fe8(void) {
    void *func_02091da8();
    return M2C_FIELD(func_02091da8(), u8 *, 0x46);
}

void func_02095ff8(s8 arg0) {
    M2C_FIELD(func_02091da8(), s8 *, 0x46) = arg0;
}

u8 func_0209600c(void) {
    u8 var_r0;

    if (func_02095fe8() == 1) {
        return 1U;
    }
    if (func_02095fe8() == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02096038(void) {
    u8 var_r0;

    if (func_02095fe8() == 3) {
        return 0U;
    }
    if (func_02095fe8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02096064(void) {
    extern u16 *data_02101e84;
    if (func_02096038() == 0) {
        return 0;
    }
    if (func_0209600c() != 0) {
        return 0;
    }
    if (!(*data_02101e84 & 8)) {
        return 0;
    }
    func_02095ff8(1);
    return 1;
}

void func_020960b4(void) {
    M2C_UNK func_0209cce4(M2C_UNK *, M2C_UNK);
    extern M2C_UNK func_020949f8;
    func_0209cce4(&func_020949f8, 5);
}

void func_020960cc(s32 arg0, s32 arg1, void *arg2) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = arg0 - arg1;
    M2C_FIELD(arg2, s16 *, 0) = (s16) (((u32) (temp_r0 & 0x3F) >> 1) * 8);
    M2C_FIELD(arg2, s16 *, 2) = (s16) (func_0207c8ec(temp_r0, 0x40) * 8);
}

void func_020960fc(void *arg0) {
M2C_UNK func_02091e50(void);
void func_02097c50(s32,s32,s32);
extern void *gCur3DSpriteEngine;
s16 pos[2];
func_020960cc(M2C_FIELD(arg0,s32 *,0x4c),M2C_FIELD((u8 *)gCur3DSpriteEngine+M2C_FIELD(arg0,u8 *,0x40)*4,s32 *,0x20),pos);
func_02097c50(func_02091e50(),pos[0]+M2C_FIELD(arg0,s16 *,0x4a),pos[1]);
}

void func_0209614c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_02091e50();
    M2C_UNK func_02097cb8();
    s32 func_0209dc48();
    s32 func_0209dd54();
    s32 temp_r4;
    u16 temp_r4_2;

    temp_r4 = func_0209dc48();
    temp_r4_2 = temp_r4 | func_0209dd54();
    if ((func_02096038() != 0) && (temp_r4_2 & 0x400)) {
        func_02095ff8(1);
    }
    if (!(temp_r4_2 & 0x430)) {
        return;
    }
    func_0208fe30(0x10012);
    func_02091e50();
    func_02097cb8();
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x44)();
    func_01ffa6fc(arg0);
}

void func_020962ec(void *arg0) {
    M2C_UNK func_020961b8(void *);
    M2C_UNK func_0209bfdc(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    func_0209bfdc(0, 0, M2C_FIELD(arg0, s32 *, 0x4C), 0xC0000321, (s32) M2C_FIELD(arg0, u16 *, 0x48), 0);
    func_020961b8(arg0);
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x44)();
}

void func_0209656c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02080e30(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209670c(s32, M2C_UNK);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_02102eec;
    s32 temp_r0;

    func_0200bc5c(&data_02102eec);
    temp_r0 = func_02080e30(arg0, 1);
    func_0209670c(temp_r0, arg1);
    func_020e35cc(temp_r0);
}

void func_02096b24(void) {
    M2C_UNK func_02086720();
    extern M2C_UNK data_02102e14;
    func_02086720();
    func_020948c4(&data_02102e14);
}

void func_02096b3c(void) {
    M2C_UNK func_02094704(M2C_UNK *);
    extern M2C_UNK data_02102e14;
    func_02094704(&data_02102e14);
}

void func_02096b50(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102dbc;
    func_02086720();
    func_01ffa3dc(&data_02102dbc, 7);
}

void func_02096b6c(void) {
    extern M2C_UNK data_02102d4c;
    func_02086720();
    func_01ffa3dc(&data_02102d4c, 7);
}

void func_02096b88(void) {
    extern M2C_UNK data_02102d84;
    func_02086720();
    func_01ffa3dc(&data_02102d84, 7);
}

void func_02096ba4(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
    s32 func_020d1938(s32);
    s32 func_020d273c(s32, s32);
    extern s32 *data_027e0058;
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    void *temp_r1;

    var_r5 = -1;
    var_r4 = 1;
loop_1:
    if ((func_020d1938(var_r4) != 0) && (func_020d273c(arg0, var_r4) == 0)) {
        var_r5 = var_r4;
    } else {
        var_r4 += 1;
        if (var_r4 < 5) {
            goto loop_1;
        }
    }
    var_r7 = 0x8C;
    var_r6 = 1;
    var_r8 = var_r5 * 0x8C;
    do {
        if ((func_020d273c(arg0, var_r6) != 0) && (func_020d1938(var_r6) != 0)) {
            if (var_r5 != -1) {
                temp_r0 = *data_027e0058;
                temp_r1 = var_r8 + temp_r0;
                M2C_FIELD(temp_r1, u16 *, 0x67C6) = (u16) (M2C_FIELD(temp_r1, u16 *, 0x67C6) + M2C_FIELD((temp_r0 + var_r7), u8 *, 0x67D5));
            }
            func_020c9ebc(var_r6, arg1);
        }
        var_r6 += 1;
        var_r7 += 0x8C;
    } while (var_r6 < 5);
    func_020c9b70();
}

