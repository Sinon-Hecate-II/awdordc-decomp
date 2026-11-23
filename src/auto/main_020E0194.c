/* 48 functions from 0x020E0194 to 0x020E0F14 (main), found by ds-decomp. */
#include "common.h"
M2C_UNK func_020e0e8c();
M2C_UNK CloseLinkMenu();
M2C_UNK CloseOnlineMenu();
typedef struct { unsigned char value:4; } E0194Bits;
typedef struct { u32 low:18; u32 value:8; u32 high:6; } E0B04Bits;
static inline s32 E0B04Process(void *entity) {
s32 IsLinkSessionActive(void);s32 func_0208477c(void);s32 GetOverlayEventFlags(void);
s32 FindTextLayer(void); M2C_UNK StartWindowClose(void);void *CreateTextLayer(void *);
M2C_UNK RenderTextLayerMessage(void *,s32,s32,s32);
extern s32 g3DSpriteEngineMain,g3DSpriteEngineSub,gCur3DSpriteEngine;
void *created; s32 bank; register s32 i; s32 saved; u8 mode;
if(!IsLinkSessionActive())return 0;
if(func_0208477c())return 0;
if(GetOverlayEventFlags()){
M2C_FIELD(entity,u16 *,0x48)|=0x1000;
if(FindTextLayer())StartWindowClose();
saved=gCur3DSpriteEngine;i=0;
do{
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,u8 *,0x44);
if(mode==0&&bank!=g3DSpriteEngineMain)goto next;
if(mode==1&&bank!=g3DSpriteEngineSub)goto next;
if(mode==3&&bank!=saved)goto next;
created=CreateTextLayer(entity);
RenderTextLayerMessage(created,2,M2C_FIELD(entity,u16 *,0x46)<<5,0x44000001);
M2C_FIELD(created,u32 *,0x58)|=0x1000;
next: ++i;
}while(i<2);
gCur3DSpriteEngine=saved;return 1;
}
return 0;

}
static inline u32 func_020e_low(void *p) { return M2C_FIELD(p,E0194Bits*,0x59).value; }
static inline u16 func_020e_get_value(void *p) { return (M2C_FIELD(p,u32*,0x40)<<6)>>24; }
static inline u8 func_020e_check(void *p) { return func_020e_low(p)+2 != func_020e_get_value(p); }

M2C_UNK func_ov010_022294ec();
M2C_UNK func_ov010_02228c88();
M2C_UNK func_ov009_02225348();
M2C_UNK Hide3DSpriteSlide();
s32 Is3DSpriteVisible();
s16 GetSpriteAnimValue();
/* Close a link-lobby menu: create the link overlay's companion object, hide the
 * menu's button and child sprites and start the panel's slide-out tween (from the
 * current animation value down to -255 over 12 frames).  Returns the tween's
 * start value. */
M2C_UNK CloseLinkMenu(void *menu) {
    void *button;
    s16 value;
    SpriteTween *slide;
    u16 start;

    func_ov009_02225348();
    button = M2C_FIELD(menu, void **, 0x54);
    if (func_020e_check(button)) Hide3DSpriteSlide(button);
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x58));
    if (Is3DSpriteVisible(M2C_FIELD(menu, void **, 0x60))) Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x60));
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x64));
    value = GetSpriteAnimValue(M2C_FIELD(menu, void **, 0x68));
    slide = M2C_FIELD(menu, void **, 0x68);
    slide->from = value;
    slide->to = -255;
    slide->duration = 12;
    start = slide->start;
    slide->current = start;
    return start;
}

/* Leave the online session, spawn its departure object and hide the menu's
 * button and child sprites.  This is CloseOnlineMenu without the panel's
 * slide-out tween, which the caller starts itself. */
M2C_UNK HideOnlineMenuSprites(void *menu) {
    void *button;

    func_ov010_022294ec(); func_ov010_02228c88(menu);
    button = M2C_FIELD(menu, void **, 0x54);
    if (func_020e_check(button)) Hide3DSpriteSlide(button);
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x58));
    if (Is3DSpriteVisible(M2C_FIELD(menu, void **, 0x60))) Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x60));
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x64));
}

