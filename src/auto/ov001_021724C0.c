/* 18 functions from 0x021724C0 to 0x0217332C (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"

#pragma cplusplus on
class KeyboardLabelRect {
public:
    u16 x, y, w, h;

    KeyboardLabelRect() {
        w = 0;
        h = 0;
        x = 0;
        y = 0;
    }
};
#pragma cplusplus off
void Ov001_HandleKeyboardKeyPress(void);
typedef struct SpritePosition { s32 x, y; } SpritePosition;
static inline void GetSpritePosition(const u32 *sprite, SpritePosition *pos) {
    u32 value = *sprite;
    pos->y = (value & 0x1ff0000) >> 16;
    pos->x = value & 255;
}

#pragma cplusplus on
extern "C" void Ov001_OpenKeyboard(void)
{
    extern const u8 data_ov001_0218f324[], data_ov001_0218f31c[];
    extern const u16 *data_ov001_02190104[];
    extern void *gOv001MenuState;
    void *Ov001_Alloc(s32, s32);
    void *Ov001_CreateSpriteFromLayout(s32, s32);
    void *Ov001_CreateSprite(s32, s32, s32);
    void Ov001_SetSpriteEntryFlags(void *, s32, s32, s32);
    void Ov001_SetSpritePalette(void *, s32, s32);
    void *CreatePooledTextPanel(s32, s32, s32, s32, s32 *, s32);
    void DrawPanelText(void *, s32, s32, s32, s32, s32, s32, u16 *);
    void *Ov001_AllocSpriteBlock(s32, s32, s32);
    s32 Ov001_AddTask(s32, void (*)(s32), s32, s32);
    void Ov001_KeyboardSlideStep1(s32);
    void Ov001_LayoutKeyboardRow(s32, s32, s32);
    void *sprite;
    s32 i;
    const u8 *auxIds;
    const u8 *actionIds;
    s32 action, label, col, row, page;
    struct {
        s32 firstLabel;
        u16 text[2];
        s32 layout;
        KeyboardLabelRect rect;
    } work;

    work.rect.w = 17;
    work.rect.h = 18;

    gOv001MenuState = Ov001_Alloc(0x128, 4);
    ((Ov001KeyboardState *)gOv001MenuState)->key = 0xFF;
    ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = 0;
    ((Ov001KeyboardState *)gOv001MenuState)->canDelete = 1;
    ((Ov001KeyboardState *)gOv001MenuState)->canAdd = 1;

    for (i = 0; i < 47; ++i) {
        ((Ov001KeyboardState *)gOv001MenuState)->charKeys[i] = Ov001_CreateSpriteFromLayout(0, 0x34);
        sprite = ((Ov001KeyboardState *)gOv001MenuState)->charKeys[i];
        *(u32 *)sprite = (*(u32 *)sprite & 0xC1FFFCFF) | 0x200;
        sprite = ((Ov001KeyboardState *)gOv001MenuState)->charKeys[i];
        M2C_FIELD(sprite, u16 *, 4) = (M2C_FIELD(sprite, u16 *, 4) & ~0xC00) | 0xC00;
    }
    auxIds = data_ov001_0218f324;
    for (i = 0; i < 4; ++i) {
        ((Ov001KeyboardState *)gOv001MenuState)->auxKeys[i] = Ov001_CreateSpriteFromLayout(0, *auxIds++);
        sprite = ((Ov001KeyboardState *)gOv001MenuState)->auxKeys[i];
        *(u32 *)sprite = (*(u32 *)sprite & 0xC1FFFCFF) | 0x200;
        sprite = ((Ov001KeyboardState *)gOv001MenuState)->auxKeys[i];
        M2C_FIELD(sprite, u16 *, 4) = (M2C_FIELD(sprite, u16 *, 4) & ~0xC00) | 0xC00;
    }
    for (action = 0, actionIds = data_ov001_0218f31c; action < 2; ++action, ++actionIds) {
        ((Ov001KeyboardState *)gOv001MenuState)->actionKeys[action] = Ov001_CreateSprite(0, *actionIds, 1);
        Ov001_SetSpriteEntryFlags(((Ov001KeyboardState *)gOv001MenuState)->actionKeys[action], -1, 0x200, 0);
        Ov001_SetSpritePalette(((Ov001KeyboardState *)gOv001MenuState)->actionKeys[action], -1, 3);
    }

    work.text[1] = 0;
    for (page = 0; page < 3; ++page) {
        for (row = 0, work.firstLabel = 0; row < 4; ++row) {
            ((Ov001KeyboardState *)gOv001MenuState)->rowPanels[page][row] = CreatePooledTextPanel(0, 28, 2, 0, &work.layout, 0);
            work.rect.x = 0;
            label = work.firstLabel;
            col = 0;
            do {
                work.text[0] = data_ov001_02190104[page][label];
                DrawPanelText(((Ov001KeyboardState *)gOv001MenuState)->rowPanels[page][row], work.rect.x, work.rect.y, work.rect.w, work.rect.h, 2, 0x480, work.text);
                ++col;
                work.rect.x += 18;
                ++label;
            } while (col < 12);
            if (page == 0) {
                ((Ov001KeyboardState *)gOv001MenuState)->textSprites[row] = Ov001_AllocSpriteBlock(0, work.layout, 1);
            }
            work.firstLabel += 12;
        }
    }
    ((Ov001KeyboardState *)gOv001MenuState)->cursor = Ov001_CreateSprite(0, 0x40, 1);
    Ov001_SetSpriteEntryFlags(((Ov001KeyboardState *)gOv001MenuState)->cursor, -1, 0x200, 0);
    Ov001_SetSpritePalette(((Ov001KeyboardState *)gOv001MenuState)->cursor, -1, 2);
    ((Ov001KeyboardState *)gOv001MenuState)->slideTask = Ov001_AddTask(0, Ov001_KeyboardSlideStep1, 0, 0x78);
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 0, KBD_ROW_HIDDEN_X);
}
#pragma cplusplus off
/* Begin closing the ov001 on-screen keyboard: destroy the cursor sprite that marks
 * the selected key and hand the still-running slide-in task over to the closing step. */
