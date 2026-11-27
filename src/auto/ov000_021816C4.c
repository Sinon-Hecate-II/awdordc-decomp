/* 9 functions from 0x021816C4 to 0x02181C88 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* Update the active state and dispatch the appropriate handler. */
void RunAiRole2EmptyAction(void) {
    extern void **gCurrentMap;
    void *state;

    if (IsAiMap175Player2Override() != 0) {
        RunAiMap175MoveOverride();
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 6) {
        return;
    }
    BuildAiInfluenceMaps();
    SelectAiActionTarget();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0) << 26) >> 26) == 25) {
        RunAiAttackAction();
    }
    state = *gCurrentMap;
    if (M2C_FIELD(state + M2C_FIELD(state, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        PlanCaptureMoveDestination();
        FinishAiUnitAction();
        return;
    }
    SelectAiRigBuildDestination(0);
    func_ov000_02191970();
    SelectAiRigBuildDestination(1);
    SelectAiPropertyDestination();
    FinishAiUnitAction();
}

/* Role-2 action for a transport carrying a unit that has an AI step set: rebuild
 * the influence maps, then run the capture step's planner or the carried unit's
 * destination planner according to the acting unit's AI step. */
void RunAiRole2CargoAction(void) {
    extern void **gCurrentMap;
    if (IsAiMap175Player2Override() != 0) return;
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == AI_STEP_ATTACK) return;
    BuildAiInfluenceMaps();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == AI_STEP_CAPTURE) PlanCaptureMoveDestination(); else func_ov000_0219234c();
}

void func_ov000_02181838(void) {
    extern void **gCurrentMap;
    void *p;

    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 6) {
        return;
    }
    BuildAiInfluenceMaps();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0) << 26) >> 26) == 25) {
        RunAiAttackAction();
    }
    p = *gCurrentMap;
    if (M2C_FIELD(p + M2C_FIELD(p, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        PlanCaptureMoveDestination();
    } else {
        func_ov000_02192d88();
    }
}

/* Plan a loaded role-2 unit's action, including unloading, then finalize without fallback replanning. */
void RunAiRole2LoadedAction(void) {
    extern void **gCurrentMap;
    extern void *gAiCommandState;
    void *map;

    if (IsAiMap175Player2Override() != 0) {
        RunAiMap175MoveOverride();
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 6) return;
    BuildAiInfluenceMaps();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) == 25) RunAiAttackAction();
    map = *gCurrentMap;
    if (M2C_FIELD(map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE)) func_ov000_02186a18();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 8) {
        PlanCaptureMoveDestination();
        FinishAiUnitAction();
        return;
    }
    func_ov000_021935c4();
    PlanProductionSiteDestination();
    M2C_FIELD(gAiCommandState, u16 *, AI_COMMAND_STATE_ACTION_FLAGS) |= AI_ACTION_SKIP_REPLAN;
    func_ov000_02192d88();
    func_ov000_021935c4();
    FinishAiUnitAction();
}

/* Runs one step of the AI action of a role-5 unit: refreshes the influence maps
   (or clears them on the first step), then chooses the acting unit's destination --
   including the kind-24 pick-up and kind-25 attack steps -- and finishes the action. */
void RunAiRole5Action(void) {
    extern void **gCurrentMap;
    void *unit;

    if (IsAiMap175Player2Override() != 0) {
        RunAiMap175MoveOverride();
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) != 1) {
        BuildAiInfluenceMaps();
    } else {
        ClearAiInfluenceMaps();
    }
    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    if (((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 6) {
        if (((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) == 25) {
            SelectUnitAttackTarget();
        }
        return;
    }
    if (((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) == 24 && M2C_FIELD(unit, u8 *, MAP_UNIT_CARRIED) == 0) {
        SelectAiActionTarget();
    } else {
        SelectAiMoveActionTarget();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) == 25) {
        RunAiAttackAction();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 8) {
        PlanCaptureMoveDestination();
        FinishAiUnitAction();
        return;
    }
    RunAiCargoOrLoadAction();
    FinishAiUnitAction();
}

/* Run the AI's supply action: unless the map-175 override applies or the acting
 * unit is on its attack step, refresh the influence maps (or clear them on the
 * first step), then pick the best adjacent tile from which to resupply. */
void RunAiSupplyAction(void) {
    M2C_UNK func_ov000_0218ef40();
    M2C_UNK ClearAiInfluenceMaps();
    M2C_UNK BuildAiInfluenceMaps();
    extern void **gCurrentMap;
    u32 aiStep;

    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    aiStep = (u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28;
    if (aiStep == AI_STEP_ATTACK) {
        return;
    }
    if (aiStep != AI_STEP_FIRST) {
        BuildAiInfluenceMaps();
    } else {
        ClearAiInfluenceMaps();
    }
    func_ov000_0218ef40();
}

/* The AI's flare action for a kind-5 unit (UNIT_KIND_FLARE): unless the map-175
 * override applies, have TagAiKind5TargetCells mark the cells the current
 * player's healthy indirect units can hit and aim the flare at the best-scored
 * cell near the cursor unit. */
void RunAiKind5Action(void) {
    M2C_UNK TagAiKind5TargetCells();
    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    TagAiKind5TargetCells();
}

/* AI action for the selected unit: unless the map-175 override applies or the
 * player's map flags forbid acting, put the cursor on the unit and issue AI
 * command 22, which makes it produce its kind-17 cargo unit. */
void RunAiProduceCargoAction(void) {
extern void **gCurrentMap;
M2C_UNK SetMapCursor(u8,u8,s32,s32,s32);
void *p;
if(IsAiMap175Player2Override()!=0)return;
p=*gCurrentMap;
if(GetMapPlayerFlags(M2C_FIELD(p,u16 *,MAP_ID),M2C_FIELD(p,u16 *,MAP_CURRENT_PLAYER)) & 0x40)return;
p=M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT);
SetMapCursor(M2C_FIELD(p,u8 *,MAP_UNIT_X),M2C_FIELD(p,u8 *,MAP_UNIT_Y),0x16,0,0);
}

/* Run the AI's CO power action: skip it if the acting unit has an attack target;
 * otherwise use the power when the AI settings' condition callback (default:
 * the unit is below half health) agrees, then choose the unit's destination. */
void RunAiCoPowerAction(void) {
s32 AiUnitHasAttackTarget(void);
s32 AiCoPowerUnitIsHurt(void);
void ChooseAiUnitMoveDestination(s32);
extern void *gAiSettings;
extern void *gAiCommandState;
s32 (*useCoPower)(void);
if(IsAiMap175Player2Override()!=0)return;
BuildAiInfluenceMaps();
if(AiUnitHasAttackTarget()!=0)return;
useCoPower=M2C_FIELD(gAiSettings,s32 (**)(void),AI_SETTINGS_USE_CO_POWER);
if(useCoPower==NULL) {if(!AiCoPowerUnitIsHurt())return;} else {if(!useCoPower())return;}
M2C_FIELD(gAiCommandState,u16 *,AI_COMMAND_STATE_ACTION_FLAGS)|=AI_ACTION_CO_POWER;
ChooseAiUnitMoveDestination(0);
}

