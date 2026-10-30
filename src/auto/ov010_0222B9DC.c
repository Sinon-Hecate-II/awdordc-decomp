/* 19 functions from 0x0222B9DC to 0x0222BD5C (ov010), found by ds-decomp. */
#include "common.h"

typedef struct { u8 value; } Flag;

void func_ov010_0222b9dc(void) {
    M2C_UNK func_020d47f0();
    func_020d47f0();
}

void func_ov010_0222b9e8(void) {
    M2C_UNK func_020852e0();
    M2C_UNK func_020d47d0();
    s32 func_ov010_022282b4(M2C_UNK);
    if (func_ov010_022282b4(0) == 0) {
        func_020d47d0();
    } else {
        func_020d47f0();
    }
    func_020852e0();
}

void func_ov010_0222ba10(s8 arg0, s16 arg1, M2C_UNK arg2) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_01ffa770(M2C_UNK *);
    s32 func_0208206c();
    extern M2C_UNK data_ov010_0222c6c4;
    extern M2C_UNK data_ov010_0222c928;
    void *temp_r0;

    if (func_ov010_022282b4(2) != 0) {
        func_020d47d0();
        return;
    }
    if (func_01ffa770(&data_ov010_0222c6c4) != 0) {
        return;
    }
    temp_r0 = func_01ffa42c(&data_ov010_0222c6c4, arg2);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov010_0222c928;
    M2C_FIELD(temp_r0, s8 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x35) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x36) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x38) = func_0208206c();
    M2C_FIELD(temp_r0, s8 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
}

void func_ov010_0222ba94(s8 arg0, s16 arg1, M2C_UNK arg2) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_01ffa770(M2C_UNK *);
    s32 func_0208206c();
    extern M2C_UNK data_ov010_0222c5d4;
    extern M2C_UNK data_ov010_0222c928;
    void *temp_r0;
    if (func_ov010_022282b4(0) == 0) {
        func_020d47d0();
        return;
    }
    if (func_01ffa770(&data_ov010_0222c5d4) != 0) return;
    temp_r0 = func_01ffa42c(&data_ov010_0222c5d4, arg2);
    if (temp_r0 == NULL) return;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov010_0222c928;
    M2C_FIELD(temp_r0, s8 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x35) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x36) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x38) = func_0208206c();
    M2C_FIELD(temp_r0, s8 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
}

void func_ov010_0222bb18(M2C_UNK arg0) {
    s32 func_0206527c(s32, s32, M2C_UNK);
    M2C_UNK func_ov010_02229a08();
    s32 func_ov010_02229b00();
    s32 func_ov010_02229b48();
    M2C_UNK func_ov010_02229eb4(M2C_UNK);
    s32 temp_r4;

    if (func_ov010_022282b4(3) == 0) {
        return;
    }
    temp_r4 = func_ov010_02229b00();
    func_ov010_02229a08();
    if (func_0206527c(temp_r4, func_ov010_02229b48(), 0x6C) == 0) {
        return;
    }
    func_ov010_02229eb4(arg0);
}

void func_ov010_0222bb64(M2C_UNK arg0) {
    extern M2C_UNK data_ov010_0222c93c;
    extern M2C_UNK data_ov010_0222c4dc;
    M2C_UNK **temp_r0;

    temp_r0 = func_01ffa3dc(&data_ov010_0222c4dc, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov010_0222c93c;
    }
}

void func_ov010_0222bb8c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c4dc;
    func_01ffa9e4(&data_ov010_0222c4dc);
}

s32 func_ov010_0222bba0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222bbb4(void) {

}

s32 func_ov010_0222bbb8(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222bbcc(void) {

}

s32 func_ov010_0222bbd0(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov010_0222bbe4(void) {

}

void *func_ov010_0222bbe8(void *arg0, void *arg1) {
    void *func_ov010_0222bc88(void *, M2C_UNK, u32, void *);
    typedef struct { u32 words[3]; } Copy;
    s32 var_r1;
    u32 var_r2;
    var_r1 = ((u32)(M2C_FIELD(arg0, s32 *, 0) << 31) >> 31) != 0;
    if (var_r1 == 0 && ((u32)(M2C_FIELD(arg1, s32 *, 0) << 31) >> 31) == 0) {
        *(Copy *)arg0 = *(Copy *)arg1;
        return arg0;
    }
    var_r2 = var_r1 ? M2C_FIELD(arg0, u32 *, 4) : (u32)(M2C_FIELD(arg0, u8 *, 0) << 24) >> 25;
    return func_ov010_0222bc88(arg0, 0, var_r2, arg1);
}

void func_ov010_0222bc54(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_ov010_0222bcd8(void *, M2C_UNK, u32, M2C_UNK);
    u32 var_r2;
    if (((u32)(M2C_FIELD(arg0, s32 *, 0) << 0x1F) >> 0x1F) == 0) {
        var_r2 = (u32)(M2C_FIELD(arg0, u8 *, 0) << 0x18) >> 0x19;
    } else {
        var_r2 = M2C_FIELD(arg0, u32 *, 4);
    }
    func_ov010_0222bcd8(arg0, 0, var_r2, arg1);
}

void *func_ov010_0222bc88(void *arg0, M2C_UNK arg1, u32 arg2, void *arg3) {
    void *func_0206fc18(void *, M2C_UNK, u32, void *, void *, Flag);
    u32 len;
    u8 *start;
    Flag unused;
    if (((u32)(M2C_FIELD(arg3, s32 *, 0) << 31) >> 31) != 0) {
        start = M2C_FIELD(arg3, u8 **, 8);
        len = M2C_FIELD(arg3, u32 *, 4);
    } else {
        start = (u8 *)arg3 + 1;
        len = (u32)(M2C_FIELD(arg3, u8 *, 0) << 24) >> 25;
    }
    return func_0206fc18(arg0, arg1, arg2, start, start + len, unused);
}

M2C_UNK func_ov010_0222bcd8(void *arg0, M2C_UNK arg1, u32 arg2, M2C_UNK arg3) {
    void *func_0206fc18(void *, M2C_UNK, u32, void *, void *, Flag);
    s32 func_02068c34(M2C_UNK);
    Flag unused;
    return (M2C_UNK)func_0206fc18(arg0, arg1, arg2, (void *)arg3, (u8 *)arg3 + func_02068c34(arg3), unused);
}

s32 func_ov010_0222bd24(s32 arg0) {
    M2C_UNK func_0206fa14(s32);
    func_0206fa14(arg0 + 0x44);
    return arg0;
}

s32 func_ov010_0222bd3c(s32 arg0) {
    func_0206fa14(arg0 + 0x44);
    func_02082040(arg0);
    return arg0;
}

