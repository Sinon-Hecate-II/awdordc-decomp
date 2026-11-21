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

/* Tilemap glyphs use two consecutive tiles and a 32-entry row. */
#define TILEMAP_GLYPH_ROW_SHIFT       6 /* log2 of the row size in bytes */
#define TILEMAP_GLYPH_ROW_BYTES       (1 << TILEMAP_GLYPH_ROW_SHIFT)
#define TILEMAP_DIGIT_FIRST_TILE      0x10
#define TILEMAP_GLYPH_ALT_VARIANT     3
#define TILEMAP_GLYPH_ALT_TILE_OFFSET 0x1C

/* Byte of the bank copied to the display blend register (0..31). */
#define DS3D_BANK_BLEND 0x53

/* The bank's OBJ attribute word (its priority is in bits 6..7). */
#define DS3D_BANK_OAMATTR 0x12
#define DS3D_BANK_OAMATTR_PRIORITY 0x00C0 /* OBJ priority bits of oamAttr */

/* Rows of the bank's cell grid above/below the split point. */
#define DS3D_BANK_ROWS_ABOVE 0x51
#define DS3D_BANK_ROWS_BELOW 0x52

/* DS3DSpriteBank::flags bits 4..8 select the active screen mode, one-hot: the
 * mode index Get3DSpriteScreenMode() returns. Reset3DSpriteLayers clears them. */
#define DS3D_BANK_MODE0 0x0010
#define DS3D_BANK_MODE1 0x0020
#define DS3D_BANK_MODE2 0x0040
#define DS3D_BANK_MODE3 0x0080
#define DS3D_BANK_MODE4 0x0100
/* The remaining three bits of the same one-hot field.  No code selects these
 * modes, but the full bank reset (func_02076244) clears all eight. */
#define DS3D_BANK_MODE5 0x0200
#define DS3D_BANK_MODE6 0x0400
#define DS3D_BANK_MODE7 0x0800

/* Bank flags copied to DISPCNT's OBJ mapping and boundary fields. */
#define DS3D_BANK_OBJ_MAPPING_1D 0x0008 /* bit 3: 1D OBJ character VRAM mapping, clear for 2D */
#define DS3D_BANK_OBJ_1D 0x1000
#define DS3D_BANK_OBJ_BOUNDARY_MASK 0x6000
#define DS3D_BANK_OBJ_BOUNDARY_SHIFT 13
#define DS3D_BANK_OBJ_BOUNDARY_BITS 2

/* OBJ attribute fields for wrapped coordinates and the hardware tile index. */
#define DS3D_OBJ_X_MASK    0x1FF
#define DS3D_OBJ_TILE_MASK 0x3FF
#define DS3D_DISPLAY_GRAPHICS 1

/* The four layer attribute words of the bank, one per layer (packed SpriteTile). */
#define DS3D_BANK_LAYER_TILE0 0x06
#define DS3D_BANK_LAYER_TILE1 0x08
#define DS3D_BANK_LAYER_TILE2 0x0A
#define DS3D_BANK_LAYER_TILE3 0x0C

/* The flags word at bank+0x02 holds two 3-bit fields, which
 * Reset3DSpriteLayerRegisters clears. */
#define DS3D_BANK_MODE_WORD       0x02
#define DS3D_BANK_MODE_WORD_BITS0 0x0007
#define DS3D_BANK_MODE_WORD_BITS1 0x0038

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

/* The engine's screen offsets (s16 at +0x3C/+0x3E) and its second offset pair
 * (filler_40/filler_42), which is added to them when the sprite's size is
 * measured. */
#define DS3D_OFFSET_X  0x3C
#define DS3D_OFFSET_Y  0x3E
#define DS3D_OFFSET2_X 0x40
#define DS3D_OFFSET2_Y 0x42

/* Extra layer displacement used by the split-map scroll animation. */
#define DS3D_SCROLL_LAYER_X 0x38 /* s16 scroll displacement on the x axis */
#define DS3D_SCROLL_LAYER_Y 0x3A /* s16 scroll displacement on the y axis */

/* Byte offsets, from the sprite bank plus the layer's s16 index, of that layer's
 * quad offset: x at +0x38, y at +0x40 (see DS3DSpriteBank::corner). */
