/* 29 functions from 0x02180738 to 0x021816C4 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 bytes[0x8c]; } PlayerRecord02180738;
static inline u8 PlayerMode02180738(PlayerRecord02180738 *players, s32 index) { return players[index].bytes[0x2a]; }

void func_ov000_02180738(void) {
M2C_UNK ClearAiInfluenceMaps();
M2C_UNK SelectUnitAttackTarget();
M2C_UNK SetMapCursor(u8, u8, s32, s32, s32);
extern void **gCurrentMap;
void *temp_r1;
ClearAiInfluenceMaps();
SelectUnitAttackTarget();
temp_r1 = M2C_FIELD(*gCurrentMap, void **, 0x52D0);
SetMapCursor(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2), 2, 0, 0);
}

void func_ov000_02180778(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanReachableAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    PlanReachableAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

void func_ov000_021807d8(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanCaptureMoveDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    PlanCaptureMoveDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

void func_ov000_02180838(void) {
M2C_UNK ClearAiInfluenceMaps();
M2C_UNK SelectAiMoveActionTarget();
M2C_UNK RunAiAttackAction();
M2C_UNK PlanReachableAttackDestination();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK SelectAttackMoveDestination();
M2C_UNK SelectPortDestination();
M2C_UNK FinishAiUnitAction();
M2C_UNK func_ov000_02186a18();
extern void **gCurrentMap;
void *temp_r3;
ClearAiInfluenceMaps();
SelectAiMoveActionTarget();
RunAiAttackAction();
temp_r3 = *gCurrentMap;
if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) { func_ov000_02186a18(); }
PlanReachableAttackDestination();
PlanProductionSiteDestination();
SelectAttackMoveDestination();
SelectPortDestination();
FinishAiUnitAction();
}

/* Role-4/6 AI step-10 action: build the influence maps and pick the acting
 * unit's action target, run the in-place attack when the owning player's AI
 * mode calls for it, then plan the HQ, enemy-unit, production-site and
 * property/port destinations and finish the unit's action. */
void RunAiRole4Or6Step10Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK RunAiAttackAction();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanEnemyHqAttackDestination();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyHqAttackDestinationAlt();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *map;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
    FindBestMoveTarget();
    map = *gCurrentMap;
    if (M2C_FIELD((s8 *)map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 0) { func_ov000_02186a18(); }
    PlanEnemyHqAttackDestination();
    PlanEnemyUnitAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyHqAttackDestinationAlt();
    SelectPortDestination();
    FinishAiUnitAction();
}

void func_ov000_02180900(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK RunAiAttackAction();
    M2C_UNK SelectAiActionTarget();
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    RunAiAttackAction();
}

void func_ov000_02180914(void) {
    M2C_UNK RunAiAttackAction();
    M2C_UNK ClearAiInfluenceMaps();
    ClearAiInfluenceMaps();
    RunAiAttackAction();
}

void func_ov000_02180924(void) {
    M2C_UNK SelectUnitAttackTarget();
    M2C_UNK ClearAiInfluenceMaps();
    ClearAiInfluenceMaps();
    SelectUnitAttackTarget();
}

/* Role-3 AI action for a unit in AI step 0 (also the fallback for a step-2 unit
 * with no enemy to fight): build the influence maps and pick the unit's attack
 * target, attacking from where it stands when the map is foggy, the weather is
 * snow or the unit is a mobile indirect; then plan the move destination and
 * finish the unit's action. */
void RunAiRole3Step0Action(void) {
M2C_UNK BuildAiInfluenceMaps();
M2C_UNK SelectAiActionTarget();
M2C_UNK FindBestMoveTarget();
M2C_UNK PlanEnemyUnitAttackDestination();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK SelectAttackMoveDestination();
M2C_UNK SelectPropertyAttackDestination();
M2C_UNK PlanEnemyHqAttackDestinationAlt();
M2C_UNK SelectPortDestination();
M2C_UNK FinishAiUnitAction();
M2C_UNK RunAiAttackAction();
s32 IsMobileIndirectUnitKind(u32);
extern void **gCurrentMap;
void *map;
BuildAiInfluenceMaps();
SelectAiActionTarget();
map = *gCurrentMap;
if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) { RunAiAttackAction(); }
FindBestMoveTarget();
PlanEnemyUnitAttackDestination();
PlanProductionSiteDestination();
SelectAttackMoveDestination();
SelectPropertyAttackDestination();
PlanEnemyHqAttackDestinationAlt();
SelectPortDestination();
FinishAiUnitAction();
}

