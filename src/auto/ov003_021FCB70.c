/* 24 functions from 0x021FCB70 to 0x021FD850 (ov003), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov003_scene.h"

#pragma opt_common_subs off
/* Confirms the map selected in the map-list menu: reads the map id from the
 * current list page (or from the entity for non-list modes) and, depending on
 * the menu kind, starts it or plays the unavailable-map sound. */
void ConfirmMapSelection(void *entity) {
M2C_UNK PlaySoundEffect(s32);s32 IsCampaignMapAvailable(u16);
M2C_UNK CreateMapOfferObject(u16,void *);M2C_UNK CreateMapTransferObjectMode0(u16,void *);M2C_UNK CreateMapTransferObjectMode1(u16,void *);
u16 mapId;s16 cursorRow;u8 pageIndex;u8 *pageBase;u32 menuKind=(u32)(M2C_FIELD(entity,u8 *,MENU_ENTITY_MODE)<<28)>>28;
if((u8)(menuKind==0)||(u8)(menuKind==2)||(u8)(menuKind==3)||(u8)(menuKind==4)||(u8)(menuKind==6)||(u8)(menuKind==7)||(u8)(menuKind==8)){
cursorRow=M2C_FIELD(M2C_FIELD(entity,void **,MENU_ENTITY_CURSOR),s32 *,0x14);pageIndex=M2C_FIELD(M2C_FIELD(entity,void **,MENU_ENTITY_PAGER),s32 *,4);
pageBase=M2C_FIELD(entity,u8 **,MENU_ENTITY_MAP_LIST)+(pageIndex<<9);
mapId=((u16 *)(pageBase+MENU_MAP_ENTRY_OFFSET))[(u16)cursorRow];
}else mapId=M2C_FIELD(entity,u16 *,MENU_ENTITY_MAP_ID);
if((u8)(menuKind==6)){
if(IsCampaignMapAvailable(mapId)){SetMenuPanelState(entity,1);CreateMapOfferObject(mapId,entity);PlaySoundEffect(0x1000d);return;}
PlaySoundEffect(0x1001d);return;
}
if((u8)(menuKind==7)){SetMenuPanelState(entity,2);CreateMapTransferObjectMode1(mapId,entity);PlaySoundEffect(0x1000d);return;}
if(!(u8)(menuKind==8))return;
SetMenuPanelState(entity,2);CreateMapTransferObjectMode0(mapId,entity);PlaySoundEffect(0x1000d);
}
#pragma opt_common_subs reset
/* Class-script action of the ov003 map-list scene: forward to the scene object's
 * virtual init method at vtable offset 0xC. */
void Ov003_MapListScene_CallInit(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_BUILD)(scene);
}

void func_ov003_021fcd24(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

/* Class-script action of the ov003 map-list menu scene: forward to the scene
 * object's virtual show method at vtable offset 0x14, which slides the scene
 * (and its map list) into view. */
void Ov003_MapListScene_CallShow(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_SHOW)(scene);
}

/* Prepares an entity's display objects for the current mode: places the two
 * status sprites, sets their blend/palette state, configures the parts list,
 * switches the screen phase to 1, then re-applies the BG layers for the modes
 * that stay active. */
