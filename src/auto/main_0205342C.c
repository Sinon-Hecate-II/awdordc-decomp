/* 7 functions from 0x0205342C to 0x020543E8 (main), found by ds-decomp. */
#include "common.h"
typedef struct RequestPair534 { s32 a,b; } RequestPair534;
typedef struct Unk02053e40 { u32 words[60]; } Unk02053e40;

#pragma peephole off
s32 func_0205342c(s32 *arg0, s32 arg1, s8 *arg2) {
    M2C_UNK func_020492a8(s8 *);
    s32 func_02052edc(s32 *, M2C_UNK *, s8 *);
    s32 func_02052f1c(s32 *, M2C_UNK *, s8 *);
    s32 func_02052f5c(s32 *, s32, s32);
    M2C_UNK func_020580fc(s8 *, s8 *, M2C_UNK);
    s32 func_02068c34(s8 *);
    s32 func_0206ad38(s8 *);
    extern M2C_UNK data_020eacc0;
    extern M2C_UNK data_020fe72c;
    extern M2C_UNK data_020fe734;
    extern M2C_UNK data_020fe744;
    extern M2C_UNK data_020fe74c;
    extern M2C_UNK data_020fe758;
    extern M2C_UNK data_020fe764;
    extern M2C_UNK data_020fe770;
    extern M2C_UNK data_020fe77c;
    extern M2C_UNK data_020fe788;
    extern M2C_UNK data_020fe7bc;
    extern M2C_UNK data_020fe7cc;
    extern M2C_UNK data_020fe7d4;
    extern M2C_UNK data_020fe7dc;
    extern M2C_UNK data_020fe7e4;
    extern M2C_UNK data_020fe7ec;
    extern M2C_UNK data_020fe7f4;
    extern M2C_UNK data_020fe7fc;
    extern M2C_UNK data_020fe804;
    extern M2C_UNK data_020fe880;
    extern M2C_UNK data_020fe884;
    extern M2C_UNK data_020fe888;
    extern M2C_UNK data_020fe918;
    extern M2C_UNK data_020fe928;
    extern M2C_UNK data_020fe938;
    extern M2C_UNK data_020fe944;
    extern M2C_UNK data_020fe95c;
    extern M2C_UNK data_020fe970;
    extern M2C_UNK data_020fe984;
    s8 sp0[0x100];
    s32 temp_r0;
    s32 temp_r0_10;
    s32 temp_r0_11;
    s32 temp_r0_12;
    s32 temp_r0_13;
    s32 temp_r0_14;
    s32 temp_r0_15;
    s32 temp_r0_16;
    s32 temp_r0_17;
    s32 temp_r0_18;
    s32 temp_r0_19;
    s32 temp_r0_20;
    s32 temp_r0_21;
    s32 temp_r0_22;
    s32 temp_r0_23;
    s32 temp_r0_24;
    s32 temp_r0_25;
    s32 temp_r0_26;
    s32 temp_r0_27;
    s32 temp_r0_28;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 temp_r4;
    s8 temp_r0_29;
    s8 var_r1;
    u32 temp_r1;

    temp_r4 = *arg0;
    if (arg2 == NULL) {
        func_02058644(arg0, &data_020fe928);
        return 2;
    }
    temp_r1 = arg1 - 0x700;
    switch (temp_r1) {
    default:
    case 10:
    case 12:
    case 19:
        func_02058644(arg0, &data_020fe918);
        return 2;
    case 0:
        if (*arg2 == 0) {
            func_02058644(arg0, &data_020fe928);
            return 2;
        }
        func_020580fc(sp0, arg2, 0x1F);
        func_020580fc(temp_r4 + 0x110, sp0, 0x1F);
        temp_r0 = func_02052edc(arg0, &data_020fe72c, sp0);
        if (temp_r0 != 0) {
            return temp_r0;
        }
        return 0;
    case 1:
        if (*arg2 == 0) {
            func_02058644(arg0, &data_020fe928);
            return 2;
        }
        func_020580fc(sp0, arg2, 0x15);
        func_020580fc(temp_r4 + 0x12F, sp0, 0x15);
        temp_r0_2 = func_02052edc(arg0, &data_020fe734, sp0);
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        return 0;
    case 2:
        if (*arg2 == 0) {
            func_02058644(arg0, &data_020fe928);
            return 2;
        }
        func_020580fc(sp0, arg2, 0x33);
        func_020492a8(sp0);
        func_020580fc(temp_r4 + 0x144, sp0, 0x33);
        temp_r0_3 = func_02052f1c(arg0, &data_020fe744, sp0);
        if (temp_r0_3 != 0) {
            return temp_r0_3;
        }
        return 0;
    case 3:
        if (*arg2 == 0) {
            func_02058644(arg0, &data_020fe928);
            return 2;
        }
        func_020580fc(sp0, arg2, 0x1F);
        func_020580fc(temp_r4 + 0x177, sp0, 0x1F);
        temp_r0_4 = func_02052f1c(arg0, &data_020fe938, sp0);
        if (temp_r0_4 != 0) {
            return temp_r0_4;
        }
        return 0;
    case 4:
        func_020580fc(sp0, arg2, 0x1F);
        temp_r0_5 = func_02052edc(arg0, &data_020fe74c, sp0);
        if (temp_r0_5 != 0) {
            return temp_r0_5;
        }
        return 0;
    case 5:
        func_020580fc(sp0, arg2, 0x1F);
        temp_r0_6 = func_02052edc(arg0, &data_020fe758, sp0);
        if (temp_r0_6 != 0) {
            return temp_r0_6;
        }
        return 0;
    case 7:
        func_020580fc(sp0, arg2, 0x4C);
        temp_r0_7 = func_02052edc(arg0, &data_020fe770, sp0);
        if (temp_r0_7 != 0) {
            return temp_r0_7;
        }
        return 0;
    case 8:
        func_020580fc(sp0, arg2, 0xB);
        temp_r0_8 = func_02052edc(arg0, &data_020fe77c, sp0);
        if (temp_r0_8 != 0) {
            return temp_r0_8;
        }
        return 0;
    case 9:
        if (func_02068c34(arg2) != 2) {
            func_02058644(arg0, &data_020fe944);
            return 2;
        }
        func_020580fc(sp0, arg2, 3);
        temp_r0_9 = func_02052edc(arg0, &data_020fe788, sp0);
        if (temp_r0_9 != 0) {
            return temp_r0_9;
        }
        return 0;
    case 11:
        var_r1 = *arg2;
        if (((s32) var_r1 >= 0) && ((s32) var_r1 < 0x80)) {
            var_r1 = (s8) *(&data_020eacc0 + var_r1);
        }
        temp_r0_29 = var_r1;
        if (temp_r0_29 == 0x4D) {
            M2C_FIELD(sp0, s8 *, 0) = (s8) M2C_FIELD(&data_020fe880, u8 *, 0);
            M2C_FIELD(sp0, u8 *, 1) = (u8) M2C_FIELD(&data_020fe880, u8 *, 1);
        } else if (temp_r0_29 == 0x46) {
            M2C_FIELD(sp0, s8 *, 0) = (s8) M2C_FIELD(&data_020fe884, u8 *, 0);
            M2C_FIELD(sp0, u8 *, 1) = (u8) M2C_FIELD(&data_020fe884, u8 *, 1);
        } else {
            M2C_FIELD(sp0, s8 *, 0) = (s8) M2C_FIELD(&data_020fe888, u8 *, 0);
            M2C_FIELD(sp0, u8 *, 1) = (u8) M2C_FIELD(&data_020fe888, u8 *, 1);
        }
        temp_r0_10 = func_02052edc(arg0, &data_020fe7bc, sp0);
        if (temp_r0_10 != 0) {
            return temp_r0_10;
        }
        return 0;
    case 6:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_11 = func_02052edc(arg0, &data_020fe764, sp0);
        if (temp_r0_11 != 0) {
            return temp_r0_11;
        }
        return 0;
    case 13:
        temp_r0_12 = func_02052f5c(arg0, 0x70D, func_0206ad38(arg2));
        if (temp_r0_12 != 0) {
            return temp_r0_12;
        }
        return 0;
    case 14:
        temp_r0_13 = func_02052f5c(arg0, 0x70E, func_0206ad38(arg2));
        if (temp_r0_13 != 0) {
            return temp_r0_13;
        }
        return 0;
    case 15:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_14 = func_02052edc(arg0, &data_020fe95c, sp0);
        if (temp_r0_14 != 0) {
            return temp_r0_14;
        }
        return 0;
    case 16:
        temp_r0_15 = func_02052f5c(arg0, 0x710, func_0206ad38(arg2));
        if (temp_r0_15 != 0) {
            return temp_r0_15;
        }
        return 0;
    case 17:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_16 = func_02052edc(arg0, &data_020fe970, sp0);
        if (temp_r0_16 != 0) {
            return temp_r0_16;
        }
        return 0;
    case 18:
        temp_r0_17 = func_02052f5c(arg0, 0x712, func_0206ad38(arg2));
        if (temp_r0_17 != 0) {
            return temp_r0_17;
        }
        return 0;
    case 20:
        temp_r0_18 = func_02052f5c(arg0, 0x714, func_0206ad38(arg2));
        if (temp_r0_18 != 0) {
            return temp_r0_18;
        }
        return 0;
    case 21:
        temp_r0_19 = func_02052f5c(arg0, 0x715, func_0206ad38(arg2));
        if (temp_r0_19 != 0) {
            return temp_r0_19;
        }
        return 0;
    case 22:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_20 = func_02052edc(arg0, &data_020fe984, sp0);
        if (temp_r0_20 != 0) {
            return temp_r0_20;
        }
        return 0;
    case 23:
        func_020580fc(sp0, arg2, 0x33);
        temp_r0_21 = func_02052edc(arg0, &data_020fe7cc, sp0);
        if (temp_r0_21 != 0) {
            return temp_r0_21;
        }
        return 0;
    case 24:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_22 = func_02052edc(arg0, &data_020fe7d4, sp0);
        if (temp_r0_22 != 0) {
            return temp_r0_22;
        }
        return 0;
    case 25:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_23 = func_02052edc(arg0, &data_020fe7dc, sp0);
        if (temp_r0_23 != 0) {
            return temp_r0_23;
        }
        return 0;
    case 26:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_24 = func_02052edc(arg0, &data_020fe7e4, sp0);
        if (temp_r0_24 != 0) {
            return temp_r0_24;
        }
        return 0;
    case 27:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_25 = func_02052edc(arg0, &data_020fe7ec, sp0);
        if (temp_r0_25 != 0) {
            return temp_r0_25;
        }
        return 0;
    case 28:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_26 = func_02052edc(arg0, &data_020fe7f4, sp0);
        if (temp_r0_26 != 0) {
            return temp_r0_26;
        }
        return 0;
    case 29:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_27 = func_02052edc(arg0, &data_020fe7fc, sp0);
        if (temp_r0_27 != 0) {
            return temp_r0_27;
        }
        return 0;
    case 30:
        func_020580fc(sp0, arg2, 0x100);
        temp_r0_28 = func_02052edc(arg0, &data_020fe804, sp0);
        if (temp_r0_28 != 0) {
            return temp_r0_28;
        }
        return 0;
    }
}
s32 func_02053c04(void **arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_0204fea0(void **, void *, M2C_UNK *);
    M2C_UNK func_0204fed0(void **, void *, s32);
    extern M2C_UNK data_020fe710;
    extern M2C_UNK data_020fe84c;
    extern M2C_UNK data_020fe990;
    extern M2C_UNK data_020fe9a8;
    void *temp_r4;

    temp_r4 = *arg0;
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe990);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe710);
    func_0204fed0(arg0, temp_r4 + 0x1F4, arg1);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe9a8);
    func_0204fed0(arg0, temp_r4 + 0x1F4, arg2);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe84c);
    return 0;
}

