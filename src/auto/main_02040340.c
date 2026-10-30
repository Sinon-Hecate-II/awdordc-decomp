/* 11 functions from 0x02040340 to 0x020411DC (main), found by ds-decomp. */
#include "common.h"
void *func_02044268(void);

#pragma opt_strength_reduction off
s32 func_02040340(s32 a, s32 b, s32 c, s32 d, s32 e) {
    return 0;
}

#pragma opt_strength_reduction off
s32 func_0204063c(s32 arg0, s32 arg1, u16 arg2) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    void *func_02044268(void);
    void func_0205ea70(s32);
    u8 func_0204284c(void);
    void func_02042af8(s32);
    s32 loc[2];
    s32 i, r;
    void *p, *q;

    if (M2C_FIELD(func_02044268(), u8 *, 0x17) != 0 && arg0 == M2C_FIELD(func_02044268(), s32 *, 0x20)) return 0;
    M2C_FIELD(func_02044268(), u8 *, 0x17) = 1;
    M2C_FIELD(func_02044268(), s32 *, 0x20) = arg0;
    M2C_FIELD(func_02044268(), s32 *, 0x1bc) = 0;
    M2C_FIELD(func_02044268(), s32 *, 0x1c8) = 0;
    func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
    M2C_FIELD(func_02044268(), s32 *, 0x204) = 0;
    p = func_02044268();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(func_02044268(), u8 *, 0x14) + 1) << 2), s32 *, 0xf4) = arg0;
    p = func_02044268();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(func_02044268(), u8 *, 0x14) + 1) << 2), s32 *, 0x24) = arg1;
    p = func_02044268();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(func_02044268(), u8 *, 0x14) + 1) << 1), u16 *, 0xa4) = arg2;
    M2C_FIELD(func_02044268(), s32 *, 0x1b8) = arg1;
    M2C_FIELD((u8 *)func_02044268() + 0x100, u16 *, 0xb4) = arg2;
    p = func_02044268();
    q = func_02044268();
    M2C_FIELD((u8 *)p + (M2C_FIELD(q, u8 *, 0x14) + 1), u8 *, 0x2d0) = func_0204284c();
    loc[0] = arg0;
    p = func_02044268();
    loc[1] = M2C_FIELD((u8 *)p + (M2C_FIELD(func_02044268(), u8 *, 0x14) + 1), u8 *, 0x2d0);
    for (i = 1; i <= (s32)M2C_FIELD(func_02044268(), u8 *, 0x14); i++) {
        p = func_02044268();
        q = func_02044268();
        r = func_0203f058(7, M2C_FIELD((u8 *)p + (i << 2), s32 *, 0xf4), M2C_FIELD((u8 *)q + (i << 2), s32 *, 0x24), M2C_FIELD((u8 *)func_02044268() + (i << 1), u16 *, 0xa4), (s32)loc, 2);
        if (r) return r;
    }
    func_02042af8(1);
    return 0;
}
#pragma opt_strength_reduction reset
void func_020407fc(s32 arg0,s32 *arg1) {
void func_02007e70(void *,void *,u32); void *func_02044268(void);
u32 n=*arg1+2;
if(n>2) func_02007e70(arg1+1,(u8 *)func_02044268()+0x350,(n-2)*4);
M2C_FIELD(func_02044268(),s32 *,0x348)=n-1;
M2C_FIELD(func_02044268(),s32 *,0x34c)=arg0;
}

void func_0204084c(s32 arg0) {
void func_02042f94(s32); void func_02043008(s32); void *func_02044268(void);
if(M2C_FIELD(func_02044268(),u8 *,0x15)==0) { func_02043008(arg0); return; }
func_02042f94(arg0);
}

