/* 21 functions from 0x02077624 to 0x020785B0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "gx.h"

static inline s32 MapCellIndex(s32 x,s32 y) { extern s32 *gCurrentMap; return x+M2C_FIELD(*gCurrentMap+y*2,u16 *,MAP_ROW_OFFSETS); }
static inline u8 BaseCellCode(s8 elev) { return elev>=0 ? 2:0; }
static inline u8 mapByte020778cc(s32 map,u32 index) { return M2C_FIELD(map+index,u8 *,0x1420); }
static inline u8 mapFog020778cc(u8 *bits,u32 index) { return bits[index>>3] & (1<<(index&7)); }
static inline u8 *mapBits020778cc(u8 *dims) { return dims+0xe1; }
static inline u32 tileFlags020778cc(u16 tile) {
 extern u32 gTerrainClassFlags[][2];
 return gTerrainClassFlags[tile][0] & 0x7fff0000;
}

typedef struct Unk0207Color3 { u32 words[3]; } Unk0207Color3;
extern const Unk0207Color3 data_020eb1b4;
extern const Unk0207Color3 data_020eb1a8;
extern void *gCur3DSpriteEngine;
s16 GetViewZoom(void *);
s32 EaseInterpolate(s32, s32, s32, s32, s32);
void BuildMapViewProjection(s32, void *, void *);

/* Recomputes the GX toon table every frame: each RGB555 entry is interpolated
 * between two reference tables with a 64-frame ping-pong phase taken from
 * gFrameCounter (dim -> bright over the first half, back again over the second),
 * then the table is uploaded. */
void UpdateToonTableBlend(void) {
    M2C_UNK GX_LoadToonTable();
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    extern u32 gFrameCounter;
    extern const u16 gToonTableDim[];
    extern const u16 gToonTableBright[];
    extern u16 gToonTable[];
    s32 i;
    s32 phase;
    const u16 *from;
    const u16 *to;
    s32 packedFrom;
    s32 packedTo;
    s32 red;
    s32 green;
    s32 blue;

    i = 0;
    phase = gFrameCounter & 0x3F;
    if (phase < 0x20) {
        from = gToonTableDim;
        to = gToonTableBright;
    } else {
        from = gToonTableBright;
        to = gToonTableDim;
        phase -= 0x20;
    }
    do {
        packedFrom = from[i];
        packedTo = to[i];
        red = EaseInterpolate(0, packedFrom & GX_RGB_CHANNEL_MASK, packedTo & GX_RGB_CHANNEL_MASK, phase, 0x20);
        green = EaseInterpolate(0, (packedFrom & GX_RGB_GREEN_MASK) >> GX_RGB_GREEN_SHIFT, (packedTo & GX_RGB_GREEN_MASK) >> GX_RGB_GREEN_SHIFT, phase, 0x20);
        blue = EaseInterpolate(0, (packedFrom & GX_RGB_BLUE_MASK) >> GX_RGB_BLUE_SHIFT, (packedTo & GX_RGB_BLUE_MASK) >> GX_RGB_BLUE_SHIFT, phase, 0x20);
        gToonTable[i] = red | (green << GX_RGB_GREEN_SHIFT) | (blue << GX_RGB_BLUE_SHIFT);
        i++;
    } while (i < 0x20);
    GX_LoadToonTable();
}

/* Animation step used for a map sprite's control word (+0x40): the base step
 * 0x20000 divided by the map view's current speed factor, the count at
 * gMapHighlightState + 0x18 (0x60000 is three times the base step). */
s32 GetFrameStep(void) {
    M2C_UNK FX_Div(M2C_UNK, s32);
    extern M2C_UNK gMapHighlightState;
    return FX_Div(0x60000, M2C_FIELD(&gMapHighlightState, s32 *, 0x18) * 3);
}

/* Set the battle map's material on the geometry engine: white diffuse (taken
 * from the vertex colour) and ambient, a dim grey specular and white emission. */
void SetMapViewMaterial(void) {
    *(volatile u32 *)0x40004c0 = GX_DEFAULT_MATERIAL_DIF_AMB;
    *(volatile u32 *)0x40004c4 = GX_MAP_VIEW_MATERIAL_SPE_EMI;
}

