/* 16 functions from 0x021EAED0 to 0x021EBEC0 (ov003), found by ds-decomp. */
#include "common.h"


#pragma push
#pragma scheduling off
void func_ov003_021eaed0(void *arg0) {
s32 Link_ReceivePacket(void *,s32);void *func_02084e64();s32 GetLocalPlayerIdForOverlay();
s8 func_ov003_021e9c24(void *);void func_ov003_021ea4a8(void *,s32);
s32 func_ov003_021e9c08(void *),func_ov003_021e9c30(void *);
u8 func_ov003_021eba24(void *);u8 func_ov003_021e82fc(s32,s32);s32 func_ov003_021e73c8(s32,s32);
s32 func_ov003_021eba74(void);s32 func_ov003_021eaeb0(void *);
u8 func_ov003_021ebbcc(void *);void func_ov003_021ebc00(void *),func_ov003_021ebc54(void *),func_ov003_021ebb88(void *);
u8 IsWaypointPanelIdle(void *);s32 func_ov003_021e9e58(void *);
void func_ov003_021e984c(void *,s32);void Link_SendPacket(void *,s32);
u8 func_ov003_021ebc88(void *);void func_ov003_021e9e4c(void *);
u8 func_ov003_021ebc90(s32,s32);void func_ov003_021ebca4(s32,s32,s32);
s32 func_ov003_021e73bc(s32,s32);s8 func_ov003_021ebd64(void *,s32);
void func_ov003_021e82f0(s32,s32,s32);u8 GetWaypointSlotIndex(s32);
void func_ov003_021ebde8(void *,s8,s8);
void func_ov003_021e9804(void *),func_ov003_021ebe60(void *);
s32 func_ov003_021e88a4(void *);u8 func_ov003_021e9cd0(s32);
void HandleWaypointPanelCancel(void *,s32);s32 func_ov003_021e74a4(s32);
void func_ov003_021ec780(s32,s32);void StepCounterDown(s32,s32,s32);
s32 func_ov003_021e9e2c(void *);void ApplyWaypointMenuAction(void *,u32),func_ov003_021ed27c(void *,u8);
void func_ov003_021e8354(s32,s32,s32);
void Ov003_UpdateWaypointSlotButtons(s32);s32 func_ov003_021ed8a8(s32),func_ov003_021ed8c4(s32),func_ov003_021ed8cc(s32),func_ov003_021ed8e8(s32);
void UpdateWaypointSelection(void *,u8),SetWaypointPanelState(void *,s32),func_ov003_021eccd4(void *),func_ov003_021ed8f0(void *,s32,u8);
s32 InRange(s32,s32,s32);s32 func_0208eb68(void *);
extern void *gTouchState;extern u16 *gKeyState;
u8 packet[36],send[36];u16 keys;s32 ready,touch;u8 i;u16 held;s32 action,slot;
if(IsLinkSessionActive()){
void *remote;s32 player,current,desired;u8 j,i;s8 count;
if(!Link_ReceivePacket(packet,36))return;
remote=func_02084e64();if(!remote)return;
player=GetLocalPlayerIdForOverlay();
count=func_ov003_021e9c24(arg0);
func_ov003_021ea4a8(arg0,(u32)(M2C_FIELD(arg0,u8 *,0x3a)<<31)>>31);
if(func_ov003_021e9c08(arg0)){
packet[13]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),func_ov003_021eba24(M2C_FIELD(arg0,void **,0x6c)));
if(func_ov003_021e6cfc()){
for(j=0;j<count;j++){if(func_ov003_021e73c8(M2C_FIELD(arg0,s32 *,0x6c),j))packet[j+18]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),j);}
if(((s32(*)(void *))func_ov003_021eba74)(arg0)){
if(func_ov003_021eaeb0(arg0)){M2C_FIELD(*(void **)arg0,s32 (**)(void *),0x1c)(arg0);return;}
packet[8]=1;
}
}
if(((u32)(M2C_FIELD(arg0,u8 *,0x39)<<30)>>31) && func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))func_ov003_021ebc00(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(func_ov003_021e6e40() && IsWaypointPanelIdle(arg0) && func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))func_ov003_021ebc00(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(func_ov003_021e6d28() && IsWaypointPanelIdle(arg0) && func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))func_ov003_021ebc00(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(func_ov003_021e9e58(arg0) && !func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))func_ov003_021ebc54(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(M2C_FIELD(remote,u8 *,8)==1){
func_ov003_021e984c(arg0,1);func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,4));
if(func_ov003_021e6d28())Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,4));
M2C_FIELD(packet,s32 *,24)=1;Link_SendPacket(packet,36);return;
}
}
if(func_ov003_021e9c30(arg0)){
if(func_ov003_021e6cfc()){
if(!func_ov003_021ebc88(M2C_FIELD(arg0,void **,0x58)))func_ov003_021e9e4c(M2C_FIELD(arg0,void **,0x58));
for(j=0;j<count;j++)packet[j+14]=func_ov003_021ebc90(M2C_FIELD(arg0,s32 *,0x6c),j);
}
if(M2C_FIELD(remote,u8 *,8)==0){
PlaySoundEffect(0x1000f);func_ov003_021e984c(arg0,0);
func_02088f1c(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,4));
func_ov003_021e9e4c(M2C_FIELD(arg0,void **,0x58));
if(func_ov003_021e6d28())Show3DSprite(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s32 *,0));
Link_SendPacket(packet,36);return;
}
}
Link_SendPacket(packet,36);
for(i=0;i<count;i++){
if(func_ov003_021e6d28()){
current=func_ov003_021ebc90(M2C_FIELD(arg0,s32 *,0x6c),i);desired=M2C_FIELD((u8 *)remote+i,u8 *,14);
if(current!=desired){PlaySoundEffect(0x10011);func_ov003_021ebca4(M2C_FIELD(arg0,s32 *,0x6c),i,desired);}
}
if(player==func_ov003_021e73bc(M2C_FIELD(arg0,s32 *,0x6c),i))continue;
if(func_ov003_021e6cfc() && func_ov003_021e73c8(M2C_FIELD(arg0,s32 *,0x6c),i))continue;
{s32 co=(s8)func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),i);
desired=func_ov003_021ebd64(arg0,i);
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
if(func_ov003_021e9c08(arg0) && M2C_FIELD(packet,s32 *,24)){
if(!func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)))func_ov003_021ebc54(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));
if(func_ov003_021ebc88(M2C_FIELD(arg0,void **,0x58)))func_ov003_021e9804(M2C_FIELD(arg0,void **,0x58));
func_ov003_021ebe60(M2C_FIELD(arg0,void **,0x64));
if(func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0))){func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));}
if(M2C_FIELD(gTouchState,u8 *,0x12))return;
if(!(*gKeyState&2))return;
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));return;
}else if(func_ov003_021e6d28() && func_ov003_021e9c30(arg0))return;
}
touch=M2C_FIELD(gTouchState,u8 *,0x12);ready=1;keys=gKeyState[0];held=gKeyState[1];
func_ov003_021ebe60(M2C_FIELD(arg0,void **,0x64));
if(func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0))){
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}
for(i=0;i<func_ov003_021e74a4(M2C_FIELD(arg0,s32 *,0x6c));i++){
if(ready && func_ov003_021e88a4(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,8))){
func_ov003_021ec780(M2C_FIELD(arg0,s32 *,0x6c),i);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,8));PlaySoundEffect(0x10011);ready=0;
}else if(ready && func_ov003_021e88a4(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,24))){
func_ov003_021ec780(M2C_FIELD(arg0,s32 *,0x6c),i);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,24));PlaySoundEffect(0x10011);ready=0;
}else if(ready && func_ov003_021e88a4(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,40))){
StepCounterDown(M2C_FIELD(arg0,s32 *,0x6c),i,1);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,40));
if(func_ov003_021e9e2c(arg0))ApplyWaypointMenuAction(arg0,(u8)(i+21));else func_ov003_021ed27c(arg0,(u8)(i+21));
PlaySoundEffect(0x10011);ready=0;
}else if(ready && func_ov003_021e88a4(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,56))){
func_ov003_021e8354(M2C_FIELD(arg0,s32 *,0x6c),i,1);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+i*4,void **,56));
if(func_ov003_021e9e2c(arg0))ApplyWaypointMenuAction(arg0,(u8)(i+21));else func_ov003_021ed27c(arg0,(u8)(i+21));
PlaySoundEffect(0x10011);ready=0;
}
}

