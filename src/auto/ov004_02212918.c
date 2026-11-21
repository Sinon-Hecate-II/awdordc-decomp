/* 23 functions from 0x02212918 to 0x022138B0 (ov004), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
static inline void Clear129(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p&~mask;}
static inline void Set129(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p|mask;}
static inline void Blend129(s32 n){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18);*p=(*p&~0xc0)|(n<<6);}
static inline void Store129(s32 off,u16 n){M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,off)=n;}

void func_ov004_02212918(void *state){
s32 EaseInterpolate(s32,s16,s16,u16,s32);void StartPaletteFade(void *,s32);void StartPaletteFadeIn(void *,s32);void func_ov004_022124e0(s32,s32,s32,s32);void DrawWindowFrameBar(s32,s32,s32);
s32 saved,screen,engine,value;
saved=gCur3DSpriteEngine;
for(screen=0;screen<2;screen++){
engine=screen==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
if(engine==g3DSpriteEngineSub){
if(M2C_FIELD(state,u8 *,0x3d)!=0)M2C_FIELD(state,u8 *,0x3d)--;
else switch(M2C_FIELD(state,u8 *,0x3b)){
case 0:
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16;
Clear129(18,1);Clear129(18,2);Clear129(18,4);Clear129(18,8);Set129(18,16);Clear129(18,32);Clear129(18,256);Clear129(18,512);Clear129(18,1024);Set129(18,2048);Clear129(18,4096);Clear129(18,8192);
Clear129(0,16);Clear129(0,32);Clear129(0,64);Set129(0,128);Set129(0,256);
M2C_FIELD(state,u16 *,0x34)=0;M2C_FIELD(state,u8 *,0x3b)++;break;
case 1:
M2C_FIELD(state,u16 *,0x34)++;
value=EaseInterpolate(0,0,16,M2C_FIELD(state,u16 *,0x34),16);
M2C_FIELD(state,u8 *,0x3c)=EaseInterpolate(0,0,20,M2C_FIELD(state,u16 *,0x34),16);
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=value;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16-value;
if(M2C_FIELD(state,u16 *,0x34)>=16){
Blend129(0);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;M2C_FIELD(state,u8 *,0x3b)++;
}break;
case 2:
Clear129(0,16);Set129(0,32);Set129(0,64);Set129(0,128);Set129(0,256);
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=16;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16;
Clear129(18,1);Clear129(18,2);Set129(18,4);Clear129(18,8);Clear129(18,16);Clear129(18,32);Clear129(18,256);Set129(18,512);Clear129(18,1024);Clear129(18,2048);Clear129(18,4096);Clear129(18,8192);
StartPaletteFade(M2C_FIELD(state,void **,0x44),32);M2C_FIELD(state,u8 *,0x3d)=16;M2C_FIELD(state,u8 *,0x3b)++;break;
case 3:
StartPaletteFade(M2C_FIELD(state,void **,0x40),32);M2C_FIELD(state,u8 *,0x3d)=16;M2C_FIELD(state,u8 *,0x3b)++;break;
case 4:
StartPaletteFadeIn(M2C_FIELD(state,void **,0x44),32);M2C_FIELD(state,u8 *,0x3b)++;break;
}
Store129(0x3a,0);Store129(0x42,0xffb0);Store129(0x3c,0);Store129(0x44,0xffb0);
Store129(0x3e,(u8)(M2C_FIELD(state,u16 *,0x36)>>1));Store129(0x46,0);
func_ov004_022124e0(80,56,0,M2C_FIELD(state,u8 *,0x3a));
DrawWindowFrameBar(32,96-M2C_FIELD(state,u8 *,0x3c),0);DrawWindowFrameBar(32,96+M2C_FIELD(state,u8 *,0x3c),0);
}}
gCur3DSpriteEngine=saved;M2C_FIELD(state,u16 *,0x36)++;
}

void func_ov004_022130f4(void) {
    M2C_UNK func_ov004_022120c0();
    func_ov004_022120c0();
}

void func_ov004_02213100(void) {
    M2C_UNK func_ov004_0221285c();
    func_ov004_0221285c();
}

void func_ov004_0221310c(void) {
    void func_ov004_02212918();
    func_ov004_02212918();
}

void func_ov004_02213118(void) {
    M2C_UNK WaitForInputOrTimeout();
    WaitForInputOrTimeout();
}

void func_ov004_02213124(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_02218da8;
    CreateSpriteObject(&data_ov004_02218da8, arg0);
}

/* Check whether any of player one's active unit records has a nonzero rank. */
s32 HasPlayerOneUnitWithRank(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitId;
    s32 unitAddress;
    s32 endId;
    BattleMapUnitKindRank *unit;

    unitId = gPlayerUnitIdBase[1] + 1;
    endId = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unitAddress = (s32)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            unit = (BattleMapUnitKindRank *)unitAddress;
            if (unit->kind && unit->rank) {
                return 1;
            }
            unitId++;
            unitAddress += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    return 0;
}

