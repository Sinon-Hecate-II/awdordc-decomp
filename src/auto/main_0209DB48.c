/* 37 functions from 0x0209DB48 to 0x0209EAF4 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
typedef struct { s32 values[16]; } ScenePanelMotionTable;
extern const ScenePanelMotionTable data_020f3b04;


typedef struct {
    void *next;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u8 lo : 4;
    u8 hi : 4;
} Unk0209Node;

typedef struct {
    u16 unk0, unk2, unk4, unk6;
} Unk0209Rect;

void func_0209db48(void){
void AppendSpriteDescToOam(u16,u16,u16,s32);void func_01ff8930(s16,s16,u16,u16,u16,s32);
void func_01ff8a8c(u16,u16,u16,s32);void func_01ff8c0c(s16,s16,u16,u16,u16,s32);
void Reset3DSpriteListsOnBothEngines(void);
extern void *g3DSpriteEngineSub,*g3DSpriteEngineMain,*data_027e01d8;
void *cur,*saved; s32 i;
saved=data_027e01d8;i=0;
do{void *head; s32 raw;
if(i==0)head=g3DSpriteEngineMain;else head=g3DSpriteEngineSub;
data_027e01d8=head;cur=M2C_FIELD(head,void **,8);
while(cur){
raw=M2C_FIELD(cur,u8 *,0x12);
if(((u32)(raw<<24)>>28)!=0){
if(((u32)((s32)raw<<28)>>28)==0)
func_01ff8930(M2C_FIELD(cur,s16 *,8),M2C_FIELD(cur,s16 *,10),M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
else func_01ff8c0c(M2C_FIELD(cur,s16 *,8),M2C_FIELD(cur,s16 *,10),M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
}else{
if((raw<<28>>28)==0)AppendSpriteDescToOam(M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
else func_01ff8a8c(M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
}
cur=M2C_FIELD(cur,void **,0);
}
i++;
}while(i<2);
data_027e01d8=saved;Reset3DSpriteListsOnBothEngines();
}

/* Panel input action for a message widget, from the keys pressed this frame:
 * A confirms, B cancels, Start skips; holding A with Down confirms as well. */
s32 GetMessageWidgetKeyAction(void) {
    extern u16 *gKeyState;
    u16 keys;

    keys = gKeyState[0]; /* KeyState.pressed */
    if (keys & KEY_A) return PANEL_INPUT_CONFIRM;
    if (keys & KEY_B) return PANEL_INPUT_CANCEL;
    if (keys & KEY_START) return PANEL_INPUT_SKIP;
    keys = gKeyState[3]; /* KeyState.held */
    if ((keys & KEY_A) && (keys & KEY_DOWN)) return PANEL_INPUT_CONFIRM;
    return 0;
}

/* Map the current key input to this text object's action mask: Start skips, B
 * cancels and A confirms (also while A and Down are held together). */
s32 GetTextObjectKeyAction(void) {
    extern u16 *gKeyState;
    u16 keys;
    keys = gKeyState[0];
    if (keys & KEY_START) return PANEL_INPUT_SKIP;
    if (keys & KEY_B) return PANEL_INPUT_CANCEL;
    if (keys & KEY_A) return PANEL_INPUT_CONFIRM;
    keys = gKeyState[3];
    if ((keys & KEY_A) && (keys & KEY_DOWN)) return PANEL_INPUT_CONFIRM;
    return 0;
}

/* Map the keys pressed this frame to this scene-panel widget's action mask:
 * Left and Right move the selection, A confirms and B cancels. */
s32 GetPanelKeyAction(void) {
    extern u16 *gKeyState;
    u16 keys;

    keys = *gKeyState;
    if (keys & KEY_LEFT) {
        return PANEL_INPUT_LEFT;
    }
    if (keys & KEY_RIGHT) {
        return PANEL_INPUT_RIGHT;
    }
    if (keys & KEY_A) {
        return PANEL_INPUT_CONFIRM;
    }
    if (keys & KEY_B) {
        return PANEL_INPUT_CANCEL;
    }
    return 0;
}

/* Fill `rect` with the whole touch screen: the top-left corner at (0, 0) and the
 * screen's full width and height. */
void InitFullScreenTouchRect(void *rect) {
    WidgetRect *r = (WidgetRect *) rect;
    r->x = 0;
    r->y = 0;
    r->w = SCREEN_WIDTH;
    r->h = SCREEN_HEIGHT;
}

