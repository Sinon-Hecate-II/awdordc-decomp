/* 63 functions from 0x02003058 to 0x0200402C (main), found by ds-decomp. */
#include "common.h"

extern u16 data_0212dbc2;

s32 func_02003ec4(s32 *a){if(*(volatile u32 *)0x4000600&0x4000)return -1;*a=(*(volatile u32 *)0x4000600&0x1f00)>>8;return 0;}
s32 func_02003ef4(s32 *a){if(*(volatile u32 *)0x4000600&0x4000)return -1;*a=(*(volatile u32 *)0x4000600&0x2000)>>13;return 0;}
void func_02003f34(void *arg0) {
    volatile s32 *p = (volatile s32 *)arg0;
    s32 i;
    for (i = 0; i < 32; i++) {
        p[i] = 0;
    }
}

void func_02003058(s32 a){extern M2C_UNK data_0212dbc4;M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,6))&~a;M2C_FIELD(&data_0212dbc4,u16 *,6)=a;switch(a){case 0:break;case 12:*(volatile u8 *)0x4000243=0x8a;*(volatile u8 *)0x4000242=0x82;break;case 4:*(volatile u8 *)0x4000242=0x82;break;case 8:*(volatile u8 *)0x4000243=0x82;break;}func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));}

void func_02003124(s32 a){extern M2C_UNK data_0212dbc4;M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,18))&~a;M2C_FIELD(&data_0212dbc4,u16 *,18)=a;switch(a){case 0:break;case 4:*(volatile u8 *)0x4000242=0x84;break;case 0x180:*(volatile u8 *)0x4000249=0x81;case 0x80:*(volatile u8 *)0x4000248=0x81;break;}func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));}

void func_020031cc(s32 a){extern M2C_UNK data_0212dbc4;M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,20))&~a;M2C_FIELD(&data_0212dbc4,u16 *,20)=a;switch(a){case 0:break;case 8:*(volatile u8 *)0x4000243=0x84;break;case 0x100:*(volatile u8 *)0x4000249=0x82;break;}func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));}

void func_0200323c(u32 a) {
extern M2C_UNK data_0212dbc4;
M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,22))&~a;
M2C_FIELD(&data_0212dbc4,u16 *,22)=a;
if(a!=0){if(a==128){*(volatile u32 *)0x04001000|=0x40000000;*(volatile u8 *)0x04000248=130;}}else {*(volatile u32 *)0x04001000&=~0x40000000;}
func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

void func_020032bc(u32 a) {
extern M2C_UNK data_0212dbc4;
M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,24))&~a;
M2C_FIELD(&data_0212dbc4,u16 *,24)=a;
if(a!=0){if(a==256){*(volatile u32 *)0x04001000|=0x80000000;*(volatile u8 *)0x04000249=131;}}else {*(volatile u32 *)0x04001000&=~0x80000000;}
func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

s32 func_0200333c(M2C_UNK *a) {
    extern M2C_UNK data_0212dbc4;
    u16 v = M2C_FIELD(a, u16 *, 0);
    M2C_FIELD(a, u16 *, 0) = 0;
    M2C_FIELD(&data_0212dbc4, u16 *, 0) = (u16)(M2C_FIELD(&data_0212dbc4, u16 *, 0) | v);
    func_02002620((s32)v);
    return (s32)v;
}

void func_02003370(void) {
    extern M2C_UNK data_0212dbd2;
    *(s32 *)0x04000000 &= ~0x40000000;
    func_0200333c(&data_0212dbd2);
}

void func_02003394(void) {
    extern M2C_UNK data_0212dbd4;
    *(s32 *)0x04000000 &= ~0x80000000;
    func_0200333c(&data_0212dbd4);
}

void func_020033b8(void) {
    M2C_UNK func_0200333c(M2C_UNK *);
    extern M2C_UNK data_0212dbcc;
    func_0200333c(&data_0212dbcc);
}

void func_020033cc(void) {
    extern M2C_UNK data_0212dbce;
    func_0200333c(&data_0212dbce);
}

void func_020033e0(void) {
    extern M2C_UNK data_0212dbd6;
    func_0200333c(&data_0212dbd6);
}

void func_020033f4(void) {
    extern M2C_UNK data_0212dbd8;
    func_0200333c(&data_0212dbd8);
}

void func_02003408(void) {
    extern M2C_UNK data_0212dbda;
    *(s32 *)0x04001000 &= ~0x40000000;
    func_0200333c(&data_0212dbda);
}

void func_02003430(void) {
    extern M2C_UNK data_0212dbdc;
    *(s32 *)0x04001000 &= ~0x80000000;
    func_0200333c(&data_0212dbdc);
}

