/* 51 functions from 0x02006F14 to 0x02007EF4 (main), found by ds-decomp. */
#include "common.h"
extern s32 data_0212dfe8;
extern u32 data_0212dfbc[2];
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

#pragma optimization_level 2
void func_02006f9c(void) {
void func_02005154(u32,void (*)(void),u32); extern u16 data_0212dfb4;
s32 zero=0; u32 *base=(u32*)&data_0212dfb4;
M2C_FIELD(base,u64 *,8)++;
if (M2C_FIELD(base,s32 *,4)) {
*(volatile u16 *)0x04000102=0;
*(volatile u16 *)0x04000100=0;
*(volatile u16 *)0x04000102=0xc1;
M2C_FIELD(base,s32 *,4)=0;
}
func_02005154(0,func_02006f9c,0);
}
#pragma optimization_level reset
u64 func_02007004(void) {
    u32 func_0200751c(void);
    void func_02007530(u32);
    extern u16 data_0212dfb4;
    volatile u16 timer;
    volatile u64 count;
    u32 state = func_0200751c();
    timer = *(volatile u16 *)0x04000100;
    count = M2C_FIELD(&data_0212dfb4, u64 *, 8) & 0x0000FFFFFFFFFFFFULL;
    if ((*(volatile u32 *)0x04000214 & 8) && !(timer & 0x8000)) count++;
    func_02007530(state);
    return (count << 16) | timer;
}

u16 func_020070a4(void) {
    return *(u16 *)0x04000100;
}

