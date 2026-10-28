/* 18 functions from 0x020E24C0 to 0x020E34BC (main), found by ds-decomp. */
#include "common.h"

extern s32 data_02168fd0[];
extern M2C_UNK data_0212d6c8, data_0212d6d4, data_0212d6e0, data_0212d6f0, data_0212d704, data_0212d714, data_0212d724, data_0212d734;

M2C_UNK func_020e24c0(M2C_UNK arg0) { return 0; }

M2C_UNK func_020e2a2c(M2C_UNK arg0) { return 0; }

void *func_020e2f9c(void *arg0) {
 M2C_UNK func_02082040();
 M2C_UNK func_020e4ca0();
 extern M2C_UNK data_0212d1e8;
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_0212d1e8;
 if(M2C_FIELD(arg0,void **,0x68)!=0)func_02082040(M2C_FIELD(arg0,void **,0x68));
 func_020e4ca0();
 func_02082040(arg0);
 return arg0;
}

void *func_020e2fd4(void *arg0) {
    M2C_UNK func_02082040();
    M2C_UNK func_020e4ca0();
    extern M2C_UNK data_0212d1e8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212d1e8;
    if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
        func_02082040();
    }
    func_020e4ca0();
    return arg0;
}

void func_020e3004(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_0212d678;
    func_0200bc5c(&data_0212d678);
}

s32 func_020e3018(s32 arg0) {
 extern u8 data_0212d600[];
 s32 i;
 u8 *p;
 p=data_0212d600;
 i=0;
 do {
 if(arg0==M2C_FIELD(p,s16*,0))return M2C_FIELD(p,s32*,4);
 i++;
 p+=8;
 }while(i<15);
 return 0;
}

M2C_UNK *func_020e304c(void) {
    extern M2C_UNK data_0212d68c;
    return &data_0212d68c;
}

void func_020e3058(void **arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4, u8 arg5, s32 arg6, s32 arg7, u8 arg8) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088e84(void *, s16, s16, s16, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, s32, u8, s32);
    M2C_UNK func_020aad18(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, u16);
    void *func_020ab1c4(s32);
    void *temp_r5;
    s16 temp_r6,temp_r7;
    s16 temp_r8,temp_r9;
    s32 temp_r10;
    s16 temp_r6_2,temp_r7_2;
    s32 temp_r8_2;
    s32 var_r0_2,var_r0_3;
    u8 var_r0;

    *arg0 = func_020ab1c4(arg7);
    if (arg8 != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    func_020aab24(*arg0, arg3, arg4, arg5, (s32) var_r0);
    temp_r8 = arg2;
    temp_r9 = arg1;
    temp_r5 = *arg0;
    func_02088e84(temp_r5, temp_r9, temp_r8, temp_r9, (s32) temp_r8);
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r10 = func_020aae10(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7, temp_r6, (s32)(u16) temp_r10, (s32)(u16) func_020aae44(temp_r5));
    }
    M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r9;
    M2C_FIELD(temp_r5, s16 *, 0x36) = temp_r8;
    if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        temp_r6_2 = M2C_FIELD(temp_r5, s16 *, 0x52);
        temp_r7_2 = M2C_FIELD(temp_r5, s16 *, 0x50);
        temp_r8_2 = func_020aae10(temp_r5);
        func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r7_2, temp_r6_2, (s32)(u16) temp_r8_2, (s32)(u16) func_020aae44(temp_r5));
    }
    func_02088d94(*arg0);
    func_020aad18(*arg0);
    if (arg6 == -1) {
        return;
    }
    func_020ab150(*arg0, (u16) arg6);
}

u8 func_020e31e0(void) {
    extern u8 data_02168f8c;
    return data_02168f8c;
}

void func_020e31f0(s32 arg0) {
 extern u8 data_02168f8c;
 data_02168f8c=1;
 if(arg0==1 || arg0==2 || arg0==5)data_02168f8c=arg0;
}

