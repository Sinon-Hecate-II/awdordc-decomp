/* 20 functions from 0x021858A4 to 0x021867AC (ov001), found by ds-decomp. */
#include "common.h"

s32 func_ov001_02185b34(void) {
    extern M2C_UNK data_ov001_02193e0c;
    if (M2C_FIELD(&data_ov001_02193e0c, void **, 4) == NULL) {
        return 1;
    }
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e0c, void **, 4), u8 *, 0x18) == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02185b60(s32 arg0) {
    s32 func_ov001_02171d30(s32);
    s32 func_ov001_02189dc8(s32, s32, s32);
    void func_ov001_02185ba8(s32);
    extern s32 data_ov001_02190be4[];
    extern s32 data_ov001_02193e0c;
    data_ov001_02193e0c = func_ov001_02189dc8(func_ov001_02171d30(data_ov001_02190be4[arg0]), 0, 4);
    func_ov001_0218c884(1, func_ov001_02185ba8, 0, 0x78);
}

void func_ov001_02185ba8(s32 arg0) {
    extern s32 data_ov001_02193e0c;
    func_020067e0(data_ov001_02193e0c, 0x600);
    func_0200442c(data_ov001_02193e0c, 0, 0x600);
    func_ov001_02189ebc(data_ov001_02193e0c);
    func_ov001_0218c92c(1, arg0);
}

s32 func_ov001_02185d78(void) {
    s32 func_020125b0(void (*)(void), void *);
    void func_ov001_02185ea8();
    extern void *data_ov001_02193e14;
    if (func_020125b0(func_ov001_02185ea8, (s8 *)data_ov001_02193e14 + 0x1374) == 2) {
        return 1;
    }
    return 0;
}

void func_ov001_02185e90(s32 arg0) {
    extern void *data_ov001_02193e14;
    M2C_FIELD(data_ov001_02193e14, s32 *, 0x1370) = arg0;
}

void func_ov001_02185ea8(u16 *p) {
extern void *data_ov001_02193e14;u32 v;void *q;
if(p[1])return;q=data_ov001_02193e14;
v=M2C_FIELD(q,u8 *,0x1b94);
if(v){if(p[0]==2)M2C_FIELD(q,u8 *,0x1b94)=2;return;}
v=p[0];if(v!=38)return;
v=p[4];switch(v){case 5:if(M2C_FIELD(q,u8 *,0x1b96))func_ov001_02186090(p);else func_ov001_02185f38(p);func_ov001_02185d78();break;
case 4:func_ov001_02185d78();break;default:func_02007958(p);break;}
}

void func_ov001_02186604(void) {
extern void *data_ov001_02193e18;void func_ov001_02186c68();s32 func_ov001_0218c884(s32,void (*)(),s32,s32);
func_ov001_0218c92c(0,M2C_FIELD(data_ov001_02193e18,s32 *,20));
M2C_FIELD(data_ov001_02193e18,s32 *,20)=func_ov001_0218c884(1,func_ov001_02186c68,0,120);
}

s8 func_ov001_02186648(void) {
    extern void *data_ov001_02193e18;
    return M2C_FIELD(data_ov001_02193e18, s8 *, 0x1B);
}

s32 func_ov001_0218665c(void) {
    extern void *data_ov001_02193e18;
    if (data_ov001_02193e18 != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02186678(s32 a) {
extern void *data_ov001_02193e18;void func_ov001_021866d8();
M2C_FIELD(data_ov001_02193e18,s8 *,26)--;
func_02003a10(0x4000050,M2C_FIELD(data_ov001_02193e18,s8 *,26));
if(M2C_FIELD(data_ov001_02193e18,s8 *,26)<=-12)func_ov001_0218c924(a,func_ov001_021866d8);
}

