/* 42 functions from 0x02181A84 to 0x02182A4C (ov001), found by ds-decomp. */
#include "common.h"

/* Load the background-step character data and enable display backgrounds. */
void func_ov001_02181a84(void) {
    M2C_UNK func_ov001_0218445c(void);
    M2C_UNK func_ov001_02175ddc(void);
    void func_ov001_02181ba8(void);
    M2C_UNK func_ov001_021722ac(void);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_02175e04(M2C_UNK);
    M2C_UNK func_ov001_02172094(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK);
    extern M2C_UNK data_ov001_02193dd4;
    extern M2C_UNK data_ov001_0218fb38;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafc;
    extern void func_ov001_02181c94(void);

    M2C_UNK r4;
    M2C_UNK r5;
    M2C_UNK r6;
    M2C_UNK r3;
    M2C_UNK r12p;
    M2C_UNK r1p;
    M2C_UNK r2p;
    M2C_UNK r3p;
    M2C_UNK rowByte;

    r4 = func_ov001_0218445c();
    M2C_FIELD(&data_ov001_02193dd4, u8 *, 2) = 0;
    if ((s8)M2C_FIELD(&data_ov001_02193dd4, s8 *, 0) == 0) {
        M2C_FIELD(&data_ov001_02193dd4, s8 *, 0) = 1;
    }
    if (func_ov001_02175ddc() != 0) {
        if ((s8)M2C_FIELD(&data_ov001_02193dd4, u8 *, 1) == 2) {
            M2C_FIELD(&data_ov001_02193dd4, u8 *, 1) = 0;
        }
        if ((s8)M2C_FIELD(&data_ov001_02193dd4, u8 *, 0) == 2) {
            M2C_FIELD(&data_ov001_02193dd4, u8 *, 0) = 1;
        }
        func_ov001_02181ba8();
        func_ov001_021722ac();
        r5 = func_ov001_02175ddc();
        {
            u8 u = (u8)M2C_FIELD((void *)r4, u8 *, 0xF4);
            s8 d = (s8)M2C_FIELD(&data_ov001_0218fb38, s8 *, r5);
            func_ov001_02171c24(0x32, d, u + 1);
        }
        func_ov001_02171dd0(1);
    }

    r6 = func_ov001_02175e04(1);
    r5 = func_ov001_02175e04(1);
    r4 = func_ov001_02175e04(1);
    r3 = func_ov001_02175e04(1);

    r12p = (M2C_UNK)((u8 *)&data_ov001_0218faf6 + r6 * 32);
    rowByte = (s8)M2C_FIELD(&data_ov001_02193dd4, s8 *, 1);
    r1p = (M2C_UNK)((u8 *)&data_ov001_0218fafa + r5 * 32);
    r2p = (M2C_UNK)((u8 *)&data_ov001_0218faf8 + r4 * 32);
    r5 = rowByte * 8;
    r3p = (M2C_UNK)((u8 *)&data_ov001_0218fafc + r3 * 32);

    func_ov001_02172094(
        *(u16 *)((u8 *)r12p + r5),
        *(u16 *)((u8 *)r1p + r5),
        *(u16 *)((u8 *)r2p + r5),
        *(u16 *)((u8 *)r3p + r5)
    );

    func_ov001_02175d54((M2C_UNK)&func_ov001_02181c94);
}

