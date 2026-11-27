/* 18 functions from 0x0217416C to 0x02174F68 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_keypad.h"


#pragma scheduling on
void Ov001_OpenKeypad(void) {
    extern u8 gKeypadLayout[];
    extern u8 data_ov001_0218f5dc[], data_ov001_0218f5e0[];
    extern u16 data_ov001_0218f628[];
    extern void *gOv001Keypad;
    void *Ov001_Alloc(s32, s32);
    void *Ov001_CreateSpriteFromLayout(s32, s32);
    void *Ov001_CreateSprite(s32, s32, s32);
    void Ov001_SetSpriteEntryFlags(void *, s32, s32, s32);
    void Ov001_SetSpritePalette(void *, s32, s32);
    void *CreatePooledTextPanel(s32, s32, s32, s32, s32 *, s32);
    void DrawPanelText(void *, s32, s32, s32, s32, s32, s32, u16 *);
    void *Ov001_AllocSpriteBlock(s32, s32, s32);
    void *Ov001_AddTask(s32, void (*)(s32), s32, s32);
    void Ov001_KeypadSlideStep1(s32);
    void Ov001_PositionKeypadStep(s32, s32);
    void *sprite;
    s32 i, label, j;
    s32 extra;
    const u8 *extraIds;
    const u8 *ids;
    struct {
        s32 firstLabel;
        u16 text[2];
        s32 layout;
        u16 x;
        u16 y, width, height;
    } work;

    work.x = M2C_FIELD(gKeypadLayout, u16 *, 0x20);
    work.y = M2C_FIELD(gKeypadLayout, u16 *, 0x22);
    work.width = 28;
    work.height = 20;
    gOv001Keypad = Ov001_Alloc(0x6c, 4);
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = 31;
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_LAST_KEY) = 0;
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CAN_DELETE) = 1;
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_DIGITS_ON) = 1;
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CAN_NEXT) = 1;
    for (i = 0; i < KEYPAD_KEY_COUNT; i++) {
        (((void **)gOv001Keypad + i)[4]) = Ov001_CreateSpriteFromLayout(0, 0x36);
        sprite = (((void **)gOv001Keypad + i)[4]);
        *(u32 *)sprite = (*(u32 *)sprite & 0xc1fffcff) | 0x200;
        sprite = (((void **)gOv001Keypad + i)[4]);
        M2C_FIELD(sprite, u16 *, 4) = (M2C_FIELD(sprite, u16 *, 4) & ~0xc00) | 0xc00;
    }
    ids = data_ov001_0218f5dc;
    for (i = 0; i < 2; i++) {
        (((void **)gOv001Keypad + i)[14]) = Ov001_CreateSpriteFromLayout(0, *ids++);
        sprite = (((void **)gOv001Keypad + i)[14]);
        *(u32 *)sprite = (*(u32 *)sprite & 0xc1fffcff) | 0x200;
        sprite = (((void **)gOv001Keypad + i)[14]);
        M2C_FIELD(sprite, u16 *, 4) = (M2C_FIELD(sprite, u16 *, 4) & ~0xc00) | 0xc00;
    }
    extraIds = data_ov001_0218f5e0;
    for (extra = 0; extra < 2; extra++) {
        (((void **)gOv001Keypad + extra)[16]) = Ov001_CreateSprite(0, *extraIds++, 1);
        Ov001_SetSpriteEntryFlags((((void **)gOv001Keypad + extra)[16]), -1, 0x200, 0);
        Ov001_SetSpritePalette((((void **)gOv001Keypad + extra)[16]), -1, 3);
    }
    work.firstLabel = 0;
    work.text[1] = 0;
    for (i = 0; i < 4; i++) {
        void *panel = CreatePooledTextPanel(0, 12, 4, 0, &work.layout, 0);
        j = 0;
        ((void **)gOv001Keypad)[i] = panel;
        label = work.firstLabel;
        work.x = 0;
        for (; j < 3; j++, label++) {
            s32 character = data_ov001_0218f628[label];
            s32 height = work.height;
            s32 x = work.x;
            work.text[0] = character;
            DrawPanelText(((void **)gOv001Keypad)[i], x, work.y, work.width, height, 2, 0x480, work.text);
            work.x += 32;
        }
        sprite = Ov001_AllocSpriteBlock(0, work.layout, 0);
        work.firstLabel = label;
        (((void **)gOv001Keypad + i)[18]) = sprite;
    }
    M2C_FIELD(gOv001Keypad, void **, 0x58) = Ov001_CreateSprite(0, 0x44, 1);
    Ov001_SetSpriteEntryFlags(M2C_FIELD(gOv001Keypad, void **, 0x58), -1, 0x200, 0);
    Ov001_SetSpritePalette(M2C_FIELD(gOv001Keypad, void **, 0x58), -1, 2);
    M2C_FIELD(gOv001Keypad, void **, 0x5c) = Ov001_AddTask(0, Ov001_KeypadSlideStep1, 0, 0x78);
    Ov001_PositionKeypadStep(0, 192);
}
#pragma scheduling reset
/* Start closing the keypad: remove the sprite that marks the selected key and
 * retarget the highlight's slide task to the close animation's next step. */
