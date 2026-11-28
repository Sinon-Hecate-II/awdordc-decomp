/* 19 functions from 0x021F25CC to 0x021F35B0 (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_mapselect.h"
#include "ov003_scene.h"
static inline s32 IsTerrain2878(s32 v) { switch(v) { case 6: case 18: case 19: case 20: case 21: return 1; default: return 0; } }
static inline s32 Active2878(void) { s32 Ov003_IsSceneReady(void); return Ov003_IsSceneReady()!=0; }
static inline u8 Block2878(s32 entry) { void *p; if(Active2878()) return 1; p=M2C_FIELD(entry,void **,0x40); return IsTerrain2878(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)]) != 0; }
static inline s32 IsSpecial2e98(s32 v) {
 switch(v-8) {case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: return 1; default:return 0;}
}
static inline u8 AtEnd2e98(void *p) {return M2C_FIELD(p,s8 *,5)==M2C_FIELD(p,s8 *,6);}
static inline u8 AtStart2e98(void *p) {
 switch(M2C_FIELD(p,u8 *,4)) {
 case 1: case 2: case 3: case 4: case 5: case 6: case 9: case 10: case 11: case 12: return M2C_FIELD(p,s8 *,5)<=1;
 default:return M2C_FIELD(p,s8 *,5)==0;
 }
}

static inline s32 BlockNext2e98(void *p) {if(AtEnd2e98(p))return 1; return IsSpecial2e98(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)+1]);}
static inline s32 BlockPrev2e98(void *p) {if(AtStart2e98(p))return 1; return IsSpecial2e98(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)-1]);}
static inline void AdvanceState2e98(s32 a) {
 s32 IsOv003SceneActive(void); void Ov003_CreateScreenTransition(void);
 if(M2C_FIELD(a,u8 *,0x44)) {M2C_FIELD(a,u8 *,0x34)=2; return;}
 if(IsOv003SceneActive()) {Ov003_CreateScreenTransition(); M2C_FIELD(a,u8 *,0x44)=1;M2C_FIELD(a,u8 *,0x34)=2;}
}
/* True while the map-select list's current category (gMapCategory) is one that
 * lists the campaign map records (ids 225..424): the story and the trial-map
 * categories.  The other categories show different map lists. */
s32 IsCampaignMapCategory(void) {
 s32 GetMapCategory();
 switch(GetMapCategory()) {
 case 6: case 8: case 12: case 14: case 15: case 16: case 17: case 22: case 23: case 24: return 1;
 case 0: case 1: case 2: case 3: case 4: case 5: case 7: case 9: case 10: case 11: case 13: case 18: case 19: case 20: case 21: default: return 0;
 }
}

/* True while the current map category shows the game's campaign maps directly:
 * its campaign map ids (225..424) are loaded from the cached campaign map
 * headers, one 50-map block per player, instead of a saved map record, so its
 * maps never need the unavailable shading.  A subset of IsCampaignMapCategory,
 * which also covers the categories whose campaign-range ids are player records. */
s32 IsCampaignMapHeaderCategory(void) {
 s32 GetMapCategory();
 switch(GetMapCategory()) {
 case 6: case 12: case 22: case 23: return 1;
 default: return 0;
 }
}

/* Return the slot `mapId` holds in a side's five-slot map-pick list, or
 * MAP_PICK_NOT_FOUND when that side has not picked the map. */
u8 FindMapPick(s32 unused, u16 *picks, s32 mapId) {
    u8 i = 0;
    do { if (mapId == picks[i]) return i; ++i; } while (i < MAP_PICK_SLOTS);
    return MAP_PICK_NOT_FOUND;
}

/* Pick one map for a side of the ov003 link map-select screen.  `block` holds
 * both sides' pick lists (at +4 and +0xE) and `picks` is the list of the side
 * that is choosing: a map that side already picked is unpicked (sound 0x1000F);
 * a map the other side already picked, or a full list, is refused (0x1001D);
 * otherwise the map fills the first free slot (sound 0x1000D). */
