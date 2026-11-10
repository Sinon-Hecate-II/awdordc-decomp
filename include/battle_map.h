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

typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height;u8 pad3[0x1a0];s8 *grid[64]; } Map16E8;

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
#define MAP_GRID            0x52e8 /* s8 *rows[64]: per-cell grid value; <0 impassable, >110 holds a unit */
#define MAP_MODE            0x52b4 /* s16 current battle-map input state */
#define MAP_CURSOR_OWNER    0x52a8 /* u16 owner mask the unit under the cursor must match */
#define MAP_CURSOR_TARGET_X 0x52c2 /* s16 tile the cursor is aimed at */
#define MAP_CURSOR_TARGET_Y 0x52c4

/* The battle map's per-player states: five 0x8c-byte records at map+0x67a4.
 * Player 0 is team A's base player and player 1 team B's; the remaining players
 * are allies sharing one of those armies (see MAP_TEAM_A_PLAYER / MAP_TEAM_B_PLAYER). */
#define MAP_PLAYER_STATES  0x67a4
#define MAP_PLAYER_STRIDE  0x8c
#define PLAYER_REC_CTRL    0x1E /* u8 PLAYER_CONTROL_*, within a record */
#define PLAYER_REC_SIDE    0x1F /* u8 SIDE_*, within a record */
#define PLAYER_REC_ARMY    0x26 /* u8 army (nation) id, within a record */
#define PLAYER_CONTROL_OFF (MAP_PLAYER_STATES + 0x1E) /* u8 PLAYER_CONTROL_* */
#define PLAYER_SIDE_OFF    (MAP_PLAYER_STATES + 0x1F) /* u8 SIDE_* */
#define PLAYER_ARMY_OFF    (MAP_PLAYER_STATES + 0x26) /* u8 army (nation) id */
#define MAP_TEAM_A_PLAYER  0x52b8 /* s16 id of the player team A's army belongs to */
#define MAP_TEAM_B_PLAYER  0x52ba /* s16 id of the player team B's army belongs to */

/* Player control kind (PLAYER_CONTROL_OFF). */
enum {
    PLAYER_CONTROL_NONE  = 0, /* no player here */
    PLAYER_CONTROL_HUMAN = 1,
    PLAYER_CONTROL_CPU   = 2
};

/* Player side (PLAYER_SIDE_OFF): which team the player fights for. */
enum {
    SIDE_NONE    = 0, /* no army (not fighting) */
    SIDE_TEAM_A  = 1, /* team A */
    SIDE_TEAM_B  = 2, /* team B */
    SIDE_HUMAN   = 3  /* team A with a human on it */
};

#endif