#define DS3D_QUAD_X 0x38
#define DS3D_QUAD_Y 0x40
/* One layer's quad offset in a bank: x is corner[layer], y is corner[layer+4]
 * (layer 0..3).  These are the byte offsets the code stores through. */
#define DS3D_CORNER_X(layer) (DS3D_QUAD_X + (layer) * 2)
#define DS3D_CORNER_Y(layer) (DS3D_QUAD_Y + (layer) * 2)

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
    s32 displayMode;   /* +0x34 DISPCNT display mode: 1 = graphics */
    s16 corner[8];     /* +0x38 the four layers' quad offsets: x in [0..3], y in [4..7] */
    u8  window0H[2];   /* +0x48 split window 0 horizontal bounds (right, left) */
    u8  window0V[2];   /* +0x4A split window 0 vertical bounds */
    u8  window1H[2];   /* +0x4C split window 1 horizontal bounds (right, left) */
    u8  window1V[2];   /* +0x4E split window 1 vertical bounds */
    s8  brightness;    /* +0x50 signed master brightness, 0 = unchanged */
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
    void *filler_54; /* +0x54 this screen's shared default text object (TextState, main_0209ACC4) */
} DS3DSpriteEngine;

/* The hardware OAM of the two screens: 0x400 bytes each, filled with 0xC0
 * attribute bytes to disable every entry. */
#define DS3D_OAM_MAIN     0x07000000
#define DS3D_OAM_SUB      0x07000400
#define DS3D_OAM_BYTES    0x400
#define DS3D_OAM_DISABLED 0xC0

/* The engine a gCur3DSpriteEngine / g3DSpriteEngineMain pointer refers to, and
 * the sprite bank that engine owns (its first word). */
#define DS3D_ENGINE(enginePtr) ((DS3DSpriteEngine *)(enginePtr))
#define DS3D_BANK(enginePtr) ((DS3DSpriteBank *)(*(void **)(enginePtr)))

/* Engine fields code reaches through a void *gCur3DSpriteEngine. */
#define DS3D_ENGINE_OAM      0x34 /* void *OAM shadow of this engine, 0x400 bytes */
#define DS3D_ENGINE_SRC      0x38 /* u16 *quads queued for the next flush, four u16 each */
#define DS3D_ENGINE_COUNT    0x48 /* u8 OAM entries in use */
#define DS3D_ENGINE_INDEX    0x4A /* u8 quads queued since the last flush */
#define DS3D_ENGINE_TEXTURE 0x1C /* u32 VRAM address graphics blocks are decompressed to */
#define DS3D_ENGINE_PALETTES 0x30 /* void *0x400-byte OBJ palette shadow: 32 palettes of 0x20 bytes */
#define DS3D_ENGINE_DIRTY    0x46 /* u8 DS3D_DIRTY_* bits (and bit i per layer) */
/* The engine's cached text (the object at +0x50): the strings it has already
 * rasterised into tiles, so a repeated string is drawn without re-rasterising. */
#define DS3D_ENGINE_TEXT_CACHE 0x50 /* void *this engine's cached-text object */
#define DS3D_ENGINE_TEXT_STATE 0x54 /* void *this screen's shared default text object (TextState, main_0209ACC4) */
#define TEXT_CACHE_EMPTY     0x00 /* u8 1 when no string is cached */
#define TEXT_CACHE_ENTRIES   0x200 /* 4 bytes per cached string: u16 tile, u8 width, u8 style */
#define TEXT_CACHE_NEXT_TILE 0x300 /* u16 tile the next string is rasterised at */
#define TEXT_CACHE_LAYER     0x302 /* u8 layer the text is drawn on */
#define TEXT_GLYPH_TILES     0x700 /* bytes of one glyph tile set the text starts from */
#define TEXT_GLYPH_OFFSET    16    /* tiles between the base tile and the glyph tiles */
#define TEXT_FIRST_TILE      100   /* tiles between the base tile and the first string */
#define DS3D_PALETTE_SHIFT   5    /* log2 of the byte size of a 16-colour palette */
#define DS3D_PALETTE_BYTES   (1 << DS3D_PALETTE_SHIFT)
#define DS3D_OBJ_PALETTE_BASE 16  /* OBJ slots follow the 16 BG slots in the palette shadow */
#define DS3D_PALETTE_15      15   /* colours in a palette the fade code rewrites */

