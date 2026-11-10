/* 1 function from 0x02069048 to 0x0206A294 (main), found by ds-decomp. */
#include "common.h"
extern const u8 data_020eae6d[267];
extern const u8 data_020eae68[5];
extern const u16 data_020ead40[128];
extern const u8 data_020eacc0[128];
extern float data_021002e8;
extern double data_021002f0;
static inline s32 ScanFloatClass(s32 ch,s32 mask){return (ch<0||ch>=128)?0:data_020ead40[ch]&mask;}
static inline s32 ScanFloatUpper(s32 ch){return (ch<0||ch>=128)?ch:data_020eacc0[ch];}
typedef struct { char text[9]; } ScanWord9;
typedef struct { char text[5]; } ScanWord5;
#define SCAN_FLOAT_NEXT() do { ++used; ch=read(ctx,0,0); } while(0)


#pragma push
#pragma opt_strength_reduction off
double func_02069048(s32 limit,s32 (*read)(void *,s32,s32),void *ctx,s32 *count,s32 *status){
double func_0206f0dc(void *);double func_02063f90(char *);void *memcpy(void *,const void *,u32);
s32 hexstate=0,used=0,space=0,state=1;
u16 decimal[19]={0};ScanWord9 infcopy;char payload[32];ScanWord9 infinity;u8 hex[8];ScanWord5 nancopy;double packed;u8 *bits=(u8 *)&packed;ScanWord5 nanword;
s32 negative=0,expnegative=0,sign=0,adjust=0,exponent=0,hexexponent=0,hexnegative=0;
u32 hexdigits; s32 nibble=0,i,k,n,ch,upper,shift;u32 j;u8 *hp;char *wordptr;double value;
*status=0;ch=read(ctx,0,0);used++;
infinity=*(const ScanWord9 *)data_020eae6d;nanword=*(const ScanWord5 *)data_020eae68;
while(used<=limit&&ch!=-1&&!(state&0x1800)){
switch(state){
case 1:
 if(ScanFloatClass(ch,256)){ch=read(ctx,0,0);space++;break;}
 switch(ScanFloatUpper(ch)){
 case '-':negative=1;
 case '+':SCAN_FLOAT_NEXT();sign=1;break;
 case 'I':SCAN_FLOAT_NEXT();state=0x4000;break;
 case 'N':SCAN_FLOAT_NEXT();state=0x2000;break;
 default:state=2;break;
 }break;
case 0x4000:
 state=1;infcopy=infinity;wordptr=infcopy.text+1;
 while(state<8&&*wordptr==ScanFloatUpper(ch)){wordptr++;state++;SCAN_FLOAT_NEXT();}
 if(state==3||state==8){if(negative)value=(double)(0.0f-data_021002e8);else value=(double)data_021002e8;*count=space+state+sign;return value;}
 state=0x1000;break;
case 0x2000:{
 nancopy=nanword;state=1;n=0;for(i=0;i<8;i++){payload[i*4]=0;payload[i*4+1]=0;payload[i*4+2]=0;payload[i*4+3]=0;}wordptr=nancopy.text+1;
 while(state<4&&*wordptr==ScanFloatUpper(ch)){wordptr++;state++;SCAN_FLOAT_NEXT();}
 if((u32)(state-3)>1){state=0x1000;break;}
 if(state==4){
 while(n<32&&(ScanFloatClass(ch,8)||ScanFloatClass(ch,1)||ch=='.')){payload[n++]=ch;SCAN_FLOAT_NEXT();}
 if(ch!=')'){state=0x1000;break;}n++;payload[n]=0;
 }
 if(negative)value=0.0-func_02063f90(payload);else value=func_02063f90(payload);*count=space+state+n+sign;return value;}
case 2:
 if(ch=='.'){state=16;SCAN_FLOAT_NEXT();break;}
 if(!ScanFloatClass(ch,8)){state=0x1000;break;}
 if(ch=='0'){SCAN_FLOAT_NEXT();if(ScanFloatUpper(ch)=='X'){state=0x8000;hexstate=1;}else state=4;}
 else state=8;break;
case 4:
 if(ch!='0'){state=8;break;}SCAN_FLOAT_NEXT();break;
case 8:
 if(!ScanFloatClass(ch,8)){if(ch!='.'){state=64;break;}state=32;SCAN_FLOAT_NEXT();break;}
 if(M2C_FIELD(decimal,u8 *,4)>=20)adjust++;else{n=M2C_FIELD(decimal,u8 *,4);M2C_FIELD(decimal,u8 *,4)=n+1;M2C_FIELD(decimal,u8 *,5+n)=ch;}SCAN_FLOAT_NEXT();break;
case 16:state=ScanFloatClass(ch,8)?32:0x1000;break;
case 32:
 if(!ScanFloatClass(ch,8)){state=64;break;}
 n=M2C_FIELD(decimal,u8 *,4);
 if(n<20){if(ch!='0'||n!=0){M2C_FIELD(decimal,u8 *,4)=n+1;M2C_FIELD(decimal,u8 *,5+n)=ch;}adjust--;}
 SCAN_FLOAT_NEXT();break;
case 64:
 if(ScanFloatUpper(ch)!='E'){state=0x800;break;}state=128;SCAN_FLOAT_NEXT();break;
case 128:
 if(ch=='+'){SCAN_FLOAT_NEXT();}else if(ch=='-'){SCAN_FLOAT_NEXT();expnegative=1;}state=256;break;
case 256:
 if(!ScanFloatClass(ch,8)){state=0x1000;break;}
 if(ch!='0'){state=1024;break;}state=512;SCAN_FLOAT_NEXT();break;
case 512:if(ch!='0'){state=1024;break;}SCAN_FLOAT_NEXT();break;
case 1024:
 if(!ScanFloatClass(ch,8)){state=0x800;break;}
 exponent=10*exponent+(ch-'0');if(exponent>32767)*status=1;SCAN_FLOAT_NEXT();break;
case 0x8000:
 switch(hexstate){
 case 1:hp=hex;hp[0]=0;hp[1]=0;hp[2]=0;hp[3]=0;hp[4]=0;hp[5]=0;hp[6]=0;hp[7]=0;hexdigits=0;nibble=0;hexstate=2;SCAN_FLOAT_NEXT();break;
 case 2:if(ch!='0'){hexstate=4;break;}SCAN_FLOAT_NEXT();break;
 case 4:
 if(!ScanFloatClass(ch,1024)){if(ch!='.'){hexstate=16;break;}hexstate=8;SCAN_FLOAT_NEXT();break;}
 if(hexdigits<14){hexdigits++;n=hp[nibble/2];ch=ScanFloatUpper(ch);j=(u8)(ch>='A'?ch-55:ch-48);if(nibble%2==0)n|=(u8)(j<<4);else n|=j;hp[nibble/2]=n;nibble++;}SCAN_FLOAT_NEXT();break;
 case 8:
 if(!ScanFloatClass(ch,1024)){hexstate=16;break;}
 if(hexdigits<14){n=hp[nibble/2];ch=ScanFloatUpper(ch);j=(u8)(ch>='A'?ch-55:ch-48);if(nibble%2==0)n|=(u8)(j<<4);else n|=j;hp[nibble/2]=n;nibble++;}SCAN_FLOAT_NEXT();break;
 case 16:if(ScanFloatUpper(ch)!='P'){state=0x800;break;}hexstate=32;SCAN_FLOAT_NEXT();break;
 case 32:
 if(ch=='-')hexnegative=1;else if(ch!='+'){read(ctx,ch,1);used--;}
 hexstate=64;SCAN_FLOAT_NEXT();break;
 case 64:
 if(!ScanFloatClass(ch,8)){state=0x1000;break;}if(ch!='0'){hexstate=256;break;}hexstate=128;SCAN_FLOAT_NEXT();break;
 case 128:if(ch!='0'){hexstate=256;break;}SCAN_FLOAT_NEXT();break;
 case 256:
 if(!ScanFloatClass(ch,8)){state=0x800;break;}
 hexexponent=10*hexexponent+(ch-'0');if(exponent>32767)*status=1;SCAN_FLOAT_NEXT();break;
 }break;
}
}
if(state==0x8000)i=(used-1<=2||(hexstate&0x18e)==0);else i=(state&0xe2c)==0;
*count=i?0:used-1+space;read(ctx,ch,1);
if(hexstate==0){
 if(expnegative)exponent=-exponent;
 n=M2C_FIELD(decimal,u8 *,4);hp=(u8 *)decimal+5+n;
 while(n--!=0&&*--hp=='0')adjust++;
 M2C_FIELD(decimal,u8 *,4)=n+1;n=(u8)(n+1);
 if(n==0){M2C_FIELD(decimal,u8 *,4)=1;M2C_FIELD(decimal,u8 *,5+n)='0';}
 exponent+=adjust;if(exponent<-32768||exponent>32767)*status=1;
 if(*status){if(expnegative)return 0.0;return negative?0.0-data_021002f0:data_021002f0;}
 M2C_FIELD(decimal,s16 *,2)=exponent;value=func_0206f0dc(decimal);
 if(value!=0.0&&value<2.2250738585072014e-308){*status=1;}else if(value>1.7976931348623157e308){*status=1;value=data_021002f0;}
 if(negative&&(state&0xe2c))value=0.0-value;return value;
}
if(hexnegative)hexexponent=-hexexponent;hexexponent+=hexdigits*4;
for(i=0;i<4&&!(hex[0]&(128>>i));i++)hexexponent--;
shift=i+1;
if(shift){u8 carry=0;for(hp=hex+7;hp>=hex;hp--){n=*hp;*hp=carry|(n<<shift);carry=(u8)(n>>(8-shift));}}
bits[0]=0;bits[1]=0;bits[2]=0;bits[3]=0;bits[4]=0;bits[5]=0;bits[6]=0;bits[7]=0;
for(i=0,j=12,n=0,k=1;(u32)i<52;i+=8,j+=8,n++){u8 b=hex[n];if((u32)(i+8)>52)b=b&(255<<(52-i));bits[k]|=(u8)(b>>(j&7));k++;bits[k]|=(u8)(b<<(8-(j&7)));}
n=hexexponent+1022;if(n&~2047){*status=1;return 0.0;}
bits[1]|=(u32)(n<<21)>>17;bits[0]|=(u32)(n<<21)>>25;if(negative)bits[0]|=128;
for(i=0;i<4;i++){n=bits[i];bits[i]=bits[7-i];bits[7-i]=n;}return *(double *)bits;
}
#pragma pop
