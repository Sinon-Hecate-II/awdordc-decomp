/* 27 functions from 0x0209EAF4 to 0x0209F990 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "ov000_ai.h"
typedef struct MapConfigRecord {
    u16 flags;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    s32 unk_8;
    s32 unk_C;
} MapConfigRecord;
typedef struct { s16 a,b,c,d; } Unk09Position;
typedef struct { s32 unk; Unk09Position *p; s32 count; } Unk09List;

void func_0209eaf4(s32 x,s32 y,s32 a){
extern void **gCurrentMap;extern M2C_UNK gBattleCommand;extern M2C_UNK gBattlePreviewPanelDef;
s32 GetRandomSeed(s32,s32,s32);void func_020d1690(u8,s32,void *);void *CreateSpriteFromClass(void *,s32);
s32 base;void *p;s32 v,n;u32 b; s32 result;
result=GetRandomSeed(x,y,a);
p=(void *)gCurrentMap;
M2C_FIELD(&gBattleCommand,s32 *,8)=result;
base=M2C_FIELD((s32)p,s32 *,0);
func_020d1690(M2C_FIELD(base,u8 *,0x52d4),1,(void *)(base+0x52dc));
base=(s32)*gCurrentMap;
b=M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),u8 *,0x539c);
n=M2C_FIELD(base,s16 *,0x6ed4);
v=b&127;
if(v<n)v=0;else v-=n;
M2C_FIELD(base+(x+M2C_FIELD((u32)base+(u32)y*2,u16 *,0x3758)),u8 *,0x539c)=v|(b&128);
p=CreateSpriteFromClass(&gBattlePreviewPanelDef,7);
M2C_FIELD(p,s32 *,0x5c)=M2C_FIELD(*gCurrentMap,s32 *,0x52d0);
M2C_FIELD(p,s32 *,0x60)=a;M2C_FIELD(p,s32 *,0x34)=0;M2C_FIELD(p,s32 *,0x38)=x;M2C_FIELD(p,s32 *,0x3c)=y;
}

/* Battle-preview panel step: keep the map view scrolled onto the tile the panel
 * previews, except while the battle-end screen is up (the battle has ended and
 * the map is in MAP_STATE 19). */
void StepBattlePreviewPanel(void *panel) {
    extern M2C_UNK gBattleEndState;
    extern void **gCurrentMap;
    u32 scrollEnabled;
    if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED)) {
        if (M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED)) scrollEnabled = M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) != 19; else scrollEnabled = 0;
        if (!(scrollEnabled & 0xFF)) return;
    }
    StepMapViewToTile(M2C_FIELD(panel, s32 *, BATTLE_PREVIEW_X), M2C_FIELD(panel, s32 *, BATTLE_PREVIEW_Y));
}

/* Gives the battle preview panel its graphic: the sprite of the unit under the
 * cursor when it previews a unit, otherwise the sprite of the tile itself.
 * Previewing a plain tile (one without destructible-terrain HP) is counted in
 * the records when the current player is human. */
void InitBattlePreviewSprite(void *panel) {
    extern void **gCurrentMap;
    void *unit = M2C_FIELD(panel, void **, 0x34);
    u32 hp;
    s32 map;
    u32 rowOffset;
    u8 *cell;

    if (unit) {
        CreateFeaturePreviewSprite(unit, panel);
        hp = M2C_FIELD(unit, u8 *, 4);
    } else {
        CreateTilePreviewSprite(M2C_FIELD(panel, s32 *, 0x38), M2C_FIELD(panel, s32 *, 0x3c), panel);
        map = (s32)*gCurrentMap;
        rowOffset = M2C_FIELD(map + M2C_FIELD(panel, s32 *, 0x3c) * 2, u16 *, MAP_ROW_OFFSETS);
        cell = (u8 *)(M2C_FIELD(panel, s32 *, 0x38) + map);
        hp = M2C_FIELD(rowOffset + cell, u8 *, MAP_CELL_TERRAIN_HP) & MAP_CELL_TERRAIN_HP_MASK;
    }
    if (hp == 0 && unit == 0) {
        if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER))) AddRecordValue(31, 1);
    }
}

