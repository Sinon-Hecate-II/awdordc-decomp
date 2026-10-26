/* 8 functions from 0x02068C50 to 0x02069048 (main), found by ds-decomp. */
#include "common.h"

unsigned char *func_02068c50(unsigned char *dst,const unsigned char *src){unsigned char *p=dst;u32 n=(u32)src&3;u32 w,t,z;if(((u32)dst&3)==n){if(n){if(!(*p=*src))return dst;n=3-n;while(n){if(!(*++p=*++src))return dst;--n;}++p;++src;}w=*(const u32*)src;if(!((w+0xfefefeff)&~w&0x80808080)){p-=4;do{*(u32*)(p+=4)=w;src+=4;w=*(const u32*)src;t=w+0xfefefeff;z=~w;}while(!((t&z)&0x80808080));p+=4;}}if(!(*p=*src))return dst;while((*++p=*++src)!=0){}return dst;}

s8 *func_02068d18(s8 *a,s8 *b,s32 n) {
s8 *p=a;
if(n==0) return a;
do {
if((*p++=*b++)==0) {
if(--n==0) return a;
do { *p++=0; } while(--n);
return a;
}
} while(--n);
return a;
}

s8 *func_02068d68(s8 *a,s8 *b) {
s8 *p=a;
while(*p++);
p--;
while((*p++=*b++)!=0);
return a;
}

s32 func_02068eac(u8 *a,u8 *b,s32 n) {
if(n) {
do {
u32 y=*b++;
u32 x=*a++;
if(x!=y) return x-y;
if(x==0) break;
} while(--n);
}
return 0;
}

s8 *func_02068ee0(s8 *a,s32 b) {
s8 c=*a++;
b=(s8)b;
while(c!=0) {
if(c==b) return a-1;
c=*a++;
}
if(b!=0) return 0;
return a-1;
}

s32 func_02068f1c(u8 *a,u8 *b) {
u8 bits[32];
u32 i=8;
u8 *p=bits;
s32 c;
u8 *q;
do {p[0]=0;p[1]=0;p[2]=0;p[3]=0;p+=4;} while(--i);
c=*b;q=b+1;
while(c) {
bits[(s32)(u8)c>>3] |= (u8)(1<<(c&7));
c=*q++;
}
c=*a;q=a+1;
while(c) {
if(bits[(s32)(u8)c>>3] & (u8)(1<<(c&7))) break;
c=*q++;
}
return q-a-1;
}

u8 *func_02068fdc(u8 *a,u8 *b) {
u8 first,c,x,y;
u8 *p,*q,*r;
if(!b || !(first=*b)) return a;
c=*a;
p=a+1;
while(c) {
if(c==first) {
q=p;r=b+1;
do {y=*r++;x=*q++;} while(x==y && x);
if(!y) return p-1;
}
c=*p++;
}
return 0;
}

