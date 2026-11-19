/* 10 functions from 0x02172754 to 0x02173468 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct PaletteIndices { u8 values[6]; } PaletteIndices;
typedef struct ArmyInfoCoStatus {
    u32 face : 8;
    u32 : 13;
    u32 power : 11;
} ArmyInfoCoStatus;
static inline u16 *ScenePalette(u32 n) { extern void *gCur3DSpriteEngine; return (u16 *)(M2C_FIELD(gCur3DSpriteEngine,u8 **,0x30)+((n<<5)&~1)); }
extern s32 data_ov000_021b976c, data_ov000_021b9bec, data_ov000_021bb06c, data_ov000_021b9c6c, data_ov000_021b99ec, data_ov000_021bb1ec;
extern void *g3DSpriteEngineSub;
extern void *gCur3DSpriteEngine;
extern void **gCurrentMap;extern M2C_UNK gInfoFrameGfxUnset, gInfoFrameGfxEnglish, gInfoFrameGfxFrench, gInfoFrameGfxGerman, gInfoFrameGfxItalian, gInfoFrameGfxSpanish;
extern M2C_UNK data_ov000_021d841c, data_ov000_021b8f5c;

#pragma opt_strength_reduction off
s32 func_ov000_02172754(void *arg0) {
    s32 GetTerrainKindFromInfoId(s32);
    s32 func_020a86c4(s32, s32);
    s32 Divide(s32, s32);
    void LoadFacePalette(s32, s32, s32, s32, u8);
    s32 GetPlayerArmyVariantIfSet(s32);
    s32 GetCoPowerMeterCost(M2C_UNK, M2C_UNK);
    s32 _fflt(s32);
    s32 func_020714f0(s32, s32);
    s32 func_02071a1c(u32);
    s32 _fmul(u32, u32);
    s32 _fdiv(s32, s32);
    u32 _ffix(s32);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void **gCurrentMap;
    extern s8 gTerrainDefenseStars[32];

    void *context = arg0;
    s32 player;
    s32 playerId;
    s32 changed;
    void *saved;
    s32 off;
    s32 *p18;
    s32 val;
    s32 i;
    u8 *rcd;
    s32 funds;
    s32 r8v;
    int k;
    void *rec;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    p18 = *(s32 **)((u8 *)arg0 + 0x18);
    changed = 0;
    val = GetTerrainKindFromInfoId(*p18);
    val = func_020a86c4(0, val);
    p18 = *(s32 **)((u8 *)context + 0x18);
    if (val >= 0 && val <= 0x270f && val != p18[2]) {
        s32 q,rem;
        q = Divide(val, 0x3e8);
        p18[6] = q;
        rem = val - q * 0x3e8;
        q = Divide(rem, 0x64);
        p18[5] = q;
        rem = rem - q * 0x64;
        q = Divide(rem, 0xa);
        p18[4] = q;
        p18[3] = rem - q * 0xa;
        p18[2] = val;
    }
    val = GetTerrainKindFromInfoId(**(s32 **)((u8 *)context + 0x18));
    val = gTerrainDefenseStars[val];
    (*(s32 **)((u8 *)context + 0x18))[1] = val;
    i = 0;
    off = 0;
    do {
        u8 *map = *(u8 **)gCurrentMap;
        u8 *info = *(u8 **)((u8 *)context + 0x18);
        playerId = i + 1;
        rec = map + 0x67a4 + playerId * 0x8c;
        rcd = info + 0x3c + off;
        {
            u8 b1e = *((u8 *)rec + 0x1e);
            u8 old34;
            u8 old33;
            old33 = rcd[0x33];
            old34 = rcd[0x34];
            player = playerId;
            if (b1e == 0 || *((u8 *)rec + 0x19) != 0) {
                rcd[0x33] = 0;
            } else {
                rcd[0x33] = 1;
            }
            rcd[0x34] = (*((u8 *)rec + 0x1c) != 0);
            if (rcd[0x33] != old33) changed = 1;
            if (rcd[0x34] != old34) {
                ArmyInfoCoStatus *co = (ArmyInfoCoStatus *)((u8 *)rec + 0x6c);
                changed = 1;
                LoadFacePalette((u8)co->face, 0, 2, (u16)i, (u8)8);
            }
            {
                int j;
                s32 ready;
                ArmyInfoCoStatus *co = (ArmyInfoCoStatus *)((u8 *)rec + 0x6c);
                funds = *(s32 *)rec;
                if (funds >= 0 && funds <= 0xf423f) {
                    if (funds != *(s32 *)(rcd + 0x2c)) {
                        s32 initial = 1;
                        *(s32 *)(rcd + 0x2c) = funds;
                        *(s32 *)(rcd + 0x28) = initial;
                        for (k = 5; k >= 0; k--) {
                            r8v = initial;
                            for (j = 0; j < k; j++) r8v *= 10;
                            {
                                s32 q2 = Divide(funds, r8v);
                                if (*(s32 *)(rcd + 0x28) == 1 && q2 != 0) *(s32 *)(rcd + 0x28) = k + 1;
                                funds = funds - q2 * r8v;
                                *(s32 *)(rcd + 0x10 + k * 4) = q2;
                            }
                        }
                    }
                }
                *(s32 *)(rcd + 0xc) = *((u8 *)rec + 0x18);
                *(s32 *)(rcd + 8) = *((u8 *)rec + 0x31);
                *(u8 *)(rcd + 0x30) = (u8)GetPlayerArmyVariantIfSet(player);
                funds = GetCoPowerMeterCost(player, 2);
                if (0.0f == (float)funds) {
                    *(s32 *)(rcd + 4) = 0;
                    rcd[0x31] = 0;
                    ready = 0;
                } else {
                    u32 power = co->power;
                    *(s32 *)(rcd + 4) = (s32)((12.0f * (float)power) / (float)funds);
                    rcd[0x31] = ((u32)funds == (co->power));
                    ready = 1;
                }
                rcd[0x32] = ready;
            }
        }
        i++;
        off += 0x38;
    } while (i < 4);
    return (gCur3DSpriteEngine = saved, changed);
}
#pragma opt_strength_reduction reset
/* Uploads the info window's frame graphics for the window's language
   (LANGUAGE_*) into the sub screen's tile buffer. */
