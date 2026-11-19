/* 44 functions from 0x022172B0 to 0x02218200 (ov006), found by ds-decomp. */
#include "common.h"
#include "ov006_map_transfer.h"
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
    u8 GetReadyPlayerMask();
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
        M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_READY) = GetReadyPlayerMask();
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
    u8 GetReadyPlayerMask();
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
        M2C_FIELD(p, u8 *, MAP_TRANSFER_PANEL_READY) = GetReadyPlayerMask();
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

void func_ov006_0221747c(void *arg0) {
    s32 HeapAllocBlock(s32);
    M2C_UNK func_020e36dc(void *);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = HeapAllocBlock(0x80);
    M2C_FIELD(arg0, s32 *, 0x48) = HeapAllocBlock(0x6F8);
    M2C_FIELD(arg0, s32 *, 0x4C) = HeapAllocBlock(0x2AC);
    func_020e36dc(arg0);
    LoadUiGraphicsBank(4);
    func_02089728();
    DisableMapConfirm();
}

void func_ov006_022174d0(void *arg0) {
    func_020e36f4();
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x3C));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x48));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x4C));
    FreeUiGraphicsBank(4);
    func_02089740();
}

void func_ov006_02217504(void *arg0) {
    M2C_UNK Link_CreateMatchRequest(void *, M2C_UNK, M2C_UNK, void *, void *, void *);
    M2C_UNK ConvertTextToGlyphs(s32, s32);
    s32 GetMapName(u16);
    ConvertTextToGlyphs(M2C_FIELD(arg0, s32 *, 0x3C), GetMapName((u16) M2C_FIELD(arg0, s32 *, 0x34)));
    Link_CreateMatchRequest(arg0 + 0x3C, 1, 0, arg0 + 0x40, arg0 + 0x44, arg0);
}

void func_ov006_02217554(void *p) {
extern M2C_UNK gMapOfferState;
if(M2C_FIELD(&gMapOfferState,s32 *,8)) {M2C_FIELD(p,s32 *,0x38)=1;return;}
CreateOnlinePlayerListNode(M2C_FIELD(&gMapOfferState,s32 *,4),p+0x38);
}

void func_ov006_02217588(void *arg0) {
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
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
    M2C_UNK func_020c47e4(M2C_UNK);
    M2C_UNK LoadMapRecord(M2C_UNK, M2C_UNK);
    M2C_UNK PackMapRecord(M2C_UNK, M2C_UNK);
    M2C_UNK ExpandMapRecord(M2C_UNK, M2C_UNK);
    s32 GetOnlineLocalPlayerId(void);
    s32 IsValidMapRecord(M2C_UNK);
    void func_020e3788(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    extern const Ov006Date data_ov006_02218394;

    const u32 *rd;
    u32 a[4];
    u32 b[3];
    u32 c[4];
    u32 d[3];
    u32 i;
    u32 *cell;

    rd = (const u32 *)&data_ov006_02218394;
    a[0] = rd[0]; a[1] = rd[1]; a[2] = rd[2]; a[3] = rd[3];
    b[0] = 0; b[1] = 0; b[2] = 0;
    c[0] = a[0]; c[1] = a[1]; c[2] = a[2]; c[3] = a[3];
    d[0] = 0; d[1] = 0; d[2] = 0;

    cell = (u32 *)M2C_FIELD(arg0, u32 *, 0x4C);

    func_020c47e4((M2C_UNK)c);
    LoadMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x34), M2C_FIELD(arg0, M2C_UNK *, 0x48));
    PackMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x48), M2C_FIELD(arg0, M2C_UNK *, 0x4C));
    ExpandMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x4C), M2C_FIELD(arg0, M2C_UNK *, 0x48));
    cell[0x14] = (u32)GetOnlineLocalPlayerId();

    cell[0x12] = (cell[0x12] & ~0xFFU) | (c[0] & 0xFFU);
    cell[0x12] = (cell[0x12] & ~0x3F00U) | ((c[1] << 26) >> 18);
    cell[0x12] = (cell[0x12] & ~0xFC000U) | ((c[2] << 26) >> 12);
    cell[0x12] = (cell[0x12] & ~0x3F00000U) | ((d[0] << 26) >> 6);
    cell[0x12] = (cell[0x12] & ~0xFC000000U) | (d[1] << 26);
    cell[0x13] = (cell[0x13] & ~0x3FU) | (d[2] & 0x3FU);
    cell[0x13] &= 0xF003FFFFU;

    if (IsValidMapRecord(M2C_FIELD(arg0, M2C_UNK *, 0x48)) != 0) {
        func_020e3788((M2C_UNK)M2C_FIELD(arg0, M2C_UNK *, 0x4C), 0x2AC, (M2C_UNK)((u8 *)arg0 + 0x38), (M2C_UNK)arg0);
    } else {
        SetSpriteAnimation(arg0, 2);
    }
}

