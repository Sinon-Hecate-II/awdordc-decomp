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

u32 func_0206a384(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d, M2C_UNK *e, M2C_UNK *f, M2C_UNK *g) {
    return 0;
}

M2C_UNK func_0206a76c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, M2C_UNK *arg4, M2C_UNK *arg5, M2C_UNK *arg6) {
    return 0;
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

#pragma push
#pragma opt_common_subs off
s32 func_0206ad4c(void *arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r1;
    u32 temp_r2;

    var_r1 = arg1;
    if ((arg0 == NULL) || (temp_r3 = M2C_FIELD(arg0, s32 *, 4), (((u32) (temp_r3 << 0x16) >> 0x1D) == 0))) {
        return 0;
    }
    temp_r2 = (u32) (temp_r3 << 0x14) >> 0x1E;
    switch (temp_r2) {                              /* irregular */
    case 2:
        var_r1 = 1;
        break;
    case 0:
        if (var_r1 > 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) ((temp_r3 & ~0xC00) | 0x800);
        } else if (var_r1 < 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) ((temp_r3 & ~0xC00) | 0x400);
        }
        break;
    case 1:
        var_r1 = -1;
        break;
    }
    return var_r1;
}
#pragma pop
void func_0206adc0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020651a4(M2C_UNK, M2C_UNK, s32);
    func_020651a4(arg0, arg1, arg2 * 2);
}

u16 *func_0206add0(u16 *p,s32 value,u32 n) {
if(n){do {if(*p==value)return p;p++;}while(--n);}
return NULL;
}

