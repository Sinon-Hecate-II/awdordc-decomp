/* 45 functions from 0x0208FE7C to 0x02090E0C (main), found by ds-decomp. */
#include "common.h"
void func_02090574(void);

s32 func_0208fe7c(s32 arg0, s32 arg1) {
    s32 func_0208fe30(s32);

    if (func_0208fe30(arg0) != 0) {
        func_0208fea0(arg1);
    }
    return 1;
}

s32 func_0208fea0(M2C_UNK arg0) {
    M2C_UNK func_0208febc(M2C_UNK, M2C_UNK, M2C_UNK);
    func_0208febc(-1, arg0, 0);
    return 1;
}

s32 func_0208febc(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157834;
    u8 func_0208ff2c(void);
    M2C_UNK func_0202ad04(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_0208ff2c() == 0) {
        return 0;
    }
    if (arg0 != -1) {
        func_0202ad04(&data_02157834, arg0, 0);
    }
    func_0202ad04(&data_02157834, arg1, arg2);
    return 1;
}

u8 func_0208ff2c(void) {
    extern M2C_UNK data_02157830;
    u8 var_r0;

    if (M2C_FIELD(&data_02157830, s32 *, 4) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_0208ff4c(s32 arg0) {
    extern M2C_UNK data_02157830;
    extern s32 data_027e15bc;
    u8 var_r0;

    if (func_0208ff2c() == 0) {
        return 0;
    }
    if ((u32) data_027e15bc <= (u32) (M2C_FIELD(&data_02157830, s32 *, 0x1C) + arg0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_0208ff94(M2C_UNK arg0) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157834;
    u8 func_0208ff2c(void);
    M2C_UNK func_0202ad90(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_0208ff2c() == 0) {
        return 0;
    }
    func_0202ad90(&data_02157834, 0xFFFF, arg0);
    return 1;
}

s32 func_0208ffe4(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157850;
    M2C_UNK func_0208fd40(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02090034(s32, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    func_02090034(arg0, 0);
    func_0208fd40(&data_02157850 + arg0, arg1, arg2);
    return 1;
}

s32 func_02090034(s32 arg0, M2C_UNK arg1) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157850;
    u8 func_02090084(s32);
    M2C_UNK func_0208fd94(M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_02090084(arg0) == 0) {
        return 0;
    }
    func_0208fd94(&data_02157850 + arg0, arg1);
    return 1;
}

u8 func_02090084(s32 arg0) {
    extern M2C_UNK data_02157850;
    u8 var_r0;

    if ((&data_02157850)[arg0] != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020900a4(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157850;
    u8 func_02090084(s32);
    M2C_UNK func_0202ad50(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_02090084(arg0) == 0) {
        return 0;
    }
    func_0202ad50(&data_02157850 + arg0, (M2C_UNK)(u16)arg1, arg2);
    return 1;
}

s32 func_02090100(s32 arg0, s32 arg1) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157850;
    u8 func_02090084(s32);
    M2C_UNK func_0202ad90(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_02090084(arg0) == 0) {
        return 0;
    }
    func_0202ad90(&data_02157850 + arg0, 0xFFFF, arg1);
    return 1;
}

s32 func_02090158(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157850;
    u8 func_02090084(s32);
    M2C_UNK func_0202ad04(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_02090084(arg0) == 0) {
        return 0;
    }
    func_0202ad04(&data_02157850 + arg0, arg1, arg2);
    return 1;
}

s32 func_020901b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 func_0208ffe4(s32, M2C_UNK, M2C_UNK);
    s32 func_02090158(s32, s32, s32);

    if (func_0208ffe4(arg0, arg1, arg2) != 0) {
        func_02090158(arg0, arg3, 0);
    }
    return 1;
}

s32 func_020901e0(s32 arg0) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_02157838;
    extern M2C_UNK data_0215783c;
    s32 func_0202d91c(M2C_UNK, M2C_UNK, s32);
    s32 func_0202d330(M2C_UNK, s32);
    
    s32 var_r4;
    u16 val;

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    val = (u16) arg0;
    if (arg0 & 0x10000) {
        var_r4 = func_0202d91c(&data_02157838, val, 0) & 0xFF;
        func_02090574();
    } else {
        var_r4 = func_0202d330(&data_0215783c, val) & 0xFF;
    }
    if (var_r4 == 0) {
        return 0;
    }
    return 1;
}

s32 func_02090248(s32 arg0) {
extern M2C_UNK data_02157830, data_0215783c, data_02157838;
u8 func_02090350(void); u8 func_02090370(void);
M2C_UNK func_0202ac60(M2C_UNK,M2C_UNK);
void func_0202d944(M2C_UNK,s32);
if(M2C_FIELD(&data_02157830,u8 *,0)==0) return 0;
if(func_02090350()!=0) func_0202ac60(&data_0215783c,arg0);
if(func_02090370()!=0) func_0202d944(&data_02157838,arg0);
return 1;
}

s32 func_020902a8(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_02157830;
    extern M2C_UNK data_0215783c;
    extern M2C_UNK data_02157838;
    u8 func_02090350(void);
    u8 func_02090370(void);
    M2C_UNK func_0202ad04(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0202d960(M2C_UNK, M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return 0;
    }
    if (func_02090350() != 0) {
        if (arg0 != -1) {
            func_0202ad04(&data_0215783c, arg0, 0);
        }
        func_0202ad04(&data_0215783c, arg1, arg2);
    }
    if (func_02090370() != 0) {
        if (arg0 != -1) {
            func_0202d960(&data_02157838, arg0, 0);
        }
        func_0202d960(&data_02157838, arg1, arg2);
    }
    return 1;
}

u8 func_02090350(void) {
    extern M2C_UNK data_02157830;
    u8 var_r0;

    if (M2C_FIELD(&data_02157830, s32 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02090370(void) {
    extern M2C_UNK data_02157830;
    u8 var_r0;

    if (M2C_FIELD(&data_02157830, s32 *, 0x8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02090390(void) {
    extern M2C_UNK data_02157830;
    void func_0202a9f0(void);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return;
    }
    func_0202a9f0();
}

void func_020903b0(void) {
    extern M2C_UNK data_02157830;
    s32 func_0202c658(void *);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return;
    }
    func_0202c658(M2C_FIELD(&data_02157830, void **, 0x10));
}

void func_020903d4(void) {
    void func_020903f0(s32, s32);
    M2C_UNK func_02090448(M2C_UNK);
    func_020903f0(1, 0x24);
    func_02090448(1);
}

void func_020903f0(s32 arg0, s32 arg1) {
    extern M2C_UNK data_02157830;
    s32 func_0202c784(M2C_UNK *);
    s32 func_0202c860(M2C_UNK, M2C_UNK);
    s32 func_0202c88c(M2C_UNK, M2C_UNK);

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return;
    }
    func_0202c784(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
    func_0202c860(arg0, M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
    func_0202c88c(arg1, M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
    func_0202c784(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
}

M2C_UNK func_02090448(M2C_UNK arg0) {
    extern M2C_UNK data_02157830;
    s32 func_0202c784(M2C_UNK *);
    M2C_UNK func_0202c848(M2C_UNK, M2C_UNK);

    func_0202c784(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
    func_0202c848(arg0, M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
    func_0202c784(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
}

void func_02090480(s32 arg0) {
    M2C_UNK func_0202c778(M2C_UNK);
    M2C_UNK func_0202c6a4(M2C_UNK, s32);
    extern M2C_UNK data_02157830;

    if (M2C_FIELD(&data_02157830, u8 *, 0) == 0) {
        return;
    }
    {
        M2C_UNK r0;
        s32 diff;

        r0 = func_0202c778(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10));
        if (r0 == 0) {
            return;
        }
        diff = r0 - arg0;
        if (diff < 0) {
            diff = 0;
        }
        func_0202c6a4(M2C_FIELD(&data_02157830, M2C_UNK *, 0x10), diff);
    }
}

s32 func_020904c4(void) {
    extern M2C_UNK data_02157914;
    s32 var_r0;
    s32 var_r2;

    var_r0 = 0x7F;
    var_r2 = 0;
    do {
        var_r0 = var_r0 * M2C_FIELD(&data_02157914, u8 *, var_r2);
        var_r2 += 1;
    } while (var_r2 < 3);
    var_r2 = 0;
    do {
        var_r0 = var_r0 / 0x7F;
        var_r2 += 1;
    } while (var_r2 < 3);
    return var_r0;
}

s32 func_0209051c(void) {
    extern M2C_UNK data_02157910;
    s32 var_r0;
    s32 var_r2;

    var_r0 = 0x7F;
    var_r2 = 0;
    do {
        var_r0 = var_r0 * M2C_FIELD(&data_02157910, u8 *, var_r2);
        var_r2 += 1;
    } while (var_r2 < 3);
    var_r2 = 0;
    do {
        var_r0 = var_r0 / 0x7F;
        var_r2 += 1;
    } while (var_r2 < 3);
    return var_r0;
}

void func_02090574(void) {
extern M2C_UNK data_02157830;
extern M2C_UNK data_02157838;
s32 func_020904c4(void);
void func_0202d994(volatile s32 *, s32, s32);
if(M2C_FIELD(&data_02157830,s32 *,8)!=0) {
s32 value=func_020904c4();
func_0202d994(&data_02157838,0,value);
func_0202d994(&data_02157838,1,value);
}
}

void func_020905bc(void) {
    M2C_UNK func_0202ab7c(M2C_UNK, s32);
    s32 func_020904c4();

    func_0202ab7c(0, func_020904c4());
    func_02090574();
}

void func_020905d8(void) {
    s32 func_0209051c();
    s32 temp_r4;
    s32 var_r5;

    temp_r4 = func_0209051c();
    var_r5 = 1;
    do {
        func_0202ab7c(var_r5, temp_r4);
        var_r5 += 1;
    } while (var_r5 <= 0xB);
}

void func_02090604(void) {
    extern M2C_UNK data_02157914;
    extern M2C_UNK data_02157910;
    void func_020905bc(void);
    void func_020905d8(void);
    u8 *var_r2;
    u8 *var_r3;
    s32 var_r1;

    var_r2 = (u8 *)&data_02157914;
    var_r3 = (u8 *)&data_02157910;
    var_r1 = 0;
    do {
        var_r1 += 1;
        *var_r2++ = 0x7F;
        *var_r3++ = 0x7F;
    } while (var_r1 < 3);
    func_020905bc();
    func_020905d8();
}

void func_02090640(s32 arg0, s32 arg1) {
    extern M2C_UNK data_02157914;
    s32 var_r1;

    var_r1 = arg1;
    if (var_r1 > 0x7F) {
        var_r1 = 0x7F;
    } else if (var_r1 < 0) {
        var_r1 = 0;
    }
    M2C_FIELD(&data_02157914, u8 *, arg0) = var_r1;
    func_020905bc();
}

void func_0209066c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_02157910;
    s32 var_r1;

    var_r1 = arg1;
    if (var_r1 > 0x7F) {
        var_r1 = 0x7F;
    } else if (var_r1 < 0) {
        var_r1 = 0;
    }
    M2C_FIELD(&data_02157910, u8 *, arg0) = var_r1;
    func_020905d8();
}

u8 func_02090698(s32 arg0) {
    extern M2C_UNK data_02157914;
    return M2C_FIELD(&data_02157914, u8 *, arg0);
}

void func_0209075c(void *arg0, void *arg1, s32 arg2) {
    s32 *temp_ip;
    s32 *temp_ip_2;
    void *temp_r2;
    void *var_r1;
    void *var_r3;

    var_r1 = arg1;
    var_r3 = M2C_FIELD(var_r1, void **, 8);
    if (var_r3 != NULL) {
        do {
            var_r1 = var_r3;
            var_r3 = M2C_FIELD(var_r3, void **, 8);
        } while (var_r3 != NULL);
    }
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) M2C_FIELD(var_r1, s32 **, 0xC);
    M2C_FIELD(arg0, u8 *, 0x2C) = arg2;
    temp_ip = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, void **, 0x14) = (void *) ((s8 *) temp_ip + *temp_ip);
    temp_ip_2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, void **, 0x10) = (void *) ((s8 *) temp_ip_2 + M2C_FIELD(temp_ip_2 + M2C_FIELD(arg0, u8 *, 0x2C), s32 *, 4));
    M2C_FIELD(arg0, s16 *, 0x20) = (s16) M2C_FIELD(var_r1, s16 *, 0x20);
    M2C_FIELD(arg0, s16 *, 0x22) = (s16) M2C_FIELD(var_r1, s16 *, 0x22);
    M2C_FIELD(arg0, u16 *, 0x24) = (u16) M2C_FIELD(var_r1, u16 *, 0x24);
    M2C_FIELD(arg0, u16 *, 0x26) = (u16) M2C_FIELD(var_r1, u16 *, 0x26);
    M2C_FIELD(arg0, u16 *, 0x28) = (u16) M2C_FIELD(var_r1, u16 *, 0x28);
    M2C_FIELD(arg0, s8 *, 0x2A) = (s8) M2C_FIELD(var_r1, s8 *, 0x2A);
    M2C_FIELD(arg0, u8 *, 0x2D) = (u8) M2C_FIELD(var_r1, u8 *, 0x2D);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(var_r1, s32 *, 0);
    M2C_FIELD(arg0, void **, 4) = var_r1;
    temp_r2 = M2C_FIELD(var_r1, void **, 8);
    M2C_FIELD(arg0, void **, 8) = temp_r2;
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 4) = arg0;
    }
    M2C_FIELD(var_r1, void **, 8) = arg0;
}

void func_02090810(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0x20) = (u16)arg1;
    M2C_FIELD(arg0, u16 *, 0x22) = (u16)arg2;
    arg0 = M2C_FIELD(arg0, void **, 0x8);
    if (arg0 != 0) {
        func_02090810(arg0, arg1, arg2);
    }
}

void func_02090830(void *arg0) {
    M2C_UNK func_02082040();
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 8) = (void *) M2C_FIELD(arg0, void **, 8);
        temp_r2_2 = M2C_FIELD(arg0, void **, 8);
        if (temp_r2_2 != NULL) {
            M2C_FIELD(temp_r2_2, void **, 4) = (void *) M2C_FIELD(arg0, void **, 4);
        }
        if (arg0 == NULL) {
            return;
        }
        func_02082040();
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x38) = (void *) M2C_FIELD(arg0, void **, 8);
    temp_r2_3 = M2C_FIELD(arg0, void **, 8);
    if (temp_r2_3 != NULL) {
        M2C_FIELD(temp_r2_3, void **, 4) = NULL;
    }
    if (arg0 == NULL) {
        return;
    }
    func_02082040();
}

void func_02090894(void **arg0) {
    M2C_UNK func_02082040(void **);
    void func_02090a88(void *);
    void **var_r4;
    void **temp_r5;

    var_r4 = arg0;
    func_02090a88(arg0);
    if (arg0 != NULL) {
        do {
            temp_r5 = M2C_FIELD(var_r4, void ***, 8);
            if (var_r4 != NULL) {
                func_02082040(var_r4);
            }
            var_r4 = temp_r5;
        } while (temp_r5 != NULL);
    }
    M2C_FIELD(*arg0, s32 *, 0x38) = 0;
}

void func_020908dc(void *arg0) {
    void func_02090830(void *);
    void func_0209075c(void *, void *, s32);
    void *func_02082028(s32);
    u8 *cur;
    u8 *node;
    void *next;

    next = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        goto decr;
    }
    goto skip;
    for (;;) {
        if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u8 *, 3) != 0) {
            switch (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u8 *, 2)) {
            case 0:
            case 0xFF:
                func_02090830(arg0);
                goto done;
            case 1:
                M2C_FIELD(arg0, u8 **, 0x10) = (u8 *)M2C_FIELD(arg0, s32 **, 0xC)
                     + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC) + M2C_FIELD(arg0, u8 *, 0x2C), s32 *, 4);
                goto skip;
            case 2:
                goto done;
            case 3:
                break;
            case 4:
                node = (u8 *)M2C_FIELD(arg0, s32 **, 0xC)
                     + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC) + M2C_FIELD(arg0, u8 *, 0x2C), s32 *, 4);
                while (M2C_FIELD(node, u8 *, 3) == 0 || M2C_FIELD(node, u8 *, 2) != 0xFF) {
                    if (M2C_FIELD(node, u8 *, 3) != 0 && M2C_FIELD(node, u8 *, 2) == 3
                        && M2C_FIELD(node, s16 *, 6) == M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6)) {
                        M2C_FIELD(arg0, void **, 0x10) = node;
                        break;
                    }
                    M2C_FIELD(arg0, u8 **, 0x10) = M2C_FIELD(arg0, u8 **, 0x10) + 0x10;
                }
                goto skip;
            case 0x10:
                if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6) > 0) {
                    node = func_02082028(0x30);
                    if (node != NULL) {
                        func_0209075c(node, arg0, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6) - 1);
                    }
                    next = M2C_FIELD(arg0, void **, 8);
                }
                break;
            case 0x11:
                M2C_FIELD(arg0, u8 *, 0x2B) = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u16 *, 6);
                break;
            default:
                break;
            }
        }
        M2C_FIELD(arg0, u8 **, 0x10) = M2C_FIELD(arg0, u8 **, 0x10) + 0x10;
    skip:
        cur = M2C_FIELD(arg0, u8 **, 0x10);
        if (M2C_FIELD(cur, u8 *, 3) != 0 || M2C_FIELD(cur, u16 *, 0) == 0) {
            continue;
        }
        M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(cur, u16 *, 0);
        M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(arg0, s32 *, 0xC)
            + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x14) + M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u8 *, 2), s32 *, 0);
        M2C_FIELD(arg0, u8 **, 0x10) = M2C_FIELD(arg0, u8 **, 0x10) + 0x10;
        break;
    }
