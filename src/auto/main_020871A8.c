/* 17 functions from 0x020871A8 to 0x02088044 (main), found by ds-decomp. */
#include "common.h"

void func_020871a8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    s32 x, y, z;
    s16 b = (s16) arg1, a = (s16) arg0, e = (s16) (arg1 + arg4), c = (s16) arg2, d = (s16) (arg0 + arg3);

    *(volatile u32 *) 0x4000500 = 1;
    *(volatile u32 *) 0x4000480 = arg5;
    x = (u32) (u16) a | ((u32) (u16) b << 0x10);
    *(volatile u32 *) 0x400048C = x;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    y = (u32) (u16) a | ((u32) (u16) e << 0x10);
    *(volatile u32 *) 0x400048C = y;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    z = (u32) (u16) d | ((u32) (u16) e << 0x10);
    *(volatile u32 *) 0x400048C = z;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    x = (u32) (u16) d | ((u32) (u16) b << 0x10);
    *(volatile u32 *) 0x400048C = x;
    *(volatile u32 *) 0x400048C = (u32) (u16) c;
    *(volatile u32 *) 0x4000504 = 0;
    *(volatile u32 *) 0x4000480 = 0x7FFF;
}

void func_0208726c(s32 *x, s32 *y, s32 angle, s32 dist) {
    extern s16 data_020e5b30[];
    s32 i = (angle >> 4) * 2;
    s32 a = data_020e5b30[i];
    s32 b = data_020e5b30[i + 1];
    s32 d = -dist;
    s32 p = -(d * a);
    s32 q = d * b;
    *x = ((p >> 11) & 1) + (p >> 12);
    *y = ((q >> 11) & 1) + (q >> 12);
}

