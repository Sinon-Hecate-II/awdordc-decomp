/* 33 functions from 0x02169F94 to 0x0216ABA8 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_unit_move.h"
typedef struct { s32 values[3]; } A77cTable;
typedef struct { u32 value, threshold; } A564Entry;
extern const A77cTable data_ov000_021aabb0;

#pragma opt_strength_reduction off
void PlayUnitMoveSound(void *p) { s32 func_020a7298(u8,u8); void PlayUnitStepSound(void *);void PlaySoundAtTile(s32,s32,s32);extern s32 *gCurrentMap;extern M2C_UNK gUnitMoveSoundSpecials;s32 idx,mode,x,y;idx=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd)); x=M2C_FIELD(p,s16 *,0x4c)+8;y=M2C_FIELD(p,s16 *,0x4e)+8;x=(s32)(x+((u32)(x>>3)>>28))>>4;y=(s32)(y+((u32)(y>>3)>>28))>>4;switch(mode=*(s32 *)((u8 *)&gUnitMoveSoundSpecials+idx*20)){case 0:break;case 0x8000:PlayUnitStepSound(p);break;case 0x4000:func_02090034(0);break;default:PlaySoundAtTile(mode,x,y);break;} }
#pragma opt_strength_reduction reset
void UpdateMoveSoundPan(void *);
void StepUnitMoveSound(void *p) {
s32 func_020a7298(u8,u8);
void PlayUnitStepSound(void *);
extern s32 *gCurrentMap;extern M2C_UNK gUnitMoveSoundSpecials;
s32 idx=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8c,u8 *,0x67cd));
if(*(s32 *)((u8 *)&gUnitMoveSoundSpecials+idx*20)==0x8000){PlayUnitStepSound(p);return;}
((void (*)(void *))UpdateMoveSoundPan)(p);
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
s32 func_020a7298(u8,u8);void PlaySoundAtTile(s32,s32,s32);void PlaySoundEffectOnChannel0(s32);
extern s32 *gCurrentMap;extern s32 gUnitMoveSounds;
s32 soundIndex,x,y;u16 sound;
soundIndex=func_020a7298(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND),M2C_FIELD(*gCurrentMap+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF));
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

void UpdateMoveSoundPan(void *p) {
s32 func_0208fa78(s32,s32);
s32 IsSlotSoundActive(s32);
s32 x,y;
if(!IsSlotSoundActive(0))return;
x=M2C_FIELD(p,s16 *,0x4c)+8;y=M2C_FIELD(p,s16 *,0x4e)+8;
PlaySlotSoundEffect(0,func_0208fa78(x/16,y/16));
}

void func_ov000_0216a30c(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK MI_CpuCopy32(s32, s32, M2C_UNK);
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK HeapFreeBlock(s32);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021b7e5c;
    extern M2C_UNK data_ov000_021b7e6c;
    s32 temp_r0;

    temp_r0 = func_02081070(&data_ov000_021b7e5c, 0);
    MI_CpuCopy32(temp_r0 + (arg0 << 8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg1, 0x100);
    HeapFreeBlock(temp_r0);
    LoadFileToSpriteBuffer(&data_ov000_021b7e6c, (arg2 + 0x10) << 5, 0x20);
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

u32 GetRecordValue(s32 a,s32 b) {
extern u32 gRecordValues[];
s32 p=GetRecordDefinition(a,b);
switch(a){case 0:return gRecordValues[M2C_FIELD(p,u16 *,4)];case 1:return gRecordValues[M2C_FIELD(p,u16 *,4)+0x28];case 2:return gRecordValues[M2C_FIELD(p,u16 *,4)+0x43];default:return 0;}
}

u16 GetRecordTier(s32 a,s32 b) {
s32 p=GetRecordDefinition(a,b);u32 n=GetRecordValue(a,b);u16 r;
if(n>=M2C_FIELD(p,u32 *,16))return 3;if(n>=M2C_FIELD(p,u32 *,12))return 2;
if(n>=M2C_FIELD(p,u32 *,8)) r=1;else r=0;return r;
}

u16 func_ov000_0216a470(void) {
s32 i,j; s32 p;u16 result=0;
i=0;do {p=GetRecordDefinition(i,0);j=0;if(M2C_FIELD(p,s32 *,0)) {do {result+=GetRecordTier(i,j);p+=0x30;j++;}while(M2C_FIELD(p,s32 *,0));}i++;}while(i<3);return result;
}

void func_ov000_0216a4e0(u16 *a,u16 *b) {
s32 i,j,p,r;i=0;*a=0;*b=0;
do {p=GetRecordDefinition(i,0);j=0;if(M2C_FIELD(p,s32 *,0)){do {r=GetRecordTier(i,j);j++;*a+=r;*b+=3;p+=0x30;}while(M2C_FIELD(p,s32 *,0));}i++;}while(i<3);
}

s8 func_ov000_0216a564(u32 a) { extern M2C_UNK data_ov000_021b67cc; s32 i=0; do {if(a>=((A564Entry *)&data_ov000_021b67cc)[i].threshold)return (s8)i;i++;}while(i<20);return 19; }

s32 func_ov000_0216a59c(s32 i) {
extern M2C_UNK data_ov000_021b67cc;
return *(s32 *)((u8 *)&data_ov000_021b67cc+i*8);
}

s32 func_ov000_0216a5ac(s32 arg0) {
    s32 GetRecordDefinition(s32, s32);
    u32 GetRecordValue(s32, s32);

    s32 *p;
    s32 i;
    u32 flag;
    unsigned long long total2;
    unsigned long long total0;
    unsigned long long total1;
    unsigned long long best;
    u32 n;
    u8 byte;
    s16 mode;
    s8 bestIndex;

    p = (s32 *)0;
    i = 0;
    flag = 1;
    total0 = 0;
    total1 = 0;
    total2 = 0;
    best = 0;
    bestIndex = 0;

    p = (s32 *)GetRecordDefinition(1, 0);
    while (*p != 0) {
        n = GetRecordValue(1, i);
        if (n != 0) {
            flag = 0;
        }
        byte = *(u8 *)((u8 *)GetRecordDefinition(1, i) + 0x18);
        n = n * byte;
        mode = *(s16 *)((u8 *)GetRecordDefinition(1, i) + 6);
        switch (mode) {
            case 0:
                total0 = total0 + n;
                break;
            case 1:
                total1 = total1 + n;
                break;
            case 2:
                total2 = total2 + n;
                break;
        }
        if ((unsigned long long)n > best) {
            best = n;
            bestIndex = i;
        }
        i = i + 1;
        p = (s32 *)((u8 *)p + 0x30);
    }

    if (arg0 != 0) {
        if (flag != 0) {
            return -1;
        }
        return bestIndex;
    }
    if (flag != 0) {
        return -1;
    }
    if (total0 < total1) {
        if (total1 < total2) {
            return 2;
        }
        return 1;
    } else {
        if (total0 < total2) {
            return 2;
        }
        return 0;
    }
}

void func_ov000_0216a76c(void) {
    M2C_UNK func_ov000_0216a5ac(M2C_UNK);
    func_ov000_0216a5ac(0);
}

s32 func_ov000_0216a77c(s32 a) {
A77cTable table;
if(a==-1)return 0xc0000021;
table=data_ov000_021aabb0;return table.values[a];
}

void func_ov000_0216a7c4(void) {
    func_ov000_0216a5ac(1);
}

s32 func_ov000_0216a7d4(s32 a) {
if(a==-1)return 0xc0000025;
return M2C_FIELD(GetRecordDefinition(1,a),s32 *,0x14);
}

s32 func_ov000_0216a7fc(void) {
    s32 EvalScriptConditions(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 *GetMapEventScript();
    s32 *temp_r0_2;
    s32 temp_r0;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = *temp_r0_2;
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a834(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 4);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a86c(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 8);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a8a4(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0xC);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
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

s32 func_ov000_0216a97c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x14);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, arg0, arg1, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216a9bc(M2C_UNK arg0) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x18);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, arg0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa04(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x18);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, arg0, 0, arg1, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa44(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x1C);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, arg1, 0, arg0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aa84(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x20);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aabc(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x24);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216aaf4(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x28);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216ab2c(void) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x2C);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, 1);
        }
    }
    return 0;
}

s32 func_ov000_0216ab64(s32 arg0) {
    s32 temp_r0;
    void *temp_r0_2;

    temp_r0_2 = GetMapEventScript();
    if (temp_r0_2 != NULL) {
        temp_r0 = M2C_FIELD(temp_r0_2, s32 *, 0x30);
        if (temp_r0 != 0) {
            return EvalScriptConditions(temp_r0, 0, 0, 0, arg0);
        }
    }
    return 0;
}

