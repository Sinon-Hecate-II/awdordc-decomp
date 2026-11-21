/* 50 functions from 0x020A28F4 to 0x020A38F4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "sound.h"

typedef struct { u32 low:8; u32 mid:2; u32 hi:2; } Word020a334c;

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
    track = func_020a8ac4(M2C_FIELD(*gCurrentMap, u16 *, MAP_ID), player);
    if (track) {
        return track;
    }
    return M2C_FIELD(&data_02126180, s32 *, ((u32)(M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24) * ARMY_DATA_SIZE);
}

void func_020a2b84(s32 arg0) {
    M2C_UNK func_0208f7d0();
    M2C_UNK GetPlayerMusicTrack(u8);
    GetPlayerMusicTrack((u8)(arg0 & 0xFF));
    func_0208f7d0();
}

void func_020a2b98(s32 a,s32 b){
s32 GetPlayerArmyVariantIfSet(s32);
extern u16 gMapConfig;
if(((u32)(gMapConfig<<19)>>31)==0)return;
if(GetPlayerArmyVariantIfSet(a)!=0)return;
AddCoPowerMeterPoints(a,b);
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
    s32 spriteVariant = func_020a3460(M2C_FIELD(view, s32 *, 0x5C));
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
spriteSet=func_020a3460(player);
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
spriteSet=func_020a3460(player);
armyId=(u32)(M2C_FIELD(tmp,s32 *,PLAYER_REC_SPRITE)<<24)>>24;
((void (*)(u8 *))M2C_FIELD(data_021261c8+armyId*156,s32 *,spriteSet*40))(unit);
goto increment;
visible:
StepMapViewToTile(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y));
if(IsMapViewScrolling())return;
tmp=*gCurrentMap+MAP_PLAYER_STATES+playerOffset;
spriteSet=func_020a3460(player);
armyId=(u32)(M2C_FIELD(tmp,s32 *,PLAYER_REC_SPRITE)<<24)>>24;
((void (*)(u8 *))M2C_FIELD(data_021261c8+armyId*156,s32 *,spriteSet*40))(unit);
done:
SpawnArmySpecialEffect(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y),M2C_FIELD(view,s16 *,0x6c),func_020a3460(player),view);
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

void func_020a2f38(s32 arg0) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK data_02120404;
    M2C_FIELD(CreateSpriteObject(&data_02120404), s32 *, 0x5C) = arg0;
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

u8 func_020a3060(u8 *arg0) {
    s32 func_020a8560(u32);
    u8 var_r0;

    if (func_020a8560((u32) (*arg0 << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020a3088(M2C_UNK arg0) {
    M2C_UNK LevelUpUnit(M2C_UNK, M2C_UNK, M2C_UNK);
    LevelUpUnit(arg0, 3, 0);
}

void func_020a309c(M2C_UNK arg0) {
    M2C_UNK RefillUnitAmmo(M2C_UNK, M2C_UNK);
    M2C_UNK RefillUnitFuel(M2C_UNK, M2C_UNK);
    RefillUnitAmmo(arg0, 0);
    RefillUnitFuel(arg0, 0);
}

void func_020a30bc(void) {

}

s32 GetRandomCoQuoteTextId(s32 a){
extern u8 data_02126194[];
s32 NextRandomValue(void);
return ((s32 *)(data_02126194+a*0x9c))[NextRandomValue()%3];
}

void func_020a3100(s32 arg0) {
    extern s32 *gCurrentMap;
    M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), s8 *, 0x6815) = 1;
}

void func_020a3128(s32 arg0){
extern s32 *gCurrentMap;
M2C_FIELD(arg0*0x8c+*gCurrentMap,s8 *,0x6815)=0;
}

u8 func_020a3150(s32 a){extern s32 *gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x6815]!=0;}

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

u8 func_020a32a8(s32 a){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;u8 r;if(!((u32)(M2C_FIELD(p,s32 *,108)<<24)>>24))return 0;if(M2C_FIELD(p,u8 *,112))r=1;else r=0;return r;}

u8 *GetPlayerSelectedUnit(s32 a){extern s32 *gCurrentMap;s32 base=*gCurrentMap;s32 p=base+0x67a4+140*a;u32 b;if(!((u32)(M2C_FIELD(p,s32 *,108)<<24)>>24))return 0;b=M2C_FIELD(p,u8 *,112);if(!b)return 0;return (u8 *)(base+0x59a4+14*b);}

s32 GetPlayerArmyVariantIfSet(s32 a) {
    extern s32 *gCurrentMap;
    s32 p = *gCurrentMap + 0x67a4 + 140 * a;
    Word020a334c *w = (Word020a334c *)(p + 108);
    if (w->low == 0) return 0;
    return (u8)w->hi;
}

void func_020a338c(s32 a,s32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0xc00)|((u32)(b<<30)>>20);}

s32 GetPlayerArmyVariant(s32 a){
extern s32 *gCurrentMap;
return (u32)(M2C_FIELD(*gCurrentMap+a*0x8c,s32 *,0x6810)<<20)>>30;
}

void func_020a33f0(s32 a,u32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0x300)|((b<<30)>>22);}

void func_020a3428(s32 a,u32 b){extern s32 *gCurrentMap;s32 p=*gCurrentMap+0x67a4+140*a;M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&~0x3000)|((b<<30)>>18);}

s32 func_020a3460(s32 a){extern s32 *gCurrentMap;return (u32)(M2C_FIELD(*gCurrentMap+140*a,u32 *,0x6810)<<18)>>30;}

void func_020a348c(void) {
    M2C_UNK func_020bcf14();
    func_020bcf14();
}

void func_020a3498(M2C_UNK arg0) {
    void func_020a338c(s32, s32);
    func_020a338c(arg0, 0);
}

#pragma opt_common_subs off
void func_020a34a8(s32 a){u32 v;u32 n;extern s32 *gCurrentMap;s32 p;p=*gCurrentMap;p+=0x3a4;p+=0x6400;p+=a*0x8c;v=*(u32*)(p+0x6c);n=(v<<14)>>28;if(n>=10)return;*(u32*)(p+0x6c)=(v&~0x3c000)|(((n+1)<<28)>>14);}
#pragma opt_common_subs reset
void func_020a34f4(M2C_UNK arg0) {
    s32 GetCoPowerMeterCost(M2C_UNK, M2C_UNK);
    M2C_UNK AddCoPowerMeterPoints(M2C_UNK, s32);
    AddCoPowerMeterPoints(arg0, 0 - GetCoPowerMeterCost(arg0, 2));
}

#pragma opt_common_subs off
s32 GetCoPowerMeterPoints(s32 a) {
    extern s32 *gCurrentMap;
    s32 p = *gCurrentMap + 0x67a4 + 140 * a;
    s32 *w = (s32 *)(p + 108);
    if (((u32)(*w << 24) >> 24) == 0) return 0;
    return (u32)*w >> 21;
}
#pragma opt_common_subs reset
void SetCoPowerMeterPoints(s32 a,s32 b){
 extern s32 *gCurrentMap;
 s32 *p;
 if(b<0)b=0;
 p=(s32 *)(*gCurrentMap+0x67a4+140*a);
 M2C_FIELD(p,u32 *,108)=(M2C_FIELD(p,u32 *,108)&0x1fffff)|((u32)b<<21);
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

s32 RefreshPlayerArmyDisplay(s32 a){
 extern s32 *gCur3DSpriteEngine;
 s32 func_020a3460(s32);
 void func_020a338c(s32,s32);
 void func_020a23c4(void);
 void RefreshMapView(void);
 M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x38)=0;
 M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x40)=0;
 func_020a338c(a,func_020a3460(a));
 func_020a23c4();
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

void func_020a36ec(void *a){s16 xy[2];s32 func_ov000_021aa820(s16 *,s32,s32,s32);if(!func_ov000_021aa820(xy,M2C_FIELD(a,s16 *,0x6c),0,1)){SetSpriteAnimation(a,0);return;}M2C_FIELD(a,s32 *,0x34)=xy[0];M2C_FIELD(a,s32 *,0x38)=xy[1];}

void func_020a3740(void *arg0) {
    M2C_UNK func_020c7874(s32, s32, M2C_UNK, M2C_UNK, void *);
    func_020c7874(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 2, 0x50, arg0);
}

void func_020a3764(void *arg0) {
    RefreshPlayerArmyDisplay(M2C_FIELD(arg0, s16 *, 0x6C));
}

void func_020a3774(s16 arg0) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK data_02120444;
    M2C_FIELD(CreateSpriteObject(&data_02120444), s16 *, 0x6C) = arg0;
}

s32 func_020a3790(s32 arg0) {
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

void func_020a3810(void *a){switch((u32)M2C_FIELD(a,s16 *,0x36)){case 0:PlaySoundEffect(0xd4);return;case 1:PlaySoundEffect(0xd6);return;case 2:PlaySoundEffect(0xd5);return;case 3:PlaySoundEffect(0xd7);return;default:return;}}

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
