/* The animated 2D/3D sprite object driven by the sprite script runner: it owns
 * a frame pointer, an animation script cursor and the delay between script
 * entries. */
#ifndef SPRITE_H
#define SPRITE_H

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

/* Script commands (the second u16 of a zero-duration entry). */
#define SPRITE_CMD_LOOP    0xFF
#define SPRITE_CMD_STOP    0x00
#define SPRITE_CMD_END     0x01

/* Return values of Sprite_UpdateAnimationScript. */
#define SPRITE_ANIM_STOPPED 0
#define SPRITE_ANIM_DONE    1
#define SPRITE_ANIM_RUNNING 0xFFFF

#endif