/* Role-3 AI step-1 handler (RunAiRole3Action case 1): clear the influence maps
 * and pick the acting unit's move-action target, attacking from where it stands
 * when the map is foggy, the weather is snow or the unit is a mobile indirect;
 * then plan the enemy-unit destination and finish the unit's action. */
void RunAiRole3Step1Action(void) {
    M2C_UNK ClearAiInfluenceMaps();
    M2C_UNK SelectAiMoveActionTarget();
    M2C_UNK PlanEnemyUnitAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPropertyAttackDestination();
    M2C_UNK PlanEnemyHqAttackDestinationAlt();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK RunAiAttackAction();
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    void *map;
    ClearAiInfluenceMaps();
    SelectAiMoveActionTarget();
    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) {
        RunAiAttackAction();
    }
    PlanEnemyUnitAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPropertyAttackDestination();
    PlanEnemyHqAttackDestinationAlt();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-3 AI action for a unit in AI step 2 when an enemy player is left: build
 * the influence maps and pick the unit's attack target, attacking from where it
 * stands when the map is foggy, the weather is snow or the unit is a mobile
 * indirect; then plan the HQ and enemy-unit destinations and finish the action. */
void RunAiRole3Step2Action(void) {
M2C_UNK BuildAiInfluenceMaps();
M2C_UNK SelectAiActionTarget();
M2C_UNK FindBestMoveTarget();
M2C_UNK PlanEnemyHqAttackDestinationAlt();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK SelectAttackMoveDestination();
M2C_UNK SelectPropertyAttackDestination();
M2C_UNK PlanEnemyUnitAttackDestination();
M2C_UNK SelectPortDestination();
M2C_UNK FinishAiUnitAction();
M2C_UNK RunAiAttackAction();
s32 IsMobileIndirectUnitKind(u32);
extern void **gCurrentMap;
void *map;
BuildAiInfluenceMaps();
SelectAiActionTarget();
map = *gCurrentMap;
if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) { RunAiAttackAction(); }
FindBestMoveTarget();
PlanEnemyHqAttackDestinationAlt();
PlanProductionSiteDestination();
SelectAttackMoveDestination();
SelectPropertyAttackDestination();
PlanEnemyUnitAttackDestination();
SelectPortDestination();
FinishAiUnitAction();
}

/* Role-3 AI step-3 handler (RunAiRole3Action case 3): rebuild the influence
 * maps, pick the acting unit's action target, and run the attack action when
 * the battlefield is hidden (fog of war or snow) or the unit under the cursor
 * is a mobile indirect unit.  Then choose the move, attack, property and port
 * destinations and finish the unit's action. */
void RunAiRole3Step3Action(void) {
M2C_UNK BuildAiInfluenceMaps();
M2C_UNK SelectAiActionTarget();
M2C_UNK FindBestMoveTarget();
M2C_UNK func_ov000_02195750();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK SelectAttackMoveDestination();
M2C_UNK SelectPropertyAttackDestination();
M2C_UNK PlanEnemyUnitAttackDestination();
M2C_UNK SelectPortDestination();
M2C_UNK FinishAiUnitAction();
M2C_UNK RunAiAttackAction();
s32 IsMobileIndirectUnitKind(u32);
extern void **gCurrentMap;
void *map;
BuildAiInfluenceMaps();
SelectAiActionTarget();
map = *gCurrentMap;
if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == MAP_WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) { RunAiAttackAction(); }
FindBestMoveTarget();
func_ov000_02195750();
PlanProductionSiteDestination();
SelectAttackMoveDestination();
SelectPropertyAttackDestination();
PlanEnemyUnitAttackDestination();
SelectPortDestination();
FinishAiUnitAction();
}

