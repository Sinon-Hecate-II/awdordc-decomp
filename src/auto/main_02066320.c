/* 2 functions from 0x02066320 to 0x02066BA8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a,b,c,d,e,f,g,h; s32 width,precision; } HexFormat;
typedef struct { s8 sign; s8 pad; s16 exp; u8 len; char digits[33]; } DecimalBD;
typedef struct { u8 mode; u8 pad; u16 digits; } DecimalFormBD;
typedef struct { u8 a,b; } HexPair;
extern const u16 gCharClassTable[];
extern u8 data_0210051c[],data_02100524[],data_0210052c[],data_02100530[],data_02100534[],data_0210053c[],data_02100544[],data_02100548[];

/* Rounds the decimal string in an object at the given digit position. */
void func_02066320(void *str, s32 pos) {
    s32 carry;
    s8 *tail;
    s8 *p;
    s8 digit;
    u8 len;
    s8 *start;
    if (pos < 0) {
zero:
        M2C_FIELD(str,s16 *,2)=0;
        M2C_FIELD(str,u8 *,4)=1;
        M2C_FIELD(str,s8 *,5)='0';
        return;
    }
    len=M2C_FIELD(str,u8 *,4);
    if (pos >= len) return;
    start=(s8 *)str+5;
    p=start+pos+1;
    digit=*--p-'0';
    if (digit == 5) {
        tail=start+len;
        do { --tail; } while (tail > p && *tail == '0');
        if (tail == p) carry=p[-1]&1;
        else carry=1;
    } else {
        carry=digit > 5;
    }
    if (pos != 0) {
        do {
            digit=(*--p-'0')+carry;
            carry=digit > 9;
            if (carry != 0 || digit == 0) {
                --pos;
            } else {
                *p=digit+'0';
                break;
            }
        } while (pos != 0);
    }
    if (carry != 0) {
        M2C_FIELD(str,s16 *,2)++;
        M2C_FIELD(str,u8 *,4)=1;
        M2C_FIELD(str,s8 *,5)='1';
        return;
    }
    if (pos == 0) goto zero;
    M2C_FIELD(str,u8 *,4)=pos;
}

#pragma scheduling off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_strength_reduction on
char *func_02066444(double arg0, char *end, HexFormat fmt) {
void func_0206f034(void *, double, void *);
int func_02071284(s32,s32,s32,s32);
void func_02066320(void *, int);

int StringLength(char *);
void func_020650a4(void *, void *, int);
double value=arg0;
DecimalFormBD form;
DecimalBD dec;

char *p,*q;
int alt=fmt.d;
int conv=fmt.f;
int precision=fmt.precision;
int sign=fmt.b;
int exp,whole,n,i;
char esign;
char *result;
if(precision>509)return 0;
form.mode=0; form.digits=32;
func_0206f034(&form,value,&dec);
q=dec.digits+dec.len;
while(dec.len>1 && *--q=='0'){dec.len--;dec.exp++;}
switch((u8)dec.digits[0]){
case '0': dec.exp=0; break;
case 'I':
if(value<0.0){result=end-5;if((conv<0 || conv>=128?0:gCharClassTable[conv]&512)){u8 *src=data_0210051c;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;result[4]=src[4];}else {u8 *src=data_02100524;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;result[4]=src[4];}}
else{result=end-4;if((conv<0 || conv>=128?0:gCharClassTable[conv]&512)){u8 *src=data_0210052c;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;}else {u8 *src=data_02100530;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;}}
return result;
case 'N':
if(dec.sign){result=end-5;if((conv<0 || conv>=128?0:gCharClassTable[conv]&512)){u8 *src=data_02100534;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;result[4]=src[4];}else {u8 *src=data_0210053c;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;result[4]=src[4];}}
else{result=end-4;if((conv<0 || conv>=128?0:gCharClassTable[conv]&512)){u8 *src=data_02100544;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;}else {u8 *src=data_02100548;HexPair pair;pair=*(HexPair *)(src+0);*(HexPair *)(result+0)=pair;pair=*(HexPair *)(src+2);*(HexPair *)(result+2)=pair;}}
return result;
}
dec.exp+=dec.len-1;
p=end; *--p=0;
switch(conv){
case 'g': case 'G':
if(dec.len>precision)func_02066320(&dec,precision);
if(dec.exp<-4 || dec.exp>=precision){
if(alt)precision--;else precision=dec.len-1;
if(conv=='g')conv='e';else conv='E';goto scientific;
}
if(alt)precision-=dec.exp+1;
else {precision=dec.len-(dec.exp+1);if(precision<0)precision=0;}
goto fixed;
case 'e':case 'E':
scientific:
if(dec.len>precision+1)func_02066320(&dec,precision+1);
exp=dec.exp;esign='+';n=0;
if(exp<0){exp=-exp;esign='-';}
for(;exp || n<2;n++){*--p=exp%10+'0';exp/=10;}
*--p=esign;*--p=conv;
if(end-p+precision>509)return 0;
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
if(n>precision){func_02066320(&dec,dec.len-(n-precision));n=dec.len-dec.exp-1;if(n<0)n=0;}
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
return p;
}
#pragma scheduling reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
#pragma optimization_level reset
