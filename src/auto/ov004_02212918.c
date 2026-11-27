/* 23 functions from 0x02212918 to 0x022138B0 (ov004), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
#include "ds3dsprite.h"
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
/* Clear/set bits of a u16 word of the current 3D sprite bank: DS3D_BANK_FLAGS
 * selects its flags word, DS3D_BANK_OAMATTR the 3D sprite's OBJ attributes. */
static inline void SpriteBankClearBits(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p&~mask;}
static inline void SpriteBankSetBits(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p|mask;}
/* Set the current 3D sprite's OBJ priority (DS3D_BANK_OAMATTR_PRIORITY). */
static inline void SpriteBankSetPriority(s32 n){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+DS3D_BANK_OAMATTR);*p=(*p&~DS3D_BANK_OAMATTR_PRIORITY)|(n<<6);}
/* Store a u16 into the current 3D sprite bank (the per-layer corner offsets). */
static inline void SpriteBankStore(s32 off,u16 n){M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,off)=n;}

/* Step the battle-start window on both screens: on the sub screen run the
 * opening's phases (split the sprite bank's cell rows apart, scroll its layers,
 * fade the palettes out and back in), and on both screens draw the day counter
 * and the top and bottom bars of the opening frame. */
void Ov004_UpdateBattleStartWindow(void *state){
s32 EaseInterpolate(s32,s16,s16,u16,s32);void StartPaletteFade(void *,s32);void StartPaletteFadeIn(void *,s32);void func_ov004_022124e0(s32,s32,s32,s32);void DrawWindowFrameBar(s32,s32,s32);
s32 saved,screen,engine,value;
saved=gCur3DSpriteEngine;
for(screen=0;screen<2;screen++){
engine=screen==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
if(engine==g3DSpriteEngineSub){
if(M2C_FIELD(state,u8 *,OV004_START_WINDOW_FADE_DELAY)!=0)M2C_FIELD(state,u8 *,OV004_START_WINDOW_FADE_DELAY)--;
else switch(M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)){
case 0:
SpriteBankSetPriority(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_ABOVE)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_BELOW)=OV004_START_WINDOW_ROWS;
SpriteBankClearBits(DS3D_BANK_OAMATTR,1);SpriteBankClearBits(DS3D_BANK_OAMATTR,2);SpriteBankClearBits(DS3D_BANK_OAMATTR,4);SpriteBankClearBits(DS3D_BANK_OAMATTR,8);SpriteBankSetBits(DS3D_BANK_OAMATTR,16);SpriteBankClearBits(DS3D_BANK_OAMATTR,32);SpriteBankClearBits(DS3D_BANK_OAMATTR,256);SpriteBankClearBits(DS3D_BANK_OAMATTR,512);SpriteBankClearBits(DS3D_BANK_OAMATTR,1024);SpriteBankSetBits(DS3D_BANK_OAMATTR,2048);SpriteBankClearBits(DS3D_BANK_OAMATTR,4096);SpriteBankClearBits(DS3D_BANK_OAMATTR,8192);
SpriteBankClearBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE0);SpriteBankClearBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE1);SpriteBankClearBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE2);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE3);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE4);
M2C_FIELD(state,u16 *,OV004_START_WINDOW_OPEN_FRAME)=0;M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)++;break;
case 1:
M2C_FIELD(state,u16 *,OV004_START_WINDOW_OPEN_FRAME)++;
value=EaseInterpolate(EASE_LINEAR,0,OV004_START_WINDOW_ROWS,M2C_FIELD(state,u16 *,OV004_START_WINDOW_OPEN_FRAME),OV004_START_WINDOW_EASE_FRAMES);
M2C_FIELD(state,u8 *,OV004_START_WINDOW_SLIT)=EaseInterpolate(EASE_LINEAR,0,OV004_START_WINDOW_SLIT_MAX,M2C_FIELD(state,u16 *,OV004_START_WINDOW_OPEN_FRAME),OV004_START_WINDOW_EASE_FRAMES);
SpriteBankSetPriority(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_ABOVE)=value;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_BELOW)=OV004_START_WINDOW_ROWS-value;
if(M2C_FIELD(state,u16 *,OV004_START_WINDOW_OPEN_FRAME)>=OV004_START_WINDOW_EASE_FRAMES){
SpriteBankSetPriority(0);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_ABOVE)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_BELOW)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_BLEND)=0;M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)++;
}break;
case 2:
SpriteBankClearBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE0);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE1);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE2);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE3);SpriteBankSetBits(DS3D_BANK_FLAGS,DS3D_BANK_MODE4);
SpriteBankSetPriority(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_ABOVE)=OV004_START_WINDOW_ROWS;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,DS3D_BANK_ROWS_BELOW)=OV004_START_WINDOW_ROWS;
SpriteBankClearBits(DS3D_BANK_OAMATTR,1);SpriteBankClearBits(DS3D_BANK_OAMATTR,2);SpriteBankSetBits(DS3D_BANK_OAMATTR,4);SpriteBankClearBits(DS3D_BANK_OAMATTR,8);SpriteBankClearBits(DS3D_BANK_OAMATTR,16);SpriteBankClearBits(DS3D_BANK_OAMATTR,32);SpriteBankClearBits(DS3D_BANK_OAMATTR,256);SpriteBankSetBits(DS3D_BANK_OAMATTR,512);SpriteBankClearBits(DS3D_BANK_OAMATTR,1024);SpriteBankClearBits(DS3D_BANK_OAMATTR,2048);SpriteBankClearBits(DS3D_BANK_OAMATTR,4096);SpriteBankClearBits(DS3D_BANK_OAMATTR,8192);
StartPaletteFade(M2C_FIELD(state,void **,OV004_START_WINDOW_FADE_SUB),OV004_START_WINDOW_PALETTE_FRAMES);M2C_FIELD(state,u8 *,OV004_START_WINDOW_FADE_DELAY)=OV004_START_WINDOW_EASE_FRAMES;M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)++;break;
case 3:
StartPaletteFade(M2C_FIELD(state,void **,OV004_START_WINDOW_FADE_MAIN),OV004_START_WINDOW_PALETTE_FRAMES);M2C_FIELD(state,u8 *,OV004_START_WINDOW_FADE_DELAY)=OV004_START_WINDOW_EASE_FRAMES;M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)++;break;
case 4:
StartPaletteFadeIn(M2C_FIELD(state,void **,OV004_START_WINDOW_FADE_SUB),OV004_START_WINDOW_PALETTE_FRAMES);M2C_FIELD(state,u8 *,OV004_START_WINDOW_PHASE)++;break;
}
SpriteBankStore(DS3D_BANK_CORNER_Y(0),0);SpriteBankStore(DS3D_BANK_CORNER_Y(2),0xffb0);SpriteBankStore(DS3D_BANK_CORNER_X(1),0);SpriteBankStore(DS3D_BANK_CORNER_X(3),0xffb0);
SpriteBankStore(DS3D_BANK_CORNER_Y(1),(u8)(M2C_FIELD(state,u16 *,OV004_START_WINDOW_FRAME)>>1));SpriteBankStore(DS3D_BANK_CORNER_Y(3),0);
func_ov004_022124e0(80,56,0,M2C_FIELD(state,u8 *,OV004_START_WINDOW_DAY));
DrawWindowFrameBar(32,96-M2C_FIELD(state,u8 *,OV004_START_WINDOW_SLIT),0);DrawWindowFrameBar(32,96+M2C_FIELD(state,u8 *,OV004_START_WINDOW_SLIT),0);
}}
gCur3DSpriteEngine=saved;M2C_FIELD(state,u16 *,OV004_START_WINDOW_FRAME)++;
}