decr:
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
done:
    if (next != NULL) {
        func_020908dc(next);
    }
}

void func_02090a88(void *arg0) {
    void func_02090c7c(void *);
    void func_0209075c(void *, void *, s32);
    void *func_02082028(s32);
    u8 *cur;
    u8 *node;
    void *next;

    next = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x3C) != 0) {
        func_02090c7c((void *)M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x3C));
    }
    goto skip;
    for (;;) {
        if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u8 *, 3) != 0) {
            switch (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), u8 *, 2)) {
            case 0:
            case 1:
            case 2:
                goto done;
            case 3:
                break;
            case 4:
                node = (u8 *)M2C_FIELD(arg0, s32 **, 0xC)
                     + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC) + M2C_FIELD(arg0, u8 *, 0x2C), s32 *, 4);
                while (M2C_FIELD(node, u8 *, 3) == 0 || M2C_FIELD(node, u8 *, 2) != 0xFF) {
                    if (M2C_FIELD(node, u8 *, 3) != 0 && M2C_FIELD(node, u8 *, 2) == 3
                        && M2C_FIELD(node, s16 *, 6) == M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6)) {
                        M2C_FIELD(arg0, void **, 0x10) = node;
                        break;
                    }
                    M2C_FIELD(arg0, u8 **, 0x10) = M2C_FIELD(arg0, u8 **, 0x10) + 0x10;
                }
                goto skip;
            case 0x10:
                if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6) > 0) {
                    node = func_02082028(0x30);
                    if (node != NULL) {
                        func_0209075c(node, arg0, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x10), s16 *, 6) - 1);
                    }
                    next = M2C_FIELD(arg0, void **, 8);
                }
                break;
            case 0xFF:
                goto done;
            default:
                break;
            }
        }
        M2C_FIELD(arg0, u8 **, 0x10) = M2C_FIELD(arg0, u8 **, 0x10) + 0x10;
    skip:
        cur = M2C_FIELD(arg0, u8 **, 0x10);
        if (M2C_FIELD(cur, u8 *, 3) != 0 || M2C_FIELD(cur, u16 *, 0) == 0) {
            goto after;
        }
        M2C_FIELD(arg0, u8 **, 0x10) = cur + 0x10;
        goto skip;
    after:
        ;
    }
