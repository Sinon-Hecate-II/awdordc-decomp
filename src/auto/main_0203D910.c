/* 19 functions from 0x0203D910 to 0x0203E908 (main), found by ds-decomp. */
#include "common.h"

void func_0203db94(s32 arg0,s32 arg1,u8 *arg2) {
 s32 func_0203f3c0(void *,u8 *,s32); s32 func_0206abd8(void *,s32,s32);
 void func_0203f45c(s32,s32,s32,s32,s32 *,s32);
 char buf[16]; s32 values[128]; s32 i;
 for(i=0;i<128;i++) {
 if(func_0203f3c0(buf,arg2+1,i)==-1) break;
 values[i]=func_0206abd8(buf,0,10);
 }
 func_0203f45c(arg2[0],arg1,0,0,values,i);
}

void func_0203dc18(void) {
 M2C_FIELD(func_02044268(),u8 *,0x3cc)=255;
 M2C_FIELD(func_02044268(),u8 *,0x3cd)=0;
}

void func_0203dc38(s32 arg0,s32 arg1) {
 extern s32 data_020fc904;
 s32 func_0203aeb4(); void func_02041e44(); void func_02037638(s32,s32); s32 func_0203af50(s32,s32 *,s32); void func_0203e9b0();
 s32 a,b,c; void *p;
 if(func_02044268()==0 || arg0==0) return;
 func_02041e44(); func_02037638(arg0,arg1); func_0203af50(1,&data_020fc904,0);
 a=M2C_FIELD(func_02044268(),u8 *,0x15)==2;
 b=M2C_FIELD(func_02044268(),s32 *,0x20c)==0;
 p=func_02044268();
 c=func_0203aeb4(M2C_FIELD(func_02044268(),s32 *,0x20c));
 ((void (*)(s32,s32,s32,s32,s32,s32))M2C_FIELD(p,void **,0x464))(arg0,0,b,a,c,M2C_FIELD(func_02044268(),s32 *,0x468));
 func_0203e9b0();
}

void func_0203dcf4(void) {
    M2C_UNK func_0205ea70(s32);
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 2) {
        return;
    }
    M2C_FIELD(func_02044268(), s8 *, 0x14) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x16) = 0;
    func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
}

void func_0203e064(M2C_UNK arg0) {
    M2C_UNK func_02040e1c(M2C_UNK);
    if (M2C_FIELD(func_02044268(), u8 *, 0x1A8) == 2) {
        return;
    }
    func_02040e1c(arg0);
}

s32 func_0203e088(s32 arg0,s32 arg1) {
 void func_0203e0ec(s32,s32); s32 i;
 if(func_02044268()==0) return 0;
 for(i=0;i<arg1;i++) {
 if(arg0==((s32 *)(func_02044268()+0xf4))[i]) {
 func_0203e0ec(i,arg1); return 1;
 }
 }
 return 0;
}

s32 func_0203e2a4(void) { if(func_02044268()==0)return 0; return M2C_FIELD(func_02044268(),u8 *,0xd); }

s32 func_0203e2c4(void) { if(func_02044268()==0)return 0; return M2C_FIELD(func_02044268(),u8 *,0xe); }

void func_0203e2e4(void) {
 s32 n=-1; s32 i;
 for(i=0;i<32;i++) { if(M2C_FIELD(func_02044268(),s32 *,0x2f0) & (1<<i)) n++; }
 if(n==-1) { M2C_FIELD(func_02044268(),u8 *,0xe)=0; return; }
 M2C_FIELD(func_02044268(),u8 *,0xe)=n;
}

s32 func_0203e338(s32 *arg0) { if(func_02044268()==0)return 0; *arg0=func_02044268()+0x2d0; return M2C_FIELD(func_02044268(),u8 *,0xd)+1; }

s32 func_0203e36c(u8 **a){extern u8 data_0213daf4[];s32 func_02044268(void);s32 i;u8 *p;void *q;
if(!func_02044268())return 0;
func_02007f8c(data_0213daf4,0,32);
i=0;if(i<=M2C_FIELD(func_02044268(),u8 *,14)){p=data_0213daf4;do{
q=(void *)func_02044268();
if(!(M2C_FIELD(q,u32 *,0x2f0)&(1<<M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0))))break;
*p++=M2C_FIELD((u8 *)func_02044268()+i,u8 *,0x2d0);
i++;}while(i<=M2C_FIELD(func_02044268(),u8 *,14));}
*a=data_0213daf4;return M2C_FIELD(func_02044268(),u8 *,14)+1;
}

s32 func_0203e410(void){
M2C_UNK func_0200567c(void *,s32,void *,s32);M2C_UNK func_02037d78(void *,void *,void *,s32);M2C_UNK func_02037db0(void *,void *,void *,s32);s32 func_0203af50(s32,s32 *,s32);
extern M2C_UNK data_020fc908,data_020fc91c,data_020fc950,data_020fc954;
u8 sp20[12];s32 sp0[8];
if(M2C_FIELD(func_02044268(),u8 *,21)!=2)return 0;
func_0200567c(sp20,12,&data_020fc908,M2C_FIELD(func_02044268(),u8 *,22)+1);
func_02037d78(&data_020fc950,sp20,sp0,47);
func_0200567c(sp20,12,&data_020fc908,M2C_FIELD(func_02044268(),u8 *,13)+1);
func_02037db0(&data_020fc954,sp20,sp0,47);
func_0200567c(sp20,12,&data_020fc908,3);
func_02037db0(&data_020fc91c,sp20,sp0,47);
return func_0203af50(6,sp0,0);
}