Ov003_UpdateWaypointSlotButtons(M2C_FIELD(arg0,s32 *,0x6c));
action=func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c));
slot=GetWaypointSlotIndex(M2C_FIELD(arg0,s32 *,0x6c));
if(ready && func_ov003_021ed8a8(M2C_FIELD(arg0,s32 *,0x6c))){
ApplyWaypointMenuAction(arg0,(u8)func_ov003_021ed8c4(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}else{
if(func_ov003_021ed8cc(M2C_FIELD(arg0,s32 *,0x6c)))func_ov003_021ed27c(arg0,(u8)func_ov003_021ed8e8(M2C_FIELD(arg0,s32 *,0x6c)));
}
if(!touch){
if(ready && (keys&1)){ApplyWaypointMenuAction(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;}
if(ready && (keys&8)){UpdateWaypointSelection(arg0,25);SetWaypointPanelState(arg0,0);ready=0;func_ov003_021eccd4(arg0);}
if(ready && func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0)) && (keys&2)){
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(arg0,void **,0x64),void **,0));HandleWaypointPanelCancel(arg0,func_ov003_021e9cd0(M2C_FIELD(arg0,s32 *,0x6c)));ready=0;
}
if(held&64)func_ov003_021ed8f0(arg0,64,keys&64);
if(held&128)func_ov003_021ed8f0(arg0,128,(u8)(keys&128));
if(held&32)func_ov003_021ed8f0(arg0,32,keys&32);
if(held&16)func_ov003_021ed8f0(arg0,16,keys&16);
if(ready && (keys&512)){
action=(s16)action;
if(InRange(action,4,7)){func_ov003_021ec780(M2C_FIELD(arg0,s32 *,0x6c),slot);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,8));PlaySoundEffect(0x10011);}
else if(InRange(action,21,24)){StepCounterDown(M2C_FIELD(arg0,s32 *,0x6c),slot,1);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,56));PlaySoundEffect(0x10011);}
}else if(ready && (keys&256)){
action=(s16)action;
if(InRange(action,4,7)){func_ov003_021ec780(M2C_FIELD(arg0,s32 *,0x6c),slot);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,24));PlaySoundEffect(0x10011);}
else if(InRange(action,21,24)){func_ov003_021e8354(M2C_FIELD(arg0,s32 *,0x6c),slot,1);func_ov003_021ebb88(M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x64)+slot*4,void **,40));PlaySoundEffect(0x10011);}
}
}
if(IsLinkSessionActive()){
if(!Link_ReceivePacket(send,36))return;
send[13]=func_ov003_021e82fc(M2C_FIELD(arg0,s32 *,0x6c),func_ov003_021eba24(M2C_FIELD(arg0,void **,0x6c)));
Link_SendPacket(send,36);
}
if(!func_ov003_021e6e40())return;
if(!IsLinkSessionActive())return;
if(!func_0208eb68(M2C_FIELD(arg0,void **,0x60)))return;
ApplyWaypointMenuAction(arg0,25);M2C_FIELD(arg0,u8 *,0x39)|=2;
}
#pragma pop
u8 func_ov003_021eba24(void *arg0) {
 s32 GetLocalPlayerIdForOverlay();
 s32 value;
 u8 i;
 u8 count;
 s8 result;
 value=GetLocalPlayerIdForOverlay();
 count=M2C_FIELD(arg0,u8 *,4);
 for(i=0;(u32)i<(u32)count;i++) {
  if(value==M2C_FIELD(arg0+i,u8 *,0x74)) {result=(s8)i; goto done;}
 }
 result=-1;
done:
 return (u8)result;
}

