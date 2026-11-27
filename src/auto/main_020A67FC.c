/* 34 functions from 0x020A67FC to 0x020A7738 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u32 value:8; u32 rest:24; } Bits020a8c10;
#include "ov000_unit_entry.h"
#include "unit_sprite.h"
static inline s32 unitHealth7074(UnkStruct_ov000_021A860C *p) { s32 Divide(s32,s32);s32 h=p->unk6;if(h==0)return 0;return Divide(h-1,10)+1; }
extern u8 gUnitKindSpriteVariants[], gUnitKindLoadMask[],gUnitKindCargoCount[],gUnitKindLoadClass[];
extern void **gCurrentMap;

s32 ProduceUnit(s32 a, s32 b, s32 c) {
    s32 GetUnitBuildCost(u16, s32);
    s32 CreateOwnedMapUnit(s32, s32, s32);
    void PayPlayerFunds(u16, s32);
    s32 IsPlayerHuman(u16);
    void AddRecordValue(s32, s32);
    void RefreshMapView(void);
    extern void **gCurrentMap;
    s32 r, cost;u16 id;
    void *p;

    cost = GetUnitBuildCost(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), c) * 10;
    p = *gCurrentMap;
    id = M2C_FIELD(p, u16 *, 0x52a4);
    if (M2C_FIELD((u8 *) p + 140u * id, s32 *, 0x67a4) < cost) {
        return 0;
    }
    r = CreateOwnedMapUnit(a, b, c);
    if (!r) return 0;
    PayPlayerFunds(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4), cost);
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4))) {
        AddRecordValue(c + 0x28, 1);
    }
    RefreshMapView();
    return r;
}

#pragma peephole off
/* Mark every map unit slot empty (clear its kind bits, keeping the owner bits)
 * and clear the cursor's unit. */
void ResetMapUnits(void) {
    extern void **gCurrentMap;
    s32 i;
    s32 offset;
    void *p;
    i = 0;
    offset = 0;
    do {
        i++;
        p = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS;
        M2C_FIELD(p, u8 *, offset) &= ~MAP_UNIT_KIND_MASK;
        offset += MAP_UNIT_STRIDE;
    } while (i < MAP_UNIT_COUNT);
    M2C_FIELD(*gCurrentMap, u16 *, MAP_UNIT_SLOT_CURSOR) = 0;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID) = 0;
    M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT) = 0;
}
#pragma peephole on
void func_020a694c(void) {

}

/* Mark the unit standing on map cell (x, y) as a repair neighbour by setting the
 * repair scratch bit in its record; cells off the map are ignored. */
void MarkRepairNeighbour(s32 x, s32 y) {
    extern void **gCurrentMap;
    void *map;
    void *unit;
    if (x >= 0 && y >= 0) {
        map = *gCurrentMap;
        if (x < M2C_FIELD(map, u16 *, MAP_WIDTH) && y < M2C_FIELD(map, u16 *, MAP_HEIGHT)) {
            unit = (u8 *)map + MAP_UNIT_RECORDS + M2C_FIELD(map, u8 *, x + M2C_FIELD((u8 *)map + y * 2, u16 *, MAP_ROW_OFFSETS)) * MAP_UNIT_STRIDE;
            if (unit != 0) M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) |= UNIT_FLAG_REPAIR_TMP;
        }
    }
}

#pragma opt_common_subs off
/* Turn-start repair pass: clears the repair-neighbour scratch bit on every unit,
 * then for every unit flagged for repair that the current player owns heals one
 * HP (never below one) and marks its four orthogonal neighbours; finally folds
 * the neighbour marks into the repair flag. */
