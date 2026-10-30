/* 16 functions from 0x020793F0 to 0x0207A3B0 (main), found by ds-decomp. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3;

void func_020793f0(void *arg0) { (void)arg0; }

void func_020796b0(M2C_UNK arg0, void *arg1) {
    void func_020799dc(void *, void *, void *, u32);
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

void func_0207971c(void *arg0, void *arg1) {
    void func_020722fc(u32, u32);
    void func_020799dc(void *, void *, void *, u32);
    extern u16 data_02168f14;
    extern M2C_UNK data_027e15bc;
    extern M2C_UNK data_020eb4ec;
    extern M2C_UNK data_020eb4e0;
    void *r8;
    unsigned char *r7;
    int globalCond;
    s32 arr1[8];
    s32 arr2[16];
    void *r3;
    int type;
    unsigned char nibble;
    int firstCount;
    int r0;
    int r6;
    int r1;
    int r5;
    int idx;
    int r1idx;
    int r2;
    int tableVal;
    void *ptr;
    int r4;
    int tmp;
    r8 = arg0;
    r7 = (unsigned char *)arg1;
    if (r7[0x30] == 1) return;
    globalCond = ((data_02168f14 & 7) == 2);
    if (globalCond) {
        r3 = *(void **)(r7 + 0x0C);
        type = ((unsigned char *)r3)[0] >> 6;
        nibble = ((unsigned char *)r3)[0x0B] & 0x0F;
        firstCount = 0;
        if (type == 3) {
            arr1[firstCount++] = 0x14;
        }
        switch (nibble) {
            case 0: arr1[firstCount++] = 0x16; break;
            case 1: arr1[firstCount++] = 0x17; break;
            case 6: arr1[firstCount++] = 0x19; break;
            case 8: arr1[firstCount++] = 0x18; break;
            default: break;
        }
        if (firstCount == 0) return;
        idx = ((u32)data_027e15bc >> 6) % firstCount;
        r0 = arr1[idx];
    } else {
        r6 = *(s32 *)(r7 + 0x1C);
        r1 = 0;
        if (r6 > 0) { arr2[0] = 0x11; r1 = 1; }
        r5 = *(s32 *)(r7 + 0x24);
        if (r5 != 0) {
            if (r5 & 0x02) arr2[r1++] = 0x0A;
            if (r5 & 0x04) arr2[r1++] = 0x0B;
            if (r5 & 0x08) arr2[r1++] = 0x0C;
            if (r5 & 0x800) arr2[r1++] = 0x15;
            if (r5 & 0x80) arr2[r1++] = 0x0D;
            if (r5 & 0x40) arr2[r1++] = 0x0E;
            if (r5 & 0x20) arr2[r1++] = 0x0F;
            if (r5 & 0x100) arr2[r1++] = 0x10;
        }
        if (r1 == 0) return;
        idx = ((u32)data_027e15bc >> 6) % r1;
        r0 = arr2[idx];
        if (r0 == 0x11) {
            if (r6 > 0) {
                r1 = r6 - 1;
                r0 = 0x11 + r1;
            }
            if (r5 & 0x400) r0 += 1;
            if (r0 == 0) return;
        } else {
            if (r0 == 0) return;
        }
    }
    r1idx = *(s32 *)(r7 + 0x14);
    if (r1idx == 0x18) r0 += 0x1A;
    r2 = r0 * 0x0E;
    tableVal = ((unsigned char *)&data_020eb4ec)[r2];
    ptr = (void *)(&data_020eb4e0 + r2);
    r4 = 0;
    if (tableVal == 0) {
        r4 = (*(s32 *)(r7 + 0x18) << 5) + 0x1200;
    } else if (tableVal == 1) {
        tmp = *(s32 *)(r7 + 0x18) & 7;
        tmp = (tmp >= 4) ? 1 : 0;
        tmp <<= 5;
        r4 = tmp + 0x1400;
    }
    func_020799dc(r8, ptr, (void *)((unsigned char *)ptr + 6), (u32)r4);
}

#pragma scheduling off
void func_020799dc(void *arg0, void *arg1, void *arg2, u32 arg3) {
extern M2C_UNK data_02140f70;
s32 x=((s16*)arg1)[0], y=((s16*)arg1)[1];
s32 h=((s16*)arg2)[1], px=((s32*)arg0)[0], w=((s16*)arg2)[0], py=((s32*)arg0)[1];
s32 vx=(s16)(px-192), vy=(s16)(py-384);
s32 tx=(s32)(((x<<12)+2048)<<8)>>16, ty=(s32)(((y<<12)+2048)<<8)>>16;
s32 by=(s32)((((y+h)<<12)+2048)<<8)>>16, rx=(s32)((((x+w)<<12)+2048)<<8)>>16;
s32 ey=(s16)py, ex=(s16)(px+192);

(*(volatile u32*)0x40004a8)=0x6d504000; (*(volatile u32*)0x40004ac)=arg3>>4;
(*(volatile u32*)0x40004a4)=M2C_FIELD(&data_02140f70,u32*,8)|(M2C_FIELD(&data_02140f70,u32*,4)|0xc0)|0x21f0000;
(*(volatile u32*)0x4000480)=0x7fff; (*(volatile u32*)0x4000500)=1;
(*(volatile u32*)0x4000488)=(u16)tx|((u16)ty<<16);
(*(volatile u32*)0x400048c)=(u16)vx|((u16)vy<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)tx|((u16)by<<16);
(*(volatile u32*)0x400048c)=(u16)vx|((u16)ey<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)rx|((u16)by<<16);
(*(volatile u32*)0x400048c)=(u16)ex|((u16)ey<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)rx|((u16)ty<<16);
(*(volatile u32*)0x400048c)=(u16)ex|((u16)vy<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000504)=0;
}
#pragma scheduling reset
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
    void func_02079c90();
    func_02079c90((arg0 * 0x300) + 0x180, (arg1 * 0x300) + 0x180);
}

#pragma opt_common_subs off
void func_02079c90(s32 arg0, s32 arg1, s32 *arg2) {
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
#pragma opt_common_subs reset
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

void func_02079db0(void) {
    return;
}