/* Return PANEL_INPUT_CONFIRM while a touch is held that began inside the whole
 * screen (the full-screen touch rectangle), else no action. */
s32 GetScreenTouchConfirm(void) {
    extern void *gTouchState;
    s16 bounds[4];
    u16 touchX;
    u16 touchY;
    touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);
    InitFullScreenTouchRect(bounds);
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) == 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) == 0) return 0;
    if (bounds[0] < touchX && touchX < bounds[0] + bounds[2] && bounds[1] < touchY && touchY < bounds[1] + bounds[3]) return PANEL_INPUT_CONFIRM;
    return 0;
}

/* Text-object twin of GetScreenTouchConfirm: return PANEL_INPUT_CONFIRM while a
 * touch is held that began inside the whole screen, else no action. */
s32 GetTextObjectTouchConfirm(void) {
    extern void *gTouchState;
    s16 bounds[4];
    u16 touchX;
    u16 touchY;
    touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);
    InitFullScreenTouchRect(bounds);
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) == 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) == 0) return 0;
    if (bounds[0] < touchX && touchX < bounds[0] + bounds[2] && bounds[1] < touchY && touchY < bounds[1] + bounds[3]) return PANEL_INPUT_CONFIRM;
    return 0;
}

/* Store one widget's touch rectangle into the shared table: slot 1 is the left
 * half and slot 2 the right half of the two-state widgets. */
void SetWidgetRect(s32 rectIndex, WidgetRect rect) {
    extern WidgetRect gWidgetRects[];
    WidgetRect *slot;

    slot = &gWidgetRects[rectIndex];
    *slot = rect;
}

/* Return which of the widget's two touch halves the point (x, y) lies in: 1 for
 * the left half, 2 for the right half, 0 for neither. */
s32 GetTouchRegion(s32 x, s32 y) {
    s32 RectContainsPoint(s32, s32, void *);
    extern Unk0209Rect gWidgetLeftRect;
    extern Unk0209Rect gWidgetRightRect;

    if (RectContainsPoint(x, y, &gWidgetLeftRect) != 0) {
        return 1;
    }
    if (RectContainsPoint(x, y, &gWidgetRightRect) != 0) {
        return 2;
    }
    return 0;
}

/* Returns the action code for the current stylus interaction, based on which of two touch regions the point lies in. */
s32 GetPanelTouchAction(void) {
    extern void *gTouchState;
    extern s32 data_0215bde0;
    s32 region;

    region = GetTouchRegion(M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2));
    if (M2C_FIELD(gTouchState, u8 *, 0x12) != 0) {
        if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
            data_0215bde0 = region;
        } else {
            if (M2C_FIELD(gTouchState, u8 *, 0x10) == 0x14) {
                data_0215bde0 = 0;
            }
            if (data_0215bde0 != region) {
                data_0215bde0 = 0;
            }
        }
        switch (region) {                          /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            return 4;
        case 2:                                     /* switch 1 */
            return 8;
        default:                                    /* switch 1 */
            return 0;
        }
    } else if ((M2C_FIELD(gTouchState, u8 *, 0x16) != 0) && (data_0215bde0 == region)) {
        switch (data_0215bde0) {                    /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            return 0x10;
        case 2:                                     /* switch 2 */
            return 0x10;
        default:                                    /* switch 2 */
            return 0;
        }
    } else {
        return 0;
    }
}

/* Task-sprite per-frame handler: once the sprite's own OS thread has finished,
 * delete the sprite (its destructor frees the thread object and stack). */
void UpdateTaskSprite(void *sprite) {
    M2C_UNK DeleteSpriteObject(void *);
    s32 TaskIsFinished(s32);
    if (TaskIsFinished(M2C_FIELD(sprite, s32 *, TASK_SPRITE_THREAD)) == 0) {
        return;
    }
    DeleteSpriteObject(sprite);
}

/* Task sprite's class destructor: free the thread object and stack block the
 * sprite owns, then run its cleanup callback, if it has one. */
void DestroyTaskSprite(void *sprite) {
    M2C_UNK HeapFreeBlock(s32);
    void (*cleanup)(void);

    HeapFreeBlock(M2C_FIELD(sprite, s32 *, TASK_SPRITE_THREAD));
    HeapFreeBlock(M2C_FIELD(sprite, s32 *, TASK_SPRITE_STACK));
    cleanup = M2C_FIELD(sprite, void (**)(void), TASK_SPRITE_CLEANUP);
    if (cleanup == NULL) {
        return;
    }
    cleanup();
}

