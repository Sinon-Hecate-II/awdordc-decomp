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

typedef volatile unsigned int vu32;
void func_020021c0(s32 *arg0, s32 *arg1) {
    s64 sq = (s64)*(volatile s32 *)(arg0+1) * arg0[1];
    sq += (s64)arg0[0] * arg0[0];
    sq += (s64)arg0[2] * arg0[2];
    *(volatile u16 *)0x04000280 = 2;
    *(volatile s32 *)0x04000290 = 0;
    *(volatile s32 *)0x04000294 = 0x01000000;
    *(volatile u32 *)0x04000298 = (u32)sq;
    *(volatile u32 *)0x0400029c = (u32)(sq >> 32);
    *(volatile u16 *)0x040002b0 = 1;
    *(volatile u32 *)0x040002b8 = (u32)(sq << 2);
    *(volatile u32 *)0x040002bc = (u32)((sq << 2) >> 32);
    while (*(volatile u16 *)0x040002b0 & 0x8000) { }
    {
        s32 scale = *(volatile s32 *)0x040002b4;
        while (*(volatile u16 *)0x04000280 & 0x8000) { }
        {
            s64 D = *(volatile s64 *)0x040002a0;
            s64 P = D * (s64)scale;
            arg1[0] = (s32)((P * (s64)arg0[0] + (1LL << 44)) >> 45);
            arg1[1] = (s32)((P * (s64)arg0[1] + (1LL << 44)) >> 45);
            arg1[2] = (s32)((P * (s64)arg0[2] + (1LL << 44)) >> 45);
        }
    }
}

void func_020022d8(void) {

}

void func_020022dc(void) {
void func_020025c0(void); s32 func_0200558c(void); void func_02007958(void); void func_02007984(s32,void *,s32,s32); void func_02007e54(s32,void *,s32);
extern s16 data_0212dbc0; extern s16 data_020f5200;
s32 v;
*(volatile u16 *)0x4000304 |= 0x8000;
*(volatile u16 *)0x4000304 = (*(volatile u16 *)0x4000304 & ~0x20e)|0x20e;
*(volatile u16 *)0x4000304 |= 1;
func_020025c0();
while(M2C_FIELD(&data_0212dbc0,u16 *,2)==0) {
v=func_0200558c();
if(v==-3) func_02007958();
M2C_FIELD(&data_0212dbc0,u16 *,2)=v;
}
*(volatile u16 *)0x4000004=0;
*(volatile u32 *)0x4000000=0;
if(M2C_FIELD(&data_020f5200,s32 *,4)!=-1) {
func_02007984(M2C_FIELD(&data_020f5200,s32 *,4),(void *)0x4000008,0,0x60);
*(volatile u16 *)0x400006c=0;
func_02007984(M2C_FIELD(&data_020f5200,s32 *,4),(void *)0x4001000,0,0x70);
} else {
func_02007e54(0,(void *)0x4000008,0x60);
*(volatile u16 *)0x400006c=0;
func_02007e54(0,(void *)0x4001000,0x70);
}
*(volatile u16 *)0x4000020=0x100;
*(volatile u16 *)0x4000026=0x100;
*(volatile u16 *)0x4000030=0x100;
*(volatile u16 *)0x4000036=0x100;
*(volatile u16 *)0x4001020=0x100;
*(volatile u16 *)0x4001026=0x100;
*(volatile u16 *)0x4001030=0x100;
*(volatile u16 *)0x4001036=0x100;
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
 extern s16 data_020f5200, data_0212dbc0;
 u16 v = data_0212dbc0;
 data_020f5200 = 1;
 if (v != 0) {
  *(volatile u32 *)0x4000000 = (*(volatile u32 *)0x4000000 & ~0x30000) | ((u32)v << 16);
  return;
 }
 *(volatile u32 *)0x4000000 |= 0x10000;
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

void func_020026d8(s32 arg0) {
}

void func_02002968(s32 a) {
extern M2C_UNK data_0212dbc4;
M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,4))&~a;
M2C_FIELD(&data_0212dbc4,u16 *,4)=a;
switch(a) {
case 3: *(volatile u8 *)0x4000241=0x8a;
case 1: *(volatile u8 *)0x4000240=0x82;break;
case 2: *(volatile u8 *)0x4000241=0x82;break;
case 0x70: *(volatile u8 *)0x4000246=0x9a;
case 0x30: *(volatile u8 *)0x4000245=0x92;
case 0x10: *(volatile u8 *)0x4000244=0x82;break;
case 0x50: *(volatile u8 *)0x4000246=0x92; *(volatile u8 *)0x4000244=0x82;break;
case 0x60: *(volatile u8 *)0x4000246=0x8a;
case 0x20: *(volatile u8 *)0x4000245=0x82;break;
case 0x40: *(volatile u8 *)0x4000246=0x82;break;
case 0:break;
}
func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

