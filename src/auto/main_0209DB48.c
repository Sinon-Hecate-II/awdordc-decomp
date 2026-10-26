/* 37 functions from 0x0209DB48 to 0x0209EAF4 (main), found by ds-decomp. */
#include "common.h"

typedef struct {
    void *next;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u8 lo : 4;
    u8 hi : 4;
} Unk0209Node;

typedef struct {
    u16 unk0, unk2, unk4, unk6;
} Unk0209Rect;

void func_0209db48(void) {
    void func_01ff883c(u16, u16, u16, s32);
    void func_01ff8930(s16, s16, u16, u16, u16, s32);
    void func_01ff8a8c(u16, u16, u16, s32);
    void func_01ff8c0c(s16, s16, u16, u16, u16, s32);
    void func_0209daec(void);
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;

    void *cur;
    void *saved;
    s32 i;

    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        void *head;
        unsigned char raw;

        if (i == 0) {
            head = data_027e00c8;
        } else {
            head = data_027e00c4;
        }
        gCur3DSpriteEngine = head;
        cur = *(void **)((char *)head + 0x8);
        while (cur != NULL) {
            raw = *(unsigned char *)((char *)cur + 0x12);
            if (((int)raw << 24 >> 28) != 0) {
                if (((int)raw << 28 >> 28) == 0) {
                    func_01ff8930(*(s16 *)((char *)cur + 0x8),
                                  *(s16 *)((char *)cur + 0xA),
                                  *(u16 *)((char *)cur + 0xC),
                                  *(u16 *)((char *)cur + 0xE),
                                  *(u16 *)((char *)cur + 0x10),
                                  *(s32 *)((char *)cur + 0x4));
                } else {
                    func_01ff8c0c(*(s16 *)((char *)cur + 0x8),
                                  *(s16 *)((char *)cur + 0xA),
                                  *(u16 *)((char *)cur + 0xC),
                                  *(u16 *)((char *)cur + 0xE),
                                  *(u16 *)((char *)cur + 0x10),
                                  *(s32 *)((char *)cur + 0x4));
                }
            } else {
                if (((int)raw << 28 >> 28) == 0) {
                    func_01ff883c(*(u16 *)((char *)cur + 0xC),
                                  *(u16 *)((char *)cur + 0xE),
                                  *(u16 *)((char *)cur + 0x10),
                                  *(s32 *)((char *)cur + 0x4));
                } else {
                    func_01ff8a8c(*(u16 *)((char *)cur + 0xC),
                                  *(u16 *)((char *)cur + 0xE),
                                  *(u16 *)((char *)cur + 0x10),
                                  *(s32 *)((char *)cur + 0x4));
                }
            }
            cur = *(void **)((char *)cur + 0x0);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    func_0209daec();
}

s32 func_0209dc48(void) {
    extern u16 *data_02101e84;
    u16 keys;
    keys = data_02101e84[0];
    if (keys & 1) return 0x10;
    if (keys & 2) return 0x20;
    if (keys & 8) return 0x400;
    keys = data_02101e84[3];
    if ((keys & 1) && (keys & 0x80)) return 0x10;
    return 0;
}

s32 func_0209dc9c(void) {
    extern u16 *data_02101e84;
    u16 keys;
    keys = data_02101e84[0];
    if (keys & 8) return 0x400;
    if (keys & 2) return 0x20;
    if (keys & 1) return 0x10;
    keys = data_02101e84[3];
    if ((keys & 1) && (keys & 0x80)) return 0x10;
    return 0;
}

s32 func_0209dcf0(void) {
    extern u16 *data_02101e84;
    u16 temp_r0;

    temp_r0 = *data_02101e84;
    if (temp_r0 & 0x20) {
        return 4;
    }
    if (temp_r0 & 0x10) {
        return 8;
    }
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    return 0;
}

void func_0209dd34(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0x100;
    M2C_FIELD(arg0, s16 *, 6) = 0xC0;
}

s32 func_0209dd54(void) {
    extern void *data_02101e88;
    s16 rect[4];
    u16 x;
    u16 y;
    x = M2C_FIELD(data_02101e88, u16 *, 0);
    y = M2C_FIELD(data_02101e88, u16 *, 2);
    func_0209dd34(rect);
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) == 0) return 0;
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) == 0) return 0;
    if (rect[0] < x && x < rect[0] + rect[2] && rect[1] < y && y < rect[1] + rect[3]) return 0x10;
    return 0;
}

s32 func_0209dde0(void) {
    extern void *data_02101e88;
    s16 rect[4];
    u16 x;
    u16 y;
    x = M2C_FIELD(data_02101e88, u16 *, 0);
    y = M2C_FIELD(data_02101e88, u16 *, 2);
    func_0209dd34(rect);
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) == 0) return 0;
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) == 0) return 0;
    if (rect[0] < x && x < rect[0] + rect[2] && rect[1] < y && y < rect[1] + rect[3]) return 0x10;
    return 0;
}

