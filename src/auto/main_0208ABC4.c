/* 24 functions from 0x0208ABC4 to 0x0208B884 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "sound.h"
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;

/* Text layer panel state word (+0x58, TEXT_LAYER_PANEL_STATE) as a bitfield: the
 * low six bits hold the panel kind and animation mode, bits 6..7 the selected
 * two-option choice (0 = left/accept, 1 = right/cancel). */
typedef struct {
    u8 unk_0x00[0x58];
    s32 kindAndAnim : 6;
    s32 choice : 2;
    s32 rest : 24;
} TextLayerPanelState;

typedef struct { u32 width:9; u32 height:9; u32 rest:14; } WindowSize0208;
typedef struct { u16 low:6; u16 window:2; u16 high:8; } WindowControl0208;
u8 IsTextLayerActive(void);

/* Per-frame input of a text-layer panel.  Ignore input while the panel is
 * animating open or closed.  A panel showing text (kind 1 or 2) is dismissed by
 * A or B with the confirm sound; the two-option panel (kind 3) switches its
 * highlighted choice with left/right, accepts with A (setting the map-confirm
 * flag) and cancels with B, then closes with the matching menu sound. */
void UpdateTextLayerPanel(M2C_UNK arg0) {
    void UpdatePanelLinkedIcons(void *);
    void StartWindowClose(void *);
    u8 SetPanelChoice(TextLayerPanelState *, s32);
    M2C_UNK PlaySoundEffect(s32);
    void EnableMapConfirm(void);
    void DisableMapConfirm(void);
    extern u16 *gKeyState;
    u32 panelKind;

    if (((u32)(M2C_FIELD(arg0, u8 *, TEXT_LAYER_PANEL_MODE) << 26) >> 30) != 0) {
        return;
    }
    UpdatePanelLinkedIcons(arg0);
    panelKind = (u8)((u32)(M2C_FIELD(arg0, s32 *, TEXT_LAYER_PANEL_STATE) << 29) >> 29);
    switch (panelKind) {
    case 1:
        if ((*(u16 *)gKeyState) & (KEY_A | KEY_B)) {
            PlaySoundEffect(SOUND_MENU_CONFIRM);
            StartWindowClose(arg0);
        }
        return;
    case 2:
        if ((*(u16 *)gKeyState) & (KEY_A | KEY_B)) {
            PlaySoundEffect(SOUND_MENU_CONFIRM);
            StartWindowClose(arg0);
        }
        return;
    case 3:
        if (((*(u16 *)gKeyState) & KEY_LEFT) && SetPanelChoice((TextLayerPanelState *)arg0, 0)) {
            PlaySoundEffect(SOUND_MENU_MOVE);
        }
        if (((*(u16 *)gKeyState) & KEY_RIGHT) && SetPanelChoice((TextLayerPanelState *)arg0, 1)) {
            PlaySoundEffect(SOUND_MENU_MOVE);
        }
        if ((*(u16 *)gKeyState) & KEY_A) {
            if (((M2C_FIELD(arg0, s32 *, TEXT_LAYER_PANEL_STATE) << 24) >> 30) == 0) {
                EnableMapConfirm();
                PlaySoundEffect(SOUND_MENU_CONFIRM);
            }
            if (((M2C_FIELD(arg0, s32 *, TEXT_LAYER_PANEL_STATE) << 24) >> 30) == 1) {
                DisableMapConfirm();
                PlaySoundEffect(SOUND_MENU_CANCEL);
            }
            StartWindowClose(arg0);
            return;
        }
        if ((*(u16 *)gKeyState) & KEY_B) {
            DisableMapConfirm();
            PlaySoundEffect(SOUND_MENU_CANCEL);
            StartWindowClose(arg0);
        }
        return;
    }
    return;
}

