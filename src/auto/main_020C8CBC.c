/* 37 functions from 0x020C8CBC to 0x020C9B9C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline u64 Pack_020c91ac(u64 x, u64 y, u64 z, u32 w) {
    return (x<<20) | (y<<36) | (z<<4) | (w&15);
}

/* Find the campaign map whose saved record matches `record`: scan this player's
 * campaign map slots (id MAP_ID_CAMPAIGN_FIRST + index) in order and return the
 * first valid record that matches, or 0 when none does. */
s32 FindCampaignMapId(M2C_UNK record) {
    s32 GetMapRecord(s32);
    s32 IsCampaignMapRecordValid(s32);
    s32 MapRecordsMatch(M2C_UNK, s32);
    s32 index;

    index = 0;
loop_1:
    if ((IsCampaignMapRecordValid(index + MAP_ID_CAMPAIGN_FIRST) != 0) && (MapRecordsMatch(record, GetMapRecord(index + MAP_ID_CAMPAIGN_FIRST)) != 0)) {
        return index + MAP_ID_CAMPAIGN_FIRST;
    }
    index += 1;
    if (index >= MAP_ID_CAMPAIGN_PER_PLAYER) {
        return 0;
    }
    goto loop_1;
}

/* Clear a campaign map's played, cleared and saved progress flags; when it is the
 * map held by the versus battle record, start a fresh battle record. */
s32 ClearCampaignMapProgress(s32 mapId) {
    void SetCampaignMapPlayed(s32,s32);
    void SetCampaignMapCleared(s32,s32);
    void SetCampaignMapSaved(s32,s32);
    s32 IsLastCampaignMap(s32);
    void StartBattleRecord(s32);
    SetCampaignMapPlayed(mapId,0);
    SetCampaignMapCleared(mapId,0);
    SetCampaignMapSaved(mapId-MAP_ID_CAMPAIGN_FIRST,0);
    if(!IsLastCampaignMap(mapId))return;
    StartBattleRecord(8);
}

/* Rebuild the live battle map's save record, clear the target campaign map's
 * progress flags and write that record to the map's save slot. */
void StoreCurrentMapAsCampaignMap(s32 mapId) {
    s32 GetMapRecordBuffer();
    M2C_UNK StoreCampaignMapRecord(M2C_UNK, s32);
    M2C_UNK PackCurrentMapRecord(); /* packs the record buffer still in r0 */
    s32 record;

    record = GetMapRecordBuffer();
    PackCurrentMapRecord();
    ClearCampaignMapProgress(mapId);
    StoreCampaignMapRecord(mapId, record);
}

/* Refresh one campaign map's cached header from its save record: accept only
 * campaign map ids, load the newest record of that map's save type, require a
 * terminated name, then cache the record's 0x54-byte header.  Returns 0 when
 * any step fails. */
s32 LoadCampaignMapHeader(s32 mapId) {
s32 GetMapRecordTerrain();MapRecordHeader *GetMapRecordHeader();s32 GetCampaignMapIndex(s32);
s32 LoadNewestSaveRecord(u8,s32);s32 StringHasTerminator(void *,s32);
extern u8 gCampaignMapHeaders[];
s32 recordBuffer=GetMapRecordBuffer(),index,inRange;u32 valid;MapRecordHeader *record;
GetMapRecordTerrain();record=GetMapRecordHeader();inRange=0;
if(mapId>=MAP_ID_CAMPAIGN_FIRST) inRange=(mapId<MAP_ID_CAMPAIGN_END);
valid=(inRange==0)?0:1;if(!valid)return 0;
index=GetCampaignMapIndex(mapId);if(!LoadNewestSaveRecord((u8)(index+SAVE_TYPE_CAMPAIGN_MAP),recordBuffer))return 0;
if(!StringHasTerminator(record->name,0x21))return 0;
MI_CpuCopy32(record,(MapRecordHeader *)gCampaignMapHeaders+index,sizeof(MapRecordHeader),record->settings.rules&=~MAP_SETTINGS_MAP_ID);
return 1;
}

