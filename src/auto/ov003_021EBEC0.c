/* 8 functions from 0x021EBEC0 to 0x021ECCD4 (ov003), found by ds-decomp. */
#include "common.h"
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } SpritePosC57C;
#pragma opt_propagation off
static inline s32 ov003_entries_differ(s32 arg0) {
 s32 count; s32 entry; u8 i;
 i=0; count=M2C_FIELD(arg0,s8*,4)-1;
 for(;i<count;i++){entry=arg0+i*24; if(M2C_FIELD(entry,s32*,0x18)!=M2C_FIELD(entry,s32*,0x30))return 1;}
 return 0;
}

void func_ov003_021ec4e4(u8 *);
#pragma inline off
void func_ov003_021ebec0(void *p,u32 state){
void PlaySoundEffect(u32);void func_ov003_021ebfcc(void *);s32 IsWaypointPanelIdle(void *);void SetWaypointPanelState(void *,s32);void func_ov003_021ec4e4(u8 *);void UpdateWaypointSelection(void *,s32);
PlaySoundEffect(0x1000f);
switch(state){
case 25:case 3:case 2:case 1:case 0:func_ov003_021ebfcc(p);break;
case 4:case 5:case 6:case 7:
if(IsWaypointPanelIdle(p))func_ov003_021ebfcc(p);else SetWaypointPanelState(p,0);break;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:
func_ov003_021ec4e4(M2C_FIELD(p,u8 **,0x6c));SetWaypointPanelState(p,0);UpdateWaypointSelection(p,27);break;
case 21:case 22:case 23:case 24:
if(IsWaypointPanelIdle(p))func_ov003_021ebfcc(p);else SetWaypointPanelState(p,0);break;
}
}

