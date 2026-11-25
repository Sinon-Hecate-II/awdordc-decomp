/* 44 functions from 0x022172B0 to 0x02218200 (ov006), found by ds-decomp. */
#include "common.h"
#include "ov006_map_transfer.h"
#include "battle_map.h"
typedef struct { s32 v[4]; } Ov006Date;

/* The map-code screen object: what its digit display shows (kind 1 is the local
 * online player id, kind 2 a received 64-bit map code) and the code being
 * displayed or edited. */
#define MAP_CODE_SCREEN_KIND 0x3B /* u8 display kind: 1 = own player id, 2 = received map code */
#define MAP_CODE_SCREEN_CODE 0x3C /* u64 map code shown, edited in place by the display */

extern const Ov006Date data_ov006_02218394;

/* Status texts of the map-transfer screen: the valid pair is shown when the
 * campaign map record exists, the missing pair otherwise, one per transfer mode. */
#define MAP_TRANSFER_MSG_VALID_0   0x4600002C
#define MAP_TRANSFER_MSG_VALID_1   0x4600002D
#define MAP_TRANSFER_MSG_MISSING_0 0x46000020
#define MAP_TRANSFER_MSG_MISSING_1 0x46000021

/* Create the map-transfer panel of the link map-setup screen at transfer step 3,
 * attached to `owner`: it shows the campaign map header pages of the players that
 * are ready and starts without any received-record buffer chosen yet. */
void CreateMapTransferPanelStep3(M2C_UNK owner) {
    s8 GetLocalPlayerIdForOverlay();
    u8 GetSessionPlayerMask();
    s32 GetCampaignMapHeader(M2C_UNK);
    void *CreateSpriteObject(void *, M2C_UNK);
    extern M2C_UNK data_ov006_0221890c, data_ov006_02218918;
    u8 i;
    void *panel = CreateSpriteObject(&data_ov006_02218918, owner);

    if (panel) {
        M2C_FIELD(panel, void **, 0) = &data_ov006_0221890c;
        M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_STEP) = 3;
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_RECORDS) = 0;
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_CHOSEN) = 0;
        M2C_FIELD(panel, s8 *, MAP_TRANSFER_PANEL_LOCAL) = GetLocalPlayerIdForOverlay();
        M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_READY) = GetSessionPlayerMask();
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0) = GetCampaignMapHeader(0);
        i = 0;
        do {
            if (M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_READY) & (1 << i))
                M2C_FIELD(panel + i * 4, s32 *, MAP_TRANSFER_PANEL_PAGES) = (s32)((u8 (*)[0x54]) M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0) + i * CAMPAIGN_PAGE_HEADERS);
            i++;
        } while (i < 4);
    }
}

/* Creates the transfer screen's downloaded-map panel: links each ready player's
   campaign-map page, and remembers the received map records and the chosen
   record. */
void CreateMapTransferPanel(M2C_UNK owner, s32 records, s32 chosen) {
    s8 GetLocalPlayerIdForOverlay();
    u8 GetSessionPlayerMask();
    s32 GetCampaignMapHeader(M2C_UNK);
    void *CreateSpriteObject(void *, M2C_UNK);
    extern M2C_UNK gMapTransferPanelVtable, gMapTransferPanelStateClass;
    u8 i;
    void *p = CreateSpriteObject(&gMapTransferPanelStateClass, owner);
    if (p) {
        M2C_FIELD(p, void **, 0) = &gMapTransferPanelVtable;
        M2C_FIELD(p, u8 *, MAP_TRANSFER_PANEL_STEP) = 4;
        M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_RECORDS) = 0;
        M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_CHOSEN) = 0;
        M2C_FIELD(p, s8 *, MAP_TRANSFER_PANEL_LOCAL) = GetLocalPlayerIdForOverlay();
        M2C_FIELD(p, u8 *, MAP_TRANSFER_PANEL_READY) = GetSessionPlayerMask();
        M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_PAGE0) = GetCampaignMapHeader(0);
        i = 0;
        do {
            if (M2C_FIELD(p, u8 *, MAP_TRANSFER_PANEL_READY) & (1 << i))
                M2C_FIELD(p + i * 4, s32 *, MAP_TRANSFER_PANEL_PAGES) = (s32)((u8 (*)[0x54])M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_PAGE0) + i * 0x32);
            i++;
        } while (i < 4);
    }
    M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_RECORDS) = records;
    M2C_FIELD(p, s32 *, MAP_TRANSFER_PANEL_CHOSEN) = chosen;
}

