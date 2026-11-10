/* 18 functions from 0x021724C0 to 0x0217332C (ov001), found by ds-decomp. */
#include "common.h"
void Ov001_HandleKeyboardKeyPress(void);
typedef struct SpritePosition { s32 x, y; } SpritePosition;
static inline void GetSpritePosition(const u32 *sprite, SpritePosition *pos) {
    u32 value = *sprite;
    pos->y = (value & 0x1ff0000) >> 16;
    pos->x = value & 255;
}

void func_ov001_021724c0(void) {
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a5f0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a61c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a260(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a474(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218ac04(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK DrawPanelText(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a070(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0217355c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_021728b0(M2C_UNK);
    extern void *gOv001MenuState;
    extern u8 data_ov001_0218f31c[];
    extern u8 data_ov001_0218f324[];
    extern void *data_ov001_02190104[];
    volatile u16 tmp[4];
    void *q;
    void *p;
    void *ret;
    s32 i, u, t;
    u16 sp1c = 0, sp1e = 0, sp20 = 0x11, sp22 = 0x12, sp14 = 0;
    volatile u16 sp16 = 0;
    M2C_UNK sp18val = 0;
    M2C_UNK *psp = &sp18val;
    s32 sp10 = 0;
    s32 r8 = 0, r9 = 0;
    tmp[2] = 0; tmp[3] = 0; tmp[0] = 0; tmp[1] = 0;
    tmp[2] = 0x11; tmp[3] = 0x12;
    q = func_ov001_0218b6f8(0x128, 4, 0x12, 0x11);
    gOv001MenuState = q;
    M2C_FIELD(gOv001MenuState, u8 *, 0x11c) = 0xff;
    M2C_FIELD(gOv001MenuState, u8 *, 0x121) = 0;
    M2C_FIELD(gOv001MenuState, u8 *, 0x123) = 1;
    M2C_FIELD(gOv001MenuState, u8 *, 0x124) = 1;
    for (i = 0; i < 0x2f; i++) {
        p = func_ov001_0218a5f0(0, 0x34);
        ((void **)((u8 *)gOv001MenuState + 0x30))[i] = p;
        p = ((void **)((u8 *)gOv001MenuState + 0x30))[i];
        {
            u32 val = *(u32 *)p;
            val = (val & 0xc1fffcffU) | 0x200;
            *(u32 *)p = val;
        }
        {
            u16 hh = *(u16 *)((u8 *)p + 4);
            hh = (hh & ~0xc00) | 0xc00;
            *(u16 *)((u8 *)p + 4) = hh;
        }
    }
    for (i = 0; i < 4; i++) {
        u8 b = data_ov001_0218f324[i];
        p = func_ov001_0218a5f0(0, b);
        ((void **)((u8 *)gOv001MenuState + 0xec))[i] = p;
        p = ((void **)((u8 *)gOv001MenuState + 0xec))[i];
        {
            u32 val = *(u32 *)p;
            val = (val & 0xc1fffcffU) | 0x200;
            *(u32 *)p = val;
        }
        {
            u16 hh = *(u16 *)((u8 *)p + 4);
            hh = (hh & ~0xc00) | 0xc00;
            *(u16 *)((u8 *)p + 4) = hh;
        }
    }
    for (u = 0; u < 2; u++) {
        u8 b = data_ov001_0218f31c[u];
        p = func_ov001_0218a61c(0, b, 1);
        ((void **)((u8 *)gOv001MenuState + 0xfc))[u] = p;
        p = ((void **)((u8 *)gOv001MenuState + 0xfc))[u];
        func_ov001_0218a260(p, (M2C_UNK)-1, 0x200, 0);
        func_ov001_0218a474(p, (M2C_UNK)-1, 3);
    }
    sp18val = 0;
    psp = &sp18val;
    for (t = 0; t < 3; t++) {
        void *obj;
        sp1c = 0;
        sp1e = 0;
        sp20 = 0x11;
        sp22 = 0x12;
        sp14 = 0;
        sp16 = t;
        (void)sp16;
        obj = (void *)func_ov001_0218ac04(0, 0x1c, 2, 0, (M2C_UNK)psp, 0);
        ((void **)((u8 *)gOv001MenuState + 0))[t * 4 + 0] = obj;
        obj = ((void **)((u8 *)gOv001MenuState + 0))[t * 4 + 0];
        sp10 = 0;
        r8 = 0;
        while (r8 < 0xc) {
            u16 ah = *(u16 *)((u8 *)data_ov001_02190104[t] + (sp10 * 2));
            sp14 = ah;
            sp22 = 0x12;
            {
                void *cur = ((void **)((u8 *)gOv001MenuState + 0))[t * 4 + 0];
                DrawPanelText(cur, sp1c, sp1e, sp20, sp22, 2, 0x480, (M2C_UNK)&sp14);
            }
            sp1c = sp1c + 0x12;
            sp10++;
            r8++;
        }
        if (t == 0) {
            r9 = 0;
            while (r9 < 4) {
                void *o2 = (void *)func_ov001_0218a070(0, sp18val, 1);
                ((void **)((u8 *)gOv001MenuState + 0x104))[r9] = o2;
                o2 = ((void **)((u8 *)gOv001MenuState + 0x104))[r9];
                (void)o2;
                r9++;
            }
        }
    }
    ret = func_ov001_0218a61c(0, 0x40, 1);
    M2C_FIELD(gOv001MenuState, void **, 0x114) = ret;
    func_ov001_0218a260(ret, (M2C_UNK)-1, 0x200, 0);
    func_ov001_0218a474(ret, (M2C_UNK)-1, 2);
    ret = (void *)func_ov001_0218c884(0, (M2C_UNK)func_ov001_021728b0, 0, 0x78);
    M2C_FIELD(gOv001MenuState, void **, 0x118) = ret;
    func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11d), 0, 0xc0);
}

void func_ov001_02172824(void) {
 extern void *gOv001MenuState;
 void func_ov001_02173e38(void);
 func_ov001_0218a1cc(M2C_FIELD(gOv001MenuState, s32 *, 0x114));
 func_ov001_0218c924(M2C_FIELD(gOv001MenuState, s32 *, 0x118), func_ov001_02173e38);
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

s32 func_ov001_02172894(void) {
 extern void *gOv001MenuState;
 if (gOv001MenuState != 0) return 1;
 return 0;
}

#pragma opt_common_subs off
void func_ov001_021728b0(s32 arg0) {
extern void *gOv001MenuState;
void func_ov001_02172944(s32);
struct {s32 x,y;} xy,*pos=&xy;
u32 value=*M2C_FIELD(gOv001MenuState,u32 **,0x30);
pos->y=(value&0x1ff0000)>>16;
pos->x=(value&255)-12;
if(pos->x>0x51) {func_ov001_0217355c(M2C_FIELD(gOv001MenuState,u8 *,0x11d),0,pos->x);return;}
func_ov001_0217355c(M2C_FIELD(gOv001MenuState,u8 *,0x11d),0,0x51);
func_ov001_0217355c(M2C_FIELD(gOv001MenuState,u8 *,0x11d),1,0xc0);
func_ov001_0218c924(arg0,func_ov001_02172944);
}
#pragma optimization_level 2
void func_ov001_02172944(s32 arg0) {
 extern void *gOv001MenuState;
 void func_ov001_021729d8(s32);
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(gOv001MenuState, u32 **, 0x60);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x67) {
  func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 1, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 1, 0x67);
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 2, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_021729d8);
}
#pragma optimization_level 3
void func_ov001_021729d8(s32 arg0) {
 extern void *gOv001MenuState;
 void func_ov001_02172a6c(s32);
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(gOv001MenuState, u32 **, 0x90);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x7D) {
  func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 2, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 2, 0x7D);
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 3, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172a6c);
}
#pragma peephole off
void func_ov001_02172a6c(s32 arg0) {
 extern void *gOv001MenuState;
 void func_ov001_02172b00(s32);
 u32 value;
 s32 x;
 u32 y;
 s32 pos[2];
 s32 yy;
 value = *M2C_FIELD(gOv001MenuState, u32 **, 0xC0);
 x = (value & 0xFF) - 12;
 y = value & 0x1FF0000;
 yy = y >> 16;
 ((volatile s32 *)pos)[1] = yy;
 ((volatile s32 *)pos)[0] = x;
 if (pos[0] > 0x93) {
  func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 3, pos[0]);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 3, 0x93);
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 4, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172b00);
}
#pragma peephole reset
void func_ov001_02172b00(s32 arg0) {
 extern void *gOv001MenuState;
 void func_ov001_02172b8c(void);
 s32 pos[2];
 func_ov001_0218a4d4(M2C_FIELD(gOv001MenuState,s32 *,0xfc),0,&pos[1],&pos[0]);
 pos[0]-=12;
 if(pos[0]>170) {func_ov001_0217355c(M2C_FIELD(gOv001MenuState,u8 *,0x11d),4,pos[0]);return;}
 func_ov001_0217355c(M2C_FIELD(gOv001MenuState,u8 *,0x11d),4,170);
 func_ov001_02173924(); func_ov001_0218c924(arg0,func_ov001_02172b8c);
}

