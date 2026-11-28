/* 42 functions from 0x02088FF4 to 0x02089D30 (main), found by ds-decomp. */
#include "common.h"
#pragma push
#pragma optimization_level 0
static inline s32 SmoothSpritePosition(s32 next,s32 current) {
s32 delta=next-current;
s32 magnitude=delta<0?-delta:delta;
if(magnitude>1)next=current+(delta>>1);
return next;
}
#pragma pop
void TextLayer_SetText(void *, s32);
extern M2C_UNK gTextLayerVtable;

#pragma opt_common_subs off
void Hide3DSpriteSlide(void *sprite) {
    M2C_UNK Hide3DSprite(void *);

    /* Hide immediately if reverse sliding is disabled; otherwise begin the slide-out animation. */
    if (!M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_SLIDE_BACK_LEN)) {
        M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_X) = M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_START_X);
        M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_Y) = M2C_FIELD(sprite, s16 *, SPRITE_ACTOR_START_Y);
        M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_DELAY) = 0;
        M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) = (u8)(M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) & ~SPRITE_ACTOR_SLIDE_MODE_MASK);
        Hide3DSprite(sprite);
        return;
    }
    if ((((u32)M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 24) >> 30) == SPRITE_SLIDE_REVERSE) {
        return;
    }
    M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_TIMER) = 0;
    M2C_FIELD(sprite, s8 *, SPRITE_ACTOR_SLIDE_DELAY) = 0;
    M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) = (u8)((M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) & ~SPRITE_ACTOR_SLIDE_MODE_MASK) | SPRITE_ACTOR_SLIDE_MODE_MASK);
}
#pragma opt_common_subs reset
/* Nonzero while the sprite actor's visible bit (SPRITE_ACTOR_STATE bit 0) is set. */
u8 Is3DSpriteVisible(void *sprite) {
    u8 result;

    if (((u32)(M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 0x1F) >> 0x1F) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Nonzero while the sprite actor's visible bit (SPRITE_ACTOR_STATE bit 0) is
 * clear. */
u8 Is3DSpriteHidden(void *sprite) {
    u8 result;

    if (((u32)(M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 0x1F) >> 0x1F) == 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Nonzero while the sprite actor's fade mode (SPRITE_ACTOR_STATE bits 4-5) is
 * set, that is while UpdateSpriteFade is fading it. */
u8 Is3DSpriteFading(void *sprite) {
    u8 result;

    if (((u32)(M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 0x1A) >> 0x1E) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Nonzero while the sprite actor's slide mode (SPRITE_ACTOR_STATE bits 6-7) is
 * set, that is while UpdateSpriteSlide is moving it. */
u8 Is3DSpriteSliding(void *sprite) {
    u8 result;

    if (((u32)(M2C_FIELD(sprite, u8 *, SPRITE_ACTOR_STATE) << 0x18) >> 0x1E) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* Nonzero while the sprite actor is still animating: it is fading
 * (SPRITE_ACTOR_FADE_MASK) or sliding (SPRITE_ACTOR_SLIDE_MODE_MASK). */
u8 Is3DSpriteAnimating(void *sprite) {
    u8 result;

    if (Is3DSpriteFading(sprite)) return 1;
    if (Is3DSpriteSliding(sprite)) result = 1;
    else result = 0;
    return result;
}

#pragma scheduling on
M2C_UNK Init3DSpriteActor(void *arg0) {
extern M2C_UNK g3DSpriteVtable;
extern void *data_027e01d8;
extern s32 data_027e00c8;
u8 a;
u8 b;
M2C_FIELD(arg0, M2C_UNK **, 0) = &g3DSpriteVtable;
M2C_FIELD(arg0,u8 *,0x48) = (M2C_FIELD(arg0,u8 *,0x48)&~1)|1;
M2C_FIELD(arg0,s16 *,0x34)=0;
M2C_FIELD(arg0,s16 *,0x36)=0;
M2C_FIELD(arg0,s32 *,0x40)&=~0x1FF;
M2C_FIELD(arg0,s32 *,0x40)&=0xFFFC01FF;
M2C_FIELD(arg0,s32 *,0x40)&=~0x03FC0000;
M2C_FIELD(arg0,s16 *,0x3E)=0;
M2C_FIELD(arg0,s16 *,0x3C)=0xC00;
M2C_FIELD(arg0,s32 *,0x40)=(M2C_FIELD(arg0,s32 *,0x40)&~0xFC000000)|0x40000000;
if ((s32)data_027e01d8 == data_027e00c8) a=1; else a=0;
if (a!=1) b=1; else b=0;
M2C_FIELD(arg0,u8 *,0x48)=(M2C_FIELD(arg0,u8 *,0x48)&~0xE)|((u32)(b<<0x1D)>>0x1C);
M2C_FIELD(arg0,u8 *,0x49)=0x11;
M2C_FIELD(arg0,s32 *,0x44)=0;
M2C_FIELD(arg0,u8 *,0x48)=(u8)(M2C_FIELD(arg0,u8 *,0x48)&~0x30)&~0xC0;
M2C_FIELD(arg0,u8 *,0x4D)=0;
M2C_FIELD(arg0,u8 *,0x4C)=0;
M2C_FIELD(arg0,u8 *,0x4E)=8;
M2C_FIELD(arg0,u8 *,0x4F)=8;
M2C_FIELD(arg0,s16 *,0x38)=0;
M2C_FIELD(arg0,s16 *,0x3A)=0;
}
void Init3DSprite(void *arg0)
{
    extern M2C_UNK g3DSpriteVtable;
    extern void *gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;

    u8 a;
    u8 b;
    M2C_UNK z = 0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &g3DSpriteVtable;

    M2C_FIELD(arg0, u8 *, 0x48) =
        (M2C_FIELD(arg0, u8 *, 0x48) & ~1) | 1;

    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;

    M2C_FIELD(arg0, s32 *, 0x40) &= ~0x1FF;
    M2C_FIELD(arg0, s32 *, 0x40) &= 0xFFFC01FF;
    M2C_FIELD(arg0, s32 *, 0x40) &= ~0x03FC0000;

    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C) = 0xC00;

    M2C_FIELD(arg0, s32 *, 0x40) =
        (M2C_FIELD(arg0, s32 *, 0x40) & ~0xFC000000)
        | 0x40000000;

    a = ((s32)gCur3DSpriteEngine == g3DSpriteEngineMain)
        ? 1 : 0;

    b = (a == 1) ? 0 : 1;

    M2C_FIELD(arg0, u8 *, 0x48) =
        (M2C_FIELD(arg0, u8 *, 0x48) & ~0xE)
        | ((u32)(b << 0x1D) >> 0x1C);

    M2C_FIELD(arg0, u8 *, 0x49) = 0x11;
    M2C_FIELD(arg0, s32 *, 0x44) = z;

    M2C_FIELD(arg0, u8 *, 0x48) =
        (u8)(M2C_FIELD(arg0, u8 *, 0x48) & ~0x30)
        & ~0xC0;

    M2C_FIELD(arg0, u8 *, 0x4D) = z;
    M2C_FIELD(arg0, u8 *, 0x4C) = z;

    M2C_FIELD(arg0, u8 *, 0x4E) = 8;
    M2C_FIELD(arg0, u8 *, 0x4F) = 8;

    M2C_FIELD(arg0, s16 *, 0x38) = z;
    M2C_FIELD(arg0, s16 *, 0x3A) = z;
}

/* Advance a 3D sprite actor's fade and slide animations, then draw it.  The
 * second argument is forwarded to the fade step (which ignores it). */
M2C_UNK UpdateAndDraw3DSpriteActor(void *sprite, s32 fadeArg) {
    void UpdateSpriteFade(void *, s32);
    M2C_UNK UpdateSpriteSlide(M2C_UNK);
    void DrawSpriteActor(void *);
    UpdateSpriteFade(sprite, fadeArg);
    UpdateSpriteSlide((M2C_UNK)sprite);
    DrawSpriteActor(sprite);
}

void func_02089310(void) {
    M2C_UNK UpdateAndDraw3DSpriteActor();
    UpdateAndDraw3DSpriteActor();
}


/* Create a plain 3D sprite owned by `owner` and initialise it to the base actor
 * state, unless it could not be created. */
void Create3DSprite(M2C_UNK owner)
{
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK g3DSpriteClass;
    void *sprite;

    sprite = CreateSpriteFromClass(&g3DSpriteClass, owner);

    if (sprite == NULL) {
        return;
    }

    Init3DSprite(sprite);
}


/* Resets a new frame-border sprite to the plain 3D sprite actor state and gives
 * it this class's vtable: it starts with no rectangle, an animated highlight and
 * its position still to be synced. */
void *InitFrameBorderSprite(void *sprite) {
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gFrameBorderSpriteVtable;
    Init3DSpriteActor();
    M2C_FIELD(sprite, M2C_UNK **, 0) = &gFrameBorderSpriteVtable;
    M2C_FIELD(sprite, s8 *, FRAME_ACTOR_HIGHLIGHT) = 1;
    M2C_FIELD(sprite, s8 *, FRAME_ACTOR_PULSE) = 1;
    M2C_FIELD(sprite, s8 *, FRAME_ACTOR_SYNC) = 1;
    M2C_FIELD(sprite, s32 *, 0x40) &= ~0x1FF;
    M2C_FIELD(sprite, s32 *, 0x40) &= 0xFFFC01FF;
    M2C_FIELD(sprite, s16 *, FRAME_ACTOR_X) = 0;
    M2C_FIELD(sprite, s16 *, FRAME_ACTOR_Y) = 0;
    M2C_FIELD(sprite, s16 *, FRAME_ACTOR_WIDTH) = 0;
    M2C_FIELD(sprite, s16 *, FRAME_ACTOR_HEIGHT) = 0;
    M2C_FIELD(sprite, s16 *, FRAME_ACTOR_COLOR) = 0;
    return sprite;
}

/* Give frame-border sprite `sprite` the pattern at `vramOffset`: its tile row,
 * OBJ palette row `palette` and highlight colour `color`; load the pattern's
 * graphics and reset the sprite's first tile and priority. */
void SetFrameBorderSpritePattern(void *sprite, u32 vramOffset, s32 palette, s32 color) {
    M2C_UNK Load3DSpritePattern(u32, s32, s32, M2C_UNK);
    *(volatile u16 *)((s8 *)sprite + SPRITE_ACTOR_TILE_ROW) = (u16)(vramOffset >> 5);
    {
        s32 word = *(volatile s32 *)((s8 *)sprite + SPRITE_ACTOR_SPLIT);
        u32 paletteBits = (u32)palette << 0x18;
        paletteBits >>= 6;
        word &= ~SPRITE_ACTOR_PALETTE_MASK;
        word |= (s32)paletteBits;
        *(volatile s32 *)((s8 *)sprite + SPRITE_ACTOR_SPLIT) = word;
    }
    *(volatile s16 *)((s8 *)sprite + FRAME_ACTOR_COLOR) = (s16)color;
    Load3DSpritePattern(vramOffset, palette, color, 2);
    *(volatile s16 *)((s8 *)sprite + SPRITE_ACTOR_TILE) = 0;
    *(volatile s8 *)((s8 *)sprite + SPRITE_ACTOR_PRIORITY) = 0;
}

/* Load a frame-border sprite's pattern, tinted with the UI's frame-border
 * colour (the sprite's VRAM offset and palette are given by the caller). */
M2C_UNK LoadFrameBorderSpritePattern(M2C_UNK sprite, M2C_UNK vramOffset, M2C_UNK palette) {
    s32 GetUiColor(M2C_UNK);
    SetFrameBorderSpritePattern((void *)sprite, vramOffset, palette, GetUiColor(UI_COLOR_FRAME_BORDER));
}

/* Give frame-border sprite `sprite` the standard frame-border pattern: the UI's
 * fixed texture offset and palette, tinted with the frame-border colour. */
void LoadFrameBorderSpriteDefaultPattern(void *sprite) {
    M2C_UNK LoadFrameBorderSpritePattern(M2C_UNK, M2C_UNK, M2C_UNK);
    LoadFrameBorderSpritePattern(sprite, FRAME_BORDER_TILE, FRAME_BORDER_PALETTE);
}

/* Snap a frame-border sprite actor's drawn rectangle to its target: copy the
 * actor's target position (SPRITE_ACTOR_X/Y) and the width and height packed into
 * SPRITE_ACTOR_SPLIT (bits 0..8 and 9..17) into the frame rectangle fields
 * (FRAME_ACTOR_X/Y/WIDTH/HEIGHT). */
void Sync3DSpriteToTarget(void *sprite) {
    *(volatile s16 *)((volatile s8 *)sprite + FRAME_ACTOR_X) = *(volatile s16 *)((volatile s8 *)sprite + SPRITE_ACTOR_X);
    *(volatile s16 *)((volatile s8 *)sprite + FRAME_ACTOR_Y) = *(volatile s16 *)((volatile s8 *)sprite + SPRITE_ACTOR_Y);
    *(volatile s16 *)((volatile s8 *)sprite + FRAME_ACTOR_WIDTH) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)sprite + SPRITE_ACTOR_SPLIT))[0] << 0x17) >> 0x17);
    *(volatile s16 *)((volatile s8 *)sprite + FRAME_ACTOR_HEIGHT) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)sprite + SPRITE_ACTOR_SPLIT))[0] << 0xE) >> 0x17);
}

