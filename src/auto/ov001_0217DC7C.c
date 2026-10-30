/* 12 functions from 0x0217DC7C to 0x0217EB6C (ov001), found by ds-decomp. */
#include "common.h"

M2C_UNK func_ov001_0217dc7c(void) {
    return 0;
}

void func_ov001_0217ded8(void) {
    M2C_UNK func_ov001_02183a08();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217def8;
    func_ov001_02183a08();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217def8);
}

void func_ov001_0217def8(void) {
    s32 func_ov001_0218a800(M2C_UNK);
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217df44;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    func_ov001_02175d54(&func_ov001_0217df44);
}

void func_ov001_0217df44(void) { }

void func_ov001_0217e238(void) {
    s32 func_02002088(u16, s32);
    void func_ov001_0217e2f8(s32, s32);
    void func_ov001_0217e494(s32, s32);
    M2C_UNK func_ov001_0217e95c();
    M2C_UNK func_ov001_02183720();
    M2C_UNK func_ov001_02183738(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b1ec(s32, M2C_UNK);
    M2C_UNK func_ov001_0218b298(s32);
    extern u16 data_ov001_0218f8fe[];
    extern M2C_UNK data_ov001_02193dac;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = func_02002088(M2C_FIELD(&data_ov001_02193dac, u16 *, 4), 0x1D);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14), 0);
    var_r5 = var_r4;
    var_r6 = 0;
    do {
        func_ov001_0217e2f8(var_r5, var_r6);
        var_r6 += 1;
        var_r5 += 1;
    } while (var_r6 < 5);
    func_ov001_02183738(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 8) + (data_ov001_0218f8fe[var_r4] * 2), 0, 0x1E, 0x13);
    var_r5 = 0;
    do {
        func_ov001_0217e494(var_r4, var_r5);
        var_r5 += 1;
        var_r4 += 1;
    } while (var_r5 < 5);
    func_ov001_02183720();
    func_ov001_0218b298(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14));
    func_ov001_0217e95c();
}

#pragma opt_common_subs off
void func_ov001_0217e2f8(s32 arg0,s32 arg1){
void *func_ov001_0218445c(void);
void func_ov001_0217e780(u8*,s32);void func_ov001_0217e8d4(void*,s32);
u8 *p=func_ov001_0218445c();s32 n;u8 text[33];
switch((u32)arg0){
case 0:func_ov001_0217e780(p+0x40,arg1);break;
case 1:
switch((u32)(p[0xe6]<<30)>>30){case 0:return;case 1:n=10;break;case 2:n=26;break;case 3:n=32;break;}
if(((u32)(p[0xe6]<<24)>>26)==1)n/=2;
func_02007f8c(text,0,33);func_02065210(text,42,n);func_ov001_0217e780(text,arg1);break;
case 3:if(p[0xf5])return;func_ov001_0217e8d4(p+0xc0,arg1);break;
case 4:if(p[0xf5])return;func_ov001_0217e8d4(p+0xf0,arg1);break;
case 5:if(p[0xf5])return;func_ov001_0217e8d4(p+0xc4,arg1);break;
case 7:if(p[0xf6])return;func_ov001_0217e8d4(p+0xc8,arg1);break;
case 8:if(p[0xf6])return;func_ov001_0217e8d4(p+0xcc,arg1);break;
}
}

void func_ov001_0217e494(s32 arg0, s32 arg1) {
    void *func_ov001_0218445c(void);
    s32 func_ov001_0217e5e8(u32);
    void func_ov001_0217e67c(s32, s32, s32);
    extern M2C_UNK data_ov001_02193dac;
    void *p;
    s32 r4 = arg0;
    s32 r5 = 0;
    s32 r1;

    p = func_ov001_0218445c();

    switch (r4) {
        case 0:
        case 1:
            r4 = 0;
            if (func_ov001_0217e5e8(0) == 0) {
                r5 = 2;
            }
            break;
        case 2: {
            u8 f5 = ((u8 *)p)[0xF5];
            void **root = M2C_FIELD(&data_ov001_02193dac, void **, 8);
            u8 b4 = ((u8 *)root)[4];
            r4 = (f5 != 0) ? 1 : 2;
            if (b4 != 0) {
                r5 = 1;
            }
            r1 = 0;
            if (((u8 *)root)[5] != 0) {
                r1 = 1;
            }
            func_ov001_0217e67c(r4, r1, arg1);
            return;
        }
        case 3:
        case 4:
        case 5:
            r4 = 0;
            if (((u8 *)p)[0xF5] != 0) {
                r5 = 2;
            } else {
                r5 = 0;
            }
            break;
        case 6: {
            u8 f6 = ((u8 *)p)[0xF6];
            r5 = 0;
            if (f6 != 0) {
                r4 = 1;
            } else {
                r4 = 2;
                if (((u8 *)p)[0xF5] == 0) {
                    r5 = 2;
                }
            }
            {
                void **root = M2C_FIELD(&data_ov001_02193dac, void **, 8);
                if (((u8 *)root)[6] != 0) {
                    r5 = 1;
                }
                r1 = 0;
                if (((u8 *)root)[7] != 0) {
                    r1 = 1;
                }
                func_ov001_0217e67c(r4, r1, arg1);
                return;
            }
        }
        case 7:
        case 8:
            func_ov001_0217e67c(0, 2, arg1);
            return;
        default:
            r4 = 0;
            r5 = 2;
            break;
    }
    func_ov001_0217e67c(r4, r5, arg1);
}

