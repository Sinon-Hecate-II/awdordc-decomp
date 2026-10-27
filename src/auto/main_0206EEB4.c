/* 24 functions from 0x0206EEB4 to 0x0206FC18 (main), found by ds-decomp. */
#include "common.h"
typedef union { struct { u32 flag:1; u32 capacity:31; u32 length; u8 *data; } large; struct { u8 flag:1; u8 length:7; u8 data[11]; } small; } StringStorage;
extern u8 data_02100894[],data_02100888[],data_02100874[],data_021008b8[];
typedef union {double d;u64 u;} DoubleBits;
extern u8 data_020eac40[128];
extern u32 data_02100734[6];
extern u32 data_0210074c[4];

#pragma opt_strength_reduction off
void func_0206eeb4(u8 *out,double x){
u32 func_0206f794(double,...);s32 func_0206f7a8(double,...);s32 func_0206f700(u64);
double func_0206dfd0(double,s32 *);double func_0206e08c(double,s32);u64 func_02070550(double);
void func_0206e6cc(void *,s32);void func_0206e3e0(void *,u64);void func_0206e4ac(void *,void *,void *);
s32 exp,n;u8 b[38],a[38];u64 bits;DoubleBits value; s8 sign;
sign=func_0206f794(x)!=0;
if(x==0.0){out[0]=sign;M2C_FIELD(out,u16 *,2)=0;out[4]=1;out[5]=0;return;}
if(func_0206f7a8(x)<=2){out[0]=sign;M2C_FIELD(out,u16 *,2)=0;out[4]=1;out[5]=func_0206f7a8(x)==1?'N':'I';return;}
if(sign)x=-x;
x=func_0206dfd0(x,&exp);
value.d=x;bits=value.u|0x10000000000000ULL;
n=53-func_0206f700((bits & -bits)-1);
func_0206e6cc(a,exp-n);
x=func_0206e08c(x,n);
func_0206e3e0(b,func_02070550(x));
func_0206e4ac(out,b,a);out[0]=sign;
}

void func_0206f034(void *arg0, s32 arg1, s32 arg2, void *arg3) {
 M2C_UNK func_0206e3a0(void *, s32);
 void func_0206eeb4();
 s32 n = M2C_FIELD(arg0,s16 *,2);
 s32 i;
 func_0206eeb4(arg3);
 if (M2C_FIELD(arg3,u8 *,5)>9U) return;
 if(n>32)n=32;
 func_0206e3a0(arg3,n);
 while(M2C_FIELD(arg3,u8 *,4)<n) {
 ((u8 *)arg3)[5+M2C_FIELD(arg3,u8 *,4)++]=0;
 }
 M2C_FIELD(arg3,s16 *,2)-=M2C_FIELD(arg3,u8 *,4)-1;
 i=0; if ((s32)M2C_FIELD(arg3,u8 *,4)>0) do { void *p=(u8 *)arg3+i; u8 c=M2C_FIELD(p,u8 *,5); i++; M2C_FIELD(p,u8 *,5)=c+0x30; } while(i<M2C_FIELD(arg3,u8 *,4));
}
#pragma opt_strength_reduction reset
s32 func_0206f700(unsigned long long x) {
 x=x-((x>>1)&0x5555555555555555ULL);
 x=(x&0x3333333333333333ULL)+((x>>2)&0x3333333333333333ULL);
 x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fULL;
 x+=x>>8; x+=x>>16; x+=x>>32;
 return (u32)x&255;
}

u32 func_0206f794(double x, ...) { return ((u32 *)&x)[1] & 0x80000000; }

s32 func_0206f7a8(double x, ...) {
 u32 hi=((u32 *)&x)[1];
 u32 exp=hi&0x7ff00000;
 if(exp!=0) {
 if(exp==0x7ff00000) return ((hi&0xfffff)||((u32 *)&x)[0])?1:2;
 } else return ((hi&0xfffff)||((u32 *)&x)[0])?5:3;
 return 4;
}

double func_0206f818(double x, s32 n) {
 double func_0206dfd0(double, s32 *);
 double func_0206e08c(double, s32);
 s32 exponent;
 x=func_0206dfd0(x,&exponent);
 exponent+=n;
 return func_0206e08c(x,exponent);
}

