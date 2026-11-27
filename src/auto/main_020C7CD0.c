/* 30 functions from 0x020C7CD0 to 0x020C8CBC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov000_ai.h"
typedef struct { u8 bytes[6]; u16 value; u32 year:8,month:6,day:6,hour:6,minute:6; u32 second:6,code:12,rest:14; u32 tail; } CompareRecord;
typedef struct { u8 low:6, state:2; u8 pad[7]; u16 x:6,y:6,rest:4; u8 unkA; u8 kind:4, high:4; } RestoredUnit;
static inline void RestoreKind(RestoredUnit *p,u8 v) {p->kind=v;}
static inline void RestoreX(RestoredUnit *p,u16 v) {p->x=v;}
static inline void RestoreY(RestoredUnit *p,u16 v) {p->y=v;}
static inline void RestoreState(RestoredUnit *p,u8 v) {p->state=v;}
typedef struct { u8 pad0[0xa10]; u16 tiles[0x508]; u8 cells[0x2338]; u16 rows[0xcf6]; u16 width,height; } Map8484;
typedef union {u32 word; struct {u32 low:10;u32 kind:5;u32 gap:3;u32 mode:4;u32 high:10;} bits; struct {u32 x:5,y:5,kind:5,owner:3,mode:4,state:2,unused:8;} fields;} PackedEntry;

/* Expands a compact saved map record into the runtime map record: copies the
 * shared header and the terrain cells, then moves the packed unit entries from
 * +0x1E4 to +0x3D8. The source may be the destination, so a temporary copy of
 * the saved record is taken first in that case. */
void ExpandMapRecord(void *arg0, void *arg1) {
    void *HeapAllocBlock(s32);
    void MI_CpuCopy32(void *, void *, s32);
    void MI_CpuFill32(s32, s32, s32);
    void HeapFreeBlock(void *);
    struct MapRecordSettings { s32 a[4]; };
    struct MapRecordStamp { s32 a[5]; };
    struct PlayerIdPair { u8 a; u8 b; };
    u32 n;
    u8 *dp;
    u8 *sp;
    u8 *src;
    u8 *dst;
    s32 i;

    src = arg0;
    if (arg0 == arg1) {
        src = HeapAllocBlock(MAP_RECORD_SAVE_SIZE);
        MI_CpuCopy32(arg0, src, MAP_RECORD_SAVE_SIZE);
    }
    dst = arg1;
    MI_CpuFill32(0, (s32)dst, MAP_RECORD_SIZE);
    ((MapRecordHeader *)dst)->magic = ((MapRecordHeader *)src)->magic;
    ((MapRecordHeader *)dst)->width = ((MapRecordHeader *)src)->width;
    ((MapRecordHeader *)dst)->height = ((MapRecordHeader *)src)->height;
    sp = src + 6;
    dp = dst + 6;
    n = 16;
    do {
        u8 c0 = sp[0];
        u8 c1 = sp[1];
        sp += 2;
        dp[0] = c0;
        dp[1] = c1;
        dp += 2;
    } while (--n);
    dp[0] = sp[0];
    ((MapRecordHeader *)dst)->playerCount = ((MapRecordHeader *)src)->playerCount;
    *(struct PlayerIdPair *)(dst + 0x28) = *(struct PlayerIdPair *)(src + 0x28);
    *(struct PlayerIdPair *)(dst + 0x2A) = *(struct PlayerIdPair *)(src + 0x2A);
    ((MapRecordHeader *)dst)->playerIds[4] = ((MapRecordHeader *)src)->playerIds[4];
    ((MapRecordHeader *)dst)->propertyCount = ((MapRecordHeader *)src)->propertyCount;
    ((MapRecordHeader *)dst)->unitsPerPlayer = ((MapRecordHeader *)src)->unitsPerPlayer;
    ((MapRecordHeader *)dst)->unitCount = ((MapRecordHeader *)src)->unitCount;
    *(struct MapRecordSettings *)(dst + 0x30) = *(struct MapRecordSettings *)(src + 0x30);
    sp = src + 0x40;
    {
        struct MapRecordStamp *srcStamp = (struct MapRecordStamp *)sp;
        struct MapRecordStamp *dstStamp = (struct MapRecordStamp *)(dst + 0x40);
        *dstStamp = *srcStamp;
    }
    i = 0;
    for (; i < (s32)((MapRecordHeader *)src)->width * (s32)((MapRecordHeader *)src)->height; i++)
        dst[0x54 + i] = src[0x54 + i];
    i = 0;
    for (; i < ((MapRecordHeader *)src)->unitCount; i++)
        ((s32 *)dst)[i + MAP_RECORD_UNITS / 4] = ((s32 *)src)[i + MAP_RECORD_SAVE_UNITS / 4];
    if (arg0 == arg1)
        HeapFreeBlock(src);
}

