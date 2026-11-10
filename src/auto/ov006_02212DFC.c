/* 1 function from 0x02212DFC to 0x02213E98 (ov006), found by ds-decomp. */
#include "common.h"
extern u16 *gKeyState;
static inline u32 ButtonBase12DFC(u8 *w) { return (u32)(w[0x59]<<28)>>28; }
static inline u16 ButtonFrame12DFC(u8 *w) { return (u32)(M2C_FIELD(w,u32 *,0x40)<<6)>>24; }
static inline u8 ButtonEnabled12DFC(u8 *w) { return ButtonBase12DFC(w)+2 != ButtonFrame12DFC(w); }
static inline void ButtonSet12DFC(u8 *w,u16 v,s8 timer) { M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,volatile u32 *,0x40)&~0x3fc0000)|((u32)(v<<24)>>6);w[0x5a]=timer; }
static inline void ButtonEnable12DFC(u8 *w) { if(!ButtonEnabled12DFC(w)) ButtonSet12DFC(w,ButtonBase12DFC(w),0); }
static inline void ButtonDisable12DFC(u8 *w) { if(ButtonEnabled12DFC(w)) ButtonSet12DFC(w,ButtonBase12DFC(w)+2,0); }
static inline u8 ButtonPressed12DFC(u8 *w) { u8 *r=M2C_FIELD(w,u8 **,0x64); int yes=1;if(M2C_FIELD(r,s8 *,11)!=1 && (!((u32)(M2C_FIELD(w,volatile u8 *,0x59)<<27)>>31) || M2C_FIELD(r,s8 *,12)!=1))yes=0;return yes; }
static inline void ButtonFlash12DFC(u8 *w) {if(M2C_FIELD(w,s8 *,0x5a)>=0)ButtonSet12DFC(w,ButtonBase12DFC(w)+1,12);}


void UpdateSpriteAnimation(void *);
void MenuSpriteUpdate(void *);
void func_020b3a58(void *);
int func_020c5464(int);
void PlaySoundEffect(int);
void func_01ffa6fc(void *);
void SetSpriteAnimation(void *,int);
int func_020b3368(void *);
int func_020b3290(void *);
int func_020b325c(void *);
int func_020b320c(void *);
void func_ov006_02212dfc(void *arg0) {
u8 *p=arg0,*w;void **list;u16 keys;
UpdateSpriteAnimation(M2C_FIELD(p,void **,0x48));list=M2C_FIELD(p,void ***,0x3c);
MenuSpriteUpdate(list[0]);
MenuSpriteUpdate(list[1]);
MenuSpriteUpdate(list[2]);
MenuSpriteUpdate(list[3]);
MenuSpriteUpdate(list[4]);
MenuSpriteUpdate(list[5]);
func_020b3a58(M2C_FIELD(p,void **,0x4c));
switch(func_020c5464(M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,8))) {
case 0:
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 1:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 2:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 3:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
}
keys=*gKeyState;
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,0));
if(ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,0)) || (keys&2)){PlaySoundEffect(0x1000f);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,0));func_01ffa6fc(p);return;}
if(!(u8)(M2C_FIELD(M2C_FIELD(p,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12)) || (keys&1))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));SetSpriteAnimation(p,9);return;}
if(!(u8)(M2C_FIELD(M2C_FIELD(p,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16)) || (keys&1))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));SetSpriteAnimation(p,9);return;}
if(!(u8)(M2C_FIELD(M2C_FIELD(p,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20)) || (keys&1024))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));SetSpriteAnimation(p,8);return;}
if(ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4)) && ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4))){if(func_020b3368(M2C_FIELD(p,void **,0x4c)))ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4));}else if(ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8)) && ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8))){if(func_020b3290(M2C_FIELD(p,void **,0x4c)))ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8));}
if(func_020b325c(M2C_FIELD(p,void **,0x4c)))ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4));else ButtonSet12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4),ButtonBase12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,4))+2,0);
if(func_020b320c(M2C_FIELD(p,void **,0x4c)))ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8));else ButtonSet12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8),ButtonBase12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,8))+2,0);
switch(func_020c5464(M2C_FIELD(M2C_FIELD(p,void **,0x4c),s16 *,8))) {
case 0:
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 1:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 2:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
case 3:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(p,u8 **,0x3c),u8 **,20));
break;
}
}
