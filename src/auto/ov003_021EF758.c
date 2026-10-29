/* 21 functions from 0x021EF758 to 0x021F05FC (ov003), found by ds-decomp. */
#include "common.h"

u32 func_ov003_021ef758(void *arg0, u32 arg1) {
    M2C_UNK func_01ffaacc(u16, M2C_UNK, u16, M2C_UNK *, s32);
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088e84(void *, s16, M2C_UNK, s16, s32);
    s16 func_020a8ff4(void *);
    u16 func_020aae10(void *);
    u16 func_020aae44(void *);
    s32 func_ov003_021e6cc4(s16, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov003_022004a8(u8);
    extern M2C_UNK data_027e00b4;
    extern u16 **gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220f89e;
    s32 sp10;
    s32 spC;
    u32 sp8;
    s16 temp_r11;
    s16 temp_r11_2;
    s16 temp_r11_3;
    s16 temp_r1;
    s16 temp_r4_5;
    s16 temp_r4_6;
    s16 temp_r4_7;
    s16 temp_r6;
    s16 temp_r6_2;
    s16 temp_r6_3;
    s16 temp_r6_4;
    s16 temp_r7;
    s16 temp_r9;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    u16 temp_r4_2;
    u16 temp_r4_3;
    u16 temp_r4_4;
    u16 temp_r7_2;
    u8 var_r1;
    u8 var_r8;
    void *temp_r5;
    void *temp_r5_2;

    sp8 = arg1;
    var_r8 = 0;
    if (arg1 == 0) {
        return arg1;
    }
    spC = 0x3FF;
    sp10 = 0x3FF;
    do {
        temp_r4 = func_020a8ff4(M2C_FIELD(arg0, void **, 0x50));
        temp_r9 = temp_r4 + func_ov003_022004a8(var_r8);
        temp_r7 = temp_r9 + 0xD;
        temp_r5 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x28);
        func_02088e84(temp_r5, temp_r7, 0x70, temp_r7, 0x70);
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            temp_r11 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4_2 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6, temp_r11, (s32) temp_r4_2, (s32) func_020aae44(temp_r5));
        }
        M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5, s16 *, 0x36) = 0x70;
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            temp_r11_2 = M2C_FIELD(temp_r5, s16 *, 0x52);
            temp_r6_2 = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4_3 = func_020aae10(temp_r5);
            func_02087d84(M2C_FIELD(temp_r5, void **, 0x64), 1, temp_r6_2, temp_r11_2, (s32) temp_r4_3, (s32) func_020aae44(temp_r5));
        }
        temp_r5_2 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x38);
        temp_r1 = temp_r9 + 0xD;
        func_02088e84(temp_r5_2, temp_r1, 0x90, temp_r1, 0x90);
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            temp_r11_3 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_3 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r4_4 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_3, temp_r11_3, (s32) temp_r4_4, (s32) func_020aae44(temp_r5_2));
        }
        M2C_FIELD(temp_r5_2, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5_2, s16 *, 0x36) = 0x90;
        if (M2C_FIELD(M2C_FIELD(temp_r5_2, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            temp_r4_5 = M2C_FIELD(temp_r5_2, s16 *, 0x52);
            temp_r6_4 = M2C_FIELD(temp_r5_2, s16 *, 0x50);
            temp_r7_2 = func_020aae10(temp_r5_2);
            func_02087d84(M2C_FIELD(temp_r5_2, void **, 0x64), 1, temp_r6_4, temp_r4_5, (s32) temp_r7_2, (s32) func_020aae44(temp_r5_2));
        }
        temp_r4_6 = temp_r9 - 1;
        if (func_ov003_021e6cc4(temp_r4_6, 0x78, 0x40, 0x20) != 0) {
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 3) {
                var_r0_5 = 1;
            } else {
                var_r0_5 = 0;
            }
            if ((var_r0_5 & 0xFF) && (var_r8 == M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7))) {
                var_r1 = 9;
            } else {
                var_r1 = 8;
            }
            func_01ffaacc((u16) (temp_r4_6 & 0x1FF), 0x78,
                          (u16) ((spC & (0x600 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) |
                                 (u16) (var_r1 << 0xC) | 0x800),
                          &data_027e00b4, 0xB);
        }
        temp_r4_7 = temp_r9 - 4;
        if (func_ov003_021e6cc4(temp_r4_7, 0x80, 0x40, 0x10) != 0) {
            func_01ffaacc((u16) (temp_r4_7 & 0x1FF), 0x80,
                          (u16) ((sp10 & ((s32) (u16) ((((u8) M2C_FIELD(((var_r8 * 0x18) + (s32) M2C_FIELD(arg0, void **, 0x6C)), s32 *, 0x18) - 1) * 0x10) + 0x620) >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) |
                                 0x6400),
                          &data_ov003_0220f89e, 0xB);
        }
        var_r8 += 1;
    } while ((u32) var_r8 < sp8);
    return sp8;
}

