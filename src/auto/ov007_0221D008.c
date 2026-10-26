/* 7 functions from 0x0221D008 to 0x0221E004 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221dbb0(u8 *arg0) {
    M2C_UNK func_020b1c60(u32);
    M2C_UNK func_ov007_0221d008();
    u8 temp_ip;
    extern void *data_02101e84;
    u16 temp_r1;
    u16 temp_r2;
    u8 var_r3;

    temp_ip = *arg0;
    temp_r1 = M2C_FIELD(data_02101e84, u16 *, 0);
    var_r3 = temp_ip;
    temp_r2 = M2C_FIELD(data_02101e84, u16 *, 2);
    if (temp_r1 & 1) {
        func_ov007_0221d008();
        return;
    }
    if (temp_r2 & 0x40) {
        switch (temp_ip) {                          /* switch 1; irregular */
        case 0x67:                                  /* switch 1 */
            if (temp_r2 == temp_r1) {
                var_r3 = 0x40;
            }
            break;
        case 0x68:                                  /* switch 1 */
            if (temp_r2 == temp_r1) {
                var_r3 = 0x42;
            }
            break;
        }
        if ((u32) var_r3 >= 0x67U) {
            if ((u32) var_r3 > 0x68U) {

            } else {
                goto block_25;
            }
        }
    } else if (temp_r2 & 0x80) {
        switch (temp_ip) {                          /* switch 2; irregular */
        case 0x67:                                  /* switch 2 */
            if (temp_r2 == temp_r1) {
                var_r3 = 4;
            }
            break;
        case 0x68:                                  /* switch 2 */
            if (temp_r2 == temp_r1) {
                var_r3 = 6;
            }
            break;
        }
        if (((u32) var_r3 >= 0x67U) && (0x68U >= var_r3)) {
            goto block_25;
        }
    } else {
block_25:
        if (temp_r2 & 0x20) {
            switch (var_r3) {                       /* switch 3; irregular */
            case 0x68:                              /* switch 3 */
                var_r3 = 0x67;
                break;
            case 0x67:                              /* switch 3 */
                var_r3 = 0x66;
                break;
            }
        } else if (temp_r2 & 0x10) {
            switch (var_r3) {                       /* switch 4; irregular */
            case 0x68:                              /* switch 4 */
                var_r3 = 0x69;
                break;
            case 0x67:                              /* switch 4 */
                var_r3 = 0x68;
                break;
            }
        }
    }
    if (temp_ip == var_r3) {
        return;
    }
    func_020b1c60((u32) var_r3);
}

void func_ov007_0221dcc0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221dcd4(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221dff0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