#pragma scheduling off
s32 func_0206f844(u8 *a,u8 *b) {
 u32 c,d;
 do {
 c=*a++; c=(u8)((s32)c<0?c:((s32)c<128?data_020eac40[c]:c));
 d=*b++; d=(u8)((s32)d<0?d:((s32)d<128?data_020eac40[d]:d));
 if(c<d)return -1;
 if(c>d)return 1;
 }while(c);
 return 0;
}
#pragma scheduling reset
void func_0206f8ac(void) {
    M2C_UNK func_0206f844();
    func_0206f844();
}

void func_0206f8b8(void) {
    M2C_UNK func_02064ad4();
    func_02064ad4();
}

void *func_0206f8c4(u32 *self,u32 value,u32 first,...) {
 void *func_02082028(u32);
 s32 *func_0206f9d4(s32 *);
 u32 local[2];

 u32 *p;
 self[0]=value;
 local[0]=value; local[1]=(u32)&first;
 p=func_02082028(16);
 if(p) {p[0]=(u32)data_02100734;p[1]=1;p[2]=1;p[0]=(u32)data_0210074c;p[3]=value;}
 self[1]=(u32)p;
 local[0]=0;
 func_0206f9d4((s32 *)local);
 return self;
}

s32 func_0206f944(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0206f958(void) {

}

s32 func_0206f95c(s32 arg0, M2C_UNK arg1) {
    s32 func_02074224(M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_02100708;
    if (func_02074224(arg1, &data_02100708) != 0) {
        return arg0 + 0xC;
    }
    return 0;
}

void func_0206f984(void *arg0) {
    M2C_UNK func_0208204c(s32);
    func_0208204c(M2C_FIELD(arg0, s32 *, 0xC));
}

void *func_0206f994(void *self) {
 void func_020700d8(void *);
 void func_02073bd0(void *);
 u8 object[24];
 if(M2C_FIELD(self,void **,4)) {func_020700d8(M2C_FIELD(self,void **,4));return self;}
 func_02073bd0(object);
}

void func_0206f9c0(void *arg0) {
    func_02073bd0(arg0);
}

#pragma frame_pointer reset

s32 *func_0206f9d4(s32 *arg0) {
    if (*arg0 != 0) {
        func_0208204c();
    }
    return arg0;
}

s32 func_0206f9f4(s32 arg0) {
    func_02082040();
    return arg0;
}

void func_0206fa08(void) {

}

s32 func_0206fa0c(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4);
}

void *func_0206fa14(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, s32 *, 0) << 0x1F) >> 0x1F) != 0) {
        func_02082040(M2C_FIELD(arg0, s32 *, 8));
    }
    return arg0;
}

#pragma thumb off
#pragma frame_pointer on
void func_0206fa3c(StringStorage *self,u32 capacity) {
u32 func_02068c34(void *);void *func_02082034(u32);void func_02068c50(void *,void *);void func_0207465c(void *,void *,void *);void func_02070068(void);void func_020651c4(void *,void *,u32);void *func_02082028(u32);
u8 context[20]; u32 exception[3]; u8 zero; int large; u32 size,oldcap; u8 *buffer; int allocated; u8 *old;
if(capacity>0x7ffffffeU) {
 exception[0]=(u32)data_02100888;
 {void *p=func_02082034(func_02068c34(data_02100894)+1);zero=0;func_0206f8c4(exception+1,(u32)p,*(u32 *)&zero);}
 func_02068c50((void *)exception[1],data_02100894);
 exception[0]=(u32)data_02100874;
 func_0207465c(data_021008b8,exception,func_02070068);
}
large=(self->large.flag?1:0);
if(large){size=self->large.length;oldcap=self->large.capacity;}
else {size=self->small.length;oldcap=11;}
if(capacity<size)capacity=size;
if(capacity+1<=11)capacity=11;else capacity=(capacity+16)&~15;
if(capacity==oldcap)return;
if(capacity==11){buffer=self->small.data;old=self->large.data;allocated=0;}
else {if(capacity>oldcap)buffer=func_02082028(capacity);else {buffer=func_02082028(capacity);if(!buffer){func_02074000(context);return;}}old=large?self->large.data:self->small.data;allocated=1;}
func_020651c4(buffer,old,size);buffer[size]=0;
if(large)func_02082040(old);
self->large.flag=allocated & 1;
if(!allocated)self->small.length=(u8)size;
else {self->large.length=size;self->large.data=buffer;self->large.capacity=capacity;}
}
#pragma use_frame_pointer reset

