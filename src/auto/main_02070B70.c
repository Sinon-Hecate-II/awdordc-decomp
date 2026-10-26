/* 16 functions from 0x02070B70 to 0x02071A64 (main), found by ds-decomp. */
#include "common.h"

s32 func_02071140(void) {
    return 0x7FFFFFFF;
}

s32 func_02071438(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;

    var_r0_2 = arg0;
    var_r1 = arg1;
    if (((u32) (var_r0_2 * 2) <= 0xFF000000U) && ((u32) (var_r1 * 2) <= 0xFF000000U)) {
        if ((s32) (var_r0_2 - 0) < 0) {
            var_r0_2 = 0 - (var_r0_2 & ~0x80000000);
        }
        if ((s32) (var_r1 - 0) < 0) {
            var_r1 = 0 - (var_r1 & ~0x80000000);
        }
        M2C_ERROR(/* unknown instruction: mrs $r12, cpsr */);
        if (var_r0_2 > var_r1) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        M2C_ERROR(/* unknown instruction: msr cpsr_f, $r12 */);
        return var_r0;
    }
    M2C_ERROR(/* unknown instruction: mrs $r12, cpsr */);
    M2C_ERROR(/* unknown instruction: msr cpsr_f, $r12 */);
    return 0;
}

s32 func_0207191c(u32 arg0) {
    u32 temp_ip;
    u32 temp_r3;
    u32 var_r3;

    temp_ip = arg0 >> 0x17;
    var_r3 = arg0 << 9;
    if ((u8) temp_ip != 0) {
        if ((u8) temp_ip != 0xFF) {
            /* Duplicate return node #2. Try simplifying control flow for better match */
            return var_r3 << 0x14;
        }
        if (var_r3 <= 0U) {
            return 0;
        }
        return -1;
    }
    if (var_r3 == 0) {
        return 0;
    }
    temp_r3 = var_r3 >> 1;
    var_r3 = (temp_r3 << CLZ(temp_r3)) * 2;
    return var_r3 << 0x14;
}

u32 func_020719a0(s32 x) {
u32 a=x&0x7fffffff; s32 n=158; n-=a>>23;
if(n>0) {a=(a<<8)|0x80000000; {u32 v=a>>n; if(x&0x80000000)v=-v; return v;}}
return ~(x>>31)+0x80000000;
}

s32 func_020719d4(s32 arg0) {
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r3;
    s32 var_r0;
    u8 temp_r0_2;

    var_r0 = arg0;
    temp_r2 = var_r0 & 0x80000000;
    if (temp_r2 & 0x80000000) {
        var_r0 = 0 - var_r0;
    }
    if (var_r0 == 0) {
        return var_r0;
    }
    temp_r3 = CLZ(var_r0);
    temp_r0_2 = var_r0 << temp_r3;
    temp_r0 = temp_r2 | ((u32) (temp_r0_2 * 2) >> 9) | ((0x9E - temp_r3) << 0x17);
    if (temp_r0_2 == 0) {
        return temp_r0;
    }
    if (!(temp_r0_2 & 0x80)) {
        return temp_r0;
    }
    if (!(temp_r0_2 & 0x7F) && !(temp_r0 & 1)) {
        return temp_r0;
    }
    return temp_r0 + 1;
}

u8 func_02071a1c(u8 arg0) {
    s32 temp_ip;
    s32 var_r3;
    u8 temp_r0;
    u8 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        return var_r0;
    }
    var_r3 = 0x9E;
    if ((s32) (var_r0 - 0) >= 0) {
        temp_ip = CLZ(var_r0);
        var_r0 <<= temp_ip;
        var_r3 = 0x9E - temp_ip;
    }
    temp_r0 = ((u32) (var_r0 * 2) >> 9) | (var_r3 << 0x17);
    if (var_r0 == 0) {
        return temp_r0;
    }
    if (!(var_r0 & 0x80)) {
        return temp_r0;
    }
    if (!(var_r0 & 0x7F) && !(temp_r0 & 1)) {
        return temp_r0;
    }
    return temp_r0 + 1;
}

