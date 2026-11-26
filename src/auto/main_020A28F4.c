/* 50 functions from 0x020A28F4 to 0x020A38F4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "sound.h"


/* PLAYER_REC_SPRITE of a player record: the army id byte, then two small
 * bitfields that pick the army's sprite tables; bits 10-11 are the army variant. */
typedef struct { u32 armyId:8; u32 reserved:2; u32 armyVariant:2; } PlayerSpriteWord;

/* Defense bonus the CO zone of `commander` gives unit kind `kind`: only kinds
 * the commander's zone covers receive it. */
s32 GetCoZoneDefenseBonus(s32 kind, s32 commander, s32 powerActive) {
    extern s32 *gCurrentMap;
    extern M2C_UNK gCoZoneKindEnabled;
    extern s16 gCoZoneDefensePct;
    s32 GetCoZoneBonusIndex(s32, s32);
    s32 row;

    row = GetCoZoneBonusIndex(((u32)(M2C_FIELD(*gCurrentMap + commander * MAP_PLAYER_STRIDE, s32 *, PLAYER_REC_SPRITE + MAP_PLAYER_STATES) << 24) >> 24), powerActive);
    if (row == -1) {
        return 0;
    }
    row *= CO_ZONE_RECORD_STRIDE;
    if (!*(s8 *)(kind + ((s32)&gCoZoneKindEnabled + row))) {
        return 0;
    }
    return M2C_FIELD(&gCoZoneDefensePct, s16 *, row);
}

/* Bonus the CO zone of `commander` gives unit kind `kind`'s movement: only kinds
 * the commander's zone covers receive it. */
s32 GetCoZoneMoveBonus(s32 kind, s32 commander, s32 powerActive) {
    extern s32 *gCurrentMap;
    extern M2C_UNK gCoZoneKindEnabled;
    extern s8 gCoZoneMoveBonus;
    s32 GetCoZoneBonusIndex(s32, s32);
    s32 row;

    row = GetCoZoneBonusIndex(((u32)(M2C_FIELD(*gCurrentMap + commander * MAP_PLAYER_STRIDE, s32 *, PLAYER_REC_SPRITE + MAP_PLAYER_STATES) << 24) >> 24), powerActive);
    if (row == -1) {
        return 0;
    }
    row *= CO_ZONE_RECORD_STRIDE;
    if (!*(s8 *)(kind + ((s32)&gCoZoneKindEnabled + row))) {
        return 0;
    }
    return M2C_FIELD(&gCoZoneMoveBonus, s8 *, row);
}

/* Bonus the CO zone of `commander` gives unit kind `kind`'s maximum attack
 * range: only kinds the commander's zone covers and kinds that already attack
 * at range 2 or more receive it. */
s32 GetCoZoneRangeBonus(s32 kind, s32 commander, s32 powerActive) {
    extern s32 *gCurrentMap;
    extern M2C_UNK gCoZoneKindEnabled;
    extern s8 gCoZoneRangePct;
    s32 GetCoZoneBonusIndex(s32, s32);
    s32 GetUnitKindMaxAttackRange(s32);
    s32 row;

    row = GetCoZoneBonusIndex(((u32)(M2C_FIELD(*gCurrentMap + commander * MAP_PLAYER_STRIDE, s32 *, PLAYER_REC_SPRITE + MAP_PLAYER_STATES) << 24) >> 24), powerActive);
    if (row == -1) {
        return 0;
    }
    row *= CO_ZONE_RECORD_STRIDE;
    if (!*(s8 *)(kind + ((s32)&gCoZoneKindEnabled + row))) {
        return 0;
    }
    if (GetUnitKindMaxAttackRange(kind) < 2) {
        return 0;
    }
    return M2C_FIELD(&gCoZoneRangePct, s8 *, row);
}

/* Music track that replaces the map theme while the player's CO power is
 * active: armies 1..7 use the first CO-power theme, every other army the
 * second. */
