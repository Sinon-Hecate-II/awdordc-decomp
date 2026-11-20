/* 19 functions from 0x02082340 to 0x02083320 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "map_selection.h"
typedef MapSelectionLists Lists020830;

/* Packed attributes of one 3D sprite layer, as passed to Configure3DSpriteLayer.
 * Field names are the bit offsets: f0 texture VRAM bank (4 bits), f4 palette
 * (5), f9 layer size class (2), f11 two tile-map type bits the layer copies,
 * then f13/f14 single flag bits; f15 is unused. */
typedef struct { u16 f0:4; u16 f4:5; u16 f9:2; u16 f11:2; u16 f13:1; u16 f14:1; u16 f15:1; } SpriteAttr;
/* Tile-map entry the 3D sprite engine keeps for every layer; names are the bit
 * offsets. f2 is the texture VRAM bank, f8 the palette index and f14 the size
 * class; f0/f6/f7/f13 are type and flag bits. */
typedef struct { u16 f0:2; u16 f2:4; u16 f6:1; u16 f7:1; u16 f8:5; u16 f13:1; u16 f14:2; } SpriteTile;
/* The engine's first entry has its own layout: f0 is the bank mode. */
typedef struct { u16 f0:3; u16 f3:13; } SpriteHead;

#pragma scheduling off
/* Configures one 3D sprite layer from its packed attribute word: texture VRAM
 * bank, palette, size class and tile-map flags, then uploads the layer's tile
 * buffer to the layer's VRAM window. */
void Configure3DSpriteLayer(s32 layer, SpriteAttr *attr) {
    void MI_CpuFill32(s32, s32, s32);
    void MI_CpuCopy32(s32, s32, s32);
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    u8 onMain;
    u32 vramBase;
    s32 size;
    u32 src;

    if (gCur3DSpriteEngine == g3DSpriteEngineMain) onMain = 1; else onMain = 0;
    if (onMain == 1) vramBase = 0x06000000; else vramBase = 0x06200000;
    Set3DSpriteLayerBank(layer, (u8)attr->f0);
    Set3DSpriteLayerPalette(layer, (u8)attr->f4);
    SetLayerSize(layer, (u8)attr->f9);
    ((SpriteTile *)((u8 *)*gCur3DSpriteEngine + 6))[layer].f0 = attr->f11;
    ((SpriteTile *)((u8 *)*gCur3DSpriteEngine + 6))[layer].f7 = attr->f13;
    ((SpriteTile *)((u8 *)*gCur3DSpriteEngine + 6))[layer].f13 = attr->f14;
    MI_CpuFill32(0, M2C_FIELD(gCur3DSpriteEngine + layer, s32 *, 0xc), 0x40);
    Clear3DSpriteLayer(layer);
    size = Get3DSpriteLayerSize((u8)((SpriteHead *)*gCur3DSpriteEngine)->f0, layer);
    src = vramBase + ((u32)((volatile SpriteTile *)((u8 *)*gCur3DSpriteEngine + 6))[layer].f8 << 11);
    MI_CpuCopy32(M2C_FIELD(gCur3DSpriteEngine + layer, volatile s32 *, 0x20), src, size);
}
#pragma scheduling on
/* Reset the current 3D sprite engine's bank for its layers: clear the bank flags
 * and the four layer tile words, clear both 3-bit fields of the flags word at
 * bank+0x02 (DS3D_BANK_MODE_WORD), and rebuild both layer matrices from the
 * default transform. */
