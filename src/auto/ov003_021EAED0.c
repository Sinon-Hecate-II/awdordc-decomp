/* 16 functions from 0x021EAED0 to 0x021EBEC0 (ov003), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "sound.h"
#include "ds3dsprite.h"
#include "waypoint_panel.h"


#pragma push
#pragma scheduling off
void func_ov003_021eaed0(void *arg0) {
s32 Link_ReceivePacket(void *,s32);void *GetLocalNetworkPlayerRecord();s32 GetLocalPlayerIdForOverlay();
s8 func_ov003_021e9c24(void *);void func_ov003_021ea4a8(void *,s32);
s32 IsWaypointPanelWide(void *),IsWaypointPanelCompact(void *);
u8 GetLocalPlayerWaypointSlot(void *);u8 func_ov003_021e82fc(s32,s32);s32 IsWaypointSlotEmpty(s32,s32);
s32 AreNetworkPlayerRecordsReady(void);s32 IsWaypointPanelTwoPlayerMap(void *);
u8 IsMenuEnabled(void *);void DisableMenuSprite(void *),EnableMenuSprite(void *),PressWaypointSprite(void *);
u8 IsWaypointPanelIdle(void *);s32 IsWaypointPanelOptionsOpen(void *);
void SetWaypointPanelMode(void *,s32);void Link_SendPacket(void *,s32);
u8 func_ov003_021ebc88(void *);void func_ov003_021e9e4c(void *);
u8 GetWaypointSlotOptionCounter(s32,s32);void func_ov003_021ebca4(s32,s32,s32);
s32 GetWaypointSlotOwner(s32,s32);s8 GetWaypointSlotCoIcon(void *,s32);
void func_ov003_021e82f0(s32,s32,s32);u8 GetWaypointSlotIndex(s32);
void func_ov003_021ebde8(void *,s8,s8);
void func_ov003_021e9804(void *),UpdateWaypointSelectSprites(void *);
s32 MenuSpriteIsClicked(void *);u8 func_ov003_021e9cd0(s32);
void HandleWaypointPanelCancel(void *,s32);s32 func_ov003_021e74a4(s32);
void ToggleWaypointSlotVariant(s32,s32);void StepCounterDown(s32,s32,s32);
s32 IsWaypointPanelAdjustingCounter(void *);void ApplyWaypointMenuAction(void *,u32),func_ov003_021ed27c(void *,u8);
void StepCounterUp(s32,s32,s32);
void Ov003_UpdateWaypointSlotButtons(s32);s32 IsWaypointSlotClicked(s32),func_ov003_021ed8c4(s32),IsWaypointSlotPressed(s32),func_ov003_021ed8e8(s32);
void UpdateWaypointSelection(void *,u8),SetWaypointPanelState(void *,s32),func_ov003_021eccd4(void *),func_ov003_021ed8f0(void *,s32,u8);
s32 InRange(s32,s32,s32);s32 IsTimerDisplayExpired(void *);
extern void *gTouchState;extern u16 *gKeyState;
u8 packet[36],send[36];u16 keys;s32 ready,touch;u8 i;u16 held;s32 action,slot;
if(IsLinkSessionActive()){
void *remote;s32 player,current,desired;u8 j,i;s8 count;
if(!Link_ReceivePacket(packet,36))return;
remote=GetLocalNetworkPlayerRecord();if(!remote)return;
player=GetLocalPlayerIdForOverlay();
count=func_ov003_021e9c24(arg0);
func_ov003_021ea4a8(arg0,(u32)(M2C_FIELD(arg0,u8 *,0x3a)<<31)>>31);
if(IsWaypointPanelWide(arg0)){
packet[13]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),GetLocalPlayerWaypointSlot(M2C_FIELD(arg0,void **,0x6c)));
if(IsSessionHost()){
for(j=0;j<count;j++){if(IsWaypointSlotEmpty(M2C_FIELD(arg0,s32 *,0x6c),j))packet[j+18]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),j);}
if(((s32(*)(void *))AreNetworkPlayerRecordsReady)(arg0)){
if(IsWaypointPanelTwoPlayerMap(arg0)){M2C_FIELD(*(void **)arg0,s32 (**)(void *),0x1c)(arg0);return;}
packet[8]=1;
}
}
if(((u32)(M2C_FIELD(arg0,u8 *,0x39)<<30)>>31) && IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))DisableMenuSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(IsMapListCategory3() && IsWaypointPanelIdle(arg0) && IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))DisableMenuSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(IsSessionGuest() && IsWaypointPanelIdle(arg0) && IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))DisableMenuSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(IsWaypointPanelOptionsOpen(arg0) && !IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))EnableMenuSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(M2C_FIELD(remote,u8 *,8)==1){
SetWaypointPanelMode(arg0,1);PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,4));
if(IsSessionGuest())Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,4));
M2C_FIELD(packet,s32 *,24)=1;Link_SendPacket(packet,36);return;
}
}
if(IsWaypointPanelCompact(arg0)){
if(IsSessionHost()){
if(!func_ov003_021ebc88(M2C_FIELD(arg0,void **,0x58)))func_ov003_021e9e4c(M2C_FIELD(arg0,void **,0x58));
for(j=0;j<count;j++)packet[j+14]=GetWaypointSlotOptionCounter(M2C_FIELD(arg0,s32 *,0x6c),j);
}
if(M2C_FIELD(remote,u8 *,8)==0){
PlaySoundEffect(0x1000f);SetWaypointPanelMode(arg0,0);
Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,4));
func_ov003_021e9e4c(M2C_FIELD(arg0,void **,0x58));
if(IsSessionGuest())Show3DSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,0));
Link_SendPacket(packet,36);return;
}
}
Link_SendPacket(packet,36);
for(i=0;i<count;i++){
if(IsSessionGuest()){
current=GetWaypointSlotOptionCounter(M2C_FIELD(arg0,s32 *,0x6c),i);desired=M2C_FIELD((u8 *)remote+i,u8 *,14);
if(current!=desired){PlaySoundEffect(0x10011);func_ov003_021ebca4(M2C_FIELD(arg0,s32 *,0x6c),i,desired);}
}
if(player==GetWaypointSlotOwner(M2C_FIELD(arg0,s32 *,0x6c),i))continue;
if(IsSessionHost() && IsWaypointSlotEmpty(M2C_FIELD(arg0,s32 *,0x6c),i))continue;
{s32 co=(s8)func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),i);
desired=GetWaypointSlotCoIcon(arg0,i);
if(co!=desired){
PlaySoundEffect(0x10011);desired=(u8)desired;
func_ov003_021e82f0(M2C_FIELD(arg0,s32 *,0x6c),i,desired);
M2C_FIELD(arg0,u8 *,0x3a)|=8;
if(i==GetWaypointSlotIndex(M2C_FIELD(arg0,s32 *,0x6c)))((void (*)(void *,s32,s32))func_ov003_021ebde8)(M2C_FIELD(arg0,void **,0x40),i,desired);
}
}
}
if(M2C_FIELD(remote,s32 *,0)){M2C_FIELD(*(void **)arg0,s32 (**)(void *),0x1c)(arg0);return;}
if(M2C_FIELD(remote,s32 *,4)){M2C_FIELD(*(void **)arg0,s32 (**)(void *),0x20)(arg0);return;}
if((u32)(M2C_FIELD(arg0,u8 *,0x39)<<30)>>31)return;
if(IsWaypointPanelWide(arg0) && M2C_FIELD(packet,s32 *,24)){
if(!IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))EnableMenuSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(func_ov003_021ebc88(M2C_FIELD(arg0,void **,0x58)))func_ov003_021e9804(M2C_FIELD(arg0,void **,0x58));
UpdateWaypointSelectSprites(M2C_FIELD(arg0,void **,0x64));
if(IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0))){PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));}
if(M2C_FIELD(gTouchState,u8 *,0x12))return;
if(!(*gKeyState&2))return;
PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));return;
}else if(IsSessionGuest() && IsWaypointPanelCompact(arg0))return;
}
touch=M2C_FIELD(gTouchState,u8 *,0x12);ready=1;keys=gKeyState[0];held=gKeyState[1];
UpdateWaypointSelectSprites(M2C_FIELD(arg0,void **,0x64));
if(IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0))){
PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}
for(i=0;i<func_ov003_021e74a4(M2C_FIELD(arg0,s32 *,0x6c));i++){
if(ready && MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,8))){
ToggleWaypointSlotVariant(M2C_FIELD(arg0,s32 *,0x6c),i);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,8));PlaySoundEffect(0x10011);ready=0;
}else if(ready && MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,24))){
ToggleWaypointSlotVariant(M2C_FIELD(arg0,s32 *,0x6c),i);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,24));PlaySoundEffect(0x10011);ready=0;
}else if(ready && MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,40))){
StepCounterDown(M2C_FIELD(arg0,s32 *,0x6c),i,1);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,40));
if(IsWaypointPanelAdjustingCounter(arg0))ApplyWaypointMenuAction(arg0,(u8)(i+21));else func_ov003_021ed27c(arg0,(u8)(i+21));
PlaySoundEffect(0x10011);ready=0;
}else if(ready && MenuSpriteIsClicked(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,56))){
StepCounterUp(M2C_FIELD(arg0,s32 *,0x6c),i,1);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,56));
if(IsWaypointPanelAdjustingCounter(arg0))ApplyWaypointMenuAction(arg0,(u8)(i+21));else func_ov003_021ed27c(arg0,(u8)(i+21));
PlaySoundEffect(0x10011);ready=0;
}
}

Ov003_UpdateWaypointSlotButtons(M2C_FIELD(arg0,s32 *,0x6c));
action=func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c));
slot=GetWaypointSlotIndex(M2C_FIELD(arg0,s32 *,0x6c));
if(ready && IsWaypointSlotClicked(M2C_FIELD(arg0,s32 *,0x6c))){
ApplyWaypointMenuAction(arg0,(u8)func_ov003_021ed8c4(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}else{
if(IsWaypointSlotPressed(M2C_FIELD(arg0,s32 *,0x6c)))func_ov003_021ed27c(arg0,(u8)func_ov003_021ed8e8(M2C_FIELD(arg0,s32 *,0x6c)));
}
if(!touch){
if(ready && (keys&1)){ApplyWaypointMenuAction(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;}
if(ready && (keys&8)){UpdateWaypointSelection(arg0,25);SetWaypointPanelState(arg0,0);ready=0;func_ov003_021eccd4(arg0);}
if(ready && IsMenuEnabled(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && (keys&2)){
PressWaypointSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}
if(held&64)func_ov003_021ed8f0(arg0,64,keys&64);
if(held&128)func_ov003_021ed8f0(arg0,128,(u8)(keys&128));
if(held&32)func_ov003_021ed8f0(arg0,32,keys&32);
if(held&16)func_ov003_021ed8f0(arg0,16,keys&16);
if(ready && (keys&512)){
action=(s16)action;
if(InRange(action,4,7)){ToggleWaypointSlotVariant(M2C_FIELD(arg0,s32 *,0x6c),slot);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,8));PlaySoundEffect(0x10011);}
else if(InRange(action,21,24)){StepCounterDown(M2C_FIELD(arg0,s32 *,0x6c),slot,1);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,56));PlaySoundEffect(0x10011);}
}else if(ready && (keys&256)){
action=(s16)action;
if(InRange(action,4,7)){ToggleWaypointSlotVariant(M2C_FIELD(arg0,s32 *,0x6c),slot);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,24));PlaySoundEffect(0x10011);}
else if(InRange(action,21,24)){StepCounterUp(M2C_FIELD(arg0,s32 *,0x6c),slot,1);PressWaypointSprite(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,40));PlaySoundEffect(0x10011);}
}
}
if(IsLinkSessionActive()){
if(!Link_ReceivePacket(send,36))return;
send[13]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),GetLocalPlayerWaypointSlot(M2C_FIELD(arg0,void **,0x6c)));
Link_SendPacket(send,36);
}
if(!IsMapListCategory3())return;
if(!IsLinkSessionActive())return;
if(!IsTimerDisplayExpired(M2C_FIELD(arg0,void **,0x60)))return;
ApplyWaypointMenuAction(arg0,25);M2C_FIELD(arg0,u8 *,0x39)|=2;
}
#pragma pop
/* Return the waypoint slot the local player owns, searched over the list's used
 * slots, or -1 (0xFF) when no used slot is theirs. */