s32 GetCoPowerMusicTrack(s32 player) {
    extern s32 *gCurrentMap;
    switch ((u32)(M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return SOUND_CO_POWER_THEME_1;
    case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        return SOUND_CO_POWER_THEME_2;
    default:
        return SOUND_CO_POWER_THEME_2;
    }
}

/* Battle music track for `player`: the CO-power theme while the player's army
 * variant is set, otherwise the track the map's player record overrides, otherwise
 * the army's default track. */
s32 GetPlayerMusicTrack(u8 player) {
    extern s32 *gCurrentMap;
    extern s32 data_02126180;
    s32 track;
    if (GetPlayerArmyVariant(player)) {
        return GetCoPowerMusicTrack(player);
    }
    track = MapData_GetPlayerTrack(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
    if (track) {
        return track;
    }
    return M2C_FIELD(&data_02126180, s32 *, ((u32)(M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24) * ARMY_DATA_SIZE);
}

void PlayPlayerMusic(s32 arg0) {
    M2C_UNK ChangeMusicTrackWithFade();
    M2C_UNK GetPlayerMusicTrack(u8);
    GetPlayerMusicTrack((u8)(arg0 & 0xFF));
    ChangeMusicTrackWithFade();
}

/* Add `points` to `player`'s CO power meter when the map enables CO powers and
 * the player is not using a fixed army variant. */
void AddCoPowerMeterPointsIfEnabled(s32 player, s32 points) {
    s32 GetPlayerArmyVariantIfSet(s32);
    extern u16 gMapConfig;
    if (((u32)(M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS) << 19) >> 31) == 0) return;
    if (GetPlayerArmyVariantIfSet(player) != 0) return;
    AddCoPowerMeterPoints(player, points);
}

s32 GetCoPowerMeterPointsPerStar(void) {
    return 0xA;
}

/* Whether a player's CO power is charged: CO powers must be enabled for the map,
 * the player must not be using a set army variant, and the player's CO power
 * meter must have reached the CO power's star cost. */
u8 IsPlayerCoPowerReady(s32 player) {
    extern u16 gMapConfig;
    s32 GetPlayerArmyVariantIfSet(s32);
    s32 GetCoPowerMeterPoints(s32);
    s32 GetCoPowerMeterCost(s32, s32);
    s32 meter;
    u8 ready;

    if (((u32)(M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS) << 19) >> 31) == 0) return 0;
    if (GetPlayerArmyVariantIfSet(player)) return 0;
    if (!GetCoPowerMeterCost(player, 2)) return 0;
    meter = GetCoPowerMeterPoints(player);
    if (meter >= GetCoPowerMeterCost(player, 2)) ready = 1;
    else ready = 0;
    return ready;
}

void func_020a2c58(void *arg0){RefreshPlayerArmyDisplay(M2C_FIELD(arg0,s32 *,0x5c));}

/* Start a player's on-map unit view at its first unit: when the player's army
 * and sprite variant have a handler in the sprite-set table, reset the view's
 * slot and frame counters; otherwise the view has nothing to draw and its
 * sprite object is removed. */
void StartPlayerUnitView(void *view) {
    extern s32 *gCurrentMap;
    extern u8 data_021261c4[];
    s32 playerRecord = *gCurrentMap + MAP_PLAYER_STATES + M2C_FIELD(view, s32 *, 0x5C) * MAP_PLAYER_STRIDE;
    s32 spriteVariant = GetPlayerSpriteSet(M2C_FIELD(view, s32 *, 0x5C));
    u32 armyId = (u32)(M2C_FIELD(playerRecord, s32 *, PLAYER_REC_SPRITE) << 24) >> 24;
    if (M2C_FIELD(data_021261c4 + armyId * 0x9C, s32 *, spriteVariant * 0x28) == 0) {
        DeleteSpriteObject(view);
    } else {
        M2C_FIELD(view, u16 *, 0x70) = 1;
        M2C_FIELD(view, u16 *, 0x6C) = 0;
    }
}

/* Advances a player's on-map unit display by one unit: walks that player's unit
 * slots, checks whether the unit may be shown for this army, positions and
 * animates the sprite (drawing it only when its cell is in the visible-cell
 * bitmap), then moves the view's slot and frame counters on. */
void UpdatePlayerUnitView(void *view) {
void RefreshMapView(void);
extern s32 *gCurrentMap;
extern u8 gMovementCostTable[], data_021261c8[];
s32 player, spriteSet, armyId;
u8 *unit;
s32 map, playerOffset;
u32 tmp;
player=M2C_FIELD(view,s32 *,0x5c);
if(IsMapViewScrolling())return;
if(M2C_FIELD(view,s16 *,0x70)<51){
playerOffset=player*0x8c;
do {
map=*gCurrentMap;
unit=(u8 *)(map+MAP_UNIT_RECORDS+(M2C_FIELD(map,u16 *,MAP_CURSOR_OWNER)+M2C_FIELD(view,s16 *,0x70))*MAP_UNIT_STRIDE);
if(((u32)(M2C_FIELD(unit,u8 *,MAP_UNIT_KIND)<<26)>>26)!=0){
spriteSet=GetPlayerSpriteSet(player);
armyId=(u32)(M2C_FIELD(map+playerOffset,s32 *,MAP_PLAYER_STATES+PLAYER_REC_SPRITE)<<24)>>24;
if(((s32 (*)(u8 *))M2C_FIELD(gMovementCostTable+armyId*156+spriteSet*40,s32 *,0x58))(unit)){
map=*gCurrentMap;
tmp=M2C_FIELD(unit,u8 *,MAP_UNIT_X)+M2C_FIELD(map+M2C_FIELD(unit,u8 *,MAP_UNIT_Y)*2,u16 *,MAP_ROW_OFFSETS);
if((u8)(M2C_FIELD(map+(tmp>>3),u8 *,MAP_CELL_BITMAP)&(1<<(tmp&7)))) {
if(!(M2C_FIELD(unit,u16 *,MAP_UNIT_FLAGS)&8))goto visible;
}
if(!(M2C_FIELD(unit,u16 *,MAP_UNIT_FLAGS)&8)){
StepMapViewToTile(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y));
if(IsMapViewScrolling())return;
}
tmp=*gCurrentMap+MAP_PLAYER_STATES+playerOffset;
spriteSet=GetPlayerSpriteSet(player);
armyId=(u32)(M2C_FIELD(tmp,s32 *,PLAYER_REC_SPRITE)<<24)>>24;
((void (*)(u8 *))M2C_FIELD(data_021261c8+armyId*156,s32 *,spriteSet*40))(unit);
goto increment;
visible:
StepMapViewToTile(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y));
if(IsMapViewScrolling())return;
tmp=*gCurrentMap+MAP_PLAYER_STATES+playerOffset;
spriteSet=GetPlayerSpriteSet(player);
armyId=(u32)(M2C_FIELD(tmp,s32 *,PLAYER_REC_SPRITE)<<24)>>24;
((void (*)(u8 *))M2C_FIELD(data_021261c8+armyId*156,s32 *,spriteSet*40))(unit);
done:
SpawnArmySpecialEffect(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y),M2C_FIELD(view,s16 *,0x6c),GetPlayerSpriteSet(player),view);
increment:
M2C_FIELD(view,s16 *,0x70)++;
break;
}
}
M2C_FIELD(view,s16 *,0x70)++;
}while(M2C_FIELD(view,s16 *,0x70)<51);
}
if(M2C_FIELD(view,s16 *,0x70)==51)Sprite_ResumeAnimation(view);
M2C_FIELD(view,s16 *,0x6c)++;
RefreshMapView();
}

