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

void func_0203dd30(u8 arg0, s32 arg1, void *arg2) {
    M2C_UNK func_020411dc(M2C_UNK);
    M2C_UNK func_02041fb0(u8, M2C_UNK);
    s32 func_02042a6c(M2C_UNK);
    M2C_UNK func_02044278(M2C_UNK);
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 var_r5;
    u8 temp_r6;
    void *temp_r0;
    void *temp_r4;
    void *temp_r4_2;

    switch (arg1) {                                 /* irregular */
    case 2:
        if (M2C_FIELD(func_02044268(), s32 *, 0x1A0) == 1) {
            if (M2C_FIELD(arg2, u8 *, 0) == 1) {
                M2C_FIELD(func_02044268(), s32 *, 0x20C) = 0;
            }
            temp_r6 = M2C_FIELD(arg2, u8 *, 1);
            temp_r0 = func_02044268();
            M2C_FIELD((temp_r0 + temp_r6), u8 *, 0x2D0) = (u8) M2C_FIELD(arg2, u8 *, 2);
            temp_r4 = func_02044268();
            M2C_FIELD((temp_r4 + (temp_r6 * 4)), s32 *, 0xF4) = (s32) M2C_FIELD(func_02044268(), s32 *, 0x200);
            if ((M2C_FIELD(func_02044268(), u8 *, 0x15) == 0) || (M2C_FIELD(func_02044268(), u8 *, 0x15) == 1)) {
                temp_r4_2 = func_02044268();
                M2C_FIELD(temp_r4_2, u8 *, 0x16) = (u8) M2C_FIELD(func_02044268(), u8 *, 0xD);
            }
            M2C_FIELD(func_02044268(), s8 *, 0x1AD) = 0;
            func_02044278(9);
        }
        func_02041fb0(arg0, 3);
        return;
    case 3:
        if (M2C_FIELD(func_02044268(), s32 *, 0x1A0) == 0x10) {
            temp_r0 = func_02044268();
            M2C_FIELD(temp_r0, s32 *, 0x1D4) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1D4) | (1 << arg0));
            temp_r4_3 = M2C_FIELD(arg2, u8 *, 0) | (M2C_FIELD(arg2, u8 *, 1) << 8);
            if (temp_r4_3 > (s32) M2C_FIELD(func_02044268(), u16 *, 0x1B0)) {
                M2C_FIELD(func_02044268(), s16 *, 0x1B0) = (s16) temp_r4_3;
            }
            temp_r4_4 = func_02042a6c(0);
            if (temp_r4_4 != M2C_FIELD(func_02044268(), s32 *, 0x1D4)) {
                return;
            }
            var_r5 = 1;
            if ((s32) M2C_FIELD(func_02044268(), u8 *, 0xD) >= 1) {
                do {
                    temp_r0 = func_02044268();
                    func_02041fb0(M2C_FIELD((temp_r0 + var_r5), u8 *, 0x2D0), 4);
                    var_r5 += 1;
                } while (var_r5 <= (s32) M2C_FIELD(func_02044268(), u8 *, 0xD));
            }
            func_02044278(0x11);
            return;
        }
        func_02041fb0(arg0, 4);
        return;
    case 4:
        if (M2C_FIELD(func_02044268(), s32 *, 0x1A0) != 9) {
            return;
        }
        func_020411dc(4);
        return;
    }
}

/* Handles deferred battle/action state transitions after the active phase check. */
s32 func_0203dee8(s32 command, s32 parameter) {
u64 func_02007004(void); s32 func_02038f6c(void);
M2C_UNK func_02044278(s32); void func_02041be0(s32); void func_02041d14(void); void func_0205afec(s32); void func_0205df50(s32);
void *state;
if(func_02038f6c()!=5)return 0;
if(M2C_FIELD(func_02044268(),u8 *,21)==2)return 1;
if(command){func_0203dc38(command,parameter+0xfffec780);return 1;}
M2C_FIELD(func_02044268(),u8 *,0x2d0)=0;
if(M2C_FIELD(func_02044268(),u8 *,0x1a9)==1 || M2C_FIELD(func_02044268(),u8 *,0x1a8)==1 || M2C_FIELD(func_02044268(),u8 *,0x1a8)==2)return 1;
if(M2C_FIELD(func_02044268(),s32 *,0x19c)){
func_0205df50(M2C_FIELD(func_02044268(),s32 *,0x19c));M2C_FIELD(func_02044268(),s32 *,0x19c)=0;}
if(M2C_FIELD(func_02044268(),u8 *,13)){
if(!M2C_FIELD(func_02044268(),u8 *,0x1a8)){M2C_FIELD(func_02044268(),u8 *,0x1a8)=3;func_0205afec(*M2C_FIELD(func_02044268(),s32 **,4));}
}else if(M2C_FIELD(func_02044268(),u8 *,21)==3)func_0203dc38(6,0xfffec5d2);
else if(M2C_FIELD(func_02044268(),s32 *,0x208))func_02041d14();
else if(M2C_FIELD(func_02044268(),s32 *,0x1a0)==1){func_02044278(18);state=(void *)func_02044268();M2C_FIELD(state,u64 *,0x1f0)=func_02007004();}
else func_02041be0(1);
return 1;
}