s32 func_02003458(M2C_UNK *a) {
    u16 v = *(u16 *)a;
    *(volatile u16 *)a = 0;
    if (v & 0x1) *(volatile u8 *)0x4000240 = 0;
    if (v & 0x2) *(volatile u8 *)0x4000241 = 0;
    if (v & 0x4) *(volatile u8 *)0x4000242 = 0;
    if (v & 0x8) *(volatile u8 *)0x4000243 = 0;
    if (v & 0x10) *(volatile u8 *)0x4000244 = 0;
    if (v & 0x20) *(volatile u8 *)0x4000245 = 0;
    if (v & 0x40) *(volatile u8 *)0x4000246 = 0;
    if (v & 0x80) *(volatile u8 *)0x4000248 = 0;
    if (v & 0x100) *(volatile u8 *)0x4000249 = 0;
    func_02007800(v & 0xffffU, data_0212dbc2);
    return v;
}

void func_02003538(void) {
    M2C_UNK func_02003458(M2C_UNK *);
    extern M2C_UNK data_0212dbc6;
    func_02003458(&data_0212dbc6);
}

void func_0200354c(void) {
    extern M2C_UNK data_0212dbc8;
    func_02003458(&data_0212dbc8);
}

void func_02003560(void) {
    extern M2C_UNK data_0212dbd2;
    *(s32 *)0x04000000 &= ~0x40000000;
    func_02003458(&data_0212dbd2);
}

void func_02003584(void) {
    extern M2C_UNK data_0212dbd4;
    *(s32 *)0x04000000 &= ~0x80000000;
    func_02003458(&data_0212dbd4);
}

void func_020035a8(void) {
    M2C_UNK func_02003458(M2C_UNK *);
    extern M2C_UNK data_0212dbcc;
    func_02003458(&data_0212dbcc);
}

void func_020035bc(void) {
    M2C_UNK func_02003458(M2C_UNK *);
    extern M2C_UNK data_0212dbce;
    func_02003458(&data_0212dbce);
}

void func_020035d0(void) {
    extern M2C_UNK data_0212dbd0;
    func_02003458(&data_0212dbd0);
}

void func_020035e4(void) {
    extern M2C_UNK data_0212dbca;
    func_02003458(&data_0212dbca);
}

void func_020035f8(void) {
    extern M2C_UNK data_0212dbc4;
    func_02003458(&data_0212dbc4);
}

void func_0200360c(void) {
    M2C_UNK func_02003458(M2C_UNK *);
    extern M2C_UNK data_0212dbd6;
    func_02003458(&data_0212dbd6);
}

void func_02003620(void) {
    M2C_UNK func_02003458(M2C_UNK *);
    extern M2C_UNK data_0212dbd8;
    func_02003458(&data_0212dbd8);
}

void func_02003634(void) {
    extern M2C_UNK data_0212dbda;
    *(s32 *)0x04001000 &= ~0x40000000;
    func_02003458(&data_0212dbda);
}

void func_0200365c(void) {
    extern M2C_UNK data_0212dbdc;
    *(s32 *)0x04001000 &= ~0x80000000;
    func_02003458(&data_0212dbdc);
}

s32 func_02003684(void){s32 b=*(volatile u16 *)0x4000008;u32 a=(*(volatile u32 *)0x4000000&0x38000000)>>27;b=(b&0x1f00)>>8;return (a<<16)+0x6000000+(b<<11);}

s32 func_020036b8(void) {
    return (((s32) (*(u16 *)0x04001008 & 0x1F00) >> 8) << 0xB) + 0x06200000;
}

s32 func_020036d8(void){s32 b=*(volatile u16 *)0x400000a;u32 a=(*(volatile u32 *)0x4000000&0x38000000)>>27;b=(b&0x1f00)>>8;return (a<<16)+0x6000000+(b<<11);}

s32 func_0200370c(void) {
    return (((s32) (*(u16 *)0x0400100A & 0x1F00) >> 8) << 0xB) + 0x06200000;
}

s32 func_0200372c(void){u32 mode=*(volatile u32 *)0x4000000&7;u32 b=*(volatile u16 *)0x400000c;u32 base=((*(volatile u32 *)0x4000000&0x38000000)>>27)<<16;u32 index=(b&0x1f00)>>8;s32 r;switch(mode){case 0:case 1:case 2:case 3:case 4:return base+0x6000000+(index<<11);case 5:if(b&0x80)r=(index<<14)+0x6000000;else r=base+0x6000000+(index<<11);return r;case 6:return 0x6000000;default:return 0;}}