u8 GetLocalPlayerWaypointSlot(void *list) {
    s32 GetLocalPlayerIdForOverlay();
    s32 playerId;
    u8 slot;
    u8 count;
    s8 found;

    playerId = GetLocalPlayerIdForOverlay();
    count = M2C_FIELD(list, u8 *, WAYPOINT_LIST_COUNT);
    for (slot = 0; (u32)slot < (u32)count; slot++) {
        if (playerId == M2C_FIELD(list + slot, u8 *, WAYPOINT_LIST_IDS)) {
            found = (s8)slot;
            goto done;
        }
    }
    found = -1;
done:
    return (u8)found;
}

/* Whether every ready player has a network player record whose data field is set;
 * the host gates starting the match on this. */
s32 AreNetworkPlayerRecordsReady(void) {
    s32 IsLinkSessionActive();
    s32 GetSessionPlayerMask();
    void *GetNetworkPlayerRecord(s32);
    s8 i;
    s32 mask;
    void *record;

    if (IsLinkSessionActive() == 0) return 0;
    mask = GetSessionPlayerMask();
    for (i = 0; i < 4; i++) {
        if (mask & (1 << i)) {
            record = GetNetworkPlayerRecord(i);
            if (record == NULL) return 0;
            if (M2C_FIELD(record, s32 *, NET_PLAYER_DATA) == 0) return 0;
        }
    }
    return 1;
}

