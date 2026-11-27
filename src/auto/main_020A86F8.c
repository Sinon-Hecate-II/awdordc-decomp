/* 69 functions from 0x020A86F8 to 0x020A94FC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "map_selection.h"

/* Six encoded localized text ids, one per army state; see sArmyStateMessageIds. */
typedef struct { s32 values[6]; } Table020a8b3c;
typedef struct { u32 value:8; u32 rest:24; } Bits020a8c10;
extern const Table020a8b3c sArmyStateMessageIds;

/* Damage `unit` deals against a target of `targetKind` with weapon `weaponIndex`
   (0 primary, 1 secondary), given the target's `targetFlags`: the unit's attack
   power (100 + its damage bonus) times the weapon's damage percent, over 100,
   never below 1.  Returns 0 when that weapon's damage percent is 0. */
s32 CalculateUnitDamage(u8 *unit, s32 targetKind, s32 weaponIndex, s32 targetFlags) {
 s32 GetUnitDamageBonus(void *, u8, u8);
 s32 GetWeaponDamagePercent(u32, s32, s32, s32);
 s32 Divide();
 s32 percent;
 u32 attackerKind;
 s32 damage;
 s32 attackPower;
 attackerKind = (u32)(unit[0] << 26) >> 26;
 attackPower = GetUnitDamageBonus(unit, unit[1], unit[2]) + 100;
 percent = GetWeaponDamagePercent(attackerKind, targetKind, weaponIndex, targetFlags);
 if (percent == 0) return 0;
 damage = Divide(attackPower * percent, 100);
 if (damage <= 1) damage = 1;
 return damage;
}

/* Attack power of `unit` in percent: the 100 base plus the unit's attack-power
 * bonus, which depends on its owner, stat block and the terrain at its tile. */
s32 GetUnitAttackPower(void *unit) {
    s32 GetUnitAttackPowerBonus(void *, u8, u8);
    return GetUnitAttackPowerBonus(unit, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y)) + 100;
}

/* Attack bonus, in damage percent, that a unit gets from its campaign owner
 * group: groups 1, 2 and 3 are progressively stronger armies (+5, +10, +20),
 * every other group gets none. */
s32 GetOwnerGroupAttackBonus(u32 ownerGroup) {
 switch(ownerGroup) { case 1: return 5; case 2: return 10; case 3: return 20; default: return 0; }
}

/* Defense bonus, in damage percent, that a unit gets from its campaign owner
 * group: only the strongest army, group 3, defends better (+20); every other
 * group gets none. */
s32 GetOwnerGroupDefenseBonus(u32 ownerGroup) {
 switch(ownerGroup) { case 1: return 0; case 2: return 0; case 3: return 20; default: return 0; }
}

/* Attack bonus, in damage percent, that a unit gets from its owner group (the top
 * two bits of its kind byte, MAP_UNIT_OWNER_MASK). */
s32 GetUnitOwnerGroupAttackBonus(u8 *unit) {
    s32 GetOwnerGroupAttackBonus(u32);
    return GetOwnerGroupAttackBonus((u32) (*unit << 0x18) >> 0x1E);
}

/* Defense bonus the unit's campaign owner group grants: take the owner group from
 * the top two bits of the unit's kind byte (MAP_UNIT_KIND) and look up its bonus
 * (only the strongest army, group 3, defends better). */
void GetUnitOwnerGroupDefenseBonus(u8 *unit) {
    M2C_UNK GetOwnerGroupDefenseBonus(u32);
    GetOwnerGroupDefenseBonus((u32) (*unit << 0x18) >> 0x1E);
}

/* Attack bonus, in damage percent, that player `player` gets from the
 * attack-boosting properties it owns (5 percent each). */
s32 GetPlayerAttackPropertyBonus(s32 player) {
    extern s32 *gCurrentMap;
    return M2C_FIELD((player * MAP_PLAYER_STRIDE) + *gCurrentMap, u8 *, PLAYER_ATTACK_PROPERTIES_OFF) * 5;
}

/* Attack-property bonus, in damage percent, that player `player` gets from the
 * attack-boosting properties it owns (5 percent each).  A byte-identical copy of
 * GetPlayerAttackPropertyBonus, used by GetUnitAttackPowerBonus. */
s32 GetPlayerAttackPropertyBonusAlt(s32 player) {
    extern s32 *gCurrentMap;
    return M2C_FIELD((player * MAP_PLAYER_STRIDE) + *gCurrentMap, u8 *, PLAYER_ATTACK_PROPERTIES_OFF) * 5;
}