s32 func_ov006_022173fc(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov006_02217410(void) {

}

void func_ov006_02217414(void) {
    s32 MemAlloc(M2C_UNK);
    extern M2C_UNK gMapOfferState;
    M2C_FIELD(&gMapOfferState, s32 *, 4) = MemAlloc(0x310);
    M2C_FIELD(&gMapOfferState, s32 *, 8) = 0;
    M2C_FIELD(&gMapOfferState, s8 *, 0) = 0;
}

void func_ov006_02217438(void) {extern M2C_UNK gMapOfferState;
if(M2C_FIELD(&gMapOfferState,s32 *,4)) {
MemFree(M2C_FIELD(&gMapOfferState,s32 *,4));
}
M2C_FIELD(&gMapOfferState,s32 *,4)=0;
}

void func_ov006_02217464(M2C_UNK arg0) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov006_02218a48;
    CreateSpriteFromClass(&data_ov006_02218a48, arg0);
}

/* Allocate the ov006 map-offer object's name, map-record and packed-record
 * buffers, clear its found-player count, then set the screen up for the search
 * (UI graphics bank 4, frame border hidden and the map-confirm prompt off). */
void InitMapOfferObject(void *offer) {
    s32 HeapAllocBlock(s32);
    M2C_UNK func_020e36dc(void *);
    M2C_FIELD(offer, s32 *, MAP_OFFER_PLAYER_COUNT) = 0;
    M2C_FIELD(offer, s32 *, MAP_OFFER_NAME) = HeapAllocBlock(0x80);
    M2C_FIELD(offer, s32 *, MAP_OFFER_RECORD) = HeapAllocBlock(MAP_OFFER_RECORD_SIZE);
    M2C_FIELD(offer, s32 *, MAP_OFFER_PACKED) = HeapAllocBlock(MAP_OFFER_PACKED_SIZE);
    func_020e36dc(offer);
    LoadUiGraphicsBank(4);
    HideFrameBorderSprite();
    DisableMapConfirm();
}

/* Tear down the ov006 map-offer object: finish its web request, free the name,
 * map-record and packed-record buffers InitMapOfferObject allocated, release UI
 * graphics bank 4 and show the shared frame border again. */
void FreeMapOfferObject(void *offer) {
    func_020e36f4();
    HeapFreeBlock(M2C_FIELD(offer, s32 *, MAP_OFFER_NAME));
    HeapFreeBlock(M2C_FIELD(offer, s32 *, MAP_OFFER_RECORD));
    HeapFreeBlock(M2C_FIELD(offer, s32 *, MAP_OFFER_PACKED));
    FreeUiGraphicsBank(4);
    ShowFrameBorderSprite();
}

/* Begin the ov006 map-offer search: turn the offered map's name into glyphs in
 * the object's text buffer, then create the link match request that finds
 * another player to exchange the map with. */
void StartMapOfferSearch(void *offer) {
    M2C_UNK Link_CreateMatchRequest(void *, M2C_UNK, M2C_UNK, void *, void *, void *);
    M2C_UNK ConvertTextToGlyphs(s32, s32);
    s32 GetMapName(u16);
    ConvertTextToGlyphs(M2C_FIELD(offer, s32 *, MAP_OFFER_NAME), GetMapName((u16) M2C_FIELD(offer, s32 *, MAP_OFFER_MAP_ID)));
    Link_CreateMatchRequest(offer + MAP_OFFER_NAME, 1, 0, offer + MAP_OFFER_TIMEOUT, offer + MAP_OFFER_FLAGS, offer);
}

/* Fill in the map-offer search's player list on `offer`: once the search is
 * finished it found a single player, so the count is 1; otherwise build the
 * online player list from the received player record, the list writing its count
 * to MAP_OFFER_PLAYER_COUNT and being owned by the offer object. */
void InitMapOfferPlayerList(void *offer) {
    void *CreateOnlinePlayerListNode(void *, s32 *, s32);
    extern M2C_UNK gMapOfferState;

    if (M2C_FIELD(&gMapOfferState, s32 *, MAP_OFFER_STATE_DONE) != 0) {
        M2C_FIELD(offer, s32 *, MAP_OFFER_PLAYER_COUNT) = 1;
        return;
    }
    CreateOnlinePlayerListNode(M2C_FIELD(&gMapOfferState, s32 *, MAP_OFFER_STATE_RECORD),
                               (s32 *) ((u8 *) offer + MAP_OFFER_PLAYER_COUNT), offer);
}

void func_ov006_02217588(void *arg0) {
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        return;
    }
    GotoSpriteAnimationLabel(arg0, 1);
}

/* Finish the search for a player to exchange the offered map with: when the
 * search found a player, mark whether its record was received, then show the
 * found or no-player status text and close the search. */
