/* 10 functions from 0x020785B0 to 0x020793F0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "gx.h"
#include "ds3dsprite.h"
#include "sound.h"
static inline s32 ClampRenderCoord(s32 v, u16 *dims, s32 axis) {
 s32 max=dims[axis]-1;
 if(v>max)return max;
 if(v<0)v=0;
 return v;
}
typedef struct { u8 x,y; u16 dx:3,dy:3,kind:4,unused:4,angle:2; u8 value; } MapRenderEntry;

typedef struct { s32 x,y,z; } Vec3;
typedef struct { u8 kind:6; u8 side:2; u8 pad[5]; u16 hp:7; u16 rest:9; } RenderUnit;
typedef struct { Vec3 pos; void *unit; s32 kind,frame,variant,side,hp,flags; u8 color; u8 pad[3]; s32 extra; u8 mode; u8 pad2[3]; } UnitRenderContext;
extern u8 gMapCellCodes[1920], gMapCellShades[1920];
extern s16 gSinCosTable[2048];
extern u32 gTerrainClassFlags[][2];

extern u32 gFrameCounter;
extern u8 gMapHighlightState[24];

/* Decides each frame whether property cells are drawn in their owner's palette
 * band: only in the zoomed-in view, and only for the last 80 frames of every
 * 140-frame pulse. */
void Map_UpdateOwnerColorBands(void) {
    s32 GetViewZoom(s32);
    extern s32 *gCurrentMap;
    s32 cellSize;
    if ((s32)(gFrameCounter % MAP_VIEW_OWNER_BAND_CYCLE) < MAP_VIEW_OWNER_BAND_DELAY) {
        gMapHighlightState[MAP_VIEW_OWNER_BANDS] = 0;
    } else {
        gMapHighlightState[MAP_VIEW_OWNER_BANDS] = 1;
    }
    if (GetViewZoom(*gCurrentMap + MAP_VIEW_ZOOM) <= 0) {
        cellSize = MAP_SPRITE_ZOOM_SMALL;
    } else {
        cellSize = MAP_SPRITE_ZOOM_LARGE;
    }
    if (cellSize == MAP_SPRITE_ZOOM_SMALL) {
        gMapHighlightState[MAP_VIEW_OWNER_BANDS] = 0;
    }
}

/* Advance the highlighted unit's flash colour index: the unit cycles through its
 * four flash colours (MAP_VIEW_FLASH_COLORS), one step every 12 frames. */
void Map_UpdateUnitFlashFrame(void) {
    gMapHighlightState[MAP_VIEW_FLASH_FRAME] = (gFrameCounter / 12) & 3;
}

#pragma scheduling on
/* Draw the tileset's four-colour background quad, then restore the map projection. */
void DrawMapBackground(void) {
    void GX_SetOrthoProjection(s32, s32, s32, s32, s32, s32, s32, s32, s32);
    void ApplyMapViewProjection(s32);
    extern s32 *gCurrentMap;
    extern u16 gMapBackgroundCornerColors[][4];
    u32 tileset = M2C_FIELD(*gCurrentMap, u8 *, MAP_TILESET);
    u16 *cornerColors = gMapBackgroundCornerColors[tileset];
    REG_GX_MTX_MODE = 0;
    REG_GX_MTX_IDENTITY = 0;
    GX_SetOrthoProjection(0, 192, 0, 256, -1000, 0, 4096, 1, 0);
    REG_GX_BEGIN_VTXS = GX_PRIM_QUADS;
    REG_GX_COLOR = cornerColors[0];
    REG_GX_VTX_16 = 0; REG_GX_VTX_16 = 0;
    REG_GX_COLOR = cornerColors[1];
    REG_GX_VTX_16 = 0xC00000; REG_GX_VTX_16 = 0;
    REG_GX_COLOR = cornerColors[2];
    REG_GX_VTX_16 = 0xC00100; REG_GX_VTX_16 = 0;
    REG_GX_COLOR = cornerColors[3];
    REG_GX_VTX_16 = 0x100; REG_GX_VTX_16 = 0;
    REG_GX_END_VTXS = 0;
    ApplyMapViewProjection(*gCurrentMap + MAP_VIEW_ZOOM);
    REG_GX_COLOR = GX_RGB_WHITE;
}

