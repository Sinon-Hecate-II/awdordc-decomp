/* 28 functions from 0x02170830 to 0x021717FC (ov001), found by ds-decomp. */
#include "common.h"
extern s32 data_ov001_02192790[];
extern s32 data_ov001_0218fde8[];
extern u8 data_ov001_0219283c[];
typedef struct { u32 words[58]; } NetworkClearState;
typedef struct { u32 w[8]; } ClearBlk8;
typedef struct { u32 w[2]; } ClearBlk2;
extern u32 data_ov001_021928fc[];
void func_ov001_0216f78c(void);
s32 func_ov001_0216e34c(s32);
s32 func_02005ab0(void);
void func_02005ac0(void *,void (*)(void),s32,s32,s32,s32);
void func_02005e5c(void *);
void func_ov001_021713a8(void);
extern void *data_ov001_02193cc8;
extern const u8 data_ov001_0218f2a8[];
extern const u8 data_ov001_0218f29a[];
extern const u16 data_ov001_0218f284[];
void func_ov001_0218a384(void *, s32, s32, void *);

#pragma thumb on
void func_ov001_02171078(u8 *a,volatile u32 *b,u32 n){u32 i;for(i=0;i<n;i+=4){a[i]=*b;a[i+1]=*b>>8;a[i+2]=*b>>16;a[i+3]=*b>>24;b++;}}
#pragma thumb on
void func_ov001_021710a4(u32 *a,u8 *b,u32 n){u32 i;for(i=0;i<n;i+=4){*a++=b[i]|(b[i+1]<<8)|(b[i+2]<<16)|(b[i+3]<<24);}}

#pragma thumb on
void func_ov001_021710d0(u8 *a,u8 *b,u32 n){u32 i;for(i=0;i<n;i++)a[i]=b[i];}
#pragma thumb off

#pragma thumb on
void func_ov001_021710e8(s8 *a,s32 b,u32 n){u32 i;for(i=0;i<n;i++)*a++=(s8)b;}

void func_ov001_02171100(M2C_UNK a,M2C_UNK b,M2C_UNK c){
 M2C_UNK func_ov001_0217073c(M2C_UNK *);M2C_UNK func_ov001_02170764(M2C_UNK *,M2C_UNK,M2C_UNK);M2C_UNK func_ov001_021707dc(M2C_UNK,M2C_UNK *);
 M2C_UNK p[22];func_ov001_0217073c(p);func_ov001_02170764(p,b,c);func_ov001_021707dc(a,p);
}

void func_ov001_02171128(void){u64 func_02007004(void);void func_02072088(u64,u64);func_02072088(func_02007004()<<6,0x82ea);}

#pragma thumb on
s32 func_ov001_02171178(s8 *a, s32 b) {
    s32 i = 0;
    u8 t = (u8)b;
    s32 v = (t & 0xF0) >> 4;
    s8 *p = a;
    do {
        s32 ch;
        if (v <= 9) {
            ch = v + 0x30;
        } else {
            ch = v + 0x37;
        }
        i++;
        *p++ = (s8)ch;
        v = t & 0x0F;
    } while (i < 2);
    *p = 0;
    return (s32)(p - a);
}
s32 func_ov001_021711ac(s8 *arg0,s8 *arg1){
 s8 *sp0=arg0; s8 *p=arg0; s32 i; s8 *q=arg1,*t;s8 v;
 for(i=0;i<6;i++){v=*q++;t=p+func_ov001_02171178(p,v);p=t;if(i<5){p=t+1;*t=0x3a;}}
 *p=0;return p-sp0;
}

