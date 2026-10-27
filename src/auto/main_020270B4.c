/* 16 functions from 0x020270B4 to 0x02028038 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_02138e4c;
s32 func_0200751c(void);
void func_02007530(s32);
void func_02028160(s32);

s32 func_020271cc(void){s32 s=func_0200751c(); void *p=(void *)data_02138e4c; if(!p){func_02007530(s);return 1;} if(M2C_FIELD(p,s32 *,0x2260)!=1){func_02007530(s);return 1;} data_02138e4c=0;func_02007530(s);return 0;}

void func_02028384(void);
s32 func_02027428(void) {
    s32 s = func_0200751c();
    void *p = (void *)data_02138e4c;
    s32 v;
    s32 r;

    if (p == 0) {
        func_02007530(s);
        return 1;
    }
    v = M2C_FIELD(p, s32 *, 0x2260);
    switch (v) {
    case 1:
        func_02007530(s);
        return 1;
    case 3:
        r = func_020121d8((M2C_UNK)func_02028384);
        switch (r) {
        case 2:
            func_02028160(4);
            M2C_FIELD((void *)data_02138e4c, u16 *, 0x2280) = 2;
            func_02007530(s);
            return 3;
        case 8:
            func_02007530(s);
            return 4;
        case 3:
        default:
            func_02028160(0xB);
            func_02007530(s);
            return 7;
        }
    case 4:
        func_02007530(s);
        return 2;
    default:
        func_02007530(s);
        return 0;
    }
}

void func_02027518(s32 a,s32 b){s32 func_020276b0(void); void func_02027538(void); if(a==0 || b==0)func_020276b0();else func_02027538();}

s32 func_02027c84(void){s32 s=func_0200751c();s32 r=0;void *p=(void *)data_02138e4c;if(p)r=M2C_FIELD(p,s32 *,0x2260);func_02007530(s);return r;}

u32 func_02027cb4(u32 arg){u32 old;u32 a=arg;s32 s=func_0200751c();u32 mask=0;void *p=(void *)data_02138e4c;old=M2C_FIELD(p+0x2000,u32 *,0x264);if(!p){func_02007530(s);return 0;}if(a&0x8000){mask|=0x3ffe;if(!(a&0x3ffe))a|=0xa082;}if(a&0x20000)mask|=0x10000;if(a&0x80000)mask|=0x40000;if(a&0x200000)mask|=0x100000;if(a&0x800000)mask|=0x400000;M2C_FIELD(p+0x2000,u32 *,0x264)=a|(old&~mask);func_02007530(s);arg=old;return arg;}

s32 func_02027d50(void) {
    extern s32 data_02138e4c;
    return data_02138e4c;
}

void func_02028018(void){M2C_FIELD((void *)data_02138e4c,u32 *,0x2264)=0xaaa082;}