/* Opens the waypoint panel: marks it active, plays the open sound, advances the
 * CO face to its next expression/tile row, hides the two selection sprites,
 * switches the scene to its opened state and, in a link session, tells the peers
 * that this player opened it. */
void OpenWaypointPanel(void *panel) {
    M2C_UNK SendWaypointPanelOpened(void *);
    void *face;

    M2C_FIELD(panel, u8 *, 0x3A) = (u8) (M2C_FIELD(panel, u8 *, 0x3A) | 0x80);
    PlaySoundEffect(0x1000D);
    face = M2C_FIELD(M2C_FIELD(panel, void **, 0x64), void **, 4);
    if ((s32) M2C_FIELD(face, s8 *, FACE_SPRITE_LAYOUT) >= 0) {
        M2C_FIELD(face, s32 *, FACE_SPRITE_TILE) = (s32) ((M2C_FIELD(face, s32 *, FACE_SPRITE_TILE) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(face, u8 *, FACE_SPRITE_EXPRESSION) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(face, s8 *, FACE_SPRITE_LAYOUT) = 0xC;
    }
    Hide3DSprite(M2C_FIELD(panel, s32 *, 0x58));
    Hide3DSprite(M2C_FIELD(panel, s32 *, 0x5C));
    SetOv003SceneState(2);
    M2C_FIELD(panel, s8 *, 0x38) = 0;
    Sprite_ResumeAnimation(panel);
    if (IsSessionHost() == 0) {
        return;
    }
    SendWaypointPanelOpened(panel);
}

/* Show a waypoint sprite's pressed frame (its base frame plus one) and hold it
 * for 12 frames; does nothing while the sprite's press timer is still negative. */
void PressWaypointSprite(void *sprite) {
    if ((s32) M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) < 0) {
        return;
    }
    M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~MENU_SPRITE_FRAME_MASK) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
    M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) = 12;
}

