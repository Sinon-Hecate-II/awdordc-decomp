/* 8 functions from 0x020A94FC to 0x020A9A30 (main), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
#pragma opt_propagation off
void DrawTextSprite(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern u8 gSpriteDesc16x16[], gSpriteDesc8x8[];
    s16 GetTextSpriteGlyphX(void *, s32);
    s32 func_020a8c54(s32, s32, s32, s32);
    M2C_UNK SetTextSpriteValue(void *, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    s32 i;
    u8 *p = arg0;
    s16 y, x;
    s32 descriptor;
    switch (p[TEXT_SPRITE_TYPE]) {
    default: return;
    case 1: return;
    case 0: break;
    }
    if ((u32)(p[0x20] << 31) >> 31) {
        s32 saved = *(s32 *)(p + TEXT_SPRITE_VALUE);
        SetTextSpriteValue(p, 0);
        x = GetTextSpriteGlyphX(p, 0);
        AddSprite((u16)(x & 0x1ff), *(s16 *)(p + TEXT_SPRITE_X) & 0xff,
            (u16)((0x3ff & (((s32)((u32)(p[0x20]<<27)>>28)*p[0x16]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine << 17)>>30))) |
            ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
            (s32)gSpriteDesc16x16, (u32)(p[0x28]<<27)>>27);
        SetTextSpriteValue(p, saved);
        return;
    }
    if (p[0x29]) p[TEXT_SPRITE_COUNT] = p[0x29];
    for (i=0; i<p[TEXT_SPRITE_COUNT]; i++) {
        x=GetTextSpriteGlyphX(p,(u8)i);
        y=*(s16 *)(p + TEXT_SPRITE_X);
        if (func_020a8c54(x,y,p[0x14],p[0x15])) {
            descriptor = *(s32 *)(p + 0x24);
            if (descriptor) {
                AddSprite((u16)(x & 0x1ff), y & 0xff,
                    (u16)((0x3ff & ((s32)(u16)(p[0x16]*p[TEXT_SPRITE_DIGITS + (u8)i]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))) |
                    ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
                    descriptor, (u32)(p[0x28]<<27)>>27);
            } else {
                AddSprite((u16)(x & 0x1ff), y & 0xff,
                    (u16)((0x3ff & ((s32)(u16)(p[0x16]*p[TEXT_SPRITE_DIGITS + (u8)i]+*(u16 *)(p+0x12)) >> ((u32)(**(u16 **)gCur3DSpriteEngine <<17)>>30))) |
                    ((u32)(p[0x21]<<28)>>16) | ((u32)(((u32)(p[0x28]<<24)>>29)<<30)>>20)),
                    (s32)gSpriteDesc8x8, (u32)(p[0x28]<<27)>>27);
            }
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_020a9774(void *arg0, s16 arg1, s16 arg2, s8 arg3, s32 arg4) {
    M2C_UNK SetTextSpriteValue(void *, s32);
    void DrawTextSprite(void *);
    M2C_FIELD(arg0, s16 *, 6) = arg1;
    M2C_FIELD(arg0, s16 *, 8) = arg2;
    M2C_FIELD(arg0, s8 *, 0x21) = arg3;
    SetTextSpriteValue(arg0, arg4);
    DrawTextSprite(arg0);
}

M2C_UNK ScrollBar_PlaceThumb(void *arg0, s16 arg1, s16 arg2) {
    s32 x;
    s32 y;
    x = M2C_FIELD(arg0, s16 *, 0x14);
    if (arg1 <= x) {
        x = M2C_FIELD(arg0, s16 *, 0x12);
        if (arg1 >= x) x = arg1;
    }
    M2C_FIELD(arg0, s16 *, 8) = x;
    y = M2C_FIELD(arg0, s16 *, 0x18);
    if (arg2 <= y) {
        y = M2C_FIELD(arg0, s16 *, 0x16);
        if (arg2 >= y) y = arg2;
    }
    M2C_FIELD(arg0, s16 *, 0xA) = y;
    M2C_FIELD(arg0, s16 *, 0xC) = M2C_FIELD(arg0, s16 *, 8) - M2C_FIELD(arg0, s16 *, 0x12);
    M2C_FIELD(arg0, s16 *, 0xE) = M2C_FIELD(arg0, s16 *, 0xA) - M2C_FIELD(arg0, s16 *, 0x16);
}

/* Drag a scrollbar's thumb: when the thumb is enabled and the touch begins on
 * the thumb (its box is centred on the thumb position, touchWidth x touchHeight),
 * grab it; a release lets go; while grabbed, move the thumb under the stylus. */