s32 GetCampaignMapHeader(s32 arg0) {
    extern M2C_UNK gCampaignMapHeaders;
    return (0x54 * arg0) + (s32) &gCampaignMapHeaders;
}

/* Return the campaign map's header record for a campaign map id: the
 * MapRecordHeader at the map's index in the gCampaignMapHeaders table. */
s32 GetMapRecord(mapId)
s32 mapId;
{
 extern M2C_UNK gCampaignMapHeaders;
 return (s32)&gCampaignMapHeaders+sizeof(MapRecordHeader)*GetCampaignMapIndex(mapId);
}

s32 GetMapRecordStamp(a)
s32 a; {
    s32 GetMapRecord();
    return GetMapRecord() + 0x40;
}

s32 GetMapRecordSettings(void) {
    return GetMapRecord() + 0x30;
}

s32 GetCampaignMapSaveType(a)
s32 a; {
    return GetCampaignMapIndex() + 9;
}

/* Whether `mapId` is a campaign map id and its saved record is in use (it has a
 * name and a player count). */
u8 IsCampaignMapRecordValid(s32 mapId) {
    u8 valid;

    if ((mapId < MAP_ID_CAMPAIGN_FIRST) || (mapId >= MAP_ID_CAMPAIGN_END)) {
        return 0U;
    }
    if (GetCampaignMapPlayerCount(mapId) != 0) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}

/* Whether a campaign map record can be played: it must be a campaign slot whose
 * record holds a real player count (0 = empty slot, 0xFF = count not set). */
s32 IsCampaignMapRecordPlayable(s32 mapId) {
    s32 playerCount;
    if (mapId < MAP_ID_CAMPAIGN_FIRST || mapId >= MAP_ID_CAMPAIGN_END) return 0;
    playerCount = GetCampaignMapPlayerCount(mapId);
    if (playerCount == 0 || playerCount == 0xFF) return 0;
    return 1;
}

/* Whether a campaign map record may be shared: it must be a valid, playable,
 * locally saved record of a map the player has cleared, no larger than 10x10
 * cells and holding at most 50 units. */
u8 IsCampaignMapAvailable(s32 mapId) {
    s32 IsLocalCampaignMapRecord(s32);
    s32 IsCampaignMapCleared(s32);
    MapRecordHeader *record;

    if (mapId < MAP_ID_CAMPAIGN_FIRST || mapId >= MAP_ID_CAMPAIGN_END) {
        return 0;
    }
    if (!IsCampaignMapRecordValid(mapId)) {
        return 0;
    }
    if (!IsCampaignMapRecordPlayable(mapId)) {
        return 0;
    }
    if (!IsLocalCampaignMapRecord(mapId)) {
        return 0;
    }
    if (!IsCampaignMapCleared(mapId)) {
        return 0;
    }
    record = (MapRecordHeader *)GetMapRecord(mapId);
    if (record->width > 10) {
        return 0;
    }
    if (record->height > 10) {
        return 0;
    }
    return record->unitCount <= 50;
}