void func_02002ab8(s32 mode) {
    extern M2C_UNK data_0212dbc4;
    /* Select a 3D VRAM bank mode and update the display control mirror. */
    M2C_FIELD(&data_0212dbc4, u16 *, 0) = (M2C_FIELD(&data_0212dbc4, u16 *, 0) | M2C_FIELD(&data_0212dbc4, u16 *, 0xe)) & ~mode;
    M2C_FIELD(&data_0212dbc4, u16 *, 0xe) = mode;
    switch (mode) {
    case 0x10:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000244 = 0x84;
        break;
    case 0x40:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000246 = 0x8c;
        break;
    case 0x60:
        *(volatile u8 *)0x4000246 = 0x8c;
    case 0x20:
        *(volatile u8 *)0x4000245 = 0x84;
        *(volatile u32 *)0x4000000 |= 0x40000000;
        break;
    case 0x0:
        *(volatile u32 *)0x4000000 &= ~0x40000000;
        break;
    }
    func_02002620(M2C_FIELD(&data_0212dbc4, u16 *, 0));
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

void func_02002c64(s32 arg0) {
    extern M2C_UNK data_0212dbc4;
    M2C_FIELD(&data_0212dbc4, u16 *, 0) = (M2C_FIELD(&data_0212dbc4, u16 *, 0) | M2C_FIELD(&data_0212dbc4, u16 *, 8)) & ~arg0;
    M2C_FIELD(&data_0212dbc4, u16 *, 8) = arg0;
    if (arg0 == 0) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xcffe;
    } else {
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 1;
        switch (arg0) {
        case 5: *(volatile u8 *)0x04000240 = 0x83; *(volatile u8 *)0x04000242 = 0x8b; break;
        case 9: *(volatile u8 *)0x04000240 = 0x83; *(volatile u8 *)0x04000243 = 0x8b; break;
        case 10: *(volatile u8 *)0x04000241 = 0x83; *(volatile u8 *)0x04000243 = 0x8b; break;
        case 11: *(volatile u8 *)0x04000240 = 0x83; *(volatile u8 *)0x04000241 = 0x8b; *(volatile u8 *)0x04000243 = 0x93; break;
        case 13: *(volatile u8 *)0x04000240 = 0x83; *(volatile u8 *)0x04000242 = 0x8b; *(volatile u8 *)0x04000243 = 0x93; break;
        case 8: *(volatile u8 *)0x04000243 = 0x83; break;
        case 12: *(volatile u8 *)0x04000243 = 0x8b; case 4: *(volatile u8 *)0x04000242 = 0x83; break;
        case 14: *(volatile u8 *)0x04000243 = 0x93; case 6: *(volatile u8 *)0x04000242 = 0x8b; case 2: *(volatile u8 *)0x04000241 = 0x83; break;
        case 15: *(volatile u8 *)0x04000243 = 0x9b; case 7: *(volatile u8 *)0x04000242 = 0x93; case 3: *(volatile u8 *)0x04000241 = 0x8b; case 1: *(volatile u8 *)0x04000240 = 0x83; break;
        default: break;
        }
    }
    func_02002620(M2C_FIELD(&data_0212dbc4, u16 *, 0));
}

void func_02002e3c(s32 a) {
    extern M2C_UNK data_0212dbc4;
    M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,0xa))&~a;
    M2C_FIELD(&data_0212dbc4,u16 *,0xa)=a;
    switch (a) {
    case 0x60:
        *(volatile u8 *)0x4000246 = 0x8b;
    case 0x20:
        *(volatile u8 *)0x4000245 = 0x83;
        break;
    case 0x40:
        *(volatile u8 *)0x4000246 = 0x83;
        break;
    case 0x70:
        *(volatile u8 *)0x4000246 = 0x9b;
    case 0x30:
        *(volatile u8 *)0x4000245 = 0x93;
    case 0x10:
        *(volatile u8 *)0x4000244 = 0x83;
        break;
    case 0:
        break;
    }
    func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

void func_02002f24(u32 a) {
extern M2C_UNK data_0212dbc4;
M2C_FIELD(&data_0212dbc4,u16 *,0)=(M2C_FIELD(&data_0212dbc4,u16 *,0)|M2C_FIELD(&data_0212dbc4,u16 *,12))&~a;
M2C_FIELD(&data_0212dbc4,u16 *,12)=a;
switch(a) {
case 3: *(volatile u8 *)0x4000240=0x93;
case 2: *(volatile u8 *)0x4000241=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 12: *(volatile u8 *)0x4000242=0x93;
case 8: *(volatile u8 *)0x4000243=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 0: *(volatile u16 *)0x4000060&=~0x4000;break;
case 1: *(volatile u8 *)0x4000240=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
case 4: *(volatile u8 *)0x4000242=0x9b; *(volatile u16 *)0x4000060|=0x4000;break;
}
func_02002620(M2C_FIELD(&data_0212dbc4,u16 *,0));
}