void func_ov001_02181ba8(void) {
    s32 func_ov001_02171d30(void *);
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    s32 func_ov001_02189dc8(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_0218fa80;
    extern M2C_UNK data_ov001_02190a0c;
    extern M2C_UNK data_ov001_02190a24;
    extern M2C_UNK data_ov001_02190a3c;
    extern M2C_UNK data_ov001_02193dd4;
    extern M2C_UNK func_020040b4;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    typedef struct { u8 bytes[22]; } PathBuffer;
    PathBuffer pathBuffer = *(PathBuffer *)&data_ov001_0218fa80;
    func_ov001_02171d90(&data_ov001_02190a0c, &func_020046cc);
    func_ov001_02171d90(&data_ov001_02190a24, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190a3c, &func_0200448c);
    M2C_FIELD(&data_ov001_02193dd4, s32 *, 4) = func_ov001_02189dc8(func_ov001_02171d30(&pathBuffer), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02181c94(void) {
    extern M2C_UNK func_ov001_02181ce8;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    func_ov001_02175d54(&func_ov001_02181ce8);
}

void func_ov001_02181ce8(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02181d24;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    func_ov001_02175d54(&func_ov001_02181d24);
}

void func_ov001_02181d24(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_02181d4c;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02181d4c);
}

extern void func_ov001_02181d60(void);
extern void func_ov001_02181ee4(void);
extern void func_ov001_02181ee8(void);
void func_ov001_02181d4c(void) {
    void func_ov001_02181d60(void);
    void func_ov001_02181ee4(void);
    void func_ov001_02181ee8(void);
    func_ov001_02181d60();
    func_ov001_02181ee4();
    func_ov001_02181ee8();
}

void func_ov001_02181d60(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    M2C_UNK func_ov001_02172094(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175e04(M2C_UNK);
    void func_ov001_021820f0(M2C_UNK);
    s32 func_ov001_0218bb00(s32);
    s32 func_ov001_0218bb24(s32);
    s32 func_ov001_0218bbd8(void *);
    extern M2C_UNK data_ov001_0218fab6;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218fafc;
    extern M2C_UNK data_ov001_02193dd4;

    u32 index;
    u8 *entry;
    s32 t0, t1, t2, t3;
    u8 *base0, *base1, *base2, *base3;
    s32 row;
    u16 va, vb, vc, vd;

    for (index = 0; index < 4; index++) {
        entry = (u8 *)&data_ov001_0218fab6 + func_ov001_02175e04(1) * 32 + index * 8;
        if (func_ov001_0218bbd8(entry) != 0) {
            func_ov001_021716d8(1);
            M2C_FIELD(&data_ov001_02193dd4, s8 *, 1) = (s8)index;
            t0 = func_ov001_02175e04(1);
            t1 = func_ov001_02175e04(1);
            t2 = func_ov001_02175e04(1);
            t3 = func_ov001_02175e04(1);
            base0 = (u8 *)&data_ov001_0218faf6 + t0 * 32;
            base2 = (u8 *)&data_ov001_0218faf8 + t2 * 32;
            base1 = (u8 *)&data_ov001_0218fafa + t1 * 32;
            base3 = (u8 *)&data_ov001_0218fafc + t3 * 32;
            row = (s8)M2C_FIELD(&data_ov001_02193dd4, s8 *, 1) * 8;
            va = *(u16 *)(base0 + row);
            vb = *(u16 *)(base1 + row);
            vc = *(u16 *)(base2 + row);
            vd = *(u16 *)(base3 + row);
            func_ov001_02172094(va, vb, vc, vd);
            return;
        }
    }
    if (func_ov001_0218bb00(1) != 0) { func_ov001_021716d8(1); return; }
    if (func_ov001_0218bb00(2) != 0) { func_ov001_021716d8(0); return; }
    if (func_ov001_0218bb24(0x40) != 0) { func_ov001_021820f0(1); return; }
    if (func_ov001_0218bb24(0x80) != 0) { func_ov001_021820f0(3); return; }
    if (func_ov001_0218bb24(0x20) != 0) { func_ov001_021820f0(0); return; }
    if (func_ov001_0218bb24(0x10) == 0) return;
    func_ov001_021820f0(2);
}

void func_ov001_02181ee4(void) {

}

void func_ov001_02181ee8(void) {
    s32 func_ov001_021716c4(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_021821e4(void);
    void func_ov001_02181f3c(void);
    extern M2C_UNK data_ov001_02193dd4;
    switch (func_ov001_021716c4()) {
    case 0: func_ov001_02185024(7); break;
    case 1:
        func_ov001_02185024(6);
        func_ov001_021821e4();
        M2C_FIELD(&data_ov001_02193dd4, u8 *, 2) = 1;
        break;
    default: return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02181f3c);
}

void func_ov001_02181f3c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02181f5c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02181f5c);
}

void func_ov001_02181f5c(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK data_ov001_02193dd4;
    extern M2C_UNK func_ov001_02181fc0;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(&data_ov001_02193dd4, u8 *, 2) != 0) {
        func_ov001_02171694();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x14, 8);
    func_ov001_02175d54(&func_ov001_02181fc0);
}

void func_ov001_02181fc0(void){
extern M2C_UNK data_ov001_02193dd4;
extern M2C_UNK func_ov001_02180d44,func_ov001_02180860,func_ov001_02179718,func_ov001_021803ec,func_ov001_0217d270;
s32 func_ov001_0218a800(s32);s32 func_ov001_0217170c(void);
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_0217170c())return;
func_ov001_02172184();func_ov001_02171cf8();func_ov001_02189ebc(M2C_FIELD(&data_ov001_02193dd4,void **,4));
func_ov001_0218b368(1,1);func_ov001_0218b368(0,20);
if(!M2C_FIELD(&data_ov001_02193dd4,u8 *,2)){func_ov001_02175d64(2,0);func_ov001_02175d54(&func_ov001_02180d44);return;}
switch(M2C_FIELD(&data_ov001_02193dd4,s8 *,1)){
case 0:func_ov001_02175d64(2,1);func_ov001_02175d54(&func_ov001_02180860);return;
case 1:func_ov001_02175d64(2,1);func_ov001_02175d54(&func_ov001_02179718);return;
case 2:func_ov001_02175d64(2,1);func_ov001_02175d54(&func_ov001_021803ec);return;
case 3:func_ov001_02175d64(2,0);func_ov001_02175da0(0,0);func_ov001_0217f72c(1);func_ov001_02175d54(&func_ov001_0217d270);return;
}
}

