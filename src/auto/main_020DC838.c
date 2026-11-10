/* 23 functions from 0x020DC838 to 0x020DD4F8 (main), found by ds-decomp. */
#include "common.h"
static inline u16 SpriteFrame(void *p) {return (M2C_FIELD(p,u32 *,0x40)<<6)>>24;}
static inline u32 SpriteBase(void *p) {return (u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28;}
static inline u8 SpriteAvailable(void *p) {u8 r;if(SpriteBase(p)+2!=SpriteFrame(p))r=1;else r=0;return r;}
static inline void SetSpriteFrame(void *p,u16 frame,s8 timer) {
M2C_FIELD(p,s32 *,0x40)=(M2C_FIELD(p,s32 *,0x40)&~0x03fc0000)|((u32)(frame<<24)>>6);
M2C_FIELD(p,s8 *,0x5a)=timer;
}

static inline void func_020dcc00(void *q) {
    s32 next;
    u32 base;
    u32 value;
    s32 test;
    base = (u32)(M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16)((u32)(M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

#pragma push
#pragma opt_strength_reduction off
/* Input handler of the matching/link menu: updates its sprites and turns the A/B
 * presses into the confirm and back animations of the highlighted option. */
void MatchingMenuConfirmInput(void *menu) {
    void MenuSpriteUpdate(void *);
    void func_020d47f0(void);
    void SetSpriteAnimation(void *, s32);
    void PlaySoundEffect(s32);
    void func_01ffa6fc(void *);
    extern u16 *gKeyState;
    typedef struct { u32 low:18; u32 frame:8; u32 high:6; } SpriteFrameBits;
    typedef struct { unsigned char base:4; } SpriteBaseBits;

    u32 keys;
    void *backSprite;
    u8 optionEnabled;

    if (M2C_FIELD(menu, void **, 0x50)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x50));
    if (M2C_FIELD(menu, void **, 0x54)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x54));
    if (M2C_FIELD(menu, void **, 0x58)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x58));

    keys = *gKeyState;
    M2C_FIELD(menu, u16 *, 0x48) &= ~0x20;

    backSprite = M2C_FIELD(menu, void **, 0x58);
    optionEnabled = 1;
    if (M2C_FIELD(M2C_FIELD(backSprite, void **, MENU_SPRITE_OWNER), s8 *, 0xb) != 1) {
        if (!((u32)(M2C_FIELD(backSprite, u8 *, MENU_SPRITE_BASE) << 27) >> 31) || M2C_FIELD(M2C_FIELD(backSprite, void **, MENU_SPRITE_OWNER), s8 *, 0xc) != 1)
            optionEnabled = 0;
    }

    if ((u8)(optionEnabled & 0xff) == 0) {
        if (!(keys & 0x2)) goto skip1;
    }
    if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) goto skip1;

    if (M2C_FIELD(backSprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
        M2C_FIELD(backSprite, SpriteFrameBits *, MENU_SPRITE_FRAME).frame = (u16)(M2C_FIELD(backSprite, SpriteBaseBits *, MENU_SPRITE_BASE).base + 1);
        M2C_FIELD(backSprite, u8 *, MENU_SPRITE_TIMER) = 12;
    }
    func_020d47f0();
    switch(M2C_FIELD(menu,s32*,0x38)){
    case 0: M2C_FIELD(menu,u8*,0x40)=0x1e; break;
    case 1: M2C_FIELD(menu,u8*,0x40)=0x1f; break;
    }
    M2C_FIELD(menu, u16 *, 0x48) |= 0x20;
    SetSpriteAnimation(menu, 0x44);
    PlaySoundEffect(0x1000f);
    return;

skip1:
    {
        void *optionSprite = M2C_FIELD(menu, void **, 0x50);
        u32 baseFrame = M2C_FIELD(optionSprite, SpriteBaseBits *, MENU_SPRITE_BASE).base;
        u16 frame = (M2C_FIELD(optionSprite, u32 *, MENU_SPRITE_FRAME) << 6) >> 24;
        s32 changed;
        if (baseFrame + 2 != frame) changed=1; else changed=0;
        if (changed & 0xff) {
            u8 optionEnabled2 = 1;
            void *owner = M2C_FIELD(optionSprite, void **, MENU_SPRITE_OWNER);
            if (M2C_FIELD(owner, s8 *, 0xb) != 1) {
                if (!((u32)(M2C_FIELD(optionSprite, u8 *, MENU_SPRITE_BASE) << 27) >> 31) || M2C_FIELD(owner, s8 *, 0xc) != 1)
                    optionEnabled2 = 0;
            }
            if ((u8)(optionEnabled2 & 0xff) == 0) {
                if (!(keys & 0x1)) return;
            }
            if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) return;
            if (M2C_FIELD(optionSprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
                M2C_FIELD(optionSprite, SpriteFrameBits *, MENU_SPRITE_FRAME).frame = (u16)(baseFrame + 1);
                M2C_FIELD(optionSprite, u8 *, MENU_SPRITE_TIMER) = 12;
            }
            if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) return;
            PlaySoundEffect(0x1000e);
            M2C_FIELD(menu, u16 *, 0x48) |= 0x4;
            func_01ffa6fc(menu);
        }
    }
}
#pragma pop
void func_020dca5c(void) {
    M2C_UNK MenuConfirmInput();
    MenuConfirmInput();
}

