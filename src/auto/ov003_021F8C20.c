/* 4 functions from 0x021F8C20 to 0x021F9B30 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021f8c20(void *arg0) {
    void *func_02084e64();
    M2C_UNK func_0208fe30(s32);
    s32 func_020a8ff4(void *);
    u32 func_020d886c();
    s32 func_ov003_021f3fe4(s32, M2C_UNK, s16);
    M2C_UNK func_ov003_021f9b30(void *);
    s16 temp_r1_3;
    s16 temp_r1_4;
    s16 temp_r3_2;
    s16 var_r7;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r3;
    s32 temp_r7;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r3;
    s8 var_r8;
    u32 temp_r0_7;
    u32 temp_r0_8;
    u8 temp_r10;
    u8 temp_r5_2;
    u8 temp_r5_3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r5;

    temp_r0 = func_02084e64();
    if (temp_r0 == NULL) {
        return;
    }
    temp_r0_2 = M2C_FIELD(arg0, void **, 0x5C);
    temp_r3 = M2C_FIELD(temp_r0_2, s32 *, 4);
    M2C_FIELD(temp_r0_2, s32 *, 4) = (s32) M2C_FIELD(temp_r0, u8 *, 9);
    temp_r10 = (u8) (u16) (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14);
    if (M2C_FIELD(temp_r0_2, u8 *, 0x14) != 0) {
        var_r1 = M2C_FIELD(temp_r0_2, s32 *, 4);
        if (var_r1 > (s32) M2C_FIELD(temp_r0_2, s32 *, 8)) {
            do {
                var_r1 = M2C_FIELD(temp_r0_2, s32 *, 4) - ((M2C_FIELD(temp_r0_2, s32 *, 8) - M2C_FIELD(temp_r0_2, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_2, s32 *, 4) = var_r1;
            } while (var_r1 > (s32) M2C_FIELD(temp_r0_2, s32 *, 8));
        }
        if (var_r1 < (s32) M2C_FIELD(temp_r0_2, s32 *, 0xC)) {
            do {
                temp_r1 = M2C_FIELD(temp_r0_2, s32 *, 4) + ((M2C_FIELD(temp_r0_2, s32 *, 8) - M2C_FIELD(temp_r0_2, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_2, s32 *, 4) = temp_r1;
            } while (temp_r1 < (s32) M2C_FIELD(temp_r0_2, s32 *, 0xC));
        }
    } else {
        temp_r1_2 = M2C_FIELD(temp_r0_2, s32 *, 4);
        var_r2 = M2C_FIELD(temp_r0_2, s32 *, 8);
        if (temp_r1_2 <= var_r2) {
            var_r2 = M2C_FIELD(temp_r0_2, s32 *, 0xC);
            if (temp_r1_2 >= var_r2) {
                var_r2 = temp_r1_2;
            }
        }
        M2C_FIELD(temp_r0_2, s32 *, 4) = var_r2;
    }
    temp_r5 = M2C_FIELD(arg0, void **, 0x60);
    M2C_FIELD(temp_r5, s32 *, 0xC) = (s32) M2C_FIELD(temp_r0, u8 *, 9);
    if (M2C_FIELD(temp_r5, u8 *, 0x1C) != 0) {
        var_r0 = M2C_FIELD(temp_r5, s32 *, 0xC);
        if (var_r0 > (s32) M2C_FIELD(temp_r5, s32 *, 0x10)) {
            do {
                var_r0 = M2C_FIELD(temp_r5, s32 *, 0xC) - ((M2C_FIELD(temp_r5, s32 *, 0x10) - M2C_FIELD(temp_r5, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r5, s32 *, 0xC) = var_r0;
            } while (var_r0 > (s32) M2C_FIELD(temp_r5, s32 *, 0x10));
        }
        if (var_r0 < (s32) M2C_FIELD(temp_r5, s32 *, 0x14)) {
            do {
                temp_r0_3 = M2C_FIELD(temp_r5, s32 *, 0xC) + ((M2C_FIELD(temp_r5, s32 *, 0x10) - M2C_FIELD(temp_r5, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r5, s32 *, 0xC) = temp_r0_3;
            } while (temp_r0_3 < (s32) M2C_FIELD(temp_r5, s32 *, 0x14));
        }
    } else {
        var_r1_2 = M2C_FIELD(temp_r5, s32 *, 0x10);
        temp_r0_4 = M2C_FIELD(temp_r5, s32 *, 0xC);
        if (temp_r0_4 <= var_r1_2) {
            var_r1_2 = M2C_FIELD(temp_r5, s32 *, 0x14);
            if (temp_r0_4 >= var_r1_2) {
                var_r1_2 = temp_r0_4;
            }
        }
        M2C_FIELD(temp_r5, s32 *, 0xC) = var_r1_2;
    }
    temp_r0_5 = func_ov003_021f3fe4(func_020a8ff4(temp_r5 + 0x20), 0, (s16) (((s16) M2C_FIELD(temp_r5, s32 *, 0x10) + 1) * M2C_FIELD(temp_r5, s16 *, 4)));
    temp_r3_2 = M2C_FIELD(temp_r5, s16 *, 4);
    temp_r7 = M2C_FIELD(temp_r5, s32 *, 0x10);
    temp_r1_3 = M2C_FIELD(temp_r5, s32 *, 0xC) * temp_r3_2;
    if (temp_r0_5 <= (s32) temp_r1_3) {
        var_r0_2 = (temp_r1_3 - temp_r0_5) << 0x10;
        var_r1_3 = (temp_r0_5 + ((s16) ((s16) ((s16) temp_r7 + 1) * temp_r3_2) - temp_r1_3)) << 0x10;
    } else {
        var_r0_2 = (((s16) ((s16) ((s16) temp_r7 + 1) * temp_r3_2) - temp_r0_5) + temp_r1_3) << 0x10;
        var_r1_3 = (temp_r0_5 - temp_r1_3) << 0x10;
    }
    if ((s32) (var_r0_2 >> 0x10) <= (s32) (var_r1_3 >> 0x10)) {
        var_r8 = 0;
    } else {
        var_r8 = 1;
    }
    temp_r1_4 = M2C_FIELD(temp_r5, s16 *, 4);
    var_r7 = M2C_FIELD(temp_r5, s32 *, 0xC) * temp_r1_4;
    temp_r0_6 = func_ov003_021f3fe4(func_020a8ff4(temp_r5 + 0x20), 0, (s16) (((s16) M2C_FIELD(temp_r5, s32 *, 0x10) + 1) * temp_r1_4));
    if (var_r8 == 0) {
        if (temp_r0_6 > (s32) var_r7) {
            var_r7 += (s16) (((s16) M2C_FIELD(temp_r5, s32 *, 0x10) + 1) * M2C_FIELD(temp_r5, s16 *, 4));
        }
    } else if (temp_r0_6 < (s32) var_r7) {
        var_r7 -= (s16) (((s16) M2C_FIELD(temp_r5, s32 *, 0x10) + 1) * M2C_FIELD(temp_r5, s16 *, 4));
    }
    M2C_FIELD(temp_r5, s16 *, 0x2E) = (s16) temp_r0_6;
    M2C_FIELD(temp_r5, s16 *, 0x30) = var_r7;
    M2C_FIELD(temp_r5, s16 *, 0x2C) = (s16) M2C_FIELD(temp_r5, s16 *, 0x2C);
    M2C_FIELD(temp_r5, u16 *, 0x22) = (u16) M2C_FIELD(temp_r5, u16 *, 0x24);
    temp_r5_2 = M2C_FIELD(temp_r0, u8 *, 0xA);
    temp_r0_7 = func_020d886c();
    switch (temp_r0_7) {                            /* switch 1 */
    default:                                        /* switch 1 */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 11:                                        /* switch 1 */
    case 13:                                        /* switch 1 */
    case 18:                                        /* switch 1 */
    case 19:                                        /* switch 1 */
    case 20:                                        /* switch 1 */
    case 21:                                        /* switch 1 */
    case 25:                                        /* switch 1 */
    case 26:                                        /* switch 1 */
    case 27:                                        /* switch 1 */
        var_r2_2 = 4;
        break;
    case 28:                                        /* switch 1 */
        var_r2_2 = 7;
        break;
    case 6:                                         /* switch 1 */
        var_r2_2 = 1;
        break;
    case 22:                                        /* switch 1 */
    case 23:                                        /* switch 1 */
        var_r2_2 = 3;
        break;
    case 12:                                        /* switch 1 */
        var_r2_2 = 5;
        break;
    case 5:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
        var_r2_2 = 0;
        break;
    case 24:                                        /* switch 1 */
        var_r2_2 = 2;
        break;
    case 8:                                         /* switch 1 */
        var_r2_2 = 6;
        break;
    case 14:                                        /* switch 1 */
        var_r2_2 = 9;
        break;
    case 15:                                        /* switch 1 */
        var_r2_2 = 0xA;
        break;
    case 16:                                        /* switch 1 */
        var_r2_2 = 0xB;
        break;
    case 17:                                        /* switch 1 */
        var_r2_2 = 0xC;
        break;
    }
    M2C_FIELD(((var_r2_2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xD) = temp_r5_2;
    temp_r5_3 = M2C_FIELD(temp_r0, u8 *, 0xB);
    temp_r0_8 = func_020d886c();
    switch (temp_r0_8) {                            /* switch 2 */
    default:                                        /* switch 2 */
    case 0:                                         /* switch 2 */
    case 1:                                         /* switch 2 */
    case 2:                                         /* switch 2 */
    case 3:                                         /* switch 2 */
    case 4:                                         /* switch 2 */
    case 9:                                         /* switch 2 */
    case 10:                                        /* switch 2 */
    case 11:                                        /* switch 2 */
    case 13:                                        /* switch 2 */
    case 18:                                        /* switch 2 */
    case 19:                                        /* switch 2 */
    case 20:                                        /* switch 2 */
    case 21:                                        /* switch 2 */
    case 25:                                        /* switch 2 */
    case 26:                                        /* switch 2 */
    case 27:                                        /* switch 2 */
        var_r3 = 4;
        break;
    case 28:                                        /* switch 2 */
        var_r3 = 7;
        break;
    case 6:                                         /* switch 2 */
        var_r3 = 1;
        break;
    case 22:                                        /* switch 2 */
    case 23:                                        /* switch 2 */
        var_r3 = 3;
        break;
    case 12:                                        /* switch 2 */
        var_r3 = 5;
        break;
    case 5:                                         /* switch 2 */
    case 7:                                         /* switch 2 */
        var_r3 = 0;
        break;
    case 24:                                        /* switch 2 */
        var_r3 = 2;
        break;
    case 8:                                         /* switch 2 */
        var_r3 = 6;
        break;
    case 14:                                        /* switch 2 */
        var_r3 = 9;
        break;
    case 15:                                        /* switch 2 */
        var_r3 = 0xA;
        break;
    case 16:                                        /* switch 2 */
        var_r3 = 0xB;
        break;
    case 17:                                        /* switch 2 */
        var_r3 = 0xC;
        break;
    }
    M2C_FIELD(((var_r3 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xA9) = temp_r5_3;
    func_ov003_021f9b30(arg0);
    if ((u8) temp_r3 != M2C_FIELD(temp_r0, u8 *, 9)) {
        func_0208fe30(0x10020);
    } else if (temp_r10 != M2C_FIELD(temp_r0, u8 *, 0xB)) {
        func_0208fe30(0x10019);
    }
    if (M2C_FIELD(temp_r0, s32 *, 0) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(), 0x1C)();
        return;
    }
    if (M2C_FIELD(temp_r0, s32 *, 4) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(), 0x20)();
}

void func_ov003_021f91a4(void *arg0) {
    s32 func_02084d3c(void *, s32);
    void func_02084d88(void *, s32);
    u8 buffer[0x24];

    if (func_02084d3c(buffer, 0x24) == 0) {
        return;
    }
    buffer[9] = M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4);
    buffer[10] = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 0xC);
    buffer[11] = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14);
    func_02084d88(buffer, 0x24);
}

/* Advance obj's animation step, or reset it, depending on its kind. */
void func_ov003_021f9200(void *obj) {
    void func_01ffa6fc(void *);
    u32 kind=(u32)(M2C_FIELD(obj,u8 *,0x3b)<<28)>>28;
    if ((u8)(kind==0)||(u8)(kind==2)||(u8)(kind==3)||(u8)(kind==4)) {
        if(M2C_FIELD(obj,u8 *,0x38)==12) func_01ffa6fc(obj);
        M2C_FIELD(obj,u8 *,0x38)++;
    } else if ((u8)(kind==1)||(u8)(kind==5)||(u8)(kind==6)||(u8)(kind==7)||(u8)(kind==8)) {
        func_01ffa6fc(obj);
    }
}

int func_ov003_021f92f4(void *arg0) {
    return 0;
}

