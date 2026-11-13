/* 1 function from 0x021E2628 to 0x021E3500 (ov003), found by ds-decomp. */
#include "common.h"
extern u8 *gTouchState;extern u16 *gKeyState;
s32 func_020d4810(void);void func_02088da8(void*);void SetOv003SceneState(s32);void func_01ffa6fc(void*);void func_ov003_021f1bd4(void);
void MenuSpriteUpdate(void*);u32 func_ov003_021f2574(void);void PlaySoundEffect(s32);
void *func_0208b564(void*);s32 func_ov003_021f1894(void);void func_020899cc(void*,s32,s32,s32);void func_0208ae88(void*,s32);
void func_ov003_021e161c(void*);void func_ov003_021e1530(void*,u8);void func_ov003_021e3714(void*);
void *func_020abb9c(void*);void *func_020abbb4(void*);void *func_020abbcc(void*);void *func_020abbe4(void*);
s32 func_020aae44(void*);s32 func_020aae10(void*);void func_0208b758(void*,s32);
typedef struct {u8 low:2,toggle:2,mode:2,pending:1,high:1;} HandlerFlags;
typedef struct {u8 frame:4,enabled:1,high:3;} ButtonFlags;
typedef struct {u32 width:9,height:9,tile:8,high:6;} HandlerGeometry;
typedef void (*MenuCallback)(void*);
static inline void VCall(void *p,s32 slot){((MenuCallback*)*(void**)p)[slot/4](p);}
static inline u8 Clicked(void *s){u8 yes=1;u8 *q=M2C_FIELD(s,u8**,0x64);if(M2C_FIELD(q,s8*,11)!=1){if(!((ButtonFlags*)((u8*)s+0x59))->enabled||M2C_FIELD(q,s8*,12)!=1)yes=0;}return yes;}
static inline void SetButtonTile(void*s,u16 tile){((HandlerGeometry*)((u8*)s+0x40))->tile=tile;}
static inline void PressButton(void *s){if(M2C_FIELD(s,s8*,0x5a)>=0){SetButtonTile(s,(u16)(((ButtonFlags*)((u8*)s+0x59))->frame+1));M2C_FIELD(s,s8*,0x5a)=12;}}
static inline u32 Available(void *p){u32 n=func_ov003_021f2574();u8 count=0,i=0;u8 *base=M2C_FIELD(p,u8**,0x6c);for(;i<5;i++)if(base[i*0x6f8+0x27])count++;return n<count?n:count;}
static inline void ShowAction(void *p,u8 mode){
void *dialog;
((HandlerFlags*)((u8*)p+0x60))->pending=1;((HandlerFlags*)((u8*)p+0x60))->mode=mode;
switch(((HandlerFlags*)((u8*)p+0x60))->mode){
case 0:dialog=func_0208b564(p);func_020899cc(dialog,3,func_ov003_021f1894()<<5,0x47000023);M2C_FIELD(dialog,u32*,0x58)|=0x400;func_0208ae88(dialog,0);break;
case 1:dialog=func_0208b564(p);func_020899cc(dialog,3,func_ov003_021f1894()<<5,0x47000024);M2C_FIELD(dialog,u32*,0x58)|=0x400;func_0208ae88(dialog,1);break;
}}
static inline void UpdateSelection(void *p){
void *sprite=M2C_FIELD(M2C_FIELD(p,u8**,0x48),void**,0x38);s32 h=func_020aae44(sprite)-4,w=func_020aae10(sprite);s16 x=M2C_FIELD(sprite,s16*,0x34),y=M2C_FIELD(sprite,s16*,0x36);u8 *cursor=M2C_FIELD(p,u8**,0x4c);
M2C_FIELD(cursor,s16*,0x34)=x+2;M2C_FIELD(cursor,s16*,0x36)=y+2;
M2C_FIELD(cursor,u32*,0x40)=(((M2C_FIELD(cursor,u32*,0x40)&~511)|((w-4)&511))&0xfffc01ff)|((u32)(h<<23)>>14);
switch((u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,u8**,0x48),u8**,0x38),u16*,0x2e)){
case 0:case 1:case 2:case 3:case 4:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000019);break;
case 5:case 6:case 7:case 8:case 9:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700001a);break;
case 10:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700001b);break;
}}