void func_020070b4(void *arg0) {
 void func_02005154(u32, void (*)(void), u32);
 s32 func_020073c0(s32);
 void func_020051c8(u32);
 u64 now = func_02007004();
 s64 delta;
 u32 timer;
 *(volatile u16 *)0x04000106 = 0;
 delta = M2C_FIELD(arg0, s64 *, 0xC) - now;
 ((void (*)(u32, void (*)(void)))func_02005154)(1, (void (*)(void))func_020073c0);
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

void func_020071a0(void *arg0, u32 arg1, u32 arg2) {
    u64 func_02007004(void);
    void func_020070b4(void *);
    u64 func_02072088(u64, u64);
    extern u16 data_0212dfc4;

    (void)arg1;
    (void)arg2;

    {
        u32 period_lo = M2C_FIELD(arg0, u32 *, 0x20);
        u32 period_hi = M2C_FIELD(arg0, u32 *, 0x1C);
        if (period_lo != 0 || period_hi != 0) {
            u64 now = func_02007004();
            u32 stored_hi = M2C_FIELD(arg0, u32 *, 0x28);
            u32 stored_lo = M2C_FIELD(arg0, u32 *, 0x24);
            u64 stored = ((u64)stored_hi << 32) | stored_lo;
            if (stored < now) {
                u64 period = ((u64)period_lo << 32) | period_hi;
                u64 q = func_02072088(now - stored, period);
                u64 inc = period * (q + 1);
                stored += inc;
                stored_lo = (u32)stored;
                stored_hi = (u32)(stored >> 32);
                M2C_FIELD(arg0, u32 *, 0x0C) = stored_lo;
                M2C_FIELD(arg0, u32 *, 0x10) = stored_hi;

                {
                    void *node = M2C_FIELD(&data_0212dfc4, void **, 4);
                    u64 newdl = ((u64)stored_hi << 32) | stored_lo;
                    while (node != 0) {
                        u32 nlo = M2C_FIELD(node, u32 *, 0x0C);
                        u32 nhi = M2C_FIELD(node, u32 *, 0x10);
                        u64 nodedl = ((u64)nhi << 32) | nlo;
                        if ((s64)newdl < (s64)nodedl) break;
                        node = M2C_FIELD(node, void **, 0x18);
                    }
                    if (node != 0) {
                        void *next = M2C_FIELD(node, void **, 0x14);
                        M2C_FIELD(arg0, void **, 0x14) = next;
                        M2C_FIELD(node, void **, 0x14) = arg0;
                        M2C_FIELD(arg0, void **, 0x18) = node;
                        if (next != 0) {
                            M2C_FIELD(next, void **, 0x18) = arg0;
                        } else {
                            M2C_FIELD(&data_0212dfc4, void **, 4) = arg0;
                            func_020070b4(arg0);
                        }
                    } else {
                        void *old_head = M2C_FIELD(&data_0212dfc4, void **, 8);
                        M2C_FIELD(arg0, void **, 0x18) = 0;
                        M2C_FIELD(&data_0212dfc4, void **, 8) = arg0;
                        M2C_FIELD(arg0, void **, 0x14) = old_head;
                        if (old_head != 0) {
                            M2C_FIELD(old_head, void **, 0x18) = arg0;
                        } else {
                            M2C_FIELD(&data_0212dfc4, void **, 8) = arg0;
                            M2C_FIELD(&data_0212dfc4, void **, 4) = arg0;
                            func_020070b4(arg0);
                        }
                    }
                }
            }
        }
    }
}

#pragma opt_common_subs off
void func_020072cc(void *arg0, u64 delay, void (*callback)(void *), void *arg4) {
 M2C_UNK func_02007958();
 u32 func_0200751c(void);
 void func_02007530(u32);
 void func_020071a0();
 u64 time;
 u32 state;
 if (arg0 == 0 || M2C_FIELD(arg0, s32 *, 0) != 0) func_02007958();
 state = func_0200751c();
 M2C_FIELD(arg0, s32 *, 0x1C) = 0;
 M2C_FIELD(arg0, s32 *, 0x20) = 0;
 M2C_FIELD(arg0, void (**)(void *), 0) = callback;
 M2C_FIELD(arg0, void **, 4) = (void*)*(volatile s32*)&arg4;
 time = delay + func_02007004();
 func_020071a0(arg0, (u32)time, (u32)(time >> 32));
 func_02007530(state);
}
#pragma opt_common_subs reset
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

#pragma interworking on
s32 func_020073c0(s32 arg0) {
    void func_020073d0(void);
    func_020073d0();
    return arg0;
}
void func_020073d0(void) {
    M2C_UNK func_020051f8(M2C_UNK);
    u64 func_02007004(void);
    void func_020070b4(void *);
    void func_020071a0(void *, u32, u32);
    extern u16 data_0212dfc4;
    extern M2C_UNK data_027e0000;

    void *node;
    void *next;
    u64 now;
    u32 deadline_hi;
    u32 deadline_lo;
    u32 t20;
    u32 t1c;
    u32 cb;
    u32 arg;

    *(volatile u16 *)0x04000106 = 0;
    func_020051f8(0x10);
    M2C_FIELD(&data_027e0000, u32 *, 0x3FF8) |= 0x10;

    now = func_02007004();

    node = M2C_FIELD(&data_0212dfc4, void **, 0x4);
    if (node == 0) return;

    deadline_hi = M2C_FIELD(node, u32 *, 0x10);
    deadline_lo = M2C_FIELD(node, u32 *, 0x0C);
    if (now < ((u64)deadline_hi << 32 | deadline_lo)) {
        func_020070b4(node);
        return;
    }

    next = M2C_FIELD(node, void **, 0x18);
    M2C_FIELD(&data_0212dfc4, void **, 0x4) = next;
    if (next == 0) {
        M2C_FIELD(&data_0212dfc4, u32 *, 0x8) = 0;
    } else {
        M2C_FIELD(next, u32 *, 0x14) = 0;
    }

    t20 = M2C_FIELD(node, u32 *, 0x20);
    t1c = M2C_FIELD(node, u32 *, 0x1C);
    cb = M2C_FIELD(node, u32 *, 0x00);
    if (t20 == 0 && t1c == 0) {
        M2C_FIELD(node, u32 *, 0x00) = 0;
    }

    if (cb != 0) {
        arg = M2C_FIELD(node, u32 *, 0x04);
        ((void (*)(u32))cb)(arg);
    }

    t20 = M2C_FIELD(node, u32 *, 0x20);
    t1c = M2C_FIELD(node, u32 *, 0x1C);
    if (t20 != 0 || t1c != 0) {
        M2C_FIELD(node, u32 *, 0x00) = cb;
        func_020071a0(node, 0, 0);
    }

    node = M2C_FIELD(&data_0212dfc4, void **, 0x4);
    if (node != 0) {
        func_020070b4(node);
    }
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

extern void func_00000678(unsigned int);
void func_0200758c(unsigned int value)
{
    if (value >= 4)
        return func_00000678(value - 4);
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

void func_02007608(s32 arg0,s32 arg1) {
M2C_UNK func_02007958();
extern M2C_UNK data_0212dfe4;
if(((u32)((arg1&0x7F00)<<8)>>16)==0x10) {M2C_FIELD(&data_0212dfe4,s16 *,0)=1;return;}
func_02007958();
}

void func_0200763c(s32 arg0) {
    s32 func_02009eb0(M2C_UNK, s32, M2C_UNK);
    do {

    } while (func_02009eb0(0xC, arg0 << 8, 0) != 0);
}

void func_02007668(s32 arg0) {
    M2C_UNK func_01ff81e4();
    void func_0200519c(s32);
    void func_02005228(s32);
    u16 func_0200558c(void);
    void func_0200763c(s32);
    M2C_UNK func_02007958();
    void func_02007ca4(s32);
    u16 func_0200fe24(u16);

    if (*(u16 *)0x027FFC40 == 2) {
        u16 x;
        func_02007958();
        x = func_0200558c();
        func_0200fe24((u16)(x << 16 >> 16));
        func_02007ca4(0);
        func_02007ca4(1);
        func_02007ca4(2);
        func_02007ca4(3);
        func_0200519c(0x40000);
        func_02005228(0xFFFFFFFF);
    }
    *(s32 *)0x027FFC20 = arg0;
    func_0200763c(0x10);
    func_01ff81e4();
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

#pragma intrinsic on
s32 func_020077c4(u32 arg0) {
    return __CLZ(arg0);
}
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

void func_02007888(void *out_arg) {
    extern u32 data_0212dfbc[2];
    u32 *out = out_arg;
    u32 *base = (u32 *)0x027FFC00;
    u16 t0 = *(u16 *)0x04000006;
    base = (u32 *)((unsigned char *)base + 0);
    out = out;

    out[0] = func_020070a4() | ((u32)t0 << 16);

    out[1] = data_0212dfbc[0] ^ (((u32)*(u16 *)((unsigned char *)base + 0xF8)) << 16);

    {
        u32 tmp = base[0x3C / 4] ^ (data_0212dfbc[1] ^ base[0xF4 / 4]);
        out[2] = tmp;
        out[2] = tmp ^ *(u32 *)0x04000600;
    }

    out[3] = base[0x1E8 / 4];

    {
        u32 *r = (u32 *)((unsigned char *)base + 0x300);
        out[4] = base[0x1EC / 4];
        out[5] = base[0x390 / 4] ^ (((u32)*(u16 *)((unsigned char *)r + 0x94)) << 16);

        {
            u16 a = *(u16 *)((unsigned char *)r + 0xAA);
            u16 b = *(u16 *)((unsigned char *)r + 0xAC);
            out[6] = (u32)b | ((u32)a << 16);
        }

        {
            u16 c = *(u16 *)0x04000130;
            u16 d = *(u16 *)((unsigned char *)base + 0x3A8);
            u16 e = *(u16 *)((unsigned char *)r + 0x98);
            out[7] = (u32)c | (u32)d | ((u32)e << 16);
        }
    }
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

