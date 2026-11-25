/* 24 functions from 0x02201E88 to 0x02202DC8 (ov003), found by ds-decomp. */
#include "common.h"
#include "coordinate_bits.h"
#include "sound.h"
static inline void E1E88Apply(void *p,u8 v) { s32 flag; s8 a; if(v==1)flag=1;else flag=0; M2C_FIELD(p,u8 *,0x39)=v; if(flag&255)a=0;else a=1; M2C_FIELD(M2C_FIELD(p,void **,0x4C),s8 *,0x59)=a; }
#pragma cplusplus on
struct SetupPanel {
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
 };
extern "C" static inline void E1E88Virtual(void *p) {
    ((SetupPanel *)p)->Slot20();
}
#pragma cplusplus off
static inline u8 E1E88IsZero(u8 v) { return v == 0; }
static inline u8 E1E88IsOne(u8 v) { return v == 1; }
static inline void E1E88Set(void *p, u8 v) { M2C_FIELD(p,s8*,0x59)=v; }
static inline void E1E88Toggle(void *p, u8 v) { u8 a; if(v)a=0;else a=1; M2C_FIELD(p,s8*,0x59)=a; }

void func_ov003_02201e88(void *spriteSlots, void *allocationGroup) {
    s32 IsLinkSessionActive();
    s32 GetSessionPlayerMask();
    void Hide3DSprite(void *);
    void *Create3DSprite(void *);
    void SetFaceChildTextureRow(void *, s32, s32);
    void SetFaceSpriteFace(void *, s32);
    void *CreateFaceChildSprite(void *);
    M2C_UNK GetPlayerCoId(s32);
    M2C_UNK GetPlayerArmyId(s32);
    M2C_UNK GetPlayerTeam(s32);
    M2C_UNK func_020cfb94();
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern u8 data_ov003_02210484[];
    u8 participantSlots[4];
    s32 savedSpriteEngine;
    u32 playerCount;
    u8 slotCount;
    u8 slot;
    s8 participant;
    s32 player;
    u32 iconMode;
    u8 team;
    s32 appearance;
    s32 participantMask;
    void *sprite;
    u16 tileIndex;

    /* Create three setup icons per player, remapping participant icons when needed. */
    playerCount = (u32) func_020cfb94();
    slotCount = 0;
    do {
        participantSlots[slotCount] = 0xFF;
        slotCount = slotCount + 1;
    } while ((u32) slotCount < 4);
    slotCount = 0;
    participantMask = GetSessionPlayerMask();
    participant = 0;
    do {
        if (participantMask & (1 << participant)) {
            participantSlots[slotCount] = (u8) participant;
            slotCount = slotCount + 1;
        }
        participant = participant + 1;
    } while (participant < 4);
    for (slot = 0; (u32) slot < playerCount; slot++) {
        u8 mappedSlot = participantSlots[slot];
        if (mappedSlot != 0xFF && slot != mappedSlot) {
            if ((s32) mappedSlot <= (s32) (playerCount - 1) && participantSlots[mappedSlot] == 0xFF) {
                participantSlots[mappedSlot] = mappedSlot;
                participantSlots[slot] = 0xFF;
            }
        }
    }
    savedSpriteEngine = (s32) gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    player = 0;
    do {
        appearance = (u8) GetPlayerCoId(player + 1);
        if (GetPlayerTeam(player + 1) == 2) {
            iconMode = 2;
        } else {
            iconMode = 1;
        }
        team = (u8) GetPlayerArmyId(player + 1);
        sprite = CreateFaceChildSprite(allocationGroup);
        ((void **) spriteSlots)[player + 1] = sprite;
        SetFaceChildTextureRow(sprite, (0x1D0 + (player << 4)) << 5, 7);
        sprite = ((void **) spriteSlots)[player + 1];
        SetFaceSpriteFace(sprite, appearance);
        sprite = ((void **) spriteSlots)[player + 1];
        *(u16 *) ((u8 *) sprite + 0x3C) = 0x800;
        sprite = ((void **) spriteSlots)[player + 1];
        Hide3DSprite(sprite);
        sprite = Create3DSprite(allocationGroup);
        ((void **) spriteSlots)[player + 5] = sprite;
        *(void **) ((u8 *) sprite + 0x44) = data_ov003_02210484;
        if ((u8) iconMode == 1) {
            if (IsLinkSessionActive() != 0) {
                tileIndex = (u16) ((participantSlots[player] << 4) + 0x180);
            } else {
                tileIndex = (u16) (0x180 + (player << 4));
            }
        } else {
            tileIndex = 0x1C0;
        }
        *(u16 *) ((u8 *) ((void **) spriteSlots)[player + 5] + 0x3E) = (u32) (tileIndex << 5) >> 5;
        *(u16 *) ((u8 *) ((void **) spriteSlots)[player + 5] + 0x3C) = 0x6800;
        Hide3DSprite(((void **) spriteSlots)[player + 5]);
        sprite = Create3DSprite(allocationGroup);
        ((void **) spriteSlots)[player + 9] = sprite;
        *(void **) ((u8 *) sprite + 0x44) = data_ov003_02210484;
        sprite = ((void **) spriteSlots)[player + 9];
        *(u16 *) ((u8 *) sprite + 0x3E) = (u32) ((((team - 1) * 0x10) + 0x140) << 5) >> 5;
        sprite = ((void **) spriteSlots)[player + 9];
        *(u16 *) ((u8 *) sprite + 0x3C) = 0x6800;
        sprite = ((void **) spriteSlots)[player + 9];
        Hide3DSprite(sprite);
        player++;
    } while (player < 4);
    gCur3DSpriteEngine = (void *) savedSpriteEngine;
}

