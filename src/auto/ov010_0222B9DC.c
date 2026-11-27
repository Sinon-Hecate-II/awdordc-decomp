/* 19 functions from 0x0222B9DC to 0x0222BD5C (ov010), found by ds-decomp. */
#include "common.h"
#include "string_storage.h"

typedef struct { u8 value; } Flag;

void func_ov010_0222b9dc(void) {
    M2C_UNK DisableMapConfirm();
    DisableMapConfirm();
}

/* Exit handler of the online sub-screen: restore the map-confirm prompt when no
 * online session has started (otherwise keep it off for the running session) and
 * remove the sub-screen link indicator. */
void Ov010_ExitSubScreenLinkIndicator(void) {
    M2C_UNK DeleteSubScreenLinkIndicator();
    M2C_UNK EnableMapConfirm();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    if (IsOnlineSessionFlagSet(OV010_FLAG_STARTED) == 0) {
        EnableMapConfirm();
    } else {
        DisableMapConfirm();
    }
    DeleteSubScreenLinkIndicator();
}

/* Create the online lobby's local-player name label at (x, y) for its owner,
 * unless matchmaking has already started (then the map-confirm prompt is enabled
 * instead) or such a label already exists. */
void CreateOnlineNameLabel(s8 x, s16 y, M2C_UNK owner) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 FindObjectByClass(M2C_UNK *);
    s32 GetLocalPlayerName();
    M2C_UNK EnableMapConfirm();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK gOnlineLobbyNameLabelClass;
    extern M2C_UNK gOnlineNameLabelVTable;
    void *label;

    if (IsOnlineSessionFlagSet(OV010_FLAG_MATCHMAKING) != 0) {
        EnableMapConfirm();
        return;
    }
    if (FindObjectByClass(&gOnlineLobbyNameLabelClass) != 0) {
        return;
    }
    label = CreateSpriteObject(&gOnlineLobbyNameLabelClass, owner);
    if (label == NULL) {
        return;
    }
    M2C_FIELD(label, M2C_UNK **, 0) = &gOnlineNameLabelVTable;
    M2C_FIELD(label, s8 *, 0x34) = 0;
    M2C_FIELD(label, s8 *, ONLINE_LABEL_X) = x;
    M2C_FIELD(label, s16 *, ONLINE_LABEL_Y) = y;
    M2C_FIELD(label, s32 *, ONLINE_LABEL_NAME) = GetLocalPlayerName();
    M2C_FIELD(label, s8 *, 0x3C) = 0;
    M2C_FIELD(label, s32 *, 0x40) = 0;
}

/* Create the online match's local-player name label at (x, y) for its owner once
 * the session has started; before that the map-confirm prompt is enabled
 * instead.  Does nothing if such a label already exists. */
void CreateOnlineMatchNameLabel(s8 x, s16 y, M2C_UNK owner) {
    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 FindObjectByClass(M2C_UNK *);
    s32 GetLocalPlayerName();
    M2C_UNK EnableMapConfirm();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK gOnlineMatchNameLabelClass;
    extern M2C_UNK gOnlineNameLabelVTable;
    void *label;

    if (IsOnlineSessionFlagSet(OV010_FLAG_STARTED) == 0) {
        EnableMapConfirm();
        return;
    }
    if (FindObjectByClass(&gOnlineMatchNameLabelClass) != 0) {
        return;
    }
    label = CreateSpriteObject(&gOnlineMatchNameLabelClass, owner);
    if (label == NULL) {
        return;
    }
    M2C_FIELD(label, M2C_UNK **, 0) = &gOnlineNameLabelVTable;
    M2C_FIELD(label, s8 *, 0x34) = 0;
    M2C_FIELD(label, s8 *, ONLINE_LABEL_X) = x;
    M2C_FIELD(label, s16 *, ONLINE_LABEL_Y) = y;
    M2C_FIELD(label, s32 *, ONLINE_LABEL_NAME) = GetLocalPlayerName();
    M2C_FIELD(label, s8 *, 0x3C) = 0;
    M2C_FIELD(label, s32 *, 0x40) = 0;
}

/* Announce this console's online player status when it has changed: while the
 * online session is running, compare the local status record with the slot record
 * published for this player and, when they differ, spawn the player's announce
 * (its counterpart in the local-wireless code is RefreshLinkPlayerAnnounce). */
void RefreshOnlinePlayerAnnounce(M2C_UNK owner) {
    s32 ByteCompareN(s32, s32, M2C_UNK);
    s32 GetOnlinePlayerSlot(s32);
    M2C_UNK GetOnlineTransportPlayerId();
    s32 GetLocalPlayerStatus();
    M2C_UNK SpawnOnlinePlayerAnnounce(M2C_UNK);
    s32 localStatus;

    if (IsOnlineSessionFlagSet(OV010_FLAG_RUNNING) == 0) {
        return;
    }
    localStatus = GetLocalPlayerStatus();
    if (ByteCompareN(localStatus, GetOnlinePlayerSlot(GetOnlineTransportPlayerId()), ONLINE_PLAYER_RECORD_SIZE) == 0) {
        return;
    }
    SpawnOnlinePlayerAnnounce(owner);
}

