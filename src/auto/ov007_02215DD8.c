/* 8 functions from 0x02215DD8 to 0x02216C94 (ov007), found by ds-decomp. */
#include "common.h"

s32 func_ov007_02215dd8(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 func_0207c330(s32, s32);
    s32 func_ov007_022156a4();
    extern void **data_027e0058;
    s32 temp_r0;
    s32 var_r6;
    void *temp_r2;

    var_r6 = 0;
loop_1:
    var_r6 += 1;
    if (var_r6 > 0x64) {
        return 0;
    }
    *arg0 = func_0207c330(0, M2C_FIELD(*data_027e0058, u16 *, 0x5144) - 1);
    temp_r0 = func_0207c330(0, M2C_FIELD(*data_027e0058, u16 *, 0x5146) - 1);
    *arg1 = temp_r0;
    temp_r2 = *data_027e0058;
    if ((arg2 == M2C_FIELD((temp_r2 + ((*arg0 + M2C_FIELD((temp_r2 + (temp_r0 * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) && (func_ov007_022156a4() != 0)) {
        return 1;
    }
    goto loop_1;
}

s32 func_ov007_02215e94(s32 *arg0, s32 *arg1, s32 arg2, void *arg3, s32 arg4) {
    s32 func_0207c330(s32, s32);
    s32 func_ov000_021a8a04(s16, s16, s16, s16);
    extern void **data_027e0058;
    s32 temp_r0;
    s32 temp_r1;
    s32 var_r5;

    var_r5 = 0;
loop_1:
    var_r5 += 1;
    if (var_r5 > 0x64) {
        return 0;
    }
    *arg0 = func_0207c330(0, M2C_FIELD(*data_027e0058, u16 *, 0x5144) - 1);
    *arg1 = func_0207c330(0, M2C_FIELD(*data_027e0058, u16 *, 0x5146) - 1);
    temp_r1 = *arg0;
    if ((arg2 == M2C_FIELD((*data_027e0058 + ((temp_r1 + M2C_FIELD((*data_027e0058 + (*arg1 * 2)), u16 *, 0x3758)) * 2)), u16 *, 0xA10)) && (func_ov000_021a8a04(M2C_FIELD(arg3, s16 *, 0), M2C_FIELD(arg3, s16 *, 2), (s16) temp_r1, (s16) *arg1) <= arg4)) {
        return 1;
    }
    goto loop_1;
}

void func_ov007_02216bf4(void) {
    s32 func_ov007_02214e24(void);
    s32 func_ov007_02214d88(s32, s32);
    s32 func_ov007_02215bc4(s32 *, s32 *, s32);
    s32 func_ov007_02215254(s32, s32, s32);
    s32 Map_MarkUnitsMoved(void);
    s32 func_ov007_02216118(s32, s32);
    extern u8 data_ov007_02221a84[];

    s32 sp4;
    s32 sp0;
    s32 r10;
    s32 r9 = 0;
    s32 r6 = 2;
    s32 r11 = 1;
    s32 r4 = 0x1E;
    u8 *r5 = data_ov007_02221a84;

    func_ov007_02214e24();
    r10 = func_ov007_02214d88(8, 0xC);
    if (r10 <= 0) {
        goto end;
    }
    do {
        if (func_ov007_02215bc4(&sp4, &sp0, r11) == 0) {
            return;
        }
        func_ov007_02215254(sp4, sp0, 0x20);
        *(r5 + sp0 * r4 + sp4) = r6;
        r9++;
    } while (r9 < r10);
end:
    Map_MarkUnitsMoved();
    func_ov007_02216118(0x20, 1);
}

