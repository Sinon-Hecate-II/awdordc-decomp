/* 53 functions from 0x0217FB68 to 0x02180B68 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_0217fb68(void) {
    extern u8 data_ov001_02193db8;
    extern M2C_UNK func_ov001_0217fbdc;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (data_ov001_02193db8 == 0) {
        func_ov001_02171694();
    }
    if (data_ov001_02193db8 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_0217fbdc);
}

void func_ov001_0217fbdc(void) {
    M2C_UNK func_ov001_02171494(void);
    s32 func_ov001_0217170c(void);
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02176438(void);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193db8;
    extern M2C_UNK func_ov001_0217fd94;
    extern M2C_UNK func_ov001_02181a84;
    if (func_ov001_0218a800(0) != 0) return;
    if ((data_ov001_02193db8 == 0) && (func_ov001_0218a800(1) != 0)) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_02171494();
    func_ov001_0218af70(0);
    if (data_ov001_02193db8 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193db8 == 0) {
        func_ov001_02176438();
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(&func_ov001_02181a84);
        return;
    }
    func_ov001_02175d64(0, 0);
    func_ov001_02175d54(&func_ov001_0217fd94);
}

void func_ov001_0217fca4(void) {
    s32 func_ov001_0217645c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c(void);
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_ov001_02171750(void);
    extern u8 data_ov001_02193db8;
    extern M2C_UNK func_ov001_0217fb48;
    void func_ov001_0217fd28(void);
    switch (func_ov001_0217645c()) {
    case 2:
        data_ov001_02193db8 = 1;
        func_ov001_02175d54(&func_ov001_0217fb48);
        return;
    case 4:
        data_ov001_02193db8 = 0;
        func_ov001_0218508c();
        func_ov001_02185024(9);
        func_ov001_021862d8(0xD, 1, 1, -1, 0);
        func_ov001_02171750();
        func_ov001_02175d54((M2C_UNK *)&func_ov001_0217fd28);
        return;
    }
}

void func_ov001_0217fd28(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217fd54;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_0217fd54);
}

void func_ov001_0217fd54(void) {
    s32 func_ov001_0218665c();
    extern M2C_UNK func_ov001_0217fb48;
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0217fb48);
}

s32 func_ov001_0217fd74(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0217fd94(void) {
    M2C_UNK func_ov001_021713c4(M2C_UNK);
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK func_ov001_021722ac(void);
    void func_ov001_0217fdd0(void);
    void func_ov001_0217fe50(void);
    extern u8 data_ov001_02193dbc;
    data_ov001_02193dbc = 0;
    func_ov001_0217fdd0();
    func_ov001_021722ac();
    func_ov001_02171e58(0x2A);
    func_ov001_021713c4(2);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217fe50);
}

void func_ov001_0217fdd0(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_021908ec;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_021908ec, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217fe50(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217fe84;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217fe84);
}

void func_ov001_0217fe84(void) {
    void func_ov001_0217feb0(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217feb0);
}

void func_ov001_0217feb0(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217fed8;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0217fed8);
}

void func_ov001_0217fed8(void) {
    M2C_UNK func_02006030(s32);
    void func_ov001_021800a0(void);
    void func_ov001_0217fef8(void);
    void func_ov001_0217ff30(void);
    void func_ov001_0217ff34(void);
    func_02006030(10);
    func_ov001_021800a0();
    func_ov001_0217fef8();
    func_ov001_0217ff30();
    func_ov001_0217ff34();
}

void func_ov001_0217fef8(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_0217fd74() == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_0217ff30(void) {

}

void func_ov001_0217ff34(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    extern M2C_UNK func_ov001_0217ff60;
    if (func_ov001_021716c4() != 0) {
        return;
    }
    func_ov001_0218508c();
    func_ov001_02185024(7);
    func_ov001_02175d54(&func_ov001_0217ff60);
}

void func_ov001_0217ff60(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217ff80;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217ff80);
}

void func_ov001_0217ff80(void) {
    M2C_UNK func_ov001_02171694();
    extern u8 data_ov001_02193dbc;
    extern M2C_UNK func_ov001_0217ffe4;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193dbc == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_0217ffe4);
}

void func_ov001_0217ffe4(void) {
    M2C_UNK func_ov001_02171494(void);
    s32 func_ov001_0217170c(void);
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02176438(void);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193dbc;
    extern M2C_UNK func_ov001_021801c4;
    extern M2C_UNK func_ov001_02181a84;
    if (func_ov001_0218a800(0) != 0) return;
    if ((data_ov001_02193dbc == 0) && (func_ov001_0218a800(1) != 0)) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_02171494();
    func_ov001_0218af70(0);
    if (data_ov001_02193dbc == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_02176438();
    if (data_ov001_02193dbc == 0) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(&func_ov001_02181a84);
        return;
    }
    func_ov001_02175d64(0, 0);
    func_ov001_02175d54(&func_ov001_021801c4);
}

void func_ov001_021800a0(void) {
s32 func_ov001_0217645c(void); M2C_UNK func_ov001_02185024(M2C_UNK); M2C_UNK func_ov001_0218508c(void); M2C_UNK func_ov001_02176518(void); M2C_UNK func_ov001_021862d8(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32); M2C_UNK func_ov001_02171750(void);
extern u8 data_ov001_02193dbc; void func_ov001_0217ff60(void); void func_ov001_02180178(void);
switch(func_ov001_0217645c()){
case 3: data_ov001_02193dbc=1;func_ov001_0218508c();func_ov001_02176518();func_ov001_02175d54((M2C_UNK *)&func_ov001_0217ff60);return;
case 4: data_ov001_02193dbc=0;func_ov001_0218508c();func_ov001_02185024(9);func_ov001_021862d8(13,1,1,-1,0);func_ov001_02171750();func_ov001_02175d54((M2C_UNK *)&func_ov001_02180178);return;
case 5: data_ov001_02193dbc=0;func_ov001_0218508c();func_ov001_02185024(18);func_ov001_021862d8(14,1,1,-1,0);func_ov001_02171750();func_ov001_02175d54((M2C_UNK *)&func_ov001_02180178);return;
}}

void func_ov001_02180178(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_021801a4;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_021801a4);
}

void func_ov001_021801a4(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217ff60);
}

void func_ov001_021801c4(void) {
M2C_UNK func_ov001_02171e58(M2C_UNK);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK func_ov001_02185024(M2C_UNK);
void func_ov001_02180200(void);
void func_ov001_02180280(void);
extern s8 data_ov001_02193dc0;
data_ov001_02193dc0=0;
func_ov001_02180200();
func_ov001_021722ac();
func_ov001_02171e58(0x26);
func_ov001_02185024(0x10);
func_ov001_02175d54((M2C_UNK *)&func_ov001_02180280);
}

void func_ov001_02180200(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190900;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190900, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02180280(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021802b4;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021802b4);
}

void func_ov001_021802b4(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_021802d8;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_021802d8);
}

void func_ov001_021802d8(void) {
    void func_ov001_021802e8(void);
    void func_ov001_02180398(void);
    func_ov001_02180398();
    func_ov001_021802e8();
}

void func_ov001_021802e8(void) {

}

void func_ov001_021802ec(void) {
    extern M2C_UNK func_ov001_02180328;
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02180328);
}

void func_ov001_02180328(void) {
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021828ac;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(0, 0);
    func_ov001_02175da0(0, 1);
    func_ov001_02175d54(&func_ov001_021828ac);
}

void func_ov001_02180398(void) {
    extern s8 data_ov001_02193dc0;
    void func_ov001_021802ec(void);
    M2C_FIELD(&data_ov001_02193dc0,u8 *,0) = M2C_FIELD(&data_ov001_02193dc0,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193dc0,u8 *,0) < 120U) return;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021802ec);
}

s32 func_ov001_021803cc(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021803ec(void) {
extern u8 data_ov001_02193dc4;
void func_ov001_021804f0(void);
void func_ov001_02180448(void);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK func_ov001_02171c24(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_02171dd0(M2C_UNK);
M2C_UNK func_ov001_02171e58(M2C_UNK);
M2C_UNK func_ov001_021713c4(M2C_UNK);
M2C_UNK func_ov001_02185024(M2C_UNK);
data_ov001_02193dc4=0;
func_ov001_02180448();
func_ov001_021722ac();
func_ov001_02171c24(0x37,-1,0);
func_ov001_02171dd0(2);
func_ov001_02171e58(0x24);
func_ov001_021713c4(0);
func_ov001_02185024(0xb);
func_ov001_02175d54((M2C_UNK *)&func_ov001_021804f0);
}

void func_ov001_02180448(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190914, data_ov001_0219092c, data_ov001_02190944;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190914, &func_020046cc);
    func_ov001_02171d90(&data_ov001_0219092c, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190944, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_021804f0(void) {
    extern M2C_UNK func_ov001_02180544;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02180544);
}

void func_ov001_02180544(void) {
void func_ov001_02180584(void);
M2C_UNK func_ov001_021763cc(void);
M2C_UNK func_ov001_02171e20(M2C_UNK);
s32 func_ov001_0218a800(s32);
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
func_ov001_021763cc();
func_ov001_02171e20(1);
func_ov001_02175d54((M2C_UNK *)&func_ov001_02180584);
}

void func_ov001_02180584(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_021805ac;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_021805ac);
}

void func_ov001_021805ac(void) {
    M2C_UNK func_02006030(s32);
    void func_ov001_02180790();
    void func_ov001_021805cc(void);
    void func_ov001_02180604(void);
    void func_ov001_02180608(void);
    func_02006030(10);
    func_ov001_02180790();
    func_ov001_021805cc();
    func_ov001_02180604();
    func_ov001_02180608();
}

void func_ov001_021805cc(void) {
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_021803cc() == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02180604(void) {

}

void func_ov001_02180608(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    extern M2C_UNK func_ov001_02180634;
    if (func_ov001_021716c4() != 0) {
        return;
    }
    func_ov001_0218508c();
    func_ov001_02185024(7);
    func_ov001_02175d54(&func_ov001_02180634);
}

void func_ov001_02180634(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02180654;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02180654);
}

void func_ov001_02180654(void) {
    extern u8 data_ov001_02193dc4;
    extern M2C_UNK func_ov001_021806c8;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (data_ov001_02193dc4 == 0) {
        func_ov001_02171694();
    }
    if (data_ov001_02193dc4 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x14, 8);
    func_ov001_02175d54(&func_ov001_021806c8);
}

void func_ov001_021806c8(void) {
    M2C_UNK func_ov001_02171494(void);
    s32 func_ov001_0217170c(void);
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02176438(void);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193dc4;
    extern M2C_UNK func_ov001_0217f97c;
    extern M2C_UNK func_ov001_02181a84;
    if (func_ov001_0218a800(0) != 0) return;
    if ((data_ov001_02193dc4 == 0) && (func_ov001_0218a800(1) != 0)) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_02171494();
    func_ov001_0218af70(0);
    if (data_ov001_02193dc4 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193dc4 == 0) {
        func_ov001_02176438();
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(&func_ov001_02181a84);
        return;
    }
    func_ov001_02175d64(0, 0);
    func_ov001_02175d54(&func_ov001_0217f97c);
}

void func_ov001_02180790(void) {
    s32 func_ov001_0217645c(void);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern void func_ov001_02180634(void);
    extern void func_ov001_02180814(void);
    M2C_UNK func_ov001_0218508c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_ov001_02171750(void);
    extern u8 data_ov001_02193dc4;

    switch (func_ov001_0217645c()) {
    case 1:
        data_ov001_02193dc4 = 1;
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02180634);
        return;
    case 4:
        data_ov001_02193dc4 = 0;
        func_ov001_0218508c();
        func_ov001_02185024(9);
        func_ov001_021862d8(0xD, 1, 1, -1, 0);
        func_ov001_02171750();
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02180814);
        return;
    }
}

void func_ov001_02180814(void) {
    extern M2C_UNK func_ov001_02180840;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_02180840);
}

void func_ov001_02180840(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02180634);
}

void func_ov001_02180860(void) {
extern u8 data_ov001_02193dc8;
extern M2C_UNK func_ov001_02180970;
void func_ov001_021808c8(void);
M2C_UNK func_ov001_02171c24(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov001_021722ac(void);
M2C_UNK func_ov001_02171dd0(M2C_UNK);
M2C_UNK func_ov001_02183f6c(void);
M2C_UNK func_ov001_02183fd4(void);
M2C_FIELD(&data_ov001_02193dc8,u16 *,2)=0;
data_ov001_02193dc8=0;
func_ov001_021808c8();
func_ov001_02171c24(0x33,-1,0);
func_ov001_021722ac();
func_ov001_02171dd0(2);
func_ov001_02171e58(0x33);
func_ov001_021713c4(0);
func_ov001_02183f6c();
func_ov001_02183fd4();
func_ov001_02185024(10);
func_ov001_02175d54(&func_ov001_02180970);
}

void func_ov001_021808c8(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190958, data_ov001_02190970, data_ov001_02190988;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190958, &func_020046cc);
    func_ov001_02171d90(&data_ov001_02190970, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190988, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02180970(void) {
    extern M2C_UNK func_ov001_021809c4;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021809c4);
}

void func_ov001_021809c4(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    extern M2C_UNK func_ov001_02180a00;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(1);
    func_ov001_02175d54(&func_ov001_02180a00);
}

void func_ov001_02180a00(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_02180a28;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02180a28);
}

void func_ov001_02180a28(void) {
    M2C_UNK func_ov001_02180b90();
    void func_ov001_02180a40(void);
    func_ov001_02180b68();
    func_ov001_02180b8c();
    func_ov001_02180b90();
    func_ov001_02180a40();
}

void func_ov001_02180a40(void){
M2C_UNK func_ov001_0218508c(void);s32 func_ov001_02184170(void **);
M2C_UNK func_ov001_021862d8(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);
M2C_UNK func_ov001_02185024(M2C_UNK);M2C_UNK func_ov001_02171750(void);
extern u8 data_ov001_02193dc8;
extern M2C_UNK func_ov001_02180cf8,func_ov001_02180bbc;
void *records;s32 count,i;void *p;
M2C_FIELD(&data_ov001_02193dc8,u16 *,2)=M2C_FIELD(&data_ov001_02193dc8,u16 *,2)+1;
if(M2C_FIELD(&data_ov001_02193dc8,u16 *,2)<300)return;
func_ov001_0218508c();
count=func_ov001_02184170(&records);
if(count==0){
data_ov001_02193dc8=2;
func_ov001_021862d8(15,1,1,-1,0);
func_ov001_02185024(18);func_ov001_02171750();func_ov001_02175d54(&func_ov001_02180cf8);return;
}
i=0;if(count>0){p=records;do{
if(M2C_FIELD(p,u8 *,0x28)!=2)break;
i++;p+=42;
}while(i<count);}
if(i==count){
data_ov001_02193dc8=3;
func_ov001_021862d8(14,1,1,-1,0);
func_ov001_02185024(18);func_ov001_02171750();func_ov001_02175d54(&func_ov001_02180cf8);return;
}
data_ov001_02193dc8=1;func_ov001_02185024(15);func_ov001_02175d54(&func_ov001_02180bbc);
}