void func_0209de6c(s32 arg0, Unk0209Rect arg1) {
    extern Unk0209Rect data_0215bde8[];
    Unk0209Rect *rect;
    rect = &data_0215bde8[arg0];
    *rect = arg1;
}

s32 func_0209deb0(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_020b2e78(M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_0215bdf0;
    extern M2C_UNK data_0215bdf8;
    if (func_020b2e78(arg0, arg1, &data_0215bdf0) != 0) {
        return 1;
    }
    if (func_020b2e78(arg0, arg1, &data_0215bdf8) != 0) {
        return 2;
    }
    return 0;
}

/* Returns the action code for the current stylus interaction, based on which of two touch regions the point lies in. */
s32 func_0209def8(void) {
    extern void *data_02101e88;
    extern s32 data_0215bde0;
    s32 region;

    region = func_0209deb0(M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2));
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) != 0) {
        if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
            data_0215bde0 = region;
        } else {
            if (M2C_FIELD(data_02101e88, u8 *, 0x10) == 0x14) {
                data_0215bde0 = 0;
            }
            if (data_0215bde0 != region) {
                data_0215bde0 = 0;
            }
        }
        switch (region) {                          /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            return 4;
        case 2:                                     /* switch 1 */
            return 8;
        default:                                    /* switch 1 */
            return 0;
        }
    } else if ((M2C_FIELD(data_02101e88, u8 *, 0x16) != 0) && (data_0215bde0 == region)) {
        switch (data_0215bde0) {                    /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            return 0x10;
        case 2:                                     /* switch 2 */
            return 0x10;
        default:                                    /* switch 2 */
            return 0;
        }
    } else {
        return 0;
    }
}

void func_0209dfe4(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    s32 func_02005d90(s32);
    if (func_02005d90(M2C_FIELD(arg0, s32 *, 0x34)) == 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_0209e008(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    M2C_UNK (*temp_r0)();

    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x34));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x38));
    temp_r0 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x3C);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r0();
}

void func_0209e034(void *arg0) {
    M2C_FIELD(arg0, void (**)(void), 0)();
}

void func_0209e044(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    void **func_01ffa3dc(M2C_UNK *, s32);
    s32 func_020e34bc(u32);
    void func_01ffa8bc(void *, s32);
    void func_02005ac0(s32, void (*)(void *), void *, s32, u32, s32);
    void func_02005e5c(s32);
    extern M2C_UNK data_0211f7dc;
    void *p;
    p = func_01ffa3dc(&data_0211f7dc, 3);
    M2C_FIELD(p, s32 *, 0x34) = func_020e34bc(0xC0);
    M2C_FIELD(p, s32 *, 0x38) = func_020e34bc(arg2);
    M2C_FIELD(p, s32 *, 0x3C) = arg4;
    func_01ffa8bc(p, arg1);
    M2C_FIELD(p, s32 *, 0x40) = arg0;
    M2C_FIELD(p, s32 *, 0x44) = arg1;
    func_02005ac0(M2C_FIELD(p, s32 *, 0x34), func_0209e034, p + 0x40, M2C_FIELD(p, s32 *, 0x38) + (arg2 & ~3), arg2, arg3);
    func_02005e5c(M2C_FIELD(p, s32 *, 0x34));
}

u8 func_0209e0dc(M2C_UNK arg0) {
    extern M2C_UNK data_0211f7dc;
    u8 var_r0;

    if (func_01ffa860(&data_0211f7dc, arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0209e104(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02080cfc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211f840;
    extern M2C_UNK data_0211f848;
    extern M2C_UNK data_0211f858;
    func_0200bc5c(&data_0211f840);
    switch (arg0) {                                 /* irregular */
    case 1:
        func_02080cfc(&data_0211f848, arg1);
        return;
    case 2:
        func_02080cfc(&data_0211f858, arg1);
        return;
    }
}

void func_0209e158(s32 arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_0208116c(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211f868;
    extern M2C_UNK data_0211f870;
    func_0200bc5c(&data_0211f868);
    func_0208116c(&data_0211f870, arg0 << 5, 0x20);
}

void func_0209e184(void *arg0, s8 arg1, u32 arg2, s32 arg3) {
    M2C_UNK func_02088da8();
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg2 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg3 << 0x18) >> 6));
    func_02088da8();
}

void func_0209e1b0(void *arg0) {
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    M2C_UNK func_0209e320(void *);
    void *old;
    u32 mode;
    s32 i;
    void *p;
    old = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) p = data_027e00c8; else p = data_027e00c4;
        gCur3DSpriteEngine = p;
        mode = (u32)(M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29;
        if (((mode != 0) || (p == data_027e00c8)) &&
            ((mode != 1) || (p == data_027e00c4)) &&
            ((mode != 3) || (p == old))) {
            func_0209e104(M2C_FIELD(arg0, u8 *, 0x5A), M2C_FIELD(p, s32 *, 0x1C) + (M2C_FIELD(arg0, u16 *, 0x3E) << 5));
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = old;
    func_0209e320(arg0);
}

void func_0209e25c(void *arg0, s8 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
    M2C_FIELD(arg0, s16 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s16 *, 0x5E) = arg3;
}

void func_0209e26c(void *arg0, s8 arg1) {
    M2C_UNK func_020991f4(s32, s8);
    M2C_UNK func_02099204(s32);
    M2C_UNK func_0209e320(void *);
    s32 temp_r0;
    s32 var_r5;

    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
    var_r5 = 0;
    do {
        temp_r0 = func_0209e2c0(arg0, var_r5);
        func_020991f4(temp_r0, arg1);
        func_02099204(temp_r0);
        var_r5 += 1;
    } while (var_r5 < 2);
    func_0209e320(arg0);
}

void func_0209e2b8(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x58) = arg1;
}

s32 func_0209e2c0(void *arg0, s32 arg1) {
    s32 var_r1;

    var_r1 = arg1;
    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r1 = 1 - var_r1;
    }
    return M2C_FIELD((arg0 + (var_r1 * 4)), s32 *, 0x68);
}

