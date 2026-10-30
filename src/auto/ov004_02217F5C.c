/* 6 functions from 0x02217F5C to 0x02218BAC (ov004), found by ds-decomp. */
#include "common.h"

void func_ov004_022188b8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov004_022188c4(void *a){extern void **gCurrentMap;extern u32 data_0215d8a0[2];func_0208fe30(0x10014);data_0215d8a0[1]=(data_0215d8a0[1]&~0xffff)|(u16)(M2C_FIELD(*gCurrentMap,u16 *,0x5142)-0xa1);if(func_020a8958(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))func_01ffa8c4(a,7);M2C_FIELD(a,u8 *,0x38)=2;M2C_FIELD(a,u8 *,0x36)=0;}

/* Advance a 16-frame transition, linearly raising the 3D sprite engine's visibility and setting its display flags. */
void func_ov004_02218950(void *transition) {
    void func_01ffa6fc(void *);
    s8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, u8, s32);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
    u16 *volatile flagsC0;
    u16 *volatile flags01;
    u16 *volatile flags02;
    u16 *volatile flags04;
    u16 *volatile flags08;
    u16 *volatile flags10;
    u16 *volatile flags100;
    u16 *volatile flags200;
    u16 *volatile flags400;
    u16 *volatile flags800;
    u16 *volatile flags1000;
    s8 visibility;
    void **previousEngine;
    void *engine01;
    void *engine02;
    void *engine04;
    void *engine08;
    void *engine10;
    void *engine100;
    void *engine200;
    void *engine400;
    void *engine800;
    void *engine1000;
    void *engine;

    M2C_FIELD(transition, u8 *, 0x36) = (u8) (M2C_FIELD(transition, u8 *, 0x36) + 1);
    visibility = func_0207ca38(0, 0, 8, M2C_FIELD(transition, u8 *, 0x36), 0x10);
    previousEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    engine = *data_027e00c8;
    flagsC0 = engine + 0x12;
    *flagsC0 = (s16) ((*flagsC0 & ~0xC0) | 0xC0);
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x51) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x52) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, 0x53) = visibility;
    engine01 = *gCur3DSpriteEngine;
    flags01 = engine01 + 0x12;
    *flags01 = (s16) ((*flags01 & ~1) | 1);
    engine02 = *gCur3DSpriteEngine;
    flags02 = engine02 + 0x12;
    *flags02 = (s16) (*flags02 | 2);
    engine04 = *gCur3DSpriteEngine;
    flags04 = engine04 + 0x12;
    *flags04 = (s16) (*flags04 | 4);
    engine08 = *gCur3DSpriteEngine;
    flags08 = engine08 + 0x12;
    *flags08 = (s16) (*flags08 | 8);
    engine10 = *gCur3DSpriteEngine;
    flags10 = engine10 + 0x12;
    *flags10 = (s16) (*flags10 | 0x10);
    engine100 = *gCur3DSpriteEngine;
    flags100 = engine100 + 0x12;
    *flags100 = (s16) (*flags100 & ~0x100);
    engine200 = *gCur3DSpriteEngine;
    flags200 = engine200 + 0x12;
    *flags200 = (s16) (*flags200 & ~0x200);
    engine400 = *gCur3DSpriteEngine;
    flags400 = engine400 + 0x12;
    *flags400 = (s16) (*flags400 & ~0x400);
    engine800 = *gCur3DSpriteEngine;
    flags800 = engine800 + 0x12;
    *flags800 = (s16) (*flags800 & ~0x800);
    engine1000 = *gCur3DSpriteEngine;
    flags1000 = engine1000 + 0x12;
    *flags1000 = (s16) (*flags1000 & ~0x1000);
    gCur3DSpriteEngine = previousEngine;
    if ((u32) M2C_FIELD(transition, u8 *, 0x36) < 0x10U) {
        return;
    }
    func_01ffa6fc(transition);
}

void func_ov004_02218b7c(M2C_UNK arg0) {
    M2C_UNK func_ov003_021ff3ac();
    M2C_UNK func_ov004_02213124(M2C_UNK);
    func_ov003_021ff3ac();
    func_ov004_02213124(arg0);
}

void func_ov004_02218b94(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_0223c684;
    func_01ffa42c(&data_ov004_0223c684, arg0);
}

