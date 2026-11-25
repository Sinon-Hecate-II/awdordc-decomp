/* 33 functions from 0x02169F94 to 0x0216ABA8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_move.h"
#include "ds3dsprite.h"
typedef struct { s32 values[3]; } FavouriteGroupTextIds; /* the favourite record group's text id per group */
typedef struct { u32 value, threshold; } A564Entry;
extern const FavouriteGroupTextIds gFavouriteGroupTextIds;
extern u32 gRecordValues[];

#pragma opt_strength_reduction off
void PlayUnitMoveSound(void *p) { s32 GetUnitVariantIndex(u8,u8); void PlayUnitStepSound(void *);void PlaySoundAtTile(s32,s32,s32);extern s32 *gCurrentMap;extern M2C_UNK gUnitMoveSoundSpecials;s32 idx,mode,x,y;idx=GetUnitVariantIndex(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd)); x=M2C_FIELD(p,s16 *,0x4c)+8;y=M2C_FIELD(p,s16 *,0x4e)+8;x=(s32)(x+((u32)(x>>3)>>28))>>4;y=(s32)(y+((u32)(y>>3)>>28))>>4;switch(mode=*(s32 *)((u8 *)&gUnitMoveSoundSpecials+idx*20)){case 0:break;case 0x8000:PlayUnitStepSound(p);break;case 0x4000:StopSlotSound(0);break;default:PlaySoundAtTile(mode,x,y);break;} }
#pragma opt_strength_reduction reset
void UpdateMoveSoundPan(void *);
/* When a unit starts a step, a walker plays the terrain's footstep sound (its
 * variant's move-sound record says so); every other unit instead has a looping
 * move sound, which is re-panned to the tile the unit is entering. */
void StepUnitMoveSound(void *move) {
s32 GetUnitVariantIndex(u8,u8);
void PlayUnitStepSound(void *);
extern s32 *gCurrentMap;extern M2C_UNK gUnitMoveSoundSpecials;
s32 variant=GetUnitVariantIndex(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND),M2C_FIELD(*gCurrentMap+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF));
if(*(s32 *)((u8 *)&gUnitMoveSoundSpecials+variant*UNIT_MOVE_SOUND_RECORD_SIZE)==UNIT_MOVE_SOUND_FOOTSTEP){PlayUnitStepSound(move);return;}
((void (*)(void *))UpdateMoveSoundPan)(move);
}

/* Returns the footstep sound id for the terrain at map cell (x, y): most kinds
 * have one sound, plain ground varies with the map tileset, and unknown cells
 * are silent. */
s32 GetTerrainStepSound(s32 unused,s32 x,s32 y){
extern s32 *gCurrentMap;void *map=(void *)*gCurrentMap;
switch(M2C_FIELD((u8*)map+(x+M2C_FIELD((u8*)map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK){
case 4:return STEP_SOUND_WOODS;
case 3:return STEP_SOUND_ROCK;
case 9:return STEP_SOUND_SHOAL;
case 2:return STEP_SOUND_WATER;
case 1:switch(M2C_FIELD(map,u8 *,MAP_TILESET)){case 1:return STEP_SOUND_PLAIN_1;case 2:return STEP_SOUND_SHOAL;case 3:return STEP_SOUND_PLAIN_3;default:return STEP_SOUND_PLAIN;}
case 13:case 14:case 15:case 16:case 17:case 18:case 19:return STEP_SOUND_PLAIN;
case 7:case 8:case 12:return STEP_SOUND_HARD;
default:return 0;
}
}

/* Play one movement step's sound for the moving unit: infantry and mechs use the
 * terrain's footstep sound, a hidden submarine a fixed sound, every other kind
 * its own movement sound; then pan the sound to the unit's tile. */
void PlayUnitStepSound(void *move){
s32 GetUnitVariantIndex(u8,u8);void PlaySoundAtTile(s32,s32,s32);void PlaySoundEffectOnChannel0(s32);
extern s32 *gCurrentMap;extern s32 gUnitMoveSounds;
s32 soundIndex,x,y;u16 sound;
soundIndex=GetUnitVariantIndex(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND),M2C_FIELD(*gCurrentMap+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF));
x=M2C_FIELD(move,s16 *,UNIT_MOVE_X)+8;y=M2C_FIELD(move,s16 *,UNIT_MOVE_Y)+8;x/=16;y/=16;
switch(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND)){
case 1:case 2:
if(!*(s32 *)((u8 *)&gUnitMoveSounds+soundIndex*20))return;
sound=GetTerrainStepSound((s32)move,x,y);if(!sound)return;
PlaySoundAtTile(sound,x,y);return;
case 22:
if(M2C_FIELD(move,void **,UNIT_MOVE_UNIT)&& (M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_UNIT),u16 *,MAP_UNIT_FLAGS)&UNIT_FLAG_FOG)){PlaySoundEffectOnChannel0(0x5d);break;}
default:
sound=0;
if(*(s32 *)((u8 *)&gUnitMoveSounds+soundIndex*20))PlaySoundEffectOnChannel0(*(s32 *)((u8 *)&gUnitMoveSounds+soundIndex*20));break;
}
UpdateMoveSoundPan(move);
}

