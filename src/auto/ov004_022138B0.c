/* 46 functions from 0x022138B0 to 0x022148A4 (ov004), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"

/* Battle-script condition: true when the AI's standing command is a unit build
 * (kind 3) and its cursor sits on a city or base owned by player 1. */
s32 IsAiBuildingOnPlayerOneCityOrBase(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    u8 terrain;
    u8 *unit;
    u8 *map;
    u8 x, y;
    map = *gCurrentMap;
    unit = M2C_FIELD(map, u8 **, MAP_CURSOR_UNIT);
    x = unit[MAP_UNIT_X]; y = unit[MAP_UNIT_Y];
    if (gAiCommand == AI_COMMAND_PRODUCE_UNIT) {
        unit = map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS));
        terrain = unit[MAP_CELL_TERRAIN];
        if (((s32)(terrain & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT) == 1 &&
            (u32)((terrain & MAP_TERRAIN_KIND_MASK) - MAP_TERRAIN_CITY) <= 1) return 1;
    }
    return 0;
}

u8 func_ov004_0221392c(void) {
    extern void **gCurrentMap;
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0x52D0), u8 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_0221395c(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    if (gAiCommand == 0x18 && ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u8 *, 0) << 26) >> 26) == 0xD) return 1;
    return 0;
}

/* Battle-script condition: true when the standing command sets a player's AI
 * mode (kind 24) and the unit under the cursor stands on a temporary airfield
 * owned by player 1. */
s32 IsSetAiModeCommandOnPlayerOneTempAirfield(void) {
    extern void **gCurrentMap;
    extern u8 gAiCommand;
    u8 value;
    u8 *p;
    u8 *base;
    u8 x, y;
    base = *gCurrentMap;
    p = M2C_FIELD(base, u8 **, MAP_CURSOR_UNIT);
    x = p[MAP_UNIT_X]; y = p[MAP_UNIT_Y];
    if (gAiCommand == AI_COMMAND_SET_AI_MODE) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, MAP_ROW_OFFSETS));
        value = p[MAP_CELL_TERRAIN];
        if (((s32)(value & MAP_TERRAIN_OWNER_MASK) >> MAP_PROPERTY_TILE_OWNER_SHIFT) == 1 && (value & MAP_TERRAIN_KIND_MASK) == MAP_TERRAIN_TEMP_AIRFIELD) return 1;
    }
    return 0;
}

/* Battle-script condition for player 1's opening move: on the first turn only,
 * returns 0 when exactly two of player 1's infantry stand east of column 13 and
 * one kind-4 unit stands east of column 12; 1 on any later turn or any other
 * arrangement. */
s32 CheckPlayerOneOpeningFormation(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 infantryCount=0,kind4Count=0; u8 *map=*gCurrentMap; s32 i,end; u8 *unit; u32 kind;
 if ((s32)M2C_FIELD(map,u16 *,MAP_TURN)>1) return 0;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+MAP_UNIT_GROUP_SCAN;
 if(i<end) {unit=map+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
 do {kind=(u32)(unit[MAP_UNIT_KIND]<<26)>>26;
 if(kind) {switch(kind) {case UNIT_KIND_INFANTRY: if(unit[MAP_UNIT_X]>=13U)infantryCount++;break; case 4:if(unit[MAP_UNIT_X]>=12U)kind4Count++;break;}}
 i++; unit+=MAP_UNIT_STRIDE;
 }while(i<end);}
 if(infantryCount==2 && kind4Count==1)return 0;
 return 1;
}

/* True (1) when player 2's unit group holds no units: counts the group's
 * occupied records (ids gPlayerUnitIdBase[2]+1 .. +0x32). */
s32 PlayerTwoHasNoUnits(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 count; s32 i; u8 *unit; s32 end; u8 kind;
 count=0; i=gPlayerUnitIdBase[2]+1; end=gPlayerUnitIdBase[2]+MAP_UNIT_GROUP_SCAN;
 if(i<end) {unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
 do {kind=*unit; if((u32)(kind<<26)>>26) count++; i++; unit+=MAP_UNIT_STRIDE;}while(i<end);}
 if(count!=0)return 0; return 1;
}

