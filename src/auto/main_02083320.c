/* 14 functions from 0x02083320 to 0x02084304 (main), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine;
extern u8 gSpriteDesc16x32[];
extern u8 gGlyphAdvance[];
void AddSprite(u16,u16,u16,void *,s32);

typedef struct { u16 unused:13; u16 mode:2; u16 last:1; } DrawControl;
typedef struct { u8 pad[15]; u8 low:4; u8 high:4; } Unk0208349c;
typedef struct { u8 pad[0x44]; s8 values[16]; } Unk0208352c;

/* A sprite-text label: up to 16 font glyphs drawn as 3D sprites, optionally
 * revealed by per-glyph offsets, framed by a left and a right end-cap sprite. */
typedef struct SpriteText {
    u8  filler_00[0x34];
    s8  glyphs[16];    /* +0x34 glyph index per character, -1 (255) = blank */
    s8  reveal[16];    /* +0x44 per-glyph reveal/fade offset */
    u16 timer;         /* +0x54 animation frame counter */
    u16 x;             /* +0x56 position */
    u16 y;             /* +0x58 position */
    u16 length;        /* +0x5A number of glyphs */
    u16 tileBase;      /* +0x5C first tile index of the font */
    u16 palette;       /* +0x5E palette row */
    u16 attr;          /* +0x60 attribute OR-ed into every sprite */
    u8  active;        /* +0x62 nonzero while the label is shown */
    s8  priority;      /* +0x63 draw priority of the end caps */
} SpriteText;

u8 IsMapInLinkCategory(s32 arg0,s32 arg1) {
 s32 IsLinkSessionActive();
 if(IsLinkSessionActive()==0) return 1;
 return (u8)((s32)(u16)(arg0-225)/50)==(u8)(arg1-8);
}

void ResetTextLabelSlots(void) {
 extern s8 gTextLabelSlotState;
 s32 i,j; s8 *p,*a,*b;
 a=&gTextLabelSlotState; i=0; b=a;
 do { j=0; *a=0;
 do { p=b+j; M2C_FIELD(p,s8 *,169)=0; ++j; M2C_FIELD(p,s8 *,13)=0; }while(j<12);
 ++i; ++a; b+=12;
 }while(i<13);
}

/* Clear the generated text state of the label slots the link player setup does
 * not keep: every slot except 0, 2, 7 and 8 loses its used flag (the one byte
 * per slot at the table base) and its 12 glyph entries in the two per-slot
 * tables at +0x0D and +0xA9. */
void ResetTextLabelSlotsPartial(void) {
 extern s8 gTextLabelSlotState;
 s32 slot,j; s8 *used,*row,*entry;
 used=&gTextLabelSlotState; slot=0; row=used;
 do { switch(slot) {
 case 1: case 3: case 4: case 5: case 6: case 9: case 10: case 11: case 12:
 j=0; *used=0;
 do { entry=row+j; M2C_FIELD(entry,s8 *,169)=0; ++j; M2C_FIELD(entry,s8 *,13)=0; }while(j<12);
 break; default: break;
 }
 ++slot; ++used; row+=12;
 }while(slot<13);
}

void ClearTextChars(void) {
 extern void *data_02101fd4;
 s32 i;
 M2C_FIELD(data_02101fd4,u8 *,17)&=~1;
 for(i=0;i<14;i++) M2C_FIELD(data_02101fd4,u8 *,i)=0;
}

void SetTextMode(s32 arg0) {
 extern void *data_02101fd4;
 ((Unk0208349c *)data_02101fd4)->high=(u8)arg0;
}

/* Reset the two text states: the first loses its text, its mode and its flag
 * bits; the second loses its text and gets its cursor fields (16, 16) and its
 * last byte cleared. */
void ResetTextState(void) {
 extern void *data_02101fd4;
 s32 charIndex;
 M2C_FIELD(data_02101fd4,u8 *,17)=0;
 SetTextMode(0); ClearTextChars();
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,15)=0;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,16)=16;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,17)=16;
 M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,18)=0;
 for(charIndex=0;charIndex<15;charIndex++) M2C_FIELD(M2C_FIELD(&data_02101fd4,void **,4),u8 *,charIndex)=0;
}

