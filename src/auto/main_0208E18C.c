/* 16 functions from 0x0208E18C to 0x0208EE90 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

typedef struct { s32 a; s32 b; } Pair;
typedef struct { u8 pad[0x60]; u64 v; u64 *p; } UnkNode0208EE1C;


void func_0208e18c(s32 a0, s32 a1, s16 a2, s32 a3, u16 a4, s32 a5) {
    typedef struct { s32 t[5][5]; } TileTable;
    void AddSprite(u16, u16, u16, void *, u8);
#define AddSprite ((void (*)(u16,u16,u16,void *,s32))AddSprite)
#define SHIFT (((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30)
    s32 Divide(s32, s32);
    void DrawVerticalBar(s32, s16, s16, u16, s32);
    void DrawVerticalBarReverse(s16, s16, s16, u16, s32);
    void DrawHorizontalBar(s16, s32, s16, u16, s32);
    void DrawHorizontalBarReverse(s16, s16, s16, u16, s32);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    extern s32 gCur3DSpriteEngine;
    extern TileTable data_020f35c8;
    extern u8 gSpriteDesc8x8[];
    extern s16 gSinCosTable[];
    TileTable tbl;
    s32 v8, vc, v10, v14, v18, v1c, v20, v38, v3c;
    s32 r4, r5, r6, r7, r11;

    s32 left, right, top, bottom, innerX, innerY, innerWidth, innerHeight;

    tbl = data_020f35c8;
    left = a0 & 0x1ff;
    top = a1 & 0xff;
    AddSprite((u16)left, (u16)top, (u16)(a4 + ((0x54 >> SHIFT) & 0x3ff)), gSpriteDesc8x8, a5);

    v8 = a0 + a2 - 8;
    right = v8 & 0x1ff;
    AddSprite((u16)right, (u16)top, (u16)(a4 + ((0x56 >> SHIFT) & 0x3ff)), gSpriteDesc8x8, a5);

    vc = a1 + a3 - 8;
    bottom = vc & 0xff;
    AddSprite((u16)left, (u16)bottom, (u16)(a4 + ((0x58 >> SHIFT) & 0x3ff)), gSpriteDesc8x8, a5);
    AddSprite((u16)right, (u16)bottom, (u16)(a4 + ((0x5a >> SHIFT) & 0x3ff)), gSpriteDesc8x8, a5);

    innerHeight = a3 - 16;
    innerY = a1 + 8;
    DrawVerticalBar(a0, (s16)innerY, (s16)innerHeight, (u16)(a4 + ((0x4a >> SHIFT) & 0x3ff)), a5);
    DrawVerticalBarReverse((s16)v8, (s16)innerY, (s16)innerHeight, (u16)(a4 + ((0x4a >> SHIFT) & 0x3ff)), a5);

    innerWidth = a2 - 16;
    innerX = a0 + 8;
    DrawHorizontalBar((s16)innerX, a1, (s16)innerWidth, (u16)(a4 + ((0x40 >> SHIFT) & 0x3ff)), a5);
    DrawHorizontalBarReverse((s16)innerX, (s16)vc, (s16)innerWidth, (u16)(a4 + ((0x40 >> SHIFT) & 0x3ff)), a5);

    v1c = (s16)innerHeight;
    v20 = (s16)innerY;
    r4 = 0x80;
    a2 -= 16;

    if (!(a2 < 0x40 && v1c < 0x40)) {
        s16 d0 = gSinCosTable[0];
        s16 d1 = gSinCosTable[1];
        s32 x5 = d1 << 4;
        s32 x6 = d0 * 16;
        s32 x7 = -d0 * 16;
        s32 c1 = Divide(x5, 0x200);
        s32 c2 = Divide(x7, 0x100);
        s32 c3 = Divide(x6, 0x200);
        s32 c4 = Divide(x5, 0x100);
        SetSpriteQuad(0x1c, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
        c1 = Divide(x5, 0x100);
        c2 = Divide(x7, 0x200);
        c3 = Divide(x6, 0x100);
        c4 = Divide(x5, 0x200);
        SetSpriteQuad(0x1b, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
        c1 = Divide(x5, 0x200);
        c2 = Divide(x7, 0x200);
        c3 = Divide(x6, 0x200);
        c4 = Divide(x5, 0x200);
        SetSpriteQuad(0x1f, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
    }

    v10 = (s16)(a0 + 8);
    v18 = 0;

    while (v18 < 5) {
        if (v1c >= r4) {
            v14 = a2;
            v38 = (u16)(((v20 - (r4 >> 1)) & 0xff) | 0x300);
            r11 = (u16)((v20 & 0xff) | 0x300);
            v3c = (u16)(v20 & 0xff);
            r5 = v10;
            r6 = 0x80;
            r7 = 0;
            while (r7 < 5) {
                while (v14 >= r6) {
                    if (r6 >= 0x40 && r4 >= 0x40) {
                        AddSprite((u16)((r5 & 0x1ff) | 0x3e00), (u16)r11, a4, (void *)tbl.t[v18][r7], a5);
                    } else if (r6 >= 0x40) {
                        AddSprite((u16)((r5 & 0x1ff) | 0x3800), (u16)v38, a4, (void *)tbl.t[v18][r7], a5);
                    } else if (r4 >= 0x40) {
                        AddSprite((u16)(((r5 - (r6 >> 1)) & 0x1ff) | 0x3600), (u16)r11, a4, (void *)tbl.t[v18][r7], a5);
                    } else {
                        AddSprite((u16)((r5 & 0x1ff)), (u16)v3c, a4, (void *)tbl.t[v18][r7], a5);
                    }
                    r5 += r6;
                    v14 -= r6;
                }
                r6 >>= 1;
                r7++;
            }
            v1c -= r4;
            v20 += r4;
            if (v1c >= r4) continue;
        }
        r4 >>= 1;
        v18++;
    }
#undef AddSprite
#undef SHIFT
}

/* Load the digit tiles and palette shared by timer and number displays. */
void LoadTimerSpriteGraphics(u32 textureOffset, s32 paletteSlot) {
    extern u8 sTimerGraphicsDirectory[], sTimerGraphicsArchive[];
    extern u8 sTimerTilesFile[], sTimerPaletteFile[];
    extern s32 gCur3DSpriteEngine;
    DS3DSpriteEngine *engine;

    SetFileDirectory(sTimerGraphicsDirectory);
    OpenNarcArchive(sTimerGraphicsArchive);
    LoadNarcFileDecompressed(sTimerTilesFile, DS3D_ENGINE(gCur3DSpriteEngine)->textureAddr + textureOffset);
    LoadNarcFileToSpriteBuffer(sTimerPaletteFile,
        (paletteSlot + DS3D_OBJ_PALETTE_BASE) << DS3D_PALETTE_SHIFT, DS3D_PALETTE_BYTES);
    CloseNarcArchive();
    engine = DS3D_ENGINE(gCur3DSpriteEngine);
    engine->layerDirty |= DS3D_DIRTY_PALETTE;
}

