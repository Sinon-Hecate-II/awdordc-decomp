/* 17 functions from 0x020C9B9C to 0x020CAB8C (main), found by ds-decomp. */
#include "common.h"

s32 func_020c9b9c(void *arg0) { (void)arg0; return 0; }

void func_020c9e14(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_020cbc88(void *, void *);
    extern void **gCurrentMap;
    extern u16 data_ov000_021aeef4[];
    s16 temp_r1;
    if (M2C_FIELD(arg0, s16 *, 0x6E) & 0x11) {
        func_01ffa6fc(arg0);
        return;
    }
    while ((temp_r1 = M2C_FIELD(arg0, s16 *, 0x70)) < 0x33) {
        func_020cbc88((u8 *)*gCurrentMap + 0x59A4 + (temp_r1 + data_ov000_021aeef4[M2C_FIELD(arg0, s16 *, 0x6C)]) * 0xE, arg0);
        M2C_FIELD(arg0, s16 *, 0x70) += 1;
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020c9e94(u16 arg0, u16 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b304;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_0212b304, 7);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x6E) = arg1;
}

void func_020c9ebc(s32 arg0, s32 arg1) {
    M2C_UNK func_02091c20(s32, s32);
    s32 func_020d19b4(s32);
    extern void **gCurrentMap;
    void *temp_r2;
    s32 temp_lr;
    s32 current;
    temp_r2 = *gCurrentMap;
    temp_lr = arg0 * 0x8C;
    M2C_FIELD((u8 *)temp_r2 + temp_lr, u16 *, 0x67BE) = M2C_FIELD(temp_r2, u16 *, 0x52A2);
    M2C_FIELD((u8 *)*gCurrentMap + temp_lr, s8 *, 0x67C0) = arg1;
    if (func_020d19b4(arg0) != 0) func_02091c20(0x18, 1);
    current = M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
    if (current == arg0) return;
    if (func_020d19b4(current) == 0) return;
    if (arg1 & 0x11) func_02091c20(0x17, 1);
    if (!(arg1 & 2)) return;
    func_02091c20(0x16, 1);
}

void func_020c9f74(s32 arg0) {
    typedef struct { s32 entries[4]; } Table;
    M2C_UNK func_02096b50(s32);
    extern void **gCurrentMap;
    extern Table data_020f4e68;
    Table sp0;
    sp0 = data_020f4e68;
    func_02096b50(sp0.entries[M2C_FIELD((u8 *)*gCurrentMap + arg0 * 0x8C, u8 *, 0x67C1) - 1]);
}

void func_020c9fc8(s32 arg0, s32 arg1) {
    void func_020ca484(void);
    void func_020a3498(void);
    void func_020bbb08(void);
    extern void **gCurrentMap;
    func_020c9f74(arg0);
    func_020c9e94((u16)arg0, (u16)arg1);
    func_020c9ebc(arg0, arg1);
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52A4) == arg0) {
        func_020a3498();
        func_020bbb08();
    }
    if (arg1 != 2) return;
    func_020ca484();
}

void func_020ca030(void) {
    void func_020c9fc8(s32, s32);
    s32 func_020d1938(s16);
    s32 func_020d3248(s16);
    s32 func_020d336c(s16);
    s32 func_020d332c(s16);
    s32 func_020d32d4(s16);
    s16 var_r8;
    var_r8 = 1;
    do {
        if (func_020d1938(var_r8) != 0) {
            if (func_020d3248(var_r8) != 0) func_020c9fc8(var_r8, 8);
            else if (func_020d336c(var_r8) == 0) func_020c9fc8(var_r8, 0x10);
            else if (func_020d332c(var_r8) == 0) func_020c9fc8(var_r8, 1);
            else if (func_020d32d4(var_r8) == 0) func_020c9fc8(var_r8, 2);
        }
        var_r8 += 1;
    } while (var_r8 < 5);
}