void SetupEntityDisplay(void *entity) {
    M2C_UNK SpriteCellListSetCellRect(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK Show3DSprite(void *);
    M2C_UNK Hide3DSprite(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Show3DSpriteSlide(void *);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    M2C_UNK ApplySceneLayerVisibility();
    s32 Ov003Battle_IsSoloLinkSession();
    s32 Ov003Battle_IsLinkSessionGuest();
    void *part0;
    s16 posY;
    s16 posX;
    s32 isState2;
    s32 isState4a;
    s32 isState4b;
    s32 hasSubflag;
    s32 isState8;
    s32 isState0;
    s32 isState2b;
    s32 isState3;
    s32 isState4c;
    s32 isState6;
    s32 isState7;
    s32 tileId;
    s32 frame;
    u32 state;
    void *part18;
    void *second;
    void *part1C;
    void *first;
    void *parts;
    void *partsB;
    void *partsC;

    frame=GetSceneEntryOffset();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = frame;
    M2C_FIELD(first, s16 *, 0x10) = 0;
    M2C_FIELD(first, s16 *, 0xC) = 0xC;
    M2C_FIELD(first, u16 *, 2) = (u16) M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = -0x20;
    M2C_FIELD(second, s16 *, 0x10) = 0;
    M2C_FIELD(second, s16 *, 0xC) = 0xC;
    M2C_FIELD(second, u16 *, 2) = (u16) M2C_FIELD(second, u16 *, 4);
    parts = M2C_FIELD(entity, void **, 0x68);
    if ((Ov003Battle_IsSoloLinkSession() == 0) && (Ov003Battle_IsLinkSessionGuest() != 0)) {
        Hide3DSprite(M2C_FIELD(parts, void **, 0));
        Hide3DSprite(M2C_FIELD(parts, void **, 0xC));
        Hide3DSprite(M2C_FIELD(parts, void **, 0x10));
        Hide3DSprite(M2C_FIELD(parts, void **, 0x14));
    } else {
        Show3DSpriteSlide(M2C_FIELD(parts, void **, 0));
        Show3DSpriteSlide(M2C_FIELD(parts, void **, 0xC));
        Show3DSpriteSlide(M2C_FIELD(parts, void **, 0x10));
        Show3DSpriteSlide(M2C_FIELD(parts, void **, 0x14));
    }
    Show3DSprite(M2C_FIELD(parts, void **, 0x18));
    part18 = M2C_FIELD(parts, void **, 0x18);
    M2C_FIELD(part18, s32 *, 0x40) = (s32) ((M2C_FIELD(part18, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(part18, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(part18, s8 *, 0x5A) = 0;
    Show3DSprite(M2C_FIELD(parts, void **, 0x1C));
    part1C = M2C_FIELD(parts, void **, 0x1C);
    isState2 = 0;
    M2C_FIELD(part1C, s32 *, 0x40) = (s32) ((M2C_FIELD(part1C, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(part1C, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(part1C, s8 *, 0x5A) = 0;
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 2) {
        isState2 = 1;
    }
    if (isState2 & 0xFF) {
        Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x20));
    }
    if ((s16) M2C_FIELD(M2C_FIELD(entity, void **, 0x60), s32 *, 0x10) == 0) {
        if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
            isState4a = 1;
        } else {
            isState4a = 0;
        }
        if (!(isState4a & 0xFF)) {
            partsB = M2C_FIELD(entity, void **, 0x68);
            Hide3DSprite(M2C_FIELD(partsB, void **, 0x10));
            Hide3DSprite(M2C_FIELD(partsB, void **, 0x14));
        }
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        isState4b = 1;
    } else {
        isState4b = 0;
    }
    if (isState4b & 0xFF) {
        Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x24));
        Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 4));
        Hide3DSprite(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0));
        part0 = M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0);
        Set3DSpriteSlideTargetAndStart(part0, 0xC0, 0xC0, 0xC0, 0xC0);
        if (M2C_FIELD(M2C_FIELD(part0, void **, 0x64), u8 *, 0x12) != 0) {
            hasSubflag = 1;
        } else {
            hasSubflag = 0;
        }
        if (hasSubflag & 0xFF) {
            posY = M2C_FIELD(part0, s16 *, 0x52);
            posX = M2C_FIELD(part0, s16 *, 0x50);
            tileId = GetUnitSpriteWidth(part0);
            SpriteCellListSetCellRect(M2C_FIELD(part0, void **, 0x64), 1, posX, posY, (u16) tileId, (u16)GetUnitSpriteHeight(part0));
        }
    }
    partsC = M2C_FIELD(entity, void **, 0x6C);
    Show3DSprite(M2C_FIELD(partsC, void **, 0));
    if ((Ov003Battle_IsSoloLinkSession() == 0) && (Ov003Battle_IsLinkSessionGuest() != 0)) {
        M2C_FIELD(M2C_FIELD(partsC, void **, 0), s8 *, 0x59) = 0;
    }
    Show3DSprite(M2C_FIELD(partsC, void **, 4));
    M2C_FIELD(entity, u8 *, 0x3B) = (u8) (M2C_FIELD(entity, u8 *, 0x3B) | 0x20);
    SetOv003SceneState(1);
    state = (u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C;
    if (state == 0) {
        isState0 = 1;
    } else {
        isState0 = 0;
    }
    if (!(isState0 & 0xFF)) {
        if (state == 2) {
            isState2b = 1;
        } else {
            isState2b = 0;
        }
        if (!(isState2b & 0xFF)) {
            if (state == 3) {
                isState3 = 1;
            } else {
                isState3 = 0;
            }
            if (!(isState3 & 0xFF)) {
                if (state == 4) {
                    isState4c = 1;
                } else {
                    isState4c = 0;
                }
                if (!(isState4c & 0xFF)) {
                    if (state == 6) {
                        isState6 = 1;
                    } else {
                        isState6 = 0;
                    }
                    if (!(isState6 & 0xFF)) {
                        if (state == 7) {
                            isState7 = 1;
                        } else {
                            isState7 = 0;
                        }
                        if (!(isState7 & 0xFF)) {
                            if (state == 8) {
                                isState8 = 1;
                            } else {
                                isState8 = 0;
                            }
                            if (!(isState8 & 0xFF)) {
                                return;
                            }
                            goto finish;
                        }
                        goto finish;
                    }
                    goto finish;
                }
                goto finish;
            }
            goto finish;
        }
        goto finish;
    }
finish:
    ApplySceneLayerVisibility();
}

void func_ov003_021fd094(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

/* Class-script action of the ov003 map-list scene: forward to the scene object's
 * virtual hide method at vtable offset 0x18, which slides the scene (and its map
 * list) out of view. */
void Ov003_MapListScene_CallHide(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_HIDE)(scene);
}

/* Refreshes an entity's display data: reinitializes its two display objects and then releases the pending handles stored in its part list (plus an extra handle when the low state nibble equals 2). */
void func_ov003_021fd0b4(void *entity) {
    M2C_UNK Hide3DSpriteSlide(s32);
    s16 GetSpriteAnimValue(void *);
    s32 GetSceneSlideDirection();
    s16 GetSceneSlideOffset();
    s16 displayValue;
    s32 flag;
    void *first;
    void *second;
    void *parts;

    displayValue = GetSceneSlideOffset();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = GetSpriteAnimValue(first);
    M2C_FIELD(first, s16 *, 0x10) = displayValue;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = GetSpriteAnimValue(second);
    M2C_FIELD(second, s16 *, 0x10) = -32;
    M2C_FIELD(second, s16 *, 0xC) = 12;
    M2C_FIELD(second, u16 *, 2) = M2C_FIELD(second, u16 *, 4);
    if (!GetSceneSlideDirection()) {
        return;
    }
    parts = M2C_FIELD(entity, void **, 0x68);
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 0));
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 4));
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 8));
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 12));
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 16));
    Hide3DSpriteSlide(M2C_FIELD(parts, s32 *, 20));
    if (((u32)(M2C_FIELD(entity, u8 *, 0x3b) << 28) >> 28) == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag & 255) {
        Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 32));
    }
    Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x6c), s32 *, 4));
}

