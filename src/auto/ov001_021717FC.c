/* 30 functions from 0x021717FC to 0x021724C0 (ov001), found by ds-decomp. */
#include "common.h"
extern s32 data_ov001_02193d14;
extern u8 data_ov001_021900e4[];
extern u8 *data_ov001_02190094[];
extern void *data_ov001_02193d18;
extern const u8 data_ov001_0218f30c[];
void func_ov001_02172418(s32);
s32 func_ov001_0218c884(s32,void (*)(s32),s32,s32);
extern s32 data_ov001_02193d10;
extern s8 data_ov001_02193ccc;
extern u8 data_ov001_02193cd0[64];
extern const u8 data_ov001_0218f2f8[8];

void func_ov001_021717fc(s32 a){
extern void *data_ov001_02193cc8;
void func_ov001_02171868(s32);
void func_ov001_0218a4d4(s32,s32,s32 *,s32 *);
void func_ov001_02171768(s32);
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193cc8,s32 *,8),0,&pos[1],&pos[0]);
pos[0]-=4;func_ov001_02171768(pos[0]);
if(pos[0]>168)return;
func_ov001_02171768(168);func_ov001_0218c924(a,(M2C_UNK *)func_ov001_02171868);
}

void func_ov001_02171868(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218c924(M2C_UNK, M2C_UNK *);
    extern void *data_ov001_02193cc8;
    extern M2C_UNK func_ov001_021718b8;
    M2C_FIELD(data_ov001_02193cc8, s8 *, 0x16) = -1;
    M2C_FIELD(data_ov001_02193cc8, u16 *, 0x14) = (u16) (M2C_FIELD(data_ov001_02193cc8, u16 *, 0x14) + 1);
    if ((u32) M2C_FIELD(data_ov001_02193cc8, u16 *, 0x14) < 4U) {
        return;
    }
    M2C_FIELD(data_ov001_02193cc8, u16 *, 0x14) = 0U;
    func_ov001_0218c924(arg0, &func_ov001_021718b8);
}

void func_ov001_021718b8(void){
extern void *data_ov001_02193cc8;
extern const u8 data_ov001_0218f2a8[],data_ov001_0218f29a[][2],data_ov001_0218f280[],data_ov001_0218f28c[][2];
extern const u16 data_ov001_0218f284[],data_ov001_0218f286[];
void func_ov001_0218b2e0(const void *,const void *,void *);s32 func_ov001_0218bbd8(void *);
void func_ov001_0218a384(s32,s32,s32,s32);s32 func_ov001_0218a24c(s32,s32);void func_ov001_0218a55c(s32,s32,s32);void func_ov001_0218a474(s32,s32,s32);void func_ov001_02171b20(s32);
s32 n,i,t;u8 point[8];
n=data_ov001_0218f2a8[M2C_FIELD(data_ov001_02193cc8,u8 *,23)];
if(M2C_FIELD(data_ov001_02193cc8,u8 *,24)==0){
if(M2C_FIELD(data_ov001_02193cc8,s8 *,22)!=-1)return;
for(i=0;i<n;i++){
func_ov001_0218b2e0((const u8 *)data_ov001_0218f284+data_ov001_0218f29a[M2C_FIELD(data_ov001_02193cc8,u8 *,23)][i]*4,data_ov001_0218f280,point);
if(func_ov001_0218bbd8(point)){
if(M2C_FIELD(data_ov001_02193cc8,s32 *,16))break;
t=data_ov001_0218f28c[M2C_FIELD(data_ov001_02193cc8,u8 *,23)][i];
func_ov001_0218a55c(0,t+1,func_ov001_0218a24c(((s32 *)data_ov001_02193cc8)[i],0));
t=data_ov001_0218f29a[M2C_FIELD(data_ov001_02193cc8,u8 *,23)][i];
func_ov001_0218a384(((s32 *)data_ov001_02193cc8)[i],-1,*(const u16 *)((const u8 *)data_ov001_0218f284+t*4),*(const u16 *)((const u8 *)data_ov001_0218f286+t*4));
func_ov001_0218a474(((s32 *)data_ov001_02193cc8)[i],-1,1);
M2C_FIELD(data_ov001_02193cc8,s32 *,16)=func_ov001_0218c884(0,func_ov001_02171b20,0,110);
M2C_FIELD(data_ov001_02193cc8,s8 *,22)=i;
return;
}
}
}
M2C_FIELD(data_ov001_02193cc8,s8 *,22)=-1;
}

