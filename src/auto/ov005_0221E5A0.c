/* 9 functions from 0x0221E5A0 to 0x0221F4F8 (ov005), found by ds-decomp. */
#include "common.h"
extern u8 data_ov005_02220b70[];
extern u8 data_ov005_02220f54[];
extern u8 data_ov005_02220a34[];
extern u8 data_ov005_02220f3c[];
extern u8 data_ov005_02220eac[];
extern u8 data_ov005_02220ecc[];
extern u8 data_ov005_02220f0c[];
extern u8 data_ov005_02220e8c[];
extern u8 data_ov005_02220e3c[];
extern u8 data_ov005_02220e6c[];
extern u8 data_ov005_02220e4c[];
extern u8 data_ov005_02220edc[];
extern u8 data_ov005_02220a1c[];
extern u8 data_ov005_02220f1c[];
extern u8 data_ov005_02220e5c[];
extern u8 data_ov005_02220eec[];

void func_ov005_0221e5a0(M2C_UNK arg0) {
    (void)arg0;
    return;
}

void func_ov005_0221e88c(void *arg0) {
void *func_01ffa42c(M2C_UNK *, M2C_UNK);
void *func_02082028(s32);
void *func_020e34bc(s32);
s32 func_020e3218(M2C_UNK *);
s32 func_020cfb94(void);
s32 func_020cfb78(void);
s32 func_020cd6d4(void);
s32 func_020e31e0(void);
s32 func_020a7290(void);
s32 func_020a7278(void);
s32 func_020a72e8(s32);
s32 func_020a8a84(s32);
s32 func_0207cb88(s32);
s32 func_ov000_0216ce10(s32);
s32 func_ov000_0216ce84(s32);
s32 func_ov000_0216cdcc(s32);
s32 func_ov000_0216cdec(s32,s32);
extern void **gCur3DSpriteEngine, **data_027e00c8, **data_027e00c4, **gCurrentMap;
void *p, *q; u8 *b; void **saved, **saved2;
u8 *dst; s32 n; s32 i,j,k,v,t;
p=func_01ffa42c(data_ov005_02220b70,arg0);
if (!p) return;
M2C_FIELD(p,void **,0)=data_ov005_02220f54;
func_0200bc5c(data_ov005_02220a34);
func_020814e4(func_020e3218(data_ov005_02220f3c));
saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
func_02081590(func_020e3218(data_ov005_02220eac),M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
func_02081590(func_020e3218(data_ov005_02220ecc),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
func_02081590(func_020e3218(data_ov005_02220f0c),M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+1280);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,36)+0x500,0x100,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
func_02080cfc(data_ov005_02220e8c,M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+0x7300);
func_0208116c(data_ov005_02220e3c,0x380,0x20);
gCur3DSpriteEngine=data_027e00c4;
func_02082134(2,2); func_01ff9ce8(2);
func_02081590(func_020e3218(data_ov005_02220e6c),M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
func_02081590(func_020e3218(data_ov005_02220e4c),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
func_02081590(func_020e3218(data_ov005_02220edc),M2C_FIELD(gCur3DSpriteEngine,s32 *,36));
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,36),0x100,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved; func_02081528();
M2C_FIELD(p,s32 *,0x3c)=0; M2C_FIELD(p,s32 *,0x50)=0; M2C_FIELD(p,s32 *,0x54)=0;
q=func_02082028(0x24);
if(q) {
M2C_FIELD(q,u16 *,16)=8; M2C_FIELD(q,u8 *,18)=0;
M2C_FIELD(q,s32 *,0)=0; M2C_FIELD(q,s32 *,4)=0;
M2C_FIELD(q,s8 *,8)=-1; M2C_FIELD(q,s8 *,9)=-1;
M2C_FIELD(q,s8 *,10)=-1; M2C_FIELD(q,s8 *,11)=-1;
M2C_FIELD(q,u8 *,13)=255; M2C_FIELD(q,s8 *,12)=-1;
M2C_FIELD(q,u8 *,14)=0; M2C_FIELD(q,u8 *,15)=255;
M2C_FIELD(q,void **,20)=func_020e34bc(0x60);
func_02007f8c(M2C_FIELD(q,void **,20),0,0x60);
}
M2C_FIELD(p,void **,0x34)=q;
M2C_FIELD(p,s32 *,0x40)=192; M2C_FIELD(p,s32 *,0x48)=192;
M2C_FIELD(p,s32 *,0x44)=-32; M2C_FIELD(p,s32 *,0x4c)=-32;
saved2=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
i=0;
if(func_020cfb94()>0) { j=0x388; k=0; do {
dst=M2C_FIELD(gCur3DSpriteEngine,u8 **,28)+((volatile s32)j<<5);
func_02007ef4(func_ov000_0216ce10(M2C_FIELD((u8 *)*gCurrentMap+k,u8 *,0x6857)),dst,0x80);
func_01ff9e44(func_ov000_0216ce84(M2C_FIELD((u8 *)*gCurrentMap+k,u8 *,0x684d)),(i+24)<<5,32);
i++; j+=4; k+=0x8c;
} while(i<func_020cfb94()); }
*(void ***)&gCur3DSpriteEngine=data_027e00c8;
k=func_020a7290()<<5; saved=(void **) (M2C_FIELD(gCur3DSpriteEngine,u8 *volatile *,28)+0x3580);
func_02007ef4(func_020a7278(),(u8 *)saved+0x4000,k);
func_01ff9e44(func_020a72e8(M2C_FIELD((u8 *)*gCurrentMap+(M2C_FIELD(p,s32 *,0x50)+1)*140,u8 *,0x67c1)),0x3c0,32);
gCur3DSpriteEngine=data_027e00c4; b=data_ov005_02220a1c;
k=0; if(*b) { j=0x3ac; do {
dst=M2C_FIELD(gCur3DSpriteEngine,u8 *volatile *,28)+((volatile s32)j<<5);
func_02007ef4(func_ov000_0216cdcc(*b),dst,256);
b++; j+=8; k++; } while(*b); }
func_01ff9e44(func_ov000_0216cdec(16,M2C_FIELD((u8 *)*gCurrentMap+(M2C_FIELD(p,s32 *,0x50)+1)*140,u8 *,0x67c1)),0x3c0,32);
gCur3DSpriteEngine=data_027e00c4; func_02099450(0,0,0);
v=func_020cfb78(); t=M2C_FIELD(*gCurrentMap,u16 *,0x52a2);
if(func_020cd6d4()) {
func_0209c048(6,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),func_020a8a84(M2C_FIELD(*gCurrentMap,u16 *,0x5142)),0,0);
func_0209c024(8,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),v,0,0);
} else func_0209c024(5,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),v,0,0);
if(!func_020e31e0()) func_0209c048(23,1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),t,0,0);
else func_0209c048((s16)(func_0207cb88(t)+24),1,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),t,0,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=saved2; v=M2C_FIELD(p,s32 *,0x54);
func_020814e4(func_020e3218(data_ov005_02220f1c));
if(v==0) { func_02081590(func_020e3218(data_ov005_02220e5c),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
 } else { func_02081590(func_020e3218(data_ov005_02220eec),M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
 }
func_02081528();
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0x800,0x2000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(p,u8 *,0x58)=1;
}

s32 func_ov005_0221eef4(void *arg0) {
    s32 func_020ad3f0(void);
    s32 func_01ffa3dc(s32 *, void *);
    extern u32 data_027e15bc;
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    extern u16 *data_02101e84;
    extern s32 data_ov005_02220ad0[];
    void **saved;
    s32 i;
    volatile u16 *volatile p;
    void **chosen;
    if (!(data_027e15bc & 3)) {
        saved = gCur3DSpriteEngine;
        i = 0;
        do {
            if (i == 0) chosen = data_027e00c8;
            else chosen = data_027e00c4;
            i++;
            gCur3DSpriteEngine = chosen;
            p = (u16 *)((u8 *)*chosen + 0x3E);
            *p = *p + 1;
        } while (i < 2);
        gCur3DSpriteEngine = saved;
    }
    if (*data_02101e84 & 8) {
        if (!func_020ad3f0()) func_01ffa3dc(data_ov005_02220ad0, arg0);
    }
}

void func_ov005_0221efac(void) {
    M2C_UNK func_ov005_0221eef4();
    func_ov005_0221eef4();
}

void func_ov005_0221efb8(void) {
    M2C_UNK func_0208f780(s32);
    extern u16 data_02168f14;
    extern void **gCurrentMap;
    s32 var_r0;
    u16 temp_r1;

    var_r0 = 0x10017;
    if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF)) {
        temp_r1 = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        if ((s32) temp_r1 <= 0xB0) {
            if (((s32) temp_r1 < 0xB0) && (temp_r1 != 0xAA)) {

            } else {
                goto block_9;
            }
        } else if ((s32) temp_r1 <= 0xB5) {
            if (temp_r1 != 0xB5) {

            } else {
                goto block_9;
            }
        } else if (temp_r1 == 0xBA) {
block_9:
            var_r0 = 0x10018;
        }
    }
    func_0208f780(var_r0);
}