void FinishMapOfferSearch(void *offer) {
    if (M2C_FIELD(offer, s32 *, MAP_OFFER_PLAYER_COUNT) != 0) {
        void *record = M2C_FIELD(&gMapOfferState, void **, MAP_OFFER_STATE_RECORD);
        s32 received;
        if (M2C_FIELD(record, s32 *, PLAYER_ENTRY_DATA_LEN) == 0) received = 0;
        else if (M2C_FIELD(record, s32 *, PLAYER_ENTRY_ID) == 0) received = 0;
        else received = 1;
        if (received) M2C_FIELD(&gMapOfferState, u8 *, MAP_OFFER_STATE_RECEIVED) = 1;
    }
    if (M2C_FIELD(&gMapOfferState, u8 *, MAP_OFFER_STATE_RECEIVED)) SetUiMessageText(MAP_OFFER_MSG_PLAYER_FOUND);
    else SetUiMessageText(MAP_OFFER_MSG_NO_PLAYER);
    M2C_FIELD(&gMapOfferState, s32 *, MAP_OFFER_STATE_DONE) = 1;
}

void func_ov006_0221762c(void *arg0) {
    void GetServerDateTime(s32 *);
    M2C_UNK LoadMapRecord(M2C_UNK, M2C_UNK);
    M2C_UNK PackMapRecord(M2C_UNK, M2C_UNK);
    M2C_UNK ExpandMapRecord(M2C_UNK, M2C_UNK);
    s32 GetOnlineLocalPlayerId(void);
    s32 IsValidMapRecord(M2C_UNK);
    void CreateOnlinePlayerListCountedNode(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    extern const Ov006Date data_ov006_02218394;

    s32 dateTime[7];
    volatile s32 initialTime[3];
    Ov006Date initialDate = data_ov006_02218394;
    u32 *cell;
    volatile s32 *zeroTime = initialTime;
    u32 stamp;
    u32 part;

    dateTime[0] = initialDate.v[0];
    dateTime[1] = initialDate.v[1];
    dateTime[2] = initialDate.v[2];
    dateTime[3] = initialDate.v[3];
    zeroTime[0] = 0;
    zeroTime[1] = 0;
    zeroTime[2] = 0;
    dateTime[4] = 0;
    dateTime[5] = 0;
    dateTime[6] = 0;

    cell = (u32 *)M2C_FIELD(arg0, u32 *, 0x4C);

    GetServerDateTime(dateTime);
    LoadMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x34), M2C_FIELD(arg0, M2C_UNK *, 0x48));
    PackMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x48), M2C_FIELD(arg0, M2C_UNK *, 0x4C));
    ExpandMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x4C), M2C_FIELD(arg0, M2C_UNK *, 0x48));
    cell[0x14] = (u32)GetOnlineLocalPlayerId();

    part = (dateTime[0] & 0xFFU);
    stamp = (cell[0x12] & ~0xFFU) | part;
    cell[0x12] = stamp;
    part = (((u32)dateTime[1] << 26) >> 18);
    stamp = (stamp & ~0x3F00U) | part;
    cell[0x12] = stamp;
    part = (((u32)dateTime[2] << 26) >> 12);
    stamp = (stamp & ~0xFC000U) | part;
    cell[0x12] = stamp;
    part = (((u32)dateTime[4] << 26) >> 6);
    stamp = (stamp & ~0x3F00000U) | part;
    cell[0x12] = stamp;
    part = ((u32)dateTime[5] << 26);
    stamp = (stamp & ~0xFC000000U) | part;
    cell[0x12] = stamp;
    cell[0x13] = (cell[0x13] & ~0x3FU) | (dateTime[6] & 0x3FU);
    ((volatile u32 *)cell)[0x13] &= 0xF003FFFFU;

    if (IsValidMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x48)) != 0) {
        CreateOnlinePlayerListCountedNode((M2C_UNK)M2C_FIELD(arg0, M2C_UNK *, 0x4C), 0x2AC, (M2C_UNK)((u8 *)arg0 + 0x38), (M2C_UNK)arg0);
    } else {
        GotoSpriteAnimationLabel(arg0, 2);
    }
}

/* Cancel the map-offer search when no other player has answered or the session
 * is in error: drop the map-confirm prompt, then play the sprite's cancel
 * animation (label 2). */
void CancelMapOfferSearch(void *offer) {
    if ((M2C_FIELD(offer, s32 *, MAP_OFFER_PLAYER_COUNT) != 0) && (IsSessionInError() == 0)) {
        return;
    }
    DisableMapConfirm();
    GotoSpriteAnimationLabel(offer, 2);
}

void func_ov006_022177c8(s32 arg0) {
    extern M2C_UNK data_ov006_02218aa8;
    M2C_FIELD(CreateSpriteObject(&data_ov006_02218aa8), s32 *, 0x34) = arg0;
}

/* Campaign map menu UI object init: load the UI graphics bank and hide the frame
 * border, then show the menu's one-time hint text; a mid event flag records that
 * the hint was shown, so later openings only clear the message. */
void InitCampaignMapMenuUi(void) {
    M2C_UNK HideFrameBorderSprite();
    LoadUiGraphicsBank(4);
    HideFrameBorderSprite();
    if (IsEventFlagMidSet(CAMPAIGN_MENU_HINT_FLAG) == 0) {
        SetUiMessageText(CAMPAIGN_MENU_MSG_HINT);
        SetEventFlagMid(CAMPAIGN_MENU_HINT_FLAG, 1);
        return;
    }
    SetUiMessageText(0);
}

