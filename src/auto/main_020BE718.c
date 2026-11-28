/* 10 functions from 0x020BE718 to 0x020BF25C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 pad; u32 year:8, month:6, day:6, hour:6, minute:6; } PackedDate;
static inline u32 dateYear(PackedDate *p) { return p->year; }
static inline u32 dateMonth(PackedDate *p) { return p->month; }
static inline u32 dateDay(PackedDate *p) { return p->day; }
static inline u32 dateHour(PackedDate *p) { return p->hour; }
static inline u32 dateMinute(PackedDate *p) { return p->minute; }

typedef struct { u8 bytes[7]; } SaveBytes7;
typedef struct { u8 bytes[8]; } SaveBytes8;
typedef struct { u8 bytes[15]; } SaveBytes15;
typedef struct { u8 bytes[16]; } SaveBytes16;
typedef struct { u8 bytes[35]; } SaveBytes35;
typedef struct { u16 halfwords[7]; } SaveHalfwords14;
typedef struct { u32 words[3]; } SaveWords12;
typedef struct { u32 words[4]; } SaveWords16;
typedef struct { u32 words[8]; } SaveWords32;
typedef struct { u32 words[64]; } SaveWords256;
typedef struct { u32 words[94]; } SaveWords376;

typedef struct SaveRecordBlock {
    u32 header[2];
    SaveWords256 payload;
    SaveBytes8 metadata;
    SaveBytes8 stamp;
} SaveRecordBlock;

typedef struct SaveSettingsSnapshot {
    SaveBytes8 listHeader;
    SaveBytes16 listSelection;
    SaveBytes8 listState;
    SaveBytes8 listRowFlags;
    SaveBytes35 listData[3];
    SaveBytes7 listFooter;
    u32 settingsWord;
    u8 settingsByte0;
    u8 settingsByte1;
    u16 settingsHalfword;
    SaveHalfwords14 settingsGroup0;
    u8 padAE[2];
    SaveWords16 settingsGroup1;
    SaveWords12 settingsGroup2;
    SaveWords32 settingsGroup3;
    SaveWords16 mapSettings;
    SaveBytes15 coUnlocked;
    u8 pad10B;
    SaveWords376 recordValues;
    SaveRecordBlock records[3];
} SaveSettingsSnapshot;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void SnapshotGameSettings(SaveSettingsSnapshot *save) {
    extern M2C_UNK gGameSettings, data_0215d990, data_0215d9c0;
    extern M2C_UNK data_0215d9d0, data_0215d9e0, gBattleSaveRecords;
    extern M2C_UNK gMapSettings, gCoUnlocked, gRecordValues, gCampaignSaveRecords;
    extern M2C_UNK gEventFlagsMid, gSeenMapBackgroundFlags, gRecordsMusicHeard, gListRowFlags;
    extern M2C_UNK gMapListFlags, gCampaignMapPlayed, gCampaignMapCleared, gCampaignMapSaved;
    SaveRecordBlock *records = (SaveRecordBlock *)&gCampaignSaveRecords;
    s32 i;

    save->settingsWord = M2C_FIELD(&gGameSettings, u32 *, 0x128);
    save->settingsByte0 = M2C_FIELD(&gGameSettings, u8 *, 0x12c);
    save->settingsByte1 = M2C_FIELD(&gGameSettings, u8 *, 0x12d);
    save->settingsHalfword = M2C_FIELD(&data_0215d990, u16 *, 0x2e);
    save->settingsGroup0 = *(SaveHalfwords14 *)&data_0215d9c0;
    save->settingsGroup1 = *(SaveWords16 *)&data_0215d9d0;
    save->settingsGroup2 = *(SaveWords12 *)&data_0215d9e0;
    save->settingsGroup3 = *(SaveWords32 *)&gBattleSaveRecords;
    save->mapSettings = *(SaveWords16 *)&gMapSettings;
    save->coUnlocked = *(SaveBytes15 *)&gCoUnlocked;
    save->recordValues = *(SaveWords376 *)&gRecordValues;
    for (i = 0; i < 3; i++) {
        save->records[i].header[0] = records[i].header[0];
        save->records[i].header[1] = records[i].header[1];
        save->records[i].payload = records[i].payload;
        save->records[i].metadata = records[i].metadata;
        save->records[i].stamp = records[i].stamp;
    }
    save->listHeader = *(SaveBytes8 *)&gEventFlagsMid;
    save->listSelection = *(SaveBytes16 *)&gSeenMapBackgroundFlags;
    save->listState = *(SaveBytes8 *)&gRecordsMusicHeard;
    save->listRowFlags = *(SaveBytes8 *)&gListRowFlags;
    save->listData[0] = *(SaveBytes35 *)&gMapListFlags;
    save->listData[1] = *(SaveBytes35 *)&gCampaignMapPlayed;
    save->listData[2] = *(SaveBytes35 *)&gCampaignMapCleared;
    save->listFooter = *(SaveBytes7 *)&gCampaignMapSaved;
}
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma scheduling off
void func_020e4b24(void);
#pragma opt_strength_reduction off
#pragma scheduling on
#pragma opt_common_subs off
#pragma opt_loop_invariants off
void func_020beabc(SaveSettingsSnapshot *save) {
    extern M2C_UNK gGameSettings, data_0215d990, data_0215d9c0;
    extern M2C_UNK data_0215d9d0, data_0215d9e0, gBattleSaveRecords;
    extern M2C_UNK gMapSettings, gCoUnlocked, gRecordValues, gCampaignSaveRecords;
    extern M2C_UNK gEventFlagsMid, gSeenMapBackgroundFlags, gRecordsMusicHeard, gListRowFlags;
    extern M2C_UNK gMapListFlags, gCampaignMapPlayed, gCampaignMapCleared, gCampaignMapSaved;
    s32 i;

    M2C_FIELD(&gGameSettings, u32 *, 0x128) = save->settingsWord;
    M2C_FIELD(&gGameSettings, u8 *, 0x12c) = save->settingsByte0;
    M2C_FIELD(&gGameSettings, u8 *, 0x12d) = save->settingsByte1;
    M2C_FIELD(&data_0215d990, u16 *, 0x2e) = save->settingsHalfword;
    *(SaveHalfwords14 *)&data_0215d9c0 = save->settingsGroup0;
    *(SaveWords16 *)&data_0215d9d0 = save->settingsGroup1;
    *(SaveWords12 *)&data_0215d9e0 = save->settingsGroup2;
    *(SaveWords32 *)&gBattleSaveRecords = save->settingsGroup3;
    *(SaveWords16 *)&gMapSettings = save->mapSettings;
    *(SaveBytes15 *)&gCoUnlocked = save->coUnlocked;
    *(SaveWords376 *)&gRecordValues = save->recordValues;
    for (i = 0; i < 3; i++) {
        ((SaveRecordBlock *)&gCampaignSaveRecords)[i].header[0] = save->records[i].header[0];
        ((SaveRecordBlock *)&gCampaignSaveRecords)[i].header[1] = save->records[i].header[1];
        ((SaveRecordBlock *)&gCampaignSaveRecords)[i].payload = save->records[i].payload;
        ((SaveRecordBlock *)&gCampaignSaveRecords)[i].metadata = save->records[i].metadata;
        ((SaveRecordBlock *)&gCampaignSaveRecords)[i].stamp = save->records[i].stamp;
    }
    *(SaveBytes8 *)&gEventFlagsMid = save->listHeader;
    *(SaveBytes16 *)&gSeenMapBackgroundFlags = save->listSelection;
    *(SaveBytes8 *)&gRecordsMusicHeard = save->listState;
    *(SaveBytes8 *)&gListRowFlags = save->listRowFlags;
    *(SaveBytes35 *)&gMapListFlags = save->listData[0];
    *(SaveBytes35 *)&gCampaignMapPlayed = save->listData[1];
    *(SaveBytes35 *)&gCampaignMapCleared = save->listData[2];
    *(SaveBytes7 *)&gCampaignMapSaved = save->listFooter;
    func_020e4b24();
}
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
/* Whether a save record of type `saveType` is available: the battle record for
 * that type must first have been stamped with a non-zero day count, and the save
 * record itself must exist. */