void func_020c8e40(void) {
    M2C_UNK LoadCampaignMapHeader(s32);
    s32 var_r4;

    ClearCampaignMapHeaders();
    var_r4 = 0;
    do {
        LoadCampaignMapHeader(var_r4 + 0xE1);
        var_r4 += 1;
    } while (var_r4 < 0x32);
}

void func_020c8e64(void *arg0) {
    M2C_UNK ClearCampaignMapHeaders();
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    ClearCampaignMapHeaders();
}

/* Load the campaign map headers of every map left in the list, starting at the
 * loader's current index (0-based within the campaign's map slots). */
void LoadCampaignMapHeadersFrom(void *loader) {
    s32 index;

    index = M2C_FIELD(loader, s32 *, 0x5C);
    if (index >= MAP_ID_CAMPAIGN_PER_PLAYER) {
        return;
    }
    do {
        LoadCampaignMapHeader(index + MAP_ID_CAMPAIGN_FIRST);
        index += 1;
    } while (index < MAP_ID_CAMPAIGN_PER_PLAYER);
}

/* Per-frame step of a campaign-map header loader: load the header for the map at
 * the loader's current index (MAP_ID_CAMPAIGN_FIRST + counter), advance the
 * counter, and once all MAP_ID_CAMPAIGN_PER_PLAYER maps are done resume the sprite. */
void StepCampaignMapHeaderLoad(void *loader) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 index;

    LoadCampaignMapHeader(M2C_FIELD(loader, s32 *, 0x5C) + MAP_ID_CAMPAIGN_FIRST);
    index = M2C_FIELD(loader, s32 *, 0x5C) + 1;
    M2C_FIELD(loader, s32 *, 0x5C) = index;
    if (index != MAP_ID_CAMPAIGN_PER_PLAYER) {
        return;
    }
    Sprite_ResumeAnimation(loader);
}

#pragma optimization_level 2
void func_020c8ed4(M2C_UNK arg0) { M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK); extern M2C_UNK data_0212b07c; CreateSpriteFromClass(&data_0212b07c,arg0); }
s32 ClearCampaignMapHeaders(void) { s32 MI_CpuFill32(s32,void *,s32); extern u8 gCampaignMapHeaders[]; return MI_CpuFill32(0,gCampaignMapHeaders,0x41a0); }

/* Decodes a game text string into the font's glyph codes: ordinary characters go
 * through the shared text decoder, while the 0x1F escape supplies a raw glyph code
 * (with 0x8C/0x9C remapped). Returns the number of glyphs written, or -1 when the
 * decoder fails. */
s32 ConvertTextToGlyphs(s16 *dst,u8 *src) {
s32 func_02019e64(s16 *,s32 *,u8 *,s32 *,s32); s32 IsLeadByte(u8 *); s32 IsGlyphEscape(u8 *);
s32 out; s32 in; s32 count=0; s32 isDouble; s32 result; s32 charLen; s8 trail; u8 code;
if(*src) { do {
if(IsGlyphEscape(src)) {
code=src[1];
switch(code) {
case 0x8c:*dst=0x152;break;
case 0x9c:*dst=0x153;break;
default:*dst=code;break;
}
src+=2;
} else {
isDouble=0;
if((u32)((src[0]^0x20)-0xa1)<0x3c) {
trail=(s8)src[1]; if(trail!=0x7f && (u8)(trail-0x40)<=0xbc) isDouble=1;
}
if(isDouble) charLen=2;else charLen=1;
in=charLen;
out=1;
if(func_02019e64(dst,&out,src,&in,0)==0) result=out;else result=-1;
if(result<0) return -1;
if(IsLeadByte(src)) src+=2;else src++;
}
dst++;count++;
} while(*src); }
*dst=0;return count;
}

#pragma optimization_level reset
void func_020c9040(void *a) {
void GotoSpriteAnimationLabel(void *,s32);
M2C_FIELD(a,volatile u8 *,0x35)=0;
if(M2C_FIELD(a,volatile u8 *,0x34)) return;
GotoSpriteAnimationLabel(a,0);
}

/* Per-frame step of the campaign map list loader: expands the next queued map
 * record into the map headers - first clearing the flags and bumping the ten-bit
 * counter of its stamp word - and sets that map's label.  When every queued
 * record is done the loader resumes its waiting owner. */
