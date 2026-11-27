/* 9 functions from 0x021E8654 to 0x021E9638 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_menu.h"
#include "waypoint_panel.h"

extern u16 data_ov003_0220f890;
extern u16 data_ov003_0220f892;
extern u16 data_ov003_0220f88e;
extern u16 data_ov003_0220f88c;
extern u16 data_ov003_0220f894;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineSub;
extern void *g3DSpriteEngineMain;
extern u8 data_ov003_0220fb84[];
extern u8 data_ov003_0220fb8c[];
extern u8 data_ov003_0220fb94[];
extern u8 data_ov003_0220fbac[];
extern u8 data_ov003_0220fbc0[];
extern u8 data_ov003_0220fbd0[];
extern u8 data_ov003_0220fbe4[];
extern u8 data_ov003_0220fbec[];
extern u8 data_ov003_0220fc00[];
extern u8 data_ov003_0220fc1c[];
extern u8 data_ov003_0220fc30[];
extern u8 data_ov003_0220fc38[];
extern u8 data_ov003_0220fc50[];
extern u8 data_ov003_0220fc60[];

/* Advances an options-menu counter by delta: the new value is kept when it lands
   in [minimum,maximum] (compared as 16-bit) or when force is set, otherwise the
   counter moves to the bound it overshot; afterwards the value either wraps
   around the range (when the wrap flag is set) or clamps into it. */
void StepCounter(OptionCounter *p, s32 delta, s32 force) {
    s32 InRange(s16,s16,s16);
    s32 next = delta + p->value;
    if (InRange((s16)next, (s16)p->minimum, (s16)p->maximum) || force) {
        p->value = next;
        if (p->wrap) {
            while (p->value > p->maximum)
                p->value -= p->maximum - p->minimum + 1;
            while (p->value < p->minimum)
                p->value += p->maximum - p->minimum + 1;
        } else {
            s32 x = p->value, hi = p->maximum;
            if (x <= hi) { hi = p->minimum; if (x >= hi) hi = x; }
            p->value = hi;
        }
    } else {
        s32 x = p->maximum;
        if (next <= x) { x = p->minimum; if (next >= x) x = next; }
        p->value = x;
        if (p->wrap) {
            while (p->value > p->maximum)
                p->value -= p->maximum - p->minimum + 1;
            while (p->value < p->minimum)
                p->value += p->maximum - p->minimum + 1;
        } else {
            s32 x = p->value, hi = p->maximum;
            if (x <= hi) { hi = p->minimum; if (x >= hi) hi = x; }
            p->value = hi;
        }
    }
}

void func_ov003_021e87d0(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x34) = arg1;
    M2C_FIELD(arg0, s16 *, 0x36) = arg2;
}

/* Animate the ov003 waypoint list's 26 slot sprites and latch, for this frame,
 * the slot whose owner reports a click (WAYPOINT_LIST_CLICKED) and the slot
 * showing its base frame advanced by one, i.e. mid press (WAYPOINT_LIST_PRESSED). */
void Ov003_UpdateWaypointSlotButtons(void *list) {
    M2C_UNK MenuSpriteUpdate(s32);
    s32 clicked;
    s32 pressed;
    u8 index;
    void *sprite;
    void *owner;

    M2C_FIELD(list, s8 *, WAYPOINT_LIST_CLICKED) = -1;
    M2C_FIELD(list, s8 *, WAYPOINT_LIST_PRESSED) = -1;
    index = 0;
    do {
        MenuSpriteUpdate(M2C_FIELD((void *)((u8 *) list + (index * 4)), s32 *, WAYPOINT_LIST_SLOTS));
        sprite = M2C_FIELD((list + (index * 4)), void **, WAYPOINT_LIST_SLOTS);
        clicked = 1;
        owner = M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER);
        if ((M2C_FIELD(owner, s8 *, 0xB) != 1) && ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(owner, s8 *, 0xC) != 1))) {
            clicked = 0;
        }
        if (clicked & 0xFF) {
            M2C_FIELD(list, u8 *, WAYPOINT_LIST_CLICKED) = index;
        }
        sprite = M2C_FIELD(&((u8 *) list)[index * 4], void **, WAYPOINT_LIST_SLOTS);
        if ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(sprite, s32 *, 0x40) << 6) >> 0x18)) {
            pressed = 1;
        } else {
            pressed = 0;
        }
        if (pressed & 0xFF) {
            M2C_FIELD(list, u8 *, WAYPOINT_LIST_PRESSED) = index;
        }
        index += 1;
    } while ((u32) index < 0x1AU);
}

