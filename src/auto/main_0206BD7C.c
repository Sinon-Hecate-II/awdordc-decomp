/* 4 functions from 0x0206BD7C to 0x0206CD20 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s8 sign; s8 pad; s16 exp; u8 len; char digits[33]; } DecimalBD;
typedef struct { u8 a,sign,b,alt; u8 c; u16 conv; s32 d,precision; } FormatBD;
typedef struct { u8 mode; u8 pad; u16 digits; } DecimalFormBD;
extern u16 gWideCharClassTable[];
extern u16 data_02100564[], data_02100570[], data_0210057c[], data_02100584[], data_0210058c[], data_02100598[], data_021005a4[], data_021005ac[];

#pragma scheduling on
u16 *func_0206bd7c(double arg0, u16 *end, FormatBD fmt) {
void func_0206f034(void *, double, void *);
int func_02071284(s32,s32,s32,s32);
void func_0206bc58(void *, int);
u16 *func_0206cdac(u16 *, u16 *);
int StringLength(char *);
s32 func_020650a4(void *, void *, int);
double value=arg0;
DecimalFormBD form;
DecimalBD dec;
char buf[512];
char *p,*q;
int alt=fmt.alt;
int sign=fmt.sign;
u16 conv=fmt.conv;
int precision=fmt.precision;
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
if(value<0.0){result=end-5;if(((u32)conv>=128?0:gWideCharClassTable[conv]&512))func_0206cdac(result,data_02100564);else func_0206cdac(result,data_02100570);}
else{result=end-4;if(((u32)conv>=128?0:gWideCharClassTable[conv]&512))func_0206cdac(result,data_0210057c);else func_0206cdac(result,data_02100584);}
return result;
case 'N':
if(dec.sign){result=end-5;if(((u32)conv>=128?0:gWideCharClassTable[conv]&512))func_0206cdac(result,data_0210058c);else func_0206cdac(result,data_02100598);}
else{result=end-4;if(((u32)conv>=128?0:gWideCharClassTable[conv]&512))func_0206cdac(result,data_021005a4);else func_0206cdac(result,data_021005ac);}
return result;
}
dec.exp+=dec.len-1;
p=buf+sizeof(buf); *--p=0;
switch(conv){
case 'g': case 'G':
if(dec.len>precision)func_0206bc58(&dec,precision);
if(dec.exp<-4 || dec.exp>=precision){
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
*--p=*(volatile u8 *)&dec.digits[0];
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
result=end-StringLength(p)-1;
func_020650a4(result,p,StringLength(p));
return result;
}
#pragma scheduling off
u16 *func_0206cdcc(u16 *,s32);
s32 func_0206cd90(u16 *);
u16 *ParseFormatSpec(u16 *,char **,FormatBD *);
u16 *FormatInteger(s32,u16 *,FormatBD);
u16 *func_0206b5c0(u64,u16 *,FormatBD);
u16 *func_0206b8c0(double,u16 *,FormatBD);
u16 *func_0206add0(u16 *,s32,s32);
char *func_02065224(char *,s32,s32);
s32 StringLength(char *);
s32 func_020650a4(void *,void *,s32);
s32 func_02065020(void *,void *,s32);
extern u16 data_021005b4[];
extern u8 data_021005b8[];
s32 func_0206c3c8(s32 (*writer)(void *,const u16 *,s32), void *state, u16 *p, char *args, ...) {
    u16 buffer[512];
    FormatBD f;
    u16 pad=' ', space;
 char narrow;
    u16 *q;
    s32 total=0;
    s32 len;
    u16 *text;
    s32 width;
    s32 value;
    u64 wide;
    double real;
    while (*p) {
        u16 *mark=func_0206cdcc(p,37);
        q=mark;
        if (!mark) {
            len=func_0206cd90(p);
 total+=len;
            if(len && !writer(state,p,len)) return -1;
            break;
        }
        len=mark-p;
total+=len;
        if(len && !writer(state,p,len)) return -1;
        p=ParseFormatSpec(q,&args,&f);
        switch(f.conv) {
        case 'd': case 'i':
            if(((u8)f.c)==3) {args+=4;
value=*(long *)(args-4);
}
            else if(((u8)f.c)==4) {args+=8;
wide=*(u64 *)(args-8);
}
            else if(((u8)f.c)==6) {args+=8;
wide=*(u64 *)(args-8);
}
            else if(((u8)f.c)==7) {args+=4;
value=*(unsigned long *)(args-4);
}
            else if(((u8)f.c)==8) {args+=4;
value=(s32)*(char **)(args-4);
}
            else {args+=4;
value=*(s32 *)(args-4);
}
            if(((u8)f.c)==2)value=(s16)value;
            if(((u8)f.c)==4 || ((u8)f.c)==6){text=func_0206b5c0(wide,buffer+512,f);
if(!text)goto invalid;
}
            else {text=FormatInteger(value,buffer+512,f);
if(!text)goto invalid;
}
            len=buffer+511-text;
break;
        case 'o': case 'u': case 'x': case 'X':
            if(((u8)f.c)==3) {args+=4;
value=*(long *)(args-4);
}
            else if(((u8)f.c)==4) {args+=8;
wide=*(u64 *)(args-8);
}
            else if(((u8)f.c)==6) {args+=8;
wide=*(u64 *)(args-8);
}
            else if(((u8)f.c)==7) {args+=4;
value=*(unsigned long *)(args-4);
}
            else if(((u8)f.c)==8) {args+=4;
value=(s32)*(char **)(args-4);
}
            else {args+=4;
value=*(s32 *)(args-4);
}
            if(((u8)f.c)==2)value=(u16)value;
            if(((u8)f.c)==4 || ((u8)f.c)==6){text=func_0206b5c0(wide,buffer+512,f);
if(!text)goto invalid;
}
            else {text=FormatInteger(value,buffer+512,f);
if(!text)goto invalid;
}
            len=buffer+511-text;
break;
        case 'e':case 'E':case 'f':case 'F':case 'g':case 'G':
            if(((u8)f.c)==9){args+=8;
real=*(double *)(args-8);
}
            else {args+=8;
real=*(long double *)(args-8);
}
            text=func_0206bd7c(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;
break;
        case 'a':case 'A':
            if(((u8)f.c)==9){args+=8;
real=*(double *)(args-8);
}
            else {args+=8;
real=*(long double *)(args-8);
}
            text=func_0206b8c0(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;
break;
        case 's':
if(((u8)f.c)==5){
args+=4;
text=*(u16 **)(args-4);
if(!text)text=(u16 *)data_021005b4;
if(f.alt){len=(u8)*text++;
if(f.b && len>f.precision)len=f.precision;
}
else if(f.b){u16 *e;
len=f.precision;
e=func_0206add0(text,0,len);
if(e)len=e-text;
}
else len=func_0206cd90(text);
}else{
char *str;
 s32 n;
 args+=4;
str=*(char **)(args-4);
if(!str)str=(char *)data_021005b8;
if(f.alt){n=*text&255;
if(f.b && n>f.precision)n=f.precision;
}
else if(f.b){char *e;
n=f.precision;
e=func_02065224(str,0,n);
if(e)n=e-str;
}
else n=StringLength(str);
len=func_020650a4(buffer,str,n);
if(len<0)goto invalid;
text=buffer;
}
break;
      case 'n':{
            void *ptr;
            args+=4;
ptr=*(void **)(args-4);
            switch(((u8)f.c)){
            case 0:*(s32 *)ptr=total;
break;
            case 2:*(s16 *)ptr=total;
break;
            case 3:*(s32 *)ptr=total;
break;
            case 6:*(s64 *)ptr=total;
break;
            case 7:*(s32 *)ptr=total;
break;
            case 8:*(s32 *)ptr=total;
break;
            case 4:*(s64 *)ptr=total;
break;
            }
            continue;
        }
        case 'c':text=buffer;
if(((u8)f.c)==5){args+=4;
buffer[0]=*(s32 *)(args-4);
len=1;
}else{args+=4;
narrow=*(s32 *)(args-4);
len=func_02065020(text,&narrow,1);
}break;
        case '%':buffer[0]='%';
text=buffer;
len=1;
break;
        case 65535:
        default:
        invalid:
            len=func_0206cd90(q);
            if(len && !writer(state,q,len))return -1;
            return total+len;
        }
        width=len;
        if(f.a){
            pad=f.a==2?'0':' ';
            if((*text=='+' || *text=='-' || *text==' ') && pad=='0'){
                if(!writer(state,text,1))return -1;
                text++;
len--;
            }
            while(width<f.d){
                if(!writer(state,&pad,1))return -1;
                width++;
            }
        }
        if(len && !writer(state,text,len))return -1;
        if(f.a==0){
            while(width<f.d){
                space=' ';
                if(!writer(state,&space,1))return -1;
                width++;
            }
        }
        total+=width;
    }
    return total;
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

void StringFormatWide(s32 arg0, s32 arg1, s32 arg2, ...) {
    void func_0206cd20();
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_0206cd20(arg0, arg1, arg2, args);

}