#pragma push
#pragma opt_propagation on
void func_ov003_021ebfcc(void *p) {
 void PlaySoundEffect(u32); s32 IsLinkSessionActive(void); s32 func_02084d3c(void*,s32); void func_02084d88(void*,s32);
 s32 func_ov003_021e6cfc(void); s32 func_ov003_021e6d28(void);
 void func_02088d94(void*); void func_02088da8(void*); void func_02088f1c(s32); void func_02088ff4(s32);
 s16 GetSpriteAnimValue(void*); void func_ov003_021e74ac(void*,s32); s32 func_020aae44(void*); s32 func_020aae10(void*); s16 func_ov003_022004a8(u8); s32 SetTextById(s32,s32); s32 InRange(u8,s32,s32);
 u8 buf[36]; u32 mode; u8 flag,i,j; u32 n; s32 *entries,*entries2; s32 count; void *s,*unit,*dst; s32 y,x; u8 state;
 PlaySoundEffect(0x1000f);
 if(IsLinkSessionActive()){
  if(!func_02084d3c(buf,0x24))return;
  mode=(u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30;
  flag=mode==0;
  if(flag){
   if(M2C_FIELD(buf,s32*,24)){M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;func_02084d88(buf,0x24);return;}
   if(!func_ov003_021e6cfc())return;
   M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;func_02084d88(buf,0x24);
   {void *self=p;M2C_FIELD(M2C_FIELD(self,void**,0),void(**)(void*),0x20)(self);}return;
  }
  flag=mode==1;if(!flag)return;
  if(!func_ov003_021e6cfc())return;
  buf[8]=0;M2C_FIELD(buf,s32*,24)=0;M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;func_02084d88(buf,0x24);return;
 }
 if(((u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30)==1){
 {u8 v=M2C_FIELD(p,u8*,0x39)&~12;flag=((u32)(v<<28)>>30)==0;M2C_FIELD(p,u8*,0x39)=v;}
 if(flag && func_ov003_021e6d28()){func_02088d94(M2C_FIELD(p,void**,0x58));func_02088f1c(*M2C_FIELD(p,s32**,0x64));}
 entries=M2C_FIELD(p,s32**,0x64);count=M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);n=count&255;
 if(!IsLinkSessionActive()){for(i=0;i<4;i++){if(i<n){func_02088d94((void*)entries[i+2]);func_02088d94((void*)entries[i+6]);}}}
 s=M2C_FIELD(p,void**,0x48);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=0;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 s=M2C_FIELD(p,void**,0x50);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=256;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 s=M2C_FIELD(p,void**,0x4c);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=192;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 flag=((u32)(M2C_FIELD(p,u8*,0x39)<<28)>>30)==1;
 if(flag){
  if(func_ov003_021e6d28()){func_02088da8(M2C_FIELD(p,void**,0x58));func_02088ff4(*M2C_FIELD(p,s32**,0x64));}
  entries2=M2C_FIELD(p,s32**,0x64);for(j=0;j<4;j++){func_02088da8((void*)entries2[j+2]);func_02088da8((void*)entries2[j+6]);}
  s=M2C_FIELD(p,void**,0x48);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=-256;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
  s=M2C_FIELD(p,void**,0x50);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=0;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
  s=M2C_FIELD(p,void**,0x4c);M2C_FIELD(s,s16*,14)=GetSpriteAnimValue(s);M2C_FIELD(s,s16*,16)=94;M2C_FIELD(s,s16*,12)=12;M2C_FIELD(s,u16*,2)=M2C_FIELD(s,u16*,4);
 }
 func_ov003_021e74ac(M2C_FIELD(p,void**,0x6c),0);
 unit=M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0);y=func_020aae44(unit);x=func_020aae10(unit);
 {s16 yy=M2C_FIELD(unit,s16*,0x36),xx=M2C_FIELD(unit,s16*,0x34);dst=M2C_FIELD(p,void**,0x58);M2C_FIELD(dst,s16*,0x34)=xx;M2C_FIELD(dst,s16*,0x36)=yy;}
 ((SpritePosC57C*)((u8*)dst+0x40))->x=x;((SpritePosC57C*)((u8*)dst+0x40))->y=y;
 M2C_FIELD(M2C_FIELD(p,void**,0x5c),s16*,0x34)=func_ov003_022004a8(M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7));
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

void func_ov003_021ec4e4(u8 *p) {
s32 GetLocalPlayerIdForOverlay(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6d28(void);
s32 IsWaypointOptionValid(u8);
u8 v=p[9];
u8 t;
if(func_ov003_021e6cfc()!=0) {
t=(p+p[7])[0x74];
if(t!=GetLocalPlayerIdForOverlay()) {
if((u8)((p+p[7])[0x74]==255)==0)goto update;
}
}
if(func_ov003_021e6d28()!=0) {
t=(p+p[7])[0x74];
if(t!=GetLocalPlayerIdForOverlay())goto update;
}
if(IsWaypointOptionValid(v)==0)return;
update:
(p+p[7])[10]=v;
p[8]=v;
}

#pragma push
#pragma opt_propagation on
/* Applies a waypoint-input action to the option panel's waypoint list and, if
 * the selection changed, refreshes the option cursor, its info text and the
 * saved cursor position. */
void UpdateWaypointSelection(void *panel, s32 action) {
    M2C_UNK SetTextById(s32, s32);
    void PlaySoundEffect(u32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    s32 InRange(u8, M2C_UNK, M2C_UNK);
    M2C_UNK HandleWaypointInput();
    s16 func_ov003_022004a8(u8);
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
    slotY = func_020aae44(slot);
    slotX = func_020aae10(slot);

    { s16 y=M2C_FIELD(slot,s16 *,0x36), x=M2C_FIELD(slot,s16 *,0x34);
    cursor = M2C_FIELD(panel, void **, 0x58);
    M2C_FIELD(cursor, s16 *, 0x34) = x;
    M2C_FIELD(cursor, s16 *, 0x36) = y;
    }
    ((SpritePosC57C *)((u8 *)cursor+0x40))->x=slotX;
    ((SpritePosC57C *)((u8 *)cursor+0x40))->y=slotY;
    M2C_FIELD(M2C_FIELD(panel, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(panel, void **, 0x6C), u8 *, 7));
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
s32 EntriesDiffer(void*);
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
    if (EntriesDiffer((void *)counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (EntriesDiffer((void *)counters)) return;
    StepCounter(counters + 0x14 + index * 24, -1, force);
    if (EntriesDiffer((void *)counters)) return;
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

s32 CanUseWaypointAction(M2C_UNK a,M2C_UNK b) {
s32 IsLinkSessionActive(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6e08(M2C_UNK);
M2C_UNK func_ov003_021e6e18(M2C_UNK);
s32 t;
if(IsLinkSessionActive()==0)return 1;
t=func_ov003_021e6e08(b);
func_ov003_021e6e18(b);
if(t==0||t==25||t==8)return 1;
if(t==4)return 0;
if(func_ov003_021e6cfc()!=0 && t==21)return 1;
return 0;
}