void Ov001_StartKeyboardClose(void) {
    extern void *gOv001MenuState;
    void Ov001_KeyboardCloseStep5(void);
    Ov001_DestroySprite(((Ov001KeyboardState *)gOv001MenuState)->cursor);
    Ov001_SetSlideStep(((Ov001KeyboardState *)gOv001MenuState)->slideTask, Ov001_KeyboardCloseStep5);
}

u8 GetKeyboardKey(void) {
    extern void *gOv001MenuState;
    return M2C_FIELD(gOv001MenuState, u8 *, 0x11C);
}

void Ov001_SetKeyboardCanDelete(s8 arg0) {
    extern void *gOv001MenuState;
    M2C_FIELD(gOv001MenuState, s8 *, 0x123) = arg0;
}

void Ov001_SetKeyboardCanAdd(s8 arg0) {
 extern void *gOv001MenuState;
 M2C_FIELD(gOv001MenuState, s8 *, 0x124) = arg0;
}

/* True while the ov001 on-screen keyboard is up (gOv001MenuState holds its state). */
s32 Ov001_IsMenuActive(void) {
    extern void *gOv001MenuState;
    if (gOv001MenuState != 0) return 1;
    return 0;
}

#pragma opt_common_subs off
void Ov001_KeyboardSlideStep1(s32 task){
extern void *gOv001MenuState;
void Ov001_KeyboardSlideStep2(s32);
u32 sprite; s32 keyX; u32 keyY; s32 pos[2];
sprite=*(u32 *)((Ov001KeyboardState *)gOv001MenuState)->charKeys[0];
keyY=sprite&0x1ff0000;
keyX=(sprite&255)-12;
((volatile s32 *)pos)[1]=keyY>>16;
pos[0]=keyX;
if(pos[0]>KBD_ROW_REST_X0){Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page,0,pos[0]);return;}
Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page,0,KBD_ROW_REST_X0);
Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page,1,KBD_ROW_HIDDEN_X);
Ov001_SetSlideStep(task,Ov001_KeyboardSlideStep2);
}
#pragma optimization_level 2
/* Slide-in step for the second keyboard row: while its leftmost key is still to
 * the right of where the row comes to rest, move the whole row along with it;
 * once it has arrived, snap the row into place, park the third row just off the
 * right edge and queue that row's step. */
