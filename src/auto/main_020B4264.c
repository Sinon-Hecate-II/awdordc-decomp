/* 29 functions from 0x020B4264 to 0x020B5258 (main), found by ds-decomp. */
#include "common.h"

/* Base of the current map data: the global map pointer holds it at offset 0. */
#define MAPBASE ((u8 *)M2C_FIELD(gCurrentMap, u8 **, 0))

/* Four consecutive words, copied as one 16-byte block. */
typedef struct { u32 w0; u32 w1; u32 w2; u32 w3; } MapQuad;

s32 func_020b4264(u8 *arg0) {
    void func_020ceec8(void);
    s32 func_020cfbb0(s32);
    s32 func_020cfbdc(s32);
    void func_02068c50(u8 *, s32);
    void func_020cfa58(s32);
    void func_020ceffc(void);
    void func_020cfb54(void);
    void func_020a17c0(s32, s32);
    void func_020a23a4(s32, s32);
    void func_020a231c(s32, s32);
    void func_020a232c(s32, s32);
    void func_020a233c(s32, s32);
    void func_020a44fc(u8 *, s32);
    void func_020a16a8(u8 *);
    extern void *gCurrentMap;
    extern M2C_UNK data_0215d9b8;
    extern M2C_UNK data_02168f14;
    extern M2C_UNK data_02168f08;
    u8 *src;
    u8 *dst;
    u8 *rec;
    u8 *unit;
    u8 *ps;
    u8 *pd;
    u16 v;
    u32 n;
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    M2C_FIELD(MAPBASE, u16 *, 0x52B0) = 0xC;
    M2C_FIELD(MAPBASE, u16 *, 0x52A2) = M2C_FIELD(arg0, u16 *, 0x16);
    M2C_FIELD(MAPBASE, u16 *, 0x52A4) = M2C_FIELD(arg0, u16 *, 0x14);
    M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16)((M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x380) | ((u32)((u16)M2C_FIELD(arg0, u8 *, 0x125B) << 29) >> 22));
    M2C_FIELD(MAPBASE, u16 *, 0x52C2) = M2C_FIELD(arg0, s16 *, 0x18);
    M2C_FIELD(MAPBASE, u16 *, 0x52C4) = M2C_FIELD(arg0, s16 *, 0x1A);
    M2C_FIELD(MAPBASE, u16 *, 0x52A6) = M2C_FIELD(MAPBASE, u16 *, 0x52A4) << 5;
    M2C_FIELD(MAPBASE, u16 *, 0x52A8) = (M2C_FIELD(MAPBASE, u16 *, 0x52A4) - 1) << 6;
    M2C_FIELD(MAPBASE, u16 *, 0x52B6) = M2C_FIELD(MAPBASE, u16 *, 0x52A4);
    src = arg0 + 0x2C;
    dst = MAPBASE + 0x5120;
    pd = dst;
    n = 0x10;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        pd[0] = a;
        pd[1] = b;
        pd += 2;
        n -= 1;
    } while (n != 0);
    M2C_FIELD(pd, u8 *, 0) = M2C_FIELD(src, u8 *, 0);
    M2C_FIELD(dst, u8 *, 0x21) = M2C_FIELD(arg0, u8 *, 0x4D);
    M2C_FIELD(dst, u16 *, 0x22) = M2C_FIELD(arg0, u16 *, 0x4E);
    M2C_FIELD(dst, u16 *, 0x24) = M2C_FIELD(arg0, u16 *, 0x50);
    M2C_FIELD(dst, u16 *, 0x26) = M2C_FIELD(arg0, u16 *, 0x52);
    M2C_FIELD(dst, u16 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x54);
    M2C_FIELD(dst, u16 *, 0x2A) = M2C_FIELD(arg0, s16 *, 0x56);
    M2C_FIELD(dst, u16 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x58);
    M2C_FIELD(dst, u16 *, 0x2E) = M2C_FIELD(arg0, s16 *, 0x5A);
    M2C_FIELD(dst, u16 *, 0x30) = M2C_FIELD(arg0, u16 *, 0x5C);
    M2C_FIELD(dst, u16 *, 0x32) = M2C_FIELD(arg0, u16 *, 0x5E);
    M2C_FIELD(dst, u8 *, 0x34) = M2C_FIELD(arg0, u8 *, 0x60);
    M2C_FIELD(dst, u8 *, 0x35) = M2C_FIELD(arg0, u8 *, 0x61);
    M2C_FIELD(dst, u8 *, 0x36) = M2C_FIELD(arg0, u8 *, 0x62);
    M2C_FIELD(dst, u8 *, 0x37) = M2C_FIELD(arg0, u8 *, 0x63);
    M2C_FIELD(dst, u8 *, 0x38) = M2C_FIELD(arg0, u8 *, 0x64);
    M2C_FIELD(dst, u8 *, 0x39) = M2C_FIELD(arg0, u8 *, 0x65);
    M2C_FIELD(dst, u8 *, 0x3A) = M2C_FIELD(arg0, u8 *, 0x66);
    M2C_FIELD(dst, u8 *, 0x3B) = M2C_FIELD(arg0, u8 *, 0x67);
    M2C_FIELD(dst, u8 *, 0x3C) = M2C_FIELD(arg0, u8 *, 0x68);
    M2C_FIELD(dst, u8 *, 0x3D) = M2C_FIELD(arg0, u8 *, 0x69);
    M2C_FIELD(dst, u8 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x6A);
    M2C_FIELD(dst, u8 *, 0x3F) = M2C_FIELD(arg0, u8 *, 0x6B);
    src = arg0 + 0x6C;
    pd = dst + 0x40;
    n = 0xA1;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        pd[0] = a;
        pd[1] = b;
        pd += 2;
        n -= 1;
    } while (n != 0);
    M2C_FIELD(&data_02168f14, u16 *, 0) = M2C_FIELD(arg0, u16 *, 0x1C);
    M2C_FIELD(&data_02168f14, u8 *, 2) = M2C_FIELD(arg0, u8 *, 0x1E);
    M2C_FIELD(&data_02168f14, u8 *, 3) = M2C_FIELD(arg0, u8 *, 0x1F);
    M2C_FIELD(&data_02168f14, u16 *, 4) = M2C_FIELD(arg0, u16 *, 0x20);
    M2C_FIELD(&data_02168f14, u16 *, 6) = M2C_FIELD(arg0, u16 *, 0x22);
    M2C_FIELD(&data_02168f14, u32 *, 8) = M2C_FIELD(arg0, u32 *, 0x24);
    M2C_FIELD(&data_02168f14, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0x28);
    func_020ceec8();
    dst = MAPBASE;
    M2C_FIELD(dst, u8 *, 0x5141) = func_020cfbb0(M2C_FIELD(dst, u16 *, 0x5142));
    dst = MAPBASE;
    func_02068c50(dst + 0x5120, func_020cfbdc(M2C_FIELD(dst, u16 *, 0x5142)));
    func_020cfa58(M2C_FIELD(MAPBASE, u16 *, 0x5142));
    func_020ceffc();
    for (y = 0; y < M2C_FIELD(MAPBASE, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(MAPBASE, u16 *, 0x5144); x++) {
            M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)) * 2, u16 *, 0xA10) =
                M2C_FIELD((u8 *)M2C_FIELD(&data_02168f08, u16 **, 0) + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)) * 2, u16 *, 2);
        }
    }
    func_020cfb54();
    for (y = 0; y < M2C_FIELD(MAPBASE, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(MAPBASE, u16 *, 0x5144); x++) {
            M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)), u8 *, 0x1420) =
                M2C_FIELD(MAPBASE + M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)) * 2, u16 *, 0xA10), u8 *, 0x6A60);
        }
    }
    rec = arg0 + 0xF08;
    for (i = 0; i < 0x63; i++) {
        v = M2C_FIELD(rec, u16 *, 2);
        x = M2C_FIELD(rec, u8 *, 0);
        y = M2C_FIELD(rec, u8 *, 1);
        if (v != 0xFFFF) {
            if ((M2C_FIELD(MAPBASE + M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)) * 2, u16 *, 0xA10), u8 *, 0x6A60) & 0x1F) == 0x1C) {
                func_020a17c0(x, y);
            } else {
                M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)) * 2, u16 *, 0xA10) = v;
                M2C_FIELD(MAPBASE + (x + M2C_FIELD(MAPBASE + y * 2, u16 *, 0x3758)), u8 *, 0x1420) = M2C_FIELD(MAPBASE + v, u8 *, 0x6A60);
            }
        }
        rec += 4;
    }
    src = arg0;
    for (j = 0; j < 4; j++) {
        dst = MAPBASE + 0x67A4 + (j + 1) * 0x8C;
        M2C_FIELD(dst, u32 *, 0) = M2C_FIELD(src, u32 *, 0x1B0);
        M2C_FIELD(dst, u32 *, 4) = M2C_FIELD(src, u32 *, 0x1B4);
        M2C_FIELD(dst, u32 *, 8) = M2C_FIELD(src, u32 *, 0x1B8);
        M2C_FIELD(dst, u32 *, 0xC) = M2C_FIELD(src, u32 *, 0x1BC);
        M2C_FIELD(dst, u8 *, 0x10) = M2C_FIELD(src, u8 *, 0x1C0);
        M2C_FIELD(dst, u8 *, 0x11) = M2C_FIELD(src, u8 *, 0x1C1);
        M2C_FIELD(dst, u8 *, 0x12) = M2C_FIELD(src, u8 *, 0x1C2);
        M2C_FIELD(dst, u8 *, 0x13) = M2C_FIELD(src, u8 *, 0x1C3);
        M2C_FIELD(dst, u8 *, 0x14) = M2C_FIELD(src, u8 *, 0x1C4);
        M2C_FIELD(dst, u8 *, 0x15) = M2C_FIELD(src, u8 *, 0x1C5);
        M2C_FIELD(dst, u8 *, 0x16) = M2C_FIELD(src, u8 *, 0x1C6);
        M2C_FIELD(dst, u8 *, 0x17) = M2C_FIELD(src, u8 *, 0x1C7);
        M2C_FIELD(dst, u8 *, 0x18) = M2C_FIELD(src, u8 *, 0x1C8);
        M2C_FIELD(dst, u8 *, 0x19) = M2C_FIELD(src, u8 *, 0x1C9);
        M2C_FIELD(dst, u16 *, 0x1A) = M2C_FIELD(src, u16 *, 0x1CA);
        M2C_FIELD(dst, u8 *, 0x1C) = M2C_FIELD(src, u8 *, 0x1CC);
        M2C_FIELD(dst, u8 *, 0x1D) = M2C_FIELD(src, u8 *, 0x1CD);
        M2C_FIELD(dst, u8 *, 0x1E) = M2C_FIELD(src, u8 *, 0x1CE);
        M2C_FIELD(dst, u8 *, 0x1F) = M2C_FIELD(src, u8 *, 0x1CF);
        M2C_FIELD(dst, u16 *, 0x20) = M2C_FIELD(src, u16 *, 0x1D0);
        M2C_FIELD(dst, u16 *, 0x22) = M2C_FIELD(src, u16 *, 0x1D2);
        M2C_FIELD(dst, s8 *, 0x24) = M2C_FIELD(src, s8 *, 0x1D4);
        M2C_FIELD(dst, u8 *, 0x25) = M2C_FIELD(src, u8 *, 0x1D5);
        M2C_FIELD(dst, u8 *, 0x26) = M2C_FIELD(src, u8 *, 0x1D6);
        M2C_FIELD(dst, u8 *, 0x27) = M2C_FIELD(src, u8 *, 0x1D7);
        M2C_FIELD(dst, u8 *, 0x28) = M2C_FIELD(src, u8 *, 0x1D8);
        M2C_FIELD(dst, u8 *, 0x29) = M2C_FIELD(src, u8 *, 0x1D9);
        M2C_FIELD(dst, u8 *, 0x2A) = M2C_FIELD(src, u8 *, 0x1DA);
        M2C_FIELD(dst, u8 *, 0x2B) = M2C_FIELD(src, u8 *, 0x1DB);
        M2C_FIELD(dst, u8 *, 0x2C) = M2C_FIELD(src, u8 *, 0x1DC);
        M2C_FIELD(dst, u8 *, 0x2D) = M2C_FIELD(src, u8 *, 0x1DD);
        M2C_FIELD(dst, u8 *, 0x2E) = M2C_FIELD(src, u8 *, 0x1DE);
        M2C_FIELD(dst, u8 *, 0x2F) = M2C_FIELD(src, u8 *, 0x1DF);
        M2C_FIELD(dst, u8 *, 0x30) = M2C_FIELD(src, u8 *, 0x1E0);
        M2C_FIELD(dst, u8 *, 0x31) = M2C_FIELD(src, u8 *, 0x1E1);
        M2C_FIELD(dst, u8 *, 0x32) = M2C_FIELD(src, u8 *, 0x1E2);
        ps = dst + 0x33;
        pd = src + 0x1E3;
        n = 0xD;
        do {
            u8 a = pd[0];
            u8 b = pd[1];
            pd += 2;
            ps[0] = a;
            ps[1] = b;
            ps += 2;
            n -= 1;
        } while (n != 0);
        M2C_FIELD(ps, u8 *, 0) = M2C_FIELD(pd, u8 *, 0);
        ps = dst + 0x4E;
        pd = src + 0x1FE;
        n = 0xD;
        do {
            u8 a = pd[0];
            u8 b = pd[1];
            pd += 2;
            ps[0] = a;
            ps[1] = b;
            ps += 2;
            n -= 1;
        } while (n != 0);
        M2C_FIELD(ps, u8 *, 0) = M2C_FIELD(pd, u8 *, 0);
        M2C_FIELD(dst, u32 *, 0x6C) = M2C_FIELD(src, u32 *, 0x21C);
        M2C_FIELD(dst, u32 *, 0x70) = M2C_FIELD(src, u32 *, 0x220);
        M2C_FIELD(dst, MapQuad *, 0x74) = M2C_FIELD(src, MapQuad *, 0x224);
        M2C_FIELD(dst, u32 *, 0x84) = M2C_FIELD(src, u32 *, 0x234);
        M2C_FIELD(dst, u32 *, 0x88) = M2C_FIELD(src, u32 *, 0x238);
        src += 0x8C;
    }
    M2C_FIELD(MAPBASE, u8 *, 0x67C1) = 0;
    i = 0;
    unit = arg0;
    for (; i < 4; i++) {
        func_020a23a4(i + 1, M2C_FIELD(unit, u8 *, 0x1CE));
        func_020a231c(i + 1, M2C_FIELD(unit, u8 *, 0x1CD));
        func_020a232c(i + 1, M2C_FIELD(unit, u8 *, 0x1D6));
        func_020a233c(i + 1, M2C_FIELD(unit, u8 *, 0x1E2));
        unit += 0x8C;
    }
    for (y = 0; y < 4; y++) {
        for (i = 0; i < 0x33; i++) {
            dst = MAPBASE + 0x59A4 + (i + y * 0x40) * 0xE;
            ps = arg0 + (y * 0x33 + i) * 0xE;
            M2C_FIELD(dst, u8 *, 0) = M2C_FIELD(ps, u8 *, 0x3E0);
            M2C_FIELD(dst, u8 *, 1) = M2C_FIELD(ps, u8 *, 0x3E1);
            M2C_FIELD(dst, u8 *, 2) = M2C_FIELD(ps, u8 *, 0x3E2);
            M2C_FIELD(dst, u16 *, 4) = M2C_FIELD(ps, u16 *, 0x3E4);
            M2C_FIELD(dst, u16 *, 6) = M2C_FIELD(ps, u16 *, 0x3E6);
            M2C_FIELD(dst, u16 *, 8) = M2C_FIELD(ps, u16 *, 0x3E8);
            M2C_FIELD(dst, u8 *, 0xA) = M2C_FIELD(ps, u8 *, 0x3EA);
            M2C_FIELD(dst, u8 *, 0xB) = M2C_FIELD(ps, u8 *, 0x3EB);
            M2C_FIELD(dst, u8 *, 0xC) = M2C_FIELD(ps, u8 *, 0x3EC);
            M2C_FIELD(dst, u8 *, 0xD) = M2C_FIELD(ps, u8 *, 0x3ED);
        }
    }
    for (j = 0; j < 0x20; j++) {
        func_020a44fc(arg0 + 0x1094 + j * 8, j);
    }
    func_020a16a8(arg0 + 0x1194);
}

