/* 28 functions from 0x020AF760 to 0x020B0658 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "ov002_effects.h"
#include "sound.h"
typedef struct { s32 x,y,z; } VecAff;
typedef struct { u8 pad[4]; s32 unk4; } Unk020af860_Sub;
typedef struct { u8 pad[0x34]; Unk020af860_Sub *unk34; } Unk020af860_Unit;
typedef struct { Unk020af860_Unit *unk0; u8 pad[0x14]; } Unk020af860_Rec;
extern u8 gMapCellSpriteScriptsLarge[],gMapCellSpriteScriptsSmall[];
extern s32 gFrameCounter;

/* Load the sound group each of the two players' effect sets plays its effects from. */
void LoadEffectSoundGroups(void) {
    M2C_UNK Sound_LoadGroup(s32);
    extern M2C_UNK gPlayerSettings;
    s32 side = 0;
    u8 *settings = (u8 *)&gPlayerSettings;
    do {
        EffectSounds *sounds = M2C_FIELD(M2C_FIELD(settings, EffectSet **, 4), EffectSounds **, 0x34);
        s32 group = sounds->group;
        if (group != 0) {
            Sound_LoadGroup(group);
        }
        side++;
        settings += 0x18;
    } while (side < 2);
}

void StopSoundPlayer(void) {
    M2C_UNK RewindMusicPlayerHeapByFrames(M2C_UNK);
    RewindMusicPlayerHeapByFrames(0);
}

void func_020af7ac(void) {
    extern u8 gSlotVolumeSoundDelay[], gSlotVariantSoundDelay[];
    s32 i = 0;
    u8 zero = i;
    volatile u8 *p = gSlotVolumeSoundDelay, *q = gSlotVariantSoundDelay;
    do {
        *p++ = zero;
        *q++ = (i++, zero);
    } while (i < 2);
}
/* Count each effect slot's volume and variant sound hold-off timers down by one
 * frame; a timer stops at zero. */
void TickSlotSoundDelays(void) {
    extern u8 gSlotVariantSoundDelay[];
    extern u8 gSlotVolumeSoundDelay[];
    s32 slot;
    u8 *volumeDelay;
    u8 *variantDelay;
    u8 volumeRemaining;
    u8 variantRemaining;

    volumeDelay = gSlotVolumeSoundDelay;
    variantDelay = gSlotVariantSoundDelay;
    slot = 0;
    do {
        volumeRemaining = *volumeDelay;
        slot += 1;
        if (volumeRemaining != 0) {
            *volumeDelay = volumeRemaining - 1;
        }
        variantRemaining = *variantDelay;
        volumeDelay += 1;
        if (variantRemaining != 0) {
            *variantDelay = variantRemaining - 1;
        }
        variantDelay += 1;
    } while (slot < 2);
}

/* Plays `soundId` for battle effect `slot`: slot 0's sounds are panned hard left,
 * slot 1's hard right.  Nothing is played when the slot has no sound. */
void PlaySlotSound(s32 slot, s32 soundId) {
    s32 PlaySoundEffect(s32);
    s32 SetSoundEffectPan(s32);

    if (soundId == 0) {
        return;
    }
    PlaySoundEffect(soundId);
    if (slot == 0) {
        SetSoundEffectPan(SOUND_PAN_LEFT);
        return;
    }
    SetSoundEffectPan(SOUND_PAN_RIGHT);
}

/* Replaces effect `slot`'s sound with the effect's intensity sound, panned left
 * for the first slot and right for the second, then refreshes the slot's variant
 * sound for the effect's current `frame`. */
void ReplaceSlotSound(s32 slot, s32 frame) {
    M2C_UNK PlaySlotPendingSound(s32, s32, s32);
    M2C_UNK SetSlotSoundPan(s32, s32);
    void UpdateSlotEffectSound(s32, s32);
    extern M2C_UNK gEffectTable;
    s32 soundId = ((EffectSounds *)M2C_FIELD(*(void **)((u8 *)&gEffectTable + slot * 0x18), void **, 0x34))->intensity;
    if (soundId == 0) return;
    PlaySlotPendingSound(slot, -1, soundId);
    if (slot == 0) SetSlotSoundPan(slot, -0x80);
    else SetSlotSoundPan(slot, 0x7F);
    UpdateSlotEffectSound(slot, frame);
}

