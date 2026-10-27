/* 38 functions from 0x02175F60 to 0x02176F4C (ov001), found by ds-decomp. */
#include "common.h"

struct MenuValues2 { u8 values[2]; };
extern struct MenuValues2 data_ov001_0218f6f4;

void func_ov001_02175f60(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 *offsets = M2C_FIELD(arg0, u32 **, 0);
    u8 *base = M2C_FIELD(arg0, u8 **, 4);
    u16 *ptr = (u16 *)(base + offsets[(u16)arg1]);
    if (arg2 >= 0) {
        ptr[arg2] = arg3 + '0';
    }
}

void func_ov001_02175f8c(void *arg0) {
    s32 func_ov001_0218b6f8(s32, s32);
    s32 func_ov001_02175f48(M2C_UNK, u32);
    s32 func_ov001_02175e34(void);
    void func_ov001_02188c78(M2C_UNK, void *);
    s32 func_ov001_02188ec4(void);
    void func_02007958(void);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193d50;
    extern u8 data_ov001_0219031c[28];
    extern M2C_UNK data_ov001_02193d58;
    extern void func_ov001_0217612c(void);
    typedef struct { u32 a, b, c, d, e, f; u8 g; u8 pad[3]; } Buf28;
    Buf28 buf;
    data_ov001_02193d50 = (void *)func_ov001_0218b6f8(0x1E2A4, 0x20);
    M2C_FIELD(data_ov001_02193d50, M2C_UNK *, 0x1E298) = (M2C_UNK)arg0;
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A0) = (u8)0;
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A1) = (u8)0;
    buf = *(Buf28 *)data_ov001_0219031c;
    buf.b = func_ov001_02175f48(data_ov001_02193d58, 0);
    buf.c = func_ov001_02175f48(data_ov001_02193d58, 1);
    buf.g = (u8)func_ov001_02175e34();
    func_ov001_02188c78(data_ov001_02193d50, &buf);
    if (func_ov001_02188ec4() == 0) {
        func_02007958();
        M2C_FIELD(data_ov001_02193d50, M2C_UNK *, 0x1E29C) = func_ov001_0218c884((s32)0, (M2C_UNK *)&func_ov001_0217612c, 0, 0x78);
    }
}

void func_ov001_02176078(void) {
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02176098;
    func_ov001_0218c884(0, &func_ov001_02176098, 0, 0x78);
}

