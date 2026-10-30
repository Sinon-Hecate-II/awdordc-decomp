/* 39 functions from 0x02037214 to 0x0203804C (main), found by ds-decomp. */
#include "common.h"
static inline void seed371(u64 *seed) {
extern u64 data_0213d1e0[];
data_0213d1e0[0]=*seed;
data_0213d1e0[1]=0x5d588b656c078965ULL;
data_0213d1e0[2]=0x269ec3;
}
static inline u32 next371(void) {
extern u64 data_0213d1e0[];
data_0213d1e0[0]=data_0213d1e0[1]*data_0213d1e0[0]+data_0213d1e0[2];
return data_0213d1e0[0]>>32;
}

/* Returns the current state code, exposing its param through outParam and a derived type through outType. */
s32 func_02037214(void *arg0, u32 arg1, s8 *arg2, s32 arg3) {
    extern s8 *data_020fba88;
    void func_02007f8c(void *, s32, s32);
    void func_02008048(void *, void *, u32);
    s8 *table;
    s32 total;
    void *src;
    void *srcEnd;
    s8 *dst;
    s32 r6;
    s32 r9;
    u8 buf[3];

    if (arg1 % 3u != 0u) {
        total = (s32)(arg1 / 3u) * 4 + 4;
    } else {
        total = (s32)(arg1 / 3u) * 4;
    }
    if (arg2 == (s8 *)0) {
        return total;
    }
    if (arg3 < total) {
        return -1;
    }
    src = arg0;
    srcEnd = (void *)((char *)arg0 + arg1);
    dst = arg2;
    table = data_020fba88;
    if (src != srcEnd) {
        do {
            s32 remaining = (s32)((char *)srcEnd - (char *)src);
            r9 = remaining;
            if (r9 >= 3) {
                r9 = 3;
            }
            r6 = (r9 * 8 + 5) / 6;
            func_02007f8c(buf, 0, 3);
            func_02008048(src, buf, (u32)r9);
            dst[0] = (s8)table[buf[0] >> 2];
            if (r6 < 2) {
                dst[1] = (s8)0x2a;
            } else {
                dst[1] = (s8)table[((buf[0] << 4) & 0x3c) | (buf[1] >> 4)];
            }
            if (r6 < 3) {
                dst[2] = (s8)0x2a;
            } else {
                dst[2] = (s8)table[((buf[1] << 2) & 0x3c) | (buf[2] >> 6)];
            }
            if (r6 < 4) {
                dst[3] = (s8)0x2a;
            } else {
                dst[3] = (s8)table[buf[2] & 0x3f];
            }
            src = (void *)((char *)src + r9);
            dst = (s8 *)((char *)dst + 4);
        } while (src != srcEnd);
    }
    total = (s32)((char *)dst - (char *)arg2);
    return total;
}

s32 func_0203739c(char *src, u32 len, char *dest, u32 maxDest) {
    u32 i;
    s32 required;
    u32 j;
    char vals[4];
    char *out;
    u32 written;

    if (len & 3u) {
        return -1;
    }
    required = 0;
    for (i = 0u; i < len; i++) {
        if ((s8)src[i] != (s8)0x2a) {
            required = required + 6;
        }
    }
    required = required / 8;
    if (dest == (char *)0) {
        return required;
    }
    if (maxDest < (u32)required) {
        return -1;
    }
    if (len == 0u) {
        dest[0] = 0;
        return 0;
    }
    out = dest;
    written = 0u;
    while (written < (u32)required) {
        for (j = 0u; j < 4u; j++) {
            s8 c;
            s8 v;
            c = (s8)src[j];
            if (c >= (s8)0x41 && c <= (s8)0x5a) {
                v = (s8)(c - (s8)0x41);
            } else if (c >= (s8)0x61 && c <= (s8)0x7a) {
                v = (s8)(c - (s8)0x47);
            } else if (c >= (s8)0x30 && c <= (s8)0x39) {
                v = (s8)(c + (s8)0x4);
            } else if (c == (s8)0x2e) {
                v = (s8)0x3e;
            } else if (c == (s8)0x2d) {
                v = (s8)0x3f;
            } else {
                v = (s8)0;
            }
            vals[j] = (char)v;
        }
        src = src + 4;
        out[0] = (char)(((s8)vals[0] << 2) | ((s8)vals[1] >> 4));
        written = (u32)(out + 1 - dest);
        if (written >= (u32)required) {
            break;
        }
        out[1] = (char)(((s8)vals[1] << 4) | ((s8)vals[2] >> 2));
        written = (u32)(out + 2 - dest);
        if (written >= (u32)required) {
            break;
        }
        out[2] = (char)(((s8)vals[2] << 6) | ((s8)vals[3]));
        out = out + 3;
        written = (u32)(out - dest);
    }
    return (s32)written;
}