void func_ov001_02171a44(s32 a){
extern void *data_ov001_02193cc8;
void func_ov001_02171aa8(s32);
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193cc8,s32 *,8),0,&pos[1],&pos[0]);
pos[0]+=4;func_ov001_02171768(pos[0]);
if(pos[0]<192)return;
func_ov001_0218c924(a,(M2C_UNK *)func_ov001_02171aa8);
}

void func_ov001_02171aa8(s32 a){
extern void *data_ov001_02193cc8;
void func_ov001_0218c92c(s32,s32);
void func_ov001_0218a1cc(s32);
s32 i;
func_ov001_0218c92c(0,a);
if(M2C_FIELD(data_ov001_02193cc8,s32 *,16))func_ov001_0218c92c(0,M2C_FIELD(data_ov001_02193cc8,s32 *,16));
for(i=0;i<2;i++)if(((s32 *)data_ov001_02193cc8)[i])func_ov001_0218a1cc(((s32 *)data_ov001_02193cc8)[i]);
func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193cc8,s32 *,8));
func_ov001_0218b71c((M2C_UNK *)&data_ov001_02193cc8);
}

void func_ov001_02171b20(s32 a){
extern void *data_ov001_02193cc8;extern const u8 data_ov001_0218f2a8[],data_ov001_0218f28c[][2];
s32 func_ov001_0218a24c(s32,s32);void func_ov001_0218a55c(s32,s32,s32);void func_ov001_0218a474(s32,s32,s32);
void func_ov001_0218c92c(s32,s32);
s32 n,i,t;
M2C_FIELD(data_ov001_02193cc8,u16 *,20)++;
if(M2C_FIELD(data_ov001_02193cc8,u16 *,20)<16U)return;
n=data_ov001_0218f2a8[M2C_FIELD(data_ov001_02193cc8,u8 *,23)];
for(i=0;i<n;i++){
t=data_ov001_0218f28c[M2C_FIELD(data_ov001_02193cc8,u8 *,23)][i];
func_ov001_0218a55c(0,t,func_ov001_0218a24c(((s32*)data_ov001_02193cc8)[i],0));
func_ov001_0218a474(((s32*)data_ov001_02193cc8)[i],-1,1);
}
func_ov001_02171768(168);
M2C_FIELD(data_ov001_02193cc8,u16 *,20)=0;
M2C_FIELD(data_ov001_02193cc8,s8 *,22)=-1;
if(M2C_FIELD(data_ov001_02193cc8,s32 *,16)){M2C_FIELD(data_ov001_02193cc8,s32 *,16)=0;func_ov001_0218c92c(0,a);}
}

void func_ov001_02171c10(void) {
    extern s8 data_ov001_02193ccc;
    data_ov001_02193ccc = 0;
}

s32 func_ov001_02171c24(s32 a,s32 b,s32 c){
extern u8 data_ov001_0218feb0[];extern s32 data_ov001_02193d58;void func_0200436c(s32,s32,s32);
void func_ov001_02171d90(u8 *,void (*)(s32,s32,s32));s32 func_ov001_0218ad0c(s32,s32);s32 func_ov001_02175f60(s32,s32,s32,s32);s32 func_ov001_02171f88(void);s32 func_ov001_0218b12c(s32,s32,s32,s32,s32,s32,s32,s32);s32 func_ov001_0218b298(s32);
s32 p,t;
if(*(u8 *)&data_ov001_02193ccc)return 0;
func_ov001_02171d90(data_ov001_0218feb0,func_0200436c);
*(volatile u32 *)0x4001010=0x1920000;
p=func_ov001_0218ad0c(1,0);t=func_ov001_02175f60(data_ov001_02193d58,a,b,c);
func_ov001_0218b12c(p,20,0,216,64,2,func_ov001_02171f88(),t);func_ov001_0218b298(p);
data_ov001_02193ccc=1;return 1;
}

s32 func_ov001_02171cf8(void) {
 void func_ov001_0218af70(s32);
 if((u8)data_ov001_02193ccc==0) return 0;
 func_ov001_0218af70(1);
 data_ov001_02193ccc=0;
 return 1;
}

void *func_ov001_02171d30(u8 *arg0) {
 void func_02068d18(void *,void *,s32);
 s32 func_ov001_02175ddc(s32);
 s32 value;
 func_02068d18(data_ov001_02193cd0,arg0,63);
 if(arg0[5]==120) return data_ov001_02193cd0;
 value=func_ov001_02175ddc(arg0[5]);
 if(arg0[5]==121 && value!=0) return data_ov001_02193cd0;
 data_ov001_02193cd0[5]=data_ov001_0218f2f8[value];
 return data_ov001_02193cd0;
}

