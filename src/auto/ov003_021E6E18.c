/* 15 functions from 0x021E6E18 to 0x021E771C (ov003), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "sprite_grid.h"
#include "waypoint_panel.h"
s32 IsSessionHost(void);
s32 IsSessionGuest(void);
s32 GetLocalPlayerIdForOverlay(void);
s32 IsWaypointOptionValid(s32);
static inline u8 SlotOwner(void *p, s32 i) {return M2C_FIELD(p+i,u8 *,0x74);}
static inline u8 SlotEmpty(void *p,s32 i) {u8 result;if(SlotOwner(p,i)==255)result=1;else result=0;return result;}
static inline void SetSlotValue(void *p,u8 v) {
u8 owner;
if(IsSessionHost()) {owner=SlotOwner(p,M2C_FIELD(p,u8 *,7));if(owner!=GetLocalPlayerIdForOverlay() && !SlotEmpty(p,M2C_FIELD(p,u8 *,7)))goto store;}
if(IsSessionGuest()) {owner=SlotOwner(p,M2C_FIELD(p,u8 *,7));if(owner!=GetLocalPlayerIdForOverlay())goto store;}
if(!IsWaypointOptionValid(v))return;
store:
M2C_FIELD(p+M2C_FIELD(p,u8 *,7),u8 *,10)=v;M2C_FIELD(p,u8 *,8)=v;
}
static inline void SelectSlot(void *p,u8 i) {M2C_FIELD(p,u8 *,7)=i;SetSlotValue(p,M2C_FIELD(p+i,u8 *,10));}

u8 GetWaypointGroupCount(void) {
    void *GetWaypointSlotGroup();
    return M2C_FIELD(GetWaypointSlotGroup(), u8 *, 1);
}

/* Index of waypoint-list slot `slot` within its slot group: the slot number
 * minus the group's first slot. */
u8 GetWaypointSlotIndexInGroup(s32 slot) {
    s32 GetWaypointGroupFirstSlot();
    return (u8) (slot - GetWaypointGroupFirstSlot());
}

/* TRUE while the map-select list shows category 3, one of the campaign map groups
 * (see IsCampaignMapListCategory); the waypoint panel uses it to hide the last
 * per-CO option in a campaign list. */
u8 IsMapListCategory3(void) {
    s32 GetMapListCategory();
    u8 isCategory3;

    if (GetMapListCategory() == 3) {
        isCategory3 = 1;
    } else {
        isCategory3 = 0;
    }
    return isCategory3;
}

/* True while the map-select scene's map-list category is one of the campaign
 * groups (category 1, 3 or 5), i.e. the groups whose slots come from the cached
 * campaign map headers. */
s32 IsCampaignMapListCategory(void) {
    if ((GetMapListCategory() == 3) || (GetMapListCategory() == 1) || (GetMapListCategory() == 5)) {
        return 1;
    }
    return 0;
}

/* Description text key of waypoint-panel CO option `option` (0 .. 12). */
s32 GetWaypointOptionTextId(s32 option) {
    M2C_UNK InRange(s32, M2C_UNK, M2C_UNK);
    extern s32 gWaypointOptionTextIds[][2];
    InRange(option, 0, WAYPOINT_OPTION_COUNT);
    return gWaypointOptionTextIds[option][0];
}

/* Whether the waypoint panel may offer CO option `option`: the Random option is
 * always valid, a category-3 map list never offers the last per-CO option, and
 * any other option needs the CO it picks to be unlocked. */
s32 IsWaypointOptionValid(s32 option) {
    s32 IsCoUnlocked();
    M2C_UNK GetWaypointOptionCoId(s32);
    if (option == WAYPOINT_OPTION_RANDOM) {
        return 1;
    }
    if ((IsMapListCategory3() != 0) && (option == WAYPOINT_OPTION_LAST_CO)) {
        return 0;
    }
    GetWaypointOptionCoId(option);
    return IsCoUnlocked();
}

/* Handle one input action on the waypoint/segment cursor menu: move the cursor
 * over the slot groups (previous/next), place the currently held unit into a
 * slot, or scroll the map view. The selected action is then passed to the
 * display refresh (FindObjectByZ) and stored as the list's current handle. */
