/* 16 functions from 0x020793F0 to 0x0207A3B0 (main), found by ds-decomp. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3;

void func_020796b0(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_020799dc(M2C_UNK, s32, s32, s32);
    extern M2C_UNK data_020eb4e0;
    s32 ptr;
    s32 index;
    s32 flip;
    if (M2C_FIELD(arg1, u8 *, 0x30) == 1) return;
    if (M2C_FIELD(arg1, s32 *, 0x20) < 1) return;
    if (M2C_FIELD(arg1, s32 *, 0x20) >= 10) return;
    index = M2C_FIELD(arg1, u32 *, 0x20);
    if (M2C_FIELD(arg1, s32 *, 0x14) == 0x18) index += 0x1A;
    ptr = index * 14 + (s32)&data_020eb4e0;
    flip = (s32)(M2C_FIELD(arg1, s32 *, 0x18) & 7) >= 4;
    func_020799dc(arg0, ptr, ptr + 6, (flip << 5) + 0x1400);
}

void func_02079b64(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x180;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0x10;
}

void func_02079b88(void *arg0) {
    void func_01ffa6fc(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)++;
    if (M2C_FIELD(arg0, s16 *, 0x6C) < M2C_FIELD(arg0, s16 *, 0x6E)) return;
    func_01ffa6fc(arg0);
}

void func_02079bb0(M2C_UNK arg0) {
    M2C_UNK func_02079bc4(M2C_UNK, M2C_UNK);
    func_02079bc4(0x10, arg0);
}

M2C_UNK func_02079bc4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0208fe30(s32);
    void *func_01ffa42c();
    extern M2C_UNK data_02100ab0;
    func_0208fe30(0x82);
    M2C_FIELD(func_01ffa42c(&data_02100ab0, arg1), s16 *, 0x6E) = arg0;
}

void func_02079bf0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x180;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x80;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0x10;
}

void func_02079c14(void *arg0) {
    void func_01ffa6fc(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)++;
    if (M2C_FIELD(arg0, s16 *, 0x6C) < M2C_FIELD(arg0, s16 *, 0x6E)) return;
    func_01ffa6fc(arg0);
}

void func_02079c3c(M2C_UNK arg0) {
    M2C_UNK func_02079c50(M2C_UNK, M2C_UNK);
    func_02079c50(0x10, arg0);
}

M2C_UNK func_02079c50(M2C_UNK arg0, M2C_UNK arg1) {
    void *func_01ffa42c();
    extern M2C_UNK data_02100a88;
    M2C_FIELD(func_01ffa42c(&data_02100a88, arg1), s16 *, 0x6E) = arg0;
}

void func_02079c6c(s32 arg0, s32 arg1) {
    M2C_UNK func_02079c90();
    func_02079c90((arg0 * 0x300) + 0x180, (arg1 * 0x300) + 0x180);
}

M2C_UNK func_02079c90(s32 arg0, s32 arg1, s32 *arg2) {
    s32 func_0207c8ec(s32, s32);
    M2C_UNK func_0207d820(Vec3 *, void *);
    extern s32 *gCurrentMap;
    s32 base;
    Vec3 pos;
    base = *gCurrentMap + 0x6EF8;
    pos.x = arg0;
    pos.y = arg1;
    pos.z = 0;
    func_0207d820(&pos, (void *)(base + 0x70));
    arg2[0] = func_0207c8ec((arg2[0] + 0x1000) << 8, 0x2000);
    arg2[1] = func_0207c8ec((0x1000 - arg2[1]) * 0xC0, 0x2000);
}

void func_02079d0c(s32 arg0, s32 arg1, s32 *arg2) {
    M2C_UNK func_02000f90(Vec3 *, void *, Vec3 *);
    s32 func_0207c8ec(s32, s32);
    extern s32 *gCurrentMap;
    Vec3 pos;
    void *temp_r4;
    temp_r4 = (void *)(*gCurrentMap + 0x6EF8);
    pos.x = func_0207c8ec((arg0 << 12) - 0x80000, 0x80);
    pos.y = -func_0207c8ec((arg1 << 12) - 0x60000, 0x60);
    pos.z = 0;
    func_02000f90(&pos, temp_r4 + 0xB0, &pos);
    arg2[0] = M2C_FIELD(temp_r4,s32 *,0xF0) + pos.x;
    arg2[1] = M2C_FIELD(temp_r4,s32 *,0xF4) + pos.y;
    arg2[2] = M2C_FIELD(temp_r4,s32 *,0xF8) + pos.z;
}

