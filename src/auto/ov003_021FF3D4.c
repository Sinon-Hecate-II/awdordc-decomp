/* 7 functions from 0x021FF3D4 to 0x022001EC (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_scene.h"
#include "battle_map.h"

/* Build the ov003 map-panel scene (class gOv003MapPanelClass, menu kind 5) for
 * the current map: install its vtables and flag bytes, then attach the paged
 * map list, the two number labels and the 8-byte scratch block. */
void Ov003_CreateMapPanelScene(void *owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK SpriteTween_Start(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    extern M2C_UNK gOv003MapPanelClass;
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003ObjectVTable;
    extern M2C_UNK gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapPanelVTable;
    extern M2C_UNK gOv003MapPanelIfaceVTable;
    extern M2C_UNK gOv003MapListVTable;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gTextLabelSlotState;
    extern void **gCurrentMap;

    Ov003MapListMenuScene *scene;
    void *child;
    u8 i;
    s32 mapId;

    scene = (Ov003MapListMenuScene *) CreateSpriteFromClass(&gOv003MapPanelClass, owner);
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
        scene->vtable = &gOv003MapPanelVTable;
        scene->iface = &gOv003MapPanelIfaceVTable;
    }
    scene->flags3B.kind = 5;
}

/* Find the ov003 map-panel object of class gOv003MapPanelClass and run its
 * virtual animation-resume step (vtable slot 0x10), which unfreezes the panel's
 * sprite animation once its appearance delay has passed.  Does nothing when the
 * panel is not loaded. */
void Ov003_ResumeMapPanelAnimation(void) {
    extern M2C_UNK gOv003MapPanelClass;
    void *panel;
    panel = FindObjectByClass(&gOv003MapPanelClass);
    if (panel == NULL) {
        return;
    }
    M2C_FIELD(*(void **)panel, void (**)(void *), 0x10)(panel);
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff7d4(void *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void RemoveMapViewSprites(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    void func_ov003_021f1920(void);
    void DeleteOv003SceneSprite(void);
    extern M2C_UNK gOv003ObjectVTable, gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapPanelVTable, gOv003MapPanelIfaceVTable;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &gOv003MapPanelVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003MapPanelIfaceVTable;
    func_ov003_021f1920();
    DeleteOv003SceneSprite();
    M2C_FIELD(obj, void **, 0) = &gOv003ObjectVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003ObjectIfaceVTable;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        HeapFreeBlock(M2C_FIELD(sub, s32 *, 0x14));
        MemFree(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) MemFree(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) MemFree(child);
    sub = M2C_FIELD(obj, void **, 104);
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
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        MemFree(sub);
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff9dc(void *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void RemoveMapViewSprites(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    void func_ov003_021f1920(void);
    void DeleteOv003SceneSprite(void);
    extern M2C_UNK gOv003ObjectVTable, gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapPanelVTable, gOv003MapPanelIfaceVTable;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &gOv003MapPanelVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003MapPanelIfaceVTable;
    func_ov003_021f1920();
    DeleteOv003SceneSprite();
    M2C_FIELD(obj, void **, 0) = &gOv003ObjectVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003ObjectIfaceVTable;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        HeapFreeBlock(M2C_FIELD(sub, s32 *, 0x14));
        MemFree(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) MemFree(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) MemFree(child);
    sub = M2C_FIELD(obj, void **, 104);
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
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        MemFree(sub);
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    MemFree(obj);
    return obj;
}

/* Releases all owned sub-objects but does not free this object (vtable reset to base first). */
void *func_ov003_021ffbec(void *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void RemoveMapViewSprites(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    void DeleteWallpaperSpritesOnAllEngines(void);
    void DeleteOv003SceneSprite(void);
    extern M2C_UNK gOv003ObjectVTable, gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapMenuVTable, gOv003MapMenuIfaceVTable;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &gOv003MapMenuVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003MapMenuIfaceVTable;
    DeleteWallpaperSpritesOnAllEngines();
    DeleteOv003SceneSprite();
    M2C_FIELD(obj, void **, 0) = &gOv003ObjectVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003ObjectIfaceVTable;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        HeapFreeBlock(M2C_FIELD(sub, s32 *, 0x14));
        MemFree(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) MemFree(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) MemFree(child);
    sub = M2C_FIELD(obj, void **, 104);
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
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        MemFree(sub);
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ffdf4(void *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void RemoveMapViewSprites(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    void DeleteWallpaperSpritesOnAllEngines(void);
    void DeleteOv003SceneSprite(void);
    extern M2C_UNK gOv003ObjectVTable, gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapMenuVTable, gOv003MapMenuIfaceVTable;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &gOv003MapMenuVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003MapMenuIfaceVTable;
    DeleteWallpaperSpritesOnAllEngines();
    DeleteOv003SceneSprite();
    M2C_FIELD(obj, void **, 0) = &gOv003ObjectVTable;
    M2C_FIELD(obj, void **, 0x34) = &gOv003ObjectIfaceVTable;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        HeapFreeBlock(M2C_FIELD(sub, s32 *, 0x14));
        MemFree(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) MemFree(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) MemFree(child);
    sub = M2C_FIELD(obj, void **, 104);
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
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) DeleteSpriteObject(M2C_FIELD(sub, void **, 4));
        MemFree(sub);
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    MemFree(obj);
    return obj;
}

/* Base destructor of the ov003 scene object: resets the vtables to the base
   ones, then releases every owned child, buffer and sprite array without
   freeing the object itself. */
void *Ov003Object_Destructor(Ov003Object *obj) {
    void DeleteSpriteObject(void *);
    void MemFree(void *);
    void RemoveMapViewSprites(void);
    void HeapFreeBlock(s32);
    void SetOv003SceneState(s32);
    void DeleteWallpaperSpritesOnAllEngines(void);
    void DeleteOv003SceneSprite(void);
    extern M2C_UNK gOv003ObjectVTable, gOv003ObjectIfaceVTable;
    extern M2C_UNK gOv003MapMenuVTable, gOv003MapMenuIfaceVTable;
    void *sub;
    void *child;
    obj->vtable = &gOv003ObjectVTable;
    obj->iface = &gOv003ObjectIfaceVTable;
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
    RemoveMapViewSprites();
    return obj;
}

