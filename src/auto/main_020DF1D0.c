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

M2C_UNK func_020df1d0(void) { return 0; }

#pragma opt_common_subs off
void func_020df718(void *arg0) {
 void MenuSpriteUpdate(void *);void func_02088f1c(void *);void func_02088ff4(void *);
 void func_020d47f0(void);void func_01ffa6fc(void *);void func_ov010_022294ec(void);void PlaySoundEffect(s32);
 u32 func_02084970(void);u32 func_02076614(void);u32 func_ov010_02229a40(void);
 s32 func_ov010_022282b4(s32);s32 func_ov010_02229bdc(void);
 void func_0208b758(void *,s32);u32 func_020848f8(void);
 void func_ov010_0222952c(void);void func_ov010_02229a94(void);void func_020d47d0(void);void func_02084a40(void);
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
 func_02084970();now=func_02076614();old=M2C_FIELD(arg0,s8 *,0x41);
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
 func_02088f1c(M2C_FIELD(arg0,void **,0x54));func_0208b758(M2C_FIELD(arg0,void **,0x64),0x44000012);
 {void *button=M2C_FIELD(arg0,void **,0x54);
 {u32 base=(u32)(M2C_FIELD(button,u8 *,0x59)<<28)>>28;
 s32 next=base+2,test;
 if(next!=(u16)((u32)(M2C_FIELD(button,u32 *,0x40)<<6)>>24))test=1;else test=0;
 if(!(test&255))return;}
 if(!SpritePressedDF(button)&&!(keys&1))return;
 }
 state=func_020848f8();if(state!=func_02084970())return;
 q=M2C_FIELD(arg0,void **,0x54);
 if(M2C_FIELD(q,s8 *,0x5a)>=0)SpriteStateDF(q,((u32)(M2C_FIELD(q,u8 *,0x59)<<28)>>28)+1,12);
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();func_02084a40();func_01ffa6fc(arg0);PlaySoundEffect(0x1000e);return;
 } else {
 q=M2C_FIELD(arg0,void **,0x60);
 if(!func_020890b8(q)&&!func_02089064(M2C_FIELD(arg0,void **,0x60)))func_02088f1c(M2C_FIELD(arg0,void **,0x60));
 func_0208b758(M2C_FIELD(arg0,void **,0x64),0x44000012);
 {void *entry=func_ov010_02229b0c(0);if(!entry)return;if(M2C_FIELD(entry,u8 *,0x1a)&2)return;}
 state=func_020848f8();if(state!=func_02084970())return;
 func_ov010_0222952c();func_ov010_02229a94();func_020d47d0();func_02084a40();func_01ffa6fc(arg0);PlaySoundEffect(0x1000e);return;
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
 func_02088ff4(M2C_FIELD(arg0,void **,0x54));func_0208b758(M2C_FIELD(arg0,void **,0x64),0x44000011);
 } else {
 if(func_020890b8(M2C_FIELD(arg0,void **,0x60)))return;
 if(!func_02089064(M2C_FIELD(arg0,void **,0x60)))return;
 func_02088ff4(M2C_FIELD(arg0,void **,0x60));func_0208b758(M2C_FIELD(arg0,void **,0x64),0x44000011);
 }
 }
}
#pragma opt_common_subs reset
M2C_UNK func_020dfb58(void) { return 0; }

void func_020e0134(void) {
    M2C_UNK func_020debf4();
    func_020debf4();
}

void func_020e0140(void) {
    func_020debf4();
}

void func_020e014c(void) {
    M2C_UNK func_020df1d0();
    func_020df1d0();
}

void func_020e0158(void) {
    func_020df1d0();
}

void func_020e0164(void *arg0) {
    void func_020df718(void *);
    func_020df718(arg0);
}

void func_020e0170(void *arg0) {
    func_020df718(arg0);
}

void func_020e017c(void) {
    M2C_UNK func_020dfb58();
    func_020dfb58();
}

void func_020e0188(void) {
    func_020dfb58();
}

