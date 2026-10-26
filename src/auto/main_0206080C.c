/* 57 functions from 0x0206080C to 0x020617BC (main), found by ds-decomp. */
#include "common.h"

void func_0206080c(void *arg0) {
    u32 func_02049208();
    M2C_UNK func_02060104(void *);
    u32 temp_r5;
    void *temp_r3;

    temp_r5 = func_02049208();
    if (M2C_FIELD(arg0, void **, 8) == NULL) {
        return;
    }
loop_3:
    if (temp_r5 <= (u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x1C) + 0x9C4)) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 0x15) = (u8) (M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 0x15) | 0x10);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x1C) = 0x9C4;
    temp_r3 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(temp_r3, u8 *, 0x15) = (u8) (M2C_FIELD(temp_r3, u8 *, 0x15) & 0xD3);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK, void *, s32), 0x44)(arg0, 1, M2C_FIELD(arg0, void **, 8), M2C_FIELD(arg0, s32 *, 0x48));
    func_02060104(arg0 + 8);
    if (M2C_FIELD(arg0, void **, 8) == NULL) {
        return;
    }
    goto loop_3;
}

void func_0206089c(void *arg0) {
    M2C_UNK func_02060104(void *);
    M2C_UNK func_020601b8(void *, void *);

    while ((s32) M2C_FIELD(arg0, s32 *, 0x10) < (s32) M2C_FIELD(arg0, s32 *, 4) && (s32) M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
        func_020601b8(arg0, func_02060104(arg0 + 0x14));
    }
}

void func_020608dc(void *arg0) {
    M2C_UNK func_02060678(void *, s32);

    if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
        return;
    }
    func_02060678(arg0, 0);
    func_0206080c(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
        func_0206089c(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(void *, s32, s32, M2C_UNK), 0x44)(arg0, 2, 0, M2C_FIELD(arg0, M2C_UNK *, 0x48));
}

void func_0206093c(void *arg0, s8 arg1) {
    s32 temp_r3;

    temp_r3 = M2C_FIELD(arg0, s32 *, 0x40);
    if (temp_r3 >= 0x14) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_r3 + 1);
    M2C_FIELD((arg0 + temp_r3), s8 *, 0x2C) = arg1;
}

void func_0206095c(void *arg0, M2C_UNK arg1) {
    s32 func_02060138(void *, M2C_UNK);

    if (func_02060138(arg0 + 8, arg1) != 0) {
        return;
    }
    func_02060138(arg0 + 0x14, arg1);
}

void func_02060988(s8 **arg0, s32 arg1) {
    s32 func_02060fe8(s8 *, s32);

    func_02060fe8(*arg0, arg1);
}

void func_02060998(s32 *arg0, s32 *arg1) {
    M2C_UNK func_0206f8ac(s32, s32);
    func_0206f8ac(*arg0, *arg1);
}

void func_020609ac(s32 *arg0) {
    M2C_UNK func_020377c4(s32);
    func_020377c4(*arg0);
}

s32 func_020609bc(void) {
    extern M2C_UNK data_0213e4b0;
    s32 func_02048c84(s32, s32, s32, void *, void *, void *);
    if (M2C_FIELD(&data_0213e4b0, s32 *, 8) == 0) {
        M2C_FIELD(&data_0213e4b0, s32 *, 8) = func_02048c84(8, 0x64, 2, func_02060988, func_02060998, func_020609ac);
    }
    return M2C_FIELD(&data_0213e4b0, s32 *, 8);
}

void func_02060a20(void) {
    extern M2C_UNK data_0213e4b0;
    s32 func_02048e38(s32);
    M2C_UNK func_02048dc4(s32);
    if (M2C_FIELD(&data_0213e4b0, s32 *, 8) == 0) return;
    if (func_02048e38(M2C_FIELD(&data_0213e4b0, s32 *, 8)) != 0) return;
    func_02048dc4(M2C_FIELD(&data_0213e4b0, s32 *, 8));
    M2C_FIELD(&data_0213e4b0, s32 *, 8) = 0;
}

void func_02060a60(void **arg0) {
    M2C_UNK func_02048dc4(s32);
    void *temp_r4;

    temp_r4 = *arg0;
    func_02048dc4(M2C_FIELD(temp_r4, s32 *, 0x18));
    M2C_FIELD(temp_r4, s32 *, 0x18) = 0;
    func_020377c4(temp_r4);
}

