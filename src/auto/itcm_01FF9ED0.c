/* 47 functions from 0x01FF9ED0 to 0x01FFADA0 (itcm), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

#pragma opt_common_subs off
void Update3DSpriteVram(void) {
    s32 Get3DSpriteLayerSize(u8, s32);
    void MI_CpuCopy32(void *, s32, s32);
    void CopyToSpritePaletteVram(void *, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain, g3DSpriteEngineSub;
    extern u16 *g3DSpriteBankMain;

    s32 savedEngine = gCur3DSpriteEngine;
    s32 layerIndex = 0, screenIndex = 0, layerSize;
    u32 vramBase;
    void *engine;
    u8 isMainScreen, isMainEngine;

    /* Upload changed layers and palette data for both sprite engines, then clear their dirty flags. */
    do {
        engine = (void *)(screenIndex == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub);
        isMainScreen = (s32)engine == g3DSpriteEngineMain;
        gCur3DSpriteEngine = (s32)engine;
        if (isMainScreen == 1) vramBase = 0x6000000;
        else vramBase = 0x6200000;
        for (layerIndex = 0; layerIndex < 4; layerIndex++) {
            engine = (void *)gCur3DSpriteEngine;
            if ((M2C_FIELD(engine, u8 *, 0x46) & (1 << layerIndex)) && !(M2C_FIELD(engine, u8 *, 0x47) & (1 << layerIndex))) {
                isMainEngine = (s32)engine == g3DSpriteEngineMain;
                layerSize = Get3DSpriteLayerSize((u8)((u32)(*M2C_FIELD(engine, u16 **, 0) << 29) >> 29), (u8)layerIndex);
                {
                    s32 destination;
                    if (isMainEngine) destination = ((u32)(g3DSpriteBankMain[1] << 29) >> 29) << 16;
                    else destination = 0;
                    destination = vramBase + destination;
                    engine = (void *)gCur3DSpriteEngine;
                    {
                        u8 *layerControl = *(u8 **)engine;
                        void *layerTileBuffer = ((void **)((u8 *)engine + 0x20))[layerIndex];
                        destination += ((u32)(M2C_FIELD(layerControl + layerIndex * 2, u16 *, 6) << 19) >> 27) << 11;
                        MI_CpuCopy32(layerTileBuffer, destination, layerSize);
                    }
                }
            }
        }
        engine = (void *)gCur3DSpriteEngine;
        if ((M2C_FIELD(engine, u8 *, 0x46) & 16) && !(M2C_FIELD(engine, u8 *, 0x47) & 16)) {
            *M2C_FIELD(engine, u16 **, 0x30) = M2C_FIELD(engine, u16 *, 0x44);
            CopyToSpritePaletteVram(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x30), (u8)screenIndex, 0, 1024);
        }
        M2C_FIELD((void *)gCur3DSpriteEngine, u8 *, 0x47) = 0;
        engine = (void *)gCur3DSpriteEngine;
        M2C_FIELD(engine, u8 *, 0x46) = M2C_FIELD(engine, u8 *, 0x47);
        screenIndex++;
    } while (screenIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}
#pragma opt_common_subs reset
s32 GetSpriteLayerHead(s32 arg0) {
    extern s32 g3DSpriteLayerLists[];
    return g3DSpriteLayerLists[arg0];
}

u8 IsLayerParent(u32 arg0) {
    u8 var_r0;

    if (arg0 < 0xBU) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Runs one update of a live, childless 3D sprite object that has no update-callback
 * override: calls the handler of its animation state and keeps calling the next
 * state's handler while that asks to run again. */
void Update3DSpriteState(void *sprite) {
    extern s32 data_01ffa068[]; /* s32 handler per animation state */
    s16 *animState;

    if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE) == 0) {
        return;
    }
    if (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_CHILD_COUNT) != 0) {
        return;
    }
    if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) != 0) {
        return;
    }
    animState = M2C_FIELD(sprite, s16 **, DS3D_SPRITE_ANIM);
    if (((s32 (*)(void *)) data_01ffa068[*animState])(sprite) == 0) {
        return;
    }
    for (;;) {
        if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE) == 0) {
            return;
        }
        if (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_CHILD_COUNT) == 0 && M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) == 0) {
            animState = M2C_FIELD(sprite, s16 **, DS3D_SPRITE_ANIM);
            if (((s32 (*)(void *)) data_01ffa068[*animState])(sprite) != 0) {
                continue;
            }
        }
        return;
    }
}

