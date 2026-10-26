/* 28 functions from 0x02057D80 to 0x02058CA4 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_020ff3ec, data_0213dce0;
extern s32 data_020ff43c;
extern M2C_UNK data_0213dcd0, data_020ff410, data_020ff414, data_020ff3f4;

s32 func_02057ed0(s32 a,s32 b,s32 c,s32 d,void *p) {
s32 func_020556e0(s32,s32,s32,s32);s32 func_020501d8(s32,s32,void *);s32 func_0205575c(s32,s32,void *,s32);void func_020675e4(void *,void *,s32,s32);
extern M2C_UNK data_020ff228,data_020ff22c;
u8 buf[32];s32 r;
if(!p)p=&data_020ff228;
r=func_020556e0(a,c,201,b);if(r)return r;
func_020675e4(buf,&data_020ff22c,1,d);
r=func_020501d8(a,c,buf);if(r)return r;
r=func_0205575c(a,c,p,-1);if(!r)r=0;return r;
}

void func_02057f74(s32 a,s32 b,s32 c,s32 d) {
s32 func_02058254(s32,void *,void *,s32);s32 func_02068adc(void *,void *,void *,void *,void *);
extern M2C_UNK data_020ff244,data_020ff24c;
u8 buf[64];s32 z,y,x;
if(!func_02058254(d,&data_020ff244,buf,64))return;
if(func_02068adc(buf,&data_020ff24c,&x,&y,&z)!=3)return;
func_02057ed0(a,(s32)&x,b,2,0);
}

M2C_UNK func_020580fc(s32 a,s32 b,s32 n) {
void func_020640a8(void *,void *,void *,s32);void func_02068d18(s32,s32,s32);
extern M2C_UNK data_020ff2cc,data_020ff2dc,data_020ff2a0,data_020ff2ec;
if(!a)func_020640a8(&data_020ff2cc,&data_020ff2dc,&data_020ff2a0,47);
if(!b)func_020640a8(&data_020ff2ec,&data_020ff2dc,&data_020ff2a0,48);
func_02068d18(a,b,n);
M2C_FIELD(a+n,u8 *,-1)=0;
return a+n;
}

void func_02058170(s32 a, ...) {}

s32 func_0205817c(void **a,s32 b,s32 c) {
s32 func_02068eac(s32,void *,s32);s32 func_02058254(s32,void *,void *,s32);s32 func_0206ad38(void *);void *func_02068fdc(s32,void *);void func_02050744(void *,s32,s32);
extern M2C_UNK data_020ff2f8,data_020ff300,data_020ff308,data_020ff314;
u8 buf[16];void *p=*a;
if(func_02068eac(b,&data_020ff2f8,7)==0){
if(func_02058254(b,&data_020ff300,buf,16))M2C_FIELD(p,s32 *,0x418)=func_0206ad38(buf);
if(!func_02058254(b,&data_020ff308,p,256))M2C_FIELD(p,u8 *,0)=0;
if(c){s32 x=func_02068fdc(b,&data_020ff314)!=0;func_02050744(a,4,x!=0);}
return 1;}return 0;
}

s32 func_0205835c(s32 p,s32 a,s32 *out){
s32 func_0204943c(s32,s32,s32*,s32*);void func_02058170(s32,...);void func_02058620(void**,s32,s32);void func_02050744(void*,s32,s32);
extern M2C_UNK data_020ff350,data_020ff364,data_020ff39c,data_020ff3b4;
s32 x=0,y=0; s32 r=func_0204943c(a,0,&x,&y);
if(r==-1){func_02058170(p,&data_020ff350);func_02058620((void**)p,5,(s32)&data_020ff364);func_02050744((void*)p,3,1);return 3;}
if(r>0){if(y){func_02058170(p,&data_020ff39c);*out=4;return 0;}if(x){func_02058170(p,&data_020ff3b4);*out=3;return 0;}}
*out=0;return 0;
}

void func_02058620(void **arg0, s32 arg1, M2C_UNK arg2) {
    void *temp_r4;

    temp_r4 = *arg0;
    func_020580fc(temp_r4, arg2, 0x100);
    M2C_FIELD(temp_r4, s32 *, 0x418) = arg1;
}

void func_02058644(s32 *arg0, M2C_UNK arg1) {
    M2C_UNK func_020580fc(s32, M2C_UNK, M2C_UNK);
    func_020580fc(*arg0, arg1, 0x100);
}

void *func_02058658(void *a,s32 b,s32 c,void *d){
void *func_02058b94(void *);void func_020640a8(void *,void *,void *,s32);s32 func_02049274(s32);
s32 func_02058b18(void *,void *);void func_02048eac(s32,void *);void *func_02058bb4(void *,s32);
s32 buf[5];
if(!a)a=M2C_FIELD(&data_0213dcd0,void **,4);
if(!a)func_020640a8(&data_020ff410,&data_020ff414,&data_020ff3f4,120);
buf[0]=func_02049274(b);buf[1]=c;buf[3]=0;buf[2]=1;
func_02058b18(buf,d);func_02048eac(M2C_FIELD(a,s32 *,0),buf);
return func_02058b94(func_02058bb4(a,b));
}

s32 func_020586f4(void *a,s32 b,void *c){
void *func_02058bb4(void *,s32);s32 func_02058b18(void *,void *);
void *p=func_02058bb4(a,b);if(!p)return 0;
M2C_FIELD(p,s32 *,8)=0;return func_02058b18(p,c);
}

s32 func_02058720(void *a,s32 b,void *c){
void *func_02058b94(void *);M2C_UNK *func_02058ab4(s32);M2C_UNK *func_02058acc(s32,s32);
void *func_02058bb4(void *,s32);s32 func_02058b18(void *,void *);s32 func_0205893c(void *,s32,void *);
s64 func_02070134(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(c,s32 *,0)+M2C_FIELD(q,s32 *,0)));}
else if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070134(*(s64 *)c,*(s64 *)q);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
else return func_0205893c(a,b,c);
}

s32 func_020587b4(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_02070b70(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(q,s32 *,0) - M2C_FIELD(c,s32 *,0)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070b70(*(s64 *)q,*(s64 *)c);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_02058838(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_02070658(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(c,s32 *,0) * M2C_FIELD(q,s32 *,0)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070658(*(s64 *)c,*(s64 *)q);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_020588b8(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_020724f8(s64,s64);s32 func_020720f0(s32,s32);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(func_020720f0(M2C_FIELD(q,s32 *,0),M2C_FIELD(c,s32 *,0))));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_020724f8(*(s64 *)q,*(s64 *)c);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_0205893c(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);void *func_02058b94(void *);void func_020640a8(void *,void *,void *,s32);s32 func_02068c34(void *);void *func_02037794(s32);void func_02068c50(void *,void *);void func_02068d68(void *,void *);void func_020377c4(void *);s32 func_02058b18(void *,void *);
extern M2C_UNK data_020ff420,data_020ff414,data_020ff400;
void *p=func_02058bb4(a,b);void *q;void *r;s32 n;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)!=2)func_020640a8(&data_020ff420,&data_020ff414,&data_020ff400,209);
q=func_02058b94(p);n=func_02068c34(q);n+=func_02068c34(c);
r=func_02037794(n+1);func_02068c50(r,q);func_02068d68(r,c);func_02058b18(p,r);func_020377c4(r);return (s32)func_02058b94(p);
}

s32 func_020589e0(void *a,s32 b,void *c) {
s64 func_020705dc(s32);s64 func_02070658(s64,s64);s64 func_02070134(s64,s64);s64 func_020724f8(s64,s64);s32 func_020720f0(s32,s32);void *func_02058bb4(void *,s32);void *func_02058b94(void *);s32 func_02058b18(void *,void *);M2C_UNK *func_02058ab4(s32);M2C_UNK *func_02058acc(s32,s32);
void *p=func_02058bb4(a,b);void *q;s32 n;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);n=++M2C_FIELD(p,s32 *,8);return func_02058b18(p,func_02058ab4(func_020720f0(n*M2C_FIELD(q,s32 *,0)+M2C_FIELD(c,s32 *,0),n)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);n=++M2C_FIELD(p,s32 *,8);v=func_02070134(*(s64 *)c,func_02070658(func_020705dc(n),*(s64 *)q));v=func_020724f8(v,func_020705dc(n));return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

M2C_UNK *func_02058ab4(s32 a) {
    *(s32 *)&data_0213dcd0 = a;
    return (M2C_UNK *)&data_0213dcd0;
}

M2C_UNK *func_02058acc(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213dcd0;
    extern M2C_UNK data_0213dcd8;
    M2C_FIELD(&data_0213dcd0, s32 *, 8) = arg0;
    M2C_FIELD(&data_0213dcd0, s32 *, 0xC) = arg1;
    return &data_0213dcd8;
}

s8 *func_02058ae8(s8 *p) {
s8 *q=p;s32 c=*p;
if(c){do{if(c==92)*p=47;c=*++p;}while(c);}
return q;
}

s32 func_02058b18(void *p,void *q) {
void func_020377c4(void *);s32 func_02049274(s32);s8 *func_02058ae8(s8 *);void *func_02058b94(void *);
s32 t=M2C_FIELD(p,s32 *,4);void *r;
if(t==0)M2C_FIELD(p,s32 *,12)=M2C_FIELD(q,s32 *,0);
else if(t==1){M2C_FIELD(p,double *,12)=M2C_FIELD(q,double *,0);}
else if(t==2){
r=M2C_FIELD(p,void **,12);if(r)func_020377c4(r);
if(!q)r=0;else r=func_02058ae8((s8 *)func_02049274((s32)q));
M2C_FIELD(p,void **,12)=r;
}
return (s32)func_02058b94(p);
}

void *func_02058b94(void *arg0) {
    if (arg0 == NULL) {
        return NULL;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 2) {
        return M2C_FIELD(arg0, void **, 0xC);
    }
    return arg0 + 0xC;
}

void *func_02058bb4(void *a,s32 b){
void func_020640a8(void *,void *,void *,s32);void *func_02048ff8(s32,void *);
s32 buf[5];
if(!a)a=M2C_FIELD(&data_0213dcd0,void **,4);
if(!a)func_020640a8(&data_020ff410,&data_020ff414,&data_020ff3ec,0x153);
buf[0]=b;return func_02048ff8(M2C_FIELD(a,s32 *,0),buf);
}

void func_02058c14(void){
void func_020496cc(s32,s32);void func_020496b8(s32);void func_0205954c(void);void func_020377c4(void *);
if(data_020ff43c!=-1){func_020496cc(data_020ff43c,2);func_020496b8(data_020ff43c);}
data_020ff43c=-1;
func_0205954c();
if(M2C_FIELD(&data_0213dce0,void **,12)){func_020377c4(M2C_FIELD(&data_0213dce0,void **,12));M2C_FIELD(&data_0213dce0,s32 *,12)=0;M2C_FIELD(&data_0213dce0,s32 *,44)=0;M2C_FIELD(&data_0213dce0,s32 *,0)=0;}
}

s32 func_02058c84(void) {
    extern s32 data_020ff43c;
    if (data_020ff43c != -1) {
        return 1;
    }
    return 0;
}