/* Whether a menu sprite reads as clicked this frame: its owner's press flag
 * (+0x0B) is set, or the sprite shows its alternate (pressed) frame and the
 * owner's alternate press flag (+0x0C) is set. */
u8 MenuSpriteIsClicked(void *sprite) {
    s32 clicked = 1;
    void *owner = M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER);
    if (M2C_FIELD(owner, s8 *, 0xb) != 1
        && ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 27) >> 31) == 0)
            || M2C_FIELD(owner, s8 *, 0xc) != 1))
        clicked = 0;
    return clicked;
}

/* Tell the peers that this player opened the waypoint panel: take the shared
 * panel packet, raise its "opened" word and send it back out. */
void SendWaypointPanelOpened(void) {
    s32 Link_ReceivePacket(s32 *, M2C_UNK);
    M2C_UNK Link_SendPacket(s32 *, M2C_UNK);
    s32 packet[9];

    if (Link_ReceivePacket(packet, 0x24) == 0) return;
    M2C_FIELD(packet, s32 *, WAYPOINT_PACKET_OPENED) = 1;
    Link_SendPacket(packet, 0x24);
}

/* Reply to the waypoint panel's close: receive the shared 0x24-byte panel
 * packet, set its word 1 (the panel-closed flag) and send the packet back. */
void SendWaypointPanelClosed(void) {
    s32 Link_ReceivePacket(s32 *, M2C_UNK);
    M2C_UNK Link_SendPacket(s32 *, M2C_UNK);
    s32 packet[9];

    if (Link_ReceivePacket(packet, 0x24) == 0) return;
    packet[1] = 1;
    Link_SendPacket(packet, 0x24);
}