/* One entry of gWallpaperFileSets: the files of a wallpaper in one language. */
typedef struct WallpaperFileSet {
    const char *name;  /* +0x00 base name of the set's files, e.g. "wallp_bmap_s" */
    u8   sizeCode;     /* +0x04 tile size class, see SetLayerSize */
    u8   filler_05;
    u16  scrollWidth;  /* +0x06 horizontal wrap threshold */
    u16  scrollHeight; /* +0x08 vertical wrap threshold */
    s16  screenGap;    /* +0x0A added to both offsets on the second screen */
    u8   scrollPeriod; /* +0x0C frames between scroll updates, 0 disables scrolling */
    s8   scrollX;      /* +0x0D horizontal step */
    s8   scrollY;      /* +0x0E vertical step */
    u8   filler_0F;
    s16  offsetA;      /* +0x10 copied to the wallpaper object */
    s16  offsetB;      /* +0x12 copied to the wallpaper object */
} WallpaperFileSet;

/* The wallpaper sprite objects built for the main and sub screens: the wallpaper
 * set it shows, that set's file record, the sprite layer and palette its graphics
 * load into, and two position offsets taken from the set (the sub-screen copy adds
 * the set's screen gap). */
#define WALLPAPER_SET            0x34 /* u8 index into gWallpaperFileSets */
#define WALLPAPER_FILE_SET       0x38 /* WallpaperFileSet *the set's files */
#define WALLPAPER_MAIN_LAYER     0x3c /* u8 main-screen sprite layer */
#define WALLPAPER_MAIN_PALETTE   0x3d /* u8 main-screen palette index */
#define WALLPAPER_MAIN_OFFSET_A  0x3e /* s16 main-screen first offset (set offsetA) */
#define WALLPAPER_MAIN_OFFSET_B  0x40 /* s16 main-screen second offset (set offsetB) */
#define WALLPAPER_MAIN_STATE     0x42 /* s16 main-screen scroll state, starts at 0 */
#define WALLPAPER_SUB_LAYER      0x44 /* u8 sub-screen sprite layer */
#define WALLPAPER_SUB_PALETTE    0x45 /* u8 sub-screen palette index */
#define WALLPAPER_SUB_OFFSET_A   0x46 /* s16 sub-screen first offset (set offsetA + screenGap) */
#define WALLPAPER_SUB_OFFSET_B   0x48 /* s16 sub-screen second offset (set offsetB + screenGap) */
#define WALLPAPER_SUB_STATE      0x4a /* s16 sub-screen scroll state, starts at 0 */

/* DS3DSpriteEngine::layerDirty bit of the OBJ palette shadow. */
#define DS3D_DIRTY_PALETTE 0x10

/* DS3DSpriteEngine::layerDirty bits: bit i says layer i's data changed and the
 * layer must be rebuilt. */
#define DS3D_DIRTY_LAYER0 0x01
#define DS3D_DIRTY_LAYER1 0x02
#define DS3D_DIRTY_LAYER2 0x04
#define DS3D_DIRTY_LAYER3 0x08
#define DS3D_LAYER_PALETTE_BYTES 0x200 /* 256 colours, two bytes each */

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

/* A screen-transition object: a 3D sprite (one of the fade classes) that slides
 * the visible screen sideways or splits it over a number of frames, then applies
 * the new screen mode and deletes itself.  Only its own fields past the plain
 * object fields (0x00..0x33) are known. */
typedef struct DS3DSpriteScreenFade {
    u8  pad00[0x34];
    s32 mode;      /* +0x34 direction: 0/1 slide one way or the other, 2 split */
    u16 elapsed;   /* +0x38 frames elapsed */
    u16 length;    /* +0x3A frames the transition takes */
    u8  screen;    /* +0x3C screen (3D-sprite engine) that shows the transition */
    u8  pad3d[3];
    s32 resource;  /* +0x40 sprite resource freed with the object, 0 when none */
} DS3DSpriteScreenFade;

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

/* A screen-change transition sprite: the 3D sprite object that animates the
 * display transition (a fade or the split) on one screen.  Its fields come after
 * the plain 3D sprite object fields; the elapsed frame count is advanced by the
 * object's own update callback. */