void *func_0209e2d8(M2C_UNK arg0) {
    s32 func_02099320();
    s32 var_r5;
    void *temp_r4;

    var_r5 = 0;
loop_1:
    temp_r4 = func_0209e2c0(arg0, var_r5);
    if ((func_02099320() != 0) && (M2C_FIELD(temp_r4, u8 *, 0x5C) != 0)) {
        return temp_r4;
    }
    var_r5 += 1;
    if (var_r5 >= 2) {
        return NULL;
    }
    goto loop_1;
}

M2C_UNK func_0209e5d0(void *arg0) {
    void *func_020993d4(void *);
    void func_02099310(void *, s32);
    void func_02099318(void *, s32);
    s32 i;
    i = 0;
    M2C_FIELD(arg0, u8 *, 0x5A) = 0;
    M2C_FIELD(arg0, u8 *, 0x5B) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = 0;
    M2C_FIELD(arg0, u16 *, 0x5E) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, u8 *, 0x59) = 1;
    M2C_FIELD(arg0, u8 *, 0x58) = 0;
    do {
        void *p = func_020993d4(arg0);
        ((void **)(arg0 + 0x68))[i] = p;
        func_02099310(((void **)(arg0 + 0x68))[i], i);
        i++;
    } while (i < 2);
    func_02099318(M2C_FIELD(arg0, void **, 0x68), 1);
    func_02099318(M2C_FIELD(arg0, void **, 0x6C), 0);
}

M2C_UNK func_0209e640(void *a){u8 v=M2C_FIELD(a,u32 *,0x40)>>26;if(v==16)return v;return func_02082770(v);}

void func_0209e980(void) {
    M2C_UNK func_0209e5d0();
    func_0209e5d0();
}

void func_0209e98c(void) {
    M2C_UNK func_0209e640();
    func_0209e640();
}

void func_0209e998(void) {
    M2C_UNK func_0209e660();
    func_0209e660();
}

void **func_0209e9a4(s32 arg0) {
    void **func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_0211f810, data_0211f804;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = func_01ffa3dc(&data_0211f810, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_0211f804;
    }
    return result;
}

void func_0209e9dc(M2C_UNK arg0) {
    M2C_UNK func_01ffa860(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211f810;
    func_01ffa860(&data_0211f810, arg0);
}

void func_0209e9f4(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_0211f810;
    func_01ffa9e4(&data_0211f810);
}

void func_0209ea08(void) {

}

s32 func_0209ea0c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

#pragma scheduling off
void func_0209ea20(s32 arg0, s32 arg1, s32 arg2) {
void *func_020a4770(); void **func_01ffa3dc(M2C_UNK *,s32);
extern void **data_027e0058; extern M2C_UNK data_02156e50; extern M2C_UNK data_0211f87c;
void **base; s32 tick; void *t,*q,*p; s32 v,b,a;
p=func_020a4770();
if(!p){func_0209eaf4(arg0,arg1,arg2);return;}
tick=func_0207c2e0(); base=data_027e0058; M2C_FIELD(&data_02156e50,s32 *,8)=tick;
t=*base;
func_020d1690(M2C_FIELD(t,u8 *,0x52d4),(u32)(M2C_FIELD(p,u16 *,2)<<22)>>28,t+0x52dc);
a=M2C_FIELD(p,u8 *,4);b=M2C_FIELD(*data_027e0058,s16 *,0x6ed4);
if(a<b)M2C_FIELD(p,u8 *,4)=0; else M2C_FIELD(p,u8 *,4)=a-b;
q=func_01ffa3dc(&data_0211f87c,7);
M2C_FIELD(q,s32 *,0x5c)=M2C_FIELD(*data_027e0058,s32 *,0x52d0);
M2C_FIELD(q,s32 *,0x60)=arg2;
M2C_FIELD(q,void **,0x34)=p;
M2C_FIELD(q,s32 *,0x38)=arg0;
M2C_FIELD(q,s32 *,0x3c)=arg1;
}
#pragma scheduling reset