void LoadNextCampaignMapRecord(void *loader) {
    s32 IsSaveInProgress();
    s32 stamp;
    u16 mapId;
    u32 count;
    u8 index;
    void *record;

    if (IsSaveInProgress() != 0) {
        return;
    }
    index = M2C_FIELD(loader, u8 *, 0x35);
    if ((u32) index >= (u32) M2C_FIELD(loader, u8 *, 0x34)) {
        Sprite_ResumeAnimation(loader);
        return;
    }
    record = M2C_FIELD((loader + (index * 4)), void **, 0x4C);
    mapId = M2C_FIELD((loader + (index * 2)), u16 *, 0x36);
    stamp = M2C_FIELD(record, s32 *, MAP_RECORD_STAMP_WORD) & ~0xE0000000;
    count = (u32) (stamp * 0x10) >> 0x16;
    M2C_FIELD(record, s32 *, MAP_RECORD_STAMP_WORD) = stamp;
    if (count < MAP_RECORD_STAMP_COUNT_MAX) {
        M2C_FIELD(record, s32 *, MAP_RECORD_STAMP_WORD) = (s32) ((M2C_FIELD(record, s32 *, MAP_RECORD_STAMP_WORD) & 0xF003FFFF) | ((u32) ((count + 1) << 0x16) >> 4));
    }
    ClearCampaignMapProgress(mapId);
    StoreCampaignMapRecord(mapId, record);
    M2C_FIELD(loader, u8 *, 0x35) = (u8) (M2C_FIELD(loader, u8 *, 0x35) + 1);
}

void func_020c9100(s32 a) {
void *CreateSpriteForOwner();
extern M2C_UNK gCampaignMapLoadQueueClass;
M2C_FIELD(CreateSpriteForOwner(&gCampaignMapLoadQueueClass,a),u8 *,0x34)=0;
}

/* Append a map id and its runtime record to the campaign map load queue; the
 * queue's per-frame step expands them into the campaign map headers. */
void AppendCampaignMapLoadEntry(s16 mapId, s32 record) {
    extern M2C_UNK gCampaignMapLoadQueueClass;
    void *queue;

    queue = FindObjectByClass(&gCampaignMapLoadQueueClass);
    if (queue == NULL) {
        return;
    }
    M2C_FIELD((queue + (M2C_FIELD(queue, u8 *, CAMPAIGN_LOAD_QUEUE_COUNT) * 2)), s16 *, CAMPAIGN_LOAD_QUEUE_IDS) = mapId;
    M2C_FIELD((queue + (M2C_FIELD(queue, u8 *, CAMPAIGN_LOAD_QUEUE_COUNT) * 4)), s32 *, CAMPAIGN_LOAD_QUEUE_RECORDS) = record;
    M2C_FIELD(queue, u8 *, CAMPAIGN_LOAD_QUEUE_COUNT) = (u8) (M2C_FIELD(queue, u8 *, CAMPAIGN_LOAD_QUEUE_COUNT) + 1);
}

/* Erase the campaign map chosen in the map list: clear its progress flags and
 * delete its saved record, rewriting the shared settings record. */
void EraseCampaignMapSave(void *panel) {
    M2C_UNK DeleteSaveRecordAndSaveSettings(s32);
    s32 GetCampaignMapSaveType(s32);
    M2C_UNK ClearCampaignMapProgress(s32);
    s32 saveType;
    s32 mapId;

    mapId = M2C_FIELD(panel, s32 *, CAMPAIGN_ERASE_PANEL_MAP_ID);
    saveType = GetCampaignMapSaveType(mapId);
    ClearCampaignMapProgress(mapId);
    DeleteSaveRecordAndSaveSettings(saveType);
}

void func_020c9190(s32 arg0) {
    void *CreateSpriteForOwner();
    extern M2C_UNK data_0212b114;
    M2C_FIELD(CreateSpriteForOwner(&data_0212b114), s32 *, 0x34) = arg0;
}