void Reset3DSpriteLayerRegisters(void) {
    void Build3DSpriteTransform(void *, void *);
    extern void **gCur3DSpriteEngine;
    extern u8 sSpriteTransformDefault[];
    u16 * volatile modeWord0;
    u16 * volatile modeWord1;

    ((u16 *)*gCur3DSpriteEngine)[0] = 0;
    ((u16 *)*gCur3DSpriteEngine)[3] = 0;
    ((u16 *)*gCur3DSpriteEngine)[4] = 0;
    ((u16 *)*gCur3DSpriteEngine)[5] = 0;
    ((u16 *)*gCur3DSpriteEngine)[6] = 0;

    modeWord0 = (u16 *)*gCur3DSpriteEngine + 1;
    *modeWord0 = *modeWord0 & ~7;

    modeWord1 = (u16 *)*gCur3DSpriteEngine + 1;
    *modeWord1 = *modeWord1 & ~0x38;

    Build3DSpriteTransform(sSpriteTransformDefault, (u8 *)*gCur3DSpriteEngine + 0x14);
    Build3DSpriteTransform(sSpriteTransformDefault, (u8 *)*gCur3DSpriteEngine + 0x24);
}

/* Reset the current 3D sprite engine's layer configuration: clear the five
   screen-mode bits and the four layer attribute words, clear the low bits of the
   bank mode word, and restore both layer transforms to the default. */
void Reset3DSpriteLayers(void){
void Build3DSpriteTransform(void *,void *);extern void **gCur3DSpriteEngine;extern u8 sSpriteTransformDefault[];
u16 *volatile mode0;u16 *volatile mode1;u16 *volatile mode2;u16 *volatile mode3;u16 *volatile mode4;u16 *volatile bankMode;u16 *volatile bankMode2;
mode0=*gCur3DSpriteEngine;*mode0=*mode0&~DS3D_BANK_MODE0;
mode1=*gCur3DSpriteEngine;*mode1=*mode1&~DS3D_BANK_MODE1;
mode2=*gCur3DSpriteEngine;*mode2=*mode2&~DS3D_BANK_MODE2;
mode3=*gCur3DSpriteEngine;*mode3=*mode3&~DS3D_BANK_MODE3;
mode4=*gCur3DSpriteEngine;*mode4=*mode4&~DS3D_BANK_MODE4;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,DS3D_BANK_LAYER_TILE0)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,DS3D_BANK_LAYER_TILE1)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,DS3D_BANK_LAYER_TILE2)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,DS3D_BANK_LAYER_TILE3)=0;
bankMode=(u16 *)*gCur3DSpriteEngine+1;*bankMode=*bankMode&~7;
bankMode2=(u16 *)*gCur3DSpriteEngine+1;*bankMode2=*bankMode2&~0x38;
Build3DSpriteTransform(sSpriteTransformDefault,(u8 *)*gCur3DSpriteEngine+0x14);
Build3DSpriteTransform(sSpriteTransformDefault,(u8 *)*gCur3DSpriteEngine+0x24);
}

void Reset3DSpriteCorners(void) {
    extern void **gCur3DSpriteEngine;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x38) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3C) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x44) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3E) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x46) = 0;
}

/* Clear every mode, layer-select and split-row setting of the current 3D
 * sprite engine's bank, leaving it with no layers configured. */
void Reset3DSpriteBankState(void) {
    extern void **gCur3DSpriteEngine;
    u16 *volatile oamC0;
    u16 *volatile oam1;
    u16 *volatile oam2;
    u16 *volatile oam4;
    u16 *volatile oam8;
    u16 *volatile oam10;
    u16 *volatile oam20;
    u16 *volatile oam100;
    u16 *volatile oam200;
    u16 *volatile oam400;
    u16 *volatile oam800;
    u16 *volatile oam1000;
    u16 *volatile oam2000;

    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr = 0;
    oamC0 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oamC0 = *oamC0 & ~0xC0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsAbove = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsBelow = 0;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->filler_53 = 0;
    oam1 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1 = *oam1 & ~0x1;
    oam2 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2 = *oam2 & ~0x2;
    oam4 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam4 = *oam4 & ~0x4;
    oam8 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam8 = *oam8 & ~0x8;
    oam10 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam10 = *oam10 & ~0x10;
    oam20 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam20 = *oam20 & ~0x20;
    oam100 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam100 = *oam100 & ~0x100;
    oam200 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam200 = *oam200 & ~0x200;
    oam400 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam400 = *oam400 & ~0x400;
    oam800 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam800 = *oam800 & ~0x800;
    oam1000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1000 = *oam1000 & ~0x1000;
    oam2000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2000 = *oam2000 & ~0x2000;
}