void func_020a2f28(void *arg0){RefreshPlayerArmyDisplay(M2C_FIELD(arg0,s32 *,0x5c));}

/* Create the on-map army display panel of player `player` and record the player in
 * it so its step callback can refresh the display. */
void CreatePlayerArmyDisplay(s32 player) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gPlayerArmyDisplayClass;
    M2C_FIELD(CreateSpriteObject(&gPlayerArmyDisplayClass), s32 *, 0x5C) = player;
}

/* Choose a different adverse weather, start its transition, and refresh the player's army. */
void ChangeToRandomAdverseWeather(s32 player) {
    extern s32 *gCurrentMap;
    s32 RandomIntRange(s32, s32);
    s32 StartWeatherChange(s32, s32);
    s32 RefreshPlayerArmyDisplay(s32);
    s32 weather = M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER);

    switch (weather) {
    case WEATHER_CLEAR:
        switch (RandomIntRange(0, 2)) {
        case 0:
        default:
            weather = WEATHER_SNOW;
            break;
        case 1:
            weather = WEATHER_RAIN;
            break;
        case 2:
            weather = WEATHER_SANDSTORM;
            break;
        }
        break;
    case WEATHER_SNOW:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            weather = WEATHER_RAIN;
            break;
        case 1:
            weather = WEATHER_SANDSTORM;
            break;
        }
        break;
    case WEATHER_RAIN:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            weather = WEATHER_SNOW;
            break;
        case 1:
            weather = WEATHER_SANDSTORM;
            break;
        }
        break;
    case WEATHER_SANDSTORM:
        switch (RandomIntRange(0, 1)) {
        case 0:
        default:
            weather = WEATHER_SNOW;
            break;
        case 1:
            weather = WEATHER_RAIN;
            break;
        }
        break;
    }
    StartWeatherChange(weather, 3);
    RefreshPlayerArmyDisplay(player);
}