M2C_UNK func_02060a84(M2C_UNK arg0, M2C_UNK *arg1, M2C_UNK *arg2) {
    s32 func_02061cb4(s32, M2C_UNK *);
    M2C_UNK func_02048eac(s32, s32 *);
    s32 values[2];
    values[0] = func_02061cb4(0, arg1);
    values[1] = func_02061cb4(0, arg2);
    func_02048eac(M2C_FIELD(arg0, s32 *, 0x18), values);
}

void func_02060ac4(M2C_UNK a,M2C_UNK *b){
 M2C_UNK func_020675e4(void *,void *);
 extern M2C_UNK data_02100060;
 u8 buf[20];
 func_020675e4(buf,&data_02100060);
 func_02060a84(a,b,(M2C_UNK *)buf);
}

s32 func_02060afc(void *arg0,s32 arg1,s32 arg2){
 void *func_02048ff8(s32,s32 *);
 M2C_UNK func_020640a8(void *,void *,void *,s32);
 extern M2C_UNK data_02100064,data_0210006c,data_02100048;
 s32 sp0[2]; void *temp_r0;
 if(!arg0)func_020640a8(&data_02100064,&data_0210006c,&data_02100048,0x97);
 if(!arg0)return 0;
 sp0[0]=arg1;temp_r0=func_02048ff8(M2C_FIELD(arg0,s32 *,0x18),sp0);
 if(temp_r0)arg2=M2C_FIELD(temp_r0,s32 *,4);
 return arg2;
}

s32 func_02060b68(void *arg0,s32 arg1,s32 arg2){
 s32 func_02068d98(s32,void *);
 s32 func_0206ad38(void *);
 extern M2C_UNK data_02100078; extern u16 data_020ead40[];
 s8 *p,*q; u8 c; s32 v;
 if(!arg0)return arg2;
 if(!func_02068d98(arg1,&data_02100078))return func_02061088(arg0);
 p=(s8 *)func_02060afc(arg0,arg1,0);
 if(!p)return arg2;
 if(*p!='-')q=p;else q=p+1;
 c=*(u8 *)q;
 if((s32)c<0 || (s32)c>=128)v=0;
 else v=data_020ead40[c]&8;
 if(!v)return arg2;
 return func_0206ad38(p);
}

double func_02060c10(void *arg0,s32 arg1,double arg2){
 double func_0206a374(s32);
 s32 p=func_02060afc(arg0,arg1,0);
 if(p)arg2=func_0206a374(p);
 return arg2;
}

s32 func_02060c44(s32 *arg0) {
    return *arg0;
}

u16 func_02060c4c(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 4);
    return (u16) ((u8) ((s32) temp_r0 >> 8) | ((temp_r0 << 8) & 0xFF00));
}

u16 func_02060c70(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 4);
}

s32 func_02060c78(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x15) & 2) == 2) {
        return 1;
    }
    return 0;
}

s32 func_02060c90(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

u16 func_02060c98(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 0xC);
    return (u16) ((u8) ((s32) temp_r0 >> 8) | ((temp_r0 << 8) & 0xFF00));
}

void func_02060cbc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}

s32 func_02060cc4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x20);
}

s32 func_02060ccc(M2C_UNK *arg0){
 s32 func_02068d98(s32,void *);
 extern void *data_020eac38[2];
 void *sp0[2]; void **arr=sp0; u32 i;
 sp0[0]=data_020eac38[0];sp0[1]=data_020eac38[1];
 for(i=0;i<2;i++){if(!func_02068d98((s32)arg0,arr[i]))return 0;}
 return 1;
}

M2C_UNK *func_02060d2c(s32 input,s32 arg1){
 extern M2C_UNK data_0213e4b0;
 s8 *arg0=(s8 *)input;
 s32 c; s8 *p;
 if(arg0)M2C_FIELD(&data_0213e4b0,s8 **,0)=arg0;
 arg0=M2C_FIELD(&data_0213e4b0,s8 **,0);p=arg0;
 while((c=*p)!=0 && c!=arg1){p++;M2C_FIELD(&data_0213e4b0,s8 **,0)=p;}
 if(p==arg0)arg0=0;
 if(c==0)return arg0;
 {s8 *next=M2C_FIELD(&data_0213e4b0,s8 **,0);*p=0;M2C_FIELD(&data_0213e4b0,s8 **,0)=next+1;}
 return arg0;
}