#pragma push
#pragma opt_strength_reduction off
void func_0208946c(void *p) {
extern void *gCur3DSpriteEngine;extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain;
s32 IsTextLayerActive(void);
void DrawFrameBorderPulse(s16,s16,s16,s16,u16,s32);
void DrawFrameBorder(s16,s16,s16,s16,u16,s32,s32);
s32 d,a,b,screen;s32 attr;s32 *engineA,*engineB;u16 tile;void *old;s32 i,priority,drawMode;u32 target,delta;void *cur;
if(Is3DSpriteHidden(p))return;
if(M2C_FIELD(p,u8 *,0x5a)){Sync3DSpriteToTarget(p);M2C_FIELD(p,u8 *,0x5a)=0;}
attr=(u16)((u32)(M2C_FIELD(p,s32 *,0x40)<<6)>>24);
a=0x3ff&((u32)M2C_FIELD(p,u16 *,0x3e)>>((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30));
tile=(u16)(a+(M2C_FIELD(p,u16 *,0x3c)+((u32)(attr<<28)>>16)));
priority=M2C_FIELD(p,u8 *,0x49);
{s32 diff,current,magnitude,next;next=M2C_FIELD(p,s16 *,0x34);current=M2C_FIELD(p,s16 *,0x5e);diff=next-current;magnitude=diff<0?-diff:diff;if(magnitude>1)next=current+(diff>>1);M2C_FIELD(p,s16 *,0x5e)=next;}
{s32 diff,current,magnitude,next;next=M2C_FIELD(p,s16 *,0x36);current=M2C_FIELD(p,s16 *,0x60);diff=next-current;magnitude=diff<0?-diff:diff;if(magnitude>1)next=current+(diff>>1);M2C_FIELD(p,s16 *,0x60)=next;}
target=(u32)(M2C_FIELD(p,s32 *,0x40)<<23)>>23;b=M2C_FIELD(p,s16 *,0x62);delta=target-b;
if(delta>1)target=b+(delta>>1);M2C_FIELD(p,s16 *,0x62)=target;
target=(u32)(M2C_FIELD(p,s32 *,0x40)<<14)>>23;b=M2C_FIELD(p,s16 *,0x64);delta=target-b;
if(delta>1)target=b+(delta>>1);M2C_FIELD(p,s16 *,0x64)=target;
if(!M2C_FIELD(p,u8 *,0x58))tile=(u16)(tile+(0x3ff&(32>>((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))));
if(IsTextLayerActive())return;
old=gCur3DSpriteEngine;engineA=&g3DSpriteEngineSub;engineB=&g3DSpriteEngineMain;drawMode=2;
for(i=0;i<2;i++){
cur=(void *)(i==0?*engineB:*engineA);gCur3DSpriteEngine=cur;
screen=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if(screen==0&&cur!=(void *)*engineB)continue;
if(attr==1&&gCur3DSpriteEngine!=(void *)g3DSpriteEngineSub)continue;
if(attr==3&&gCur3DSpriteEngine!=old)continue;
if(M2C_FIELD(p,u8 *,0x58)&&M2C_FIELD(p,u8 *,0x59))
DrawFrameBorderPulse((s16)(M2C_FIELD(p,s16 *,0x5e)+M2C_FIELD(p,s16 *,0x38)),(s16)(M2C_FIELD(p,s16 *,0x60)+M2C_FIELD(p,s16 *,0x3a)),M2C_FIELD(p,s16 *,0x62),M2C_FIELD(p,s16 *,0x64),tile,priority);
else DrawFrameBorder((s16)(M2C_FIELD(p,s16 *,0x5e)+M2C_FIELD(p,s16 *,0x38)),(s16)(M2C_FIELD(p,s16 *,0x60)+M2C_FIELD(p,s16 *,0x3a)),M2C_FIELD(p,s16 *,0x62),M2C_FIELD(p,s16 *,0x64),tile,priority,drawMode);
}
gCur3DSpriteEngine=old;
}
#pragma pop
void func_020896e4(void) {
    void func_0208946c();
    func_0208946c();
}

/* Create a frame-border sprite of `owner`'s and initialise it, if it was created. */
void CreateFrameBorderSprite(M2C_UNK owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gFrameBorderSpriteClass;
    void *sprite = CreateSpriteFromClass(&gFrameBorderSpriteClass, owner);
    if (sprite == NULL) return;
    InitFrameBorderSprite(sprite);
}

/* Find the UI's frame-border sprite object, or NULL when none was created. */
void *FindFrameBorderSprite(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gFrameBorderSpriteClass;
    return FindObjectByClass(&gFrameBorderSpriteClass);
}

/* Hide the frame-border sprite, if the screen currently has one. */
void HideFrameBorderSprite(void) {
 M2C_UNK Hide3DSprite();
 if (FindFrameBorderSprite() == 0) return;
 Hide3DSprite();
}

/* Show the frame-border sprite, if the screen currently has one. */
void ShowFrameBorderSprite(void) {
 M2C_UNK Show3DSprite();
 if (FindFrameBorderSprite() == 0) return;
 Show3DSprite();
}

/* Draw callback of a text-layer panel proxy sprite: the sprite keeps a pointer
 * to the panel it stands for at +0x34, and drawing the proxy redraws that panel
 * on the current engine, passing the engine's sprite count.  Returns that count. */
u8 DrawTextLayerPanelProxy(void *proxy) {
    M2C_UNK func_0208af98(s32, u8);
    extern void *gCur3DSpriteEngine;
    func_0208af98(M2C_FIELD(proxy, s32 *, 0x34), M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49));
    return M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49);
}

