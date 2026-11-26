/* Map-sprite effect tasks: the 3D sprite objects (see ds3dsprite.h) that the
 * battle map uses to play missile, tornado and other tile effects.  The
 * object's state table drives its handlers; the effect's own data lives from
 * +0x34 on. */
#ifndef MAP_EFFECT_H
#define MAP_EFFECT_H
#include "common.h"

/* A placed map sprite: the 3D sprite object the effect handlers create and
 * PlaceMapSprite (main_020B4264.c) positions on the map. */
typedef struct MapSprite {
    u8  pad00[0x34];
    s32 x;      /* +0x34 x position, in map-view pixels */
    s32 y;      /* +0x38 y position, in map-view pixels */
    s32 z;      /* +0x3C z/attribute word (0x8B1 for a map sprite) */
    s32 speed;  /* +0x40 animation step (0x20000, or GetFrameStep()) */
    u32 flags;  /* +0x44 sprite control flags */
} MapSprite;

/* An attack-target effect: the marker sprite an attack creates (class
 * data_0212b00c, see CreateAttackTargetEffect), aiming at a target tile from
 * the tile the attack comes from.  Its animation script holds the map view on
 * the target while the strike plays. */
typedef struct AttackTargetEffect {
    u8  pad00[0x34];
    s32 sourceX;    /* +0x34 map tile x the attack comes from */
    s32 sourceY;    /* +0x38 map tile y */
    u8  pad3C[0x16]; /* +0x3C */
    s16 power;      /* +0x52 power the marker shows */
    u8  pad54[0x18]; /* +0x54 */
    s16 targetX;    /* +0x6C map tile x the attack is aimed at */
    s16 targetY;    /* +0x6E map tile y */
} AttackTargetEffect;

/* The missile effect's task.  Fields from +0x34 are per effect; these are the
 * ones the missile effect uses: the sprite sheet it loads, the map tile it is
 * fired from and the eased climb of the missile sprite it drives. */
typedef struct MissileEffect {
    u8  pad00[0x34];
    char name[0x10];    /* +0x34 name of the sprite sheet the effect loads */
    s16 tileX;          /* +0x44 map tile x the effect is fired from */
    s16 tileY;          /* +0x46 map tile y */
    s16 frame;          /* +0x48 frames since the effect started */
    s16 duration;       /* +0x4A frames the missile takes to climb */
    u8  pad4C[4];       /* +0x4C */
    s32 endSound;       /* +0x50 sound played when the effect ends, 0 = none */
    s32 from;           /* +0x54 y the climb starts from */
    s32 to;             /* +0x58 y the climb ends at */
    u8  pad5C[4];       /* +0x5C */
    MapSprite *missile; /* +0x60 the flying missile sprite */
} MissileEffect;


/* Explosion effect type: which sprite sheet GetExplosionSpriteName picks.  Types
 * 0..2 are the normal ground explosion, 8 the meteor burst a terrain blast plays
 * and 9 the boss explosion. */
enum {
    EXPLOSION_TYPE_NORMAL = 0, /* 0..2: normal ground explosion */
    EXPLOSION_TYPE_AIR    = 3, /* air unit hit */
    EXPLOSION_TYPE_SHIP   = 4, /* naval unit hit */
    EXPLOSION_TYPE_QUICK  = 5, /* quick, bright explosion */
    EXPLOSION_TYPE_HIT    = 6, /* 6..7: hit explosion */
    EXPLOSION_TYPE_METEOR = 8, /* meteor / terrain blast */
    EXPLOSION_TYPE_BOSS   = 9  /* boss explosion */
};

/* An explosion effect: the effect task the battle map creates on a tile and the
 * animated sprite it spawns for it.  The task keeps its tile at +0x38/+0x3C and
 * its type at +0x5C; the spawned sprite carries the same type, a triggered flag,
 * its per-frame callback and the trigger that plays the sound and map effect. */
typedef struct ExplosionEffect {
    u8  pad00[0x38];
    s32 tileX;      /* +0x38 map tile x */
    s32 tileY;      /* +0x3C map tile y */
    s32 unk40;      /* +0x40 */
    u32 flags;      /* +0x44 sprite control word (SpriteFlags; bits 24..25 are the easing curve) */
    u8  pad48[0x10];
    s32 triggered;  /* +0x58 nonzero once the effect has been triggered */
    s32 type;       /* +0x5C explosion type (GetExplosionSpriteName) */
    u8  pad60[0x0C];
    void (*update)(void *);  /* +0x6C per-frame callback */
    void (*trigger)(void *); /* +0x70 plays the explosion's sound and map effect once */
} ExplosionEffect;

/* A unit removal effect: an explosion plays on the unit's tile, then the unit is
 * destroyed or simply removed from the map.  It is an animated sprite object (see
 * ds3dsprite.h), so its control word and animation handle are the sprite's; its own
 * fields start at +0x58. */
typedef struct UnitRemoveEffect {
    u8  pad00[0x38];
    s32 tileX;      /* +0x38 map tile x */
    s32 tileY;      /* +0x3C map tile y */
    u8  pad40[0x04];
    u32 flags;      /* +0x44 SpriteFlags control word */
    u8  pad48[0x04];
    void *anim;     /* +0x4C sprite-animation handle */
    u8  pad50[0x08];
    u32 done;       /* +0x58 nonzero once the effect has finished */
    s32 type;       /* +0x5C explosion type (GetExplosionSpriteName) */
    s32 destroy;    /* +0x60 nonzero: destroy the unit, 0: only remove it */
    s32 unitIndex;  /* +0x64 index of the unit in the unit table */
} UnitRemoveEffect;

/* One tile sprite of the range-damage effect: main_020B6168 creates one per tile
 * of the effect's diamond, stores the tile it damages and the damage amount on it,
 * and registers the per-frame update that fires the damage once. */
#define RANGE_EFFECT_TIMER  0x48 /* u32 shared sprite timer; only frame 0 deals the damage */
#define RANGE_EFFECT_TILE_X 0x58 /* s32 map tile x */
#define RANGE_EFFECT_TILE_Y 0x5C /* s32 map tile y */
#define RANGE_EFFECT_DAMAGE 0x60 /* s32 damage dealt to the unit on the tile */

/* A fuel-crash effect: the sprite a unit that ran out of fuel plays while the
 * map view pans to its tile; once the pan is done the unit explodes.  Its only
 * own field is the starving unit record (a BattleMapUnit). */
typedef struct FuelCrashEffect {
    u8  pad00[0x34];
    void *unit;     /* +0x34 the unit that ran out of fuel */
} FuelCrashEffect;

#endif