void ApplyTurnRepairs(void){
s32 IsUnitMarkedForRepair(void *);s32 GetUnitOwner(void *);
s32 i,j,k,x,y;UnkStruct_ov000_021A860C *unit,*first,*last;
for(i=1;i<256;i++){
first=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[i];
if(first->unk0)M2C_FIELD(first,u16 *,MAP_UNIT_FLAGS)&=~UNIT_FLAG_REPAIR_TMP;
}
for(j=1;j<256;j++){
unit=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[j];
if(unit->unk0 && IsUnitMarkedForRepair(unit)){
x=M2C_FIELD(unit,u8 *,1);y=M2C_FIELD(unit,u8 *,2);
if(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)==GetUnitOwner(unit)){
if(unit->unk6>10)unit->unk6-=10;else unit->unk6=1;
}
MarkRepairNeighbour(x-1,y);MarkRepairNeighbour(x+1,y);MarkRepairNeighbour(x,y-1);MarkRepairNeighbour(x,y+1);
}
}
for(k=1;k<256;k++){
last=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[k];
if(last->unk0){
if(M2C_FIELD(last,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_REPAIR_TMP)M2C_FIELD(last,u16 *,MAP_UNIT_FLAGS)|=UNIT_FLAG_REPAIR;
M2C_FIELD(last,u16 *,MAP_UNIT_FLAGS)&=~UNIT_FLAG_REPAIR_TMP;
}
}
}
#pragma opt_common_subs reset
/* Unit-sprite class update: copy the tile x/y of the map unit the sprite draws
 * (the record it holds at UNIT_SPRITE_UNIT) so the sprite follows its unit. */
void UnitSprite_UpdateTilePosition(void *sprite) {
    void *unit;

    unit = M2C_FIELD(sprite, void **, UNIT_SPRITE_UNIT);
    M2C_FIELD(sprite, s32 *, UNIT_SPRITE_TILE_X) = (s32) M2C_FIELD(unit, u8 *, 1);
    M2C_FIELD(sprite, s32 *, UNIT_SPRITE_TILE_Y) = (s32) M2C_FIELD(unit, u8 *, 2);
}

/* Unit-sprite state handler: explode the unit the sprite draws (the BattleMapUnit
 * pointer it holds at +0x54) and mark the units around the tile it sits on
 * (+0x34/+0x38), scanning the range-2 area pattern with no reference unit. */
void UnitSprite_ExplodeUnit(void *sprite) {
    M2C_UNK MarkEnemyUnitsInArea(M2C_UNK, s32, s32, M2C_UNK);
    M2C_UNK ExplodeUnit(s32);
    ExplodeUnit(M2C_FIELD(sprite, s32 *, 0x54));
    MarkEnemyUnitsInArea(0, M2C_FIELD(sprite, s32 *, 0x34), M2C_FIELD(sprite, s32 *, 0x38), 2);
}

/* Unit-sprite class update: place the map cursor at the tile of the unit the
 * sprite shows (its tile x/y were set from the unit record at +0x54), then keep
 * the sprite's animation held while a battle effect runs, resuming it when none
 * is active. */
void UnitSprite_PlaceCursorAndResume(void *sprite) {
    extern void **gCurrentMap;
    s32 IsBattleEffectActive(void);
    void Sprite_ResumeAnimation(void *);
    void (*cursorCallback)(s32, s32, s32);
    cursorCallback = (void (*)(s32, s32, s32))M2C_FIELD(gCurrentMap[1], void **, MAPVIEW_CURSOR_CB);
    if (cursorCallback != 0) cursorCallback(M2C_FIELD(sprite, s32 *, 0x34) * 16, M2C_FIELD(sprite, s32 *, 0x38) * 16, 10);
    if (IsBattleEffectActive() != 0) return;
    Sprite_ResumeAnimation(sprite);
}

/* Create the sprite that draws map unit `unit` blowing up (the explosion
 * animation script) and remember the unit it draws.  The effect that spawned the
 * sprite is passed as `unused`. */
void SpawnUnitSprite(BattleMapUnitHead *unit, void *unused) {
    void *CreateSpriteObject(M2C_UNK *);
    extern M2C_UNK gUnitExplosionSpriteScript;
    M2C_FIELD(CreateSpriteObject(&gUnitExplosionSpriteScript), s32 *, UNIT_SPRITE_UNIT) = (s32) unit;
}

