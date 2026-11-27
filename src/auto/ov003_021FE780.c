/* 9 functions from 0x021FE780 to 0x021FF3D4 (ov003), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov003_scene.h"

/* Build the ov003 map-pick list scene (menu kind 7): create the scene object,
 * install its vtables and flag/menu-kind bytes from the current map, then attach
 * its paged map list, its two number labels and its 8-byte scratch block. */
void Ov003_CreateMapPick7Scene(void *owner) {
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
    scene->flags3B.kind = 7;
}

/* Build the ov003 map-pick list scene (menu kind 8): create the scene object,
 * install its vtables and flag/menu-kind bytes from the current map, then attach
 * its paged map list, its two number labels and its 8-byte scratch block. */
void Ov003_CreateMapPick8Scene(void *owner) {
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
    scene->flags3B.kind = MENU_KIND_MAP_PICK_8;
}

/* Clear every row's drawn marker of the map-list menu entity so the whole map
 * list is redrawn, then redraw the map preview. */
void Ov003_RedrawMapList(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK Ov003_RefreshMapPreview(void *, M2C_UNK);
    extern M2C_UNK gOv003MapListMenuClass;
    void *entity;

    entity = FindObjectByClass(&gOv003MapListMenuClass);
    if (entity == NULL) {
        return;
    }
    MI_CpuFill8(M2C_FIELD(entity, s32 *, MENU_ENTITY_MAP_LIST) + MENU_MAP_LIST_DRAWN, 0, MENU_MAP_LIST_DRAWN_SIZE);
    Ov003_RefreshMapPreview(entity, 0);
}

/* Build the ov003 map-menu scene (class gOv003MapMenuClass, menu kind 1): create
 * the scene object, install its vtables and flag/menu-kind bytes from the
 * current map, then attach its paged map list, its two number labels and its
 * 8-byte scratch block. */
void Ov003_CreateMapMenuScene(void *owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK SpriteTween_Start(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    extern M2C_UNK gOv003MapMenuClass;
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003ObjectVTable;
    extern M2C_UNK gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapMenuVTable;
    extern M2C_UNK gOv003MapMenuIfaceVTable;
    extern M2C_UNK gOv003MapListVTable;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gTextLabelSlotState;
    extern void **gCurrentMap;

    Ov003MapListMenuScene *scene;
    void *child;
    u8 i;
    s32 mapId;

    scene = (Ov003MapListMenuScene *) CreateSpriteFromClass(&gOv003MapMenuClass, owner);
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
        scene->vtable = &gOv003MapMenuVTable;
        scene->iface = &gOv003MapMenuIfaceVTable;
    }
    scene->flags3B.kind = 1;
}

/* Deleting destructor of the ov003 paged map list (slot 1 of
 * gOv003MapListVTable): the list owns no heap of its own, so just free it and
 * hand the pointer back. */
s32 Ov003MapList_Delete(s32 list) {
    M2C_UNK MemFree();
    MemFree();
    return list;
}

/* Deleting destructor of the ov003 battle-setup option-list list widget
 * (slot 1 of gOv003OptionListVTable, the scene object's child4C): the list owns
 * no separate allocation, so just free it and hand the pointer back. */
s32 Ov003OptionList_Delete(s32 list) {
    M2C_UNK MemFree();
    MemFree();
    return list;
}

/* Deleting destructor of the ov003 option list's scroll-position object (slot 1
 * of gOv003OptionListScrollVTable): it owns no heap of its own, so just free it
 * and hand the pointer back. */
s32 Ov003OptionListScroll_Delete(s32 scroll) {
    M2C_UNK MemFree();
    MemFree();
    return scroll;
}

/* Point the map-select menu scene at the current map and redraw its preview. */
void Ov003_SyncMapMenuMap(void) {
    extern void **gCurrentMap;
    extern M2C_UNK gOv003MapMenuClass;
    Ov003MapMenuScene *menu;

    menu = FindObjectByClass(&gOv003MapMenuClass);
    if (menu == NULL) {
        return;
    }
    menu->mapId = (u16) M2C_FIELD(*gCurrentMap, u16 *, MAP_ID);
    Ov003_RefreshMapPreview(menu, 0);
}

/* Destroy the map menu: find the live gOv003MapMenuClass scene and run its
 * vtable destruction method at +0x10. */
void Ov003_DestroyMapMenu(void) {
    extern M2C_UNK gOv003MapMenuClass;
    Ov003MapMenuScene *menu;

    menu = FindObjectByClass(&gOv003MapMenuClass);
    if (menu == NULL) {
        return;
    }
    M2C_FIELD(*(void **)menu, void (**)(void *), 0x10)(menu);
}

