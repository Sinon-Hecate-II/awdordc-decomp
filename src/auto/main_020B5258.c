/* 29 functions from 0x020B5258 to 0x020B6168 (main), found by ds-decomp. */
#include "common.h"
#include "map_effect.h"
#include "battle_map.h"
typedef struct { u8 kind:6; u8 rest:2; } UnitKindBits;
extern u8 data_ov000_021b5c0d[];
extern s32 *gCurrentMap;

/* True while the battle effect object or any animated sprite object exists. */
u8 IsBattleEffectActive(void) {
    s32 IsAnimatedSpriteObjectActive();
    s32 IsBattleEffectObjectActive();
    u8 active;

    if (IsBattleEffectObjectActive() != 0) {
        return 1U;
    }
    if (IsAnimatedSpriteObjectActive() != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Name of the sprite resource an explosion effect of the given type plays:
 * normal for types 0..2, air, ship, quick, hit for 6..7, meteor and boss. */
M2C_UNK *GetExplosionSpriteName(u32 effectType) {
    extern M2C_UNK sExplosionNormalName, sExplosionAirName, sExplosionShipName, sExplosionQuickName, sExplosionHitName, sExplosionMeteorName, sExplosionBossName;
    switch (effectType) {
    case 0: case 1: case 2: return &sExplosionNormalName;
    case 3: return &sExplosionAirName;
    case 4: return &sExplosionShipName;
    case 5: return &sExplosionQuickName;
    case 6: case 7: return &sExplosionHitName;
    case 8: return &sExplosionMeteorName;
    case 9: return &sExplosionBossName;
    default: return NULL;
    }
}

/* Draws one of several unit/map status overlays at position (x, y) depending on mode. */
void ExplosionEffect_Play(u8 mode, s32 x, s32 y) {
    M2C_UNK PlaySoundAtTile(s32, s16, s16);
    void CreateScreenOffsetEffect(s32, s32, s32);
    void CreateScreenFlash(s32, s32, s32, s32);
    M2C_UNK SpawnSoundEffectAtTile(s32, s32, s32, s32);
    typedef M2C_UNK (*Fb0c)(s32, s32, s32);
    switch (mode) {
    case 0:
    case 1:
    case 2:
        ((Fb0c)PlaySoundAtTile)(0x8a, x, y);
        CreateScreenOffsetEffect(1, 0x14, 0);
        return;
    case 3:
        ((Fb0c)PlaySoundAtTile)(0x6d, x, y);
        CreateScreenOffsetEffect(1, 0x14, 0);
        return;
    case 4:
        ((Fb0c)PlaySoundAtTile)(0x73, x, y);
        CreateScreenOffsetEffect(1, 0x14, 0);
        return;
    case 5:
        ((Fb0c)PlaySoundAtTile)(0x8a, x, y);
        CreateScreenOffsetEffect(0, 0xa, 0);
        return;
    case 6:
        ((Fb0c)PlaySoundAtTile)(0x8a, x, y);
        CreateScreenOffsetEffect(0, 5, 0);
        return;
    case 7:
        ((Fb0c)PlaySoundAtTile)(0x11f, x, y);
        CreateScreenOffsetEffect(0, 5, 0);
        return;
    case 8:
        SpawnSoundEffectAtTile(0x10e, x, y, 0);
        SpawnSoundEffectAtTile(0x10f, x, y, 0x1e);
        CreateScreenOffsetEffect(1, 0x14, 0);
        CreateScreenFlash(4, 0, 2, 0);
        return;
    case 9:
        ((Fb0c)PlaySoundAtTile)(0xfa, x, y);
        CreateScreenOffsetEffect(1, 0x1e, 0);
        CreateScreenFlash(8, 0, 4, 0);
        return;
    }
}

/* Trigger handler of a spawned explosion sprite: play the explosion's sound and
 * screen effect on the tile the sprite is on, only the first time it is called. */
void ExplosionSprite_Trigger(void *effect) {
    s32 GetObjectTileX(void *);
    s32 GetObjectTileY(void *);
    void ExplosionEffect_Play(u8, s32, s32);
    s32 x;
    u8 type;

    type = (u8) ((ExplosionEffect *) effect)->type;
    if (((ExplosionEffect *) effect)->triggered & 0xFF) return;
    x = GetObjectTileX(effect);
    ExplosionEffect_Play(type, x, GetObjectTileY(effect));
    ((ExplosionEffect *) effect)->triggered = 1;
}

/* Per-frame update of an explosion sprite: play the explosion when the sprite has
 * no animation frames yet, and again when its animation reports a script command
 * (the explosion has finished). ExplosionSprite_Trigger runs only once. */
void ExplosionSprite_Update(void *arg0) {
    s32 TakeSpriteAnimCommand(void *);
    if ((u16) (((ExplosionEffect *) arg0)->flags >> 26) == 0) ExplosionSprite_Trigger(arg0);
    if (TakeSpriteAnimCommand(arg0) == 0) return;
    ExplosionSprite_Trigger(arg0);
}

void func_020b5504(void *arg0) {
    M2C_UNK StepMapViewToTile(s32, s32);
    StepMapViewToTile(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
}

/* Start handler of the explosion effect: spawn the animated sprite for the
 * effect's type on its tile, then hook up its per-frame update and its trigger. */
void ExplosionEffect_Start(ExplosionEffect *effect) {
    void *CreateEffectMapSprite(void *, s32, s32, s32, s32, s32, void *);
    s32 type;
    void *name;
    ExplosionEffect *sprite;

    type = effect->type;
    name = GetExplosionSpriteName(type);
    if (name == 0) return;
    sprite = CreateEffectMapSprite(name, effect->tileX, effect->tileY, 0, 0, 0, effect);
    sprite->triggered = 0;
    sprite->type = type;
    sprite->update = ExplosionSprite_Update;
    sprite->trigger = ExplosionSprite_Trigger;
    sprite->flags = (sprite->flags & ~0x03000000) | 0x02000000;
}

/* Spawn an explosion effect task of `type` on map tile (tileX, tileY), owned by
 * `owner`; its class start handler then spawns the animated explosion sprite. */
M2C_UNK CreateExplosionEffect(s32 tileX, s32 tileY, s32 type, s32 owner) {
    void *CreateSpriteForOwner(M2C_UNK *, s32);
    extern M2C_UNK gExplosionTaskClass;
    ExplosionEffect *effect = CreateSpriteForOwner(&gExplosionTaskClass, owner);

    effect->tileX = tileX;
    effect->tileY = tileY;
    effect->type = type;
}

/* Finishing step of a unit removal effect: play the explosion on the unit's tile,
 * then destroy the unit (or only remove it), refresh the map, mark the effect done
 * and schedule the battle-end check and the map event. */
void UnitRemoveEffect_Trigger(UnitRemoveEffect *effect) {
    s32 GetObjectTileX(void *);
    s32 GetObjectTileY(void *);
    void RemoveUnit(u8);
    void DestroyUnit(u8);
    void ExplosionEffect_Play(u8, s32, s32);
    void ScheduleBattleEndCheck(void);
    void RunUnitGoneEvent(void);
    s32 x;
    u8 type, destroy, unitIndex;

    type = effect->type;
    destroy = effect->destroy;
    unitIndex = effect->unitIndex;
    if (effect->done & 0xFF) return;
    x = GetObjectTileX(effect);
    ExplosionEffect_Play(type, x, GetObjectTileY(effect));
    if (destroy) DestroyUnit(unitIndex); else RemoveUnit(unitIndex);
    RefreshMapView();
    effect->done = 1;
    ScheduleBattleEndCheck();
    RunUnitGoneEvent();
}

/* Per-frame update of a unit-removal effect sprite: run its trigger on the first
 * frame (while the sprite control word's high bits are clear), step the sprite's
 * animation, and run the trigger again once that step reports the animation done. */
void UnitRemoveEffect_Update(void *effect) {
    s32 func_0208c1dc(void *);
    if ((u16)(((UnitRemoveEffect *)effect)->flags >> 26) == 0) UnitRemoveEffect_Trigger(effect);
    if (func_0208c1dc(effect) == 0) return;
    UnitRemoveEffect_Trigger(effect);
}

M2C_UNK func_020b567c(M2C_UNK a, s32 arg1) {
u8 *unit=(u8 *)a;
void *CreateAnimatedMapSprite(void *,s16,s16,s32,s32,s32,void *);
s32 kind, index; void *p;
/* Spawns a managed unit object from a unit-table entry. */
if (!unit) return;
kind=data_ov000_021b5c0d[((UnitKindBits *)unit)->kind*0x70];
index=unit ? ((s32)unit-(*gCurrentMap+0x59A4))/14 : 0;
p=GetExplosionSpriteName(kind);
if(!p) return;
p=CreateAnimatedMapSprite(p,unit[1],unit[2],0,0,0,(void *)7);
M2C_FIELD(p,s32 *,0x58)=0;
M2C_FIELD(p,s32 *,0x5c)=kind;
M2C_FIELD(p,s32 *,0x60)=arg1;
M2C_FIELD(p,s32 *,0x64)=index;
M2C_FIELD(p,void (**)(void *),0x6c)=UnitRemoveEffect_Update;
M2C_FIELD(p,void (**)(void *),0x70)=(void (*)(void *))UnitRemoveEffect_Trigger;
M2C_FIELD(p,u32 *,0x44)=(M2C_FIELD(p,u32 *,0x44)&~0x3000000)|0x2000000;
}

void ExplodeUnit(M2C_UNK arg0) {
    M2C_UNK func_020b567c(M2C_UNK, M2C_UNK);
    func_020b567c(arg0, 1);
}

void RemoveUnitWithEffect(M2C_UNK arg0) {
    M2C_UNK func_020b567c(M2C_UNK, M2C_UNK);
    func_020b567c(arg0, 0);
}

void func_020b578c(void *arg0) {
    M2C_UNK CreateExplosionEffect(s32, s32, M2C_UNK, M2C_UNK);
    CreateExplosionEffect(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 9, 7);
}

#pragma scheduling off
/* Adds the tile-graphic offset 0x60 to the 3x3 block of map cells that ends at the
   effect object's tile (x, y) - columns x-1..x+1, rows y-2..y - then refreshes the map. */
void func_020b57ac(void *obj) {
    s32 x = M2C_FIELD(obj, s32 *, 0x38);
    s32 y = M2C_FIELD(obj, s32 *, 0x3C);
    void *map;
    u16 rowOffset;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + y * 2);
    *(u16 *)((char *)map + 0xA10 + ((x - 1) + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + y * 2);
    *(u16 *)((char *)map + 0xA10 + (x + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + y * 2);
    *(u16 *)((char *)map + 0xA10 + ((x + 1) + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 1) * 2);
    *(u16 *)((char *)map + 0xA10 + ((x - 1) + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 1) * 2);
    *(u16 *)((char *)map + 0xA10 + (x + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 1) * 2);
    *(u16 *)((char *)map + 0xA10 + ((x + 1) + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 2) * 2);
    *(u16 *)((char *)map + 0xA10 + ((x - 1) + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 2) * 2);
    *(u16 *)((char *)map + 0xA10 + (x + rowOffset) * 2) += 0x60;
    map = (void *)*gCurrentMap;
    rowOffset = *(u16 *)((char *)map + 0x3758 + (y - 2) * 2);
    *(u16 *)((char *)map + 0xA10 + ((x + 1) + rowOffset) * 2) += 0x60;
    RefreshMapView();
}
#pragma scheduling reset
/* Spawn the map-order effect sprite for `order` under `parent`, positioned at the
 * order's effect tile (GetMapOrderEffectPosition). */
void CreateMapOrderEffectSprite(MapOrder *order, s32 parent) {
    void GetMapOrderEffectPosition(MapOrder *, s16 *);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gMapOrderEffectSpriteClass;
    s16 pos[2];
    void *effect;

    GetMapOrderEffectPosition(order, pos);
    effect = CreateSpriteObject(&gMapOrderEffectSpriteClass, parent);
    M2C_FIELD(effect, s32 *, 0x38) = pos[0];
    M2C_FIELD(effect, s32 *, 0x3c) = pos[1];
}

void LineAttackEffect_Trigger(void *arg0) {
    CreateExplosionEffect(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 9, 7);
}

#pragma scheduling off
void LineAttackEffect_Update(void *arg0) {
    s32 x = M2C_FIELD(arg0, s32 *, 0x38);
    s32 y = M2C_FIELD(arg0, s32 *, 0x3C);
    void *u = (void *) M2C_FIELD(arg0, s32 *, 0x34);
    u32 hi = (u32) *(u16 *) ((char *) u + 2);
    u32 mode = (hi << 22) >> 28;

    switch (mode) {
    case 6:
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 3) * 2);
            *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0xC9;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 4) * 2);
            *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0xE0;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 5) * 2);
            *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0xF7;
        }
        break;
    case 7:
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + y * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x - 1) + row) * 2) += 0x40;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + y * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x + 1) + row) * 2) += 0x40;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x - 1) + row) * 2) += 0x40;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x + 1) + row) * 2) += 0x40;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x - 2) + row) * 2) += 0x40;
        }
        {
            void *base = (void *) *gCurrentMap;
            u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
            *(u16 *) ((char *) base + 0xA10 + ((x + 2) + row) * 2) += 0x40;
        }
        if (x < 12) {
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x1C;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 2) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x1C;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 3) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x1C;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 4) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x1C;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 5) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x1C;
            }
        } else {
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 1) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x24;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 2) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x24;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 3) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x24;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char *) base + 0x3758 + (y - 4) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x24;
            }
            {
                void *base = (void *) *gCurrentMap;
                u16 row = *(u16 *) ((char*) base + 0x3758 + (y - 5) * 2);
                *(u16 *) ((char *) base + 0xA10 + (x + row) * 2) += 0x24;
            }
        }
        break;
    default:
        break;
    }
    RemoveMapOrder();
    func_020cfd28();
}
#pragma scheduling reset
/* Spawn the line-attack highlight effect for `order` under `parent`: an effect
 * sprite on the order's own tile that keeps the order it highlights (its update
 * dims the tiles along the attack line). */
