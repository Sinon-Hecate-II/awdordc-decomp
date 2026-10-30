/* 25 functions from 0x0202E470 to 0x0202F37C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0xd0a];u8 a;u8 b:2;u8 padb:6;u8 c:4;u8 d:2;u8 padd:2; } Config0202ef;
typedef struct { s32 unk_0; s32 unk_4; } Unk0202ed18;

s32 func_0202ed18(void *,s32);
void func_0202ed8c(s32);
void func_0202ed9c(void *,s32,s32,s32);
void func_0202edd4(s32);
s32 func_0202ede4(void *,s32);
void func_0202ee0c(void);
s32 func_0202ee10(void *,s32,s32,s32);
void func_0202ee2c(void);
void func_0202ec98(void *arg0,s32 arg1) {
 if(func_0202c444(arg1)==0) {
 M2C_FIELD(arg0,void **,0x164)=func_0202ed18;
 M2C_FIELD(arg0,void **,0x168)=func_0202ed8c;
 M2C_FIELD(arg0,void **,0x16C)=func_0202ed9c;
 M2C_FIELD(arg0,void **,0x170)=func_0202edd4;
 } else {
 M2C_FIELD(arg0,void **,0x164)=func_0202ede4;
 M2C_FIELD(arg0,void **,0x168)=func_0202ee0c;
 M2C_FIELD(arg0,void **,0x16C)=func_0202ee10;
 M2C_FIELD(arg0,void **,0x170)=func_0202ee2c;
 }
}

s32 func_0202ed18(void *arg0, s32 arg1) {
 s32 func_0202c3ac(s32,void *,s32,s32);
 void func_0202c424(void *);
 s32 func_0200b9e4(void *,Unk0202ed18);
 s32 func_0202c35c(s32);
 Unk0202ed18 sp0;
 if(func_0202c3ac(arg1,arg0+0xA8,0x40,0)!=0x40)return 0;
 func_0202c424(&sp0);
 if(!func_0200b9e4(arg0+0x5C,sp0))return 0;
 M2C_FIELD(arg0,s32 *,0xA4)=func_0202c35c(arg1);return 1;
}

void func_0202ed8c(s32 arg0) {
    M2C_UNK func_0200ba9c(s32);
    func_0200ba9c(arg0 + 0x5C);
}

void func_0202ed9c(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0200bbe0(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200bbf0(void *, s32, M2C_UNK);
    func_0200bbf0(arg0 + 0x5C, M2C_FIELD(arg0, s32 *, 0xA4) + arg3, 0);
    func_0200bbe0(arg0 + 0x5C, arg1, arg2);
}

void func_0202edd4(s32 arg0) {
    M2C_UNK func_0200bb98(s32);
    func_0200bb98(arg0 + 0x5C);
}

s32 func_0202ede4(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(s32, s32, M2C_UNK);
    s32 func_0202c444(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_0202c444(arg1);
    M2C_FIELD(arg0, s32 *, 0xA4) = temp_r0;
    func_02008048(temp_r0, arg0 + 0xA8, 0x40);
    return 1;
}

void func_0202ee0c(void) {

}

s32 func_0202ee10(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
 func_02008048(M2C_FIELD(arg0,s32 *,0xA4)+arg3,arg1,arg2); return arg2;
}

void func_0202ee2c(void) {

}

#pragma opt_common_subs off
void func_0202ee30(void *arg0) {
 void func_02005da4(void *); void func_02006564(void *); void func_020065e8(void *);
 void *func_0202e09c(void *); void func_0202e470(void *); void func_0202e12c(void *);
 register char *base=(char *)arg0+0xC8;
 func_02005da4(arg0+0x4C0);
 for (;;) {
 register void *p;
 func_02006564(base+0x400);
 p=func_0202e09c(arg0+0x4E0);
 if (!p) {func_020065e8(base+0x400);continue;}
 func_0202e470(p);func_0202e12c(p);func_020065e8(base+0x400);
 }
}
#pragma opt_common_subs reset
void *func_0202ee80(void *arg0,s32 arg1) {
 void *p;
 if(arg1<0)return NULL;
 if((u32)arg1>=M2C_FIELD(arg0,u32 *,0x1C))return NULL;
 p=arg0+0x20+arg1*12;
 if(M2C_FIELD(p,s32 *,0)==-1)return NULL;
 return p;
}

void func_0202eec0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_0202eed8(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0202ef00();
    M2C_FIELD(arg0, s32 *, 0) = func_0202ef00();
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 func_0202ef00(void *arg0) {
 s32 func_020720f0(s32,s32);
 s32 n=M2C_FIELD(arg0,s32 *,0xC);
 s32 t=M2C_FIELD(arg0,s32 *,8);
 s32 start;
 if(t>=n)return M2C_FIELD(arg0,s32 *,4);
 start=M2C_FIELD(arg0,s32 *,0);
 return start+func_020720f0(t*(M2C_FIELD(arg0,s32 *,4)-start),n);
}

void func_0202ef34(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r2 < (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r2 + 1);
    }
}

s32 func_0202ef4c(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 8) >= (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        return 1;
    }
    return 0;
}

s32 func_0202ef64(void *a) {
void func_02007e54(s32,void *,s32);s32 func_0202f2f4(s32,M2C_UNK);void func_02045c90(void);s32 func_020270b4(void *,s32);void func_0202f37c(void);
extern M2C_UNK data_0213d100;
void *p,*q;Config0202ef *cfg;s32 r;
p=M2C_FIELD(a,void *(**)(s32,s32),0)(1,24);
M2C_FIELD(&data_0213d100,void **,16)=p;func_02007e54(0,p,24);
p=M2C_FIELD(&data_0213d100,void **,16);
M2C_FIELD(p,s32 *,0)=M2C_FIELD(a,s32 *,0);M2C_FIELD(p,s32 *,4)=M2C_FIELD(a,s32 *,4);
M2C_FIELD(p,u8 *,9)=1;M2C_FIELD(p,u8 *,22)=1;M2C_FIELD(p,u8 *,8)=1;
M2C_FIELD(&data_0213d100,s32 *,0)=func_0202f2f4(16,0xd18);
M2C_FIELD(&data_0213d100,s32 *,4)=func_0202f2f4(2,0x2300);
M2C_FIELD(&data_0213d100,s32 *,8)=func_0202f2f4(4,88);
M2C_FIELD(&data_0213d100,s32 *,12)=func_0202f2f4(8,12);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,0),0xd18);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,4),0x2300);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,8),88);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,12),12);
cfg=M2C_FIELD(&data_0213d100,Config0202ef **,0);
cfg->a=M2C_FIELD(a,u8 *,8);cfg->b=M2C_FIELD(a,u8 *,9);
q=M2C_FIELD(&data_0213d100,void **,12);M2C_FIELD(q,s32 *,0)=M2C_FIELD(a,s32 *,0);M2C_FIELD(q,s32 *,4)=M2C_FIELD(a,s32 *,4);M2C_FIELD(q,s32 *,8)=0;
cfg->c=M2C_FIELD(a,u8 *,10);cfg->d=M2C_FIELD(a,u8 *,11);
func_02045c90();
r=func_020270b4(M2C_FIELD(&data_0213d100,void **,4),0x2300);
if(r==1 || r>=4){func_0202f37c();return 0;}return 1;
}

s32 func_0202f10c(void) {
 u32 func_0202f544();
 u32 func_02031208(); u32 func_02030a38(); u32 func_0202fc9c();
 u32 func_0203095c(); u32 func_02031290(); u32 func_02030324();
 s32 func_0200751c(); void func_02007530(s32);
 void func_0202f4e4(u32); s32 func_0202f5f4(); void func_0202f5bc();
 u32 n=func_0202f544(); s32 t;
 if(n==1)n=func_02031208();
 else if(n<7){t=func_0200751c();n=func_02030a38();func_0202f4e4(n);func_02007530(t);}
 else if(n<9)n=func_0202fc9c();
 else if(n<10)n=func_0203095c();
 else if(n<16)n=func_02031290();
 else if(n==17)n=func_02030324();
 func_0202f4e4(n);
 if(n==16){t=func_0202f5f4();func_0202f5bc();return t;}
 if(n==18){func_0202f5bc();return -1;}
 return 0;
}

s32 func_0202f1dc(void) {
 u32 func_0202f544();
 s32 func_02030348(u32);
 u32 n=func_0202f544();
 if(n<=1)return 0;
 if(n<7)return 1;
 if(n==9)return 4;
 if(n<10)return 2;
 if(n==11)return 4;
 if(n<16)return 3;
 if(n==16)return 5;
 if(n==17)return 4;
 return func_02030348(n);
}

u8 func_0202f248(void) {
    u32 func_0202f544();
    extern M2C_UNK data_0213d100;
    u32 temp_r0;
    u8 var_r4;

    var_r4 = 0xFF;
    if (M2C_FIELD(&data_0213d100, void **, 0x10) == NULL) {
        return 0xFFU;
    }
    temp_r0 = func_0202f544();
    if ((temp_r0 >= 0xAU) && (temp_r0 <= 0x10U)) {
        var_r4 = M2C_FIELD(M2C_FIELD(&data_0213d100, void **, 0x10), u8 *, 0x17);
    }
    return var_r4;
}

s32 func_0202f28c(void) {
 u32 func_0202f544();
 void func_0202f37c(void);
 void func_020301dc(u8 *);
 void func_0202f4e4(u32);
 u8 n=func_0202f544();
 if(n==0 || n==18) {
 func_0202f37c(); return 1;
 }
 func_020301dc(&n);func_0202f4e4(n);return 0;
}

void func_0202f2c8(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02007e70(M2C_UNK, s32, M2C_UNK);
    s32 func_0202f48c(M2C_UNK);
    func_02007e70(arg1, func_0202f48c(0x10) + (arg0 << 8), 0xF0);
}

s32 func_0202f2f4(s32 arg0, M2C_UNK arg1) {
    u8 temp_r1;
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 8);
    if (temp_r1 & arg0) {
        return 0;
    }
    M2C_FIELD(temp_r0, u8 *, 8) = (u8) (temp_r1 | arg0);
    return M2C_FIELD(temp_r0, s32 (**)(s32, M2C_UNK), 0)(arg0, arg1);
}

void func_0202f334(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    u8 temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    temp_r2 = M2C_FIELD(temp_r0, u8 *, 8);
    if (!(temp_r2 & arg0)) {
        return;
    }
    M2C_FIELD(temp_r0, u8 *, 8) = (u8) (temp_r2 & ~arg0);
    M2C_FIELD(temp_r0, M2C_UNK (**)(s32, M2C_UNK, M2C_UNK), 4)(arg0, arg1, arg2);
}