void Ov001_KeyboardSlideStep2(s32 task) {
    extern void *gOv001MenuState;
    void Ov001_KeyboardSlideStep3(s32);
    u32 sprite;
    s32 keyX;
    u32 keyY;
    s32 pos[2];
    sprite = *(u32 *)((Ov001KeyboardState *)gOv001MenuState)->charKeys[12];
    keyY = sprite & 0x1ff0000;
    keyX = (sprite & 255) - 12;
    ((volatile s32 *)pos)[1] = keyY >> 16;
    pos[0] = keyX;
    if (pos[0] > KBD_ROW_REST_X1) {
        Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 1, pos[0]);
        return;
    }
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 1, KBD_ROW_REST_X1);
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 2, KBD_ROW_HIDDEN_X);
    Ov001_SetSlideStep(task, Ov001_KeyboardSlideStep3);
}
#pragma optimization_level 3
/* Slide-in step for the third keyboard row: while its leftmost key is still to
 * the right of where the row comes to rest, move the whole row along with it;
 * once it has arrived, snap the row into place, park the fourth row just off the
 * right edge and queue that row's step. */
void Ov001_KeyboardSlideStep3(s32 task) {
    extern void *gOv001MenuState;
    void Ov001_KeyboardSlideStep4(s32);
    u32 sprite;
    s32 keyX;
    u32 keyY;
    s32 pos[2];
    sprite = *(u32 *)((Ov001KeyboardState *)gOv001MenuState)->charKeys[24];
    keyY = sprite & 0x1ff0000;
    keyX = (sprite & 255) - 12;
    ((volatile s32 *)pos)[1] = keyY >> 16;
    pos[0] = keyX;
    if (pos[0] > KBD_ROW_REST_X2) {
        Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 2, pos[0]);
        return;
    }
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 2, KBD_ROW_REST_X2);
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 3, KBD_ROW_HIDDEN_X);
    Ov001_SetSlideStep(task, Ov001_KeyboardSlideStep4);
}
#pragma peephole off
/* Slide-in step for the fourth keyboard row: while its leftmost key is still to
 * the right of where the row comes to rest, move the whole row along with it;
 * once it has arrived, snap the row into place, park the bottom action row just
 * off the right edge and queue that row's step. */
void Ov001_KeyboardSlideStep4(s32 task) {
    extern void *gOv001MenuState;
    void Ov001_KeyboardSlideStep5(s32);
    u32 sprite;
    s32 keyX;
    u32 keyY;
    s32 pos[2];
    sprite = *(u32 *)((Ov001KeyboardState *)gOv001MenuState)->charKeys[36];
    keyY = sprite & 0x1ff0000;
    keyX = (sprite & 255) - 12;
    ((volatile s32 *)pos)[1] = keyY >> 16;
    pos[0] = keyX;
    if (pos[0] > KBD_ROW_REST_X3) {
        Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 3, pos[0]);
        return;
    }
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 3, KBD_ROW_REST_X3);
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, 4, KBD_ROW_HIDDEN_X);
    Ov001_SetSlideStep(task, Ov001_KeyboardSlideStep5);
}
#pragma peephole reset
/* Slide-in step for the bottom action row: while its leftmost key is still to
 * the right of where the row comes to rest, move the whole row along with it;
 * once it has arrived, snap the row into place, update the cursor and finish
 * the slide-in. */
void Ov001_KeyboardSlideStep5(s32 task) {
 extern void *gOv001MenuState;
 void Ov001_KeyboardSlideDone(void);
 s32 pos[2];
 Ov001_GetSpritePosition(M2C_FIELD(gOv001MenuState,s32 *,0xfc),0,&pos[1],&pos[0]);
 pos[0]-=12;
 if(pos[0]>KBD_ROW_REST_X4) {Ov001_LayoutKeyboardRow(M2C_FIELD(gOv001MenuState,u8 *,0x11d),4,pos[0]);return;}
 Ov001_LayoutKeyboardRow(M2C_FIELD(gOv001MenuState,u8 *,0x11d),4,KBD_ROW_REST_X4);
 Ov001_UpdateKeyboardCursor(); Ov001_SetSlideStep(task,Ov001_KeyboardSlideDone);
}

/* The keyboard's slide-in has finished: catch up with the touch state as it
 * stands (keys moved under a finger still down during the slide) by running the
 * keyboard's touch handlers once — press, hold, release — and then hand over to
 * the keyboard's regular key input. */
