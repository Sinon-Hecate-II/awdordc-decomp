/* 34 functions from 0x0209BC58 to 0x0209CC04 (main), found by ds-decomp. */
#include "common.h"

extern s32 gCur3DSpriteEngine;
extern s32 data_027e00c8;
extern u8 data_021580a8[256];
extern s32 data_0215d8a8[58];  // 232 bytes / 4
extern s32 data_0215d8a0[2];   // 8 bytes / 4

void func_0209bc58(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6, u16 arg7) {
    s32 func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_02099e58(s32);
    M2C_UNK func_0209bdcc(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK data_02103300;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;
    temp_r4 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x54);
    func_0209bdcc(temp_r4, arg0, arg1, arg2, arg3, arg4, arg5, (s32)arg6, (s32)arg7);
    func_02099e58(temp_r4);
    func_01ffa3dc(&data_02103300, 7);
}

void func_0209bccc(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    void func_0209bd0c(M2C_UNK, M2C_UNK, s32, s32, s32, s32, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *temp_r5;

    temp_r5 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209bd0c(arg0, arg1, arg2, M2C_FIELD(temp_r5, s32 *, 0xC), M2C_FIELD(temp_r5, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5);
}

void func_0209bd0c(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u16 g,u16 h) {
s32 func_02086680(s32);
s32 func_0209bd60(s32,s32,s32,s32,s32,s32,u16,u16);
func_0209bd60(a,b,c,d,e,func_02086680(f),g,h);
}

s32 func_0209bd60(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6, u16 arg7) {
    s32 func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_0209bdcc(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK data_02103328;
    s32 temp_r0;
    temp_r0 = func_01ffa3dc(&data_02103328, 7);
    func_0209bdcc(temp_r0, arg0, arg1, arg2, arg3, arg4, arg5, (s32)arg6, (s32)arg7);
    return temp_r0;
}

s32 func_0209bdcc(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,u16 h,u16 i) {
void func_0209be10(void *,s32,s32,s32,s32,s32,s32,u16,u16,u16);
func_0209be10((void *)a,b,c,d,e,f,g,h,0,i);
}

void func_0209be10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u16 arg7, u16 arg8, u16 arg9) {
    void (*func_02091fb4(u32))(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;

    M2C_FIELD(arg0, s32 *, 0x34) = arg6;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, u8 *, 0x57) = (u8)arg3;
    M2C_FIELD(arg0, s32 *, 0x3c) = arg4;
    M2C_FIELD(arg0, s32 *, 0x40) = arg5;
    M2C_FIELD(arg0, u16 *, 0x44) = arg7;
    M2C_FIELD(arg0, u16 *, 0x46) = arg8;
    M2C_FIELD(arg0, u16 *, 0x4e) = arg9;
    M2C_FIELD(arg0, u16 *, 0x4c) = arg9;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, u8 *, 0x48) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x49) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4a) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4b) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x54) = (u8)(0 - 1);
    M2C_FIELD(arg0, u8 *, 0x55) = 2;
    M2C_FIELD(arg0, s32 *, 0x50) = (s32)func_02091fb4((u32)arg3);
    {
        s32 temp_r0;

        if (gCur3DSpriteEngine == data_027e00c8) {
            temp_r0 = 1;
        } else {
            temp_r0 = 0;
        }
        temp_r0 = (s32)(u8)temp_r0;
        if (temp_r0 != 1) {
            temp_r0 = 1;
        } else {
            temp_r0 = 0;
        }
        M2C_FIELD(arg0, u8 *, 0x5a) = (u8)temp_r0;
    }
    M2C_FIELD(arg0, u8 *, 0x56) = 0;
    M2C_FIELD(arg0, u8 *, 0x58) = 0;
    M2C_FIELD(arg0, u8 *, 0x59) = 0;
    M2C_FIELD(arg0, u8 *, 0x5c) = 0;
}

