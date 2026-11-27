/* 35 functions from 0x020BF25C to 0x020C0254 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "sound.h"
extern char data_0215e5e4[], gCampaignSaveRecords[];
extern char data_021295c4[], data_021295d0[], data_021295d8[], data_021295dc[], data_021295e4[], data_021295ec[], data_021295f4[], data_021295f8[], data_021295fc[], data_02129604[];
static inline int SaveRangeA(s32 n) { int b=0; if(n>=0xa1) b=(n<0xbb); return b!=0; }
static inline int SaveRangeB(s32 n) { int b=0; if(n>=0xbb) b=(n<0xe1); return b!=0; }
static inline int SaveRangeAU(u32 n) { int b=0; if(n>=0xa1) b=(n<0xbb); return b!=0; }
static inline int SaveRangeBU(u32 n) { int b=0; if(n>=0xbb) b=(n<0xe1); return b!=0; }
typedef struct { u32 state:3; u32 unused:26; u32 rank:3; } SaveRankEntry;
typedef struct { u8 header[8]; SaveRankEntry entries[64]; u8 tail[16]; } SaveRankRecord;
typedef struct { u16 a, b; } SavePair;
typedef struct { u16 id:8; u16 index:4; u16 mode:4; } SaveInitEntry;
typedef struct {
    SaveInitEntry entries[4];
    u32 a:1; u32 b:11; u32 c:1; u32 d:3; u32 e:1;
    u32 f:4; u32 g:7; u32 h:4;
    u32 j:17; u32 k:14; u32 l:1;
} SaveInit;
typedef struct { u8 enabled:1; u8 mode:3; u8 unused:4; } SaveFlags;
typedef struct { u16 low:7; u16 mode:3; u16 high:6; } SaveMode;
extern M2C_UNK gGameSettings, gGameSettingsSaveBuffer, gMovementCostTable;

#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void *BuildSaveSlotText(s32 arg0,s32 arg1) {
s32 GetSaveType(s32); void *GetBattleRecord(s32);
s32 IsUnitAvailable(s32); s32 GetLocalizedText(s32); void StringAppend(char*,const char*); void StringFormat(char*,const char*,...);
s32 func_020a8a84(s32); s32 GetMapName(s32); void FormatDateTime(char*,void*); s32 CampaignSaveSlotInUse(s32); void LoadCampaignMapHeader(s32);
char *buf=data_0215e5e4; s32 n; s32 a=arg0; s32 b=arg1; u16 *p; s32 c1,c2,c3; SaveRankRecord *rec; s32 i;
buf[0x100]=0; n=GetSaveType(a);
p=GetBattleRecord(n);
switch(a) {
case 0: case 5:
if(IsUnitAvailable(n)) {
StringAppend(buf+256,GetLocalizedText(0x4800003f));
if(SaveRangeAU((u32)p[0]))StringAppend(buf+256,GetLocalizedText(0x48000039));
if(SaveRangeBU((u32)p[0]))StringAppend(buf+256,GetLocalizedText(0x4800003a));
n=func_020a8a84(p[0]);StringFormat(buf,data_021295c4,n,GetMapName(p[0]));StringAppend(buf+256,buf);
StringAppend(buf+256,GetLocalizedText(0x4800003f));StringAppend(buf+256,GetLocalizedText(0x4800003e));
StringFormat(buf,data_021295d0,p[1]);StringAppend(buf+256,buf);StringAppend(buf+256,data_021295d8);
StringAppend(buf+256,GetLocalizedText(0x4800003f));FormatDateTime(buf,p);StringAppend(buf+256,buf);
} else if(CampaignSaveSlotInUse(b)) {
rec=(SaveRankRecord *)gCampaignSaveRecords+b;c1=0;c2=0;c3=0;
i=0; goto check_entries;
scan_entry: { if(M2C_FIELD(rec,SaveRankRecord*,i*4).entries[0].state>=3){s32 id=i+0xa1; if(SaveRangeA(id))c1++;if(SaveRangeB(id))c2++;if(M2C_FIELD(rec,SaveRankRecord*,i*4).entries[0].rank==4)c3++;} i++; }
check_entries: if(i<64) goto scan_entry;
if(c1==26)StringAppend(buf+256,GetLocalizedText(0x48000040));else StringAppend(buf+256,GetLocalizedText(0x4800003f));
StringFormat(buf,data_021295dc,GetLocalizedText(0x4800003b),c1);StringAppend(buf+256,buf);
if(c2==38)StringAppend(buf+256,GetLocalizedText(0x48000040));else StringAppend(buf+256,GetLocalizedText(0x4800003f));
StringFormat(buf,data_021295e4,GetLocalizedText(0x4800003c),c2);StringAppend(buf+256,buf);
if(c3==64)StringAppend(buf+256,GetLocalizedText(0x48000040));else StringAppend(buf+256,GetLocalizedText(0x4800003f));
StringFormat(buf,data_021295ec,GetLocalizedText(0x4800003d),c3);StringAppend(buf+256,buf);
StringAppend(buf+256,data_021295f4);StringAppend(buf+256,GetLocalizedText(0x4800003f));FormatDateTime(buf,p);StringAppend(buf+256,buf);
}else if(a==5)StringAppend(buf+256,GetLocalizedText(0x48000041));else StringAppend(buf+256,GetLocalizedText(0x4800002d));
break;
case 1:
if(IsUnitAvailable(n)&&b) {
LoadCampaignMapHeader(p[0]);StringAppend(buf+256,GetLocalizedText(0x4800003f));
StringFormat(buf,data_021295f8,GetMapName(p[0]));StringAppend(buf+256,buf);
StringAppend(buf+256,GetLocalizedText(0x4800003f));StringAppend(buf+256,GetLocalizedText(0x4800003e));
StringFormat(buf,data_021295fc,p[1]);StringAppend(buf+256,buf);StringAppend(buf+256,data_02129604);
StringAppend(buf+256,GetLocalizedText(0x4800003f));FormatDateTime(buf,p);StringAppend(buf+256,buf);
}else StringAppend(buf+256,GetLocalizedText(0x4800002e));
break;
}
return buf+256;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
/* Snapshot the live game settings into the shared snapshot buffer and queue
 * that snapshot as the shared settings save record. */