#pragma opt_instruction_scheduling off
/* Pack a campaign map record into its shareable 64-bit map code: the low
 * nibble of the record's stamp counter in bits 0..3, the inverted halves of the
 * recording console's WFC player id in bits 4..19 and 36..51 (MapCode_GetPid
 * re-inverts them) and the record checksum in bits 20..35.  Returns 0 when the
 * map has no valid record or the stamp names no console. */
u64 PackMapCode(s32 mapId) {
s32 IsCampaignMapRecordValid(s32); void *GetMapRecordStamp(s32);
void *stamp; s32 playerId;
if (!IsCampaignMapRecordValid(mapId)) return 0;
stamp=GetMapRecordStamp(mapId); playerId=M2C_FIELD(stamp,s32 *,0x10);
if (!playerId) return 0;
return ((u64)(u16)~playerId<<36) | ((u64)(s32)M2C_FIELD(stamp,u16 *,6)<<20) | ((u64)(s32)(u16)(~playerId>>16)<<4) | ((M2C_FIELD(stamp,u32 *,0xc)<<14>>20)&15);
}
#pragma opt_instruction_scheduling reset
s32 MapCode_GetPid(u64 a) {
return ~((u32)((a>>4)&0xffff)<<16 | (u32)((a>>36)&0xffff));
}

u16 MapCode_GetCrc(u64 a) {
return (u16)((a>>20)&0xffff);
}

/* Format the packed code of map `mapIndex` as four base-10000 decimal groups
 * and draw it into the text sprite of `owner` at vertical position `y`. Returns
 * 0 when the map has no valid record. */
s32 DrawMapCode(s32 mapIndex,s32 y,s32 owner) {
void *GetMapRecordStamp(s32); void *CreateTextLayer(s32);
void StringFormat(void *,const void *,...); void RenderTextLayer(void *,s32,s32,void *);
extern char sMapCodeFormat[];
u64 code=PackMapCode(mapIndex), mid, top; s32 group3,group2,group1,group0; char buf[64]; void *sprite;
GetMapRecordStamp(mapIndex);
if(!code)return 0;
mid=code/10000; top=mid/10000;
MapCode_GetPid(code);MapCode_GetCrc(code);
group3=(top/10000)%10000; group2=top%10000; group1=mid%10000; group0=code%10000;
StringFormat(buf,sMapCodeFormat,group3,group2,group1,group0);
sprite=CreateTextLayer(owner);RenderTextLayer(sprite,2,y<<5,buf);
M2C_FIELD(sprite,u32 *,0x58)|=0x400;return 1;
}

/* Clears the cursor's held-direction state: each input channel's held direction
 * (+0..+1), the two channels remembered as used (+2/+3), and the two
 * direction-marker slots. */
void ClearHeldDirections(void) {
    extern M2C_UNK gHeldDirections;
    extern M2C_UNK data_ov000_021e146c;
    M2C_FIELD(&gHeldDirections, u8 *, 0) = 0;
    M2C_FIELD(&gHeldDirections, u8 *, 1) = 0;
    M2C_FIELD(&gHeldDirections, u8 *, 2) = 0;
    M2C_FIELD(&gHeldDirections, u8 *, 3) = 0;
    M2C_FIELD(&data_ov000_021e146c, void **, 0) = NULL;
    M2C_FIELD(&data_ov000_021e146c, void **, 4) = NULL;
}

/* Set the direction held on cursor selector `selector` to `direction` (a
 * direction code + 1, 0 = none) and remember this selector as the last one used,
 * so that a release can clear that selector's direction. */
void SetHeldDirection(s32 selector, s32 direction) {
    s32 CountHeldDirections(s32);
    extern M2C_UNK gHeldDirections;

    if (!CountHeldDirections(selector)) M2C_FIELD(&gHeldDirections, u8 *, 2) = selector;
    else M2C_FIELD(&gHeldDirections, u8 *, 3) = selector;
    M2C_FIELD(&gHeldDirections, u8 *, selector) = direction;
}

u8 GetHeldDirection(s32 arg0) {
    extern M2C_UNK gHeldDirections;
    return M2C_FIELD(&gHeldDirections, u8 *, arg0);
}

/* Resolves the direction held on cursor input channel `channel` into the code a
   battle command carries: it steps the cursor cell one cell that way and, when
   the step's cell is not marked in the player's bitmap but holds a unit, reports
   direction 5 instead. */
