/* 30 functions from 0x022162F4 to 0x022172B0 (ov006), found by ds-decomp. */
#include "common.h"

void func_ov006_0221679c(void *arg0) {
 M2C_UNK func_02087e34(s32);
 M2C_UNK func_020b2140();
 M2C_UNK func_020b2178();
 func_020b2178();
 func_02087e34(M2C_FIELD(arg0, s32 *, 0x40));
 func_020b2140();
}

void func_ov006_022167b8(void) {
    M2C_UNK func_ov006_0221619c();
    func_ov006_0221619c();
}

void func_ov006_02216bac(void) {
    M2C_UNK func_ov006_0221661c();
    func_ov006_0221661c();
}

void func_ov006_02216bb8(void) {
    void func_ov006_0221679c();
    func_ov006_0221679c();
}

void func_ov006_02216bc4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_020a8f8c(void *);
    void *ptr = M2C_FIELD(arg0, void **, 0x48);
    u8 equal = M2C_FIELD(ptr, u16 *, 2) == M2C_FIELD(ptr, s16 *, 0xC);
    if (equal) {
        func_01ffa6fc(arg0);
        return;
    }
    func_020a8f8c(ptr);
}

void func_ov006_02216bfc(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov006_02216c10(void) {
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    func_020b1c44(0, 0);
}

void *func_ov006_02216da4(void *arg0) {
 M2C_UNK func_02082040(void *);
 M2C_UNK func_020e35cc(s32);
 extern M2C_UNK data_ov006_022188f8;
 void *temp_r4;
 void *temp_r0;
 M2C_FIELD(arg0, void **, 0) = &data_ov006_022188f8;
 temp_r4 = M2C_FIELD(arg0, void **, 0x40);
 if (temp_r4 != NULL) {
 func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
 func_02082040(temp_r4);
 }
 temp_r0 = M2C_FIELD(arg0, void **, 0x44);
 if (temp_r0 != NULL) {
 M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
 }
 temp_r0 = M2C_FIELD(arg0, void **, 0x48);
 if (temp_r0 != NULL) func_02082040(temp_r0);
 func_02082040(arg0);
 return arg0;
}

void *func_ov006_02216e0c(void *arg0) {
 M2C_UNK func_02082040(void *);
 M2C_UNK func_020e35cc(s32);
 extern M2C_UNK data_ov006_022188f8;
 void *temp_r4;
 void *temp_r0;
 M2C_FIELD(arg0, void **, 0) = &data_ov006_022188f8;
 temp_r4 = M2C_FIELD(arg0, void **, 0x40);
 if (temp_r4 != NULL) {
 func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
 func_02082040(temp_r4);
 }
 temp_r0 = M2C_FIELD(arg0, void **, 0x44);
 if (temp_r0 != NULL) {
 M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
 }
 temp_r0 = M2C_FIELD(arg0, void **, 0x48);
 if (temp_r0 != NULL) func_02082040(temp_r0);
 
 return arg0;
}

u8 func_ov006_02216e6c(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

u8 func_ov006_02216e84(void) {
    s32 func_020846a4();
    s32 func_0208485c();
    s32 result;
    if (func_020846a4() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov006_02216eb0(void) {
    void *func_ov006_02217164(void);
    return M2C_FIELD(func_ov006_02217164(), u8 *, 0x34) == 1;
}

u8 func_ov006_02216ed0(void) {
    void *func_ov006_02217164(void);
    return M2C_FIELD(func_ov006_02217164(), u8 *, 0x34) == 2;
}

u8 func_ov006_02216ef0(void) {
    void *func_ov006_02217164(void);
    return M2C_FIELD(func_ov006_02217164(), u8 *, 0x34) == 3;
}

u8 func_ov006_02216f10(void) {
 void *func_ov006_02217164(void);
 return M2C_FIELD(func_ov006_02217164(),u8 *,0x34)==4;
}

void func_ov006_02216f30(void) {
    u8 func_ov006_02216e6c(s32, s32, s32);
    extern void **data_027e0058;
    func_ov006_02216e6c(M2C_FIELD(*data_027e0058, s16 *, 0x5142), 0xE1, 0x1A9);
}

void func_ov006_02216f5c(void *arg0) {
 M2C_UNK func_02007e98(M2C_UNK,s32,s32);
 M2C_UNK func_02007ef4(s32,s32,s32);
 M2C_UNK func_02085724(void *,s32,s32,void *);
 M2C_UNK func_020c8e40();
 s32 base; u8 n;
 func_020c8e40();
 func_02007e98(0,M2C_FIELD(arg0,s32 *,0x38)+0x1068,0x3138);
 n=M2C_FIELD(arg0,u8 *,0x4c);
 if(n) { base=M2C_FIELD(arg0,s32 *,0x38); func_02007ef4(base,(s32)((s32 (*)[21])base+n*0x32),0x1068); }
 func_02085724(arg0+0x3c,M2C_FIELD(arg0+M2C_FIELD(arg0,u8 *,0x4c)*4,s32 *,0x3c),0x1068,arg0);
}

void func_ov006_02216fd0(void *arg0) {
 extern void **data_027e0058;
 s32 func_0207c8ec(s32,s32);
 s32 func_020c79ec();
 M2C_UNK func_020c85c4(u16,s32);
 s32 func_020be120();
 M2C_UNK func_0208547c(s32,s32,void *);
 M2C_UNK func_0208559c(s32,s32,void *);
 u16 value=M2C_FIELD(*data_027e0058,u16 *,0x5142);
 u16 n=func_0207c8ec(value-0xe1,0x32);
 if(!func_ov006_02216e6c((s16)value,0xe1,0x1a9)) return;
 if(M2C_FIELD(arg0,u8 *,0x4c)==n) {
 func_020c85c4((u16)(value-n*0x32),func_020c79ec());
 func_0208547c(func_020be120(),0x6f8,arg0);
 return;
 }
 func_0208559c(func_020be120(),0x6f8,arg0);
}

void func_ov006_02217078(void *arg0) {
 void *func_020bfa74();
 M2C_UNK func_0208547c(s32,s32,void *);
 M2C_UNK func_0208559c(s32,s32,void *);
 if(M2C_FIELD(arg0,u8 *,0x4c)==0) { func_0208547c((s32)func_020bfa74(),0x10,arg0); return; }
 func_0208559c((s32)func_020bfa74(),0x10,arg0);
}

void func_ov006_022170b4(void *arg0) {
    void *func_020bfa74();
    M2C_UNK func_020c002c(M2C_UNK);
    M2C_UNK func_020cf0a8(u32);
    func_020cf0a8((u32) (M2C_FIELD(func_020bfa74(), s32 *, 8) << 0x14) >> 0x15);
    if (M2C_FIELD(arg0, u8 *, 0x4C) == 0) {
        return;
    }
    func_020c002c(0);
}

void func_ov006_022170e8(void *arg0) {
    M2C_UNK func_0208547c(s32, s32, void *);
    M2C_UNK func_0208559c(s32, s32, void *);
    u8 func_ov006_02216e84();
    if (func_ov006_02216e84() != 0) {
        func_0208547c(M2C_FIELD(arg0, s32 *, 0x50), 0x22D8, arg0);
        return;
    }
    func_0208559c(M2C_FIELD(arg0, s32 *, 0x54), 0x22D8, arg0);
}

void func_ov006_02217124(void *arg0) {
    if (func_ov006_02216e84() != 0) {
        func_0208559c(M2C_FIELD(arg0, s32 *, 0x54), 0x22D8, arg0);
        return;
    }
    func_0208547c(M2C_FIELD(arg0, s32 *, 0x50), 0x22D8, arg0);
}

void func_ov006_02217160(void) {

}

void *func_ov006_02217164(void) {
    void *func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov006_02218918;
    return func_01ffa770(&data_ov006_02218918);
}

void func_ov006_02217178(M2C_UNK arg0) {s8 func_020848c4(); u8 func_020848f8(); s32 func_020c7e58(M2C_UNK);
void *func_01ffa42c(void *,M2C_UNK);
extern M2C_UNK data_ov006_0221890c,data_ov006_02218918;
u8 i; void *p=func_01ffa42c(&data_ov006_02218918,arg0);
if(p) {
M2C_FIELD(p,void **,0)=&data_ov006_0221890c;
M2C_FIELD(p,u8 *,0x34)=1;
M2C_FIELD(p,s32 *,0x50)=0;M2C_FIELD(p,s32 *,0x54)=0;
M2C_FIELD(p,s8 *,0x4c)=func_020848c4();
M2C_FIELD(p,u8 *,0x4d)=func_020848f8();
M2C_FIELD(p,s32 *,0x38)=func_020c7e58(0);
i=0;
do {
if(M2C_FIELD(p,u8 *,0x4d)&(1<<i))
M2C_FIELD(p+i*4,s32 *,0x3c)=(s32)((u8 (*)[0x54])M2C_FIELD(p,s32 *,0x38)+i*0x32);
i++;
}while(i<4);
}
}

void func_ov006_02217214(M2C_UNK arg0) {s8 func_020848c4(); u8 func_020848f8(); s32 func_020c7e58(M2C_UNK);
void *func_01ffa42c(void *,M2C_UNK);
extern M2C_UNK data_ov006_0221890c,data_ov006_02218918;
u8 i; void *p=func_01ffa42c(&data_ov006_02218918,arg0);
if(p) {
M2C_FIELD(p,void **,0)=&data_ov006_0221890c;
M2C_FIELD(p,u8 *,0x34)=2;
M2C_FIELD(p,s32 *,0x50)=0;M2C_FIELD(p,s32 *,0x54)=0;
M2C_FIELD(p,s8 *,0x4c)=func_020848c4();
M2C_FIELD(p,u8 *,0x4d)=func_020848f8();
M2C_FIELD(p,s32 *,0x38)=func_020c7e58(0);
i=0;
do {
if(M2C_FIELD(p,u8 *,0x4d)&(1<<i))
M2C_FIELD(p+i*4,s32 *,0x3c)=(s32)((u8 (*)[0x54])M2C_FIELD(p,s32 *,0x38)+i*0x32);
i++;
}while(i<4);
}
}

