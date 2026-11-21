/* 19 functions from 0x020D9A98 to 0x020DAA90 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* Tear down a screen entity: run the cleanup for its driver type (+0x34/+0x38),
   reset the sprite bank of both 3D engines, release the entity's five sprite
   objects, and reset the engine scroll offsets. */
void TeardownEntity(void *a) {
void Link_SetMessageHandler(s32);s32 func_ov009_02224508(s32);s32 GetLinkPhase(void);void Link_InstallCommandHandler(void);void func_ov009_02225b54(s32);void func_02084eec(s32);void EnableMapConfirm(void);M2C_UNK ResetPlayerMask(void);M2C_UNK DisableMapConfirm(void);s32 IsOnlineSessionFlagSet(s32);void CreateVoiceChatWidget(s32);void func_020b2178(void);void DeleteSpriteObject(s32);M2C_UNK SetSpriteSlotScroll(s32,s32);
extern void **gCur3DSpriteEngine,**g3DSpriteEngineSub,**g3DSpriteEngineMain;
s32 i;void **savedEngine;u16 *volatile bank10;u16 *volatile bank20;u16 *volatile bank40;u16 *volatile bank80;u16 *volatile bank100;u16 *volatile oamAttr;
Link_SetMessageHandler(0);
switch(M2C_FIELD(a,s32 *,0x34)){
case 0:
if(!func_ov009_02224508(1)&&(GetLinkPhase()==4||GetLinkPhase()==5)&&!(M2C_FIELD(a,u16 *,0x48)&0x1000)){
Link_InstallCommandHandler();func_ov009_02225b54(M2C_FIELD(a,s32 *,0x18));func_02084eec(M2C_FIELD(a,s32 *,0x18));EnableMapConfirm();
}else {if(M2C_FIELD(a,u16 *,0x48)&0x1000)ResetPlayerMask();DisableMapConfirm();}break;
case 1:case 2:
if(!IsOnlineSessionFlagSet(6)&&IsOnlineSessionFlagSet(3)&&!(M2C_FIELD(a,u16 *,0x48)&0x1000)){
if(M2C_FIELD(a,s32 *,0x34)==2&&M2C_FIELD(a,s32 *,0x38)==0)CreateVoiceChatWidget(7);
Link_InstallCommandHandler();func_02084eec(M2C_FIELD(a,s32 *,0x18));EnableMapConfirm();
}else {if(M2C_FIELD(a,u16 *,0x48)&0x1000)ResetPlayerMask();DisableMapConfirm();}break;
}
savedEngine=gCur3DSpriteEngine;
for(i=0;i<2;i++){
gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
bank10=(u16 *)*gCur3DSpriteEngine;*bank10=*bank10&~0x10;
bank20=(u16 *)*gCur3DSpriteEngine;*bank20=*bank20&~0x20;
bank40=(u16 *)*gCur3DSpriteEngine;*bank40=*bank40|0x40;
bank80=(u16 *)*gCur3DSpriteEngine;*bank80=*bank80&~0x80;
bank100=(u16 *)*gCur3DSpriteEngine;*bank100=*bank100|0x100;
oamAttr=(u16 *)((u8 *)*gCur3DSpriteEngine+0x12);*oamAttr=*oamAttr&~0xc0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=0;M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x53)=0;
}
gCur3DSpriteEngine=savedEngine;func_020b2178();
if(M2C_FIELD(a,s32 *,0x50)){DeleteSpriteObject(M2C_FIELD(a,s32 *,0x50));M2C_FIELD(a,s32 *,0x50)=0;}
if(M2C_FIELD(a,s32 *,0x54)){DeleteSpriteObject(M2C_FIELD(a,s32 *,0x54));M2C_FIELD(a,s32 *,0x54)=0;}
if(M2C_FIELD(a,s32 *,0x58)){DeleteSpriteObject(M2C_FIELD(a,s32 *,0x58));M2C_FIELD(a,s32 *,0x58)=0;}
if(M2C_FIELD(a,s32 *,0x5c)){DeleteSpriteObject(M2C_FIELD(a,s32 *,0x5c));M2C_FIELD(a,s32 *,0x5c)=0;}
if(M2C_FIELD(a,s32 *,0x60)){DeleteSpriteObject(M2C_FIELD(a,s32 *,0x60));M2C_FIELD(a,s32 *,0x60)=0;}
SetSpriteSlotScroll(0,0);
}