s32 ResolveHeldDirection(u32 x,s32 y,s32 channel) {
extern void **gCurrentMap;
s32 dir=GetHeldDirection(channel);
void *map;
switch(dir) {case 0: break; case 1: y--; break; case 2: x++; break; case 3: y++; break; case 4: x--; break;}
if(!dir) return dir;
map=*gCurrentMap;
x+=M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS);
if((u8)(M2C_FIELD(map+(x>>3),u8 *,MAP_CELL_BITMAP) & (1<<(x&7)))) return dir;
if(M2C_FIELD(map+x,u8 *,MAP_CELL_UNIT_ID)) dir=5;
return dir;
}

/* Combine the MAP_DIR_* bits of the directions currently held on the two cursor
 * input channels, read from the gMapCursorDirs direction table. */
s32 GetHeldMapDirections(void) {
    extern u8 gMapCursorDirs[][4];
    s32 mask = 0;
    if (GetHeldDirection(0)) mask |= gMapCursorDirs[GetHeldDirection(0) - 1][MAP_CURSOR_DIR_MASK];
    if (GetHeldDirection(1)) mask |= gMapCursorDirs[GetHeldDirection(1) - 1][MAP_CURSOR_DIR_MASK];
    return mask;
}

/* How many of the two cursor input channels currently hold a direction
 * (0..2); the selector argument is not used. */
s32 CountHeldDirections(s32 unused) {
    s32 count = 0;

    if (GetHeldDirection(0)) count++;
    if (GetHeldDirection(1)) count++;
    return count;
}

#pragma optimization_level 3
void func_020c9580(s32 a) {
extern void **gCurrentMap;
extern M2C_UNK gMapCursorDirDX,gMapCursorDirDY,data_ov000_021e146c;
s32 CreateDirectionMarker(s32,s32);
s32 i = (s32)GetHeldDirection(a) - 1;
volatile void *p = *gCurrentMap;
s32 x = M2C_FIELD(p,s16 *,0x52dc);
s32 y = M2C_FIELD(p,s16 *,0x52de);
M2C_FIELD(&data_ov000_021e146c,s32 *,a*4)=CreateDirectionMarker(x + M2C_FIELD(&gMapCursorDirDX,s8 *,i*4), y + M2C_FIELD(&gMapCursorDirDY,s8 *,i*4));
}
#pragma optimization_level reset
void func_020c95e4(void) {
extern M2C_UNK gHeldDirections;
s32 CountHeldDirections();
u32 i=CountHeldDirections()+1;
u8 *p=(u8 *)&gHeldDirections;
i=p[i];
p[i]=0;
DeleteDirectionMarkerSprites();
}

/* Face the map action popup sprite at tile (tileX, tileY): use animation frame
 * `baseFrame` when the tile's screen x is in the left half, else the next frame. */
void OrientMapActionPopup(s32 tileX, s32 tileY, s32 baseFrame, void *sprite) {
    void MapTileToScreen(s32, s32, s32 *);
    void SetSpriteAnimFrame(void *, s32);
    s32 screenPos[3];
    MapTileToScreen(tileX, tileY, screenPos);
    if (screenPos[0] < 128) { SetSpriteAnimFrame(sprite, baseFrame); return; }
    SetSpriteAnimFrame(sprite, baseFrame + 1);
}

/* Plays the map action sound effect belonging to an action mode at tile (x, y):
 * the repair/refill and level-up popups, unit selection, and the army-specific
 * production sound share this dispatcher. */
void PlayMapActionSound(s32 x, s32 y, s32 mode) {
    M2C_UNK PlaySoundAtTile(s32, M2C_UNK, M2C_UNK);
    switch (mode) {
    case 0: PlaySoundAtTile(0x81, x, y); return;
    case 1: PlaySoundAtTile(0xE4, x, y); return;
    case 2: PlaySoundAtTile(0xE4, x, y); return;
    case 3: PlaySoundAtTile(0x114, x, y); return;
    case 4: PlaySoundAtTile(0x111, x, y); return;
    case 5: PlaySoundAtTile(0x111, x, y); return;
    case 6: PlaySoundAtTile(0x111, x, y); return;
    case 7: PlaySoundAtTile(0x111, x, y); return;
    }
}