void UpdatePanelLinkedIcons(void *entity) {
    unsigned flagRight;
    unsigned flagLeft;
    void *objLeft;
    void *objRight;

    objLeft = M2C_FIELD(entity, void **, 0x5C);
    objRight = M2C_FIELD(entity, void **, 0x60);
    if ((u8) ((u32) (M2C_FIELD((int)entity, s32 *, 0x58) << 0x1D) >> 0x1D) != 3) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(objLeft, void **, 0x64), s8 *, 0xC) == 1) {
        flagLeft = 1;
    } else {
        flagLeft = 0;
    }
    if (flagLeft & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) (M2C_FIELD(entity, s32 *, 0x58) & ~0xC0);
    }
    if (M2C_FIELD(M2C_FIELD(objRight, void **, 0x64), s8 *, 0xC) == 1) {
        flagRight = 1;
    } else {
        flagRight = 0;
    }
    if (flagRight & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) ((M2C_FIELD(entity, s32 *, 0x58) & ~0xC0) | 0x40);
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) == 0) {
        M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) != 1) {
        return;
    }
    M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
}

/* Set the two-option panel's highlighted choice (bits 6..7 of the panel state
 * word, TEXT_LAYER_PANEL_CHOICE_MASK) and return nonzero when it changed. */
u8 SetPanelChoice(TextLayerPanelState *panel, s32 choice) {
    s32 changed;
    changed = panel->choice != choice;
    panel->choice = choice;
    return changed;
}

/* Start a window opening: enter the opening animation mode, hide its two child
 * sprites, and hand off to the opened-window notification. */
void StartWindowOpen(void *window) {
    M2C_UNK Hide3DSprite();
    M2C_UNK NotifyWindowOpened(void *);
    M2C_FIELD(window, s32 *, TEXT_LAYER_PANEL_STATE) = (s32) ((M2C_FIELD(window, s32 *, TEXT_LAYER_PANEL_STATE) & ~TEXT_LAYER_PANEL_ANIMATION_MASK) | TEXT_LAYER_PANEL_ANIM_OPEN);
    M2C_FIELD(window, u8 *, TEXT_LAYER_PANEL_MODE) = (u8) ((M2C_FIELD(window, u8 *, TEXT_LAYER_PANEL_MODE) & ~TEXT_LAYER_PANEL_MODE_MASK) | TEXT_LAYER_PANEL_MODE_OPEN);
    M2C_FIELD(window, s8 *, TEXT_LAYER_PANEL_FRAME) = 0;
    M2C_FIELD(window, s8 *, TEXT_LAYER_PANEL_FRAMES) = 6;
    if (M2C_FIELD(window, s32 *, TEXT_LAYER_LEFT_ICON) != 0) {
        Hide3DSprite();
    }
    if (M2C_FIELD(window, s32 *, TEXT_LAYER_RIGHT_ICON) != 0) {
        Hide3DSprite();
    }
    NotifyWindowOpened(window);
}

/* Start closing a window sprite: a sprite with no animation state is deleted
 * outright; otherwise it enters its closing mode, hides its two child sprites
 * and starts an eight-frame close, which NotifyWindowClosed then plays out. */
void StartWindowClose(void *window) {
    M2C_UNK NotifyWindowClosed(void *);
    s32 flags;
    u32 state;

    flags = M2C_FIELD(window, s32 *, 0x58);
    state = (u32) (flags << 0x1A) >> 0x1D;
    if (state == 0) {
        DeleteSpriteObject(window, flags, state);
    } else {
        M2C_FIELD(window, s32 *, 0x58) = (s32) ((flags & ~0x38) | 0x18);
        M2C_FIELD(window, u8 *, 0x48) = (u8) ((M2C_FIELD(window, u8 *, 0x48) & ~0x30) | 0x20);
        M2C_FIELD(window, s8 *, 0x4B) = 0;
        M2C_FIELD(window, s8 *, 0x4A) = 8;
        if (M2C_FIELD(window, s32 *, 0x5C) != 0) {
            Hide3DSprite();
        }
        if (M2C_FIELD(window, s32 *, 0x60) != 0) {
            Hide3DSprite();
        }
    }
    NotifyWindowClosed(window);
}

