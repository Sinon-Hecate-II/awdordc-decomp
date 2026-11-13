/* 1 function from 0x021ED8F0 to 0x021EE8B8 (ov003), found by ds-decomp. */
#include "common.h"
void *func_020abb9c(void*);void *func_020abbb4(void*);void *func_020abbcc(void*);void *func_020abbe4(void*);
void HandleWaypointInput(void*,u8);s32 InRange(s16,s16,s16);void PlaySoundEffect(s32);
s32 func_020aae44(void*);s32 func_020aae10(void*);s16 func_ov003_022004a8(u8);void SetTextById(void*,s32);
typedef struct {u8 low:2,mode:2,state:4;} OptionsFlags;
typedef struct {u8 enabled:1,other:7;} OptionsBits;
void StepCounter(void*,s32,s32);void StepCounterDown(void*,u8,s32);void func_ov003_021e8354(void*,u8,s32);
typedef struct {u8 frame:4,other:4;} OptionsButtonFlags;
typedef struct {u32 low:18,tile:8,high:6;} OptionsGeometry;
typedef struct {u32 width:9,height:9,rest:14;} OptionsSize;
static inline void SetOptionTile(void*s,u16 n){((OptionsGeometry*)((u8*)s+0x40))->tile=n;}
static inline void PressOption(void*s){if(M2C_FIELD(s,s8*,0x5a)>=0){SetOptionTile(s,(u16)(((OptionsButtonFlags*)((u8*)s+0x59))->frame+1));M2C_FIELD(s,s8*,0x5a)=12;}}
static inline s32 OptionsEntriesDiffer(void *p){
s32 count=M2C_FIELD(p,s8*,4)-1;u8 i=0;for(;i<count;i++){u8 *q=(u8*)p+i*24;if(M2C_FIELD(q,s32*,0x18)!=M2C_FIELD(q,s32*,0x30))return 1;}return 0;
}
#pragma opt_propagation off
static inline void ChangeOptionValue(void *menu,u8 index,s32 delta){
s32 offset=index*24;
u8 *value=(u8*)menu+0x18,*maximum=(u8*)menu+0x1c,*minimum=(u8*)menu+0x20,*q;
s32 next=M2C_FIELD(value,s32*,offset)+delta;
InRange((s16)next,(s16)M2C_FIELD(minimum,s32*,offset),(s16)M2C_FIELD(maximum,s32*,offset));
M2C_FIELD(value,s32*,offset)=next;q=(u8*)menu+offset;
if(M2C_FIELD(q,u8*,0x28)){
if(M2C_FIELD(value,s32*,offset)>M2C_FIELD(maximum,s32*,offset))do{M2C_FIELD(q,s32*,0x18)-=M2C_FIELD(q,s32*,0x1c)-M2C_FIELD(q,s32*,0x20)+1;}while(M2C_FIELD(q,s32*,0x18)>M2C_FIELD(q,s32*,0x1c));
if(M2C_FIELD(value,s32*,offset)<M2C_FIELD(minimum,s32*,offset))do{u8 *low=(u8*)menu+offset;M2C_FIELD(low,s32*,0x18)+=M2C_FIELD(low,s32*,0x1c)-M2C_FIELD(low,s32*,0x20)+1;}while(M2C_FIELD((u8*)menu+offset,s32*,0x18)<M2C_FIELD((u8*)menu+offset,s32*,0x20));
}else{
s32 x=M2C_FIELD(value,s32*,offset),hi=M2C_FIELD(maximum,s32*,offset);if(x<=hi){hi=M2C_FIELD(minimum,s32*,offset);if(x>=hi)hi=x;}M2C_FIELD(value,s32*,offset)=hi;
}
}
#pragma opt_propagation reset

static inline void RefreshOptionCursor(void *p){
void *sprite=M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0);
s32 h=func_020aae44(sprite),w=func_020aae10(sprite);
s16 y=M2C_FIELD(sprite,s16*,0x36),x;u8 *cursor;x=M2C_FIELD(sprite,s16*,0x34);cursor=M2C_FIELD(p,u8**,0x58);
M2C_FIELD(cursor,s16*,0x34)=x;M2C_FIELD(cursor,s16*,0x36)=y;
((OptionsSize*)(cursor+0x40))->width=w;((OptionsSize*)(cursor+0x40))->height=h;
M2C_FIELD(M2C_FIELD(p,void**,0x5c),s16*,0x34)=func_ov003_022004a8(M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7));
}
static inline void RefreshOptionText(void *p){
u8 index;
if(((OptionsBits*)((u8*)p+0x3a))->enabled){
index=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e);
if(InRange(index,0,3))SetTextById(M2C_FIELD(p,void**,0x54),0x47000011);
else if(InRange(index,4,7))SetTextById(M2C_FIELD(p,void**,0x54),0x47000012);
else if(InRange(index,8,20))SetTextById(M2C_FIELD(p,void**,0x54),0x47000011);
else if(InRange(index,21,24))SetTextById(M2C_FIELD(p,void**,0x54),0x47000010);
else if(index==25){
u8 zero=((OptionsFlags*)((u8*)p+0x39))->mode==0;
if(zero)SetTextById(M2C_FIELD(p,void**,0x54),0x47000016);
else{u8 one=((OptionsFlags*)((u8*)p+0x39))->mode==1;if(one)SetTextById(M2C_FIELD(p,void**,0x54),0x47000017);}
}}
}
static inline void CopyOptionPosition(u8 *menu,u8 *position){u8 y=menu[8],x=menu[7];position[16]=x;position[17]=y;}
static inline void SaveOptionPosition(void *p){
CopyOptionPosition(M2C_FIELD(p,u8**,0x6c),M2C_FIELD(p,u8**,0x40));M2C_FIELD(p,u8*,0x3a)|=8;
}


