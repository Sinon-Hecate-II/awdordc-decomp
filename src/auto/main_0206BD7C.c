/* 4 functions from 0x0206BD7C to 0x0206CD20 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s8 sign; s8 pad; s16 exp; u8 len; char digits[33]; } DecimalBD;
typedef struct { u8 a,sign,b,alt; u16 c,conv; s32 d,precision; } FormatBD;
typedef struct { u8 mode; u8 pad; u16 digits; } DecimalFormBD;
extern u16 data_020eaf78[];
extern u16 data_02100564[], data_02100570[], data_0210057c[], data_02100584[], data_0210058c[], data_02100598[], data_021005a4[], data_021005ac[];

#pragma scheduling off
u16 *func_0206bd7c(double value, u16 *end, FormatBD fmt) {
void func_0206f034(void *, double, void *);
int func_02071284(s32,s32,s32,s32);
void func_0206bc58(void *, int);
u16 *func_0206cdac(u16 *, u16 *);
int func_02068c34(char *);
void func_020650a4(void *, void *, int);
DecimalFormBD form;
DecimalBD dec;
char buf[512];
char *p,*q;
int precision=fmt.precision;
u16 conv=fmt.conv;
u8 alt=fmt.alt;
u8 sign=fmt.sign;
int exp,whole,n,i;
char esign;
u16 *result;
if(precision>509)return 0;
form.mode=0; form.digits=32;
func_0206f034(&form,value,&dec);
q=dec.digits+dec.len;
while(dec.len>1 && *--q=='0'){dec.len--;dec.exp++;}
switch((u8)dec.digits[0]){
case '0': dec.exp=0; break;
case 'I':
if(value<0.0){result=end-5;if(((u32)conv>=128?0:data_020eaf78[conv]&512))func_0206cdac(result,data_02100564);else func_0206cdac(result,data_02100570);}
else{result=end-4;if(((u32)conv>=128?0:data_020eaf78[conv]&512))func_0206cdac(result,data_0210057c);else func_0206cdac(result,data_02100584);}
return result;
case 'N':
if(dec.sign){result=end-5;if(((u32)conv>=128?0:data_020eaf78[conv]&512))func_0206cdac(result,data_0210058c);else func_0206cdac(result,data_02100598);}
else{result=end-4;if(((u32)conv>=128?0:data_020eaf78[conv]&512))func_0206cdac(result,data_021005a4);else func_0206cdac(result,data_021005ac);}
return result;
}
dec.exp+=dec.len-1;
p=buf+sizeof(buf); *--p=0;
switch(conv){
case 'g': case 'G':
if(dec.len>precision)func_0206bc58(&dec,precision);
if(!(dec.exp>=-4 && dec.exp<precision)){
if(alt)precision--;else precision=dec.len-1;
if(conv=='g')conv='e';else conv='E';goto scientific;
}
if(alt)precision-=dec.exp+1;
else {precision=dec.len-(dec.exp+1);if(precision<0)precision=0;}
goto fixed;
case 'e':case 'E':
scientific:
if(dec.len>precision+1)func_0206bc58(&dec,precision+1);
exp=dec.exp;esign='+';n=0;
if(exp<0){exp=-exp;esign='-';}
for(;exp || n<2;n++){*--p=exp%10+'0';exp/=10;}
*--p=esign;*--p=conv;
if(buf-p+precision>509)return 0;
if(dec.len<precision+1){i=precision+2-dec.len;while(--i)*--p='0';}
q=dec.digits+dec.len;i=dec.len;
while(--i)*--p=*--q;
if(precision || alt)*--p='.';
*--p=(u8)dec.digits[0];
if(dec.sign)*--p='-';
else if(sign==1)*--p='+';
else if(sign==2)*--p=' ';
break;
case 'f':case 'F':
fixed:
n=dec.len-dec.exp-1;if(n<0)n=0;
if(n>precision){func_0206bc58(&dec,dec.len-(n-precision));n=dec.len-dec.exp-1;if(n<0)n=0;}
whole=dec.exp+1;if(whole<0)whole=0;
if(whole+n>509)return 0;
q=dec.digits+dec.len;
for(i=0;i<precision-n;i++)*--p='0';
for(i=0;i<n && i<dec.len;i++)*--p=*--q;
for(;i<n;i++)*--p='0';
if(precision || alt)*--p='.';
if(whole){
for(i=0;i<whole-dec.len;i++)*--p='0';
for(;i<whole;i++)*--p=*--q;
}else *--p='0';
if(dec.sign)*--p='-';
else if(sign==1)*--p='+';
else if(sign==2)*--p=' ';
}
result=end-func_02068c34(p)-1;
func_020650a4(result,p,func_02068c34(p));
return result;
}
s32 func_0206ccb8(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0206adc0(s32, M2C_UNK, s32);
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;
    s32 result;
    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5 = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32)(temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    result = func_0206adc0(M2C_FIELD(arg0, s32 *, 0) + (temp_r3 * 2), arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, s32 *, 8) + var_r5;
    return result;
}

void func_0206ccf8(s32 arg0, s32 arg1, s32 arg2, ...) {
    void func_0206cd20();
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_0206cd20(arg0, arg1, arg2, args);

}