#pragma optimization_level 3
void func_020c9730(void *arg0) {
void *CreateSpriteAnim(M2C_UNK *,s32,s32);
void PlayMapActionSound(s32,s32,s32);
extern M2C_UNK data_02120920;
void *p=CreateSpriteAnim(&data_02120920,14,6);
M2C_FIELD(arg0,void **,0x54)=p;
M2C_FIELD(p,s32 *,0x28)=0x329a0;
M2C_FIELD(M2C_FIELD(arg0,void **,0x54),s32 *,0x2c)=0x1560;
OrientMapActionPopup(M2C_FIELD(arg0,s32 *,0x34)/16,M2C_FIELD(arg0,s32 *,0x38)/16,M2C_FIELD(arg0,s32 *,0x48),M2C_FIELD(arg0,void **,0x54));
M2C_FIELD(arg0,s32 *,0x50)=0x200;
M2C_FIELD(arg0,s32 *,0x4c)=-1;
PlayMapActionSound(M2C_FIELD(arg0,s32 *,0x3c),M2C_FIELD(arg0,s32 *,0x40),M2C_FIELD(arg0,s32 *,0x44));
func_020cc6a4();
}
#pragma optimization_level reset
/* Per-frame update of a map action popup (repair/refill/level-up sprite): draw
 * its 3D sprite zoomed by the popup's scale, then count down the popup timer
 * or, while the zoom-in is still running, ease the scale toward 1x and start the
 * timer once it gets there.  A face button or the timer running out deletes the
 * popup. */
void UpdateMapActionPopup(void *arg0) {
    s32 GetFrameStep(void);
    s32 Divide(s32, s32);
    M2C_UNK DrawSprite3D(s32, s32 *, s32, M2C_UNK);
    s32 Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    s32 pos[3];
    s32 step;
    s32 timer;
    s32 next;
    s32 current;
    s32 eased;
    u32 delta;

    step = GetFrameStep();
    current = M2C_FIELD(arg0, s32 *, MAP_ACTION_SCALE);
    step = Divide(step * current, 0x100);
    pos[0] = M2C_FIELD(arg0, s32 *, MAP_ACTION_X) * 0x30;
    pos[1] = M2C_FIELD(arg0, s32 *, MAP_ACTION_Y) * 0x30;
    pos[2] = 0x8B1;
    DrawSprite3D(M2C_FIELD(arg0, s32 *, MAP_ACTION_SPRITE), pos, step, 0);
    timer = M2C_FIELD(arg0, s32 *, MAP_ACTION_TIMER);
    if (timer > 0) {
        next = timer - 1;
        M2C_FIELD(arg0, s32 *, MAP_ACTION_TIMER) = next;
        if ((next != 0) && !(*gKeyState & (KEY_A | KEY_B | KEY_START | KEY_X | KEY_Y))) {
            return;
        }
        Sprite_ResumeAnimation(arg0);
        return;
    }
    current = M2C_FIELD(arg0, s32 *, MAP_ACTION_SCALE);
    delta = (u32)(current - 0x100);
    eased = current - ((s32)((delta + (delta >> 31))) >> 1);
    if ((eased - 0x100) == 4) {
        M2C_FIELD(arg0, s32 *, MAP_ACTION_TIMER) = MAP_ACTION_HOLD;
        eased = 0x100;
    }
    M2C_FIELD(arg0, s32 *, MAP_ACTION_SCALE) = eased;
}

void func_020c989c(void *arg0) {
    void Sprite_ClearHandle(s32 *);
    M2C_UNK ReleaseMapViewHold();
    ReleaseMapViewHold();
    Sprite_ClearHandle(M2C_FIELD(arg0, s32 *, 0x54));
}