void func_ov001_02171d90(u8 *arg0,void (*arg1)(s32,s32,s32)) {
 void func_020067e0(s32,s32);
 s32 func_ov001_02189dc8(void *,s32 *,s32);
 void func_ov001_02189ebc(s32);
 s32 size;
 s32 p=func_ov001_02189dc8(func_ov001_02171d30(arg0),&size,4);
 func_020067e0(p,size);
 arg1(p,0,size);
 func_ov001_02189ebc(p);
}

void func_ov001_02171dd0(s32 a){
s32 x;func_ov001_02175d78(&x,0);
if(x==1){func_ov001_021850b8(a);return;}
if(x==2)func_ov001_0218564c(a);
}

void func_ov001_02171e20(M2C_UNK arg0) {
    M2C_UNK func_ov001_0217159c(M2C_UNK);
    M2C_UNK func_ov001_02175d78(M2C_UNK, s32 *);
    s32 sp0;

    func_ov001_02175d78(0, &sp0);
    if (sp0 != 1) {
        return;
    }
    func_ov001_0217159c(arg0);
}

void func_ov001_02171e58(M2C_UNK arg0) {
    s32 func_ov001_02171f88();
    s32 func_ov001_02175f48(s32, M2C_UNK);
    s32 func_ov001_0218ad0c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b12c(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK func_ov001_0218b298(s32);
    extern s32 data_ov001_02193d58;
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = func_ov001_0218ad0c(0, 0);
    temp_r4 = func_ov001_02175f48(data_ov001_02193d58, arg0);
    func_ov001_0218b12c(temp_r5, 0xD, 0x28, 0xE6, 0x70, 2, func_ov001_02171f88(), temp_r4);
    func_ov001_0218b298(temp_r5);
}

void func_ov001_02171ecc(s32 a,s32 b){
extern s32 data_ov001_02193d58;
s32 func_ov001_02175ddc(s32);
extern u16 data_ov001_0218f2de[],data_ov001_0218f2dc[];

void func_ov001_0218af94(s32,s32,s32,s32,s32,s32);
s32 p,t,x,y;
p=func_ov001_0218ad0c(0,0);t=func_ov001_02175f48(data_ov001_02193d58,b);
func_ov001_0218b12c(p,13,60,230,94,2,func_ov001_02171f88(),t);
x=((s32 (*)(void))func_ov001_02175ddc)();y=((s32 (*)(void))func_ov001_02175ddc)();
func_ov001_0218af94(p,data_ov001_0218f2dc[x*2],data_ov001_0218f2de[y*2],2,0x209,a);
func_ov001_0218b298(p);
}

s32 func_ov001_02171f88(void) {
    s32 func_ov001_02175ddc(s32);
    extern s32 data_ov001_0218f2c0[];
    s32 index = ((s32 (*)(void))func_ov001_02175ddc)();
    return data_ov001_0218f2c0[index];
}

void func_ov001_02171fa0(void) {
 s32 func_ov001_0218b6f8(s32,s32);
 data_ov001_02193d10=func_ov001_0218b6f8(16,4);
}

void func_ov001_02171fc0(void) {
    M2C_UNK func_ov001_02172184();
    extern M2C_UNK data_ov001_02193d10;
    func_ov001_02172184();
    func_ov001_0218b71c(&data_ov001_02193d10);
}

void func_ov001_02171fd8(s32 a,s32 b,s32 c,s32 d){
extern u8 data_ov001_0218f300[];
extern s32 data_ov001_02193d10;
s32 func_ov001_0218a61c(s32,s32,s32);
void func_ov001_0218a474(s32,s32,s32);
void func_ov001_0218a384(s32,s32,s32,s32);
s32 i;u8 *p;
func_ov001_02172184();
p=&data_ov001_0218f300[a*2];
for(i=0;i<2;i++){
((s32 *)data_ov001_02193d10)[i]=func_ov001_0218a61c(0,*p++,1);
func_ov001_0218a474(((s32 *)data_ov001_02193d10)[i],-1,1);
}
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[0],-1,b,d);
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[1],-1,c,d);
}

void func_ov001_02172094(s32 a,s32 b,s32 c,s32 d){
extern s32 data_ov001_02193d10;
s32 func_ov001_0218a61c(s32,s32,s32);void func_ov001_0218a474(s32,s32,s32);void func_ov001_0218a384(s32,s32,s32,s32);
s32 j=6,i;func_ov001_02172184();
for(i=0;i<4;i++,j++){
((s32 *)data_ov001_02193d10)[i]=func_ov001_0218a61c(0,j,1);
func_ov001_0218a474(((s32 *)data_ov001_02193d10)[i],-1,1);
}
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[0],-1,a,c);
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[1],-1,b,c);
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[2],-1,a,d);
func_ov001_0218a384(((s32 *)data_ov001_02193d10)[3],-1,b,d);
}