s32 IsUnitAvailable(s32 saveType) {
    s32 SaveRecordExistsForType(s32);
    void *GetBattleRecord();
    if (M2C_FIELD(GetBattleRecord(), u16 *, BATTLE_RECORD_DAYS) == 0) {
        return 0;
    }
    return SaveRecordExistsForType(saveType);
}

/* Record the battle that just ended in its save slot: the map it was fought on,
 * the number of days it lasted, and the current local date and time packed as
 * year:8 month:6 day:6 hour:6 minute:6 into the record's date word.  The slot is
 * the caller's r0, which GetBattleRecord passes on to pick the record. */
void StampBattleRecord(void) {
    extern void **gCurrentMap;
    M2C_UNK GetRtcDateTime(s32 *, s32 *);
    void *GetBattleRecord();
    s32 date[4];
    s32 time[3];
    void *record;
    record = GetBattleRecord();
    GetRtcDateTime(date, time);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFF) | (u8)date[0];
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0x3F00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFC000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0x3F00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFC000000) | (time[1] << 26);

    M2C_FIELD(record, u16 *, BATTLE_RECORD_MAP) = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
    M2C_FIELD(record, u16 *, BATTLE_RECORD_DAYS) = M2C_FIELD(*gCurrentMap, u16 *, 0x52A2);
}

/* Start a fresh battle record: stamp it with the current local date and time and
 * clear the map id and the day count; both are filled in when the battle ends
 * (see StampBattleRecord). */
