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
#define MAP_CURRENT_OWNER   0x52a6 /* u16 the current player's owner bits (MAP_CURRENT_PLAYER << 5) */
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
#define MAP_VIEW_X          0x5148 /* s16 view scroll x, in 1/16-cell units */
#define MAP_VIEW_Y          0x514a /* s16 view scroll y, in 1/16-cell units */
#define MAP_VIEW_CELL_X     0x5150 /* s16 view scroll x, in whole cells (MAP_VIEW_X / 16) */
#define MAP_VIEW_CELL_Y     0x5152 /* s16 view scroll y, in whole cells (MAP_VIEW_Y / 16) */
#define MAP_VIEW_ZOOM       0x6ef8 /* s16 view zoom: 0 and 128 are the two levels */
#define MAP_TILESET         0x5157 /* u8 battle-setting/tileset index, selects the terrain tileset bank */
#define MAP_ID              0x5142 /* u16 map id, key into the per-map data records */
#define MAP_PLAYER_COUNT    0x5141 /* u8 number of players the map has (1..4) */
#define MAP_NAME            0x5120 /* char[] the map's display name */
#define MAP_CELL_TILE_ID    0xa10  /* u16 per cell: tile id, keyed through the current terrain tileset */
#define MAP_ROW_OFFSETS     0x3758 /* u16 per row: offset of the row in the cell arrays */
#define MAP_CELL_UNIT_ID    0x508  /* u8 per cell: id of the unit standing there, 0 if none */
#define MAP_CELL_TERRAIN    0x1420 /* u8 per cell: low 5 bits terrain kind, high 3 bits owner */
#define MAP_TILE_TERRAIN    0x6a60 /* u8 per tile id: terrain kind/owner byte the cell gets */
#define MAP_TERRAIN_KIND_MASK  0x1f /* terrain byte: terrain kind */
#define MAP_TERRAIN_OWNER_MASK 0xe0 /* terrain byte: owner bits (player << 5) */
#define MAP_UNIT_RECORDS    0x59a4 /* 256 unit records of 14 bytes */
#define MAP_UNIT_STRIDE     14     /* bytes per unit record */

/* Offsets within a unit record (see BattleMapUnit). */
#define MAP_UNIT_KIND       0x00 /* u8 kind in the low six bits, owner in the top two */
#define MAP_UNIT_X          0x01 /* u8 tile x */
#define MAP_UNIT_Y          0x02 /* u8 tile y */
#define MAP_UNIT_FLAGS      0x04 /* u16 per-unit flags */
#define MAP_UNIT_HEALTH     0x06 /* u16 health in the low seven bits */
#define MAP_UNIT_CARRIED    0x0C /* u8 first carried unit, 0 if none */
#define MAP_UNIT_NEXT_CARRIED 0x0D /* u8 next unit in the carry chain, 0 if none */
#define MAP_UNIT_TARGET     0x08 /* u16 packed AI move target: x in low six bits, y in bits 6..11 */
#define MAP_UNIT_TARGET_NONE 0x3F /* a target coordinate of 0x3f means "no target" */
#define MAP_UNIT_TARGET_X_MASK 0x003F /* low six bits of MAP_UNIT_TARGET: target x */
#define MAP_UNIT_TARGET_Y_MASK 0x0FC0 /* bits 6..11 of MAP_UNIT_TARGET: target y */
#define MAP_UNIT_TARGET_Y_NONE 0x0FC0 /* all six target-y bits set: no target */
#define MAP_UNIT_AI_STATE   0x0B /* u8 low nibble AI step; bit 5 held while a move target is assigned */
#define MAP_UNIT_AI_STATE_MASK 0x0F /* low nibble of MAP_UNIT_AI_STATE */
#define MAP_UNIT_KIND_MASK  0x3F /* low six bits of MAP_UNIT_KIND: the kind, the owner is above */

/* The two battle-participant scratch records, 0x20 bytes each: the side that
 * starts the fight at MAP_BATTLE_ATTACKER, its opponent at MAP_BATTLE_DEFENDER.
 * Each begins with the BattleMapUnit * it was loaded from. */