done:
    if (next != NULL) {
        func_02090a88(next);
    }
}

void func_02090bd8(void *arg0) {
    void func_02090bd8(void *);
    void func_01ffabac(s32, s32, s32, s32, s32, void *, s32);
    void func_01ffad4c(s32, s32, s32, s32, s32, void *, s32);

    u8 flags;

    flags = M2C_FIELD(arg0, u8 *, 0x2D);
    if (flags & 0x1) {
        return;
    }
    if ((flags & 0x2) == 0) {
        func_01ffabac(M2C_FIELD(arg0, s16 *, 0x20),
                      M2C_FIELD(arg0, s16 *, 0x22),
                      (u16)M2C_FIELD(arg0, u16 *, 0x24),
                      (u16)M2C_FIELD(arg0, u16 *, 0x26),
                      M2C_FIELD(arg0, u16 *, 0x28),
                      (void *)M2C_FIELD(arg0, void **, 0x18),
                      M2C_FIELD(arg0, s8 *, 0x2A) + M2C_FIELD(arg0, s8 *, 0x2B));
    } else {
        func_01ffad4c(M2C_FIELD(arg0, s16 *, 0x20),
                      M2C_FIELD(arg0, s16 *, 0x22),
                      (u16)M2C_FIELD(arg0, u16 *, 0x24),
                      (u16)M2C_FIELD(arg0, u16 *, 0x26),
                      M2C_FIELD(arg0, u16 *, 0x28),
                      (void *)M2C_FIELD(arg0, void **, 0x18),
                      M2C_FIELD(arg0, s8 *, 0x2A) + M2C_FIELD(arg0, s8 *, 0x2B));
    }
    if (M2C_FIELD(arg0, void **, 0x8) != 0) {
        func_02090bd8(M2C_FIELD(arg0, void **, 0x8));
    }
}