void TaskSpriteEntry(void *arg0) {
    M2C_FIELD(arg0, void (**)(void), 0)();
}

/* Start an OS thread owned by a new task sprite: allocate the thread object and
 * a `stackSize`-byte stack, record `cleanup` to be run with the sprite, start
 * `entry` on the thread at `priority` and wake it.  `z` is the sprite's depth,
 * also recorded as the value handed to the entry function. */
void CreateTaskSprite(s32 entry, s32 z, u32 stackSize, s32 priority, s32 cleanup) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    s32 HeapAllocBlock(u32);
    void SetSpriteZ(void *, s32);
    void TaskCreate(s32, void (*)(void *), void *, s32, u32, s32);
    void TaskWake(s32);
    extern M2C_UNK gTaskSpriteClass;
    void *sprite;

    sprite = CreateSpriteFromClass(&gTaskSpriteClass, 3);
    M2C_FIELD(sprite, s32 *, TASK_SPRITE_THREAD) = HeapAllocBlock(TASK_SPRITE_THREAD_SIZE);
    M2C_FIELD(sprite, s32 *, TASK_SPRITE_STACK) = HeapAllocBlock(stackSize);
    M2C_FIELD(sprite, s32 *, TASK_SPRITE_CLEANUP) = cleanup;
    SetSpriteZ(sprite, z);
    M2C_FIELD(sprite, s32 *, TASK_SPRITE_ENTRY) = entry;
    M2C_FIELD(sprite, s32 *, TASK_SPRITE_ARG) = z;
    TaskCreate(M2C_FIELD(sprite, s32 *, TASK_SPRITE_THREAD), TaskSpriteEntry, sprite + TASK_SPRITE_ENTRY, M2C_FIELD(sprite, s32 *, TASK_SPRITE_STACK) + (stackSize & ~3), stackSize, priority);
    TaskWake(M2C_FIELD(sprite, s32 *, TASK_SPRITE_THREAD));
}

/* True while the task sprite created by CreateTaskSprite (class gTaskSpriteClass)
 * is alive at sprite depth `z`; a sprite with no depth set is never found. */
u8 IsTaskSpriteRunning(u16 z) {
    extern M2C_UNK gTaskSpriteClass;
    u8 running;

    if (Find3DSpriteByClassAndZ(&gTaskSpriteClass, z) != 0) {
        running = 1;
    } else {
        running = 0;
    }
    return running;
}

/* Load the dialogue window's graphics into `dest`: pick window_talk.cg or
 * window_body.cg from the window directory according to the panel layout. */
void LoadWindowGraphics(s32 layout, M2C_UNK dest) {
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, M2C_UNK);
    extern M2C_UNK sWindowGfxDirectory;
    extern M2C_UNK sWindowTalkCgFile;
    extern M2C_UNK sWindowBodyCgFile;
    SetFileDirectory(&sWindowGfxDirectory);
    switch (layout) {
    case SCENE_PANEL_LAYOUT_TALK:
        LoadDecompressedFileTo(&sWindowTalkCgFile, dest);
        return;
    case SCENE_PANEL_LAYOUT_BODY:
        LoadDecompressedFileTo(&sWindowBodyCgFile, dest);
        return;
    }
}

/* Load the scene window's 16-colour palette from window.cl into the 3D sprite
 * palette slot `paletteSlot`. */
void LoadWindowPalette(s32 paletteSlot) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK sWindowPaletteDirectory;
    extern M2C_UNK sWindowPaletteFile;
    SetFileDirectory(&sWindowPaletteDirectory);
    LoadFileToSpriteBuffer(&sWindowPaletteFile, paletteSlot << DS3D_PALETTE_SHIFT, DS3D_PALETTE_BYTES);
}

/* Configure a freshly allocated scene-panel sprite: its window layout (talk or
 * body), the texture row its tiles are drawn from (arg2 in 32-unit steps) and its
 * OBJ palette row, then hide it so the change takes effect. */