s32 func_020a886c(void) {
    return 0;
}

s32 *MapData_GetRecord(a) s32 a; {extern u8 data_ov000_021afe90[];return (s32 *)(80*a+(s32)data_ov000_021afe90);}

s32 MapData_GetNameTextId(void) {
    s32 *MapData_GetRecord();
    return *MapData_GetRecord();
}

/* The tileset index of map `mapId`: campaign maps have no entry in the per-map
 * data table and use tileset 0. */
u8 MapData_GetTileset(s32 mapId) {
    if ((mapId >= MAP_ID_CAMPAIGN_FIRST) && (mapId < MAP_ID_CAMPAIGN_END)) {
        return 0U;
    }
    return M2C_FIELD(MapData_GetRecord(), u8 *, MAP_DATA_TILESET);
}

u8 func_020a88c4(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 7);
}

s32 func_020a88d4(void) {
    return M2C_FIELD(MapData_GetRecord(), u16 *, 4) & 1;
}

s32 func_020a88e8(void) {
    return M2C_FIELD(MapData_GetRecord(), u16 *, 4) & 2;
}

s32 func_020a88fc(void) {
    return M2C_FIELD(MapData_GetRecord(), u16 *, 4) & 4;
}

s32 func_020a8910(void) {
    return M2C_FIELD(MapData_GetRecord(), u16 *, 4) & 8;
}

s32 MapData_IsRandomSelectable(void) {
    return M2C_FIELD(MapData_GetRecord(), u16 *, 4) & 0x10;
}

u8 GetMapAiCategory(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 8);
}

u8 MapData_GetPlayerCount(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 9);
}

/* The map-data category of map `mapId`: every custom map id belongs to the
 * custom category; otherwise the map record's own category byte is used. */
u8 MapData_GetCategory(s32 mapId) {
    if ((mapId >= MAP_CUSTOM_FIRST) && (mapId < MAP_CUSTOM_LINK_END)) {
        return MAP_DATA_CATEGORY_CUSTOM;
    }
    return M2C_FIELD(MapData_GetRecord(), u8 *, MAP_DATA_CATEGORY);
}

u8 MapData_GetTurnLimit(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 0xB);
}

u8 MapData_GetBattleSetting(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 0xC);
}

/* The map-specific value of the current map (MAPCONFIG_VALUE): the map data
 * record's value byte in its 0xE10-unit scale, truncated to the 16-bit field. */
u16 MapData_GetMapValue(void) {
    return (u16) (M2C_FIELD(MapData_GetRecord(), u8 *, MAP_DATA_MAP_VALUE) * MAP_DATA_MAP_VALUE_UNIT);
}

/* The map's low value bound, in MAP_DATA_VALUE_LIMIT_UNITs. */
u16 MapData_GetValueLimitLow(void) {
    return (u16) (M2C_FIELD(MapData_GetRecord(), u8 *, MAP_DATA_VALUE_LIMIT_LOW) * MAP_DATA_VALUE_LIMIT_UNIT);
}

/* The highest value the current map's value may reach (MAPCONFIG_VALUE): the
 * map data record's high-bound byte in its 100-unit scale, truncated to 16 bits. */
u16 MapData_GetValueLimitHigh(void) {
    return (u16) (M2C_FIELD(MapData_GetRecord(), u8 *, MAP_DATA_VALUE_LIMIT_HIGH) * MAP_DATA_VALUE_LIMIT_UNIT);
}

u8 func_020a8a04(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 0x10);
}

/* The per-player flags byte of the map data record of `mapId` for player slot
 * `player` (1-based). */
u8 GetMapPlayerFlags(s32 mapId, s32 player) {
    u8 *record = (u8 *) MapData_GetRecord(mapId);
    return M2C_FIELD(record + (player - 1), u8 *, MAP_DATA_PLAYER_FLAGS);
}

/* The CO id the map data record of `mapId` assigns to player slot `player`
 * (1-based): 0 means a random CO, 15 leaves the map's default in place. */
u8 GetMapPlayerCoId(s32 mapId, s32 player) {
    u8 *record = (u8 *) MapData_GetRecord(mapId);
    return M2C_FIELD(record + (player - 1), u8 *, MAP_DATA_PLAYER_CO_ID);
}