/* Role-3 AI step-4 handler (RunAiRole3Action case 4): rebuild the influence
 * maps, pick the acting unit's action target, and run the attack action when
 * the battlefield is hidden (fog of war or snow) or the unit under the cursor
 * is a mobile indirect unit.  Then choose the move, attack, property and port
 * destinations and finish the unit's action. */
void RunAiRole3Step4Action(void) {
M2C_UNK BuildAiInfluenceMaps();
M2C_UNK SelectAiActionTarget();
M2C_UNK FindBestMoveTarget();
M2C_UNK PlanAiStep4Destination();
M2C_UNK SelectAttackMoveDestination();
M2C_UNK PlanEnemyUnitAttackDestination();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK SelectPropertyAttackDestination();
M2C_UNK SelectPortDestination();
M2C_UNK FinishAiUnitAction();
M2C_UNK RunAiAttackAction();
s32 IsMobileIndirectUnitKind(u32);
extern void **gCurrentMap;
void *map;
BuildAiInfluenceMaps();
SelectAiActionTarget();
map = *gCurrentMap;
if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == MAP_WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) { RunAiAttackAction(); }
FindBestMoveTarget();
PlanAiStep4Destination();
SelectAttackMoveDestination();
PlanEnemyUnitAttackDestination();
PlanProductionSiteDestination();
SelectPropertyAttackDestination();
SelectPortDestination();
FinishAiUnitAction();
}

/* Role-3 AI step-5 action for a unit whose player has an HQ: like the step-0
 * action, pick the unit's attack target and attack from where it stands when the
 * map is foggy, the weather is snow or the unit is a mobile indirect, then plan
 * the unit's move destination and finish its action. */
void RunAiRole3Step5Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK func_ov000_0219604c();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK RunAiAttackAction();
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, MAP_FOG) != 0 || M2C_FIELD(temp_r0, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) {
        RunAiAttackAction();
    }
    FindBestMoveTarget();
    func_ov000_0219604c();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-3 AI step-6 action: while the battlefield is hidden (fog of war or snow)
 * pick the acting unit's attack target, then put the map cursor on the unit the
 * cursor is over. */
void RunAiRole3Step6Action(void) {
    M2C_UNK SelectUnitAttackTarget();
    M2C_UNK SetMapCursor(u8, u8, s32, s32, s32);
    extern void **gCurrentMap;
    void *map;
    void *unit;
    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == MAP_WEATHER_SNOW) {
        SelectUnitAttackTarget();
    }
    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    SetMapCursor(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y), 2, 0, 0);
}

/* Role-3 AI step-7 action: pick the unit's attack target and attack from where
 * it stands when the map is foggy, the weather is snow or the unit is a mobile
 * indirect, then plan the unit's move destination and finish its action. */
