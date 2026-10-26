/* 39 functions from 0x02037214 to 0x0203804C (main), found by ds-decomp. */
#include "common.h"

s32 func_02037508(s32 *arg0, s32 *arg1) {
    extern M2C_UNK data_0213d1cc;
    if (arg0 != (s32 *)0) {
        *arg0 = M2C_FIELD(&data_0213d1cc, s32 *, 4);
    }
    if (arg1 != (s32 *)0) {
        switch (M2C_FIELD(&data_0213d1cc, s32 *, 0)) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            *arg1 = 6;
            break;
        case 6:
            *arg1 = 3;
            break;
        case 7:
            *arg1 = 4;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            *arg1 = 1;
            break;
        case 1:
        case 9:
            *arg1 = 7;
            break;
        case 14:
            *arg1 = 5;
            break;
        case 15:
        case 17:
        case 19:
            *arg1 = 6;
            break;
        case 16:
        case 18:
            *arg1 = 2;
            break;
        default:
            *arg1 = 0;
            break;
        }
    }
    return M2C_FIELD(&data_0213d1cc, s32 *, 0);
}

void func_020375fc(void) {
    extern M2C_UNK data_0213d1cc;
    if (M2C_FIELD(&data_0213d1cc, s32 *, 0) != 9) {
        M2C_FIELD(&data_0213d1cc, s32 *, 0) = 0;
        M2C_FIELD(&data_0213d1cc, s32 *, 4) = 0;
    }
}

s32 func_0203761c(void) {
    extern s32 data_0213d1cc;
    if (data_0213d1cc != 0) {
        return 1;
    }
    return 0;
}

void func_02037638(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d1cc;
    if (M2C_FIELD(&data_0213d1cc, s32 *, 0) != 9) {
        M2C_FIELD(&data_0213d1cc, s32 *, 0) = arg0;
        M2C_FIELD(&data_0213d1cc, s32 *, 4) = arg1;
    }
}

s32 func_02037650(s32 arg0) {
    return arg0 - 0x20;
}

void *func_02037658(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0x4457434D;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return arg0 + 0x20;
}

s32 func_02037670(s32 arg0) {
    return M2C_FIELD((void *)func_02037650(arg0), s32 *, 4);
}

void func_02037680(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d1d4;
    M2C_FIELD(&data_0213d1d4, s32 *, 4) = arg0;
    M2C_FIELD(&data_0213d1d4, s32 *, 0) = arg1;
}

void func_02037694(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020376a4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020376a4(arg0, arg1, 0x20);
}

