/* 35 functions from 0x020BF25C to 0x020C0254 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a, b; } SavePair;
typedef struct { u16 id:8; u16 index:4; u16 mode:4; } SaveInitEntry;
typedef struct {
    SaveInitEntry entries[4];
    u32 a:1; u32 b:11; u32 c:1; u32 d:3; u32 e:1;
    u32 f:4; u32 g:7; u32 h:4;
    u32 j:17; u32 k:14; u32 l:1;
} SaveInit;
typedef struct { u8 enabled:1; u8 mode:3; u8 unused:4; } SaveFlags;
typedef struct { u16 low:7; u16 mode:3; u16 high:6; } SaveMode;
extern M2C_UNK data_0215d890, data_0215deec, data_0212616c;

void *func_020bf25c(s32 arg0) {
    (void)arg0;
    return 0;
}

#pragma opt_propagation off
void func_020bf798(void) {
    M2C_UNK func_020be718(M2C_UNK *);
    M2C_UNK func_020be438(s32, M2C_UNK *, s32);
    extern M2C_UNK data_0215deec;
    s32 size = 0x5CC;
    func_020be718(&data_0215deec);
    func_020be438(4, &data_0215deec, size);
}
#pragma opt_propagation reset
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
    extern void **gCurrentMap;
    u16 temp_r2;
    void *temp_r3;

    temp_r3 = *gCurrentMap;
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

#pragma opt_common_subs off
void func_020bf97c(void) {
s32 func_0207cfb8(void);extern M2C_UNK data_0215d990;
switch(func_0207cfb8()){
case 0:M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380);return;
case 128:M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|128;return;
default:M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|128;return;
}
}
#pragma opt_common_subs reset
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
SaveInit *p=(SaveInit *)arg0;
s32 i;
if(!p) p=(SaveInit *)func_020bfa74();
p->a=0; p->b=0; p->c=0; p->d=0; p->e=0; p->f=0; p->g=0;
p->j=0; p->k=1000; p->h=2; p->l=1;
for(i=0;i<4;i++){
p->entries[i].id=((u8 *)&data_0211faf4)[i+1];
p->entries[i].index=(u16)(i+1);
if(i==0) p->entries[i].mode=1;
else p->entries[i].mode=2;
}
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
    func_020bfa80(var_r5);
    temp_r0 = func_020bfc0c();
    M2C_FIELD(var_r5, s32 *, 8) = (s32) ((M2C_FIELD(var_r5, s32 *, 8) & 0xFFFFF001) | ((u32) (temp_r0 << 0x15) >> 0x14));
    M2C_FIELD(var_r5, s32 *, 8) = (s32) ((M2C_FIELD(var_r5, s32 *, 8) & ~0x1000) | ((u32) (func_020bfc94() << 0x1F) >> 0x13));
    temp_r1 = (M2C_FIELD(var_r5, s32 *, 8) & ~0x1E0000) | ((u32) (func_020bfccc() << 0x1C) >> 0xB);
    M2C_FIELD(var_r5, s32 *, 8) = temp_r1;
    M2C_FIELD(var_r5, s32 *, 8) = (s32) (((M2C_FIELD(var_r5, s32 *, 8) & ~0xE000) | (u16) (func_020bfd1c((u32) (temp_r1 << 0xB) >> 0x1C) << 0xD)) & ~0x10000);
    temp_r1 = (M2C_FIELD(var_r5, s32 *, 8) & ~0x0FE00000) | ((u32) (func_020a8994(temp_r0) << 0x19) >> 4);
 M2C_FIELD(var_r5,s32 *,8)=temp_r1;
 M2C_FIELD(var_r5,s32 *,8)=(M2C_FIELD(var_r5,s32 *,8) & ~0xF0000000)|0x20000000;
    M2C_FIELD(var_r5, s32 *, 0xC) = (s32) ((M2C_FIELD(var_r5, s32 *, 0xC) & ~0x1FFFF) | (func_020a89c4(temp_r0) & 0x1FFFF));
    temp_r1 = (M2C_FIELD(var_r5, s32 *, 0xC) & 0x8001FFFF) | ((u32) (func_020a89e4(temp_r0) << 0x12) >> 1);
 M2C_FIELD(var_r5,s32 *,12)=temp_r1;
 M2C_FIELD(var_r5,s32 *,12)=(M2C_FIELD(var_r5,s32 *,12) & ~0x80000000)|0x80000000;
}

void func_020bfebc(void *p) {
 extern void **gCurrentMap; extern u8 data_02168f14[];
 if(!p)p=func_020bfa74();
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&4294963201U)|((u32)(M2C_FIELD(*gCurrentMap,u16 *,20802)<<21)>>20);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&4294963199U)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,20822)<<31)>>19);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&4294909951U)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,20827)<<29)>>16);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&4294901759U)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,20825)<<31)>>15);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&4293001215U)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,20823)<<28)>>11);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&~0xFE00000)|((u32)(data_02168f14[3]<<25)>>4);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&~0xF0000000)|(((u32)(M2C_FIELD(data_02168f14,u16 *,0)<<26)>>29)<<28);
M2C_FIELD(p,u32 *,12)=(M2C_FIELD(p,u32 *,12)&~0x1FFFF)|(M2C_FIELD(data_02168f14,u32 *,8)&0x1FFFF);
M2C_FIELD(p,u32 *,12)=(M2C_FIELD(p,u32 *,12)&0x8001FFFF)|((u32)(M2C_FIELD(data_02168f14,u16 *,6)<<18)>>1);
M2C_FIELD(p,u32 *,12)=(M2C_FIELD(p,u32 *,12)&~0x80000000)|((((u32)(M2C_FIELD(data_02168f14,u16 *,0)<<23)>>31)&1)<<31);
M2C_FIELD(p,u32 *,8)=(M2C_FIELD(p,u32 *,8)&~1)|(((u32)(M2C_FIELD(data_02168f14,u16 *,0)<<25)>>31)&1);
}

void func_020c002c(void *arg0) {
    M2C_UNK *func_020bfa74(void);
    extern void **gCurrentMap;
    extern u8 data_02168f14[];
    if (!arg0) {
        arg0 = func_020bfa74();
    }
    if (((*((u32 *)((s8 *)arg0 + 8)) << 20) >> 21) != 0) {
        *((u16 *)((s8 *)*gCurrentMap + 0x5142)) = (u16)((*((u32 *)((s8 *)arg0 + 8)) << 20) >> 21);
        *((u8 *)((s8 *)*gCurrentMap + 0x5156)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 19) >> 31);
        *((u8 *)((s8 *)*gCurrentMap + 0x5158)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 16) >> 29);
        *((u8 *)((s8 *)*gCurrentMap + 0x515A)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 16) >> 29);
        *((u8 *)((s8 *)*gCurrentMap + 0x515B)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 16) >> 29);
        *((u8 *)((s8 *)*gCurrentMap + 0x5159)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 15) >> 31);
        *((u8 *)((s8 *)*gCurrentMap + 0x5157)) = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 11) >> 28);
        data_02168f14[3] = (u8)((*((u32 *)((s8 *)arg0 + 8)) << 4) >> 25);
        *((u16 *)data_02168f14) = (u16)((*((u16 *)data_02168f14) & ~0x38) | (((*((u32 *)((s8 *)arg0 + 8)) >> 28) << 29) >> 26));
        *((u32 *)(data_02168f14 + 8)) = ((*((u32 *)((s8 *)arg0 + 0xC)) << 15) >> 15);
        *((u16 *)(data_02168f14 + 6)) = (u16)((*((u32 *)((s8 *)arg0 + 0xC)) << 1) >> 18);
        *((u16 *)data_02168f14) = (u16)((*((u16 *)data_02168f14) & ~0x100) | (((*((u32 *)((s8 *)arg0 + 0xC)) >> 31) << 31) >> 23));
        *((u16 *)data_02168f14) = (u16)((*((u16 *)data_02168f14) & ~0x40) | (((*((u32 *)((s8 *)arg0 + 8)) & 1) << 31) >> 25));
    }
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