/* Whether a menu sprite is in its enabled (clickable) state: its current frame
 * is anything but the disabled frame, the base frame plus two. */
u8 IsMenuEnabled(void *sprite) {
    u8 enabled;

    if ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 2) != (u16) ((u32) (M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) << 6) >> 0x18)) {
        enabled = 1;
    } else {
        enabled = 0;
    }
    return enabled;
}

/* Put a menu sprite into its disabled (unavailable) frame - the base frame plus
 * two - and clear its press timer, so it stops accepting clicks. */
void DisableMenuSprite(void *sprite) {
    M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~MENU_SPRITE_FRAME_MASK) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) = 0;
}

/* Return 1 while the waypoint panel is idle: its state nibble
 * (WAYPOINT_PANEL_STATE_MASK of WAYPOINT_PANEL_FLAGS) is WAYPOINT_PANEL_IDLE,
 * which means no menu is open. */
u8 IsWaypointPanelIdle(void *panel) {
    u8 idle;

    if (((u32) (M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS) << 0x18) >> 0x1C) == WAYPOINT_PANEL_IDLE) {
        idle = 1;
    } else {
        idle = 0;
    }
    return idle;
}

/* Put a menu sprite back into its enabled frame - the base frame - and clear its
 * press timer, so it accepts clicks again. */
