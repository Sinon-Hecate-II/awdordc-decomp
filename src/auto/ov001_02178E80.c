/* 53 functions from 0x02178E80 to 0x02179E74 (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02178e80(void) {
    s32 func_ov001_0217170c();
    extern M2C_UNK data_ov001_02193d80;
    extern M2C_UNK func_ov001_021778c0;
    extern M2C_UNK func_ov001_02179320;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_0218af70(0);
    if (M2C_FIELD(&data_ov001_02193d80, u8 *, 1) == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (M2C_FIELD(&data_ov001_02193d80, u8 *, 1) == 0) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(&func_ov001_021778c0);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(&func_ov001_02179320);
}

void func_ov001_02178f28(void) {
void *func_ov001_02176114(void);
void func_ov001_02178ff8(void);
void func_ov001_021792ec(void);
void func_ov001_02179078(void);
s32 func_ov001_0218ad0c(s32,s32);
M2C_UNK func_02007df8(s32,void *,s32);
M2C_UNK func_02007e20(void *,void *,s32);
M2C_UNK func_ov001_0218b12c(s32,s32,s32,s32,s32,s32,s32,void *);
extern s8 data_ov001_02193d84;
u8 buf[22];
s32 handle;
void *p;
p=func_ov001_02176114();
handle=func_ov001_0218ad0c(0,0);
M2C_FIELD(&data_ov001_02193d84,u8 *,1)=0;
M2C_FIELD(&data_ov001_02193d84,u8 *,0)=0;
func_ov001_02178ff8();
func_02007df8(0,buf,22);
func_02007e20(p+2,buf,M2C_FIELD(p,u8 *,1)*2);
func_ov001_0218b12c(handle,8,53,240,28,2,0x480,buf);
func_ov001_0218b298(handle);
func_ov001_021760f0(func_ov001_021792ec);
func_ov001_021862d8(29,4,0,-1,0);
func_ov001_02175d54(func_ov001_02179078);
}

void func_ov001_02178ff8(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190668;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_02190668, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02179078(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021790ac;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_021790ac);
}

void func_ov001_021790ac(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_021790d0;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_021790d0);
}

void func_ov001_021790d0(void) {
    s32 func_ov001_02186648();
    void func_ov001_021790f4(void);
    if (func_ov001_02186648() == -2) {
        return;
    }
    func_ov001_02175d54(&func_ov001_021790f4);
}

void func_ov001_021790f4(void) {
    void func_ov001_02179164(void);
    void func_ov001_02179168(void);
    void func_ov001_0217916c(void);
    extern s8 data_ov001_02193d84;
    s32 temp_r0;
    func_ov001_02179164();
    func_ov001_02179168();
    temp_r0 = func_ov001_02186648();
    switch (temp_r0) {
    case 0:
        M2C_FIELD(&data_ov001_02193d84, u8 *, 1) = 0;
        func_ov001_02185024(7);
        break;
    case 1:
        M2C_FIELD(&data_ov001_02193d84, u8 *, 1) = 1;
        func_ov001_02185024(0xE);
        break;
    default: return;
    }
    func_ov001_021760f0(0);
    func_ov001_02186604();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217916c);
}

void func_ov001_02179164(void) {

}

void func_ov001_02179168(void) {

}

void func_ov001_0217916c(void) {
    extern s8 data_ov001_02193d84;
    extern M2C_UNK func_ov001_021791c8;
    if (func_ov001_0218665c() != 0) return;
    if (M2C_FIELD(&data_ov001_02193d84, u8 *, 1) == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_021791c8);
}

void func_ov001_021791c8(void) {
 M2C_UNK func_ov001_02176078();
 M2C_UNK func_ov001_02176108();
 extern s8 data_ov001_02193d84;
 extern M2C_UNK func_ov001_02179224;
 if(func_ov001_0218a800(1)!=0)return;
 if(func_ov001_0218a800(0)!=0)return;
 if(M2C_FIELD(&data_ov001_02193d84,u8 *,0)==0 && M2C_FIELD(&data_ov001_02193d84,u8 *,1)==1) {
 func_ov001_02176108();
 }else {func_ov001_02176078();}
 func_ov001_02175d54(&func_ov001_02179224);
}

void func_ov001_02179224(void) {
s32 func_ov001_021760d4(void);
extern s8 data_ov001_02193d84;
extern M2C_UNK func_ov001_02178bc0, func_ov001_021778c0, func_ov001_02177fd8;
if(M2C_FIELD(&data_ov001_02193d84,u8 *,0) || !M2C_FIELD(&data_ov001_02193d84,u8 *,1))
if(!func_ov001_021760d4())return;
func_ov001_0218af70(0);
func_ov001_0218b368(0,21);
if(!M2C_FIELD(&data_ov001_02193d84,u8 *,1)) {
func_ov001_02171cf8();func_ov001_0218b368(1,1);
}
func_ov001_02175d64(0,1);
if(M2C_FIELD(&data_ov001_02193d84,u8 *,0)) {
func_ov001_02175d54(&func_ov001_02178bc0);return;
}
if(!M2C_FIELD(&data_ov001_02193d84,u8 *,1)) {
func_ov001_0218b368(1,1);
func_ov001_02175d54(&func_ov001_021778c0);return;
}
func_ov001_02175d54(&func_ov001_02177fd8);
}

void func_ov001_021792ec(void) {
    extern s8 data_ov001_02193d84;
    data_ov001_02193d84 = 1;
}

s32 func_ov001_02179300(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02179320(void) {
 M2C_UNK func_ov001_02175f8c(M2C_UNK *);
 M2C_UNK func_ov001_02171e58(M2C_UNK);
 M2C_UNK func_ov001_021713c4(M2C_UNK);
 void func_ov001_0217969c(s32);
 void func_ov001_0217936c(void);
 void func_ov001_021793ec(void);
 extern u8 data_ov001_02193d88;
 func_ov001_02175f8c((M2C_UNK *)&func_ov001_0217969c);
 data_ov001_02193d88=0;
 func_ov001_0217936c();
 func_ov001_02171e58(0x1C);
 func_ov001_021713c4(0);
 func_ov001_02185024(11);
 func_ov001_02175d54((M2C_UNK *)&func_ov001_021793ec);
}

void func_ov001_0217936c(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_0219067c;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_0219067c, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021793ec(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    void func_ov001_02179420(void);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02179420);
}

void func_ov001_02179420(void) {
    void func_ov001_0217944c(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(1);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217944c);
}

void func_ov001_0217944c(void) {
    s32 func_ov001_021716c4();
    extern M2C_UNK func_ov001_02179470;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02175d54(&func_ov001_02179470);
}

void func_ov001_02179470(void) {
 void func_ov001_02179484(void);
 void func_ov001_021794bc(void);
 void func_ov001_021794c0(void);
 func_ov001_02179484();
 func_ov001_021794bc();
 func_ov001_021794c0();
}

void func_ov001_02179484(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_02179300() == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_021794bc(void) {

}

void func_ov001_021794c0(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    extern M2C_UNK func_ov001_021794ec;
    if (func_ov001_021716c4() != 0) {
        return;
    }
    func_ov001_0218508c();
    func_ov001_02185024(7);
    func_ov001_02175d54(&func_ov001_021794ec);
}

void func_ov001_021794ec(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02176078();
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern u8 data_ov001_02193d88;
    extern M2C_UNK func_ov001_02179524;
    if (data_ov001_02193d88 == 0) {
        func_ov001_02176078();
    }
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02179524);
}

void func_ov001_02179524(void) {
    s32 func_ov001_021760d4();
    M2C_UNK func_ov001_02171694();
    extern u8 data_ov001_02193d88;
    extern M2C_UNK func_ov001_021795a4;
    if (func_ov001_0218a800(1) != 0) return;
    if (data_ov001_02193d88 == 0 && func_ov001_021760d4() == 0) return;
    func_ov001_02171694();
    if (data_ov001_02193d88 == 0) func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_021795a4);
}

/* Starts the selected battle mode: validates state, then schedules the
 * appropriate per-mode update callback via the state dispatch. */
