/* 26 functions from 0x02187F7C to 0x02188D64 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
void func_ov000_02188688(void);
u8 func_ov000_021889ac(void);

u8 func_ov000_02188850(void);


void func_ov000_02187f7c(void) {
    extern void **gCurrentMap;
    (void)gCurrentMap;
}

s32 func_ov000_021882c4(void) {
    s32 func_ov000_02189f3c();
    s32 flag, count, current;
    if (func_ov000_02187e50() == 1) return 0;
    flag = func_ov000_0218a2f8();
    if (flag) count = func_ov000_02189e2c();
    else count = func_ov000_02189f3c();
    if (count == 0) return 0;
    current = func_ov000_0218a230();
    if (flag == 0) {
        if (current < count + 1) return 1;
    } else {
        if (current < count + 2) return 1;
    }
    return 0;
}

s32 func_ov000_02188338(void) {
    s32 func_ov000_0218a230();
    s32 func_ov000_0218a3fc();
    s32 temp_r4;
    s32 var_r0;
    s32 var_r5;

    temp_r4 = func_ov000_02189e2c();
    if (func_ov000_0218a3fc() == 0) {
        var_r5 = 0x80;
    } else {
        var_r5 = 0;
    }
    var_r0 = (temp_r4 + 2) - func_ov000_0218a230();
    if (var_r0 & 0x80) {
        var_r0 = 0x7F;
    }
    return var_r0 | var_r5;
}

void func_ov000_02188370(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = func_ov000_021882c4;
    data_ov000_021df648 = func_ov000_02188338;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
}

u8 CanDoFootAiAction(s32 arg0, s32 arg1) {
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);
    current = func_ov000_0218a230();
    if (current < func_ov000_02189e2c() + 2) result = 1;
    else result = 0;
    return result;
}

u8 func_ov000_02188448(void) {
    s32 func_ov000_02187e50();
    s32 temp_r0;
    u8 var_r0;

    if (func_ov000_02187e50() == 1) {
        return 0U;
    }
    temp_r0 = func_ov000_0218a2f8();
    if (temp_r0 == 0) {
        return 0U;
    }
    if (func_ov000_0218a294() < (s32) (temp_r0 + 5)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02188488(void) {
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r2;

    temp_r4 = func_ov000_0218a2f8();
    temp_r0 = func_ov000_0218a294();
    if (temp_r4 > 5) {
        var_r2 = 5;
    } else {
        var_r2 = temp_r4;
    }
    if (((s32) (temp_r4 - var_r2) < temp_r0) && ((s32) (temp_r4 + var_r2) > temp_r0)) {
        var_r1 = 0x80;
    } else {
        var_r1 = 0;
    }
    if (temp_r4 > temp_r0) {
        var_r0_2 = temp_r4 - temp_r0;
    } else {
        var_r0_2 = temp_r0 - temp_r4;
    }
    var_r0 = var_r0_2 + 1;
    if (var_r0 & 0x80) {
        var_r0 = 0x7F;
    }
    return var_r0 | var_r1;
}

void func_ov000_021884e4(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_02188448;
    data_ov000_021df648 = func_ov000_02188488;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_02188688();
}

u8 CanDoAiAction01(s32 arg0, s32 arg1) {
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);

    current = func_ov000_0218a2f8();
    if (current == 0) return 0;
    if (func_ov000_0218a294() < current + 5) result = 1;
    else result = 0;
    return result;
}

s32 func_ov000_021885c8(void) {
    s32 IsPlayerActive(s32);
    s32 func_020d243c(s32);
    s32 IsSameTeam(u16, s32);
    extern void **gCurrentMap;
    s32 i, offset;
    void *base, *entry;
    if (func_ov000_02187e50() == 1) return 0;
    for (i = 1, offset = 0x8C; i < 5; i++, offset += 0x8C) {
        if (IsPlayerActive(i) && !IsSameTeam(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) && func_020d243c(i)) {
            base = *gCurrentMap;
            entry = (u8 *)base + offset;
            if (M2C_FIELD(M2C_FIELD((u8 *)base + ((u32)(M2C_FIELD(entry, u8 *, 0x67D0) << 25) >> 23), s8 **, 0x52E8), s8 *, M2C_FIELD(entry, u8 *, 0x67CF) & 0x7F) > 0) return 1;
        }
    }
    return 0;
}

s32 func_ov000_02188680(void) {
    return 1;
}

void func_ov000_02188688(void) {
    s32 func_ov000_021885c8(void);
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = func_ov000_021885c8;
    data_ov000_021df648 = func_ov000_02188680;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
}

void CanDoAiAction2(s32 arg0, s32 arg1) {
    s32 func_ov000_021885c8(void);
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);

    func_ov000_021885c8();
}

u8 func_ov000_02188744(void) {
    s32 func_ov000_0218a2f8();
    s32 temp_r4;
    u8 var_r0;

    if (func_ov000_0218a2f8() == 0) {
        return 0U;
    }
    temp_r4 = func_ov000_02189e2c();
    if (temp_r4 > func_ov000_0218a294()) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov000_02188778(void) {
    s32 func_ov000_02189e2c();
    s32 func_ov000_0218a294();
    s32 temp_r4;

    temp_r4 = func_ov000_02189e2c();
    return temp_r4 - func_ov000_0218a294();
}

void func_ov000_02188790(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_02188744;
    data_ov000_021df648 = func_ov000_02188778;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

void CanDoAiAction34(s32 arg0, s32 arg1) {
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);
    func_ov000_02188744();
}

u8 func_ov000_02188850(void) {
    s32 func_020d243c(s32);
    extern void **gCurrentMap;
    void *base, *entry;
    u8 result;
    if (func_ov000_02187e50() == 1) return 0;
    if (func_020d243c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) == 0) return 0;
    base = *gCurrentMap;
    entry = (u8 *)base + 0x67A4 + M2C_FIELD(base, u16 *, 0x52A4) * 0x8C;
    if (M2C_FIELD(M2C_FIELD((u8 *)base + ((u32)(M2C_FIELD(entry, u8 *, 0x2C) << 25) >> 23), s8 **, 0x52E8), s8 *, M2C_FIELD(entry, u8 *, 0x2B) & 0x7F) > 0) result = 1;
    else result = 0;
    return result;
}

s32 func_ov000_021888e4(void) {
    return 1;
}

void func_ov000_021888ec(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_02188850;
    data_ov000_021df648 = func_ov000_021888e4;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

void CanDoAiAction5(s32 arg0, s32 arg1) {
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 current, offset;
    u8 result;
    void *base, *table;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);
    func_ov000_02188850();
}

#pragma opt_lifetimes off
u8 func_ov000_021889ac(void) {
    extern void **gCurrentMap;
    u16 value;
    s8 *bank;
    void *base, *entry;
    u8 result;
    base = *gCurrentMap;
    entry = (u8 *)base + 0x59A4 + M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xC) * 14;
    if (func_ov000_02187e50() == 1) return 0;
    value = M2C_FIELD(entry, u16 *, 8);
    bank = M2C_FIELD((u8 *)*gCurrentMap + (((u32)(value << 20) >> 26) * 4), s8 **, 0x52E8);
    if (bank[((u32)(value << 26) >> 26)] > 0) result = 1;
    else result = 0;
    return result;
}
#pragma opt_lifetimes reset
s32 func_ov000_02188a30(void) {
    return 1;
}

void func_ov000_02188a38(void) {
    extern void *gAiCommandState;
    extern s32 (*data_ov000_021df64c)(void);
    extern s32 (*data_ov000_021df648)(void);
    data_ov000_021df64c = (s32 (*)(void))func_ov000_021889ac;
    data_ov000_021df648 = func_ov000_02188a30;
    func_ov000_02187f7c();
    if (M2C_FIELD(gAiCommandState, u16 *, 8) & 8) func_ov000_02187e20();
    func_ov000_021884e4();
}

u8 CanDoAiAction789(s32 arg0, s32 arg1) {
    s32 func_ov000_02179ce4(void *);
    extern void **gCurrentMap;
    s32 offset;
    void *base, *table;
    u16 value;
    s8 *bank;
    u8 result;
    base = *gCurrentMap;
    table = (u8 *)base + 0x59A4;
    offset = M2C_FIELD(M2C_FIELD(base, void **, 0x52D0), u8 *, 0xD) * 14;
    FloodFillUnitRange(arg0, arg1, (u32)(M2C_FIELD(table, u8 *, offset) << 26) >> 26, func_ov000_02179ce4((u8 *)table + offset), 0);

    value = M2C_FIELD((u8 *)table + offset, u16 *, 8);
    if (((u32)(value << 26) >> 26) == 0x3F) return 0;

    bank = M2C_FIELD((u8 *)*gCurrentMap + (((u32)(value << 20) >> 26) * 4), s8 **, 0x52E8);
    if (bank[((u32)(value << 26) >> 26)] > 0) result = 1;
    else result = 0;
    return result;
}

#pragma push
#pragma opt_condition off
#pragma opt_strength_reduction off
/* Runs the AI action check for the unit's current state; if that action is not
 * possible, tries the fallback actions and records the state that can act. */
