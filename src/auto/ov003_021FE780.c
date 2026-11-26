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
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    extern M2C_UNK data_ov003_022100d4;
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
        scene->vtable = &data_ov003_02210104;
        scene->iface = &data_ov003_02210130;
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

            list->vtable = &data_ov003_022100d4;
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

void func_ov003_021feb4c(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK SpriteTween_Start(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    M2C_UNK SetOv003SceneClass(M2C_UNK *);
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gTextLabelSlotState;
    extern void **data_027e0058;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003MapListMenuClass;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    SetOv003SceneClass(&gOv003MapListMenuClass);
    temp_r0 = CreateSpriteFromClass(&gOv003MapListMenuClass, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &gTextLabelSlotState;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = MemAlloc(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &gMapPickSelectionIfaceVTable;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
                var_r0 += 1;
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, (u32)0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            SpriteTween_Start(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = MemAlloc(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
        temp_r0_4 = MemAlloc(0x2C);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = MemAlloc(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 0x8);
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

void func_ov003_021fef58(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK SpriteTween_Start(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gTextLabelSlotState;
    extern void **gCurrentMap;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003MapMenuClass;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac;
    extern M2C_UNK data_ov003_022101d8;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    temp_r0 = CreateSpriteFromClass(&gOv003MapMenuClass, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gSceneBaseVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gSceneBaseIfaceVTable;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0x40) & ~0x80;
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        M2C_FIELD(temp_r0, u8 *, 0x3E) = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) & ~0x40) & ~0x80;
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &gTextLabelSlotState;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = MemAlloc(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &gMapPickSelectionIfaceVTable;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
                var_r0 += 1;
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            SpriteTween_Start(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = MemAlloc(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
        temp_r0_4 = MemAlloc(0x2C);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = MemAlloc(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_022101ac;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_022101d8;
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) | 0x1);
}

s32 func_ov003_021ff330(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

s32 func_ov003_021ff344(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

s32 func_ov003_021ff358(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
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