void func_ov001_021795a4(void) {
    s32 func_ov001_0217170c(void);
    s32 func_ov001_021760d4(void);
    extern u8 data_ov001_02193d88;
    void func_ov001_021778c0(void);
    void func_ov001_02178bc0(void);
    if (func_ov001_0218a800(0) != 0) return;
    if (data_ov001_02193d88 == 0 && func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    if (data_ov001_02193d88 == 0 && func_ov001_021760d4() == 0) return;
    func_ov001_02171494();
    func_ov001_0218af70(0);
    if (data_ov001_02193d88 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193d88 == 0) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(func_ov001_021778c0);
        return;
    }
    if (data_ov001_02193d88 == 2) {
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(func_ov001_02178bc0);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175d54(func_ov001_02178f28);
}

void func_ov001_0217969c(s32 arg0) {
    extern u8 data_ov001_02193d88;
    void func_ov001_021794ec(void);
    func_ov001_0218508c();
    if (arg0 == 0) {
        data_ov001_02193d88 = 1;
        func_ov001_02185024(0x10);
    } else {
        data_ov001_02193d88 = 2;
        func_ov001_02185024(0x12);
    }
    func_ov001_021760f0(0);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_021794ec);
}

s32 func_ov001_021796f8(void) {
    if (((s32) (*(u16 *)0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02179718(void) {
    extern u8 data_ov001_02193d8c;
    void func_ov001_02179778(void);
    void func_ov001_02179820(void);
    M2C_UNK func_ov001_021722ac();
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171dd0(M2C_UNK);
    M2C_UNK func_ov001_021756c0();
    M2C_FIELD(&data_ov001_02193d8c, u16 *, 2) = 0;
    func_ov001_02179778();
    func_ov001_021722ac();
    func_ov001_02171c24(0x36, -1, 0);
    func_ov001_02171dd0(2);
    func_ov001_02171e58(0x22);
    func_ov001_021713c4(0);
    func_ov001_021756c0();
    func_ov001_02185024(0xB);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02179820);
}

void func_ov001_02179778(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190690, data_ov001_021906a8, data_ov001_021906c0;
    extern M2C_UNK func_020046cc, func_020040b4, func_0200448c;
    func_ov001_02171d90(&data_ov001_02190690, &func_020046cc);
    func_ov001_02171d90(&data_ov001_021906a8, &func_020040b4);
    func_ov001_02171d90(&data_ov001_021906c0, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02179820(void) {
    extern M2C_UNK func_ov001_02179874;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02179874);
}

void func_ov001_02179874(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    void func_ov001_021798b0(void);
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(1);
    func_ov001_02175d54(&func_ov001_021798b0);
}

void func_ov001_021798b0(void) {
    s32 func_ov001_0218c884(s32, void (*)(void), s32, s32);
    void func_ov001_02179bd0(void);
    extern M2C_UNK func_ov001_021798f8;
    extern u8 data_ov001_02193d8c;
    if (func_ov001_021716c4() == -2) return;
    M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) = func_ov001_0218c884(1, &func_ov001_02179bd0, 0, 0x78);
    func_ov001_02175d54(&func_ov001_021798f8);
}

/* Poll a pending online battle connection and, on success, hand off to the appropriate follow-up handler. */
void func_ov001_021798f8(void) {
    void func_ov001_021799cc(void);
    void func_ov001_02179a04(void);
    void func_ov001_02179a08(void);
    s32 func_ov001_02175820(void);
    void func_ov001_02179c38(void);
    void func_ov001_02179bec(void);
    M2C_UNK func_ov001_0218c94c(s32, s32);
    M2C_UNK func_ov001_0218508c(void);
    M2C_UNK func_ov001_021862d8(s32, s32, s32, s32, s32);
    M2C_UNK func_ov001_02185024(s32);
    M2C_UNK func_ov001_02171750(void);
    extern u8 data_ov001_02193d8c;
    s32 pending;
    func_ov001_021799cc();
    func_ov001_02179a04();
    func_ov001_02179a08();
    switch (func_ov001_02175820()) {
    case 0:
        return;
    case 1:
        pending = M2C_FIELD(&data_ov001_02193d8c, s32 *, 4);
        if (!pending) return;
        M2C_FIELD(&data_ov001_02193d8c, u8 *, 0) = 1;
        func_ov001_0218c94c(1, pending);
        M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) = 0;
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02179c38);
        return;
    case 2:
        pending = M2C_FIELD(&data_ov001_02193d8c, s32 *, 4);
        if (!M2C_FIELD(&data_ov001_02193d8c, s32 *, 4)) return;
        func_ov001_0218508c();
        func_ov001_021862d8(12, 1, 1, -1, 0);
        func_ov001_02185024(9);
        func_ov001_02171750();
        func_ov001_0218c94c(1, M2C_FIELD(&data_ov001_02193d8c, s32 *, 4));
        M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) = 0;
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02179bec);
        return;
    }
}

