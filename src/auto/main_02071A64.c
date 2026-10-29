/* 10 functions from 0x02071A64 to 0x02072A54 (main), found by ds-decomp. */
#include "common.h"

s32 func_02071a64(u32 arg0, u32 arg1) {
    s32 temp_ip_2;
    s32 temp_ip_3;
    s32 temp_ip_4;
    s32 temp_r0;
    s32 temp_r1;
    s32 temp_r1_4;
    s32 temp_r1_5;
    s32 temp_r2;
    s32 temp_r3;
    s32 var_ip_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r3;
    u32 temp_ip;
    u32 temp_ip_5;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r1_2;
    u32 temp_r1_3;
    u8 var_ip;

    temp_r2 = (arg0 ^ arg1) & 0x80000000;
    var_r3 = 0xFF & (arg0 >> 0x17);
    temp_r0 = arg0 << 8;
    if ((var_r3 != 0) && (var_r3 != 0xFF)) {
        var_r0_4 = temp_r0 | 0x80000000;
        var_ip = 0xFF & (arg1 >> 0x17);
        var_r1 = arg1 << 8;
        if ((var_ip != 0) && (var_ip != 0xFF)) {
            var_r1_2 = var_r1 | 0x80000000;
            goto block_9;
        }
        if (var_ip != 0) {
            goto block_29;
        }
        goto block_39;
    }
    if (var_r3 != 0) {
        if ((temp_r0 * 2) == 0) {
            temp_ip = arg1 >> 0x17;
            temp_r1 = arg1 << 9;
            if ((u8) temp_ip != 0) {
                if (((s32) (u8) temp_ip >= 0xFF) && (temp_r1 != 0)) {
                    /* Duplicate return node #56. Try simplifying control flow for better match */
                    return 0x7FFFFFFF;
                }
                /* Duplicate return node #55. Try simplifying control flow for better match */
                return temp_r2 | (0xFF000000U >> 1);
            }
            if (temp_r1 != 0) {
                /* Duplicate return node #55. Try simplifying control flow for better match */
                return temp_r2 | (0xFF000000U >> 1);
            }
            /* Duplicate return node #57. Try simplifying control flow for better match */
            return 0x7FFFFFFF;
        }
        /* Duplicate return node #56. Try simplifying control flow for better match */
        return 0x7FFFFFFF;
    }
    temp_r0_2 = temp_r0 * 2;
    if (temp_r0_2 != 0) {
        temp_r0_3 = temp_r0_2 >> 1;
        temp_r3 = CLZ(temp_r0_3);
        var_r0_4 = temp_r0_3 << temp_r3;
        var_r3 = 1 - temp_r3;
        var_r1 = arg1 << 8;
        var_ip = (u8) (arg1 >> 0x17);
        if (var_ip != 0) {
            if (var_ip != 0xFF) {
                var_r1_2 = var_r1 | 0x80000000;
                goto block_9;
            }
block_29:
            if ((var_r1 * 2) == 0) {
                return temp_r2 | (0xFF000000U >> 1);
            }
            /* Duplicate return node #56. Try simplifying control flow for better match */
            return 0x7FFFFFFF;
        }
block_39:
        temp_r1_2 = var_r1 * 2;
        if (temp_r1_2 != 0) {
            temp_r1_3 = temp_r1_2 >> 1;
            temp_ip_2 = CLZ(temp_r1_3);
            var_r1_2 = temp_r1_3 << temp_ip_2;
            var_ip = 1 - temp_ip_2;
block_9:
            var_ip_2 = var_r3 + var_ip;
            temp_r1_4 = var_r0_4 * var_r1_2;
            var_r0_5 = MULTU_HI(var_r0_4, var_r1_2);
            if (var_r0_5 >= 0) {
                var_r0_5 *= 2;
                var_ip_2 -= 1;
            }
            temp_ip_3 = var_ip_2 - 0x7F;
            if (temp_ip_3 >= 0) {
                if (temp_ip_3 < 0xFE) {
                    var_r0_3 = (temp_r2 | ((u32) var_r0_5 >> 8)) + (temp_ip_3 << 0x17);
                    if (!((u8) var_r0_5 & 0x80)) {
                        return var_r0_3;
                    }
                    if (((temp_r1_4 | ((u8) var_r0_5 << 0x19)) == 0) && !(var_r0_3 & 1)) {

                    } else {
                        var_r0_3 += 1;
                    }
                    return var_r0_3;
                }
                return temp_r2 | (0xFF000000U >> 1);
            }
            if (temp_ip_3 != -0x18) {
                if ((s32) (temp_ip_3 - -0x18) >= 0) {
                    if (temp_r1_4 != 0) {
                        var_r0_5 |= 1;
                    }
                    temp_ip_4 = 0 - temp_ip_3;
                    var_r0_2 = temp_r2 | ((u32) ((u32) var_r0_5 >> 8) >> temp_ip_4);
                    temp_r1_5 = var_r0_5 << (0x18 - temp_ip_4);
                    if (temp_r1_5 == 0) {
                        return var_r0_2;
                    }
                    if (!(temp_r1_5 & 0x80000000)) {
                        return var_r0_2;
                    }
                    if (((temp_r1_5 * 2) == 0) && !(var_r0_2 & 1)) {

                    } else {
                        var_r0_2 += 1;
                    }
                    return var_r0_2;
                }
                return temp_r2;
            }
            var_r0 = temp_r2;
            if ((var_r0_5 * 2) != 0) {
                var_r0 += 1;
            }
            return var_r0;
        }
        /* Duplicate return node #63. Try simplifying control flow for better match */
        return temp_r2;
    }
    temp_ip_5 = arg1 >> 0x17;
    if (((u8) temp_ip_5 != 0) && ((s32) (u8) temp_ip_5 >= 0xFF)) {
        if ((arg1 << 9) != 0) {
            return 0x7FFFFFFF;
        }
        return 0x7FFFFFFF;
    }
    return temp_r2;
}

f32 func_02071c50(f32 a, f32 b) {
    return a - b;
}

u64 func_02072088(u64 a,u64 b){return b?a/b:a;}

u64 func_020720d0(u64 a,u64 b){return a*b;}

M2C_UNK func_020724f8(M2C_UNK arg0, M2C_UNK arg1) { (void)arg0; (void)arg1; return 0; }

void func_02072a3c(void) {

}

s32 func_02072a40(void *a) {
    (void)a;
    return 3;
}