s32 TryUnitAiActions(s32 x, s32 y) {
    s32 IsFootUnitKind(s32);
    u8 CanDoFootAiAction(s32, s32);
    u8 CanDoAiAction01(s32, s32);
    u8 CanDoAiAction789(s32, s32);
    extern void **gCurrentMap;
    void *map, *unitBase;
    u8 *unit;
    s32 (*check)(s32, s32);
    s32 state;
    s32 result;

    map = *gCurrentMap;
    unitBase = (u8 *)map + MAP_UNIT_RECORDS;
    unit = (u8 *)unitBase + M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_NEXT_CARRIED) * MAP_UNIT_STRIDE;

    if (IsFootUnitKind(((u32)(unit[MAP_UNIT_KIND] << 26) >> 26)) != 0 || ((u32)(unit[MAP_UNIT_KIND] << 26) >> 26) == 0x0D) {
        check = (s32 (*)(s32, s32))CanDoFootAiAction;
    } else {
        state = ((u32)(unit[MAP_UNIT_AI_STATE] << 28) >> 28);
        switch (state) {
            case 0:
            case 1:
                check = (s32 (*)(s32, s32))CanDoAiAction01;
                break;
            case 2:
                check = (s32 (*)(s32, s32))CanDoAiAction2;
                break;
            case 3:
            case 4:
                check = (s32 (*)(s32, s32))CanDoAiAction34;
                break;
            case 5:
                check = (s32 (*)(s32, s32))CanDoAiAction5;
                break;
            case 7:
            case 8:
            case 9:
                check = (s32 (*)(s32, s32))CanDoAiAction789;
                break;
            default:
                check = 0;
                break;
        }
    }

    result = check(x, y);
    if (result == 1) return 1;

    state = ((u32)(unit[MAP_UNIT_AI_STATE] << 28) >> 28);
    switch (state) { case 7: case 8: case 9: return 0; default: break; }

    if (CanDoAiAction01(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)(unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    if (((s32 (*)(s32, s32))CanDoAiAction34)(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)((unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK) | 0x03);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    if (((s32 (*)(s32, s32))CanDoAiAction2)(x, y) == 1) {
        unit[MAP_UNIT_AI_STATE] = (u8)((unit[MAP_UNIT_AI_STATE] & ~MAP_UNIT_AI_STATE_MASK) | 0x02);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_X_MASK) | MAP_UNIT_TARGET_NONE);
        *(u16 *)(unit + MAP_UNIT_TARGET) = (u16)((*(u16 *)(unit + MAP_UNIT_TARGET) & ~MAP_UNIT_TARGET_Y_MASK) | MAP_UNIT_TARGET_Y_NONE);
        return 1;
    }
    return 0;
}
#pragma pop