void func_ov001_02176098(M2C_UNK arg0) {
    s32 func_ov001_02188d68();
    M2C_UNK func_ov001_0218c92c(M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193d50;
    if (func_ov001_02188d68() == 0) {
        return;
    }
    M2C_FIELD(data_ov001_02193d50, u8 *, 0x1E2A1) = 1;
    func_ov001_0218c92c(0, arg0);
}

s32 func_ov001_021760d4(void) {
    extern void *data_ov001_02193d50;
    return data_ov001_02193d50 == 0;
}

void func_ov001_021760f0(s32 arg0) {
    extern void *data_ov001_02193d50;
    M2C_FIELD(data_ov001_02193d50, s32 *, 0x1E298) = arg0;
}

void func_ov001_02176108(void) {
    M2C_UNK func_ov001_02188f0c();
    func_ov001_02188f0c();
}

void *func_ov001_02176114(void) {
    extern void *data_ov001_02193d50;
    return (u8 *)data_ov001_02193d50 + 0x1E280;
}

void func_ov001_021763cc(void) {
    s32 func_ov001_0218b6f8(s32, s32);
    s32 func_ov001_021711e0(s32, s32, void *, void *, void *, s32);
    void func_ov001_02176544(void *);
    void func_ov001_0217655c(s32);
    void func_ov001_0217656c(void);
    extern M2C_UNK data_ov001_02193d54;
    data_ov001_02193d54 = func_ov001_0218b6f8(0xC, -4);
    if (func_ov001_021711e0(0xF, 0x40, func_ov001_02176544, func_ov001_0217655c, func_ov001_0217656c, 0x800) != 1) {
        func_02007958();
    }
    func_02006030(0xA);
}

void func_ov001_02176438(void) {
    M2C_UNK func_02007958();
    s32 func_ov001_021712c8();
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK data_ov001_02193d54;
    if (func_ov001_021712c8() != 1) {
        func_02007958();
    }
    func_ov001_0218b71c(&data_ov001_02193d54);
}

s32 func_ov001_0217645c(s32 arg0) {
    s32 func_ov001_02171394(void *);
    extern M2C_UNK data_ov001_02193d54;
    s32 state[58];
    switch (*(u32 *)data_ov001_02193d54) {
    case 0:
    case 1:
    case 3:
    case 5: return 0;
    case 2: return 1;
    case 4: return 2;
    case 6:
        if (func_ov001_02171394(state) != 1) func_02007958();
        if (state[8] >= 0 && state[8] <= 3 && state[9] == 1) return 3;
        return 5;
    case 7: return 4;
    }
    return arg0;
}

void func_ov001_02176518(void) {
 s32 func_ov001_02171394(void *);
 M2C_UNK func_ov001_02184a3c(void *);
 s32 state[58];
 if(func_ov001_02171394(state) != 1) func_02007958();
 func_ov001_02184a3c(state);
}

void func_ov001_02176544(void *arg0) {
 typedef struct { s32 values[3]; } State;
 extern M2C_UNK data_ov001_02193d54;
 *(State *)data_ov001_02193d54 = *(State *)arg0;
}

void func_ov001_0217655c(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    func_ov001_0218b6f8(arg0, 0x20);
}

void func_ov001_0217656c(void) {
    M2C_UNK func_ov001_0218b760();
    func_ov001_0218b760();
}

void func_ov001_02176578(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021765b4;
    func_ov001_0218a824(3, 1, 0x3F, 0x14);
    func_ov001_0218a824(3, 0, 0x3F, 0x14);
    func_ov001_02175d54(&func_ov001_021765b4);
}

void func_ov001_021765b4(void) {
    M2C_UNK func_ov001_02171fc0();
    M2C_UNK func_ov001_0217223c();
    M2C_UNK func_ov001_02175e20();
    M2C_UNK func_ov001_02175eb0();
    M2C_UNK func_ov001_02175f1c(s32);
    M2C_UNK func_ov001_02184448();
    M2C_UNK func_ov001_0218a534(M2C_UNK);
    M2C_UNK func_ov001_0218c99c(M2C_UNK, M2C_UNK);
    extern s32 data_ov001_02193d58;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_0218c99c(0, 0);
    func_ov001_0218c99c(1, 0);
    func_ov001_0218a534(1);
    func_ov001_0218a534(0);
    func_ov001_0217223c();
    func_ov001_02171fc0();
    func_ov001_02175f1c(data_ov001_02193d58);
    func_ov001_02175eb0();
    func_ov001_02184448();
    func_ov001_02175e20();
}

void func_ov001_02176808(void) {
    extern M2C_UNK func_ov001_02176844;
    func_ov001_0218a824(2, 1, 2, 0x14);
    func_ov001_0218a824(2, 0, 2, 0x14);
    func_ov001_02175d54(&func_ov001_02176844);
}

void func_ov001_02176844(void) {
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    s32 func_ov001_02175dec();
    extern M2C_UNK func_ov001_021768b8;
    extern M2C_UNK func_ov001_02180d44;
    s32 temp_r0;

    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    temp_r0 = func_ov001_02175dec();
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov001_02175d64(0, 1);
        func_ov001_02175d54(&func_ov001_021768b8);
        return;
    case 1:
        func_ov001_02175d64(1, 1);
        func_ov001_02175d54(&func_ov001_02180d44);
        return;
    }
}

void func_ov001_021768b8(void) {
 void func_ov001_02176934(void);
 M2C_UNK func_ov001_02172250(M2C_UNK);
 M2C_UNK func_ov001_02171c24(M2C_UNK,M2C_UNK,M2C_UNK);
 M2C_UNK func_ov001_02185b60(M2C_UNK);
 M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
 void func_ov001_02176a20(void);
 extern u8 data_ov001_02193d5c;
   extern u16 data_ov001_0218f706, data_ov001_0218f708, data_ov001_0218f70a, data_ov001_0218f70c;
 s32 offset;
 func_ov001_02176934();
 func_ov001_02172250(0);
 func_ov001_02171c24(0x2e,-1,0);
 func_ov001_02185b60(4);
 offset = data_ov001_02193d5c * 8;
 func_ov001_02172094(M2C_FIELD(&data_ov001_0218f706,u16 *,offset),M2C_FIELD(&data_ov001_0218f70a,u16 *,offset),M2C_FIELD(&data_ov001_0218f708,u16 *,offset),M2C_FIELD(&data_ov001_0218f70c,u16 *,offset));
 func_ov001_02175d54((M2C_UNK *)&func_ov001_02176a20);
}