void func_020d9d5c(void *arg0) {
    M2C_UNK SetSpriteAnimation(void *, u8);
    s32 IsMapConfirmEnabled();
    if (IsMapConfirmEnabled() != 0) {
        return;
    }
    SetSpriteAnimation(arg0, M2C_FIELD(arg0, u8 *, 0x40));
}

/* Draw four 5-wide progress bars (level rows 1/6/11/16) onto the UI screen,
   mark it dirty, then update the cached entry id if it changed. */
void func_020d9d80(void *entry) {
    M2C_UNK SetTileRectPalette(u16 *, s32, s32, u32);
    M2C_UNK PlaySoundEffect(s32);
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    void *panel;
    void **savedEngine;
    s32 i;
    s32 col;
    s32 levelEnd;

    panel = M2C_FIELD(entry, void **, 0x10);
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;

    col = 1;
    levelEnd = 5;
    i = 0;
    do {
        SetTileRectPalette((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 2 + (col << 6)),
                      0x1e,
                      (s32)(u16)(levelEnd - col),
                      (u32)(u16)(M2C_FIELD(entry, u8 *, 0) != i ? 5 : 6));
        { s32 nextCol = col + 5; s32 nextEnd = levelEnd + 5; i++; col = (s16)nextCol; levelEnd = (s16)nextEnd; }
    } while (i < 4);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = savedEngine;

    if ((s8)M2C_FIELD(panel, s8 *, 0x43) != M2C_FIELD(entry, u8 *, 0)) {
        M2C_FIELD(panel, s8 *, 0x43) = M2C_FIELD(entry, u8 *, 0);
        PlaySoundEffect(0x10019);
    }
}

void func_020d9e7c(void *arg0){extern s32 gUnitSlotIds[]; s32 temp_r2; u16 temp_r3; void *temp_r4;
temp_r4=M2C_FIELD(arg0,void**,0x10); temp_r3=M2C_FIELD(temp_r4,u16*,0x48);
if(temp_r3&0x20)return; temp_r2=temp_r3&2; if(temp_r2!=0)return;
if(gUnitSlotIds[M2C_FIELD(arg0,u8*,0)]<0)return; if(temp_r2!=0)return;
M2C_FIELD(temp_r4,u16*,0x48)=temp_r3&~1;
M2C_FIELD(temp_r4,u16*,0x48)=M2C_FIELD(temp_r4,u16*,0x48)|2;
PlaySoundEffect(0x1000D); Sprite_ResumeAnimation(temp_r4);}

void func_020d9ee4(u8 *arg0){M2C_UNK FocusSpriteSlotById(); extern void *gKeyState; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(gKeyState,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(gKeyState,u16*,0); if(temp_r1&0x40){if(temp_r3==0){if(temp_r2&0x40)var_r0=4;}else var_r0=temp_r3-1;}else if(temp_r1&0x80) var_r0=temp_r3+1; if(var_r0==temp_r3) return; FocusSpriteSlotById(var_r0); }

#pragma scheduling off
/* Draw the option widget's four 5-wide progress bars (columns 1/6/11/16) onto
   the UI screen in one flat palette, mark the sprite layer dirty, then cache the
   widget's selected value; play the cursor sound when it changed. */
void DrawOptionProgressBars(void *entry) {
 M2C_UNK SetTileRectPalette(u16 *,s32,s32,u32);
 M2C_UNK PlaySoundEffect(s32);
 extern void **gCur3DSpriteEngine;
 extern void **g3DSpriteEngineMain;
 void *panel; void **savedEngine; s32 i,col,levelEnd;
 panel=M2C_FIELD(entry,void **,0x10);
 savedEngine=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
 col=1; levelEnd=5; i=0;
 do {
 SetTileRectPalette((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x20)+2+(col<<6)),30,(u16)(levelEnd-col),5);
 {s32 nextCol=col+5; s32 nextEnd=levelEnd+5; i++; col=(s16)nextCol; levelEnd=(s16)nextEnd;}
 }while(i<4);
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
 gCur3DSpriteEngine=savedEngine;
 if(M2C_FIELD(panel,s8 *,0x43)!=M2C_FIELD(entry,u8 *,0)){
 M2C_FIELD(panel,s8 *,0x43)=M2C_FIELD(entry,u8 *,0); PlaySoundEffect(0x10019);
 }
}
#pragma scheduling reset
/* Takes the menu's second option: if the menu is still idle, presses the option's
 * sprite (frame +1 for 12 frames), records the second option as chosen and plays
 * the confirm sound with the menu's close animation. */