/* Return the name of the campaign map record for `mapId` (its name field), or the
 * localized empty-name text when the record holds no player count (an empty slot). */
s32 GetCampaignMapName(s32 mapId) {
    s32 GetLocalizedText(s32);
    s32 GetCampaignMapPlayerCount(M2C_UNK);
    s32 record;

    record = GetMapRecord(mapId);
    if (GetCampaignMapPlayerCount(mapId) != 0) {
        return record + MAP_RECORD_NAME;
    }
    return GetLocalizedText(0xC00002EC);
}

s32 GetCampaignMapIndex(s32 arg0) {
    return arg0 - 0xE1;
}

/* How many players the campaign map `mapId` is saved for, or 0 when its slot
 * holds no record (no magic, or an empty name). */
s32 GetCampaignMapPlayerCount(s32 mapId) {
    MapRecordHeader *record = (MapRecordHeader *)GetMapRecord(mapId);
    s32 playerCount;
    if (record->magic != MAP_RECORD_MAGIC) return 0;
    if (M2C_FIELD(record, u8 *, MAP_RECORD_NAME) == 0) playerCount = 0;
    else playerCount = record->playerCount;
    return playerCount;
}

/* Whether `mapId` is the last campaign map the player cleared, as recorded in the
 * versus battle record: true while that record holds a battle, the id is a
 * campaign map id and it matches the id saved in the record. */
s32 IsLastCampaignMap(s32 mapId) {
    s32 IsUnitAvailable(M2C_UNK);
    u16 *GetBattleRecord(M2C_UNK);
    u16 *record;

    if (IsUnitAvailable(SAVE_RECORD_TYPE_VERSUS) != 0) {
        record = GetBattleRecord(SAVE_RECORD_TYPE_VERSUS);
        if ((mapId >= MAP_ID_CAMPAIGN_FIRST) && (mapId < MAP_ID_CAMPAIGN_END) && (mapId == M2C_FIELD(record, u16 *, BATTLE_RECORD_MAP))) {
            return 1;
        }
    }
    return 0;
}

/* Whether campaign map record `mapId` was created on this console: a valid
 * campaign record whose stored stamp (GetMapRecordStamp) carries the local
 * console's MAC address. */
s32 IsLocalCampaignMapRecord(s32 mapId) {
 s32 IsLocalMacAddress(s32);
 if(mapId<MAP_ID_CAMPAIGN_FIRST||mapId>=MAP_ID_CAMPAIGN_END)return 0;
 if(!IsCampaignMapRecordValid(mapId))return 0;
 return IsLocalMacAddress(GetMapRecordStamp(mapId));
}

/* Whether the current campaign map is one received over a link that is not stored
 * here yet: a valid campaign-map record that is not local, whose slot does not
 * already hold a saved user map, with no rating yet in its stamp and a nonzero
 * map code. */
u8 IsReceivedCampaignMap(s32 mapId) {
    s32 IsCampaignMapSaved(s32);
    s32 stamp, index; u8 hasCode;
    if (mapId >= MAP_ID_CAMPAIGN_FIRST && mapId < MAP_ID_CAMPAIGN_END) {
        stamp = GetMapRecordStamp(mapId); index = GetCampaignMapIndex(mapId);
        if (!IsCampaignMapRecordValid(mapId)) return 0;
        if (IsLocalCampaignMapRecord(mapId)) return 0;
        if (IsCampaignMapSaved(index)) return 0;
        if (M2C_FIELD(stamp, u32 *, 0xc) >> 29) return 0;
        if (M2C_FIELD(stamp, s32 *, 0x10)) hasCode = 1; else hasCode = 0;
        return hasCode;
    }
    return 0;
}

/* Set a campaign map's star rating: reloads the map's saved record into the
 * map-record buffer, writes `mode` into the top three bits of its stamp word
 * (1..5, set by the map-rating screen), flags the map in the campaign map
 * bitmap, then saves the record back to its slot. */