/* Sets one of the map ambience loops (a scripted sound slot) to a volume derived
 * from how many of its cells are on screen: the count is scaled by the view zoom
 * and eased into 0..SOUND_VOLUME_MAX, then the loop is started at that volume.
 * A zero count leaves the slot silent. */
void SetAmbienceSoundVolume(s32 slot, s32 soundId, s32 cellCount) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 GetViewZoom(s32);
    M2C_UNK PlaySlotScriptedSound(s32, s32, s32);
    M2C_UNK PlaySlotScriptedSoundAtVolume(s32, s32, s32, s32);
    extern s32 *gCurrentMap;
    s32 zoom;
    s32 volume;
    s32 count;

    count = cellCount;
    zoom = GetViewZoom(*gCurrentMap + MAP_VIEW_ZOOM);
    volume = 0;
    if (count != 0) {
        if (count < 8) {
            count = 8;
        }
        volume = EaseInterpolate(EASE_LINEAR, 0, SOUND_VOLUME_MAX, count * zoom, 0x1000);
        if (volume > SOUND_VOLUME_MAX) {
            volume = SOUND_VOLUME_MAX;
        } else if (volume < 0) {
            volume = 0;
        }
    }
    if (PlaySlotScriptedSound(slot, volume, 0xA) != 0) {
        return;
    }
    if (volume == 0) {
        return;
    }
    PlaySlotScriptedSoundAtVolume(slot, -1, soundId, volume);
}

