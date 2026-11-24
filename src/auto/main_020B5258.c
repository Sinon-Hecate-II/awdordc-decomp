/* 29 functions from 0x020B5258 to 0x020B6168 (main), found by ds-decomp. */
#include "common.h"
#include "map_effect.h"
#include "battle_map.h"
typedef struct { u8 kind:6; u8 rest:2; } UnitKindBits;
extern u8 data_ov000_021b5c0d[];
extern s32 *gCurrentMap;

u8 IsBattleEffectActive(void) {
    s32 func_0208c724();
    s32 func_020c306c();
    u8 var_r0;

    if (func_020c306c() != 0) {
        return 1U;
    }
    if (func_0208c724() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
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

void ExplosionSprite_Update(void *arg0) {
    s32 func_0208c1dc(void *);
    if ((u16)(M2C_FIELD(arg0, u32 *, 0x44) >> 26) == 0) ExplosionSprite_Trigger(arg0);
    if (func_0208c1dc(arg0) == 0) return;
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

M2C_UNK CreateExplosionEffect(s32 a,s32 b,s32 c,s32 d) {
void *CreateSpriteForOwner(M2C_UNK *,s32); extern M2C_UNK data_02128c6c;
void *p=CreateSpriteForOwner(&data_02128c6c,d);
M2C_FIELD(p,s32 *,0x38)=a; M2C_FIELD(p,s32 *,0x3c)=b; M2C_FIELD(p,s32 *,0x5c)=c;
}

/* Finishing step of a unit removal effect: play the explosion on the unit's tile,
 * then destroy the unit (or only remove it), refresh the map, mark the effect done
 * and schedule the battle-end check and the map event. */
void func_020b55c4(UnitRemoveEffect *effect) {
    s32 GetObjectTileX(void *);
    s32 GetObjectTileY(void *);
    void RemoveUnit(u8);
    void DestroyUnit(u8);
    void ExplosionEffect_Play(u8, s32, s32);
    void ScheduleBattleEndCheck(void);
    void func_ov000_0216ab2c(void);
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
    func_ov000_0216ab2c();
}

void func_020b5640(void *arg0) {
    s32 func_0208c1dc(void *);
    if ((u16)(M2C_FIELD(arg0, u32 *, 0x44) >> 26) == 0) func_020b55c4(arg0);
    if (func_0208c1dc(arg0) == 0) return;
    func_020b55c4(arg0);
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
M2C_FIELD(p,void (**)(void *),0x6c)=func_020b5640;
M2C_FIELD(p,void (**)(void *),0x70)=(void (*)(void *))func_020b55c4;
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
void func_020b5964(s32 a,s32 b) {
void GetMapOrderEffectPosition(s32,s16 *); void *CreateSpriteObject(M2C_UNK *,s32); extern M2C_UNK data_02128c34;
s16 xy[2]; void *p;
GetMapOrderEffectPosition(a,xy); p=CreateSpriteObject(&data_02128c34,b);
M2C_FIELD(p,s32 *,0x38)=xy[0]; M2C_FIELD(p,s32 *,0x3c)=xy[1];
}

void func_020b59a0(void *arg0) {
    CreateExplosionEffect(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 9, 7);
}

#pragma scheduling off
void func_020b59c0(void *arg0) {
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
void func_020b5d94(u8 *arg0,s32 arg1) {
void *CreateSpriteObject(M2C_UNK *,s32); extern M2C_UNK data_02128bc4;
void *p=CreateSpriteObject(&data_02128bc4,arg1);
M2C_FIELD(p,s32 *,0x38)=arg0[0]; M2C_FIELD(p,s32 *,0x3c)=arg0[1]; M2C_FIELD(p,void **,0x34)=arg0;
}

void func_020b5dc0(void *arg0) {
    CreateExplosionEffect(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 8, 7);
}

void func_020b5de0(void *arg0) {
    M2C_UNK ApplyTerrainBlast(s32, s32);
    M2C_UNK RebuildMapPropertyCells();
    M2C_UNK RefreshMapView();
    ApplyTerrainBlast(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
    RefreshMapView();
    RebuildMapPropertyCells();
}

void func_020b5e00(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128bfc;
    void *temp_r0;

    temp_r0 = CreateSpriteObject(&data_02128bfc, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
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

void func_020b5f3c(s16 arg0, s16 arg1, M2C_UNK arg2) {
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK data_02128b04;
    extern M2C_UNK data_02128e8c;
    void *temp_r0;

    temp_r0 = CreateSpriteObject(&data_02128b04, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = arg1;
    StringCopy(temp_r0 + 0x34, &data_02128e8c);
}

/* Switch the map cell at (x, y) to its other tile: a cell showing tile 0x180
 * becomes tile 0x1A0 with terrain 0x19, and the map is redrawn either way. */
void func_020b5f74(s32 x, s32 y) {
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