void func_020b4a44(void *arg0){s32 func_0207c2e0(); extern u8 data_02157718;extern M2C_UNK data_02168f68;s32 i;u8 *p;u8 v;
M2C_FIELD(arg0,s32 *,0)=func_0207c2e0();p=&data_02157718;i=0;do{v=*p++;M2C_FIELD(arg0+i,u8 *,4)=v;i++;}while(i<4);
M2C_FIELD(arg0,s16 *,8)=M2C_FIELD(&data_02168f68,s16 *,0);
M2C_FIELD(arg0,s16 *,10)=M2C_FIELD(&data_02168f68,s16 *,2);
M2C_FIELD(arg0,s16 *,12)=M2C_FIELD(&data_02168f68,s16 *,4);
M2C_FIELD(arg0,s16 *,14)=M2C_FIELD(&data_02168f68,s16 *,6);
M2C_FIELD(arg0,s32 *,16)=M2C_FIELD(&data_02168f68,s32 *,8);func_020b3c48(arg0);}

void func_020b4ab4(void *arg0) {
    M2C_UNK func_0207c2d0(s32);
    M2C_UNK func_020b4264();
    extern u8 data_02157718;
    extern M2C_UNK data_02168f68;
    s32 var_r1;
    u8 *var_r2;
    u8 temp_r0;

    func_020b4264();
    func_0207c2d0(M2C_FIELD(arg0, s32 *, 0));
    var_r2 = &data_02157718;
    var_r1 = 0;
    do {
        temp_r0 = M2C_FIELD((arg0 + var_r1), u8 *, 4);
        var_r1 += 1;
        *var_r2 = temp_r0;
        var_r2 += 1;
    } while (var_r1 < 4);
    M2C_FIELD(&data_02168f68, s16 *, 0) = (s16) M2C_FIELD(arg0, s16 *, 8);
    M2C_FIELD(&data_02168f68, s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
    M2C_FIELD(&data_02168f68, s16 *, 4) = (s16) M2C_FIELD(arg0, s16 *, 0xC);
    M2C_FIELD(&data_02168f68, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0xE);
    M2C_FIELD(&data_02168f68, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
}

void func_020b4b20(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0, 8);
}

void func_020b4b34(void) {
    M2C_UNK func_0208f8d8();
    func_0208f8d8();
}

void func_020b4b40(void *arg0){void *func_020be120();s32 func_020bf084(u8);s32 func_020bf0dc(s32,u8);u8 v=M2C_FIELD(arg0,s32 *,0x5c);func_020bee8c(v);if(!func_020bf084(v)){func_020bf0dc(0,v);func_020e4870();}func_020b4a44(func_020be120());func_020be438(v,func_020be120(),0x125c);}

void func_020b4b98(void *arg0) {
    if (func_020be4c0((u8) M2C_FIELD(arg0, s32 *, 0x5C)) == 0) {
        func_02086720(0xC000034C);
        return;
    }
    func_02086720(0);
}

void func_020b4bcc(s32 arg0, M2C_UNK arg1){extern u8 data_02168f0c;extern M2C_UNK data_0212882c;func_020b3c44();if(data_02168f0c)return;M2C_FIELD(func_01ffa444(&data_0212882c,arg1),s32 *,0x5c)=arg0;}

void func_020b4c08(u8 arg0){void *func_020be120();s32 func_020bf084(u8);s32 func_020bf0dc(s32,u8);extern M2C_UNK data_0215d9b8;extern void *gCurrentMap;void (*fn)(void);
func_020be324(arg0,func_020be120());func_020b4ab4(func_020be120());if(!func_020bf084(arg0)){M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x70)|((u32)((u16)func_020bf0dc(0,arg0)<<29)>>25);}
func_020cfd14();fn=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x50);if(fn)fn();func_020cd8a8();func_020cfd28();func_020c0a1c(3);}

