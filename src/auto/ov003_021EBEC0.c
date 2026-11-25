/* 8 functions from 0x021EBEC0 to 0x021ECCD4 (ov003), found by ds-decomp. */
#include "common.h"
#include "waypoint_panel.h"
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } SpritePosC57C;
#pragma opt_propagation off
static inline s32 ov003_entries_differ(s32 arg0) {
 s32 count; s32 entry; u8 i;
 i=0; count=M2C_FIELD(arg0,s8*,4)-1;
 for(;i<count;i++){entry=arg0+i*24; if(M2C_FIELD(entry,s32*,0x18)!=M2C_FIELD(entry,s32*,0x30))return 1;}
 return 0;
}

void RestoreWaypointOption(u8 *);
#pragma inline off
/* Cancel the selected panel action, restoring an option edit before returning to its player slot. */
void HandleWaypointPanelCancel(void *panel, u32 selection) {
    void PlaySoundEffect(u32);
    void ToggleWaypointPanelMode(void *);
    s32 IsWaypointPanelIdle(void *);
    void SetWaypointPanelState(void *, s32);
    void RestoreWaypointOption(u8 *);
    void UpdateWaypointSelection(void *, s32);

    PlaySoundEffect(0x1000f);
    switch (selection) {
    case 25:
    case 3:
    case 2:
    case 1:
    case 0:
        ToggleWaypointPanelMode(panel);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (IsWaypointPanelIdle(panel)) ToggleWaypointPanelMode(panel);
        else SetWaypointPanelState(panel, WAYPOINT_PANEL_IDLE);
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        RestoreWaypointOption(M2C_FIELD(panel, u8 **, WAYPOINT_PANEL_MENU_OFFSET));
        SetWaypointPanelState(panel, WAYPOINT_PANEL_IDLE);
        UpdateWaypointSelection(panel, WAYPOINT_ACTION_CURRENT_SLOT);
        break;
    case 21:
    case 22:
    case 23:
    case 24:
        if (IsWaypointPanelIdle(panel)) ToggleWaypointPanelMode(panel);
        else SetWaypointPanelState(panel, WAYPOINT_PANEL_IDLE);
        break;
    }
}

