/* 10 functions from 0x0206A294 to 0x0206ADF8 (main), found by ds-decomp. */
#include "common.h"

double func_0206a294(M2C_UNK p,M2C_UNK end){
double func_02069048(); double func_0206dfb0(double);void func_02068a04();extern s32 gErrno;
s32 count,overflow;M2C_UNK state[2];double value,absolute;
state[1]=0;state[0]=p;
value=func_02069048(0x7fffffff,func_02068a04,state,&count,&overflow);
if(end)M2C_FIELD(end,s32*,0)=p+count;
absolute=func_0206dfb0(value);
if(overflow || (value!=0.0 && (absolute<2.2250738585072014e-308 || absolute>1.7976931348623157e308)))gErrno=34;
return value;
}

void func_0206a374(M2C_UNK arg0) {
    double func_0206a294(M2C_UNK, M2C_UNK);
    func_0206a294(arg0, 0);
}

u32 func_0206a384(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d, M2C_UNK *e, M2C_UNK *f, M2C_UNK *g) {
    return 0;
}

u64 func_0206a76c(s32 base,s32 width,s32 (*get)(void *,s32,s32),void *ctx,s32 *count,s32 *negative,s32 *overflow) {
extern u16 gCharClassTable[]; extern u8 data_020eacc0[];
s32 state,c,n,space,d; u64 limit,value;
u64 func_02072088(u64,u64);
*overflow=0;value=0;limit=0;*negative=0;state=1;space=0;n=0;
if(base<0 || base==1 || base>36 || width<1)state=64;
else {n++;c=get(ctx,0,0);if(base)limit=func_02072088(~(u64)0,(s64)base);}
while(n<=width && c!=-1 && !(state&96)){
switch(state){
case 1:
if(((c<0 || c>=128)?0:(gCharClassTable[c]&256))){c=get(ctx,0,0);space++;break;}
if(c=='+'){n++;c=get(ctx,0,0);}else if(c=='-'){n++;c=get(ctx,0,0);*negative=1;}state=2;break;
case 2:
if((base==0 || base==16)&&c=='0'){state=4;n++;c=get(ctx,0,0);}else state=8;break;
case 4:
if(c=='X'||c=='x'){base=16;state=8;n++;c=get(ctx,0,0);}else {if(!base)base=8;state=16;}break;
case 8: case 16:
if(!base)base=10;if(!limit)limit=func_02072088(~(u64)0,(s64)base);
if(((c<0 || c>=128)?0:(gCharClassTable[c]&8))){c-='0';if(c>=base){state=state==16?32:64;c+='0';break;}}
else {
if(!((c<0||c>=128)?0:(gCharClassTable[c]&1)) || (c<0||c>=128?c:data_020eacc0[c])-55>=base){state=state==16?32:64;break;}
if(c<0){}else if(c<128)c=data_020eacc0[c];c-=55;
}
if(value>limit)*overflow=1;value*=base;if((u64)(s64)c>~(u64)0-value)*overflow=1;value+=c;state=16;n++;c=get(ctx,0,0);break;
}}
if(!(state&52)){value=0;*count=0;}else *count=n-1+space;
get(ctx,c,1);return value;
}

#pragma opt_strength_reduction off
#pragma opt_instruction_scheduling off
s32 func_0206abd8(s32 arg0, s32 *arg1, M2C_UNK arg2) {
    u32 func_0206a384();
    void func_02068a04();
    extern s32 gErrno;
    s32 count;
    s32 negative;
    s32 overflow;
    M2C_UNK state[2];
    u32 value;
    state[0] = arg0;
    state[1] = 0;
    value = func_0206a384(arg2, 0x7fffffff, func_02068a04, state, &count, &negative, &overflow);
    if (arg1 != 0) {
        *arg1 = arg0 + count;
    }
    if (overflow != 0) {
        value = -1;
        gErrno = 0x22;
        goto done;
    }
    if (negative != 0) {
        return -value;
    }
    done: return value;
}
#pragma opt_strength_reduction reset
#pragma opt_instruction_scheduling reset
s32 func_0206ac70(M2C_UNK p,M2C_UNK end,M2C_UNK base){
u32 func_0206a384();void func_02068a04();extern s32 gErrno;
s32 count,negative,overflow; M2C_UNK state[2];u32 value;
state[0]=p;state[1]=0;
value=func_0206a384(base,0x7fffffff,func_02068a04,state,&count,&negative,&overflow);
if(end)M2C_FIELD(end,s32*,0)=p+count;
if(overflow || (!negative && value>0x7fffffffU) || (negative && value>0x80000000U)){
value=negative?0x80000000:0x7fffffff;gErrno=34;return value;
}
return negative?-value:value;
}

void ParseInt(M2C_UNK arg0) {
    M2C_UNK func_0206ac70(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0206ac70(arg0, 0, 0xA);
}

#pragma opt_propagation off
s32 func_0206ad4c(void *arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r1;
    u32 temp_r2;

    var_r1 = arg1;
    if ((arg0 == NULL) || (temp_r3 = M2C_FIELD(arg0, s32 *, 4), (((u32) (temp_r3 << 0x16) >> 0x1D) == 0))) {
        return 0;
    }
    temp_r2 = (u32) (temp_r3 << 0x14) >> 0x1E;
    switch (temp_r2) {
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
#pragma opt_propagation reset
void func_0206adc0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK MemCopy(M2C_UNK, M2C_UNK, s32);
    MemCopy(arg0, arg1, arg2 * 2);
}

u16 *func_0206add0(u16 *p,s32 value,u32 n) {
if(n){do {if(*p==value)return p;p++;}while(--n);}
return NULL;
}