#define TRANSITION_SPRITE_MODE    0x34 /* s32 TRANSITION_MODE_*, or 3 for the active screen's mode */
#define TRANSITION_SPRITE_ELAPSED 0x38 /* u16 frames elapsed */
#define TRANSITION_SPRITE_LENGTH  0x3a /* u16 frames the transition takes */
#define TRANSITION_SPRITE_SCREEN  0x3c /* u8 screen to animate: 0 main, 1 sub, 3 the active one */
#define TRANSITION_SPRITE_PARENT  0x40 /* void *parent sprite whose child count it holds */

/* TRANSITION_SPRITE_MODE values. */
enum {
    TRANSITION_MODE_DARK   = 0, /* fade the screen down to black (brightness -16) */
    TRANSITION_MODE_BRIGHT = 1, /* fade the screen up to white (brightness +16) */
    TRANSITION_MODE_SPLIT  = 2  /* split the screen into two sliding windows */
};

/* A queued 3D sprite task: a plain 3D sprite object created by CreateQueuedSpriteTask
 * (main_0209CC04.c), which records the function the engine runs at +0x34.  The
 * copy/upload tasks in main_0207C2F0.c keep their arguments in the fields
 * below; the callback runs once and then the object is destroyed. */
#define DS3D_TASK_CALLBACK    0x34 /* void (*)(void *): the task's run function */
#define DS3D_TASK_SOURCE      0x38 /* void *source block to copy or upload */
#define DS3D_TASK_DEST        0x3C /* void *destination of a memory copy */
#define DS3D_TASK_SIZE        0x40 /* s32 bytes to copy or upload */
#define DS3D_TASK_OFFSET      0x44 /* s32 destination offset of a VRAM/palette upload */
#define DS3D_TASK_FREE_SOURCE 0x50 /* s32: free SOURCE when the task has run */
#define DS3D_COPY_TASK_Z      0xFF02 /* sprite depth used by queued copies and uploads */

/* A task sprite: a 3D sprite object that owns an OS thread, so that the thread
 * lives in a heap block freed with the object.  Creation allocates the thread
 * (TASK_SPRITE_THREAD_SIZE bytes) and its stack, starts the entry function on
 * it and wakes it; the object's class destructor frees both blocks and calls
 * TASK_SPRITE_CLEANUP.  The plain 3D sprite object fields (0x00..0x33) come
 * first. */
#define TASK_SPRITE_THREAD   0x34 /* void *OS thread object the sprite owns */
#define TASK_SPRITE_STACK    0x38 /* u8 *bottom of the thread's stack block */
#define TASK_SPRITE_CLEANUP  0x3C /* void (*)(void) run when the sprite is destroyed */
#define TASK_SPRITE_ENTRY    0x40 /* void (*)(void): the thread's entry function */
#define TASK_SPRITE_ARG      0x44 /* s32 argument recorded for the entry function */
#define TASK_SPRITE_THREAD_SIZE 0xC0 /* bytes of the thread object */

/* The UI mode the list/menu screens are in (gUiMode points at one UiModeState):
 * the mode in effect, the one asked for with SetUiMode and, while a sub screen
 * (mode 3) is up, the mode to come back to.  A requested mode is applied in one
 * step (previous <- current <- requested) once the screen change that covers the
 * swap has finished, that is once IsUiModeSwitchBusy() returns 0; `param` is the
 * value the new mode's screen object is created with, the chosen list row for
 * the modes that take one.  Mode 1 is the battle map screen (overlay 0) and mode
 * 2 is entered through the screen-change transition. */
typedef struct UiModeState {
    s16 previous;  /* +0x00 mode before the current one */
    s16 current;   /* +0x02 mode in effect, returned by GetUiMode */
    s16 requested; /* +0x04 mode asked for by SetUiMode */
    s16 saved;     /* +0x06 mode saved while a sub screen (mode 3) is up */
    s32 param;     /* +0x08 parameter of the requested mode */
} UiModeState;

/* Fields of a 3D sprite object, the nodes of the twelve per-layer sprite lists
 * (g3DSpriteLists) that Update3DSpriteObject walks.  An object has a sibling
 * chain through NEXT and a child tree through CHILD. */
#define DS3D_SPRITE_CLASS        0x00 /* void ** class pointer; its +0 method destroys the object */
#define DS3D_SPRITE_ALIVE        0x04 /* s32 class pointer; 0 once the object is deleted */
#define DS3D_SPRITE_ANIM         0x08 /* s16 *state cursor: 8-byte entries, DS3D_STATE_* */
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
#define DS3D_SPRITE_TEMPLATE     0x44 /* void *: the SpriteQuadTemplate the sprite draws (handed to AddSprite) */
#define DS3D_SPRITE_CELLS        0x64 /* void *the object's SpriteCellList (see sprite_grid.h) */
#define DS3D_CLASS_DESTROY       0x00 /* method at DS3D_SPRITE_CLASS +0x00: destroys the object it is given */

