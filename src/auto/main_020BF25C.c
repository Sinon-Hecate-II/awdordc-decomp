/* 35 functions from 0x020BF25C to 0x020C0254 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a, b; } SavePair;
typedef struct { u8 enabled:1; u8 mode:3; u8 unused:4; } SaveFlags;
typedef struct { u16 low:7; u16 mode:3; u16 high:6; } SaveMode;
extern M2C_UNK data_0215d890, data_0215deec, data_0212616c;

void func_020bf798(void){
void func_020be718(void *);void func_020be438(s32,void *,s32);
u16 size=0x5cc;
func_020be718(&data_0215deec);
func_020be438(4,&data_0215deec,size);
}

M2C_UNK func_020bf7c4(void){
void func_020bfa08(void);void func_020bfa48(void);
s32 func_020be324(s32,void *);void func_020beabc(void *);void func_020be5d0(void);
if(!func_020be324(4,&data_0215deec))return;
func_020beabc(&data_0215deec);
if(M2C_FIELD(&data_0215d890,u32 *,0x128)!=0x20070810)func_020be5d0();
func_020bfa08();func_020bfa48();
}

void func_020bf814(s32 a){
void func_020bf8ac(s32,s32);
s32 i;u8 *p=(u8 *)&data_0212616c;
i=0;do{if(a==M2C_FIELD(p,u16 *,0x24))func_020bf8ac(i,1);i++;p+=0x9c;}while(i<15);
}

void func_020bf858(void) {

}

void func_020bf85c(void) {
    extern void **data_027e0058;
    u16 temp_r2;
    void *temp_r3;

    temp_r3 = *data_027e0058;
    temp_r2 = M2C_FIELD(temp_r3, u16 *, 0x52A2);
    if ((s32) temp_r2 < 0x3E7) {
        M2C_FIELD(temp_r3, u16 *, 0x52A2) = (u16) (temp_r2 + 1);
    }
}

u32 func_020bf894(s32 a) {
extern M2C_UNK data_0215da1c;
return (u32)(M2C_FIELD(&data_0215da1c,u8 *,a)<<31)>>31;
}

void func_020bf8ac(s32 a,s32 b) {
extern M2C_UNK data_0215da1c;
M2C_FIELD(&data_0215da1c,u8 *,a)=(M2C_FIELD(&data_0215da1c,u8 *,a)&~1)|(b&1);
}

u32 func_020bf8cc(s32 a) {
extern M2C_UNK data_0215da1c;
if(a==0||a>=15)return 0;
return (u32)(M2C_FIELD(&data_0215da1c,u8 *,a)<<28)>>29;
}

void func_020bf8fc(s32 a,s32 b) {
extern M2C_UNK data_0215da1c;
if(a==0)return;if(a>=15)return;
((SaveFlags *)&data_0215da1c)[a].mode=(u8)b;
}

void func_020bf930(M2C_UNK arg0) {
    M2C_UNK func_0207cfb0(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0215d990;
    u32 temp_r1;

    temp_r1 = (u32) (M2C_FIELD(&data_0215d990, u16 *, 0x2E) << 0x16) >> 0x1D;
    switch (temp_r1) {                              /* irregular */
    case 0:
        func_0207cfb0(arg0, 0);
        return;
    case 1:
        func_0207cfb0(arg0, 0x80);
        return;
    default:
        func_0207cfb0(arg0, 0x80);
        return;
    }
}

void func_020bf97c(void) {
s32 func_0207cfb8(void);extern M2C_UNK data_0215d990;
switch(func_0207cfb8()){
case 0:((SaveMode *)((u8 *)&data_0215d990+0x2e))->mode=0;return;
case 128:M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|128;return;
default:M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|128;return;
}
}

u8 func_020bf9e0(void) {
    extern M2C_UNK data_0215d890;
    return M2C_FIELD(&data_0215d890, u8 *, 0x12C);
}

void func_020bf9f0(s32 a) {
extern M2C_UNK data_0215d890;void func_020bfa08(void);
M2C_FIELD(&data_0215d890,u8 *,0x12c)=a;
func_020bfa08();
}