/* Draw a minutes:centiseconds readout with AddSprite digits at (x, y). */
void DrawTimerDigits(s16 x, s32 y, u16 baseTile, u8 priority, s32 value) {
s32 Divide(s32,s32);
void AddSprite(u16,u16,u16,void *,u8);
extern s32 gCur3DSpriteEngine;
extern u8 gSpriteDesc16x8[],gSpriteDesc8x8[];
s32 minutes,centis;
u16 sy;
const s32 mask=0x3ff;
minutes=Divide(value,60);
centis=Divide((value%60)*100,60);
if(value<600)baseTile+=(32>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask;
sy=(u16)y;
AddSprite((u16)x,sy,(u16)(baseTile+((22>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc16x8,priority);
x+=48;
AddSprite((u16)x,sy,(u16)(baseTile+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
centis=Divide(centis,10);
AddSprite((u16)x,sy,(u16)(baseTile+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
AddSprite((u16)x,sy,(u16)(baseTile+((20>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
do{
AddSprite((u16)x,sy,(u16)(baseTile+(((minutes%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
minutes=Divide(minutes,10);
x-=8;
}while(minutes!=0);
}

/* Point a countdown-timer display at the shared timer digit graphics: set its
 * texture row from the graphics offset, store the OBJ palette row in the actor's
 * palette field and load the digit tiles and palette. */
void SetTimerDisplayGraphics(void *display, u32 textureOffset, s32 paletteSlot) {
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_TILE_ROW) = (s16) (textureOffset >> 5);
    M2C_FIELD(display, s32 *, SPRITE_ACTOR_PALETTE) = (s32) ((M2C_FIELD(display, s32 *, SPRITE_ACTOR_PALETTE) & ~SPRITE_ACTOR_PALETTE_MASK) | ((u32) (paletteSlot << 0x18) >> 6));
    LoadTimerSpriteGraphics(textureOffset, paletteSlot);
}

void SetTimerDisplayTicks(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
}

/* Return whether the countdown timer display has reached zero. */
u8 IsTimerDisplayExpired(void *timerDisplay) {
    u8 isExpired;

    if (M2C_FIELD(timerDisplay, s32 *, TIMER_DISPLAY_TICKS) == 0) {
        isExpired = 1;
    } else {
        isExpired = 0;
    }
    return isExpired;
}

void func_0208eb80(void *p) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
void DrawTimerDigits(s16,s32,u16,u8,s32);
s32 saved,bank,i,clamped;
u32 mode,shift;
u16 pal,base,tile,bankVal;
void **bankPtr;
if(M2C_FIELD(p,s32 *,0x58)>0)M2C_FIELD(p,s32 *,0x58)--;
if(M2C_FIELD(p,s32 *,0x58)<0)M2C_FIELD(p,s32 *,0x58)=0;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;
mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==g3DSpriteEngineMain)&&(mode!=1||bank==g3DSpriteEngineSub)&&(mode!=3||bank==saved)){
bankPtr=(void **)bank;
bankVal=M2C_FIELD(bankPtr,u16 *,0);
shift=(((u32)bankVal)<<17)>>30;
pal=(u16)((u32)(M2C_FIELD(p,u32 *,0x40)<<6)>>24);
base=M2C_FIELD(p,u16 *,0x3c);
tile=M2C_FIELD(p,u16 *,0x3e);
clamped=M2C_FIELD(p,s32 *,0x58);
DrawTimerDigits((s16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&511),
(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255,
(u16)(base|((u16)(pal<<12))|(((u32)tile>>shift)&1023)),
M2C_FIELD(p,u8 *,0x49),clamped);
}}
gCur3DSpriteEngine=saved;
}

/* Constructor of a countdown-timer display sprite: run the sprite actor's shared
 * base initialiser, install the timer display's class, draw on the main screen
 * (or both when created while the sub engine is current), and reset its position
 * and remaining time. */
void *InitTimerDisplay(void *display) {
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gTimerDisplayVtable;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 isMain;
    u8 target;

    Init3DSpriteActor();
    M2C_FIELD(display, M2C_UNK **, 0) = &gTimerDisplayVtable;
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        isMain = 1;
    } else {
        isMain = 0;
    }
    if (isMain != 1) {
        target = 1;
    } else {
        target = 0;
    }
    M2C_FIELD(display, u8 *, SPRITE_ACTOR_STATE) = (u8) ((M2C_FIELD(display, u8 *, SPRITE_ACTOR_STATE) & ~0xE) | ((u32) (target << 0x1D) >> 0x1C));
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_X) = 0;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_Y) = 0;
    M2C_FIELD(display, s32 *, TIMER_DISPLAY_TICKS) = 0;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_TILE) = 0;
    return display;
}

void func_0208ed40(void) {

}

s32 func_0208ed44(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208ed58(void *p){func_0208eb80(p);}

/* Create the countdown-timer display sprite owned by `owner` and initialise it;
 * nothing is created when the sprite could not be made. */
void CreateTimerDisplay(void *owner) {
    s32 CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *InitTimerDisplay();
    extern M2C_UNK gTimerDisplayClass;

    if (CreateSpriteFromClass(&gTimerDisplayClass, owner) == 0) {
        return;
    }
    InitTimerDisplay();
}

/* Constructor of a number-display sprite: run the sprite actor's shared base
 * initialiser, install the number display's vtable, draw on the main screen (or
 * both when the display is created while the sub engine is current), and start
 * with no digits shown: cursor on digit 0, nine digits, value 0 and no source. */
void *InitNumberDisplay(void *display) {
    M2C_UNK Init3DSpriteActor();
    extern M2C_UNK gNumberDisplayVtable;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 isMain;
    u8 target;

    Init3DSpriteActor();
    M2C_FIELD(display, M2C_UNK **, 0) = &gNumberDisplayVtable;
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        isMain = 1;
    } else {
        isMain = 0;
    }
    if (isMain != 1) {
        target = 1;
    } else {
        target = 0;
    }
    M2C_FIELD(display, u8 *, SPRITE_ACTOR_STATE) = (u8) ((M2C_FIELD(display, u8 *, SPRITE_ACTOR_STATE) & ~0xE) | ((u32) (target << 0x1D) >> 0x1C));
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_X) = 0;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_Y) = 0;
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_TILE) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_DIGIT) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_DIGITS) = 9;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_VALUE) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_HIGH) = 0;
    M2C_FIELD(display, s32 *, NUMBER_DISPLAY_SOURCE) = 0;
    return display;
}

#pragma opt_propagation off
/* Non-deleting destructor of a number display: write the value it displays back
 * through its source pointer and return the display; DeleteNumberDisplay does
 * that and then frees it. */
void *DestroyNumberDisplay(void *display) {
    u64 *source = M2C_FIELD(display, u64 **, NUMBER_DISPLAY_SOURCE);
    if (source != 0) {
        *source = M2C_FIELD(display, u64 *, NUMBER_DISPLAY_VALUE);
    }
    return display;
}
#pragma opt_propagation reset
/* Deleting destructor of a number-display sprite: write the value it displays
 * back through its NUMBER_DISPLAY_SOURCE pointer, then free the sprite. */
void *DeleteNumberDisplay(void *display) {
    void *source;

    source = M2C_FIELD(display, void **, NUMBER_DISPLAY_SOURCE);
    if (source != 0) {
        *(u64 *)source = M2C_FIELD(display, u64 *, NUMBER_DISPLAY_VALUE);
    }
    MemFree(display);
    return display;
}

#pragma opt_propagation reset
/* Point a number display at another digit graphics set: make its texture row
 * from the set's byte offset in the tiles area (32 bytes a tile) and its palette
 * row from the palette slot, then load that set's tiles and palette. */
void SetNumberDisplayGraphics(void *display, u32 tileOffset, s32 paletteSlot) {
    M2C_FIELD(display, s16 *, SPRITE_ACTOR_TILE_ROW) = (s16) (tileOffset >> 5);
    M2C_FIELD(display, s32 *, SPRITE_ACTOR_PALETTE) = (s32) ((M2C_FIELD(display, s32 *, SPRITE_ACTOR_PALETTE) & ~SPRITE_ACTOR_PALETTE_MASK) | ((u32) (paletteSlot << 0x18) >> 6));
    LoadTimerSpriteGraphics(tileOffset, paletteSlot);
}

