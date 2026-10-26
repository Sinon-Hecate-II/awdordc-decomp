/* 40 functions from 0x0218B368 to 0x0218C228 (ov001), found by ds-decomp. */
#include "common.h"
void func_020051c8(s32);
extern s32 data_ov001_02193e6c;

typedef struct ListLink { struct ListLink *prev; struct ListLink *next; } ListLink;
extern s32 data_ov001_02193e60[2];

typedef struct TouchFlags {
    u8 active : 1;
    u8 pressed : 1;
    u8 released : 1;
    u8 unused : 5;
} TouchFlags;

void func_ov001_0218b368(s32 a,s32 b){
if(a==1){volatile u32 *p=(volatile u32 *)0x04001000;u32 t=*p&0x1f00;*p=(*p&~0x1f00)|((~b&(t>>8))<<8);return;}
{volatile u32 *p=(volatile u32 *)0x04000000;u32 t=*p&0x1f00;*p=(*p&~0x1f00)|((~b&(t>>8))<<8);}
}

void func_ov001_0218b648(s32 a){
M2C_UNK func_02007f8c(s32,M2C_UNK,M2C_UNK);
s32 func_0202a424(s32,s32,s32);void func_02007958(void);extern s32 data_ov001_02193e44;
func_02007f8c(a,0,0x40000);data_ov001_02193e44=func_0202a424(a,0x40000,0);
if(data_ov001_02193e44==0)func_02007958();
}

void func_ov001_0218b688(void) {
    M2C_UNK func_0202a45c(s32);
    extern s32 data_ov001_02193e44;
    func_0202a45c(data_ov001_02193e44);
    data_ov001_02193e44 = 0;
}

s32 func_ov001_0218b6ac(s32 a,s32 b){
s32 func_020051f8(s32);void func_020051c8(s32);s32 func_0202a468(s32,s32,s32);void func_02007958(void);extern s32 data_ov001_02193e44;s32 result,saved;
saved=func_020051f8(1);result=func_0202a468(data_ov001_02193e44,a,b);
if(!result)func_02007958();func_020051c8(saved);return result;
}

s32 func_ov001_0218b6f8(M2C_UNK arg0) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    s32 func_ov001_0218b6ac();
    s32 temp_r0;

    temp_r0 = func_ov001_0218b6ac();
    func_02007f8c(temp_r0, 0, arg0);
    return temp_r0;
}

s32 func_ov001_0218b71c(s32 *p) {
s32 func_020051f8(s32);
extern s32 data_ov001_02193e44;
s32 saved=func_020051f8(1);
if(*p==0)return saved;
func_0202a498(data_ov001_02193e44,*p);
func_020051c8(saved);
*p=0;
return 0;
}

void func_ov001_0218b760(s32 a) {
s32 func_020051f8(s32);
extern s32 data_ov001_02193e44;
s32 saved=func_020051f8(1);
if(a==0)return;
func_0202a498(data_ov001_02193e44,a);
func_020051c8(saved);
}

void func_ov001_0218b850(void);
void func_ov001_0218b79c(void) {
extern M2C_UNK data_ov001_02193e48;
s32 buf[2];
M2C_FIELD(&data_ov001_02193e48,s32 *,4)=((s32 (*)())func_ov001_0218b6f8)(0x3a,4);
if(func_0200d5bc(buf)==0)func_02007958();
func_0200d650(buf);
func_0200d85c(0,4,M2C_FIELD(&data_ov001_02193e48,s32 *,4),5);
func_0200dd14(2);
if(func_0200dd2c(2)!=0)func_02007958();
func_ov001_0218b850();
}

void func_ov001_0218b818(void) {
    M2C_UNK func_0200d95c();
    M2C_UNK func_0200dd14(M2C_UNK);
    s32 func_0200dd2c(M2C_UNK);
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193e4c;
    do {
        func_0200d95c();
        func_0200dd14(4);
    } while (func_0200dd2c(4) != 0);
    func_ov001_0218b71c(&data_ov001_02193e4c);
}

void func_ov001_0218b850(void) {
    M2C_UNK func_ov001_0218b964();
    M2C_UNK func_ov001_0218b860();
    func_ov001_0218b860();
    func_ov001_0218b964();
}

s32 func_ov001_0218bb00(s32 arg0) {
    extern M2C_UNK data_ov001_02193e48;
    if (arg0 == (arg0 & M2C_FIELD(M2C_FIELD(&data_ov001_02193e48, void **, 4), u16 *, 0x32))) {
        return 1;
    }
    return 0;
}

s32 func_ov001_0218bb24(s32 a) {
extern M2C_UNK data_ov001_02193e48;
return a==(a&M2C_FIELD(M2C_FIELD(&data_ov001_02193e48,void **,4),u16 *,0x34));
}

s32 func_ov001_0218bb48(s32 a){extern M2C_UNK data_ov001_02193e48;return a==(a&M2C_FIELD(M2C_FIELD(&data_ov001_02193e48,void **,4),u16 *,0x36));}

