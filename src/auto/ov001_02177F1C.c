/* 68 functions from 0x02177F1C to 0x02178E80 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02177f1c(s32 arg0) {
    s32 func_020020c4(s32, s32);
    M2C_UNK func_ov001_02185024(s32);
    M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
    extern M2C_UNK data_ov001_0218f77a;
extern M2C_UNK data_ov001_0218f77c;
extern M2C_UNK data_ov001_0218f77e;
extern M2C_UNK data_ov001_0218f780;
    extern M2C_UNK data_ov001_02193d68;
    s32 offset;
    if (arg0 == 1) {
        M2C_FIELD(&data_ov001_02193d68, u8 *, 0) = func_020020c4(M2C_FIELD(&data_ov001_02193d68, u8 *, 0) + 2, 3);
    } else {
        M2C_FIELD(&data_ov001_02193d68, u8 *, 0) = func_020020c4(M2C_FIELD(&data_ov001_02193d68, u8 *, 0) + 1, 3);
    }
    func_ov001_02185024(8);
    offset = M2C_FIELD(&data_ov001_02193d68, u8 *, 0) * 8;
    func_ov001_02172094(M2C_FIELD(&data_ov001_0218f77a,u16 *,offset), M2C_FIELD(&data_ov001_0218f77e,u16 *,offset), M2C_FIELD(&data_ov001_0218f77c,u16 *,offset), M2C_FIELD(&data_ov001_0218f780,u16 *,offset));
}

void func_ov001_02177fac(void) {
    void func_ov001_021837e4(s32,u8,u8);
    extern M2C_UNK data_ov001_0218f72c;
    extern M2C_UNK data_ov001_02193d68;
    u8 value;
    value = M2C_FIELD(&data_ov001_0218f72c, u8 *, M2C_FIELD(&data_ov001_02193d68,u8 *,0));
    func_ov001_021837e4(M2C_FIELD(&data_ov001_02193d68,s32 *,4),value,value);
}

void func_ov001_02177fd8(void) {
    void func_ov001_02178010(void);
    void func_ov001_02178090(void);
    M2C_UNK func_ov001_02171e58(s32);
    M2C_UNK func_ov001_021713c4(s32);
    M2C_UNK func_ov001_0217231c(s32);
    M2C_UNK func_ov001_02185024(s32);
    func_ov001_02178010();
    func_ov001_02171e58(30);
    func_ov001_021713c4(0);
    func_ov001_0217231c(1);
    func_ov001_02185024(11);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178090);
}

void func_ov001_02178010(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190618;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190618, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02178090(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021780c4;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021780c4);
}

void func_ov001_021780c4(void) {
    M2C_UNK func_ov001_021760f0(M2C_UNK *);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_021780f4;
    extern M2C_UNK func_ov001_021781c8;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_021760f0(&func_ov001_021781c8);
    func_ov001_02175d54(&func_ov001_021780f4);
}

void func_ov001_021780f4(void) {
    void func_ov001_02178104(void);
    void func_ov001_02178108(void);
    func_ov001_02178104();
    func_ov001_02178108();
}

void func_ov001_02178104(void) {

}

void func_ov001_02178108(void) {

}

void func_ov001_0217810c(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02178134;
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02178134);
}

void func_ov001_02178134(void) {
    M2C_UNK func_ov001_02171494();
    M2C_UNK func_ov001_021723d4();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    s32 func_ov001_021760d4();
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern s8 data_ov001_02193d74;
    void func_ov001_02178250(void);
    void func_ov001_021789d8(void);
    void func_ov001_02178bc0(void);
    if (func_ov001_0218a800(0) != 0) return;
    if (func_ov001_021760d4() == 0) return;
    func_ov001_021723d4();
    func_ov001_02171494();
    func_ov001_0218af70(0);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(0, 1);
    if ((u8)data_ov001_02193d74 == 0) {
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02178bc0);
        return;
    }
    if ((u8)data_ov001_02193d74 == 2) {
        func_ov001_02175d54((M2C_UNK *)&func_ov001_021789d8);
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178250);
}

void func_ov001_021781c8(s32 arg0) {
    M2C_UNK func_ov001_02176078();
    M2C_UNK func_ov001_02184cac();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    extern s8 data_ov001_02193d74;
    if (arg0 == 2) {
        func_ov001_02184cac();
        data_ov001_02193d74 = 1;
        func_ov001_0218508c();
        func_ov001_02185024(0x10);
    } else if (arg0 == 3) {
        data_ov001_02193d74 = 2;
        func_ov001_0218508c();
        func_ov001_02185024(0x12);
    } else {
        data_ov001_02193d74 = 0;
        func_ov001_0218508c();
        func_ov001_02185024(0x12);
    }
    func_ov001_021760f0(0);
    func_ov001_02176078();
    func_ov001_02175d54(&func_ov001_0217810c);
}

void func_ov001_02178250(void) {
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    void func_ov001_02178270(void);
    extern M2C_UNK func_ov001_021782d8;
    func_ov001_02178270();
    func_ov001_02171e58(0x1F);
    func_ov001_02175d54(&func_ov001_021782d8);
}

void func_ov001_02178270(void) {
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021782d8(void) {
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217830c;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217830c);
}

void func_ov001_0217830c(void) {
    void func_ov001_02178338(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(5);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178338);
}

void func_ov001_02178338(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_02178360;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02178360);
}

void func_ov001_02178360(void) {
    void func_ov001_02178374(void);
    void func_ov001_02178394(void);
    void func_ov001_02178398(void);
    func_ov001_02178374();
    func_ov001_02178394();
    func_ov001_02178398();
}

void func_ov001_02178374(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02178394(void) {

}

void func_ov001_02178398(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_021783c0(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_02185024(6);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021783c0);
}

void func_ov001_021783c0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_021783e0;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_021783e0);
}

void func_ov001_021783e0(void) {
    void func_ov001_0217842c(void);
    if (func_ov001_0218a800(1) != 0) return;
    func_ov001_0218a824(3, 1, 0x3F, 0x40);
    func_ov001_0218a824(3, 0, 0x3F, 0x40);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217842c);
}

void func_ov001_0217842c(void) {
    M2C_UNK func_0200758c(M2C_UNK);
    M2C_UNK func_0200e840();
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_0200758c(0x01000000);
    func_0200e840();
}

void func_ov001_02178460(void) {
    void func_ov001_02178480(void);
    extern M2C_UNK func_ov001_021784e8;
    func_ov001_02178480();
    func_ov001_02171e58(0x1A);
    func_ov001_02175d54(&func_ov001_021784e8);
}

void func_ov001_02178480(void) {
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021784e8(void) {
    extern M2C_UNK func_ov001_0217851c;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217851c);
}

void func_ov001_0217851c(void) {
    void func_ov001_02178558(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(4);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178558);
}

void func_ov001_02178558(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_02178580;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02178580);
}

void func_ov001_02178580(void) {
    void func_ov001_02178594(void);
    void func_ov001_021785b4(void);
    void func_ov001_021785b8(void);
    func_ov001_02178594();
    func_ov001_021785b4();
    func_ov001_021785b8();
}

void func_ov001_02178594(void) {
    if (func_ov001_0218bb00(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_021785b4(void) {

}

void func_ov001_021785b8(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_021785e0(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_02185024(6);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021785e0);
}

void func_ov001_021785e0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02178600;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02178600);
}

void func_ov001_02178600(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK func_ov001_0217863c;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_0217863c);
}

void func_ov001_0217863c(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02179320;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }
    func_ov001_0218af70(0);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(&func_ov001_02179320);
}

void func_ov001_0217868c(void) {
    s8 func_ov001_02171c24(s32, s32, s32);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    void func_ov001_021786d4(void);
    void func_ov001_02178754(void);
    extern u8 data_ov001_02193d78;
    data_ov001_02193d78 = 0;
    func_ov001_021786d4();
    func_ov001_02172250(0x13);
    func_ov001_02171c24(0x3C, -1, 0);
    func_ov001_02171e58(0x1B);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178754);
}

void func_ov001_021786d4(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_0219062c;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_0219062c, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02178754(void) {
    extern M2C_UNK func_ov001_021787a8;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021787a8);
}

void func_ov001_021787a8(void) {
    void func_ov001_021787d4(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(3);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021787d4);
}

void func_ov001_021787d4(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_021787fc;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_021787fc);
}

void func_ov001_021787fc(void) {
    void func_ov001_02178810(void);
    void func_ov001_02178848(void);
    void func_ov001_0217884c(void);
    func_ov001_02178810();
    func_ov001_02178848();
    func_ov001_0217884c();
}

void func_ov001_02178810(void) {
    if (func_ov001_0218bb00(1) != 0) {
        func_ov001_021716d8(1);
    }
    if (func_ov001_0218bb00(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02178848(void) {

}

void func_ov001_0217884c(void) {
    extern u8 data_ov001_02193d78;
    void func_ov001_0217889c(void);
    switch (func_ov001_021716c4()) {
    case 0: func_ov001_02185024(7); break;
    case 1:
        func_ov001_02185024(6);
        data_ov001_02193d78 = 1;
        break;
    default: return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217889c);
}

void func_ov001_0217889c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_021788bc;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_021788bc);
}

void func_ov001_021788bc(void) {
    extern u8 data_ov001_02193d78;
    extern M2C_UNK func_ov001_02178920;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193d78 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02178920);
}

void func_ov001_02178920(void) {
    s32 func_ov001_0217170c();
    extern M2C_UNK func_ov001_021778c0;
    void func_ov001_02178460(void);
    extern u8 data_ov001_02193d78;
    if (func_ov001_0218a800(0) != 0) return;
    if (data_ov001_02193d78 == 0 && func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_0218af70(0);
    if (data_ov001_02193d78 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193d78 == 0) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(&func_ov001_021778c0);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178460);
}

void func_ov001_021789d8(void) {
    void func_ov001_02178a08(void);
    extern s8 data_ov001_02193d7c;
    extern M2C_UNK func_ov001_02178a74;
    data_ov001_02193d7c = 0;
    func_ov001_02178a08();
    func_ov001_02171e58(0x21);
    func_ov001_02175d54(&func_ov001_02178a74);
}

void func_ov001_02178a08(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190640;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190640, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16)((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16)((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16)((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16)((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02178a74(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02178aa8;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02178aa8);
}

void func_ov001_02178aa8(void) {
    s32 func_ov001_021760d4();
    extern M2C_UNK func_ov001_02178ad8;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_021760d4() == 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_02178ad8);
}

void func_ov001_02178ad8(void) {
    void func_ov001_02178b8c(void);
    void func_ov001_02178ae8(void);
    func_ov001_02178b8c();
    func_ov001_02178ae8();
}

void func_ov001_02178ae8(void) {

}

void func_ov001_02178aec(void) {
    extern M2C_UNK func_ov001_02178b28;
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02178b28);
}

void func_ov001_02178b28(void) {
    M2C_UNK func_ov001_02171cf8();
    extern M2C_UNK func_ov001_021778c0;
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
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(&func_ov001_021778c0);
}

void func_ov001_02178b8c(void) {
    extern s8 data_ov001_02193d7c;
    void func_ov001_02178aec(void);
    M2C_FIELD(&data_ov001_02193d7c,u8 *,0) = M2C_FIELD(&data_ov001_02193d7c,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193d7c,u8 *,0) < 120U) return;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178aec);
}

void func_ov001_02178bc0(void) {
    s8 func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02178bfc(void);
    extern s8 data_ov001_02193d80;
    extern M2C_UNK func_ov001_02178c7c;
    func_ov001_02178bfc();
    func_ov001_02171e58(0x20);
    data_ov001_02193d80 = func_ov001_02171c24(0x3C, -1, 0);
    func_ov001_02175d54(&func_ov001_02178c7c);
}

void func_ov001_02178bfc(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190654;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190654, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02178c7c(void) {
    extern s8 data_ov001_02193d80;
    void func_ov001_02178ce4(void);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    if ((u8)data_ov001_02193d80 != 0) {
        func_ov001_0218a824(2, 1, 1, 8);
        func_ov001_0218b314(1, 1);
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178ce4);
}

void func_ov001_02178ce4(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    void func_ov001_02178d20(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(3);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02178d20);
}

void func_ov001_02178d20(void) {
    extern M2C_UNK func_ov001_02178d54;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    if (func_ov001_021760d4() == 0) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02178d54);
}

void func_ov001_02178d54(void) {
    void func_ov001_02178d68(void);
    void func_ov001_02178da0(void);
    void func_ov001_02178da4(void);
    func_ov001_02178d68();
    func_ov001_02178da0();
    func_ov001_02178da4();
}

void func_ov001_02178d68(void) {
    if (func_ov001_0218bb00(1) != 0) {
        func_ov001_021716d8(1);
    }
    if (func_ov001_0218bb00(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02178da0(void) {

}

void func_ov001_02178da4(void) {
    s32 func_ov001_021716c4(void);
    M2C_UNK func_ov001_02185024(s32);
    extern s8 data_ov001_02193d80;
    extern M2C_UNK func_ov001_02178dfc;
    switch (func_ov001_021716c4()) {
    case 1:
        M2C_FIELD(&data_ov001_02193d80, u8 *, 1) = 1;
        func_ov001_02185024(6);
        break;
    case 0:
        M2C_FIELD(&data_ov001_02193d80, u8 *, 1) = 0;
        func_ov001_02185024(7);
        break;
    default:
        return;
    }
    func_ov001_02175d54(&func_ov001_02178dfc);
}

void func_ov001_02178dfc(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02178e1c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02178e1c);
}

void func_ov001_02178e1c(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_02171694(void);
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s8 data_ov001_02193d80;
    extern M2C_UNK func_ov001_02178e80;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (M2C_FIELD(&data_ov001_02193d80, u8 *, 1) == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02178e80);
}

