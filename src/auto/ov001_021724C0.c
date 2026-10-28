/* 18 functions from 0x021724C0 to 0x0217332C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_021724c0(void) {
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

void func_ov001_021728b0(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172944();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x30);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x51) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 0, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 0, 0x51);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172944);
}

void func_ov001_02172944(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_021729d8();
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

void func_ov001_02172a6c(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172b00();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0xC0);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x93) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, 0x93);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 4, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172b00);
}

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

M2C_UNK func_ov001_02172ba4(void) {
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
        u16 *b = data_ov001_0218f34c;
        u16 *c = data_ov001_0218f35c;
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
            b += 2;
            c += 2;
        }
    }
    {
        u16 *d = data_ov001_0218f344;
        u16 *e = data_ov001_0218f32c;
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

