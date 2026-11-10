/* 7 functions from 0x0216ABA8 to 0x0216B898 (ov000), found by ds-decomp. */
#include "common.h"
#pragma optimization_level 0
static inline u16 ScriptTurn16(void) { extern s32 *gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x52a2); }
static inline u16 ScriptPhase16(void) { extern s32 *gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x52a4); }
#pragma optimization_level reset
typedef struct ScriptPlayer16 { u8 pad[0x71]; u8 flag; u8 tail[26]; } ScriptPlayer16;
typedef struct ScriptPlayers16 { u8 pad[0x67a4]; ScriptPlayer16 players[4]; } ScriptPlayers16;
typedef struct ScriptMapNested16 { u8 pad[0x59a4]; struct { u8 entries[256][14]; } units; } ScriptMapNested16;

typedef struct ScriptUnit16 { u8 kind:6; u8 team:2; u8 rest[13]; } ScriptUnit16;
typedef struct ScriptMap16 { u8 pad[0x59a4]; ScriptUnit16 units[256]; } ScriptMap16;
#pragma optimization_level 0
typedef struct ScriptUnitsBlock16 { ScriptUnit16 entries[256]; } ScriptUnitsBlock16;
static inline ScriptUnitsBlock16 *ScriptBlock16(void) { extern s32 *gCurrentMap; return (ScriptUnitsBlock16*)&((ScriptMapNested16*)*gCurrentMap)->units; }
static inline ScriptUnit16 *ScriptUnits16(void) { return ScriptBlock16()->entries; }
static inline ScriptUnit16 *ScriptUnitAt16(s32 n) { return &ScriptBlock16()->entries[n]; }
static inline ScriptPlayer16 *ScriptPlayerAt16(s32 n) { extern s32 *gCurrentMap; return &((ScriptPlayers16*)*gCurrentMap)->players[n]; }
#pragma optimization_level reset

#pragma optimization_level 0
/* Evaluate a scripted condition list (8-byte commands, terminated by opcode 0x22):
 * return 1 when any condition/OR-group holds, otherwise 0. Failing groups are
 * skipped with SkipToNextConditionGroup; when applyEffects is set the action commands
 * of a satisfied group are also executed. */
s32 EvalScriptConditions(u8 *cmd, u8 *unit, u8 *target, s32 teamId, u8 applyEffects) {
u8 *SkipToNextConditionGroup(u8*); s32 func_02086b40(); void func_02086ae4(); void func_02094808(); s32 IsUnitSelected(); s32 GetPlayerSelectedUnit();
extern s32 *gCurrentMap;
s32 (*conditionFn)(); s32 matched=0; s32 turnMatches;
while(cmd[0]!=34) {
switch(cmd[0]) {
case 0:case 1:case 2:
turnMatches=0;
if(*(u16*)(cmd+2)==65535 || (*(u16*)(cmd+2)==0 && M2C_FIELD(*gCurrentMap,u16*,0x52a2)==0) || *(u16*)(cmd+2)==ScriptTurn16()){
if(cmd[1]==0 || cmd[1]==ScriptPhase16())turnMatches=1;
}
if(!turnMatches)cmd=SkipToNextConditionGroup(cmd);break;
case 23:case 24:case 25:
if(cmd[1]!=255 && func_02086b40(cmd[1])){cmd=SkipToNextConditionGroup(cmd);break;}
if(!applyEffects){matched=1;break;}
if(*(s32*)(cmd+4)){func_02094808(*(s32*)(cmd+4));matched=1;}
if(cmd[1]!=255)func_02086ae4(cmd[1],1);
break;
case 15:case 16:case 17:conditionFn=*(s32(**)())(cmd+4);if(conditionFn()!=1)cmd=SkipToNextConditionGroup(cmd);break;
case 18:case 19:case 20:conditionFn=*(s32(**)())(cmd+4);if(conditionFn()!=0)cmd=SkipToNextConditionGroup(cmd);break;
case 3:case 4:case 5:
if(!unit || ((ScriptUnit16*)unit)->kind!=cmd[1])cmd=SkipToNextConditionGroup(cmd);break;
case 26:
if(!unit || cmd[1]!=(((unit?((ScriptUnit16*)unit-ScriptUnitAt16(0)):0)>>6)+1))cmd=SkipToNextConditionGroup(cmd);break;
case 27:if(!unit || ((ScriptUnit16*)unit)->kind!=cmd[1])cmd=SkipToNextConditionGroup(cmd);break;
case 28:if(!unit || !IsUnitSelected(unit))cmd=SkipToNextConditionGroup(cmd);break;
case 29:
if(!target || cmd[1]!=(((target?((ScriptUnit16*)target-ScriptUnitAt16(0)):0)>>6)+1))cmd=SkipToNextConditionGroup(cmd);break;
case 30:if(!target || ((ScriptUnit16*)target)->kind!=cmd[1])cmd=SkipToNextConditionGroup(cmd);break;
case 31:if(!target || !IsUnitSelected(target))cmd=SkipToNextConditionGroup(cmd);break;
case 32:if(!GetPlayerSelectedUnit(cmd[1]))cmd=SkipToNextConditionGroup(cmd);break;
case 33:if(ScriptPlayerAt16(cmd[1])->flag)cmd=SkipToNextConditionGroup(cmd);break;
case 12:case 13:case 14:if(cmd[1]!=teamId)cmd=SkipToNextConditionGroup(cmd);break;
case 6:case 7:case 8:if(!func_02086b40(cmd[1]))cmd=SkipToNextConditionGroup(cmd);break;
case 9:case 10:case 11:if(func_02086b40(cmd[1]))cmd=SkipToNextConditionGroup(cmd);break;
case 22:cmd=SkipToNextConditionGroup(cmd);break;
default:break;
}
cmd+=8;
}
return matched;
}
u8 *SkipToNextConditionGroup(u8 *arg0) {
    while (*arg0 != 0x17 && *arg0 != 0x18 && *arg0 != 0x19) {
        if (*arg0 == 0x22) {
            return arg0;
        }
        arg0 += 8;
    }
    return arg0;
}
#pragma optimization_level reset
void *func_ov000_0216b0c8(void) {
    void *func_020a8b0c(u16);
    s32 func_020cd6d4();
    extern s32 *data_027e0058;
    switch (func_020cd6d4()) {
    case 0: return NULL;
    default: return func_020a8b0c(M2C_FIELD((*data_027e0058 + 0x5120), u16 *, 0x22));
    }
}
#pragma optimization_level 0
s32 func_ov000_0216b104(void) {  void *p=func_ov000_0216b0c8(); if(p!=0 && M2C_FIELD(p,s32 *,0x28)!=0) {return EvalScriptConditions(M2C_FIELD(p,s32 *,0x28),0,0,0,0);}else return 0;}
#pragma optimization_level reset
s32 func_ov000_0216b154(void) {
    return 0;
}

