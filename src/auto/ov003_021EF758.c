/* 21 functions from 0x021EF758 to 0x021F05FC (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_scene.h"

u32 func_ov003_021ef758(void *arg0, u32 arg1) {
    M2C_UNK AddSprite(u16, M2C_UNK, u16, M2C_UNK *, s32);
    M2C_UNK SpriteCellListSetCellRect(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, s16, M2C_UNK, s16, s32);
    s16 GetSpriteAnimValue(void *);
    M2C_UNK GetUnitSpriteWidth(void *);
    M2C_UNK GetUnitSpriteHeight(void *);
    M2C_UNK IsRectOnScreen(s16, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GetWaypointSlotX(u8);
    extern M2C_UNK gSpriteDesc64x32;
    extern u16 **gCur3DSpriteEngine;
    extern M2C_UNK data_ov003_0220f89e;
    s32 sp10;
    s32 spC;
    u32 sp8;
    s32 temp_r4_6;
    s32 temp_r4_7;
    s16 temp_r7;
    s16 temp_r9;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    u32 var_r1;
    u8 var_r8;
    void *temp_r5;

    s16 spriteX, spriteY;

    sp8 = arg1;
    var_r8 = 0;
    if (arg1 == 0) {
        return arg1;
    }
    spC = 0x3FF;
    sp10 = 0x3FF;
    do {
        temp_r4 = GetSpriteAnimValue(M2C_FIELD(arg0, s32 *, 0x50));
        temp_r9 = temp_r4 + GetWaypointSlotX(var_r8);
        temp_r5 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x28);
        temp_r7 = temp_r9 + 0xD;
        Set3DSpriteSlideTargetAndStart(temp_r5, temp_r7, 0x70, temp_r7, 0x70);
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 & 0xFF) {
            spriteY = M2C_FIELD(temp_r5, s16 *, 0x52);
            spriteX = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = GetUnitSpriteWidth(temp_r5);
            SpriteCellListSetCellRect(M2C_FIELD(temp_r5, void **, 0x64), 1, spriteX, spriteY, (u16) temp_r4, (u16) GetUnitSpriteHeight(temp_r5));
        }
        M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5, s16 *, 0x36) = 0x70;
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 & 0xFF) {
            spriteY = M2C_FIELD(temp_r5, s16 *, 0x52);
            spriteX = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = GetUnitSpriteWidth(temp_r5);
            SpriteCellListSetCellRect(M2C_FIELD(temp_r5, void **, 0x64), 1, spriteX, spriteY, (u16) temp_r4, (u16) GetUnitSpriteHeight(temp_r5));
        }
        temp_r5 = M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x64) + (var_r8 * 4)), void **, 0x38);
        Set3DSpriteSlideTargetAndStart(temp_r5, temp_r9 + 0xD, 0x90, temp_r9 + 0xD, 0x90);
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        if (var_r0_3 & 0xFF) {
            spriteY = M2C_FIELD(temp_r5, s16 *, 0x52);
            spriteX = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = GetUnitSpriteWidth(temp_r5);
            SpriteCellListSetCellRect(M2C_FIELD(temp_r5, void **, 0x64), 1, spriteX, spriteY, (u16) temp_r4, (u16) GetUnitSpriteHeight(temp_r5));
        }
        M2C_FIELD(temp_r5, s16 *, 0x34) = temp_r7;
        M2C_FIELD(temp_r5, s16 *, 0x36) = 0x90;
        if (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x64), u8 *, 0x12) != 0) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (var_r0_4 & 0xFF) {
            spriteY = M2C_FIELD(temp_r5, s16 *, 0x52);
            spriteX = M2C_FIELD(temp_r5, s16 *, 0x50);
            temp_r4 = GetUnitSpriteWidth(temp_r5);
            SpriteCellListSetCellRect(M2C_FIELD(temp_r5, void **, 0x64), 1, spriteX, spriteY, (u16) temp_r4, (u16) GetUnitSpriteHeight(temp_r5));
        }
        temp_r4_6 = temp_r9 - 1;
        if (IsRectOnScreen(temp_r4_6, 0x78, 0x40, 0x20) != 0) {
            if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 3) {
                var_r0_5 = 1;
            } else {
                var_r0_5 = 0;
            }
            if ((var_r0_5 & 0xFF) && (var_r8 == M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7))) {
                var_r1 = 9;
            } else {
                var_r1 = 8;
            }
            AddSprite((u16) (temp_r4_6 & 0x1FF), 0x78,
                          (u16) ((spC & (0x600 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) |
                                 (u16) ((u8)var_r1 << 0xC) | 0x800),
                          &gSpriteDesc64x32, 0xB);
        }
        temp_r4_7 = temp_r9 - 4;
        if (IsRectOnScreen(temp_r4_7, 0x80, 0x40, 0x10) != 0) {
            AddSprite((u16) (temp_r4_7 & 0x1FF), 0x80,
                          (u16) ((sp10 & ((s32) (u16) ((((u8) M2C_FIELD(((var_r8 * 0x18) + (s32) M2C_FIELD(arg0, void **, 0x6C)), s32 *, 0x18) - 1) * 0x10) + 0x620) >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6400),
                          &data_ov003_0220f89e, 0xB);
        }
        var_r8 += 1;
    } while ((u32) var_r8 < sp8);
    return sp8;
}

void func_ov003_021efb40(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021efb54(void) {
    M2C_UNK func_ov003_021ea57c();
    func_ov003_021ea57c();
}

void func_ov003_021efb60(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov003_021efb74(void *arg0) {
    M2C_UNK Show3DSprite(s32);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK Hide3DSpriteSlide(s32);
    M2C_UNK Show3DSpriteSlide(s32);
    M2C_UNK IsLinkSessionActive(void);
    M2C_UNK SetTextById(void *, s32);
    M2C_UNK IsWaypointOptionValid(u8);
    M2C_UNK IsRectOnScreen(s16, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK IsSessionHost(void);
    M2C_UNK IsSessionGuest(void);
    M2C_UNK InRange(s32, s32, s32);
    M2C_UNK GetSceneEntryOffset(void);
    void SetOv003SceneState(s32);

    void *r7 = arg0;
    void *r4;
    u32 r5;
    void *r2;
    void *r0p;
    void *playerSprites;
    u32 playerCount;
    u8 slot;
    s32 byte1v;
    u8 byte2;
    u32 cond2;
    u32 ok;
    void *r4b;
    u8 r5b;
    void *r4c;
    void *r1p;
    u8 b3a;
    u32 textEnabled;
    void *p6c;
    void *p6c2;
    u16 val16;
    u32 r4x;
    u8 byte39;
    u32 cond3;
    M2C_UNK _v;

    Show3DSprite(M2C_FIELD(r7, s32 *, 0x58));
    r4 = M2C_FIELD(r7, void **, 0x68);
    Show3DSprite(M2C_FIELD(r4, s32 *, 0x78));

    r5 = 0;
    do {

        if (IsWaypointOptionValid((u8)r5) != 0) {
            Show3DSprite(M2C_FIELD((char *)r4 + r5 * 4, s32 *, 0x14));
        } else {
            Hide3DSprite(M2C_FIELD((char *)r4 + r5 * 4, s32 *, 0x14));
        }
        Show3DSprite(M2C_FIELD((char *)r4 + r5 * 4, s32 *, 0x44));
        ++r5;
    } while ((s32)r5 < 12);

    Show3DSprite(M2C_FIELD(r4, s32 *, 0x74));
    _v = GetSceneEntryOffset();
    r2 = M2C_FIELD(r7, void **, 0x3c);
    M2C_FIELD(r2, s16 *, 0xe) = (s16)_v;
    M2C_FIELD(r2, s16 *, 0x10) = 0;
    M2C_FIELD(r2, s16 *, 0xc) = 0xc;
    M2C_FIELD(r2, s16 *, 0x2) = M2C_FIELD(r2, u16 *, 0x4);

    r0p = M2C_FIELD(r7, void **, 0x6c);
    playerSprites = M2C_FIELD(r7, void **, 0x64);
    byte1v = M2C_FIELD(r0p, s8 *, 0x4);
    playerCount = (u8)(s16)byte1v;
    Show3DSpriteSlide(M2C_FIELD(playerSprites, s32 *, 0x0));
    Show3DSpriteSlide(M2C_FIELD(playerSprites, s32 *, 0x4));

    slot = 0;
    if ((u32)slot < playerCount) {
        do {
            if (IsLinkSessionActive() == 0) {
                if (slot < playerCount) {

                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x8));
                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x18));
                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x28));
                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x38));
                }
            } else {
                if (IsSessionHost() != 0) {

                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x28));
                    Show3DSprite(M2C_FIELD((char *)playerSprites + slot * 4, s32 *, 0x38));
                }
            }
            slot = (slot + 1) & 0xff;
        } while (slot < playerCount);
    }

    byte2 = M2C_FIELD(r7, u8 *, 0x39);
    cond2 = (((u32)byte2 << 0x1c) >> 0x1e);
    ok = (cond2 == 1) ? 1 : 0;
    if (ok & 0xff) {
        r4b = M2C_FIELD(r7, void **, 0x64);
        r5b = 0;
        do {

            Hide3DSprite(M2C_FIELD((char *)r4b + r5b * 4, s32 *, 0x8));
            Hide3DSprite(M2C_FIELD((char *)r4b + r5b * 4, s32 *, 0x18));
            ++r5b;
        } while (r5b < 4);
        if (IsSessionGuest() != 0) {
            Hide3DSprite(M2C_FIELD(r7, s32 *, 0x58));
            r4c = M2C_FIELD(r7, void **, 0x64);
            Hide3DSpriteSlide(M2C_FIELD(r4c, s32 *, 0x0));
            Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(r7, void **, 0x64), s32 *, 0x4));
            r1p = M2C_FIELD(r7, void **, 0x44);
            M2C_FIELD(r1p, s16 *, 0xe) = (s16)0xc0;
            M2C_FIELD(r1p, s16 *, 0x10) = (s16)0x24;
            M2C_FIELD(r1p, s16 *, 0xc) = (s16)0xc;
            M2C_FIELD(r1p, s16 *, 0x2) = M2C_FIELD(r1p, u16 *, 0x4);
            Show3DSpriteSlide(M2C_FIELD(r7, s32 *, 0x54));
        }
    }

    b3a = M2C_FIELD(r7, u8 *, 0x3a);
    b3a = (b3a & ~1) | 1;
    textEnabled = (u32)((u8)b3a << 31);
    M2C_FIELD(r7, u8 *, 0x3a) = b3a;

    if (textEnabled >> 31) {
    p6c = M2C_FIELD(r7, void **, 0x6c);
    p6c2 = M2C_FIELD(p6c, void **, 0xe0);
    val16 = M2C_FIELD(p6c2, u16 *, 0x2e);
    r4x = val16 & 0xff;

    if (InRange((s32)r4x, 0, 3) != 0) {
        SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000011);
    } else if (InRange((s32)r4x, 4, 7) != 0) {
        SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000012);
    } else if (InRange((s32)r4x, 8, 0x14) != 0) {
        SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000011);
    } else if (InRange((s32)r4x, 0x15, 0x18) != 0) {
        SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000010);
    } else if (r4x == 0x19) {
        byte39 = M2C_FIELD(r7, u8 *, 0x39);
        cond3 = (((u32)byte39 << 0x1c) >> 0x1e);
        ok = cond3 == 0;
        if (ok & 0xff) {
            SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000016);
        } else {
            ok = cond3 == 1;
            if (ok & 0xff) SetTextById(M2C_FIELD(r7, void **, 0x54), 0x47000017);
        }
    }

    }
    SetOv003SceneState(1);
}
#pragma pop
void func_ov003_021efe90(void) {
    M2C_UNK func_ov003_021eaed0();
    func_ov003_021eaed0();
}

void func_ov003_021efe9c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

/* Resets the battle scene's slide: starts a 12-frame tween of the map and the
 * side panels from their current positions to the scene offset or the panel
 * home x, clears the CO panel record and hides the panel sprites. */