#pragma push
#pragma scheduling off
void func_ov003_021ed8f0(void *arg0,u32 arg1,s32 arg2){
u8 *p=arg0,*menu=M2C_FIELD(p,u8**,0x6c);u8 state=((OptionsFlags*)(p+0x39))->state;
u8 zero=state==0,two=state==2;u8 oldX=menu[7],selected;void *next;
if(zero|two){switch(arg1){case 64:
next=func_020abb9c(M2C_FIELD(menu,void**,0xe0));
menu=M2C_FIELD(p,u8**,0x6c);selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0xe0),u16*,0x2e);
HandleWaypointInput(menu,(u8)M2C_FIELD(next,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e)){
PlaySoundEffect(0x10019);RefreshOptionCursor(p);RefreshOptionText(p);SaveOptionPosition(p);
}break;
case 128:
next=func_020abbb4(M2C_FIELD(menu,void**,0xe0));
menu=M2C_FIELD(p,u8**,0x6c);selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0xe0),u16*,0x2e);
HandleWaypointInput(menu,(u8)M2C_FIELD(next,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e)){
PlaySoundEffect(0x10019);RefreshOptionCursor(p);RefreshOptionText(p);SaveOptionPosition(p);
}break;
case 32:
next=func_020abbcc(M2C_FIELD(menu,void**,0xe0));
menu=M2C_FIELD(p,u8**,0x6c);selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0xe0),u16*,0x2e);
HandleWaypointInput(menu,(u8)M2C_FIELD(next,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e)){
PlaySoundEffect(0x10019);RefreshOptionCursor(p);RefreshOptionText(p);SaveOptionPosition(p);
}break;
case 16:
next=func_020abbe4(M2C_FIELD(menu,void**,0xe0));
menu=M2C_FIELD(p,u8**,0x6c);selected=(u8)M2C_FIELD(M2C_FIELD(menu,void**,0xe0),u16*,0x2e);
HandleWaypointInput(menu,(u8)M2C_FIELD(next,u16*,0x2e));
if(selected!=(u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0),u16*,0x2e)){
PlaySoundEffect(0x10019);RefreshOptionCursor(p);RefreshOptionText(p);SaveOptionPosition(p);
}break;
}
PlaySoundEffect(0x10019);return;
}
if((u8)(state==1)&&arg2){
switch(arg1){case 32: (menu+14)[oldX]=(menu+14)[oldX]==1?2:1;PressOption(M2C_FIELD(M2C_FIELD(p,u8**,0x64)+oldX*4,void**,8));PlaySoundEffect(0x10011);break;
case 16:(menu+14)[oldX]=(menu+14)[oldX]==1?2:1;PressOption(M2C_FIELD(M2C_FIELD(p,u8**,0x64)+oldX*4,void**,0x18));PlaySoundEffect(0x10011);break;
}return;
}
if(!((u8)(state==3)&&arg2))return;
switch(arg1){case 64:ChangeOptionValue(menu,oldX,-1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,-1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,-1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,-1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,-1,1);
if(!OptionsEntriesDiffer(menu))StepCounterDown(menu,oldX,1);
}}}}
PressOption(M2C_FIELD(M2C_FIELD(p,u8**,0x64)+oldX*4,void**,40));
PlaySoundEffect(0x10011);break;case 128:ChangeOptionValue(menu,oldX,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,1,1);
if(!OptionsEntriesDiffer(menu)){
StepCounter(menu+0x14+oldX*24,1,1);
if(!OptionsEntriesDiffer(menu))func_ov003_021e8354(menu,oldX,1);
}}}}
PressOption(M2C_FIELD(M2C_FIELD(p,u8**,0x64)+oldX*4,void**,56));
PlaySoundEffect(0x10011);break;}
}
#pragma pop
