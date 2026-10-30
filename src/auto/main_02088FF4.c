/* 42 functions from 0x02088FF4 to 0x02089D30 (main), found by ds-decomp. */
#include "common.h"
void func_02089c34(void *, s32);
extern M2C_UNK data_02102638;

#pragma opt_common_subs off
void func_02088ff4(void *p) {
    M2C_UNK func_02088da8(void *);
    if (!M2C_FIELD(p, u8 *, 0x4F)) {
        M2C_FIELD(p, s16 *, 0x34) = M2C_FIELD(p, s16 *, 0x54);
        M2C_FIELD(p, s16 *, 0x36) = M2C_FIELD(p, s16 *, 0x56);
        M2C_FIELD(p, s8 *, 0x4D) = 0;
        M2C_FIELD(p, u8 *, 0x48) = (u8)(M2C_FIELD(p, u8 *, 0x48) & ~0xC0);
        func_02088da8(p);
        return;
    }
    if ((((u32)M2C_FIELD(p, u8 *, 0x48) << 24) >> 30) == 3) {
        return;
    }
    M2C_FIELD(p, s8 *, 0x4C) = 0;
    M2C_FIELD(p, s8 *, 0x4D) = 0;
    M2C_FIELD(p, u8 *, 0x48) = (u8)((M2C_FIELD(p, u8 *, 0x48) & ~0xC0) | 0xC0);
}
#pragma opt_common_subs reset
u8 func_02089064(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1F) >> 0x1F) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02089080(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1F) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_0208909c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1A) >> 0x1E) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020890b8(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x18) >> 0x1E) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020890d4(void *arg0) {
 u8 result;
 if (func_0208909c(arg0) != 0) return 1;
 if (func_020890b8(arg0) != 0) result = 1;
 else result = 0;
 return result;
}

M2C_UNK func_02089108(void *arg0) {
extern M2C_UNK data_02102610;
extern void *gCur3DSpriteEngine;
extern s32 data_027e00c8;
u8 a;
u8 b;
M2C_UNK z = 0;
M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02102610;
M2C_FIELD(arg0,u8 *,0x48) = (M2C_FIELD(arg0,u8 *,0x48)&~1)|1;
M2C_FIELD(arg0,s16 *,0x34)=0;
M2C_FIELD(arg0,s16 *,0x36)=0;
M2C_FIELD(arg0,s32 *,0x40)&=~0x1FF;
M2C_FIELD(arg0,s32 *,0x40)&=0xFFFC01FF;
M2C_FIELD(arg0,s32 *,0x40)&=~0x03FC0000;
M2C_FIELD(arg0,s16 *,0x3E)=0;
M2C_FIELD(arg0,s16 *,0x3C)=0xC00;
M2C_FIELD(arg0,s32 *,0x40)=(M2C_FIELD(arg0,s32 *,0x40)&~0xFC000000)|0x40000000;
a = ((s32)gCur3DSpriteEngine == data_027e00c8) ? 1 : 0;
b = (a == 1) ? 0 : 1;
M2C_FIELD(arg0,u8 *,0x48)=(M2C_FIELD(arg0,u8 *,0x48)&~0xE)|((u32)(b<<0x1D)>>0x1C);
M2C_FIELD(arg0,u8 *,0x49)=0x11;
M2C_FIELD(arg0,s32 *,0x44)=z;
M2C_FIELD(arg0,u8 *,0x48)=(u8)(M2C_FIELD(arg0,u8 *,0x48)&~0x30)&~0xC0;
M2C_FIELD(arg0,u8 *,0x4D)=z;
M2C_FIELD(arg0,u8 *,0x4C)=z;
M2C_FIELD(arg0,u8 *,0x4E)=8;
M2C_FIELD(arg0,u8 *,0x4F)=8;
M2C_FIELD(arg0,s16 *,0x38)=z;
M2C_FIELD(arg0,s16 *,0x3A)=z;
}

M2C_UNK func_020892f0(void *arg0, s32 arg1) {
 void func_02088964(void *,s32);
 M2C_UNK func_02088c78(M2C_UNK);
 void func_020887ec(void *);
 func_02088964(arg0,arg1);func_02088c78((M2C_UNK)arg0);func_020887ec(arg0);
}

void func_02089310(void) {
    M2C_UNK func_020892f0();
    func_020892f0();
}