/* Resets the current 3D sprite engine's sprite queues and status flags. */
void Reset3DSpriteEngineState(void) {
    extern void **gCur3DSpriteEngine;
    u16 *volatile a;
    u16 *volatile b;
    u16 *volatile c;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0xE) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x10) = 0;
    a = *gCur3DSpriteEngine;
    *a = *a & ~0x200;
    b = *gCur3DSpriteEngine;
    *b = *b & ~0x400;
    c = *gCur3DSpriteEngine;
    *c = *c & ~0x800;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x48) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4A) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x49) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4B) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4C) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4E) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4D) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x4F) = 0;
}

#pragma scheduling off
void Build3DSpriteTransform(void *arg0, void *arg1) {
s32 Divide(s32,s16);
extern s16 gSinCosTable[];
void *out=arg1; void *in=arg0;
s32 x,y,dx,dy,index,sine,cosine,a,b;
index=((s32)(u16)(M2C_FIELD(in,u16 *,0x10)<<8)>>4)*2;
cosine=gSinCosTable[index+1]<<8;
x=M2C_FIELD(in,s32 *,0); y=M2C_FIELD(in,s32 *,4);
dx=x-M2C_FIELD(in,s16 *,8);dy=y-M2C_FIELD(in,s16 *,10);
M2C_FIELD(out,s16 *,0)=Divide(cosine,M2C_FIELD(in,s16 *,12))>>4;
sine=gSinCosTable[index]<<8;
M2C_FIELD(out,s16 *,2)=Divide(sine,M2C_FIELD(in,s16 *,12))>>4;
M2C_FIELD(out,s16 *,4)=(-Divide(sine,M2C_FIELD(in,s16 *,14)))>>4;
M2C_FIELD(out,s16 *,6)=Divide(cosine,M2C_FIELD(in,s16 *,14))>>4;
b=dy-y;a=dx-x;
M2C_FIELD(out,s32 *,8)=M2C_FIELD(out,s16 *,0)*a+M2C_FIELD(out,s16 *,2)*b+(x<<8);
M2C_FIELD(out,s32 *,12)=M2C_FIELD(out,s16 *,4)*a+M2C_FIELD(out,s16 *,6)*b+(y<<8);
}
/* Restore both display banks, layers, windows and brightness to their defaults. */
void Reset3DSpriteDisplayState(void) {
    extern void *g3DSpriteBankMain;
    extern void *g3DSpriteBankSub;
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineSub;
    extern void **g3DSpriteEngineMain;
    u16 *volatile objMapping;
    u16 *volatile objBoundary;
    void **savedEngine;
    s32 engineIndex;

    ((DS3DSpriteBank *)g3DSpriteBankMain)->displayMode = DS3D_DISPLAY_GRAPHICS;
    ((DS3DSpriteBank *)g3DSpriteBankSub)->displayMode = DS3D_DISPLAY_GRAPHICS;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~1) | 1;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) &= ~2;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) &= ~4;
    objMapping = *gCur3DSpriteEngine;
    *objMapping = *objMapping & ~DS3D_BANK_OBJ_1D;
    objBoundary = *gCur3DSpriteEngine;
    *objBoundary = *objBoundary & ~DS3D_BANK_OBJ_BOUNDARY_MASK;
    savedEngine = gCur3DSpriteEngine;
    for (engineIndex = 0; engineIndex < 2; engineIndex++) {
        gCur3DSpriteEngine = engineIndex == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        Reset3DSpriteLayerRegisters();
        Reset3DSpriteCorners();
        Reset3DSpriteBankState();
        Reset3DSpriteEngineState();
        ((DS3DSpriteBank *)*gCur3DSpriteEngine)->brightness = 0;
    }
    gCur3DSpriteEngine = savedEngine;
}