void ShutdownCampaignMapMenuUi(void) {
    M2C_UNK ShowFrameBorderSprite();
    FreeUiGraphicsBank(4);
    ShowFrameBorderSprite();
}

void CreateCampaignMapMenuUi(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov006_02218a78;
    CreateSpriteObject(&data_ov006_02218a78, arg0);
}

/* Set up the map-transfer object: allocate the received-player and map-record
 * buffers, initialise its graphics, then show the status text of the selected
 * campaign map for this transfer mode. */
void InitMapTransferObject(void *object) {
    s32 IsCampaignMapRecordValid(s32);
    M2C_FIELD(object, s32 *, MAP_TRANSFER_ENTRIES) = HeapAllocBlock(MAP_TRANSFER_SLOTS * MAP_TRANSFER_ENTRY_SIZE);
    M2C_FIELD(object, s32 *, MAP_TRANSFER_RECORDS) = HeapAllocBlock(MAP_TRANSFER_SLOTS * MAP_TRANSFER_RECORD_SIZE);
    M2C_FIELD(object, s32 *, MAP_TRANSFER_CHOSEN) = 0;
    func_020e36dc(object);
    LoadUiGraphicsBank(4);
    HideFrameBorderSprite();
    DisableMapConfirm();
    if (IsCampaignMapRecordValid(M2C_FIELD(object, s32 *, MAP_TRANSFER_MAP_ID))) {
        switch (M2C_FIELD(object, s32 *, MAP_TRANSFER_MODE)) {
        case 0: SetUiMessageText(MAP_TRANSFER_MSG_VALID_0); return;
        case 1: SetUiMessageText(MAP_TRANSFER_MSG_VALID_1); return;
        }
    } else {
        switch (M2C_FIELD(object, s32 *, MAP_TRANSFER_MODE)) {
        case 0: SetUiMessageText(MAP_TRANSFER_MSG_MISSING_0); return;
        case 1: SetUiMessageText(MAP_TRANSFER_MSG_MISSING_1); return;
        }
    }
}

void func_ov006_0221791c(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK func_020e36f4();
    func_020e36f4();
    FreeUiGraphicsBank(4);
    ShowFrameBorderSprite();
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x4C));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x50));
}

/* Rebuild the map-transfer object's received-player list for its transfer mode:
 * reset the collected count to MAP_TRANSFER_SLOTS and build the online-player list
 * node that fills MAP_TRANSFER_ENTRIES -- mode 0 caps it at 100 players, mode 1
 * has no cap, mode 2 keeps only the ids named in MAP_TRANSFER_SOURCE. */
void BuildMapTransferPlayerList(void *transfer) {
    M2C_UNK CreateOnlinePlayerListUpToLimitNode(M2C_UNK, M2C_UNK, void *, void *);
    M2C_UNK CreateOnlinePlayerListNoLimitNode(M2C_UNK, void *, void *);
    M2C_UNK CreateOnlinePlayerListWithIdsNode(void *, M2C_UNK, void *, void *);
    s32 mode;

    M2C_FIELD(transfer, s32 *, MAP_TRANSFER_COUNT) = MAP_TRANSFER_SLOTS;
    mode = M2C_FIELD(transfer, s32 *, MAP_TRANSFER_MODE);
    switch (mode) {
    case 0:
        CreateOnlinePlayerListUpToLimitNode(M2C_FIELD(transfer, s32 *, MAP_TRANSFER_ENTRIES), 0x64, transfer + MAP_TRANSFER_COUNT, transfer);
        return;
    case 1:
        CreateOnlinePlayerListNoLimitNode(M2C_FIELD(transfer, s32 *, MAP_TRANSFER_ENTRIES), transfer + MAP_TRANSFER_COUNT, transfer);
        return;
    case 2:
        CreateOnlinePlayerListWithIdsNode(transfer + MAP_TRANSFER_SOURCE, M2C_FIELD(transfer, s32 *, MAP_TRANSFER_ENTRIES), transfer + MAP_TRANSFER_COUNT, transfer);
        return;
    }
}

