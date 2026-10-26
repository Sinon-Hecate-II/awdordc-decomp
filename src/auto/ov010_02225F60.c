/* 41 functions from 0x02225F60 to 0x02226D9C (ov010), found by ds-decomp. */
#include "common.h"

s32 func_ov010_02225f60(void){
extern M2C_UNK data_ov010_0222ee70, data_ov010_0222ee98, data_ov010_0222ee78;
void func_ov010_02225e50(); void func_ov010_02225f54();
s32 func_ov010_02229a08(); s32 func_ov010_02225cd8(s32); s32 func_ov010_02225640(void*);
void func_ov010_02228b50(); void func_ov010_02222c9c(); void func_ov010_02225d00(); void func_ov010_02225d64(); s32 func_ov010_02229bf4(); void func_ov010_02222c28();
if(M2C_FIELD(&data_ov010_0222ee70,s32*,0)!=0)return 1;
M2C_FIELD(&data_ov010_0222ee70,s32*,0)=func_ov010_022260f4(0x6b40,32);
M2C_FIELD(&data_ov010_0222ee70,s32*,16)=1;
M2C_FIELD(&data_ov010_0222ee70,void**,8)=&data_ov010_0222ee98;
M2C_FIELD(&data_ov010_0222ee70,s32*,12)=2;
M2C_FIELD(&data_ov010_0222ee70,u8*,20)=func_ov010_02229a08();
M2C_FIELD(&data_ov010_0222ee70,void**,32)=func_ov010_02225e50;
M2C_FIELD(&data_ov010_0222ee70,s32*,36)=0;
M2C_FIELD(&data_ov010_0222ee70,s32*,24)=M2C_FIELD(&data_ov010_0222ee70,s32*,0);
M2C_FIELD(&data_ov010_0222ee70,s32*,28)=0x6b40;
if(!func_ov010_02225cd8(0x6b40))return 0;
if(!func_ov010_02225640(&data_ov010_0222ee78))return 0;
func_ov010_02228b50(func_ov010_02225f54);
func_ov010_02222c9c(1);
M2C_FIELD(&data_ov010_0222ee70,s32*,4)=0;
func_ov010_02225d00();func_ov010_02225d64();
if(func_ov010_02229bf4())func_ov010_02226060(0);
func_ov010_02222c28(1);return 1;
}

void func_ov010_02226054(void) {
    M2C_UNK func_ov010_022257a0();
    func_ov010_022257a0();
}

s32 func_ov010_02226060(s32 arg0) {
    s32 func_ov010_02223ec8(s32);
    void func_ov010_02223ef0(s32);
    s32 func_ov010_0222405c(s32, s32);
    extern M2C_UNK data_ov010_0222ee70;
    s32 temp_r4;
    if (M2C_FIELD(&data_ov010_0222ee70, s32 *, 4) == 0) {
        temp_r4 = func_ov010_02223ec8(arg0);
        if (temp_r4 == 0) return 0;
        if (func_ov010_0222405c(temp_r4, 0) != 0) {
            func_ov010_02223ef0(temp_r4);
            return 0;
        }
        M2C_FIELD(&data_ov010_0222ee70, s32 *, 4) = temp_r4;
    }
    return 1;
}

void func_ov010_022260b8(void) {
    void func_ov010_02225d38();
    void func_ov010_02225db8();
    void func_ov010_02228b50(s32);
    void func_ov010_02225778();
    void func_ov010_02226100();
    extern M2C_UNK data_ov010_0222ee70;
    func_ov010_02225d38();
    func_ov010_02225db8();
    func_ov010_02228b50(0);
    func_ov010_02225778();
    func_ov010_02226100(M2C_FIELD(&data_ov010_0222ee70, s32 *, 0), M2C_FIELD(&data_ov010_0222ee70, s32 *, 0x1C));
    M2C_FIELD(&data_ov010_0222ee70, s32 *, 0) = 0;
}

