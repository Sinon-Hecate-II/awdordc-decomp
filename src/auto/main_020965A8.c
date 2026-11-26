/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u16 unk0, unk2, unk4, unk6; } Unk0209Rect;
typedef struct { u8 kind:6; u8 owner:2; u8 rest[13]; } Unit964;
extern u8 data_02102ee4[];
extern u16 gMapConfig[];
static inline u32 MinUnitResource(u32 a,u32 b) { if(a<=b)b=a;return b; }

/* The word at a player record's +0x6C (PLAYER_REC_SPRITE): low byte the player's army id. */
typedef struct { u32 armyId:8; u32 rest:24; } PlayerSpriteWord;

#pragma opt_strength_reduction off
/* Nearest cell to a deployment entry's tile that holds no unit, used when the
 * entry's tile is already taken: flood the entry's tile as reachable ground,
 * then scan the grid layer for the lowest-value cell without a unit (ties are
 * broken by alternating on the frame counter's parity).  A loaded (carried)
 * entry first steps forward to the entry whose carry link names `unitIndex`. */
s32 FindNearestFreeCell(MapDeploymentEntry *entry, s16 *out, s32 unitIndex) {
    void FloodFillUnitRange(s32, s32, u8, s32, s32);
    extern s32 gFrameCounter;
    extern s32 *gCurrentMap;
    s32 best, tieBreak, found;
    s32 y;
    s32 x;

    tieBreak = gFrameCounter;
    best = 0x7fff;
    found = 0;

    if (entry->flags & UNIT_FLAG_LOADED) {
    node_search:
        if (entry->firstCarried == unitIndex || entry->nextCarried == unitIndex) goto node_check;
        entry++;
        goto node_search;
    node_check:
        if (entry->flags & UNIT_FLAG_LOADED) goto node_search;
    }

    FloodFillUnitRange(entry->x, entry->y, entry->kind, MAP_GRID_NO_UNIT_MAX, 0);
    for (y = 0; y < *(u16 *)(((u8 *)*gCurrentMap) + MAP_HEIGHT); y++) {
        for (x = 0; x < *(u16 *)(((u8 *)*gCurrentMap) + MAP_WIDTH); x++) {
            s8 cand = (*(s8 **)(((u8 *)*gCurrentMap) + MAP_GRID + y * 4))[x];
            if (cand < 0) continue;
            if (((u8 *)*gCurrentMap)[x + *(u16 *)(((u8 *)*gCurrentMap) + MAP_ROW_OFFSETS + y * 2) + MAP_CELL_UNIT_ID]) continue;
            if (best < cand) continue;
            if (best == cand && (++tieBreak & 1)) continue;
            out[0] = x;
            out[1] = y;
            found = 1;
            best = (*(s8 **)(((u8 *)*gCurrentMap) + MAP_GRID + y * 4))[x];
        }
    }
    return found;
}
#pragma opt_strength_reduction reset
/* Place a map's units from its deployment ("dispos") file: each 16-byte entry
 * gives one unit's tile, kind, owner and starting state.  An entry at 0xfe
 * selects the player the following entries belong to (and resets the ids the
 * carried-unit links refer to), 0xff ends the list.  A unit whose tile is
 * taken moves to the nearest free cell when `displace` is set and is skipped
 * otherwise; a loaded unit (UNIT_FLAG_LOADED) occupies no cell at all. */