void func_ov001_021820f0(M2C_UNK arg0) {
    M2C_UNK func_ov001_02175e04(M2C_UNK);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02172094(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193dd4;
    extern M2C_UNK data_ov001_0218fa96;
    extern M2C_UNK data_ov001_0218faf6;
    extern M2C_UNK data_ov001_0218fafa;
    extern M2C_UNK data_ov001_0218faf8;
    extern M2C_UNK data_ov001_0218fafc;

    s32 temp_r4;
    s32 temp_idx;
    s32 temp_offset;
    s8 temp_val;
    s32 row;
    s32 r6, r5, temp_r4b, r3;
    M2C_UNK a, b, c, d;

    temp_r4 = (s8)M2C_FIELD(&data_ov001_02193dd4, s8 *, 1);
    temp_idx = func_ov001_02175e04(1);
    temp_offset = (s32)&data_ov001_0218fa96 + temp_idx * 16 + temp_r4 * 4;
    temp_val = M2C_FIELD(arg0, s8 *, temp_offset);
    if (temp_val == -1) {
        return;
    }
    if (temp_val == 0) {
        M2C_FIELD(&data_ov001_02193dd4, s8 *, 0) = temp_r4;
    }
    if (temp_val != -2) {
        M2C_FIELD(&data_ov001_02193dd4, s8 *, 1) = temp_val;
        return;
    }

    M2C_FIELD(&data_ov001_02193dd4, s8 *, 1) = M2C_FIELD(&data_ov001_02193dd4, s8 *, 0);
    func_ov001_02185024(0x8);
    r6 = func_ov001_02175e04(1);
    r5 = func_ov001_02175e04(1);
    temp_r4b = func_ov001_02175e04(1);
    r3 = func_ov001_02175e04(1);
    row = M2C_FIELD(&data_ov001_02193dd4, s8 *, 1) * 8;

    a = *(u16 *)((u8 *)&data_ov001_0218faf6 + r6 * 32 + row);
    b = *(u16 *)((u8 *)&data_ov001_0218fafa + r5 * 32 + row);
    c = *(u16 *)((u8 *)&data_ov001_0218faf8 + temp_r4b * 32 + row);
    d = *(u16 *)((u8 *)&data_ov001_0218fafc + r3 * 32 + row);

    func_ov001_02172094(a, b, c, d);
}

void func_ov001_021821e4(void) {
    M2C_UNK func_ov001_021837e4(s32, u8, u8);
    struct Table { u8 values[4]; };
    extern struct Table data_ov001_0218fa7c;
    extern M2C_UNK data_ov001_02193dd4;
    struct Table table = data_ov001_0218fa7c;
    u8 value = table.values[M2C_FIELD(&data_ov001_02193dd4, s8 *, 1)];
    func_ov001_021837e4(M2C_FIELD(&data_ov001_02193dd4, s32 *, 4), value, value);
}

void func_ov001_0218223c(void) {
    M2C_UNK func_ov001_021713c4(M2C_UNK);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_021722ac();
    M2C_UNK func_ov001_0217231c(M2C_UNK);
    void func_ov001_021822c8(void);
    void func_ov001_02182370(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    extern s8 data_ov001_02193ddc;
    extern M2C_UNK func_ov001_02182408;
    s32 sp0;

    data_ov001_02193ddc = 0;
    func_ov001_021822c8();
    func_ov001_02175db4(0, &sp0);
    if (sp0 == 0) {
        func_ov001_02171c24(0x31, -1, 0);
    }
    func_ov001_02171dd0(2);
    if (sp0 == 0) {
        func_ov001_021722ac();
    }
    func_ov001_02171e58(0x2C);
    func_ov001_021713c4(0);
    func_ov001_02182370();
    func_ov001_0217231c(0);
    func_ov001_02185024(0xC);
    func_ov001_02175d54(&func_ov001_02182408);
}

void func_ov001_021822c8(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190a50, data_ov001_02190a68, data_ov001_02190a80;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190a50, &func_020046cc);
    func_ov001_02171d90(&data_ov001_02190a68, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190a80, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02182370(void) {
    extern u8 data_ov001_0218fb40[];
    extern void func_ov001_021825a8(s32);

    M2C_UNK temp_r4;
    M2C_UNK sp0;
    u8 sp4[12];

    temp_r4 = func_ov001_0218445c();
    func_02007e70(data_ov001_0218fb40, sp4, 0xC);
    func_ov001_02175db4(0, &sp0);
    if (sp0 == 2) {
        sp4[10] = 4;
    } else {
        sp4[10] = M2C_FIELD(temp_r4, u8 *, 0xF4) + 1;
    }
    if (func_0202ef64(sp4) == 0) {
        func_02007958();
    }
    if (sp0 == 0) {
        func_0202f2c8(M2C_FIELD(temp_r4, u8 *, 0xF4), temp_r4);
    }
    func_ov001_0218c884(0, (void *)func_ov001_021825a8, 0, 0x78);
}

void func_ov001_02182408(void) {
    void func_ov001_02182474(void);
    s32 sp0;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175db4(0, &sp0);
    if (sp0 == 0) {
        func_ov001_0218a824(2, 1, 1, 8);
        func_ov001_0218b314(1, 1);
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182474);
}

void func_ov001_02182474(void) {
    extern M2C_UNK func_ov001_021824a8;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_021824a8);
}

void func_ov001_021824a8(void) {
    void func_ov001_021824bc(void);
    void func_ov001_021824c0(void);
    void func_ov001_021824c4(void);
    func_ov001_021824bc();
    func_ov001_021824c0();
    func_ov001_021824c4();
}

void func_ov001_021824bc(void) {

}

void func_ov001_021824c0(void) {

}

void func_ov001_021824c4(void) {

}

void func_ov001_021824c8(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021824f0;
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_021824f0);
}

void func_ov001_021824f0(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02182514;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_02182514);
}