void CreateLineAttackEffectSprite(MapOrder *order, s32 parent) {
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gLineAttackEffectClass;
    void *effect = CreateSpriteObject(&gLineAttackEffectClass, parent);
    M2C_FIELD(effect, s32 *, BATTLE_PREVIEW_X) = order->x;
    M2C_FIELD(effect, s32 *, BATTLE_PREVIEW_Y) = order->y;
    M2C_FIELD(effect, void **, BATTLE_PREVIEW_UNIT) = order;
}

void TerrainBlastEffect_Explode(void *arg0) {
    CreateExplosionEffect(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 8, 7);
}

void TerrainBlastEffect_DestroyTerrain(void *arg0) {
    M2C_UNK ApplyTerrainBlast(s32, s32);
    M2C_UNK RebuildMapPropertyCells();
    M2C_UNK RefreshMapView();
    ApplyTerrainBlast(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
    RefreshMapView();
    RebuildMapPropertyCells();
}

/* Spawns the terrain-blast effect sprite at map tile (tileX, tileY) under
 * `parent`: its script explodes on the tile and blasts the terrain away. */
void CreateTerrainBlastEffect(s32 tileX, s32 tileY, M2C_UNK parent) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTerrainBlastEffectClass;
    void *effect;

    effect = CreateSpriteObject(&gTerrainBlastEffectClass, parent);
    M2C_FIELD(effect, s32 *, 0x38) = tileX;
    M2C_FIELD(effect, s32 *, 0x3C) = tileY;
}

