/* 38 functions from 0x021F05FC to 0x021F15D4 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_mapselect.h"

/* The ov003 battle-setup record (class/vtable data_ov003_0220fb18): it holds the
 * per-player setup (CO id and army state) of the four players and the unit sprite
 * pointers the setup screen draws. */
#define BATTLE_SETUP_PLAYERS     0x14 /* first of four player-setup entries */
#define BATTLE_SETUP_PLAYER_LEN  0x18 /* bytes per player-setup entry */
#define BATTLE_SETUP_PLAYER_COUNT 4
#define BATTLE_SETUP_SPRITES     0x78 /* first of the record's unit sprite pointers */
#define BATTLE_SETUP_SPRITE_COUNT 0x1A

void func_ov003_021f05fc(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    M2C_UNK ConstructArray(M2C_UNK **, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK **MemAlloc(M2C_UNK);
    void SetOv003SceneClass(s32);
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK data_ov003_0220f8e0;
    extern M2C_UNK gBattlePanelVTable;
    extern M2C_UNK gWaypointPanelGroupVTable;
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;
    extern M2C_UNK InitOv003OptionValue;
    extern M2C_UNK Ov003OptionValue_Destructor;
    M2C_UNK **temp_r0_10;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    M2C_UNK **temp_r0_8;
    M2C_UNK **temp_r0_9;
    M2C_UNK **temp_r1;
    M2C_UNK **temp_r1_2;
    M2C_UNK **temp_r2;
    s32 var_r3;
    u8 temp_ip;
    u8 temp_r5;
    u8 temp_r5_2;
    u8 var_r1;
    u8 var_r3_2;
    void *temp_r0;

    SetOv003SceneClass((s32)&data_ov003_0220f8e0);
    temp_r0 = CreateSpriteFromClass(&data_ov003_0220f8e0, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_0220fb38;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220fb64;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        temp_r5 = M2C_FIELD(temp_r0, u8 *, 0x39) & ~2;
        M2C_FIELD(temp_r0, u8 *, 0x39) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((u8) (temp_r5 & ~0xC) & ~0xF0);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~1) & ~2;
        temp_r5_2 = (u8) (temp_ip & ~4) & ~8;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = temp_r5_2;
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (temp_r5_2 & ~0x70) & ~0x80);
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x54) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x64) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x6C) = NULL;
        temp_r0_2 = MemAlloc(0x12);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_2, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 2) = (u16) M2C_FIELD(temp_r0_2, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_2;
        temp_r0_3 = MemAlloc(0x14);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &gBattlePanelVTable;
            M2C_FIELD(temp_r0_3, s16 *, 4) = 8;
            M2C_FIELD(temp_r0_3, s16 *, 6) = 4;
            M2C_FIELD(temp_r0_3, s16 *, 8) = 0xA0;
            M2C_FIELD(temp_r0_3, s16 *, 0xA) = 0xA0;
            M2C_FIELD(temp_r0_3, s8 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x13) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x10) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0x11) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xE) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xF) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xC) = 0x63;
            M2C_FIELD(temp_r0_3, s8 *, 0xD) = 0x63;
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_3;
        temp_r0_4 = MemAlloc(0x12);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_4, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_4, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_4, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_4, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_4, u16 *, 2) = (u16) M2C_FIELD(temp_r0_4, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_4;
        temp_r0_5 = MemAlloc(0x12);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_5, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_5, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_5, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_5, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_5, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_5, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_5, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_5, u16 *, 2) = (u16) M2C_FIELD(temp_r0_5, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_5;
        temp_r0_6 = MemAlloc(0x12);
        if (temp_r0_6 != NULL) {
            M2C_FIELD(temp_r0_6, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_6, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_6, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_6, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_6, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_6, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_6, u16 *, 2) = (u16) M2C_FIELD(temp_r0_6, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = temp_r0_6;
        temp_r0_7 = MemAlloc(0x12);
        if (temp_r0_7 != NULL) {
            M2C_FIELD(temp_r0_7, s8 *, 0) = 4;
            M2C_FIELD(temp_r0_7, s8 *, 1) = 0;
            M2C_FIELD(temp_r0_7, u16 *, 2) = 0U;
            M2C_FIELD(temp_r0_7, u16 *, 4) = 0U;
            M2C_FIELD(temp_r0_7, s16 *, 6) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 8) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0xA) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 0xC) = 1;
            M2C_FIELD(temp_r0_7, s16 *, 0xE) = 0;
            M2C_FIELD(temp_r0_7, s16 *, 0x10) = 0;
            M2C_FIELD(temp_r0_7, u16 *, 2) = (u16) M2C_FIELD(temp_r0_7, u16 *, 4);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_7;
        temp_r0_8 = MemAlloc(0x48);
        if (temp_r0_8 != NULL) {
            var_r1 = 0;
            M2C_FIELD(temp_r0_8, M2C_UNK **, 0) = NULL;
            M2C_FIELD(temp_r0_8, s32 *, 4) = 0;
            do {
                temp_r2 = &temp_r0_8[var_r1];
                M2C_FIELD(temp_r2, s32 *, 8) = 0;
                M2C_FIELD(temp_r2, s32 *, 0x18) = 0;
                M2C_FIELD(temp_r2, s32 *, 0x28) = 0;
                var_r1 += 1;
                M2C_FIELD(temp_r2, s32 *, 0x38) = 0;
            } while ((u32) var_r1 < 4U);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x64) = temp_r0_8;
        temp_r0_9 = MemAlloc(0x80);
        if (temp_r0_9 != NULL) {
            var_r3 = 0;
            *temp_r0_9 = &gWaypointPanelGroupVTable;
            do {
                temp_r1 = &temp_r0_9[var_r3];
                var_r3 += 1;
                M2C_FIELD(temp_r1, s32 *, 0x44) = 0;
            } while (var_r3 < 0xD);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = temp_r0_9;
        temp_r0_10 = MemAlloc(0xE8);
        if (temp_r0_10 != NULL) {
            *temp_r0_10 = &data_ov003_0220fb18;
            ConstructArray(temp_r0_10 + 0x14, 4, 0x18, &InitOv003OptionValue, &Ov003OptionValue_Destructor);
            var_r3_2 = 0;
            do {
                temp_r1_2 = &temp_r0_10[var_r3_2];
                var_r3_2 += 1;
                M2C_FIELD(temp_r1_2, s32 *, 0x78) = 0;
            } while ((u32) var_r3_2 < 0x1AU);
        }
        M2C_FIELD(temp_r0, M2C_UNK ***, 0x6C) = temp_r0_10;
    }
    M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~1) | 1);
}

