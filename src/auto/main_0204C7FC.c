/* 11 functions from 0x0204C7FC to 0x0204D5C0 (main), found by ds-decomp. */
#include "common.h"

void func_0204ce20(void *arg0) {
    M2C_UNK func_0204a594(void *);
    M2C_UNK func_0204bc64(void *);
    s32 func_0204c300(void *);
 extern M2C_UNK data_020fd864;
 M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
    extern M2C_UNK data_020fd7d0;
    extern M2C_UNK data_020fd93c;
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x148);
    temp_r0 = func_0204c300(arg0);
    if (temp_r0 == 0) {
        if ((M2C_FIELD(arg0, s32 *, 0xFC) != 0) && (M2C_FIELD(arg0, s32 *, 0x38) != 0)) {

        } else {
            func_020640a8(&data_020fd93c, &data_020fd864, &data_020fd7d0, 0x200);
        }
        func_0204bc64(arg0);
        return;
    }
    if (temp_r5 != M2C_FIELD(arg0, s32 *, 0x148)) {
        func_0204a594(arg0);
    }
    if (temp_r0 != 1) {
        return;
    }
    func_0204bc64(arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = 5;
    func_0204a518(arg0, 0, 0);
}

void func_0204ceb8(void *arg0) {
    s32 func_0204943c(s32, s32 *, M2C_UNK, M2C_UNK);
    s32 func_02049900(s32);
    M2C_UNK func_0204a518(void *, M2C_UNK, M2C_UNK);
    s32 sp0;

    if (func_0204943c(M2C_FIELD(arg0, s32 *, 0x48), &sp0, 0, 0) == -1) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 5;
        M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        return;
    }
    if (sp0 == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = 6;
    func_0204a518(arg0, 0, 0);
}

s32 func_0204d1ac(void *arg0,s32 arg1,s32 arg2) {
 s32 func_02049ef4(void *);
 M2C_UNK func_0204a518(void *,s32,s32);
 s32 a=0,b=0;
 s32 c=M2C_FIELD(arg0,s32 *,0x100)+arg2;
 M2C_FIELD(arg0,s32 *,0x100)=c;
 if(c==M2C_FIELD(arg0,s32 *,0x104)||M2C_FIELD(arg0,s32 *,0x130)) M2C_FIELD(arg0,s32 *,0xFC)=1;
 if(M2C_FIELD(arg0,s32 *,0xC)==0) {
 if(!func_02049ef4(arg0+0xBC)) return 0;
 a=M2C_FIELD(arg0,s32 *,0xC0); b=M2C_FIELD(arg0,s32 *,0xC8);
 } else if(M2C_FIELD(arg0,s32 *,0xC)==1) {
 if(arg2) { M2C_FIELD(arg0,s32 *,0xFC)=1; M2C_FIELD(arg0,s32 *,0x38)=13; return 0; }
 a=arg1;b=arg2;
 } else if(M2C_FIELD(arg0,s32 *,0xC)==2) {a=arg1;b=arg2;}
 func_0204a518(arg0,a,b); return 1;
}

s32 func_0204d26c(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02068adc(void *, M2C_UNK *, s32 *);
    extern M2C_UNK data_020fd7f0;
    extern M2C_UNK data_020fd864;
    extern M2C_UNK data_020fd998;
    extern M2C_UNK data_020fd99c;
    s32 sp0;

    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        func_020640a8(&data_020fd998, &data_020fd864, &data_020fd7f0, 0x321);
    }
    if (func_02068adc(arg0 + 0x114, &data_020fd99c, &sp0) != 1) {
        return -1;
    }
    return sp0;
}

void func_0204d2d0(void *p,void *src,s32 n) {
extern M2C_UNK data_020fd858,data_020fd864,data_020fd838,data_020fd9a0,data_020fd9a8;
s32 left;
if(!p)func_020640a8(&data_020fd858,&data_020fd864,&data_020fd838,0x333);
if(!src)func_020640a8(&data_020fd9a0,&data_020fd864,&data_020fd838,0x334);
if(n<0)func_020640a8(&data_020fd9a8,&data_020fd864,&data_020fd838,0x335);
if(!n)return;
if(M2C_FIELD(p,s32 *,0x120)>=10)return;
left=10-M2C_FIELD(p,s32 *,0x120);
if(left>=n)left=n;
func_020651a4((u8 *)p+0x114+M2C_FIELD(p,s32 *,0x120),src,left);
M2C_FIELD(p,s32 *,0x120)+=left;
*((u8 *)p+M2C_FIELD(p,s32 *,0x120)+0x114)=0;
}