void func_ov001_021799cc(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (func_ov001_021796f8() == 0) return;
    func_ov001_021716d8(0);
}

void func_ov001_02179a04(void) {

}

void func_ov001_02179a08(void) {
    extern u8 data_ov001_02193d8c;
    extern M2C_UNK func_ov001_02179c84;
    if (func_ov001_021716c4() != 0) return;
    if (M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) == 0) return;
    func_ov001_0218c92c(1, M2C_FIELD(&data_ov001_02193d8c, s32 *, 4));
    M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) = 0;
    func_ov001_02171750();
    func_ov001_02175d54(&func_ov001_02179c84);
}

void func_ov001_02179a54(void) {
    extern u8 data_ov001_02193d8c;
    void func_ov001_02179a90(void);
    func_ov001_02171750();
    if (M2C_FIELD(&data_ov001_02193d8c, s32 *, 4) != 0) {
        func_ov001_0218c94c(1, M2C_FIELD(&data_ov001_02193d8c, s32 *, 4));
    }
    func_ov001_0218aa24(8);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02179a90);
}

void func_ov001_02179a90(void) {
    M2C_UNK func_ov001_02171694();
    extern u8 data_ov001_02193d8c;
    extern M2C_UNK func_ov001_02179af4;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193d8c == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02179af4);
}

