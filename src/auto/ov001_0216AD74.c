/* 14 functions from 0x0216AD74 to 0x0216BD08 (ov001), found by ds-decomp. */
#include "common.h"

#pragma thumb on
u32 func_ov001_0216b87c(u32 a,u32 b) {u32 t=a&b; b=~b; a=((a&b)+1)|t; if(a>=(b|t)) a=1|t; return a;}

void func_ov001_0216b894(void) {
extern u32 data_ov001_02191800[];
void func_ov001_0216ad64(u32);
if(data_ov001_02191800[3]) {func_ov001_0216ad64(data_ov001_02191800[3]);data_ov001_02191800[3]=0;}
if(data_ov001_02191800[1]) {func_ov001_0216ad64(data_ov001_02191800[1]);data_ov001_02191800[1]=0;}
}

s32 func_ov001_0216bb28(u8 *p,s32 n) {s32 i; for(i=0;i<n;i++){u32 c=*p++;if(c<32||c>127)return -1;}return 0;}

#pragma thumb on
s32 func_ov001_0216bb4c(u32 *arg0) {
s32 func_ov001_0216cdb4(void *,M2C_UNK *,s32);
s32 func_ov001_0216cf08(M2C_UNK *);
extern M2C_UNK data_ov001_0218fda4;
s32 result;
u32 n;
s32 matches;
s32 i;
u8 *p;
u8 *text;
p=(u8 *)arg0;
matches=0;
result=0;
n=*(u32 *)p;
if(n==0)return 5;
if(n>64)n=64;
i=0;
if((s32)n>0) {
text=p+8;
do {
if((M2C_FIELD(p,u32 *,0x54)&1) && M2C_FIELD(p,s32 *,4)==func_ov001_0216cf08(&data_ov001_0218fda4) && !func_ov001_0216cdb4(text,&data_ov001_0218fda4,func_ov001_0216cf08(&data_ov001_0218fda4)))matches++;
i++;p+=0x54;text+=0x54;
}while(i<(s32)n);
}
if(matches>1)result=4;
if(matches==0)result=5;
return result;
}

#pragma thumb on
s32 func_ov001_0216bbc8(void *p) {
extern M2C_UNK data_ov001_0218fda4;
extern M2C_UNK data_ov001_0218fdb0;
s32 func_ov001_0216cf08(M2C_UNK *);
M2C_UNK func_ov001_0216cdd4(void *,M2C_UNK *,s32);
u32 n;
M2C_FIELD(p,u32 *,0)=func_ov001_0216cf08(&data_ov001_0218fda4);
func_ov001_0216cdd4((u8 *)p+4,&data_ov001_0218fda4,M2C_FIELD(p,u32 *,0));
M2C_FIELD(p,u32 *,0x24)=1;
n=M2C_FIELD(p,u32 *,0x28)=func_ov001_0216cf08(&data_ov001_0218fdb0);
if(n>13)return -1;
func_ov001_0216cdd4((u8 *)p+0x2c,&data_ov001_0218fdb0,n);
return 0;
}
void func_ov001_0216bc0c(s32 n,void *p,M2C_UNK *src) {
M2C_UNK func_ov001_0216cdd4(void *,M2C_UNK *,s32);
u16 func_ov001_0216ceb0(u16);
u16 func_ov001_0216cf1c(void);
s32 i;
for(i=0;i<n;i++,p=(u8 *)p+8) {
func_ov001_0216cdd4(p,src,6);
M2C_FIELD(p,u16 *,6)=func_ov001_0216cf1c();
M2C_FIELD(p,u16 *,6)=func_ov001_0216ceb0(M2C_FIELD(p,u16 *,6));
}
}

s32 func_ov001_0216bc68(s32 a,void *b,s32 *c,s32 d) {
s32 func_ov001_0216bd08(s32,void *,s32 *,s32);
s32 func_ov001_0216bde4(s32,void *,s32 *,s32);
s32 func_ov001_0216bebc(s32,void *,s32 *,s32);
s32 func_ov001_0216bf60(void *);
u32 func_ov001_0216cef0(u16);
void *p=(u8 *)b+12;
if(func_ov001_0216cef0(M2C_FIELD(b,u16 *,12))<1U){++*c;return a;}
if(M2C_FIELD(p,u8 *,15)!=17){++*c;return a;}
if(func_ov001_0216bf60((u8 *)b+12)>0){++*c;return a;}
switch(func_ov001_0216cef0(M2C_FIELD(p,u16 *,6))) {
case 0x1010:a=func_ov001_0216bd08(a,b,c,d);break;
case 0x2010:a=func_ov001_0216bde4(a,b,c,d);break;
case 0x3010:a=func_ov001_0216bebc(a,b,c,d);break;
}
return a;
}
#pragma thumb off

#pragma thumb off

