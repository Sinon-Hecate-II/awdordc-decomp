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
extern M2C_UNK data_02102638;

#pragma opt_common_subs off
void Hide3DSpriteSlide(void *p) {
    M2C_UNK Hide3DSprite(void *);
    if (!M2C_FIELD(p, u8 *, 0x4F)) {
        M2C_FIELD(p, s16 *, 0x34) = M2C_FIELD(p, s16 *, 0x54);
        M2C_FIELD(p, s16 *, 0x36) = M2C_FIELD(p, s16 *, 0x56);
        M2C_FIELD(p, s8 *, 0x4D) = 0;
        M2C_FIELD(p, u8 *, 0x48) = (u8)(M2C_FIELD(p, u8 *, 0x48) & ~0xC0);
        Hide3DSprite(p);
        return;
    }
    if ((((u32)M2C_FIELD(p, u8 *, 0x48) << 24) >> 30) == 3) {
        return;
    }
    M2C_FIELD(p, s8 *, 0x4C) = 0;
    M2C_FIELD(p, s8 *, 0x4D) = 0;
    M2C_FIELD(p, u8 *, 0x48) = (u8)((M2C_FIELD(p, u8 *, 0x48) & ~0xC0) | 0xC0);
}
#pragma opt_common_subs reset
u8 Is3DSpriteVisible(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1F) >> 0x1F) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02089080(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1F) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_0208909c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x1A) >> 0x1E) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020890b8(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x48) << 0x18) >> 0x1E) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 Is3DSpriteAnimating(void *arg0) {
 u8 result;
 if (func_0208909c(arg0) != 0) return 1;
 if (func_020890b8(arg0) != 0) result = 1;
 else result = 0;
 return result;
}

#pragma scheduling on
M2C_UNK Init3DSpriteActor(void *arg0) {
extern M2C_UNK data_02102610;
extern void *data_027e01d8;
extern s32 data_027e00c8;
u8 a;
u8 b;
M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02102610;
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
void func_020891fc(void *arg0)
{
    extern M2C_UNK data_02102610;
    extern void *gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;

    u8 a;
    u8 b;
    M2C_UNK z = 0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02102610;

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

M2C_UNK func_020892f0(void *arg0, s32 arg1) {
 void UpdateSpriteFade(void *,s32);
 M2C_UNK UpdateSpriteSlide(M2C_UNK);
 void func_020887ec(void *);
 UpdateSpriteFade(arg0,arg1);UpdateSpriteSlide((M2C_UNK)arg0);func_020887ec(arg0);
}

void func_02089310(void) {
    M2C_UNK func_020892f0();
    func_020892f0();
}


void func_0208931c(M2C_UNK arg0)
{
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102658;
    void *ptr;

    ptr = CreateSpriteFromClass(&data_02102658, arg0);

    if (ptr == NULL) {
        return;
    }

    func_020891fc(ptr);
}


void *func_02089340(void *arg0) {
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK data_021025fc;
    Init3DSpriteActor();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021025fc;
    M2C_FIELD(arg0, s8 *, 0x58) = 1;
    M2C_FIELD(arg0, s8 *, 0x59) = 1;
    M2C_FIELD(arg0, s8 *, 0x5A) = 1;
    M2C_FIELD(arg0, s32 *, 0x40) &= ~0x1FF;
    M2C_FIELD(arg0, s32 *, 0x40) &= 0xFFFC01FF;
    M2C_FIELD(arg0, s16 *, 0x5E) = 0;
    M2C_FIELD(arg0, s16 *, 0x60) = 0;
    M2C_FIELD(arg0, s16 *, 0x62) = 0;
    M2C_FIELD(arg0, s16 *, 0x64) = 0;
    M2C_FIELD(arg0, s16 *, 0x5C) = 0;
    return arg0;
}

void func_020893a8(void *arg0, u32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK Load3DSpritePattern(u32, s32, s32, M2C_UNK);
    *(volatile u16 *)((s8 *)arg0 + 0x3E) = (u16)(arg1 >> 5);
    {
        s32 t = *(volatile s32 *)((s8 *)arg0 + 0x40);
        u32 shifted = (u32)arg2 << 0x18;
        shifted >>= 6;
        t &= ~0x03FC0000;
        t |= (s32)shifted;
        *(volatile s32 *)((s8 *)arg0 + 0x40) = t;
    }
    *(volatile s16 *)((s8 *)arg0 + 0x5C) = (s16)arg3;
    Load3DSpritePattern(arg1, arg2, arg3, 2);
    *(volatile s16 *)((s8 *)arg0 + 0x3C) = 0;
    *(volatile s8 *)((s8 *)arg0 + 0x49) = 0;
}

M2C_UNK func_020893f4(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 GetUiColor(M2C_UNK);
    func_020893a8((void *)arg0, arg1, arg2, GetUiColor(9));
}

void func_02089424(M2C_UNK arg0) {
    M2C_UNK func_020893f4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020893f4(arg0, 0x1000, 1);
}

void Sync3DSpriteToTarget(void *arg0) {
    *(volatile s16 *)((volatile s8 *)arg0 + 0x5E) = *(volatile s16 *)((volatile s8 *)arg0 + 0x34);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x60) = *(volatile s16 *)((volatile s8 *)arg0 + 0x36);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x62) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)arg0 + 0x40))[0] << 0x17) >> 0x17);
    *(volatile s16 *)((volatile s8 *)arg0 + 0x64) = (s16) ((u32)(((volatile s32 *)((volatile s8 *)arg0 + 0x40))[0] << 0xE) >> 0x17);
}