void ConfirmMenuOption(void *entry) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK Sprite_ResumeAnimation(void *);
    u16 state;
    u16 stateAfterPress;
    void *pressSprite;
    void *menu;

    menu = M2C_FIELD(entry, void **, 0x10);
    state = M2C_FIELD(menu, u16 *, MENU_STATE);
    if (state & MENU_STATE_ACCEPTED) {
        return;
    }
    if (state & MENU_STATE_CHOSEN) {
        return;
    }
    pressSprite = M2C_FIELD(menu, void **, MENU_PRESS_SPRITE);
    if ((s32) M2C_FIELD(pressSprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
        M2C_FIELD(pressSprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(pressSprite, s32 *, MENU_SPRITE_FRAME) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(pressSprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(pressSprite, s8 *, MENU_SPRITE_TIMER) = 0xC;
    }
    stateAfterPress = M2C_FIELD(menu, u16 *, MENU_STATE);
    if (stateAfterPress & MENU_STATE_CHOSEN) {
        return;
    }
    M2C_FIELD(menu, u16 *, MENU_STATE) = (u16) (stateAfterPress | MENU_STATE_OPTION);
    M2C_FIELD(menu, u16 *, MENU_STATE) = (u16) (M2C_FIELD(menu, u16 *, MENU_STATE) | MENU_STATE_CHOSEN);
    PlaySoundEffect(0x1000D); /* SOUND_MENU_CONFIRM */
    Sprite_ResumeAnimation(menu);
}

void func_020da0a0(u8 *arg0){M2C_UNK FocusSpriteSlotById(); extern void *gKeyState; u16 temp_r1; u16 temp_r2; u8 temp_r3; s32 var_r0;
temp_r3=*arg0; temp_r1=M2C_FIELD(gKeyState,u16*,2); var_r0=temp_r3; temp_r2=M2C_FIELD(gKeyState,u16*,0); if(temp_r1&0x40)var_r0=temp_r3-1;else if((temp_r1&0x80)&&(temp_r2&0x80))var_r0=0; if(var_r0==temp_r3) return; FocusSpriteSlotById(var_r0); }

// Draws two 5-step progress bars (levels x/y growing by 5) onto a UI screen, then marks it dirty.
void func_020da0ec(void *a) {
    M2C_UNK SetTileRectPalette(u16 *, s32, s32, u32);
    M2C_UNK PlaySoundEffect(s32);
    extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    void *p = M2C_FIELD(a, void **, 0x10);
    void **saved = gCur3DSpriteEngine;
    s32 i, x, y;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    x = 10;
    y = 14;
    i = 0;
    do {
        SetTileRectPalette((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 8 + (x << 6)),
                      24,
                      (u16)(y - x),
                      (u16)(M2C_FIELD(a, u8 *, 0) != i ? 7 : 8));
        { s32 nx = x + 5; s32 ny = y + 5; i++; x = (s16)nx; y = (s16)ny; }
    } while (i < 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = saved;
    if (M2C_FIELD(a, u8 *, 0) != M2C_FIELD(p, s32 *, 0x3c)) {
        M2C_FIELD(p, s32 *, 0x3c) = M2C_FIELD(a, u8 *, 0);
        PlaySoundEffect(0x10019);
    }
}

void func_020da1e8(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    s32 temp_r0_2;
    u16 temp_r0;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0 & 0x20) {
        return;
    }
    temp_r0_2 = temp_r0 & 4;
    if ((temp_r0_2 == 0) && (temp_r0_2 == 0)) {
        PlaySoundEffect(0x1000E);
        M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x48) | 4);
        Sprite_ResumeAnimation(temp_r4);
    }
}

