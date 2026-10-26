/* 4 functions from 0x021F8C20 to 0x021F9B30 (ov003), found by ds-decomp. */
#include "common.h"

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

