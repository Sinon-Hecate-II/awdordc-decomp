/* 10 functions from 0x020BE718 to 0x020BF25C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 pad; u32 year:8, month:6, day:6, hour:6, minute:6; } PackedDate;
static inline u32 dateYear(PackedDate *p) { return p->year; }
static inline u32 dateMonth(PackedDate *p) { return p->month; }
static inline u32 dateDay(PackedDate *p) { return p->day; }
static inline u32 dateHour(PackedDate *p) { return p->hour; }
static inline u32 dateMinute(PackedDate *p) { return p->minute; }

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