void func_ov005_0221f038(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220a44;
    extern M2C_UNK data_ov005_02220a6c;
    extern M2C_UNK data_ov005_02220d50;
    extern M2C_UNK data_ov005_02220fe0;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov005_02220d50, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    func_0200bc5c(&data_ov005_02220a44);
    M2C_FIELD(temp_r0, s32 *, 0x34) = func_02081070(&data_ov005_02220a6c, 1);
}

void func_ov005_0221f084(void *arg0) {
    M2C_UNK func_0207c650(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(M2C_UNK *, s32);
    s32 func_020815bc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208232c();
    M2C_UNK func_02082340(M2C_UNK, u16 *);
    M2C_UNK func_02082cb4();
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02091cd0();
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    M2C_UNK func_020ab150(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    s32 func_020e3218(M2C_UNK *);
    extern void **data_027e00c4;
    extern void **data_027e00c8;
    extern void *data_027e01d8;
    extern u16 data_ov005_02220078;
    extern M2C_UNK data_ov005_02221230;
    extern M2C_UNK data_ov005_02221238;
    extern M2C_UNK data_ov005_0222124c;
    extern M2C_UNK data_ov005_02221260;
    extern M2C_UNK data_ov005_02221274;
    extern M2C_UNK data_ov005_02221288;
    extern M2C_UNK data_ov005_0222129c;
    extern M2C_UNK data_ov005_022212b0;
    extern M2C_UNK data_ov005_022212c4;
    extern M2C_UNK data_ov005_022212d4;
    extern M2C_UNK data_ov005_022212e4;
    u16 *sp1C;
    u16 *sp18;
    u16 *sp14;
    u16 *sp10;
    u16 *spC;
    u16 sp8;
    s16 temp_r5;
    s16 temp_r6;
    s32 var_r0_2;
    s32 var_r9;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 temp_r7;
    void *temp_r11;
    void *temp_r4;
    void *var_r0;

    sp8 = data_ov005_02220078;
    func_02082cb4();
    func_02091cd0();
    func_0200bc5c(&data_ov005_02221230);
    temp_r11 = data_027e01d8;
    var_r9 = 0;
    do {
        if (var_r9 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        data_027e01d8 = var_r0;
        func_0208232c();
        func_02082340(3, &sp8);
        var_r9 += 1;
        temp_r0 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp1C = temp_r0;
        *temp_r0 = *sp1C & ~0x10;
        temp_r0_2 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp18 = temp_r0_2;
        *temp_r0_2 = *sp18 & ~0x20;
        temp_r0_3 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp14 = temp_r0_3;
        *temp_r0_3 = *sp14 & ~0x40;
        temp_r0_4 = M2C_FIELD(data_027e01d8, u16 **, 0);
        sp10 = temp_r0_4;
        *temp_r0_4 = *sp10 | 0x80;
        temp_r0_5 = M2C_FIELD(data_027e01d8, u16 **, 0);
        spC = temp_r0_5;
        *temp_r0_5 = *spC | 0x100;
    } while (var_r9 < 2);
    data_027e01d8 = data_027e00c8;
    func_020814e4(&data_ov005_02221238);
    func_02081590(&data_ov005_0222124c, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    func_02081590(&data_ov005_02221260, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x3C) = func_020815bc(&data_ov005_02221274, 0x200);
    func_0207c650(M2C_FIELD(arg0, s32 *, 0x3C), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    func_02081528();
    func_02080cfc(func_020e3218(&data_ov005_02221288), M2C_FIELD(data_027e01d8, s32 *, 0x1C) + 0x2800);
    func_0208116c(&data_ov005_0222129c, 0x2C0, 0x20);
    data_027e01d8 = data_027e00c4;
    func_020814e4(&data_ov005_022212b0);
    func_02081590(&data_ov005_022212c4, M2C_FIELD(data_027e01d8, s32 *, 0x18));
    func_02081590(&data_ov005_022212d4, M2C_FIELD(data_027e01d8, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x40) = func_020815bc(&data_ov005_022212e4, 0x200);
    func_0207c650(M2C_FIELD(arg0, s32 *, 0x40), 3, 0, 0x200, 0);
    M2C_FIELD(data_027e01d8, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e01d8, u8 *, 0x46) | 8);
    func_02081528();
    data_027e01d8 = data_027e00c8;
    M2C_FIELD(arg0, void **, 0x34) = func_020ab1c4(arg0);
    func_020aab24(M2C_FIELD(arg0, void **, 0x34), 1, 0x120, 3, 1);
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    func_02088e84(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = func_020aae10(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5, (s32) temp_r7, (s32) func_020aae44(temp_r4));
    }
    func_020ab150(M2C_FIELD(arg0, void **, 0x34), 1);
    func_020aad18(M2C_FIELD(arg0, void **, 0x34));
    func_02088da8(M2C_FIELD(arg0, void **, 0x34));
    data_027e01d8 = temp_r11;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
}

void func_ov005_0221f3e8(void *arg0) {
    M2C_UNK func_01ffa6fc();
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    s32 temp_r1;

    if (*data_02101e84 & 0xC0B) {
        func_01ffa6fc();
        return;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        func_01ffa6fc();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r1 < 0x84) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_r1 + 1);
    }
}

void func_ov005_0221f448(void *arg0) {
    s32 func_020e35cc(s32);
    extern void **data_027e00c4, **data_027e00c8, **gCur3DSpriteEngine;
    u16 *volatile p;
    void **saved;
    s32 i;
    void **chosen;
    i = 0;
    saved = gCur3DSpriteEngine;
    do {
        if (i == 0) chosen = data_027e00c8;
        else chosen = data_027e00c4;
        i++;
        gCur3DSpriteEngine = chosen;
        p = (u16 *)((u8 *)*chosen + 0x12);
        *p = *p & ~0xC0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x53) = 0;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x40));
}