u8 func_020c98b4(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_0212b3e4;
    u8 var_r0;

    if (FindObjectByClass(&data_0212b3e4) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020c98d8(s32 x, s32 y, s32 mode) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    void SetFileDirectory(M2C_UNK *);
    M2C_UNK GetLocalizedFileName(M2C_UNK *);
    M2C_UNK QueueFileToTextureBank(M2C_UNK, M2C_UNK);
    M2C_UNK QueueFileToObjExtPalette(M2C_UNK *, M2C_UNK, s32);
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, s32);
    s32 StepMapViewToTile(s32, s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, s32);
    void PlayMapActionSound(s32, s32, s32);
    extern void **gCurrentMap;
    extern M2C_UNK data_0212b3e4;
    extern M2C_UNK data_0212b77c;
    extern M2C_UNK data_0212b788;
    extern M2C_UNK data_0212b794;
    extern M2C_UNK data_0212b79c;
    extern M2C_UNK data_0212b7a4;
    extern M2C_UNK data_0212b7b0;
    extern M2C_UNK data_0212b7bc;
    extern M2C_UNK data_0212b7c8;
    s32 px;
    s32 py;
    u16 height;
    s32 xs;
    s32 ys;
    u8 terrain;
    void *obj;
    s32 pass;
    u16 row;
    s32 idx;
    u8 occ;
    s32 low;

    height = M2C_FIELD(*gCurrentMap, u16 *, 0x52a4);
    xs = x << 4;
    ys = y << 4;
    terrain = M2C_FIELD((s8 *)(*gCurrentMap) + height * 0x8c + 0x6000, u8 *, 0x7c3);
    px = xs + 8;
    py = ys + 8;

    if (terrain & 0x2) {
        pass = 1;
    } else {
        row = M2C_FIELD((s8 *)(*gCurrentMap) + y * 2 + 0x3700, u16 *, 0x58);
        idx = x + row;
        if ((u8)(M2C_FIELD((s8 *)(*gCurrentMap) + ((u32)idx >> 3) + 0x5000, u8 *, 0x201) & (1 << (idx & 7)))) pass = 1;
        else pass = 0;
    }
    if (!pass) return 0;

    if (mode != 0 && mode != 1 && mode != 2) goto second_path;

    if (FindObjectByClass(&data_0212b3e4) == 0) {
        SetFileDirectory(&data_0212b77c);
        QueueFileToTextureBank(GetLocalizedFileName(&data_0212b788), 0x329a0);
        QueueFileToObjExtPalette(&data_0212b794, 0x1560, 0x20);
    }
    obj = (void *)CreateSpriteFromClass(&data_0212b3e4, 7);
    M2C_FIELD(obj, s32 *, 0x34) = px;
    M2C_FIELD(obj, s32 *, 0x38) = py;
    M2C_FIELD(obj, s32 *, 0x3c) = x;
    M2C_FIELD(obj, s32 *, 0x40) = y;
    M2C_FIELD(obj, s32 *, 0x44) = mode;
    switch(mode) { case 0: M2C_FIELD(obj,s32 *,0x48)=0;break; case 1:M2C_FIELD(obj,s32 *,0x48)=2;break; case 2:M2C_FIELD(obj,s32 *,0x48)=4;break; }
    StepMapViewToTile(x, y);
    return 1;

second_path:
    switch (mode) {
        case 3: CreateAnimatedMapSprite(&data_0212b79c, x, y, 8, 0, 0, 7); break;
        case 4: CreateAnimatedMapSprite(&data_0212b7a4, x, y, 8, 0, 0, 7); break;
        case 5: CreateAnimatedMapSprite(&data_0212b7b0, x, y, 8, 0, 0, 7); break;
        case 6: CreateAnimatedMapSprite(&data_0212b7bc, x, y, 8, 0, 0, 7); break;
        case 7: CreateAnimatedMapSprite(&data_0212b7c8, x, y, 8, 0, 0, 7); break;
        default: break;
    }
    PlayMapActionSound(x, y, mode);
    return 1;
}

/* Enter the end-of-battle state: restore the active armies' players, run the
 * battle-end event and switch the map state machine to the battle-finish step. */
void EnterBattleEnd(void) {
    M2C_UNK RestorePlayersOfActiveArmies();
    M2C_UNK RunBattleEndEvent();
    extern void **gCurrentMap;
    RestorePlayersOfActiveArmies();
    RunBattleEndEvent();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_STATE) = MAP_STATE_BATTLE_FINISH;
}