s32 func_02037508(s32 *outParam, s32 *outType) {
    extern M2C_UNK data_0213d1cc;
    if (outParam != (s32 *)0) {
        *outParam = M2C_FIELD(&data_0213d1cc, s32 *, 4);
    }
    if (outType != (s32 *)0) {
        switch (M2C_FIELD(&data_0213d1cc, s32 *, 0)) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            *outType = 6;
            break;
        case 6:
            *outType = 3;
            break;
        case 7:
            *outType = 4;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            *outType = 1;
            break;
        case 1:
        case 9:
            *outType = 7;
            break;
        case 14:
            *outType = 5;
            break;
        case 15:
        case 17:
        case 19:
            *outType = 6;
            break;
        case 16:
        case 18:
            *outType = 2;
            break;
        default:
            *outType = 0;
            break;
        }
    }
    return M2C_FIELD(&data_0213d1cc, s32 *, 0);
}

void func_020375fc(void) {
    extern M2C_UNK data_0213d1cc;
    if (M2C_FIELD(&data_0213d1cc, s32 *, 0) != 9) {
        M2C_FIELD(&data_0213d1cc, s32 *, 0) = 0;
        M2C_FIELD(&data_0213d1cc, s32 *, 4) = 0;
    }
}

s32 func_0203761c(void) {
    extern s32 data_0213d1cc;
    if (data_0213d1cc != 0) {
        return 1;
    }
    return 0;
}

void func_02037638(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d1cc;
    if (M2C_FIELD(&data_0213d1cc, s32 *, 0) != 9) {
        M2C_FIELD(&data_0213d1cc, s32 *, 0) = arg0;
        M2C_FIELD(&data_0213d1cc, s32 *, 4) = arg1;
    }
}

s32 func_02037650(s32 arg0) {
    return arg0 - 0x20;
}

void *func_02037658(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0x4457434D;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return arg0 + 0x20;
}

s32 func_02037670(s32 arg0) {
    s32 *p;
    s32 dummy;
    p = (s32 *)func_02037650(arg0);
    (void)dummy;
    return p[1];
}

void func_02037680(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d1d4;
    M2C_FIELD(&data_0213d1d4, s32 *, 4) = arg0;
    M2C_FIELD(&data_0213d1d4, s32 *, 0) = arg1;
}

void func_02037694(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020376a4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020376a4(arg0, arg1, 0x20);
}

M2C_UNK func_020376a4(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_0213d1d4;
    void *temp_r0;
    temp_r0 = M2C_FIELD(&data_0213d1d4, void *(**)(M2C_UNK, s32, M2C_UNK), 4)(arg0, arg1 + 0x20, arg2);
    if (temp_r0 == NULL) {
        return 0;
    }
    return (s32)func_02037658(temp_r0, arg1);
}

void func_020376d8(M2C_UNK a, M2C_UNK b, M2C_UNK c) {
    extern M2C_UNK data_0213d1d4;
    if (b == 0) {
        return;
    }
    M2C_FIELD(&data_0213d1d4, void (**)(s32, s32, s32), 0)(
        a, func_02037650(b), c);
}

