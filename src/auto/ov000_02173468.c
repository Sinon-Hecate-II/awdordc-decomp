/* 6 functions from 0x02173468 to 0x021743F0 (ov000), found by ds-decomp. */
#include "common.h"

u8 func_ov000_02173e6c(void *arg0) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x14) == 0) {
        return 0U;
    }
    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void *func_ov000_02173ea8(void *a){s32 p;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,8)=1;M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,u8 *,16)=0;M2C_FIELD(a,u8 *,17)=1;M2C_FIELD(a,u8 *,18)=0;M2C_FIELD(a,u8 *,19)=0;M2C_FIELD(a,u8 *,20)=0;M2C_FIELD(a,s16 *,22)=-1;M2C_FIELD(a,s16 *,24)=-1;M2C_FIELD(a,u8 *,26)=255;p=func_02082028(20);if(p)p=func_ov000_02175088(p);M2C_FIELD(a,s32 *,0)=p;p=func_02082028(28);if(p)p=func_ov000_021724dc(p);M2C_FIELD(a,s32 *,4)=p;M2C_FIELD(a,s32 *,28)=func_020e31e0();return a;}

void *func_ov000_02173f30(void *arg0) {
    M2C_UNK func_02082040(s32);
    M2C_UNK func_ov000_021725c8(s32);
    M2C_UNK func_ov000_0217519c(s32);
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r4 != 0) {
        func_ov000_0217519c(temp_r4);
        func_02082040(temp_r4);
    }
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r4_2 != 0) {
        func_ov000_021725c8(temp_r4_2);
        func_02082040(temp_r4_2);
    }
    return arg0;
}

void func_ov000_02173f78(void *arg0) {
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007ef4(s32, s32, s32);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080c50(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_020985b0(u8, s32, s32);
    M2C_UNK func_02098a34(u8, M2C_UNK, M2C_UNK, u16, s32);
    s32 func_020a7278();
    s32 func_020a7290();
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020ad150(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_020af19c(M2C_UNK, M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern s32 *data_027e0058;
    extern void *data_027e00c4;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov000_021b8e48;
    extern M2C_UNK data_ov000_021b8e50;
    extern M2C_UNK data_ov000_021b8e8c;
    extern M2C_UNK data_ov000_021b8ea0;
    extern M2C_UNK data_ov000_021b8eb0;
    extern M2C_UNK data_ov000_021b8ebc;
    extern M2C_UNK data_ov000_021b8ec8;
    extern M2C_UNK data_ov000_021b8ed4;
    extern M2C_UNK data_ov000_021b8ee8;
    extern M2C_UNK data_ov000_021b8ef4;
    extern M2C_UNK data_ov000_021b8f00;
    extern M2C_UNK data_ov000_021b8f0c;
    extern M2C_UNK data_ov000_021b8f1c;
    extern M2C_UNK data_ov000_021b8f2c;
    extern M2C_UNK data_ov000_021b8f3c;
    extern M2C_UNK data_ov000_021b8f4c;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 *sp8;
    void *sp4;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r9;
    u16 *temp_r2;
    u16 *temp_r2_2;
    u16 *temp_r2_3;
    u16 *temp_r2_4;
    u16 *temp_r2_5;
    u16 *temp_r2_6;
    u16 var_r8;
    u8 temp_r1;
    u8 var_r0;

    M2C_FIELD(arg0, s32 *, 8) = 1;
    sp4 = data_027e01d8;
    data_027e01d8 = data_027e00c4;
    func_020822b8(&data_ov000_021b8e50);
    temp_r2 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp1C = temp_r2;
    *temp_r2 = *sp1C & ~0x10;
    temp_r2_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp18 = temp_r2_2;
    *temp_r2_2 = *sp18 & ~0x20;
    temp_r2_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp14 = temp_r2_3;
    *temp_r2_3 = *sp14 & ~0x40;
    temp_r2_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp10 = temp_r2_4;
    *temp_r2_4 = *sp10 | 0x80;
    temp_r2_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
    spC = temp_r2_5;
    *temp_r2_5 = *spC & ~0x100;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s16 *, 0x44) = 0;
    temp_r2_6 = M2C_FIELD(data_027e01d8, u16 **, 0);
    sp8 = temp_r2_6 + 0x12;
    M2C_FIELD(temp_r2_6, s16 *, 0x12) = (s16) (*sp8 & ~0xC0);
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(data_027e01d8, u16 **, 0), s8 *, 0x53) = 0;
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 1);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 2);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 4);
    func_020af19c(3, 0xE);
    func_02007e98(0, M2C_FIELD(data_027e01d8, s32 *, 0xC), 0x40);
    var_r8 = 0;
    do {
        temp_r9 = ((var_r8 + 1) * 0x8C) + (*data_027e0058 + 0x67A4);
        if (M2C_FIELD(temp_r9, u8 *, 0x1E) != 0) {
            temp_r1 = (u8) M2C_FIELD(temp_r9, s32 *, 0x6C);
            func_020985b0(temp_r1, 0, M2C_FIELD(data_027e01d8, s32 *, 0xC) + (*(&data_ov000_021b8e48 + (var_r8 * 2)) << 6));
            if (M2C_FIELD(temp_r9, u8 *, 0x1C) != 0) {
                var_r0 = 8;
            } else {
                var_r0 = 0;
            }
            func_02098a34(temp_r1, 0, 2, var_r8, (s32) var_r0);
        }
        var_r8 += 1;
    } while ((s32) var_r8 < 4);
    func_0200bc5c(&data_ov000_021b8e8c);
    func_020e3218(&data_ov000_021b8ea0);
    func_020814e4();
    func_02081590(func_020e3218(&data_ov000_021b8eb0), M2C_FIELD(data_027e00c4, s32 *, 0x14));
    func_02081590(func_020e3218(&data_ov000_021b8ebc), M2C_FIELD(data_027e00c4, s32 *, 0x14) + 0x3000);
    func_0208ca2c(0x800, 1, func_020ae22c(9), 2);
    func_020a9a30(1, 0, 0, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x1000);
    func_020a9a30(1, 0, 2, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x1180);
    func_02081590(func_020e3218(&data_ov000_021b8ec8), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x1400);
    func_02080c50(&data_ov000_021b8ed4, M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    temp_r5 = func_020a7290() << 5;
    temp_r4 = M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0xE0;
    func_02007ef4(func_020a7278(), temp_r4 + 0x3000, temp_r5);
    func_02081528();
    func_0208116c(&data_ov000_021b8ee8, 0, 0x80);
    func_0208116c(&data_ov000_021b8ef4, 0x160, 0x20);
    func_02091d4c(0xF);
    func_0208116c(&data_ov000_021b8f00, 0x2C0, 0x20);
    func_020a9a30(1, 2, 1, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x300);
    func_020a9a30(1, 2, 2, M2C_FIELD(data_027e01d8, s32 *, 0x30) + 0x340);
    func_0208116c(&data_ov000_021b8f0c, 0x360, 0x20);
    func_0208116c(&data_ov000_021b8f1c, 0x380, 0x20);
    func_0208116c(&data_ov000_021b8f2c, 0x3A0, 0x20);
    func_0208116c(&data_ov000_021b8f3c, 0x3C0, 0x20);
    func_0208116c(&data_ov000_021b8f4c, 0x3E0, 0x20);
    data_027e01d8 = sp4;
    func_020ad150(0, 0x10, 1, 7);
}

void func_ov000_021743ec(void) {

}
