/* The battle map (gCurrentMap) and its unit records.
 *
 * The map is a byte array; the offsets below are the ones the unit and cursor code uses.
 * The unit records start at MAP_UNIT_RECORDS and are 14 bytes each; a record is picked by
 * the unit id byte, whose top two bits hold the owner (player) and whose low six bits the
 * slot of the unit.
 */
#ifndef BATTLE_MAP_H
#define BATTLE_MAP_H

/* Area-scan state: modes 0..5 use relative offsets; higher modes scan all tiles. */
typedef struct AreaScan {
    s32 width;
    s32 height;
    s32 originX;
    s32 originY;
    s32 x;
    s32 y;
    s32 mode;
    s32 index;
} AreaScan;

enum { AREA_SCAN_FULL_MAP = 6, AREA_SCAN_END = 127 };
extern s16 *gAreaScanOffsetTables[];


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

/* The packed kind and rank byte at the start of each unit record. */
typedef struct BattleMapUnitKindRank {
    u8 kind:6;
    u8 rank:2; /* 0 unranked, 1 level 1, 2 level 2, 3 veteran or CO unit */
} BattleMapUnitKindRank;

/* The head of a unit record read through bitfields: the kind is the low six bits
 * of the first byte and the owner the top two, followed by the tile position.
 * Sized like BattleMapUnit so it can index the record array directly. */
 typedef struct BattleMapUnitHead {
     u8 kind:6;    /* +0x00 unit kind */
     u8 owner:2;   /* +0x00 owner (player) */
     u8 x;         /* +0x01 tile x */
     u8 y;         /* +0x02 tile y */
     u8 unk3;      /* +0x03 */
     u16 flags;    /* +0x04 per-unit flags, UNIT_FLAG_* */
     u16 health:7; /* +0x06 current HP (MAP_UNIT_HEALTH) */
     u16 ammo:4;   /* +0x06 ammo in bits 7..10 (MAP_UNIT_AMMO) */
     u16 facing:5; /* +0x06 capture points in bits 11..15, 0 when not capturing (MAP_UNIT_CAPTURE) */
     u16 targetX:6;    /* +0x08 AI move target x, MAP_UNIT_TARGET_NONE when unset */
     u16 targetY:6;    /* +0x08 AI move target y in bits 6..11 */
     u16 unk8_12:2;    /* +0x08+12 */
     u16 unk8_14:2;    /* +0x08+14 */
     u8 fuel:7;    /* +0x0A fuel in the low seven bits (MAP_UNIT_FUEL) */
     u8 unkA_7:1;  /* +0x0A+7 */
     u8 aiState:4; /* +0x0B AI action step (MAP_UNIT_AI_STATE) */
     u8 unkB4:1;   /* +0x0B+4 */
     u8 unkB5:1;   /* +0x0B+5, held while a move target is assigned */
     u8 unkB6:1;   /* +0x0B+6 */
     u8 unkB7:1;   /* +0x0B+7 */
     u8 firstCarried; /* +0x0C first carried unit, 0 if none */
     u8 nextCarried;  /* +0x0D next unit in the carry chain, 0 if none */
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

/* The stat block's two word stats: +0x08 is the damage-percentage bonus (zero for
 * a unit kind that cannot attack), +0x0A the attack-power percentage bonus (the
 * part unit attack power adds its 100 base to). */
#define UNIT_STAT_DAMAGE_BONUS       0x08
#define UNIT_STAT_ATTACK_POWER_BONUS 0x0A

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
#define MAP_UNIT_SLOT_CURSOR 0x52c0 /* s16 unit slot the free-slot search starts after, 0 = none used yet */
#define MAP_CURRENT_OWNER   0x52a6 /* u16 the current player's owner bits (MAP_CURRENT_PLAYER << 5) */
#define MAP_VIEW_HOLD       0x52aa /* s8 holds taken on the map view; map input is blocked while it is nonzero */
#define MAP_UNIT_MOVE_ACTIVE 0x52ab /* u8 nonzero while a unit move is running; the battle loop waits on it (IsUnitMoveActive) */
#define MAP_COMMAND_PENDING 0x52ac /* u8 nonzero while a map command is pending (IsMapCommandPending); the cursor cancels it instead of opening the action menu */
#define MAP_ACTIVE_PLAYER   0x52b6 /* u16 player whose units are being processed, saved and restored around influence builds */
#define MAP_CURSOR_UNIT     0x52d0 /* BattleMapUnit * of the unit under the cursor */
#define MAP_CURSOR_UNIT_ID  0x52d4 /* u8 id of the unit under the cursor */
#define MAP_CURSOR_DIR      0x52d5 /* u8 direction the cursor points at; ResolvePathAttack also stores the move cost of the path here, which ChargeUnitMoveFuel then charges to the unit's fuel */
#define MAP_CURSOR_CARRIER  0x52d6 /* u8 id of the transport carrying that unit, 0 if none */
#define MAP_CURSOR_OLD_X    0x52d8 /* s16 the cursor position before the last move */
#define MAP_CURSOR_OLD_Y    0x52da
#define MAP_CURSOR_X        0x52dc /* s16 tile x of the cursor */
#define MAP_CURSOR_Y        0x52de /* s16 tile y of the cursor */
#define MAP_PATH_X          0x52e0 /* s16 tile x the movement path starts at */
#define MAP_PATH_Y          0x52e2 /* s16 tile y the movement path starts at */
#define MAP_CURSOR_PATH     0x5388 /* the path from the unit to the cursor */

/* A cursor direction marker: the arrow sprite that shows an attack direction
 * picked for one of the two attack targets.  The marker is an object of
 * gDirectionMarkerSpriteClass; the draw callback draws its arrow tile at the
 * tile it sits on, selected by the direction it shows. */
typedef struct DirectionMarker {
    u8  pad00[0x34];
    s32 x;         /* +0x34 map tile x the marker sits on */
    s32 y;         /* +0x38 map tile y the marker sits on */
    u8  pad3C[0x30];
    s16 direction; /* +0x6C direction of the arrow the marker shows */
} DirectionMarker;
#define MAP_CELL_BITMAP     0x5201 /* u8[0xA1] the second team's bitmap of the cells it can see or threaten */
#define MAP_CELL_BITMAP_TEAM_A 0x5160 /* u8[0xA1] the first team's bitmap of the cells it can see or threaten */
#define MAP_CELL_BITMAP_SIZE 0xA1 /* bytes in one team's cell bitmap; the two bitmaps sit back to back */
#define MAP_WIDTH           0x5144 /* u16 map width in cells */
#define MAP_HEIGHT          0x5146 /* u16 map height in cells */
#define MAP_DISTANCE_REFERENCE_CELLS 30 /* side of the reference map a scaled distance threshold is based on */
#define MAP_DISTANCE_REFERENCE_AREA_FIXED8 0x3840000 /* (MAP_DISTANCE_REFERENCE_CELLS << 8) squared */
#define MAP_VIEW_X          0x5148 /* s16 view scroll x, in 1/16-cell units */
#define MAP_VIEW_Y          0x514a /* s16 view scroll y, in 1/16-cell units */
#define MAPVIEW_SCROLL_DONE 0x001C /* callback invoked when map-view scrolling finishes */
#define MAP_VIEW_WIDTH_CELLS  0x6f04 /* u8 width of the visible view in map cells */
#define MAP_VIEW_HEIGHT_CELLS 0x6f05 /* u8 height of the visible view in map cells */
#define MAP_VIEW_MARGIN       16   /* 1/16-cell units in one cell: border kept around a followed point */
#define MAP_VIEW_NO_SCROLL    10000 /* s16 sentinel: this axis does not need to scroll */
#define MAP_VIEW_CELL_X     0x5150 /* s16 view scroll x, in whole cells (MAP_VIEW_X / 16) */
#define MAP_VIEW_CELL_Y     0x5152 /* s16 view scroll y, in whole cells (MAP_VIEW_Y / 16) */
#define MAP_VIEW_SCROLL_STATE 0x5154 /* u8 map-view scroll flags; the low nibble is nonzero while a scroll runs (IsMapCursorIdle) */
#define MAP_BATTLE_RULES    0x5155 /* u8 battle-rule flags, set to 0x13 at battle start-up and overridable by the map script; the player-defeat checks test them */
#define MAP_RULE_DEFEAT_BY_HQ 0x02 /* MAP_BATTLE_RULES: lose when the player's HQ has been lost */
#define MAP_RULE_DEFEAT_BY_ROUT 0x01 /* MAP_BATTLE_RULES: lose when the player's army has been routed */
#define MAP_RULE_DEFEAT_BY_ROUT_HUMAN 0x10 /* MAP_BATTLE_RULES: the rout rule applies to human players */
#define MAP_VIEW_ZOOM       0x6ef8 /* s16 view zoom: 0 and 128 are the two levels */
/* The eye position (view+0x10..0x18, UpdateMapViewEye) is the view's zoom-scaled
 * offset plus the map scroll converted to view units: MAP_VIEW_EYE_CELL units per
 * map cell, half a cell in from the map's corner. */
#define MAP_VIEW_EYE_CELL   0x300
#define MAP_VIEW_EYE_HALF_CELL 0x180
/* Inside the map view block (MAP_VIEW_ZOOM is its base): the 4x4 view*projection
 * matrix that projects world points to the screen, the Q12 matrix the view
 * unprojects screen points with, and the world origin a projected point is
 * relative to. */
#define MAP_VIEW_PROJECTION 0x70 /* s32[16]: view*projection matrix, projects world points to the screen */
#define MAP_VIEW_MATRIX     0xb0 /* s32[9]: Q12 inverse of the projection's 3x3, unprojects screen points */
#define MAP_VIEW_ORIGIN     0xf0 /* s32[3]: world position a projected point is added to */
#define MAP_TILESET         0x5157 /* u8 battle-setting/tileset index, selects the terrain tileset bank */
#define MAP_FOG             0x5156 /* u8 nonzero when fog of war hides distant units */
/* Values stored in the map's weather fields. */
enum { WEATHER_CLEAR = 0, WEATHER_RAIN = 1, WEATHER_SNOW = 2, WEATHER_SANDSTORM = 3 };
#define WEATHER_OPTION_RANDOM 4 /* the weather menu's random option: clear weather in auto-change mode */
#define MAP_WEATHER         0x5158 /* u8 current weather (0 clear, 1 rain, 2 snow, 3 sandstorm) */
#define MAP_WEATHER_CLEAR     0 /* MAP_WEATHER: no weather */
#define MAP_WEATHER_RAIN      1 /* MAP_WEATHER: rain */
#define MAP_WEATHER_SNOW      2 /* MAP_WEATHER: snow */
#define MAP_WEATHER_SANDSTORM 3 /* MAP_WEATHER: sandstorm */
#define MAP_WEATHER_MODE    0x5159 /* u8 nonzero when the weather may change by itself */
#define MAP_WEATHER_START   0x515a /* u8 weather when the battle starts */
#define MAP_WEATHER_RESET   0x515b /* u8 weather the battle returns to after a change */
#define MAP_WEATHER_DELAY   0x515c /* u8[4] per-player turns left before the weather may change again */

/* The weather transition sprite (class gWeatherTransitionSpriteClass, main_020A38F4): its
 * script takes the map-view hold, changes the map's weather, plays the new weather's
 * sound and refreshes the view. */
#define WEATHER_SPRITE_TARGET   0x36 /* s16 weather the map is changing to */
#define WEATHER_SPRITE_IS_RESET 0x38 /* s16 1 for the reset to the start weather, 0 for a change */

/* The map view's per-frame highlight state (gMapHighlightState, 24 bytes): the height
 * the wave-animated cells are raised by, the property owner-colour pulse, the
 * frame index of the highlighted unit's flash colours, the map's polygon
 * attributes, the raise timer of the cells being lifted and those four colours. */
#define MAP_VIEW_WAVE_HEIGHT      0x00 /* u8 0..15 height the wave-animated cells are raised by */
#define MAP_VIEW_OWNER_BANDS      0x01 /* u8 1 while property cells are drawn in their owner's palette band */
#define MAP_VIEW_FLASH_FRAME      0x02 /* u8 index of the highlighted unit's flash colours */
#define MAP_VIEW_POLY_ATTR        0x04 /* u32 polygon attribute bits of the map's quads */
#define MAP_VIEW_POLY_ATTR2       0x08 /* u32 further polygon attribute bits */
#define MAP_VIEW_RAISE_TIMER      0x0c /* s32 frames the lifted cells have been rising, 0..8 */
#define MAP_VIEW_FLASH_COLORS     0x10 /* u16[4] colours a highlighted unit is drawn in */
#define MAP_VIEW_OWNER_BAND_CYCLE 140  /* frames one owner-band pulse lasts */
#define MAP_VIEW_OWNER_BAND_DELAY  60  /* frames of that pulse the bands are hidden for */

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
#define MAP_TURN_MAX        999    /* the turn counter saturates here (AdvanceMapTurn) */
#define MAP_ID              0x5142 /* u16 map id, key into the per-map data records */
#define MAP_PLAYER_COUNT    0x5141 /* u8 number of players the map has (1..4) */
#define MAP_NAME            0x5120 /* char[] the map's display name */
#define MAP_CELL_TILE_ID    0xa10  /* u16 per cell: tile id, keyed through the current terrain tileset */
#define MAP_ROW_OFFSETS     0x3758 /* u16 per row: offset of the row in the cell arrays */
#define MAP_ROW_OFFSETS_WORD 0x1bac /* MAP_ROW_OFFSETS as a u16 index into gCurrentMap (0x3758 / 2) */
#define MAP_CELL_UNIT_ID    0x508  /* u8 per cell: id of the unit standing there, 0 if none */
#define MAP_PLAYER_MOVE_RANGE   0x37f8 /* u8 per cell, one 0x508-byte grid per player: set for the cells that player's selected unit can reach */
#define MAP_PLAYER_MOVE_RANGE_STRIDE 0x508 /* bytes between two players' movement-range grids */
#define MAP_CELL_VISIBLE_UNIT 0x000 /* u8 per cell: id of the unit the viewing player can see there, 0 if none (fog) */
#define MAP_CELL_TERRAIN    0x1420 /* u8 per cell: low 5 bits terrain kind, high 3 bits owner */
#define MAP_CELL_PROPERTY_INDEX 0x1928 /* s8 per cell: index of the cell's record in MAP_PROPERTY_CELLS */
#define MAP_TILE_TERRAIN    0x6a60 /* u8 per tile id: terrain kind/owner byte the cell gets */
#define MAP_TERRAIN_KIND_MASK  0x1f /* terrain byte: terrain kind */
#define MAP_TERRAIN_OWNER_MASK 0xe0 /* terrain byte: owner bits (player << 5) */

/* gTerrainClassFlags: one 8-byte record per terrain class (a tile's class id from
 * the current tileset): the class flags word, then palette/x/y/offset bytes.  The
 * low bits of the flags word say which autotile family the class is drawn with. */
#define TERRAIN_CLASS_VARIANT1  0x0001 /* draw with the single-tile variant */
#define TERRAIN_CLASS_CONNECTED 0x0002 /* draw with the connected autotile */
#define TERRAIN_CLASS_EDGE      0x0004 /* draw with the edge autotile */

/* Terrain kinds the map code names directly; the tileset's MAP_TILE_TERRAIN
 * table maps each tile id to one of these packed values. */
#define MAP_TERRAIN_SHOAL      9    /* shoal (beach) ground: a sea unit can enter it and a Rig builds a temporary port on it */
#define MAP_TERRAIN_BASE       0x11 /* base: produces land units */
#define MAP_TERRAIN_CITY       0x10
#define MAP_TERRAIN_AIRPORT    0x12
#define MAP_TERRAIN_PORT       0x13 /* port: produces naval units */
#define MAP_TERRAIN_TEMP_AIRFIELD 0x14
#define MAP_TERRAIN_TEMP_PORT  0x15
#define MAP_TERRAIN_COM_TOWER  0x16
#define MAP_TERRAIN_RADAR      0x17
#define MAP_TERRAIN_PLAIN      1    /* plain ground */
#define MAP_TERRAIN_MOUNTAIN   3    /* rock/mountain ground (tile MAP_TILE_ROCK) */
#define MAP_TERRAIN_WOODS      4    /* woods/forest ground (tile MAP_TILE_WOODS) */
#define MAP_TERRAIN_WASTELAND  8    /* barren ground a destroyed owned property leaves */
#define MAP_TERRAIN_BRIDGE     0x0D /* bridge over a river: the kind the map editor's bridge brush paints */
#define MAP_TERRAIN_BRIDGE_WASTELAND 0x0E /* the same bridge painted over wasteland; the editor reports it as MAP_TERRAIN_BRIDGE */
#define MAP_TERRAIN_PROPERTY_FIRST 0x0f /* first property terrain kind: headquarters */
#define MAP_TERRAIN_HQ         0x0f /* headquarters: the AI scores it 30 capture points, other properties 1 */
#define MAP_TERRAIN_PROPERTY_LAST  0x18 /* last property terrain kind */
#define MAP_TERRAIN_SILO       0x18 /* missile silo: a unit that can reach it may launch a missile; not capturable */
#define MAP_TERRAIN_SILO_EMPTY 0x19 /* fired missile silo: the empty shell the cell shows afterwards */
#define MAP_TERRAIN_IMPACT     0x1c /* destructible impact feature; its cell becomes a crater */
#define MAP_TERRAIN_FEATURE    0x1d /* feature tile: a cell of this kind anchors a destructible map feature and is highlighted inside an order effect area */

/* Columns of the per-owner terrain count table used by the property icon grid. */
enum {
    MAP_PROPERTY_COUNT_HQ = 0,
    MAP_PROPERTY_COUNT_CITY = 1,
    MAP_PROPERTY_COUNT_BASE = 2,
    MAP_PROPERTY_COUNT_AIRPORT = 3,
    MAP_PROPERTY_COUNT_PORT = 4,
    MAP_PROPERTY_COUNT_COM_TOWER = 7,
    MAP_PROPERTY_COUNT_KIND_18_19 = 8, /* terrain kinds 0x18 and 0x19 share a column */
    MAP_PROPERTY_COUNT_RADAR = 9,
    MAP_PROPERTY_COUNT_NONE = -1
};

/* Shape of the per-owner property count grid filled by CountMapProperties: one
 * band per player/owner and one column per MAP_PROPERTY_COUNT_* kind. */
#define MAP_PROPERTY_GRID_BANDS   5
#define MAP_PROPERTY_GRID_COLUMNS 12

/* The property tile ids (gPropertyTileIds): nine rows of
 * MAP_PROPERTY_TILE_OWNERS tile ids, one row per capturable property kind in
 * tileset sheet order; a row holds the kind's tile for owner 0 (unowned) up to
 * owner 4, so the row of a kind starts at row * MAP_PROPERTY_TILE_OWNERS. */
#define MAP_PROPERTY_TILE_OWNERS      5
#define MAP_PROPERTY_TILE_NONE        0xffff /* ends the table (gPropertyTileIds[0] is it when the map has no property tiles) */
#define MAP_PROPERTY_TILE_OWNER_SHIFT 5  /* MAP_TERRAIN_OWNER_MASK >> this: the owner colour */
#define MAP_PROPERTY_TILE_HQ_ROW      0  /* headquarters tiles (terrain kind 0x0f) */
#define MAP_PROPERTY_TILE_REBUILT_ROW 2  /* tiles a cell shows once it is no longer a headquarters (terrain kind 0x10) */

/* Remaining HP of destructible terrain (low seven bits, 0 where there is none). */
#define MAP_CELL_TERRAIN_HP    0x539c /* u8 per cell */
#define MAP_CELL_TERRAIN_HP_MASK    0x7f /* remaining HP in the byte */
#define MAP_CELL_TERRAIN_HP_PRESENT 0x80 /* set on every nonzero HP byte: the saved-map run-length data keeps such bytes as literals */
#define MAP_TERRAIN_IMPACT_HP_FULL  99   /* HP an impact feature has when the battle starts */

/* Run-length form of the terrain-HP grid a saved map record holds at +0x1194: a
 * run of zero cells is a count byte below 0x80, a nonzero cell is kept as itself
 * (its MAP_CELL_TERRAIN_HP_PRESENT bit keeps it apart from a count), and
 * MAP_TERRAIN_HP_RLE_END closes the data. */
#define MAP_TERRAIN_HP_RLE_MAX 127  /* longest zero run one count byte holds */
#define MAP_TERRAIN_HP_RLE_END 0xff /* byte that ends the run-length data */

/* Tile ids the impact blast writes into the current tileset bank. */
#define MAP_TILE_WASTELAND     3
#define MAP_TILE_BLAST_GROUND  4
#define MAP_TILE_BLAST_CRATER  5

/* Tiles the random-map generator (overlay 7) seeds on plain ground and grows
 * into patches with Map_GrowTerrain; their cells end up the given terrain kind. */
#define MAP_TILE_WOODS         0x20 /* woods/forest, terrain kind 4 */

/* Tiles of a missile silo: the ready silo and the empty shell a launch leaves
 * behind. */
#define MAP_TILE_SILO          0x180
#define MAP_TILE_SILO_FIRED    0x1A0
#define MAP_TILE_ROCK          0x21 /* rock/mountain, terrain kind 3 */
#define MAP_TILE_REEF          0x168 /* reef, terrain kind 0x0C */
#define MAP_TILE_PLAIN         1
#define MAP_TILE_ROUGH_GROUND  2    /* terrain kind 5 */
#define MAP_TILE_SEA           3    /* terrain kind 8 */

enum {
    MAP_RANDOM_ROUGH_GROUND_COUNT_MIN = 20,
    MAP_RANDOM_ROUGH_GROUND_COUNT_MAX = 40
};

enum {
    MAP_RANDOM_REEF_COUNT_MIN = 5,
    MAP_RANDOM_REEF_COUNT_MAX = 10
};

/* Reach of the impact blast: the movement range of a pseudo unit kind, searched
 * with an effectively unlimited movement-cost budget. */
#define IMPACT_BLAST_MOVE_KIND   0x1d
#define IMPACT_BLAST_MOVE_BUDGET 110
#define MAP_UNIT_RECORDS    0x59a4 /* 256 unit records of 14 bytes */
#define MAP_UNIT_STRIDE     14     /* bytes per unit record */
#define MAP_UNIT_COUNT      256    /* unit records in MAP_UNIT_RECORDS */
#define MAP_UNIT_GROUP_SIZE 64     /* records per player slot; a record's owner (player << 6) picks its group */
#define MAP_UNIT_GROUP_BASE 0x52a8 /* u16 base id of the current player's unit group (gPlayerUnitIdBase[MAP_CURRENT_PLAYER], the owner bits of a group) */
#define MAP_UNIT_ID_OWNER_MASK 0xC0 /* top two bits of a unit id: the owner group, compared with MAP_UNIT_GROUP_BASE */
#define MAP_UNIT_GROUP_SCAN 0x33   /* exclusive end of the unit ids scanned within a group: base+1 .. base+0x33 */

/* The map's order queue: 8-byte MapOrder records at MAP_ORDERS, ended by one
 * whose type is 0.  +0x06 is an order's countdown: it is loaded with the order's
 * kind when the order's targets are played and ticked down one frame at a time. */
#define MAP_ORDERS       0x58a4 /* first MapOrder record */
#define MAP_ORDER_STRIDE 8      /* bytes per MapOrder record (see MapOrder) */
#define MAP_ORDER_COUNT  32     /* MapOrder records the queue holds */
#define MAP_ORDER_TIMER  0x06   /* s8 frames left before the order's targets are played */
#define MAP_ORDER_TYPE   0x02   /* u16 bits 6..9: the order's type (0 ends the queue) */
#define MAP_ORDER_TYPE_BITS 0x3c0 /* the MAP_ORDER_TYPE field's bits in the record's u16 */
#define MAP_ORDER_VALUE  0x04   /* u8 the order's value (health, amount...) */

/* Values of MapOrder.type (the field at MAP_ORDER_TYPE). */
enum {
    MAPORDER_NONE               = 0, /* free slot, ends the queue */
    MAPORDER_EFFECT_AREA        = 3, /* pulsating target-area rectangle */
    MAPORDER_ATTACK_AREA        = 4, /* radius-5 area attack */
    MAPORDER_ATTACK_POINT       = 5, /* point/column attack */
    MAPORDER_ATTACK_LINE        = 6, /* line attack */
    MAPORDER_ATTACK_LINE_FACING = 7, /* line attack whose facing depends on the player */
    MAPORDER_CURSOR             = 9  /* map cursor placed on one tile */
};

/* Battle-preview target kind of a tile (GetTileTargetKind): the type of the attack
 * order anchored on it, or this value when the tile has destructible impact-terrain
 * hit points left. */
#define MAP_TARGET_IMPACT_TERRAIN 1

/* Damage-table kinds (the row GetWeaponDamagePercent indexes within a weapon's
 * per-attacker damage table) for the non-unit battle-preview targets above, as
 * returned by GetDamageTargetIndex. */
#define DAMAGE_TARGET_IMPACT_TERRAIN 0x1d
#define DAMAGE_TARGET_ATTACK_AREA    0x1e
#define DAMAGE_TARGET_ATTACK_LINE    0x1f

/* One record of the map's order queue (MAP_ORDERS): the tile rectangle the order
 * covers, its type and the value and countdown it runs with.  The byte at +0x05
 * holds the player the order belongs to, its enabled flag and its mode. */
typedef struct MapOrder {
    u8 x;             /* +0x00 rectangle x */
    u8 y;             /* +0x01 rectangle y */
    u16 width:3;      /* +0x02 rectangle width in tiles */
    u16 height:3;     /* +0x02 rectangle height in tiles */
    u16 type:4;       /* +0x02 order type, 0 = free slot */
    u16 kind:4;       /* +0x02 order kind, loaded into the countdown when it runs */
    u16 top:2;        /* +0x02 */
    u8 value;         /* +0x04 order value (health, amount...) */
    u8 player:3;      /* +0x05 player the order belongs to */
    u8 enabled:1;     /* +0x05 nonzero: the order is in effect */
    u8 mode:4;        /* +0x05 order mode */
    u8 timer;         /* +0x06 countdown; the order's targets play when it runs out */
    u8 last;          /* +0x07 */
} MapOrder;

/* One command of a battle event script: the interpreter keeps the current command
 * in its context's +4 cursor and runs 0x10-byte commands.  +0x08 is an s16 player
 * slot, +0x0A an s16 parameter (kind, tile coordinate...) and +0x0C an s32 argument,
 * their meaning depending on the opcode. */
#define MAP_SCRIPT_COMMAND_SIZE 0x10

/* One bit per neighbour direction of a map tile, as set in the cursor and unit
 * move direction masks.  The direction table at gMapCursorDirs maps each cursor
 * direction index to its bit and its (dx, dy) step in this encoding. */
#define MAP_DIR_UP    1
#define MAP_DIR_DOWN  2
#define MAP_DIR_LEFT  4
#define MAP_DIR_RIGHT 8

/* Cursor option index: which neighbour tile the directional cursor points at,
 * in gMapCursorDirs order (up, right, down, left). */
#define MAP_CURSOR_OPTION_UP    0
#define MAP_CURSOR_OPTION_RIGHT 1
#define MAP_CURSOR_OPTION_DOWN  2
#define MAP_CURSOR_OPTION_LEFT  3
#define MAP_CURSOR_OPTION_COUNT 4

/* The direction keys that cycle the directional cursor, as returned by
 * GetCursorCycleKey from the auto-repeating keys: right/down steps to the next
 * option, left/up to the previous one. */
#define MAP_CURSOR_CYCLE_NEXT 8 /* right or down held */
#define MAP_CURSOR_CYCLE_PREV 4 /* left or up held */

/* Columns of the gMapCursorDirs table. */
#define MAP_CURSOR_DIR_MASK 0
#define MAP_CURSOR_DIR_DX   2
#define MAP_CURSOR_DIR_DY   3

/* The (dx, dy) step of each cursor option, gMapCursorOptionStep: two s16 per
 * MAP_CURSOR_OPTION_* in gMapCursorDirs order (up, right, down, left). */
#define MAP_CURSOR_OPTION_STRIDE 2

/* The task object that drives a directional map-cursor option (the arrows that
 * pick a neighbouring cell): the directions that may be chosen, the option
 * chosen so far, and, for a cargo drop, the carried-unit slot it acts on. */
#define MAP_OPTION_DIR_MASK    0x6C /* s16 MAP_DIR_* bits of the directions that can be picked */
#define MAP_OPTION_SELECTED    0x6E /* s16 chosen option, MAP_CURSOR_OPTION_* */
#define MAP_OPTION_CARGO_SLOT  0x70 /* s16 carried-unit slot a cargo drop acts on (0 = first, 1 = next) */

/* Scratch fields of the supply overlay's sprite object (the sprite the task
 * FindSupplyTargetDirections in main_020CAB8C.c walks): the direction being
 * scanned, and whether finishing the overlay also completes the supply action. */
#define SUPPLY_OVERLAY_DIR     0x34 /* s16 direction being scanned; the overlay finishes once it reaches MAP_CURSOR_OPTION_COUNT */
#define SUPPLY_OVERLAY_COMPLETE 0x36 /* s16 0 when finishing also completes the supply action: the cursor snaps to MAP_CURSOR_TARGET_X/Y and the unit ends its action with AI_COMMAND_WAIT; 1 leaves both alone */

/* The map's property-cell list, rebuilt by RebuildMapPropertyCells: one 6-byte record per
 * property (or kind 0x18 special) cell, ended by a 0xff terrain kind. */
#define MAP_PROPERTY_CELLS  0x6c60 /* first record */
#define MAP_PROPERTY_STRIDE 6      /* bytes per record */
#define MAP_PROPERTY_KIND   0x00   /* u8 terrain kind of the cell */
#define MAP_PROPERTY_X      0x01   /* u8 tile x */
#define MAP_PROPERTY_Y      0x02   /* u8 tile y */
#define MAP_PROPERTY_COUNT  0x03   /* u8 times the cell was used */
#define MAP_PROPERTY_MAX    0x63   /* property records the table can hold; the AI turn resets all of them */
#define MAP_PROPERTY_END    0xff   /* terrain kind that ends the list */

/* One player's slot in a map-settings record: the CO, army and team that player
 * chose for the map.  MapSettings_SavePlayers fills the four slots. */
typedef struct MapSettingsPlayer {
    u16 co:8;   /* CO id */
    u16 army:4; /* army id (colour) */
    u16 team:4; /* team number */
} MapSettingsPlayer;

/* Bit masks of a player slot's packed word (the fields of MapSettingsPlayer). */
#define MAP_SETTINGS_PLAYER_CO   0x00FF /* bits 0..7: CO id */
#define MAP_SETTINGS_PLAYER_ARMY 0x0F00 /* bits 8..11: army id */
#define MAP_SETTINGS_PLAYER_TEAM 0xF000 /* bits 12..15: team number */

/* CO ids and their icon-strip indices (GetPlayerCoIconIndex): ids 1..12 use icons
 * 0..11 in order; id 0 is the random/unset slot, which uses the last icon. */
#define CO_ID_RANDOM      0
#define CO_ICON_RANDOM    12
#define CO_ICON_NONE      0xFF /* returned for a CO id outside the icon strip */

/* CO portrait strips in the occupation screen's sprite sheet (GetCOPortraitOffset):
 * each portrait is a 32x8 strip of CO_PORTRAIT_TILE_STRIDE tiles, and the slots of
 * CO ids 3 and 4 come in the opposite order to the ids.  CO_PORTRAIT_TILE_NONE is
 * the tile value that means "no portrait to draw". */
#define CO_PORTRAIT_TILE_BASE   0x4EC
#define CO_PORTRAIT_TILE_STRIDE 4
#define CO_PORTRAIT_TILE_NONE   0xFFFF

/* Backgrounds of the occupation screen (GetOccupationBackgroundIndex): one name
 * (gOccupationBackgroundNames) per property terrain kind in the table. */
#define OCCUPATION_BACKGROUND_COUNT 9

/* OBJ tile offset of one occupation-screen background graphic in the sprite
 * atlas: OCCUPATION_BACKGROUND_TILE_BASE per background index, one background
 * every OCCUPATION_BACKGROUND_TILE_STEP tiles (GetOccupationBackgroundTileOffset). */
#define OCCUPATION_BACKGROUND_TILE_BASE 0x424
#define OCCUPATION_BACKGROUND_TILE_STEP 0x14

/* gMapConfig, the decoded per-battle configuration (a 16-byte record): a u16
 * flags word followed by the battle setting, value limits and per-player mask. */
#define MAPCONFIG_FLAGS     0x00 /* u16 packed rule flags */
#define MAPCONFIG_CONFIG_FLAGS 0x0038 /* bits 3..5 of MAPCONFIG_FLAGS: the setup's four-choice config flags, saved in MapSettings.rules bits 28..30 (MAP_SETTINGS_FLAGS) */
#define MAPCONFIG_MODE      0x00 /* u16: the battle mode in the low three bits of MAPCONFIG_FLAGS */
#define MAPCONFIG_MODE_MASK 0x0007 /* low three bits of MAPCONFIG_FLAGS */
#define MAPCONFIG_MODE_TEAM 0    /* battle mode of the story/team battles, whose maps restrict what may be built */
#define MAPCONFIG_PROPERTY_LIMIT 0x02 /* u8 properties a player must own to win; 0 disables the rule */
#define MAPCONFIG_BATTLE_SETTING 0x03 /* u8 additional battle setting (MAP_SETTINGS_SETTING); the default setting 4 is stored as 0 */
#define MAPCONFIG_CO_POWER  0x1000 /* bit 12 of MAPCONFIG_FLAGS: CO powers are enabled */
#define MAPCONFIG_ARMY_MODE 0x2000 /* bit 13 of MAPCONFIG_FLAGS: army mode — the map uses per-army movement costs and the CO-zone bonus tables */
#define MAPCONFIG_LIMIT_FLAG 0x0040 /* bit 6 of MAPCONFIG_FLAGS: the second value limit applies (MAP_SETTINGS_VALUE_FLAG) */
#define MAPCONFIG_VALUE_FLAG 0x0100 /* bit 8 of MAPCONFIG_FLAGS: the value flag is on, saved as MAP_SETTINGS_VALUE_FLAG */
#define MAPCONFIG_SHOW_UNIT_INFO_PANEL 0x0400 /* bit 10 of MAPCONFIG_FLAGS: the map view draws the unit info panel; a map script sets and clears it (MapScriptShowUnitInfoPanel / MapScriptHideUnitInfoPanel) */
#define MAPCONFIG_INFO_PANEL 0x0400 /* bit 10 of MAPCONFIG_FLAGS: the map-view unit info panel is shown; a map script may show and hide it (DrawUnitInfoPanel) */
#define MAPCONFIG_INFO_PANEL 0x0400 /* bit 10 of MAPCONFIG_FLAGS: the cursor info panel is drawn (DrawUnitInfoPanel tests it; the map-script opcodes MapScriptShow/HideInfoPanel set and clear it) */
#define MAPCONFIG_UNBUILDABLE_KINDS 0x0C /* u32 per unit kind: a set bit means the map forbids building that kind (a map script sets and clears the bits) */
#define MAPCONFIG_INCOME    0x06 /* u16 funds each income-paying property adds to its owner's income per turn; the second value limit, MAP_SETTINGS_VALUE_HIGH */
#define MAPCONFIG_VALUE     0x04 /* u16 map-specific value: set from the map data (MapData record byte 0xD) and overridable by a map script (MapScriptSetMapValue) */

/* Packed per-map settings, saved with a slot and copied into the battle map and
 * gMapConfig by ApplyMapSettings. */
typedef struct MapSettings {
    MapSettingsPlayer players[4]; /* +0x00: per-player CO, army and team */
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
#define MAP_UNIT_AMMO_SHIFT 7    /* first bit of the ammo field in MAP_UNIT_AMMO */
#define MAP_UNIT_AMMO_MASK  0x780 /* the four ammo bits in MAP_UNIT_AMMO */
 #define MAP_UNIT_CAPTURE    0x06 /* u16: capture points in bits 11..15, 0 when the unit is not capturing (20 finishes it) */
 #define MAP_UNIT_CAPTURE_SHIFT 11   /* first bit of the capture-points field in MAP_UNIT_CAPTURE */
 #define MAP_UNIT_CAPTURE_MASK  0xf800 /* the five capture-point bits in MAP_UNIT_CAPTURE */
#define MAP_UNIT_FUEL       0x0A /* u8 fuel in the low seven bits */
#define MAP_UNIT_FUEL_MASK  0x7F /* the seven fuel bits of MAP_UNIT_FUEL */
#define MAP_UNIT_MOVE_PLANNED 0x80 /* bit 7 of the fuel byte: the AI has planned a move for the unit (SetMapCursor sets it) */
#define MAP_UNIT_CAPTURE_COMPLETE 20 /* capture points at which a property is captured */
#define MAP_UNIT_HEALTH_HEALTHY 61 /* lowest HP (0..100) the AI counts as healthy */
#define MAP_UNIT_CARRIED    0x0C /* u8 first carried unit, 0 if none */
#define MAP_UNIT_FIRST_CARRIED 0x0C /* u8 first unit this unit carries, 0 if none */
#define MAP_UNIT_NEXT_CARRIED 0x0D /* u8 next unit in the carry chain, 0 if none */
#define MAP_UNIT_TARGET     0x08 /* u16 packed AI move target: x in low six bits, y in bits 6..11 */
#define MAP_UNIT_NEED_STATE 0x08 /* u16: resupply/repair need in bits 12..13 (0 none, 1 resupply, 2 repair) */
#define MAP_UNIT_NEED_MASK   0x3000 /* bits 12..13 of MAP_UNIT_NEED_STATE */
#define MAP_UNIT_NEED_NONE   0x0000
#define MAP_UNIT_NEED_SUPPLY 0x1000
#define MAP_UNIT_NEED_REPAIR 0x2000
#define MAP_UNIT_TARGET_NONE 0x3F /* a target coordinate of 0x3f means "no target" */
#define MAP_UNIT_ACTION     0x08 /* u16 bits 14..15 of MAP_UNIT_TARGET: the AI's action state */
#define MAP_UNIT_ACTION_MASK 0xC000 /* bits 14..15 of MAP_UNIT_TARGET */
#define MAP_UNIT_AI_HAS_TARGET 0x20 /* u8 bit 5 of MAP_UNIT_AI_STATE: a move target is assigned */
#define MAP_UNIT_ACTION_NONE 0 /* the AI has chosen no action for the unit */
#define MAP_UNIT_ACTION_MOVE 1 /* the AI moves the unit to its target, then acts there */
#define MAP_UNIT_ACTION_STAY 2 /* the AI acts from where the unit stands */
#define MAP_UNIT_TARGET_X_MASK 0x003F /* low six bits of MAP_UNIT_TARGET: target x */
#define MAP_UNIT_TARGET_Y_MASK 0x0FC0 /* bits 6..11 of MAP_UNIT_TARGET: target y */
#define MAP_UNIT_TARGET_Y_NONE 0x0FC0 /* all six target-y bits set: no target */
#define MAP_DESTINATION_NONE 0x270F /* s16 destination-search sentinel: no tile found */
#define MAP_UNIT_AI_STATE   0x0B /* u8 low nibble AI step; bit 5 held while a move target is assigned */
#define MAP_UNIT_AI_STATE_MASK 0x0F /* low nibble of MAP_UNIT_AI_STATE */
#define MAP_UNIT_AI_KNOWN   0x40 /* u8 bit 6 of MAP_UNIT_AI_STATE: the AI knows where this unit is even without sight of its cell */
#define MAP_UNIT_KIND_MASK  0x3F /* low six bits of MAP_UNIT_KIND: the kind, the owner is above */
#define MAP_UNIT_OWNER_MASK  0xC0 /* top two bits of MAP_UNIT_KIND: the owner group */
#define MAP_UNIT_OWNER_SHIFT 6    /* player = (owner group >> this) + 1 */
#define MAP_UNIT_LIMIT       50   /* most units one player may have; the map editor refuses to place past it */

/* Unit kind ids the battle and command code names directly. */
#define UNIT_KIND_FLARE      5    /* Flare: fires a flare that reveals fog, spending ammo; available in fog or snow */
#define UNIT_KIND_SUBMARINE  22   /* submarine: can Dive and Surface, and is hidden while submerged */
#define UNIT_KIND_MOBILE_INDIRECT 20 /* the indirect kind that may move and fire in the same turn (IsMobileIndirectUnitKind) */
#define UNIT_DAMAGE_ROW_SUBMERGED 27 /* gUnitKindDamageTable row a submerged submarine is hit on */

/* One 16-byte entry of a map's unit deployment ("dispos") file, the list
 * file, the list PlaceMapDeployment places the map's units from.  Entries are
* read in order; MAP_DEPLOY_SWITCH_PLAYER starts the next player's block, MAP_DEPLOY_END ends
 * the list.  The carried-unit fields are 1-based indices into the units the
 * current player's block placed so far. */
#define MAP_DEPLOY_STRIDE        0x10
#define MAP_DEPLOY_SWITCH_PLAYER 0xfe /* x of the entry that selects the player the next entries belong to */
#define MAP_DEPLOY_END           0xff /* x of the entry that ends the list */

typedef struct MapDeploymentEntry {
    u8 x;           /* +0x00 tile x, or MAP_DEPLOY_* */
    u8 y;           /* +0x01 tile y (the player slot after a switch) */
    u8 kind;        /* +0x02 unit kind */
    u8 flags;       /* +0x03 per-unit flags (UNIT_FLAG_LOADED: the unit rides in a transport) */
    u8 owner;       /* +0x04 owner (player) of the unit */
    u8 health;      /* +0x05 starting HP */
    u8 ammo;        /* +0x06 starting ammo, capped by the kind's maximum */
    u8 fuel;        /* +0x07 starting fuel, capped by the kind's maximum */
    u8 firstCarried; /* +0x08 1-based index of the unit this unit carries, 0 if none */
    u8 nextCarried;  /* +0x09 1-based index of the next unit in the carry chain, 0 if none */
    u8 selected;    /* +0x0A nonzero to make the unit the player's selected unit */
    u8 unk0B;       /* +0x0B unused */
    u8 aiState;     /* +0x0C AI state (MAP_UNIT_AI_STATE) */
    u8 unkB4;       /* +0x0D copied to the unit's unkB4 bit */
    u8 targetX;     /* +0x0E AI target x for aiState 7..9, MAP_UNIT_TARGET_NONE when unset */
    u8 targetY;     /* +0x0F AI target y for aiState 7..9, MAP_UNIT_TARGET_NONE when unset */
} MapDeploymentEntry;

/* One entry of the battle map's target list: the unit on a cell (0 when the
 * cell holds none), a value that is the damage to deal when the cell holds a
 * unit or the visibility value when it does not, and the cell's position.  The
 * cursor code (main_0209F990.c) builds the list; GetTargetPosition walks it.
 * The list lives at gTargetList: +0x04 the MapTargetEntry array, +0x08 its count
 * and +0x00 a scratch buffer pointer. */
typedef struct MapTargetEntry {
    u16 id;    /* +0x00 unit id on the cell, 0 when there is none */
    u16 value; /* +0x02 damage to deal, or the cell's visibility value */
    s16 x;     /* +0x04 tile x */
    s16 y;     /* +0x06 tile y */
} MapTargetEntry;

/* The target list's own record (gTargetList): the array above and how many of its
 * entries are in use. */
typedef struct MapTargetList {
    void *scratch;           /* +0x00 scratch buffer pointer */
    MapTargetEntry *entries; /* +0x04 the MapTargetEntry array */
    s32 count;               /* +0x08 number of entries in use */
} MapTargetList;

/* Offsets inside gTargetList, for the code that addresses it as a byte buffer
 * (the global is only 4 bytes in config/, so its fields are reached that way). */
#define MAP_TARGET_LIST_ARRAY  0x04 /* MapTargetList.entries */
#define MAP_TARGET_LIST_COUNT  0x08 /* MapTargetList.count */

/* Per-unit flag bits in MAP_UNIT_FLAGS. */
#define UNIT_FLAG_ACTED      0x0001 /* the unit has acted this turn (HasUnitActed) */
#define UNIT_FLAG_CARRIED    0x0002 /* the unit is carried in a transport: it stands on no map cell */
#define UNIT_FLAG_MOVING     0x0004 /* the unit is playing its move animation: it is drawn even out of sight and the sight pass leaves its cell entry alone */
#define UNIT_FLAG_REPAIR     0x0100 /* unit is flagged for repair/resupply (drives a status icon) */
#define UNIT_FLAG_REPAIR_TMP 0x8000 /* scratch bit marking a repair neighbour during the repair pass */
#define UNIT_FLAG_LOADED     0x0008 /* unit is loaded in a transport (turn passes skip it) */
#define UNIT_FLAG_CARRYING   0x0010 /* the unit carries a unit: its carry chain is nonempty */
#define UNIT_FLAG_SUBMERGED  0x0020 /* a submarine is created with it and IsUnitSubmerged reads it: the unit is hidden (the same bit as UNIT_FLAG_FOG) */
#define UNIT_FLAG_TURN_MASK  0x0081 /* action bits cleared for every unit of the acting player at turn start */

/* Per-unit fog-of-war bits in MAP_UNIT_FLAGS. At the start of a turn the two
 * bits of UNIT_FLAG_FOG_MASK are cleared on every unit of a playing team and
 * UNIT_FLAG_VISIBLE is set again on the fogged enemy units in sight of the
 * viewing team (RefreshUnitVisibility). */
#define UNIT_FLAG_FOG      0x0020 /* the unit stands in fog: the visibility pass rechecks it */
#define UNIT_FLAG_VISIBLE  0x0040 /* the unit is in sight of team A */
#define UNIT_FLAG_VISIBLE_TEAM_B 0x0080 /* the unit is in sight of team B (a submerged unit a team-B player can move past) */
#define UNIT_FLAG_FOG_MASK 0x00C0 /* the two per-team visibility bits the sight pass resets */

/* The two battle-participant scratch records, 0x20 bytes each: the side that
 * starts the fight at MAP_BATTLE_ATTACKER, its opponent at MAP_BATTLE_DEFENDER.
 * Each begins with the BattleMapUnit * it was loaded from. */
#define MAP_BATTLE_ATTACKER 0x6eb8
#define MAP_BATTLE_DEFENDER 0x6ed8
#define MAP_BATTLE_STRIDE   0x20
#define MAP_BATTLE_WINNER   0x6ed6 /* s16: side that wins the previewed battle, 0 = no preview */
#define MAP_BATTLE_DAMAGE   0x6ed4 /* s16: damage the previewed attacker deals to its target */
/* The BattleUnit::health words of the two previewed sides (the AI target score
 * reads them to price the health each side loses). */
#define MAP_BATTLE_ATTACKER_HEALTH (MAP_BATTLE_ATTACKER + 0x0E) /* s16 attacker health after the preview */
#define MAP_BATTLE_DEFENDER_HEALTH (MAP_BATTLE_DEFENDER + 0x0E) /* s16 defender health after the preview */
#define MAP_BATTLE_ATTACKER_UNK1A  (MAP_BATTLE_ATTACKER + 0x1A) /* s16 BattleUnit::unk1A of the attacker */
#define MAP_BATTLE_DEFENDER_UNK1A  (MAP_BATTLE_DEFENDER + 0x1A) /* s16 BattleUnit::unk1A of the defender */
#define MAP_GRID            0x52e8 /* s8 *rows[64]: per-cell grid value; <0 impassable, >110 holds a unit */
#define MAP_GRID_ROW_INDEX  0x14ba /* MAP_GRID seen as an s8 * array: index of row y (MAP_GRID / 4) */
#define MAP_GRID_NO_UNIT_MAX 0x6E  /* largest MAP_GRID value of a cell that holds no unit */
#define MAP_GRID_HOLDS_UNIT  0x6F  /* MAP_GRID value marking a cell as holding a unit */
#define MAP_GRID_TAKEN       0x40  /* bit of a cell an attack range covers */
#define MAP_CELL_SCORE      0x2338 /* s8 per cell: influence/score layer (movement cost, danger range, ...) */
#define MAP_CELL_UNSET      0x7f   /* s8 marker FillMapLayer clears a cell layer to: no value computed yet */
#define MAP_CELL_LAYER_BYTES 0x508 /* bytes of one per-cell byte layer (the largest map's cell count) */
#define MAP_CELL_ORDER      0x1e30 /* s8 per cell: working order/overlay layer */
#define MAP_CELL_THREAT_DIRECT   0x2840 /* u8 per cell: threat from direct attackers */
#define MAP_CELL_THREAT_INDIRECT 0x2d48 /* u8 per cell: threat from indirect attackers */
/* gMapCellCornerColors: one u8 corner-colour code per map cell, stored
 * column-major ([x][y], MAP_CORNER_COLOR_STRIDE rows per column).  The map
 * renderer picks a cell corner's colour from the code; the terrain overlay pass
 * (func_02076980) leaves a cell alone once its code is MAP_CORNER_COLOR_RESERVED,
 * which PinMapCellCorners writes to reserve the corners of an effect cell. */
#define MAP_CORNER_COLOR_STRIDE   42 /* rows (cells) per column of gMapCellCornerColors */
#define MAP_CORNER_COLOR_RESERVED 7  /* corner code the overlay pass skips */
#define MAP_MODE            0x52b4 /* s16 current battle-map input state */
#define MAP_MODE_CURSOR     0      /* MAP_MODE value of the normal cursor handler (UpdateMapMode case 0) */
#define MAP_MODE_UNIT_SELECT 3     /* MAP_MODE value of the unit-selection handler (UpdateUnitSelectCursor) */
#define MAP_MODE_TARGET_CURSOR 5   /* MAP_MODE value of the map-target handler (UpdateMapTargetCursor): the action menu is open at the cursor tile */
#define MAP_MODE_CURSOR_SETTLE 10  /* MAP_MODE value of the cursor-settling handler (UpdateMapMode case 10): the cursor tracks its target, unit status icons stay hidden (RenderUnitAt mode 1) and the handler falls back to MAP_MODE_CURSOR once the cursor is idle. The map editor leaves it set on its terrain page. */
#define MAP_STATE           0x52b0 /* u16 battle-map state-machine step the per-frame dispatcher switches on */
#define MAP_RETURN_STATE    0x52b2 /* u16 state to go back to after a temporary submode (0 = none) */

/* Steps of the battle-map state machine (MAP_STATE), one run per frame by the
 * battle-map state dispatcher in main_020D3464.  15 and 17 are unused. */
enum {
    MAP_STATE_NONE             = 0,  /* no step running: the state dispatcher does nothing */
    MAP_STATE_TURN_LIMIT       = 1,  /* check the day limit, then schedule the next turn */
    MAP_STATE_ADVANCE_TURN     = 2,  /* advance the turn to the next active player */
    MAP_STATE_BEGIN_PHASE      = 3,  /* start the player's phase (BeginPlayerPhase) */
    MAP_STATE_TURN_START_WAIT  = 4,  /* wait for the turn-start transition to finish */
    MAP_STATE_TURN_START_SETUP = 5,  /* turn-start setup before the banner */
    MAP_STATE_TURN_START       = 6,  /* start-of-turn repairs and weather change */
    MAP_STATE_TURN_BANNER      = 7,  /* build the army-info window, pick the intro path */
    MAP_STATE_TURN_INTRO1      = 8,  /* first turn-intro sprite step */
    MAP_STATE_TURN_INTRO2      = 9,  /* second turn-intro sprite step */
    MAP_STATE_TURN_INTRO3      = 10, /* third turn-intro sprite step */
    MAP_STATE_TURN_INTRO_WAIT  = 11, /* wait out the turn intro, then begin the turn */
    MAP_STATE_PLAYER_TURN      = 12, /* begin the current player's turn (BeginPlayerTurn) */
    MAP_STATE_MAP_INPUT        = 13, /* run the map's input mode (UpdateMapMode) */
    MAP_STATE_AI_TURN          = 14, /* run the CPU turn (UpdateAiTurn) */
    MAP_STATE_RETURN           = 16, /* go back to MAP_RETURN_STATE */
    MAP_STATE_BATTLE_FINISH    = 18, /* finish the battle */
    MAP_STATE_LINK_TURN        = 19, /* replay another console's battle commands (UpdateLinkAiCommand) */
    MAP_STATE_RESUME_INPUT     = 20, /* resume the map's input mode */
    MAP_STATE_END_TURN         = 21, /* end the current player's turn */
    MAP_STATE_END_TURN_STEP    = 22, /* end-player-turn step (EndPlayerTurn) */
    MAP_STATE_OVERLAY_RESULT   = 23, /* show the overlay's (link/network) result sprites */
    MAP_STATE_AFTER_OVERLAY    = 24, /* resume the map after an overlay event */
    MAP_STATE_OVERLAY_CLEANUP  = 25, /* create the overlay-cleanup sprite */
    MAP_STATE_FINISH           = 26  /* wrap up the battle */
};

/* The map's interaction state as the battle HUD asks for it: whether the local
 * human player is driving the map and which kind of cursor is up. */
enum {
    MAP_INPUT_CURSOR    = 0, /* the human player's cursor is active */
    MAP_INPUT_MENU      = 1, /* a map menu is up */
    MAP_INPUT_NOT_HUMAN = 2, /* it is not the local human player's turn */
    MAP_INPUT_BLOCKED   = 3  /* a dialog, or any other state, blocks map input */
};
#define MAP_CURSOR_OWNER    0x52a8 /* u16 owner mask the unit under the cursor must match */
#define MAP_COMMAND_PENDING 0x52ac /* u8 nonzero while a map command is queued to run (Set/ClearMapCommandPending) */
#define MAP_CONFIRM_ENABLED 0x52ad /* u8 nonzero while the current map/choice is confirmed (IsMapConfirmEnabled) */
#define MAP_CURSOR_TARGET_X 0x52c2 /* s16 tile the cursor is aimed at */
#define MAP_CURSOR_TARGET_Y 0x52c4 /* s16 tile the cursor is aimed at */
#define MAP_CURSOR_CELL_DISPLAY_MODE 0x52e4 /* s16 cursor cell display mode */
#define MAP_CURSOR_CELL_UPPER 0    /* display mode: the cursor's tile is on the upper screen */
#define MAP_CURSOR_CELL_LOWER 0xA8 /* display mode: the cursor's tile is on the lower screen */
#define MAP_CURSOR_CELL_CACHE 0x52e6 /* u16 cached cursor-cell coordinates and flags */
#define MAP_CURSOR_CELL_X_SHIFT 2
#define MAP_CURSOR_CELL_Y_SHIFT 9
#define MAP_CURSOR_CELL_COORD_MASK 0x1FC
#define MAP_CURSOR_CELL_COORD_Y_MASK 0xFE00
#define MAP_CURSOR_CELL_FLAGS_MASK 0x0003
#define MAP_CURSOR_PIXEL_X  0x52c6 /* s16 smoothed cursor position, x in 1/16-cell units */
#define MAP_CURSOR_PIXEL_Y  0x52c8 /* s16 smoothed cursor position, y in 1/16-cell units */
#define MAP_CURSOR_TILE_UNITS 16 /* MAP_CURSOR_PIXEL_X/Y units per tile */
#define MAP_TILE_SIZE 768 /* 3 * 256: one map tile's on-screen size in pixels */
#define MAP_TOUCH_TILE_X    0x52ca /* s16 tile the current stylus press started on, 0xff when none */
#define MAP_TOUCH_TILE_Y    0x52cc
#define MAP_TOUCH_NO_TILE   0xff   /* MAP_TOUCH_TILE_X/Y value while no tile is touched */

/* Fields of the touch cursor sprite (class gTouchCursorClass), the ring the map
 * draws around the tile a stylus press started on. */
#define TOUCH_CURSOR_FRAME_TIMER 0x4C /* s16 frames the cursor's held state has run */
#define TOUCH_CURSOR_FRAME_LIMIT 8    /* frames after which the state resumes the cursor's animation */

/* The battle help/status panel state (gBattleHelpPanel): the page it shows, a flag
 * that the panel is up, and the cursor position saved around the panel's unit
 * cursor (SaveBattleCursorPosition saves it, RestoreBattleCursorPosition restores it). */
#define MAP_HELP_PAGE       0 /* u8 page/tile the panel shows, toggled by func_020c5b98 */
#define MAP_HELP_SHOWN      1 /* u8 nonzero while the panel covers part of the screen */
#define MAP_HELP_SAVED_X    2 /* s16 cursor old x saved while the panel's unit cursor runs */
#define MAP_HELP_SAVED_Y    4 /* s16 cursor old y */
#define MAP_TILE_SUBPIXEL   0x300  /* map-position units per tile, from ScreenToMapPosition */

/* The battle map's top-row touch buttons: three 32x16 buttons at y 0..0x10,
 * whose hit tests accept x in [start, start + MAP_TOP_BUTTON_SPAN]. */
#define MAP_TOP_BUTTON_Y_MIN  0
#define MAP_TOP_BUTTON_Y_MAX  0x10
#define MAP_TOP_BUTTON_LEFT    0x40 /* X/cancel button */
#define MAP_TOP_BUTTON_CENTER  0x70 /* A/confirm (next target) button */
#define MAP_TOP_BUTTON_RIGHT   0xA0 /* R/map-menu button */
#define MAP_TOP_BUTTON_SPAN    0x20

/* Action flags shared by map keyboard and stylus input. */
enum {
    MAP_ACTION_CONFIRM = 0x10,
    MAP_ACTION_CANCEL = 0x20,
    MAP_ACTION_CLOSE = 0x40,  /* X: close the aiming cursor */
    MAP_ACTION_MENU = 0x100   /* R: open the map menu */
};

/* The three 32x16 touch buttons along the top of the lower screen, all at
 * y 0..0x10: left (cancel/back) at x 0x40..0x60, middle (confirm, or "next
 * target" while picking a target) at 0x70..0x90, right (map menu) at 0xA0..0xC0. */
#define MAP_BUTTON_ROW_Y0    0
#define MAP_BUTTON_ROW_Y1    0x10
#define MAP_BUTTON_LEFT_X0   0x40
#define MAP_BUTTON_LEFT_X1   0x60
#define MAP_BUTTON_MIDDLE_X0 0x70
#define MAP_BUTTON_MIDDLE_X1 0x90
#define MAP_BUTTON_RIGHT_X0  0xA0
#define MAP_BUTTON_RIGHT_X1  0xC0
#define MAP_PREVIEW_UNIT_TILE_BASE 19 /* gTileGfxRowOffset index of the first unit-marker tile row */

/* gMapPreviewPalettes: staging data for the map preview, three 16-colour
 * palettes (u16[16] each, 0x20 bytes apart).  The first is copied into the OBJ
 * palette slot the preview was last drawn with (gMapPreviewPaletteSlot); the
 * third is the cursor colour ramp, one colour per animation frame, whose
 * current entry replaces colour 14 of that slot. */
#define MAP_PREVIEW_PALETTE     0x00 /* u16[16] the preview's own palette */
#define MAP_PREVIEW_CURSOR_RAMP 0x40 /* u16[16] per-frame cursor colours */
#define MAP_PREVIEW_CURSOR_COLOR 14  /* colour of the preview palette the ramp rewrites */

/* A map-preview layer sprite (created by DrawMapPreview, one per layer): over a
 * 64-frame cycle it copies the map's top half into its VRAM layer, then the bottom
 * half, and later stamps the visible units' markers. */
#define MAP_PREVIEW_SPRITE_VRAM  0x34 /* s32: VRAM offset the layer's tiles are copied to */
#define MAP_PREVIEW_SPRITE_FRAME 0x6C /* s16: per-frame counter driving the copies */
#define MAP_PREVIEW_FRAME_MASK   0x3F /* the counter wraps every 64 frames */
#define MAP_PREVIEW_FRAME_TOP    0    /* copy the map's top half */
#define MAP_PREVIEW_FRAME_BOTTOM 1    /* copy the map's bottom half */
#define MAP_PREVIEW_FRAME_UNITS  22   /* stamp a marker for every visible unit */

/* The battle map's per-player states: five 0x8c-byte records at map+0x67a4.
 * Player 0 is team A's base player and player 1 team B's; the remaining players
 * are allies sharing one of those armies (see MAP_TEAM_A_PLAYER / MAP_TEAM_B_PLAYER). */
#define MAP_PLAYER_STATES  0x67a4
#define MAP_PLAYER_STRIDE  0x8c

/* The on-map player unit view: one sprite object per player (created by
 * CreatePlayerUnitView from class gPlayerUnitViewClass at main_020BCB94.c) that
 * walks that player's 51 unit slots and draws the units as a rotating display;
 * StartPlayerUnitView and UpdatePlayerUnitView drive it.  These fields come after
 * the plain 3D sprite object fields. */
#define PLAYER_UNIT_VIEW_PLAYER  0x5C /* s32 player whose units the view shows */
#define PLAYER_UNIT_VIEW_SET     0x64 /* s32 sprite set/variant the view uses */
#define PLAYER_UNIT_VIEW_VARIANT 0x68 /* s32 random model variant of the view */
#define PLAYER_UNIT_VIEW_FRAME   0x6C /* s16 frames the view has been running */
#define PLAYER_UNIT_VIEW_SLOT    0x70 /* s16 unit slot the view is showing, 0..50 */

/* Map scripts are arrays of MAP_SCRIPT_COMMAND_SIZE-byte commands, run by the
 * opcode handlers in main_02092DF4.  The interpreter state keeps the block at
 * +0, the command being run at +4 and a wait callback at +8; a command holds
 * s16 operands at +8 and +10 and a s32 operand at +0x0C. */
#define MAP_SCRIPT_COMMAND_SIZE 0x10
#define MAP_SCRIPT_COMMAND_OPCODE 0x00 /* s32 opcode of a command */
#define MAP_SCRIPT_OP_END       7  /* terminator command: the block ends here */
#define MAP_SCRIPT_OP_LABEL     29 /* label command: names a jump target in MAP_SCRIPT_OPERAND2 */
#define MAP_SCRIPT_OP_MESSAGE   0x6B /* a message command: the script-skip command seeks to the next one, or to the end */
#define MAP_SCRIPT_PLAYER_CURRENT 5 /* player operand meaning "the player whose turn it is" (MapScriptResolvePlayer) */
#define MAP_SCRIPT_PARAM        0x04 /* opcode-specific word of the current command (a callback or a sprite class) */
#define MAP_SCRIPT_STATE_BLOCK  0x00 /* the script block being run; MapScriptFindLabel scans its commands */
#define MAP_SCRIPT_STATE_IP     0x04
#define MAP_SCRIPT_STATE_WAIT   0x08 /* wait callback run each frame while the command runs; 0 finishes it */
#define MAP_SCRIPT_STATE_PLAYER 0x11 /* u8 player id the wait command targets */
#define MAP_SCRIPT_STATE_TURN   0x12 /* s16 map turn the wait command waits for, -1 for any */
#define MAP_SCRIPT_STATE_DELAY  0x0C /* u16 frames left to wait before the next command runs (same slot as DialogSequence.delay) */
#define MAP_SCRIPT_OPERAND0     0x08 /* s16 first operand of the current command */
#define MAP_SCRIPT_OPERAND1     0x0A /* s16 second operand */
#define MAP_SCRIPT_OPERAND2     0x0C /* s32 wide operand */
#define PLAYER_REC_FUNDS   0x00 /* s32 funds: builds cost ten times the unit's price */
#define PLAYER_REC_FUNDS_SPENT 0x04 /* s32 total funds the player has spent */
#define PLAYER_FUNDS_SPENT_MAX 999999999 /* cap of PLAYER_REC_FUNDS_SPENT */
#define PLAYER_FUNDS_MAX 999999 /* funds saturate at the six-digit display maximum */
#define PLAYER_REC_INCOME  0x08 /* s32 funds the player's properties pay it per turn */
#define PLAYER_FUNDS_OFF (MAP_PLAYER_STATES + PLAYER_REC_FUNDS) /* s32 funds of a player record */
#define PLAYER_INCOME_OFF (MAP_PLAYER_STATES + PLAYER_REC_INCOME) /* s32 per-turn income of a player record */
#define PLAYER_REC_SPRITE  0x6C /* u32 unit-sprite state: low byte army id, small bitfields select the sprite tables */
#define PLAYER_ARMY_VARIANT_MASK 0x0C00 /* bits 10..11 of PLAYER_REC_SPRITE: the army's sprite variant, also its active CO power level (GetPlayerArmyVariant) */
/* The player's CO power meter is packed into bits 21..31 of PLAYER_REC_SPRITE:
 * GetCoPowerMeterPoints reads it and SetCoPowerMeterPoints writes it; charging it adds
 * points clamped to the player's dual-power cost. */
#define PLAYER_CO_METER_SHIFT 21 /* bits 21..31 of PLAYER_REC_SPRITE: CO power meter points */
#define PLAYER_CO_METER_MASK  0x1FFFFF /* the low 21 bits of PLAYER_REC_SPRITE, kept when the meter is rewritten */
#define PLAYER_SPRITE_SET_MASK 0x3000 /* bits 12..13 of PLAYER_REC_SPRITE: the sprite set/variant its unit views use */

/* The PLAYER_REC_SPRITE word read as its bitfields: the player's army id (the row
 * of the army data table the CO-zone code looks up), whether the player's CO
 * power is running and the sprite set.  Only the low fourteen bits are described:
 * the CO power meter sits above them (PLAYER_CO_METER_SHIFT). */
typedef struct PlayerSpriteBits {
    u32 armyId : 8;      /* bits 0..7: the player's army (CO) id */
    u32 unk8 : 2;        /* bits 8..9 */
    u32 powerActive : 2; /* bits 10..11: nonzero while the player's CO power is active */
    u32 spriteSet : 2;   /* bits 12..13: sprite set/variant the player's unit views use (GetPlayerSpriteSet) */
} PlayerSpriteBits;

/* A player record's head up to its PLAYER_REC_SPRITE word, so code that reads
 * that word can address the record as a struct. */
typedef struct PlayerRecordSprite {
    u8 pad[PLAYER_REC_SPRITE]; /* the record's other fields */
    PlayerSpriteBits sprite;   /* bits of the PLAYER_REC_SPRITE word */
} PlayerRecordSprite;
/* Power selector for GetCoPowerMeterCost: which of a commander's powers' star cost to read. */
#define CO_POWER_LEVEL_NONE 0
#define CO_POWER_LEVEL_CO   1
#define CO_POWER_LEVEL_DUAL 2
#define PLAYER_REC_SELECTED_UNIT 0x70 /* u8 id of the player's selected unit, 0 = none */
#define PLAYER_REC_SELECTION_ENABLED 0x71 /* u8 nonzero while the player may pick a unit; set at the start of its turn while it has none selected, cleared with its selection state */
#define PLAYER_SELECTION_ENABLED_OFF (MAP_PLAYER_STATES + PLAYER_REC_SELECTION_ENABLED) /* u8 nonzero while the player may pick a unit */
#define PLAYER_REC_PROPERTIES 0x18 /* u8 properties (cities/bases/HQ) the player owns, recounted when the map loads */
#define PLAYER_REC_SKIP_TURN 0x19 /* u8 nonzero: the turn-start step skips this player's turn */
/* Per-kind property counters of a player record, recounted with
 * PLAYER_REC_PROPERTIES at the start of a turn (main_020D2470): bases
 * (terrain kind 17), kind 16, HQs (18), ports (19), attack properties (22),
 * kind 23, airports (20) and kind 21.  Cities only add income and are not
 * counted here. */
#define PLAYER_REC_PROPERTY_COUNTS 0x10 /* u8[8] property counts by kind */
#define PLAYER_REC_KIND_COUNT     8
#define PLAYER_REC_ATTACK_PROPERTIES 0x14 /* u8 attack-boosting properties the player owns (terrain kind 22), 5 percent attack each */
#define PLAYER_ATTACK_PROPERTIES_OFF (MAP_PLAYER_STATES + PLAYER_REC_ATTACK_PROPERTIES) /* u8 */
#define PLAYER_REC_DEFEAT_TURN   0x1A /* u16 turn the player was defeated on, 0 while still in the battle (IsPlayerActive) */
#define PLAYER_REC_DEFEAT_REASON 0x1C /* u8 why the player was defeated: 8, 0x10, 1 or 2, the victory-rule flag that removed them */
#define PLAYER_DEFEAT_PROPERTIES 0x20 /* PLAYER_REC_DEFEAT_REASON: fewer properties than the winner at the turn limit */
/* PLAYER_REC_DEFEAT_REASON values: each is the victory-rule flag that removed the player. */
#define PLAYER_DEFEAT_GAVE_UP    8    /* the player's give-up flag is set: the AI resigned or a team-mate was defeated first */
#define PLAYER_DEFEAT_HUMAN      0x10 /* a human player is left without units and properties (rule flag 0x10) */
#define PLAYER_DEFEAT_NO_UNITS   1    /* the player is left without units and properties (rule flag 1) */
#define PLAYER_DEFEAT_LOST       2    /* the player's lost flag is set (rule flag 2) */
#define PLAYER_REC_CTRL    0x1E /* u8 PLAYER_CONTROL_*, within a record */
#define PLAYER_REC_UNITS_DESTROYED 0x20 /* u16 enemy units this player has destroyed, saturating at 0xFFFF (AddPlayerUnitDestroyed) */
#define PLAYER_REC_ENEMIES_DESTROYED 0x20 /* u16 saturating count of opposing-team units this player has destroyed (bumped when a battle kills one) */
#define PLAYER_REC_ENEMY_UNITS 0x22 /* u16 running total of the opposing team's units */
#define PLAYER_REC_DEFENSE_BONUS 0x24 /* s8 flat terrain-defense points this player's units add; reset each turn (ResetPlayerTurnBonuses) */
#define PLAYER_DEFENSE_BONUS_OFF (MAP_PLAYER_STATES + PLAYER_REC_DEFENSE_BONUS) /* s8 */
#define PLAYER_REC_UNIT_COUNT  0x31 /* u8 units the player has alive */
#define PLAYER_REC_UNIT_OWNER  0x32 /* u8 low two bits: owner group stamped into MAP_UNIT_KIND of the units the player creates (allies share one) */
#define PLAYER_REC_UNIT_KIND_COUNT 27 /* entries in a player's per-kind unit tallies: one per unit kind (the kind byte's low six bits) */
#define PLAYER_REC_UNITS_BUILT 0x33 /* u8[PLAYER_REC_UNIT_KIND_COUNT] per unit kind: units the player has built so far (AddPlayerUnitKind) */
#define PLAYER_REC_UNITS_LOST  0x4E /* u8[PLAYER_REC_UNIT_KIND_COUNT] per unit kind: the player's units that have been destroyed (bumped when one dies) */
#define PLAYER_REC_SIDE    0x1F /* u8 SIDE_*, within a record */
#define PLAYER_REC_CROSS_ALL 0x1F /* u8 bits: terrain the player's units may enter regardless of movement type */
#define PLAYER_REC_ARMY    0x26 /* u8 army (nation) id, within a record */
#define PLAYER_REC_PROPERTY_ARMY 0x1D /* u8 1-based army id that owns the player's properties (property records), 0 = none */
#define PLAYER_REC_ARMY_INDEX 0x1D /* u8 1-based army index that picks its colour */
#define PLAYER_REC_ARMY_STATE 0x27 /* u8 per-player army state shown by the army info window */
#define PLAYER_REC_CURSOR_X  0x2D /* u8 tile x the map cursor was left on */
#define PLAYER_REC_CURSOR_Y  0x2E /* u8 tile y the map cursor was left on */
#define PLAYER_REC_GAVE_UP   0x2F /* u8 give-up flag: the AI resigned, or a team-mate was defeated first */
#define PLAYER_REC_LOST      0x30 /* u8 lost flag: the player's HQ was captured */
#define PLAYER_REC_TURN_TIME 0x88 /* u32 elapsed turn time in frames (0 when untimed) */
#define PLAYER_REC_AI_MODE    0x2A /* u8 AI behaviour mode (0..3) */
#define PLAYER_REC_HQ_X       0x2B /* u8 HQ tile x in the low seven bits; bit 7 set when the player has no HQ */
#define PLAYER_REC_HQ_Y       0x2C /* u8 HQ tile y in the low seven bits */
/* Battle-rating accumulators of a player record, updated as fights resolve. */
#define PLAYER_REC_DAMAGE_DEALT  0x74 /* s32 total damage this player's attacks dealt */
#define PLAYER_REC_ATTACK_COUNT  0x78 /* s32 number of attacks this player made */
#define PLAYER_REC_KILL_DAMAGE   0x7C /* s32 damage of attacks that left the target at 0 HP */
#define PLAYER_REC_BATTLE_COUNT  0x80 /* s32 number of fights this player took part in */
#define PLAYER_REC_TOTAL_TIME    0x84 /* u32 saturating total frames this player's clock has run while the turn timer is enabled */
#define PLAYER_DAMAGE_DEALT_OFF (MAP_PLAYER_STATES + PLAYER_REC_DAMAGE_DEALT)
#define PLAYER_ATTACK_COUNT_OFF (MAP_PLAYER_STATES + PLAYER_REC_ATTACK_COUNT)
#define PLAYER_BATTLE_COUNT_OFF (MAP_PLAYER_STATES + PLAYER_REC_BATTLE_COUNT)
#define PLAYER_CONTROL_OFF (MAP_PLAYER_STATES + 0x1E) /* u8 PLAYER_CONTROL_* */
#define PLAYER_ENEMY_UNITS_OFF (MAP_PLAYER_STATES + PLAYER_REC_ENEMY_UNITS) /* u16 opposing team's unit total */
#define PLAYER_UNIT_COUNT_OFF (MAP_PLAYER_STATES + PLAYER_REC_UNIT_COUNT) /* u8 units the player has alive */
#define PLAYER_SIDE_OFF    (MAP_PLAYER_STATES + 0x1F) /* u8 SIDE_* */
#define PLAYER_ARMY_OFF    (MAP_PLAYER_STATES + 0x26) /* u8 army (nation) id */
#define PLAYER_ARMY_INDEX_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_INDEX) /* u8 */
#define PLAYER_ARMY_STATE_OFF (MAP_PLAYER_STATES + PLAYER_REC_ARMY_STATE) /* u8 */
#define PLAYER_TURN_TIME_OFF (MAP_PLAYER_STATES + PLAYER_REC_TURN_TIME) /* u32 elapsed turn time in frames */
#define PLAYER_REC_FLIP        0x28 /* u8 nonzero when this player's unit sprites are mirrored horizontally */
#define PLAYER_REC_SPRITE_STATE 0x29 /* u8 cached 0/1 state that picks the unit sprite variant (GetUnitVariantIndex) */
#define PLAYER_FLIP_OFF (MAP_PLAYER_STATES + PLAYER_REC_FLIP) /* u8 */
#define PLAYER_SPRITE_STATE_OFF (MAP_PLAYER_STATES + PLAYER_REC_SPRITE_STATE) /* u8 */
#define PLAYER_HQ_X_OFF (MAP_PLAYER_STATES + PLAYER_REC_HQ_X) /* u8 HQ tile x; bit 7 set when the player has no HQ */
#define MAP_TEAM_A_PLAYER  0x52b8 /* s16 id of the player team A's army belongs to */
#define MAP_TEAM_B_PLAYER  0x52ba /* s16 id of the player team B's army belongs to */

/* The per-army (CO) data table at gMovementCostTable, one 0x9c-byte block per
 * army id: +0x00 is the s32 localized name text id, +0x64 the s8 * movement
 * cost table for the army's current weather and variant. */
#define ARMY_DATA_UNLOCK_MAP 0x24 /* u16 map id whose completion unlocks this CO (0 for the initial COs) */
#define ARMY_DATA_SIZE 0x9c
#define ARMY_DATA_NAME 0x00
#define ARMY_DATA_QUOTE_TEXT_IDS 0x28 /* s32[ARMY_DATA_QUOTE_COUNT] the CO's quote-line text ids */
#define ARMY_DATA_QUOTE_COUNT 3      /* quote lines per CO; one is picked at random */
#define ARMY_DATA_MOVE_COSTS 0x64 /* s8 **[variant][row]: per-terrain cost rows, 32 bytes per movement type */
#define ARMY_DATA_VARIANT_STRIDE 0x28 /* bytes between movement-cost variants */
#define ARMY_DATA_ROW_STRIDE 4 /* bytes between cost-table rows within a variant */
#define ARMY_REC_ARMY_ID 0x6c /* u8 low byte of PLAYER_REC_SPRITE (i.e. player record +0x6c): the player's army id, a row of the army data table */
#define ARMY_TILE_BYTES 0x80 /* bytes of 4bpp tile data in one army state's face icon */
#define PLAYER_REC_MOVE_COST_ROW 0x25 /* u8 row of the army's movement-cost variant */

/* Army id the weather rules leave alone: no rain movement penalty, no sandstorm damage penalty. */
#define ARMY_WEATHER_IMMUNE 10

/* CO-zone bonuses (the gCoZone* field symbols): one 0x48-byte record per
 * commander and power state, selected by GetCoZoneBonusIndex() as
 * (commander - 1) * 2 + powerActive.  A record holds the zone's percentages at
 * +0x00 (s8 move), +0x04 (s8 range), +0x06 (s16 attack) and +0x08 (s16
 * defense), then one byte per unit kind at +0x0F saying whether the
 * commander's zone boosts that kind, and a second per-kind table at +0x2A
 * saying whether the kind may be selected for orders.  The field symbols point
 * at record 0; later records follow every CO_ZONE_RECORD_STRIDE bytes. */
#define CO_ZONE_RECORD_STRIDE 0x48
#define CO_ZONE_KIND_COUNT    27
#define CO_ZONE_MOVE_PCT      0x00 /* s8 movement bonus */
#define CO_ZONE_RANGE_PCT     0x04 /* s8 maximum attack range bonus, for kinds with range 2 or more */
#define CO_ZONE_ATTACK_PCT    0x06 /* s16 attack percent, damage scales by (100 + n) / 100 */
#define CO_ZONE_DEFENSE_PCT   0x08 /* s16 defense percent, damage scales by 100 / (100 + n) */
#define CO_ZONE_BASE_MOVE     0x0A /* s8 base move range the commander's zone grants (before the charged meter levels) */
#define CO_ZONE_KIND_ENABLED  0x0F /* s8[CO_ZONE_KIND_COUNT]: nonzero when the kind receives the zone bonus */
#define CO_ZONE_KIND_SELECTABLE 0x2A /* s8[CO_ZONE_KIND_COUNT]: nonzero when the kind may be selected for orders */

/* gCurrentMap[2] points to the three-slot pool of active unit-move controllers:
 * a byte is nonzero while the controller with that slot exists. */
#define MAP_UNIT_MOVE_SLOTS 0x08
/* The four block pointers held in gCurrentMap, as byte offsets (gCurrentMap[0..3]). */
#define MAP_DATA_PTR        0x00 /* the runtime battle map (the MAP_* fields) */
#define MAP_VIEW_PTR        MAPVIEW_CONTROLLER_INDEX * 4 /* the map-view controller */
#define MAP_UNIT_MOVE_PTR   0x08 /* the MAP_UNIT_MOVE_SLOTS pool */
#define MAP_EFFECT_PTR      0x0C /* the MAP_EFFECT_* state */

/* gCurrentMap[1] is the map-view controller: it owns the scroll task and gets
 * a callback run each time a scroll pan finishes. */
#define MAPVIEW_SCROLL_DONE 0x1c /* void (*)(void): run when a view pan reaches its target */
#define MAPVIEW_CURSOR_CB   0x08 /* void (*)(s16 x, s16 y, s32 kind): place a map cursor at a
                                 * 1/16-cell position; kind selects which cursor, MAP_CURSOR_KIND_* */
#define MAPVIEW_UPLOAD_GRAPHICS 0x54 /* void (*)(void): upload the map's tiles, terrain and army palettes */
#define MAPVIEW_SET_TERRAIN     0x58 /* void (*)(u8 weather, u8 tileset): apply the map's current
                                      * weather (MAP_WEATHER) and tileset (MAP_TILESET) to the view */
#define MAPVIEW_INIT_PRESENTATION 0x40 /* void (*)(void): prepare the map view before creating its sprites */
#define MAPVIEW_FRAME_CB        0x30 /* void (*)(void): run once per frame by the battle-map state dispatcher */
#define MAPVIEW_FRAME_TICK      0x2C /* void (*)(s32 frame): run once per frame with the frame counter
                                      * (the default view fades its palette with it) */
#define MAPVIEW_SETUP_CB        0x4c /* void (*)(void): set up the view's own data once a battle map has been loaded */
#define MAPVIEW_EMPTY_TILE_CB   0x44 /* void (*)(void): run when the cursor is aimed at an empty tile (no unit there);
                                      * StartEmptyTileSettle calls it before entering the settling mode */
#define MAPVIEW_RESTORE_CB      0x50 /* void (*)(void): reset the view's state before its presentation is rebuilt (save resume and view restore) */
#define MAPVIEW_ORDER_EFFECT    0x60 /* s32 nonzero while the view shows a map order's effect highlight */
/* The animation script of the map-order effect sprite is the view controller's
 * +0x5C pointer; the sprite is created as a child of another sprite and its
 * +0x6C slot holds the order effect it shows (0 = none).  The handlers in
 * main_020B0658 start, advance and reset the map's cell-raise highlight. */
#define MAPVIEW_ORDER_EFFECT_SCRIPT 0x5C /* void *the effect sprite's animation script */
#define MAPORDER_EFFECT_SPRITE_KIND  0x6C /* s16 order effect the sprite raises, 0 = none */
#define MAPVIEW_CONTROLLER_INDEX 1   /* index into gCurrentMap */
#define MAP_CURSOR_KIND_TARGET 2 /* cursor selector the target-cursor updater (main_020CBACC) passes */

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

/* Players are numbered 1..MAX_PLAYERS-1; player 0 means "none". */
#define MAX_PLAYERS 5

/* Battle outcome for one player, returned by GetPlayerResult. */
enum {
    BATTLE_RESULT_NONE = 0,
    BATTLE_RESULT_WIN  = 1,
    BATTLE_RESULT_LOSE = 2,
    BATTLE_RESULT_DRAW = 3
};

/* Relationship of one player towards another, returned by GetPlayerRelation. */
enum {
    PLAYER_RELATION_NONE  = 0, /* the other player is not in the battle */
    PLAYER_RELATION_ENEMY = 1, /* different army (nation) */
    PLAYER_RELATION_ALLY  = 2  /* same army (nation) */
};

/* The battle-results summary block (gBattleResults).  When a battle ends the
 * game lists the players by outcome and stores the winning player's ratings;
 * the results screen (overlay 5) lays its rows out from the player lists and
 * the counts that follow them. */
#define BATTLE_RESULTS_WINNERS    0x00 /* u8[4] players that won (BATTLE_RESULT_WIN) */
#define BATTLE_RESULTS_LOSERS     0x04 /* u8[4] players that lost (BATTLE_RESULT_LOSE) */
#define BATTLE_RESULTS_DRAWERS    0x08 /* u8[4] players that drew (BATTLE_RESULT_DRAW) */
#define BATTLE_RESULTS_WIN_COUNT  0x0c /* u8 entries used in BATTLE_RESULTS_WINNERS */
#define BATTLE_RESULTS_LOSE_COUNT 0x0d /* u8 entries used in BATTLE_RESULTS_LOSERS */
#define BATTLE_RESULTS_DRAW_COUNT 0x0e /* u8 entries used in BATTLE_RESULTS_DRAWERS */
#define BATTLE_RESULTS_SPEED      0x10 /* u8 speed rating of the winning player, 0..150 */
#define BATTLE_RESULTS_POWER      0x11 /* u8 power rating of the winning player, 0..150 */
#define BATTLE_RESULTS_TECHNIQUE  0x12 /* u8 technique rating of the winning player, 0..150 */
#define BATTLE_RESULTS_RANK       0x13 /* u8 grade of the total rating (GetRatingRank, 1..4) */
#define BATTLE_RESULTS_WINNER     0x14 /* u8 player the ratings were computed for */
#define BATTLE_RESULTS_TOTAL      0x16 /* u16 total of the three ratings, capped at BATTLE_RESULTS_TOTAL_MAX */
#define BATTLE_RESULTS_TOTAL_MAX   0x3E7 /* the sum of the three ratings saturates here */
#define BATTLE_RESULTS_TOTAL_LIMIT 0x3E8 /* the sum reaches this value: it is stored as BATTLE_RESULTS_TOTAL_MAX */
#define BATTLE_RESULTS_FLAGS      0x18 /* s32 flag word; its low 15 bits are cleared when the ratings are recomputed */

/* Grade boundaries of the winning player's total rating (GetRatingRank): the first
 * total that earns each grade; below BATTLE_RATING_GRADE2_MIN the grade is 1. */
#define BATTLE_RATING_GRADE2_MIN 200 /* 0xC8 */
#define BATTLE_RATING_GRADE3_MIN 250 /* 0xFA */
#define BATTLE_RATING_GRADE4_MIN 300 /* 0x12C */

/* Battle-end state (gBattleEndState): byte 0 is non-zero once the battle has
 * finished, bytes 1 and 2 are the end conditions, byte 3 qualifies byte 2. */
#define BATTLE_END_ENDED 0
#define BATTLE_END_FLAG1 1
#define BATTLE_END_FLAG2 2
#define BATTLE_END_FLAG3 3

/* Z-order carried by the battle-end screen's sprites (its banner and two
 * decorations); the screen counts as up once a sprite at this Z exists. */
#define BATTLE_END_SPRITE_Z 0xFF03
/* Field of the frame-callback task that removes the battle-end sprites: the Z of
 * the sprites it deletes (main_020D4430.c). */
#define BATTLE_END_TASK_Z  0x5C /* s32 */
/* Field of the battle map view's sprite object: nonzero while the map has a
 * frame waiting to be drawn (IsBattleMapFramePending, main_020D4430.c). */
#define BATTLE_MAP_FRAME_PENDING 0x5C /* s32 */

/* The battle-preview panel sprite (gBattlePreviewPanelDef, the class function
 * func_0209eaf4 creates) and the preview sprite built under it: the feature it
 * previews and the tile it was opened on. */
#define BATTLE_PREVIEW_UNIT 0x34 /* void *MapOrder feature it previews, 0 when it previews the tile */
#define BATTLE_PREVIEW_X    0x38 /* s32 tile x */
#define BATTLE_PREVIEW_Y    0x3C /* s32 tile y */
#define BATTLE_PREVIEW_ARMED 0x60 /* s32 nonzero when confirming the preview issues the battle command; 0 for a preview that only shows the forecast (the AI's own previews) */
#define BATTLE_PREVIEW_MODE 0x6c /* s16 the previewed feature's order type (MAP_ORDER_TYPE) */
#define BATTLE_PREVIEW_VALUE 0x6e /* s16 the previewed feature's value / remaining HP (MAP_ORDER_VALUE) */

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
#define MAPDATA_LINK_BATTLE 0x04 /* u8 nonzero when the battle runs over a link/online session (its overlay is polled) */
#define MAPDATA_OVERLAY_RESULT 0x05 /* u8 nonzero once the polled link/online overlay reported a finished event */
#define MAPDATA_EVENT_FLAGS 0x06 /* u8 nonzero when the overlay raised event flags */
#define MAP_MATCH_LABEL_Y 0x25c /* y the match name/status label is placed at on the battle map */
#define MAPDATA_MATCH_RESULT 0x07 /* u8 online matchmaking outcome written by the overlay poll: 1 = opponent found, 0 = failed */
#define MAPDATA_TURN_TIMER 0x08 /* u32 nonzero while the battle's per-frame time accumulation runs (EnableBattleTurnTimer) */
#define MAPDATA_RULES   0x0C /* u16 packed battle rule flags; bit 12 (0x1000) is CO powers enabled, cleared when the map forbids them, bit 13 (0x2000) selects army-specific movement costs instead of army 0's */
/* Bits 0..2 of MAPDATA_RULES: the kind of battle the map is played in, read
 * by IsCampaignBattleRules / IsFreePlayBattleMode / IsMapEditorMode. */
#define MAPDATA_MODE_MASK     0x0007 /* the low three MAPDATA_RULES bits */
#define MAPDATA_MODE_CAMPAIGN 0      /* a campaign (story) battle */
#define MAPDATA_MODE_FREE_PLAY 1     /* a free-play battle */
#define MAPDATA_MODE_MAP_EDITOR 2    /* the map editor's map view (EnterMapEditorScreen sets it) */
#define MAPDATA_DAY_LIMIT 0x0F /* u8 day limit: when a new day starts on this day (MAP_TURN) the battle ends, 0 = unlimited */
#define MAPDATA_TURN_TIME 0x10 /* u16 configured per-turn time limit in frames, 0 = untimed */

/* Map ids in this range are story missions with a rank entry in the per-map
 * progress table; the trial maps follow up to 0xE0. */
#define MAP_ID_STORY_FIRST 0xA1
#define MAP_ID_STORY_END   0xBB /* one past the last story mission */
#define MAP_ID_STORY_FINAL 0xBA /* the last story mission: the campaign's final battle */

/* Map ids in this range are campaign maps with a full 0x6f8-byte record. */
#define MAP_ID_CAMPAIGN_FIRST 0xE1
#define MAP_ID_CAMPAIGN_END   0x1A9 /* one past the last campaign map */

/* The campaign ids are divided into equal blocks by player slot: the block a
 * map id falls in, (id - MAP_ID_CAMPAIGN_FIRST) / MAP_ID_CAMPAIGN_PER_PLAYER,
 * is the slot of the player who owns it. */
#define MAP_ID_CAMPAIGN_PER_PLAYER 50
/* All campaign map headers: one MAP_ID_CAMPAIGN_PER_PLAYER block per player slot. */
#define CAMPAIGN_MAP_COUNT (MAP_ID_CAMPAIGN_END - MAP_ID_CAMPAIGN_FIRST)

/* The campaign map list's erase dialog (class gCampaignErasePanelClass): a modal panel
 * opened for the map chosen in the list; it clears that map's progress flags and
 * deletes its saved record. */
#define CAMPAIGN_ERASE_PANEL_MAP_ID 0x34 /* s32 campaign map id to erase */

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
    MapSettings settings; /* +0x30 map settings block (rules at record +0x38) */
    u8  stamp[0x14];    /* +0x40 date, checksum and console id stamp */
} MapRecordHeader;

/* The stamp of a saved map record (MAP_RECORD_STAMP, 0x14 bytes): when and on
 * which console it was saved, and the record's checksum. */
typedef struct MapRecordStamp {
    u8  pad00[6];
    u16 checksum; /* +0x06 MAP_RECORD_CHECKSUM of the record */
    u8  pad08[4];
    u32 word;     /* +0x0C MAP_RECORD_STAMP_WORD (counter and flags) */
    u32 playerId; /* +0x10 WFC player id of the console that saved the record */
} MapRecordStamp;

#define MAP_RECORD_NAME        0x06 /* char[0x21] map name, NUL terminated */
#define MAP_RECORD_MAGIC       0x20070731
#define MAP_RECORD_CHECKSUM    0x46 /* u16 CRC-16 of the record data (Crc16 from +0x54, 0x6A4 bytes) */
#define MAP_RECORD_DATA        0x54 /* start of the record data the checksum covers (terrain and units) */
#define MAP_RECORD_DATA_SIZE   0x6A4 /* bytes the checksum covers; MAP_RECORD_DATA + this = MAP_RECORD_SIZE */
#define MAP_RECORD_SAVE_SIZE   0x2AC /* compact saved record */
#define MAP_RECORD_SIZE        0x6F8 /* expanded runtime record */
#define MAP_RECORD_STAMP       0x40  /* u8[0x14] date, checksum and console id stamp */
#define MAP_RECORD_STAMP_WORD  0x4C  /* u32 stamp word: a ten-bit counter in bits 18..27, the map's
                                      * 1..5 star rating in bits 29..31 (SetCampaignMapRating), bit 28 unused */
#define MAP_RECORD_RATING_SHIFT 29   /* the rating's first bit in MAP_RECORD_STAMP_WORD */
#define MAP_RECORD_RATING_UNRATED 0  /* no rating yet: the map has not come in over a link */
#define MAP_RECORD_STAMP_COUNT_MAX 1000 /* the counter is not bumped past this */
#define MAP_RECORD_SAVE_UNITS  0x1E4 /* packed unit entries in the saved record */
#define MAP_RECORD_UNITS       0x3D8 /* packed unit entries in the runtime record */
#define MAP_RECORD_PLAYER_COUNT 0x27 /* u8; a map-selection slot holding 0 is empty */
#define MAP_RECORD_PLAYER_SLOTS 5    /* playerIds[] entries the record carries */

/* Fields of a per-map data record (0x50 bytes, MapData_GetRecord), the table the
 * map-selection code reads a map's settings from. */
#define MAP_DATA_RECORD_SIZE   0x50 /* bytes per record in the map data table */
#define MAP_DATA_RULE_FLAGS    0x04 /* u16 the map's rule bits, tested by the map-selection code */
#define MAP_DATA_RULE_FOG      0x0001 /* bit 0: the map forces fog of war on (MapData_IsFogOfWar) */
#define MAP_DATA_RULE_NO_CO    0x0002 /* bit 1: COs are off (MapData_HasNoCoRule): no army is assigned and unit selection is blocked */
#define MAP_DATA_RULE_RANDOM_PICK 0x0010 /* bit 4: the map takes part in random map selection (MapData_IsRandomSelectable) */
#define MAP_DATA_RULE_NO_PRODUCTION 0x0004 /* bit 2: owned production sites cannot be used (MapData_IsProductionDisabled) */
#define MAP_DATA_RULE_NO_ROUT 0x0008 /* bit 3: defeat by rout is off (MapData_HasNoRoutRule); the map suppresses the out-of-units result */
#define MAP_DATA_TILESET       0x06 /* u8 the map's tileset index (MapData_GetTileset) */
#define MAP_DATA_PLAYER_COUNT  0x09 /* u8 the number of armies the map is set up for */
#define MAP_DATA_CATEGORY      0x0A /* u8 the map-data category (MapData_GetCategory) */
#define MAP_DATA_MAP_VALUE     0x0D /* u8 the map-specific value, in MAP_DATA_MAP_VALUE_UNITs (scaled into MAPCONFIG_VALUE) */
#define MAP_DATA_MAP_VALUE_UNIT 0xE10 /* one unit of MAP_DATA_MAP_VALUE when stored in MAPCONFIG_VALUE */
#define MAP_DATA_VALUE_LIMIT_LOW  0x0E /* u8 low bound of the map's value, in MAP_DATA_VALUE_LIMIT_UNITs (MapData_GetValueLimitLow) */
#define MAP_DATA_VALUE_LIMIT_HIGH 0x0F /* u8 high bound of the map's value (MapData_GetValueLimitHigh) */
#define MAP_DATA_VALUE_LIMIT_UNIT 100  /* the value bounds are stored in units of 100 */
#define MAP_DATA_PLAYER_STATE  0x38 /* u8[4] per-player state used by campaign battles */
#define MAP_DATA_GRID_X        0x12 /* u8 the map's column in the map-selection grid (MAP_DATA_GRID_POS) */
#define MAP_DATA_GRID_Y        0x13 /* u8 the map's row in the map-selection grid */
#define MAP_DATA_PLAYER_CO_ID  0x1C /* u8[4] CO id assigned to each player slot, 0 = random, 15 = the map's own (GetMapPlayerCoId) */
/* One flags byte per player slot (GetMapPlayerFlags); bit 7 marks a player fighting
 * on the first player's side, bit 6 one whose units the cursor cannot select. */
#define MAP_DATA_PLAYER_FLAGS  0x3C /* u8[4] per-player flags */
#define MAP_PLAYER_FLAG_NO_SELECT 0x40 /* the player's units cannot be selected (CanSelectCursorUnit) */
#define MAP_PLAYER_FLAG_ALLY      0x80 /* the player is an ally of the first player (InitBattleMapConfig) */
#define MAP_DATA_PLAYER_CO_ID  0x1C /* u8[4] CO id assigned to each player slot (GetMapPlayerCoId) */
#define MAP_DATA_PLAYER_ID     0x20 /* u8[4] player id each player slot is assigned (GetMapPlayerId) */
#define MAP_DATA_PLAYER_ARMY   0x24 /* u8[4] army (nation) id assigned to each player slot (GetMapPlayerArmyId) */
#define MAP_DATA_PLAYER_MUSIC  0x28 /* s32[4] music track overriding the army's for each player slot, 0 = none (MapData_GetPlayerTrack) */
#define MAP_DATA_FOLLOWUP_MAPS 0x14 /* u16[4] map ids a cleared battle on this map unlocks, per player count slot */
#define MAP_DATA_EVENT_SCRIPT  0x44 /* void *the map's event-script block (GetMapEventScript) */

/* The map's event-script block (the per-map data record's MAP_DATA_EVENT_SCRIPT):
 * one compiled condition list per map event, each a pointer to 8-byte commands that
 * end with opcode 0x22.  The EvalScriptConditions wrappers in ov000_02169F94 run
 * one list per event. */
#define MAP_EVENT_TURN_START    0x08 /* run at the start of a player's turn (MAP_STATE_TURN_START_SETUP) */
#define MAP_EVENT_TURN_INTRO    0x0C /* run once the player's turn intro (army banner) has played (TurnIntro3Step, MAP_STATE_TURN_INTRO3); what the event stands for is not confirmed */
#define MAP_EVENT_UNIT_SELECTED 0x10 /* run with the unit a player just selected */
#define MAP_EVENT_BATTLE        0x14 /* run when a battle starts, with its attacker and defender (the MAP_BATTLE_* records) */
#define MAP_EVENT_CURSOR_UNIT   0x18 /* run with the unit under the battle cursor once its path is refreshed */
#define MAP_EVENT_UNIT          0x1C /* run for a unit lifecycle event: the first value is the event code (14 = unit built, 0x31 = unit destroyed, or a carried unit kind), the unit is the second */
#define MAP_EVENT_BATTLE_END    0x20 /* run when a battle ends (EnterBattleEnd, main_020C8CBC) */
#define MAP_EVENT_ENDING        0x24 /* run while the final campaign map's ending scene plays (state 7 of the ending sprite, ov004_02211200.c) */
#define MAP_EVENT_MAP_MENU      0x28 /* run when a map-menu action is taken (RunMapMenuEventCommand, main_020C5D0C.c); IsMapEventConditionMet tests the same list to enable the action */
#define MAP_EVENT_UNIT_GONE     0x2C /* run once a unit has left the map: after its removal effect destroyed or removed it (UnitRemoveEffect_Trigger, main_020B5258.c) */
#define MAP_EVENT_CURSOR_IDLE   0x30 /* run while the battle cursor rests (UpdateMapCursor, main_020D4430) */

/* A map-selection list: five runtime map records held one after another. */
#define MAP_RECORD_LIST_COUNT 5
#define MAP_RECORD_LIST_SIZE  0x22D8 /* MAP_RECORD_LIST_COUNT * MAP_RECORD_SIZE */

/* The task that fades the battle map in when the map view opens and out when it
 * closes: MapFadeInStep (main_020CBACC.c) bumps fadeTimer each frame while the
 * map is drawn, MapFadeOutStep counts it back down. */
typedef struct MapViewTask {
    u8  pad0[0x34];
    s16 fadeTimer; /* +0x34 fade-in/fade-out frame counter */
    s16 viewX;     /* +0x36 saved map view scroll x (MAP_VIEW_X) */
    s16 viewY;     /* +0x38 saved map view scroll y (MAP_VIEW_Y) */
    s16 unk3A;     /* +0x3A nonzero: recentre the cursor on the view's middle when it closes */
} MapViewTask;

/* Drawing a map cell with the 3D sprite engine.  The cell's
 * sprite id picks a script out of one of two tables, one per view zoom; the
 * matching graphics block lives at a fixed VRAM address.  A sprite id at or
 * above MAP_SPRITE_PART_MIN is drawn from a ring of parts around the cell. */
#define MAP_SPRITE_ZOOM_SMALL     16     /* cell size the view is drawn at when GetViewZoom <= 0 */
#define MAP_SPRITE_ZOOM_LARGE     24     /* ... and when it is above 0 */
#define MAP_SPRITE_GFX_ADDR_SMALL 0x21000 /* VRAM address of the small cell sprite graphics */
#define MAP_SPRITE_GFX_ADDR_LARGE 0x21980 /* VRAM address of the large cell sprite graphics */
#define MAP_SPRITE_GFX_SIZE_SMALL 0x30000 /* size of the small cell sprite graphics block */
#define MAP_SPRITE_GFX_SIZE_LARGE 0x20000 /* size of the large cell sprite graphics block */
#define MAP_SPRITE_TILE_DATA_SIZE 0x1440  /* size of the cell sprite's tile data block (stride 0x20) */
#define MAP_SPRITE_PALETTE        31      /* OBJ palette the cell sprites are drawn with */
#define MAP_SPRITE_CELL_SIZE      48      /* map-position units per cell (1/16-cell input * this) */
#define MAP_SPRITE_PART_MIN       20      /* first sprite id drawn from parts around the cell */
#define MAP_SPRITE_ATTR           0x8a1   /* z/attribute word of the drawn cell sprite */
#define MAP_SPRITE_PART_STEP      16      /* 1/16-cell units between the parts of the ring */

/* Script ids of the ring parts (MAP_SPRITE_PART_MIN + 0..7): the four sides and
 * then the four diagonal runs between them. */
enum {
    MAP_CELL_PART_TOP = MAP_SPRITE_PART_MIN,
    MAP_CELL_PART_BOTTOM,
    MAP_CELL_PART_LEFT,
    MAP_CELL_PART_RIGHT,
    MAP_CELL_PART_UP_LEFT,
    MAP_CELL_PART_UP_RIGHT,
    MAP_CELL_PART_DOWN_LEFT,
    MAP_CELL_PART_DOWN_RIGHT
};

/* The campaign map load queue (class gCampaignMapLoadQueueClass): a sprite the
 * campaign map screens create to have saved map records expanded into the
 * campaign map headers one per frame. Entries are appended by
 * AppendCampaignMapLoadEntry and consumed in order by LoadNextCampaignMapRecord
 * (the class's vtable step). */
#define CAMPAIGN_LOAD_QUEUE_COUNT   0x34 /* u8 entries queued */
#define CAMPAIGN_LOAD_QUEUE_INDEX   0x35 /* u8 entry being expanded */
#define CAMPAIGN_LOAD_QUEUE_IDS     0x36 /* u16[CAMPAIGN_LOAD_QUEUE_MAX] queued map ids */
#define CAMPAIGN_LOAD_QUEUE_RECORDS 0x4C /* MapRecordHeader *[CAMPAIGN_LOAD_QUEUE_MAX] queued records */
#define CAMPAIGN_LOAD_QUEUE_MAX     11   /* entries the queue holds (0x4C - 0x36 halves) */

/* The campaign map header loader (class gCampaignMapHeaderLoaderClass): a sprite
 * that clears and then loads the cached campaign map headers, one campaign map of
 * the player's fifty per frame.  Its +0x5C is the 0-based campaign map slot it is
 * loading next. */
#define CAMPAIGN_HEADER_LOAD_INDEX  0x5C /* s32 next campaign map index */

#endif