s32 SetCampaignMapRating(s32 mapId, s32 mode) {
    s32 GetMapRecordBuffer();
    s32 GetMapRecordBufferStamp();
    s32 LoadMapRecord(s32, s32);
    void SetCampaignMapSaved(s32, s32);
    s32 index, record, stamp;

    if (mapId < MAP_ID_CAMPAIGN_FIRST || mapId >= MAP_ID_CAMPAIGN_END) return 0;
    index = GetCampaignMapIndex(mapId);
    record = GetMapRecordBuffer();
    stamp = GetMapRecordBufferStamp();
    if (!LoadMapRecord(mapId, record)) return 0;
    M2C_FIELD(stamp, u32 *, 0xC) = (M2C_FIELD(stamp, u32 *, 0xC) & ~0xE0000000) | (mode << 29);
    SetCampaignMapSaved(index, 1);
    return StoreCampaignMapRecord(mapId, record);
}

/* Normalizes the AI action steps saved with the units of a map record that has
 * just been loaded: a unit still saved in step 0 or 1 drops back to step 0, and
 * the attack and capture steps are kept so the action the unit was in the middle
 * of is resumed.  Steps 2..5 and 7 are left alone, and the kinds whose unit-kind
 * record leaves UNIT_KIND_STATS_UNK_6C clear are skipped. */
s32 ResetSavedUnitActions(void *record) {
    extern u8 gUnitKindStats[];
    typedef union {
        u32 word;
        struct {
            u32 x:5;      /* tile x */
            u32 y:5;      /* tile y */
            u32 kind:5;   /* unit kind */
            u32 owner:3;  /* owner (player) */
            u32 aiStep:4; /* AI action step (MAP_UNIT_AI_STATE) */
            u32 state:2;  /* unit state */
            u32 unused:8;
        } bits;
    } MapRecordUnit;
    s32 i;
    MapRecordUnit *unit;

    for (i = 0; i < ((MapRecordHeader *)record)->unitCount; i++) {
        unit = (MapRecordUnit *)((u8 *)record + MAP_RECORD_UNITS) + i;
        if (gUnitKindStats[unit->bits.kind * UNIT_KIND_STATS_SIZE + UNIT_KIND_STATS_UNK_6C]) {
            switch (unit->bits.aiStep) {
            case 0:
            case 1:
                unit->bits.aiStep = 0;
                break;
            case AI_STEP_ATTACK:
                unit->bits.aiStep = AI_STEP_ATTACK;
                break;
            case AI_STEP_CAPTURE:
                unit->bits.aiStep = AI_STEP_CAPTURE;
                break;
            }
        }
    }
}

/* Rebuild the battle-map units from a saved map record's packed entries, and
 * reselect the saved unit for every player that had one. */
void RestoreMapUnits(s32 record) {
void ResetMapUnits(void);
void *CreateMapUnit(s32,s32,s32,s32);
void SetPlayerSelectedUnit(s32,void *);
extern void **gCurrentMap;
s32 unitIndex,x,y,unitKind,owner,mode,state;
u32 *entry;
RestoredUnit *unit;
ResetMapUnits();
unitIndex=0;
if(unitIndex>=((MapRecordHeader *)record)->unitCount)return;
entry=(u32 *)((u8 *)record+MAP_RECORD_UNITS);
do {
s32 packed=*entry;
x=(u32)(packed<<27)>>27;
y=(u32)(packed<<22)>>27;
unitKind=(u32)(packed<<17)>>27;
owner=(u32)(packed<<14)>>29;
mode=(u32)(packed<<10)>>28;
state=(u32)(packed<<8)>>30;
unit=CreateMapUnit(x,y,unitKind,owner);
if(unit) {
RestoreKind(unit,mode);
RestoreX(unit,x);
RestoreY(unit,y);
RestoreState(unit,state);
if(state==3) {
s32 playerRecord=M2C_FIELD((u8 *)*gCurrentMap+owner*MAP_PLAYER_STRIDE,s32 *,MAP_PLAYER_STATES+PLAYER_REC_SPRITE);
if((u32)(playerRecord<<24)>>24)SetPlayerSelectedUnit(owner,unit);
}
}
unitIndex++;entry++;
}while(unitIndex<((MapRecordHeader *)record)->unitCount);
}