void EnableMenuSprite(void *sprite) {
    M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~MENU_SPRITE_FRAME_MASK) | ((u32) ((u16) ((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(sprite, s8 *, MENU_SPRITE_TIMER) = 0;
}

u8 func_ov003_021ebc88(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x59);
}

/* The option counter value kept for waypoint-list slot `slot`. */
u8 GetWaypointSlotOptionCounter(s32 list, s32 slot) {
    return (u8) M2C_FIELD(((slot * WAYPOINT_LIST_OPTION_COUNTER_STRIDE) + list), s32 *,
                          WAYPOINT_LIST_OPTION_COUNTERS + WAYPOINT_OPTION_COUNTER_VALUE);
}

void func_ov003_021ebca4(s32 arg0,s32 arg1,s32 arg2) {
 u32 offset;
 u32 base;
 void *p;
 void *q;
 s32 value;
 s32 temp;
 offset=arg1*0x18;
 base=arg0+0x18;
 M2C_FIELD(base,s32 *,offset)=arg2;
 p=(void *)(arg0+offset);
 if(M2C_FIELD(p,u8 *,0x28)) {
  if(M2C_FIELD(base,s32 *,offset)>M2C_FIELD(p,s32 *,0x1c)) {
   do {
    temp=M2C_FIELD(p,s32 *,0x18)-(M2C_FIELD(p,s32 *,0x1c)-M2C_FIELD(p,s32 *,0x20)+1);
    M2C_FIELD(p,s32 *,0x18)=temp;
   } while(temp>M2C_FIELD(p,s32 *,0x1c));
  }
  q=(void *)((char *)arg0+offset);
  if(M2C_FIELD(base,s32 *,offset)>=M2C_FIELD(q,s32 *,0x20)) return;
  do {
   temp=M2C_FIELD(q,s32 *,0x18)+(M2C_FIELD(q,s32 *,0x1c)-M2C_FIELD(q,s32 *,0x20)+1);
   M2C_FIELD(q,s32 *,0x18)=temp;
  } while(temp<M2C_FIELD(q,s32 *,0x20));
  return;
 }
 value=M2C_FIELD(p,s32 *,0x1c);
 temp=M2C_FIELD(base,s32 *,offset);
 if(temp<=value) {
  value=M2C_FIELD(p,s32 *,0x20);
  if(temp>=value) value=temp;
 }
 M2C_FIELD(base,s32 *,offset)=value;
}

/* Return the CO icon index a waypoint slot should show: the CO the player
 * assigned to the slot picked, or for an empty slot the local player's saved
 * choice for that slot.  Without a network player record both fall back to the
 * local CO of the same slot number. */
s8 GetWaypointSlotCoIcon(void *panel, s32 slot) {
    void *GetNetworkPlayerRecord(s32);
    void *GetLocalNetworkPlayerRecord();
    s32 GetPlayerCoId(s32);
    s32 GetPlayerCoIconIndex(u8);
    s32 playerId = M2C_FIELD(M2C_FIELD(panel, s32 *, WAYPOINT_PANEL_LIST) + slot, u8 *, WAYPOINT_LIST_IDS);
    u8 noPlayer;
    void *record;

    if (playerId == WAYPOINT_NO_PLAYER) noPlayer = 1; else noPlayer = 0;
    if (!noPlayer) {
        record = GetNetworkPlayerRecord(playerId);
        if (record) return M2C_FIELD(record, s8 *, NET_PLAYER_CO_ICON);
        return (s8)GetPlayerCoIconIndex((u8)GetPlayerCoId(slot + 1));
    }
    record = GetLocalNetworkPlayerRecord(playerId);
    if (record) return M2C_FIELD(record + slot, s8 *, NET_PLAYER_SLOT_ICONS);
    return (s8)GetPlayerCoIconIndex((u8)GetPlayerCoId(slot + 1));
}

void func_ov003_021ebde8(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 0x10) = arg1;
    M2C_FIELD(arg0, s8 *, 0x11) = arg2;
}

/* Close the waypoint panel: mark it closed, play the cancel sound, hide its
 * target cursor and slot marker and return the setup scene to its idle state.
 * The host then tells the other player the panel is closed, except on maps of
 * map-list category 3. */
void CloseWaypointPanel(void *panel) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 IsSessionHost();
    s32 IsMapListCategory3();
    M2C_UNK SendWaypointPanelClosed(void *);
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_FIELD(panel, u8 *, 0x3A) = (u8) (M2C_FIELD(panel, u8 *, 0x3A) & ~0x80);
    PlaySoundEffect(0x1000F);
    Hide3DSprite(M2C_FIELD(panel, s32 *, 0x58));
    Hide3DSprite(M2C_FIELD(panel, s32 *, 0x5C));
    SetOv003SceneState(2);
    M2C_FIELD(panel, s8 *, 0x38) = 0;
    Sprite_ResumeAnimation(panel);
    if (IsSessionHost() == 0) {
        return;
    }
    if (IsMapListCategory3() != 0) {
        return;
    }
    SendWaypointPanelClosed(panel);
}

/* Animate every sprite of a waypoint player-select set: its two slide sprites and
 * the sprite each of the four player columns holds in all four rows. */
void UpdateWaypointSelectSprites(void *sprites) {
 M2C_UNK MenuSpriteUpdate(s32);
 u8 i;
 MenuSpriteUpdate(M2C_FIELD(sprites,s32 *,WAYPOINT_SELECT_SLIDE));
 MenuSpriteUpdate(M2C_FIELD(sprites,s32 *,WAYPOINT_SELECT_SLIDE_ALT));
 for(i=0;(u32)i<4U;i++) {
  MenuSpriteUpdate(((s32 *)(sprites+WAYPOINT_SELECT_TILE))[i]);
  MenuSpriteUpdate(((s32 *)(sprites+WAYPOINT_SELECT_TILE_ALT))[i]);
  MenuSpriteUpdate(((s32 *)(sprites+WAYPOINT_SELECT_ROW_2))[i]);
  MenuSpriteUpdate(((s32 *)(sprites+WAYPOINT_SELECT_ROW_3))[i]);
 }
}