void func_0208931c(M2C_UNK arg0) {
 void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
 M2C_UNK func_020891fc();
 extern M2C_UNK data_02102658;
 if (func_01ffa3dc(&data_02102658, arg0) == NULL) return;
 func_020891fc();
}

void *func_02089340(void *arg0) {
    M2C_UNK func_02089108();
    extern M2C_UNK data_021025fc;
    func_02089108();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021025fc;
    M2C_FIELD(arg0, s8 *, 0x58) = 1;
    M2C_FIELD(arg0, s8 *, 0x59) = 1;
    M2C_FIELD(arg0, s8 *, 0x5A) = 1;
    M2C_FIELD(arg0, s32 *, 0x40) &= ~0x1FF;
    M2C_FIELD(arg0, s32 *, 0x40) &= 0xFFFC01FF;
    M2C_FIELD(arg0, s16 *, 0x5E) = 0;
    M2C_FIELD(arg0, s16 *, 0x60) = 0;
    M2C_FIELD(arg0, s16 *, 0x62) = 0;
    M2C_FIELD(arg0, s16 *, 0x64) = 0;
    M2C_FIELD(arg0, s16 *, 0x5C) = 0;
    return arg0;
}

void func_020893a8(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_0208ca2c(u32, s32, s32, M2C_UNK);
    *(volatile u16 *)((s8 *)arg0 + 0x3E) = (u16)(arg1 >> 5);
    {
        s32 t = *(volatile s32 *)((s8 *)arg0 + 0x40);
        u32 shifted = (u32)arg2 << 0x18;
        shifted >>= 6;
        t &= ~0x03FC0000;
        t |= (s32)shifted;
        *(volatile s32 *)((s8 *)arg0 + 0x40) = t;
    }
    *(volatile s16 *)((s8 *)arg0 + 0x5C) = (s16)arg3;
    func_0208ca2c(arg1, arg2, arg3, 2);
    *(volatile s16 *)((s8 *)arg0 + 0x3C) = 0;
    *(volatile s8 *)((s8 *)arg0 + 0x49) = 0;
}

M2C_UNK func_020893f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_020ae22c(M2C_UNK);
    func_020893a8((void *)arg0, arg1, arg2, func_020ae22c(9));
}

void func_02089424(M2C_UNK arg0) {
    M2C_UNK func_020893f4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020893f4(arg0, 0x1000, 1);
}

void func_02089438(void *arg0) {
    *(volatile s16 *)((volatile s8 *)arg0 + 0x5E) = *(volatile s16 *)((volatile s8 *)arg0 + 0x34);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x60) = *(volatile s16 *)((volatile s8 *)arg0 + 0x36);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x62) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)arg0 + 0x40))[0] << 0x17) >> 0x17);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x64) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)arg0 + 0x40))[0] << 0xE) >> 0x17);
}

M2C_UNK func_0208946c(void) { return 0; }

void func_020896e4(void) {
    M2C_UNK func_0208946c();
    func_0208946c();
}

void func_020896f0(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102678;
    void *ptr = func_01ffa3dc(&data_02102678, arg0);
    if (ptr == NULL) return;
    func_02089340(ptr);
}

s32 func_02089714(void) {
    M2C_UNK func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102678;
    return func_01ffa770(&data_02102678);
}

void func_02089728(void) {
 M2C_UNK func_02088da8();
 if (func_02089714() == 0) return;
 func_02088da8();
}

void func_02089740(void) {
 M2C_UNK func_02088d94();
 if (func_02089714() == 0) return;
 func_02088d94();
}

u8 func_02089758(void *arg0) {
    M2C_UNK func_0208af98(s32, u8);
    extern void *gCur3DSpriteEngine;
    func_0208af98(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49));
    return M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49);
}

void func_02089784(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102698;
    M2C_FIELD(func_01ffa3dc(&data_02102698, 6), s32 *, 0x34) = arg0;
}

void func_020897a4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102698;
    func_01ffa9e4(&data_02102698);
}

