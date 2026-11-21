#ifndef OV002_EFFECTS_H
#define OV002_EFFECTS_H
#include "common.h"

/* One effect's node configuration.  The effect table entry's +0x28 pointer
 * leads here. */
typedef struct EffectConfig {
    u8 pad00[0x78];
    s16 posX;          /* +0x78 node position in the effect's frame */
    s16 posY;          /* +0x7A */
    s16 posZ;          /* +0x7C */
    u16 scale;         /* +0x7E scaled by textureScale */
    s16 pos2X;         /* +0x80 position of the effect's second node */
    s16 pos2Y;         /* +0x82 */
    s16 pos2Z;         /* +0x84 */
    u16 scale2;        /* +0x86 scaled by textureScale */
    s16 transform2[8]; /* +0x88 transform of the effect's second node */
    s16 transform[8];  /* +0x98 affine/colour values copied to the node */
    u8 padA8[0x08];
    s16 variantOfs[7][2]; /* +0xB0 x/y offset of each variant */
    u16 textureScale;  /* +0xCC */
} EffectConfig;

/* What one effect plays while it is displayed.  Reached at 0x34 from an
 * EffectSet (its template); the sound ids at +0x08 and +0x14 are indexed by the
 * effect's variant. */
typedef struct EffectSounds {
    u8 pad00[4];
    s32 intensity;       /* +0x04 0 = nothing to play until the effect starts */
    s32 volumeSound[2];  /* +0x08 per variant: the sound the slot plays for that variant */
    s32 startSound;      /* +0x10 id played when the effect appears */
    s32 variantSound[2]; /* +0x14 per variant: the sound played while that variant is showing */
    s32 stopSound;       /* +0x1C id played when the effect goes away */
} EffectSounds; /* 0x20 bytes */

/* An effect table entry, reached at 24-byte stride from gEffectTable. */
typedef struct EffectSet {
    u8 pad00[0x28];
    EffectConfig *config; /* +0x28 */
    u8 pad2C[0x08];
    EffectSounds *sounds; /* +0x34 what the effect set plays while displayed */
    u8 pad38[0x05];
    u8 phase;             /* +0x3D current phase of the effect (func_020af9cc, func_020afb34) */
    u8 variantActive[1];  /* +0x3E one byte per variant: 1 while that variant is showing */
} EffectSet;

/* One timed variant of an effect. */
typedef struct EffectVariant {
    u8 pad00[0x12];
    u8 startFrame; /* +0x12 frame the variant starts on */
    u8 pad13[0x55];
} EffectVariant; /* 0x68 bytes */

/* gEffectHasVariants[effect]: the effect swaps between timed variants. */
/* gEffectVariants[effect]: the effect's variants, EffectVariant[]. */
/* gSoundLevelVolumes[level 0..7]: the sound id each level plays. */

/* One disc effect of a unit model (0x14 bytes): a flat filled circle drawn in
 * the model's 3D space that grows and fades in over its lifetime.  The model
 * keeps them in its third child list; DrawModelEffectDisc draws one per frame. */
typedef struct EffectDisc {
    s16 x;            /* +0x00 centre in the model's space, 0 when mirror is set */
    s16 y;            /* +0x02 */
    s16 z;            /* +0x04 */
    u16 elapsed;      /* +0x06 frames the disc has been drawn */
    u16 duration;     /* +0x08 frames until it finishes */
    u16 color;        /* +0x0A BGR555 fill colour */
    u16 radiusFrom;   /* +0x0C radius at frame 0 */
    u16 radiusTo;     /* +0x0E radius it grows to */
    u8  alphaTo;      /* +0x10 polygon alpha it fades in to, 0..31 */
    u8  polygonAttr;  /* +0x11 high byte of REG_GX_POLYGON_ATTR while drawing */
    u8  mirror;       /* +0x12 nonzero: draw the disc at -x */
    u8  unk13;        /* +0x13 */
} EffectDisc; /* 0x14 bytes */

/* One unit model of the ov002 battle scene (0x90 bytes): a 3D effect-driven model
 * that a unit view holds in its five slots (UNIT_VIEW_SLOTS).  Its animation
 * scripts come from the effect set of a country, chosen by UNIT_MODEL_COUNTRY.
 * Its initializer sets the country and slot variant and resets its transform. */
#define UNIT_MODEL_X        0x6C /* s16 model position */
#define UNIT_MODEL_Y        0x6E
#define UNIT_MODEL_Z        0x70
#define UNIT_MODEL_SCALE    0x72 /* u16 scale in 8.8, 0x100 = 1.0 */
#define UNIT_MODEL_ROT_X    0x74 /* s32 rotation offset in 8.8, added to the position */
#define UNIT_MODEL_ROT_Y    0x78
#define UNIT_MODEL_ROCK_X   0x7C /* s16 rocking rotation offset */
#define UNIT_MODEL_ROCK_Y   0x7E
#define UNIT_MODEL_FRAME    0x80 /* s32 animation frame, staggered by slot variant */
#define UNIT_MODEL_EFFECT_VARIANT 0x84 /* s32 current effect-variant index, stepped as the effect plays */
#define UNIT_MODEL_UNUSED_84 UNIT_MODEL_EFFECT_VARIANT /* s32 (name used by the initializer) */
#define UNIT_MODEL_STEP_X   0x88 /* s16 per-frame position delta */
#define UNIT_MODEL_STEP_Y   0x8A
#define UNIT_MODEL_COUNTRY  0x8C /* u8 country/side whose effect set the model plays */
#define UNIT_MODEL_VARIANT  0x8D /* u8 slot variant within that effect set */

#endif
