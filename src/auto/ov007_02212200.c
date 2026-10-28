/* 6 functions from 0x02212200 to 0x02213150 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_02212cbc(void) {
    M2C_UNK func_020ab200();
    func_020ab200();
}

void func_ov007_02212cc8(M2C_UNK arg0) {
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    s32 func_020d46e8(void);
    M2C_UNK func_ov007_02211f10(s32);
    s32 func_ov007_02211f20(void);
    M2C_UNK func_ov007_02212dcc(void);
    extern u16 *data_02101e84;
    s32 initialTimer;

    initialTimer = func_ov007_02211f20();
    if (*data_02101e84 & 1) {
        func_ov007_02211f10(0);
    }
    if (*data_02101e84 & 2) {
        func_ov007_02211f10(1);
    }
    if (*data_02101e84 & 0x400) {
        func_ov007_02211f10(2);
    }
    if (*data_02101e84 & 0x800) {
        func_ov007_02211f10(3);
    }
    if (*data_02101e84 & 0xC0B) {
        func_ov007_02212dcc();
    }
    if (initialTimer != func_ov007_02211f20()) {
        func_0208fe30(0x10011);
    }
    if (func_020d46e8() == 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov007_02212da0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6e8;
    func_01ffa3dc(&data_ov007_0221f6e8, 7);
}

void func_ov007_02212db8(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov007_0221f6e8;
    func_01ffa9e4(&data_ov007_0221f6e8);
}

M2C_UNK func_ov007_02212dcc(void) {
    M2C_UNK func_ov007_02211f00(void);
    M2C_UNK func_ov007_02211f20(void);
    extern M2C_UNK data_ov007_02221a50[];

    M2C_UNK r = func_ov007_02211f00();
    if (r == 0) return 0;
    if (r != 1) return 0;

    {
        M2C_UNK base = (M2C_UNK)data_ov007_02221a50;
        int offs[4];
        int i;
        offs[0]=0x0c; offs[1]=0x10; offs[2]=0x14; offs[3]=0x18;
        for (i=0;i<4;i++) {
            void *p = (void *)M2C_FIELD(base, void **, offs[i]);
            u8 b = M2C_FIELD(p, u8 *, 0x59) & 0x0f;
            M2C_UNK f = M2C_FIELD(p, M2C_UNK *, 0x40);
            f = (f & ~0x3fc0000) | ((M2C_UNK)b << 18);
            M2C_FIELD(p, M2C_UNK *, 0x40) = f;
        }
    }

    {
        M2C_UNK c = func_ov007_02211f20();
        M2C_UNK base = (M2C_UNK)data_ov007_02221a50;
        int off = 0;
        if (c == 0) off = 0x0c;
        else if (c == 1) off = 0x10;
        else if (c == 2) off = 0x14;
        else if (c == 3) off = 0x18;
        else { return 0; }
        {
            void *p = (void *)M2C_FIELD(base, void **, off);
            u8 b = (M2C_FIELD(p, u8 *, 0x59) & 0x0f) + 1;
            M2C_UNK f = M2C_FIELD(p, M2C_UNK *, 0x40);
            f = (f & ~0x3fc0000) | ((M2C_UNK)b << 18);
            M2C_FIELD(p, M2C_UNK *, 0x40) = f;
        }
    }

    {
        M2C_UNK c = func_ov007_02211f20();
        M2C_UNK base = (M2C_UNK)data_ov007_02221a50;
        int off = 0;
        if (c == 0) off = 0x20;
        else if (c == 1) off = 0x24;
        else if (c == 2) off = 0x28;
        else if (c == 3) off = 0x2c;
        else { return 0; }
        {
            void *p = (void *)M2C_FIELD(base, void **, off);
            u8 b = (M2C_FIELD(p, u8 *, 0x59) & 0x0f) + 1;
            M2C_UNK f = M2C_FIELD(p, M2C_UNK *, 0x40);
            f = (f & ~0x3fc0000) | ((M2C_UNK)b << 18);
            M2C_FIELD(p, M2C_UNK *, 0x40) = f;
        }
    }

    {
        M2C_UNK base = (M2C_UNK)data_ov007_02221a50;
        int offs[4];
        int i;
        offs[0]=0x20; offs[1]=0x24; offs[2]=0x28; offs[3]=0x2c;
        for (i=0;i<4;i++) {
            void *p = (void *)M2C_FIELD(base, void **, offs[i]);
            u8 b = M2C_FIELD(p, u8 *, 0x59) & 0x0f;
            M2C_UNK f = M2C_FIELD(p, M2C_UNK *, 0x40);
            f = (f & ~0x3fc0000) | ((M2C_UNK)b << 18);
            M2C_FIELD(p, M2C_UNK *, 0x40) = f;
        }
    }
    return 0;
}