void ToggleMapPick(s32 block, s32 picks, M2C_UNK map) {
    u8 IsMapPickListFull();
    M2C_UNK PlaySoundEffect(s32);
    s32 FindFreeMapPick(s32,s32);
    s32 i; s32 other;
    i = FindMapPick(block, (u16 *)picks, map);
    if (i != MAP_PICK_NOT_FOUND) {
        PlaySoundEffect(0x1000f); ((u16 *)picks)[i] = MAP_PICK_EMPTY; return;
    }
    if (IsMapPickListFull(block, picks)) { PlaySoundEffect(0x1001d); return; }
    other = block + 4; if (picks == other) other = block + 14;
    if (FindMapPick(block, (u16 *)other, map) != MAP_PICK_NOT_FOUND) { PlaySoundEffect(0x1001d); return; }
    i = FindFreeMapPick(block, picks);
    PlaySoundEffect(0x1000d);
    ((u16 *)picks)[i] = map;
}

/* Count the maps picked in a side's five-slot map-pick list: every slot that is
 * not MAP_PICK_EMPTY counts. */
s32 CountMapPicks(s32 unused, u16 *picks) {
    u8 count = 0, i = 0;

    do {
        if (picks[i] != MAP_PICK_EMPTY) count++;
        i++;
    } while (i < MAP_PICK_SLOTS);
    return count;
}

/* True when a side's five-slot map-pick list already holds MAP_PICK_SLOTS maps,
 * so no further map can be picked.  `block` and `picks` are passed straight
 * through to CountMapPicks by its old-style declaration. */
u8 IsMapPickListFull(s32 block, s32 picks) {
    s32 CountMapPicks();
    u8 full;

    if (CountMapPicks() == MAP_PICK_SLOTS) {
        full = 1;
    } else {
        full = 0;
    }
    return full;
}

/* Return the first free (MAP_PICK_EMPTY) slot of a side's five-slot map-pick
 * list, or MAP_PICK_NOT_FOUND when it is full. */
s32 FindFreeMapPick(s32 unused, s32 picks) {
    u8 i = 0;
    do { if (((u16 *)picks)[i] == MAP_PICK_EMPTY) return i; ++i; } while (i < MAP_PICK_SLOTS);
    return MAP_PICK_NOT_FOUND;
}

/* Pick or unpick the map the first side has selected in the link map-select
 * screen, after checking its campaign map record: a map whose record is not
 * valid is refused with sound 0x1001D instead. */
void ToggleFirstSideMapPick(s32 block, s32 map) {
    M2C_UNK PlaySoundEffect(s32);
    s32 IsCampaignMapRecordValid(M2C_UNK);
    void ToggleMapPick(s32, s32, M2C_UNK);
    if (IsCampaignMapRecordValid(map) == 0) {
        PlaySoundEffect(0x1001D);
        return;
    }
    ToggleMapPick(block, block + 4, map);
}

/* Copy the shared saved map picks back into the panel block's two pick lists
 * (at +4 and +0xE), dropping whatever the player had toggled. */
void RestoreMapPickLists(s32 block) {
    M2C_UNK CopyMapPickLists(s32, s32);
    CopyMapPickLists(block + 4, block + 0xE);
}

/* Fill the panel block's two five-entry map-id pick lists (at +4 and +0xE) from
 * the saved selection and downloaded lists, leaving the stored lists as they are. */
void LoadSavedMapPickLists(s32 block) {
    M2C_UNK LoadMapPickLists(s32, s32);
    LoadMapPickLists(block + 4, block + 0xE);
}