void func_02060d90(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_02060a84(M2C_UNK, M2C_UNK *, M2C_UNK *);
    s32 func_02060ccc(M2C_UNK *);
    M2C_UNK *func_02060d2c(s32, M2C_UNK);
    extern M2C_UNK data_02100080;
    M2C_UNK *var_r8;
    M2C_UNK *var_r9;

    var_r8 = func_02060d2c(arg1 + 1, 0x5C);
    if (var_r8 == NULL) {
        return;
    }
    do {
        var_r9 = func_02060d2c(0, 0x5C);
        if (var_r9 == NULL) {
            var_r9 = &data_02100080;
        }
        if (func_02060ccc(var_r8) != 0) {
            func_02060a84(arg0, var_r8, var_r9);
        }
        var_r8 = func_02060d2c(0, 0x5C);
    } while (var_r8 != NULL);
}

#pragma push
#pragma optimize_ifs off
s32 func_02060fe8(s8 *arg0, s32 arg1) {
    extern u8 data_020eac40[];
    s64 func_020722fc(s32, s32);
    s32 hash;
    s32 c;

    hash = 0;
    c = *arg0;
    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = data_020eac40[c];
            }
            hash = hash * 0x9CCF9319 + c;
            c = *++arg0;
        } while (c != 0);
    }
    return func_020722fc(hash, arg1) >> 32;
}
#pragma pop
void func_02061040(void *arg0) {
    M2C_UNK func_02061d24(M2C_UNK, s32);
    func_02061d24(0, M2C_FIELD(arg0, s32 *, 0));
    func_02061d24(0, M2C_FIELD(arg0, s32 *, 4));
}

void func_02061064(s8 **arg0, s32 arg1) {
    s32 func_02060fe8(s8 *, s32);

    func_02060fe8(*arg0, arg1);
}

void func_02061074(s32 *arg0, s32 *arg1) {
    func_0206f8ac(*arg0, *arg1);
}

s32 func_02061088(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x1C);
}

void *func_02061090(s32 arg0,s32 arg1,s32 arg2){
 void *func_02037794(s32);M2C_UNK func_020377c4(s32);
 s32 func_02048c84(s32,s32,s32,void *,void *,void *);
 void *temp_r0=func_02037794(0x24);
 if(!temp_r0)return 0;
 M2C_FIELD(temp_r0,s32 *,0x18)=func_02048c84(8,8,4,func_02061064,func_02061074,func_02061040);
 if(!M2C_FIELD(temp_r0,s32 *,0x18)){func_020377c4((s32)temp_r0);return 0;}
 M2C_FIELD(temp_r0,u8 *,0x14)=0;M2C_FIELD(temp_r0,u8 *,0x15)=0;
 M2C_FIELD(temp_r0,s32 *,0x20)=0;M2C_FIELD(temp_r0,s32 *,0x1c)=0;
 M2C_FIELD(temp_r0,s32 *,0x10)=0;M2C_FIELD(temp_r0,s32 *,0)=arg1;
 M2C_FIELD(temp_r0,u16 *,4)=arg2;M2C_FIELD(temp_r0,s32 *,8)=0;
 M2C_FIELD(temp_r0,u16 *,12)=0;return temp_r0;
}

void func_0206113c(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x15) = arg1;
}

void func_02061144(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xC) = arg2;
}

void func_02061150(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
}

void func_02061158(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x14) = arg1;
}

u8 func_02061160(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x14);
}

s32 func_02061168(s32 arg0) {
    extern M2C_UNK data_0213e4b0;
    if (arg0 == M2C_FIELD(&data_0213e4b0, s32 *, 4)) {
        return 1;
    }
    return 0;
}