void func_020897b8(void) {
    M2C_UNK func_0208e0f0(M2C_UNK, M2C_UNK, s32, s32);
    s32 func_020ae22c(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_020ae22c(0xD);
    func_0208e0f0(0x1400, 1, temp_r4, func_020ae22c(0xE));
}

void func_020897e8(void) {
    M2C_UNK func_01ff9ed0();
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    s32 func_020ae22c(M2C_UNK);
    s32 func_020ae3e0(s32, s32, u8, u8);
    M2C_UNK func_0208e0f0(M2C_UNK, M2C_UNK, s32, s32);
    extern volatile s32 data_027e15c0;
    s32 temp_r4;
    s32 temp_r4_2;
    u8 var_r0;
    var_r0 = (u32)(data_027e15c0 & 0x1F) < 0x10U ?
        func_0207ca38(0, 0, 0x20, data_027e15c0 & 0x1F, 0x10) :
        func_0207ca38(0, 0x20, 0, (data_027e15c0 & 0x1F) - 0x10, 0x10);
    temp_r4 = func_020ae22c(0xF);
    temp_r4_2 = func_020ae3e0(temp_r4, func_020ae22c(0x10), var_r0, (u8)(0x20 - var_r0));
    func_0208e0f0(0x1400, 1, func_020ae22c(0xD), temp_r4_2);
    func_01ff9ed0();
}

void func_0208989c(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102738;
    M2C_FIELD(func_01ffa3dc(&data_02102738, 1), s32 *, 0x34) = arg0;
}

void func_020898bc(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102738;
    func_01ffa9e4(&data_02102738);
}

void *func_020898d0(void *arg0) {
 func_02089108(arg0);
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_02102638;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x38;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x300;
 M2C_FIELD(arg0,u32 *,0x58)&=~0xC0;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x38000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x3C0000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x1FC00000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0xE0000000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x800;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x400;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x1000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x2000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x4000;
 M2C_FIELD(arg0,s32 *,0x5C)=0;
 M2C_FIELD(arg0,s32 *,0x60)=0;
 M2C_FIELD(arg0,s32 *,0x64)=0;
 M2C_FIELD(arg0,s32 *,0x68)=0;
 M2C_FIELD(arg0,s32 *,0x6C)=0;
 M2C_FIELD(arg0,s32 *,0x70)=0;
 return arg0;
}

M2C_UNK **func_02089944(M2C_UNK **arg0) {
    M2C_UNK func_02089cec(M2C_UNK **);
    extern M2C_UNK data_02102638;
    *arg0 = &data_02102638;
    func_02089bdc();
    func_02089cec(arg0);
    return arg0;
}

M2C_UNK **func_0208996c(M2C_UNK **arg0) {
 M2C_UNK func_02089cec(M2C_UNK **);
 M2C_UNK func_02082040(M2C_UNK **);
 *arg0=&data_02102638;
 func_02089bdc();func_02089cec(arg0);func_02082040(arg0);return arg0;
}

void func_0208999c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02086680(M2C_UNK);
    M2C_UNK func_020899fc(M2C_UNK, M2C_UNK, s32, s32);
    func_020899fc(arg0, arg1, 0x4B80, func_02086680(arg2));
}

void func_020899cc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    func_020899fc(arg0, arg1, arg2, func_02086680(arg3));
}