void func_020bfa08(void) {
    M2C_UNK func_02090640(M2C_UNK, s32);
    func_02090640(1, func_020bf9e0());
}

s32 func_020bfa20(void){return M2C_FIELD(&data_0215d890,u8 *,0x12d);}

void func_020bfa30(s32 a) {
void func_020bfa48(void);
M2C_FIELD(&data_0215d890,u8 *,0x12d)=a;
func_020bfa48();
}

void func_020bfa48(void) {
    M2C_UNK func_0209066c(M2C_UNK, s32);
    s32 func_020bfa20();
    func_0209066c(1, func_020bfa20());
}

void *func_020bfa60(s32 a) {
extern M2C_UNK data_0215d9ec;
return (u8 *)&data_0215d9ec+((a-5)<<3);
}

M2C_UNK *func_020bfa74(void) {
    extern M2C_UNK data_0215da0c;
    return &data_0215da0c;
}

void func_020bfa80(u16 *arg0) {
    extern M2C_UNK data_0211faf4;
    u16 *p;
    u32 t;
    s32 i;
    u8 *dp;
    u16 old_i;

    p = arg0;
    if (p == 0) {
        p = (u16 *) func_020bfa74();
    }
    t = *(u32 *)(p + 4);
    t = t & ~1u;
    t = t & 0xFFFFF001u;
    t = t & ~0x1000u;
    t = t & ~0xE000u;
    t = t & ~0x10000u;
    t = t & ~0x1E0000u;
    t = t & ~0x0FE00000u;
    *(u32 *)(p + 4) = t;
    t = *(u32 *)(p + 6);
    t = t & 0xFFFE0000u;
    t = t & 0x8001FFFFu;
    t = t | 0x07D00000u;
    *(u32 *)(p + 6) = t;
    dp = (u8 *) &data_0211faf4;
    t = *(u32 *)(p + 4);
    t = (t & ~0xF0000000u) | 0x20000000u;
    *(u32 *)(p + 4) = t;
    t = *(u32 *)(p + 6);
    t = (t & ~0x80000000u) | 0x80000000u;
    *(u32 *)(p + 6) = t;
    i = 0;
    do {
        old_i = (u16) i;
        p[0] = (u16) ((p[0] & ~0xFFu) | dp[1]);
        {
            u16 x = (u16) (i + 1);
            p[0] = (u16) ((p[0] & ~0xF00u) | (u16) (((u32) x << 28) >> 20));
        }
        t = p[0];
        i = i + 1;
        dp = dp + 1;
        if (old_i == 0) {
            t = (t & ~0xF000u) | 0x1000u;
        } else {
            t = (t & ~0xF000u) | 0x2000u;
        }
        p[0] = (u16) t;
        if (i >= 4) {
            break;
        }
        p = p + 1;
    } while (1);
}

void func_020bfb74(void *a) {
if (!a) a=func_020bfa74();
M2C_FIELD(&data_0215d890,SavePair *,0)=M2C_FIELD(a,SavePair *,0);
M2C_FIELD(&data_0215d890,SavePair *,4)=M2C_FIELD(a,SavePair *,4);
M2C_FIELD(&data_0215d890,u32 *,8)=M2C_FIELD(a,u32 *,8);
M2C_FIELD(&data_0215d890,u32 *,12)=M2C_FIELD(a,u32 *,12);
}

void func_020bfbc0(void *a) {
if (!a) a=func_020bfa74();
M2C_FIELD(a,SavePair *,0)=M2C_FIELD(&data_0215d890,SavePair *,0);
M2C_FIELD(a,SavePair *,4)=M2C_FIELD(&data_0215d890,SavePair *,4);
M2C_FIELD(a,u32 *,8)=M2C_FIELD(&data_0215d890,u32 *,8);
M2C_FIELD(a,u32 *,12)=M2C_FIELD(&data_0215d890,u32 *,12);
}