void Ov001_StartKeypadClose(void) {
    extern void *gOv001Keypad;
    void Ov001_KeypadCloseStep5(void);
    Ov001_DestroySprite(M2C_FIELD(gOv001Keypad, s32 *, KEYPAD_CURSOR_SPRITE));
    Ov001_SetSlideStep(M2C_FIELD(gOv001Keypad, s32 *, KEYPAD_SLIDE_TASK), Ov001_KeypadCloseStep5);
}

u8 Ov001_GetKeypadCode(void) {
    extern void *gOv001Keypad;
    return M2C_FIELD(gOv001Keypad, u8 *, 0x60);
}

void Ov001_SetKeypadDeleteEnabled(s8 arg0) {
    extern void *gOv001Keypad;
    M2C_FIELD(gOv001Keypad, s8 *, 0x66) = arg0;
}

void Ov001_SetKeypadDigitsEnabled(s8 arg0) {
    extern void *gOv001Keypad;
    M2C_FIELD(gOv001Keypad, s8 *, 0x67) = arg0;
}

void Ov001_SetKeypadNextEnabled(s8 arg0){extern void *gOv001Keypad;M2C_FIELD(gOv001Keypad,s8*,0x68)=arg0;}

/* Whether the ov001 on-screen keypad is up (its object has been created and not
 * yet freed). */
s32 Ov001_IsKeypadOpen(void) {
    extern void *gOv001Keypad;
    if (gOv001Keypad != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
/* Keypad slide-in step for the first number row: while its leftmost key is still
 * right of where the row comes to rest, move the whole row along with it; once it
 * has arrived, snap the row into place, park the second row just off the right
 * edge and queue that row's step. */
void Ov001_KeypadSlideStep1(s32 task){
extern void *gOv001Keypad;
void Ov001_KeypadSlideStep2(s32);
u32 sprite; s32 keyX; u32 keyY; s32 pos[2];
sprite=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,KEYPAD_KEY_SPRITE(0)),u32 *,0);
keyY=sprite&0x1ff0000;
keyX=(sprite&255)-12;
((volatile s32 *)pos)[1]=keyY>>16;
((volatile s32 *)pos)[0]=keyX;
if(pos[0]>KPAD_ROW_REST_X0){Ov001_PositionKeypadStep(0,pos[0]);return;}
Ov001_PositionKeypadStep(0,KPAD_ROW_REST_X0);
Ov001_PositionKeypadStep(1,KPAD_ROW_HIDDEN_X);
Ov001_SetSlideStep(task,Ov001_KeypadSlideStep2);
}
#pragma opt_propagation reset
/* Keypad slide-in step for the second number row: while its leftmost key is
 * still right of where the row comes to rest, move the whole row along with it;
 * once it has arrived, snap the row into place, park the third row just off the
 * right edge and queue that row's step. */
void Ov001_KeypadSlideStep2(s32 task){
extern void *gOv001Keypad;
void Ov001_KeypadSlideStep3(s32);
u32 v; s32 x; s32 y; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(gOv001Keypad,void**,KEYPAD_KEY_SPRITE(KEYPAD_KEYS_PER_ROW)),u32*,0);
y=v&OV001_SPRITE_POS_Y_MASK;
x=(v&OV001_SPRITE_POS_X_MASK)-12;
y=(u32)y>>OV001_SPRITE_POS_Y_SHIFT;
((volatile s32 *)pos)[1]=y;
((volatile s32 *)pos)[0]=x;
if(pos[0]>KPAD_ROW_REST_X1){Ov001_PositionKeypadStep(1,x);return;}
Ov001_PositionKeypadStep(1,KPAD_ROW_REST_X1);
Ov001_PositionKeypadStep(2,KPAD_ROW_HIDDEN_X);
Ov001_SetSlideStep(task,Ov001_KeypadSlideStep3);
}

#pragma opt_propagation off
/* Keypad slide-in step for the third number row: while its leftmost key is still
 * right of where the row comes to rest, move the whole row along with it; once it
 * has arrived, snap the row into place, park the next row just off the right edge
 * and queue that row's step. */
