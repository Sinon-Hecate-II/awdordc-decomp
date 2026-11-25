/* 14 functions from 0x021E41AC to 0x021E4B94 (ov002), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov002_panel.h"


/* Compares two entries (index temp_r0 vs its counterpart) and returns 0/1/2. */
s32 CompareUnitViewGauges(void *entry, s32 flag) {
    extern u8 gVersusPlayerCoIndex[];
    extern u8 gVersusGaugeHp[];
    extern u8 gVersusPlayerStates[];
    u32 idx;
    u8 val0, val1;
    s32 alt;

    idx = (u32)(((u8 *)entry)[3] << 0x1C) >> 0x1C;
    if (gVersusPlayerCoIndex[idx * 0x18] == 0) {
        return 0;
    }
    val0 = gVersusGaugeHp[idx * 0x18];
    if (val0 == 0) {
        return 2;
    }
    alt = (idx == 0) ? 1 : 0;
    if (gVersusGaugeHp[alt * 0x18] == 0) {
        return 1;
    }
    if (flag != 0) {
        alt = (idx == 0) ? 1 : 0;
        if (gVersusPlayerStates[alt * 0x18] == 0) {
            return 0;
        }
    }
    alt = (idx == 0) ? 1 : 0;
    val1 = gVersusGaugeHp[alt * 0x18];
    if (((val0 + 9) / 10) + 4 <= ((val1 + 9) / 10)) {
        return 2;
    }
    return 0;
}

void func_ov002_021e42a8(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 2) = arg1;
}

void func_ov002_021e42b0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 3) = (u8) ((M2C_FIELD(arg0, u8 *, 3) & ~0xF0) | 0x10);
}

/* One frame of a versus screen unit view: advance its HP-gauge fill animation a
 * step and, when the fill settles, play the defeat sound if the player is out of
 * HP; then decay the view's screenshake counter while the gauges are moving. */
void StepUnitViewGauge(u8 *view) {
 u32 StopEffectSlotSound(u32,s32,s32);
 extern u8 gVersusGaugeHp[];
 if((u32)(view[UNIT_VIEW_FLAGS]<<24)>>28) {
 if((u32)view[UNIT_VIEW_GAUGE_FRAME]<(u32)view[UNIT_VIEW_GAUGE_LENGTH]) {
 if(++view[UNIT_VIEW_GAUGE_FRAME]==(u32)view[UNIT_VIEW_GAUGE_LENGTH]) {
 u32 player=(u32)(view[UNIT_VIEW_FLAGS]<<28)>>28;
 if(((s32)gVersusGaugeHp[player*VERSUS_DATA_STRIDE]+9)/10==0) StopEffectSlotSound(player,32,0);
 }}}
 if(AreUnitViewGaugesDone() && view[UNIT_VIEW_SHAKE]) --view[UNIT_VIEW_SHAKE];
}

/* Draws a flat single-colour quad from its four corners at depth z, submitting
   the vertices in perimeter order tl, bl, br, tr. */
void DrawFlatQuad(s32 tlX,s32 tlY,s32 trX,s32 trY,s32 blX,s32 blY,s32 brX,s32 brY,s32 z,s32 color) {
s32 x,y,w;
s16 bb=(s16)tlY, aa=(s16)tlX, ff=(s16)blY, ee=(s16)blX, hh=(s16)brY, gg=(s16)brX, dd=(s16)trY, cc=(s16)trX;
REG_GX_BEGIN_VTXS=GX_PRIM_QUADS;
REG_GX_COLOR=(u16)color;
x=(u32)(u16)aa|((u32)(u16)bb<<16);
REG_GX_VTX_16=x;
REG_GX_VTX_16=(u16)(s16)z;
y=(u32)(u16)ee|((u32)(u16)ff<<16);
REG_GX_VTX_16=y;
REG_GX_VTX_16=(u16)(s16)z;
w=(u32)(u16)gg|((u32)(u16)hh<<16);
REG_GX_VTX_16=w;
REG_GX_VTX_16=(u16)(s16)z;
x=(u32)(u16)cc|((u32)(u16)dd<<16);
REG_GX_VTX_16=x;
REG_GX_VTX_16=(u16)(s16)z;
REG_GX_END_VTXS=0;
REG_GX_COLOR=GX_RGB_WHITE;
}