#pragma push
#pragma opt_strength_reduction off
void DrawMapEffectEntry(void*);
void RenderUnitAt(s32,s32,s32,u8);
void Map_SubmitTerrainQuads(s32,s32,s32,s32,s32,s32,s32,s32);
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma scheduling off
void func_02078828(void) {
extern s32 *gCurrentMap;
extern u16 gMapCellCornerA[],gMapCellCornerB[];
void ScreenToMapFixedPoint(s32,s32,Vec3*);
s32 Divide(s32,s32);
s32 rawx,rawy,rawx1,rawy1;
s32 i,y,x,x1,mode,x0,y0,y1;
u32 counts[32];
Vec3 pos;
s32 base,tile,visible,v1,v2;
u16 a,b;
u32 index;
mode=M2C_FIELD(*gCurrentMap,u16*,0x52b4)==10?1:0;
UpdateToonTableBlend();SetMapViewDefaultLight();DrawMapBackground();
*(volatile u32*)0x4000444=0;
*(volatile u32*)0x4000440=3;
*(volatile u32*)0x4000454=0;
*(volatile u32*)0x4000440=2;
*(volatile u32*)0x4000454=0;
ScreenToMapFixedPoint(0,0,&pos);
rawx=Divide(pos.x,768); rawy=Divide(pos.y,768);
ScreenToMapFixedPoint(256,192,&pos);
rawx1=Divide(pos.x,768);rawy1=Divide(pos.y,768);
x0=ClampRenderCoord(rawx,(u16*)(*gCurrentMap+0x5120),18);
y0=ClampRenderCoord(rawy,(u16*)(*gCurrentMap+0x5120),19);
x1=ClampRenderCoord(rawx1,(u16*)(*gCurrentMap+0x5120),18);
y1=ClampRenderCoord(rawy1,(u16*)(*gCurrentMap+0x5120),19);
func_0207750c();BuildMapCellCodes(x0,y0,x1,y1);BuildMapCellShades(x0,y0,x1,y1);
UpdateMapWaveHeight();Map_UpdateOwnerColorBands();Map_UpdateUnitFlashFrame();UpdateTerrainAnimOffsets();
for(i=0;i<32;i++)counts[i]=0;
*(volatile u32*)0x40004a8=0x6f600000;
for(y=y0;y<=y1;y++)for(x=x0;x<=x1;x++){
if(x<0 || y<0)continue;
base=*gCurrentMap;
{ u16 *dims=(u16*)(base+0x5120);if(x>=dims[18] || y>=dims[19])continue; }
index=x+M2C_FIELD(base+y*2,u16*,0x3758);
a=((u16*)((u8*)gMapCellCornerA+x*80))[y];b=((u16*)((u8*)gMapCellCornerB+x*80))[y];
tile=M2C_FIELD(base+index,u8*,0x1420);
visible=((u8*)(base+0x5120+0xe1))[index>>3]&(1<<(index&7));
visible=(u8)visible;
if(!tile)continue;
v1=(gMapCellCodes+x*40)[y];v2=(gMapCellShades+x*40)[y];
counts[tile&31]++;
Map_SubmitTerrainQuads(x,y,a,b,tile,visible,v1,v2);
}
func_020778cc(x0,y0,x1,y1);
for(i=0;i<32;i++){
void *p=(void*)(*gCurrentMap+0x58a4+i*8);
if((u32)(M2C_FIELD(p,u16*,2)<<22)>>28)DrawMapEffectEntry(p);
}
if(IsMapGridEnabled())func_02077740();
for(y=y0;y<=y1;y++)for(x=x0;x<=x1;x++){
if(IsUnitVisibleAt(x,y))RenderUnitAt(x,y,gMapCellCodes[x*40+y],mode);
}
*(volatile u32*)0x4000448=1;
SetAmbienceSoundVolume(1,0x108,counts[26]);SetAmbienceSoundVolume(2,0x109,counts[27]);
}
#pragma pop
void func_02078c60(s32 x,s32 y,s32 angle,s32 kind){
void GX_MatrixRotateZ(s32,s32); void Map_SubmitCellQuads(s32,s32,s32,s32,s32,s32);
s32 a,b,c,d,sn,cs; a=(gMapCellCodes+x*40)[y];b=(gMapCellShades+x*40)[y];
*(volatile u32 *)0x4000444=0;
if(angle){d=(y<<4)*48+0x180;c=(x<<4)*48+0x180;
cs=gSinCosTable[(angle>>4)*2+1];sn=gSinCosTable[(angle>>4)*2];
*(volatile u32 *)0x4000470=c;*(volatile u32 *)0x4000470=d;*(volatile u32 *)0x4000470=0;
GX_MatrixRotateZ(sn,cs);
*(volatile u32 *)0x4000470=-c;*(volatile u32 *)0x4000470=-d;*(volatile u32 *)0x4000470=0;}
*(volatile u32 *)0x4000470=0;*(volatile u32 *)0x4000470=0x300;*(volatile u32 *)0x4000470=0;
Map_SubmitCellQuads(x,y,kind,0,a,b);*(volatile u32 *)0x4000448=1;
}

#pragma push
#pragma scheduling on
#pragma opt_common_subs on
/* Draws one map order/effect marker on the 3D layer: kind 3 is a pulsating
   alpha-blended quad, 6/7/8 are sprites (optionally rotated) and 9 calls the
   map's cell callback. */
