/* The ov000 AI turn state, the block gAiState points at.  The AI walks its units
 * at the start of a turn, scores the army, and then decides unit-by-unit what it
 * wants to build and where the units should go. */
#ifndef OV000_AI_H
#define OV000_AI_H

#define AI_STATE_TARGET_COUNT  0x00 /* u8 number of target candidates (CollectAiTargetCandidates) */
#define AI_STATE_GROUP_COUNT   0x01 /* u8 number of target groups (BuildAiTargetGroups) */
#define AI_STATE_PHASE         0x02 /* u8 AI turn phase (state machine in ProcessAiTurnPlan) */
#define AI_STATE_PLACE_STEP    0x03 /* u8 built-unit placement step (0 idle, 1 panning to the tile, 2 waiting) */
#define AI_STATE_ACTION_CANDIDATE 0x04 /* u8 target candidate the current action uses */
#define AI_STATE_UNIT_COUNT_MAX 50 /* the AI's army is at its unit cap, so the turn plan stops */
#define AI_STATE_RESERVE_RETRY 0x05 /* u8 retries left to reserve money for a purchase */
#define AI_STATE_UNIT_COUNT    0x07 /* u8 friendly units counted this turn */
#define AI_STATE_INFANTRY_MECH 0x08 /* u8 the AI's infantry and mech units, denominator of the unit-type ratios */
#define AI_STATE_ACTION        0x0c /* u8 kind of the action being taken */
#define AI_STATE_ARMY_VALUE    0x10 /* s32 total value of the player's units */
#define AI_STATE_SHORTFALL     0x14 /* s32 money reserved for an unaffordable purchase */

/* Byte of gAiCommandState holding the number of distinct property target areas
 * the AI marked for this turn; 1 means a single area. */
#define AI_COMMAND_STATE_TARGET_AREAS 0x06

/* Extra infantry and mechs the AI wants beyond its weighted property count. */
#define AI_FOOT_UNIT_BUFFER_NO_TARGETS 1
#define AI_FOOT_UNIT_BUFFER_WITH_TARGETS 2

/* A packed AI priority byte: the low 7 bits are the magnitude, capped at
 * AI_SCORE_MAX, and bit 7 (AI_SCORE_FLAG) is an action-specific flag ORed on top
 * so a flagged value outranks any unflagged one. */
#define AI_SCORE_MAX  0x7f
#define AI_SCORE_FLAG 0x80

/* Values of AI_COMMAND_STATE_PHASE, driven by UpdateAiTurn (ov000_0219B848.c).
 * Phases 0..2 and 4 are stepped inside a task sprite running
 * ProcessAiCommandPhase until the phase leaves that set; 3, 5 and 6 are stepped
 * once per frame by UpdateAiTurn itself. */
#define AI_COMMAND_PHASE_START_TURN  0 /* begin the AI's turn (BeginAiTurn) */
#define AI_COMMAND_PHASE_PLAN_UNITS  1 /* run the turn plan's unit-selection step for the current AI_STATE_PHASE */
#define AI_COMMAND_PHASE_PICK_ACTION 2 /* pick the next AI unit's action */
#define AI_COMMAND_PHASE_ACT         3 /* carry out the picked command, frame by frame (ProcessAiCommandStep) */
#define AI_COMMAND_PHASE_PLAN_TURN   4 /* run the turn plan's order step for the current AI_STATE_PHASE */
#define AI_COMMAND_PHASE_PLACE_UNIT  5 /* place the unit the AI bought (AiPlaceBuildingUnit) */
#define AI_COMMAND_PHASE_END_TURN    6 /* end the AI's turn (EndAiTurn) */
#define AI_COMMAND_TASK_SPRITE_Z     6 /* z slot of the task sprite that runs the planning phases */

/* Values of gLinkAiCommandStage, the battle state's replay of a battle command
 * that another console broadcast (UpdateLinkAiCommand, main_02084304.c).  Idle
 * polls the current player's command queue; Busy steps the popped command with
 * ProcessAiCommandStep until the AI goes back to picking its next action. */
#define AI_COMMAND_STAGE_IDLE 0 /* no command queued for this player */
#define AI_COMMAND_STAGE_BUSY 1 /* a popped command is being carried out */

