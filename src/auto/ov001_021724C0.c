/* 18 functions from 0x021724C0 to 0x0217332C (ov001), found by ds-decomp. */
#include "common.h"
void func_ov001_02172ba4(void);
typedef struct SpritePosition { s32 x, y; } SpritePosition;
static inline void GetSpritePosition(const u32 *sprite, SpritePosition *pos) {
    u32 value = *sprite;
    pos->y = (value & 0x1ff0000) >> 16;
    pos->x = value & 255;
}

void func_ov001_021724c0(void) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a5f0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a61c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a260(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a474(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218ac04(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b12c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a070(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0217355c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_021728b0(M2C_UNK);
    extern void *data_ov001_02193d1c;
    extern u8 data_ov001_0218f31c[];
    extern u8 data_ov001_0218f324[];
    extern void *data_ov001_02190104[];
    volatile u16 tmp[4];
    void *q;
    void *p;
    void *ret;
    s32 i, u, t;
    u16 sp1c = 0, sp1e = 0, sp20 = 0x11, sp22 = 0x12, sp14 = 0;
    volatile u16 sp16 = 0;
    M2C_UNK sp18val = 0;
    M2C_UNK *psp = &sp18val;
    s32 sp10 = 0;
    s32 r8 = 0, r9 = 0;
    tmp[2] = 0; tmp[3] = 0; tmp[0] = 0; tmp[1] = 0;
    tmp[2] = 0x11; tmp[3] = 0x12;
    q = func_ov001_0218b6f8(0x128, 4, 0x12, 0x11);
    data_ov001_02193d1c = q;
    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = 0xff;
    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = 0;
    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x123) = 1;
    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x124) = 1;
    i = 0;
    while (i < 0x2f) {
        p = func_ov001_0218a5f0(0, 0x34);
        ((void **)((u8 *)data_ov001_02193d1c + 0x30))[i] = p;
        p = ((void **)((u8 *)data_ov001_02193d1c + 0x30))[i];
        {
            u32 val = *(u32 *)p;
            val = (val & 0xc1fffcffU) | 0x200;
            *(u32 *)p = val;
        }
        i++;
        {
            u16 hh = *(u16 *)((u8 *)p + 4);
            hh = (hh & ~0xc00) | 0xc00;
            *(u16 *)((u8 *)p + 4) = hh;
        }
    }
    i = 0;
    while (i < 4) {
        u8 b = data_ov001_0218f324[i];
        p = func_ov001_0218a5f0(0, b);
        ((void **)((u8 *)data_ov001_02193d1c + 0xec))[i] = p;
        p = ((void **)((u8 *)data_ov001_02193d1c + 0xec))[i];
        {
            u32 val = *(u32 *)p;
            val = (val & 0xc1fffcffU) | 0x200;
            *(u32 *)p = val;
        }
        i++;
        {
            u16 hh = *(u16 *)((u8 *)p + 4);
            hh = (hh & ~0xc00) | 0xc00;
            *(u16 *)((u8 *)p + 4) = hh;
        }
    }
    for (u = 0; u < 2; u++) {
        u8 b = data_ov001_0218f31c[u];
        p = func_ov001_0218a61c(0, b, 1);
        ((void **)((u8 *)data_ov001_02193d1c + 0xfc))[u] = p;
        p = ((void **)((u8 *)data_ov001_02193d1c + 0xfc))[u];
        func_ov001_0218a260(p, (M2C_UNK)-1, 0x200, 0);
        func_ov001_0218a474(p, (M2C_UNK)-1, 3);
    }
    sp18val = 0;
    psp = &sp18val;
    for (t = 0; t < 3; t++) {
        void *obj;
        sp1c = 0;
        sp1e = 0;
        sp20 = 0x11;
        sp22 = 0x12;
        sp14 = 0;
        sp16 = t;
        (void)sp16;
        obj = (void *)func_ov001_0218ac04(0, 0x1c, 2, 0, (M2C_UNK)psp, 0);
        ((void **)((u8 *)data_ov001_02193d1c + 0))[t * 4 + 0] = obj;
        obj = ((void **)((u8 *)data_ov001_02193d1c + 0))[t * 4 + 0];
        sp10 = 0;
        r8 = 0;
        while (r8 < 0xc) {
            u16 ah = *(u16 *)((u8 *)data_ov001_02190104[t] + (sp10 * 2));
            sp14 = ah;
            sp22 = 0x12;
            {
                void *cur = ((void **)((u8 *)data_ov001_02193d1c + 0))[t * 4 + 0];
                func_ov001_0218b12c(cur, sp1c, sp1e, sp20, sp22, 2, 0x480, (M2C_UNK)&sp14);
            }
            sp1c = sp1c + 0x12;
            sp10++;
            r8++;
        }
        if (t == 0) {
            r9 = 0;
            while (r9 < 4) {
                void *o2 = (void *)func_ov001_0218a070(0, sp18val, 1);
                ((void **)((u8 *)data_ov001_02193d1c + 0x104))[r9] = o2;
                o2 = ((void **)((u8 *)data_ov001_02193d1c + 0x104))[r9];
                (void)o2;
                r9++;
            }
        }
    }
    ret = func_ov001_0218a61c(0, 0x40, 1);
    M2C_FIELD(data_ov001_02193d1c, void **, 0x114) = ret;
    func_ov001_0218a260(ret, (M2C_UNK)-1, 0x200, 0);
    func_ov001_0218a474(ret, (M2C_UNK)-1, 2);
    ret = (void *)func_ov001_0218c884(0, (M2C_UNK)func_ov001_021728b0, 0, 0x78);
    M2C_FIELD(data_ov001_02193d1c, void **, 0x118) = ret;
    func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11d), 0, 0xc0);
}

