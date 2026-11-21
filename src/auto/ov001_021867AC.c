/* 21 functions from 0x021867AC to 0x02187590 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_link.h"
#include "ov001_menu.h"
/* The ov001 wireless-link work header: the seven status words the link code
 * (Ov001_GetLinkStatus and friends) clears when the link is set up. */
typedef struct { u16 value[7]; } Ov001LinkHeader;
/* The parent's owner info sent to the download-play children: a flags byte, the
 * nickname length and the nickname. */
typedef struct { u8 low:4, high:4; u8 len; u16 name[10]; } MbParentInfo;
static inline void ClearLinkHeader(Ov001LinkHeader *p) { p->value[0]=0; p->value[1]=0; p->value[2]=0; p->value[3]=0; p->value[4]=0; p->value[5]=0; p->value[6]=0; }
extern void *gOv001LinkWork;
extern void *gOv001RegionMenu;
extern const u8 data_ov001_0218fc66[], gOv001RegionItemSlot[];
extern const u16 gOv001RegionItemPos[], data_ov001_0218fcce[];

/* Selects the UI button under the cursor in the active button group, or deselects. */
void Ov001_UpdateRegionMenuInput(void) {
extern u8 gOv001RegionItemCount[];
extern const u16 data_ov001_0218fc70[];
extern const s8 data_ov001_0218fc5c[], data_ov001_0218fc5d[];
s32 TouchRectPressed(void *);
s32 KeyPressed(s32);
void BuildTouchRect(const void *, const void *, void *);
void Ov001_ShowRegionMenuItem(s32);
s32 i;
u32 rect[2];
for (i = 0; i < gOv001RegionItemCount[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)]; i++) {
    BuildTouchRect(&((const u32 (*)[2])gOv001RegionItemPos)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][((const u8 (*)[2])gOv001RegionItemSlot)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][i]], &((const u32 *)data_ov001_0218fc70)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)], rect);
    if (TouchRectPressed(rect)) {
        M2C_FIELD(gOv001RegionMenu, s8 *, 0x1b) = i;
        break;
    }
}
if (KeyPressed(1)) M2C_FIELD(gOv001RegionMenu, s8 *, 0x1b) = data_ov001_0218fc5c[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) * 2];
if (KeyPressed(2)) M2C_FIELD(gOv001RegionMenu, s8 *, 0x1b) = data_ov001_0218fc5d[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) * 2];
for (i = 0; i < gOv001RegionItemCount[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)]; i++) {
    if (i == M2C_FIELD(gOv001RegionMenu, s8 *, 0x1b)) {
        Ov001_ShowRegionMenuItem(i);
        return;
    }
}
M2C_FIELD(gOv001RegionMenu, s8 *, 0x1b) = -1;
}

/* Per-frame task for a region whose menu has no items: keep the selection
 * cleared, count frames towards OV001_REGION_EMPTY_TIMEOUT, then report the
 * timeout and schedule Ov001_RegionMenuCloseDelay that many frames later. */
void Ov001_RegionMenuEmptyTimeout(s32 task) {
    s32 Ov001_AddTask(s32, void (*)(s32), s32, s32);
    void Ov001_RegionMenuCloseDelay(s32);
    void Ov001_PostTaskMessage(s32, s32);
    M2C_FIELD(gOv001RegionMenu, s8 *, OV001_REGION_SELECTED) = -1;
    M2C_FIELD(gOv001RegionMenu, u16 *, OV001_REGION_TIMER)++;
    if (M2C_FIELD(gOv001RegionMenu, u16 *, OV001_REGION_TIMER) < OV001_REGION_EMPTY_TIMEOUT) return;
    Ov001_PostTaskMessage(0, task);
    M2C_FIELD(gOv001RegionMenu, s32 *, OV001_REGION_TASK) = Ov001_AddTask(1, Ov001_RegionMenuCloseDelay, 0, OV001_REGION_EMPTY_TIMEOUT);
}

/* Slide the selected region's menu column to vertical position topY: move the
 * two side sprites and every item sprite, hide those that leave the screen, and
 * set the clip window over the region's column. */
