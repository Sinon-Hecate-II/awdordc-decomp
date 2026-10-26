/* 51 functions from 0x02006F14 to 0x02007EF4 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_0212dfe8;
extern u16 data_0212dfec[10];
typedef struct { u8 bytes[0x64]; u16 flags; } SystemInfo;

void func_02006f14(void) {
    void func_02006ef8(s32);
    void func_02004ff8(u32, void (*)(void));
    void func_020051c8(u32);
    void func_02006f9c(void);
    extern u16 data_0212dfb4;
    if (data_0212dfb4 != 0) return;
    data_0212dfb4 = 1;
    func_02006ef8(0);
    M2C_FIELD(&data_0212dfb4, u64 *, 8) = 0;
    *(volatile u16 *)0x04000102 = 0;
    *(volatile u16 *)0x04000100 = 0;
    *(volatile u16 *)0x04000102 = 0xC1;
    func_02004ff8(8, func_02006f9c);
    func_020051c8(8);
    M2C_FIELD(&data_0212dfb4, s32 *, 4) = 0;
}

u16 func_02006f8c(void) {
    extern u16 data_0212dfb4;
    return data_0212dfb4;
}

void func_02006f9c(void) {
    void func_02005154(u32, void (*)(void), u32);
    extern u16 data_0212dfb4;
    M2C_FIELD(&data_0212dfb4, s64 *, 8) += 1;
    if (M2C_FIELD(&data_0212dfb4, s32 *, 4) != 0) {
        *(volatile u16 *)0x04000102 = 0;
        *(volatile u16 *)0x04000100 = 0;
        *(volatile u16 *)0x04000102 = 0xC1;
        M2C_FIELD(&data_0212dfb4, s32 *, 4) = 0;
    }
    func_02005154(0, func_02006f9c, 0);
}

u64 func_02007004(void) {
    u32 func_0200751c(void);
    void func_02007530(u32);
    extern u16 data_0212dfb4;
    volatile u64 count;
    volatile u16 timer;
    u32 state = func_0200751c();
    timer = *(volatile u16 *)0x04000100;
    count = M2C_FIELD(&data_0212dfb4, u64 *, 8) & 0x0000FFFFFFFFFFFFULL;
    if ((*(volatile u32 *)0x04000214 & 8) && !(timer & 0x8000)) count++;
    func_02007530(state);
    return (count << 16) | (s64)(s32)timer;
}

u16 func_020070a4(void) {
    return *(u16 *)0x04000100;
}

void func_020070b4(void *arg0) {
 void func_02005154(u32, void (*)(void), u32);
 void func_020073c0(void);
 void func_020051c8(u32);
 u64 now = func_02007004();
 s64 delta;
 u32 timer;
 *(volatile u16 *)0x04000106 = 0;
 delta = M2C_FIELD(arg0, s64 *, 0xC) - now;
 ((void (*)(u32, void (*)(void)))func_02005154)(1, func_020073c0);
 timer = 0;
 if (delta < 0) timer = 0xFFFE;
 else if (delta < 0x10000) timer = (u16)~(u32)delta;
 *(volatile u16 *)0x04000104 = timer;
 *(volatile u16 *)0x04000106 = 0xC1;
 func_020051c8(0x10);
}

void func_02007140(void) {
 void func_02006ef8(s32);
 M2C_UNK func_020051f8(M2C_UNK);
 extern u16 data_0212dfc4;
 if (M2C_FIELD(&data_0212dfc4, u16 *, 0) != 0) return;
 M2C_FIELD(&data_0212dfc4, u16 *, 0) = 1;
 func_02006ef8(1);
 M2C_FIELD(&data_0212dfc4, s32 *, 4) = 0;
 M2C_FIELD(&data_0212dfc4, s32 *, 8) = 0;
 func_020051f8(0x10);
}

u16 func_02007180(void) {
    extern u16 data_0212dfc4;
    return data_0212dfc4;
}

void func_02007190(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

#pragma scheduling off
void func_020072cc(void *arg0, u64 delay, s32 arg3, s32 arg4) {
 M2C_UNK func_02007958();
 u32 func_0200751c(void);
 void func_02007530(u32);
 void func_020071a0();
 u32 state;
 u64 time;
 if (arg0 == 0 || M2C_FIELD(arg0, s32 *, 0) != 0) func_02007958();
 state = func_0200751c();
 M2C_FIELD(arg0, s32 *, 0x1C) = 0;
 M2C_FIELD(arg0, s32 *, 0x20) = 0;
 M2C_FIELD(arg0, s32 *, 0) = arg3;
 M2C_FIELD(arg0, s32 *, 4) = arg4;
 time = delay + func_02007004();
 func_020071a0(arg0, (u32)time, (u32)(time >> 32));
 func_02007530(state);
}

#pragma scheduling reset
void func_02007338(void *arg0) {
 u32 func_0200751c(void);
 void func_02007530(u32);
 extern u16 data_0212dfc4;
 u32 state;
 void *prev;
 void *next;
 state = func_0200751c();
 if (M2C_FIELD(arg0,s32 *,0) == 0) {
 func_02007530(state);
 return;
 }
 prev = M2C_FIELD(arg0,void **,0x18);
 if (prev == NULL) {
 M2C_FIELD(&data_0212dfc4,void **,8) = M2C_FIELD(arg0,void **,0x14);
 } else {
 M2C_FIELD(prev,void **,0x14) = M2C_FIELD(arg0,void **,0x14);
 }
 next = M2C_FIELD(arg0,void **,0x14);
 if (next != NULL) M2C_FIELD(next,void **,0x18) = prev;
 else {
 M2C_FIELD(&data_0212dfc4,void **,4) = prev;
 if (prev != NULL) func_020070b4(prev);
 }
 M2C_FIELD(arg0,s32 *,0) = 0;
 M2C_FIELD(arg0,s32 *,0x1C) = 0;
 M2C_FIELD(arg0,s32 *,0x20) = 0;
 func_02007530(state);
}

#pragma interworking off
void func_020073c0(void) {
 void func_020073d0(void);
 s32 saved;
 func_020073d0();
}
#pragma interworking reset

void func_020074c0(void) {
    M2C_UNK func_020051f8(M2C_UNK);
    extern M2C_UNK data_0212dfd0;
    if (M2C_FIELD(&data_0212dfd0, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0212dfd0, u16 *, 0) = 1U;
    M2C_FIELD(&data_0212dfd0, s32 *, 0xC) = 0;
    M2C_FIELD(&data_0212dfd0, s32 *, 0x10) = 0;
    func_020051f8(4);
    M2C_FIELD(&data_0212dfd0, s32 *, 8) = 0;
    M2C_FIELD(&data_0212dfd0, s32 *, 4) = 0;
}

s32 func_02007508(void) {
    M2C_ERROR(/* unknown instruction: msr cpsr_c, $r1 */);
    return M2C_ERROR(/* unknown instruction: mrs $r0, cpsr */) & 0x80;
}