/* Initialise an area-damage battle effect: set its two active flags, allocate
 * one bit per map cell for the cells it has already damaged and clear them. */
void InitAreaDamageEffect(void *effect){
u8 *HeapAllocBlock(s32);
u8 *covered; s32 x; s32 y; u8 *map; u32 cell;
M2C_FIELD(effect,s32 *,0x5c)=1;M2C_FIELD(effect,s32 *,0x60)=1;
covered=HeapAllocBlock(MAP_CELL_LAYER_BYTES/8);M2C_FIELD(effect,u8 **,0x54)=covered;
map=*gCurrentMap;
for(y=0;y<M2C_FIELD(map,u16 *,MAP_HEIGHT);y++){
for(x=0;x<M2C_FIELD(map,u16 *,MAP_WIDTH);x++){
cell=x+M2C_FIELD((map+((u32)y<<1)),u16 *,MAP_ROW_OFFSETS);
covered[cell>>3]&=((1<<(cell&7)) ^ -1);
map=*gCurrentMap;
}}
}

void func_020a6cbc(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x54));
}

void ApplyAreaDamageEffect(void *effect){
void DamageUnitAtTile(s32,s32,s32);s32 IsBattleEffectActive(void);s32 IsUnitCapturing(void *);void InitAreaScan(void *,s32,s32,s32,s32,s32);s32 NextAreaTile(void *);void Sprite_ResumeAnimation(void *);
extern u16 gPlayerUnitIdBase[];
u8 *covered=M2C_FIELD(effect,u8 **,0x54);s32 found=0,player,unitId;u32 index;s32 scan[8];UnkStruct_ov000_021A860C *unit;
/* Area-damage effect: for the first eligible unit, apply 40 damage to every
   unit within two tiles of it and spawn its sprite.  The eligibility test
   IsUnitCapturing is always false in this build, so the effect only finishes. */
if(IsBattleEffectActive())return;
for(player=1;player<5;player++){
for(unitId=gPlayerUnitIdBase[player]+1;unitId<gPlayerUnitIdBase[player]+51;unitId++){
unit=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[unitId];
if(unit->unk0 && IsUnitCapturing(unit)){
InitAreaScan(scan,2,M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2),M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH),M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT));
for(;;){if(!NextAreaTile(scan))break;
index=scan[4]+M2C_FIELD((u8 *)*gCurrentMap+scan[5]*2,u16 *,MAP_ROW_OFFSETS);
if(!(u8)(covered[index>>3]&(1<<(index&7)))){
DamageUnitAtTile(scan[4],scan[5],40);
index=scan[4]+M2C_FIELD((u8 *)*gCurrentMap+scan[5]*2,u16 *,MAP_ROW_OFFSETS);
covered[index>>3]|=1<<(index&7);
}
}
SpawnUnitSprite((s32)unit,effect);
found++;if(found==1)return;
}
}
}
if(!found)Sprite_ResumeAnimation(effect);
}

/* Turn start for the current player's units: clear the per-turn action bits on every
 * unit that is not loaded in a transport, and clear bit 1 on the units carried by a
 * carrier so they may act again after unloading. */
void func_020a6eb0(void){
extern u16 gPlayerUnitIdBase[];s32 IsCarrierUnitKind(u32);
s32 i;UnkStruct_ov000_021A860C *p;u8 n;
for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_GROUP_SCAN;i++){
p=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[i];
if(p->unk0 && !(M2C_FIELD(p,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED)){
M2C_FIELD(p,u16 *,MAP_UNIT_FLAGS)&=~UNIT_FLAG_TURN_MASK;
if(IsCarrierUnitKind(p->unk0)){
n=p->unkC[0];
if(n)M2C_FIELD(&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[n],u16 *,MAP_UNIT_FLAGS)&=~1;
n=p->unkC[1];
if(n)M2C_FIELD(&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+MAP_UNIT_RECORDS))[n],u16 *,MAP_UNIT_FLAGS)&=~1;
}
}
}}

