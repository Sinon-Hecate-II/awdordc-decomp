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
#define AI_STATE_ACTION        0x0c /* u8 kind of the action being taken */
#define AI_STATE_ARMY_VALUE    0x10 /* s32 total value of the player's units */
#define AI_STATE_SHORTFALL     0x14 /* s32 money reserved for an unaffordable purchase */

/* Fields of the command record gAiCommand (filled by the cursor code and the AI). */
#define AI_COMMAND_KIND  0x00 /* u8 kind of the command */
#define AI_COMMAND_UNIT  0x06 /* u8 unit the command acts on */

/* The army value is scaled by 3/2 and never goes below this floor. */
#define AI_ARMY_VALUE_MIN      1000

/* Layout of one unit-kind record in gUnitKindStats. */
#define UNIT_KIND_STATS_SIZE   112 /* bytes per unit kind */
#define UNIT_KIND_STATS_MOVE   0x08 /* u8 base movement range */
#define UNIT_KIND_STATS_MAX_RANGE 0x09 /* u8 maximum attack range: 0 cannot attack, 1 direct, above 1 indirect */
#define UNIT_KIND_STATS_MIN_RANGE 0x0C /* u8 minimum attack range (1 = direct unit) */
#define UNIT_KIND_STATS_FLAGS  0x13 /* u8 unit-kind capability flags (used by the AI targeting/movement checks) */
#define UNIT_KIND_STATS_MOVETYPE 0x12 /* u8 movement type: first index of the terrain movement-cost row (gMovementTypeTable) */

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

#endif