#pragma push
#pragma opt_strength_reduction off
/* Prepare a sprite-text label's reveal animation: reset the frame counter; an
 * inactive label just gets its idle animation, an active one gets a per-glyph
 * reveal start spread evenly over the label's length by averaging two eased
 * ramps. */
void InitSpriteTextReveal(SpriteText *text) {
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 i, count, delay;

    i = 0;
    text->timer = 0;
    if (text->active == 0) {
        SetSpriteAnimation(text, 0);
        return;
    }
    count = text->length;
    if (count <= 0) return;
    do {
        delay = EaseInterpolate(0, 0, 48, i, (s32)M2C_FIELD(text, volatile u16 *, 0x5a) - 1);
        delay = (delay + EaseInterpolate(4, 0, 48, i, count - 1)) >> 1;
        text->reveal[i] = (s8)delay;
        count = text->length;
        ++i;
    } while (i < count);
}
#pragma opt_strength_reduction off
void func_020835d4(void *obj) {
 extern s16 gSinCosTable[];
 s32 Divide(s32,s32);s32 EaseInterpolate(s32,s32,s32,s32,s32);void SetSpriteQuad(s32,s16,s16,s16,s16);void Sprite_ResumeAnimation(void *);
 s32 i,e,d,a,b,s; u16 y,x; s32 c,offset,pos,glyph;
 x=M2C_FIELD(obj,u16 *,0x56);y=M2C_FIELD(obj,u16 *,0x58);
 c=gSinCosTable[1]<<4;s=*(volatile s16 *)gSinCosTable;
 M2C_FIELD(obj,u16 *,0x54)++;
 a=Divide(c,256);b=Divide((-s)<<4,64);d=Divide(s<<4,256);e=Divide(c,64);
 SetSpriteQuad(31,(s16)a,(s16)b,(s16)d,(s16)e);
 for(i=0;i<M2C_FIELD(obj,u16 *,0x5a);i++) {
 if(M2C_FIELD(obj,u16 *,0x54)<M2C_FIELD((u8 *)obj+i,u8 *,0x44))break;
 offset=M2C_FIELD(obj,u16 *,0x54)-M2C_FIELD((u8 *)obj+i,u8 *,0x44);
 if(offset>8)offset=0;else offset=EaseInterpolate(4,256,0,offset,8);
 pos=x+offset;if(pos>=256)break;
 AddSprite((u16)((pos&511)|0x3e00),(u16)((y&255)|256),(u16)(M2C_FIELD(obj,u16 *,0x60)|(((M2C_FIELD(obj,u16 *,0x5c)+(M2C_FIELD((u8 *)obj+i,s8 *,0x34)<<3))>>((DrawControl *)M2C_FIELD(gCur3DSpriteEngine,void **,0))->mode &1023)+((M2C_FIELD(obj,u16 *,0x5e)&15)<<12))),gSpriteDesc16x32,M2C_FIELD(obj,s8 *,0x63));
 glyph=M2C_FIELD((u8 *)obj+i,s8 *,0x34);
 if(glyph==255)x+=14;else x+=gGlyphAdvance[glyph]-2;
 }
 if(M2C_FIELD(obj,u16 *,0x54)==56) {M2C_FIELD(obj,u16 *,0x54)=0;Sprite_ResumeAnimation(obj);}
}
void func_020837b4(void *obj) {
extern s16 gSinCosTable[]; extern u8 gSpriteDesc64x64[];
s32 Divide(s32,s32);s32 EaseInterpolate(s32,s32,s32,s32,s32);void SetSpriteQuad(s32,s16,s16,s16,s16);void Sprite_ResumeAnimation(void *);
s32 s; s16 c; s32 scale2,scale1,a,b,d,e,i,offset,pos,glyph; u16 y; s32 x;
x=M2C_FIELD(obj,u16 *,0x56);y=M2C_FIELD(obj,u16 *,0x58);
M2C_FIELD(obj,u16 *,0x54)++;
scale1=((EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16)<0?-EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16):EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16))>=2?EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16):(EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16)>2?2:(EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16) < -2 ? -2:EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16))));
c=gSinCosTable[1];s=gSinCosTable[0];
scale2=((EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16)<0?-EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16):EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16))>=2?EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16):(EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16)>2?2:(EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16) < -2 ? -2:EaseInterpolate(0,64,256,M2C_FIELD(obj,u16 *,0x54),16))));