void func_0203e4e0(void) {
    M2C_UNK func_020376d8(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020427f4();
    M2C_UNK func_02044258(M2C_UNK);
    extern M2C_UNK data_0213d39c;
    func_02044258(0);
    if (M2C_FIELD(&data_0213d39c, s32 *, 8) != 0) {
        func_020376d8(4, M2C_FIELD(&data_0213d39c, s32 *, 8), 0);
        M2C_FIELD(&data_0213d39c, s32 *, 8) = 0;
    }
    func_020427f4();
    if (M2C_FIELD(&data_0213d39c, s32 *, 0) != 0) {
        func_020376d8(4, M2C_FIELD(&data_0213d39c, s32 *, 0), 0);
        M2C_FIELD(&data_0213d39c, s32 *, 0) = 0;
    }
    M2C_FIELD(&data_0213d39c, s8 *, 0x1C) = 0;
    M2C_FIELD(&data_0213d39c, s8 *, 0x1D) = 0;
}

s32 func_0203e558(void) {
    s32 func_02044268();
    if (func_02044268() == 0) {
        return 1;
    }
    return 0;
}

/* Reset matchmaking context: mode 2 preserves a session, copying byte 0xD to 0x14 and
   selecting state 0x01 (mode 3) or 0x0A (mode 2); mode 1 keeps mode but selects state
   0x03 (mode 0) or 0x04 (mode 1); mode 0 clears mode callbacks too. */
void func_0203e570(s32 resetMode) {
    M2C_UNK func_02007df8(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007e54(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    s16 func_02037eec(M2C_UNK);
    M2C_UNK func_02044278(M2C_UNK);
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r4;
    void *temp_r5;

    M2C_FIELD(func_02044268(), s8 *, 0xC) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x17C) = 0;
    temp_r5 = func_02044268();
    M2C_FIELD(temp_r5, s16 *, 0x17E) = func_02037eec(0x10000);
    M2C_FIELD(func_02044268(), s32 *, 0x180) = 0;
    temp_r0 = func_02044268();
    M2C_FIELD(temp_r0, s32 *, 0x184) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x188) = 0;
    temp_r0_2 = func_02044268();
    M2C_FIELD(temp_r0_2, s32 *, 0x18C) = 0;
    M2C_FIELD(temp_r0_2, s32 *, 0x190) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A4) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A9) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1AA) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1AB) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1AC) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A7) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A8) = 0;
    M2C_FIELD(func_02044268(), s16 *, 0x1B2) = 0;
    M2C_FIELD(func_02044268(), s16 *, 0x1B4) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x1B8) = 0;
    temp_r0_3 = func_02044268();
    M2C_FIELD(temp_r0_3, s32 *, 0x1E0) = 0;
    M2C_FIELD(temp_r0_3, s32 *, 0x1E4) = 0;
    temp_r0_4 = func_02044268();
    M2C_FIELD(temp_r0_4, s32 *, 0x1F0) = 0;
    M2C_FIELD(temp_r0_4, s32 *, 0x1F4) = 0;
    func_02007e54(0, func_02044268() + 0x3CC, 0x98);
    if (resetMode == 2) {
        temp_r4 = func_02044268();
        M2C_FIELD(temp_r4, u8 *, 0x14) = (u8) M2C_FIELD(func_02044268(), u8 *, 0xD);
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 3) {
            func_02044278(1);
            return;
        }
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) != 2) {
            return;
        }
        func_02044278(0xA);
        return;
    }
    M2C_FIELD(func_02044268(), s8 *, 0xD) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0xE) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x14) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x17) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x20) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0xE8) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A5) = 0;
    M2C_FIELD(func_02044268(), s16 *, 0x1B0) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x1BC) = 0;
    temp_r0_5 = func_02044268();
    M2C_FIELD(temp_r0_5, s32 *, 0x1C0) = 0;
    M2C_FIELD(temp_r0_5, s32 *, 0x1C4) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x1C8) = 0;
    temp_r0_6 = func_02044268();
    M2C_FIELD(temp_r0_6, s32 *, 0x1CC) = 0;
    M2C_FIELD(temp_r0_6, s32 *, 0x1D0) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x1D4) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x204) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x208) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x2F0) = 0;
    func_02007e54(0, func_02044268() + 0x24, 0x80);
    func_02007df8(0, func_02044268() + 0xA4, 0x40);
    func_02007e54(0, func_02044268() + 0xF4, 0x80);
    func_02007e54(0, func_02044268() + 0x194, 0xC);
    func_02007e54(0, func_02044268() + 0x210, 0x80);
    func_02007df8(0, func_02044268() + 0x290, 0x40);
    func_02007f8c(func_02044268() + 0x2D0, 0, 0x20);
    func_02007e54(0, func_02044268() + 0x348, 0x84);
    if (resetMode == 1) {
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 0) {
            func_02044278(3);
            return;
        }
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) != 1) {
            return;
        }
        func_02044278(4);
        return;
    }
    M2C_FIELD(func_02044268(), s8 *, 0x15) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x16) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x18) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x20C) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1A6) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1AE) = 0;
    M2C_FIELD(func_02044268(), s8 *, 0x1AD) = 0;
    temp_r0_7 = func_02044268();
    M2C_FIELD(temp_r0_7, s32 *, 0x1F8) = 0;
    M2C_FIELD(temp_r0_7, s32 *, 0x1FC) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x46C) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x470) = 0;
}