void func_020ca0e0(void) {
    void func_020c9ebc(s32, s32);
    s32 func_020d1938(s16);
    s32 func_020d3248(s16);
    s32 func_020d336c(s16);
    s32 func_020d332c(s16);
    s32 func_020d32d4(s16);
    s16 var_r8;
    var_r8 = 1;
    do {
        if (func_020d1938(var_r8) != 0) {
            if (func_020d3248(var_r8) != 0) func_020c9ebc(var_r8, 8);
            else if (func_020d336c(var_r8) == 0) func_020c9ebc(var_r8, 0x10);
            else if (func_020d332c(var_r8) == 0) func_020c9ebc(var_r8, 1);
            else if (func_020d32d4(var_r8) == 0) func_020c9ebc(var_r8, 2);
        }
        var_r8 += 1;
    } while (var_r8 < 5);
}

s32 func_020ca190(void) {
    extern u8 data_02168f14[];
    extern void **gCurrentMap;
    u8 var_r0;
    if (data_02168f14[2] == 0) return 0;
    var_r0 = 1;
    do {
        if ((u32)M2C_FIELD((u8 *)*gCurrentMap + var_r0 * 0x8C, u8 *, 0x67BC) >= (u32)data_02168f14[2]) return var_r0;
        var_r0 += 1;
    } while (var_r0 < 5U);
    return 0;
}

s32 func_020ca1ec(void) {
    return 0;
}

void func_020ca484(void) {
    extern void **gCurrentMap;
    u16 temp_r2;
    void *temp_r0;

    temp_r0 = *gCurrentMap;
    temp_r2 = M2C_FIELD(temp_r0, u16 *, 0x52B0);
    if (temp_r2 == 0x10) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x52B2) = temp_r2;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0x10;
}

void func_020ca4c0(void) {
    M2C_UNK func_02096c7c(s32, M2C_UNK);
    M2C_UNK func_020c9b70();
    void func_020ca030();
    void func_020ca0e0();
    s32 func_020ca190();
    s32 func_020ca1ec();
    s32 temp_r0;

    if (func_020ca1ec() != 0) {
        func_020ca0e0();
        func_020c9b70();
        return;
    }
    temp_r0 = func_020ca190();
    if (temp_r0 != 0) {
        func_02096c7c(temp_r0, 0x20);
        return;
    }
    func_020ca030();
}

void func_020ca4fc(void *arg0) {
    void func_0208fe30(s32);
    s16 func_0209f8d4(void);
    void *func_0209f8e4(s16);
    void func_020cbdbc(void);
    extern void **gCurrentMap;
    s16 temp_r4;
    s16 temp_r5;
    void *temp_r0;
    void *temp_r1;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = func_0209f8d4();
    temp_r1 = *gCurrentMap;
    temp_r4 = M2C_FIELD(temp_r1, s16 *, 0x52C2);
    temp_r5 = M2C_FIELD(temp_r1, s16 *, 0x52C4);
    temp_r0 = func_0209f8e4(M2C_FIELD(arg0, s16 *, 0x6C));
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(temp_r0, s16 *, 4);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(temp_r0, s16 *, 6);
    func_020cbdbc();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = temp_r4;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = temp_r5;
    func_0208fe30(0x10019);
}