#pragma optimization_level 3
void func_ov003_021e2628(void *arg0) {
u8 *p=arg0;u16 keys,repeat;u8 allowed,busy,clicked;void *menu,*sprite;u8 selected;
if(((HandlerFlags*)(p+0x60))->pending){
((HandlerFlags*)(p+0x60))->pending=0;
switch(((HandlerFlags*)(p+0x60))->mode){
case 0:if(func_020d4810())VCall(p,0x1c);break;
case 1:if(func_020d4810())VCall(p,0x20);break;
case 2:if(p[0x39])func_02088da8(M2C_FIELD(p,void**,0x4c));SetOv003SceneState(2);p[0x38]=0;func_01ffa6fc(p);break;
}
}
func_ov003_021f1bd4();if(((HandlerFlags*)(p+0x60))->pending)return;
busy=gTouchState[0x12];keys=gKeyState[0];repeat=gKeyState[1];
menu=M2C_FIELD(p,void**,0x44);allowed=1;MenuSpriteUpdate(M2C_FIELD(menu,void**,0));MenuSpriteUpdate(M2C_FIELD(menu,void**,4));
sprite=M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0);
clicked=Clicked(sprite);if(clicked){PressButton(sprite);if(Available(p)){PlaySoundEffect(0x1000d);ShowAction(p,0);}else VCall(p,0x1c);allowed=0;}
if(allowed&&Clicked(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,4))){sprite=M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,4);PlaySoundEffect(0x1000f);PressButton(sprite);if(Available(p))ShowAction(p,1);else VCall(p,0x20);allowed=0;}
func_ov003_021e161c(M2C_FIELD(p,void**,0x48));menu=M2C_FIELD(p,void**,0x48);
if((u8)(M2C_FIELD(menu,s8*,5)!=-1)){
selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0x38),u16*,0x2e);func_ov003_021e1530(menu,(u8)M2C_FIELD(menu,s8*,5));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38),u16*,0x2e)){PlaySoundEffect(0x10019);func_ov003_021e3714(p);UpdateSelection(p);}
}
if(busy)return;
if(allowed&&(keys&1)){PressButton(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0));if(Available(p)){PlaySoundEffect(0x1000d);ShowAction(p,0);}else VCall(p,0x1c);allowed=0;}
if(allowed&&(keys&8)){PressButton(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0));if(Available(p)){PlaySoundEffect(0x1000d);ShowAction(p,0);}else VCall(p,0x1c);allowed=0;}
if(allowed&&(keys&2)){PlaySoundEffect(0x1000f);PressButton(M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,4));if(Available(p))ShowAction(p,1);else VCall(p,0x20);}
if(repeat&64) {
sprite=func_020abb9c(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38));menu=M2C_FIELD(p,void**,0x48);
selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0x38),u16*,0x2e);
func_ov003_021e1530(menu,(u8)M2C_FIELD(sprite,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38),u16*,0x2e)){
PlaySoundEffect(0x10019);func_ov003_021e3714(p);UpdateSelection(p);}
}
else if(repeat&128) {
sprite=func_020abbb4(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38));menu=M2C_FIELD(p,void**,0x48);
selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0x38),u16*,0x2e);
func_ov003_021e1530(menu,(u8)M2C_FIELD(sprite,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38),u16*,0x2e)){
PlaySoundEffect(0x10019);func_ov003_021e3714(p);UpdateSelection(p);}
}
if(repeat&32) {
sprite=func_020abbcc(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38));menu=M2C_FIELD(p,void**,0x48);
selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0x38),u16*,0x2e);
func_ov003_021e1530(menu,(u8)M2C_FIELD(sprite,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38),u16*,0x2e)){
PlaySoundEffect(0x10019);func_ov003_021e3714(p);UpdateSelection(p);}
}
else if(repeat&16) {
sprite=func_020abbe4(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38));menu=M2C_FIELD(p,void**,0x48);
selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0x38),u16*,0x2e);
func_ov003_021e1530(menu,(u8)M2C_FIELD(sprite,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x48),void**,0x38),u16*,0x2e)){
PlaySoundEffect(0x10019);func_ov003_021e3714(p);UpdateSelection(p);}
}
}
#pragma optimization_level reset
