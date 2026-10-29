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

u8 func_ov003_021e88a4(void *arg0) {
s32 result=1;
void *p=M2C_FIELD(arg0,void **,0x64);
if(M2C_FIELD(p,s8 *,0xb)!=1 && ((((u32)(M2C_FIELD(arg0,u8 *,0x59)<<27)>>31)==0) || M2C_FIELD(p,s8 *,0xc)!=1))result=0;
return result;
}

void func_ov003_021e88e0(void) {
s32 func_02084d3c(s32 *,M2C_UNK);
M2C_UNK func_02084d88(s32 *,M2C_UNK);
s32 buffer[9];
if(func_02084d3c(buffer,0x24)==0)return;
buffer[0]=1;
func_02084d88(buffer,0x24);
}

void func_ov003_021e891c(void) {
s32 func_02084d3c(s32 *,M2C_UNK);
M2C_UNK func_02084d88(s32 *,M2C_UNK);
s32 buffer[9];
if(func_02084d3c(buffer,0x24)==0)return;
buffer[1]=1;
func_02084d88(buffer,0x24);
}

void func_ov003_021e8958(void *arg0) { (void)arg0; }

void func_ov003_021e8f80(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 0x39) = (u8) ((M2C_FIELD(arg0, u8 *, 0x39) & ~1) | (arg1 & 1));
}