void HandleWaypointInput(void *arg0,int action){
s32 IsSessionHost(void);s32 IsSessionGuest(void);s32 GetLocalPlayerIdForOverlay(void);s32 IsLinkSessionActive(void);
s32 FindObjectByZ(s32);
u8 *list=arg0;
switch((u32)action){
case 0:case 1:case 2:case 3:SelectSlot(list,action);break;
case 27:action=list[7];break;
case 4:case 5:case 6:case 7:SelectSlot(list,action-4);break;
case 28:action=(u16)(list[7]+4);break;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:
if(IsLinkSessionActive()){
s32 canUseSlot;u8 slot=list[7];
if(!IsLinkSessionActive())canUseSlot=0;
else {u8 *owners=list+0x74;u8 owner=owners[slot];if(owner==GetLocalPlayerIdForOverlay())canUseSlot=1;else if(IsSessionHost() && ((u8)(owners[slot]==255)))canUseSlot=1;else canUseSlot=0;}
if(!canUseSlot){
s32 playerId=GetLocalPlayerIdForOverlay();u8 i; s32 foundSlot;
for(i=0;i<list[4];i++){if(playerId==M2C_FIELD(list+i,u8 *,0x74)){foundSlot=(s8)i;goto found_slot;}}
foundSlot=-1;
found_slot:SelectSlot(list,foundSlot);
}}
SetSlotValue(list,action-8);
break;
case 29:action=(u16)(list[8]+8);break;
case 21:case 22:case 23:case 24:SelectSlot(list,action-21);break;
case 30:action=(u16)(list[7]+21);break;
case 25:M2C_FIELD(M2C_FIELD(list,void **,0xdc),u16 *,0x68)=list[0xe4]+list[7];M2C_FIELD(M2C_FIELD(list,void **,0xdc),u16 *,0x6a)=list[0xe5]+list[7];break;
}
M2C_FIELD(list,s32 *,0xe0)=FindObjectByZ(action);
}

u8 GetWaypointSlotOwner(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0x74);
}

/* Whether waypoint-list slot `slot` has no player assigned to it yet (its owner
 * byte is WAYPOINT_NO_PLAYER). */
u8 IsWaypointSlotEmpty(s32 list, s32 slot) {
    u8 empty;

    if (M2C_FIELD((list + slot), u8 *, WAYPOINT_LIST_IDS) == WAYPOINT_NO_PLAYER) {
        empty = 1;
    } else {
        empty = 0;
    }
    return empty;
}

u8 GetWaypointSlotIndex(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 7);
}

/* Whether the waypoint list's slot belongs to the local player: the slot's owner
 * must be the local player, or (for the session host only) the slot must still be
 * empty.  Always 0 outside a link session. */
s32 IsWaypointSlotLocalPlayer(s32 list, s32 slot) {
    s32 IsLinkSessionActive();
    s32 GetLocalPlayerIdForOverlay();
    s32 IsSessionHost();
    u8 *owners;
    u8 owner;
    s32 noOwner;
    if (IsLinkSessionActive() == 0) return 0;
    owners = (u8 *)(list + WAYPOINT_LIST_IDS);
    owner = owners[slot];
    if (owner == GetLocalPlayerIdForOverlay()) return 1;
    if (IsSessionHost() != 0) {
        if (owners[slot] == WAYPOINT_NO_PLAYER) noOwner = 1;
        else noOwner = 0;
        if (noOwner & 0xFF) return 1;
    }
    return 0;
}

u8 func_ov003_021e7450(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 8);
}

/* Ov003 waypoint-list slot update: refresh the slot sprite's cell while the slot
 * lies in the used range [groupFirst, groupFirst + count), and otherwise drop the
 * slot's sub-cell so an unused slot shows nothing. */
