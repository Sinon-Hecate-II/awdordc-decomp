/* 18 functions from 0x0219C7EC to 0x0219D724 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* Bubble-sort the AI unit list and its parallel score array best-first: for each
 * starting index, make a right-to-left pass over the entries after it, swapping
 * adjacent entries whose earlier score is lower, so the best unit ends up first.
 * count is the number of units to sort; the list's 0 terminator is left alone. */
void SortAiUnitsBestFirst(s32 count) {
    extern u8 gAiUnitList;
    extern s8 gAiUnitScores;
    s32 n, i, j;
    u8 *scores, *units;
    u8 left, right, unit;
    if (count < 2) return;
    n = count - 2;
    i = 0;
    if (n < 0) return;
    do {
        j = n;
        if (n >= i) {
            scores = (u8 *)&gAiUnitScores + n;
            units = &gAiUnitList + n;
            do {
                right = scores[1];
                left = scores[0];
                if ((u32)left < (u32)right) {
                    scores[0] = right;
                    scores[1] = left;
                    unit = units[0];
                    units[0] = units[1];
                    units[1] = unit;
                }
                j--;
                scores--;
                units--;
            } while (j >= i);
        }
        i++;
    } while (i <= n);
}

/* Bubble-sort the AI unit list and its parallel score array worst-first: for each
 * starting index, make a right-to-left pass over the entries after it, swapping
 * adjacent entries whose earlier score is higher, so the worst unit ends up first.
 * count is the number of units to sort; the list's 0 terminator is left alone. */
void SortAiUnitsWorstFirst(s32 count) {
    extern u8 gAiUnitList;
    extern s8 gAiUnitScores;
    s32 n, i, j;
    u8 *scores, *units;
    u8 left, right, unit;
    if (count < 2) return;
    n = count - 2;
    i = 0;
    if (n < 0) return;
    do {
        j = n;
        if (n >= i) {
            scores = (u8 *)&gAiUnitScores + n;
            units = &gAiUnitList + n;
            do {
                right = scores[1];
                left = scores[0];
                if ((u32)left > (u32)right) {
                    scores[0] = right;
                    scores[1] = left;
                    unit = units[0];
                    units[0] = units[1];
                    units[1] = unit;
                }
                j--;
                scores--;
                units--;
            } while (j >= i);
        }
        i++;
    } while (i <= n);
}

void func_ov000_0219c8fc(void){
void SortAiUnitsBestFirst(s32);extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
u8 *p=&gAiUnitList;s8 *q=&gAiUnitScores;s32 *base=gCurrentMap;s32 n=0;u8 x;
loop:x=*p;if(x!=0){s32 a=x*14+(*base+0x59a4);p++;*q=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>24;if(((u32)(M2C_FIELD(a,u16 *,8)<<26)>>26)!=63)*q=*(volatile u8 *)q+1;q++;n++;goto loop;}
SortAiUnitsBestFirst(n);
}
#pragma opt_common_subs reset
void ScoreAiUnitsByHp(void){
void SortAiUnitsBestFirst(s32);extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
u8 *p; s8 *q; s32 *base; s32 n;u8 x;
base=gCurrentMap;p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop:x=*p;if(x!=0){p++;(*q)=(u8)((u32)(M2C_FIELD(*base+x*14,u16 *,0x59aa)<<25)>>25);q++;n++;goto loop;}SortAiUnitsBestFirst(n);
}