void ResetBattleSceneSlide(void *scene) {
M2C_UNK Hide3DSpriteSlide(s32);s16 GetSpriteAnimValue(void *);s32 GetSceneSlideDirection();s16 GetSceneSlideOffset();
s16 offset;void *tween,*panel;
offset=GetSceneSlideOffset();
tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SLIDE_MAP); ((SpriteTween *)tween)->from=GetSpriteAnimValue(tween);((SpriteTween *)tween)->to=offset;((SpriteTween *)tween)->duration=BATTLE_SCENE_SLIDE_FRAMES;((SpriteTween *)tween)->current=((SpriteTween *)tween)->start;
panel=M2C_FIELD(scene,void **,BATTLE_SCENE_PANEL_INFO);M2C_FIELD(panel,s8 *,BATTLE_PANEL_CURRENT)=BATTLE_PANEL_NONE;M2C_FIELD(panel,s8 *,BATTLE_PANEL_ICON)=BATTLE_PANEL_NONE;
tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SLIDE_A); ((SpriteTween *)tween)->from=GetSpriteAnimValue(tween);((SpriteTween *)tween)->to=offset;((SpriteTween *)tween)->duration=BATTLE_SCENE_SLIDE_FRAMES;((SpriteTween *)tween)->current=((SpriteTween *)tween)->start;
tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SLIDE_PANEL); ((SpriteTween *)tween)->from=GetSpriteAnimValue(tween);((SpriteTween *)tween)->to=BATTLE_SCENE_PANEL_HOME_X;((SpriteTween *)tween)->duration=BATTLE_SCENE_SLIDE_FRAMES;((SpriteTween *)tween)->current=((SpriteTween *)tween)->start;
tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SLIDE_C); ((SpriteTween *)tween)->from=GetSpriteAnimValue(tween);((SpriteTween *)tween)->to=offset;((SpriteTween *)tween)->duration=BATTLE_SCENE_SLIDE_FRAMES;((SpriteTween *)tween)->current=((SpriteTween *)tween)->start;
tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SLIDE_B); ((SpriteTween *)tween)->from=GetSpriteAnimValue(tween);((SpriteTween *)tween)->to=BATTLE_SCENE_PANEL_HOME_X;((SpriteTween *)tween)->duration=BATTLE_SCENE_SLIDE_FRAMES;((SpriteTween *)tween)->current=((SpriteTween *)tween)->start;
Hide3DSpriteSlide(M2C_FIELD(scene,s32 *,BATTLE_SCENE_PANEL_SPRITE));if(GetSceneSlideDirection()==0)return;tween=M2C_FIELD(scene,void **,BATTLE_SCENE_SPRITES);Hide3DSpriteSlide(M2C_FIELD(tween,s32 *,0));Hide3DSpriteSlide(M2C_FIELD(tween,s32 *,4));}