/* Sets the setup panel's state: records it, hides the panel sprite while the
 * active state is shown and clears the 32x32 background tile rect, then draws
 * the 8x8 highlight of the selected entry and marks the engine dirty. */
void Ov003_SetSetupPanelState(void *panel, u32 state) {
    s32 Divide(u8, s32);
    s32 Modulo(u8, s32);
    void SetTileRectPalette(s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    s32 flag;
    u8 entryIndex;
    s32 tileX;

    M2C_FIELD(panel, u8 *, 0x39) = state;
    flag = state & 0xff;
    if (flag == 1) flag = 1; else flag = 0;
    if (flag & 255) M2C_FIELD(M2C_FIELD(panel, void **, 0x4c), s8 *, 0x59) = 0;
    else M2C_FIELD(M2C_FIELD(panel, void **, 0x4c), s8 *, 0x59) = 1;
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c), 32, 32, 0);
    flag = E1E88IsOne(M2C_FIELD(panel, u8 *, 0x39));
    if (flag) {
        entryIndex = M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, 0x44), void **, 0x10c), u16 *, 0x2e);
        tileX = Modulo(entryIndex, 4);
        {
            s32 tileY = Divide(entryIndex, 4);
            tileX = (tileX * 8 + 0x60);
            SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c) + ((u32)((tileY * 0x120 + tileX) << 16) >> 15), 8, 8, 1);
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
}

u8 func_ov003_022021c0(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x39) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_022021d8(void *arg0) {
    return (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10C), u16 *, 0x2E);
}

/* Place the setup screen's target cursor over the preview unit sprite, sized to
 * that unit's sprite. */
void Ov003_PlaceSetupCursor(void *panel) {
s32 GetUnitSpriteWidth(void *);s32 GetUnitSpriteHeight(void *);
s32 width,height;void *unit;
unit=M2C_FIELD(M2C_FIELD(panel,void**,0x44),void**,SETUP_MENU_CURRENT);
height=GetUnitSpriteHeight(unit);width=GetUnitSpriteWidth(unit);
 SetSpriteActorRect(M2C_FIELD(panel,void**,0x4c),M2C_FIELD(unit,s16*,SPRITE_ACTOR_X),M2C_FIELD(unit,s16*,SPRITE_ACTOR_Y),width,height);
}