M2C_UNK *func_020e3218(s32 arg0) {
    M2C_UNK func_020675e4(M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_0212d69c;
    extern M2C_UNK data_0212d6a0;
    extern M2C_UNK data_0212d6a8;
    extern M2C_UNK data_0212d6b0;
    extern M2C_UNK data_0212d6b8;
    extern M2C_UNK data_0212d6c0;
    extern M2C_UNK data_02168f90;
    u32 temp_r0;

    if (arg0 == 0) {
        return NULL;
    }
    temp_r0 = func_020e31e0();
    switch (temp_r0) {
    default:
        break;
    case 0:
        func_020675e4(&data_02168f90, &data_0212d69c, arg0);
        break;
    case 1:
        func_020675e4(&data_02168f90, &data_0212d6a0, arg0);
        break;
    case 2:
        func_020675e4(&data_02168f90, &data_0212d6a8, arg0);
        break;
    case 3:
        func_020675e4(&data_02168f90, &data_0212d6b0, arg0);
        break;
    case 4:
        func_020675e4(&data_02168f90, &data_0212d6b8, arg0);
        break;
    case 5:
        func_020675e4(&data_02168f90, &data_0212d6c0, arg0);
        break;
    }
    return &data_02168f90;
}

M2C_UNK *func_020e32e8(s32 arg0) {
 M2C_UNK *r;
 u8 old;
 old=((s32 (*)(void))func_020e31e0)();
 if(old==0)func_020e31f0(1);
 r=func_020e3218(arg0);
 func_020e31f0(old);
 return r;
}

void func_020e3320(void) {
 extern s32 data_02168fd0[];
 s32 i=0;
 do { data_02168fd0[i]=0; i++; } while(i<5);
}

void func_020e3344(void) {
 void func_020e3400(void);
 M2C_UNK func_0200bc5c();
 s32 func_02080e30();
 void func_020814e4();
 s32 func_020815a8();
 void func_02081528();
 func_020e3400();
 func_0200bc5c(&data_0212d6c8);
 data_02168fd0[0]=func_02080e30(func_020e3218((s32)&data_0212d6d4),1);
 data_02168fd0[1]=func_02080e30(func_020e3218((s32)&data_0212d6e0),1);
 func_0200bc5c(&data_0212d6f0);
 func_020814e4(func_020e3218((s32)&data_0212d704));
 data_02168fd0[2]=func_020815a8(func_020e3218((s32)&data_0212d714));
 data_02168fd0[3]=func_020815a8(func_020e3218((s32)&data_0212d724));
 data_02168fd0[4]=func_020815a8(func_020e3218((s32)&data_0212d734));
 func_02081528();
}

void func_020e3400(void) {
 void func_020e35cc(s32);
 s32 i=0;
 do {
 if(data_02168fd0[i]!=0)func_020e35cc(data_02168fd0[i]);
 data_02168fd0[i]=0;
 i++;
 }while(i<5);
}

s32 func_020e3438(s32 arg0) {
    extern s32 data_02168fd0[];
    return data_02168fd0[arg0];
}

void func_020e3448(void) {
    s32 func_02006a10(M2C_UNK);
    s32 func_02006a24(M2C_UNK);
    s32 func_02006bec(M2C_UNK, s32, M2C_UNK);
    s32 func_0202a424(s32, s32, M2C_UNK);
    M2C_UNK func_0202a4d4(s32, M2C_UNK);
    extern s32 data_02168fe4;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;

    temp_r4 = func_02006a24(0);
    temp_r4_2 = (func_02006a10(0) - temp_r4) & ~7;
    temp_r0 = func_0202a424(func_02006bec(0, temp_r4_2, 8), temp_r4_2, 0);
    data_02168fe4 = temp_r0;
    func_0202a4d4(temp_r0, 0);
}

u16 func_020e349c(void) {
 u16 a,b;
 a=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=0;
 b=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=a;
 return b;
}