/* Runs the missile effect's start state: load its sprite sheet, show the launch
   flash, then launch the missile sprite, which climbs 0x1E00 pixels over 0x40
   frames (see the effect's per-frame handler). */
void SpawnMissileEffect(MissileEffect *effect) {
    M2C_UNK SetAnimatedSpriteFrame(void *, M2C_UNK);
    void *CreateAnimatedMapSprite(void *, s16, s16, M2C_UNK, s32, s32, void *);
    M2C_UNK ResetEffectSpritePool();
    M2C_UNK LoadEffectSpriteSheet(s32 name, s32 tileIndex);
    M2C_UNK PlaySoundAtTile(s32, s16, s16);
    MapSprite *missile;

    ResetEffectSpritePool();
    LoadEffectSpriteSheet((s32)effect->name, 0);
    SetAnimatedSpriteFrame(CreateAnimatedMapSprite(effect->name, effect->tileX, effect->tileY, 0x10, 0, 0, effect), 3);
    missile = CreateAnimatedMapSprite(effect->name, effect->tileX, effect->tileY, 0x10, 0, 0, effect);
    effect->missile = missile;
    SetAnimatedSpriteFrame(missile, 4);
    effect->frame = 0;
    effect->duration = 0x40;
    effect->from = effect->missile->y;
    effect->to = effect->missile->y - 0x1E00;
    PlaySoundAtTile(0x94, effect->tileX, effect->tileY);
}

