/* 24 functions from 0x0206EEB4 to 0x0206FC18 (main), found by ds-decomp. */
#include "common.h"
#include "string_storage.h"
extern u8 data_02100894[],data_02100888[],data_02100874[],data_021008b8[];
typedef union {double d;u64 u;} DoubleBits;
typedef struct Decimal38 { s8 sign;u8 pad;s16 exponent;u8 length;u8 digits[33]; } Decimal38;
extern u8 data_020eac40[128];
extern u32 data_02100734[6];
extern u32 data_0210074c[4];

#pragma opt_strength_reduction off
/* Convert the double `value` to the decimal number in `out`: store its sign,
 * give zero, NaN and infinity their class byte, then take the 53-bit mantissa,
 * scale it to an integer and multiply the decimal forms of the mantissa and of
 * the power of two it was scaled by. */
void DoubleToDecimal(u8 *out,double value){
u32 DoubleSignBit(double,...);s32 ClassifyDouble(double,...);s32 CountBits64(u64);
double Frexp(double,s32 *);double ScaleDoubleByExp(double,s32);u64 DoubleToU64(double);
void DecimalFromPowerOfTwo(void *,s32);void DecimalFromU64(void *,u64);void DecimalMultiply(void *,void *,void *);
s32 exponent,scale;u8 mantissa[38],power[38];u64 mantissaBits;DoubleBits parts; s8 negative;
negative=DoubleSignBit(value)!=0;
if(value==0.0){out[0]=negative;M2C_FIELD(out,u16 *,2)=0;out[4]=1;out[5]=0;return;}
if(ClassifyDouble(value)<=DOUBLE_CLASS_INFINITE){out[0]=negative;M2C_FIELD(out,u16 *,2)=0;out[4]=1;out[5]=ClassifyDouble(value)==DOUBLE_CLASS_NAN?'N':'I';return;}
if(negative)value=-value;
value=Frexp(value,&exponent);
parts.d=value;mantissaBits=parts.u|0x10000000000000ULL;
scale=53-CountBits64((mantissaBits & -mantissaBits)-1);
DecimalFromPowerOfTwo(power,exponent-scale);
value=ScaleDoubleByExp(value,scale);
DecimalFromU64(mantissa,DoubleToU64(value));
DecimalMultiply(out,mantissa,power);out[0]=negative;
}

/* Format the double value (passed through and read by DoubleToDecimal) as the
 * decimal number `number` with the digit count stored at `form`+2: convert it,
 * clamp the count to 32, round and pad the digits out to that count, shift the
 * exponent to match and add '0' to every digit to make it ASCII.  A non-finite
 * value (whose first digit byte is above 9) is left alone. */
void FormatDoubleAsDecimal(void *form, s32 valueLo, s32 valueHi, Decimal38 *number) {
 M2C_UNK RoundDecimalToDigits(void *, s32);
 void DoubleToDecimal();
 s32 n = M2C_FIELD(form,s16 *,2);
 s32 i;
 s32 unused = valueLo + valueHi;
 DoubleToDecimal(number);
 if (number->digits[0]>9U) return;
 if(n>32)n=32;
 RoundDecimalToDigits(number,n);
 while(number->length<n) {
 number->digits[number->length++]=0;
 }
 number->exponent-=number->length-1;
 i=0; if ((s32)number->length>0) do { void *p=(u8 *)number+i; u8 c=M2C_FIELD(p,u8 *,5); i++; M2C_FIELD(p,u8 *,5)=c+0x30; } while(i<number->length);
 (void)unused;
}