void RunAiRole3Step7Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanReachableAttackDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK RunAiAttackAction();
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    void *temp_r0;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    temp_r0 = *gCurrentMap;
    if (M2C_FIELD(temp_r0, u8 *, MAP_FOG) != 0 || M2C_FIELD(temp_r0, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(temp_r0, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) {
        RunAiAttackAction();
    }
    FindBestMoveTarget();
    PlanReachableAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Role-3 AI step-8 (capture) handler: rebuild the influence maps and pick the
 * unit's action target, attacking from where it stands when the map is foggy,
 * the weather is snow or the unit is a mobile indirect; then plan the capture
 * move and finish the unit's action. */
void RunAiRole3Step8Action(void) {
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK SelectAiActionTarget();
    M2C_UNK FindBestMoveTarget();
    M2C_UNK PlanCaptureMoveDestination();
    M2C_UNK PlanProductionSiteDestination();
    M2C_UNK SelectAttackMoveDestination();
    M2C_UNK SelectPortDestination();
    M2C_UNK FinishAiUnitAction();
    M2C_UNK RunAiAttackAction();
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    void *map;
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 || M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) {
        RunAiAttackAction();
    }
    FindBestMoveTarget();
    PlanCaptureMoveDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* Plans a role-3 unit's step 9 move, checking for attacks first in fog or snow or when the unit can move and fire indirectly. */
void RunAiRole3Step9Action(void) {
    M2C_UNK ClearAiInfluenceMaps(void);
    M2C_UNK SelectAiMoveActionTarget(void);
    M2C_UNK PlanReachableAttackDestination(void);
    M2C_UNK PlanProductionSiteDestination(void);
    M2C_UNK SelectAttackMoveDestination(void);
    M2C_UNK SelectPortDestination(void);
    M2C_UNK FinishAiUnitAction(void);
    M2C_UNK RunAiAttackAction(void);
    s32 IsMobileIndirectUnitKind(u32);
    extern void **gCurrentMap;
    u8 *map;

    ClearAiInfluenceMaps();
    SelectAiMoveActionTarget();
    map = *gCurrentMap;
    if (M2C_FIELD(map, u8 *, MAP_FOG) != 0 ||
        M2C_FIELD(map, u8 *, MAP_WEATHER) == WEATHER_SNOW ||
        IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(map, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) != 0) {
        RunAiAttackAction();
    }
    PlanReachableAttackDestination();
    PlanProductionSiteDestination();
    SelectAttackMoveDestination();
    SelectPortDestination();
    FinishAiUnitAction();
}

/* AI step-10 handler for a role-3 unit: builds the influence maps and chooses the
   unit's action target, attacking from where it stands when the map is foggy, the
   weather is snow, or the unit is a mobile indirect; then runs the destination
   planners and finishes the unit's action. */
void RunAiRole3Step10Action(void) {
 M2C_UNK BuildAiInfluenceMaps(); M2C_UNK SelectAiActionTarget(); M2C_UNK RunAiAttackAction(); M2C_UNK FindBestMoveTarget(); M2C_UNK PlanEnemyHqAttackDestination(); M2C_UNK PlanEnemyUnitAttackDestination(); M2C_UNK PlanProductionSiteDestination(); M2C_UNK SelectAttackMoveDestination(); M2C_UNK SelectPropertyAttackDestination(); M2C_UNK PlanEnemyHqAttackDestinationAlt(); M2C_UNK SelectPortDestination(); M2C_UNK FinishAiUnitAction();
 s32 IsMobileIndirectUnitKind(u32); extern void **gCurrentMap; void *p;
 BuildAiInfluenceMaps(); SelectAiActionTarget(); p=*gCurrentMap;
 if(M2C_FIELD(p,u8 *,MAP_FOG)!=0 || M2C_FIELD(p,u8 *,MAP_WEATHER)==WEATHER_SNOW || IsMobileIndirectUnitKind((u32)(M2C_FIELD(M2C_FIELD(p,void **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26)!=0) RunAiAttackAction();
 FindBestMoveTarget(); PlanEnemyHqAttackDestination(); PlanEnemyUnitAttackDestination(); PlanProductionSiteDestination(); SelectAttackMoveDestination(); SelectPropertyAttackDestination(); PlanEnemyHqAttackDestinationAlt(); SelectPortDestination(); FinishAiUnitAction();
}

/* Role-1 capture action callback (installed by BuildAiRole1UnitList for the
 * current player's placed role-1 units that already hold capture progress and
 * have no AI step yet): skip the map-175 player-2 override and units already in
 * the attack or capture step, rebuild the influence maps, plan a capture
 * destination when the owner's AI mode is not 3, then commit the capture-stay
 * destination. */
void RunAiRole1CaptureAction(void) {
    s32 IsAiMap175Player2Override();
    M2C_UNK BuildAiInfluenceMaps();
    M2C_UNK func_ov000_0218f0ec();
    M2C_UNK SelectCaptureStayDestination();
    extern void **gCurrentMap;
    u32 aiStep;
    void *map;
    if (IsAiMap175Player2Override()) return;
    aiStep = (u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28;
    if (aiStep == AI_STEP_ATTACK || aiStep == AI_STEP_CAPTURE) return;
    BuildAiInfluenceMaps();
    map = *gCurrentMap;
    if (M2C_FIELD((u8 *) map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE) != 3) func_ov000_0218f0ec();
    SelectCaptureStayDestination();
}

void func_ov000_02180ec8(void) {
    M2C_UNK func_ov000_0218f468();
    extern void **gCurrentMap;
    u32 temp_r0;

    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 0x1C) >> 0x1C;
    if ((temp_r0 != 6) && (temp_r0 != 8)) {
        BuildAiInfluenceMaps();
        func_ov000_0218f468();
    }
}

/* Destination plan for an AI role-3 unit whose own turn comes next: on the
 * attacking AI modes it only positions for a capture and picks a target, and it
 * hands the already-wounded attacker a retreat (func_ov000_02190f74) so the
 * healthy one gets the kill. The special movement kinds (6 and 8) skip it. */
void PlanAiAdvanceDestination(void) {
extern void **gCurrentMap;
void *p; u32 type;
if(IsAiMap175Player2Override()) return;
type=(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28;
if(type==6 || type==8)return;
BuildAiInfluenceMaps();
p=*gCurrentMap;
if(M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67ce)!=3) {
func_ov000_0218f0ec();
func_ov000_0219137c();
}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)<=60)func_ov000_02190f74();
SelectAiActionTarget(); SelectCaptureStayDestination(); SelectAIDestination();
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)>60)func_ov000_02190f74();
}

#pragma opt_strength_reduction off
/* Runs the AI's action for the acting unit: selects a move destination, then
   attacks, captures or simply finishes, depending on the unit's AI step and the
   owning player's AI mode. */
void RunAIUnitAction(void) {
M2C_UNK BuildAiInfluenceMaps();
M2C_UNK RunAiMap175MoveOverride();
M2C_UNK SelectUnitAttackTarget();
M2C_UNK func_ov000_0218f0ec();
M2C_UNK func_ov000_0219137c();
M2C_UNK RunAiAttackAction();
M2C_UNK PlanCaptureMoveDestination();
M2C_UNK func_ov000_02190f74();
M2C_UNK SelectAiActionTarget();
M2C_UNK SelectCaptureStayDestination();
M2C_UNK SelectAIDestination();
M2C_UNK func_ov000_02186a18();
M2C_UNK FindJoinTarget();
M2C_UNK func_ov000_0218d908();
M2C_UNK func_ov000_02190094();
M2C_UNK PlanProductionSiteDestination();
M2C_UNK PlanEnemyUnitAttackDestination();
M2C_UNK FinishAiUnitAction();
s32 IsAiMap175Player2Override();
extern void **gCurrentMap; extern void *gAiCommandState;
void *map; PlayerRecord02180738 *playerRecord; u32 state; s32 handled;
if(IsAiMap175Player2Override()) {RunAiMap175MoveOverride();return;}
BuildAiInfluenceMaps();map=*gCurrentMap;
state=(u32)(M2C_FIELD(M2C_FIELD(map,void **,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_AI_STATE)<<28)>>28;
if(state==6){SelectUnitAttackTarget();return;}
if(state==8){func_ov000_0218f0ec();func_ov000_0219137c();RunAiAttackAction();PlanCaptureMoveDestination();return;}
if(M2C_FIELD((u8 *)map+M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_AI_MODE)!=3){func_ov000_0218f0ec();func_ov000_0219137c();}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_HEALTH)<<25)>>25)<=60)func_ov000_02190f74();
SelectAiActionTarget();SelectCaptureStayDestination();SelectAIDestination();
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_HEALTH)<<25)>>25)>60)func_ov000_02190f74();
map=*gCurrentMap;handled=0;
playerRecord=(PlayerRecord02180738 *)((u8 *)map+MAP_PLAYER_STATES);
playerRecord += M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
state=playerRecord->bytes[PLAYER_REC_AI_MODE];
if(state==3 || (state==2 && ((u32)(M2C_FIELD(M2C_FIELD(map,void **,MAP_CURSOR_UNIT),u8 *,0)<<26)>>26)!=2)){func_ov000_02186a18();handled=1;}
RunAiAttackAction();FindJoinTarget();
if(!handled){map=*gCurrentMap;if(M2C_FIELD((u8 *)map+M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_AI_MODE)!=0)func_ov000_02186a18();}
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_HEALTH)<<25)>>25)<=60)func_ov000_0218d908();
func_ov000_02190094();PlanProductionSiteDestination();
M2C_FIELD(gAiCommandState,u16 *,8)|=0x20;
func_ov000_02190094();PlanEnemyUnitAttackDestination();FinishAiUnitAction();
}
#pragma opt_strength_reduction reset
/* Action callback shared by AI role-4 and role-6 units: flag the action plan when
 * the acting unit is set to act in place, then run the handler for its AI step. */
