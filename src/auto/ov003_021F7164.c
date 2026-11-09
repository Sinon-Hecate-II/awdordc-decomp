/* 1 function from 0x021F7164 to 0x021F8C20 (ov003), found by ds-decomp. */
#include "common.h"
extern u8 *data_02101e88;
extern u16 *data_02101e84;
extern void *gCur3DSpriteEngine;
static inline u8 ov003_menu_kind(void *p,u32 kind){
u8 result;if(((u32)(M2C_FIELD(p,u8 *,0x3b)<<28)>>28)==kind)result=1;else result=0;return result;
}
static inline s32 ov003_button_pressed(void *button){
s32 result=1;void *p=M2C_FIELD(button,void **,0x64);
if(M2C_FIELD(p,s8 *,11)!=1){if(!((u32)(M2C_FIELD(button,u8 *,0x59)<<27)>>31)||M2C_FIELD(p,s8 *,12)!=1)result=0;}
return result;
}
static inline void ov003_animate_button(void *button){
if(M2C_FIELD(button,s8 *,0x5a)>=0){
u16 frame=((u32)(M2C_FIELD(button,u8 *,0x59)<<28)>>28)+1;
M2C_FIELD(button,u32 *,0x40)=(M2C_FIELD(button,u32 *,0x40)&~0x3fc0000)|((u32)(frame<<24)>>6);
M2C_FIELD(button,u8 *,0x5a)=12;
}
}


static inline void ov003_menu_set_mode(u8 *p,s32 mode,s32 sound){
void func_0208fe30(s32);void func_020808dc(void *,s32,s32,s32);void func_ov003_021fc98c(void *,s32);
void func_0208b758(void *,s32);void func_02088f1c(void *);void func_02088ff4(void *);s32 func_020ae22c(s32);void func_020893a8(void *,s32,s32,s32);
func_0208fe30(sound);p[0x3e]=(p[0x3e]&~7)|mode;
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void **,36),32,3,7);
if((u32)(p[0x3e]<<24)>>31)func_ov003_021fc98c(p,mode?5:4);
if(mode)func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void **,36)+32,16,3,6);
else func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void **,36),16,3,6);
func_0208b758(M2C_FIELD(M2C_FIELD(p,void **,0x6c),void **,4),mode?0x4700001f:0x4700001d);
if(mode){
func_02088ff4(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,4));
func_02088f1c(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,8));
M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,8),u8 *,0x4d)=8;
}else{
func_02088f1c(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,4));
M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,4),u8 *,0x4d)=8;
func_02088ff4(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,8));
}
func_020893a8(M2C_FIELD(M2C_FIELD(p,void **,0x6c),void **,0),0x8b80,1,func_020ae22c(mode?18:17));
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
}
static inline void ov003_menu_back(void *p){
s32 func_02084644(void);s32 func_020846a4(void);void func_ov003_021fc98c(void *,s32);
s32 special;
if(ov003_menu_kind(p,6)||ov003_menu_kind(p,7)||ov003_menu_kind(p,8))special=1;
else if(ov003_menu_kind(p,4)){if(func_02084644()==2)special=1;else special=0;}else special=0;
if(special&&func_020846a4())func_ov003_021fc98c(p,3);
else M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x20)(p);
}
static inline u8 ov003_button_ready(void *button){
u8 result;result=((u32)(M2C_FIELD(button,u8 *,0x59)<<28)>>28)+2!=(u16)((u32)(M2C_FIELD(button,u32 *,0x40)<<6)>>24);return result;
}
static inline u8 ov003_menu_positioned(void *p){
void *sprite=M2C_FIELD(M2C_FIELD(p,void **,0x6c),void **,0);u8 result;
if(M2C_FIELD(sprite,s16 *,0x34)==M2C_FIELD(sprite,s16 *,0x5e)&&M2C_FIELD(sprite,s16 *,0x36)==M2C_FIELD(sprite,s16 *,0x60))result=1;else result=0;return result;
}