/* Class-script action of the ov003 map-list scene: forward to the scene object's
 * virtual resume method at vtable offset 0x10, which resumes its sprite animation. */
void Ov003_MapListScene_CallResume(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_RESUME)(scene);
}

/* True while the map-list menu entity's first row is still sliding into
 * place (its slide tween has not reached its duration). */
u8 Ov003_IsMapListMenuTweenRunning(void *entity) {
    SpriteTween *tween;
    s32 finished;
    u8 running;

    tween = M2C_FIELD(entity, SpriteTween **, MENU_ENTITY_TWEEN_TOP);
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

void func_ov003_021fd1cc(void) {
    M2C_UNK Ov003_AcknowledgeLinkSync();
    Ov003_AcknowledgeLinkSync();
}

void func_ov003_021fd1d8(void) {
    M2C_UNK Ov003_RefreshMapListDisplay();
    Ov003_RefreshMapListDisplay();
}

void func_ov003_021fd1e4(void) {
    M2C_UNK func_ov003_021f8c20();
    func_ov003_021f8c20();
}

/* Starts the link map transfer from the map-list menu: once the menu entity is
 * in its list mode and a link session is running with no scene transition in
 * progress, broadcast this console's player setup and open the map-transfer
 * panel. */
void BeginLinkMapTransfer(void *entity) {
    s32 IsLinkSessionActive();
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK func_ov003_021f152c(M2C_UNK);
    s32 GetSceneEntryOffset();
    M2C_UNK Ov003_BroadcastPlayerSetup(M2C_UNK);
    M2C_UNK CreateMapTransferPanelStep1(void *);
    s32 isMapList;

    if (((u32) (M2C_FIELD(entity, u8 *, MENU_ENTITY_MODE) << 0x1C) >> 0x1C) == 0) {
        isMapList = 1;
    } else {
        isMapList = 0;
    }
    if (!(isMapList & 0xFF)) {
        return;
    }
    if (IsLinkSessionActive() == 0) {
        return;
    }
    if (GetSceneEntryOffset() != 0) {
        return;
    }
    func_ov003_021f152c(1);
    SetOv003SceneState(1);
    Ov003_BroadcastPlayerSetup(1);
    CreateMapTransferPanelStep1(entity);
}

/* Whether the map-list menu entity is in menu kind 4, one of the paged map-list
 * modes (see MENU_ENTITY_MODE); the class descriptor polls this. */
u8 IsMapMenuKind4(void *entity) {
    u8 isKind4;

    if (((u32) (M2C_FIELD(entity, u8 *, MENU_ENTITY_MODE) << 0x1C) >> 0x1C) == 4) {
        isKind4 = 1;
    } else {
        isKind4 = 0;
    }
    return isKind4;
}

/* True when the entity's menu kind is one of the three kinds that open an ov006
 * map sub-panel: the campaign map list (6) and the two map-pick lists (7, 8). */
u8 IsMapSubmenuKind(void *entity) {
    s32 isKind6, isKind7, isKind8, isSubmenuKind;
    u32 menuKind;
    s32 isKind67;
    isSubmenuKind = 1;
    isKind67 = 1;
    menuKind = (u32)(M2C_FIELD(entity, u8 *, MENU_ENTITY_MODE) << 28) >> 28;
    if (menuKind == MENU_KIND_CAMPAIGN) isKind6 = 1; else isKind6 = 0;
    if (!(isKind6 & 0xFF)) {
        if (menuKind == MENU_KIND_MAP_PICK_7) isKind7 = 1; else isKind7 = 0;
        if (!(isKind7 & 0xFF)) isKind67 = 0;
    }
    if (isKind67 == 0) {
        if (menuKind == MENU_KIND_MAP_PICK_8) isKind8 = 1; else isKind8 = 0;
        if (!(isKind8 & 0xFF)) isSubmenuKind = 0;
    }
    return isSubmenuKind;
}

/* Clears the low state bits of an entity, switches it to state 4 handling, and updates its display lists/palette. */
void func_ov003_021fd2d0(void *entity) {
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Hide3DSpriteSlide(s32);
    M2C_UNK SetFrameBorderSpritePattern(s32, s32, M2C_UNK, s32);
    M2C_UNK SetTextById(s32, s32);
    s32 GetUiColor(M2C_UNK);
    M2C_UNK SetMenuPanelState(void *, M2C_UNK);
    M2C_UNK CreateCampaignMapMenuUi(void *);
    M2C_UNK ShowMapPickHint8(void *);
    M2C_UNK ShowMapPickHint7(void *);
    extern void *gCur3DSpriteEngine;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        CreateCampaignMapMenuUi(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 8) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        ShowMapPickHint8(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 7) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        ShowMapPickHint7(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (!(var_r0_4 & 0xFF)) {
        return;
    }
    M2C_FIELD(entity, u8 *, 0x3E) = (u8) (M2C_FIELD(entity, u8 *, 0x3E) & ~7);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 3, 7);
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3E) << 0x18) >> 0x1F) != 0) {
        SetMenuPanelState(entity, 4);
    }
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x10, 3, 6);
    SetTextById(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 4), 0x4700001D);
    Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 8));
    SetFrameBorderSpritePattern(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 0), 0x8B80, 1, GetUiColor(0x11));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