void func_0209ecf0(s32 arg0, s32 arg1) {
    void RunBattleIfTarget(u8, s32, void *);
    s32 Divide(s32, s32);
    s32 GetMoveRangeCommanderId(s32, s32, s32);
    void AddCoPowerMeterPointsIfEnabled(s32, s32);
    s16 GetCoPowerMeterPoints(s32);
    s32 func_020cd614(void);
    void *CreateSpriteFromClass(void *, s32);
    s32 SetMapCommandPending(void);
    void BattleUpdateUnitCursor(void);
    extern void **gCurrentMap;
    extern M2C_UNK gBattleCommand;
    extern M2C_UNK gBattlePreviewFullDef;
    extern M2C_UNK gBattlePreviewMapDef;

    u8 selectedBucket;
    s32 unitBucket;
    void *p;
    s32 player;
    BattleMapUnitHead *unitPtr;
    BattleMapUnitHead *selected;
    u8 *map = *gCurrentMap;
    unitPtr = (BattleMapUnitHead *)(map + MAP_UNIT_RECORDS) + arg0;
    selected = M2C_FIELD(map, BattleMapUnitHead **, MAP_CURSOR_UNIT);

    if (selected) {
        s32 index;
        if (!selected) index = 0;
        else index = ((u8 *)selected - (map + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        player = (index >> 6) + 1;
    } else player = 0;
    selectedBucket = player;

    if (unitPtr) {
        s32 index;
        if (!unitPtr) index = 0;
        else index = ((u8 *)unitPtr - (map + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        player = (index >> 6) + 1;
    } else player = 0;
    unitBucket = (u8)player;

    if (arg0 == 0) {
        BattleMapUnitHead *sel = M2C_FIELD(map + 0x5000, BattleMapUnitHead * volatile *, 0x2d0);
        sel->ammo = (u16)(sel->ammo + 0xffff);
        (void)SetMapCommandPending();
        BattleUpdateUnitCursor();
        return;
    }

    {
        s32 seed = GetRandomSeed();
        void **mapHandle = gCurrentMap;
        M2C_FIELD(&gBattleCommand, s32 *, 0x8) = seed;
        map = *mapHandle;
        RunBattleIfTarget(M2C_FIELD(map, u8 *, 0x52d4), arg0, map + 0x52dc);
    }

    {
        register void ***mapGlobal = &gCurrentMap;
        s32 playerOffset = selectedBucket * 0x8c;
        u8 *record;
        s32 value;
        map = **mapGlobal;
        record = map + 0x67a4 + playerOffset;
        value = M2C_FIELD(record, s32 *, 0x74) + M2C_FIELD(map, s16 *, 0x6ed4);
        if (value < 0x0fffffff && M2C_FIELD(record, s32 *, 0x78) < 0x0fffffff) {
            M2C_FIELD(record, s32 *, 0x74) = value;
            record = (u8 *)**mapGlobal + 0x67a4 + playerOffset;
            M2C_FIELD(record, s32 *, 0x78)++;
            map = **mapGlobal;
            if (M2C_FIELD(map, s16 *, 0x6ee6) == 0) {
                record = map + 0x67a4 + playerOffset;
                M2C_FIELD(record, s32 *, 0x7c) += M2C_FIELD(map, s16 *, 0x6ed4);
                record = (u8 *)**mapGlobal + 0x67a4 + playerOffset;
                M2C_FIELD(record, s32 *, 0x80)++;
            }
        }
    }

    {
        s16 globalW = M2C_FIELD(*gCurrentMap, s16 *, 0x6ec6);
        s32 globalRng = (globalW == 0) ? 0 : Divide(globalW - 1, 10) + 1;
        s32 selLow7 = M2C_FIELD(*gCurrentMap, BattleMapUnitHead **, MAP_CURSOR_UNIT)->health;
        s32 selRng = (selLow7 == 0) ? 0 : Divide(selLow7 - 1, 10) + 1;
        s32 sdiff = selRng - globalRng;
        s16 baseW = M2C_FIELD(*gCurrentMap, s16 *, 0x6ee6);
        s32 baseRng = (baseW == 0) ? 0 : Divide(baseW - 1, 10) + 1;
        s32 unitLow7 = unitPtr->health;
        s32 unitRng = (unitLow7 == 0) ? 0 : Divide(unitLow7 - 1, 10) + 1;

        s32 udiff = unitRng - baseRng;

        if (GetMoveRangeCommanderId(selectedBucket, M2C_FIELD(*gCurrentMap, s16 *, 0x52dc), M2C_FIELD(*gCurrentMap, s16 *, 0x52de)) != -1) AddCoPowerMeterPointsIfEnabled(selectedBucket, udiff);
        if (GetMoveRangeCommanderId(unitBucket, M2C_FIELD(*gCurrentMap, s16 *, 0x52dc), M2C_FIELD(*gCurrentMap, s16 *, 0x52de)) != -1) AddCoPowerMeterPointsIfEnabled(unitBucket, sdiff);
    }

    {
        u8 *side = (u8 *)*gCurrentMap + 0x6eb8;
        M2C_FIELD(side, s16 *, 0x12) = GetCoPowerMeterPoints(selectedBucket);
        side = (u8 *)*gCurrentMap + 0x6ed8;
        M2C_FIELD(side, s16 *, 0x12) = GetCoPowerMeterPoints(unitBucket);
    }

    if (func_020cd614()) p = CreateSpriteFromClass(&gBattlePreviewFullDef, 7);
    else p = CreateSpriteFromClass(&gBattlePreviewMapDef, 7);
    M2C_FIELD(p, s32 *, 0x60) = arg1;
    M2C_FIELD(p, void **, 0x34) = unitPtr;
    M2C_FIELD(p, s32 *, 0x38) = (s32)M2C_FIELD(unitPtr, u8 *, 0x1);
    M2C_FIELD(p, s32 *, 0x3c) = (s32)M2C_FIELD(unitPtr, u8 *, 0x2);
}

/* Orders two units for a battle preview: first by tile y, and for units on the
 * same row by their owner's HQ tile x (the low seven bits, bit 7 marks no HQ).
 * Returns 1 when unit a is drawn before unit b. */
s32 IsUnitDrawnBefore(u8 *a,u8 *b){
extern void **gCurrentMap;s32 i,j;u8 *p,*q,*base;
if(a[1]>b[1])return 1;
if(a[1]==b[1]){
if(b)i=(b-((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;else i=0;
base=*gCurrentMap;
q=base+MAP_PLAYER_STATES+((i>>6)+1)*MAP_PLAYER_STRIDE;
if(a)j=(a-(base+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;else j=0;
p=base+MAP_PLAYER_STATES+((j>>6)+1)*MAP_PLAYER_STRIDE;
if((p[0x2b]&127)>(q[0x2b]&127))return 1;
}
return 0;
}

/* Start the battle preview animation of `preview`: the cursor unit and the
 * preview's target unit become the attacker and defender records, the one drawn
 * first taking the attacker side; then the battle scene sprite is created. */
void StartBattlePreview(void *preview) {
    extern void **gCurrentMap;
    void *target = M2C_FIELD(preview, void **, 0x34);
    u8 *base;
    if (!IsUnitDrawnBefore(M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT), target)) {
        base = *gCurrentMap;
        SetupBattleAnimation(M2C_FIELD(base, s32 *, MAP_CURSOR_UNIT), target, base + MAP_BATTLE_ATTACKER, base + MAP_BATTLE_DEFENDER);
    } else {
        base = *gCurrentMap;
        SetupBattleAnimation(target, M2C_FIELD(base, s32 *, MAP_CURSOR_UNIT), base + MAP_BATTLE_DEFENDER, base + MAP_BATTLE_ATTACKER);
    }
    CreateBattleSceneSprite(preview);
}

/* Clear the sub (top) screen's 3D sprite bank master brightness, returning it to
 * normal after a fade. */
void ResetSubScreenBrightness(void) {
    extern void *g3DSpriteBankSub;
    M2C_FIELD(g3DSpriteBankSub, s8 *, DS3D_BANK_BRIGHTNESS) = 0;
}

/* Run the map's staged battle event: hand its recorded attacker and defender
 * (MAP_BATTLE_ATTACKER / MAP_BATTLE_DEFENDER) to RunBattleEvent. */
void RunStagedBattleEvent(void) {
    extern void **gCurrentMap;
    void RunBattleEvent(s32, s32);
    u8 *battle = (u8 *)*gCurrentMap + 0x6000;
    RunBattleEvent(M2C_FIELD(battle, s32 *, MAP_BATTLE_ATTACKER - 0x6000), M2C_FIELD(battle, s32 *, MAP_BATTLE_DEFENDER - 0x6000));
}

void func_0209f260(void) {
    M2C_UNK FadeMusicToHalfVolume();
    FadeMusicToHalfVolume();
}

void func_0209f26c(void) {
    M2C_UNK FadeMusicToFullVolume();
    FadeMusicToFullVolume();
}

/* Rebuild the battle map's presentation after its data changed: run the
 * map-view controller's restore callback, then reset the 3D sprite engine's
 * queues and status flags. */
void RestoreBattleMapPresentation(void) {
    extern void **gCurrentMap;
    void (*restoreView)(void) = M2C_FIELD(gCurrentMap[MAPVIEW_CONTROLLER_INDEX], void (**)(void), MAPVIEW_RESTORE_CB);
    if (restoreView) restoreView();
    InitBattleMapPresentation();
    Reset3DSpriteEngineState();
}

/* Refresh the map view and mark a map command pending. */
void RefreshMapViewAndQueueCommand(void) {
    M2C_UNK SetMapCommandPending();
    M2C_UNK RefreshMapView();
    RefreshMapView();
    SetMapCommandPending();
}

/* Order the battle command for the target the cursor has selected: the battle
 * cursor is saved around the unit-cursor refresh, then, when the preview is armed
 * to issue a command, the command attacks the unit the selected cursor option names. */
void BattlePreviewAttackTarget(void *preview) {
    void *GetTargetPosition(s32);
    extern s32 gMapCursorOptionValue;
    extern void **gCurrentMap;
    void SetBattleCommand(s32, u8, s32, s32);
    u16 *target;

    SaveBattleCursorPosition();
    BattleUpdateUnitCursor();
    RestoreBattleCursorPosition();
    if (!M2C_FIELD(preview, s32 *, BATTLE_PREVIEW_ARMED)) return;
    target = GetTargetPosition(gMapCursorOptionValue);
    SetBattleCommand(AI_COMMAND_ATTACK_TARGET, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), target[0], 0);
}

/* Order the battle command for the tile the preview panel shows: the battle cursor
 * is saved around the unit-cursor refresh, then, when the preview is armed to issue
 * a command, the command attacks the panel's own tile. */
void BattlePreviewAttackTile(void *preview) {
    extern void **gCurrentMap;
    void SetBattleCommand(s32, u8, s32, s32);

    SaveBattleCursorPosition();
    BattleUpdateUnitCursor();
    RestoreBattleCursorPosition();
    if (!M2C_FIELD(preview, s32 *, BATTLE_PREVIEW_ARMED)) return;
    SetBattleCommand(AI_COMMAND_ATTACK_TILE, M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), M2C_FIELD(preview, s32 *, BATTLE_PREVIEW_X), M2C_FIELD(preview, s32 *, BATTLE_PREVIEW_Y));
}

/* Run the map cursor-unit script event for the unit under the cursor. */
void RunSelectedCursorUnitEvent(void) {
    M2C_UNK RunCursorUnitEvent(s32);
    extern void **gCurrentMap;
    RunCursorUnitEvent(M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT));
}

void func_0209f384(void) {

}

void func_0209f388(void) {

}

void func_0209f38c(void) {

}

/* Battle start-up: copy players 1-4 out of the map's data record into the
   per-player setup tables, copy the record's rule values into the battle
   config, then set the map's battle/tileset flags. */
void InitBattleMapConfig(void) {
    extern void **gCurrentMap;
    extern MapConfigRecord gMapConfig;
    void ResetPlayerSetupTables(void);
    s32 GetMapPlayerCoId(s32,s32); s32 GetMapPlayerArmyId(s32,s32); s32 GetMapPlayerId(s32,s32); s32 GetMapPlayerFlags(s32,s32);
    void SetPlayerCoId(s32,s32); void SetPlayerArmyId(s32,s32); void SetPlayerIdForSlot(s32,s32); void SetPlayerTeam(s32,s32);
    s32 MapData_IsFogOfWar(s32); s32 MapData_GetBattleSetting(s32); s32 MapData_GetMapValue(s32); s32 MapData_GetValueLimitLow(s32); s32 MapData_GetValueLimitHigh(s32); s32 func_020a8a04(s32);
    void func_020a88c4(s32); void SetMapWeather(void); s32 MapData_GetTileset(s32);
    s32 player, value, fieldA, fieldB, playerFlags, team;
    u8 *base;
    s32 setting;
    void **map;

    ResetPlayerSetupTables();
    for (player = 1; player < 5; player++) {
        value = GetMapPlayerCoId(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
        fieldA = GetMapPlayerArmyId(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
        fieldB = GetMapPlayerId(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
        playerFlags = GetMapPlayerFlags(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
        switch (value) {
        case 0: SetPlayerCoId(player, 0); break;
        case 15: break;
        default: SetPlayerCoId(player, value); break;
        }
        SetPlayerArmyId(player, fieldA);
        SetPlayerIdForSlot(player, fieldB);
        if (playerFlags & 0x80) team = 1;
        else team = (player != 1) ? 2 : 1;
        SetPlayerTeam(player, team);
    }
    if (MapData_IsFogOfWar(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID)) != 0) M2C_FIELD(*gCurrentMap, u8 *, 0x5156) = 1;
    setting = MapData_GetBattleSetting(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    gMapConfig.unk_3 = setting;
    setting = MapData_GetMapValue(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    gMapConfig.unk_4 = setting;
    setting = MapData_GetValueLimitLow(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    gMapConfig.unk_8 = setting;
    setting = MapData_GetValueLimitHigh(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    gMapConfig.unk_6 = setting;
    setting = func_020a8a04(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    gMapConfig.unk_2 = setting;
    gMapConfig.flags |= 0x4000;
    gMapConfig.flags |= 0x8000;
    func_020a88c4(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID));
    SetMapWeather();
    base = (u8 *)*gCurrentMap;
    base[MAP_TILESET] = MapData_GetTileset(M2C_FIELD(base, u16 *, MAP_ID));
    M2C_FIELD(*gCurrentMap, u8 *, 0x5155) = 0x13;
}

/* Battle start-up: fill the per-player setup tables for players 1-4 (id/team
 * slots via the func_020a23xx byte setters), clear the map's edge counters,
 * and initialize the player config record at gMapConfig (flags word plus
 * default values 0/1000/0/0), setting its default flag bits. */
void ResetPlayerSetupTables(void) {
    void SetPlayerCoId(s32, s32);
    void SetPlayerIdForSlot(s32, s32);
    void SetPlayerArmyId(s32, s32);
    void func_020a233c(s32, s32);
    void SetInitialCoPowerMeter(s32, s32);
    void SetPlayerTeam(s32, s32);
    extern void **gCurrentMap;
    extern MapConfigRecord gMapConfig;
    u8 *p;
    u8 *q;
    u16 *cfg;
    u32 bits;

    cfg = &gMapConfig.flags;

    p = (u8 *)*gCurrentMap;
    p += 0x5000;
    p[0x2ae] = 0;
    p = (u8 *)*gCurrentMap;
    p += 0x5000;
    p[0x2af] = 0;

    SetPlayerTeam(1, 1);
    SetPlayerTeam(2, 2);
    SetPlayerTeam(3, 2);
    SetPlayerTeam(4, 2);
    SetPlayerIdForSlot(1, 1);
    SetPlayerIdForSlot(2, 2);
    SetPlayerIdForSlot(3, 3);
    SetPlayerIdForSlot(4, 4);
    SetPlayerCoId(1, 0);
    SetPlayerCoId(2, 0);
    SetPlayerCoId(3, 0);
    SetPlayerCoId(4, 0);
    SetInitialCoPowerMeter(1, 0);
    SetInitialCoPowerMeter(2, 0);
    SetInitialCoPowerMeter(3, 0);
    SetInitialCoPowerMeter(4, 0);
    SetPlayerArmyId(1, 1);
    SetPlayerArmyId(2, 2);
    SetPlayerArmyId(3, 3);
    SetPlayerArmyId(4, 4);
    func_020a233c(1, 0);
    func_020a233c(2, 0);
    func_020a233c(3, 0);
    func_020a233c(4, 0);

    *(u16 *)((u8 *)cfg + 4) = 0;
    *((u8 *)cfg + 3) = 0;
    *((u8 *)cfg + 2) = 0;
    bits = *cfg;
    bits |= 0x100;
    *cfg = bits;
    bits = *cfg;
    bits &= ~0x200;
    *cfg = bits;
    *(u16 *)((u8 *)cfg + 6) = 0x3e8;
    *(u32 *)((u8 *)cfg + 8) = 0;
    *(u32 *)((u8 *)cfg + 12) = 0;

    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x156] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x157] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x15b] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x158] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x159] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x15a] = 0;
    q = (u8 *)*gCurrentMap;
    q += 0x5000;
    q[0x155] = 3;

    bits = *cfg;
    bits |= 0x400;
    *cfg = bits;
    bits = *cfg;
    bits &= ~0x800;
    *cfg = bits;
    bits = *cfg;
    bits &= ~0x38;
    bits |= 0x10;
    *cfg = bits;
    bits = *cfg;
    bits &= ~0x40;
    *cfg = bits;
    bits = *cfg;
    bits &= ~0x80;
    *cfg = bits;
    bits = *cfg;
    bits |= 0x2000;
    *cfg = bits;
    bits = *cfg;
    bits |= 0x1000;
    *cfg = bits;
    bits = *cfg;
    bits |= 0x4000;
    *cfg = bits;
    bits = *cfg;
    bits |= 0x8000;
    *cfg = bits;
}

/* Reset the battle-end record to its start-of-battle state: the battle has not
 * ended and no end condition has been raised (the qualifier byte keeps its
 * default of 1). */
void ResetBattleEndState(void) {
    extern M2C_UNK gBattleEndState;
    M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_ENDED) = 0;
    M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG1) = 0;
    M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG2) = 0;
    M2C_FIELD(&gBattleEndState, u8 *, BATTLE_END_FLAG3) = 1;
}

/* Reset the map config record to its free-play defaults: mode 1 in
 * gMapConfig.flags, the default map id, the player setup tables and the
 * battle-end record. */
void ResetMapConfig(void) {
    extern MapConfigRecord gMapConfig;
    extern void **gCurrentMap;

    gMapConfig.flags = (gMapConfig.flags & ~7) | 1;
    M2C_FIELD(*gCurrentMap, u16 *, MAP_ID) = 1;
    ResetPlayerSetupTables();
    ResetBattleEndState();
}

/* Empty the shared battle target list before the cursor code rebuilds it: no
 * entry of gTargetList is in use. */
void ResetTargetList(void) {
    extern M2C_UNK gTargetList;

    M2C_FIELD(&gTargetList, s32 *, MAP_TARGET_LIST_COUNT) = 0;
}

s32 GetTargetCount(void) {
    extern M2C_UNK gTargetList;
    return M2C_FIELD(&gTargetList, s32 *, 8);
}

/* Pointer to entry n of the shared battle target list (the list the cursor code
 * builds: one MapTargetEntry per targeted cell). */
void *GetTargetPosition(s32 n) {
    extern M2C_UNK gTargetList;
    return M2C_FIELD(&gTargetList, u8 **, MAP_TARGET_LIST_ARRAY) + n * 8;
}

/* Append a battle-target entry for cell (x, y) to the shared target list
 * gTargetList: the id of the unit standing there and the damage to deal (or the
 * cell's visibility value), then bump the list's count. */
void AppendTargetEntry(s32 x, s32 y, s32 id, s32 value) {
    extern M2C_UNK gTargetList;
    Unk09List *list = (Unk09List *)&gTargetList;
    MapTargetEntry *entry = (MapTargetEntry *)list->p;
    entry[list->count].x = x;
    entry[list->count].y = y;
    entry[list->count].id = id;
    entry[list->count].value = value;
    list->count++;
}

/* Return 1 when the battle target list already holds the cell (x, y). */
s32 IsTargetCellListed(s32 x, s32 y) {
    extern M2C_UNK gTargetList;
    MapTargetList *list = (MapTargetList *)&gTargetList;
    MapTargetEntry *entry = list->entries;
    s32 i;
    s32 count = list->count;
    for (i = 0; i < count; i++, entry++) {
        if (x == entry->x && y == entry->y) return 1;
    }
    return 0;
}