void func_ov003_021effb8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

/* Whether the battle scene's map slide tween is still running (its frame
 * counter has not reached its duration); the iface method the state machine polls. */
u8 Ov003_IsBattleSceneSlideRunning(void *scene) {
    s32 finished;
    u8 running;
    SpriteTween *tween;

    tween = M2C_FIELD(scene, SpriteTween **, BATTLE_SCENE_SLIDE_MAP);
    if (tween->current == tween->duration) {
        finished = 1;
    } else {
        finished = 0;
    }
    if (!(finished & 0xFF)) {
        running = 1;
    } else {
        running = 0;
    }
    return running;
}

void func_ov003_021efff8(void) {
    M2C_UNK Ov003_SyncLinkSlots();
    Ov003_SyncLinkSlots();
}

void func_ov003_021f0004(void) {
    M2C_UNK WaypointPanel_RefreshPlayerReady();
    WaypointPanel_RefreshPlayerReady();
}

void func_ov003_021f0010(void) {

}

/* Link-session start step of the ov003 map-setup screen: once the map is
 * confirmed (scene flag at 0x39, bit 0), broadcasts the chosen map settings,
 * switches the scene to its map-transfer screen and, on a guest console,
 * answers the host's start packet with the local player's CO icon. */
void Ov003_StartLinkMapTransfer(void *scene) {
    s32 IsLinkSessionActive();
    s32 GetLocalPlayerIdForOverlay();
    s32 Link_ReceivePacket(void *, s32);
    void Link_SendPacket(void *, s32);
    void Link_FlushSend();
    s32 GetPlayerCoId(s32);
    s32 IsSessionGuest();
    void SetOv003SceneState(s32);
    void func_ov003_021f152c(s32);
    void Ov003_BroadcastPlayerSetup(s32);
    s32 GetPlayerCoIconIndex(u8);
    void CreateMapTransferPanelStep3(void *);
    u8 packet[0x24];
    s32 mapConfirmed;
    if (!IsLinkSessionActive()) return;
    if (((u32)(M2C_FIELD(scene, u8 *, 0x39) << 31) >> 31) == 1) mapConfirmed = 1; else mapConfirmed = 0;
    if (!(mapConfirmed & 255)) return;
    Ov003_BroadcastPlayerSetup(0); func_ov003_021f152c(1); SetOv003SceneState(1); CreateMapTransferPanelStep3(scene);
    if (!IsSessionGuest()) return;
    if (!Link_ReceivePacket(packet, 0x24)) return;
    packet[13] = GetPlayerCoIconIndex((u8)GetPlayerCoId(GetLocalPlayerIdForOverlay() + 1));
    Link_SendPacket(packet, 0x24); Link_FlushSend();
}