#pragma push
#pragma opt_strength_reduction off
void func_0208946c(void *p) {
extern void *gCur3DSpriteEngine;extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain;
s32 func_0208b5a8(void);
void DrawFrameBorderPulse(s16,s16,s16,s16,u16,s32);
void DrawFrameBorder(s16,s16,s16,s16,u16,s32,s32);
s32 d,a,b,screen;s32 attr;s32 *engineA,*engineB;u16 tile;void *old;s32 i,priority,drawMode;u32 target,delta;void *cur;
if(func_02089080(p))return;
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
if(func_0208b5a8())return;
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

void func_020896f0(M2C_UNK arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102678;
    void *ptr = CreateSpriteFromClass(&data_02102678, arg0);
    if (ptr == NULL) return;
    func_02089340(ptr);
}

s32 func_02089714(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02102678;
    return FindObjectByClass(&data_02102678);
}

void func_02089728(void) {
 M2C_UNK Hide3DSprite();
 if (func_02089714() == 0) return;
 Hide3DSprite();
}

void func_02089740(void) {
 M2C_UNK Show3DSprite();
 if (func_02089714() == 0) return;
 Show3DSprite();
}

u8 func_02089758(void *arg0) {
    M2C_UNK func_0208af98(s32, u8);
    extern void *gCur3DSpriteEngine;
    func_0208af98(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49));
    return M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x49);
}

void func_02089784(s32 arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102698;
    M2C_FIELD(CreateSpriteFromClass(&data_02102698, 6), s32 *, 0x34) = arg0;
}

void func_020897a4(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102698;
    DeleteSpriteObjectsOfClass(&data_02102698);
}

void func_020897b8(void) {
    M2C_UNK DrawUiGradient(M2C_UNK, M2C_UNK, s32, s32);
    s32 GetUiColor(M2C_UNK);
    s32 temp_r4;

    temp_r4 = GetUiColor(0xD);
    DrawUiGradient(0x1400, 1, temp_r4, GetUiColor(0xE));
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

void func_0208989c(s32 arg0) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102738;
    M2C_FIELD(CreateSpriteFromClass(&data_02102738, 1), s32 *, 0x34) = arg0;
}

void func_020898bc(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02102738;
    DeleteSpriteObjectsOfClass(&data_02102738);
}

void *func_020898d0(void *arg0) {
 Init3DSpriteActor(arg0);
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_02102638;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x38;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x300;
 M2C_FIELD(arg0,u32 *,0x58)&=~0xC0;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x38000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x3C0000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x1FC00000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0xE0000000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x800;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x400;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x1000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x2000;
 M2C_FIELD(arg0,u32 *,0x58)&=~0x4000;
 M2C_FIELD(arg0,s32 *,0x5C)=0;
 M2C_FIELD(arg0,s32 *,0x60)=0;
 M2C_FIELD(arg0,s32 *,0x64)=0;
 M2C_FIELD(arg0,s32 *,0x68)=0;
 M2C_FIELD(arg0,s32 *,0x6C)=0;
 M2C_FIELD(arg0,s32 *,0x70)=0;
 return arg0;
}

M2C_UNK **func_02089944(M2C_UNK **arg0) {
    M2C_UNK func_02089cec(M2C_UNK **);
    extern M2C_UNK data_02102638;
    *arg0 = &data_02102638;
    TextLayer_FreeText();
    func_02089cec(arg0);
    return arg0;
}

M2C_UNK **func_0208996c(M2C_UNK **arg0) {
 M2C_UNK func_02089cec(M2C_UNK **);
 M2C_UNK MemFree(M2C_UNK **);
 *arg0=&data_02102638;
 TextLayer_FreeText();func_02089cec(arg0);MemFree(arg0);return arg0;
}

