/* 32 functions from 0x020B6168 to 0x020B7138 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
typedef struct { u8 pad[0x48]; u32 distance:10; u32 flags:22; } RangeEffect;

/* Fields of the Aurora order strike's staging object (class gAuroraEffectClass
 * in main_020B6168.c): where the strike lands and which queued target starts it. */
#define AURORA_EFFECT_X            0x38 /* s32: strike cell x, biased by 1 */
#define AURORA_EFFECT_Y            0x3C /* s32: strike cell y, biased by 1 */
#define AURORA_EFFECT_FIRST_TARGET 0x6C /* s16: selection-queue index of the first target */
#define AURORA_EFFECT_STAGE        0x56 /* s16: staged-load step (0..3), see StageAuroraEffect */

/* Fields of the strike sprite StageAuroraEffect builds from the staging object:
 * where the target queue starts and the aim/smoke/damage sheets it loaded. */
#define AURORA_STRIKE_FIRST_TARGET 0x58 /* s32: target-list index of the first target to damage */
#define AURORA_STRIKE_AIM_GRAPHIC 0x5C /* s32: loaded "arura_aim" sheet offset */
#define AURORA_STRIKE_SMOKE_GRAPHIC 0x60 /* s32: loaded smoke sheet offset, used as the smoke frame */
#define AURORA_STRIKE_DAMAGE_GRAPHIC 0x64 /* s32: loaded "damage" sheet offset, 0 while not loaded */

/* The gas order effect task (main_020B7138.c's CreateGasStormEffect): the target
 * cell it gases and the target-list index where the order's targets start. */
#define GAS_EFFECT_TARGET_X     0x3C /* s32: target cell x */
#define GAS_EFFECT_TARGET_Y     0x40 /* s32: target cell y */
#define GAS_EFFECT_FIRST_TARGET 0x44 /* s32: target-list index of the order's first target */