void func_ov001_02172824(void) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02173e38(void);
 func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x114));
 func_ov001_0218c924(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x118), func_ov001_02173e38);
}

u8 func_ov001_02172858(void) {
    extern void *data_ov001_02193d1c;
    return M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11C);
}

void func_ov001_0217286c(s8 arg0) {
    extern void *data_ov001_02193d1c;
    M2C_FIELD(data_ov001_02193d1c, s8 *, 0x123) = arg0;
}

void func_ov001_02172880(s8 arg0) {
 extern void *data_ov001_02193d1c;
 M2C_FIELD(data_ov001_02193d1c, s8 *, 0x124) = arg0;
}

s32 func_ov001_02172894(void) {
 extern void *data_ov001_02193d1c;
 if (data_ov001_02193d1c != 0) return 1;
 return 0;
}

#pragma opt_common_subs off
void func_ov001_021728b0(s32 arg0) {
extern void *data_ov001_02193d1c;
void func_ov001_02172944(s32);
struct {s32 x,y;} xy,*pos=&xy;
u32 value=*M2C_FIELD(data_ov001_02193d1c,u32 **,0x30);
pos->y=(value&0x1ff0000)>>16;
pos->x=(value&255)-12;
if(pos->x>0x51) {func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),0,pos->x);return;}
func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),0,0x51);
func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),1,0xc0);
func_ov001_0218c924(arg0,func_ov001_02172944);
}
#pragma optimization_level 2
void func_ov001_02172944(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_021729d8(s32);
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x60);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x67) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, 0x67);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_021729d8);
}
#pragma optimization_level 3
void func_ov001_021729d8(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172a6c();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x90);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x7D) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, 0x7D);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172a6c);
}
#pragma peephole off
void func_ov001_02172a6c(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172b00(s32);
 u32 value;
 s32 x;
 u32 y;
 s32 pos[2];
 s32 yy;
 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0xC0);
 x = (value & 0xFF) - 12;
 y = value & 0x1FF0000;
 yy = y >> 16;
 ((volatile s32 *)pos)[1] = yy;
 ((volatile s32 *)pos)[0] = x;
 if (pos[0] > 0x93) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, pos[0]);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, 0x93);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 4, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172b00);
}
#pragma peephole reset
void func_ov001_02172b00(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172b8c(void);
 s32 pos[2];
 func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193d1c,s32 *,0xfc),0,&pos[1],&pos[0]);
 pos[0]-=12;
 if(pos[0]>170) {func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),4,pos[0]);return;}
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),4,170);
 func_ov001_02173924(); func_ov001_0218c924(arg0,func_ov001_02172b8c);
}

void func_ov001_02172b8c(void) {
    void func_ov001_021730d4(void);
    M2C_UNK func_ov001_0217332c();
    func_ov001_02172ba4();
    func_ov001_02172d8c();
    func_ov001_021730d4();
    func_ov001_0217332c();
}