M2C_UNK func_020899fc(M2C_UNK entity, M2C_UNK arg1, s32 arg2, s32 arg3) {
    extern void *gCur3DSpriteEngine;
    extern s32 data_027e00c8, data_027e00c4;
    u8 func_0208ae88(M2C_UNK, s32);
    M2C_UNK func_020ae22c(s32);
    M2C_UNK func_0208e0f0(M2C_UNK, M2C_UNK, s32, s32);
    void func_02091c98(void);
    void func_02091d4c(s32);
    void func_02089b18(M2C_UNK, M2C_UNK);

    void *savedBank;
    void *bank;
    u32 mode;
    u16 spriteIndex;
    s32 i;
    s32 low3;
    s32 tmp;
    M2C_UNK t1;
    M2C_UNK t2;

    savedBank = gCur3DSpriteEngine;
    spriteIndex = (u16)(arg2 >> 5);
    i = 0;
    low3 = (s32)arg1 & 7;
    tmp = ~0x62;
    do {
        if (i == 0) {
            bank = (void *)data_027e00c8;
        } else {
            bank = (void *)data_027e00c4;
        }
        gCur3DSpriteEngine = bank;
        mode = (u32)(M2C_FIELD(entity, u8 *, 0x48) << 28) >> 29;
        if ((mode != 0 || bank == (void *)data_027e00c8) &&
            (mode != 1 || bank == (void *)data_027e00c4) &&
            (mode != 3 || bank == savedBank)) {
            M2C_FIELD(entity, u16 *, 0x3E) = spriteIndex;
            M2C_FIELD(entity, s32 *, 0x58) = (M2C_FIELD(entity, s32 *, 0x58) & ~7) | low3;
            M2C_FIELD(entity, s32 *, 0x58) = (M2C_FIELD(entity, s32 *, 0x58) & ~0xE0000000) | (low3 << 29);
            M2C_FIELD(entity, u8 *, 0x49) = (u8)tmp;
            func_0208ae88(entity, tmp + 0x62);
            t1 = func_020ae22c(0xD);
            t2 = func_020ae22c(0xE);
            func_0208e0f0(0x1400, 1, t1, t2);
            func_02091c98();
            func_02091d4c(0x12);
            func_02089b18(entity, arg3);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
    return 0;
}

void func_02089b18(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02089b38(M2C_UNK, M2C_UNK);
    M2C_UNK func_02089bdc();
    func_02089bdc();
    func_02089b38(arg0, arg1);
}

#pragma opt_common_subs off
M2C_UNK func_02089b38(M2C_UNK arg0,M2C_UNK arg1) {
 s32 func_02068c34(s32);
 s32 func_020e34bc(s32);
 void func_02068c50(s32,s32);
 void func_02068d68(s32,s32);
 void func_02089c34(void *,s32);
 register s32 p; register s32 len;
 if(!arg1)return;
 if(!M2C_FIELD(arg0,s32 *,0x64)) {
 M2C_FIELD(arg0,s32 *,0x64)=func_020e34bc(func_02068c34(arg1)+1);
 func_02068c50(M2C_FIELD(arg0,s32 *,0x64),arg1);
 } else {
 len=func_02068c34(M2C_FIELD(arg0,s32 *,0x64));
 p=func_020e34bc(len+func_02068c34(arg1)+1);
 func_02068c50(p,M2C_FIELD(arg0,s32 *,0x64));func_02068d68(p,arg1);
 func_02089bdc(arg0);M2C_FIELD(arg0,s32 *,0x64)=p;
 }
 M2C_FIELD(arg0,s32 *,0x68)=func_020e34bc(8);
 M2C_FIELD(arg0,s32 *,0x6C)=func_020e34bc(8);
 func_02089c34((void *)arg0,M2C_FIELD(arg0,s32 *,0x64));
}
#pragma opt_common_subs reset
M2C_UNK func_02089bdc(void *arg0) {
    s32 func_020e35cc(s32);
    s32 p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x64);
    if (p != 0) {
        func_020e35cc(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x64) = p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x68);
    if (p != 0) {
        func_020e35cc(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x68) = p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x6C);
    if (p != 0) {
        func_020e35cc(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x6C) = p;
    *(volatile s32 *)((s8 *)arg0 + 0x70) = p;
    return p;
}

#pragma peephole off
void func_02089c34(void *arg0, s32 arg1) {
    s32 func_0209c658(s32);
    u32 temp_r1;

    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    if (func_0209c658(arg1) != 0) {
        M2C_FIELD(arg0, u32 *, 0x58) = (u32) ((M2C_FIELD(arg0, u32 *, 0x58) & ~7) | 1);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u32 *, 0x58);
    M2C_FIELD(arg0, u32 *, 0x58) = (u32) ((temp_r1 & ~7) | ((temp_r1 >> 0x1D) & 7));
}
#pragma peephole reset
void func_02089c80(void *arg0) {
 s32 func_0209c658(s32);
 M2C_UNK func_01ffa8c4(void *,s32);
 M2C_UNK func_01ffa574(void *);
 s32 p=func_0209c658(M2C_FIELD(arg0,s32 *,0x70));
 if(p){func_02089c34(arg0,p);func_01ffa8c4(arg0,0);return;}
 func_01ffa574(arg0);
}

s32 func_02089cb8(void *arg0) {
    s32 temp_r2;
    u32 temp_r1;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_r1 = (u32) (temp_r2 * 8) >> 0x19;
    if (temp_r1 <= 1U) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r2 & ~0x1FC00000) | ((u32) ((temp_r1 - 1) << 0x19) >> 3));
    return 1;
}

M2C_UNK func_02089cec(M2C_UNK **arg0) {
 M2C_UNK func_01ffa574(void *);
 void *p;
 p=M2C_FIELD(arg0,void **,0x5C); if(p){func_01ffa574(p);M2C_FIELD(arg0,s32 *,0x5C)=0;}
 p=M2C_FIELD(arg0,void **,0x60); if(p){func_01ffa574(p);M2C_FIELD(arg0,s32 *,0x60)=0;}
 func_020897a4();func_020898bc();
}

