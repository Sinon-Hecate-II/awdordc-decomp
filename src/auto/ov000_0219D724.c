/* 19 functions from 0x0219D724 to 0x0219E6D4 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

void func_ov000_0219d724(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK func_ov000_02181470;
void ScoreAiUnitsByMoveRange(int);
void MoveChosenAiUnitFirst(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
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
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 3) {
out = gAiUnitListCursor;
gAiUnitListCursor = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByMoveRange(1);
MoveChosenAiUnitFirst();
gAiUnitAction = &func_ov000_02181470;
*gAiCommandState = 2;
}

void func_ov000_0219d848(void) {
    /* Collect the indices of type-6 map entries into a list, then install the
       func_ov000_021811e8 callback. */
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_021811e8;
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
    gAiUnitAction = &func_ov000_021811e8;
    *gAiCommandState = 2;
}

void func_ov000_0219d960(void) {
    /* Variant of func_ov000_0219d848 installing func_ov000_02181560. */
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_02181560;
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
    gAiUnitAction = &func_ov000_02181560;
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

void func_ov000_0219db90(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_021855e4;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_021855e4;
 *gAiCommandState = 2;
}

void func_ov000_0219dbe8(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_0219b3c8;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_0219b3c8;
 *gAiCommandState = 2;
}

void func_ov000_0219dc40(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_0219a6c8;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_0219a6c8;
 *gAiCommandState = 2;
}

void func_ov000_0219dc98(void) {
    s8 FindBestSelectableUnit();
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_02181ba4;
    s8 *temp_r3;
    s8 temp_r0;

    gAiUnitListCursor = &gAiUnitList;
    temp_r0 = FindBestSelectableUnit();
    if (temp_r0 != 0) {
        temp_r3 = gAiUnitListCursor;
        gAiUnitListCursor = temp_r3 + 1;
        *temp_r3 = temp_r0;
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &func_ov000_02181ba4;
    *gAiCommandState = 2;
}

void func_ov000_0219dd14(void) {
    s8 func_ov000_021aa214();
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern s8 gAiUnitList;
    extern M2C_UNK func_ov000_02181c10;
    s8 *temp_r3;
    s8 temp_r0;

    gAiUnitListCursor = &gAiUnitList;
    temp_r0 = func_ov000_021aa214();
    if (temp_r0 != 0) {
        temp_r3 = gAiUnitListCursor;
        gAiUnitListCursor = temp_r3 + 1;
        *temp_r3 = temp_r0;
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = &gAiUnitList;
    gAiUnitAction = &func_ov000_02181c10;
    *gAiCommandState = 2;
}

void func_ov000_0219dd90(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK AssignUnitMoveTargets;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &AssignUnitMoveTargets;
 *gAiCommandState = 2;
}

void func_ov000_0219dde8(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_0217d6dc;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_0217d6dc;
 *gAiCommandState = 2;
}

void func_ov000_0219de40(void) {
 extern s8 *gAiCommandState;
 extern M2C_UNK *gAiUnitAction;
 extern s8 *gAiUnitListCursor;
 extern s8 gAiUnitList;
 extern M2C_UNK func_ov000_0217d850;
 gAiUnitListCursor = &gAiUnitList;
 *gAiUnitListCursor++ = 0x40;
 *gAiUnitListCursor = 0;
 gAiUnitListCursor = &gAiUnitList;
 gAiUnitAction = &func_ov000_0217d850;
 *gAiCommandState = 2;
}

void func_ov000_0219de98(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK func_ov000_021816ac;
s32 index,stride;
s8 *out;
u16 baseIndex;
u32 type;
void *table,*obj,*unit;
gAiUnitListCursor=&gAiUnitList;
obj=*gCurrentMap;
baseIndex=gPlayerUnitIdBase[M2C_FIELD(obj,u16 *,0x52a4)];
index=baseIndex+1;
if(index<baseIndex+0x33) {
stride=index*14;
do {
table=(u8 *)obj+0x59a4;
unit=(u8 *)table+stride;
type=(u32)(M2C_FIELD(table,u8 *,stride)<<26)>>26;
if(type!=0) {
if(!(M2C_FIELD(unit,u16 *,4)&1)&&type==13) {
if(((u32)(M2C_FIELD(unit,u16 *,6)<<16)>>27)!=0) {
out=gAiUnitListCursor;
gAiUnitListCursor=out+1;
*out=index;
}
}
}
index++;obj=*gCurrentMap;stride+=14;
}while(index<gPlayerUnitIdBase[M2C_FIELD(obj,u16 *,0x52a4)]+0x33);
}
*gAiUnitListCursor=0;
gAiUnitListCursor=&gAiUnitList;
gAiUnitAction=&func_ov000_021816ac;
*gAiCommandState=2;
}

void func_ov000_0219dfac(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK func_ov000_021816c4;
void ScoreAiUnitsByMoveRange(int);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
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
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 2 && M2C_FIELD((u8 *)table + stride, u8 *, 0xC) == 0) {
out = gAiUnitListCursor;
gAiUnitListCursor = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByMoveRange(0);
gAiUnitAction = &func_ov000_021816c4;
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
    extern M2C_UNK func_ov000_021817c0;
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
    gAiUnitAction = &func_ov000_021817c0;
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
    extern M2C_UNK func_ov000_0218190c;
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
    gAiUnitAction = &func_ov000_0218190c;
    *gAiCommandState = 2;
}

void func_ov000_0219e49c(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK func_ov000_02181a14;
void func_ov000_0219cd0c(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
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
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 5) {
out = gAiUnitListCursor;
gAiUnitListCursor = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
func_ov000_0219cd0c();
gAiUnitAction = &func_ov000_02181a14;
*gAiCommandState = 2;
}

void func_ov000_0219e5b8(void) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern s8 gAiUnitList;
extern M2C_UNK func_ov000_02181b34;
void func_ov000_0219cd0c(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
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
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x69] != 0) {
out = gAiUnitListCursor;
gAiUnitListCursor = out + 1;
*out = index;
}}
index++;
obj = *gCurrentMap;
stride += 14;
} while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;

gAiUnitAction = &func_ov000_02181b34;
*gAiCommandState = 2;
}

