/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_0219169c;

void func_ov001_0218851c(void *p) {
 s32 func_ov001_02188480(u16);
 u16 a,b,c; int n;
 if(M2C_FIELD(p,u16 *,2)){func_ov001_02187b90();func_ov001_02187b14(9);return;}
 if(M2C_FIELD(&data_ov001_02193e20,void (**)(int,void *,int,int),0))
 M2C_FIELD(&data_ov001_02193e20,void (**)(int,void *,int,int),0)(0x8000000,&data_ov001_0219169c,M2C_FIELD(p,u16 *,8),M2C_FIELD(p,u16 *,10));
 b=M2C_FIELD(p,u16 *,10);c=M2C_FIELD(p,u16 *,8);
 a=M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,94);
 if(a>b) {
 M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,94)=b;
 M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,96)=1<<(c-1);
 }else if(a==b) M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,96)|=1<<(c-1);
 n=func_ov001_02188480((u16)(c+1));
 if(n==24){func_ov001_02187b14(7);return;}
 if(n==2)return;
 func_ov001_02187b14(9);
}

void func_ov001_021885f4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02013dac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02013dac(arg0, 3, 0x11, arg1, 0x1E);
}

s32 func_ov001_02188614(void) {
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_021916b4;
s32 func_ov001_0218868c(u16);
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,0x40)!=7) func_02007958();
func_ov001_02187b14(1);
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,0x5C)=func_ov001_0218868c(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,0x60));
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0))
M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *,s32),0)(0x8000000,&data_ov001_021916b4,M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,0x5C));
return M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,0x5C);
}

s32 func_ov001_0218868c(u16 bits) {
 s16 last=0; u16 count=0; s16 i=0; u16 pick;
 for(;i<16;i++) if(bits&(1<<i)){last=i+1;count++;}
 if(count<=1)return last;
 M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u32 *,88)=M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u32 *,88)*0x10dcd+0x3039;
 pick=(count*(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u32 *,88)&255))>>8;
 for(i=0;i<16;bits>>=1,i++)if(bits&1){if(pick==0)return (s16)(i+1);pick--;}
 return 0;
}

s32 func_ov001_02188774(void) {
extern M2C_UNK data_ov001_02193e20;
s32 result;
s32 func_ov001_0218880c(void);
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,4772)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,4768)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,72)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,80)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,82)=1;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,84)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,0)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,4)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,76)=0;
result=func_ov001_0218880c(); if(result==0) result=0; else result=1; return result;
}

void func_ov001_021887ec(void *arg0) {
    M2C_UNK func_02007958();
    if (M2C_FIELD(arg0, u16 *, 2) != 8) {
        return;
    }
    func_ov001_02187b14(9);
    func_02007958();
}

s32 func_ov001_0218880c(void) {
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02188858;
s32 func_02012218(void *,void *,s32);
func_ov001_02187b14(3);
if(func_02012218((u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x80,&func_ov001_02188858,2)==2) return 1;
func_ov001_02187b90();
func_ov001_02187b14(10);
return 0;
}

void func_ov001_02188858(void *arg0){
s32 func_020119dc(void *);
if(M2C_FIELD(arg0,u16 *,2)){func_ov001_02187b90();func_ov001_02187b14(10);return;}
if(func_020119dc((void *)func_ov001_021887ec)){func_ov001_02187b90();func_ov001_02187b14(10);return;}
func_ov001_02187b14(1);
}

void func_ov001_02188a20(s32 arg0) {
    extern M2C_UNK data_ov001_02193e20;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x4C) = arg0;
}

void func_ov001_02188a34(s32 arg0) {
extern M2C_UNK data_ov001_02193e20;
void func_02013aa8(void *, void *, s32);
func_02013aa8((u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x13E0,(u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 4)+0x1C00,arg0);
}

s32 func_ov001_02188a5c(void *arg0){
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_021916e8;
extern M2C_UNK data_ov001_02191718;
s32 func_02013248(void *,void *,void *);
s32 result=func_02013248((u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x13e0,arg0,(u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x1c00);
if(result==7){
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0)(0x8000000,&data_ov001_021916e8);
return 0;}
if(result==5){
if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0)(0x8000000,&data_ov001_02191718);
func_ov001_02187b90(result);return 0;}
if(result==0)return 1;
func_ov001_02187b90();return 0;
}

void func_ov001_02188b04(void) {
    M2C_UNK func_ov001_02187b14(M2C_UNK);
    s32 func_ov001_021882e0();
    if (func_ov001_021882e0() != 0) {
        return;
    }
    func_ov001_02187b14(0xA);
}

s32 func_ov001_02188c28(void){
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02188344;
s32 func_020122ac(void *);
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40)!=1)func_02007958();
func_ov001_02187b14(3);
if(func_020122ac(&func_ov001_02188344)==2)return 1;
func_ov001_02187b14(9);return 0;
}