void func_020b4ca0(void) {
    s32 func_020bee64();
    func_020befd8();
    if (func_020bee64() == 0) {
        func_02086720(0xC000032D);
        return;
    }
    func_02086720(0xC000032E);
}

void func_020b4cd4(M2C_UNK arg0) {
    
    s32 temp_r0;

    temp_r0 = func_020befd8();
    if (temp_r0 == 0) {
        return;
    }
    func_020b4bcc(temp_r0, arg0);
}

void func_020b4cf4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021286f4;
    func_01ffa3dc(&data_021286f4, 7);
}

void func_020b4d0c(void) {
    s32 func_020befd8();
    M2C_UNK func_020d4ac8();
    if (func_020befd8() == 0) {
        return;
    }
    func_020d4ac8();
}

void func_020b4d24(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021287b4;
    func_01ffa3dc(&data_021287b4, 7);
}

void func_020b4d3c(void *arg0) {
    M2C_UNK func_020e4870(s32);
    extern s32 data_0215d8a0;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    func_020bf054(0, temp_r4);
    func_020bef44();
    data_0215d8a0 = (data_0215d8a0 & ~0xF) | (temp_r4 & 0xF);
    func_020e4870(temp_r4);
    func_020bf798();
}

void func_020b4d80(void) {
    M2C_UNK func_02086720(s32);
    s32 func_020be4c0(M2C_UNK);
    if (func_020be4c0(4) == 0) {
        func_02086720(0xC000034C);
        return;
    }
    func_02086720(0);
}