void func_ov003_021e8958(void *arg0) {
    void SetWaypointPanelTwoPlayer(void *, s32);
    void func_ov003_021e8f98(void *, s32);
    s32 GetCurrentMapPlayerCount(void *);
    void SetSceneLayerOverrideMain(s32, void *);
    void SetSceneLayerOverrideSub(s32, void *);
    void Apply3DSpriteBanks(void);
    void func_ov003_021e771c(void *, void *);
    void CreateWaypointPanelSprites(void *, void *);
    void *CreateFrameBorderSprite(void *);
    void LoadFrameBorderSpritePattern(void *, s32, s32);
    void SetSpriteActorPositionAndSize(void *, s32, s32, s32, s32);
    void Sync3DSpriteToTarget(void *);
    void func_ov003_021e97fc(void *, s32);
    void func_ov003_021e9804(void *);
    s32 Hide3DSprite(void *);
    void *CreateScrollingTextSprite(void *);
    void func_ov003_021e9810(void *, s32);
    void SetSpriteActorPaletteRow(void *, s32);
    s32 IsMapListCategory3(void);
    void *CreateTimerDisplay(void *);
    void SetTimerDisplayGraphics(void *, s32, s32);
    void SetTimerDisplayTicks(void *, s32);
    s32 GetSceneEntryOffset(void);
    void SetSpriteTweenValue(void *, s32);
    s32 IsLinkSessionActive(void);
    void *GetLocalNetworkPlayerRecord(void);
    void SetWaypointPanelMode(void *, s32);
    s32 IsWaypointPanelNotTwoPlayer(void *);
    void SetWaypointPanelState(void *, s32);
    void PlaceWaypointPanelCursor(void *);
    s32 GetWaypointSlotIndex(void *);
    s32 func_ov003_021e7450(void *);
    void InitWaypointOptionState(void *, s32, s32);
    void func_ov003_021e9eb4(void *);
    void DrawWaypointOption(void *);
    void SetFileDirectory(void *);
    void Clear3DSpriteLayer(s32);
    s32 func_ov003_021e9c24(void *);
    void Ov003_LoadPlayerSelectBg(s32, s32, s32);
    void Mark3DSpriteLayerDirty(s32);
    void LoadFaceTexture(s32, s32, s32);
    void LoadFaceTextureAndPalette(s32, s32, s32);
    void LoadSpriteImage(s32, s32, s32);
    void LoadSpritePalette(s32, s32, s32);
    void *GetLocalizedFileName(void *);
    void *LoadFileToBuffer(void *, s32);
    void LoadGraphicsBlock(void *, s32);
    void HeapFreeBlock(void *);
    void LoadDecompressedFileTo(void *, s32);
    void LoadFileToSpriteBuffer(void *, s32, s32);
    void Reset3DSpriteBankDisplay(void);
    void SetTileRectPalette(s32, s32, s32, s32);
    void LoadScenePanelPalette(s32);
    s32 t1;
    s32 t2;
    s32 v;
    s32 t3;
    void *p;
    u8 i;
    u8 *h;

    if (GetCurrentMapPlayerCount(arg0) == 2) SetWaypointPanelTwoPlayer(arg0, 1);
    SetSceneLayerOverrideMain(3, &data_ov003_0220f890);
    SetSceneLayerOverrideMain(0, &data_ov003_0220f892);
    SetSceneLayerOverrideMain(1, &data_ov003_0220f88e);
    SetSceneLayerOverrideSub(0, &data_ov003_0220f88c);
    SetSceneLayerOverrideSub(3, &data_ov003_0220f894);
    Apply3DSpriteBanks();
    func_ov003_021e771c(M2C_FIELD(arg0, void **, 0x6c), arg0);
    func_ov003_021e8f98(M2C_FIELD(arg0, void **, 0x64), arg0);
    CreateWaypointPanelSprites(M2C_FIELD(arg0, void **, 0x68), arg0);
    M2C_FIELD(arg0, void **, 0x58) = CreateFrameBorderSprite(arg0);
    LoadFrameBorderSpritePattern(M2C_FIELD(arg0, void **, 0x58), 0xb000, 0xa);
    SetSpriteActorPositionAndSize(M2C_FIELD(arg0, void **, 0x58), 0xa, 0x10, 0x38, 0x38);
    Sync3DSpriteToTarget(M2C_FIELD(arg0, void **, 0x58));
    func_ov003_021e97fc(M2C_FIELD(arg0, void **, 0x58), 1);
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x58));
    M2C_FIELD(arg0, void **, 0x5c) = CreateFrameBorderSprite(arg0);
    LoadFrameBorderSpritePattern(M2C_FIELD(arg0, void **, 0x5c), 0xb400, 0xa);
    SetSpriteActorPositionAndSize(M2C_FIELD(arg0, void **, 0x5c), 0x38, 0x10, 0x38, 0x38);
    Sync3DSpriteToTarget(M2C_FIELD(arg0, void **, 0x5c));
    func_ov003_021e97fc(M2C_FIELD(arg0, void **, 0x5c), 1);
    func_ov003_021e9804(M2C_FIELD(arg0, void **, 0x5c));
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x5c));
    t1 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    M2C_FIELD(arg0, void **, 0x54) = CreateScrollingTextSprite(arg0);
    func_ov003_021e9810(M2C_FIELD(arg0, void **, 0x54), 0x180);
    SetSpriteActorPaletteRow(M2C_FIELD(arg0, void **, 0x54), 7);
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x54));
    gCur3DSpriteEngine = t1;
    if (IsMapListCategory3()) {
        t2 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        M2C_FIELD(arg0, void **, 0x60) = CreateTimerDisplay(arg0);
        SetTimerDisplayGraphics(M2C_FIELD(arg0, void **, 0x60), 0xd400, 0xb);
        SetTimerDisplayTicks(M2C_FIELD(arg0, void **, 0x60), 0x708);
        func_ov003_021e87d0(M2C_FIELD(arg0, void **, 0x60), 0, 0xb6);
        gCur3DSpriteEngine = t2;
    }
    v = GetSceneEntryOffset();
    SetSpriteTweenValue(M2C_FIELD(arg0, s32 *, 0x48), v);
    SetSpriteTweenValue(M2C_FIELD(arg0, s32 *, 0x50), v);
    SetSpriteTweenValue(M2C_FIELD(arg0, s32 *, 0x4c), 0xc0);
    if (IsLinkSessionActive()) {
        p = GetLocalNetworkPlayerRecord();
        if (p == 0) return;
        SetWaypointPanelMode(arg0, M2C_FIELD(p, u8 *, 8));
    } else if (IsWaypointPanelNotTwoPlayer(arg0) && v == (s32) 0xFFFFFF00) {
        SetWaypointPanelMode(arg0, 1);
    } else {
        SetWaypointPanelMode(arg0, 0);
    }
    SetWaypointPanelState(arg0, 0);
    PlaceWaypointPanelCursor(arg0);
    Sync3DSpriteToTarget(M2C_FIELD(arg0, void **, 0x58));
    Sync3DSpriteToTarget(M2C_FIELD(arg0, void **, 0x5c));
    {
        s32 a = GetWaypointSlotIndex(M2C_FIELD(arg0, void **, 0x6c));
        s32 b = func_ov003_021e7450(M2C_FIELD(arg0, void **, 0x6c));
        InitWaypointOptionState(M2C_FIELD(arg0, s32 *, 0x40), a, b);
    }
    func_ov003_021e9eb4(arg0);
    DrawWaypointOption(arg0);
    t3 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    SetFileDirectory(data_ov003_0220fb84);
    Clear3DSpriteLayer(3);
    Ov003_LoadPlayerSelectBg(3, 0, func_ov003_021e9c24(arg0) & 0xff);
    Mark3DSpriteLayerDirty(3);
    for (i = 0; i < 12; i++) LoadFaceTexture(i + 1, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc) + (((i << 7) + 2) << 5));
    for (i = 0; i < 13; i++) LoadFaceTextureAndPalette(i, ((i << 4) + 0x1f0) << 5, 7);
    LoadSpriteImage(4, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x3400);
    LoadSpritePalette(5, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2c0);
    SetFileDirectory(data_ov003_0220fb8c);
    h = LoadFileToBuffer(GetLocalizedFileName(data_ov003_0220fb94), 1);
    LoadGraphicsBlock(h + 0x254, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xa400);
    LoadGraphicsBlock(h + 0x460, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xa800);
    LoadGraphicsBlock(h + 0x568, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xac00);
    LoadGraphicsBlock(h + 0x164, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xb800);
    LoadGraphicsBlock(h + 0x92c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xc000);
    LoadGraphicsBlock(h + 0x67c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xc400);
    LoadGraphicsBlock(h + 0x9c8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xd000);
    HeapFreeBlock(h);
    h = LoadFileToBuffer(GetLocalizedFileName(data_ov003_0220fbac), 1);
    LoadGraphicsBlock(h + 0x92c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xcc00);
    HeapFreeBlock(h);
    LoadDecompressedFileTo(data_ov003_0220fbc0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0xbc00);
    LoadFileToSpriteBuffer(data_ov003_0220fbd0, 0x300, 0x40);
    Reset3DSpriteBankDisplay();
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    SetFileDirectory(data_ov003_0220fbe4);
    Clear3DSpriteLayer(0);
    LoadDecompressedFileTo(GetLocalizedFileName(data_ov003_0220fbec), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xc));
    LoadDecompressedFileTo(GetLocalizedFileName(data_ov003_0220fc00), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
    LoadFileToSpriteBuffer(data_ov003_0220fc1c, 0, 0x20);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x20, 0x20, 0);
    Mark3DSpriteLayerDirty(0);
    LoadScenePanelPalette(2);
    SetFileDirectory(data_ov003_0220fc30);
    h = LoadFileToBuffer(GetLocalizedFileName(data_ov003_0220fc38), 1);
    LoadGraphicsBlock(h, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x2800);
    HeapFreeBlock(h);
    LoadDecompressedFileTo(data_ov003_0220fc50, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1c) + 0x2c00);
    LoadFileToSpriteBuffer(data_ov003_0220fc60, 0x2c0, 0x20);
    Reset3DSpriteBankDisplay();
    gCur3DSpriteEngine = t3;
}