void func_ov001_02179af4(void) {
    extern u8 data_ov001_02193d8c;
    extern void func_ov001_02181a84(void);
    extern void func_ov001_02179cb4(void);

    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (data_ov001_02193d8c == 0 && func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }

    func_ov001_021757d0(data_ov001_02193d8c != 0);
    func_ov001_02171494();
    func_ov001_0218af70(0);

    if (data_ov001_02193d8c == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);

    if (data_ov001_02193d8c == 0) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(func_ov001_02181a84);
    } else {
        func_ov001_02175d64(0, 0);
        func_ov001_02175d54(func_ov001_02179cb4);
    }
}

void func_ov001_02179bd0(void) {
    void func_ov001_021799cc(void);
    void func_ov001_02179a08(void);
    M2C_UNK func_ov001_0218b850();
    M2C_UNK func_ov001_0218c7d4(M2C_UNK);
    func_ov001_0218b850();
    func_ov001_0218c7d4(0);
    func_ov001_021799cc();
    func_ov001_02179a08();
}

void func_ov001_02179bec(void) {
    M2C_UNK func_ov001_02185024(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_02179c18;
    if (func_ov001_02186648() != 0) {
        return;
    }
    func_ov001_02185024(6);
    func_ov001_02186604();
    func_ov001_02175d54(&func_ov001_02179c18);
}

void func_ov001_02179c18(void) {
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    s32 func_ov001_0218665c();
    void func_ov001_02179a54(void);
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179c38(void) {
extern u8 data_ov001_02193d8c;
u8 *p;
func_ov001_021799cc();
func_ov001_02179a04();
func_ov001_02179a08();
p=&data_ov001_02193d8c;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,2)+1;
if(M2C_FIELD(p,u16 *,2)<0x438U) return;
func_ov001_0218508c();
func_ov001_02175d54((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179c84(void) {
extern u8 data_ov001_02193d8c;
func_ov001_0218508c();
func_ov001_02185024(7);
data_ov001_02193d8c=0;
func_ov001_02175d54((M2C_UNK *)&func_ov001_02179a54);
}

void func_ov001_02179cb4(void) {
extern u8 data_ov001_02193d94;
void func_ov001_02179cf0(void);
void func_ov001_02179d5c(void);
data_ov001_02193d94=0;
func_ov001_02179cf0();
func_ov001_021722ac();
func_ov001_02171e58(0x23);
func_ov001_02185024(0x10);
func_ov001_02175d54((M2C_UNK *)&func_ov001_02179d5c);
}

void func_ov001_02179cf0(void) {
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_021906d4;
    extern M2C_UNK func_0200448c;
    func_ov001_02171d90(&data_ov001_021906d4, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_02179d5c(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02179d90;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02179d90);
}

void func_ov001_02179d90(void) {
    extern M2C_UNK func_ov001_02179db4;
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_02179db4);
}

void func_ov001_02179db4(void) {
 void func_ov001_02179e74(void);
 void func_ov001_02179dc4(void);
 func_ov001_02179e74();
 func_ov001_02179dc4();
}

void func_ov001_02179dc4(void) {

}

void func_ov001_02179dc8(void) {
    extern M2C_UNK func_ov001_02179e04;
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_02179e04);
}

void func_ov001_02179e04(void) {
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