void Ov001_KeypadSlideStep3(s32 task){
extern void *gOv001Keypad;
void Ov001_KeypadSlideStep4(s32);
u32 sprite; s32 keyX; u32 keyY; s32 pos[2];
sprite=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,KEYPAD_KEY_SPRITE(6)),u32 *,0);
keyY=sprite&0x1ff0000;
keyX=(sprite&255)-12;
((volatile s32 *)pos)[1]=keyY>>16;
((volatile s32 *)pos)[0]=keyX;
if(pos[0]>KPAD_ROW_REST_X2){Ov001_PositionKeypadStep(2,pos[0]);return;}
Ov001_PositionKeypadStep(2,KPAD_ROW_REST_X2);
Ov001_PositionKeypadStep(3,KPAD_ROW_HIDDEN_X);
Ov001_SetSlideStep(task,Ov001_KeypadSlideStep4);
}
#pragma opt_propagation off
/* Keypad slide step 3: read the row sprite at +0x34's packed position and, once
 * its x has passed 145, snap rows 3 and 4 to their final x and hand over to the
 * last slide step. */
void Ov001_KeypadSlideStep4(s32 task){
extern void *gOv001Keypad;
void Ov001_KeypadSlideStep5(s32);
u32 packed; s32 x; u32 y; s32 pos[2];
packed=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,52),u32 *,0);
y=packed&0x1ff0000;
x=(packed&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>145){Ov001_PositionKeypadStep(3,pos[0]);return;}
Ov001_PositionKeypadStep(3,145);
Ov001_PositionKeypadStep(4,192);
Ov001_SetSlideStep(task,Ov001_KeypadSlideStep5);
}
#pragma opt_propagation on
/* Keypad slide-in step for the bottom action row: while the row's first action
 * sprite is still right of its resting x, keep sliding the row; once it has
 * arrived, snap it into place, update the highlighted key and switch the task to
 * the keypad's input step. */
void Ov001_KeypadSlideStep5(s32 task) {
    extern void *gOv001Keypad;
    void Ov001_KeypadInputStep(void);
    s32 pos[2];

    Ov001_GetSpritePosition(M2C_FIELD(gOv001Keypad, s32 *, KEYPAD_ACTION_SPRITES), 0, &pos[1], &pos[0]);
    pos[0] -= 12;
    if (pos[0] > KPAD_ROW_REST_X4) {
        Ov001_PositionKeypadStep(4, pos[0]);
        return;
    }
    Ov001_PositionKeypadStep(4, KPAD_ROW_REST_X4);
    Ov001_UpdateKeypadCursor();
    Ov001_SetSlideStep(task, Ov001_KeypadInputStep);
}

void Ov001KeypadTouchHeld(void);
void Ov001KeypadTouchPressed(void);
void Ov001KeypadTouchReleased(void);
/* One frame of the keypad's input: run the stylus pressed/held/released
 * handlers, then the d-pad and button handler that edits the code. */
void Ov001_KeypadInputStep(void) {
    void Ov001_KeypadButtonInput(void);

    Ov001KeypadTouchPressed();
    Ov001KeypadTouchHeld();
    Ov001KeypadTouchReleased();
    Ov001_KeypadButtonInput();
}

/* Handles the start of a stylus touch on the numeric keypad: remembers the key the touch landed
 * on, buzzing instead when a key that cannot be used yet is touched (the digit keys while the
 * code is full, delete with nothing to remove, next with no free slot). */
void Ov001KeypadTouchPressed(void) {
    extern void *gOv001Keypad;
    s32 TouchRectPressed(void *);
    void BuildTouchRect(void *, void *, void *);
    void Ov001_PlaySound(s32);
    extern u8 gTouchScreenRect[];
    extern u8 gKeypadDigitRects[];
    extern u8 gKeypadLayout[];
    extern u8 gKeypadAuxRects[];
    extern u8 gKeypadAuxKeySize[];
    extern u8 gKeypadActionRects[];
    extern u8 gKeypadActionKeySize[];

    u8 touchRect[8];
    u8 *keyRect;
    s32 key;

    if (TouchRectPressed(gTouchScreenRect) == 0) {
        return;
    }
    M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) = -1;

    keyRect = gKeypadDigitRects;
    for (key = 0; key < KEYPAD_KEY_COUNT; key++) {
        BuildTouchRect(keyRect, gKeypadLayout, touchRect);
        if (TouchRectPressed(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_DIGITS_ON) == 0) {
                Ov001_PlaySound(9);
                return;
            }
            Ov001_PlaySound(0);
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_TOUCH_KEY) = (u8)key;
            return;
        }
        keyRect += 4;
    }

    keyRect = gKeypadAuxRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadAuxKeySize, touchRect);
        if (TouchRectPressed(touchRect) != 0) {
            if (key != 0) goto checkNext;
            if (M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CAN_DELETE) == 0) goto buzz;