void ScoreAiUnitsByMoveRange(s32 arg0) {
    u8 GetUnitKindMoveRange(s32);
    void SortAiUnitsWorstFirst(s32);
    void SortAiUnitsBestFirst(s32);
    extern s32 *gCurrentMap;
    extern u8 gAiUnitList;
    extern s8 gAiUnitScores;
    s32 var_r8;
    u8 *var_r9;
    u8 var_r1;
    s8 *var_r10;

    var_r9 = &gAiUnitList;
    var_r10 = &gAiUnitScores;
    var_r8 = 0;
loop:
    var_r1 = *var_r9;
    if (!var_r1) goto done;
    if (((u32)(M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x11) {
        *var_r10 = (s8)(GetUnitKindMoveRange(14) + 1);
    } else if (((u32)(M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x0F) {
        *var_r10 = (s8)(GetUnitKindMoveRange(14) + 2);
    } else {
        *var_r10 = (s8)GetUnitKindMoveRange(((u32)(M2C_FIELD(var_r1 * 14 + *gCurrentMap, u8 *, 0x59A4) << 0x1A) >> 0x1A));
    }
    var_r9 += 1;
    var_r10++;
    var_r8 += 1;
    goto loop;
done:
    if (arg0 == 0) {
        SortAiUnitsWorstFirst(var_r8);
    } else {
        SortAiUnitsBestFirst(var_r8);
    }
}

/* Score the current player's AI units by movement type: a kind-17 unit moves as a
 * kind-14 unit plus one, a kind-15 unit as a kind-14 unit plus two, everything else
 * as its own kind; sea and air kinds not loaded on a transport lose ten points more.
 * The scored unit-id list is then sorted best-first. */
void func_ov000_0219caac(void) {
u8 GetUnitKindMoveRange(s32);void SortAiUnitsWorstFirst(s32);
extern u8 gAiUnitList;extern s8 gAiUnitScores;extern s32 *gCurrentMap;extern u8 gUnitKindStats[];
s32 count;u8 *entry;u8 *p;u8 *q;u8 unit;u32 kind;
p=&gAiUnitList;q=(u8 *)&gAiUnitScores;count=0;
while(1){
unit=*p;if(!unit)break;
entry=(u8 *)(*gCurrentMap+MAP_UNIT_RECORDS+unit*MAP_UNIT_STRIDE);
kind=(u32)(*entry<<26)>>26;
if(kind==17)*q=GetUnitKindMoveRange(14)+1;
else if(kind==15)*q=GetUnitKindMoveRange(14)+2;
else *q=GetUnitKindMoveRange(kind);
kind=(u32)(*entry<<26)>>26;
if(gUnitKindStats[kind*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_FLAGS]&UNIT_KIND_FLAGS_SEA)
if(!(*(u16 *)(entry+MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED))*q=*(volatile u8 *)q+10;
p++;q++;count++;
}
SortAiUnitsWorstFirst(count);
}

void ScoreAiUnitsByAttackRange(void) {
    void SortAiUnitsWorstFirst(s32);
    s8 GetUnitKindMaxAttackRange(u32);
    extern s32 *gCurrentMap;
    extern u8 gAiUnitList;
    extern s8 gAiUnitScores;
    s32 var_r4;
    u8 *var_r5;
    s8 *var_r6;
    u8 temp_r1;

    var_r5 = &gAiUnitList;
    var_r6 = &gAiUnitScores;
    var_r4 = 0;
loop_1:
    temp_r1 = *var_r5;
    if (temp_r1 != 0) {
        *var_r6 = GetUnitKindMaxAttackRange((u32) (M2C_FIELD(((temp_r1 * 0xE) + *gCurrentMap), u8 *, 0x59A4) << 0x1A) >> 0x1A);
        var_r6 += 1;
        ++var_r5;
        ++var_r4;
        goto loop_1;
    }
    SortAiUnitsWorstFirst(var_r4);
}

void ScoreAiUnitsByPosition(s32 arg0) {
s8 GetUnitMoveScoreWeather(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop: x=*p;if(x){a=x*14+(*gCurrentMap+0x59a4);*q=GetUnitMoveScoreWeather(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));q++;p++;n++;goto loop;}
if(arg0==0){SortAiUnitsWorstFirst(n);return;}SortAiUnitsBestFirst(n);
}

/* Score the AI unit list by each unit's weather-aware move score at its own
 * tile, add ten to every unit that is not riding a transport, then order the
 * list worst-first. */
void ScoreAiUnitsByWeatherMove(void) {
s8 GetUnitMoveScoreWeather(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 count;u8 *units;s8 *scores;u8 unit;s32 record;
units=&gAiUnitList;scores=&gAiUnitScores;count=0;
loop: unit=*units;if(unit){record=unit*MAP_UNIT_STRIDE+(*gCurrentMap+MAP_UNIT_RECORDS);*scores=GetUnitMoveScoreWeather(record,M2C_FIELD(record,u8 *,MAP_UNIT_X),M2C_FIELD(record,u8 *,MAP_UNIT_Y));units++;count++;if(!(M2C_FIELD(record,u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_LOADED))*scores=*(volatile u8*)scores+10;scores++;goto loop;}
SortAiUnitsWorstFirst(count);
}

void ScoreAiUnitsByProperty(void){
void SortAiUnitsBestFirst(s32);s32 IsUnitProductionTerrain(u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 n,a;u8 *p;s8 *q;u8 x;u32 yv,xv; s32 xa,ya;
p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop:x=*p;if(x){
u8 *map=(u8 *)*gCurrentMap;
a=(s32)(map+MAP_UNIT_RECORDS+x*MAP_UNIT_STRIDE);
yv=M2C_FIELD(a,u8 *,2);xv=M2C_FIELD(a,u8 *,1);
ya=(s32)&map[yv*2];xa=(s32)&map[xv];
if(IsUnitProductionTerrain(M2C_FIELD(M2C_FIELD(ya,u16 *,0x3758)+xa,u8 *,0x1420))){
if(!M2C_FIELD(a,u8 *,12))*q=5;
else if(M2C_FIELD(a,u8 *,13))*q=4;
else *q=3;
}else{
if(!M2C_FIELD(a,u8 *,12))*q=2;
else if(M2C_FIELD(a,u8 *,13))*q=1;
else *q=0;
}
p++;q++;n++;goto loop;
}
SortAiUnitsBestFirst(n);
}

/* Moves the current player's selected unit to the end of the AI's unit list,
 * closing the gap it leaves so the AI acts with the other units first. */
void MoveSelectedAiUnitLast(void) {
    s32 IsUnitSelected(s32);
    extern s32 *gCurrentMap;
    extern u8 gAiUnitList;
    unsigned index;
    u8 unit;
    register u8 *dst;
    u8 next;
    u8 *slot;
    u8 entry;
    long found;

    index = 0;
    slot = &gAiUnitList;
    found = 0;
    unit = 0;
loop_1:
    entry = *slot;
    if (entry) {
        if (IsUnitSelected((entry * MAP_UNIT_STRIDE) + (*gCurrentMap + MAP_UNIT_RECORDS)) != 0) {
            found = index;
            unit = (&gAiUnitList)[index];
        } else {
            ++slot;
            ++index;
            goto loop_1;
        }
    }
    if (unit == 0) {
        return;
    }
    dst = &(&gAiUnitList)[found];
loop_8:
    next = M2C_FIELD(dst, u8 *, 1);
    if (next) {
        ++dst;
        M2C_FIELD(dst, u8 *, 0) = next;
        ++found;
        goto loop_8;
    }
    (&gAiUnitList)[found] = unit;
}

/* Collects the current player's role-1 units that are placed on the map, have not
   acted yet and carry no flag 0, stores their unit ids in gAiUnitList (0-terminated),
   then starts the matching AI action handler and moves the command to phase 2. */
void BuildAiRole1UnitList(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern u8 gAiUnitList;
    extern M2C_UNK func_ov000_02180e4c;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)];
    index = baseIndex + 1;
    if (index < baseIndex + MAP_UNIT_GROUP_SCAN) {
        stride = index * MAP_UNIT_STRIDE;
        do {
            table = (u8 *)obj + MAP_UNIT_RECORDS;
            type = (u32)(M2C_FIELD(table, u8 *, stride + MAP_UNIT_KIND) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, MAP_UNIT_FLAGS) & 1)
                    && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 1
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u16 *, MAP_UNIT_CAPTURE) << 0x10) >> 0x1B) != 0
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, MAP_UNIT_AI_STATE) << 0x1C) >> 0x1C) == 0) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += MAP_UNIT_STRIDE;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    gAiUnitAction = &func_ov000_02180e4c;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 2;
}

