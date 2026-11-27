/* Touchable sprite slots: the 0x3C-byte records in gSpriteSlots (85 of them)
 * that the UI layer hit-tests and clicks. */
#ifndef SPRITE_SLOT_H
#define SPRITE_SLOT_H

#define SPRITE_SLOT_ID       0x00 /* u8 id */
#define SPRITE_SLOT_VISIBLE  0x01 /* u8 slot is active */
#define SPRITE_SLOT_STATE    0x03 /* u8 SPRITE_SLOT_STATE_* */
#define SPRITE_SLOT_ANIM     0x04 /* u8 SPRITE_SLOT_ANIM_* */
#define SPRITE_SLOT_OWNER    0x10 /* void *object the slot's callbacks work on */
#define SPRITE_SLOT_X        0x14 /* s16 left edge */
#define SPRITE_SLOT_Y        0x16 /* s16 top edge */
#define SPRITE_SLOT_W        0x18 /* s16 width */
#define SPRITE_SLOT_H        0x1a /* s16 height */
#define SPRITE_SLOT_FLAGS    0x1c /* u16 SPRITE_SLOT_FLAG_* */
#define SPRITE_SLOT_TILE     0x20 /* u16 OBJ tile index (low 10 bits pick the tile in the screen's bank) */
#define SPRITE_SLOT_PRIORITY 0x22 /* u16 OBJ priority bits 0..1 */
#define SPRITE_SLOT_CLICK_CB 0x2c /* void (*)(void *) */
#define SPRITE_SLOT_CANCEL_CB 0x30 /* void (*)(void *): run on cancel (B) while the slot is focused */
#define SPRITE_SLOT_UPDATE_CB 0x24 /* void (*)(void *): run for the slot every frame */
#define SPRITE_SLOT_KEY_CB   0x28 /* void (*)(void *): run on key input while the slot is focused and ready */
#define SPRITE_SLOT_FOCUS_CB 0x34 /* void (*)(void *): run when the slot takes keyboard focus */
#define SPRITE_SLOT_STRIDE   0x3c
#define SPRITE_SLOT_COUNT    85   /* slots in the gSpriteSlots pool */

/* Fields of the sprite-slot manager (gSpriteSlotManager). */
#define SPRITE_SLOT_MGR_FOCUS_ID  0x08 /* u8 id used to find the focused slot */
#define SPRITE_SLOT_MGR_FOCUS     0x0C /* void *slot that currently has focus, 0 when none */
#define SPRITE_SLOT_MGR_FRAME_TL_X 0x10 /* s16 focus frame top-left x */
#define SPRITE_SLOT_MGR_FRAME_TL_Y 0x12 /* s16 focus frame top-left y */
#define SPRITE_SLOT_MGR_FRAME_TR_X 0x14 /* s16 focus frame top-right x */
#define SPRITE_SLOT_MGR_FRAME_TR_Y 0x16 /* s16 focus frame top-right y */
#define SPRITE_SLOT_MGR_FRAME_BL_X 0x18 /* s16 focus frame bottom-left x */
#define SPRITE_SLOT_MGR_FRAME_BL_Y 0x1A /* s16 focus frame bottom-left y */
#define SPRITE_SLOT_MGR_FRAME_BR_X 0x1C /* s16 focus frame bottom-right x */
#define SPRITE_SLOT_MGR_FRAME_BR_Y 0x1E /* s16 focus frame bottom-right y */
#define SPRITE_SLOT_MGR_FRAME_OFF_X 0x20 /* s16 x drawn from the top-left corner */
#define SPRITE_SLOT_MGR_FRAME_OFF_Y 0x22 /* s16 y drawn from the top-left corner */
#define SPRITE_SLOT_MGR_SCREEN    0x24 /* u8 screen the active slots belong to (0 main, 1 sub, 3 either) */
#define SPRITE_SLOT_MGR_HAS_FOCUS 0x25 /* u8 nonzero while a slot took focus */
#define SPRITE_SLOT_MGR_UPDATE_PAUSE_DEPTH 0x26 /* u8 nesting count for an update pause */
#define SPRITE_SLOT_MGR_DRAW_PAUSE_DEPTH   0x27 /* u8 nesting count that pauses both drawing and updates */

/* SPRITE_SLOT_FLAGS bits. */
#define SPRITE_SLOT_FLAG_ENABLED  0x0001 /* enabled; may take keyboard focus */
#define SPRITE_SLOT_FLAG_DISABLED 0x0400 /* touch does not click it */
#define SPRITE_SLOT_FLAG_ALWAYS_HIT 0x1000 /* the hit test always succeeds */

/* SPRITE_SLOT_STATE values. */
enum {
    SPRITE_SLOT_STATE_IDLE     = 0, /* nothing touching */
    SPRITE_SLOT_STATE_PRESSED  = 1, /* touch began on the slot */
    SPRITE_SLOT_STATE_DRAGGING = 2  /* held too long; a release no longer clicks */
};

/* SPRITE_SLOT_ANIM values: the slot's intro/outro animation state machine
 * (AnimateSpriteSlot in main_020B25B8).  Only READY takes touch and key input. */
enum {
    SPRITE_SLOT_ANIM_START   = 0, /* before the intro starts */
    SPRITE_SLOT_ANIM_INTRO   = 1, /* intro animation running */
    SPRITE_SLOT_ANIM_READY   = 2, /* intro done: the slot is interactive */
    SPRITE_SLOT_ANIM_CLOSING = 3, /* outro requested */
    SPRITE_SLOT_ANIM_OUTRO   = 4, /* outro animation running */
    SPRITE_SLOT_ANIM_GONE    = 5  /* outro done; the slot is deleted */
};

/* The definition a slot is created from (AddSpriteSlot's `desc`): the slot is
 * placed at the caller's (x, y) plus dx/dy and gets the definition's size, flags,
 * tile and callbacks, which land in the slot's own fields at 0x24..0x38 (the
 * per-frame callback and SPRITE_SLOT_CLICK_CB among them). */
#define SPRITE_SLOT_DEF_DX        0x00 /* s16 x offset on top of the caller's x */
#define SPRITE_SLOT_DEF_DY        0x02 /* s16 y offset */
#define SPRITE_SLOT_DEF_W         0x04 /* s16 width */
#define SPRITE_SLOT_DEF_H         0x06 /* s16 height */
#define SPRITE_SLOT_DEF_FLAGS     0x08 /* u16 SPRITE_SLOT_FLAG_* */
#define SPRITE_SLOT_DEF_UNK0A     0x0A /* u16 */
#define SPRITE_SLOT_DEF_TILE      0x0C /* u16 OBJ tile index */
#define SPRITE_SLOT_DEF_PRIORITY  0x0E /* u16 */
#define SPRITE_SLOT_DEF_UPDATE_CB 0x10 /* void * -> slot +0x24, run every frame */
#define SPRITE_SLOT_DEF_KEY_CB    0x14 /* void * -> slot +0x28, run on key input */
#define SPRITE_SLOT_DEF_CLICK_CB  0x18 /* void * -> slot +0x2C */
#define SPRITE_SLOT_DEF_CANCEL_CB 0x1C /* void * -> slot +0x30 */
#define SPRITE_SLOT_DEF_FOCUS_CB  0x20 /* void * -> slot +0x34 */
#define SPRITE_SLOT_DEF_UNK24     0x24 /* void * -> slot +0x38 */
#define SPRITE_SLOT_DEF_SIZE      0x28

#endif