void func_ov001_02188c78(void *p,void *a){
extern void *data_ov001_02193e28;
void func_ov001_02186e40(void *);
void func_02045eb4(void *);
void *func_ov001_02184c60(void);
data_ov001_02193e28=p;
func_ov001_02186e40((u8*)p+0xb00);
M2C_FIELD(data_ov001_02193e28,u16 *,1608)=0;
M2C_FIELD(data_ov001_02193e28,u16 *,1610)=0;
M2C_FIELD(data_ov001_02193e28,u8 *,2704)=1;
M2C_FIELD(data_ov001_02193e28,u8 *,2705)=1;
M2C_FIELD(data_ov001_02193e28,s32 *,2716)=0;
func_ov001_02189828();
M2C_FIELD(data_ov001_02193e28,s32 *,2740)=M2C_FIELD(a,s32 *,0);
M2C_FIELD(data_ov001_02193e28,s32 *,2744)=M2C_FIELD(a,s32 *,4);
M2C_FIELD(data_ov001_02193e28,s32 *,2748)=M2C_FIELD(a,s32 *,8);
M2C_FIELD(data_ov001_02193e28,s32 *,2752)=M2C_FIELD(a,s32 *,12);
M2C_FIELD(data_ov001_02193e28,s32 *,2756)=M2C_FIELD(a,s32 *,16);
M2C_FIELD(data_ov001_02193e28,s32 *,2760)=M2C_FIELD(a,s32 *,20);
M2C_FIELD(data_ov001_02193e28,u8 *,0xa92)=M2C_FIELD(a,u8 *,24);
M2C_FIELD(data_ov001_02193e28,u8 *,0xacc)=2;
func_02007004();func_02045eb4((u8*)data_ov001_02193e28+0x64c);func_02007004();M2C_FIELD(data_ov001_02193e28,void **,0xaa4)=func_ov001_02184c60();
}

int func_ov001_02188d68(void) {
 extern void *data_ov001_02193e28; void func_0201808c(void);
 unsigned int state=M2C_FIELD(data_ov001_02193e28,u8 *,0xa90);
 if(state==1||state==20||state==23||state==26||state==29){
 M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)=34;
 M2C_FIELD(data_ov001_02193e28,u8 *,0xaac)=0;return 1;
 }
 if(state==4||state==5||state==6||state==13){
 if(state==4 && M2C_FIELD(data_ov001_02193e28,u32 *,0xa98)<6)return 0;
 func_0201808c();
 M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)=16;
 M2C_FIELD(data_ov001_02193e28,u8 *,0xaac)=2;return 1;
 }
 if((u8)(state+247)<=1){M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)=32;return 1;}
 if(state==12){M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)=34;return 1;}
 return 0;
}

void func_ov001_02188e44(void) {
extern void *data_ov001_02193e28;
func_ov001_0218836c(M2C_FIELD(data_ov001_02193e28,s32 *,0xAC8));
M2C_FIELD(data_ov001_02193e28,u8 *,0xA90)=1;
M2C_FIELD(data_ov001_02193e28,u16 *,0x648)=func_02012084();
func_02008048(M2C_FIELD(data_ov001_02193e28,void **,0xAA4),(u8 *)data_ov001_02193e28+0xA50,0x40);
M2C_FIELD(data_ov001_02193e28,u8 *,0xA93)=0;
M2C_FIELD(data_ov001_02193e28,s32 *,0x204)=0;
M2C_FIELD(data_ov001_02193e28,u16 *,0x648)++;
}

s32 func_ov001_02188ec4(void) {
extern void *data_ov001_02193e28;
u32 state=M2C_FIELD(data_ov001_02193e28,u8 *,0xA90);
if(state!=1 && state!=26 && state!=29) return 0;
func_ov001_02188e44();func_ov001_02188774();
M2C_FIELD(data_ov001_02193e28,u8 *,0xA90)=2;return 1;
}

s32 func_ov001_02188f0c(void){
extern void *data_ov001_02193e28;
if(M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)!=5)return 0;
M2C_FIELD(data_ov001_02193e28,u8 *,0xa90)=6;
func_ov001_0218730c();return 1;
}

void func_ov001_021892c4(u8 *arg0,u8 *arg1) {
extern void *data_ov001_02193e28;
*arg0=M2C_FIELD(data_ov001_02193e28,u8 *,0xA90);
if(M2C_FIELD(data_ov001_02193e28,u8 *,0xA90)!=M2C_FIELD(data_ov001_02193e28,u8 *,0xA91)) *arg1=1; else *arg1=0;
M2C_FIELD(data_ov001_02193e28,u8 *,0xA91)=M2C_FIELD(data_ov001_02193e28,u8 *,0xA90);
}

void func_ov001_02189308(void) {
    func_02013e98(1);
}

s32 func_ov001_02189318(void) {
    extern M2C_UNK data_ov001_02193e20;
    s32 temp_r0 = func_ov001_02188394();
    switch (temp_r0) {
        case 0:
        case 3:
        case 5:
        case 6:
        case 7:
            break;
        case 1:
        case 2:
            func_ov001_021883a8();
            break;
        case 4:
            func_ov001_02188614();
            break;
        case 8:
            {
                u8 *temp_r2 = (u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 0);
                *(u16 *)(temp_r2 + 0x64a) = func_ov001_02188614();
                *(s32 *)(temp_r2 + 0xa98) = 0;
                temp_r2[0xa90] = 3;
            }
            break;
        case 9:
            {
                u8 *temp_r0_2 = (u8 *)M2C_FIELD(&data_ov001_02193e20, void **, 0);
                *(s32 *)(temp_r0_2 + 0xa98) = 0;
                temp_r0_2[0xa90] = 3;
            }
            break;
        case 10:
            func_ov001_02188b04();
            break;
        case 11:
            func_02007958();
            break;
    }
    return 0;
}

void func_ov001_021893c0(void) {
    M2C_UNK func_ov001_02186e80(s32, u16);
    extern void *data_ov001_02193e28;
    func_ov001_02186e80(M2C_FIELD(data_ov001_02193e28, s32 *, 0xAC8), M2C_FIELD(data_ov001_02193e28, u16 *, 0x648));
}