void *memset(void *,s32,u32);
#pragma optimize_for_size off
s32 func_ov001_021711e0(s32 a,s32 b,s32 c,s32 (*d)(s32),s32 e,s32 f){
s32 r;u32 i;u32 *p;
if(data_ov001_02192790[14]>=1 && data_ov001_02192790[14]<=5)return -10;
data_ov001_0218fde8[4]=b;data_ov001_02192790[14]=7;data_ov001_02192790[31]=c;((s32 (**)(s32))data_ov001_02192790)[1]=d;data_ov001_02192790[3]=e;data_ov001_0218fde8[2]=f;
r=func_ov001_0216e34c(b);data_ov001_02192790[29]=1;if(r<0){data_ov001_02192790[30]=r;return r;}
r=((s32 (**)(s32))data_ov001_02192790)[1](data_ov001_0218fde8[2]);data_ov001_02192790[12]=r;if(!r){data_ov001_02192790[30]=-1;return -1;}if(func_02005ab0()!=1){data_ov001_02192790[30]=-9;return -9;}
func_02005ac0(data_ov001_0219283c,func_ov001_0216f78c,0,data_ov001_02192790[12]+(data_ov001_0218fde8[2]&~7),data_ov001_0218fde8[2],a);data_ov001_02192790[14]=1;data_ov001_0218fde8[3]=((s32 (*)(void))func_ov001_02171128)()+60000;data_ov001_02192790[4]=0;
p=data_ov001_021928fc;i=58;do{*p++=0;}while(--i);
func_ov001_021713a8();func_02005e5c(data_ov001_0219283c);data_ov001_02192790[25]=1;return 1;
}
#pragma optimize_for_size reset
void func_ov001_021714d0(void);
#pragma thumb off
void func_ov001_021713c4(u8 arg0) {
s32 *func_ov001_0218a5f0(s32,s32); void *func_ov001_0218b6f8(s32,s32); s32 func_ov001_0218c884(s32,void (*)(void),s32,s32);
extern M2C_UNK data_ov001_0218f278; extern void *data_ov001_02193cc4;
s32 *p; void *a; u32 v;
a=func_ov001_0218b6f8(12,4);data_ov001_02193cc4=a;M2C_FIELD(a,s8 *,8)=arg0;
M2C_FIELD(data_ov001_02193cc4,s32 **,4)=func_ov001_0218a5f0(0,0x47);
v=((u8 *)&data_ov001_0218f278)[arg0];
p=M2C_FIELD(data_ov001_02193cc4,s32 **,4);
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xc00)|0x400;
p=M2C_FIELD(data_ov001_02193cc4,s32 **,4);*p&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(v<<12);
p=M2C_FIELD(data_ov001_02193cc4,s32 **,4);*p=(*p&0xfe00ff00)|0xe6008b;
M2C_FIELD(data_ov001_02193cc4,s32 *,0)=func_ov001_0218c884(1,func_ov001_021714d0,0,120);
}
#pragma merge_constants off
void func_ov001_02171494(void) {
    M2C_UNK func_ov001_0218b71c(void **);
    M2C_UNK func_ov001_0218c104(s32);
    M2C_UNK func_ov001_0218c94c(M2C_UNK, s32);
    extern void *data_ov001_02193cc4;
    extern void *data_ov001_02193cc8;
    func_ov001_0218c94c(1, M2C_FIELD(data_ov001_02193cc4, s32 *, 0));
    func_ov001_0218c104(M2C_FIELD(data_ov001_02193cc4, s32 *, 4));
    func_ov001_0218b71c(&data_ov001_02193cc8 - 1);
}
#pragma merge_constants reset
void func_ov001_021714d0(void) {
    s32 func_02002088(u8, M2C_UNK);
    u8 func_020020c4(s32, M2C_UNK);
    M2C_UNK func_ov001_0218a55c(M2C_UNK, s32, s32 *);
    extern M2C_UNK data_ov001_0218f278;
    extern void *data_ov001_02193cc4;
    s32 *temp_r2;
    s32 *temp_r3;
    s32 *temp_r3_2;

    M2C_FIELD(data_ov001_02193cc4, u8 *, 9) = func_020020c4(M2C_FIELD(data_ov001_02193cc4, u8 *, 9) + 1, (M2C_UNK)0x28);
    func_ov001_0218a55c(0, func_02002088(M2C_FIELD(data_ov001_02193cc4, u8 *, 9), 5) + 0x47, M2C_FIELD(data_ov001_02193cc4, s32 **, 4));
    temp_r3 = M2C_FIELD(data_ov001_02193cc4, s32 **, 4);
    M2C_FIELD(temp_r3, u16 *, 4) = (u16) ((M2C_FIELD(temp_r3, u16 *, 4) & ~0xC00) | 0x400);
    temp_r3_2 = M2C_FIELD(data_ov001_02193cc4, s32 **, 4);
    M2C_FIELD(temp_r3_2, s32 *, 0) &= ~0xC00;
    M2C_FIELD(temp_r3_2, u16 *, 4) = (u16) ((M2C_FIELD(temp_r3_2, u16 *, 4) & ~0xF000) | (((u8 *)&data_ov001_0218f278)[M2C_FIELD(data_ov001_02193cc4, u8 *, 8)] << 0xC));
    temp_r2 = M2C_FIELD(data_ov001_02193cc4, s32 **, 4);
    *temp_r2 = (*temp_r2 & 0xFE00FF00) | 0xE6008B;
}