void func_0206133c(s32 arg0,s32 arg1,void *arg2,void *arg3){
 switch(arg1){
 case 1:M2C_FIELD(arg3,M2C_UNK (**)(void *,s32,void *,s32),0x630)(arg3,2,arg2,M2C_FIELD(arg3,s32 *,0x634));break;
 case 0:M2C_FIELD(arg3,M2C_UNK (**)(void *,s32,void *,s32),0x630)(arg3,1,arg2,M2C_FIELD(arg3,s32 *,0x634));break;
 case 2:M2C_FIELD(arg3,M2C_UNK (**)(void *,s32,void *,s32),0x630)(arg3,4,arg2,M2C_FIELD(arg3,s32 *,0x634));break;
 }
 if(!arg2)return;
 if(M2C_FIELD(arg2,s32 *,0)!=M2C_FIELD(arg3,s32 *,0x628))return;
 if(M2C_FIELD(arg2,u16 *,4)==M2C_FIELD(arg3,u16 *,0x62c))M2C_FIELD(arg3,s32 *,0x628)=0;
}

void *func_020613dc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    void *func_02037794(s32);
    M2C_UNK func_02060398(void *, s32, s32, s32, M2C_UNK *, void *);
    M2C_UNK func_02061dd0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, M2C_UNK *, void *);
    extern s32 data_0213db84;
    extern M2C_UNK func_02061184;
    void func_0206133c(s32, s32, void *, void *);
    void *obj;

    if ((arg6 == 0) && (data_0213db84 != 1)) {
        return NULL;
    }
    obj = func_02037794(0x638);
    if (obj == NULL) {
        return NULL;
    }
    M2C_FIELD(obj, s32 *, 0x630) = arg7;
    M2C_FIELD(obj, s32 *, 0x634) = arg8;
    M2C_FIELD(obj, s32 *, 0x624) = 0;
    func_02061dd0(obj + 0x4C, arg0, arg1, arg2, arg3, arg6, &func_02061184, obj);
    func_02060398(obj, arg4, arg5, arg6, (M2C_UNK *)&func_0206133c, obj);
    return obj;
}

void func_020614b0(s32 arg0) {
    M2C_UNK func_02060430(s32);
    M2C_UNK func_02062738(s32);
    func_02062738(arg0 + 0x4C);
    func_02060430(arg0);
    func_020377c4(arg0);
}

void func_02061604(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g){
 void func_020614d4(s32,s32,s32,s32,s32,s32,s32,s32);
 func_020614d4(a,b,c,d,e,f,128,g);
}

void func_02061638(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_02063aa8(s32, s32, u16, M2C_UNK, s32);
    func_02063aa8(arg0 + 0x4C, func_020498e4(arg1), (u16) ((u8) (arg2 >> 8) | ((arg2 << 8) & 0xFF00)), arg3, arg4);
}

void func_02061690(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    s32 func_020498e4(M2C_UNK);
    M2C_UNK func_02063bd0(s32, s32, u16, M2C_UNK);
    func_02063bd0(arg0 + 0x4C, func_020498e4(arg1), (u16) ((u8) (arg2 >> 8) | ((arg2 << 8) & 0xFF00)), arg3);
}

void func_020616d8(s32 arg0){
 s32 func_02061a74(s32); M2C_UNK func_02061b6c(s32,s32);
 s32 n=func_02061a74(arg0+0x4c);
 if(n==-1)return;
 func_02061b6c(arg0+0x4c,n);
}

void func_02061704(s32 arg0) {
    M2C_UNK func_02063dac(s32);

    func_020608dc((void *) arg0);
    func_02063dac(arg0 + 0x4C);
}

M2C_UNK func_0206171c(void *p){
 M2C_UNK func_020626d4(void *);M2C_UNK func_02060414(void *);
 func_020626d4((u8 *)p+0x4c);func_02060414(p);
}

void func_02061738(s32 arg0) {
    M2C_UNK func_0206171c();
    M2C_UNK func_02061c34(s32);
    func_0206171c();
    func_02061c34(arg0 + 0x4C);
}

s32 func_02061750(void *arg0){
 s32 n;
 if(M2C_FIELD(arg0,s32 *,0x10)>0)return 2;
 n=M2C_FIELD(arg0,s32 *,0x4c);
 if(n==3 || n==0)return 1;
 if(n==1)return 0;
 return 3;
}

void func_02061784(s32 arg0) {
    M2C_UNK func_02061bc8(s32);
    func_02061bc8(arg0 + 0x4C);
}

void func_02061794(s32 arg0) {
    M2C_UNK func_02061bb8(s32);
    func_02061bb8(arg0 + 0x4C);
}

void func_020617a4(s32 arg0) {
    M2C_UNK func_020619c0(s32);
    func_020619c0(arg0 + 0x4C);
}

s32 func_020617b4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4EC);
}