void RunAiRole4Or6Action(void) {
 s32 IsAiMap175Player2Override(); M2C_UNK func_ov000_0218049c(); M2C_UNK func_ov000_021804b0(); M2C_UNK func_ov000_021804c4();
 extern void **gCurrentMap; extern void *gAiCommandState;
 if(IsAiMap175Player2Override()) return;
 if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u16 *,MAP_UNIT_ACTION)<<18)>>30)==MAP_UNIT_ACTION_STAY)
 M2C_FIELD(gAiCommandState,u16 *,AI_COMMAND_STATE_ACTION_FLAGS)|=0x80;
 switch((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_AI_STATE)<<28)>>28) {
 case 0: case 2: case 3: case 4: case 5: case 7: case 8: func_ov000_0218049c(); return;
 case 1: case 9: func_ov000_021804b0(); return;
 case 6: func_ov000_021804c4(); return;
 }
}

/* Dispatches on the low nibble of byte at p+0x52db; runs various step handlers. */
void func_ov000_021812a8(void) {
extern void **gCurrentMap;
void *state;
if(IsAiMap175Player2Override()) {RunAiMap175MoveOverride(); return;}
state=*gCurrentMap;
switch((u32)(M2C_FIELD(M2C_FIELD(state,void **,0x52d0),u8 *,11)<<28)>>28) {
case 0: RunAiAttackAndPlanStep(); return;
case 1: RunAiUnitActionStep1(); return;
case 2: if(HasEnemyPlayer()==1)RunAiRole4Or6Step2Action(); else RunAiAttackAndPlanStep(); return;
case 3: RunAiUnitActionStep3(); return;
case 4: RunAiRole4Or6Step4Action(); return;
case 5: if(PlayerHasHq(M2C_FIELD(state,u16 *,0x52a4))==1)func_ov000_021806d8(); else RunAiRole4Or6Step4Action(); return;
case 7: func_ov000_02180778(); return;
case 8: func_ov000_021807d8(); return;
case 9: func_ov000_02180838(); return;
case 6: func_ov000_02180738(); return;
case 10: RunAiRole4Or6Step10Action(); return;
}
}

