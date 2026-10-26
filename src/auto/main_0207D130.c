/* 14 functions from 0x0207D130 to 0x0207DE50 (main), found by ds-decomp. */
#include "common.h"
extern void **data_027e0058;
extern u8 data_02101884;
extern const u8 data_020ec6bc[], data_020ecabc[], data_020ecebc[], data_020ed2bc[], data_020ed6bc[], data_020edabc[], data_020ec2bc[];
extern u32 data_0214c0c0[2];
extern const u16 data_020ebddc[8];

s32 func_0207d6c8(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x8:
        return 0;
    case 0x10:
        return 1;
    case 0x20:
        return 2;
    case 0x40:
        return 3;
    case 0x80:
        return 4;
    case 0x100:
        return 5;
    case 0x200:
        return 6;
    case 0x400:
        return 7;
    default:
        return 0;
    }
}

s32 func_0207d774(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x8:
        return 0;
    case 0x10:
        return 1;
    case 0x20:
        return 2;
    case 0x40:
        return 3;
    case 0x80:
        return 4;
    case 0x100:
        return 5;
    case 0x200:
        return 6;
    case 0x400:
        return 7;
    default:
        return 0;
    }
}

void func_0207d95c(M2C_UNK *arg0) {
    extern M2C_UNK data_02101874;
    M2C_UNK *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = &data_02101874;
    }
    *(s32 *)0x04000580 = M2C_FIELD(var_r0, s32 *, 0) | (M2C_FIELD(var_r0, s32 *, 4) << 8) | (M2C_FIELD(var_r0, s32 *, 8) << 0x10) | (M2C_FIELD(var_r0, s32 *, 0xC) << 0x18);
}

void func_0207d990(s32 arg0, void *arg1, void *arg2) {
    M2C_UNK func_0200154c(s32, s32, s32, s32, s32);
    M2C_UNK func_02001624(s32, s32, s32, s32, s32);
    M2C_UNK func_02003fc8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    func_02003fc8(-0x1200, 0x1200, -0x1800, 0x1800, 0, 0x2000, 0x1000, 1, arg0);
    func_0200154c(arg0, arg0, M2C_FIELD(arg2, s32 *, 0), M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 8));
    func_02001624(arg0, arg0, M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, s32 *, 8));
    *(s32 *)0x0400044C = 0;
}

void func_0207da34(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004bb0(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02004cf0();
    func_02004b54();
    func_02004bb0(arg0, arg1, arg2);
    func_02004cf0();
}

void func_0207da60(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02004d3c();
    M2C_UNK func_02004d70(s32, s32, s32);
    M2C_UNK func_02004ddc();
    M2C_UNK func_0207dacc(s32, s32);
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r6 = arg0;
    var_r5 = arg1;
    var_r4 = arg2;
    if ((var_r6 & 2) || (var_r5 & 2) || (var_r4 & 2)) {
        if (var_r4 == 0) {
            return;
        }
        do {
            func_0207dacc(var_r6, var_r5);
            var_r6 += 2;
            var_r5 += 2;
            var_r4 -= 2;
        } while (var_r4 != 0);
        return;
    }
    func_02004d3c();
    func_02004d70(var_r6, var_r5, var_r4);
    func_02004ddc();
}

M2C_UNK func_0207dacc(s32 arg0,s32 arg1) {
s32 func_020033cc(void);
void func_02002e3c(s32);
s32 state=func_020033cc();
u32 base=(u32)data_020ebddc[state>>4]<<12;
data_0214c0c0[1]=state;
data_0214c0c0[0]=base;
*(u16 *)(base+(arg1&~1))=*(u16 *)arg0;
func_02002e3c(state);
}

void func_0207db18(u8 arg0) { switch(M2C_FIELD(*data_027e0058,u8 *,0x5157)) {
case 4: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ec6bc;break;
case 5: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ecabc;break;
case 6: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ecebc;break;
case 7: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ed2bc;break;
case 8: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ed6bc;break;
case 9: M2C_FIELD(&data_02101884,const u8 **,4)=data_020edabc;break;
default:M2C_FIELD(&data_02101884,const u8 **,4)=data_020ec2bc;break;
} data_02101884=arg0; }

u8 func_0207dbfc(void) {
    extern u8 data_02101884;
    return data_02101884;
}