void func_ov006_022179b4(void *arg0) {
    s32 NextRandomValue();
    u64 RuntimeIntDivMod(s32, s32);
    s32 IsValidMapRecord(s32);
    M2C_UNK ExpandMapRecord(s32, s32);
    s32 IsLocalMacAddress(void *);
    s32 FindCampaignMapId(s32);
    s32 GetOnlineLocalPlayerId();
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    s32 var_r6;   /* hit mask */
    s32 var_r5;   /* loop index */
    volatile s32 sp0;  /* match count on stack */
    s32 var_r8;   /* entry offset */
    s32 var_r9;   /* tile offset */
    s32 temp_r4;
    void *temp_r11;
    s32 temp_r7;
    s32 var_r0;
    s32 temp_r1;
    u32 temp_r2;
    s32 var_r3;
    u32 var_r4;

    var_r6 = 0;
    sp0 = var_r6;
    var_r5 = var_r6;
    if ((u32) M2C_FIELD(arg0, u32 *, 0x3C) > 0U) {
        var_r8 = var_r6;
        var_r9 = var_r6;
        do {
            temp_r4 = M2C_FIELD(arg0, s32 *, 0x50);
            temp_r11 = M2C_FIELD(arg0, s32 *, 0x4C) + var_r8;
            ExpandMapRecord(temp_r11 + 0x10, temp_r4 + var_r9);
            temp_r7 = M2C_FIELD(temp_r11, s32 *, 4);
            if (temp_r7 == GetOnlineLocalPlayerId()) {
                var_r0 = 1;
            } else if (IsLocalMacAddress(temp_r11 + 0x50) != 0) {
                var_r0 = 1;
            } else {
                var_r0 = 0;
            }
            if ((var_r0 == 0) && (IsValidMapRecord(temp_r4 + var_r9) != 0) && (FindCampaignMapId(temp_r4 + var_r9) == 0)) {
                var_r6 |= 1 << var_r5;
                sp0 += 1;
            }
            var_r5 += 1;
            var_r8 += 0x310;
            var_r9 += 0x6F8;
        } while (var_r5 < (u32) M2C_FIELD(arg0, u32 *, 0x3C));
    }
    if (sp0 == 0) {
        GotoSpriteAnimationLabel(arg0, 3);
        return;
    }
    temp_r1 = (s32)(RuntimeIntDivMod(NextRandomValue(), sp0) >> 32);
    temp_r2 = M2C_FIELD(arg0, u32 *, 0x3C);
    var_r3 = 0;
    var_r4 = 0;
    if (temp_r2 > 0U) {
        do {
            if (var_r6 & (1 << var_r4)) {
                if (var_r3 == temp_r1) {
                    M2C_FIELD(arg0, s32 *, 0x54) = (s32) ((var_r4 * 0x6F8) + M2C_FIELD(arg0, s32 *, 0x50));
                    goto done;
                } else {
                    var_r3 += 1;
                }
            }
            var_r4 += 1;
        } while (var_r4 < temp_r2);
    }
done:
    if (M2C_FIELD(arg0, s32 *, 0x54) != 0) {
        return;
    }
    GotoSpriteAnimationLabel(arg0, 3);
}

void func_ov006_02217b08(void *arg0) {
    M2C_UNK func_020c9100();
    M2C_UNK AppendCampaignMapLoadEntry(s32, s32);
    func_020c9100();
    AppendCampaignMapLoadEntry(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x54));
}

/* Show the map-transfer screen's chosen map: create a text layer with the
 * transfer status text, append the chosen record's name, reload the campaign map
 * headers and schedule the campaign scene's teardown. */
void ShowMapTransferChosenName(void *transfer) {
    M2C_UNK RenderTextLayerMessageDefault(s32, M2C_UNK, s32);
    M2C_UNK TextLayer_AppendText(s32, M2C_UNK *);
    s32 CreateTextLayer();
    M2C_UNK CreateQueuedSpriteTask(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020c8e40();
    extern M2C_UNK sMapTransferNameBreak;
    extern M2C_UNK Ov003_RedrawMapList;
    s32 layer;

    layer = CreateTextLayer();
    RenderTextLayerMessageDefault(layer, 2, MAP_TRANSFER_MSG_CHOSEN_MAP);
    TextLayer_AppendText(layer, &sMapTransferNameBreak);
    TextLayer_AppendText(layer, M2C_FIELD(transfer, s32 *, MAP_TRANSFER_CHOSEN) + MAP_RECORD_NAME);
    func_020c8e40();
    CreateQueuedSpriteTask(&Ov003_RedrawMapList, 6);
}

void func_ov006_02217b7c(M2C_UNK arg0) {
    s32 IsSessionInError();
    M2C_UNK DisableMapConfirm();
    if (IsSessionInError() == 0) {
        return;
    }
    DisableMapConfirm();
    GotoSpriteAnimationLabel(arg0, 4);
}

/* Start the map-transfer screen's target-player id display: a nine-digit number
 * at (0xa0, 0x58) that starts empty and writes its value back to the transfer
 * object's target player id. */
void CreateMapTransferTargetIdDisplay(s32 transfer) {
    M2C_UNK SetNumberDisplayGraphics(void *, M2C_UNK, M2C_UNK);
    void *CreateNumberDisplay();
    void *display;

    display = CreateNumberDisplay();
    SetNumberDisplayGraphics(display, 0xCC00, 0xF);
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_SOURCE) = (s32) (transfer + MAP_TRANSFER_TARGET_ID);
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_VALUE) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_HIGH) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_DIGITS) = 9;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_X) = 0xA0;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_Y) = 0x58;
}