void Ov001_KeyboardSlideDone(void) {
    void func_ov001_02172d8c(void); /* the keyboard's held-touch handler */
    void Ov001_HandleKeyboardKeyRelease(void);
    M2C_UNK Ov001_KeyboardInput();
    Ov001_HandleKeyboardKeyPress();
    func_ov001_02172d8c();
    Ov001_HandleKeyboardKeyRelease();
    Ov001_KeyboardInput();
}

/* Handles the stylus being pressed on the on-screen keyboard: records the key under the press,
 * buzzing instead when the text is full and the key cannot be added, or the delete key when
 * nothing can be deleted. */
void Ov001_HandleKeyboardKeyPress(void) {
    extern void *gOv001MenuState;
    extern u16 gTouchScreenRect[];
    extern u16 gKeyboardCharKeyPos[];
    extern u16 gKeyboardCharKeySize[];
    extern u16 gKeyboardAuxKeyPos[];
    extern u16 gKeyboardAuxKeySize[];
    extern u16 gKeyboardActionKeyPos[];
    extern u16 gKeyboardActionKeySize[];
    extern s32 gKeyboardAuxKeySound[];
    s32 TouchRectPressed(void *);
    void BuildTouchRect(void *, void *, void *);
    void Ov001_PlaySound(s32);
    u16 buf[4];
    s32 i;
    if (!TouchRectPressed(gTouchScreenRect)) return;
    ((Ov001KeyboardState *)gOv001MenuState)->touchKey = -1;
    {
        u16 *keyPos = gKeyboardCharKeyPos;
        for (i = 0; i < KBD_CHAR_KEY_COUNT; i++) {
            BuildTouchRect(keyPos, gKeyboardCharKeySize, buf);
            if (TouchRectPressed(buf)) {
                if (((Ov001KeyboardState *)gOv001MenuState)->canAdd == 0) {
                    Ov001_PlaySound(9);
                    return;
                }
                Ov001_PlaySound(0);
                ((Ov001KeyboardState *)gOv001MenuState)->touchKey = (u8)i;
                return;
            }
            keyPos += 2;
        }
    }
    {
        u16 *keySize = gKeyboardAuxKeySize;
        u16 *keyPos = gKeyboardAuxKeyPos;
        for (i = 0; i < 4; i++) {
            BuildTouchRect(keyPos, keySize, buf);
            if (TouchRectPressed(buf)) {
                if ((i == 3 && ((Ov001KeyboardState *)gOv001MenuState)->canDelete == 0) ||
                    (i == 2 && ((Ov001KeyboardState *)gOv001MenuState)->canAdd == 0)) {
                    Ov001_PlaySound(9);
                    return;
                }
                Ov001_PlaySound(gKeyboardAuxKeySound[i]);
                ((Ov001KeyboardState *)gOv001MenuState)->touchKey = (u8)(i + KBD_CHAR_KEY_COUNT);
                return;
            }
            keySize += 2;
            keyPos += 2;
        }
    }
    {
        u16 *keySize;
        u16 *keyPos;
        keyPos = gKeyboardActionKeyPos;
        keySize = gKeyboardActionKeySize;
        for (i = 0; i < 2; i++) {
            BuildTouchRect(keyPos, keySize, buf);
            if (TouchRectPressed(buf)) {
                Ov001_PlaySound(0);
                ((Ov001KeyboardState *)gOv001MenuState)->touchKey = (u8)(i + KBD_ACTION_KEY_BASE);
                return;
            }
            keyPos += 2;
        }
    }
    return;
}