void func_ov003_021efb40(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021efb54(void) {
    M2C_UNK func_ov003_021ea57c();
    func_ov003_021ea57c();
}

void func_ov003_021efb60(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021efb74(void *arg0) { (void)arg0; return; }

void func_ov003_021efe90(void) {
    M2C_UNK func_ov003_021eaed0();
    func_ov003_021eaed0();
}

void func_ov003_021efe9c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

void func_ov003_021efeb0(void *arg0) {
M2C_UNK func_02088ff4(s32);s16 func_020a8ff4(void *);s32 func_ov003_021f15d4();s16 func_ov003_021f1608();
s16 value;void *p,*q;
value=func_ov003_021f1608();
p=M2C_FIELD(arg0,void **,60); M2C_FIELD(p,s16 *,14)=func_020a8ff4(p);M2C_FIELD(p,s16 *,16)=value;M2C_FIELD(p,s16 *,12)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
q=M2C_FIELD(arg0,void **,64);M2C_FIELD(q,s8 *,16)=99;M2C_FIELD(q,s8 *,17)=99;
p=M2C_FIELD(arg0,void **,72); M2C_FIELD(p,s16 *,14)=func_020a8ff4(p);M2C_FIELD(p,s16 *,16)=value;M2C_FIELD(p,s16 *,12)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
p=M2C_FIELD(arg0,void **,68); M2C_FIELD(p,s16 *,14)=func_020a8ff4(p);M2C_FIELD(p,s16 *,16)=0xc0;M2C_FIELD(p,s16 *,12)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
p=M2C_FIELD(arg0,void **,80); M2C_FIELD(p,s16 *,14)=func_020a8ff4(p);M2C_FIELD(p,s16 *,16)=value;M2C_FIELD(p,s16 *,12)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
p=M2C_FIELD(arg0,void **,76); M2C_FIELD(p,s16 *,14)=func_020a8ff4(p);M2C_FIELD(p,s16 *,16)=0xc0;M2C_FIELD(p,s16 *,12)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
func_02088ff4(M2C_FIELD(arg0,s32 *,84));if(func_ov003_021f15d4()==0)return;p=M2C_FIELD(arg0,void **,100);func_02088ff4(M2C_FIELD(p,s32 *,0));func_02088ff4(M2C_FIELD(p,s32 *,4));}

void func_ov003_021effb8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021effcc(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
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

void func_ov003_021efff8(void) {
    M2C_UNK func_ov003_021ea314();
    func_ov003_021ea314();
}

void func_ov003_021f0004(void) {
    M2C_UNK func_ov003_021ea3f4();
    func_ov003_021ea3f4();
}

void func_ov003_021f0010(void) {

}

void func_ov003_021f0014(void *arg0) {
s32 func_020846a4(); s32 func_020848c4(); s32 func_02084d3c(void *,s32); void func_02084d88(void *,s32); void func_02084e74(); s32 func_020a22fc(s32); s32 func_ov003_021e6d28(); void func_ov003_021f140c(s32); void func_ov003_021f152c(s32); void func_ov003_022006dc(s32); s32 func_ov003_02200808(u8); void func_ov006_022172b0(void *);
u8 buf[0x24]; s32 v;
if (!func_020846a4()) return;
if (((u32)(M2C_FIELD(arg0,u8 *,0x39)<<31)>>31)==1) v=1; else v=0;
if (!(v&255)) return;
func_ov003_022006dc(0); func_ov003_021f152c(1); func_ov003_021f140c(1); func_ov006_022172b0(arg0);
if (!func_ov003_021e6d28()) return;
if (!func_02084d3c(buf,0x24)) return;
buf[13]=func_ov003_02200808((u8)func_020a22fc(func_020848c4()+1));
func_02084d88(buf,0x24); func_02084e74();
}

void func_ov003_021f00cc(void) {

}

void func_ov003_021f00d0(void) {
    M2C_UNK func_ov003_021ee8b8();
    func_ov003_021ee8b8();
}

void func_ov003_021f00dc(void *arg0) {
void *func_02084e24(); void *func_02084e64(); s32 func_020a22fc(s32); s32 func_ov003_02200808(u8);
s32 flag; s8 old,count,value; u8 i; void *p,*q;
i=0; count=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),s8 *,4);
if(count<=0)return;
do {
p=M2C_FIELD(arg0,void **,0x6c)+i;
old=M2C_FIELD(p,s8 *,10);
if(M2C_FIELD(p,u8 *,0x74)==255) flag=1; else flag=0;
if(!(flag&255)){
q=func_02084e24();
if(q) value=M2C_FIELD(q,s8 *,13); else value=func_ov003_02200808((u8)func_020a22fc(i+1));
}else{
q=func_02084e64();
if(q) value=M2C_FIELD(q+i,s8 *,0x12); else value=func_ov003_02200808((u8)func_020a22fc(i+1));
}
if(old!=value){
M2C_FIELD(M2C_FIELD(arg0,void **,0x6c)+i,u8 *,10)=(u8)value;
M2C_FIELD(arg0,u8 *,0x3a)|=8;
if(i==M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),u8 *,7)){
q=M2C_FIELD(arg0,void **,0x40); M2C_FIELD(q,u8 *,0x10)=i; M2C_FIELD(q,u8 *,0x11)=(u8)value;
}
}
i++;
}while(i<count);
}

