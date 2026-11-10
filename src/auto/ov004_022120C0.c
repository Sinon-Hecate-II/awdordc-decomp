/* 5 functions from 0x022120C0 to 0x02212918 (ov004), found by ds-decomp. */
#include "common.h"
static inline s32 SpriteTile124(s32 tile) { extern s32 gCur3DSpriteEngine; return (tile >> ((u32)(*(u16 *)*(void **)gCur3DSpriteEngine <<17)>>30))&1023; }

void func_ov004_022120c0(void *arg0) {
    M2C_UNK func_020822b8();
    M2C_UNK func_0200bc5c();
    M2C_UNK func_02080cfc();
    M2C_UNK func_020811b8();
    M2C_UNK func_0208116c();
    M2C_UNK func_02007ef4();
    M2C_UNK func_020675e4();
    M2C_UNK func_020814e4();
    M2C_UNK func_020e3218();
    M2C_UNK func_02081590();
    M2C_UNK func_01ff85b8();
    M2C_UNK func_02081528();
    M2C_UNK func_020aca8c();
    M2C_UNK func_0208ca14();
    M2C_UNK func_0208c79c();
    M2C_UNK func_0208c75c();
    M2C_UNK func_0208c7b8();
    M2C_UNK func_020a8a84();
    M2C_UNK func_ov004_02212088();

    extern u16 data_ov004_02218bb8[];
    extern M2C_UNK data_ov004_02218df8;
    extern M2C_UNK data_ov004_02218e04;
    extern M2C_UNK data_ov004_02218e0c;
    extern M2C_UNK data_ov004_02218e14;
    extern M2C_UNK data_ov004_02218e1c;
    extern M2C_UNK data_ov004_02218e24;
    extern M2C_UNK data_ov004_02218e34;
    extern M2C_UNK data_ov004_02218e44;
    extern M2C_UNK data_ov004_02218e4c;
    extern M2C_UNK data_ov004_02218e5c;
    extern M2C_UNK data_ov004_02218e64;
    extern M2C_UNK data_ov004_02218e70;
    extern s32 gCurrentMap;
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;

    register void *a0 asm("r10") = arg0;
    register s32 i asm("r9");
    register u8 *bp asm("r8");

    u16 tmp[6];
    u8 buf[0x20];
    s32 oldEngine;
    s32 e;
    void *o1;
    void *o2;
    s32 map;
    s32 inner;
    u16 v;
    u8 res;

    bp = buf;

    tmp[0] = data_ov004_02218bb8[0];
    tmp[1] = data_ov004_02218bb8[1];
    tmp[2] = data_ov004_02218bb8[2];
    tmp[3] = data_ov004_02218bb8[3];
    tmp[4] = data_ov004_02218bb8[4];
    tmp[5] = data_ov004_02218bb8[5];

    map = gCurrentMap;
    inner = *(s32 *)map;
    inner = inner + 0x5100;
    v = *(u16 *)(inner + 0x42);
    res = (u8)func_020a8a84(v);
    *((u8 *)a0 + 0x3a) = res;

    oldEngine = gCur3DSpriteEngine;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            e = g3DSpriteEngineMain;
        } else {
            e = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = e;
        if (e == g3DSpriteEngineSub) {
            func_020822b8(tmp);
            func_0200bc5c(&data_ov004_02218df8);
            func_02080cfc(&data_ov004_02218e04, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
            func_02080cfc(&data_ov004_02218e0c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c));
            func_020811b8(&data_ov004_02218e14, 3, 0, 0x200);
            func_0208116c(&data_ov004_02218e1c, 0, 0x20);
            func_02007ef4(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x20, 0x20);
            func_020675e4(bp, &data_ov004_02218e24, *((u8 *)a0 + 0x3a));
            func_020814e4(bp);
            func_020675e4(bp, &data_ov004_02218e34, *((u8 *)a0 + 0x3a));
            func_02081590(func_020e3218(bp), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10) + 0x20);
            func_02080cfc(&data_ov004_02218e44, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x100, 1);
            func_020675e4(bp, &data_ov004_02218e4c, *((u8 *)a0 + 0x3a));
            func_02081590(func_020e3218(bp), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14) + 0x20);
            func_02080cfc(&data_ov004_02218e5c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
            func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), 0x100, 0x1001);
            func_02081528();
            func_02080cfc(func_020e3218(&data_ov004_02218e64), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c));
            func_0208116c(&data_ov004_02218e70, 0x200, 0x20);

            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x01;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x02;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x04;
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x08;

            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x38) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x40) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3a) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x42) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3c) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x44) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x3e) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0x46) = 0;

            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0) &= ~0x10;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0) &= ~0x20;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0) &= ~0x40;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0) |= 0x80;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0), u16 *, 0) &= ~0x100;

            func_020aca8c();

            o1 = func_0208ca14(a0);
            M2C_FIELD(a0, void **, 0x40) = o1;
            M2C_FIELD(o1, u8 *, 0x34) = 0;
            func_0208c79c(o1, 0);
            func_0208c75c(o1, 0);
            func_0208c7b8(o1, 0);

            o2 = func_0208ca14(a0);
            M2C_FIELD(a0, void **, 0x44) = o2;
            M2C_FIELD(o2, u8 *, 0x34) = 1;
            func_0208c79c(o2, 0);
            func_0208c75c(o2, 1);
            func_0208c7b8(o2, 0);
        }
    }

    gCur3DSpriteEngine = oldEngine;

    M2C_FIELD(a0, u16 *, 0x34) = 0;
    M2C_FIELD(a0, u16 *, 0x36) = 0;
    M2C_FIELD(a0, u8 *, 0x3b) = 0;
    M2C_FIELD(a0, u8 *, 0x3c) = 0;
    M2C_FIELD(a0, u8 *, 0x3d) = 0;
    M2C_FIELD(a0, u16 *, 0x38) = 0;

    func_ov004_02212088(a0);
}

