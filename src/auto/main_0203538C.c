/* 2 functions from 0x0203538C to 0x020362D4 (main), found by ds-decomp. */
#include "common.h"

void func_0203538c(void) {
}

void func_02036290(s32 arg0) {
    M2C_UNK func_02006564(void *);
    M2C_UNK func_020065e8(void *);
    extern void *data_0213d138;
    func_02006564(data_0213d138 + 0x11DC);
    M2C_FIELD(data_0213d138, s32 *, 0x1000) = arg0;
    func_020065e8(data_0213d138 + 0x11DC);
}
