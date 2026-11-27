/* 36 functions from 0x021E4448 to 0x021E5118 (ov003), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov003_scene.h"

void func_ov003_021e4448(void *arg0){
M2C_UNK LoadSavedMapPickLists(void *);M2C_UNK SetOv003SceneState(M2C_UNK);M2C_UNK CountMapPicks(M2C_UNK,M2C_UNK *);M2C_UNK CreateMapTransferPanel(M2C_UNK,M2C_UNK,M2C_UNK);s32 LoadMapRecord(s32,s32);
extern M2C_UNK gMapPickSelectionIfaceVTable;
struct {void *data;u16 buf0[5];u16 buf1[5];}local;
u32 count;u8 i; void *block;void *base;u16 val;u8 zero;
local.data=&gMapPickSelectionIfaceVTable;
for(i=0;i<5;i++){local.buf1[i]=65535;local.buf0[i]=local.buf1[i];}
LoadSavedMapPickLists(&local);SetOv003SceneState(1);
i=0;zero=i;block=&local;
do{
count=CountMapPicks((M2C_UNK)block,local.buf0);
base=M2C_FIELD(arg0,void **,0x68);
if((u32)i>=count)M2C_FIELD((s32)base+i*0x6f8,u8 *,0x27)=zero;
else{
val=M2C_FIELD(block+i*2,u16 *,4);
LoadMapRecord(val,(s32)base+i*0x6f8);
}
i++;
}while(i<5);
CreateMapTransferPanel(arg0,M2C_FIELD(arg0,void **,0x68),M2C_FIELD(arg0,void **,0x6c));
}

void func_ov003_021e450c(void) {

}

/* Drops downloaded map records that are identical to a campaign map: marks the
 * matching record empty, removes its id from the downloaded-map selection, and
 * packs the remaining records down. */
void RemoveDownloadedCampaignMaps(void *view) {
    s32 FindCampaignMapId(void *);
    void RemoveDownloadedMapId();
    void *HeapAllocBlock(s32);
    void MI_CpuCopy32(void *, void *, u32);
    void HeapFreeBlock(void *);
    u8 anyRemoved = 0;
    u8 *record;
    u8 k;
    u8 *copy;
    u8 i, kept;
    u8 *mapRecords;
    u32 slotOffset;

    for (k = 0; k < MAP_RECORD_LIST_COUNT; k++) {
        record = M2C_FIELD(view, u8 **, 0x6c) + k * MAP_RECORD_SIZE;
        if ((u16)FindCampaignMapId(record)) {
            record[MAP_RECORD_PLAYER_COUNT] = 0;
            RemoveDownloadedMapId();
            anyRemoved = 1;
        }
    }
    if (!anyRemoved) return;
    copy = HeapAllocBlock(MAP_RECORD_LIST_SIZE);
    MI_CpuCopy32(M2C_FIELD(view, void **, 0x6c), copy, MAP_RECORD_LIST_SIZE);
    for (kept = 0, i = 0; i < MAP_RECORD_LIST_COUNT; i++) {
        record = copy + i * MAP_RECORD_SIZE;
        slotOffset = kept * MAP_RECORD_SIZE;
        mapRecords = M2C_FIELD(view, u8 **, 0x6c);
        if (record[MAP_RECORD_PLAYER_COUNT]) {
            MI_CpuCopy32(record, mapRecords + slotOffset, MAP_RECORD_SIZE);
            kept++;
        }
    }
    while (kept < MAP_RECORD_LIST_COUNT) {
        M2C_FIELD(M2C_FIELD(view, u8 **, 0x6c) + kept * MAP_RECORD_SIZE, u8 *, MAP_RECORD_PLAYER_COUNT) = 0;
        kept++;
    }
    HeapFreeBlock(copy);
}