/* Pick the variant of effect `effect` that shows at frame `frame`: set the
 * effect's frame window (ticked through func_020900a4) and play the sound of
 * the level it falls on. */
void UpdateSlotEffectSound(s32 effect, s32 frame) {
    M2C_UNK SetSlotSoundPending(s32, s32, M2C_UNK);
    M2C_UNK PlaySlotScriptedSound(s32, u8, M2C_UNK);
    extern u8 gSoundLevelVolumes[];
    extern u8 gEffectVariants[];
    extern M2C_UNK gEffectTable;
    extern u8 gEffectHasVariants[];
    s32 level;
    s32 levelScan;
    s32 variant;
    s32 variantAddr;
    u8 startFrame;
    void *temp_r1;

    temp_r1 = *(void **)((u8 *)&gEffectTable + (effect * 0x18));
    if (M2C_FIELD(M2C_FIELD(temp_r1, void **, 0x34), s32 *, 4) == 0) {
        return;
    }
    if (M2C_FIELD(temp_r1, u8 *, 0x3D) == 3) {
        level = 7;
    } else if (gEffectHasVariants[effect * 0x2C] != 0 && frame != 0) {
        level = 7;
    } else if (frame <= 0) {
        level = 0;
    } else if (frame <= 1) {
        level = 1;
    } else if (frame <= 3) {
        level = 3;
    } else {
        level = 7;
    }
    SetSlotSoundPending(effect, ~level, 2);
    variant = 5;
    if (gEffectHasVariants[effect * 0x2C] != 0) {
        variant = 0;
    } else {
        variantAddr = (effect * 0x68) + (s32)gEffectVariants;
        levelScan = 0;
        do {
            startFrame = M2C_FIELD(variantAddr, u8 *, 0x12);
            variantAddr += 1;
            if ((s32)startFrame < frame) {
                variant = levelScan;
            }
            levelScan += 1;
        } while (levelScan < variant);
    }
    PlaySlotScriptedSound(effect, gSoundLevelVolumes[variant], 0);
}

void StopEffectSlotSound(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK StopSlotSound(s32,s32); extern M2C_UNK gEffectTable;
if(arg2==0 && M2C_FIELD(*(void **)((u8*)&gEffectTable+arg0*0x18),u8 *,0x3d)==3)return;
StopSlotSound(arg0,arg1);
}

/* Plays effect `slot`'s volume sound for the effect's default variant, throttled
 * to at most once every four frames while that variant is showing. */
void PlaySlotVolumeSound(s32 slot){extern M2C_UNK gEffectTable;extern u8 gEffectDefaultVariant;extern u8 gSlotVolumeSoundDelay[];u32 variant=*((u8 *)&gEffectDefaultVariant+slot*24);void *effect=*(void **)((u8 *)&gEffectTable+slot*24);if(M2C_FIELD((u8 *)effect+variant,u8 *,0x3e)==1){if((gSlotVolumeSoundDelay)[slot])return;(gSlotVolumeSoundDelay)[slot]=4;}PlaySlotSound(slot,M2C_FIELD((u8 *)M2C_FIELD(effect,void **,0x34)+variant*4,s32 *,8));}

void func_020afa64(s32 a) {
    extern M2C_UNK gEffectTable;
    s32 b = (a == 0) ? 1 : 0;
    PlaySlotSound(a, M2C_FIELD(M2C_FIELD(*(void **)((u8 *)&gEffectTable + b * 24), void **, 0x34), s32 *, 0x10));
}

/* Play effect slot `slot`'s alternate variant sound while the effect in the other
 * slot is showing its variant, at most once every four frames; otherwise play the
 * slot's normal variant sound. */