void func_ov006_02217bf0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C) = 1;
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x38) = 2;
}

void func_ov006_02217c0c(s32 a) {
extern M2C_UNK data_ov006_02218bd8;
void *p=((void *(*)())CreateSpriteObject)(&data_ov006_02218bd8);
M2C_FIELD(p,s32 *,0x34)=a;M2C_FIELD(p,s32 *,0x38)=0;
}

void func_ov006_02217c30(s32 a) { extern M2C_UNK data_ov006_02218bd8; void *p=((void *(*)())CreateSpriteObject)(&data_ov006_02218bd8); M2C_FIELD(p,s32 *,0x34)=a; M2C_FIELD(p,s32 *,0x38)=1; }

void func_ov006_02217c54(void) {
    LoadUiGraphicsBank(4);
}

void func_ov006_02217c64(void) {
    FreeUiGraphicsBank(4);
}

/* Show the map-pick list 8 hint once: create the hint sprite under `owner` and
 * show its text, recording in a mid event flag that the hint has been shown so
 * later openings of the list keep quiet. */
void ShowMapPickHint8(M2C_UNK owner) {
    M2C_UNK SetUiMessageText(s32);
    M2C_UNK SetEventFlagMid(M2C_UNK, M2C_UNK);
    s32 IsEventFlagMidSet(M2C_UNK);
    extern M2C_UNK gMapPickHintClass;
    if (IsEventFlagMidSet(MAP_PICK_HINT_FLAG_8) != 0) {
        return;
    }
    SetUiMessageText(MAP_PICK_HINT_MSG_8);
    SetEventFlagMid(MAP_PICK_HINT_FLAG_8, 1);
    CreateSpriteObject(&gMapPickHintClass, owner);
}

/* Show the map-pick list 7 hint once: create the hint sprite under `owner` and
 * show its text, recording in a mid event flag that the hint has been shown so
 * later openings of the list keep quiet. */
void ShowMapPickHint7(M2C_UNK owner) {
    M2C_UNK SetUiMessageText(s32);
    M2C_UNK SetEventFlagMid(M2C_UNK, M2C_UNK);
    s32 IsEventFlagMidSet(M2C_UNK);
    extern M2C_UNK gMapPickHintClass;
    if (IsEventFlagMidSet(MAP_PICK_HINT_FLAG_7) != 0) {
        return;
    }
    SetUiMessageText(MAP_PICK_HINT_MSG_7);
    SetEventFlagMid(MAP_PICK_HINT_FLAG_7, 1);
    CreateSpriteObject(&gMapPickHintClass, owner);
}

void func_ov006_02217cfc(s32 arg0) {
    extern s32 data_ov006_02218e2c;
    data_ov006_02218e2c = arg0;
}

s32 func_ov006_02217d0c(void) {extern s32 data_ov006_02218e2c;return (data_ov006_02218e2c*10)>>8;}

/* Sets up the online map-list screen object: allocates its ten received player
 * entries and the per-candidate player-id, map-id, status and joinable-id
 * arrays, resets the code display, hides the shared 3D sprite and clears the
 * map-confirm flag. */
void InitMapListObject(void *object) {
    M2C_FIELD(object, s32 *, MAP_LIST_ENTRIES) = HeapAllocBlock(MAP_LIST_MAX_ENTRIES * MAP_LIST_ENTRY_SIZE);
    M2C_FIELD(object, s32 *, MAP_LIST_PLAYER_IDS) = HeapAllocBlock(MAP_LIST_MAX_ENTRIES * 4);
    M2C_FIELD(object, s32 *, MAP_LIST_MAP_IDS) = HeapAllocBlock(MAP_LIST_MAX_ENTRIES * 2);
    M2C_FIELD(object, s32 *, MAP_LIST_STATUS) = HeapAllocBlock(MAP_LIST_MAX_ENTRIES);
    M2C_FIELD(object, s32 *, MAP_LIST_JOINABLE_IDS) = HeapAllocBlock(MAP_LIST_MAX_JOINABLE * 2);
    M2C_FIELD(object, s8 *, MAP_LIST_DISPLAY_KIND) = 0;
    func_020e36dc(object);
    LoadUiGraphicsBank(4);
    HideFrameBorderSprite();
    func_ov006_02217cfc(0);
    DisableMapConfirm();
}

/* Tear down the online map-list object: free the received player entries and the
 * per-candidate arrays it allocated, finish its web request, release the UI
 * graphics bank it loaded and show the shared frame border again. */
