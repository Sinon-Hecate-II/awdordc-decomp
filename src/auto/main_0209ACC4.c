/* 22 functions from 0x0209ACC4 to 0x0209BC58 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 digits[10]; } DigitTable;
extern const DigitTable data_020f399c;

void func_0209b084(void *entity) {
    s32 func_02095fe8(void);
    void func_02095ff8(s8);
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    void func_01ff9ce8(u8);
    void func_02095fc0(void);
    void func_02097768(void);
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern M2C_UNK data_02102eac, data_02102e74;

    s32 saved;
    s32 i;

    if (func_02095fe8() == 3) {
        func_02095ff8(0);
        if (func_02095fe8() == 2) {
            func_02095ff8(0);
        }
    }
    func_01ffa9e4(&data_02102eac);
    func_01ffa9e4(&data_02102e74);

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x4)) {
        saved = gCur3DSpriteEngine;
        for (i = 0; i < 2; i++) {
            gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
            {
                u8 mode = M2C_FIELD(entity, u8 *, 0x5a);
                if (mode == 0 && gCur3DSpriteEngine != data_027e00c8) continue;
                if (mode == 1 && gCur3DSpriteEngine != data_027e00c4) continue;
                if (mode == 3 && gCur3DSpriteEngine != saved) continue;
            }
            func_01ff9ce8(M2C_FIELD(entity, u8 *, 0x57));
            {
                u8 *p = (u8 *)gCur3DSpriteEngine;
                s8 idx = M2C_FIELD(entity, s8 *, 0x57);
                p[0x46] = (u8)(p[0x46] | (1 << idx));
            }
        }
        gCur3DSpriteEngine = saved;
    }

    if (!(M2C_FIELD(entity, u8 *, 0x5c) & 0x8)) goto skip8;
    func_02095fc0();
    func_02097768();
skip8:;
}

void func_0209b190(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_02097be0();
    if (func_02097be0() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_0209b1b0(void *arg0) {
    extern s32 gCur3DSpriteEngine;
    void *src = M2C_FIELD(gCur3DSpriteEngine, void **, 0x54);

    M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(src, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x38) = M2C_FIELD(src, s32 *, 0x38);
    M2C_FIELD(arg0, s8 *, 0x57) = M2C_FIELD(src, s8 *, 0x57);
    M2C_FIELD(arg0, s32 *, 0x3C) = M2C_FIELD(src, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x40) = M2C_FIELD(src, s32 *, 0x40);
    M2C_FIELD(arg0, u16 *, 0x44) = M2C_FIELD(src, u16 *, 0x44);
    M2C_FIELD(arg0, u16 *, 0x46) = M2C_FIELD(src, u16 *, 0x46);
    M2C_FIELD(arg0, u16 *, 0x4E) = M2C_FIELD(src, u16 *, 0x4C);
    M2C_FIELD(arg0, u16 *, 0x4C) = M2C_FIELD(src, u16 *, 0x4C);
    M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(src, s32 *, 0x60);
    M2C_FIELD(arg0, u8 *, 0x48) = M2C_FIELD(src, u8 *, 0x48);
    M2C_FIELD(arg0, u8 *, 0x49) = M2C_FIELD(src, u8 *, 0x49);
    M2C_FIELD(arg0, u8 *, 0x4A) = M2C_FIELD(src, u8 *, 0x4A);
    M2C_FIELD(arg0, u8 *, 0x4B) = M2C_FIELD(src, u8 *, 0x4B);
    M2C_FIELD(arg0, s8 *, 0x54) = M2C_FIELD(src, s8 *, 0x54);
    M2C_FIELD(arg0, s8 *, 0x55) = M2C_FIELD(src, s8 *, 0x55);
    M2C_FIELD(arg0, s32 *, 0x50) = M2C_FIELD(src, s32 *, 0x50);
    M2C_FIELD(arg0, u8 *, 0x56) = M2C_FIELD(src, u8 *, 0x56);
    M2C_FIELD(arg0, u8 *, 0x58) = M2C_FIELD(src, u8 *, 0x58);
    M2C_FIELD(arg0, u8 *, 0x59) = M2C_FIELD(src, u8 *, 0x59);
    M2C_FIELD(arg0, u8 *, 0x5C) = M2C_FIELD(src, u8 *, 0x5C);
}

void func_0209b26c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209b2b4(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    func_0209b2b4(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5);
}

void func_0209b2b4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);

    func_0209b32c(arg0, arg1, arg2, arg3, arg4, 0, arg5);
}

void func_0209b2dc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    void func_0209b32c(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16, u16);
    func_0209b32c(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5, arg6);
}

void func_0209b32c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5, u16 arg6) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *temp_r6;

    temp_r6 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209b370(arg0, arg1, arg2, M2C_FIELD(temp_r6, s32 *, 0xC), M2C_FIELD(temp_r6, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5, (s32) arg6);
}

M2C_UNK func_0209b370(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 e,s32 f,u16 g,u16 h,u16 i) {
 M2C_UNK func_0209be10(s32,M2C_UNK,M2C_UNK,M2C_UNK,s32,s32,s32,s32,s32,s32);
 M2C_UNK func_02099e58(s32); void *func_01ffa3dc(M2C_UNK *,s32);
 extern s32 gCur3DSpriteEngine; extern M2C_UNK data_021032d8;
 void *p=(void *)gCur3DSpriteEngine;
 p=M2C_FIELD(p,void **,0x54);
 func_0209be10((s32)p,a,b,c,d,e,f,(s32)g,(s32)h,(s32)i);
 func_02099e58((s32)p); func_01ffa3dc(&data_021032d8,7);
}

void func_0209b3e8(s16 a,s32 b,s32 c,s32 d,u16 e,u16 f) {
 s32 func_0207c8ec(s32,s32);
 DigitTable table=data_020f399c;
 do {func_0209b2b4(a,b,c,table.digits[d%10],e,f);
 d=func_0207c8ec(d,10); if(!d) return;
 f+=2; a--;
 } while(1);
}

void func_0209b4a8(M2C_UNK arg0, M2C_UNK arg1, u16 arg2) {
    s32 func_020e34bc();
    M2C_UNK func_020e35cc(s32);
    void func_02007ef4(M2C_UNK, M2C_UNK, u32);
    s32 i;
    s32 count;
    M2C_UNK buf;
    u8 *src;
    u8 *dst;
    src = (u8 *)arg0;
    dst = (u8 *)arg1;
    buf = func_020e34bc(0x100);
    count = (arg2 + 7) >> 3;
    count = (count + 3) >> 2;
    for (i = 0; i < count; i++) {
        func_02007ef4(src, buf, 0x100);
        func_02007ef4(buf, dst, 0x20);
        func_02007ef4((u8 *)buf + 0x40, (u8 *)dst + 0x20, 0x20);
        func_02007ef4((u8 *)buf + 0x80, (u8 *)dst + 0x40, 0x20);
        func_02007ef4((u8 *)buf + 0xc0, (u8 *)dst + 0x60, 0x20);
        func_02007ef4((u8 *)buf + 0x20, (u8 *)dst + 0x80, 0x20);
        func_02007ef4((u8 *)buf + 0x60, (u8 *)dst + 0xa0, 0x20);
        func_02007ef4((u8 *)buf + 0xa0, (u8 *)dst + 0xc0, 0x20);
        func_02007ef4((u8 *)buf + 0xe0, (u8 *)dst + 0xe0, 0x20);
        src += 0x100;
        dst += 0x100;
    }
    func_020e35cc((s32)buf);
}

void func_0209b59c(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK, s32);
    func_02007e98(0, arg0, ((s32) (((s32) (arg1 + 7) >> 3) + 3) >> 2) << 8);
}

void func_0209b5c4(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_02086680(M2C_UNK);
    M2C_UNK func_0209b5e4(M2C_UNK, s32);
    func_0209b5e4(arg0, func_02086680(arg1));
}

s32 func_0209b5e4(M2C_UNK a,s32 b) {
 s32 func_0209c454(s32,M2C_UNK); s32 func_020e34bc(); void func_0209b4a8(s32,s32,u16); M2C_UNK func_020e35cc(s32);
 s32 n,p;
 n=func_0209c454(b,0);
 if((((((n+7)>>3)+3)>>2)<<8)>0) {
 p=func_020e34bc(); func_0209b59c(p,n); func_0209b370(0,0,4,p,0,b,0,0,0);
 func_0209b4a8(p,a,(u16)n); func_020e35cc(p);
 }
 return n;
}

void func_0209b8c0(void *arg0) {
    void func_0209b4a8(s32, s32, u16);
    M2C_UNK func_020e35cc(s32);
    func_0209b4a8(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), (u16) M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_0209b8ec(s32 arg0, s32 arg1, s32 arg2) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021032b8;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_021032b8, 1);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
}

s32 func_0209b91c(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_0209b370(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16, u16);
    s32 func_0209c454(s32, M2C_UNK);
    s32 func_020e34bc();
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = func_0209c454(arg1, 0);
    if ((s32) (((s32) (((s32) (temp_r0 + 7) >> 3) + 3) >> 2) << 8) > 0) {
        temp_r0_2 = func_020e34bc();
        func_0209b59c(temp_r0_2, temp_r0);
        func_0209b370(0, 0, 4, temp_r0_2, 0, arg1, 0, 0, 0);
        func_0209b8ec(temp_r0_2, arg0, temp_r0);
    }
    return temp_r0;
}

void func_0209bbd0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    void func_0209bc18(M2C_UNK, M2C_UNK, s32, s32, u16, u16);
    M2C_UNK func_02086680(M2C_UNK);

    func_0209bc18(arg0, arg1, arg2, func_02086680(arg3), arg4, arg5);
}

void func_0209bc18(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    M2C_UNK func_0209bc58(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *temp_r5;

    temp_r5 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209bc58(arg0, arg1, arg2, M2C_FIELD(temp_r5, s32 *, 0xC), M2C_FIELD(temp_r5, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5);
}

