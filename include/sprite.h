/* The animated 2D/3D sprite object driven by the sprite script runner: it owns
 * a frame pointer, an animation script cursor and the delay between script
 * entries. */
#ifndef SPRITE_H
#define SPRITE_H

/* gSpritePool holds SPRITE_POOL_COUNT of these objects; a type of 0 is a free
 * slot, which is what FindSpriteByType(0) hands out. */
#define SPRITE_POOL_COUNT    32   /* sprites in gSpritePool */
#define SPRITE_POOL_SIZE     0x34 /* bytes of one pool sprite */

#define SPRITE_TYPE          0x00 /* s32 * non-null while the sprite is alive */
#define SPRITE_DATA_BASE     0x04 /* void *frame data, or an offset table into it */
#define SPRITE_LOOP_PTR      0x08 /* script cursor to restart from on command 0xFF */
#define SPRITE_SCRIPT        0x0C /* u16 *current script cursor */
#define SPRITE_FRAME         0x10 /* current frame data pointer */
#define SPRITE_LOOP_FRAME    0x14 /* loop frame pointer, 0 when the frame does not loop */
#define SPRITE_TIMER         0x18 /* s16 animation timer */
#define SPRITE_DELAY         0x1A /* s16 frames left before advancing the script */
#define SPRITE_SPEED         0x1C /* u16 script speed multiplier */
#define SPRITE_FRACTION      0x1E /* u16 fractional delay accumulator */
#define SPRITE_PALETTE       0x21 /* u8 palette index */
#define SPRITE_FLAGS         0x22 /* u8 animation flags */
#define SPRITE_COMMAND       0x24 /* u16 last script command */

#define SPRITE_FLAG_FRAME_SET    0x01 /* a frame has been selected */
#define SPRITE_FLAG_OFFSET_TABLE 0x02 /* SPRITE_DATA_BASE entries are byte offsets, not pointers */
#define SPRITE_FLAG_CHILD_POS    0x04 /* position is relative to the parent/engine origin */
#define SPRITE_FLAG_GEOMETRY_PARAM 0x08 /* handed to DrawSprite3DGeometry as its last argument */
#define SPRITE_FLAG_PALETTE_FIXED 0x10 /* use SetSpritePaletteBase instead of the object's palette */
#define SPRITE_FLAG_PALETTE_CYCLE 0x20 /* cycle the palette through gSpritePaletteCycle */
#define SPRITE_FLAG_DEFER        0x40 /* skip this frame's draw, then clear the bit */
#define SPRITE_PALETTE_CYCLE_LEN 22 /* entries in gSpritePaletteCycle */

/* Fields of a sprite object that is being drawn as an OBJ quad. */
#define SPRITE_PRIORITY  0x20 /* s8 priority the quad is submitted with */
#define SPRITE_TILE_BASE 0x23 /* u8 first tile of the sprite's quads (low five bits also enter the x word) */
#define SPRITE_OAM_ATTR2 0x28 /* u32 OAM attribute word 2: tile id in bits 0..9, priority/palette above */
#define SPRITE_PARTS     0x30 /* s32 extra quad parts of the sprite, 0 when it has none */

/* A sprite wrapper (main_02090E0C): a 3D sprite object that holds one child
 * sprite and draws it at the wrapper's position every frame, deleting itself
 * once the child has stopped.  The 3D draw scales x and y by the map cell size
 * and uses z as the child's graphics-block size; the 2D draw takes them as
 * screen pixels. */
#define SPRITE_WRAPPER_CHILD 0x58 /* void *child sprite the wrapper draws */
#define SPRITE_WRAPPER_X     0x5C /* s32 x of the child: 1/16-cell units, or pixels for the 2D draw */
#define SPRITE_WRAPPER_Y     0x60 /* s32 y of the child, same units as X */
#define SPRITE_WRAPPER_Z     0x64 /* s32 z/attribute word handed to the 3D draw */

/* Extra fields of the sprite that runs the map's tile-scatter transition
 * (main_0207A3B0): the motion points of the effect, one x, y, velocity x,
 * velocity y per map tile, and the frame counter that ends it. */
#define SPRITE_SCATTER_POINTS 0x54 /* s16 (*)[4]: x, y, velocity x, velocity y of each point */
#define SPRITE_SCATTER_COUNT  0x6C /* s16 points in use */
#define SPRITE_SCATTER_FRAME  0x6E /* s16 frames the effect has run */
#define SPRITE_SCATTER_MAX    204  /* points the effect's 0x660-byte array holds */
#define SPRITE_SCATTER_FRAMES 8    /* frames the effect runs before the sprite is deleted */

/* Script commands (the second u16 of a zero-duration entry). */
#define SPRITE_CMD_LOOP    0xFF
#define SPRITE_CMD_STOP    0x00
#define SPRITE_CMD_END     0x01

/* Return values of Sprite_UpdateAnimationScript. */
#define SPRITE_ANIM_STOPPED 0
#define SPRITE_ANIM_DONE    1
#define SPRITE_ANIM_RUNNING 0xFFFF

#endif