void FreeMapListObject(void *list) {
    HeapFreeBlock(M2C_FIELD(list, s32 *, MAP_LIST_ENTRIES));
    HeapFreeBlock(M2C_FIELD(list, s32 *, MAP_LIST_PLAYER_IDS));
    HeapFreeBlock(M2C_FIELD(list, s32 *, MAP_LIST_MAP_IDS));
    HeapFreeBlock(M2C_FIELD(list, s32 *, MAP_LIST_STATUS));
    HeapFreeBlock(M2C_FIELD(list, s32 *, MAP_LIST_JOINABLE_IDS));
    func_020e36f4(list);
    FreeUiGraphicsBank(4);
    ShowFrameBorderSprite();
}

/* Start the map-code screen's digit display, which shows and edits the 64-bit
 * code at object+0x3c.  Kind 1 starts from the local online player id, drawn as
 * nine digits at (0xa0, 0x58); kind 2 starts from zero, drawn as the sixteen
 * digits of a received map code at (0xc0, 0x58). */
void func_ov006_02217de4(void *object) {
    s32 GetOnlineLocalPlayerId();
    void *CreateNumberDisplay();
    M2C_UNK SetNumberDisplayGraphics(void *, M2C_UNK, M2C_UNK);
    s32 playerId;
    u8 kind;
    void *display;

    display = CreateNumberDisplay();
    SetNumberDisplayGraphics(display, 0x6B80, 0xB);
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_SOURCE) = (s32) (object + MAP_CODE_SCREEN_CODE);
    kind = M2C_FIELD(object, u8 *, MAP_CODE_SCREEN_KIND);
    switch (kind) {
    case 1:
        playerId = GetOnlineLocalPlayerId();
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_VALUE) = playerId;
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_HIGH) = (s32) (playerId >> 0x1F);
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_DIGITS) = 9;
        M2C_FIELD(display, s16 *, SPRITE_ACTOR_X) = 0xA0;
        M2C_FIELD(display, s16 *, SPRITE_ACTOR_Y) = 0x58;
        return;
    case 2:
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_VALUE) = 0;
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_HIGH) = 0;
        M2C_FIELD(display, s32 *, NUMBER_DISPLAY_DIGITS) = 0x10;
        M2C_FIELD(display, s16 *, SPRITE_ACTOR_X) = 0xC0;
        M2C_FIELD(display, s16 *, SPRITE_ACTOR_Y) = 0x58;
        return;
    }
}

/* Fills the map-code screen's info text according to the display kind at
 * object+0x3b: kind 1 publishes the local online player id, kind 2 unfolds the
 * 64-bit map code at object+0x3c/+0x40 into its PID and CRC, publishes the PID and
 * renders "PID = %d\nCRC = %04X" in a text layer attached to the object. */
void DrawMapCodeInfo(void *object) {
M2C_UNK StringFormat(void *,void *,s32,s32); M2C_UNK SetOnlineLocalPlayerId(s32); M2C_UNK RenderTextLayer(void *,s32,s32,void *); s32 MapCode_GetPid(s32,s32); s32 MapCode_GetCrc(s32,s32); 
extern M2C_UNK sMapCodeDebugFormat;
u8 buf[64]; s32 pid,crc; void *sprite;
switch(M2C_FIELD(object,u8 *,0x3b)) {
case 1: SetOnlineLocalPlayerId(M2C_FIELD(object,s32 *,0x3c)); return;
case 2: pid=MapCode_GetPid(M2C_FIELD(object,s32 *,0x3c),M2C_FIELD(object,s32 *,0x40)); crc=MapCode_GetCrc(M2C_FIELD(object,s32 *,0x3c),M2C_FIELD(object,s32 *,0x40)); SetOnlineLocalPlayerId(pid); StringFormat(buf,&sMapCodeDebugFormat,pid,crc); sprite=(void *)CreateTextLayer(object); RenderTextLayer(sprite,2,0xcc00,buf); M2C_FIELD(sprite,s32 *,0x58)|=0x400; return;
}}

void func_ov006_02217f20(void *arg0) {
    s32 GetOnlineLocalPlayerId();
    s32 IsCampaignMapSaved(s32);
    void *GetMapRecordStamp(s32);
    s32 j, i;
    for (j = 0; j < 10; j++) {
        M2C_FIELD(arg0, s32 **, 0x44)[j] = 0;
        M2C_FIELD(arg0, u16 **, 0x48)[j] = 0;
        M2C_FIELD(arg0, u8 **, 0x4c)[j] = 0;
    }
    M2C_FIELD(arg0, s32 **, 0x44)[0] = GetOnlineLocalPlayerId();
    M2C_FIELD(arg0, u32 *, 0x34) = 1;
    M2C_FIELD(arg0, u8 *, 0x38) = 1;
    for (j = 0; j < 50; j++) {
        if (IsCampaignMapSaved(j)) {
            i = j + 0xe1;
            M2C_FIELD(arg0, s32 **, 0x44)[M2C_FIELD(arg0, u32 *, 0x34)] = M2C_FIELD(GetMapRecordStamp(i), volatile s32 *, 0x10);
            M2C_FIELD(arg0, u16 **, 0x48)[M2C_FIELD(arg0, u32 *, 0x34)] = (u16)i;
            M2C_FIELD(arg0, u32 *, 0x34)++;
            M2C_FIELD(arg0, u8 *, 0x38)++;
            if (M2C_FIELD(arg0, u32 *, 0x34) >= 10) break;
        }
    }
    CreateOnlinePlayerListWithIdsNode(M2C_FIELD(arg0, void **, 0x44), M2C_FIELD(arg0, s32 *, 0x54), (u8 *)arg0 + 0x34, arg0);
}