/* Takes the next free 3D sprite object from the pool: the allocator cursor names
 * the first unused slot of the order array, and the object there is handed out
 * while the cursor advances.  A slot whose object is still being visited (its
 * VISITING flag set, e.g. one deleted during this frame's update walk) is skipped
 * by swapping it past a genuinely free slot, which is returned instead. */
void *AllocSpriteObject(void) {
    extern void **g3DSpriteOrderCursor;
    void **scan;
    void *candidate;
    void *sprite;

    sprite = *g3DSpriteOrderCursor;
    if (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_VISITING) {
        scan = g3DSpriteOrderCursor;
        do {
            scan += 1;
            candidate = *scan;
        } while (M2C_FIELD(candidate, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_VISITING);
        *g3DSpriteOrderCursor = candidate;
        *scan = sprite;
        sprite = *g3DSpriteOrderCursor;
    }
    g3DSpriteOrderCursor += 1;
    return sprite;
}

/* Frees `sprite` from the ordered sprite array: drops the array's last slot and,
 * when `sprite` is not the one dropped, moves that slot's object into `sprite`'s
 * place, leaving `sprite` just past the shortened array. */
void Free3DSpriteObject(void *sprite) {
    extern void **g3DSpriteOrderCursor;
    void **scan;
    void *last;

    g3DSpriteOrderCursor -= 1;
    scan = g3DSpriteOrderCursor;
    last = *scan;
    if (last == sprite) {
        return;
    }
    do {
        scan -= 1;
    } while (*scan != sprite);
    *scan = last;
    *g3DSpriteOrderCursor = sprite;
}

void InsertSpriteInLayer(void *arg0, u32 arg1) {
 extern s32 g3DSpriteLayerLists[];
 void **table=(void **)g3DSpriteLayerLists;
 void *prev=table[arg1];
 if(prev!=NULL) {
 M2C_FIELD(prev,void **,0x20)=arg0;
 M2C_FIELD(arg0,void **,0x24)=table[arg1];
 }
 M2C_FIELD(arg0,u32 *,0x18)=arg1;
 table[arg1]=arg0;
}

void InsertSpriteInParent(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x1C);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0x20) = arg0;
        M2C_FIELD(arg0, void **, 0x24) = (void *) M2C_FIELD(arg1, void **, 0x1C);
    }
    M2C_FIELD(arg1, void **, 0x1C) = arg0;
    M2C_FIELD(arg0, void **, 0x18) = arg1;
}

/* Unlink `sprite` from the sibling list it is in - one of the twelve per-layer
 * lists when its parent field is a layer index, otherwise its parent's child
 * list - and clear its sibling links. */
void RemoveSpriteFromOwner(void *sprite) {
    extern s32 g3DSpriteLayerLists[];
    void *sibling = M2C_FIELD(sprite, void **, DS3D_SPRITE_PREV);
    u32 owner;
    if (sibling) M2C_FIELD(sibling, void **, DS3D_SPRITE_NEXT) = M2C_FIELD(sprite, void **, DS3D_SPRITE_NEXT);
    sibling = M2C_FIELD(sprite, void **, DS3D_SPRITE_NEXT);
    if (sibling) M2C_FIELD(sibling, void **, DS3D_SPRITE_PREV) = M2C_FIELD(sprite, void **, DS3D_SPRITE_PREV);
    owner = M2C_FIELD(sprite, u32 *, DS3D_SPRITE_PARENT);
    if (owner > 12) {
        if (M2C_FIELD(owner, void **, DS3D_SPRITE_CHILD) == sprite) M2C_FIELD(owner, void **, DS3D_SPRITE_CHILD) = M2C_FIELD(sprite, void **, DS3D_SPRITE_NEXT);
    } else {
        if (M2C_FIELD(g3DSpriteLayerLists, void **, owner * 4) == sprite) g3DSpriteLayerLists[owner] = M2C_FIELD(sprite, s32 *, DS3D_SPRITE_NEXT);
    }
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_PREV) = 0;
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_NEXT) = 0;
}

