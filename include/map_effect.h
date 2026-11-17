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

#endif