#define MAP_BATTLE_ATTACKER 0x6eb8
#define MAP_BATTLE_DEFENDER 0x6ed8
#define MAP_BATTLE_STRIDE   0x20
#define MAP_BATTLE_WINNER   0x6ed6 /* s16: side that wins the previewed battle, 0 = no preview */
#define MAP_GRID            0x52e8 /* s8 *rows[64]: per-cell grid value; <0 impassable, >110 holds a unit */
#define MAP_CELL_SCORE      0x2338 /* s8 per cell: influence/score layer (movement cost, danger range, ...) */
#define MAP_CELL_ORDER      0x1e30 /* s8 per cell: working order/overlay layer */
#define MAP_CELL_THREAT_DIRECT   0x2840 /* u8 per cell: threat from direct attackers */
#define MAP_CELL_THREAT_INDIRECT 0x2d48 /* u8 per cell: threat from indirect attackers */
#define MAP_MODE            0x52b4 /* s16 current battle-map input state */
#define MAP_CURSOR_OWNER    0x52a8 /* u16 owner mask the unit under the cursor must match */
#define MAP_CURSOR_TARGET_X 0x52c2 /* s16 tile the cursor is aimed at */
#define MAP_CURSOR_TARGET_Y 0x52c4

/* The battle map's per-player states: five 0x8c-byte records at map+0x67a4.
 * Player 0 is team A's base player and player 1 team B's; the remaining players
 * are allies sharing one of those armies (see MAP_TEAM_A_PLAYER / MAP_TEAM_B_PLAYER). */
#define MAP_PLAYER_STATES  0x67a4
#define MAP_PLAYER_STRIDE  0x8c
#define PLAYER_REC_SPRITE  0x6C /* u32 unit-sprite state: low byte army id, small bitfields select the sprite tables */
#define PLAYER_REC_CTRL    0x1E /* u8 PLAYER_CONTROL_*, within a record */
#define PLAYER_REC_SIDE    0x1F /* u8 SIDE_*, within a record */
#define PLAYER_REC_ARMY    0x26 /* u8 army (nation) id, within a record */
#define PLAYER_REC_ARMY_INDEX 0x1D /* u8 1-based army index that picks its colour */
#define PLAYER_REC_ARMY_STATE 0x27 /* u8 per-player army state shown by the army info window */
#define PLAYER_REC_AI_MODE    0x2A /* u8 AI behaviour mode (0..3) */
#define PLAYER_CONTROL_OFF (MAP_PLAYER_STATES + 0x1E) /* u8 PLAYER_CONTROL_* */
#define PLAYER_SIDE_OFF    (MAP_PLAYER_STATES + 0x1F) /* u8 SIDE_* */
#define PLAYER_ARMY_OFF    (MAP_PLAYER_STATES + 0x26) /* u8 army (nation) id */
#define PLAYER_ARMY_INDEX_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_INDEX) /* u8 */
#define PLAYER_ARMY_STATE_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_STATE) /* u8 */
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

/* Attack class of a unit kind, from its maximum attack range (GetUnitAttackClass). */
enum {
    UNIT_ATTACK_DIRECT   = 0, /* range 1: attacks from an adjacent tile */
    UNIT_ATTACK_INDIRECT = 1, /* range above 1: needs a free firing tile */
    UNIT_ATTACK_NONE     = 2  /* cannot attack */
};

/* The decoded map definition block (gMapData) loaded for the current map. */
#define MAPDATA_WIDTH   0x00 /* u8 map width in cells */
#define MAPDATA_HEIGHT  0x01 /* u8 map height in cells */
#define MAPDATA_TILES   0x02 /* u16 per cell: tile id into MAP_TILE_TERRAIN */

/* Map ids in this range are campaign maps with a full 0x6f8-byte record. */
#define MAP_ID_CAMPAIGN_FIRST 0xE1
#define MAP_ID_CAMPAIGN_END   0x1A9 /* one past the last campaign map */

#endif