/* Collects the current player's role-1 units that are holding an AI step
   (MAP_UNIT_AI_STATE low nibble nonzero) and have not acted yet, stores their ids
   in gAiUnitList (0-terminated), scores and sorts that list, then installs the
   role-1 continuation callback and moves the AI command to phase 2.
   BuildScoredAiRole1UnitList is the same scan for units whose step is still 0. */
void BuildScoredAiRole1UnitListWithAiStep(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern u8 gAiUnitList;
    extern M2C_UNK func_ov000_02180ec8;
    void func_ov000_0219c8fc(void);
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)];
    index = baseIndex + 1;
    if (index < baseIndex + MAP_UNIT_GROUP_SCAN) {
        stride = index * MAP_UNIT_STRIDE;
        do {
            table = (u8 *)obj + MAP_UNIT_RECORDS;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, MAP_UNIT_FLAGS) & 1)
                    && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 1
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, MAP_UNIT_AI_STATE) << 0x1C) >> 0x1C) != 0) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += MAP_UNIT_STRIDE;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    func_ov000_0219c8fc();
    gAiUnitAction = &func_ov000_02180ec8;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 2;
}

/* Collects the current player's role-1 units that have not acted yet (AI step 0) and
   carry no bit-1 flag, stores their ids in gAiUnitList (0-terminated), scores and sorts
   that list, then installs the role-1 action callback and moves the AI command to phase 2.
   Unlike BuildAiRole1UnitList it does not require the unit to be placed (no facing gate). */
