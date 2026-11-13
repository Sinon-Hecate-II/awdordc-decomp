/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_0219169c;
extern M2C_UNK data_ov001_0219166c, data_ov001_02191684, data_ov001_021916cc;

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
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,0x40)!=7) SystemHalt();
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

#pragma peephole off

#pragma peephole reset

/* Initialize the active map state pointed to by the global from the allocated buffer p and the config a. */