void DrawInfoWindowFrame(void *unused) {
 M2C_UNK LoadGraphicsBlock(M2C_UNK *,s32); u32 GetInfoWindowLanguage();
 void *savedEngine; s32 tiles; M2C_UNK *gfx;
 tiles=M2C_FIELD(g3DSpriteEngineSub,s32 *,0x28); savedEngine=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineSub;
 switch(GetInfoWindowLanguage()) {
 case LANGUAGE_UNSET:gfx=&gInfoFrameGfxUnset;break;
 case LANGUAGE_ENGLISH:gfx=&gInfoFrameGfxEnglish;break;
 case LANGUAGE_FRENCH:gfx=&gInfoFrameGfxFrench;break;
 case LANGUAGE_GERMAN:gfx=&gInfoFrameGfxGerman;break;
 case LANGUAGE_ITALIAN:gfx=&gInfoFrameGfxItalian;break;
 case LANGUAGE_SPANISH:gfx=&gInfoFrameGfxSpanish;break;
 default:gfx=&gInfoFrameGfxUnset;break;
 }
 LoadGraphicsBlock(gfx,tiles);gCur3DSpriteEngine=savedEngine;
}

/* Draw the selected terrain's banner: its graphic, the tileset-specific tiles
   and its localized name. */
void DrawTerrainInfoBanner(void *entry) {
    M2C_UNK LoadGraphicsBlock(M2C_UNK *, s32);
    void CopyToObjPaletteShadow(M2C_UNK, s32, s32);
    void func_0209b26c(s32, s32, s32, s32, s32, u16);
    s32 GetTerrainInfoContext();
    s32 GetTerrainGraphic(s32, s32);
    s32 func_ov000_02172478(s32, s32);
    s32 func_ov000_02172488(s32, s32);
    s32 func_ov000_02172498(s32, s32);
    s32 func_ov000_021724a8(s32, s32);
    s32 GetTerrainNameId(s32, s32);
    s32 context; void *savedEngine; s32 drawY; s32 palette;
    context = GetTerrainInfoContext();
    palette = M2C_FIELD(entry, s32 *, 0) ? 0xa3 : 0x103;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    drawY = M2C_FIELD(entry, s32 *, 0) ? M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x10) + 0x20 : M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x10) + 0xa40;
    if (GetTerrainGraphic(context, *M2C_FIELD(entry, s32 **, 0x18))) {
        LoadGraphicsBlock((M2C_UNK *)GetTerrainGraphic(context, *M2C_FIELD(entry, s32 **, 0x18)), drawY);
    } else {
        LoadGraphicsBlock(&data_ov000_021d841c, drawY);
    }
    if (GetTerrainGraphic(context, *M2C_FIELD(entry, s32 **, 0x18))) {
        switch (M2C_FIELD(M2C_FIELD(gCurrentMap, s32 *, 0) + 0x5000, u8 *, 0x157)) {
        case 0: case 5: case 7: case 8: case 9:
            CopyToObjPaletteShadow(func_ov000_02172478(context, *M2C_FIELD(entry, s32 **, 0x18)), 0x80, 0xc0); break;
        case 1:
            CopyToObjPaletteShadow(func_ov000_02172498(context, *M2C_FIELD(entry, s32 **, 0x18)), 0x80, 0xc0); break;
        case 2:
            CopyToObjPaletteShadow(func_ov000_021724a8(context, *M2C_FIELD(entry, s32 **, 0x18)), 0x80, 0xc0); break;
        case 3: case 4: case 6:
            CopyToObjPaletteShadow(func_ov000_02172488(context, *M2C_FIELD(entry, s32 **, 0x18)), 0x80, 0xc0); break;
        }
    } else {
        CopyToObjPaletteShadow((s32)&data_ov000_021b8f5c, 0x80, 0xc0);
    }
    func_0209b26c(2, 0xa, 1, GetTerrainNameId(context, *M2C_FIELD(entry, s32 **, 0x18)), 0xf000, (u16)palette);
    gCur3DSpriteEngine = savedEngine;
}

