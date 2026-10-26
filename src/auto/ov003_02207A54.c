/* 13 functions from 0x02207A54 to 0x0220856C (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_02207a54(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x36) << 0x18) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02207a70(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Reset the 6 child slots of the given structure to their initial state. */
void func_ov003_02207a8c(void *arg0) {
    s32 slotOff;
    u8 i;
    void *cfg;
    void *slot;
    void *slot2;
    void *slot3;

    cfg = M2C_FIELD(arg0, void **, 0x50);
    i = 0;
    M2C_FIELD(cfg, u16 *, 2) = (u16) M2C_FIELD(cfg, u16 *, 4);
    do {
        slotOff = i * 0x24;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 4) = 1;
        i += 1;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 6) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 8) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xA) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xB) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 0xE) = 0xCD;
        slot = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot, u16 *, 0xC) = (u16) M2C_FIELD(slot, u16 *, 0xE);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x10) = 8;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x12) = 0;
        slot2 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot2, u8 *, 0x11) = (u8) M2C_FIELD(slot2, u8 *, 0x12);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x14) = 5;
        slot3 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot3, s8 *, 0x13) = (s8) M2C_FIELD(slot3, s8 *, 0x14);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x15) = 1;
    } while ((u32) i < 6U);
    M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) | 0x20);
}

#pragma thumb off
void func_ov003_02207b84(void *arg0) {
M2C_UNK func_ov003_02207c7c(void *); M2C_UNK func_ov003_02207e80(void *);
s32 var_ip,var_lr,var_r5,var_r5_2,var_r6,var_r7; void *temp_r8; s32 var_r9,var_r10; void *temp_r1,*temp_r5;
temp_r1=M2C_FIELD(arg0,void **,0x50);var_r9=0;
M2C_FIELD(temp_r1,u16 *,2)=M2C_FIELD(temp_r1,u16 *,4);
if((s32)*M2C_FIELD(arg0,u8 **,0x44)>0){
var_r10=0;
do{
temp_r8=M2C_FIELD(arg0,u8 **,0x48)+var_r10;
temp_r5=*M2C_FIELD(arg0,void ***,0x5c);
if(temp_r5!=NULL)var_r5=M2C_FIELD(temp_r5,u16 *,8);else var_r5=-1U;
if(var_r9==(u8)(var_r5-11)){var_r6=256;var_r7=16;var_ip=1;var_lr=2;var_r5_2=3;}
else{var_r6=205;var_r7=8;var_ip=0;var_lr=5;var_r5_2=1;}
M2C_FIELD(temp_r8,s8 *,0x12)=var_ip;
M2C_FIELD(temp_r8,s8 *,0x14)=var_lr;
M2C_FIELD(temp_r8,s8 *,0x15)=var_r5_2;
M2C_FIELD(temp_r8,s16 *,0xe)=var_r6;
M2C_FIELD(temp_r8,s8 *,0x10)=var_r7;
var_r10+=36;var_r9++;
}while(var_r9<(s32)*M2C_FIELD(arg0,u8 **,0x44));
}
func_ov003_02207e80(arg0);func_ov003_02207c7c(arg0);
}
u8 func_ov003_02207c5c(void *arg0) {
    s32 var_r0;
    void *temp_r0;

    temp_r0 = *M2C_FIELD(arg0, void ***, 0x5C);
    if (temp_r0 != NULL) {
        var_r0 = M2C_FIELD(temp_r0, u16 *, 8);
    } else {
        var_r0 = -1;
    }
    return (u8) (var_r0 - 0xB);
}

u8 func_ov003_02207e38(void *arg0, s32 arg1) {
    s32 func_ov003_02206690(s32, s32, s32);
    s32 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if ((var_r0 & 0xFF) && (func_ov003_02206690(arg1, 2, 4) != 0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (u8) var_r0;
}

u8 func_ov003_0220801c(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_022084f0(void *arg0) {
    M2C_UNK func_020a91a8(s32);
    M2C_UNK func_ov003_02208034(void *);
    void *temp_r6;
    void *var_r5;
    s32 var_r4;
    s32 var_r7;

    var_r4 = 0;
    var_r5 = arg0;
    if ((s32) *M2C_FIELD(var_r5, u8 **, 0x44) > 0) {
        var_r7 = 0;
        do {
            temp_r6 = M2C_FIELD(var_r5, s32 *, 0x48) + var_r7;
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x18));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x1C));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x20));
            ++var_r4;
            var_r7 += 0x24;
        } while (var_r4 < (s32) *M2C_FIELD(var_r5, u8 **, 0x44));
    }
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x18));
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x1C));
    func_ov003_02208034(var_r5);
}