double func_0206f0dc(Decimal38 *input){
s32 ClassifyDouble(double,...);
double func_0206df88(double,double);
double _f2d(u32);
double func_0206e2d8(double,double);
double ScaleDoubleByExp(double,s32);
void DecimalFromDigitString(void*,void*,s32);
int func_0206eb30(void*,void*);
int Bcd_IsEqual(void*,void*);
void func_0206ec10(void*,void*,void*);
extern u32 data_021002e8;
extern u8 data_021006d0[];
extern double data_021005bc[];
Decimal38 value,a,b,c,d,e;DoubleBits nan;double x,y,tmp,scaled;volatile u64 *yp;u8 *cursor,*end;s32 exp,n,i,digits;int above,below;
if(input->length==0)return func_0206df88(0.0,input->sign==0?1.0:-1.0);
switch(input->digits[0]){
case '0':return func_0206df88(0.0,input->sign==0?1.0:-1.0);
case 'I':return func_0206df88(_f2d(data_021002e8),input->sign==0?1.0:-1.0);
case 'N':{DoubleBits *nanp;nanp=&nan;
#pragma scheduling off
nanp->u=0x7ff0000000000000ULL;if(input->sign)nanp->u|=0x8000000000000000ULL;nanp->u|=0x0008000000000000ULL;return nanp->d;
#pragma scheduling reset
}
}
value=*input;cursor=value.digits;end=cursor+value.length;
if(cursor<end)do{*cursor=(u8)(*cursor-'0');cursor++;}while(cursor<end);
value.exponent+=value.length-1;exp=value.exponent;
DecimalFromDigitString(&a,data_021006d0,0x134);
if(func_0206eb30(&a,&value))return func_0206df88(_f2d(data_021002e8),input->sign==0?1.0:-1.0);
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
if(ClassifyDouble(x)==2){(*(u64*)&x)=0x7fefffffffffffffULL;}
yp=(u64*)&y;DoubleToDecimal((u8*)&b,x);
above=0;if(!Bcd_IsEqual(&b,&value)){
above=0;if(func_0206eb30(&b,&value))above=1;
for(;;){
below=above==0;y=x;
if(!below){(*(u64*)&y)++;if(ClassifyDouble(y)==2)break;}else (*yp)--;DoubleToDecimal((u8*)&c,y);
if(above){if(!func_0206eb30(&c,&value))break;}
if(!above && !func_0206eb30(&value,&c)){d=b;b=c;c=d;tmp=x;x=y;y=tmp;break;}
b=c;x=y;
}
func_0206ec10(&d,&value,&b);func_0206ec10(&e,&c,&value);
if(Bcd_IsEqual(&d,&e)){if((*(u64*)&x)&1)x=y;}
else if(!func_0206eb30(&d,&e))x=y;
}
if(value.sign)x=-x;return x;
}

#pragma opt_strength_reduction reset
/* Returns the number of one bits in `value`, by the classic SWAR popcount
 * (folding the pairs, then the nibbles, then the bytes and halves together). */
s32 CountBits64(unsigned long long value) {
 value=value-((value>>1)&0x5555555555555555ULL);
 value=(value&0x3333333333333333ULL)+((value>>2)&0x3333333333333333ULL);
 value=(value+(value>>4))&0x0f0f0f0f0f0f0f0fULL;
 value+=value>>8; value+=value>>16; value+=value>>32;
 return (u32)value&255;
}

u32 DoubleSignBit(double x, ...) { return ((u32 *)&x)[1] & 0x80000000; }

/* Classify the double `x` for the software-float layer: a DOUBLE_CLASS_* value
 * from its exponent and mantissa fields. */
s32 ClassifyDouble(double x, ...) {
    u32 hi = ((u32 *)&x)[1];
    u32 exp = hi & DOUBLE_EXP_HI;
    if (exp != 0) {
        if (exp == DOUBLE_EXP_HI) return ((hi & DOUBLE_MANTISSA_HI) || ((u32 *)&x)[0]) ? DOUBLE_CLASS_NAN : DOUBLE_CLASS_INFINITE;
    } else return ((hi & DOUBLE_MANTISSA_HI) || ((u32 *)&x)[0]) ? DOUBLE_CLASS_SUBNORMAL : DOUBLE_CLASS_ZERO;
    return DOUBLE_CLASS_NORMAL;
}

double func_0206f818(double x, s32 n) {
 double Frexp(double, s32 *);
 double ScaleDoubleByExp(double, s32);
 s32 exponent;
 x=Frexp(x,&exponent);
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
    M2C_UNK IntegerToRadixString();
    IntegerToRadixString();
}

/* Build the exception's message string `string` from the already-allocated
 * `buffer`: wrap the buffer in a 16-byte owner block of its own (so it lives
 * and dies with the exception) and hand a disarmed temporary owner record to
 * the destructor, the string having taken the buffer over. */
void *func_0206f8c4(u32 *string,u32 buffer,u32 firstArg,...) {
 void *MemAlloc(u32);
 s32 *func_0206f9d4(s32 *);
 u32 temp[2];

 void *owner;
 string[0]=buffer;
 temp[0]=buffer; temp[1]=(u32)&firstArg;
 owner=MemAlloc(16);
 if(owner) {((u32*)owner)[0]=(u32)data_02100734;((u32*)owner)[1]=1;((u32*)owner)[2]=1;((u32*)owner)[0]=(u32)data_0210074c;((u32*)owner)[3]=buffer;}
 string[1]=(u32)owner;
 temp[0]=0;
 func_0206f9d4((s32 *)temp);
 return string;
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
void StringStorageReserve(StringStorage *self,u32 capacity) {
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