void func_020b4db0(s32 arg0) {
    extern M2C_UNK data_0212895c;
    M2C_FIELD(func_01ffa444(&data_0212895c), s32 *, 0x5C) = arg0;
}

void func_020b4dcc(void *arg0) {
    M2C_UNK func_020bef44();
    M2C_UNK func_020bf054(M2C_UNK, s32);
    M2C_UNK func_020bf798();
    M2C_UNK func_020e4818(s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    func_020bf054(0, temp_r4);
    func_020bef44();
    func_020e4818(temp_r4);
    func_020bf798();
}

void func_020b4df4(s32 arg0) {
    extern M2C_UNK data_0212874c;
    M2C_FIELD(func_01ffa444(&data_0212874c), s32 *, 0x5C) = arg0;
}

void func_020b4e10(M2C_UNK arg0) {
    M2C_UNK func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128a0c;
    func_01ffa444(&data_02128a0c, arg0);
}

void func_020b4e28(void) {
 void func_02082cb4(void); void func_0208232c(void); void func_020d4d78(void);
 void func_020994e0(s32); void func_020c0a88(void); void func_01ff9e44(void *,s32,s32); void func_020af1c0(s32,s32);
 extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8,*data_027e00bc;
 extern u8 data_020f3c60[];
 u16 *volatile p0,*volatile p1,*volatile p2,*volatile p3,*volatile p4,*volatile p5,*volatile p6,*volatile p7,*volatile p8;
 void *saved; s32 i;
 func_02082cb4(); saved=gCur3DSpriteEngine;
 i=0; do {
 gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
 func_0208232c();
 p0=*(u16 **)gCur3DSpriteEngine; *p0 = *p0 &~0x200;
 p1=*(u16 **)gCur3DSpriteEngine; *p1 = *p1 &~0x400;
 p2=*(u16 **)gCur3DSpriteEngine; *p2 = *p2 &~0x800;
 p3=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12); *p3 = *p3 &~0xc0;
 M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
 M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
 M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
 p4=*(u16 **)gCur3DSpriteEngine; *p4 = *p4 |0x10;
 p5=*(u16 **)gCur3DSpriteEngine; *p5 = *p5 |0x20;
 p6=*(u16 **)gCur3DSpriteEngine; *p6 = *p6 |0x40;
 p7=*(u16 **)gCur3DSpriteEngine; *p7 = *p7 |0x80;
 p8=*(u16 **)gCur3DSpriteEngine; *p8 = *p8 |0x100;
 i++; }while(i<2);
 gCur3DSpriteEngine=saved; func_020d4d78();
 M2C_FIELD(data_027e00bc,u16 *,4)=(M2C_FIELD(data_027e00bc,u16 *,4)&~1)|1;
 func_020994e0(0); func_020c0a88(); func_01ff9e44(data_020f3c60,32,32);func_020af1c0(3,15);
}