#pragma push
#pragma opt_propagation on
void ToggleWaypointPanelMode(void *p) {
 void PlaySoundEffect(u32); s32 IsLinkSessionActive(void); s32 Link_ReceivePacket(void*,s32); void Link_SendPacket(void*,s32);
 s32 IsSessionHost(void); s32 IsSessionGuest(void);
 void Show3DSprite(void*); void Hide3DSprite(void*); void Show3DSpriteSlide(s32); void Hide3DSpriteSlide(s32);
 s16 GetSpriteAnimValue(void*); void SetWaypointListLayout(void*,s32); s32 GetUnitSpriteHeight(void*); s32 GetUnitSpriteWidth(void*); s16 GetWaypointSlotX(u8); s32 SetTextById(s32,s32); s32 InRange(u8,s32,s32);
 u8 buf[36]; u32 mode; u8 flag,i,j; u32 n; s32 *entries,*entries2; s32 count; void *s,*unit,*dst; s32 y,x; u8 state;
 PlaySoundEffect(0x1000f);
 if(IsLinkSessionActive()){
  if(!Link_ReceivePacket(buf,0x24))return;
  mode=(u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30;
  flag=mode==0;
  if(flag){
   if(M2C_FIELD(buf,s32*,24)){M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;Link_SendPacket(buf,0x24);return;}
   if(!IsSessionHost())return;
   M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;Link_SendPacket(buf,0x24);
   {void *self=p;M2C_FIELD(M2C_FIELD(self,void**,0),void(**)(void*),0x20)(self);}return;
  }
  flag=mode==1;if(!flag)return;
  if(!IsSessionHost())return;
  buf[8]=0;M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;Link_SendPacket(buf,0x24);return;
 }
 if(((u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30)==1){
 {u8 v=M2C_FIELD(p,u8*,0x39)&~12;flag=((u32)(v<<28)>>30)==0;M2C_FIELD(p,u8*,0x39)=v;}
 if(flag && IsSessionGuest()){Show3DSprite(M2C_FIELD(p,void**,0x58));Show3DSpriteSlide(*M2C_FIELD(p,s32**,0x64));}
 entries=M2C_FIELD(p,s32**,0x64);count=M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);n=count&255;
 if(!IsLinkSessionActive()){for(i=0;i<4;i++){if(i<n){Show3DSprite((void*)entries[i+2]);Show3DSprite((void*)entries[i+6]);}}}
 s=M2C_FIELD(p,void**,0x48);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=0;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 s=M2C_FIELD(p,void**,0x50);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=256;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 s=M2C_FIELD(p,void**,0x4c);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=192;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 flag=((u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30)==1;
 if(flag){
  if(IsSessionGuest()){Hide3DSprite(M2C_FIELD(p,void**,0x58));Hide3DSpriteSlide(*M2C_FIELD(p,s32**,0x64));}
  entries2=M2C_FIELD(p,s32**,0x64);for(j=0;j<4;j++){Hide3DSprite((void*)entries2[j+2]);Hide3DSprite((void*)entries2[j+6]);}
  s=M2C_FIELD(p,void**,0x48);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=-256;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
  s=M2C_FIELD(p,void**,0x50);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=0;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
  s=M2C_FIELD(p,void**,0x4c);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=94;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 }
 SetWaypointListLayout(M2C_FIELD(p,void**,0x6c),0);
 unit=M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0);y=GetUnitSpriteHeight(unit);x=GetUnitSpriteWidth(unit);
 {s16 yy=M2C_FIELD(unit,s16*,0x36),xx=M2C_FIELD(unit,s16*,0x34);dst=M2C_FIELD(p,void**,0x58);M2C_FIELD(dst,s16*,0x34)=xx;M2C_FIELD(dst,s16*,0x36)=yy;}
 ((SpritePosC57C*)((u8*)dst+0x40))->x=x;((SpritePosC57C*)((u8*)dst+0x40))->y=y;
 M2C_FIELD(M2C_FIELD(p,void**,0x5c),s16*,0x34)=GetWaypointSlotX(M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7));
 if(!((u32)(M2C_FIELD(p,u8*,0x3a)<<31)>>31))return;
 state=M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e);
 if(InRange(state,0,3)){SetTextById(M2C_FIELD(p,s32*,0x54),0x47000011);return;}
 if(InRange(state,4,7)){SetTextById(M2C_FIELD(p,s32*,0x54),0x47000012);return;}
 if(InRange(state,8,20)){SetTextById(M2C_FIELD(p,s32*,0x54),0x47000011);return;}
 if(InRange(state,21,24)){SetTextById(M2C_FIELD(p,s32*,0x54),0x47000010);return;}
 if(state!=25)return;
 mode=(u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30;flag=mode==0;
 if(flag){SetTextById(M2C_FIELD(p,s32*,0x54),0x47000016);return;}
 flag=mode==1;if(flag)SetTextById(M2C_FIELD(p,s32*,0x54),0x47000017);
} else {void *self=p;M2C_FIELD(M2C_FIELD(self,void**,0),void(**)(void*),0x20)(self);}
}
#pragma pop

/* Apply the option the player-option menu was editing to the selected waypoint
 * slot (and to the list's current option), unless the link rules reserve the
 * slot for another player, or the option itself is not a usable CO choice. */
void RestoreWaypointOption(u8 *list) {
    s32 GetLocalPlayerIdForOverlay(void);
    s32 IsSessionHost(void);
    s32 IsSessionGuest(void);
    s32 IsWaypointOptionValid(u8);
    u8 pending = M2C_FIELD(list, u8 *, WAYPOINT_LIST_PENDING_OPTION);
    u8 owner;

    if (IsSessionHost() != 0) {
        owner = M2C_FIELD(list + M2C_FIELD(list, u8 *, WAYPOINT_LIST_SELECTED), u8 *, WAYPOINT_LIST_IDS);
        if (owner != GetLocalPlayerIdForOverlay()) {
            if ((u8)(M2C_FIELD(list + M2C_FIELD(list, u8 *, WAYPOINT_LIST_SELECTED), u8 *, WAYPOINT_LIST_IDS) == 255) == 0) goto update;
        }
    }
    if (IsSessionGuest() != 0) {
        owner = M2C_FIELD(list + M2C_FIELD(list, u8 *, WAYPOINT_LIST_SELECTED), u8 *, WAYPOINT_LIST_IDS);
        if (owner != GetLocalPlayerIdForOverlay()) goto update;
    }
    if (IsWaypointOptionValid(pending) == 0) return;
update:
    M2C_FIELD(list + M2C_FIELD(list, u8 *, WAYPOINT_LIST_SELECTED), u8 *, WAYPOINT_LIST_SLOT_OPTIONS) = pending;
    M2C_FIELD(list, u8 *, WAYPOINT_LIST_OPTION) = pending;
}

