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
void func_01ff883c(u16,u16,u16,s32);void func_01ff8930(s16,s16,u16,u16,u16,s32);
void func_01ff8a8c(u16,u16,u16,s32);void func_01ff8c0c(s16,s16,u16,u16,u16,s32);
void func_0209daec(void);
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
if((raw<<28>>28)==0)func_01ff883c(M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
else func_01ff8a8c(M2C_FIELD(cur,u16 *,12),M2C_FIELD(cur,u16 *,14),M2C_FIELD(cur,u16 *,16),M2C_FIELD(cur,s32 *,4));
}
cur=M2C_FIELD(cur,void **,0);
}
i++;
}while(i<2);
data_027e01d8=saved;func_0209daec();
}

s32 func_0209dc48(void) {
    extern u16 *gKeyState;
    u16 keys;
    keys = gKeyState[0];
    if (keys & 1) return 0x10;
    if (keys & 2) return 0x20;
    if (keys & 8) return 0x400;
    keys = gKeyState[3];
    if ((keys & 1) && (keys & 0x80)) return 0x10;
    return 0;
}

s32 func_0209dc9c(void) {
    extern u16 *gKeyState;
    u16 keys;
    keys = gKeyState[0];
    if (keys & 8) return 0x400;
    if (keys & 2) return 0x20;
    if (keys & 1) return 0x10;
    keys = gKeyState[3];
    if ((keys & 1) && (keys & 0x80)) return 0x10;
    return 0;
}

s32 GetPanelKeyAction(void) {
    extern u16 *gKeyState;
    u16 temp_r0;

    temp_r0 = *gKeyState;
    if (temp_r0 & 0x20) {
        return 4;
    }
    if (temp_r0 & 0x10) {
        return 8;
    }
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    return 0;
}

void func_0209dd34(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0x100;
    M2C_FIELD(arg0, s16 *, 6) = 0xC0;
}

s32 func_0209dd54(void) {
    extern void *gTouchState;
    s16 rect[4];
    u16 x;
    u16 y;
    x = M2C_FIELD(gTouchState, u16 *, 0);
    y = M2C_FIELD(gTouchState, u16 *, 2);
    func_0209dd34(rect);
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, 0x14) == 0) return 0;
    if (rect[0] < x && x < rect[0] + rect[2] && rect[1] < y && y < rect[1] + rect[3]) return 0x10;
    return 0;
}

s32 func_0209dde0(void) {
    extern void *gTouchState;
    s16 rect[4];
    u16 x;
    u16 y;
    x = M2C_FIELD(gTouchState, u16 *, 0);
    y = M2C_FIELD(gTouchState, u16 *, 2);
    func_0209dd34(rect);
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, 0x14) == 0) return 0;
    if (rect[0] < x && x < rect[0] + rect[2] && rect[1] < y && y < rect[1] + rect[3]) return 0x10;
    return 0;
}

void SetWidgetRect(s32 arg0, Unk0209Rect arg1) {
    extern Unk0209Rect data_0215bde8[];
    Unk0209Rect *rect;
    rect = &data_0215bde8[arg0];
    *rect = arg1;
}

s32 func_0209deb0(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_020b2e78(M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_0215bdf0;
    extern M2C_UNK data_0215bdf8;
    if (func_020b2e78(arg0, arg1, &data_0215bdf0) != 0) {
        return 1;
    }
    if (func_020b2e78(arg0, arg1, &data_0215bdf8) != 0) {
        return 2;
    }
    return 0;
}

/* Returns the action code for the current stylus interaction, based on which of two touch regions the point lies in. */
s32 GetPanelTouchAction(void) {
    extern void *gTouchState;
    extern s32 data_0215bde0;
    s32 region;

    region = func_0209deb0(M2C_FIELD(gTouchState, u16 *, 0), M2C_FIELD(gTouchState, u16 *, 2));
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

void func_0209dfe4(void *arg0) {
    M2C_UNK DeleteSpriteObject(void *);
    s32 TaskIsFinished(s32);
    if (TaskIsFinished(M2C_FIELD(arg0, s32 *, 0x34)) == 0) {
        return;
    }
    DeleteSpriteObject(arg0);
}

void func_0209e008(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    M2C_UNK (*temp_r0)();

    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x34));
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x38));
    temp_r0 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x3C);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r0();
}

void func_0209e034(void *arg0) {
    M2C_FIELD(arg0, void (**)(void), 0)();
}

void func_0209e044(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    s32 HeapAllocBlock(u32);
    void func_01ffa8bc(void *, s32);
    void TaskCreate(s32, void (*)(void *), void *, s32, u32, s32);
    void TaskWake(s32);
    extern M2C_UNK data_0211f7dc;
    void *p;
    p = CreateSpriteFromClass(&data_0211f7dc, 3);
    M2C_FIELD(p, s32 *, 0x34) = HeapAllocBlock(0xC0);
    M2C_FIELD(p, s32 *, 0x38) = HeapAllocBlock(arg2);
    M2C_FIELD(p, s32 *, 0x3C) = arg4;
    func_01ffa8bc(p, arg1);
    M2C_FIELD(p, s32 *, 0x40) = arg0;
    M2C_FIELD(p, s32 *, 0x44) = arg1;
    TaskCreate(M2C_FIELD(p, s32 *, 0x34), func_0209e034, p + 0x40, M2C_FIELD(p, s32 *, 0x38) + (arg2 & ~3), arg2, arg3);
    TaskWake(M2C_FIELD(p, s32 *, 0x34));
}

