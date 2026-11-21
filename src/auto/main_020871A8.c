/* 17 functions from 0x020871A8 to 0x02088044 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "sprite_grid.h"

/* Draws the axis-aligned quad at (x, y) of size width x height, at depth z,
 * filled with one GX colour, and leaves the current vertex colour white. */
void DrawSolidQuad(s32 x, s32 y, s32 z, s32 width, s32 height, u16 color) {
    s32 v, w, d;
    s16 y0 = (s16) y, x0 = (s16) x, y1 = (s16) (y + height), zz = (s16) z, x1 = (s16) (x + width);

    REG_GX_BEGIN_VTXS = GX_PRIM_QUADS;
    REG_GX_COLOR = color;
    v = (u32) (u16) x0 | ((u32) (u16) y0 << 0x10);
    REG_GX_VTX_16 = v;
    REG_GX_VTX_16 = (u32) (u16) zz;
    w = (u32) (u16) x0 | ((u32) (u16) y1 << 0x10);
    REG_GX_VTX_16 = w;
    REG_GX_VTX_16 = (u32) (u16) zz;
    d = (u32) (u16) x1 | ((u32) (u16) y1 << 0x10);
    REG_GX_VTX_16 = d;
    REG_GX_VTX_16 = (u32) (u16) zz;
    v = (u32) (u16) x1 | ((u32) (u16) y0 << 0x10);
    REG_GX_VTX_16 = v;
    REG_GX_VTX_16 = (u32) (u16) zz;
    REG_GX_END_VTXS = 0;
    REG_GX_COLOR = GX_RGB_WHITE;
}

void func_0208726c(s32 *x, s32 *y, s32 angle, s32 dist) {
    extern s16 gSinCosTable[];
    s32 i = (angle >> 4) * 2;
    s32 a = gSinCosTable[i];
    s32 b = gSinCosTable[i + 1];
    s32 d = -dist;
    s32 p = -(d * a);
    s32 q = d * b;
    *x = ((p >> 11) & 1) + (p >> 12);
    *y = ((q >> 11) & 1) + (q >> 12);
}

