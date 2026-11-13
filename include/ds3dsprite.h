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

/* DS3DSpriteBank::flags bits 4..8 select the active screen mode, one-hot: the
 * mode index Get3DSpriteScreenMode() returns. Reset3DSpriteLayers clears them. */
#define DS3D_BANK_MODE0 0x0010
#define DS3D_BANK_MODE1 0x0020
#define DS3D_BANK_MODE2 0x0040
#define DS3D_BANK_MODE3 0x0080
#define DS3D_BANK_MODE4 0x0100

/* The four layer attribute words of the bank, one per layer (packed SpriteTile). */
#define DS3D_BANK_LAYER_TILE0 0x06
#define DS3D_BANK_LAYER_TILE1 0x08
#define DS3D_BANK_LAYER_TILE2 0x0A
#define DS3D_BANK_LAYER_TILE3 0x0C

/* The window registers of the bank that the screen-split transition animates:
 * two bounds per window, all zero once the transition has finished. */
#define DS3D_BANK_WINDOW0_H 0x48
#define DS3D_BANK_WINDOW0_V 0x4a
#define DS3D_BANK_WINDOW1_H 0x4c
#define DS3D_BANK_WINDOW1_V 0x4e

/* Which of a bank's two layer matrices a transform is built into (the G3_*
 * transform helpers take one of these). */
#define DS3D_MATRIX_A 2 /* DS3DSpriteBank.matrixA, includes the screen offset */
#define DS3D_MATRIX_B 3 /* DS3DSpriteBank.matrixB, relative to the screen offset */

/* Affine transform of the 3D sprite's layer grid, built by BuildSpriteTransform
 * from a DS3DSpriteTransform. The coefficients are 8.8 fixed point. */
typedef struct DS3DSpriteMatrix {
    s16 m00; /* +0x00 */
    s16 m01; /* +0x02 */
    s16 m10; /* +0x04 */
    s16 m11; /* +0x06 */
    s32 tx;  /* +0x08 translation, 8.8 fixed point */
    s32 ty;  /* +0x0C */
} DS3DSpriteMatrix; /* 0x10 bytes */

/* Source description of a 3D sprite transform: a point, the point it maps to,
 * the scale of the two axes and the rotation angle (0..0xFFFF). */
typedef struct DS3DSpriteTransform {
    s32 x;       /* +0x00 source x, 8.8 fixed point */
    s32 y;       /* +0x04 source y, 8.8 fixed point */
    s16 mapX;    /* +0x08 x the source maps to */
    s16 mapY;    /* +0x0A y the source maps to */
    s16 scaleX;  /* +0x0C x scale, 8.8 fixed point */
    s16 scaleY;  /* +0x0E y scale, 8.8 fixed point */
    u16 angle;   /* +0x10 rotation, 0..0xFFFF */
    u8  filler_12[2];
} DS3DSpriteTransform; /* 0x14 bytes */

typedef struct DS3DSpriteBank {
    u16 flags;         /* +0x00 */
    u8  filler_02[0x10];
    u16 oamAttr;       /* +0x12 OBJ attribute word of the 3D sprite */
    DS3DSpriteMatrix matrixA; /* +0x14 transform including the screen offset */
    DS3DSpriteMatrix matrixB; /* +0x24 transform relative to the screen offset */
    u8  filler_34[4];
    s16 corner[8];     /* +0x38 four (x,y) corner offsets of the sprite quad */
    u8  window0H[2];   /* +0x48 split window 0 horizontal bounds (right, left) */
    u8  window0V[2];   /* +0x4A split window 0 vertical bounds */
    u8  window1H[2];   /* +0x4C split window 1 horizontal bounds (right, left) */
    u8  window1V[2];   /* +0x4E split window 1 vertical bounds */
    u8  filler_50;
    u8  rowsAbove;     /* +0x51 rows of the cell grid above the split */
    u8  rowsBelow;     /* +0x52 rows of the cell grid below the split */
    u8  filler_53;     /* +0x53 display blend level (0..31) */
} DS3DSpriteBank;

/* A 3D sprite quad template: a quad count (always 1) followed by the three OAM
 * attribute words of that quad.  The gSpriteDescWxH templates in DTCM are these;
 * AddSprite hands one to the sprite engine as its source quad. */
typedef struct SpriteQuadTemplate {
    u16 count;   /* +0x00 number of quads that follow */
    u16 attr[3]; /* +0x02 OAM attribute words 0..2 of the quad */
} SpriteQuadTemplate;

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

/* Fields of a 3D sprite object, the nodes of the twelve per-layer sprite lists
 * (g3DSpriteLists) that Update3DSpriteObject walks.  An object has a sibling
 * chain through NEXT and a child tree through CHILD. */
#define DS3D_SPRITE_CLASS        0x00 /* void ** class pointer; its +0 method destroys the object */
#define DS3D_SPRITE_ALIVE        0x04 /* s32 nonzero while the object is alive */
#define DS3D_SPRITE_ANIM         0x08 /* s16 *animation state: the low half indexes the state table */
#define DS3D_SPRITE_DELETE_CB    0x0C /* void (*)(void *) run while the object is destroyed */
#define DS3D_SPRITE_UPDATE_CB    0x10 /* void (*)(void *): overrides the default state update */
#define DS3D_SPRITE_DRAW_CB      0x14 /* void (*)(void *): draw pass, run after the update */
#define DS3D_SPRITE_PARENT       0x18 /* u32 parent object, or a layer index below 12 */
#define DS3D_SPRITE_CHILD        0x1C /* void *first child */
#define DS3D_SPRITE_PREV         0x20 /* void *previous sibling */
#define DS3D_SPRITE_NEXT         0x24 /* void *next sibling */
#define DS3D_SPRITE_ENGINE       0x28 /* s32 engine to point gCur3DSpriteEngine at while the callbacks run */
#define DS3D_SPRITE_LAYER        0x2C /* u16 */
#define DS3D_SPRITE_Z            0x2E /* u16 */
#define DS3D_SPRITE_FLAGS        0x30 /* u8 DS3D_SPRITE_FLAG_* */
#define DS3D_SPRITE_CHILD_COUNT  0x31 /* u8 number of children */

/* DS3D_SPRITE_FLAGS bits. */
#define DS3D_SPRITE_FLAG_DEAD       0x01 /* removed from its list; the walk stops for it */
#define DS3D_SPRITE_FLAG_TREE_OWNED 0x02 /* freed as part of a tree, not on its own */
#define DS3D_SPRITE_FLAG_HAS_PARENT 0x04 /* the object was created as a child object */
#define DS3D_SPRITE_FLAG_INIT       0x08 /* still initialising; the first update is skipped */
#define DS3D_SPRITE_FLAG_NEW        0x10 /* first update deferred until the screen is ready */
#define DS3D_SPRITE_FLAG_VISITING   0x20 /* recursion guard: the object is being visited */
#define DS3D_SPRITE_FLAG_REPEAT     0x40 /* the update asked to run again this frame */

#endif
