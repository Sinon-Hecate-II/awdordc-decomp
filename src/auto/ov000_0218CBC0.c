/* 5 functions from 0x0218CBC0 to 0x0218D908 (ov000), found by ds-decomp. */
#include "common.h"

typedef struct { u8 kind:6; u8 flags:2; u8 pad[5]; u16 health:7; u16 flags2:4; u16 value:5; u8 tail[6]; } Unit0218C4;

#pragma opt_strength_reduction off
M2C_UNK func_ov000_0218cbc0(void) {
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    u8 *func_020a47e0(s32, s32);
    s32 func_ov000_021a9bc0(void);
    s32 func_ov000_021a9740(void *, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_020d1690(s32, s32, s16 *);
    s32 func_ov000_021a93ec(s16, s16);
    s32 func_ov000_02176e28(s32, s16 *);
    s32 func_020d27a4(s32, s32);
    void func_ov000_0217c3a4(void);
    void func_ov000_02199d74(s32, s32, s32, s32, s32);
    s16 position[2];
    s32 bestX = -1, bestY = -1, bestScore = 0, bestId = 0, bestX2 = -1, bestY2 = -1;
    s16 savedX, savedY;
    s32 xmin, xmax, ymin, ymax;
    s32 bestHealth = 0xff;
    u8 *unit;
    u8 *other;
    s32 x, y, kind, health, damage, score, d;

    position[0] = M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 1);
    position[1] = M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 2);
    {
        u8 *map = *gCurrentMap;
        u8 *sel = M2C_FIELD(map, u8 **, 0x52d0);
        s32 sx = sel[1];
        s32 sy = sel[2];
        xmin = sx - 1;
        if (xmin < 0) xmin = 0;
        ymin = sy - 1;
        if (ymin < 0) ymin = 0;
        xmax = M2C_FIELD(map, u16 *, 0x5144) - 1;
        if (sx + 1 < xmax) xmax = sx + 1;
        ymax = M2C_FIELD(map, u16 *, 0x5146) - 1;
        if (sy + 1 < ymax) ymax = sy + 1;
    }

    for (y = ymin; y <= ymax; y++) {
        for (x = xmin; x <= xmax; x++) {
            s32 dx = M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 1) - x;
            if (dx <= 0) dx = x - M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 1);
            d = 0;
            d = d + dx;
            {
                s32 dy = M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 2) - y;
                if (dy <= 0) dy = y - M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 2);
                d = d + dy;
            }
            if (d < 1) continue;
            if (d > 1) continue;

            unit = func_020a47e0(x, y);
            if (unit != 0 && func_ov000_021a9bc0() != 0) {
                health = unit[4];
                kind = ((u32)M2C_FIELD(unit, u16 *, 2) << 0x16) >> 0x1c;
            } else if ((((u32)M2C_FIELD(data_ov000_021df580, u8 *, 7) << 0x1d) >> 0x1f) != 0) {
                kind = 1;
                health = M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0x539c) & 0x7f;
                if (health == 0) goto c20;
                if (M2C_FIELD((u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758), u8 *, 0) != 0) goto c20;
            } else {
                goto c20;
            }

            damage = func_0207c8ec(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->health * func_ov000_021a9740(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), kind), 100);
            func_020d1690(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), kind, position);
            if (M2C_FIELD(*gCurrentMap, s16 *, 0x6ed6) == 0) continue;
            if (damage >= bestHealth) {
                if (damage < health) continue;
                if (bestHealth > health) continue;
            } else {
                if (bestHealth < health) continue;
            }
            bestX2 = position[0];
            bestHealth = health;
            bestY2 = position[1];
            savedX = (s16)x;
            savedY = (s16)y;
            continue;

        c20:
            {
                u8 *base = (u8 *)*gCurrentMap + 0x59a4;
                u8 *tile = (u8 *)*gCurrentMap + x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758);
                s32 id = tile[0];
                other = base + id * 14;
                if (((Unit0218C4 *)other)->kind == 0) continue;
                if (func_020d27a4(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), other ? (s32)((other - base) / 14) : 0) == 1) continue;
                if (func_ov000_021a93ec((s16)x, (s16)y) == 0) continue;
                score = func_ov000_02176e28(((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)], position);
                if (score == 0) continue;
                if (score < bestScore) continue;
                bestScore = score;
                bestX = position[0];
                bestY = position[1];
                bestId = ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)];
            }
        }
    }

    if (bestScore != 0) {
        func_ov000_0217c3a4();
        func_ov000_02199d74(bestX, bestY, 4, (u8)bestId, 0);
    }
    if (bestHealth != 0xff) {
        func_ov000_0217c3a4();
        func_ov000_02199d74(bestX2, bestY2, 5, (u8)savedX, (u8)savedY);
    }
}
#pragma opt_strength_reduction reset
void func_ov000_0218cfec(void) {
    M2C_UNK func_ov000_0218bbd0(M2C_UNK);
    M2C_UNK func_ov000_0218cbc0();
    s32 func_ov000_021a98e4(u32);
    extern void **gCurrentMap;
    s32 temp_r0;

    temp_r0 = func_ov000_021a98e4((u32) (*M2C_FIELD(*gCurrentMap, u8 **, 0x52D0) << 0x1A) >> 0x1A);
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_ov000_0218cbc0();
        return;
    case 1:
        func_ov000_0218bbd0(0);
        return;
    }
}

void func_ov000_0218d040(void *arg0) { (void)arg0; }

s32 func_ov000_0218d40c(void){
extern void **gCurrentMap; extern u8 data_ov000_021b5c0a[],data_ov000_021b5c05[];
u8 *p=M2C_FIELD(*gCurrentMap,u8 **,0x52D0); u32 type;
if(((u32)(M2C_FIELD(p,volatile u16 *,6)<<25)>>25)<=90)return 1;
type=(u32)(p[0]<<26)>>26;
if((s32)((u32)(p[10]<<25)>>25)<(s32)data_ov000_021b5c0a[type*112]>>1){
if(type!=1 && type!=2)return 1;
}
if(data_ov000_021b5c05[type*112]>=6U && ((u32)(M2C_FIELD(p,volatile u16 *,6)<<21)>>28)<=3)return 1;
return 0;
}

M2C_UNK func_ov000_0218d4b4(void) { return 0; }

