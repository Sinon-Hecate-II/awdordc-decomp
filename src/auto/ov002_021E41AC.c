/* 14 functions from 0x021E41AC to 0x021E4B94 (ov002), found by ds-decomp. */
#include "common.h"
#include "gx.h"


/* Compares two entries (index temp_r0 vs its counterpart) and returns 0/1/2. */
s32 func_ov002_021e41ac(void *entry, s32 flag) {
    extern u8 data_ov002_021f3105[];
    extern u8 data_ov002_021f30fe[];
    extern u8 gVersusPlayerStates[];
    u32 idx;
    u8 val0, val1;
    s32 alt;

    idx = (u32)(((u8 *)entry)[3] << 0x1C) >> 0x1C;
    if (data_ov002_021f3105[idx * 0x18] == 0) {
        return 0;
    }
    val0 = data_ov002_021f30fe[idx * 0x18];
    if (val0 == 0) {
        return 2;
    }
    alt = (idx == 0) ? 1 : 0;
    if (data_ov002_021f30fe[alt * 0x18] == 0) {
        return 1;
    }
    if (flag != 0) {
        alt = (idx == 0) ? 1 : 0;
        if (gVersusPlayerStates[alt * 0x18] == 0) {
            return 0;
        }
    }
    alt = (idx == 0) ? 1 : 0;
    val1 = data_ov002_021f30fe[alt * 0x18];
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

void func_ov002_021e42c4(u8 *p) {
 u32 func_020af9cc(u32,s32,s32);
 extern u8 data_ov002_021f30fe[];
 if((u32)(p[3]<<24)>>28) {
 if((u32)p[0]<(u32)p[1]) {
 if(++p[0]==(u32)p[1]) {
 u32 id=(u32)(p[3]<<28)>>28;
 if(((s32)data_ov002_021f30fe[id*24]+9)/10==0) func_020af9cc(id,32,0);
 }}}
 if(func_ov002_021e4b68() && p[5]) --p[5];
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

void func_ov002_021e45c0(s32 x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUVFlip(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 j,i,k,next;
 j=0;k=0;
 do {
 i=0; do {
 func_02087064(4,8,32,tiles+(i+k)*8,pal);
 DrawTexturedQuadUVFlip(x+(8-i)*8,y,0,8,32,0,0,8,32,1,0);
 i++; } while(i<9);
 k+=9; y+=32; next=j+1; j=next;
 } while(j<2);
}

#pragma opt_strength_reduction off
void func_ov002_021e4674(s32 x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 j,i,k,pp;
 u32 xx;
 pp=pal;
 j=0;k=0;
 do {
 xx=x;i=0;do {
 func_02087064(4,8,32,tiles+(i+k)*8,pp);
 DrawTexturedQuadUV(xx,y,0,8,32,0,0,8,32);
 xx+=8;i++; if(i>=9) break; } while(1);
 k+=9;j++;y+=32;
 }while(j<2);
}
#pragma opt_strength_reduction reset
void func_ov002_021e4728(s32 x,s32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUVFlip(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 i=0;
 do {
 func_02087064(4,16,16,tiles+((u32)i<<3),pal);
 DrawTexturedQuadUVFlip(x+(2-i)*16,y,0,16,16,0,0,16,16,1,0);
 i++;
 }while(i<3);
}

void func_ov002_021e47b0(s32 x,s32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 i;
 i=0; do {
 func_02087064(4,16,16,tiles+((u32)i<<3),pal);
 DrawTexturedQuadUV(x,y,0,16,16,0,0,16,16);
 i++; x+=16;
 } while(i<3);
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

void func_ov002_021e48e8(u8 *x,s32 y,s32 z,s32 w) {
 M2C_UNK DrawTexturedQuadUV(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 k,h,i,o;
 h=16;
 DrawTexturedQuadUV((s32)x,y,z,w+12,h,0,0,w+12,h);
 k=w+12; h-=4; i=0; o=1;
 do {
  DrawTexturedQuadUV((s32)(x+k),y,z,o,h,k,0,k+1,h);
  i++; k++; h-=2;
 } while(i<5);
}

#pragma scheduling off
void func_ov002_021e497c(s32 x,s32 y,s32 flip,s32 tile) {
void AddSprite(u16,u16,u16,void *,s32);
void func_01ffad0c(u16,u16,u16,void *,s32);
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
func_01ffad0c(px,py,attr,data_ov002_021f2d2a,1);
AddSprite((u16)((x+8)&511),(u16)((y+8)&255),(u16)((0x3ff&((0x150+(tile<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12)),data_ov002_021f2d1c,0);
}
}
#pragma scheduling reset
s32 func_ov002_021e4b68(void) {
    extern M2C_UNK gUnitViews;
    if ((M2C_FIELD(&gUnitViews, u8 *, 0) == M2C_FIELD(&gUnitViews, u8 *, 1)) && (M2C_FIELD(&gUnitViews, u8 *, 0x2C) == M2C_FIELD(&gUnitViews, u8 *, 0x2D))) {
        return 1;
    }
    return 0;
}