/* Drives the missile effect's launch climb: advance the frame counter and ease
 * the missile sprite from the effect's start height towards its end height, then
 * resume the effect's task once the climb is done. */
void StepMissileLaunch(MissileEffect *effect) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 EaseInterpolate(M2C_UNK, s32, s32, s16, s32);

    effect->frame = (s16) (effect->frame + 1);
    effect->missile->y = EaseInterpolate(0, effect->from, effect->to, effect->frame, (s32) effect->duration);
    if ((s32) effect->frame < (s32) effect->duration) {
        return;
    }
    Sprite_ResumeAnimation(effect);
}

/* Create a missile effect task at tile (x, y) under `parent`, using the
 * "missile_n" sprite sheet. */
void CreateMissileEffect(s16 tileX, s16 tileY, M2C_UNK parent) {
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK gMissileEffectClass;
    extern M2C_UNK gMissileSheetName;
    void *effect;

    effect = CreateSpriteObject(&gMissileEffectClass, parent);
    M2C_FIELD(effect, s16 *, 0x44) = tileX;
    M2C_FIELD(effect, s16 *, 0x46) = tileY;
    StringCopy(effect + 0x34, &gMissileSheetName);
}

/* Switch the map cell at (x, y) to its other tile: a cell showing tile 0x180
 * becomes tile 0x1A0 with terrain 0x19, and the map is redrawn either way. */