void SaveGameSettings(void) {
    void SnapshotGameSettings(void *);
    void WriteSaveRecord(s32, void *, s32);
    extern M2C_UNK gGameSettingsSaveBuffer;
    s32 size = SAVE_SETTINGS_RECORD_SIZE;
    SnapshotGameSettings(&gGameSettingsSaveBuffer);
    WriteSaveRecord(SAVE_TYPE_SETTINGS, &gGameSettingsSaveBuffer, size);
}
#pragma opt_propagation reset
/* Load the saved game-settings snapshot, restore its values, and initialise defaults if its magic is invalid. */
M2C_UNK LoadGameSettings(void) {
    void ApplyMusicVolumeSetting(void);
    void ApplySoundEffectVolumeSetting(void);
    s32 LoadNewestSaveRecord(s32, void *);
    void func_020beabc(void *);
    void InitDefaultGameSettings(void);

    if (!LoadNewestSaveRecord(4, &gGameSettingsSaveBuffer)) {
        return;
    }
    func_020beabc(&gGameSettingsSaveBuffer);
    if (M2C_FIELD(&gGameSettings, u32 *, 0x128) != GAME_SETTINGS_MAGIC) {
        InitDefaultGameSettings();
    }
    ApplyMusicVolumeSetting();
    ApplySoundEffectVolumeSetting();
}

/* Unlock every CO whose unlock map (ARMY_DATA_UNLOCK_MAP) is `mapId`, awarding
 * the COs a completed map unlocks. */
