/* 29 functions from 0x02224F94 to 0x02225F60 (ov010), found by ds-decomp. */
#include "common.h"
extern s16 data_ov010_0222c03c[];
extern s16 data_ov010_0222ddb4[];
extern s32 data_ov010_0222d95c[];
extern s32 data_ov010_0222d944[];

void func_ov010_02225174(void) {
 void func_ov010_02224f28(void);
 extern s32 data_ov010_0222c02c;
 s16 n;
 M2C_FIELD(&data_ov010_0222c02c,s32 *,8)=15;
 n=M2C_FIELD(&data_ov010_0222c02c,s32 *,8);
 M2C_FIELD(&data_ov010_0222c02c,s32 *,12)=n*(s16)0x44;
 func_ov010_02224f28();
}

#pragma opt_strength_reduction off
s32 func_ov010_0222519c(s16 *a,u32 bytes){
extern s32 data_ov010_0222d930;
s32 input,value,prev,square;u32 n,i;s64 sum;
input=a[0]*(s16)0xe9f;
value=(input+M2C_FIELD(&data_ov010_0222d930,s32 *,4)+M2C_FIELD(&data_ov010_0222d930,s32 *,16)*0xd3e)>>12;
square=value*value;n=bytes>>1;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
prev=-input;M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
sum=square;
for(i=1;i<n;i++){
input=a[i]*(s16)0xe9f;
prev=input+prev+value*0xd3e;
a[i-1]=value;
value=prev>>12;
square=value*value;sum+=square;prev=-input;
}
M2C_FIELD(&data_ov010_0222d930,s32 *,4)=prev;
M2C_FIELD(&data_ov010_0222d930,s32 *,16)=value;
*(s16 *)((char *)a+n*2-2)=value;
*(volatile u16 *)0x4000280=1;
*(volatile s64 *)0x4000290=sum;
*(volatile u64 *)0x4000298=n;
while(*(volatile u16 *)0x4000280&0x8000){}
return *(volatile s32 *)0x40002a0;
}
#pragma opt_strength_reduction on
void func_ov010_02225288(void) {
 extern s32 data_ov010_0222d930;
 s16 *src=data_ov010_0222c03c;
 s32 i,j;
 M2C_FIELD(&data_ov010_0222d930,s32 *,12)=0;
 M2C_FIELD(&data_ov010_0222d930,s32 *,8)=0x19D;
 for(i=0;i<0x800;i++) data_ov010_0222ddb4[i]=0;
 for(j=0;j<6;j++) {
 data_ov010_0222d95c[j]=0;
 data_ov010_0222d944[j]=src[j];
 }
}

void func_ov010_02225304(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007ef4(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov010_0222d974;
    func_02007ef4(arg0, &data_ov010_0222d974, arg1);
}

void func_ov010_02225538(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2) {
 void func_ov010_0222531c(M2C_UNK,M2C_UNK *,M2C_UNK,M2C_UNK);
 extern M2C_UNK data_ov010_0222d974;
 func_ov010_0222531c(arg0,&data_ov010_0222d974,arg1,arg2);
}

void func_ov010_02225558(s16 *a,s16 *b,s16 *out,u32 size){
u32 i; s32 v;
for(i=0;i<(size>>1);i+=4){
v=a[i+0]+b[i+0];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+0]=v;
v=a[i+1]+b[i+1];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+1]=v;
v=a[i+2]+b[i+2];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+2]=v;
v=a[i+3]+b[i+3];if(v>32767)v=32767;else if(v< -32768)v=-32768;out[i+3]=v;
}
}

void func_ov010_02225778(void) {
    M2C_UNK func_ov010_022225b0();
    M2C_UNK func_ov010_02224270();
    M2C_UNK func_ov010_02224ea0();
    extern M2C_UNK data_ov010_0222edb4;
    func_ov010_022225b0();
    func_ov010_02224270();
    func_ov010_02224ea0();
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_ov010_0222edb4, s32 *, 8) = 0;
}

void func_ov010_022257a0(void) {
extern s32 data_ov010_0222edb4;
void func_ov010_02224288(void);
s32 func_ov010_022231d4(void);
void func_ov010_02223114(void);
if(!M2C_FIELD(&data_ov010_0222edb4,s32 *,8))return;
if(!(++data_ov010_0222edb4 & 15))func_ov010_02224288();
if(func_ov010_022231d4())func_ov010_02223114();
}

s32 func_ov010_022257e4(s32 a,s32 b,s32 c) {
s32 func_ov010_02225858(s32,s32,s32,s32 *);
extern s32 data_ov010_0222edb4;
s32 out[2];
s32 result = func_ov010_02225858(a,b,c,out);
switch(result){
case 0:break;
case 1:
((void (*)(s32,s32,s32,s32))M2C_FIELD(&data_ov010_0222edb4,s32 *,16))(a,out[0],out[1],M2C_FIELD(&data_ov010_0222edb4,s32 *,20));
return 1;
case 2:return 0;
}
return 1;
}