/* Tests whether player 2 has any occupied unit records. */
s32 Ov004_IsPlayerTwoArmyEmpty(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount;
    s32 unitId;
    u8 *unit;
    s32 endId;
    u8 kindAndRank;

    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kindAndRank = unit[MAP_UNIT_KIND];
            if ((u32)(kindAndRank << 26) >> 26) {
                unitCount++;
            }
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    if (unitCount != 0) {
        return 0;
    }
    return 1;
}

void func_ov004_02213bb8(void) {
extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
s32 RandomIntRange(s32,s32); s32 func_020a7bbc(s32); void func_02086930(s32,u8);
u8 buf[27],out[27]; s32 i,t,cnt,maxCount,chosen,primCount,j; u32 outCount; void **map; s32 wt; u8 *dst;
for(j=0;j<27;j++)buf[j]=0;
map=gCurrentMap;
for(i=gPlayerUnitIdBase[M2C_FIELD(*map,u16 *,0x52a4)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*map,u16 *,0x52a4)]+0x33;i++){
cnt=(u32)((s32)M2C_FIELD((char *)*(void * volatile *)map+i*14,u8 *,0x59a4)<<26)>>26;
if(cnt)buf[cnt]++;
}
outCount=0;dst=out;
primCount=outCount;
for (;;) {
maxCount=0;chosen=-1;
for(t=0;t<27;t++){
if(buf[t]==0)continue;
if(maxCount>buf[t])continue;
if(chosen!=-1 && maxCount==buf[t]){
wt=func_020a7bbc(t);
if(wt<func_020a7bbc(chosen))continue;
}
maxCount=buf[t];chosen=t;
}
if(chosen==-1)break;
buf[(u8)chosen]=0;
*dst++=chosen;
++outCount;
if (++primCount >= 3) break;
}
if(maxCount!=0){u8 *end=out+outCount;for(i=0;i<27;i++){if(maxCount==buf[i]){*end++=i;outCount++;}}}
if(outCount){i=RandomIntRange(0,outCount-1);func_02086930(0,out[i]);}
else func_02086930(0,0);
}

void func_ov004_02213d90(void) {
    M2C_UNK SetUiMessageText(s32);
    s32 func_02086a20(M2C_UNK);
    extern s32 data_ov004_02225f70[];
    SetUiMessageText(data_ov004_02225f70[func_02086a20(0)]);
}

void func_ov004_02213db0(void) {
    M2C_UNK SetUiMessageText(s32);
    s32 func_02086a20(M2C_UNK);
    extern s32 data_ov004_02225fdc[];
    SetUiMessageText(data_ov004_02225fdc[func_02086a20(0)]);
}

/* Mark every unit of the current player whose kind is the AI's chosen kind as
 * having acted, so it is skipped for the rest of the turn.  Does nothing when
 * no kind was chosen (kind 0). */
void Ov004_MarkChosenKindActed(void) {
extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
s32 func_02086a20(M2C_UNK);
s32 i; u8 *p;
if(func_02086a20(0)==0)return;
for(i=gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)]+MAP_UNIT_GROUP_SCAN;i++){
p=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
if((u32)(p[0]<<26)>>26) {
if(func_02086a20(0)==((u32)(p[0]<<26)>>26)) M2C_FIELD(p,u16 *,MAP_UNIT_FLAGS)|=UNIT_FLAG_ACTED;
}
}
}

u8 func_ov004_02213e94(void) {
 extern void **gCurrentMap;
 s32 n=M2C_FIELD(*gCurrentMap,u16 *,0x52A2); u8 r;
 if(n<=0)return 0;
 if(((n+1)&3)==0)r=1;else r=0; return r;
}

u8 func_ov004_02213ed0(void) {
 extern void **gCurrentMap;
 s32 n=M2C_FIELD(*gCurrentMap,u16 *,0x52A2); u8 r;
 if(n<=0)return 0;
 if((n&3)==0)r=1;else r=0; return r;
}

/* Battle-script condition: true when player 2 has no units left on the map, i.e.
 * none of its unit slots (base+1 .. base+MAP_UNIT_GROUP_SCAN) holds a live kind. */
s32 IsPlayerTwoUnitGroupEmpty(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count;
    s32 i;
    u8 *unit;
    s32 end;
    u8 kind;

    count = 0;
    i = gPlayerUnitIdBase[2] + 1;
    end = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            kind = *unit;
            if ((u32)(kind << 26) >> 26) count++;
            i++;
            unit += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    if (count != 0) return 0;
    return 1;
}