/* Battle-script condition: true while player 1 has a unit at 90 HP or below,
 * i.e. one of its units has been damaged.  (The same check as
 * IsPlayerOneUnitWounded; the mission script lists it under a second id.) */
s32 IsPlayerOneUnitUnder90Hp(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    u32 kind;
    s32 unitId;
    u8 *unit;
    s32 endId;

    unitId = gPlayerUnitIdBase[1] + 1;
    endId = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kind = (u32)(*unit << 26) >> 26;
            if (kind && ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25) <= 90U) return 1;
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    return 0;
}

s32 func_ov004_0221322c(void) {
 extern void **gCurrentMap;
 void *p;
 s32 n;
 s16 x, y;
 p = *gCurrentMap;
 n = M2C_FIELD(p, u16 *, 0x52A2);
 if (n < 2) return 0;
 x = M2C_FIELD(p, s16 *, 0x52DC);
 y = M2C_FIELD(p, s16 *, 0x52DE);
 return x == 11 && y == 6;
}

/* Mission condition: from the second turn on, true while any unit of player 1
 * stands on tile (11,6). */
s32 IsPlayerOneUnitOnTileAfterFirstTurn(void) {
    extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
    s32 i; u8 *unit; s32 end; u8 *map;
    map = (u8 *) *gCurrentMap;
    if ((s32) M2C_FIELD(map, u16 *, MAP_TURN) < 2) return 0;
    i = gPlayerUnitIdBase[1] + 1; end = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        unit = map + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            if (((u32) (unit[MAP_UNIT_KIND] << 26) >> 26) && unit[MAP_UNIT_X] == 11 && unit[MAP_UNIT_Y] == 6) return 1;
            i++; unit += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    return 0;
}

/* Mission condition: true while player 1 still has a mech (kind 2) at 70 HP or
 * below, i.e. one of its mechs has been damaged. */
s32 IsPlayerOneMechWounded(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    u32 kind;
    s32 unitId;
    u8 *unit;
    s32 endId;

    unitId = gPlayerUnitIdBase[1] + 1;
    endId = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kind = (u32)(*unit << 26) >> 26;
            if (kind && ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25) <= 70U && kind == UNIT_KIND_MECH) return 1;
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    return 0;
}

/* Mission condition: true while player 1 still has a tank (kind 7) at 70 HP or
 * below, i.e. one of its tanks has been damaged. */
s32 IsPlayerOneTankWounded(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    u32 kind;
    s32 unitId;
    u8 *unit;
    s32 endId;

    unitId = gPlayerUnitIdBase[1] + 1;
    endId = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kind = (u32)(*unit << 26) >> 26;
            if (kind && ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25) <= 70U && kind == UNIT_KIND_TANK) return 1;
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    return 0;
}

u8 func_ov004_02213404(void) {
    extern void **gCurrentMap;
    u8 temp_r1;
    u8 var_r0;
    void *temp_r2;

    temp_r2 = *gCurrentMap;
    temp_r1 = M2C_FIELD((temp_r2 + (M2C_FIELD(temp_r2, u16 *, 0x3762) + 5)), u8 *, 0x508);
    if (temp_r1 == 0) {
        return 0U;
    }
    if ((u32) ((u32) (M2C_FIELD(((temp_r1 * 0xE) + (s32) temp_r2), u16 *, 0x59AA) << 0x19) >> 0x19) <= 0x5AU) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 PlayerTwoHasFiveOrFewerUnits(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount;
    s32 unitId;
    u8 *unit;
    s32 endId;
    u8 kindAndRank;

    /* Battle-script condition: count player two's active units and accept five or fewer. */
    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + 0x33;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + 0x59A4 + unitId * 14;
        do {
            kindAndRank = *unit;
            if ((u32)(kindAndRank << 26) >> 26) unitCount++;
            unitId++;
            unit += 14;
        } while (unitId < endId);
    }
    if (unitCount <= 4) return 1;
    return 0;
}

/* Mission condition: holds while the battle is still on its first turn and no
 * infantry unit (kind 1) of player 1 stands in the top five map rows (y <= 5). */
s32 func_ov004_022134d0(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 result;
    u32 kind;
    s32 i;
    u8 *unit;
    s32 end;
    u8 *base;

    result = 1;
    base = (u8 *) *gCurrentMap;
    if ((s32) M2C_FIELD(base, u16 *, MAP_TURN) > 1) return 0;
    i = gPlayerUnitIdBase[1] + 1;
    end = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        unit = base + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            kind = (u32) (*unit << 26) >> 26;
            if (kind && kind == 1 && M2C_FIELD(unit, u8 *, MAP_UNIT_Y) <= 5U) result = 0;
            i++;
            unit += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    return result;
}

