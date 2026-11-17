/* 18 functions from 0x0206FC18 to 0x02070B70 (main), found by ds-decomp. */
#include "common.h"
#include "string_storage.h"

typedef struct { u8 value; } Flag;
#pragma optimization_level 0
static inline void *AllocateStringElements(u32 count,u32 width) {
void *MemAllocArray(u32);
return MemAllocArray(count*width);
}
static inline void InitStringException(u32 *object,u8 *message,void *vtable) {
u32 StringLength(void *);void StringCopy(void *,void *);
void func_0206f8c4(u32 *,u32,Flag);
extern u8 data_02100888[];
u32 *text=object+1;void *p;Flag zero;
object[0]=(u32)data_02100888;
p=AllocateStringElements(StringLength(message)+1,1);
zero.value=0;
func_0206f8c4(text,(u32)p,zero);
StringCopy((void *)text[0],message);
object[0]=(u32)vtable;
}
#pragma optimization_level reset

#pragma optimization_level 3
void *func_0206fc18(StringStorage *self, u32 pos, u32 remove, u8 *first, u8 *last, Flag unused) {
u32 StringLength(void *);void *MemAllocArray(u32),*MemAlloc(u32);
void StringCopy(void *,void *);void func_0206f8c4(u32 *,u32,Flag);
void func_0207465c(void *,void *,void *);
s32 func_020700a0(s32),func_02070068(s32);
void MemCopy(void *,void *,u32),MemMove(void *,void *,u32);s32 MemFree(s32);
void func_0206ffc4(void *,s32,s32);void *func_0206fa14(void *);
extern u8 data_021008f0[],data_02100888[],data_02100860[],data_0210090c[],data_02100944[],data_02100874[],data_021008b8[],data_021007f4[];
u32 exception1[3],exception2[3];StringStorage temp;
u32 required,remaining,oldcap,oldsize,removed,newsize,capacity,inserted,tail,i;
u8 *data,*buffer,*middle,*end=last; s32 large;Flag zero1,zero2;
large=self->large.flag?1:0;
if(!large){oldcap=11;data=self->small.data;oldsize=self->small.length;}
else {oldcap=self->large.capacity;oldsize=self->large.length;data=self->large.data;}
if(pos>oldsize){
InitStringException(exception1,data_021008f0,data_02100860);
func_0207465c(data_0210090c,exception1,func_020700a0);
}
remaining=oldsize-pos;
removed=*(remaining<remove?&remaining:&remove);
inserted=end-first;
if(inserted>0x7ffffffeU || oldsize-removed>0x7ffffffeU-inserted){
InitStringException(exception2,data_02100944,data_02100874);
func_0207465c(data_021008b8,exception2,func_02070068);
}
newsize=inserted+(oldsize-removed);tail=oldsize-(pos+removed);
if(newsize>=oldcap){
required=newsize+1;capacity=(oldcap+15)&~15;
while(capacity<required)capacity=(capacity*2+15)&~15;
buffer=MemAlloc(capacity);
if(pos)MemCopy(buffer,data,pos);
middle=buffer+pos;MemMove(middle,first,end-first);
if(tail)MemCopy(middle+inserted,data+pos+removed,tail);
buffer[newsize]=data_021007f4[1];
if(large)MemFree(data);else self->large.flag=1;
self->large.data=buffer;self->large.length=newsize;self->large.capacity=capacity;
}else {
for(i=0;i<3;i++)((u32 *)&temp)[i]=0;
if(tail && data+pos+inserted<end && end<=data+oldsize){
func_0206ffc4(&temp,(s32)first,(s32)end);
if(!temp.large.flag)first=temp.small.data;else first=temp.large.data;
}
if(tail)MemMove(data+pos+inserted,data+pos+removed,tail);
MemMove(data+pos,first,inserted);
data[newsize]=data_021007f4[0];
if(large)self->large.length=newsize;else self->small.length=(u8)newsize;
func_0206fa14(&temp);
}
return self;
}
#pragma optimization_level reset
void func_0206ffc4(void *a, s32 b, s32 c) {
    void func_0207000c(void *, s32, u32, s32, s32, s32);
    u32 n;
    if (((u32)(M2C_FIELD(a,s32 *,0)<<31)>>31)==0) {
        n=(u32)(M2C_FIELD(a,u8 *,0)<<24)>>25;
    } else n=M2C_FIELD(a,u32 *,4);
    func_0207000c(a,0,n,b,c,0);
}

void func_0207000c(void *a, s32 b, u32 c, s32 d, s32 e, s32 f) {
    Flag unused;
    func_0206fc18(a,b,c,d,e,unused);
}