void func_0208af98(void *p) {
 s32 EaseInterpolate(s32,s32,s32,s32,s32); void Show3DSprite(void*);void TextLayer_AdvancePageOrClose(void*);s32 Is3DSpriteAnimating();void DrawTileRow(u16,u16,u16,u16,s32);void func_0208e18c(s16,s16,s16,s16,u16,s32);
 s32 bottom,right,tx,ty,j,maxw,i,depth,y,x,height,width; u8 alpha;u32 tile,mode,count;u16 frame;void *old,*engine; WindowControl0208 *volatile control;u8 *widths,*aligns;s32 w; u16 kind;
 frame=(u16)(0x1000|(0x3ff&(0xa0>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30))));
 tile=M2C_FIELD(p,u16*,0x3e)<<5;
 width=((WindowSize0208*)((u8*)p+0x40))->width;height=((WindowSize0208*)((u8*)p+0x40))->height;
 x=M2C_FIELD(p,s16*,0x34);y=M2C_FIELD(p,s16*,0x36);depth=M2C_FIELD(p,s8*,0x49);alpha=4;
 mode=(u32)(M2C_FIELD(p,u8*,0x48)<<26)>>30;
 switch(mode){
 case 1:
  M2C_FIELD(p,u8*,0x4b)++;
  if(M2C_FIELD(p,u8*,0x4b)>=M2C_FIELD(p,u8*,0x4a)){
   M2C_FIELD(p,u32*,0x58)=(M2C_FIELD(p,u32*,0x58)&~0x38)|0x10;
   M2C_FIELD(p,u8*,0x48)&=~0x30;
   if(M2C_FIELD(p,void**,0x5c))Show3DSprite(M2C_FIELD(p,void**,0x5c));
   if(M2C_FIELD(p,void**,0x60))Show3DSprite(M2C_FIELD(p,void**,0x60));
  }
  width=(EaseInterpolate(4,0,width,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a))+4)&~7;
  x+=((s32)(((WindowSize0208*)((u8*)p+0x40))->width)-width)/2;
  if(!((u32)(M2C_FIELD(p,u32*,0x58)<<18)>>31))alpha=(u8)EaseInterpolate(0,0,4,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a));
  break;
 case 2:
  M2C_FIELD(p,u8*,0x4b)++;
  if(M2C_FIELD(p,u8*,0x4b)>=M2C_FIELD(p,u8*,0x4a))TextLayer_AdvancePageOrClose(p);
  width=(EaseInterpolate(4,width,0,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a))+4)&~7;
  x+=((s32)(((WindowSize0208*)((u8*)p+0x40))->width)-width)/2;
  alpha=(u8)EaseInterpolate(0,4,0,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a));
  break;
 }
 right=x+width;bottom=y+height;old=gCur3DSpriteEngine;
 for(i=0;i<2;i++){
  engine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
  mode=(u32)(M2C_FIELD(p,u8*,0x48)<<28)>>29;
  if((mode!=0||engine==g3DSpriteEngineMain)&&(mode!=1||engine==g3DSpriteEngineSub)&&(mode!=3||engine==old)){
   if((u8)((u32)(M2C_FIELD(p,u32*,0x58)<<21)>>31)){
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x48)=x;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x4a)=y;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x49)=right;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x4b)=bottom;
    control=(WindowControl0208*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0)+0x12);control->window=3;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x51)=0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x52)=0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x53)=alpha;
   }
   if(!Is3DSpriteAnimating(p)){
    maxw=0;count=(u32)(M2C_FIELD(p,u32*,0x58)<<10)>>28;
    if(count){widths=M2C_FIELD(p,u8**,0x68);for(j=0;j<count;j++)if(maxw<*widths++)maxw=M2C_FIELD(p,u8**,0x68)[j];}
    j=0;if(j<count){ty=y+8;tx=x+(width-maxw)/2;
    do {
     w=M2C_FIELD(p,u8**,0x68)[j];
     kind=(u16)(0x2000|(0x3ff&((tile>>5)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30))));
     switch(M2C_FIELD(p,u8**,0x6c)[j]){
      case 2:DrawTileRow((u16)tx,(u16)ty,(u16)((w+31)&~31),kind,depth);break;
      case 3:DrawTileRow((u16)(tx+maxw-w),(u16)ty,(u16)((w+31)&~31),kind,depth);break;
      default:DrawTileRow((u16)(x+(width-(s32)w)/2),(u16)ty,(u16)((w+31)&~31),kind,depth);break;
     }
     tile+=((((s32)w+7)>>3)+3>>2)<<8;
     ty+=16;j++;
    }while(j<((u32)(M2C_FIELD(p,u32*,0x58)<<10)>>28));
   }}
   if(width>=8&&height>=8)func_0208e18c((s16)x,(s16)y,(s16)width,(s16)height,frame,depth);
  }
 }
 gCur3DSpriteEngine=old;
}