void Ov001_SetRegionMenuY(s32 topY) {
    extern u8 gOv001RegionItemCount[];
    extern const u8 gOv001RegionItemSlot[];
    extern const u16 gOv001RegionOrigin[], gOv001RegionItemPos[], gOv001RegionWidth[], gOv001RegionHeight[];
    void Ov001_MoveSpriteLayout(void *, s32, s32, s32);
    void Ov001_ClipSpriteLayout(M2C_UNK, s32);
    void SetRect16(s32, s32, s32, s32, void *);
    void SetWindowRect(s32, s32, u16 *);
    s32 item;
    u16 rect[4];
    Ov001_MoveSpriteLayout(M2C_FIELD(gOv001RegionMenu, void **, 0), -1, gOv001RegionOrigin[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) * 2], topY);
    Ov001_MoveSpriteLayout(M2C_FIELD(gOv001RegionMenu, void **, 4), -1, gOv001RegionOrigin[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) * 2] + 8, topY + 8);
    Ov001_ClipSpriteLayout(M2C_FIELD(gOv001RegionMenu, void **, 0), topY);
    Ov001_ClipSpriteLayout(M2C_FIELD(gOv001RegionMenu, void **, 4), topY);
    for (item = 0; item < gOv001RegionItemCount[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)]; item++) {
        Ov001_MoveSpriteLayout(
            ((void **)gOv001RegionMenu)[item + 2], -1,
            ((const u16 (*)[2][2])gOv001RegionItemPos)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][((const u8 (*)[2])gOv001RegionItemSlot)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][item]][0],
            topY + ((const u16 (*)[2][2])gOv001RegionItemPos)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][((const u8 (*)[2])gOv001RegionItemSlot)[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c)][item]][1]
            - gOv001RegionOrigin[M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c) * 2 + 1]);
        Ov001_ClipSpriteLayout(((void **)gOv001RegionMenu)[item + 2], topY);
    }
    {
        s32 region = M2C_FIELD(gOv001RegionMenu, u8 *, 0x1c);
        s32 y = topY & 0xff;
        s32 bottom;
        if (y >= 0xc0) { bottom = 0; y = 0; }
        else { bottom = y + gOv001RegionHeight[region * 2]; }
        if (bottom > 0xc0) bottom = 0xc0;
        SetRect16(gOv001RegionOrigin[region * 2], y,
             gOv001RegionOrigin[region * 2] + gOv001RegionWidth[region * 2], bottom, rect);
    }
    SetWindowRect(0, 0, rect);
}

/* Hide the entries of a sprite layout that are not on screen: each entry is shown
 * when its y lies between topY and the bottom of the 192-pixel screen, and hidden
 * with SPRITE_ENTRY_HIDDEN otherwise. */
void Ov001_ClipSpriteLayout(M2C_UNK obj, s32 topY) {
s32 Ov001_GetSpriteEntryCount();
M2C_UNK Ov001_SetSpriteEntryFlags(M2C_UNK,s32,s32,M2C_UNK);
M2C_UNK Ov001_GetSpritePosition(M2C_UNK,s32,M2C_UNK *,s32 *);
M2C_UNK x; s32 y; s32 count; s32 flags; s32 i;
count=Ov001_GetSpriteEntryCount();i=0;if(count<=0)return;
do {Ov001_GetSpritePosition(obj,i,&x,&y);
if(y>=topY && y<SCREEN_HEIGHT)flags=0;else flags=SPRITE_ENTRY_HIDDEN;
Ov001_SetSpriteEntryFlags(obj,i,flags,0);i++;
}while(i<count);
}

/* Give the region menu item `item` its selected look: load its highlighted sprite
 * frame, move the item's sprite onto the item's slot position in the open column
 * and reset its palette. */
void Ov001_ShowRegionMenuItem(s32 item) {
s32 Ov001_GetSpriteObjEntry(s32,s32);
Ov001_LoadSpriteObjLayout(0,((const u8 (*)[2])data_ov001_0218fc66)[M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_INDEX)][item]+1,Ov001_GetSpriteObjEntry(M2C_FIELD(gOv001RegionMenu+item*4,s32 *,OV001_REGION_ITEM_SPRITES),0));
Ov001_MoveSpriteLayout(M2C_FIELD(gOv001RegionMenu+item*4,s32 *,OV001_REGION_ITEM_SPRITES),-1,((const u16 (*)[4])gOv001RegionItemPos)[M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_INDEX)][((const u8 (*)[2])gOv001RegionItemSlot)[M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_INDEX)][item]*2],((const u16 (*)[4])data_ov001_0218fcce)[M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_INDEX)][((const u8 (*)[2])gOv001RegionItemSlot)[M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_INDEX)][item]*2]);
Ov001_SetSpritePalette(M2C_FIELD(gOv001RegionMenu+item*4,s32 *,OV001_REGION_ITEM_SPRITES),-1,0);
}

