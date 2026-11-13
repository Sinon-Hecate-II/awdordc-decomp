/* 11 functions from 0x020DF1D0 to 0x020E0194 (main), found by ds-decomp. */
#include "common.h"

static inline u8 SpriteChangedDF(void *q) {
 u32 base; s32 next,test;
 base=(u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28;
 next=base+2;
 if(next!=(u16)((u32)(M2C_FIELD(q,u32 *,0x40)<<6)>>24))test=1;else test=0;
 return test&255;
}
static inline void SpriteStateDF(void *q,u32 value,s32 timer) {
 M2C_FIELD(q,u32 *,0x40)=(M2C_FIELD(q,u32 *,0x40)&~0x3fc0000)|((u32)((u16)value<<24)>>6);
 M2C_FIELD(q,u8 *,0x5a)=timer;
}
static inline u8 SpritePressedDF(void *q) {
 void *p=M2C_FIELD(q,void **,0x64);s32 yes=1;
 if(M2C_FIELD(p,s8 *,11)!=1) {
 if(!((u32)(M2C_FIELD(q,u8 *,0x59)<<27)>>31)||M2C_FIELD(p,s8 *,12)!=1)yes=0;
 }
 return yes&255;
}




static inline void SpriteResetDF(void *q) {
 u32 base; s32 next,test;
 base=(u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28;
 next=base+2;
 if(next!=(u16)((u32)(M2C_FIELD(q,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255))SpriteStateDF(q,base,0);
}

static inline s32 SpriteCancelDF(void *q,u16 keys) {
 u32 base=(u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(q,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(test&255) { if(SpritePressedDF(q)||(keys&2)) {
 if(M2C_FIELD(q,s8 *,0x5a)>=0)SpriteStateDF(q,base+1,12);
 return 1;
 }}
 return 0;
}

#pragma opt_common_subs off
/* Per-frame update for the link/multiplayer player-list menu: animates its
 * three row sprites, handles back (B) and ready (A) input, plays page/count
 * sounds, and mirrors the menu onto the requested DS screen side. */
void LinkMenuUpdate(void *menu) {
 void MenuSpriteUpdate(void *);void func_02088f1c(void *);void func_02088ff4(void *);
 void func_020d47f0(void);void func_01ffa6fc(void *);void func_ov010_022294ec(void);void PlaySoundEffect(s32);
 u32 GetActivePlayerMask(void);u32 CountBits(void);u32 func_ov010_02229a40(void);
 s32 func_ov010_022282b4(s32);s32 func_ov010_02229bdc(void);
 void SetTextById(void *,s32);u32 GetReadyPlayerMask(void);
 void func_ov010_0222952c(void);void func_ov010_02229a94(void);void func_020d47d0(void);void ResetPlayerMask(void);
 s32 func_020890b8(void *);s32 func_02089064(void *);void *func_ov010_02229b0c(s32);
 extern u16 *gKeyState;
 extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
 s32 func_0208b5ec(void);void func_0208af20(void);void *func_0208b564(void *);void func_020899cc(void *,s32,s32,u32);
 void *sprite,*unused;u16 keys;u32 readyMask,playerCount;s32 prevPlayerCount;
 sprite=M2C_FIELD(menu,void **,0x50);if(sprite)MenuSpriteUpdate(sprite);
 sprite=M2C_FIELD(menu,void **,0x54);if(sprite)MenuSpriteUpdate(sprite);
 sprite=M2C_FIELD(menu,void **,0x58);if(sprite)MenuSpriteUpdate(sprite);
 keys=*gKeyState;M2C_FIELD(menu,u16 *,0x48)&=~32;
 {void *flipSprite=M2C_FIELD(menu,void **,0x58);
 u32 base=(u32)(M2C_FIELD(flipSprite,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(flipSprite,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(test&255) {
 if(SpritePressedDF(flipSprite)||(keys&2)) {
 if(M2C_FIELD(flipSprite,s8 *,0x5a)>=0)SpriteStateDF(flipSprite,base+1,12);
 func_020d47f0();func_01ffa6fc(menu);func_ov010_022294ec();PlaySoundEffect(0x1000f);return;
 }
 }

 }
 GetActivePlayerMask();playerCount=CountBits();prevPlayerCount=M2C_FIELD(menu,s8 *,0x41);
 if(prevPlayerCount>1||playerCount>1) {
 if(prevPlayerCount!=playerCount) {
 PlaySoundEffect(prevPlayerCount<(s32)playerCount?0x122:0x123);
 M2C_FIELD(menu,s8 *,0x41)=playerCount;
 }
 }
 if(M2C_FIELD(menu,u16 *,0x48)&0x100) {
 if(func_0208b5ec())func_0208af20();
 {s32 i; void *savedEngine=gCur3DSpriteEngine;
 for(i=0;i<2;i++) {
 u8 screen;gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
 screen=M2C_FIELD(menu,u8 *,0x44);
 if(screen==0&&gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;
 if(screen==1&&gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;
 if(screen==3&&gCur3DSpriteEngine!=savedEngine)continue;
 {void *drawn=func_0208b564(menu);func_020899cc(drawn,2,M2C_FIELD(menu,u16 *,0x46)<<5,0x44000001);M2C_FIELD(drawn,u32 *,0x58)|=0x1000;}
 }
 gCur3DSpriteEngine=savedEngine;
 }
 func_020d47f0();func_01ffa6fc(menu);func_ov010_022294ec();return;
 }
 if(func_ov010_02229a40()>=2&&func_ov010_022282b4(3)) {
 if(M2C_FIELD(menu,s16 *,0x4c)>0)M2C_FIELD(menu,s16 *,0x4c)--;
 if(func_ov010_02229bdc()) {
 sprite=M2C_FIELD(menu,void **,0x54);
 {u32 base=(u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28; s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(sprite,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255)) {SpriteStateDF(sprite,base,0);
 func_02088f1c(M2C_FIELD(menu,void **,0x54));SetTextById(M2C_FIELD(menu,void **,0x64),0x44000012);}}
 {sprite=M2C_FIELD(menu,void **,0x54);
 if(!SpriteChangedDF(sprite))return;
 if(!SpritePressedDF(sprite)&&!(keys&1)&&M2C_FIELD(menu,s16 *,0x4c)!=0)return;
 }
 readyMask=GetReadyPlayerMask();if(readyMask!=GetActivePlayerMask())return;
 sprite=M2C_FIELD(menu,void **,0x54);
 if(M2C_FIELD(sprite,s8 *,0x5a)>=0)SpriteStateDF(sprite,((u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28)+1,12);
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(menu);PlaySoundEffect(0x1000e);return;
 } else {
 sprite=M2C_FIELD(menu,void **,0x60);
 if(!func_020890b8(sprite)&&!func_02089064(M2C_FIELD(menu,void **,0x60))) {func_02088f1c(M2C_FIELD(menu,void **,0x60));
 SetTextById(M2C_FIELD(menu,void **,0x64),0x44000012);}
 {void *entry=func_ov010_02229b0c(0);if(!entry)return;if(M2C_FIELD(entry,u8 *,0x1a)&2)return;}
 readyMask=GetReadyPlayerMask();if(readyMask!=GetActivePlayerMask())return;
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(menu);PlaySoundEffect(0x1000e);return;
 }
 } else {
 M2C_FIELD(menu,s16 *,0x4c)=0x708;
 if(func_ov010_02229bdc()) {
 {void *row=M2C_FIELD(menu,void **,0x54);
 u32 base=(u32)(M2C_FIELD(row,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(row,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255))return;
 SpriteStateDF(row,next,0);
 }
 func_02088ff4(M2C_FIELD(menu,void **,0x54));SetTextById(M2C_FIELD(menu,void **,0x64),0x44000011);
 } else {
 if(func_020890b8(M2C_FIELD(menu,void **,0x60)))return;
 if(!func_02089064(M2C_FIELD(menu,void **,0x60)))return;
 func_02088ff4(M2C_FIELD(menu,void **,0x60));SetTextById(M2C_FIELD(menu,void **,0x64),0x44000011);
 }
 }
}

#pragma opt_common_subs off
void func_020df718(void *arg0) {
 void MenuSpriteUpdate(void *);void func_02088f1c(void *);void func_02088ff4(void *);
 void func_020d47f0(void);void func_01ffa6fc(void *);void func_ov010_022294ec(void);void PlaySoundEffect(s32);
 u32 GetActivePlayerMask(void);u32 CountBits(void);u32 func_ov010_02229a40(void);
 s32 func_ov010_022282b4(s32);s32 func_ov010_02229bdc(void);
 void SetTextById(void *,s32);u32 GetReadyPlayerMask(void);
 void func_ov010_0222952c(void);void func_ov010_02229a94(void);void func_020d47d0(void);void ResetPlayerMask(void);
 s32 func_020890b8(void *);s32 func_02089064(void *);void *func_ov010_02229b0c(s32);
 extern u16 *gKeyState;
 void *q,*p;u16 keys;u32 state,now;s32 old;
 q=M2C_FIELD(arg0,void **,0x50);if(q)MenuSpriteUpdate(q);
 q=M2C_FIELD(arg0,void **,0x54);if(q)MenuSpriteUpdate(q);
 q=M2C_FIELD(arg0,void **,0x58);if(q)MenuSpriteUpdate(q);
 keys=*gKeyState;M2C_FIELD(arg0,u16 *,0x48)&=~32;
 {void *q=M2C_FIELD(arg0,void **,0x58);
 u32 base=(u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(q,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(test&255) {
 if(SpritePressedDF(q)||(keys&2)) {
 if(M2C_FIELD(q,s8 *,0x5a)>=0)SpriteStateDF(q,base+1,12);
 func_020d47f0();func_01ffa6fc(arg0);func_ov010_022294ec();PlaySoundEffect(0x1000f);return;
 }
 }

 }
 GetActivePlayerMask();now=CountBits();old=M2C_FIELD(arg0,s8 *,0x41);
 if(old>1||now>1) {
 if(old!=now) {
 PlaySoundEffect(old<(s32)now?0x122:0x123);
 M2C_FIELD(arg0,s8 *,0x41)=now;
 }
 }
 if(func_ov010_02229a40()>=2&&func_ov010_022282b4(3)) {
 if(func_ov010_02229bdc()) {
 q=M2C_FIELD(arg0,void **,0x54);
 SpriteResetDF(q);
 func_02088f1c(M2C_FIELD(arg0,void **,0x54));SetTextById(M2C_FIELD(arg0,void **,0x64),0x44000012);
 {void *button=M2C_FIELD(arg0,void **,0x54);
 {u32 base=(u32)(M2C_FIELD(button,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(button,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255))return;}
 if(!SpritePressedDF(button)&&!(keys&1))return;
 }
 state=GetReadyPlayerMask();if(state!=GetActivePlayerMask())return;
 q=M2C_FIELD(arg0,void **,0x54);
 if(M2C_FIELD(q,s8 *,0x5a)>=0)SpriteStateDF(q,((u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28)+1,12);
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(arg0);PlaySoundEffect(0x1000e);return;
 } else {
 q=M2C_FIELD(arg0,void **,0x60);
 if(!func_020890b8(q)&&!func_02089064(M2C_FIELD(arg0,void **,0x60)))func_02088f1c(M2C_FIELD(arg0,void **,0x60));
 SetTextById(M2C_FIELD(arg0,void **,0x64),0x44000012);
 {void *entry=func_ov010_02229b0c(0);if(!entry)return;if(M2C_FIELD(entry,u8 *,0x1a)&2)return;}
 state=GetReadyPlayerMask();if(state!=GetActivePlayerMask())return;
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(arg0);PlaySoundEffect(0x1000e);return;
 }
 } else {
 if(func_ov010_02229bdc()) {
 {void *q=M2C_FIELD(arg0,void **,0x54);
 u32 base=(u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(q,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255))return;
 SpriteStateDF(q,next,0);
 }
 func_02088ff4(M2C_FIELD(arg0,void **,0x54));SetTextById(M2C_FIELD(arg0,void **,0x64),0x44000011);
 } else {
 if(func_020890b8(M2C_FIELD(arg0,void **,0x60)))return;
 if(!func_02089064(M2C_FIELD(arg0,void **,0x60)))return;
 func_02088ff4(M2C_FIELD(arg0,void **,0x60));SetTextById(M2C_FIELD(arg0,void **,0x64),0x44000011);
 }
 }
}
#pragma opt_common_subs off
/* Per-frame update of the link-menu variant that also handles the left/right
 * page-flip flags (0x100/0x200).  It animates the three row sprites, drives the
 * back and ready buttons through their confirm/back animations, mirrors the menu
 * onto the requested DS screen, keeps the player-count sound in sync and commits
 * the ready state when every player is ready. */
void LinkMenuPageFlipUpdate(void *menu) {
 void MenuSpriteUpdate(void *);void func_02088f1c(void *);void func_02088ff4(void *);
 void func_020d47f0(void);void func_01ffa6fc(void *);void func_ov010_022294ec(void);void PlaySoundEffect(s32);
 u32 GetActivePlayerMask(void);u32 CountBits(void);u32 func_ov010_02229a40(void);
 s32 func_ov010_022282b4(s32);s32 func_ov010_02229bdc(void);
 void SetTextById(void *,s32);u32 GetReadyPlayerMask(void);
 void func_ov010_0222952c(void);void func_ov010_02229a94(void);void func_020d47d0(void);void ResetPlayerMask(void);
 s32 func_020890b8(void *);s32 func_02089064(void *);void *func_ov010_02229b0c(s32);
 extern u16 *gKeyState;
 extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
 s32 func_0208b5ec(void);void func_0208af20(void);void *func_0208b564(void *);void func_020899cc(void *,s32,s32,u32);
 void *sprite;u16 keys;u32 readyMask,playerCount;s32 prevPlayerCount;
 sprite=M2C_FIELD(menu,void **,0x50);if(sprite)MenuSpriteUpdate(sprite);
 sprite=M2C_FIELD(menu,void **,0x54);if(sprite)MenuSpriteUpdate(sprite);
 sprite=M2C_FIELD(menu,void **,0x58);if(sprite)MenuSpriteUpdate(sprite);
 keys=*gKeyState;M2C_FIELD(menu,u16 *,0x48)&=~32;

 if(!(M2C_FIELD(menu,u16 *,0x48)&1)) {
 if(M2C_FIELD(menu,u16 *,0x48)&0x100) {
 if(func_0208b5ec())func_0208af20();
 {s32 sideIndex; void *savedEngine=gCur3DSpriteEngine;
 for(sideIndex=0;sideIndex<2;sideIndex++) {
 u8 screen;gCur3DSpriteEngine=sideIndex==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
 screen=M2C_FIELD(menu,u8 *,0x44);
 if(screen==0&&gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;
 if(screen==1&&gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;
 if(screen==3&&gCur3DSpriteEngine!=savedEngine)continue;
 {void *effect=func_0208b564(menu);func_020899cc(effect,2,M2C_FIELD(menu,u16 *,0x46)<<5,0x44000001);M2C_FIELD(effect,u32 *,0x58)|=0x1000;}
 }
 gCur3DSpriteEngine=savedEngine;
 }
 func_020d47f0();func_01ffa6fc(menu);func_ov010_022294ec();return;
 }
 if(M2C_FIELD(menu,u16 *,0x48)&0x200) {
 if(func_0208b5ec())func_0208af20();
 {s32 sideIndex; void *savedEngine=gCur3DSpriteEngine;
 for(sideIndex=0;sideIndex<2;sideIndex++) {
 u8 screen;gCur3DSpriteEngine=sideIndex==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
 screen=M2C_FIELD(menu,u8 *,0x44);
 if(screen==0&&gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;
 if(screen==1&&gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;
 if(screen==3&&gCur3DSpriteEngine!=savedEngine)continue;
 {void *effect=func_0208b564(menu);func_020899cc(effect,2,M2C_FIELD(menu,u16 *,0x46)<<5,0x44000002);M2C_FIELD(effect,u32 *,0x58)|=0x1000;}
 }
 gCur3DSpriteEngine=savedEngine;
 }
 func_020d47f0();func_01ffa6fc(menu);func_ov010_022294ec();return;
 }

 }
 {void *backSprite=M2C_FIELD(menu,void **,0x58);
 u32 frameBase=(u32)(M2C_FIELD(backSprite,u8 *,0x59)<<28)>>28;
 s32 nextFrame=frameBase+2,frameChanged;
 if(nextFrame!=(u16)((u32)(M2C_FIELD(backSprite,u32 *,0x40)<<6)>>24))frameChanged=1;else frameChanged=0;
 if(frameChanged&255) {
 if(SpritePressedDF(backSprite)||(keys&2)) {
 if(M2C_FIELD(backSprite,s8 *,0x5a)>=0)SpriteStateDF(backSprite,frameBase+1,12);
 func_020d47f0();func_01ffa6fc(menu);func_ov010_022294ec();PlaySoundEffect(0x1000f);return;
 }
 }

 }
 GetActivePlayerMask();playerCount=CountBits();prevPlayerCount=M2C_FIELD(menu,s8 *,0x41);
 if(prevPlayerCount>1||playerCount>1) {
 if(prevPlayerCount!=playerCount) {
 PlaySoundEffect(prevPlayerCount<(s32)playerCount?0x122:0x123);
 M2C_FIELD(menu,s8 *,0x41)=playerCount;
 }
 }

 if(M2C_FIELD(menu,u16 *,0x48)&1) {
 if(func_ov010_02229a40()>=2) {
 sprite=M2C_FIELD(menu,void **,0x54);
 {u32 frameBase=(u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28;
 s32 nextFrame=frameBase+2,frameChanged;
 if(nextFrame!=(u16)((u32)(M2C_FIELD(sprite,u32 *,0x40)<<6)>>24))frameChanged=1;else frameChanged=0;
 if(!(frameChanged&255)) {
 SpriteStateDF(sprite,frameBase,0);
 func_02088f1c(M2C_FIELD(menu,void **,0x54));
 SetTextById(M2C_FIELD(menu,void **,0x64),0x44000012);
 }}
 } else {
 sprite=M2C_FIELD(menu,void **,0x54);
 {u32 frameBase=(u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28;
 s32 nextFrame=frameBase+2,frameChanged;
 if(nextFrame!=(u16)((u32)(M2C_FIELD(sprite,u32 *,0x40)<<6)>>24))frameChanged=1;else frameChanged=0;
 if(frameChanged&255) {
 SpriteStateDF(sprite,nextFrame,0);
 func_02088ff4(M2C_FIELD(menu,void **,0x54));
 SetTextById(M2C_FIELD(menu,void **,0x64),0x44000011);
 }}
 }
 sprite=M2C_FIELD(menu,void **,0x54);
 if(!SpriteChangedDF(sprite))return;
 if(!SpritePressedDF(sprite)&&!(keys&1))return;
 readyMask=GetReadyPlayerMask();if(readyMask!=GetActivePlayerMask())return;
 sprite=M2C_FIELD(menu,void **,0x54);
 if(M2C_FIELD(sprite,s8 *,0x5a)>=0)SpriteStateDF(sprite,((u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28)+1,12);
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(menu);PlaySoundEffect(0x1000e);return;
 } else {
 if(func_ov010_02229a40()>=2) {
 if(!func_020890b8(M2C_FIELD(menu,void **,0x60))&&!func_02089064(M2C_FIELD(menu,void **,0x60))) {
 func_02088f1c(M2C_FIELD(menu,void **,0x60));SetTextById(M2C_FIELD(menu,void **,0x64),0x44000012);
 }
 } else {
 if(!func_020890b8(M2C_FIELD(menu,void **,0x60))&&func_02089064(M2C_FIELD(menu,void **,0x60))) {
 func_02088ff4(M2C_FIELD(menu,void **,0x60));SetTextById(M2C_FIELD(menu,void **,0x64),0x44000011);
 }
 }
 {void *entry=func_ov010_02229b0c(0);if(!entry)return;if(M2C_FIELD(entry,u8 *,0x1a)&2)return;}
 readyMask=GetReadyPlayerMask();if(readyMask!=GetActivePlayerMask())return;
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();ResetPlayerMask();func_01ffa6fc(menu);PlaySoundEffect(0x1000e);return;
 }
}
#pragma opt_common_subs reset
void func_020e0134(void) {
    M2C_UNK func_020debf4();
    func_020debf4();
}

void func_020e0140(void) {
    func_020debf4();
}

void func_020e014c(void *arg0) {
    LinkMenuUpdate(arg0);
}

void func_020e0158(void *arg0) {
    LinkMenuUpdate(arg0);
}

void func_020e0164(void *arg0) {
    void func_020df718(void *);
    func_020df718(arg0);
}

void func_020e0170(void *arg0) {
    func_020df718(arg0);
}

void func_020e017c(void *menu) {
    LinkMenuPageFlipUpdate(menu);
}

void func_020e0188(void *menu) {
    LinkMenuPageFlipUpdate(menu);
}