void func_0208b4e4(void) {
    M2C_UNK func_0208a750();
    func_0208a750();
}

void func_0208b4f0(void) {
    M2C_UNK ReleaseWindowResources();
    ReleaseWindowResources();
}

void func_0208b4fc(void) {
    M2C_UNK UpdateTextLayerRefreshTimer();
    UpdateTextLayerRefreshTimer();
}

void func_0208b508(void) {
    M2C_UNK func_02089d30();
    func_02089d30();
}

void func_0208b514(M2C_UNK window) {
    UpdateTextLayerPanel(window);
}

/* Create a text-layer sprite under `owner` on the current 3D-sprite engine and
 * mark it TEXT_LAYER_PANEL_NESTED when another text layer was already up, so it
 * knows it is drawn over one. */
void CreateTextLayerChild(s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *InitTextLayer(void);
    extern M2C_UNK gTextLayerSpriteClass;
    s32 nested;
    void *layer;
    nested = IsTextLayerActive();
    layer = CreateSpriteFromClass(&gTextLayerSpriteClass, owner);
    if (layer != 0) layer = InitTextLayer();
    M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) = (M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) & ~TEXT_LAYER_PANEL_NESTED) | ((u32)(nested << 31) >> 18);
}

/* Create a text-layer sprite owned by `owner` and mark it TEXT_LAYER_PANEL_NESTED
 * when another text layer was already up, so it knows it is drawn over one. */
void CreateTextLayer(s32 owner) {
    void *CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    void *InitTextLayer(void);
    extern M2C_UNK gTextLayerSpriteClass;
    s32 nested;
    void *layer;
    nested = IsTextLayerActive();
    layer = CreateSpriteForOwner(&gTextLayerSpriteClass, owner);
    if (layer != 0) layer = InitTextLayer();
    M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) = (M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) & ~TEXT_LAYER_PANEL_NESTED) | ((u32)(nested << 31) >> 18);
}

u8 IsTextLayerActive(void) {
    u8 var_r0;
    if (FindTextLayer() != 0) var_r0 = 1;
    else var_r0 = 0;
    return var_r0;
}

/* True when a text-layer panel is on screen and still animating: FindTextLayer's
 * layer pointer stays in the argument register and doubles as the sprite that
 * Is3DSpriteAnimating inspects (it reports fading or sliding in progress, so
 * input should wait). */
s32 IsTextLayerAnimating(void) {
    s32 Is3DSpriteAnimating(void);
    if ((FindTextLayer() != 0) && (Is3DSpriteAnimating() != 0)) return 1;
    return 0;
}

s32 FindTextLayer(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gTextLayerSpriteClass;
    return FindObjectByClass(&gTextLayerSpriteClass);
}

void func_0208b600(void *arg0) {
    M2C_UNK func_0208b884(s32);
    func_0208b884(M2C_FIELD(arg0, s32 *, 0x34));
}

/* Create the draw-proxy child sprite for a scrolling-text sprite: its per-frame
 * step draws `owner`'s text, which it keeps at +0x34. */
void *CreateScrollingTextRenderSprite(s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gScrollingTextRenderSpriteClass;
    void *sprite = CreateSpriteFromClass(&gScrollingTextRenderSpriteClass, 1);
    M2C_FIELD(sprite, s32 *, 0x34) = owner;
    return sprite;
}

/* Constructor of the scrolling text sprite: run the sprite actor's shared base
   initialiser, install the scrolling text class, reset the rendered width, the
   scroll position and timer (one pixel every 60 frames), then start the sprite
   just below the screen and slide it up to y = 0xA0. */