void func_020b6168(void *arg0) {
    extern void **gCurrentMap;
    M2C_UNK PlaySoundAtTile(M2C_UNK, s32, s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 SetAnimatedSpriteFrame(void *, s32);
    void CreateScreenOffsetEffect(s32, s32, s32);
    void CreateScreenFlash(s32, s32, s32, s32);
    M2C_UNK CancelMapCursorAnimation(void);
    void ApplyAreaDamageTile(void *);

    u8 *core;
    register s32 xc,yc,range;
    s32 minX, minY, maxY;
    register s32 maxX;
    s32 t;
    register void *p;
    register s32 x,y,dy,dx;
    s32 dist, adx, ady;
    u32 bits;


    range = M2C_FIELD(arg0, s16 *, 0x4C);
    xc = M2C_FIELD(arg0, s16 *, 0x44);
    yc = M2C_FIELD(arg0, s16 *, 0x46);

    minX = xc - range;
    if (minX < 0) minX = 0;
    minY = yc - range;
    if (minY < 0) minY = 0;

    core = (u8 *)*gCurrentMap;
    maxX = (s32)M2C_FIELD(core, u16 *, 0x5144) - 1;
    t = xc + range;
    if (t < maxX) maxX = t;

    maxY = (s32)M2C_FIELD(core, u16 *, 0x5146) - 1;
    t = yc + range;
    if (t < maxY) maxY = t;

    if (minY <= maxY) {
        for (y = minY; y <= maxY; y++) {
            for (x = minX; x <= maxX; x++) {
                dx = M2C_FIELD(arg0,s16 *,0x44) - x;
                dist=0;
                if (dx > 0) dist += dx;
                else dist += x - M2C_FIELD(arg0,s16 *,0x44);
                dy = M2C_FIELD(arg0,s16 *,0x46) - y;
                if (dy > 0) dist += dy;
                else dist += y - M2C_FIELD(arg0,s16 *,0x46);
                if (dist < 0) continue;
                if (dist > M2C_FIELD(arg0,s16 *,0x4c)) continue;

                if (dy < 0) dy=-dy;
                if (dx < 0) dx=-dx;

                p = CreateEffectMapSprite((M2C_UNK *)((u8 *)arg0 + 0x34), x, y, 0x10, 0, 0, arg0);
                SetAnimatedSpriteFrame(p, 2);
                ((RangeEffect *)p)->distance=(u8)((dx+dy)*8);
                M2C_FIELD(p, s32 *, 0x58) = x;
                M2C_FIELD(p, s32 *, 0x5C) = y;
                M2C_FIELD(p, s32 *, 0x60) = M2C_FIELD(arg0, s16 *, 0x4E);
                M2C_FIELD(p, void (**)(void *), 0x6C) = ApplyAreaDamageTile;
            }
        }
    }

    CreateScreenOffsetEffect(2, 0x3C, 0);
    CreateScreenFlash(4, 0, 2, 0);
    PlaySoundAtTile(0x93, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
    CancelMapCursorAnimation();
}

/* Step the screen-transition down-counter (func_020b524c -> CloseEffectNarcArchive, which
 * fires CloseNarcArchive once the counter wraps to zero), then finalize the current
 * map view and run its registered callbacks (RefreshMapView -> RefreshMapUnitDisplay +
 * func_020cfd38). */
void func_020b6320(void) {
    M2C_UNK RefreshMapView();
    M2C_UNK func_020b524c();
    func_020b524c();
    RefreshMapView();
}

/* Spawn a path-marker task at tile (x, y) with the given range and tile index,
 * copy its label string into the task, then move the view onto the marker. */
void CreateMissileNMarker(s16 x, s16 y, s16 range, s16 tileIdx, s32 parent) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK gMissileMarkerClass, gMissileNName;
    void *task;
    task = CreateSpriteObject(&gMissileMarkerClass, parent);
    M2C_FIELD(task, s16 *, 0x44) = x;
    M2C_FIELD(task, s16 *, 0x46) = y;
    M2C_FIELD(task, s16 *, 0x4C) = range;
    M2C_FIELD(task, s16 *, 0x4E) = tileIdx;
    M2C_FIELD(task, s32 *, 0x50) = 0;
    StringCopy(task + 0x34, &gMissileNName);
    PanMapViewToTile(x, y);
}

/* Spawn the "missile_b" missile marker task at tile (x, y) with the given range
 * and tile index, copy its label string into the task, then move the view onto
 * the marker. */
void CreateMissileBMarker(s16 x, s16 y, s16 range, s16 tileIdx, s32 parent) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK gMissileMarkerClass, gMissileBName;
    M2C_UNK *g = &gMissileMarkerClass;
    void *p;
    p = CreateSpriteObject(g, parent);
    M2C_FIELD(p, s16 *, 0x44) = x;
    M2C_FIELD(p, s16 *, 0x46) = y;
    M2C_FIELD(p, s16 *, 0x4C) = range;
    M2C_FIELD(p, s16 *, 0x4E) = tileIdx;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    StringCopy(p + 0x34, &gMissileBName);
    PanMapViewToTile(x, y);
}

/* Spawn the "missile_e" missile marker task at tile (x, y) with the given range
 * and tile index, copy its label string into the task, then move the view onto
 * the marker. */
void CreateMissileEMarker(s16 x, s16 y, s16 range, s16 tileIdx, s32 parent) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK gMissileMarkerClass, gMissileEName;
    M2C_UNK *g = &gMissileMarkerClass;
    void *p;
    p = CreateSpriteObject(g, parent);
    M2C_FIELD(p, s16 *, 0x44) = x;
    M2C_FIELD(p, s16 *, 0x46) = y;
    M2C_FIELD(p, s16 *, 0x4C) = range;
    M2C_FIELD(p, s16 *, 0x4E) = tileIdx;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    StringCopy(p + 0x34, &gMissileEName);
    PanMapViewToTile(x, y);
}

/* Spawn the unit flare effect over the unit the task points at (its +0x5C):
 * take the unit's tile and owner, shift the flare left or right of the tile by
 * the owner's facing byte, then load the flare sheet, place the flare sprite on
 * the tile and play the hit sound there. */
