/* 18 functions from 0x0218C228 to 0x0218C9B4 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { s32 a; u8 pad[4]; s32 b; u8 rest[52]; } RuntimePair64;

void func_ov001_0218c3a0(u32 arg0) {
    M2C_UNK func_ov001_0218a6f4(s32, u32);
    M2C_UNK func_ov001_0218bf4c();
    extern s32 data_ov001_02193e6c;
    s32 var_r4;

    var_r4 = 0;
    func_ov001_0218bf4c();
    if (arg0 >= (u32) (data_ov001_02193e6c + 0x1A0)) {
        var_r4 = 1;
    }
    func_ov001_0218a6f4(M2C_FIELD(((var_r4 * 0x1A0) + data_ov001_02193e6c), s32 *, 0x19C), arg0);
}

s32 func_ov001_0218c3e0(u8 *p,s32 n) {
s32 i;
for(i=0;i<n;i++) if(!p[i]) break;
return i;
}

void func_ov001_0218c40c(void) {
M2C_UNK func_02003538(void);
M2C_UNK func_0200354c(void);
M2C_UNK func_02003560(void);
M2C_UNK func_02003584(void);
M2C_UNK func_020035a8(void);
M2C_UNK func_020035bc(void);
M2C_UNK func_020035d0(void);
M2C_UNK func_0200360c(void);
M2C_UNK func_02003620(void);
M2C_UNK func_02003634(void);
M2C_UNK func_0200365c(void);
M2C_UNK func_020035e4(void);
M2C_UNK func_020035f8(void);
void func_02003058(s32);
void func_ov001_0218c5b8();
extern s32 data_ov001_02193e70[];
data_ov001_02193e70[0]=func_02003538();
data_ov001_02193e70[1]=func_0200354c();
data_ov001_02193e70[2]=func_02003560();
data_ov001_02193e70[3]=func_02003584();
data_ov001_02193e70[4]=func_020035a8();
data_ov001_02193e70[5]=func_020035bc();
data_ov001_02193e70[6]=func_020035d0();
data_ov001_02193e70[7]=func_0200360c();
data_ov001_02193e70[8]=func_02003620();
data_ov001_02193e70[9]=func_02003634();
data_ov001_02193e70[10]=func_0200365c();
data_ov001_02193e70[11]=func_020035e4();
data_ov001_02193e70[12]=func_020035f8();
func_02003058(data_ov001_02193e70[11]);
func_ov001_0218c5b8();
return;
}

void func_ov001_0218c4c0(void){extern s32 data_ov001_02193e70[];
s32 func_02003538(void);s32 func_0200354c(void);s32 func_0200360c(void);s32 func_02003620(void);void func_ov001_0218c5b8(void);void func_0200ec24(s32);
void func_020026d8(s32);
void func_02002968(s32);
void func_02002ab8(s32);
void func_02002bb8(s32);
void func_02002c64(s32);
void func_02002e3c(s32);
void func_02002f24(s32);
void func_02003124(s32);
void func_020031cc(s32);
void func_0200323c(s32);
void func_020032bc(s32);
s32 func_02003104(s32);
func_02003538();func_0200354c();func_0200360c();func_02003620();func_ov001_0218c5b8();
func_020026d8(data_ov001_02193e70[0]);
func_02002968(data_ov001_02193e70[1]);
func_02002ab8(data_ov001_02193e70[2]);
func_02002bb8(data_ov001_02193e70[3]);
func_02002c64(data_ov001_02193e70[4]);
func_02002e3c(data_ov001_02193e70[5]);
func_02002f24(data_ov001_02193e70[6]);
func_02003124(data_ov001_02193e70[7]);
func_020031cc(data_ov001_02193e70[8]);
func_0200323c(data_ov001_02193e70[9]);
func_020032bc(data_ov001_02193e70[10]);
func_02003104(data_ov001_02193e70[12]);
*(volatile u16 *)0x4000050=0;*(volatile u16 *)0x4001050=0;
*(volatile u32 *)0x4000010=0;*(volatile u32 *)0x4000014=0;*(volatile u32 *)0x4000018=0;*(volatile u32 *)0x400001c=0;
*(volatile u32 *)0x4001010=0;*(volatile u32 *)0x4001014=0;*(volatile u32 *)0x4001018=0;*(volatile u32 *)0x400101c=0;
func_0200ec24(1);
}

void func_ov001_0218c5b8(void) {
    M2C_UNK func_02003104(s32);
    M2C_UNK func_020035f8();
    M2C_UNK func_02007e98(M2C_UNK, s32, M2C_UNK);
    func_02003104(0x1F3);
    func_02007e98(0, 0x06800000, 0x40000);
    func_02007e98(0, 0x06880000, 0x24000);
    func_020035f8();
    func_02007e98(0x200, 0x07000000, 0x400);
    func_02007e98(0, 0x05000000, 0x400);
    func_02007e98(0x200, 0x07000400, 0x400);
    func_02007e98(0, 0x05000400, 0x400);
}

void func_ov001_0218c63c(void) {
    s32 func_0200ed18(s32 *);
    s32 sp0;

    if (func_0200ed18(&sp0) != 0) {
        return;
    }
    if (sp0 == 0xF) {
        return;
    }
    func_0200eca8(0xF);
}

void func_ov001_0218c668(void) {
    func_0200eca8(1);
}

void func_ov001_0218c78c(void) {
void func_ov001_0218bf30(s32);
void func_ov001_0218a6d8(s32);
void func_ov001_0218b71c(void *);
extern s32 data_ov001_02193ea4;
s32 i;
for(i=0;i!=2;i++) {
func_ov001_0218bf30(((RuntimePair64 *)data_ov001_02193ea4)[i].b);
func_ov001_0218a6d8(((RuntimePair64 *)data_ov001_02193ea4)[i].a);
}
func_ov001_0218b71c((u8 *)&data_ov001_02193ea4);
}

void func_ov001_0218c7d4(s32 n) {
s32 func_ov001_0218a74c(s32);
M2C_UNK func_ov001_0218c958();
extern s32 data_ov001_02193ea4;
void *node;
s32 i;

if(!M2C_FIELD(data_ov001_02193ea4+(n<<6),u8 *,0x38)) return;
node=M2C_FIELD(data_ov001_02193ea4+(n<<6),void **,0x10);
while(node!=(void *)(data_ov001_02193ea4+(n<<6)+0x20)) {
M2C_FIELD(node,void (**)(void *,s32),8)(node,M2C_FIELD(node,s32 *,12));
node=M2C_FIELD(node,void **,4);
}
for(i=0;i<M2C_FIELD((RuntimePair64 *)data_ov001_02193ea4+n,s32 *,0x34);i++) {
s32 p=func_ov001_0218a74c(M2C_FIELD((RuntimePair64 *)data_ov001_02193ea4+n,s32 *,4));
if(!p) return;
func_ov001_0218c958(n,p);
}
}

void func_ov001_0218c884(s32 a,s32 b,s32 c,s32 d) {
void *func_ov001_0218c898(s32,s32,s32,s32,u8);
func_ov001_0218c898(a,b,c,d,0);
}

void *func_ov001_0218c898(s32 n,s32 callback,s32 arg,s32 priority,u8 owns) {
s32 func_ov001_0218a74c(s32);
s32 func_020051f8(s32);
void func_020051c8(s32);
void func_ov001_0218bf84(void *,void *);
extern s32 data_ov001_02193ea4;
void *p;
void *q;
s32 saved;
p=(void *)func_ov001_0218a74c(M2C_FIELD(data_ov001_02193ea4+(n<<6),s32 *,0));
M2C_FIELD(p,s32 *,8)=callback;
M2C_FIELD(p,s32 *,12)=arg;
M2C_FIELD(p,u8 *,16)=priority;
M2C_FIELD(p,u8 *,17)=owns;
saved=func_020051f8(1);
q=M2C_FIELD(data_ov001_02193ea4+(n<<6),void **,16);
for(;;) {
if((u32)priority<M2C_FIELD(q,u8 *,16)) {
func_ov001_0218bf84(q,p);
break;
}
q=M2C_FIELD(q,void **,4);
}
func_020051c8(saved);
return p;
}

void func_ov001_0218c924(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

void func_ov001_0218c92c(s32 n,u32 arg) {
M2C_UNK func_ov001_0218a6f4(s32,u32);
extern s32 data_ov001_02193ea4;
func_ov001_0218a6f4(M2C_FIELD(data_ov001_02193ea4+(n<<6),s32 *,4),arg);
}

void func_ov001_0218c94c(void) {
    M2C_UNK func_ov001_0218c958();
    func_ov001_0218c958();
}

M2C_UNK func_ov001_0218c958(s32 n,void *p) {
void func_ov001_0218b71c(void *);
M2C_UNK func_ov001_0218bf4c();
M2C_UNK func_ov001_0218a6f4(s32,u32);
extern s32 data_ov001_02193ea4;
if(M2C_FIELD(p,u8 *,17)) func_ov001_0218b71c((u8 *)p+12);
func_ov001_0218bf4c(p);
func_ov001_0218a6f4(M2C_FIELD(data_ov001_02193ea4+(n<<6),s32 *,0),(u32)p);
}

void func_ov001_0218c99c(s32 arg0, s8 arg1) {
    extern s32 data_ov001_02193ea4;
    M2C_FIELD((data_ov001_02193ea4 + (arg0 << 6)), s8 *, 0x38) = arg1;
}