void func_0209bee0(void *a,s32 b,s32 c,s32 d,s32 e,s32 f,u16 g,u16 h) {
M2C_FIELD(a,u8 *,0x57)=d;
M2C_FIELD(a,s32 *,0x3c)=e;
M2C_FIELD(a,s32 *,0x40)=f;
M2C_FIELD(a,u16 *,0x44)=g;
M2C_FIELD(a,u16 *,0x4e)=h;
M2C_FIELD(a,u16 *,0x4c)=h;
M2C_FIELD(a,u8 *,0x48)=(u8)b;
M2C_FIELD(a,u8 *,0x49)=(u8)c;
M2C_FIELD(a,u8 *,0x4a)=(u8)b;
M2C_FIELD(a,u8 *,0x4b)=(u8)c;
}

u8 func_0209bf28(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02103328;
    extern M2C_UNK data_021032d8;
    extern M2C_UNK data_02103300;
    u8 var_r0;

    if (func_01ffa770(&data_02103328) != 0) {
        return 1U;
    }
    if (func_01ffa770(&data_021032d8) != 0) {
        return 1U;
    }
    if (func_01ffa770(&data_02103300) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0209bf7c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02103328, data_021032d8, data_02103300;
    func_01ffa9e4(&data_02103328);
    func_01ffa9e4(&data_021032d8);
    func_01ffa9e4(&data_02103300);
}

void func_0209bfa8(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_021032d8;
    extern M2C_UNK data_02103300;
    func_01ffa9e4(&data_021032d8);
    func_01ffa9e4(&data_02103300);
}

void func_0209bfc8(void) {
    M2C_UNK func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02103328;
    func_01ffa770(&data_02103328);
}

void func_0209bfdc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    M2C_UNK func_0209c024(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    func_0209c024(arg0, arg1, arg2, func_02086680(arg3), (s32) arg4, (s32) arg5);
}

s32 func_0209c024(s32 a,s32 b,s32 c,s32 d,u16 e,u16 f) {
s32 func_0209953c(s32,s32,s32,s32,u16,u16);
func_0209953c(a,b,c,d,e,f);
}

void func_0209c048(s32 arg0, s32 arg1, s32 arg2, u32 arg3, u16 arg4, u16 arg5) {
    u32 var_r3;
    u16 var_r1;
    s16 *var_r0;

    var_r3 = arg3;
    var_r0 = (s16 *)(arg2 + (arg0 * 2) + (arg1 << 6));
    var_r1 = 0x10;
    if (arg5 == 3) {
        var_r1 += 0x1C;
    }
    do {
        u32 rem;

        rem = var_r3 % 10;
        *var_r0 = (s16)(arg4 | (var_r1 + (rem * 2)));
        *(s16 *)((u8 *)var_r0 + 0x40) = (s16)(arg4 | ((var_r1 + (rem * 2)) + 1));
        var_r0 = (s16 *)((u8 *)var_r0 - 2);
        var_r3 = var_r3 / 10;
    } while (var_r3 != 0);
}

void func_0209c0bc(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    u16 var_r2;

    arg0 = arg2 + (arg0 * 2) + (arg1 << 6);
    var_r2 = 0x10;
    switch (arg3) {
    case 0x47:
        var_r2 += 0x1A;
        break;
    case 0x2B:
        var_r2 += 0x14;
        break;
    case 0x2D:
        var_r2 += 0x16;
        break;
    case 0x3D:
        var_r2 += 0x18;
        break;
    }
    if (arg5 == 3) {
        var_r2 += 0x1C;
    }
    *(s16 *)arg0 = (s16)(var_r2 | arg4);
    *(s16 *)((u8 *)arg0 + 0x40) = (s16)((var_r2 + 1) | arg4);
}

s32 func_0209c168(void *arg0, s32 arg1) {
    u8 temp_r1;
    u8 var_r2;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x56) + arg1;
    var_r2 = temp_r1;
    M2C_FIELD(arg0, u8 *, 0x56) = temp_r1;
    if ((u32) var_r2 >= 8U) {
        do {
            M2C_FIELD(arg0, u8 *, 0x56) = (u8) (M2C_FIELD(arg0, u8 *, 0x56) - 8);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + 2);
            M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 1);
            var_r2 = M2C_FIELD(arg0, u8 *, 0x56);
        } while ((u32) var_r2 >= 8U);
    }
    if (var_r2 != 0) {
        return 1;
    }
    return 0;
}