u8 func_0209e0dc(M2C_UNK arg0) {
    extern M2C_UNK data_0211f7dc;
    u8 var_r0;

    if (func_01ffa860(&data_0211f7dc, arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void LoadWindowGraphics(s32 arg0, M2C_UNK arg1) {
    M2C_UNK LoadDecompressedFileTo(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211f840;
    extern M2C_UNK data_0211f848;
    extern M2C_UNK data_0211f858;
    SetFileDirectory(&data_0211f840);
    switch (arg0) {                                 /* irregular */
    case 1:
        LoadDecompressedFileTo(&data_0211f848, arg1);
        return;
    case 2:
        LoadDecompressedFileTo(&data_0211f858, arg1);
        return;
    }
}

void LoadWindowPalette(s32 arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_0211f868;
    extern M2C_UNK data_0211f870;
    SetFileDirectory(&data_0211f868);
    LoadFileToSpriteBuffer(&data_0211f870, arg0 << 5, 0x20);
}

void func_0209e184(void *arg0, s8 arg1, u32 arg2, s32 arg3) {
    M2C_UNK Hide3DSprite();
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg2 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg3 << 0x18) >> 6));
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

void func_0209e25c(void *arg0, s8 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
    M2C_FIELD(arg0, s16 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s16 *, 0x5E) = arg3;
}

void func_0209e26c(void *arg0, s8 arg1) {
    M2C_UNK func_020991f4(s32, s8);
    M2C_UNK RefreshFaceSprite(s32);
    void UpdateScenePanelPalette(void *);
    s32 temp_r0;
    s32 var_r5;

    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
    var_r5 = 0;
    do {
        temp_r0 = Get3DSpriteChild(arg0, var_r5);
        func_020991f4(temp_r0, arg1);
        RefreshFaceSprite(temp_r0);
        var_r5 += 1;
    } while (var_r5 < 2);
    UpdateScenePanelPalette(arg0);
}

void func_0209e2b8(void *arg0, s8 arg1) {
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

void *func_0209e2d8(M2C_UNK arg0) {
    s32 FaceSpriteIsLoaded();
    s32 var_r5;
    void *temp_r4;

    var_r5 = 0;
loop_1:
    temp_r4 = Get3DSpriteChild(arg0, var_r5);
    if ((FaceSpriteIsLoaded() != 0) && (M2C_FIELD(temp_r4, u8 *, 0x5C) != 0)) {
        return temp_r4;
    }
    var_r5 += 1;
    if (var_r5 >= 2) {
        return NULL;
    }
    goto loop_1;
}

/* Blend sprite palette colors for animation transitions. */
void UpdateScenePanelPalette(void *arg0) {
    extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
    extern u8 data_020f3a08[],data_020f3a3a[],data_020f3a9e[],data_020f3ad0[],data_020f3a6c[],data_020f39ee[],data_020f39d4[];
    s32 Is3DSpriteVisible(void*);s32 IsFaceSpriteLoaded(void*);s32 BlendRgb555_16(s32,s32,s32,s32);
    void func_020ae528(void*);void *func_0209bfc8(void);void *func_02097e84(u8);
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
            if(!p[0x59])func_020ae528(pal);
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
    p=func_0209e2d8((s32)arg0);
    if(q && p)M2C_FIELD(q,void**,0x60)=func_02097e84(p[0x58]);
}

M2C_UNK func_0209e5d0(void *arg0) {
    void *func_020993d4(void *);
    void func_02099310(void *, s32);
    void func_02099318(void *, s32);
    s32 i;
    i = 0;
    M2C_FIELD(arg0, u8 *, 0x5A) = 0;
    M2C_FIELD(arg0, u8 *, 0x5B) = 0;
    M2C_FIELD(arg0, u16 *, 0x5C) = 0;
    M2C_FIELD(arg0, u16 *, 0x5E) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, u8 *, 0x59) = 1;
    M2C_FIELD(arg0, u8 *, 0x58) = 0;
    do {
        void *p = func_020993d4(arg0);
        ((void **)(arg0 + 0x68))[i] = p;
        func_02099310(((void **)(arg0 + 0x68))[i], i);
        i++;
    } while (i < 2);
    func_02099318(M2C_FIELD(arg0, void **, 0x68), 1);
    func_02099318(M2C_FIELD(arg0, void **, 0x6C), 0);
}

M2C_UNK func_0209e640(void *a){u8 v=M2C_FIELD(a,u32 *,0x40)>>26;if(v==16)return v;return Reset3DSpriteBankState(v);}

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
    M2C_UNK func_0209e5d0();
    func_0209e5d0();
}

void func_0209e98c(void) {
    M2C_UNK func_0209e640();
    func_0209e640();
}

void func_0209e998(void) {
    ((void (*)())UpdateScenePanel)();
}

void **Alloc3DSprite(s32 arg0) {
    void **CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_0211f810, data_0211f804;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = CreateSpriteFromClass(&data_0211f810, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_0211f804;
    }
    return result;
}

void FindScenePanel(M2C_UNK arg0) {
    M2C_UNK func_01ffa860(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211f810;
    func_01ffa860(&data_0211f810, arg0);
}

void func_0209e9f4(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_0211f810;
    DeleteSpriteObjectsOfClass(&data_0211f810);
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
