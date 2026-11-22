/* 19 functions from 0x0219D724 to 0x0219E6D4 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* AI turn phase starter for units whose kind has AI role 3: collect the current
 * player's ready role-3 units into gAiUnitList, order them by movement range,
 * put the chosen unit first and install the role-3 action callback. */
void SelectAiRole3Unit(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK RunAiRole3Action;
void ScoreAiUnitsByMoveRange(s32);
void MoveSelectedAiUnitLast(void);
s32 unitId; s32 offset; s8 *cursor; u16 firstUnitId; u32 kind; void *units; void *map;
gAiUnitListCursor = &gAiUnitList;
map = *gCurrentMap;
firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
unitId = firstUnitId + 1;
if (unitId < firstUnitId + MAP_UNIT_GROUP_SCAN) {
offset = unitId * MAP_UNIT_STRIDE;
do {
units = (u8 *)map + MAP_UNIT_RECORDS;
kind = (u32)(M2C_FIELD(units, u8 *, offset) << 26) >> 26;
if (kind != 0) {
if (!(M2C_FIELD((u8 *)units + offset, u16 *, MAP_UNIT_FLAGS) & 1) && gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 3) {
cursor = gAiUnitListCursor;
gAiUnitListCursor = cursor + 1;
*cursor = unitId;
}}
unitId++;
map = *gCurrentMap;
offset += MAP_UNIT_STRIDE;
} while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByMoveRange(1);
MoveSelectedAiUnitLast();
gAiUnitAction = &RunAiRole3Action;
*gAiCommandState = 2;
}

void func_ov000_0219d848(void) {
    /* Collect the indices of type-6 map entries into a list, then install the
       RunAiRole4Or6Action callback. */
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiRole4Or6Action;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    gAiUnitListCursor = &gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 6) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = (s8)index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiRole4Or6Action;
    *gAiCommandState = 2;
}

void func_ov000_0219d960(void) {
    /* Variant of func_ov000_0219d848 installing RunAiRole6Action. */
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiRole6Action;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    gAiUnitListCursor = &gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 6) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = (s8)index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiRole6Action;
    *gAiCommandState = 2;
}

void func_ov000_0219da78(void) {
    /* Collect the indices of type-6 map entries into a list, then install the
       func_ov000_021812a8 callback. */
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_021812a8;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    gAiUnitListCursor = &gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 6) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &func_ov000_021812a8;
    *gAiCommandState = 2;
}

/* AI turn-plan phase 0: no single unit is picked.  Install the army-wide
 * BuildAiThreatMap action, which clears the AI's range layers and rebuilds every
 * unit's threat range; the AI_UNIT_LIST_NO_UNIT entry makes PickAiUnitAction run
 * it once without a cursor unit. */