void func_ov004_022130f4(void) {
    M2C_UNK func_ov004_022120c0();
    func_ov004_022120c0();
}

void func_ov004_02213100(void) {
    M2C_UNK ResetSub3DSpriteBankState();
    ResetSub3DSpriteBankState();
}

void func_ov004_0221310c(void) {
    void Ov004_UpdateBattleStartWindow();
    Ov004_UpdateBattleStartWindow();
}

void func_ov004_02213118(void) {
    M2C_UNK WaitForInputOrTimeout();
    WaitForInputOrTimeout();
}

/* Spawn the battle-start window sprite that plays the ov004 opening animation. */
void Ov004_CreateBattleStartWindow(s32 owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gOv004BattleStartWindowClass;
    CreateSpriteObject(&gOv004BattleStartWindowClass, owner);
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

/* Mission condition: from the second turn on, true while the map cursor is on
 * tile (11,6). */
s32 IsCursorOnTileAfterFirstTurn(void) {
 extern void **gCurrentMap;
 void *map;
 s32 turn;
 s16 cursorX, cursorY;
 map = *gCurrentMap;
 turn = M2C_FIELD(map, u16 *, MAP_TURN);
 if (turn < 2) return 0;
 cursorX = M2C_FIELD(map, s16 *, MAP_CURSOR_X);
 cursorY = M2C_FIELD(map, s16 *, MAP_CURSOR_Y);
 return cursorX == 11 && cursorY == 6;
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

/* Battle-script condition: true when a unit stands on tile (5,5) and its HP
 * (the low seven bits of the unit record's health word) is 90 or below. */
u8 IsUnitOnTileFiveFiveWounded(void) {
    extern void **gCurrentMap;
    u8 unitId;
    u8 wounded;
    void *map;

    map = *gCurrentMap;
    unitId = M2C_FIELD((map + (M2C_FIELD(map, u16 *, MAP_ROW_OFFSETS + 5 * 2) + 5)), u8 *, MAP_CELL_UNIT_ID);
    if (unitId == 0) {
        return 0U;
    }
    if ((u32) ((u32) (M2C_FIELD(((unitId * MAP_UNIT_STRIDE) + (s32) map), u16 *, MAP_UNIT_RECORDS + MAP_UNIT_HEALTH) << 0x19) >> 0x19) <= 0x5AU) {
        wounded = 1;
    } else {
        wounded = 0;
    }
    return wounded;
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

/* Mission condition: true when the viewing player is player 1, player 1 owns the
 * property on tile (3, 6), and no unit is visible on that tile. */
s32 IsPlayerOnePropertyThreeSixUndefended(void) {
    extern void **gCurrentMap;
    u8 *base;
    u32 cell;
    u8 terrain;

    base = *gCurrentMap;
    if (M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER) == 1) {
        cell = M2C_FIELD(base, u16 *, MAP_ROW_OFFSETS + 6 * 2) + 3; /* tile (3, 6) */
        terrain = (base + cell)[MAP_CELL_TERRAIN];
        if (((s32)(terrain & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT) == 1) {
            if (base[cell] == 0) return 1; /* MAP_CELL_VISIBLE_UNIT */
        }
    }
    return 0;
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

/* Battle-script condition: true while event flag 1 is set (the construction menu
 * uses it to allow a facility on map 0xa5 once the mission raised the flag). */
u8 Ov004_IsEventFlag1Set(void) {
    s32 IsEventFlagSet(M2C_UNK);
    u8 flagSet;

    if (IsEventFlagSet(1) != 0) {
        flagSet = 1;
    } else {
        flagSet = 0;
    }
    return flagSet;
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

