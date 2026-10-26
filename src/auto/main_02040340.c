/* 11 functions from 0x02040340 to 0x020411DC (main), found by ds-decomp. */
#include "common.h"
void *func_02044268(void);

void func_020407fc(s32 arg0,s32 *arg1) {
void func_02007e70(void *,void *,u32); void *func_02044268(void);
u32 n=*arg1+2;
if(n>2) func_02007e70(arg1+1,(u8 *)func_02044268()+0x350,(n-2)*4);
M2C_FIELD(func_02044268(),s32 *,0x348)=n-1;
M2C_FIELD(func_02044268(),s32 *,0x34c)=arg0;
}

void func_0204084c(s32 arg0) {
void func_02042f94(s32); void func_02043008(s32); void *func_02044268(void);
if(M2C_FIELD(func_02044268(),u8 *,0x15)==0) { func_02043008(arg0); return; }
func_02042f94(arg0);
}

s32 func_02040cf0(M2C_UNK arg0) {
 void *func_02044268(); unsigned long long func_02007004(); s32 func_0203ea4c(); s32 func_02040a28(); M2C_UNK func_02044278(M2C_UNK); M2C_UNK func_0203dc38(M2C_UNK,s32);
 void func_02043008(s32); void *p;
 M2C_FIELD(func_02044268(),s32*,0x208)=0;
 M2C_FIELD(func_02044268(),s32*,0x204)=0;
 M2C_FIELD(func_02044268(),u8*,0x1a7)=0;
 p=func_02044268();
 M2C_FIELD(p,unsigned long long*,0x1cc)=func_02007004();
 if(M2C_FIELD(func_02044268(),u8*,0x15)==0) {
 func_02044278(3); func_0203ea4c(0); if(((s32 (*)())func_02043008)())return 0;
 } else if(M2C_FIELD(func_02044268(),u8*,0x15)==1) {
 func_02040a28(0,0,arg0); if(((s32 (*)())func_0204084c)())return 0;
 } else if(M2C_FIELD(func_02044268(),u8*,0x15)==3) {
 func_0203dc38(6,0xfffec5e6);return 0;
 }
 return 1;
}

s32 func_02040dc8(M2C_UNK arg0) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    void *func_02044268();
    s32 temp_r4;
    void *temp_r4_2;

    temp_r4_2 = func_02044268();
    temp_r4 = func_0203f058(5, arg0, M2C_FIELD(temp_r4_2, s32 *, 0x24), M2C_FIELD(func_02044268(), u16 *, 0xA4), 0, 0);
    M2C_FIELD(func_02044268(), s32 *, 0x204) = 0;
    return temp_r4;
}

s32 func_02041038(void) {
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s32 func_02040cf0(M2C_UNK);
    M2C_UNK func_02041ce0();
    M2C_UNK func_02041e44();
    M2C_UNK func_02044278(M2C_UNK);
    M2C_UNK func_0205df50(s32);
    s32 var_r4;
    void *temp_r5;

    var_r4 = 1;
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 3) {
        if (M2C_FIELD(func_02044268(), u8 *, 0xD) != 0) {
            func_02041e44();
        }
        func_0203dc38(6, 0xFFFEC5D2);
        return 0;
    }
    temp_r5 = func_02044268();
    M2C_FIELD(temp_r5, u8 *, 0x14) = (u8) M2C_FIELD(func_02044268(), u8 *, 0xD);
    M2C_FIELD(func_02044268(), s32 *, 0x208) = 0;
    if (M2C_FIELD(func_02044268(), s32 *, 0x19C) != 0) {
        func_0205df50(M2C_FIELD(func_02044268(), s32 *, 0x19C));
        M2C_FIELD(func_02044268(), s32 *, 0x19C) = 0;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0xD) != 0) {
        func_02041ce0();
    } else {
        func_02044278(4);
        var_r4 = func_02040cf0(0);
    }
    return var_r4;
}

#pragma opt_strength_reduction off
s32 func_020410f8(void) {
 s32 func_0203f058(M2C_UNK,M2C_UNK,s32,u16,s32,s32); void func_0205afec(s32); 
 s32 i,r; void *a,*b,*c,*d;
 for(i=1;i<=(s32)M2C_FIELD(func_02044268(),u8*,0xd);i++){
 a=func_02044268();b=func_02044268();c=func_02044268();d=func_02044268();
 r=func_0203f058(10,M2C_FIELD((u8*)a+(i<<2),s32*,0xf4),M2C_FIELD((u8*)b+i*4,s32*,0x24),M2C_FIELD((u8*)c+(i<<1),u16*,0xa4),(s32)((u8*)d+0x348),M2C_FIELD(func_02044268(),s32*,0x348)+1);
 if(r)return r;
 }
 M2C_FIELD(func_02044268(),u8*,0x17)=0;
 M2C_FIELD(func_02044268(),s32*,0x20)=0;
 M2C_FIELD(func_02044268(),u8*,0x1a8)=1;
 func_0205afec(*M2C_FIELD(func_02044268(),s32**,4));
 M2C_FIELD(func_02044268(),u8*,0x1a8)=0;
 return 0;
}
#pragma opt_strength_reduction reset
