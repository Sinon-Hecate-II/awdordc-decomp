/* 44 functions from 0x0216CCE0 to 0x0216DBDC (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02192740;

#pragma thumb on
void func_ov001_0216cce0(s32 arg0, s32 arg1, s32 arg2) {
    void func_ov001_0216cdd4(s32, s32, s32);
    s32 half = arg1 / 2;
    func_ov001_0216cdd4(arg2, arg0 + half, half);
    func_ov001_0216cdd4(arg2 + half, arg0, half);
    func_ov001_0216cdd4(arg0, arg2, arg1);
}
s32 func_ov001_0216cd10(s32 arg0, s32 arg1) {
    extern s32 (*data_ov001_021925e0)(s32);
    if (arg1 > 0) return data_ov001_021925e0(arg1);
    return 0;
}

void func_ov001_0216cd28(s32 arg0, s32 arg1) {
    extern void (*data_ov001_021925ec)(s32);
    data_ov001_021925ec(arg1);
}

s32 func_ov001_0216cd38(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov001_0216ce88(s32);
    s32 func_02021a90(void *);
    void func_02006030();
    extern s32 data_021372e0;
    extern M2C_UNK data_ov001_0218fd44;
    extern M2C_UNK data_ov001_0218fd4c;
    M2C_FIELD(&data_ov001_0218fd44, s32 *, 0x18) = func_ov001_0216ce88(arg0);
    M2C_FIELD(&data_ov001_0218fd44, s32 *, 0x1c) = func_ov001_0216ce88(arg1);
    M2C_FIELD(&data_ov001_0218fd44, s32 *, 0x20) = func_ov001_0216ce88(arg2);
    if (func_02021a90(&data_ov001_0218fd4c) < 0) return -1;
    while (data_021372e0 == 0) func_02006030(100);
    return 0;
}

s32 func_ov001_0216cd90(void) {
    s32 func_02021c04();
    s32 func_ov001_0216d1e4();
    if (func_02021c04() < 0) return -1;
    return -(func_ov001_0216d1e4() != 0);
}

s32 func_ov001_0216cdb4(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 result = 0;
    while (arg2-- > 0 && (result = *arg0 - *arg1) == 0) {
        arg0++;
        arg1++;
    }
    return result;
}

void func_ov001_0216cdd4(s32 arg0, s32 arg1, s32 arg2) {
 void func_02008048(s32, s32, s32);
 func_02008048(arg1, arg0, arg2);
}

void func_ov001_0216cde4(s32 arg0, s32 arg1) {
 void func_02007f8c(s32, u8);
 func_02007f8c(arg0, (u8)arg1);
}

void func_ov001_0216cdf0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 *arg5) {
 void func_020215f8(s32, s32, s32, s32, u8 *);
 *arg4 = *arg5;
 func_020215f8(arg0, arg1, arg2, arg3, arg4);
}

void func_ov001_0216ce04(M2C_UNK arg0, s32 *arg1, M2C_UNK arg2, M2C_UNK arg3, s32 *arg4) {
    M2C_UNK func_02021d34(s32 *, s32, u64);
    u64 func_020720d0(s64, s64);
    s32 sp0;
    s32 sp4;
    u64 temp = 0;

    sp0 = arg1[0];
    sp4 = arg1[1];
    temp += func_020720d0(arg4[0], 0x1FF6210) >> 6;
    temp += func_020720d0(arg4[1], 0x1FF6210) >> 6;
    func_02021d34(&sp0, 1, temp);
}

void func_ov001_0216ce58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 *arg4, s32 arg5) {
    M2C_UNK func_020216cc(s32, s32, s32, s32, s8 *);
    *arg4 = (s8) arg5;
    func_020216cc(arg0, arg1, arg2, arg3, arg4);
}

void func_ov001_0216ce68(void) {

}

#pragma thumb on
void func_ov001_0216ce6c(void) {
    void func_02021500(void);
    func_02021500();
}

void func_ov001_0216ce74(M2C_UNK arg0, void *arg1, u8 arg2) {
    void func_0202152c(M2C_UNK, void *);
    M2C_FIELD(arg1, u8 *, 0) = arg2;
    func_0202152c(arg0, arg1);
}

void func_ov001_0216ce80(void) {
    void func_0202175c(void);
    func_0202175c();
}

s32 func_ov001_0216ce88(s32 arg0) {
    u32 x = (u32) arg0;
    return ((x << 0x18) & 0xFF000000) | (((x << 8) & 0xFF0000) | ((u8) (x >> 0x18) | ((x >> 8) & 0xFF00)));
}

u16 func_ov001_0216ceb0(s32 arg0) {
    return (u16) ((u8) (arg0 >> 8) | (0xFF00 & (arg0 << 8)));
}

s32 func_ov001_0216cec8(s32 arg0) {
    u32 x = (u32) arg0;
    return ((x << 0x18) & 0xFF000000) | (((x << 8) & 0xFF0000) | ((u8) (x >> 0x18) | ((x >> 8) & 0xFF00)));
}

u16 func_ov001_0216cef0(s32 arg0) {
    return (u16) ((u8) (arg0 >> 8) | (0xFF00 & (arg0 << 8)));
}

s32 func_ov001_0216cf08(s8 *arg0) {
    s32 var_r2;

    var_r2 = 0;
    if (*arg0 != 0) {
        do {
            var_r2 += 1;
        } while (*(arg0 + var_r2) != 0);
    }
    return var_r2;
}

#pragma thumb on
u16 func_ov001_0216cf1c(void) {
    s32 func_0200eff8(void *);
    extern s32 data_ov001_02191800;
    u32 t[3];
    u32 seed;
    u32 next;
    if (M2C_FIELD(&data_ov001_02191800, s32 *, 8) == 0) {
        seed = 0;
        ((void (*)(void *, s32, s32))func_ov001_0216cde4)(t, 0, 12);
        if (func_0200eff8(t) == 0) {
            seed += t[0] << 10;
            seed += t[1] << 3;
            seed += t[2];
        }
        M2C_FIELD(&data_ov001_02191800, u32 *, 0x18) = seed;
        M2C_FIELD(&data_ov001_02191800, u32 *, 0x1C) = 0x5D588B65;
        M2C_FIELD(&data_ov001_02191800, u32 *, 0x20) = 0x269EC3;
        M2C_FIELD(&data_ov001_02191800, s32 *, 8) = 1;
    }
    next = M2C_FIELD(&data_ov001_02191800, u32 *, 0x1C) * M2C_FIELD(&data_ov001_02191800, u32 *, 0x18) + M2C_FIELD(&data_ov001_02191800, u32 *, 0x20);
    M2C_FIELD(&data_ov001_02191800, u32 *, 0x18) = next;
    return ((next >> 16) * 0x7FFF) >> 16;
}
void func_ov001_0216cf8c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

void func_ov001_0216cf98(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = arg0;
    M2C_FIELD(arg1, s16 *, 4) = 1;
}

void func_ov001_0216d02c(s32 *arg0, void *arg1) {
    void func_02007df8(s32, void *, s32);
    func_02007df8(0, arg1 + 12, 32);
    M2C_FIELD(arg1, u16 *, 10) = *arg0;
    func_02008048((s32)(arg0 + 1), (s32)(arg1 + 12), M2C_FIELD(arg1, u16 *, 10));
}

#pragma thumb on
void func_ov001_0216d050(s32 *arg0, M2C_UNK arg1, s32 arg2) {
    void func_ov001_0216cfa0(M2C_UNK, void *);
    *arg0 = arg2;
    func_ov001_0216cfa0(arg1, arg0 + 1);
}
#pragma thumb on

void func_ov001_0216d060(s32 arg0) {
 void func_020062fc(void *, s32, s32);
 extern s32 data_ov001_02192600;
 func_020062fc(&data_ov001_02192600, arg0, 0);
}

void func_ov001_0216d074(s32 arg0) {
 void func_020062fc(void *, s32, s32);
 extern s32 data_ov001_02192600;
 func_020062fc(&data_ov001_02192600, arg0, 0);
}

s32 func_ov001_0216d1e4(void) {
    s32 func_02006390(void *, s32 *, s32);
    extern s32 data_ov001_02192600;
    s32 msg;
    s32 result = -1;
    s32 again;
    if (func_ov001_0216da10()) {
        do {
            func_02006390(&data_ov001_02192600, &msg, 1);
            if (msg == 14) {
                again = 0;
                result = again;
            } else {
                again = 0;
            }
        } while (again != 0);
    }
    return result;
}

#pragma push
#pragma optimization_level 2
#pragma opt_propagation off
#pragma thumb on
s32 func_ov001_0216d394(void *arg0,s32 *arg1){
 s32 func_02006390(void *,s32 *,s32);void func_02007190(void *);void func_020072cc(void *,s32,s32,void *,s32);void func_02007338(void *);
 void func_02007f8c(s32,u8);void func_02029220(void);
 s32 func_ov001_0216d8e4(s32,void *,s32,s32);
 extern s32 data_ov001_02192600,data_ov001_02192620,data_ov001_021926e0;
 u32 timer[11];s32 msg;s32 result,tries,bound,i,active,flags,ready;u8 *packet;s32 offset; void *p;
 active=1;p=arg0;result=active-2;ready=0;
 if(M2C_FIELD(p,s32 *,0x24)==0)flags=0x80000;
 else if(M2C_FIELD(p,s32 *,0x24)==1)flags=0xc0000;
 flags|=0x30000;
 ((void (*)(s32,s32,s32))func_02007f8c)((s32)&data_ov001_021926e0,0,96);
 if(M2C_FIELD(p,s32 *,40)==5)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=1;
 else if(M2C_FIELD(p,s32 *,40)==13)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=2;
 else if(M2C_FIELD(p,s32 *,40)==16)M2C_FIELD(&data_ov001_021926e0,u8 *,0)=3;
 else return -1;
 packet=(u8 *)&data_ov001_021926e0;
 offset=(ready*5)*4+2;
 packet[1]=ready;
 func_02008048((s32)((u8 *)p+44),(s32)(packet+offset),M2C_FIELD(p,s32 *,40));
 func_02029220();
 if(func_ov001_0216d8e4(0,(u8 *)p+4,M2C_FIELD(p,s32 *,0),0x30bffe)){
 tries=0;func_02007190(timer);func_020072cc(timer,0x3fec42,0,(void *)func_ov001_0216d074,18);
 goto test;
 do {
 func_02006390(&data_ov001_02192600,&msg,1);
 switch(msg){
 case 18:if(!ready){active=0;}
 case 19:goto test;
 case 5:if(ready)break;
 func_02007338(timer);
 if(func_ov001_0216d8a0((s32)&data_ov001_02192620,1)!=1){active=0;break;}
 func_ov001_0216d02c(p,&data_ov001_02192620);
 i=0;bound=M2C_FIELD(&data_ov001_02192620,u16 *,10);for(;i<bound;i++){}
 if(!func_ov001_0216daa0((s32)&data_ov001_02192620,(s32)&data_ov001_021926e0,flags)){active=0;break;}
 ready=1;break;
 case 10:
 func_ov001_0216d02c(p,&data_ov001_02192620);
 if(!func_ov001_0216daa0((s32)&data_ov001_02192620,(s32)&data_ov001_021926e0,flags))active=0;
 break;
 case 12:active=0;result=0;break;
 case 13:
 if(++tries<3){if(!func_ov001_0216daa0((s32)&data_ov001_02192620,(s32)&data_ov001_021926e0,flags))active=0;}else active=0;
 break;
 case 4:case 8:break;
 default:active=0;break;
 } next:; test:; }while(active);
 func_02007338(timer);
 while(func_02006390(&data_ov001_02192600,&msg,0)==1){}
 }
 func_ov001_0216d050(arg1,(s32)&data_ov001_02192620,result==0);
 return result;
}
#pragma pop
void func_ov001_0216d564(void) {
    void func_02006030(void);
    func_02006030();
}

s32 func_ov001_0216d56c(s32 a){extern s32 (*data_ov001_021925e0)(s32);void (*f)(s32)=M2C_FIELD(&data_ov001_021925e0,void (**)(s32),4);if(f)f(a);return 0;}

s32 func_ov001_0216d8a0(s32 arg0, s32 arg1) {
    M2C_UNK func_02007e70(s32, s32, M2C_UNK);
    s32 func_02029274();
    M2C_UNK func_020292cc(M2C_UNK);
    s32 func_02029348(u16);
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;

    var_r5 = arg0;
    func_020292cc(1);
    temp_r0 = func_02029274();
    if (temp_r0 > 0) {
        var_r4 = 0;
        if (temp_r0 > 0) {
loop_2:
            if (var_r4 < arg1) {
                func_02007e70(func_02029348((u16) var_r4), var_r5, 0xC0);
                var_r4 += 1;
                var_r5 += 0xC0;
                if (var_r4 < temp_r0) {
                    goto loop_2;
                }
            }
        }
    }
    func_020292cc(0);
    return temp_r0;
}

s32 func_ov001_0216d9d4(void){s32 t=func_0200751c();if(M2C_FIELD(&data_ov001_02192740,s32 *,0x18)==5 && func_02027518(0,0,0)==3){M2C_FIELD(&data_ov001_02192740,s32 *,0x18)=4;func_02007530(t);return 1;}func_02007530(t);return 0;}

s32 func_ov001_0216da10(void) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_02027958();
    extern M2C_UNK data_ov001_02192740;
    s32 temp_r4;

    temp_r4 = func_0200751c();
    if ((M2C_FIELD(&data_ov001_02192740, s32 *, 0x18) == 7) && (func_02027958() == 3)) {
        M2C_FIELD(&data_ov001_02192740, s32 *, 0x18) = 4;
        func_02007530(temp_r4);
        return 1;
    }
    func_02007530(temp_r4);
    return 0;
}

s32 func_ov001_0216da48(void){s32 t=func_0200751c();if(M2C_FIELD(&data_ov001_02192740,s32 *,0x18)==3){if(func_02027428()!=3){func_02007530(t);return 0;}M2C_FIELD(&data_ov001_02192740,s32 *,0x18)=2;func_02007530(t);return 1;}if(func_ov001_0216d838()==1){M2C_FIELD(&data_ov001_02192740,s32 *,0x18)=2;func_02007530(t);return 1;}func_02007530(t);return 0;}

s32 func_ov001_0216daa0(s32 a,s32 b,s32 c){s32 t=func_0200751c();M2C_FIELD(&data_ov001_02192740,s32 *,12)=c;if(b)func_02008048(b,M2C_FIELD(&data_ov001_02192740,s32 *,36),80);else func_02007f8c(M2C_FIELD(&data_ov001_02192740,s32 *,36),0,80);func_02007e70(a,M2C_FIELD(&data_ov001_02192740,s32 *,32),192);if(func_ov001_0216d838()==1){M2C_FIELD(&data_ov001_02192740,s32 *,24)=8;func_02007530(t);return 1;}if(M2C_FIELD(&data_ov001_02192740,s32 *,24)==3 && func_02027754(M2C_FIELD(&data_ov001_02192740,s32 *,32),M2C_FIELD(&data_ov001_02192740,s32 *,36),M2C_FIELD(&data_ov001_02192740,s32 *,12))==3){M2C_FIELD(&data_ov001_02192740,s32 *,24)=8;func_02007530(t);return 1;}func_02007530(t);return 0;}

