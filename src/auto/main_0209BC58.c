/* 34 functions from 0x0209BC58 to 0x0209CC04 (main), found by ds-decomp. */
#include "common.h"
typedef struct SpriteStateWord {
    u32 state : 3;
    u32 field3 : 4;
    u32 field7 : 10;
    u32 field17 : 9;
    u32 field26 : 3;
    u32 field29 : 3;
} SpriteStateWord;

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
    s32 sum;
    u32 mod;

    sum = M2C_FIELD(arg0, u8 *, 0x56) + arg1;
    mod = sum & 0xFF;
    M2C_FIELD(arg0, u8 *, 0x56) = (u8)sum;
    if (mod >= 8) {
        do {
            M2C_FIELD(arg0, u8 *, 0x56) = (u8)(M2C_FIELD(arg0, u8 *, 0x56) - 8);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16)(M2C_FIELD(arg0, u16 *, 0x4C) + 2);
            M2C_FIELD(arg0, u8 *, 0x4A) = (u8)(M2C_FIELD(arg0, u8 *, 0x4A) + 1);
            mod = M2C_FIELD(arg0, u8 *, 0x56);
        } while (mod >= 8);
    }
    if (mod != 0) {
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

s32 func_0209c690(M2C_UNK arg0) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 temp_r1;

    temp_r0 = func_02099b18(arg0, 0x1d, 0);
    if (temp_r0 == 0) {
        goto fail;
    }
    temp_r1 = *(u8 *)((u8 *)temp_r0 + 1) & 0x7F;
    switch (temp_r1) {
    case 0:
    case 1:
    case 2:
    case 3:
        return temp_r1;
    default:
        break;
    }
fail:
    return 0;
}

void *func_0209c6d8(s32 arg0) {
 u8 result=(gCur3DSpriteEngine==data_027e00c8);
 s32 flag=result!=1;
 u8 *base=data_021580a8;
 return base+(flag<<7)+(arg0<<2);
}

s32 func_0209c720(s32 arg0,s16 arg1,s8 arg2,s32 arg3,volatile u8 arg4){
void *func_0209c6d8(s32);u8 *p=func_0209c6d8(arg0);u8 old;u32 value;
*(s16 *)p=arg1;p[2]=arg2;
old=*(volatile u8 *)(p+3);value=arg4;
old=(old&~15)|(value&15);
p[3]=(old&~240)|((value<<28)>>24);
}

void func_0209c764(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *func_0209c6d8(s32);
    s32 func_01ff8e44(s32, s32);
    void func_01ffaacc(s32, s32, s32, s32);
    extern M2C_UNK gCur3DSpriteEngine;
    u8 *r4;
    u8 byte3;
    u32 high;
    u32 low;
    s32 temp0;
    u8 byte2;
    u16 half_self;
    u16 half_eng;
    u32 mask;

    r4 = (u8 *)func_0209c6d8(arg0);
    byte3 = r4[3];
    high = ((u32)byte3 << 24) >> 28;
    low = ((u32)(byte3 & 0x0F)) << 3;
    temp0 = func_01ff8e44((s32)low, (s32)(high << 3));
    if (temp0 == 0) return;
    byte2 = r4[2];
    half_self = *(u16 *)r4;
    half_eng = *(u16 *)((void *)gCur3DSpriteEngine);
    mask = 0x3FF;
    mask = mask & (half_self >> (((u32)half_eng >> 13) & 3));
    mask = (u32)arg3 | mask;
    mask = mask | ((u32)byte2 << 12);
    func_01ffaacc(arg1, arg2, (s32)(mask & 0xFFFF), arg4);
}

#pragma opt_propagation off
#pragma opt_lifetimes off
void func_0209c7fc(void) {
s32 i; volatile s32 *p; s32 a,b,c,d;
u32 mask1,mask2;
p=data_0215d8a8; mask1=0xfffe007f; mask2=0xfc01ffff; i=0;
do {
a=*p;
i++;
b=a&~7;
c=b&~0x78;
d=c&mask1;
a=d&mask2;
c=a&~0x1c000000;
a=c&~0xe0000000;
*(volatile s32 *)p=c;
*p++=a;
}while(i<64);
*(s32 *)((u8 *)&data_0215d8a0+8)=(*(s32 *)((u8 *)&data_0215d8a0+8)&~7)|1;
}
#pragma opt_propagation off
void func_0209c868(void) {
s32 i;
SpriteStateWord *p;
p=(SpriteStateWord *)data_0215d8a8;
i=0;
do {
i++;
if(p->state==1)p->state=2;
if(p->state==3)p->state=4;
p->field26=p->field29;
p++;
}while(i<64);
}