void *InitScrollingTextSprite(void *sprite) {
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gScrollingTextSpriteVtable;
    Init3DSpriteActor();
    M2C_FIELD(sprite, M2C_UNK **, DS3D_SPRITE_CLASS) = &gScrollingTextSpriteVtable;
    M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TEXT_WIDTH) = 0;
    M2C_FIELD(sprite, s16 *, SPRITE_TEXT_SCROLL) = 0;
    M2C_FIELD(sprite, s8 *, SPRITE_TEXT_SCROLL_TIMER) = 0;
    M2C_FIELD(sprite, s8 *, SPRITE_TEXT_SCROLL_PERIOD) = 0x3C;
    M2C_FIELD(sprite, s32 *, SPRITE_TEXT_HANDLE) = 0;
    M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_TILE) = 0;
    M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_X) = 0;
    M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_Y) = 0xC0;
    Set3DSpriteSlideTargetAndStart(sprite, 0, 0xA0, 0, 0xC0);
    return sprite;
}

/* Render `text` into a sprite actor's text texture on every display engine the
   actor's screen mode selects, storing the rendered width and resetting the
   actor's text animation. */
void SetSpriteText(M2C_UNK arg0, M2C_UNK arg1) {
extern void *g3DSpriteEngineSub;extern void *g3DSpriteEngineMain;extern void *gCur3DSpriteEngine;
s16 RenderTextToBitmap(M2C_UNK,M2C_UNK);
void *old; s32 i; void *p; u32 mode;
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
mode=(u32)(M2C_FIELD(arg0,u8 *,0x48)<<28)>>29;
if(((mode!=0)||(p==g3DSpriteEngineMain))&&((mode!=1)||(p==g3DSpriteEngineSub))&&((mode!=3)||(p==old))){
M2C_FIELD(arg0,s16 *,SPRITE_ACTOR_TEXT_WIDTH)=RenderTextToBitmap((u8 *)M2C_FIELD(p,void **,0x1c)+((M2C_FIELD(arg0,u16 *,SPRITE_ACTOR_TILE_ROW)<<5)+0x400),arg1);
M2C_FIELD(arg0,s16 *,0x5a)=0;M2C_FIELD(arg0,u8 *,0x5c)=0;
}i++;
}while(i<2);
gCur3DSpriteEngine=old;
}

/* Draw the localized message `textId` into a text sprite's text texture. */
void SetTextById(M2C_UNK sprite, M2C_UNK textId) {
    s32 GetLocalizedText(M2C_UNK);
    SetSpriteText(sprite, GetLocalizedText(textId));
}

/* Refresh the display banks selected by the entity's mode, then allocate and link a handle for it. */
void func_0208b778(void *entity) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    extern u8 data_0211e1ec[], gUiSpritePalette[];
    void *savedBank;
    void *bank;
    u32 mode;
    s32 i;

    savedBank = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) {
            bank = g3DSpriteEngineMain;
        } else {
            bank = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = bank;
        mode = (u32)(M2C_FIELD(entity, u8 *, 0x48) << 28) >> 29;
        if ((mode != 0 || bank == g3DSpriteEngineMain) &&
            (mode != 1 || bank == g3DSpriteEngineSub) &&
            (mode != 3 || bank == savedBank)) {
            LoadGraphicsBlock(data_0211e1ec, M2C_FIELD(bank, u8 **, 0x1C) + (M2C_FIELD(entity, u16 *, 0x3E) << 5));
            CopyToObjPaletteShadow(gUiSpritePalette, ((u16)((u32)(M2C_FIELD(entity, u32 *, 0x40) << 6) >> 24) + 16) << 5, 32);
            LoadScenePanelPalette(18);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
    M2C_FIELD(entity, void **, 0x60) = CreateScrollingTextRenderSprite((s32)entity);
}

void func_0208b868(void *arg0) {
    M2C_UNK DeleteSpriteObject(s32);
    DeleteSpriteObject(M2C_FIELD(arg0, s32 *, 0x60));
}

void func_0208b878(void) {
    M2C_UNK UpdateSpriteSlide();
    UpdateSpriteSlide();
}