/* One entry of an object's animation state cursor (DS3D_SPRITE_ANIM).  The state
 * machine runs the handler g3DSpriteStateHandlers[id] of the current entry; a
 * handler advances the cursor by DS3D_STATE_SIZE to move on to the next entry. */
#define DS3D_STATE_SIZE  0x08 /* bytes per state entry */
#define DS3D_STATE_ID    0x00 /* s16 index into g3DSpriteStateHandlers (data_01ffa068) */
#define DS3D_STATE_PARAM 0x02 /* s16 parameter of the state's handler */
#define DS3D_STATE_DATA  0x04 /* s32 handler data (a class, callback or script) */

/* The 3D sprite pool and its allocator.  g3DSpriteObjects is the pool of
 * DS3D_SPRITE_COUNT objects of DS3D_SPRITE_SIZE bytes each; g3DSpriteOrder is the
 * array of pointers to them with the live objects first, g3DSpriteAllocator is the
 * boundary into that array (its cursor field) and g3DSpriteLayerHeads holds the
 * twelve per-layer list heads. */
#define DS3D_SPRITE_COUNT  0x80  /* objects in the pool */
#define DS3D_SPRITE_SIZE   0x74  /* bytes of one object */
#define DS3D_SPRITE_Z_NONE 0xFF00 /* DS3D_SPRITE_Z of an object with no depth set */
#define DS3D_ALLOC_CURSOR  0x00  /* void *: first free slot in the order array */
#define DS3D_ALLOC_TAIL    0x234 /* word after the order array; the reset clears it */

/* DS3D_SPRITE_FLAGS bits. */
#define DS3D_SPRITE_FLAG_DEAD       0x01 /* removed from its list; the walk stops for it */
#define DS3D_SPRITE_FLAG_TREE_OWNED 0x02 /* freed as part of a tree, not on its own */
#define DS3D_SPRITE_FLAG_HAS_PARENT 0x04 /* the object was created as a child object */
#define DS3D_SPRITE_FLAG_INIT       0x08 /* still initialising; the first update is skipped */
#define DS3D_SPRITE_FLAG_NEW        0x10 /* first update deferred until the screen is ready */
#define DS3D_SPRITE_FLAG_VISITING   0x20 /* recursion guard: the object is being visited */
#define DS3D_SPRITE_FLAG_REPEAT     0x40 /* the update asked to run again this frame */

/* A screen-offset track sprite: a 3D sprite object whose update callback
 * (see main_02080414.c) moves one or both engines' offset pair along a
 * looping 2-D path and hands the object back to its regular animation after
 * `steps` path points (or after the first pass when `steps` is -1).  The path
 * tables are the pointers in g3DSpriteOffsetTracks; a point whose x is 0x7FFF
 * ends a pass. */
typedef struct DS3DSpriteOffsetTrack {
    u8  pad00[0x4C];
    s16 steps;      /* +0x4C path points shown before the effect ends, -1 = one pass */
    u8  pad4E[2];
    s16 target;     /* +0x50 Set3DSpriteOffset target: which engine offsets move */
    u16 scale;      /* +0x52 offset size in percent */
    s16 (*path)[2]; /* +0x54 path points: x in [0], y in [1], 0x7FFF ends a pass */
    u8  pad58[4];
    s32 index;      /* +0x5C current path point */
    s32 elapsed;    /* +0x60 path points shown so far */
} DS3DSpriteOffsetTrack;


/* Fields a 3D sprite object gains when it is a screen flash (func_02080358
 * creates it; the update callbacks in main_02080414 step it): the fade to white,
 * a hold at white, then the fade back.  The plain 3D sprite object fields
 * (0x00..0x33) come first. */
