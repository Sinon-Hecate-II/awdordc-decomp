/* The DS "3D sprite" (the hardware's 3D OBJ layer) engine.
 *
 * gCur3DSpriteEngine points at the engine of the screen that is being drawn.  There are two
 * engines: g3DSpriteEngineMain (main engine, bottom screen, 3D sprite OAM at 0x07000000) and
 * g3DSpriteEngineSub (sub engine, top screen, 3D sprite OAM at 0x07000400).  Code saves
 * gCur3DSpriteEngine, points it at the engine it wants to touch and puts the old value back.
 *
 * The engine's first word points at its sprite bank.  The bank holds the OBJ attribute word
 * of the 3D sprite and the row at which the sprite's cell grid is cut into an upper and a
 * lower half, so that the two halves can be moved apart.
 *
 * Fields are read and written with M2C_FIELD(); the offsets below are the ones the code uses.
 */
#ifndef DS3DSPRITE_H
#define DS3DSPRITE_H

typedef struct DS3DSpriteBank {
    u16 flags;         /* +0x00 */
    u8  filler_02[0x10];
    u16 oamAttr;       /* +0x12 OBJ attribute word of the 3D sprite */
    u8  filler_14[0x24];
    s16 corner[8];     /* +0x38 four (x,y) corner offsets of the sprite quad */
    u8  filler_48[8];
    u8  filler_50;
    u8  rowsAbove;     /* +0x51 rows of the cell grid above the split */
    u8  rowsBelow;     /* +0x52 rows of the cell grid below the split */
    u8  filler_53;
} DS3DSpriteBank;

typedef struct DS3DSpriteEngine {
    void *bank;        /* +0x00 the sprite bank of this engine */
    void *sprites;     /* +0x04 the 3D sprite list of this engine */
    u8   filler_08[0x14];
    u32  textureAddr;  /* +0x1C */
    u8   filler_20[0x10];
    void *oamBuffer;   /* +0x30 0x400 bytes of 3D sprite OAM entries */
    u16 *oamEntries;   /* +0x34 */
    u16 *spriteSrc;    /* +0x38 */
    s16  offsetX;      /* +0x3C */
    s16  offsetY;      /* +0x3E */
    s16  filler_40;
    s16  filler_42;
    s16  filler_44;
    s16  filler_46;
    u8   count;        /* +0x48 number of 3D sprites in use */
    u8   filler_49;
    u8   index;        /* +0x4A */
    u8   filler_4B;
    u8   filler_4C;
    u8   filler_4D;
    u8   filler_4E;
    u8   filler_4F;
    void *filler_50;
    void *filler_54;
} DS3DSpriteEngine;

/* Control word of a 3D sprite object (at object+0x44). */
typedef struct SpriteFlags {
    u32 attr:16;          /* 16-bit attribute handed to the sprite draw call */
    u32 screen:3;         /* engine to draw on: 0 main, 1 sub, 3 the active one */
    u32 a:1;
    u32 closeOnInput:1;   /* destroy the object once an input arrives */
    u32 yAttr:1;          /* extra bit OR-ed into the 2D sprite's y */
    u32 drawMode:2;       /* 0 none, 1 3D transform, 2 screen-space sprite */
    u32 easing:2;         /* 0 none, else the EaseInterpolate curve of the fade */
    u32 high:6;
} SpriteFlags;

/* Timing word of a 3D sprite object (at object+0x48). */
typedef struct SpriteTimer {
    u32 delay:10;    /* frames left before the object is updated */
    u32 duration:11; /* total frames of the eased fade */
    u32 elapsed:11;  /* frames since the fade started */
} SpriteTimer;

/* Easing curves of EaseInterpolate(mode, from, to, t, duration). */
enum {
    EASE_LINEAR = 0,      /* constant speed */
    EASE_IN_QUAD = 1,     /* starts slowly */
    EASE_IN_CUBIC = 2,
    EASE_IN_QUART = 3,
    EASE_OUT_QUAD = 4,    /* ends slowly */
    EASE_OUT_CUBIC = 5
};

#endif
