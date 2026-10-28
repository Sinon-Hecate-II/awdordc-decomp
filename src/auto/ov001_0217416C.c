/* 18 functions from 0x0217416C to 0x02174F68 (ov001), found by ds-decomp. */
#include "common.h"


void func_ov001_0217416c(void) {
    extern u8 data_ov001_0218f5f0[];
    extern u8 data_ov001_0218f5dc[];
    extern u8 data_ov001_0218f628[];
    extern u8 func_ov001_02174548[];
    extern void *data_ov001_02193d20;
    M2C_UNK func_ov001_0218b6f8();
    M2C_UNK func_ov001_0218a5f0();
    M2C_UNK func_ov001_0218a61c();
    M2C_UNK func_ov001_0218a260();
    M2C_UNK func_ov001_0218a474();
    M2C_UNK func_ov001_0218ac04();
    M2C_UNK func_ov001_0218a070();
    M2C_UNK func_ov001_02174f68();
    M2C_UNK func_ov001_0218c884();

    u16 sp1c;
    u16 sp1e;
    u16 sp20;
    u16 sp22;
    void *p;
    s32 mask;
    s32 i;
    u8 *src;
    u16 h;
    u8 *r9;
    s32 r10;
    s32 r8i;
    u16 r2h;
    u16 sp14;
    u16 sp0;
    s32 sp4;
    s32 sp8;
    void *spc;
    u16 sp1cnew;
    void *q;
    void *x;
    s32 sp10;
    u16 sp16;

    sp1c = *(u16*)(data_ov001_0218f5f0 + 0x20);
    sp1e = *(u16*)(data_ov001_0218f5f0 + 0x22);
    sp20 = 0x1c;
    sp22 = 0x14;

    p = (void*)func_ov001_0218b6f8(0x6c, 0x4);
    data_ov001_02193d20 = p;
    M2C_FIELD(p, u8*, 0x60) = 0x1f;
    M2C_FIELD(p, u8*, 0x63) = 0;
    M2C_FIELD(p, u8*, 0x66) = 1;
    M2C_FIELD(p, u8*, 0x67) = 1;
    M2C_FIELD(p, u8*, 0x68) = 1;

    mask = 0xc1fffcff;
    for (i = 0; i < 10; i++) {
        q = (void*)func_ov001_0218a5f0(0, 0x36);
        M2C_FIELD(p, void**, 0x10 + i*4) = q;
        *(s32*)q = (*(s32*)q & mask) | 0x200;
        h = M2C_FIELD(q, u16*, 0x4);
        h = (h & ~0xc00) | 0xc00;
        M2C_FIELD(q, u16*, 0x4) = h;
    }
    src = data_ov001_0218f5dc;
    for (i = 0; i < 2; i++) {
        u8 b = *src++;
        q = (void*)func_ov001_0218a5f0(0, b);
        M2C_FIELD(p, void**, 0x38 + i*4) = q;
        *(s32*)q = (*(s32*)q & mask) | 0x200;
        h = M2C_FIELD(q, u16*, 0x4);
        h = (h & ~0xc00) | 0xc00;
        M2C_FIELD(q, u16*, 0x4) = h;
    }

    r9 = data_ov001_0218f628;
    r10 = 0;
    while (r10 < 2) {
        u8 b2 = *r9++;
        void *q2 = (void*)func_ov001_0218a61c(0, b2, 1);
        M2C_FIELD(p, void**, 0x40 + r10*4) = q2;
        func_ov001_0218a260(q2, -1, 0x200, 0);
        func_ov001_0218a474(q2, 3);
        r10++;
    }

    sp10 = 0;
    sp16 = 0;
    r10 = 0;
    r8i = 0;
    while (r10 < 4) {
        r2h = *(u16*)(func_ov001_02174548 + (r8i << 1));
        sp14 = r2h;
        sp0 = sp22;
        sp4 = 2;
        sp8 = 0x480;
        spc = (void*)&sp14;
        // stack args are illustrative; call
        func_ov001_0218ac04(0, 0xc, 0x4, 0, 0, 0);
        sp1c = sp1c + 0x20;
        r8i++;
        r10++;
    }

    q = (void*)func_ov001_0218a61c(0, -1, 2);
    M2C_FIELD(p, void**, 0x58) = q;
    func_ov001_0218a260(q, -1, 0x200, 0);
    func_ov001_0218a474(q, 2);

    x = (void*)func_ov001_0218c884(0, 0, 0, 0x78);
    M2C_FIELD(p, void**, 0x5c) = x;
    func_ov001_02174f68(0, 0);

    (void)sp0; (void)sp4; (void)sp8; (void)spc;
    (void)sp10; (void)sp14; (void)sp16; (void)sp1c; (void)sp1e; (void)sp20; (void)sp22;
    (void)p; (void)sp1cnew;
}