void func_ov003_021e4610(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021e4624(void) {
    M2C_UNK func_ov003_021e2518();
    func_ov003_021e2518();
}

void func_ov003_021e4630(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

/* Intro handler of the ov003 scene view (its +0x14 interface method): arms the
 * two slide tweens (the top from off-screen 0x100, the bottom from -0x20), shows
 * the view's sprites and marks the view visible. */
void Ov003_ShowSceneView(void *scene) {
    M2C_UNK Show3DSprite(s32);
    M2C_UNK Show3DSpriteSlide(s32);
    SpriteTween *tweenTop;
    SpriteTween *tweenBottom;
    void *spritePair;

    tweenTop = M2C_FIELD(scene, SpriteTween **, 0x3C);
    tweenTop->from = 0x100;
    tweenTop->to = 0;
    tweenTop->duration = 0xC;
    tweenTop->current = tweenTop->start;
    tweenBottom = M2C_FIELD(scene, SpriteTween **, 0x40);
    tweenBottom->from = -0x20;
    tweenBottom->to = 0;
    tweenBottom->duration = 0xC;
    tweenBottom->current = tweenBottom->start;
    Show3DSprite(M2C_FIELD(scene, s32 *, 0x4C));
    Show3DSpriteSlide(M2C_FIELD(scene, s32 *, 0x58));
    spritePair = M2C_FIELD(scene, void **, 0x44);
    Show3DSpriteSlide(M2C_FIELD(spritePair, s32 *, 0));
    Show3DSpriteSlide(M2C_FIELD(spritePair, s32 *, 4));
    M2C_FIELD(scene, s8 *, 0x39) = 1;
}

void func_ov003_021e46bc(void) {
    M2C_UNK func_ov003_021e2628();
    func_ov003_021e2628();
}

void func_ov003_021e46c8(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

/* Starts the map-transfer panel's slide-out and hides its sprites when the panel is marked unavailable. */
u32 SlideOutMapTransferPanelWhenEmpty(void *panel) {
    u32 Hide3DSpriteSlide(s32);
    s16 GetSpriteAnimValue(void *);
    u32 unavailable;
    void *spritePair;
    void *topTween;
    void *bottomTween;

    unavailable = (u32) (((Ov003MapTransferPanel *)panel)->mapFlags << 0x18) >> 0x1F;
    if (unavailable == 0) {
        return unavailable;
    }
    topTween = ((Ov003MapTransferPanel *)panel)->topTween;
    M2C_FIELD(topTween, s16 *, 0xE) = GetSpriteAnimValue(topTween);
    M2C_FIELD(topTween, s16 *, 0x10) = 0;
    M2C_FIELD(topTween, s16 *, 0xC) = OV003_MAP_TRANSFER_SLIDE_FRAMES;
    M2C_FIELD(topTween, u16 *, 2) = (u16) M2C_FIELD(topTween, u16 *, 4);
    bottomTween = ((Ov003MapTransferPanel *)panel)->bottomTween;
    M2C_FIELD(bottomTween, s16 *, 0xE) = GetSpriteAnimValue(bottomTween);
    M2C_FIELD(bottomTween, s16 *, 0x10) = -0x20;
    M2C_FIELD(bottomTween, s16 *, 0xC) = OV003_MAP_TRANSFER_SLIDE_FRAMES;
    M2C_FIELD(bottomTween, u16 *, 2) = (u16) M2C_FIELD(bottomTween, u16 *, 4);
    Hide3DSpriteSlide(((Ov003MapTransferPanel *)panel)->sprite);
    spritePair = ((Ov003MapTransferPanel *)panel)->spritePair;
    Hide3DSpriteSlide(M2C_FIELD(spritePair, s32 *, 0));
    return Hide3DSpriteSlide(M2C_FIELD(spritePair, s32 *, 4));
}

void func_ov003_021e4764(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

/* Whether the scene view's top intro tween is still running (its frame counter
 * has not reached its duration); the iface method the state machine polls. */
u8 Ov003_IsSceneViewTweenRunning(void *view) {
    s32 finished;
    u8 running;
    SpriteTween *tween;

    tween = M2C_FIELD(view, SpriteTween **, 0x3C);
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

void func_ov003_021e47a4(void) {
    void func_ov003_021e4448();
    func_ov003_021e4448();
}

void func_ov003_021e47b0(void) {
    void RemoveDownloadedCampaignMaps();
    RemoveDownloadedCampaignMaps();
}

/* Recompute the scene view's map-transfer-unavailable flag: mark the transfer
 * unavailable when neither side has a map picked and the matching five-record map
 * list is empty, then return the flag. */
u32 Ov003_UpdateMapTransferAvailability(void *view) {
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    struct { void *iface; u16 firstPicks[5]; u16 secondPicks[5]; } picks;
    u8 count;
    u8 i;
    M2C_FIELD(view, u8 *, 0x60) = (u8)(M2C_FIELD(view, u8 *, 0x60) & ~OV003_MAP_TRANSFER_UNAVAILABLE);
    picks.iface = (void *)&gMapPickSelectionIfaceVTable;
    for (i = 0; i < MAP_RECORD_LIST_COUNT; i++) {
        picks.secondPicks[i] = MAP_PICK_NONE;
        picks.firstPicks[i] = picks.secondPicks[i];
    }
    LoadSavedMapPickLists(&picks);
    {
        u8 count;
        u8 i;
        count = 0;
        for (i = 0; i < MAP_RECORD_LIST_COUNT; i++) {
            if (M2C_FIELD((s32)M2C_FIELD(view, void **, 0x6C) + (s32)i * MAP_RECORD_SIZE, u8 *, MAP_RECORD_PLAYER_COUNT) != 0) {
                count++;
            }
        }
        if (count == 0 && CountMapPicks((s32)&picks, picks.firstPicks) == 0) {
            M2C_FIELD(view, u8 *, 0x60) = (u8)(M2C_FIELD(view, u8 *, 0x60) | OV003_MAP_TRANSFER_UNAVAILABLE);
        }
    }
    {
        u8 count;
        u8 i;
        count = 0;
        for (i = 0; i < MAP_RECORD_LIST_COUNT; i++) {
            if (M2C_FIELD((s32)M2C_FIELD(view, void **, 0x68) + (s32)i * MAP_RECORD_SIZE, u8 *, MAP_RECORD_PLAYER_COUNT) != 0) {
                count++;
            }
        }
        if (count == 0 && CountMapPicks((s32)&picks, picks.secondPicks) == 0) {
            M2C_FIELD(view, u8 *, 0x60) = (u8)(M2C_FIELD(view, u8 *, 0x60) | OV003_MAP_TRANSFER_UNAVAILABLE);
        }
    }
    return (u32)((u32)M2C_FIELD(view, u8 *, 0x60) << 24) >> 31;
}

void func_ov003_021e48dc(void) {
    M2C_UNK func_ov003_021f14a0();
    func_ov003_021f14a0();
}

/* Reset the map-select state after leaving the screen: keep map confirmation
 * enabled, put the scene phase back to map select (2) and clear the view's
 * state byte. */
void Ov003_ResetMapSelectState(void *view) {
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK Ov003_SetMapConfirmEnabled();
    Ov003_SetMapConfirmEnabled();
    SetOv003SceneState(2);
    ((Ov003SceneView *)view)->state38 = 0;
}

/* Create the ov003 scene view (class gOv003SceneViewClass): make the scene
 * object, install its vtables, then build its two intro slide tweens, the
 * 11-glyph label group, the two number labels, the map-pick selection child and
 * the two five-map record lists it switches between. */
void CreateOv003SceneView(void *owner) {
    void SetOv003SceneClass(M2C_UNK *);
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK *);
    void *MemAlloc(s32);
    void SetTextSpriteValue(void *, s32);
    void *HeapAllocBlock(s32);
    void AddRecordValue(s32, s32);
    extern M2C_UNK gOv003SceneViewClass;
    extern M2C_UNK gSceneBaseVTable;
    extern M2C_UNK gSceneBaseIfaceVTable;
    extern M2C_UNK gOv003SceneViewVTable;
    extern M2C_UNK gOv003SceneViewIfaceVTable;
    extern M2C_UNK gMapPickSelectionVTable;
    extern M2C_UNK gMapPickSelectionIfaceVTable;
    extern M2C_UNK gSceneLabelGroupVTable;
    extern M2C_UNK gHeapObjectVTable;

    Ov003SceneView *view;
    void *child;
    u8 i;

    SetOv003SceneClass(&gOv003SceneViewClass);
    view = (Ov003SceneView *)CreateSpriteFromClass(&gOv003SceneViewClass, owner);
    if (view == NULL) {
        return;
    }

    view->vtable = &gSceneBaseVTable;
    view->iface = &gSceneBaseIfaceVTable;
    view->vtable = &gOv003SceneViewVTable;
    view->iface = &gOv003SceneViewIfaceVTable;

    view->state38 = 0;
    view->visible = 0;
    view->flags3A = 0;
    view->tweenTop = NULL;
    view->tweenBottom = NULL;
    view->spritePair = NULL;
    view->labelGroup = NULL;
    view->sprite4C = 0;
    view->labelA = NULL;
    view->labelB = NULL;
    view->sprite58 = 0;
    view->selection = NULL;

    view->flags.first = 0;
    view->flags.second = 0;
    view->flags.third = 0;
    view->flags.fourth = 0;
    view->flags.fifth = 0;
    view->mapRecords = NULL;
    view->downloadedMaps = NULL;

    child = MemAlloc(0x58);
    if (child) {
        MapPickSelection *selection = child;

        selection->vtable = &gMapPickSelectionVTable;
        selection->iface = &gMapPickSelectionIfaceVTable;
        for (i = 0; i < 5; i++) {
            selection->pending[i] = MAP_PICK_NONE;
            selection->current[i] = selection->pending[i];
        }
    }
    view->selection = child;

    child = MemAlloc(0x12);
    if (child) {
        SpriteTween *tween = child;

        tween->mode = SPRITE_TWEEN_EASE_OUT;
        tween->done = 0;
        tween->current = 0;
        tween->start = 0;
        tween->step = 1;
        tween->base = 0;
        tween->amplitude = 1;
        tween->duration = 1;
        tween->from = 0;
        tween->to = 0;
        tween->current = tween->start;
    }
    view->tweenTop = child;

    child = MemAlloc(0x12);
    if (child) {
        SpriteTween *tween = child;

        tween->mode = SPRITE_TWEEN_EASE_OUT;
        tween->done = 0;
        tween->current = 0;
        tween->start = 0;
        tween->step = 1;
        tween->base = 0;
        tween->amplitude = 1;
        tween->duration = 1;
        tween->from = 0;
        tween->to = 0;
        tween->current = tween->start;
    }
    view->tweenBottom = child;

    child = MemAlloc(0x8);
    if (child) {
        ((s32 *)child)[0] = 0;
        ((s32 *)child)[1] = 0;
    }
    view->spritePair = child;

    child = MemAlloc(0x3C);
    if (child) {
        SceneViewLabelGroup *group = child;

        group->vtable = &gSceneLabelGroupVTable;
        group->color = -1;
        group->palette = -1;
        group->flags = 0xFF;
        group->unk07 = 0;
        group->unk08 = 0;
        group->unk09 = 0;
        group->unk0A = 0;
        group->unk0B = 0;
        group->count = 0;
        for (i = 0; i < 11; i++) {
            group->glyphs[i] = 0;
        }
    }
    view->labelGroup = child;

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
        label->unk28 = (u8)(label->unk28 & ~0xE0);
        label->unk29 = 0;
    }
    view->labelA = child;
    view->labelA->unk16 = 2;
    view->labelA->unk14 = 8;
    view->labelA->unk17 = 8;
    SetTextSpriteValue(view->labelA, 0);
    view->labelA->flags.third = 2;
    view->labelA->unk28 = (u8)((view->labelA->unk28 & ~0xE0) | 0x20);

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
        label->unk28 = (u8)(label->unk28 & ~0xE0);
        label->unk29 = 0;
    }
    view->labelB = child;
    view->labelB->unk16 = 2;
    view->labelB->unk14 = 8;
    view->labelB->unk17 = 8;
    SetTextSpriteValue(view->labelB, 0);
    view->labelB->flags.third = 2;
    view->labelB->unk28 = (u8)(view->labelB->unk28 & ~0xE0);
    view->labelB->textId = 0x270;
    view->labelB->unk21 = 9;

    view->mapRecords = HeapAllocBlock(MAP_RECORD_LIST_SIZE);
    view->downloadedMaps = HeapAllocBlock(MAP_RECORD_LIST_SIZE);
    AddRecordValue(0x22, 1);
}

/* Base (non-deleting) destructor of the ov003 battle-scene view: restores the
 * base vtables and releases the sub-objects, sprite handles and map-record
 * buffers it owns, then returns the object still allocated.  Its vtable
 * neighbour DestroyOv003SceneView frees the object as well. */
void *Ov003SceneView_Destructor(void *obj) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK MemFree();
    M2C_UNK RemoveMapViewSprites();
    M2C_UNK LoadCampaignMapHeaders();
    void HeapFreeBlock(void *);
    extern M2C_UNK gOv003SceneViewVTable;
    extern M2C_UNK gOv003SceneViewIfaceVTable;
    M2C_UNK SetOv003SceneState(s32);
    void **child5C;
    void **child48;
    void **child50;
    void **child54;
    void *spritePair;

    M2C_FIELD(obj, M2C_UNK **, 0) = &gOv003SceneViewVTable;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &gOv003SceneViewIfaceVTable;
    LoadCampaignMapHeaders();
    child5C = M2C_FIELD(obj, void ***, 0x5C);
    if (child5C != NULL) {
        M2C_FIELD(*child5C, void (**)(void *), 4)(child5C);
    }
    if (M2C_FIELD(obj, s32 *, 0x3C) != 0) {
        MemFree();
    }
    if (M2C_FIELD(obj, s32 *, 0x40) != 0) {
        MemFree();
    }
    spritePair = M2C_FIELD(obj, void **, 0x44);
    if (spritePair != NULL) {
        if (M2C_FIELD(spritePair, s32 *, 0) != 0) {
            DeleteSpriteObject();
        }
        if (M2C_FIELD(spritePair, s32 *, 4) != 0) {
            DeleteSpriteObject();
        }
        MemFree(spritePair);
    }
    child48 = M2C_FIELD(obj, void ***, 0x48);
    if (child48 != NULL) {
        M2C_FIELD(*child48, void (**)(void *), 4)(child48);
    }
    child50 = M2C_FIELD(obj, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child54 = M2C_FIELD(obj, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(obj, s32 *, 0x4C) != 0) {
        DeleteSpriteObject();
    }
    if (M2C_FIELD(obj, s32 *, 0x58) != 0) {
        DeleteSpriteObject();
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    if (M2C_FIELD(obj, s32 *, 0x68) != 0) {
        HeapFreeBlock(M2C_FIELD(obj, s32 *, 0x68));
    }
    if (M2C_FIELD(obj, s32 *, 0x6C) != 0) {
        HeapFreeBlock(M2C_FIELD(obj, s32 *, 0x6C));
    }
    return obj;
}

s32 func_ov003_021e4e58(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Deleting destructor of a scene-view label group: restore the group's vtable,
 * delete its eleven glyph sprites, then free the group itself. */
SceneViewLabelGroup *DestroySceneViewLabelGroup(SceneViewLabelGroup *group) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK MemFree();
    extern M2C_UNK gSceneLabelGroupVTable;
    u8 i;

    group->vtable = &gSceneLabelGroupVTable;
    i = 0;
    do {
        if (group->glyphs[i] != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while ((u32) i < SCENE_LABEL_GLYPH_COUNT);
    MemFree(group);
    return group;
}

/* Destructor of the ov003 battle-scene object: resets its two vtables, releases
 * the text sprites, child objects, sprite arrays and map-record buffers it owns,
 * then frees the object itself. */
void *DestroyOv003SceneView(void *obj) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK MemFree();
    M2C_UNK RemoveMapViewSprites();
    M2C_UNK LoadCampaignMapHeaders();
    void HeapFreeBlock(void *);
    extern M2C_UNK gOv003SceneViewVTable;
    extern M2C_UNK gOv003SceneViewIfaceVTable;
    M2C_UNK SetOv003SceneState(s32);
    void **child5C;
    void **child48;
    void **child50;
    void **child54;
    void *spritePair;

    M2C_FIELD(obj, M2C_UNK **, 0) = &gOv003SceneViewVTable;
    M2C_FIELD(obj, M2C_UNK **, 0x34) = &gOv003SceneViewIfaceVTable;
    LoadCampaignMapHeaders();
    child5C = M2C_FIELD(obj, void ***, 0x5C);
    if (child5C != NULL) {
        M2C_FIELD(*child5C, void (**)(void *), 4)(child5C);
    }
    if (M2C_FIELD(obj, s32 *, 0x3C) != 0) {
        MemFree();
    }
    if (M2C_FIELD(obj, s32 *, 0x40) != 0) {
        MemFree();
    }
    spritePair = M2C_FIELD(obj, void **, 0x44);
    if (spritePair != NULL) {
        if (M2C_FIELD(spritePair, s32 *, 0) != 0) {
            DeleteSpriteObject();
        }
        if (M2C_FIELD(spritePair, s32 *, 4) != 0) {
            DeleteSpriteObject();
        }
        MemFree(spritePair);
    }
    child48 = M2C_FIELD(obj, void ***, 0x48);
    if (child48 != NULL) {
        M2C_FIELD(*child48, void (**)(void *), 4)(child48);
    }
    child50 = M2C_FIELD(obj, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child54 = M2C_FIELD(obj, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(obj, s32 *, 0x4C) != 0) {
        DeleteSpriteObject();
    }
    if (M2C_FIELD(obj, s32 *, 0x58) != 0) {
        DeleteSpriteObject();
    }
    SetOv003SceneState(4);
    RemoveMapViewSprites();
    if (M2C_FIELD(obj, s32 *, 0x68) != 0) {
        HeapFreeBlock(M2C_FIELD(obj, s32 *, 0x68));
    }
    if (M2C_FIELD(obj, s32 *, 0x6C) != 0) {
        HeapFreeBlock(M2C_FIELD(obj, s32 *, 0x6C));
    }
    MemFree(obj);
    return obj;
}

/* Destructor core of the scene-view label group: reset its vtable to the base
 * one and delete each of its eleven glyph sprites (the deleting destructor then
 * frees the group itself). */
SceneViewLabelGroup *ReleaseSceneViewLabelGroup(SceneViewLabelGroup *group) {
    M2C_UNK DeleteSpriteObject();
    extern M2C_UNK gSceneLabelGroupVTable;
    u8 i;

    group->vtable = &gSceneLabelGroupVTable;
    i = 0;
    do {
        if (group->glyphs[i] != 0) {
            DeleteSpriteObject();
        }
        i += 1;
    } while ((u32) i < SCENE_LABEL_GLYPH_COUNT);
    return group;
}

void func_ov003_021e5030(void) {

}

/* Deleting destructor of an empty class: free the object, then return it. */
s32 func_ov003_021e5034(s32 object) {
    M2C_UNK MemFree();
    MemFree(object);
    return object;
}

void func_ov003_021e5048(void) {

}

/* Deleting destructor of an empty class: free the object, then return it. */
s32 func_ov003_021e504c(s32 object) {
    M2C_UNK MemFree();
    MemFree(object);
    return object;
}

#pragma peephole off
#pragma interworking off
void func_ov003_021e5060(s32 arg0) {
    void *DestroyOv003SceneView(void *);
    DestroyOv003SceneView(arg0 + 0xFFFFFFCC);
}
#pragma interworking reset
#pragma peephole reset
/* Whether the rectangle at (x, y) with the given width and height overlaps the
 * 256x192 screen at all (a rectangle entirely off any side does not). */
s32 Ov003_IsRectOnScreen(s32 x, s32 y, s32 width, s32 height) {
    if (x + width < 0 || x > SCREEN_WIDTH) return 0;
    if (y + height < 0 || y > SCREEN_HEIGHT) return 0;
    return 1;
}

