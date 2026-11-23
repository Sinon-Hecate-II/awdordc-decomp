#ifndef OV004_EFFECT_H
#define OV004_EFFECT_H

#include "common.h"

/* Sprite state shared by the ura_plane and ura_side effect variants. */
typedef struct Ov004UraPlaneEffect {
    u8 sprite[0x34];
    s16 scaleStart;      /* +0x34 */
    s16 scaleEnd;        /* +0x36 */
    s16 scaleFrame;      /* +0x38 */
    s16 scaleFrames;     /* +0x3A */
    s16 bobAmplitude;    /* +0x3C */
    s16 bobFrame;        /* +0x3E */
    s16 bobPeriod;       /* +0x40 */
    s16 bombFrame;       /* +0x42 */
    s16 bombFrames;      /* +0x44 */
    s16 burstFrame;      /* +0x46 */
    s16 burstFrames;     /* +0x48 */
    s16 centerX;         /* +0x4A */
    s16 centerY;         /* +0x4C */
    s16 offsetX;         /* +0x4E */
    s16 offsetY;         /* +0x50 */
    s16 scrollFrame;     /* +0x52 */
} Ov004UraPlaneEffect;

#define OV004_URA_PLANE_SCALE_ONE 0x100 /* resting scale the effect starts and ends at (1x) */
#define OV004_URA_PLANE_ZOOM_IN_SCALE 0x800 /* scale the ura-plane zoom-in grows to (8x) */
#define OV004_URA_PLANE_ZOOM_IN_FRAMES 60 /* ura-plane zoom-in duration, in frames */
#define OV004_URA_PLANE_START_SOUND 0xF7

#endif
