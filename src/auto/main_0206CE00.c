/* 1 function from 0x0206CE00 to 0x0206DF88 (main), found by ds-decomp. */
#include "common.h"
extern double data_020eb178[],data_020eb188[],data_020eb198[];
extern float data_021002ec;
extern s32 data_0213e9f4;
#define POW_HI(x) (((s32 *)&(x))[1])
#define POW_LO(x) (((u32 *)&(x))[0])

double func_0206ce00(double x,double y) {
double func_02070134(double,double);double func_02070b70(double,double);double func_02070658(double,double);double func_020724f8(double,double);
double func_020709bc(double);double func_0206dfb0(double);double func_0207191c(float);double func_0206f818(double,s32);
s32 hx=POW_HI(x),hy=POW_HI(y),ix=hx&0x7fffffff,iy=hy&0x7fffffff;
u32 lx=POW_LO(x),ly=POW_LO(y);s32 j; s32 yisint,k,n,i,signFlag;
double z,ax,zh,zl,ph,pl,y1,t1,t2,r,s,t,u,v,w,s2,sh,sl,th,tl;
if((iy|ly)==0)return 1.0;
if(ix>0x7ff00000||(ix==0x7ff00000&&lx)||(iy>0x7ff00000)||(iy==0x7ff00000&&ly))return func_02070134(x,y);
yisint=0;
if(hx<0){
if(iy>=0x43400000)yisint=2;
else if(iy>=0x3ff00000){
k=(iy>>20)-1023;
if(k>20){j=ly>>(52-k);if((j<<(52-k))==ly)yisint=2-(j&1);}
else if(ly==0){j=iy>>(20-k);if((j<<(20-k))==(u32)iy)yisint=2-(j&1);}
}
}
if(ly==0){
if(iy==0x7ff00000){
if(((ix-0x3ff00000)|lx)==0)return func_02070b70(y,y);
if(ix>=0x3ff00000){if(hy>=0)return y;return 0.0;}
if(hy<0)return func_02070b70(0.0,y);return 0.0;
}
if(iy==0x3ff00000){if(hy>=0)return x;return func_020724f8(1.0,x);}
if(hy==0x40000000)return func_02070658(x,x);
if(hy==0x3fe00000&&hx>=0)return func_020709bc(x);
}
ax=func_0206dfb0(x);
if(lx==0&&(ix==0x7ff00000||ix==0||ix==0x3ff00000)){
z=ax;if(hy<0)z=func_020724f8(1.0,z);
if(hx<0){
if(((ix-0x3ff00000)|yisint)==0)z=func_020724f8(func_02070b70(z,z),func_02070b70(z,z));
else if(yisint==1)z=func_02070b70(0.0,z);
}
return z;
}
signFlag=(hx>>31)+1;
if((signFlag|yisint)==0){data_0213e9f4=33;return func_0207191c(data_021002ec);}
if(iy>0x41e00000){
if(iy>0x43f00000){
if(ix<=0x3fefffff){return hy<0?(1.0/0.0):0.0;}
if(ix>=0x3ff00000){return hy>0?(1.0/0.0):0.0;}
}
if(ix<0x3fefffff){return hy<0?(1.0/0.0):0.0;}
if(ix>0x3ff00000){return hy>0?(1.0/0.0):0.0;}
t=func_02070b70(x,1.0);
w=func_02070658(func_02070658(t,t),func_02070b70(0.5,func_02070658(t,func_02070b70(0.33333333333333331,func_02070658(0.25,t)))));
u=func_02070658(1.4426950216293335,t);v=func_02070b70(func_02070658(1.9259629911266175e-8,t),func_02070658(1.4426950408889634,w));
t1=func_02070134(u,v);POW_LO(t1)=0;t2=func_02070b70(v,func_02070b70(t1,u));
}else{
n=0;
if(ix<0x100000){ax=func_02070658(9007199254740992.0,ax);n-=53;ix=POW_HI(ax);}
n+=(ix>>20)-1023;j=ix&0xfffff;ix=j|0x3ff00000;
if(j<=0x3988e)k=0;else if(j<0xbb67a)k=1;else {k=0;n++;ix-=0x100000;}
POW_HI(ax)=ix;
u=func_02070b70(ax,data_020eb188[k]);v=func_020724f8(1.0,func_02070134(ax,data_020eb188[k]));
s=func_02070658(u,v);sh=s;POW_LO(sh)=0;
th=0.0;POW_HI(th)=((ix>>1)|0x20000000)+0x80000+(k<<18);
tl=func_02070b70(ax,func_02070b70(th,data_020eb188[k]));
sl=func_02070658(v,func_02070b70(func_02070b70(u,func_02070658(sh,th)),func_02070658(sh,tl)));
s2=func_02070658(s,s);
r=func_02070658(func_02070658(s2,s2),func_02070134(0.59999999999999465,func_02070658(s2,func_02070134(0.42857142857855018,func_02070658(s2,func_02070134(0.33333332981837743,func_02070658(s2,func_02070134(0.27272812380853401,func_02070658(s2,func_02070134(0.23066074577556175,func_02070658(0.20697501780033842,s2)))))))))));
r=func_02070134(r,func_02070658(sl,func_02070134(sh,s)));
s2=func_02070658(sh,sh);th=func_02070134(func_02070134(3.0,s2),r);POW_LO(th)=0;
tl=func_02070b70(r,func_02070b70(func_02070b70(th,3.0),s2));
u=func_02070658(sh,th);v=func_02070134(func_02070658(sl,th),func_02070658(tl,s));
ph=func_02070134(u,v);POW_LO(ph)=0;pl=func_02070b70(v,func_02070b70(ph,u));
zh=func_02070658(0.96179628372192383,ph);zl=func_02070134(data_020eb198[k],func_02070134(func_02070658(-7.0284616509527583e-9,ph),func_02070658(0.96179669392597555,pl)));
t=(double)n;
t1=func_02070134(t,func_02070134(func_02070134(zh,zl),data_020eb178[k]));POW_LO(t1)=0;
t2=func_02070b70(zl,func_02070b70(func_02070b70(func_02070b70(t1,t),data_020eb178[k]),zh));
}
s=1.0;if((signFlag|(yisint-1))==0)s=-1.0;
y1=y;POW_LO(y1)=0;
pl=func_02070134(func_02070658(t1,func_02070b70(y,y1)),func_02070658(y,t2));ph=func_02070658(y1,t1);
z=func_02070134(pl,ph);j=POW_HI(z);i=POW_LO(z);
if((s32)j>=0x40900000){
if((((s32)j-0x40900000)|i)!=0){return func_02070658(1.0e300,func_02070658(1.0e300,s));}
if(func_02070134(pl,8.0085662595372941e-17)>func_02070b70(z,ph)){return func_02070658(1.0e300,func_02070658(1.0e300,s));}
}else if((j&0x7fffffff)>=0x4090cc00){
if((((s32)j-(s32)0xc090cc00)|i)!=0)return func_02070658(1.0e-300,func_02070658(1.0e-300,s));
if(pl<=func_02070b70(z,ph))return func_02070658(1.0e-300,func_02070658(1.0e-300,s));
}
i=j&0x7fffffff;k=(i>>20)-1023;n=0;
if(i>0x3fe00000){
n=j+(0x100000>>(k+1));k=((n&0x7fffffff)>>20)-1023;t=0.0;POW_HI(t)=n&~(0xfffff>>k);
n=((n&0xfffff)|0x100000)>>(20-k);if((s32)j<0)n=-n;ph=func_02070b70(ph,t);
}
t=func_02070134(pl,ph);POW_LO(t)=0;
u=func_02070658(0.69314718246459961,t);v=func_02070134(func_02070658(0.69314718055994529,func_02070b70(pl,func_02070b70(t,ph))),func_02070658(-1.9046542999577680e-9,t));
z=func_02070134(u,v);w=func_02070b70(v,func_02070b70(z,u));t=func_02070658(z,z);
t1=func_02070b70(z,func_02070658(t,func_02070134(0.16666666666666602,func_02070658(t,func_02070134(-0.0027777777777015593,func_02070658(t,func_02070134(0.000066137563214379344,func_02070658(t,func_02070134(-0.0000016533902205465252,func_02070658(4.1381367970572385e-8,t))))))))));
r=func_02070b70(func_020724f8(func_02070658(z,t1),func_02070b70(t1,2.0)),func_02070134(w,func_02070658(z,w)));
z=func_02070b70(1.0,func_02070b70(r,z));
j=POW_HI(z);j+=n<<20;
if(((s32)j>>20)<=0)z=func_0206f818(z,n);else POW_HI(z)=j;
return func_02070658(s,z);
}