void func_02007598(void) {
    M2C_UNK WaitByLoop(M2C_UNK);
    M2C_UNK func_02004e60(M2C_UNK, M2C_UNK);
    WaitByLoop(1);
    func_02004e60(1, 1);
}

void func_020075b4(void) {
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212dfe4;
    extern M2C_UNK func_02007608;
    if (M2C_FIELD(&data_0212dfe4, u16 *, 2) != 0) {
        return;
    }
    M2C_FIELD(&data_0212dfe4, u16 *, 2) = 1U;
    func_02009d34();
    do {

    } while (func_02009e8c(0xC, 1) == 0);
    func_02009e40(0xC, &func_02007608);
}

void func_0200763c(s32 arg0) {
    s32 func_02009eb0(M2C_UNK, s32, M2C_UNK);
    do {

    } while (func_02009eb0(0xC, arg0 << 8, 0) != 0);
}

void func_02007724(M2C_UNK arg0) {
    M2C_UNK func_02008048(s32, M2C_UNK, M2C_UNK);
    func_02008048(0x027FFCF4, arg0, 6);
}

void func_02007740(void *arg0) {
 void func_02007e20(void *, void *, u32);
 SystemInfo *info=(SystemInfo *)0x027FFC80;
 M2C_FIELD(arg0,u8 *,0) = (u32)(info->flags << 29) >> 29;
 M2C_FIELD(arg0,u8 *,1) = (u32)(info->bytes[2] << 28) >> 28;
 M2C_FIELD(arg0,u8 *,2) = info->bytes[3];
 M2C_FIELD(arg0,u8 *,3) = info->bytes[4];
 M2C_FIELD(arg0,u16 *,0x1a) = info->bytes[0x1a];
 M2C_FIELD(arg0,u16 *,0x52) = info->bytes[0x50];
 func_02007e20(info->bytes+6,(u8 *)arg0+4,20);
 func_02007e20(info->bytes+0x1c,(u8 *)arg0+0x1c,52);
 M2C_FIELD(arg0,u16 *,0x18)=0;
 M2C_FIELD(arg0,u16 *,0x50)=0;
}