#pragma opt_propagation off
#pragma opt_cond_exec off
#pragma opt_common_subs off
void func_02077740(void){
extern s32 *gCurrentMap;
s32 *base;u16 w,h;s32 mode,tx,ty,z=0,x=0,y=0;
u16 a,b,c,d,e;
base=(s32*)*gCurrentMap;h=M2C_FIELD(base,u16*,0x5146);w=M2C_FIELD(base,u16*,0x5144);
ty=h*3;tx=w*3;tx<<=8;ty<<=8;
mode=GetViewZoom((u8*)base+0x6ef8);if(mode<=0)mode=16;else mode=24;
switch(mode){case 16:*(volatile u32*)0x40004a8=0x6c9364a4;x=w<<16;y=h<<16;z=0;break;
case 24:*(volatile u32*)0x40004a8=0x6d2364b4;x=w<<17;y=h<<17;z=0;break;}
a=(u16)(s16)(z>>8);b=(u16)(s16)(y>>8);c=(u16)(s16)ty;d=(u16)(s16)(x>>8);e=(u16)(s16)tx;
*(volatile u32*)0x40004ac=0x152;*(volatile u32*)0x40004a4=0x3080080;*(volatile u32*)0x4000480=0x7fff;*(volatile u32*)0x4000500=1;
*(volatile u32*)0x4000488=a|((u32)a<<16);*(volatile u32*)0x400048c=0;*(volatile u32*)0x400048c=0x420;
*(volatile u32*)0x4000488=a|((u32)b<<16);*(volatile u32*)0x400048c=(u32)c<<16;*(volatile u32*)0x400048c=0x420;
*(volatile u32*)0x4000488=d|((u32)b<<16);*(volatile u32*)0x400048c=e|((u32)c<<16);*(volatile u32*)0x400048c=0x420;
*(volatile u32*)0x4000488=d|((u32)a<<16);*(volatile u32*)0x400048c=e;*(volatile u32*)0x400048c=0x420;
*(volatile u32*)0x4000504=0;
}
#pragma opt_propagation reset
#pragma opt_cond_exec reset
#pragma opt_common_subs reset
#pragma push
void func_020778cc(s32 left,s32 top,s32 right,s32 bottom) {
 void Map_SubmitTerrainQuads(s32,s32,s32,s32,u8,u8,u8,u8);
 extern s32 *gCurrentMap;
 extern u8 gMapCellCodes[];
 extern u8 gMapCellCornerA[3840];
 extern u32 gTerrainClassFlags[][2];
 extern u8 gMapCellShades[];
 s32 x,y;
 u32 flags;
 s32 base;
 s32 index;
 u8 *bits;
 u8 *dims;
 u8 fog; s32 terrain,a,b;
 *(volatile u32 *)0x04000444=0;
 *(volatile u32 *)0x04000470=0;
 *(volatile u32 *)0x04000470=0;
 *(volatile u32 *)0x04000470=-16;
 for(y=top;y<=bottom;y++) {
 for(x=left;x<=right;x++) {
 if(x>=0 && y>=0) {
 base=*gCurrentMap;
 dims=(u8 *)base+0x5120;
 if(x<M2C_FIELD(dims,u16 *,0x24) && y<M2C_FIELD(dims,u16 *,0x26)) {
 flags=tileFlags020778cc(((u16 (*)[40])gMapCellCornerA)[x][y]);
 if(flags&0x20000) {
 bits=mapBits020778cc(dims);
 index=x+M2C_FIELD(base+y*2,u16 *,0x3758);
 fog=mapFog020778cc(bits,index);
 terrain=mapByte020778cc(base,index);
 a=(gMapCellCodes+x*40)[y];
 b=(gMapCellShades+x*40)[y];
 Map_SubmitTerrainQuads(x,y,0xac,0,terrain,fog,a,b);
 }
 }
 }
 }
 }
 *(volatile u32 *)0x04000448=1;
}
#pragma pop
/* Switch the 3D engine's fog off: GX_SetFog clears DISP3DCNT's fog enable,
 * blend and density bits. */