void func_ov001_02182514(void) {
    s32 func_ov001_02184c60();
    s32 func_0202f28c();
    s32 func_02046878();
    M2C_UNK func_02008048(s32, s32, s32);
    M2C_UNK func_ov001_02171494();
    M2C_UNK func_ov001_0218af70(s32);
    M2C_UNK func_ov001_0218b368(s32, s32);
    M2C_UNK func_ov001_02175d64(s32, s32);
    extern s8 data_ov001_02193ddc;
    extern M2C_UNK func_ov001_0217cc4c;
    void func_ov001_02182638(void);
    s32 temp_r4;
    temp_r4 = func_ov001_02184c60();
    if (func_0202f28c() == 0) return;
    func_02008048(func_02046878(), temp_r4 + 0xF0, 0xE);
    func_02008048(func_02046878(), temp_r4 + 0x1F0, 0xE);
    func_ov001_02171494();
    func_ov001_0218af70(0);
    func_ov001_0218b368(0, 0x15);
    if ((u8)data_ov001_02193ddc == 0) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(&func_ov001_0217cc4c);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182638);
}

void func_ov001_021825a8(s32 arg0) {
    s32 func_0202f10c(void);
    extern s8 data_ov001_02193ddc;
    s32 result = func_0202f10c();
    if (result == 0) return;
    func_ov001_021723d4();
    func_ov001_0218508c();
    if (result > 0) {
        data_ov001_02193ddc = 1;
        func_ov001_02185024(0x11);
    } else {
        func_0202f1dc();
        func_ov001_0217d260();
        func_ov001_02185024(0x12);
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021824c8);
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_02182614(s32 arg0, s32 arg1) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    func_ov001_0218b6f8(arg1, 0x20);
}

