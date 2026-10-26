/* 39 functions from 0x0207B2F0 to 0x0207C2F0 (main), found by ds-decomp. */
#include "common.h"

u8 func_0207b7c4(void);
void func_0207b754(M2C_UNK, M2C_UNK);

s32 func_0207b5ac(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207b2f0(s32 *, s32 *, s32);
    void *func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_02100c20;
    extern void *data_027e0058;
    void *p;
    if (func_0207b7c4() != 0) return 1;
    if (func_0207b2f0(&arg0, &arg1, arg2) == 0) return 0;
    M2C_FIELD(M2C_FIELD(data_027e0058, void **, 0), u8 *, 0x5154) = 0;
    p = func_01ffa3dc(&data_02100c20, 7);
    M2C_FIELD(p, s16 *, 0x38) = arg0 << 4;
    M2C_FIELD(p, s16 *, 0x3A) = arg1 << 4;
    return 1;
}

s32 func_0207b648(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207b2f0(s32 *, s32 *, s32);
    extern void *data_027e0058;
    void (*callback)(void);
    if (func_0207b2f0(&arg0, &arg1, arg2) == 0) return 0;
    M2C_FIELD(M2C_FIELD(data_027e0058, void **, 0), s16 *, 0x5148) = arg0 << 4;
    M2C_FIELD(M2C_FIELD(data_027e0058, void **, 0), s16 *, 0x514A) = arg1 << 4;
    callback = M2C_FIELD(M2C_FIELD(data_027e0058, void **, 4), void (**)(void), 0x1C);
    if (callback != NULL) callback();
    return 1;
}

void func_0207b6d0(void) {
    s32 func_020d1938(s32);
    s32 func_020d243c(s32);
    extern void *data_027e0058;
    u32 x, y;
    void *p;
    if (func_020d1938(1) != 0 && func_020d243c(1) != 0) {
        p = M2C_FIELD(data_027e0058, void **, 0);
        x = M2C_FIELD(p, u8 *, 0x685B) & 0x7F;
        y = M2C_FIELD(p, u8 *, 0x685C) & 0x7F;
    } else {
        p = M2C_FIELD(data_027e0058, void **, 0);
        x = (u32) M2C_FIELD(p, u16 *, 0x5144) >> 1;
        y = (u32) M2C_FIELD(p, u16 *, 0x5146) >> 1;
    }
    func_0207b754(x, y);
}

