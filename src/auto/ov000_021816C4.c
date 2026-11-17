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
        func_ov000_0218ca94();
    }
    state = *gCurrentMap;
    if (M2C_FIELD(state + M2C_FIELD(state, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        func_ov000_021962f8();
        FinishAiUnitAction();
        return;
    }
    func_ov000_02193d6c(0);
    func_ov000_02191970();
    func_ov000_02193d6c(1);
    func_ov000_02192018();
    FinishAiUnitAction();
}

void func_ov000_021817c0(void) {
extern void **gCurrentMap;
if(IsAiMap175Player2Override()!=0)return;
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28)==6)return;
BuildAiInfluenceMaps();
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,11)<<28)>>28)==8)func_ov000_021962f8();else func_ov000_0219234c();
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
        func_ov000_0218ca94();
    }
    p = *gCurrentMap;
    if (M2C_FIELD(p + M2C_FIELD(p, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        func_ov000_021962f8();
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
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) == 25) func_ov000_0218ca94();
    map = *gCurrentMap;
    if (M2C_FIELD(map + M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_AI_MODE)) func_ov000_02186a18();
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 8) {
        func_ov000_021962f8();
        FinishAiUnitAction();
        return;
    }
    func_ov000_021935c4();
    func_ov000_02194370();
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
            func_ov000_0218cfec();
        }
        return;
    }
    if (((u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26) == 24 && M2C_FIELD(unit, u8 *, MAP_UNIT_CARRIED) == 0) {
        SelectAiActionTarget();
    } else {
        func_ov000_0218eea8();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_KIND) << 26) >> 26) == 25) {
        func_ov000_0218ca94();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT), u8 *, MAP_UNIT_AI_STATE) << 28) >> 28) == 8) {
        func_ov000_021962f8();
        FinishAiUnitAction();
        return;
    }
    func_ov000_02189df4();
    FinishAiUnitAction();
}

void RunAiSupplyAction(void) {
    M2C_UNK func_ov000_0218ef40();
    M2C_UNK ClearAiInfluenceMaps();
    M2C_UNK BuildAiInfluenceMaps();
    extern void **gCurrentMap;
    u32 temp_r0;

    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xB) << 0x1C) >> 0x1C;
    if (temp_r0 == 6) {
        return;
    }
    if (temp_r0 != 1) {
        BuildAiInfluenceMaps();
    } else {
        ClearAiInfluenceMaps();
    }
    func_ov000_0218ef40();
}

void RunAiKind5Action(void) {
    M2C_UNK TagAiKind5TargetCells();
    if (IsAiMap175Player2Override() != 0) {
        return;
    }
    TagAiKind5TargetCells();
}

void func_ov000_02181ba4(void) {
extern void **gCurrentMap;
M2C_UNK SetMapCursor(u8,u8,s32,s32,s32);
void *p;
if(IsAiMap175Player2Override()!=0)return;
p=*gCurrentMap;
if(func_020a8a14(M2C_FIELD(p,u16 *,0x5142),M2C_FIELD(p,u16 *,0x52a4)) & 0x40)return;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
SetMapCursor(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),0x16,0,0);
}

void func_ov000_02181c10(void) {
s32 func_ov000_0218cb20(void);
s32 func_ov000_021aa3bc(void);
extern void *gAiSettings;
extern void *gAiCommandState;
s32 (*callback)(void);
if(IsAiMap175Player2Override()!=0)return;
BuildAiInfluenceMaps();
if(func_ov000_0218cb20()!=0)return;
callback=M2C_FIELD(gAiSettings,s32 (**)(void),4);
if(callback==NULL) {if(!func_ov000_021aa3bc())return;} else {if(!callback())return;}
M2C_FIELD(gAiCommandState,u16 *,8)|=0x100;
func_ov000_0218d040(0);
}