#pragma push
#pragma optimization_level 2
void func_ov003_021f2878(s32 entry) {
    s32 IsLinkSessionActive(void);
    s32 IsSessionInError(void);
    s32 GetActiveOverlay(void);
    void SetLinkResultFlag(M2C_UNK);
    s32 IsLinkResultFlagSet(M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    void SetOnlineSessionFlag(M2C_UNK);
    M2C_UNK GetNetErrorVeneer(M2C_UNK *, M2C_UNK *);
    s32 GetOverlayEventFlags(void);
    s32 GetSessionPlayerCount(void);
    s32 Ov003SceneObjectHasChildren(void);
    M2C_UNK Ov003_IsSceneReady(void);
    s32 var_sp4;
    s32 var_sp0;

    if (M2C_FIELD(entry, u8 *, 0x47) != 0) {
        goto ready;
    }
    if (IsLinkSessionActive() == 0) {
        return;
    }
    if (M2C_FIELD(entry, u8 *, 0x34) != 2) {
        return;
    }
    if (IsSpecial2e98(M2C_FIELD(M2C_FIELD(entry,void **,0x40),u8 **,8)[M2C_FIELD(M2C_FIELD(entry,void **,0x40),s8 *,5)])) return;
    {
        s32 t = Ov003SceneObjectHasChildren();
        if (t != 0) {
            return;
        }
    }
ready:
    if (M2C_FIELD(entry,u8 *,0x45) || M2C_FIELD(entry,u8 *,0x46)) return;
    if (IsSessionInError() != 0) {
        s32 sw = GetActiveOverlay();
        switch (sw) { case 1:
            if (IsLinkResultFlagSet(1) == 0) {
                SetLinkResultFlag(1);
                M2C_FIELD(entry, u8 *, 0x45) = 1;
            }
        break; case 2:
            if (IsOnlineSessionFlagSet(6) == 0) {
                SetOnlineSessionFlag(6);
                GetNetErrorVeneer(&var_sp4, &var_sp0);
                switch (var_sp0) {
                case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                    SetOnlineSessionFlag(6);
                    break;
                default:
                    break;
                }
                M2C_FIELD(entry,u8 *,0x45)=1;
            }
        }
    }

tail:
 if(M2C_FIELD(entry,u8 *,0x47)) { M2C_FIELD(entry,u8 *,0x47)=0; return; }
 if(!GetOverlayEventFlags() && (u32)GetSessionPlayerCount()>1) return;
 if(!Active2878() && !(u8)(IsTerrain2878(M2C_FIELD(M2C_FIELD(entry,void **,0x40),u8 **,8)[M2C_FIELD(M2C_FIELD(entry,void **,0x40),s8 *,5)]) != 0)) M2C_FIELD(entry,u8 *,0x46)=1;
}
#pragma pop
/* Attempt to start a contextual action (overlay-dependent); returns 1 if one was started. */
s32 ShowLinkResultPanel(s32 entry) {
    s32 IsLinkSessionActive(void);
    s32 IsTextLayerActive(void);
    s32 GetActiveOverlay(void);
    s32 GetLinkResultCode(void);
    void CreateLinkStatusLabel(s32, s32, s32, void *);
    s32 GetNetErrorVeneer(s32 *, s32 *);
    void CreateNetErrorSprite(s32, s32, s32, s32, s32, void *);
    void func_ov010_02228320(void);
    void Ov010Online_ClearStepFlag(s32);
    s32 result, spare;

    if (!IsLinkSessionActive()) {
        return 0;
    }
    if (!M2C_FIELD(entry, u8 *, 0x45)) {
        return 0;
    }
    if (IsTextLayerActive()) {
        return 0;
    }
    switch (GetActiveOverlay()) {
    case 1:
        CreateLinkStatusLabel(0, 0x6e0, GetLinkResultCode(), (void *)entry);
        break;
    case 2:
        CreateNetErrorSprite(0, 0x6e0, GetNetErrorVeneer(&result, &spare), result, spare, (void *)entry);
        func_ov010_02228320();
        switch (spare) {
        case 0:
        case 1:
        case 2:
            Ov010Online_ClearStepFlag(6);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        }
        break;
    }
    return 1;
}

/* In a link session, when the highlighted map cannot be used (mapUnavailable)
 * and no link-result panel is due, create the notice text layer and report that
 * the action was started. */
s32 ShowMapUnavailableMessage(s32 arg0) {
    Ov003BattleSetup *entry = (Ov003BattleSetup *)arg0;
    s32 IsLinkSessionActive(void);
    s32 IsTextLayerActive(void);
    void *CreateTextLayer(s32);
    void RenderTextLayerMessage(void *, s32, s32, u32);
    if (!IsLinkSessionActive()) return 0;
    if (entry->linkResultReceived) return 0;
    if (!entry->mapUnavailable) return 0;
    if (IsTextLayerActive()) return 0;
    RenderTextLayerMessage(CreateTextLayer(arg0), 2, 0xdc00, 0x44000001);
    return 1;
}

/* Initializes the ov003 map-select screen: configures both sprite engines'
 * background layers, sets up the cursor and preview-list objects at entry+0x3C
 * and entry+0x38, and marks the screen state ready (3). */
void InitMapSelectScreen(s32 arg0) {
    M2C_UNK ClearAll3DSpriteLayers(void);
    void GX_ReleaseBankGrants(void);
    void Set3DSpriteVramBanks(void);
    void GX_ReleaseBankGrantForBGExtPalette(void);
    void GX_SetBankForObjExtPalette(s32);
    void GX_ReleaseBankGrantForOBJExtPltt(void);
    void GX_SetBankForBGExtPalette(s32);
    void SetSceneLayoutMain(s32);
    void SetSceneLayoutSub(s32);
    s32 IsMapConfirmEnabled(void);
    void Ov003_SetMapConfirmEnabled(void);
    void Ov003_SetMapConfirmDisabled(void);
    void CreateScene3DSprite(void *);
    void ApplySceneLayers(void *);
    void ClearOverlayEventFlags(void);
    s32 IsLinkSessionActive(void);
    void CreateSubScreenLinkIndicator(void);
    void func_ov003_021f1884(s32);
    void func_ov003_021f2e98(s32);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    extern M2C_UNK data_ov003_0220fcb4;
    extern M2C_UNK data_ov003_0220fca8;

    s32 layer;
    u16 **savedEngine;
    u16 **engine;
    u16 *volatile reg10, *volatile reg20, *volatile reg40, *volatile reg80, *volatile reg100, *volatile regC0;
    u16 *t10, *t20, *t40, *t80, *t100, *tC0;
    void *unusedSaved;
    void *unusedObj;

    ClearAll3DSpriteLayers();
    GX_ReleaseBankGrants();
    Set3DSpriteVramBanks();
    GX_ReleaseBankGrantForBGExtPalette();
    GX_SetBankForObjExtPalette(0x40);
    GX_ReleaseBankGrantForOBJExtPltt();
    GX_SetBankForBGExtPalette(0x20);
    SetSceneLayoutMain((s32)&data_ov003_0220fcb4);
    SetSceneLayoutSub((s32)&data_ov003_0220fca8);

    layer = 0;
    savedEngine = (u16 **)gCur3DSpriteEngine;
    do {
        if (layer == 0) {
            engine = (u16 **)g3DSpriteEngineMain;
        } else {
            engine = (u16 **)g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = (void *)engine;
        t10 = *engine;
        reg10 = t10;
        *reg10 = *reg10 | 0x10;
        t20 = *(u16 **)gCur3DSpriteEngine;
        reg20 = t20;
        *reg20 = *reg20 | 0x20;
        t40 = *(u16 **)gCur3DSpriteEngine;
        reg40 = t40;
        *reg40 = *reg40 | 0x40;
        t80 = *(u16 **)gCur3DSpriteEngine;
        reg80 = t80;
        *reg80 = *reg80 | 0x80;
        t100 = *(u16 **)gCur3DSpriteEngine;
        reg100 = t100;
        *reg100 = *reg100 | 0x100;
        tC0 = *(u16 **)gCur3DSpriteEngine;
        regC0 = (u16 *)((u8 *)tC0 + 0x12);
        *regC0 = (s16)(*regC0 & ~0xC0);
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x51) = 0;
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x52) = 0;
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x53) = 0;
        layer += 1;
    } while (layer < 2);
    gCur3DSpriteEngine = savedEngine;

    if (IsMapConfirmEnabled() != 0) {
        Ov003_SetMapConfirmEnabled();
    } else {
        Ov003_SetMapConfirmDisabled();
    }


    M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,0)=1;
    { s32 displayKind;
      switch(M2C_FIELD(M2C_FIELD(arg0,void **,0x40),u8 *,4)) {
      case 0: displayKind=1; break;
      case 7: case 8: displayKind=7; break;
      case 1: case 3: case 5: displayKind=2; break;
      case 2: case 4: case 6: displayKind=3; break;
      case 9: case 10: case 11: case 12: displayKind=14; break;
      default:displayKind=0;break;
      }
      M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,1)=displayKind;
    }
    M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),s32 *,4)=0x780;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,8)=0x1f;
    CreateScene3DSprite(M2C_FIELD(arg0,void **,0x3c));
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,0)=1;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,1)=2;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,2)=15;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,3)=1;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,4)=2;
    M2C_FIELD(M2C_FIELD(arg0,void **,0x38),u8 *,5)=15;
    ApplySceneLayers(M2C_FIELD(arg0,void **,0x38));
    ClearOverlayEventFlags();
    if (IsLinkSessionActive() != 0) {
        CreateSubScreenLinkIndicator();
    }
    func_ov003_021f1884(0x6E0);
    func_ov003_021f2e98(arg0);
    *(u8 *)((u8 *)arg0 + 0x34) = 3;
}

