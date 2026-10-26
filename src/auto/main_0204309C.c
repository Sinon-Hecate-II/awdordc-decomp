/* 18 functions from 0x0204309C to 0x02043E10 (main), found by ds-decomp. */
#include "common.h"

s32 func_0204309c(u32 ret){
s32 func_02038f6c(void);
u32 off,code;
if(ret==0)return 0;
switch(ret){
case 1:code=6;off=code-56;break;
case 2:code=6;off=code-66;break;
case 3:code=6;off=code-36;break;
case 4:code=6;off=code-86;break;
case 5:code=6;off=code-26;break;
}
switch(func_02038f6c()){
case 2:func_02039db4(code,off-0xfa00);break;
case 4:func_0203accc(code,off+0xfffedef0);break;
case 5:func_0203dc38(code,off+0xfffeb7e0);break;
default:func_02037638(code,off+0xfffe90d0);break;
}
return ret;
}

s32 func_02043184(s32 a,s32 unused,s32 off) {
s32 code=a;
if(a==0)return 0;
switch(a){
case 1:code=9;off=code-10;break;
case 2:code=6;off=code-56;break;
case 3:code=6;off=code-36;break;
}
func_0203dc38(code,off+0xfffeb010);
return a;
}

s32 func_020431e0(s32 a) {
s32 code=6;
if(a==0)return 0;
switch(a){case 1:return 1;case 2:return 2;}
if(code)func_0203dc38(code,0xfffeb007);
return a;
}

u32 func_02043230(u32 a,u32 unused,u32 off) {
u32 ret=a;
u32 code;
code=ret;
if(ret==0)return 0;
switch(ret){
case 1:code=9;off=code-10;break;
case 2:case 5:code=0;off=code;ret=code;break;
case 3:code=6;off=code-16;break;
case 4:code=6;off=code-36;break;
case 6:code=6;off=code-76;break;
case 7:code=6;off=code-86;break;
}
if(code)func_0203dc38(code,off+0xfffeac28);
return ret;
}

void func_020436d8(void) {

}

void func_02043b6c(void) {

}

void func_02043b70(void) {

}

void func_02043b74(s32 a,s32 b) {
extern u8 data_0213d3bc[];
s32 i;u8 *p;
switch(a){case 0:break;case 1:case 2:default:return;}
func_0205eb50(b,8);
func_0205eb50(b,10);
func_0205eb50(b,50);
func_0205eb50(b,51);
func_0205eb50(b,52);
func_0205eb50(b,53);
func_0205eb50(b,54);
p=data_0213d3bc;
for(i=0;i<154;i++,p+=12)if(*p)func_0205eb50(b,*p);
}

s32 func_02043c18(void) {
    return 0;
}

void func_02043c20(void) {
    M2C_UNK func_0204309c();
    func_0204309c();
}

void func_02043c2c(s32 arg0, s16 arg1) {
    void *func_02044268();
    M2C_FIELD(func_02044268(), s32 *, 0x1C) = arg0;
    M2C_FIELD(func_02044268(), s16 *, 0x1A) = arg1;
}

void func_02043c4c(s32 arg0) {
    void *func_02044268();
    M2C_UNK func_02044278(M2C_UNK);
    s32 func_02043184();
    M2C_UNK func_0203ecb0(M2C_UNK, s32);
    void *p;
    s32 zero;

    zero = 0;
    p = func_02044268();
    if (M2C_FIELD(p, s32 *, 0x1A0) == 1) {
        func_02044278(6);
    } else {
        p = func_02044268();
        if (M2C_FIELD(p, s32 *, 0x1A0) != 6) {
            p = func_02044268();
            if (M2C_FIELD(p, s32 *, 0x1A0) != 0xB) {
                return;
            }
        }
    }
    p = func_02044268();
    if (arg0 == M2C_FIELD(p, s32 *, 0x180)) {
        p = func_02044268();
        M2C_FIELD(p, u8 *, 0x17C) = (u8)(M2C_FIELD(p, u8 *, 0x17C) + 1);
    } else {
        p = func_02044268();
        M2C_FIELD(p, u8 *, 0x17C) = 0;
        p = func_02044268();
        M2C_FIELD(p, s32 *, 0x180) = arg0;
    }
    p = func_02044268();
    M2C_FIELD(p, s32 *, 0x184) = zero;
    M2C_FIELD(p, s32 *, 0x188) = zero;
    func_0203ecb0(1, arg0);
    if (func_02043184() != 0) {
        return;
    }
    p = func_02044268();
    M2C_FIELD(p, u8 *, 0x3CC) = 0xFF;
}

void func_02043e0c(void) {

}