void ConfigureScenePanelSprite(void *sprite, s8 layout, u32 tileRow, s32 paletteRow) {
    M2C_UNK Hide3DSprite();
    M2C_FIELD(sprite, s8 *, SCENE_PANEL_LAYOUT) = layout;
    M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TILE_ROW) = (s16) (tileRow >> 5);
    M2C_FIELD(sprite, s32 *, SPRITE_ACTOR_PALETTE) = (s32) ((M2C_FIELD(sprite, s32 *, SPRITE_ACTOR_PALETTE) & ~SPRITE_ACTOR_PALETTE_MASK) | ((u32) (paletteRow << 0x18) >> 6));
    Hide3DSprite();
}

/* Load the dialogue window's graphics into each screen the panel is shown on:
 * the panel's layout picks window_talk.cg or window_body.cg, decompressed to its
 * tile row in the selected engine's VRAM, then recolour the window palette. */
void ReloadScenePanelGraphics(void *panel) {
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void UpdateScenePanelPalette(void *);
    void *savedEngine;
    u32 target;
    s32 screen;
    void *engine;

    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) engine = g3DSpriteEngineMain; else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        target = (u32)(M2C_FIELD(panel, u8 *, SPRITE_ACTOR_STATE) << 28) >> 29;
        if (((target != DS3D_TARGET_MAIN) || (engine == g3DSpriteEngineMain)) &&
            ((target != DS3D_TARGET_SUB) || (engine == g3DSpriteEngineSub)) &&
            ((target != DS3D_TARGET_ACTIVE) || (engine == savedEngine))) {
            LoadWindowGraphics(M2C_FIELD(panel, u8 *, SCENE_PANEL_LAYOUT), M2C_FIELD(engine, s32 *, DS3D_ENGINE_TEXTURE) + (M2C_FIELD(panel, u16 *, SPRITE_ACTOR_TILE_ROW) << 5));
        }
        screen++;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
    UpdateScenePanelPalette(panel);
}

void SetScenePanelMotion(void *arg0, s8 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
    M2C_FIELD(arg0, s16 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s16 *, 0x5E) = arg3;
}

/* Set the scene panel's face display state and apply it to both of its face
 * children, refreshing each, then rebuild the panel's palette. */
void SetScenePanelFaceState(void *panel, s8 faceState) {
    M2C_UNK SetFaceSpriteActive(s32, s8);
    M2C_UNK RefreshFaceSprite(s32);
    void UpdateScenePanelPalette(void *);
    s32 child;
    s32 i;

    M2C_FIELD(panel, s8 *, SCENE_PANEL_FACE_STATE) = faceState;
    i = 0;
    do {
        child = Get3DSpriteChild(panel, i);
        SetFaceSpriteActive(child, faceState);
        RefreshFaceSprite(child);
        i += 1;
    } while (i < 2);
    UpdateScenePanelPalette(panel);
}

void SetScenePanelChildFlip(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x58) = arg1;
}

s32 Get3DSpriteChild(void *arg0, s32 arg1) {
    s32 var_r1;

    var_r1 = arg1;
    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r1 = 1 - var_r1;
    }
    return M2C_FIELD((arg0 + (var_r1 * 4)), s32 *, 0x68);
}

/* The scene panel's face sprite that is in use: the first of its two face
 * children (in flip order) that has a face loaded and its active-face flag set,
 * or NULL when neither is showing. */
void *GetActivePanelFace(void *panel) {
    s32 FaceSpriteIsLoaded(void *);
    s32 index;
    void *child;

    index = 0;
loop_1:
    child = (void *) Get3DSpriteChild(panel, index);
    if ((FaceSpriteIsLoaded(child) != 0) && (M2C_FIELD(child, u8 *, FACE_SPRITE_ACTIVE) != 0)) {
        return child;
    }
    index += 1;
    if (index >= 2) {
        return NULL;
    }
    goto loop_1;
}

