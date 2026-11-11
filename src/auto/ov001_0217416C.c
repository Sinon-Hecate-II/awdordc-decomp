/* 18 functions from 0x0217416C to 0x02174F68 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_keypad.h"


void func_ov001_0217416c(void) {
    extern u8 gKeypadLayout[];
    extern u8 data_ov001_0218f5dc[];
    extern u8 data_ov001_0218f628[];
    extern u8 func_ov001_02174548[];
    extern void *gOv001Keypad;
    M2C_UNK func_ov001_0218b6f8();
    M2C_UNK func_ov001_0218a5f0();
    M2C_UNK func_ov001_0218a61c();
    M2C_UNK func_ov001_0218a260();
    M2C_UNK func_ov001_0218a474();
    M2C_UNK func_ov001_0218ac04();
    M2C_UNK func_ov001_0218a070();
    M2C_UNK func_ov001_02174f68();
    M2C_UNK func_ov001_0218c884();

    u16 sp1c;
    u16 sp1e;
    u16 sp20;
    u16 sp22;
    void *p;
    s32 mask;
    s32 i;
    u8 *src;
    u16 h;
    u8 *r9;
    s32 r10;
    s32 r8i;
    u16 r2h;
    u16 sp14;
    u16 sp0;
    s32 sp4;
    s32 sp8;
    void *spc;
    u16 sp1cnew;
    void *q;
    void *x;
    s32 sp10;
    u16 sp16;

    sp1c = *(u16*)(gKeypadLayout + 0x20);
    sp1e = *(u16*)(gKeypadLayout + 0x22);
    sp20 = 0x1c;
    sp22 = 0x14;

    p = (void*)func_ov001_0218b6f8(0x6c, 0x4);
    gOv001Keypad = p;
    M2C_FIELD(p, u8*, 0x60) = 0x1f;
    M2C_FIELD(p, u8*, 0x63) = 0;
    M2C_FIELD(p, u8*, 0x66) = 1;
    M2C_FIELD(p, u8*, 0x67) = 1;
    M2C_FIELD(p, u8*, 0x68) = 1;

    mask = 0xc1fffcff;
    for (i = 0; i < 10; i++) {
        q = (void*)func_ov001_0218a5f0(0, 0x36);
        M2C_FIELD(p, void**, 0x10 + i*4) = q;
        *(s32*)q = (*(s32*)q & mask) | 0x200;
        h = M2C_FIELD(q, u16*, 0x4);
        h = (h & ~0xc00) | 0xc00;
        M2C_FIELD(q, u16*, 0x4) = h;
    }
    src = data_ov001_0218f5dc;
    for (i = 0; i < 2; i++) {
        u8 b = *src++;
        q = (void*)func_ov001_0218a5f0(0, b);
        M2C_FIELD(p, void**, 0x38 + i*4) = q;
        *(s32*)q = (*(s32*)q & mask) | 0x200;
        h = M2C_FIELD(q, u16*, 0x4);
        h = (h & ~0xc00) | 0xc00;
        M2C_FIELD(q, u16*, 0x4) = h;
    }

    r9 = data_ov001_0218f628;
    r10 = 0;
    while (r10 < 2) {
        u8 b2 = *r9++;
        void *q2 = (void*)func_ov001_0218a61c(0, b2, 1);
        M2C_FIELD(p, void**, 0x40 + r10*4) = q2;
        func_ov001_0218a260(q2, -1, 0x200, 0);
        func_ov001_0218a474(q2, 3);
        r10++;
    }

    sp10 = 0;
    sp16 = 0;
    r10 = 0;
    r8i = 0;
    while (r10 < 4) {
        r2h = *(u16*)(func_ov001_02174548 + (r8i << 1));
        sp14 = r2h;
        sp0 = sp22;
        sp4 = 2;
        sp8 = 0x480;
        spc = (void*)&sp14;
        func_ov001_0218ac04(0, 0xc, 0x4, 0, 0, 0);
        sp1c = sp1c + 0x20;
        r8i++;
        r10++;
    }

    q = (void*)func_ov001_0218a61c(0, -1, 2);
    M2C_FIELD(p, void**, 0x58) = q;
    func_ov001_0218a260(q, -1, 0x200, 0);
    func_ov001_0218a474(q, 2);

    x = (void*)func_ov001_0218c884(0, 0, 0, 0x78);
    M2C_FIELD(p, void**, 0x5c) = x;
    func_ov001_02174f68(0, 0);

    (void)sp0; (void)sp4; (void)sp8; (void)spc;
    (void)sp10; (void)sp14; (void)sp16; (void)sp1c; (void)sp1e; (void)sp20; (void)sp22;
    (void)p; (void)sp1cnew;
}

void func_ov001_021744a8(void) {
    extern void *gOv001Keypad;
    void func_ov001_021753c8(void);
    func_ov001_0218a1cc(M2C_FIELD(gOv001Keypad, s32 *, 0x58));
    func_ov001_0218c924(M2C_FIELD(gOv001Keypad, s32 *, 0x5c), func_ov001_021753c8);
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
func_ov001_0218c924(arg0,func_ov001_021745cc);
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
func_ov001_0218c924(arg0,func_ov001_02174650);
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
func_ov001_0218c924(arg0,func_ov001_021746d4);
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
func_ov001_0218c924(arg0,func_ov001_02174758);
}
#pragma opt_propagation on
void func_ov001_02174758(s32 arg0){extern void *gOv001Keypad;
void func_ov001_021747cc(void);
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(gOv001Keypad,s32*,0x40),0,&pos[1],&pos[0]);
pos[0]-=12;
if(pos[0]>170){func_ov001_02174f68(4,pos[0]);return;}
func_ov001_02174f68(4,170);Ov001KeypadCommitKey();func_ov001_0218c924(arg0,func_ov001_021747cc);
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
    void func_ov001_0217531c(s32);
    s32 KeyPressed(s32);
    s32 KeyHeld(s32);
    s32 KeyReleased(s32);
    void Ov001_PlaySound(s32);
    register s8 k;

    if (KeyHeld(0x20)) {
        func_ov001_0217531c(0);
    }
    if (KeyHeld(0x40)) {
        func_ov001_0217531c(1);
    }
    if (KeyHeld(0x10)) {
        func_ov001_0217531c(2);
    }
    if (KeyHeld(0x80)) {
        func_ov001_0217531c(3);
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