void func_ov006_02217794(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x38) != 0) && (func_0208471c() == 0)) {
        return;
    }
    DisableMapConfirm();
    SetSpriteAnimation(arg0, 2);
}

void func_ov006_022177c8(s32 arg0) {
    extern M2C_UNK data_ov006_02218aa8;
    M2C_FIELD(CreateSpriteObject(&data_ov006_02218aa8), s32 *, 0x34) = arg0;
}

void func_ov006_022177e4(void) {
    M2C_UNK func_02089728();
    LoadUiGraphicsBank(4);
    func_02089728();
    if (func_02086a30(0x21) == 0) {
        SetUiMessageText(0x46000026);
        func_02086740(0x21, 1);
        return;
    }
    SetUiMessageText(0);
}

void func_ov006_0221782c(void) {
    M2C_UNK func_02089740();
    FreeUiGraphicsBank(4);
    func_02089740();
}

void func_ov006_02217840(M2C_UNK arg0) {
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
    func_02089728();
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
    func_02089740();
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x4C));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x50));
}

void func_ov006_02217948(void *arg0) {
    M2C_UNK CreateOnlinePlayerListUpToLimitNode(M2C_UNK, M2C_UNK, void *, void *);
    M2C_UNK CreateOnlinePlayerListNoLimitNode(M2C_UNK, void *, void *);
    M2C_UNK CreateOnlinePlayerListWithIdsNode(void *, M2C_UNK, void *, void *);
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0x3C) = 10;
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x38);
    switch (temp_r0) {
    case 0:
        CreateOnlinePlayerListUpToLimitNode(M2C_FIELD(arg0, s32 *, 0x4C), 0x64, arg0 + 0x3C, arg0);
        return;
    case 1:
        CreateOnlinePlayerListNoLimitNode(M2C_FIELD(arg0, s32 *, 0x4C), arg0 + 0x3C, arg0);
        return;
    case 2:
        CreateOnlinePlayerListWithIdsNode(arg0 + 0x48, M2C_FIELD(arg0, s32 *, 0x4C), arg0 + 0x3C, arg0);
        return;
    }
}

void func_ov006_022179b4(void *arg0) {
    s32 NextRandomValue();
    u64 func_020720f0(s32, s32);
    s32 IsValidMapRecord(s32);
    M2C_UNK ExpandMapRecord(s32, s32);
    s32 IsLocalMacAddress(void *);
    s32 FindCampaignMapId(s32);
    s32 GetOnlineLocalPlayerId();
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
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
        SetSpriteAnimation(arg0, 3);
        return;
    }
    temp_r1 = (s32)(func_020720f0(NextRandomValue(), sp0) >> 32);
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
    SetSpriteAnimation(arg0, 3);
}

void func_ov006_02217b08(void *arg0) {
    M2C_UNK func_020c9100();
    M2C_UNK func_020c9120(s32, s32);
    func_020c9100();
    func_020c9120(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x54));
}

