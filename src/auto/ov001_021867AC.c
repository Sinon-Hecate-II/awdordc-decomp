/* 21 functions from 0x021867AC to 0x02187590 (ov001), found by ds-decomp. */
#include "common.h"
extern void *data_ov001_02193e1c;
extern void *data_ov001_02193e18;
extern const u8 data_ov001_0218fc66[], data_ov001_0218fc52[];
extern const u16 data_ov001_0218fccc[], data_ov001_0218fcce[];

void func_ov001_02186908(s32 arg0) {
s32 func_ov001_0218c884(s32,void (*)(s32),s32,s32);
void func_ov001_02186c68(s32);
M2C_FIELD(data_ov001_02193e18,s8 *,0x1b)=-1;
M2C_FIELD(data_ov001_02193e18,u16 *,0x18)++;
if(M2C_FIELD(data_ov001_02193e18,u16 *,0x18)<120U)return;
func_ov001_0218c92c(0,arg0);
M2C_FIELD(data_ov001_02193e18,s32 *,0x14)=func_ov001_0218c884(1,func_ov001_02186c68,0,120);
}

void func_ov001_02186b1c(M2C_UNK arg0,s32 arg1) {
s32 func_ov001_0218a258();
M2C_UNK func_ov001_0218a260(M2C_UNK,s32,s32,M2C_UNK);
M2C_UNK func_ov001_0218a4d4(M2C_UNK,s32,M2C_UNK *,s32 *);
M2C_UNK sp4; s32 sp0; s32 temp_r0; s32 var_r2; s32 var_r8;
temp_r0=func_ov001_0218a258();var_r8=0;if(temp_r0<=0)return;
do {func_ov001_0218a4d4(arg0,var_r8,&sp4,&sp0);
if(sp0>=arg1 && sp0<0xc0)var_r2=0;else var_r2=0x200;
func_ov001_0218a260(arg0,var_r8,var_r2,0);var_r8++;
}while(var_r8<temp_r0);
}

void func_ov001_02186ba8(s32 arg0) {
s32 func_ov001_0218a24c(s32,s32);
func_ov001_0218a55c(0,((const u8 (*)[2])data_ov001_0218fc66)[M2C_FIELD(data_ov001_02193e18,u8 *,0x1c)][arg0]+1,func_ov001_0218a24c(M2C_FIELD(data_ov001_02193e18+arg0*4,s32 *,8),0));
func_ov001_0218a384(M2C_FIELD(data_ov001_02193e18+arg0*4,s32 *,8),-1,((const u16 (*)[4])data_ov001_0218fccc)[M2C_FIELD(data_ov001_02193e18,u8 *,0x1c)][((const u8 (*)[2])data_ov001_0218fc52)[M2C_FIELD(data_ov001_02193e18,u8 *,0x1c)][arg0]*2],((const u16 (*)[4])data_ov001_0218fcce)[M2C_FIELD(data_ov001_02193e18,u8 *,0x1c)][((const u8 (*)[2])data_ov001_0218fc52)[M2C_FIELD(data_ov001_02193e18,u8 *,0x1c)][arg0]*2]);
func_ov001_0218a474(M2C_FIELD(data_ov001_02193e18+arg0*4,s32 *,8),-1,0);
}

void func_ov001_02186c68(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218c924(M2C_UNK, M2C_UNK *);
    extern void *data_ov001_02193e18;
    extern M2C_UNK func_ov001_02186ca4;
    M2C_FIELD(data_ov001_02193e18, u8 *, 0x1D) = (u8) (M2C_FIELD(data_ov001_02193e18, u8 *, 0x1D) + 1);
    if ((u32) M2C_FIELD(data_ov001_02193e18, u8 *, 0x1D) < 8U) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02186ca4);
}

void func_ov001_02186ca4(s32 a) {
extern void *data_ov001_02193e18;
void func_ov001_02186d34(); void func_ov001_02186d90();
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193e18,s32 *,0),0,&pos[1],&pos[0]);
pos[0]+=12;
func_ov001_02186974(pos[0]);
if(pos[0]<192)return;
if(M2C_FIELD(data_ov001_02193e18,u8 *,30))func_ov001_0218c924(a,func_ov001_02186d34);
else func_ov001_0218c924(a,func_ov001_02186d90);
}

void func_ov001_02186d34(s32 a) {
extern void *data_ov001_02193e18;
void func_ov001_02186d90();
M2C_FIELD(data_ov001_02193e18,s8 *,26)++;
func_02003a10(0x4000050,M2C_FIELD(data_ov001_02193e18,s8 *,26));
if(M2C_FIELD(data_ov001_02193e18,s8 *,26)>=0)func_ov001_0218c924(a,func_ov001_02186d90);
}

void func_ov001_02186d90(s32 a) {
extern void *data_ov001_02193e18; extern u8 data_ov001_0218fcfc[];
s32 i;
*(volatile u32 *)0x4000000 &= ~0xe000;
func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193e18,s32 *,0));
func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193e18,s32 *,4));
for(i=0;i<data_ov001_0218fcfc[M2C_FIELD(data_ov001_02193e18,u8 *,28)];i++) {
if(M2C_FIELD(data_ov001_02193e18,s32 *,8+4*i))func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193e18,s32 *,8+4*i));
}
func_ov001_0218ace0(M2C_FIELD(data_ov001_02193e18,s32 *,16));
func_ov001_0218c92c(1,a);
func_ov001_0218b71c(&data_ov001_02193e18);
}