#define DS3D_SPRITE_FLASH_IN_ELAPSED   0x5C /* s32 frames the fade to white has run */
#define DS3D_SPRITE_FLASH_HOLD_ELAPSED 0x60 /* s32 frames the white screen has been held */
#define DS3D_SPRITE_FLASH_OUT_ELAPSED  0x64 /* s32 frames the fade back has run */
#define DS3D_SPRITE_FLASH_IN_FRAMES    0x6C /* s16 frames the fade to white takes */
#define DS3D_SPRITE_FLASH_HOLD_FRAMES  0x6E /* s16 frames the white screen is held */
#define DS3D_SPRITE_FLASH_OUT_FRAMES   0x70 /* s16 frames the fade back takes */


/* Palette fade fields a 3D sprite object gains when it is animated by
 * UpdatePaletteFade (main_0208C830): the object fades the palette of its layer
 * from `from` to `to` over `duration` frames.  The plain 3D sprite object
 * fields (0x00..0x33) come first. */
typedef struct DS3DSpritePaletteFade {
    u8  pad00[0x34];
    u8  palette;   /* +0x34 palette slot in the engine's OBJ palette shadow */
    u8  flags;     /* +0x35 DS3D_FADE_* bits */
    u8  timer;     /* +0x36 frames elapsed */
    u8  duration;  /* +0x37 frames one fade takes */
    u16 from[15];  /* +0x38 palette faded from */
    u16 to[15];    /* +0x56 palette faded to */
} DS3DSpritePaletteFade;

/* DS3DSpritePaletteFade::flags */
#define DS3D_FADE_ACTIVE   0x01 /* the fade is running */
#define DS3D_FADE_FORWARD  0x02 /* fade towards `to`, otherwise towards `from` */
#define DS3D_FADE_PINGPONG 0x04 /* reverse direction instead of stopping */
#define DS3D_FADE_DELETE   0x08 /* delete the object once the fade has finished */

/* The three scene panels occupy the top, middle and bottom 64-pixel bands. */
enum {
    SCENE_PANEL_TOP = 0,
    SCENE_PANEL_MIDDLE = 1,
    SCENE_PANEL_BOTTOM = 2,
    SCENE_PANEL_CURRENT = 3
};

/* Screen the 3D-sprite system draws on, returned by Get3DSpriteTarget. */
enum {
    DS3D_TARGET_MAIN   = 0,
    DS3D_TARGET_SUB    = 1,
    DS3D_TARGET_BOTH   = 2, /* both engines, one after the other */
    DS3D_TARGET_ACTIVE = 3 /* whichever engine gCur3DSpriteEngine already holds */
};

/* One 12-byte panel record at the start of Get3DSpriteManager(). */
#define SCENE_PANEL_TILE_COLUMNS 32 /* u16 cells in one row of a panel's tilemap */
typedef struct ScenePanelState {
    void *tiles;       /* +0x00 tile buffer */
    u16 tileAttr;      /* +0x04 tile attributes passed to the text renderer */
    u8 palette;        /* +0x06 OBJ palette slot */
    u8 mode;           /* +0x07 */
    u16 unk_08;        /* +0x08 */
    u8 unk_0A[2];
} ScenePanelState;

/* Input action flags of the scene-panel widgets, returned for the buttons and
 * for the stylus. */
enum {
    PANEL_INPUT_LEFT    = 0x04, /* left key, or a touch on the widget's left half */
    PANEL_INPUT_RIGHT   = 0x08, /* right key, or a touch on the widget's right half */
    PANEL_INPUT_CONFIRM = 0x10, /* A key, or a touch release on the touched half */
    PANEL_INPUT_CANCEL  = 0x20, /* B key */
    PANEL_INPUT_SKIP    = 0x400 /* Start key: skip or advance a message */
};

/* Text layer of a 3D sprite object: the object shows `values[palette]` through
 * the text renderer of the layer it asks for, on one or both display banks.
 * Fields at 0x34.. are the text layer's own, past the plain object fields. */
#define TEXT_LAYER_FLAGS    0x34 /* u8 TEXT_LAYER_FLAG_* */
#define TEXT_LAYER_ENGINE   0x35 /* s8 engine to draw on: 0 main, 1 sub, 3 active, below 0 both */
#define TEXT_LAYER_VALUE    0x36 /* u16 palette offset of the layer's text */

/* TEXT_LAYER_FLAGS bits. */
#define TEXT_LAYER_FLAG_CONFIRMED 0x01 /* the screen choice was confirmed */

/* TEXT_LAYER_FLAGS bits of the online-match label sprites: the confirmed bit
 * above is theirs too, so their split transitions use the next two bits. */