void UnlockCosForMap(s32 mapId) {
void SetCoUnlocked(s32,s32);
s32 i;u8 *army=(u8 *)&gMovementCostTable;
i=0;do{if(mapId==M2C_FIELD(army,u16 *,ARMY_DATA_UNLOCK_MAP))SetCoUnlocked(i,1);i++;army+=ARMY_DATA_SIZE;}while(i<CO_COUNT);
}

void func_020bf858(void) {

}

/* Advance the battle turn counter, which saturates at MAP_TURN_MAX (999). */
void AdvanceMapTurn(void) {
    extern void **gCurrentMap;
    u16 turn;
    void *map;

    map = *gCurrentMap;
    turn = M2C_FIELD(map, u16 *, MAP_TURN);
    if ((s32) turn < MAP_TURN_MAX) {
        M2C_FIELD(map, u16 *, MAP_TURN) = (u16) (turn + 1);
    }
}

u32 IsCoUnlocked(s32 a) {
extern M2C_UNK gCoUnlocked;
return (u32)(M2C_FIELD(&gCoUnlocked,u8 *,a)<<31)>>31;
}

/* Set (flag 1) or clear (flag 0) the unlock bit of CO `coId` in the CO roster,
 * leaving the saved-mode bits beside it alone. */
void SetCoUnlocked(s32 coId, s32 flag) {
    extern M2C_UNK gCoUnlocked;
    u32 old = M2C_FIELD(&gCoUnlocked, u8 *, coId);

    flag &= 1;
    M2C_FIELD(&gCoUnlocked, u8 *, coId) = (old & ~1) | flag;
}

/* Return the mode a CO was left in: the 3-bit field beside the CO's unlock bit,
 * 0 for the empty roster entry 0 and for every entry past the roster. */
u32 GetCoSavedMode(s32 coId) {
    extern M2C_UNK gCoUnlocked;

    if (coId == 0 || coId >= CO_COUNT) return 0;
    return ((SaveFlags *)&gCoUnlocked)[coId].mode;
}

/* Store the mode a CO was left in: the 3-bit field beside the CO's unlock bit,
 * skipping the empty roster entry 0 and every entry past the roster. */
void SetCoSavedMode(s32 coId, s32 mode) {
    extern M2C_UNK gCoUnlocked;

    if (coId == 0) return;
    if (coId >= CO_COUNT) return;
    ((SaveFlags *)&gCoUnlocked)[coId].mode = (u8)mode;
}

/* Apply the saved map-view zoom option to `view`: the options word's 3-bit zoom
 * field selects zoom 0 (the zoomed-in value) when it is clear, and otherwise the
 * zoomed-out level GAME_OPTION_ZOOM_OUT. */
void ApplyViewZoomOption(void *view) {
    M2C_UNK SetViewZoomField(void *, s16);
    extern M2C_UNK data_0215d990;
    u32 zoomOption;

    zoomOption = (u32) (M2C_FIELD(&data_0215d990, u16 *, GAME_OPTIONS_WORD) << 0x16) >> 0x1D;
    switch (zoomOption) {                              /* irregular */
    case 0:
        SetViewZoomField(view, 0);
        return;
    case 1:
        SetViewZoomField(view, GAME_OPTION_ZOOM_OUT);
        return;
    default:
        SetViewZoomField(view, GAME_OPTION_ZOOM_OUT);
        return;
    }
}

#pragma opt_common_subs off
/* Saves the map view's zoom into the game-options word: 0 while the view is
 * zoomed in, GAME_OPTION_ZOOM_OUT while it is zoomed out.  The view whose zoom is
 * read arrives as the (otherwise unused) argument of the GetViewZoom call. */
