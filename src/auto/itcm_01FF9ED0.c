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

u8 func_01ffa14c(u32 arg0) {
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

void *AllocSpriteObject(void) {
    extern void **g3DSpriteOrderCursor;
    void **var_r3;
    void *temp_r2;
    void *var_r0;

    var_r0 = *g3DSpriteOrderCursor;
    if (M2C_FIELD(var_r0, u8 *, 0x30) & 0x20) {
        var_r3 = g3DSpriteOrderCursor;
        do {
            var_r3 += 1;
            temp_r2 = *var_r3;
        } while (M2C_FIELD(temp_r2, u8 *, 0x30) & 0x20);
        *g3DSpriteOrderCursor = temp_r2;
        *var_r3 = var_r0;
        var_r0 = *g3DSpriteOrderCursor;
    }
    g3DSpriteOrderCursor += 1;
    return var_r0;
}

void func_01ffa244(s32 arg0) {
    extern void **g3DSpriteOrderCursor;
    void **var_r2;
    s32 temp_r3;

    g3DSpriteOrderCursor -= 1;
    var_r2 = g3DSpriteOrderCursor;
    temp_r3 = (s32) *var_r2;
    if (temp_r3 == arg0) {
        return;
    }
    do {
        var_r2 -= 1;
    } while ((s32) *var_r2 != arg0);
    *var_r2 = (void *) temp_r3;
    *g3DSpriteOrderCursor = (void *) arg0;
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

s32 func_01ffa3f4(s32 a,s32 b,s32 c) {
 void *p=(void *)CreateSpriteObjectInLayer(a,b,c);
 void *parent;
 if(M2C_FIELD(p,s32 *,4)==0)return 0;
 M2C_FIELD(p,u8 *,0x30)|=4;
 parent=M2C_FIELD(p,void **,0x18);
 M2C_FIELD(parent,u8 *,0x31)++;
 return (s32)p;
}

void CreateSpriteObject(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_01ffa3f4(M2C_UNK, M2C_UNK, s32);
    extern s32 gCur3DSpriteEngine;
    func_01ffa3f4(arg0, arg1, gCur3DSpriteEngine);
}

void CreateSpriteForOwner(s32 a,s32 b) {
 if(b==0)b=7;
 if(b<12)CreateSpriteFromClass(a,b);else CreateSpriteObject(a,b);
}

void func_01ffa468(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 if(q)func_01ffa468(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)func_01ffa468(q);
 M2C_FIELD(p,u8 *,0x30)|=2;
}

void func_01ffa4a0(void *p) {
 void *q=M2C_FIELD(p,void **,0x24);
 if(q)func_01ffa4a0(q);
 q=M2C_FIELD(p,void **,0x1C);
 if(q)func_01ffa4a0(q);
 if(M2C_FIELD(p,u8 *,0x30)&1)return;
 M2C_FIELD(p,u8 *,0x30)|=1;
 func_01ffa244((s32)p);
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
void DeleteSpriteObject(void *arg0) { do { if(!arg0) break; switch(M2C_FIELD(arg0,u32 *,4)){case 0: return;default:break;} if(M2C_FIELD(arg0,u8 *,0x30)&2) break; RemoveSpriteFromOwner(arg0);func_01ffa468(arg0);Delete3DSpriteTree(arg0);func_01ffa4a0(arg0); } while(0); }
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

void Sprite_ResumeAnimationRepeat(void *arg0) {
    register s16 *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    } else {
        temp_r2 = M2C_FIELD(arg0, s16 **, 8);
        if ((temp_r2 != NULL) && (*temp_r2 == 2)) {
            M2C_FIELD(arg0, s16 **, 8) = (s16 *) ((s32)temp_r2 + 8);
        }
    }
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (M2C_FIELD(arg0, u8 *, 0x30) | 0x40);
}

void *FindObjectByClass(s32 arg0) {
 extern void **g3DSpriteOrderCursor;
 extern void *g3DSpriteSortOrder[];
 void **p=g3DSpriteSortOrder;
 void *q;
 for(;p<g3DSpriteOrderCursor;p++) {
 q=*p;
 if(M2C_FIELD(q,s32 *,4)==arg0)return q;
 }
 return 0;
}

void *Find3DSpriteById(s32 arg0) {
 extern void **g3DSpriteOrderCursor;
 extern void *g3DSpriteSortOrder[];
 extern s32 gCur3DSpriteEngine;
 void **p=g3DSpriteSortOrder;
 void *q;
 for(;p<g3DSpriteOrderCursor;p++) {
 q=*p;
 if(M2C_FIELD(q,s32 *,0x28)==gCur3DSpriteEngine && M2C_FIELD(q,s32 *,4)==arg0)return q;
 }
 return 0;
}

void *FindObjectByZ(s32 a) {
 extern void **g3DSpriteOrderCursor;
 extern void *g3DSpriteSortOrder[];
 void **q;void *p;
 if(a==0xFF00)return 0;
 for(q=g3DSpriteSortOrder;q<g3DSpriteOrderCursor;q++){
 p=*q;if(M2C_FIELD(p,u16 *,0x2E)==a)return p;
 }
 return 0;
}

void *func_01ffa860(s32 a,s32 b) {
 extern void **g3DSpriteOrderCursor;
 extern void *g3DSpriteSortOrder[];
 void **q;void *p;
 if(b==0xFF00)return 0;
 for(q=g3DSpriteSortOrder;q<g3DSpriteOrderCursor;q++){
 p=*q;if(M2C_FIELD(p,s32 *,4)==a && M2C_FIELD(p,u16 *,0x2E)==b)return p;
 }
 return 0;
}

void SetSpriteZ(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x2E) = arg1;
}

void SetSpriteAnimation(void *p,s32 value) {
 s16 *q=M2C_FIELD(p,s16 **,4);
 s16 v=*q;
 if(v==0)return;
 do {
 if(v==20 && q[1]==value) {
 M2C_FIELD(p,s16 **,8)=q;M2C_FIELD(p,s32 *,0x10)=0;return;
 }
 q+=4;v=*q;
 }while(v!=0);
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

void func_01ffa928(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 g3DSpriteObjectPool[];
    u8 *p = g3DSpriteObjectPool;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) == arg0) {
            ((void (*)(void *)) arg1)(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void func_01ffa968(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 g3DSpriteObjectPool[];
    extern s32 gCur3DSpriteEngine;
    u8 *p = g3DSpriteObjectPool;
    s32 i;

    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) == arg0 && M2C_FIELD(p, s32 *, 0x28) == gCur3DSpriteEngine) {
            ((void (*)(void *)) arg1)(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void func_01ffa9bc(M2C_UNK arg0) {
    void Sprite_ResumeAnimation(void *);
    func_01ffa928(arg0, (M2C_UNK *) &Sprite_ResumeAnimation);
}

void func_01ffa9d0(M2C_UNK arg0) {
    void Sprite_ResumeAnimation(void *);
    func_01ffa968(arg0, (M2C_UNK *)&Sprite_ResumeAnimation);
}

void DeleteSpriteObjectsOfClass(M2C_UNK arg0) {
    void DeleteSpriteObject(void *);
    func_01ffa928(arg0, (M2C_UNK *) &DeleteSpriteObject);
}

void func_01ffa9f8(M2C_UNK arg0) {
    void DeleteSpriteObject(void *);
    func_01ffa968(arg0, (M2C_UNK *)&DeleteSpriteObject);
}

void func_01ffaa0c(s32 arg0) {
    extern u8 g3DSpriteObjectPool[];
    u8 *p = g3DSpriteObjectPool;
    s32 i;

    if (arg0 == 0xFF00) {
        return;
    }
    i = 0;
    do {
        if (M2C_FIELD(p, s32 *, 4) != 0 && M2C_FIELD(p, u16 *, 0x2E) == arg0) {
            DeleteSpriteObject(p);
        }
        i++;
        p += 0x74;
    } while (i < 0x80);
}

void IncrementSpriteChildCount(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x31) = (u8) (M2C_FIELD(arg0, u8 *, 0x31) + 1);
}

void func_01ffaa6c(void *arg0) {
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

void func_01ffaa8c(void *arg0) {
    u8 temp_r0;
    void *temp_r1;

    if (func_01ffa14c(M2C_FIELD(arg0, void **, 0x18)) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x30);
    if (!(temp_r0 & 4)) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x30) = (u8) (temp_r0 & ~4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(temp_r1, u8 *, 0x31) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x31) - 1);
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
void func_01ffabac(s32 a, s32 b, s32 c, s32 d, u16 e, s32 f, s32 priority) {
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

void func_01ffac9c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    s32 temp_r5;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    AddSprite(arg0, arg1, arg2, arg3, arg4);
    gCur3DSpriteEngine = temp_r5;
}

void func_01ffacd4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void AddSprite(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    s32 temp_r5;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    AddSprite(arg0, arg1, arg2, arg3, arg4);
    gCur3DSpriteEngine = temp_r5;
}

void func_01ffad0c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
void AddSprite(s32,s32,s32,s32,s32);
extern s32 gCur3DSpriteEngine;
void *p=(void *)gCur3DSpriteEngine;
u8 *q=(u8 *)M2C_FIELD(p,volatile s32 *,4)+M2C_FIELD(p,volatile u8 *,0x49)*0x14;
AddSprite(arg0,arg1,arg2,arg3,arg4);
q[0x12]=(q[0x12]&~15)|1;
}

void func_01ffad4c(s32 arg0,s32 arg1,s32 arg2,s32 arg3,u16 arg4,s32 arg5,s32 arg6) {
void func_01ffabac(s32,s32,s32,s32,u16,s32,s32);
extern s32 gCur3DSpriteEngine;
void *p=(void *)gCur3DSpriteEngine;
u8 *q=(u8 *)M2C_FIELD(p,volatile s32 *,4)+M2C_FIELD(p,volatile u8 *,0x49)*0x14;
func_01ffabac(arg0,arg1,arg2,arg3,arg4,arg5,arg6);
q[0x12]=(q[0x12]&~15)|1;
}