void func_020ca59c(void *dialog) {
    M2C_UNK func_020be010(void);
    s32 func_0207b7c4(void);
    s32 func_020cccb8(void);
    s32 func_020bcb94(void);
    s32 func_020bd990(s16);
    s32 func_020d46cc(void);
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_0207b764(s16, s16);
    void *func_0209f8e4(s16);
    M2C_UNK func_020cc66c(s16, s16);
    s32 func_020ccca0(void);
    void func_020d8fa0(void);
    void func_020bcb34(void *, s16);
    void func_020bd7a4(void *, s16);
    void func_0208fe30(s32);
    void func_020cf5ec(s32);
    void func_020d6778(s32);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK func_020cf69c(s32, s32);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;

    s32 saved = M2C_FIELD(dialog, s16 *, 0x6C);
    s32 flags = 0;
    s16 r6 = M2C_FIELD(dialog, s16 *, 0x6E);
    s32 merged;

    if (r6 <= 1) {
        func_020cf828(0x10019);
        func_0207a7a4(1, 4);
        func_020cf69c(2, 10);
        return;
    }

    func_020be010();
    if (func_0207b7c4() != 0) return;
    if (func_020cccb8() != 0) return;

    flags |= func_020bcb94();
    merged = flags | func_020bd990(r6);

    if (merged & 0x20) {
        if (!func_020d46cc()) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        }
        data_0215be0c = -1;
        func_01ffa574(dialog);
        func_0207b764(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                      M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
        return;
    }
    if (merged & 0x10) {
        void *p;
        data_0215be0c = M2C_FIELD(dialog, s16 *, 0x6C);
        p = func_0209f8e4(M2C_FIELD(dialog, s16 *, 0x6C));
        func_020cc66c(M2C_FIELD(p, s16 *, 0x4), M2C_FIELD(p, s16 *, 0x6));
        func_01ffa574(dialog);
        return;
    }
    if (merged & 0x100) {
        func_020ccca0();
        return;
    }
    if (merged & 0x40) {
        s32 oldval;
        void *p;
        func_020d8fa0();
        oldval = saved;
        func_020bcb34(&saved, r6);
        func_020bd7a4(&saved, r6);
        if (oldval != saved) {
            func_0208fe30(0x10019);
            M2C_FIELD(dialog, s16 *, 0x6C) = (s16)saved;
            p = func_0209f8e4(M2C_FIELD(dialog, s16 *, 0x6C));
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(p, s16 *, 0x4);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(p, s16 *, 0x6);
            func_0207b764(M2C_FIELD(p, s16 *, 0x4), M2C_FIELD(p, s16 *, 0x6));
            if (func_0207b7c4() != 0) return;
            func_020cf5ec(2);
            func_020d6778(1);
        }
    }
}

void func_020ca77c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b1fc;
    func_01ffa42c(&data_0212b1fc, arg0);
}

void func_020ca794(void *arg0) {
    return;
}

/* Handles a confirmation-style selection menu: moves the cursor, opens detail view on confirm, or signals cancel. */
void func_020caa34(void *dialog) {
    M2C_UNK func_020bdfdc(void);
    s32 func_020d4dd0(void);
    s32 func_020bcc34(void);
    s32 func_020bddd4(void);
    M2C_UNK func_0207b764(s16, s16);
    M2C_UNK func_01ffa6fc(void *);
    s32 func_0209f944(s16, s16);
    M2C_UNK func_020d468c(void);
    M2C_UNK func_020cc66c(s16, s16);
    M2C_UNK func_ov000_02199f50(s32, u8, u8, u8);
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_020ccca0(void);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK func_020cf69c(s32, s32);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;

    s32 flags = 0;

    func_020bdfdc();
    if (func_020d4dd0() != 0) {
        flags |= func_020bcc34();
        flags |= func_020bddd4();
        if (flags & 0x20) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
            data_0215be0c = -1;
            func_0207b764(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                          M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
            func_01ffa6fc(dialog);
            return;
        }
        if (flags & 0x10) {
            if (func_0209f944(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                               M2C_FIELD(*gCurrentMap, s16 *, 0x52C4)) != 0) {
                func_020d468c();
                func_020cc66c(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                              M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                func_ov000_02199f50(0x15,
                    M2C_FIELD(*gCurrentMap, u8 *, 0x52D4),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                func_01ffa574(dialog);
                return;
            }
        }
        if (flags & 0x100) {
            func_020ccca0();
            return;
        }
    }
    func_020cf828(0x1001a);
    func_0207a7a4(1, 4);
    func_020cf69c(2, 10);
}