void SaveViewZoomOption(void) {
s32 GetViewZoom(void);extern M2C_UNK data_0215d990;
switch(GetViewZoom()){
case 0:M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)=(M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)&~GAME_OPTION_ZOOM_MASK);return;
case 0x80:M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)=(M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)&~GAME_OPTION_ZOOM_MASK)|GAME_OPTION_ZOOM_OUT;return;
default:M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)=(M2C_FIELD(&data_0215d990,u16 *,GAME_OPTIONS_WORD)&~GAME_OPTION_ZOOM_MASK)|GAME_OPTION_ZOOM_OUT;return;
}
}
#pragma opt_common_subs reset
u8 GetMusicVolumeSetting(void) {
    extern M2C_UNK gGameSettings;
    return M2C_FIELD(&gGameSettings, u8 *, 0x12C);
}

void SetMusicVolumeSetting(s32 a) {
extern M2C_UNK gGameSettings;void ApplyMusicVolumeSetting(void);
M2C_FIELD(&gGameSettings,u8 *,0x12c)=a;
ApplyMusicVolumeSetting();
}

/* Apply the player's music volume setting to the music channel. */
void ApplyMusicVolumeSetting(void) {
    M2C_UNK SetMusicVolumeLevel(M2C_UNK, s32);
    SetMusicVolumeLevel(SOUND_VOLUME_LEVEL_PLAYER, GetMusicVolumeSetting());
}

s32 GetSoundEffectVolumeSetting(void){return M2C_FIELD(&gGameSettings,u8 *,0x12d);}

void SetSoundEffectVolumeSetting(s32 a) {
void ApplySoundEffectVolumeSetting(void);
M2C_FIELD(&gGameSettings,u8 *,0x12d)=a;
ApplySoundEffectVolumeSetting();
}

/* Push the saved sound-effect volume setting to the sound driver. */
void ApplySoundEffectVolumeSetting(void) {
    void SetSoundEffectVolumeLevel(M2C_UNK, s32);
    s32 GetSoundEffectVolumeSetting(void);

    SetSoundEffectVolumeLevel(1, GetSoundEffectVolumeSetting());
}

void *GetBattleRecord(s32 a) {
extern M2C_UNK data_0215d9ec;
return (u8 *)&data_0215d9ec+((a-5)<<3);
}

M2C_UNK *GetMapSettings(void) {
    extern M2C_UNK gMapSettings;
    return &gMapSettings;
}

/* Resets a map-settings record (gMapSettings when none is given) to its defaults:
 * no map, no fog or weather, value limits of 1000, and the four player slots set
 * to the default CO with the player's army; player 1 gets team 1, the rest team 2. */
void MapSettings_SetDefaults(u16 *arg0) {
extern M2C_UNK gDefaultPlayerCoIds;
SaveInit *p=(SaveInit *)arg0;
s32 i;
if(!p) p=(SaveInit *)GetMapSettings();
p->a=0; p->b=0; p->c=0; p->d=0; p->e=0; p->f=0; p->g=0;
p->j=0; p->k=1000; p->h=2; p->l=1;
for(i=0;i<4;i++){
p->entries[i].id=((u8 *)&gDefaultPlayerCoIds)[i+1];
p->entries[i].index=(u16)(i+1);
if(i==0) p->entries[i].mode=1;
else p->entries[i].mode=2;
}
}

/* Copy a map-settings record (gMapSettings when none is given) into the map
 * settings at the start of gGameSettings: the four player slots, the packed rules
 * and the packed value limits. */
void MapSettings_CopyToGameSettings(void *settings) {
    if (!settings) settings = GetMapSettings();
    M2C_FIELD(&gGameSettings, SavePair *, 0) = M2C_FIELD(settings, SavePair *, 0);
    M2C_FIELD(&gGameSettings, SavePair *, 4) = M2C_FIELD(settings, SavePair *, 4);
    M2C_FIELD(&gGameSettings, u32 *, 8) = M2C_FIELD(settings, u32 *, 8);
    M2C_FIELD(&gGameSettings, u32 *, 12) = M2C_FIELD(settings, u32 *, 12);
}

/* Copy the current game settings' 16-byte player setup block (the four player
 * entries and the two option words) into the map settings record, or into
 * gMapSettings when no record is given. */
