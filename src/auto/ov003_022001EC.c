/* 40 functions from 0x022001EC to 0x02200EE4 (ov003), found by ds-decomp. */
#include "common.h"

extern s32 data_ov003_022103dc[4];
extern s16 data_ov003_022103d4[4];
extern s16 data_ov003_022103cc[4];

void func_ov003_022003dc(void) {

}

void func_ov003_022003e0(void) {

}

void func_ov003_022003e4(void) {

}

s16 func_ov003_022004a8(M2C_UNK arg0) {
    s16 func_ov003_022004d0();
    s16 func_ov003_022004f0(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_ov003_022004d0();
    return (s16) (temp_r4 + func_ov003_022004f0(arg0));
}

s16 func_ov003_022004d0(void) {
    s32 func_020cfb94(void);
    return data_ov003_022103d4[func_020cfb94() - 1];
}

s16 func_ov003_022004f0(s32 arg0) {
    s32 func_020cfb94(void);
    s32 val = data_ov003_022103cc[func_020cfb94() - 1];
    s32 r = arg0 * val;
    return (s16)r;
}

s32 func_ov003_02200520(s32 arg0) {
    return data_ov003_022103dc[arg0 - 1];
}

s32 func_ov003_02200534(u32 arg0) {
    switch (arg0) {
    case 1:
        return 0x2937;
    case 2:
        return 0x65A9;
    case 3:
        return 0x1A33;
    case 4:
        return 0x2D4B;
    default:
        return 0;
    }
}

s32 func_ov003_0220058c(u32 a){switch(a){case 1:return 0x4e5b;case 2:return 0x76b2;case 3:return 0x46f9;case 4:return 0x5274;default:return 0;}}

void func_ov003_022005e4(s32 arg0, s32 arg1, u32 arg2) {
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_020814ac(s32, s32, M2C_UNK, s32);
    s32 func_020a2360(s32);
    s32 func_020ae7a4(s32, s32, s32);
    s32 func_020e3218(M2C_UNK *);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0221042c;
    extern M2C_UNK data_ov003_02210440;
    u8 i;

    func_02080cfc(func_020e3218(&data_ov003_0221042c), M2C_FIELD((void *)((u8 *)gCur3DSpriteEngine + (arg0 * 4)), s32 *, 0xC));
    func_020814ac(func_ov003_02200520(arg2), M2C_FIELD((void *)((u8 *)gCur3DSpriteEngine + (arg0 * 4)), s32 *, 0x20), 0, arg1);
    func_0208116c(&data_ov003_02210440, arg1 << 5, 0x40);
    if (arg2 <= 1U) {
        return;
    }
    for (i = 0; i < arg2; i++) {
        func_020ae7a4(arg1, (u8)(i + 1), func_ov003_02200534((u8)func_020a2360(i + 1)));
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

void func_ov003_022006b0(s32 a, s32 b) {
s32 func_020a2360(s32);
s32 func_020ae7a4(s32,s32,s32);
s32 func_ov003_0220058c(u32);
func_020ae7a4(a,1,func_ov003_0220058c((u8)func_020a2360(b+1)));
}

void func_ov003_022006dc(s32 arg0) {
    extern void **gCurrentMap;
    s32 func_020846a4(void);
    void func_020833d0(void);
    s32 func_020bfda8(s32);
    void func_020a231c(s32, s32);
    void func_020a232c(s32, s32);
    void func_020a2204(s32);
    void func_02007e98(s32, void *, s32);
    s8 func_020a2370(s32);
    s32 func_020a22fc(s32);
    s32 func_ov003_02200808(u32);
    s32 func_0208492c(void);
    void func_02084d88(void *, s32);

    u8 sp[0x24];
    u8 r5;
    u8 *r6;
    s32 val;

    if (func_020846a4() == 0) {
        return;
    }
    func_020833d0();
    if (arg0 == 0) {
        func_020bfda8(0);
        M2C_FIELD(*gCurrentMap, u8 *, 0x5141) = 2;
        func_020a231c(1, 1);
        func_020a231c(2, 2);
        func_020a231c(3, 3);
        func_020a231c(4, 4);
        func_020a232c(1, 1);
        func_020a232c(2, 2);
        func_020a232c(3, 3);
        func_020a232c(4, 4);
    }
    func_020a2204(0);
    func_02007e98(0, sp, 0x24);
    r5 = 0;
    do {
        r6 = sp + r5;
        r6[0xe] = (u8)func_020a2370(r5 + 1);
        val = func_020a22fc(r5 + 1);
        val = val & 0xFF;
        val = func_ov003_02200808(val);
        r5 = (u8)(r5 + 1);
        r6[0x12] = (u8)val;
    } while (r5 < 4);
    val = func_0208492c();
    val = val + 1;
    val = func_020a22fc(val);
    val = val & 0xFF;
    val = func_ov003_02200808(val);
    sp[0xd] = (u8)val;
    func_02084d88(sp, 0x24);
}

s32 func_ov003_02200808(u32 a) {
switch(a) {
case 1:return 0;
case 2:return 1;
case 3:return 2;
case 4:return 3;
case 5:return 4;
case 6:return 5;
case 7:return 6;
case 8:return 7;
case 9:return 8;
case 10:return 9;
case 11:return 10;
case 12:return 11;
case 0:return 12;
default:return 255;
}
}

s32 func_ov003_022008b8(u32 a){switch(a){case 0:return 1;case 1:return 2;case 2:return 3;case 3:return 4;case 4:return 5;case 5:return 6;case 6:return 7;case 7:return 8;case 8:return 9;case 9:return 10;case 10:return 11;case 11:return 12;case 12:return 0;default:return 255;}}

s32 func_ov003_02200968(u32 a){switch(a){case 3:return 3;case 4:return 4;case 0:return 0;case 1:return 1;case 2:return 2;case 5:return 5;case 6:return 6;case 7:return 7;case 8:return 8;case 9:return 9;case 10:return 10;case 11:return 11;case 12:return 12;default:return 0;}}

u16 func_ov003_02200a18(u32 arg0, M2C_UNK arg1) {
    s32 func_020c7ef4(M2C_UNK);
    s32 func_020c80a4(M2C_UNK);
    s32 func_020cfbb0(M2C_UNK);
    s32 temp_r4;
    u16 var_r0;

    temp_r4 = func_020cfbb0(arg1);
    switch (arg0) {
    default:
    case 0:
        return 0U;
    case 1:
        return 3U;
    case 3:
        return (u16) (temp_r4 + 2);
    case 4:
        return 0U;
    case 5:
        return 1U;
    case 6:
        return 2U;
    case 2:
        return (u16) (temp_r4 + 5);
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        if (func_020c7ef4(arg1) == 0) {
            return 0xDU;
        }
        if (func_020c80a4(arg1) != 0) {
            var_r0 = temp_r4 + 8;
        } else {
            var_r0 = temp_r4 + 0xC;
        }
        return var_r0;
    }
}

s32 func_ov003_02200ae8(u32 a){switch(a){case 0:return 0;case 1:return 1;case 2:return 2;case 3:return 3;case 4:return 4;case 5:return 7;case 6:return 9;case 7:return 8;default:return -1;}}

s32 func_ov003_02200b5c(u32 a){switch(a){case 0:return 15;case 1:return 16;case 2:return 17;case 3:return 18;case 4:return 19;case 5:return 22;case 6:return 23;case 7:return 24;default:return -1;}}

void func_ov003_02200bd0(u32 arg0) {
    M2C_UNK func_ov003_02200968(u32);
    u32 var_r0;

    var_r0 = arg0;
    switch (var_r0) {
    default:
        break;
    case 3:
        var_r0 = 4;
        break;
    case 4:
        var_r0 = 0;
        break;
    case 5:
        var_r0 = 1;
        break;
    case 6:
        var_r0 = 2;
        break;
    case 2:
        var_r0 = 6;
        break;
    case 7:
        var_r0 = 5;
        break;
    case 8:
        var_r0 = 8;
        break;
    case 9:
        var_r0 = 9;
        break;
    case 10:
        var_r0 = 0xA;
        break;
    case 11:
        var_r0 = 0xB;
        break;
    }
    func_ov003_02200968(var_r0);
}

u8 func_ov003_02200c64(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_02200c7c(void) {
    s32 func_020846a4();
    s32 func_0208485c();
    s32 result;
    if (func_020846a4() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_02200ca8(void) {
    s32 func_020846a4();
    s32 func_02084890();
    s32 result;
    if (func_020846a4() && func_02084890()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_02200cd4(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

u16 func_ov003_02200cec(u32 a,u16 b) {
extern u16 data_ov003_0221045e[];
extern u16 data_ov003_0221047a[];
extern u16 data_ov003_02210462[];
extern u16 data_ov003_0221046a[];
switch(a){
case 0:b=data_ov003_0221045e[b];break;
case 1:b=data_ov003_0221047a[b];break;
case 2:b=data_ov003_02210462[b];break;
case 6:b=data_ov003_0221046a[b];break;
case 7:b=data_ov003_0221045e[b];break;
default:break;
}
return (u16)(b<<4);
}

s32 func_ov003_02200d80(s32 a,s32 b){extern s32 data_ov003_022104a4[],data_ov003_022104b4[],data_ov003_02210494[];switch(a){case 6:b=data_ov003_022104a4[b];break;case 1:b=data_ov003_022104b4[b];break;case 2:b=data_ov003_02210494[b];break;}return b;}

void func_ov003_02200dc8(void *a,u32 b) {
s32 func_0207c928(u8,s32);
s32 func_01ffa810(u32);
u8 v;void *p;
if(b<8)M2C_FIELD(a,u8 *,6)=b;
else if(b==8){
v=func_0207c928(M2C_FIELD(a,u8 *,6),4);
p=a+b*4;
M2C_FIELD(M2C_FIELD(p,void **,0xe8),s16 *,0x68)=v+4;
M2C_FIELD(M2C_FIELD(p,void **,0xe8),s16 *,0x6a)=v;
}
M2C_FIELD(a,s32 *,0x10c)=func_01ffa810(b);
}

void func_ov003_02200e1c(void *arg0) {
    M2C_UNK func_020aacf0(s32);
    s32 var_r0;
    s32 var_r0_2;
    u8 var_r8;
    void *temp_r0;
    void *temp_r2;
    void *temp_r3;

    M2C_FIELD(arg0, s8 *, 4) = -1;
    M2C_FIELD(arg0, s8 *, 5) = -1;
    var_r8 = 0;
    do {
        func_020aacf0(M2C_FIELD((void *)((u8 *) arg0 + (var_r8 * 4)), s32 *, 0xE8));
        temp_r3 = M2C_FIELD((arg0 + (var_r8 * 4)), void **, 0xE8);
        var_r0 = 1;
        temp_r2 = M2C_FIELD(temp_r3, void **, 0x64);
        if ((M2C_FIELD(temp_r2, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(temp_r3, u8 *, 0x59) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(temp_r2, s8 *, 0xC) != 1))) {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 4) = var_r8;
        }
        temp_r0 = M2C_FIELD(&((u8 *) arg0)[var_r8 * 4], void **, 0xE8);
        if ((((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(temp_r0, s32 *, 0x40) << 6) >> 0x18)) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            M2C_FIELD(arg0, u8 *, 5) = var_r8;
        }
        var_r8 += 1;
    } while ((u32) var_r8 < 9U);
}

