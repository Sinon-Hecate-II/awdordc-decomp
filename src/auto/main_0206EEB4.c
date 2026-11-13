/* 24 functions from 0x0206EEB4 to 0x0206FC18 (main), found by ds-decomp. */
#include "common.h"
typedef union { struct { u32 flag:1; u32 capacity:31; u32 length; u8 *data; } large; struct { u8 flag:1; u8 length:7; u8 data[11]; } small; } StringStorage;
extern u8 data_02100894[],data_02100888[],data_02100874[],data_021008b8[];
typedef union {double d;u64 u;} DoubleBits;
typedef struct Decimal38 { s8 sign;u8 pad;s16 exponent;u8 length;u8 digits[33]; } Decimal38;
extern u8 data_020eac40[128];
extern u32 data_02100734[6];
extern u32 data_0210074c[4];

#pragma opt_strength_reduction off
void func_0206eeb4(u8 *out,double x){
u32 func_0206f794(double,...);s32 func_0206f7a8(double,...);s32 func_0206f700(u64);
double func_0206dfd0(double,s32 *);double ScaleDoubleByExp(double,s32);u64 func_02070550(double);
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
x=ScaleDoubleByExp(x,n);
func_0206e3e0(b,func_02070550(x));
func_0206e4ac(out,b,a);out[0]=sign;
}

void func_0206f034(void *arg0, s32 arg1, s32 arg2, void *arg3) {
 M2C_UNK func_0206e3a0(void *, s32);
 void func_0206eeb4();
 s32 n = M2C_FIELD(arg0,s16 *,2);
 s32 i;
 s32 unused = arg1 + arg2;
 func_0206eeb4(arg3);
 if (M2C_FIELD(arg3,u8 *,5)>9U) return;
 if(n>32)n=32;
 func_0206e3a0(arg3,n);
 while(M2C_FIELD(arg3,u8 *,4)<n) {
 ((u8 *)arg3)[5+M2C_FIELD(arg3,u8 *,4)++]=0;
 }
 M2C_FIELD(arg3,s16 *,2)-=M2C_FIELD(arg3,u8 *,4)-1;
 i=0; if ((s32)M2C_FIELD(arg3,u8 *,4)>0) do { void *p=(u8 *)arg3+i; u8 c=M2C_FIELD(p,u8 *,5); i++; M2C_FIELD(p,u8 *,5)=c+0x30; } while(i<M2C_FIELD(arg3,u8 *,4));
 (void)unused;
}

double func_0206f0dc(Decimal38 *input){
s32 func_0206f7a8(double,...);
double func_0206df88(double,double);
double func_0207191c(u32);
double func_0206e2d8(double,double);
double ScaleDoubleByExp(double,s32);
void func_0206e630(void*,void*,s32);
int func_0206eb30(void*,void*);
int func_0206ea50(void*,void*);
void func_0206ec10(void*,void*,void*);
extern u32 data_021002e8;
extern u8 data_021006d0[];
extern double data_021005bc[];
Decimal38 value,a,b,c,d,e;DoubleBits nan;double x,y,tmp,scaled;volatile u64 *yp;u8 *cursor,*end;s32 exp,n,i,digits;int above,below;
if(input->length==0)return func_0206df88(0.0,input->sign==0?1.0:-1.0);
switch(input->digits[0]){
case '0':return func_0206df88(0.0,input->sign==0?1.0:-1.0);
case 'I':return func_0206df88(func_0207191c(data_021002e8),input->sign==0?1.0:-1.0);
case 'N':{DoubleBits *nanp;nanp=&nan;
#pragma scheduling off
nanp->u=0x7ff0000000000000ULL;if(input->sign)nanp->u|=0x8000000000000000ULL;nanp->u|=0x0008000000000000ULL;return nanp->d;
#pragma scheduling reset
}
}
value=*input;cursor=value.digits;end=cursor+value.length;
if(cursor<end)do{*cursor=(u8)(*cursor-'0');cursor++;}while(cursor<end);
value.exponent+=value.length-1;exp=value.exponent;
func_0206e630(&a,data_021006d0,0x134);
if(func_0206eb30(&a,&value))return func_0206df88(func_0207191c(data_021002e8),input->sign==0?1.0:-1.0);
cursor=value.digits;x=*cursor++;
while(cursor<end){
n=(end-cursor)%8;if(n==0)n=8;
digits=0;for(i=0;i<n;i++)digits=10*digits+*cursor++;
scaled=x*data_021005bc[n-1];tmp=scaled+(double)digits;
if(digits!=0 && scaled==tmp)break;
x=tmp;exp-=n;
}
if(exp<0)x/=func_0206e2d8(5.0,(double)-exp);
else x*=func_0206e2d8(5.0,(double)exp);
x=ScaleDoubleByExp(x,exp);
if(func_0206f7a8(x)==2){(*(u64*)&x)=0x7fefffffffffffffULL;}
yp=(u64*)&y;func_0206eeb4((u8*)&b,x);
above=0;if(!func_0206ea50(&b,&value)){
above=0;if(func_0206eb30(&b,&value))above=1;
for(;;){
below=above==0;y=x;
if(!below){(*(u64*)&y)++;if(func_0206f7a8(y)==2)break;}else (*yp)--;func_0206eeb4((u8*)&c,y);
if(above){if(!func_0206eb30(&c,&value))break;}
if(!above && !func_0206eb30(&value,&c)){d=b;b=c;c=d;tmp=x;x=y;y=tmp;break;}
b=c;x=y;
}
func_0206ec10(&d,&value,&b);func_0206ec10(&e,&c,&value);
if(func_0206ea50(&d,&e)){if((*(u64*)&x)&1)x=y;}
else if(!func_0206eb30(&d,&e))x=y;
}
if(value.sign)x=-x;return x;
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
 if(exp==0x7ff00000) return ((hi&0x000fffff)||((u32 *)&x)[0])?1:2;
 } else return ((hi&0x000fffff)||((u32 *)&x)[0])?5:3;
 return 4;
}