/* Create the proxy sprite that redraws `panel` (a text layer) whenever the proxy
 * is drawn; draw layer 6 puts it behind the screen's other UI sprites. */
void CreateTextLayerPanelProxy(s32 panel) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTextLayerPanelProxyClass;

    M2C_FIELD(CreateSpriteFromClass(&gTextLayerPanelProxyClass, 6), s32 *, TEXT_LAYER_PANEL_PROXY_PANEL) = panel;
}

/* Delete every text-layer panel proxy sprite (the objects CreateTextLayerPanelProxy
 * makes). */
void DeleteTextLayerPanelProxies(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gTextLayerPanelProxyClass;
    DeleteSpriteObjectsOfClass(&gTextLayerPanelProxyClass);
}

/* Draws the resting UI bar gradient: the gradient strip runs from UI colour 0xD
 * to UI colour 0xE (DrawUiGradientPulse is the highlighted variant). */
void DrawUiGradientStatic(void) {
    M2C_UNK DrawUiGradient(M2C_UNK, M2C_UNK, s32, s32);
    s32 GetUiColor(M2C_UNK);
    s32 startColor;

    startColor = GetUiColor(UI_GRADIENT_COLOR_START);
    DrawUiGradient(UI_GRADIENT_TILE, UI_GRADIENT_PALETTE, startColor, GetUiColor(UI_GRADIENT_COLOR_END));
}

