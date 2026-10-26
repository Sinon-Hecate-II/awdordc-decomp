/* 24 functions from 0x02002060 to 0x02003058 (main), found by ds-decomp. */
#include "common.h"

void func_02002060(s32 arg0, s32 arg1) {
    M2C_FIELD((void *)0x04000280, s16 *, 0) = 1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x14) = arg0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x18) = arg1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x1C) = 0;
}

s32 func_02002088(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A0;
}

s32 func_020020c4(s32 arg0, s32 arg1) {
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = arg0;
    *(volatile s64 *)0x04000298 = (u32)arg1;
    while (*(volatile u16 *)0x04000280 & 0x8000) {}
    return *(volatile s32 *)0x040002A8;
}

s32 func_02002100(s32 *arg0, s32 *arg1) {
    return ((s64)arg0[0] * arg1[0] + (s64)arg0[1] * arg1[1] + (s64)arg0[2] * arg1[2] + 0x800) >> 12;
}

void func_0200213c(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 x = ((s64)arg0[1] * arg1[2] - (s64)arg0[2] * arg1[1] + 0x800) >> 12;
    s32 y = ((s64)arg0[2] * arg1[0] - (s64)arg0[0] * arg1[2] + 0x800) >> 12;
    s32 z = ((s64)arg0[0] * arg1[1] - (s64)arg0[1] * arg1[0] + 0x800) >> 12;
    arg2[0] = x; arg2[1] = y; arg2[2] = z;
}

void func_020022d8(void) {

}

s32 func_02002428(s32 a) {
s32 v=*(volatile u16 *)0x4000004 & 0x10;
if(a!=0){*(volatile u16 *)0x4000004 |= 0x10;return v;}
*(volatile u16 *)0x4000004 &= ~0x10;
return v;
}

s32 func_0200245c(s32 a) {
s32 v=*(volatile u16 *)0x4000004 & 8;
if(a!=0){*(volatile u16 *)0x4000004 |= 8;return v;}
*(volatile u16 *)0x4000004 &= ~8;
return v;
}

void func_02002490(void) {
    extern s16 data_020f5200;
    extern s16 data_0212dbc0;
    s32 temp_ip;

    temp_ip = *(s32 *)0x04000000;
    data_020f5200 = 0;
    data_0212dbc0 = (s16) ((u32) (temp_ip & 0x30000) >> 0x10);
    *(s32 *)0x04000000 = temp_ip & ~0x30000;
}

void func_020024cc(void) {
extern s16 data_0212dbc0,data_020f5200;
u32 v=*(u16 *)&data_0212dbc0;
data_020f5200=(u16)(v-v+1);
if(v){*(u32 *)0x4000000=(*(u32 *)0x4000000 & ~0x30000)|(v<<16);return;}
*(u32 *)0x4000000 |= 0x10000;
}

void func_02002514(u32 a,u32 b,u32 c) {
extern s16 data_020f5200,data_0212dbc0;
u32 flag=(u16)data_020f5200;
u32 old=*(volatile u32 *)0x4000000;
data_0212dbc0=a;
if(!flag)a=0;
*(volatile u32 *)0x4000000=(old&0xfff0fff0)|(a<<16)|b|(c<<3);
if(!*(u16 *)&data_0212dbc0)data_020f5200=0;
}

void func_0200257c(s32 arg0) {
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~7) | arg0;
}

void func_02002598(s16 *arg0, s32 arg1) {
    if (arg1 == 0) {
        *arg0 = 0;
        return;
    }
    if (arg1 > 0) {
        *arg0 = arg1 | 0x4000;
        return;
    }
    *arg0 = (0 - arg1) | 0x8000;
}

void func_020025c0(void) {
    extern M2C_UNK data_0212dbc4;
    M2C_FIELD(&data_0212dbc4, s16 *, 0) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 2) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 4) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 6) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 8) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0xA) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0xC) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0xE) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0x10) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0x12) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0x14) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0x16) = 0;
    M2C_FIELD(&data_0212dbc4, s16 *, 0x18) = 0;
    M2C_FIELD((void *)0x04000240, s32 *, 0) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 4) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 5) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 6) = 0;
    M2C_FIELD((void *)0x04000240, s16 *, 8) = 0;
}

void func_02002620(s32 arg0) {
    if (arg0 & 1) {
        *(volatile u8 *)0x04000240 = 0x80;
    }
    if (arg0 & 2) {
        *(volatile u8 *)0x04000241 = 0x80;
    }
    if (arg0 & 4) {
        *(volatile u8 *)0x04000242 = 0x80;
    }
    if (arg0 & 8) {
        *(volatile u8 *)0x04000243 = 0x80;
    }
    if (arg0 & 0x10) {
        *(volatile u8 *)0x04000244 = 0x80;
    }
    if (arg0 & 0x20) {
        *(volatile u8 *)0x04000245 = 0x80;
    }
    if (arg0 & 0x40) {
        *(volatile u8 *)0x04000246 = 0x80;
    }
    if (arg0 & 0x80) {
        *(volatile u8 *)0x04000248 = 0x80;
    }
    if (arg0 & 0x100) {
        *(volatile u8 *)0x04000249 = 0x80;
    }
}

void func_02002bb8(u32 a) {
    extern M2C_UNK data_0212dbc4;
    M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,16))&~a;
    M2C_FIELD(&data_0212dbc4,u16 *,16)=a;
    if (a != 0) {
        if (a == 0x20) {
            *(volatile u32 *)0x04000000 |= 0x80000000;
            *(volatile u8 *)0x04000245 = 0x85;
        } else if (a == 0x40) {
            *(volatile u32 *)0x04000000 |= 0x80000000;
            *(volatile u8 *)0x04000246 = 0x85;
        }
    } else {
        *(volatile u32 *)0x04000000 &= ~0x80000000;
    }
    func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