extern void func_ov003_021fca84(void *);
#pragma opt_propagation off
void func_ov003_021f7164(void *arg0) {
void func_020aacf0(void *);void func_02088044(void *);s32 func_0207c8ec(s32,s32);
void func_020ab4c0(void *);void func_020ab598(void *);void func_0208fe30(s32);void func_ov003_021f92f4(void *,s32);
s32 func_020ab30c(void *);u8 func_ov003_021f3f0c(s16,s16,s16);
void func_ov003_021fcb70(void *);void func_ov003_021f2808(void *,u16);void func_ov003_021f26c8(void *,void *,u16);
void func_020808dc(void *,s32,s32,s32);void func_ov003_021fc98c(void *,s32);
void func_0208b758(void *,s32);
void func_02088ff4(void *);void func_02088f1c(void *);s32 func_020ae22c(s32);void func_020893a8(void *,s32,s32,s32);
void func_020c9190(u16,void *);void func_020c9288(u16,s32,void *);void func_ov003_021fbd48(void *,s32);void func_ov003_021fbcf8(void *,s32,u8);s32 func_020a8ff4(void *);void func_020ab3b0(void *,s16,s32);s32 func_ov003_021f4038(void);void func_ov003_021f91a4(void *);
u8 *p=arg0;void **buttons;void *list,*button,*context;u16 held,down,selection;register u32 repeat;s32 active;u8 enable; s32 keyx,keyy,i,inputFlag;u32 mode; 
if(ov003_menu_kind(p,1))return;
if(ov003_menu_kind(p,5))return;
func_ov003_021fca84(p);
if((u32)(p[0x3e]<<25)>>31)return;
mode=(u32)(p[0x3b]<<28)>>28;
inputFlag=data_02101e88[0x12];held=data_02101e84[0];down=data_02101e84[1];repeat=data_02101e84[3];
if(ov003_menu_kind(p,0)||ov003_menu_kind(p,2)||ov003_menu_kind(p,3)||ov003_menu_kind(p,4)||ov003_menu_kind(p,6)||ov003_menu_kind(p,7)||ov003_menu_kind(p,8)){
context=M2C_FIELD(p,void **,0x44);list=M2C_FIELD(p,void **,0x4c);
selection=M2C_FIELD(context+((M2C_FIELD(M2C_FIELD(p,void **,0x5c),u32 *,4)&255)*512)+(u16)(s16)M2C_FIELD(list,s32 *,0x14)*2,u16 *,0x2e);
}else selection=M2C_FIELD(p,u16 *,0x3c);
buttons=M2C_FIELD(p,void ***,0x68);
active=1;
if(!((u32)(p[0x3a]<<24)>>31)){down=0;held=down;}
func_020aacf0(buttons[0]);func_020aacf0(buttons[1]);func_020aacf0(buttons[2]);func_020aacf0(buttons[3]);func_020aacf0(buttons[4]);func_020aacf0(buttons[5]);func_020aacf0(buttons[6]);func_020aacf0(buttons[7]);func_020aacf0(buttons[8]);func_020aacf0(buttons[9]);
func_02088044(M2C_FIELD(p,void **,0x70));
button=M2C_FIELD(p,void **,0x70);keyy=M2C_FIELD(button,u8 *,12);keyx=M2C_FIELD(button,u8 *,11);
list=M2C_FIELD(p,void **,0x4c);
enable=0;
if((s16)func_0207c8ec(M2C_FIELD(list,s16 *,12),M2C_FIELD(list,s16 *,8))>0)
if(M2C_FIELD(list,s16 *,6)<=(s16)func_0207c8ec((s16)M2C_FIELD(list,s32 *,24),M2C_FIELD(list,s16 *,8)))enable=active;
if(enable){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,24);
if((u8)ov003_button_pressed(button)){
ov003_animate_button(button);func_020ab4c0(M2C_FIELD(p,void **,0x4c));func_0208fe30(0x10019);
func_ov003_021f92f4(p,0);active=0;
}
}
if(active){
s16 rows,oldRows;list=M2C_FIELD(p,void **,0x4c);
rows=M2C_FIELD(list,s16 *,6);oldRows=(s16)func_0207c8ec(M2C_FIELD(list,s16 *,12),M2C_FIELD(list,s16 *,8));
enable=rows+oldRows<(s16)func_0207c8ec((s16)M2C_FIELD(list,s32 *,24),M2C_FIELD(list,s16 *,8))+1;
if(enable){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,28);
if((u8)ov003_button_pressed(button)){
ov003_animate_button(button);func_020ab598(M2C_FIELD(p,void **,0x4c));func_0208fe30(0x10019);func_ov003_021f92f4(p,0);active=0;
}
}
}
if(active){
buttons=M2C_FIELD(p,void ***,0x68);
button=buttons[0];
if((u8)ov003_button_pressed(button)||(u8)ov003_button_pressed(button=buttons[2])||(u8)ov003_button_pressed(button=buttons[1])||func_ov003_021f3f0c((s16)keyx,10,(s16)(func_020ab30c(M2C_FIELD(p,void **,0x4c))+10))){
if(ov003_menu_kind(p,6)||ov003_menu_kind(p,7)||ov003_menu_kind(p,8))func_ov003_021fcb70(p);
else if(ov003_menu_kind(p,4)){
mode=(u32)(p[0x3e]<<29)>>29;
if((u8)(mode==0)){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,4);ov003_animate_button(button);
func_ov003_021f2808(M2C_FIELD(p,void **,0x44)+4,selection);
}else if((u8)(mode==1)){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,8);ov003_animate_button(button);
context=M2C_FIELD(p,void **,0x44);func_ov003_021f26c8(context+4,context+0x12,selection);
}
list=M2C_FIELD(p,void **,0x4c);context=M2C_FIELD(p,void **,0x44);
i=(u8)(u16)(s16)M2C_FIELD(list,s32 *,0x14);
M2C_FIELD(context+0x186c,u8 *,i>>3)&=~(1<<(i&7));
}else M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x1c)(p);
active=0;
}
}
if(active&&ov003_menu_kind(p,4)){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,36);
if((u8)ov003_button_pressed(button)){
ov003_animate_button(button);
mode=(u32)(p[0x3e]<<29)>>29;
if((u8)(mode==0))ov003_menu_set_mode(p,1,0x1000d);
else if((u8)(mode==1))M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x1c)(p);
active=0;
}
}
if(active){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,12);
if((u8)ov003_button_pressed(button)){
if(ov003_menu_kind(p,4)){
if((u8)(((u32)(p[0x3e]<<29)>>29)==1))ov003_menu_set_mode(p,0,0x1000f);
else M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x20)(p);
}else ov003_menu_back(p);
active=0;
}else if(active){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,32);
if((u8)ov003_button_pressed(button)&&ov003_menu_kind(p,2)&&ov003_button_ready(button)&&ov003_menu_positioned(p)){
func_ov003_021fc98c(p,0);func_020c9190(selection,p);func_0208fe30(0x1000d);active=0;
}
}
}
if(active&&(ov003_menu_kind(p,0)||ov003_menu_kind(p,3))){
buttons=M2C_FIELD(p,void ***,0x68);
if((u8)ov003_button_pressed(buttons[4])){
if(ov003_menu_kind(p,4)){if((u8)(((u32)(p[0x3e]<<29)>>29)==1))ov003_menu_set_mode(p,0,0x10020);}
else func_ov003_021fbd48(p,-1);
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,16));active=0;
}else if((u8)ov003_button_pressed(buttons[5])){
if(ov003_menu_kind(p,4)){if((u8)(((u32)(p[0x3e]<<29)>>29)==0))ov003_menu_set_mode(p,1,0x10020);}
else func_ov003_021fbd48(p,1);
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,20));active=0;
}
}
list=M2C_FIELD(p,void **,0x4c);enable=1;
if((u8)(M2C_FIELD(list,s16 *,0x2a)>func_020a8ff4(list+0x30))){}
else if(!(u8)(M2C_FIELD(list,s16 *,0x2a)<func_020a8ff4(list+0x30)))enable=0;
if(!enable){
if(func_ov003_021f3f0c((s16)keyy,10,(s16)(func_020ab30c(M2C_FIELD(p,void **,0x4c))+10))&&keyy!=((u32)(p[0x39]<<25)>>25)){
list=M2C_FIELD(p,void **,0x4c);
keyx=(s16)(keyy-10+M2C_FIELD(list,s16 *,12));
if(M2C_FIELD(list,s32 *,24)!=keyx)func_020ab3b0(list,(s16)keyx,1);
func_ov003_021f92f4(p,0);func_0208fe30(0x10019);active=0;
}
}
p[0x39]=(p[0x39]&~127)|(keyy&127);
if(inputFlag==0){
if(active&&(held&9)){
if(ov003_menu_kind(p,6)||ov003_menu_kind(p,7)||ov003_menu_kind(p,8))func_ov003_021fcb70(p);
else if(ov003_menu_kind(p,4)){
if(held&1){
mode=(u32)(p[0x3e]<<29)>>29;
if((u8)(mode==0)){
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,4));
func_ov003_021f2808(M2C_FIELD(p,void **,0x44)+4,selection);
}else if((u8)(mode==1)){
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,8));
context=M2C_FIELD(p,void **,0x44);func_ov003_021f26c8(context+4,context+18,selection);
}
list=M2C_FIELD(p,void **,0x4c);context=M2C_FIELD(p,void **,0x44);
keyx=(u8)(u16)(s16)M2C_FIELD(list,s32 *,20);M2C_FIELD(context+0x186c,u8 *,keyx>>3)&=~(1<<(keyx&7));
}
if(held&8){
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,36));
if((u32)(p[0x3e]<<24)>>31){
mode=(u32)(p[0x3e]<<29)>>29;
if((u8)(mode==0))ov003_menu_set_mode(p,1,0x1000d);
else if((u8)(mode==1))M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x1c)(p);
}else M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x1c)(p);
}
}else M2C_FIELD(M2C_FIELD(p,void ***,0),void (**)(void *),0x1c)(p);
active=0;
}
if(active&&(held&2)){
if(((u32)(p[0x3e]<<24)>>31)&&ov003_menu_kind(p,4)&&(u8)(((u32)(p[0x3e]<<29)>>29)==1))ov003_menu_set_mode(p,0,0x1000f);
else ov003_menu_back(p);
active=0;
}
if(active&&(held&4)&&ov003_menu_kind(p,2)){
button=M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,32);
if(ov003_button_ready(button)&&ov003_menu_positioned(p)&&!(held&0xf0)){
ov003_animate_button(button);func_ov003_021fc98c(p,0);func_020c9190(selection,p);func_0208fe30(0x1000d);active=0;
}
}
if(active){
if(down&64){func_ov003_021fbcf8(p,-2,held&64);active=0;}
else if(down&128){func_ov003_021fbcf8(p,2,(u8)(held&128));active=0;}
if(down&32){func_ov003_021fbcf8(p,-1,held&32);active=0;}
else if(down&16){func_ov003_021fbcf8(p,1,held&16);active=0;}
}
if(active&&(ov003_menu_kind(p,0)||ov003_menu_kind(p,3))){
if(down&512){
if(ov003_menu_kind(p,4)){if((u8)(((u32)(p[0x3e]<<29)>>29)==1))ov003_menu_set_mode(p,0,0x10020);}
else func_ov003_021fbd48(p,-1);
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,16));
}else if(down&256){
if(ov003_menu_kind(p,4)){if((u8)(((u32)(p[0x3e]<<29)>>29)==0))ov003_menu_set_mode(p,1,0x10020);}
else func_ov003_021fbd48(p,1);
ov003_animate_button(M2C_FIELD(M2C_FIELD(p,void **,0x68),void **,20));
}
}
}
if(ov003_menu_kind(p,2)&&(repeat&512)&&(repeat&256)&&(held&1024))func_020c9288(selection,1760,p);
if(ov003_menu_kind(p,4))return;
if(ov003_menu_kind(p,6))return;
if(ov003_menu_kind(p,7))return;
if(ov003_menu_kind(p,8))return;
if(func_ov003_021f4038())func_ov003_021f91a4(p);
}
#pragma opt_propagation on
