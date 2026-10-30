/* 55 functions from 0x0208EE90 to 0x0208FE7C (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_021577e4;
extern u32 data_021577e8[9], data_0215780c[9];

M2C_UNK func_0208ee90(void) { return 0; }

void func_0208f3a4(void) {
    M2C_UNK func_0208ee90();
    func_0208ee90();
}

void func_0208f3b0(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208ed88();
    extern M2C_UNK data_021026f8;
    if (func_01ffa42c(&data_021026f8, arg0) == 0) {
        return;
    }
    func_0208ed88();
}

void func_0208f3d4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r0 > 0) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_r0 - 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x34)();
    func_01ffa6fc(arg0);
}

#pragma opt_common_subs off
u16 func_0208f404(u8 *arg0, s32 arg1) {
    u32 crc = 0;
    u32 byte;
    s32 i;
    u32 poly;

    if (arg1 > 0) {
        poly = 0x18003;
        do {
            byte = *arg0;
            i = 0;
            do {
                crc = crc << 1;
                if (crc & 0x10000) {
                    crc = crc << 16;
                    crc = poly ^ (crc >> 16);
                }
                byte = byte << 17;
                crc = crc << 16;
                byte = byte >> 16;
                crc = crc >> 16;
                if (byte & 0x100) {
                    crc = crc ^ 1;
                }
                i = i + 1;
            } while (i < 8);
            arg1 = arg1 - 1;
            arg0 = arg0 + 1;
        } while (arg1 > 0);
    }
    return (u16)crc;
}
#pragma opt_common_subs reset
void func_0208f478(void) {

}

s32 func_0208f47c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0208f490(void) {

}

s32 func_0208f494(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0208f4a8(void) {

}

s32 func_0208f4ac(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0208f4c0(void) {

}

s32 func_0208f4c4(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_0208f4d8(void) {
    s32 func_02007004();
    extern M2C_UNK data_021577e4;
    M2C_FIELD(&data_021577e4, s32 *, 4) = func_02007004();
}

void func_0208f4f0(void) {
s32 func_02007004(void);
u64 func_02072088(u64,u64);
s32 i; u32 t;
t=func_02007004()-M2C_FIELD(&data_021577e4,u32 *,4);
M2C_FIELD(&data_021577e4,u32 *,4)=t;
M2C_FIELD(&data_021577e4,u32 *,0x28)=func_02072088((u64)t*64000,33514);
for(i=0;i<3;i++) {
data_0215780c[i+1]=func_02072088((u64)data_021577e8[i+1]*64000,33514);
data_021577e8[i+1]=0;
}
M2C_FIELD(&data_021577e4,u32 *,0x38)=func_02072088((u64)M2C_FIELD(&data_021577e4,u32 *,0x14)*64000,33514);
}

void func_0208f5cc(void) {
    M2C_UNK func_0208f890();
    func_0208f890();
}

void func_0208f5d8(void) {
    func_0208f780(4);
}

s32 func_0208f5e8(void) {
    u32 func_020e31e0();
    u32 temp_r0;

    temp_r0 = func_020e31e0();
    switch (temp_r0) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 1;
    }
}

void func_0208f64c(void) {
s32 func_02005080(s32);
void func_02004ff8(s32,s32);
void func_020051f8(s32);
void func_0200245c(s32);
void func_0208fce8(void);
void func_02088724(void);
void func_02037854(s32);
void *func_020e3580(s32,s32);
void func_ov001_0217589c(void *,s32,s32);
M2C_UNK func_020e35cc();
void func_0208859c(void);
void func_02088634(void);
void func_0208fba0(void);
void func_020051c8(s32);
void func_02007598(void);
void func_020024cc(void);
s32 old;void *p;u16 unused;
old=func_02005080(1);
func_02004ff8(1,0);
func_020051f8(1);
func_0200245c(0);
func_0208fce8();
func_02088724();
func_02037854(2);
p=func_020e3580(0x40000,0x20);
if(func_0208f5e8()==0) func_ov001_0217589c(p,func_0208f5e8(),0x10);
else func_ov001_0217589c(p,func_0208f5e8(),0);
func_020e35cc(p);
func_0208859c();
func_02088634();
func_0208fba0();
func_02004ff8(1,old);
func_020051c8(1);
unused=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=1;
func_0200245c(1);
func_02007598();
func_020024cc();
*(volatile u32 *)0x4001000 |= 0x10000;
}

void func_0208f730(M2C_UNK arg0) {
    extern M2C_UNK data_021028c4;
    extern M2C_UNK data_021028d0;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa42c(&data_021028d0, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_021028c4;
    }
}

void func_0208f758(void) {

}

s32 func_0208f75c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

s32 func_0208f770(void) {
    extern s32 data_02102910;
    return data_02102910;
}

M2C_UNK func_0208f780(s32 arg0) {
extern s32 data_02102910;
void func_0208f904(void);
void func_020901e0(s32);
void func_020ad594(s32);
void func_020ad640(void);
s32 current=data_02102910;
if(current==arg0) return current;
func_0208f904();
func_020901e0(arg0);
data_02102910=arg0;
func_020ad594(arg0);
func_020ad640();
}

void func_0208f7c0(void *arg0) {
    func_0208f780(M2C_FIELD(arg0, s32 *, 0x5C));
}

void func_0208f7d0(s32 arg0) {
    M2C_UNK func_0208f890();
    void *func_01ffa3dc(M2C_UNK *, s32);
    extern s32 data_02102910;
    extern M2C_UNK data_0210295c;
    if (data_02102910 == arg0) {
        return;
    }
    func_0208f890();
    M2C_FIELD(func_01ffa3dc(&data_0210295c, 7), s32 *, 0x5C) = arg0;
}

void func_0208f808(void) {
    extern s32 data_02102910;
    data_02102910 = 0xffff;
}

void func_0208f820(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)--;
    if (M2C_FIELD(arg0, s16 *, 0x6C) != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_0208f844(s32 arg0) {
    void func_02090248(s32);
    void *func_01ffa3dc(M2C_UNK *, s32);
    extern s32 data_02102910;
    extern M2C_UNK data_02102934;
    if (data_02102910 == 0xFFFF) {
        return;
    }
    if (arg0 == 0) {
        arg0 = 1;
    }
    func_02090248(arg0);
    M2C_FIELD(func_01ffa3dc(&data_02102934, 7), s16 *, 0x6C) = (s16)arg0;
}

M2C_UNK func_0208f890(void) {
    void func_0208f844(s32);
    func_0208f844(0x1E);
}

u8 func_0208f8a0(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102934;
    u8 var_r0;

    if (func_01ffa770(&data_02102934) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208f8c4(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0x40, 0x1E);
}

void func_0208f8d8(void) {
    func_0208f8ec(0x7F, 0x1E);
}

s32 func_0208f8ec(s32 a,s32 b){s32 func_020902a8(s32,s32,s32);return func_020902a8(-1,a,b);}

void func_0208f904(void){
 M2C_UNK func_01ffa9e4(M2C_UNK*);
 void func_02090248(s32);
 extern M2C_UNK data_02102934,data_0210295c;
 extern s32 data_02102910;
 func_01ffa9e4(&data_02102934);func_01ffa9e4(&data_0210295c);
 func_02090248(0);data_02102910=0xffff;
}

void func_0208f940(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

void func_0208f94c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s16 temp_r1;
    s32 temp_r4;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x54);
    M2C_FIELD(arg0, s16 *, 0x54) = (s16) (temp_r1 + 1);
    if ((s32) temp_r1 < (s32) M2C_FIELD(arg0, s16 *, 0x52)) {
        return;
    }
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x64);
    if (func_0208fe7c(M2C_FIELD(arg0, s32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60)) != 0) {
        func_0208ff94(temp_r4);
    }
    func_01ffa574(arg0);
}

void func_0208f998(s32 arg0, s16 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102984;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_02102984, 7);
    M2C_FIELD(temp_r0, s32 *, 0x5C) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0x7F;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x52) = arg1;
}

void func_0208f9d0(void *a){
 u64 func_020722fc(s32,s16);
 s32 func_0208fe30(s32);
 extern s32 data_027e15bc;
 if((u32)(func_020722fc(data_027e15bc,M2C_FIELD(a,s16*,0x52))>>32)!=0)return;
 func_0208fe30(M2C_FIELD(a,s32*,0x5c));
}

void func_0208fa00(s32 a,s32 b){
 void *func_01ffa3dc(M2C_UNK*,M2C_UNK);
 extern M2C_UNK data_02102914;
 void *p=func_01ffa3dc(&data_02102914,7);
 M2C_FIELD(p,s32*,0x5c)=a;M2C_FIELD(p,s16*,0x52)=b;
}

void func_0208fa28(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102914;
    func_01ffa9e4(&data_02102914);
}

s32 func_0208fa3c(void) {
    s32 func_0207cfb8(s32);
    extern s32 *gCurrentMap;
    s32 var_r0;

    if (func_0207cfb8(*gCurrentMap + 0x6EF8) <= 0) {
        var_r0 = 0x10;
    } else {
        var_r0 = 0x18;
    }
    if (var_r0 == 0x10) {
        return 0x5F;
    }
    return 0x7F;
}

s32 func_0208fa78(s32 a,s32 b){
 void func_02079c6c(s32,s32,s32*);
 s32 func_0207ca38(s32,s32,s32,s32,s32);
 s32 v[3];
 func_02079c6c(a,b,v);
 if(v[0]<0)return -32;
 if(v[0]>256)return 32;
 return func_0207ca38(0,-32,32,v[0],256);
}

void func_0208facc(M2C_UNK arg0) {
    s32 func_0208fa3c();
    M2C_UNK func_0208fe7c(M2C_UNK, s32);
    func_0208fe7c(arg0, func_0208fa3c());
}

void func_0208fae8(M2C_UNK arg0) {
    M2C_UNK func_020901b0(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020901b0(0, -1, arg0, func_0208fa3c());
}

void func_0208fb0c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0208fa78(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208ff94(s32);
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = func_0208fa3c();
    temp_r4 = func_0208fa78(arg1, arg2);
    if (func_0208fe7c(arg0, temp_r5) == 0) {
        return;
    }
    func_0208ff94(temp_r4);
}

void func_0208fb54(s32 a,s32 b,s32 c,s32 d){
 void *func_01ffa3dc(M2C_UNK*,M2C_UNK);
 extern M2C_UNK data_02102984;
 void *p=func_01ffa3dc(&data_02102984,7);
 M2C_FIELD(p,s32*,0x5c)=a;
 M2C_FIELD(p,s32*,0x60)=func_0208fa3c();
 M2C_FIELD(p,s32*,0x64)=func_0208fa78(b,c);
 M2C_FIELD(p,s16*,0x52)=d;
}

#pragma opt_strength_reduction off
void func_0208fba0(void){
 void func_0208fc50(void);void func_0208fc4c(void);
 extern M2C_UNK data_0215783c,data_02157834,data_02157838,data_02157850,data_02157830,data_02157860;
 extern s32 data_027e15bc;
 u8 *p; s32 i;
 func_0202a968();func_0202acb0(&data_0215783c);func_0202acb0(&data_02157834);func_0202d9c0(&data_02157838);
 for (p=(u8*)&data_02157850,i=0;i<4;i++,p+=4)func_0202acb0(p);
 M2C_FIELD(&data_02157830,u8*,0)=0;
 M2C_FIELD(&data_02157830,s32*,0x18)=0;
 M2C_FIELD(&data_02157830,s32*,0x1c)=data_027e15bc;
 for(i=0;i<8;i++)((s32*)&data_02157860)[i]=0;
 func_0208fc50();func_0208fc4c();func_020903d4();func_0208fc4c();func_02090604();func_020903b0();
}
#pragma opt_strength_reduction reset
void func_0208fc4c(void) {

}

void func_0208fc50(void){
 s32 func_020e34f4(s32);s32 func_0202c4ac(s32,s32);
 extern M2C_UNK data_02157830,data_02157880,data_021029ac;
 s32 p;
 if(M2C_FIELD(&data_02157830,u8*,0))return;
 if(!M2C_FIELD(&data_02157830,s32*,0x14))M2C_FIELD(&data_02157830,s32*,0x14)=func_020e34f4(0xd0000);
 p=func_0202c4ac(M2C_FIELD(&data_02157830,s32*,0x14),0xd0000);
 M2C_FIELD(&data_02157830,s32*,0x10)=p;
 func_0202bd00(&data_02157880,&data_021029ac,p,0);
 func_0202d294(M2C_FIELD(&data_02157830,s32*,0x10));
 func_0202d6d4(10,M2C_FIELD(&data_02157830,s32*,0x10));
 M2C_FIELD(&data_02157830,u8*,0)=1;func_020903b0();
}

void func_0208fce8(void) {
    M2C_UNK func_0202ac70(M2C_UNK);
    M2C_UNK func_0202c51c(s32);
    M2C_UNK func_020e35cc();
    extern M2C_UNK data_02157830;
    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return;
    }
    func_0202ac70(0);
    func_0202c51c(M2C_FIELD(&data_02157830, s32 *, 0x14));
    M2C_FIELD(&data_02157830, u8 *, 0) = 0U;
    if (M2C_FIELD(&data_02157830, s32 *, 0x14) == 0) {
        return;
    }
    func_020e35cc();
    M2C_FIELD(&data_02157830, s32 *, 0x14) = 0;
}

void func_0208fd40(M2C_UNK *a,s32 b,u32 c){
 u32 hi=(c&0xffff0000)>>16;u32 lo=(u16)c;
 if(hi){func_0202d468(a,b,-1,-1,hi,lo);return;}
 func_0202d378(a,b,-1,-1,lo);
}

void func_0208fd94(void) {
    M2C_UNK func_0202ac60();
    func_0202ac60();
}

#pragma opt_strength_reduction off
s32 func_0208fda0(s32 arg0) {
    extern M2C_UNK data_02157830;
    extern s32 data_027e15bc;
    extern M2C_UNK data_02157860;
    u32 i;
    u32 count;

    if (M2C_FIELD(&data_02157830, s32 *, 0x1C) != data_027e15bc) {
        M2C_FIELD(&data_02157830, s32 *, 0x18) = 0;
        M2C_FIELD(&data_02157830, s32 *, 0x1C) = data_027e15bc;
    }
    count = M2C_FIELD(&data_02157830, s32 *, 0x18);
    for (i = 0; i < count; i++) {
        if (arg0 == M2C_FIELD(&data_02157860, s32 *, i << 2)) {
            return 0;
        }
    }
    if (count < 8) {
        M2C_FIELD(&data_02157860, s32 *, count << 2) = arg0;
        M2C_FIELD(&data_02157830, s32 *, 0x18) = count + 1;
    }
    return 1;
}
s32 func_0208fe30(s32 a){
 s32 func_0208fda0(s32);
 void func_0208fd40(M2C_UNK*,s32,u32);
 extern M2C_UNK data_02157830,data_02157834;
 u8 enabled=M2C_FIELD(&data_02157830,u8*,0);
 if(enabled==0)return 0;
 if(!func_0208fda0(a))return 0;
 func_0208fd40(&data_02157834,-1,a);return 1;
}