/* Moves the focus between the two options of a toggle widget on an up or down
 * key repeat, wrapping from the first or last option only on a fresh press (not
 * on auto-repeat), and focuses the newly selected option's sprite. */
void HandleToggleOptionFocus(u8 *option) {
    M2C_UNK FocusSpriteSlotById();
    extern void *gKeyState;
    u16 repeat;
    u16 pressed;
    u8 selection;
    s32 next;

    selection = *option;
    repeat = M2C_FIELD(gKeyState, u16 *, 2);      /* KeyState::repeat */
    next = selection;
    pressed = M2C_FIELD(gKeyState, u16 *, 0);     /* KeyState::pressed */
    if (repeat & KEY_UP) {
        if (selection == 0) {
            if (pressed & KEY_UP) next = 1;
        } else next = selection - 1;
    } else if (repeat & KEY_DOWN) {
        if (selection == 1) {
            if (pressed & KEY_DOWN) next = 0;
        } else next = selection + 1;
    }
    if (next == selection) return;
    FocusSpriteSlotById(next);
}

/* Two-option menu entry: draws its two 5-step bars with the selected one in the
   brighter palette, then mirrors the selection into bit 2 of the local player's
   network status while the Wi-Fi overlay is up. Plays the cursor sound on a change. */
void UpdateToggleOption(void *entry) {
    M2C_UNK SetTileRectPalette(u16 *, s32, s32, u32);
    M2C_UNK PlaySoundEffect(s32);
    extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    s32 GetActiveOverlay(void); void *GetLocalPlayerStatus(void); s32 current; void *status;
    void **saved = gCur3DSpriteEngine;
    s32 i, x, y;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    x = 10;
    y = 14;
    i = 0;
    do {
        SetTileRectPalette((u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0x20) + 8 + (x << 6)),
                      24,
                      (u16)(y - x),
                      (u16)(M2C_FIELD(entry, u8 *, 0) != i ? 7 : 8));
        { s32 nx = x + 5; s32 ny = y + 5; i++; x = (s16)nx; y = (s16)ny; }
    } while (i < 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = saved;

    if (GetActiveOverlay() == 2) current = (M2C_FIELD(GetLocalPlayerStatus(), u8 *, 0x1a) & 4) ? 1 : 0;
    else current = 0;
    { s32 selected = M2C_FIELD(entry, u8 *, 0); if (selected == current) return; current = selected; }

    if (GetActiveOverlay() == 2) {
        status = GetLocalPlayerStatus();
        if (current == 1) M2C_FIELD(status, u8 *, 0x1a) |= 4;
        else M2C_FIELD(status, u8 *, 0x1a) &= ~4;
    }
    PlaySoundEffect(0x10019);
}

void func_020da3c8(void *arg0) {
    s32 temp_r0_2;
    u16 temp_r0;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_r0 & 0x20) {
        return;
    }
    temp_r0_2 = temp_r0 & 8;
    if ((temp_r0_2 == 0) && (temp_r0_2 == 0)) {
        PlaySoundEffect(0x1000E);
        M2C_FIELD(temp_r4, u16 *, 0x48) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x48) | 8);
        Sprite_ResumeAnimation(temp_r4);
    }
}

/* Key handler for a two-option list: up/down move the focus to the other option,
 * wrapping past an end only on a fresh press; the option's sprite slot follows. */
void HandleTwoOptionListInput(u8 *option) {
    M2C_UNK FocusSpriteSlotById();
    extern void *gKeyState;
    u16 repeat;
    u16 pressed;
    u8 selection;
    s32 next;

    selection = *option;
    repeat = M2C_FIELD(gKeyState, u16 *, 2);      /* KeyState::repeat */
    next = selection;
    pressed = M2C_FIELD(gKeyState, u16 *, 0);     /* KeyState::pressed */
    if (repeat & KEY_UP) {
        if (selection == 0) {
            if (pressed & KEY_UP) next = 1;
        } else next = selection - 1;
    } else if (repeat & KEY_DOWN) {
        if (selection == 1) {
            if (pressed & KEY_DOWN) next = 0;
        } else next = selection + 1;
    }
    if (next == selection) return;
    FocusSpriteSlotById(next);
}