a=Divide(c<<4,256);b=Divide((-s)<<4,scale2);d=Divide(s<<4,256);e=Divide(c,scale1);
SetSpriteQuad(31,(s16)a,(s16)b,(s16)d,(s16)e);
offset=EaseInterpolate(4,128,0,M2C_FIELD(obj,u16 *,0x54),16);
pos=x-42-offset;
if(pos > -64){
AddSprite((u16)(pos&511),(u16)((y-16)&255),(u16)(M2C_FIELD(obj,u16 *,0x60)|(((M2C_FIELD(obj,u16 *,0x5c)+224)>>((DrawControl *)M2C_FIELD(gCur3DSpriteEngine,void **,0))->mode &1023)+(((M2C_FIELD(obj,u16 *,0x5e)+1)&15)<<12))),gSpriteDesc64x64,M2C_FIELD(obj,s8 *,0x63)+1);
}
for(i=0;i<M2C_FIELD(obj,u16 *,0x5a);i++) {
AddSprite((u16)((x&511)|0x3e00),(u16)((y&255)|256),(u16)(M2C_FIELD(obj,u16 *,0x60)|(((M2C_FIELD(obj,u16 *,0x5c)+(M2C_FIELD((u8 *)obj+i,s8 *,0x34)<<3))>>((DrawControl *)M2C_FIELD(gCur3DSpriteEngine,void **,0))->mode &1023)+((M2C_FIELD(obj,u16 *,0x5e)&15)<<12))),gSpriteDesc16x32,M2C_FIELD(obj,s8 *,0x63));
glyph=M2C_FIELD((u8 *)obj+i,s8 *,0x34);if(glyph==255)x=(u16)(x+14);else x=(u16)(x+(gGlyphAdvance[glyph]-2));
}
pos=x-19+offset;
if(pos<256){
AddSprite((u16)(pos&511),(u16)((y-16)&255),(u16)(M2C_FIELD(obj,u16 *,0x60)|(((M2C_FIELD(obj,u16 *,0x5c)+288)>>((DrawControl *)M2C_FIELD(gCur3DSpriteEngine,void **,0))->mode &1023)+(((M2C_FIELD(obj,u16 *,0x5e)+1)&15)<<12))),gSpriteDesc64x64,M2C_FIELD(obj,s8 *,0x63)+1);
}
if(M2C_FIELD(obj,u16 *,0x54)==16){M2C_FIELD(obj,u16 *,0x54)=0;Sprite_ResumeAnimation(obj);}
}

#pragma opt_strength_reduction off
/* Draw a sprite-text label without animation: a left cap, one 16x32 sprite per
 * glyph, then a right cap, advancing x by each glyph's width. */
void DrawSpriteText(SpriteText *obj) {
    extern u8 gSpriteDesc64x64[];
    s32 i;
    s32 x = obj->x, y = obj->y;
    s32 top = (y - 16) & 255, glyph;

    AddSprite((u16)((x - 42) & 511), (u16)top,
        (u16)(obj->attr | (((obj->tileBase + 224) >> ((DrawControl *)M2C_FIELD(gCur3DSpriteEngine, void **, 0))->mode & 1023) + (((obj->palette + 1) & 15) << 12))),
        gSpriteDesc64x64, obj->priority + 1);
    for (i = 0; i < obj->length; i++) {
        AddSprite((u16)(x & 511), (u16)(y & 255),
            (u16)(obj->attr | (((obj->tileBase + (obj->glyphs[i] << 3)) >> ((DrawControl *)M2C_FIELD(gCur3DSpriteEngine, void **, 0))->mode & 1023) + ((obj->palette & 15) << 12))),
            gSpriteDesc16x32, obj->priority);
        glyph = obj->glyphs[i];
        if (glyph == 255) x = (u16)(x + 14); else x = (u16)(x + (gGlyphAdvance[glyph] - 2));
    }
    x -= 19;
    AddSprite((u16)(x & 511), (u16)top,
        (u16)(obj->attr | (((obj->tileBase + 288) >> ((DrawControl *)M2C_FIELD(gCur3DSpriteEngine, void **, 0))->mode & 1023) + (((obj->palette + 1) & 15) << 12))),
        gSpriteDesc64x64, obj->priority + 1);
}