void PlaySlotVariantSound(s32 slot){
extern M2C_UNK gEffectTable;extern u8 gEffectDefaultVariant;extern u8 gSlotVariantSoundDelay[];s32 variant;
if(M2C_FIELD((u8 *)*(void **)((u8 *)&gEffectTable+(slot==0?1:0)*24)+*((u8 *)&gEffectDefaultVariant+(slot==0?1:0)*24),u8 *,0x3e)==1){if((gSlotVariantSoundDelay)[slot])return;(gSlotVariantSoundDelay)[slot]=4;variant=1;}else variant=0;
PlaySlotSound(slot,M2C_FIELD((u8 *)M2C_FIELD(*(void **)((u8 *)&gEffectTable+slot*24),void **,0x34)+variant*4,s32 *,0x14));
}

/* Plays the sound for effect slot `slot`'s current phase: phases 2 and 3 each
 * have their own effect sound, every other phase gets the default one. */
void PlaySlotPhaseSound(s32 slot){extern M2C_UNK gEffectTable;EffectSet *effect=M2C_FIELD(&gEffectTable,EffectSet **,slot*24);switch(effect->phase){case 2:PlaySlotSound(slot,0x2000b);return;case 3:PlaySlotSound(slot,0x2000c);return;default:PlaySlotSound(slot,0x2000a);return;}}

void func_020afb94(s32 arg0) {
extern M2C_UNK gEffectTable;
void PlaySlotPhaseSound(s32);
s32 v=M2C_FIELD(M2C_FIELD(*(void **)((u8*)&gEffectTable+arg0*24),void **,0x34),s32 *,0x1c);
if(v){PlaySlotSound(arg0,v);return;}PlaySlotPhaseSound(arg0);
}

