/* 10 functions from 0x0203BE54 to 0x0203CB38 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma scheduling off
s8 func_0203be54(s8 arg0, s32 arg1, s32 arg2) {
    s32 func_02037694(M2C_UNK, s32);
    M2C_UNK func_020376d8(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK func_02068c34(s32);
    M2C_UNK func_02068c50(M2C_UNK, s32);
    s32 func_02068d98(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 data_0213d3bc[];
    extern u8 data_0213d3bd[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 data_0213d3c4[];
    s32 var_r5;
    s32 var_r6;
    s8 var_r7;
    u32 temp_r4;
    s32 temp_r0;

    var_r6 = arg1;
    var_r5 = arg2;
    var_r7 = arg0;
    if (var_r6 == 0 || var_r5 == 0) {
        return 0;
    }
    if ((u32) var_r7 >= 0x64U && data_0213d3bc[(var_r7 - 0x64) * 0xC] != 0) {
        u32 off = (var_r7 - 0x64) * 0xC;
        if (*((volatile s32 *)(data_0213d3c0 + off)) != 0 && func_02068d98() != 0) {
            return 0;
        }
    } else {
        var_r7 = func_020427b4();
        if ((u32) var_r7 == 0) {
            return 0;
        }
    }
    temp_r4 = (var_r7 - 0x64) * 0xC;
    data_0213d3bc[temp_r4] = var_r7;
    data_0213d3bd[temp_r4] = 0;
    *((u16 *)(data_0213d3be + temp_r4)) = 0;
    if (*((volatile s32 *)(data_0213d3c0 + temp_r4)) != 0) {
        func_020376d8(4);
    }
    temp_r0 = func_02037694(4, func_02068c34(var_r6) + 1);
    *((volatile s32 *)(data_0213d3c0 + temp_r4)) = temp_r0;
    if (temp_r0 == 0) {
        func_0203dc38(9, 0xFFFEC77F);
        return 0;
    }
    func_02068c50(temp_r0, var_r6);
    *((volatile s32 *)(data_0213d3c4 + temp_r4)) = var_r5;
    func_0205fdbc(var_r7, *((volatile s32 *)(data_0213d3c0 + temp_r4)));
    return var_r7;
}
#pragma pop
s8 func_0203bf80(u32 arg0, s32 arg1, s32 arg2) {
    s32 func_02037694(M2C_UNK, s32);
    M2C_UNK func_020376d8(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK func_02068c34(s32);
    M2C_UNK func_02068c50(M2C_UNK, s32);
    s32 func_02068d98(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 data_0213d3bc[];
    extern u8 data_0213d3bd[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 data_0213d3c4[];
    s32 var_r6;
    s32 var_r5;
    u32 var_r7;
    s32 temp_r4;
    u8 *var_r8;
    s32 temp_r0;
    s32 temp_r3;

    var_r6 = arg1;
    var_r5 = arg2;
    var_r7 = arg0;
    if (var_r6 != 0 && var_r5 != 0) {
        if (var_r7 >= 0x64U) {
            temp_r3 = (var_r7 - 0x64) * 0xC;
            if (data_0213d3bc[temp_r3] != 0) {
                if (*((s32 *)(data_0213d3c0 + temp_r3)) != 0 && func_02068d98() != 0) {
                    return 0;
                }
                goto block_11;
            }
        }
        var_r7 = (u32) func_020427b4();
        if (var_r7 == 0) {
            return 0;
        }
    block_11:
        temp_r4 = (var_r7 - 0x64) * 0xC;
        data_0213d3bc[temp_r4] = (s8) var_r7;
        data_0213d3bd[temp_r4] = 1;
        *((u16 *)(data_0213d3be + temp_r4)) = 0;
        if (*((s32 *)(data_0213d3c0 + temp_r4)) != 0) {
            func_020376d8(4);
        }
        temp_r0 = func_02037694(4, func_02068c34(var_r6) + 1);
        var_r8 = data_0213d3c0;
        *((s32 *)(var_r8 + temp_r4)) = temp_r0;
        if (temp_r0 == 0) {
            func_0203dc38(9, 0xFFFEC77F);
            return 0;
        }
        func_02068c50(temp_r0, var_r6);
        *((s32 *)(data_0213d3c4 + temp_r4)) = var_r5;
        func_0205fdbc((s8) var_r7, *((s32 *)(var_r8 + temp_r4)));
        return (s8) var_r7;
    }
    return 0;
}

s32 func_0203c0b0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0203761c();
    void *func_02044268();
    s32 func_02060b68(s32, M2C_UNK, s32);
    s32 func_02061784(s32, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = arg2;
    if ((func_02044268() == NULL) || (func_0203761c() != 0)) {
        return var_r4;
    }
    temp_r0 = func_02061784(M2C_FIELD(func_02044268(), s32 *, 0xE4), arg0);
    if (temp_r0 != 0) {
        var_r4 = func_02060b68(temp_r0, arg1, var_r4);
    }
    return var_r4;
}

void func_0203c110(s32 arg0,s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g) {
void *func_02044268(void);s32 func_02044278(s32);
void func_02044258(s32);void func_020427f4(void);void func_0203e570(s32);
void func_02007f8c(void *,s32,s32);
extern M2C_UNK data_0213d39c;
void *p;
func_02044258(arg0);
M2C_FIELD(func_02044268(),s32 *,0)=a;
M2C_FIELD(func_02044268(),s32 *,4)=b;
M2C_FIELD(func_02044268(),s32 *,8)=c;
M2C_FIELD(func_02044268(),s32 *,16)=0;
M2C_FIELD(func_02044268(),s32 *,28)=0;
M2C_FIELD(func_02044268(),u16 *,26)=0;
M2C_FIELD(func_02044268(),s32 *,228)=0;
func_02044278(0);
M2C_FIELD(func_02044268(),u8 *,15)=0;
M2C_FIELD(func_02044268(),u8 *,25)=0;
M2C_FIELD(func_02044268(),u8 *,431)=0;
M2C_FIELD(func_02044268(),u16 *,438)=0;
M2C_FIELD(func_02044268(),s32 *,476)=0;
M2C_FIELD(func_02044268(),s32 *,512)=0;
M2C_FIELD(func_02044268(),s32 *,756)=d;
M2C_FIELD(func_02044268(),s32 *,760)=e;
M2C_FIELD(func_02044268(),s32 *,764)=f;
M2C_FIELD(func_02044268(),s32 *,768)=g;
func_02007f8c((u8 *)func_02044268()+0x304,0,64);
M2C_FIELD(func_02044268(),s32 *,836)=0;
M2C_FIELD(func_02044268(),s32 *,1124)=0;
M2C_FIELD(func_02044268(),s32 *,1128)=0;
M2C_FIELD(func_02044268(),s32 *,1140)=0;
M2C_FIELD(func_02044268(),s32 *,1144)=0;
M2C_FIELD(func_02044268(),s32 *,1148)=0;
M2C_FIELD(func_02044268(),s32 *,1152)=0;
p=func_02044268();
M2C_FIELD(p,s32 *,0x174)=0;M2C_FIELD(p,s32 *,0x178)=0;
func_020427f4();
M2C_FIELD(&data_0213d39c,u8 *,0x1c)=0;
M2C_FIELD(&data_0213d39c,u8 *,0x1d)=0;
M2C_FIELD(&data_0213d39c,u16 *,0x1e)=0;
func_0203e570(0);
}

s32 func_0203c28c(s32 arg0){
void *func_02044268(void);
s32 func_0205b030(s32);s32 func_0205b048(s32);
s32 func_0205e670(void*,s32,s32,s32,s32,s32,s32,void*,void*,void*,void*,void*,void*,s32);
extern s32 func_02043a24,func_02043b6c,func_02043b70,func_02043b74,func_02043c18,func_02043c20,func_02043c2c,func_02043c4c,func_02043d00;
s32 i,result,a,b;void *p,*q;
if(M2C_FIELD(func_02044268(),s32*,16))return 0;
M2C_FIELD(func_02044268(),s32*,512)=arg0;
for(i=0;i<5;i++){
p=func_02044268();
a=func_0205b048(*M2C_FIELD(func_02044268(),s32**,4));
b=func_0205b030(*M2C_FIELD(func_02044268(),s32**,4));
q=func_02044268();
result=func_0205e670((u8*)p+16,a,b,M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(func_02044268(),s32*,0x2f8),1,1,&func_02043a24,&func_02043b6c,&func_02043b70,&func_02043b74,&func_02043c18,&func_02043c20,0);
if(!result)break;
func_0205eacc(M2C_FIELD(func_02044268(),s32*,16));
M2C_FIELD(func_02044268(),s32*,16)=0;
if(result!=3 || i==4){func_0204309c(result);return result;}
}
M2C_FIELD(func_02044268(),s32*,28)=0;
M2C_FIELD(func_02044268(),s16*,26)=0;
func_0205e864(M2C_FIELD(func_02044268(),s32*,16),&func_02043c2c);
func_0205e834(M2C_FIELD(func_02044268(),s32*,16),&func_02043c4c);
func_0205e84c(M2C_FIELD(func_02044268(),s32*,16),&func_02043d00);
func_0205ea70(M2C_FIELD(func_02044268(),s32*,16));
return result;
}

void func_0203c428(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5){
void *func_02044268(void);s32 func_02044278(s32);
s32 func_0203e908(s32,s32,M2C_UNK,M2C_UNK);
s32 func_0203ec48(void*,s32,s32,s32);
s32 func_02068c34(s32);s32 func_02037694(s32,s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK*,s32);
s32 func_02043008(s32);
extern M2C_UNK data_0213d39c,data_020fc8fc,data_020fc904,func_020432d4;
u8 text[256]; s32 len;void *p,*q,*r,*t; s32 value; void *state=&data_0213d39c;
value=M2C_FIELD(state,s32*,8);
if(value){func_020376d8(4,value,0);M2C_FIELD(&data_0213d39c,s32*,8)=0;}
if(arg1){
len=func_0203ec48(text,-1,32,3);
len=256-len-func_02068c34((s32)&data_020fc8fc);
value=func_02037694(4,len);
M2C_FIELD(&data_0213d39c,s32*,8)=value;
if(!value){func_0203dc38(9,0xfffec77f);return;}
func_02008048(arg1,value,len);
((u8*)M2C_FIELD(&data_0213d39c,void**,8)+len)[-1]=0;
}
func_0203e908(0,arg0,arg2,arg3);
M2C_FIELD(func_02044268(),s32*,0x474)=arg4;
M2C_FIELD(func_02044268(),s32*,0x478)=arg5;
func_02044278(2);
if(!M2C_FIELD(func_02044268(),s32*,0xe4)){
t=func_02044268();q=func_02044268();r=func_02044268();
M2C_FIELD(t,s32*,0xe4)=func_020613dc(M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(r,s32*,0x2f4),M2C_FIELD(func_02044268(),s32*,0x2f8),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(func_02044268(),s32*,0xe4)&&func_02043008(5))return;
func_0203af50(3,&data_020fc904,0);
if(func_02043008(func_0203ea4c(M2C_FIELD(func_02044268(),s32*,0x200))))return;
if(!M2C_FIELD(func_02044268(),s32*,16))func_0203c28c(M2C_FIELD(func_02044268(),s32*,512));
func_02042af8(0);
}

void func_0203c878(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_0203c28c(s32);
    M2C_UNK func_0203e410();
    M2C_UNK func_0203e908(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02042f94();
    M2C_UNK func_02044278(M2C_UNK);
    extern M2C_UNK data_0213d39c;
    void *temp_r4;

    func_0203e908(2, arg0, arg1, arg2);
    M2C_FIELD(func_02044268(), s32 *, 0x46C) = arg3;
    M2C_FIELD(func_02044268(), s32 *, 0x470) = arg4;
    temp_r4 = func_02044268();
    M2C_FIELD(temp_r4, s32 *, 0xF4) = (s32) M2C_FIELD(func_02044268(), s32 *, 0x200);
    M2C_FIELD(func_02044268(), s32 *, 0x2F0) = 1;
    M2C_FIELD(func_02044268(), s8 *, 0xE) = 0;
    M2C_FIELD(&data_0213d39c, s8 *, 0x1D) = 0;
    func_02044278(0xA);
    func_0203e410();
    if (func_02042f94() != 0) {
        return;
    }
    if (M2C_FIELD(func_02044268(), s32 *, 0x10) != 0) {
        return;
    }
    func_0203c28c(M2C_FIELD(func_02044268(), s32 *, 0x200));
}

void func_0203c920(s32 arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3,s32 arg4) {
s32 func_02044268(void);
s32 func_02044278(s32);
s32 func_0203e908(s32,s32,M2C_UNK,M2C_UNK);
M2C_UNK func_0203af50(M2C_UNK,M2C_UNK *,M2C_UNK);
M2C_UNK func_0204084c(void);
M2C_UNK func_02040878(s32,M2C_UNK);
s32 func_02043008(M2C_UNK);
s32 func_02042f94(void);
s32 func_0203c28c(s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK *,s32);
extern M2C_UNK data_020fc904,func_020432d4;
void *p,*q,*r,*t;
func_0203e908(3,0,arg1,arg2);
M2C_FIELD(func_02044268(),s32 *,0x46c)=arg3;
M2C_FIELD(func_02044268(),s32 *,0x470)=arg4;
M2C_FIELD(func_02044268(),u8 *,0x17)=1;
p=func_02044268();
M2C_FIELD(p,s32 *,0x20)=M2C_FIELD(func_02044268(),s32 *,0x200);
M2C_FIELD(func_02044268(),s32 *,0xf4)=arg0;
func_02044278(4);
if(!M2C_FIELD(func_02044268(),s32 *,0xe4)){
t=func_02044268();q=func_02044268();r=func_02044268();
M2C_FIELD(t,s32 *,0xe4)=func_020613dc(M2C_FIELD(q,s32 *,0x2f4),M2C_FIELD(r,s32 *,0x2f4),M2C_FIELD(func_02044268(),s32 *,0x2f8),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(func_02044268(),s32 *,0xe4)&&func_02043008(5))return;
func_0203af50(5,&data_020fc904,0);
if(func_02042f94())return;
if(!M2C_FIELD(func_02044268(),s32 *,0x10)&&func_0203c28c(M2C_FIELD(func_02044268(),s32 *,0x200)))return;
func_02040878(M2C_FIELD(func_02044268(),s32 *,0xf4),0);
if(func_0204084c())return;
}

void func_0203ca88(void *arg0) {
    M2C_UNK func_0205e87c();
    M2C_UNK func_0205ea70(s32);
    u32 temp_r0_2;
    u8 temp_r0;

    if (arg0 == NULL) {
        return;
    }
    func_0205e87c();
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(func_02044268(), u8 *, 0x15);
    switch (temp_r0) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
        temp_r0_2 = M2C_FIELD(func_02044268(), u32 *, 0x1A0);
        switch (temp_r0_2) {                        /* switch 2 */
        default:                                    /* switch 2 */
            return;
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
        case 4:                                     /* switch 2 */
        case 6:                                     /* switch 2 */
        case 11:                                    /* switch 2 */
            func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
            return;
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        if (M2C_FIELD(func_02044268(), s32 *, 0x1A0) != 0xB) {
            return;
        }
        func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
        return;
    }
}