/* Draws a horizontal-gradient quad from the four corners (tl, tr, bl, br):
 * the left vertices get color and the right vertices white, or the reverse
 * when flip is set (mirrored panels). */
void DrawGradientQuad(s32 tlX,s32 tlY,s32 trX,s32 trY,s32 blX,s32 blY,s32 brX,s32 brY,s32 z,s32 color,s32 flip) {
s32 leftColor,rightColor,xy,xy2;
REG_GX_BEGIN_VTXS=GX_PRIM_QUADS;
leftColor=flip?GX_RGB_WHITE:color;
{
s16 bb=(s16)tlY,aa=(s16)tlX,ff=(s16)blY,ee=(s16)blX,zz=(s16)z;
REG_GX_COLOR=(u16)leftColor;
xy=(u32)(u16)aa|((u32)(u16)bb<<16);
REG_GX_VTX_16=xy;
REG_GX_VTX_16=(u16)zz;
xy2=(u32)(u16)ee|((u32)(u16)ff<<16);
REG_GX_VTX_16=xy2;
REG_GX_VTX_16=(u16)zz;
}
rightColor=flip?color:GX_RGB_WHITE;
{
s16 hh=(s16)brY,gg=(s16)brX,dd=(s16)trY,cc=(s16)trX,zz=(s16)z;
REG_GX_COLOR=(u16)rightColor;
xy=(u32)(u16)gg|((u32)(u16)hh<<16);
REG_GX_VTX_16=xy;
REG_GX_VTX_16=(u16)zz;
xy2=(u32)(u16)cc|((u32)(u16)dd<<16);
REG_GX_VTX_16=xy2;
REG_GX_VTX_16=(u16)zz;
}
REG_GX_END_VTXS=0;
REG_GX_COLOR=GX_RGB_WHITE;
}

/* Draw the left (player 0) versus-screen panel's background art mirrored about x:
 * two rows of nine 8x32 tiles, the columns running right to left, each tile using
 * its own 8x32 block of the panel's texture tile list. */