void BuildScoredAiRole1UnitList(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern u8 gAiUnitList;
    extern M2C_UNK PlanAiAdvanceDestination;
    void func_ov000_0219c8fc(void);
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)];
    index = baseIndex + 1;
    if (index < baseIndex + MAP_UNIT_GROUP_SCAN) {
        stride = index * MAP_UNIT_STRIDE;
        do {
            table = (u8 *)obj + MAP_UNIT_RECORDS;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, MAP_UNIT_FLAGS) & 1)
                    && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 1
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u8 *, MAP_UNIT_AI_STATE) << 0x1C) >> 0x1C) == 0) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += MAP_UNIT_STRIDE;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    func_ov000_0219c8fc();
    gAiUnitAction = &PlanAiAdvanceDestination;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 2;
}

#pragma scheduling off
void func_ov000_0219d220(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern u8 gAiUnitList;
    u8 IsMidActionStep(s32);
    void func_ov000_0219c8fc(void);
    extern M2C_UNK RunAIUnitAction;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    obj = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1)
                    && gUnitKindStats[type * 0x70 + 0x14] == 1) {
                    u32 nibble = (u32)(M2C_FIELD((u8 *)table + stride, u8 *, 0xB) << 0x1C) >> 0x1C;
                    if (nibble != 0 && IsMidActionStep((s32)nibble) != 0) {
                        out = gAiUnitListCursor;
                        gAiUnitListCursor = out + 1;
                        *out = index;
                    }
                }
            }
            index++;
            obj = *gCurrentMap;
            stride += 14;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    func_ov000_0219c8fc();
    gAiUnitAction = &RunAIUnitAction;
    *gAiCommandState = 2;
}
#pragma scheduling on
/* Collect the player's ready units whose kind has AI role 4, order them (by HP,
   then by position in fog or snow, by movement range in clear weather), put the
   chosen unit first and install the role-4 action callback for the AI turn. */