#pragma push
#pragma opt_propagation on
/* Applies a waypoint-input action to the option panel's waypoint list and, if
 * the selection changed, refreshes the option cursor, its info text and the
 * saved cursor position. */
void UpdateWaypointSelection(void *panel, s32 action) {
    M2C_UNK SetTextById(s32, s32);
    void PlaySoundEffect(u32);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    s32 InRange(u8, M2C_UNK, M2C_UNK);
    M2C_UNK HandleWaypointInput();
    s16 GetWaypointSlotX(u8);
    s32 slotX;
    s32 slotY;
    s32 isMode1;
    s32 isMode0;
    u8 selection;
    u32 mode;
    u8 oldSelection;
    void *menu;
    void *cursor;
    void *savedPos;
    void *slot;

    oldSelection = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
    HandleWaypointInput(M2C_FIELD(panel,void **,0x6c),action);
    if (oldSelection == (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), void **, 0xE0), u16 *, 0x2E)) {
        return;
    }
    PlaySoundEffect(0x10019);
    slot = M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), void **, 0xE0);
    slotY = GetUnitSpriteHeight(slot);
    slotX = GetUnitSpriteWidth(slot);

    { s16 y=M2C_FIELD(slot,s16 *,0x36), x=M2C_FIELD(slot,s16 *,0x34);
    cursor = M2C_FIELD(panel, void **, 0x58);
    M2C_FIELD(cursor, s16 *, 0x34) = x;
    M2C_FIELD(cursor, s16 *, 0x36) = y;
    }
    ((SpritePosC57C *)((u8 *)cursor+0x40))->x=slotX;
    ((SpritePosC57C *)((u8 *)cursor+0x40))->y=slotY;
    M2C_FIELD(M2C_FIELD(panel, void **, 0x5C), s16 *, 0x34) = GetWaypointSlotX(M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), u8 *, 7));
    if (((u32) (M2C_FIELD(panel, u8 *, 0x3A) << 0x1F) >> 0x1F) != 0) {
        selection = M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
        if (InRange((u8) selection, 0, 3) != 0) {
            SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000011);
        } else if (InRange((u8) selection, 4, 7) != 0) {
            SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000012);
        } else if (InRange((u8) selection, 8, 0x14) != 0) {
            SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000011);
        } else if (InRange((u8) selection, 0x15, 0x18) != 0) {
            SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000010);
        } else if ((u8) selection == 0x19) {
            mode = (u32) (M2C_FIELD(panel, u8 *, 0x39) << 0x1C) >> 0x1E;
            if (mode == 0) {
                isMode0 = 1;
            } else {
                isMode0 = 0;
            }
            if (isMode0 & 0xFF) {
                SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000016);
            } else {
                if (mode == 1) {
                    isMode1 = 1;
                } else {
                    isMode1 = 0;
                }
                if (isMode1 & 0xFF) {
                    SetTextById(M2C_FIELD(panel, s32 *, 0x54), 0x47000017);
                }
            }
        }
    }
    menu = M2C_FIELD(panel,void **,0x6c);
    { u8 y=M2C_FIELD(menu,u8 *,8), x=M2C_FIELD(menu,u8 *,7);
    savedPos=M2C_FIELD(panel,void **,0x40);
    M2C_FIELD(savedPos,u8 *,0x10)=x;
    M2C_FIELD(savedPos,u8 *,0x11)=y; }
    M2C_FIELD(panel,u8 *,0x3a)|=8;
}
#pragma pop
void func_ov003_021ec780(u8 *p,s32 i) {p+=14;p[i]=p[i]==1?2:1;}

s32 InRange(u8,s32,s32);
void StepCounter(s32,s32,s32);
s32 WaypointOptionsDiffer(void*);
#pragma inline on
#pragma opt_propagation on
/* Decrements counter entry `index` by one (wrapping or clamping to its min/max at
 * +0x1c/+0x20 when the wrap byte at +0x28 is set), then steps the sibling counter
 * -1 and recurses while the entry group keeps changing. */