double func_0206f818(double x, s32 n) {
 double func_0206dfd0(double, s32 *);
 double ScaleDoubleByExp(double, s32);
 s32 exponent;
 x=func_0206dfd0(x,&exponent);
 exponent+=n;
 return ScaleDoubleByExp(x,exponent);
}

#pragma opt_if_conversion off
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
#pragma opt_if_conversion reset
void func_0206f8ac(void) {
    M2C_UNK func_0206f844();
    func_0206f844();
}

void func_0206f8b8(void) {
    M2C_UNK func_02064ad4();
    func_02064ad4();
}

void *func_0206f8c4(u32 *self,u32 value,u32 first,...) {
 void *MemAlloc(u32);
 s32 *func_0206f9d4(s32 *);
 u32 local[2];

 void *p;
 self[0]=value;
 local[0]=value; local[1]=(u32)&first;
 p=MemAlloc(16);
 if(p) {((u32*)p)[0]=(u32)data_02100734;((u32*)p)[1]=1;((u32*)p)[2]=1;((u32*)p)[0]=(u32)data_0210074c;((u32*)p)[3]=value;}
 self[1]=(u32)p;
 local[0]=0;
 func_0206f9d4((s32 *)local);
 return self;
}

s32 func_0206f944(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
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
    M2C_UNK MemFreeArray(s32);
    MemFreeArray(M2C_FIELD(arg0, s32 *, 0xC));
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
        MemFreeArray();
    }
    return arg0;
}

s32 func_0206f9f4(s32 arg0) {
    MemFree();
    return arg0;
}

void func_0206fa08(void) {

}

s32 func_0206fa0c(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4);
}

void *func_0206fa14(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, s32 *, 0) << 0x1F) >> 0x1F) != 0) {
        MemFree(M2C_FIELD(arg0, s32 *, 8));
    }
    return arg0;
}

#pragma use_frame_pointer on
void func_0206fa3c(StringStorage *self,u32 capacity) {
u32 StringLength(void *);void *MemAllocArray(u32);void StringCopy(void *,void *);void func_0207465c(void *,void *,void *);void func_02070068(void);void MemMove(void *,void *,u32);void *MemAlloc(u32);
u8 context[20]; u32 exception[3]; u8 zero; int large; u32 size,oldcap; u8 *buffer; int allocated; u8 *old;
if(capacity>0x7ffffffeU) {
 exception[0]=(u32)data_02100888;
 {void *p=MemAllocArray(StringLength(data_02100894)+1);zero=0;func_0206f8c4(exception+1,(u32)p,*(u32 *)&zero);}
 StringCopy((void *)exception[1],data_02100894);
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
else {if(capacity>oldcap)buffer=MemAlloc(capacity);else {buffer=MemAlloc(capacity);if(!buffer){func_02074000(context);return;}}old=large?self->large.data:self->small.data;allocated=1;}
MemMove(buffer,old,size);buffer[size]=0;
if(large)MemFree(old);
self->large.flag=allocated & 1;
if(!allocated)self->small.length=(u8)size;
else {self->large.length=size;self->large.data=buffer;self->large.capacity=capacity;}
}