s32 func_0209c1c0(u8 *arg0, s32 *arg1) {
    u8 func_02099ae8(u8 *);
    u8 func_02099b00(u8 *);
    extern u8 data_ov000_021b7e7c[256];

    if (arg0 != NULL) {
        if (func_02099ae8(arg0)) {
            *arg1 += 8;
            return 2;
        }
        if (func_02099b00(arg0)) {
            if (*arg1 != 0) {
                *arg1 += 1;
            }
            *arg1 += data_ov000_021b7e7c[arg0[1]];
            return 2;
        }
        if (*arg1 != 0) {
            *arg1 += 1;
        }
        *arg1 += data_ov000_021b7e7c[arg0[0]];
        return 1;
    }
    return 0;
}

s32 func_0209c268(u8 *arg0) {
    s32 func_0209c1c0(u8 *, s32 *);
    s32 sp0;
    u8 *var_r5;

    var_r5 = arg0;
    sp0 = 0;
    if ((var_r5 != NULL) && (*var_r5 != 0)) {
        do {
            var_r5 = &var_r5[func_0209c1c0(var_r5, &sp0)];
        } while (*var_r5 != 0);
    }
    return sp0;
}

s32 func_0209c2a8(void) {
    s32 func_0209c2c4();
    s32 temp_r1;

    temp_r1 = func_0209c2c4() + 6;
    return (s32) (temp_r1 + ((u32) (temp_r1 >> 2) >> 0x1D)) >> 3;
}

s32 func_0209c2c4(u8 *arg0) {
    s32 func_02086680(u32);
    s32 func_0209c268(u8 *);
    s32 func_0209c1c0(u8 *, s32 *);
    extern u8 data_0212616c[];
    extern void **gCurrentMap;
    s32 sp0;
    u8 *r9;

    sp0 = 0;
    r9 = arg0;
    if (*r9 != 0) {
        do {
            u8 c;
            c = *r9;
            if (c == 0) break;
            if (c <= 0x16) {
                if (c == 0x16) {
                    r9 += 2;
                } else if (c >= 0x8) {
                    if (c == 0x8) {
                        r9 += func_0209c1c0(r9, &sp0);
                    } else if (c == 0xB) {
                        u8 sub = (u8)(r9[1] - 0x80);
                        if (sub <= 3) {
                            if (sub <= 1) {
                                sp0 += 0x10;
                                r9 += 2;
                            } else {
                                u16 sel;
                                s8 kind;
                                sel = *(u16 *)((u8 *)*gCurrentMap + 0x52A4);
                                kind = *(s8 *)((u8 *)*gCurrentMap + (u32)sel * 0x8C + 0x6810);
                                sp0 += func_0209c268((u8 *)func_02086680(*(u32 *)(data_0212616c + (int)kind * 0x9C)));
                                r9 += 2;
                            }
                        }
                    } else {
                        sp0 += 0x10;
                        r9 += 2;
                    }
                } else {
                    sp0 += 0x10;
                    r9 += 2;
                }
            } else {
                if (c >= 0x17 && c <= 0x1D && (c == 0x17 || c == 0x1C || c == 0x1D)) {
                    r9 += 2;
                } else {
                    sp0 += 0x10;
                    r9 += 2;
                }
            }
        } while (*r9 != 0);
    }
    if (sp0 < 0) {
        sp0 = 0;
    }
    return sp0;
}

void func_0209c418(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
}