/* Whether the unit record `unit` is of a kind other than unit-kind class 6.
 * The kind is the low six bits of the record's first byte; class 6 kinds are
 * exempt from the attack/damage bonuses and from scripted damage. */
u8 IsUnitKindNotClass6(u8 *unit) {
    s32 IsUnitKindClass6(u32);
    u8 notClass6;

    if (IsUnitKindClass6((u32) (*unit << 0x1A) >> 0x1A) == 0) {
        notClass6 = 1;
    } else {
        notClass6 = 0;
    }
    return notClass6;
}

void func_020a3088(M2C_UNK arg0) {
    M2C_UNK LevelUpUnit(M2C_UNK, M2C_UNK, M2C_UNK);
    LevelUpUnit(arg0, 3, 0);
}

/* Refill a unit's ammo and fuel up to their maxima at no cost (a scripted action
 * such as a supply drop or repair). */
void RestockUnit(s32 unit) {
    M2C_UNK RefillUnitAmmo(M2C_UNK, M2C_UNK);
    M2C_UNK RefillUnitFuel(M2C_UNK, M2C_UNK);

    RefillUnitAmmo(unit, 0);
    RefillUnitFuel(unit, 0);
}

void func_020a30bc(void) {

}

/* One of the CO's quote lines picked at random: army `armyId`'s entry of
 * ARMY_DATA_QUOTE_COUNT text ids at armydata+ARMY_DATA_QUOTE_TEXT_IDS. */
s32 GetRandomCoQuoteTextId(s32 armyId){
extern u8 gArmyQuoteTextIds[];
s32 NextRandomValue(void);
return ((s32 *)(gArmyQuoteTextIds+armyId*ARMY_DATA_SIZE))[NextRandomValue()%ARMY_DATA_QUOTE_COUNT];
}

/* Let `player` pick a unit again: set its selection-enabled flag. */
void EnablePlayerSelection(s32 player) {
    extern s32 *gCurrentMap;
    M2C_FIELD((player * MAP_PLAYER_STRIDE) + *gCurrentMap, s8 *, PLAYER_SELECTION_ENABLED_OFF) = 1;
}

/* Stop `player` from picking a unit: clear its selection-enabled flag. */
void DisablePlayerSelection(s32 player) {
    extern s32 *gCurrentMap;
    M2C_FIELD((player * MAP_PLAYER_STRIDE) + *gCurrentMap, s8 *, PLAYER_SELECTION_ENABLED_OFF) = 0;
}

/* Whether player `player` may still pick a unit: the start of its turn enables
 * the flag while nothing is selected, and clearing its selection state disables it. */