/* Set the waypoint panel's two-player flag (bit 0 of the packed panel flags)
 * for a map that has two players. */
void SetWaypointPanelTwoPlayer(void *panel, s32 twoPlayer) {
    M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS) =
        (u8) ((M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS) & ~WAYPOINT_PANEL_TWO_PLAYER)
            | (twoPlayer & WAYPOINT_PANEL_TWO_PLAYER));
}

#pragma opt_common_subs off
#pragma opt_propagation on
void func_ov003_021e8f98(void *arg0, M2C_UNK arg1) {
    M2C_UNK SpriteCellListSetCellRect(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088da8(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, s32, M2C_UNK, s32, s32);
    M2C_UNK func_020aab24(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020aad18(void *);
    u32 func_020aae10(void *);
    u32 func_020aae44(void *);
    void *CreateUnitSprite(M2C_UNK);
    s32 GetWaypointSlotX(u8);
u8 i; s32 pos, left; s32 hidden; 
M2C_FIELD(arg0,void**,0)=CreateUnitSprite(arg1);func_020aab24(M2C_FIELD(arg0,void**,0),2,344,3,1);{ void *p=M2C_FIELD(arg0,void**,0);Set3DSpriteSlideTargetAndStart(p,224,160,224,192);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_020aad18(M2C_FIELD(arg0,void**,0));func_02088da8(M2C_FIELD(arg0,void**,0)); }M2C_FIELD(arg0,void**,4)=CreateUnitSprite(arg1);func_020aab24(M2C_FIELD(arg0,void**,4),31,320,3,0);{ void *p=M2C_FIELD(arg0,void**,4);Set3DSpriteSlideTargetAndStart(p,96,164,96,192);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_020aad18(M2C_FIELD(arg0,void**,4));func_02088da8(M2C_FIELD(arg0,void**,4)); }hidden=-32;i=0;do{pos=GetWaypointSlotX(i);{ void *created=CreateUnitSprite(arg1);M2C_FIELD(arg0+i*4,void**,8)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,8),23,360,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,8);left=(s16)(pos-1);Set3DSpriteSlideTargetAndStart(p,left,72,left,72);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=left;M2C_FIELD(p,s16*,0x36)=72;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,8)); }{ void *created=CreateUnitSprite(arg1);M2C_FIELD(arg0+i*4,void**,24)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,24),24,364,3,0);pos=(s16)(pos+40);{ void *p=M2C_FIELD(arg0+i*4,void**,24);Set3DSpriteSlideTargetAndStart(p,pos,72,pos,72);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=pos;M2C_FIELD(p,s16*,0x36)=72;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,24)); }{ void *created=CreateUnitSprite(arg1);M2C_FIELD(arg0+i*4,void**,40)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,40),8,368,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,40);Set3DSpriteSlideTargetAndStart(p,hidden,0,hidden,0);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=hidden;M2C_FIELD(p,s16*,0x36)=0;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,40)); }{ void *created=CreateUnitSprite(arg1);M2C_FIELD(arg0+i*4,void**,56)=created; }func_020aab24(M2C_FIELD(arg0+i*4,void**,56),9,376,3,0);{ void *p=M2C_FIELD(arg0+i*4,void**,56);Set3DSpriteSlideTargetAndStart(p,hidden,0,hidden,0);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }M2C_FIELD(p,s16*,0x34)=hidden;M2C_FIELD(p,s16*,0x36)=0;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) { s32 y=M2C_FIELD(p,s16*,0x52); s32 x=M2C_FIELD(p,s16*,0x50); u32 w=func_020aae10(p); SpriteCellListSetCellRect(M2C_FIELD(p,void**,0x64),1,x,y,(u16)w,(u16)func_020aae44(p)); }func_02088da8(M2C_FIELD(arg0+i*4,void**,56)); }i++;}while(i<4);}
#pragma opt_common_subs reset
#pragma opt_propagation reset
