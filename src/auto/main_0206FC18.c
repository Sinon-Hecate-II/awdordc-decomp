/* 18 functions from 0x0206FC18 to 0x02070B70 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 value; } Flag;

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

void func_020700d8(void *a) {
    void func_02070108(void *);
    s32 n = M2C_FIELD(a,s32 *,4)-1;
    M2C_FIELD(a,s32 *,4)=n;
    if(n) return;
    M2C_FIELD(*(void **)a,void (**)(void *),12)(a);
    func_02070108(a);
}

void func_02070108(void *a) {
if (--M2C_FIELD(a,s32 *,8)!=0) return;
if (!a) return;
M2C_FIELD(*(void **)a,void (**)(void *),4)(a);
}

s32 func_0207044c(u32 arg0, u32 arg1) {
    double d;
    float f;
    ((u32 *)&d)[0] = arg0;
    ((u32 *)&d)[1] = arg1;
    f = (float)d;
    return *(s32 *)&f;
}

u64 func_02070550(u32 lo, u32 hi) {
    s32 n;
    u32 m, l, h;
    if (!(hi&0x80000000)) {
        n=0x43e - (hi>>20);
        if(n<0) goto overflow;
        if(n>=64) return 0;
        m=(hi<<11)|0x80000000|(lo>>21);
        if(n>32) { h=0; l=m>>(n-32); }
        else { h=m>>n; l=((lo<<11)>>n)|(m<<(32-n)); }
        return ((u64)h<<32)+l;
    }
    if(hi>0xfff00000) goto overflow;
    if(hi==0xfff00000 && lo) goto overflow;
    return 0;
overflow:
    return ~0ULL;
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