void func_ov001_02172ba4(void) {
    extern void *data_ov001_02193d1c;
    extern u16 data_ov001_0218fd20[];
    extern u16 data_ov001_0218f36c[];
    extern u16 data_ov001_0218f330[];
    extern u16 data_ov001_0218f34c[];
    extern u16 data_ov001_0218f35c[];
    extern u16 data_ov001_0218f344[];
    extern u16 data_ov001_0218f32c[];
    extern s32 data_ov001_02190110[];
    s32 func_ov001_0218bbd8(void *);
    void func_ov001_0218b2e0(void *, void *, void *);
    void func_ov001_02185024(s32);
    u16 buf[4];
    s32 i;
    if (!func_ov001_0218bbd8(data_ov001_0218fd20)) return;
    M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) = -1;
    {
        u16 *a = data_ov001_0218f36c;
        for (i = 0; i < 0x2f; i++) {
            func_ov001_0218b2e0(a, data_ov001_0218f330, buf);
            if (func_ov001_0218bbd8(buf)) {
                if (M2C_FIELD(data_ov001_02193d1c, u8 *, 0x124) == 0) {
                    func_ov001_02185024(9);
                    return;
                }
                func_ov001_02185024(0);
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11e) = (u8)i;
                return;
            }
            a += 2;
        }
    }
    {
        u16 *c = data_ov001_0218f35c;
        u16 *b = data_ov001_0218f34c;
        for (i = 0; i < 4; i++) {
            func_ov001_0218b2e0(b, c, buf);
            if (func_ov001_0218bbd8(buf)) {
                if ((i == 3 && M2C_FIELD(data_ov001_02193d1c, u8 *, 0x123) == 0) ||
                    (i == 2 && M2C_FIELD(data_ov001_02193d1c, u8 *, 0x124) == 0)) {
                    func_ov001_02185024(9);
                    return;
                }
                func_ov001_02185024(data_ov001_02190110[i]);
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11e) = (u8)(i + 0x2f);
                return;
            }
            c += 2;
            b += 2;
        }
    }
    {
        u16 *e;
        u16 *d;
        d = data_ov001_0218f344;
        e = data_ov001_0218f32c;
        for (i = 0; i < 2; i++) {
            func_ov001_0218b2e0(d, e, buf);
            if (func_ov001_0218bbd8(buf)) {
                func_ov001_02185024(0);
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11e) = (u8)(i + 0x33);
                return;
            }
            d += 2;
        }
    }
    return;
}

s32 func_ov001_02172d8c(void) {
    extern void *data_ov001_02193d1c;
    extern u16 data_ov001_0218fd20[];
    extern u16 data_ov001_0218f36c[];
    extern u16 data_ov001_0218f330[];
    extern void *data_ov001_021900f8[];
    extern u16 data_ov001_0218f364[];
    extern u16 data_ov001_0218f354[];
    extern u16 data_ov001_0218f5d0[];
    extern u16 data_ov001_0218f344[];
    extern u16 data_ov001_0218f32c[];
    extern u16 data_ov001_0218f320[];
    extern u16 data_ov001_0218f34c[];
    extern u16 data_ov001_0218f35c[];
    extern u16 data_ov001_0218f350[];
    extern u16 data_ov001_0218f360[];
    void func_ov001_0218b2e0(void *, void *, void *);
    s32 func_ov001_0218bcb0(void *);
    void func_ov001_021737d8(s32);
    s32 func_ov001_02173924(void);
    void func_ov001_02173074(void);
    void func_ov001_021730a4(void);

    u8 buf[8];
    s32 i;
    u8 *p;
    u8 *q;
    u8 *tableEntry;

    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = 0;
    if (func_ov001_0218bcb0(data_ov001_0218fd20) == 0) {
        return 0;
    }

    p = (u8 *)data_ov001_0218f36c;
    q = (u8 *)data_ov001_0218f330;
    for (i = 0; i < 0x2f; i++) {
        func_ov001_0218b2e0(p, q, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i) {
                return 0;
            }
            tableEntry = (u8 *)data_ov001_021900f8[M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11d)];
            M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = tableEntry[i];
            if (M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11d) == 1) {
                func_ov001_021737d8(0);
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = 0;
                func_ov001_02173924();
                return 0;
            }
        }
        p += 4;
    }

    p = (u8 *)data_ov001_0218f354;
    q = (u8 *)data_ov001_0218f364;
    for (i = 2; i < 4; i++) {
        func_ov001_0218b2e0(p, q, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i + 0x2f) {
                return 0;
            }
            M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = (u8)data_ov001_0218f344[i];
            if (M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11d) == 1) {
                func_ov001_021737d8(0);
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = (u8)(i + 0x2f);
                func_ov001_02173924();
                return 0;
            }
        }
        p += 4;
        q += 4;
    }

    p = (u8 *)data_ov001_0218f5d0;
    q = (u8 *)data_ov001_0218f344;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, q, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i + 0x33) {
                return 0;
            }
            M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = (u8)data_ov001_0218f32c[i];
            M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = (u8)(i + 0x33);
            func_ov001_02173924();
            return 0;
        }
        p += 4;
    }

    func_ov001_0218b2e0(data_ov001_0218f320, data_ov001_0218f350, buf);
    if (func_ov001_0218bcb0(buf) != 0) {
        if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != 0x2f) {
            return 0;
        }
        func_ov001_02173074();
        M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = 0x2f;
        func_ov001_02173924();
        return 0;
    }

    func_ov001_0218b2e0(data_ov001_0218f34c, data_ov001_0218f360, buf);
    if (func_ov001_0218bcb0(buf) != 0) {
        if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != 0x30) {
            return 0;
        }
        func_ov001_021730a4();
        M2C_FIELD(data_ov001_02193d1c, u8 *, 0x121) = 0x30;
        func_ov001_02173924();
        return 0;
    }
    return 0;
}