void StepCounterDown(void *counters, s32 index, s32 force) {
    s32 next = M2C_FIELD(counters + 0x18, s32 *, index * 24) - 1;
    if (((s32 (*)(s16, s16, s16))InRange)((s16)next, (s16)M2C_FIELD(counters + 0x20, s32 *, index * 24), (s16)M2C_FIELD(counters + 0x1c, s32 *, index * 24)) || force) {
        M2C_FIELD(counters + 0x18, s32 *, index * 24) = next;
        if (((u8 (*)[24])counters)[index][0x28]) {
            if (M2C_FIELD(counters + 0x18, s32 *, index * 24) > M2C_FIELD(counters + 0x1c, s32 *, index * 24)) {
                s32 entry = counters + index * 24;
                do { M2C_FIELD(entry, s32 *, 0x18) -= M2C_FIELD(entry, s32 *, 0x1c) - M2C_FIELD(entry, s32 *, 0x20) + 1; } while (M2C_FIELD(entry, s32 *, 0x18) > M2C_FIELD(entry, s32 *, 0x1c));
            }
            if (M2C_FIELD(counters + 0x18, s32 *, index * 24) < M2C_FIELD(counters + 0x20, s32 *, index * 24)) {
                s32 entry = counters + index * 24;
                do { M2C_FIELD(entry, s32 *, 0x18) += M2C_FIELD(entry, s32 *, 0x1c) - M2C_FIELD(entry, s32 *, 0x20) + 1; } while (M2C_FIELD(entry, s32 *, 0x18) < M2C_FIELD(entry, s32 *, 0x20));
            }
        } else {
            M2C_FIELD(counters + 0x18, s32 *, index * 24) = M2C_FIELD(counters + 0x18, s32 *, index * 24) > M2C_FIELD(counters + 0x1c, s32 *, index * 24) ? M2C_FIELD(counters + 0x1c, s32 *, index * 24) : (M2C_FIELD(counters + 0x18, s32 *, index * 24) < M2C_FIELD(counters + 0x20, s32 *, index * 24) ? M2C_FIELD(counters + 0x20, s32 *, index * 24) : M2C_FIELD(counters + 0x18, s32 *, index * 24));
        }
    } else {
        if (next > M2C_FIELD(counters + 0x1c, s32 *, index * 24)) next = M2C_FIELD(counters + 0x1c, s32 *, index * 24); else next = next < M2C_FIELD(counters + 0x20, s32 *, index * 24) ? M2C_FIELD(counters + 0x20, s32 *, index * 24) : next;
        M2C_FIELD(counters + 0x18, s32 *, index * 24) = next;
        if (((u8 (*)[24])counters)[index][0x28]) {
            if (M2C_FIELD(counters + 0x18, s32 *, index * 24) > M2C_FIELD(counters + 0x1c, s32 *, index * 24)) {
                s32 entry = counters + index * 24;
                do { M2C_FIELD(entry, s32 *, 0x18) -= M2C_FIELD(entry, s32 *, 0x1c) - M2C_FIELD(entry, s32 *, 0x20) + 1; } while (M2C_FIELD(entry, s32 *, 0x18) > M2C_FIELD(entry, s32 *, 0x1c));
            }
            if (M2C_FIELD(counters + 0x18, s32 *, index * 24) < M2C_FIELD(counters + 0x20, s32 *, index * 24)) {
                s32 entry = counters + index * 24;
                do { M2C_FIELD(entry, s32 *, 0x18) += M2C_FIELD(entry, s32 *, 0x1c) - M2C_FIELD(entry, s32 *, 0x20) + 1; } while (M2C_FIELD(entry, s32 *, 0x18) < M2C_FIELD(entry, s32 *, 0x20));
            }
        } else {
            M2C_FIELD(counters + 0x18, s32 *, index * 24) = M2C_FIELD(counters + 0x18, s32 *, index * 24) > M2C_FIELD(counters + 0x1c, s32 *, index * 24) ? M2C_FIELD(counters + 0x1c, s32 *, index * 24) : (M2C_FIELD(counters + 0x18, s32 *, index * 24) < M2C_FIELD(counters + 0x20, s32 *, index * 24) ? M2C_FIELD(counters + 0x20, s32 *, index * 24) : M2C_FIELD(counters + 0x18, s32 *, index * 24));
        }
    }
    if (ov003_entries_differ(counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (ov003_entries_differ(counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (WaypointOptionsDiffer((void *)counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (WaypointOptionsDiffer((void *)counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (WaypointOptionsDiffer((void *)counters)) return;
    StepCounterDown(counters, index, force);
}
/* Applies the waypoint option panel action the player picked (direction group 0-3,
 * slot group 4-7, option group 8-20, group 21-24, or 25 = confirm): updates the
 * panel's selection and state, and plays the select or error sound. */
void ApplyWaypointMenuAction(void *arg0, u32 arg1) {
    s32 IsLinkSessionActive();
    void PlaySoundEffect(u32);
    s32 IsWaypointOptionValid(u8);
    s32 GetWaypointSlotIndex(s32);
    s32 IsWaypointSlotLocalPlayer(s32, s32);
    void SetWaypointPanelState(void *,s32);
    s32 IsWaypointPanelIdle(void *);
    void UpdateWaypointSelection(void *,s32);
    s32 CanUseWaypointAction(M2C_UNK,M2C_UNK);
    M2C_UNK func_ov003_021eccd4(void *);
    if (CanUseWaypointAction((s32)arg0,arg1) == 0) {
        return;
    }
    switch (arg1) {
    case 0:
    case 1:
    case 2:
    case 3:
        if ((IsLinkSessionActive() != 0) && (IsWaypointSlotLocalPlayer(M2C_FIELD(arg0, s32 *, 0x6C), GetWaypointSlotIndex(M2C_FIELD(arg0, s32 *, 0x6C))) == 0)) {
            PlaySoundEffect(0x1001D);
            return;
        }
        if (IsWaypointPanelIdle(arg0) != 0) {
            SetWaypointPanelState(arg0, 2);
            UpdateWaypointSelection(arg0, 0x1DU);
        } else {
            UpdateWaypointSelection(arg0, arg1);
            SetWaypointPanelState(arg0, 0);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        UpdateWaypointSelection(arg0, arg1);
        if (IsWaypointPanelIdle(arg0) != 0) {
            SetWaypointPanelState(arg0, 1);
        } else {
            SetWaypointPanelState(arg0, 0);
        }
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        if (IsWaypointOptionValid((u8) (arg1 - 8)) == 0) {
            PlaySoundEffect(0x1001D);
            return;
        }
        SetWaypointPanelState(arg0, 0);
        UpdateWaypointSelection(arg0, 0x1BU);
        break;
    case 21:
    case 22:
    case 23:
    case 24:
        UpdateWaypointSelection(arg0, arg1);
        if (IsWaypointPanelIdle(arg0) != 0) {
            SetWaypointPanelState(arg0, 3);
        } else {
            SetWaypointPanelState(arg0, 0);
        }
        break;
    case 25:
        func_ov003_021eccd4(arg0);
        break;
    default:break;
    }
    PlaySoundEffect(0x1000D);
}

/* Whether the waypoint panel may run `action`: every action is allowed without a
 * link session; in one, the groups 0-3, 8-20 and 25 are open to everyone, 21-24
 * only to the session host, and 4-7 to nobody. */
s32 CanUseWaypointAction(M2C_UNK panel,M2C_UNK action) {
s32 IsLinkSessionActive(void);
s32 IsSessionHost(void);
s32 GetWaypointGroupFirstSlot(M2C_UNK);
M2C_UNK GetWaypointGroupCount(M2C_UNK);
s32 groupFirstSlot;
if(IsLinkSessionActive()==0)return 1;
groupFirstSlot=GetWaypointGroupFirstSlot(action);
GetWaypointGroupCount(action);
if(groupFirstSlot==WAYPOINT_GROUP_0_FIRST||groupFirstSlot==WAYPOINT_GROUP_4_FIRST||groupFirstSlot==WAYPOINT_GROUP_2_FIRST)return 1;
if(groupFirstSlot==WAYPOINT_GROUP_1_FIRST)return 0;
if(IsSessionHost()!=0 && groupFirstSlot==WAYPOINT_GROUP_3_FIRST)return 1;
return 0;
}