void func_02090c7c(void *arg0) {
    void *var_r0;
    void *temp_r5;
    void *temp_r4;

    var_r0 = arg0;
    temp_r5 = var_r0;
    if (temp_r5 != 0) {
        do {
            temp_r4 = M2C_FIELD(var_r0, void **, 0xC);
            if (var_r0 != 0) {
                M2C_FIELD(M2C_FIELD(var_r0, void **, 0), void (**)(void *), 8)(var_r0);
            }
            var_r0 = temp_r4;
        } while (temp_r4 != 0);
    }
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 4), s32 *, 0x3C) = 0;
}

s32 func_02090cbc(void *t) {
void func_020908dc(void *);void func_02090d84(void *);void func_01ffa574(void *);void func_02090bd8(void *);
void *q; void *p=t;
t=M2C_FIELD(p,void **,0x38);if(t)func_020908dc(t);
q=M2C_FIELD(p,void **,0x3C);
if(q) {
t=q; (*(void (***)(void *))t)[0](t);q=M2C_FIELD(q,void **,0xC);
if(q) {
t=q; (*(void (***)(void *))t)[0](t);q=M2C_FIELD(q,void **,0xC);
if(q) {
t=q; (*(void (***)(void *))t)[0](t);q=M2C_FIELD(q,void **,0xC);
if(q) {
t=q; (*(void (***)(void *))t)[0](t);q=M2C_FIELD(q,void **,0xC);
t=q;if(t)func_02090d84(t);
}}}}
t=M2C_FIELD(p,void **,0x38);if(!t && !M2C_FIELD(p,void **,0x3C))func_01ffa574(p);
else if(t)func_02090bd8(t);
}

#pragma scheduling off
void func_02090d84(void *arg0) {
void *p=arg0;
(*(void (**)(void *))*(void **)arg0)(arg0);
p=((void **)p)[3]; if(!p)return;
arg0=p; (*(void (**)(void *))*(void **)arg0)(arg0);
p=((void **)p)[3]; if(!p)return;
arg0=p; (*(void (**)(void *))*(void **)arg0)(arg0);
p=((void **)p)[3]; if(!p)return;
arg0=p; (*(void (**)(void *))*(void **)arg0)(arg0);
arg0=((void **)p)[3]; if(!arg0)return;
func_02090d84(arg0);
}
#pragma scheduling reset
void func_02090e00(void) {
    M2C_UNK func_02090cbc();
    func_02090cbc();
}
