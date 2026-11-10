/* The battle map (gCurrentMap) and its unit records.
 *
 * The map is a byte array; the offsets below are the ones the unit and cursor code uses.
 * The unit records start at MAP_UNIT_RECORDS and are 14 bytes each; a record is picked by
 * the unit id byte, whose top two bits hold the owner (player) and whose low six bits the
 * slot of the unit.
 */
#ifndef BATTLE_MAP_H
#define BATTLE_MAP_H

/* A unit record of the battle map. */
typedef struct BattleMapUnit {
    u8 kind;         /* +0x00 kind of the unit */
    u8 x;            /* +0x01 tile x */
    u8 y;            /* +0x02 tile y */
    u8 unk3;         /* +0x03 */
    u16 flags;       /* +0x04 */
    u16 health:7;    /* +0x06 */
    u16 rest:9;      /* +0x06 the facing direction is in its top five bits */
    u8 unk8[4];      /* +0x08 */
    u8 firstCarried; /* +0x0C id of the first unit this unit carries */
    u8 nextCarried;  /* +0x0D id of the next unit in the carry chain */
} BattleMapUnit;

/* Fields of the battle map. */
#define MAP_CURRENT_PLAYER  0x52a4 /* u16 the player the view belongs to */
#define MAP_ACTIVE_PLAYER   0x52b6 /* u16 player whose units are being processed, saved and restored around influence builds */
#define MAP_CURSOR_UNIT     0x52d0 /* BattleMapUnit * of the unit under the cursor */
#define MAP_CURSOR_UNIT_ID  0x52d4 /* u8 id of the unit under the cursor */
#define MAP_CURSOR_DIR      0x52d5 /* u8 direction the cursor points at */
#define MAP_CURSOR_CARRIER  0x52d6 /* u8 id of the transport carrying that unit, 0 if none */
#define MAP_CURSOR_OLD_X    0x52d8 /* s16 the cursor position before the last move */
#define MAP_CURSOR_OLD_Y    0x52da
#define MAP_CURSOR_X        0x52dc /* s16 tile x of the cursor */
#define MAP_CURSOR_Y        0x52de /* s16 tile y of the cursor */
#define MAP_PATH_X          0x52e0 /* s16 tile x the movement path starts at */
#define MAP_PATH_Y          0x52e2 /* s16 tile y the movement path starts at */
#define MAP_CURSOR_PATH     0x5388 /* the path from the unit to the cursor */
#define MAP_CELL_BITMAP     0x5201 /* bitmap of the occupied cells */
#define MAP_WIDTH           0x5144 /* u16 map width in cells */
#define MAP_HEIGHT          0x5146 /* u16 map height in cells */
#define MAP_CELL_TILE_ID    0xa10  /* u16 per cell: tile id, keyed through the current terrain tileset */
#define MAP_ROW_OFFSETS     0x3758 /* u16 per row: offset of the row in the cell arrays */
#define MAP_UNIT_RECORDS    0x59a4 /* 256 unit records of 14 bytes */

#endif