/* Creates a sprite object of `spriteClass` on engine `engine`, owned by `owner` (a
 * layer index below 12, otherwise a parent sprite to attach it to): takes a free
 * object from the pool, stores the class in its class and animation-state fields,
 * clears its callbacks and links, inserts it, runs its first state update with
 * `engine` current and clears the initialising flag.  Returns the new object. */
s32 CreateSpriteObjectInLayer(s32 spriteClass,s32 owner,s32 engine) {
 void InsertSpriteInLayer(void *,u32);
 void InsertSpriteInParent(void *,void *);
 extern s32 gCur3DSpriteEngine;
 void *sprite=AllocSpriteObject();
 s32 savedEngine;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_ALIVE)=spriteClass;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_ANIM)=spriteClass;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_DELETE_CB)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_UPDATE_CB)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_DRAW_CB)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_PARENT)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_CHILD)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_PREV)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_NEXT)=0;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_ENGINE)=engine;
 M2C_FIELD(sprite,u16 *,DS3D_SPRITE_LAYER)=0;
 M2C_FIELD(sprite,u16 *,DS3D_SPRITE_Z)=0xFF00;
 M2C_FIELD(sprite,u8 *,DS3D_SPRITE_CHILD_COUNT)=0;
 M2C_FIELD(sprite,u8 *,DS3D_SPRITE_FLAGS)=DS3D_SPRITE_FLAG_INIT|DS3D_SPRITE_FLAG_NEW;
 if((u32)owner<12)InsertSpriteInLayer(sprite,owner);else InsertSpriteInParent(sprite,(void *)owner);
 savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=engine;
 Update3DSpriteState(sprite);
 gCur3DSpriteEngine=savedEngine;
 M2C_FIELD(sprite,u8 *,DS3D_SPRITE_FLAGS)&=~DS3D_SPRITE_FLAG_INIT;
 return (s32)sprite;
}

void CreateSpriteFromClass(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CreateSpriteObjectInLayer(M2C_UNK, M2C_UNK, s32);
    extern s32 gCur3DSpriteEngine;
    CreateSpriteObjectInLayer(arg0, arg1, gCur3DSpriteEngine);
}

s32 CreateChildSpriteObject(s32 a,s32 b,s32 c) {
 void *p=(void *)CreateSpriteObjectInLayer(a,b,c);
 void *parent;
 if(M2C_FIELD(p,s32 *,4)==0)return 0;
 M2C_FIELD(p,u8 *,0x30)|=4;
 parent=M2C_FIELD(p,void **,0x18);
 M2C_FIELD(parent,u8 *,0x31)++;
 return (s32)p;
}

void CreateSpriteObject(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CreateChildSpriteObject(M2C_UNK, M2C_UNK, s32);
    extern s32 gCur3DSpriteEngine;
    CreateChildSpriteObject(arg0, arg1, gCur3DSpriteEngine);
}

void CreateSpriteForOwner(s32 a,s32 b) {
 if(b==0)b=7;
 if(b<12)CreateSpriteFromClass(a,b);else CreateSpriteObject(a,b);
}

void Mark3DSpriteTreeOwned(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 if(q)Mark3DSpriteTreeOwned(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)Mark3DSpriteTreeOwned(q);
 M2C_FIELD(p,u8 *,0x30)|=2;
}

/* Marks a 3D sprite object and everything below it (later siblings and children)
 * as dead and gives each object back to the free pool. */
void Release3DSpriteTree(void *sprite) {
    void *node;
    node = M2C_FIELD(sprite, void **, DS3D_SPRITE_NEXT);
    if (node) Release3DSpriteTree(node);
    node = M2C_FIELD(sprite, void **, DS3D_SPRITE_CHILD);
    if (node) Release3DSpriteTree(node);
    if (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_DEAD) return;
    M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) |= DS3D_SPRITE_FLAG_DEAD;
    Free3DSpriteObject((s32)sprite);
}

/* Destroys a 3D sprite object and everything below it: the later siblings and the
 * children are destroyed first, then the object's delete callback and its class's
 * destructor run, its class, state cursor and callbacks are cleared, and it is
 * dropped from its parent's child count when it was created as a child object. */