void SpawnUnitFlareEffect(void *task) {
    void ResetEffectSpritePool(void);
    void LoadEffectSpriteSheet(M2C_UNK *, s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 SetAnimatedSpriteFrame(void *, s32);
    M2C_UNK PlaySoundAtTile(M2C_UNK, s32, s32);
    extern void **gCurrentMap;
    extern M2C_UNK gUnitFlareName;
    extern M2C_UNK gUnitFlareSprite;
    u8 *unit;
    s32 owner, x, y;

    unit = M2C_FIELD(task, u8 **, 0x5c);
    x = unit[MAP_UNIT_X] << 4;
    y = unit[MAP_UNIT_Y] << 4;
    if (unit) {
        if (!unit) owner = 0;
        else owner = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
        owner = (owner >> 6) + 1;
    } else {
        owner = 0;
    }
    if (*((u8 *)*gCurrentMap + owner * MAP_PLAYER_STRIDE + MAP_PLAYER_STATES + 0x28) != 0) {
        x = x + 6;
        y -= 2;
    } else {
        x = x - 6;
        y -= 2;
    }
    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&gUnitFlareName, 0);
    {
        void *flare = CreateEffectMapSprite(&gUnitFlareSprite, x, y, 0x30, 0, 0, task);
        SetAnimatedSpriteFrame(flare, 0);
    }
    {
        u8 *unit2 = M2C_FIELD(task, u8 **, 0x5c);
        PlaySoundAtTile(0x12f, unit2[MAP_UNIT_X], unit2[MAP_UNIT_Y]);
    }
}

/* Spawn the unit-flare effect object that follows `unit`: the object remembers the
 * unit in its +0x5C field (the unit its first update, SpawnUnitFlareEffect, will
 * draw the flare over) and the map view pans onto the unit. */
void CreateUnitFlareSprite(void *unit) {
    void *CreateSpriteObject();
    M2C_UNK PanMapViewToUnit(void *);
    extern M2C_UNK gUnitFlareSpriteClass;

    M2C_FIELD(CreateSpriteObject(&gUnitFlareSpriteClass), s32 *, 0x5C) = (s32) unit;
    PanMapViewToUnit(unit);
}

#pragma opt_propagation off
void UpdateSmallFlareSprite(void *arg0) {
s32 EaseInterpolate(s32,s32,s32,u16,s32);M2C_UNK func_0208c0d0(void *,u8);
s32 bits=M2C_FIELD(arg0,u32 *,0x48);
u32 high=(u32)bits>>21;
u16 top=(u16)high,bottom=(u16)(((u32)bits<<11)>>21);
s32 a=EaseInterpolate(4,31,0,top,bottom);
s32 b=EaseInterpolate(4,0,0x40000,top,bottom);
func_0208c0d0(arg0,(u8)a);M2C_FIELD(arg0,s32 *,0x40)=b;
}
#pragma opt_propagation reset
void InitFallingFlarePosition(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_r2 - 0x600);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r2;
}

/* Per-frame update of a falling "flare" sprite: eases its y from the descent start
 * to the target the sprite was given (its +0x58 and +0x5C) over the fade duration in
 * its SpriteTimer, and every 16 elapsed frames drops a copy of the flare sheet at
 * the sprite's current position. */
void UpdateFlareSprite(void *sprite) {
    s32 EaseInterpolate(s32, s32, s32, u16, s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK SetAnimatedSpriteFrame(void *, s32);
    extern M2C_UNK gFlareName;
    u16 elapsed;
    u32 bits;
    void *copy;
    bits = M2C_FIELD(sprite, u32 *, 0x48);
    elapsed = (u16)(bits >> 21);
    M2C_FIELD(sprite, s32 *, 0x38) = EaseInterpolate(EASE_LINEAR, M2C_FIELD(sprite, s32 *, 0x58), M2C_FIELD(sprite, s32 *, 0x5C), elapsed, (u16)((bits << 11) >> 21));
    if ((s32)elapsed % 16 != 0) return;
    copy = (void *)CreateAnimatedMapSprite(&gFlareName, 0, 0, 0x10, 0, 0, sprite);
    SetAnimatedSpriteFrame(copy, 2);
    M2C_FIELD(copy, s32 *, 0x34) = M2C_FIELD(sprite, s32 *, 0x34);
    M2C_FIELD(copy, s32 *, 0x38) = M2C_FIELD(sprite, s32 *, 0x38);
}

/* Spawn a falling flare over the task's cell: reset the effect sprite pool, load
 * the flare sheet, place the flare sprite on the task's tile with the descent
 * initialiser as its create callback and the flare update as its per-frame one,
 * then play the flare launch sound there. */
void CreateFallingFlareSprite(void *task) {
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK SetAnimatedSpriteFrame(void *, s32);
    void InitFallingFlarePosition(void *);
    void UpdateFlareSprite(void *);
    extern M2C_UNK gFallingFlareName, gFallingFlareSprite;
    void *flare;
    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&gFallingFlareName, 0);
    flare = CreateEffectMapSprite(&gFallingFlareSprite, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46), 16, 0, 0, task);
    SetAnimatedSpriteFrame(flare, 1);
    M2C_FIELD(flare, void (**)(void *), 0x68) = InitFallingFlarePosition;
    M2C_FIELD(flare, void (**)(void *), 0x6C) = UpdateFlareSprite;
    PlaySoundAtTile(0x130, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46));
}