void func_0209c8d4(void) {
    s32 func_02084644();
    s32 func_020846a4();
    M2C_UNK func_02086844(u16, M2C_UNK);
    M2C_UNK func_02086878(u16, M2C_UNK);
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    s32 func_020a1944();
    M2C_UNK func_020bf814(u16);
    s32 func_020bf894(s32);
    s32 func_020cd1e4();
    s32 func_020d1afc();
    s32 func_020d1b40();
    s32 func_020e4b54();
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_0215c340;
    extern s32 data_0215d8a0[2];
    extern s32 data_0215d8a8[58];
    extern u16 data_02168f14;
    extern void **data_027e0058;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r9;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r5;
    s32 var_r7;
    u16 temp_r8;
    u32 temp_r3_2;
    u32 var_r1;
    u8 temp_r11;

    temp_r11 = M2C_FIELD(&data_0215c334, u8 *, 4);
    temp_r8 = M2C_FIELD(*data_027e0058, u16 *, 0x5142);
    var_r7 = 0;
    temp_r9 = temp_r8 - 0xA1;
    do {
        if (func_020bf894(var_r7) != 0) {
            var_r0 = M2C_FIELD(&data_0215c334, s32 *, 8) | (1 << var_r7);
        } else {
            var_r0 = M2C_FIELD(&data_0215c334, s32 *, 8) & (-1 ^ (1 << var_r7));
        }
        var_r7 += 1;
        M2C_FIELD(&data_0215c334, s32 *, 8) = var_r0;
    } while (var_r7 < 0xF);
    if (func_020846a4() == 0) {
        func_02086844(temp_r8, 1);
        if (func_020cd1e4() != 0) {
            if ((func_020d1afc() != 0) && (func_020d1b40() == 0)) {
                func_02091c20(0x1A, 1);
                func_02086878(temp_r8, 1);
            }
            switch (temp_r8) {                      /* switch 1; irregular */
            case 0xB1:                              /* switch 1 */
                func_02091c20(0x1D, 1);
                break;
            case 0xBA:                              /* switch 1 */
                func_02091c20(0x1E, 1);
                break;
            }
            if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF)) {
                temp_r5 = data_0215d8a8[temp_r9];
                if ((u32) M2C_FIELD(&data_0215c334, u16 *, 6) >= (u32) ((u32) (temp_r5 << 6) >> 0x17)) {
                    temp_r3 = (((temp_r5 & ~0x78) | ((u32) (*(s32 *)((u8 *)&data_0215c340 + (temp_r11 * 0xC)) << 0x1C) >> 0x19)) & 0xFC01FFFF) | ((u32) (M2C_FIELD(&data_0215c334, u16 *, 6) << 0x17) >> 6);
                    data_0215d8a8[temp_r9] = temp_r3;
                    temp_r3_2 = (temp_r3 & 0xFFFE007F) | ((u32) (M2C_FIELD(*data_027e0058, u16 *, 0x52A2) << 0x16) >> 0xF);
                    data_0215d8a8[temp_r9] = (temp_r3_2 & ~0x1C000000) | ((u32) ((temp_r3_2 >> 0x1D) << 0x1D) >> 3);
                    data_0215d8a8[temp_r9] = (data_0215d8a8[temp_r9] & ~0xE0000000) | (func_020a1944() << 0x1D);
                }
                temp_r0 = data_0215d8a8[temp_r9];
                temp_r0_2 = temp_r0 & ~7;
                if ((u32) ((u32) (temp_r0 << 0x1D) >> 0x1D) < 3U) {
                    var_r0_2 = temp_r0_2 | 3;
                } else {
                    var_r0_2 = temp_r0_2 | 4;
                }
                data_0215d8a8[temp_r9] = var_r0_2;
                func_020bf814(temp_r8);
                if (func_020e4b54() != 0) {
                    var_r1 = (u32) (data_0215d8a0[0] << 8) >> 0x18;
                    if ((s32) var_r1 < 0xFF) {
                        var_r1 += 1;
                    }
                    data_0215d8a0[0] = (data_0215d8a0[0] & ~0xFF0000) | ((u32) (var_r1 << 0x18) >> 8);
                }
                switch (M2C_FIELD(&data_0215c334, u8 *, 3)) { /* switch 2 */
                default:                            /* switch 2 */
                    break;
                case 4:                             /* switch 2 */
                    func_02091c20(2, 1);
                    break;
                case 3:                             /* switch 2 */
                    func_02091c20(3, 1);
                    break;
                case 2:                             /* switch 2 */
                    func_02091c20(4, 1);
                    break;
                case 1:                             /* switch 2 */
                    func_02091c20(5, 1);
                    break;
                }
            }
        }
    }
    var_r5 = 0;
    do {
        if (!(M2C_FIELD(&data_0215c334, s32 *, 8) & (1 << var_r5)) && (func_020bf894(var_r5) != 0)) {
            M2C_FIELD(&data_0215c334, s32 *, 8) = (s32) (M2C_FIELD(&data_0215c334, s32 *, 8) | (1 << var_r5));
        } else {
            M2C_FIELD(&data_0215c334, s32 *, 8) = (s32) (M2C_FIELD(&data_0215c334, s32 *, 8) & (-1 ^ (1 << var_r5)));
        }
        var_r5 += 1;
    } while (var_r5 < 0xF);
    temp_r0_3 = func_02084644();
    switch (temp_r0_3) {                            /* switch 3; irregular */
    case 1:                                         /* switch 3 */
        func_02091c20(0x21, 1);
        return;
    case 2:                                         /* switch 3 */
        func_02091c20(0x20, 1);
        return;
    }
}

#pragma opt_propagation reset
void func_0209cbe4(u32 *arg0) {
    u32 temp_r2;

    temp_r2 = *arg0 + 1;
    if (temp_r2 >= 0x0CDFE5C4U) {
        *arg0 = 0x0CDFE5C4;
        return;
    }
    *arg0 = temp_r2;
}

