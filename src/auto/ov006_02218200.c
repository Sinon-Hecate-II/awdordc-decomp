/* 3 functions from 0x02218200 to 0x02218340 (ov006), found by ds-decomp. */
#include "common.h"

/* Validates the linked sub-object and propagates its state into the entity's slots. */
void func_ov006_02218200(void *entity) {
    s32 GetMapRecordBuffer();
    s32 GetCampaignMapHeader(s32);
    s32 GetOnlineLocalPlayerId();
    s32 IsLocalMacAddress(void *);
    s32 IsValidMapRecord(s32);
    void *sub = M2C_FIELD(entity, void **, 0x54);
    s32 curId = GetMapRecordBuffer();
    s32 prevId = GetCampaignMapHeader(0);
    s32 hasSub;
    s32 ok;
    s32 value;

    if (!M2C_FIELD(entity, s32 *, 0x34)) {
        GotoSpriteAnimationLabel(entity, 2);
        return;
    }
    if (!M2C_FIELD(sub, s32 *, 0x30C)) {
        hasSub = 0;
    } else if (!M2C_FIELD(sub, s32 *, 4)) {
        hasSub = 0;
    } else {
        hasSub = 1;
    }
    if (!hasSub) {
        GotoSpriteAnimationLabel(entity, 2);
        return;
    }
    value = M2C_FIELD(sub, s32 *, 4);
    if (value == GetOnlineLocalPlayerId()) {
        ok = 1;
    } else if (IsLocalMacAddress(sub + 0x50)) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (!ok) {
        GotoSpriteAnimationLabel(entity, 2);
        return;
    }
    ExpandMapRecord(sub + 0x10, curId);
    if (!IsValidMapRecord(curId)) {
        GotoSpriteAnimationLabel(entity, 3);
        return;
    }
    SetReceivedMapValue(M2C_FIELD(sub, s32 *, 8));
    MI_CpuCopy32(curId, prevId, 0x54);
    EnableMapConfirm();
}

/* Per-frame check of the ov006 received-map screen: cancel it when the session is
 * in error -- drop the map-confirm prompt and jump the sprite to its error
 * animation (label 3). */
void CancelMapReceiveOnSessionError(void *sprite) {
    if (IsSessionInError() == 0) {
        return;
    }
    DisableMapConfirm();
    GotoSpriteAnimationLabel(sprite, 3);
}

/* Spawn the ov006 joinable-map list object as a child sprite of `owner`: its
 * script runs InitMapListObject, the list build/input steps and FreeMapListObject. */
void CreateMapListObject(M2C_UNK owner) {
    void CreateSpriteObject(void *, s32);
    extern M2C_UNK gMapListClass;
    CreateSpriteObject(&gMapListClass, owner);
}
