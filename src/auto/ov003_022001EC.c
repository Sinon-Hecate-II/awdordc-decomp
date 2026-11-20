/* 40 functions from 0x022001EC to 0x02200EE4 (ov003), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "waypoint_panel.h"

/* A polymorphic ov003 scene object: a vtable at +0, a second interface vtable at
 * +0x34, then the children, buffers and sprite-handle arrays it owns. */
typedef struct Ov003Object {
    void *vtable;        /* +0x00 */
    u8  filler_04[0x30];
    void *iface;         /* +0x34 second vtable */
    u8  filler_38[0x0C];
    void *child44;       /* +0x44 child object */
    u8  filler_48[4];
    void *child4C;       /* +0x4C child object */
    void *child50;       /* +0x50 child object */
    void *child54;       /* +0x54 child object */
    void *buffer58;      /* +0x58 buffer */
    void *child5C;       /* +0x5C child object */
    void *child60;       /* +0x60 child object */
    void *buffer64;      /* +0x64 buffer */
    void *sprites68;     /* +0x68 array of 10 sprite handles */
    void *sprites6C;     /* +0x6C array of 2 sprite handles */
    void *sub70;         /* +0x70 sub-object with a resource handle at +0x14 */
} Ov003Object;

extern s32 sShogunBgFileNames[4];
extern s16 data_ov003_022103d4[4];
extern s16 data_ov003_022103cc[4];

/* Destructor: resets the object's vtables to the base ones, releases every owned
 * child object, buffer and sprite array, then frees the object itself. */
void *DestroyOv003Object(Ov003Object *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void func_020c127c(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    void *sub;
    void *child;

    obj->vtable = &data_ov003_02210104;
    obj->iface = &data_ov003_02210130;
    sub = obj->sub70;
    if (sub != NULL) {
        HeapFreeBlock(M2C_FIELD(sub, s32 *, 0x14));
        MemFree(sub);
    }
    child = obj->child44;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->child4C;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->child50;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->child54;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->child5C;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->child60;
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = obj->buffer58;
    if (child != NULL) MemFree(child);
    child = obj->buffer64;
    if (child != NULL) MemFree(child);
    sub = obj->sprites68;
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 36));
        MemFree(sub);
    }
    sub = obj->sprites6C;
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        MemFree(sub);
    }
    SetOv003SceneState(4);
    func_020c127c();
    MemFree(obj);
    return obj;
}

void func_ov003_022003dc(void) {

}

void func_ov003_022003e0(void) {

}

void func_ov003_022003e4(void) {

}

s16 GetWaypointSlotX(M2C_UNK arg0) {
    s16 func_ov003_022004d0();
    s16 func_ov003_022004f0(M2C_UNK);
    s32 temp_r4;

    temp_r4 = func_ov003_022004d0();
    return (s16) (temp_r4 + func_ov003_022004f0(arg0));
}

s16 func_ov003_022004d0(void) {
    s32 func_020cfb94(void);
    return data_ov003_022103d4[func_020cfb94() - 1];
}

s16 func_ov003_022004f0(s32 arg0) {
    s32 func_020cfb94(void);
    s32 val = data_ov003_022103cc[func_020cfb94() - 1];
    s32 r = arg0 * val;
    return (s16)r;
}

s32 GetShogunBgFileName(s32 arg0) {
    return sShogunBgFileNames[arg0 - 1];
}

s32 GetPlayerBgFlagTile(u32 arg0) {
    switch (arg0) {
    case 1:
        return 0x2937;
    case 2:
        return 0x65A9;
    case 3:
        return 0x1A33;
    case 4:
        return 0x2D4B;
    default:
        return 0;
    }
}

s32 GetPlayerPanelFlagTile(u32 a){switch(a){case 1:return 0x4e5b;case 2:return 0x76b2;case 3:return 0x46f9;case 4:return 0x5274;default:return 0;}}