/* Fields of the AI command state used while a unit's action is chosen. */
#define AI_COMMAND_STATE_PHASE      0x00 /* u8 AI command phase (*gAiCommandState, dispatched by the AI state machine) */
#define AI_COMMAND_STATE_STEP       0x01 /* u8 step within the current phase */
#define AI_COMMAND_STATE_TIEBREAK   0x03 /* u8 random 0..99 chosen when an action starts, breaks score ties */
#define AI_COMMAND_STATE_MOVE_RANGE 0x05 /* u8 movement range of the acting unit */
#define AI_COMMAND_STATE_FLAGS      0x07 /* u8 AI action flags */
#define AI_COMMAND_STATE_ACTION_FLAGS 0x08 /* u16 action-planning flags */
#define AI_ACTION_SKIP_REPLAN 0x20 /* suppress the fallback callback in action finalization */
#define AI_ACTION_DESTINATION_CHOSEN 0x10 /* the acting unit's destination is chosen; finalization does not choose it again */
#define AI_ACTION_PRODUCTION_IMPROVED 0x08 /* a production tile's score improved, so the move is re-finalized */
#define AI_ACTION_CO_POWER 0x100 /* the action being planned is the AI's CO-power use */
#define AI_COMMAND_STATE_MODE       0x0A /* u16 bitfield word (3-bit fields at bits 3..5, 6..8, 9..11) */
/* Total property count of the players not on the current army's team, summed
 * at the start of the AI's turn (CountEnemyProperties). */
#define AI_COMMAND_STATE_ENEMY_PROPERTIES 0x04 /* u8 enemy property total */
#define AI_COMMAND_STATE_CAPTURE_PUSH     0x20 /* bit of the above: the enemies hold enough properties that infantry and mechs head straight for any property */
#define AI_COMMAND_STATE_ATTACKER   0x0C /* u8 kind of the unit the AI is evaluating an attack with */
#define AI_COMMAND_STATE_PLAYER     0x0D /* u8 player slot the AI is acting for */

/* The AI action's two unit-move objects are kept in the pointer slots just past
 * gAiCommandTimer (the same slots as data_ov000_021e146c[0] and [1]).  The step
 * that finishes an action deletes them once their movement is over. */
#define AI_COMMAND_MOVE_OBJECT_0 0x04 /* void * first unit-move object */
#define AI_COMMAND_MOVE_OBJECT_1 0x08 /* void * second unit-move object */

/* Fields of the command record gAiCommand (filled by the cursor code and the AI). */
#define AI_COMMAND_KIND    0x00 /* u8 kind of the command */
#define AI_COMMAND_ACTOR   0x01 /* u8 id of the unit giving the command */
#define AI_COMMAND_CURSOR_X 0x02 /* u8 cursor tile x when the command was given */
#define AI_COMMAND_CURSOR_Y 0x03 /* u8 cursor tile y when the command was given */
#define AI_COMMAND_OLD_X   0x04 /* u8 cursor tile x before the last move */
#define AI_COMMAND_OLD_Y   0x05 /* u8 cursor tile y before the last move */
#define AI_COMMAND_UNIT    0x06 /* u8 unit kind the command acts on */
#define AI_COMMAND_ARG_Y   0x07 /* u8 second command parameter (target tile y) */
#define AI_COMMAND_UNIT_STATE 0x07 /* u8 AI state a built unit starts with (same slot as AI_COMMAND_ARG_Y) */
#define AI_COMMAND_SEED    0x08 /* s32 random seed captured with the command */
#define AI_COMMAND_FUEL_LEFT 0x12 /* u8 fuel the acting unit has left after the move */
#define AI_COMMAND_READY   0x13 /* u8 set once the command record is complete */
/* One past the last valid AI_COMMAND_KIND: kinds 1..0x18 are commands, 0 and
 * above this are not (IsAiCommandKindValid). */
#define AI_COMMAND_KIND_LIMIT 0x19
#define AI_COMMAND_ATTACK_TARGET 4 /* attack the unit AI_COMMAND_UNIT names on the command tile */
#define AI_COMMAND_ATTACK_TILE   5 /* attack the tile AI_COMMAND_CURSOR_X/Y names */
#define AI_COMMAND_PRODUCE_UNIT 3 /* build the unit kind in AI_COMMAND_ACTOR at the command tile */
#define AI_COMMAND_SET_AI_MODE  24 /* set player AI_COMMAND_UNIT's AI behaviour mode to AI_COMMAND_ARG_Y */