s32 func_020077c4(u32 arg0) { return __builtin_arm_clz(arg0); }

void func_020077cc(void) {
 s32 i=0;
 data_0212dfe8=0;
 do { data_0212dfec[i]=0; i++; } while(i<9);
}

void func_02007800(s32 arg0,s32 arg1) {
 u32 func_0200751c(void);
 void func_02007530(u32);
 s32 func_020077c4(u32);
 s32 bits;
 u32 state;
 s32 index,mask;
 state=func_0200751c();
 bits=arg0 & data_0212dfe8 & 0x1ff;

 loop:
 index=31-func_020077c4(bits);
 if(index>=0) {
 mask=~(1<<index);
 bits &= mask;
 if(arg1==data_0212dfec[index]) {data_0212dfec[index]=0; data_0212dfe8 &= mask;}
 goto loop;
 }
 func_02007530(state);
}

s32 func_02007958(void) {
 u32 func_0200751c(void); void func_02007968(void);
 for (;;) { func_0200751c(); func_02007968(); }
}

void func_02007974(s8 arg0) {
    *(s8 *)0x04000247 = arg0;
}

void func_02007984(s32 a,s32 b,u32 c,u32 n) {
 u32 func_0200751c(void); void func_02007530(u32); void func_01ff8554(s32,u32,s32,u32);
 volatile u32 *p; u32 state;
 if (!n) return;
 p=(volatile u32 *)(0x040000B0+(a*3+2)*4);
 while (*p & 0x80000000) {}
 state=func_0200751c();
 *(volatile u32 *)(0x040000E0+a*4)=c;
 func_01ff8554(a,0x040000E0+a*4,b,(n>>2)|0x85000000);
 func_02007530(state);
 while (*p & 0x80000000) {}
}

void func_02007a04(s32 a,s32 b,s32 c,u32 n) {
 void func_01ff84c0(s32,s32,s32,u32); void func_02007da4(s32,s32,s32,s32);
 volatile u32 *p;
 func_02007da4(a,b,n,0);
 if (!n) return;
 p=(volatile u32 *)(0x040000B0+(a*3+2)*4);
 while (*p & 0x80000000) {}
 func_01ff84c0(a,b,c,(n>>2)|0x84000000);
 while (*p & 0x80000000) {}
}

void func_02007a74(s32 a,s32 b,s32 c,u32 n) {
 void func_01ff84c0(s32,s32,s32,u32); void func_02007da4(s32,s32,s32,s32);
 volatile u32 *p;
 if (!n) return;
 func_02007da4(a,b,n,0);
 p=(volatile u32 *)(0x040000B0+(a*3+2)*4);
 while (*p & 0x80000000) {}
 func_01ff84c0(a,b,c,(n>>1)|0x80000000);
 while (*p & 0x80000000) {}
}

void func_02007ae0(s32 arg0, M2C_UNK arg1, s32 arg2, u32 arg3, void (*arg4)(s32), s32 arg5) {
    void func_02007c3c(s32);
    void func_0200510c(s32, s32, s32);
    u32 func_0200751c(void);
    void func_02007530(u32);
    void func_01ff8530(s32, s32, M2C_UNK, s32);
    u32 state;

    if (arg3 == 0) {
        if (arg4 == 0) {
            return;
        }
        arg4(arg5);
        return;
    }
    func_02007c3c(arg0);
    if (arg4 != 0) {
        func_0200510c(arg0, (s32)arg4, arg5);
        state = func_0200751c();
        M2C_FIELD((arg0 * 4 + 0x04000000), s32 *, 0xE0) = arg2;
        func_01ff8530(arg0, arg0 * 4 + 0x040000E0, arg1, (arg3 >> 2) | 0xC5000000);
        func_02007530(state);
        return;
    }
    state = func_0200751c();
    M2C_FIELD((arg0 * 4 + 0x04000000), s32 *, 0xE0) = arg2;
    func_01ff8530(arg0, arg0 * 4 + 0x040000E0, arg1, (arg3 >> 2) | 0x85000000);
    func_02007530(state);
}