/* The player id the map data record of `mapId` assigns to player slot `player`
 * (1-based), used to set each slot's player in the battle. */
u8 GetMapPlayerId(s32 mapId, s32 player) {
    u8 *record = (u8 *) MapData_GetRecord(mapId);
    return M2C_FIELD(record + (player - 1), u8 *, MAP_DATA_PLAYER_ID);
}

/* The army (nation) id the map data record of `mapId` assigns to player slot `player`
 * (1-based); ARM_* ids. */
u8 GetMapPlayerArmyId(s32 mapId, s32 player) {
    u8 *record = (u8 *) MapData_GetRecord(mapId);
    return M2C_FIELD(record + (player - 1), u8 *, MAP_DATA_PLAYER_ARMY);
}

u8 func_020a8a84(void) {
    return M2C_FIELD(MapData_GetRecord(), u8 *, 0x11);
}

/* The map-selection grid position of the map `mapId`: its row in the high byte
 * and its column in the low byte. */
s32 MapData_GetGridPosition(s32 mapId){u8 *p=(u8*)MapData_GetRecord(mapId);return (p[MAP_DATA_GRID_Y]<<8)|p[MAP_DATA_GRID_X];}

/* The id of the map that clearing `mapId` unlocks for follow-up slot `index`
 * (0..3); 0 when that slot has no follow-up map. */
u16 GetMapFollowupMapId(s32 mapId,s32 index){u16 *p=(u16*)MapData_GetRecord(mapId);return M2C_FIELD(p+index,u16 *,MAP_DATA_FOLLOWUP_MAPS);}

/* Music track that the map data of `mapId` assigns to player slot `player`
 * (1-based), 0 when the map leaves the army's track in place. */
s32 MapData_GetPlayerTrack(s32 mapId, s32 player) {
    s32 *record = MapData_GetRecord(mapId);

    return M2C_FIELD(record + (player - 1), s32 *, MAP_DATA_PLAYER_MUSIC);
}

/* The per-player state byte of the map data record of `mapId` for player slot
 * `player` (1-based), used to set up the campaign unit icons. */
u8 GetMapPlayerState(s32 mapId, s32 player) {
    u8 *record = (u8 *) MapData_GetRecord(mapId);
    return M2C_FIELD(record + (player - 1), u8 *, MAP_DATA_PLAYER_STATE);
}

s32 MapData_GetWinRuleTextId(void) {
    return M2C_FIELD(MapData_GetRecord(), s32 *, 0x40);
}

s32 func_020a8b0c(void) {
    return M2C_FIELD(MapData_GetRecord(), s32 *, 0x44);
}

s32 func_020a8b1c(void) {
    return M2C_FIELD(MapData_GetRecord(), s32 *, 0x48);
}

s32 func_020a8b2c(void) {
    return M2C_FIELD(MapData_GetRecord(), s32 *, 0x4C);
}

/* Return the localized label of army state `armyState` (an index into the six
 * army-state message ids). */
s32 GetArmyStateLabel(s32 armyState) {
    s32 GetLocalizedText(s32);
    Table020a8b3c t = sArmyStateMessageIds;
    return GetLocalizedText(t.values[armyState]);
}

M2C_UNK *func_020a8b78(void) {
    extern M2C_UNK data_02126148;
    return &data_02126148;
}

M2C_UNK *func_020a8b84(void) {
    extern M2C_UNK data_0212615c;
    return &data_0212615c;
}

M2C_UNK *func_020a8b90(void) {
    extern M2C_UNK data_02126140;
    return &data_02126140;
}

M2C_UNK *func_020a8b9c(void) {
    extern M2C_UNK data_02126150;
    return &data_02126150;
}

M2C_UNK *func_020a8ba8(void) {
    extern M2C_UNK data_02126154;
    return &data_02126154;
}

M2C_UNK *func_020a8bb4(void) {
    extern M2C_UNK data_02126164;
    return &data_02126164;
}

M2C_UNK *func_020a8bc0(void) {
    extern M2C_UNK data_02126144;
    return &data_02126144;
}

M2C_UNK *func_020a8bcc(void) {
    extern M2C_UNK data_0212614c;
    return &data_0212614c;
}

/* Give player `player` the army (CO) id `armyId` in the live map record: write
 * the low byte of its PLAYER_REC_SPRITE word, keeping the rest of the word (the
 * sprite table selectors and the CO power meter). */
