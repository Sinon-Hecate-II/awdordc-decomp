/* 57 functions from 0x02086208 to 0x020871A8 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct { s32 x,y,z; } Vec02086dfc;
extern const Vec02086dfc gSpriteSceneCameraEye, gSpriteSceneCameraUp;
extern void (*data_02168fe8)(void);
extern u8 gEventFlagsLow[4];

/* Push-to-talk voice-chat widget (same fields as the definition in main_020852F4). */
typedef struct VoiceChatWidget {
    u8  filler_00[0x34];
    s16 x;               /* +0x34 */
    s16 y;               /* +0x36 */
    s32 enabled;         /* +0x38 nonzero while the widget is shown */
    s32 initialized;     /* +0x3C set on the first update */
    s32 lastVoice;       /* +0x40 last voice-data-ready value seen */
    u8  filler_44[4];
    s32 talkHeld;        /* +0x48 Y button was held last update */
    u8  mainScreen;      /* +0x4C nonzero while the widget is drawn on the main engine (func_02085ebc) */
    u8  unk_4D;          /* +0x4D cleared whenever mainScreen is set */
    /* +0x4E */
    s16 refreshTimer;    /* +0x4E cooldown before the fade may be re-targeted */
    SpriteTween *anim;   /* +0x50 volume fade */
} VoiceChatWidget;

/* Create the push-to-talk voice-chat widget on the sub engine while the ov010
 * overlay is active: place it, enable it from the local player's status and set
 * up its volume fade in the neutral (127) position. */
void CreateVoiceChatWidget(s32 mode){
void *FindObjectByClass(M2C_UNK *);s16 Divide(s32,s32);s32 CreateSpriteFromClass(M2C_UNK *,s32);void *GetLocalPlayerStatus(void);void *MemAlloc(s32);
extern M2C_UNK gVoiceChatWidgetClass,gVoiceChatWidgetVtbl;extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub;
s32 saved;VoiceChatWidget *p;SpriteTween *q;
if(GetActiveOverlay()!=2)return;
if(FindObjectByClass(&gVoiceChatWidgetClass))return;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
p=(VoiceChatWidget *)CreateSpriteFromClass(&gVoiceChatWidgetClass,mode);
if(p){
M2C_FIELD(p,void **,0)=&gVoiceChatWidgetVtbl;
p->x=0xde;p->y=1;
p->enabled=M2C_FIELD(GetLocalPlayerStatus(),u8 *,0x1a)&4;
p->initialized=0;p->lastVoice=0;M2C_FIELD(p,s32 *,0x44)=0;p->talkHeld=0;
M2C_FIELD(p,u8 *,0x4c)=0;M2C_FIELD(p,u8 *,0x4d)=0;
p->refreshTimer=Divide(0x2bf20,1000);
q=(SpriteTween *)MemAlloc(18);
if(q){
q->mode=1;q->done=0;
q->current=0;q->start=0;q->step=1;q->base=0;q->amplitude=1;q->duration=1;q->from=0;q->to=0;
M2C_FIELD(q,u16 *,2)=M2C_FIELD(q,volatile u16 *,4);
}
p->anim=q;
q->from=127;q->to=127;q->duration=0;q->current=q->start;
}
gCur3DSpriteEngine=saved;
}

void DeleteVoiceChatWidgets(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    DeleteSpriteObjectsOfClass(&gVoiceChatWidgetClass);
}

void func_02086344(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xEF;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 0x12;
}

void func_02086370(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xDE;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 1;
}

/* Switch the push-to-talk voice-chat widget to the main engine (it is created on
 * the sub engine) and load the scene panel graphics it draws with there. */
void ShowVoiceChatWidgetOnMainScreen(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK LoadScenePanelGraphicsOnBothEngines(void *);
    extern M2C_UNK gVoiceChatWidgetClass;
    VoiceChatWidget *widget;

    widget = FindObjectByClass(&gVoiceChatWidgetClass);
    if (widget == 0) {
        return;
    }
    widget->mainScreen = 1;
    widget->unk_4D = 0;
    LoadScenePanelGraphicsOnBothEngines(widget);
}

void func_020863cc(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gVoiceChatWidgetClass;
    void *temp_r0;
    temp_r0 = FindObjectByClass(&gVoiceChatWidgetClass);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, s8 *, 0x4D) = 0;
    }
}