void func_ov006_02217b24(void *arg0) {
    M2C_UNK func_0208999c(s32, M2C_UNK, s32);
    M2C_UNK TextLayer_AppendText(s32, M2C_UNK *);
    s32 CreateTextLayer();
    M2C_UNK func_0209ccb8(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020c8e40();
    extern M2C_UNK data_ov006_02218cd8;
    extern M2C_UNK func_ov003_021fef18;
    s32 temp_r0;

    temp_r0 = CreateTextLayer();
    func_0208999c(temp_r0, 2, 0x4600001F);
    TextLayer_AppendText(temp_r0, &data_ov006_02218cd8);
    TextLayer_AppendText(temp_r0, M2C_FIELD(arg0, s32 *, 0x54) + 6);
    func_020c8e40();
    func_0209ccb8(&func_ov003_021fef18, 6);
}

void func_ov006_02217b7c(M2C_UNK arg0) {
    s32 func_0208471c();
    M2C_UNK DisableMapConfirm();
    if (func_0208471c() == 0) {
        return;
    }
    DisableMapConfirm();
    SetSpriteAnimation(arg0, 4);
}

void func_ov006_02217ba4(s32 arg0) {
    M2C_UNK SetNumberDisplayGraphics(void *, M2C_UNK, M2C_UNK);
    void *CreateNumberDisplay();
    void *temp_r0;

    temp_r0 = CreateNumberDisplay();
    SetNumberDisplayGraphics(temp_r0, 0xCC00, 0xF);
    M2C_FIELD(temp_r0, s32 *, 0x68) = (s32) (arg0 + 0x40);
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x5C) = 9;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xA0;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 0x58;
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

void func_ov006_02217c74(M2C_UNK arg0) {
    M2C_UNK SetUiMessageText(s32);
    M2C_UNK func_02086740(M2C_UNK, M2C_UNK);
    s32 func_02086a30(M2C_UNK);
    extern M2C_UNK data_ov006_02218ba8;
    if (func_02086a30(0x22) != 0) {
        return;
    }
    SetUiMessageText(0x46000027);
    func_02086740(0x22, 1);
    CreateSpriteObject(&data_ov006_02218ba8, arg0);
}

void func_ov006_02217cb8(M2C_UNK arg0) { M2C_UNK SetUiMessageText(s32); M2C_UNK func_02086740(M2C_UNK,M2C_UNK); s32 func_02086a30(M2C_UNK); extern M2C_UNK data_ov006_02218ba8; if(func_02086a30(0x23)!=0)return; SetUiMessageText(0x46000028); func_02086740(0x23,1); CreateSpriteObject(&data_ov006_02218ba8,arg0); }

void func_ov006_02217cfc(s32 arg0) {
    extern s32 data_ov006_02218e2c;
    data_ov006_02218e2c = arg0;
}

s32 func_ov006_02217d0c(void) {extern s32 data_ov006_02218e2c;return (data_ov006_02218e2c*10)>>8;}

void func_ov006_02217d28(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x54) = HeapAllocBlock(0x1EA0);
    M2C_FIELD(arg0, s32 *, 0x44) = HeapAllocBlock(0x28);
    M2C_FIELD(arg0, s32 *, 0x48) = HeapAllocBlock(0x14);
    M2C_FIELD(arg0, s32 *, 0x4C) = HeapAllocBlock(0xA);
    M2C_FIELD(arg0, s32 *, 0x50) = HeapAllocBlock(6);
    M2C_FIELD(arg0, s8 *, 0x3B) = 0;
    func_020e36dc(arg0);
    LoadUiGraphicsBank(4);
    func_02089728();
    func_ov006_02217cfc(0);
    DisableMapConfirm();
}

void func_ov006_02217d9c(void *arg0) {
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x54));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x44));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x48));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x4C));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x50));
    func_020e36f4(arg0);
    FreeUiGraphicsBank(4);
    func_02089740();
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

void func_ov006_02218128(void *p) {
void *GetMapRecordStamp(s32); u32 i; u16 id; void *q; u32 flags; void *out; s32 value;
i=M2C_FIELD(p,u8 *,0x3a);
if(i>=M2C_FIELD(p,u8 *,0x39)){Sprite_ResumeAnimation(p);return;}
M2C_FIELD(p,u8 *,0x3a)=i+1;
id=M2C_FIELD(p,u16 **,0x50)[i]; GetMapRecord(id); q=GetMapRecordStamp(id);
flags=(M2C_FIELD(q,u32 *,0xc)>>29)<<8;
value=M2C_FIELD(q,s32 *,0x10); out=p+0x58;
if(M2C_FIELD(p,u8 *,0x3a)==M2C_FIELD(p,u8 *,0x39)) func_020e40e0(value,flags,out,p);
else CreateOnlinePlayerIdListNode(value,flags,out,p);
}

void func_ov006_022181a4(void *p) { s32 i; for(i=0;i<M2C_FIELD(p,u8 *,0x38);i++){u16 b=M2C_FIELD(p,u16 **,0x48)[i]; s32 a=M2C_FIELD(p,u8 **,0x4c)[i]; if(a==1)goto call; if(a!=2)continue; call: func_020868ac(b-0xe1,0);}}