s32 func_ov010_022260f4() {
    M2C_UNK func_020e3580();
    func_020e3580();
}

void func_ov010_02226100(s32 arg0) {
    M2C_UNK func_020e35cc();
    if (arg0 == 0) {
        return;
    }
    func_020e35cc();
}

M2C_UNK func_ov010_02226114(M2C_UNK arg0) {
    s32 func_ov010_022261f4(void);
    extern s32 data_ov010_0222eec8;
    func_ov010_022261f4();
    data_ov010_0222eec8 = arg0;
}

void func_ov010_02226130(void) {
    M2C_UNK func_020459ec();
    func_020459ec();
}

s32 func_ov010_0222613c(void) {
    s32 func_ov010_022282b4(M2C_UNK);
    void func_ov010_02226204();
    u8 *func_020c4acc();
    s32 func_02045458(M2C_UNK *, u8 *);
    M2C_UNK func_ov010_02226114(M2C_UNK);
    M2C_UNK **func_01ffa3dc(M2C_UNK *, s32);
    void func_ov010_02228298(M2C_UNK);
    extern M2C_UNK data_ov010_0222c0e8;
    extern M2C_UNK data_ov010_0222c0c0;
    extern M2C_UNK data_ov010_0222c054;
    s32 var_r4;
    u32 temp_r0;
    M2C_UNK **temp_r0_2;

    var_r4 = 1;
    if (func_ov010_022282b4(5) != 0) return 1;
    func_ov010_02226204();
    temp_r0 = func_02045458(&data_ov010_0222c0e8, func_020c4acc() + 4);
    switch (temp_r0) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        var_r4 = 0;
        break;
    case 5:
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    }
    if ((temp_r0 != 0) && (temp_r0 != 3)) {
        func_ov010_02226114(temp_r0);
    } else {
        temp_r0_2 = func_01ffa3dc(&data_ov010_0222c0c0, 3);
        if (temp_r0_2 != NULL) {
            *temp_r0_2 = &data_ov010_0222c054;
        }
        func_ov010_02228298(5);
    }
    return var_r4;
}

s32 func_ov010_022261f4(void) {
    extern s32 data_ov010_0222eec8;
    return data_ov010_0222eec8;
}

void func_ov010_02226204(void) {
    M2C_UNK func_ov010_02226114(M2C_UNK);
    func_ov010_02226114(0);
}

s32 func_ov010_02226214(s32 a,s32 b,s32 c,s32 d,s32 e){
s32 func_02037ca0(M2C_UNK *,M2C_UNK *); s64 func_020c4858(s32,M2C_UNK *,M2C_UNK *); s32 func_02085c18(); u32 func_0204563c(s32,s32,s32,s32,s32);
M2C_UNK date[4]; M2C_UNK time[3]; s32 result; u32 status;
result=1;
if(func_02037ca0(date,time)!=0)func_020c4858(func_02085c18(),date,time);
status=func_0204563c(a,b,c,d,e);
switch(status){default:break;case 1:result=0;break;case 7:result=0;break;case 2:result=0;break;case 8:result=0;break;case 9:result=0;break;}
if(status!=0)func_ov010_02226114(status);
return result;
}

