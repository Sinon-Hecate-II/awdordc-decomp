/* 10 functions from 0x0216B898 to 0x0216C7F0 (ov000), found by ds-decomp. */
#include "common.h"

M2C_UNK func_ov000_0216b898(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x36) == 0) return 0;
    return 0;
}

void func_ov000_0216bfa4(void *arg0) {
extern u16 *data_02101e84;
extern u8 *data_02101e88;
func_020a91a8(M2C_FIELD(arg0,s32 *,0x44));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x48));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x4c));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x50));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x54));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x58));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x5c));
switch(M2C_FIELD(arg0,u16 *,0x34)){
case 8:func_0208fe30(0x1003e);
case 0x68:func_0208fe30(0x1003f);
}
if((*data_02101e84 &9)||data_02101e88[0x14]||M2C_FIELD(arg0,u16 *,0x34)==0x83)func_01ffa6fc(arg0);
M2C_FIELD(arg0,u16 *,0x34)++;
}

void func_ov000_0216c068(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    M2C_FIELD(arg0, u8 *, 0x36) = 0;
}

void func_ov000_0216c09c(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
func_020c0a88();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_ov000_0216c1c4(void) {
    M2C_UNK func_ov000_0216b194();
    func_ov000_0216b194();
}

void func_ov000_0216c1d0(void) {
    void func_ov000_0216c09c(void);
    func_ov000_0216c09c();
}

void func_ov000_0216c1dc(void) {
    void func_ov000_0216c068();
    func_ov000_0216c068();
}

void func_ov000_0216c1e8(void) {
    M2C_UNK func_ov000_0216b898();
    func_ov000_0216b898();
}

void func_ov000_0216c1f4(void) {
    void func_ov000_0216bfa4();
    func_ov000_0216bfa4();
}

void func_ov000_0216c200(void) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(M2C_UNK);
    M2C_UNK func_020a9218(void *);
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02168f14;
    extern void **data_027e0058;
    extern M2C_UNK data_ov000_021b83f8;
    extern M2C_UNK data_ov000_021b841c;
    extern M2C_UNK data_ov000_021b844c;
    extern M2C_UNK data_ov000_021b8488;
    extern M2C_UNK data_ov000_021b84c4;
    extern M2C_UNK data_ov000_021b8500;
    extern M2C_UNK data_ov000_021b853c;
    extern M2C_UNK data_ov000_021b8578;
    extern M2C_UNK data_ov000_021b8690;
    s8 var_r0;
    u16 temp_ip;
    void *mapPtr;
    void *temp_r0;
    void *temp_r0_10;
    void *temp_r0_11;
    void *temp_r0_12;
    void *temp_r0_13;
    void *temp_r0_14;
    void *temp_r0_15;
    void *temp_r0_16;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r0_8;
    void *temp_r0_9;

    temp_r0 = func_01ffa3dc(&data_ov000_021b8578, 7);
    if (temp_r0 == NULL) {
        return;
    }
    var_r0 = 0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov000_021b8690;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x36) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x38) = 0x100;
    temp_ip = (u16)M2C_FIELD(*data_027e0058, u16 *, 0x52A4);
    M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8)temp_ip;
    mapPtr = (void*)*data_027e0058;
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8)M2C_FIELD((mapPtr + ((s32)(u8)temp_ip * 0x8C)), u8 *, 0x67CB);
    mapPtr = (void*)*data_027e0058;
    M2C_FIELD(temp_r0, s8 *, 0x3C) = (s8)(M2C_FIELD((mapPtr + ((s32)M2C_FIELD(temp_r0, u8 *, 0x3A) * 0x8C)), u8 *, 0x67C1) - 1);
    if (M2C_FIELD(&data_02168f14, u8 *, 3) != 0) {
        var_r0 = 1;
    }
    M2C_FIELD(temp_r0, s8 *, 0x3D) = var_r0;
    M2C_FIELD(temp_r0, s16 *, 0x3E) = 0;
    temp_r0_2 = func_02082028(0x2C);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_02129870;
        M2C_FIELD(temp_r0_2, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_2, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_2, s8 *, 0x18) = 8;
        {
            u8 a = (u8)(M2C_FIELD(temp_r0_2, u8 *, 0x20) & ~1);
            u8 b = (u8)(a & ~0x1E);
            M2C_FIELD(temp_r0_2, u8 *, 0x20) = (u8)((b & ~0xE0) | 0x40);
        }
        M2C_FIELD(temp_r0_2, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_2, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_2, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_2, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_2, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x40) = temp_r0_2;
    temp_r0_3 = func_02082028(0x10);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(temp_r0_3, M2C_UNK **, 4) = &data_ov000_021b844c;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 8) = &data_ov000_021b844c;
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0;
        temp_r0_4 = func_02082028(0x12);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_3, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_4, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_4, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_4, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = (u16) M2C_FIELD(temp_r0_4, u16 *, 4);
        }
        M2C_FIELD(temp_r0_3, void **, 0) = temp_r0_4;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_3, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_3);
        M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_3;
    temp_r0_5 = func_02082028(0x10);
    if (temp_r0_5 != NULL) {
        M2C_FIELD(temp_r0_5, M2C_UNK **, 4) = &data_ov000_021b8488;
        M2C_FIELD(temp_r0_5, M2C_UNK **, 8) = &data_ov000_021b8488;
        M2C_FIELD(temp_r0_5, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xF) = 0;
        temp_r0_6 = func_02082028(0x12);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_5, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_6, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_6, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_6, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = (u16) M2C_FIELD(temp_r0_6, u16 *, 4);
        }
        M2C_FIELD(temp_r0_5, void **, 0) = temp_r0_6;
        M2C_FIELD(temp_r0_5, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_5, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_5, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_5);
        M2C_FIELD(temp_r0_5, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_5, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x48) = temp_r0_5;
    temp_r0_7 = func_02082028(0x10);
    if (temp_r0_7 != NULL) {
        M2C_FIELD(temp_r0_7, M2C_UNK **, 4) = &data_ov000_021b84c4;
        M2C_FIELD(temp_r0_7, M2C_UNK **, 8) = &data_ov000_021b84c4;
        M2C_FIELD(temp_r0_7, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xF) = 0;
        temp_r0_8 = func_02082028(0x12);
        if (temp_r0_8 != NULL) {
            M2C_FIELD(temp_r0_8, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_7, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_8, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_8, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_8, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_8, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_8, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_8, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_8, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_8, u16 *, 2) = (u16) M2C_FIELD(temp_r0_8, u16 *, 4);
        }
        M2C_FIELD(temp_r0_7, void **, 0) = temp_r0_8;
        M2C_FIELD(temp_r0_7, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_7, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_7, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_7);
        M2C_FIELD(temp_r0_7, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x4C) = temp_r0_7;
    temp_r0_9 = func_02082028(0x10);
    if (temp_r0_9 != NULL) {
        M2C_FIELD(temp_r0_9, M2C_UNK **, 4) = &data_ov000_021b853c;
        M2C_FIELD(temp_r0_9, M2C_UNK **, 8) = &data_ov000_021b853c;
        M2C_FIELD(temp_r0_9, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xF) = 0;
        temp_r0_10 = func_02082028(0x12);
        if (temp_r0_10 != NULL) {
            M2C_FIELD(temp_r0_10, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_9, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_10, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_10, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_10, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_10, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_10, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_10, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_10, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_10, u16 *, 2) = (u16) M2C_FIELD(temp_r0_10, u16 *, 4);
        }
        M2C_FIELD(temp_r0_9, void **, 0) = temp_r0_10;
        M2C_FIELD(temp_r0_9, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_9, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_9, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_9);
        M2C_FIELD(temp_r0_9, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_9;
    temp_r0_11 = func_02082028(0x10);
    if (temp_r0_11 != NULL) {
        M2C_FIELD(temp_r0_11, M2C_UNK **, 4) = &data_ov000_021b83f8;
        M2C_FIELD(temp_r0_11, M2C_UNK **, 8) = &data_ov000_021b83f8;
        M2C_FIELD(temp_r0_11, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xF) = 0;
        temp_r0_12 = func_02082028(0x12);
        if (temp_r0_12 != NULL) {
            M2C_FIELD(temp_r0_12, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_11, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_12, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_12, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_12, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_12, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_12, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_12, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_12, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_12, u16 *, 2) = (u16) M2C_FIELD(temp_r0_12, u16 *, 4);
        }
        M2C_FIELD(temp_r0_11, void **, 0) = temp_r0_12;
        M2C_FIELD(temp_r0_11, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_11, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_11, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_11);
        M2C_FIELD(temp_r0_11, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_11, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_11;
    temp_r0_13 = func_02082028(0x10);
    if (temp_r0_13 != NULL) {
        M2C_FIELD(temp_r0_13, M2C_UNK **, 4) = &data_ov000_021b841c;
        M2C_FIELD(temp_r0_13, M2C_UNK **, 8) = &data_ov000_021b841c;
        M2C_FIELD(temp_r0_13, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xF) = 0;
        temp_r0_14 = func_02082028(0x12);
        if (temp_r0_14 != NULL) {
            M2C_FIELD(temp_r0_14, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_13, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_14, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_14, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_14, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_14, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_14, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_14, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_14, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_14, u16 *, 2) = (u16) M2C_FIELD(temp_r0_14, u16 *, 4);
        }
        M2C_FIELD(temp_r0_13, void **, 0) = temp_r0_14;
        M2C_FIELD(temp_r0_13, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_13, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_13, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_13);
        M2C_FIELD(temp_r0_13, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_13, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x58) = temp_r0_13;
    temp_r0_15 = func_02082028(0x10);
    if (temp_r0_15 != NULL) {
        M2C_FIELD(temp_r0_15, M2C_UNK **, 4) = &data_ov000_021b8500;
        M2C_FIELD(temp_r0_15, M2C_UNK **, 8) = &data_ov000_021b8500;
        M2C_FIELD(temp_r0_15, s16 *, 0xC) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xF) = 0;
        temp_r0_16 = func_02082028(0x12);
        if (temp_r0_16 != NULL) {
            M2C_FIELD(temp_r0_16, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(temp_r0_15, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(temp_r0_16, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_16, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_16, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_16, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_16, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_16, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_16, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_16, u16 *, 2) = (u16) M2C_FIELD(temp_r0_16, u16 *, 4);
        }
        M2C_FIELD(temp_r0_15, void **, 0) = temp_r0_16;
        M2C_FIELD(temp_r0_15, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(temp_r0_15, M2C_UNK **, 4);
        M2C_FIELD(temp_r0_15, s16 *, 0xC) = 0;
        func_020a9218(temp_r0_15);
        M2C_FIELD(temp_r0_15, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0_15, s8 *, 0xF) = 0;
    }
    M2C_FIELD(temp_r0, void **, 0x5C) = temp_r0_15;
}