s32 func_02040878(s32 arg0, s32 arg1) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    u64 func_02007004(void);
    void *func_02044268(void);
    s32 func_02061784(s32, M2C_UNK);
    s32 func_02060c44(s32 *);
    s32 func_02060b68(s32, M2C_UNK, s32);
    u16 func_02060c4c(void *);
    extern M2C_UNK data_020fc958;
    s32 loc[3];
    void *p, *q;
    s32 u, slot, begin;

    if (arg1 != 0 || (M2C_FIELD(func_02044268(), s32 *, 0x1c) == 0 && M2C_FIELD(func_02044268(), u16 *, 0x1a) == 0)) {
        M2C_FIELD(func_02044268(), s32 *, 0x1bc) = 1;
        p = func_02044268();
        M2C_FIELD(p, u64 *, 0x1c0) = func_02007004();
        M2C_FIELD(func_02044268(), s32 *, 0xf4) = arg0;
        return 0;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 0) {
        u = func_02061784(M2C_FIELD(func_02044268(), s32 *, 0xe4), 0);
        p = func_02044268();
        M2C_FIELD(p, s32 *, 0xf4) = func_02060b68(u, (s32) &data_020fc958, 0);
        p = func_02044268();
        M2C_FIELD(p, s32 *, 0x24) = func_02060c44((s32 *) u);
        p = func_02044268();
        M2C_FIELD(p, u16 *, 0xa4) = func_02060c4c((void *) u);
        p = func_02044268();
        q = func_02044268();
        slot = 1;
        M2C_FIELD(p, s32 *, 0x204) = M2C_FIELD(q, s32 *, 0xf4);
    } else {
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 1) {
            M2C_FIELD(func_02044268(), s32 *, 0xf4) = arg0;
        }
        M2C_FIELD(func_02044268(), s32 *, 0x204) = arg0;
        loc[1] = M2C_FIELD(func_02044268(), s32 *, 0x1c);
        loc[2] = M2C_FIELD(func_02044268(), u16 *, 0x1a);
        slot = 3;
    }
    M2C_FIELD(func_02044268(), s32 *, 0x1c8) = 0x1770;
    p = func_02044268();
    M2C_FIELD(p, u64 *, 0x1cc) = func_02007004();
    M2C_FIELD(func_02044268(), s32 *, 0x1bc) = 0;
    begin = M2C_FIELD(func_02044268(), s32 *, 0x208) != 0 ? 11 : 1;
    loc[0] = M2C_FIELD(func_02044268(), u8 *, 0x15);
    q = func_02044268();
    p = func_02044268();
    return func_0203f058(begin, arg0, M2C_FIELD(q, s32 *, 0x24), M2C_FIELD(p, u16 *, 0xa4), (s32) &loc[0], slot);
}

s32 func_02040a28(s32 arg0, s32 arg1, s32 arg2) {
    (void)arg0; (void)arg1; (void)arg2;
    return 0;
}

s32 func_02040cf0(M2C_UNK arg0) {
 void *func_02044268(); unsigned long long func_02007004(); s32 func_0203ea4c(); s32 func_02040a28(); M2C_UNK func_02044278(M2C_UNK); M2C_UNK func_0203dc38(M2C_UNK,s32);
 void func_02043008(s32); void *p;
 M2C_FIELD(func_02044268(),s32*,0x208)=0;
 M2C_FIELD(func_02044268(),s32*,0x204)=0;
 M2C_FIELD(func_02044268(),u8*,0x1a7)=0;
 p=func_02044268();
 M2C_FIELD(p,unsigned long long*,0x1cc)=func_02007004();
 if(M2C_FIELD(func_02044268(),u8*,0x15)==0) {
 func_02044278(3); func_0203ea4c(0); if(((s32 (*)())func_02043008)())return 0;
 } else if(M2C_FIELD(func_02044268(),u8*,0x15)==1) {
 func_02040a28(0,0,arg0); if(((s32 (*)())func_0204084c)())return 0;
 } else if(M2C_FIELD(func_02044268(),u8*,0x15)==3) {
 func_0203dc38(6,0xfffec5e6);return 0;
 }
 return 1;
}

s32 func_02040dc8(M2C_UNK arg0) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    void *func_02044268();
    s32 temp_r4;
    void *temp_r4_2;

    temp_r4_2 = func_02044268();
    temp_r4 = func_0203f058(5, arg0, M2C_FIELD(temp_r4_2, s32 *, 0x24), M2C_FIELD(func_02044268(), u16 *, 0xA4), 0, 0);
    M2C_FIELD(func_02044268(), s32 *, 0x204) = 0;
    return temp_r4;
}