enum AiCargoDropDirection {
    AI_CARGO_DROP_NONE = 0,
    AI_CARGO_DROP_UP = 1,
    AI_CARGO_DROP_RIGHT = 2,
    AI_CARGO_DROP_DOWN = 3,
    AI_CARGO_DROP_LEFT = 4,
    AI_CARGO_DROP_OCCUPIED = 5
};

/* Sentinels in gAiUnitList, the list of unit ids the current AI phase walks.
 * AI_UNIT_LIST_END finishes the walk; AI_UNIT_LIST_NO_UNIT is an entry with no
 * unit behind it (a build or other army-wide action) that just runs the
 * installed gAiUnitAction callback. */
#define AI_UNIT_LIST_END     0x00
#define AI_UNIT_LIST_NO_UNIT 0x40

/* The army value is scaled by 3/2 and never goes below this floor. */
#define AI_ARMY_VALUE_MIN      1000

/* Layout of one unit-kind record in gUnitKindStats. */
#define UNIT_KIND_STATS_SIZE   112 /* bytes per unit kind */
#define UNIT_KIND_STATS_CARGO_COUNT 0x60 /* u8 number of units the kind can carry (its cargo slots) */
#define UNIT_KIND_STATS_LOAD_CLASS  0x61 /* u8 the kind's carry class, a column in the load mask below */
#define UNIT_KIND_STATS_LOAD_MASK   0x62 /* u8 per load class: nonzero when the kind may be carried by a kind of that class */
#define UNIT_KIND_STATS_MOVE   0x08 /* u8 base movement range */
#define UNIT_KIND_STATS_AMMO   0x09 /* u8 maximum ammo (0 = the kind cannot attack) */
#define UNIT_KIND_STATS_INFINITE_AMMO 0x0B /* u8 nonzero when the kind's weapon uses no ammo (it can attack with ammo 0; the info panel then shows an infinity icon) */
#define UNIT_KIND_STATS_MAX_RANGE 0x0D /* u8 base maximum attack range: 0 cannot attack, 1 direct, above 1 indirect */
#define UNIT_KIND_STATS_MIN_RANGE 0x0C /* u8 minimum attack range (1 = direct unit) */
#define UNIT_KIND_STATS_FUEL   0x0E /* u8 maximum fuel */
#define UNIT_KIND_STATS_FLAGS  0x13 /* u8 unit-kind capability flags (used by the AI targeting/movement checks) */
#define UNIT_KIND_STATS_MOVETYPE 0x12 /* u8 movement type: first index of the terrain movement-cost row (gMovementTypeTable) */
#define UNIT_KIND_STATS_AI_ROLE  0x14 /* u8 AI role category (1..6) the per-role turn phases select units by */
#define UNIT_KIND_STATS_CAN_SUPPLY 0x69 /* u8 nonzero when the kind can resupply/repair adjacent units */
#define UNIT_KIND_STATS_SUPPLY_FLAG 0x6A /* u8 nonzero when the kind can be resupplied */
#define UNIT_KIND_STATS_CAPTURE_MASK 0x54 /* s8 *per terrain: nonzero when the kind may capture/enter that property */
#define UNIT_KIND_STATS_FUEL_COST    0x58 /* s8 *per-terrain: fuel the kind spends per turn standing there (negative = cannot stand) */
#define UNIT_KIND_STATS_UNK_6C       0x6C /* u8 nonzero when the save-load fix-up adjusts the kind's saved AI step */

/* Bits of gUnitKindFlags, the +0x13 flag byte of a unit-kind record (indexed
 * by kind * UNIT_KIND_STATS_SIZE).  The sea and air kinds are the ones that
 * are lost when their fuel reaches zero. */
#define UNIT_KIND_FLAGS_SEA  0x10 /* naval kind */
#define UNIT_KIND_FLAGS_AIR  0x20 /* air kind */
#define UNIT_KIND_FLAGS_FUEL_CRITICAL (UNIT_KIND_FLAGS_SEA | UNIT_KIND_FLAGS_AIR)

/* The AI steps in which a unit is carrying out the action it chose earlier: the
 * attack step resolves its attack, the capture step walks it onto the property.
 * The per-turn handlers run these; unit scans skip units that are in them. */
#define AI_STEP_FIRST       1 /* the action's first step: the influence maps are cleared, not built */
#define AI_STEP_ATTACK      6
#define AI_STEP_CAPTURE     8

/* Attack-distance rings added outside a movement flood fill start above its cost values. */
#define AI_THREAT_RING_FIRST 111