/* Build the state for a render effect indexed by id: allocate the 28-byte
   control block, load its sprite list from data_ov001_0218f28c, and set up
   animation timer (120 units). */
void func_ov001_0217159c(s32 id) {
    extern const u8 data_ov001_0218f28c[];
    void func_ov001_02171768(void *);
    void *func_ov001_0218b6f8(s32, s32);
    void *func_ov001_0218a61c(s32, s32, s32);
    void func_ov001_0218a474(void *, s32, s32);
    void func_ov001_021717fc(void);
    s32 func_ov001_0218c884(s32, void (*)(void), s32, s32);
    s32 n, i;
    const u8 *p;
    n = data_ov001_0218f2a8[id];
    data_ov001_02193cc8 = func_ov001_0218b6f8(28, 4);
    M2C_FIELD(data_ov001_02193cc8, s8 *, 22) = -2;
    M2C_FIELD(data_ov001_02193cc8, u8 *, 23) = id;
    i = 0;
    if (n > 0) {
        p = data_ov001_0218f28c + id * 2;
        do {
            ((void **)data_ov001_02193cc8)[i] = func_ov001_0218a61c(0, *p++, 1);
            func_ov001_0218a474(((void **)data_ov001_02193cc8)[i], -1, 1);
            i++;
        } while (i < n);
    }
    M2C_FIELD(data_ov001_02193cc8, void **, 8) = func_ov001_0218a61c(0, 1, 1);
    func_ov001_0218a474(M2C_FIELD(data_ov001_02193cc8, void **, 8), -1, 1);
    func_ov001_02171768((void *)192);
    M2C_FIELD(data_ov001_02193cc8, s32 *, 12) = func_ov001_0218c884(0, func_ov001_021717fc, 0, 120);
}

void func_ov001_02171694(void){
 extern void *data_ov001_02193cc8;void func_ov001_0218c924(s32,void (*)(void));void func_ov001_02171a44(void);
 M2C_FIELD(data_ov001_02193cc8,u8 *,0x19)=1;
 func_ov001_0218c924(M2C_FIELD(data_ov001_02193cc8,s32 *,12),func_ov001_02171a44);
}

#pragma thumb off

#pragma thumb off

s8 func_ov001_021716c4(void) {
    extern void *data_ov001_02193cc8;
    return M2C_FIELD(data_ov001_02193cc8, s8 *, 0x16);
}

void func_ov001_021716d8(s8 a){if(M2C_FIELD(data_ov001_02193cc8,s8 *,0x16)==-1)M2C_FIELD(data_ov001_02193cc8,s8 *,0x16)=a;}

void func_ov001_021716f8(s8 a){extern void *data_ov001_02193cc8;M2C_FIELD(data_ov001_02193cc8,s8 *,0x16)=a;}

s32 func_ov001_0217170c(void){if(data_ov001_02193cc8==NULL)return 1;if(M2C_FIELD(data_ov001_02193cc8,u8 *,0x19)==0)return 1;return 0;}

#pragma thumb off
void func_ov001_02171738(void){extern void *data_ov001_02193cc8;M2C_FIELD(data_ov001_02193cc8,u8 *,0x18)=0;}

void func_ov001_02171750(void){M2C_FIELD(data_ov001_02193cc8,u8 *,0x18)=1;}

void func_ov001_02171768(void *a){s32 n,i;n=data_ov001_0218f2a8[M2C_FIELD(data_ov001_02193cc8,u8 *,0x17)];func_ov001_0218a384(M2C_FIELD(data_ov001_02193cc8,void **,8),-1,0,a);for(i=0;i<n;i++)func_ov001_0218a384(((void **)data_ov001_02193cc8)[i],-1,data_ov001_0218f284[((const u8 (*)[2])data_ov001_0218f29a)[M2C_FIELD(data_ov001_02193cc8,u8 *,0x17)][i]*2],(u8 *)a+4);}

