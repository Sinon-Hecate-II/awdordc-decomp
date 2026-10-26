/* 27 functions from 0x020C1230 to 0x020C1F58 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_020f4dd0[];

void func_020c1230(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    M2C_UNK func_0209cce4(M2C_UNK *, M2C_UNK);
    s32 func_020c11e4(s32);
    M2C_UNK func_020c1298(s32, M2C_UNK, s32, M2C_UNK);
    extern M2C_UNK func_020c1364;
    if (func_020c11e4(arg0 + (arg2 << 5)) == 0) {
        return;
    }
    func_0209cce4(&func_020c1364, 1);
    func_020c1298(arg0, arg1, arg2, arg3);
}

void func_020c127c(void) {
 void func_0209cd00(void (*)(void)); void func_020c121c(void); void func_020c1d98(void); void func_020c1364(void);
 func_0209cd00(func_020c1364); func_020c121c(); func_020c1d98();
}

M2C_UNK func_020c1298(s32 arg0,M2C_UNK arg1,s32 arg2,M2C_UNK arg3) {
 M2C_UNK func_01ff9e44(M2C_UNK *, s32, M2C_UNK);
 M2C_UNK func_020c1078();
 void func_020c13a8(M2C_UNK);
 M2C_UNK func_020c13c0(M2C_UNK,s32);
 extern M2C_UNK data_0211e18c; extern s32 data_02163f98;
 data_02163f98=arg3;
 func_020c1078();
 func_01ff9e44(&data_0211e18c,arg3<<5,0x20);
 func_020c13a8(arg0+(arg2<<5));
 return func_020c13c0(arg1,(arg2&0x3ff)|(u16)(arg3<<12));
}

void func_020c12f8(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_01ff9e44(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_020c1078();
    M2C_UNK func_020c13c0(M2C_UNK, s32);
    extern M2C_UNK data_0211e18c;
    extern s32 data_02163f98;
    s32 temp_r4;

    data_02163f98 = arg3;
    func_020c1078();
    func_01ff9e44(&data_0211e18c, arg3 << 5, 0x20);
    temp_r4 = arg0 + (arg2 << 5);
    func_020c15ec(temp_r4);
    func_020c1768(temp_r4);
    func_020c13c0(arg1, (arg2 & 0x3FF) | (u16) (arg3 << 0xC));
}

void func_020c1364(void) {
    M2C_UNK func_01ff9e78(void *, s32, M2C_UNK);
    extern s32 data_0211e18c;
    extern s32 data_02163f98;
    extern s32 data_027e15bc;
    
    func_01ff9e78(
        (char *)&data_0211e18c + 0x40 + ((u32)(data_027e15bc & 0x3C) >> 1),
        (data_02163f98 << 5) + 0x1C,
        2
    );
}

void func_020c13a8(M2C_UNK arg0) {
    M2C_UNK func_020c15ec();
    M2C_UNK func_020c1768(M2C_UNK);
    func_020c15ec();
    func_020c1768(arg0);
}

M2C_UNK func_020c13c0(M2C_UNK arg0,s32 arg1) {
 extern void **data_027e0058;
 s32 index=0,y=index,x,row;
 void *base=*data_027e0058;
 s32 height=M2C_FIELD(base,volatile u16 *,0x5146);
 s32 width=M2C_FIELD(base,volatile u16 *,0x5144);
 height=(((height+1)&~1)>>1)<<4;
 width=(width+1)&~1;
 if(height<=0) return;
 width>>=1;
 row=0;
 do {
 for(x=0;x<width;x++) { ((u16 *)arg0)[row+x]=arg1+index++; }
 y+=16; row+=32;
 } while(y<height);
}

M2C_UNK func_020c1768(M2C_UNK p){
u32 func_020d4dac(void);u16 *func_020c10a4(s32,s32,s32);
extern void **data_027e0058;extern u16 data_0216402c[],data_02163fdc[];
s32 x,y,w,z,h;u16 *src,*dst;void *base;z=func_020d4dac();base=*data_027e0058;
h=M2C_FIELD(base,volatile u16 *,0x5146);w=M2C_FIELD(base,volatile u16 *,0x5144);
h=(h+1)&~1;w=(w+1)&~1;
for(y=h>>1;y<h;y++){for(x=0;x<w;x++){src=func_020c10a4(x,y,z);dst=(u16*)p+data_0216402c[x]+data_02163fdc[y];dst[0]=src[0];dst[2]=src[2];dst[4]=src[4];{u16 v=src[6];dst[6]=v;}}}
}

void func_020c183c(void *arg0) {
    M2C_UNK func_01ff9e78(void *, s32, M2C_UNK);
    extern s32 data_0211e18c;
    extern s32 data_027e15bc;
    
    func_01ff9e78(
        (char *)&data_0211e18c + 0x40 + ((u32)(data_027e15bc & 0x3C) >> 1),
        (M2C_FIELD(arg0, s16 *, 0x5A) << 5) + 0x1C,
        2
    );
}

s32 func_020c1980(s32 arg0,s32 arg1,s32 index) {
 s32 sum=0;
 if(index<0) {
 arg1=arg0+arg1;
 for(index=0;index<5;index++,arg1+=12) sum+=*(u8 *)arg1;
 } else {
 arg0+=index*12;
 sum+=*(u8 *)(arg1+arg0);
 }
 return sum;
}

s32 func_020c19c4(s32 a){switch((u32)(a&31)){case 15:return 0;case 16:return 1;case 17:return 2;case 18:return 3;case 19:return 4;case 20:return 5;case 21:return 6;case 22:return 7;case 23:return 9;case 24:return 8;case 25:return 8;case 28:return 10;case 26:return 11;default:return -1;}}

u8 func_020c1a80(void) {
    s32 func_020c19c4();
    u8 var_r0;

    if (func_020c19c4() >= 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c1a9c(s32 a,s32 b){s32 func_020ae22c(s32); func_0208ca2c(a<<5,(u16)b,func_020ae22c(11),1);}

void func_020c1bf0(void *a){extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine; s32 old,i,p,mode; old=gCur3DSpriteEngine;i=0;do{if(i==0)p=data_027e00c8;else p=data_027e00c4;gCur3DSpriteEngine=p;mode=M2C_FIELD(a,s32 *,0x64);if(((mode!=0)||(p==data_027e00c8))&&((mode!=1)||(p==data_027e00c4))&&((mode!=3)||(p==old)))func_020c1a9c(M2C_FIELD(a,s32 *,0x5c),M2C_FIELD(a,s32 *,0x60));i++;}while(i<2);gCur3DSpriteEngine=old;}

void func_020c1c88(void *a){extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine; s32 old,i,p,mode; old=gCur3DSpriteEngine;i=0;do{if(i==0)p=data_027e00c8;else p=data_027e00c4;gCur3DSpriteEngine=p;mode=M2C_FIELD(a,s32 *,0x64);if(((mode!=0)||(p==data_027e00c8))&&((mode!=1)||(p==data_027e00c4))&&((mode!=3)||(p==old)))func_020c1acc(M2C_FIELD(a,s32 *,0x38),M2C_FIELD(a,s32 *,0x3c),M2C_FIELD(a,s32 *,0x5c),M2C_FIELD(a,s32 *,0x60));i++;}while(i<2);gCur3DSpriteEngine=old;}

void func_020c1d28(s32 a,s32 b,s32 c,s32 d) {
 void *func_01ffa3dc(void *,s32);
 extern M2C_UNK data_021296b8;
 extern s32 gCur3DSpriteEngine,data_027e00c8;
 void *p=func_01ffa3dc(&data_021296b8,7);
 M2C_FIELD(p,s32 *,0x38)=a;
 M2C_FIELD(p,s32 *,0x3c)=b;
 M2C_FIELD(p,s32 *,0x5c)=c;
 M2C_FIELD(p,s32 *,0x60)=d;
 M2C_FIELD(p,s32 *,0x64)=((u8)(gCur3DSpriteEngine==data_027e00c8)!=1);
}

void func_020c1d98(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_021296b8;
    func_01ffa9e4(&data_021296b8);
}

u8 func_020c1dac(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

s32 func_020c1dc4(s32 arg0) {
 switch(arg0) {
 case 18:return 0;
 case 19:return 1;
 case 15:return 2;
 case 16:return 3;
 case 17:return 4;
 case 22:return 5;
 case 23:return 6;
 case 20:return 7;
 case 21:return 8;
 default:return 0;
 }
}

u16 func_020c1e48(void) {
    s32 func_020c1dc4();
    return (u16) ((func_020c1dc4() * 0x14) + 0x424);
}

s32 func_020c1e6c(s32 arg0) {
 s32 n=func_020c1dc4(arg0);
 func_020c1dac((s16)n,0,8);
 return data_020f4dd0[n];
}

u16 func_020c1e9c(u32 arg0) {
 switch(arg0) {
 case 0:return 0xffff;
 case 1:arg0=0;break;
 case 2:arg0=1;break;
 case 3:arg0=3;break;
 case 4:arg0=2;break;
 }
 return arg0*4+0x4ec;
}

s32 func_020c1efc(u32 a) { s32 func_020ae22c(s32); switch(a){case 1:return func_020ae22c(2);case 2:return func_020ae22c(4);case 3:return func_020ae22c(5);case 4:return func_020ae22c(0);case 0:default:return 0;}}