s32 func_020bfc0c(void) {
s32 func_0207c2f0(void);
s32 func_020a8924(s32);
s32 i,count,chosen,n;
count=0;i=0;
do { if(func_020a8924(i))count++; i++; } while(i<0x113);
if(count) {
chosen=func_0207c2f0()%count;
n=0;i=0;
do {if(func_020a8924(i)){if(chosen==n)return i;n++;}i++;}while(i<0x113);
}
return 0;
}

s32 func_020bfc94(void) {
s32 func_0207c2f0(void);
return func_0207c2f0()%100>80;
}

s32 func_020bfccc(void) {
s32 func_0207c2f0(void);
s32 n=func_0207c2f0()%100;
if(n>80)return 1;if(n>60)return 2;if(n>40)return 3;return 0;
}

s32 func_020bfd1c(u32 a) {
s32 func_0207c2f0(void);
s32 n=func_0207c2f0()%100;
switch(a) {
case 1:if(n>70)return 1;break;
case 2:if(n>70)return 3;break;
case 3:if(n>70)return 2;break;
case 0:if(n>80)return 2;break;
}
return 0;
}

void func_020bfda8(void *arg0) {
    s32 func_020a8994(s32);
    s32 func_020a89c4(s32);
    s32 func_020a89e4(s32);
    void func_020bfa80(u16 *);
    s32 func_020bfc0c();
    s32 func_020bfc94();
    s32 func_020bfccc();
    s32 func_020bfd1c(u32);
    register unsigned long temp_r0;
    unsigned temp_r1;
    void *var_r5;

    var_r5 = arg0;
    if (var_r5 == NULL) {
        var_r5 = func_020bfa74();
    }
    temp_r0 = func_020bfc0c();
    func_020bfa80(var_r5);
    M2C_FIELD(var_r5, s32 *, 8) = (s32) ((M2C_FIELD(var_r5, s32 *, 8) & 0xFFFFF001) | ((u32) (temp_r0 << 0x15) >> 0x14));
    M2C_FIELD(var_r5, s32 *, 8) = (s32) ((M2C_FIELD(var_r5, s32 *, 8) & ~0x1000) | ((u32) (func_020bfc94() << 0x1F) >> 0x13));
    temp_r1 = (M2C_FIELD(var_r5, s32 *, 8) & ~0x1E0000) | ((u32) (func_020bfccc() << 0x1C) >> 0xB);
    M2C_FIELD(var_r5, s32 *, 8) = temp_r1;
    M2C_FIELD(var_r5, s32 *, 8) = (s32) (((M2C_FIELD(var_r5, s32 *, 8) & ~0xE000) | (u16) (func_020bfd1c((u32) (temp_r1 << 0xB) >> 0x1C) << 0xD)) & ~0x10000);
    M2C_FIELD(var_r5, s32 *, 8) = (s32) ((((M2C_FIELD(var_r5, s32 *, 8) & ~0x0FE00000) | ((u32) (func_020a8994(temp_r0) << 0x19) >> 4)) & ~0xF0000000) | 0x20000000);
    M2C_FIELD(var_r5, s32 *, 0xC) = (s32) ((M2C_FIELD(var_r5, s32 *, 0xC) & ~0x1FFFF) | (func_020a89c4(temp_r0) & 0x1FFFF));
    M2C_FIELD(var_r5, s32 *, 0xC) = (s32) ((((M2C_FIELD(var_r5, s32 *, 0xC) & 0x8001FFFF) | ((u32) (func_020a89e4(temp_r0) << 0x12) >> 1)) & ~0x80000000) | 0x80000000);
}

void func_020c01bc(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212945c;
    func_01ffa42c(&data_0212945c, arg0);
}

void func_020c01d4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212942c;
    func_01ffa42c(&data_0212942c, arg0);
}

void func_020c01ec(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02129514;
    func_01ffa42c(&data_02129514, arg0);
}

void func_020c0204(void) {
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK func_02086680(s32);
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020bf7c4();
    M2C_UNK func_020c4910();
    if (func_02076208() != 0) {
        func_02086680(0xC000034D);
        func_02076244();
    }
    func_020bf7c4();
    func_02091c20(0x27, 1);
    func_020c4910();
}

void func_020c023c(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02129404;
    func_01ffa3dc(&data_02129404, arg0);
}