/* Create the online player-announce refresher owned by `owner` and install its
 * vtable at offset 0. */
void SpawnOnlinePlayerAnnounceRefresher(M2C_UNK owner) {
    extern M2C_UNK gOnlineAnnounceRefresherVTable;
    extern M2C_UNK gOnlineAnnounceRefresherClass;
    M2C_UNK **refresher;

    refresher = CreateSpriteFromClass(&gOnlineAnnounceRefresherClass, owner);
    if (refresher != NULL) {
        *refresher = &gOnlineAnnounceRefresherVTable;
    }
}

/* Delete every online player-announce refresher sprite, stopping the online
 * engine re-announcing the local player. */
void DeleteOnlineAnnounceRefreshers(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gOnlineAnnounceRefresherClass;
    DeleteSpriteObjectsOfClass(&gOnlineAnnounceRefresherClass);
}

s32 func_ov010_0222bba0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222bbb4(void) {

}

s32 func_ov010_0222bbb8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222bbcc(void) {

}

s32 func_ov010_0222bbd0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222bbe4(void) {

}

/* Assign the stored text string `src` to the stored string `dst`: when both are
 * small (inline) strings the 12-byte value is copied whole, otherwise src's text
 * replaces all of dst's contents. */
void *StringStorageAssign(void *dst, void *src) {
    void *StringStorageReplaceWith(void *, M2C_UNK, u32, void *);
    typedef struct { u32 words[3]; } Copy;
    s32 dstIsLarge;
    u32 removeLength;
    dstIsLarge = ((u32)(M2C_FIELD(dst, s32 *, 0) << 31) >> 31) != 0;
    if (dstIsLarge == 0 && ((u32)(M2C_FIELD(src, s32 *, 0) << 31) >> 31) == 0) {
        *(Copy *)dst = *(Copy *)src;
        return dst;
    }
    removeLength = dstIsLarge ? M2C_FIELD(dst, u32 *, 4) : (u32)(M2C_FIELD(dst, u8 *, 0) << 24) >> 25;
    return StringStorageReplaceWith(dst, 0, removeLength, src);
}

/* Set the stored string `storage` to the NUL-terminated C string `text`:
 * replace everything the string currently holds with it. */
void StringStorageAssignText(void *storage, M2C_UNK text) {
    M2C_UNK StringStorageReplaceWithText(void *, M2C_UNK, u32, M2C_UNK);
    u32 length;

    if (((StringStorage *)storage)->large.flag == 0) {
        length = ((StringStorage *)storage)->small.length;
    } else {
        length = ((StringStorage *)storage)->large.length;
    }
    StringStorageReplaceWithText(storage, 0, length, text);
}

/* Replace the range [pos, pos+remove) of the stored string `dst` with the whole
 * contents of the stored string `src`, taking `src`'s text from wherever it is
 * held: inline in the small form, or on the heap in the large form. */
void *StringStorageReplaceWith(void *dst, M2C_UNK pos, u32 remove, void *src) {
    void *StringStorageReplace(void *, M2C_UNK, u32, void *, void *, Flag);
    u32 length;
    u8 *text;
    Flag unused;

    if (((StringStorage *)src)->large.flag) {
        text = ((StringStorage *)src)->large.data;
        length = ((StringStorage *)src)->large.length;
    } else {
        text = ((StringStorage *)src)->small.data;
        length = ((StringStorage *)src)->small.length;
    }
    return StringStorageReplace(dst, pos, remove, text, text + length, unused);
}

/* Replace the range [pos, pos+remove) of the stored string `storage` with the
 * NUL-terminated C string `text`, whose length StringStorageReplace derives from
 * its start and end pointers. */
M2C_UNK StringStorageReplaceWithText(void *storage, M2C_UNK pos, u32 remove, M2C_UNK text) {
    void *StringStorageReplace(void *, M2C_UNK, u32, void *, void *, Flag);
    s32 StringLength(M2C_UNK);
    Flag unused;
    return (M2C_UNK)StringStorageReplace(storage, pos, remove, (void *)text, (u8 *)text + StringLength(text), unused);
}

/* Release the message text a network-error message sprite owns (its stored string
 * at NET_ERROR_TEXT) and hand the sprite back; the sprite itself stays alive. */
s32 ReleaseNetErrorSpriteText(s32 sprite) {
    M2C_UNK StringStorageFree(s32);
    StringStorageFree(sprite + NET_ERROR_TEXT);
    return sprite;
}

/* Destroy a network-error message sprite: release the text it keeps at +0x44 and
 * free the sprite itself.  Returns the sprite (it is the vtable's free slot). */
void *FreeNetErrorSprite(void *sprite) {
    M2C_UNK StringStorageFree();
    M2C_UNK MemFree();

    StringStorageFree((u8 *) sprite + 0x44);
    MemFree(sprite);
    return sprite;
}