/* Load the select-screen background for `playerCount` players into sprite layer
 * `layer` (the per-count CG, its tile data and the shared palette in OBJ palette
 * `palette`), then set each joined player's colour flag tile. */
void Ov003_LoadPlayerSelectBg(s32 layer, s32 palette, u32 playerCount) {
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_020814ac(s32, s32, M2C_UNK, s32);
    s32 GetPlayerIdForSlot(s32);
    s32 func_020ae7a4(s32, s32, s32);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK sShogunSelectCgName;
    extern M2C_UNK sSelectCommonBgPaletteName;
    u8 i;

    LoadDecompressedFileTo(GetLocalizedFileName(&sShogunSelectCgName), M2C_FIELD((void *)((u8 *)gCur3DSpriteEngine + (layer * 4)), s32 *, 0xC));
    func_020814ac(GetShogunBgFileName(playerCount), M2C_FIELD((void *)((u8 *)gCur3DSpriteEngine + (layer * 4)), s32 *, 0x20), 0, palette);
    LoadFileToSpriteBuffer(&sSelectCommonBgPaletteName, palette << 5, 0x40);
    if (playerCount <= 1U) {
        return;
    }
    for (i = 0; i < playerCount; i++) {
        func_020ae7a4(palette, (u8)(i + 1), GetPlayerBgFlagTile((u8)GetPlayerIdForSlot(i + 1)));
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
}

void Ov003_SetPanelPlayerFlagTile(s32 a, s32 b) {
s32 GetPlayerIdForSlot(s32);
s32 func_020ae7a4(s32,s32,s32);
s32 GetPlayerPanelFlagTile(u32);
func_020ae7a4(a,1,GetPlayerPanelFlagTile((u8)GetPlayerIdForSlot(b+1)));
}

void func_ov003_022006dc(s32 arg0) {
    extern void **gCurrentMap;
    s32 IsLinkSessionActive(void);
    void ResetTextLabelSlotsPartial(void);
    s32 MapSettings_Randomize(s32);
    void SetPlayerIdForSlot(s32, s32);
    void SetPlayerArmyId(s32, s32);
    void ApplyMapSettingsToPlayers(s32);
    void MI_CpuFill32(s32, void *, s32);
    s8 GetPlayerArmyId(s32);
    s32 GetPlayerCoId(s32);
    s32 GetPlayerCoIconIndex(u32);
    s32 func_0208492c(void);
    void Link_SendPacket(void *, s32);

    u8 r5;
    u8 *r6;
    u8 sp[0x24];

    if (IsLinkSessionActive() == 0) {
        return;
    }
    ResetTextLabelSlotsPartial();
    if (arg0 == 0) {
        MapSettings_Randomize(0);
        M2C_FIELD(*gCurrentMap, u8 *, 0x5141) = 2;
        SetPlayerIdForSlot(1, 1);
        SetPlayerIdForSlot(2, 2);
        SetPlayerIdForSlot(3, 3);
        SetPlayerIdForSlot(4, 4);
        SetPlayerArmyId(1, 1);
        SetPlayerArmyId(2, 2);
        SetPlayerArmyId(3, 3);
        SetPlayerArmyId(4, 4);
    }
    ApplyMapSettingsToPlayers(0);
    MI_CpuFill32(0, sp, 0x24);
    r5 = 0;
    do {
        r6 = sp + r5;
        r6[0xe] = (u8)GetPlayerArmyId(r5 + 1);
        r6[0x12] = (u8)GetPlayerCoIconIndex(GetPlayerCoId(r5 + 1) & 0xFF);
        r5 = (u8)(r5 + 1);
    } while (r5 < 4);
    sp[0xd] = (u8)GetPlayerCoIconIndex(GetPlayerCoId(func_0208492c() + 1) & 0xFF);
    Link_SendPacket(sp, 0x24);
}

/* Maps a CO id to its index in the CO icon strip: ids 1..12 use icons 0..11 in
   order and the random/unset id 0 uses the last icon.  Any other id has no icon. */
s32 GetPlayerCoIconIndex(u32 coId) {
    switch (coId) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    case 10: return 9;
    case 11: return 10;
    case 12: return 11;
    case CO_ID_RANDOM: return CO_ICON_RANDOM;
    default: return CO_ICON_NONE;
    }
}

