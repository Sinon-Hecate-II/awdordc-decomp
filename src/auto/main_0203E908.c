/* 10 functions from 0x0203E908 to 0x0203F45C (main), found by ds-decomp. */
#include "common.h"
typedef M2C_UNK (*fmt_fn_t)(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, M2C_UNK);


void func_0203e908(u8 arg0, u8 arg1, s32 arg2, s32 arg3) {
    void func_0203e570(s32);
    void *func_02044268(void);
    void func_0205fdbc(s32, s8 *);
    extern M2C_UNK data_020fc958;
    extern M2C_UNK data_020fc960;
    extern M2C_UNK data_020fc96c;
    extern M2C_UNK data_020fc978;
    extern M2C_UNK data_020fc984;
    func_0203e570(0);
    M2C_FIELD(func_02044268(), u8 *, 0x15) = arg0;
    M2C_FIELD(func_02044268(), u8 *, 0x16) = arg1;
    M2C_FIELD(func_02044268(), s32 *, 0x464) = arg2;
    M2C_FIELD(func_02044268(), s32 *, 0x468) = arg3;
    M2C_FIELD(func_02044268(), u8 *, 0x17D) = 0;
    M2C_FIELD(func_02044268(), u8 *, 0x2D0) = 0;
    func_0205fdbc(0x32, (s8 *)&data_020fc958);
    func_0205fdbc(0x33, (s8 *)&data_020fc960);
    func_0205fdbc(0x34, (s8 *)&data_020fc96c);
    func_0205fdbc(0x35, (s8 *)&data_020fc978);
    func_0205fdbc(0x36, (s8 *)&data_020fc984);
}

void func_0203e9b0(void) {
    M2C_UNK func_020376d8(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_0203bd0c();
    M2C_UNK func_020427f4();
    void *func_02044268();
    M2C_UNK func_02044278(M2C_UNK);
    M2C_UNK func_020614b0(s32);
    extern M2C_UNK data_0213d39c;
    if (func_02044268() == NULL) {
        return;
    }
    if (M2C_FIELD(func_02044268(), s32 *, 0xE4) != 0) {
        if (M2C_FIELD(&data_0213d39c, s32 *, 0x18) != 0) {
            M2C_FIELD(&data_0213d39c, s32 *, 0x14) = 1;
        } else {
            func_020614b0(M2C_FIELD(func_02044268(), s32 *, 0xE4));
            M2C_FIELD(func_02044268(), s32 *, 0xE4) = 0;
        }
    }
    func_0203bd0c();
    func_02044278(0);
    if (M2C_FIELD(&data_0213d39c, s32 *, 8) != 0) {
        func_020376d8(4, M2C_FIELD(&data_0213d39c, s32 *, 8), 0);
        M2C_FIELD(&data_0213d39c, s32 *, 8) = 0;
    }
    func_020427f4();
    M2C_FIELD(func_02044268(), s8 *, 0x18) = 1;
}

void func_0203ec48(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_0200567c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, M2C_UNK *, s32, s32, s32, M2C_UNK *, s32, M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_020fc958;
    extern M2C_UNK data_020fc960;
    extern M2C_UNK data_020fc96c;
    extern M2C_UNK data_020fc978;
    extern M2C_UNK data_020fc9a4;
    func_0200567c(arg0, 0x100, &data_020fc9a4, &data_020fc978, 3, &data_020fc958, arg1, arg2, arg2, &data_020fc960, arg3, &data_020fc96c, &data_020fc958);
}

s32 func_0203ef9c(void *arg0) {
    s32 func_02043008();
    s32 func_0205b048(s32);
    s32 func_0205d4d8(s32, M2C_UNK, M2C_UNK);
    s32 func_0205de88(s32, s32, u8, M2C_UNK *, M2C_UNK *, void *);
    M2C_UNK func_02061690(s32, s32, u16, s32);
    extern M2C_UNK func_02043e0c;
    extern M2C_UNK func_02043e10;
    s32 temp_r0;
    s32 var_r6;
    void *temp_r4;

    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        temp_r4 = func_02044268();
        func_02061690(M2C_FIELD(temp_r4, s32 *, 0xE4), func_0205d4d8(M2C_FIELD(arg0, s32 *, 4), 0, 0), M2C_FIELD(arg0, u16 *, 2), M2C_FIELD(arg0, s32 *, 8));
        if (func_02043008() != 0) {
            return 2;
        }
    }
    var_r6 = 0;
loop_4:
    temp_r0 = func_0205de88(func_0205b048(*M2C_FIELD(func_02044268(), s32 **, 4)), M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, u8 *, 0), &func_02043e0c, &func_02043e10, arg0);
    if (temp_r0 == 0) {
        return temp_r0;
    }
    if (temp_r0 != 3) {
        return temp_r0;
    }
    var_r6 += 1;
    if (var_r6 >= 5) {
        return temp_r0;
    }
    goto loop_4;
}

void func_0203f31c(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, u8 *arg3) {
    M2C_UNK func_0200567c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32, M2C_UNK *, s32, s32, s32, M2C_UNK *, s32, M2C_UNK *, M2C_UNK *);
    s32 func_02068c34(u8 *);
    void func_02008048(u8 *, u8 *, u32);
    void func_0204e634(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_020fca08;
    extern M2C_UNK data_020fca10;
    extern M2C_UNK data_020fca18;
    char buf[0x200];
    s32 len;
    M2C_UNK (*fmt)(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, M2C_UNK) =
        (M2C_UNK (*)(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, M2C_UNK))func_0200567c;
    len = (s32)fmt((M2C_UNK)buf, 0x200, (M2C_UNK)&data_020fca08, (M2C_UNK)&data_020fca10, 3, (M2C_UNK)&data_020fca18);
    buf[len] = (char)arg1;
    buf[len + 1] = 0;
    if (arg3 != 0) {
        s32 alen = func_02068c34(arg3);
        func_02008048(arg3, (u8 *)buf + len + 1, alen);
        buf[len + 1 + alen] = 0;
    }
    func_0204e634(arg0, arg2, (M2C_UNK)buf);
}

s32 func_0203f3c0(u8 *arg0, u8 *arg1, s32 arg2) {
    s8 *func_02068ee0(s8 *, s32);
    void func_02008048(u8 *, u8 *, u32);
    u8 *p = arg1;
    u8 *end = (u8 *)func_02068ee0((s8 *)arg1, 0);
    s32 count = 0;
    if (arg2 > 0) {
        s8 *f;
        do {
            f = func_02068ee0((s8 *)p, '/');
            if (f == 0) {
                return -1;
            }
            count += 1;
            p = (u8 *)f + 1;
        } while (count < arg2);
    }
    {
        u8 *f2 = (u8 *)func_02068ee0((s8 *)p, '/');
        if (f2 == 0) {
            f2 = end;
        }
        if (p == f2) {
            return -1;
        }
        {
            s32 len = (s32)(f2 - p);
            func_02008048(p, arg0, len);
            arg0[len] = 0;
            return len;
        }
    }
}