/* Point the panel's value-text label at the message for the entry it has
 * selected: entries 1, 2 and 6 show an option name resolved from the entry's
 * value, the others use a fixed message. */
void Ov003_UpdateSelectedEntryText(void *panel) {
M2C_UNK SetTextById(s32,s32); s32 Ov003_GetEntryValueTextId(u8,u8);
s32 entryValue; u8 entryIndex; void *menu;
if((u8)(((u32)(M2C_FIELD(panel,u8 *,0x3a)<<26)>>26)==1)) return;
menu=M2C_FIELD(panel,void **,0x44);
entryIndex=(u8)M2C_FIELD(M2C_FIELD(menu,void **,0x10c),u16 *,0x2e);
entryValue=M2C_FIELD((u8 *)menu+entryIndex*24,s32 *,12);
switch(entryIndex) {
case 0:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x47000000);break;
case 1:SetTextById(M2C_FIELD(panel,s32 *,0x58),Ov003_GetEntryValueTextId(entryIndex,(u8)entryValue));break;
case 2:SetTextById(M2C_FIELD(panel,s32 *,0x58),Ov003_GetEntryValueTextId(entryIndex,(u8)entryValue));break;
case 3:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x4700000b);break;
case 4:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x47000014);break;
case 5:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x4700000a);break;
case 6:SetTextById(M2C_FIELD(panel,s32 *,0x58),Ov003_GetEntryValueTextId(entryIndex,(u8)entryValue));break;
case 7:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x47000015);break;
case 8:SetTextById(M2C_FIELD(panel,s32 *,0x58),0x47000018);break;
}}

void func_ov003_02202380(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x12) = arg1;
}

void func_ov003_02202388(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x16) = arg1;
}

void func_ov003_02202390(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x14) = arg1;
}

void func_ov003_02202398(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x21) = arg1;
}

void func_ov003_022023a0(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x17) = arg1;
}

void func_ov003_022023a8(void *arg0,s32 arg1){M2C_FIELD(arg0,u8*,0x28)=(M2C_FIELD(arg0,u8*,0x28)&~0xe0)|((u32)((u8)arg1<<29)>>24);}

void func_ov003_022023c4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
}

void func_ov003_022023cc(void *arg0,s32 arg1){M2C_FIELD(arg0,u8*,0x20)=(M2C_FIELD(arg0,u8*,0x20)&~0xe0)|((u32)(arg1<<29)>>24);}

void func_ov003_022023e4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadSpriteResource(arg0, 0, arg1, arg2);
}

void func_ov003_022023fc(void) {
    M2C_UNK func_020cfb94();
    func_020cfb94();
}

s32 func_ov003_02202408(s32 arg0) {
    return (s32) (arg0 << 0xD) >> 0x10;
}

/* Refresh the setup menu's network state packet from the local player's record,
 * clear its start flag and send it to the other players. */