/* Blend sprite palette colors for animation transitions. */
void UpdateScenePanelPalette(void *arg0) {
    extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
    extern u8 data_020f3a08[],data_020f3a3a[],data_020f3a9e[],data_020f3ad0[],data_020f3a6c[],data_020f39ee[],data_020f39d4[];
    s32 Is3DSpriteVisible(void*);s32 IsFaceSpriteLoaded(void*);s32 BlendRgb555_16(s32,s32,s32,s32);
    void DimPalette(void*);void *func_0209bfc8(void);void *func_02097e84(u8);
    s32 i;
    u8 *pal;
    s32 c0,c1,c2;
    u8 *a,*p=arg0,*b;
    void *old,*engine,*q,*q0;
    u32 mode;
    q0=(void*)Get3DSpriteChild(p,0);
    q=(void*)Get3DSpriteChild(p,1);
    b=M2C_FIELD(q,u8**,0x60);
    a=M2C_FIELD(q0,u8**,0x60);
    old=gCur3DSpriteEngine;
    i=0;do{
        if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
        gCur3DSpriteEngine=engine;
        mode=(u32)(p[0x48]<<28)>>29;
        if((mode!=0 || engine==g3DSpriteEngineMain) && (mode!=1 || engine==g3DSpriteEngineSub) && (mode!=3 || engine==old)){
            LoadWindowPalette((u16)(((u32)(M2C_FIELD(p,u32*,0x40)<<6)>>24)+16));
            pal=(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x30)+(((((u32)(M2C_FIELD(p,u32*,0x40)<<6)>>24)+16)<<5)&~1);
            c0=M2C_FIELD(pal,u16*,0x16);c1=M2C_FIELD(pal,u16*,0x18);c2=M2C_FIELD(pal,u16*,0x1a);
            if(a[0x59]){if(Is3DSpriteVisible(a))c0=c1;}else c1=BlendRgb555_16(c1,0,8,8);
            if(b[0x59]){if(Is3DSpriteVisible(b))c0=c2;}else c2=BlendRgb555_16(c2,0,8,8);
            M2C_FIELD(pal,u16*,6)=c1;M2C_FIELD(pal,u16*,8)=c2;M2C_FIELD(pal,u16*,10)=c0;
            if(!p[0x59])DimPalette(pal);
            M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=16;
        }
        i++;
    }while(i<2);
    gCur3DSpriteEngine=old;
    M2C_FIELD(p,void**,0x60)=data_020f3a08;M2C_FIELD(p,void**,0x64)=data_020f3a08;
    switch(p[0x5a]){
        case 2:
            if(IsFaceSpriteLoaded(a)&&Is3DSpriteVisible(a)){if(a[0x59])M2C_FIELD(p,void**,0x60)=data_020f3a3a;else M2C_FIELD(p,void**,0x60)=data_020f3a9e;}
            if(IsFaceSpriteLoaded(b)&&Is3DSpriteVisible(b)){if(b[0x59])M2C_FIELD(p,void**,0x64)=data_020f3ad0;else M2C_FIELD(p,void**,0x64)=data_020f3a6c;}
            p[0x49]=4;break;
        case 1:M2C_FIELD(p,void**,0x60)=data_020f39ee;M2C_FIELD(p,void**,0x64)=data_020f39d4;p[0x49]=7;break;
    }
    q=func_0209bfc8();
    p=GetActivePanelFace((s32)arg0);
    if(q && p)M2C_FIELD(q,void**,0x60)=func_02097e84(p[0x58]);
}

/* Set up a scene panel's pair of CO faces: clear its flip flag, face state,
 * layout, motion and the two half sprite sources, then create one face child per
 * half and give the two faces their layout slots and variant flags. */
M2C_UNK InitScenePanelFaces(void *panel) {
    void *CreateFaceSprite(void *);
    void SetFaceSpriteLayout(void *, s32);
    void SetFaceSpriteVariant(void *, s32);
    s32 i;
    i = 0;
    M2C_FIELD(panel, u8 *, SCENE_PANEL_LAYOUT) = 0;
    M2C_FIELD(panel, u8 *, SCENE_PANEL_MOTION) = 0;
    M2C_FIELD(panel, u16 *, SCENE_PANEL_MOTION_X) = 0;
    M2C_FIELD(panel, u16 *, SCENE_PANEL_MOTION_Y) = 0;
    M2C_FIELD(panel, s32 *, SCENE_PANEL_HALF0) = 0;
    M2C_FIELD(panel, s32 *, SCENE_PANEL_HALF1) = 0;
    M2C_FIELD(panel, u8 *, SCENE_PANEL_FACE_STATE) = 1;
    M2C_FIELD(panel, u8 *, SCENE_PANEL_FLIP) = 0;
    do {
        void *face = CreateFaceSprite(panel);
        ((void **)(panel + SCENE_PANEL_FACE0))[i] = face;
        SetFaceSpriteLayout(((void **)(panel + SCENE_PANEL_FACE0))[i], i);
        i++;
    } while (i < 2);
    SetFaceSpriteVariant(M2C_FIELD(panel, void **, SCENE_PANEL_FACE0), 1);
    SetFaceSpriteVariant(M2C_FIELD(panel, void **, SCENE_PANEL_FACE1), 0);
}