/* Fills the UI gradient palette with a gradient from UI colour 0xD to a colour
 * that cycles between the highlight colours 0xF and 0x10 on a 32-frame triangle
 * wave, then uploads the changed sprite data. */
void DrawUiGradientPulse(void) {
    M2C_UNK Update3DSpriteVram();
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 GetUiColor(M2C_UNK);
    s32 BlendRgb555_32(s32, s32, u8, u8);
    M2C_UNK DrawUiGradient(M2C_UNK, M2C_UNK, s32, s32);
    extern volatile s32 gVBlankCount;
    s32 highlightColor;
    s32 blendedColor;
    u8 pulse;

    pulse = (u32)(gVBlankCount & 0x1F) < UI_GRADIENT_PULSE_HALF ?
        EaseInterpolate(0, 0, UI_GRADIENT_PULSE_FRAMES, gVBlankCount & 0x1F, UI_GRADIENT_PULSE_HALF) :
        EaseInterpolate(0, UI_GRADIENT_PULSE_FRAMES, 0, (gVBlankCount & 0x1F) - UI_GRADIENT_PULSE_HALF, UI_GRADIENT_PULSE_HALF);
    highlightColor = GetUiColor(0xF);
    blendedColor = BlendRgb555_32(highlightColor, GetUiColor(0x10), pulse, (u8)(UI_GRADIENT_PULSE_FRAMES - pulse));
    DrawUiGradient(UI_GRADIENT_TILE, UI_GRADIENT_PALETTE, GetUiColor(0xD), blendedColor);
    Update3DSpriteVram();
}

