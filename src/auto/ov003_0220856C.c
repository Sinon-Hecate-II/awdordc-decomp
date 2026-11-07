/* 5 functions from 0x0220856C to 0x02209310 (ov003), found by ds-decomp. */
#include "common.h"

s16 func_020a8ff4(void *);
void func_02086e9c(void);
void func_02086dfc(s32);
s32 func_0207c8ec(s32, s32);
void func_02087048(s32, s32);
void func_020a8cf0(s32, s32, s32, s32, u16, s32, u16, u16, u16, volatile u16);
s32 func_ov003_02206690(s32, s32, s32);
s32 func_020e4b28(s32);
s32 func_020a8e28(s32, s32);
void func_020bf054(s32, s32);
s32 func_020bee64(void);
void func_020a8e3c(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_ov003_0220856c(void *arg0, s32 arg1, s32 arg2) {
    s32 x;
    s32 sx;
    s32 sy;
    s32 i;
    s32 y;
    void *entry;
    s32 width;
    void *desc;
    void *selection;
    void *data;
    s32 offset;
    s32 count;
    s32 originX;
    s32 originY;
    s32 height;
    s32 drawColor;
    s32 alpha;
    s32 scaleX;
    s32 scaleY;
    s32 image;
    s32 image2;
    s32 row;
    s32 packed;
    s32 selected;
    s32 base;
    s32 noImage;
    s32 restoreColor;
    s32 textureB;
    s32 textureC;
    s32 textureD;
    s32 textureE;

    func_02086dfc((s16)arg2);
    originY = (s16)arg2;
    originX = arg1;
    data = M2C_FIELD(arg0, void **, 0x44);
    i = 0;
    count = M2C_FIELD(data, u8 *, 0);
    if (count <= 0) {
        return;
    }
    base = 0x8ec0;
    noImage = -1;
    restoreColor = noImage + 0x8000;
    textureB = base - 0x300;
    textureC = base - 0x2a00;
    textureD = base - 0x3480;
    textureE = base - 0x2f40;
    offset = 0;
    do {
        entry = (u8 *)M2C_FIELD(arg0, void **, 0x48) + offset;
        desc = M2C_FIELD(entry, void **, 0);
        width = M2C_FIELD(data, u8 *, 1);
        x = (s16)(originX + M2C_FIELD(entry, s16 *, 6) + (width >> 1));
        height = M2C_FIELD(data, u8 *, 2);
        y = (s16)(originY + M2C_FIELD(entry, s16 *, 8) + (height >> 1));
        drawColor = M2C_FIELD(entry, u8 *, 0x11) == 1 ? 0x6bef : 0;
        if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
            if (M2C_FIELD(M2C_FIELD(entry, void **, 0x20), u8 *, 0x0e) != 0) {
                alpha = M2C_FIELD(entry, s8 *, 0x13);
            } else {
                alpha = func_020a8ff4(M2C_FIELD(M2C_FIELD(entry, void **, 0x20), void **, 0));
            }
            drawColor = 0x1a;
            if (M2C_FIELD(M2C_FIELD(entry, void **, 0x18), u8 *, 0x0e) == 0) {
                sx = (M2C_FIELD(entry, u16 *, 0x0c) * func_020a8ff4(M2C_FIELD(M2C_FIELD(entry, void **, 0x18), void **, 0))) >> 8;
                sy = (M2C_FIELD(entry, u16 *, 0x0c) * func_020a8ff4(M2C_FIELD(M2C_FIELD(entry, void **, 0x1c), void **, 0))) >> 8;
                scaleX = func_020a8ff4(M2C_FIELD(M2C_FIELD(entry, void **, 0x18), void **, 0));
                scaleY = func_020a8ff4(M2C_FIELD(M2C_FIELD(entry, void **, 0x1c), void **, 0));
                if (sx == 0 && sy == 0) {
                    data = M2C_FIELD(arg0, void **, 0x44);
                    originY = (s16)(originY + M2C_FIELD(data, u8 *, 4));
                    i++;
                    offset += 0x24;
                    continue;
                }
            }
        } else {
            alpha = M2C_FIELD(entry, s8 *, 0x13);
        }
        selection = M2C_FIELD(M2C_FIELD(arg0, void **, 0x5c), void **, 0);
        selected = (((selection != 0 ? M2C_FIELD(selection, u16 *, 8) : noImage) - 0xb) & 0xff);
        if (i != selected) {
            drawColor = 0x1a;
        } else {
            alpha += func_020a8ff4(M2C_FIELD(arg0, void **, 0x50));
            drawColor = 0x1f;
            sx = M2C_FIELD(entry, u16 *, 0x0c);
            sy = sx;
            scaleX = 0x100;
            scaleY = 0x100;
            func_02087048(1, 0x1f);
        }
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3c), u8 *, 0x0f) == 8 && i <= 1) {
            packed = drawColor | (drawColor << 5);
            packed |= drawColor << 10;
            *(volatile u32 *)0x04000480 = (u16)packed;
            func_020a8cf0(x + (width >> 2), y, 1, width >> 1, 0x18, 3, 0x22a, 1, scaleX, scaleY);
            *(volatile u32 *)0x04000480 = restoreColor;
        }
        if (((sx * 0x18) >> 8) >= 3 && ((width * sy) >> 8) >= 3) {
            if (i == selected) {
                image = M2C_FIELD(desc, u16 *, 4);
                if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3c), u8 *, 0x0f) == 0xb) {
                    func_020bf054(0, i);
                    if (func_020bee64()) {
                        image = 0x9500;
                    } else if (func_020e4b28(i) == 0) {
                        image = 0x8000;
                    }
                } else if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3c), u8 *, 0x0f) != 9 && func_020e4b28(i) == 0) {
                    image = 0x8000;
                }
                func_020a8cf0(x, y, 1, sx, 0x18, 3, image >> 5, 1, scaleX, scaleY);
            } else {
                sx = func_0207c8ec(scaleX << 8, 0xcd);
                sy = func_0207c8ec(scaleY << 8, 0xcd);
                image = M2C_FIELD(desc, u16 *, 6);
                image2 = 0;
                row = M2C_FIELD(M2C_FIELD(arg0, void **, 0x3c), u8 *, 0x0f);
                if (row == 0xb) {
                    func_020bf054(0, i);
                    if (func_020bee64()) {
                        image = base + 0x1cc0;
                    } else if (func_020e4b28(i) == 0) {
                        image = base + 0x10c0;
                    }
                } else if (row != 9 && func_020e4b28(i) == 0) {
                    image = base + 0x10c0;
                }
                if (row == 8 && i <= 1) {
                    func_020a8cf0(x - (width >> 2) + func_020a8e28(width >> 1, sx), y, 1, width >> 1, 0x18, 3, image >> 5, 1, scaleX, scaleY);
                }
                if (row == 8 && i >= 2 && i <= 4 && func_ov003_02206690(i, 2, 4)) {
                    image2 = textureB;
                    if (i == 2) image2 = textureC;
                    if (i == 3) image2 = textureD;
                    if (i == 4) image2 = textureE;
                    func_020a8cf0(x - 0x30, y, 1, sx, 0x10, 3, image >> 5, 1, sx, sy);
                    func_020a8cf0(x + 0x30, y, 1, sx, 0x10, 3, image2 >> 5, 1, sx, sy);
                }
                func_020a8cf0(x, y, 1, 0xc0, 0x10, 3, image >> 5, 1, sx, sy);
            }
        }
        if (alpha != 0 && (drawColor != 0)) {
            func_02087048(1, alpha & 0xff);
            func_020a8e3c(x, y, 2, width, M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), u8 *, 3), drawColor, sx, sy, alpha, 0x100);
            func_02087048(1, 0x1f);
        }
        data = M2C_FIELD(arg0, void **, 0x44);
        originY = (s16)(originY + M2C_FIELD(data, u8 *, 4));
        i++;
        offset += 0x24;
    } while (i < M2C_FIELD(data, u8 *, 0));
    func_02086e9c();
}

u8 func_ov003_02209258(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 9) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02209274(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 2) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092a8(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 3) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092dc(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 4) result = 1;
 else result = 0;
 return result;
}