/* Spawn the small "flare_s" effect over the task's cell: reset the effect sprite
 * pool, load the flare sheet, place the flare sprite on the task's tile with the
 * small-flare update as its per-frame callback, cancel the cursor animation and
 * play the flare sound there. */
void CreateSmallFlareSprite(void *task) {
    M2C_UNK SetAnimatedSpriteFrame(void *, M2C_UNK);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    M2C_UNK CancelMapCursorAnimation();
    extern M2C_UNK gSmallFlareName;
    extern M2C_UNK gSmallFlareSprite;
    void UpdateSmallFlareSprite(void *);
    void *flare;

    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&gSmallFlareName, 0);
    flare = CreateEffectMapSprite(&gSmallFlareSprite, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46), 0x10, 0, 0, task);
    SetAnimatedSpriteFrame(flare, 0);
    M2C_FIELD(flare, void (**)(void *), 0x6C) = UpdateSmallFlareSprite;
    CancelMapCursorAnimation();
    PlaySoundAtTile(0x131, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46));
}

/* Last step of the missile-strike effect script: mark the two-tile blast area
 * around the effect's map tile on team A's threat layer as directly threatened
 * for the current player, then redraw the map view. */
void MarkBlastThreatArea(void *marker) {
    M2C_UNK MarkThreatBitmap(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK RefreshMapView(void);
    extern void **gCurrentMap;
    void **mapRef = gCurrentMap;
    void *p = marker;
    u8 player = (u8)M2C_FIELD(*mapRef, u16 *, MAP_CURRENT_PLAYER);
    MarkThreatBitmap(M2C_FIELD(p, s16 *, 0x44), M2C_FIELD(p, s16 *, 0x46), 2, SIDE_TEAM_A, player, 2);
    RefreshMapView();
}

/* Spawn the falling-flare strike effect at tile (x, y) under `parent` and move the
 * map view onto that tile.  The effect's script drops a flare, bursts a small
 * flare and marks the blast threat area. */
void CreateFallingFlareStrike(s16 x, s16 y, M2C_UNK parent) {
    extern M2C_UNK gFallingFlareStrikeClass;
    void *temp_r0;

    void *CreateSpriteObject();
 temp_r0 = CreateSpriteObject(&gFallingFlareStrikeClass, parent);
    M2C_FIELD(temp_r0, s16 *, 0x44) = x;
    M2C_FIELD(temp_r0, s16 *, 0x46) = y;
    PanMapViewToTile(x, y);
}

#pragma opt_propagation off
void func_020b6814(void *p){
s32 CreateExplosionEffect(s32,s32,s32);s32 CreateTerrainBlastEffect(s32,s32,void*,...);s32 CreateMapOrderEffectSprite(s32,void*);s32 CreateLineAttackEffectSprite(s32,void*);
s32 a=M2C_FIELD(p,s32*,0x34);
if(M2C_FIELD(p,s16*,0x6e)>0){CreateExplosionEffect(M2C_FIELD(p,s32*,0x38),M2C_FIELD(p,s32*,0x3c),0);return;}
switch(M2C_FIELD(p,s16*,0x6c)){
case 0:break;case 1:CreateTerrainBlastEffect(M2C_FIELD(p,s32*,0x38),M2C_FIELD(p,s32*,0x3c),p);return;
case 2:break;case 3:break;case 4:CreateMapOrderEffectSprite(a,p);return;case 5:break;case 6:case 7:CreateLineAttackEffectSprite(a,p);return;default:break;
}}
#pragma opt_propagation reset
/* Create the battle-preview sprite for the destructible feature `feature` under
 * `parent`: place it at the feature's effect tile and carry the feature's order
 * type as the sprite's mode and the feature's value (its remaining HP) as its
 * value. */
s32 CreateFeaturePreviewSprite(MapOrder *feature,s32 parent) {
void GetMapOrderEffectPosition(MapOrder *,s16 *);void *CreateSpriteObject();extern M2C_UNK gMapPreviewSpriteClass;
s16 pos[2];s32 p;
GetMapOrderEffectPosition(feature,pos);p=CreateSpriteObject(&gMapPreviewSpriteClass,parent);
M2C_FIELD(p,s32 *,BATTLE_PREVIEW_X)=pos[0];M2C_FIELD(p,s32 *,BATTLE_PREVIEW_Y)=pos[1];
M2C_FIELD(p,s16 *,BATTLE_PREVIEW_MODE)=(u32)(M2C_FIELD(feature,u16 *,MAP_ORDER_TYPE)<<22)>>28;
M2C_FIELD(p,s16 *,BATTLE_PREVIEW_VALUE)=M2C_FIELD(feature,u8 *,MAP_ORDER_VALUE);
M2C_FIELD(p,void **,BATTLE_PREVIEW_UNIT)=feature;return p;
}

/* Spawn the tile-preview sprite for map cell (x, y) under `parent`: record the
 * cell, give it sprite mode 1 and its tile index from the cell's terrain-HP byte,
 * and store 0 in its link field. */
s32 CreateTilePreviewSprite(s32 x,s32 y,s32 parent) {
extern M2C_UNK gMapPreviewSpriteClass;extern void **gCurrentMap;void *CreateSpriteObject();
s32 p=CreateSpriteObject(&gMapPreviewSpriteClass,parent);
void *base;
M2C_FIELD(p,s32 *,0x38)=x;M2C_FIELD(p,s32 *,0x3c)=y;
M2C_FIELD(p,s16 *,0x6c)=1;base=*gCurrentMap;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN_HP)&127;
M2C_FIELD(p,s32 *,0x34)=0;return p;
}