s32 func_020b501c(s32 p,s32 a,s32 x,s32 y,s32 rawFlags,s32 b,s32 c){
s32 func_02077700(void);u32 flags=*(u16 *)&rawFlags;u16 tile;s32 saved=*(volatile s32 *)&c;
if(!(flags&32)){x<<=4;y<<=4;}
switch(flags&3){
case 1:x=(x+8)*48;y=(y+16)*48;break;
case 0:x=(x+8)*48;y=(y+8)*48;break;
case 2:x*=48;y*=48;break;
}
M2C_FIELD(p,s32 *,0x34)=x;M2C_FIELD(p,s32 *,0x38)=y;M2C_FIELD(p,s32 *,0x3c)=0x8b1;
M2C_FIELD(p,s32 *,0x40)=flags&8?func_02077700():0x20000;
if(flags&64)M2C_FIELD(p,u32 *,0x44)&=~0x80000;
else M2C_FIELD(p,u32 *,0x44)|=0x80000;
tile=(u16)(saved+0xab);
if(flags&16)func_0208bd2c(p,a,b+0x329a0,tile,0);
else func_0208bd2c(p,a,b+0x329a0,tile,1);
}

s32 func_020b5134(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6) {
    s32 func_0208c528(s32);
    M2C_UNK func_020b501c(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    s32 temp_r0;

    temp_r0 = func_0208c528(arg6);
    func_020b501c(temp_r0, arg0, arg1, arg2, arg3, arg4, (s32) arg5);
    return temp_r0;
}

s32 func_020b5188(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6) {
    s32 func_0208c54c(s32);
    s32 temp_r0;

    temp_r0 = func_0208c54c(arg6);
    func_020b501c(temp_r0, arg0, arg1, arg2, arg3, arg4, (s32) arg5);
    return temp_r0;
}

void func_020b51dc(void) {
    extern s32 data_0215d848;
    data_0215d848 = 0;
}

s32 func_020b51f0(void) {
    extern s32 data_0215d848;
    return data_0215d848;
}

s32 func_020b5200(s32 arg0,s32 arg1){s32 func_0208c570(s32,s32,u16);extern s32 data_0215d848;s32 old=data_0215d848;data_0215d848+=func_0208c570(arg0,old+0x329a0,(u16)(arg1+0xab));return old;}

void func_020b5240(void) {
    M2C_UNK func_0208c69c();
    func_0208c69c();
}

void func_020b524c(void) {
    M2C_UNK func_0208c6fc();
    func_0208c6fc();
}

