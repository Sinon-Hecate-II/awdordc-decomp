/* 18 functions from 0x0206FC18 to 0x02070B70 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 value; } Flag;

void func_0206fc18(void *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, Flag arg5) { }

void func_0206ffc4(void *a, s32 b, s32 c) {
    void func_0207000c(void *, s32, u32, s32, s32, s32);
    u32 n;
    if (((u32)(M2C_FIELD(a,s32 *,0)<<31)>>31)==0) {
        n=(u32)(M2C_FIELD(a,u8 *,0)<<24)>>25;
    } else n=M2C_FIELD(a,u32 *,4);
    func_0207000c(a,0,n,b,c,0);
}

void func_0207000c(void *a, s32 b, u32 c, s32 d, s32 e, s32 f) {
    void func_0206fc18(void *, s32, u32, s32, s32, Flag);
    Flag unused;
    func_0206fc18(a,b,c,d,e,unused);
}

s32 func_02070030(s32 arg0) {
    M2C_UNK func_0206f994(s32);
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_02070048(s32 arg0) {
    M2C_UNK func_02082040(s32);
    func_0206f994(arg0 + 4);
    func_02082040(arg0);
    return arg0;
}

s32 func_02070068(s32 arg0) {
    M2C_UNK func_0206f994(s32);
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_02070080(s32 arg0) {
    func_0206f994(arg0 + 4);
    func_02082040(arg0);
    return arg0;
}

s32 func_020700a0(s32 arg0) {
    func_0206f994(arg0 + 4);
    return arg0;
}

s32 func_020700b8(s32 arg0) {
    func_0206f994(arg0 + 4);
    func_02082040(arg0);
    return arg0;
}

#pragma optimization_level 2
void func_020700d8(void *a) {
    void func_02070108(void *);
    void *p = a;
    if (--M2C_FIELD(p, s32 *, 4) != 0) {
        return;
    }
    M2C_FIELD(*(void **)a, void (**)(void *), 12)(a);
    func_02070108(a);
}
#pragma optimization_level reset
void func_02070108(void *a) {
if (--M2C_FIELD(a,s32 *,8)!=0) return;
if (!a) return;
M2C_FIELD(*(void **)a,void (**)(void *),4)(a);
}

void func_02070134(void) {
    return;
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
    exp = (r1 >> 20) & 0x7ffu;
    if (exp == 0u) goto L8ac;
    if (exp >= 2032u) goto L890;

    if (exp < 0x380u) goto L8bc;

    r12 = exp - 0x380u;
    if (r12 >= 0xffu) goto L92c;

    r1 = r1 << 12;
    {
        u32 r3 = sign | (r1 >> 9) | (r0 >> 29);
        lowshifted = r0 << 3;
        r0 = r3 | (r12 << 23);
        if (lowshifted == 0u) goto ret;
        if ((lowshifted & 0x80000000u) == 0u) goto ret;
        t = lowshifted << 1;
        if (t != 0u) r0 += 1u;
        else if ((r0 & 1u) != 0u) r0 += 1u;
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
    extern u32 data_0213e9f4;
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
    data_0213e9f4 = 0x21u;
    ((u32 *)&x)[0] = r0;
    ((u32 *)&x)[1] = r1;
    return x;
}

