/* 9 functions from 0x0204EEE8 to 0x0204FED0 (main), found by ds-decomp. */
#include "common.h"

s32 func_0204eee8(void *arg0, void *arg1) {
    return 0;
}

s32 func_0204f89c(void **arg0,s32 arg1,s32 arg2,void *arg3) {
 void func_0204fea0(M2C_UNK,M2C_UNK,M2C_UNK);
 extern M2C_UNK data_020fddcc;
 extern M2C_UNK data_020fdda0;
 extern M2C_UNK data_020fde5c;
 extern M2C_UNK data_020fde20;
 extern M2C_UNK data_020fddc4;
 u8 buf[0xdb0]; void *p;
 p=*arg0;
 func_020580fc(buf,arg3,0xdad);
 func_0204fea0(arg0,p+0x1f4,&data_020fddcc);
 func_0204fed0(arg0,p+0x1f4,arg2);
 func_0204fea0(arg0,p+0x1f4,&data_020fdda0);
 func_0204fed0(arg0,p+0x1f4,M2C_FIELD(p,s32*,0x198));
 func_0204fea0(arg0,p+0x1f4,&data_020fde5c);
 func_0204fed0(arg0,p+0x1f4,arg1);
 func_0204fea0(arg0,p+0x1f4,&data_020fde20);
 func_0204fea0(arg0,p+0x1f4,(s32)buf);
 func_0204fea0(arg0,p+0x1f4,&data_020fddc4);
 return 0;
}

s32 func_0204f978(void **a,s32 b,s32 c,void *d) {
s32 func_0205528c(void);
s32 func_02055b84(void **,s32,void **);
s32 func_020552e0(void **,s32,s32);
s32 func_02055360(void **,s32);
s32 func_020553c4(void **,s32);
s32 func_02055550(void **,s32,s32,void *);
void *p; s32 v,r;
v=func_0205528c();
if(!v) {
if(!func_02055b84(a,b,&p) || !M2C_FIELD(p,void **,8) || !M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,0x14)) return func_0204f89c(a,b,c,d);
v=func_020552e0(a,b,1);
if(!v) return 1;
if(!M2C_FIELD(p,s32 *,0x18)) {r=func_02055360(a,v);if(r)return r;}
else {r=func_020553c4(a,v);if(r)return r;}
}
r=func_02055550(a,v,c,d);if(!r)return 0;return r;
}

s32 func_0204fa60(void **arg0, M2C_UNK arg1) {
    M2C_UNK func_020377c4(s32);
    s32 func_02055b84(void **, M2C_UNK, void **);
    M2C_UNK func_02055bf4(void **, void *);
    s32 func_02055d6c(void *);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    unsigned temp_r0;
    void *sp0;
    s32 func_0204ee40(void **);
    extern M2C_UNK data_020fde60;
    register void *temp_r5;

    temp_r5 = *arg0;
    if (func_02055b84(arg0, arg1, &sp0) == 0) {
        func_02058644(arg0, &data_020fde60);
        return 2;
    }
    if (M2C_FIELD(sp0, volatile s32 *, 0x10) == 0) {
        func_02058644(arg0, &data_020fde60);
        return 2;
    }
    temp_r0 = func_0204ee40(arg0);
    if (temp_r0) {
        return temp_r0;
    }
    M2C_FIELD(sp0, s32 *, 0x14) = (s32) (M2C_FIELD(sp0, s32 *, 0x14) - 1);
    if ((M2C_FIELD(temp_r5, s32 *, 0x100) == 0) && (M2C_FIELD(sp0, s32 *, 0x14) <= 0)) {
        func_020377c4(M2C_FIELD(sp0, s32 *, 0x10));
        M2C_FIELD(sp0, s32 *, 0x10) = 0;
        if (func_02055d6c(sp0) != 0) {
            func_02055bf4(arg0, sp0);
        }
    }
    return 0;
}

s32 func_0204fb2c(void *unused,void *arg1,s32 arg2) {
s32 *p=M2C_FIELD(arg1,s32 **,8);
if(p) { s32 n=*p; if(n>arg2) *p=n-1; }
return 1;
}

