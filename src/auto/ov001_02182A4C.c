/* 60 functions from 0x02182A4C to 0x02183A20 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02182a4c(void) {
    void func_ov001_02182a88(void);
    void func_ov001_02182a8c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    void func_ov001_02182a90(void);
    func_ov001_02182a88();
    func_ov001_02182a8c();
    if (func_ov001_02186648() != 0) return;
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02185024(6);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182a90);
}

void func_ov001_02182a88(void) {

}

void func_ov001_02182a8c(void) {

}

void func_ov001_02182a90(void) {
    s32 func_ov001_0218665c();
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02182ac4(void);
    if (func_ov001_0218665c() != 0) return;
    func_ov001_0218a824(3, 0, 0x14, 8);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182ac4);
}

void func_ov001_02182ac4(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0218223c;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_0218b368(0, 0x14);
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(&func_ov001_0218223c);
}

void func_ov001_02182b00(void) {
 void func_ov001_02182b40(void);
 M2C_UNK func_ov001_02172250(M2C_UNK);
 M2C_UNK func_ov001_02171e58(M2C_UNK);
 M2C_UNK func_ov001_02185024(M2C_UNK);
 M2C_UNK func_ov001_02175d54();
 void func_ov001_02182bc0(void);
 extern u8 data_ov001_02193de4;
 data_ov001_02193de4 = 0;
 func_ov001_02182b40();
 func_ov001_02172250(8);
 func_ov001_02171e58(0x29);
 func_ov001_02185024(0x10);
 func_ov001_02175d54((M2C_UNK *)&func_ov001_02182bc0);
}

void func_ov001_02182b40(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190abc;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190abc, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02182bc0(void) {
 M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
 M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
 M2C_UNK func_ov001_02175d54();
 void func_ov001_02182bf4(void);
 func_ov001_0218a824(2, 0, 0x15, 8);
 func_ov001_0218b314(0, 0x15);
 func_ov001_02175d54((M2C_UNK *)&func_ov001_02182bf4);
}

void func_ov001_02182bf4(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02182c18;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_02182c18);
}

void func_ov001_02182c18(void) {
    void func_ov001_02182cd8(void);
    void func_ov001_02182c28(void);
    func_ov001_02182cd8();
    func_ov001_02182c28();
}

void func_ov001_02182c28(void) {

}

void func_ov001_02182c2c(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_02182c68(void);
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182c68);
}

void func_ov001_02182c68(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021828ac;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(0, 0);
    func_ov001_02175da0(0, 2);
    func_ov001_02175d54(&func_ov001_021828ac);
}

void func_ov001_02182cd8(void) {
    extern u8 data_ov001_02193de4;
    data_ov001_02193de4 = data_ov001_02193de4 + 1;
    if ((u32)data_ov001_02193de4 < 120U) return;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182c2c);
}

void func_ov001_02182d0c(void) {
    M2C_UNK func_ov001_02172250(M2C_UNK);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_02182d5c(void);
    void func_ov001_02182e04(void);
    extern u8 data_ov001_02193de8;
    data_ov001_02193de8 = 0;
    func_ov001_02182d5c();
    func_ov001_02172250(8);
    func_ov001_02171c24(0x38, -1, 0);
    func_ov001_02171dd0(1);
    func_ov001_02171e58(0x27);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182e04);
}

void func_ov001_02182d5c(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190ad0, data_ov001_02190ae8, data_ov001_02190b00;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190ad0, &func_020046cc);
    func_ov001_02171d90(&data_ov001_02190ae8, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190b00, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02182e04(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_02182e58(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182e58);
}

void func_ov001_02182e58(void) {
    extern M2C_UNK func_ov001_02182e94;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(6);
    func_ov001_02175d54(&func_ov001_02182e94);
}

void func_ov001_02182e94(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern M2C_UNK func_ov001_02182ebc;
    if (func_ov001_021716c4() == -2) return;
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02182ebc);
}

void func_ov001_02182ebc(void) {
 void func_ov001_02182ed0(void);
 void func_ov001_02182f08(void);
 void func_ov001_02182f0c(void);
 func_ov001_02182ed0();
 func_ov001_02182f08();
 func_ov001_02182f0c();
}

void func_ov001_02182ed0(void) {
    if (func_ov001_0218bb00(1) != 0) {
        func_ov001_021716d8(1);
    }
    if (func_ov001_0218bb00(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02182f08(void) {

}

void func_ov001_02182f0c(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern u8 data_ov001_02193de8;
    void func_ov001_02182f5c(void);
    switch (func_ov001_021716c4()) {
    case 0: func_ov001_02185024(7); break;
    case 1:
        func_ov001_02185024(6);
        data_ov001_02193de8 = 1;
        break;
    default: return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182f5c);
}

void func_ov001_02182f5c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02182f7c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02182f7c);
}

void func_ov001_02182f7c(void) {
    M2C_UNK func_ov001_02171694();
    extern u8 data_ov001_02193de8;
    extern M2C_UNK func_ov001_02182fe0;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193de8 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02182fe0);
}

void func_ov001_02182fe0(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193de8;
    extern M2C_UNK func_ov001_02180d44;
    extern M2C_UNK func_ov001_021830b8;
    if (func_ov001_0218a800(0) != 0) return;
    if (data_ov001_02193de8 == 0 && func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_0218af70(0);
    if (data_ov001_02193de8 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193de8 == 0) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(&func_ov001_02180d44);
        return;
    }
    func_ov001_02175d64(2, 1);
    func_ov001_02175d54(&func_ov001_021830b8);
}

s32 func_ov001_02183098(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021830b8(void) {
    M2C_UNK func_02007740(u8 *);
    M2C_UNK func_02007df8(M2C_UNK, u8 *, s32);
    M2C_UNK func_02007e20(u8 *, u8 *, s32);
    M2C_UNK func_ov001_021713c4(M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_02171ecc(u8 *, M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0218314c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02185bf4(M2C_UNK *);
    extern u8 data_ov001_02193dec;
    extern M2C_UNK func_ov001_02183498;
    extern M2C_UNK func_ov001_021831f4;
    u8 sp[0x6C];

    data_ov001_02193dec = 0;
    func_ov001_0218314c();
    func_ov001_02172250(8);
    func_ov001_02171dd0(2);
    func_02007740(&sp[0x16]);
    func_02007df8(0, &sp[0], 0x16);
    func_02007e20(&sp[0x1A], &sp[0], M2C_FIELD(sp, u16 *, 0x30) * 2);
    func_ov001_02171ecc(&sp[0], 0x28);
    func_ov001_021713c4(0);
    func_ov001_02185bf4((M2C_UNK *)&func_ov001_02183498);
    func_ov001_02185024(0xB);
    func_ov001_02175d54(&func_ov001_021831f4);
}

void func_ov001_0218314c(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190b14, data_ov001_02190b2c, data_ov001_02190b44;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190b14, &func_020046cc);
    func_ov001_02171d90(&data_ov001_02190b2c, &func_020040b4);
    func_ov001_02171d90(&data_ov001_02190b44, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_021831f4(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern M2C_UNK func_ov001_02183228;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02183228);
}

void func_ov001_02183228(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    extern M2C_UNK func_ov001_02183254;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(2);
    func_ov001_02175d54(&func_ov001_02183254);
}

void func_ov001_02183254(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern M2C_UNK func_ov001_0218327c;
    if (func_ov001_021716c4() == -2) return;
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0218327c);
}

void func_ov001_0218327c(void) {
    void func_ov001_02183290(void);
    void func_ov001_021832c8(void);
    void func_ov001_021832cc(void);
    func_ov001_02183290();
    func_ov001_021832c8();
    func_ov001_021832cc();
}

void func_ov001_02183290(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_02183098() == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_021832c8(void) {

}

void func_ov001_021832cc(void){void func_ov001_02183318(void);extern u8 data_ov001_02193dec;M2C_UNK func_ov001_0218508c();if(data_ov001_02193dec)return;if(func_ov001_021716c4())return;data_ov001_02193dec=2;func_ov001_0218508c();func_ov001_02185024(7);func_ov001_02175d54((M2C_UNK *)&func_ov001_02183318);}

void func_ov001_02183318(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02183338;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02183338);
}

void func_ov001_02183338(void){extern u8 data_ov001_02193dec;extern M2C_UNK func_ov001_021833a4;M2C_UNK func_ov001_02171694();if(func_ov001_0218a800(1))return;func_ov001_02171694();if((u8)(data_ov001_02193dec+254)<=1)func_ov001_0218a824(3,1,1,8);func_ov001_0218a824(3,0,21,8);func_ov001_02175d54(&func_ov001_021833a4);}

/* Sets up the overlay 001 mode based on the selected slot/state, runs init hooks, then schedules render callbacks. */
void func_ov001_021833a4(void) {
    M2C_UNK func_ov001_02171494(void);
    s32 func_ov001_0217170c(void);
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    void func_ov001_02185dac(void);
    extern u8 data_ov001_02193dec;
    extern void func_ov001_02180d44(void);
    extern void func_ov001_02182d0c(void);
    extern void func_ov001_02182b00(void);

    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if ((data_ov001_02193dec == 2) && (func_ov001_0218a800(1) != 0)) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }
    func_ov001_02185dac();
    func_ov001_02171494();
    func_ov001_0218af70(0);
    if (data_ov001_02193dec == 2 || data_ov001_02193dec == 3) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193dec == 2) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02180d44);
        return;
    }
    if (data_ov001_02193dec == 3) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02182d0c);
        return;
    }
    func_ov001_02175d64(0, 0);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02182b00);
}