s32 func_020037b0(void){u32 mode=*(volatile u32 *)0x4000000&7;u32 b=*(volatile u16 *)0x400000e;u32 base=((*(volatile u32 *)0x4000000&0x38000000)>>27)<<16;u32 index=(b&0x1f00)>>8;s32 r;switch(mode){case 0:case 1:case 2:return base+0x6000000+(index<<11);case 3:case 4:case 5:if(b&0x80)r=(index<<14)+0x6000000;else r=base+0x6000000+(index<<11);return r;case 6:return 0;default:return 0;}}

s32 func_02003834(void){s32 b=*(volatile u16 *)0x4000008;u32 a=(*(volatile u32 *)0x4000000&0x7000000)>>24;b=(b&0x3c)>>2;return (a<<16)+0x6000000+(b<<14);}

s32 func_02003868(void) {
    return (((s32) (*(u16 *)0x04001008 & 0x3C) >> 2) << 0xE) + 0x06200000;
}

s32 func_02003888(void){s32 b=*(volatile u16 *)0x400000a;u32 a=(*(volatile u32 *)0x4000000&0x7000000)>>24;b=(b&0x3c)>>2;return (a<<16)+0x6000000+(b<<14);}

s32 func_020038bc(void) {
    return (((s32) (*(u16 *)0x0400100A & 0x3C) >> 2) << 0xE) + 0x06200000;
}

s32 func_020038dc(void){s32 mode=*(volatile u32*)0x4000000&7;u32 b=*(volatile u16*)0x400000c;if(mode<5 || !(b&0x80)){u32 a=(*(volatile u32*)0x4000000&0x7000000)>>24;u32 base=(a<<16)+0x6000000;return base+(((b&0x3c)>>2)<<14);}return 0;}

s32 func_0200392c(void){s32 mode=*(volatile u32*)0x4000000&7;u32 b=*(volatile u16*)0x400000e;if(mode<3 || (mode<6 && !(b&0x80))){u32 a=(*(volatile u32*)0x4000000&0x7000000)>>24;u32 base=(a<<16)+0x6000000;return base+(((b&0x3c)>>2)<<14);}return 0;}

void func_02003984(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *arg0 = arg1 | 0x40 | (arg2 << 8) | ((arg3 | (arg4 << 8)) << 0x10);
}

void func_020039a0(void *arg0, s32 arg1, s32 arg2) {
    if (arg2 < 0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0xC0);
        M2C_FIELD(arg0, s16 *, 4) = (s16) (0 - arg2);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0x80);
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg2;
}

void func_020039c8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_FIELD(arg0, s16 *, 2) = (s16) (arg3 | (arg4 << 8));
    if (arg5 < 0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0xC0 | (arg2 << 8));
        M2C_FIELD(arg0, s16 *, 4) = (s16) (0 - arg5);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0x80 | (arg2 << 8));
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg5;
}

void func_02003a10(void *arg0, s32 arg1) {
    s32 temp_r2;
    u16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u16 *, 0);
    temp_r2 = temp_r3 & 0xC0;
    if (arg1 < 0) {
        if (temp_r2 == 0x80) {
            M2C_FIELD(arg0, u16 *, 0) = (u16) ((temp_r3 & ~0xC0) | 0xC0);
        }
        M2C_FIELD(arg0, s16 *, 4) = (s16) (0 - arg1);
        return;
    }
    if (temp_r2 == 0xC0) {
        M2C_FIELD(arg0, u16 *, 0) = (u16) ((temp_r3 & ~0xC0) | 0x80);
    }
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg1;
}

void func_02003a54(s32 a){void func_02004e44(s32);*(volatile s32 *)0x4000400=0x16;func_02004e44(a);}

void func_02003a70(s32 a) {
void func_02004e20(s32);
*(s32 *)0x04000400=0x17;
func_02004e20(a);
}

void func_02003a8c(s32 a){void func_02004e44(s32);*(s32 *)0x4000400=0x18;func_02004e44(a);}

void func_02003aa8(s32 a){void func_02004e20(s32);*(s32 *)0x4000400=0x19;func_02004e20(a);}

