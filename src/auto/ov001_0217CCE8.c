/* 23 functions from 0x0217CCE8 to 0x0217DC7C (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02193dac;
extern const u8 data_ov001_0218f9bc[];
void func_ov001_0217f6cc(void);
void func_ov001_0217ded8(void);
void func_ov001_0217dbd8(s32);
void func_ov001_0217dc44(s32);

void *func_ov001_0218445c();

void func_ov001_0217d044(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217d078;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_0217d078);
}

void func_ov001_0217d078(void) {
    void func_ov001_0217d0b4(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(4);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217d0b4);
}

void func_ov001_0217d0b4(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    void func_ov001_0217d0dc(void);
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0217d0dc);
}

void func_ov001_0217d0dc(void) {
    void func_ov001_0217d0f0(void);
    void func_ov001_0217d110(void);
    void func_ov001_0217d114(void);
    func_ov001_0217d0f0();
    func_ov001_0217d110();
    func_ov001_0217d114();
}

void func_ov001_0217d0f0(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 func_ov001_0218bb00(M2C_UNK);
    if (func_ov001_0218bb00(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_0217d110(void) {

}

void func_ov001_0217d114(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_0217d13c(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_02185024(6);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217d13c);
}

void func_ov001_0217d13c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217d15c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217d15c);
}

void func_ov001_0217d15c(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK func_ov001_0217d1ac;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    func_ov001_02175d54(&func_ov001_0217d1ac);
}

void func_ov001_0217d1ac(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0217f72c(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217d270;
    extern M2C_UNK func_ov001_02180d44;
    s32 sp0;

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
    func_ov001_02175db4(0, &sp0);
    if (sp0 != 0) {
        func_ov001_02175d64(2, 1);
        func_ov001_02175d54(&func_ov001_02180d44);
        return;
    }
    func_ov001_02175d64(2, 0);
    func_ov001_02175da0(0, 0);
    func_ov001_0217f72c(0);
    func_ov001_02175d54(&func_ov001_0217d270);
}

void func_ov001_0217d260(s32 arg0) {
    extern s32 data_ov001_02193da8;
    data_ov001_02193da8 = arg0;
}

void func_ov001_0217d680(void) {
    M2C_UNK func_ov001_02175db4(M2C_UNK, s32 *);
    void *func_ov001_0218445c();
    extern M2C_UNK data_ov001_02193dac;
    s32 sp0;

    func_ov001_0218445c();
    func_ov001_02175db4(0, &sp0);
    if (sp0 != 0) {
        return;
    }
    M2C_FIELD(&data_ov001_02193dac, s16 *, 4) = 0;
    M2C_FIELD(&data_ov001_02193dac, s8 *, 0) = 0;
    M2C_FIELD(&data_ov001_02193dac, s8 *, 2) = 0;
}

void func_ov001_0217d6bc(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217d710(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x1D, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x1D);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217d710);
}

void func_ov001_0217d710(void) {
    extern M2C_UNK func_ov001_0217d744;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02175d54(&func_ov001_0217d744);
}

void func_ov001_0217d744(void) {
    M2C_UNK func_ov001_0217dc7c();
    M2C_UNK func_ov001_0217d754();
    func_ov001_0217d754();
    func_ov001_0217dc7c();
}

s32 func_ov001_0217d9d4(void) {
    M2C_UNK func_ov001_0217da58(u32);
    s32 func_ov001_0217e5e8();
    u32 func_ov001_0217eb6c();
    M2C_UNK func_ov001_0217f1c0(u32);
    M2C_UNK func_ov001_0217f568();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    u32 temp_r0;

    func_ov001_0218445c();
    temp_r0 = func_ov001_0217eb6c();
    if (temp_r0 == 0xE) {
        return 0;
    }
    if (func_ov001_0217e5e8() == 0) {
        func_ov001_02185024(9);
        return 1;
    }
    func_ov001_0217f1c0(temp_r0);
    switch (temp_r0) {
    default:
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        func_ov001_0217f568();
        break;
    }
    func_ov001_0217da58(temp_r0);
    return 1;
}

/* Dispatch a screen selection (0..13): set up UI state, graphics, and continue via func_ov001_0217ded8. */
s32 func_ov001_0217da58(u32 a){
if(func_ov001_0217e5e8()==0){func_ov001_02185024(9);return;}
switch(a){
case 2:case 3:func_ov001_02185024(6);func_ov001_0217dbd8(((a-2)^1)!=0);return;
case 7:case 8:func_ov001_02185024(6);func_ov001_0217dc44(((a-7)^1)!=0);return;
case 0:case 1:case 4:case 5:case 6:break;
}
M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),u8 *,64)=a;
if(a-11<=1){
func_ov001_0217f4e0();
if(func_ov001_0217f62c()==0){
func_ov001_02185024(9);func_ov001_021862d8(6,1,1,-1,0);func_ov001_02175d54((M2C_UNK *)func_ov001_0217f6cc);return;
}
if(a==11)func_ov001_02185024(6);else func_ov001_02185024(14);
}else if(a==13){func_ov001_0217f4e0();func_ov001_02185024(7);}
else {func_ov001_02185024(6);func_ov001_0217e67c(0,1,func_ov001_0217ede0(data_ov001_0218f9bc[a]));func_ov001_0217e95c();}
func_ov001_02183a08();func_ov001_02175d54((M2C_UNK *)func_ov001_0217ded8);
}

void func_ov001_0217dbd8(s32 arg0) {
    M2C_UNK func_ov001_0217e238();
    M2C_UNK func_ov001_02184470(s32);
    M2C_UNK func_ov001_02184484(s32);
    extern M2C_UNK data_ov001_02193dac;
    s32 var_r5;
    void *temp_r0;
    temp_r0 = func_ov001_0218445c();
    if (M2C_FIELD(temp_r0, u8 *, 0xF5) == arg0) return;
    if (arg0 != 0) {
        var_r5 = M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), u8 *, 0x43) != 0;
    } else {
        var_r5 = 0;
        M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), u8 *, 0x43) = M2C_FIELD(temp_r0, u8 *, 0xF6);
    }
    func_ov001_02184470(arg0);
    func_ov001_02184484(var_r5);
    func_ov001_0217e238();
}

void func_ov001_0217dc44(s32 arg0) {
    M2C_UNK func_ov001_0217e238();
    M2C_UNK func_ov001_02184484(s32);
    extern M2C_UNK data_ov001_02193dac;
    s32 current;
    current = M2C_FIELD(func_ov001_0218445c(), u8 *, 0xF6);
    if (current == arg0) return;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), u8 *, 0x43) = arg0;
    func_ov001_02184484(arg0);
    func_ov001_0217e238();
}