#define ONLINE_LABEL_FLAG_SPLIT_MAIN 0x02 /* main screen's split transition started */
#define ONLINE_LABEL_FLAG_SPLIT_SUB  0x04 /* sub screen's split transition started */

/* The text renderer's bitmap: TEXT_BITMAP_ROW_BYTES-byte pixel rows, eight rows
 * to a TEXT_BITMAP_BLOCK_BYTES-byte block whose upper and lower halves are kept
 * apart for the 3D sprite. */
#define TEXT_BITMAP_ROW_BYTES   32
#define TEXT_BITMAP_BLOCK_ROWS  8
#define TEXT_BITMAP_BLOCK_BYTES 256

/* A two-state widget of a scene panel: two 32x16 halves side by side, one of
 * them selected. The layout helper places it and the update helper handles its
 * input and runs `callback` once the user has chosen. */
typedef struct ToggleWidget {
    u8 pad00[0x34];
    s16 selected;           /* +0x34 0 = left half, 1 = right half */
    u8 pad36[0x0A];
    u8 engine;              /* +0x40 engine (screen) whose layer the widget is on */
    u8 pad41[3];
    void (*callback)(void); /* +0x44 run after the choice is made */
    u16 panelEntry;         /* +0x48 panel entry the widget was created on */
    s16 x;                  /* +0x4A x offset of the selected half */
    s32 tile;               /* +0x4C offset of the widget's tile in the layer */
} ToggleWidget;             /* 0x50 bytes */

/* A CO face sprite (the portrait nodes built by func_02099338): a 3D sprite
 * object extended with the face texture shown, its expression and palette
 * style, and a linked face object that is refreshed with it. */
#define FACE_SPRITE_TILE        0x40 /* u32: bits 18..25 are the face tile row */
#define FACE_SPRITE_TILE_ROW_MASK 0x03FC0000 /* bits of FACE_SPRITE_TILE holding the row */
#define FACE_SPRITE_SCREEN      0x48 /* u8: bits 1..3 pick the engine (0 main, 1 sub, 3 active) */
#define FACE_SPRITE_TILE_ROW    0x49 /* u8 tile row inside the face texture */
#define FACE_SPRITE_FACE        0x58 /* u8 face id; 0 = no face loaded */
#define FACE_SPRITE_EXPRESSION  0x59 /* u8 expression/pose index; 0 = none */
#define FACE_SPRITE_LAYOUT      0x5A /* u8 layout of the linked face group */
#define FACE_SPRITE_VARIANT     0x5B /* u8 variant index into the face table */
#define FACE_SPRITE_ACTIVE      0x5C /* u8 nonzero while this is the active face */
#define FACE_SPRITE_PALETTE     0x5D /* u8 palette style: 1 sepia, 2 grayscale */
#define FACE_SPRITE_CHILD       0x60 /* void *linked face object refreshed with this one */

/* Palette effects LoadFacePaletteAt applies to the face palette it loads. */
#define FACE_EFFECT_DIM   0x01 /* inactive face: blend towards dark blue */
#define FACE_EFFECT_SEPIA 0x02 /* warm tint */
#define FACE_EFFECT_GRAY  0x04 /* grayscale */
#define FACE_EFFECT_DIM_HALF 0x08 /* blend half way towards black */
#define FACE_EFFECT_DIM_MOST 0x10 /* blend down to a quarter brightness */
#define FACE_EFFECT_BLACK 0x20 /* blend all the way to black */

/* Face layout types, the index into the face graphics file table (see
 * GetFaceLayoutFile): info.cg, select.cg, the battle (btl), talk and body
 * poses neutral/smile/angry, and the defeated break.cg.  The layout size
 * helpers give the pixel size of each layout's texture. */
enum {
    FACE_LAYOUT_INFO = 0,
    FACE_LAYOUT_SELECT = 1,
    FACE_LAYOUT_BTL_N = 2,
    FACE_LAYOUT_BTL_S = 3,
    FACE_LAYOUT_BTL_A = 4,
    FACE_LAYOUT_TALK_N = 5,
    FACE_LAYOUT_TALK_S = 6,
    FACE_LAYOUT_TALK_A = 7,
    FACE_LAYOUT_BODY_N = 8,
    FACE_LAYOUT_BODY_S = 9,
    FACE_LAYOUT_BODY_A = 10,
    FACE_LAYOUT_BREAK = 11
};

#endif
