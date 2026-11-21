/* The ov000 unit-move controller: it walks a map unit along a byte-stream path,
 * one command per step (0..3 = walk left/right/down/up, 9 = set speed, 10 =
 * attack, 4/-1 = end).  Only the fields the start/update code touches are named. */
#ifndef OV000_UNIT_MOVE_H
#define OV000_UNIT_MOVE_H

#define UNIT_MOVE_SLOT_COUNT  3    /* simultaneous unit-move controllers (the map's slot pool) */
#define UNIT_MOVE_UNIT_FLAGS  0x0006 /* MAP_UNIT_FLAGS bits owned by an attached controller; 0x0004 is UNIT_FLAG_MOVING */
#define UNIT_MOVE_SPRITE_LAYER 9   /* 3D sprite layer the moving unit's object is created in */
#define UNIT_MOVE_SPRITE      0x34 /* s32 * unit sprite object */
#define UNIT_MOVE_SPRITE2     0x38 /* s32 * second unit sprite object */
#define UNIT_MOVE_UNIT        0x3c /* u8 * map unit record being moved */
#define UNIT_MOVE_COMMAND     0x40 /* u8 read position in the command stream */
#define UNIT_MOVE_STATE       0x41 /* u8 state, index into the handler table */
#define UNIT_MOVE_KIND        0x42 /* u8 unit kind */
#define UNIT_MOVE_OWNER       0x43 /* u8 owner (player) of the unit */
#define UNIT_MOVE_DIRECTION   0x44 /* s8 direction the unit faces */
#define UNIT_MOVE_SLOT        0x45 /* u8 pool slot of the controller */
#define UNIT_MOVE_ACTIVE      0x46 /* u8 nonzero while the move runs */
#define UNIT_MOVE_PALETTE_MODE 0x47 /* u8 cached sprite palette mode: 0x10 normal, 0x18 zoomed */
#define UNIT_MOVE_SPRITE_ATTR  0x871 /* attribute word of the moving unit's 3D sprite */
/* 1/16-cell offsets added to the unit's position before it is scaled by MAP_SPRITE_CELL_SIZE. */
#define UNIT_MOVE_SPRITE_OFFSET_X 8
#define UNIT_MOVE_SPRITE_OFFSET_Y 16
#define UNIT_MOVE_GFX         0x50 /* s32 unit tile-graphics buffer (freed with HeapFreeBlock) */
#define UNIT_MOVE_ANIM        0x54 /* s32 unit sprite animation data buffer */
#define UNIT_MOVE_PHASE       0x48 /* u16 progress through the current step */
#define UNIT_MOVE_SPEED       0x4a /* s16 movement speed */
#define UNIT_MOVE_X           0x4c /* s16 x in 1/16-tile units */
#define UNIT_MOVE_Y           0x4e /* s16 y in 1/16-tile units */
#define UNIT_MOVE_COMMANDS    0x58 /* s8[] copy of the movement command stream */

/* Values of UNIT_MOVE_STATE: the controller's per-frame state machine.  Each
 * state names its own entry in gUnitMoveStateHandlers. */
enum {
    UNIT_MOVE_STATE_NONE        = 0, /* detached: no per-frame work */
    UNIT_MOVE_STATE_IDLE        = 1, /* attached, not yet stepping */
    UNIT_MOVE_STATE_WALK        = 2, /* stepping toward the next tile */
    UNIT_MOVE_STATE_HOLD        = 3, /* paused for the step timer */
    UNIT_MOVE_STATE_WAIT_SCROLL = 4, /* resumes walking when the view stops scrolling */
    UNIT_MOVE_STATE_WAIT_ATTACK = 5  /* resumes walking when the attack effect ends */
};

/* Footstep sound ids GetTerrainStepSound returns; the low 5 bits of the cell's
 * MAP_CELL_TERRAIN select them, and plain ground also depends on MAP_TILESET. */
#define STEP_SOUND_PLAIN       0x40 /* plain ground, properties, tileset 0 */
#define STEP_SOUND_PLAIN_1     0x41 /* plain ground on tileset 1 */
#define STEP_SOUND_WOODS       0x42 /* terrain kind 4 */
#define STEP_SOUND_HARD        0x43 /* terrain kinds 7, 8 and 12 */
#define STEP_SOUND_WATER       0x44 /* terrain kind 2 */
#define STEP_SOUND_PLAIN_3     0x45 /* plain ground on tileset 3 */
#define STEP_SOUND_SHOAL       0x46 /* terrain kind 9 and plain ground on tileset 2 */
#define STEP_SOUND_ROCK        0x3f /* terrain kind 3 */

#endif