/* Restart the voice-chat widget's Y-press cooldown (3 seconds, 180 frames) when
 * the display wakes: the widget then ignores a Y button that is still held from
 * before the sleep until the player presses it again. */
void RestartVoiceChatCooldown(void) {
    void *FindObjectByClass(M2C_UNK *);
    s16 Divide(s32, s32);
    extern M2C_UNK gVoiceChatWidgetClass;
    VoiceChatWidget *widget;

    widget = (VoiceChatWidget *)FindObjectByClass(&gVoiceChatWidgetClass);
    if (widget == NULL) {
        return;
    }
    widget->refreshTimer = Divide(0x2BF20, 1000);
}

/* Whether an online player has voice chat available: the online overlay must be
 * up, and the player's record must exist with voice chat enabled. */
s32 IsOnlinePlayerVoiceChatEnabled(s32 playerId) {
    s32 GetActiveOverlay();
    void *GetOnlinePlayerRecord(M2C_UNK);
    void *record;

    if (GetActiveOverlay() == 2) {
        record = GetOnlinePlayerRecord(playerId);
        if (record != NULL && M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 3) == 1 &&
            M2C_FIELD(record, s8 *, ONLINE_PLAYER_SLOT_STATE + 4) == 0) {
            if (M2C_FIELD(record, u8 *, ONLINE_PLAYER_FLAGS) & ONLINE_PLAYER_FLAG_VOICE) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

/* Delete the voice-chat widget: free its volume-fade animation, restore the
 * music and sound-effect channel 2 volumes to their default, and free the
 * object itself. */
void *DeleteVoiceChatWidget(VoiceChatWidget *widget) {
    M2C_UNK MemFree();
    M2C_UNK SetMusicVolumeLevel(M2C_UNK, M2C_UNK);
    M2C_UNK SetSoundEffectVolumeLevel(M2C_UNK, M2C_UNK);
    extern M2C_UNK gVoiceChatWidgetVtbl;
    M2C_FIELD(widget, M2C_UNK **, 0) = &gVoiceChatWidgetVtbl;
    if (widget->anim != 0) {
        MemFree(widget->anim);
    }
    SetMusicVolumeLevel(2, 0x7F);
    SetSoundEffectVolumeLevel(2, 0x7F);
    MemFree(widget);
    return widget;
}

/* Release the voice-chat widget's resources without freeing the object itself:
 * reset its vtable, free its volume-fade animation and restore the music and
 * sound-effect channel 2 volumes. */
void *DestroyVoiceChatWidget(VoiceChatWidget *widget) {
    M2C_UNK MemFree();
    M2C_UNK SetMusicVolumeLevel(M2C_UNK, M2C_UNK);
    M2C_UNK SetSoundEffectVolumeLevel(M2C_UNK, M2C_UNK);
    extern M2C_UNK gVoiceChatWidgetVtbl;
    M2C_FIELD(widget, M2C_UNK **, 0) = &gVoiceChatWidgetVtbl;
    if (widget->anim != 0) {
        MemFree(widget->anim);
    }
    SetMusicVolumeLevel(2, 0x7F);
    SetSoundEffectVolumeLevel(2, 0x7F);
    return widget;
}

void Init3DSpriteScene(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102210;
    CreateSpriteFromClass(&data_02102210, 7);
}

/* Whether text bank `bank` is one of the banks the boot UI keeps loaded for
 * the whole game (the shared system and menu strings, banks 0..3, 6, 8, 9 and
 * the last slot 39).  The other banks belong to one screen, which loads and
 * frees them itself, so a language change only reloads these. */
s32 IsUiGraphicsBankInUse(s32 bank) {
    switch (bank) {                                 /* irregular */
    case 39:
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}

void func_02086574(void) {
    void ReloadUiGraphicsBanks(void);
    extern M2C_UNK gUiGraphicsBanks[];
    s32 i;
    i = 0;
    do {
        gUiGraphicsBanks[i] = 0;
        i = i + 1;
    } while (i < 0x28);
    ReloadUiGraphicsBanks();
}

/* Reload the localized UI text banks after a language change: free each bank
   that is in use and still loaded, then load every in-use bank again. */
void ReloadUiGraphicsBanks(void) {
    void LoadUiGraphicsBank(u8);
    void FreeUiGraphicsBank(u8);
    extern M2C_UNK gUiGraphicsBanks[];
    s32 unloadBank;
    s32 loadBank;

    unloadBank = 0;
    do {
        if ((IsUiGraphicsBankInUse((u8)unloadBank) != 0) && (((s32 *)&gUiGraphicsBanks)[unloadBank] != 0)) {
            FreeUiGraphicsBank((u8)unloadBank);
        }
        unloadBank += 1;
    } while (unloadBank < TEXT_BANK_COUNT);
    loadBank = 0;
    do {
        if (IsUiGraphicsBankInUse((u8)loadBank) != 0) {
            LoadUiGraphicsBank((u8)loadBank);
        }
        loadBank += 1;
    } while (loadBank < TEXT_BANK_COUNT);
}

/* Load localized text bank `bank`: build its file path from the bank's base file
 * name and the current language, decompress it and keep the loaded bank in
 * gUiGraphicsBanks. */
void LoadUiGraphicsBank(u8 bank) {
 s32 GetLocalizedFileName(s32);
 void StringFormat(void *, void *, s32);
 s32 LoadDecompressedFile(void *, s32);
 extern M2C_UNK gTextBankFileNames, gMessageBankPathFormat, gUiGraphicsBanks[];
 u8 path[0x20];
 StringFormat(path, &gMessageBankPathFormat, GetLocalizedFileName(M2C_FIELD(&gTextBankFileNames, s32 *, bank * 8)));
 ((s32 *)&gUiGraphicsBanks)[bank] = LoadDecompressedFile(path, 1);
}

void FreeUiGraphicsBank(u8 arg0) {
 void HeapFreeBlock(s32);
 extern M2C_UNK gUiGraphicsBanks[];
 HeapFreeBlock(((s32 *)&gUiGraphicsBanks)[arg0]);
 ((s32 *)&gUiGraphicsBanks)[arg0] = 0;
}

/* GetLocalizedText: look up a UI string by its text id (-1 asks for the id of
 * the current message).  The bank table is walked in order and the first bank
 * whose first text id is not above the wanted id holds the string; the id's low
 * 24 bits index that bank's offset table, and the offset is added to the bank's
 * base in memory.  An id that no bank claims returns 0. */
s32 GetLocalizedText(u32 textId) {
 extern u32 gTextBankTable;
 extern M2C_UNK gUiGraphicsBanks[];
 u32 *entry = &gTextBankTable;
 if (textId == -1U) textId = GetUiMessageText();
 for (; entry[1] != 0; entry += 2) {
  if (textId >= entry[0]) {
   s32 bank = ((s32 *)&gUiGraphicsBanks)[((s32)entry - (s32)&gTextBankTable) / 8];
   return bank + ((s32 *)bank)[textId & TEXT_BANK_INDEX_MASK];
  }
 }
 return 0;
}

s32 IsMessageTextIdValid(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == -1) {
        var_r0 = GetUiMessageText();
    }
    if (var_r0 == 0) {
        return 0;
    }
    return 1;
}

void SetUiMessageText(s32 arg0) {
    extern s32 gUiMessageText;
    gUiMessageText = arg0;
}

s32 GetUiMessageText(void) {
    extern s32 gUiMessageText;
    return gUiMessageText;
}

/* Set (value nonzero) or clear bit `flagId` of the middle event-flag bank: one of
 * the 64 flags in gEventFlagsMid, at bit flagId&7 of byte flagId>>3. */
void SetEventFlagMid(u32 flagId, s32 value) {
    extern M2C_UNK gEventFlagsMid;
    s32 shift = flagId & 7;
    s32 mask = 1 << shift;
    u8 byte = M2C_FIELD(&gEventFlagsMid, u8 *, flagId >> 3);
    M2C_FIELD(&gEventFlagsMid, u8 *, flagId >> 3) = (byte & ~mask) | (mask * value);
}

/* Mark the background of map `mapId` as seen (seen nonzero) or unseen, as bit
 * mapId&7 of byte mapId>>3 in the game's seen-background bitmap. */
void SetMapBackgroundSeenFlag(u32 mapId, s32 seen) {
    extern M2C_UNK gSeenMapBackgroundFlags;
    s32 shift = mapId & 7;
    M2C_FIELD(&gSeenMapBackgroundFlags, u8 *, mapId >> 3) = (M2C_FIELD(&gSeenMapBackgroundFlags, u8 *, mapId >> 3) & ~(1 << shift)) | ((1 << shift) * seen);
}

/* Set (value nonzero) or clear bit `entry` of the records screen's "music entry
 * heard" flags: one of the 0x40 bits in gRecordsMusicHeard. */
void SetRecordsMusicHeard(u32 entry, s32 value) {
 extern M2C_UNK gRecordsMusicHeard;
 s32 shift = entry & 7;
 M2C_FIELD(&gRecordsMusicHeard, u8 *, entry >> 3) = (M2C_FIELD(&gRecordsMusicHeard, u8 *, entry >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Mark list row `rowId` as flagged (value nonzero) or clear it, as bit rowId&7 of
 * byte rowId>>3 in the list-row flag bitmap. */
void SetListRowFlag(u32 rowId, s32 value) {
    extern M2C_UNK gListRowFlags;
    s32 shift = rowId & 7;
    M2C_FIELD(&gListRowFlags, u8 *, rowId >> 3) = (M2C_FIELD(&gListRowFlags, u8 *, rowId >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Set (value nonzero) or clear bit `flagId` of the map-list flag bitmap: one bit
 * per map list entry, at bit flagId&7 of byte flagId>>3 of gMapListFlags. */
void SetMapListFlag(u32 flagId, s32 value) {
 extern M2C_UNK gMapListFlags;
 s32 shift = flagId & 7;
 M2C_FIELD(&gMapListFlags, u8 *, flagId >> 3) = (M2C_FIELD(&gMapListFlags, u8 *, flagId >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Mark campaign map `mapId` as played (value nonzero) or clear it, as bit mapId&7
 * of byte mapId>>3 in the played-campaign-map bitmap. */
void SetCampaignMapPlayed(u32 mapId, s32 value) {
    extern M2C_UNK gCampaignMapPlayed;
    s32 shift = mapId & 7;
    M2C_FIELD(&gCampaignMapPlayed, u8 *, mapId >> 3) = (M2C_FIELD(&gCampaignMapPlayed, u8 *, mapId >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Set (value nonzero) or clear bit `mapId` of the campaign-map-cleared bitmap:
 * one bit per campaign map, at bit mapId&7 of byte mapId>>3 of gCampaignMapCleared. */
void SetCampaignMapCleared(u32 mapId, s32 value) {
 extern M2C_UNK gCampaignMapCleared;
 s32 shift = mapId & 7;
 M2C_FIELD(&gCampaignMapCleared, u8 *, mapId >> 3) = (M2C_FIELD(&gCampaignMapCleared, u8 *, mapId >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Mark campaign map `mapId` as saved (value nonzero) or clear it, as bit mapId&7
 * of byte mapId>>3 in the saved-campaign-map bitmap gCampaignMapSaved. */
void SetCampaignMapSaved(u32 mapId, s32 value) {
    extern M2C_UNK gCampaignMapSaved;
    s32 shift = mapId & 7;
    M2C_FIELD(&gCampaignMapSaved, u8 *, mapId >> 3) = (M2C_FIELD(&gCampaignMapSaved, u8 *, mapId >> 3) & ~(1 << shift)) | ((1 << shift) * value);
}

/* Set (value nonzero) or clear bit `flagId` of the high event-flag bank: one of
 * the 64 flags in gEventFlagsHigh, at bit flagId&7 of byte flagId>>3. */
void SetEventFlagHigh(u32 flagId, s32 value) {
    extern M2C_UNK gEventFlagsHigh;
    s32 shift;
    s32 mask;
    if (value != 0) {
        shift = flagId & 7;
        mask = 1 << shift;
        M2C_FIELD(&gEventFlagsHigh, u8 *, flagId >> 3) |= mask;
    } else {
        shift = flagId & 7;
        mask = -1 ^ (1 << shift);
        M2C_FIELD(&gEventFlagsHigh, u8 *, flagId >> 3) &= mask;
    }
}

void func_02086930(s32 arg0, s8 arg1) {
    extern M2C_UNK gEventValues;
    M2C_FIELD(&gEventValues, s8 *, arg0) = arg1;
}

u8 IsMapListFlagSet(u32 arg0) {
    extern M2C_UNK gMapListFlags;
    return (u8) (M2C_FIELD(&gMapListFlags, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsCampaignMapCleared(u32 arg0) {
    extern M2C_UNK gCampaignMapCleared;
    return (u8) (M2C_FIELD(&gCampaignMapCleared, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsCampaignMapSaved(u32 arg0) {
    extern M2C_UNK gCampaignMapSaved;
    return (u8) (M2C_FIELD(&gCampaignMapSaved, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

s32 IsEventFlagHighSet(s32 arg0) {
    extern M2C_UNK gEventFlagsHigh;
    return (u8)(M2C_FIELD(&gEventFlagsHigh,u8 *, (u32)arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsMapBackgroundSeenFlagSet(u32 arg0) {
    extern M2C_UNK gSeenMapBackgroundFlags;
    return (u8) (M2C_FIELD(&gSeenMapBackgroundFlags, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_020869e0(u32 arg0) {
    extern M2C_UNK gRecordsMusicHeard;
    return (u8) (M2C_FIELD(&gRecordsMusicHeard, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 IsListRowFlagSet(u32 arg0) {
    extern M2C_UNK gListRowFlags;
    return (u8) (M2C_FIELD(&gListRowFlags, u8 *, arg0 >> 3) & (1 << (arg0 & 7)));
}

u8 func_02086a20(s32 arg0) {
    extern M2C_UNK gEventValues;
    return M2C_FIELD(&gEventValues, u8 *, arg0);
}

s32 IsEventFlagMidSet(s32 arg0) {
    extern M2C_UNK gEventFlagsMid;
    s32 shift = arg0 & 7;
    u8 value = M2C_FIELD(&gEventFlagsMid,u8 *, (u32)arg0 >> 3);
    return (u8)(value & (1 << shift));
}

/* Set (value nonzero) or clear bit `flagId` of the low event-flag bank: one of
 * the 32 flags in gEventFlagsLow, at bit flagId&7 of byte flagId>>3. */
void SetEventFlagLow(s32 flagId, s32 value) {
    s32 shift;
    s32 mask;
    if (value) {
        shift = flagId & 7;
        mask = 1 << shift;
        gEventFlagsLow[flagId >> 3] |= mask;
    } else {
        shift = flagId & 7;
        mask = -1 ^ (1 << shift);
        gEventFlagsLow[flagId >> 3] &= mask;
    }
}

s32 IsEventFlagLowSet(s32 arg0) {
 s32 shift=arg0&7;u8 value=gEventFlagsLow[arg0>>3];return (u8)(value&(1<<shift));
}

void ClearEventFlagsLow(void) {
 s32 i=0;u8 *p=gEventFlagsLow;u8 zero=i;
 do{i++;*p++=zero;}while(i<4);
}

/* Set event flag `flag` to `value` in whichever of the three event-flag blocks owns
 * its id (low, mid or high); ids outside 0..0x9F are ignored. */
M2C_UNK SetEventFlag(s32 flag,s32 value) {
 if(flag>=EVENT_FLAG_LOW_BASE&&flag<EVENT_FLAG_MID_BASE){SetEventFlagLow(flag,value);return;}
 if(flag>=EVENT_FLAG_MID_BASE&&flag<EVENT_FLAG_HIGH_BASE){SetEventFlagMid(flag-EVENT_FLAG_MID_BASE,(u8)value);return;}
 if(flag<EVENT_FLAG_HIGH_BASE)return;
 if(flag>=EVENT_FLAG_COUNT)return;
 SetEventFlagHigh(flag-EVENT_FLAG_HIGH_BASE,(u8)value);
}

/* Return whether event flag `flag` is set: flag ids 0x00-0x1F live in the low
 * block, 0x20-0x5F in the mid block and 0x60-0x9F in the high block, so route to
 * the matching getter; ids outside 0x00-0x9F are never set. */
s32 IsEventFlagSet(s32 flag) {
    s32 IsEventFlagHighSet(s32);
    s32 IsEventFlagMidSet(s32);
    s32 IsEventFlagLowSet();
    if ((flag >= 0) && (flag < 0x20)) {
        return IsEventFlagLowSet();
    }
    if ((flag >= 0x20) && (flag < 0x60)) {
        return IsEventFlagMidSet(flag - 0x20);
    }
    if ((flag >= 0x60) && (flag < 0xA0)) {
        return IsEventFlagHighSet(flag - 0x60);
    }
    return 0;
}

/* Initializes/clears the bitfield/flag tables used by the main overlay. */
void func_02086b9c(void) {
    M2C_UNK SetEventFlag(s32, M2C_UNK);
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r6;
    s32 var_r6_2;
    s32 var_r7;

    var_r7 = 0;
    do {
        if ((var_r7 >= 0xA1) && (var_r7 < 0xE1)) {
            SetMapListFlag(var_r7, 0);
        } else {
            SetMapListFlag(var_r7, 1);
        }
        var_r7 += 1;
    } while (var_r7 < 0x113);
    var_r6 = 0;
    do {
        SetCampaignMapPlayed(var_r6, 0);
        var_r6 += 1;
    } while (var_r6 < 0x113);
    var_r6_2 = 0;
    do {
        SetCampaignMapCleared(var_r6_2, 0);
        var_r6_2 += 1;
    } while (var_r6_2 < 0x113);
    var_r5 = 0;
    do {
        SetCampaignMapSaved(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x32);
    var_r5_2 = 0x20;
    do {
        SetEventFlag(var_r5_2, 0);
        var_r5_2 += 1;
    } while (var_r5_2 < 0x60);
    var_r5_3 = 0x60;
    do {
        SetEventFlag(var_r5_3, 0);
        var_r5_3 += 1;
    } while (var_r5_3 < 0xA0);
    var_r5_4 = 0;
    do {
        SetMapBackgroundSeenFlag(var_r5_4, 0);
        var_r5_4 += 1;
    } while (var_r5_4 < 0x80);
    var_r5_5 = 0;
    do {
        SetRecordsMusicHeard(var_r5_5, 0);
        var_r5_5 += 1;
    } while (var_r5_5 < 0x40);
    var_r5_6 = 0;
    do {
        SetListRowFlag(var_r5_6, 0);
        var_r5_6 += 1;
    } while (var_r5_6 < 0x40);
    var_r5_7 = 0;
    do {
        func_02086930(var_r5_7, 0);
        var_r5_7 += 1;
    } while (var_r5_7 < 8);
}

/* Prepare the 3D engine for a scene: clear the 3D display control's blend and error
 * status bits, enable the 3D display, use a blue clear colour and a full-screen
 * orthographic projection, then start a new projection matrix. */
void Init3DRendering(void) {
    M2C_UNK GX_SetClearColor(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK GX_SetOrthoProjection(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);

    REG_DISP3DCNT = (u16)(REG_DISP3DCNT & (u16)~(DISP3DCNT_ALPHA_BLEND | DISP3DCNT_ERROR_MASK));
    REG_GX_SWAP_BUFFERS = 1;
    GX_SetClearColor(0x2BEA, 0, GX_CLEAR_DEPTH_MAX, 0x3F, 0);
    *(s32 *)0x04000580 = 0xBFFF0000;
    GX_SetOrthoProjection(0, -0xC0, 0, 0x100, 1, 0x2000, 0x1000, 1, 0);
    REG_GX_MTX_STORE = 0;
    REG_GX_MTX_MODE = 2;
}

/* Set the 3D engine's default material and light 0: white diffuse (taken from the
 * vertex colour), ambient, specular and emission, a white light shining along the
 * Z axis. */
void SetDefault3DLightMaterial(void) {
    REG_GX_LIGHT_VECTOR = GX_DEFAULT_LIGHT_VECTOR;
    REG_GX_LIGHT_COLOR = GX_DEFAULT_LIGHT_COLOR;
    REG_GX_DIF_AMB = GX_DEFAULT_MATERIAL_DIF_AMB;
    REG_GX_SPE_EMI = GX_DEFAULT_MATERIAL_SPE_EMI;
}

/* Set up the 3D engine for a flat sprite scene: clear its error state and set the
 * default polygon attribute, place the look-at camera, set the default light and
 * material, then start a new projection matrix and write a straight normal. */
void SetupSprite3DScene(void) {
 void G3X_Reset(void);
 void G3X_SetCamera(Vec02086dfc *,Vec02086dfc *,Vec02086dfc *,s32,s32);
 void SetDefault3DLightMaterial(void);
 Vec02086dfc eye=gSpriteSceneCameraEye;
 Vec02086dfc center={0,0,0};
 Vec02086dfc up=gSpriteSceneCameraUp;
 G3X_Reset();G3X_SetCamera(&eye,&up,&center,1,0);SetDefault3DLightMaterial();
 REG_GX_MTX_PUSH=0;REG_GX_MTX_MODE=3;
 REG_GX_MTX_IDENTITY=0;REG_GX_MTX_MODE=2;
 REG_GX_NORMAL=0x20000000;
}

void func_02086e9c(void) {
    M2C_FIELD((void *)0x04000448, s32 *, 0) = 1;
    M2C_FIELD((void *)0x04000448, s32 *, 0xF8) = 1;
}

void func_02086eb4(void) {
    *(s32 *)0x04000540 = 1;
}

void func_02086ec8(void) {
 void func_02086eb4(void);
 *(volatile u32 *)0x04000448=1;data_02168fe8=func_02086eb4;
}

/* Maps a texture's side length in pixels (GX_TEX_SIZE_*) to the code the GX
 * TEXIMAGE_PARAM size field stores (GX_TEX_CODE_*).  Another copy of the same
 * helper as GetGxTextureSizeCode; the display-list writers below put the result
 * in the 3D sprite's texture-image attribute. */
s32 GetGxTextureSizeCode3(s32 size) {
    switch (size) {                                 /* irregular */
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

/* Maps a square texture's size in pixels (8, 16, ... 1024) to its 3-bit GX
 * texture-size code (0..7); another copy of the helper, used here for the
 * 3D sprite's texture image attributes. */
s32 GetGxTextureSizeCode4(s32 size) {
    switch (size) {                                 /* irregular */
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

void SetGxPolygonAttr(s32 arg0, s32 arg1) {
    *(s32 *)0x040004A4 = (arg0 << 0x18) | 0x81 | (arg1 << 0x10);
}

/* Program the GX texture registers for one texture: TEXIMAGE_PARAM gets the
 * format, the width/height size codes, the texture's VRAM offset and the two
 * always-set flag bits; TEXPLTT_BASE gets the palette base, scaled differently
 * for 256-colour textures (format 2). */
void SetGxTextureParams(s32 format,s32 width,s32 height,s32 textureOffset,s32 paletteBase) {
 s32 heightCode; s32 paletteShift;
 heightCode=GetGxTextureSizeCode4(height);
 REG_GX_TEXIMAGE_PARAM=((u32)(textureOffset<<5)>>3)|(format<<GX_TEXIMAGE_FORMAT_SHIFT)|0x40000000|(GetGxTextureSizeCode3(width)<<GX_TEXIMAGE_SIZE_SHIFT)|(heightCode<<(GX_TEXIMAGE_SIZE_SHIFT+3))|0x20000000;
 paletteShift=format==2?1:0;
 REG_GX_TEXPLTT_BASE=(u32)(paletteBase<<5)>>(4-paletteShift);
}

void func_020870dc(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,u8 arg5,u8 arg6,u8 arg7) {
 s32 temp_r0; s32 temp_r4; s32 var_r0; s32 var_r1; s32 var_r2; s32 var_r3;
 temp_r4=GetGxTextureSizeCode4(arg2);
 temp_r0=GetGxTextureSizeCode3(arg1);
 var_r1=arg5?3:0;var_r2=arg6?3:0;var_r3=arg7?1:0;
 *(volatile u32 *)0x040004A8=(((u32)(arg3<<5)>>3)|(arg0<<26)|0x40000000|(temp_r0<<20)|(temp_r4<<23))|(var_r1<<16)|(var_r2<<18)|(var_r3<<29);
 var_r0=arg0==2?1:0;
 *(volatile u32 *)0x040004AC=(u32)(arg4<<5)>>(4-var_r0);
}

void ResetGxTextureParams(void) {
    M2C_FIELD((void *)0x040004A8, s32 *, 0) = 0x20000000;
    M2C_FIELD((void *)0x040004A8, s32 *, 4) = 0;
}