void func_020dca68(void) {
    M2C_UNK MenuConfirmInput();
    MenuConfirmInput();
}

void func_020dca74(void) {
    void MatchingMenuConfirmInput();
    MatchingMenuConfirmInput();
}

void func_020dca80(void) {
    void MatchingMenuConfirmInput();
    MatchingMenuConfirmInput();
}

M2C_UNK func_020dca8c(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

M2C_UNK func_020dcae8(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

void func_020dcb44(void) {
    M2C_UNK func_020dca8c();
    func_020dca8c();
}

void func_020dcb50(void) {
    M2C_UNK func_020dca8c();
    func_020dca8c();
}

void func_020dcb5c(void) {
    M2C_UNK func_020dcae8();
    func_020dcae8();
}

void func_020dcb68(void) {
    M2C_UNK func_020dcae8();
    func_020dcae8();
}

/* Set up the matching/link menu: configure the 3D sprite bank, build the five
   list rows, refresh the selection bars of the current row and initialise the
   row's sprite animation. */
void SetupMatchingMenu(void *entity) {
extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
extern M2C_UNK gLinkPath, gMatchingNarcName, gMatchingScName, gMatchRowTemplate, gMatchWideRowTemplate;
M2C_UNK func_01ff9ce8(s32), SetFileDirectory(void *);
s32 GetLocalizedFileName(void *);
M2C_UNK OpenNarcArchive(void), CloseNarcArchive(void);
M2C_UNK LoadNarcFileDecompressed(s32,s32), func_02080944(s32,s32,s32,s32);
s32 func_020b20e0(s32);
void *func_020b22a4(s32,s32,void *,s32), *func_020b1c78(s32);
M2C_UNK func_020808dc(s32,s32,u16,u16);
void PlaySoundEffect(s32);
M2C_UNK func_020b1c44(s32,s32);
M2C_UNK func_02088f1c(void *), func_0208b758(void *,s32);
s16 GetSpriteAnimValue(void *);
void func_ov009_02224560(s32,s32,s32);
s32 row, rowX, bar;
void *selectedRow;
s32 barX, barEnd, barColor, hasRows;
void **savedEngine;
void *panel;
void **savedBarEngine;
void *sprite;
u8 selectedId;

savedEngine = gCur3DSpriteEngine;
gCur3DSpriteEngine = g3DSpriteEngineMain;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
SetFileDirectory(&gLinkPath);
GetLocalizedFileName(&gMatchingNarcName);
OpenNarcArchive();
LoadNarcFileDecompressed(GetLocalizedFileName(&gMatchingScName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
CloseNarcArchive();
func_02080944(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 32, 24, 5);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
gCur3DSpriteEngine = savedEngine;
M2C_FIELD(entity, u16 *, 0x48) |= 32;
if (func_020b20e0(0) == 0) hasRows = 1; else hasRows = 0;
if (hasRows) {
    row = 0; rowX = 0;
    do {
        sprite = func_020b22a4(0, rowX, &gMatchRowTemplate, row);
        row++;
        M2C_FIELD(sprite, void **, 0x10) = entity;
        rowX += 0x28;
    } while (row < 4);
}
sprite = func_020b22a4(0, 0, &gMatchWideRowTemplate, 4);
M2C_FIELD(sprite, void **, 0x10) = entity;
selectedRow = func_020b1c78(M2C_FIELD(entity, s8 *, 0x43));
if (selectedRow) {
    panel = M2C_FIELD(selectedRow, void **, 0x10);
    savedBarEngine = gCur3DSpriteEngine;
    barX = 1;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    barEnd = 5;
    bar = 0;
    do {
        if (M2C_FIELD(selectedRow, u8 *, 0) != bar) barColor = 5; else barColor = 6;
        func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20) + 2 + (barX << 6), 30, (u16)(barEnd - barX), (u16)barColor);
        bar++;
        barX = (s16)(barX + 5);
        barEnd = (s16)(barEnd + 5);
    } while (bar < 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = savedBarEngine;
    selectedId = M2C_FIELD(selectedRow, u8 *, 0);
    if (M2C_FIELD(panel, s8 *, 0x43) != selectedId) {
        M2C_FIELD(panel, s8 *, 0x43) = selectedId;
        PlaySoundEffect(0x10019);
    }
}
func_020b1c44(0, 0);
sprite = M2C_FIELD(entity, void **, 0x50);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x50);
func_020dcc00(sprite);
M2C_FIELD(sprite,u8 *,0x5a)=0;
sprite = M2C_FIELD(entity, void **, 0x58);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x58);
func_020dcc00(sprite);
M2C_FIELD(sprite,u8 *,0x5a)=0;
func_0208b758(M2C_FIELD(entity, void **, 0x64), 0x44000010);
func_02088f1c(M2C_FIELD(entity, void **, 0x64));
if (GetSpriteAnimValue(M2C_FIELD(entity, void **, 0x68))) {
    s16 result = GetSpriteAnimValue(M2C_FIELD(entity, void **, 0x68));
    sprite = M2C_FIELD(entity, void **, 0x68);
    M2C_FIELD(sprite, u16 *, 0xe) = result;
    M2C_FIELD(sprite, u16 *, 0x10) = 0;
    M2C_FIELD(sprite, u16 *, 0xc) = 12;
    M2C_FIELD(sprite, u16 *, 2) = M2C_FIELD(sprite, u16 *, 4);
sprite = M2C_FIELD(entity, void **, 0x5c);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x5c);
if(SpriteAvailable(sprite))SetSpriteFrame(sprite,SpriteBase(sprite),0);
else SetSpriteFrame(sprite,SpriteBase(sprite)+2,0);
} else {
sprite = M2C_FIELD(entity, void **, 0x5c);
{s16 py=M2C_FIELD(sprite,s16 *,0x52); s16 px=M2C_FIELD(sprite,s16 *,0x50); M2C_FIELD(sprite,s16 *,0x34)=px; M2C_FIELD(sprite,s16 *,0x36)=py;}
sprite = M2C_FIELD(entity, void **, 0x5c);
if(SpriteAvailable(sprite))SetSpriteFrame(sprite,SpriteBase(sprite),0);
else SetSpriteFrame(sprite,SpriteBase(sprite)+2,0);
}
M2C_FIELD(entity, u16 *, 0x48) &= ~0x2;
M2C_FIELD(entity,s8 *,0x41)=0;
func_ov009_02224560(0,0,0);
}