void func_ov001_021744a8(void) {
    extern void *data_ov001_02193d20;
    void func_ov001_021753c8(void);
    func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58));
    func_ov001_0218c924(M2C_FIELD(data_ov001_02193d20, s32 *, 0x5c), func_ov001_021753c8);
}

u8 func_ov001_021744dc(void) {
    extern void *data_ov001_02193d20;
    return M2C_FIELD(data_ov001_02193d20, u8 *, 0x60);
}

void func_ov001_021744f0(s8 arg0) {
    extern void *data_ov001_02193d20;
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x66) = arg0;
}

void func_ov001_02174504(s8 arg0) {
    extern void *data_ov001_02193d20;
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x67) = arg0;
}

void func_ov001_02174518(s8 arg0){extern void *data_ov001_02193d20;M2C_FIELD(data_ov001_02193d20,s8*,0x68)=arg0;}

s32 func_ov001_0217452c(void) {
    extern void *data_ov001_02193d20;
    if (data_ov001_02193d20 != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02174548(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_021745cc(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,16),u32*,0);
((volatile s32 *)pos)[1]=(v&0x1ff0000)>>16;
((volatile s32 *)pos)[0]=(v&255)-12;
if(pos[0]>76){func_ov001_02174f68(0,pos[0]);return;}
func_ov001_02174f68(0,76);
func_ov001_02174f68(1,192);
func_ov001_0218c924(arg0,func_ov001_021745cc);
}

void func_ov001_021745cc(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_02174650(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,28),u32*,0);
((volatile s32 *)pos)[1]=(v&0x1ff0000)>>16;
((volatile s32 *)pos)[0]=(v&255)-12;
if(pos[0]>99){func_ov001_02174f68(1,pos[0]);return;}
func_ov001_02174f68(1,99);
func_ov001_02174f68(2,192);
func_ov001_0218c924(arg0,func_ov001_02174650);
}

void func_ov001_02174650(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_021746d4(s32);
u32 v,y; s32 x,pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,40),u32*,0);
y=v&0x1ff0000;
x=(v&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>122){func_ov001_02174f68(2,pos[0]);return;}
func_ov001_02174f68(2,122);
func_ov001_02174f68(3,192);
func_ov001_0218c924(arg0,func_ov001_021746d4);
}

void func_ov001_021746d4(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_02174758(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,52),u32*,0);
((volatile s32 *)pos)[1]=(v>>16)&511;
((volatile s32 *)pos)[0]=(u8)v-12;
if(pos[0]>145){func_ov001_02174f68(3,pos[0]);return;}
func_ov001_02174f68(3,145);
func_ov001_02174f68(4,192);
func_ov001_0218c924(arg0,func_ov001_02174758);
}

void func_ov001_02174758(s32 arg0){extern void *data_ov001_02193d20;
void func_ov001_021747cc(void);
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193d20,s32*,0x40),0,&pos[1],&pos[0]);
pos[0]-=12;
if(pos[0]>170){func_ov001_02174f68(4,pos[0]);return;}
func_ov001_02174f68(4,170);func_ov001_02175290();func_ov001_0218c924(arg0,func_ov001_021747cc);
}

void func_ov001_021749c0(void);
void func_ov001_021747e4(void);
void func_ov001_02174b90(void);
void func_ov001_021747cc(void) {
          void func_ov001_02174dcc(void);
    func_ov001_021747e4();
    func_ov001_021749c0();
    func_ov001_02174b90();
    func_ov001_02174dcc();
}

