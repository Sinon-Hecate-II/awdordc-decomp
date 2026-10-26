/* 28 functions from 0x020C3D34 to 0x020C4D28 (main), found by ds-decomp. */
#include "common.h"

void func_020c4604(M2C_UNK arg0){extern u16 *data_02101e84;extern void *data_02164094;
M2C_FIELD(data_02164094,s32*,0)++;
if((M2C_FIELD(data_02164094,s32*,0)<250)&&!(*data_02101e84&1))return;
M2C_FIELD(data_02164094,s32*,4)=0;func_01ffa6fc(arg0);}

void func_020c4658(M2C_UNK arg0){extern void *data_02164094;
M2C_FIELD(data_02164094,s32*,0)++;M2C_FIELD(data_02164094,s32*,4)++;
if(M2C_FIELD(data_02164094,s32*,0)>=250)M2C_FIELD(data_02164094,s32*,0)=250;
if(M2C_FIELD(data_02164094,s32*,4)<64)return;func_01ffa6fc(arg0);}

void func_020c46b4(void){M2C_UNK func_020e35cc(void *);extern void *data_02164094;extern u16 **data_027e00c4;extern u16 **gCur3DSpriteEngine;u16 **temp_r0;
if(data_02164094!=0){func_020e35cc(data_02164094);data_02164094=0;}
temp_r0=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
{u16 *ptr=*gCur3DSpriteEngine;*ptr &=~0x200;}
{u16 *ptr=*gCur3DSpriteEngine;*ptr &=~0x400;}
{u16 *ptr=*gCur3DSpriteEngine;*ptr &=~0x800;}
gCur3DSpriteEngine=temp_r0;}

void func_020c4764(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a3cc;
    func_01ffa42c(&data_0212a3cc, arg0);
}

s32 func_020c477c(s32 arg0) {
 M2C_UNK *func_020c4acc(void);
 s32 func_02032580(void *,s32);
 return func_02032580((u8 *)func_020c4acc()+4,arg0);
}

s32 func_020c4798(void) {
 M2C_UNK *func_020c4b60(void);
 s32 func_02032380(s32);
 s32 temp_r0;
 s32 var_r4;
 s32 var_r5;
 s32 var_r6;
 var_r4=-1;
 temp_r0=(s32)func_020c4b60();
 if(temp_r0==0)return var_r4;
 var_r6=temp_r0+4;
 var_r5=0;
 do {
 if(func_02032380(var_r6)==0){var_r4=var_r5;break;}
 var_r5+=1;var_r6+=12;
 }while(var_r5<60);
 return var_r4;
}

void func_020c47e4(s32 *arg0) {
 s32 func_02084644(void);
 s32 func_02037ca0(s32 *,s32 *);
 s32 a[4];s32 b[3];
 if(func_02084644()!=2)return;
 if(!func_02037ca0(a,b))return;
 arg0[0]=a[0];arg0[1]=a[1];arg0[2]=a[2];arg0[3]=a[3];
 arg0[4]=b[0];arg0[5]=b[1];arg0[6]=b[2];
}

long long func_020c4858(s32 arg0,s32 arg1,s32 arg2) {
 long long func_0200f7e0(s32,s32);
 long long t=func_0200f7e0(arg0,arg0+16);
 return func_0200f7e0(arg1,arg2)-t;
}