/* Applies the pending damage held by the battle map's target list to every
 * target from index `firstTarget` on: damages the unit on each target tile,
 * pops a "damage" sprite over it, marks the tile, then shakes the screen and
 * plays the explosion sound at the average target position. */
s32 ApplyPendingDamageToTargets(s32 firstTarget, s32 graphicOffset, s32 tileIndex) {
s32 GetTargetCount(void); void *GetTargetPosition(s32);
s32 CreateAnimatedMapSprite(M2C_UNK *,s32,s32,s32,s32,s32,void *);
s32 Divide(s32,s32);
extern void **gCurrentMap; extern M2C_UNK gDamageSpriteName;
s32 n=0, sx=0, sy=0; s32 x,y;
for (;firstTarget<GetTargetCount();firstTarget++) {
u16 id=M2C_FIELD(GetTargetPosition(firstTarget),u16 *,0);
u8 *unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+id*MAP_UNIT_STRIDE;
MapTargetEntry *target=GetTargetPosition(firstTarget);
x=unit[MAP_UNIT_X]; y=unit[MAP_UNIT_Y];
DamageUnitAtTile(x,y,target->value);
M2C_FIELD((void *)CreateAnimatedMapSprite(&gDamageSpriteName,x,y,16,graphicOffset,tileIndex,(void *)7),s32 *,0x3c)=0x8c1;
PinMapCellCorners(x,y);
sx+=x; sy+=y; n++;
}
CreateScreenOffsetEffect(1,20,0); CreateScreenFlash(4,0,2,0);
if(n>0) PlaySoundAtTile(0x6d,Divide(sx,n),Divide(sy,n));
else PlaySoundAtCurrentVolume(0x6d);
}

/* Centres the map view on the average tile of the battle targets from index
 * start on (the list GetTargetCount / GetTargetPosition describe). */
s32 PanMapViewToTargetCenter(s16 start) {
    s32 GetTargetCount(void);
    void *GetTargetPosition(s32);
    s32 RuntimeIntDivMod(s32, s32);
    extern void **gCurrentMap;
    BattleMapUnit *unit;
    s32 sumX = 0, sumY = 0, count = 0, i = start;
    u16 id;

    for (; i < GetTargetCount(); i++) {
        id = M2C_FIELD(GetTargetPosition(i), u16 *, 0);
        unit = (BattleMapUnit *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS) + id;
        sumX += unit->x;
        sumY += unit->y;
        count++;
    }
    if (count > 0) PanMapViewToTile(RuntimeIntDivMod(sumX, count), RuntimeIntDivMod(sumY, count));
}