#pragma push
#pragma opt_schedule off
void func_020da480(void *arg0) {
    M2C_UNK ResetPlayerMask(void);
    M2C_UNK func_02086330(void);
    M2C_UNK Configure3DSpriteLayer(M2C_UNK, void *);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK SetFileDirectory(void *);
    M2C_UNK GetLocalizedFileName(void *);
    M2C_UNK OpenNarcArchive(M2C_UNK);
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK, void *);
    M2C_UNK LoadFileToSpriteBuffer(void *, M2C_UNK, M2C_UNK);
    M2C_UNK CloseNarcArchive(void);
    M2C_UNK GetUiColor(M2C_UNK);
    M2C_UNK Load3DSpritePattern(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff9dd8(M2C_UNK);
    M2C_UNK DisableMapConfirm(void);
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    extern void *g3DSpriteBankMain;
    extern u8 data_0212c5f2[];
    extern u8 data_0212c5f0[];
    extern u8 data_0212d1f4[];
    extern u8 data_0212d1fc[];
    extern u8 data_0212d20c[];
    extern u8 data_0212d218[];
    extern u8 data_0212d224[];
    extern u8 data_0212d234[];
    extern void **g3DSpriteEngineSub;

    void *savedEngine;
    void *unitStruct;
    void *tmpPtr;
    M2C_UNK r0v;
    u8 displayMode;

    ResetPlayerMask();
    func_02086330();

    unitStruct = *(void **)((u8 *)arg0 + 0x68);
    *(u16 *)((u8 *)unitStruct + 0xe) = 0;
    *(u16 *)((u8 *)unitStruct + 0x10) = 0;
    *(u16 *)((u8 *)unitStruct + 0xc) = 0xc;
    *(u16 *)((u8 *)unitStruct + 0x2) = *(u16 *)((u8 *)unitStruct + 0x4);

    tmpPtr = g3DSpriteBankMain;
    *(u16 *)tmpPtr = (u16)(*(u16 *)tmpPtr & ~0x8);

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;

    Configure3DSpriteLayer(1, data_0212c5f2);
    Configure3DSpriteLayer(0, data_0212c5f0);

    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x10);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x20);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x40);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags & ~0x80);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x100);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
        *flags = (u16)(*flags & ~0xc0);
    }
    ((u8 *)*gCur3DSpriteEngine)[0x51] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x52] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x53] = 0;
    displayMode = ((volatile u8 *)gCur3DSpriteEngine)[0x46];
    r0v = 9;
    ((volatile u8 *)gCur3DSpriteEngine)[0x46] = displayMode | 2;

    LoadScenePanelPalette(r0v);
    Clear3DSpriteLayer(0);
    SetFileDirectory(data_0212d1f4);
    r0v = GetLocalizedFileName(data_0212d1fc);
    OpenNarcArchive(r0v);
    LoadNarcFileDecompressed(GetLocalizedFileName(data_0212d20c), *(void **)((u8 *)gCur3DSpriteEngine + 0xc));

    LoadFileToSpriteBuffer(data_0212d218, 0xa0, 0x80);
    ((u8 *)gCur3DSpriteEngine)[0x46] |= 1;

    r0v = GetLocalizedFileName(data_0212d224);
    LoadNarcFileDecompressed(r0v, (void *)((u8 *)*(void **)((u8 *)gCur3DSpriteEngine + 0x1c) + 0x7100));

    LoadFileToSpriteBuffer(data_0212d234, 0x2c0, 0x20);
    CloseNarcArchive();
    r0v = GetUiColor(9);
    Load3DSpritePattern(0x1000, 1, r0v, 2);

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags & ~0x10);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags & ~0x20);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x40);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags & ~0x80);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine);
        *flags = (u16)(*flags | 0x100);
    }
    {
        u16 *volatile flags = (u16 *)((u8 *)*gCur3DSpriteEngine + 0x12);
        *flags = (u16)(*flags & ~0xc0);
    }
    ((u8 *)*gCur3DSpriteEngine)[0x51] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x52] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x53] = 0;

    Clear3DSpriteLayer(0);
    func_01ff9dd8(0);
    gCur3DSpriteEngine = savedEngine;
    DisableMapConfirm();
}
#pragma pop
void func_020da8e4(s32,void *);
void HandleOnlineLinkResult(s32,M2C_UNK,u32,void *);
/* Dispatch an entity's driver based on its type field (+0x34) and sub-state (+0x38). */
void func_020da7e8(void *entity) {
    void func_020da8e4(s32, void *);
    void HandleOnlineLinkResult(s32, M2C_UNK, u32, void *);

    switch (M2C_FIELD(entity, s32 *, 0x34)) {
    case 0:
        func_ov009_02225d88(func_020da8e4, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: SetSpriteAnimation(entity, 6); break;
        case 1: SetSpriteAnimation(entity, 7); break;
        }
        break;
    case 1:
        func_ov010_0222a20c(HandleOnlineLinkResult, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: SetSpriteAnimation(entity, 2); break;
        case 1: SetSpriteAnimation(entity, 17); break;
        }
        break;
    case 2:
        func_ov010_0222a20c(HandleOnlineLinkResult, entity);
        switch (M2C_FIELD(entity, s32 *, 0x38)) {
        case 0: SetSpriteAnimation(entity, 12); break;
        case 1: SetSpriteAnimation(entity, 13); break;
        }
        break;
    }
}

