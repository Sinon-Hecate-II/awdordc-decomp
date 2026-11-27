/* Per-unit-kind sprite descriptor returned by the unit-kind lookup.  The record
 * is picked from the low seven bits of a unit object's kind byte (object+0x58). */
#ifndef UNIT_SPRITE_H
#define UNIT_SPRITE_H

typedef struct UnitSpriteDef {
    u8 width;    /* +0x00 sprite width, 0 = keep the object's own tile x */
    u8 height;   /* +0x01 sprite height, 0 = keep the object's own tile y */
    u8 pad[2];
    s32 gfx;     /* +0x04 graphics/frame data pointer stored at object+0x44 */
    u32 flags;   /* +0x08 bit 4: read the other screen's key state */
} UnitSpriteDef; /* 12 bytes */

/* The frame word and base-frame byte of a sprite object (at the offsets
 * MENU_SPRITE_FRAME / MENU_SPRITE_BASE in common.h).  The pressed frame is the
 * base frame plus one. */
typedef struct SpriteFrameBits {
    u32 low:18;
    u32 frame:8;   /* displayed frame index */
    u32 high:6;
} SpriteFrameBits;

typedef struct SpriteBaseBits {
    u8 base:4;     /* base frame index */
} SpriteBaseBits;

/* A unit sprite's button task (class gUnitSpriteButtonTaskClass): a small object
 * the sprite at UNIT_SPRITE_BUTTON_TASK points at, which watches the given key
 * mask and plays the sprite's press animation.  Its per-frame update is
 * UpdateUnitSpriteAnimation. */
#define UNIT_SPRITE_BUTTON_TASK 0x60 /* void *the sprite's button task, 0 when none */
#define UNIT_SPRITE_CELLS       0x64 /* SpriteCellList *the sprite's cell list, freed with the sprite */
#define UNIT_SPRITE_TASK_SPRITE 0x34 /* void *unit sprite the task drives */
#define UNIT_SPRITE_TASK_BUTTONS 0x38 /* u16 key mask that presses the sprite */
#define UNIT_SPRITE_UNIT        0x54 /* void *the map unit record the sprite draws */
#define UNIT_SPRITE_TILE_X      0x34 /* s32 tile x copied from the unit record's +1 */
#define UNIT_SPRITE_TILE_Y      0x38 /* s32 tile y copied from the unit record's +2 */

/* A unit sprite also serves as a menu entry sprite: the ov003 unit list, setup
 * menu and map grid draw their entries as unit sprites whose depth
 * (DS3D_SPRITE_Z) is the entry's index.  These four hold the index the d-pad
 * moves to from this entry; the sprite at that index is then looked up by
 * class and depth (the directional helpers in main_020AB884.c). */
#define UNIT_SPRITE_UP    0x68 /* u16 entry index above this one */
#define UNIT_SPRITE_DOWN  0x6A /* u16 entry index below this one */
#define UNIT_SPRITE_LEFT  0x6C /* u16 entry index to the left */
#define UNIT_SPRITE_RIGHT 0x6E /* u16 entry index to the right */

/* The unit sprites' shared input flags at gUnitSpriteInput: the hold counter at
 * +0 pauses their per-frame animation updates while nonzero, and the pressed
 * flag at +1 is set by MarkUnitSpritePressed while any unit sprite is pressed. */
#define UNIT_SPRITE_HOLD_COUNT 0
#define UNIT_SPRITE_PRESSED    1

#endif