s32 func_020720f0(s32,s32);
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void func_020872c8(s32 x,s32 y,s32 z,s32 r,s32 n,u16 color){s32 px,qx,py,qy,i;*(volatile u32*)0x4000500=0;*(volatile u32*)0x4000480=color;if(n&1) {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=n;i++){func_0208726c(&qx,&qy,(u16)func_020720f0(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}else if(n&2) {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=(n>>1);i++){func_0208726c(&qx,&qy,(u16)func_020720f0(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qx) | ((u32)(u16)(s16)(y-qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-px) | ((u32)(u16)(s16)(y-py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}else {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=(n>>2);i++){func_0208726c(&qx,&qy,(u16)func_020720f0(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qx) | ((u32)(u16)(s16)(y-qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-px) | ((u32)(u16)(s16)(y-py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qy) | ((u32)(u16)(s16)(y+qx)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-py) | ((u32)(u16)(s16)(y+px)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) | (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qy) | ((u32)(u16)(s16)(y-qx)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+py) | ((u32)(u16)(s16)(y-px)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}*(volatile u32*)0x4000504=0;*(volatile u32*)0x4000480=0x7fff;}
#pragma pop
void func_020878c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    u16 temp_r0;
    u16 temp_r10;
    u16 temp_r6;
    u16 temp_lr;
    u16 temp_r7;
    u16 temp_r4;
    u16 temp_r5;
    u16 temp_r2;
    u16 temp_r1;

    *(volatile u32 *) 0x4000500 = 1;
    temp_r0 = (u16) ((s32) (((arg6 << 0xC) + 0x800) << 8) >> 0x10);
    temp_r10 = (u16) ((s32) (((arg5 << 0xC) + 0x800) << 8) >> 0x10);
    temp_r6 = (u16) ((s32) (((arg8 << 0xC) + 0x800) << 8) >> 0x10);
    temp_lr = (u16) ((s32) (((arg7 << 0xC) + 0x800) << 8) >> 0x10);
    temp_r7 = (u16) (s16) arg1;
    temp_r4 = (u16) (s16) arg0;
    temp_r5 = (u16) (s16) (arg1 + arg4);
    temp_r2 = (u16) (s16) (arg0 + arg3);
    *(volatile u32 *) 0x4000488 = temp_r10 | ((u32) temp_r0 << 0x10);
    *(volatile u32 *) 0x400048C = temp_r4 | ((u32) temp_r7 << 0x10);
    temp_r1 = (u16) (s16) arg2;
    *(volatile u32 *) 0x400048C = (u32) temp_r1;
    *(volatile u32 *) 0x4000488 = temp_r10 | ((u32) temp_r6 << 0x10);
    *(volatile u32 *) 0x400048C = temp_r4 | ((u32) temp_r5 << 0x10);
    *(volatile u32 *) 0x400048C = (u32) temp_r1;
    *(volatile u32 *) 0x4000488 = temp_lr | ((u32) temp_r6 << 0x10);
    *(volatile u32 *) 0x400048C = temp_r2 | ((u32) temp_r5 << 0x10);
    *(volatile u32 *) 0x400048C = (u32) temp_r1;
    *(volatile u32 *) 0x4000488 = temp_lr | ((u32) temp_r0 << 0x10);
    *(volatile u32 *) 0x400048C = temp_r2 | ((u32) temp_r7 << 0x10);
    *(volatile u32 *) 0x400048C = (u32) temp_r1;
    *(volatile u32 *) 0x4000504 = 0;
}

void func_02087a08(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 z,s32 t0,s32 t1,s32 t2,s32 t3) {
register u16 vA=(u16)((s32)(((t1<<12)+0x800)<<8)>>16);
u16 v9=(u16)((s32)(((t0<<12)+0x800)<<8)>>16);
register u16 vC=(u16)((s32)(((t3<<12)+0x800)<<8)>>16);
u16 vB=(u16)((s32)(((t2<<12)+0x800)<<8)>>16);
s16 bb=(s16)b,aa=(s16)a,ff=(s16)f,ee=(s16)e,zz=(s16)z,hh=(s16)h,gg=(s16)g,dd=(s16)d,cc=(s16)c;
*(volatile u32*)0x4000500=1;
*(volatile u32*)0x4000488=v9|((u32)vA<<16);
*(volatile u32*)0x400048c=(u16)aa|((u32)(u16)bb<<16);
*(volatile u32*)0x400048c=(u16)zz;
*(volatile u32*)0x4000488=v9|((u32)vC<<16);
*(volatile u32*)0x400048c=(u16)ee|((u32)(u16)ff<<16);
*(volatile u32*)0x400048c=(u16)zz;
*(volatile u32*)0x4000488=vB|((u32)vC<<16);
*(volatile u32*)0x400048c=(u16)gg|((u32)(u16)hh<<16);
*(volatile u32*)0x400048c=(u16)zz;
*(volatile u32*)0x4000488=vB|((u32)vA<<16);
*(volatile u32*)0x400048c=(u16)cc|((u32)(u16)dd<<16);
*(volatile u32*)0x400048c=(u16)zz;
*(volatile u32*)0x4000504=0;
}

void func_020878c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
void func_02087b94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    if (arg9 != 0 && arg10 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg7 - 1, arg8 - 1, arg5 - 1, arg6 - 1);
    } else if (arg9 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg7 - 1, arg6, arg5 - 1, arg8);
    } else if (arg10 != 0) {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg5, arg8 - 1, arg7, arg6 - 1);
    } else {
        func_020878c4(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
}

void func_02087c6c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,u16 f) {
 s32 x,y,z; s16 b=(s16)arg1,a=(s16)arg0,d=(s16)arg3,e=(s16)arg4,c=(s16)arg2;
 
 *(volatile u32 *)0x4000500=0;
 *(volatile u32 *)0x4000480=f;
 x=(u16)a|((u32)(u16)b<<16); z=(u16)e;
 *(volatile u32 *)0x400048c=x;
 *(volatile u32 *)0x400048c=z;
 y=(u16)c|((u32)(u16)d<<16);
 *(volatile u32 *)0x400048c=y;
 *(volatile u32 *)0x400048c=z;
 *(volatile u32 *)0x400048c=x;
 *(volatile u32 *)0x400048c=z;
 *(volatile u32 *)0x4000504=0;
 *(volatile u32 *)0x4000480=0x7fff;
}

#pragma opt_strength_reduction off
void func_02087d18(void *p,s32 a,s32 b,s32 c,u16 d,u16 e,u16 f) {
 u16 *q=M2C_FIELD(p,u16 **,0x14); s32 i; s32 n=M2C_FIELD(p,u16 *,0x10);
 for(i=0;i<n;i++,q+=6) {
 if(q[5]==0) {
 q[0]=a; q[1]=b; q[2]=c; q[3]=d; q[4]=e; q[5]=f;
 M2C_FIELD(p,u8 *,0x12)++; return;
 }
 }
}
#pragma opt_strength_reduction reset
void func_02087d84(void *a,s32 b,s32 c,s32 d,u16 e,u16 f) {void *func_02087e68(void *,s32);u16 *p=func_02087e68(a,(s16)b);p[0]=c;p[1]=d;p[2]=e;p[3]=f;}

void func_02087db8(void *arg0, s32 arg1) {
    s32 var_r2;
    u16 temp_r3;
    void *temp_r0;
    void *var_r0;

    temp_r3 = M2C_FIELD(arg0, u16 *, 0x10);
    var_r0 = M2C_FIELD(arg0, void **, 0x14);
    var_r2 = 0;
    if ((s32) temp_r3 > 0) {
loop_1:
        if (M2C_FIELD(var_r0, u16 *, 8) == arg1) {
            func_02007f8c(var_r0, 0, 0xC);
            M2C_FIELD(arg0, u8 *, 0x12) = (u8) (M2C_FIELD(arg0, u8 *, 0x12) - 1);
        } else {
            var_r2 += 1;
            var_r0 += 0xC;
            if (var_r2 < (s32) temp_r3) {
                goto loop_1;
            }
        }
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0);
    if (temp_r0 == NULL) {
        return;
    }
    if (arg1 == M2C_FIELD(temp_r0, u16 *, 8)) {
        M2C_FIELD(arg0, void **, 0) = NULL;
        M2C_FIELD(arg0, s32 *, 4) = 0;
    }
}

#pragma optimization_level 2
void func_02087e34(void *arg0) { M2C_UNK func_02007f8c(s32,M2C_UNK,s32); M2C_FIELD(arg0,s32 *,0)=0; M2C_FIELD(arg0,s32 *,4)=0; func_02007f8c(M2C_FIELD(arg0,s32 *,0x14),0,M2C_FIELD(arg0,u16 *,0x10)*12); M2C_FIELD(arg0,u8 *,0x12)=0; }
#pragma optimization_level reset
void *func_02087e68(void *a,s32 b) {s32 i;u16 n;u8 *p;n=M2C_FIELD(a,u16 *,16);p=M2C_FIELD(a,u8 **,20);for(i=0;i<(s32)n;i++,p+=12)if(M2C_FIELD(p,u16 *,8)==b)return p;return 0;}

#pragma optimize_for_size off
void func_02087ea0(void *arg0,void *arg1){
if(M2C_FIELD(arg1,u16*,0xA)&4){
u32 zero=0; void *old=M2C_FIELD(arg0,void**,0);
M2C_FIELD(arg0,void**,0)=arg1;
M2C_FIELD(arg0,void**,4)=old;
M2C_FIELD(arg0,s8*,0xF)=zero;
}}
#pragma push
#pragma opt_propagation off
void func_02087ec0(void *a,s32 b){
void *func_02087e68(void*,s32);void func_02087ea0(void*,void*);
if(b==-1){M2C_FIELD(a,s32*,4)=0;M2C_FIELD(a,s32*,0)=0;M2C_FIELD(a,u8*,15)=255;return;}
func_02087ea0(a,func_02087e68(a,b));
}
#pragma pop
void func_02087f00(void *p, s32 id) { void func_02087ec0(void *, s32); func_02087ec0(p, id); M2C_FIELD(p,s32 *,4)=M2C_FIELD(p,s32 *,0); M2C_FIELD(p,u8 *,15)=255; }

s32 func_02087f20(s32 a,void *b,s32 c,s32 d) {s32 x=M2C_FIELD(b,s16 *,0);s32 y;if(c<x || x+M2C_FIELD(b,u16 *,4)<=c)return 0;y=M2C_FIELD(b,s16 *,2);if(d<y || y+M2C_FIELD(b,u16 *,6)<=d)return 0;return 1;}

s32 func_02087f70(void *a,s32 x,s32 y){
s32 left=M2C_FIELD(a,s16*,0x18);
s32 top;u16 n;void *p;s32 i;u16 pad;s16 px,py;
if(x<left || left+M2C_FIELD(a,u16*,0x1c)<=x)return 0;
top=M2C_FIELD(a,s16*,0x1a);
if(y<top || top+M2C_FIELD(a,u16*,0x1e)<=y)return 0;
n=M2C_FIELD(a,u16*,0x10);p=M2C_FIELD(a,void**,0x14);
for(i=0;i<n;i++,p=(u8*)p+12){
if(M2C_FIELD(p,u16*,10)){
pad=M2C_FIELD(a,u16*,0x20);px=M2C_FIELD(p,s16*,0);
if(x<px-pad)continue;
if(px+M2C_FIELD(p,u16*,4)+pad<=x)continue;
py=M2C_FIELD(p,s16*,2);
if(y<py-pad)continue;
if(py+M2C_FIELD(p,u16*,6)+pad>y)return 0;
}}
return 1;
}