void func_020afbcc(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020afbe8(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}

void func_020afc04(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020afc20(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void func_020afc3c(void) {

}

void func_020afc40(void) {

}

#pragma opt_common_subs off
/* Draw the ring of parts of a wide map-cell sprite: the four side parts (top,
 * bottom, left, right) at the ring's cardinal points, then the four diagonal
 * runs between them, one part per radius step.  x and y are the cell's
 * 1/16-cell position and radius is in 1/16-cell steps. */
void DrawMapCellSpriteParts(s32 x, s32 y, s32 radius, void *scripts, s32 gfxAddr, s32 tileDataSize, s32 gfxSize) {
    void DrawSpriteScript(void *, s32, s32, VecAff *, s32, s32, s32, s32, s32);
    extern s32 gFrameCounter;
    VecAff pos;
    s32 worldX = x * MAP_SPRITE_CELL_SIZE;
    s32 limit4, limit3, limit2, limit1;
    s32 worldY;
    s32 step;

    pos.z = MAP_SPRITE_ATTR;
    pos.y = (y - radius * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
    pos.x = worldX;
    DrawSpriteScript(scripts, MAP_CELL_PART_TOP, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
    pos.y = (y + radius * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
    pos.x = worldX;
    DrawSpriteScript(scripts, MAP_CELL_PART_BOTTOM, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
    pos.x = (x - radius * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
    worldY = y * MAP_SPRITE_CELL_SIZE;
    pos.y = worldY;
    DrawSpriteScript(scripts, MAP_CELL_PART_LEFT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
    pos.y = worldY;
    pos.x = (x + radius * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
    DrawSpriteScript(scripts, MAP_CELL_PART_RIGHT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
    {
        step = 1;
        limit1 = radius - 1;
        for (; step <= limit1; ++step) {
            pos.x = (x - step * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            pos.y = (y - (radius - step) * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            DrawSpriteScript(scripts, MAP_CELL_PART_UP_LEFT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
        }
    }
    {
        limit2 = radius - 1;
        for (step = 1; step <= limit2; ++step) {
            pos.x = (x + step * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            pos.y = (y - (radius - step) * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            DrawSpriteScript(scripts, MAP_CELL_PART_UP_RIGHT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
        }
    }
    {
        limit3 = radius - 1;
        for (step = 1; step <= limit3; ++step) {
            pos.x = (x - step * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            pos.y = (y + (radius - step) * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            DrawSpriteScript(scripts, MAP_CELL_PART_DOWN_LEFT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
        }
    }
    {
        limit4 = radius - 1;
        for (step = 1; step <= limit4; ++step) {
            pos.x = (x + step * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            pos.y = (y + (radius - step) * MAP_SPRITE_PART_STEP) * MAP_SPRITE_CELL_SIZE;
            DrawSpriteScript(scripts, MAP_CELL_PART_DOWN_RIGHT, gFrameCounter, &pos, gfxAddr, tileDataSize, gfxSize, 0, 0);
        }
    }
}
#pragma opt_common_subs on
/* Draw the 3D sprite of the map cell at the 1/16-cell position (x, y): pick the
   sprite script table and graphics block for the current view zoom, look up the
   cell's sprite id, then draw it either as one sprite or, for a wide sprite id,
   as a ring of parts around the cell. */
void DrawMapCellSprite(s32 x,s32 y){
s32 func_0207b9f4(s32,s32);
s32 GetViewZoom(s32);
void SetSpritePaletteIndex(s32);
void DrawMapCellSpriteParts(s32,s32,s32,void *,s32,s32,s32);
void DrawSpriteScript(void *,s32,s32,VecAff *,s32,s32,s32,s32,s32);
extern s32 *gCurrentMap;
VecAff pos;
s32 gfxSize;void *scripts;s32 gfxAddr; s32 spriteId; s32 zoom;
spriteId=func_0207b9f4(x+8,y+8);
zoom=GetViewZoom(*gCurrentMap+MAP_VIEW_ZOOM)<=0?MAP_SPRITE_ZOOM_SMALL:MAP_SPRITE_ZOOM_LARGE;
if(zoom==MAP_SPRITE_ZOOM_SMALL){gfxAddr=MAP_SPRITE_GFX_ADDR_SMALL;scripts=gMapCellSpriteScriptsSmall;gfxSize=MAP_SPRITE_GFX_SIZE_SMALL;}
else {gfxAddr=MAP_SPRITE_GFX_ADDR_LARGE;scripts=gMapCellSpriteScriptsLarge;gfxSize=MAP_SPRITE_GFX_SIZE_LARGE;}
SetSpritePaletteIndex(MAP_SPRITE_PALETTE);
if(spriteId>MAP_SPRITE_PART_MIN-1){DrawMapCellSpriteParts(x+8,y+8,spriteId-(MAP_SPRITE_PART_MIN-1),scripts,gfxAddr,MAP_SPRITE_TILE_DATA_SIZE,gfxSize);return;}
pos.x=(x+8)*MAP_SPRITE_CELL_SIZE;pos.y=(y+8)*MAP_SPRITE_CELL_SIZE;pos.z=MAP_SPRITE_ATTR;
DrawSpriteScript(scripts,spriteId,gFrameCounter,&pos,gfxAddr,MAP_SPRITE_TILE_DATA_SIZE,gfxSize,0,0);
}

void func_020b00c0(void) {
    M2C_UNK func_0207ce54(s32);
    extern s32 *gCurrentMap;
    func_0207ce54(*gCurrentMap + 0x6EF8);
}

void func_020b00e4(void) {

}

void func_020b00e8(void) {

}

/* Sets the current 3D sprite engine's four layer rotation modes to the alternate
   permutation (display layers 0-3 sample texture layers 3/0/1/2). */
void Set3DSpriteLayerModesAlt(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE0)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE0)&~DS3D_LAYER_MODE_MASK)|3;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE1)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE1)&~DS3D_LAYER_MODE_MASK)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE2)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE2)&~DS3D_LAYER_MODE_MASK)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE3)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE3)&~DS3D_LAYER_MODE_MASK)|2;
}

/* Set the 2-bit rotation mode of the current 3D sprite engine's four layers:
 * 1, 0, 2 and 3 for layers 0 to 3, the map-view arrangement. */
void Set3DSpriteLayerModes(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE0)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE0)&~DS3D_LAYER_MODE_MASK)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE1)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE1)&~DS3D_LAYER_MODE_MASK)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE2)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE2)&~DS3D_LAYER_MODE_MASK)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE3)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,DS3D_BANK_LAYER_TILE3)&~DS3D_LAYER_MODE_MASK)|3;
}