void Ov001_RegionMenuCloseDelay(M2C_UNK arg0) {
    M2C_UNK Ov001_SetSlideStep(M2C_UNK, M2C_UNK *);
    extern void *gOv001RegionMenu;
    extern M2C_UNK Ov001_SlideRegionMenuOut;
    M2C_FIELD(gOv001RegionMenu, u8 *, 0x1D) = (u8) (M2C_FIELD(gOv001RegionMenu, u8 *, 0x1D) + 1);
    if ((u32) M2C_FIELD(gOv001RegionMenu, u8 *, 0x1D) < 8U) {
        return;
    }
    Ov001_SetSlideStep(arg0, &Ov001_SlideRegionMenuOut);
}

/* One frame of the region column closing: slide it down by OV001_REGION_OPEN_STEP
 * pixels and stop once it is below the 192-pixel screen, then hand the task to
 * the fade-out step or straight to the close. */
void Ov001_SlideRegionMenuOut(s32 task) {
extern void *gOv001RegionMenu;
void Ov001_RegionMenuFadeOutStep(); void Ov001_RegionMenuCloseFinish();
s32 pos[2];
Ov001_GetSpritePosition(M2C_FIELD(gOv001RegionMenu,s32 *,OV001_REGION_SPRITE_TOP),0,&pos[1],&pos[0]);
pos[0]+=OV001_REGION_OPEN_STEP;
Ov001_SetRegionMenuY(pos[0]);
if(pos[0]<192)return;
if(M2C_FIELD(gOv001RegionMenu,u8 *,OV001_REGION_FADE_OUT))Ov001_SetSlideStep(task,Ov001_RegionMenuFadeOutStep);
else Ov001_SetSlideStep(task,Ov001_RegionMenuCloseFinish);
}

void Ov001_RegionMenuFadeOutStep(s32 a) {
extern void *gOv001RegionMenu;
void Ov001_RegionMenuCloseFinish();
M2C_FIELD(gOv001RegionMenu,s8 *,26)++;
GX_SetBlendY(0x4000050,M2C_FIELD(gOv001RegionMenu,s8 *,26));
if(M2C_FIELD(gOv001RegionMenu,s8 *,26)>=0)Ov001_SetSlideStep(a,Ov001_RegionMenuCloseFinish);
}

#pragma opt_strength_reduction off
void Ov001_RegionMenuCloseFinish(s32 a) {
    extern void *data_ov001_02193e18; extern u8 data_ov001_0218fcfc[];
    s32 i;
    *(volatile u32 *)0x4000000 &= ~0xe000;
    Ov001_DestroySprite(((s32**)data_ov001_02193e18)[0]);
    Ov001_DestroySprite(((s32**)data_ov001_02193e18)[1]);
    for (i = 0; i < data_ov001_0218fcfc[((u8*)data_ov001_02193e18)[0x1c]]; i++) {
        if (((s32**)data_ov001_02193e18)[2 + i]) Ov001_DestroySprite(((s32**)data_ov001_02193e18)[2 + i]);
    }
    func_ov001_0218ace0(((s32**)data_ov001_02193e18)[4]);
    Ov001_PostTaskMessage(1, a);
    Ov001_FreeAlloc((void*)0x02193e18);
}
#pragma opt_strength_reduction reset
void func_ov001_02186e40(void *arg0) {
    M2C_UNK func_ov001_02187ad8(void *);
    gOv001LinkWork = arg0;
    func_ov001_02187ad8(arg0 + 0x1B160);
    M2C_FIELD(gOv001LinkWork, s32 *, 0x1B140) = 0;
    M2C_FIELD(gOv001LinkWork, s32 *, 0x1B144) = 0;
}

/* Start the overlay's DS Download Play (multiboot) parent transfer: build the
 * parent's owner info (flags and nickname) from the system owner record, clear
 * the link work header, hand the transfer buffer at +0x10040 to the multiboot
 * library - halting if it refuses - then set the library up and enter the link
 * state machine. */