void Delete3DSpriteTree(void *obj) {
    void *node;
    void (*deleteCb)(void *);
    node = M2C_FIELD(obj, void **, DS3D_SPRITE_NEXT);
    if (node) Delete3DSpriteTree(node);
    node = M2C_FIELD(obj, void **, DS3D_SPRITE_CHILD);
    if (node) Delete3DSpriteTree(node);
    deleteCb = M2C_FIELD(obj, void (**)(void *), DS3D_SPRITE_DELETE_CB);
    if (deleteCb) deleteCb(obj);
    node = M2C_FIELD(obj, void **, DS3D_SPRITE_CLASS);
    if (node) M2C_FIELD(node, void (**)(void *), DS3D_CLASS_DESTROY)(obj);
    M2C_FIELD(obj, s32 *, DS3D_SPRITE_CLASS) = 0;
    M2C_FIELD(obj, s32 *, DS3D_SPRITE_ALIVE) = 0;
    M2C_FIELD(obj, s32 *, DS3D_SPRITE_ANIM) = 0;
    M2C_FIELD(obj, s32 *, DS3D_SPRITE_UPDATE_CB) = 0;
    M2C_FIELD(obj, s32 *, DS3D_SPRITE_DRAW_CB) = 0;
    if (M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_HAS_PARENT) {
        node = M2C_FIELD(obj, void **, DS3D_SPRITE_PARENT);
        M2C_FIELD(node, u8 *, DS3D_SPRITE_CHILD_COUNT)--;
    }
}

#pragma push
#pragma optimization_level 2
/* Remove a live standalone sprite from its owner and destroy/release its entire sprite tree. */
void DeleteSpriteObject(void *sprite) {
    do {
        if (!sprite) break;
        switch (M2C_FIELD(sprite, u32 *, DS3D_SPRITE_ALIVE)) {
        case 0:
            return;
        default:
            break;
        }
        if (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_TREE_OWNED) break;
        RemoveSpriteFromOwner(sprite);
        Mark3DSpriteTreeOwned(sprite);
        Delete3DSpriteTree(sprite);
        Release3DSpriteTree(sprite);
    } while (0);
}
#pragma pop
/* One frame of a 3D sprite object tree: walk the sibling chain, then, unless the
 * object has children, run its state update (or the UPDATE_CB override), point
 * gCur3DSpriteEngine at its engine while doing so, run its draw callback and
 * finally recurse into its children. */
void Update3DSpriteObject(void *obj) {
    extern u8 gSpriteUpdateBusy, gFramePending;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;
    void *node;

    if (!obj) return;
    M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) |= DS3D_SPRITE_FLAG_VISITING;
    node = M2C_FIELD(obj, void **, DS3D_SPRITE_NEXT);
    if (node) Update3DSpriteObject(node);
    M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) &= ~DS3D_SPRITE_FLAG_VISITING;
    if (M2C_FIELD(obj, u8 *, DS3D_SPRITE_CHILD_COUNT) == 0 && !(M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_INIT)) {
        if (M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_NEW) {
            if (gSpriteUpdateBusy && gFramePending) goto skip;
            M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) &= ~DS3D_SPRITE_FLAG_NEW;
        }
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = M2C_FIELD(obj, s32 *, DS3D_SPRITE_ENGINE);
        do {
            M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) &= ~DS3D_SPRITE_FLAG_REPEAT;
            if (!M2C_FIELD(obj, s32 *, DS3D_SPRITE_UPDATE_CB)) Update3DSpriteState(obj);
            if (M2C_FIELD(obj, s32 *, DS3D_SPRITE_UPDATE_CB)) ((void (*)(void *))M2C_FIELD(obj, s32 *, DS3D_SPRITE_UPDATE_CB))(obj);
        } while (M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_REPEAT);
        M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) &= ~DS3D_SPRITE_FLAG_REPEAT;
        gCur3DSpriteEngine = savedEngine;
        if (M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_DEAD) return;
    }