void PlaceMapDeployment(MapDeploymentEntry *entries,s32 displace) {
extern s32 *gCurrentMap; extern u8 gUnitKindStats[];
BattleMapUnitHead *CreateMapUnit(s32,s32,s32,s32); void SetPlayerSelectedUnit(s32,void*);void RefreshMapView(void);
MapDeploymentEntry *entry=entries; s32 oldPlayer=M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER); u8 unitIds[MAP_UNIT_LIMIT]; u8 unitCount=0; s16 freePos[2]; BattleMapUnitHead *unit; u8 fuel; u16 ammo;
nextEntry:
if(entry->x==MAP_DEPLOY_END)goto done;
{
if(entry->x==MAP_DEPLOY_SWITCH_PLAYER) {
M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)=entry->y;
M2C_FIELD(*gCurrentMap,u16*,MAP_CURSOR_OWNER)=(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)-1)<<6;
entry++;unitCount=0;goto nextEntry;
}
if(((u8*)*gCurrentMap)[entry->x+M2C_FIELD((u8*)*gCurrentMap+entry->y*2,u16*,MAP_ROW_OFFSETS)+MAP_CELL_UNIT_ID]) {
if(!displace){entry++;goto nextEntry;}
if(FindNearestFreeCell(entry,freePos,unitCount)) unit=CreateMapUnit(freePos[0],freePos[1],entry->kind,M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER));
else {entry++;goto nextEntry;}
} else unit=CreateMapUnit(entry->x,entry->y,entry->kind,M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER));
if(!unit)goto done;
if(!(entry->flags&UNIT_FLAG_LOADED)) ((u8*)*gCurrentMap)[unit->x+M2C_FIELD((u8*)*gCurrentMap+unit->y*2,u16*,MAP_ROW_OFFSETS)+MAP_CELL_UNIT_ID]=unit ? unit-(BattleMapUnitHead*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS):0;
unitIds[unitCount++]=unit ? unit-(BattleMapUnitHead*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS):0;
unit->owner=entry->owner;unit->health=entry->health;unit->flags=entry->flags;
fuel=(u8)MinUnitResource(entry->fuel,gUnitKindStats[unit->kind*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_FUEL]);unit->fuel=fuel;
ammo=(u16)MinUnitResource(entry->ammo,gUnitKindStats[unit->kind*UNIT_KIND_STATS_SIZE+UNIT_KIND_STATS_AMMO]);unit->ammo=ammo;
unit->aiState=entry->aiState;
switch(unit->aiState){case 7:case 8:case 9:unit->targetX=entry->targetX;unit->targetY=entry->targetY;break;default:unit->targetX=MAP_UNIT_TARGET_NONE;unit->targetY=MAP_UNIT_TARGET_NONE;break;}
unit->unkB4=entry->unkB4;unit->unk8_12=0;unit->unk8_14=0;unit->unkA_7=0;unit->unkB5=0;unit->unkB6=0;unit->unkB7=0;
if(entry->firstCarried)unit->firstCarried=unitIds[entry->firstCarried-1];if(entry->nextCarried)unit->nextCarried=unitIds[entry->nextCarried-1];
if(entry->selected&&((PlayerSpriteWord*)((u8*)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE+MAP_PLAYER_STATES+PLAYER_REC_SPRITE))->armyId) SetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER),unit);
entry++;goto nextEntry;
}
done:
M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)=oldPlayer;
RefreshMapView();
M2C_FIELD(*gCurrentMap,u16*,MAP_CURSOR_OWNER)=(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER)-1)<<6;
}

void ShowPlayerUnitDialogSequence(void) {
    M2C_UNK SetUiMessageText();
    extern M2C_UNK data_02102e14;
    SetUiMessageText();
    StartDialogSequence(&data_02102e14);
}

void func_02096b3c(void) {
    M2C_UNK IsDialogSequenceActive(M2C_UNK *);
    extern M2C_UNK data_02102e14;
    IsDialogSequenceActive(&data_02102e14);
}

void ShowUiMessage(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102dbc;
    SetUiMessageText();
    CreateSpriteFromClass(&data_02102dbc, 7);
}

void func_02096b6c(void) {
    extern M2C_UNK data_02102d4c;
    SetUiMessageText();
    CreateSpriteFromClass(&data_02102d4c, 7);
}

void func_02096b88(void) {
    extern M2C_UNK data_02102d84;
    SetUiMessageText();
    CreateSpriteFromClass(&data_02102d84, 7);
}

/* Refresh the map records for `player`'s team when the view switches to it: count
 * every active teammate's units into the first active opponent's opposing-unit
 * total, refresh each teammate's record, then finish the view update. */
void UpdateTeamRecords(s32 player, M2C_UNK flags) {
    M2C_UNK EnterBattleEnd();
    M2C_UNK MarkPlayerDefeated(s32, M2C_UNK);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    extern s32 *gCurrentMap;
    s32 temp_r0;
    s32 opponent;
    s32 scan;
    s32 mate;
    s32 offset;
    s32 opponentOffset;
    void *temp_r1;

    opponent = -1;
    scan = 1;
loop_1:
    if ((IsPlayerActive(scan) != 0) && (IsSameTeam(player, scan) == 0)) {
        opponent = scan;
    } else {
        scan += 1;
        if (scan < 5) {
            goto loop_1;
        }
    }
    offset = MAP_PLAYER_STRIDE;
    mate = 1;
    opponentOffset = opponent * MAP_PLAYER_STRIDE;
    do {
        if ((IsSameTeam(player, mate) != 0) && (IsPlayerActive(mate) != 0)) {
            if (opponent != -1) {
                temp_r0 = *gCurrentMap;
                temp_r1 = opponentOffset + temp_r0;
                M2C_FIELD(temp_r1, u16 *, PLAYER_ENEMY_UNITS_OFF) = (u16) (M2C_FIELD(temp_r1, u16 *, PLAYER_ENEMY_UNITS_OFF) + M2C_FIELD((temp_r0 + offset), u8 *, PLAYER_UNIT_COUNT_OFF));
            }
            MarkPlayerDefeated(mate, flags);
        }
        mate += 1;
        offset += MAP_PLAYER_STRIDE;
    } while (mate < 5);
    EnterBattleEnd();
}
