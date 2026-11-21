/* 65 functions from 0x0209CC04 to 0x0209DB48 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* Initialise the 3D sprite object pool and its allocator: every object is emptied
 * (dead, no class or links, no depth), the order array lists the whole pool with
 * the allocator's free-slot cursor at its front, and the twelve per-layer lists
 * start empty. */
void Init3DSpritePool(void) {
    extern M2C_UNK g3DSpriteOrderCursor;
    extern s32 g3DSpriteLayerLists[];
    extern void *g3DSpriteSortOrder[];
    extern M2C_UNK g3DSpriteObjectPool;
    u8 *object;
    s32 i;
    s32 layer;
    i = 0;
    object = (u8 *)&g3DSpriteObjectPool;
    do {
        M2C_FIELD(object, s32 *, DS3D_SPRITE_CLASS) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_ALIVE) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_ANIM) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_DELETE_CB) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_UPDATE_CB) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_DRAW_CB) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_PARENT) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_CHILD) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_PREV) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_NEXT) = 0;
        M2C_FIELD(object, s32 *, DS3D_SPRITE_ENGINE) = 0;
        M2C_FIELD(object, s16 *, DS3D_SPRITE_LAYER) = 0;
        M2C_FIELD(object, u16 *, DS3D_SPRITE_Z) = DS3D_SPRITE_Z_NONE;
        M2C_FIELD(object, s8 *, DS3D_SPRITE_FLAGS) = DS3D_SPRITE_FLAG_DEAD;
        g3DSpriteSortOrder[i] = object;
        i++;
        M2C_FIELD(object, s8 *, DS3D_SPRITE_CHILD_COUNT) = 0;
        object += DS3D_SPRITE_SIZE;
    } while (i < DS3D_SPRITE_COUNT);
    M2C_FIELD(&g3DSpriteOrderCursor, s32 *, DS3D_ALLOC_TAIL) = 0;
    M2C_FIELD(&g3DSpriteOrderCursor, void **, DS3D_ALLOC_CURSOR) = &g3DSpriteSortOrder;
    layer = 0;
    do {
        g3DSpriteLayerLists[layer] = 0;
        layer++;
    } while (layer < 12);
}

void func_0209cca8(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 0x34)(arg0);
}

void CreateQueuedSpriteTask(s32 arg0) {
    void *CreateSpriteFromClass(M2C_UNK *);
    extern M2C_UNK data_0211e010;
    M2C_FIELD(CreateSpriteFromClass(&data_0211e010), s32 *, 0x34) = arg0;
}

void func_0209ccd4(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 0x34)(arg0);
}

void func_0209cce4(s32 arg0) {
    void *CreateSpriteFromClass(M2C_UNK *);
    extern M2C_UNK data_0211dff0;
    M2C_FIELD(CreateSpriteFromClass(&data_0211dff0), s32 *, 0x34) = arg0;
}

void func_0209cd00(s32 arg0) {
 M2C_UNK DeleteSpriteObject();
 extern M2C_UNK data_0211dff0;
 extern M2C_UNK g3DSpriteObjectPool;
 u8 *p;
 s32 i;
 p = (u8 *)&g3DSpriteObjectPool;
 i = 0;
 do {
  if (M2C_FIELD(p, void **, 4) == &data_0211dff0 && M2C_FIELD(p, s32 *, 0x34) == arg0) DeleteSpriteObject(p);
  i++;
  p += 0x74;
 } while (i < 0x80);
}

s32 func_0209cd4c(void) {
    M2C_UNK DeleteSpriteObject();
    DeleteSpriteObject();
    return 0;
}

s32 func_0209cd5c(void) {
    return 0;
}

s32 func_0209cd64(void) {
    return 1;
}

s32 func_0209cd6c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 1;
}