u8 IsPlayerSelectionEnabled(s32 player) {
    extern s32 *gCurrentMap;
    return M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, u8 *,
                     MAP_PLAYER_STATES + PLAYER_REC_SELECTION_ENABLED) != 0;
}

/* Set the player's selected unit (0 clears it): drop the selection marker from the
 * player's previous unit and set it on `unit`, and store the unit's record id in
 * the player record. */
void SetPlayerSelectedUnit(s32 player, u8 *unit) {
    extern s32 *gCurrentMap;
    u8 *GetPlayerSelectedUnit(s32);
    u8 *old; s32 index;
    old = GetPlayerSelectedUnit(player);
    if (old && old != unit) *old &= ~MAP_UNIT_OWNER_MASK;
    if (unit == 0) index = 0;
    else { if (unit == 0) index = 0; else index = ((s32)unit - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE; }
    M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_SELECTED_UNIT) = index;
    if (unit) *unit = (*unit & ~MAP_UNIT_OWNER_MASK) | MAP_UNIT_OWNER_MASK;
}

/* Update the owner's selected-unit ID when the selected unit is merged into another unit or cleared. */
void ReplacePlayerSelectedUnit(BattleMapUnitHead *selected, BattleMapUnitHead *replacement) {
    extern s32 *gCurrentMap;
    u8 *GetPlayerSelectedUnit(s32);
    s32 GetUnitOwner(void *);
    s32 replacementId;

    if (selected != (BattleMapUnitHead *)GetPlayerSelectedUnit(GetUnitOwner(selected))) {
        return;
    }
    if (replacement == 0) {
        replacementId = 0;
    } else {
        replacementId = ((s32)replacement - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
    }
    M2C_FIELD(*gCurrentMap + GetUnitOwner(selected) * MAP_PLAYER_STRIDE, u8 *,
              MAP_PLAYER_STATES + PLAYER_REC_SELECTED_UNIT) = replacementId;
}

/* Whether player `player` has a selected unit: the player must have an army
 * (the sprite word's low byte is nonzero) and a selected-unit id. */
u8 HasPlayerSelectedUnit(s32 player) {
    extern s32 *gCurrentMap;
    s32 record = *gCurrentMap + MAP_PLAYER_STATES + MAP_PLAYER_STRIDE * player;
    u8 selected;
    if (!((u32)(M2C_FIELD(record, s32 *, PLAYER_REC_SPRITE) << 24) >> 24)) return 0;
    if (M2C_FIELD(record, u8 *, PLAYER_REC_SELECTED_UNIT)) selected = 1;
    else selected = 0;
    return selected;
}

/* Pointer to player `player`'s selected unit record, or NULL when the player has
 * no army yet (its sprite word is 0) or has nothing selected. */
u8 *GetPlayerSelectedUnit(s32 player) {
    extern s32 *gCurrentMap;
    s32 base = *gCurrentMap;
    s32 record = base + MAP_PLAYER_STATES + MAP_PLAYER_STRIDE * player;
    u32 selected;
    if (!((u32)(M2C_FIELD(record, s32 *, PLAYER_REC_SPRITE) << 24) >> 24)) return 0;
    selected = M2C_FIELD(record, u8 *, PLAYER_REC_SELECTED_UNIT);
    if (!selected) return 0;
    return (u8 *)(base + MAP_UNIT_RECORDS + MAP_UNIT_STRIDE * selected);
}

/* Player `player`'s army variant (bits 10-11 of its sprite state), or 0 when the
 * player has no army at all: the sprite state's army-id byte is 0. */
s32 GetPlayerArmyVariantIfSet(s32 player) {
    extern s32 *gCurrentMap;
    s32 record = *gCurrentMap + MAP_PLAYER_STATES + MAP_PLAYER_STRIDE * player;
    PlayerSpriteWord *sprite = (PlayerSpriteWord *)(record + PLAYER_REC_SPRITE);
    if (sprite->armyId == 0) return 0;
    return (u8)sprite->armyVariant;
}

/* Store player `player`'s army variant (bits 10..11 of its sprite state); the
 * variant doubles as the level of CO power the player's army is showing. */
void SetPlayerArmyVariant(s32 player,s32 variant){
extern s32 *gCurrentMap;
s32 record=*gCurrentMap+MAP_PLAYER_STATES+MAP_PLAYER_STRIDE*player;
M2C_FIELD(record,u32 *,PLAYER_REC_SPRITE)=(M2C_FIELD(record,u32 *,PLAYER_REC_SPRITE)&~PLAYER_ARMY_VARIANT_MASK)|((u32)(variant<<30)>>20);
}

/* Player `player`'s army variant: bits 10..11 of its sprite state, which double
 * as the level of the army's CO power being shown. */
s32 GetPlayerArmyVariant(s32 player) {
    extern s32 *gCurrentMap;
    return (u32)(M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 20) >> 30;
}

/* Write the two auxiliary bits (8..9) of player `player`'s PLAYER_REC_SPRITE
 * word, keeping the army id, the army variant, the sprite set and the CO power
 * meter around them.  No reader names these bits; every caller clears them. */
void SetPlayerSpriteAuxBits(s32 player, u32 bits) {
    extern s32 *gCurrentMap;
    s32 record = *gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE;

    M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) =
        (M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) & ~0x300) | ((bits << 30) >> 22);
}