void func_0203e064(M2C_UNK arg0) {
    M2C_UNK func_02040e1c(M2C_UNK);
    if (M2C_FIELD(func_02044268(), u8 *, 0x1A8) == 2) {
        return;
    }
    func_02040e1c(arg0);
}

s32 func_0203e088(s32 arg0,s32 arg1) {
 s32 func_0203e0ec(s32,s32); s32 i;
 if(func_02044268()==0) return 0;
 for(i=0;i<arg1;i++) {
 if(arg0==((s32 *)(func_02044268()+0xf4))[i]) {
 func_0203e0ec(i,arg1); return 1;
 }
 }
 return 0;
}

s32 func_0203e0ec(s32 arg0, s32 arg1) {
    s32 func_02044268(void); void func_0203e2e4(void);
    s32 r9, r8, r11;
    void *p3, *p4;
    void *a, *b, *baseFirst, *baseSecond;
    u8 byteVal, bb;
    s32 r4, r5, r6, r7, idx;
    void *q, *w;
    r9 = arg0;
    r8 = arg1;
    if (func_02044268() == 0) return 0;
    r11 = *(s32 *)((u8 *)func_02044268() + r9 * 4 + 0xf4);
    p3 = func_02044268();
    p4 = func_02044268();
    byteVal = *(u8 *)((u8 *)p4 + r9 + 0x2d0);
    *(s32 *)((u8 *)p3 + 0x2f0) &= ~(1 << byteVal);
    func_0203e2e4();
    if (r9 < r8 - 1) {
        r5 = r8 - r9 - 1;
        r4 = 0;
        if (r5 > 0) {
            do {
                r7 = r9 + r4;
                r6 = r7 + 1;
                a = func_02044268();
                b = func_02044268();
                *(s32 *)((u8 *)a + r7 * 4 + 0x24) = *(s32 *)((u8 *)b + r6 * 4 + 0x24);
                a = func_02044268();
                b = func_02044268();
                *(u16 *)((u8 *)a + r7 * 2 + 0xa4) = *(u16 *)((u8 *)b + r6 * 2 + 0xa4);
                a = func_02044268();
                b = func_02044268();
                *(s32 *)((u8 *)a + r7 * 4 + 0xf4) = *(s32 *)((u8 *)b + r6 * 4 + 0xf4);
                a = func_02044268();
                b = func_02044268();
                *(s32 *)((u8 *)a + r7 * 4 + 0x210) = *(s32 *)((u8 *)b + r6 * 4 + 0x210);
                a = func_02044268();
                b = func_02044268();
                *(u16 *)((u8 *)a + r7 * 2 + 0x290) = *(u16 *)((u8 *)b + r6 * 2 + 0x290);
                baseFirst = func_02044268();
                baseSecond = func_02044268();
                q = (void *)((s32)r9 + (s32)baseSecond);
                bb = *(u8 *)((u8 *)q + r4 + 0x2d1);
                w = (void *)((s32)r9 + (s32)baseFirst);
                *(u8 *)((u8 *)w + r4 + 0x2d0) = bb;
                r4++;
            } while (r4 < r5);
        }
    }
    if (r8 > 0) {
        idx = r8 - 1;
        b = func_02044268();
        *(s32 *)((u8 *)b + idx * 4 + 0x24) = 0;
        b = func_02044268();
        *(u16 *)((u8 *)b + idx * 2 + 0xa4) = 0;
        b = func_02044268();
        *(s32 *)((u8 *)b + idx * 4 + 0xf4) = 0;
        b = func_02044268();
        *(s32 *)((u8 *)b + idx * 4 + 0x210) = 0;
        b = func_02044268();
        *(u16 *)((u8 *)b + idx * 2 + 0x290) = 0;
        b = func_02044268();
        *(u8 *)((u8 *)b + idx + 0x2d0) = 0;
    }
    return r11;
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

