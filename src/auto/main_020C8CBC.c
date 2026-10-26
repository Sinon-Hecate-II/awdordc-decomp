/* 37 functions from 0x020C8CBC to 0x020C9B9C (main), found by ds-decomp. */
#include "common.h"
static inline u64 Pack_020c91ac(u64 x, u64 y, u64 z, u32 w) {
    return (x<<20) | (y<<36) | (z<<4) | (w&15);
}

s32 func_020c8cbc(M2C_UNK arg0) {
    s32 func_020c7e6c(s32);
    s32 func_020c7eb8(s32);
    s32 func_020c8b0c(M2C_UNK, s32);
    s32 var_r4;

    var_r4 = 0;
loop_1:
    if ((func_020c7eb8(var_r4 + 0xE1) != 0) && (func_020c8b0c(arg0, func_020c7e6c(var_r4 + 0xE1)) != 0)) {
        return var_r4 + 0xE1;
    }
    var_r4 += 1;
    if (var_r4 >= 0x32) {
        return 0;
    }
    goto loop_1;
}

s32 func_020c8d0c(s32 a) {
void func_02086844(s32,s32);
void func_02086878(s32,s32);
void func_020868ac(s32,s32);
s32 func_020c8054(s32);
void func_020bef44(s32);
func_02086844(a,0); func_02086878(a,0); func_020868ac(a-0xe1,0);
if (!func_020c8054(a)) return;
func_020bef44(8);
}

void func_020c8d50(M2C_UNK arg0) {
    s32 func_020c79ec();
    M2C_UNK func_020c8624(M2C_UNK, s32);
    M2C_UNK func_020c879c();
    s32 temp_r4;

    temp_r4 = func_020c79ec();
    func_020c879c();
    func_020c8d0c(arg0);
    func_020c8624(arg0, temp_r4);
}

s32 func_020c8d7c(s32 a){
s32 func_020c79ec();void *func_020c7a08();s32 func_020c8018(s32);
s32 func_020be324(u8,s32);s32 func_0207c368(void *,s32);
extern u8 data_02164d64[];
s32 n=func_020c79ec(),v,b;u8 c;void *p;func_020c79f8();p=func_020c7a08();b=0;
if(a>=225 && a<425)b=1;if(b)c=1;else c=0;if(!c)return 0;
v=func_020c8018(a);if(!func_020be324((u8)(v+9),n))return 0;
if(!func_0207c368(p+6,33))return 0;
func_02007ef4(p,data_02164d64+v*84,84,M2C_FIELD(p,u32 *,56)&=0xfffff001);
return 1;
}

void func_020c8e40(void) {
    M2C_UNK func_020c8d7c(s32);
    s32 var_r4;

    func_020c8eec();
    var_r4 = 0;
    do {
        func_020c8d7c(var_r4 + 0xE1);
        var_r4 += 1;
    } while (var_r4 < 0x32);
}

void func_020c8e64(void *arg0) {
    M2C_UNK func_020c8eec();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    func_020c8eec();
}

void func_020c8e78(void *arg0) {
    s32 var_r4;

    var_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (var_r4 >= 0x32) {
        return;
    }
    do {
        func_020c8d7c(var_r4 + 0xE1);
        var_r4 += 1;
    } while (var_r4 < 0x32);
}

void func_020c8ea0(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 temp_r0;

    func_020c8d7c(M2C_FIELD(arg0, s32 *, 0x5C) + 0xE1);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x5C) + 1;
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r0;
    if (temp_r0 != 0x32) {
        return;
    }
    func_01ffa6fc(arg0);
}