void RefreshWaypointSlotSprite(void *list, s32 slot, s32 groupFirst) {
    M2C_UNK RemoveSpriteCell(void *, M2C_UNK);
    M2C_UNK func_020aad18(void *);
    s32 active;
    s32 count;
    void *sprite;
    count = M2C_FIELD(list, s8 *, WAYPOINT_LIST_COUNT);
    sprite = M2C_FIELD(list + slot * 4, void **, WAYPOINT_LIST_SLOTS);
    if (slot < groupFirst + count) {
        func_020aad18(sprite);
        return;
    }
    sprite = M2C_FIELD(sprite, void **, DS3D_SPRITE_CELLS);
    if (M2C_FIELD(sprite, u8 *, SPRITE_CELL_LIST_USED) != 0) active = 1;
    else active = 0;
    if (!(active & 0xFF)) return;
    RemoveSpriteCell(sprite, 1);
}

s8 func_ov003_021e74a4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 4);
}

/* Re-initialize a 26-slot waypoint/segment list. Each slot (p+i*4, +0x78) is a
 * segment; seg+0x64 is its sub-object whose +0x12 entry count tells whether it
 * is active. In mode 0 (path), slots 0-20 are (re)built for the current path
 * state (RefreshWaypointSlotSprite) or cleared (func_020aad18), and slots 21-25 are
 * released if active; in mode 1 (grid), slots 0-20 are released and 21-25 built.
 * The list's head/tail next-pointers are re-linked to the active range, then the
 * display is refreshed (HandleWaypointInput). */
void SetWaypointListLayout(void *list, s32 mode) {
    s32 IsLinkSessionActive(void);
    M2C_UNK RemoveSpriteCell(void *, M2C_UNK);
    M2C_UNK func_020aad18(void *);
    s32 InRange(s32, s32, s32);
    void HandleWaypointInput(void *, s32);
    u32 i;
    u32 j;
    s32 active;
    void *sub;

    switch (mode) {
    case 0:
        if (IsLinkSessionActive() != 0) M2C_FIELD(list, s8 *, 0xe4) = 0;
        else M2C_FIELD(list, s8 *, 0xe4) = 4;
        M2C_FIELD(list, s8 *, 0xe5) = 0;
        i = 0;
        do {
            if (!InRange(i, 21, 24)) {
                if (InRange(i, 0, 3)) RefreshWaypointSlotSprite(list, i, 0);
                else if (InRange(i, 4, 7)) RefreshWaypointSlotSprite(list, i, 4);
                else func_020aad18(M2C_FIELD(list + i * 4, void **, 0x78));
            } else {
                sub = M2C_FIELD(M2C_FIELD(list + i * 4, void **, 0x78), void **, 0x64);
                if (M2C_FIELD(sub, u8 *, 0x12)) active = 1;
                else active = 0;
                if (active & 255) RemoveSpriteCell(sub, 1);
            }
            i = (u8)(i + 1);
        } while (i < 26);
        M2C_FIELD(M2C_FIELD(list, void **, 0x78), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) - 1;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) - 1) * 4, void **, 0x78), s16 *, 0x6e) = 0;
        M2C_FIELD(M2C_FIELD(list, void **, 0x88), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 3;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) + 3) * 4, void **, 0x78), s16 *, 0x6e) = 4;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) - 1;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6e) = 0;
        break;
    case 1:
        M2C_FIELD(list, s8 *, 0xe5) = 21;
        j = 0;
        M2C_FIELD(list, s8 *, 0xe4) = 21;
        do {
            if (j >= 21) {
                if (InRange(j, 21, 24)) RefreshWaypointSlotSprite(list, j, 21);
                else func_020aad18(M2C_FIELD(list + j * 4, void **, 0x78));
            } else {
                sub = M2C_FIELD(M2C_FIELD(list + j * 4, void **, 0x78), void **, 0x64);
                if (M2C_FIELD(sub, u8 *, 0x12)) active = 1;
                else active = 0;
                if (active & 255) RemoveSpriteCell(sub, 1);
            }
            j = (u8)(j + 1);
        } while (j < 26);
        M2C_FIELD(M2C_FIELD(list, void **, 0xcc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 20;
        M2C_FIELD(M2C_FIELD(list + (M2C_FIELD(list, s8 *, 4) + 20) * 4, void **, 0x78), s16 *, 0x6e) = 21;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6c) = M2C_FIELD(list, s8 *, 4) + 20;
        M2C_FIELD(M2C_FIELD(list, void **, 0xdc), s16 *, 0x6e) = 21;
        break;
    }
    HandleWaypointInput(list, 25);
}

