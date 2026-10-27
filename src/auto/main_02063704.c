/* 22 functions from 0x02063704 to 0x02064684 (main), found by ds-decomp. */
#include "common.h"

typedef struct M2C_S_02063BD0 {
    u32 field_0;
} M2C_S_02063BD0;

/* Add (or update) an entry parsed from the input buffer. */
s32 func_02063704(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02061090(void *, s32, u16);
    s32 func_02061168();
    M2C_UNK func_02061a38(void *, s32);
    s32 func_02061ac8(void *, s32, u16);
    s32 func_02061bc8(void *, s32);
    M2C_UNK func_020629bc(void *, M2C_UNK, s32, s32 *, u16 *);
    s32 func_02062a2c(void *, s32, M2C_UNK, s32, s32);
    s32 entry;
    u16 kind;
    s32 found;
    s32 count;

    if (arg2 < 5) {
        return 4;
    }
    func_020629bc(arg0, arg1, arg2, &count, &kind);
    found = func_02061ac8(arg0, count, kind);
    if (found == -1) {
        entry = func_02061090(arg0, count, kind);
        if (func_02061168() != 0) {
            return 5;
        }
        goto apply;
    }
    entry = func_02061bc8(arg0, found);
apply:
    if (func_02062a2c(arg0, entry, arg1, arg2, 0) < 0) {
        return 4;
    }
    if (found == -1) {
        func_02061a38(arg0, entry);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK, s32, s32), 0x488)(arg0, 1, entry, M2C_FIELD(arg0, s32 *, 0x494));
    return 0;
}

s32 func_020639c0(void *arg0) {
    s32 func_02049534(s32);
    s32 func_020497cc(s32, s32, s32, M2C_UNK);
    M2C_UNK func_0206006c(void *, s32, s32);
    M2C_UNK func_02061efc(void *);
    s32 func_02062e30(void *);
    s32 func_020637fc(void *);
    s32 temp_r0;
    s32 var_r4;
    s32 temp_r5;

    if (func_02049534(M2C_FIELD(arg0, s32 *, 0x4B0)) == 0) {
        return 0;
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x80);
    temp_r0 = func_020497cc(M2C_FIELD(arg0, s32 *, 0x4B0), M2C_FIELD(arg0, s32 *, 0x7C) + temp_r5, 0x1000 - temp_r5, 0);
    if ((u32) (temp_r0 + 1) <= 1U) {
        func_02061efc(arg0);
        return 3;
    }
    var_r4 = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = M2C_FIELD(arg0, s32 *, 0x80) + temp_r0;
    if (M2C_FIELD(arg0, s32 *, 0) != 2 && M2C_FIELD(arg0, s32 *, 0x5C8) > 0) {
        func_0206006c((u8 *)arg0 + 0x4BC, M2C_FIELD(arg0, s32 *, 0x7C) + temp_r5, M2C_FIELD(arg0, s32 *, 0x80) - temp_r5);
    }
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        var_r4 = func_02062e30(arg0);
    }
    if (var_r4 != 0) {
        return var_r4;
    }
    if (M2C_FIELD(arg0, s32 *, 0) == 2 && M2C_FIELD(arg0, s32 *, 0x80) > 0) {
        return func_020637fc(arg0);
    }
    return 0;
}

s32 func_02063dac(void *arg0) {
    void func_02061bdc(void *);
    s32 func_020639c0(void *);
    s32 func_02063c88(void *);
    s32 temp_r0;

    func_02061bdc(arg0);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_r0) {
    case 2:
    case 3:
        return func_020639c0(arg0);
    case 0:
        return func_02063c88(arg0);
    case 1:
    default:
        return 0;
    }
}

M2C_UNK func_02063df8(void) {
    M2C_UNK func_02068b04(M2C_UNK);
    void func_02063e1c(M2C_UNK);
    extern M2C_UNK data_0213e4c4;
    func_02068b04(1);
    M2C_FIELD(&data_0213e4c4, s32 *, 0xC) = 1;
    func_02063e1c(1);
}

void func_02063e1c(M2C_UNK arg0) {
    M2C_UNK func_02063e68(M2C_UNK);
    M2C_UNK func_02074074();
    extern M2C_UNK data_0213e4c4;
    if (M2C_FIELD(&data_0213e4c4, s32 *, 0xC) == 0) {
        func_02074074();
        if (M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4) != NULL) {
            M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4)();
            M2C_FIELD(&data_0213e4c4, M2C_UNK (**)(), 4) = NULL;
        }
    }
    func_02063e68(arg0);
}

void func_02063f90(void) {
    M2C_UNK func_0207191c(s32);
    extern s32 data_021002ec;
    func_0207191c(data_021002ec);
}

s32 func_0206409c(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    return var_r0;
}

void func_020640a8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02063df8();
    M2C_UNK func_0206743c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_021002b0;
    func_0206743c(&data_021002b0, arg0, arg1, arg2, arg3);
    func_02063df8();
}

void func_020640e4(void) {

}

void func_020640e8(M2C_UNK, M2C_UNK *) {

}

void func_020640ec(void *arg0) {
    s32 temp_r3;

    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r3;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (temp_r3 - (M2C_FIELD(arg0, s32 *, 0x18) & M2C_FIELD(arg0, s32 *, 0x2C)));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
}

s32 func_0206411c(void *arg0, M2C_UNK *arg1, M2C_UNK arg2) {
    M2C_UNK temp_r0;

    func_020640ec(arg0);
    if (arg2 == 1) {
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x20);
    }
    temp_r0 = M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK), 0x3C)(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x48));
    if (temp_r0 == 2) {
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(arg0, s32 *, 0x28);
    }
    if (temp_r0 != 0) {
        return temp_r0;
    }
    M2C_FIELD(arg0, s32 *, 0x18) += M2C_FIELD(arg0, s32 *, 0x28);
    if (((u32) M2C_FIELD(arg0, s32 *, 4) << 0x13) >> 0x1F == 0) {
        func_020640e8(M2C_FIELD(arg0, s32 *, 0x1C), &M2C_FIELD(arg0, s32 *, 0x28));
    }
    return 0;
}

s32 func_02064230(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, void *arg3) {
    s32 func_02006680(void *);
    M2C_UNK func_02006564();
    M2C_UNK func_020065e8();
    s32 func_0206433c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u8 data_021001cc[];
    extern u8 data_0213e61c[];
    extern M2C_UNK data_0212dca4;
    extern s32 data_0213e5d4[];
    extern s32 data_0213e5f8[];

    u32 n;
    s32 result;
    void *thread;
    s32 owner;

    if (arg3 == (void *)data_021001cc) {
        n = 2;
    } else {
        n = 5;
    }

    if (func_02006680(data_0213e61c + n * 24) == 0) {
        data_0213e5d4[n] = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0x6C);
        data_0213e5f8[n] = 1;
    } else if ((thread = M2C_FIELD(&data_0212dca4, void **, 4),
               owner = data_0213e5d4[n],
               owner == M2C_FIELD(thread, s32 *, 0x6C))) {
        data_0213e5f8[n]++;
    } else {
        func_02006564(data_0213e61c + n * 24);
        data_0213e5d4[n] = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), s32 *, 0x6C);
        data_0213e5f8[n] = 1;
    }

    result = func_0206433c(arg0, arg1, arg2, arg3);

    if (--data_0213e5f8[n] == 0) {
        func_020065e8(data_0213e61c + n * 24);
    }

    return result;
}

