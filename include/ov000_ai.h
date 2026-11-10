/* The ov000 AI turn state, the block gAiState points at.  The AI walks its units
 * at the start of a turn, scores the army, and then decides unit-by-unit what it
 * wants to build and where the units should go. */
#ifndef OV000_AI_H
#define OV000_AI_H

#define AI_STATE_TARGET_COUNT  0x00 /* u8 number of target candidates (BuildAiTargetCandidates) */
#define AI_STATE_GROUP_COUNT   0x01 /* u8 number of target groups (BuildAiTargetGroups) */
#define AI_STATE_PHASE         0x02 /* u8 AI turn phase (state machine in ProcessAiTurn) */
#define AI_STATE_RESERVE_RETRY 0x05 /* u8 retries left to reserve money for a purchase */
#define AI_STATE_UNIT_COUNT    0x07 /* u8 friendly units counted this turn */
#define AI_STATE_ACTION        0x0c /* u8 kind of the action being taken */
#define AI_STATE_ARMY_VALUE    0x10 /* s32 total value of the player's units */
#define AI_STATE_SHORTFALL     0x14 /* s32 money reserved for an unaffordable purchase */

/* The army value is scaled by 3/2 and never goes below this floor. */
#define AI_ARMY_VALUE_MIN      1000

#endif