void func_02007ba4(s32 a, s32 b, s32 c, s32 d, void (*e)(s32), s32 f) {
    void func_02007da4(s32, s32, s32, s32);
    void func_02007c3c(s32);
    void func_0200510c(s32, s32, s32);
    void func_01ff8480(s32, s32, s32, s32);
    func_02007da4(a, b, d, 0);
    if (d == 0) {
        if (e != 0) {
            e(f);
        }
        return;
    }
    func_02007c3c(a);
    if (e != 0) {
        func_0200510c(a, (s32)e, f);
        func_01ff8480(a, b, c, ((u32)d >> 2) | 0xC4000000);
        return;
    }
    func_01ff8480(a, b, c, ((u32)d >> 2) | 0x84000000);
}

void func_02007c3c(s32 a) {
 u32 func_0200751c(void); void func_02007530(u32);
 u32 state=func_0200751c();
 while (*(volatile u32 *)(0x040000B0 + (a*3+2)*4) & 0x80000000) {}
 if (a==0) {
 volatile u32 *p=(volatile u32 *)(0x040000B0+a*12);
 p[0]=0;p[1]=0;p[2]=0x81400001;
 }
 func_02007530(state);
}

void func_02007ca4(s32 a) {
    u32 func_0200751c(void);
    void func_02007530(u32);
    u32 state = func_0200751c();
    volatile u16 *p = (volatile u16 *)(0x040000B0 + (a * 6 + 5) * 2);
    *p = *p & ~0x3A00;
    *p = *p & ~0x8000;
    (void)(*p);
    (void)(*p);
    if (a == 0) {
        volatile u32 *q = (volatile u32 *)(0x040000B0 + a * 12);
        q[0] = 0;
        q[1] = 0;
        q[2] = 0x81400001;
    }
    func_02007530(state);
}

void func_02007d20(s32 arg0, s32 arg1) {
    M2C_UNK func_02007958();
    s32 i;
    s32 *ptr;
    s32 temp_r0;
    s32 temp_r0_2;
    i = 0;
    ptr = (s32 *)0x040000B8;
    do {
        if (i != arg0) {
            temp_r0 = *ptr;
            if ((temp_r0 & 0x80000000) && (temp_r0_2 = temp_r0 & 0x38000000, (temp_r0_2 != arg1))) {
                if ((temp_r0_2 == 0x08000000) && (arg1 == 0x10000000)) {

                } else if ((temp_r0_2 == 0x10000000) && (arg1 == 0x08000000)) {

                } else if ((temp_r0_2 != 0x18000000) && (temp_r0_2 != 0x20000000) && (temp_r0_2 != 0x28000000) && (temp_r0_2 != 0x30000000) && (temp_r0_2 != 0x38000000) && (temp_r0_2 != 0x08000000) && (temp_r0_2 != 0x10000000)) {

                } else {
                    func_02007958();
                }
            }
        }
        ++i;
        ptr += 0xC / sizeof(s32);
    } while (i < 3);
}

void func_02007da4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_02007958();
    s32 var_r1;
    u32 temp_ip;
    u32 temp_r0;

    var_r1 = arg1;
    if (arg0 != 0) {
        return;
    }
    temp_ip = var_r1 & 0xFF000000;
    switch (arg3) {                                 /* irregular */
    case 0x800000:
        var_r1 -= arg2;
        break;
    case 0x0:
        var_r1 += arg2;
        break;
    }
    temp_r0 = var_r1 & 0xFF000000;
    if ((temp_ip != 0x04000000) && (temp_ip < 0x08000000U) && (temp_r0 != 0x04000000) && (temp_r0 < 0x08000000U)) {
        return;
    }
    func_02007958();
}

void func_02007e54(u32 value, s32 dest, s32 size) {
 s32 end = dest + size;
 while (dest < end) { *(u32 *)dest = value; dest += 4; }
}