/* Battle-script condition: true when the AI's standing command is a unit build
 * (kind 3) and its cursor sits on a city owned by player 1. */
s32 IsAiBuildingOnPlayerOneCity(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    u8 terrain;
    u8 *p;
    u8 *base;
    u8 x, y;

    base = *gCurrentMap;
    p = M2C_FIELD(base, u8 **, MAP_CURSOR_UNIT);
    x = p[MAP_UNIT_X]; y = p[MAP_UNIT_Y];
    if (gAiCommand == AI_COMMAND_PRODUCE_UNIT) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS));
        terrain = p[MAP_CELL_TERRAIN];
        if (((s32)(terrain & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT) == 1 &&
            (terrain & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_CITY) return 1;
    }
    return 0;
}

/* Battle-script condition: true when the AI's standing command is a unit build
 * (kind 3) and its cursor sits on a base owned by player 1. */
s32 IsAiBuildingOnPlayerOneBase(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    u8 terrain, *p, *base, x, y;

    base = *gCurrentMap;
    p = M2C_FIELD(base, u8 **, MAP_CURSOR_UNIT);
    x = p[MAP_UNIT_X]; y = p[MAP_UNIT_Y];
    if (gAiCommand == AI_COMMAND_PRODUCE_UNIT) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS));
        terrain = p[MAP_CELL_TERRAIN];
        if (((s32)(terrain & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT) == 1 &&
            (terrain & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_BASE) return 1;
    }
    return 0;
}

/* Battle-script condition: true when player 1 is the current player and the AI's
 * standing command is a unit build (kind 3) whose cursor sits on any base. */
s32 IsAiBuildingOnBaseOnPlayerOneTurn(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    u8 terrain, *p, *base, x, y;

    base = *gCurrentMap;
    p = M2C_FIELD(base, u8 **, MAP_CURSOR_UNIT);
    x = p[MAP_UNIT_X]; y = p[MAP_UNIT_Y];
    if (gAiCommand == AI_COMMAND_PRODUCE_UNIT && M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER) == 1) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS));
        terrain = p[MAP_CELL_TERRAIN];
        if ((terrain & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_BASE) return 1;
    }
    return 0;
}

/* Mission condition: true while player 1 has a unit at 90 HP or below, i.e. one
 * of its units has been damaged. */
s32 IsPlayerOneUnitWounded(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    u32 kind;
    s32 unitId;
    u8 *unit;
    s32 endId;

    unitId = gPlayerUnitIdBase[1] + 1;
    endId = gPlayerUnitIdBase[1] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kind = (u32)(*unit << 26) >> 26;
            if (kind && ((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 25) >> 25) <= 90U) return 1;
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    return 0;
}

s32 func_ov004_0221373c(void) {
extern void **gCurrentMap;
u8 *base; u32 i; u8 v;
base=*gCurrentMap;
if(M2C_FIELD(base,u16 *,0x52a4)==1) {
i=M2C_FIELD(base,u16 *,0x3764)+3;
v=(base+i)[0x1420];
if(((s32)(v&0xe0)>>5)==1) {if(base[i]==0)return 1;}
}return 0;
}

/* Battle-script condition: true while event flag 0 is clear and player 2 has no
 * live units (none of its unit slots base+1 .. base+MAP_UNIT_GROUP_SCAN holds a
 * kind).  The flag-gated twin of IsPlayerTwoDefeated. */
s32 IsPlayerTwoDefeatedFlagClear(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count, i, end;
    u8 *unit, kind;
    count = 0;
    if (IsEventFlagSet(0)) return count;
    i = gPlayerUnitIdBase[2] + 1;
    end = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            kind = *unit;
            if ((u32)(kind << 26) >> 26) count++;
            i++;
            unit += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    if (count != 0) return 0;
    return 1;
}

u8 func_ov004_02213820(void) {
    s32 IsEventFlagSet(M2C_UNK);
    u8 var_r0;

    if (IsEventFlagSet(1) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Battle-script condition that succeeds when player 2 has no units: counts the
 * occupied records of its unit group (ids gPlayerUnitIdBase[2]+1 .. +MAP_UNIT_GROUP_SCAN). */
s32 Ov004_IsPlayerTwoArmyEmpty_02213840(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount;
    s32 unitId;
    u8 *unit;
    s32 endId;
    u8 kindAndRank;

    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kindAndRank = unit[MAP_UNIT_KIND];
            if ((u32)(kindAndRank << 26) >> 26) {
                unitCount++;
            }
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    if (unitCount != 0) {
        return 0;
    }
    return 1;
}