void Ov001_StartDownloadPlay(s32 param,s32 programId){
void GetSystemUserProfile(void *);
void MI_CpuCopy8(void *,void *,s32);
s32 MultiBoot_StartParent(void *,void *,s32,s32,s32);
void MultiBoot_SetParentParams(s32,s32);
void func_02013e70(void (*)(void));
void Ov001_HandleLinkEvent(void);
MbParentInfo parentInfo;
u8 ownerInfo[84];
GetSystemUserProfile(ownerInfo);
parentInfo.low=ownerInfo[1];
parentInfo.len=*(u16 *)(ownerInfo+26);
MI_CpuCopy8(ownerInfo+4,parentInfo.name,*(u16 *)(ownerInfo+26)*2);
parentInfo.high=0;
{
Ov001LinkHeader zero={0};
*(Ov001LinkHeader *)gOv001LinkWork=zero;
}
M2C_FIELD(gOv001LinkWork,void **,0x1b140)=(u8 *)gOv001LinkWork+0x10040;
if(MultiBoot_StartParent(M2C_FIELD(gOv001LinkWork,void **,0x1b140),&parentInfo,param,programId,2))SystemHalt();
MultiBoot_SetParentParams(256,1);
func_02013e70(Ov001_HandleLinkEvent);
Ov001_SetLinkStatus(1);
}

void func_ov001_02186fa0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SystemHalt();
    s32 func_02017f90(M2C_UNK);
    s32 Ov001_LoadDownloadPlayProgram(M2C_UNK);
    Ov001_SetLinkStatus(2);
    if (func_02017f90(arg1) != 0) {
        Ov001_SetLinkStatus(7);
        return;
    }
    if (Ov001_LoadDownloadPlayProgram(arg0) != 0) {
        return;
    }
    SystemHalt();
}

/* Load the DS Download Play program image into the link work block and register
 * it with the multiboot library: when the caller's file request block carries a
 * path the image is read from that file, otherwise from the ROM's program area.
 * A request block opened here is closed again; returns 1 once the image is
 * registered, 0 when it could not be loaded. */
s32 Ov001_LoadDownloadPlayProgram(s32 fileRequest) {
    s32 OpenFileRequest(void *, s32);
    s32 Mb_GetProgramSize(void *);
    s32 Mb_LoadProgramImage(void *, void *, s32);
    s32 Mb_RegisterProgram(M2C_UNK, void *);
    u32 file[18];
    void *request;
    s32 result = 0;

    if (M2C_FIELD(fileRequest, s32 *, 0) == 0) request = 0;
    else {
        InitFileRequest(file);
        if (!OpenFileRequest(file, M2C_FIELD(fileRequest, s32 *, 0))) return 0;
        request = file;
    }
    if (Mb_GetProgramSize(request)) {
        M2C_FIELD(gOv001LinkWork, void **, OV001_LINK_PROGRAM) = (u8 *)gOv001LinkWork + 0x2c;
        if (M2C_FIELD(gOv001LinkWork, void **, OV001_LINK_PROGRAM) &&
            Mb_LoadProgramImage(request, M2C_FIELD(gOv001LinkWork, void **, OV001_LINK_PROGRAM), 0x10000) &&
            Mb_RegisterProgram(fileRequest, M2C_FIELD(gOv001LinkWork, void **, OV001_LINK_PROGRAM))) result = 1;
    }
    if (request == file) CloseFileRequest(file);
    return result;
}

/* Reacts to a download-play child acknowledging link phase 1: a child that has
   not reached the phase's expected multiboot state is dropped from every link
   bitmap (with interrupts off) and its connection closed. */
void Ov001_HandleChildPhase1(s32 player) {
    extern void *gOv001LinkWork;
    u16 mask;
    s32 state;

    if (Mb_AckPlayerPhase(player, 1)) return;
    mask = ~(1 << player);
    state = OS_DisableInterrupts();
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) &= mask;
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= mask;
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) &= mask;
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= mask;
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= mask;
    M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) &= mask;
    OS_RestoreInterrupts(state);
    Mb_RemovePlayer(player);
}

/* Reacts to a download-play child acknowledging link phase 0: if the child has
 * not reached the phase's expected multiboot state, drop it from every link
 * bitmap (players +2, +4, +6, +8, +10, +12) and close its connection; if it
 * has, only clear its joined (+2) and kicked (+4) bits. */