#pragma opt_strength_reduction off
void func_02083e50(SpriteText *text) {
    extern s16 gSinCosTable[];
    s32 Divide(s32, s32);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    void Sprite_ResumeAnimation(void *);
    s32 scaleX, scaleY;
    s32 xx, xy, yx, yy;
    s32 i, glyph;
    u16 x = text->x;
    u16 y = text->y;
    s32 sinValue, cosValue, scaledCos;
    u16 elapsed;
    const s16 *sincos;

    text->timer++;
    scaleX = (EaseInterpolate(0,64,256,text->timer,16) < 0
              ? -EaseInterpolate(0,64,256,text->timer,16)
              : EaseInterpolate(0,64,256,text->timer,16)) >= 2
        ? EaseInterpolate(0,64,256,text->timer,16)
        : (EaseInterpolate(0,64,256,text->timer,16) > 2 ? 2
           : (EaseInterpolate(0,64,256,text->timer,16) < -2 ? -2
              : EaseInterpolate(0,64,256,text->timer,16)));
    elapsed = text->timer;
    sincos = gSinCosTable;
    cosValue = sincos[1];
    sinValue = sincos[0];
    scaleY = (EaseInterpolate(0,64,256,elapsed,16) < 0
              ? -EaseInterpolate(0,64,256,text->timer,16)
              : EaseInterpolate(0,64,256,text->timer,16)) >= 2
        ? EaseInterpolate(0,64,256,text->timer,16)
        : (EaseInterpolate(0,64,256,text->timer,16) > 2 ? 2
           : (EaseInterpolate(0,64,256,text->timer,16) < -2 ? -2
              : EaseInterpolate(0,64,256,text->timer,16)));

    scaledCos = cosValue << 4;
    xx = Divide(scaledCos, 256);
    xy = Divide(-sinValue << 4, scaleY);
    yx = Divide(sinValue << 4, 256);
    yy = Divide(scaledCos, scaleX);
    SetSpriteQuad(31, (s16)xx, (s16)xy, (s16)yx, (s16)yy);
    EaseInterpolate(4, 128, 0, text->timer, 16);
    for (i = 0; i < text->length; i++) {
        AddSprite((u16)((x & 511) | 0x3e00), (u16)((y & 255) | 256),
                  (u16)(text->attr | ((((text->tileBase + (text->glyphs[i] << 3))
                      >> ((DrawControl *)M2C_FIELD(gCur3DSpriteEngine, void **, 0))->mode) & 1023)
                      + ((text->palette & 15) << 12))),
                  gSpriteDesc16x32, text->priority);
        glyph = text->glyphs[i];
        if (glyph == 255) x = (u16)(x + 14);
        else x = (u16)(x + (gGlyphAdvance[glyph] - 2));
    }
    if (text->timer == 16) {
        text->timer = 0;
        Sprite_ResumeAnimation(text);
    }
}
#pragma opt_strength_reduction reset
/* Draw the glyph run of a sprite-text label from its own x position (no end caps):
 * one 16x32 sprite per glyph, advancing x by each glyph's width. */
void DrawSpriteTextGlyphs(void *a){
s32 i; u16 x,y; void *p;
x=M2C_FIELD(a,u16 *,0x56);y=M2C_FIELD(a,u16 *,0x58);
for(i=0;i<M2C_FIELD(a,u16 *,0x5a);i++){
p=(char*)a+(u32)i;
AddSprite((u16)(x&511),(u16)(y&255),(u16)(M2C_FIELD(a,u16 *,0x60)|(((M2C_FIELD(a,u16 *,0x5c)+(M2C_FIELD(p,s8 *,0x34)<<3))>>(((**(DrawControl ***)&gCur3DSpriteEngine)->mode)))&1023)+((M2C_FIELD(a,u16 *,0x5e)&15)<<12)),gSpriteDesc16x32,M2C_FIELD(a,s8 *,0x63));
if(M2C_FIELD(p,s8 *,0x34)==255)x+=14;
else x+=gGlyphAdvance[M2C_FIELD(p,s8 *,0x34)]-2;
}}

void func_020842b4(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02101ff8;
    extern M2C_UNK data_02102040;
    DeleteSpriteObjectsOfClass(&data_02101ff8);
    DeleteSpriteObjectsOfClass(&data_02102040);
}

void func_020842d4(void) {
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_020842b4();
    gCur3DSpriteEngine = temp_r4;
}