s32 func_02070030(s32 arg0) {
    M2C_UNK func_0206f994(s32);
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_02070048(s32 arg0) {
    M2C_UNK MemFree(s32);
    func_0206f994(arg0 + 4);
    MemFree(arg0);
    return arg0;
}

s32 func_02070068(s32 arg0) {
    M2C_UNK func_0206f994(s32);
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_02070080(s32 arg0) {
    func_0206f994(arg0 + 4);
    MemFree(arg0);
    return arg0;
}

s32 func_020700a0(s32 arg0) {
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_020700b8(s32 arg0) {
    func_0206f994(arg0 + 4);
    MemFree(arg0);
    return arg0;
}

#pragma optimization_level 4
void func_020700d8(void *a) {
void func_02070108(void *);
if (--M2C_FIELD(a,s32 *,4)!=0) return;
M2C_FIELD(*(void **)a,void (**)(void *),12)(a);
func_02070108(a);
}
void func_02070108(void *a) {
if (--M2C_FIELD(a,s32 *,8)!=0) return;
if (!a) return;
M2C_FIELD(*(void **)a,void (**)(void *),4)(a);
}

double func_02070134(double a, double b) {
    return a + b;
}

s32 func_0207044c(u32 r0, u32 r1) {
    u32 sign;
    u32 exp;
    u32 huge_mant;
    u32 lowshifted;
    u32 t;
    u32 sticky;
    u32 res;
    u32 r12;

    sign = r1 & 0x80000000u;
    exp = (r1 >> 20) & ~0x800u;
    if (exp == 0u) goto L8ac;
    if ((exp << 21) >= 0xffe00000u) goto L890;

    r12 = exp - 0x380u;
    if (exp <= 0x380u) goto L8bc;
    if ((s32)r12 >= 0xff) goto L92c;

    r1 = r1 << 12;
    {
        u32 r3 = sign | (r1 >> 9) | (r0 >> 29);
        lowshifted = r0 << 3;
        r0 = r3 | (r12 << 23);
        if (lowshifted == 0u) goto ret;
        if ((lowshifted & 0x80000000u) == 0u) goto ret;
        t = lowshifted << 1;
        if (t == 0) t = r0 & 1;
        if (t) r0++;
        goto ret;
    }

L890:
    huge_mant = r0 | (r1 << 12);
    if (huge_mant != 0u) goto L8a4;
    r0 = sign | 0x7f800000u;
    goto ret;
L8a4:
    r0 = 0x7fffffffu;
    goto ret;
L8ac:
    if ((r0 | (r1 << 12)) != 0) goto L924;
    r0 = sign;
    goto ret;
L8bc:
    {
        s32 s12 = (s32)exp - 0x380;
        if (s12 == -23) goto L910;
        if (s12 < -23) goto L924;
        {
            u32 m;
            u32 r3;
            u32 shift;
            u32 shift2;
            m = (r1 << 11) | 0x80000000u;
            r3 = (m >> 8) | (r0 >> 29);
            shift = (u32)(1 - s12);
            lowshifted = r0 << 3;
            res = sign | (r3 >> shift);
            shift2 = 32u - shift;
            sticky = (r3 << shift2) | ((lowshifted != 0u) ? 1u : 0u);
            if (sticky == 0u) { r0 = res; goto ret; }
            if ((sticky & 0x80000000u) == 0u) { r0 = res; goto ret; }
            t = sticky << 1;
            if (t != 0u) res += 1u;
            else if ((res & 1u) != 0u) res += 1u;
            r0 = res;
            goto ret;
        }
    }
L910:
    r0 = r0 | (r1 << 12);
    r1 = r0;
    r0 = sign;
    if (r1 != 0u) r0 += 1u;
    goto ret;
L924:
    r0 = sign;
    goto ret;
L92c:
    r0 = sign | 0x7f800000u;
    goto ret;
ret:
    return (s32)r0;
}

u64 func_02070550(u32 lo,u32 hi){s32 n;u32 m;
if(!(hi&0x80000000)){
n=0x43e - (hi>>20);
if(n<0)goto overflow;
if(n<64){
m=(hi<<11)|0x80000000; m|=lo>>21;
if(n>32){n-=32;return (u64)(m>>n);}
return ((u64)(m>>n)<<32)|((lo<<11)>>n)|(m<<(32-n));
}return 0ULL;
}
if((hi+0x100000U)>0 || (hi==0xfff00000U && lo))goto overflow;
return 0ULL;
overflow:return ~0ULL;
}

s32 func_020705dc(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 & 0x80000000 & 0x80000000) {
        var_r0 = 0 - var_r0;
    }
    if (var_r0 == 0) {
        return var_r0;
    }
    return (var_r0 << CLZ(var_r0)) << 0x15;
}

s32 func_0207061c(s32 arg0) {
    s32 temp_ip;
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        return var_r0;
    }
    if ((s32) (var_r0 - 0) >= 0) {
        temp_ip = CLZ(var_r0);
        var_r0 <<= temp_ip;
    }
    return var_r0 << 0x15;
}

s32 func_02070658(s32 a, s32 b, s32 c, s32 d) {
    return 0;
}

double func_020709bc(double x) {
    extern u32 gErrno;
    u32 r0, r1, r2, r3, r4, r5, r6, r12, lr;
    r0 = ((u32 *)&x)[0];
    r1 = ((u32 *)&x)[1];

    r2 = 0x7FF00000u;
    if (r1 >= r2) goto Lef0;

    r12 = r1 >> 20;
    if (r12 == 0) goto Le9c;

    r1 &= ~r2;
    r1 |= 0x00100000u;
    {
        u32 old = r12;
        r12 = (s32)old >> 1;
        if (old & 1) goto Ldd8;
    }

    r12 -= 1;
  Leven_norm:
    {
        u32 carry = r0 >> 31;
        r0 <<= 1;
        r1 = (r1 << 1) | carry;
    }
    {
        u32 carry = r0 >> 31;
        r3 = r0 << 1;
        r1 = (r1 << 1) | carry;
    }
    goto Lmain;

  Ldd8:
    {
        u32 carry = r0 >> 31;
        r0 <<= 1;
        r1 = (r1 << 1) | carry;
    }
    r3 = r0;
    goto Lmain;

  Lmain:
    r2 = 0;
    r4 = 0;
    lr = 0x00200000u;
  Lloop1:
    r6 = r4 + lr;
    if (r6 <= r1) {
        r4 = r6 + lr;
        r1 -= r6;
        r2 += lr;
    }
    {
        u32 carry = r3 >> 31;
        r3 <<= 1;
        r1 = (r1 << 1) | carry;
    }
    {
        u32 carry = lr & 1;
        (void)carry;
        lr >>= 1;
    }
    if (lr != 0) goto Lloop1;

    r0 = 0;
    r5 = 0;
    if (r1 < r4 || (r1 == r4 && r3 < 0x80000000u)) goto Le34;
    {
        u32 oldr3 = r3;
        r3 -= 0x80000000u;
        r1 = r1 - r4 - (oldr3 < 0x80000000u ? 1 : 0);
    }
    r4 += 1;
    r0 = 0x80000000u;
    {
        u32 carry = r3 >> 31;
        r3 <<= 1;
        r1 = (r1 << 1) | carry;
    }
    lr = 0x40000000u;
  Lloop2:
    r6 = r5 + lr;
    if (!(r4 > r1 || (r4 == r1 && r6 > r3))) {
        r5 = r6 + lr;
        {
            u32 oldr3 = r3;
            r3 -= r6;
            r1 = r1 - r4 - (oldr3 < r6 ? 1 : 0);
        }
        r0 += lr;
    }
    {
        u32 carry = r3 >> 31;
        r3 <<= 1;
        r1 = (r1 << 1) | carry;
    }
    {
        u32 carry = lr & 1;
        (void)carry;
        lr >>= 1;
    }
    if (lr != 0) goto Lloop2;

    if ((r1 | r3) == 0) r0 &= ~1u;
    {
        u32 carry_in = r2 & 1;   /* adc merged with rrx below */
        r1 = r2 >> 1;
        r0 = (r0 >> 1) | (carry_in << 31);
        r0 += (r0 & 1) ? 0 : 0; /* placeholder */
    }

    r1 += 0x20000000u;
    r1 -= 0x00100000u;
    r1 += (r12 << 20);

    ((u32 *)&x)[0] = r0;
    ((u32 *)&x)[1] = r1;
    return x;

  Le34:
    if ((r1 | r3) == 0) r0 &= ~1u;
    {
        u32 carry_in = r2 & 1;
        r1 = r2 >> 1;
        r0 = (r0 >> 1) | (carry_in << 31);
    }
    r1 += 0x20000000u;
    r1 -= 0x00100000u;
    r1 += (r12 << 20);
    ((u32 *)&x)[0] = r0;
    ((u32 *)&x)[1] = r1;
    return x;

  Le9c:
    if (r1 != 0) goto Lecc;
    if (r0 == 0) return x;
    r12 = ~0x00000013u;
    r5 = CLZ(r0);
    r0 <<= r5;
    r12 -= r5;
    r1 = r0 >> 11;
    r0 <<= 21;
    goto Leven_norm;

  Lecc:
    r5 = CLZ(r1);
    r1 <<= r5;
    r2 = 0x2B - r5;
    r1 >>= 11;
    r1 |= r0 >> (0x2B - r5);
    r6 = 0x20 - (0x2B - r5);
    r0 <<= r6;
    r12 = 1 - r6;
    goto Leven_norm;

  Lef0:
    if (r1 & 0x80000000u) {
        r3 = r1 & ~0x80000000u;
        if (r3 == 0 && r0 == 0) return x;
        goto Lf18;
    } else {
        r2 = (r0 | (r1 << 12));
        if (r2 == 0) return x;
        goto Lf18;
    }
  Lf18:
    r1 |= 0x7FF80000u;
    gErrno = 0x21u;
    ((u32 *)&x)[0] = r0;
    ((u32 *)&x)[1] = r1;
    return x;
}