void func_ov001_02173074(void) {
 extern void *data_ov001_02193d1c;
 s32 n;
 n=M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d)==2?0:2;
 func_ov001_021737d8(n); func_ov001_02185024(1);
}

void func_ov001_021730a4(void) {
 extern void *data_ov001_02193d1c;
 func_ov001_021737d8(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d)!=1);
 func_ov001_02185024(1);
}

void func_ov001_021730d4(void) {
    extern u16 data_ov001_0218fd20[];
    extern u16 data_ov001_0218f36c[];
    extern u16 data_ov001_0218f330[];
    extern u16 data_ov001_0218f364[];
    extern u16 data_ov001_0218f354[];
    extern u16 data_ov001_0218f344[];
    extern u16 data_ov001_0218f32c[];
    extern void *data_ov001_02193d1c;
    void func_ov001_0218b2e0(void *, void *, void *);
    s32 func_ov001_0218bb6c(void *);
    void func_ov001_021732d8(s32);
    M2C_UNK func_ov001_02185024(M2C_UNK);

    s32 i;
    u8 buf[8];
    u8 *q;
    u8 *p;

    if (func_ov001_0218bb6c(data_ov001_0218fd20) == 0) {
        goto fail;
    }

    p = (u8 *)data_ov001_0218f36c;
    for (i = 0; i < 0x2f; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f330, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i) {
                goto fail;
            }
            func_ov001_021732d8(i);
            goto tail;
        }
        p += 4;
    }

    q = (u8 *)data_ov001_0218f364;
    p = (u8 *)data_ov001_0218f354;
    for (i = 2; i < 4; i++) {
        func_ov001_0218b2e0(p, q, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i + 0x2f) {
                goto fail;
            }
            func_ov001_021732d8(i + 0x2f);
            if (i != 3) {
                return;
            }
            M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122) =
                (u8)(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122) + 1);
            {
                u8 __v = M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122);
                if (__v < 0x28) {
                    return;
                }
            }
            if (M2C_FIELD(data_ov001_02193d1c, u8 *, 0x123) == 0) {
                func_ov001_02185024(9);
                M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) = -1;
                return;
            } else {
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11c) = 0x80;
                M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122) =
                    (u8)(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122) - 7);
                return;
            }
        }
        q += 4;
        p += 4;
    }

    p = (u8 *)data_ov001_0218f344;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f32c, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d1c, s8 *, 0x11e) != i + 0x33) {
                goto fail;
            }
            func_ov001_021732d8(i + 0x33);
            goto tail;
        }
        p += 4;
    }

fail:
    func_ov001_021732d8(-1);

tail:
    M2C_FIELD(data_ov001_02193d1c, u8 *, 0x122) = 0;
    return;
}

void func_ov001_021732d8(s32 arg0) {
 extern void *data_ov001_02193d1c;
 if(arg0==M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f)) return;
 func_ov001_0217385c(arg0,1);
 func_ov001_0217385c(M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f),0);
 M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f)=arg0;
}


