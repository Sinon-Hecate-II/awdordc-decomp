/* 4 functions from 0x0217E798 to 0x0217F754 (ov000), found by ds-decomp. */
#include "common.h"

/* Ticks a unit state: handles 0x40 pending-swap, early-outs on 0x80/0x100 flags, dispatches cases 2/9. */
void func_ov000_0217e798(M2C_UNK arg0, M2C_UNK arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    M2C_UNK func_ov000_0217e8c4(M2C_UNK, M2C_UNK, u8 *, u8 *, u8 *);
    M2C_UNK func_ov000_0217f754(M2C_UNK, M2C_UNK, u8 *, u8 *);
    M2C_UNK func_ov000_02180268(M2C_UNK, M2C_UNK);
    extern void **data_027e0058;
    extern void *data_ov000_021df580;
    u16 temp_r1_2;
    u8 temp_r0;
    u8 temp_r1;
    u8 temp_r2;
    void *temp_r3;

    if (M2C_FIELD(data_ov000_021df580, u16 *, 8) & 0x40) {
        temp_r3 = M2C_FIELD(*data_027e0058, void **, 0x52D0);
        temp_r2 = M2C_FIELD(temp_r3, u8 *, 0xC);
        M2C_FIELD(temp_r3, u8 *, 0xC) = (u8) M2C_FIELD(temp_r3, u8 *, 0xD);
        M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xD) = temp_r2;
        if (*arg2 == 8) {
            temp_r1 = *arg3;
            *arg3 = *arg4;
            *arg4 = temp_r1;
        }
        M2C_FIELD(data_ov000_021df580, u16 *, 8) = (u16) (M2C_FIELD(data_ov000_021df580, u16 *, 8) & ~0x40);
    }
    temp_r1_2 = M2C_FIELD(data_ov000_021df580, u16 *, 8);
    if (temp_r1_2 & 0x80) {
        return;
    }
    if (temp_r1_2 & 0x100) {
        *arg2 = 0xE;
        return;
    }
    temp_r0 = *arg2;
    switch (temp_r0) {                              /* irregular */
    case 2:
        if (!(temp_r1_2 & 1)) {
            func_ov000_0217f754(arg0, arg1, arg2, arg3);
        }
        break;
    case 9:
        func_ov000_02180268(arg0, arg1);
        break;
    }
    func_ov000_0217e8c4(arg0, arg1, arg2, arg3, arg4);
}
