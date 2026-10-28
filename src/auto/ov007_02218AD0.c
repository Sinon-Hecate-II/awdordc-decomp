/* 21 functions from 0x02218AD0 to 0x02219ACC (ov007), found by ds-decomp. */
#include "common.h"

static inline s32 ov007_item_id(void *p) {
    void *q = M2C_FIELD(p, void **, 0);
    return q ? M2C_FIELD(q, u16 *, 8) : -1;
}


void func_ov007_02218ad0(void *arg0) {
    M2C_UNK func_01ff8ddc(M2C_UNK, s16, s16, s16, s32);
    s32 func_0207c8ec(s32, u16);
    extern M2C_UNK data_020e5b30;
    s32 sp8;
    s32 sp4;
    s16 temp_r4;
    s32 temp_r0;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r4_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r7_3;
    s32 temp_r8;
    s32 temp_r8_2;
    u16 var_r1;
    u16 var_r1_2;
    u16 var_r7;
    u16 var_r7_2;
    u16 var_r8;
    u16 var_r8_2;
    u16 var_r8_3;
    u16 var_r9;
    u16 var_r9_2;
    u16 var_r9_3;

    var_r1 = M2C_FIELD(arg0, u16 *, 0x3C);
    if ((s32) var_r1 >= 2) {
        var_r7 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r7 = 2;
    } else {
        var_r7 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r7 = var_r1;
        }
    }
    temp_r4 = M2C_FIELD(&data_020e5b30, s16 *, 2);
    if ((s32) var_r1 >= 2) {
        var_r8 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r8 = 2;
    } else {
        var_r8 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r8 = var_r1;
        }
    }
    if ((s32) var_r1 >= 2) {
        var_r9 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r9 = 2;
    } else {
        var_r9 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r9 = var_r1;
        }
    }
    if ((s32) var_r1 < 2) {
        if ((u32) var_r1 > 2U) {
            var_r1 = 2;
        } else if ((s32) var_r1 < -2) {
            var_r1 = -2U;
        }
    }
    temp_r11 = temp_r4 * 0x10;
    temp_r6 = (0 - M2C_FIELD(&data_020e5b30, s16 *, 0)) * 0x10;
    temp_r5 = M2C_FIELD(&data_020e5b30, s16 *, 0) * 0x10;
    sp8 = func_0207c8ec(temp_r11, var_r1);
    temp_r8 = func_0207c8ec(temp_r6, var_r9);
    temp_r7 = func_0207c8ec(temp_r5, var_r8);
    func_01ff8ddc(0, (s16) sp8, (s16) temp_r8, (s16) temp_r7, (s32) (s16) func_0207c8ec(temp_r11, var_r7));
    var_r1_2 = M2C_FIELD(arg0, u16 *, 0x3E);
    if ((s32) var_r1_2 >= 2) {
        var_r7_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r7_2 = 2;
    } else {
        var_r7_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r7_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 >= 2) {
        var_r8_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r8_2 = 2;
    } else {
        var_r8_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r8_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 >= 2) {
        var_r9_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r9_2 = 2;
    } else {
        var_r9_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r9_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 < 2) {
        if ((u32) var_r1_2 > 2U) {
            var_r1_2 = 2;
        } else if ((s32) var_r1_2 < -2) {
            var_r1_2 = -2U;
        }
    }
    temp_r0 = temp_r4 * 0x10;
    sp4 = temp_r0;
    temp_r11_2 = func_0207c8ec(temp_r0, var_r1_2);
    temp_r8_2 = func_0207c8ec(temp_r6, var_r9_2);
    temp_r7_2 = func_0207c8ec(temp_r5, var_r8_2);
    func_01ff8ddc(1, (s16) temp_r11_2, (s16) temp_r8_2, (s16) temp_r7_2, (s32) (s16) func_0207c8ec(temp_r0, var_r7_2));
    var_r9_3 = M2C_FIELD(arg0, u16 *, 0x40);
    if ((s32) var_r9_3 >= 2) {
        var_r8_3 = var_r9_3;
    } else if ((u32) var_r9_3 > 2U) {
        var_r8_3 = 2;
    } else {
        var_r8_3 = -2U;
        if ((s32) var_r9_3 >= -2) {
            var_r8_3 = var_r9_3;
        }
    }
    if ((s32) var_r9_3 < 2) {
        if ((u32) var_r9_3 > 2U) {
            var_r9_3 = 2;
        } else if ((s32) var_r9_3 < -2) {
            var_r9_3 = -2U;
        }
    }
    temp_r7_3 = temp_r4 * 0x10;
    temp_r4_2 = func_0207c8ec(temp_r7_3, 0x100U);
    temp_r6_2 = func_0207c8ec(temp_r6, var_r9_3);
    temp_r5_2 = func_0207c8ec(temp_r5, 0x100U);
    func_01ff8ddc(2, (s16) temp_r4_2, (s16) temp_r6_2, (s16) temp_r5_2, (s32) (s16) func_0207c8ec(temp_r7_3, var_r8_3));
}