/* Releases the four-player battle object's children and re-applies its vtables
 * and per-player settings, but keeps the object itself alive. */
M2C_UNK ShutdownBattleObject(M2C_UNK obj) {
    M2C_UNK IsLinkSessionActive();
    M2C_UNK GetLocalPlayerIdForOverlay();
    void Link_DeleteAnnounceRefreshers();
    M2C_UNK MemFree();
    M2C_UNK DeleteSpriteObject();
    M2C_UNK GetWaypointOptionCoId();
    void SetPlayerCoId(M2C_UNK, M2C_UNK);
    void SetPlayerArmyId(M2C_UNK, M2C_UNK);
    void SetPlayerTeam(M2C_UNK, M2C_UNK);
    void SetOv003SceneState(s8);
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;

    M2C_UNK *setup;
    M2C_UNK playerCount;
    u8 playerState, controlMode, playerId;
    u8 i;

    M2C_FIELD(obj, M2C_UNK **, 0) = &data_ov003_0220fb38;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &data_ov003_0220fb64;

    // block 0
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 0) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0xe);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x74);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x74) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(1, playerState);

    // block 1
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 1) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0xf);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x75);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x75) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(2, playerState);

    // block 2
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 2) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0x10);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x76);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x76) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(3, playerState);

    // block 3
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 3) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0x11);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x77);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x77) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(4, playerState);

    // per-player army colours
    SetPlayerCoId(1, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xa)));
    SetPlayerCoId(2, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xb)));
    SetPlayerCoId(3, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xc)));
    SetPlayerCoId(4, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xd)));

    // per-player teams
    SetPlayerArmyId(1, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x18) & 0xff);
    SetPlayerArmyId(2, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x30) & 0xff);
    SetPlayerArmyId(3, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x48) & 0xff);
    SetPlayerArmyId(4, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x60) & 0xff);

    if (IsLinkSessionActive() != 0) {
        Link_DeleteAnnounceRefreshers();
    }

    if (M2C_FIELD(obj, M2C_UNK **, 0x3c)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x3c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x40)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x40), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x40));
    }
    if (M2C_FIELD(obj, M2C_UNK **, 0x44)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x44));
    if (M2C_FIELD(obj, M2C_UNK **, 0x48)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x48));
    if (M2C_FIELD(obj, M2C_UNK **, 0x4c)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x4c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x50)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x50));

    if (M2C_FIELD(obj, M2C_UNK **, 0x64)) {
        M2C_UNK *block = M2C_FIELD(obj, M2C_UNK **, 0x64);
        if (M2C_FIELD(block, M2C_UNK **, 0)) DeleteSpriteObject(M2C_FIELD(block, M2C_UNK **, 0));
        if (M2C_FIELD(block, M2C_UNK **, 4)) DeleteSpriteObject(M2C_FIELD(block, M2C_UNK **, 4));
        for (i = 0; i < 4; i++) {
            if (((M2C_UNK *)((u8 *)block + 0x8))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x8))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x18))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x18))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x28))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x28))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x38))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x38))[i]);
        }
        MemFree(block);
    }

    if (M2C_FIELD(obj, M2C_UNK **, 0x58)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x58));
    if (M2C_FIELD(obj, M2C_UNK **, 0x5c)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x5c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x54)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x54));
    if (M2C_FIELD(obj, M2C_UNK **, 0x60)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x60));

    if (M2C_FIELD(obj, M2C_UNK **, 0x68)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x68), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x68));
    }
    if (M2C_FIELD(obj, M2C_UNK **, 0x6c)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x6c));
    }

    SetOv003SceneState(4);
    return obj;
}