void Ov003_SendSetupPlayerState(void *panel) {
    M2C_UNK Link_SendPacket(void *, M2C_UNK);
    M2C_UNK ReadActivePlayerRecord(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Link_FlushSend();

    ReadActivePlayerRecord(0, M2C_FIELD(panel, void **, SETUP_PANEL_MENU) + SETUP_MENU_PACKET, SETUP_MENU_PACKET_SIZE);
    M2C_FIELD(M2C_FIELD(panel, void **, SETUP_PANEL_MENU), s32 *, SETUP_MENU_PACKET) = 0;
    Link_SendPacket(M2C_FIELD(panel, void **, SETUP_PANEL_MENU) + SETUP_MENU_PACKET, SETUP_MENU_PACKET_SIZE);
    Link_FlushSend();
}

/* Hide every sprite of the setup panel: its two slide sprites, the four rows of
 * four slot sprites (each loop pass hides one sprite from two of the rows), and
 * the panel's highlight cursor. */
void Ov003_HideSetupPanelSprites(void *panel) {
    void *sprites;
    u8 i;
    sprites = M2C_FIELD(panel, void **, SETUP_PANEL_SPRITES);
    Hide3DSprite(M2C_FIELD(sprites, s32 *, 0)); Hide3DSprite(M2C_FIELD(sprites, s32 *, 4));
    for (i = 0; (u32)i < 8; i++) { Hide3DSprite(((s32 *)(sprites + 8))[i]); Hide3DSprite(((s32 *)(sprites + 0x28))[i]); }
    Hide3DSprite(M2C_FIELD(panel, s32 *, SETUP_PANEL_HIGHLIGHT));
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov003_022024a8(void *arg0) {
    void AddSprite(u16, u8, u16, void *, s32);
    s32 func_020cfb94(void);
    void UpdateSpriteAnimation(void *);
    s16 GetSpriteAnimValue(void *);
    s32 GetWaypointSlotX(u8);
    s32 GetWaypointSlotBaseX();
    s32 GetWaypointSlotOffsetX(M2C_UNK);
    s32 Ov003_IsLinkSessionGuest();
    M2C_UNK func_ov003_0220501c(void *, s16, M2C_UNK);
    extern M2C_UNK gSpriteDesc64x32;
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_022104c8;
    s32 temp_r0_2;
    s32 adjustedY;
    s16 temp_r1;
    s32 temp_r5;
    s16 temp_r6;
    s32 temp_r10;
    s32 temp_r2;
    s32 temp_r4_2;
    s32 temp_r5_2;
    s32 screenX;
    s32 temp_r8;
    void *temp_r4, *temp_r11;
    u32 temp_r0;
    u32 var_r0;
    s32 var_r9;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r2_2;
    void *temp_r3;

    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x19) >> 0x1F;
    if (temp_r0 == 0) {
        return;
    }
    UpdateSpriteAnimation(M2C_FIELD(arg0, void **, 0x3C));
    UpdateSpriteAnimation(M2C_FIELD(arg0, void **, 0x48));
    temp_r6 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x3C));
    temp_r4 = gCur3DSpriteEngine;
    temp_r5 = 0 - temp_r6;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*(void **)g3DSpriteEngineMain, s16 *, 0x3E) = temp_r5;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x46) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 0x38) = temp_r6;
    AddSprite(0, (u8) GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x48)), (u16) ((0x3FF & (0x1C0 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7C00), &data_ov003_022104c8, 0xB);
    func_ov003_0220501c(arg0, temp_r6, 0);
    if (Ov003_IsLinkSessionGuest() != 0) {
        temp_r2 = (s32)((u32)GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x48)) << 5);
        adjustedY = -(temp_r2 / 32);
        AddSprite(0xC0, (u8)(s16)(adjustedY + 0xA0), (u16) ((0x3FF & (0x320 >> ((u32) (**(u16 **)gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7000), &gSpriteDesc64x32, 0xB);
    }
    gCur3DSpriteEngine = temp_r4;
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        return;
    }
    temp_r11 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    temp_r4_2 = temp_r6 - 8;
    M2C_FIELD(*(void **)g3DSpriteEngineSub, s16 *, 0x3E) = temp_r5;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x46) = 0xFFD0;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, s16 *, 0x38) = (s16) (0 - (temp_r4_2 + GetWaypointSlotBaseX()));
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x40) = 0xFFC0;
    temp_r5_2 = GetWaypointSlotBaseX();
    M2C_FIELD(*(void **)gCur3DSpriteEngine, s16 *, 0x3A) = (s16) (0 - (temp_r4_2 + temp_r5_2 + GetWaypointSlotOffsetX(1)));
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x42) = 0xFFC0;
    temp_r10 = func_020cfb94();
    screenX = (s16)(temp_r6 - 4);
    temp_r8 = M2C_FIELD(arg0, s32 *, 0x50);
    var_r9 = 0;
    do {
        temp_r0_2 = (s16)(GetWaypointSlotX((u8)var_r9) + screenX);
        if ((s32) var_r9 < temp_r10) {
            temp_r3 = temp_r8 + (var_r9 * 4);
            temp_r2_2 = M2C_FIELD(temp_r3, void **, 4);
            temp_r1 = (s16)temp_r0_2;
            M2C_FIELD(temp_r2_2, s16 *, 0x34) = temp_r1;
            M2C_FIELD(temp_r2_2, s16 *, 0x36) = 0x30;
            temp_r0_3 = M2C_FIELD(temp_r3, void **, 0x14);
            M2C_FIELD(temp_r0_3, s16 *, 0x34) = temp_r1;
            M2C_FIELD(temp_r0_3, s16 *, 0x36) = 0x78;
            temp_r0_4 = M2C_FIELD(temp_r3, void **, 0x24);
            M2C_FIELD(temp_r0_4, s16 *, 0x34) = temp_r1;
            M2C_FIELD(temp_r0_4, s16 *, 0x36) = 0x88;
        } else {
            Hide3DSprite(M2C_FIELD((temp_r8 + (var_r9 * 4)), void **, 4));
            Hide3DSprite(M2C_FIELD((temp_r8 + (var_r9 * 4)), void **, 0x14));
            Hide3DSprite(M2C_FIELD((temp_r8 + (var_r9 * 4)), void **, 0x24));
        }
        var_r9 += 1;
    } while ((s32) var_r9 < 4);
    gCur3DSpriteEngine = temp_r11;
}
#pragma opt_common_subs on
#pragma opt_strength_reduction on
void func_ov003_0220277c(void *arg0) {
    void Ov003_UpdateSetupPanelSprites(void *);
    M2C_UNK MenuSpriteIsClicked(M2C_UNK);
    M2C_UNK PressWaypointSprite(M2C_UNK);
    u8 func_ov003_022021d8(void *);
    void Ov003_CancelSetupPanel();
    void Ov003_IncreaseSelectedEntry(void *, s32);
    u8 func_ov003_02202e94(s32, s32);
    void Ov003_UpdateSelectedEntryText(void *);
    u8 func_ov003_022021c0(void *);
    void func_ov003_02202ec0(void *, u32);
    void Ov003_RefreshSelectedEntry();
    void Ov003_DecreaseSelectedEntry(void *, s32);
    void Ov003_UpdateSetupMenuButtons(void *);
    u8 func_ov003_022036c8(void *);
    s8 func_ov003_022036e4(void *);
    u8 func_ov003_022036ec(void *);
    s8 func_ov003_02203708(void *);
    void func_ov003_02203710(void *, s32);
    s32 func_ov003_02200c64(s32, s32, s32);
    M2C_UNK IsSessionHostAlt();
    M2C_UNK func_ov003_02204ec4(void *);
    M2C_UNK PlaySoundEffect(s32);

    extern void *gKeyState;
    extern void *gTouchState;

    u8 sp0 = M2C_FIELD(gTouchState, u8 *, 0x12);
    u16 r6 = M2C_FIELD(gKeyState, u16 *, 0);
    u8 r8;
    s32 r7 = 1;
    s32 r5 = 0x10011;
    s32 r11 = 0;
    s32 r4 = 0;
    u16 r9 = M2C_FIELD(gKeyState, u16 *, 2);

    Ov003_UpdateSetupPanelSprites(M2C_FIELD(arg0, void **, 0x40));
    if (MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 0)) != 0) {
        PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 0));
        Ov003_CancelSetupPanel(arg0, func_ov003_022021d8(M2C_FIELD(arg0, void **, 0x44)));
        r7 = 0;
    }

    for (r8 = 0; r8 < 8; r8++) {
        if (r7 != 0) {
            if (MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r8 * 4, void **, 8)) != 0) {
                Ov003_IncreaseSelectedEntry(M2C_FIELD(arg0, void **, 0x44), r8);
                PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r8 * 4, void **, 8));
                if (func_ov003_02202e94((s32)arg0, r8) != 0) {
                    Ov003_UpdateSelectedEntryText(arg0);
                    if (func_ov003_022021c0(arg0) != 0) {
                        func_ov003_02202ec0(arg0, r8);
                    } else {
                        Ov003_RefreshSelectedEntry(arg0, r8);
                    }
                }
                PlaySoundEffect(r5);
                r7 = r4;
            }
        }
        if (r7 != 0) {
            if (MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r8 * 4, void **, 0x28)) != 0) {
                Ov003_DecreaseSelectedEntry(M2C_FIELD(arg0, void **, 0x44), r8);
                PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r8 * 4, void **, 0x28));
                if (func_ov003_022021c0(arg0) != 0) {
                    func_ov003_02202ec0(arg0, r8);
                } else {
                    Ov003_RefreshSelectedEntry(arg0, r8);
                }
                if (func_ov003_02202e94((s32)arg0, r8) != 0) {
                    Ov003_UpdateSelectedEntryText(arg0);
                }
                PlaySoundEffect(r5);
                r7 = r11;
            }
        }
    }

    Ov003_UpdateSetupMenuButtons(M2C_FIELD(arg0, void **, 0x44));

    if (r7 != 0) {
        if (func_ov003_022036c8(M2C_FIELD(arg0, void **, 0x44)) != 0) {
            func_ov003_02202ec0(arg0, (u8)func_ov003_022036e4(M2C_FIELD(arg0, void **, 0x44)));
            r7 = 0;
        }
    } else {
        if (func_ov003_022036ec(M2C_FIELD(arg0, void **, 0x44)) != 0) {
            Ov003_RefreshSelectedEntry(arg0, (u8)func_ov003_02203708(M2C_FIELD(arg0, void **, 0x44)));
        }
    }

    if (sp0 == 0) {
        if (r7 != 0 && (r6 & 0x1)) {
            func_ov003_02202ec0(arg0, func_ov003_022021d8(M2C_FIELD(arg0, void **, 0x44)));
            r7 = 0;
        }
        if (r7 != 0 && (r6 & 0x8)) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void (**)(void *), 0x1C)(arg0);
            r7 = 0;
        }
        if (r7 != 0 && (r6 & 0x2)) {
            Ov003_CancelSetupPanel(arg0, func_ov003_022021d8(M2C_FIELD(arg0, void **, 0x44)));
            r7 = 0;
        }
        if (r9 & 0x40) {
            func_ov003_02203710(arg0, 1);
        } else if (r9 & 0x80) {
            func_ov003_02203710(arg0, 2);
        }
        if (r9 & 0x20) {
            func_ov003_02203710(arg0, 4);
        } else if (r9 & 0x10) {
            func_ov003_02203710(arg0, 8);
        }
        r4 = (s32)func_ov003_022021d8(M2C_FIELD(arg0, void **, 0x44));
        if (r7 != 0 && (r9 & 0x100)) {
            if (func_ov003_02200c64((r4 << 16) >> 16, 0, 7) != 0) {
                Ov003_IncreaseSelectedEntry(M2C_FIELD(arg0, void **, 0x44), r4 & 0xFF);
                PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r4 * 4, void **, 8));
                if (func_ov003_02202e94((s32)arg0, r4 & 0xFF) != 0) {
                    Ov003_UpdateSelectedEntryText(arg0);
                }
                PlaySoundEffect(r5);
            }
        }
        if (r7 != 0 && (r9 & 0x200)) {
            if (func_ov003_02200c64((r4 << 16) >> 16, 0, 7) != 0) {
                Ov003_DecreaseSelectedEntry(M2C_FIELD(arg0, void **, 0x44), r4 & 0xFF);
                PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0, void **, 0x40) + r4 * 4, void **, 0x28));
                if (func_ov003_02202e94((s32)arg0, r4 & 0xFF) != 0) {
                    Ov003_UpdateSelectedEntryText(arg0);
                }
                PlaySoundEffect(r5);
            }
        }
    }

    if (IsSessionHostAlt() == 0) {
        return;
    }
    func_ov003_02204ec4(arg0);
}