void Ov001_HandleChildPhase0(s32 player) {
u16 mask; s32 state; s32 mask2;
if(!Mb_AckPlayerPhase(player,0)) {
mask=~(1<<player);
state=OS_DisableInterrupts();
M2C_FIELD(gOv001LinkWork,u16 *,2) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,4) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,6) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,8) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,10) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,12) &= mask;
OS_RestoreInterrupts(state); Mb_RemovePlayer(player);
} else {
state=OS_DisableInterrupts();
mask2=~(1<<player);
M2C_FIELD(gOv001LinkWork,u16 *,4) &= mask2;
M2C_FIELD(gOv001LinkWork,u16 *,2) &= mask2;
OS_RestoreInterrupts(state);
}
}

/* Finish a player's leave: if the child took the setup step, move its bit from
 * kick-pending to kick-answered; if it did not, clear it from every link bitmap
 * and close its connection. */
void Ov001_CompletePlayerLeave(s32 player) {
    u16 mask;
    s32 state;

    if (!func_02013f70(player, 2)) {
        mask = ~(1 << player);
        state = OS_DisableInterrupts();
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) &= mask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= mask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) &= mask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= mask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= mask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) &= mask;
        OS_RestoreInterrupts(state);
        func_020180c8(player);
    } else {
        state = OS_DisableInterrupts();
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) |= 1 << player;
        OS_RestoreInterrupts(state);
    }
}

/* Drop every joined player (bit set in work+2) that has not been kicked (+4): once
   acknowledge (+6) is not pending, clear all six link-header bits with interrupts
   off and close that player's connection; players still mid-kick go through the
   same echo-group check that may finish the drop (Ov001_CompletePlayerLeave). */
void Ov001_DropUnacknowledgedPlayers(void) {
u16 i,mask;
s32 state;
Ov001_SetLinkStatus(3);
for(i=1;i<16;i++) {
if((M2C_FIELD(gOv001LinkWork,u16 *,2)&(1<<i)) && !(M2C_FIELD(gOv001LinkWork,u16 *,4)&(1<<i))) {
if(!(M2C_FIELD(gOv001LinkWork,u16 *,6)&(1<<i))) {
mask=~(1<<i);
state=OS_DisableInterrupts();
M2C_FIELD(gOv001LinkWork,u16 *,2) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,4) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,6) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,8) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,10) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,12) &= mask;
OS_RestoreInterrupts(state); Mb_RemovePlayer(i);
} else Ov001_CompletePlayerLeave(i);
}
}
}

/* Whether every joined download-play player has completed its multiboot setup:
 * false when no player has joined, or when any joined player is not yet ready. */
s32 Ov001_AreJoinedPlayersReady(void) {
    s32 Mb_IsPlayerReady(u16);
    u16 player;
    if (M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) == 0) return 0;
    for (player = 1; player < 16; player++) {
        if (M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) & (1 << player)) {
            if (!Mb_IsPlayerReady(player)) return 0;
        }
    }
    return 1;
}

/* For each ready player (bit in +10), drop those failing the connection check; set state 7 if none remain, else 4. */
void func_ov001_02187454(void) {
u16 i,mask,remainingPlayers=0;
s32 savedState,ready;
for(i=1;i<16;i++) {
if(M2C_FIELD(gOv001LinkWork,u16 *,10)&(1<<i)) {
if(!Mb_AckPlayerPhase(i,3)) {
mask=~(1<<i);
savedState=OS_DisableInterrupts();
M2C_FIELD(gOv001LinkWork,u16 *,2) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,4) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,6) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,8) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,10) &= mask;
M2C_FIELD(gOv001LinkWork,u16 *,12) &= mask;
OS_RestoreInterrupts(savedState); Mb_RemovePlayer(i);
} else remainingPlayers |= 1<<i;
}
}
if(remainingPlayers==0)Ov001_SetLinkStatus(7);
else Ov001_SetLinkStatus(4);
}

void func_ov001_0218754c(void) {
M2C_UNK func_0201808c();M2C_UNK Ov001_SetLinkStatus(M2C_UNK);
Ov001_SetLinkStatus(6);func_0201808c();
}

void Ov001_TryStartTransfer(void) {
    extern void *gOv001LinkWork;
    if ((M2C_FIELD(gOv001LinkWork, u16 *, 0) == 4) && (M2C_FIELD(gOv001LinkWork, u16 *, 2) == M2C_FIELD(gOv001LinkWork, u16 *, 0xC))) {
        func_0201808c();
    }
}

