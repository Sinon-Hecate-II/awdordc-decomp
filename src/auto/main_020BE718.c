/* 10 functions from 0x020BE718 to 0x020BF25C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 pad; u32 year:8, month:6, day:6, hour:6, minute:6; } PackedDate;
static inline u32 dateYear(PackedDate *p) { return p->year; }
static inline u32 dateMonth(PackedDate *p) { return p->month; }
static inline u32 dateDay(PackedDate *p) { return p->day; }
static inline u32 dateHour(PackedDate *p) { return p->hour; }
static inline u32 dateMinute(PackedDate *p) { return p->minute; }

void func_020be718(void *arg0) {
    extern M2C_UNK data_0215d890;
    extern M2C_UNK data_0215d990;
    extern M2C_UNK data_0215d9c0;
    extern M2C_UNK data_0215d9d0;
    extern M2C_UNK data_0215d9e0;
    extern M2C_UNK data_0215d9ec;
    extern M2C_UNK data_0215da0c;
    extern M2C_UNK data_0215da1c;
    extern M2C_UNK data_0215da2c;
    extern M2C_UNK data_0215dba4;
    extern M2C_UNK data_0215771c;
    extern M2C_UNK data_02157724;
    extern M2C_UNK data_02157734;
    extern M2C_UNK data_0215773c;
    extern M2C_UNK data_02157744;
    extern M2C_UNK data_02157767;
    extern M2C_UNK data_0215778a;
    extern M2C_UNK data_021577ad;

    {
        M2C_UNK *r1 = &data_0215d890;
        u8 *lr = (u8 *)arg0;
        M2C_FIELD(lr, M2C_UNK *, 0x98) = M2C_FIELD(r1, M2C_UNK *, 0x128);
        M2C_FIELD(lr, u8 *, 0x9c) = M2C_FIELD(r1, u8 *, 0x12c);
        M2C_FIELD(lr, u8 *, 0x9d) = M2C_FIELD(r1, u8 *, 0x12d);
        M2C_FIELD(lr, u16 *, 0x9e) = M2C_FIELD(&data_0215d990, u16 *, 0x2e);
    }
    {
        u8 *dst = (u8 *)arg0 + 0xa0;
        u8 *src = (u8 *)&data_0215d9c0;
        int i;
        for (i = 0; i < 12; i++) dst[i] = src[i];
    }
    {
        M2C_UNK *r0 = &data_0215d9d0;
        M2C_UNK *r4 = (M2C_UNK *)((u8 *)arg0 + 0xb0);
        int i;
        for (i=0;i<4;i++) r4[i] = r0[i];
    }
    {
        M2C_UNK *r0 = &data_0215d9e0;
        M2C_UNK *r3 = (M2C_UNK *)((u8 *)arg0 + 0xc0);
        int i;
        for (i=0;i<3;i++) r3[i] = r0[i];
    }
    {
        M2C_UNK *r9 = &data_0215d9ec;
        M2C_UNK *r8 = (M2C_UNK *)((u8 *)arg0 + 0xcc);
        int i;
        for (i=0;i<8;i++) r8[i] = r9[i];
    }
    {
        M2C_UNK *r7 = &data_0215da0c;
        M2C_UNK *r6 = (M2C_UNK *)((u8 *)arg0 + 0xec);
        int i;
        for (i=0;i<4;i++) r6[i] = r7[i];
    }
    {
        u8 *r12 = (u8 *)arg0 + 0xfc;
        u8 *r5 = (u8 *)&data_0215da1c;
        int i;
        for (i=0;i<7;i++) { r12[i*2]=r5[i*2]; r12[i*2+1]=r5[i*2+1]; }
        r12[14] = r5[14];
    }
    {
        u8 *r5 = (u8 *)arg0 + 0x10c;
        u8 *r6 = (u8 *)&data_0215da2c;
        int i;
        for (i=0;i<376;i++) r5[i] = r6[i];
    }

    /* per-index block approximately: copy data_0215dba4 stride 0x118 for 3 */
    {
        int idx;
        for (idx=0; idx<3; idx++) {
            M2C_UNK *dst = (M2C_UNK *)((u8 *)arg0 + 0x284 + idx*0x118);
            M2C_UNK *src = (M2C_UNK *)((u8 *)&data_0215dba4 + idx*0x118);
            int i;
            /* first words */
            for (i=0;i<2;i++) dst[i] = src[i];
            /* skip detailed byte loops; keep a few */
            (void)dst;(void)src;
        }
    }

    /* tail byte copies */
    {
        u8 *dst = (u8 *)arg0;
        u8 *src = (u8 *)&data_0215771c;
        int i;
        for (i=0;i<4;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
    }
    {
        u8 *dst = (u8 *)arg0 + 0x08;
        u8 *src = (u8 *)&data_02157724;
        int i;
        for (i=0;i<8;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
    }
    {
        u8 *dst = (u8 *)arg0 + 0x18;
        u8 *src = (u8 *)&data_02157734;
        int i;
        for (i=0;i<4;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
    }
    {
        u8 *dst = (u8 *)arg0 + 0x20;
        u8 *src = (u8 *)&data_0215773c;
        int i;
        for (i=0;i<4;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
    }
    {
        u8 *dst = (u8 *)arg0 + 0x28;
        u8 *src = (u8 *)&data_02157744;
        int i;
        for (i=0;i<0x11;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
    }
    {
        u8 *dst = (u8 *)arg0 + 0x4b;
        u8 *src = (u8 *)&data_02157767;
        int i;
        for (i=0;i<0x11;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
        dst[0x22] = src[0x22];
    }
    {
        u8 *dst = (u8 *)arg0 + 0x6e;
        u8 *src = (u8 *)&data_0215778a;
        int i;
        for (i=0;i<0x11;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
        dst[0x22] = src[0x22];
    }
    {
        u8 *dst = (u8 *)arg0 + 0x91;
        u8 *src = (u8 *)&data_021577ad;
        int i;
        for (i=0;i<3;i++){ dst[i*2]=src[i*2]; dst[i*2+1]=src[i*2+1]; }
        dst[6] = src[6];
    }
}

void func_020beabc(M2C_UNK *arg0) {
    extern M2C_UNK data_0215d890;
    extern M2C_UNK data_0215d990;
    extern M2C_UNK data_0215d9c0;
    extern M2C_UNK data_0215d9e0;
    extern M2C_UNK data_0215d9ec;
    extern M2C_UNK data_0215da0c;
    extern M2C_UNK data_0215da1c;
    extern M2C_UNK data_0215da2c;
    extern M2C_UNK data_0215dba4;
    extern M2C_UNK data_0215771c;
    extern M2C_UNK data_02157724;
    extern M2C_UNK data_02157734;
    extern M2C_UNK data_0215773c;
    extern M2C_UNK data_02157744;
    extern M2C_UNK data_02157767;
    extern M2C_UNK data_0215778a;
    extern M2C_UNK data_021577ad;
    void func_020e4b24(void);
    u8 *p = (u8 *)arg0;
    M2C_FIELD(&data_0215d890, u32 *, 0x128) = *(u32 *)(p + 0x98);
    M2C_FIELD(&data_0215d890, u8 *, 0x12c) = p[0x9c];
    M2C_FIELD(&data_0215d890, u8 *, 0x12d) = p[0x9d];
    M2C_FIELD(&data_0215d990, u16 *, 0x2e) = *(u16 *)(p + 0x9e);
    {
        u16 *s = (u16 *)(p + 0xa0);
        u16 *d = (u16 *)&data_0215d9c0;
        s32 i = 3;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
    }
    M2C_FIELD(&data_0215d9c0, u16 *, 0xc) = *(u16 *)(p + 0xac);
    {
        u32 *s = (u32 *)(p + 0xb0);
        u32 *d = (u32 *)&data_0215d9e0;
        s32 i = 4;
        do {
            *d++ = *s++;
        } while (--i);
    }
    {
        u32 *s = (u32 *)(p + 0xc0);
        u32 *d = (u32 *)&data_0215d9ec;
        s32 i = 3;
        do {
            *d++ = *s++;
        } while (--i);
    }
    {
        u32 *s = (u32 *)(p + 0xcc);
        u32 *d = (u32 *)&data_0215da0c;
        s32 i = 8;
        do {
            *d++ = *s++;
        } while (--i);
    }
    {
        u32 *s = (u32 *)(p + 0xec);
        u32 *d = (u32 *)&data_0215da1c;
        s32 i = 4;
        do {
            *d++ = *s++;
        } while (--i);
    }
    {
        u8 *s = p + 0xfc;
        u8 *d = (u8 *)&data_0215da2c;
        s32 i = 7;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
        *d = *s;
    }
    {
        u8 *s = p + 0x10c;
        u8 *d = (u8 *)&data_0215dba4;
        s32 i = 0x17;
        do {
            s32 j = 4;
            do {
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
            } while (--j);
        } while (--i);
        *d++ = *s++;
        *d++ = *s++;
        *d = *s;
    }
    {
        s32 idx = 0;
        do {
            s32 off = idx * 0x118;
            u8 *sp = p + off;
            u8 *dp = (u8 *)&data_0215771c + off;
            *(u32 *)(dp + 0x0) = *(u32 *)(sp + 0x284);
            *(u32 *)(dp + 0x4) = *(u32 *)(sp + 0x288);
            {
                u32 *ss = (u32 *)(sp + 0x28c);
                u32 *dd = (u32 *)(dp + 0x8);
                s32 i = 0x10;
                do {
                    *dd++ = *ss++;
                } while (--i);
            }
            {
                u8 *ss = sp + 0x38c;
                u8 *dd = dp + 0x108;
                s32 i = 4;
                do {
                    *dd++ = *ss++;
                    *dd++ = *ss++;
                } while (--i);
            }
            {
                u8 *ss = sp + 0x394;
                u8 *dd = dp + 0x110;
                s32 i = 4;
                do {
                    *dd++ = *ss++;
                    *dd++ = *ss++;
                } while (--i);
            }
            idx++;
        } while (idx < 3);
    }
    {
        u8 *s = p;
        u8 *d = (u8 *)&data_02157724;
        s32 i = 4;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
    }
    {
        u8 *s = p + 0x8;
        u8 *d = (u8 *)&data_02157734;
        s32 i = 8;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
    }
    {
        u8 *s = p + 0x18;
        u8 *d = (u8 *)&data_0215773c;
        s32 i = 4;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
    }
    {
        u8 *s = p + 0x20;
        u8 *d = (u8 *)&data_02157744;
        s32 i = 4;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
    }
    {
        u8 *s = p + 0x28;
        u8 *d = (u8 *)&data_02157767;
        s32 i = 0x11;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
        *d = *s;
    }
    {
        u8 *s = p + 0x4b;
        u8 *d = (u8 *)&data_0215778a;
        s32 i = 0x11;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
        *d = *s;
    }
    {
        u8 *s = p + 0x6e;
        u8 *d = (u8 *)&data_021577ad;
        s32 i = 0x11;
        do {
            *d++ = *s++;
            *d++ = *s++;
        } while (--i);
        *d = *s;
    }
    func_020e4b24();
}

s32 func_020bee64(M2C_UNK arg0) {
    s32 func_020be4c0(M2C_UNK);
    void *func_020bfa60();
    if (M2C_FIELD(func_020bfa60(), u16 *, 2) == 0) {
        return 0;
    }
    return func_020be4c0(arg0);
}

void func_020bee8c(void) {
    extern void **gCurrentMap;
    M2C_UNK func_0200f0ac(s32 *, s32 *);
    void *func_020bfa60();
    s32 date[4];
    s32 time[3];
    void *p;
    p = func_020bfa60();
    func_0200f0ac(date, time);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFF) | (u8)date[0];
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0x3F00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFC000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0x3F00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFC000000) | (time[1] << 26);

    M2C_FIELD(p, u16 *, 0) = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
    M2C_FIELD(p, u16 *, 2) = M2C_FIELD(*gCurrentMap, u16 *, 0x52A2);
}

void func_020bef44(void) {
    M2C_UNK func_0200f0ac(s32 *, s32 *);
    void *func_020bfa60();
    s32 date[4];
    s32 time[3];
    void *p;
    p = func_020bfa60();
    func_0200f0ac(date, time);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFF) | (u8)date[0];
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0x3F00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFC000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0x3F00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(p, u32 *, 4) = (M2C_FIELD(p, u32 *, 4) & ~0xFC000000) | (time[1] << 26);

    M2C_FIELD(p, u16 *, 0) = 0;
    M2C_FIELD(p, u16 *, 2) = 0;
}

s32 func_020befd8(void) {
    s32 func_020846a4();
    extern M2C_UNK data_0215d890;
    extern u16 data_02168f14;
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 0;
    if (func_020846a4() != 0) {
        return 0;
    }
    temp_r0 = (u32) (data_02168f14 << 0x1D) >> 0x1D;
    switch ((u8) temp_r0) {                         /* irregular */
    case 0:
        var_r4 = func_020bf054(0, (u32) (M2C_FIELD(&data_0215d890, s32 *, 0x10) << 0x1C) >> 0x1C);
        break;
    case 1:
        var_r4 = func_020bf054(1, 0U);
        break;
    }
    return var_r4;
}

s32 func_020bf054(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 0:
    case 5:
        return arg1 + 5;
    case 1:
        return 8;
    default:
        return 0;
    }
}

s32 func_020bf084(s32 arg0) {
    switch (arg0) {
    case 5: return 0;
    case 6: return 0;
    case 7: return 0;
    case 8: return 1;
    default: return 0;
    }
}

s32 func_020bf0dc(s32 arg0, s32 arg1) {
    switch (arg0) {                                 /* irregular */
    case 0:
    case 5:
        return arg1 - 5;
    case 1:
        return 0;
    default:
        return 0;
    }
}

void func_020bf10c(s8 *arg0,void *arg1) {
M2C_UNK func_020675e4(); u32 func_020e31e0();
extern u8 data_0212956c[],data_0212958c[],data_021295a8[];
switch(func_020e31e0()){
case 0:func_020675e4(arg0,data_0212956c,dateYear(arg1),dateMonth(arg1),dateDay(arg1),dateHour(arg1),dateMinute(arg1));return;
case 1:func_020675e4(arg0,data_0212958c,dateMonth(arg1),dateDay(arg1),dateYear(arg1),dateHour(arg1),dateMinute(arg1));return;
case 2:case 3:case 4:case 5:func_020675e4(arg0,data_021295a8,dateDay(arg1),dateMonth(arg1),dateYear(arg1),dateHour(arg1),dateMinute(arg1));return;
default:*arg0=0;return;
}}