s32 func_02053c9c(void **a,s32 b,s32 c,s32 d,s32 e,s32 f) {
s32 func_02055b84(void **,s32,void **);void *func_02037794(s32);M2C_UNK func_02058644(void **,M2C_UNK *);void func_02052408(void *,void *);
s32 func_02050838(void **,RequestPair534,void *,void *,s32);void func_02054484(void **,void *);s32 func_0204ec8c(void **,s32);
extern M2C_UNK data_020fe824;
register void *buffer; register s32 id; register s32 finish=d; register s32 value=b;
void *found,*req; void *base=*a; s32 enabled,result;RequestPair534 pair;
req=0;enabled=0;if(c==1)enabled=1;
if(M2C_FIELD(base,s32 *,256)==0)enabled=0;
if(e && enabled && func_02055b84(a,b,&found) && M2C_FIELD(found,void **,12)) {
buffer=func_02037794(516);
if(!buffer){func_02058644(a,&data_020fe824);return 1;}
func_02052408(M2C_FIELD(found,void **,12),buffer);
M2C_FIELD(buffer,s32 *,0)=0;M2C_FIELD(buffer,s32 *,4)=b;
pair.a=e;pair.b=f;
result=func_02054330(a,2,0,&req,1,e,f);if(result)return result;
id=M2C_FIELD(req,s32 *,24);
result=func_02050838(a,pair,buffer,req,0);if(result)return result;
func_02054484(a,req);
}else{
result=func_02054330(a,2,0,&req,d,e,f);if(result)return result;
id=M2C_FIELD(req,s32 *,24);result=func_02053c04(a,b,id);if(result)return result;
}
if(d){result=func_0204ec8c(a,id);if(result)return result;}
return 0;
}