/* Draw the selected terrain's icon into the info window's tile layer 1: the
 * window flag picks the tile base (0x52 or 1) and the icon is drawn in palette
 * bank 4, but only when the terrain has an icon. */
void DrawTerrainInfoIcon(void *window) {
 M2C_UNK DrawTilemapBlock(s32,s32,u16,s32);
 s32 GetTerrainInfoContext(); s32 GetTerrainIcon(s32,s32);
 s32 tiles; void *saved; s32 context,icon; s32 tileBase;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
 context=GetTerrainInfoContext();
 tiles=M2C_FIELD(g3DSpriteEngineSub,s32 *,0x24);
 tileBase=M2C_FIELD(window,s32 *,0)?0x52:1;
 icon=GetTerrainIcon(context,*M2C_FIELD(window,s32 **,0x18));
 if(GetTerrainIcon(context,*M2C_FIELD(window,s32 **,0x18))) DrawTilemapBlock(icon,tiles+0xc4,(u16)tileBase,4);
 gCur3DSpriteEngine=saved;
}

void func_ov000_02172dc0(void *p){
M2C_UNK DrawTilemapBlock(s32,s32,u16,s32);
void *ctx,*saved;
if(M2C_FIELD(p,s32*,12)%4==0){
s32 *frames[6]={&data_ov000_021b976c,&data_ov000_021b9bec,&data_ov000_021bb06c,&data_ov000_021b9c6c,&data_ov000_021b99ec,&data_ov000_021bb1ec};
s32 **table=frames;
saved=gCur3DSpriteEngine;
ctx=g3DSpriteEngineSub;
gCur3DSpriteEngine=ctx;
{
s32 index=M2C_FIELD(p,s32*,12)/4;
s32 base=M2C_FIELD(g3DSpriteEngineSub,s32*,0x24);
DrawTilemapBlock((s32)table[index],base+0xc4,(u16)(M2C_FIELD(p,s32*,0)?0x52:1),4);
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
gCur3DSpriteEngine=saved;
}
M2C_FIELD(p,s32*,12)++;
if(24<=M2C_FIELD(p,s32*,12))M2C_FIELD(p,s32*,12)=0;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_02172e90(void *arg0) {
    M2C_UNK BlendRgb555_16(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u8 gArmyPaletteIndices[12];

    void *saved;
    u8 buf[6];
    register u8 *p;
    register u8 *bufptr;
    register s32 i;
    register s32 off;
    register s32 stride;
    void *rec;
    u8 mapByte;
    s32 rcd;
    s32 t;
    s32 counter;
    u8 r3v;
    u16 h;
    u8 *tab;
 
    *(PaletteIndices *)buf = *(PaletteIndices *)(gArmyPaletteIndices+6);

    *(s32 *)((s8 *)arg0 + 0x10) = *(s32 *)((s8 *)arg0 + 0x10) + 1;
    if (*(s32 *)((s8 *)arg0 + 0x10) > 0x80) {
        *(s32 *)((s8 *)arg0 + 0x10) = 0;
    }

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    bufptr=buf;
    stride=0x8c;
    i = 0;
    off = 0;
    do {
        rec = (void *)((i + 1) * stride + (s32)*gCurrentMap + 0x6000);
        rcd = *(s32 *)((s8 *)arg0 + 0x18) + 0x3c + off;
        mapByte = *(u8 *)((s8 *)rec + 0x7c1);
        tab = *(u8 * volatile *)((s8 *)gCur3DSpriteEngine + 0x30);
        p = tab + ((bufptr[mapByte] << 5)&~1);
        tab = *(u8 * volatile *)((s8 *)gCur3DSpriteEngine + 0x30);
        tab += ((bufptr[mapByte] << 5)&~1);

        if (*(u8 *)((s8 *)rcd + 0x34) != 0) {
            *(u16 *)((s8 *)p + 0x06) = (u16)BlendRgb555_16(*(u16*)(tab+0x1e), 0, 8, 8);
        } else {
            if (*(u8 *)((s8 *)rcd + 0x30) != 0) {
                counter = *(s32 *)((s8 *)arg0 + 0x10);
                t = counter % 32;
                if (t <= 0x10) {
                    r3v = (u8)((t >> 1) & 0xff);
                } else {
                    t = t - 0x10;
                    t = t >> 1;
                    r3v = (u8)((8 - t) & 0xff);
                }
            } else if (*(u8 *)((s8 *)rcd + 0x31) != 0) {
                counter = *(s32 *)((s8 *)arg0 + 0x10);
                if (counter <= 0x40) {
                    r3v = (u8)((counter >> 3) & 0xff);
                } else {
                    counter = counter - 0x40;
                    counter = counter >> 3;
                    r3v = (u8)((8 - counter) & 0xff);
                }
            } else {
                r3v = 0;
            }
            *(u16 *)((s8 *)p + 0x06) = (u16)BlendRgb555_16(*(u16 *)(tab+0x1e), 0xffff, (16 - r3v) & 0xff, r3v);
        }

        i = i + 1;
        off = off + 0x38;
    } while (i < 4);

    *(u8 *)((s8 *)gCur3DSpriteEngine + 0x46) =
        (u8)(*(u8 *)((s8 *)gCur3DSpriteEngine + 0x46) | 0x10);
    gCur3DSpriteEngine = saved;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov000_02173058(void *arg0) {
s32 GetTerrainInfoContext();s32 func_ov000_021724b8(s32,s32);s32 GetNameGraphicFile(s32);void MI_CpuCopy32(s32,s32,u32);
s32 base;void *saved;s32 index;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
index=func_ov000_021724b8(GetTerrainInfoContext(),*M2C_FIELD(arg0,s32 **,0x18));
base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x2880;
if(index!=-1)MI_CpuCopy32(GetNameGraphicFile(2)+(s16)index*0x4e0,base,0x4e0);
gCur3DSpriteEngine=saved;
}

#pragma opt_strength_reduction off
/* Draws one row per active player in the map info window: the player's army
 * emblem sprite (its table chosen by the info window's view) followed by the
 * player's army label element. */
void DrawPlayerArmyList(void *info) {
    M2C_UNK Clear3DSpriteLayer(s32);
    M2C_UNK DrawTilemapBlock(s32, s32, u16, s32);
    void FillFaceTileMap(u32, s32, s32, s32, u16, u16, u8);
    u32 GetInfoWindowLanguage();
    extern u8 gArmyPaletteIndices[12];
    extern u16 gPlayerLabelTiles[4];
    extern M2C_UNK gArmyIconSprite0, gArmyIconSprite1, gArmyIconSprite2, gArmyIconSprite3, gArmyIconSprite4, gArmyIconSprite5;

    void *saved;
    u8 paletteIndices[6];
    M2C_UNK *sprite;
    s32 player;
    s32 dst;
    M2C_UNK *playerState;
    s32 stateOff;
    s32 rowOff;
    s32 row;

    paletteIndices[0] = gArmyPaletteIndices[0];
    paletteIndices[1] = gArmyPaletteIndices[1];
    paletteIndices[2] = gArmyPaletteIndices[2];
    paletteIndices[3] = gArmyPaletteIndices[3];
    paletteIndices[4] = gArmyPaletteIndices[4];
    paletteIndices[5] = gArmyPaletteIndices[5];
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Clear3DSpriteLayer(0);
    player = 0;
    stateOff = 0;
    rowOff = 0;
    row = 2;
    do {
        playerState = (M2C_UNK *)((player + 1) * MAP_PLAYER_STRIDE + ((s32)*gCurrentMap + MAP_PLAYER_STATES));
        if (M2C_FIELD(M2C_FIELD(info, s32 *, 0x18) + stateOff, u8 *, 0x6f) != 0) {
            dst = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28) + 0xac + rowOff * 2;
            switch (GetInfoWindowLanguage()) {
            case 0: sprite = &gArmyIconSprite0; break;
            case 1: sprite = &gArmyIconSprite1; break;
            case 2: sprite = &gArmyIconSprite2; break;
            case 3: sprite = &gArmyIconSprite3; break;
            case 4: sprite = &gArmyIconSprite4; break;
            case 5: sprite = &gArmyIconSprite5; break;
            default: sprite = &gArmyIconSprite0; break;
            }
            DrawTilemapBlock((s32)sprite, dst, (u16)(M2C_FIELD(playerState, u8 *, PLAYER_REC_ARMY_STATE) << 5), paletteIndices[M2C_FIELD(playerState, u8 *, PLAYER_REC_ARMY_INDEX)]);
            FillFaceTileMap(0, 0x1a, row, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), gPlayerLabelTiles[player], (u16)player, 0);
            rowOff += 0xa0;
            row += 5;
        }
        stateOff += 0x38;
        player++;
    } while (player < 4);
    gCur3DSpriteEngine = saved;
}
#pragma opt_strength_reduction reset
void func_ov000_02173290(void *arg0) {
     void DrawTerrainInfoBanner(void *);
 void func_ov000_02173058();
 func_ov000_02173058();
    if (M2C_FIELD(arg0, u8 *, 0x15) != 0) {
        return;
    }
    DrawTerrainInfoBanner(arg0);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (1 - M2C_FIELD(arg0, s32 *, 0));
}

/* Draws the map info window on the lower screen: first the window frame, then
 * either the selected terrain's icon or the map overview (cleared preview area,
 * terrain preview centred with its name drawn below), then one row per player. */
void DrawMapInfoWindow(void *window) {
    void ClearTileRect(M2C_UNK, s32, s32);
    s32 DrawTextLine(s32, s32, s32, s32, s32, s32);
    void DrawMapPreview(M2C_UNK, M2C_UNK, s32, s32);
    void SetFrameRect(s32, s32, s32, s32);
    s32 GetCurrentMapName(void);
    void DrawInfoWindowFrame(void *);
    void DrawTerrainInfoIcon(void *);
    void DrawPlayerArmyList(void *);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern void **gCurrentMap;

    void *savedEngine;
    void **map;
    s32 previewWidth;
    s32 previewHeight;
    u32 left;
    u32 top;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    M2C_FIELD(M2C_FIELD(g3DSpriteEngineSub, void **, 0), s16 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x40) = 0;
    DrawInfoWindowFrame(window);
    if (M2C_FIELD(window, u8 *, 0x15) == 0) {
        DrawTerrainInfoIcon(window);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    } else {
        ClearTileRect(M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x28) + 0x80, 0x18, 0x14);
        map = *gCurrentMap;
        previewWidth = M2C_FIELD(map, u16 *, MAP_WIDTH) * 4;
        previewHeight = M2C_FIELD(map, u16 *, MAP_HEIGHT) * 4;
        left = 0x58 - (previewWidth / 2);
        top = 0x60 - (previewHeight / 2);
        DrawMapPreview(M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x10), M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x24), 1, 10);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = (s16) (0 - left);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = (s16) (0 - top);
        SetFrameRect(left, top, 0x60, 7);
        DrawTextLine(1, 2, 2, GetCurrentMapName(), 0xF000, 0x340);
    }
    DrawPlayerArmyList(window);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = savedEngine;
}