/* Reset the current 3D sprite bank's row split for `sprite`, unless the sprite's
 * cell grid is not split at all (SPRITE_ACTOR_SPLIT = 16, the whole sprite). */
M2C_UNK Reset3DSpriteBankSplitForSprite(void *sprite) {
    u8 splitRow = M2C_FIELD(sprite, u32 *, SPRITE_ACTOR_SPLIT) >> 26;

    if (splitRow == 16) return splitRow;
    return Reset3DSpriteBankState(splitRow);
}

/* Per-frame update of a scene panel: advance its fade and slide, re-split the
   sprite bank, bob the panel with the motion table, place its two face children
   with their linked faces and draw the two panel halves. */
void UpdateScenePanel(void *arg0) {
void UpdateSpriteFade(void *),UpdateSpriteSlide(void *);
s32 Is3DSpriteAnimating(void *);
void DrawSpriteActorAt(void *,s32,s32,s32,void *);
s32 Is3DSpriteVisible(void *);
extern void *g3DSpriteBankMain;extern u32 gFrameCounter;
extern u8 data_020f39cc[],data_020f39c4[];
ScenePanelMotionTable motionTable;
s32 childIndex,offset,x,y;void *child,*sprite;u8 mode;
UpdateSpriteFade(arg0);UpdateSpriteSlide(arg0);
if((u8)(M2C_FIELD(arg0,u32 *,SPRITE_ACTOR_SPLIT)>>26)!=16){
u16 *flags;u8 splitRow;
Reset3DSpriteBankState();
flags=(u16 *)((u8 *)g3DSpriteBankMain+0x12);
splitRow=(u8)(M2C_FIELD(arg0,u32 *,SPRITE_ACTOR_SPLIT)>>26);
*flags=(*flags&~0xc0)|0x40;
M2C_FIELD(g3DSpriteBankMain,u8 *,0x51)=splitRow;
M2C_FIELD(g3DSpriteBankMain,u8 *,0x52)=16-splitRow;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)&=~1;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)&=~2;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)&=~4;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)&=~8;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)&=~16;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)|=0x100;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)|=0x200;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)|=0x400;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)|=0x800;
M2C_FIELD(g3DSpriteBankMain,u16 *,0x12)|=0x1000;
}
if(M2C_FIELD(arg0,u8 *,SCENE_PANEL_FACE_STATE) && !Is3DSpriteAnimating(arg0)){
motionTable=data_020f3b04;
offset=motionTable.values[(gFrameCounter>>2)&15];
switch(M2C_FIELD(arg0,u8 *,SCENE_PANEL_MOTION)){
case 1:DrawSpriteActorAt(arg0,M2C_FIELD(arg0,s16 *,SCENE_PANEL_MOTION_X)-offset,M2C_FIELD(arg0,s16 *,SCENE_PANEL_MOTION_Y),2,data_020f39cc);break;
case 2:DrawSpriteActorAt(arg0,M2C_FIELD(arg0,s16 *,SCENE_PANEL_MOTION_X),M2C_FIELD(arg0,s16 *,SCENE_PANEL_MOTION_Y)-offset,2,data_020f39c4);break;
}
}
childIndex=0;do{
child=(void *)Get3DSpriteChild(arg0,childIndex);
mode=M2C_FIELD(child,u8 *,FACE_SPRITE_LAYOUT);
sprite=M2C_FIELD(child,void **,FACE_SPRITE_CHILD);
switch(M2C_FIELD(child,u8 *,FACE_SPRITE_EXPRESSION)){
case 5:case 6:case 7:
x=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_X);y=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_Y);
M2C_FIELD(child,s16 *,SPRITE_ACTOR_X)=x+mode*192+8;
M2C_FIELD(child,s16 *,SPRITE_ACTOR_Y)=y+8;
x=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_X);y=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_Y);
M2C_FIELD(sprite,s16 *,SPRITE_ACTOR_X)=x+mode*192;
M2C_FIELD(sprite,s16 *,SPRITE_ACTOR_Y)=y+48;
if(Is3DSpriteVisible(arg0)){Show3DSprite((s32)child);Show3DSprite((s32)sprite);}else{Hide3DSprite((s32)child);Hide3DSprite((s32)sprite);}
break;
case 8:case 9:case 10:
M2C_FIELD(child,s16 *,SPRITE_ACTOR_X)=mode*96;M2C_FIELD(child,s16 *,SPRITE_ACTOR_Y)=0;
x=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_X);y=M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_Y);
M2C_FIELD(sprite,s16 *,SPRITE_ACTOR_X)=x+mode*184+4;
M2C_FIELD(sprite,s16 *,SPRITE_ACTOR_Y)=y+2;break;
}
childIndex++;
}while(childIndex<2);
DrawSpriteActorAt(arg0,M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_X),M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_Y),M2C_FIELD(arg0,s8 *,SPRITE_ACTOR_PRIORITY),M2C_FIELD(arg0,void **,SCENE_PANEL_HALF0));
DrawSpriteActorAt(arg0,M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_X)+128,M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_Y),M2C_FIELD(arg0,s8 *,SPRITE_ACTOR_PRIORITY),M2C_FIELD(arg0,void **,SCENE_PANEL_HALF1));
}