void func_020c488c(void *arg0) {
    M2C_UNK func_020c4d64(s32, void *);
    func_020c4c70(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    func_020c4d64(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

void func_020c48b0(void *arg0) {
 if(func_020c4b6c(M2C_FIELD(arg0,s32*,0x34))==0) {
 func_020c4954(M2C_FIELD(arg0,s32*,0x34));
 func_020c4ad8(M2C_FIELD(arg0,s32 **,0x38));
 return;
 }
 func_01ffa8c4(arg0,1);
}

void func_020c48ec(void *arg0) {
    M2C_UNK func_020c5030(s32, void *);
    M2C_UNK func_020c526c(s32, void *);
    func_020c5030(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    func_020c526c(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

void func_020c4910(void) {
 void *func_01ffa3dc(M2C_UNK *,s32);
 extern M2C_UNK data_0212a5cc;
 extern M2C_UNK data_0212a514;
 extern M2C_UNK data_02164098;
 extern M2C_UNK data_02164128;
 void *p=func_01ffa3dc(&data_0212a5cc,7);
 if(p==0)return;
 M2C_FIELD(p,M2C_UNK **,0)=&data_0212a514;
 M2C_FIELD(p,M2C_UNK **,0x34)=&data_02164098;
 M2C_FIELD(p,M2C_UNK **,0x38)=&data_02164128;
}

s32 func_020c4a74(void *arg0) {
 M2C_UNK *func_020c4acc(void);
 void func_020323a4(void *,u32);
 s32 func_020c52ec(s32);
 void func_02031ee4(void);
 void func_0203287c(void *);
 s32 i;
 if(arg0==0)arg0=func_020c4acc();
 func_020323a4((u8*)arg0+4,0x5957324a);
 i=0;
 do {
 if(func_020c52ec(i)!=0)func_02031ee4();
 i++;
 }while(i<60);
 func_0203287c((u8*)arg0+4);
 return 1;
}

M2C_UNK *func_020c4acc(void) {
    extern M2C_UNK data_02164098;
    return &data_02164098;
}

s32 func_020c4ad8(s32 *arg0) {
    M2C_UNK func_02007df8(M2C_UNK, void *, M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    s32 *var_r10;
    void *var_r9;
    s32 var_r8;

    var_r10 = arg0;
    *var_r10 = 0x07090600;
    func_02007f8c(var_r10 + 4, 0, 0x2D0);
    var_r8 = 0;
    var_r9 = var_r10 + 0x2D4;
    do {
        func_02007df8(0, var_r9, 0x1A);
        M2C_FIELD(var_r10, s16 *, 0x2EE) = 0;
        M2C_FIELD(var_r10, s16 *, 0x2F0) = 0;
        M2C_FIELD(var_r10, s16 *, 0x2F2) = 0;
        M2C_FIELD(var_r10, s8 *, 0x2F4) = -1;
        M2C_FIELD(var_r10, s8 *, 0x2F5) = -2;
        var_r8 += 1;
        M2C_FIELD(var_r10, s8 *, 0x2F6) = -2;
        var_r9 += 0x28;
        var_r10 += 0x28;
    } while (var_r8 < 0x3C);
    return 1;
}

M2C_UNK *func_020c4b60(void) {
    extern M2C_UNK data_02164128;
    return &data_02164128;
}

s32 func_020c4b6c(s32 arg0) {
    M2C_UNK func_020323b0(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020323b0(var_r0 + 4);
}

void func_020c4b88(s32 arg0) {
    M2C_UNK func_02032424(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032424(var_r0 + 4);
}

void func_020c4ba4(s32 arg0) {
    M2C_UNK func_020323f4(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020323f4(var_r0 + 4);
}

void func_020c4bc0(s32 arg0) {
    M2C_UNK func_020324e4(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_020324e4(var_r0 + 4);
}

void func_020c4bdc(s32 arg0) {
    M2C_UNK func_02032508(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032508(var_r0 + 4);
}

void func_020c4bf8(void *arg0) {
    extern M2C_UNK data_0212a6a4;
    func_020c4bdc(M2C_FIELD(arg0, s32 *, 0x34));
    func_02076010(2, 1);
    func_02075fd8(M2C_FIELD(arg0, s32 *, 0x34), &data_0212a6a4, 0x90, 2);
    func_02076198();
}

void func_020c4c34(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_020761f8();
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK func_02086680(s32);
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        func_02086680(0xC000034C);
        func_02076244();
    }
    func_01ffa6fc(arg0);
}

M2C_UNK func_020c4c70(s32 arg0,s32 arg1) {
void *func_01ffa3dc(M2C_UNK *,M2C_UNK);
M2C_UNK func_01ffa42c(M2C_UNK *,s32);
extern M2C_UNK data_0212a614,data_0212a550;
s32 var_r5; void *temp_r0; void *temp_r0_2;
var_r5=arg0;
if(var_r5==0)var_r5=(s32)func_020c4acc();
if(arg1!=0){temp_r0=(void *)func_01ffa42c(&data_0212a614,arg1);if(temp_r0==NULL)return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a550;M2C_FIELD(temp_r0,s32*,0x34)=var_r5;return;}
temp_r0_2=func_01ffa3dc(&data_0212a614,3);if(temp_r0_2!=NULL){M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a550;M2C_FIELD(temp_r0_2,s32*,0x34)=var_r5;}
}

void func_020c4cdc(M2C_UNK arg0) {
    M2C_UNK func_020c4c70(M2C_UNK, M2C_UNK);
    func_020c4c70(0, arg0);
}

void func_020c4cf0(void *arg0) {
    M2C_UNK func_02075fd8(s32, M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_02076010(M2C_UNK, M2C_UNK);
    M2C_UNK func_02076198();
    extern M2C_UNK data_0212a6b4;
    func_02076010(3, 1);
    func_02075fd8(M2C_FIELD(arg0, s32 *, 0x34), &data_0212a6b4, 0xC34, 3);
    func_02076198();
}