void func_0208999c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 GetLocalizedText(M2C_UNK);
    M2C_UNK RenderTextLayer(M2C_UNK, M2C_UNK, s32, s32);
    RenderTextLayer(arg0, arg1, 0x4B80, GetLocalizedText(arg2));
}

void RenderTextLayerMessage(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    RenderTextLayer(arg0, arg1, arg2, GetLocalizedText(arg3));
}

M2C_UNK RenderTextLayer(M2C_UNK entity, M2C_UNK arg1, s32 arg2, s32 arg3) {
    extern void *gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 g3DSpriteEngineSub;
    u8 func_0208ae88(M2C_UNK, s32);
    M2C_UNK GetUiColor(s32);
    M2C_UNK DrawUiGradient(M2C_UNK, M2C_UNK, s32, s32);
    void func_02091c98(void);
    void LoadScenePanelPalette(s32);
    void func_02089b18(M2C_UNK, M2C_UNK);

    void *savedBank;
    void *bank;
    u32 mode;
    u16 spriteIndex;
    s32 i;
    s32 low3;
    s32 tmp;
    M2C_UNK t1;
    M2C_UNK t2;

    savedBank = gCur3DSpriteEngine;
    spriteIndex = (u16)(arg2 >> 5);
    i = 0;
    low3 = (s32)arg1 & 7;
    tmp = ~0x62;
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
            M2C_FIELD(entity, u8 *, 0x49) = (u8)tmp;
            func_0208ae88(entity, tmp + 0x62);
            t1 = GetUiColor(0xD);
            t2 = GetUiColor(0xE);
            DrawUiGradient(0x1400, 1, t1, t2);
            func_02091c98();
            LoadScenePanelPalette(0x12);
            func_02089b18(entity, arg3);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
    return 0;
}

void func_02089b18(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK TextLayer_AppendText(M2C_UNK, M2C_UNK);
    M2C_UNK TextLayer_FreeText();
    TextLayer_FreeText();
    TextLayer_AppendText(arg0, arg1);
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
M2C_UNK TextLayer_FreeText(void *arg0) {
    s32 HeapFreeBlock(s32);
    s32 p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x64);
    if (p != 0) {
        HeapFreeBlock(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x64) = p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x68);
    if (p != 0) {
        HeapFreeBlock(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x68) = p;
    p = *(volatile s32 *)((s8 *)arg0 + 0x6C);
    if (p != 0) {
        HeapFreeBlock(p);
    }
    p = 0;
    *(volatile s32 *)((s8 *)arg0 + 0x6C) = p;
    *(volatile s32 *)((s8 *)arg0 + 0x70) = p;
    return p;
}

#pragma peephole off
void TextLayer_SetText(void *arg0, s32 arg1) {
    s32 func_0209c658(s32);
    u32 temp_r1;

    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    if (func_0209c658(arg1) != 0) {
        M2C_FIELD(arg0, u32 *, 0x58) = (u32) ((M2C_FIELD(arg0, u32 *, 0x58) & ~7) | 1);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, u32 *, 0x58);
    M2C_FIELD(arg0, u32 *, 0x58) = (u32) ((temp_r1 & ~7) | ((temp_r1 >> 0x1D) & 7));
}
#pragma peephole reset
void func_02089c80(void *arg0) {
 s32 func_0209c658(s32);
 M2C_UNK SetSpriteAnimation(void *,s32);
 M2C_UNK DeleteSpriteObject(void *);
 s32 p=func_0209c658(M2C_FIELD(arg0,s32 *,0x70));
 if(p){TextLayer_SetText(arg0,p);SetSpriteAnimation(arg0,0);return;}
 DeleteSpriteObject(arg0);
}

s32 func_02089cb8(void *arg0) {
    s32 temp_r2;
    u32 temp_r1;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_r1 = (u32) (temp_r2 * 8) >> 0x19;
    if (temp_r1 <= 1U) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r2 & ~0x1FC00000) | ((u32) ((temp_r1 - 1) << 0x19) >> 3));
    return 1;
}

M2C_UNK func_02089cec(M2C_UNK **arg0) {
 M2C_UNK DeleteSpriteObject(void *);
 void *p;
 p=M2C_FIELD(arg0,void **,0x5C); if(p){DeleteSpriteObject(p);M2C_FIELD(arg0,s32 *,0x5C)=0;}
 p=M2C_FIELD(arg0,void **,0x60); if(p){DeleteSpriteObject(p);M2C_FIELD(arg0,s32 *,0x60)=0;}
 func_020897a4();func_020898bc();
}

