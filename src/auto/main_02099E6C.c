/* 3 functions from 0x02099E6C to 0x0209ACC4 (main), found by ds-decomp. */
#include "common.h"

s32 func_02099e6c(void *arg0, s32 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0207a3b0(s32, u32, u16, u8, s32, s32, s32, s32, s32, s32, s32);
    s32 func_0207c8ec(s32, M2C_UNK);
    void *func_02086680(s32);
    s32 func_02091dc4(M2C_UNK);
    s32 func_02091ddc(M2C_UNK);
    M2C_UNK func_020943bc(s32);
    M2C_UNK func_02094410(s32);
    M2C_UNK func_02094a74();
    M2C_UNK func_02094a94();
    M2C_UNK func_02094af8(s32, s32, s32);
    M2C_UNK func_02094b28(s32, u8);
    M2C_UNK func_02094b50(s32, s32);
    M2C_UNK func_02094b78(s32, M2C_UNK);
    M2C_UNK func_02094ba0();
    M2C_UNK func_02094bc0();
    M2C_UNK func_02094be0();
    M2C_UNK func_02094c00(s32, s32, s32, s32);
    M2C_UNK func_02094c38(s32, s32, s32);
    M2C_UNK func_02094c68(s32, M2C_UNK);
    M2C_UNK func_02094c90(s32, void *);
    M2C_UNK func_02094d8c();
    M2C_UNK func_02094dac();
    M2C_UNK func_02094df0(M2C_UNK, s32, s32);
    M2C_UNK func_02095250(s32);
    M2C_UNK func_020952c8(s32);
    M2C_UNK func_020952ec(M2C_UNK, M2C_UNK);
    M2C_UNK func_020953d0();
    M2C_UNK func_0209544c(s32);
    M2C_UNK func_02095c58(M2C_UNK, s32, void *);
    M2C_UNK func_02095f94(u8 *);
    s32 func_020999b8(void *);
    s32 func_020999e8(void *);
    s32 func_02099a0c(void *);
    M2C_UNK func_02099a6c(void *);
    M2C_UNK func_02099ac4(void *);
    s32 func_02099ae8();
    s32 func_02099b00(void *);
    M2C_UNK func_02099e58(void *);
    M2C_UNK func_0209c418(void *);
    M2C_UNK func_0209c428(void *);
    extern M2C_UNK data_02102e74;
    extern M2C_UNK data_02102eac;
    extern M2C_UNK data_0212616c;
    extern void **data_027e0058;
    u8 sp1C;
    s32 temp_r0_10;
    s32 temp_r0_9;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r8;
    u16 var_r0;
    u16 var_r0_2;
    u32 temp_r0_12;
    u32 temp_r0_13;
    u32 temp_r0_6;
    u32 temp_r0_7;
    u32 temp_r0_8;
    u32 temp_r2_2;
    u32 temp_r2_3;
    u8 *var_r4;
    u8 temp_r0;
    u8 temp_r0_11;
    u8 temp_r0_3;
    u8 temp_r0_5;
    u8 temp_r3_4;
    u8 var_r1;
    void *temp_r0_14;
    void *temp_r0_15;
    void *temp_r0_16;
    void *temp_r0_2;
    void *temp_r0_4;
    void *temp_r1;
    void *temp_r2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r6;

loop_1:
    temp_r1 = M2C_FIELD(arg0, void **, 0x34);
    temp_r0 = M2C_FIELD(temp_r1, u8 *, 0);
    if (temp_r0 == 0x16) {
        M2C_FIELD(arg0, s16 *, 0x46) = (s16) (M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        func_0209c418(arg0);
        func_0209c418(arg0);
        goto loop_1;
    }
    switch (temp_r0) {                              /* switch 1 */
    default:                                        /* switch 1 */
    case 1:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
    case 14:                                        /* switch 1 */
    case 15:                                        /* switch 1 */
    case 22:                                        /* switch 1 */
        return 1;
    case 0:                                         /* switch 1 */
        temp_r2 = M2C_FIELD(arg0, void **, 0x38);
        if (temp_r2 == NULL) {
            return 0;
        }
        M2C_FIELD(arg0, void **, 0x34) = temp_r2;
        M2C_FIELD(arg0, void **, 0x38) = NULL;
        return func_02099e6c(arg0, arg1);
    case 5:                                         /* switch 1 */
    case 6:                                         /* switch 1 */
        if (func_020999b8(arg0) == 0) {
            temp_r0_2 = func_01ffa3dc(&data_02102e74, 7);
            M2C_FIELD(temp_r0_2, s32 *, 0x4C) = arg1;
            M2C_FIELD(temp_r0_2, s32 *, 0x3C) = func_02099a0c(arg0);
            M2C_FIELD(temp_r0_2, s8 *, 0x40) = (s8) M2C_FIELD(arg0, s8 *, 0x57);
            M2C_FIELD(temp_r0_2, u16 *, 0x48) = (u16) M2C_FIELD(arg0, u16 *, 0x44);
            M2C_FIELD(temp_r0_2, s16 *, 0x4A) = (s16) M2C_FIELD(arg0, u8 *, 0x56);
            M2C_FIELD(temp_r0_2, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
            temp_r0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0);
            if ((temp_r0_3 == 5) || (temp_r0_3 != 6)) {
                M2C_FIELD(temp_r0_2, s16 *, 0x34) = 0;
            } else {
                M2C_FIELD(temp_r0_2, s16 *, 0x34) = 1;
            }
            M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 8);
        }
        func_0209c418(arg0);
        return 2;
    case 10:                                        /* switch 1 */
    case 13:                                        /* switch 1 */
        if (func_020999e8(arg0) == 0) {
            return 0;
        }
        if (func_020999b8(arg0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x4B) = (u8) (M2C_FIELD(arg0, u8 *, 0x4B) + 2);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + 2);
            func_02099a6c(arg0);
        }
        func_0209c418(arg0);
        return 3;
    case 2:                                         /* switch 1 */
        if (func_020999b8(arg0) == 0) {
            temp_r0_4 = func_01ffa3dc(&data_02102eac, 7);
            M2C_FIELD(temp_r0_4, s32 *, 0x4C) = arg1;
            M2C_FIELD(temp_r0_4, s32 *, 0x3C) = func_02099a0c(arg0);
            M2C_FIELD(temp_r0_4, s8 *, 0x40) = (s8) M2C_FIELD(arg0, s8 *, 0x57);
            M2C_FIELD(temp_r0_4, s16 *, 0x4A) = (s16) M2C_FIELD(arg0, u8 *, 0x56);
            M2C_FIELD(temp_r0_4, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) M2C_FIELD(arg0, u16 *, 0x4E);
            M2C_FIELD(arg0, u8 *, 0x55) = 2U;
            func_02099ac4(arg0);
        }
        func_0209c428(arg0);
        return 2;
    case 4:                                         /* switch 1 */
        if (func_020999b8(arg0) == 0) {
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) M2C_FIELD(arg0, u16 *, 0x4E);
            func_02099ac4(arg0);
        }
        func_0209c418(arg0);
        return 2;
    case 3:                                         /* switch 1 */
        temp_r4 = M2C_FIELD(temp_r1, u8 *, 1) & 0x7F;
        func_0209c418(arg0);
        func_0209c428(arg0);
        if (func_020999b8(arg0) != 0) {
            return 3;
        }
        func_0209544c(temp_r4);
        return 2;
    case 12:                                        /* switch 1 */
        if (func_020999b8(arg0) == 0) {
            temp_r0_5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1);
            if (temp_r0_5 == 0) {
                func_02099e58(arg0);
            } else {
                M2C_FIELD(arg0, u8 *, 0x55) = temp_r0_5;
                M2C_FIELD(arg0, s8 *, 0x54) = 0;
            }
        }
        func_0209c418(arg0);
        func_0209c418(arg0);
        return 3;
    case 11:                                        /* switch 1 */
        temp_r0_6 = M2C_FIELD(temp_r1, u8 *, 1) - 0x80;
        switch (temp_r0_6) {                        /* switch 2 */
        default:                                    /* switch 2 */
            func_0209c418(arg0);
            func_0209c418(arg0);
            return 3;
        case 0:                                     /* switch 2 */
            if (func_020999b8(arg0) == 0) {
                temp_r3 = *data_027e0058;
                temp_r4_2 = (M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0xC) * 0xE) + (s32) (temp_r3 + 0x59A4);
                temp_r0_7 = (u32) (M2C_FIELD(temp_r4_2, u16 *, 6) << 0x19) >> 0x19;
                if (temp_r0_7 == 0) {
                    var_r0 = 0;
                } else {
                    var_r0 = func_0207c8ec(temp_r0_7 - 1, 0xA) + 1;
                }
                func_0207a3b0(M2C_FIELD(arg0, s32 *, 0x40) + (M2C_FIELD(arg0, u8 *, 0x4A) * 2) + (M2C_FIELD(arg0, u8 *, 0x4B) << 6), (u32) (M2C_FIELD(temp_r4_2, u8 *, 0) << 0x1A) >> 0x1A, M2C_FIELD(*data_027e0058, u16 *, 0x52A8), M2C_FIELD(temp_r4_2, u8 *, 0xC), 0, (s32) var_r0, 0, 0, 0, 0, 0);
                M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 2);
            }
            func_0209c418(arg0);
            func_0209c418(arg0);
            return 3;
        case 1:                                     /* switch 2 */
            if (func_020999b8(arg0) == 0) {
                temp_r3_2 = *data_027e0058;
                temp_r4_3 = (M2C_FIELD(M2C_FIELD(temp_r3_2, void **, 0x52D0), u8 *, 0xD) * 0xE) + (s32) (temp_r3_2 + 0x59A4);
                temp_r0_8 = (u32) (M2C_FIELD(temp_r4_3, u16 *, 6) << 0x19) >> 0x19;
                if (temp_r0_8 == 0) {
                    var_r0_2 = 0;
                } else {
                    var_r0_2 = func_0207c8ec(temp_r0_8 - 1, 0xA) + 1;
                }
                func_0207a3b0(M2C_FIELD(arg0, s32 *, 0x40) + (M2C_FIELD(arg0, u8 *, 0x4A) * 2) + (M2C_FIELD(arg0, u8 *, 0x4B) << 6), (u32) (M2C_FIELD(temp_r4_3, u8 *, 0) << 0x1A) >> 0x1A, M2C_FIELD(*data_027e0058, u16 *, 0x52A8), M2C_FIELD(temp_r4_3, u8 *, 0xC), 0, (s32) var_r0_2, 0, 0, 0, 0, 0);
                M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 2);
            }
            func_0209c418(arg0);
            func_0209c418(arg0);
            return 3;
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
            M2C_FIELD(arg0, void **, 0x38) = (void *) (temp_r1 + 2);
            temp_r6 = *data_027e0058;
            M2C_FIELD(arg0, void **, 0x34) = func_02086680(*(&data_0212616c + ((u8) M2C_FIELD(((M2C_FIELD(temp_r6, u16 *, 0x52A4) * 0x8C) + (s32) temp_r6), s32 *, 0x6810) * 0x9C)));
            return func_02099e6c(arg0, arg1);
        }
        break;
    case 8:                                         /* switch 1 */
        func_0209c418(arg0);
        func_0209c418(arg0);
        return 3;
    case 16:                                        /* switch 1 */
        if (temp_r0 == 0x10) {
            do {
                temp_r2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) - 0x80;
                temp_r0_9 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) - 0x80;
                switch (temp_r2_2) {                /* switch 3 */
                default:                            /* switch 3 */
                    break;
                case 0:                             /* switch 3 */
                    func_02094af8(temp_r0_9, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 13:                            /* switch 3 */
                    func_02094b50(temp_r0_9, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 12:                            /* switch 3 */
                    var_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3);
                    if (var_r1 == 0) {
                        temp_r3_3 = *data_027e0058;
                        var_r1 = M2C_FIELD(((M2C_FIELD(temp_r3_3, u16 *, 0x52A4) * 0x8C) + (s32) temp_r3_3), u8 *, 0x67C1);
                    }
                    func_02094b28(temp_r0_9, var_r1);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 10:                            /* switch 3 */
                    func_02094a74();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 11:                            /* switch 3 */
                    func_02094a94();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 14:                            /* switch 3 */
                    func_02094ba0();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 6:                             /* switch 3 */
                    func_02094c90(temp_r0_9, arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 8:                             /* switch 3 */
                    func_02094b78(temp_r0_9, 0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 9:                             /* switch 3 */
                    func_02094b78(temp_r0_9, 1);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x10);
        }
        return 2;
    case 17:                                        /* switch 1 */
        if (temp_r0 == 0x11) {
            do {
                temp_r2_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) - 0x80;
                temp_r0_10 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) - 0x80;
                switch (temp_r2_3) {                /* switch 4 */
                default:                            /* switch 4 */
                    break;
                case 0:                             /* switch 4 */
                    func_02094c38(temp_r0_10, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 1:                             /* switch 4 */
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 2:                             /* switch 4 */
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 3:                             /* switch 4 */
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 4:                             /* switch 4 */
                    func_02094bc0();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 5:                             /* switch 4 */
                    func_02094be0();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 6:                             /* switch 4 */
                    func_02094d8c();
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 7:                             /* switch 4 */
                    func_02094c00(temp_r0_10, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 5) & 0x7F);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 8:                             /* switch 4 */
                    func_02094c68(temp_r0_10, 0);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                case 9:                             /* switch 4 */
                    func_02094c68(temp_r0_10, 1);
                    func_0209c418(arg0);
                    func_0209c418(arg0);
                    func_0209c428(arg0);
                    break;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x11);
        }
        return 2;
    case 18:                                        /* switch 1 */
        func_02094dac();
        func_0209c428(arg0);
        return 2;
    case 19:                                        /* switch 1 */
        temp_r0_11 = M2C_FIELD(temp_r1, u8 *, 1);
        if (temp_r0_11 == 0x80) {
            func_020953d0();
            func_0209c418(arg0);
            func_0209c428(arg0);
            return 2;
        }
        temp_r0_12 = temp_r0_11 - 0x81;
        switch (temp_r0_12) {                       /* switch 5 */
        default:                                    /* switch 5 */
            break;
        case 0:                                     /* switch 5 */
            func_020952ec(0, 0);
            break;
        case 1:                                     /* switch 5 */
            func_020952ec(1, 0);
            break;
        case 2:                                     /* switch 5 */
            func_020952ec(0, 2);
            break;
        case 3:                                     /* switch 5 */
            func_020952ec(1, 2);
            break;
        case 4:                                     /* switch 5 */
            func_020952ec(0, 1);
            break;
        case 5:                                     /* switch 5 */
            func_020952ec(1, 1);
            break;
        }
        func_0209c418(arg0);
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 3;
    case 20:                                        /* switch 1 */
        if (temp_r0 == 0x14) {
            do {
                temp_r0_13 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) & 0x7F;
                temp_r8 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) & 0x7F;
                switch (temp_r0_13) {               /* switch 6 */
                default:                            /* switch 6 */
                    break;
                case 0:                             /* switch 6 */
                    func_02094df0(0, func_02091dc4(0), temp_r8);
                    break;
                case 1:                             /* switch 6 */
                    func_02094df0(1, func_02091dc4(1), temp_r8);
                    break;
                case 2:                             /* switch 6 */
                    func_02094df0(0, func_02091ddc(0), temp_r8);
                    break;
                case 3:                             /* switch 6 */
                    func_02094df0(1, func_02091ddc(1), temp_r8);
                    break;
                case 4:                             /* switch 6 */
                    func_02095c58(0, temp_r8, arg0);
                    break;
                case 5:                             /* switch 6 */
                    func_02095c58(1, temp_r8, arg0);
                    break;
                }
                func_0209c418(arg0);
                func_0209c418(arg0);
                func_0209c428(arg0);
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x14);
        }
        return 3;
    case 21:                                        /* switch 1 */
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 3;
    case 23:                                        /* switch 1 */
        func_02094410(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        func_0209c418(arg0);
        func_0209c428(arg0);
        /* Duplicate return node #202. Try simplifying control flow for better match */
        return 2;
    case 25:                                        /* switch 1 */
        func_020952c8(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 2;
    case 24:                                        /* switch 1 */
        func_02095250(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 2;
    case 26:                                        /* switch 1 */
        func_0209c418(arg0);
        var_r4 = &sp1C;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) != 0x1E) {
            do {
                if ((func_02099ae8() != 0) || (func_02099b00(M2C_FIELD(arg0, void **, 0x34)) != 0)) {
                    temp_r0_14 = M2C_FIELD(arg0, void **, 0x34);
                    M2C_FIELD(arg0, void **, 0x34) = (void *) (temp_r0_14 + 1);
                    M2C_FIELD(var_r4, u8 *, 0) = M2C_FIELD(temp_r0_14, u8 *, 0);
                    temp_r0_15 = M2C_FIELD(arg0, void **, 0x34);
                    M2C_FIELD(arg0, void **, 0x34) = (void *) (temp_r0_15 + 1);
                    M2C_FIELD(var_r4, u8 *, 1) = (u8) M2C_FIELD(temp_r0_15, u8 *, 0);
                    var_r4 += 2;
                } else {
                    temp_r0_16 = M2C_FIELD(arg0, void **, 0x34);
                    M2C_FIELD(arg0, void **, 0x34) = (void *) (temp_r0_16 + 1);
                    M2C_FIELD(var_r4, u8 *, 0) = M2C_FIELD(temp_r0_16, u8 *, 0);
                    var_r4 += 1;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) != 0x1E);
        }
        *var_r4 = 0;
        func_02095f94(&sp1C);
        M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 8);
        func_0209c428(arg0);
        return 3;
    case 27:                                        /* switch 1 */
        func_020943bc(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 3;
    case 28:                                        /* switch 1 */
        temp_r3_4 = M2C_FIELD(temp_r1, u8 *, 1);
        M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x48) + (temp_r3_4 & 0x7F));
        M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + (u8) (temp_r3_4 * 2));
        M2C_FIELD(arg0, u8 *, 0x56) = 0U;
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 1;
    case 29:                                        /* switch 1 */
        func_0209c418(arg0);
        func_0209c428(arg0);
        return 1;
    case 30:                                        /* switch 1 */
        func_0209c428(arg0);
        return 3;
    }
}

void func_0209ac6c(void *arg0, void *arg1) {
    if (arg1 == NULL) {
        return;
    }
    M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u16 *, 0x4C) | M2C_FIELD(arg0, u16 *, 0x44));
    M2C_FIELD(arg1, s16 *, 0x40) = (s16) ((M2C_FIELD(arg0, u16 *, 0x4C) + 1) | M2C_FIELD(arg0, u16 *, 0x44));
}

void func_0209ac9c(void *arg0) {
    s8 func_02095fe8();
    M2C_UNK func_020974d0(void *);
    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 1);
    M2C_FIELD(arg0, s8 *, 0x5B) = func_02095fe8();
    func_020974d0(arg0);
}
