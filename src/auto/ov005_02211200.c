/* 19 functions from 0x02211200 to 0x022121F8 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct { u32 x:9; u32 y:9; u32 layer:8; u32 rest:6; } Menu005Flags;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
M2C_UNK func_ov005_02211200(M2C_UNK arg0) {
    M2C_UNK savedEngine;
    u32 tile;
    s32 i;
    s16 pos;
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern void **gCurrentMap;
    extern u8 data_ov005_02220198[];
    extern u8 data_ov005_022201a0[];
    extern u8 data_ov005_022201b0[];
    extern u8 data_ov005_022201c0[];
    extern u8 data_ov005_022201d0[];
    void func_020885fc(void);
    void func_02082cb4(void);
    void func_0208232c(void);
    void func_02082770(void);
    void *func_020896f0(void *);
    void func_02089424(void);
    void *func_020ab1c4(void *);
    void func_020aab24(void *, s32, s32, s32, s32);
    void func_02088e84(void *, s16, s16, s16, s32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void func_020ab150(void *, s32);
    void func_02088f1c(void *);
    void func_020aad18(void *);
    void func_02087d84(void *, s32, s32, s32, s32, s32);
    void func_020af04c(s32, s32, s32, s32);
    void func_0200bc5c(void *);
    s32 func_020e3218(void *);
    void func_020814e4(void);
    void func_02081590(s32,s32);
    void func_020815fc(s32,s32,s32);
    void func_02081528(void);
    void func_020cf0a8(u16);
    void func_ov003_021ff3d4(void *);
    void func_02089438(void *);
    void func_02086608(s32);

    func_020885fc();
    func_02082cb4();
    savedEngine = gCur3DSpriteEngine;
    i=0;do {
        gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
        func_0208232c();
        { u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 16; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 32; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 64; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 128; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 256; }
        func_02082770(); i++;
    }while(i<2);
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD((void *)arg0, void **, 0x4C) = func_020896f0((void *)arg0);
    func_02089424();
    {
        void *p = M2C_FIELD((void *)arg0, void **, 0x4C);
        M2C_FIELD(p,Menu005Flags*,0x40).x=32;
        M2C_FIELD(p,Menu005Flags*,0x40).y=32;
    }
    tile=0x140;
    { void *sprite; sprite = func_020ab1c4((void *)arg0);
    func_020aab24(sprite, 0, tile, 3, 1);
    func_02088e84(sprite, 0xC0, 0xA0, 0xE0, 0xC0);
    if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12)!=0)) {
        s16 a = M2C_FIELD(sprite, s16 *, 0x52);
        s16 b = M2C_FIELD(sprite, s16 *, 0x50);
        s32 w=func_020aae10(sprite);
        func_02087d84(M2C_FIELD(sprite, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(sprite));
    }
    func_020ab150(sprite, 1);
    func_02088f1c(sprite);
    func_020aad18(sprite);

    }
    { void *sprite2; sprite2 = func_020ab1c4((void *)arg0);
    func_020aab24(sprite2, 3, 0x150, 3, 1);
    func_02088e84(sprite2, 0xE0, 0xA0, 0xC0, 0xC0);
    if ((u8)(M2C_FIELD(M2C_FIELD(sprite2, void **, 0x64), u8 *, 0x12)!=0)) {
        s16 a = M2C_FIELD(sprite2, s16 *, 0x52);
        s16 b = M2C_FIELD(sprite2, s16 *, 0x50);
        s32 w=func_020aae10(sprite2);
        func_02087d84(M2C_FIELD(sprite2, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(sprite2));
    }
    func_020ab150(sprite2, 2);
    func_02088f1c(sprite2);
    func_020aad18(sprite2);

    }
    {
        s32 neg = -1;
        
        s32 r9 = 0;
        s32 r8 = 0x20;
        tile+=0x20;
        do {
            void *spSprite;
            M2C_FIELD((u8 *)(void *)arg0 + r9 * 4, void **, 0x38) = func_020ab1c4((void *)arg0);
            func_020aab24(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38), (r9 + 0x3F) & 0xFF, tile, 3, 0);
            spSprite=M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38);
            pos = (s16)r8;
            func_02088e84(spSprite, pos, 0x58, pos, 0x58);
            if ((u8)(M2C_FIELD(M2C_FIELD(spSprite, void **, 0x64), u8 *, 0x12)!=0)) {
                s16 a = M2C_FIELD(spSprite, s16 *, 0x52);
                s16 b = M2C_FIELD(spSprite, s16 *, 0x50);
                s32 w=func_020aae10(spSprite); s32 h=func_020aae44(spSprite);
        func_02087d84(M2C_FIELD(spSprite, void **, 0x64),1,b,a,(u16)w,(u16)h);
                }
            M2C_FIELD(spSprite, s16 *, 0x34) = pos;
            M2C_FIELD(spSprite, s16 *, 0x36) = 0x58;
            if ((u8)(M2C_FIELD(M2C_FIELD(spSprite, void **, 0x64), u8 *, 0x12)!=0)) {
                s16 a = M2C_FIELD(spSprite, s16 *, 0x52);
                s16 b = M2C_FIELD(spSprite, s16 *, 0x50);
                s32 w=func_020aae10(spSprite); s32 h=func_020aae44(spSprite);
        func_02087d84(M2C_FIELD(spSprite, void **, 0x64),1,b,a,(u16)w,(u16)h);
            }
            M2C_FIELD(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38),u8*,0x5a)=neg;
            func_020aad18(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38));
            tile += 0x10;
            r8 += 0x28; r9++;
        }while(r9<5);
    }

    func_0200bc5c(data_ov005_02220198);
    func_020e3218(data_ov005_022201a0);
    func_020814e4();
    func_02081590(func_020e3218(data_ov005_022201b0),M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    func_02081590(func_020e3218(data_ov005_022201c0),M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
    func_020815fc(func_020e3218(data_ov005_022201d0),0,0x20);
    func_02081528();
    {
        void *cur = (void *)gCur3DSpriteEngine;
        u8 val = M2C_FIELD(cur, u8 *, 0x46);
        val |= 0x04;
        M2C_FIELD(cur, u8 *, 0x46) = val;
        func_020af04c(3, 0x0F, 0x06, val);
    }
    gCur3DSpriteEngine = data_027e00c4;
    {
        void *map = *gCurrentMap;
        func_020cf0a8(M2C_FIELD(map, u16 *, 0x5142));
    }
    func_ov003_021ff3d4((void *)arg0);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD((void *)arg0, s32 *, 0x34) = 2;
    {
        void *p = M2C_FIELD((void *)arg0, void **, 0x4C);
        M2C_FIELD(p, s16 *, 0x34) = (s16)M2C_FIELD((void*)arg0,s32*,0x34)*(s16)0x28+0x20;
        M2C_FIELD(p, s16 *, 0x36) = 0x58;
    }
    func_02089438(M2C_FIELD((void *)arg0, void **, 0x4C));
    func_02086608(4);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov005_0221174c(void) {
s32 func_02086658(s32); s32 func_020af1e4(); s32 func_ov003_021ff7ac(); s32 func_02088624();
func_02086658(4); func_020af1e4(); func_ov003_021ff7ac(); func_02088624();
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov005_02211768(void *arg0) {
    void func_020aacf0(void *);
    void func_0208fe30(s32);
    void func_01ffa8c4(void *, s32);
    extern u16 *data_02101e84;
    s32 any;
    s32 back;
    s32 old;
    s32 i;
    s32 j;
    s32 cur;
    void *p;
    void *f;
    u8 ok;
    u8 isCur;
    u16 keys;

    old = M2C_FIELD(arg0, s32 *, 0x34);
    any = 0;
    back = 0;
    if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x20) {
        if (old > 0) {
            M2C_FIELD(arg0, s32 *, 0x34) = old - 1;
        } else if (M2C_FIELD(data_02101e84, u16 *, 0) & 0x20) {
            M2C_FIELD(arg0, s32 *, 0x34) = 4;
        }
    }
    if (M2C_FIELD(data_02101e84, u16 *, 2) & 0x10) {
        cur = M2C_FIELD(arg0, s32 *, 0x34);
        if (cur < 4) {
            M2C_FIELD(arg0, s32 *, 0x34) = cur + 1;
        } else if (M2C_FIELD(data_02101e84, u16 *, 0) & 0x10) {
            M2C_FIELD(arg0, s32 *, 0x34) = 0;
        }
    }
    keys = M2C_FIELD(data_02101e84, u16 *, 0);
    if (keys & 1) {
        any = 1;
    }
    if (keys & 2) {
        back = 1;
    }
    for (i = 0; i < 5; i++) {
        func_020aacf0(M2C_FIELD((u8 *) arg0 + i * 4, void **, 0x38));
        p = M2C_FIELD((u8 *) arg0 + i * 4, void **, 0x38);
        isCur = (M2C_FIELD(M2C_FIELD(p, void **, 0x64), s8 *, 0xC) == 1);
        if (isCur) {
            M2C_FIELD(arg0, s32 *, 0x34) = i;
        }
        ok = 1;
        p = M2C_FIELD((u8 *) arg0 + i * 4, void **, 0x38);
        f = M2C_FIELD(p, void **, 0x64);
        if (M2C_FIELD(f, s8 *, 0xB) != 1
            && !((((u32) (M2C_FIELD(p, u8 *, 0x59) << 0x1B) >> 0x1F) != 0) && M2C_FIELD(f, s8 *, 0xC) == 1)) {
            ok = 0;
        }
        if (ok & 0xFF) {
            any = 1;
        }
    }
    for (j = 0; j < 5; j++) {
        if (M2C_FIELD(arg0, s32 *, 0x34) == j) {
            p = M2C_FIELD((u8 *) arg0 + j * 4, void **, 0x38);
            M2C_FIELD(p, s32 *, 0x40) = (s32) ((M2C_FIELD(p, s32 *, 0x40) & ~0x03FC0000)
                | ((u32) ((u16) (((u32) (*(volatile u8 *) ((u8 *) p + 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        } else {
            p = M2C_FIELD((u8 *) arg0 + j * 4, void **, 0x38);
            M2C_FIELD(p, s32 *, 0x40) = (s32) ((M2C_FIELD(p, s32 *, 0x40) & ~0x03FC0000)
                | ((u32) ((u16) ((u32) (*(volatile u8 *) ((u8 *) p + 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x34) != old) {
        func_0208fe30(0x10019);
        p = M2C_FIELD(arg0, void **, 0x4C);
        M2C_FIELD(p, u16 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x34) * 0x28 + 0x20;
        M2C_FIELD(p, u16 *, 0x36) = 0x58;
    }
    if (any) {
        func_0208fe30(0x1000D);
        func_01ffa8c4(arg0, 1);
    } else if (back) {
        func_0208fe30(0x1000F);
        func_01ffa8c4(arg0, 2);
    }
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov005_02211988(void *arg0) {
s32 func_020c818c(s32,s32);
extern void **gCurrentMap;
return func_020c818c(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(arg0,s32 *,0x34)+1);
}

void func_ov005_022119b4(void) {
    M2C_UNK func_ov005_02211200();
    func_ov005_02211200();
}

void func_ov005_022119c0(void) {
    M2C_UNK func_ov005_0221174c();
    func_ov005_0221174c();
}

void func_ov005_022119cc(void *arg0) {
    func_ov005_02211768(arg0);
}

void func_ov005_022119d8(void) {
    M2C_UNK func_ov005_02211988();
    func_ov005_02211988();
}

void func_ov005_022119e4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_020c80ec(u16);
    extern u8 data_02168f0c;
    extern void **gCurrentMap;
    extern M2C_UNK data_ov005_022200a0;
    if (data_02168f0c != 0) {
        return;
    }
    if (func_020c80ec(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) == 0) {
        return;
    }
    func_01ffa42c(&data_ov005_022200a0, arg0);
}

s32 func_ov005_02211a38(s32 arg0) {
    extern s32 data_ov005_02221300;
    return (0xA * arg0) + (data_ov005_02221300 + 0x10);
}

u8 func_ov005_02211a54(s32 arg0,s32 arg1) {
s32 func_ov000_0216a3a8(s32,s32);
extern s32 data_ov005_02221300;
u8 result;
if(M2C_FIELD(data_ov005_02221300,u8 *,0)!=0)return 0;
if(func_ov000_0216a3a8(arg0,arg1)==0)result=1;else result=0;
return result;
}

void func_ov005_02211a8c(void) {
extern s32 data_ov005_02221300, data_027e00c4;
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov005_02220270;
s32 func_ov000_0216a38c(s32,s32); s32 func_ov000_0216a414(s32,s32);
void func_0208b758(s32,s32); void func_0208b698(s32,void *);
s32 q, index, old;
s32 p=data_ov005_02221300;
s32 table = func_ov005_02211a38(M2C_FIELD(p,s8 *,1));
s32 a = M2C_FIELD(table,s16 *,2);
s8 b = M2C_FIELD(p,s8 *,2);
q = func_ov000_0216a38c(M2C_FIELD(p,s8 *,1), a+b);
index = func_ov000_0216a414(M2C_FIELD(data_ov005_02221300,s8 *,1), a+b);
old = gCur3DSpriteEngine;
gCur3DSpriteEngine = data_027e00c4;
if (func_ov005_02211a54(M2C_FIELD(data_ov005_02221300,s8 *,1),a+b)==0)
func_0208b758(M2C_FIELD(data_ov005_02221300,s32 *,0x48),M2C_FIELD(q+index*4,s32 *,0x1c));
else func_0208b698(M2C_FIELD(data_ov005_02221300,s32 *,0x48),&data_ov005_02220270);
gCur3DSpriteEngine = old;
}

void func_ov005_02211b4c(void) {
    s32 func_0207c8ec(s32, s32);
    extern M2C_UNK data_0215d9b8;
    extern s32 data_ov005_02221300;
    s32 timeVal;

    timeVal = M2C_FIELD(&data_0215d9b8, s32 *, 0x74);
    M2C_FIELD(data_ov005_02221300, s32 *, 4) = func_0207c8ec(timeVal, 0x34BC0);
    if (M2C_FIELD(data_ov005_02221300, s32 *, 4) > 0x3E7) {
        M2C_FIELD(data_ov005_02221300, s32 *, 4) = 0x3E7;
        M2C_FIELD(data_ov005_02221300, s32 *, 8) = 0x3B;
        M2C_FIELD(data_ov005_02221300, s32 *, 12) = 0x3B;
        return;
    }
    M2C_FIELD(data_ov005_02221300, s32 *, 8) = func_0207c8ec(timeVal, 0xE10) % 60;
    M2C_FIELD(data_ov005_02221300, s32 *, 12) = func_0207c8ec(timeVal, 0x3C) % 60;
}

void func_ov005_02211c24(s32 arg0) {
s32 p=func_ov005_02211a38(arg0);
s32 q=func_ov000_0216a38c(arg0,0);
M2C_FIELD(p,s16 *,8)=0; M2C_FIELD(p,s16 *,6)=0;
while(M2C_FIELD(q,s32 *,0)) {
if(!func_ov005_02211a54(arg0,M2C_FIELD(p,s16 *,8))) M2C_FIELD(p,s16 *,6)++;
M2C_FIELD(p,s16 *,8)++;
q+=0x30;
}
}

void func_ov005_02211c94(void) {
extern s32 data_ov005_02221300;
M2C_FIELD(data_ov005_02221300,s32 *,0x34)=func_ov000_0216a77c(func_ov000_0216a76c());
M2C_FIELD(data_ov005_02221300,s32 *,0x38)=func_ov000_0216a7d4(func_ov000_0216a7c4());
M2C_FIELD(data_ov005_02221300,u8 *,0x32)=func_ov000_0216a564(func_ov000_0216a470());
M2C_FIELD(data_ov005_02221300,s32 *,0x3c)=func_ov000_0216a59c(func_ov000_0216a564(func_ov000_0216a470()));
}

void func_ov005_02211cf4(void) {
    s32 func_ov000_0216a38c();
    s32 func_ov000_0216a414();
    s32 func_ov005_02211a38();

    extern s32 data_ov005_02221300;

    u8 *gp = (u8 *)data_ov005_02221300;
    void *u;
    u32 t;
    u32 idx0;
    u32 idx2;
    u32 r4, r5, r6, r7;
    s32 score;
    s16 cnt;

    /* type 0 (0x00) -> byte 0x40 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    idx0 = 0;
    if (t != 0) {
        r4 = 0;
        idx0 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, idx0);
            if (M2C_FIELD(u, u16 *, 0x4) == 0) break;
            r4 = idx0;
            idx0++;
        }
    }
    score = func_ov000_0216a414(0, idx0);
    gp[0x40] = (score == 3) ? 1 : 0;

    /* type 2 (0x02) -> byte 0x41 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    idx2 = 0;
    if (t != 2) {
        r4 = 0;
        idx2 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, idx2);
            if (M2C_FIELD(u, u16 *, 0x4) == 2) break;
            r4 = idx2;
            idx2++;
        }
    }
    score = func_ov000_0216a414(0, idx2);
    gp[0x41] = (score == 3) ? 1 : 0;

    /* kind 1 counts -> byte 0x42 */
    u = (void *)func_ov005_02211a38(1);
    cnt = M2C_FIELD(u, s16 *, 0x8);
    score = 0;
    if (cnt > 0) {
        r6 = 0;
        r7 = 0;
        while (1) {
            score += func_ov000_0216a414(1, r7);
            r7++;
            u = (void *)func_ov005_02211a38(1);
            cnt = M2C_FIELD(u, s16 *, 0x8);
            if (r7 >= cnt) break;
        }
    }
    gp[0x42] = (score >= 0x32) ? 1 : 0;

    /* kind 2 counts -> byte 0x43 */
    u = (void *)func_ov005_02211a38(2);
    cnt = M2C_FIELD(u, s16 *, 0x8);
    score = 0;
    if (cnt > 0) {
        r6 = 0;
        r7 = 0;
        while (1) {
            score += func_ov000_0216a414(2, r6);
            r6++;
            u = (void *)func_ov005_02211a38(2);
            cnt = M2C_FIELD(u, s16 *, 0x8);
            if (r6 >= cnt) break;
        }
    }
    gp[0x43] = (score >= 0x32) ? 1 : 0;

    /* type 0x20 & 0x21 -> byte 0x44 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r5 = 0;
    if (t != 0x20) {
        r4 = 0;
        r5 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, r5);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x20) break;
            r4 = r5;
            r5++;
        }
    }
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r6 = 0;
    if (t != 0x21) {
        r4 = 0;
        r6 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, r6);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x21) break;
            r4 = r6;
            r6++;
        }
    }
    score = func_ov000_0216a414(0, r5) + func_ov000_0216a414(0, r6);
    gp[0x44] = (score >= 4) ? 1 : 0;

    /* type 0x19 -> byte 0x45 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r5 = 0;
    if (t != 0x19) {
        r4 = 0;
        r5 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, r5);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x19) break;
            r4 = r5;
            r5++;
        }
    }
    score = func_ov000_0216a414(0, r5);
    gp[0x45] = (score == 3) ? 1 : 0;

    /* type 0x1a -> byte 0x46 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r5 = 0;
    if (t != 0x1a) {
        r4 = 0;
        r5 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r4, r5);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x1a) break;
            r4 = r5;
            r5++;
        }
    }
    score = func_ov000_0216a414(0, r5);
    gp[0x46] = (score == 3) ? 1 : 0;

    /* 0x1d, 0x1e, 0x1f -> byte 0x47 */
    /* index for 0x1d -> r4 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r4 = 0;
    if (t != 0x1d) {
        r5 = 0;
        r4 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r5, r4);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x1d) break;
            r5 = r4;
            r4++;
        }
    }
    /* index for 0x1e -> r5 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r5 = 0;
    if (t != 0x1e) {
        r7 = 0;
        r5 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r7, r5);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x1e) break;
            r7 = r5;
            r5++;
        }
    }
    /* index for 0x1f -> r7 */
    u = (void *)func_ov000_0216a38c(0, 0);
    t = M2C_FIELD(u, u16 *, 0x4);
    r7 = 0;
    if (t != 0x1f) {
        r6 = 0;
        r7 = 1;
        while (1) {
            u = (void *)func_ov000_0216a38c(r6, r7);
            if (M2C_FIELD(u, u16 *, 0x4) == 0x1f) break;
            r6 = r7;
            r7++;
        }
    }
    score = func_ov000_0216a414(0, r7) + func_ov000_0216a414(0, r4) + func_ov000_0216a414(0, r5);
    gp[0x47] = (score >= 5) ? 1 : 0;

    return;
}

s32 func_ov005_02212118(void) {
extern s32 data_ov005_02221300;
void func_0208fe30(s32);
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s32 n=M2C_FIELD(p,s16 *,2);
if(!n)return 0;
M2C_FIELD(p,s16 *,2)=n-1;
func_0208fe30(0x10019);func_ov005_02211a8c();return 1;
}

s16 func_ov005_02212160(void) {
extern s32 data_ov005_02221300;
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s16 old=M2C_FIELD(p,s16 *,2);
M2C_FIELD(p,s16 *,2)=old-7;
if(M2C_FIELD(p,s16 *,2)<0)M2C_FIELD(p,s16 *,2)=0;
return M2C_FIELD(p,s16 *,2)-old;
}

s32 func_ov005_022121a8(void) {
extern s32 data_ov005_02221300;
void func_0208fe30(s32);
s32 p=func_ov005_02211a38(M2C_FIELD(data_ov005_02221300,s8 *,1));
s16 n=M2C_FIELD(p,s16 *,2);
s32 next=n+7;
if(next>=M2C_FIELD(p,s16 *,8))return 0;
M2C_FIELD(p,s16 *,2)++;
func_0208fe30(0x10019);
func_ov005_02211a8c();
return 1;
}