M2C_UNK func_ov001_02183498(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218508c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_ov001_02171750();
    void func_ov001_02185e90(s32);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern u8 data_ov001_02193dec;
    void func_ov001_02183584(void);
    void func_ov001_02183318(void);
    void func_ov001_021835d0(void);

    if (data_ov001_02193dec != 0) {
        return arg0;
    }
    switch (arg0) {
    case 0:
        data_ov001_02193dec = 3;
        func_ov001_0218508c();
        func_ov001_02185024(0x12);
        func_ov001_021862d8(0x10, 1, 1, -1, 0);
        func_ov001_02171750();
        return func_ov001_02175d54((M2C_UNK *)&func_ov001_02183584);
    case 1:
        data_ov001_02193dec = 1;
        func_ov001_0218508c();
        return func_ov001_02175d54((M2C_UNK *)&func_ov001_02183318);
    case 2:
        func_ov001_0218508c();
        func_ov001_02185e90(0);
        func_ov001_021862d8(0x11, 0, 1, -1, 0);
        func_ov001_02171750();
        return func_ov001_02175d54((M2C_UNK *)&func_ov001_021835d0);
    case 3:
        data_ov001_02193dec = 2;
        func_ov001_0218508c();
        func_ov001_02185024(9);
        return func_ov001_02175d54((M2C_UNK *)&func_ov001_02183318);
    }
    return arg0;
}