void func_ov004_022124e0(s32 x,s32 y,s32 z,s32 number) {
void AddSprite(u16,u16,u16,void *,s32);extern s32 gCur3DSpriteEngine;extern M2C_UNK data_027e005c,data_027e006c;
AddSprite((u16)x,(u16)y,(u16)(z+SpriteTile124(14)),&data_027e005c,11);
AddSprite((u16)(x+32),(u16)y,(u16)(z+SpriteTile124(18)),&data_027e005c,11);
AddSprite((u16)(x+64),(u16)y,(u16)(z+SpriteTile124(number/10+22)),&data_027e006c,11);
AddSprite((u16)(x+72),(u16)y,(u16)(z+SpriteTile124(number%10+22)),&data_027e006c,11);
}

void func_ov004_02212688(s32 x, s32 y, s32 z)
{
  void AddSprite(u16, u16, u16, void *, s32);
  extern M2C_UNK data_027e005c;
  AddSprite((u16) x, (u16) y, (u16) z, &data_027e005c, 11);
  AddSprite((u16) (x + 32), (u16) y, (u16) (z + SpriteTile124(4)), &data_027e005c, 11);
  AddSprite((u16) (x + 64), (u16) y, (u16) (z + SpriteTile124(8)), &data_027e005c, 11);
  AddSprite((u16)((x + 96) | 4096), (u16) y, (u16) (z + SpriteTile124(8)), &data_027e005c, 11);
  AddSprite((u16) ((x + 128) | 4096), (u16) y, (u16) (z + SpriteTile124(4)), &data_027e005c, 11);
  x = (x+160)|4096;
  AddSprite((u16)x,(u16)y,(u16)z,&data_027e005c,11);
}

void func_ov004_0221285c(void) {
    M2C_UNK func_02082770();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r7;
    s32 var_r1;
    s32 var_r8;

    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) {
            var_r1 = g3DSpriteEngineMain;
        } else {
            var_r1 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r1;
        if (var_r1 == g3DSpriteEngineSub) {
            func_02082770();
        }
        var_r8 += 1;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
}

void func_ov004_022128b8(void *arg0) {
    M2C_UNK func_01ffa6fc();
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    u16 temp_r1;

    if ((*data_02101e84 & 0xC0B) || (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0)) {
        func_01ffa6fc();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0x38);
    if ((u32) temp_r1 < 0x384U) {
        M2C_FIELD(arg0, u16 *, 0x38) = (u16) (temp_r1 + 1);
        return;
    }
    func_01ffa6fc();
}