skip:
    if (M2C_FIELD(obj, s32 *, DS3D_SPRITE_DRAW_CB)) {
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = M2C_FIELD(obj, s32 *, DS3D_SPRITE_ENGINE);
        ((void (*)(void *))M2C_FIELD(obj, s32 *, DS3D_SPRITE_DRAW_CB))(obj);
        gCur3DSpriteEngine = savedEngine;
        if (M2C_FIELD(obj, u8 *, DS3D_SPRITE_FLAGS) & DS3D_SPRITE_FLAG_DEAD) return;
    }
    node = M2C_FIELD(obj, void **, DS3D_SPRITE_CHILD);
    if (node) Update3DSpriteObject(node);
}
#pragma scheduling reset
void Sprite_ResumeAnimation(void *arg0) {
    s16 *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        return;
    }
    temp_r2 = M2C_FIELD(arg0, s16 **, 8);
    if (temp_r2 == NULL) {
        return;
    }
    if (*temp_r2 == 2) {
        M2C_FIELD(arg0, s16 **, 8) = (s16 *) ((s32) temp_r2 + 8);
    }
}

/* Resume a paused 3D sprite's animation: clear the update-callback override that
 * paused it, or step past the animation's wait state (state 2) when that is where
 * it stopped, then ask the update to run again this frame. */
void Sprite_ResumeAnimationRepeat(void *sprite) {
    register s16 *animState;

    if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) != 0) {
        M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) = 0;
    } else {
        animState = M2C_FIELD(sprite, s16 **, DS3D_SPRITE_ANIM);
        if ((animState != NULL) && (*animState == 2)) {
            M2C_FIELD(sprite, s16 **, DS3D_SPRITE_ANIM) = (s16 *) ((s32)animState + DS3D_STATE_SIZE);
        }
    }
    M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) = (u8) (M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) | DS3D_SPRITE_FLAG_REPEAT);
}

/* Return the first live 3D sprite object of class `spriteClass` in the depth sort
 * order, or NULL when there is none. */
void *FindObjectByClass(s32 spriteClass) {
    extern void **g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    void **cursor = g3DSpriteSortOrder;
    void *sprite;
    for (; cursor < g3DSpriteOrderCursor; cursor++) {
        sprite = *cursor;
        if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE) == spriteClass) return sprite;
    }
    return 0;
}

/* Return the first live sprite of `spriteClass` that belongs to the current 3D
 * sprite engine, or NULL when there is none. */
void *Find3DSpriteByClassOnCurrentEngine(s32 spriteClass) {
    extern void **g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    extern s32 gCur3DSpriteEngine;
    void **p = g3DSpriteSortOrder;
    void *q;
    for (; p < g3DSpriteOrderCursor; p++) {
        q = *p;
        if (M2C_FIELD(q, s32 *, DS3D_SPRITE_ENGINE) == gCur3DSpriteEngine && M2C_FIELD(q, s32 *, DS3D_SPRITE_ALIVE) == spriteClass) return q;
    }
    return 0;
}

/* Return the first 3D sprite object in the depth sort order whose DS3D_SPRITE_Z
 * is `z`, or NULL; DS3D_SPRITE_Z_NONE marks a sprite with no depth and is never
 * found. */
void *FindObjectByZ(u16 z) {
 extern void **g3DSpriteOrderCursor;
 extern void *g3DSpriteSortOrder[];
 void **cursor;void *sprite;
 if(z==DS3D_SPRITE_Z_NONE)return 0;
 for(cursor=g3DSpriteSortOrder;cursor<g3DSpriteOrderCursor;cursor++){
 sprite=*cursor;if(M2C_FIELD(sprite,u16 *,DS3D_SPRITE_Z)==z)return sprite;
 }
 return 0;
}

/* Find the sprite object of class `spriteClass` that sits at depth `z` in the
 * order array; an object with no depth set (DS3D_SPRITE_Z_NONE) is never
 * matched, and 0 means nothing was found. */
void *Find3DSpriteByClassAndZ(s32 spriteClass, u16 z) {
    extern void **g3DSpriteOrderCursor;
    extern void *g3DSpriteSortOrder[];
    void **cursor;
    void *sprite;

    if (z == DS3D_SPRITE_Z_NONE) return 0;
    for (cursor = g3DSpriteSortOrder; cursor < g3DSpriteOrderCursor; cursor++) {
        sprite = *cursor;
        if (M2C_FIELD(sprite, s32 *, DS3D_SPRITE_ALIVE) == spriteClass && M2C_FIELD(sprite, u16 *, DS3D_SPRITE_Z) == z) return sprite;
    }
    return 0;
}

void SetSpriteZ(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x2E) = arg1;
}