#pragma optimization_level 2
void func_020c8ed4(M2C_UNK arg0) {
M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
extern M2C_UNK data_0212b07c;
func_01ffa3dc(&data_0212b07c,arg0);
}
s32 func_020c8eec(void) {
s32 func_02007e98(s32,void *,s32);
extern u8 data_02164d64[];
return func_02007e98(0,data_02164d64,0x41a0);
}
#pragma optimization_level reset
void func_020c9040(void *a) {
void func_01ffa8c4(void *,s32);
M2C_FIELD(a,volatile u8 *,0x35)=0;
if(M2C_FIELD(a,volatile u8 *,0x34)) return;
func_01ffa8c4(a,0);
}

void func_020c9060(void *arg0) {
    s32 func_020be1a8();
    s32 temp_r2;
    u16 temp_r4;
    u32 temp_r1_2;
    u8 temp_r1;
    void *temp_r5;

    if (func_020be1a8() != 0) {
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x35);
    if ((u32) temp_r1 >= (u32) M2C_FIELD(arg0, u8 *, 0x34)) {
        func_01ffa6fc(arg0);
        return;
    }
    temp_r5 = M2C_FIELD((arg0 + (temp_r1 * 4)), void **, 0x4C);
    temp_r4 = M2C_FIELD((arg0 + (temp_r1 * 2)), u16 *, 0x36);
    temp_r2 = M2C_FIELD(temp_r5, s32 *, 0x4C) & ~0xE0000000;
    temp_r1_2 = (u32) (temp_r2 * 0x10) >> 0x16;
    M2C_FIELD(temp_r5, s32 *, 0x4C) = temp_r2;
    if (temp_r1_2 < 0x3E8U) {
        M2C_FIELD(temp_r5, s32 *, 0x4C) = (s32) ((M2C_FIELD(temp_r5, s32 *, 0x4C) & 0xF003FFFF) | ((u32) ((temp_r1_2 + 1) << 0x16) >> 4));
    }
    func_020c8d0c(temp_r4);
    func_020c8624(temp_r4, temp_r5);
    M2C_FIELD(arg0, u8 *, 0x35) = (u8) (M2C_FIELD(arg0, u8 *, 0x35) + 1);
}

void func_020c9100(s32 a) {
void *func_01ffa444();
extern M2C_UNK data_0212b0ac;
M2C_FIELD(func_01ffa444(&data_0212b0ac,a),u8 *,0x34)=0;
}

void func_020c9120(s16 arg0, s32 arg1) {
    extern M2C_UNK data_0212b0ac;
    void *temp_r0;

    temp_r0 = func_01ffa770(&data_0212b0ac);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, u8 *, 0x34) * 2)), s16 *, 0x36) = arg0;
    M2C_FIELD((temp_r0 + (M2C_FIELD(temp_r0, u8 *, 0x34) * 4)), s32 *, 0x4C) = arg1;
    M2C_FIELD(temp_r0, u8 *, 0x34) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x34) + 1);
}

void func_020c9168(void *arg0) {
    M2C_UNK func_020be488(s32);
    s32 func_020c7ea8(s32);
    M2C_UNK func_020c8d0c(s32);
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x34);
    temp_r4 = func_020c7ea8(temp_r5);
    func_020c8d0c(temp_r5);
    func_020be488(temp_r4);
}

void func_020c9190(s32 arg0) {
    void *func_01ffa444();
    extern M2C_UNK data_0212b114;
    M2C_FIELD(func_01ffa444(&data_0212b114), s32 *, 0x34) = arg0;
}

u64 func_020c91ac(s32 a) {
s32 func_020c7eb8(s32);
void *func_020c7e88(s32);
void *p; s32 v;
if (!func_020c7eb8(a)) return 0;
p=func_020c7e88(a);
v=M2C_FIELD(p,s32 *,0x10);
if (!v) return 0;
return ((u64)(s32)M2C_FIELD(p,u16 *,6)<<20) |
((u64)(u16)~v<<36) |
((u64)(s32)(u16)(~v>>16)<<4) |
((M2C_FIELD(p,u32 *,0xc)<<14>>20)&15);
}

