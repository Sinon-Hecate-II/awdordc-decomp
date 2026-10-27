/* 48 functions from 0x02176F4C to 0x02177F1C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02176f4c(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    void func_ov001_02176f88(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(3);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02176f88);
}

void func_ov001_02176f88(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    void func_ov001_02176fb0(void);
    if (func_ov001_021716c4() == -2) return;
    func_ov001_02171738();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02176fb0);
}

void func_ov001_02176fb0(void) {
    void func_ov001_02176fc4(void);
    void func_ov001_02176ffc(void);
    void func_ov001_02177000(void);
    func_ov001_02176fc4();
    func_ov001_02176ffc();
    func_ov001_02177000();
}

void func_ov001_02176fc4(void) {
    if (func_ov001_0218bb00(1) != 0) {
        func_ov001_021716d8(1);
    }
    if (func_ov001_0218bb00(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02176ffc(void) {

}

void func_ov001_02177000(void) {
    void func_ov001_02177068(void);
    void func_ov001_021771a4(void);
    s32 temp_r0;
    temp_r0 = func_ov001_021716c4();
    switch (temp_r0) {
    case 0:
        func_ov001_02185024(7);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02177068);
        return;
    case 1:
        func_ov001_02185024(6);
        func_ov001_021862d8(0x18, 0, 1, -1, 0);
        func_ov001_02171750();
        func_ov001_02175d54((M2C_UNK *)&func_ov001_021771a4);
        return;
    }
}

void func_ov001_02177068(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177088;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02177088);
}

void func_ov001_02177088(void) {
    extern u8 data_ov001_02193d64;
    extern M2C_UNK func_ov001_021770ec;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193d64 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_021770ec);
}

void func_ov001_021770ec(void) {
    s32 func_ov001_0217170c();
    extern M2C_UNK func_ov001_021778c0;
    void func_ov001_02177214(void);
    extern u8 data_ov001_02193d64;
    if (func_ov001_0218a800(0) != 0) return;
    if (data_ov001_02193d64 == 0 && func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_0218af70(0);
    if (data_ov001_02193d64 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193d64 == 0) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(&func_ov001_021778c0);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02177214);
}

void func_ov001_021771a4(void) {
    void func_ov001_021771f4(void);
    extern u8 data_ov001_02193d64;
    s32 temp_r0;
    temp_r0 = func_ov001_02186648();
    switch (temp_r0) {
    case 1:
        func_ov001_02185024(0xE);
        data_ov001_02193d64 = 1;
        break;
    case 0:
        func_ov001_02185024(7);
        break;
    default: return;
    }
    func_ov001_02186604();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021771f4);
}

void func_ov001_021771f4(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02177068);
}

void func_ov001_02177214(void) {
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    void func_ov001_02177238(void);
    M2C_UNK func_ov001_02184cac();
    extern M2C_UNK func_ov001_021772b8;
    func_ov001_02177238();
    func_ov001_02171e58(0x19);
    func_ov001_02184cac();
    func_ov001_02175d54(&func_ov001_021772b8);
}

void func_ov001_02177238(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190534;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190534, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021772b8(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021772ec;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021772ec);
}

void func_ov001_021772ec(void) {
    void func_ov001_02177318(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(5);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02177318);
}

void func_ov001_02177318(void) {
    extern M2C_UNK func_ov001_02177340;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02177340);
}

void func_ov001_02177340(void) {
    void func_ov001_02177354(void);
    void func_ov001_02177374(void);
    void func_ov001_02177378(void);
    func_ov001_02177354();
    func_ov001_02177374();
    func_ov001_02177378();
}

void func_ov001_02177354(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02177374(void) {

}

void func_ov001_02177378(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_021773a0(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_02185024(6);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021773a0);
}

void func_ov001_021773a0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_021773c0;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_021773c0);
}

void func_ov001_021773c0(void) {
    void func_ov001_0217740c(void);
    if (func_ov001_0218a800(1) != 0) return;
    func_ov001_0218a824(3, 1, 0x3F, 0x40);
    func_ov001_0218a824(3, 0, 0x3F, 0x40);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217740c);
}

void func_ov001_0217740c(void) {
    M2C_UNK func_0200758c(M2C_UNK);
    M2C_UNK func_0200e840();
    s32 func_ov001_0218a800(M2C_UNK);
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_0200758c(0x01000000);
    func_0200e840();
}

void func_ov001_02177440(void) {
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    void func_ov001_02177474(void);
    M2C_UNK func_ov001_021774f4();
    extern M2C_UNK func_ov001_021776c8;
    func_ov001_02177474();
    func_ov001_02172250(0x11);
    func_ov001_02171c24(0x3A, -1, 0);
    func_ov001_021774f4();
    func_ov001_02175d54(&func_ov001_021776c8);
}

void func_ov001_02177474(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190548;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190548, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021776c8(void) {
    extern M2C_UNK func_ov001_0217771c;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217771c);
}

void func_ov001_0217771c(void) {
    void func_ov001_02177758(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(2);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02177758);
}

void func_ov001_02177758(void) {
    extern M2C_UNK func_ov001_02177780;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02177780);
}

void func_ov001_02177780(void) {
    void func_ov001_02177794(void);
    void func_ov001_021777b4(void);
    void func_ov001_021777b8(void);
    func_ov001_02177794();
    func_ov001_021777b4();
    func_ov001_021777b8();
}

void func_ov001_02177794(void) {
    if (func_ov001_0218bb00(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_021777b4(void) {

}

void func_ov001_021777b8(void) {
    void func_ov001_021777e0(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_02185024(7);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021777e0);
}

void func_ov001_021777e0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177800;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02177800);
}

void func_ov001_02177800(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK func_ov001_02177850;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02177850);
}

void func_ov001_02177850(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021778c0;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(&func_ov001_021778c0);
}

void func_ov001_021778c0(void) {
extern M2C_UNK data_ov001_02193d68;
extern M2C_UNK data_ov001_0218f77a,data_ov001_0218f77e,data_ov001_0218f77c,data_ov001_0218f780;
void func_ov001_02177988(void);
void func_ov001_02177b24(void);
void *func_ov001_0218a5f0(s32,s32);
M2C_UNK func_ov001_02172250(s32);
M2C_UNK func_ov001_02185b60(s32);
M2C_UNK func_ov001_02171c24(s32,s32,s32);
M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
void *p; s32 offset;
M2C_FIELD(&data_ov001_02193d68,u8 *,1)=0;
func_ov001_02177988();
func_ov001_02172250(16);
func_ov001_02185b60(3);
func_ov001_02171c24(0x39,-1,0);
p=func_ov001_0218a5f0(0,0x5b);
M2C_FIELD(&data_ov001_02193d68,void **,8)=p;
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|0x84|0xe00000;
p=M2C_FIELD(&data_ov001_02193d68,void **,8);
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xc00)|0xc00;
offset=M2C_FIELD(&data_ov001_02193d68,u8 *,0)*8;
func_ov001_02172094(M2C_FIELD(&data_ov001_0218f77a,u16 *,offset),M2C_FIELD(&data_ov001_0218f77e,u16 *,offset),M2C_FIELD(&data_ov001_0218f77c,u16 *,offset),M2C_FIELD(&data_ov001_0218f780,u16 *,offset));
func_ov001_02175d54((M2C_UNK *)&func_ov001_02177b24);
}

void func_ov001_02177b24(void) {
    extern M2C_UNK func_ov001_02177b78;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    func_ov001_02175d54(&func_ov001_02177b78);
}

void func_ov001_02177b78(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02177bb4;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    func_ov001_02175d54(&func_ov001_02177bb4);
}

void func_ov001_02177bb4(void) {
    extern M2C_UNK func_ov001_02177bdc;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02177bdc);
}

void func_ov001_02177bdc(void) {
    void func_ov001_02177bf0(void);
    void func_ov001_02177ce4(void);
    void func_ov001_02177ce8(void);
    func_ov001_02177bf0();
    func_ov001_02177ce4();
    func_ov001_02177ce8();
}

void func_ov001_02177bf0(void) {
    s32 func_ov001_0218bbd8(void *);
    s32 func_ov001_0218bb24(s32);
    void func_ov001_02177f1c(s32);
    M2C_UNK func_ov001_02172094(u16, u16, u16, u16);
    extern u8 data_ov001_0218f762[];
    extern M2C_UNK data_ov001_0218f77a;
    extern M2C_UNK data_ov001_0218f77e;
    extern M2C_UNK data_ov001_0218f77c;
    extern M2C_UNK data_ov001_0218f780;
    extern M2C_UNK data_ov001_02193d68;
    s32 var_r4;
    u8 *var_r5;
    s32 offset;
    var_r5 = data_ov001_0218f762;
    for (var_r4 = 0; (u32)var_r4 < 3; var_r4++, var_r5 += 8) {
        if (func_ov001_0218bbd8(var_r5) != 0) {
            func_ov001_021716d8(1);
            offset = (u8)var_r4 * 8;
            M2C_FIELD(&data_ov001_02193d68, u8 *, 0) = var_r4;
            func_ov001_02172094(M2C_FIELD(&data_ov001_0218f77a,u16 *,offset), M2C_FIELD(&data_ov001_0218f77e,u16 *,offset), M2C_FIELD(&data_ov001_0218f77c,u16 *,offset), M2C_FIELD(&data_ov001_0218f780,u16 *,offset));
            return;
        }
    }
    if (func_ov001_0218bb00(1) != 0) {
        func_ov001_021716d8(1);
        return;
    }
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_0218bb24(0x40) != 0) {
        func_ov001_02177f1c(1);
        return;
    }
    if (func_ov001_0218bb24(0x80) == 0) return;
    func_ov001_02177f1c(3);
}

void func_ov001_02177ce4(void) {

}

void func_ov001_02177ce8(void) {
    M2C_UNK func_02045cbc(void *);
    M2C_UNK func_ov001_021716f8(M2C_UNK);
    M2C_UNK func_ov001_02177fac();
    void func_ov001_02177d8c(void);
    extern M2C_UNK data_ov001_02193d68;
    struct { u64 value; u32 unk_08[3]; } sp0;
    switch (func_ov001_021716c4()) {
    case 0:
        func_ov001_02185024(7);
        break;
    case 1:
        func_02045cbc(&sp0);
        if (M2C_FIELD(&data_ov001_02193d68, u8 *, 0) != 0) {
            if (sp0.value == 0) {
                func_ov001_02185024(9);
                func_ov001_021716f8(-1);
                return;
            }
        }
        func_ov001_02185024(6);
        func_ov001_02177fac();
        M2C_FIELD(&data_ov001_02193d68, u8 *, 1) = 1;
        break;
    default:
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02177d8c);
}

void func_ov001_02177d8c(void) {
    extern M2C_UNK func_ov001_02177dac;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02177dac);
}

void func_ov001_02177dac(void) {
    extern M2C_UNK data_ov001_02193d68;
    extern M2C_UNK func_ov001_02177e10;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(&data_ov001_02193d68, u8 *, 1) != 0) {
        func_ov001_02171694();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x14, 8);
    func_ov001_02175d54(&func_ov001_02177e10);
}

void func_ov001_02177e10(void) {
extern M2C_UNK data_ov001_02193d68;
void func_ov001_021768b8(void);void func_ov001_02177440(void);void func_ov001_02176e30(void);void func_ov001_0217868c(void);
s32 func_ov001_0218a800(M2C_UNK);
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_0217170c())return;
func_ov001_0218c104(M2C_FIELD(&data_ov001_02193d68,void **,8));
func_ov001_02172184();func_ov001_02171cf8();
func_ov001_02189ebc(M2C_FIELD(&data_ov001_02193d68,void **,4));
func_ov001_0218b368(1,1);func_ov001_0218b368(0,20);
if(!M2C_FIELD(&data_ov001_02193d68,u8 *,1)){func_ov001_02175d64(0,0);func_ov001_02175d54((M2C_UNK *)&func_ov001_021768b8);return;}
switch(M2C_FIELD(&data_ov001_02193d68,u8 *,0)){
case 0:func_ov001_02175d64(0,1);func_ov001_02175d54((M2C_UNK *)&func_ov001_02177440);return;
case 1:func_ov001_02175d64(0,1);func_ov001_02175d54((M2C_UNK *)&func_ov001_02176e30);return;
case 2:func_ov001_02175d64(0,1);func_ov001_02175d54((M2C_UNK *)&func_ov001_0217868c);return;
}
}