u8 func_ov004_02213f78(void) {
 void *GetPlayerSelectedUnit(u16); extern void **gCurrentMap;
 u8 r; if(GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)))r=1;else r=0;return r;
}

void func_ov004_02213fac(void) {
 void *GetPlayerSelectedUnit(u16); extern void **gCurrentMap;
 void *p=GetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,0x52A4));
 if(p)M2C_FIELD(p,u16 *,4)|=1;
}

s32 func_ov004_02213fe0(void) {
 extern void **gCurrentMap;
 void *p=*gCurrentMap;
 s16 a=M2C_FIELD(p,s16 *,0x52DC), b=M2C_FIELD(p,s16 *,0x52DE);
 return a==0 && b==4;
}

u8 func_ov004_02214010(void) {
    s32 IsEventFlagSet(M2C_UNK);
    u8 var_r0;

    if (IsEventFlagSet(0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214030(void) {
    s32 GetCoPowerMeterPoints(M2C_UNK);
    u8 var_r0;

    if (GetCoPowerMeterPoints(1) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214050(void) {
    s32 GetCoPowerMeterCost(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    u8 var_r0;

    temp_r4 = GetCoPowerMeterCost(1, 2);
    if ((temp_r4 - GetCoPowerMeterPoints(1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* ov004 battle-script condition: true (1) when player 2's unit group holds no
 * units (ids gPlayerUnitIdBase[2]+1 .. +0x32), false when any record is occupied. */
s32 IsPlayerTwoGroupEmpty(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 count; s32 i; u8 *unit; s32 end; u8 kind;
 count=0; i=gPlayerUnitIdBase[2]+1; end=gPlayerUnitIdBase[2]+MAP_UNIT_GROUP_SCAN;
 if(i<end) {unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+i*MAP_UNIT_STRIDE;
 do {kind=*unit; if((u32)(kind<<26)>>26) count++; i++; unit+=MAP_UNIT_STRIDE;}while(i<end);}
 if(count!=0)return 0; return 1;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Returns 1 when a cell owned by player 1 is a headquarters (0x0f) or base
 * (0x11) terrain and has a unit standing on it. */
s32 Ov004_IsHqOrBaseOccupied(void) {
extern void **gCurrentMap;
s32 x,y=0,terrain,width; u8 *cell; u8 *scan; u8 unitId;
u8 *map=*gCurrentMap;
if(y<M2C_FIELD(map,u16 *,0x5146)) do {
width=M2C_FIELD(map,u16 *,0x5144);
x=0;
if(x<width){
scan=map+M2C_FIELD(map+(y<<1),u16 *,0x3758);
do {
if(((M2C_FIELD(scan,u8 *,0x1420)&0xE0)>>5)==1){
cell=map+M2C_FIELD(map+(y<<1),u16 *,0x3758)+x;
terrain=M2C_FIELD(cell,u8 *,0x1420)&31;
if(terrain==15||terrain==17){unitId=M2C_FIELD(cell,u8 *,0x508);if(unitId!=0 && (unitId>>6)==0)return 1;}
}
x++;scan++;
}while(x<width);
}
y++;
}while(y<M2C_FIELD(map+0x5120,u16 *,0x26));
return 0;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov004_022141bc(void) {
    s32 temp_r4;

    temp_r4 = GetCoPowerMeterCost(1, 2);
    if ((temp_r4 == GetCoPowerMeterPoints(1)) && (GetCoPowerMeterPoints(1) > 0)) {
        return 1;
    }
    return 0;
}

u8 func_ov004_022141fc(void) {
    s32 HasActiveMapOrderOfType(M2C_UNK);
    u8 var_r0;

    if (HasActiveMapOrderOfType(4) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_0221421c(void) {
    u8 var_r0;

    if (IsEventFlagSet(0) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Mark every unit of the current player as having acted, so the rest of the
 * turn skips it.  The player's unit group starts at gPlayerUnitIdBase, and the
 * ids scanned are base+1 .. base+MAP_UNIT_GROUP_SCAN; empty records (kind 0) are
 * left alone. */
void Ov004_MarkPlayerUnitsActed(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 i;
    u16 groupBase;
    u8 *unit;

    groupBase = gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)];
    for (i = groupBase + 1; i < gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)] + MAP_UNIT_GROUP_SCAN; i++) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        if ((u32) (unit[MAP_UNIT_KIND] << 26) >> 26) {
            M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) |= UNIT_FLAG_ACTED;
        }
    }
}

/* ov004 battle-script condition: from the second turn on, with event flag 0
 * clear, true when a unit is selected and the map cursor sits on the scripted
 * watch tile (4, 12). */
s32 IsSelectedUnitAtScriptTile(void) {
 extern void **gCurrentMap;
 void *p; s16 cursorX,cursorY;
 if((s32)M2C_FIELD(*gCurrentMap,u16 *,MAP_TURN)<2)return 0;
 if(IsEventFlagSet(0))return 0;
 if(!IsUnitSelected(M2C_FIELD(*gCurrentMap,void **,MAP_CURSOR_UNIT)))return 0;
 p=*gCurrentMap; cursorX=M2C_FIELD(p,s16 *,MAP_CURSOR_X); cursorY=M2C_FIELD(p,s16 *,MAP_CURSOR_Y);
 return cursorX==4 && cursorY==12;
}

/* Battle-script condition that succeeds when player 2 has no units. */
s32 Ov004_IsPlayerTwoArmyEmpty_0221435C(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount;
    s32 unitId;
    u8 *unit;
    s32 endId;
    u8 kindAndRank;

    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kindAndRank = unit[MAP_UNIT_KIND];
            if ((u32)(kindAndRank << 26) >> 26) {
                unitCount++;
            }
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    if (unitCount != 0) {
        return 0;
    }
    return 1;
}

/* Battle-script condition: player 2 is defeated.  True when the player's lost
 * flag is set or when none of its unit slots (base+1 .. base+MAP_UNIT_GROUP_SCAN)
 * holds a live unit kind. */
s32 IsPlayerTwoDefeated(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 count, i, end;
    u8 *unit, kind;
    count = 0;
    if (HasPlayerLost(2)) return 1;
    i = gPlayerUnitIdBase[2] + 1;
    end = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (i < end) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + i * MAP_UNIT_STRIDE;
        do {
            kind = *unit;
            if ((u32)(kind << 26) >> 26) count++;
            i++;
            unit += MAP_UNIT_STRIDE;
        } while (i < end);
    }
    if (count != 0) return 0;
    return 1;
}

s32 func_ov004_02214454(void) {
    return 1;
}

void func_ov004_0221445c(s32 arg0) {
    void CreateScriptMarkerSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    CreateScriptMarkerSprite(9, 6, 3, 0x32, arg0);
}

u8 func_ov004_0221447c(void) {
 extern void **gCurrentMap;
 s32 n=M2C_FIELD(*gCurrentMap,u16 *,0x52A2);u8 r;
 if(n<3)return 0;
 if(n<=5)r=1;else r=0;return r;
}

/* Battle-event script command: pick the best area-effect target for player 2
 * (range 3, power 50) and create a target marker sprite there for the script
 * object `owner`.  Nothing is marked when no target scores. */
void ScriptCmd_ShowAreaEffectTarget(s32 owner) {
    s32 SelectAreaEffectTargetOnAllCells(s16 *, s32, s32, s32, s32, s32);
    void CreateScriptMarkerSprite(s32, s32, s32, s32, s32);
    s16 pos[2];

    if (!SelectAreaEffectTargetOnAllCells(pos, 2, 0, 6, 3, 50)) return;
    CreateScriptMarkerSprite(pos[0], pos[1], 3, 50, owner);
}

/* Battle-script condition that succeeds when player 2 has no units. */
s32 Ov004_IsPlayerTwoArmyEmpty_02214510(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount;
    s32 unitId;
    u8 *unit;
    s32 endId;
    u8 kindAndRank;

    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kindAndRank = unit[MAP_UNIT_KIND];
            if ((u32)(kindAndRank << 26) >> 26) {
                unitCount++;
            }
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    if (unitCount != 0) {
        return 0;
    }
    return 1;
}

/* ov004 battle-script condition: player 2 has at most three units.  It counts
 * the non-empty records of player 2's unit group (base+1 .. base+MAP_UNIT_GROUP_SCAN). */
s32 Ov004_IsPlayerTwoUnitCountAtMostThree(void) {
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s32 unitCount, unitId, endId;
    u8 *unit;
    u8 kindAndRank;

    unitCount = 0;
    unitId = gPlayerUnitIdBase[2] + 1;
    endId = gPlayerUnitIdBase[2] + MAP_UNIT_GROUP_SCAN;
    if (unitId < endId) {
        unit = (u8 *)*gCurrentMap + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE;
        do {
            kindAndRank = *unit;
            if ((u32)(kindAndRank << 26) >> 26) unitCount++;
            unitId++;
            unit += MAP_UNIT_STRIDE;
        } while (unitId < endId);
    }
    if (unitCount > 3) return 0;
    return 1;
}

s32 GetTurnReinforcementKind(s8 *a) {
extern void **gCurrentMap;
s32 Modulo(s32,s32);
s32 n=0;
while(a[n]>=0)n++;
return a[Modulo(M2C_FIELD(*gCurrentMap,u16 *,0x52a2)-1,n)];
}

/* Battle-script command: when tile (10,8) is empty, spawn player 2's unit of the
 * kind the turn reinforcement table picks for this turn there. */
void SpawnReinforcementAt10_8(void) {
extern s8 gReinforcementKindsAt10_8[];extern void **gCurrentMap;
s32 kind=GetTurnReinforcementKind(gReinforcementKindsAt10_8);void *p=*gCurrentMap;
s32 i=M2C_FIELD(p,u16 *,0x3768)+10;
if(M2C_FIELD((u8 *)p+i,u8 *,0x508))return;
if(!kind)return;
CreateMapUnitAndRefreshView(10,8,kind,2);
}

/* Battle-script command: when tile (14,8) is empty, spawn player 2's unit of
 * the kind the turn reinforcement table picks for this turn there. */
void SpawnReinforcementAt14_8(void) {
extern s8 gReinforcementKindsAt14_8[];extern void **gCurrentMap;
s32 kind=GetTurnReinforcementKind(gReinforcementKindsAt14_8);void *p=*gCurrentMap;
s32 i=M2C_FIELD(p,u16 *,0x3768)+14;
if(M2C_FIELD((u8 *)p+i,u8 *,0x508))return;
if(!kind)return;
CreateMapUnitAndRefreshView(14,8,kind,2);
}

void func_ov004_022146f8(void) {
    M2C_UNK Create3DSpriteOffsetTrack(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    Create3DSpriteOffsetTrack(4, 2, 0, 0x32, 0);
}

u8 func_ov004_02214718(void) {
    M2C_UNK FindMapOrderAtTile(M2C_UNK, M2C_UNK);
    s32 IsMapOrderActive();
    u8 var_r0;

    FindMapOrderAtTile(6, 6);
    if (IsMapOrderActive() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214740(void) {
    u8 var_r0;

    FindMapOrderAtTile(0xB, 5);
    if (IsMapOrderActive() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214768(void) {
    u8 var_r0;

    FindMapOrderAtTile(0xC, 5);
    if (IsMapOrderActive() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214790(void) {
    u8 var_r0;

    FindMapOrderAtTile(0xD, 5);
    if (IsMapOrderActive() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_022147b8(void) {
    u8 var_r0;

    FindMapOrderAtTile(0x12, 6);
    if (IsMapOrderActive() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_022147e0(void) {
    u8 var_r0;

    if (HasActiveMapOrderOfType(6) != 0) {
        return 0U;
    }
    if (HasActiveMapOrderOfType(7) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Draw the outline of the rectangle (x0,y0)-(x1,y1) as four GX lines at depth
 * z: top and bottom run one pixel past the right edge, right and left one
 * pixel past the bottom edge. */
void DrawGxRectFrame(s32 x0, s32 y0, s32 x1, s32 y1, s32 z, s32 color) {
    M2C_UNK DrawGxLine(s32, s32, s32, s32, s32, s32);
    DrawGxLine(x0, y0, x1 + 1, y0, z, color);
    DrawGxLine(x1, y0, x1, y1 + 1, z, color);
    DrawGxLine(x1 + 1, y1, x0, y1, z, color);
    DrawGxLine(x0, y1 + 1, x0, y0, z, color);
}

