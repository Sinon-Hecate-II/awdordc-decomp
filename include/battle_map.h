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

/* The head of a unit record read through bitfields: the kind is the low six bits
 * of the first byte and the owner the top two, followed by the tile position.
 * Sized like BattleMapUnit so it can index the record array directly. */
typedef struct BattleMapUnitHead {
    u8 kind:6;    /* +0x00 unit kind */
    u8 owner:2;   /* +0x00 owner (player) */
    u8 x;         /* +0x01 tile x */
    u8 y;         /* +0x02 tile y */
    u8 rest[11];  /* +0x03 rest of the 14-byte record */
} BattleMapUnitHead;

/* The stat block built for a battle-map unit: seven signed stat values at
 * +0x00..+0x06 and two signed word stats at +0x08 and +0x0A.  The unit-info
 * window reads the values through the func_020a26xx accessors. */
typedef struct UnitStatBlock {
    s8  stat[7]; /* +0x00 */
    s8  pad;     /* +0x07 */
    s16 value8;  /* +0x08 */
    s16 valueA;  /* +0x0A */
} UnitStatBlock;

/* One commander's bonus record in the commander bonus table, 0x48 bytes: the
 * stat bonuses every unit of the commander gets, then per-unit-kind
 * availability flags.  The table is indexed by commander id. */
typedef struct CommanderBonus {
    UnitStatBlock base;      /* +0x00 stat bonuses applied to the commander's units */
    u8  unk0C[5];            /* +0x0C */
    s8  canDeploy[27];       /* +0x11 nonzero when the commander may deploy that unit kind */
    s8  canUse[27];          /* +0x2C nonzero when the commander may use that unit kind */
    u8  pad47;               /* +0x47 */
} CommanderBonus;

typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height;u8 pad3[0x1a0];s8 *grid[64]; } Map16E8;

/* One side of a battle, copied from its BattleMapUnit at MAP_BATTLE_ATTACKER or
 * MAP_BATTLE_DEFENDER.  A strike fills in attackPower, weaponDamage and weapon,
 * which the damage helpers then apply. */
typedef struct BattleUnit {
    BattleMapUnit *unit;   /* +0x00 map unit this side was loaded from */
    s16 terrainDefense;    /* +0x04 terrain defense stars */
    s16 attackBase;        /* +0x06 base attack before health scaling */
    s16 maxHealth;         /* +0x08 HP from the map unit */
    s16 maxAmmo;           /* +0x0A ammo from the map unit */
    s16 moveRange;         /* +0x0C */
    s16 health;            /* +0x0E current HP */
    s16 ammo;              /* +0x10 current ammo, spent by the primary weapon */
    s16 unk12;             /* +0x12 */
    s16 damage;            /* +0x14 damage applied to this side this round */
    s16 attackPower;       /* +0x16 attack power for this strike */
    s16 weaponDamage;      /* +0x18 damage the chosen weapon deals */
    s16 unk1A;             /* +0x1A */
    s16 unk1C;             /* +0x1C */
    s16 weapon;            /* +0x1E 1 = primary weapon, 2 = secondary weapon */
} BattleUnit;

/* Weapon choice stored in BattleUnit.weapon. */
enum {
    BATTLE_WEAPON_NONE      = 0,
    BATTLE_WEAPON_PRIMARY   = 1,
    BATTLE_WEAPON_SECONDARY = 2
};

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
#define MAP_VIEW_WIDTH_CELLS  0x6f04 /* u8 width of the visible view in map cells */
#define MAP_VIEW_HEIGHT_CELLS 0x6f05 /* u8 height of the visible view in map cells */
#define MAP_VIEW_MARGIN       16   /* 1/16-cell units in one cell: border kept around a followed point */
#define MAP_VIEW_NO_SCROLL    10000 /* s16 sentinel: this axis does not need to scroll */
#define MAP_VIEW_CELL_X     0x5150 /* s16 view scroll x, in whole cells (MAP_VIEW_X / 16) */
#define MAP_VIEW_CELL_Y     0x5152 /* s16 view scroll y, in whole cells (MAP_VIEW_Y / 16) */
#define MAP_VIEW_ZOOM       0x6ef8 /* s16 view zoom: 0 and 128 are the two levels */
#define MAP_TILESET         0x5157 /* u8 battle-setting/tileset index, selects the terrain tileset bank */
#define MAP_FOG             0x5156 /* u8 nonzero when fog of war hides distant units */
#define MAP_WEATHER         0x5158 /* u8 current weather (0 clear, 1 rain, 2 snow, 3 sandstorm) */
#define MAP_WEATHER_MODE    0x5159 /* u8 nonzero when the weather may change by itself */
#define MAP_WEATHER_START   0x515a /* u8 weather when the battle starts */
#define MAP_WEATHER_RESET   0x515b /* u8 weather the battle returns to after a change */
#define MAP_WEATHER_DELAY   0x515c /* u8[4] per-player turns left before the weather may change again */