/* Play the strike sound under an Aurora aim marker on its first update, once the
 * marker's start delay has run out and its elapsed-frame count is still 0. */
void UpdateAuroraAimMarker(void *marker) {
    s32 GetObjectTileX(void *); s32 GetObjectTileY(void *);
    s32 tileX; s32 tileY; u32 bits = M2C_FIELD(marker, u32 *, SPRITE_OBJ_TIMER);
    u16 elapsed = (u16)(bits >> 21);
    if (elapsed) return;
    tileX = GetObjectTileX(marker);
    tileY = GetObjectTileY(marker);
    PlaySoundAtTile(0xfc, tileX, tileY);
}

/* Apply the Aurora strike's pending damage (called at the strike's frame 60):
 * damage every battle target from the strike's first target on, then clear the
 * damage sheet offset that marks the damage as applied.  While no damage sheet is
 * loaded it does nothing and returns the first target index. */
s32 ApplyPendingDamage(void *strike) {
    s32 ApplyPendingDamageToTargets(s32, s32, s32);
    s32 damageGraphic = M2C_FIELD(strike, s32 *, AURORA_STRIKE_DAMAGE_GRAPHIC);
    s32 firstTarget = M2C_FIELD(strike, s32 *, AURORA_STRIKE_FIRST_TARGET);

    if (!damageGraphic) return firstTarget;
    ApplyPendingDamageToTargets(firstTarget, damageGraphic, 8);
    M2C_FIELD(strike, s32 *, AURORA_STRIKE_DAMAGE_GRAPHIC) = 0;
    return 0;
}

/* Aim the Aurora strike at the remaining targets: each target's unit cell gets
 * an "arura_aim" marker made with the strike's aim graphic, its start delayed by
 * 8 frames per marker, and UpdateAuroraAimMarker as its update callback. */
void AuroraBombardTargets(void *strike) {
    s32 GetTargetCount(void);
    void *GetTargetPosition(s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    extern void **gCurrentMap;
    extern M2C_UNK gAuroraAimName;

    s32 aimGraphic, delay, i;
    void *unit, *marker;

    i = M2C_FIELD(strike, s32 *, 0x58);
    aimGraphic = M2C_FIELD(strike, s32 *, 0x5c);
    delay = 0;
    for (; i < GetTargetCount(); i++) {
        u16 id = M2C_FIELD(GetTargetPosition(i), u16 *, 0);
        unit = *gCurrentMap + MAP_UNIT_RECORDS + id * MAP_UNIT_STRIDE;
        marker = CreateEffectMapSprite(&gAuroraAimName, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y), 16, aimGraphic, 0, strike);
        M2C_FIELD(marker, u32 *, 0x48) = (M2C_FIELD(marker, u32 *, 0x48) & ~1023) | ((u8)delay & 1023);
        M2C_FIELD(marker, void (**)(void *), 0x6c) = UpdateAuroraAimMarker;
        delay += 8;
    }
}

#pragma opt_common_subs off
/* Per-frame update of the Aurora effect: plays its sound cues at fixed frames,
 * applies the staged damage at frame 60, shakes the tile randomly between
 * frames 32 and 90 and spawns a smoke puff. */
void UpdateAuroraEffect(void *effect) {
    M2C_UNK GetObjectTileX(void *);
    M2C_UNK GetObjectTileY(void *);
    M2C_UNK PlaySoundAtTile(s32, s32, s32);
    s32 ApplyPendingDamage(void *);
    u32 NextRandomValue(void);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    extern M2C_UNK gAuroraSmokeName;
    s32 tileX, tileY, power;
    u16 frame;

    power = M2C_FIELD(effect, s32 *, 0x60);
    frame = (u16)(M2C_FIELD(effect, u32 *, 0x48) >> 21);
    tileX = GetObjectTileX(effect);
    tileY = GetObjectTileY(effect) - 1;
    switch (frame) {
    case 0: PlaySoundAtTile(253, tileX, tileY); break;
    case 20: PlaySoundAtTile(254, tileX, tileY); break;
    case 32: PlaySoundAtTile(256, tileX, tileY); break;
    case 90: PlaySoundAtTile(255, tileX, tileY); break;
    case 104: PlaySoundAtTile(258, tileX, tileY); break;
    }
    if (frame == 60) ApplyPendingDamage(effect);
    if ((s32)frame < 32) return;
    if ((s32)frame > 90) return;
    if ((s32)frame % 8) return;
    if (NextRandomValue() & 1) tileX += (s32)NextRandomValue() % 2 + 2;
    else tileX -= (s32)NextRandomValue() % 2 + 2;
    if (NextRandomValue() & 1) tileY += (s32)NextRandomValue() % 2 + 2;
    else tileY -= (s32)NextRandomValue() % 2 + 2;
    PlaySoundAtTile(257, tileX, tileY);
    CreateAnimatedMapSprite(&gAuroraSmokeName, tileX, tileY, 16, power, 1, effect);
}
#pragma opt_common_subs reset
void ApplyAuroraPendingDamage(void) {
    M2C_UNK ApplyPendingDamage();
    ApplyPendingDamage();
}

