/* 13 functions from 0x0207F460 to 0x02080414 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
static inline void Window7fafc(s32 *dst,s32 start,s32 end) { *dst=(start&511)|((end&511)<<16); }

/* The current tile offset of one animated terrain kind, in pixels. */
typedef struct {
    s16 x;
    s16 y;
} TerrainAnimOffset;

/* One frame of a terrain kind's animation: how many frames it lasts and the tile
 * offset it shows.  Lists of these end with a zero duration. */
typedef struct {
    u8 duration;
    s8 x;
    s8 y;
} TerrainAnimFrame;

#define TERRAIN_ANIM_KIND_COUNT 6 /* animated kinds in gTerrainAnimFrames */



s32 TerrainByteToTileId(s32 id) {
    switch (id) {                                 /* irregular */
    case 0x1:
        return 1;
    case 0x8:
        return 3;
    case 0x2:
        return 6;
    case 0x5:
        return 2;
    case 0xB:
        return 7;
    case 0xA:
        return 0x27;
    case 0x4:
        return 0x20;
    case 0x3:
        return 0x21;
    case 0x9:
        return 0x22;
    case 0x7:
        return 0x23;
    case 0xD:
        return 0x24;
    case 0xE:
        return 0x25;
    case 0xC:
        return 0x168;
    case 0x1B:
        return 0x142;
    case 0x1C:
        return 0x162;
    case 0x3B:
        return 0x146;
    case 0x3C:
        return 0x166;
    case 0x6:
        return 0x181;
    case 0x1A:
        return 0x1A1;
    case 0x18:
        return 0x180;
    case 0xF:
        return 0x1C0;
    case 0x2F:
        return 0x1C5;
    case 0x4F:
        return 0x1CA;
    case 0x6F:
        return 0x1CF;
    case 0x8F:
        return 0x1D4;
    case 0x11:
        return 0x1C1;
    case 0x31:
        return 0x1C6;
    case 0x51:
        return 0x1CB;
    case 0x71:
        return 0x1D0;
    case 0x91:
        return 0x1D5;
    case 0x10:
        return 0x1C2;
    case 0x30:
        return 0x1C7;
    case 0x50:
        return 0x1CC;
    case 0x70:
        return 0x1D1;
    case 0x90:
        return 0x1D6;
    case 0x12:
        return 0x1C3;
    case 0x32:
        return 0x1C8;
    case 0x52:
        return 0x1CD;
    case 0x72:
        return 0x1D2;
    case 0x92:
        return 0x1D7;
    case 0x13:
        return 0x1C4;
    case 0x33:
        return 0x1C9;
    case 0x53:
        return 0x1CE;
    case 0x73:
        return 0x1D3;
    case 0x93:
        return 0x1D8;
    case 0x16:
        return 0x1B9;
    case 0x36:
        return 0x1BA;
    case 0x56:
        return 0x1BB;
    case 0x76:
        return 0x1BC;
    case 0x96:
        return 0x1BD;
    case 0x17:
        return 0x1D9;
    case 0x37:
        return 0x1DA;
    case 0x57:
        return 0x1DB;
    case 0x77:
        return 0x1DC;
    case 0x97:
        return 0x1DD;
    case 0x14:
        return 0x179;
    case 0x34:
        return 0x17A;
    case 0x54:
        return 0x17B;
    case 0x74:
        return 0x17C;
    case 0x94:
        return 0x17D;
    case 0x15:
        return 0x199;
    case 0x35:
        return 0x19A;
    case 0x55:
        return 0x19B;
    case 0x75:
        return 0x19C;
    case 0x95:
        return 0x19D;
    default:
        return 1;
    }
}

/* Total number of frames the terrain kind's TerrainAnimFrame list lasts: the sum
 * of its entries' durations, ending at the zero-duration terminator. */
s32 TerrainAnimTotalFrames(u8 *frameList) {
    s32 total;
    TerrainAnimFrame *frame;
    u8 duration;

    frame = (TerrainAnimFrame *)frameList;
    duration = frame->duration;
    total = 0;
    if (duration != 0) {
        do {
            total += duration;
            frame++;
            duration = frame->duration;
        } while (duration != 0);
    }
    return total;
}

/* Index of the frame the terrain kind's frame list shows on this game frame: walk
 * its entries' durations until the frame counter's position falls inside one. */
s32 GetTerrainAnimFrame(u8 *frameList) {
    s64 U32DivideRem(s32, s32);
    extern s32 gFrameCounter;
    s32 remaining;
    s32 index;
    u8 *frame;
    u8 duration;

    frame = frameList;
    index = 0;
    remaining = U32DivideRem(gFrameCounter, TerrainAnimTotalFrames(frameList)) >> 32;
    duration = *frame;
    while (duration != 0) {
        if (remaining <= duration) return index;
        remaining -= duration;
        frame += 3;
        duration = *frame;
        index++;
    }
    return 0;
}