void func_ov001_02183584(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_021835b0;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_021835b0);
}

void func_ov001_021835b0(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02183318);
}

void func_ov001_021835d0(void){void func_ov001_0218362c(void);extern u8 data_ov001_02193dec;switch(func_ov001_02186648()){case 1:data_ov001_02193dec=3;func_ov001_02185024(6);break;case 0:data_ov001_02193dec=1;func_ov001_02185024(7);break;default:return;}func_ov001_02186604();func_ov001_02175d54((M2C_UNK *)&func_ov001_0218362c);}

void func_ov001_0218362c(void) {
    M2C_UNK func_ov001_02171738();
    void func_ov001_02185e90(s32);
    extern u8 data_ov001_02193dec;
    void func_ov001_0218327c(void);
          M2C_UNK func_ov001_02183498(M2C_UNK);
      if (func_ov001_0218665c() != 0) {
        return;
    }
    if (data_ov001_02193dec == 1) {
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02183318);
        return;
    }
    func_ov001_02185024(0xB);
    func_ov001_02171738();
    data_ov001_02193dec = 0;
    func_ov001_02185e90((M2C_UNK)&func_ov001_02183498);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0218327c);
}

void func_ov001_02183694(void *a){extern void *data_ov001_02193df0;void *func_ov001_0218b6f8(s32,s32);void func_02007ef4(void *,void *,s32);s32 func_ov001_0218c884(s32,void (*)(),s32,s32);void func_ov001_02183790(void);void *p=func_ov001_0218b6f8(0x608,4);data_ov001_02193df0=p;func_02007ef4(a,(u8 *)p+4,0x600);M2C_FIELD(data_ov001_02193df0,s32 *,0)=func_ov001_0218c884(1,func_ov001_02183790,0,120);}

void func_ov001_021836f4(void) {
    extern void *data_ov001_02193df0;
    void func_ov001_0218c94c(s32, s32);
    void func_ov001_0218b71c(void *);
    s32 task = M2C_FIELD(data_ov001_02193df0, s32 *, 0);
    func_ov001_0218c94c(1, task);
    func_ov001_0218b71c(&data_ov001_02193df0);
}

void func_ov001_02183720(void) {
    extern void *data_ov001_02193df0;
    M2C_FIELD(data_ov001_02193df0, s8 *, 0x604) = 1;
}

void func_ov001_02183738(void *a,s32 b,s32 c,s32 d){extern void *data_ov001_02193df0;u8 *src=a;u8 *dst=(u8 *)data_ov001_02193df0+4+b*2;s32 i;for(i=0;i<d;i++){func_02007e20(src,dst,c*2);src+=64;dst+=64;}}