/* The map's effect state, the block gCurrentMap[3] points to.  ApplyWeatherEffects
 * (main_020A38F4) fills it when the weather changes; the particle update/draw
 * code then scrolls and renders it every frame. */
#define MAP_EFFECT_PARTICLES       0x000 /* 32 WeatherParticle records */
#define MAP_EFFECT_PARTICLE_COUNT  32
#define MAP_EFFECT_PARTICLE_STRIDE 12
#define MAP_EFFECT_DRIFTERS        0x180 /* 4 drifting records, e.g. cloud shadows */
#define MAP_EFFECT_DRIFTER_COUNT   4
#define MAP_EFFECT_DRIFTER_STRIDE  20
#define MAP_EFFECT_PARTICLE_X      0x00 /* u16 x position, 8.8 fixed point */
#define MAP_EFFECT_PARTICLE_Y      0x02 /* u16 y position, 8.8 fixed point */
#define MAP_EFFECT_PARTICLE_DX     0x04 /* u16 x velocity per frame */
#define MAP_EFFECT_PARTICLE_DY     0x06 /* u16 y velocity per frame */
#define MAP_EFFECT_PARTICLE_SPRITE 0x08 /* u16 sprite id */
#define MAP_EFFECT_DRIFTER_X       0x00 /* s32 x position, 8.8 fixed point */
#define MAP_EFFECT_DRIFTER_Y       0x04 /* s32 y position, 8.8 fixed point */
#define MAP_EFFECT_DRIFTER_DX      0x08 /* s32 x velocity per frame */
#define MAP_EFFECT_DRIFTER_DY      0x0C /* s32 y velocity per frame */
#define MAP_EFFECT_DRIFTER_TIMER   0x10 /* u16 countdown, randomised when set up */
#define MAP_TURN            0x52a2 /* u16 battle turn number, 1 on the first turn */
#define MAP_ID              0x5142 /* u16 map id, key into the per-map data records */
#define MAP_PLAYER_COUNT    0x5141 /* u8 number of players the map has (1..4) */
#define MAP_NAME            0x5120 /* char[] the map's display name */
#define MAP_CELL_TILE_ID    0xa10  /* u16 per cell: tile id, keyed through the current terrain tileset */
#define MAP_ROW_OFFSETS     0x3758 /* u16 per row: offset of the row in the cell arrays */
#define MAP_CELL_UNIT_ID    0x508  /* u8 per cell: id of the unit standing there, 0 if none */
#define MAP_CELL_TERRAIN    0x1420 /* u8 per cell: low 5 bits terrain kind, high 3 bits owner */
#define MAP_CELL_PROPERTY_INDEX 0x1928 /* s8 per cell: index of the cell's record in MAP_PROPERTY_CELLS */
#define MAP_TILE_TERRAIN    0x6a60 /* u8 per tile id: terrain kind/owner byte the cell gets */
#define MAP_TERRAIN_KIND_MASK  0x1f /* terrain byte: terrain kind */
#define MAP_TERRAIN_OWNER_MASK 0xe0 /* terrain byte: owner bits (player << 5) */

/* Terrain kinds the map code names directly; the tileset's MAP_TILE_TERRAIN
 * table maps each tile id to one of these packed values. */
#define MAP_TERRAIN_PLAIN      1    /* plain ground */
#define MAP_TERRAIN_WASTELAND  8    /* barren ground a destroyed owned property leaves */
#define MAP_TERRAIN_IMPACT     0x1c /* destructible impact feature; its cell becomes a crater */

/* Remaining HP of destructible terrain (low seven bits, 0 where there is none). */
#define MAP_CELL_TERRAIN_HP    0x539c /* u8 per cell */

/* Tile ids the impact blast writes into the current tileset bank. */
#define MAP_TILE_WASTELAND     3
#define MAP_TILE_BLAST_GROUND  4
#define MAP_TILE_BLAST_CRATER  5

/* Reach of the impact blast: the movement range of a pseudo unit kind, searched
 * with an effectively unlimited movement-cost budget. */