s32 func_0209cd80(void *arg0) {
    M2C_UNK func_01ffa918(void *, s32);
    func_01ffa918(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cda8(void *arg0) {
    M2C_UNK func_01ffa920(void *, s32);
    func_01ffa920(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cdd0(void *arg0) {
    void *temp_r1;
    M2C_UNK (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, M2C_UNK (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    fn(arg0);
    return 1;
}

s32 func_0209cdf0(void *arg0) {
    void *temp_r2;
    s16 value;
    M2C_UNK (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, M2C_UNK (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    fn(arg0, value);
    return 1;
}

s32 func_0209ce14(void *arg0) {
    void *temp_r1;
    s32 (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    if (fn(arg0) == 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209ce50(void *arg0) {
    void *temp_r2;
    s16 value;
    s32 (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    if (fn(arg0, value) == 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209ce90(void *arg0) {
    void *temp_r1;
    s32 (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    if (fn(arg0) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209cecc(void *arg0) {
    void *temp_r2;
    s16 value;
    s32 (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    if (fn(arg0, value) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209cf0c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209cf2c(void *arg0) {
    s32 FindObjectByClass(s32);
    if (FindObjectByClass(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cf60(void *arg0) {
    CreateSpriteFromClass(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4), arg0);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cf8c(void *arg0) {
    M2C_UNK CreateSpriteObject(s32, void *);
    CreateSpriteObject(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4), arg0);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209cfb8(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    CreateSpriteFromClass(M2C_FIELD(temp_r0, s32 *, 4), M2C_FIELD(temp_r0, s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cfe4(void *arg0) {
    M2C_UNK DeleteSpriteObjectsOfClass(s32);
    M2C_UNK func_01ffa9f8(s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s16 *, 2) != 0) {
        func_01ffa9f8(M2C_FIELD(temp_r1, s32 *, 4));
    } else {
        DeleteSpriteObjectsOfClass(M2C_FIELD(temp_r1, s32 *, 4));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d020(void *arg0) {
    M2C_UNK func_01ffa9bc(s32);
    M2C_UNK func_01ffa9d0(s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s16 *, 2) != 0) {
        func_01ffa9d0(M2C_FIELD(temp_r1, s32 *, 4));
    } else {
        func_01ffa9bc(M2C_FIELD(temp_r1, s32 *, 4));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d05c(void *arg0) {
    M2C_UNK SetSpriteAnimation(void *, s16);
    SetSpriteAnimation(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    return 1;
}

s32 func_0209d074(void *arg0) {
    s32 (*func)(void *);
    func = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 (**)(void *), 4);
    if (func == NULL || func(arg0) != 0) {
        SetSpriteAnimation(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    } else {
        M2C_FIELD(arg0, void **, 8) += 8;
    }
    return 1;
}

s32 func_0209d0c0(void *arg0) {
    s32 (*func)(void *);
    func = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 (**)(void *), 4);
    if (func == NULL || func(arg0) == 0) {
        SetSpriteAnimation(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    } else {
        M2C_FIELD(arg0, void **, 8) += 8;
    }
    return 1;
}

s32 func_0209d10c(void *arg0) {
    M2C_UNK func_01ffa904(void *, s32);
    func_01ffa904(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    return 1;
}

void func_0209d124(void *arg0) {
    void Sprite_ResumeAnimation(void *);
    M2C_FIELD(arg0, s16 *, 0x2C)--;
    if (M2C_FIELD(arg0, s16 *, 0x2C) > 0) return;
    Sprite_ResumeAnimation(arg0);
}

s32 func_0209d148(void *arg0) {
    void func_0209d124(void *);
    s16 temp_r2;

    temp_r2 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    if (temp_r2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2C) = temp_r2;
        M2C_FIELD(arg0, void (**)(void *), 0x10) = &func_0209d124;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

void func_0209d178(void *arg0) {
    void Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    extern void *gTouchState;
    M2C_FIELD(arg0, s16 *, 0x2C)--;
    if (M2C_FIELD(arg0, s16 *, 0x2C) <= 0) {
        Sprite_ResumeAnimation(arg0);
        return;
    }
    if (*gKeyState == 0 && M2C_FIELD(gTouchState, u8 *, 0x14) == 0) return;
    Sprite_ResumeAnimation(arg0);
}

s32 func_0209d1d4(void *arg0) {
    void func_0209d178(void *);
    s16 temp_r2;

    temp_r2 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    if (temp_r2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2C) = temp_r2;
        M2C_FIELD(arg0, void (**)(void *), 0x10) = &func_0209d178;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209d204(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2E) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

/* Copy of SpriteState_DeleteSelfIfDuplicate for the other state table: when a live
 * sprite of the same class exists, delete this sprite and stop - for any sprite
 * when the state's parameter is 0, for one on the current engine otherwise - and
 * advance the state cursor when no duplicate is found. */
s32 SpriteState_DeleteSelfIfDuplicateAlt(void *sprite) {
    extern M2C_UNK g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = g3DSpriteSortOrder;
    for (; p < M2C_FIELD(&g3DSpriteOrderCursor, void ***, 0); p++) {
        void *other = *p;
        if (other != sprite && M2C_FIELD(other, s32 *, DS3D_SPRITE_ALIVE) == M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE)) {
            if (M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM) == 0 || M2C_FIELD(other, s32 *, DS3D_SPRITE_ENGINE) == gCur3DSpriteEngine) {
                DeleteSpriteObject(sprite);
                return 0;
            }
        }
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

/* 3D-sprite state handler: when another live sprite of the same class exists it
 * deletes this object and stops - for any sprite when the state's parameter is 0,
 * for one on the current engine otherwise - and advances the state cursor when no
 * duplicate is found. */
s32 SpriteState_DeleteSelfIfDuplicate(void *sprite) {
    extern M2C_UNK g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = g3DSpriteSortOrder;
    for (; p < M2C_FIELD(&g3DSpriteOrderCursor, void ***, 0); p++) {
        void *other = *p;
        if (other != sprite && M2C_FIELD(other, s32 *, DS3D_SPRITE_ALIVE) == M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE)) {
            if (M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM) == 0 || M2C_FIELD(other, s32 *, DS3D_SPRITE_ENGINE) == gCur3DSpriteEngine) {
                DeleteSpriteObject(sprite);
                return 0;
            }
        }
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

/* 3D-sprite state handler used when a sprite replaces another of its class: delete
 * the older sprite of the same class from the sort order - any sprite when the
 * state's parameter is 0, one on the current engine otherwise - and advance the
 * new sprite's state cursor. */
s32 SpriteState_DeleteOtherIfDuplicate(void *sprite) {
    extern M2C_UNK g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = g3DSpriteSortOrder;
    for (; p < M2C_FIELD(&g3DSpriteOrderCursor, void ***, 0); p++) {
        void *other = *p;
        if (other != sprite && M2C_FIELD(other, s32 *, DS3D_SPRITE_ALIVE) == M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE)) {
            if (M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM) == 0 || M2C_FIELD(other, s32 *, DS3D_SPRITE_ENGINE) == gCur3DSpriteEngine) {
                DeleteSpriteObject(other);
                break;
            }
        }
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

s32 func_0209d3c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 1;
}

/* Sprite state handler: start a split-screen transition (TRANSITION_MODE_SPLIT)
 * lasting the state's duration parameter.  The state data's low bits pick the
 * screen it runs on (main, sub, both, else the active one) and bit 3 starts it
 * on the sprite's children instead of the whole screen.  Advances the state. */
s32 SpriteState_StartSplitTransition(void *sprite) {
    void CreateScreenTransitions(s32, u16, s32, void *);
    void CreateScreenTransitionChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) CreateScreenTransitionChildren(TRANSITION_MODE_SPLIT, (u16)duration, target, sprite);
    else CreateScreenTransitions(TRANSITION_MODE_SPLIT, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

/* Sprite state handler: start a split-mode screen fade (TRANSITION_MODE_SPLIT)
 * lasting the state's duration parameter.  The state data's low bits pick the
 * screen it runs on (main, sub, both, else the active one) and bit 3 starts it
 * on the sprite's children instead of the whole screen.  Advances the state. */
s32 SpriteState_StartSplitFade(void *sprite) {
    void StartScreenFades(s32, u16, s32, void *);
    void StartScreenFadeChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) StartScreenFadeChildren(TRANSITION_MODE_SPLIT, (u16)duration, target, sprite);
    else StartScreenFades(TRANSITION_MODE_SPLIT, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

/* Sprite state handler: start a darkening screen transition (TRANSITION_MODE_DARK)
 * lasting the state's duration parameter.  The state data's low bits pick the
 * screen it runs on (main, sub, both, else the active one) and bit 3 starts it
 * on the sprite's children instead of the whole screen.  Advances the state. */
s32 SpriteState_CreateDarkTransition(void *sprite) {
    void CreateScreenTransitions(s32, u16, s32, void *);
    void CreateScreenTransitionChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) CreateScreenTransitionChildren(TRANSITION_MODE_DARK, (u16)duration, target, sprite);
    else CreateScreenTransitions(TRANSITION_MODE_DARK, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

s32 SpriteState_StartMainScreenFade(void *sprite) {
    void StartScreenFades(s32, u16, s32, void *);
    void StartScreenFadeChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);

    /* Start a main-screen fade (or fade the sprite's children) and advance this animation state. */
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) StartScreenFadeChildren(0, (u16)duration, target, sprite);
    else StartScreenFades(0, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

/* Sprite state handler: start a brightening screen transition
 * (TRANSITION_MODE_BRIGHT) lasting the state's duration parameter.  The state
 * data's low bits pick the screen it runs on (main, sub, both, else the active
 * one) and bit 3 starts it on the sprite's children instead of the whole screen.
 * Advances the state. */
s32 SpriteState_CreateBrightTransition(void *sprite) {
    void CreateScreenTransitions(s32, u16, s32, void *);
    void CreateScreenTransitionChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) CreateScreenTransitionChildren(TRANSITION_MODE_BRIGHT, (u16)duration, target, sprite);
    else CreateScreenTransitions(TRANSITION_MODE_BRIGHT, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

s32 SpriteState_StartSubScreenFade(void *sprite) {
    void StartScreenFades(s32, u16, s32, void *);
    void StartScreenFadeChildren(s32, u16, s32, void *);
    void *state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    s32 target = DS3D_TARGET_ACTIVE;
    s32 flags = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    s16 duration = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);

    /* Start a sub-screen fade (or fade the sprite's children) and advance this animation state. */
    if (flags & 1) target = DS3D_TARGET_MAIN;
    if (flags & 2) target = DS3D_TARGET_SUB;
    if (flags & 4) target = DS3D_TARGET_BOTH;
    if (flags & 8) StartScreenFadeChildren(1, (u16)duration, target, sprite);
    else StartScreenFades(1, (u16)duration, target, sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 1;
}

s32 func_0209d67c(void *arg0) {
    M2C_UNK PlayMusicTrack(s32);
    PlayMusicTrack(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6a4(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6cc(void *arg0) {
    M2C_UNK PlaySlotPendingSound(M2C_UNK, M2C_UNK, s32);
    PlaySlotPendingSound(0, -1, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6fc(void *arg0) {
    M2C_UNK func_02090034(M2C_UNK, s16);
    func_02090034(0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d728(void *arg0) {
    M2C_UNK func_0208f844(s16);
    func_0208f844(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d750(void *arg0) {
    void LoadUiGraphicsBank(u8);
    void FreeUiGraphicsBank(u8);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s32 *, 4) != 0) {
        LoadUiGraphicsBank(M2C_FIELD(temp_r1, s16 *, 2));
    } else {
        FreeUiGraphicsBank(M2C_FIELD(temp_r1, s16 *, 2));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d790(void *arg0) {
    s32 IsMessageTextIdValid(s32);
    M2C_UNK ShowMessageText(s32);
    M2C_UNK func_02092888(void *);
    M2C_UNK ResetDialogUI();
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4);
    if (IsMessageTextIdValid(temp_r4) != 0) {
        ResetDialogUI();
        ShowMessageText(temp_r4);
        func_02092888(arg0);
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209d7d8(void *arg0) {
    void LoadResource(u8);
    void func_020884f8(u8);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s32 *, 4) != 0) {
        LoadResource(M2C_FIELD(temp_r1, s16 *, 2));
    } else {
        func_020884f8(M2C_FIELD(temp_r1, s16 *, 2));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

void TextLayer_ShowMessage(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_0208999c(void *, u8, s32);
    void RenderTextLayerMessage(void *, u8, s32, s32);
    if (arg3 < 0) func_0208999c(arg0, (u8)arg1, arg2);
    else RenderTextLayerMessage(arg0, (u8)arg1, arg3 << 5, arg2);
    M2C_FIELD(arg0, s32 *, 0x58) |= 0x1000;
}

s32 func_0209d858(void *arg0) {
    void *func_0208b520(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (IsMessageTextIdValid(id) != 0) {
        obj = func_0208b520(arg0);
        TextLayer_ShowMessage(obj, 0, id, value);
        M2C_FIELD(obj, s32 *, 0x58) = M2C_FIELD(obj, s32 *, 0x58) | 0xC00;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

/* 3D-sprite state handler: create the sprite's text panel, draw the localized
 * message named by the state's data at the row in its parameter, and hide the
 * panel (no screen window). */
s32 SpriteState_CreateHiddenTextPanel(void *sprite) {
    void *func_0208b520(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = func_0208b520(sprite);
        TextLayer_ShowMessage(panel, 0, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) = (M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) | TEXT_LAYER_PANEL_HIDDEN) & ~TEXT_LAYER_PANEL_WINDOW_MASK;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

s32 func_0209d91c(void *arg0) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (IsMessageTextIdValid(id) != 0) {
        obj = CreateTextLayer(arg0);
        TextLayer_ShowMessage(obj, 2, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d97c(void *arg0) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (IsMessageTextIdValid(id) != 0) {
        obj = CreateTextLayer(arg0);
        TextLayer_ShowMessage(obj, 1, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d9dc(void *arg0) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (IsMessageTextIdValid(id) != 0) {
        obj = CreateTextLayer(arg0);
        TextLayer_ShowMessage(obj, 3, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209da3c(void *arg0) {
    M2C_UNK StartWindowClose();
    s32 FindTextLayer();
    if (FindTextLayer() != 0) {
        StartWindowClose();
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 0;
}

s32 func_0209da68(void *arg0) {
    if (func_0208b5c4() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 0;
}

void func_0209da8c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void func_0209da98(void *arg0) {
    s32 count;
    count = M2C_FIELD(arg0, s32 *, 0x5c) + 1;
    M2C_FIELD(arg0, s32 *, 0x5c) = count;
    if (count < M2C_FIELD(arg0, s32 *, 0x60)) return;
    DeleteSpriteObject(arg0);
}

void func_0209dabc(s32 arg0) {
    extern M2C_UNK data_0211e030;
    M2C_FIELD(CreateSpriteFromClass(&data_0211e030), s32 *, 0x60) = arg0;
}

void func_0209dad8(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_0209daec(void) {
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 saved;
    s32 i;
    s32 obj;
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) obj = g3DSpriteEngineMain;
        else obj = g3DSpriteEngineSub;
        gCur3DSpriteEngine = obj;
        M2C_FIELD(obj, s32 *, 8) = 0;
        M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x49) = 0;
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
}