/* Closes the online session, hides the menu's button sprites and starts the menu
 * panel's slide-out tween.  Returns the tween's start value. */
M2C_UNK CloseOnlineMenu(void *menu) {
    void *button;
    s16 value;
    SpriteTween *slide;
    u16 start;

    func_ov010_022294ec(); func_ov010_02228c88(menu);
    button = M2C_FIELD(menu, void **, 0x54);
    if (func_020e_check(button)) Hide3DSpriteSlide(button);
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x58));
    if (Is3DSpriteVisible(M2C_FIELD(menu, void **, 0x60))) Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x60));
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x64));
    value = GetSpriteAnimValue(M2C_FIELD(menu, void **, 0x68));
    slide = M2C_FIELD(menu, void **, 0x68);
    slide->from = value;
    slide->to = -255;
    slide->duration = 12;
    start = slide->start;
    slide->current = start;
    return start;
}

void func_020e0350(void) {
    M2C_UNK CloseOnlineMenu();
    ((M2C_UNK (*)())CloseOnlineMenu)();
}

void func_020e035c(void) {
    M2C_UNK CloseLinkMenu();
    ((M2C_UNK (*)())CloseLinkMenu)();
}

void func_020e0368(void) {
    ((M2C_UNK (*)())CloseLinkMenu)();
}

s32 IsMapConfirmEnabled();
M2C_UNK func_020e0374(void *arg0) { s16 v; void *q; u16 value; HideOnlineMenuSprites(arg0);  v=GetSpriteAnimValue(M2C_FIELD(arg0,void**,0x68));
 q=M2C_FIELD(arg0,void**,0x68);
 M2C_FIELD(q,s16*,0xe)=v;
 M2C_FIELD(q,s16*,0x10)=-255;
 M2C_FIELD(q,s16*,0xc)=12;
 value=M2C_FIELD(q,u16*,4);
M2C_FIELD(q,u16*,2)=value;
 return value;
}

void func_020e03ac(void) {
    M2C_UNK HideOnlineMenuSprites();
    HideOnlineMenuSprites();
}

/* Hide an online menu's buttons and label and start its slide-out animation;
   unless a map confirm is already enabled, also close the online session and
   create its departure object.  Returns the animation's start value. */
M2C_UNK DismissOnlineMenu(void *menu) {
    void *button;
    s16 value;
    SpriteTween *slide;
    u16 start;

    if (!IsMapConfirmEnabled()) { func_ov010_022294ec(); func_ov010_02228c88(menu); }
    button = M2C_FIELD(menu, void **, 0x54);
    if (func_020e_check(button)) Hide3DSpriteSlide(button);
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x58));
    if (Is3DSpriteVisible(M2C_FIELD(menu, void **, 0x60))) Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x60));
    Hide3DSpriteSlide(M2C_FIELD(menu, void **, 0x64));
    value = GetSpriteAnimValue(M2C_FIELD(menu, void **, 0x68));
    slide = M2C_FIELD(menu, void **, 0x68);
    slide->from = value;
    slide->to = -255;
    slide->duration = 12;
    start = slide->start;
    slide->current = start;
    return start;
}

void func_020e0468(void) {
    ((M2C_UNK (*)())CloseOnlineMenu)();
}

void func_020e0474(void) {
    M2C_UNK DismissOnlineMenu();
    DismissOnlineMenu();
}

void func_020e0480(void) {
    func_020e0350();
}