/* Advance the cursor/movement state machine for the current entry. */
void func_ov003_021f2e98(s32 entry) {
 M2C_UNK AddSceneObjectChild(); M2C_UNK GotoSpriteAnimationLabel(M2C_UNK,M2C_UNK);
 void Sprite_ResumeAnimation(s32); s32 IsOv003SceneActive(void); void Ov003_CreateScreenTransition(void);
 s32 GetMapConfirmState(void); void EnableMapConfirm(void); void DisableMapConfirm(void);
 void DeleteVoiceChatWidgets(void); void CreateMatchNameLabel(s32,s32,s32);
 void SetOv003SceneState(s32); s32 GetSceneSlideOffset(void);
 void Ov003_StartScreenFade(void); void Ov003_SetSceneBattleState(void);
 s32 IsOv003SceneClosed(void); void Ov003_StartBattleScene(s32,s32,s32,s32,s32);
 s32 direction; u8 next; s32 prev; void *p;
 func_ov003_021f2878(entry);
 if(ShowLinkResultPanel(entry)||ShowMapUnavailableMessage(entry)) {
 AddSceneObjectChild(); GotoSpriteAnimationLabel(entry,5); return;
 }
 if(M2C_FIELD(entry,u8 *,0x45)||M2C_FIELD(entry,u8 *,0x46)) return;
 switch(M2C_FIELD(entry,u8 *,0x34)) {
 case 0: break;
 case 4: break;
 case 5: break;
 default: break;
 case 1:
 if(M2C_FIELD(entry,u8 *,0x44)) {M2C_FIELD(entry,u8 *,0x34)=2;return;}
 if(M2C_FIELD(entry,u8 *,0x44)) return;
 if(!IsOv003SceneActive()) return;
 Ov003_CreateScreenTransition(); M2C_FIELD(entry,u8 *,0x44)=1; M2C_FIELD(entry,u8 *,0x34)=2;
 return;
 case 2:
 switch(GetMapConfirmState()) {
 case 0: default: return;
 case 1:
 if(AtEnd2e98(M2C_FIELD(entry,void **,0x40))) {EnableMapConfirm();Sprite_ResumeAnimation(entry);return;}
 M2C_FIELD(entry,u8 *,0x34)=3;
 p=M2C_FIELD(entry,void **,0x40);
 if(IsSpecial2e98(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)])) SetOv003SceneState(4);
 else {if(!GetSceneSlideOffset()){Ov003_StartScreenFade();M2C_FIELD(entry,u8 *,0x44)=0;}Ov003_SetSceneBattleState();}
 p=M2C_FIELD(entry,void **,0x40);M2C_FIELD(p,s8 *,5)++;return;
 case 2:
 if(AtStart2e98(M2C_FIELD(entry,void **,0x40))) {DisableMapConfirm();DeleteVoiceChatWidgets();CreateMatchNameLabel(0,0x6e0,entry);Sprite_ResumeAnimation(entry);return;}
 M2C_FIELD(entry,u8 *,0x34)=3;
 p=M2C_FIELD(entry,void **,0x40);
 if(IsSpecial2e98(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)])) SetOv003SceneState(4);
 else {if(!GetSceneSlideOffset()){Ov003_StartScreenFade();M2C_FIELD(entry,u8 *,0x44)=0;}Ov003_SetSceneBattleState();}
 p=M2C_FIELD(entry,void **,0x40);M2C_FIELD(p,s8 *,5)--;return;
 }
 case 3:
 if(!IsOv003SceneClosed()) return;
 p=M2C_FIELD(entry,void **,0x40);
 if(IsSpecial2e98(M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)])){GotoSpriteAnimationLabel(entry,3);return;}
 M2C_FIELD(entry,u8 *,0x34)=1;
 switch(GetMapConfirmState()) {
 case 2: p=M2C_FIELD(entry,void **,0x40);direction=BlockNext2e98(p)?0:2;break;
 case 1: p=M2C_FIELD(entry,void **,0x40);if(BlockPrev2e98(p)) direction=0; else direction=1;break;
 }
 p=M2C_FIELD(entry,void **,0x40);
 next=(u8)!BlockNext2e98(p); prev=BlockPrev2e98(p)?0:2;
 Ov003_StartBattleScene(entry,M2C_FIELD(p,u8 **,8)[M2C_FIELD(p,s8 *,5)],direction,
 next,prev);
 return;
 }
}
void func_ov003_021f34d8(void) {
    ((void (*)())InitMapSelectScreen)();
}

