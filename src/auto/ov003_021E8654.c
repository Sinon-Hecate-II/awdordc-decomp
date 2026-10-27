/* 9 functions from 0x021E8654 to 0x021E9638 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021e8654(void *p,s32 delta,s32 force){
s32 func_ov003_021e6cac(s16,s16,s16);
s32 next=delta+M2C_FIELD(p,s32*,4);
if(func_ov003_021e6cac((s16)next,(s16)M2C_FIELD(p,s32*,12),(s16)M2C_FIELD(p,s32*,8))||force){
M2C_FIELD(p,s32*,4)=next;
if(M2C_FIELD(p,u8*,20)){
while(M2C_FIELD(p,s32*,4)>M2C_FIELD(p,s32*,8))
M2C_FIELD(p,s32*,4)-=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
while(M2C_FIELD(p,s32*,4)<M2C_FIELD(p,s32*,12))
M2C_FIELD(p,s32*,4)+=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
}else{
s32 x=M2C_FIELD(p,s32*,4),hi=M2C_FIELD(p,s32*,8);
if(x<=hi){hi=M2C_FIELD(p,s32*,12);if(x>=hi)hi=x;}
M2C_FIELD(p,s32*,4)=hi;
}
}else{
s32 x=M2C_FIELD(p,s32*,8);
if(next<=x){x=M2C_FIELD(p,s32*,12);if(next>=x)x=next;}
M2C_FIELD(p,s32*,4)=x;
if(M2C_FIELD(p,u8*,20)){
while(M2C_FIELD(p,s32*,4)>M2C_FIELD(p,s32*,8))
M2C_FIELD(p,s32*,4)-=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
while(M2C_FIELD(p,s32*,4)<M2C_FIELD(p,s32*,12))
M2C_FIELD(p,s32*,4)+=M2C_FIELD(p,s32*,8)-M2C_FIELD(p,s32*,12)+1;
}else{
s32 x=M2C_FIELD(p,s32*,4),hi=M2C_FIELD(p,s32*,8);
if(x<=hi){hi=M2C_FIELD(p,s32*,12);if(x>=hi)hi=x;}
M2C_FIELD(p,s32*,4)=hi;
}
}
}

void func_ov003_021e87d0(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    M2C_FIELD(arg0, s16 *, 0x36) = arg2;
}

void func_ov003_021e87dc(void *arg0) {
    M2C_UNK func_020aacf0(s32);
    s32 var_r0;
    s32 var_r0_2;
    u8 var_r8;
    void *temp_r0;
    void *temp_r2;
    void *temp_r3;

    var_r8 = 0;
    M2C_FIELD(arg0, u8 *, 5) = -1U;
    M2C_FIELD(arg0, u8 *, 6) = -1U;
    do {
        func_020aacf0(M2C_FIELD((arg0 + (var_r8 * 4)), s32 *, 0x78));
        temp_r3 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x78);
        var_r0 = 1;
        temp_r2 = M2C_FIELD(temp_r3, void **, 0x64);
        if ((M2C_FIELD(temp_r2, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(temp_r3, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(temp_r2, s8 *, 0xC) != 1))) {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 5) = var_r8;
        }
        temp_r0 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x78);
        if ((((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(temp_r0, s32 *, 0x40) << 6) >> 0x18)) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 6) = var_r8;
        }
        var_r8 += 1;
    } while ((u32) var_r8 < 0x1AU);
}

void func_ov003_021e8f80(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 0x39) = (u8) ((M2C_FIELD(arg0, u8 *, 0x39) & ~1) | (arg1 & 1));
}

