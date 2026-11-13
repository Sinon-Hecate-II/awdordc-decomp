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

#endif