/* Spawn the area-damage effect sprite on the default layer: it allocates its
 * covered-cell bitmap (InitAreaDamageEffect), applies the area damage each frame
 * and resets the current player's units for the new turn.  Called when a turn
 * ends (EndPlayerTurn) and by the AI weather command. */
void SpawnAreaDamageEffect(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gAreaDamageEffectClass;
    CreateSpriteFromClass(&gAreaDamageEffectClass, 7);
}

#pragma scheduling off
/* Whether the transport unit `unit` can load a unit of kind `kind`: the unit's
 * kind must have a free cargo slot (its capacity is 1 or 2) and the load table
 * must allow a carrier of the unit's load class to carry that kind. */
s32 CanUnitLoadKind(u8 *unit, s32 kind) {
    s32 capacity, index, allowed;
    index = ((u32)(unit[MAP_UNIT_KIND] << 26) >> 26) * UNIT_KIND_STATS_SIZE;
    capacity = gUnitKindCargoCount[index];
    {
        u32 loadClass = gUnitKindLoadClass[index];
        u8 *row = gUnitKindLoadMask + kind * UNIT_KIND_STATS_SIZE;
        allowed = loadClass[row];
    }
    if (!capacity) return 0;
    if (!allowed) return 0;
    if (capacity == 2 && unit[MAP_UNIT_FIRST_CARRIED + 1]) return 0;
    if (capacity == 1 && unit[MAP_UNIT_FIRST_CARRIED]) return 0;
    return 1;
}
#pragma scheduling reset
/* Whether `unit` may join (merge with) `target`: same unit kind and owner, neither
   is already carrying a unit, the target has lost HP (so the merge actually heals)
   and the two are not both the currently selected unit. */
s32 CanUnitsJoin(UnkStruct_ov000_021A860C *unit,UnkStruct_ov000_021A860C *target){
s32 Divide(s32,s32);s32 IsUnitSelected(void *);
s32 targetIndex,unitIndex,health;
if(unit->unk0!=target->unk0)return 0;
if(target)targetIndex=((u8 *)target-((u8 *)*gCurrentMap+0x59a4))/14;else targetIndex=0;
if(unit)unitIndex=((u8 *)unit-((u8 *)*gCurrentMap+0x59a4))/14;else unitIndex=0;
if((unitIndex&0xc0)!=(targetIndex&0xc0))return 0;
if(unit->unkC[0]||target->unkC[0])return 0;
health=unitHealth7074(target);
if(health==10)return 0;
if(IsUnitSelected(unit)&&IsUnitSelected(target))return 0;
return 1;
}

#pragma opt_instruction_scheduling off
void DamageUnitAtTile(s32 x,s32 y,s32 amount) {
s32 IsUnitKindClass6(u32);
void *base;
u8 *p;
u32 type; s16 health;
if(x<0 || y<0)return;
base=*gCurrentMap;
if(x>=M2C_FIELD(base,u16 *,MAP_WIDTH) || y>=M2C_FIELD(base,u16 *,MAP_HEIGHT))return;
p=(u8 *)base+MAP_UNIT_RECORDS+(s16)M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_UNIT_ID)*(s16)MAP_UNIT_STRIDE;
type=(u32)(p[0]<<26)>>26;
if(!type)return;
if(M2C_FIELD(p,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED)return;
if(IsUnitKindClass6(type))return;
health=((UnkStruct_ov000_021A860C *)p)->unk6;
if(amount+1>health) ((UnkStruct_ov000_021A860C *)p)->unk6=1;
else ((UnkStruct_ov000_021A860C *)p)->unk6=(u16)(health-amount);
}
#pragma opt_instruction_scheduling reset
M2C_UNK *func_020a7278(void) {
    extern M2C_UNK data_02121e08;
    return &data_02121e08;
}

M2C_UNK *func_020a7284(void) {
    extern M2C_UNK data_02121020;
    return &data_02121020;
}

s32 func_020a7290(void) {
    return 0x78;
}