/* Allocates and initializes an object structure. */
s32 func_02053e40(void **arg0, void *arg1, Unk02053e40 *arg2) {
    void func_02053f18(void *);
    void *func_02037794(s32);
    u32 func_02049274(u32);
    Unk02053e40 *p;

    if (!M2C_FIELD(*arg0, s32 *, 0x100)) {
        return 1;
    }
    func_02053f18(arg1);
    p = M2C_FIELD(arg1, Unk02053e40 **, 12) = func_02037794(0xf0);
    if (p) {
        *p = *arg2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 0) = func_02049274(M2C_FIELD(arg2, u32 *, 0));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 4) = func_02049274(M2C_FIELD(arg2, u32 *, 4));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 8) = func_02049274(M2C_FIELD(arg2, u32 *, 8));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 12) = func_02049274(M2C_FIELD(arg2, u32 *, 12));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 16) = func_02049274(M2C_FIELD(arg2, u32 *, 16));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 20) = func_02049274(M2C_FIELD(arg2, u32 *, 20));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 200) = func_02049274(M2C_FIELD(arg2, u32 *, 200));
    }
    return M2C_FIELD(arg1, void **, 12) != 0;
}

void func_02053f18(void *arg0) {
    M2C_UNK func_020377c4(void *);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r0 == NULL) {
        return;
    }
    func_020377c4(M2C_FIELD(temp_r0, void **, 0));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 4));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 4) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 8));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 8) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x14));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x14) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC8));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC8) = NULL;
    func_020377c4(M2C_FIELD(arg0, void **, 0xC));
    M2C_FIELD(arg0, void **, 0xC) = NULL;
}