s32 func_020c9244(u64 a) {
return ~((u32)((a>>4)&0xffff)<<16 | (u32)((a>>36)&0xffff));
}

u16 func_020c9268(u64 a) {
return (u16)((a>>20)&0xffff);
}

void func_020c93cc(void) {
    extern M2C_UNK data_02168f04;
    extern M2C_UNK data_ov000_021e146c;
    M2C_FIELD(&data_02168f04, s8 *, 0) = 0;
    M2C_FIELD(&data_02168f04, s8 *, 1) = 0;
    M2C_FIELD(&data_02168f04, s8 *, 2) = 0;
    M2C_FIELD(&data_02168f04, s8 *, 3) = 0;
    M2C_FIELD(&data_ov000_021e146c, s32 *, 0) = 0;
    M2C_FIELD(&data_ov000_021e146c, s32 *, 4) = 0;
}

void func_020c93fc(s32 a,s32 b) {
s32 func_020c9550(s32);
extern M2C_UNK data_02168f04;
if (!func_020c9550(a)) M2C_FIELD(&data_02168f04,u8 *,2)=a;
else M2C_FIELD(&data_02168f04,u8 *,3)=a;
M2C_FIELD(&data_02168f04,u8 *,a)=b;
}

u8 func_020c9430(s32 arg0) {
    extern M2C_UNK data_02168f04;
    return M2C_FIELD(&data_02168f04, u8 *, arg0);
}

s32 func_020c9440(u32 x,s32 y,s32 a) {
extern void **data_027e0058;
s32 d=func_020c9430(a);
void *p;
switch(d) {case 0: break; case 1: y--; break; case 2: x++; break; case 3: y++; break; case 4: x--; break;}
if(!d) return d;
p=*data_027e0058;
x+=M2C_FIELD(p+y*2,u16 *,0x3758);
if((u8)(M2C_FIELD(p+(x>>3),u8 *,0x5201) & (1<<(x&7)))) return d;
if(M2C_FIELD(p+x,u8 *,0x508)) d=5;
return d;
}

s32 func_020c94ec(void) {
extern M2C_UNK data_0212b1b8;
s32 v=0;
if(func_020c9430(0)) v|=M2C_FIELD(&data_0212b1b8,u8 *, (func_020c9430(0)-1)*4);
if(func_020c9430(1)) v|=M2C_FIELD(&data_0212b1b8,u8 *, (func_020c9430(1)-1)*4);
return v;
}

s32 func_020c9550(s32 a) {
s32 v=0;
if(func_020c9430(0)) v++;
if(func_020c9430(1)) v++;
return v;
}

void func_020c9580(s32 a) {
extern void **data_027e0058;
extern M2C_UNK data_0212b1ba,data_0212b1bb,data_ov000_021e146c;
s32 func_020a15b4(s32,s32);
s32 i=func_020c9430(a)-1;
void *p=*data_027e0058;
M2C_FIELD(&data_ov000_021e146c,s32 *,a*4)=func_020a15b4(M2C_FIELD(&data_0212b1ba,s8 *,i*4)+M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(&data_0212b1bb,s8 *,i*4)+M2C_FIELD(p,s16 *,0x52de));
}

void func_020c95e4(void) {
extern M2C_UNK data_02168f04;
s32 func_020c9550();
u32 i=func_020c9550()+1;
u8 *p=(u8 *)&data_02168f04;
i=p[i];
p[i]=0;
func_020a15e4();
}

void func_020c960c(s32 a,s32 b,s32 c,void *d) {
void func_02079c6c(s32,s32,s32 *);
void func_02091700(void *,s32);
s32 v[3];
func_02079c6c(a,b,v);
if(v[0]<128) {func_02091700(d,c);return;}
func_02091700(d,c+1);
}

