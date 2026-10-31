/* 4 functions from 0x0206536C to 0x02066320 (main), found by ds-decomp. */
#include "common.h"

extern const u16 data_020ead40[];
static inline int FormatDigit(int ch) {
    return (ch < 0 || ch >= 128) ? 0 : data_020ead40[ch] & 8;
}

typedef struct { u8 a,b,c,d,e,f,g,h; s32 width,precision; } HexFormat;
typedef struct { u8 v[6]; } HexText6;
typedef struct { u8 v[5]; } HexText5;
typedef struct { u8 v[4]; } HexText4;
typedef struct { u8 a,b; } HexPair;
extern HexText6 data_02100514;
extern HexText5 data_0210051c,data_02100524,data_02100534,data_0210053c;
extern HexText4 data_0210052c,data_02100530,data_02100544,data_02100548;
char *func_020658fc(int,char *,HexFormat);
void func_0206f034();
double func_0206dfb0(double);

#pragma opt_common_subs off
char *func_0206536c(char *input, s32 **args, HexFormat *out) {
 char *format;
 HexFormat f;
 int ch;
 int active;
 int modifier;
 f.a=1; f.b=0; f.c=0; f.d=0; f.e=0; f.width=0; f.precision=0;
 format=input+1; ch=*format;
 if(ch=='%') { f.f=ch; *out=f; return format+1; }
 do {
 active=1;
  switch(ch) {
   case '-': f.a=0;break;
   case '+': f.b=1;break;
   case ' ': if(f.b!=1) f.b=2;break;
   case '#': f.d=1;break;
   case '0': if(f.a) f.a=2;break;
   default: active=0;break;
  }
  if(!active) break;
  ch=*++format;
 } while(1);
 if(ch=='*') {
  *args+=1; f.width=(*args)[-1];
  if(f.width<0) { f.a=0; f.width=-f.width; }
  ch=*++format;
 } else {
  while(FormatDigit(ch)) { f.width=f.width*10+(ch-'0'); ch=*++format; }
 }
 if(f.width>509) { f.f=255; *out=f; return format+1; }
 if(ch=='.') {
  ch=*++format;f.c=1;
  if(ch=='*') {
   *args+=1; f.precision=(*args)[-1];
   ch=*++format;
   if(f.precision<0) f.c=0;
  } else {
   while(FormatDigit(ch)) { f.precision=f.precision*10+(ch-'0'); ch=*++format; }
  }
 }
 modifier=1;
 switch(ch) {
 case 'h': f.e=2;if(format[1]=='h') { f.e=1;ch=*++format; }break;
 case 'l': f.e=3;if(format[1]=='l') { f.e=4;ch=*++format; }break;
 case 'L': f.e=9;break;
 case 'j': f.e=6;break;
 case 't': f.e=8;break;
 case 'z': f.e=7;break;
 default: modifier=0;break;
 }
 if(modifier) ch=*++format;
 f.f=ch;
 switch(ch) {
 case 'd':case 'i':case 'o':case 'u':case 'x':case 'X':
  if(f.e==9) f.f=255;
  else if(!f.c) f.precision=1;
  else if(f.a==2) f.a=1;
  break;
 case 'f':case 'F':
  if(f.e==2||f.e==6||f.e==7||f.e==8||f.e==4) f.f=255;
  else if(!f.c) f.precision=6;
  break;
 case 'a':case 'A':
  if(!f.c) f.precision=13;
  if(f.e==2||f.e==6||f.e==7||f.e==8||f.e==4||f.e==1) f.f=255;
  break;
 case 'g':case 'G':
  if(f.precision==0) f.precision=1;
 case 'e':case 'E':
  if(f.e==2||f.e==6||f.e==7||f.e==8||f.e==4||f.e==1) f.f=255;
  else if(!f.c) f.precision=6;
  break;
 case 'p': f.f='x'; f.d=1; f.e=3; f.precision=8;break;
 case 'c':
  if(f.e==3) f.e=5;
  else if(f.c || f.e!=0) f.f=255;
  break;
 case 's':
  if(f.e==3) f.e=5;
  else if(f.e) f.f=255;
  break;
 case 'n': if(f.e==9) f.f=255;break;
 default: f.f=255;break;
 }
 *out=f;
 return format+1;
}

char *func_020658fc(int value, char *out, HexFormat fmt) {
    (void)value;
    (void)fmt;
    return out;
}