/* Animate every sprite of the setup panel's sprite set (the two slide sprites
 * and the four rows of four slot sprites) by one frame. */
void Ov003_UpdateSetupPanelSprites(void *sprites) {
    M2C_UNK MenuSpriteUpdate(s32);
    u8 i;
    MenuSpriteUpdate(M2C_FIELD(sprites, s32 *, SETUP_SPRITES_SLIDE_0));
    MenuSpriteUpdate(M2C_FIELD(sprites, s32 *, SETUP_SPRITES_SLIDE_1));
    for (i = 0; (u32)i < SETUP_SPRITES_ROW_COUNT; i++) {
        MenuSpriteUpdate(((s32 *)(sprites + SETUP_SPRITES_ROW_TOP))[i]);
        MenuSpriteUpdate(((s32 *)(sprites + SETUP_SPRITES_ROW_BOTTOM))[i]);
    }
}

/* Cancel the setup panel: play the cancel sound; if the panel is already closed,
 * leave the screen through its interface, otherwise close the panel, clear the
 * tile-rect palette behind it and re-highlight the selected entry's cell. */
void Ov003_CancelSetupPanel(void *panel) {
    s32 Divide(u8, s32);
    s32 Modulo(u8, s32);
    void SetTileRectPalette(s32, s32, s32, s32);
    s32 PlaySoundEffect(s32);
    extern void *gCur3DSpriteEngine;
    s32 open;
    u8 entryIndex;
    s32 tileX;

    PlaySoundEffect(SOUND_MENU_CANCEL);
    if (E1E88IsZero(M2C_FIELD(panel, u8 *, SETUP_PANEL_STATE))) { E1E88Virtual(panel); return; }
    M2C_FIELD(panel, u8 *, SETUP_PANEL_STATE) = SETUP_PANEL_CLOSED;
    if (M2C_FIELD(panel, u8 *, SETUP_PANEL_STATE) == SETUP_PANEL_OPEN) open = 1; else open = 0;
    if (open & 255) E1E88Set(M2C_FIELD(panel, void **, SETUP_PANEL_HIGHLIGHT), 0);
    else E1E88Set(M2C_FIELD(panel, void **, SETUP_PANEL_HIGHLIGHT), 1);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c), 32, 32, 0);
    open = E1E88IsOne(M2C_FIELD(panel, u8 *, SETUP_PANEL_STATE));
    if (open) {
        entryIndex = M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, SETUP_PANEL_MENU), void **, SETUP_MENU_CURRENT), u16 *, 0x2e);
        tileX = Modulo(entryIndex, 4);
        {
            s32 tileY = Divide(entryIndex, 4);
            tileX = (tileX * 8 + 0x60);
            SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2c) + ((u32)((tileY * 0x120 + tileX) << 16) >> 15), 8, 8, 1);
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
}

void func_ov003_02202cc4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020d47f0();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK Ov003_SetMapConfirmDisabled();
    s32 IsSessionHostAlt();
    M2C_UNK func_ov003_02204fd0(void *);
    extern u16 data_02168f14;
    s32 temp_r6;
    s32 var_r0;
    u8 var_r7;
    void **temp_r0_2;
    void *temp_r0;

    func_0208fe30(0x1000F);
    func_020d47f0();
    temp_r0 = *M2C_FIELD(arg0, void ***, 0x40);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    Ov003_SetMapConfirmDisabled();
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r6 = M2C_FIELD(arg0, s32 *, 0x44);
        var_r7 = 0;
        do {
            temp_r0_2 = M2C_FIELD((temp_r6 + (var_r7 * 4)), void ***, 0xC8);
            M2C_FIELD(*temp_r0_2, M2C_UNK (**)(void **, s32), 0x1C)(temp_r0_2, M2C_FIELD(((var_r7 * 0x18) + temp_r6), s32 *, 0xC));
            var_r7 += 1;
        } while ((u32) var_r7 < 8U);
        data_02168f14 |= 0x2000;
    }
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (IsSessionHostAlt() == 0) {
        return;
    }
    func_ov003_02204fd0(arg0);
}

