/* 7 functions from 0x0221D008 to 0x0221E004 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221d008(u8 *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_02007ef4(s32 *, s8 *, M2C_UNK);
    M2C_UNK func_02019424(s32 *, M2C_UNK);
    s32 func_020194e0(s32 *, M2C_UNK *);
    s32 func_02099ae8(s32 *);
    s32 func_0209c268(s32 *);
    M2C_UNK func_01ffa8c4(s32, M2C_UNK);
    M2C_UNK func_020899cc(void *, M2C_UNK, M2C_UNK, s32);
    void *func_0208b564(s32);
    M2C_UNK func_020b269c();
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    extern s32 data_ov007_022205c0;
    extern s32 data_ov007_02220890;
    extern s32 data_ov007_02220960;
    extern s32 data_ov007_02220d28;
    extern s32 data_ov007_02221224[];
    extern s32 data_ov007_02221e0c;
    extern s32 data_ov007_02221e10;
    s32 scratch[17];
    s32 padding[17];
    void *ctx;
    s8 *phase;
    ctx = *(void **)(arg0 + 0x10);
    phase = (s8 *)ctx + 0x3c;
    switch (arg0[0]) {
    case 0x67: {
        s32 index;
        s32 i;
        if (*phase > 0) {
            index = (s8)(*phase - 1);
            if (index < 0 || index >= 17) goto shift_67;
            if (((s32 *)&data_ov007_02221e10)[index] == 0 &&
                (index <= 0 || ((s32 *)&data_ov007_02221e10)[index - 1] == 0)) goto shift_67;
            *phase = (s8)index;
        shift_67:
            i = *phase;
            while (i < 16) {
                ((s32 *)&data_ov007_02221e10)[i] = ((s32 *)&data_ov007_02221e10)[i + 1];
                i++;
            }
            M2C_FIELD(&data_ov007_02221e0c, s32 *, 0x44) = 0;
            func_0208fe30(0x1000d);
            return;
        }
        index = *phase;
        if (index != 0 || ((s32 *)&data_ov007_02221e10)[index] == 0) goto no_move_67;
        for (i = index; i < 16; i++) {
            ((s32 *)&data_ov007_02221e10)[i] = ((s32 *)&data_ov007_02221e10)[i + 1];
        }
        M2C_FIELD(&data_ov007_02221e0c, s32 *, 0x44) = 0;
        func_0208fe30(0x1000d);
        return;
    no_move_67:
        func_0208fe30(0x1001d);
        return;
    }
    case 0x68: {
        if ((s32)&data_ov007_02221224[0] == *(s32 *)((u8 *)ctx + 0x34)) {
            s32 *items = *(s32 **)((u8 *)ctx + 0x34);
            if (func_020194e0(&data_ov007_02220960, &data_ov007_02220890) == 0) {
                s32 phaseValue = *phase;
                s32 found = -1;
                s32 i;
                s32 *entry = 0;
                if (phaseValue != 0) {
                    entry = &((s32 *)&data_ov007_02221e10)[(s8)(phaseValue - 1)];
                    for (i = 0; i < 0x4b; i++) {
                        if (func_020194e0(entry, (M2C_UNK *)items[i]) == 0) {
                            found = i;
                            break;
                        }
                    }
                }
                if (found >= 0) {
                    s32 old = *phase;
                    s32 next = old;
                    if (next > 0) {
                        next = (s8)(next - 1);
                        if (next >= 0 && next < 17 && (((s32 *)&data_ov007_02221e10)[next] != 0 ||
                            (next > 0 && ((s32 *)&data_ov007_02221e10)[next - 1] != 0))) {
                            void *field12c;
                            *phase = (s8)next;
                            field12c = (void *)*(s32 *)((u8 *)items[found] + 0x12c);
                            if (func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase], (M2C_UNK *)field12c) == 0) {
                                if (old >= 0 && old < 17 && (((s32 *)&data_ov007_02221e10)[old] != 0 ||
                                    (old > 0 && ((s32 *)&data_ov007_02221e10)[old - 1] != 0))) {
                                    *phase = (s8)old;
                                    func_0208fe30(0x1001d);
                                }
                            } else if (func_020194e0((s32 *)field12c, &data_ov007_02220d28) == 0) {
                                found = -1;
                                if (*phase != 0) {
                                    entry = &((s32 *)&data_ov007_02221e10)[(s8)(*phase - 1)];
                                    for (i = 0; i < 0x4b; i++) {
                                        if (func_020194e0(entry, (M2C_UNK *)items[i]) == 0) {
                                            found = i;
                                            break;
                                        }
                                    }
                                }
                                if (found >= 0) {
                                    func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase],
                                        (M2C_UNK *)*(s32 *)((u8 *)items[found] + 0x12c));
                                }
                            }
                            if (func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase],
                                (M2C_UNK *)*(s32 *)((u8 *)items[found] + 0x258)) == 0) {
                                if (old >= 0 && old < 17 && (((s32 *)&data_ov007_02221e10)[old] != 0 ||
                                    (old > 0 && ((s32 *)&data_ov007_02221e10)[old - 1] != 0))) {
                                    *phase = (s8)old;
                                    func_0208fe30(0x1001d);
                                }
                            }
                        }
                    }
                }
                func_02007ef4(&data_ov007_02221e10, (s8 *)padding, 0x44);
            } else if (func_020194e0(&data_ov007_02220960, &data_ov007_02220d28) == 0) {
                s32 phaseValue = *phase;
                s32 found = -1;
                s32 i;
                if (phaseValue != 0) {
                    s32 *entry = &((s32 *)&data_ov007_02221e10)[(s8)(phaseValue - 1)];
                    for (i = 0; i < 0x4b; i++) {
                        if (func_020194e0(entry, (M2C_UNK *)items[i]) == 0) {
                            found = i;
                            break;
                        }
                    }
                }
                if (found >= 0) {
                    s32 old = *phase;
                    s32 next = old;
                    if (next > 0) {
                        next = (s8)(next - 1);
                        if (next >= 0 && next < 17 && (((s32 *)&data_ov007_02221e10)[next] != 0 ||
                            (next > 0 && ((s32 *)&data_ov007_02221e10)[next - 1] != 0))) {
                            *phase = (s8)next;
                            if (func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase],
                                (M2C_UNK *)*(s32 *)((u8 *)items[found] + 0x258)) == 0) {
                                if (old >= 0 && old < 17 && (((s32 *)&data_ov007_02221e10)[old] != 0 ||
                                    (old > 0 && ((s32 *)&data_ov007_02221e10)[old - 1] != 0))) {
                                    *phase = (s8)old;
                                    func_0208fe30(0x1001d);
                                }
                            }
                        }
                    }
                }
                func_02007ef4(&data_ov007_02221e10, (s8 *)scratch, 0x44);
            }
            func_02007ef4(&data_ov007_02221e10, (s8 *)padding, 0x44);
            padding[*phase] = 0;
            func_02019424(&padding[*phase], &data_ov007_022205c0);
            {
                s32 count = 0;
                s32 *node = padding;
                if (*node != 0) {
                    do {
                        if (func_02099ae8(node) == 0 && count != 0) count++;
                        count += func_0209c268(node);
                    } while (*++node != 0);
                }
                if (count > 0x40) {
                    s32 old = *phase;
                    if (old >= 0 && old < 17 && (((s32 *)&data_ov007_02221e10)[old] != 0 ||
                        (old > 0 && ((s32 *)&data_ov007_02221e10)[old - 1] != 0))) {
                        *phase = (s8)old;
                        func_020b269c();
                        {
                            s32 oldEngine = gCur3DSpriteEngine;
                            void *sprite;
                            gCur3DSpriteEngine = data_027e00c8;
                            sprite = func_0208b564((s32)ctx);
                            func_020899cc(sprite, 2, 0x2800, 0x46000012);
                            M2C_FIELD(sprite, s32 *, 0x58) = M2C_FIELD(sprite, s32 *, 0x58) | 0x1000;
                            gCur3DSpriteEngine = oldEngine;
                            func_01ffa8c4((s32)ctx, 5);
                            func_0208fe30(0x1001d);
                        }
                    }
                } else {
                    s32 old = *phase;
                    s32 next = (s8)(old + 1);
                    s32 *table = &data_ov007_02221e10;
                    if (next >= 0 && next < 17 && (table[next] != 0 || (next > 0 && table[next - 1] != 0))) {
                        *phase = (s8)next;
                        func_0208fe30(0x1000d);
                    }
                }
            }
            if (*phase == 16 || *phase == 17) {
                func_020b269c();
                {
                    s32 oldEngine = gCur3DSpriteEngine;
                    void *sprite;
                    gCur3DSpriteEngine = data_027e00c8;
                    sprite = func_0208b564((s32)ctx);
                    func_020899cc(sprite, 2, 0x2800, (*phase == 16) ? 0x46000012 : 0x46000013);
                    M2C_FIELD(sprite, s32 *, 0x58) = M2C_FIELD(sprite, s32 *, 0x58) | 0x1000;
                    gCur3DSpriteEngine = oldEngine;
                    func_01ffa8c4((s32)ctx, 5);
                    func_0208fe30(0x1001d);
                }
            }
        } else {
            s32 *items = *(s32 **)((u8 *)ctx + 0x34);
            s32 phaseValue = *phase;
            s32 found = -1;
            s32 i;
            if (func_020194e0(&data_ov007_02220960, &data_ov007_02220d28) == 0 && phaseValue != 0) {
                s32 *entry = &((s32 *)&data_ov007_02221e10)[(s8)(phaseValue - 1)];
                for (i = 0; i < 0x4b; i++) {
                    if (func_020194e0(entry, (M2C_UNK *)items[i]) == 0) {
                        found = i;
                        break;
                    }
                }
                if (found >= 0) {
                    s32 old = *phase;
                    s32 next = (s8)(old - 1);
                    if (next >= 0 && next < 17 && ((s32 *)&data_ov007_02221e10)[next] != 0) {
                        *phase = (s8)next;
                        if (func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase], (M2C_UNK *)*(s32 *)((u8 *)items[found] + 0x12c)) == 0) {
                            *phase = (s8)old;
                            func_0208fe30(0x1001d);
                        }
                        if (func_020194e0(&((s32 *)&data_ov007_02221e10)[*phase], (M2C_UNK *)*(s32 *)((u8 *)items[found] + 0x258)) == 0) {
                            *phase = (s8)old;
                            func_0208fe30(0x1001d);
                        }
                    }
                }
            }
            func_02007ef4(&data_ov007_02221e10, (s8 *)scratch, 0x44);
            scratch[*phase] = 0;
            func_02019424(&scratch[*phase], &data_ov007_022205c0);
            {
                s32 count = 0;
                s32 *node = scratch;
                if (*node != 0) {
                    do {
                        if (func_02099ae8(node) == 0 && count != 0) count++;
                        count += func_0209c268(node);
                    } while (*++node != 0);
                }
                if (count > 0x40) {
                    s32 old = *phase;
                    if (old >= 0 && old < 17 && (((s32 *)&data_ov007_02221e10)[old] != 0 ||
                        (old > 0 && ((s32 *)&data_ov007_02221e10)[old - 1] != 0))) {
                        *phase = (s8)old;
                        func_020b269c();
                        {
                            s32 oldEngine = gCur3DSpriteEngine;
                            void *sprite;
                            gCur3DSpriteEngine = data_027e00c8;
                            sprite = func_0208b564((s32)ctx);
                            func_020899cc(sprite, 2, 0x2800, 0x46000013);
                            M2C_FIELD(sprite, s32 *, 0x58) = M2C_FIELD(sprite, s32 *, 0x58) | 0x1000;
                            gCur3DSpriteEngine = oldEngine;
                            func_01ffa8c4((s32)ctx, 5);
                            func_0208fe30(0x1001d);
                        }
                    }
                } else {
                    s32 old = *phase;
                    s32 next = (s8)(old + 1);
                    s32 *table = &data_ov007_02221e10;
                    if (next >= 0 && next < 17 && (table[next] != 0 || (next > 0 && table[next - 1] != 0))) {
                        *phase = (s8)next;
                        func_0208fe30(0x1000d);
                    }
                }
            }
        }
        return;
    }
    default:
        return;
    }
}

void func_ov007_0221dbb0(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *data_02101e84;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(data_02101e84,u16 *,0);
current=old;
held=M2C_FIELD(data_02101e84,u16 *,2);
if(pressed&1){func_ov007_0221d008(arg0);return;}
if(held&0x40){
switch(old){
case 103:if(held==pressed)current=64;break;
case 104:if(held==pressed)current=66;break;
}
if(current>=103U){ if(current>104U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 103:if(held==pressed)current=4;break;
case 104:if(held==pressed)current=6;break;
}
if(current>=103U && current<=104U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 104:current=103;break;
case 103:current=102;break;
}
if(current>=103U && current<=104U)goto done;
}else if(held&0x10){
switch(current){
case 104:current=105;break;
case 103:current=104;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221dcc0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221dcd4(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221dce0(void *arg0) {
    M2C_UNK func_01ffa8c4(s32, M2C_UNK);
    M2C_UNK func_02008048(s32 *, s8 *, M2C_UNK);
    s32 func_020194e0(s32 *, M2C_UNK *);
    M2C_UNK func_020899cc(void *, M2C_UNK, M2C_UNK, s32);
    void *func_0208b564(s32);
    s32 func_02099ae8(s32 *);
    s32 func_02099b00(s32 *);
    M2C_UNK func_020b269c();
    M2C_UNK func_020d47d0();
    M2C_UNK func_020d47f0();
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_02220404;
    extern M2C_UNK data_ov007_02220824;
    extern M2C_UNK data_ov007_02221e0c;
    extern s32 data_ov007_02221e10;
    s32 *var_r7_2;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r1;
    s32 *var_r2;
    s32 var_r7;
    s32 *var_r8;
    s8 *var_r8_2;
    u32 var_r9;
    u8 temp_r1;
    void *temp_r0;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x10);
    switch (temp_r1) {                              /* irregular */
    case 0x69:
        func_020d47f0();
        func_01ffa8c4(temp_r4, 3);
        func_0208fe30(0x1000F);
        return;
    case 0x6A:
        var_r1 = 0;
        var_r2 = &data_ov007_02221e10;
        if (M2C_FIELD(&data_ov007_02221e0c, s32 *, 4) != 0) {
            do {
                var_r2 += 1;
                var_r1 += 1;
            } while (*var_r2 != 0);
        }
        if (var_r1 != 0) {
            var_r7 = 1;
            var_r8 = &data_ov007_02221e10;
            if (M2C_FIELD(&data_ov007_02221e0c, s32 *, 4) != 0) {
loop_9:
                if ((func_020194e0(var_r8, &data_ov007_02220404) != 0) && (func_020194e0(var_r8, &data_ov007_02220824) != 0)) {
                    var_r7 = 0;
                } else {
                    var_r8 += 1;
                    if (*var_r8 != 0) {
                        goto loop_9;
                    }
                }
            }
            if (var_r7 == 0) {
                var_r7_2 = &data_ov007_02221e10;
                var_r8_2 = M2C_FIELD(&data_ov007_02221e0c, s8 **, 0);
                var_r9 = 0;
                while ((*var_r7_2 != 0) && (var_r9 < 0x10U)) {
                    if ((func_02099ae8(var_r7_2) != 0) || (func_02099b00(var_r7_2) != 0)) {
                        func_02008048(var_r7_2, var_r8_2, 2);
                        var_r8_2 += 2;
                    } else {
                        func_02008048(var_r7_2, var_r8_2, 1);
                        var_r8_2 += 1;
                    }
                    var_r9 += 1;
                    var_r7_2 += 1;
                }
                *var_r8_2 = 0;
                func_020d47d0();
                func_01ffa8c4(temp_r4, 3);
                func_0208fe30(0x1000E);
                return;
            }
        }
        func_020b269c();
        temp_r5 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        temp_r0 = func_0208b564(temp_r4);
        func_020899cc(temp_r0, 2, 0x2800, 0x4600000F);
        M2C_FIELD(temp_r0, s32 *, 0x58) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x58) | 0x1000);
        gCur3DSpriteEngine = temp_r5;
        func_01ffa8c4(temp_r4, 5);
        func_0208fe30(0x1001D);
        return;
    }
}

void func_ov007_0221ded4(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *data_02101e84;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(data_02101e84,u16 *,0);
current=old;
held=M2C_FIELD(data_02101e84,u16 *,2);
if(pressed&1){func_ov007_0221dce0(arg0);return;}
if(held&0x40){
switch(old){
case 105:if(held==pressed)current=69;break;
case 106:if(held==pressed)current=72;break;
}
if(current>=105U){ if(current>106U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 105:if(held==pressed)current=9;break;
case 106:if(held==pressed)current=12;break;
}
if(current>=105U && current<=106U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 106:current=105;break;
case 105:current=104;break;
}
if(current>=105U && current<=106U)goto done;
}else if(held&0x10){
switch(current){
case 105:current=106;break;
case 106:if(held==pressed)current=100;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221dff0(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

