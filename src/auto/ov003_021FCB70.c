/* 24 functions from 0x021FCB70 to 0x021FD850 (ov003), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
void func_ov003_021fcb70(void *arg0) {
M2C_UNK func_0208fe30(s32);s32 func_020c7f30(u16);
M2C_UNK func_ov006_022177c8(u16,void *);M2C_UNK func_ov006_02217c0c(u16,void *);M2C_UNK func_ov006_02217c30(u16,void *);
u16 unit;s16 index;u8 page;u8 *row;u32 mode=(u32)(M2C_FIELD(arg0,u8 *,0x3b)<<28)>>28;
if((u8)(mode==0)||(u8)(mode==2)||(u8)(mode==3)||(u8)(mode==4)||(u8)(mode==6)||(u8)(mode==7)||(u8)(mode==8)){
index=M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14);page=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4);
row=M2C_FIELD(arg0,u8 **,0x44)+(page<<9);
unit=((u16 *)(row+0x2e))[(u16)index];
}else unit=M2C_FIELD(arg0,u16 *,0x3c);
if((u8)(mode==6)){
if(func_020c7f30(unit)){func_ov003_021fc98c(arg0,1);func_ov006_022177c8(unit,arg0);func_0208fe30(0x1000d);return;}
func_0208fe30(0x1001d);return;
}
if((u8)(mode==7)){func_ov003_021fc98c(arg0,2);func_ov006_02217c30(unit,arg0);func_0208fe30(0x1000d);return;}
if(!(u8)(mode==8))return;
func_ov003_021fc98c(arg0,2);func_ov006_02217c0c(unit,arg0);func_0208fe30(0x1000d);
}
#pragma opt_common_subs reset
void func_ov003_021fcd10(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fcd24(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fcd30(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021fcd44(void *arg0) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02088f1c(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    M2C_UNK func_ov003_021f2008();
    s32 func_ov003_021f400c();
    s32 func_ov003_021f4064();
    s16 temp_r5;
    s16 temp_r6;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r1_4;
    s32 var_r1_5;
    s32 var_r1_6;
    u16 temp_r8;
    u32 temp_r0_2;
    void *temp_r0;
    void *temp_r1;
    void *temp_r3;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_5;

    temp_r4 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_r4, s16 *, 0xE) = func_ov003_021f153c();
    M2C_FIELD(temp_r4, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r4, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4, u16 *, 2) = (u16) M2C_FIELD(temp_r4, u16 *, 4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x64);
    M2C_FIELD(temp_r1, s16 *, 0xE) = -0x20;
    M2C_FIELD(temp_r1, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r1, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r1, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x68);
    if ((func_ov003_021f400c() == 0) && (func_ov003_021f4064() != 0)) {
        func_02088da8(M2C_FIELD(temp_r4_2, void **, 0));
        func_02088da8(M2C_FIELD(temp_r4_2, void **, 0xC));
        func_02088da8(M2C_FIELD(temp_r4_2, void **, 0x10));
        func_02088da8(M2C_FIELD(temp_r4_2, void **, 0x14));
    } else {
        func_02088f1c(M2C_FIELD(temp_r4_2, void **, 0));
        func_02088f1c(M2C_FIELD(temp_r4_2, void **, 0xC));
        func_02088f1c(M2C_FIELD(temp_r4_2, void **, 0x10));
        func_02088f1c(M2C_FIELD(temp_r4_2, void **, 0x14));
    }
    func_02088d94(M2C_FIELD(temp_r4_2, void **, 0x18));
    temp_r0 = M2C_FIELD(temp_r4_2, void **, 0x18);
    M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r0, s8 *, 0x5A) = 0;
    func_02088d94(M2C_FIELD(temp_r4_2, void **, 0x1C));
    temp_r3 = M2C_FIELD(temp_r4_2, void **, 0x1C);
    var_r0 = 0;
    M2C_FIELD(temp_r3, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r3, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r3, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r3, s8 *, 0x5A) = 0;
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 2) {
        var_r0 = 1;
    }
    if (var_r0 & 0xFF) {
        func_02088f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x20));
    }
    if ((s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x10) == 0) {
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (!(var_r0_2 & 0xFF)) {
            temp_r4_3 = M2C_FIELD(arg0, void **, 0x68);
            func_02088da8(M2C_FIELD(temp_r4_3, void **, 0x10));
            func_02088da8(M2C_FIELD(temp_r4_3, void **, 0x14));
        }
    }
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        func_02088f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x24));
        func_02088f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 4));
        func_02088da8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0));
        temp_r4_4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0);
        func_02088e84(temp_r4_4, 0xC0, 0xC0, 0xC0, 0xC0);
        if (M2C_FIELD(M2C_FIELD(temp_r4_4, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r5 = M2C_FIELD(temp_r4_4, s16 *, 0x52);
            temp_r6 = M2C_FIELD(temp_r4_4, s16 *, 0x50);
            temp_r8 = func_020aae10(temp_r4_4);
            func_02087d84(M2C_FIELD(temp_r4_4, void **, 0x64), 1, temp_r6, temp_r5, (s32) temp_r8, (s32) func_020aae44(temp_r4_4));
        }
    }
    temp_r4_5 = M2C_FIELD(arg0, void **, 0x6C);
    func_02088d94(M2C_FIELD(temp_r4_5, void **, 0));
    if ((func_ov003_021f400c() == 0) && (func_ov003_021f4064() != 0)) {
        M2C_FIELD(M2C_FIELD(temp_r4_5, void **, 0), s8 *, 0x59) = 0;
    }
    func_02088d94(M2C_FIELD(temp_r4_5, void **, 4));
    M2C_FIELD(arg0, u8 *, 0x3B) = (u8) (M2C_FIELD(arg0, u8 *, 0x3B) | 0x20);
    func_ov003_021f140c(1);
    temp_r0_2 = (u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C;
    if (temp_r0_2 == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    if (!(var_r1 & 0xFF)) {
        if (temp_r0_2 == 2) {
            var_r1_2 = 1;
        } else {
            var_r1_2 = 0;
        }
        if (!(var_r1_2 & 0xFF)) {
            if (temp_r0_2 == 3) {
                var_r1_3 = 1;
            } else {
                var_r1_3 = 0;
            }
            if (!(var_r1_3 & 0xFF)) {
                if (temp_r0_2 == 4) {
                    var_r1_4 = 1;
                } else {
                    var_r1_4 = 0;
                }
                if (!(var_r1_4 & 0xFF)) {
                    if (temp_r0_2 == 6) {
                        var_r1_5 = 1;
                    } else {
                        var_r1_5 = 0;
                    }
                    if (!(var_r1_5 & 0xFF)) {
                        if (temp_r0_2 == 7) {
                            var_r1_6 = 1;
                        } else {
                            var_r1_6 = 0;
                        }
                        if (!(var_r1_6 & 0xFF)) {
                            if (temp_r0_2 == 8) {
                                var_r0_5 = 1;
                            } else {
                                var_r0_5 = 0;
                            }
                            if (!(var_r0_5 & 0xFF)) {
                                return;
                            }
                            func_ov003_021f2008();
                            return;
                        }
                        func_ov003_021f2008();
                        return;
                    }
                    func_ov003_021f2008();
                    return;
                }
                func_ov003_021f2008();
                return;
            }
            func_ov003_021f2008();
            return;
        }
        func_ov003_021f2008();
        return;
    }
    func_ov003_021f2008();
}

void func_ov003_021fd094(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd0a0(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

/* Refreshes an entity's display data: reinitializes its two display objects and then releases the pending handles stored in its part list (plus an extra handle when the low state nibble equals 2). */
void func_ov003_021fd0b4(void *entity) {
    M2C_UNK func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    s32 func_ov003_021f15d4();
    s16 func_ov003_021f1608();
    s16 displayValue;
    s32 flag;
    void *first;
    void *second;
    void *parts;

    displayValue = func_ov003_021f1608();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = func_020a8ff4(first);
    M2C_FIELD(first, s16 *, 0x10) = displayValue;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = func_020a8ff4(second);
    M2C_FIELD(second, s16 *, 0x10) = -32;
    M2C_FIELD(second, s16 *, 0xC) = 12;
    M2C_FIELD(second, u16 *, 2) = M2C_FIELD(second, u16 *, 4);
    if (!func_ov003_021f15d4()) {
        return;
    }
    parts = M2C_FIELD(entity, void **, 0x68);
    func_02088ff4(M2C_FIELD(parts, s32 *, 0));
    func_02088ff4(M2C_FIELD(parts, s32 *, 4));
    func_02088ff4(M2C_FIELD(parts, s32 *, 8));
    func_02088ff4(M2C_FIELD(parts, s32 *, 12));
    func_02088ff4(M2C_FIELD(parts, s32 *, 16));
    func_02088ff4(M2C_FIELD(parts, s32 *, 20));
    if (((u32)(M2C_FIELD(entity, u8 *, 0x3b) << 28) >> 28) == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag & 255) {
        func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 32));
    }
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x6c), s32 *, 4));
}