s32 func_0204fb50(void **a,s32 b) {
void func_0204fea0(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_0204fb2c(void *,void *,s32);
s32 func_02055b84(void **,s32,void **);
s32 func_02055d6c(void *);
M2C_UNK func_02055bf4(void **,void *);
M2C_UNK func_02058644(void **,M2C_UNK *);
M2C_UNK func_020377c4(s32);
void func_020640a8(void *,void *,void *,s32);
extern M2C_UNK data_020fde60,data_020fde74,data_020fdda0,data_020fde80,data_020fddc4,data_020fde90,data_020fde9c,data_020fdd84,data_020fdea8;
void *p=*a,*q; s32 n;
if(!func_02055b84(a,b,&q)){func_02058644(a,&data_020fde60);return 2;}
func_0204fea0(a,p+0x1f4,&data_020fde74);
func_0204fea0(a,p+0x1f4,&data_020fdda0);
func_0204fed0(a,p+0x1f4,M2C_FIELD(p,s32 *,0x198));
func_0204fea0(a,p+0x1f4,&data_020fde80);
func_0204fed0(a,p+0x1f4,M2C_FIELD(q,s32 *,0));
func_0204fea0(a,p+0x1f4,&data_020fddc4);
if(M2C_FIELD(q,void **,8)){
n=M2C_FIELD(M2C_FIELD(q,void **,8),s32 *,0);
if(n<0)func_020640a8(&data_020fde90,&data_020fde9c,&data_020fdd84,0x1fd);
func_020377c4(M2C_FIELD(M2C_FIELD(q,void **,8),s32 *,8));
M2C_FIELD(M2C_FIELD(q,void **,8),s32 *,8)=0;
func_020377c4(M2C_FIELD(M2C_FIELD(q,void **,8),s32 *,12));
M2C_FIELD(M2C_FIELD(q,void **,8),s32 *,12)=0;
func_020377c4(M2C_FIELD(q,s32 *,8));M2C_FIELD(q,s32 *,8)=0;
if(func_02055d6c(q))func_02055bf4(a,q);
if(--M2C_FIELD(p,s32 *,0x430)<0)func_020640a8(&data_020fdea8,&data_020fde9c,&data_020fdd84,0x204);
func_02055cd0(a,func_0204fb2c,n);
}
return 0;
}

s32 func_0204fcfc(void **a,void *b,s32 c) {
extern char data_020fdf5c[],data_020fdf74[],data_020fdf0c[];
extern M2C_UNK data_020fdf80;
void func_020640a8(void *,void *,void *,s32);
void *func_020377a8(void *,s32);
M2C_UNK func_02058644(void **,M2C_UNK *);
s32 len,cap;
u8 *p;
if(!b) func_020640a8(data_020fdf5c,data_020fdf74,data_020fdf0c,0x25);
len=M2C_FIELD(b,s32 *,8);
p=M2C_FIELD(b,u8 **,0);
cap=M2C_FIELD(b,s32 *,4);
if(cap==len) {
cap+=0x800;
p=func_020377a8(p,cap+1);
if(!p) {func_02058644(a,&data_020fdf80);return 1;}
}
p[len]=c;
p[len+1]=0;
M2C_FIELD(b,s32 *,8)++;
M2C_FIELD(b,s32 *,4)=cap;
M2C_FIELD(b,u8 **,0)=p;
return 0;
}

s32 gpiAppendStringToBufferLen(void **a,void *b,void *s,s32 n) {
extern char data_020fdf90[],data_020fdf74[],data_020fdf40[],data_020fdfa0[],data_020fdf5c[];
extern M2C_UNK data_020fdf80;
void func_020640a8(void *,void *,void *,s32);
void *func_020377a8(void *,s32);
M2C_UNK func_02058644(void **,M2C_UNK *);
s32 len,cap; u8 *p;
if(!s)func_020640a8(data_020fdf90,data_020fdf74,data_020fdf40,0x51);
if(n<0)func_020640a8(data_020fdfa0,data_020fdf74,data_020fdf40,0x52);
if(!b)func_020640a8(data_020fdf5c,data_020fdf74,data_020fdf40,0x53);
if(!s)return 0;
len=M2C_FIELD(b,s32 *,8);cap=M2C_FIELD(b,s32 *,4);p=M2C_FIELD(b,u8 **,0);
if(cap-len<n){cap+=n<0x800?0x800:n;p=func_020377a8(p,cap+1);if(!p){func_02058644(a,&data_020fdf80);return 1;}}
func_020651a4(p+len,s,n);p[len+n]=0;
M2C_FIELD(b,s32 *,8)+=n;M2C_FIELD(b,s32 *,4)=cap;M2C_FIELD(b,u8 **,0)=p;
return 0;
}

void func_0204fea0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 gpiAppendStringToBufferLen(void **, void *, void *, s32);
    s32 func_02068c34(M2C_UNK);
    gpiAppendStringToBufferLen(arg0, arg1, arg2, func_02068c34(arg2));
}