#pragma opt_strength_reduction off
void func_ov001_02172d8c(void) {
    extern void *gOv001MenuState;
    extern u16 gTouchScreenRect[];
    extern u16 gKeyboardCharKeyPos[];
    extern u16 gKeyboardCharKeySize[];
    extern u8 *gKeyboardCharTables[];
    extern u16 data_ov001_0218f364[];
    extern u16 data_ov001_0218f354[];
    extern u8 gKeyboardSpecialChars[];
    extern u16 gKeyboardActionKeyPos[];
    extern u16 gKeyboardActionKeySize[];
    extern u8 gKeyboardActionChars[];
    extern u16 gKeyboardAuxKeyPos[];
    extern u16 gKeyboardAuxKeySize[];
    extern u16 data_ov001_0218f350[];
    extern u16 data_ov001_0218f360[];
    void BuildTouchRect(void *, void *, void *);
    s32 TouchRectHeld(void *);
    void Ov001_SetKeyboardPage(s32);
    s32 Ov001_UpdateKeyboardCursor(void);
    void Ov001_ToggleKeyboardCase(void);
    void Ov001_ToggleKeyboardSymbols(void);

    u8 buf[8];
    s32 i;
    u8 *p;
    u8 *q;
    Ov001KeyboardState *state;

    ((Ov001KeyboardState *)gOv001MenuState)->key = 0;
    if (TouchRectHeld(gTouchScreenRect) == 0) {
        return;
    }

    p = (u8 *)gKeyboardCharKeyPos;
    q = (u8 *)gKeyboardCharKeySize;
    for (i = 0; i < 0x2f; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            state = (Ov001KeyboardState *)gOv001MenuState;
            if (state->touchKey != i) {
                return;
            }
            state->key = gKeyboardCharTables[state->page][i];
            if (((Ov001KeyboardState *)gOv001MenuState)->page == 1) {
                Ov001_SetKeyboardPage(0);
                ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = (u8)i;
                Ov001_UpdateKeyboardCursor();
                return;
            }
        }
        p += 4;
    }

    q = (u8 *)data_ov001_0218f364;
    p = (u8 *)data_ov001_0218f354;
    for (i = 2; i < 4; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            state = (Ov001KeyboardState *)gOv001MenuState;
            if (state->touchKey != i + 0x2f) {
                return;
            }
            state->key = gKeyboardSpecialChars[i];
            if (((Ov001KeyboardState *)gOv001MenuState)->page == 1) {
                Ov001_SetKeyboardPage(0);
                ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = (u8)(i + 0x2f);
                Ov001_UpdateKeyboardCursor();
                return;
            }
        }
        p += 4;
        q += 4;
    }

    p = (u8 *)gKeyboardActionKeyPos;
    q = (u8 *)gKeyboardActionKeySize;
    for (i = 0; i < 2; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            state = (Ov001KeyboardState *)gOv001MenuState;
            if (state->touchKey != i + 0x33) {
                return;
            }
            state->key = gKeyboardActionChars[i];
            ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = (u8)(i + 0x33);
            Ov001_UpdateKeyboardCursor();
            return;
        }
        p += 4;
    }

    BuildTouchRect(gKeyboardAuxKeyPos, gKeyboardAuxKeySize, buf);
    if (TouchRectHeld(buf) != 0) {
        if (((Ov001KeyboardState *)gOv001MenuState)->touchKey != 0x2f) {
            return;
        }
        Ov001_ToggleKeyboardCase();
        ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = 0x2f;
        Ov001_UpdateKeyboardCursor();
        return;
    }

    BuildTouchRect(data_ov001_0218f350, data_ov001_0218f360, buf);
    if (TouchRectHeld(buf) != 0) {
        if (((Ov001KeyboardState *)gOv001MenuState)->touchKey != 0x30) {
            return;
        }
        Ov001_ToggleKeyboardSymbols();
        ((Ov001KeyboardState *)gOv001MenuState)->selectedKey = 0x30;
        Ov001_UpdateKeyboardCursor();
        return;
    }
    return;
}
#pragma opt_strength_reduction reset
/* Switch the on-screen keyboard between its lowercase and uppercase pages:
 * uppercase drops back to lowercase, and either other page becomes uppercase. */
void Ov001_ToggleKeyboardCase(void) {
 extern void *gOv001MenuState;
 Ov001KeyboardState *state = (Ov001KeyboardState *)gOv001MenuState;
 s32 page;
 page=state->page==KBD_PAGE_UPPER?KBD_PAGE_LOWER:KBD_PAGE_UPPER;
 Ov001_SetKeyboardPage(page); Ov001_PlaySound(OV001_SOUND_KEY);
}

/* Switch the on-screen keyboard between its symbol page and its lowercase page,
 * away from whichever of the two is showing, and play the key sound. */
void Ov001_ToggleKeyboardSymbols(void) {
    extern void *gOv001MenuState;
    Ov001_SetKeyboardPage(((Ov001KeyboardState *)gOv001MenuState)->page != KBD_PAGE_SYMBOLS);
    Ov001_PlaySound(OV001_SOUND_KEY);
}