void func_0209c428(void *arg0) {
    void func_0209c418(void *);
    func_0209c418(arg0);
    if (*(u8 *) M2C_FIELD(arg0, void **, 0x34) == 0x0D ||
        *(u8 *) M2C_FIELD(arg0, void **, 0x34) == 0x0A) {
        func_0209c428(arg0);
    }
}

s32 func_0209c454(u8 *arg0,s32 arg1) {
s32 func_0209c1c0(u8 *,s32 *);
s32 width; s32 zero;  s32 max=0;u8 *p=arg0; u8 c; width=0;
if(!p)return 0;
c=*p;
if(c){zero=0;do{
switch(c){
case 10:case 13:
if(!arg1)return width;
p++;if(width>max)max=width;width=zero;break;
case 4:p++;break;
case 22:case 23:case 28:case 29:p+=2;break;
default:p+=func_0209c1c0(p,&width);break;
}
c=*p;
}while(c);}
if(max>width)width=max;
return width;
}

s32 func_0209c550(u8 *arg0) {
    s32 var_r1;
    u8 *var_r0;
    u8 var_r2;

    var_r0 = arg0;
    var_r1 = 0x10;
    if (var_r0 == NULL) {
        return 0;
    }
    var_r2 = *var_r0;
    if (var_r2 != 0) {
        do {
            switch ((s32) var_r2) {                 /* irregular */
            case 10:
            case 13:
                var_r1 += 0x10;
                var_r0 += 1;
                break;
            case 23:
            case 28:
                /* fallthrough */
            case 22:
                var_r0 += 2;
                break;
            default:
                var_r0 += 1;
                break;
            }
            var_r2 = *var_r0;
        } while (var_r2 != 0);
    }
    return var_r1;
}

void *func_0209c5dc(void *arg0, s32 arg1) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *cur;
    s32 i;

    if (arg0 == NULL) {
        return NULL;
    }
    cur = arg0;
    i = 0;
    if (arg1 > 0) {
        do {
            void *r0;

            r0 = func_02099b18(cur, 13, 1);
            if (r0 == NULL) {
                r0 = func_02099b18(cur, 10, 1);
                if (r0 == NULL) {
                    return NULL;
                }
            }
            i++;
            cur = (void *)((u8 *)r0 + 1);
        } while (i < arg1);
    }
    return cur;
}

void *func_0209c658(M2C_UNK arg0) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 temp_r1;
    void *temp_r0;
    void *var_r0;

    temp_r0 = func_02099b18(arg0, 4, 1);
    if (temp_r0 != NULL) {
        temp_r1 = M2C_FIELD(temp_r0, u8 *, 1);
        var_r0 = temp_r0 + 1;
        if ((temp_r1 != 0xA) && (temp_r1 != 0xD)) {

        } else {
            var_r0 += 1;
        }
        return var_r0;
    }
    return NULL;
}

s32 func_0209c690(void) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 temp_r1;

    temp_r0 = ((void *(*)(M2C_UNK, M2C_UNK))func_02099b18)(0x1d, 0);
    if (temp_r0 == NULL) {
        return 0;
    }
    temp_r1 = *(u8 *)((u8 *)temp_r0 + 1) & 0x7F;
    switch (temp_r1) {
    case 0:
    case 1:
    case 2:
    case 3:
        return temp_r1;
    default:
        return 0;
    }
}

void *func_0209c6d8(s32 arg0) {
    u8 result;
    u8 *base;

    if (gCur3DSpriteEngine == data_027e00c8) {
        result = 1;
    } else {
        result = 0;
    }
    if (result != 1) {
        result = 1;
    } else {
        result = 0;
    }
    base = data_021580a8;
    return base + (result << 7) + (arg0 << 2);
}

