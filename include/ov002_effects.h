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

/* An effect table entry, reached at 24-byte stride from gEffectTable. */
typedef struct EffectSet {
    u8 pad00[0x28];
    EffectConfig *config; /* +0x28 */
} EffectSet;

/* What one effect plays while it is displayed.  Reached at 0x34 from an
 * EffectSet (its template); the sound id halves at +0x04 are indexed by the
 * effect's variant. */
typedef struct EffectSounds {
    u8 pad00[4];
    s32 intensity;    /* +0x04 0 = nothing to play until the effect starts */
    s32 volumeId;     /* +0x08 id SetSoundEffectVolume takes when the variant's byte is 1 */
    u8 pad0C[4];
    s32 startSound;   /* +0x10 id played when the effect appears */
    s32 variantSound; /* +0x14 id played when its variant byte is 1 */
    u8 pad18[4];
    s32 stopSound;    /* +0x1C id played when the effect goes away */
} EffectSounds;

/* One timed variant of an effect. */
typedef struct EffectVariant {
    u8 pad00[0x12];
    u8 startFrame; /* +0x12 frame the variant starts on */
    u8 pad13[0x55];
} EffectVariant; /* 0x68 bytes */

/* gEffectHasVariants[effect]: the effect swaps between timed variants. */
/* gEffectVariants[effect]: the effect's variants, EffectVariant[]. */
/* gSoundLevelVolumes[level 0..7]: the sound id each level plays. */

#endif