void func_ov001_021721c4(void) {
 void func_0200460c(s32,s32,s32);
 void func_020043cc(s32,s32,s32);
 s32 func_ov001_02175dec(void);
 data_ov001_02193d14=func_ov001_0218b6f8(192,4);
 func_ov001_02171d90(data_ov001_021900e4,func_0200460c);
 switch(func_ov001_02175dec()) {
 case 0: func_ov001_02171d90(data_ov001_02190094[0],func_020043cc); return;
 case 1: func_ov001_02171d90(data_ov001_02190094[1],func_020043cc); return;
 }
}

void func_ov001_0217223c(void) {
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193d14;
    func_ov001_0218b71c(&data_ov001_02193d14);
}

void func_ov001_021722dc(s32);
M2C_UNK func_ov001_02172250(s32 a) {
 void func_02007ef4(s32,s32,s32);
 s32 p=func_ov001_02189dc8(func_ov001_02171d30(data_ov001_02190094[a]),0,4);
 func_02007ef4(p,data_ov001_02193d14,192);
 func_ov001_02189ebc(p);
 func_ov001_0218c884(1,func_ov001_021722dc,0,120);
}

void func_ov001_021722ac(void) {
    M2C_UNK func_ov001_02172250(s32);
    void *func_ov001_0218445c();
    func_ov001_02172250(M2C_FIELD(func_ov001_0218445c(), u8 *, 0xF4) + 5);
}

void func_ov001_021722c4(void) {
    func_ov001_02172250(M2C_FIELD(func_ov001_0218445c(), u8 *, 0xF4) + 2);
}

void func_ov001_021722dc(s32 a) {
 void func_020043cc(s32,s32,s32);
 void func_ov001_0218c92c(s32,s32);
 func_020067e0(data_ov001_02193d14,192);
 func_020043cc(data_ov001_02193d14,0,192);
 func_ov001_0218c92c(1,a);
}

void func_ov001_0217231c(s8 a) {
 s32 *func_ov001_0218a5f0(s32,u8);
 s32 *p;
 s32 *q;
 void *v;
 if(data_ov001_02193d18!=NULL) return;
 v=(void *)func_ov001_0218b6f8(12,4);
 data_ov001_02193d18=v;
 M2C_FIELD(v,s8 *,8)=a;
 M2C_FIELD(data_ov001_02193d18,s32 **,0)=func_ov001_0218a5f0(0,data_ov001_0218f30c[a*4]);
 p=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 *p=(*p&0xFE00FF00)|0xE50026;
 q=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 M2C_FIELD(q,u16 *,4)=(M2C_FIELD(q,u16 *,4)&~0xC00)|0x800;
 M2C_FIELD(data_ov001_02193d18,s32 *,4)=func_ov001_0218c884(0,func_ov001_02172418,0,120);
}

void func_ov001_021723d4(void) {
 void func_ov001_0218c94c(s32,s32);
 void func_ov001_0218c104(s32);
 if(data_ov001_02193d18==NULL) return;
 func_ov001_0218c94c(0,M2C_FIELD(data_ov001_02193d18,s32 *,4));
 func_ov001_0218c104(M2C_FIELD(data_ov001_02193d18,s32 *,0));
 func_ov001_0218b71c((M2C_UNK *)&data_ov001_02193d18);
}

void func_ov001_02172418(s32 a) {
 s32 func_02011d58(void);
 s32 func_02011d78(void);
 void func_ov001_0218a55c(s32,s32,s32);
 volatile u16 *ime=(volatile u16 *)0x4000208;
 u16 old=*ime;
 s32 offset=0;
 s32 *p; s32 *q;
 *ime=0;
 if(func_02011d58()!=0x8000) offset=func_02011d78();
 (void)*ime;
 *ime=old;
 func_ov001_0218a55c(0,(data_ov001_0218f30c+M2C_FIELD(data_ov001_02193d18,s8 *,8)*4)[offset],M2C_FIELD(data_ov001_02193d18,s32 *,0));
 p=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 *p=(*p&0xFE00FF00)|0xE50026;
 q=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 M2C_FIELD(q,u16 *,4)=(M2C_FIELD(q,u16 *,4)&~0xC00)|0x800;
}