void func_02003ac4(void) {
void func_02003c3c(void);
void func_02003c64(void);
void func_02003e24(void);
func_02003c3c();
*(volatile u32 *)0x4000504=0;
while(*(volatile u32 *)0x4000600&0x8000000){}
*(volatile u16 *)0x4000060=0;
*(volatile u32 *)0x4000600=0;
*(volatile u32 *)0x4000010=0;
*(volatile u16 *)0x4000060|=0x2000;
*(volatile u16 *)0x4000060|=0x1000;
*(volatile u16 *)0x4000060&=0xffffcffd;
*(volatile u16 *)0x4000060=(*(volatile u16 *)0x4000060&~0x3000)|0x10;
*(volatile u16 *)0x4000060&=0xcffb;
*(volatile u32 *)0x4000600|=0x8000;
*(volatile u32 *)0x4000600=(*(volatile u32 *)0x4000600&~0xc0000000)|0x80000000;
func_02003c64();
*(volatile u32 *)0x4000350=0;
*(volatile u16 *)0x4000354=0x7fff;
*(volatile u16 *)0x4000356=0;
*(volatile u32 *)0x4000358=0;
*(volatile u16 *)0x400035c=0;
*(volatile u16 *)0x4000008&=~3;
func_02003e24();
*(volatile u32 *)0x40004a4=0x1f0080;
*(volatile u32 *)0x40004a8=0;
*(volatile u32 *)0x40004ac=0;
}

void func_02003cfc(void);
void func_02003bd0(void){
while(*(volatile u32 *)0x4000600 & 0x8000000){}
*(volatile u32 *)0x4000600 |=0x8000;
*(volatile u16 *)0x4000060 |=0x2000;
*(volatile u16 *)0x4000060 |=0x1000;
func_02003cfc();
((volatile u32 *)0x40004a4)[0]=0x1f0080;
((volatile u32 *)0x40004a4)[1]=0;
((volatile u32 *)0x40004a4)[2]=0;
}

void func_02003c3c(void){
func_02003f34(0x4000400);
while(*(volatile u32 *)0x4000600&0x8000000){
}
}


void func_02003c64(void){
s32 a,b;
*(volatile u32 *)0x4000600|=0x8000;
while(func_02003ec4(&a)){
}
while(func_02003ef4(&b)){
}
*(volatile u32 *)0x4000440=3;
*(volatile u32 *)0x4000454=0;
*(volatile u32 *)0x4000440=0;
if(b)*(volatile u32 *)0x4000448=b;
*(volatile u32 *)0x4000454=0;
*(volatile u32 *)0x4000440=2;
*(volatile u32 *)0x4000448=a;
*(volatile u32 *)0x4000454=0;
}


void func_02003cfc(void){
s32 a,b;
*(volatile u32 *)0x4000600|=0x8000;
while(func_02003ec4(&a)){
}
while(func_02003ef4(&b)){
}
*(volatile u32 *)0x4000440=3;
*(volatile u32 *)0x4000454=0;
*(volatile u32 *)0x4000440=0;
if(b)*(volatile u32 *)0x4000448=b;
*(volatile u32 *)0x4000440=2;
*(volatile u32 *)0x4000448=a;
*(volatile u32 *)0x4000454=0;
}


void func_02003d8c(s32 a,s32 b,s32 c,s32 d){if(a){*(volatile u16 *)0x400035c=d;*(volatile u16 *)0x4000060=(*(volatile u16 *)0x4000060&~0x3f40)|((c<<8)|(b<<6)|0x80);}else *(volatile u16 *)0x4000060&=0xcf7f;}

void func_02003de4(M2C_UNK arg0) {
    M2C_UNK func_02007e20(M2C_UNK, s32, M2C_UNK);
    func_02007e20(arg0, 0x04000380, 0x40);
}

void func_02003dfc(s32 arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 var_r1;

    var_r1 = arg0 | (arg1 << 0x10) | (arg3 << 0x18);
    if (arg4 != 0) {
        var_r1 |= 0x8000;
    }
    M2C_FIELD((void *)0x04000350, s32 *, 0) = var_r1;
    M2C_FIELD((void *)0x04000350, s16 *, 4) = arg2;
}

void func_02003e24(void){extern s32 data_020f5204;s32 i; if(data_020f5204!=-1){func_02007ae0(data_020f5204,0x4000330,0,16,0,0);func_02007984(data_020f5204,0x4000360,0,96);}else{func_02007e54(0,0x4000330,16);func_02007e54(0,0x4000360,96);}i=0;do{i++;*(volatile s32 *)0x40004d0=0;}while(i<32);}

void func_02003f24(s32 arg0) {
    *(s32 *)0x04000010 = arg0;
}

void func_02003fc8(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 *p){
void func_02001dac(s32,s32,s32,s32,s32,s32,s32,s32*);
s32 tmp[16];
if(!p)p=tmp;
func_02001dac(a,b,c,d,e,f,g,p);
if(!h)return;
*(volatile s32*)0x4000440=0;
func_02003a54((s32)p);
}