void func_ov001_02172b8c(void) {
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

s32 func_ov001_02172d8c(void) {
    extern void *gOv001MenuState;
    extern u16 gTouchScreenRect[];
    extern u16 gKeyboardCharKeyPos[];
    extern u16 gKeyboardCharKeySize[];
    extern void *gKeyboardCharTables[];
    extern u16 data_ov001_0218f364[];
    extern u16 data_ov001_0218f354[];
    extern u16 gKeyboardSpecialChars[];
    extern u16 gKeyboardActionKeyPos[];
    extern u16 gKeyboardActionKeySize[];
    extern u16 gKeyboardActionChars[];
    extern u16 gKeyboardAuxKeyPos[];
    extern u16 gKeyboardAuxKeySize[];
    extern u16 data_ov001_0218f350[];
    extern u16 data_ov001_0218f360[];
    void BuildTouchRect(void *, void *, void *);
    s32 TouchRectHeld(void *);
    void Ov001_SetKeyboardPage(s32);
    s32 func_ov001_02173924(void);
    void Ov001_ToggleKeyboardCase(void);
    void Ov001_ToggleKeyboardSymbols(void);

    u8 buf[8];
    s32 i;
    u8 *p;
    u8 *q;
    u8 *tableEntry;

    M2C_FIELD(gOv001MenuState, u8 *, 0x11c) = 0;
    if (TouchRectHeld(gTouchScreenRect) == 0) {
        return 0;
    }

    p = (u8 *)gKeyboardCharKeyPos;
    q = (u8 *)gKeyboardCharKeySize;
    for (i = 0; i < 0x2f; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            if (M2C_FIELD(gOv001MenuState, s8 *, 0x11e) != i) {
                return 0;
            }
            tableEntry = (u8 *)gKeyboardCharTables[M2C_FIELD(gOv001MenuState, u8 *, 0x11d)];
            M2C_FIELD(gOv001MenuState, u8 *, 0x11c) = tableEntry[i];
            if (M2C_FIELD(gOv001MenuState, u8 *, 0x11d) == 1) {
                Ov001_SetKeyboardPage(0);
                M2C_FIELD(gOv001MenuState, u8 *, 0x121) = 0;
                func_ov001_02173924();
                return 0;
            }
        }
        p += 4;
    }

    p = (u8 *)data_ov001_0218f354;
    q = (u8 *)data_ov001_0218f364;
    for (i = 2; i < 4; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            if (M2C_FIELD(gOv001MenuState, s8 *, 0x11e) != i + 0x2f) {
                return 0;
            }
            M2C_FIELD(gOv001MenuState, u8 *, 0x11c) = (u8)gKeyboardActionKeyPos[i];
            if (M2C_FIELD(gOv001MenuState, u8 *, 0x11d) == 1) {
                Ov001_SetKeyboardPage(0);
                M2C_FIELD(gOv001MenuState, u8 *, 0x121) = (u8)(i + 0x2f);
                func_ov001_02173924();
                return 0;
            }
        }
        p += 4;
        q += 4;
    }

    p = (u8 *)gKeyboardSpecialChars;
    q = (u8 *)gKeyboardActionKeyPos;
    for (i = 0; i < 2; i++) {
        BuildTouchRect(p, q, buf);
        if (TouchRectHeld(buf) != 0) {
            if (M2C_FIELD(gOv001MenuState, s8 *, 0x11e) != i + 0x33) {
                return 0;
            }
            M2C_FIELD(gOv001MenuState, u8 *, 0x11c) = (u8)gKeyboardActionKeySize[i];
            M2C_FIELD(gOv001MenuState, u8 *, 0x121) = (u8)(i + 0x33);
            func_ov001_02173924();
            return 0;
        }
        p += 4;
    }

    BuildTouchRect(gKeyboardActionChars, data_ov001_0218f350, buf);
    if (TouchRectHeld(buf) != 0) {
        if (M2C_FIELD(gOv001MenuState, s8 *, 0x11e) != 0x2f) {
            return 0;
        }
        Ov001_ToggleKeyboardCase();
        M2C_FIELD(gOv001MenuState, u8 *, 0x121) = 0x2f;
        func_ov001_02173924();
        return 0;
    }

    BuildTouchRect(gKeyboardAuxKeyPos, data_ov001_0218f360, buf);
    if (TouchRectHeld(buf) != 0) {
        if (M2C_FIELD(gOv001MenuState, s8 *, 0x11e) != 0x30) {
            return 0;
        }
        Ov001_ToggleKeyboardSymbols();
        M2C_FIELD(gOv001MenuState, u8 *, 0x121) = 0x30;
        func_ov001_02173924();
        return 0;
    }
    return 0;
}

void Ov001_ToggleKeyboardCase(void) {
 extern void *gOv001MenuState;
 s32 n;
 n=M2C_FIELD(gOv001MenuState,u8 *,0x11d)==2?0:2;
 Ov001_SetKeyboardPage(n); Ov001_PlaySound(1);
}

void Ov001_ToggleKeyboardSymbols(void) {
 extern void *gOv001MenuState;
 Ov001_SetKeyboardPage(M2C_FIELD(gOv001MenuState,u8 *,0x11d)!=1);
 Ov001_PlaySound(1);
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

void Ov001_SetSelectedKeyboardKey(s32 arg0) {
 extern void *gOv001MenuState;
 if(arg0==M2C_FIELD(gOv001MenuState,s8 *,0x11f)) return;
 func_ov001_0217385c(arg0,1);
 func_ov001_0217385c(M2C_FIELD(gOv001MenuState,s8 *,0x11f),0);
 M2C_FIELD(gOv001MenuState,s8 *,0x11f)=arg0;
}