void func_020da8e4(s32 arg0, void *arg1) {
    s32 GetScreenFlag(u8);
    s32 IsScreenFadeActive();
    M2C_UNK DisableMapConfirm();
    M2C_UNK CreateLinkStatusLabel(s8, u16, s32, void *);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    if ((GetScreenFlag(M2C_FIELD(arg1, u8 *, 0x44)) == 1) || (IsScreenFadeActive() != 0)) {
        Ov010Online_ClearStepFlag(6);
        return;
    }
    if (arg0 == 0) {
        return;
    }
    CreateLinkStatusLabel((s8) M2C_FIELD(arg1, u8 *, 0x44), M2C_FIELD(arg1, u16 *, 0x46), arg0, arg1);
    DisableMapConfirm();
    SetSpriteAnimation(arg1, 1);
}

/* Online session result callback: when the menu state no longer allows the link
 * (or a dialog is open) clear the link step flag; otherwise report the network
 * error into the session's result object and react to its class - the quiet
 * classes clear the session step flag, a connection failure starts the error
 * animation, and a cancel is ignored. */
void HandleOnlineLinkResult(s32 netError, M2C_UNK errorParam, u32 errorClass, void *entity) {
    s32 GetScreenFlag(u8);
    s32 IsScreenFadeActive(void);
    M2C_UNK func_ov009_02224528(M2C_UNK);
    void func_ov010_02228320(void);
    M2C_UNK CreateNetErrorSprite(s8, u16, s32, M2C_UNK, u32, void *);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    M2C_UNK DisableMapConfirm(void);
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);

    if (GetScreenFlag(M2C_FIELD(entity, u8 *, 0x44)) == 1 || IsScreenFadeActive() != 0) {
        func_ov009_02224528(1); return;
    }
    if (netError == 0) return;
    CreateNetErrorSprite(M2C_FIELD(entity, s8 *, 0x44), M2C_FIELD(entity, u16 *, 0x46), netError, errorParam, errorClass, entity);
    func_ov010_02228320();
    switch (errorClass) {
    case 0: case 1: case 2: Ov010Online_ClearStepFlag(6); return;
    case 3: case 4: case 5: case 6: DisableMapConfirm(); SetSpriteAnimation(entity, 1); return;
    case 7: default: return;
    }
}

void UpdateMainEngineMapScroll(void *scrollEffect) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK SetSpriteSlotScroll(s32, M2C_UNK);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    s32 scrollValue;
    u16 inverseScroll;
    void **savedEngine;

    /* Animate the main engine's scroll offset and apply the matching sprite-bank offset. */
    UpdateSpriteAnimation(M2C_FIELD(scrollEffect, s32 *, 0x68));
    scrollValue = GetSpriteAnimValue(M2C_FIELD(scrollEffect, s32 *, 0x68));
    SetSpriteSlotScroll(scrollValue, 0);
    savedEngine = gCur3DSpriteEngine;
    inverseScroll = 0 - scrollValue;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, DS3D_SCROLL_LAYER_Y) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_Y) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, DS3D_SCROLL_LAYER_X) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_X) = 0;
    gCur3DSpriteEngine = savedEngine;
}

