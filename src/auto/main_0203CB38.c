/* 3 functions from 0x0203CB38 to 0x0203D910 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a, b; u16 c; s32 d; } UnkPacket;
extern u8 data_020ff88c[8];
extern char data_020fc920[12];
extern char data_020fc92c[12];
extern char data_020fc938[24];
void func_02007e54(int, void *, int);
void *func_02044268(void);
void func_0205e510(void *, int, void *);
void func_0205f83c(int, void *, int, void *);
int func_0206527c(void *, void *, int);

void func_0203cb38(void *arg0) { }

s32 func_0203d5d4(s32 unused, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    UnkPacket packet;
    u8 c;
    if (!arg4 || !arg3) return 0;
    func_02007e54(0,&packet,8);
    packet.b=2;
    packet.c=(u8)(arg2>>8)|((arg2<<8)&0xff00);
    packet.d=arg1;
    c=arg3[0];
    if ((c==0xfe && arg3[1]==0xfd)||c==0x5c) {
        if (M2C_FIELD(func_02044268(),s32 *,0x10))
            func_0205f83c(M2C_FIELD(func_02044268(),s32 *,0x10),arg3,arg4,&packet);
    } else if (!func_0206527c(arg3,data_020ff88c,6)) {
        func_0205e510(arg3,arg4,&packet);
    } else {
        switch(c) { case 0xfe: break; }
        return 0;
    }
    return 1;
}

void func_0203d6c8(s32 unused, s32 p1, s32 p2, s32 p3, s32 p4, u8 *p5) {
    void *func_02044268(void);
    s32 func_020390d4(void);
    void func_0205adc0(s32, void *, s32);
    void func_0203dc38(s32, s32);
    void func_0203dc18(void);
    void *func_02039130(s32);
    void *func_020391a8(s32);
    s32 func_0205adb4(s32, s32);
    s32 func_0206abd8(void *, s32, s32);
    void func_0205b058(void *, s32);
    void func_020411dc(s32);

    s32 r8 = p1;
    s32 r7 = p2;
    s32 r6 = p3;
    void *g;
    s32 r5;
    void *r4;
    void *r9;
    s32 tmp;
    s32 val;

    (void)unused;

    g = func_02044268();
    if (g == 0) goto err_init;
    g = func_02044268();
    if (M2C_FIELD(g, s32 *, 0x1a0) != 7) goto err_init;
    g = func_02044268();
    if (M2C_FIELD(g, u8 *, 0x1a9) != 0) goto err_init;
    goto state_init;

err_init:
    func_0205adc0(r8, data_020fc920, -1);
    return;

state_init:
    r5 = func_020390d4();
    if (r5 == -1) {
        func_0205adc0(r8, data_020fc92c, -1);
        func_0203dc38(6, (s32)0xfffeabc4);
        return;
    }

    r4 = func_02044268();
    g = func_02044268();
    tmp = M2C_FIELD(g, u8 *, 0x0d);
    if (r7 != *(s32 *)((u8 *)r4 + (tmp << 2) + 0x210)) goto c54;

    r4 = func_02044268();
    g = func_02044268();
    tmp = M2C_FIELD(g, u8 *, 0x0d);
    if (r6 != *(u16 *)((u8 *)r4 + (tmp << 1) + 0x200 + 0x90)) goto c54;

    goto ce0;

c54:
    if (p5[0] != 0) {
        val = func_0206abd8(p5, 0, 10);
        r9 = func_02044268();
        g = func_02044268();
        tmp = M2C_FIELD(g, u8 *, 0x0d);
        if (val == *(s32 *)((u8 *)r9 + (tmp << 2) + 0xf4)) {
            r4 = func_02044268();
            g = func_02044268();
            tmp = M2C_FIELD(g, u8 *, 0x0d);
            *(s32 *)((u8 *)r4 + (tmp << 2) + 0x210) = r7;

            r4 = func_02044268();
            g = func_02044268();
            tmp = M2C_FIELD(g, u8 *, 0x0d);
            *(u16 *)((u8 *)r4 + (tmp << 1) + 0x200 + 0x90) = (u16)r6;
            goto ce0;
        }
    }

    func_0205adc0(r8, data_020fc938, -1);
    return;

ce0:
    g = func_02044268();
    M2C_FIELD(g, s32 *, 0x18c) = 0;
    M2C_FIELD(g, s32 *, 0x190) = 0;

    g = func_02044268();
    if (func_0205adb4(r8, M2C_FIELD(g, s32 *, 0x08)) == 0) {
        func_0203dc38(6, (s32)0xfffec5e6);
        return;
    }

    func_0203dc18();

    g = func_02044268();
    tmp = M2C_FIELD(g, u8 *, 0x0d);
    if (tmp == 0) {
        s32 half = p4 >> 1;
        if (half >= 0xffff) half = 0xffff;
        g = func_02044268();
        *(u16 *)((u8 *)g + 0x100 + 0xb0) = (u16)half;
    }

    {
        void *A = func_02039130(r5);
        void *B;
        B = func_020391a8(r5);
        *(u32 *)A = (u32)r8;
        r4 = B;

        g = func_02044268();
        tmp = M2C_FIELD(g, u8 *, 0x0d);
        M2C_FIELD(g, u8 *, 0x0d) = (u8)(tmp + 1);
        *(u8 *)r4 = (u8)r5;

        g = func_02044268();
        {
            void *g3 = func_02044268();
            s32 t = M2C_FIELD(g3, u8 *, 0x0d);
            void *ptr = (void *)((u8 *)g + (t - 1));
            u8 byte = *(u8 *)((u8 *)ptr + 0x2d0);
            *(u8 *)((u8 *)r4 + 1) = byte;
        }
        *(u16 *)((u8 *)r4 + 2) = 0;
        *(s32 *)((u8 *)r4 + 4) = 0;
    }

    func_0205b058((void *)r8, (s32)r4);
    func_020411dc(2);
    return;
}