s32 func_02053fe4(void **arg0, void *arg1) {
    void *func_02037794(s32);
    void func_02065210(void *, s32, s32);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02050838(void **, RequestPair534, void *, void *, s32);
    extern M2C_UNK data_020fe9ec;
    extern M2C_UNK data_020fea00;
    extern M2C_UNK data_020fe9c4;
    extern M2C_UNK data_020fea10;
    extern M2C_UNK data_020fea24;
    extern M2C_UNK data_020fea38;
    extern M2C_UNK data_020fea48;

    void *base = *arg0;
    void *operation = arg1;
    RequestPair534 pair;
    void *buffer;
    s32 result;
    s32 i;

    if (arg0 == NULL) {
        func_020640a8((M2C_UNK)&data_020fe9ec, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x22);
    }
    if (*arg0 == NULL) {
        func_020640a8((M2C_UNK)&data_020fea10, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x23);
    }
    if (operation == NULL) {
        func_020640a8((M2C_UNK)&data_020fea24, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x24);
    }

    pair.a = M2C_FIELD(operation, s32 *, 0xC);
    pair.b = M2C_FIELD(operation, s32 *, 0x10);
    if (pair.a != 0) {
        switch (M2C_FIELD(operation, s32 *, 0x00)) {
            case 0:
                buffer = func_02037794(0x20);
                if (buffer == NULL) {
                    func_02058644(arg0, &data_020fea38);
                    return 1;
                }
                func_02065210(buffer, 0, 0x20);
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                if (M2C_FIELD(base, s32 *, 0x418) == 0x201) {
                    M2C_FIELD(buffer, s32 *, 0x04) = M2C_FIELD(base, s32 *, 0x1A0);
                    M2C_FIELD(base, s32 *, 0x1A0) = 0;
                }
                result = func_02050838(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 1:
                buffer = func_02037794(8);
                if (buffer == NULL) {
                    func_02058644(arg0, &data_020fea38);
                    return 1;
                }
                {
                    u8 *p = buffer;
                    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
                    p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0;
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = func_02050838(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 2:
                buffer = func_02037794(0x204);
                if (buffer == NULL) {
                    func_02058644(arg0, &data_020fea38);
                    return 1;
                }
                func_02065210(buffer, 0, 0x204);
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = func_02050838(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 3:
                buffer = func_02037794(0x10);
                if (buffer == NULL) {
                    func_02058644(arg0, &data_020fea38);
                    return 1;
                }
                {
                    s32 zero = 0;
                    s32 n = 4;
                    u8 *ptr = (u8 *)buffer;
                    do {
                        ptr[0] = zero; ptr[1] = zero; ptr[2] = zero; ptr[3] = zero;
                        ptr += 4;
                    } while (--n != 0);
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                M2C_FIELD(buffer, s32 *, 0x0C) = 0;
                result = func_02050838(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 4:
                buffer = func_02037794(4);
                if (buffer == NULL) {
                    func_02058644(arg0, &data_020fea38);
                    return 1;
                }
                {
                    u8 *p = buffer;
                    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = func_02050838(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            default:
                func_020640a8((M2C_UNK)&data_020fea48, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x6B);
                break;
        }
    }
    return 0;
}

s32 func_02054330(void **arg0, s32 arg1, s32 arg2, void **arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *func_02037794(M2C_UNK);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    extern M2C_UNK data_020fea38;
    s32 temp_r2;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = *arg0;
    temp_r0 = func_02037794(0x24);
    if (temp_r0 == NULL) {
        func_02058644(arg0, &data_020fea38);
        return 1;
    }
    M2C_FIELD(temp_r0, s32 *, 0) = arg1;
    M2C_FIELD(temp_r0, s32 *, 4) = arg2;
    M2C_FIELD(temp_r0, s32 *, 8) = arg4;
    M2C_FIELD(temp_r0, s32 *, 0x14) = 0;
    if (arg1 == 0) {
        M2C_FIELD(temp_r0, s32 *, 0x18) = 1;
    } else {
        temp_r2 = M2C_FIELD(temp_r4, s32 *, 0x20C);
        M2C_FIELD(temp_r4, s32 *, 0x20C) = (s32) (temp_r2 + 1);
        M2C_FIELD(temp_r0, s32 *, 0x18) = temp_r2;
        if ((s32) M2C_FIELD(temp_r4, s32 *, 0x20C) < 2) {
            M2C_FIELD(temp_r4, s32 *, 0x20C) = 2;
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg5;
    M2C_FIELD(temp_r0, s32 *, 0x10) = arg6;
    M2C_FIELD(temp_r0, void **, 0x20) = (void *) M2C_FIELD(temp_r4, void **, 0x424);
    M2C_FIELD(temp_r4, void **, 0x424) = temp_r0;
    *arg3 = temp_r0;
    return 0;
}

