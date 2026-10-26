/* 10 functions from 0x0206A294 to 0x0206ADF8 (main), found by ds-decomp. */
#include "common.h"

double func_0206a294(M2C_UNK p,M2C_UNK end){
double func_02069048(); double func_0206dfb0(double);void func_02068a04();extern s32 data_0213e9f4;
s32 count,overflow;M2C_UNK state[2];double value,absolute;
state[1]=0;state[0]=p;
value=func_02069048(0x7fffffff,func_02068a04,state,&count,&overflow);
if(end)M2C_FIELD(end,s32*,0)=p+count;
absolute=func_0206dfb0(value);
if(overflow || (value!=0.0 && (absolute<2.2250738585072014e-308 || absolute>1.7976931348623157e308)))data_0213e9f4=34;
return value;
}

void func_0206a374(M2C_UNK arg0) {
    double func_0206a294(M2C_UNK, M2C_UNK);
    func_0206a294(arg0, 0);
}

s32 func_0206ac70(M2C_UNK p,M2C_UNK end,M2C_UNK base){
u32 func_0206a384();void func_02068a04();extern s32 data_0213e9f4;
s32 count,negative,overflow; M2C_UNK state[2];u32 value;
state[0]=p;state[1]=0;
value=func_0206a384(base,0x7fffffff,func_02068a04,state,&count,&negative,&overflow);
if(end)M2C_FIELD(end,s32*,0)=p+count;
if(overflow || (!negative && value>0x7fffffffU) || (negative && value>0x80000000U)){
value=negative?0x80000000:0x7fffffff;data_0213e9f4=34;return value;
}
return negative?-value:value;
}

void func_0206ad38(M2C_UNK arg0) {
    M2C_UNK func_0206ac70(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0206ac70(arg0, 0, 0xA);
}

void func_0206adc0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020651a4(M2C_UNK, M2C_UNK, s32);
    func_020651a4(arg0, arg1, arg2 * 2);
}