void func_02082c84(void) {
    M2C_UNK func_02003538();
    M2C_UNK func_0200354c();
    M2C_UNK func_02003560();
    M2C_UNK func_02003584();
    M2C_UNK func_020035a8();
    M2C_UNK func_020035bc();
    M2C_UNK func_0200360c();
    M2C_UNK func_02003620();
    M2C_UNK func_02003634();
    M2C_UNK func_0200365c();
    func_02003538();
    func_0200354c();
    func_02003560();
    func_02003584();
    func_020035a8();
    func_020035bc();
    func_0200360c();
    func_02003620();
    func_02003634();
    func_0200365c();
}

void Set3DSpriteVramBanks(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK GX_SetBankForOBJ(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK GX_SetBankForTex(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPltt(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK GX_SetBankForBGExtPlttSub(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPlttSub(M2C_UNK);
    func_02082c84();
    GX_SetBankForTex(1);
    GX_SetBankForBG(2);
    func_02003124(4);
    func_020031cc(8);
    GX_SetBankForOBJ(0x10);
    GX_SetBankForOBJExtPltt(0x20);
    func_02002ab8(0x40);
    GX_SetBankForBGExtPlttSub(0x80);
    GX_SetBankForOBJExtPlttSub(0x100);
}

/* Initialise both 3DS-sprite engines: select the main engine as the current one,
   give each engine its sprite bank, texture address, OAM/sprite buffers and
   offset fields, clear its OAM buffer and per-engine offsets, then install the
   two engines' sprite list pointers. */
void func_02082d08(void) {
    void MI_CpuFill32(s32, s32, s32);
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    extern void *g3DSpriteBankMain;
    extern void *g3DSpriteBankSub;
    extern void **g3DSpriteEngineSub;
    extern u8 data_027e068c[];
    extern u8 data_0214e8dc[];
    extern u8 data_0214e0dc[];
    extern u8 data_0214d2dc[];
    extern u8 data_027e028c[];
    extern u8 data_0214e4dc[];
    extern u8 data_0214dcdc[];
    extern u8 data_0214c8dc[];
    extern u8 data_0214c2d4[];
    extern u8 data_0214c5d8[];
    extern u8 data_0214c20c[];
    extern u8 data_0214c270[];

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->bank = g3DSpriteBankMain;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->textureAddr = 0x06400000;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->oamBuffer = (void *)data_027e068c;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->oamEntries = (u16 *)data_0214e8dc;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->spriteSrc = (u16 *)data_0214e0dc;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->sprites = (void *)data_0214d2dc;
    MI_CpuFill32(0, (s32)((DS3DSpriteEngine *)g3DSpriteEngineMain)->oamBuffer, 0x400);
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->offsetX = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->offsetY = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->filler_40 = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->filler_42 = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->filler_44 = 0;

    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->bank = g3DSpriteBankSub;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->textureAddr = 0x06600000;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->oamBuffer = (void *)data_027e028c;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->oamEntries = (u16 *)data_0214e4dc;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->spriteSrc = (u16 *)data_0214dcdc;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->sprites = (void *)data_0214c8dc;
    MI_CpuFill32(0, (s32)((DS3DSpriteEngine *)g3DSpriteEngineSub)->oamBuffer, 0x400);
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->offsetX = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->offsetY = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->filler_40 = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->filler_42 = 0;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->filler_44 = 0;

    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->filler_50 = (void *)data_0214c2d4;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->filler_50 = (void *)data_0214c5d8;
    ((DS3DSpriteEngine *)g3DSpriteEngineMain)->filler_54 = (void *)data_0214c20c;
    ((DS3DSpriteEngine *)g3DSpriteEngineSub)->filler_54 = (void *)data_0214c270;
}

/* Copy `size` bytes of a buffer straight into the current 3D sprite engine's BG
 * extended palette: the main engine's when it is current, the sub engine's
 * otherwise, at the given palette slot and byte offset. */
void UploadBGExtPalette(s32 src, s32 paletteSlot, s32 offset, s32 size) {
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    void DC_FlushRange(s32, s32);
    void GX_BeginLoadBGExtPltt(void);
    void GX_LoadBGExtPltt(s32, s32, s32);
    void GX_EndLoadBGExtPltt(void);
    void GX_BeginLoadBGExtPlttSub(void);
    void GX_LoadBGExtPlttSub(s32, s32, s32);
    void GX_EndLoadBGExtPlttSub(void);
    s32 isMainEngine;
    DC_FlushRange(src, size);
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) isMainEngine = 1; else isMainEngine = 0;
    if (isMainEngine & 255) {
        GX_BeginLoadBGExtPltt();
        GX_LoadBGExtPltt(src, offset + (paletteSlot << 13), size);
        GX_EndLoadBGExtPltt();
    } else {
        GX_BeginLoadBGExtPlttSub();
        GX_LoadBGExtPlttSub(src, offset + (paletteSlot << 13), size);
        GX_EndLoadBGExtPlttSub();
    }
}

/* Whether map `mapId` can be played in the current session: with no link
 * session the link-only custom map slots are unavailable, and with one the map
 * must seat at least as many players as the session.  A campaign map slot must
 * hold a playable map record. */
s32 IsMapValidForSession(s32 mapId) {
    s32 IsLinkSessionActive();
    s32 GetSessionPlayerCount();
    s32 IsCampaignMapRecordPlayable(s32);
    s32 GetMapPlayerCount(u16);
    s32 players;

    if (IsLinkSessionActive() == 0) {
        if ((mapId >= MAP_CUSTOM_FIRST) && (mapId < MAP_CUSTOM_LINK_END) && (mapId >= MAP_CUSTOM_LOCAL_END)) {
            return 0;
        }
        goto campaign_check;
    }
    players = GetMapPlayerCount((u16) mapId);
    if (players < GetSessionPlayerCount()) {
        return 0;
    }
campaign_check:
    if ((mapId >= MAP_CUSTOM_FIRST) && (mapId < MAP_CUSTOM_LINK_END) && (IsCampaignMapRecordPlayable(mapId) == 0)) {
        return 0;
    }
    return 1;
}

s32 func_02082fc4(u32 x){switch(x){case 0:return 1;case 2:return 3;case 1:return 2;case 3:return 4;case 4:return 5;case 5:return 6;case 6:return 7;default:return 0;}}

/* Maps a map-list category (a slot of the map-selection list, MAP_LIST_*) to the
 * map-data category (MapData_GetCategory) its maps are drawn from: the first six
 * list slots are the six data categories in order, and every custom-map list slot
 * uses the custom category. */
s32 MapListCategoryToDataCategory(u32 listCategory) {
    switch (listCategory) {
    case 2: return 1;
    case 4: return 3;
    case 1: return 0;
    case 5: return 4;
    case 6: return 5;
    case 3: return 2;
    case MAP_LIST_CUSTOM:
    case MAP_LIST_LINK_CUSTOM_FIRST:
    case 9:
    case 10:
    case 11:
        return MAP_DATA_CATEGORY_CUSTOM;
    default: return 0;
    }
}

u8 func_020830a8(u16 x){ s32 MapData_GetCategory(void); s32 IsCampaignMapRecordPlayable(s32); s32 GetMapPlayerCount(u16); u8 y=func_02082fc4(MapData_GetCategory()); if(y!=7)return y; if(!IsCampaignMapRecordPlayable(x))return 7; return GetMapPlayerCount(x)+7; }

#pragma opt_common_subs off
/* Build the available map categories, or a single list of local custom-map slots. */
void BuildMapSelectionLists(u32 mode, MapSelectionLists *lists, s32 playerCount) {
    s32 IsLinkSessionActive(void);
    void BuildMapSelectionCategory(void *, s32, s32);
    s32 category;
    u8 mapCount = 0;

    lists->count = 0;
    switch (mode) {
    case 0:
    case 8:
        for (category = 2; category < MAP_LIST_CATEGORY_END; category++) {
            if (!IsLinkSessionActive()) {
                if (category < MAP_LIST_LINK_CUSTOM_FIRST || category > 11) goto process;
                goto next;
            } else if (category == MAP_LIST_CUSTOM) goto next;
        process:
            if (mode == 8 && category == MAP_LIST_CUSTOM) continue;
            BuildMapSelectionCategory((void *)lists + (lists->count << 9), (u8)category, playerCount);
            if (M2C_FIELD((void *)lists + (lists->count << 9), u8 *, MAP_LIST_COUNT_OFFSET)) lists->count++;
        next:;
        }
        break;
    case 6:
    case 7:
    case 9:
        lists->count = 1;
        for (category = MAP_CUSTOM_FIRST; category < MAP_CUSTOM_LOCAL_END; category++) {
            M2C_FIELD(lists, u16 *, mapCount * 2) = category;
            mapCount++;
        }
        M2C_FIELD(lists, u8 *, MAP_LIST_COUNT_OFFSET) = mapCount;
        M2C_FIELD(lists, u8 *, MAP_LIST_CATEGORY_OFFSET) = MAP_LIST_CUSTOM;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
}
#pragma opt_common_subs reset
/* Fills one map-list category block with the ids the current session may pick:
 * every selectable map of the category's map-record type and the requested player
 * count, and outside the campaign range only the maps of this category's link
 * block.  Stores the category at +0x1fe and the number of ids at +0x1ff. */
void BuildMapSelectionCategory(void *categoryBlock,s32 listCategory,s32 playerCount){
s32 IsLinkSessionActive(void);s32 IsMapInLinkCategory(s32,s32);
s32 count=0; s32 mapId; s32 limit; u8 mapCategory;
M2C_FIELD(categoryBlock,u8 *,MAP_LIST_CATEGORY_OFFSET)=listCategory;
mapCategory=MapListCategoryToDataCategory(listCategory);
if(IsLinkSessionActive())limit=MAP_CUSTOM_LINK_END;else limit=MAP_CUSTOM_LOCAL_END;
mapId=0;while(mapId<limit){if(IsMapSelectable(mapId,mapCategory,playerCount)){if(mapId<MAP_CUSTOM_FIRST || mapId>=MAP_CUSTOM_LINK_END || IsMapInLinkCategory(mapId,listCategory)){((u16 *)categoryBlock)[count]=mapId;count++;}}mapId++;}
M2C_FIELD(categoryBlock,u8 *,MAP_LIST_COUNT_OFFSET)=count;
}

/* Whether map `mapId` can be picked in the current session: it must belong to the
   requested map-data category, be valid for the session, have the requested number
   of players (when one is asked for), and outside a link session a category-2 map
   must also be flagged available in the map list. */
s32 IsMapSelectable(s32 mapId,s32 dataCategory,s32 playerCount){
s32 MapData_GetCategory(void);s32 IsLinkSessionActive(void);s32 IsMapListFlagSet(s32);s32 GetMapPlayerCount(u16);
if(dataCategory!=MapData_GetCategory())return 0;
if(!IsMapValidForSession(mapId))return 0;
if(playerCount && playerCount!=GetMapPlayerCount((u16)mapId))return 0;
if(!IsLinkSessionActive() && dataCategory==2){if(!IsMapListFlagSet(mapId))return 0;}
return 1;
}