void func_ov001_02186e40(void *arg0) {
    M2C_UNK func_ov001_02187ad8(void *);
    data_ov001_02193e1c = arg0;
    func_ov001_02187ad8(arg0 + 0x1B160);
    M2C_FIELD(data_ov001_02193e1c, s32 *, 0x1B140) = 0;
    M2C_FIELD(data_ov001_02193e1c, s32 *, 0x1B144) = 0;
}

void func_ov001_02186fa0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007958();
    s32 func_02017f90(M2C_UNK);
    s32 func_ov001_02186fe8(M2C_UNK);
    func_ov001_021878b4(2);
    if (func_02017f90(arg1) != 0) {
        func_ov001_021878b4(7);
        return;
    }
    if (func_ov001_02186fe8(arg0) != 0) {
        return;
    }
    func_02007958();
}

s32 func_ov001_02186fe8(M2C_UNK arg0) {
s32 func_0200ba54(void *,s32);
s32 func_02015248(void *);
s32 func_020152c8(void *,void *,s32);
s32 func_0201579c(M2C_UNK,void *);
u32 file[18];
void *p;
s32 result=0;
if(M2C_FIELD(arg0,s32 *,0)==0) p=0;
else {
func_0200b774(file);
if(!func_0200ba54(file,M2C_FIELD(arg0,s32 *,0))) return 0;
p=file;
}
if(func_02015248(p)) {
M2C_FIELD(data_ov001_02193e1c,void **,0x1b144)=(u8 *)data_ov001_02193e1c+0x2c;
if(M2C_FIELD(data_ov001_02193e1c,void **,0x1b144) &&
func_020152c8(p,M2C_FIELD(data_ov001_02193e1c,void **,0x1b144),0x10000) &&
func_0201579c(arg0,M2C_FIELD(data_ov001_02193e1c,void **,0x1b144))) result=1;
}
if(p==file)func_0200ba9c(file);
return result;
}

void func_ov001_021870bc(s32 a) {
extern void *data_ov001_02193e1c;
u16 mask; s32 state;
if(func_02013f70(a,1))return;
mask=~(1<<a);
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,8) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,10) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,12) &= mask;
func_02007530(state); func_020180c8(a);
}

void func_ov001_0218715c(s32 a) {
u16 mask; s32 state; s32 mask2;
if(!func_02013f70(a,0)) {
mask=~(1<<a);
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,8) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,10) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,12) &= mask;
func_02007530(state); func_020180c8(a);
} else {
state=func_0200751c();
mask2=~(1<<a);
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask2;
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask2;
func_02007530(state);
}
}

void func_ov001_02187234(s32 a) {
u16 mask; s32 state;
if(!func_02013f70(a,2)) {
mask=~(1<<a);
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,8) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,10) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,12) &= mask;
func_02007530(state); func_020180c8(a);
} else {
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= ~(1<<a);
M2C_FIELD(data_ov001_02193e1c,u16 *,8) |= 1<<a;
func_02007530(state);
}
}

void func_ov001_0218730c(void) {
u16 i,mask;
s32 state;
func_ov001_021878b4(3);
for(i=1;i<16;i++) {
if((M2C_FIELD(data_ov001_02193e1c,u16 *,2)&(1<<i)) && !(M2C_FIELD(data_ov001_02193e1c,u16 *,4)&(1<<i))) {
if(!(M2C_FIELD(data_ov001_02193e1c,u16 *,6)&(1<<i))) {
mask=~(1<<i);
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,8) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,10) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,12) &= mask;
func_02007530(state); func_020180c8(i);
} else func_ov001_02187234(i);
}
}
}

s32 func_ov001_021873ec(void) {
s32 func_02013f1c(u16);
u16 i;
if(M2C_FIELD(data_ov001_02193e1c,u16 *,2)==0)return 0;
for(i=1;i<16;i++){
if(M2C_FIELD(data_ov001_02193e1c,u16 *,2)&(1<<i)){
if(!func_02013f1c(i))return 0;
}
}
return 1;
}

void func_ov001_02187454(void) {
u16 i,mask,remaining=0;
s32 state,ready;
for(i=1;i<16;i++) {
if(M2C_FIELD(data_ov001_02193e1c,u16 *,10)&(1<<i)) {
if(!func_02013f70(i,3)) {
mask=~(1<<i);
state=func_0200751c();
M2C_FIELD(data_ov001_02193e1c,u16 *,2) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,4) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,6) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,8) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,10) &= mask;
M2C_FIELD(data_ov001_02193e1c,u16 *,12) &= mask;
func_02007530(state); func_020180c8(i);
} else remaining |= 1<<i;
}
}
if(remaining==0)func_ov001_021878b4(7);
else func_ov001_021878b4(4);
}

void func_ov001_0218754c(void) {
M2C_UNK func_0201808c();M2C_UNK func_ov001_021878b4(M2C_UNK);
func_ov001_021878b4(6);func_0201808c();
}

void func_ov001_02187560(void) {
    extern void *data_ov001_02193e1c;
    if ((M2C_FIELD(data_ov001_02193e1c, u16 *, 0) == 4) && (M2C_FIELD(data_ov001_02193e1c, u16 *, 2) == M2C_FIELD(data_ov001_02193e1c, u16 *, 0xC))) {
        func_0201808c();
    }
}