void func_0207b744(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0207b648(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0207b648(arg0, arg1, 0);
}

void func_0207b754(M2C_UNK arg0, M2C_UNK arg1) {
    func_0207b648(arg0, arg1, 1);
}

s32 func_0207b764(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0207b5ac(M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0207b5ac(arg0, arg1, 0);
}

s32 func_0207b774(M2C_UNK arg0, M2C_UNK arg1) {
    return func_0207b5ac(arg0, arg1, 1);
}

s32 func_0207b784(void *arg0) {
    if (arg0 == NULL) return 0;
    return func_0207b764(M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

s32 func_0207b7a4(void *arg0) {
    if (arg0 == NULL) return 0;
    return func_0207b774(M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 func_0207b7c4(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02100c20;
    u8 var_r0;

    if (func_01ffa770(&data_02100c20) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0207b7e8(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02100bf8;
    func_01ffa42c(&data_02100bf8, arg0);
}

void func_0207b800(void) {
    extern M2C_UNK data_02144d60;
    extern M2C_UNK data_02144d64;
    extern M2C_UNK data_02144dc8;
    extern M2C_UNK data_02144f98;
    extern void *data_027e0058;
    M2C_FIELD(data_027e0058, M2C_UNK **, 0) = &data_02144f98;
    M2C_FIELD(data_027e0058, M2C_UNK **, 4) = &data_02144d64;
    M2C_FIELD(data_027e0058, M2C_UNK **, 8) = &data_02144d60;
    M2C_FIELD(data_027e0058, M2C_UNK **, 0xC) = &data_02144dc8;
}

void func_0207b84c(void) {
void func_020822b8(void *);
extern M2C_UNK data_02100c64,data_02100c70;
extern u16 *data_027e00bc;
extern u16 **data_027e00c8, **gCur3DSpriteEngine;
u16 *volatile p0; u16 *volatile p1; u16 *volatile p2; u8 equal;
*data_027e00bc |=8;
p0=*gCur3DSpriteEngine; *p0=*p0 & ~7;
func_020822b8(&data_02100c64);
if(gCur3DSpriteEngine==data_027e00c8)equal=1;else equal=0;
if(equal){
*data_027e00bc |=8;
p1=*gCur3DSpriteEngine; *p1=*p1 & ~7;
func_020822b8(&data_02100c64);
return;
}
p2=*gCur3DSpriteEngine; *p2=*p2 & ~7;
func_020822b8(&data_02100c70);
}

void func_0207b940(void) {
    void func_020822b8(void *);
    extern M2C_UNK data_02100c58, data_02100c70;
    extern u16 *data_027e00bc;
    extern u16 **data_027e00c8, **gCur3DSpriteEngine;
    u16 *sp4;
    u16 *sp0;
    u8 equal;
    if (gCur3DSpriteEngine == data_027e00c8) equal = 1; else equal = 0;
    if (equal) {
        *data_027e00bc &= ~8;
        sp4 = *gCur3DSpriteEngine;
        *sp4 = *sp4 & ~7;
        func_020822b8(&data_02100c58);
        return;
    }
    sp0 = *gCur3DSpriteEngine;
    *sp0 = *sp0 & ~7;
    func_020822b8(&data_02100c70);
}

/* Convert a tile type into the movement/collision result used by callers. */
u32 func_0207b9f4(s32 tileX, s32 tileY, u32 tileType) {
    u32 func_0207badc(s32, s32, M2C_UNK);
    s32 func_020cf878(s32, s32);
    M2C_UNK probeResult;
    u32 result;

    result = tileType;
    switch (result) {
    default:
        break;
    case 0:
        if (func_020cf878(tileX >> 4, tileY >> 4) != 0) {
            probeResult = 4;
        } else {
            probeResult = 0;
        }
        result = func_0207badc(tileX, tileY, probeResult);
        break;
    case 1:
        result = func_0207badc(tileX, tileY, 0);
        break;
    case 2:
        result = 0x10;
        break;
    case 3:
        result = func_0207badc(tileX, tileY, 4);
        break;
    case 4:
        result = func_0207badc(tileX, tileY, 8);
        break;
    case 5:
        result = func_0207badc(tileX, tileY, 0xC);
        break;
    case 6:
        result = 0x11;
        break;
    case 7:
        result = 0x12;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        result += 0xB;
        break;
    }
    return result;
}

u32 func_0207badc(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void func_02079c90(s32, s32, s32 *);
    s32 pos[3];
    s32 result = arg2;
    func_02079c90(arg0 * 0x30, arg1 * 0x30, pos);
    if (pos[0] >= 0xC0) {
        if (pos[1] >= 0x80) result += 2;
        else result += 1;
    } else if (pos[1] >= 0x80) result += 3;
    return result;
}

s32 func_0207bb3c(s32 arg0, s32 arg1, s32 *arg2) {
    void func_02079d0c(s32, s32, s32 *);
    extern void *data_027e0058;
    s32 result = 1;
    s32 maxX, maxY;
    void *map = M2C_FIELD(data_027e0058, void **, 0);
    maxX = M2C_FIELD(map, u16 *, 0x5144) * 0x300 - 1;
    maxY = M2C_FIELD(map, u16 *, 0x5146) * 0x300 - 1;
    func_02079d0c(arg0, arg1, arg2);
    if (arg2[0] < 0) { result = 0; arg2[0] = 0; }
    if (arg2[1] < 0) { result = 0; arg2[1] = 0; }
    if (arg2[0] > maxX) { arg2[0] = maxX; result = 0; }
    if (arg2[1] > maxY) { result = 0; arg2[1] = maxY; }
    return result;
}

void func_0207bbc8(s32 arg0) {
    extern s32 data_0214bfa4;
    data_0214bfa4 = arg0;
}

void func_0207bbd8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_0207bc94(s32, s32);
    void func_0207bcb0(s32);
    extern s32 data_0214bfa4;
    extern u16 **gCur3DSpriteEngine;
    s32 i;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 8) = arg0;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0xC) = arg1;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x10) = M2C_FIELD((u8 *)gCur3DSpriteEngine + arg0 * 4, s32 *, 0xC);
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x14) = arg2;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x50) = arg3;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x54) = 0;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x64) = 0;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0) = 0;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 4) = 0;
    func_0207bc94(10, 2);
    func_0207bcb0(0x20);
    for (i = 0; i < 10; i++) {
        M2C_FIELD((void *)(data_0214bfa4 + i), u8 *, 0x3C) = 0;
    }
}

void func_0207bc80(s32 arg0) {
    extern s32 data_0214bfa4;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x64) = arg0;
}

void func_0207bc94(s32 arg0, s32 arg1) {
    extern s32 data_0214bfa4;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x58) = arg0;
    M2C_FIELD((void *)data_0214bfa4, s32 *, 0x5C) = arg1;
}

void func_0207bcb0(s32 arg0) {
extern s32 data_0214bfa4;
M2C_FIELD(data_0214bfa4,s32 *,0x60)=arg0;
}