void MapSettings_CopyFromGameSettings(void *settings) {
    if (!settings) settings = GetMapSettings();
    M2C_FIELD(settings, SavePair *, 0) = M2C_FIELD(&gGameSettings, SavePair *, 0);
    M2C_FIELD(settings, SavePair *, 4) = M2C_FIELD(&gGameSettings, SavePair *, 4);
    M2C_FIELD(settings, u32 *, 8) = M2C_FIELD(&gGameSettings, u32 *, 8);
    M2C_FIELD(settings, u32 *, 12) = M2C_FIELD(&gGameSettings, u32 *, 12);
}

/* Pick a random map id among the maps a random battle may use: count them,
 * choose one of them by its index, then walk the ids again and return the chosen
 * one.  Returns 0 when no map can be picked. */
s32 RandomSelectableMapId(void) {
    s32 NextRandomValue(void);
    s32 MapData_IsRandomSelectable(s32);
    s32 index, count, chosen, mapId;

    count = 0;
    index = 0;
    do { if (MapData_IsRandomSelectable(index)) count++; index++; } while (index < 0x113);
    if (count) {
        chosen = NextRandomValue() % count;
        mapId = 0;
        index = 0;
        do {
            if (MapData_IsRandomSelectable(index)) {
                if (chosen == mapId) return index;
                mapId++;
            }
            index++;
        } while (index < 0x113);
    }
    return 0;
}

/* Roll fog for a randomly generated map: true about 20% of the time (rolls above
 * 80). */
s32 RandomFog(void) {
    s32 NextRandomValue(void);
    return NextRandomValue() % 100 > 80;
}

/* Roll the tileset a randomly generated map starts on: tileset 1 20% of the
 * time, tileset 2 or 3 20% each, otherwise tileset 0. */
s32 RandomTileset(void) {
s32 NextRandomValue(void);
s32 roll=NextRandomValue()%100;
if(roll>80)return 1;if(roll>60)return 2;if(roll>40)return 3;return 0;
}

/* Pick the starting weather for a randomly generated map from its tileset:
 * tileset 1 brings rain, 2 sandstorms and 3 snow 30% of the time, tileset 0
 * brings snow 20% of the time, everything else stays clear. */
s32 WeatherForTileset(u32 tileset) {
s32 NextRandomValue(void);
s32 roll=NextRandomValue()%100;
switch(tileset) {
case 1:if(roll>70)return WEATHER_RAIN;break;
case 2:if(roll>70)return WEATHER_SANDSTORM;break;
case 3:if(roll>70)return WEATHER_SNOW;break;
case 0:if(roll>80)return WEATHER_SNOW;break;
}
return WEATHER_CLEAR;
}

/* Fill a map-settings record for a randomly generated map: a random selectable
 * map id, random fog, tileset and weather, and the chosen map record's battle
 * setting and value limits, packed into the rules and values words. */
