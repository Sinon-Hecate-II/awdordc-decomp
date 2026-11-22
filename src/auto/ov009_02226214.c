/* 9 functions from 0x02226214 to 0x022262EC (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"

/* During an active link game, re-announce the local player when its stored slot
 * no longer matches the local player record (both are 0x60-byte announce
 * records).  `owner` is the sprite object the announce hangs off. */
void RefreshLinkPlayerAnnounce(M2C_UNK owner) {
    s32 ByteCompareN(s32, s32, M2C_UNK);
    s32 GetLinkLocalPlayerInfo();
    s32 GetLinkPlayerSlot(s32);
    s32 GetLinkPhase();
    M2C_UNK GetLinkLocalPlayerId();
    M2C_UNK SpawnLinkPlayerAnnounce(M2C_UNK);
    s32 localRecord;

    if ((GetLinkPhase() != LINK_PHASE_ACTIVE) && (GetLinkPhase() != LINK_PHASE_INGAME)) {
        return;
    }
    localRecord = GetLinkLocalPlayerInfo();
    if (ByteCompareN(localRecord, GetLinkPlayerSlot(GetLinkLocalPlayerId()), LINK_PLAYER_ANNOUNCE_SIZE) == 0) {
        return;
    }
    SpawnLinkPlayerAnnounce(owner);
}

void func_ov009_02226268(M2C_UNK arg0) {
    extern M2C_UNK data_ov009_02226728;
    extern M2C_UNK data_ov009_0222675c;
    M2C_UNK **temp_r0;

    temp_r0 = CreateSpriteFromClass(&data_ov009_0222675c, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov009_02226728;
    }
}

void func_ov009_02226290(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_ov009_0222675c;
    DeleteSpriteObjectsOfClass(&data_ov009_0222675c);
}

s32 func_ov009_022262a4(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_022262b8(void) {

}

s32 func_ov009_022262bc(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov009_022262d0(void) {

}

void func_ov009_022262d4(void) {

}

s32 func_ov009_022262d8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