s32 func_ov001_0218bb6c(u16 *a){extern M2C_UNK data_ov001_02193e48;void *p=M2C_FIELD(&data_ov001_02193e48,void **,4);
if(M2C_FIELD(p,TouchFlags *,0x38).active==0)return 0;
if(a[0]>M2C_FIELD(p,u16 *,0x28))return 0;
if(a[2]<M2C_FIELD(p,u16 *,0x28))return 0;
if(a[1]>M2C_FIELD(p,u16 *,0x2a))return 0;
return a[3]>=M2C_FIELD(p,u16 *,0x2a);
}

s32 func_ov001_0218bbd8(u16 *a){extern M2C_UNK data_ov001_02193e48;void *p=M2C_FIELD(&data_ov001_02193e48,void **,4);u32 x=M2C_FIELD(p,u8 *,0x38);
if((x<<30>>31)==0)return 0;
if(a[0]>M2C_FIELD(p,u16 *,0x28))return 0;
if(a[2]<M2C_FIELD(p,u16 *,0x28))return 0;
if(a[1]>M2C_FIELD(p,u16 *,0x2a))return 0;
return a[3]>=M2C_FIELD(p,u16 *,0x2a);
}

s32 func_ov001_0218bc44(u16 *a){extern M2C_UNK data_ov001_02193e48;void *p=M2C_FIELD(&data_ov001_02193e48,void **,4);u32 x=M2C_FIELD(p,u8 *,0x38);
if((x<<29>>31)==0)return 0;
if(a[0]>M2C_FIELD(p,u16 *,0x28))return 0;
if(a[2]<M2C_FIELD(p,u16 *,0x28))return 0;
if(a[1]>M2C_FIELD(p,u16 *,0x2a))return 0;
return a[3]>=M2C_FIELD(p,u16 *,0x2a);
}

s32 func_ov001_0218bcb0(u16 *a){extern M2C_UNK data_ov001_02193e48;void *p=M2C_FIELD(&data_ov001_02193e48,void **,4);u32 x=M2C_FIELD(p,u8 *,0x38);
if((x<<28>>31)==0)return 0;
if(a[0]>M2C_FIELD(p,u16 *,0x28))return 0;
if(a[2]<M2C_FIELD(p,u16 *,0x28))return 0;
if(a[1]>M2C_FIELD(p,u16 *,0x2a))return 0;
return a[3]>=M2C_FIELD(p,u16 *,0x2a);
}

s32 func_ov001_0218bd1c(u16 *a){u16 box[4];box[0]=a[0];box[1]=a[1];box[2]=a[0]+a[2];box[3]=a[1]+a[3];return func_ov001_0218bbd8(box);}

s32 func_ov001_0218bd64(u16 *a){extern M2C_UNK data_ov001_02193e48;void *p=M2C_FIELD(&data_ov001_02193e48,void **,4);u16 x,y;
if(!M2C_FIELD(p,TouchFlags *,0x38).active){x=M2C_FIELD(p,volatile u16 *,0x2c);y=M2C_FIELD(p,volatile u16 *,0x2e);a[0]=x;a[1]=y;return 0;}
x=M2C_FIELD(p,volatile u16 *,0x28);y=M2C_FIELD(p,volatile u16 *,0x2a);a[0]=x;a[1]=y;return 1;
}

void func_ov001_0218bdb0(void) {
extern M2C_UNK data_ov001_02193e48;
if(M2C_FIELD(&data_ov001_02193e48,u8 *,0)){
if(((*(volatile u16 *)0x027fffa8)&0x8000)>>15)return;
if(func_0200ec24(1))M2C_FIELD(&data_ov001_02193e48,u8 *,0)=0;
}else{
if(!(((*(volatile u16 *)0x027fffa8)&0x8000)>>15))return;
if(func_0200ec24(0))M2C_FIELD(&data_ov001_02193e48,u8 *,0)=1;
}
}

void func_ov001_0218bedc(void);
void func_ov001_0218be2c(void) {
data_ov001_02193e60[1]=*(volatile u32 *)0x04000210;
func_0200519c(0x40018);func_020051c8(1);
data_ov001_02193e60[0]=func_02005080(1);
func_02004ff8(1,func_ov001_0218bedc);func_02005228(1);
{u16 old=*(volatile u16 *)0x04000208;*(volatile u16 *)0x04000208=1;func_02007508(1,old);}
}

void func_ov001_0218bea0(void) {
(void)*(volatile u16 *)0x04000208;
*(volatile u16 *)0x04000208=0;
func_0200519c(data_ov001_02193e60[1]);
func_02004ff8(1,data_ov001_02193e60[0]);
}

void func_ov001_0218bedc(void) {
    M2C_UNK func_ov001_0218c7d4(M2C_UNK);
    extern M2C_UNK data_027e0000;
    func_ov001_0218c7d4(1);
    M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) = (s32) (M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) | 1);
}