/* Fill the object's status/joinable arrays for an online game list: for each candidate map
 * id, find a saved entry that is not this console's own and whose recorded settings match the
 * map record, marking the id joinable (1) or rejected (2) and collecting up to three
 * joinable ids. */
void BuildJoinableMapList(void *list){
void *GetMapRecord(s32);void *GetMapRecordStamp(s32);s32 GetOnlineLocalPlayerId(void);s32 IsLocalMacAddress(void *);s32 MapRecordsMatch(void *,void *);
void *entry,*stamp;s32 j,owner,offset,i,id,isLocalEntry;void *record;
i=0;M2C_FIELD(list,u8 *,0x39)=0;M2C_FIELD(list,u8 *,0x3a)=0;
if((s32)M2C_FIELD(list,u8 *,0x38)<=0)return;
do{
id=M2C_FIELD(list,u16 **,0x48)[i];record=GetMapRecord(id);stamp=GetMapRecordStamp(id);
j=0;
if((u32)j<M2C_FIELD(list,u32 *,0x34)){do{offset=j*0x310;
entry=M2C_FIELD(list,u8 **,0x54)+offset;
owner=M2C_FIELD(entry,s32 *,4);
if(owner==GetOnlineLocalPlayerId())isLocalEntry=1;else isLocalEntry=IsLocalMacAddress(entry+0x50)!=0;
if(isLocalEntry==0 && M2C_FIELD(stamp,s32 *,0x10)==M2C_FIELD(entry,s32 *,0x60)){
if(MapRecordsMatch(record,entry+0x10)==0)M2C_FIELD(list,u8 **,0x4c)[i]=2;
else{M2C_FIELD(list,u8 **,0x4c)[i]=1;M2C_FIELD(list,u16 **,0x50)[M2C_FIELD(list,u8 *,0x39)]=id;M2C_FIELD(list,u8 *,0x39)++;}
break;
}
j++;
}while((u32)j<M2C_FIELD(list,u32 *,0x34));}
if(M2C_FIELD(list,u8 *,0x39)>=3)return;
i++;
}while(i<(s32)M2C_FIELD(list,u8 *,0x38));
}

/* List-row step callback for the joinable campaign maps: create one online-player
 * id list row per joinable map id, taking the player id and flags of the map's
 * record stamp; the last row comes from the other id-list sprite bank.  Once every
 * row exists the list sprite goes back to its regular animation. */
void func_ov006_02218128(void *list) {
    void *GetMapRecordStamp(s32); u32 index; u16 mapId; void *stamp; u32 flags; void *owner; s32 playerId;
    index = M2C_FIELD(list, u8 *, 0x3a);
    if (index >= M2C_FIELD(list, u8 *, 0x39)) { Sprite_ResumeAnimation(list); return; }
    M2C_FIELD(list, u8 *, 0x3a) = index + 1;
    mapId = M2C_FIELD(list, u16 **, 0x50)[index]; GetMapRecord(mapId); stamp = GetMapRecordStamp(mapId);
    flags = (M2C_FIELD(stamp, u32 *, 0xc) >> 29) << 8;
    playerId = M2C_FIELD(stamp, s32 *, 0x10); owner = list + 0x58;
    if (M2C_FIELD(list, u8 *, 0x3a) == M2C_FIELD(list, u8 *, 0x39)) func_020e40e0(playerId, flags, owner, list);
    else CreateOnlinePlayerIdListNode(playerId, flags, owner, list);
}

/* Clear the campaign-map saved flag (SetCampaignMapSaved) of every map the list
 * holds: an entry whose join status is joinable (1) or rejected (2) maps it to its
 * save slot (map id minus the first campaign id). */
void ClearListedMapSavedFlags(void *list) {
    s32 i;
    for (i = 0; i < M2C_FIELD(list, u8 *, MAP_LIST_MAP_COUNT); i++) {
        u16 mapId = M2C_FIELD(list, u16 **, MAP_LIST_MAP_IDS)[i];
        s32 status = M2C_FIELD(list, u8 **, MAP_LIST_STATUS)[i];
        if (status == 1) goto clear;
        if (status != 2) continue;
    clear:
        SetCampaignMapSaved(mapId - MAP_ID_CAMPAIGN_FIRST, 0);
    }
}

