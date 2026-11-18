/* 18 functions from 0x0217416C to 0x02174F68 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_keypad.h"


#pragma scheduling on
void func_ov001_0217416c(void) {
    extern u8 gKeypadLayout[];
    extern u8 data_ov001_0218f5dc[], data_ov001_0218f5e0[];
    extern u16 data_ov001_0218f628[];
    extern void *gOv001Keypad;
    void *Ov001_Alloc(s32, s32);
    void *Ov001_CreateSpriteFromLayout(s32, s32);
    void *Ov001_CreateSprite(s32, s32, s32);
    void func_ov001_0218a260(void *, s32, s32, s32);
    void Ov001_SetSpritePalette(void *, s32, s32);
    void *CreatePooledTextPanel(s32, s32, s32, s32, s32 *, s32);
    void DrawPanelText(void *, s32, s32, s32, s32, s32, s32, u16 *);
    void *func_ov001_0218a070(s32, s32, s32);
    void *Ov001_AddTask(s32, void (*)(s32), s32, s32);
    void func_ov001_02174548(s32);
    void func_ov001_02174f68(s32, s32);
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
        func_ov001_0218a260((((void **)gOv001Keypad + extra)[16]), -1, 0x200, 0);
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
        sprite = func_ov001_0218a070(0, work.layout, 0);
        work.firstLabel = label;
        (((void **)gOv001Keypad + i)[18]) = sprite;
    }
    M2C_FIELD(gOv001Keypad, void **, 0x58) = Ov001_CreateSprite(0, 0x44, 1);
    func_ov001_0218a260(M2C_FIELD(gOv001Keypad, void **, 0x58), -1, 0x200, 0);
    Ov001_SetSpritePalette(M2C_FIELD(gOv001Keypad, void **, 0x58), -1, 2);
    M2C_FIELD(gOv001Keypad, void **, 0x5c) = Ov001_AddTask(0, func_ov001_02174548, 0, 0x78);
    func_ov001_02174f68(0, 192);
}
#pragma scheduling reset
void func_ov001_021744a8(void) {
    extern void *gOv001Keypad;
    void func_ov001_021753c8(void);
    Ov001_DestroySprite(M2C_FIELD(gOv001Keypad, s32 *, 0x58));
    Ov001_SetSlideStep(M2C_FIELD(gOv001Keypad, s32 *, 0x5c), func_ov001_021753c8);
}

u8 func_ov001_021744dc(void) {
    extern void *gOv001Keypad;
    return M2C_FIELD(gOv001Keypad, u8 *, 0x60);
}

void func_ov001_021744f0(s8 arg0) {
    extern void *gOv001Keypad;
    M2C_FIELD(gOv001Keypad, s8 *, 0x66) = arg0;
}

void func_ov001_02174504(s8 arg0) {
    extern void *gOv001Keypad;
    M2C_FIELD(gOv001Keypad, s8 *, 0x67) = arg0;
}

void func_ov001_02174518(s8 arg0){extern void *gOv001Keypad;M2C_FIELD(gOv001Keypad,s8*,0x68)=arg0;}

s32 func_ov001_0217452c(void) {
    extern void *gOv001Keypad;
    if (gOv001Keypad != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
void func_ov001_02174548(s32 arg0){
extern void *gOv001Keypad;
void func_ov001_021745cc(s32);
u32 v; s32 x; u32 y; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,16),u32 *,0);
y=v&0x1ff0000;x=(v&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>76){func_ov001_02174f68(0,pos[0]);return;}
func_ov001_02174f68(0,76);func_ov001_02174f68(1,192);
Ov001_SetSlideStep(arg0,func_ov001_021745cc);
}
#pragma opt_propagation reset
void func_ov001_021745cc(s32 arg0){
extern void *gOv001Keypad;
void func_ov001_02174650(s32);
u32 v; u32 hi; u32 lo; s32 x; s32 y; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(gOv001Keypad,void**,28),u32*,0);
y=v&0x1ff0000;
x=(v&255)-12;
y=(u32)y>>16;
((volatile s32 *)pos)[1]=y;
((volatile s32 *)pos)[0]=x;
if(pos[0]>99){func_ov001_02174f68(1,x);return;}
func_ov001_02174f68(1,99);
func_ov001_02174f68(2,192);
Ov001_SetSlideStep(arg0,func_ov001_02174650);
}

#pragma opt_propagation off
void func_ov001_02174650(s32 arg0){
extern void *gOv001Keypad;
void func_ov001_021746d4(s32);
u32 v; s32 x; u32 y; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,40),u32 *,0);
y=v&0x1ff0000;
x=(v&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>122){func_ov001_02174f68(2,pos[0]);return;}
func_ov001_02174f68(2,122);
func_ov001_02174f68(3,192);
Ov001_SetSlideStep(arg0,func_ov001_021746d4);
}
#pragma opt_propagation off
void func_ov001_021746d4(s32 arg0){
extern void *gOv001Keypad;
void func_ov001_02174758(s32);
u32 v; s32 x; u32 y; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(gOv001Keypad,void **,52),u32 *,0);
y=v&0x1ff0000;
x=(v&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>145){func_ov001_02174f68(3,pos[0]);return;}
func_ov001_02174f68(3,145);
func_ov001_02174f68(4,192);
Ov001_SetSlideStep(arg0,func_ov001_02174758);
}
#pragma opt_propagation on
void func_ov001_02174758(s32 arg0){extern void *gOv001Keypad;
void func_ov001_021747cc(void);
s32 pos[2];
Ov001_GetSpritePosition(M2C_FIELD(gOv001Keypad,s32*,0x40),0,&pos[1],&pos[0]);
pos[0]-=12;
if(pos[0]>170){func_ov001_02174f68(4,pos[0]);return;}
func_ov001_02174f68(4,170);Ov001KeypadCommitKey();Ov001_SetSlideStep(arg0,func_ov001_021747cc);
}

void Ov001KeypadTouchHeld(void);
void Ov001KeypadTouchPressed(void);
void Ov001KeypadTouchReleased(void);
void func_ov001_021747cc(void) {
          void func_ov001_02174dcc(void);
    Ov001KeypadTouchPressed();
    Ov001KeypadTouchHeld();
    Ov001KeypadTouchReleased();
    func_ov001_02174dcc();
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
    int Ov001KeypadCommitKey(void);

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
            Ov001KeypadCommitKey();
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
            Ov001KeypadCommitKey();
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
            Ov001KeypadCommitKey();
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
    void Ov001KeypadSetHighlight(s32);
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
            Ov001KeypadSetHighlight(key);
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
            Ov001KeypadSetHighlight(key + KEYPAD_DELETE);
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
            Ov001KeypadSetHighlight(key + KEYPAD_CLEAR);
            goto tail;
        }
        keyRect += 4;
    }

fail:
    Ov001KeypadSetHighlight(-1);

tail:
    M2C_FIELD(gOv001Keypad, u8 *, KEYPAD_REPEAT) = 0;
    return;
}

void Ov001KeypadSetHighlight(s32 arg0){extern void *gOv001Keypad;
if(arg0==M2C_FIELD(gOv001Keypad,s8*,0x62))return;
func_ov001_021751c8(arg0,1);
func_ov001_021751c8(M2C_FIELD(gOv001Keypad,s8*,0x62),0);
M2C_FIELD(gOv001Keypad,s8*,0x62)=arg0;
}

void func_ov001_02174dcc(void) {
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