/* Start handler of the Aurora strike effect task (gAuroraEffectClass +0x2C):
 * clear the effect sprite pool and rewind the strike's staged sequence so
 * StageAuroraEffect starts loading its sheets again. */
void StartAuroraEffect(void *effect) {
    M2C_UNK ResetEffectSpritePool();
    ResetEffectSpritePool();
    M2C_FIELD(effect, s16 *, AURORA_EFFECT_STAGE) = 0;
}

/* Advance the staged Aurora strike: the first three frames load the aim, smoke and
 * damage sprite handles onto the staging object, then the fourth spawns the strike
 * sprite, copies those handles and the power value onto it, wires up its bombard/
 * update/apply callbacks and deletes the staging object. */
void StageAuroraEffect(void *effect) {
    s32 LoadEffectSpriteSheet(M2C_UNK *, s32);
    s32 GetEffectSpritePoolOffset(void);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    void Sprite_ResumeAnimation(void *);
    extern M2C_UNK gAuroraAimSprite, gAuroraSmokeSprite, gAuroraDamageSprite, gAuroraSprite;
    void AuroraBombardTargets(void *);
    void UpdateAuroraEffect(void *);
    void ApplyAuroraPendingDamage(void);

    s32 stage = M2C_FIELD(effect, s16 *, 0x56);
    s32 x, y, power;
    void *strike;

    power = M2C_FIELD(effect, s16 *, 0x6c);
    x = M2C_FIELD(effect, s32 *, 0x38);
    y = M2C_FIELD(effect, s32 *, 0x3c);
    M2C_FIELD(effect, s16 *, 0x56) = stage + 1;
    switch (stage) {
    case 0:
        M2C_FIELD(effect, s32 *, 0x5c) = LoadEffectSpriteSheet(&gAuroraAimSprite, 0);
        break;
    case 1:
        M2C_FIELD(effect, s32 *, 0x60) = LoadEffectSpriteSheet(&gAuroraSmokeSprite, 1);
        break;
    case 2:
        M2C_FIELD(effect, s32 *, 0x64) = LoadEffectSpriteSheet(&gAuroraDamageSprite, 8);
        break;
    case 3:
        strike = CreateEffectMapSprite(&gAuroraSprite, x, y, 1, GetEffectSpritePoolOffset(), 2, effect);
        M2C_FIELD(strike, s32 *, 0x58) = power;
        M2C_FIELD(strike, s32 *, 0x5c) = M2C_FIELD(effect, s32 *, 0x5c);
        M2C_FIELD(strike, s32 *, 0x60) = M2C_FIELD(effect, s32 *, 0x60);
        M2C_FIELD(strike, s32 *, 0x64) = M2C_FIELD(effect, s32 *, 0x64);
        M2C_FIELD(strike, u32 *, 0x48) = (M2C_FIELD(strike, u32 *, 0x48) & ~1023) | 10;
        M2C_FIELD(strike, void **, 0x68) = AuroraBombardTargets;
        M2C_FIELD(strike, void **, 0x6c) = UpdateAuroraEffect;
        M2C_FIELD(strike, void **, 0x70) = ApplyAuroraPendingDamage;
        Sprite_ResumeAnimation(effect);
        break;
    }
}

/* Spawn the Aurora order's strike effect at the order's cell: record the cell and
 * the first queued target to bombard, then pan the map view onto the targets. */
