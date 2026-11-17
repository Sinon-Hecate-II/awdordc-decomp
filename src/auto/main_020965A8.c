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

s32 FindNearestFreeCell(void *arg0, s16 *arg1, s32 arg2) {
    M2C_UNK FloodFillUnitRange(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 *data_027e0058;
    extern s32 gFrameCounter;

    u8 *node = (u8 *)arg0;
    s32 gen = gFrameCounter;
    s32 found = 0;
    s32 threshold = 0x7fff;
    s16 *out = arg1;

    if (node[3] & 8) {
    node_search:
        if (node[8] == arg2 || node[9] == arg2) goto node_check;
        node += 0x10;
        goto node_search;
    node_check:
        if (node[3] & 8) goto node_search;
    }

    FloodFillUnitRange(node[0], node[1], node[2], 0x6e, 0);

    {
        void *base = (void *)*data_027e0058;
        s32 row = 0;
        s32 col;
        s32 inner_count;
        u16 outer_count = *(u16 *)((u8 *)base + 0x5146);

        if (outer_count <= 0) goto done;

    outer_loop:
        if (row >= (s32)*(u16 *)((u8 *)base + 0x5146)) goto done;
        base = (void *)*data_027e0058;
        inner_count = (s32)*(u16 *)((u8 *)base + 0x5144);
        col = 0;
        if (inner_count <= 0) goto outer_next;

    inner_loop:
        if (col >= inner_count) goto outer_next;
        {
            s8 cand = ((s8 **)((u8 *)base + (row << 2) + 0x52e8))[0][col];
            if (cand < 0) goto skip_col;
            {
                u16 rtab = *(u16 *)((u8 *)base + (row << 1) + 0x3758);
                u8 cond = *((u8 *)base + col + rtab + 0x508);
                if (cond != 0) goto skip_col;
                if (threshold < cand) goto skip_col;
                if (threshold == cand) {
                    gen += 1;
                    if (gen & 1) goto skip_col;
                }
                out[0] = (s16)col;
                out[1] = (s16)row;
                found = 1;
                base = (void *)*data_027e0058;
                threshold = ((s8 **)((u8 *)base + (row << 2) + 0x52e8))[0][col];
                inner_count = (s32)*(u16 *)((u8 *)base + 0x5144);
                col += 1;
                goto inner_loop;
            }
        }
    skip_col:
        col += 1;
        goto inner_loop;

    outer_next:
        row += 1;
        base = (void *)*data_027e0058;
        goto outer_loop;
    }

done:
    return found;
}

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

void func_02096b24(void) {
    M2C_UNK SetUiMessageText();
    extern M2C_UNK data_02102e14;
    SetUiMessageText();
    func_020948c4(&data_02102e14);
}

void func_02096b3c(void) {
    M2C_UNK func_02094704(M2C_UNK *);
    extern M2C_UNK data_02102e14;
    func_02094704(&data_02102e14);
}

void func_02096b50(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102dbc;
    SetUiMessageText();
    func_01ffa3dc(&data_02102dbc, 7);
}

void func_02096b6c(void) {
    extern M2C_UNK data_02102d4c;
    SetUiMessageText();
    func_01ffa3dc(&data_02102d4c, 7);
}

void func_02096b88(void) {
    extern M2C_UNK data_02102d84;
    SetUiMessageText();
    func_01ffa3dc(&data_02102d84, 7);
}

/* Refresh the map records for `player`'s team when the view switches to it: count
 * every active teammate's units into the first active opponent's opposing-unit
 * total, refresh each teammate's record, then finish the view update. */
void UpdateTeamRecords(s32 player, M2C_UNK flags) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
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
            func_020c9ebc(mate, flags);
        }
        mate += 1;
        offset += MAP_PLAYER_STRIDE;
    } while (mate < 5);
    func_020c9b70();
}