#pragma opt_strength_reduction off
s32 func_02040e1c(M2C_UNK arg0) {
    u64 func_02007004(void);
    M2C_UNK func_02040a28(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02041be0(M2C_UNK);
    M2C_UNK func_02041ce0(void);
    M2C_UNK func_02041dd4(M2C_UNK);
    s32 func_02042310(s32, M2C_UNK);
    void func_0205ea70(s32);
    M2C_UNK func_0205df50(s32);
    M2C_UNK func_02044278(M2C_UNK);
    void *func_02044268(void);
    s32 var_r4;
    s32 var_r5;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r6;

    if ((M2C_FIELD(func_02044268(), u8 *, 0x17) != 0) && (temp_r4 = func_02044268(), (M2C_FIELD(temp_r4, s32 *, 0x20) == M2C_FIELD(func_02044268(), s32 *, 0x200)))) {
        var_r4 = 0;
    } else {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        M2C_FIELD(func_02044268(), u8 *, 0x17) = 0;
        M2C_FIELD(func_02044268(), s32 *, 0x20) = 0;
        func_0205ea70(M2C_FIELD(func_02044268(), s32 *, 0x10));
        if ((u32) M2C_FIELD(func_02044268(), u8 *, 0xD) < 0x1FU) {
            temp_r6 = func_02044268();
            M2C_FIELD((temp_r6 + ((M2C_FIELD(func_02044268(), u8 *, 0xD) + 1) << 2)), s32 *, 0xF4) = 0;
        }
        M2C_FIELD(func_02044268(), u8 *, 0x3CC) = 0xFF;
        if (M2C_FIELD(func_02044268(), s32 *, 0x19C) != 0) {
            func_0205df50(M2C_FIELD(func_02044268(), s32 *, 0x19C));
            M2C_FIELD(func_02044268(), s32 *, 0x19C) = 0;
        }
        temp_r6 = func_02044268();
        M2C_FIELD(temp_r6, u8 *, 0x14) = (u8) M2C_FIELD(func_02044268(), u8 *, 0xD);
        M2C_FIELD(func_02044268(), s32 *, 0x204) = 0;
    }
    if (var_r4 == 0) {
        if (M2C_FIELD(func_02044268(), u8 *, 0x15) != 3) {
            func_02041ce0();
        }
        goto done;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 0) {
        func_02044278(3);
        M2C_FIELD(func_02044268(), s32 *, 0xE8) = 2;
        temp_r4_2 = func_02044268();
        M2C_FIELD(temp_r4_2, u64 *, 0xEC) = func_02007004();
        goto done;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 1) {
        func_02044278(4);
        func_02040a28(1, 0, 0);
        goto done;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 2) {
        func_02044278(0xE);
        M2C_FIELD(func_02044268(), s32 *, 0x1D8) = 0;
        M2C_FIELD(func_02044268(), s16 *, 0x1B2) = 0;
        func_02041dd4(arg0);
        var_r5 = 1;
        var_r4 = 0xD;
        if ((s32) M2C_FIELD(func_02044268(), u8 *, 0xD) >= 1) {
            for (;;) {
                if (func_02042310(M2C_FIELD((func_02044268() + (var_r5 << 2)), s32 *, 0xF4), var_r4) == 0) {
                    return 0;
                }
                var_r5 += 1;
                if (var_r5 > (s32) M2C_FIELD(func_02044268(), u8 *, 0xD)) {
                    break;
                }
            }
        }
        if (M2C_FIELD(func_02044268(), u8 *, 0xD) == 0) {
            func_02041be0(2);
        }
        goto done;
    }
done:
    return 1;
}
#pragma opt_strength_reduction reset
s32 func_02041038(void) {
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s32 func_02040cf0(M2C_UNK);
    M2C_UNK func_02041ce0();
    M2C_UNK func_02041e44();
    M2C_UNK func_02044278(M2C_UNK);
    M2C_UNK func_0205df50(s32);
    s32 var_r4;
    void *temp_r5;

    var_r4 = 1;
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) == 3) {
        if (M2C_FIELD(func_02044268(), u8 *, 0xD) != 0) {
            func_02041e44();
        }
        func_0203dc38(6, 0xFFFEC5D2);
        return 0;
    }
    temp_r5 = func_02044268();
    M2C_FIELD(temp_r5, u8 *, 0x14) = (u8) M2C_FIELD(func_02044268(), u8 *, 0xD);
    M2C_FIELD(func_02044268(), s32 *, 0x208) = 0;
    if (M2C_FIELD(func_02044268(), s32 *, 0x19C) != 0) {
        func_0205df50(M2C_FIELD(func_02044268(), s32 *, 0x19C));
        M2C_FIELD(func_02044268(), s32 *, 0x19C) = 0;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0xD) != 0) {
        func_02041ce0();
    } else {
        func_02044278(4);
        var_r4 = func_02040cf0(0);
    }
    return var_r4;
}

#pragma opt_strength_reduction off
s32 func_020410f8(void) {
 s32 i,r; void *a,*b,*c,*d;
 s32 func_0203f058(M2C_UNK,M2C_UNK,s32,u16,s32,s32); void func_0205afec(s32); 
 for(i=1;i<=M2C_FIELD(func_02044268(),u8*,0xd);i++){
 a=func_02044268();b=func_02044268();c=func_02044268();d=func_02044268();
 r=func_0203f058(10,M2C_FIELD((u8*)a+(i<<2),s32*,0xf4),M2C_FIELD((u8*)b+(int)i*4,s32*,0x24),M2C_FIELD((u8*)c+(i<<1),u16*,0xa4),(s32)((u8*)d+0x348),M2C_FIELD(func_02044268(),s32*,0x348)+1);
 if(r)return r;
 }
 M2C_FIELD(func_02044268(),u8*,0x17)=0;
 M2C_FIELD(func_02044268(),s32*,0x20)=0;
 M2C_FIELD(func_02044268(),u8*,0x1a8)=1;
 func_0205afec(*M2C_FIELD(func_02044268(),s32**,4));
 M2C_FIELD(func_02044268(),u8*,0x1a8)=0;
 return 0;
}
#pragma opt_strength_reduction reset