/* Re-pans the moving unit's looping move sound to the tile it currently occupies
 * (the unit position is kept in 1/16-tile units, so it is rounded to a tile). */
void UpdateMoveSoundPan(void *move) {
s32 MapTileToSoundPan(s32,s32);
s32 IsSlotSoundActive(s32);
s32 x,y;
if(!IsSlotSoundActive(0))return;
x=M2C_FIELD(move,s16 *,UNIT_MOVE_X)+8;y=M2C_FIELD(move,s16 *,UNIT_MOVE_Y)+8;
SetSlotSoundPan(0,MapTileToSoundPan(x/16,y/16));
}

/* Copy one 0x100-byte block of the rank icon tiles from /window/rank.cg into
 * sprite texture memory at destOffset, and the icon palette from
 * /window/rank.cl into sprite palette slot palette. */
void LoadRankIconGraphics(s32 icon, s32 destOffset, s32 palette) {
    s32 LoadDecompressedFile(s32, s32);
    void MI_CpuCopy32(s32, s32, s32);
    void HeapFreeBlock(s32);
    s32 LoadFileToSpriteBuffer(s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern const char gRankIconGfxFile[];
    extern const char gRankIconPaletteFile[];
    s32 gfx;

    gfx = LoadDecompressedFile((s32)gRankIconGfxFile, 0);
    MI_CpuCopy32(gfx + (icon << 8), M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_TEXTURE) + destOffset, 0x100);
    HeapFreeBlock(gfx);
    LoadFileToSpriteBuffer((s32)gRankIconPaletteFile, (palette + DS3D_OBJ_PALETTE_BASE) << DS3D_PALETTE_SHIFT, DS3D_PALETTE_BYTES);
}

void AddSprite32x16(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK AddSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK gSpriteDesc32x16;
    AddSprite(arg0, arg1, arg2, &gSpriteDesc32x16, arg3);
}

s32 GetRecordDefinition(s32 arg0, s32 arg1) {
    extern M2C_UNK gRecordTable;
    return (arg1 * 0x30) + ((arg0 * 0x750) + (s32) &gRecordTable);
}

/* The value the player has accumulated for record (group, index): the record
 * entry's id picks a counter in gRecordValues, offset by the group's block. */
u32 GetRecordValue(s32 group, s32 index) {
RecordDefinition *record = (RecordDefinition *)GetRecordDefinition(group, index);
switch (group) {
case 0: return gRecordValues[record->id + RECORD_VALUE_GROUP0_BASE];
case 1: return gRecordValues[record->id + RECORD_VALUE_GROUP1_BASE];
case 2: return gRecordValues[record->id + RECORD_VALUE_GROUP2_BASE];
default: return 0;
}
}

/* The tier (0..3) a record's accumulated value has reached: 3 at its gold
   threshold, 2 at silver, 1 at bronze, and 0 below bronze. */
u16 GetRecordTier(s32 group,s32 index) {
RecordDefinition *record=(RecordDefinition *)GetRecordDefinition(group,index);u32 value=GetRecordValue(group,index);u16 tier;
if(value>=record->gold)return 3;if(value>=record->silver)return 2;
if(value>=record->bronze) tier=1;else tier=0;return tier;
}

/* Sum the tier every listed record has reached across the three record groups. */
u16 GetEarnedRecordTierTotal(void) {
    s32 group;
    s32 index;
    s32 record;
    u16 total = 0;

    group = 0;
    do {
        record = GetRecordDefinition(group, 0);
        index = 0;
        if (M2C_FIELD(record, s32 *, 0)) {
            do {
                total += GetRecordTier(group, index);
                record += RECORD_DEFINITION_SIZE;
                index++;
            } while (M2C_FIELD(record, s32 *, 0));
        }
        group++;
    } while (group < RECORD_GROUP_COUNT);
    return total;
}