void func_ov001_021747e4(void) {
    extern void *data_ov001_02193d20;
    s32 func_ov001_0218bbd8(void *);
    void func_ov001_0218b2e0(void *, void *, void *);
    void func_ov001_02185024(s32);
    extern u8 data_ov001_0218fd20[];
    extern u8 data_ov001_0218f642[];
    extern u8 data_ov001_0218f5f0[];
    extern u8 data_ov001_0218f618[];
    extern u8 data_ov001_0218f5f8[];
    extern u8 data_ov001_0218f620[];
    extern u8 data_ov001_0218f5fc[];

    u8 buf[8];
    u8 *p;
    s32 i;

    if (func_ov001_0218bbd8(data_ov001_0218fd20) == 0) {
        return;
    }
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) = -1;

    p = data_ov001_0218f642;
    for (i = 0; i < 10; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f0, buf);
        if (func_ov001_0218bbd8(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x67) == 0) {
                func_ov001_02185024(9);
                return;
            }
            func_ov001_02185024(0);
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x61) = (u8)i;
            return;
        }
        p += 4;
    }

    p = data_ov001_0218f618;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f8, buf);
        if (func_ov001_0218bbd8(buf) != 0) {
            if (i != 0) goto mid_770;
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x66) == 0) goto mid_78c;
mid_770:
            if (i != 1) goto mid_79c;
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x68) != 0) goto mid_79c;
mid_78c:
            func_ov001_02185024(9);
            return;
mid_79c:
            func_ov001_02185024(0);
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x61) = (u8)(i + 10);
            return;
        }
        p += 4;
    }

    p = data_ov001_0218f620;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5fc, buf);
        if (func_ov001_0218bbd8(buf) != 0) {
            func_ov001_02185024(0);
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x61) = (u8)(i + 12);
            return;
        }
        p += 4;
    }
}

void func_ov001_021749c0(void) {
    extern void *data_ov001_02193d20;
    extern u8 data_ov001_0218f642[];
    extern u8 data_ov001_0218f5f0[];
    extern u8 data_ov001_0218f6dc[];
    extern u8 data_ov001_0218f618[];
    extern u8 data_ov001_0218f5f8[];
    extern u8 data_ov001_0218f5ec[];
    extern u8 data_ov001_0218f620[];
    extern u8 data_ov001_0218f5fc[];
    extern u8 data_ov001_0218f5e8[];
    extern u8 data_ov001_0218fd20[];
    int func_ov001_0218bcb0(void *);
    void func_ov001_0218b2e0(void *, void *, void *);
    int func_ov001_02175290(void);

    u8 buf[8];
    u8 *p;
    s32 i;

    M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = 0;
    if (func_ov001_0218bcb0(data_ov001_0218fd20) == 0) {
        return;
    }

    p = data_ov001_0218f642;
    for (i = 0; i < 10; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f0, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i) {
                return;
            }
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f6dc[i];
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x63) = (u8)i;
            func_ov001_02175290();
            return;
        }
        p += 4;
    }

    p = data_ov001_0218f618;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f8, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i + 10) {
                return;
            }
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f5ec[i];
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x63) = (u8)(i + 10);
            func_ov001_02175290();
            return;
        }
        p += 4;
    }

    p = data_ov001_0218f620;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5fc, buf);
        if (func_ov001_0218bcb0(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i + 12) {
                return;
            }
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f5e8[i];
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x63) = (u8)(i + 12);
            func_ov001_02175290();
            return;
        }
        p += 4;
    }
}

