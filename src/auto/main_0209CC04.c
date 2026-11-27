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

/* Create a queued 3D sprite task of class g3DSpriteTaskClass and record
 * `callback` as the function the engine runs at DS3D_TASK_CALLBACK. */
void CreateQueuedSpriteTask(void *callback) {
    void *CreateSpriteFromClass(M2C_UNK *);
    extern M2C_UNK g3DSpriteTaskClass;
    M2C_FIELD(CreateSpriteFromClass(&g3DSpriteTaskClass), void **, DS3D_TASK_CALLBACK) = callback;
}

void func_0209ccd4(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 0x34)(arg0);
}

/* Create a 3D sprite of the frame-callback task class and register `callback`
 * as the function it runs on every frame. */
void CreateFrameCallbackTask(s32 callback) {
    void *CreateSpriteFromClass(M2C_UNK *);
    extern M2C_UNK gFrameCallbackTaskClass;
    M2C_FIELD(CreateSpriteFromClass(&gFrameCallbackTaskClass), s32 *, DS3D_TASK_CALLBACK) = callback;
}

/* Destroy every frame-callback task sprite whose registered callback is
 * `callback`: walk the 3D sprite pool and delete each matching object. */
void DeleteFrameCallbackTask(s32 callback) {
    M2C_UNK DeleteSpriteObject();
    extern M2C_UNK gFrameCallbackTaskClass;
    extern M2C_UNK g3DSpriteObjectPool;
    u8 *object;
    s32 i;

    object = (u8 *)&g3DSpriteObjectPool;
    i = 0;
    do {
        if (M2C_FIELD(object, void **, DS3D_SPRITE_ALIVE) == &gFrameCallbackTaskClass && M2C_FIELD(object, s32 *, DS3D_TASK_CALLBACK) == callback) DeleteSpriteObject(object);
        i++;
        object += DS3D_SPRITE_SIZE;
    } while (i < DS3D_SPRITE_COUNT);
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

/* 3D-sprite state handler: skip this state entry and continue with the next one. */
s32 SpriteState_SkipEntry(void *sprite) {
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) = (s32) (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: install the state entry's data as the sprite's delete
 * callback, then move on to the next entry. */
s32 SpriteState_SetDeleteCallback(void *sprite) {
    M2C_UNK Set3DSpriteDeleteCallback(void *, s32);
    Set3DSpriteDeleteCallback(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: install the state entry's data as the sprite's draw
 * callback, then move on to the next entry. */
s32 SpriteState_SetDrawCallback(void *sprite) {
    M2C_UNK Set3DSpriteDrawCallback(void *, s32);
    Set3DSpriteDrawCallback(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: call the state entry's callback with the sprite and move
 * on to the next entry (the callback's result is ignored). */
s32 SpriteState_CallCallback(void *sprite) {
    void *entry;
    M2C_UNK (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    callback = M2C_FIELD(entry, M2C_UNK (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    callback(sprite);
    return 1;
}

/* 3D-sprite state handler: call the state entry's callback with the entry's
 * parameter and move on to the next entry at once (the callback's result is
 * ignored). */
s32 SpriteState_CallCallbackWithParam(void *sprite) {
    void *entry;
    s16 param;
    M2C_UNK (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    param = M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM);
    callback = M2C_FIELD(entry, M2C_UNK (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    callback(sprite, param);
    return 1;
}

/* 3D-sprite state handler: call the state entry's callback and stay on this state
 * while it returns nonzero; once it returns zero, continue with the next entry. */
s32 SpriteState_WaitForFalseCallback(void *sprite) {
    void *entry;
    s32 (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    callback = M2C_FIELD(entry, s32 (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    if (callback(sprite) == 0) {
        return 1;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) - DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: call the state entry's callback with the entry's
 * parameter and stay on this state while it returns nonzero; once it returns 0,
 * continue with the next entry. */
s32 SpriteState_WaitForCallbackWithParam(void *sprite) {
    void *entry;
    s16 param;
    s32 (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    param = M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM);
    callback = M2C_FIELD(entry, s32 (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    if (callback(sprite, param) == 0) {
        return 1;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) - DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: call the state entry's callback and move on to the next
 * entry once it returns nonzero; while it returns 0, stay on this state. */
s32 SpriteState_WaitForTrueCallback(void *sprite) {
    void *entry;
    s32 (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    callback = M2C_FIELD(entry, s32 (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    if (callback(sprite) != 0) {
        return 1;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) - DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: call the state entry's callback with the entry's
 * parameter and move on to the next entry once it returns nonzero; while it
 * returns 0, stay on this state. */
s32 SpriteState_WaitForTrueCallbackWithParam(void *sprite) {
    void *entry;
    s16 param;
    s32 (*callback)();

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    param = M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM);
    callback = M2C_FIELD(entry, s32 (**)(), DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (entry + DS3D_STATE_SIZE);
    if (callback(sprite, param) != 0) {
        return 1;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) - DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: install the state entry's data as the sprite's update
 * callback, then stop the state run for this frame so the new callback starts on
 * the next one. */
s32 SpriteState_SetUpdateCallback(void *sprite) {
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) = (s32) M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: stay on this state while any live sprite of the class
 * the entry's data names remains; once none does, move on to the next entry. */
s32 SpriteState_WaitForObjectClassRemoved(void *sprite) {
    s32 FindObjectByClass(s32);

    if (FindObjectByClass(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA)) != 0) {
        return 0;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: create a child sprite of the class the state's data
 * names, parented to the sprite running the state machine, then move on to the
 * next state entry. */
s32 SpriteState_CreateChildOfClass(void *sprite) {
    CreateSpriteFromClass(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA), sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: create a child sprite of the class the state entry
 * names on the current engine, parented to this sprite, then stop the state run
 * for this frame. */
s32 SpriteState_CreateChildSprite(void *sprite) {
    M2C_UNK CreateSpriteObject(s32, void *);
    CreateSpriteObject(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA), sprite);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: create a sprite of the class the state's data names,
 * owned by the owner the state's parameter names (a layer index, or a parent
 * object), then move on to the next state entry. */
s32 SpriteState_CreateSpriteOfClass(void *sprite) {
    void *entry;

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    CreateSpriteFromClass(M2C_FIELD(entry, s32 *, DS3D_STATE_DATA), M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: delete every live sprite of the class the entry names
 * (only on the current 3D sprite engine when the entry's parameter is set), then
 * move on to the next entry. */
s32 SpriteState_DeleteObjectsOfClass(void *sprite) {
    M2C_UNK DeleteSpriteObjectsOfClass(s32);
    void *entry;

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    if (M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM) != 0) {
        DeleteSpriteObjectsOfClassOnCurrentEngine(M2C_FIELD(entry, s32 *, DS3D_STATE_DATA));
    } else {
        DeleteSpriteObjectsOfClass(M2C_FIELD(entry, s32 *, DS3D_STATE_DATA));
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: resume the animation of every object of the state's
 * class (on the current engine only when its parameter is nonzero), then move on
 * to the next state entry. */
s32 SpriteState_ResumeObjectsOfClass(void *sprite) {
    void ResumeAnimationOfSpriteClass(M2C_UNK);
    void ResumeAnimationOfSpriteClassOnCurrentEngine(M2C_UNK);
    void *entry;

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    if (M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM) != 0) {
        ResumeAnimationOfSpriteClassOnCurrentEngine(M2C_FIELD(entry, s32 *, DS3D_STATE_DATA));
    } else {
        ResumeAnimationOfSpriteClass(M2C_FIELD(entry, s32 *, DS3D_STATE_DATA));
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: jump the sprite's animation unconditionally to the
 * label named by the state entry's parameter, then keep running states this
 * frame. */
s32 SpriteState_GotoLabel(void *sprite) {
    M2C_UNK GotoSpriteAnimationLabel(void *, s16);
    GotoSpriteAnimationLabel(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM));
    return 1;
}

/* 3D-sprite state handler: jump the sprite's animation to the state whose id the
 * parameter names when the state's predicate callback (its data) is missing or
 * returns nonzero; otherwise fall through to the next state. */
s32 SpriteState_GotoIfPredicate(void *sprite) {
    s32 (*predicate)(void *);
    predicate = M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 (**)(void *), DS3D_STATE_DATA);
    if (predicate == NULL || predicate(sprite) != 0) {
        GotoSpriteAnimationLabel(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM));
    } else {
        M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    }
    return 1;
}

/* 3D-sprite state handler: jump the sprite's animation to the state whose id the
 * parameter names when the state's predicate callback (its data) is missing or
 * returns zero; otherwise fall through to the next state. */
s32 SpriteState_GotoIfNotPredicate(void *sprite) {
    s32 (*predicate)(void *);
    predicate = M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 (**)(void *), DS3D_STATE_DATA);
    if (predicate == NULL || predicate(sprite) == 0) {
        GotoSpriteAnimationLabel(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM));
    } else {
        M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    }
    return 1;
}

/* 3D-sprite state handler: install the state entry's data as the sprite's class,
 * restarting its animation script at the class record, then run on in the same
 * frame. */
s32 SpriteState_SetClass(void *sprite) {
    void Set3DSpriteClass(void *, s32);

    Set3DSpriteClass(sprite, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    return 1;
}

/* 3D-sprite update callback: count the wait state's timer down and resume the
 * sprite's animation script once it reaches zero. */
void SpriteState_WaitForTimeout(void *sprite) {
    void Sprite_ResumeAnimation(void *);
    M2C_FIELD(sprite, s16 *, DS3D_SPRITE_WAIT_TIMER)--;
    if (M2C_FIELD(sprite, s16 *, DS3D_SPRITE_WAIT_TIMER) > 0) return;
    Sprite_ResumeAnimation(sprite);
}

/* 3D-sprite state handler: store the delay the state entry names in the sprite
 * and switch its update callback to the countdown (SpriteState_WaitForTimeout);
 * then continue with the next entry. */
s32 SpriteState_StartWaitForTimeout(void *sprite) {
    s16 delay;

    delay = M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM);
    if (delay != 0) {
        M2C_FIELD(sprite, s16 *, 0x2C) = delay;
        M2C_FIELD(sprite, void (**)(void *), DS3D_SPRITE_UPDATE_CB) = &SpriteState_WaitForTimeout;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: count down the state's delay at +0x2C, then resume the
 * sprite's animation script -- when the delay reaches zero, or earlier once any key
 * is held or a touch starts. */
void SpriteState_WaitForInputOrTimeout(void *sprite) {
    void Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    extern void *gTouchState;
    M2C_FIELD(sprite, s16 *, 0x2C)--;
    if (M2C_FIELD(sprite, s16 *, 0x2C) <= 0) {
        Sprite_ResumeAnimation(sprite);
        return;
    }
    if (*gKeyState == 0 && M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) == 0) return;
    Sprite_ResumeAnimation(sprite);
}

/* 3D-sprite state handler: when the state gives a timeout, set the sprite's wait
 * timer to it and install the update that resumes the animation when it runs out
 * or sooner once a key is held or a touch starts; then move to the next state. */
s32 SpriteState_StartWaitForInputOrTimeout(void *sprite) {
    void SpriteState_WaitForInputOrTimeout(void *);
    s16 timeout;

    timeout = M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM);
    if (timeout != 0) {
        M2C_FIELD(sprite, s16 *, DS3D_SPRITE_WAIT_TIMER) = timeout;
        M2C_FIELD(sprite, void (**)(void *), DS3D_SPRITE_UPDATE_CB) = &SpriteState_WaitForInputOrTimeout;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: store the state entry's parameter as the sprite's Z
 * depth and move on to the next entry. */
s32 SpriteState_SetZ(void *sprite) {
    M2C_FIELD(sprite, s16 *, DS3D_SPRITE_Z) = (s16) M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM);
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
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

/* 3D-sprite state handler: skip this state entry and continue with the next one
 * (a second, byte-identical copy used for another opcode slot). */
s32 SpriteState_SkipEntry2(void *sprite) {
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) = (s32) (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
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

/* 3D-sprite state handler: play the music track named by the state entry's data,
 * then move on to the next entry. */
s32 SpriteState_PlayMusicTrack(void *sprite) {
    M2C_UNK PlayMusicTrack(s32);
    PlayMusicTrack(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: play the sound effect named by the state entry's data
 * word, then move on to the next entry. */
s32 SpriteState_PlaySoundEffect(void *sprite) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: play the sound effect named by the state entry's data
 * word in sound slot 0 on the default channel, then continue with the next entry
 * in the same frame. */
s32 SpriteState_PlaySlotSound(void *sprite) {
    M2C_UNK PlaySlotPendingSound(M2C_UNK, M2C_UNK, s32);
    PlaySlotPendingSound(0, -1, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: stop the sound effect named by the state entry's
 * parameter in sound slot 0, then continue with the next entry in the same
 * frame. */
s32 SpriteState_StopSlotSound(void *sprite) {
    M2C_UNK StopSlotSound(M2C_UNK, s16);
    StopSlotSound(0, M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: fade the music out over the number of frames held in
 * the state entry's parameter, then continue with the next entry in the same
 * frame. */
s32 SpriteState_FadeOutMusicOverFrames(void *sprite) {
    M2C_UNK FadeOutMusicOverFrames(s16);
    FadeOutMusicOverFrames(M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s16 *, DS3D_STATE_PARAM));
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: load the UI graphics bank named by the state entry's
 * parameter when its data word is nonzero, free that bank otherwise, then
 * continue with the next entry. */
s32 SpriteState_LoadOrUnloadUiGraphicsBank(void *sprite) {
    void LoadUiGraphicsBank(u8);
    void FreeUiGraphicsBank(u8);
    void *entry;

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    if (M2C_FIELD(entry, s32 *, DS3D_STATE_DATA) != 0) {
        LoadUiGraphicsBank(M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM));
    } else {
        FreeUiGraphicsBank(M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM));
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* 3D-sprite state handler: when the state's data names a valid message, reset the
 * dialog UI, show the message and spawn its text sprite under this sprite, then
 * advance to the next state entry. */
s32 SpriteState_ShowMessage(void *sprite) {
    s32 IsMessageTextIdValid(s32);
    M2C_UNK ShowMessageText(s32);
    M2C_UNK SpawnMessageTextSprite(void *);
    M2C_UNK ResetDialogUI();
    s32 textId;

    textId = M2C_FIELD(M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM), s32 *, DS3D_STATE_DATA);
    if (IsMessageTextIdValid(textId) != 0) {
        ResetDialogUI();
        ShowMessageText(textId);
        SpawnMessageTextSprite(sprite);
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: load the resource the state entry's parameter names
 * when its data word is nonzero, unload it otherwise, then continue. */
s32 SpriteState_LoadOrUnloadResource(void *sprite) {
    void LoadResource(u8);
    void UnloadResource(u8);
    void *entry;

    entry = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    if (M2C_FIELD(entry, s32 *, DS3D_STATE_DATA) != 0) {
        LoadResource(M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM));
    } else {
        UnloadResource(M2C_FIELD(entry, s16 *, DS3D_STATE_PARAM));
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 1;
}

/* Lay the localized message `textId` onto a text layer in text mode `mode`, at the
 * palette offset of line `row` (a negative row uses the default offset), then mark
 * the panel's text as drawn. */
void TextLayer_ShowMessage(void *layer, s32 mode, s32 textId, s32 row) {
    void RenderTextLayerMessageDefault(void *, u8, s32);
    void RenderTextLayerMessage(void *, u8, s32, s32);
    if (row < 0) RenderTextLayerMessageDefault(layer, (u8)mode, textId);
    else RenderTextLayerMessage(layer, (u8)mode, row << 5, textId);
    M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) |= 0x1000;
}

/* 3D-sprite state handler: create the sprite's text panel and draw the localized
 * message named by the state's data at the row in its parameter, marking the
 * panel hidden behind a configured screen window. */
s32 SpriteState_ShowTextPanel(void *sprite) {
    void *CreateTextLayerChild(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = CreateTextLayerChild(sprite);
        TextLayer_ShowMessage(panel, 0, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) = M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) | (TEXT_LAYER_PANEL_WINDOW_MASK | TEXT_LAYER_PANEL_HIDDEN);
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: create the sprite's text panel, draw the localized
 * message named by the state's data at the row in its parameter, and hide the
 * panel (no screen window). */
s32 SpriteState_CreateHiddenTextPanel(void *sprite) {
    void *CreateTextLayerChild(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = CreateTextLayerChild(sprite);
        TextLayer_ShowMessage(panel, 0, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) = (M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) | TEXT_LAYER_PANEL_HIDDEN) & ~TEXT_LAYER_PANEL_WINDOW_MASK;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: create the sprite's text panel and draw the localized
 * message named by the state's data at the row in its parameter, in text mode 2
 * with the panel's screen window enabled. */
s32 SpriteState_ShowTextPanelMode2(void *sprite) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = CreateTextLayer(sprite);
        TextLayer_ShowMessage(panel, 2, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) |= TEXT_LAYER_PANEL_WINDOW_MASK;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: create the sprite's text panel and draw the localized
 * message named by the state's data at the row in its parameter, in text mode 1
 * with the panel's screen window enabled. */
s32 SpriteState_ShowTextPanelMode1(void *sprite) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = CreateTextLayer(sprite);
        TextLayer_ShowMessage(panel, 1, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) |= TEXT_LAYER_PANEL_WINDOW_MASK;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: create the sprite's text panel and draw the localized
 * message named by the state's data at the row in its parameter, in text mode 3
 * with the panel's screen window enabled. */
s32 SpriteState_ShowTextPanelMode3(void *sprite) {
    void *CreateTextLayer(void *);
    void TextLayer_ShowMessage(void *, s32, s32, s32);
    s32 textId;
    s16 row;
    void *state;
    void *panel;
    state = M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM);
    textId = M2C_FIELD(state, s32 *, DS3D_STATE_DATA);
    row = M2C_FIELD(state, s16 *, DS3D_STATE_PARAM);
    if (IsMessageTextIdValid(textId) != 0) {
        panel = CreateTextLayer(sprite);
        TextLayer_ShowMessage(panel, 3, textId, row);
        M2C_FIELD(panel, s32 *, TEXT_LAYER_PANEL_STATE) |= TEXT_LAYER_PANEL_WINDOW_MASK;
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) += DS3D_STATE_SIZE;
    return 0;
}

/* 3D-sprite state handler: close the text layer's window when one is up, then
 * continue with the next state entry. */
s32 SpriteState_CloseTextLayerWindow(void *sprite) {
    void StartWindowClose(void *);
    s32 FindTextLayer(void);
    void *window;

    window = (void *) FindTextLayer();
    if (window != 0) {
        StartWindowClose(window);
    }
    M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) = (void *) (M2C_FIELD(sprite, void **, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

/* 3D-sprite state handler: stay on this state entry while the text layer is
 * animating, then move on to the next entry. */
s32 SpriteState_WaitForTextLayerAnimation(void *sprite) {
    if (IsTextLayerAnimating() != 0) {
        return 0;
    }
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) = (s32) (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ANIM) + DS3D_STATE_SIZE);
    return 0;
}

void ResetTimedSpriteElapsed(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

/* Frame update of a timed sprite: count one more frame alive and, once the count
 * reaches the sprite's lifetime, delete it. */
void UpdateTimedSprite(void *sprite) {
    s32 elapsed;

    elapsed = M2C_FIELD(sprite, s32 *, DS3D_SPRITE_LIFETIME_ELAPSED) + 1;
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_LIFETIME_ELAPSED) = elapsed;
    if (elapsed < M2C_FIELD(sprite, s32 *, DS3D_SPRITE_LIFETIME_FRAMES)) return;
    DeleteSpriteObject(sprite);
}

/* Create a sprite of the timed-sprite class that deletes itself once it has
 * lived for `frames` frames. */
void CreateTimedSprite(s32 frames) {
    extern M2C_UNK gTimedSpriteClass;
    M2C_FIELD(CreateSpriteFromClass(&gTimedSpriteClass), s32 *, DS3D_SPRITE_LIFETIME_FRAMES) = frames;
}

void func_0209dad8(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

/* Empties the 3D sprite list of both engines: each engine's list head and its
   sprite count are cleared, dropping every sprite it held. */
void Reset3DSpriteListsOnBothEngines(void) {
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 activeEngine;
    s32 engineIndex;
    s32 engine;
    activeEngine = gCur3DSpriteEngine;
    engineIndex = 0;
    do {
        if (engineIndex == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        M2C_FIELD(engine, s32 *, DS3D_ENGINE_SPRITE_LIST) = 0;
        M2C_FIELD(gCur3DSpriteEngine, s8 *, DS3D_ENGINE_SPRITE_COUNT) = 0;
        engineIndex++;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = activeEngine;
}

