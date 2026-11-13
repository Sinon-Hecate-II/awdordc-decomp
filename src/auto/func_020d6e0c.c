#include "common.h"
extern u8 gSpriteDesc64x32[],gSpriteDesc16x32[],gSpriteDesc8x32[],data_02101f1c[],gSpriteDesc16x16[],gSpriteDesc8x16[],data_02101f0c[],gSpriteDesc16x8[],gSpriteDesc8x8[];

void DrawUnitInfoFrame(s32 arg0, u8 arg1, s32 arg3) {
    // Simplified version without complex bit shifts
    if (arg3 == 0) {
        AddSprite(arg0 & 0x1FF, arg1 + 0x18, 0x400, &data_02101f1c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x18, 0x400, &gSpriteDesc16x16, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x18, 0x400, &gSpriteDesc8x16, 0xA);
        AddSprite(arg1 + 0x28, 0x400, &data_02101f0c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x28, 0x400, &gSpriteDesc16x8, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x28, 0x400, &gSpriteDesc8x8, 0xA);
    } else {
        AddSprite(arg0 & 0x1FF, arg1 + 0x400, &gSpriteDesc64x32, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x400, &gSpriteDesc16x32, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x400, &gSpriteDesc8x32, 0xA);
        AddSprite(arg1 + 0x20, 0x400, &data_02101f1c, 0xA);
        AddSprite((arg0 + 0x40) & 0x1FF, arg1 + 0x20, &gSpriteDesc16x16, 0xA);
        AddSprite((arg0 + 0x50) & 0x1FF, arg1 + 0x20, &gSpriteDesc8x16, 0xA);
    }
}