/* Loads the step-screen background NCL file and registers its rendering callbacks, then selects VRAM banks 3 for the displays. */
void func_ov001_02176934(void) {
    s32 func_ov001_02171d30(void *);
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    s32 func_ov001_02189dc8(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_0218f716;
    extern M2C_UNK data_ov001_021904dc;
    extern M2C_UNK data_ov001_021904f4;
    extern M2C_UNK data_ov001_0219050c;
    extern M2C_UNK func_020040b4;
    extern u8 data_ov001_02193d5c;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    typedef struct { u8 bytes[22]; } Text;
    Text text = *(Text *)&data_ov001_0218f716;
    func_ov001_02171d90(&data_ov001_021904f4, &func_020040b4);
    func_ov001_02171d90(&data_ov001_0219050c, &func_0200448c);
    func_ov001_02171d90(&data_ov001_021904dc, &func_020046cc);
    M2C_FIELD(&data_ov001_02193d5c, s32 *, 4) = func_ov001_02189dc8(func_ov001_02171d30(&text), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
}

void func_ov001_02176a20(void) {
    extern M2C_UNK func_ov001_02176a74;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    func_ov001_02175d54(&func_ov001_02176a74);
}

void func_ov001_02176a74(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02176ab0;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    func_ov001_02175d54(&func_ov001_02176ab0);
}

void func_ov001_02176ab0(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_02176ad8;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_02176ad8);
}

void func_ov001_02176ad8(void) {
    void func_ov001_02176aec(void);
    void func_ov001_02176c18(void);
    void func_ov001_02176c1c(void);
    func_ov001_02176aec();
    func_ov001_02176c18();
    func_ov001_02176c1c();
}

#pragma opt_strength_reduction off
void func_ov001_02176aec(void){
M2C_UNK func_ov001_021716d8(M2C_UNK);
M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
void func_ov001_02176d80(s32);
s32 func_ov001_0218bb00(s32);s32 func_ov001_0218bb24(s32);s32 func_ov001_0218bbd8(void *);
extern u8 data_ov001_0218f6f6[];
extern u16 data_ov001_0218f706,data_ov001_0218f70a,data_ov001_0218f708,data_ov001_0218f70c;
extern u8 data_ov001_02193d5c;
u32 index;u8 *entry;s32 offset;u16 a,b,c,d;
entry=data_ov001_0218f6f6;
for(index=0;index<2;index++,entry+=8){
if(func_ov001_0218bbd8(entry)){
func_ov001_021716d8(1);
offset=(u8)index*8;
a=M2C_FIELD(&data_ov001_0218f706,u16 *,offset);
b=M2C_FIELD(&data_ov001_0218f70a,u16 *,offset);
c=M2C_FIELD(&data_ov001_0218f708,u16 *,offset);
d=M2C_FIELD(&data_ov001_0218f70c,u16 *,offset);
M2C_FIELD(&data_ov001_02193d5c,s8 *,0)=index;
func_ov001_02172094(a,b,c,d);return;
}
}
if(func_ov001_0218bb00(1)){func_ov001_021716d8(1);return;}
if(func_ov001_0218bb00(2)){func_ov001_021716d8(0);return;}
if(func_ov001_0218bb24(0x40)){func_ov001_02176d80(1);return;}
if(func_ov001_0218bb24(0x80)){func_ov001_02176d80(3);return;}
if(func_ov001_0218bb24(0x20)){func_ov001_02176d80(0);return;}
if(!func_ov001_0218bb24(0x10))return;
func_ov001_02176d80(2);
}
#pragma opt_strength_reduction reset
void func_ov001_02176c18(void) {

}

void func_ov001_02176c1c(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_02176df0(void);
    void func_ov001_02176c6c(void);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_ov001_021716c4();
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov001_02185024(7);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02176578);
        return;
    case 1:
        func_ov001_02185024(6);
        func_ov001_02176df0();
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02176c6c);
        return;
    }
}