void func_020dd004(void) {

}

/* Builds the alternate matching/link menu: configures the 3D sprite bank and its
   files, creates the five list rows, redraws the selection bars of the current
   row and resets that row's sprite animation. */
void SetupMatchingMenuAlt(void *entity) {
extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
extern M2C_UNK gLinkPathAlt, gMatchingNarcNameAlt, gMatchingScNameAlt, gMatchRowTemplate, gMatchWideRowTemplate;
M2C_UNK func_01ff9ce8(s32), SetFileDirectory(void *);
s32 GetLocalizedFileName(void *);
M2C_UNK OpenNarcArchive(void), CloseNarcArchive(void);
M2C_UNK LoadNarcFileDecompressed(s32,s32), func_02080944(s32,s32,s32,s32);
s32 func_020b20e0(s32);
void *func_020b22a4(s32,s32,void *,s32), *func_020b1c78(s32);
M2C_UNK func_020808dc(s32,s32,u16,u16);
void PlaySoundEffect(s32);
M2C_UNK func_020b1c44(s32,s32);
M2C_UNK func_02088f1c(void *), func_0208b758(void *,s32);
s16 GetSpriteAnimValue(void *);
void func_ov009_02224560(s32,s32,s32);
s32 row, rowX, bar;
void *selectedRow;
s32 barX, barEnd, barColor, hasRows;
void **savedEngine;
void *panel;
void **savedBarEngine;
void *sprite;
u8 selectedId;

savedEngine = gCur3DSpriteEngine;
gCur3DSpriteEngine = g3DSpriteEngineMain;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
SetFileDirectory(&gLinkPathAlt);
GetLocalizedFileName(&gMatchingNarcNameAlt);
OpenNarcArchive();
LoadNarcFileDecompressed(GetLocalizedFileName(&gMatchingScNameAlt), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
CloseNarcArchive();
func_02080944(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 32, 24, 5);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
gCur3DSpriteEngine = savedEngine;
M2C_FIELD(entity, u16 *, 0x48) |= 32;
if (func_020b20e0(0) == 0) hasRows = 1; else hasRows = 0;
if (hasRows) {
    row = 0; rowX = 0;
    do {
        sprite = func_020b22a4(0, rowX, &gMatchRowTemplate, row);
        row++;
        M2C_FIELD(sprite, void **, 0x10) = entity;
        rowX += 0x28;
    } while (row < 4);
}
sprite = func_020b22a4(0, 0, &gMatchWideRowTemplate, 4);
M2C_FIELD(sprite, void **, 0x10) = entity;
selectedRow = func_020b1c78(M2C_FIELD(entity, s8 *, 0x43));
if (selectedRow) {
    panel = M2C_FIELD(selectedRow, void **, 0x10);
    savedBarEngine = gCur3DSpriteEngine;
    barX = 1;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    barEnd = 5;
    bar = 0;
    do {
        if (M2C_FIELD(selectedRow, u8 *, 0) != bar) barColor = 5; else barColor = 6;
        func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20) + 2 + (barX << 6), 30, (u16)(barEnd - barX), (u16)barColor);
        bar++;
        barX = (s16)(barX + 5);
        barEnd = (s16)(barEnd + 5);
    } while (bar < 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = savedBarEngine;
    selectedId = M2C_FIELD(selectedRow, u8 *, 0);
    if (M2C_FIELD(panel, s8 *, 0x43) != selectedId) {
        M2C_FIELD(panel, s8 *, 0x43) = selectedId;
        PlaySoundEffect(0x10019);
    }
}
func_020b1c44(0, 0);
sprite = M2C_FIELD(entity, void **, 0x50);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x50);
func_020dcc00(sprite);
M2C_FIELD(sprite,u8 *,0x5a)=0;
sprite = M2C_FIELD(entity, void **, 0x58);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x58);
func_020dcc00(sprite);
M2C_FIELD(sprite,u8 *,0x5a)=0;
func_0208b758(M2C_FIELD(entity, void **, 0x64), 0x44000010);
func_02088f1c(M2C_FIELD(entity, void **, 0x64));
if (GetSpriteAnimValue(M2C_FIELD(entity, void **, 0x68))) {
    s16 result = GetSpriteAnimValue(M2C_FIELD(entity, void **, 0x68));
    sprite = M2C_FIELD(entity, void **, 0x68);
    M2C_FIELD(sprite, u16 *, 0xe) = result;
    M2C_FIELD(sprite, u16 *, 0x10) = 0;
    M2C_FIELD(sprite, u16 *, 0xc) = 12;
    M2C_FIELD(sprite, u16 *, 2) = M2C_FIELD(sprite, u16 *, 4);
sprite = M2C_FIELD(entity, void **, 0x5c);
func_02088f1c(sprite);
sprite = M2C_FIELD(entity, void **, 0x5c);
if(SpriteAvailable(sprite))SetSpriteFrame(sprite,SpriteBase(sprite),0);
else SetSpriteFrame(sprite,SpriteBase(sprite)+2,0);
} else {
sprite = M2C_FIELD(entity, void **, 0x5c);
{s16 py=M2C_FIELD(sprite,s16 *,0x52); s16 px=M2C_FIELD(sprite,s16 *,0x50); M2C_FIELD(sprite,s16 *,0x34)=px; M2C_FIELD(sprite,s16 *,0x36)=py;}
sprite = M2C_FIELD(entity, void **, 0x5c);
if(SpriteAvailable(sprite))SetSpriteFrame(sprite,SpriteBase(sprite),0);
else SetSpriteFrame(sprite,SpriteBase(sprite)+2,0);
}
M2C_FIELD(entity, u16 *, 0x48) &= ~0x2;
M2C_FIELD(entity,s8 *,0x41)=0;
}

void func_020dd48c(void) {
    void SetupMatchingMenuAlt();
    SetupMatchingMenuAlt();
}

void func_020dd498(void) {
    void SetupMatchingMenu();
    SetupMatchingMenu();
}

void func_020dd4a4(void) {
    void SetupMatchingMenu();
    SetupMatchingMenu();
}

void func_020dd4b0(void) {
    func_020dd004();
}

void func_020dd4bc(void) {
    func_020dd004();
}

void func_020dd4c8(void) {
    void SetupMatchingMenuAlt();
    SetupMatchingMenuAlt();
}

void func_020dd4d4(void) {
    void SetupMatchingMenuAlt();
    SetupMatchingMenuAlt();
}

void func_020dd4e0(void) {
    func_020dd48c();
}

void func_020dd4ec(void) {
    func_020dd48c();
}