/* Highest search range GetAiUnitRange returns (it clamps scaled ranges to it);
 * GetAiUnitSearchRange returns it for a unit whose kind is 0 (no unit). */
#define AI_UNIT_RANGE_MAX 110

/* Unit kinds the battle and AI code names directly. */
#define UNIT_KIND_INFANTRY  1
#define UNIT_KIND_MECH      2
#define UNIT_KIND_TANK      7

/* The AI's counter-unit kind (BuildAiCounterUnit builds one when an enemy has
 * a unit of the class it answers).  An existing one is only considered usable
 * while it keeps at least half its health. */
#define AI_COUNTER_UNIT_KIND       14
#define AI_COUNTER_UNIT_MIN_HEALTH 50
#define UNIT_KIND_TRANSPORT 19
#define UNIT_KIND_SUBMARINE 22 /* created submerged and charged 5 fuel a turn while submerged */
#define UNIT_KIND_SUBMARINE_FUEL 5 /* fuel a submerged submarine spends per turn */

/* GetUnitThreatClass returns this for a kind the AI's threat table does not model. */
#define AI_THREAT_CLASS_NONE 10

/* An AI target candidate record, 12 bytes each. */
#define AI_CANDIDATE_X        0x00 /* u8 tile x */
#define AI_CANDIDATE_Y        0x01 /* u8 tile y */
#define AI_CANDIDATE_TYPE     0x02 /* u8 target type */
#define AI_CANDIDATE_STATUS   0x03 /* u8 AI_CANDIDATE_* status */
#define AI_CANDIDATE_GROUP    0x04 /* s8 target group */
#define AI_CANDIDATE_ENEMY_GROUP_DISTANCE 0x07 /* u8 distance to the closest enemy in the candidate's target group */
#define AI_CANDIDATE_STRIDE   12
#define AI_CANDIDATE_TYPE_ANY 4 /* wildcard used by candidate searches */
/* Candidate fields 0x05..0x0A are reused per target type.  On a property
 * candidate (type 2) the AI target-group scan files the number of enemy units
 * that can reach the tile and the distance to the closest of them. */
#define AI_PROPERTY_CANDIDATE_ENEMY_COUNT    0x06 /* u8 enemy units that can reach the tile */
#define AI_PROPERTY_CANDIDATE_ENEMY_DISTANCE 0x07 /* u8 Manhattan distance to the closest enemy (255 = none) */
/* Distances UpdateAiCandidateCosts files on a candidate: the closest of the
 * current player's capture units, and the closest unit that AI kind 24 can
 * attack while it is in state 2. 0xFF/0x7F means none was found. */
#define AI_CANDIDATE_CAPTURE_DISTANCE 0x09 /* u8 distance to the closest capture unit */
#define AI_CANDIDATE_ATTACK_DISTANCE  0x0A /* u8 distance to the closest attackable unit */
/* The remaining per-type fields, filled by UpdateAiCandidateCosts and the
 * property/unit scans: each holds the distance to the cheapest reachable goal of
 * its kind, 255 when there is none. */
#define AI_CANDIDATE_UNIT_BALANCE      0x05 /* s8 friendly minus enemy units that can reach the tile */
#define AI_CANDIDATE_PROPERTY_DISTANCE 0x08 /* u8 distance to the closest capturable property */
#define AI_CANDIDATE_CAPTURE_DISTANCE  0x09 /* u8 distance to the closest capturable current-player unit */
#define AI_CANDIDATE_COMBAT_DISTANCE   0x0A /* u8 distance to the closest unit a kind-24 unit can attack */
#define AI_CANDIDATE_FRESH    0x7f /* untouched candidate */
#define AI_CANDIDATE_REJECTED 0xfc /* candidate given up on */
#define AI_CANDIDATE_SKIPPED  0xfd /* candidate skipped this turn */

/* The AI's per-unit parameter data (BuildAiUnitParameters / SetupAiUnitParameters).
 * gAiUnitSetStats holds one AI_SET_STRIDE-byte set per AI unit set: a 12-byte header
 * followed by AI_UNIT_COUNT base/spread byte pairs, one per unit type.
 * gAiUnitTuningSets holds one AI_TUNING_STRIDE-byte tuning block per variant: an 8-byte
 * header, then AI_UNIT_COUNT records of AI_TUNING_RECORD bytes (a scale, two base/spread
 * pairs and two extra bytes).  The result is written into gAiSettings as AI_UNIT_RECORDS
 * AI_UNIT_RECORD_STRIDE-byte per-unit-type records preceded by an 8-byte header. */