/* Deleting destructor of the battle scene's CO panel record (BATTLE_SCENE_PANEL_INFO,
 * slot 1 of gBattlePanelVTable): free the record and return it. */
s32 BattlePanel_Delete(s32 panel) {
    M2C_UNK MemFree();
    MemFree(panel);
    return panel;
}

/* Free the waypoint panel's sprite group: install its class, drop the panel's
 * face sprites and face children, delete the 13 label handles the group owns,
 * then free the group. WaypointPanelGroup_Destructor is the non-freeing twin. */
M2C_UNK **DestroyWaypointPanelGroup(M2C_UNK **group) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DeleteAllFaceChildren();
    M2C_UNK DeleteAllFaceSprites();
    extern M2C_UNK gWaypointPanelGroupVTable;
    register s32 i;

    *group = &gWaypointPanelGroupVTable;
    DeleteAllFaceSprites();
    DeleteAllFaceChildren();
    i = 0;
    do {
        if (group[i + 0x11] != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while (i < 0xD);
    MemFree(group);
    return group;
}

/* Destructor of the battle-setup record: install its class, release the unit
 * sprites and the four player-setup entries it owns, then free the record. */
M2C_UNK **DestroyBattleSetup(M2C_UNK **setup) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DestroyArray(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK Ov003OptionValue_Destructor;
    u8 i;
    *setup = &data_ov003_0220fb18;
    i = 0;
    do {
        if (M2C_FIELD(((s32)setup + (i * 4)), s32 *, BATTLE_SETUP_SPRITES) != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while ((u32)i < BATTLE_SETUP_SPRITE_COUNT);
    DestroyArray((u8 *)setup + BATTLE_SETUP_PLAYERS, BATTLE_SETUP_PLAYER_COUNT, BATTLE_SETUP_PLAYER_LEN, &Ov003OptionValue_Destructor);
    MemFree(setup);
    return setup;
}

#pragma opt_strength_reduction off
/* Destructor for the four-player battle object: re-applies the vtables and the
 * per-player settings from the battle setup, then releases every child
 * allocation and the object itself. */
M2C_UNK DestroyBattleObject(M2C_UNK obj) {
    M2C_UNK IsLinkSessionActive();
    M2C_UNK GetLocalPlayerIdForOverlay();
    void Link_DeleteAnnounceRefreshers();
    M2C_UNK MemFree();
    M2C_UNK DeleteSpriteObject();
    M2C_UNK GetWaypointOptionCoId();
    void SetPlayerCoId(M2C_UNK, M2C_UNK);
    void SetPlayerArmyId(M2C_UNK, M2C_UNK);
    void SetPlayerTeam(M2C_UNK, M2C_UNK);
    void SetOv003SceneState(s8);
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;

    M2C_UNK *setup;
    M2C_UNK playerCount;
    u8 playerState, controlMode, playerId;
    u8 i;

    M2C_FIELD(obj, M2C_UNK **, 0) = &data_ov003_0220fb38;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &data_ov003_0220fb64;

    // block 0
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 0) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0xe);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x74);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x74) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(1, playerState);

    // block 1
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 1) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0xf);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x75);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x75) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(2, playerState);

    // block 2
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 2) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0x10);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x76);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x76) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(3, playerState);

    // block 3
    setup = M2C_FIELD(obj, M2C_UNK **, 0x6c);
    playerCount = M2C_FIELD(setup, s8 *, 4);
    if (playerCount <= 3) playerState = 0;
    else {
        controlMode = M2C_FIELD(setup, u8 *, 0x11);
        if (controlMode == 1) {
            if (IsLinkSessionActive() == 1) {
                playerId = M2C_FIELD(setup, u8 *, 0x77);
                if (playerId == GetLocalPlayerIdForOverlay()) playerState = 1;
                else playerState = (u8)((M2C_FIELD(setup, u8 *, 0x77) + 3) & 0xff);
            } else {
                playerState = 1;
            }
        } else {
            playerState = 2;
        }
    }
    SetPlayerTeam(4, playerState);

    // per-player army colours
    SetPlayerCoId(1, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xa)));
    SetPlayerCoId(2, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xb)));
    SetPlayerCoId(3, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xc)));
    SetPlayerCoId(4, GetWaypointOptionCoId(M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), u8 *, 0xd)));

    // per-player teams
    SetPlayerArmyId(1, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x18) & 0xff);
    SetPlayerArmyId(2, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x30) & 0xff);
    SetPlayerArmyId(3, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x48) & 0xff);
    SetPlayerArmyId(4, M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0x60) & 0xff);

    if (IsLinkSessionActive() != 0) {
        Link_DeleteAnnounceRefreshers();
    }

    // cleanup pointers 0x3c..0x50
    if (M2C_FIELD(obj, M2C_UNK **, 0x3c)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x3c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x40)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x40), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x40));
    }
    if (M2C_FIELD(obj, M2C_UNK **, 0x44)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x44));
    if (M2C_FIELD(obj, M2C_UNK **, 0x48)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x48));
    if (M2C_FIELD(obj, M2C_UNK **, 0x4c)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x4c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x50)) MemFree(M2C_FIELD(obj, M2C_UNK **, 0x50));

    // 0x64 sub-block
    if (M2C_FIELD(obj, M2C_UNK **, 0x64)) {
        M2C_UNK *block = M2C_FIELD(obj, M2C_UNK **, 0x64);
        if (M2C_FIELD(block, M2C_UNK **, 0)) DeleteSpriteObject(M2C_FIELD(block, M2C_UNK **, 0));
        if (M2C_FIELD(block, M2C_UNK **, 4)) DeleteSpriteObject(M2C_FIELD(block, M2C_UNK **, 4));
        for (i = 0; i < 4; i++) {
            if (((M2C_UNK *)((u8 *)block + 0x8))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x8))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x18))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x18))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x28))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x28))[i]);
            if (((M2C_UNK *)((u8 *)block + 0x38))[i]) DeleteSpriteObject(((M2C_UNK *)((u8 *)block + 0x38))[i]);
        }
        MemFree(block);
    }

    if (M2C_FIELD(obj, M2C_UNK **, 0x58)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x58));
    if (M2C_FIELD(obj, M2C_UNK **, 0x5c)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x5c));
    if (M2C_FIELD(obj, M2C_UNK **, 0x54)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x54));
    if (M2C_FIELD(obj, M2C_UNK **, 0x60)) DeleteSpriteObject(M2C_FIELD(obj, M2C_UNK **, 0x60));

    if (M2C_FIELD(obj, M2C_UNK **, 0x68)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x68), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x68));
    }
    if (M2C_FIELD(obj, M2C_UNK **, 0x6c)) {
        M2C_UNK *vtable = M2C_FIELD(M2C_FIELD(obj, M2C_UNK **, 0x6c), M2C_UNK *, 0);
        ((void (*)(M2C_UNK))vtable[1])(M2C_FIELD(obj, M2C_UNK **, 0x6c));
    }

    SetOv003SceneState(4);

    MemFree(obj);
    return obj;
}
#pragma opt_strength_reduction reset
/* Release the waypoint panel's sprite group without freeing it: install its class,
 * drop the panel's face sprites and face children, then delete the 13 label handles
 * the group owns (one per slot plus the trailing label). DestroyWaypointPanelGroup
 * is the freeing twin. */