/* Jump a 3D sprite's animation to the state labelled `label`: scan the object's
 * animation script for the label entry (DS3D_STATE_LABEL) whose parameter names
 * it, point the state cursor there and clear the update-callback override so the
 * default state machine runs on from the label. */
void GotoSpriteAnimationLabel(void *sprite, s32 label) {
    DS3DStateEntry *state = M2C_FIELD(sprite, DS3DStateEntry **, DS3D_SPRITE_ALIVE);
    s16 id = state->id;

    if (id == 0) return;
    do {
        if (id == DS3D_STATE_LABEL && state->param == label) {
            M2C_FIELD(sprite, DS3DStateEntry **, DS3D_SPRITE_ANIM) = state;
            M2C_FIELD(sprite, s32 *, DS3D_SPRITE_UPDATE_CB) = 0;
            return;
        }
        state += 1;
        id = state->id;
    } while (id != 0);
}

void func_01ffa904(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}

void func_01ffa918(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
}

void func_01ffa920(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
}

/* Run `callback` on every live 3D sprite object in the pool that is of class
   `spriteClass`, whichever engine the object belongs to. */
void ApplyToSpriteClass(M2C_UNK spriteClass, M2C_UNK *callback) {
    extern u8 g3DSpriteObjectPool[];
    u8 *object = g3DSpriteObjectPool;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(object, s32 *, DS3D_SPRITE_ALIVE) == spriteClass) {
            ((void (*)(void *)) callback)(object);
        }
        i++;
        object += DS3D_SPRITE_SIZE;
    } while (i < DS3D_SPRITE_COUNT);
}

/* Run `callback` on every 3D sprite object in the pool that is of class
   `spriteClass` and assigned to the current 3D sprite engine. */
void ApplyToSpriteClassOnCurrentEngine(M2C_UNK spriteClass, M2C_UNK *callback) {
    extern u8 g3DSpriteObjectPool[];
    extern s32 gCur3DSpriteEngine;
    u8 *object = g3DSpriteObjectPool;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(object, s32 *, DS3D_SPRITE_ALIVE) == spriteClass && M2C_FIELD(object, s32 *, DS3D_SPRITE_ENGINE) == gCur3DSpriteEngine) {
            ((void (*)(void *)) callback)(object);
        }
        i++;
        object += DS3D_SPRITE_SIZE;
    } while (i < DS3D_SPRITE_COUNT);
}

void ResumeAnimationOfSpriteClass(M2C_UNK arg0) {
    void Sprite_ResumeAnimation(void *);
    ApplyToSpriteClass(arg0, (M2C_UNK *) &Sprite_ResumeAnimation);
}

void ResumeAnimationOfSpriteClassOnCurrentEngine(M2C_UNK arg0) {
    void Sprite_ResumeAnimation(void *);
    ApplyToSpriteClassOnCurrentEngine(arg0, (M2C_UNK *)&Sprite_ResumeAnimation);
}

void DeleteSpriteObjectsOfClass(M2C_UNK arg0) {
    void DeleteSpriteObject(void *);
    ApplyToSpriteClass(arg0, (M2C_UNK *) &DeleteSpriteObject);
}

void DeleteSpriteObjectsOfClassOnCurrentEngine(M2C_UNK arg0) {
    void DeleteSpriteObject(void *);
    ApplyToSpriteClassOnCurrentEngine(arg0, (M2C_UNK *)&DeleteSpriteObject);
}

/* Delete every live 3D sprite object whose depth (DS3D_SPRITE_Z) is `z`;
 * DS3D_SPRITE_Z_NONE (a sprite with no depth) deletes nothing. */
void DeleteSpriteObjectsWithZ(s32 z) {
    extern u8 g3DSpriteObjectPool[];
    u8 *object = g3DSpriteObjectPool;
    s32 i;

    if (z == DS3D_SPRITE_Z_NONE) {
        return;
    }
    i = 0;
    do {
        if (M2C_FIELD(object, s32 *, DS3D_SPRITE_ALIVE) != 0 && M2C_FIELD(object, u16 *, DS3D_SPRITE_Z) == z) {
            DeleteSpriteObject(object);
        }
        i++;
        object += DS3D_SPRITE_SIZE;
    } while (i < DS3D_SPRITE_COUNT);
}