void func_0207bcc4(s32 arg0, s32 arg1) {
extern s32 data_0214bfa4;
extern u8 data_021011d4[], data_021011d5[];
void func_0207bd58(s32,s32);
M2C_FIELD(data_0214bfa4+M2C_FIELD(data_0214bfa4,s32 *,0x54),u8 *,0x3c)=arg0;
M2C_FIELD(data_0214bfa4+M2C_FIELD(data_0214bfa4,s32 *,0x54),u8 *,0x46)=arg1;
func_0207bd58(M2C_FIELD(data_0214bfa4,s32 *,0x54), ((data_021011d4[arg0*8]+7)>>3)*((data_021011d5[arg0*8]+7)>>3));
M2C_FIELD(data_0214bfa4,s32 *,0x54)++;
}

s32 func_0207bd40(s32 arg0) {
extern s32 data_0214bfa4;
return M2C_FIELD(data_0214bfa4+arg0*4,s32 *,0x14);
}

void func_0207bd58(s32 arg0,s32 arg1) {
extern s32 data_0214bfa4;
if(arg0>=9)return;
M2C_FIELD(data_0214bfa4+(arg0+1)*4,s32 *,0x14)=arg1+M2C_FIELD(data_0214bfa4+arg0*4,s32 *,0x14);
}

s32 func_0207bd88(s32 arg0) {
s32 func_0207bd40(s32); extern s32 data_0214bfa4;
s32 base=data_0214bfa4;
s32 index=func_0207bd40(arg0);
return M2C_FIELD(base,s32 *,0x10)+M2C_FIELD(base,s32 *,0x60)*index;
}

s32 func_0207bdac(s32 arg0) {
extern s32 data_0214bfa4;
return M2C_FIELD(data_0214bfa4,s32 *,0x50)+arg0;
}

void func_0207bf00(s32 arg0,s32 arg1) {
extern s32 data_0214bfa4; extern u16 **gCur3DSpriteEngine; void func_0207bfb4(void);
s32 x,y; s32 index;
M2C_FIELD(data_0214bfa4,s32 *,0)=arg0>>3;
M2C_FIELD(data_0214bfa4,s32 *,4)=arg1>>3;
func_0207bfb4();
x=arg0&7; y=arg1&7;
index=M2C_FIELD(data_0214bfa4,s32 *,12)&255;
M2C_FIELD((u32)*gCur3DSpriteEngine+index*2,s16 *,0x38)=7-x;
M2C_FIELD((u32)*gCur3DSpriteEngine+index*2,s16 *,0x40)=-3-y;
index=M2C_FIELD(data_0214bfa4,s32 *,8)&255;
M2C_FIELD((u32)*gCur3DSpriteEngine+index*2,s16 *,0x38)=-x;
M2C_FIELD((u32)*gCur3DSpriteEngine+index*2,s16 *,0x40)=-y;
}

s32 func_0207c18c(void) {
    s32 func_0207c1b4();
    return (s32) (func_0207c1b4() + 7) >> 3;
}

s32 func_0207c1a0(void) {
    s32 func_0207c1d8();
    return (s32) (func_0207c1d8() + 7) >> 3;
}

s32 func_0207c1b4(s32 arg0) {
    extern s32 data_0214bfa4;
    extern u8 data_021011d4[];
    return data_021011d4[M2C_FIELD((void *)(data_0214bfa4 + arg0), u8 *, 0x3C) * 8];
}

s32 func_0207c1d8(s32 arg0) {
    extern s32 data_0214bfa4;
    extern u8 data_021011d5[];
    return data_021011d5[M2C_FIELD((void *)(data_0214bfa4 + arg0), u8 *, 0x3C) * 8];
}

void func_0207c1fc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004cf0();
    M2C_UNK func_02004d3c();
    M2C_UNK func_02004ddc();
    M2C_UNK func_02007ef4(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0207c780(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02101468;
    extern M2C_UNK data_02101488;
    func_02004b54();
    func_0207c780(&data_02101488, arg0);
    func_02004cf0();
    func_02004d3c();
    func_02007ef4(&data_02101468, arg1, 0x20);
    func_02004ddc();
}

void func_0207c240(void) {
s32 func_0200ef4c(void *); s32 func_0200eff8(void *); extern s32 data_0214bfa8;
s32 date[4]; s32 time[3];
if(func_0200ef4c(date)==0 && func_0200eff8(time)==0) {
data_0214bfa8=((((date[0]*12+date[1])*30+date[2])*24+time[0])*60+time[1])*60+time[2];
return;
}
data_0214bfa8=0x12345678;
}

void func_0207c2d0(s32 arg0) {
    extern s32 data_0214bfa8;
    data_0214bfa8 = arg0;
}

s32 func_0207c2e0(void) {
    extern s32 data_0214bfa8;
    return data_0214bfa8;
}