#define IMPACT_BLAST_MOVE_KIND   0x1d
#define IMPACT_BLAST_MOVE_BUDGET 110
#define MAP_UNIT_RECORDS    0x59a4 /* 256 unit records of 14 bytes */
#define MAP_UNIT_STRIDE     14     /* bytes per unit record */
#define MAP_UNIT_COUNT      256    /* unit records in MAP_UNIT_RECORDS */
#define MAP_UNIT_GROUP_SIZE 64     /* records per player slot; a record's owner (player << 6) picks its group */
#define MAP_UNIT_GROUP_SCAN 0x33   /* exclusive end of the unit ids scanned within a group: base+1 .. base+0x33 */

/* The map's property-cell list, rebuilt by func_020cf2c8: one 6-byte record per
 * property (or kind 0x18 special) cell, ended by a 0xff terrain kind. */
#define MAP_PROPERTY_CELLS  0x6c60 /* first record */
#define MAP_PROPERTY_STRIDE 6      /* bytes per record */
#define MAP_PROPERTY_KIND   0x00   /* u8 terrain kind of the cell */
#define MAP_PROPERTY_X      0x01   /* u8 tile x */
#define MAP_PROPERTY_Y      0x02   /* u8 tile y */
#define MAP_PROPERTY_COUNT  0x03   /* u8 times the cell was used */
#define MAP_PROPERTY_END    0xff   /* terrain kind that ends the list */

/* Packed per-map settings, saved with a slot and copied into the battle map and
 * gMapConfig by ApplyMapSettings. */
typedef struct MapSettings {
    u8  pad00[8];
    u32 rules;   /* +0x08: packed map id and rule bits, MAP_SETTINGS_* */
    u32 values;  /* +0x0C: packed value limits */
} MapSettings;

#define MAP_SETTINGS_MAP_ID        0x00000FFE /* bits 1..11: map id */
#define MAP_SETTINGS_FOG           0x00001000 /* bit 12: fog of war */
#define MAP_SETTINGS_WEATHER       0x0000E000 /* bits 13..15: starting weather */
#define MAP_SETTINGS_WEATHER_MODE  0x00010000 /* bit 16: weather may change by itself */
#define MAP_SETTINGS_TILESET       0x001E0000 /* bits 17..20: battle-setting/tileset index */
#define MAP_SETTINGS_SETTING       0x0FE00000 /* bits 21..27: additional battle setting */
#define MAP_SETTINGS_FLAGS         0x70000000 /* bits 28..30: config flags */

/* Bit ranges of MapSettings.values (the packed value limits). */
#define MAP_SETTINGS_VALUE_LOW     0x0001FFFF /* bits 0..16: first limit, signed 17-bit */
#define MAP_SETTINGS_VALUE_HIGH    0x7FFE0000 /* bits 17..30: second limit, 14-bit */
#define MAP_SETTINGS_VALUE_FLAG    0x80000000 /* bit 31: limit flag */

/* Offsets within a unit record (see BattleMapUnit). */
#define MAP_UNIT_KIND       0x00 /* u8 kind in the low six bits, owner in the top two */
#define MAP_UNIT_X          0x01 /* u8 tile x */
#define MAP_UNIT_Y          0x02 /* u8 tile y */
#define MAP_UNIT_FLAGS      0x04 /* u16 per-unit flags */
#define MAP_UNIT_HEALTH     0x06 /* u16 health in the low seven bits */
#define MAP_UNIT_AMMO       0x06 /* u16: ammo in bits 7..10 (health in bits 0..6) */
#define MAP_UNIT_FACING     0x06 /* u16: facing direction in bits 11..15, nonzero once the unit is placed */
#define MAP_UNIT_FUEL       0x0A /* u8 fuel in the low seven bits */
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

/* One entry of the battle map's target list: the unit on a cell (0 when the
 * cell holds none), a value that is the damage to deal when the cell holds a
 * unit or the visibility value when it does not, and the cell's position.  The
 * cursor code (main_0209F990.c) builds the list; GetTargetPosition walks it. */
typedef struct MapTargetEntry {
    u16 id;    /* +0x00 unit id on the cell, 0 when there is none */
    u16 value; /* +0x02 damage to deal, or the cell's visibility value */
    s16 x;     /* +0x04 tile x */
    s16 y;     /* +0x06 tile y */
} MapTargetEntry;