M2C_UNK func_02037714(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02037728(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 dummy = 0;
    (void)dummy;
    return func_02037728(arg0, arg1, arg2, arg3, 0x20);
}

M2C_UNK func_02037728(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK size,s32 align){
 void func_02008048(void *,void *,u32);
 M2C_UNK sz=size;
 M2C_UNK p;
 u32 n;
 p=func_020376a4(a,sz,align);if(!p)return 0;
 if(b){n=func_02037670(b);if(n<=(u32)sz)sz=n;func_02008048(b,p,sz);func_020376d8(a,b,n);}
 return p;
}

void func_02037794(M2C_UNK arg0) {
    func_02037694(5, arg0);
}

void func_020377a8(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02037714(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02037714(5, arg0, arg1, arg1);
}

void func_020377c4(M2C_UNK arg0) {
    void func_020376d8(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020376d8(5, arg0, 0);
}

M2C_UNK func_020377dc(M2C_UNK a,M2C_UNK b,M2C_UNK unused,M2C_UNK d){
 extern void *data_0213d1dc;
 void func_02037854(s32);
 void func_02007f8c(void *,s32,s32);void func_020220a8(s32);
 if(data_0213d1dc)return;
 func_02007f8c(a,0,12);
 M2C_FIELD(a,u16 *,8)=b;M2C_FIELD(a,u16 *,10)=1;M2C_FIELD(a,u16 *,4)=1;M2C_FIELD(a,u16 *,6)=0;
 data_0213d1dc=(void *)a;func_02037854(0);func_020220a8(d);
}

void func_0203783c(M2C_UNK arg0) {
    M2C_UNK func_020377dc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020377dc(arg0, 3, 1, 0x14);
}

void func_02037854(s32 arg0) {
    M2C_UNK func_0203289c(M2C_UNK *);
    extern M2C_UNK data_020fc818;
    extern M2C_UNK data_020fc840;
    extern M2C_UNK data_020fc864;
    switch (arg0) {                                 /* irregular */
    case 0:
        func_0203289c(&data_020fc818);
        return;
    case 1:
        func_0203289c(&data_020fc840);
        return;
    case 2:
        func_0203289c(&data_020fc864);
        return;
    }
}

void func_020378a4(void) {
    extern void *data_0213d1dc;
    void func_02007f8c(void *, s32, s32);
    s32 func_0202ef64(void *);
    void func_02037638(s32, s32);
    s32 args[3];
    if (data_0213d1dc) {
        if (M2C_FIELD(data_0213d1dc, u16 *, 4) != 1) return;
        func_02007f8c((s32)args, 0, 12);
        M2C_FIELD(args, u8 *, 8) = M2C_FIELD(data_0213d1dc, u16 *, 8);
        M2C_FIELD(args, u8 *, 9) = M2C_FIELD(data_0213d1dc, u16 *, 10);
        args[0] = (s32)func_02037694;
        args[1] = (s32)func_020376d8;
        M2C_FIELD(data_0213d1dc, u16 *, 4) = 2;
        if (!func_0202ef64(args)) {
            func_02037638(9, -6);
        }
    } else {
        func_02037638(9, -4);
    }
}

s32 func_02037954(void) {
    extern void *data_0213d1dc;
    s32 func_02037a0c(void);
    s32 dummy = 0;
    (void)dummy;
    if (!data_0213d1dc) {
        return 0;
    }
    if (!M2C_FIELD(data_0213d1dc, s32 *, 0)) {
        return 0;
    }
    M2C_FIELD(data_0213d1dc, u16 *, 4) = 3;
    func_02037a0c();
    return 1;
}

void func_02037994(void) {
    extern void *data_0213d1dc;
    s32 func_0202f10c(void);
    s32 func_02027c84(void);
    s32 dummy = 0;
    (void)dummy;
    if (!data_0213d1dc) return;
    if (M2C_FIELD(data_0213d1dc, u16 *, 4) == 2) {
        M2C_FIELD(data_0213d1dc, s32 *, 0) = func_0202f10c();
        return;
    }
    if (M2C_FIELD(data_0213d1dc, u16 *, 4) == 4 && M2C_FIELD(data_0213d1dc, u16 *, 6) != 0) {
        if (func_02027c84() != 9) {
            M2C_FIELD(data_0213d1dc, u16 *, 6) = 0;
            M2C_FIELD(data_0213d1dc, u16 *, 4) = 6;
        }
    }
}

s32 func_02037a0c(void) {
    extern void *data_0213d1dc;
    s32 func_0202f1dc(void);
    void func_02037638(s32, s32);
    s32 n;
    s32 dummy = 0;
    (void)dummy;
    if (!data_0213d1dc) return 0;
    n = M2C_FIELD(data_0213d1dc, u16 *, 4);
    if (n == 1) return n;
    n = func_0202f1dc();
    if (n == 5) {
        M2C_FIELD(data_0213d1dc, u16 *, 4) = 4;
        M2C_FIELD(data_0213d1dc, u16 *, 6) = 1;
        return 4;
    }
    if (n < 0) {
        if (n >= -10) {
            func_02037638(9, n - 700);
            M2C_FIELD(data_0213d1dc, u16 *, 4) = 8;
            return 8;
        }
        func_02037638(5, n);
        M2C_FIELD(data_0213d1dc, u16 *, 4) = 7;
        return 7;
    }
    return 2;
}

void func_02037abc(void) {
extern void *data_0213d1dc;s32 func_0202f28c(void);void func_02006030(s32);
if(!data_0213d1dc)return;
if(M2C_FIELD(data_0213d1dc,u16 *,4)==1){data_0213d1dc=0;return;}
while(!func_0202f28c())func_02006030(10);
data_0213d1dc=0;
}

s32 func_02037b1c(void) {
    extern void *data_0213d1dc;
    s32 func_0202f28c(void);
    s32 dummy = 0;
    (void)dummy;
    if (!data_0213d1dc) return 1;
    if (M2C_FIELD(data_0213d1dc, u16 *, 4) == 8) return 0;
    if (M2C_FIELD(data_0213d1dc, u16 *, 4) == 1) {
        data_0213d1dc = 0;
        return 1;
    }
    M2C_FIELD(data_0213d1dc, u16 *, 4) = 5;
    if (!func_0202f28c()) return 0;
    data_0213d1dc = 0;
    return 1;
}

s32 func_02037b8c(void) {
    extern void *data_0213d1dc;
    if ((data_0213d1dc != NULL) && (M2C_FIELD(data_0213d1dc, u16 *, 4) == 6)) {
        return 1;
    }
    return 0;
}

void func_02037bb8(void) {
    M2C_UNK func_02029ad8();
    func_02029ad8();
}

s32 func_02037bc4(void) {
    u32 func_0202f248(void);
    void func_02037994(void);
    void func_02037abc(void);
    void func_02037638(s32, s32);
    s32 func_02037b8c(void);
    u32 var_r2;
    s32 dummy;
    (void)dummy;

    func_02037994();
    if (func_02037b8c() != 0) {
        var_r2 = func_0202f248();
        if (var_r2 > 0x63U) {
            var_r2 = 0x63;
        }
        func_02037638(8, 0xFFFF2D10 - var_r2);
        func_02037abc();
        return 1;
    }
    return 0;
}

void func_02037c10(void) {
    M2C_UNK func_020362d4();
    func_020362d4();
}

s32 func_02037c1c(void) {
    u32 func_020364f4(void);
    u32 func_0202f248(void);
    void func_02037638(s32, s32);
    u32 n;
    s32 dummy;
    (void)dummy;

    switch (func_020364f4()) {
    case 0: return 1;
    case 1: return 2;
    case 2:
    case 3:
        n = func_0202f248();
        if (n > 99) {
            n = 99;
        }
        func_02037638(8, 0xffff2cac - n);
        return 3;
    case 4: return 0;
    default: return 3;
    }
}

s32 func_02037c90(void) {
    extern s32 data_0213d114;
    return data_0213d114;
}

s32 func_02037ca0(s32 a,s32 b){
extern s32 data_0213d1b4;extern s64 data_0213d1b8,data_0213d1c0;
s32 func_0200f0ac(s32,s32);s64 func_0200f7e0(s32,s32);void func_0200f9c4(s32,s32);
s64 t,d;
if(!data_0213d1b4)return 0;
if(func_0200f0ac(a,b))return 0;
t=func_0200f7e0(a,b);if(t==-1)return 0;
if(t<data_0213d1b8)t+=0xbc191380LL;
d=t-data_0213d1c0;
if(d<0 || d>0xbc19137fLL)return 0;
func_0200f9c4(a,b);return 1;
}

M2C_UNK func_02037d78(s32 a,s32 b,s32 c,s32 d){
 M2C_UNK func_0200567c(s32,s32,void *,...);M2C_UNK func_02068c34(s32);extern M2C_UNK data_020fc884;
 func_0200567c(c,0x1000,&data_020fc884,d,a,d,b);func_02068c34(c);
}

void func_02037db0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02037d78(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02068c34(M2C_UNK);
    s32 func_02068ee0(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 dummy = 0;
    (void)dummy;
    temp_r0 = func_02068ee0(arg2, 0);
    func_02037d78(arg0, arg1, temp_r0, arg3);
    func_02068c34(arg2);
}

s32 func_02037df0(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg3) {

s8 *p; s8 *q; s32 len;
if (!arg1) return -1;
p=func_02068ee0(arg2,arg3); if(!p)return -1;
for (;;) {
len=func_02068c34(arg0);
if(func_02068eac((u8*)(p+1),(u8*)arg0,len)!=0)goto next;
len=func_02068c34(arg0); if(arg3==*(s8 *)(len+(s32)p+1))goto extract;
next:
q=func_02068ee0(p+1,arg3);if(!q)return -1;
p=func_02068ee0(q+1,arg3);if(!p)return -1;
}
extract:
p=func_02068ee0(p+1,arg3);if(!p)return -1;
q=func_02068ee0(p+1,arg3);
if(q)len=q-(p+1);else len=func_02068c34(p+1);
func_02068d18(arg1,p+1,len);arg1[len]=0;return len;
}

u32 func_02037eec(u32 max) {
extern u64 data_0213d1e0[];
void func_02007724(void *); u64 func_02007004(void);
u64 seed,v;
if(data_0213d1e0[0]==0&&data_0213d1e0[1]==0&&data_0213d1e0[2]==0){
func_02007724(&seed);
seed=((seed>>24)&0xffffffULL)|(func_02007004()<<24);
data_0213d1e0[0]=seed;
data_0213d1e0[1]=0x5d588b656c078965ULL;
data_0213d1e0[2]=0x269ec3;
}
data_0213d1e0[0]=data_0213d1e0[1]*data_0213d1e0[0]+data_0213d1e0[2];
v=data_0213d1e0[0]>>32;
if(max==0)return v;
return (v*max)>>32;
}

s32 func_02038020(u16 *a){s32 i=0;if(*a){do{i++;}while(a[i]);}return i;}