s32 GetUnitVariantIndex(s32 a,u8 b){return ((u8 *)b)[(s32)gUnitKindSpriteVariants+a*0x70];}

/* The sprite tile index (four tiles per sprite variant) that player `player`'s
 * units of `kind` use: the player record's cached sprite state picks the variant. */
s32 GetPlayerUnitSpriteTile(s32 player, s32 kind) {
    s32 GetUnitVariantIndex(s32, u8);
    extern void **gCurrentMap;
    return GetUnitVariantIndex(kind, M2C_FIELD(((player * MAP_PLAYER_STRIDE) + (s32)*gCurrentMap), u8 *, PLAYER_SPRITE_STATE_OFF)) * 4;
}

void *func_020a72e8(s32 arg0) {
    extern M2C_UNK gArmyPalettes;
    return (u8 *)&gArmyPalettes + ((arg0 - 1) << 5);
}

s32 GetSubmergedDamageRow(s32 arg0, s32 arg1) {
    s32 var_r0;

    var_r0 = arg0;
    if (arg1 == 0) {
        return var_r0;
    }
    if (var_r0 == 0x16) {
        var_r0 = 0x1B;
    }
    return var_r0;
}

/* Return the 1-based player that owns the unit record at `p`, from its slot in
 * the map's 256-entry unit array (64 slots per player).  A NULL pointer reports
 * player 1.  The K&R header keeps the non-prototype calls in this file valid. */
