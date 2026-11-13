/* The ov000 unit-move controller: it walks a map unit along a byte-stream path,
 * one command per step (0..3 = walk left/right/down/up, 9 = set speed, 10 =
 * attack, 4/-1 = end).  Only the fields the start/update code touches are named. */
#ifndef OV000_UNIT_MOVE_H
#define OV000_UNIT_MOVE_H

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
#define UNIT_MOVE_PHASE       0x48 /* u16 progress through the current step */
#define UNIT_MOVE_SPEED       0x4a /* s16 movement speed */
#define UNIT_MOVE_X           0x4c /* s16 x in 1/16-tile units */
#define UNIT_MOVE_Y           0x4e /* s16 y in 1/16-tile units */
#define UNIT_MOVE_COMMANDS    0x58 /* s8[] copy of the movement command stream */

#endif
