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
void UpdateSpriteGrid(void *);
int func_020c5464(int);
void PlaySoundEffect(int);
void Sprite_ResumeAnimation(void *);
void GotoSpriteAnimationLabel(void *,int);
int ScrollSpriteGridUp(void *);
int ScrollSpriteGridDown(void *);
int CanScrollSpriteGridUp(void *);
int CanScrollSpriteGridDown(void *);
/* Frame step of the ov006 battle-save screen: update its reveal animation,
 * the six menu buttons and the battle-slot grid, enable the three action
 * buttons that fit the selected slot's record kind (func_020c5464), then handle
 * the button presses and the B/A and up/down keys, flashing the pressed button
 * and animating the screen on to its next step. */
void UpdateBattleSaveScreen(void *arg0) {
u8 *screen=arg0,*unused;void **buttons;u16 keys;
UpdateSpriteAnimation(M2C_FIELD(screen,void **,0x48));buttons=M2C_FIELD(screen,void ***,0x3c);
MenuSpriteUpdate(buttons[0]);
MenuSpriteUpdate(buttons[1]);
MenuSpriteUpdate(buttons[2]);
MenuSpriteUpdate(buttons[3]);
MenuSpriteUpdate(buttons[4]);
MenuSpriteUpdate(buttons[5]);
UpdateSpriteGrid(M2C_FIELD(screen,void **,0x4c));
/* Enable the action buttons (12/16/20) allowed for the selected slot kind. */
switch(func_020c5464(M2C_FIELD(M2C_FIELD(screen,void **,0x4c),s16 *,8))) {
case 0:
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 1:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 2:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 3:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
}
keys=*gKeyState;
/* Back (button 0) or B leaves the screen. */
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,0));
if(ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,0)) || (keys&2)){PlaySoundEffect(0x1000f);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,0));Sprite_ResumeAnimation(screen);return;}
/* Action button 12 (index 3), with A while the grid is not animating. */
if(!(u8)(M2C_FIELD(M2C_FIELD(screen,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12)) || (keys&1))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));GotoSpriteAnimationLabel(screen,9);return;}
/* Action button 16 (index 4). */
if(!(u8)(M2C_FIELD(M2C_FIELD(screen,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16)) || (keys&1))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));GotoSpriteAnimationLabel(screen,9);return;}
/* Action button 20 (index 5). */
if(!(u8)(M2C_FIELD(M2C_FIELD(screen,u8 **,0x4c),s16 *,18)!=0) && ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20)) && (ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20)) || (keys&1024))){PlaySoundEffect(0x1000d);ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));GotoSpriteAnimationLabel(screen,8);return;}
/* Scroll buttons 4/8 move the battle-slot grid. */
if(ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4)) && ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4))){if(ScrollSpriteGridUp(M2C_FIELD(screen,void **,0x4c)))ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4));}else if(ButtonEnabled12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8)) && ButtonPressed12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8))){if(ScrollSpriteGridDown(M2C_FIELD(screen,void **,0x4c)))ButtonFlash12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8));}
/* Grey the scroll buttons out at the top and bottom of the grid. */
if(CanScrollSpriteGridUp(M2C_FIELD(screen,void **,0x4c)))ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4));else ButtonSet12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4),ButtonBase12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,4))+2,0);
if(CanScrollSpriteGridDown(M2C_FIELD(screen,void **,0x4c)))ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8));else ButtonSet12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8),ButtonBase12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,8))+2,0);
/* Re-apply the enabled state after the input moved the selection. */
switch(func_020c5464(M2C_FIELD(M2C_FIELD(screen,void **,0x4c),s16 *,8))) {
case 0:
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 1:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 2:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
case 3:
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,12));
ButtonDisable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,16));
ButtonEnable12DFC(M2C_FIELD(M2C_FIELD(screen,u8 **,0x3c),u8 **,20));
break;
}
}
