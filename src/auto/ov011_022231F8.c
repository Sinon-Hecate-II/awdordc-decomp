/* 3 functions from 0x022231F8 to 0x02223CB8 (ov011), found by ds-decomp. */
#include "common.h"
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f28;
extern void *gCur3DSpriteEngine, *data_027e00c8, *data_027e00c4;

M2C_UNK func_ov011_022231f8() { return 0; }

void func_ov011_02223764(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, u16, s32);
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    extern M2C_UNK data_ov011_02228ce0;
    u16 *sp44 = 0;
    u16 *sp40 = 0;
    u16 *sp3C = 0;
    u16 *sp38 = 0;
    u16 *sp34 = 0;
    u16 *sp30 = 0;
    u16 *sp2C = 0;
    u16 *sp28 = 0;
    u16 *sp24 = 0;
    u16 *sp20 = 0;
    u16 *sp1C = 0;
    u16 *sp18 = 0;
    u16 *sp14 = 0;
    u16 *sp10 = 0;
    u16 *spC = 0;
    u16 *sp8 = 0;
    u16 *sp4 = 0;
    s32 temp_z = 0;
    s32 temp_z_2 = 0;
    s32 var_r1 = 0;
    s32 var_r2 = 0;
    s32 var_r2_2 = 0;
    void *temp_r0 = 0;
    void *temp_r1 = 0;
    void *temp_r1_2 = 0;
    void **var_r6 = 0;
    void **var_r7 = 0;
    void **var_r8 = 0;
    u16 *temp_r6 = 0;
    u16 *temp_r7 = 0;
    u16 *temp_r7_2 = 0;
    u16 *temp_r7_3 = 0;
    u16 *temp_r7_4 = 0;
    u16 *temp_r7_5 = 0;
    u16 *temp_r8 = 0;
    u16 *temp_r8_10 = 0;
    u16 *temp_r8_11 = 0;
    u16 *temp_r8_2 = 0;
    u16 *temp_r8_3 = 0;
    u16 *temp_r8_4 = 0;
    u16 *temp_r8_5 = 0;
    u16 *temp_r8_6 = 0;
    u16 *temp_r8_7 = 0;
    u16 *temp_r8_8 = 0;
    u16 *temp_r8_9 = 0;
    u8 var_r0 = 0;

    if (arg1 == 0) {
        var_r2 = 0;
        temp_r1 = data_027e01d8;
        do {
            temp_z = var_r2 == 0;
            var_r2 += 1;
            if (temp_z) {
                var_r6 = (void**)data_027e00c8;
            } else {
                var_r6 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r6;
            temp_r6 = *var_r6;
            sp44 = temp_r6 + 0x12;
            M2C_FIELD(temp_r6, s16 *, 0x12) = (s16) (*sp44 & ~0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x53) = 0;
        } while (var_r2 < 2);
        data_027e01d8 = temp_r1;
        M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) = 0U;
        return;
    }
    if (arg1 > 0) {
        var_r0 = func_0207ca38(0, 0x10, 0, M2C_FIELD(&data_ov011_02228ce0, u16 *, 4), arg1);
    } else {
        var_r0 = func_0207ca38(0, 0, 0x10, M2C_FIELD(&data_ov011_02228ce0, u16 *, 4), 0 - arg1);
    }
    if ((u32) var_r0 < 0x10U) {
        var_r2_2 = 0;
        temp_r1_2 = data_027e01d8;
        do {
            if (var_r2_2 == 0) {
                var_r8 = (void**)data_027e00c8;
            } else {
                var_r8 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r8;
            temp_r8 = *var_r8;
            sp40 = temp_r8 + 0x12;
            M2C_FIELD(temp_r8, s16 *, 0x12) = (s16) ((*sp40 & ~1) | 1);
            temp_r8_2 = *(void**)data_027e01d8;
            sp3C = temp_r8_2 + 0x12;
            M2C_FIELD(temp_r8_2, s16 *, 0x12) = (s16) (*sp3C | 2);
            temp_r8_3 = *(void**)data_027e01d8;
            sp38 = temp_r8_3 + 0x12;
            M2C_FIELD(temp_r8_3, s16 *, 0x12) = (s16) (*sp38 | 4);
            temp_r8_4 = *(void**)data_027e01d8;
            sp34 = temp_r8_4 + 0x12;
            M2C_FIELD(temp_r8_4, s16 *, 0x12) = (s16) (*sp34 | 8);
            temp_r8_5 = *(void**)data_027e01d8;
            sp30 = temp_r8_5 + 0x12;
            M2C_FIELD(temp_r8_5, s16 *, 0x12) = (s16) (*sp30 & ~0x10);
            temp_r8_6 = *(void**)data_027e01d8;
            sp2C = temp_r8_6 + 0x12;
            M2C_FIELD(temp_r8_6, s16 *, 0x12) = (s16) (*sp2C & ~0x100);
            temp_r8_7 = *(void**)data_027e01d8;
            sp28 = temp_r8_7 + 0x12;
            M2C_FIELD(temp_r8_7, s16 *, 0x12) = (s16) (*sp28 & ~0x200);
            temp_r8_8 = *(void**)data_027e01d8;
            sp24 = temp_r8_8 + 0x12;
            M2C_FIELD(temp_r8_8, s16 *, 0x12) = (s16) (*sp24 & ~0x400);
            temp_r8_9 = *(void**)data_027e01d8;
            sp20 = temp_r8_9 + 0x12;
            M2C_FIELD(temp_r8_9, s16 *, 0x12) = (s16) (*sp20 & ~0x800);
            temp_r8_10 = *(void**)data_027e01d8;
            sp1C = temp_r8_10 + 0x12;
            M2C_FIELD(temp_r8_10, s16 *, 0x12) = (s16) (*sp1C & ~0x1000);
            var_r2_2 += 1;
            temp_r8_11 = *(void**)data_027e01d8;
            sp18 = temp_r8_11 + 0x12;
            M2C_FIELD(temp_r8_11, s16 *, 0x12) = (s16) ((*sp18 & ~0xC0) | 0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, u8 *, 0x53) = var_r0;
        } while (var_r2_2 < 2);
        data_027e01d8 = temp_r1_2;
    } else {
        temp_r0 = data_027e01d8;
        var_r1 = 0;
        do {
            temp_z_2 = var_r1 == 0;
            var_r1 += 1;
            if (temp_z_2) {
                var_r7 = (void**)data_027e00c8;
            } else {
                var_r7 = (void**)data_027e00c4;
            }
            data_027e01d8 = var_r7;
            temp_r7 = *(void**)data_027e01d8;
            sp14 = temp_r7;
            *temp_r7 = *sp14 & ~0x10;
            temp_r7_2 = *(void**)data_027e01d8;
            sp10 = temp_r7_2;
            *temp_r7_2 = *sp10 & ~0x20;
            temp_r7_3 = *(void**)data_027e01d8;
            spC = temp_r7_3;
            *temp_r7_3 = *spC & ~0x40;
            temp_r7_4 = *(void**)data_027e01d8;
            sp8 = temp_r7_4;
            *temp_r7_4 = *sp8 & ~0x80;
            temp_r7_5 = *(void**)data_027e01d8;
            sp4 = temp_r7_5;
            *temp_r7_5 = *sp4 | 0x100;
        } while (var_r1 < 2);
        data_027e01d8 = temp_r0;
    }
    M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) = (u16) (M2C_FIELD(&data_ov011_02228ce0, u16 *, 4) + 1);
    ((M2C_UNK(*)(M2C_UNK,u8,s32,M2C_UNK,s32))func_ov011_022231f8)(arg0, (u8)(arg2 | 0x80), 0x7FFF, 0x80, arg3);
}

void func_ov011_02223b70(s32 unused,s32 value,u32 mode) {
void func_02082a8c(void*,void*);
ContextTemplate temp=data_ov011_02227f28;
void *saved,*p; s32 i;
if(mode<2)return;
i=0;
if(value==0){saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;return;}
((s16*)&temp)[7]=value;
((s16*)&temp)[6]=((s16*)&temp)[7];
saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