/* Handles the stylus being released over the on-screen keyboard: selects the key
 * under the release, and while the delete key is held repeats the deletion after
 * a delay until the text can no longer be deleted. */
void Ov001_HandleKeyboardKeyRelease(void) {
    extern u16 gTouchScreenRect[];
    extern u16 gKeyboardCharKeyPos[];
    extern u16 gKeyboardCharKeySize[];
    extern u16 data_ov001_0218f364[];
    extern u16 data_ov001_0218f354[];
    extern u16 gKeyboardActionKeyPos[];
    extern u16 gKeyboardActionKeySize[];
    extern void *gOv001MenuState;
    void BuildTouchRect(void *, void *, void *);
    s32 TouchRectReleased(void *);
    void Ov001_SetSelectedKeyboardKey(s32);
    M2C_UNK Ov001_PlaySound(M2C_UNK);

    s32 i;
    u8 buf[8];
    u8 *keySize;
    u8 *keyPos;

    if (TouchRectReleased(gTouchScreenRect) == 0) {
        goto fail;
    }

    keyPos = (u8 *)gKeyboardCharKeyPos;
    for (i = 0; i < KBD_CHAR_KEY_COUNT; i++) {
        BuildTouchRect(keyPos, gKeyboardCharKeySize, buf);
        if (TouchRectReleased(buf) != 0) {
            if (((Ov001KeyboardState *)gOv001MenuState)->touchKey != i) {
                goto fail;
            }
            Ov001_SetSelectedKeyboardKey(i);
            goto tail;
        }
        keyPos += 4;
    }

    keySize = (u8 *)data_ov001_0218f364;
    keyPos = (u8 *)data_ov001_0218f354;
    for (i = 2; i < 4; i++) {
        BuildTouchRect(keyPos, keySize, buf);
        if (TouchRectReleased(buf) != 0) {
            if (((Ov001KeyboardState *)gOv001MenuState)->touchKey != i + KBD_CHAR_KEY_COUNT) {
                goto fail;
            }
            Ov001_SetSelectedKeyboardKey(i + KBD_CHAR_KEY_COUNT);
            if (i != 3) {
                return;
            }
            ((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat =
                (u8)(((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat + 1);
            {
                u8 repeat = ((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat;
                if (repeat < KBD_DELETE_REPEAT_DELAY) {
                    return;
                }
            }
            if (((Ov001KeyboardState *)gOv001MenuState)->canDelete == 0) {
                Ov001_PlaySound(9);
                ((Ov001KeyboardState *)gOv001MenuState)->touchKey = -1;
                return;
            } else {
                ((Ov001KeyboardState *)gOv001MenuState)->key = KBD_KEY_DELETE;
                ((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat =
                    (u8)(((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat - KBD_DELETE_REPEAT_STEP);
                return;
            }
        }
        keySize += 4;
        keyPos += 4;
    }

    keyPos = (u8 *)gKeyboardActionKeyPos;
    for (i = 0; i < 2; i++) {
        BuildTouchRect(keyPos, gKeyboardActionKeySize, buf);
        if (TouchRectReleased(buf) != 0) {
            if (((Ov001KeyboardState *)gOv001MenuState)->touchKey != i + KBD_ACTION_KEY_BASE) {
                goto fail;
            }
            Ov001_SetSelectedKeyboardKey(i + KBD_ACTION_KEY_BASE);
            goto tail;
        }
        keyPos += 4;
    }

fail:
    Ov001_SetSelectedKeyboardKey(-1);

tail:
    ((Ov001KeyboardState *)gOv001MenuState)->deleteRepeat = 0;
    return;
}

/* Moves the keyboard's touch highlight to `key`: clears the selected flag on the
 * key that had it, sets it on the new one and remembers it. */
void Ov001_SetSelectedKeyboardKey(s32 key) {
 extern void *gOv001MenuState;
 if(key==((Ov001KeyboardState *)gOv001MenuState)->highlightedKey) return;
 Ov001_SetKeyboardKeySelected(key,1);
 Ov001_SetKeyboardKeySelected(((Ov001KeyboardState *)gOv001MenuState)->highlightedKey,0);
 ((Ov001KeyboardState *)gOv001MenuState)->highlightedKey=key;
}