/* Create the gradient-bar proxy sprite of text layer `panel` on the main engine
 * and keep the panel pointer the proxy's draw callbacks use. */
void CreateTextLayerGradientProxy(void *panel) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gTextLayerGradientProxyClass;

    M2C_FIELD(CreateSpriteFromClass(&gTextLayerGradientProxyClass, 1), s32 *, 0x34) = (s32) panel;
}

/* Delete every live gradient-bar proxy sprite of the text layers. */
void DeleteTextLayerGradientProxies(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gTextLayerGradientProxyClass;
    DeleteSpriteObjectsOfClass(&gTextLayerGradientProxyClass);
}

/* Initializes a 3D text layer with no child sprites or text buffers. */
void *InitTextLayer(void *layer) {
    Init3DSpriteActor(layer);
    M2C_FIELD(layer, M2C_UNK **, 0) = &gTextLayerVtable;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_ANIMATION_MASK;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_POSITION_MASK;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_CHOICE_MASK;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_ICON_COUNT;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_LINE_COUNT;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_REFRESH_TIMER;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_SAVED_MODE;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~0x800;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_WINDOW_MASK;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~0x1000;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_NESTED;
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) &= ~TEXT_LAYER_PANEL_LINK_SOUND;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_LEFT_ICON) = 0;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_RIGHT_ICON) = 0;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_STRING) = 0;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_BUFFER_A) = 0;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_BUFFER_B) = 0;
    M2C_FIELD(layer, s32 *, TEXT_LAYER_TEXT_DATA) = 0;
    return layer;
}