void func_ov003_021e8f98(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, s32, M2C_UNK, s32, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    void *func_020ab1c4(M2C_UNK);
    s32 func_ov003_022004a8(u8);
    s32 spC;
    s32 sp8;
    s16 temp_r11;
    s16 temp_r11_2;
    s16 temp_r11_3;
    s16 temp_r4_6;
    s16 temp_r5;
    s16 temp_r5_2;
    s16 temp_r5_5;
    s16 temp_r5_6;
    s16 temp_r5_7;
    s16 temp_r5_8;
    s16 temp_r6;
    s16 temp_r6_10;
    s16 temp_r6_2;
    s16 temp_r6_3;
    s16 temp_r6_4;
    s16 temp_r6_5;
    s16 temp_r6_6;
    s16 temp_r6_7;
    s16 temp_r6_8;
    s16 temp_r6_9;
    s16 temp_r7_4;
    s32 temp_r7_3;
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    u16 temp_r4_3;
    u16 temp_r4_4;
    u16 temp_r4_5;
    u16 temp_r7;
    u16 temp_r7_2;
    u16 temp_r7_5;
    u16 temp_r7_6;
    u16 temp_r7_7;
    u16 temp_r7_8;
    u16 temp_r7_9;
    u8 var_r8;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_7;
    void *temp_r4_8;
    void *temp_r5_3;
    void *temp_r5_4;

    M2C_FIELD(arg0, void **, 0) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 0), 2, 0x158, 3, 1);
    temp_r4 = M2C_FIELD(arg0, void **, 0);
    func_02088e84(temp_r4, 0xE0, 0xA0, 0xE0, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r5 = M2C_FIELD(temp_r4, s16 *, 0x52);
        temp_r6 = M2C_FIELD(temp_r4, s16 *, 0x50);
        temp_r7 = func_020aae10(temp_r4);
        func_02087d84(M2C_FIELD(temp_r4, void **, 0x64), 1, temp_r6, temp_r5, (s32) temp_r7, (s32) func_020aae44(temp_r4));
    }
    func_020aad18(M2C_FIELD(arg0, void **, 0));
    func_02088da8(M2C_FIELD(arg0, void **, 0));
    M2C_FIELD(arg0, void **, 4) = func_020ab1c4(arg1);
    func_020aab24(M2C_FIELD(arg0, void **, 4), 0x1F, 0x140, 3, 0);
    temp_r4_2 = M2C_FIELD(arg0, void **, 4);
    func_02088e84(temp_r4_2, 0x60, 0xA4, 0x60, 0xC0);
    if (M2C_FIELD(M2C_FIELD(temp_r4_2, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        temp_r5_2 = M2C_FIELD(temp_r4_2, s16 *, 0x52);
        temp_r6_2 = M2C_FIELD(temp_r4_2, s16 *, 0x50);
        temp_r7_2 = func_020aae10(temp_r4_2);
        func_02087d84(M2C_FIELD(temp_r4_2, void **, 0x64), 1, temp_r6_2, temp_r5_2, (s32) temp_r7_2, (s32) func_020aae44(temp_r4_2));
    }
    func_020aad18(M2C_FIELD(arg0, void **, 4));
    func_02088da8(M2C_FIELD(arg0, void **, 4));
    var_r8 = 0;
    spC = -0x20;
    do {
        temp_r7_3 = func_ov003_022004a8(var_r8);
        temp_r1 = arg0 + (var_r8 * 4);
        M2C_FIELD(temp_r1, void **, 8) = func_020ab1c4(arg1);
        func_020aab24(M2C_FIELD(temp_r1, void **, 8), 0x17, 0x168, 3, 0);
        temp_r5_3 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 8);
        sp8 = (s32) (s16) (temp_r7_3 - 1);
        func_02088e84(temp_r5_3, sp8, 0x48, sp8, 0x48);
        if (M2C_FIELD(M2C_FIELD(temp_r5_3, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            temp_r11 = M2C_FIELD(temp_r5_3, s16 *, 0x52);
            temp_r6_3 = M2C_FIELD(temp_r5_3, s16 *, 0x50);
            temp_r4_3 = func_020aae10(temp_r5_3);
            func_02087d84(M2C_FIELD(temp_r5_3, void **, 0x64), 1, temp_r6_3, temp_r11, (s32) temp_r4_3, (s32) func_020aae44(temp_r5_3));
        }
        M2C_FIELD(temp_r5_3, s16 *, 0x34) = (s16) sp8;
        M2C_FIELD(temp_r5_3, s16 *, 0x36) = 0x48;
        if (M2C_FIELD(M2C_FIELD(temp_r5_3, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r11_2 = M2C_FIELD(temp_r5_3, s16 *, 0x52);
            temp_r6_4 = M2C_FIELD(temp_r5_3, s16 *, 0x50);
            temp_r4_4 = func_020aae10(temp_r5_3);
            func_02087d84(M2C_FIELD(temp_r5_3, void **, 0x64), 1, temp_r6_4, temp_r11_2, (s32) temp_r4_4, (s32) func_020aae44(temp_r5_3));
        }
        func_02088da8(M2C_FIELD((arg0 + (var_r8 * 4)), void **, 8));
        temp_r1_2 = arg0 + (var_r8 * 4);
        M2C_FIELD(temp_r1_2, void **, 0x18) = func_020ab1c4(arg1);
        func_020aab24(M2C_FIELD(temp_r1_2, void **, 0x18), 0x18, 0x16C, 3, 0);
        temp_r7_4 = temp_r7_3 + 0x28;
        temp_r5_4 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x18);
        func_02088e84(temp_r5_4, (s32) temp_r7_4, 0x48, (s32) temp_r7_4, 0x48);
        if (M2C_FIELD(M2C_FIELD(temp_r5_4, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_5 = 1;
        } else {
            var_r0_5 = 0;
        }
        if (var_r0_5 & 0xFF) {
            temp_r11_3 = M2C_FIELD(temp_r5_4, s16 *, 0x52);
            temp_r6_5 = M2C_FIELD(temp_r5_4, s16 *, 0x50);
            temp_r4_5 = func_020aae10(temp_r5_4);
            func_02087d84(M2C_FIELD(temp_r5_4, void **, 0x64), 1, temp_r6_5, temp_r11_3, (s32) temp_r4_5, (s32) func_020aae44(temp_r5_4));
        }
        M2C_FIELD(temp_r5_4, s16 *, 0x34) = temp_r7_4;
        M2C_FIELD(temp_r5_4, s16 *, 0x36) = 0x48;
        if (M2C_FIELD(M2C_FIELD(temp_r5_4, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_6 = 1;
        } else {
            var_r0_6 = 0;
        }
        if (var_r0_6 & 0xFF) {
            temp_r4_6 = M2C_FIELD(temp_r5_4, s16 *, 0x52);
            temp_r6_6 = M2C_FIELD(temp_r5_4, s16 *, 0x50);
            temp_r7_5 = func_020aae10(temp_r5_4);
            func_02087d84(M2C_FIELD(temp_r5_4, void **, 0x64), 1, temp_r6_6, temp_r4_6, (s32) temp_r7_5, (s32) func_020aae44(temp_r5_4));
        }
        func_02088da8(M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x18));
        temp_r1_3 = arg0 + (var_r8 * 4);
        M2C_FIELD(temp_r1_3, void **, 0x28) = func_020ab1c4(arg1);
        func_020aab24(M2C_FIELD(temp_r1_3, void **, 0x28), 8, 0x170, 3, 0);
        temp_r4_7 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x28);
        func_02088e84(temp_r4_7, spC, 0, spC, 0);
        if (M2C_FIELD(M2C_FIELD(temp_r4_7, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_7 = 1;
        } else {
            var_r0_7 = 0;
        }
        if (var_r0_7 & 0xFF) {
            temp_r5_5 = M2C_FIELD(temp_r4_7, s16 *, 0x52);
            temp_r6_7 = M2C_FIELD(temp_r4_7, s16 *, 0x50);
            temp_r7_6 = func_020aae10(temp_r4_7);
            func_02087d84(M2C_FIELD(temp_r4_7, void **, 0x64), 1, temp_r6_7, temp_r5_5, (s32) temp_r7_6, (s32) func_020aae44(temp_r4_7));
        }
        M2C_FIELD(temp_r4_7, s16 *, 0x34) = (s16) spC;
        M2C_FIELD(temp_r4_7, s16 *, 0x36) = 0;
        if (M2C_FIELD(M2C_FIELD(temp_r4_7, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_8 = 1;
        } else {
            var_r0_8 = 0;
        }
        if (var_r0_8 & 0xFF) {
            temp_r5_6 = M2C_FIELD(temp_r4_7, s16 *, 0x52);
            temp_r6_8 = M2C_FIELD(temp_r4_7, s16 *, 0x50);
            temp_r7_7 = func_020aae10(temp_r4_7);
            func_02087d84(M2C_FIELD(temp_r4_7, void **, 0x64), 1, temp_r6_8, temp_r5_6, (s32) temp_r7_7, (s32) func_020aae44(temp_r4_7));
        }
        func_02088da8(M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x28));
        temp_r1_4 = arg0 + (var_r8 * 4);
        M2C_FIELD(temp_r1_4, void **, 0x38) = func_020ab1c4(arg1);
        func_020aab24(M2C_FIELD(temp_r1_4, void **, 0x38), 9, 0x178, 3, 0);
        temp_r4_8 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x38);
        func_02088e84(temp_r4_8, spC, 0, spC, 0);
        if (M2C_FIELD(M2C_FIELD(temp_r4_8, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_9 = 1;
        } else {
            var_r0_9 = 0;
        }
        if (var_r0_9 & 0xFF) {
            temp_r5_7 = M2C_FIELD(temp_r4_8, s16 *, 0x52);
            temp_r6_9 = M2C_FIELD(temp_r4_8, s16 *, 0x50);
            temp_r7_8 = func_020aae10(temp_r4_8);
            func_02087d84(M2C_FIELD(temp_r4_8, void **, 0x64), 1, temp_r6_9, temp_r5_7, (s32) temp_r7_8, (s32) func_020aae44(temp_r4_8));
        }
        M2C_FIELD(temp_r4_8, s16 *, 0x34) = (s16) spC;
        M2C_FIELD(temp_r4_8, s16 *, 0x36) = 0;
        if (M2C_FIELD(M2C_FIELD(temp_r4_8, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_10 = 1;
        } else {
            var_r0_10 = 0;
        }
        if (var_r0_10 & 0xFF) {
            temp_r5_8 = M2C_FIELD(temp_r4_8, s16 *, 0x52);
            temp_r6_10 = M2C_FIELD(temp_r4_8, s16 *, 0x50);
            temp_r7_9 = func_020aae10(temp_r4_8);
            func_02087d84(M2C_FIELD(temp_r4_8, void **, 0x64), 1, temp_r6_10, temp_r5_8, (s32) temp_r7_9, (s32) func_020aae44(temp_r4_8));
        }
        func_02088da8(M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0x38));
        var_r8 += 1;
    } while ((u32) var_r8 < 4U);
}