void func_ov003_021f00cc(void) {

}

void func_ov003_021f00d0(void) {
    M2C_UNK func_ov003_021ee8b8();
    func_ov003_021ee8b8();
}

/* Refresh the CO icon of every player slot in the waypoint list from that
 * player's link/online record (the local player's record for an empty slot).
 * A changed icon is written back, marks the panel dirty and, on the selected
 * slot, goes to the CO panel record too. */
void WaypointPanel_RefreshCoIcons(void *panel) {
    void *GetNetworkPlayerRecord(); void *GetLocalNetworkPlayerRecord(); s32 GetPlayerCoId(s32); s32 GetPlayerCoIconIndex(u8);
    s32 isEmpty; u8 playerId; s8 oldIcon,count,newIcon; u8 i; void *slot,*record;
    i=0; count=M2C_FIELD(M2C_FIELD(panel,void **,WAYPOINT_PANEL_LIST),s8 *,WAYPOINT_LIST_COUNT);
    if(count<=0)return;
    do {
        slot=M2C_FIELD(panel,void **,WAYPOINT_PANEL_LIST)+i;
        playerId=M2C_FIELD(slot,u8 *,WAYPOINT_LIST_IDS);
        oldIcon=M2C_FIELD(slot,s8 *,WAYPOINT_LIST_SLOT_OPTIONS);
        if(playerId==255) isEmpty=1; else isEmpty=0;
        if(!(isEmpty&255)){
            record=GetNetworkPlayerRecord(playerId);
            if(record) newIcon=M2C_FIELD(record,s8 *,13); else newIcon=GetPlayerCoIconIndex((u8)GetPlayerCoId(i+1));
        }else{
            record=GetLocalNetworkPlayerRecord();
            if(record) newIcon=M2C_FIELD(record+i,s8 *,0x12); else newIcon=GetPlayerCoIconIndex((u8)GetPlayerCoId(i+1));
        }
        if(oldIcon!=newIcon){
            M2C_FIELD(M2C_FIELD(panel,void **,WAYPOINT_PANEL_LIST)+i,u8 *,WAYPOINT_LIST_SLOT_OPTIONS)=(u8)newIcon;
            M2C_FIELD(panel,u8 *,OV003_FLAGS)|=OV003_FLAG_PANEL_DIRTY;
            if(i==M2C_FIELD(M2C_FIELD(panel,void **,WAYPOINT_PANEL_LIST),u8 *,WAYPOINT_LIST_SELECTED)){
                record=M2C_FIELD(panel,void **,WAYPOINT_PANEL_ICON_RECORD); M2C_FIELD(record,u8 *,BATTLE_PANEL_CURRENT)=i; M2C_FIELD(record,u8 *,BATTLE_PANEL_ICON)=(u8)newIcon;
            }
        }
        i++;
    }while(i<count);
}