void IncrementSpriteChildCount(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x31) = (u8) (M2C_FIELD(arg0, u8 *, 0x31) + 1);
}

void DecrementSpriteChildCount(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x31) = (u8) (M2C_FIELD(arg0, u8 *, 0x31) - 1);
}

u32 GetSpriteParent(void *arg0) {
    u32 var_r0;

    var_r0 = M2C_FIELD(arg0, u32 *, 0x18);
    if (var_r0 <= 0xCU) {
        var_r0 = 0;
    }
    return var_r0;
}

/* Stop counting `sprite` as a child object of its parent: when it is attached to
 * a parent sprite (rather than a layer) and was created as a child object, clear
 * its HAS_PARENT flag and drop its parent's child count. */
void DetachSpriteFromParent(void *sprite) {
    u8 flags;
    void *parent;

    if (IsLayerParent(M2C_FIELD(sprite, void **, DS3D_SPRITE_PARENT)) != 0) {
        return;
    }
    flags = M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS);
    if (!(flags & DS3D_SPRITE_FLAG_HAS_PARENT)) {
        return;
    }
    M2C_FIELD(sprite, u8 *, DS3D_SPRITE_FLAGS) = (u8) (flags & ~DS3D_SPRITE_FLAG_HAS_PARENT);
    parent = M2C_FIELD(sprite, void **, DS3D_SPRITE_PARENT);
    M2C_FIELD(parent, u8 *, DS3D_SPRITE_CHILD_COUNT) = (u8) (M2C_FIELD(parent, u8 *, DS3D_SPRITE_CHILD_COUNT) - 1);
}

/* Adds one 3D sprite to the active engine's list: claims the next of its 128
 * 20-byte slots, fills it in and links it into the list kept sorted by
 * priority (highest first).  Silently drops the sprite when the list is full. */
void AddSprite(s32 x, s32 y, s32 tile, s32 template_, s32 priority) {
    extern s32 gCur3DSpriteEngine;
    void *sprite, *prev, *next;
    u8 *list;
    u32 index;

    if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49) >= 128) return;
    list = M2C_FIELD(gCur3DSpriteEngine, u8 *volatile *, 4);
    index = M2C_FIELD(gCur3DSpriteEngine, volatile u8 *, 0x49);
    sprite = list + index * 20;

    M2C_FIELD(sprite, s16 *, 8) = 0;
    M2C_FIELD(sprite, s16 *, 10) = 0;
    M2C_FIELD(sprite, s16 *, 12) = x;
    M2C_FIELD(sprite, s16 *, 14) = y;
    M2C_FIELD(sprite, s16 *, 16) = tile;
    M2C_FIELD(sprite, s32 *, 4) = template_;
    M2C_FIELD(sprite, s8 *, 19) = priority;
    M2C_FIELD(sprite, u8 *, 18) &= ~15;
    M2C_FIELD(sprite, u8 *, 18) &= ~240;

    if (M2C_FIELD(gCur3DSpriteEngine, void **, 8) == 0) {
        M2C_FIELD(gCur3DSpriteEngine, void **, 8) = sprite;
        M2C_FIELD(sprite, void **, 0) = 0;
    } else {
        prev = M2C_FIELD(gCur3DSpriteEngine, void *volatile *, 8);
        if (M2C_FIELD(prev, s8 *, 19) > priority) {
            M2C_FIELD(sprite, void **, 0) = prev;
            M2C_FIELD(gCur3DSpriteEngine, void **, 8) = sprite;
        } else {
            for (;;) {
                next = M2C_FIELD(prev, void **, 0);
                if (!next || M2C_FIELD(next, s8 *, 19) > priority) {
                    M2C_FIELD(sprite, void **, 0) = next;
                    M2C_FIELD(prev, void **, 0) = sprite;
                    break;
                }
                prev = next;
            }
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49)++;
}