s32 func_ov010_022262e0(void) {
    M2C_UNK func_02085c04();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c04();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 3:
    case 4:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 func_ov010_02226334(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, void *arg5) {
    s32 func_01ffa42c(M2C_UNK *, s32);
    s32 func_ov010_02226214(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern M2C_UNK data_ov010_0222c080;
    if (func_ov010_02226214(arg0, arg1, arg2, arg3, arg4) == 0) {
        return 0;
    }
    return func_01ffa42c(&data_ov010_0222c080, arg5);
}

s32 func_ov010_02226364(void) {
    s32 func_02037ca0(M2C_UNK *, M2C_UNK *);
    s64 func_020c4858(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    M2C_UNK date[4];
    M2C_UNK time[3];
    s64 temp;
    s32 res;

    if (func_02037ca0(date, time) == 0) {
        temp = 0;
    } else {
        temp = func_020c4858(func_02085c18(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

s32 func_ov010_022264e4(void) {
    M2C_UNK func_02085c28();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c28();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 4:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 func_ov010_02226538(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_01ffa42c(M2C_UNK *, s32);
    s32 func_ov010_022263b0();
    extern M2C_UNK data_ov010_0222c0a0;
    if (func_ov010_022263b0() == 0) return 0;
    return func_01ffa42c(&data_ov010_0222c0a0, arg4);
}

s32 func_ov010_02226560(void) {
    s32 func_02037ca0(M2C_UNK *, M2C_UNK *);
    s64 func_020c4858(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c3c();
    M2C_UNK date[4];
    M2C_UNK time[3];
    s64 temp;
    s32 res;

    if (func_02037ca0(date, time) == 0) {
        temp = 0;
    } else {
        temp = func_020c4858(func_02085c3c(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

s32 func_ov010_022265ac(s32 a,s32 b,s32 c,s32 d){
s32 func_02037ca0(M2C_UNK *,M2C_UNK *); s64 func_020c4858(s32,M2C_UNK *,M2C_UNK *); s32 func_02085c18(); u32 func_02045934(s32,s32,s32,s32);
M2C_UNK time[3]; M2C_UNK date[4]; s32 result; u32 status;
result=1;
if(func_02037ca0(date,time)!=0)func_020c4858(func_02085c18(),date,time);
status=func_02045934(a,b,c,d);
switch(status){default:break;case 1:result=0;break;case 7:result=0;break;case 2:result=0;break;case 8:result=0;break;case 9:result=0;break;}
if(status!=0)func_ov010_02226114(status);
return result;
}

s32 func_ov010_02226670(void) {
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 1;
    temp_r0 = func_02045a88();
    switch (temp_r0) {
    default:
        break;
    case 5:
        func_02085c04();
        var_r4 = 0;
        break;
    case 6:
        var_r4 = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
        var_r4 = 0;
        break;
    }
    return var_r4;
}

s32 func_ov010_022266c4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_01ffa42c(M2C_UNK *, s32);
    s32 func_ov010_022265ac();
    extern M2C_UNK data_ov010_0222c060;
    if (func_ov010_022265ac() == 0) return 0;
    return func_01ffa42c(&data_ov010_0222c060, arg4);
}

s32 func_ov010_022266ec(void) {
    s32 func_02037ca0(M2C_UNK *, M2C_UNK *);
    s64 func_020c4858(s32, M2C_UNK *, M2C_UNK *);
    s32 func_02085c18();
    M2C_UNK time[3];
    M2C_UNK date[4];
    s64 temp;
    s32 res;

    if (func_02037ca0(date, time) == 0) {
        temp = 0;
    } else {
        temp = func_020c4858(func_02085c18(), date, time);
    }
    res = 0;
    if (temp >= 0x3C) {
        res = 1;
    }
    return res;
}

void func_ov010_02226738(void) {
    M2C_UNK func_02045a88();
    func_02045a88();
}

s32 func_ov010_02226744(void) {
 s32 func_02045ba0(s32 *);
 s32 sp0, temp_r0, var_r4;
 var_r4 = -1;
 temp_r0 = func_02045ba0(&sp0);
 switch(temp_r0) {
 case 0: var_r4 = sp0; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) func_ov010_02226114(temp_r0);
 return var_r4;
}

s32 func_ov010_022267b0(M2C_UNK arg0, M2C_UNK arg1) {
 s32 func_02045a98(M2C_UNK, M2C_UNK);
 s32 temp_r0, var_r4;
 var_r4 = 0;
 temp_r0 = func_02045a98(arg1,arg0);
 switch(temp_r0) {
 case 0: var_r4 = 1; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) func_ov010_02226114(temp_r0);
 return var_r4;
}

s32 func_ov010_0222681c(void) {
 s32 func_02045c34(s32 *);
 s32 sp0, temp_r0, var_r4;
 var_r4 = -1;
 temp_r0 = func_02045c34(&sp0);
 switch(temp_r0) {
 case 0: var_r4 = sp0; break;
 case 1: break;
 case 2: break;
 case 15: break;
 case 16: break;
 case 17: break;
 }
 if(temp_r0 != 0) func_ov010_02226114(temp_r0);
 return var_r4;
}

s32 func_ov010_02226888(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    s32 func_02045620();
    s32 func_ov010_022282b4(M2C_UNK);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    extern M2C_UNK data_ov010_0222c0c0;
    s32 temp_r0;
    s32 var_r5;

    if (func_ov010_022282b4(5) == 0) {
        return 1;
    }
    temp_r0 = func_02045620();
    if (temp_r0 == 0) {
        var_r5 = 1;
    } else {
        var_r5 = 0;
    }
    func_01ffa9e4(&data_ov010_0222c0c0);
    if (temp_r0 != 0) {
        func_ov010_02226114(temp_r0);
    }
    func_ov010_022282d4(5);
    return var_r5;
}

void func_ov010_022268dc(void) {

}

s32 func_ov010_022268e0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_022268f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
 M2C_UNK func_020e3580();
 func_020e3580(arg1,arg2);
}

M2C_UNK func_ov010_02226908(M2C_UNK arg0, s32 arg1, s32 arg2) {
 M2C_UNK func_020e35cc();
 if(arg1 == 0) return;
 func_020e35cc(arg1);
}

void func_ov010_02226920(void *arg0) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x1A);
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x5DC000;
    M2C_FIELD(arg0, s8 *, 0x24) = -1;
    M2C_FIELD(arg0, s8 *, 0x25) = -2;
    M2C_FIELD(arg0, s8 *, 0x26) = -2;
    M2C_FIELD(arg0, s8 *, 0x27) = -1;
    M2C_FIELD(arg0, s8 *, 0x28) = -1;
    func_02007f8c(arg0 + 0x2C, 0, 0x40);
}

void *func_ov010_0222697c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x5DC000;
    M2C_FIELD(arg0, s8 *, 0x24) = -1;
    M2C_FIELD(arg0, s8 *, 0x25) = -2;
    M2C_FIELD(arg0, s8 *, 0x26) = -2;
    M2C_FIELD(arg0, s8 *, 0x27) = -1;
    M2C_FIELD(arg0, s8 *, 0x28) = -1;
    func_02007f8c(arg0, 0, 0x1A);
    func_02007f8c(arg0 + 0x2C, 0, 0x40);
    return arg0;
}

void func_ov010_022269dc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007e20(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02007e20(arg1, arg0, 0x18);
}

void func_ov010_022269f8(s32 a,s32 b,s32 c){func_02008048(b,a+44,c);}

void func_ov010_02226a10(void *a){volatile u32 saved;u32 temp;void *p;temp=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=0;p=M2C_FIELD(a,void **,0);saved=temp;while(p!=0){M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0);func_ov010_02226908(0,(s32)p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(a,void **,0);}M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,8)=0;(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;}

s32 func_ov010_02226be8(s32 a){extern M2C_UNK data_ov010_0222eee0;u32 saved=*(volatile u16 *)0x4000208;void *p;*(volatile u16 *)0x4000208=0;p=M2C_FIELD(&data_ov010_0222eee0,void **,0x60);while(p){if(a==M2C_FIELD(p,u8 *,8)){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 1;}p=M2C_FIELD(p,void **,0);}(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}

void func_ov010_02226d74(void *arg0) {
    M2C_UNK func_ov010_02226908(M2C_UNK, s32, s32);
    func_ov010_02226908(0, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