M2C_UNK func_020376a4(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_0213d1d4;
    void *temp_r0;
    temp_r0 = M2C_FIELD(&data_0213d1d4, void *(**)(M2C_UNK, s32, M2C_UNK), 4)(arg0, arg1 + 0x20, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return (s32)func_02037658(temp_r0, arg1);
}

M2C_UNK func_020376d8(M2C_UNK a,M2C_UNK b,M2C_UNK c){
 extern M2C_UNK data_0213d1d4;
 if(b==0)return;
 M2C_FIELD(&data_0213d1d4,void (**)(s32,s32,s32),0)(a,func_02037650(b),c);
}

M2C_UNK func_02037714(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02037728(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    return func_02037728(arg0, arg1, arg2, arg3, 0x20);
}

M2C_UNK func_02037728(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK size,s32 align){
 void func_02008048(s32,s32,u32);
 s32 p;u32 n;
 p=func_020376a4(a,size,align);if(!p)return 0;
 if(b){n=func_02037670(b);if(n<=(u32)size)size=n;func_02008048(b,p,size);func_020376d8(a,b,n);}return p;
}

void func_02037794(M2C_UNK arg0) {
    func_02037694(5, arg0);
}

void func_020377a8(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02037714(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02037714(5, arg0, arg1, arg1);
}

void func_020377c4(M2C_UNK arg0) {
    M2C_UNK func_020376d8(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020376d8(5, arg0, 0);
}

M2C_UNK func_020377dc(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK d){
 extern void *data_0213d1dc;
 void func_02037854(s32);
 void func_02007f8c(s32,s32,s32);void func_020220a8(s32);
 if(data_0213d1dc)return;
 func_02007f8c(a,0,12);
 M2C_FIELD(a,u16 *,8)=b;M2C_FIELD(a,u16 *,10)=1;M2C_FIELD(a,u16 *,4)=1;M2C_FIELD(a,u16 *,6)=0;
 data_0213d1dc=(void *)a;func_02037854(0);func_020220a8(d);
}

void func_0203783c(M2C_UNK arg0) {
    M2C_UNK func_020377dc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020377dc(arg0, 3, 1, 0x14);
}

void func_02037854(s32 arg0) {
    M2C_UNK func_0203289c(M2C_UNK *);
    extern M2C_UNK data_020fc818;
    extern M2C_UNK data_020fc840;
    extern M2C_UNK data_020fc864;
    switch (arg0) {                                 /* irregular */
    case 0:
        func_0203289c(&data_020fc818);
        return;
    case 1:
        func_0203289c(&data_020fc840);
        return;
    case 2:
        func_0203289c(&data_020fc864);
        return;
    }
}

void func_020378a4(void){
 extern void *data_0213d1dc;
 void func_02007f8c(s32,s32,s32);s32 func_0202ef64(void *);
 s32 args[3];
 if(data_0213d1dc){
 if(M2C_FIELD(data_0213d1dc,u16 *,4)!=1)return;
 func_02007f8c((s32)args,0,12);
 M2C_FIELD(args,u8 *,8)=M2C_FIELD(data_0213d1dc,u16 *,8);
 M2C_FIELD(args,u8 *,9)=M2C_FIELD(data_0213d1dc,u16 *,10);
 args[0]=(s32)func_02037694;args[1]=(s32)func_020376d8;
 M2C_FIELD(data_0213d1dc,u16 *,4)=2;
 if(!func_0202ef64(args))func_02037638(9,-6);
 }else func_02037638(9,-4);
}

s32 func_02037954(void){
 extern void *data_0213d1dc;s32 func_02037a0c(void);
 if(!data_0213d1dc)return 0;
 if(!M2C_FIELD(data_0213d1dc,s32 *,0))return 0;
 M2C_FIELD(data_0213d1dc,u16 *,4)=3;func_02037a0c();return 1;
}

void func_02037994(void){
 extern void *data_0213d1dc;
 s32 func_0202f10c(void);s32 func_02027c84(void);
 if(!data_0213d1dc)return;
 if(M2C_FIELD(data_0213d1dc,u16 *,4)==2){
 M2C_FIELD(data_0213d1dc,s32 *,0)=func_0202f10c();return;
 }
 if(M2C_FIELD(data_0213d1dc,u16 *,4)==4 && M2C_FIELD(data_0213d1dc,u16 *,6)!=0){
 if(func_02027c84()!=9){
 M2C_FIELD(data_0213d1dc,u16 *,6)=0;
 M2C_FIELD(data_0213d1dc,u16 *,4)=6;
 }}
}

s32 func_02037a0c(void) {
extern void *data_0213d1dc;s32 func_0202f1dc(void);s32 n;
if(!data_0213d1dc)return 0;
n=M2C_FIELD(data_0213d1dc,u16 *,4);if(n==1)return n;
n=func_0202f1dc();
if(n==5){M2C_FIELD(data_0213d1dc,u16 *,4)=4;M2C_FIELD(data_0213d1dc,u16 *,6)=1;return 4;}
if(n<0){if(n>=-10){func_02037638(9,n-700);M2C_FIELD(data_0213d1dc,u16 *,4)=8;return 8;}func_02037638(5,n);M2C_FIELD(data_0213d1dc,u16 *,4)=7;return 7;}
return 2;
}

void func_02037abc(void) {
extern void *data_0213d1dc;s32 func_0202f28c(void);void func_02006030(s32);
if(!data_0213d1dc)return;
if(M2C_FIELD(data_0213d1dc,u16 *,4)==1){data_0213d1dc=0;return;}
while(!func_0202f28c())func_02006030(10);
data_0213d1dc=0;
}

s32 func_02037b1c(void) {
extern void *data_0213d1dc;s32 func_0202f28c(void);
if(!data_0213d1dc)return 1;
if(M2C_FIELD(data_0213d1dc,u16 *,4)==8)return 0;
if(M2C_FIELD(data_0213d1dc,u16 *,4)==1){data_0213d1dc=0;return 1;}
M2C_FIELD(data_0213d1dc,u16 *,4)=5;
if(!func_0202f28c())return 0;
data_0213d1dc=0;return 1;
}

s32 func_02037b8c(void) {
    extern void *data_0213d1dc;
    if ((data_0213d1dc != NULL) && (M2C_FIELD(data_0213d1dc, u16 *, 4) == 6)) {
        return 1;
    }
    return 0;
}

void func_02037bb8(void) {
    M2C_UNK func_02029ad8();
    func_02029ad8();
}

s32 func_02037bc4(void) {
    u32 func_0202f248();


    u32 var_r2;

    func_02037994();
    if (func_02037b8c() != 0) {
        var_r2 = func_0202f248();
        if (var_r2 > 0x63U) {
            var_r2 = 0x63;
        }
        func_02037638(8, 0xFFFF2D10 - var_r2);
        func_02037abc();
        return 1;
    }
    return 0;
}

void func_02037c10(void) {
    M2C_UNK func_020362d4();
    func_020362d4();
}

s32 func_02037c1c(void) {
u32 func_020364f4(void);u32 func_0202f248(void);u32 n;
switch(func_020364f4()){
case 0:return 1;
case 1:return 2;
case 2:case 3:n=func_0202f248();if(n>99)n=99;func_02037638(8,0xffff2cac-n);return 3;
case 4:return 0;
default:return 3;
}
}

s32 func_02037c90(void) {
    extern s32 data_0213d114;
    return data_0213d114;
}

s32 func_02037ca0(s32 a,s32 b){
extern s32 data_0213d1b4;extern s64 data_0213d1b8,data_0213d1c0;
s32 func_0200f0ac(s32,s32);s64 func_0200f7e0(s32,s32);void func_0200f9c4(s32,s32);
s64 t;u64 d;
if(!data_0213d1b4)return 0;
if(func_0200f0ac(a,b))return 0;
t=func_0200f7e0(a,b);if(t==-1)return 0;
if(t<data_0213d1b8)t+=0xbc191380LL;
d=t-data_0213d1c0;
if((s64)d<0 || (s64)d>0xbc19137fLL)return 0;
func_0200f9c4(a,b);return 1;
}

M2C_UNK func_02037d78(s32 a,s32 b,s32 c,s32 d){
 M2C_UNK func_0200567c(s32,s32,void *,...);M2C_UNK func_02068c34(s32);extern M2C_UNK data_020fc884;
 func_0200567c(c,0x1000,&data_020fc884,d,a,d,b);func_02068c34(c);
}

void func_02037db0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02037d78(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02068c34(M2C_UNK);
    s32 func_02068ee0(M2C_UNK, M2C_UNK);
    func_02037d78(arg0, arg1, func_02068ee0(arg2, 0), arg3);
    func_02068c34(arg2);
}

s32 func_02037df0(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg3) {
    s8 *r5;
    s8 *q;
    s32 len;
    if (arg1 == (s8 *)0) {
        return -1;
    }
    r5 = func_02068ee0(arg2, arg3);
    if (r5 == (s8 *)0) {
        return -1;
    }
    for (;;) {
        len = func_02068c34(arg0);
        if (func_02068eac((u8 *)(r5 + 1), (u8 *)arg0, len) != 0) {
            goto next;
        }
        if (arg3 == *(s8 *)(func_02068c34(arg0) + r5 + 1)) {
            goto extract;
        }
    next:
        q = func_02068ee0(r5 + 1, arg3);
        if (q == (s8 *)0) {
            return -1;
        }
        r5 = func_02068ee0(q + 1, arg3);
        if (r5 == (s8 *)0) {
            return -1;
        }
    }
extract:
    q = func_02068ee0(r5 + 1, arg3);
    if (q == (s8 *)0) {
        return -1;
    }
    r5 = q;
    q = func_02068ee0(r5 + 1, arg3);
    if (q != (s8 *)0) {
        len = (s32)(q - (r5 + 1));
    } else {
        len = func_02068c34(r5 + 1);
    }
    func_02068d18(arg1, r5 + 1, len);
    arg1[len] = 0;
    return len;
}

s32 func_02038020(u16 *a){s32 i=0;if(*a){do{i++;}while(a[i]);}return i;}