/* Sums the player's record tiers over the three record groups: *earned receives
 * the tiers reached and *possible the three tiers every listed record can reach. */
void GetRecordTierTotals(u16 *earned, u16 *possible) {
s32 group,index,record,tier;group=0;*earned=0;*possible=0;
do {record=GetRecordDefinition(group,0);index=0;if(M2C_FIELD(record,s32 *,0)){do {tier=GetRecordTier(group,index);index++;*earned+=tier;*possible+=3;record+=0x30;}while(M2C_FIELD(record,s32 *,0));}group++;}while(group<3);
}

s8 GetRecordRank(u32 a) { extern M2C_UNK data_ov000_021b67cc; s32 i=0; do {if(a>=((A564Entry *)&data_ov000_021b67cc)[i].threshold)return (s8)i;i++;}while(i<20);return 19; }

s32 GetRecordRankTextId(s32 i) {
extern M2C_UNK data_ov000_021b67cc;
return *(s32 *)((u8 *)&data_ov000_021b67cc+i*8);
}

/* Find the player's favourite record of group 1: each record's value times its
 * weight (at +0x18), the highest wins.  With byGroup clear it instead returns
 * the group (record +0x06, 0..2) whose records add up to the highest total.
 * -1 when no record of the group has a value yet. */
s32 GetFavouriteRecord(s32 byGroup) {
    s32 GetRecordDefinition(s32, s32);
    u32 GetRecordValue(s32, s32);

    s32 index;
    u64 group2Total;
    u64 group0Total;
    u64 group1Total;
    long long bestIndex;
    u64 bestValue;
    u32 empty;
    s32 *record;
    u32 value;
    u8 weight;
    s16 group;

    group0Total = 0;
    empty = 1;
    group1Total = 0;
    group2Total = 0;
    bestIndex = 0;
    bestValue = 0;
    index = 0;

    record = (s32 *)GetRecordDefinition(1, index);
    while (*record != 0) {
        value = GetRecordValue(1, index);
        if (value != 0) {
            empty = 0;
        }
        weight = *(u8 *)((u8 *)GetRecordDefinition(1, index) + 0x18);
        value = value * weight;
        group = *(s16 *)((u8 *)GetRecordDefinition(1, index) + 6);
        switch (group) {
            case 0:
                group0Total = group0Total + value;
                break;
            case 1:
                group1Total = group1Total + value;
                break;
            case 2:
                group2Total = group2Total + value;
                break;
        }
        if ((unsigned long long)value > bestValue) {
            bestIndex = index;
            bestValue = value;
        }
        index = index + 1;
        record = (s32 *)((u8 *)record + 0x30);
    }

    if (byGroup == 0) {
        if (empty != 0) {
            return -1;
        }
        if (group0Total >= group1Total && group0Total >= group2Total) {
            return 0;
        }
        if (group1Total >= group0Total && group1Total >= group2Total) {
            return 1;
        }
        return 2;
    }
    return empty ? -1 : (s8)bestIndex;
}

void GetFavouriteRecordGroup(void) {
    M2C_UNK GetFavouriteRecord(M2C_UNK);
    GetFavouriteRecord(0);
}

/* The text id naming the player's favourite record group: -1 (no favourite) has its
 * own string, groups 0..2 the string their slot of the table holds. */
s32 GetFavouriteGroupTextId(s32 group) {
    FavouriteGroupTextIds table;
    if (group == -1) return 0xc0000021;
    table = gFavouriteGroupTextIds;
    return table.values[group];
}

void GetFavouriteRecordIndex(void) {
    GetFavouriteRecord(1);
}

s32 GetFavouriteRecordTextId(s32 a) {
if(a==-1)return 0xc0000025;
return M2C_FIELD(GetRecordDefinition(1,a),s32 *,0x14);
}

/* Run the map's first event-script list (script slot +0x00) with no arguments;
 * returns nonzero when a condition of the event matched.  Nothing yet says which
 * map event that slot is. */
s32 func_ov000_0216a7fc(void) {
    s32 EvalScriptConditions(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 *GetMapEventScript();
    s32 *eventScript;
    s32 script;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = *eventScript;
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's second event-script list (script slot +0x04) with no arguments;
 * returns nonzero when a condition of the event matched.  Nothing yet says which
 * map event that slot is. */
s32 func_ov000_0216a834(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, 4);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's turn-start event (script slot MAP_EVENT_TURN_START) when a
 * player's turn begins; returns nonzero when a condition of the event matched. */
s32 RunTurnStartEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_TURN_START);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's turn-intro event (script slot MAP_EVENT_TURN_INTRO, +0x0C) once
 * the player's turn-intro banner has played (func_020d42d0, MAP_STATE_TURN_INTRO3);
 * returns nonzero when a condition of the event matched. */
s32 RunTurnIntroEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_TURN_INTRO);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's unit-selected event for the unit a player just picked: its condition
 * list is evaluated with the unit (its action commands run when a condition holds).
 * Units outside the first group of unit records have no event. */