void CreateAuroraStrikeEffect(s32 x, s32 y, s16 firstTarget, M2C_UNK parent) {
    M2C_UNK PanMapViewToTargetCenter(s16);
    extern M2C_UNK gAuroraEffectClass;
    void *effect;

    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    effect = CreateSpriteObject(&gAuroraEffectClass, parent);
    M2C_FIELD(effect, s32 *, AURORA_EFFECT_X) = (s32) (x + 1);
    M2C_FIELD(effect, s32 *, AURORA_EFFECT_Y) = (s32) (y + 1);
    M2C_FIELD(effect, s16 *, AURORA_EFFECT_FIRST_TARGET) = firstTarget;
    PanMapViewToTargetCenter(firstTarget);
}

/* Start handler of a map-view pan effect task: clear the effect sprite pool,
 * then pan the view onto the tile stored at +0x34/+0x38 of the task. */
void StartMapViewPanEffect(void *task) {
    M2C_UNK PanMapViewToTile(s32, s32);
    ResetEffectSpritePool();
    PanMapViewToTile(M2C_FIELD(task, s32 *, 0x34), M2C_FIELD(task, s32 *, 0x38));
}

/* Spawn the "gas_ball_up" gas effect over the task's tile: load its sprite sheet,
 * place the animated sprite at the task's stored position, and play the effect
 * sound there. */
void CreateGasBallUpSprite(void *task) {
    M2C_UNK PlaySoundAtTile(s32, s32, s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    extern M2C_UNK gGasBallUpName;
    extern M2C_UNK gGasBallUpSprite;
    CreateAnimatedMapSprite(&gGasBallUpSprite, M2C_FIELD(task, s32 *, 0x34), M2C_FIELD(task, s32 *, 0x38), 0x10, LoadEffectSpriteSheet(&gGasBallUpName, 0), 0, task);
    PlaySoundAtTile(0x105, M2C_FIELD(task, s32 *, 0x34), M2C_FIELD(task, s32 *, 0x38));
}

/* Spawns the "gas_ball_down" gas effect over the task's tile: places the animated
 * sprite, pans the map view onto the tile and holds the view there until the
 * effect finishes. */
void CreateGasBallDownSprite(void *task) {
    M2C_UNK CreateMapViewScrollHold(s32);
    extern M2C_UNK gGasBallDownName;
    extern M2C_UNK gGasBallDownSprite;
    s32 sprite;

    sprite = CreateAnimatedMapSprite(&gGasBallDownSprite, M2C_FIELD(task, s32 *, 0x3C), M2C_FIELD(task, s32 *, 0x40), 0x10, LoadEffectSpriteSheet(&gGasBallDownName, 1), 1, task);
    PanMapViewToTile(M2C_FIELD(task, s32 *, 0x3C), M2C_FIELD(task, s32 *, 0x40));
    CreateMapViewScrollHold(sprite);
}

/* Spawn the "gas_storm" gas effect over the task's tile: load its sprite sheet,
 * place the animated sprite at the task's stored position, and play the effect
 * sound there. */
void CreateGasStormSprite(void *task) {
    extern M2C_UNK gGasStormName;
    extern M2C_UNK gGasStormSprite;
    s32 sheet = LoadEffectSpriteSheet(&gGasStormName, 2);
    CreateAnimatedMapSprite(&gGasStormSprite, M2C_FIELD(task, s32 *, 0x3C), M2C_FIELD(task, s32 *, 0x40), 0x10, sheet, 2, task);
    PlaySoundAtTile(0x106, M2C_FIELD(task, s32 *, 0x3C), M2C_FIELD(task, s32 *, 0x40));
}

/* Apply the gas storm order's pending damage: load the "damage" effect sheet
 * into palette slot 8 and damage every queued target from the order's first
 * target index on. */
void ApplyGasStormDamage(void *task) {
    s32 LoadEffectSpriteSheet(M2C_UNK *, M2C_UNK);
    M2C_UNK ApplyPendingDamageToTargets(s32, s32, M2C_UNK);
    extern M2C_UNK gGasStormDamageName;
    ApplyPendingDamageToTargets(M2C_FIELD(task, s32 *, GAS_EFFECT_FIRST_TARGET), LoadEffectSpriteSheet(&gGasStormDamageName, 8), 8);
}