void func_ov001_02174b90(void) {
    extern void *data_ov001_02193d20;
    extern u8 data_ov001_0218fd20[];
    extern u8 data_ov001_0218f642[];
    extern u8 data_ov001_0218f5f0[];
    extern u8 data_ov001_0218f618[];
    extern u8 data_ov001_0218f5f8[];
    extern u8 data_ov001_0218f620[];
    extern u8 data_ov001_0218f5fc[];
    void func_ov001_0218b2e0(void *, void *, void *);
    s32 func_ov001_0218bb6c(void *);
    void func_ov001_02174d80(s32);
    void func_ov001_02185024(s32);

    s32 i;
    u8 buf[8];
    u8 *p;

    if (func_ov001_0218bb6c(data_ov001_0218fd20) == 0) {
        goto fail;
    }

    p = data_ov001_0218f642;
    for (i = 0; i < 10; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f0, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i) {
                goto fail;
            }
            func_ov001_02174d80(i);
            goto tail;
        }
        p += 4;
    }

    p = data_ov001_0218f618;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5f8, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i + 10) {
                goto fail;
            }
            func_ov001_02174d80(i + 10);
            if (i != 0) {
                goto tail;
            }
            M2C_FIELD(data_ov001_02193d20, u8 *, 0x65) =
                (u8)(M2C_FIELD(data_ov001_02193d20, u8 *, 0x65) + 1);
            {
                u8 __v = M2C_FIELD(data_ov001_02193d20, u8 *, 0x65);
                if (__v < 0x28) {
                    return;
                }
            }
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x66) == 0) {
                func_ov001_02185024(9);
                M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) = -1;
                return;
            } else {
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = 0x10;
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x65) =
                    (u8)(M2C_FIELD(data_ov001_02193d20, u8 *, 0x65) - 7);
                return;
            }
        }
        p += 4;
    }

    p = data_ov001_0218f620;
    for (i = 0; i < 2; i++) {
        func_ov001_0218b2e0(p, data_ov001_0218f5fc, buf);
        if (func_ov001_0218bb6c(buf) != 0) {
            if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x61) != i + 12) {
                goto fail;
            }
            func_ov001_02174d80(i + 12);
            goto tail;
        }
        p += 4;
    }

fail:
    func_ov001_02174d80(-1);

tail:
    M2C_FIELD(data_ov001_02193d20, u8 *, 0x65) = 0;
    return;
}

void func_ov001_02174d80(s32 arg0){extern void *data_ov001_02193d20;
if(arg0==M2C_FIELD(data_ov001_02193d20,s8*,0x62))return;
func_ov001_021751c8(arg0,1);
func_ov001_021751c8(M2C_FIELD(data_ov001_02193d20,s8*,0x62),0);
M2C_FIELD(data_ov001_02193d20,s8*,0x62)=arg0;
}

void func_ov001_02174dcc(void) {
    extern void *data_ov001_02193d20;
    extern u8 data_ov001_0218f6dc[];
    extern u8 data_ov001_0218f5ec[];
    extern u8 data_ov001_0218f5e8[];
    void func_ov001_0217531c(s32);
    s32 func_ov001_0218bb00(s32);
    s32 func_ov001_0218bb24(s32);
    s32 func_ov001_0218bb48(s32);
    void func_ov001_02185024(s32);

    if (func_ov001_0218bb24(0x20)) {
        func_ov001_0217531c(0);
    }
    if (func_ov001_0218bb24(0x40)) {
        func_ov001_0217531c(1);
    }
    if (func_ov001_0218bb24(0x10)) {
        func_ov001_0217531c(2);
    }
    if (func_ov001_0218bb24(0x80)) {
        func_ov001_0217531c(3);
    }
    if (func_ov001_0218bb00(1)) {
        s8 k = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63);
        if (k < 10) {
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x67) != 0) {
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f6dc[k];
            } else {
                func_ov001_02185024(9);
            }
        } else {
            s32 t = k - 10;
            if (t < 2) {
                if (t == 0 && M2C_FIELD(data_ov001_02193d20, u8 *, 0x66) == 0) {
                    func_ov001_02185024(9);
                    return;
                }
                if (t == 1 && M2C_FIELD(data_ov001_02193d20, u8 *, 0x68) == 0) {
                    func_ov001_02185024(9);
                    return;
                }
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f5ec[t];
            } else {
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = data_ov001_0218f5e8[k - 12];
            }
        }
    } else {
        if (func_ov001_0218bb24(2)) {
            if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x66) == 0) {
                if (M2C_FIELD(data_ov001_02193d20, u8 *, 0x69) == 0) {
                    func_ov001_02185024(9);
                    M2C_FIELD(data_ov001_02193d20, u8 *, 0x69) = 1;
                }
            } else {
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x60) = 0x10;
            }
        } else {
            if (func_ov001_0218bb48(2)) {
                M2C_FIELD(data_ov001_02193d20, u8 *, 0x69) = 0;
            }
        }
    }
}