/* CO id (1..12) of a waypoint-panel CO option: option 12 is the random choice,
   whose CO id is 0, and any other option has no CO. */
s32 GetWaypointOptionCoId(u32 option) {
    switch (option) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    case 4: return 5;
    case 5: return 6;
    case 6: return 7;
    case 7: return 8;
    case 8: return 9;
    case 9: return 10;
    case 10: return 11;
    case 11: return 12;
    case WAYPOINT_OPTION_RANDOM: return 0;
    default: return WAYPOINT_CO_NONE;
    }
}

/* Icon frame index of a map-list icon id: ids 0..12 map to themselves and any
   other id falls back to frame 0. */
s32 GetMapIconFrameIndex(u32 iconId) {
    switch (iconId) {
    case 3: return 3;
    case 4: return 4;
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 10: return 10;
    case 11: return 11;
    case 12: return 12;
    default: return 0;
    }
}

/* Icon tile a map-list row of `kind` uses for map `id`.  The map's player count
 * picks between the two-, three- and four-player icons (kinds 2 and 3 give one
 * group, 7 to 11 the map-record group), and a campaign map record that is not
 * playable keeps the "unavailable" icon 13. */
u16 GetMapListIconTile(u32 kind, M2C_UNK id) {
s32 IsCampaignMapRecordPlayable(M2C_UNK); s32 IsLocalCampaignMapRecord(M2C_UNK); s32 GetMapPlayerCount(M2C_UNK);
s32 players=GetMapPlayerCount(id);s32 tile;
switch(kind){case 1:return 3;case 3:return players+2;case 4:return 0;case 5:return 1;case 6:return 2;case 2:return players+5;case 7:case 8:case 9:case 10:case 11:if(!IsCampaignMapRecordPlayable(id))return 13;tile=IsLocalCampaignMapRecord(id)?players+8:players+12;return (u16)tile;default:case 0:break;}return 0;
}

s32 GetIconGridRecordIndex(u32 a){switch(a){case 0:return 0;case 1:return 1;case 2:return 2;case 3:return 3;case 4:return 4;case 5:return 7;case 6:return 9;case 7:return 8;default:return -1;}}

s32 func_ov003_02200b5c(u32 a){switch(a){case 0:return 15;case 1:return 16;case 2:return 17;case 3:return 18;case 4:return 19;case 5:return 22;case 6:return 23;case 7:return 24;default:return -1;}}

/* Translate a map record's kind byte (2..11) into the map-list icon id the
 * row draws, then resolve that id to its icon frame index. */
s32 GetMapKindIconFrameIndex(u32 kind) {
    M2C_UNK GetMapIconFrameIndex(u32);
    u32 iconId;

    iconId = kind;
    switch (iconId) {
    default:
        break;
    case 3:
        iconId = 4;
        break;
    case 4:
        iconId = 0;
        break;
    case 5:
        iconId = 1;
        break;
    case 6:
        iconId = 2;
        break;
    case 2:
        iconId = 6;
        break;
    case 7:
        iconId = 5;
        break;
    case 8:
        iconId = 8;
        break;
    case 9:
        iconId = 9;
        break;
    case 10:
        iconId = 0xA;
        break;
    case 11:
        iconId = 0xB;
        break;
    }
    return GetMapIconFrameIndex(iconId);
}