/* Destructor for a text layer: switch it to the class vtable, free its text and
 * its icon child sprites, then return the layer without freeing it. */
M2C_UNK **TextLayer_Destroy(M2C_UNK **layer) {
    M2C_UNK TextLayer_FreeChildSprites(M2C_UNK **);
    extern M2C_UNK gTextLayerVtable;
    *layer = &gTextLayerVtable;
    TextLayer_FreeText();
    TextLayer_FreeChildSprites(layer);
    return layer;
}

/* Destroy a text layer: switch it to the class vtable, release its text and its
 * icon child sprites, then free the layer itself. */
M2C_UNK **TextLayer_Free(M2C_UNK **layer) {
 M2C_UNK TextLayer_FreeChildSprites(M2C_UNK **);
 M2C_UNK MemFree(M2C_UNK **);
 *layer=&gTextLayerVtable;
 TextLayer_FreeText();TextLayer_FreeChildSprites(layer);MemFree(layer);return layer;
}

void RenderTextLayer(M2C_UNK, M2C_UNK, u32, s32);

/* Renders a localized message into a text layer using the default message panel
 * tileset (tile 0x4B80 of the panel texture). */
void RenderTextLayerMessageDefault(M2C_UNK layer, M2C_UNK style, M2C_UNK textId) {
    s32 GetLocalizedText(M2C_UNK);
    RenderTextLayer(layer, style, 0x4B80, GetLocalizedText(textId));
}

/* Show a message on a text layer: draw the localized string for message id
 * `textId`, passing the layer's draw mode and base tile straight through. */