#pragma opt_common_subs reset
s32 func_ov001_0217e5e8(u32 arg0) {
    void *func_ov001_0218445c();
    s32 var_r1;
    void *temp_r0;

    temp_r0 = func_ov001_0218445c();
    var_r1 = 1;
    switch (arg0) {
    default:
        break;
    case 7:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) == 0) {
            var_r1 = 0;
        }
        break;
    case 0:
    case 1:
        if ((u32) (u8) (M2C_FIELD(temp_r0, u8 *, 0xE7) + 0xFF) <= 1U) {
            var_r1 = 0;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (M2C_FIELD(temp_r0, u8 *, 0xF5) != 0) {
            var_r1 = 0;
        }
        break;
    case 9:
    case 10:
        if (M2C_FIELD(temp_r0, u8 *, 0xF6) != 0) {
            var_r1 = 0;
        }
        break;
    }
    return var_r1;
}

void func_ov001_0217e67c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov001_0217ee24(s32);
    M2C_UNK func_ov001_0218a55c(M2C_UNK);
    extern M2C_UNK data_ov001_0218f8ee;
    extern M2C_UNK data_ov001_02193dac;
    u16 sp[5];
    void **var_r4;
    s32 *temp_r2;

    sp[0] = 0xCC;
    sp[1] = 0xC0;
    sp[2] = 0xC0;
    sp[3] = 0x8F;
    sp[4] = 0x8F;
    var_r4 = M2C_FIELD(&data_ov001_02193dac, void **, 8) + 0x18 + (arg2 * 4);
    if ((u32) (arg0 - 1) <= 1U) {
        if (func_ov001_0217ee24(arg2) == 2) {
            var_r4 = M2C_FIELD(&data_ov001_02193dac, void **, 8) + 0x2C;
        } else {
            var_r4 = M2C_FIELD(&data_ov001_02193dac, void **, 8) + 0x30;
        }
    }
    temp_r2 = (s32 *) *var_r4;
    if (((u8 *) arg1)[(s32) &data_ov001_0218f8ee + arg0 * 3] != 0) {
        func_ov001_0218a55c(0);
        M2C_FIELD(*var_r4, s32 *, 0) = (s32) ((M2C_FIELD(*var_r4, s32 *, 0) & 0xFE00FF00) | ((u32) (sp[arg0] << 0x17) >> 7));
        M2C_FIELD(*var_r4, u16 *, 4) = (u16) ((M2C_FIELD(*var_r4, u16 *, 4) & ~0xC00) | 0xC00);
        return;
    }
    M2C_FIELD(temp_r2, s32 *, 0) = (s32) ((M2C_FIELD(temp_r2, s32 *, 0) & 0xFE00FF00) | 0x01000000);
}

void func_ov001_0217e780(u8 *arg0,s32 arg1){
extern M2C_UNK data_ov001_02193dac;
s32 func_ov001_0218c3e0(u8 *,s32);
M2C_UNK func_02007f8c(void *,s32,s32);
M2C_UNK func_ov001_0218b080(s32,s32,s32,s32,s32,M2C_UNK *,s32);
u16 buf[17];s32 len,n,i,y;
func_02007f8c(buf,0,0x22);
len=func_ov001_0218c3e0(arg0,32);
n=len<=16?len:16;
for(i=0;i<n;i++){if(arg0[i]==32)buf[i]=0xe01d;else buf[i]=arg0[i];}
y=arg1*29+2;
if(len<=16)y+=5;
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),s32 *,0x14),72,y,2,8,(M2C_UNK *)buf,1);
if(len<=16)return;
func_02007f8c(buf,0,0x22);
len-=16;
for(i=0;i<len;i++){if(arg0[i+16]==32)buf[i]=0xe01d;else buf[i]=arg0[i+16];}
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac,void **,8),s32 *,0x14),72,y+12,2,8,(M2C_UNK *)buf,1);
}

void func_ov001_0217e8d4(void *arg0, s32 arg1) {
    M2C_UNK func_0206ccf8(M2C_UNK *, M2C_UNK, M2C_UNK *, u8, s32, s32, s32);
    M2C_UNK func_ov001_0218b080(s32, M2C_UNK, s32, M2C_UNK, s32, M2C_UNK *, s32);
    extern M2C_UNK data_ov001_02190874;
    extern M2C_UNK data_ov001_02193dac;
    u8 spC[0x20];

    func_0206ccf8(spC, 0x10, &data_ov001_02190874, M2C_FIELD(arg0, u8 *, 0), (s32) M2C_FIELD(arg0, u8 *, 1), (s32) M2C_FIELD(arg0, u8 *, 2), (s32) M2C_FIELD(arg0, u8 *, 3));
    func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193dac, void **, 8), s32 *, 0x14), 0x5F, (arg1 * 0x1D) + 8, 2, 7, spC, 1);
}