u8 RunUnitSelectedEvent(s32 unit) {
extern s32 *gCurrentMap;
s32 script= (s32)GetMapEventScript();s32 index;
if(unit==0)index=0;else index=(unit-(*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;
if((index&0xc0)>>6)return 0;
if(script && M2C_FIELD(script,s32 *,MAP_EVENT_UNIT_SELECTED))return EvalScriptConditions(M2C_FIELD(script,s32 *,MAP_EVENT_UNIT_SELECTED),unit,0,0,1);return 0;
}

/* Run the map's battle-start event (script slot MAP_EVENT_BATTLE) with the
 * previewed battle's attacker and defender; returns nonzero when a condition of
 * the event matched. */
s32 RunBattleEvent(s32 attacker, s32 defender) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_BATTLE);
        if (script != 0) {
            return EvalScriptConditions(script, attacker, defender, 0, 1);
        }
    }
    return 0;
}

/* Run the map's cursor-unit event (script slot 0x18) with the unit under the
 * battle cursor; returns nonzero when a condition of the event matched. */
s32 RunCursorUnitEvent(s32 unit) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_CURSOR_UNIT);
        if (script != 0) {
            return EvalScriptConditions(script, unit, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's cursor-unit event (script slot MAP_EVENT_CURSOR_UNIT) with the
 * unit and an extra script value; returns nonzero when a condition matched. */
s32 RunCursorUnitEventWithValue(s32 unit, s32 value) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_CURSOR_UNIT);
        if (script != 0) {
            return EvalScriptConditions(script, unit, 0, value, 1);
        }
    }
    return 0;
}

/* Run the map's unit-lifecycle event (script slot MAP_EVENT_UNIT) for a unit: the
 * event code selects the case (unit built, unit destroyed, a carried unit kind)
 * and the unit is the one it applies to. Returns nonzero when a condition matched. */
s32 RunUnitEvent(s32 eventCode, s32 unit) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_UNIT);
        if (script != 0) {
            return EvalScriptConditions(script, unit, 0, eventCode, 1);
        }
    }
    return 0;
}

/* Run the map's battle-end event (script slot MAP_EVENT_BATTLE_END, +0x20) once a
 * battle is over (EnterBattleEnd, main_020C8CBC); returns nonzero when a condition
 * of the event matched. */
s32 RunBattleEndEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_BATTLE_END);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's ending event (script slot MAP_EVENT_ENDING, +0x24), the one the
 * final campaign map's ending sprite runs while the ending scene plays (state 7,
 * func_ov004_02211260); returns nonzero when a condition of the event matched. */
s32 RunEndingEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_ENDING);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's menu event (script slot MAP_EVENT_MAP_MENU, +0x28): the map-menu
 * action func_020c5da4 runs it after closing the menu, and IsMapEventConditionMet
 * tests the same list to decide whether that action is available; returns nonzero
 * when a condition of the event matched. */
s32 RunMapMenuEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_MAP_MENU);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's unit-gone event (script slot MAP_EVENT_UNIT_GONE, +0x2C) once a
 * unit has left the map: UnitRemoveEffect_Trigger calls it after the explosion,
 * whether the unit was destroyed or only removed; returns nonzero when a
 * condition of the event matched. */
s32 RunUnitGoneEvent(void) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_UNIT_GONE);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, 1);
        }
    }
    return 0;
}

/* Run the map's cursor-idle event (script slot MAP_EVENT_CURSOR_IDLE) while the
 * battle cursor rests: evaluate the event's condition list, applying its effects
 * when `applyEffects` is set; returns nonzero when a condition matched. */
s32 RunCursorIdleEvent(s32 applyEffects) {
    s32 script;
    void *eventScript;

    eventScript = GetMapEventScript();
    if (eventScript != NULL) {
        script = M2C_FIELD(eventScript, s32 *, MAP_EVENT_CURSOR_IDLE);
        if (script != 0) {
            return EvalScriptConditions(script, 0, 0, 0, applyEffects);
        }
    }
    return 0;
}