void func_0209e980(void) {
    M2C_UNK InitScenePanelFaces();
    InitScenePanelFaces();
}

void func_0209e98c(void) {
    M2C_UNK Reset3DSpriteBankSplitForSprite();
    Reset3DSpriteBankSplitForSprite();
}

void func_0209e998(void) {
    ((void (*)())UpdateScenePanel)();
}

/* Create a scene-panel 3D sprite from gScenePanelSpriteClass, defaulting the layer
 * to 7, and install its vtable.  Returns the new sprite, or NULL. */
void **Alloc3DSprite(s32 layer) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gScenePanelSpriteClass, gScenePanelSpriteVtbl;
    void **result;
    if (layer == 0) layer = 7;
    result = CreateSpriteFromClass(&gScenePanelSpriteClass, layer);
    if (result != 0) {
        Init3DSpriteActor();
        *result = &gScenePanelSpriteVtbl;
    }
    return result;
}

void FindScenePanel(M2C_UNK arg0) {
    M2C_UNK Find3DSpriteByClassAndZ(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScenePanelSpriteClass;
    Find3DSpriteByClassAndZ(&gScenePanelSpriteClass, arg0);
}

void func_0209e9f4(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gScenePanelSpriteClass;
    DeleteSpriteObjectsOfClass(&gScenePanelSpriteClass);
}

void func_0209ea08(void) {

}

s32 func_0209ea0c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

#pragma opt_propagation off
/* Starts the battle preview for the target on tile (x, y): finds the map feature
 * anchored there, saves the battle RNG seed, forecasts the fight against the
 * cursor unit and subtracts the resulting damage from the feature's hit points,
 * then opens the battle preview panel on it.  Falls back to the plain unit path
 * when the tile holds no feature. */
void StartBattlePreviewOnFeature(s32 x, s32 y, s32 arg2) {
    void *FindMapFeatureAtTile();
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    extern void **gCurrentMap;
    extern M2C_UNK gBattleCommand, gBattlePreviewPanelDef;
    void *feature, *panel, *map;
    s32 hp, damage, seed;
    void **mapRef;
    s32 *seedSlot;

    feature = FindMapFeatureAtTile();
    if (!feature) { func_0209eaf4(x, y, arg2); return; }
    seed = GetRandomSeed();
    mapRef = gCurrentMap;
    seedSlot = (s32 *)&gBattleCommand;
    seedSlot[2] = seed;
    map = *mapRef;
    func_020d1690(M2C_FIELD(map, u8 *, MAP_CURSOR_UNIT_ID), (u32)(M2C_FIELD(feature, u16 *, 2) << 22) >> 28, (u8 *)map + MAP_CURSOR_X);
    hp = M2C_FIELD(feature, u8 *, 4);
    damage = M2C_FIELD(*gCurrentMap, s16 *, MAP_BATTLE_DAMAGE);
    if (hp < damage) M2C_FIELD(feature, u8 *, 4) = 0;
    else M2C_FIELD(feature, u8 *, 4) = hp - damage;
    panel = CreateSpriteFromClass(&gBattlePreviewPanelDef, 7);
    M2C_FIELD(panel, s32 *, 0x5c) = M2C_FIELD(*gCurrentMap, s32 *, MAP_CURSOR_UNIT);
    M2C_FIELD(panel, s32 *, 0x60) = arg2;
    M2C_FIELD(panel, void **, 0x34) = feature;
    M2C_FIELD(panel, s32 *, 0x38) = x;
    M2C_FIELD(panel, s32 *, 0x3c) = y;
}
#pragma opt_propagation reset