void func_ov001_02176c6c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02176c8c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_02176c8c);
}

void func_ov001_02176c8c(void) {
    extern M2C_UNK func_ov001_02176cd8;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x16, 8);
    func_ov001_02175d54(&func_ov001_02176cd8);
}

void func_ov001_02176cd8(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_02172184();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02189ebc(s32);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    extern u8 data_ov001_02193d5c;
    extern M2C_UNK func_ov001_02180d44;
    extern M2C_UNK func_ov001_021778c0;

    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02172184();
    func_ov001_02171cf8();
    func_ov001_02189ebc(M2C_FIELD(&data_ov001_02193d5c, s32 *, 4));
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x14);
    switch (data_ov001_02193d5c) {                  /* irregular */
    case 0:
        func_ov001_02175d64(1, 0);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_02180d44);
        return;
    case 1:
        func_ov001_02175d64(0, 0);
        func_ov001_02175d54((M2C_UNK *)&func_ov001_021778c0);
        return;
    }
}

void func_ov001_02176d80(s32 arg0) {
    M2C_UNK func_ov001_02172094(u16, u16, u16, u16);
    M2C_UNK func_ov001_02185024(M2C_UNK);
    extern u16 data_ov001_0218f706, data_ov001_0218f708, data_ov001_0218f70a, data_ov001_0218f70c;
    extern u8 data_ov001_02193d5c;
    s32 offset;

    if ((arg0 != 1) && (arg0 != 3)) {
        data_ov001_02193d5c ^= 1;
        func_ov001_02185024(8);
        offset = data_ov001_02193d5c * 8;
        func_ov001_02172094(M2C_FIELD(&data_ov001_0218f706, u16 *, offset), M2C_FIELD(&data_ov001_0218f70a, u16 *, offset), M2C_FIELD(&data_ov001_0218f708, u16 *, offset), M2C_FIELD(&data_ov001_0218f70c, u16 *, offset));
    }
}

void func_ov001_02176df0(void) {
M2C_UNK func_ov001_021837e4(s32,u8,u8);
extern u8 data_ov001_02193d5c;
struct MenuValues2 table=data_ov001_0218f6f4;
u8 value=table.values[data_ov001_02193d5c];
func_ov001_021837e4(M2C_FIELD(&data_ov001_02193d5c,s32 *,4),value,value);
}

void func_ov001_02176e30(void) {
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    void func_ov001_02176e78();
    extern s8 data_ov001_02193d64;
    extern M2C_UNK func_ov001_02176ef8;
    data_ov001_02193d64 = 0;
    func_ov001_02176e78();
    func_ov001_02172250(0x12);
    func_ov001_02171c24(0x3B, -1, 0);
    func_ov001_02171e58(0x17);
    func_ov001_02175d54(&func_ov001_02176ef8);
}

void func_ov001_02176e78(void) {
 M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
 extern M2C_UNK data_ov001_02190520;
 extern M2C_UNK func_0200448c;
 func_ov001_02171d90(&data_ov001_02190520, &func_0200448c);
 M2C_FIELD((void *)0x04001008,u16 *,0) = (M2C_FIELD((void *)0x04001008,u16 *,0) & ~3) | 3;
 M2C_FIELD((void *)0x04001008,u16 *,2) = (M2C_FIELD((void *)0x04001008,u16 *,2) & ~3) | 3;
 *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
 M2C_FIELD((void *)0x0400000a,u16 *,0) = (M2C_FIELD((void *)0x0400000a,u16 *,0) & ~3) | 3;
 M2C_FIELD((void *)0x0400000a,u16 *,2) = (M2C_FIELD((void *)0x0400000a,u16 *,2) & ~3) | 3;
}

void func_ov001_02176ef8(void) {
    extern M2C_UNK func_ov001_02176f4c;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    func_ov001_02175d54(&func_ov001_02176f4c);
}