checkNext:
            if (key != 1) goto accept;
            if (M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CAN_NEXT) != 0) goto accept;
buzz:
            Ov001_PlaySound(9);
            return;
accept:
            Ov001_PlaySound(0);
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_TOUCH_KEY) = (u8)(key + KEYPAD_DELETE);
            return;
        }
        keyRect += 4;
    }

    keyRect = gKeypadActionRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadActionKeySize, touchRect);
        if (TouchRectPressed(touchRect) != 0) {
            Ov001_PlaySound(0);
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_TOUCH_KEY) = (u8)(key + KEYPAD_CLEAR);
            return;
        }
        keyRect += 4;
    }
}

/* Stylus held on the numeric keypad: resets the produced key code and then, if the
 * touch has not moved off the key it started on, commits the key under the finger
 * (number keys, then delete/next, then clear/confirm) to KEYPAD_CODE. */
void Ov001KeypadTouchHeld(void) {
    extern void *gOv001Keypad;
    extern u8 gKeypadDigitRects[];
    extern u8 gKeypadLayout[];
    extern u8 gKeypadDigitChars[];
    extern u8 gKeypadAuxRects[];
    extern u8 gKeypadAuxKeySize[];
    extern u8 gKeypadAuxCodes[];
    extern u8 gKeypadActionRects[];
    extern u8 gKeypadActionKeySize[];
    extern u8 gKeypadActionCodes[];
    extern u8 gTouchScreenRect[];
    int TouchRectHeld(void *);
    void BuildTouchRect(void *, void *, void *);
    int Ov001_UpdateKeypadCursor(void);

    u8 touchRect[8];
    u8 *keyRect;
    s32 key;

    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = 0;
    if (TouchRectHeld(gTouchScreenRect) == 0) {
        return;
    }

    keyRect = gKeypadDigitRects;
    for (key = 0; key < KEYPAD_KEY_COUNT; key++) {
        BuildTouchRect(keyRect, gKeypadLayout, touchRect);
        if (TouchRectHeld(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key) {
                return;
            }
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = gKeypadDigitChars[key];
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_LAST_KEY) = (u8)key;
            Ov001_UpdateKeypadCursor();
            return;
        }
        keyRect += 4;
    }

    keyRect = gKeypadAuxRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadAuxKeySize, touchRect);
        if (TouchRectHeld(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key + KEYPAD_DELETE) {
                return;
            }
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = gKeypadAuxCodes[key];
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_LAST_KEY) = (u8)(key + KEYPAD_DELETE);
            Ov001_UpdateKeypadCursor();
            return;
        }
        keyRect += 4;
    }

    keyRect = gKeypadActionRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadActionKeySize, touchRect);
        if (TouchRectHeld(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key + KEYPAD_CLEAR) {
                return;
            }
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = gKeypadActionCodes[key];
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_LAST_KEY) = (u8)(key + KEYPAD_CLEAR);
            Ov001_UpdateKeypadCursor();
            return;
        }
        keyRect += 4;
    }
}

/* Handle the end of a stylus touch on the numeric keypad: whichever key was
 * released is committed only if it is still the key the touch started on.  The
 * delete key auto-repeats while the stylus is held and produces its code every
 * few releases once the repeat delay is reached; any other key just ends the
 * repeat and resets it. */