/* Store player `player`'s sprite set/variant (bits 12..13 of its sprite state),
 * which picks the variant its on-map unit views draw. */
void SetPlayerSpriteSet(s32 player, u32 spriteSet) {
    extern s32 *gCurrentMap;
    s32 record = *gCurrentMap + MAP_PLAYER_STATES + MAP_PLAYER_STRIDE * player;

    M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) =
        (M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) & ~PLAYER_SPRITE_SET_MASK) | ((spriteSet << 30) >> 18);
}

/* Player `player`'s sprite set (bits 12..13 of its PLAYER_REC_SPRITE word): which
 * variant its on-map unit views draw, as SetPlayerSpriteSet stores it. */
s32 GetPlayerSpriteSet(s32 player) {
    extern s32 *gCurrentMap;

    return (u32)(M2C_FIELD((u8 *)*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE,
                           u32 *, PLAYER_REC_SPRITE) << 18) >> 30;
}

void func_020a348c(void) {
    M2C_UNK CreatePlayerUnitView();
    CreatePlayerUnitView();
}

void SetPlayerCoAnimationToIdle(M2C_UNK arg0) {
    void SetPlayerArmyVariant(s32, s32);
    SetPlayerArmyVariant(arg0, 0);
}

#pragma opt_common_subs off
void AdvancePlayerSpriteState(s32 a){u32 v;u32 n;extern s32 *gCurrentMap;s32 p;p=*gCurrentMap;p+=0x3a4;p+=0x6400;p+=a*0x8c;v=*(u32*)(p+0x6c);n=(v<<14)>>28;if(n>=10)return;*(u32*)(p+0x6c)=(v&~0x3c000)|(((n+1)<<28)>>14);}
#pragma opt_common_subs reset
/* Consume the player's dual CO power: take its dual-power meter cost back off
 * the player's CO power meter. */
void ConsumeDualCoPowerCost(s32 player) {
    s32 GetCoPowerMeterCost(s32, s32);
    s32 AddCoPowerMeterPoints(s32, s32);
    AddCoPowerMeterPoints(player, 0 - GetCoPowerMeterCost(player, CO_POWER_LEVEL_DUAL));
}

#pragma opt_common_subs off
/* A player's CO power meter points (bits 21..31 of PLAYER_REC_SPRITE), or 0 when
 * the player has no army: its army id, the sprite word's low byte, is 0. */
