/* 69 functions from 0x020A86F8 to 0x020A94FC (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 values[6]; } Table020a8b3c;
typedef struct { u32 value:8; u32 rest:24; } Bits020a8c10;
extern const Table020a8b3c data_020f49e0;

s32 func_020a86f8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
 s32 func_020a736c(void *, u8, u8);
 s32 func_020a792c(u32, s32, s32, s32);
 s32 func_0207c8ec();
 s32 temp_r0;
 u32 temp_r4;
 s32 var_r0;
 s32 temp_r5;
 temp_r4 = (u32)(arg0[0] << 26) >> 26;
 temp_r5 = func_020a736c(arg0, arg0[1], arg0[2]) + 100;
 temp_r0 = func_020a792c(temp_r4, arg1, arg2, arg3);
 if (temp_r0 == 0) return 0;
 var_r0 = func_0207c8ec(temp_r5 * temp_r0, 100);
 if (var_r0 <= 1) var_r0 = 1;
 return var_r0;
}

s32 func_020a875c(void *arg0) {
    s32 func_020a74a8(void *, u8, u8);
    return func_020a74a8(arg0, M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2)) + 0x64;
}

s32 func_020a8774(u32 arg0) {
 switch(arg0) { case 1: return 5; case 2: return 10; case 3: return 20; default: return 0; }
}

s32 func_020a87b0(u32 arg0) {
 switch(arg0) { case 1: return 0; case 2: return 0; case 3: return 20; default: return 0; }
}

void func_020a87ec(u8 *arg0) {
    M2C_UNK func_020a8774(u32);
    func_020a8774((u32) (*arg0 << 0x18) >> 0x1E);
}

void func_020a8804(u8 *arg0) {
    M2C_UNK func_020a87b0(u32);
    func_020a87b0((u32) (*arg0 << 0x18) >> 0x1E);
}

s32 func_020a881c(s32 arg0) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), u8 *, 0x67B8) * 5;
}

s32 func_020a8844(s32 arg0) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), u8 *, 0x67B8) * 5;
}

s32 func_020a886c(void) {
    return 0;
}

s32 *func_020a8874(a) s32 a; {extern u8 data_ov000_021afe90[];return (s32 *)(80*a+(s32)data_ov000_021afe90);}

s32 func_020a8888(void) {
    s32 *func_020a8874();
    return *func_020a8874();
}

u8 func_020a8898(s32 arg0) {
    if ((arg0 >= 0xE1) && (arg0 < 0x1A9)) {
        return 0U;
    }
    return M2C_FIELD(func_020a8874(), u8 *, 6);
}

u8 func_020a88c4(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 7);
}

s32 func_020a88d4(void) {
    return M2C_FIELD(func_020a8874(), u16 *, 4) & 1;
}

s32 func_020a88e8(void) {
    return M2C_FIELD(func_020a8874(), u16 *, 4) & 2;
}

s32 func_020a88fc(void) {
    return M2C_FIELD(func_020a8874(), u16 *, 4) & 4;
}

s32 func_020a8910(void) {
    return M2C_FIELD(func_020a8874(), u16 *, 4) & 8;
}

s32 func_020a8924(void) {
    return M2C_FIELD(func_020a8874(), u16 *, 4) & 0x10;
}

u8 func_020a8938(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 8);
}

u8 func_020a8948(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 9);
}

u8 func_020a8958(s32 arg0) {
    if ((arg0 >= 0xE1) && (arg0 < 0x1A9)) {
        return 6U;
    }
    return M2C_FIELD(func_020a8874(), u8 *, 0xA);
}

u8 func_020a8984(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 0xB);
}

u8 func_020a8994(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 0xC);
}

u16 func_020a89a4(void) {
    return (u16) (M2C_FIELD(func_020a8874(), u8 *, 0xD) * 0xE10);
}

u16 func_020a89c4(void) {
    return (u16) (M2C_FIELD(func_020a8874(), u8 *, 0xE) * 0x64);
}

u16 func_020a89e4(void) {
    return (u16) (M2C_FIELD(func_020a8874(), u8 *, 0xF) * 0x64);
}

u8 func_020a8a04(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 0x10);
}

u8 func_020a8a14(s32 a,s32 b){u8 *p=(u8*)func_020a8874(a);return M2C_FIELD(p+(b-1),u8 *,60);}

u8 func_020a8a30(s32 a,s32 b){u8 *p=(u8*)func_020a8874(a);return M2C_FIELD(p+(b-1),u8 *,28);}

u8 func_020a8a4c(s32 a,s32 b){u8 *p=(u8*)func_020a8874(a);return M2C_FIELD(p+(b-1),u8 *,32);}

u8 func_020a8a68(s32 a,s32 b){u8 *p=(u8*)func_020a8874(a);return M2C_FIELD(p+(b-1),u8 *,36);}

u8 func_020a8a84(void) {
    return M2C_FIELD(func_020a8874(), u8 *, 0x11);
}

s32 func_020a8a94(s32 a){u8 *p=(u8*)func_020a8874(a);return (p[19]<<8)|p[18];}

u16 func_020a8aac(s32 a,s32 b){u16 *p=(u16*)func_020a8874(a);return M2C_FIELD(p+b,u16 *,20);}

s32 func_020a8ac4(s32 a,s32 b){s32 *p=func_020a8874(a);return M2C_FIELD(p+(b-1),s32 *,40);}

u8 func_020a8ae0(s32 a,s32 b){u8 *p=(u8*)func_020a8874(a);return M2C_FIELD(p+(b-1),u8 *,56);}

s32 func_020a8afc(void) {
    return M2C_FIELD(func_020a8874(), s32 *, 0x40);
}

s32 func_020a8b0c(void) {
    return M2C_FIELD(func_020a8874(), s32 *, 0x44);
}

s32 func_020a8b1c(void) {
    return M2C_FIELD(func_020a8874(), s32 *, 0x48);
}

s32 func_020a8b2c(void) {
    return M2C_FIELD(func_020a8874(), s32 *, 0x4C);
}

s32 func_020a8b3c(s32 a){s32 func_02086680(s32);Table020a8b3c t=data_020f49e0;return func_02086680(t.values[a]);}

M2C_UNK *func_020a8b78(void) {
    extern M2C_UNK data_02126148;
    return &data_02126148;
}

M2C_UNK *func_020a8b84(void) {
    extern M2C_UNK data_0212615c;
    return &data_0212615c;
}

M2C_UNK *func_020a8b90(void) {
    extern M2C_UNK data_02126140;
    return &data_02126140;
}

M2C_UNK *func_020a8b9c(void) {
    extern M2C_UNK data_02126150;
    return &data_02126150;
}

M2C_UNK *func_020a8ba8(void) {
    extern M2C_UNK data_02126154;
    return &data_02126154;
}

M2C_UNK *func_020a8bb4(void) {
    extern M2C_UNK data_02126164;
    return &data_02126164;
}

M2C_UNK *func_020a8bc0(void) {
    extern M2C_UNK data_02126144;
    return &data_02126144;
}

M2C_UNK *func_020a8bcc(void) {
    extern M2C_UNK data_0212614c;
    return &data_0212614c;
}

void func_020a8bd8(s32 a,s32 b){extern s32 *gCurrentMap;s32 *p=(s32 *)(*gCurrentMap+0x67a4+140*a);M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~255)|(b&255);}

u32 func_020a8c10(s32 a){extern s32 *gCurrentMap;return M2C_FIELD(*gCurrentMap+140*a,Bits020a8c10 *,0x6810).value;}

u8 func_020a8c3c(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

s32 func_020a8c54(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

s32 func_020a8c8c(s32 a,s32 b,s32 c,s32 d,s16 e,s16 f){if(a<c || c+e<a)return 0;if(b<d || d+f<b)return 0;return 1;}

u32 func_020a8cc0(u32 arg0) {
    u32 var_r1;

    var_r1 = 0x100;
loop_1:
    if (arg0 >= var_r1) {
        return var_r1;
    }
    var_r1 = (u32) (var_r1 << 0xF) >> 0x10;
    if (var_r1 < 8U) {
        return arg0;
    }
    goto loop_1;
}

s32 func_020a8ce4(s32 arg0, s32 arg1) {
    return (s32) (arg0 * arg1) >> 8;
}

void func_020a8cf0(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5,u16 arg6,u16 arg7,u16 arg8,volatile u16 arg9) {
 M2C_UNK func_02087064(s32,s32,s32,u16,s32);
 M2C_UNK func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 height; s32 flags; s32 scaleY; s32 scaleX; volatile s32 width; volatile s32 z; volatile s32 origin;
 s32 y; s32 dy; s32 tileH; u16 index; s32 remaining; s32 x; s32 tileW; s32 dx;
 width=arg3;z=arg2;origin=arg0;
 if(width && (height=arg4)!=0) {
 remaining=width; index=arg6;
 y=arg1-(func_020a8ce4(height,arg9)>>1);
 scaleX=arg8;flags=arg7;scaleY=arg9;
 do {
 tileH=func_020a8cc0((u16)height);
 x=origin-(func_020a8ce4(width,scaleX)>>1);
 dy=(tileH*scaleY)>>8;
 do {
 tileW=func_020a8cc0((u16)remaining);
 func_02087064(arg5,tileW,tileH,index,flags);
 dx=tileW*scaleX;
 func_020878c4(x,y,z,dx>>8,dy,0,0,tileW,tileH);
 index+=(tileW*tileH)>>6;
 x+=dx>>8;remaining-=tileW;
 }while(remaining);
 remaining=width;height-=tileH;y+=dy;
 }while(height);
 }
}

s32 func_020a8e28(s32 arg0, s32 arg1) {
    return (s32) ((arg0 - ((s32) (arg0 * arg1) >> 8)) << 0xF) >> 0x10;
}

void func_020a8e3c(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 i,s32 j){void func_0208718c();void func_020871a8(s32,s32,s32,s32,s32,u16);s32 px,py,x,y;px=a-(func_020a8ce4(d,g)>>1);py=b-(func_020a8ce4(e,h)>>1);x=func_020a8ce4(d,g);y=func_020a8ce4(e,h);if(i!=256)x=func_020a8ce4(x,i);if(j!=256)y=func_020a8ce4(y,j);func_0208718c();func_020871a8(px,py,c,x,y,(u16)f);}

u8 func_020a8ef8(s32 a){s32 func_020848c4();s32 func_0207c8ec();s32 b;u8 v;if(func_020a8c3c((s16)a,225,425)==0)return 0;b=func_020848c4();if(b==(u8)func_0207c8ec(a-225,50))v=1;else v=0;return v;}

u16 func_020a8f4c(s32 arg0) {
    M2C_UNK func_020846a4();
    s32 func_020848c4();
    u8 func_020a8ef8(s32);
    func_020846a4();
    if (func_020a8ef8(arg0) == 0) {
        return 0xFFFFU;
    }
    return (u16) (arg0 - (func_020848c4() * 0x32));
}

void func_020a8f8c(void *a){s16 v;if(M2C_FIELD(a,u8 *,1))return;switch(M2C_FIELD(a,u8 *,0)){case 1:case 3:case 4:M2C_FIELD(a,u16 *,2)+=M2C_FIELD(a,u16 *,6);v=M2C_FIELD(a,s16 *,12);if(M2C_FIELD(a,u16 *,2)>v)M2C_FIELD(a,u16 *,2)=v;return;case 0:M2C_FIELD(a,u16 *,2)+=M2C_FIELD(a,u16 *,6);return;case 2:return;}}

s16 func_020a8ff4(void *arg0) {
    s32 func_0207c8ec();
    extern M2C_UNK data_020e5b30;
    s16 temp_ip;
    s16 temp_ip_2;
    s16 var_r0;
    s32 temp_r3_2;
    u16 temp_r3;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0);
    switch (temp_r0) {
    case 1:
        if (M2C_FIELD(arg0, s16 *, 0xC) == 0) {
            var_r0 = M2C_FIELD(arg0, s16 *, 8) + (M2C_FIELD(arg0, s16 *, 0x10) * M2C_FIELD(arg0, s16 *, 0xA));
        } else {
            var_r0 = (M2C_FIELD(arg0, s16 *, 0xA) * func_0207c8ec(M2C_FIELD(arg0, u16 *, 2) * (M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xE)), M2C_FIELD(arg0, s16 *, 0xC))) + (M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xE));
        }
        return var_r0;
    case 3:
        temp_ip = M2C_FIELD(arg0, s16 *, 0xC);
        if (temp_ip == 0) {
            return (s16) (M2C_FIELD(arg0, s16 *, 8) + (M2C_FIELD(arg0, s16 *, 0x10) * M2C_FIELD(arg0, s16 *, 0xA)));
        }
        temp_r3 = M2C_FIELD(arg0, u16 *, 2);
        return (s16) ((M2C_FIELD(arg0, s16 *, 0xA) * func_0207c8ec(temp_r3 * (temp_r3 * (M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xE))), temp_ip * temp_ip)) + (M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xE)));
    case 4:
        temp_ip_2 = M2C_FIELD(arg0, s16 *, 0xC);
        temp_r3_2 = temp_ip_2 - M2C_FIELD(arg0, u16 *, 2);
        return (s16) ((M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0x10)) - (M2C_FIELD(arg0, s16 *, 0xA) * func_0207c8ec(temp_r3_2 * (temp_r3_2 * (M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xE))), temp_ip_2 * temp_ip_2)));
    case 0: {
        u16 u = M2C_FIELD(arg0, u16 *, 2);
        s16 a = M2C_FIELD(arg0, s16 *, 0xA);
        s16 base = M2C_FIELD(arg0, s16 *, 8);
        s16 val = *(s16 *)((s8 *)&data_020e5b30 + ((s32)(u >> 4) << 2));
        return (s16)(base + (a * val * 0x10 >> 0x10));
    }
    case 2:
        return (s16) (M2C_FIELD(arg0, s16 *, 8) + (M2C_FIELD(arg0, s16 *, 0xE) * M2C_FIELD(arg0, s16 *, 0xA)));
    }
    return 0;
}

void func_020a9188(void *arg0, u16 arg1) {
    s32 func_0207c8ec();
    M2C_FIELD(arg0, s16 *, 6) = func_0207c8ec(0x10000);
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 4);
}

void func_020a91a8(void *arg0) {
void func_020a8f8c(void *);
void func_020a9218(void *);
u8 *p;
if(M2C_FIELD(arg0,u8 *,14)||M2C_FIELD(arg0,u8 *,15))return;
M2C_FIELD(arg0,u16 *,12)++;
if(M2C_FIELD(arg0,u16 *,12)>=M2C_FIELD(M2C_FIELD(arg0,void **,8),s16 *,0)){
func_020a9218(arg0);
p=M2C_FIELD(arg0,u8 **,8)+12;
M2C_FIELD(arg0,u8 **,8)=p;
if(M2C_FIELD(p,s32 *,4)==-1) M2C_FIELD(arg0,u8 *,15)=1;
}else func_020a8f8c(M2C_FIELD(arg0,void **,0));
}

void func_020a9218(void *arg0) {
void func_020a9188(void *,u16);
void *p=M2C_FIELD(arg0,void **,8);
void *q;
void *obj;
s32 a,b,c,d;
M2C_FIELD(M2C_FIELD(arg0,void **,0),u8 *,0)=M2C_FIELD(p,s32 *,4);
q=M2C_FIELD(arg0,void **,8);
switch(M2C_FIELD(q,u32 *,4)){
case 1:case 3:case 4:
a=M2C_FIELD(p,s16 *,12)-M2C_FIELD(q,s16 *,0);
c=M2C_FIELD(q,s16 *,8);
d=M2C_FIELD(p,s16 *,20);
obj=M2C_FIELD(arg0,void **,0);
M2C_FIELD(obj,s16 *,14)=c;
M2C_FIELD(obj,s16 *,16)=d;
M2C_FIELD(obj,s16 *,12)=a;
M2C_FIELD(obj,u16 *,2)=M2C_FIELD(obj,u16 *,4);
break;
case 0:
func_020a9188(M2C_FIELD(arg0,void **,0),M2C_FIELD(q,u16 *,8));
break;
case 2:
d=M2C_FIELD(p,s16 *,20);
c=M2C_FIELD(q,s16 *,8);
obj=M2C_FIELD(arg0,void **,0);
M2C_FIELD(obj,s16 *,14)=c;
M2C_FIELD(obj,s16 *,16)=d;
M2C_FIELD(obj,s16 *,12)=0;
M2C_FIELD(obj,u16 *,2)=M2C_FIELD(obj,u16 *,4);
break;
}
}

void func_020a92bc(void *arg0,s32 arg1) {
 M2C_UNK func_02007f8c(s32,s32,s32);
 s32 func_0207c928(s32,s32);
 s32 func_0207cb5c(s32,s32);
 s32 func_0207c8ec();
 s32 clamped, n, value, digit; u32 i;
 func_02007f8c((s32)arg0+11,0,6);
 clamped=0xf423f;
 if(arg1<=clamped) {if(arg1 < -clamped)clamped=-clamped;else clamped=arg1;}
 M2C_FIELD(arg0,s32 *,28)=clamped;
 for(n=1;n<=7;n++){
 value=M2C_FIELD(arg0,s32 *,28);
 if(value<0)value=-value;
 if(value<func_0207cb5c(10,n)){M2C_FIELD(arg0,u8 *,10)=n;break;}
 }
 if(!arg1)return;
 for(i=0;(s32)i<M2C_FIELD(arg0,u8 *,10);i++) {
 switch(i){
 case 0:M2C_FIELD(arg0+i,u8 *,11)=func_0207c928(M2C_FIELD(arg0,s32 *,28),10);break;
 case 1:case 2:case 3:case 4:case 5:
 digit=func_0207c928(M2C_FIELD(arg0,s32 *,28),func_0207cb5c(10,i+1));
 M2C_FIELD(arg0+i,u8 *,11)=func_0207c8ec(digit,func_0207cb5c(10,i));break;
 }
 }
}

s16 func_020a93e4(void *arg0,s32 arg1) {
s32 result=0;
s32 count;
s32 base;
u8 step;
switch((u32)(M2C_FIELD(arg0,u8 *,32)<<24)>>29){
case 0:
result=M2C_FIELD(arg0,u8 *,23)*(M2C_FIELD(arg0,u8 *,10)-arg1-1)+M2C_FIELD(arg0,s16 *,6);
break;
case 1:
step=M2C_FIELD(arg0,u8 *,23);
count=M2C_FIELD(arg0,u8 *,10)-1;
base=M2C_FIELD(arg0,s16 *,6)-((step*count+M2C_FIELD(arg0,u8 *,20))>>1);
result=base+step*(count-arg1);
break;
case 2:
base=M2C_FIELD(arg0,u8 *,23)*-arg1-M2C_FIELD(arg0,u8 *,20);
result=base+M2C_FIELD(arg0,s16 *,6);
break;
}
return result;
}

void func_020a947c(void *arg0,u32 arg1) {
extern M2C_UNK data_027e0084,data_027e0064;
switch(arg1){
case 0:case 1:case 2:
M2C_FIELD(arg0,u8 *,20)=8;
M2C_FIELD(arg0,u8 *,21)=8;
M2C_FIELD(arg0,u8 *,23)=8;
M2C_FIELD(arg0,u8 *,24)=8;
M2C_FIELD(arg0,u8 *,22)=1;
M2C_FIELD(arg0,void **,36)=&data_027e0084;
break;
case 3:case 4:case 5:
M2C_FIELD(arg0,u8 *,20)=16;
M2C_FIELD(arg0,u8 *,21)=16;
M2C_FIELD(arg0,u8 *,23)=10;
M2C_FIELD(arg0,u8 *,24)=16;
M2C_FIELD(arg0,u8 *,22)=4;
M2C_FIELD(arg0,void **,36)=&data_027e0064;
break;
}
}