/* Set the battle map up from a saved map record: its name, player count and the
 * five player-slot ids, then its width and height. */
void ApplyMapHeader(MapRecordHeader *record) {
    extern void **gCurrentMap;
    void StringCopy(void *, void *);
    void SetPlayerIdForSlot(s32, s32);
    s32 i;
    u8 *base;
    StringCopy((u8 *)*gCurrentMap + MAP_NAME, record->name);
    M2C_FIELD(*gCurrentMap, u8 *, MAP_PLAYER_COUNT) = record->playerCount;
    for (i = 0; i < MAP_RECORD_PLAYER_SLOTS; i++)
        SetPlayerIdForSlot(i, record->playerIds[i]);
    base = (u8 *)*gCurrentMap;
    M2C_FIELD(base, u16 *, MAP_WIDTH) = record->width;
    base = (u8 *)*gCurrentMap;
    M2C_FIELD(base, u16 *, MAP_HEIGHT) = record->height;
}

/* Applies a saved map record's terrain bytes to the runtime map: for every cell it
 * stores the byte as the cell's terrain and sets the cell's tile id from it. */
s32 ApplyMapTerrain(s32 terrain) {
extern void **gCurrentMap;
void BuildMapRowOffsets(void); u16 TerrainByteToTileId(u32);
s32 x,y; Map8484 *base; u8 *p=(u8 *)terrain;
BuildMapRowOffsets();
base=*gCurrentMap;
for(y=0;y<base->height;y++) {
for(x=0;x<base->width;x++) {
u8 v;
base->cells[base->rows[y]+x]=(v=*p++);
base=*gCurrentMap;
base->tiles[x+base->rows[y]]=TerrainByteToTileId(v);
base=*gCurrentMap;
}
}
return (s32)base;
}

void ApplyMapRecord(s32 arg0) {
    void ApplyMapHeader();
    M2C_UNK ApplyMapTerrain(s32);
    ApplyMapHeader();
    ApplyMapTerrain(arg0 + 0x54);
}

/* Apply a saved map record's units to the battle map: normalize the AI action
 * steps saved with them, then rebuild the units and the selected unit per player. */
void RestoreSavedMapUnits(s32 record) {
    M2C_UNK ResetSavedUnitActions();

    ResetSavedUnitActions(record);
    RestoreMapUnits(record);
}

/* Load the saved record of map `mapId` into the map-record buffer and install it
 * on the battle map: its header and terrain, its units, the property-cell list
 * and the map view.  Returns 0 when the record could not be loaded. */
s32 LoadMapById(s32 mapId) {
    s32 GetMapRecordBuffer();
    s32 LoadMapRecord(s32, s32);
    M2C_UNK RebuildMapPropertyCells();
    M2C_UNK RefreshMapView();
    s32 record;

    record = GetMapRecordBuffer();
    if (LoadMapRecord(mapId, record) == 0) {
        return 0;
    }
    ApplyMapRecord(record);
    RestoreMapUnits(record);
    RebuildMapPropertyCells();
    RefreshMapView();
    return 1;
}

/* Load campaign map `mapId`'s newest saved record into `buffer` and report
 * whether that record still matches the map's own record. */