void MapSettings_Randomize(void *arg0) {
    s32 MapData_GetBattleSetting(s32);
    s32 MapData_GetValueLimitLow(s32);
    s32 MapData_GetValueLimitHigh(s32);
    void MapSettings_SetDefaults(u16 *);
    s32 RandomSelectableMapId();
    s32 RandomFog();
    s32 RandomTileset();
    s32 WeatherForTileset(u32);
    register unsigned long mapId;
    unsigned word;
    void *settings;

    settings = arg0;
    if (settings == NULL) {
        settings = GetMapSettings();
    }
    MapSettings_SetDefaults(settings);
    mapId = RandomSelectableMapId();
    M2C_FIELD(settings, s32 *, 8) = (s32) ((M2C_FIELD(settings, s32 *, 8) & 0xFFFFF001) | ((u32) (mapId << 0x15) >> 0x14));
    M2C_FIELD(settings, s32 *, 8) = (s32) ((M2C_FIELD(settings, s32 *, 8) & ~0x1000) | ((u32) (RandomFog() << 0x1F) >> 0x13));
    word = (M2C_FIELD(settings, s32 *, 8) & ~0x1E0000) | ((u32) (RandomTileset() << 0x1C) >> 0xB);
    M2C_FIELD(settings, s32 *, 8) = word;
    M2C_FIELD(settings, s32 *, 8) = (s32) (((M2C_FIELD(settings, s32 *, 8) & ~0xE000) | (u16) (WeatherForTileset((u32) (word << 0xB) >> 0x1C) << 0xD)) & ~0x10000);
    word = (M2C_FIELD(settings, s32 *, 8) & ~0x0FE00000) | ((u32) (MapData_GetBattleSetting(mapId) << 0x19) >> 4);
    M2C_FIELD(settings, s32 *, 8) = word;
    M2C_FIELD(settings, s32 *, 8) = (M2C_FIELD(settings, s32 *, 8) & ~0xF0000000) | 0x20000000;
    M2C_FIELD(settings, s32 *, 0xC) = (s32) ((M2C_FIELD(settings, s32 *, 0xC) & ~0x1FFFF) | (MapData_GetValueLimitLow(mapId) & 0x1FFFF));
    word = (M2C_FIELD(settings, s32 *, 0xC) & 0x8001FFFF) | ((u32) (MapData_GetValueLimitHigh(mapId) << 0x12) >> 1);
    M2C_FIELD(settings, s32 *, 0xC) = word;
    M2C_FIELD(settings, s32 *, 0xC) = (M2C_FIELD(settings, s32 *, 0xC) & ~0x80000000) | 0x80000000;
}

/* Capture the current battle map and gMapConfig back into a packed settings
   record: the rules word (map id, fog, weather, tileset, setting and flags) and
   the value-limit word.  The inverse of MapSettings_Apply. */
void MapSettings_Capture(void *p) {
 extern void **gCurrentMap; extern u8 gMapConfig[];
 if(!p)p=GetMapSettings();
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_MAP_ID)|((u32)(M2C_FIELD(*gCurrentMap,u16 *,MAP_ID)<<21)>>20);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_FOG)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,MAP_FOG)<<31)>>19);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_WEATHER)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,MAP_WEATHER_RESET)<<29)>>16);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_WEATHER_MODE)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,MAP_WEATHER_MODE)<<31)>>15);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_TILESET)|((u32)(M2C_FIELD(*gCurrentMap,u8 *,MAP_TILESET)<<28)>>11);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~MAP_SETTINGS_SETTING)|((u32)(gMapConfig[3]<<25)>>4);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~0xF0000000)|(((u32)(M2C_FIELD(gMapConfig,u16 *,0)<<26)>>29)<<28);
((MapSettings *)p)->values=(((MapSettings *)p)->values&~MAP_SETTINGS_VALUE_LOW)|(M2C_FIELD(gMapConfig,u32 *,8)&MAP_SETTINGS_VALUE_LOW);
((MapSettings *)p)->values=(((MapSettings *)p)->values&~MAP_SETTINGS_VALUE_HIGH)|((u32)(M2C_FIELD(gMapConfig,u16 *,6)<<18)>>1);
((MapSettings *)p)->values=(((MapSettings *)p)->values&~MAP_SETTINGS_VALUE_FLAG)|((((u32)(M2C_FIELD(gMapConfig,u16 *,0)<<23)>>31)&1)<<31);
((MapSettings *)p)->rules=(((MapSettings *)p)->rules&~1)|(((u32)(M2C_FIELD(gMapConfig,u16 *,0)<<25)>>31)&1);
}

/* Apply a packed settings record (map id, fog, weather, tileset and the value
 * limits) to the current battle map and to gMapConfig. */