void DrawMapEffectEntry(void *arg0) {
s32 GetUiColor(s32);s32 EaseInterpolate(s32,s32,s32,s32,s32);s32 GetFacingOffset(s32);void MapView_SetCursorPosition(s16,s16,s32);
MapRenderEntry *entry=arg0;u32 bits=M2C_FIELD(arg0,u16 *,2);s32 x=M2C_FIELD(arg0,u8 *,0),y=M2C_FIELD(arg0,u8 *,1);
s32 offX=entry->dx,offY=entry->dy; s32 x0,y0,x1,y1,color; u32 alpha; s16 sx0,sy0,sx1,sy1;
switch(entry->kind){
case 3:
x0=(x<<4)*48;y0=(y<<4)*48;x1=x0+offX*768;y1=y0+offY*768;
color=GetUiColor(M2C_FIELD(arg0,u8 *,4));
if(((*(volatile u32 *)&gFrameCounter)&63)<32)alpha=EaseInterpolate(4,2,12,(*(volatile u32 *)&gFrameCounter)&63,32);
else alpha=EaseInterpolate(1,12,2,((*(volatile u32 *)&gFrameCounter)&63)-32,32);
if(!(alpha=(u8)alpha))return;
*(volatile u32*)0x40004a8=0x2d00000;
*(volatile u32*)0x40004a4=0x70000c0|(alpha<<16);
sx0=x0;sy0=y0;sx1=x1;sy1=y1;
*(volatile u32*)0x4000500=1;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx0|((u16)sy0<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx0|((u16)sy1<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx1|((u16)sy1<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx1|((u16)sy0<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000504=0;*(volatile u32*)0x4000480=0x7fff;return;
case 6:func_02078c60(x,y,0,0x381);return;
case 7:func_02078c60(x,y,(u16)GetFacingOffset(entry->angle),0x382);return;
case 8:func_02078c60(x,y,M2C_FIELD(arg0,u8 *,4)<<8,0x382);return;
case 9:
*(volatile u32*)0x4000480=0x7fff;*(volatile u32*)0x4000444=0;
*(volatile u32*)0x4000470=0;*(volatile u32*)0x4000470=0;*(volatile u32*)0x4000470=-16;
MapView_SetCursorPosition((s16)(x<<4),(s16)(y<<4),M2C_FIELD(arg0,u8 *,4));
*(volatile u32*)0x4000448=1;return;
}
}
#pragma pop
/* Draws the unit standing on map tile (x,y): finds its record, collects the status
 * bits that select the unit's status icons (fuel/HP warning, cargo, acted,
 * selected, ...), converts the tile to world coordinates and hands it to
 * RenderUnitSprite. */
void RenderUnitAt(s32 x, s32 y, s32 extra, u8 mode) {
    s32 IsUnitLowOnFuel(void *);
    s32 IsUnitLowOnAmmo(void *);
    s32 UnitKindCanSupply(s32);
    s32 IsUnitSubmerged(void *);
    s32 UnitHasCapturePoints(void *);
    s32 UnitHasCargo(void *);
    s32 Map_ShowsCargoForUnit(s32, u16, s32);
    s32 HasUnitActed(void *);
    s32 IsUnitSelected(void *);
    s32 IsUnitMarkedForRepair(void *);
    void RenderUnitSprite(Vec3 *, RenderUnit *, s32, s32, s32, u8);
    extern s32 *gCurrentMap;

    s32 base, player, kind, vecx, vecy, vecz; s32 flags;
    u16 rowoff;
    u8 val;
    u8 *unit;
    Vec3 pos;

    base = *gCurrentMap;
    rowoff = *(u16 *)((u8 *)base + y * 2 + MAP_ROW_OFFSETS);
    val = *(u8 *)((u8 *)base + (x + rowoff) + MAP_CELL_UNIT_ID);
    if (val == 0) return;

    flags = 0;
    player = ((val & 0xc0) >> 6) + 1;
    unit = (u8 *)base + MAP_UNIT_RECORDS + (s32)(val * MAP_UNIT_STRIDE);

    if (IsUnitLowOnFuel((void *)unit)) flags |= 0x2;
    if (IsUnitLowOnAmmo((void *)unit)) {
        kind = ((RenderUnit *)unit)->kind;
        if (UnitKindCanSupply(kind)) flags |= 0x8;
        else flags |= 0x4;
    }
    if (IsUnitSubmerged((void *)unit)) flags |= 0x20;
    {
        u8 side = *(u8 *)((u8 *)*gCurrentMap + (player) * MAP_PLAYER_STRIDE + PLAYER_SIDE_OFF);
        if (!(side & SIDE_TEAM_B)) flags |= 0x1;
    }
    if (UnitHasCapturePoints((void *)unit)) flags |= 0x40;
    if (UnitHasCargo((void *)unit)) flags |= 0x80;
    {
        kind = ((RenderUnit *)unit)->kind;
        if (Map_ShowsCargoForUnit(kind, *(u16 *)((u8 *)*gCurrentMap + MAP_CURRENT_PLAYER), (u16)player)) flags |= 0x100;
    }
    if (HasUnitActed((void *)unit)) flags |= 0x200;
    if (IsUnitSelected((void *)unit)) flags |= 0x400;
    if (IsUnitMarkedForRepair((void *)unit)) flags |= 0x800;

    vecx = (x * 16 + 8) * 48;
    vecy = (y * 16 + 16) * 48;
    vecz = ((y << 12) >> 8) + 1073;

    pos.x = vecx;
    pos.y = vecy;
    pos.z = vecz;
    RenderUnitSprite(&pos, (RenderUnit *)unit, player, flags, extra, (u8)mode);
}

#pragma scheduling on
/* Draws the 3D unit sprite for `unit` at `origin`: picks the sprite variant from
   the owner's army index plus the acted/selected flags, fills the shared render
   context, draws the body and then the status icons on either side of it. */
void RenderUnitSprite(Vec3 *origin,RenderUnit *unit,s32 player,s32 flags,s32 extra,u8 mode){
s32 GetUnitVariantIndex(s32,u8);s32 GetViewZoom(s32);s32 Divide(s32,s32);
void func_020793f0(UnitRenderContext *);void DrawUnitStatusIcon(Vec3 *,UnitRenderContext *);void DrawUnitHpIcon(Vec3 *,UnitRenderContext *);
extern s32 *gCurrentMap;
Vec3 pos;UnitRenderContext ctx; s32 spriteVariant;
pos=*origin;
spriteVariant=M2C_FIELD(*gCurrentMap+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_ARMY_INDEX_OFF)-1;
if(flags&0x200)spriteVariant+=4;
if(flags&0x400)spriteVariant+=8;
ctx.pos=pos;ctx.unit=unit;
ctx.kind=GetUnitVariantIndex(unit->kind,M2C_FIELD(*gCurrentMap+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF));
ctx.frame=GetViewZoom(*gCurrentMap+MAP_VIEW_ZOOM)<=0?16:24;
ctx.variant=spriteVariant;ctx.flags=flags;
ctx.side=unit->side;
ctx.color=M2C_FIELD(*gCurrentMap+player*MAP_PLAYER_STRIDE,u8 *,PLAYER_FLIP_OFF);
ctx.extra=extra;ctx.mode=mode;
ctx.hp=unit->hp==0?0:Divide(unit->hp-1,10)+1;
func_020793f0(&ctx);pos.x-=192;DrawUnitStatusIcon(&pos,&ctx);pos.x+=384;DrawUnitHpIcon(&pos,&ctx);
}
/* Submit the terrain quads of one map cell: the terrain class's flags say whether
 * the cell has a visible top (bit 3) and/or a side face (bit 4); a property adds
 * its owner's corner height to the top.  A cell with two facing variants (d)
 * submits both, the first lowered by that height. */
void Map_SubmitTerrainQuads(s32 x,s32 y,s32 terrain,s32 altTerrain,s32 tile,s32 visible,s32 cornerA,s32 cornerB){
void Map_SubmitCellQuads(s32,s32,s32,s32,s32,s32);s32 Map_GetPropertyOwnerArmy(s32);
s32 flags; s32 mask,xOff=0,yOff=0;
if(visible)mask=24;else{xOff+=16;mask=8;yOff=xOff;} flags=gTerrainClassFlags[terrain][0];
if(mask&(u16)flags)xOff+=Map_GetPropertyOwnerArmy(tile);
if(altTerrain){Map_SubmitCellQuads(x,y,terrain,xOff,cornerA,cornerB);Map_SubmitCellQuads(x,y,altTerrain,yOff,cornerA,cornerB);return;}
Map_SubmitCellQuads(x,y,terrain,xOff,cornerA,cornerB);
}