s32 func_ov003_021eba74(void) {
 s32 IsLinkSessionActive();
 s32 GetReadyPlayerMask();
 void *func_02084e24(s32);
 s8 i;
 s32 mask;
 void *p;
 if(IsLinkSessionActive()==0) return 0;
 mask=GetReadyPlayerMask();
 for(i=0;i<4;i++) {
  if(mask & (1<<i)) {
   p=func_02084e24(i);
   if(p==NULL) return 0;
   if(M2C_FIELD(p,s32 *,0x18)==0) return 0;
  }
 }
 return 1;
}

void func_ov003_021ebae0(void *arg0) {
    M2C_UNK func_ov003_021e88e0(void *);
    void *temp_r0;

    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) | 0x80);
    PlaySoundEffect(0x1000D);
    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), void **, 4);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    Hide3DSprite(M2C_FIELD(arg0, s32 *, 0x58));
    Hide3DSprite(M2C_FIELD(arg0, s32 *, 0x5C));
    SetOv003SceneState(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_021e6cfc() == 0) {
        return;
    }
    func_ov003_021e88e0(arg0);
}

void func_ov003_021ebb88(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s8 *, 0x5A) < 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0xC;
}

u8 func_ov003_021ebbcc(void *arg0) {
    u8 var_r0;

    if ((((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) != (u16) ((u32) (M2C_FIELD(arg0, s32 *, 0x40) << 6) >> 0x18)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021ebc00(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0;
}

u8 IsWaypointPanelIdle(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021ebc54(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0;
}

u8 func_ov003_021ebc88(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x59);
}

u8 func_ov003_021ebc90(s32 arg0, s32 arg1) {
    return (u8) M2C_FIELD(((arg1 * 0x18) + arg0), s32 *, 0x18);
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

s8 func_ov003_021ebd64(void *arg0,s32 arg1) {
 void *func_02084e24(s32);
 void *func_02084e64(s32);
 s32 GetPlayerCoId(s32);
 s32 GetPlayerCoIconIndex(u8);
 s32 id=M2C_FIELD(M2C_FIELD(arg0,s32 *,0x6c)+arg1,u8 *,0x74);
 u8 missing;
 void *p;
 if(id==0xff) missing=1; else missing=0;
 if(!missing) {
  p=func_02084e24(id);
  if(p) return M2C_FIELD(p,s8 *,0xd);
  return (s8)GetPlayerCoIconIndex((u8)GetPlayerCoId(arg1+1));
 }
 p=func_02084e64(id);
 if(p) return M2C_FIELD(p+arg1,s8 *,0x12);
 return (s8)GetPlayerCoIconIndex((u8)GetPlayerCoId(arg1+1));
}

void func_ov003_021ebde8(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 0x10) = arg1;
    M2C_FIELD(arg0, s8 *, 0x11) = arg2;
}

void func_ov003_021ebdf4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6e40();
    M2C_UNK func_ov003_021e891c(void *);
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) & ~0x80);
    PlaySoundEffect(0x1000F);
    Hide3DSprite(M2C_FIELD(arg0, s32 *, 0x58));
    Hide3DSprite(M2C_FIELD(arg0, s32 *, 0x5C));
    SetOv003SceneState(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_021e6cfc() == 0) {
        return;
    }
    if (func_ov003_021e6e40() != 0) {
        return;
    }
    func_ov003_021e891c(arg0);
}

void func_ov003_021ebe60(void *arg0) {
 M2C_UNK MenuSpriteUpdate(s32);
 u8 i;
 MenuSpriteUpdate(M2C_FIELD(arg0,s32 *,0));
 MenuSpriteUpdate(M2C_FIELD(arg0,s32 *,4));
 for(i=0;(u32)i<4U;i++) {
  MenuSpriteUpdate(((s32 *)(arg0+8))[i]);
  MenuSpriteUpdate(((s32 *)(arg0+0x18))[i]);
  MenuSpriteUpdate(((s32 *)(arg0+0x28))[i]);
  MenuSpriteUpdate(((s32 *)(arg0+0x38))[i]);
 }
}