void RenderTextLayerMessage(void *layer, s32 mode, s32 tile, u32 textId) {
    RenderTextLayer(layer, mode, tile, GetLocalizedText(textId));
}

void RenderTextLayer(M2C_UNK entity, M2C_UNK arg1, u32 arg2, s32 arg3) {
    extern void *gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 g3DSpriteEngineSub;
    u8 SetPanelChoice(M2C_UNK, s32);
    M2C_UNK GetUiColor(s32);
    M2C_UNK DrawUiGradient(M2C_UNK, M2C_UNK, s32, s32);
    void LoadScenePanelGraphics(void);
    void LoadScenePanelPalette(s32);
    void TextLayer_ReplaceText(M2C_UNK, M2C_UNK);

    s32 low3;
    u32 spriteIndex;
    void *savedBank;
    s32 i;
    void *bank;
    u32 mode;
    s32 tmp;
    M2C_UNK t1;
    M2C_UNK t2;

    savedBank = gCur3DSpriteEngine;
    spriteIndex = arg2 >> 5;
    i = 0;
    tmp = -99;
    low3 = (s32)arg1 & 7;
    do {
        if (i == 0) {
            bank = (void *)g3DSpriteEngineMain;
        } else {
            bank = (void *)g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = bank;
        mode = (u32)(M2C_FIELD(entity, u8 *, 0x48) << 28) >> 29;
        if ((mode != 0 || bank == (void *)g3DSpriteEngineMain) &&
            (mode != 1 || bank == (void *)g3DSpriteEngineSub) &&
            (mode != 3 || bank == savedBank)) {
            M2C_FIELD(entity, u16 *, 0x3E) = spriteIndex;
            M2C_FIELD(entity, s32 *, 0x58) = (M2C_FIELD(entity, s32 *, 0x58) & ~7) | low3;
            M2C_FIELD(entity, s32 *, 0x58) = (M2C_FIELD(entity, s32 *, 0x58) & ~0xE0000000) | (low3 << 29);
            M2C_FIELD(entity, s8 *, 0x49) = tmp;
            SetPanelChoice(entity, tmp + 0x62);
            t1 = GetUiColor(0xD);
            t2 = GetUiColor(0xE);
            DrawUiGradient(0x1400, 1, t1, t2);
            LoadScenePanelGraphics();
            LoadScenePanelPalette(0x12);
            TextLayer_ReplaceText(entity, arg3);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
}

/* Replace a text layer's accumulated text: drop the old string, then append the
 * new one. */
void TextLayer_ReplaceText(M2C_UNK layer, M2C_UNK text) {
    M2C_UNK TextLayer_AppendText(M2C_UNK, M2C_UNK);
    M2C_UNK TextLayer_FreeText();
    TextLayer_FreeText();
    TextLayer_AppendText(layer, text);
}

#pragma opt_common_subs off
/* Append a string to a text layer's accumulated text (reallocating it), give the
 * layer its two 8-byte render buffers, and hand the whole text to the renderer. */
M2C_UNK TextLayer_AppendText(M2C_UNK arg0,M2C_UNK arg1) {
 s32 StringLength(s32);
 s32 HeapAllocBlock(s32);
 void StringCopy(s32,s32);
 void StringAppend(s32,s32);
 void TextLayer_SetText(void *,s32);
 register s32 text; register s32 len;
 if(!arg1)return;
 if(!M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING)) {
 M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING)=HeapAllocBlock(StringLength(arg1)+1);
 StringCopy(M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING),arg1);
 } else {
 len=StringLength(M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING));
 text=HeapAllocBlock(len+StringLength(arg1)+1);
 StringCopy(text,M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING));StringAppend(text,arg1);
 TextLayer_FreeText(arg0);M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING)=text;
 }
 M2C_FIELD(arg0,s32 *,TEXT_LAYER_BUFFER_A)=HeapAllocBlock(8);
 M2C_FIELD(arg0,s32 *,TEXT_LAYER_BUFFER_B)=HeapAllocBlock(8);
 TextLayer_SetText((void *)arg0,M2C_FIELD(arg0,s32 *,TEXT_LAYER_STRING));
}
#pragma opt_common_subs reset
/* Free a text layer's owned accumulated text and its two render buffers and
 * forget the text it currently draws. */