void func_020c9654(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
M2C_UNK func_0208fb0c(s32,M2C_UNK,M2C_UNK);
switch(arg2) {

case 0:func_0208fb0c(129,arg0,arg1);return;
case 1:func_0208fb0c(228,arg0,arg1);return;
case 2:func_0208fb0c(228,arg0,arg1);return;
case 3:func_0208fb0c(276,arg0,arg1);return;
case 4:func_0208fb0c(273,arg0,arg1);return;
case 5:func_0208fb0c(273,arg0,arg1);return;
case 6:func_0208fb0c(273,arg0,arg1);return;
case 7:func_0208fb0c(273,arg0,arg1);return;
}}

void func_020c9730(void *arg0) {
void *func_02091270(M2C_UNK *,s32,s32);
void func_020c9654(s32,s32,s32);
extern M2C_UNK data_02120920;
void *p=func_02091270(&data_02120920,14,6);
M2C_FIELD(arg0,void **,0x54)=p;
M2C_FIELD(p,s32 *,0x28)=0x329a0;
M2C_FIELD(M2C_FIELD(arg0,void **,0x54),s32 *,0x2c)=0x1560;
func_020c960c(M2C_FIELD(arg0,s32 *,0x34)/16,M2C_FIELD(arg0,s32 *,0x38)/16,M2C_FIELD(arg0,s32 *,0x48),M2C_FIELD(arg0,void **,0x54));
M2C_FIELD(arg0,s32 *,0x50)=0x200;
M2C_FIELD(arg0,s32 *,0x4c)=-1;
func_020c9654(M2C_FIELD(arg0,s32 *,0x3c),M2C_FIELD(arg0,s32 *,0x40),M2C_FIELD(arg0,s32 *,0x44));
func_020cc6a4();
}

void func_020c97c0(void *arg0) {
    s32 func_02077700(void);
    s32 func_0207c8ec(s32, s32);
    M2C_UNK func_020910d0(s32, s32 *, s32, M2C_UNK);
    s32 func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    s32 sp[3];
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r1;
    s32 var_r1;
    u32 temp_r0_4;
    s32 field;

    temp_r0 = func_02077700();
    field = M2C_FIELD(arg0, s32 *, 0x50);
    temp_r0 = func_0207c8ec(temp_r0 * field, 0x100);
    sp[0] = M2C_FIELD(arg0, s32 *, 0x34) * 0x30;
    sp[1] = M2C_FIELD(arg0, s32 *, 0x38) * 0x30;
    sp[2] = 0x8B1;
    func_020910d0(M2C_FIELD(arg0, s32 *, 0x54), sp, temp_r0, 0);
    temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x4C);
    if (temp_r0_2 > 0) {
        temp_r0_3 = temp_r0_2 - 1;
        M2C_FIELD(arg0, s32 *, 0x4C) = temp_r0_3;
        if ((temp_r0_3 != 0) && !(*data_02101e84 & 0xC0B)) {
            return;
        }
        func_01ffa6fc(arg0);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x50);
    temp_r0_4 = (u32)(temp_r1 - 0x100);
    var_r1 = temp_r1 - ((s32)((temp_r0_4 + (temp_r0_4 >> 31)) ) >> 1);
    if ((var_r1 - 0x100) == 4) {
        M2C_FIELD(arg0, s32 *, 0x4C) = 0x1E;
        var_r1 = 0x100;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = var_r1;
}

void func_020c989c(void *arg0) {
    void func_020912a4(s32 *);
    M2C_UNK func_020d472c();
    func_020d472c();
    func_020912a4(M2C_FIELD(arg0, s32 *, 0x54));
}

u8 func_020c98b4(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_0212b3e4;
    u8 var_r0;

    if (func_01ffa770(&data_0212b3e4) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020c9b70(void) {
    M2C_UNK func_020d28bc();
    M2C_UNK func_ov000_0216aa84();
    extern void **data_027e0058;
    func_020d28bc();
    func_ov000_0216aa84();
    M2C_FIELD(*data_027e0058, s16 *, 0x52B0) = 0x12;
}