M2C_UNK **WaypointPanelGroup_Destructor(M2C_UNK **group) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DeleteAllFaceChildren();
    M2C_UNK DeleteAllFaceSprites();
    extern M2C_UNK gWaypointPanelGroupVTable;
    register s32 i;
    *group = &gWaypointPanelGroupVTable;
    DeleteAllFaceSprites();
    DeleteAllFaceChildren();
    i = 0;
    do {
        if (group[i + 0x11] != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while (i < 0xD);
    
    return group;
}

/* Releases the battle-setup record without freeing it: re-apply its class, delete
 * the unit sprites it owns and destroy its four player-setup entries; the record
 * is left cleared for reuse.  DestroyBattleSetup is the freeing twin. */
M2C_UNK **ShutdownBattleSetup(M2C_UNK **setup) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK DestroyArray(void *, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_ov003_0220fb18;
    extern M2C_UNK Ov003OptionValue_Destructor;
    u8 i;
    *setup = &data_ov003_0220fb18;
    i = 0;
    do {
        if (M2C_FIELD(((s32)setup + (i * 4)), s32 *, BATTLE_SETUP_SPRITES) != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while ((u32)i < BATTLE_SETUP_SPRITE_COUNT);
    DestroyArray((u8 *)setup + BATTLE_SETUP_PLAYERS, BATTLE_SETUP_PLAYER_COUNT, BATTLE_SETUP_PLAYER_LEN, &Ov003OptionValue_Destructor);
    return setup;
}

/* Non-deleting destructor of the battle scene's CO panel record (slot 0 of
 * gBattlePanelVTable): its class has nothing to tear down.  BattlePanel_Delete is
 * its deleting twin. */
void BattlePanel_Destroy(void) {

}

/* Deleting destructor of a bounded option-value record (Ov003OptionValue):
 * free the record and return it.  Its non-freeing twin is
 * Ov003OptionValue_Destructor. */
s32 DestroyOv003OptionValue(s32 value) {
    M2C_UNK MemFree();
    MemFree(value);
    return value;
}

void func_ov003_021f1348(s32 arg0) {
    M2C_UNK DestroyBattleObject(s32);
    DestroyBattleObject(arg0 + 0xFFFFFFCC);
}

/* The live ov003 scene object of the class SetOv003SceneClass stored, or 0 before
 * a class is set.  FindObjectByClass is called without an argument because r0
 * still holds the class word from the load above. */
s32 GetOv003SceneObject(void) {
    s32 FindObjectByClass();
    extern M2C_UNK gOv003SceneState;

    if (M2C_FIELD(&gOv003SceneState, s32 *, SCENE_STATE_CLASS) == 0) {
        return 0;
    }
    return FindObjectByClass();
}

/* Set the class descriptor of the scene object the ov003 screen creates and
 * clear the scene state, so GetOv003SceneObject starts looking for the new class. */
void SetOv003SceneClass(s32 sceneClass) {
    void SetOv003SceneState(s8);
    extern M2C_UNK gOv003SceneState;
    SetOv003SceneState(0);
    M2C_FIELD(&gOv003SceneState, s32 *, SCENE_STATE_CLASS) = sceneClass;
}

void SetOv003SceneState(s8 arg0) {
    extern M2C_UNK gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, s8 *, 5) = arg0;
}

u8 GetOv003SceneState(void) {
    extern M2C_UNK gOv003SceneState;
    return M2C_FIELD(&gOv003SceneState, u8 *, 5);
}

/* TRUE while the ov003 scene state is 4, the state the scene view's destructor
 * leaves behind; the map-select cursor waits for it before switching to the
 * battle scene. */
u8 IsOv003SceneClosed(void) {
    u8 closed;

    if (GetOv003SceneState() == 4) {
        closed = 1;
    } else {
        closed = 0;
    }
    return closed;
}

/* TRUE while the ov003 scene is up and taking input (state 1), which lets the
 * map-select view start its screen transition. */
u8 IsOv003SceneActive(void) {
    u8 active;

    if (GetOv003SceneState() == SCENE_STATE_ACTIVE) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* TRUE while the ov003 scene is in its map-select phase (state 2), the phase
 * the overlay goes back to when a sub-screen (the map info, the waypoint panel
 * or the map-select panel) closes. */
u8 IsOv003SceneMapSelect(void) {
    u8 mapSelect;

    if (GetOv003SceneState() == 2) {
        mapSelect = 1;
    } else {
        mapSelect = 0;
    }
    return mapSelect;
}

void SetMapListCategory(s8 arg0) {
    extern M2C_UNK gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, s8 *, 6) = arg0;
}

u8 GetMapListCategory(void) {
    extern M2C_UNK gOv003SceneState;
    return M2C_FIELD(&gOv003SceneState, u8 *, 6);
}

/* Mark the ov003 scene as loaded, so it may take input. */
void Ov003_SetSceneReady(void) {
    extern M2C_UNK gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, u8 *, SCENE_READY) = 1;
}

/* Mark the ov003 scene as not loaded yet, so the next scene start rebuilds it. */
void Ov003_ClearSceneReady(void) {
    extern M2C_UNK gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, u8 *, SCENE_READY) = 0;
}

