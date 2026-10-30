/* 20 functions from 0x021858A4 to 0x021867AC (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02185f38(u16 *);
void func_ov001_02186090(u16 *);

#pragma opt_strength_reduction off
void func_ov001_021858a4(s32 arg0) {
extern s32 data_ov001_02193e0c;
extern const u8 data_ov001_0218fbd2[];
M2C_UNK func_ov001_0218a4d4(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK func_ov001_0218a384(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218c924(M2C_UNK,M2C_UNK);
void func_ov001_02185980(s32);
s32 pos[2],i;
func_ov001_0218a4d4(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[2],0,&pos[1],&pos[0]);
pos[1]-=8;
if(pos[1]>80){
for(i=2;i<5;i++)func_ov001_0218a384(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
return;
}
pos[1]=80;
for(i=2;i<5;i++)func_ov001_0218a384(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
func_ov001_0218c924(arg0,(M2C_UNK)func_ov001_02185980);
}
#pragma opt_strength_reduction reset
void func_ov001_02185980(s32 arg0) {
    extern M2C_UNK data_ov001_02193e0c;
    extern const u8 data_ov001_0218fbd2[];
    M2C_UNK func_ov001_0218a4d4(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov001_0218a384(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c924(M2C_UNK, M2C_UNK);
    void func_ov001_02185a5c(s32);
    s32 pos[2];
    s32 i;

    func_ov001_0218a4d4(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[1], 0, &pos[1], &pos[0]);
    pos[1] -= 8;
    if (pos[1] > 32) {
        for (i = 1; i < 5; i++) {
            func_ov001_0218a384(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[i], -1, pos[1], ((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
        }
        return;
    }
    pos[1] = 32;
    for (i = 1; i < 5; i++) {
        func_ov001_0218a384(((s32 *)M2C_FIELD(&data_ov001_02193e0c, void **, 4))[i], -1, pos[1], ((const u16 (*)[2])data_ov001_0218fbd2)[i][1]);
    }
    func_ov001_0218c924(arg0, (M2C_UNK)func_ov001_02185a5c);
}

#pragma opt_strength_reduction off
void func_ov001_02185a5c(s32 arg0) {
extern s32 data_ov001_02193e0c,data_ov001_02193e10;
extern const u8 data_ov001_0218fbd2[];
M2C_UNK func_ov001_0218a4d4(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK func_ov001_0218a384(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218c92c(M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_0218a1cc(M2C_UNK);
M2C_UNK func_ov001_0218b71c(M2C_UNK);
s32 pos[2],i;
func_ov001_0218a4d4(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[0],0,&pos[1],&pos[0]);
pos[1]-=8;
for(i=0;i<5;i++)func_ov001_0218a384(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i],-1,pos[1],M2C_FIELD(data_ov001_0218fbd2+i*4,u16 *,2));
if(pos[1]>0x1d6)return;
if(pos[1]<0x100)return;
func_ov001_0218c92c(0,arg0);
for(i=0;i<5;i++)func_ov001_0218a1cc(M2C_FIELD(&data_ov001_02193e0c,void ***,4)[i]);
func_ov001_0218b71c(&data_ov001_02193e10);
}
#pragma opt_strength_reduction reset
s32 func_ov001_02185b34(void) {
    extern M2C_UNK data_ov001_02193e0c;
    if (M2C_FIELD(&data_ov001_02193e0c, void **, 4) == NULL) {
        return 1;
    }
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c, void **, 4), u8 *, 0x18) == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02185b60(s32 arg0) {
    s32 func_ov001_02171d30(s32);
    s32 func_ov001_02189dc8(s32, s32, s32);
    void func_ov001_02185ba8(s32);
    extern s32 data_ov001_02190be4[];
    extern s32 data_ov001_02193e0c;
    data_ov001_02193e0c = func_ov001_02189dc8(func_ov001_02171d30(data_ov001_02190be4[arg0]), 0, 4);
    func_ov001_0218c884(1, func_ov001_02185ba8, 0, 0x78);
}

void func_ov001_02185ba8(s32 arg0) {
    extern s32 data_ov001_02193e0c;
    func_020067e0(data_ov001_02193e0c, 0x600);
    func_0200442c(data_ov001_02193e0c, 0, 0x600);
    func_ov001_02189ebc(data_ov001_02193e0c);
    func_ov001_0218c92c(1, arg0);
}

s32 func_ov001_02185bf4(s32 arg0) {
    void *func_ov001_0218b6f8(s32, s32);
    u64 func_02007004(void);
    s32 func_02012218(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02011af8(void *);
    u16 func_02011e98(void);
    void func_02007740(void *);
    void func_02008048(void *, void *, s32);
    s32 func_ov001_02185d78(void);
    M2C_UNK func_ov001_0218c884(M2C_UNK, void (*)(void), M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b71c(M2C_UNK);
    void func_ov001_02185ea8();
    void func_ov001_0218619c();
    extern void *data_ov001_02193e14;
    extern const u8 data_ov001_0218fbfc[];
    extern const u8 data_ov001_0218fbf0[];

    u8 buf[0x54];
    void *p;
    u16 h;
    M2C_UNK task;
    s32 i;
    u32 *dst;
    const u32 *src;

    p = func_ov001_0218b6f8(0x1ba0, 0x20);
    data_ov001_02193e14 = p;
    M2C_FIELD(p, s32 *, 0x1370) = arg0;

    {
        u64 ts = func_02007004();
        M2C_FIELD(p, u32 *, 0x1B88) = (u32)ts;
        M2C_FIELD(p, u32 *, 0x1B8C) = (u32)(ts >> 32);
    }

    if (func_02012218((M2C_UNK)p, (M2C_UNK)func_ov001_02185ea8, 3) != 2) {
        func_ov001_0218b71c((M2C_UNK)&data_ov001_02193e14);
        return 0;
    }

    func_02011af8((void *)((u8 *)p + 0x13B8));

    h = M2C_FIELD(p, u16 *, 0x13B8);
    if (h == 2) {
        dst = (u32 *)((u8 *)p + 0x1374);
        src = (const u32 *)data_ov001_0218fbfc;
        for (i = 0; i < 4; i++) {
            dst[i] = src[i];
        }
        dst[4] = src[4];
        M2C_FIELD(p, void **, 0x1374) = (u8 *)p + 0xF00;
    }

    M2C_FIELD(p, u16 *, 0x137C) = func_02011e98();

    func_02007740(buf);
    func_02008048((void *)((u8 *)p + 0x1388), (void *)data_ov001_0218fbf0, 8);
    M2C_FIELD(p, u8 *, 0x1391) = 1;
    func_02008048(buf + 4, (void *)((u8 *)p + 0x1394), M2C_FIELD(buf, u16 *, 0x1A) << 1);

    if (func_ov001_02185d78()) {
        task = func_ov001_0218c884(0, (void (*)(void))func_ov001_0218619c, 0, 0x78);
        M2C_FIELD(p, M2C_UNK *, 0x1B90) = task;
        return 1;
    }

    func_ov001_0218b71c((M2C_UNK)&data_ov001_02193e14);
    return 0;
}

s32 func_ov001_02185d78(void) {
    s32 func_020125b0(void (*)(void), void *);
    void func_ov001_02185ea8();
    extern void *data_ov001_02193e14;
    if (func_020125b0(func_ov001_02185ea8, (s8 *)data_ov001_02193e14 + 0x1374) == 2) {
        return 1;
    }
    return 0;
}

s32 func_ov001_02185dac(void) {
    s32 func_02011af8(void *);
    s32 func_02012274(void (*)(void));
    s32 func_020122ac(void (*)(void));
    void func_ov001_02185ea8(u16 *);
    void func_ov001_0218c94c(s32);
    M2C_UNK func_ov001_0218b71c(M2C_UNK);
    extern void *data_ov001_02193e14;

    *(u8 *)((s8 *)data_ov001_02193e14 + 0x1b94) = 1;
    func_02011af8((s8 *)data_ov001_02193e14 + 0x13b8);
    if (*(u16 *)((s8 *)data_ov001_02193e14 + 0x13b8) != 2) {
        if (func_02012274((void (*)(void))func_ov001_02185ea8) != 2) {
            return 0;
        }
        do {
            func_02011af8((s8 *)data_ov001_02193e14 + 0x13b8);
        } while (*(u16 *)((s8 *)data_ov001_02193e14 + 0x13b8) != 2);
    }
    if (func_020122ac((void (*)(void))func_ov001_02185ea8) != 2) {
        return 0;
    }
    if (*(s32 *)((s8 *)data_ov001_02193e14 + 0x1b90) != 0) {
        func_ov001_0218c94c(0);
    }
    if (*(u8 *)((s8 *)data_ov001_02193e14 + 0x1b94) == 2) {
        func_ov001_0218b71c((M2C_UNK)(void *)(&data_ov001_02193e14));
    }
    return 1;
}

void func_ov001_02185e90(s32 arg0) {
    extern void *data_ov001_02193e14;
    M2C_FIELD(data_ov001_02193e14, s32 *, 0x1370) = arg0;
}

void func_ov001_02185ea8(u16 *p) {
extern void *data_ov001_02193e14;u32 v;void *q;
if(p[1])return;q=data_ov001_02193e14;
v=M2C_FIELD(q,u8 *,0x1b94);
if(v){if(p[0]==2)M2C_FIELD(q,u8 *,0x1b94)=2;return;}
v=p[0];if(v!=38)return;
v=p[4];switch(v){case 5:if(M2C_FIELD(q,u8 *,0x1b96))func_ov001_02186090(p);else func_ov001_02185f38(p);func_ov001_02185d78();break;
case 4:func_ov001_02185d78();break;default:func_02007958(p);break;}
}

void func_ov001_02185f38(u16 *arg0) {
    void func_020067a8(void *, s32);
    s32 func_0206527c(void *, const void *, s32);
    void func_02008048(void *, void *, s32);
    extern void *data_ov001_02193e14;
    extern const u8 data_ov001_0218fbf0[];
    extern const u8 data_ov001_0218fbe8[];
    u8 *rec;
    s32 k;
    u8 *slot;
    s32 j;
    u8 *base;

    for (j = 0; j < arg0[7]; j++) {
        rec = ((void **)arg0)[4 + j];
        func_020067a8(rec, 0xC0);
        if (func_0206527c(rec + 0xC, data_ov001_0218fbf0, 8) != 0) continue;
        base = data_ov001_02193e14;
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (func_0206527c(rec + 4, slot, 6) == 0) {
                if (*(u8 *)(base + k * 7 + 0x1306) != 0) goto next;
                if (!(rec[0x15] & 1)) goto next;
                if (M2C_FIELD(base, void **, 0x1370) != NULL) {
                    ((void (*)(s32))M2C_FIELD(base, void **, 0x1370))(1);
                }
                return;
            }
            slot += 7;
        }
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (func_0206527c(slot, data_ov001_0218fbe8, 6) == 0) {
                func_02008048(rec + 4, base + 0x1300 + k * 7, 6);
                *(u8 *)((u8 *)data_ov001_02193e14 + k * 7 + 0x1306) = (rec[0x15] & 1) ? 1 : 0;
                break;
            }
            slot += 7;
        }
    next:;
    }
}

void func_ov001_02186090(u16 *arg0) {
    void func_020067a8(void *, s32);
    s32 func_0206527c(void *, const void *, s32);
    extern void *data_ov001_02193e14;
    extern const u8 data_ov001_0218fbf0[];
    extern M2C_UNK data_ov001_0219174c;

    void *g = data_ov001_02193e14;
    if (*((u8 *)g + 0x1B95) != 0) {
        void (*cb)(s32, void *) = *(void (**)(s32, void *))( (u8 *)g + 0x1370);
        if (cb != 0) {
            cb(0x8000000, &data_ov001_0219174c);
        }
        return;
    }

    func_020067a8((u8 *)g + 0x0F00, 0x400);

    {
        s32 j;
        u8 *base;
        u8 *slot;
        u8 *rec;
        s32 k;
        u16 count = arg0[7];

        for (j = 0; j < count; j++) {
            rec = ((void **)arg0)[4 + j];
            if (func_0206527c(rec + 0x0C, data_ov001_0218fbf0, 8) != 0) {
                continue;
            }
            if (!(rec[0x15] & 1)) {
                continue;
            }
            base = (u8 *)g + 0x1300;
            slot = g;
            for (k = 0; k < 16; k++) {
                if (func_0206527c(rec + 4, base, 6) == 0) {
                    if (*((u8 *)g + k * 7 + 0x1306) != 0) {
                        break;
                    }
                    {
                        void (*cb)(s32) = *(void (**)(s32))((u8 *)g + 0x1370);
                        if (cb == 0) {
                            *((u8 *)g + 0x1B95) = 1;
                            return;
                        }
                        cb(1);
                        return;
                    }
                }
                base += 7;
            }
        }
    }
}

void func_ov001_0218619c(s32 arg0) {
    u64 func_02007004(void);
    s32 func_0206527c(void *, const void *, s32);
    M2C_UNK func_ov001_0218c92c(M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193e14;
    extern const u8 data_ov001_0218fbe8[];
    u64 now;
    s32 i;
    s32 hasOn;
    s32 hasOff;
    u8 *rec;
    u8 *flag;
    u8 *base;

    now = func_02007004();
    base = data_ov001_02193e14;
    if (now < M2C_FIELD(base, u64 *, 0x1B88) + 0x17F898) {
        return;
    }
    hasOff = 0;
    hasOn = 0;
    i = 0;
    flag = base;
    rec = base + 0x1300;
    for (; i < 16; i++) {
        if (func_0206527c(rec, data_ov001_0218fbe8, 6) != 0) {
            if (M2C_FIELD(flag, u8 *, 0x1306) != 0) {
                hasOn = 1;
            } else {
                hasOff = 1;
            }
        }
        rec += 7;
        flag += 7;
    }
    if (hasOn && hasOff) {
        if (M2C_FIELD(base, void **, 0x1370) != NULL) {
            ((void (*)(s32)) M2C_FIELD(base, void **, 0x1370))(2);
        }
    } else if (hasOn) {
        if (M2C_FIELD(base, void **, 0x1370) != NULL) {
            ((void (*)(s32)) M2C_FIELD(base, void **, 0x1370))(1);
        }
    } else if (!hasOff) {
        if (M2C_FIELD(base, void **, 0x1370) != NULL) {
            ((void (*)(s32)) M2C_FIELD(base, void **, 0x1370))(0);
        }
    }
    M2C_FIELD(data_ov001_02193e14, s32 *, 0x1B90) = 0;
    M2C_FIELD(data_ov001_02193e14, u8 *, 0x1B96) = 1;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_021862d8(void *a, s32 b, void *c, s32 d, s32 e) {
    volatile s32 x = 1;
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)x;
}

void func_ov001_02186604(void) {
extern void *data_ov001_02193e18;void func_ov001_02186c68();s32 func_ov001_0218c884(s32,void (*)(),s32,s32);
func_ov001_0218c92c(0,M2C_FIELD(data_ov001_02193e18,s32 *,20));
M2C_FIELD(data_ov001_02193e18,s32 *,20)=func_ov001_0218c884(1,func_ov001_02186c68,0,120);
}

s8 func_ov001_02186648(void) {
    extern void *data_ov001_02193e18;
    return M2C_FIELD(data_ov001_02193e18, s8 *, 0x1B);
}

s32 func_ov001_0218665c(void) {
    extern void *data_ov001_02193e18;
    if (data_ov001_02193e18 != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02186678(s32 a) {
extern void *data_ov001_02193e18;void func_ov001_021866d8();
M2C_FIELD(data_ov001_02193e18,s8 *,26)--;
func_02003a10(0x4000050,M2C_FIELD(data_ov001_02193e18,s8 *,26));
if(M2C_FIELD(data_ov001_02193e18,s8 *,26)<=-12)func_ov001_0218c924(a,func_ov001_021866d8);
}

void func_ov001_021866d8(s32 arg0) {
    extern void *data_ov001_02193e18;
    extern const u16 data_ov001_0218fc9e[];
    M2C_UNK func_ov001_02186974(M2C_UNK);
    void func_ov001_02186908(void);
    void func_ov001_021867ac(void);
    M2C_UNK func_ov001_0218c884(M2C_UNK, void (*)(void), M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c92c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a4d4(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    s32 pos[2];

    func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193e18, s32 *, 0), 0, &pos[1], &pos[0]);
    pos[0] -= 0xc;
    if (pos[0] > data_ov001_0218fc9e[M2C_FIELD(data_ov001_02193e18, u8 *, 0x1c) << 1]) {
        func_ov001_02186974(pos[0]);
        return;
    }
    func_ov001_02186974(data_ov001_0218fc9e[M2C_FIELD(data_ov001_02193e18, u8 *, 0x1c) << 1]);
    if (M2C_FIELD(data_ov001_02193e18, u8 *, 0x1c) == 5) {
        M2C_FIELD(data_ov001_02193e18, s32 *, 0x14) =
            (M2C_UNK)func_ov001_0218c884(0, (void (*)(void))func_ov001_02186908, 0, 0x78);
    } else {
        M2C_FIELD(data_ov001_02193e18, s32 *, 0x14) =
            (M2C_UNK)func_ov001_0218c884(0, (void (*)(void))func_ov001_021867ac, 0, 0x78);
    }
    func_ov001_0218c92c(1, arg0);
}