void func_0209c720(s32 arg0, s16 arg1, s8 arg2, s32 arg3, u8 arg4) {
    void *func_0209c6d8(s32);
    u8 *p;
    u8 old;
    u8 r1, r2, r3, r12;

    (void)arg3;
    p = (u8 *)func_0209c6d8(arg0);
    *(s16 *)p = arg1;
    p[2] = (u8)arg2;
    old = p[3];
    r2 = arg4;
    r1 = (u8)(old & ~0xF);
    r3 = (u8)(r2 & 0xF);
    r12 = (u8)(r1 | r3);
    r1 = (u8)(r12 & 0xFF);
    r1 = (u8)(r1 & ~0xF0);
    r3 = (u8)((int)r2 << 0x1C);
    r3 = (u8)((int)r3 >> 0x18);
    p[3] = (u8)(r1 | r3);
}

void func_0209c764(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_01ff8e44(s32, s32);
    void func_01ffaacc(s32, s32, s32);
    u8 *r4;
    u8 r1_val;
    s32 r0_val;
    s32 r2_val;
    s32 r1_shifted;
    s32 temp_r0;
    u8 r12_val;
    u16 r2_half;
    u16 r1_half;
    u32 r0_mask;

    r4 = func_0209c6d8(arg0);
    r1_val = r4[3];
    r0_val = (r1_val << 24) >> 28;
    r2_val = r1_val << 28;
    r1_shifted = r2_val >> 25;
    r1_shifted = r0_val << 3;
    temp_r0 = func_01ff8e44(r0_val, r1_shifted);
    if (temp_r0 == 0) {
        return;
    }
    r12_val = r4[2];
    r2_half = *(u16 *)r4;
    r1_half = *(u16 *)gCur3DSpriteEngine;
    r0_mask = 0x3FF;
    r0_mask = r0_mask & (r2_half >> ((r1_half >> 13) & 3));
    r0_mask = arg3 | r0_mask;
    r0_mask = r0_mask | (r12_val << 12);
    func_01ffaacc(arg1, arg2, r0_mask & 0xFFFF);
}

void func_0209c7fc(void) {
    s32 *var_r5;
    s32 var_r4;
    s32 temp_r2;
    s32 temp_r3;
    s32 temp_lr;
    s32 temp_r12;
    u32 const1 = 0xFFFE007F;
    u32 const2 = 0xFC01FFFF;

    var_r5 = data_0215d8a8;
    var_r4 = 0;
    const1 = 0xFFFE007F;
    const2 = 0xFC01FFFF;
    do {
        var_r4 += 1;
        temp_r2 = *var_r5;
        temp_lr = temp_r2 & ~7;
        temp_r3 = temp_lr & ~0x78;
        temp_r12 = temp_r3 & const1;
        temp_r2 = temp_r12 & const2;
        temp_r3 = temp_r2 & ~0x1C000000;
        temp_r2 = temp_r3 & ~0xE0000000;
        *var_r5 = temp_r3;
        *var_r5++ = temp_r2;
    } while (var_r4 < 0x40);
    *(s32 *)((u8 *)&data_0215d8a0 + 8) = (*(s32 *)((u8 *)&data_0215d8a0 + 8) & ~7) | 1;
}

void func_0209c868(void) {
    s32 *p = (s32 *)&data_0215d8a8;
    s32 i = 0;

    do {
        s32 t;

        t = *p;
        i = i + 1;
        if (((u32)t << 29 >> 29) == 1) {
            *p = (t & ~7) | 2;
        }
        t = *p;
        if (((u32)t << 29 >> 29) == 3) {
            *p = (t & ~7) | 4;
        }
        t = *p;
        *p = (t & ~0x1C000000) | (((u32)t >> 29) << 26);
        p = p + 1;
    } while (i < 0x40);
}

void func_0209cbe4(u32 *arg0) {
    u32 temp_r2;

    temp_r2 = *arg0 + 1;
    if (temp_r2 >= 0x0CDFE5C4U) {
        *arg0 = 0x0CDFE5C4;
        return;
    }
    *arg0 = temp_r2;
}