u8 Ov003_IsSceneReady(void) {
    extern M2C_UNK gOv003SceneState;
    return M2C_FIELD(&gOv003SceneState, u8 *, 1);
}

/* Store how the scene was entered (`entryState`, SCENE_ENTRY_*) and the slide
 * directions toward the next map of the list and back to the previous one. */
void SetSceneSlideDirections(s8 entryState, s8 nextMapSlide, s8 previousMapSlide) {
    extern M2C_UNK gOv003SceneState;

    M2C_FIELD(&gOv003SceneState, s8 *, SCENE_ENTRY_STATE) = entryState;
    M2C_FIELD(&gOv003SceneState, s8 *, SCENE_SLIDE_FORWARD) = nextMapSlide;
    M2C_FIELD(&gOv003SceneState, s8 *, SCENE_SLIDE_BACK) = previousMapSlide;
}

/* Horizontal offset the ov003 scene slides a page to for a slide direction code
 * (a page can only be left through the side it has a neighbour on): -0x100 when
 * moving on to the next page (1), +0x100 when going back to the previous one
 * (2), and 0 when the scene does not slide. */
s32 GetSlideDirectionOffset(s32 direction) {
    switch (direction) {                            /* irregular */
    case 0:
        return 0;
    case 1:
        return -0x100;
    case 2:
        return 0x100;
    default:
        return 0;
    }
}

