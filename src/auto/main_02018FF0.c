/* 16 functions from 0x02018FF0 to 0x02019E64 (main), found by ds-decomp. */
#include "common.h"
typedef struct Work19334 { s32 (*first)(struct Work19334 *); void (*second)(struct Work19334 *); s32 result; s32 rest[6]; } Work19334;

void func_020191e4(s32 a,s32 b) {
extern s16 data_02136c9c;
if((b&63)==1){data_02136c9c=1;return;}
func_02007958();
}

void func_02019210(s32 a,s32 b) {
void func_0201926c(void);
extern M2C_UNK data_02136ca0;
if((b&63)==17){
s32 result;
if(M2C_FIELD(&data_02136ca0,s32 *,12))return;
result=0;
if(M2C_FIELD(&data_02136ca0,s32 (**)(),24)) result=M2C_FIELD(&data_02136ca0,s32 (**)(),24)();
if(result)func_0201926c();
M2C_FIELD(&data_02136ca0,s32 *,12)=1;
return;
}
func_02007958();
}

void func_0201926c(void) {
    M2C_UNK func_02007958();
    M2C_UNK func_02018ea4(M2C_UNK);
    func_02018ea4(2);
    func_02007958();
}

void func_02019280(void) {
    extern M2C_UNK data_02136ca0;
    M2C_FIELD(&data_02136ca0, s32 *, 4) = 0;
}

void func_02019294(M2C_UNK a) {
void func_02019320(M2C_UNK);
extern s32 data_02136e68;
extern M2C_UNK data_02136e6c,data_02137290;
void func_02019334();
s32 func_0200751c(void);
void func_02007530(s32);
void func_02005ac0(M2C_UNK,void (*)(void),M2C_UNK,void *,s32,s32);
s32 saved=func_0200751c();
if(!data_02136e68){
data_02136e68=a;
func_02019320(a+0xc4);
func_02019320((s32)&data_02136e6c);
M2C_FIELD(a,s32 *,0xc0)=0;
func_02005ac0(a,func_02019334,a,&data_02137290,0x400,20);
func_02005e5c(a);
}
func_02007530(saved);
}

void func_02019320(M2C_UNK arg0) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x24);
}

void func_02019334(void *arg0) {
extern s32 data_02136e68;
s32 func_0200751c(void); void func_02007530(s32);
void func_02005da4(s32); void func_02005bbc(void);
u32 saved; Work19334 w; void (*second)(Work19334 *);
do {
func_02007f8c((s32)&w,0,0x24);
saved=func_0200751c();
while(!M2C_FIELD(arg0,Work19334 * volatile *,0xc0)) func_02005da4(0);
w=*M2C_FIELD(arg0,Work19334 **,0xc0);
func_02007530(saved);
if(w.first) w.result=w.first(&w);
saved=func_0200751c();
second=w.second;
M2C_FIELD(&data_02136e68,u8 *,0x26)=0;
if(second) second(&w);
if(!data_02136e68) break;
M2C_FIELD(arg0,Work19334 **,0xc0)=0;
func_02007530(saved);
} while(1);
func_02005bbc();
}

s8 *func_02019424(s8 *dst,volatile s8 *src) {
s8 *saved=dst;
if(*src) do { *dst++=*src; } while(*++src);
*dst=0;
return saved;
}

s32 func_02019458(s8 *a,s8 *b,s32 n) {
 s32 i; s8 *p;
 p=b;i=0;
 for(;i<n-1;i++,p++) { a[i]=*p; if(*p==0)break; }
 if(i>=n-1 && n!=0)a[i]=0;
 return func_020194b8(b);
}

s32 func_020194b8(s8 *arg0) {
    s32 var_r2;

    var_r2 = 0;
    if (*arg0 != 0) {
        do {
            var_r2 += 1;
        } while (*(arg0 + var_r2) != 0);
    }
    return var_r2;
}

s32 func_020194e0(s8 *a,s8 *b) {
 s32 x,y;
 for(; (y=*b,x=*a)==(s32)y && x!=0; a++,b++) {}
 return x-y;
}

void func_0201950c(void *arg0, s8 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        *M2C_FIELD(arg0, s8 **, 4) = arg1;
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) - 1);
    }
    M2C_FIELD(arg0, s8 **, 4) = (s8 *) (M2C_FIELD(arg0, s8 **, 4) + 1);
}

void func_0201953c(void *p,s8 v,s32 n) {
 u32 i,len;
 if(n<=0)return;
 len=M2C_FIELD(p,u32*,0);i=0;
 if(len>(u32)n)len=n;
 for(;i<len;i++)M2C_FIELD(p,s8**,4)[i]=v;
 M2C_FIELD(p,u32*,0)-=len;
 M2C_FIELD(p,s8**,4)+=n;
}

void func_02019590(void *p,s8 *s,s32 n) {
 u32 i,len;
 if(n<=0)return;
 len=M2C_FIELD(p,u32*,0);i=0;
 if(len>(u32)n)len=n;
 for(;i<len;i++)M2C_FIELD(p,s8**,4)[i]=s[i];
 M2C_FIELD(p,u32*,0)-=len;
 M2C_FIELD(p,s8**,4)+=n;
}

