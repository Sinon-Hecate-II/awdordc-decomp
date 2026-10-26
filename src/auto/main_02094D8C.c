/* 17 functions from 0x02094D8C to 0x02095C90 (main), found by ds-decomp. */
#include "common.h"

void func_02094d8c(M2C_UNK arg0) {
    s32 func_0209600c();
    M2C_UNK func_02097a2c(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097a2c(arg0);
}

void func_02094dac(void) {
    s32 func_02091db4();
    M2C_UNK func_020979a4(M2C_UNK);
    s32 temp_r0;

    if (func_0209600c() != 0) {
        return;
    }
    temp_r0 = func_02091db4();
    switch (temp_r0) {                              /* irregular */
    case 0:
    case 1:
        func_020979a4(-1);
        return;
    case 2:
        func_02097a2c(-1);
        return;
    }
}

void func_02095250(s32 arg0) {
extern M2C_UNK data_02102aa8;
if(func_0209600c())return;
switch(arg0) {
case 100:func_0208f890();return;
case 101:func_01ffa3dc(&data_02102aa8,7);return;
default:func_0208f780(func_020ad584(arg0));return;
}
}

u8 func_020952a4(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102aa8;
    u8 var_r0;

    if (func_01ffa770(&data_02102aa8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020952c8(M2C_UNK arg0) {
    M2C_UNK func_0208fe30();
    M2C_UNK func_020ad560(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_020ad560(arg0);
    func_0208fe30();
}

void func_020952ec(s32 arg0,s32 arg1,s32 arg2) {
u32 value=(u8)func_02091e44();
if(func_0209600c())arg2=0;
switch(arg0) {
case 0:func_020ad150((u8)arg1,(u16)arg2,value,7);return;
case 1:func_020ad1f8((u8)arg1,(u16)arg2,value,7);return;
}
}

void func_0209535c(s32 arg0) {
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 saved,i,v;
if(func_020ad3f0()) {
if(!func_02096064())return;
saved=gCur3DSpriteEngine;
i=0;
do {
if(i==0)v=data_027e00c8;else v=data_027e00c4;
gCur3DSpriteEngine=v;
func_020ace54();
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
func_01ffa6fc(arg0);
}

void func_020953d0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102ac8;
    func_01ffa3dc(&data_02102ac8, 7);
}

u8 func_020953e8(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102ac8;
    u8 var_r0;

    if (func_01ffa770(&data_02102ac8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0209540c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 func_02096064();
    s16 temp_r1;

    if (func_02096064() != 0) {
        func_01ffa6fc(arg0);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x6C);
    M2C_FIELD(arg0, s16 *, 0x6C) = (s16) (temp_r1 - 1);
    if (temp_r1 != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_0209544c(s16 arg0) {
    extern M2C_UNK data_02102a88;
    M2C_FIELD(func_01ffa3dc(&data_02102a88, 7), s16 *, 0x6C) = arg0;
}

u8 func_0209546c(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102a88;
    u8 var_r0;

    if (func_01ffa770(&data_02102a88) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02095c58(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102ae8;
    void *temp_r0;

    if (func_0209600c() != 0) {
        return;
    }
    temp_r0 = func_01ffa42c(&data_02102ae8, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x5C) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = arg1;
}