u8 func_ov003_02200c64(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_02200c7c(void) {
    s32 IsLinkSessionActive();
    s32 func_0208485c();
    s32 result;
    if (IsLinkSessionActive() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_02200ca8(void) {
    s32 IsLinkSessionActive();
    s32 func_02084890();
    s32 result;
    if (IsLinkSessionActive() && func_02084890()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_02200cd4(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

/* Icon tile offset of a setup-menu entry's value: the value indexes the icon
 * table of the entry's kind (kinds 0 and 7 share one), and the tile index is
 * returned in 16-byte units.  Kinds without a table keep the value as it is. */
u16 Ov003_GetEntryValueIconTile(u32 kind, u16 value) {
    extern u16 gOv003EntryIconTableKind0[];
    extern u16 gOv003EntryIconTableKind1[];
    extern u16 gOv003EntryIconTableKind2[];
    extern u16 gOv003EntryIconTableKind6[];
    switch (kind) {
    case 0: value = gOv003EntryIconTableKind0[value]; break;
    case 1: value = gOv003EntryIconTableKind1[value]; break;
    case 2: value = gOv003EntryIconTableKind2[value]; break;
    case 6: value = gOv003EntryIconTableKind6[value]; break;
    case 7: value = gOv003EntryIconTableKind0[value]; break;
    default: break;
    }
    return (u16)(value << 4);
}

s32 Ov003_GetEntryValueTextId(s32 a, s32 b) {
    extern s32 data_ov003_022104a4[], data_ov003_022104b4[], data_ov003_02210494[];
    switch (a) {
    case 1:
        b = data_ov003_022104b4[b];
        break;
    case 2:
        b = data_ov003_02210494[b];
        break;
    case 6:
        b = data_ov003_022104a4[b];
        break;
    default:
        break;
    }
    return b;
}

void func_ov003_02200dc8(void *a,u32 b) {
s32 Modulo(u8,s32);
s32 FindObjectByZ(u32);
u8 v;s32 n;
if(b<8)M2C_FIELD(a,u8 *,6)=b;
else if(b==8){
v=Modulo(M2C_FIELD(a,u8 *,6),4);
n=v+4;
M2C_FIELD(M2C_FIELD(&((u8 *)a)[b*4],void **,0xe8),s16 *,0x68)=n;
M2C_FIELD(M2C_FIELD(&((u8 *)a)[b*4],void **,0xe8),s16 *,0x6a)=v;
}
M2C_FIELD(a,s32 *,0x10c)=FindObjectByZ(b);
}

/* Animate the ov003 setup menu's nine entry sprites and latch, for this frame,
 * the entry whose owner reports a click (SETUP_MENU_CLICKED) and the entry
 * showing its base frame advanced by one, i.e. mid press (SETUP_MENU_PRESSED). */
void Ov003_UpdateSetupMenuButtons(void *menu) {
    M2C_UNK MenuSpriteUpdate(s32);
    s32 clicked;
    s32 pressed;
    u8 index;
    void *sprite;
    void *owner;

    M2C_FIELD(menu, s8 *, SETUP_MENU_CLICKED) = -1;
    M2C_FIELD(menu, s8 *, SETUP_MENU_PRESSED) = -1;
    index = 0;
    do {
        MenuSpriteUpdate(M2C_FIELD((void *)((u8 *) menu + (index * 4)), s32 *, SETUP_MENU_SLOTS));
        sprite = M2C_FIELD((menu + (index * 4)), void **, SETUP_MENU_SLOTS);
        clicked = 1;
        owner = M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER);
        if ((M2C_FIELD(owner, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(owner, s8 *, 0xC) != 1))) {
            clicked = 0;
        }
        if (clicked & 0xFF) {
            M2C_FIELD(menu, u8 *, SETUP_MENU_CLICKED) = index;
        }
        sprite = M2C_FIELD(&((u8 *) menu)[index * 4], void **, SETUP_MENU_SLOTS);
        if ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(sprite, s32 *, 0x40) << 6) >> 0x18)) {
            pressed = 1;
        } else {
            pressed = 0;
        }
        if (pressed & 0xFF) {
            M2C_FIELD(menu, u8 *, SETUP_MENU_PRESSED) = index;
        }
        index += 1;
    } while ((u32) index < 9U);
}

