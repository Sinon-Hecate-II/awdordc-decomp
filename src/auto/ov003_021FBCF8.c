/* 8 functions from 0x021FBCF8 to 0x021FCB70 (ov003), found by ds-decomp. */
#include "common.h"
typedef struct PanelFlagByte { unsigned char low:3; unsigned char mode:3; unsigned char pending:1; unsigned char high:1; } PanelFlagByte;
static inline void PanelDispatch(void *p, int slot) { ((void (**)(void *))*(void **)p)[slot](p); }

static inline u8 PanelModeIs(void *p, u32 mode) {
    return ((u32)(M2C_FIELD(p,u8 *,0x3b)<<28)>>28)==mode;
}

static inline s32 PanelCategory(u32 kind) {
    switch(kind) {
    case 28: return 7;
    case 6: return 1;
    case 22: case 23: return 3;
    case 12: return 5;
    case 5: case 7: return 0;
    case 24: return 2;
    case 8: return 6;
    case 14: return 9;
    case 15: return 10;
    case 16: return 11;
    case 17: return 12;
    default: return 4;
    }
}

void func_ov003_021fbcf8(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020ab664(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    s16 temp_r4;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x4C);
    temp_r4 = (s16) M2C_FIELD(temp_r0, s32 *, 0x14);
    func_020ab664(temp_r0, arg1, arg2, 1);
    if (temp_r4 == (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14)) {
        return;
    }
    func_ov003_021f92f4(arg0, 0);
    func_0208fe30(0x10019);
}