#define AI_SET_STRIDE         64
#define AI_TUNING_STRIDE      192
#define AI_UNIT_COUNT         26
#define AI_UNIT_RECORDS       27
#define AI_UNIT_RECORD_STRIDE 12
#define AI_TUNING_RECORD      7

/* The unit set's 12 header bytes are copied to gAiSettings+8 .. +19. */
#define AI_SETTING_TRANSPORT_PERCENT   0x0B /* u8 wanted transports as a percentage of the infantry+mech count */
#define AI_SETTING_UNIT13_PERCENT      0x0C /* u8 wanted kind-13 units as a percentage of the infantry+mech count */
#define AI_SETTING_UNIT13_LAST_TURN    0x12 /* u8 last turn on which more kind-13 units are built */
#define AI_SETTING_TRANSPORT_LAST_TURN 0x13 /* u8 last turn on which more transports are built */
#define AI_SETTING_BUILD_FLAGS         0x11 /* u8 mask of the optional unit kinds the AI may build */
#define AI_BUILD_FLAG_UNIT_25          0x01 /* the AI may build unit kind 25 */
#define AI_BUILD_FLAG_UNIT_24          0x02 /* the AI may build unit kind 24 */

/* The two callbacks at the start of gAiSettings, before the per-kind records. */
#define AI_SETTINGS_UNIT_FILTER  0x00 /* s32 (*)(s32 commander, s32 unitKind): picks the kind of unit to act; NULL uses AiSettings_DefaultUnitFilter */
#define AI_SETTINGS_USE_CO_POWER 0x04 /* s32 (*)(void): whether to use the CO power now; NULL uses the default, AiCoPowerUnitIsHurt */

/* The per-kind records of gAiSettings start after its 8-byte header.  The record
 * index is the unit kind and record byte 0 is the kind's weight in the AI unit
 * set chosen for this match; 0 means that set does not build the kind. */
#define AI_SETTING_UNIT_RECORDS        0x08
#define AI_SETTING_UNIT_WEIGHT         0x00
#define AI_SETTING_UNIT(kind)          (AI_SETTING_UNIT_RECORDS + (kind) * AI_UNIT_RECORD_STRIDE + AI_SETTING_UNIT_WEIGHT)
/* Byte fields of one AI_UNIT_RECORD (AI_UNIT_RECORD_STRIDE bytes): the threats
 * above which the AI avoids a tile, and the fuel and health below which it sends
 * the kind off to be resupplied or repaired. */
#define AI_UNIT_RECORD_THREAT_DIRECT   0x01 /* u8 direct-threat limit */
#define AI_UNIT_RECORD_THREAT_INDIRECT 0x02 /* u8 indirect-threat limit */
#define AI_UNIT_RECORD_FUEL_PERCENT    0x03 /* u8 resupply below this fuel percentage */
#define AI_UNIT_RECORD_HEALTH          0x04 /* u8 repair below this health */

/* One AI target group record in gAiTargetGroups, 8 bytes each. */
#define AI_GROUP_SCORE       0x00 /* s8 value of the group, higher is better */
#define AI_GROUP_CLAIMED     0x01 /* u8 0xFF once the group can no longer be used */
#define AI_GROUP_PROPERTIES  0x02 /* u8 number of properties in the group */
#define AI_GROUP_FLAGS       0x03 /* u8 AI_GROUP_FLAG_* bits */
#define AI_GROUP_DIRECT_COMMITTED   0x04 /* u8 direct-attack units committed to the group */
#define AI_GROUP_INDIRECT_COMMITTED 0x05 /* u8 indirect-attack units committed to the group */
#define AI_GROUP_KIND26_COMMITTED   0x06 /* u8 kind-26 units committed to the group (also counted as indirect) */
#define AI_GROUP_STRIDE      8
#define AI_GROUP_FLAG_CLAIMED     0x01 /* a build already reserved the group */
#define AI_GROUP_FLAG_SEA_THREAT  0x02 /* an enemy sea unit threatens the group and no ready kind-6/14 unit is in it */
#define AI_GROUP_FLAG_PROPERTY    0x04 /* the group's best tile is worth capturing */

/* Bit 0x100 of the capture-target evaluation result: the group holds a kind-24/25
 * production site (a base or port), so its tile is not a capture target. */
#define AI_CAPTURE_EVAL_PRODUCTION_SITE 0x100

#endif