void StartBattleRecord(void) {
    M2C_UNK GetRtcDateTime(s32 *, s32 *);
    void *GetBattleRecord();
    s32 date[4];
    s32 time[3];
    void *record;

    record = GetBattleRecord();
    GetRtcDateTime(date, time);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFF) | (u8)date[0];
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0x3F00) | ((u32)(date[1] << 26) >> 18);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFC000) | ((u32)(date[2] << 26) >> 12);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0x3F00000) | ((u32)(time[0] << 26) >> 6);
    M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) = (M2C_FIELD(record, u32 *, BATTLE_RECORD_DATE) & ~0xFC000000) | (time[1] << 26);

    M2C_FIELD(record, u16 *, BATTLE_RECORD_MAP) = 0;
    M2C_FIELD(record, u16 *, BATTLE_RECORD_DAYS) = 0;
}

/* GetCurrentSaveType: the save-record type of the battle in progress, used to
 * store its result.  A link session is never saved (0).  A campaign battle uses
 * record 5 + its save slot (the low four bits of the game settings word at
 * +0x10), while a versus battle uses the single record 8, which has no slot.
 * Menu and other non-battle modes save nothing. */
s32 GetCurrentSaveType(void) {
    s32 IsLinkSessionActive();
    s32 GetSaveType(s32, s32);
    extern M2C_UNK gGameSettings;
    extern u16 gMapConfig;
    s32 saveType;
    u32 mapMode;

    saveType = 0;
    if (IsLinkSessionActive() != 0) {
        return 0;
    }
    mapMode = (u32) (gMapConfig << 0x1D) >> 0x1D;
    switch ((u8) mapMode) {                         /* irregular */
    case 0:
        saveType = GetSaveType(0, (u32) (M2C_FIELD(&gGameSettings, s32 *, 0x10) << 0x1C) >> 0x1C);
        break;
    case 1:
        saveType = GetSaveType(1, 0U);
        break;
    }
    return saveType;
}

/* Save-record type of a battle for save kind `kind` and campaign save slot
 * `slot`: kinds 0 and 5 are campaign battles (record SAVE_RECORD_TYPE_CAMPAIGN +
 * slot), kind 1 the versus battle (its single SAVE_RECORD_TYPE_VERSUS record),
 * and every other kind saves nothing (0). */
s32 GetSaveType(s32 kind, s32 slot) {
    switch (kind) {                                 /* irregular */
    case 0:
    case 5:
        return slot + SAVE_RECORD_TYPE_CAMPAIGN;
    case 1:
        return SAVE_RECORD_TYPE_VERSUS;
    default:
        return 0;
    }
}

/* Whether a battle-save record type keeps no save slot of its own: only the
 * versus battle's single SAVE_RECORD_TYPE_VERSUS record, so the caller must not
 * look up a slot for it. */
s32 SaveTypeHasNoSlot(s32 saveType) {
    switch (saveType) {
    case SAVE_RECORD_TYPE_CAMPAIGN + 0: return 0;
    case SAVE_RECORD_TYPE_CAMPAIGN + 1: return 0;
    case SAVE_RECORD_TYPE_CAMPAIGN + 2: return 0;
    case SAVE_RECORD_TYPE_VERSUS: return 1;
    default: return 0;
    }
}

/* Save slot of a battle for save kind `kind` and battle-save record type
 * `saveType`, the inverse of GetSaveType: the campaign records (kinds 0 and 5)
 * sit at SAVE_RECORD_TYPE_CAMPAIGN + slot, the versus record (kind 1) is slot 0,
 * and any other kind saves nothing. */
s32 GetSaveSlot(s32 kind, s32 saveType) {
    switch (kind) {
    case 0:
    case 5:
        return saveType - SAVE_RECORD_TYPE_CAMPAIGN;
    case 1:
        return 0;
    default:
        return 0;
    }
}

/* Writes a save record's packed date/time (the bit-packed word at +4) into
 * `out`, using the date order of the console's language: year/month/day
 * (Japanese), month/day/year (American) or day/month/year (European). */
void FormatDateTime(s8 *out, void *date) {
    M2C_UNK StringFormat();
    u32 GetLanguage();
    extern u8 gDateTimeFormatYMD[], gDateTimeFormatMDY[], gDateTimeFormatDMY[];

    switch (GetLanguage()) {
    case 0:
        StringFormat(out, gDateTimeFormatYMD, dateYear(date), dateMonth(date), dateDay(date), dateHour(date), dateMinute(date));
        return;
    case 1:
        StringFormat(out, gDateTimeFormatMDY, dateMonth(date), dateDay(date), dateYear(date), dateHour(date), dateMinute(date));
        return;
    case 2:
    case 3:
    case 4:
    case 5:
        StringFormat(out, gDateTimeFormatDMY, dateDay(date), dateMonth(date), dateYear(date), dateHour(date), dateMinute(date));
        return;
    default:
        *out = 0;
        return;
    }
}

