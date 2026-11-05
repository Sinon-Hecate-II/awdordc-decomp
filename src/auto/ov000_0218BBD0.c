/* 4 functions from 0x0218BBD0 to 0x0218CBC0 (ov000), found by ds-decomp. */
#include "common.h"

typedef struct { u8 kind:6; u8 flags:2; u8 pad[5]; u16 health:7; u16 flags2:4; u16 value:5; u8 tail[6]; } Unit0218C4;

int func_ov000_0218bbd0(void *arg0) {
    return 0;
}

#pragma opt_strength_reduction off
s32 func_ov000_0218c400(s32 arg0) {
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 *data_ov000_021df644;
    void func_01ffc328(void *);
    void func_01ffb9c4(int);
    s32 func_020a7cfc(void *);
    s32 func_020a76d4(void *);
    u8 *func_020a47e0(s32, s32);
    s32 func_ov000_021a9bc0(void);
    s32 func_ov000_021a9740(void *, s32);
    s32 func_0207c8ec(s32, s32);
    s32 func_ov000_02178268(s32, s32, s16 *);
    s32 func_020d1690(s32, s32, s16 *);
    s32 func_ov000_021a98a8(s32);
    s32 func_ov000_021a9c90(s32, s32);
    s32 func_ov000_02178e84(s32, s32);
    s32 func_ov000_021a93ec(s16, s16);
    s32 func_ov000_021a9904(s32);
    s32 func_ov000_0217d150(s32, s32, void *);
    s32 func_ov000_02176e28(s32, s16 *);
    void func_ov000_0217c3a4(void);
    void func_ov000_02199d74(s32, s32, s32, s32, s32);
    s16 position[2];
    s32 bestX = -1, bestY = -1, bestScore = 0, bestId = 0, bestX2 = -1, bestY2 = -1;
    s32 flags = 0;
    s32 savedX, savedY;
    s32 bestHealth = 0xff;
    u8 *unit;
    u8 *other;
    s32 i, x, y, kind, health, damage, score, bonus;

    if (func_020a7cfc(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)) != 0) flags |= 0x400000;
    func_01ffc328(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
    for (i = 0; i < func_020a76d4(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)); i++)
        func_01ffb9c4((s8)(i + 0x6f));

    for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
            if (M2C_FIELD((u8 *)*gCurrentMap + y * 4, s8 **, 0x52e8)[x] < 0) continue;
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
            if (damage < health && damage < 10) continue;
            if (func_ov000_02178268(x, y, position) == 0) continue;
            func_020d1690(M2C_FIELD(*gCurrentMap, u8 *, 0x52d4), kind, position);
            if (M2C_FIELD(*gCurrentMap, s16 *, 0x6ed6) == 0) continue;
            if (damage >= bestHealth) {
                if (damage < health) continue;
                if (bestHealth > health) continue;
            } else {
                if (bestHealth < health) continue;
            }

            if (M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap, u16 *, 0x52a4) * 0x8c + 0x67ce, u8 *, 0) == 3) {
                if (damage < health) {
                    if (func_ov000_021a98a8(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind) == 0) {
                        u8 *tile = (u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758);
                        if (!(M2C_FIELD(tile, u8 *, 0x2840) < data_ov000_021df644[1] && M2C_FIELD(tile, u8 *, 0x2d48) < data_ov000_021df644[2])) continue;
                    }
                }
            }
            if (M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD((u8 *)*gCurrentMap, u16 *, 0x52a4) * 0x8c + 0x67ce, u8 *, 0) == 2) {
                if (func_ov000_021a9c90(bestX, bestY) >= 2) {
                    if (func_ov000_021a98a8(((Unit0218C4 *)M2C_FIELD(*gCurrentMap, u8 **, 0x52d0))->kind) == 0) {
                        u8 *tile = (u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758);
                        if (M2C_FIELD(tile, u8 *, 0x2d48) >= data_ov000_021df644[2]) continue;
                    }
                }
            }
            if (func_ov000_02178e84(position[0], position[1]) == 0) continue;
            bestHealth = health;
            bestX2 = position[0];
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
                if (func_ov000_02178268(x, y, position) == 0) continue;
                {
                    u32 v2 = M2C_FIELD((u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758), u8 *, 0x2d48);
                    u32 d2 = data_ov000_021df644[2];
                    bonus = 0;
                    if (v2 >= d2) goto bonus_chk;
                    {
                        u32 v1 = M2C_FIELD((u8 *)*gCurrentMap + position[0] + M2C_FIELD((u8 *)*gCurrentMap + position[1] * 2, u16 *, 0x3758), u8 *, 0x2840);
                        u32 d1 = data_ov000_021df644[1];
                        if (v1 < d1) goto score;
                    }
                bonus_chk:
                    if (other[0xc] == 0 && func_ov000_021a9904(((Unit0218C4 *)other)->kind) == 2 && func_ov000_0217d150(position[0], position[1], other) == 0)
                        bonus = 0x80000;
                score:
                    score = func_ov000_02176e28(flags | (bonus | ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)]), position);
                    if (score == 0) continue;
                    if (score < bestScore) continue;
                    bestScore = score;
                    bestX = position[0];
                    bestY = position[1];
                    bestId = ((u8 *)*gCurrentMap)[x + M2C_FIELD((u8 *)*gCurrentMap + y * 2, u16 *, 0x3758)];
                }
            }
        }
    }

    if (bestScore != 0) {
        if (arg0 != 0) return 1;
        func_ov000_0217c3a4();
        func_ov000_02199d74((s16)bestX, (s16)bestY, 4, (u8)bestId, 0);
    }
    if (bestHealth != 0xff) {
        if (arg0 != 0) return 1;
        func_ov000_0217c3a4();
        func_ov000_02199d74((s16)bestX2, (s16)bestY2, 5, (u8)savedY, (u8)savedX);
    }
    return 0;
}
#pragma opt_strength_reduction reset
void func_ov000_0218ca94(void) {
extern void **gCurrentMap;
switch(func_ov000_021a98e4((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26)){
case 0: func_ov000_0218b0d8(0); return;
case 1: if(func_020a85c8((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26))func_ov000_0218c400(0);else func_ov000_0218bbd0(0);return;
}}

s32 func_ov000_0218cb20(void) {
extern void **gCurrentMap;
u32 x=(u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26;
if(x==6)return 0;
switch(func_ov000_021a98e4(x)){
case 0: return func_ov000_0218b0d8(1);
case 1: if(func_020a85c8((u32)(*M2C_FIELD(*gCurrentMap,u8 **,0x52d0)<<26)>>26))return func_ov000_0218c400(1);else return func_ov000_0218bbd0(1);
default:return 0;
}}

