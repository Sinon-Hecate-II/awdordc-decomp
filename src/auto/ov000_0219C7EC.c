/* 18 functions from 0x0219C7EC to 0x0219D724 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

void func_ov000_0219c7ec(s32 a){extern u8 gAiUnitList;extern s8 gAiUnitScores;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&gAiUnitScores+n;q=&gAiUnitList+n;do{y=p[1];x=p[0];if((u32)x<(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c874(s32 a){extern u8 gAiUnitList;extern s8 gAiUnitScores;s32 n,i,j;u8 *p,*q;u8 x,y,t;if(a<2)return;n=a-2;i=0;if(n<0)return;do{j=n;if(n>=i){p=(u8 *)&gAiUnitScores+n;q=&gAiUnitList+n;do{y=p[1];x=p[0];if((u32)x>(u32)y){p[0]=y;p[1]=x;t=q[0];q[0]=q[1];q[1]=t;}j--;p--;q--;}while(j>=i);}i++;}while(i<=n);}

void func_ov000_0219c8fc(void){
void func_ov000_0219c7ec(s32);extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
u8 *p=&gAiUnitList;s8 *q=&gAiUnitScores;s32 *base=gCurrentMap;s32 n=0;u8 x;
loop:x=*p;if(x!=0){s32 a=x*14+(*base+0x59a4);p++;*q=(u32)(M2C_FIELD(a,u16 *,6)<<25)>>24;if(((u32)(M2C_FIELD(a,u16 *,8)<<26)>>26)!=63)*q=*(volatile u8 *)q+1;q++;n++;goto loop;}
func_ov000_0219c7ec(n);
}
#pragma opt_common_subs reset
void ScoreAiUnitsByHp(void){
void func_ov000_0219c7ec(s32);extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
u8 *p; s8 *q; s32 *base; s32 n;u8 x;
base=gCurrentMap;p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop:x=*p;if(x!=0){p++;(*q)=(u8)((u32)(M2C_FIELD(*base+x*14,u16 *,0x59aa)<<25)>>25);q++;n++;goto loop;}func_ov000_0219c7ec(n);
}

void ScoreAiUnitsByMoveRange(s32 arg0) {
    u8 func_020a7b24(s32);
    void func_ov000_0219c874(s32);
    void func_ov000_0219c7ec(s32);
    extern s32 *data_027e0058;
    extern u8 gAiUnitList;
    extern s8 gAiUnitScores;
    s32 var_r8;
    u8 *var_r9;
    u8 var_r1;
    s8 *var_r10;
    (void)var_r1;

    var_r9 = &gAiUnitList;
    var_r10 = &gAiUnitScores;
    var_r8 = 0;
loop:
    var_r1 = *var_r9;
    if (!var_r1) goto done;
    if ((u32)((M2C_FIELD(var_r1 * 14 + *data_027e0058, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x11) {
        *var_r10 = (s8)(func_020a7b24(14) + 1);
    } else if ((u32)((M2C_FIELD(var_r1 * 14 + *data_027e0058, u8 *, 0x59A4) << 0x1A) >> 0x1A) == 0x0F) {
        *var_r10 = (s8)(func_020a7b24(14) + 2);
    } else {
        *var_r10 = (s8)func_020a7b24((u32)((M2C_FIELD(var_r1 * 14 + *data_027e0058, u8 *, 0x59A4) << 0x1A) >> 0x1A));
    }
    var_r9 += 1;
    var_r10++;
    var_r8 += 1;
    goto loop;
done:
    if (arg0 == 0) {
        func_ov000_0219c874(var_r8);
    } else {
        func_ov000_0219c7ec(var_r8);
    }
}

void func_ov000_0219caac(void) {
u8 func_020a7b24(s32);void func_ov000_0219c874(s32);
extern u8 gAiUnitList;extern s8 gAiUnitScores;extern s32 *gCurrentMap;extern u8 gUnitKindStats[];
s32 n;u8 *entry;u8 *p;u8 *q;u8 unit;u32 code;
p=&gAiUnitList;q=(u8 *)&gAiUnitScores;n=0;
while(1){
unit=*p;if(!unit)break;
entry=(u8 *)(*gCurrentMap+0x59a4+unit*14);
code=(u32)(*entry<<26)>>26;
if(code==17)*q=func_020a7b24(14)+1;
else if(code==15)*q=func_020a7b24(14)+2;
else *q=func_020a7b24(code);
code=(u32)(*entry<<26)>>26;
if(gUnitKindStats[code*112+19]&16)
if(!(*(u16 *)(entry+4)&8))*q=*(volatile u8 *)q+10;
p++;q++;n++;
}
func_ov000_0219c874(n);
}

void func_ov000_0219cb98(void) {
    void func_ov000_0219c874(s32);
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
    func_ov000_0219c874(var_r4);
}

void ScoreAiUnitsByPosition(s32 arg0) {
s8 func_020a7824(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop: x=*p;if(x){a=x*14+(*gCurrentMap+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));q++;p++;n++;goto loop;}
if(arg0==0){func_ov000_0219c874(n);return;}func_ov000_0219c7ec(n);
}

void func_ov000_0219cc84(void) {
s8 func_020a7824(s32,u8,u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 n;u8 *p;s8 *q;u8 x;s32 a;
p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop: x=*p;if(x){a=x*14+(*gCurrentMap+0x59a4);*q=func_020a7824(a,M2C_FIELD(a,u8 *,1),M2C_FIELD(a,u8 *,2));p++;n++;if(!(M2C_FIELD(a,u16 *,4)&8))*q=*(volatile u8*)q+10;q++;goto loop;}
func_ov000_0219c874(n);
}

void func_ov000_0219cd0c(void){
void func_ov000_0219c7ec(s32);s32 func_ov000_021a9084(u8);
extern s32 *gCurrentMap;extern u8 gAiUnitList;extern s8 gAiUnitScores;
s32 n,a;u8 *p;s8 *q;u8 x;u32 yv,xv; s32 xa,ya;
p=&gAiUnitList;q=&gAiUnitScores;n=0;
loop:x=*p;if(x){
s32 map=*gCurrentMap;
a=x*14+(map+0x59a4);
yv=M2C_FIELD(a,u8 *,2);xv=M2C_FIELD(a,u8 *,1);
ya=map+yv*2;xa=map+xv;
if(func_ov000_021a9084(M2C_FIELD(M2C_FIELD(ya,u16 *,0x3758)+xa,u8 *,0x1420))){
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
func_ov000_0219c7ec(n);
}

void MoveChosenAiUnitFirst(void) {
    s32 IsUnitSelected(s32);
    extern s32 *gCurrentMap;
    extern u8 gAiUnitList;
    unsigned var_r4;
    u8 var_r5;
    register u8 *var_r1;
    u8 temp_r0;
    u8 *var_r6;
    u8 temp_r1;
    long var_r7;

    var_r4 = 0;
    var_r6 = &gAiUnitList;
    var_r7 = 0;
    var_r5 = 0;
loop_1:
    temp_r1 = *var_r6;
    if (temp_r1) {
        if (IsUnitSelected((temp_r1 * 0xE) + (*gCurrentMap + 0x59A4)) != 0) {
            var_r7 = var_r4;
            var_r5 = (&gAiUnitList)[var_r4];
        } else {
            ++var_r6;
            ++var_r4;
            goto loop_1;
        }
    }
    if (var_r5 == 0) {
        return;
    }
    var_r1 = &(&gAiUnitList)[var_r7];
loop_8:
    temp_r0 = M2C_FIELD(var_r1, u8 *, 1);
    if (temp_r0) {
        ++var_r1;
        M2C_FIELD(var_r1, u8 *, 0) = temp_r0;
        ++var_r7;
        goto loop_8;
    }
    (&gAiUnitList)[var_r7] = var_r5;
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
                    && ((u32)(M2C_FIELD((u8 *)table + stride, u16 *, MAP_UNIT_FACING) << 0x10) >> 0x1B) != 0
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
    extern M2C_UNK func_ov000_02180f14;
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
    gAiUnitAction = &func_ov000_02180f14;
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
    u8 func_ov000_021a8984(s32);
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
                    if (nibble != 0 && func_ov000_021a8984((s32)nibble) != 0) {
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
extern M2C_UNK func_ov000_021811e8;
void ScoreAiUnitsByHp(void);
void ScoreAiUnitsByPosition(s32);
void ScoreAiUnitsByMoveRange(s32);
void MoveChosenAiUnitFirst(void);
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
MoveChosenAiUnitFirst();
gAiUnitAction = &func_ov000_021811e8;
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
void func_ov000_0219cc84(void);
void func_ov000_0219caac(void);
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
func_ov000_0219cc84();
}
goto skip;
do_caac:
func_ov000_0219caac();
skip:
MoveChosenAiUnitFirst();
gAiUnitAction = &func_ov000_021812a8;
*gAiCommandState = 2;
}

void func_ov000_0219d604(void) {
extern s32 *gCurrentMap;
extern u16 gPlayerUnitIdBase[];
extern u8 gUnitKindStats[];
extern s8 *gAiCommandState;
extern M2C_UNK *gAiUnitAction;
extern s8 *gAiUnitListCursor;
extern u8 gAiUnitList;
extern M2C_UNK func_ov000_021813a4;
void ScoreAiUnitsByHp(void);
void func_ov000_0219cb98(void);
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
ScoreAiUnitsByHp();
func_ov000_0219cb98();
gAiUnitAction = &func_ov000_021813a4;
*gAiCommandState = 2;
}

