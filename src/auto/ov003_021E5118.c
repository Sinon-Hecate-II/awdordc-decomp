/* 6 functions from 0x021E5118 to 0x021E5E24 (ov003), found by ds-decomp. */
#include "common.h"
static inline void CallSlot20(void *p) { M2C_FIELD(M2C_FIELD(p,void **,0),void (**)(void *),32)(p); }

void func_ov003_021e5b18(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020aacf0(void *);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    register u8 temp_r4;
    s32 var_r0;
    u16 temp_r5;
    unsigned int var_r3;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r2;

    temp_r4 = M2C_FIELD(data_02101e88, u8 *, 0x12);
    temp_r5 = *data_02101e84;
    func_020aacf0(*M2C_FIELD(arg0, void ***, 0x48));
    var_r3 = 1;
    temp_r2 = *M2C_FIELD(arg0, void ***, 0x48);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xB);
    if ((var_r0 != 1) && ((var_r0 = (u32) ((u32) (M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1B) >> 0x1F), (!var_r0)) || (var_r0 = M2C_FIELD(temp_r1, s8 *, 0xC), (var_r0 != 1)))) {
        var_r3 = 0;
    }
    if (var_r3 & 0xFF) {
        func_0208fe30(0x1000F);
        temp_r0 = *M2C_FIELD(arg0, void ***, 0x48);
        if (M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
            M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
        }
        CallSlot20(arg0);
    }
    if (temp_r4 != 0) {
        return;
    }
    if (!(temp_r5 & 2)) {
        return;
    }
    func_0208fe30(0x1000F);
    temp_r0_2 = *M2C_FIELD(arg0, void ***, 0x48);
    if ((s32) M2C_FIELD(temp_r0_2, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0_2, s32 *, (unsigned)0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0xC;
    }
    CallSlot20(arg0);
}

void func_ov003_021e5c68(void *arg0) {
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e5c8c(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}