void func_ov003_021f01cc(void *arg0) {
    M2C_UNK func_ov003_021f1bd4();
    M2C_UNK func_ov003_021f1be8();
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x18) >> 0x1F) != 0) {
        func_ov003_021f1bd4();
        return;
    }
    func_ov003_021f1be8();
}

void func_ov003_021f01f0(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_02082028(s32);
    M2C_UNK func_02074114(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    void func_ov003_021f05cc(void *);
    void func_ov003_021f05f8(void);
    extern M2C_UNK data_02102174;
    extern M2C_UNK data_ov003_0220f8e0;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;
    extern M2C_UNK data_ov003_0220faf8;
    extern M2C_UNK data_ov003_0220fb08;
    extern M2C_UNK data_ov003_0220fb18;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    u8 b, r3, r5, r12, i;
    M2C_UNK *base;

    func_ov003_021f13ec(&data_ov003_0220f8e0);
    temp_r0 = func_01ffa3dc(&data_ov003_0220f8e0, arg0);
    if (temp_r0 == NULL) return;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_0220fb38;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220fb64;
    M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
    b = M2C_FIELD(temp_r0, u8 *, 0x39);
    r5 = b & ~2;
    b = r5;
    r3 = b & ~0xC;
    b = r3;
    *(volatile u8 *)((s8 *)temp_r0 + 0x39) = r5;
    b = b & ~0xF0;
    M2C_FIELD(temp_r0, u8 *, 0x39) = b;
    b = M2C_FIELD(temp_r0, u8 *, 0x3A);
    r5 = b & ~1;
    b = r5;
    r12 = b & ~2;
    b = r12;
    r3 = b & ~4;
    b = r3;
    r5 = b & ~8;
    b = r5;
    r3 = b & ~0x70;
    b = r3;
    *(volatile u8 *)((s8 *)temp_r0 + 0x3A) = r12;
    *(volatile u8 *)((s8 *)temp_r0 + 0x3A) = r5;
    b = b & ~0x80;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = b;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x50) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x54) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x6C) = 0;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, void **, 0x3C) = temp_r0_2;
    temp_r0_2 = func_02082028(0x14);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_0220faf8;
        M2C_FIELD(temp_r0_2, s16 *, 0x4) = 8;
        M2C_FIELD(temp_r0_2, s16 *, 0x6) = 4;
        M2C_FIELD(temp_r0_2, s16 *, 0x8) = 0xA0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 0xA0;
        M2C_FIELD(temp_r0_2, s8 *, 0x12) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x13) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x10) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0x11) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xE) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xF) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xC) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xD) = 0x63;
    }
    M2C_FIELD(temp_r0, void **, 0x40) = temp_r0_2;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, void **, 0x48) = temp_r0_2;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, void **, 0x4C) = temp_r0_2;
    temp_r0_2 = func_02082028(0x12);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
    }
    M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_2;
    temp_r0_3 = func_02082028(0x48);
    if (temp_r0_3 != NULL) {
        i = 0;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = NULL;
        M2C_FIELD(temp_r0_3, s32 *, 4) = 0;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            M2C_FIELD(base, s32 *, 8) = 0;
            M2C_FIELD(base, s32 *, 0x18) = 0;
            M2C_FIELD(base, s32 *, 0x28) = 0;
            i += 1;
            M2C_FIELD(base, s32 *, 0x38) = 0;
        } while (i < 4);
    }
    M2C_FIELD(temp_r0, void **, 0x64) = temp_r0_3;
    temp_r0_3 = func_02082028(0x80);
    if (temp_r0_3 != NULL) {
        i = 0;
        * (M2C_UNK **)temp_r0_3 = &data_ov003_0220fb08;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            i += 1;
            M2C_FIELD(base, s32 *, 0x44) = 0;
        } while (i < 0xD);
    }
    M2C_FIELD(temp_r0, void **, 0x68) = temp_r0_3;
    temp_r0_3 = func_02082028(0xE8);
    if (temp_r0_3 != NULL) {
        * (M2C_UNK **)temp_r0_3 = &data_ov003_0220fb18;
        func_02074114(temp_r0_3 + 0x14, 4, 0x18, &func_ov003_021f05cc, &func_ov003_021f05f8);
        i = 0;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            i += 1;
            M2C_FIELD(base, s32 *, 0x78) = 0;
        } while (i < 0x1A);
    }
    M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_3;
    M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x39) & ~1);
}

void func_ov003_021f05cc(void *arg0) {
    extern M2C_UNK data_ov003_0220fb28;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_0220fb28;
    M2C_FIELD(arg0, s8 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}

void func_ov003_021f05f8(void) {

}