s32 GetUnitOwner(p)
void *p;
{
    s32 slot;
    if (!p) slot = 0;
    else slot = ((s32)p - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
    return (slot >> MAP_UNIT_OWNER_SHIFT) + 1;
}

u32 GetMapUnitKind(u8 *arg0) {
    return (u32) (*arg0 << 0x1A) >> 0x1A;
}

/* Damage-percentage bonus of `unit` attacking from tile (x,y): the owner's
   power bonus, -30 in a sandstorm unless that player's sprite state is 10, then
   the unit's weapon bonus and its stat-block bonus.  0 for excluded kinds. */
s32 GetUnitDamageBonus(u8 *unit,s32 x,s32 y){
s32 IsUnitKindClass6(u32);s32 GetPlayerAttackPropertyBonus(s32);s32 GetUnitOwnerGroupAttackBonus(void *);s32 GetUnitStatDamageBonus(void *,s32,s32);
s32 bonus=0,owner;
if(IsUnitKindClass6((u32)(unit[0]<<26)>>26))return bonus;
if(unit){if(!unit)owner=0;else owner=((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14;owner=(owner>>6)+1;}else owner=0;
bonus+=GetPlayerAttackPropertyBonus(owner);
if(unit){if(!unit)owner=0;else owner=((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14;owner=(owner>>6)+1;}else owner=0;
if(((Bits020a8c10 *)((u8 *)*gCurrentMap+owner*140+0x6810))->value!=10){
if(M2C_FIELD(*gCurrentMap,u8 *,0x5158)==3)bonus-=30;
}
bonus+=GetUnitOwnerGroupAttackBonus(unit);
return bonus+GetUnitStatDamageBonus(unit,x,y);
}

/* Attack-power bonus (the part GetUnitAttackPower adds its 100 base to) of
   `unit` at tile (x, y): the owner's power bonus, the unit's rank bonus and the
   stat block's valueA; 0 for the unit kinds the bonus does not apply to. */
s32 GetUnitAttackPowerBonus(u8 *unit, s32 x, s32 y) {
    s32 IsUnitKindClass6(u32);
    s32 GetPlayerAttackPropertyBonusAlt(s32);
    s32 GetUnitOwnerGroupDefenseBonus(void *);
    s32 GetUnitAttackPowerStatBonus(void *, s32, s32);
    s32 bonus = 0, owner;
    if (IsUnitKindClass6((u32)(unit[0] << 26) >> 26)) return bonus;
    if (unit) {
        if (!unit) owner = 0;
        else owner = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        owner = (owner >> 6) + 1;
    } else owner = 0;
    bonus += GetPlayerAttackPropertyBonusAlt(owner);
    bonus += GetUnitOwnerGroupDefenseBonus(unit);
    return bonus + GetUnitAttackPowerStatBonus(unit, x, y);
}

s32 func_020a7558(void) {
    M2C_UNK GetUnitOwner();
    GetUnitOwner();
    return 2;
}

/* Capture points a unit contributes per turn: its health in HP bars plus its
 * commander's capture-rate bonus (its stat block's capture stat). */
s32 GetUnitCaptureRate(void *unit, s32 x, s32 y) {
    s32 Divide(s32, M2C_UNK);
    s32 GetUnitCaptureBonus(void *, M2C_UNK, M2C_UNK);
    s32 healthBars;
    u32 health;

    GetUnitOwner();
    health = (u32) (M2C_FIELD(unit, u16 *, MAP_UNIT_HEALTH) << 0x19) >> 0x19;
    if (health == 0) {
        healthBars = 0;
    } else {
        healthBars = Divide(health - 1, 0xA) + 1;
    }
    return healthBars + GetUnitCaptureBonus(unit, x, y);
}

/* Effective movement of a unit: its kind's base movement plus the stat block's
 * movement bonus, minus one in rain unless its owner's status index is 10. */
s32 GetUnitMovement(void *arg0) {
    s32 GetUnitKindMoveRange(u32);
    s32 GetUnitMoveBonus(void *, u8, u8);
    u8 *unit = arg0;
    s32 base, bonus, owner, penalty;

    GetUnitOwner(unit);
    base = GetUnitKindMoveRange((u32)(unit[0] << 26) >> 26);
    bonus = GetUnitMoveBonus(unit, unit[1], unit[2]);
    penalty = 0;
    if (unit) {
        if (!unit) owner = 0;
        else owner = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        owner = (owner >> 6) + 1;
    } else owner = 0;
    if (((Bits020a8c10 *)((u8 *)*gCurrentMap + owner * MAP_PLAYER_STRIDE + MAP_PLAYER_STATES + PLAYER_REC_SPRITE))->value != 10)
        penalty = -(M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER) == WEATHER_RAIN);
    return penalty + (base + bonus);
}

/* How far `unit` can still move this turn: its remaining fuel divided by its
 * owner's fuel rate, capped at its kind's movement range. */
s32 GetUnitRemainingMoveRange(BattleMapUnitHead *unit) {
    s32 GetUnitMovement(void *);
    s32 GetPlayerFuelRate(s32);
    s32 Divide(s32, s32);
    u32 fuel;
    s32 moveRange, range;

    fuel = unit->fuel;
    moveRange = GetUnitMovement(unit);
    range = Divide(fuel, GetPlayerFuelRate(GetUnitOwner(unit)));
    if (range >= moveRange) range = moveRange;
    return range;
}

/* Highest attack range of unit `unit`: its kind's base range plus the
 * attack-range bonus from its commander's stat block, which a unit only gets
 * when its base range is 2 or more. */
s32 GetUnitAttackRangeMax(u8 *unit) {
    s32 GetUnitKindMaxAttackRange(s32);
    s32 GetUnitAttackRangeBonus(void *, u8, u8);
    s32 maxRange, bonus;

    GetUnitOwner(unit);
    maxRange = GetUnitKindMaxAttackRange((u32)(unit[0] << 26) >> 26);
    bonus = GetUnitAttackRangeBonus(unit, unit[1], unit[2]);
    if (maxRange >= 2) maxRange += bonus;
    return maxRange;
}

/* Radius in tiles of the attack-range scan around battle-map `unit`: a fixed five
 * tiles plus the range bonus its commander grants it. */
s32 GetUnitAttackRangeRadius(void *unit) {
    s32 GetUnitAttackRangeBonus(void *, u8, u8);
    GetUnitOwner();
    return GetUnitAttackRangeBonus(unit, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y)) + 5;
}

