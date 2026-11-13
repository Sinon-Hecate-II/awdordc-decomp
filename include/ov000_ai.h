/* The ov000 AI turn state, the block gAiState points at.  The AI walks its units
 * at the start of a turn, scores the army, and then decides unit-by-unit what it
 * wants to build and where the units should go. */
#ifndef OV000_AI_H
#define OV000_AI_H

#define AI_STATE_TARGET_COUNT  0x00 /* u8 number of target candidates (CollectAiTargetCandidates) */
#define AI_STATE_GROUP_COUNT   0x01 /* u8 number of target groups (BuildAiTargetGroups) */
#define AI_STATE_PHASE         0x02 /* u8 AI turn phase (state machine in ProcessAiTurn) */
#define AI_STATE_RESERVE_RETRY 0x05 /* u8 retries left to reserve money for a purchase */
#define AI_STATE_UNIT_COUNT    0x07 /* u8 friendly units counted this turn */
#define AI_STATE_INFANTRY_MECH 0x08 /* u8 the AI's infantry and mech units, denominator of the unit-type ratios */
#define AI_STATE_ACTION        0x0c /* u8 kind of the action being taken */
#define AI_STATE_ARMY_VALUE    0x10 /* s32 total value of the player's units */
#define AI_STATE_SHORTFALL     0x14 /* s32 money reserved for an unaffordable purchase */

/* Byte of gAiCommandState holding the number of distinct property target areas
 * the AI marked for this turn; 1 means a single area. */
#define AI_COMMAND_STATE_TARGET_AREAS 0x06

/* Fields of the AI command state used while a unit's action is chosen. */
#define AI_COMMAND_STATE_PHASE      0x00 /* u8 AI command phase (*gAiCommandState, dispatched by the AI state machine) */
#define AI_COMMAND_STATE_STEP       0x01 /* u8 step within the current phase */
#define AI_COMMAND_STATE_MOVE_RANGE 0x05 /* u8 movement range of the acting unit */
#define AI_COMMAND_STATE_FLAGS      0x07 /* u8 AI action flags */
#define AI_COMMAND_STATE_MODE       0x0A /* u16 bitfield word (3-bit fields at bits 3..5, 6..8, 9..11) */
#define AI_COMMAND_STATE_ATTACKER   0x0C /* u8 kind of the unit the AI is evaluating an attack with */
#define AI_COMMAND_STATE_PLAYER     0x0D /* u8 player slot the AI is acting for */

/* Fields of the command record gAiCommand (filled by the cursor code and the AI). */
#define AI_COMMAND_KIND  0x00 /* u8 kind of the command */
#define AI_COMMAND_UNIT  0x06 /* u8 unit the command acts on */

/* The army value is scaled by 3/2 and never goes below this floor. */
#define AI_ARMY_VALUE_MIN      1000

/* Layout of one unit-kind record in gUnitKindStats. */
#define UNIT_KIND_STATS_SIZE   112 /* bytes per unit kind */
#define UNIT_KIND_STATS_MOVE   0x08 /* u8 base movement range */
#define UNIT_KIND_STATS_AMMO   0x09 /* u8 maximum ammo (0 = the kind cannot attack) */
#define UNIT_KIND_STATS_MAX_RANGE 0x0D /* u8 base maximum attack range: 0 cannot attack, 1 direct, above 1 indirect */
#define UNIT_KIND_STATS_MIN_RANGE 0x0C /* u8 minimum attack range (1 = direct unit) */
#define UNIT_KIND_STATS_FUEL   0x0E /* u8 maximum fuel */
#define UNIT_KIND_STATS_FLAGS  0x13 /* u8 unit-kind capability flags (used by the AI targeting/movement checks) */
#define UNIT_KIND_STATS_MOVETYPE 0x12 /* u8 movement type: first index of the terrain movement-cost row (gMovementTypeTable) */
#define UNIT_KIND_STATS_AI_ROLE  0x14 /* u8 AI role category (1..6) the per-role turn phases select units by */
#define UNIT_KIND_STATS_SUPPLY_FLAG 0x6A /* u8 nonzero when the kind can be resupplied */

/* Unit kinds the AI code names directly. */
#define UNIT_KIND_INFANTRY  1
#define UNIT_KIND_MECH      2
#define UNIT_KIND_TRANSPORT 19

/* An AI target candidate record, 12 bytes each. */
#define AI_CANDIDATE_X        0x00 /* u8 tile x */
#define AI_CANDIDATE_Y        0x01 /* u8 tile y */
#define AI_CANDIDATE_TYPE     0x02 /* u8 target type */
#define AI_CANDIDATE_STATUS   0x03 /* u8 AI_CANDIDATE_* status */
#define AI_CANDIDATE_GROUP    0x04 /* s8 target group */
#define AI_CANDIDATE_STRIDE   12
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
#define AI_SETTING_TRANSPORT_LAST_TURN 0x13 /* u8 last turn on which more transports are built */

#endif