s32 func_ov001_0218bf04(void){s32 p=((s32 (*)(s32,s32))func_ov001_0218b6f8)(16,4);
M2C_FIELD(p,s32 *,0)=0;M2C_FIELD(p,s32 *,4)=p+8;M2C_FIELD(p,s32 *,8)=p;M2C_FIELD(p,s32 *,12)=0;return p;}

void func_ov001_0218bf30(s32 arg0, ...) {
 M2C_UNK func_ov001_0218b71c(M2C_UNK *);
 func_ov001_0218b71c(&arg0);
}

void func_ov001_0218bf4c(ListLink *node){s32 func_020051f8(s32);void func_020051c8(s32);s32 state=func_020051f8(1);node->prev->next=node->next;node->next->prev=node->prev;node->next=0;node->prev=0;func_020051c8(state);}

M2C_UNK func_ov001_0218bf84(a,b)
s32 a; s32 b;{s32 func_020051f8(s32);s32 state=func_020051f8(1);ListLink *head=(ListLink *)a,*node=(ListLink *)b;head->prev->next=node;node->prev=head->prev;node->next=head;head->prev=node;func_020051c8(state);}

void func_ov001_0218bfb4(s32 arg0) {
    func_ov001_0218bf84(arg0 + 8);
}

void func_ov001_0218bfc4(void *arg0) {
    M2C_UNK func_ov001_0218bf84();
    func_ov001_0218bf84(M2C_FIELD(arg0, s32 *, 4));
}

void func_ov001_0218bfd4(void){
void func_ov001_0218c070(void);
extern s32 data_ov001_02193e68;void func_02007e98(s32,s32,s32);s32 func_ov001_0218a698(s32,s32,s32);s32 func_ov001_0218c884(s32,void (*)(void),s32,s32);
s32 i,offset; s32 p=((s32 (*)(s32,s32))func_ov001_0218b6f8)(0x80c,4);data_ov001_02193e68=p;func_02007e98(0x200,p,0x800);
for(i=0,offset=0;i<2;i++){s32 result=func_ov001_0218a698(0x40,data_ov001_02193e68+offset,8);offset+=0x400;((s32 *)data_ov001_02193e68)[i+0x200]=result;}
M2C_FIELD(data_ov001_02193e68,s32 *,0x808)=func_ov001_0218c884(1,func_ov001_0218c070,0,200);
}

void func_ov001_0218c070(void){
extern s32 data_ov001_02193e68;void func_020067e0(s32,s32);void func_02004210(s32,s32,s32);void func_02004264(s32,s32,s32);
func_020067e0(data_ov001_02193e68,0x800);func_02004210(data_ov001_02193e68,0,0x400);func_02004264(data_ov001_02193e68+0x400,0,0x400);
}

void func_ov001_0218c0b8(void) {
extern s32 data_ov001_02193e68;
func_ov001_0218c94c(1,((s32 *)data_ov001_02193e68)[0x202]);
func_ov001_0218b71c((s32 *)&data_ov001_02193e68);
}

void func_ov001_0218c0e4(s32 n){
extern s32 data_ov001_02193e68; void func_ov001_0218a74c(s32);
func_ov001_0218a74c(M2C_FIELD(data_ov001_02193e68+(n<<2),s32 *,0x800));
}

void func_ov001_0218c104(u32 *p){
extern s32 data_ov001_02193e68;
void func_ov001_0218a6f4(s32,void *);
s32 i=0;
*p=(*p&0xc1fffcff)|0x200;
if((u32)p>=(u32)(data_ov001_02193e68+0x400))i=1;
func_ov001_0218a6f4(M2C_FIELD(data_ov001_02193e68+(i<<2),s32 *,0x800),p);
}

s32 func_ov001_0218c150(s32 arg0, s32 arg1) {
    extern s32 data_ov001_02193e68;
    return data_ov001_02193e68 + (arg0 << 0xA) + (arg1 * 8);
}

void func_ov001_0218c168(void){
s32 i;
data_ov001_02193e6c=((s32 (*)(s32,s32))func_ov001_0218b6f8)(0x340,4);
for(i=0;i<2;i++){
M2C_FIELD(data_ov001_02193e6c+i*0x1a0,s32 *,0x19c)=func_ov001_0218a698(0x20,data_ov001_02193e6c+i*0x1a0,12);
M2C_FIELD(data_ov001_02193e6c+i*0x1a0,s32 *,0x198)=func_ov001_0218bf04();
M2C_FIELD(data_ov001_02193e6c+i*0x1a0,u16 *,0x188)=0x300;
M2C_FIELD(data_ov001_02193e6c+i*0x1a0,u16 *,0x194)=0x400;
((void (*)(s32,s32))func_ov001_0218bfc4)(M2C_FIELD(data_ov001_02193e6c+i*0x1a0,s32 *,0x198),data_ov001_02193e6c+i*0x1a0+0x180);
((void (*)(s32,s32))func_ov001_0218bfb4)(M2C_FIELD(data_ov001_02193e6c+i*0x1a0,s32 *,0x198),data_ov001_02193e6c+i*0x1a0+0x18c);
}
}