/* Allocates a paired-sprite entry in gCur3DSpriteEngine's array, fills in fields, and inserts it into the priority-ordered list. Returns silently if the 128-entry array is full. */
void AddSpriteEntry(s32 a, s32 b, s32 c, s32 d, u16 e, s32 f, s32 priority) {
    extern s32 gCur3DSpriteEngine;
    void *p, *q, *next;
    u8 *base;
    u32 index;

    if (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49) >= 128) return;

    base = M2C_FIELD(gCur3DSpriteEngine, u8 *volatile *, 4);
    index = M2C_FIELD(gCur3DSpriteEngine, volatile u8 *, 0x49);
    p = base + index * 20;

    M2C_FIELD(p, s16 *, 8) = a;
    M2C_FIELD(p, s16 *, 10) = b;
    M2C_FIELD(p, s16 *, 12) = c;
    M2C_FIELD(p, s16 *, 14) = d;
    M2C_FIELD(p, s16 *, 16) = e;
    M2C_FIELD(p, s32 *, 4) = f;
    M2C_FIELD(p, s8 *, 19) = priority;

    M2C_FIELD(p, u8 *, 18) &= ~15;
    M2C_FIELD(p, u8 *, 18) = (M2C_FIELD(p, u8 *, 18) & ~240) | 16;

    if (M2C_FIELD(gCur3DSpriteEngine, void **, 8) == 0) {
        M2C_FIELD(gCur3DSpriteEngine, void **, 8) = p;
        M2C_FIELD(p, void **, 0) = 0;
    } else {
        q = M2C_FIELD(gCur3DSpriteEngine, void *volatile *, 8);
        if (M2C_FIELD(q, s8 *, 19) > priority) {
            M2C_FIELD(p, void **, 0) = q;
            M2C_FIELD(gCur3DSpriteEngine, void **, 8) = p;
        } else {
            for (;;) {
                next = M2C_FIELD(q, void **, 0);
                if (!next || M2C_FIELD(next, s8 *, 19) > priority) {
                    M2C_FIELD(p, void **, 0) = next;
                    M2C_FIELD(q, void **, 0) = p;
                    break;
                }
                q = next;
            }
        }
    }

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49)++;
}

/* Add a 3D sprite to the main screen's engine: make the main engine current,
 * add the sprite there and restore the previously current engine. */
void AddSpriteToMainEngine(s32 x, s32 y, s32 tile, s32 template_, s32 priority) {
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    AddSprite(x, y, tile, template_, priority);
    gCur3DSpriteEngine = savedEngine;
}

/* Add a 3D sprite to the sub (lower) screen engine's list, restoring the
 * previously active engine afterwards. */
void AddSpriteToSubEngine(s32 x, s32 y, s32 tile, s32 template_, s32 priority) {
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    AddSprite(x, y, tile, template_, priority);
    gCur3DSpriteEngine = savedEngine;
}

/* Add a sprite to the current 3D sprite engine's list, then mark the slot it
 * took as an affine (3D) sprite. */
void AddAffineSprite(s32 x, s32 y, s32 tile, s32 template_, s32 priority) {
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *engine = (void *)gCur3DSpriteEngine;
    u8 *entry = (u8 *)M2C_FIELD(engine, volatile s32 *, DS3D_ENGINE_SPRITE_ARRAY) +
                M2C_FIELD(engine, volatile u8 *, DS3D_ENGINE_SPRITE_COUNT) * DS3D_ENTRY_SIZE;

    AddSprite(x, y, tile, template_, priority);
    entry[DS3D_ENTRY_FLAGS] = (entry[DS3D_ENTRY_FLAGS] & ~15) | DS3D_ENTRY_FLAG_AFFINE;
}

/* Add a sprite to the current 3D sprite engine's list, taking its position as the
 * low and high halves of x and y, then mark the slot as an affine (3D) sprite. */
void AddSpriteEntry3D(s32 x, s32 y, s32 xHigh, s32 yHigh, u16 tile, s32 template_, s32 priority) {
    void AddSpriteEntry(s32, s32, s32, s32, u16, s32, s32);
    extern s32 gCur3DSpriteEngine;
    void *engine = (void *)gCur3DSpriteEngine;
    u8 *entry = (u8 *)M2C_FIELD(engine, volatile s32 *, 4) +
                M2C_FIELD(engine, volatile u8 *, DS3D_ENGINE_SPRITE_COUNT) * DS3D_ENTRY_SIZE;

    AddSpriteEntry(x, y, xHigh, yHigh, tile, template_, priority);
    entry[DS3D_ENTRY_FLAGS] = (entry[DS3D_ENTRY_FLAGS] & ~15) | DS3D_ENTRY_FLAG_AFFINE;
}