s32 func_ov000_0216b15c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

void func_ov000_0216b194(void *arg0) {
    M2C_UNK func_01ff9e44(s32, M2C_UNK, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, s32);
    s32 func_02080e30(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_0209b59c(s32, M2C_UNK);
    M2C_UNK func_0209b5e4(s32, s32);
    s32 func_0209c268();
    s8 GetSpriteAnimValue(s32);
    M2C_UNK func_020a92bc(void *, s32);
    s32 func_020cfb78();
    s32 GetLanguage();
    s32 GetLocalizedFileName(M2C_UNK *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK gMapConfig;
    extern s32 *gCurrentMap;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern void *data_ov000_021b83b0[];
    extern void *data_ov000_021b83c4[];
    extern M2C_UNK data_ov000_021b869c;
    extern M2C_UNK data_ov000_021b86a8;
    extern M2C_UNK data_ov000_021b86b0;
    extern M2C_UNK data_ov000_021b86b8;
    extern M2C_UNK data_ov000_021b86c4;
    extern M2C_UNK data_ov000_021b86cc;
    extern M2C_UNK data_ov000_021b86d4;
    extern M2C_UNK data_ov000_021b86e0;
    extern M2C_UNK data_ov000_021b86e8;
    extern M2C_UNK data_ov000_021b86f8;
    extern M2C_UNK data_ov000_021b8708;
    void *saved;
    s8 n0;
    s8 n1;
    s32 var_r0;
    s32 var_r3;
    s32 var_r3_2;
    s32 temp_r0_18;
    s32 temp_r0_23;
    s32 temp_r6_5;
    s32 off;
    s32 res;
    s16 temp_r0_19;
    s32 var_r1;
    u8 temp_r0_20;
    u8 temp_r0_21;
    u8 temp_r0_22;

    SetFileDirectory(&data_ov000_021b869c);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x16) = 0x10;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x14) = 0x1A;
    if (M2C_FIELD(arg0, u8 *, 0x3D) != 0) {
        var_r1 = (M2C_FIELD(&gMapConfig, u8 *, 3) - M2C_FIELD(*gCurrentMap, u16 *, 0x52A2)) + 1;
    } else {
        var_r1 = M2C_FIELD(*gCurrentMap, u16 *, 0x52A2);
    }
    func_020a92bc(M2C_FIELD(arg0, void **, 0x40), var_r1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), u8 *, 0x20) = (u8) ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), u8 *, 0x20) & ~0xE0) | 0x20);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    {u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|0x10;}
    {u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|0x20;}
    {u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]&~0x40;}
    {u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|0x80;}
    {u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|0x100;}
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    n0 = GetSpriteAnimValue(*M2C_FIELD(arg0, s32 **, 0x44));
    n1 = GetSpriteAnimValue(*M2C_FIELD(arg0, s32 **, 0x44));
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=(p[0]&~0xC0)|0x40;}
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s8 *, 0x51) = n1;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s8 *, 0x52) = (s8) (0x10 - n0);
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~1;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~2;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~4;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]|8;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~0x10;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~0x20;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]|0x100;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]|0x200;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~0x400;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]&~0x800;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]|0x1000;}
    {u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+0x12); p[0]=p[0]|0x2000;}
    off = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x6E80;
    LoadDecompressedFileTo(&data_ov000_021b86a8, off);
    off = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x8280;
    LoadDecompressedFileTo(&data_ov000_021b86b0, off);
    GetLocalizedFileName(&data_ov000_021b86b8);
    func_020814e4();
    off = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    res = GetLocalizedFileName(&data_ov000_021b86c4);
    func_02081590(res, off + 0x6B80);
    off = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    res = GetLocalizedFileName(&data_ov000_021b86cc);
    func_02081590(res, off + 0x8640);
    off = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    res = GetLocalizedFileName(&data_ov000_021b86d4);
    func_02081590(res, off + 0x87C0);
    func_02081528();
    temp_r0_18 = func_02080e30(&data_ov000_021b86e0, 1);
    func_01ff9e44(temp_r0_18 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0x360, 0x20);
    func_020e35cc(temp_r0_18);
    func_0209b59c(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x8FC0, 0x60);
    temp_r6_5 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    func_0209b5e4(temp_r6_5 + 0x8FC0, func_020cfb78());
    func_02091d4c(0x12);
    M2C_FIELD(arg0, s16 *, 0x3E) = 0x20;
    func_020cfb78();
    temp_r0_19 = func_0209c268();
    if ((s32) temp_r0_19 > 0x40) {
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (M2C_FIELD(arg0, s16 *, 0x3E) - (temp_r0_19 - 0x40));
    }
    if (GetLanguage() == 2) {
        temp_r0_20 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_20) {
        case 1:
            var_r0 = 0;
            break;
        case 2:
            var_r0 = 1;
            break;
        case 3:
            var_r0 = 2;
            break;
        case 4:
            var_r0 = 3;
            break;
        case 5:
            var_r0 = 4;
            break;
        case 0:
            var_r0 = 4;
            break;
        default:
            var_r0 = 0;
            break;
        }
        if (var_r0 == 0) {
            LoadDecompressedFileTo(&data_ov000_021b86e8, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x18));
            LoadDecompressedFileTo(&data_ov000_021b86f8, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x2C));
        } else {
            goto block_24;
        }
    } else {
block_24:
        temp_r0_21 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_21) {
        case 1:
            var_r3 = 0;
            break;
        case 2:
            var_r3 = 1;
            break;
        case 3:
            var_r3 = 2;
            break;
        case 4:
            var_r3 = 3;
            break;
        case 5:
            var_r3 = 4;
            break;
        case 0:
            var_r3 = 4;
            break;
        default:
            var_r3 = 0;
            break;
        }
        LoadDecompressedFileTo(data_ov000_021b83b0[var_r3], M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x18));
        temp_r0_22 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_22) {
        case 1:
            var_r3_2 = 0;
            break;
        case 2:
            var_r3_2 = 1;
            break;
        case 3:
            var_r3_2 = 2;
            break;
        case 4:
            var_r3_2 = 3;
            break;
        case 5:
            var_r3_2 = 4;
            break;
        case 0:
            var_r3_2 = 4;
            break;
        default:
            var_r3_2 = 0;
            break;
        }
        LoadDecompressedFileTo(data_ov000_021b83c4[var_r3_2], M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x2C));
    }
    func_020808dc(M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x2C), 0x20, 0x20, 6);
    temp_r0_23 = func_02080e30(&data_ov000_021b8708, 1);
    func_01ff9e44(temp_r0_23 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0xC0, 0x20);
    func_020e35cc(temp_r0_23);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3E) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x46) = 0;
    gCur3DSpriteEngine = saved;
    M2C_FIELD(arg0, s8 *, 0x36) = 1;
}