void MapSettings_Apply(void *arg0) {
M2C_UNK *GetMapSettings(void); extern void **gCurrentMap; extern u8 gMapConfig[];
u32 mapId;
if(!arg0)arg0=GetMapSettings();
mapId=(((MapSettings *)arg0)->rules<<20)>>21;
if(mapId) M2C_FIELD(*gCurrentMap,u16*,MAP_ID)=mapId;
M2C_FIELD(*gCurrentMap,u8*,MAP_FOG)=(((MapSettings *)arg0)->rules<<19)>>31;
M2C_FIELD(*gCurrentMap,u8*,MAP_WEATHER)=(((MapSettings *)arg0)->rules<<16)>>29;
M2C_FIELD(*gCurrentMap,u8*,MAP_WEATHER_START)=(((MapSettings *)arg0)->rules<<16)>>29;
M2C_FIELD(*gCurrentMap,u8*,MAP_WEATHER_RESET)=(((MapSettings *)arg0)->rules<<16)>>29;
M2C_FIELD(*gCurrentMap,u8*,MAP_WEATHER_MODE)=(((MapSettings *)arg0)->rules<<15)>>31;
M2C_FIELD(*gCurrentMap,u8*,MAP_TILESET)=(((MapSettings *)arg0)->rules<<11)>>28;
gMapConfig[3]=(((MapSettings *)arg0)->rules<<4)>>25;
M2C_FIELD(gMapConfig,u16*,0)=(M2C_FIELD(gMapConfig,u16*,0)&~0x38)|((u32)((u16)(((MapSettings *)arg0)->rules>>28)<<29)>>26);
M2C_FIELD(gMapConfig,u32*,8)=(u32)((s32)((MapSettings *)arg0)->values<<15)>>15;
M2C_FIELD(gMapConfig,u16*,6)=(((MapSettings *)arg0)->values<<1)>>18;
M2C_FIELD(gMapConfig,u16*,0)=(M2C_FIELD(gMapConfig,u16*,0)&~0x100)|((u32)((u16)(((MapSettings *)arg0)->values>>31)<<31)>>23);
M2C_FIELD(gMapConfig,u16*,0)=(M2C_FIELD(gMapConfig,u16*,0)&~0x40)|((u32)((u16)((u32)((s32)((MapSettings *)arg0)->rules<<31)>>31)<<31)>>25);
}

/* Create a child sprite owned by `owner` for one of the save/load screen's actions;
 * its class (whose callbacks reference SaveGameSettings and IsSaveInProgress)
 * carries the action out. */
void func_020c01bc(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212945c;
    CreateSpriteObject(&data_0212945c, owner);
}

/* Create a child sprite owned by `owner` for one of the save/load screen's actions;
 * its class's callbacks reference LoadGameSettings and IsSaveInProgress, the load
 * counterpart of func_020c01bc's save class. */
void func_020c01d4(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212942c;
    CreateSpriteObject(&data_0212942c, owner);
}

/* Create a child sprite owned by `owner` from one of the save/load feature's data
 * classes; ov003's map-select transition starts it (with the screen object as
 * `owner`) when a new list entry is chosen. */
void func_020c01ec(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02129514;
    CreateSpriteObject(&data_02129514, owner);
}

/* Open the save/load screen from the main menu: halt with the load-failure
 * message when the save archive is unusable, load the saved game settings, count
 * the opening of the screen, then create the screen's sprite. */
void OpenSaveLoadScreen(void) {
    s32 IsSaveArchiveUnusable();
    M2C_UNK HaltWithMessage();
    M2C_UNK GetLocalizedText(s32);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK LoadGameSettings();
    M2C_UNK CreateSaveLoadScreen();

    if (IsSaveArchiveUnusable() != 0) {
        GetLocalizedText(TEXT_ID_SAVE_LOAD_FAILED);
        HaltWithMessage();
    }
    LoadGameSettings();
    AddRecordValue(0x27, 1);
    CreateSaveLoadScreen();
}

/* Spawn the save/load screen "open" sprite, owned by layer `owner`. */
void CreateSaveLoadScreenOpenSprite(M2C_UNK owner) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSaveLoadScreenOpenClass;
    CreateSpriteFromClass(&gSaveLoadScreenOpenClass, owner);
}