/* Applies the map-select confirm state to the map, and in a link session on the
 * campaign or trial map list opens the map-transfer panel.  Kinds 1, 3 and 5
 * first reset the map settings to the global game settings. */
void ApplyMapConfirmState(void *entry) {
    s32 IsLinkSessionActive(void);
    void MapSettings_CopyFromGameSettings(s32);
    void EnableMapConfirm(void);
    void DisableMapConfirm(void);
    s32 GetMapConfirmState(void);
    void CreateMapTransferPanelStep2(void *);
    u8 listKind = M2C_FIELD(M2C_FIELD(entry, Ov003BattleSetupMenu **, 0x40), u8 *, 4);
    s32 resetSettings;
    switch (listKind) {
    case 1: case 3: case 5: resetSettings = 1; break;
    default: resetSettings = 0; break;
    }
    if (resetSettings) MapSettings_CopyFromGameSettings(0);
    if (GetMapConfirmState() == MAP_CONFIRM_ENABLED) {
        EnableMapConfirm();
        if (!IsLinkSessionActive()) return;
        listKind = M2C_FIELD(M2C_FIELD(entry, Ov003BattleSetupMenu **, 0x40), u8 *, 4);
        if (listKind != 1 && listKind != 5) return;
        CreateMapTransferPanelStep2(entry);
    } else DisableMapConfirm();
}

/* Refresh the link status of the highlighted map-select entry: run the link
 * session handler, then if a link-result panel was shown or the "map
 * unavailable" notice was raised, cancel the cursor's animation and play the
 * refusal animation (5). */
void RefreshMapSelectLinkState(s32 entry) {
    M2C_UNK GotoSpriteAnimationLabel(M2C_UNK, M2C_UNK);
    M2C_UNK AddSceneObjectChild();
    void func_ov003_021f2878();
    s32 ShowLinkResultPanel(M2C_UNK);
    s32 ShowMapUnavailableMessage(M2C_UNK);
    func_ov003_021f2878(entry);
    if ((ShowLinkResultPanel(entry) == 0) && (ShowMapUnavailableMessage(entry) == 0)) {
        return;
    }
    AddSceneObjectChild();
    GotoSpriteAnimationLabel(entry, 5);
}

void func_ov003_021f35a4(void) {
    void func_ov003_021f2e98();
    func_ov003_021f2e98();
}

