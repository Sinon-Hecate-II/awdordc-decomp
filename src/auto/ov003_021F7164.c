/* 1 function from 0x021F7164 to 0x021F8C20 (ov003), found by ds-decomp. */
#include "common.h"

extern void func_ov003_021fca84(void *);
void func_ov003_021f7164(void *arg0) {
    u8 kind = *(u8 *)((u8 *)arg0 + 0x3b) & 0x0f;
    if (kind == 1) {
        return;
    }
    if (kind == 5) {
        return;
    }
    func_ov003_021fca84(arg0);
    if (*(u8 *)((u8 *)arg0 + 0x3e) & 0x40) {
        return;
    }
}
