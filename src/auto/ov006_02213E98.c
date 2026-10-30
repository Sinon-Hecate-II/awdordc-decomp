/* 2 functions from 0x02213E98 to 0x022144AC (ov006), found by ds-decomp. */
#include "common.h"
typedef struct {
 u8 pad[0x40];
 u32 low:18;u32 frame:8;u32 high:6;
 u8 pad44[0x15];
 u8 base:4;u8 upper:4;
 u8 timer;
} MenuSprite_02213e98;
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

void func_02088ff4(void *);
u32 func_020c5464(s16);
/* Updates menu state and sprite frames based on selection */
void func_ov006_02213e98(void *arg0) {
 void *p = M2C_FIELD(arg0, void **, 0x48);
 MenuSprite_02213e98 **sprites;
 M2C_FIELD(p, s16 *, 14) = 0;
 M2C_FIELD(p, s16 *, 16) = -255;
 M2C_FIELD(p, s16 *, 12) = 12;
 M2C_FIELD(p, u16 *, 2) = M2C_FIELD(p, u16 *, 4);
 sprites = M2C_FIELD(arg0, void **, 0x3c);
 func_02088ff4(sprites[0]);
 SetMenuFrame_02213e98(sprites[1], (u16)(sprites[1]->base + 2));
 SetMenuFrame_02213e98(sprites[2], (u16)(sprites[2]->base + 2));
 func_02088ff4(sprites[3]);
 func_02088ff4(sprites[4]);
 func_02088ff4(sprites[5]);
 switch (func_020c5464(M2C_FIELD(M2C_FIELD(arg0, void **, 0x4c), s16 *, 8))) {
 case 0:
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[3];
  u32 frame = s->base;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (!disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[4];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[5];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 break;
 case 1:
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[3];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[4];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[5];
  u32 frame = s->base;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (!disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 break;
 case 2:
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[3];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[4];
  u32 frame = s->base;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (!disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[5];
  u32 frame = s->base;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (!disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 break;
 case 3:
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[3];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[4];
  u32 frame = s->base + 2;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 {
  MenuSprite_02213e98 *s = ((MenuSprite_02213e98 **)M2C_FIELD(arg0, void **, 0x3c))[5];
  u32 frame = s->base;
  u8 disabled = (s->base + 2 != (u16)s->frame);
  if (!disabled) {
   s->frame = (u16)frame;
   s->timer = 0;
  }
 }
 break;
 }
}

void func_ov006_0221440c(void *a){u64 func_020c5430(void);extern M2C_UNK data_ov006_02218e00;u64 v;void *p;func_020c52ec(M2C_FIELD(M2C_FIELD(a,void**,0x4c),s16*,8));v=func_020c5430();if(v)func_020c5498(&data_ov006_02218e00,(u32)v,(u32)(v>>32));else func_02007f8c(&data_ov006_02218e00,0,13);func_01ffa920(a,0);p=M2C_FIELD(a,void**,0x3c);func_02088da8(M2C_FIELD(p,s32*,0));func_02088da8(M2C_FIELD(p,s32*,4));func_02088da8(M2C_FIELD(p,s32*,8));func_02088da8(M2C_FIELD(p,s32*,12));func_02088da8(M2C_FIELD(p,s32*,16));func_02088da8(M2C_FIELD(p,s32*,20));func_ov006_02216c24(&data_ov006_02218e00,a);}