/* Per-unit flag bits in MAP_UNIT_FLAGS. */
#define UNIT_FLAG_REPAIR     0x0100 /* unit is flagged for repair/resupply (drives a status icon) */
#define UNIT_FLAG_REPAIR_TMP 0x8000 /* scratch bit marking a repair neighbour during the repair pass */

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
#define MAP_STATE           0x52b0 /* u16 battle-map state-machine step the per-frame dispatcher switches on */
#define MAP_RETURN_STATE    0x52b2 /* u16 state to go back to after a temporary submode (0 = none) */
#define MAP_CURSOR_OWNER    0x52a8 /* u16 owner mask the unit under the cursor must match */
#define MAP_CURSOR_TARGET_X 0x52c2 /* s16 tile the cursor is aimed at */
#define MAP_CURSOR_TARGET_Y 0x52c4
#define MAP_TOUCH_TILE_X    0x52ca /* s16 tile the current stylus press started on, 0xff when none */
#define MAP_TOUCH_TILE_Y    0x52cc
#define MAP_TILE_SUBPIXEL   0x300  /* map-position units per tile, from ScreenToMapPosition */
#define MAP_PREVIEW_UNIT_TILE_BASE 19 /* gTileGfxRowOffset index of the first unit-marker tile row */

/* The battle map's per-player states: five 0x8c-byte records at map+0x67a4.
 * Player 0 is team A's base player and player 1 team B's; the remaining players
 * are allies sharing one of those armies (see MAP_TEAM_A_PLAYER / MAP_TEAM_B_PLAYER). */
#define MAP_PLAYER_STATES  0x67a4
#define MAP_PLAYER_STRIDE  0x8c
#define PLAYER_REC_FUNDS   0x00 /* s32 funds: builds cost ten times the unit's price */
#define PLAYER_FUNDS_OFF (MAP_PLAYER_STATES + PLAYER_REC_FUNDS) /* s32 funds of a player record */
#define PLAYER_REC_SPRITE  0x6C /* u32 unit-sprite state: low byte army id, small bitfields select the sprite tables */
#define PLAYER_REC_CTRL    0x1E /* u8 PLAYER_CONTROL_*, within a record */
#define PLAYER_REC_SIDE    0x1F /* u8 SIDE_*, within a record */
#define PLAYER_REC_ARMY    0x26 /* u8 army (nation) id, within a record */
#define PLAYER_REC_ARMY_INDEX 0x1D /* u8 1-based army index that picks its colour */
#define PLAYER_REC_ARMY_STATE 0x27 /* u8 per-player army state shown by the army info window */
#define PLAYER_REC_TURN_TIME 0x88 /* u32 elapsed turn time in frames (0 when untimed) */
#define PLAYER_REC_AI_MODE    0x2A /* u8 AI behaviour mode (0..3) */
#define PLAYER_REC_HQ_X       0x2B /* u8 HQ tile x in the low seven bits; bit 7 set when the player has no HQ */
#define PLAYER_REC_HQ_Y       0x2C /* u8 HQ tile y in the low seven bits */
/* Battle-rating accumulators of a player record, updated as fights resolve. */
#define PLAYER_REC_DAMAGE_DEALT  0x74 /* s32 total damage this player's attacks dealt */
#define PLAYER_REC_ATTACK_COUNT  0x78 /* s32 number of attacks this player made */
#define PLAYER_REC_KILL_DAMAGE   0x7C /* s32 damage of attacks that left the target at 0 HP */
#define PLAYER_REC_BATTLE_COUNT  0x80 /* s32 number of fights this player took part in */
#define PLAYER_DAMAGE_DEALT_OFF (MAP_PLAYER_STATES + PLAYER_REC_DAMAGE_DEALT)
#define PLAYER_ATTACK_COUNT_OFF (MAP_PLAYER_STATES + PLAYER_REC_ATTACK_COUNT)
#define PLAYER_BATTLE_COUNT_OFF (MAP_PLAYER_STATES + PLAYER_REC_BATTLE_COUNT)
#define PLAYER_CONTROL_OFF (MAP_PLAYER_STATES + 0x1E) /* u8 PLAYER_CONTROL_* */
#define PLAYER_SIDE_OFF    (MAP_PLAYER_STATES + 0x1F) /* u8 SIDE_* */
#define PLAYER_ARMY_OFF    (MAP_PLAYER_STATES + 0x26) /* u8 army (nation) id */
#define PLAYER_ARMY_INDEX_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_INDEX) /* u8 */
#define PLAYER_ARMY_STATE_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_STATE) /* u8 */
#define PLAYER_TURN_TIME_OFF (MAP_PLAYER_STATES + PLAYER_REC_TURN_TIME) /* u32 elapsed turn time in frames */
#define PLAYER_REC_FLIP        0x28 /* u8 nonzero when this player's unit sprites are mirrored horizontally */
#define PLAYER_REC_SPRITE_STATE 0x29 /* u8 cached 0/1 state that picks the unit sprite variant (func_020a7298) */
#define PLAYER_FLIP_OFF (MAP_PLAYER_STATES + PLAYER_REC_FLIP) /* u8 */
#define PLAYER_SPRITE_STATE_OFF (MAP_PLAYER_STATES + PLAYER_REC_SPRITE_STATE) /* u8 */
#define MAP_TEAM_A_PLAYER  0x52b8 /* s16 id of the player team A's army belongs to */
#define MAP_TEAM_B_PLAYER  0x52ba /* s16 id of the player team B's army belongs to */