/* Role-3 AI action callback (the variant installed by SelectAiRole3UnitByRange):
 * unless the map-175 override is active, mark an AI action-plan flag when the
 * cursor unit's AI sub-state is not 2, then run the handler for that unit's AI
 * step. */
void RunAiRole3ActionByRange(void) {
 s32 IsAiMap175Player2Override();
 extern void **gCurrentMap; extern void *gAiCommandState;
 if(IsAiMap175Player2Override()) return;
 if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u16 *,8)<<18)>>30)!=2)
 M2C_FIELD(gAiCommandState,u16 *,AI_COMMAND_STATE_ACTION_FLAGS)|=128;
 switch((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT),u8 *,MAP_UNIT_AI_STATE)<<28)>>28) {
 case 0: case 2: case 3: case 4: case 5: case 7: case 8: func_ov000_02180900(); return;
 case 1: case 9: func_ov000_02180914(); return;
 case 6: func_ov000_02180924(); return;
 case 10: RunAiRole3Step10Action(); return;
 }
}

/* Dispatches on the low nibble of the unit state's byte at +0x52DB (state step) and runs the matching handler. */
void RunAiRole3Action(void) {
    extern void **gCurrentMap;
    void *state;
    if (IsAiMap175Player2Override()) { RunAiMap175MoveOverride(); return; }
    state = *gCurrentMap;
    switch ((u32)(M2C_FIELD(M2C_FIELD(state, void **, 0x52D0), u8 *, 11) << 28) >> 28) {
    case 0: RunAiRole3Step0Action(); return;
    case 1: RunAiRole3Step1Action(); return;
    case 2: if (HasEnemyPlayer() == 1) RunAiRole3Step2Action(); else RunAiRole3Step0Action(); return;
    case 3: RunAiRole3Step3Action(); return;
    case 4: RunAiRole3Step4Action(); return;
    case 5: if (PlayerHasHq(M2C_FIELD(state, u16 *, 0x52a4)) == 1) RunAiRole3Step5Action(); else RunAiRole3Step4Action(); return;
    case 6: RunAiRole3Step6Action(); return;
    case 7: RunAiRole3Step7Action(); return;
    case 8: RunAiRole3Step8Action(); return;
    case 9: RunAiRole3Step9Action(); return;
    }
}