void func_ov001_02182628(s32 arg0, s32 arg1) {
    M2C_UNK func_ov001_0218b760(M2C_UNK);
    func_ov001_0218b760(arg1);
}

void func_ov001_02182638(void) {
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    void func_ov001_02182668();
    extern u8 data_ov001_02193de0;
    extern M2C_UNK func_ov001_021826d4;
    data_ov001_02193de0 = 0;
    func_ov001_02182668();
    func_ov001_02171e58(0x2D);
    func_ov001_02175d54(&func_ov001_021826d4);
}

void func_ov001_02182668(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190a94;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190a94, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16)((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16)((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16)((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16)((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021826d4(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02182708;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02182708);
}

void func_ov001_02182708(void) {
    extern M2C_UNK func_ov001_0218272c;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0218272c);
}

void func_ov001_0218272c(void) {
    void func_ov001_0218283c(void);
    void func_ov001_0218273c(void);
    func_ov001_0218283c();
    func_ov001_0218273c();
}

void func_ov001_0218273c(void) {

}

void func_ov001_02182740(void) {
    M2C_UNK func_ov001_02175db4(M2C_UNK, s32 *);
    M2C_UNK func_ov001_0218560c();
    extern M2C_UNK func_ov001_02182798;
    s32 sp0;

    func_ov001_02175db4(0, &sp0);
    if (sp0 != 0) {
        func_ov001_0218560c();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02182798);
}

void func_ov001_02182798(void) {
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    s32 func_ov001_02185b34();
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021768b8;
    extern M2C_UNK func_ov001_0217d270;
    s32 sp0;

    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_02185b34() == 0) {
        return;
    }
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(2, 1);
    func_ov001_02175db4(0, &sp0);
    if (sp0 == 0) {
        func_ov001_02175da0(0, 0);
        func_ov001_02175d54(&func_ov001_0217d270);
        return;
    }
    func_ov001_02175d54(&func_ov001_021768b8);
}

void func_ov001_0218283c(void) {
    s32 func_ov001_02175dec(void);
    extern u8 data_ov001_02193de0;
    extern M2C_UNK func_ov001_02176578;
    s32 sp0;
    s32 temp_r0;
    if ((u32)++data_ov001_02193de0 < 0xB4U) return;
    func_ov001_02175db4(0, &sp0);
    temp_r0 = func_ov001_02175dec();
    if ((temp_r0 != 0) && (temp_r0 == 1) && (sp0 != 0)) {
        func_ov001_02175d54(&func_ov001_02176578);
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182740);
}

void func_ov001_021828ac(void) {
    M2C_UNK func_ov001_02183fa0(void);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_021722ac(void);
    M2C_UNK func_ov001_02184960(void);
    void func_ov001_02182904(void);
    void func_ov001_02182970(void);
    s32 sp0;
    func_ov001_02183fa0();
    func_ov001_02175db4(0, &sp0);
    func_ov001_02182904();
    func_ov001_02171c24(0x31, -1, 0);
    if (sp0 != 2) func_ov001_021722ac();
    if (sp0 == 1) func_ov001_02184960();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182970);
}

void func_ov001_02182904(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190aa8;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190aa8, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02182970(void) {
    extern M2C_UNK func_ov001_021829c4;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    func_ov001_02175d54(&func_ov001_021829c4);
}

void func_ov001_021829c4(void) {
    struct Table { s32 values[3]; };
    extern struct Table data_ov001_0218fb4c;
    extern M2C_UNK func_ov001_02182a4c;
    M2C_UNK func_ov001_021862d8(s32, s32, s32, s32, s32);
    struct Table table = data_ov001_0218fb4c;
    s32 index;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02175db4(0, &index);
    func_ov001_021862d8(table.values[index], 1, 1, -1, 0);
    func_ov001_02175d54(&func_ov001_02182a4c);
}