void func_ov003_021fbd48(void *arg0, s32 arg1) {
    s32 func_020a8ff4(void *);
    u32 func_020d886c();
    s32 func_ov003_021f3fe4(s32, M2C_UNK, s16);
    M2C_UNK func_ov003_021f9b30(void *);
    s16 temp_r1_3;
    s16 temp_r2;
    s16 temp_r3;
    s16 var_r5;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r1_3;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s8 var_r6;
    u32 temp_r0;
    u32 temp_r0_2;
    u8 temp_r4;
    u8 temp_r4_2;
    void *temp_r0_3;
    void *temp_r4_3;

    temp_r4 = (u8) (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14);
    temp_r0 = func_020d886c();
    switch (temp_r0) {                              /* switch 1 */
    default:                                        /* switch 1 */
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
    case 3:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 11:                                        /* switch 1 */
    case 13:                                        /* switch 1 */
    case 18:                                        /* switch 1 */
    case 19:                                        /* switch 1 */
    case 20:                                        /* switch 1 */
    case 21:                                        /* switch 1 */
    case 25:                                        /* switch 1 */
    case 26:                                        /* switch 1 */
    case 27:                                        /* switch 1 */
        var_r2 = 4;
        break;
    case 28:                                        /* switch 1 */
        var_r2 = 7;
        break;
    case 6:                                         /* switch 1 */
        var_r2 = 1;
        break;
    case 22:                                        /* switch 1 */
    case 23:                                        /* switch 1 */
        var_r2 = 3;
        break;
    case 12:                                        /* switch 1 */
        var_r2 = 5;
        break;
    case 5:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
        var_r2 = 0;
        break;
    case 24:                                        /* switch 1 */
        var_r2 = 2;
        break;
    case 8:                                         /* switch 1 */
        var_r2 = 6;
        break;
    case 14:                                        /* switch 1 */
        var_r2 = 9;
        break;
    case 15:                                        /* switch 1 */
        var_r2 = 0xA;
        break;
    case 16:                                        /* switch 1 */
        var_r2 = 0xB;
        break;
    case 17:                                        /* switch 1 */
        var_r2 = 0xC;
        break;
    }
    M2C_FIELD(((var_r2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xA9) = temp_r4;
    temp_r4_2 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 0xC);
    temp_r0_2 = func_020d886c();
    switch (temp_r0_2) {                            /* switch 2 */
    default:                                        /* switch 2 */
    case 0:                                         /* switch 2 */
    case 1:                                         /* switch 2 */
    case 2:                                         /* switch 2 */
    case 3:                                         /* switch 2 */
    case 4:                                         /* switch 2 */
    case 9:                                         /* switch 2 */
    case 10:                                        /* switch 2 */
    case 11:                                        /* switch 2 */
    case 13:                                        /* switch 2 */
    case 18:                                        /* switch 2 */
    case 19:                                        /* switch 2 */
    case 20:                                        /* switch 2 */
    case 21:                                        /* switch 2 */
    case 25:                                        /* switch 2 */
    case 26:                                        /* switch 2 */
    case 27:                                        /* switch 2 */
        var_r2_2 = 4;
        break;
    case 28:                                        /* switch 2 */
        var_r2_2 = 7;
        break;
    case 6:                                         /* switch 2 */
        var_r2_2 = 1;
        break;
    case 22:                                        /* switch 2 */
    case 23:                                        /* switch 2 */
        var_r2_2 = 3;
        break;
    case 12:                                        /* switch 2 */
        var_r2_2 = 5;
        break;
    case 5:                                         /* switch 2 */
    case 7:                                         /* switch 2 */
        var_r2_2 = 0;
        break;
    case 24:                                        /* switch 2 */
        var_r2_2 = 2;
        break;
    case 8:                                         /* switch 2 */
        var_r2_2 = 6;
        break;
    case 14:                                        /* switch 2 */
        var_r2_2 = 9;
        break;
    case 15:                                        /* switch 2 */
        var_r2_2 = 0xA;
        break;
    case 16:                                        /* switch 2 */
        var_r2_2 = 0xB;
        break;
    case 17:                                        /* switch 2 */
        var_r2_2 = 0xC;
        break;
    }
    M2C_FIELD(((var_r2_2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48) + (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)), u8 *, 0xD) = temp_r4_2;
    temp_r0_3 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_FIELD(temp_r0_3, s32 *, 4) = (s32) (M2C_FIELD(temp_r0_3, s32 *, 4) + arg1);
    if (M2C_FIELD(temp_r0_3, u8 *, 0x14) != 0) {
        var_r1 = M2C_FIELD(temp_r0_3, s32 *, 4);
        if (var_r1 > (s32) M2C_FIELD(temp_r0_3, s32 *, 8)) {
            do {
                var_r1 = M2C_FIELD(temp_r0_3, s32 *, 4) - ((M2C_FIELD(temp_r0_3, s32 *, 8) - M2C_FIELD(temp_r0_3, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_3, s32 *, 4) = var_r1;
            } while (var_r1 > (s32) M2C_FIELD(temp_r0_3, s32 *, 8));
        }
        if (var_r1 < (s32) M2C_FIELD(temp_r0_3, s32 *, 0xC)) {
            do {
                temp_r1 = M2C_FIELD(temp_r0_3, s32 *, 4) + ((M2C_FIELD(temp_r0_3, s32 *, 8) - M2C_FIELD(temp_r0_3, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_3, s32 *, 4) = temp_r1;
            } while (temp_r1 < (s32) M2C_FIELD(temp_r0_3, s32 *, 0xC));
        }
    } else {
        temp_r1_2 = M2C_FIELD(temp_r0_3, s32 *, 4);
        var_r2_3 = M2C_FIELD(temp_r0_3, s32 *, 8);
        if (temp_r1_2 <= var_r2_3) {
            var_r2_3 = M2C_FIELD(temp_r0_3, s32 *, 0xC);
            if (temp_r1_2 >= var_r2_3) {
                var_r2_3 = temp_r1_2;
            }
        }
        M2C_FIELD(temp_r0_3, s32 *, 4) = var_r2_3;
    }
    func_ov003_021f9b30(arg0);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x60);
    M2C_FIELD(temp_r4_3, s32 *, 0xC) = (s32) (s16) (arg1 + (s16) M2C_FIELD(temp_r4_3, s32 *, 0xC));
    if (M2C_FIELD(temp_r4_3, u8 *, 0x1C) != 0) {
        var_r0 = M2C_FIELD(temp_r4_3, s32 *, 0xC);
        if (var_r0 > (s32) M2C_FIELD(temp_r4_3, s32 *, 0x10)) {
            do {
                var_r0 = M2C_FIELD(temp_r4_3, s32 *, 0xC) - ((M2C_FIELD(temp_r4_3, s32 *, 0x10) - M2C_FIELD(temp_r4_3, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r4_3, s32 *, 0xC) = var_r0;
            } while (var_r0 > (s32) M2C_FIELD(temp_r4_3, s32 *, 0x10));
        }
        if (var_r0 < (s32) M2C_FIELD(temp_r4_3, s32 *, 0x14)) {
            do {
                temp_r0_4 = M2C_FIELD(temp_r4_3, s32 *, 0xC) + ((M2C_FIELD(temp_r4_3, s32 *, 0x10) - M2C_FIELD(temp_r4_3, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r4_3, s32 *, 0xC) = temp_r0_4;
            } while (temp_r0_4 < (s32) M2C_FIELD(temp_r4_3, s32 *, 0x14));
        }
    } else {
        var_r1_2 = M2C_FIELD(temp_r4_3, s32 *, 0x10);
        temp_r0_5 = M2C_FIELD(temp_r4_3, s32 *, 0xC);
        if (temp_r0_5 <= var_r1_2) {
            var_r1_2 = M2C_FIELD(temp_r4_3, s32 *, 0x14);
            if (temp_r0_5 >= var_r1_2) {
                var_r1_2 = temp_r0_5;
            }
        }
        M2C_FIELD(temp_r4_3, s32 *, 0xC) = var_r1_2;
    }
    temp_r0_6 = func_ov003_021f3fe4(func_020a8ff4(temp_r4_3 + 0x20), 0, (s16) (((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4)));
    temp_r2 = M2C_FIELD(temp_r4_3, s16 *, 4);
    temp_r1_3 = M2C_FIELD(temp_r4_3, s32 *, 0xC) * temp_r2;
    if (temp_r0_6 <= (s32) temp_r1_3) {
        var_r0_2 = (temp_r1_3 - temp_r0_6) << 0x10;
        var_r1_3 = (temp_r0_6 + ((s16) ((s16) ((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r2) - temp_r1_3)) << 0x10;
    } else {
        var_r0_2 = (((s16) ((s16) ((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r2) - temp_r0_6) + temp_r1_3) << 0x10;
        var_r1_3 = (temp_r0_6 - temp_r1_3) << 0x10;
    }
    if ((s32) (var_r0_2 >> 0x10) <= (s32) (var_r1_3 >> 0x10)) {
        var_r6 = 0;
    } else {
        var_r6 = 1;
    }
    temp_r3 = M2C_FIELD(temp_r4_3, s16 *, 4);
    var_r5 = M2C_FIELD(temp_r4_3, s32 *, 0xC) * temp_r3;
    temp_r0_7 = func_ov003_021f3fe4(func_020a8ff4(temp_r4_3 + 0x20), 0, (s16) (((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r3));
    if (var_r6 == 0) {
        if (temp_r0_7 > (s32) var_r5) {
            var_r5 += (s16) (((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4));
        }
    } else if (temp_r0_7 < (s32) var_r5) {
        var_r5 -= (s16) (((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4));
    }
    M2C_FIELD(temp_r4_3, s16 *, 0x2E) = (s16) temp_r0_7;
    M2C_FIELD(temp_r4_3, s16 *, 0x30) = var_r5;
    M2C_FIELD(temp_r4_3, s16 *, 0x2C) = (s16) M2C_FIELD(temp_r4_3, s16 *, 0x2C);
    M2C_FIELD(temp_r4_3, u16 *, 0x22) = (u16) M2C_FIELD(temp_r4_3, u16 *, 0x24);
    func_0208fe30(0x10020);
}

#pragma opt_strength_reduction off
void func_ov003_021fc26c(void *arg0) {
 s32 func_ov003_021f2780(void *,void *);
 void func_ov003_021fc98c(void *,u32);
 M2C_UNK func_0208fe30(s32);
 u32 func_020d886c(void);
 M2C_UNK func_ov003_021f92f4(void *,s32);
 void func_ov003_021f1bd4(void);
 void func_020d8ccc(u16);
 void func_020d47d0(void);
 void func_ov003_021f2848(void *);
 s32 func_ov003_021f4038(void);
 void *func_020c7e6c(u16);
 void func_020c002c(void *);
 void func_ov003_021fc820(void *);
 void func_ov003_021fc95c(void *);
 u8 value;
 s32 category;
 u16 selected;
 void *sprite;
 s32 index;
 s32 row;
 if(PanelModeIs(arg0,4)) {
  if(!func_ov003_021f2780((u8 *)M2C_FIELD(arg0,void **,0x44)+4,(u8 *)M2C_FIELD(arg0,void **,0x44)+8) &&
     !func_ov003_021f2780((u8 *)M2C_FIELD(arg0,void **,0x44)+4,(u8 *)M2C_FIELD(arg0,void **,0x44)+0x12)) {
   func_0208fe30(0x1001d);
   func_ov003_021fc98c(arg0,6);
   return;
  }
 }
 value=(u8)(s16)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14);
 switch(func_020d886c()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 category=(s32)M2C_FIELD(arg0,void **,0x48)+category*12;
 M2C_FIELD(category+(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4),u8 *,0xa9)=value;
 value=(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,0xc);
 switch(func_020d886c()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 category=(s32)M2C_FIELD(arg0,void **,0x48)+category*12;
 M2C_FIELD(category+(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4),u8 *,0xd)=value;
 value=(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4);
 switch(func_020d886c()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 M2C_FIELD(M2C_FIELD(arg0,void **,0x48),u8 *,category)=value;
 func_ov003_021f92f4(arg0,1);
 if(PanelModeIs(arg0,0)||PanelModeIs(arg0,2)||PanelModeIs(arg0,3)||PanelModeIs(arg0,4)||PanelModeIs(arg0,6)||PanelModeIs(arg0,7)||PanelModeIs(arg0,8)) {
  index=(s16)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14);
  row=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4);
  row=(u32)M2C_FIELD(arg0,void **,0x44)+((u8)row<<9);
  selected=M2C_FIELD(row+(u16)index*2,u16 *,0x2e);
 } else selected=M2C_FIELD(arg0,u16 *,0x3c);
 sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,0);
 if(M2C_FIELD(sprite,s8 *,0x5a)>=0) {
  M2C_FIELD(sprite,u32 *,0x40)=(M2C_FIELD(sprite,u32 *,0x40)&~0x03fc0000)|((u32)(u16)(((u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28)+1)<<24>>6);
  M2C_FIELD(sprite,s8 *,0x5a)=12;
 }
 func_ov003_021f1bd4();
 func_ov003_021fc95c(arg0);
 func_020d8ccc(selected);
 func_020d47d0();
 if(PanelModeIs(arg0,4)||PanelModeIs(arg0,2)) func_0208fe30(0x1000e);
 else func_0208fe30(0x1000d);
 if(PanelModeIs(arg0,4)) func_ov003_021f2848((u8 *)M2C_FIELD(arg0,void **,0x44)+4);
 else if(func_ov003_021f4038()) func_ov003_021fc820(arg0);
 if(PanelModeIs(arg0,0) && selected>=0xe1 && selected<0x1a9) {
  if((u32)(M2C_FIELD(func_020c7e6c(selected),u32 *,0x38)<<31)>>31)
   func_020c002c((u8 *)func_020c7e6c(selected)+0x30);
 }
}
#pragma opt_strength_reduction reset
void func_ov003_021fc820(void *arg0) {
    s32 func_02084d3c(s32 *, M2C_UNK);
    M2C_UNK func_02084d88(s32 *, M2C_UNK);
    M2C_UNK func_02084e74();
    s32 buffer[9];

    if (func_02084d3c(buffer, 0x24) == 0) {
        return;
    }
    buffer[0] = 1;
    func_02084d88(buffer, 0x24);
    func_02084e74();
}

void func_ov003_021fc860(void *arg0) {
M2C_UNK func_ov003_021f1be8(M2C_UNK);
void func_ov003_021fc95c(void *);
s32 func_02084644(void);
s32 func_020846a4(void);
M2C_UNK func_0208fe30(s32);
void func_020d47f0(void);

void *p;
s8 sb;
u8 ub;
u32 x;
s32 a;
s32 b;
s32 c;
s32 special;
s32 result;

p = M2C_FIELD(arg0, void **, 0x68);
p = M2C_FIELD(p, void **, 0xC);
sb = M2C_FIELD(p, s8 *, 0x5A);
if (sb >= 0) {
ub = M2C_FIELD(p, u8 *, 0x59);
M2C_FIELD(p, s32 *, 0x40) = (s32) ((M2C_FIELD(p, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (ub << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
M2C_FIELD(p, u8 *, 0x5A) = 0xC;
func_ov003_021f1be8(p);
func_ov003_021fc95c(arg0);
}

x = (u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C;
result = 1;
special = 1;
if ((s32) x == 6) {
a = 1;
} else {
a = 0;
}
if (!(a & 0xFF)) {
if ((s32) x == 7) {
b = 1;
} else {
b = 0;
}
if (!(b & 0xFF)) {
special = 0;
}
}
if (special == 0) {
if ((s32) x == 8) {
c = 1;
} else {
c = 0;
}
if (!(c & 0xFF)) {
result = 0;
}
}

if (result == 0) {
if ((s32) x == 4) {
result = (func_02084644() == 2) ? 1 : 0;
} else {
result = 0;
}
}

if (result != 0) {
if (func_020846a4() != 0) {
return;
}
}
func_0208fe30(0x1000F);
func_020d47f0();
}

void func_ov003_021fc95c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    func_02088da8(*M2C_FIELD(arg0, s32 **, 0x6C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021fc98c(void *arg0, u32 arg1) {
void *func_0208b564(void *);
void func_020899cc(void *, s32, s32, u32);
u8 byte;
u32 r1tmp;
u32 low;
u32 merged;
u32 temp;
void *r0;
byte = M2C_FIELD(arg0, u8 *, 0x3E);
r1tmp = arg1 & 0xFFu;
low = r1tmp << 0x1Du;
merged = byte | 0x40u;
temp = merged & ~0x38u;
M2C_FIELD(arg0, u8 *, 0x3E) = (u8)(temp | (low >> 0x1Au));
switch (arg1) {
case 0:
case 1:
case 2:
    return;
case 3:
    r0 = func_0208b564(arg0);
    func_020899cc(r0, 3, 0xDC00, 0x4200001D);
    M2C_FIELD(r0, s32 *, 0x58) = M2C_FIELD(r0, s32 *, 0x58) | 0x400;
    return;
case 4:
    r0 = func_0208b564(arg0);
    func_020899cc(r0, 2, 0xDC00, 0x4700001E);
    M2C_FIELD(r0, s32 *, 0x58) = M2C_FIELD(r0, s32 *, 0x58) | 0x400;
    return;
case 5:
    r0 = func_0208b564(arg0);
    func_020899cc(r0, 2, 0xDC00, 0x47000020);
    M2C_FIELD(r0, s32 *, 0x58) = M2C_FIELD(r0, s32 *, 0x58) | 0x400;
    return;
case 6:
    r0 = func_0208b564(arg0);
    func_020899cc(r0, 2, 0xDC00, 0x47000021);
    M2C_FIELD(r0, s32 *, 0x58) = M2C_FIELD(r0, s32 *, 0x58) | 0x400;
    return;
default:
    return;
}
}

#pragma scheduling off
void func_ov003_021fca84(void *arg0) {
 s32 func_020d4810(); M2C_UNK func_01ff9ce8(M2C_UNK); M2C_UNK func_02007f8c(s32,M2C_UNK,M2C_UNK); M2C_UNK func_020c8e40(); extern void *gCur3DSpriteEngine;
 PanelFlagByte *flags=(PanelFlagByte *)((u8 *)arg0+0x3e);
 if(!flags->pending)return;
 flags->pending=0;
 switch(flags->mode){
 case 0: if(!func_020d4810())return; func_01ff9ce8(0); M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1; func_02007f8c(M2C_FIELD(arg0,s32 *,0x44)+0x186c,0,13); func_020c8e40(); func_ov003_021f92f4(arg0,0); return;
 case 1: case 2: if(!func_020d4810())return; ((void(*)(void*))M2C_FIELD(M2C_FIELD(arg0,void **,0),void **,0x1c))(arg0); return;
 case 3: if(!func_020d4810())return; ((void(*)(void*))M2C_FIELD(M2C_FIELD(arg0,void **,0),void **,0x20))(arg0); return;
 case 4: case 5: case 6: default: return;
 }
}
#pragma scheduling reset