s32 func_ov010_02225858(s32 a,s32 b,s32 c,s32 *out) {
extern s32 data_ov010_0222edb4;
u64 func_02007004(void);
void func_ov010_02222f28(s32,s32,s32,u64);
s32 func_ov010_02224334(s32,s32,s32,s32 *);
u64 now; u8 kind; s32 *state;
if(!b)return 0;
if(M2C_FIELD(b,u32*,0)!=0x5f564354)return 2;
if(!M2C_FIELD(&data_ov010_0222edb4,s32*,28)||!M2C_FIELD(&data_ov010_0222edb4,s32*,8))return 0;
out[1]=out[0]=0;
now=func_02007004();
kind=M2C_FIELD(b,u8*,4);
if((0xf0&kind)==0x40) {
state=&data_ov010_0222edb4;
state[1]=state[1]+1;
func_ov010_02222f28(a,b,c,now);
return 0;
}
if(kind==0||kind==255) return func_ov010_02224334(a,b,c,out)!=0;
return 0;
}

void func_ov010_02225934(void) {
 extern s32 data_ov010_0222edd8;
 M2C_FIELD(&data_ov010_0222edd8,s32 *,0x10)=1;
}

void func_ov010_02225948(void) {
void func_ov010_02224f28(void);
extern s32 data_ov010_0222edd8;
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222edd8,s32 *,16)=0;
}

void func_ov010_02225cd8(void) {
    M2C_UNK func_ov010_02225aa4(M2C_UNK *, M2C_UNK);
    extern M2C_UNK func_ov010_02225964;
    func_ov010_02225aa4(&func_ov010_02225964, 0x44);
}

s32 func_ov010_02225cf0(void) {
    extern s32 data_ov010_0222edd8;
    return data_ov010_0222edd8;
}

void func_ov010_02225d00(void) {
extern s32 data_ov010_0222ee14;
void func_0202b70c(void *);
void func_0202a9f0(void);
void func_02004e60(s32,s32);
s32 i;
func_0202b70c(&data_ov010_0222ee14);
for(i=0;i<4;i++){func_0202a9f0();func_02004e60(1,1);}
}

void func_ov010_02225d38(void) {
    M2C_UNK func_0200df70();
    extern M2C_UNK data_ov010_0222ee14;
    func_0200df70();
    func_0202b760(&data_ov010_0222ee14);
}

void func_ov010_02225d50(void) {
extern s32 data_ov010_0222edd8;
M2C_FIELD(&data_ov010_0222edd8,s32 *,4)=1;
}

void func_ov010_02225d64(void) {
extern s32 data_ov010_0222edd8;
void func_0200df14(void (*)(void),s32);
func_0200df14(func_ov010_02225948,0);
M2C_FIELD(&data_ov010_0222edd8,s32 *,4)=0;
}

s32 func_ov010_02225d8c(void) {
    extern M2C_UNK data_ov010_0222edd8;
    return M2C_FIELD(&data_ov010_0222edd8, s32 *, 0x10);
}

s32 func_ov010_02225d9c(void) {
void func_ov010_02224f74(s32 *);
s32 out[4];func_ov010_02224f74(out);return out[0];
}

void func_ov010_02225db8(void) {
extern s32 data_ov010_0222ee14;
extern s32 data_ov010_0222edd8;
void func_0202b544(void *);
void func_ov010_02226100(s32,s32);
void func_0200e868(s32);
func_0202b760(&data_ov010_0222ee14);
func_0202b544(&data_ov010_0222ee14);
func_ov010_02226100(M2C_FIELD(&data_ov010_0222edd8,s32 *,12),M2C_FIELD(&data_ov010_0222edd8,s32 *,24));
M2C_FIELD(&data_ov010_0222edd8,s32 *,12)=0;
func_ov010_02226100(M2C_FIELD(&data_ov010_0222edd8,s32 *,28),M2C_FIELD(&data_ov010_0222edd8,s32 *,20));
M2C_FIELD(&data_ov010_0222edd8,s32 *,28)=0;
func_0200e868(0);
}

void func_ov010_02225e10(s32 a) {
extern s32 data_ov010_0222ee70;
void func_ov010_022226fc(s32);
void func_ov010_02223ef0(s32);
if(a==M2C_FIELD(&data_ov010_0222ee70,s32 *,4)){
func_ov010_022226fc(a);
func_ov010_02223ef0(a);
M2C_FIELD(&data_ov010_0222ee70,s32 *,4)=0;
}else func_ov010_02223ef0(a);
}

void func_ov010_02225f54(void) {
    M2C_UNK func_ov010_022257e4();
    func_ov010_022257e4();
}