void GX_DisableFog(void) {
    M2C_UNK GX_SetFog(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    GX_SetFog(0, 0, 0, 0);
}

/* Restore the battle map view's default lighting: no polygon-attribute tint on the
 * map's quads and a white light shining straight along +Z. */
void SetMapViewDefaultLight(void) {
    extern M2C_UNK gMapHighlightState;
    M2C_FIELD(&gMapHighlightState, s32 *, MAP_VIEW_POLY_ATTR) = 0;
    REG_GX_LIGHT_VECTOR = GX_MAP_VIEW_LIGHT_VECTOR;
    REG_GX_LIGHT_COLOR = GX_DEFAULT_LIGHT_COLOR;
}

/* Bring the battle map's presentation back up: begin the frame, reset the map's
 * default light and the raised-cells timer, load the map's texture and animation
 * data, then reset the view camera (inside the map, at *gCurrentMap +
 * MAP_VIEW_ZOOM) and the standalone default camera. */
void InitBattleMapGraphics(void) {
    void Map_BeginFrame(void);
    void SetMapViewDefaultLight(void);
    void func_02077eb8(void);
    void func_02077ebc(void);
    void ResetMapViewCamera(void *);
    void InitDefaultMapCamera(void);
    void ResetMapViewRaiseTimer(void);
    extern s32 *gCurrentMap;

    Map_BeginFrame();
    SetMapViewDefaultLight();
    func_02077eb8();
    func_02077ebc();
    ResetMapViewCamera((void *)(*gCurrentMap + MAP_VIEW_ZOOM));
    InitDefaultMapCamera();
    ResetMapViewRaiseTimer();
}

/* Interpolate two constant backdrop colors by blend factor t and store the resulting RGB plus engine viewport dimensions into gMapViewProjection. */
M2C_UNK func_02077ab8(s32 arg0) {
    extern M2C_UNK gMapViewProjection;
    Unk0207Color3 colorTop = data_020eb1b4;
    Unk0207Color3 colorBottom = data_020eb1a8;
    s32 t = GetViewZoom((void *)arg0);
    s32 colors[3];
    s32 dims[3];
    void *engine;

    colors[0] = EaseInterpolate(0, colorTop.words[0], colorBottom.words[0], t, 0x80);
    colors[1] = EaseInterpolate(0, colorTop.words[1], colorBottom.words[1], t, 0x80);
    colors[2] = EaseInterpolate(0, colorTop.words[2], colorBottom.words[2], t, 0x80);
    engine = gCur3DSpriteEngine;
    dims[0] = (M2C_FIELD(engine, s16 *, 0x3C) + M2C_FIELD(engine, s16 *, 0x40)) * 0x30;
    dims[1] = (M2C_FIELD(engine, s16 *, 0x3E) + M2C_FIELD(engine, s16 *, 0x42)) * 0x30;
    dims[2] = 0;
    BuildMapViewProjection((s32)&gMapViewProjection, colors, dims);
}

/* Multiply the map view's camera matrices into the GX projection stack: select the
 * projection matrix, multiply in the view's projection, then multiply in the 4x4
 * form of the view's affine 3x4 eye matrix at view+0x1C, and finish on the identity. */
void ApplyMapViewProjection(s32 view) {
    void GX_MultMatrix4x4(void *);
    void Matrix3x4To4x4(s32, void *);
    extern M2C_UNK gMapViewProjection;
    u8 eyeMatrix[64];

    REG_GX_MTX_MODE = 0;
    REG_GX_MTX_IDENTITY = 0;
    GX_MultMatrix4x4(&gMapViewProjection);
    Matrix3x4To4x4(view + 28, eyeMatrix);
    GX_MultMatrix4x4(eyeMatrix);
    REG_GX_MTX_MODE = 2;
    REG_GX_MTX_IDENTITY = 0;
}

/* Bring up the current map view for the frame: set the backdrop colour, rebuild
 * the view projection for its zoom, update the eye position and the view
 * transform, then load the view's projection onto the GX matrix stack.  The view
 * block sits at *gCurrentMap + MAP_VIEW_ZOOM (0x2F8 + 0x6C00). */
void UpdateMapView(void) {
    M2C_UNK func_02077ab8(s32);
    void ApplyMapViewProjection(s32);
    M2C_UNK BuildMapViewTransform(s32);
    M2C_UNK BuildMapViewScreenTransform(s32, M2C_UNK *);
    M2C_UNK UpdateMapViewEyeVeneer(s32);
    M2C_UNK SetGxViewport(M2C_UNK);
    extern M2C_UNK gMapViewProjection;
    extern s32 *gCurrentMap;
    s32 view;

    view = *gCurrentMap + 0x2F8;
    SetGxViewport(0);
    func_02077ab8(view + 0x6C00);
    UpdateMapViewEyeVeneer(view + 0x6C00);
    BuildMapViewTransform(view + 0x6C00);
    BuildMapViewScreenTransform(view + 0x6C00, &gMapViewProjection);
    ApplyMapViewProjection(view + 0x6C00);
}

void func_02077c64(void) {
    M2C_UNK G3X_Reset();
    void SetMapViewMaterial();
    M2C_UNK func_02078828();
    G3X_Reset();
    func_02078828();
    SetMapViewMaterial();
}

void func_02077c78(void) {
    *(s32 *)0x04000540 = 0;
}

/* Set up a map frame: configure the 3D sprite bank's layer modes, let the active map view claim
 * its VRAM banks, program the main screen and 3D registers and load the current toon table. */
void Map_BeginFrame(void) {
    void G3X_Init(void);
    void GX_RestoreMatrixStack(void);
    M2C_UNK GX_SetClearColor(s32, s32, s16, s32, s32);
    M2C_UNK GX_LoadToonTable(M2C_UNK);
    void GX_DisableFog(void);
    extern u32 g3DSpriteBankMain;
    extern void *gCur3DSpriteEngine;
    extern s32 *gCurrentMap;
    extern u16 gToonTable[];

    u8 *spriteBank;
    u16 *bank;
    u8 *disp;
    u32 dispcnt;

    spriteBank = (u8 *)g3DSpriteBankMain;
    *(u32 *)(spriteBank + 0x34) = 1;
    {u16 * volatile flags=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags=*flags & ~7;}
    *(u16 *)g3DSpriteBankMain |=8;
    {u16 * volatile flags1=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags1=*flags1|16;}
    {u16 * volatile flags2=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags2=*flags2|32;}
    {u16 * volatile flags3=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags3=*flags3|64;}
    {u16 * volatile flags4=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags4=*flags4|128;}
    {u16 * volatile flags5=(u16 *)*(u32 *)gCur3DSpriteEngine;*flags5=*flags5|256;}
    bank=(u16 *)*(u32 *)gCur3DSpriteEngine;bank[3]=(bank[3] & ~3)|3;
    bank=(u16 *)*(u32 *)gCur3DSpriteEngine;bank[4]=(bank[4] & ~3);
    bank=(u16 *)*(u32 *)gCur3DSpriteEngine;bank[5]=(bank[5] & ~3);
    bank=(u16 *)*(u32 *)gCur3DSpriteEngine;bank[6]=(bank[6] & ~3);
    G3X_Init();
    GX_RestoreMatrixStack();

    {
        void **viewSlot = (void **)((u8 *)gCurrentMap + 4);
        void *mapView = *viewSlot;
        void (**cbSlot)(void) = (void (**)(void))((u8 *)mapView + 0x4c);
        void (*beginView)(void) = *cbSlot;
        if (beginView != 0) {
            beginView();
        }
    }

    disp = (u8 *)0x4000000;                  /* DISPCNT */
    dispcnt = *(u32 *)disp;
    dispcnt = (dispcnt & ~0x1f00) | 0x1100;  /* main-engine VRAM banks */
    *(u32 *)disp = dispcnt;
    bank = (u16 *)disp;
    bank[4] = bank[4] & ~3;                  /* BG0CNT priority */
    bank[0x30] = bank[0x30] & (u16)0xcfef;   /* DISP3DCNT */
    bank[0x30] = (bank[0x30] & ~0x3000) | 8;
    bank[0x28] = 0;                          /* BLDCNT: no blending */
    GX_SetClearColor(0, 0x1f, (s16)0x7fff, 0x3f, 0);

    {
        u16 *disp3d=(u16 *)0x4000060;
        *(volatile u32 *)0x4000580=0xbfff0000;
        *disp3d=(*disp3d & 0xffffcffd)|2;
        GX_LoadToonTable((M2C_UNK)gToonTable);
        GX_DisableFog();
        *(u32 *)0x4000540=0;                 /* SWAP_BUFFERS: no buffer swap */
    }
}

void func_02077eb8(void) {

}

/* Loads and prepares the animation/texture data tables used at startup. */
void func_02077ebc(void) {
    M2C_UNK GX_BeginLoadTex();
    M2C_UNK LoadTextureBankBlock(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK GX_EndLoadTex();
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToTextureBank(M2C_UNK *, s32);
    M2C_UNK LoadFileToObjExtPalette(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileToObjExtPalette(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_0208168c(M2C_UNK *, s32);
    M2C_UNK *GetLocalizedFileName(M2C_UNK *);
    extern M2C_UNK data_02100ad8;
    extern M2C_UNK data_02100ae4;
    extern M2C_UNK data_02100af0;
    extern M2C_UNK data_02100afc;
    extern M2C_UNK data_02100b0c;
    extern M2C_UNK data_02100b1c;
    extern M2C_UNK data_02100b28;
    extern M2C_UNK data_02100b3c;
    extern M2C_UNK data_02100b50;
    extern M2C_UNK data_02100b60;
    extern M2C_UNK data_02100b70;
    extern M2C_UNK data_02100b7c;
    extern M2C_UNK data_02100b88;
    extern M2C_UNK data_02100b94;
    extern M2C_UNK data_02100b9c;
    extern M2C_UNK data_02100ba4;
    extern M2C_UNK data_02144cbc;
    s32 i;
    s32 j;

    GX_BeginLoadTex();
    i = 0;
    do {
        LoadTextureBankBlock(&data_02144cbc, i + 0x329A0, 0x20);
        i += 0x20;
    } while (i < 0xD660);
    j = 0;
    do {
        LoadTextureBankBlock(&data_02144cbc, j + 0x30D20, 0x20);
        j += 0x20;
    } while (j < 0x1800);
    GX_EndLoadTex();
    SetFileDirectory(&data_02100ad8);
    LoadFileToTextureBank(&data_02100ae4, 0x24D20);
    LoadFileToObjExtPalette(&data_02100af0, 0x1200, 0x200);
    LoadFileToTextureBank(GetLocalizedFileName(&data_02100afc), 0x20000);
    LoadFileToObjExtPalette(&data_02100b0c, 0x1400, 0x40);
    OpenNarcArchive(&data_02100b1c);
    func_0208168c(&data_02100b28, 0x22F20);
    LoadNarcFileToObjExtPalette(&data_02100b3c, 0x1460, 0x40);
    func_0208168c(&data_02100b50, 0x21000);
    func_0208168c(&data_02100b60, 0x21980);
    LoadNarcFileToObjExtPalette(&data_02100b70, 0x1440, 0x20);
    func_0208168c(&data_02100b7c, 0x32520);
    func_0208168c(&data_02100b88, 0x325A0);
    LoadNarcFileToObjExtPalette(&data_02100b94, 0x1520, 0x20);
    func_0208168c(&data_02100b9c, 0x327A0);
    LoadNarcFileToObjExtPalette(&data_02100ba4, 0x1540, 0x20);
    CloseNarcArchive();
}

#pragma push
#pragma optimization_level 2
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Rebuild the current player's movement-range overlay: clear the per-cell flags,
 * then mark every cell inside the selected unit's move range.  Leaves the flags
 * cleared when the player has no selected unit, while their CO power is active,
 * or when the unit's own cell is hidden by fog. */
void BuildMoveRangeFlags(void)
{
    void MI_CpuFill32(u32, void *, u32);
    u8 *GetPlayerSelectedUnit(s32);
    s32 GetPlayerArmyVariantIfSet(s32);
    s32 GetMoveRangeCommanderId(s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 gMapMoveRangeFlags[];
    s32 x, y;
    s32 base = *gCurrentMap;
    u8 *dimensions = (u8 *)base + 0x5120;
    s32 player = M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER);
    s32 width = M2C_FIELD(dimensions, u16 *, 0x24);
    s32 height = M2C_FIELD(dimensions, u16 *, 0x26);
    BattleMapUnit *unit;

    MI_CpuFill32(0, gMapMoveRangeFlags, 0x780);
    unit = (BattleMapUnit *)GetPlayerSelectedUnit(player);
    if (unit == 0 || GetPlayerArmyVariantIfSet(player)) {
        return;
    }
    base = *gCurrentMap;
    dimensions = (u8 *)base + 0x5120;
    if (!mapFog020778cc(mapBits020778cc(dimensions), MapCellIndex(unit->x, unit->y))) {
        return;
    }
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            if (GetMoveRangeCommanderId(player, x, y) != -1) {
                (gMapMoveRangeFlags + x * 40)[y] = 1;
            }
        }
    }
}
#pragma pop

#pragma optimization_level 2
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Fills the per-cell display code buffer gMapCellCodes for the visible viewport,
 * clamped to the map: 2 for land, 3 for high ground (elevation >= 0x40), 1 for a
 * highlighted cell (a bridge/pipe terrain kind or the cursor) and 0 elsewhere. */
void BuildMapCellCodes(s32 x0, s32 y0, s32 x1, s32 y1) {
    u8 IsTouchCursorActive(void);
    s32 IsOrderEffectHighlightActive(void);
    u8 IsCellInOrderEffectArea(s32, s32);
    extern s32 *gCurrentMap;
    extern u8 gMapCellCodes[];
    extern M2C_UNK gMapHighlightState;
    u8 *viewRect;
    u16 mapWidth;
    u16 mapHeight;
    s32 x;
    u8 highlightCursor;
    s32 y;

    viewRect = (u8 *)*gCurrentMap + 0x120;
    mapWidth = M2C_FIELD(viewRect,u16 *,0x5024);
    mapHeight = M2C_FIELD(viewRect,u16 *,0x5026);
    highlightCursor = IsTouchCursorActive();
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 > mapWidth - 1) x1 = mapWidth - 1;
    if (y1 > mapHeight - 1) y1 = mapHeight - 1;

    if (IsOrderEffectHighlightActive()) {
    for (y = y0; y <= y1; y++) {
        for (x = x0; x <= x1; x++) {
            u16 rowVal;
            s32 cell;
            u8 tile;
            u8 code;
            s8 elev;

            rowVal = *(u16 *)((u8 *)*gCurrentMap + MAP_ROW_OFFSETS + y * 2);
            cell = x + rowVal;
            tile = *((u8 *)*gCurrentMap + MAP_CELL_TERRAIN + cell);
            elev = (s8)*((u8 *)*gCurrentMap + MAP_CELL_ORDER + cell);
            code = BaseCellCode(elev);
            elev = *(s8 *)((u8 *)*gCurrentMap + MAP_CELL_ORDER + MapCellIndex(x,y));
            if (elev >= 0x40) code = 3;

            if ((tile & MAP_TERRAIN_KIND_MASK) == 0x1D &&
                *(s32 *)(((u8 *)&gMapHighlightState) + 0xC) != 0 &&
                IsCellInOrderEffectArea(x, y) != 0) {
                code = 1;
            }

            if (highlightCursor) {
                if (*(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_TARGET_X) == x &&
                    *(s16 *)((u8 *)*gCurrentMap + MAP_CURSOR_TARGET_Y) == y) {
                    code = 1;
                }
            }

            (gMapCellCodes+x * 0x28)[y] = code;
        }
    }
    } else {
    for (y = y0; y <= y1; y++) {
            for (x = x0; x <= x1; x++) {
                (gMapCellCodes+x * 0x28)[y] = 0;
            }
        }
    }
}
typedef struct MapOverlayPalette {
    u8 shades[32];
} MapOverlayPalette;

#pragma opt_strength_reduction off
/* Fills the per-cell shade map for the visible rectangle, clamped to the map:
 * cells flagged as inside the selected unit's movement range get the current
 * value of the pulsing movement-range shade ramp, the rest shade 0. */
void BuildMapCellShades(s32 x0, s32 y0, s32 x1, s32 y1) {
    extern s32 *gCurrentMap;
    extern u8 gMapMoveRangeFlags[];
    extern u8 gMapCellShades[];
    extern u32 gFrameCounter;
    extern const MapOverlayPalette gMoveRangeShadeRamp;
    MapOverlayPalette palette;
    u8 *viewRect = (u8 *)*gCurrentMap + 0x120;
    u16 mapWidth = M2C_FIELD(viewRect, u16 *, 0x5024);
    u16 mapHeight = M2C_FIELD(viewRect, u16 *, 0x5026);
    s32 x;
    u8 shade;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 > mapWidth - 1) x1 = mapWidth - 1;
    if (y1 > mapHeight - 1) y1 = mapHeight - 1;

    while (y0 <= y1) {
        x = x0;
        while (x <= x1) {
            shade = 0;
            if ((gMapMoveRangeFlags + x * 40)[y0] != 0) {
                palette = gMoveRangeShadeRamp;
                shade = palette.shades[(*(volatile u32 *)&gFrameCounter >> 2) & 31];
            }
            (gMapCellShades + x * 40)[y0] = shade;
            x++;
        }
        y0++;
    }
}
#pragma opt_strength_reduction off
void func_0207843c(s32 x0,s32 y0,s32 x1,s32 y1){
s32 func_0207e52c(s32,s32);s32 GetTerrainClassVariant(s32,s32,u16);
extern s32 *gCurrentMap;extern u8 gMapCellCornerA[3840],gMapCellCornerB[3840];
u8 *base=*(u8**)gCurrentMap;u8 *sub=base+0x120;s32 off;u16 *p; s32 a,x,y,w,h,b;u16 *q;
w=M2C_FIELD(sub,u16*,0x5024);h=M2C_FIELD(sub,u16*,0x5026);
if(x0<0)x0=0;if(y0<0)y0=0;if(x1>w-1)x1=w-1;if(y1>h-1)y1=h-1;
p=(u16*)gMapCellCornerA;y=y0;goto outercheck;outer: off=y*2;x=x0;goto innercheck;inner:
a=func_0207e52c(x,y);b=GetTerrainClassVariant(x,y,(u16)a);
M2C_FIELD((u8*)p+x*80,u16*,off)=a;
M2C_FIELD(gMapCellCornerB+x*80,u16*,off)=b;
x++;innercheck:if(x<=x1)goto inner;
y++;outercheck:if(y<=y1)goto outer;
}
/* Chooses the height the wave-animated map cells are raised by: the frame
 * counter picks a point in a weighted table of heights, and the matching entry
 * of the height-step table is stored in the map view's wave-height field. */
void UpdateMapWaveHeight(void) {
    u64 U32DivideRem(u32, u32);
    extern u8 gWaveHeightWeights[32], gWaveHeightSteps[32];
    extern u32 gFrameCounter;
    extern M2C_UNK gMapHighlightState;
    s32 total;
    s32 index;
    s32 accumulated;
    u8 *weights;
    s32 i;
    u64 division;
    s32 remainder;

    total = 0;
    accumulated = 0;
    index = 0;
    i = 0;
    weights = gWaveHeightWeights;
    do {
        total += *weights++;
        i++;
    } while (i < 30);
    division = U32DivideRem(gFrameCounter, total);
    remainder = division >> 32;
    {
        u8 *weight = gWaveHeightWeights;
        s32 j = 0;
        do {
            accumulated += *weight;
            if (accumulated > remainder) {
                index = j;
                break;
            }
            j++;
            weight++;
        } while (j < 30);
    }
    M2C_FIELD(&gMapHighlightState, u8 *, MAP_VIEW_WAVE_HEIGHT) = gWaveHeightSteps[index];
}