void func_ov003_021f152c(s8 arg0) {
    extern M2C_UNK gOv003SceneState;
    M2C_FIELD(&gOv003SceneState, s8 *, 4) = arg0;
}

/* Horizontal slide offset of the scene transition the current ov003 scene was
 * entered with (gOv003SceneState+4): +0x100 for an entry from the right, -0x100
 * for an entry from the left, and 0 when the scene does not slide. */
s32 GetSceneEntryOffset(void) {
    extern M2C_UNK gOv003SceneState;
    switch (M2C_FIELD(&gOv003SceneState, u8 *, SCENE_ENTRY_STATE)) {
    case SCENE_ENTRY_NONE: return 0;
    case SCENE_ENTRY_RIGHT: return 0x100;
    case SCENE_ENTRY_LEFT: return -0x100;
    default: return 0;
    }
}

u8 GetNextMapSlideDirection(void) {
extern M2C_UNK gOv003SceneState;
return M2C_FIELD(&gOv003SceneState,u8 *,2);
}

/* Horizontal offset the scene slides to when the player picks the next map of
 * the list (SCENE_SLIDE_FORWARD is the direction toward it). */
s32 GetNextMapSlideOffset(void) {
extern M2C_UNK gOv003SceneState;
return GetSlideDirectionOffset(M2C_FIELD(&gOv003SceneState,u8 *,SCENE_SLIDE_FORWARD));
}

u8 GetPreviousMapSlideDirection(void) {
    extern M2C_UNK gOv003SceneState;
    return M2C_FIELD(&gOv003SceneState, u8 *, 3);
}

/* Horizontal offset the scene slides to when the player picks the previous map
 * of the list (SCENE_SLIDE_BACK is the direction back to it). */
s32 GetPreviousMapSlideOffset(void) {
extern M2C_UNK gOv003SceneState;
return GetSlideDirectionOffset(M2C_FIELD(&gOv003SceneState,u8 *,SCENE_SLIDE_BACK));
}