void SelectAiRole4Unit(void) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern u8 gAiUnitList;
extern M2C_UNK RunAiRole4Or6Action;
void ScoreAiUnitsByHp(void);
void ScoreAiUnitsByPosition(s32);
void ScoreAiUnitsByMoveRange(s32);
void MoveSelectedAiUnitLast(void);
s32 index; s32 stride; s8 *out; u16 baseIndex; u32 type; void *table; void *obj;
gAiUnitListCursor = &gAiUnitList;
obj = *gCurrentMap;
baseIndex = gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)];
index = baseIndex + 1;
if (index < baseIndex + 0x33) {
stride = index * MAP_UNIT_STRIDE;
do {
table = (u8 *)obj + MAP_UNIT_RECORDS;
type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
if (type != 0) {
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 4) {
out = gAiUnitListCursor;
gAiUnitListCursor = out + 1;
*out = index;
}
}
index++;
obj = *gCurrentMap;
stride += MAP_UNIT_STRIDE;
} while (index < gPlayerUnitIdBase[M2C_FIELD(obj, u16 *, MAP_CURRENT_PLAYER)] + 0x33);
}
*gAiUnitListCursor = 0;
gAiUnitListCursor = &gAiUnitList;
ScoreAiUnitsByHp();
if (M2C_FIELD(*gCurrentMap, u8 *, MAP_FOG) != 0 || M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER) == 2) {
    ScoreAiUnitsByPosition(1);
} else {
    ScoreAiUnitsByMoveRange(0);
}
MoveSelectedAiUnitLast();
gAiUnitAction = &RunAiRole4Or6Action;
*gAiCommandState = 2;
}

void func_ov000_0219d4b4(void) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern u8 gAiUnitList;
extern M2C_UNK func_ov000_021812a8;
void ScoreAiUnitsByWeatherMove(void);
void func_ov000_0219caac(void);
void MoveSelectedAiUnitLast(void);
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
if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && gUnitKindStats[type * 0x70 + 0x14] == 4) {
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
if (M2C_FIELD(*gCurrentMap, u8 *, 0x5156) != 0) goto do_caac;
if (M2C_FIELD(*gCurrentMap, u8 *, 0x5158) == 2) {
ScoreAiUnitsByWeatherMove();
}
goto skip;
do_caac:
func_ov000_0219caac();
skip:
MoveSelectedAiUnitLast();
gAiUnitAction = &func_ov000_021812a8;
*gAiCommandState = 2;
}

/* AI turn phase starter for role-3 units: collect the current player's ready
   ones into gAiUnitList, order them by HP and then by their kind's maximum attack
   range, install the role-3 action callback and move the AI command to phase 2. */
void SelectAiRole3UnitByRange(void) {
    extern s32 *gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    extern u8 gUnitKindStats[];
    extern s8 *gAiCommandState;
    extern M2C_UNK *gAiUnitAction;
    extern s8 *gAiUnitListCursor;
    extern u8 gAiUnitList;
    extern M2C_UNK RunAiRole3ActionByRange;
    void ScoreAiUnitsByHp(void);
    void ScoreAiUnitsByAttackRange(void);
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *units;
    void *map;

    gAiUnitListCursor = (s8 *)&gAiUnitList;
    map = *gCurrentMap;
    baseIndex = gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)];
    index = baseIndex + 1;
    if (index < baseIndex + MAP_UNIT_GROUP_SCAN) {
        stride = index * MAP_UNIT_STRIDE;
        do {
            units = (u8 *)map + MAP_UNIT_RECORDS;
            type = (u32)(M2C_FIELD(units, u8 *, stride + MAP_UNIT_KIND) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)units + stride, u16 *, MAP_UNIT_FLAGS) & 1)
                    && gUnitKindStats[type * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_AI_ROLE] == 3) {
                    out = gAiUnitListCursor;
                    gAiUnitListCursor = out + 1;
                    *out = index;
                }
            }
            index++;
            map = *gCurrentMap;
            stride += MAP_UNIT_STRIDE;
        } while (index < gPlayerUnitIdBase[M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN);
    }
    *gAiUnitListCursor = 0;
    gAiUnitListCursor = (s8 *)&gAiUnitList;
    ScoreAiUnitsByHp();
    ScoreAiUnitsByAttackRange();
    gAiUnitAction = &RunAiRole3ActionByRange;
    gAiCommandState[AI_COMMAND_STATE_PHASE] = 2;
}

