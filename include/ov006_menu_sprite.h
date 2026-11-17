#ifndef OV006_MENU_SPRITE_H
#define OV006_MENU_SPRITE_H
#include "common.h"
typedef struct {
 u8 pad[0x40];
 u32 low:18;u32 frame:8;u32 high:6;
 u8 pad44[0x15];
 u8 base:4;u8 upper:4;
 u8 timer;
} MenuSprite_02213e98;

#ifndef OV006_MENU_FRAME_HELPERS_LOCAL
static inline void SetMenuFrame_02213e98(MenuSprite_02213e98 *s,u16 frame) {
 s->frame=(u16)frame;s->timer=0;
}
static inline u16 MenuBase_02213e98(MenuSprite_02213e98 *s){return s->base;}
static inline u16 MenuFrame_02213e98(MenuSprite_02213e98 *s){return s->frame;}
static inline u8 IsMenuDisabled_02213e98(MenuSprite_02213e98 *s) {
 return MenuBase_02213e98(s)+2!=MenuFrame_02213e98(s);
}
static inline void EnableMenuSprite_02213e98(MenuSprite_02213e98 *s) {
 u16 frame=MenuBase_02213e98(s);if(!IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);
}
static inline void DisableMenuSprite_02213e98(MenuSprite_02213e98 *s) {
 u16 frame=s->base+2;
 if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);
}
#endif
#endif