s32 LoadMapRecord(s32 mapId, s32 buffer) {
    u8 DoesMapRecordMatchBuffer(s32, s32);
    void MI_CpuFill32(s32, s32, s32);
    s32 LoadNewestSaveRecord(s32, s32);
    s32 saveType = GetCampaignMapSaveType(mapId);
    u8 match;
    MI_CpuFill32(0, buffer, MAP_RECORD_SIZE);
    if (!LoadNewestSaveRecord(saveType, buffer)) return 0;
    if (DoesMapRecordMatchBuffer(mapId, buffer)) match = 1; else match = 0;
    return match;
}

/* Store a campaign map's record: take the map's save slot and, when `record` is
 * a valid map record, write the full-size runtime record into it. Returns 1 when
 * it was written. */
s32 StoreCampaignMapRecord(s32 mapId, s32 record) {
    s32 IsValidMapRecord(s32);
    void WriteSaveRecord(s32, s32, s32);
    s32 saveType = GetCampaignMapSaveType(mapId);

    if (!IsValidMapRecord(record)) return 0;
    WriteSaveRecord(saveType, record, MAP_RECORD_SIZE);
    return 1;
}

/* Whether `buffer` holds a valid map record that matches campaign map `mapId`'s
 * own stored record (used to check a loaded save record still fits the map). */
u8 DoesMapRecordMatchBuffer(s32 mapId, s32 buffer) {
    s32 IsValidMapRecord(s32);
    u8 MapRecordsMatch(u8 *, u8 *);
    s32 mapRecord = GetMapRecord(mapId);
    u8 match;

    if (!IsValidMapRecord(buffer)) return 0;
    if (MapRecordsMatch((u8 *)buffer, (u8 *)mapRecord)) match = 1; else match = 0;
    return match;
}

/* Pack the current system date/time and a CRC of the record data into its header. */
void func_020c86a8(void *p) {
    s32 ComputeMapRecordChecksum(); s32 GetRtcDateTime(); void GetMacAddress(void *);
    extern u32 gFrameCounter;
    s32 date[4], time[3];
    s32 v = ComputeMapRecordChecksum(p);
    GetRtcDateTime(date, time);
    GetMacAddress((u8 *)p + 64);
    M2C_FIELD(p, u32 *, 76) = (M2C_FIELD(p, u32 *, 76) & 0xfffc003f) | ((gFrameCounter << 20) >> 14);
    M2C_FIELD(p, u16 *, 70) = v;
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xff) | (u8)date[0];
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0x3f00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xfc000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0x3f00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(p, u32 *, 72) = (M2C_FIELD(p, u32 *, 72) & ~0xfc000000) | (time[1] << 26);
    M2C_FIELD(p, u32 *, 76) = (M2C_FIELD(p, u32 *, 76) & ~0x3f) | (time[2] & 0x3f);
    M2C_FIELD(p, u32 *, 76) &= 0xf003ffff;
    M2C_FIELD(p, u32 *, 76) &= ~0x10000000;
    M2C_FIELD(p, u32 *, 76) &= ~0xe0000000;
    M2C_FIELD(p, u32 *, 80) = 0;
}