/* Processes two current-entity slots, creating objects for an entity when slot conditions allow. */
void func_020e048c(void *entity) {
    M2C_UNK FillU16(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK RenderTextLayerMessage(void *, s32, s32, s32);
    M2C_UNK StartWindowClose();
    void *func_0208b520(void *);
    s32 FindTextLayer();
    extern M2C_UNK data_02168f74;
    extern s32 g3DSpriteEngineMain, g3DSpriteEngineSub, gCur3DSpriteEngine;
    void *created;
    s32 bank;
    register s32 i;
    u8 mode;
    int savedEntity;
    if (FindTextLayer()) StartWindowClose();
    i = 0;
    savedEntity = gCur3DSpriteEngine;
    do {
        if (i == 0) bank = g3DSpriteEngineMain; else bank = g3DSpriteEngineSub;
        gCur3DSpriteEngine = bank;
        mode = M2C_FIELD(entity, u8 *, 0x44);
        if (mode == 0 && bank != g3DSpriteEngineMain) goto next;
        if (mode == 1 && bank != g3DSpriteEngineSub) goto next;
        if (mode == 3 && bank != savedEntity) goto next;
        created = func_0208b520(entity);
        RenderTextLayerMessage(created, 0, M2C_FIELD(entity, u16 *, 0x46) << 5, 0x44000009);
        M2C_FIELD(created, s32 *, 0x58) |= 0x1800;
    next:
        ++i;
    } while (2 > i);
    gCur3DSpriteEngine = savedEntity;
    FillU16(0, &data_02168f74, 8);
    Link_CreateStartRequest(0x434c4353, entity);
}

M2C_UNK func_020e0580(s32 arg0) {
 s32 GetLocalPlayerIdForOverlay(); s16 GetReadyPlayerMask(); M2C_UNK CreateLinkPlayerDataListener();
 extern u16 *gLinkPlayerMasks[];
 s32 i=GetLocalPlayerIdForOverlay();
 *gLinkPlayerMasks[i]=GetReadyPlayerMask();
 return CreateLinkPlayerDataListener(gLinkPlayerMasks,gLinkPlayerMasks[GetLocalPlayerIdForOverlay()],2,arg0);
}

/* For each linked player whose session mask differs from the local player's, set
   the map's link flag and (re)create that player's marker object on the matching
   3D engine; if none differs, drop any leftover marker object. */
void RefreshLinkPlayerSprites(void *entity) {
s32 GetLocalPlayerIdForOverlay(); void EnableMapConfirm(); void DisableMapConfirm();
s32 FindTextLayer(); M2C_UNK StartWindowClose(); void *CreateTextLayer(void *);
M2C_UNK RenderTextLayerMessage(void *,s32,s32,s32);
extern u16 *gLinkPlayerMasks[];
extern s32 g3DSpriteEngineMain,g3DSpriteEngineSub,gCur3DSpriteEngine;
void *sprite; s32 engine; register s32 slot; u8 screenMode; s32 savedEngine; u16 playerMask; s32 player;
playerMask=*gLinkPlayerMasks[GetLocalPlayerIdForOverlay()];
EnableMapConfirm();
for(player=0;player<4;player++){
if((playerMask & (1<<player)) && playerMask != *gLinkPlayerMasks[player]){
if(FindTextLayer())StartWindowClose();
savedEngine=gCur3DSpriteEngine;slot=0;
do {
if(slot==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
screenMode=M2C_FIELD(entity,u8*,0x44);
if(screenMode==0 && engine!=g3DSpriteEngineMain)goto next;
if(screenMode==1 && engine!=g3DSpriteEngineSub)goto next;
if(screenMode==3 && engine!=savedEngine)goto next;
sprite=CreateTextLayer(entity);
RenderTextLayerMessage(sprite,2,M2C_FIELD(entity,u16*,0x46)<<5,0x4400000a);
M2C_FIELD(sprite,s32*,0x58)|=0x1000;
next: ++slot;
}while(slot<2);
gCur3DSpriteEngine=savedEngine;DisableMapConfirm();break;
}}
if(IsMapConfirmEnabled() && FindTextLayer())StartWindowClose();
}

/* Build the voice-chat ("VCHT") option menu entity: load the menu's screen
 * file into the main sprite engine's layer, create the option row sprites, draw
 * the toggle bar in its palette, apply the option to the local player's link
 * status, then refresh the entity's child widgets. */
void SetupVoiceChatMenu(void *entity) {
extern s32 gCur3DSpriteEngine, g3DSpriteEngineMain;
extern M2C_UNK gVoiceChatPath, gVoiceChatNarcName, gVoiceChatScreenName, gVoiceChatRowTemplate;
M2C_UNK Clear3DSpriteLayer(s32), SetFileDirectory(void *);
s32 GetLocalizedFileName(void *);
M2C_UNK OpenNarcArchive(void), CloseNarcArchive(void), LoadNarcFileDecompressed(s32, s32), AddTileRectPalette(s32, s32, s32, s32);
s32 FindSpriteSlotById(s32); void *AddSpriteSlot(s32, s32, void *, s32), *SelectSpriteSlot(s32);
M2C_UNK SetTileRectPalette(s32, s32, u16, u16);
s32 GetActiveOverlay(void); void *GetLocalPlayerStatus(void);
void PlaySoundEffect(s32); M2C_UNK SetSpriteSlotScroll(s32, s32), Show3DSpriteSlide(void *), SetTextById(void *, s32);
s32 row, rowX, bar;
void *selectedRow;
s32 barX, barEnd, barColor, hasRows, savedEngine, savedBarEngine, status;
void *sprite;
u8 selectedId;

savedEngine = gCur3DSpriteEngine;
gCur3DSpriteEngine = g3DSpriteEngineMain;
Clear3DSpriteLayer(1);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
SetFileDirectory(&gVoiceChatPath);
GetLocalizedFileName(&gVoiceChatNarcName);
OpenNarcArchive();
LoadNarcFileDecompressed(GetLocalizedFileName(&gVoiceChatScreenName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
CloseNarcArchive();
AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 32, 24, 5);
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
gCur3DSpriteEngine = savedEngine;
M2C_FIELD(entity, u16 *, VCHT_MENU_FLAGS) |= VCHT_FLAG_BUILDING;
if (FindSpriteSlotById(0) == 0) hasRows = 1; else hasRows = 0;
if (hasRows) {
    row = 0; rowX = 0;
    do {
        sprite = AddSpriteSlot(0, rowX, &gVoiceChatRowTemplate, row);
        row++;
        M2C_FIELD(sprite, void **, 0x10) = entity;
        rowX += 40;
    } while (row < 2);
}
selectedRow = SelectSpriteSlot(M2C_FIELD(entity, s32 *, VCHT_MENU_SELECTED_ROW));
if (selectedRow) {
    savedBarEngine = gCur3DSpriteEngine;
    barX = 10;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    barEnd = 14;
    bar = 0;
    do {
        if (M2C_FIELD(selectedRow, u8 *, 0) != bar) barColor = 7; else barColor = 8;
        SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20) + 8 + (barX << 6), 24, (u16)(barEnd - barX), (u16)barColor);
        bar++;
        barX = (s16)(barX + 5);
        barEnd = (s16)(barEnd + 5);
    } while (bar < 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    gCur3DSpriteEngine = savedBarEngine;
    if (GetActiveOverlay() == 2) status = (M2C_FIELD(GetLocalPlayerStatus(), u8 *, LOCAL_STATUS_OPTIONS) & LOCAL_OPTION_VOICE_CHAT) != 0; else status = 0;
    selectedId = M2C_FIELD(selectedRow, u8 *, 0);
    if (selectedId != status) {
        if (GetActiveOverlay() == 2) {
            sprite = GetLocalPlayerStatus();
            if (selectedId == 1) M2C_FIELD(sprite, u8 *, LOCAL_STATUS_OPTIONS) |= LOCAL_OPTION_VOICE_CHAT;
            else M2C_FIELD(sprite, u8 *, LOCAL_STATUS_OPTIONS) &= ~LOCAL_OPTION_VOICE_CHAT;
        }
        PlaySoundEffect(0x10019);
    }
}
SetSpriteSlotScroll(0, 0);
Show3DSpriteSlide(M2C_FIELD(entity, void **, VCHT_MENU_TOGGLE0));
sprite = M2C_FIELD(entity, void **, VCHT_MENU_TOGGLE0);
if (func_020e_check(sprite)) M2C_FIELD(sprite, E0B04Bits *, 0x40).value = (u16)func_020e_low(sprite);
else M2C_FIELD(sprite, E0B04Bits *, 0x40).value = (u16)(func_020e_low(sprite) + 2);
M2C_FIELD(sprite, u8 *, 0x5a) = 0;
Show3DSpriteSlide(M2C_FIELD(entity, void **, VCHT_MENU_TOGGLE1));
sprite = M2C_FIELD(entity, void **, VCHT_MENU_TOGGLE1);
M2C_FIELD(sprite, E0B04Bits *, 0x40).value = (u16)(func_020e_low(sprite) + 2);
M2C_FIELD(sprite, u8 *, 0x5a) = 0;
sprite = M2C_FIELD(entity, void **, VCHT_MENU_TOGGLE0);
if (!func_020e_check(sprite)) { M2C_FIELD(sprite, E0B04Bits *, 0x40).value = (u16)func_020e_low(sprite); M2C_FIELD(sprite, u8 *, 0x5a) = 0; }
SetTextById(M2C_FIELD(entity, void **, VCHT_MENU_LABEL), 0x44000013);
Show3DSpriteSlide(M2C_FIELD(entity, void **, VCHT_MENU_LABEL));
if (GetSpriteAnimValue(M2C_FIELD(entity, void **, VCHT_MENU_ANIM))) {
    s16 result = GetSpriteAnimValue(M2C_FIELD(entity, void **, VCHT_MENU_ANIM));
    sprite = M2C_FIELD(entity, void **, VCHT_MENU_ANIM);
    M2C_FIELD(sprite, u16 *, 0xe) = result;
    M2C_FIELD(sprite, u16 *, 0x10) = 0;
    M2C_FIELD(sprite, u16 *, 0xc) = 12;
    M2C_FIELD(sprite, u16 *, 2) = M2C_FIELD(sprite, u16 *, 4);
}
M2C_FIELD(entity, u16 *, VCHT_MENU_FLAGS) &= ~VCHT_FLAG_CONFIRMED;
M2C_FIELD(entity, u16 *, VCHT_MENU_FLAGS) &= ~VCHT_FLAG_OVERLAY;
}

void func_020e0aa4(void) {
    ((M2C_UNK (*)())SetupVoiceChatMenu)();
}

void func_020e0ab0(void) {
    func_020e0aa4();
}

void func_020e0abc(void) {
    ((M2C_UNK (*)())SetupVoiceChatMenu)();
}

void func_020e0ac8(void) {
    ((M2C_UNK (*)())SetupVoiceChatMenu)();
}

void func_020e0ad4(void) {
    func_020e0aa4();
}

void func_020e0ae0(void) {
    func_020e0aa4();
}

void func_020e0aec(void) {
    func_020e0ab0();
}

void func_020e0af8(void) {
    func_020e0ab0();
}

/* Updates child objects and resumes the entity script when its primary child is ready or A is pressed. */
void func_020e0b04(void *entity) {
    s32 IsLinkSessionActive(void); s32 func_0208477c(void); s32 GetOverlayEventFlags(void);
    s32 FindTextLayer(void); M2C_UNK StartWindowClose(void); void *CreateTextLayer(void *);
    M2C_UNK RenderTextLayerMessage(void *, s32, s32, s32);
    void DisableMapConfirm(void); void SetSpriteAnimation(void *, s32);
    void PlaySoundEffect(s32); void Sprite_ResumeAnimation(void *);
    void MenuSpriteUpdate(void *);
    extern u16 *gKeyState;
    extern s32 g3DSpriteEngineMain, g3DSpriteEngineSub, gCur3DSpriteEngine;
    void *created; s32 bank; register s32 i; u8 mode; s32 saved;
    u32 keys; s32 changed; void *primaryChild; u8 canAdvance; u32 frame;

    if (M2C_FIELD(entity, void **, 0x50)) MenuSpriteUpdate(M2C_FIELD(entity, void **, 0x50));
    if (M2C_FIELD(entity, void **, 0x54)) MenuSpriteUpdate(M2C_FIELD(entity, void **, 0x54));
    if (M2C_FIELD(entity, void **, 0x58)) MenuSpriteUpdate(M2C_FIELD(entity, void **, 0x58));
    keys = *gKeyState;
    M2C_FIELD(entity, u16 *, 0x48) &= ~0x20;
    if (E0B04Process(entity)) {
        DisableMapConfirm();
        SetSpriteAnimation(entity, 0x40);
        return;
    }
    primaryChild = M2C_FIELD(entity, void **, 0x50);
    if (!func_020e_check(primaryChild)) return;
    frame = func_020e_low(primaryChild);
    canAdvance = 1;
    if (M2C_FIELD(M2C_FIELD(primaryChild, void **, 0x64), s8 *, 11) != 1) {
        if (!((u32)(M2C_FIELD(primaryChild, u8 *, 0x59) << 27) >> 31) ||
            M2C_FIELD(M2C_FIELD(primaryChild, void **, 0x64), s8 *, 12) != 1) canAdvance = 0;
    }
    if ((u8)(canAdvance & 0xff) == 0 && !(keys & 1)) return;
    if (M2C_FIELD(entity, u16 *, 0x48) & 8) return;
    if (M2C_FIELD(primaryChild, s8 *, 0x5a) >= 0) {
        M2C_FIELD(primaryChild, E0B04Bits *, 0x40).value = (u16)(frame + 1);
        M2C_FIELD(primaryChild, u8 *, 0x5a) = 12;
    }
    if (M2C_FIELD(entity, u16 *, 0x48) & 8) return;
    PlaySoundEffect(0x1000e);
    M2C_FIELD(entity, u16 *, 0x48) |= 8;
    Sprite_ResumeAnimation(entity);
}

void func_020e0d6c(void *entity) {
    void func_020e0b04(void *);
    func_020e0b04(entity);
}

void func_020e0d78(void *entity) {
    func_020e0d6c(entity);
}

void func_020e0d84(void *entity) {
    func_020e0b04(entity);
}

void func_020e0d90(void *entity) {
    func_020e0b04(entity);
}

void func_020e0d9c(void *entity) {
    func_020e0d6c(entity);
}

void func_020e0da8(void *entity) {
    func_020e0d6c(entity);
}

void func_020e0db4(void *entity) {
    func_020e0d78(entity);
}

void func_020e0dc0(void *entity) {
    func_020e0d78(entity);
}

void func_020e0dcc(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    M2C_UNK PublishLocalPlayerStatus();
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

void func_020e0dec(M2C_UNK arg0) {
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

void func_020e0e0c(M2C_UNK arg0) {
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

void func_020e0e2c(M2C_UNK arg0) {
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

void func_020e0e4c(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    M2C_UNK PublishLocalPlayerStatus();
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

void func_020e0e6c(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    M2C_UNK PublishLocalPlayerStatus();
    PublishLocalPlayerStatus();
    Link_CreateStartRequest(0x56434854, arg0);
}

M2C_UNK func_020e0e8c(void *arg0) { M2C_UNK HideAllSpriteSlots();
M2C_UNK SetSpriteSlotScroll();
func_ov010_022294ec();
func_ov010_02228c88(arg0);
HideAllSpriteSlots();
return SetSpriteSlotScroll(0,0);
}

void func_020e0eb4(void) {
    M2C_UNK func_020e0e8c();
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ec0(void) {
    func_020e0eb4();
}

void func_020e0ecc(void) {
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ed8(void) {
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ee4(void) {
    func_020e0eb4();
}

void func_020e0ef0(void) {
    func_020e0eb4();
}

void func_020e0efc(void) {
    func_020e0ec0();
}

void func_020e0f08(void) {
    func_020e0ec0();
}

