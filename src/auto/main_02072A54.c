/* 15 functions from 0x02072A54 to 0x020739F8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 type:5; } RuntimeType;

s32 func_02072a54(void) { return 7; }

s32 func_02072a68(void) { return 0x18; }

s32 func_02072a78(s32 unused,u8 *p,u32 *count) {
s32 func_02072a54(void);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) {
s32 c=func_02072a54();
p[i]=(short)c;
if((u8)c==13 || (u8)c==10) { *count=i+1; break; }
}
return 0;
}

s32 func_02072ac8(s32 unused,u8 *p,u32 *count) {
void func_02072a40(u8 *);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) func_02072a40(p+i);
return 0;
}

s32 func_02072afc(void) {
    return 0;
}

s32 func_02072b04(void *buf) {
    /* save context */
    /* can't express stmia of registers in C directly */
    return 0;
}

void *func_02072b20(void *arg0, s32 *arg1) {
    s8 temp_r2;
    u8 temp_lr;
    u8 temp_r4;

    temp_r2 = M2C_FIELD(arg0, s8 *, 0);
    if (!(temp_r2 & 1)) {
        *arg1 = temp_r2 >> 1;
        return arg0 + 1;
    }
    temp_r4 = M2C_FIELD(arg0, u8 *, 1);
    if (!(temp_r2 & 2)) {
        *arg1 = temp_r4 | ((temp_r2 >> 2) << 8);
        return arg0 + 2;
    }
    temp_lr = M2C_FIELD(arg0, u8 *, 2);
    if (!(temp_r2 & 4)) {
        *arg1 = temp_lr | ((temp_r4 << 8) | ((temp_r2 >> 3) << 0x10));
        return arg0 + 3;
    }
    *arg1 = M2C_FIELD(arg0, u8 *, 3) | ((temp_r4 << 0x10) | ((temp_r2 >> 3) << 0x18) | (temp_lr << 8));
    return arg0 + 4;
}

void *func_02072bac(u8 *p,u32 *out) {
u32 a;
u32 b,c;
a=*(u8 *)p;
if(!(a&1)) { *out=a>>1; return p+1; }
b=p[1];
if(!(a&2)) { *out=b|((a>>2)<<8); return p+2; }
c=p[2];
if(!(a&4)) { *out=c|((b<<8)|((a>>3)<<16)); return p+3; }
*out=p[3]|((b<<16)|((a>>3)<<24)|(c<<8)); return p+4;
}

void *func_02072c38(u32 *p,s32 n,u32 addr) {
s32 mid;
u32 *q;
s32 lo=0;
s32 hi=n-1;
while(lo<=hi) {
mid=(lo+hi)>>1;
q=(u32 *)((u8 *)p+mid*12);
if(addr<q[0]) hi=mid-1;
else if(addr>q[0]+(q[1]&~1U)) lo=mid+1;
else return q;
}
return 0;
}

u8 func_02072da4(void *arg0) {
u8 *p=M2C_FIELD(arg0,u8 **,8);
s32 result;
if(p) result=*p&31;
else result=0;
return (u8)result;
}