void DrawVersusPanelArtFlipped(s32 x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK SetGxTextureParams(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUVFlip(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 row,i,rowBase,nextRow;
 row=0;rowBase=0;
 do {
 i=0; do {
 SetGxTextureParams(4,8,32,tiles+(i+rowBase)*8,pal);
 DrawTexturedQuadUVFlip(x+(8-i)*8,y,0,8,32,0,0,8,32,1,0);
 i++; } while(i<9);
 rowBase+=9; y+=32; nextRow=row+1; row=nextRow;
 } while(row<2);
}

#pragma opt_strength_reduction off
void DrawVersusPanelArt(s32 x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK SetGxTextureParams(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 j,i,k,pp;
 u32 xx;
 pp=pal;
 j=0;k=0;
 do {
 xx=x;i=0;do {
 SetGxTextureParams(4,8,32,tiles+(i+k)*8,pp);
 DrawTexturedQuadUV(xx,y,0,8,32,0,0,8,32);
 xx+=8;i++; if(i>=9) break; } while(1);
 k+=9;j++;y+=32;
 }while(j<2);
}
#pragma opt_strength_reduction reset
/* Draw the versus-screen player panel's smaller artwork mirrored about x: three
 * 16x16 tiles from the panel's tile list, drawn right to left. */
void DrawVersusPanelArtSmallFlipped(s32 x,s32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK SetGxTextureParams(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUVFlip(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 col=0;
 do {
 SetGxTextureParams(4,16,16,tiles+((u32)col<<3),pal);
 DrawTexturedQuadUVFlip(x+(2-col)*16,y,0,16,16,0,0,16,16,1,0);
 col++;
 }while(col<3);
}

/* Draw the versus-screen player panel's smaller artwork: three 16x16 tiles of
 * the panel's tile list, drawn left to right from (x, y). */
void DrawVersusPanelArtSmall(s32 x, s32 y, s32 unused, s32 tiles, s32 palette) {
    M2C_UNK SetGxTextureParams(s32,s32,s32,s32,s32);
    M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
    s32 tile;
    tile = 0; do {
        SetGxTextureParams(4,16,16,tiles+((u32)tile<<3),palette);
        DrawTexturedQuadUV(x,y,0,16,16,0,0,16,16);
        tile++; x+=16;
    } while(tile<3);
}

/* Draw a versus-screen player panel's gauge fill, anchored at its right edge:
 * a 16-pixel-high textured body whose right edge stays at x+128 and whose left
 * edge moves left with `fill` (0..116), then five one-pixel strips that taper
 * the fill's left end.  y is the top edge, z the depth. */
void DrawGaugeFillAnchoredRight(s32 x,s32 y,s32 z,s32 fill) {
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 u,edge,height,i;
 height=16;u=116-fill;
 DrawTexturedQuadUV((s32)(x+u),y,z,fill+12,height,u,0,128,height);
 edge=fill+12; y+=4; height-=4;i=0;
 do {
 u=128-edge;
 DrawTexturedQuadUV((s32)(x+128-edge)-1,y,z,1,height,u-1,16-height,u,16);
 i++; edge++;y+=2;height-=2;
 }while(i<5);
}

/* Draw a versus-screen player panel's gauge fill, anchored at its left edge: a
 * 16-pixel-high textured body starting at x, then five one-pixel strips that
 * taper the fill's right end.  y is the top edge, z the depth. */
void DrawGaugeFillAnchoredLeft(u8 *x, s32 y, s32 z, s32 fill) {
    M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
    s32 edge, height, i, stripWidth;
    height = 16;
    DrawTexturedQuadUV((s32)x, y, z, fill + 12, height, 0, 0, fill + 12, height);
    edge = fill + 12; height -= 4; i = 0; stripWidth = 1;
    do {
        DrawTexturedQuadUV((s32)(x + edge), y, z, stripWidth, height, edge, 0, edge + 1, height);
        i++; edge++; height -= 2;
    } while (i < 5);
}

#pragma scheduling off
void func_ov002_021e497c(s32 x,s32 y,s32 flip,s32 tile) {
void AddSprite(u16,u16,u16,void *,s32);
void AddAffineSprite(u16,u16,u16,void *,s32);
extern u16 **gCur3DSpriteEngine;
extern u8 data_ov002_021f2d2a[],data_ov002_021f2d1c[];
u16 attr,px,py;
if(!flip) {
attr=(u16)((0x3ff&(0x11e>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12));
px=(u16)(x&511);py=(u16)(y&255);
AddSprite(px,py,attr,data_ov002_021f2d2a,1);
AddSprite((u16)((x+16)&511),(u16)((y+8)&255),(u16)((0x3ff&((0x150+(tile<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12)),data_ov002_021f2d1c,0);
} else {
attr=(u16)((0x3ff&(0x11e>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12));
px=(u16)((x+80)&511);py=(u16)(y&255);
AddAffineSprite(px,py,attr,data_ov002_021f2d2a,1);
AddSprite((u16)((x+8)&511),(u16)((y+8)&255),(u16)((0x3ff&((0x150+(tile<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12)),data_ov002_021f2d1c,0);
}
}
#pragma scheduling reset
/* True once both players' versus-screen HP gauges have finished filling: each
 * view's gauge frame has reached its fill length. */
s32 AreUnitViewGaugesDone(void) {
    extern u8 gUnitViews[];
    if ((gUnitViews[UNIT_VIEW_GAUGE_FRAME] == gUnitViews[UNIT_VIEW_GAUGE_LENGTH]) && (gUnitViews[UNIT_VIEW_SIZE + UNIT_VIEW_GAUGE_FRAME] == gUnitViews[UNIT_VIEW_SIZE + UNIT_VIEW_GAUGE_LENGTH])) {
        return 1;
    }
    return 0;
}