#pragma scheduling off
/* Refresh the current tile offsets of the six animated terrain kinds: for each
 * kind with a frame list, pick the frame gFrameCounter falls in and copy that
 * frame's x/y offset out. */
void UpdateTerrainAnimOffsets(void) {
    extern u8 *gTerrainAnimFrames[];
    extern s32 gTerrainAnimOffsets[];
    s32 i = 0;
    s32 zero = i;
    u8 *frameList;
    u8 *frame;

    for (; i < TERRAIN_ANIM_KIND_COUNT; i++) {
        frameList = gTerrainAnimFrames[i];
        if (frameList != 0) {
            frame = frameList + GetTerrainAnimFrame(frameList) * 3;
            ((TerrainAnimOffset *)gTerrainAnimOffsets)[i].x = (s8)frame[1];
            ((TerrainAnimOffset *)gTerrainAnimOffsets)[i].y = (s8)frame[2];
        } else {
            ((TerrainAnimOffset *)gTerrainAnimOffsets)[i].x = zero;
            ((TerrainAnimOffset *)gTerrainAnimOffsets)[i].y = zero;
        }
    }
}
#pragma scheduling reset
s32 GetTerrainAnimOffset(s32 arg0) {
    extern s32 gTerrainAnimOffsets[];
    return gTerrainAnimOffsets[arg0];
}

/* Install `handler` as the HBlank (scanline) interrupt handler, enable that
 * interrupt, and queue the sprite task that turns the engine's HBlank IRQ on. */
void InstallHBlankIrqHandler(s32 handler) {
    M2C_UNK OS_SetIrqHandler(s32, s32);
    M2C_UNK OS_EnableIrqMask(s32);
    M2C_UNK CreateQueuedSpriteTask(M2C_UNK *, M2C_UNK);
    void EnableHBlankIrqTask(void);
    OS_SetIrqHandler(IRQ_HBLANK, handler);
    OS_EnableIrqMask(IRQ_HBLANK);
    CreateQueuedSpriteTask((M2C_UNK *)EnableHBlankIrqTask, 2);
}

/* Turn the HBlank (scanline) interrupt back off by queueing the sprite task that
 * clears the main sprite bank's HBlank enable and masks the interrupt; the
 * counterpart of InstallHBlankIrqHandler. */
void StopHBlankIrq(void) {
    M2C_UNK CreateQueuedSpriteTask(M2C_UNK *, M2C_UNK);
    void DisableHBlankIrqTask(void);
    CreateQueuedSpriteTask((M2C_UNK *)DisableHBlankIrqTask, 2);
}

/* Turn the HBlank (scanline) interrupt on in the main sprite bank; queued as a
 * sprite task by InstallHBlankIrqHandler so the change happens at a safe point. */
void EnableHBlankIrqTask(void) {
    extern void *g3DSpriteBankMain;
    ((DS3DSpriteBank *)g3DSpriteBankMain)->irqFlags |= DS3D_BANK_IRQ_HBLANK;
}

/* Disable the HBlank (scanline) interrupt: clear the main sprite bank's HBlank
 * enable and mask the interrupt in the IRQ controller. */
void DisableHBlankIrqTask(void) {
    void OS_DisableIrqMask(s32);
    extern void *g3DSpriteBankMain;
    ((DS3DSpriteBank *)g3DSpriteBankMain)->irqFlags &= ~DS3D_BANK_IRQ_HBLANK;
    OS_DisableIrqMask(IRQ_HBLANK);
}

