#include "common.h"
extern u8 data_027e00b4[],data_027e0074[],data_027e009c[],data_02101f1c[],gSpriteDesc16x16[],data_027e006c[],data_02101f0c[],gSpriteDesc16x8[],gSpriteDesc8x8[];

void func_020d6e0c(s32 arg0, u8 arg1, s32 arg3) {
    // Simplified version without complex bit shifts
    if (arg3 == 0) {
        AddSprite(arg0 & 0x1FF, arg1 + 0x18, 0x400, &data_02101f1c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x18, 0x400, &gSpriteDesc16x16, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x18, 0x400, &data_027e006c, 0xA);
        AddSprite(arg1 + 0x28, 0x400, &data_02101f0c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x28, 0x400, &gSpriteDesc16x8, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x28, 0x400, &gSpriteDesc8x8, 0xA);
    } else {
        AddSprite(arg0 & 0x1FF, arg1 + 0x400, &data_027e00b4, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x400, &data_027e0074, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x400, &data_027e009c, 0xA);
        AddSprite(arg1 + 0x20, 0x400, &data_02101f1c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x20, &gSpriteDesc16x16, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x20, &data_027e006c, 0xA);
    }
}