M2C_UNK TextLayer_FreeText(void *layer) {
    s32 HeapFreeBlock(s32);
    s32 block;

    block = M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_STRING);
    if (block != 0) {
        HeapFreeBlock(block);
    }
    block = 0;
    M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_STRING) = block;
    block = M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_BUFFER_A);
    if (block != 0) {
        HeapFreeBlock(block);
    }
    block = 0;
    M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_BUFFER_A) = block;
    block = M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_BUFFER_B);
    if (block != 0) {
        HeapFreeBlock(block);
    }
    block = 0;
    M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_BUFFER_B) = block;
    M2C_FIELD(layer, volatile s32 *, TEXT_LAYER_TEXT_DATA) = block;
    return block;
}

#pragma peephole off
/* Point the text layer at `text` and pick its panel kind: text holding a line
 * break becomes a dismissable text panel, otherwise the panel's saved mode is
 * restored over the kind. */
void TextLayer_SetText(void *layer, s32 text) {
    s32 Text_FindLineBreakEnd(s32);
    u32 panelState;

    M2C_FIELD(layer, s32 *, TEXT_LAYER_TEXT_DATA) = text;
    if (Text_FindLineBreakEnd(text) != 0) {
        M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) = (u32)((M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) & ~TEXT_LAYER_PANEL_KIND_MASK) | TEXT_LAYER_PANEL_KIND_TEXT);
        return;
    }
    panelState = M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE);
    M2C_FIELD(layer, u32 *, TEXT_LAYER_PANEL_STATE) = (u32)((panelState & ~TEXT_LAYER_PANEL_KIND_MASK) | ((panelState >> TEXT_LAYER_PANEL_SAVED_MODE_SHIFT) & TEXT_LAYER_PANEL_KIND_MASK));
}
#pragma peephole reset
/* Advance a text panel to its next page: if the layer's text still holds a line
 * break, show the rest and restart the panel's animation, otherwise delete the
 * panel. */
void TextLayer_AdvancePageOrClose(void *layer) {
 s32 Text_FindLineBreakEnd(s32);
 M2C_UNK GotoSpriteAnimationLabel(void *,s32);
 M2C_UNK DeleteSpriteObject(void *);
 s32 nextPage=Text_FindLineBreakEnd(M2C_FIELD(layer,s32 *,TEXT_LAYER_TEXT_DATA));
 if(nextPage){TextLayer_SetText(layer,nextPage);GotoSpriteAnimationLabel(layer,0);return;}
 DeleteSpriteObject(layer);
}

/* Count a text panel's refresh timer (TEXT_LAYER_PANEL_REFRESH_TIMER) down one
 * frame; return 1 while the panel still has frames left, 0 once it has run out. */
s32 UpdateTextLayerRefreshTimer(void *layer) {
    s32 state;
    u32 refreshTimer;

    state = M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE);
    refreshTimer = (u32)(state * 8) >> 0x19;
    if (refreshTimer <= 1U) {
        return 0;
    }
    M2C_FIELD(layer, s32 *, TEXT_LAYER_PANEL_STATE) = (s32)((state & ~TEXT_LAYER_PANEL_REFRESH_TIMER) | ((u32)((refreshTimer - 1) << 0x19) >> 3));
    return 1;
}

/* Release a text layer's two icon child sprites, then delete any objects of the
 * icon sprite classes they were created from. */
M2C_UNK TextLayer_FreeChildSprites(M2C_UNK **layer) {
    M2C_UNK DeleteSpriteObject(void *);
    void *sprite;

    sprite = M2C_FIELD(layer, void **, TEXT_LAYER_LEFT_ICON); if (sprite) { DeleteSpriteObject(sprite); M2C_FIELD(layer, s32 *, TEXT_LAYER_LEFT_ICON) = 0; }
    sprite = M2C_FIELD(layer, void **, TEXT_LAYER_RIGHT_ICON); if (sprite) { DeleteSpriteObject(sprite); M2C_FIELD(layer, s32 *, TEXT_LAYER_RIGHT_ICON) = 0; }
    DeleteTextLayerPanelProxies(); DeleteTextLayerGradientProxies();
}