/* AI action for a role-6 unit: when a unit record is free, the player can afford
 * the kind-17 structure, the acting unit has ammo and carries nothing, and its
 * tile is a valid build site, issue the unit's in-place build/capture command
 * (23) at that tile unless the tile's enemy threat exceeds the unit's health. */
void RunAiRole6Action(void) {
extern void **gCurrentMap;
s32 FindFreeUnitRecord(u16);
s32 GetUnitBuildCost(u16,s32);
s32 func_ov000_02178e84(u8,u8);
void *map,*unit;
u16 player;
s32 buildCost;u32 index;
if(IsAiMap175Player2Override()!=0) return;
if(FindFreeUnitRecord(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER))==0)return;
map=*gCurrentMap;player=M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER);
buildCost=GetUnitBuildCost(player,17)*10;
if(buildCost>M2C_FIELD((u8 *)map+player*MAP_PLAYER_STRIDE,s32 *,PLAYER_FUNDS_OFF)) return;
map=*gCurrentMap;unit=M2C_FIELD(map,void **,MAP_CURSOR_UNIT);
if(((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_AMMO)<<21)>>28)==0)return;
if(M2C_FIELD(unit,u8 *,MAP_UNIT_NEXT_CARRIED)!=0)return;
index=M2C_FIELD(unit,u8 *,MAP_UNIT_FIRST_CARRIED);
if(index!=0 && ((u32)(M2C_FIELD((u8 *)map+index*MAP_UNIT_STRIDE,u8 *,MAP_UNIT_RECORDS)<<26)>>26)==17)return;
if(func_ov000_02178e84(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y))==0)return;
BuildAiInfluenceMaps();
map=*gCurrentMap;unit=M2C_FIELD(map,void **,MAP_CURSOR_UNIT);
index=M2C_FIELD(unit,u8 *,MAP_UNIT_X)+M2C_FIELD((u8 *)map+M2C_FIELD(unit,u8 *,MAP_UNIT_Y)*2,u16 *,MAP_ROW_OFFSETS);
if((s32)((u32)(M2C_FIELD(unit,u16 *,MAP_UNIT_HEALTH)<<25)>>25)>M2C_FIELD((u8 *)map+index,u8 *,MAP_CELL_THREAT_DIRECT)+M2C_FIELD((u8 *)map+index,u8 *,MAP_CELL_THREAT_INDIRECT))
SetMapCursor(M2C_FIELD(unit,u8 *,MAP_UNIT_X),M2C_FIELD(unit,u8 *,MAP_UNIT_Y),23,0,0);
}

void RunAiKind13Action(void) {
    M2C_UNK RunAiKind13BuildAction();
    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    RunAiKind13BuildAction();
}

