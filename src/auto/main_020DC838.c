/* 23 functions from 0x020DC838 to 0x020DD4F8 (main), found by ds-decomp. */
#include "common.h"

static inline void func_020dcc00(void *q) {
    u32 base;
    s32 next;
    u32 value;
    s32 test;
    base = (u32)(M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16)((u32)(M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

M2C_UNK func_020dc838(void *entity) {
    void func_020aacf0(void *);
    void func_020d47f0(void);
    void func_01ffa8c4(void *, s32);
    void func_0208fe30(s32);
    void func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    typedef struct { u32 low:18; u32 value:8; u32 high:6; } E0B04Bits;
    typedef struct { unsigned char value:4; } E0194Bits;

    u32 keys;
    void *p;
    u8 allowed;

    if (M2C_FIELD(entity, void **, 0x50)) func_020aacf0(M2C_FIELD(entity, void **, 0x50));
    if (M2C_FIELD(entity, void **, 0x54)) func_020aacf0(M2C_FIELD(entity, void **, 0x54));
    if (M2C_FIELD(entity, void **, 0x58)) func_020aacf0(M2C_FIELD(entity, void **, 0x58));

    keys = *data_02101e84;
    M2C_FIELD(entity, u16 *, 0x48) &= ~0x20;

    p = M2C_FIELD(entity, void **, 0x58);
    allowed = 1;
    if (M2C_FIELD(M2C_FIELD(p, void **, 0x64), s8 *, 0xb) != 1) {
        if (!((u32)(M2C_FIELD(p, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(M2C_FIELD(p, void **, 0x64), s8 *, 0xc) != 1)
            allowed = 0;
    }

    if ((u8)(allowed & 0xff) == 0) {
        if (!(keys & 0x2)) goto skip1;
        if (M2C_FIELD(entity, u16 *, 0x48) & 0x4) goto skip1;
    }

    if (M2C_FIELD(p, s8 *, 0x5a) >= 0) {
        M2C_FIELD(p, E0B04Bits *, 0x40).value = (u16)(M2C_FIELD(p, E0194Bits *, 0x59).value + 1);
        M2C_FIELD(p, u8 *, 0x5a) = 12;
    }
    func_020d47f0();
    if (M2C_FIELD(entity, s32 *, 0x38) == 0)
        M2C_FIELD(entity, u8 *, 0x40) = 0x1e;
    else if (M2C_FIELD(entity, s32 *, 0x38) == 1)
        M2C_FIELD(entity, u8 *, 0x40) = 0x1f;
    M2C_FIELD(entity, u16 *, 0x48) |= 0x20;
    func_01ffa8c4(entity, 0x44);
    func_0208fe30(0x1000f);
    return;

skip1:
    p = M2C_FIELD(entity, void **, 0x50);
    {
        u8 low = M2C_FIELD(p, E0194Bits *, 0x59).value;
        u32 extracted = (M2C_FIELD(p, u32 *, 0x40) << 6) >> 24;
        if (low + 2 != extracted) {
            u8 allowed2 = 1;
            void *rp = M2C_FIELD(p, void **, 0x64);
            if (M2C_FIELD(rp, s8 *, 0xb) != 1) {
                if (!((u32)(M2C_FIELD(p, u8 *, 0x59) << 27) >> 31) || M2C_FIELD(rp, s8 *, 0xc) != 1)
                    allowed2 = 0;
            }
            if ((u8)(allowed2 & 0xff) == 0) {
                if (!(keys & 0x1)) return;
                if (M2C_FIELD(entity, u16 *, 0x48) & 0x4) return;
            }
            if (M2C_FIELD(p, s8 *, 0x5a) >= 0) {
                M2C_FIELD(p, E0B04Bits *, 0x40).value = (u16)(low + 1);
                M2C_FIELD(p, u8 *, 0x5a) = 12;
            }
            if (M2C_FIELD(entity, u16 *, 0x48) & 0x4) return;
            func_0208fe30(0x1000e);
            M2C_FIELD(entity, u16 *, 0x48) |= 0x4;
            func_01ffa6fc(entity);
        }
    }
}

void func_020dca5c(void) {
    M2C_UNK func_020dc614();
    func_020dc614();
}

void func_020dca68(void) {
    M2C_UNK func_020dc614();
    func_020dc614();
}

void func_020dca74(void) {
    M2C_UNK func_020dc838();
    func_020dc838();
}

void func_020dca80(void) {
    M2C_UNK func_020dc838();
    func_020dc838();
}

M2C_UNK func_020dca8c(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

M2C_UNK func_020dcae8(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 func_020a8ff4(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

void func_020dcb44(void) {
    M2C_UNK func_020dca8c();
    func_020dca8c();
}

void func_020dcb50(void) {
    M2C_UNK func_020dca8c();
    func_020dca8c();
}

void func_020dcb5c(void) {
    M2C_UNK func_020dcae8();
    func_020dcae8();
}

void func_020dcb68(void) {
    M2C_UNK func_020dcae8();
    func_020dcae8();
}

M2C_UNK func_020dcb74(void *arg0) {
extern void **gCur3DSpriteEngine, **data_027e00c8;
extern M2C_UNK data_0212d3a8, data_0212d3b0, data_0212d3c0, data_0212c608, data_0212c630;
M2C_UNK func_01ff9ce8(s32), func_0200bc5c(void *);
s32 func_020e3218(void *);
M2C_UNK func_020814e4(void), func_02081528(void);
M2C_UNK func_02081590(s32,s32), func_02080944(s32,s32,s32,s32);
s32 func_020b20e0(s32);
void *func_020b22a4(s32,s32,void *,s32), *func_020b1c78(s32);
M2C_UNK func_020808dc(s32,s32,u16,u16);
void func_0208fe30(s32);
M2C_UNK func_020b1c44(s32,s32);
M2C_UNK func_02088f1c(void *), func_0208b758(void *,s32);
s16 func_020a8ff4(void *);
void func_ov009_02224560(s32,s32,s32);
#pragma opt_strength_reduction off
s32 i, x, i2, y, end, color, test;
void **saved, **sp0;
void *sp4, *p, *item;
u8 selected;

saved = gCur3DSpriteEngine;
gCur3DSpriteEngine = data_027e00c8;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
func_0200bc5c(&data_0212d3a8);
func_020e3218(&data_0212d3b0);
func_020814e4();
func_02081590(func_020e3218(&data_0212d3c0), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
func_02081528();
func_02080944(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 32, 24, 5);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
gCur3DSpriteEngine = saved;
M2C_FIELD(arg0, u16 *, 0x48) |= 32;
if (func_020b20e0(0) == 0) test = 1; else test = 0;
if (test) {
    i = 0; x = 0;
    do {
        p = func_020b22a4(0, x, &data_0212c608, i);
        i++;
        M2C_FIELD(p, void **, 0x10) = arg0;
        x += 0x28;
    } while (i < 4);
}
p = func_020b22a4(0, 0, &data_0212c630, 4);
M2C_FIELD(p, void **, 0x10) = arg0;
item = func_020b1c78(M2C_FIELD(arg0, s8 *, 0x43));
if (item) {
    sp4 = M2C_FIELD(item, void **, 0x10);
    sp0 = gCur3DSpriteEngine;
    y = 1;
    gCur3DSpriteEngine = data_027e00c8;
    end = 5;
    i2 = 0;
    do {
        if (M2C_FIELD(item, u8 *, 0) != i2) color = 5; else color = 6;
        func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20) + 2 + (y << 6), 30, (u16)(end - y), (u16)color);
        i2++;
        y = (s16)(y + 5);
        end = (s16)(end + 5);
    } while (i2 < 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = sp0;
    selected = M2C_FIELD(item, u8 *, 0);
    if (selected != M2C_FIELD(sp4, s8 *, 0x43)) {
        M2C_FIELD(sp4, s8 *, 0x43) = selected;
        func_0208fe30(0x10019);
    }
}
func_020b1c44(0, 0);
p = M2C_FIELD(arg0, void **, 0x50);
func_02088f1c(p);
p = M2C_FIELD(arg0, void **, 0x50);
func_020dcc00(p);
M2C_FIELD(p, u8 *, 0x5a) = 0;
p = M2C_FIELD(arg0, void **, 0x58);
func_02088f1c(p);
p = M2C_FIELD(arg0, void **, 0x58);
func_020dcc00(p);
M2C_FIELD(p, u8 *, 0x5a) = 0;
func_0208b758(M2C_FIELD(arg0, void **, 0x64), 0x44000010);
func_02088f1c(M2C_FIELD(arg0, void **, 0x64));
if (func_020a8ff4(M2C_FIELD(arg0, void **, 0x68))) {
    s16 result = func_020a8ff4(M2C_FIELD(arg0, void **, 0x68));
    p = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(p, u16 *, 0xe) = result;
    M2C_FIELD(p, u16 *, 0x10) = 0;
    M2C_FIELD(p, u16 *, 0xc) = 12;
    M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
}
p = M2C_FIELD(arg0, void **, 0x5c);
func_02088f1c(p);
p = M2C_FIELD(arg0, void **, 0x5c);
func_020dcc00(p);
M2C_FIELD(p, u8 *, 0x5a) = 0;
p = M2C_FIELD(arg0, void **, 0x5c);
M2C_FIELD(p, s16 *, 0x34) = M2C_FIELD(p, s16 *, 0x50);
M2C_FIELD(p, s16 *, 0x36) = M2C_FIELD(p, s16 *, 0x52);
p = M2C_FIELD(arg0, void **, 0x5c);
func_020dcc00(p);
M2C_FIELD(p, u8 *, 0x5a) = 0;
M2C_FIELD(arg0, u16 *, 0x48) &= ~0x2;
func_ov009_02224560(0, 0, 0);
#pragma opt_strength_reduction on
}

void func_020dd004(void) {

}

M2C_UNK func_020dd008(void) { return (M2C_UNK)0; }

void func_020dd48c(void) {
    M2C_UNK func_020dd008();
    func_020dd008();
}

void func_020dd498(void) {
    M2C_UNK func_020dcb74();
    func_020dcb74();
}

void func_020dd4a4(void) {
    M2C_UNK func_020dcb74();
    func_020dcb74();
}

void func_020dd4b0(void) {
    func_020dd004();
}

void func_020dd4bc(void) {
    func_020dd004();
}

void func_020dd4c8(void) {
    M2C_UNK func_020dd008();
    func_020dd008();
}

void func_020dd4d4(void) {
    M2C_UNK func_020dd008();
    func_020dd008();
}

void func_020dd4e0(void) {
    func_020dd48c();
}

void func_020dd4ec(void) {
    func_020dd48c();
}