#pragma push
#pragma opt_dead_code off
void func_0207fafc(void) {
extern void **gCur3DSpriteEngine;
extern s32 data_027e012c;
extern s32 data_027e0128;
extern s32 data_027e0124;
extern s32 data_027e0120;
extern u16 data_027e0108;
extern u16 data_027e010c;
extern u16 data_027e0100;
extern u16 data_027e0114;
extern u16 data_027e0118;
extern u16 data_027e00fc;
extern u16 data_027e0110;
extern u16 data_027e0104;
extern s32 data_027e011c;
s32 Is3DSpriteWholeLayer(u8,s32);
void GX_SetAlphaBlend(s32*,s32,s32,s32,s32);void GX_SetBlendState(s32*,s32,s32,s32,s32,s32);
extern void *g3DSpriteBankMain; extern u8 data_027e00f8;
void *engine=gCur3DSpriteEngine;
data_027e012c=(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<27)>>31)?1:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<26)>>31)?2:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<25)>>31)?4:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<24)>>31)?8:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<23)>>31)?16:0);
data_027e0128=(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<22)>>31)?1:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<21)>>31)?2:0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<20)>>31)?4:0);
data_027e0124=((M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,66)<<16)&(511<<16))|(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,58)&511);
data_027e0120=((M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,68)<<16)&(511<<16))|(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,60)&511);
{s32 a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),c=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),d=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8),e=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,8); data_027e0108=((u32)(e<<16)>>30<<14)|(*(volatile u16*)0x400000a&64)|((u32)(d<<24)>>31<<7)|((u32)(c<<19)>>27<<8)|((u32)(b<<26)>>28<<2)|((u32)(a<<30)>>30);}
if(Is3DSpriteWholeLayer((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<29)>>29),2)==1){{s32 a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),c=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),d=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10),e=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10); data_027e010c=((u32)(e<<16)>>30<<14)|(*(volatile u16*)0x400000c&64)|((u32)(d<<24)>>31<<7)|((u32)(c<<19)>>27<<8)|((u32)(b<<26)>>28<<2)|((u32)(a<<30)>>30);}}
else{data_027e010c=((*(volatile u16*)0x400000a&64)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<16)>>30<<14)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<19)>>27<<8)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<26)>>28<<2)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<18)>>31<<13)|((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,10)<<30)>>30));engine=gCur3DSpriteEngine;
data_027e0100=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,20);
data_027e0114=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,22);
data_027e0118=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,24);
data_027e00fc=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s16 *,26);
data_027e0110=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s32 *,28);
data_027e0104=(u16)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),s32 *,32);
}
switch((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18)<<24)>>30){
default:case 0:data_027e011c=0;break;
case 1:GX_SetAlphaBlend(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52));break;
case 2:GX_SetBlendState(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x53));break;
case 3:GX_SetBlendState(&data_027e011c,(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 31) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 30) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 29) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 28) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 27) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 26) >> 31) ? 32 : 0),(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 23) >> 31) ? 1 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 22) >> 31) ? 2 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 21) >> 31) ? 4 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 20) >> 31) ? 8 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 19) >> 31) ? 16 : 0)|(((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,18) << 18) >> 31) ? 32 : 0),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x51),M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x52),-(s32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u8 *,0x53));break;
}
data_027e00f8=(u32)(M2C_FIELD(g3DSpriteBankMain,u16 *,2)<<29)>>29;
}
#pragma pop
/* Create the screen-flash 3D sprite (cloned from source when one is given) and
 * set its fade-in, hold and fade-out durations. */
void CreateScreenFlash(s16 fadeInFrames, s16 holdFrames, s16 fadeOutFrames, s32 source) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gScreenFlashSpriteClass;
    void *sprite;

    if (source != 0) {
        sprite = CreateSpriteObject(&gScreenFlashSpriteClass, source);
    } else {
        sprite = CreateSpriteFromClass(&gScreenFlashSpriteClass, 7);
    }
    M2C_FIELD(sprite, s16 *, DS3D_SPRITE_FLASH_IN_FRAMES) = fadeInFrames;
    M2C_FIELD(sprite, s16 *, DS3D_SPRITE_FLASH_HOLD_FRAMES) = holdFrames;
    M2C_FIELD(sprite, s16 *, DS3D_SPRITE_FLASH_OUT_FRAMES) = fadeOutFrames;
}

/* Screen-flash callback: when the flash has a fade-out, reset the current sprite
 * bank's brightness to normal (0). */
void ResetScreenFlashBrightness(void *sprite) {
    extern void **gCur3DSpriteEngine;
    if (M2C_FIELD(sprite, s16 *, DS3D_SPRITE_FLASH_OUT_FRAMES) == 0) {
        return;
    }
    M2C_FIELD(*gCur3DSpriteEngine, s8 *, DS3D_BANK_BRIGHTNESS) = 0;
}

#pragma push
#pragma optimize_ifs off
/* Screen-flash init callback: reset the fade-in, hold and fade-out frame counters
 * and set the engine's brightness to white (16) when the flash has no fade-in,
 * otherwise to normal (0) so the fade-in callback raises it. */
void InitScreenFlash(void *sprite) {
    extern void **gCur3DSpriteEngine;
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_FLASH_IN_ELAPSED) = 0;
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_FLASH_HOLD_ELAPSED) = 0;
    M2C_FIELD(sprite, s32 *, DS3D_SPRITE_FLASH_OUT_ELAPSED) = 0;
    switch (M2C_FIELD(sprite, s16 *, DS3D_SPRITE_FLASH_IN_FRAMES)) {
    case 0:
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, DS3D_BANK_BRIGHTNESS) = 16;
        break;
    default:
        M2C_FIELD(*gCur3DSpriteEngine, s8 *, DS3D_BANK_BRIGHTNESS) = 0;
        break;
    }
}
#pragma pop