void SetMissileSiloFired(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 cell;
    s32 map;
    s32 next;

    map = *gCurrentMap;
    cell = x + M2C_FIELD((map + (y * 2)), u16 *, MAP_ROW_OFFSETS);
    if (M2C_FIELD((map + (cell * 2)), u16 *, MAP_CELL_TILE_ID) == 0x180) {
        M2C_FIELD((map + cell), s8 *, MAP_CELL_TERRAIN) = 0x19;
        next = *gCurrentMap;
        M2C_FIELD((next + ((x + M2C_FIELD((next + (y * 2)), u16 *, MAP_ROW_OFFSETS)) * 2)), s16 *, MAP_CELL_TILE_ID) = 0x1A0;
    }
    RefreshMapView();
}

/* Spawns the missile strike effect: opens the effect archive, loads the
 * effect's sprite sheet, creates its missile sprite high above the target tile
 * plus the target cursor, and sets the missile's climb down onto the tile. */
void SpawnMissileStrike(MissileEffect *effect) {
    M2C_UNK SetAnimatedSpriteFrame(void *, M2C_UNK);
    void *CreateAnimatedMapSprite(void *, s16, s16, M2C_UNK, s32, s32, void *);
    M2C_UNK ResetEffectSpritePool();
    M2C_UNK LoadEffectSpriteSheet(s32, M2C_UNK);
    M2C_UNK func_020b5240(s32);
    M2C_UNK CreateTargetCursor(s16, s16);
    void *missile;

    func_020b5240((s32)effect->name);
    ResetEffectSpritePool();
    LoadEffectSpriteSheet((s32)effect->name, 0);
    missile = CreateAnimatedMapSprite(effect->name, effect->tileX, effect->tileY, 0x10, 0, 0, effect);
    effect->missile = missile;
    SetAnimatedSpriteFrame(missile, 0);
    effect->frame = 0;
    effect->duration = 0x20;
    effect->from = (s32) (effect->missile->y - 0x1E00);
    effect->to = (s32) effect->missile->y;
    CreateTargetCursor(effect->tileX, effect->tileY);
}

/* Drives the missile strike's descent: the sprite eases from its start height
 * down onto the target tile, and when it gets there it shows the impact frame of
 * the effect's sprite sheet, plays the effect's end sound and resumes its task. */
void StepMissileStrike(MissileEffect *effect) {
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK PlaySoundAtTile(s32, s16, s16);
    s32 endSound;

    effect->frame = (s16)(effect->frame + 1);
    effect->missile->y = EaseInterpolate(0, effect->from, effect->to, effect->frame, (s32)effect->duration);
    if ((s32)effect->frame < (s32)effect->duration) {
        return;
    }
    SetAnimatedSpriteFrame(CreateAnimatedMapSprite(effect->name, effect->tileX, effect->tileY, 0x10, 0, 0, effect), 1);
    endSound = effect->endSound;
    if (endSound != 0) {
        PlaySoundAtTile(endSound, effect->tileX, effect->tileY);
    }
    DeleteSpriteObject(effect->missile);
    Sprite_ResumeAnimation(effect);
}

/* Per-frame update of one tile of the range-damage effect: on the tile sprite's
 * first frame, pin the map cell's corners and damage the unit standing on the tile
 * by the amount the effect stored. */
void ApplyAreaDamageTile(void *sprite) {
    M2C_UNK PinMapCellCorners(s32, s32);
    M2C_UNK DamageUnitAtTile(s32, s32, s32);
    s32 tileX;
    s32 tileY;
    s32 amount;

    if ((u16)((u32)M2C_FIELD(sprite, u32 *, RANGE_EFFECT_TIMER) >> 0x15) != 0) {
        return;
    }
    tileY = M2C_FIELD(sprite, s32 *, RANGE_EFFECT_TILE_Y);
    tileX = M2C_FIELD(sprite, s32 *, RANGE_EFFECT_TILE_X);
    amount = M2C_FIELD(sprite, s32 *, RANGE_EFFECT_DAMAGE);
    PinMapCellCorners(tileX, tileY);
    DamageUnitAtTile(tileX, tileY, amount);
}

