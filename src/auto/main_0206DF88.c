/* 16 functions from 0x0206DF88 to 0x0206EEB4 (main), found by ds-decomp. */
#include "common.h"

double func_0206df88(double x,double y) { ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000); return x; }

double func_0206dfb0(double x) { ((u32 *)&x)[1] &= 0x7fffffff; return x; }

double func_0206dfd0(double x,s32 *exp) {
 double func_02070658(double,double);
 s32 hi,word,lo;
 word=((s32 *)&x)[1]; hi=word & 0x7fffffff; *exp=0; lo=((s32 *)&x)[0];
 if(hi>=0x7ff00000 || (hi|lo)==0) return x;
 if(hi<0x100000) { x=func_02070658(x,18014398509481984.0); *exp=-54; word=((s32 *)&x)[1]; hi=word & 0x7fffffff; }
 *exp += (hi>>20)-1022;
 ((u32 *)&x)[1]=(word & 0x800fffff) | 0x3fe00000;
 return x;
}

void func_0206e2d8(void) {
    M2C_UNK func_0206ce00();
    func_0206ce00();
}

s32 func_0206e2e4(u8 *p,s32 i) {
 u8 *q=p+5+i; u8 *end;
 if(*q>5) return 1; if(*q<5) return -1;
 q++; end=p+5+p[4];
 while(q<end) { if(*q!=0)return 1; q++; }
 i--; if(M2C_FIELD(p+i,u8 *,5)&1)return 1; return -1;
}

void func_0206e350(u8 *p,s32 n) {
 u8 *start=p+5; u8 *q=start+n-1;
 do {
 if(*q<9) { ++*q; break; }
 if(q==start) { *q=1; M2C_FIELD(p,s16 *,2) += 1; break; }
 *q--=0;
 } while(1);
}

void func_0206e39c(void) {

}

void func_0206e3a0(u8 *p,s32 n) {
 s32 r;
 if(n<=0)return; if(n>=p[4])return;
 r=func_0206e2e4(p,n); p[4]=n; if(r<0)return;
 func_0206e350(p,n);
}

u64 func_02072088(u64,u64);
u64 func_02072094(u64,u64);
void func_0206e3e0(u8 *p, u64 value) {
    u8 *lo;
    u8 *hi;
    p[0] = 0;
    p[4] = 0;
    while (value) {
        u8 old = p[4];
        p[4] = (u8)(old + 1);
        p[5 + old] = (u8)func_02072094(value, 10ULL);
        value = func_02072088(value, 10ULL);
    }
    lo = p + 5;
    hi = lo + p[4] - 1;
    while (lo < hi) {
        u8 t = *lo;
        *lo++ = *hi;
        *hi-- = t;
    }
    *((s16 *)(p + 2)) = (s16)(p[4] - 1);
}

void func_0206e630(u8 *p,s8 *s,s16 e) {
 s32 n=0;
 M2C_FIELD(p,s16 *,2)=e; p[0]=0;
 while(n<32 && *s) { p[5+n++]=*s++-'0'; }
 p[4]=n;
 if(*s==0)return;
 if(*s<5)return;
 if(*s<=5) {
 {s32 c=s[1]; s++;
 while(c) { if(c!='0')goto round; c=*++s; }}
 n--; if(!(M2C_FIELD(p+n,u8 *,5)&1))return;
 }
round:
 func_0206e350(p,p[4]);
}

s32 func_0206ea50(void *a,void *b){
s32 i,n;u8 x,y,z;
x=M2C_FIELD(a,u8*,5);
if(x==0)return M2C_FIELD(b,u8*,5)==0;
if(M2C_FIELD(b,u8*,5)==0)return x==0;
if(M2C_FIELD(a,s16*,2)==M2C_FIELD(b,s16*,2)){
y=M2C_FIELD(a,u8*,4);z=M2C_FIELD(b,u8*,4);i=0;n=y;
if((s32)y>(s32)z)n=z;
for(;i<n;i++){if(M2C_FIELD(a+i,u8*,5)!=M2C_FIELD(b+i,u8*,5))return 0;}
if(n==y)a=b;
for(;i<M2C_FIELD(a,volatile u8*,4);i++){if(M2C_FIELD(a+i,u8*,5)!=0)return 0;}
return 1;
}
return 0;
}

s32 func_0206eb30(void *arg0,void *arg1){s16 x,y;s32 i,min;s32 b;u32 a;u8 c,d;
if(!M2C_FIELD(arg0,u8 *,5))return M2C_FIELD(arg1,u8 *,5)!=0;
if(!M2C_FIELD(arg1,u8 *,5))return 0;
y=M2C_FIELD(arg1,s16 *,2);x=M2C_FIELD(arg0,s16 *,2);
if(x==y){a=M2C_FIELD(arg0,u8 *,4);b=M2C_FIELD(arg1,u8 *,4);i=0;min=a;if((s32)a>(s32)b)min=b;
if(min>0)do{d=M2C_FIELD(arg1+i,u8 *,5);c=M2C_FIELD(arg0+i,u8 *,5);if(c<d)return 1;if(d<c)return 0;i++;}while(i<min);
if(min==a && i<b){do{if(M2C_FIELD(arg1+i,u8 *,5)!=0)return 1;i++;}while(i<M2C_FIELD(arg1,volatile u8 *,4));}return 0;}return x<y;}