s32 GetCoPowerMeterPoints(s32 player) {
    extern s32 *gCurrentMap;
    s32 record = *gCurrentMap + MAP_PLAYER_STATES + MAP_PLAYER_STRIDE * player;
    s32 *spriteWord = (s32 *)(record + PLAYER_REC_SPRITE);
    if (((u32)(*spriteWord << 24) >> 24) == 0) return 0;
    return (u32)*spriteWord >> PLAYER_CO_METER_SHIFT;
}
#pragma opt_common_subs reset
/* Store a player's CO power meter points (bits 21..31 of its sprite state), clamped at zero. */
void SetCoPowerMeterPoints(s32 player,s32 points){
 extern s32 *gCurrentMap;
 s32 *record;
 if(points<0)points=0;
 record=(s32 *)(*gCurrentMap+MAP_PLAYER_STATES+MAP_PLAYER_STRIDE*player);
 M2C_FIELD(record,u32 *,PLAYER_REC_SPRITE)=(M2C_FIELD(record,u32 *,PLAYER_REC_SPRITE)&PLAYER_CO_METER_MASK)|((u32)points<<PLAYER_CO_METER_SHIFT);
}

/* Meter points needed for a player's CO power level: nothing at level 0,
 * otherwise the commander's star cost of that power from the per-commander CO
 * table (gArmyCoPowerCost is its +0x18 field, gArmyDualPowerCost the +0x1c
 * one), at ten meter points per star. */
