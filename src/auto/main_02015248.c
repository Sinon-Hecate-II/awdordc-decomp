/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"

/* Select units by state into priority groups, then dispatch the matching network action. */

u32 func_02015248(void *arg0) {
 s32 func_0200bbe0(void *,s32,s32);
 void func_0200bbf0(void *,s32,s32);
 void *p;
 u32 result;
 u32 sp0[24];
 s32 pos;
 p = NULL;
 result = 0;
 if (arg0 != NULL) {
     pos = M2C_FIELD(arg0, s32 *, 0x2c) - M2C_FIELD(arg0, s32 *, 0x24);
     if ((u32)func_0200bbe0(arg0, (s32)sp0, 0x60) >= 0x60U) {
         p = sp0;
     }
     func_0200bbf0(arg0, pos, 0);
 } else {
     p = (void *)0x027ffe00;
 }
 if (p != NULL) {
     result = M2C_FIELD(p, s32 *, 0x2c) + 0x268 + M2C_FIELD(p, s32 *, 0x3c);
     if (result < 0x10000U) {
         result = 0x10000;
     }
 }
 return result;
}

void func_02015724(void *arg0, u32 arg1, u32 arg2, s32 arg3) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    M2C_UNK func_02008048(s32, s32, s32);
    u32 temp_ip;
    u32 temp_r1;
    u32 var_lr;
    u32 var_r2;

    var_r2 = arg2;
    var_lr = arg1;
    temp_ip = M2C_FIELD(arg0, u32 *, 0);
    if (var_lr < 0x4000U) {
        var_lr = 0x4000;
    }
    if (var_r2 > 0x8000U) {
        var_r2 = 0x8000;
    }
    temp_r1 = temp_ip + M2C_FIELD(arg0, s32 *, 0xC);
    if (var_lr < temp_ip) {
        var_lr = temp_ip;
    }
    if (var_r2 > temp_r1) {
        var_r2 = temp_r1;
    }
    if (var_lr >= var_r2) {
        return;
    }
    if (arg3 != 0) {
        func_02007f8c(M2C_FIELD(arg0, s32 *, 8) + var_lr, 0, var_r2 - var_lr);
        return;
    }
    func_02008048(M2C_FIELD(arg0, s32 *, 4) + var_lr, M2C_FIELD(arg0, s32 *, 8) + var_lr, var_r2 - var_lr);
}

s32 func_0201579c(s32 arg0, s32 arg1) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    void func_02015a2c(void *, void *);
    s32 func_02015c18(void *, void *);
    M2C_UNK func_02015f94(void *, s32, void *);
    M2C_UNK func_020161bc(void *);
    s32 func_02018418();
    M2C_UNK func_0201869c(void *, M2C_UNK);
    s32 func_0201871c();
    M2C_UNK func_02018738(void *);
    extern u8 data_02131184;
    extern void *data_02136c4c;
    u8 var_r4;
    u8 var_r6;
    s32 temp_r2;
    s32 temp_r5;
    s32 temp_r6;
    void *temp_r9;

    var_r4 = 0xFF;
    temp_r5 = func_0200751c();
    if (func_02018418() == 0) {
        func_02007530(temp_r5);
        return 0;
    }
    if ((s32) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1) > 0x10) {
        func_02007530(temp_r5);
        return 0;
    }
    var_r6 = 0;
loop_5:
    temp_r2 = (var_r6 * 0x5D4) + (s32) data_02136c4c;
    if (M2C_FIELD(temp_r2, s32 *, 0x1D40) == arg0) {
        func_02007530(temp_r5);
        return 0;
    }
    if (M2C_FIELD(temp_r2, u8 *, 0x1D52) == 0) {
        var_r4 = var_r6;
        goto block_10;
    }
    var_r6 += 1;
    if ((u32) var_r6 >= 0x10U) {
block_10:
        if (var_r6 == 0x10) {
            func_02007530(temp_r5);
            return 0;
        }
        temp_r6 = var_r4 * 0x5D4;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D40) = arg0;
        temp_r9 = data_02136c4c + 0x1788 + temp_r6;
        func_02015a2c(temp_r9, arg1);
        func_02008048(arg0 + 0x1C, temp_r9 + 0xC4, 0x20);
        if (func_02015c18(data_02136c4c + 0x1D2C + temp_r6, temp_r9) == 0) {
            func_02007530(temp_r5);
            return 0;
        }
        func_02015f94(data_02136c4c + 0x186C + temp_r6, arg0, data_02136c4c + 0x1300);
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D21) = var_r4;
        func_020161bc(data_02136c4c + 0x186C + temp_r6);
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D1F) = (u8) data_02131184;
        M2C_FIELD((data_02136c4c + temp_r6), s16 *, 0x1D4E) = 1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D44) = arg1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D54) = (s32) (arg1 + 0x1E8);
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D58) = (s32) (arg1 + 0x258);
        data_02131184 += 1;
        if ((M2C_FIELD(M2C_FIELD((data_02136c4c + temp_r6), void **, 0x1D54), s32 *, 0x6C) != 0) && (func_0201871c() == 0)) {
            func_02018738(data_02136c4c + 0x7CE0);
            func_0201869c(data_02136c4c + 0x74E0, 0x800);
        }
        M2C_FIELD((data_02136c4c + temp_r6), s8 *, 0x1D52) = 1;
        M2C_FIELD(data_02136c4c, u8 *, 0x1524) = (u8) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1);
        func_02007530(temp_r5);
        return 1;
    }
    goto loop_5;
}

void func_02015a2c(void *arg0, void *arg1) {
 M2C_UNK func_02008048(s32,s32,s32);
 void func_02015aa0(void *, void *, void *, s32 *);
 extern u8 data_020ea72c[];
 s32 sp0;
 u8 *p;
 void *out;
 s32 i;
 sp0=0x022C0000;
 p=data_020ea72c;
 M2C_FIELD(arg0,s32 *,0)=M2C_FIELD(arg1,s32 *,0x24);
 out=arg0+12;
 M2C_FIELD(arg0,s32 *,4)=M2C_FIELD(arg1,s32 *,0x34);
 i=0;
 do {func_02015aa0(arg1,p,out,&sp0); i++; out+=16; p+=4;} while(i<3);
 func_02008048((s32)arg1+0x160,(s32)arg0+0x3c,0x88);
}