/* Class-script action of the ov003 map-menu scene (class gOv003MapMenuClass,
 * menu kind 1): forward to the scene object's virtual init method at vtable
 * offset 0xC, which builds the scene's sprites, layers and panels. */
void Ov003_MapMenuScene_CallInit(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_BUILD)(scene);
}

void func_ov003_021fd444(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd450(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

/* Class-script action of the ov003 map-list scene: forward to the scene object's
 * virtual init method at vtable offset 0xC (second phase using the same action). */
void Ov003_MapListScene_CallInit2(void **scene) {
    M2C_FIELD(*scene, void (**)(void *), OV003_SCENE_VT_BUILD)(scene);
}

void func_ov003_021fd470(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd47c(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

/* Build the ov003 map-list menu scene in menu kind 0 (the standard map-list
 * mode): create the scene object, install its vtables and flag/menu-kind bytes
 * from the current map, then attach its paged map list, its two number labels
 * and its 8-byte scratch block. */
void Ov003_CreateMapListScene(void *owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK SpriteTween_Start(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    M2C_UNK SetOv003SceneClass(M2C_UNK *);
    extern M2C_UNK gOv003MapListMenuClass;
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003ObjectVTable;
    extern M2C_UNK gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapListVTable;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gTextLabelSlotState;
    extern void **gCurrentMap;

    Ov003MapListMenuScene *scene;
    void *child;
    u8 i;
    s32 mapId;

    SetOv003SceneClass(&gOv003MapListMenuClass);
    scene = (Ov003MapListMenuScene *) CreateSpriteFromClass(&gOv003MapListMenuClass, owner);
    if (scene != NULL) {
        scene->vtable = &gSceneBaseVTable;
        scene->iface = &gSceneBaseIfaceVTable;
        scene->vtable = &gOv003ObjectVTable;
        scene->iface = &gOv003ObjectIfaceVTable;
        scene->state38 = 0;
        scene->visible.low = 0xA;
        scene->flags3A.low = 0;
        scene->flags3A.high = 1;
        scene->flags3B.kind = 0;
        scene->flags3B.first = 0;
        scene->flags3B.second = 0;
        scene->flags3B.third = 0;
        mapId = M2C_FIELD(*gCurrentMap, u16 *, MAP_ID);
        scene->mapId = mapId;
        scene->flags3E.flags.first = 2;
        scene->flags3E.flags.second = 7;
        scene->flags3E.flags.third = 0;
        scene->flags3E.flags.fourth = 0;

        scene->mapList = NULL;
        scene->labelSlots = &gTextLabelSlotState;
        scene->unk4C = 0;
        scene->labelA = NULL;
        scene->labelB = NULL;
        scene->unk58 = 0;
        scene->unk5C = 0;
        scene->unk60 = 0;
        scene->unk64 = 0;
        scene->unk68 = 0;
        scene->unk70 = 0;

        child = MemAlloc(0x187C);
        if (child) {
            Ov003MapList *list = child;

            list->vtable = &gOv003MapListVTable;
            list->iface = &gMapPickSelectionIfaceVTable;
            for (i = 0; i < 5; i++) {
                list->pending[i] = MAP_PICK_NONE;
                list->current[i] = list->pending[i];
            }
            list->tween.mode = SPRITE_TWEEN_SINE;
            list->tween.done = 0;
            list->tween.current = 0;
            list->tween.start = 0;
            list->tween.step = 1;
            list->tween.base = 0;
            list->tween.amplitude = 1;
            list->tween.duration = 1;
            list->tween.from = 0;
            list->tween.to = 0;
            list->tween.current = list->tween.start;
            SpriteTween_Start(&list->tween, 0x69);
            list->tween.start = 0xC000;
            list->tween.base = 8;
            list->tween.amplitude = 8;
        }
        scene->mapList = child;

        child = MemAlloc(0x2C);
        if (child) {
            SceneViewLabel *label = child;

            label->vtable = &gHeapObjectVTable;
            label->kind = 0;
            label->textId = 0;
            label->unk14 = 8;
            label->unk15 = 8;
            label->unk16 = 1;
            label->unk17 = 8;
            label->unk18 = 8;
            label->flags.first = 0;
            label->flags.second = 0;
            label->flags.third = 2;
            label->unk21 = 0;
            label->unk24 = 0;
            label->unk28 = (u8) (label->unk28 & ~0xE0);
            label->unk29 = 0;
        }
        scene->labelA = child;
        scene->labelA->unk16 = 2;
        scene->labelA->unk14 = 8;
        scene->labelA->unk17 = 8;
        SetTextSpriteValue(scene->labelA, 0);
        scene->labelA->flags.third = 2;
        scene->labelA->unk28 = (u8) ((scene->labelA->unk28 & ~0xE0) | 0x20);

        child = MemAlloc(0x2C);
        if (child) {
            SceneViewLabel *label = child;

            label->vtable = &gHeapObjectVTable;
            label->kind = 0;
            label->textId = 0;
            label->unk14 = 8;
            label->unk15 = 8;
            label->unk16 = 1;
            label->unk17 = 8;
            label->unk18 = 8;
            label->flags.first = 0;
            label->flags.second = 0;
            label->flags.third = 2;
            label->unk21 = 0;
            label->unk24 = 0;
            label->unk28 = (u8) (label->unk28 & ~0xE0);
            label->unk29 = 0;
        }
        scene->labelB = child;
        scene->labelB->unk16 = 2;
        scene->labelB->unk14 = 8;
        scene->labelB->unk17 = 8;
        SetTextSpriteValue(scene->labelB, 0);
        scene->labelB->flags.third = 2;
        scene->labelB->unk28 = (u8) (scene->labelB->unk28 & ~0xE0);
        scene->labelB->textId = 0x270;
        scene->labelB->unk21 = 9;

        child = MemAlloc(8);
        if (child) {
            ((s32 *) child)[0] = 0;
            ((s32 *) child)[1] = 0;
        }
        scene->unk6C = child;
        scene->flags3E.byte |= 0x80;
    }
    scene->flags3B.kind = 0;
}

