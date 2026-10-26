/* 24 functions from 0x02044E04 to 0x02045D94 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[4]; } CallbackRecord;

s32 func_02044e04(void) {
    M2C_UNK func_0204b378();
    extern M2C_UNK data_0213db18;
    func_0204b378();
    M2C_FIELD(&data_0213db18, s32 *, 4) = (s32) (M2C_FIELD(&data_0213db18, s32 *, 4) + 1);
    return 1;
}

s32 func_02044e28(void){extern M2C_UNK data_0213db18;void func_0204b3cc(void);void func_02045374(void);s32 n;if(M2C_FIELD(&data_0213db18,s32 *,4)<=0)return 1;func_0204b3cc();n=M2C_FIELD(&data_0213db18,s32 *,4)-1;M2C_FIELD(&data_0213db18,s32 *,4)=n;if(n==0)func_02045374();return 1;}

s32 func_02044e68(void) {
    s32 func_0203761c();
    M2C_UNK func_0204b674();
    if (func_0203761c() != 0) {
        return 0;
    }
    func_0204b674();
    return 1;
}

s32 func_02044e88(s32 unused,s32 a,s32 b,s32 c,void *arg){void func_020376d8(s32,s32,s32);void func_02045138(s32);void func_020452f0(void *);s32 flag;void (*cb)(s32,s32,s32,s32);void *p=arg;s32 x;cb=M2C_FIELD(p,void (**)(s32,s32,s32,s32),4);flag=M2C_FIELD(p,s32 *,12);if(cb){if(a==0)cb(b,c,a,M2C_FIELD(p,s32 *,0));else{func_02045138(a);cb(0,0,a,M2C_FIELD(p,s32 *,0));}}if(a!=0||flag==1){x=M2C_FIELD(p,s32 *,16);if(x==0)flag=1;else func_020376d8(4,x,0);}func_020452f0(p);if(flag)return 1;return 0;}

void func_02044f24(s32 unused,s32 a,s32 b,s32 c,s32 d,s32 e,void *p){
void (*cb)(s32,s32,s32,s32,s32,s32)=M2C_FIELD(p,void (**)(s32,s32,s32,s32,s32,s32),8);
if(!cb)return;cb(a,b,c,d,e,M2C_FIELD(p,s32 *,0));
}

void func_02045110(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_UNK func_02044f6c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    func_02044f6c(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

void *func_02045294(CallbackRecord *src){void *func_02037694(s32,s32);extern M2C_UNK data_0213db18;void *p=func_02037694(4,28);if(!p)return 0;*(CallbackRecord *)p=*src;M2C_FIELD(p,s32 *,24)=0;M2C_FIELD(p,s32 *,16)=0;if(!M2C_FIELD(&data_0213db18,void **,0)){M2C_FIELD(&data_0213db18,void **,0)=p;return p;}else{M2C_FIELD(p,void **,24)=M2C_FIELD(&data_0213db18,void **,0);M2C_FIELD(&data_0213db18,void **,0)=p;}return p;}

void func_020452f0(void *a) {
 extern M2C_UNK data_0213db18; void func_020376d8(s32,s32,s32);
 void *p=M2C_FIELD(&data_0213db18,void **,0),*q,*n;
 if(!p)return;
 if(p==a){n=M2C_FIELD(p,void **,24);func_020376d8(4,(s32)p,0);M2C_FIELD(&data_0213db18,void **,0)=n;return;}
 q=M2C_FIELD(p,void **,24);
 while(q) {
 if(q!=a)p=q;
 else {n=M2C_FIELD(p,void **,24);M2C_FIELD(p,void **,24)=M2C_FIELD(n,void **,24);func_020376d8(4,(s32)n,0);return;}
 q=M2C_FIELD(q,void **,24);
 }
}

void func_02045374(void) {
 extern M2C_UNK data_0213db18;void func_020376d8(s32,s32,s32);
 void *p=M2C_FIELD(&data_0213db18,void **,0),*q;
 while(p){q=p;p=M2C_FIELD(p,void **,24);if(M2C_FIELD(q,s32 *,16))func_020376d8(4,M2C_FIELD(q,s32 *,16),0);func_020376d8(4,(s32)q,0);}
 M2C_FIELD(&data_0213db18,void **,0)=0;
}

s32 func_020453e4(s32 *a) {
 s32 func_0203761c();s32 *func_02047928(s32 *);extern s32 data_0213db20;
 s32 x; s32 *p;
 if(func_0203761c())return 1;
 if(data_0213db20!=5)return 16;
 p=func_02047928(&x);if(!x)return 17;
 a[0]=x;a[1]=*p++;a[2]=(s32)p;return 0;
}

s32 func_02045620(void){void func_020478b8(void);extern s32 data_0213db20;func_020478b8();return data_0213db20=0;}

s32 func_02045934(s32 a, s32 b, u32 c, s32 d) {
    s32 func_0203761c();
    s32 func_02047dd4(s32, u32, s32, s32);
    extern s32 data_0213db20;
    if (func_0203761c() != 0) return 1;
    if (data_0213db20 != 1 && data_0213db20 != 5) return 10;
    if (c > 1000) return 2;
    if (a < 0 || a >= 9) return 2;
    if (b < 0) return 2;
    {
        s32 r = func_02047dd4(a, c, b, d);
        if (r == 2) return 12;
        if (r == 3) return 11;
        data_0213db20 = 4;
        return 0;
    }
}

s32 func_020459ec(void) {
    s32 func_0203761c();
    s32 func_020477ac();
    extern s32 data_0213db20;
    if (func_0203761c()) return 1;
    if (data_0213db20 != 2 && data_0213db20 != 3 && data_0213db20 != 4) return 14;
    switch (func_020477ac()) {
        case 0:
        case 1:
            data_0213db20 = 6;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        case 8:
            data_0213db20 = 5;
            break;
    }
    return 0;
}

s32 func_02045a88(void) {
    extern s32 data_0213db20;
    return data_0213db20;
}

s32 func_02045ba0(s32 *a) {
    s32 func_0203761c();
    s32 func_020453e4(s32 *);
    s32 x[3], r;
    if (func_0203761c()) return 1;
    r = func_020453e4(x); if (r) return r;
    if (!a) return 2;
    switch (x[1]) {
        case 0:
            return 15;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            *a = *(s32 *)x[2];
            return 0;
    }
}

s32 func_02045c34(s32 *a) {
 s32 func_0203761c(); s32 func_020453e4(s32 *);
 s32 x[3],r;
 if(func_0203761c())return 1;
 r=func_020453e4(x);if(r)return r;
 if(!a)return 2;
 *a=M2C_FIELD(x[2],s32 *,4);return 0;
}

s32 func_02045c90(M2C_UNK arg0) {
    s32 func_020465c4(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213db28;
    if (func_020465c4(M2C_FIELD(&data_0213db28, s32 *, 8), 0x300, arg0) != 0) {
        return 1;
    }
    return 0;
}