void SetPlayerRecordArmyId(s32 player, s32 armyId) {
    extern s32 *gCurrentMap;
    u8 *record = (u8 *)(*gCurrentMap + MAP_PLAYER_STATES + player * MAP_PLAYER_STRIDE);

    M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) =
        (M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) & ~0xFF) | (armyId & 0xFF);
}

/* Army (CO) id of player `player` in the live map: the low byte of its player
 * record's PLAYER_REC_SPRITE word. */
u32 GetPlayerRecordArmyId(s32 player) {
    extern s32 *gCurrentMap;

    return M2C_FIELD(*gCurrentMap + player * MAP_PLAYER_STRIDE,
                     Bits020a8c10 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE).value;
}

/* Whether `value` lies within the inclusive range `min`..`max`. */
u8 IsIndexInRange(s32 value, s32 min, s32 max) {
    s32 result;

    if ((min <= value) && (value <= max)) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Whether a box at (x, y) of size width x height overlaps the 256x192 screen,
 * so a text glyph that hangs off an edge is still drawn. */
s32 IsBoxOnScreen(s32 x, s32 y, s32 width, s32 height) {
    if (((s32) (x + width) < 0) || (x > SCREEN_WIDTH)) {
        return 0;
    }
    if (((s32) (y + height) < 0) || (y > SCREEN_HEIGHT)) {
        return 0;
    }
    return 1;
}

/* Whether the point (x, y) lies inside the rectangle at (left, top) with the
 * given width and height, its right and bottom edges included. */
s32 IsPointInRect(s32 x, s32 y, s32 left, s32 top, s16 width, s16 height) {
    if (x < left || left + width < x) return 0;
    if (y < top || top + height < y) return 0;
    return 1;
}

/* Largest power-of-two texel chunk (8..256) that fits within `extent`: scaled
 * quads are drawn in chunks no larger than 256 texels, halving down to 8; an
 * extent under the minimum chunk size is returned unchanged. */
u32 GetTileChunkSize(u32 extent) {
    u32 chunkSize;

    chunkSize = 0x100;
loop:
    if (extent >= chunkSize) {
        return chunkSize;
    }
    chunkSize = (u32) (chunkSize << 0xF) >> 0x10;
    if (chunkSize < 8U) {
        return extent;
    }
    goto loop;
}

s32 ScaleFixed8(s32 arg0, s32 arg1) {
    return (s32) (arg0 * arg1) >> 8;
}

void func_020a8cf0(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5,u16 arg6,u16 arg7,u16 arg8,volatile u16 arg9) {
 M2C_UNK SetGxTextureParams(s32,s32,s32,u16,s32);
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 volatile s32 width; volatile s32 z; volatile s32 origin;
 s32 height; s32 flags; s32 scaleY; s32 scaleX;
 s32 y; s32 dy; s32 tileH; u16 index; s32 remaining; s32 x; s32 tileW; s32 dx;
 width=arg3;z=arg2;origin=arg0;
 if(width && (height=arg4)!=0) {
 y=arg1-(ScaleFixed8(height,arg9)>>1);
 index=arg6;
 scaleX=arg8;flags=arg7;scaleY=arg9;
 do {
 remaining=width;
 tileH=GetTileChunkSize((u16)height);
 x=origin-(ScaleFixed8(width,scaleX)>>1);
 dy=(tileH*scaleY)>>8;
 do {
 tileW=GetTileChunkSize((u16)remaining);
 SetGxTextureParams(arg5,tileW,tileH,index,flags);
 dx=tileW*scaleX;
 DrawTexturedQuadUV(x,y,z,dx>>8,dy,0,0,tileW,tileH);
 index+=(tileW*tileH)>>6;
 x+=dx>>8;remaining-=tileW;
 }while(remaining);
 height-=tileH;y+=dy;
 }while(height);
 }
}

s32 func_020a8e28(s32 arg0, s32 arg1) {
    return (s32) ((arg0 - ((s32) (arg0 * arg1) >> 8)) << 0xF) >> 0x10;
}

/* Draw a solid-colour quad centred on (centerX, centerY) at depth z: the base
 * width and height are scaled by scaleX and scaleY (8.8 fixed point, 256 =
 * unchanged), then by widthScale and heightScale (256 = unchanged), which grow
 * the quad from its top-left corner. */
void DrawSolidQuadScaled(s32 centerX,s32 centerY,s32 z,s32 width,s32 height,s32 color,s32 scaleX,s32 scaleY,s32 widthScale,s32 heightScale){
void ResetGxTextureParams();void DrawSolidQuad(s32,s32,s32,s32,s32,u16);s32 px,py,x,y;
px=centerX-(ScaleFixed8(width,scaleX)>>1);py=centerY-(ScaleFixed8(height,scaleY)>>1);x=ScaleFixed8(width,scaleX);y=ScaleFixed8(height,scaleY);
if(widthScale!=256)x=ScaleFixed8(x,widthScale);
if(heightScale!=256)y=ScaleFixed8(y,heightScale);
ResetGxTextureParams();DrawSolidQuad(px,py,z,x,y,(u16)color);}

/* Whether `mapId` is one of the local player's own campaign maps: campaign map
   ids are split into 50-map blocks by player slot, and this is the block
   belonging to the local player. */
u8 IsCampaignMapForLocalPlayer(s32 mapId) {
    s32 GetLocalPlayerIdForOverlay();
    s32 Divide();
    s32 localPlayerId;
    u8 owned;
    if (IsIndexInRange((s16)mapId, MAP_ID_CAMPAIGN_FIRST, MAP_ID_CAMPAIGN_END) == 0) return 0;
    localPlayerId = GetLocalPlayerIdForOverlay();
    if (localPlayerId == (u8)Divide(mapId - MAP_ID_CAMPAIGN_FIRST, MAP_ID_CAMPAIGN_PER_PLAYER)) owned = 1;
    else owned = 0;
    return owned;
}

/* Campaign map ids are split into MAP_ID_CAMPAIGN_PER_PLAYER-map blocks owned by
 * the player slots.  Map `mapId`, when it is one of the local player's own
 * campaign maps, back to its id in the base block; return 0xFFFF otherwise. */
u16 GetCampaignMapBaseId(s32 mapId) {
    M2C_UNK IsLinkSessionActive();
    s32 GetLocalPlayerIdForOverlay();
    u8 IsCampaignMapForLocalPlayer(s32);
    IsLinkSessionActive();
    if (IsCampaignMapForLocalPlayer(mapId) == 0) {
        return 0xFFFFU;
    }
    return (u16) (mapId - (GetLocalPlayerIdForOverlay() * MAP_ID_CAMPAIGN_PER_PLAYER));
}

/* Advance a tween's frame counter by its per-update step: the linear and eased
 * curves stop once the counter reaches the duration, the constant curve keeps
 * counting, and a tween marked done is left alone. */
void UpdateSpriteAnimation(void *arg0) {
    SpriteTween *tween = arg0;
    s16 limit;
    if (tween->done) return;
    switch (tween->mode) {
    case SPRITE_TWEEN_LINEAR:
    case SPRITE_TWEEN_EASE_IN:
    case SPRITE_TWEEN_EASE_OUT:
        tween->current += tween->step;
        limit = tween->duration;
        if (tween->current > limit) tween->current = limit;
        return;
    case SPRITE_TWEEN_SINE:
        tween->current += tween->step;
        return;
    case SPRITE_TWEEN_CONSTANT:
        return;
    }
}

/* Evaluate a sprite tween at its current time: mode selects the curve, base and
 * amplitude shape the value between from and to over duration. */
s16 GetSpriteAnimValue(void *arg0) {
    s32 Divide();
    extern s16 gSinCosTable[];
    s16 duration;
    s16 duration2;
    s16 value;
    s32 remaining;
    u16 current;
    u8 mode;

    mode = ((SpriteTween *)arg0)->mode;
    switch (mode) {
    case SPRITE_TWEEN_LINEAR:
        if (((SpriteTween *)arg0)->duration == 0) {
            value = ((SpriteTween *)arg0)->base + (((SpriteTween *)arg0)->to * ((SpriteTween *)arg0)->amplitude);
        } else {
            value = (((SpriteTween *)arg0)->amplitude * Divide(((SpriteTween *)arg0)->current * (((SpriteTween *)arg0)->to - ((SpriteTween *)arg0)->from), ((SpriteTween *)arg0)->duration)) + (((SpriteTween *)arg0)->base + ((SpriteTween *)arg0)->from);
        }
        return value;
    case SPRITE_TWEEN_EASE_IN:
        duration = ((SpriteTween *)arg0)->duration;
        if (duration == 0) {
            return (s16) (((SpriteTween *)arg0)->base + (((SpriteTween *)arg0)->to * ((SpriteTween *)arg0)->amplitude));
        }
        current = ((SpriteTween *)arg0)->current;
        return (s16) ((((SpriteTween *)arg0)->amplitude * Divide(current * (current * (((SpriteTween *)arg0)->to - ((SpriteTween *)arg0)->from)), duration * duration)) + (((SpriteTween *)arg0)->base + ((SpriteTween *)arg0)->from));
    case SPRITE_TWEEN_EASE_OUT:
        duration2 = ((SpriteTween *)arg0)->duration;
        remaining = duration2 - ((SpriteTween *)arg0)->current;
        return (s16) ((((SpriteTween *)arg0)->base + ((SpriteTween *)arg0)->to) - (((SpriteTween *)arg0)->amplitude * Divide(remaining * (remaining * (((SpriteTween *)arg0)->to - ((SpriteTween *)arg0)->from)), duration2 * duration2)));
    case SPRITE_TWEEN_SINE: {
        u16 u = ((SpriteTween *)arg0)->current;
        s16 a = ((SpriteTween *)arg0)->amplitude;
        s16 base = ((SpriteTween *)arg0)->base;
        s16 val = gSinCosTable[(u >> 4) * 2];
        return (s16)(base + (a * val * 0x10 >> 0x10));
    }
    case SPRITE_TWEEN_CONSTANT:
        return (s16) (((SpriteTween *)arg0)->base + (((SpriteTween *)arg0)->from * ((SpriteTween *)arg0)->amplitude));
    }
    return 0;
}

/* Starts a tween: sets its per-frame step so it advances 0x10000 over `frames`
 * frames, then moves its current value back to its start value. */
void SpriteTween_Start(void *tween, u16 frames) {
    s32 Divide(s32, s32);
    M2C_FIELD(tween, s16 *, 6) = Divide(0x10000, frames);
    M2C_FIELD(tween, u16 *, 2) = (u16) M2C_FIELD(tween, u16 *, 4);
}

/* Advance an animation player by one frame: when the frame counter reaches the
 * current segment's end frame, set up the next segment and move to the following
 * frame-table entry (a -1 mode there marks the table ended); otherwise step the
 * player's tween. */
void StepAnimationFrames(void *arg0) {
    void UpdateSpriteAnimation(void *);
    void SpriteAnim_SetupFrame(void *);
    SpriteAnimPlayer *anim = arg0;
    SpriteAnimFrame *next;

    if (anim->done || anim->ended) return;
    anim->index++;
    if (anim->index >= anim->frame->endFrame) {
        SpriteAnim_SetupFrame(anim);
        next = anim->frame + 1;
        anim->frame = next;
        if (next->mode == -1) anim->ended = 1;
    } else {
        UpdateSpriteAnimation(anim->tween);
    }
}

/* Configures an animation player's tween from the frame entry playing now: copies
 * the entry's mode into the tween, sets the tween's duration and its from/to
 * values, and restarts it (mode 0 derives the per-frame step from the entry's
 * frame count, mode 2 forces a zero-length segment). */
void SpriteAnim_SetupFrame(void *anim) {
void SpriteTween_Start(void *,u16);
SpriteTween *tween;
void *frame=M2C_FIELD(anim,void **,8);
void *next;
s32 length,from,to;
M2C_FIELD(M2C_FIELD(anim,void **,0),u8 *,0)=M2C_FIELD(frame,s32 *,4);
next=M2C_FIELD(anim,void **,8);
switch(M2C_FIELD(next,u32 *,4)){
case 1:case 3:case 4:
length=M2C_FIELD(frame,s16 *,12)-M2C_FIELD(next,s16 *,0);
from=M2C_FIELD(next,s16 *,8);
to=M2C_FIELD(frame,s16 *,20);
tween=M2C_FIELD(anim,SpriteTween **,0);
tween->from=from;
tween->to=to;
tween->duration=length;
tween->current=tween->start;
break;
case 0:
SpriteTween_Start(M2C_FIELD(anim,void **,0),M2C_FIELD(next,u16 *,8));
break;
case 2:
to=M2C_FIELD(frame,s16 *,20);
from=M2C_FIELD(next,s16 *,8);
tween=M2C_FIELD(anim,SpriteTween **,0);
tween->from=from;
tween->to=to;
tween->duration=0;
tween->current=tween->start;
break;
}
}

/* Writes a number into a text sprite as decimal digit glyphs: clamps it to
 * +/-999999, stores the clamped value, works out how many digits it needs, then
 * fills TEXT_SPRITE_DIGITS least-significant first and records the count in
 * TEXT_SPRITE_COUNT.  A zero just leaves the digits cleared. */
void SetTextSpriteValue(void *sprite,s32 number) {
 M2C_UNK MI_CpuFill8(s32,s32,s32);
 s32 Modulo(s32,s32);
 s32 IntPow(s32,s32);
 s32 Divide();
 s32 clamped, count, magnitude, digit; u32 i;
 MI_CpuFill8((s32)sprite+TEXT_SPRITE_DIGITS,0,6);
 clamped=0xf423f;
 if(number<=clamped) {if(number < -clamped)clamped=-clamped;else clamped=number;}
 M2C_FIELD(sprite,s32 *,TEXT_SPRITE_VALUE)=clamped;
 for(count=1;count<=7;count++){
 magnitude=M2C_FIELD(sprite,s32 *,TEXT_SPRITE_VALUE);
 if(magnitude<0)magnitude=-magnitude;
 if(magnitude<IntPow(10,count)){M2C_FIELD(sprite,u8 *,TEXT_SPRITE_COUNT)=count;break;}
 }
 if(!number)return;
 for(i=0;(s32)i<M2C_FIELD(sprite,u8 *,TEXT_SPRITE_COUNT);i++) {
 switch(i){
 case 0:M2C_FIELD(sprite+i,u8 *,TEXT_SPRITE_DIGITS)=Modulo(M2C_FIELD(sprite,s32 *,TEXT_SPRITE_VALUE),10);break;
 case 1:case 2:case 3:case 4:case 5:
 digit=Modulo(M2C_FIELD(sprite,s32 *,TEXT_SPRITE_VALUE),IntPow(10,i+1));
 M2C_FIELD(sprite+i,u8 *,TEXT_SPRITE_DIGITS)=Divide(digit,IntPow(10,i));break;
 }
 }
}

/* X screen coordinate of glyph `index` of a text sprite; glyph 0 is the
 * rightmost one (the digits are stored least significant first).  The top three
 * bits of the sprite's +0x20 flags byte pick the layout: 0 = left aligned at
 * TEXT_SPRITE_ANCHOR_X, 1 = centred on it, 2 = right aligned; each glyph advances
 * +0x17 pixels and the run's width is at +0x14. */
s16 GetTextSpriteGlyphX(void *sprite, s32 index) {
    s32 x = 0;
    s32 count;
    s32 start;
    u8 advance;

    switch ((u32) (M2C_FIELD(sprite, u8 *, 32) << 24) >> 29) {
    case 0:
        x = M2C_FIELD(sprite, u8 *, 23) * (M2C_FIELD(sprite, u8 *, 10) - index - 1) + M2C_FIELD(sprite, s16 *, 6);
        break;
    case 1:
        advance = M2C_FIELD(sprite, u8 *, 23);
        count = M2C_FIELD(sprite, u8 *, 10) - 1;
        start = M2C_FIELD(sprite, s16 *, 6) - ((advance * count + M2C_FIELD(sprite, u8 *, 20)) >> 1);
        x = start + advance * (count - index);
        break;
    case 2:
        start = M2C_FIELD(sprite, u8 *, 23) * -index - M2C_FIELD(sprite, u8 *, 20);
        x = start + M2C_FIELD(sprite, s16 *, 6);
        break;
    }
    return x;
}

/* Set a number sprite's glyph metrics for a font size: sizes 0..2 use 8x8
 * glyphs, sizes 3..5 16x16 glyphs; other sizes leave the sprite unchanged. */
void SetTextSpriteFont(void *sprite,u32 font) {
extern M2C_UNK gSpriteDesc8x8,gSpriteDesc16x16;
switch(font){
case 0:case 1:case 2:
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_W)=8;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_H)=8;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_ADVANCE)=8;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_GLYPH_H)=8;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_TILE_STEP)=1;
M2C_FIELD(sprite,void **,TEXT_SPRITE_DESC)=&gSpriteDesc8x8;
break;
case 3:case 4:case 5:
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_W)=16;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_H)=16;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_ADVANCE)=10;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_GLYPH_H)=16;
M2C_FIELD(sprite,u8 *,TEXT_SPRITE_TILE_STEP)=4;
M2C_FIELD(sprite,void **,TEXT_SPRITE_DESC)=&gSpriteDesc16x16;
break;
}
}

