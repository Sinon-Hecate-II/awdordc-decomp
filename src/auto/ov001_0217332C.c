/* 12 functions from 0x0217332C to 0x0217416C (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[5]; } SpriteGroupCounts;
typedef struct { s32 x; u32 y; } Position;


void func_ov001_0217355c(u8 arg0, s32 arg1, s32 arg2, u32 arg3);
void func_ov001_0217385c(s32 arg0, s32 arg1);
s32 *func_ov001_0218a24c(s32 arg0, s32 arg1);
void func_ov001_0218c924(void *arg0, void *arg1);
extern void *data_ov001_02193d1c;
extern u8 data_ov001_0218f314[];
extern u8 data_ov001_0218f318[];
extern u8 data_ov001_0218f36c[];
void func_ov001_02173ebc(void *arg0);
void func_ov001_02173f30(void *arg0);
void func_ov001_02173fa4(void *arg0);
void func_ov001_02174018(void *arg0);
void func_ov001_0217408c(int arg0);

void func_ov001_0217332c(void) { return; }

#pragma scheduling off
#pragma optimization_level 3
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void func_ov001_0217355c(u8 arg0,s32 arg1,s32 arg2,u32 arg3){
extern u8 data_ov001_0218f328[];
extern u16 data_ov001_0218f34c[],data_ov001_0218f344[];
void func_ov001_0218b200(s32,u16,s32,s32,s32);
s32 func_020020c4(s32,s32);
void func_ov001_0218a260(void *,s32,s32,s32);
M2C_UNK func_ov001_0218a384(s32,M2C_UNK,u16,u16);
SpriteGroupCounts a,b,c;
s32 index=arg1*12; s32 i,j;void *p;u16 tile;
a=*(SpriteGroupCounts *)(data_ov001_0218f328+17);
b=*(SpriteGroupCounts *)(data_ov001_0218f328+22);
c=*(SpriteGroupCounts *)(data_ov001_0218f328+12);
i=0;j=index;
if(a.v[arg1]>0)do{
tile=*(u16 *)(data_ov001_0218f36c+j*4);
p=M2C_FIELD((u8 *)data_ov001_02193d1c+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=M2C_FIELD(p,u32 *,0)&~0x3e000300U;
p=M2C_FIELD((u8 *)data_ov001_02193d1c+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|((tile&0x1ff)<<16)|(arg2&255);
i++;j++;
}while(i<a.v[arg1]);
if(arg1<4)func_ov001_0218b200(M2C_FIELD((u8 *)data_ov001_02193d1c+arg0*16+arg1*4,s32 *,0),*(u16 *)(data_ov001_0218f36c+index*4),arg2,M2C_FIELD((u8 *)data_ov001_02193d1c+arg1*4,s32 *,0x104),2);
j=func_020020c4(arg1+3,4);
i=0;
if(b.v[arg1]>0){
j*=4;
tile=*(u16 *)((u8 *)data_ov001_0218f34c+j);
do{
p=M2C_FIELD((u8 *)data_ov001_02193d1c+j,void **,0xec);
M2C_FIELD(p,u32 *,0)&=0xc1fffcff;
p=M2C_FIELD((u8 *)data_ov001_02193d1c+j,void **,0xec);
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|((tile&0x1ff)<<16)|(arg2&255);
i++;
}while(i<b.v[arg1]);
}
i=0;
if(c.v[arg1]>0)do{
func_ov001_0218a260(M2C_FIELD((u8 *)data_ov001_02193d1c+i*4,void **,0xfc),-1,0,0);
func_ov001_0218a384(M2C_FIELD((u8 *)data_ov001_02193d1c+i*4,s32 *,0xfc),-1,data_ov001_0218f344[i*2],arg2);
i++;
}while(i<c.v[arg1]);
}
#pragma opt_strength_reduction off
void func_ov001_021737d8(s8 arg0) {
s32 var_r4,var_r5,var_r6,var_r7;
var_r5=0;var_r6=0;var_r4=0;var_r7=0;
M2C_FIELD(data_ov001_02193d1c,s8*,0x11d)=arg0;
do {
((void(*)(s8,s32,u16))func_ov001_0217355c)(arg0,var_r4,M2C_FIELD(data_ov001_0218f36c+var_r7*4,u16*,2));
var_r4++;var_r7+=12;
}while(var_r4<4);
if(arg0==2)var_r5=1;else if(arg0==1)var_r6=1;
func_ov001_0217385c(47,var_r5);func_ov001_0217385c(48,var_r6);
}
#pragma scheduling off
#pragma opt_common_subs off
void func_ov001_0217385c(s32 arg0, s32 arg1) {
    void func_ov001_0218a304(void *, s32, s32, u8);
    void *p;

    if (arg0 < 0) {
        return;
    }
    if (arg0 < 0x2f) {
        p = M2C_FIELD((data_ov001_02193d1c + (arg0 * 4)), void **, 0x30);
        arg1 = data_ov001_0218f314[arg1];
        M2C_FIELD(p, s32 *, 0) = (s32)(M2C_FIELD(p, s32 *, 0) & ~0xc00);
        M2C_FIELD(p, u16 *, 4) = (u16)((M2C_FIELD(p, u16 *, 4) & ~0xf000) | (arg1 << 0xc));
        return;
    }
    {
        s32 temp_ip = arg0 - 0x2f;
        if (temp_ip < 4) {
            p = M2C_FIELD((data_ov001_02193d1c + (temp_ip * 4)), void **, 0xec);
            arg1 = data_ov001_0218f314[arg1];
            M2C_FIELD(p, s32 *, 0) = (s32)(M2C_FIELD(p, s32 *, 0) & ~0xc00);
            M2C_FIELD(p, u16 *, 4) = (u16)((M2C_FIELD(p, u16 *, 4) & ~0xf000) | (arg1 << 0xc));
            return;
        }
    }
    func_ov001_0218a304(M2C_FIELD((data_ov001_02193d1c + ((arg0 - 0x33) * 4)), s32 *, 0xfc), -1, 0, data_ov001_0218f318[arg1]);
}
#pragma scheduling reset
#pragma opt_common_subs reset
void func_ov001_02173924(void) {
    s32 *func_ov001_0218a24c(s32, s32);
    M2C_UNK func_ov001_0218a384(s32, M2C_UNK, u16, u16);
    M2C_UNK func_ov001_0218a474(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a55c(M2C_UNK, M2C_UNK, s32);
    extern void *data_ov001_02193d1c;
    extern u16 data_ov001_0218f428[];
    extern u16 data_ov001_0218f42a[];
    M2C_UNK var_r4;
    s32 temp_ip;

    switch (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x121) - 0x2F) {
    case 0:
        var_r4 = 0x42;
        break;
    case 1:
        var_r4 = 0x41;
        break;
    case 2:
        var_r4 = 0x43;
        break;
    case 3:
        var_r4 = 0x41;
        break;
    case 4:
    case 5:
        var_r4 = 0x45;
        break;
    default:
        var_r4 = 0x40;
        break;
    }
    func_ov001_0218a55c(0, var_r4, func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x114), 0));
    func_ov001_0218a474(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x114), -1, 2);
    temp_ip = M2C_FIELD(data_ov001_02193d1c, s8 *, 0x121) * 2;
    func_ov001_0218a384(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x114), -1, data_ov001_0218f428[temp_ip], data_ov001_0218f42a[temp_ip]);
}

void func_ov001_02173a00(s32 arg0) {
extern s8 data_ov001_0218f4fc[];
void func_ov001_02185024(s32);
s32 old = M2C_FIELD(data_ov001_02193d1c,s8 *,0x121);
void *p; s32 n;
M2C_FIELD(data_ov001_02193d1c,s8 *,0x121)=*(data_ov001_0218f4fc+old*4+arg0);
p=data_ov001_02193d1c;n=M2C_FIELD(p,s8 *,0x121);
if(n==46 && arg0==3) M2C_FIELD(p,s8 *,0x120)=old;
else if(n==51 && (arg0==1 || arg0==3)) M2C_FIELD(p,s8 *,0x120)=old;
else if(n==52 && (arg0==1 || arg0==3)) {if(old!=46) M2C_FIELD(p,s8 *,0x120)=old;}
else if(n==-1) {if(M2C_FIELD(p,s8 *,0x120)==35 || M2C_FIELD(p,s8 *,0x120)==50) M2C_FIELD(p,s8 *,0x121)=35;else M2C_FIELD(p,s8 *,0x121)=34;}
else if(n==-2) {switch(M2C_FIELD(p,s8 *,0x120)) {case 0:case 49:M2C_FIELD(p,s8 *,0x121)=49;break;case 1:case 36:M2C_FIELD(p,s8 *,0x121)=36;break;case 3:case 38:M2C_FIELD(p,s8 *,0x121)=38;break;case 4:case 39:M2C_FIELD(p,s8 *,0x121)=39;break;case 5:case 40:M2C_FIELD(p,s8 *,0x121)=40;break;default:M2C_FIELD(p,s8 *,0x121)=37;break;}}
else if(n==-3) {switch(M2C_FIELD(p,s8 *,0x120)) {case 6:case 41:M2C_FIELD(p,s8 *,0x121)=41;break;case 7:case 42:M2C_FIELD(p,s8 *,0x121)=42;break;case 9:case 44:M2C_FIELD(p,s8 *,0x121)=44;break;case 10:case 45:M2C_FIELD(p,s8 *,0x121)=45;break;case 11:case 34:case 35:case 50:M2C_FIELD(p,s8 *,0x121)=46;break;default:M2C_FIELD(p,s8 *,0x121)=43;break;}}
else if(n==-4) {switch(M2C_FIELD(p,s8 *,0x120)) {case 0:case 49:M2C_FIELD(p,s8 *,0x121)=0;break;case 1:case 36:M2C_FIELD(p,s8 *,0x121)=1;break;case 3:case 38:M2C_FIELD(p,s8 *,0x121)=3;break;case 4:case 39:M2C_FIELD(p,s8 *,0x121)=4;break;case 5:case 40:M2C_FIELD(p,s8 *,0x121)=5;break;default:M2C_FIELD(p,s8 *,0x121)=2;break;}}
else if(n==-5) {switch(M2C_FIELD(p,s8 *,0x120)) {case 6:case 41:M2C_FIELD(p,s8 *,0x121)=6;break;case 7:case 42:M2C_FIELD(p,s8 *,0x121)=7;break;case 9:case 44:M2C_FIELD(p,s8 *,0x121)=9;break;case 10:case 45:M2C_FIELD(p,s8 *,0x121)=10;break;case 11:case 34:M2C_FIELD(p,s8 *,0x121)=11;break;case 35:case 50:M2C_FIELD(p,s8 *,0x121)=50;break;default:M2C_FIELD(p,s8 *,0x121)=8;break;}}
func_ov001_02173924();func_ov001_02185024(8);}

void func_ov001_02173e38(void *arg0) {
    typedef struct { s32 x; u32 y; } Position;
    extern void *data_ov001_02193d1c;
    Position pos;
    s32 bits;

    bits = *func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d1c, s32 *, 0xFC), 0);
    pos.x = (u8)bits + 0xC;
    pos.y = (u32)(bits & 0x01FF0000) >> 0x10;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 4, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173ebc);
}

void func_ov001_02173ebc(void *arg0) {
Position pos;
void *a=data_ov001_02193d1c;
u32 bits=*M2C_FIELD(a,u32**,0xc0);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,3,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02173f30);
}

void func_ov001_02173f30(void *arg0) {
Position pos;
void *a=data_ov001_02193d1c;
u32 bits=*M2C_FIELD(a,u32**,0x90);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,2,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02173fa4);
}

#pragma opt_strength_reduction off
void func_ov001_02173fa4(void *arg0) {
Position pos;
void *a=data_ov001_02193d1c;
u32 bits=*M2C_FIELD(a,u32**,0x60);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,1,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02174018);
}
#pragma opt_strength_reduction reset
void func_ov001_02174018(void *arg0) {
    void func_ov001_0218c924(void *, void *);
    void func_ov001_0217355c(u8, s32, s32, u32);
    Position pos;
    void *a = data_ov001_02193d1c;
    u32 bits = *M2C_FIELD(a, u32 **, 0x30);
    u8 b = M2C_FIELD(a, u8 *, 0x11d);
    pos.y = (bits & 0x01ff0000U) >> 16;
    pos.x = (u8)bits + 12;
    func_ov001_0217355c(b, 0, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xc0) return;
    func_ov001_0218c924(arg0, &func_ov001_0217408c);
}

void func_ov001_0217408c(int arg0) {
int i, j; unsigned int *ptr;
func_ov001_0218c92c(0,arg0);
for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        ptr=(unsigned int *)data_ov001_02193d1c;
        func_ov001_0218ace0(((unsigned int (*)[4])ptr)[i][j]);
        if(i==0){ptr=(unsigned int *)data_ov001_02193d1c;func_ov001_0218a1cc(((void **)ptr)[j+0x41]);}
    }
}
for(i=0;i<2;i++){ptr=(unsigned int *)data_ov001_02193d1c;func_ov001_0218a1cc(((void **)ptr)[i+0x3f]);}
for(i=0;i<4;i++){ptr=(unsigned int *)data_ov001_02193d1c;func_ov001_0218c104(((void **)ptr)[i+0x3b]);}
for(i=0;i<0x2f;i++){ptr=(unsigned int *)data_ov001_02193d1c;func_ov001_0218c104(((void **)ptr)[i+0xc]);}
func_ov001_0218b71c(&data_ov001_02193d1c);
}

