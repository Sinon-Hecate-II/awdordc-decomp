/* 16 functions from 0x0216EB84 to 0x0216FB7C (ov001), found by ds-decomp. */
#include "common.h"
extern u8 data_ov001_0218ca48[8];
extern u8 *data_ov001_0218fde8;
extern u32 data_ov001_02192790[21];
extern u8 data_ov001_02192c38[8], data_ov001_02192cc4[8];

#pragma thumb on
s32 func_ov001_0216eb84(void *a,s32 b,void *c,s32 d,s32 e){s32 sum=0;u8 *p,*end;s32 start=(s32)a;M2C_FIELD(c,u8 *,0)=0;M2C_FIELD(c,u8 *,1)=0;M2C_FIELD(c,u8 *,2)=0;M2C_FIELD(c,u8 *,3)=0;M2C_FIELD(c,u8 *,4)=0;M2C_FIELD(c,u8 *,5)=0;M2C_FIELD(c,u8 *,6)=0;M2C_FIELD(c,u8 *,7)=0;M2C_FIELD(c,u16 *,0)=((u8)((s32)(u16)(d-8)>>8)|(((u16)(d-8)<<8)&0xff00));if(e){func_ov001_0216f7c4(a+6,c,d,e,16);d+=8;}else func_020651a4(a+6,c,d);M2C_FIELD(a,u8 *,0)=0;M2C_FIELD(a,u8 *,1)=0;M2C_FIELD(a,u8 *,2)=0;M2C_FIELD(a,u8 *,3)=0;M2C_FIELD(a,u8 *,4)=0;M2C_FIELD(a,u8 *,5)=0;M2C_FIELD(a,u16 *,0)=((u8)((s32)(u16)(b)>>8)|(((u16)(b)<<8)&0xff00));M2C_FIELD(a,u16 *,2)=((u8)((s32)(u16)(d)>>8)|(((u16)(d)<<8)&0xff00));end=(u8 *)(start+6+d);for(p=a;p<end;p++)sum+=*p;M2C_FIELD(end,u16 *,0)=((u8)((s32)(u16)(sum)>>8)|(((u16)(sum)<<8)&0xff00));return (s32)(end+2)-(s32)a;}
void *func_ov001_0216ec48(u8 *a,s32 b,void *c,s32 d){s32 n;u16 t;M2C_FIELD(a,u8 *,0)=0;M2C_FIELD(a,u8 *,1)=0;M2C_FIELD(a,u8 *,2)=0;M2C_FIELD(a,u8 *,3)=0;t=b;M2C_FIELD(a,u16 *,0)=((u8)((s32)(u16)(t)>>8)|(((u16)(t)<<8)&0xff00));n=((d+11)&~7)-4;t=d;M2C_FIELD(a,u16 *,2)=((u8)((s32)(u16)(t)>>8)|(((u16)(t)<<8)&0xff00));a=(u8 *)((s32)a+4);func_02065210(a,0,n);func_020651a4(a,c,d);return (void *)((s32)a+n);}

s32 func_ov001_0216eca8(void *a,s32 b,void *c,s32 d){s32 n;M2C_FIELD(a,u8 *,0)=0;M2C_FIELD(a,u8 *,1)=0;M2C_FIELD(a,u8 *,2)=0;M2C_FIELD(a,u8 *,3)=0;M2C_FIELD(a,u8 *,4)=0;M2C_FIELD(a,u8 *,5)=0;M2C_FIELD(a,u8 *,6)=0;M2C_FIELD(a,u8 *,7)=0;n=(u8 *)func_ov001_0216ec48(a+8,b,c,d)-(u8 *)a;M2C_FIELD(a,u16 *,0)=n-8;return n;}

s32 func_ov001_0216ecd0(void *a,s32 *out){s32 kind,len,tag,size; s32 cursor; volatile s32 b; s32 n,base; u16 x,y,t; u16 *p; base=func_ov001_0216ea90(a,&kind,&len);x=0;y=0;cursor=base;b=0;if(!base)return 0;if(kind!=1)return 0;n=len;cursor=8+base; p=(u16 *)func_ov001_0216eb00(&cursor,n+base,&tag,&size);while(p){switch(tag){case 1:t=*p;x=(u8)((s32)t>>8)|((t<<8)&0xff00);break;case 2:t=*p;b=(u16)((u8)((s32)t>>8)|(0xff00&(t<<8)));break;case 5:t=*p;y=(u8)((s32)t>>8)|((t<<8)&0xff00);break;}p=(u16 *)func_ov001_0216eb00(&cursor,n+base,&tag,&size);}if(x!=1||b!=1)return 0;if((s32)y>=1)*out=1;else *out=0;return 1;}

s32 func_ov001_0216eda4(void *a,s32 b,void *c,s32 d){s32 x,n;void *p;p=(void *)func_ov001_0216ea90(a,&x,&n);if(!p)return 0;if(x!=b)return 0;if(d){func_ov001_0216f97c(c,p,n,d,16);n-=8;}else func_020651a4(c,p,n);return n;}

void func_ov001_0216edf4(void *a){u16 buf[5];u32 n;u8 *dst,*src;u8 *p;dst=(u8 *)buf;buf[0]=0x100;src=data_ov001_0218ca48;dst+=2;n=7;do{u8 t=*src;src++;*dst=t;dst++;n--;}while(n!=0);p=func_ov001_0216ec48(data_ov001_0218fde8,1,buf,2);p=func_ov001_0216ec48(p,2,buf,2);if(data_ov001_02192790[20])p=func_ov001_0216ec48(p,5,buf,2);p=func_ov001_0216ec48(p,3,(u8 *)buf+2,7);if(data_ov001_02192790[20])p=func_ov001_0216ec48(p,4,data_ov001_02192c38,6);func_ov001_0216eb84(a,2,data_ov001_02192cc4,p-data_ov001_0218fde8+8,0);}

s32 func_ov001_0216ee90(void){func_02007724();return 1;}

s32 func_ov001_0216f16c(u8 *a,s8 *b,s32 n){s32 c,v,i;v=0;i=v;for(;i<n;i++){c=b[i];switch(c){case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':v+=c-48;break;case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':v+=c-87;break;case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':v+=c-55;break;default:return 0;}if(i%2==0)v<<=4;else{a[i/2]=v;v=0;}}return 1;}

void func_ov001_0216fb34(u8 *a,u8 *b,u8 *c){c[0]=a[0]^b[0];c[1]=a[1]^b[1];c[2]=a[2]^b[2];c[3]=a[3]^b[3];c[4]=a[4]^b[4];c[5]=a[5]^b[5];c[6]=a[6]^b[6];c[7]=a[7]^b[7];}