void func_ov001_02183790(void){
extern void *data_ov001_02193df0;void func_020067e0();void func_0200448c();
if(!M2C_FIELD(data_ov001_02193df0,u8 *,0x604))return;
func_020067e0((u8 *)data_ov001_02193df0+4,0x600);
func_0200448c((u8 *)data_ov001_02193df0+4,0,0x600);
M2C_FIELD(data_ov001_02193df0,u8 *,0x604)=0;
}

void func_ov001_021837e4(s32 a,s32 b,s32 c){
extern void *data_ov001_02193df0;void func_ov001_02183820();s32 func_ov001_0218c884(s32,void (*)(),s32,s32);
M2C_FIELD(&data_ov001_02193df0,s32 *,4)=a+(b<<5);
M2C_FIELD(&data_ov001_02193df0,s32 *,8)=(c<<5)+0x5000000;
func_ov001_0218c884(1,func_ov001_02183820,0,0x78);
}

void func_ov001_02183820(s32 a){
extern void *data_ov001_02193df0;
func_02007e20(M2C_FIELD(&data_ov001_02193df0,s32 *,4),M2C_FIELD(&data_ov001_02193df0,s32 *,8),32);
func_ov001_0218c92c(1,a);
}

void func_ov001_0218384c(s32 a){
extern void *data_ov001_02193df0;void func_ov001_02183878();s32 func_ov001_0218c884(s32,void (*)(),s32,s32);
M2C_FIELD(&data_ov001_02193df0,s32 *,4)=a;
func_ov001_0218c884(1,func_ov001_02183878,0,0x78);
}

void func_ov001_02183878(s32 a){
extern void *data_ov001_02193df0;
func_02007e20(M2C_FIELD(&data_ov001_02193df0,s32 *,4),0x5000000,0x200);func_ov001_0218c92c(1,a);
}

void func_ov001_021838a8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    extern void *data_ov001_02193dfc;
    extern u8 data_ov001_0218fb58[];
    void *func_ov001_0218b6f8(s32, s32);
    void func_ov001_0218b2bc(s32, s32, void *);
    M2C_UNK func_ov001_0218a61c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0218a384(void *, s32, s32, u8);
    void func_ov001_0218a474(void *, s32, s32);
    s32 func_ov001_0218c884(s32, void (*)(), s32, s32);
    void func_ov001_02183a20(void);

    void *p;
    M2C_UNK t;

    p = func_ov001_0218b6f8(0x20, 0x4);
    data_ov001_02193dfc = p;
    *(u8 *)((char *)p + 0x1b) = (u8)a;
    *(u8 *)((char *)data_ov001_02193dfc + 0x19) = (u8)b;
    *(u8 *)((char *)data_ov001_02193dfc + 0x1a) = (u8)e;
    func_ov001_0218b2bc(c, d, (char *)data_ov001_02193dfc + 0x10);
    t = func_ov001_0218a61c(0, data_ov001_0218fb58[a], 1);
    *(M2C_UNK *)data_ov001_02193dfc = t;
    func_ov001_0218a384(data_ov001_02193dfc, -1, c, (u8)(d + e));
    func_ov001_0218a474(data_ov001_02193dfc, -1, 1);
    *(M2C_UNK *)((char *)data_ov001_02193dfc + 0xc) = func_ov001_0218c884(0, func_ov001_02183a20, 0, 0x80);
}

void func_ov001_02183980(void){
extern void *data_ov001_02193dfc;
func_ov001_0218c94c(0,M2C_FIELD(data_ov001_02193dfc,s32 *,12));
func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193dfc,s32 *,0));
func_ov001_0218b71c(0x02193dfc);
}

u8 func_ov001_021839bc(void) {
    extern void *data_ov001_02193dfc;
    return M2C_FIELD(data_ov001_02193dfc, u8 *, 0x1A);
}

u8 func_ov001_021839d0(void){extern void *data_ov001_02193dfc;return M2C_FIELD(data_ov001_02193dfc,u8 *,29);}

void func_ov001_021839e4(void) {
    M2C_UNK func_ov001_02183f30();
    func_ov001_02183f30();
}

void func_ov001_021839f0(void){extern void *data_ov001_02193dfc;M2C_FIELD(data_ov001_02193dfc,u8 *,30)=0;}

void func_ov001_02183a08(void){extern void *data_ov001_02193dfc;M2C_FIELD(data_ov001_02193dfc,u8 *,30)=1;}