void func_ov003_021fd18c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021fd1a0(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x58);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021fd1cc(void) {
    M2C_UNK func_ov003_021f66d4();
    func_ov003_021f66d4();
}

void func_ov003_021fd1d8(void) {
    M2C_UNK func_ov003_021f6724();
    func_ov003_021f6724();
}

void func_ov003_021fd1e4(void) {
    M2C_UNK func_ov003_021f8c20();
    func_ov003_021f8c20();
}

void func_ov003_021fd1f0(void *arg0) {
    s32 func_020846a4();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f152c(M2C_UNK);
    s32 func_ov003_021f153c();
    M2C_UNK func_ov003_022006dc(M2C_UNK);
    M2C_UNK func_ov006_02217178(void *);
    s32 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        return;
    }
    if (func_020846a4() == 0) {
        return;
    }
    if (func_ov003_021f153c() != 0) {
        return;
    }
    func_ov003_021f152c(1);
    func_ov003_021f140c(1);
    func_ov003_022006dc(1);
    func_ov006_02217178(arg0);
}

u8 func_ov003_021fd250(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021fd270(void *arg0) {
    s32 a, b, c, result;
    u32 value;
    s32 either;
    result = 1;
    either = 1;
    value = (u32)(M2C_FIELD(arg0, u8 *, 0x3B) << 28) >> 28;
    if (value == 6) a = 1; else a = 0;
    if (!(a & 0xFF)) {
        if (value == 7) b = 1; else b = 0;
        if (!(b & 0xFF)) either = 0;
    }
    if (either == 0) {
        if (value == 8) c = 1; else c = 0;
        if (!(c & 0xFF)) result = 0;
    }
    return result;
}

/* Clears the low state bits of an entity, switches it to state 4 handling, and updates its display lists/palette. */
void func_ov003_021fd2d0(void *entity) {
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_020893a8(s32, s32, M2C_UNK, s32);
    M2C_UNK func_0208b758(s32, s32);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK func_ov003_021fc98c(void *, M2C_UNK);
    M2C_UNK func_ov006_02217840(void *);
    M2C_UNK func_ov006_02217c74(void *);
    M2C_UNK func_ov006_02217cb8(void *);
    extern void *gCur3DSpriteEngine;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        func_ov006_02217840(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 8) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        func_ov006_02217c74(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 7) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        func_ov006_02217cb8(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (!(var_r0_4 & 0xFF)) {
        return;
    }
    M2C_FIELD(entity, u8 *, 0x3E) = (u8) (M2C_FIELD(entity, u8 *, 0x3E) & ~7);
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 3, 7);
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3E) << 0x18) >> 0x1F) != 0) {
        func_ov003_021fc98c(entity, 4);
    }
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x10, 3, 6);
    func_0208b758(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 4), 0x4700001D);
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 8));
    func_020893a8(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 0), 0x8B80, 1, func_020ae22c(0x11));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_ov003_021fd430(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd444(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd450(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd45c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd470(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd47c(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd488(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK func_020a92bc(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_02129870;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = func_02082028(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = func_02082028(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
        temp_r0_4 = func_02082028(0x2C);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &data_02129870;
            M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        func_020a92bc(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = func_02082028(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF);
}