void func_ov007_02218d8c(void *arg0) {
    M2C_UNK func_01ffaacc(u16, s32, u16, M2C_UNK *, s32);
    s32 func_ov007_02217c50();
    extern M2C_UNK data_02101f5c;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_027e0064;
    void *sp4;
    s32 temp_r7;
    u32 var_r10;
    long var_r8;
    s32 var_r9;

    sp4 = arg0;
    temp_r7 = func_ov007_02217c50();
    if (M2C_FIELD(sp4, u16 *, 0x3C) > 0x10U) {
        var_r8 = 0;
        if (temp_r7 > 0) {
            var_r9 = 0x39C;
            var_r10 = 8;
            do {
                func_01ffaacc((u16) (var_r10 & 0x1FF), 0x58C, (u16) (0x3FF & (var_r9 >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))), &data_027e0064, 0xF);
                var_r8 += 1;
                var_r9 += 4;
                var_r10 += 0x18;
            } while (temp_r7 > var_r8);
        }
    }
    if (M2C_FIELD(sp4, u16 *, 0x40) <= 0x10U) {
        return;
    }
    func_01ffaacc(0x480U, 0x58C, (u16) (0x3FF & (0x3B0 >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))), &data_02101f5c, 0xF);
}

M2C_UNK func_ov007_02218e98(void *arg0) {
    M2C_UNK func_ov007_02217b64(s32);
    void func_ov007_02218ad0(void *);
    void func_ov007_02218d8c(void *);
    M2C_UNK func_01ffaacc(u16, s32, u16, M2C_UNK *, s32);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    extern M2C_UNK data_027e0074;
    extern M2C_UNK data_027e005c;
    extern M2C_UNK data_027e0064;
    u16 **saved;
    s32 r7;
    u8 player;
    u8 selected;
    s8 *base;
    u16 *p;
    u8 idxByte;
    s8 *selRec;
    u16 *sp50;
    s8 *rec;
    u8 a;
    u8 b;
    s8 s0;
    u8 idx;
    u16 dist;
    u8 p3;
    u16 x;
    u16 y;
    u16 bits;
    u16 third;
    u16 val2;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    r7 = 0x3dc;
    player = M2C_FIELD(arg0, u8 *, 0x37);
    selected = M2C_FIELD((u8 *)arg0 + player, u8 *, 0x3a);
    base = (s8 *)func_ov007_02217b64(player);

    func_ov007_02218ad0(arg0);
    func_ov007_02218d8c(arg0);

    p = M2C_FIELD(arg0, u16 **, 0x54);
    idxByte = M2C_FIELD((u8 *)arg0 + player, u8 *, 0x38);
    M2C_FIELD(p, u16 *, 0x34) = (u16)(idxByte * 0x18 + 0x8);
    M2C_FIELD(p, u16 *, 0x36) = 0x8c;

    switch (M2C_FIELD(arg0, u8 *, 0x37)) {
    case 0:
        selRec = base + selected * 5;
        sp50 = M2C_FIELD(arg0, u16 **, 0x50);
        M2C_FIELD(sp50, u16 *, 0x34) = (u16)(selRec[1] * 0x24 + 0xa);
        M2C_FIELD(sp50, u16 *, 0x36) = (u16)(selRec[2] * 0x20 + 0x8);
        rec = base;
        if (rec[0] >= 0) {
            do {
                a = (u8)rec[1];
                b = (u8)rec[2];
                s0 = rec[0];
                idx = (u8)rec[4];
                if (s0 == 0x0f) {
                    idxByte = M2C_FIELD((u8 *)arg0 + player, u8 *, 0x38);
                    if (idxByte == 4) {
                        r7 += 0x18;
                        rec += 5;
                        continue;
                    }
                }
                dist = M2C_FIELD((u8 *)arg0 + idx * 2, u16 *, 0x3c);
                if (dist > 0x10) {
                    p3 = (u8)rec[3];
                    x = (u16)(((a * 0x24 + 0x2) + 0x8) & 0x1ff);
                    x |= (u16)(idx << 9);
                    y = (u16)(((b * 0x20 + 0x8) - 0x10) & 0xff);
                    y |= 0x500;
                    bits = (u16)(((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1e));
                    third = (u16)((0x3ff & (r7 >> bits)) | ((p3 + 0x6) << 12));
                    func_01ffaacc(x, y, third, &data_027e0074, 0xf);
                }
                val2 = M2C_FIELD(arg0, u16 *, 0x3c);
                if (val2 > 0x10) {
                    x = (u16)((a * 0x24 + 0x2) & 0x1ff);
                    y = (u16)(((b * 0x20 + 0x8) + 0x10) & 0xff);
                    y |= 0x500;
                    bits = (u16)(((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1e));
                    third = (u16)((0x3ff & ((r7 + 0x8) >> bits)) | 0x2000);
                    func_01ffaacc(x, y, third, &data_027e005c, 0xf);
                }
                r7 += 0x18;
                rec += 5;
            } while (rec[0] >= 0);
        }
        break;
    case 1:
        selRec = base + selected * 5;
        sp50 = M2C_FIELD(arg0, u16 **, 0x50);
        M2C_FIELD(sp50, u16 *, 0x34) = (u16)(selRec[1] * 0x24 + 0xa);
        M2C_FIELD(sp50, u16 *, 0x36) = (u16)(selRec[2] * 0x20 + 0x8);
        rec = base;
        if (rec[0] >= 0) {
            do {
                a = (u8)rec[1];
                b = (u8)rec[2];
                s0 = rec[0];
                idx = (u8)rec[4];
                dist = M2C_FIELD((u8 *)arg0 + idx * 2, u16 *, 0x3c);
                if (dist > 0x10) {
                    x = (u16)(((a * 0x24 + 0x2) + 0x8) & 0x1ff);
                    x |= (u16)(idx << 9);
                    y = (u16)((b * 0x20 + 0x8) & 0xff);
                    y |= 0x500;
                    bits = (u16)(((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1e));
                    third = (u16)((0x3ff & (r7 >> bits)) | 0x6000);
                    func_01ffaacc(x, y, third, &data_027e0064, 0xf);
                }
                val2 = M2C_FIELD(arg0, u16 *, 0x3c);
                if (val2 > 0x10) {
                    x = (u16)((a * 0x24 + 0x2) & 0x1ff);
                    y = (u16)(((b * 0x20 + 0x8) + 0x10) & 0xff);
                    y |= 0x500;
                    bits = (u16)(((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1e));
                    third = (u16)((0x3ff & ((r7 + 0x4) >> bits)) | 0x2000);
                    func_01ffaacc(x, y, third, &data_027e005c, 0xf);
                }
                r7 += 0xc;
                rec += 5;
            } while (rec[0] >= 0);
        }
        break;
    default:
        break;
    }

    gCur3DSpriteEngine = saved;
}

M2C_UNK func_ov007_02219230(void *arg) {
void func_ov007_02217cd0(void *); s32 func_ov007_02217c80(void *); s32 func_ov007_02217ca8(void *); void func_ov007_02219bb4(void *,s32); void func_01ffa8c4(void *,s32); s32 func_ov007_02217d30(void *); M2C_UNK func_0208fe30(s32); void func_02088044(void *);
extern u16 *data_02101e84;
u32 keys; void *p; void *q; s32 v;
keys=*data_02101e84;
if(keys&1) {func_ov007_02217cd0(arg);return;}
if(keys&0x400) {func_ov007_02219bb4(arg,func_ov007_02217c80(arg));return;}
if(keys&0x800) {func_ov007_02219bb4(arg,func_ov007_02217ca8(arg));return;}
if(keys&0x304) {func_01ffa8c4(arg,1);return;}
if(keys&2) {func_01ffa8c4(arg,2);return;}
if(func_ov007_02217d30(arg)) {func_0208fe30(0x10019);return;}
func_02088044(M2C_FIELD(arg,void **,0x58));
p=M2C_FIELD(arg,void **,0x58);
if((u8)(M2C_FIELD(p,s8 *,9)>=0)) {
v=ov007_item_id(p);
func_0208fe30(0x10019);
M2C_FIELD((u8 *)arg+M2C_FIELD(arg,u8 *,0x37),u8 *,0x3a)=v;
}
if((u8)(M2C_FIELD(M2C_FIELD(arg,void **,0x58),s8 *,11)>=0)) {func_ov007_02217cd0(arg);return;}
func_02088044(M2C_FIELD(arg,void **,0x5c));
p=M2C_FIELD(arg,void **,0x5c);
if(!(u8)(M2C_FIELD(p,s8 *,9)>=0)) return;
{
v=ov007_item_id(p);
if(v!=M2C_FIELD((u8 *)arg+M2C_FIELD(arg,u8 *,0x37),u8 *,0x38)) func_ov007_02219bb4(arg,v);
}
}

void func_ov007_02219398(void) {
    M2C_UNK func_ov007_02217f8c();
    func_ov007_02217f8c();
}

void func_ov007_022193a4(void) {
    M2C_UNK func_ov007_02218570();
    func_ov007_02218570();
}

void func_ov007_022193b0(void) {
    M2C_UNK func_ov007_02218e98();
    func_ov007_02218e98();
}

void func_ov007_022193bc(void) {
    M2C_UNK func_ov007_0221863c();
    func_ov007_0221863c();
}

void func_ov007_022193c8(void) {
    M2C_UNK func_ov007_02218a60();
    func_ov007_02218a60();
}

void func_ov007_022193d4(void) {
    M2C_UNK func_ov007_02219230();
    func_ov007_02219230();
}

void func_ov007_022193e0(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x37);
    switch (temp_r1) {                              /* irregular */
    case 1:
        M2C_FIELD(arg0, u8 *, 0x37) = 0U;
        break;
    case 0:
        M2C_FIELD(arg0, u8 *, 0x37) = 1U;
        break;
    }
    func_0208fe30(0x10020);
}

void func_ov007_02219418(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221ff90;
    func_01ffa3dc(&data_ov007_0221ff90, 7);
}

M2C_UNK func_ov007_02219430(void) {
    M2C_UNK func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov007_0221ff90;
    return func_01ffa770(&data_ov007_0221ff90);
}

void func_ov007_02219444(void *arg0) {
M2C_UNK func_ov007_02219430(void); void func_02088eec(void *,s32); void func_02088da8(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp0; u16 **old; void *r4;
r4=(void *)func_ov007_02219430();
if(M2C_FIELD(r4,u8 *,0x34)!=0) {
old=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
sp0=(u16 *)((u8 *)*data_027e00c8+0x12);
*sp0=(*sp0 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=0x10;
gCur3DSpriteEngine=old;
func_02088eec(M2C_FIELD(r4,void **,0x44),8);
func_02088eec(M2C_FIELD(r4,void **,0x48),8);
func_02088eec(M2C_FIELD(r4,void **,0x4c),8);
}
func_02088da8(M2C_FIELD(r4,void **,0x50));
func_02088da8(M2C_FIELD(r4,void **,0x54));
M2C_FIELD(arg0,u16 *,0x54)=0;
}

void func_ov007_0221950c(void *arg) {
s32 func_0207ca38(s32,s32,s32,s32,s32); void func_01ffa574(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp4; u16 **old; void *r4; s32 v;
r4=(void *)func_ov007_02219430();
M2C_FIELD(arg,s16 *,0x54)++;
M2C_FIELD(r4,u16 *,0x3c)=func_0207ca38(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
M2C_FIELD(r4,u16 *,0x3e)=func_0207ca38(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
if(M2C_FIELD(r4,u8 *,0x34)) {
M2C_FIELD(r4,u16 *,0x40)=func_0207ca38(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
v=func_0207ca38(0,16,4,M2C_FIELD(arg,s16 *,0x54),8);
old=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
sp4=*data_027e00c8+9; *sp4=(*sp4 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=v;
gCur3DSpriteEngine=old;
}
if(M2C_FIELD(arg,s16 *,0x54)>=8) func_01ffa574(arg);
}

void func_ov007_02219634(void) {
    M2C_UNK func_ov007_02219430(void);
    void func_02088d94(void *);
    void func_02089438(void *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    u16 * volatile sp8;
    u16 * volatile sp4;
    u16 * volatile sp0;
    u16 **old;
    void *r4;

    r4 = (void *)func_ov007_02219430();
    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    sp8 = *data_027e00c8;
    *sp8 = (*sp8 & ~0x200);
    sp4 = *gCur3DSpriteEngine;
    *sp4 = (*sp4 & ~0x400);
    sp0 = *gCur3DSpriteEngine;
    *sp0 = (*sp0 & ~0x800);
    func_02088d94(M2C_FIELD(r4, void **, 0x50));
    func_02088d94(M2C_FIELD(r4, void **, 0x54));
    func_02089438(M2C_FIELD(r4, void **, 0x50));
    func_02089438(M2C_FIELD(r4, void **, 0x54));
    M2C_FIELD(r4, u8 *, 0x34) = 0;
    gCur3DSpriteEngine = old;
}

void func_ov007_022196f4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fdf8;
    func_01ffa42c(&data_ov007_0221fdf8, arg0);
}

void func_ov007_0221970c(void *arg) {
M2C_UNK func_ov007_02219430(void);
void func_02088fc4(void *, int); void func_02088da8(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp0; u16 **old; void *r4;
r4=(void *)func_ov007_02219430();
if (M2C_FIELD(r4,u8 *,0x35)) {
old=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
sp0=*data_027e00c8+9; *sp0=(*sp0 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0; M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=4; gCur3DSpriteEngine=old;
func_02088fc4(M2C_FIELD(r4,void **,0x44),6);
func_02088fc4(M2C_FIELD(r4,void **,0x48),6);
func_02088fc4(M2C_FIELD(r4,void **,0x4c),6);
}
func_02088da8(M2C_FIELD(r4,void **,0x50));
func_02088da8(M2C_FIELD(r4,void **,0x54));
M2C_FIELD(arg,u16 *,0x54)=0;
}

void func_ov007_022197d4(void *arg) {
s32 func_0207ca38(s32,s32,s32,s32,s32); void func_01ffa574(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **data_027e00c8;
u16 * volatile sp4; u16 **old; void *r4; s32 v;
r4=(void *)func_ov007_02219430();
M2C_FIELD(arg,s16 *,0x54)++;
M2C_FIELD(r4,u16 *,0x3c)=func_0207ca38(4,256,0,M2C_FIELD(arg,s16 *,0x54),6);
M2C_FIELD(r4,u16 *,0x3e)=func_0207ca38(4,256,0,M2C_FIELD(arg,s16 *,0x54),6);
if(M2C_FIELD(r4,u8 *,0x35)) {
M2C_FIELD(r4,u16 *,0x40)=func_0207ca38(4,256,0,M2C_FIELD(arg,s16 *,0x54),6);
v=func_0207ca38(0,4,16,M2C_FIELD(arg,s16 *,0x54),6);
old=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c8;
sp4=*data_027e00c8+9; *sp4=(*sp4 & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=v;
gCur3DSpriteEngine=old;
}
if(M2C_FIELD(arg,s16 *,0x54)>=6) func_01ffa574(arg);
}

void func_ov007_022198fc(void) {
    M2C_UNK func_ov007_02219430(void);
    void func_01ff9ce8(s32);
    void func_02088d94(void *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c8;
    u16 * volatile sp18;
    u16 * volatile sp14;
    u16 * volatile sp10;
    u16 * volatile spC;
    u16 * volatile sp8;
    u16 * volatile sp4;
    u16 * volatile sp0;
    u16 **old;
    void *r5;

    r5 = (void *)func_ov007_02219430();
    if (M2C_FIELD(r5, u8 *, 0x35) != 0) {
        old = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        func_01ff9ce8(1);
        func_01ff9ce8(2);
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x46) | 2);
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x46) | 4);
        sp18 = (u16 *)((u8 *)M2C_FIELD(*gCur3DSpriteEngine, void **, 0) + 0x12);
        *sp18 = *sp18 & ~0xc0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x53) = 0;
        sp14 = (u16 *)M2C_FIELD(*gCur3DSpriteEngine, void **, 0);
        *sp14 = *sp14 & ~0x200;
        sp10 = (u16 *)M2C_FIELD(*gCur3DSpriteEngine, void **, 0);
        *sp10 = *sp10 & ~0x400;
        spC = (u16 *)M2C_FIELD(*gCur3DSpriteEngine, void **, 0);
        *spC = *spC & ~0x800;
        gCur3DSpriteEngine = old;
    } else {
        old = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        func_02088d94(M2C_FIELD(r5, void **, 0x50));
        func_02088d94(M2C_FIELD(r5, void **, 0x54));
        sp8 = *gCur3DSpriteEngine;
        *sp8 = *sp8 & ~0x200;
        sp4 = *gCur3DSpriteEngine;
        *sp4 = *sp4 & ~0x400;
        sp0 = *gCur3DSpriteEngine;
        *sp0 = *sp0 & ~0x800;
        gCur3DSpriteEngine = old;
    }
}

void func_ov007_02219ab4(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221fe20;
    func_01ffa42c(&data_ov007_0221fe20, arg0);
}