void StartAiThreatMapPhase(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK BuildAiThreatMap;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &BuildAiThreatMap;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn-plan phase with no single acting unit: install the army-wide action
   that rebuilds the foot-unit (infantry/mech) reachability layer from the map's
   property cells.  The AI_UNIT_LIST_NO_UNIT entry makes the action run once
   without a cursor unit. */
void StartAiFootRangePhase(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_0219b3c8;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
 *gAiUnitListCursor = AI_UNIT_LIST_END;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_0219b3c8;
 *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn-plan phase 12: no single unit is picked.  Install the army-wide
 * ClearAiUnitLoadCounts action, which resets the per-unit count of how often
 * each unit was used as a load target; the AI_UNIT_LIST_NO_UNIT entry runs it
 * once without a cursor unit. */
void StartAiLoadCountResetPhase(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK ClearAiUnitLoadCounts;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &ClearAiUnitLoadCounts;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn phase for the general case: ask FindBestSelectableUnit for the best unit
 * to act with, put its id on the AI unit list and install the action callback that
 * carries the choice out. */
void SelectBestAiUnit(void) {
    s8 FindBestSelectableUnit();
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiProduceCargoAction;
    s8 *cursor;
    s8 unitId;

    gAiUnitListCursor = &gAiUnitList;
    unitId = FindBestSelectableUnit();
    if (unitId != 0) {
        cursor = gAiUnitListCursor;
        gAiUnitListCursor = cursor + 1;
        *cursor = unitId;
    }
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiProduceCargoAction;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn phase starter for a CO power: put the unit the CO power belongs to
 * alone into gAiUnitList (the list is empty when it is not ready) and install
 * the CO-power action callback. */
void SelectAiCoPowerUnit(void) {
    s8 GetCoPowerUnitId();
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiCoPowerAction;
    s8 *cursor;
    s8 unitId;

    gAiUnitListCursor = &gAiUnitList;
    unitId = GetCoPowerUnitId();
    if (unitId != 0) {
        cursor = gAiUnitListCursor;
        gAiUnitListCursor = cursor + 1;
        *cursor = unitId;
    }
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiCoPowerAction;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn-plan phase 15: no single unit is picked.  Install the army-wide
 * AssignUnitMoveTargets action, which gives every foot unit a property to
 * capture; the AI_UNIT_LIST_NO_UNIT entry runs it once without a cursor unit. */
void StartAssignUnitMoveTargetsPhase(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK AssignUnitMoveTargets;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &AssignUnitMoveTargets;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn-plan phase 17: no single unit is picked.  Install the army-wide
 * ReleaseUnitMoveTargets action, which drops the capture targets the previous
 * phase assigned; the AI_UNIT_LIST_NO_UNIT entry runs it once without a
 * cursor unit. */
void StartReleaseUnitMoveTargetsPhase(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK ReleaseUnitMoveTargets;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &ReleaseUnitMoveTargets;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* Install the army-wide ClearAiActionFlags action, which drops the 0x08 flag
 * BeginAiTurn sets on the AI's action flags; the AI_UNIT_LIST_NO_UNIT entry runs
 * it once without a cursor unit. */
void StartAiClearActionFlags(void) {
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK ClearAiActionFlags;

    gAiUnitListCursor = &gAiUnitList;
    *gAiUnitListCursor++ = AI_UNIT_LIST_NO_UNIT;
    *gAiUnitListCursor = AI_UNIT_LIST_END;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &ClearAiActionFlags;
    *gAiCommandState = AI_COMMAND_PHASE_PICK_ACTION;
}

/* AI turn phase starter for kind-13 units: collect the current player's ready
 * kind-13 units (not yet acted, with a facing set) into gAiUnitList, then install
 * the kind-13 action callback. */
void SelectAiKind13Unit(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiKind13Action;
    s32 unitId, offset;
    s8 *cursor;
    u16 firstUnitId;
    u32 kind;
    void *units, *map, *unit;

    gAiUnitListCursor = &gAiUnitList;
    map = *gCurrentMap;
    firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    unitId = firstUnitId + 1;
    if (unitId < firstUnitId + MAP_UNIT_GROUP_SCAN) {
        offset = unitId * MAP_UNIT_STRIDE;
        do {
            units = (u8 *)map + MAP_UNIT_RECORDS;
            unit = (u8 *)units + offset;
            kind = (u32)(M2C_FIELD(units, u8 *, offset) << 26) >> 26;
            if (kind != 0) {
                if (!(M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) & 1) && kind == 13) {
                    if (((u32)(M2C_FIELD(unit, u16 *, MAP_UNIT_CAPTURE) << 16) >> 27) != 0) {
                        cursor = gAiUnitListCursor;
                        gAiUnitListCursor = cursor + 1;
                        *cursor = unitId;
                    }
                }
            }
            unitId++;
            map = *gCurrentMap;
            offset += MAP_UNIT_STRIDE;
        } while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &RunAiKind13Action;
    *gAiCommandState = 2;
}

/* AI turn phase starter for role-2 units with an empty cargo slot: collect the
 * current player's ready ones into gAiUnitList, order them by movement range and
 * install the role-2 empty-cargo action callback. */
void SelectAiRole2EmptyUnit(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK RunAiRole2EmptyAction;
void ScoreAiUnitsByMoveRange(int);
s32 unitId; s32 offset; s8 *cursor; u16 firstUnitId; u32 kind; void *units; void *map;
gAiUnitListCursor = &gAiUnitList;
map = *gCurrentMap;
firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
unitId = firstUnitId + 1;
if (unitId < firstUnitId + MAP_UNIT_GROUP_SCAN) {
offset = unitId * MAP_UNIT_STRIDE;
do {
units = (u8 *)map + MAP_UNIT_RECORDS;
kind = (u32)(M2C_FIELD(units, u8 *, offset) << 26) >> 26;
if (kind != 0) {
if (!(M2C_FIELD((u8 *)units + offset, u16 *, MAP_UNIT_FLAGS) & 1) && gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 2 && M2C_FIELD((u8 *)units + offset, u8 *, MAP_UNIT_CARRIED) == 0) {
cursor = gAiUnitListCursor;
gAiUnitListCursor = cursor + 1;
*cursor = unitId;
}}
unitId++;
map = *gCurrentMap;
offset += MAP_UNIT_STRIDE;
} while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByMoveRange(0);
gAiUnitAction = &RunAiRole2EmptyAction;
*gAiCommandState = 2;
}

/* AI turn phase starter for kind role 2: collect the current player's ready units
   whose kind has AI role 2 and that carry a unit whose AI step is set, order them
   by movement range, put the chosen unit first and install the role-2 action
   callback. */
void SelectAiRole2Unit(void) {
    void ScoreAiUnitsByMoveRange(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiRole2CargoAction;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    u8 cargo;
    void *unit;
    void *unit2;
    void *gameState;

    gAiUnitListCursor = &gAiUnitList;
    gameState = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(gameState, u16 *, MAP_CURRENT_PLAYER)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * MAP_UNIT_STRIDE;
        do {
            unit = (u8 *)gameState + MAP_UNIT_RECORDS;
            unit2 = (u8 *)unit + stride;
            type = (u32)(M2C_FIELD(unit, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD(unit2, u16 *, MAP_UNIT_FLAGS) & 1) && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 2) {
                    cargo = M2C_FIELD(unit2, u8 *, MAP_UNIT_CARRIED);
                    if (cargo != 0 && ((u32)(M2C_FIELD((u8 *)gameState + cargo * MAP_UNIT_STRIDE, u8 *, MAP_UNIT_RECORDS + MAP_UNIT_AI_STATE) << 28) >> 28) != 0) {
                        out = gAiUnitListCursor;
                        gAiUnitListCursor = out + 1;
                        *out = index;
                    }
                }
            }
            index++;
            gameState = *gCurrentMap;
            stride += MAP_UNIT_STRIDE;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(gameState, u16 *, MAP_CURRENT_PLAYER)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    ScoreAiUnitsByMoveRange(0);
    gAiUnitAction = &RunAiRole2CargoAction;
    *gAiCommandState = 2;
}

/* Collects eligible slot indices into the slot list buffer, then installs the
   corresponding handler callback and switches the mode to 2. */
void func_ov000_0219e214(void) {
    void ScoreAiUnitsByMoveRange(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_02181838;
    s32 slotIndex;
    s32 stride;
    s8 *outputPtr;
    u16 countBase;
    u32 entryId;
    u8 flags;
    void *entry;
    void *entry2;
    void *gameState;

    gAiUnitListCursor = &gAiUnitList;
    gameState = *gCurrentMap;
    countBase = gPlayerUnitIdBase[M2C_FIELD(gameState,u16 *,0x52A4)];
    slotIndex = countBase + 1;
    if (slotIndex < countBase + 0x33) {
        stride = slotIndex * 14;
        do {
            entry = (u8 *)gameState + 0x59A4;
            entry2 = (u8 *)entry + stride;
            entryId = (u32)(M2C_FIELD(entry,u8 *,stride) << 26) >> 26;
            if (entryId != 0) {
                if (!(M2C_FIELD(entry2,u16 *,4) & 1) && gUnitKindStats[entryId * 0x70 + 0x14] == 2) {
                    flags = M2C_FIELD(entry2,u8 *,0xC);
                    if (flags != 0 && ((u32)(M2C_FIELD((u8 *)gameState + flags * 14,u8 *,0x59AF) << 28) >> 28) == 0) {
                        outputPtr = gAiUnitListCursor;
                        gAiUnitListCursor = outputPtr + 1;
                        *outputPtr = slotIndex;
                    }
                }
            }
            slotIndex++;
            gameState = *gCurrentMap;
            stride += 14;
        } while (slotIndex < gPlayerUnitIdBase[M2C_FIELD(gameState,u16 *,0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    ScoreAiUnitsByMoveRange(0);
    gAiUnitAction = &func_ov000_02181838;
    *gAiCommandState = 2;
}

/* Collects eligible slot indices into the slot list buffer, then installs the
   corresponding handler callback and switches the mode to 2. */
void func_ov000_0219e358(void) {
    void ScoreAiUnitsByMoveRange(s32);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK RunAiRole2LoadedAction;
    s32 slotIndex;
    s32 stride;
    s8 *outputPtr;
    u16 countBase;
    u32 entryId;
    u8 flags;
    void *entry;
    void *entry2;
    void *gameState;

    gAiUnitListCursor = &gAiUnitList;
    gameState = *gCurrentMap;
    countBase = gPlayerUnitIdBase[M2C_FIELD(gameState,u16 *,0x52A4)];
    slotIndex = countBase + 1;
    if (slotIndex < countBase + 0x33) {
        stride = slotIndex * 14;
        do {
            entry = (u8 *)gameState + 0x59A4;
            entry2 = (u8 *)entry + stride;
            entryId = (u32)(M2C_FIELD(entry,u8 *,stride) << 26) >> 26;
            if (entryId != 0) {
                if (!(M2C_FIELD(entry2,u16 *,4) & 1) && gUnitKindStats[entryId * 0x70 + 0x14] == 2) {
                    flags = M2C_FIELD(entry2,u8 *,0xC);
                    if (flags != 0 && ((u32)(M2C_FIELD((u8 *)gameState + flags * 14,u8 *,0x59AF) << 28) >> 28) == 0) {
                        outputPtr = gAiUnitListCursor;
                        gAiUnitListCursor = outputPtr + 1;
                        *outputPtr = slotIndex;
                    }
                }
            }
            slotIndex++;
            gameState = *gCurrentMap;
            stride += 14;
        } while (slotIndex < gPlayerUnitIdBase[M2C_FIELD(gameState,u16 *,0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    ScoreAiUnitsByMoveRange(0);
    gAiUnitAction = &RunAiRole2LoadedAction;
    *gAiCommandState = 2;
}

/* AI turn phase starter for units whose kind has AI role 5: collect the current
 * player's ready role-5 units into gAiUnitList, score them by the property
 * terrain they stand on, and install the role-5 action callback. */
void SelectAiRole5Unit(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK RunAiRole5Action;
void ScoreAiUnitsByProperty(void);
s32 unitId; s32 offset; s8 *cursor; u16 firstUnitId; u32 kind; void *units; void *map;
gAiUnitListCursor = &gAiUnitList;
map = *gCurrentMap;
firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
unitId = firstUnitId + 1;
if (unitId < firstUnitId + MAP_UNIT_GROUP_SCAN) {
offset = unitId * MAP_UNIT_STRIDE;
do {
units = (u8 *)map + MAP_UNIT_RECORDS;
kind = (u32)(M2C_FIELD(units, u8 *, offset) << 26) >> 26;
if (kind != 0) {
if (!(M2C_FIELD((u8 *)units + offset, u16 *, MAP_UNIT_FLAGS) & 1) && gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 5) {
cursor = gAiUnitListCursor;
gAiUnitListCursor = cursor + 1;
*cursor = unitId;
}}
unitId++;
map = *gCurrentMap;
offset += MAP_UNIT_STRIDE;
} while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByProperty();
gAiUnitAction = &RunAiRole5Action;
*gAiCommandState = 2;
}

/* AI turn phase starter for units whose kind can resupply others: collect the current
 * player's ready supply units into gAiUnitList, order them by the property terrain they
 * stand on, and install the supply action callback. */
void SelectAiSupplyUnit(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK RunAiSupplyAction;
void ScoreAiUnitsByProperty(void);
s32 unitId; s32 offset; s8 *cursor; u16 firstUnitId; u32 kind; void *units; void *map;
gAiUnitListCursor = &gAiUnitList;
map = *gCurrentMap;
firstUnitId = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
unitId = firstUnitId + 1;
if (unitId < firstUnitId + MAP_UNIT_GROUP_SCAN) {
offset = unitId * MAP_UNIT_STRIDE;
do {
units = (u8 *)map + MAP_UNIT_RECORDS;
kind = (u32)(M2C_FIELD(units, u8 *, offset) << 26) >> 26;
if (kind != 0) {
if (!(M2C_FIELD((u8 *)units + offset, u16 *, MAP_UNIT_FLAGS) & 1) && gUnitKindStats[kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_CAN_SUPPLY] != 0) {
cursor = gAiUnitListCursor;
gAiUnitListCursor = cursor + 1;
*cursor = unitId;
}}
unitId++;
map = *gCurrentMap;
offset += MAP_UNIT_STRIDE;
} while (unitId < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;

gAiUnitAction = &RunAiSupplyAction;
*gAiCommandState = 2;
}