s32 RuntimeIntDivMod(s32,s32);
#pragma push
#pragma optimization_level 4
#pragma opt_common_subs off
void DrawGxCircleFan(s32 x,s32 y,s32 z,s32 r,s32 n,u16 color){s32 px,qx,py,qy,i;*(volatile u32*)0x4000500=0;*(volatile u32*)0x4000480=color;if(n&1) {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=n;i++){func_0208726c(&qx,&qy,(u16)RuntimeIntDivMod(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}else if(n&2) {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=(n>>1);i++){func_0208726c(&qx,&qy,(u16)RuntimeIntDivMod(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qx) | ((u32)(u16)(s16)(y-qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-px) | ((u32)(u16)(s16)(y-py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}else {func_0208726c(&px,&py,0,(s16)r);for(i=1;i<=(n>>2);i++){func_0208726c(&qx,&qy,(u16)RuntimeIntDivMod(i<<16,n),(s16)r);*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qx) | ((u32)(u16)(s16)(y+qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+px) | ((u32)(u16)(s16)(y+py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qx) | ((u32)(u16)(s16)(y-qy)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-px) | ((u32)(u16)(s16)(y-py)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-qy) | ((u32)(u16)(s16)(y+qx)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x-py) | ((u32)(u16)(s16)(y+px)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=((u32)(u16)(s16)(y)<<16) + (u32)(u16)(s16)(x);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+qy) | ((u32)(u16)(s16)(y-qx)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
*(volatile u32*)0x400048c=(u32)(u16)(s16)(x+py) | ((u32)(u16)(s16)(y-px)<<16);
*(volatile u32*)0x400048c=(u32)(u16)(s16)z;
px=qx;py=qy;}}*(volatile u32*)0x4000504=0;*(volatile u32*)0x4000480=0x7fff;}
#pragma pop
/* Draws one textured quad spanning (x, y) to (x + width, y + height) at depth z,
 * sampling the texture rectangle (u0, v0) to (u1, v1): the texel coordinates are
 * rounded into GX's 1/16-texel fixed-point texture coordinates. */
void DrawTexturedQuadUV(s32 x, s32 y, s32 z, s32 width, s32 height, s32 u0, s32 v0, s32 u1, s32 v1) {
    u16 y0 = (u16) (s16) y;
    u16 x0 = (u16) (s16) x;
    s16 top = (s16)(((v0 << 12) + GX_FX_HALF) >> 8);
    s16 left = (s16)(((u0 << 12) + GX_FX_HALF) >> 8);
    s16 bottom = (s16)(((v1 << 12) + GX_FX_HALF) >> 8);
    u16 y1 = (u16) (s16) (y + height);
    s16 right = (s16)(((u1 << 12) + GX_FX_HALF) >> 8);
    u16 x1 = (u16) (s16) (x + width);

    REG_GX_BEGIN_VTXS = GX_PRIM_QUADS;
    REG_GX_TEX_COORD = (u32)(u16)left | ((u32)(u16)top << 0x10);
    REG_GX_VTX_16 = x0 | ((u32) y0 << 0x10);
    REG_GX_VTX_16 = (u16) (s16) z;
    REG_GX_TEX_COORD = (u32)(u16)left | ((u32)(u16)bottom << 0x10);
    REG_GX_VTX_16 = x0 | ((u32) y1 << 0x10);
    REG_GX_VTX_16 = (u16) (s16) z;
    REG_GX_TEX_COORD = (u32)(u16)right | ((u32)(u16)bottom << 0x10);
    REG_GX_VTX_16 = x1 | ((u32) y1 << 0x10);
    REG_GX_VTX_16 = (u16) (s16) z;
    REG_GX_TEX_COORD = (u32)(u16)right | ((u32)(u16)top << 0x10);
    REG_GX_VTX_16 = x1 | ((u32) y0 << 0x10);
    REG_GX_VTX_16 = (u16) (s16) z;
    REG_GX_END_VTXS = 0;
}

#pragma push
#pragma optimization_level 4
/* Draws one textured quad from four explicit corners: (x0, y0) and (x1, y1)
 * form the top edge, (x2, y2) and (x3, y3) the bottom edge, at depth z, sampling
 * the texture rectangle (u0, v0) to (u1, v1); the texel coordinates are rounded
 * into GX's 1/16-texel fixed-point texture coordinates. */
void DrawTexturedQuadCorners(s32 x0, s32 y0, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3, s32 y3,
                             s32 z, s32 u0, s32 v0, s32 u1, s32 v1) {
    s16 v0fx = (s16)(((v0 << 12) + GX_FX_HALF) >> 8);
    u16 v0u = (u16) v0fx;
    s16 u0fx = (s16)(((u0 << 12) + GX_FX_HALF) >> 8);
    s16 v1fx = (s16)(((v1 << 12) + GX_FX_HALF) >> 8);
    s16 u1fx = (s16)(((u1 << 12) + GX_FX_HALF) >> 8);
    s16 y0s = (s16) y0, x0s = (s16) x0, y2s = (s16) y2, x2s = (s16) x2,
        zs = (s16) z, y3s = (s16) y3, x3s = (s16) x3, y1s = (s16) y1, x1s = (s16) x1;

    REG_GX_BEGIN_VTXS = GX_PRIM_QUADS;
    REG_GX_TEX_COORD = (u16) u0fx | ((u32) v0u << 16);
    REG_GX_VTX_16 = (u16) x0s | ((u32)(u16) y0s << 16);
    REG_GX_VTX_16 = (u16) zs;
    REG_GX_TEX_COORD = (u16) u0fx | ((u32)(u16) v1fx << 16);
    REG_GX_VTX_16 = (u16) x2s | ((u32)(u16) y2s << 16);
    REG_GX_VTX_16 = (u16) zs;
    REG_GX_TEX_COORD = (u16) u1fx | ((u32)(u16) v1fx << 16);
    REG_GX_VTX_16 = (u16) x3s | ((u32)(u16) y3s << 16);
    REG_GX_VTX_16 = (u16) zs;
    REG_GX_TEX_COORD = (u16) u1fx | ((u32) v0u << 16);
    REG_GX_VTX_16 = (u16) x1s | ((u32)(u16) y1s << 16);
    REG_GX_VTX_16 = (u16) zs;
    REG_GX_END_VTXS = 0;
}
#pragma pop
void DrawTexturedQuadUV(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
/* Draws a textured quad (position x,y, depth z, size w x h) sampling texels
 * (u0,v0)..(u1,v1), mirroring the texture on the S axis, the T axis or both when
 * the matching flip flag is set; the -1 on a mirrored edge skips the last texel
 * so the mirrored span stays inside the source rectangle. */
void DrawTexturedQuadUVFlip(s32 x, s32 y, s32 z, s32 w, s32 h, s32 u0, s32 v0, s32 u1, s32 v1, s32 hFlip, s32 vFlip) {
    if (hFlip != 0 && vFlip != 0) {
        DrawTexturedQuadUV(x, y, z, w, h, u1 - 1, v1 - 1, u0 - 1, v0 - 1);
    } else if (hFlip != 0) {
        DrawTexturedQuadUV(x, y, z, w, h, u1 - 1, v0, u0 - 1, v1);
    } else if (vFlip != 0) {
        DrawTexturedQuadUV(x, y, z, w, h, u0, v1 - 1, u1, v0 - 1);
    } else {
        DrawTexturedQuadUV(x, y, z, w, h, u0, v0, u1, v1);
    }
}

/* Draws a 1-pixel line from (x0, y0) to (x1, y1) at depth z in one GX colour.
 * The DS has no line primitive, so it is sent as the degenerate triangle
 * (start, end, start); the current vertex colour is left white afterwards. */
void DrawGxLine(s32 x0,s32 y0,s32 x1,s32 y1,s32 z,u16 color) {
 s32 start,end,depth; s16 yb=(s16)y0,xa=(s16)x0,yd=(s16)y1,ze=(s16)z,xc=(s16)x1;
 
 REG_GX_BEGIN_VTXS=GX_PRIM_TRIANGLES;
 REG_GX_COLOR=color;
 start=(u16)xa|((u32)(u16)yb<<16); depth=(u16)ze;
 REG_GX_VTX_16=start;
 REG_GX_VTX_16=depth;
 end=(u16)xc|((u32)(u16)yd<<16);
 REG_GX_VTX_16=end;
 REG_GX_VTX_16=depth;
 REG_GX_VTX_16=start;
 REG_GX_VTX_16=depth;
 REG_GX_END_VTXS=0;
 REG_GX_COLOR=GX_RGB_WHITE;
}

#pragma opt_strength_reduction off
/* Adds one cell to a sprite-cell block: it fills the first free cell (attr 0)
 * with the given rectangle and graphic, bumps the block's used-cell count, and
 * does nothing when every cell is taken. */
void AddSpriteCell(void *list, s32 x, s32 y, s32 width, u16 height, u16 tile, u16 attr) {
    u16 capacity = M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_CAPACITY);
    SpriteCell *cell = M2C_FIELD(list, SpriteCell **, SPRITE_CELL_LIST_CELLS);
    s32 i;

    for (i = 0; i < (s32) capacity; i++, cell++) {
        if (cell->attr == 0) {
            cell->x = (s16) x;
            cell->y = (s16) y;
            cell->width = (s16) width;
            cell->height = (s16) height;
            cell->tile = tile;
            cell->attr = attr;
            M2C_FIELD(list, u8 *, SPRITE_CELL_LIST_USED)++;
            return;
        }
    }
}
#pragma opt_strength_reduction reset
void func_02087d84(void *a,s32 b,s32 c,s32 d,u16 e,u16 f) {void *func_02087e68(void *,s32);u16 *p=func_02087e68(a,(s16)b);p[0]=c;p[1]=d;p[2]=e;p[3]=f;}

/* Take the cell showing tile `tile` out of a cell list: clear it, decrement the
 * list's used-cell count and, when the list was on that cell, forget it. */
void RemoveSpriteCell(void *list, s32 tile) {
    s32 i;
    u16 capacity;
    SpriteCell *cell;
    SpriteCell *current;

    capacity = M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_CAPACITY);
    cell = M2C_FIELD(list, SpriteCell **, SPRITE_CELL_LIST_CELLS);
    i = 0;
    if ((s32) capacity > 0) {
loop_1:
        if (cell->tile == tile) {
            MI_CpuFill8(cell, 0, sizeof(SpriteCell));
            M2C_FIELD(list, u8 *, SPRITE_CELL_LIST_USED) = (u8) (M2C_FIELD(list, u8 *, SPRITE_CELL_LIST_USED) - 1);
        } else {
            i += 1;
            cell += 1;
            if (i < (s32) capacity) {
                goto loop_1;
            }
        }
    }
    current = M2C_FIELD(list, SpriteCell **, SPRITE_CELL_LIST_CURRENT);
    if (current == NULL) {
        return;
    }
    if (tile == current->tile) {
        M2C_FIELD(list, SpriteCell **, SPRITE_CELL_LIST_CURRENT) = NULL;
        M2C_FIELD(list, s32 *, SPRITE_CELL_LIST_PREVIOUS) = 0;
    }
}

#pragma optimization_level 2
void func_02087e34(void *arg0) { M2C_UNK MI_CpuFill8(s32,M2C_UNK,s32); M2C_FIELD(arg0,s32 *,0)=0; M2C_FIELD(arg0,s32 *,4)=0; MI_CpuFill8(M2C_FIELD(arg0,s32 *,0x14),0,M2C_FIELD(arg0,u16 *,0x10)*12); M2C_FIELD(arg0,u8 *,0x12)=0; }
#pragma optimization_level reset
void *func_02087e68(void *a,s32 b) {s32 i;u16 n;u8 *p;n=M2C_FIELD(a,u16 *,16);p=M2C_FIELD(a,u8 **,20);for(i=0;i<(s32)n;i++,p+=12)if(M2C_FIELD(p,u16 *,8)==b)return p;return 0;}

#pragma optimize_for_size off
void func_02087ea0(void *arg0,void *arg1){
if(M2C_FIELD(arg1,u16*,0xA)&4){
u32 zero=0; void *old=M2C_FIELD(arg0,void**,0);
M2C_FIELD(arg0,void**,0)=arg1;
M2C_FIELD(arg0,void**,4)=old;
M2C_FIELD(arg0,s8*,0xF)=zero;
}}
#pragma push
#pragma opt_propagation off
void func_02087ec0(void *a,s32 b){
void *func_02087e68(void*,s32);void func_02087ea0(void*,void*);
if(b==-1){M2C_FIELD(a,s32*,4)=0;M2C_FIELD(a,s32*,0)=0;M2C_FIELD(a,u8*,15)=255;return;}
func_02087ea0(a,func_02087e68(a,b));
}
#pragma pop
void func_02087f00(void *p, s32 id) { void func_02087ec0(void *, s32); func_02087ec0(p, id); M2C_FIELD(p,s32 *,4)=M2C_FIELD(p,s32 *,0); M2C_FIELD(p,u8 *,15)=255; }

s32 func_02087f20(s32 a,void *b,s32 c,s32 d) {s32 x=M2C_FIELD(b,s16 *,0);s32 y;if(c<x || x+M2C_FIELD(b,u16 *,4)<=c)return 0;y=M2C_FIELD(b,s16 *,2);if(d<y || y+M2C_FIELD(b,u16 *,6)<=d)return 0;return 1;}

/* Tests whether a point falls on a sprite cell list's background: it must lie
 * inside the list's bounding box and on none of its active cells (each cell's
 * rectangle expanded by the list's hit tolerance).  Returns 1 on a background
 * hit, 0 when the point is outside the box or on a cell. */
s32 SpriteCellListBackgroundHit(void *list, s32 x, s32 y) {
    s32 left = M2C_FIELD(list, s16 *, SPRITE_CELL_LIST_BOX_LEFT);
    s32 top;
    u16 count;
    SpriteCell *cell;
    s32 i;
    u16 pad;
    s16 px, py;

    if (x < left || left + M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_BOX_WIDTH) <= x) return 0;
    top = M2C_FIELD(list, s16 *, SPRITE_CELL_LIST_BOX_TOP);
    if (y < top || top + M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_BOX_HEIGHT) <= y) return 0;
    count = M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_CAPACITY);
    cell = M2C_FIELD(list, SpriteCell **, SPRITE_CELL_LIST_CELLS);
    for (i = 0; i < count; i++, cell++) {
        if (cell->attr) {
            pad = M2C_FIELD(list, u16 *, SPRITE_CELL_LIST_HIT_PAD);
            px = cell->x;
            if (x < px - pad) continue;
            if (px + M2C_FIELD(cell, u16 *, 4) + pad <= x) continue;
            py = cell->y;
            if (y < py - pad) continue;
            if (py + M2C_FIELD(cell, u16 *, 6) + pad > y) return 0;
        }
    }
    return 1;
}

