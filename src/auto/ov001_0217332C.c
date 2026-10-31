/* 12 functions from 0x0217332C to 0x0217416C (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[5]; } SpriteGroupCounts;


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
#pragma scheduling reset
#pragma optimization_level reset
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
void func_ov001_021737d8(s8 arg0) {
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r5 = 0;
    var_r6 = 0;
    var_r4 = 0;
    var_r7 = 0;
    M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11D) = arg0;
    do {
        func_ov001_0217355c(arg0, var_r4, *(u16*)(data_ov001_0218f36c + var_r7 * 4 + 2), 0);
        var_r4 += 1;
        var_r7 += 0xC;
    } while (var_r4 < 4);
    if (arg0 == 2) {
        var_r5 = 1;
    } else if (arg0 == 1) {
        var_r6 = 1;
    }
    func_ov001_0217385c(0x2F, var_r5);
    func_ov001_0217385c(0x30, var_r6);
}

#pragma scheduling off
void func_ov001_0217385c(s32 arg0, s32 arg1) {
    void func_ov001_0218a304(void *, s32, s32, u8);
    void *temp_r2;

    if (arg0 < 0) {
        return;
    }
    if (arg0 < 0x2f) {
        arg1 = data_ov001_0218f314[arg1];
        temp_r2 = M2C_FIELD((data_ov001_02193d1c + (arg0 * 4)), void **, 0x30);
        M2C_FIELD(temp_r2, s32 *, 0) = (s32)(M2C_FIELD(temp_r2, s32 *, 0) & ~0xc00);
        M2C_FIELD(temp_r2, u16 *, 4) = (u16)((M2C_FIELD(temp_r2, u16 *, 4) & ~0xf000) | (arg1 << 0xc));
        return;
    }
    {
        s32 temp_ip = arg0 - 0x2f;
        if (temp_ip < 4) {
            arg1 = data_ov001_0218f314[arg1];
            temp_r2 = M2C_FIELD((data_ov001_02193d1c + (temp_ip * 4)), void **, 0xec);
            M2C_FIELD(temp_r2, s32 *, 0) = (s32)(M2C_FIELD(temp_r2, s32 *, 0) & ~0xc00);
            M2C_FIELD(temp_r2, u16 *, 4) = (u16)((M2C_FIELD(temp_r2, u16 *, 4) & ~0xf000) | (arg1 << 0xc));
            return;
        }
    }
    func_ov001_0218a304(M2C_FIELD((data_ov001_02193d1c + ((arg0 - 0x33) * 4)), s32 *, 0xfc), -1, 0, data_ov001_0218f318[arg1]);
}
#pragma scheduling reset
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

M2C_UNK func_ov001_02173a00(M2C_UNK arg0) {
    return 0;
}

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
    void func_ov001_0218c924(void *, void *);
    void func_ov001_0217355c(u8, s32, s32, u32);
    M2C_UNK A;
    M2C_UNK B;
    u8 b;
    u32 v;
    volatile struct { s32 sp0; u32 sp4; } stk;

    A = (M2C_UNK)data_ov001_02193d1c;
    B = M2C_FIELD(A, M2C_UNK *, 0xc0);
    b = M2C_FIELD(A, u8 *, 0x11d);
    v = M2C_FIELD(B, u32 *, 0);
    stk.sp0 = (s32)(v & 0xffU) + 0xc;
    stk.sp4 = (s32)((v & 0x01ff0000U) >> 16);
    func_ov001_0217355c(b, 3, stk.sp0, stk.sp4);
    if (stk.sp0 < 0xc0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173f30);
}

void func_ov001_02173f30(void *arg0) {
    void func_ov001_0217355c(u8, s32, s32, u32);
    void func_ov001_0218c924(void *, void *);
    u32 temp_ip;
    volatile u32 sp4;
    volatile s32 sp0;

    temp_ip = *(u32 *)M2C_FIELD(data_ov001_02193d1c, u32 **, 0x90);
    sp0 = (s32)(temp_ip & 0xff) + 0xC;
    sp4 = (temp_ip & 0x01FF0000) >> 0x10;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, sp0, sp4);
    if (sp0 < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173fa4);
}

void func_ov001_02173fa4(void *arg0) {
    void func_ov001_0218c924(void *, void *);
    void func_ov001_0217355c(u8, s32, s32, u32);
    M2C_UNK A;
    M2C_UNK B;
    u8 b;
    u32 v;
    volatile struct { s32 sp0; u32 sp4; } stk;

    A = (M2C_UNK)data_ov001_02193d1c;
    B = M2C_FIELD(A, M2C_UNK *, 0x60);
    b = M2C_FIELD(A, u8 *, 0x11d);
    v = M2C_FIELD(B, u32 *, 0);
    stk.sp0 = (s32)(v & 0xffU) + 0xc + 0;
    stk.sp4 = (s32)((v & 0x01ff0000U) >> 16);
    func_ov001_0217355c(b, 1, stk.sp0, stk.sp4);
    if (stk.sp0 < 0xc0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02174018);
}

void func_ov001_02174018(void *arg0) {
    void func_ov001_0218c924(void *, void *);
    void func_ov001_0217355c(u8, s32, s32, u32);
    M2C_UNK A;
    M2C_UNK B;
    u8 b;
    u32 v;
    volatile struct { s32 sp0; u32 sp4; } stk;

    A = (M2C_UNK)data_ov001_02193d1c;
    B = M2C_FIELD(A, M2C_UNK *, 0x30);
    b = M2C_FIELD(A, u8 *, 0x11d);
    v = M2C_FIELD(B, u32 *, 0);
    stk.sp0 = (s32)(v & 0xffU) + 0xc;
    stk.sp4 = (s32)((v & 0x01ff0000U) >> 16);
    func_ov001_0217355c(b, 0, stk.sp0, stk.sp4);
    if (stk.sp0 < 0xc0) {
        return;
    }
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