/* Configure the current 3D sprite engine for a map view: set the four layer
   modes, pick the bank's split rows from the map's tileset setting, then force
   the OAM attribute bits and restart the engine. */
void Configure3DSpriteMapView(void) {
    void Set3DSpriteLayerModes(void);
    void Reset3DSpriteEngineState(void);
    extern s32 *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    u16 *volatile oamC0;
    u16 *volatile oam1;
    u16 *volatile oam2;
    u16 *volatile oam4;
    u16 *volatile oam8;
    u16 *volatile oam10;
    u16 *volatile oam20;
    u16 *volatile oam100;
    u16 *volatile oam200;
    u16 *volatile oam400;
    u16 *volatile oam800;
    u16 *volatile oam1000;
    u16 *volatile oam2000;
    u8 splitAbove;
    u8 splitBelow;
    u8 zero = 0;

    Set3DSpriteLayerModes();
    if (M2C_FIELD(*gCurrentMap, u8 *, MAP_TILESET) == 1) {
        splitAbove = 0xa;
        splitBelow = 0x8;
    } else {
        splitAbove = 0xc;
        splitBelow = 0x8;
    }
    oamC0 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oamC0 = (*oamC0 & ~0xc0) | 0x40;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsAbove = splitAbove;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsBelow = splitBelow;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->filler_53 = zero;
    oam1 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1 = (*oam1 & ~1) | 1;
    oam2 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2 = *oam2 & ~2;
    oam4 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam4 = *oam4 & ~4;
    oam8 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam8 = *oam8 & ~8;
    oam10 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam10 = *oam10 & ~0x10;
    oam20 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam20 = *oam20 & ~0x20;
    oam100 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam100 = *oam100 & ~0x100;
    oam200 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam200 = *oam200 & ~0x200;
    oam400 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam400 = *oam400 | 0x400;
    oam800 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam800 = *oam800 | 0x800;
    oam1000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1000 = *oam1000 | 0x1000;
    oam2000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2000 = *oam2000 | 0x2000;
    Reset3DSpriteEngineState();
}

/* Configure the 3D sprite engine for a map view: set the per-layer 2-bit
 * rotation modes (layers 0-3 to 1/0/2/3 via Set3DSpriteLayerModes), pick the two
 * layer-scope bytes by the map's 0x5157 mode flag, then update the engine's
 * flag word at +0x12 (layer 3 enabled, all layer-select/enable bits cleared,
 * the high mode bits 0x400-0x2000 set) before resetting the engine state. */
void func_020b0408(void) {
    void Set3DSpriteLayerModes(void);
    void Reset3DSpriteEngineState(void);
    extern s32 *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;
    u8 v51;
    u8 v52;
    u8 v0 = 0;

    Set3DSpriteLayerModes();
    if (*(u8 *)((s32)*gCurrentMap + 0x5157) == 1) {
        v51 = 0xa;
        v52 = 0x8;
    } else {
        v51 = 0x6;
        v52 = 0x10;
    }
    sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp30 = (*sp30 & ~0xc0) | 0x40;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = v51;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = v52;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = v0;
    sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp2C = (*sp2C & ~1) | 1;
    sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp28 = *sp28 & ~2;
    sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp24 = *sp24 & ~4;
    sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp20 = *sp20 & ~8;
    sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp1C = *sp1C & ~0x10;
    sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp18 = *sp18 & ~0x20;
    sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp14 = *sp14 & ~0x100;
    sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp10 = *sp10 & ~0x200;
    spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *spC = *spC | 0x400;
    sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp8 = *sp8 | 0x800;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 | 0x1000;
    sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp0 = *sp0 | 0x2000;
    Reset3DSpriteEngineState();
}