void PackCurrentMapRecord(void *arg0){
extern void **gCurrentMap;extern s8 gTerrainPropertyFlags[];
void MI_CpuFill32(s32,s32,s32);void StringCopy(void *,void *);s32 GetPlayerTeam(s32);s32 GetPlayerIdForSlot(s32);void MI_CpuCopy32(void *,void *,s32);void func_020c86a8(void *);void *GetMapSettings(void);
u8 counts[6];u8 *out=arg0;
u8 *cursor=out+0x54;
u16 i;
MI_CpuFill32(0,(s32)out,0x6f8);*(u32 *)out=0x20070731;
StringCopy(out+6,(u8 *)*gCurrentMap+0x5120);
out[4]=((Map8484 *)*gCurrentMap)->width;out[5]=((Map8484 *)*gCurrentMap)->height;
{s32 y,x;
y=0;x=0;do{if(GetPlayerTeam(x))y=(u16)(y+1);x=(u16)(x+1);}while((u32)x<5);
if((u32)y<2)out[0x27]=255;else out[0x27]=y;
x=0;do{out[0x28+x]=GetPlayerIdForSlot(x);x=(u16)(x+1);}while((u32)x<5);
i=0;do{counts[i]=0;i++;}while(i<6);
y=0;while(y<M2C_FIELD(*gCurrentMap,u16 *,0x5146)){
x=0;while(x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)){
Map8484 *map=*gCurrentMap;
s32 row=map->rows[y];
s32 cell=M2C_FIELD((u8 *)map+x+row,u8 *,0x1420);
*cursor++=cell;if(gTerrainPropertyFlags[cell&31]){counts[5]++;counts[cell>>5]++;}
x++;
}y++;
}
}
{s32 k;RestoredUnit *unit;u16 used;
used=0;
for(k=1;k<256;k++){
unit=(RestoredUnit *)((u8 *)*gCurrentMap+0x59a4+k*14);
if(unit->low){
((PackedEntry *)(out+0x3d8))[used].fields.x=M2C_FIELD(unit,u8 *,1);
((PackedEntry *)(out+0x3d8))[used].fields.y=M2C_FIELD(unit,u8 *,2);
((PackedEntry *)(out+0x3d8))[used].fields.owner=unit ? (unit ? (((s32)((u8 *)unit-((u8 *)*gCurrentMap+0x59a4))/14)>>6):0)+1:0;
((PackedEntry *)(out+0x3d8))[used].fields.kind=unit->low;
((PackedEntry *)(out+0x3d8))[used].fields.mode=unit->kind;
((PackedEntry *)(out+0x3d8))[used].fields.state=unit->state;
((PackedEntry *)(out+0x3d8))[used].fields.unused=0;
used++;
}
}
out[0x2f]=used;
}
i=0;do{if(counts[0]<counts[i])counts[0]=counts[i];i++;}while(i<5);
out[0x2d]=counts[5];out[0x2e]=counts[0]+1;
MI_CpuCopy32(GetMapSettings(),out+0x30,16);func_020c86a8(out);
}

/* Returns 1 if the two save/checkpoint record blobs compare equal field-by-field. */
u8 MapRecordsMatch(u8 *lhs, u8 *rhs) {
    s32 i;
    CompareRecord *p;
    CompareRecord *q;

    if (lhs[0x27] != rhs[0x27]) {
        return 0;
    }
    if (lhs[0x2f] != rhs[0x2f]) {
        return 0;
    }
    if (lhs[4] != rhs[4]) {
        return 0;
    }
    if (lhs[5] != rhs[5]) {
        return 0;
    }
    p = (CompareRecord *)(lhs + 0x40);
    q = (CompareRecord *)(rhs + 0x40);
    for (i = 0; i < 6; i++) {
        if (p->bytes[i] != q->bytes[i]) {
            return 0;
        }
    }
    if (p->code != q->code) {
        return 0;
    }
    if (p->value != q->value) {
        return 0;
    }
    if (p->year != q->year) {
        return 0;
    }
    if (p->month != q->month) {
        return 0;
    }
    if (p->day != q->day) {
        return 0;
    }
    if (p->hour != q->hour) {
        return 0;
    }
    if (p->minute != q->minute) {
        return 0;
    }
    if (p->second != q->second) {
        return 0;
    }
    return (u8)(p->tail == q->tail);
}

/* Return whether a stored six-byte hardware address matches this console's MAC address. */
s32 IsLocalMacAddress(s32 storedAddress) {
    void GetMacAddress(void *address);
    u8 localAddress[6];
    s32 byteIndex;

    GetMacAddress(localAddress);
    for (byteIndex = 0; byteIndex < 6; byteIndex++) {
        if (localAddress[byteIndex] != *(u8 *)(storedAddress + byteIndex)) {
            return 0;
        }
    }
    return 1;
}