void ScrollBar_HandleThumbTouch(void *thumb) {
    s32 IsPointInRect(s16, s16, s16, s16, s32, s32);
    M2C_UNK ScrollBar_PlaceThumb(void *, s16, s16);
    extern void *gTouchState;
    s16 touchX;
    s16 touchY;
    u8 touchWidth;
    u8 touchHeight;

    if (M2C_FIELD(thumb, u8 *, 5) == 0) {
        return;
    }
    touchX = M2C_FIELD(gTouchState, s16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, s16 *, TOUCH_CUR_Y);
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) != 0) {
        touchHeight = M2C_FIELD(thumb, u8 *, 0x11);
        touchWidth = M2C_FIELD(thumb, u8 *, 0x10);
        if (IsPointInRect(touchX, touchY, (s16) (M2C_FIELD(thumb, s16 *, 8) - ((s32) touchWidth >> 1)), (s16) (M2C_FIELD(thumb, s16 *, 0xA) - ((s32) touchHeight >> 1)), (s32) touchWidth, (s32) touchHeight) != 0) {
            M2C_FIELD(thumb, u8 *, 6) = 1U;
        }
    }
    if ((M2C_FIELD(thumb, u8 *, 6) != 0) && (M2C_FIELD(gTouchState, u8 *, TOUCH_RELEASED) != 0)) {
        M2C_FIELD(thumb, u8 *, 6) = 0U;
    }
    if (M2C_FIELD(thumb, u8 *, 6) == 0) {
        return;
    }
    ScrollBar_PlaceThumb(thumb, touchX, touchY);
}

/* Touch handling for a scrollbar: first lets the thumb itself be dragged (via
 * ScrollBar_HandleThumbTouch), then, when the thumb is not being dragged and a
 * touch starts inside the track, grabs the thumb, moves it under the stylus and
 * maps its offset back to the scroll value; releases the grab when the touch
 * ends. */
void ScrollBar_HandleTouch(void *bar) {
extern void *gTouchState;
s32 Divide(s32,s32);
s32 IsPointInRect(s16,s16,s16,s16,s32,s32);
void *thumb; s16 touchX,touchY; s32 valueRange,trackLength,offset;
if(M2C_FIELD(bar,u8 *,5)==0)return;
ScrollBar_HandleThumbTouch(M2C_FIELD(bar,void **,0x1c));
thumb=M2C_FIELD(bar,void **,0x1c);
if(M2C_FIELD(thumb,u8 *,6)!=0){offset=M2C_FIELD(thumb,s16 *,0xc); valueRange=M2C_FIELD(bar,s16 *,0x16)-M2C_FIELD(bar,s16 *,0x14); trackLength=(s16)(M2C_FIELD(thumb,s16 *,0x14)-M2C_FIELD(thumb,s16 *,0x12)); M2C_FIELD(bar,s16 *,0x12)=Divide(valueRange*offset,trackLength); return;}
touchX=M2C_FIELD(gTouchState,s16 *,TOUCH_CUR_X);touchY=M2C_FIELD(gTouchState,s16 *,TOUCH_CUR_Y);
if(M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED)!=0){
if(IsPointInRect(touchX,touchY,M2C_FIELD(bar,s16 *,8),M2C_FIELD(bar,s16 *,0xa),M2C_FIELD(bar,u8 *,0xc),M2C_FIELD(bar,u8 *,0xd))!=0)M2C_FIELD(bar,u8 *,6)=1;
}
if(M2C_FIELD(bar,u8 *,6)==0)return;
ScrollBar_PlaceThumb(M2C_FIELD(bar,void **,0x1c),touchX,touchY);
thumb=M2C_FIELD(bar,void **,0x1c);
offset=M2C_FIELD(thumb,s16 *,0xc); valueRange=M2C_FIELD(bar,s16 *,0x16)-M2C_FIELD(bar,s16 *,0x14); trackLength=(s16)(M2C_FIELD(thumb,s16 *,0x14)-M2C_FIELD(thumb,s16 *,0x12)); M2C_FIELD(bar,s16 *,0x12)=Divide(valueRange*offset,trackLength);
if(M2C_FIELD(gTouchState,u8 *,TOUCH_RELEASED)!=0)M2C_FIELD(bar,u8 *,6)=0;
}

void func_020a99f4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 5) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s8 *, 5) = 1;
}

void func_020a9a08(void *arg0) {
    M2C_FIELD(arg0, s8 *, 5) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), s8 *, 5) = 0;
}

void func_020a9a1c(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x14) = arg1;
    M2C_FIELD(arg0, s16 *, 0x16) = arg2;
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) (arg2 - arg1);
}