void func_ov003_021f01cc(void *arg0) {
    M2C_UNK Ov003_SetMapConfirmEnabled();
    M2C_UNK Ov003_SetMapConfirmDisabled();
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x18) >> 0x1F) != 0) {
        Ov003_SetMapConfirmEnabled();
        return;
    }
    Ov003_SetMapConfirmDisabled();
}

void func_ov003_021f01f0(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK ConstructArray(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK SetOv003SceneClass(M2C_UNK *);
    void InitOv003OptionValue(void *);
    void Ov003OptionValue_Destructor(void);
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK data_ov003_0220f8e0;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK data_ov003_0220fb38;
    extern M2C_UNK data_ov003_0220fb64;
    extern M2C_UNK data_ov003_0220faf8;
    extern M2C_UNK gWaypointPanelGroupVTable;
    extern M2C_UNK data_ov003_0220fb18;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    u8 b, r3, r5, r12, i;
    M2C_UNK *base;

    SetOv003SceneClass(&data_ov003_0220f8e0);
    temp_r0 = CreateSpriteFromClass(&data_ov003_0220f8e0, arg0);
    if (temp_r0 == NULL) return;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_0220fb38;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220fb64;
    M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
    b = M2C_FIELD(temp_r0, u8 *, 0x39);
    r5 = b & ~2;
    b = r5;
    r3 = b & ~0xC;
    b = r3;
    M2C_FIELD(temp_r0, u8 *, 0x39) = r5;
    b = b & ~0xF0;
    M2C_FIELD(temp_r0, u8 *, 0x39) = b;
    b = M2C_FIELD(temp_r0, u8 *, 0x3A);
    r5 = b & ~1;
    b = r5;
    r12 = b & ~2;
    b = r12;
    r3 = b & ~4;
    b = r3;
    r5 = b & ~8;
    b = r5;
    r3 = b & ~0x70;
    b = r3;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = r12;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = r5;
    b = b & ~0x80;
    M2C_FIELD(temp_r0, u8 *, 0x3A) = b;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x50) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x54) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x6C) = 0;
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
    M2C_FIELD(temp_r0, void **, 0x3C) = temp_r0_2;
    temp_r0_2 = MemAlloc(0x14);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_0220faf8;
        M2C_FIELD(temp_r0_2, s16 *, 0x4) = 8;
        M2C_FIELD(temp_r0_2, s16 *, 0x6) = 4;
        M2C_FIELD(temp_r0_2, s16 *, 0x8) = 0xA0;
        M2C_FIELD(temp_r0_2, s16 *, 0xA) = 0xA0;
        M2C_FIELD(temp_r0_2, s8 *, 0x12) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x13) = 0;
        M2C_FIELD(temp_r0_2, s8 *, 0x10) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0x11) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xE) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xF) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xC) = 0x63;
        M2C_FIELD(temp_r0_2, s8 *, 0xD) = 0x63;
    }
    M2C_FIELD(temp_r0, void **, 0x40) = temp_r0_2;
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
    M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
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
    M2C_FIELD(temp_r0, void **, 0x48) = temp_r0_2;
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
    M2C_FIELD(temp_r0, void **, 0x4C) = temp_r0_2;
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
    M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_2;
    temp_r0_3 = MemAlloc(0x48);
    if (temp_r0_3 != NULL) {
        i = 0;
        M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = NULL;
        M2C_FIELD(temp_r0_3, s32 *, 4) = 0;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            M2C_FIELD(base, s32 *, 8) = 0;
            M2C_FIELD(base, s32 *, 0x18) = 0;
            M2C_FIELD(base, s32 *, 0x28) = 0;
            i += 1;
            M2C_FIELD(base, s32 *, 0x38) = 0;
        } while (i < 4);
    }
    M2C_FIELD(temp_r0, void **, 0x64) = temp_r0_3;
    temp_r0_3 = MemAlloc(0x80);
    if (temp_r0_3 != NULL) {
        i = 0;
        * (M2C_UNK **)temp_r0_3 = &gWaypointPanelGroupVTable;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            i += 1;
            M2C_FIELD(base, s32 *, 0x44) = 0;
        } while (i < 0xD);
    }
    M2C_FIELD(temp_r0, void **, 0x68) = temp_r0_3;
    temp_r0_3 = MemAlloc(0xE8);
    if (temp_r0_3 != NULL) {
        * (M2C_UNK **)temp_r0_3 = &data_ov003_0220fb18;
        ConstructArray(temp_r0_3 + 0x14, 4, 0x18, &InitOv003OptionValue, &Ov003OptionValue_Destructor);
        i = 0;
        do {
            base = &((M2C_UNK *)temp_r0_3)[i];
            i += 1;
            M2C_FIELD(base, s32 *, 0x78) = 0;
        } while (i < 0x1A);
    }
    M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_3;
    M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x39) & ~1);
}

/* Construct an option-value record: install its vtable, clear the value and the
 * bounds, and start with wrapping off.  (The unk10 field is always 1.) */
void InitOv003OptionValue(void *option) {
    extern M2C_UNK gOv003OptionRowVTable;
    Ov003OptionValue *row = option;

    row->vtable = &gOv003OptionRowVTable;
    row->wrap = 0;
    row->upper = 0;
    row->lower = 0;
    row->value = 0;
    row->unk10 = 1;
}

void Ov003OptionValue_Destructor(void) {

}

