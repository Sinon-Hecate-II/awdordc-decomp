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

/* Byte of the bank copied to the display blend register (0..31). */
#define DS3D_BANK_BLEND 0x53

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
    u8  filler_53;     /* +0x53 display blend level (0..31) */
} DS3DSpriteBank;

typedef struct DS3DSpriteEngine {
    void *bank;        /* +0x00 the sprite bank of this engine */
    void *sprites;     /* +0x04 the 3D sprite list of this engine */
    u32  filler_08;    /* +0x08 */
    u32  layerVram[4]; /* +0x0C VRAM address each layer's texture is decompressed to */
    u32  textureAddr;  /* +0x1C */
    void *layerTiles[4]; /* +0x20 RAM buffer holding each layer's tile data */
    void *oamBuffer;   /* +0x30 0x400-byte OBJ palette shadow: 32 palettes of 0x20 bytes */
    u16 *oamEntries;   /* +0x34 */
    u16 *spriteSrc;    /* +0x38 */
    s16  offsetX;      /* +0x3C */
    s16  offsetY;      /* +0x3E */
    s16  filler_40;
    s16  filler_42;
    s16  filler_44;
    u8   layerDirty;   /* +0x46 bit i: layer i's data changed, bit 4: the palette changed */
    u8   filler_47;
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

/* One entry of gWallpaperFileSets: the files of a wallpaper in one language. */
typedef struct WallpaperFileSet {
    const char *name;  /* +0x00 base name of the set's files, e.g. "wallp_bmap_s" */
    u8   sizeCode;     /* +0x04 tile size class, see SetLayerSize */
    u8   filler_05[5];
    s16  screenGap;    /* +0x0A added to both offsets on the second screen */
    u32  filler_0C;
    s16  offsetA;      /* +0x10 copied to the wallpaper object */
    s16  offsetB;      /* +0x12 copied to the wallpaper object */
} WallpaperFileSet;

/* DS3DSpriteEngine::layerDirty bit of the OBJ palette shadow. */
#define DS3D_DIRTY_PALETTE 0x10

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

/* A 3D sprite screen-split transition object: the two halves of a screen's 3D
 * sprite are moved apart over a number of frames and the object then deletes
 * itself. Only the fields the split animation uses are known. */
typedef struct DS3DSpriteSplit {
    u8  pad00[0x5C];
    s32 screen;   /* +0x5C engine that shows the split: 0 main, 1 sub, 3 the active one */
    s32 length;   /* +0x60 frames the split takes */
    s32 elapsed;  /* +0x64 frames elapsed so far */
} DS3DSpriteSplit;

/* State of the screen-change split transition (gScreenTransition, 12 bytes). */
typedef struct ScreenTransition {
    s16 flags;  /* +0x00 TRANSITION_* */
    s16 type;   /* +0x02 variant of the effect */
    s16 side;   /* +0x04 which half slides, 0 or 1 */
    s16 frame;  /* +0x06 current frame */
    s16 length; /* +0x08 total frames */
    s16 value;  /* +0x0A eased interpolation value (0..0x100) */
} ScreenTransition;

/* ScreenTransition::flags */
enum {
    TRANSITION_DONE    = 0x1,
    TRANSITION_ENABLED = 0x2,
    TRANSITION_CANCEL  = 0x4
};

#endif
