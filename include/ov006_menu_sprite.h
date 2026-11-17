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
#endif