/* gCurrentMap[1] is the map-view controller: it owns the scroll task and gets
 * a callback run each time a scroll pan finishes. */
#define MAPVIEW_SCROLL_DONE 0x1c /* void (*)(void): run when a view pan reaches its target */

/* A map-view panning animation, one of the view controller's sprite tasks.  It
 * pans the view from the position saved at start (+0x34/+0x36) to the target
 * (+0x38/+0x3a) along whichever axis has the larger delta, using a per-frame
 * speed ramp indexed by the countdown at +0x40. */
typedef struct MapScrollAnim {
    u8  pad00[0x34];
    s16 startX;    /* +0x34 view x when the pan started */
    s16 startY;    /* +0x36 view y when the pan started */
    s16 targetX;   /* +0x38 destination view x */
    s16 targetY;   /* +0x3a destination view y */
    s16 deltaX;    /* +0x3c targetX - startX */
    s16 deltaY;    /* +0x3e targetY - startY */
    u16 remaining; /* +0x40 index of the current speed step, counts down */
    u16 accum;     /* +0x42 cells travelled so far, times the major-axis sign */
} MapScrollAnim;

/* Battle outcome for one player, returned by GetPlayerResult. */
enum {
    BATTLE_RESULT_NONE = 0,
    BATTLE_RESULT_WIN  = 1,
    BATTLE_RESULT_LOSE = 2,
    BATTLE_RESULT_DRAW = 3
};

/* Battle-end state (gBattleEndState): byte 0 is non-zero once the battle has
 * finished, bytes 1 and 2 are the end conditions, byte 3 qualifies byte 2. */
#define BATTLE_END_ENDED 0
#define BATTLE_END_FLAG1 1
#define BATTLE_END_FLAG2 2
#define BATTLE_END_FLAG3 3

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
#define MAPDATA_TURN_TIME 0x10 /* u16 configured per-turn time limit in frames, 0 = untimed */

/* Map ids in this range are campaign maps with a full 0x6f8-byte record. */
#define MAP_ID_CAMPAIGN_FIRST 0xE1
#define MAP_ID_CAMPAIGN_END   0x1A9 /* one past the last campaign map */

/* A saved map record. The 0x54-byte header is shared by the compact saved form
 * (0x2AC bytes: a 20x20 terrain area with the packed unit entries after it at
 * +0x1E4) and the expanded runtime form (0x6F8 bytes: a 30x30 terrain area with
 * the unit entries at +0x3D8). */
typedef struct MapRecordHeader {
    u32 magic;          /* +0x00 MAP_RECORD_MAGIC */
    u8  width;          /* +0x04 map width in cells */
    u8  height;         /* +0x05 map height in cells */
    char name[0x21];    /* +0x06 map name, NUL terminated */
    u8  playerCount;    /* +0x27 players on the map, 255 = none */
    u8  playerIds[5];   /* +0x28 player id of each player slot */
    u8  propertyCount;  /* +0x2D terrain cells carrying a property flag */
    u8  unitsPerPlayer; /* +0x2E one more than the largest army's unit count */
    u8  unitCount;      /* +0x2F packed unit entries in the record */
    u8  settings[0x10]; /* +0x30 map settings block */
    u8  stamp[0x14];    /* +0x40 date, checksum and console id stamp */
} MapRecordHeader;

#define MAP_RECORD_MAGIC       0x20070731
#define MAP_RECORD_SAVE_SIZE   0x2AC /* compact saved record */
#define MAP_RECORD_SIZE        0x6F8 /* expanded runtime record */
#define MAP_RECORD_SAVE_UNITS  0x1E4 /* packed unit entries in the saved record */
#define MAP_RECORD_UNITS       0x3D8 /* packed unit entries in the runtime record */

/* The task that fades the battle map in when the map view opens: MapFadeInStep
 * (main_020CBACC.c) bumps fadeTimer each frame while the map is drawn. */
typedef struct MapViewTask {
    u8  pad0[0x34];
    s16 fadeTimer; /* +0x34 fade-in frame counter */
    s16 viewX;     /* +0x36 saved map view scroll x (MAP_VIEW_X) */
    s16 viewY;     /* +0x38 saved map view scroll y (MAP_VIEW_Y) */
    s16 unk3A;     /* +0x3A */
} MapViewTask;

#endif