#pragma opt_scheduling off
char *func_02065b48(u64 n,char *end,HexFormat f) {
char *p=end; int alt,conv,width,sign,precision; u64 base; int negative=0,count=0,digit;
*--p=0;
precision=f.precision;alt=f.d;conv=f.f;width=f.width;sign=f.b;
if(n==0 && precision==0 && (!alt || conv!='o'))return p;
switch(conv) {
case 'd':case 'i':base=10;if((s64)n<0){if(n!=0x8000000000000000ULL)n=-n;negative=1;}break;
case 'o':sign=0;base=8;break;
case 'u':sign=0;base=10;break;
case 'x':case 'X':sign=0;base=16;break;
}
do {digit=n%base;n/=base;if(digit<10)digit+='0';else if(conv=='x')digit+=87;else digit+=55;*--p=digit;count++;}while(n!=0);
if(base==8 && alt && *p!='0'){*--p='0';count++;}
if(f.a==2){precision=width;if(negative || sign)precision--;if(base==16 && alt)precision-=2;}
if(precision+(end-p)>509)return 0;
while(count<precision){*--p='0';count++;}
if(base==16 && alt){p[-1]=conv;p[-2]='0';p-=2;}
if(negative)*--p='-';else if(sign==1)*--p='+';else if(sign==2)*--p=' ';
return p;
}
#pragma opt_scheduling on
char *func_02065e44(double value,char *end,HexFormat fmt) {
 char *p=end;
 int precision=fmt.precision;
 u8 spec=fmt.f,alt=fmt.d,sign=fmt.b;
 HexFormat f;
 u8 decimal[40],conv[4];
 int i,bit,n;
 u8 digit;
 s8 tmp;
 u8 *bytes;
 if(precision>509)return 0;
 conv[0]=0;*(u16 *)(conv+2)=32;
 func_0206f034(conv,value,decimal);
 if(func_0206dfb0(value)==0.0){p=end-6;{ const u8 *src=(const u8 *)&data_02100514;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;a=src[4];b=src[5];p[4]=a;p[5]=b;}return p;}
 if(decimal[5]=='I'){
 if(*(s8 *)decimal){p=end-5;if(spec=='A'){{ const u8 *src=(const u8 *)&data_0210051c;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;a=src[4];p[4]=a;}return p;}else {{ const u8 *src=(const u8 *)&data_02100524;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;a=src[4];p[4]=a;}return p;}}
 p=end-4;if(spec=='A'){{ const u8 *src=(const u8 *)&data_0210052c;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;}return p;}else {{ const u8 *src=(const u8 *)&data_02100530;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;}return p;}
 }
 if(decimal[5]=='N'){
 if(*(s8 *)decimal){p=end-5;if(spec=='A'){{ const u8 *src=(const u8 *)&data_02100534;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;a=src[4];p[4]=a;}return p;}else {{ const u8 *src=(const u8 *)&data_0210053c;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;a=src[4];p[4]=a;}return p;}}
 p=end-4;if(spec=='A'){{ const u8 *src=(const u8 *)&data_02100544;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;}return p;}else {{ const u8 *src=(const u8 *)&data_02100548;u8 a,b;a=src[0];b=src[1];p[0]=a;p[1]=b;a=src[2];b=src[3];p[2]=a;p[3]=b;}return p;}
 }
 bytes=(u8 *)&value;
 f.a=1;f.b=1;f.c=0;f.d=0;f.e=0;f.width=0;f.precision=1;f.f=100;
 for(i=0;i<4;i++){tmp=((s8 *)bytes)[i];((s8 *)bytes)[i]=((s8 *)bytes)[7-i];((s8 *)bytes)[7-i]=tmp;}
 p=func_020658fc(((((u32)((u8 *)&value)[1]<<17)|((u32)((u8 *)&value)[0]<<25))>>21&0x7ff)-1023,end,f);
 *--p=spec=='a'?'p':'P';
 bit=precision*4+11;
 n=precision;
 while(n>=1){
 if(bit<64){
 int shift=7-(bit&7);
 digit=bytes[bit>>3]>>shift;
 if((bit&~7)!=((bit-4)&~7))digit=(u8)(digit | (bytes[(bit>>3)-1]<<8)>>shift);
 digit&=15;
 if(digit<10)digit+='0';
 else if(spec=='a')digit+=87;else digit+=55;
 }else digit='0';
 --n;*--p=digit;bit-=4;
 }
 if(precision || alt)*--p='.';
 p[-1]='1';p-=2;*p=spec=='a'?'x':'X';*--p='0';
 if(*(s8 *)decimal)*--p='-';else if(sign==1)*--p='+';else if(sign==2)*--p=' ';
 return p;
}
