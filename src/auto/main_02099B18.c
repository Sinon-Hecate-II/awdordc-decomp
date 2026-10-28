/* 4 functions from 0x02099B18 to 0x02099E6C (main), found by ds-decomp. */
#include "common.h"

u8 func_02099ae8(u8 *arg0);
u8 func_02099b00(u8 *arg0);
s32 func_02099b18(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    register s32 r8 asm("r8") = arg0;
    register s32 r7 asm("r7") = arg1;
    register s32 r6 asm("r6") = arg2;
    register s32 r4 asm("r4") = 0;
    register s32 r5 asm("r5") = 0;
    register s32 r0 asm("r0");
    u8 var_r1;

    if (r8 == 0) {
        return 0;
    }
    r0 = *(u8 *)r8;
    if (r0 == 0) {
        return 0;
    }
    r4 = 0;
    r5 = r4;
loop:
    switch (r0) {
        case 3:
        case 5:
        case 6:
        case 7:
        case 11:
        case 14:
            if (r6 == 0) {
                return 0;
            }
            r5 = r4 + 1;
            break;
        case 4:
            r5 = r4 + 2;
            break;
        case 9:
            r5 = r4 + 1;
            if (r0 >= 0x80) {
                if (r0 <= 0x99) {
                    r5 = r4 + 2;
                } else if (r0 >= 0x9A) {
                    if (r0 <= 0xB3) {
                        r5 = r5 + 1;
                    }
                }
            }
            break;
        case 12:
            var_r1 = ((u8 *)r8)[1];
            r5 = r4 + 1;
            if ((u8)(var_r1 + 0x80) <= 1) {
                r5 = r4 + 2;
            }
            break;
        case 17:
            var_r1 = ((u8 *)r8)[2];
            var_r1 = (u8)(var_r1 - 0x80);
            switch (var_r1) {
                case 0:
                    r5 = r4 + 5;
                    break;
                case 6:
                    r5 = r4 + 3;
                    break;
                case 8:
                    r5 = r4 + 3;
                    break;
                case 9:
                    r5 = r4 + 3;
                    break;
                case 10:
                    r5 = r4 + 3;
                    break;
                case 11:
                    r5 = r4 + 3;
                    break;
                case 12:
                    r5 = r4 + 4;
                    break;
                case 13:
                    r5 = r4 + 4;
                    break;
                case 14:
                    r5 = r4 + 3;
                    break;
                default:
                    break;
            }
            break;
        case 18:
            var_r1 = ((u8 *)r8)[1];
            if (var_r1 == 0x80) {
                r5 = r4 + 2;
            } else {
                r5 = r4 + 3;
            }
            break;
        case 19:
        case 27:
            r5 = r4 + 3;
            break;
        case 20:
            r5 = r4 + 2;
            break;
        case 21:
            if (func_02099ae8((u8 *)r8)) {
                r5 = r5 + 2;
            } else if (func_02099b00((u8 *)r8)) {
                r5 = r5 + 2;
            } else {
                r5 = r5 + 1;
            }
            goto advance;
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 28:
        case 29:
        case 30:
            r5 = r4 + 3;
            break;
        default:
            r5 = r4 + 2;
            break;
    }

    if (r7 == r0) {
        return (s32)r8;
    }
advance:
    r8 = r8 + r5;
    r0 = *(u8 *)r8;
    if (r0 == 0) {
        return 0;
    }
    r5 = r4;
    goto loop;
}

u8 func_02099dcc(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 var_r0;

    if (func_02099b18(arg0, 5, 1) != 0) {
        return 0U;
    }
    if (func_02099b18(arg0, 6, 1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02099e10(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 value;
    temp_r0 = (void *)func_02099b18(arg0, 0x15, 1);
    if (temp_r0 != NULL) {
        value = M2C_FIELD(temp_r0, u8 *, 1);
        if (value == 0x80) return 0;
        if (value == 0x81) return 1;
        if (value == 0x82) return 2;
    }
    return 1;
}

void func_02099e58(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x55) = 0;
    M2C_FIELD(arg0, s8 *, 0x54) = -2;
}
