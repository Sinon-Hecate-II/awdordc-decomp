/* 1 function from 0x0206CE00 to 0x0206DF88 (main), found by ds-decomp. */
#include "common.h"
extern double gPowDpHigh[],gPowBp[],gPowDpLow[];
extern float gFloatNanBits;
extern s32 gErrno;
#define POW_HI(x) (((s32 *)&(x))[1])
#define POW_LO(x) (((u32 *)&(x))[0])

#pragma opt_common_subs off
/* fdlibm pow(x,y): x raised to the power y, for the C runtime's double math.
 * It works on the doubles' two 32-bit halves (POW_HI/POW_LO) and performs every
 * arithmetic step through the runtime helpers RuntimeDoubleAdd/Subtract/
 * Multiply/Divide/Sqrt, so it compiles to the same soft-float code.
 * gPowBp, gPowDpHigh and gPowDpLow are fdlibm's bp/dp_h/dp_l constant tables. */
double RuntimeDoublePow(double x,double y) {
double RuntimeDoubleAdd(double,double);double RuntimeDoubleSubtract(double,double);double RuntimeDoubleMultiply(double,double);double RuntimeDoubleDivide(double,double);
double RuntimeDoubleSqrt(double);double Fabs(double);double _f2d(float);double Ldexp(double,s32);
s32 hx=POW_HI(x),hy=POW_HI(y),ix=hx&0x7fffffff,iy=hy&0x7fffffff;
u32 lx=POW_LO(x),ly=POW_LO(y);s32 j; s32 yisint,k,n,i,signFlag;
double z,ax,zh,zl,ph,pl,y1,t1,t2,r,s,t,u,v,w;
double s2,sh,sl,th,tl;
if((iy|ly)==0)return 1.0;
if(ix>0x7ff00000||(ix==0x7ff00000&&lx)||(iy>0x7ff00000)||(iy==0x7ff00000&&ly))return RuntimeDoubleAdd(x,y);
yisint=0;
if(hx<0){
if(iy>=0x43400000)yisint=2;
else if(iy>=0x3ff00000){
k=(iy>>20)-1023;
if(k>20){i=52-k;j=ly>>i;if((j<<i)==ly)yisint=2-(j&1);}
else if(ly==0){i=20-k;j=iy>>i;if((j<<i)==(u32)iy)yisint=2-(j&1);}
}
}
if(ly==0){
if(iy==0x7ff00000){
if(((ix-0x3ff00000)|lx)==0)return RuntimeDoubleSubtract(y,y);
if(ix>=0x3ff00000){if(hy>=0)return y;return 0.0;}
if(hy<0)return RuntimeDoubleSubtract(0.0,y);return 0.0;
}
if(iy==0x3ff00000){if(hy>=0)return x;return RuntimeDoubleDivide(1.0,x);}
if(hy==0x40000000)return RuntimeDoubleMultiply(x,x);
if(hy==0x3fe00000&&hx>=0)return RuntimeDoubleSqrt(x);
}
ax=Fabs(x);
if(lx==0&&(ix==0x7ff00000||ix==0||ix==0x3ff00000)){
z=ax;if(hy<0)z=RuntimeDoubleDivide(1.0,z);
if(hx<0){
if(((ix-0x3ff00000)|yisint)==0)z=RuntimeDoubleDivide(RuntimeDoubleSubtract(z,z),RuntimeDoubleSubtract(z,z));
else if(yisint==1)z=RuntimeDoubleSubtract(0.0,z);
}
return z;
}
signFlag=(hx>>31)+1;
if((signFlag|yisint)==0){gErrno=33;return _f2d(gFloatNanBits);}
if(iy>0x41e00000){
if(iy>0x43f00000){
if(ix<=0x3fefffff){return hy<0?(1.0/0.0):0.0;}
if(ix>=0x3ff00000){return hy>0?(1.0/0.0):0.0;}
}
if(ix<0x3fefffff){return hy<0?(1.0/0.0):0.0;}
if(ix>0x3ff00000){return hy>0?(1.0/0.0):0.0;}
t=RuntimeDoubleSubtract(x,1.0);
w=RuntimeDoubleMultiply(RuntimeDoubleMultiply(t,t),RuntimeDoubleSubtract(0.5,RuntimeDoubleMultiply(t,RuntimeDoubleSubtract(0.33333333333333331,RuntimeDoubleMultiply(0.25,t)))));
u=RuntimeDoubleMultiply(1.4426950216293335,t);v=RuntimeDoubleSubtract(RuntimeDoubleMultiply(1.9259629911266175e-8,t),RuntimeDoubleMultiply(1.4426950408889634,w));
t1=RuntimeDoubleAdd(u,v);POW_LO(t1)=0;t2=RuntimeDoubleSubtract(v,RuntimeDoubleSubtract(t1,u));
}else{
n=0;
if(ix<0x100000){ax=RuntimeDoubleMultiply(ax,9007199254740992.0);n-=53;ix=POW_HI(ax);}
n+=(ix>>20)-1023;j=ix&0xfffff;ix=j|0x3ff00000;
if(j<=0x3988e)k=0;else if(j<0xbb67a)k=1;else {k=0;n++;ix-=0x100000;}
POW_HI(ax)=ix;
u=RuntimeDoubleSubtract(ax,gPowBp[k]);v=RuntimeDoubleDivide(1.0,RuntimeDoubleAdd(ax,gPowBp[k]));
s=RuntimeDoubleMultiply(u,v);sh=s;POW_LO(sh)=0;
th=0.0;POW_HI(th)=((ix>>1)|0x20000000)+0x80000+(k<<18);
tl=RuntimeDoubleSubtract(ax,RuntimeDoubleSubtract(th,gPowBp[k]));
sl=RuntimeDoubleMultiply(v,RuntimeDoubleSubtract(RuntimeDoubleSubtract(u,RuntimeDoubleMultiply(sh,th)),RuntimeDoubleMultiply(sh,tl)));
s2=RuntimeDoubleMultiply(s,s);
r=RuntimeDoubleMultiply(RuntimeDoubleMultiply(s2,s2),RuntimeDoubleAdd(0.59999999999999465,RuntimeDoubleMultiply(s2,RuntimeDoubleAdd(0.42857142857855018,RuntimeDoubleMultiply(s2,RuntimeDoubleAdd(0.33333332981837743,RuntimeDoubleMultiply(s2,RuntimeDoubleAdd(0.27272812380853401,RuntimeDoubleMultiply(s2,RuntimeDoubleAdd(0.23066074577556175,RuntimeDoubleMultiply(0.20697501780033842,s2)))))))))));
r=RuntimeDoubleAdd(r,RuntimeDoubleMultiply(sl,RuntimeDoubleAdd(sh,s)));
s2=RuntimeDoubleMultiply(sh,sh);th=RuntimeDoubleAdd(RuntimeDoubleAdd(3.0,s2),r);POW_LO(th)=0;
tl=RuntimeDoubleSubtract(r,RuntimeDoubleSubtract(RuntimeDoubleSubtract(th,3.0),s2));
u=RuntimeDoubleMultiply(sh,th);v=RuntimeDoubleAdd(RuntimeDoubleMultiply(sl,th),RuntimeDoubleMultiply(tl,s));
ph=RuntimeDoubleAdd(u,v);POW_LO(ph)=0;pl=RuntimeDoubleSubtract(v,RuntimeDoubleSubtract(ph,u));
zh=RuntimeDoubleMultiply(0.96179670095443726,ph);zl=RuntimeDoubleAdd(gPowDpLow[k],RuntimeDoubleAdd(RuntimeDoubleMultiply(-7.0284616509527583e-9,ph),RuntimeDoubleMultiply(0.96179669392597555,pl)));
t=(double)n;
t1=RuntimeDoubleAdd(t,RuntimeDoubleAdd(RuntimeDoubleAdd(zh,zl),gPowDpHigh[k]));POW_LO(t1)=0;
t2=RuntimeDoubleSubtract(zl,RuntimeDoubleSubtract(RuntimeDoubleSubtract(RuntimeDoubleSubtract(t1,t),gPowDpHigh[k]),zh));
}
s=1.0;if((signFlag|(yisint-1))==0)s=-1.0;
y1=y;POW_LO(y1)=0;
pl=RuntimeDoubleAdd(RuntimeDoubleMultiply(t1,RuntimeDoubleSubtract(y,y1)),RuntimeDoubleMultiply(y,t2));ph=RuntimeDoubleMultiply(y1,t1);
z=RuntimeDoubleAdd(pl,ph);j=POW_HI(z);i=POW_LO(z);
if((s32)j>=0x40900000){
if((((s32)j-0x40900000)|i)!=0){return RuntimeDoubleMultiply(1.0e300,RuntimeDoubleMultiply(1.0e300,s));}
if((8.0085662595372941e-17+pl)>(z-ph)){return RuntimeDoubleMultiply(1.0e300,RuntimeDoubleMultiply(1.0e300,s));}
}else if((j&0x7fffffff)>=0x4090cc00){
if((((s32)j-(s32)0xc090cc00)|i)!=0)return RuntimeDoubleMultiply(1.0e-300,RuntimeDoubleMultiply(1.0e-300,s));
if(pl<=RuntimeDoubleSubtract(z,ph))return RuntimeDoubleMultiply(1.0e-300,RuntimeDoubleMultiply(1.0e-300,s));
}
i=j&0x7fffffff;k=(i>>20)-1023;n=0;
if(i>0x3fe00000){
n=j+(0x100000>>(k+1));k=((n&0x7fffffff)>>20)-1023;t=0.0;POW_HI(t)=n&~(0xfffff>>k);
n=((n&0xfffff)|0x100000)>>(20-k);if((s32)j<0)n=-n;ph=RuntimeDoubleSubtract(ph,t);
}
t=RuntimeDoubleAdd(pl,ph);POW_LO(t)=0;
u=RuntimeDoubleMultiply(0.69314718246459961,t);v=RuntimeDoubleAdd(RuntimeDoubleMultiply(0.69314718055994529,RuntimeDoubleSubtract(pl,RuntimeDoubleSubtract(t,ph))),RuntimeDoubleMultiply(-1.9046542999577680e-9,t));
z=RuntimeDoubleAdd(u,v);w=RuntimeDoubleSubtract(v,RuntimeDoubleSubtract(z,u));t=RuntimeDoubleMultiply(z,z);
t1=RuntimeDoubleSubtract(z,RuntimeDoubleMultiply(t,RuntimeDoubleAdd(0.16666666666666602,RuntimeDoubleMultiply(t,RuntimeDoubleAdd(-0.0027777777777015593,RuntimeDoubleMultiply(t,RuntimeDoubleAdd(0.000066137563214379344,RuntimeDoubleMultiply(t,RuntimeDoubleAdd(-0.0000016533902205465252,RuntimeDoubleMultiply(4.1381367970572385e-8,t))))))))));
r=RuntimeDoubleSubtract(RuntimeDoubleDivide(RuntimeDoubleMultiply(z,t1),RuntimeDoubleSubtract(t1,2.0)),RuntimeDoubleAdd(w,RuntimeDoubleMultiply(z,w)));
z=RuntimeDoubleSubtract(1.0,RuntimeDoubleSubtract(r,z));
j=POW_HI(z);j+=n<<20;
if(((s32)j>>20)<=0)z=Ldexp(z,n);else POW_HI(z)+=n<<20;
return RuntimeDoubleMultiply(s,z);
}
#pragma opt_common_subs on