void Ov001KeypadTouchReleased(void) {
    extern void *gOv001Keypad;
    extern u8 gTouchScreenRect[];
    extern u8 gKeypadDigitRects[];
    extern u8 gKeypadLayout[];
    extern u8 gKeypadAuxRects[];
    extern u8 gKeypadAuxKeySize[];
    extern u8 gKeypadActionRects[];
    extern u8 gKeypadActionKeySize[];
    void BuildTouchRect(void *, void *, void *);
    s32 TouchRectReleased(void *);
    void Ov001_SetKeypadHighlight(s32);
    void Ov001_PlaySound(s32);

    s32 key;
    u8 touchRect[8];
    u8 *keyRect;

    if (TouchRectReleased(gTouchScreenRect) == 0) {
        goto fail;
    }

    keyRect = gKeypadDigitRects;
    for (key = 0; key < KEYPAD_KEY_COUNT; key++) {
        BuildTouchRect(keyRect, gKeypadLayout, touchRect);
        if (TouchRectReleased(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key) {
                goto fail;
            }
            Ov001_SetKeypadHighlight(key);
            goto tail;
        }
        keyRect += 4;
    }

    keyRect = gKeypadAuxRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadAuxKeySize, touchRect);
        if (TouchRectReleased(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key + KEYPAD_DELETE) {
                goto fail;
            }
            Ov001_SetKeypadHighlight(key + KEYPAD_DELETE);
            if (key != 0) {
                goto tail;
            }
            M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) =
                (u8)(M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) + 1);
            {
                u8 repeatCount = M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT);
                if (repeatCount < KEYPAD_REPEAT_DELAY) {
                    return;
                }
            }
            if (M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CAN_DELETE) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) = -1;
                return;
            } else {
                M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_CODE) = KEYPAD_CODE_DELETE;
                M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) =
                    (u8)(M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) - KEYPAD_REPEAT_STEP);
                return;
            }
        }
        keyRect += 4;
    }

    keyRect = gKeypadActionRects;
    for (key = 0; key < 2; key++) {
        BuildTouchRect(keyRect, gKeypadActionKeySize, touchRect);
        if (TouchRectReleased(touchRect) != 0) {
            if (M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_TOUCH_KEY) != key + KEYPAD_CLEAR) {
                goto fail;
            }
            Ov001_SetKeypadHighlight(key + KEYPAD_CLEAR);
            goto tail;
        }
        keyRect += 4;
    }

fail:
    Ov001_SetKeypadHighlight(-1);

tail:
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) = 0;
    return;
}

/* Move the keypad's highlight to `key`: give the newly highlighted key its pressed
 * frame, return the previously highlighted key to its normal frame, and remember
 * the new one (nothing happens when it is already highlighted). */
void Ov001_SetKeypadHighlight(s32 key) {
    extern void *gOv001Keypad;
    if (key == M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_HIGHLIGHTED)) return;
    Ov001_SetKeypadKeySelected(key, 1);
    Ov001_SetKeypadKeySelected(M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_HIGHLIGHTED), 0);
    M2C_FIELD(gOv001Keypad, s8 *, KEYPAD_HIGHLIGHTED) = key;
}

void Ov001_KeypadButtonInput(void) {
    extern void *gOv001Keypad;
    extern u8 gKeypadDigitChars[];
    extern u8 gKeypadAuxCodes[];
    extern u8 gKeypadActionCodes[];
    void Ov001KeypadMoveSelection(s32);
    s32 KeyPressed(s32);
    s32 KeyHeld(s32);
    s32 KeyReleased(s32);
    void Ov001_PlaySound(s32);
    register s8 k;

    if (KeyHeld(0x20)) {
        Ov001KeypadMoveSelection(0);
    }
    if (KeyHeld(0x40)) {
        Ov001KeypadMoveSelection(1);
    }
    if (KeyHeld(0x10)) {
        Ov001KeypadMoveSelection(2);
    }
    if (KeyHeld(0x80)) {
        Ov001KeypadMoveSelection(3);
    }
    if (KeyPressed(1)) {
        k = M2C_FIELD(gOv001Keypad, s8 *, 0x63);
        if (k < 10) {
            if (M2C_FIELD(gOv001Keypad, u8 *, 0x67) != 0) {
                M2C_FIELD(gOv001Keypad, u8 *, 0x60) = gKeypadDigitChars[k];
            } else {
                Ov001_PlaySound(9);
            }
            return;
        }
        if (k - 10 < 2) {
            if ((k - 10 == 0 && M2C_FIELD(gOv001Keypad, u8 *, 0x66) == 0) ||
                (k - 10 == 1 && M2C_FIELD(gOv001Keypad, u8 *, 0x68) == 0)) {
                Ov001_PlaySound(9);
                return;
            }
            M2C_FIELD(gOv001Keypad, u8 *, 0x60) = gKeypadAuxCodes[k - 10];
            return;
        }
        M2C_FIELD(gOv001Keypad, u8 *, 0x60) = gKeypadActionCodes[k - 12];
    }
    if (KeyHeld(2)) {
        if (M2C_FIELD(gOv001Keypad, u8 *, 0x66) == 0) {
            if (M2C_FIELD(gOv001Keypad, u8 *, 0x69) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(gOv001Keypad, u8 *, 0x69) = 1;
            }
        } else {
            M2C_FIELD(gOv001Keypad, u8 *, 0x60) = 0x10;
        }
    } else {
        if (KeyReleased(2)) {
            M2C_FIELD(gOv001Keypad, u8 *, 0x69) = 0;
        }
    }
}