s32 GetCoPowerMeterCost(s32 player, s32 level) {
    extern s32 *gCurrentMap;
    extern u8 gArmyCoPowerCost[], gArmyDualPowerCost[];
    s32 GetCoPowerMeterPointsPerStar(void);
    s32 cost;
    u32 commander;

    switch (level) {
    default:
    case 0:
        cost = 0;
        break;
    case 1:
        commander = (u32)(M2C_FIELD(*gCurrentMap + player * 0x8c, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24;
        cost = *(s32 *)(gArmyCoPowerCost + commander * ARMY_DATA_SIZE);
        break;
    case 2:
        commander = (u32)(M2C_FIELD((u8 *)*gCurrentMap + player * 0x8c, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24;
        cost = *(s32 *)(gArmyDualPowerCost + commander * ARMY_DATA_SIZE);
        break;
    }
    return cost * ((s32 (*)(s32))GetCoPowerMeterPointsPerStar)(player);
}

/* Reset the on-map army display of player `player`: zero layer 0's quad offsets
 * on the current sprite bank, copy the player's sprite set into the display's
 * variant, clear the per-turn bonuses of the active players and redraw the map
 * view. */
s32 RefreshPlayerArmyDisplay(s32 player) {
    extern s32 *gCur3DSpriteEngine;
    s32 GetPlayerSpriteSet(s32);
    void SetPlayerArmyVariant(s32, s32);
    void ResetPlayerTurnBonuses(void);
    void RefreshMapView(void);
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_QUAD_X) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_QUAD_Y) = 0;
    SetPlayerArmyVariant(player, GetPlayerSpriteSet(player));
    ResetPlayerTurnBonuses();
    RefreshMapView();
}

/* Add `points` to a player's CO power meter, clamped between zero and the
 * player's dual-power meter cost; a player with no commander (army id 0) has no
 * meter to charge and is returned unchanged. */
s32 AddCoPowerMeterPoints(s32 player, s32 points) {
  extern s32 *gCurrentMap;
  s32 GetCoPowerMeterPoints(s32);
  s32 GetCoPowerMeterCost(s32, s32);
  void SetCoPowerMeterPoints(s32, s32);
  s32 armyId = (s32)((u32)(M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24);
  if (armyId == 0) {
    return player;
  }
  {
    s32 current = GetCoPowerMeterPoints(player);
    s32 max = GetCoPowerMeterCost(player, CO_POWER_LEVEL_DUAL);
    s32 meter = current + points;
    if (meter < 0) meter = 0;
    if (meter > max) meter = max;
    SetCoPowerMeterPoints(player, meter);
  }
}

/* Start handler of the player's army display panel sprite: look up the panel's
 * screen position for the player id at +0x6C and store it at +0x34/+0x38; hide
 * the sprite when the player has no panel to show. */
void StartPlayerArmyDisplay(void *panel) {
    s16 pos[2];
    s32 SelectAreaEffectTargetForMode(s16 *, s32, s32, s32);
    if (!SelectAreaEffectTargetForMode(pos, M2C_FIELD(panel, s16 *, 0x6C), 0, 1)) {
        GotoSpriteAnimationLabel(panel, 0);
        return;
    }
    M2C_FIELD(panel, s32 *, 0x34) = pos[0];
    M2C_FIELD(panel, s32 *, 0x38) = pos[1];
}

/* Draw handler of the player's army display panel: add its child tile marker at
 * the panel position saved at +0x34/+0x38, showing image tile 0x50. */
void CreateArmyPanelMarkerSprite(void *panel) {
    M2C_UNK CreateTileMarkerSprite(s32, s32, M2C_UNK, M2C_UNK, void *);
    CreateTileMarkerSprite(M2C_FIELD(panel, s32 *, 0x34), M2C_FIELD(panel, s32 *, 0x38), 2, 0x50, panel);
}

void func_020a3764(void *arg0) {
    RefreshPlayerArmyDisplay(M2C_FIELD(arg0, s16 *, 0x6C));
}

/* Create the army display panel sprite of player `player` and record the player id
 * at +0x6C, where its start, draw and step handlers read it. */
void CreatePlayerArmyDisplayPanel(s16 player) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gPlayerArmyDisplayPanelClass;
    M2C_FIELD(CreateSpriteObject(&gPlayerArmyDisplayPanelClass), s16 *, 0x6C) = player;
}

s32 NormalizeWeather(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0xFE) {
        var_r0 = 1;
    }
    return var_r0;
}

/* Apply a weather change to the map: store the change sprite's weather id in the
 * map, refresh team A's sight bitmap when the sprite asks for it, then let the
 * map-view controller re-apply the terrain for the new weather and tileset. */
void ApplyWeatherChange(void *sprite){
extern s32 *gCurrentMap;void (*cb)(u8,u8);
M2C_FIELD(*gCurrentMap,u8 *,MAP_WEATHER)=M2C_FIELD(sprite,s16 *,0x36);
if(M2C_FIELD(sprite,s16 *,0x38))FillTeamSightBitmap((u8)M2C_FIELD(*gCurrentMap,u16 *,MAP_TEAM_A_PLAYER));
cb=M2C_FIELD(gCurrentMap[1],void (**)(u8,u8),MAPVIEW_SET_TERRAIN);
if(!cb)return;
cb(M2C_FIELD(*gCurrentMap,u8 *,MAP_WEATHER),M2C_FIELD(*gCurrentMap,u8 *,MAP_TILESET));
}

/* Sprite handler of the weather transition sprite: plays the sound of the new
 * weather the sprite is switching the map to (its weather id at +0x36). */
void PlayWeatherChangeSound(void *sprite) {
    switch ((u32)M2C_FIELD(sprite, s16 *, 0x36)) {
    case WEATHER_CLEAR:     PlaySoundEffect(SOUND_WEATHER_CLEAR);     return;
    case WEATHER_RAIN:      PlaySoundEffect(SOUND_WEATHER_RAIN);      return;
    case WEATHER_SNOW:      PlaySoundEffect(SOUND_WEATHER_SNOW);      return;
    case WEATHER_SANDSTORM: PlaySoundEffect(SOUND_WEATHER_SANDSTORM); return;
    default: return;
    }
}

#pragma opt_instruction_scheduling off
/* Ticks down the current player's weather-change delay and reports whether the
 * weather may change now: the delay reached zero and no active player still has a
 * reset weather pending. */
s32 IsWeatherChangeDue(void) {
extern s32 *gCurrentMap; s32 IsPlayerActive(s32);
u8 *delay; s32 player,turnsLeft,i;
delay=(u8*)(*gCurrentMap+MAP_WEATHER_DELAY);
player=M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)-1;
turnsLeft=delay[player];
if(turnsLeft>0){turnsLeft--;delay[player]=turnsLeft;}
if(turnsLeft>0)return 0;
for(i=1;i<MAX_PLAYERS;i++){if(IsPlayerActive(i)!=0){if(M2C_FIELD(*gCurrentMap+i,u8*,MAP_WEATHER_RESET)!=0)return 0;}}
return 1;
}
#pragma opt_instruction_scheduling reset
