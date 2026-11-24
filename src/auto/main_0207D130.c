/* 14 functions from 0x0207D130 to 0x0207DE50 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "gx.h"
#include "ds3dsprite.h"
typedef struct { s16 coords[24]; } TerrainCoords48;
typedef struct { s16 coords[12]; } TerrainCoords24;
extern void **gCurrentMap;
extern u8 gTerrainTileset;
extern const s16 gNeighborOffsets8[24];
extern const s16 gTerrainNeighborOffsets[24];
extern const u16 gTerrainEndTileTable[16];
extern const u16 gTerrainVariantTable[256];
extern const u8 gTerrainClassFlags[];

extern const u8 data_020ec6bc[], data_020ecabc[], data_020ecebc[], data_020ed2bc[], data_020ed6bc[], data_020edabc[], data_020ec2bc[];
/* Main OBJ extended-palette direct write: [0] is the VRAM base of the released
 * palette banks and [1] the bank grant the last write used. */
extern u32 gObjExtPlttWriteState[2];
extern const u16 gVramBankBaseTable[8];

extern s16 gSinCosTable[2048];
extern s16 data_02101834[4][4][2];
extern void *gCur3DSpriteEngine;
void func_02004078(s32, s32);
void func_0207d49c(s32, s32, s32);
void DrawTexturedQuad(s32, s32, s32);
s32 GetGxTextureSizeCode(s32);
s32 GetGxTextureSizeCode2(s32);
void func_0207d130(const u16 *attr, const s32 *position, u32 texture, u32 palette,
                  s32 scale, s32 angle, s32 centered, s32 texWidth, s32 texHeight,
                  s32 tileScale, s32 tileOffset) {
    register s32 count = *attr++;
    register volatile u32 *gx = (volatile u32 *)0x04000440;
    s32 palNum, flips, posX, posY, posZ, drawX, drawY, heightCode, cosine, sine;
    posX = position[0];
    posY = position[1];
    posZ = position[2];
    gx[0] = 3;
    gx[1] = 0;
    gx[0] = 2;
    if (count > 0) {
        cosine = gSinCosTable[(angle >> 4) * 2 + 1];
        sine = gSinCosTable[(angle >> 4) * 2];
        while (count > 0) {
            u16 a0, a1, a2;
            s32 width, height, x, y, tile;
            s32 widthCode;
            DS3DSpriteEngine *engine;
            gx[1] = 0;
            a0 = attr[0];
            a1 = attr[1];
            a2 = attr[2];
            width = data_02101834[a0 >> 14][a1 >> 14][0];
            height = data_02101834[a0 >> 14][a1 >> 14][1];
            palNum = (a2 & 0xf000) >> 12;
            x = a1 & 0x1ff;
            y = a0 & 0xff;
            tile = a2 & 0x3ff;
            flips = a1 & 0x3000;
            if (tileScale) {
                s32 tileX, tileY;
                u32 tileIndex;
                gx[0] = 3;
                gx[5] = 0;
                tileIndex = tileOffset + tile;
                tileX = (tileIndex & 0x1f) << 7;
                tileY = (s32)(tileIndex & 0x3e0) >> 2;
                tileX <<= 12;
                tileY <<= 16;
                gx[12] = ((s64)tileX * tileScale + GX_FX_HALF) >> 12;
                gx[12] = ((s64)tileY * tileScale + GX_FX_HALF) >> 12;
                gx[12] = 0;
                gx[11] = tileScale;
                gx[11] = tileScale;
                gx[11] = 0;
                gx[0] = 2;
            }
            --count;
            if (x & 0x100) x |= -0x200;
            if (y & 0x80) y |= -0x100;
            if (centered) {
                s32 centerX = x + (width >> 1);
                s32 centerY = y + height;
                engine = DS3D_ENGINE(gCur3DSpriteEngine);
                drawX = engine->offsetX + centerX;
                drawY = engine->offsetY + centerY;
            } else {
                engine = DS3D_ENGINE(gCur3DSpriteEngine);
                drawX = x + engine->offsetX;
                drawY = y + engine->offsetY;
            }
            gx[12] = posX;
            gx[12] = posY;
            gx[12] = posZ;
            func_02004078(sine, cosine);
            gx[11] = scale;
            gx[11] = scale;
            gx[11] = GX_FX_ONE;
            gx[12] = drawX;
            gx[12] = drawY;
            gx[12] = count;
            heightCode = GetGxTextureSizeCode2(texHeight ? texHeight : height);
            widthCode = GetGxTextureSizeCode(texWidth ? texWidth : width);
            gx[26] = ((texture + (tile << 5)) >> 3) | 0x4c000000 |
                                    (widthCode << 20) | (heightCode << 23) | 0x20000000;
            gx[27] = (palette + (palNum << 5)) >> 4;
            if (centered) func_0207d49c(width, height, flips);
            else DrawTexturedQuad(width, height, flips);
            gx[2] = 1;
            attr += 3;
        }
    }
    REG_GX_MTX_MODE = 3;
    REG_GX_MTX_POP = 1;
    REG_GX_MTX_MODE = 2;
}

void func_0207d49c(s32 a,s32 b,s32 flags){
s32 left=0x800,half=a>>1,ax=a<<12,by=b<<12; s32 right=ax+0x800,top=0x800,bottom=by+0x800;
s16 vright,vy,vleft,y1,x1,y2,x2;
vy=(s16)-b;vleft=(s16)-half;vright=(s16)half;
if(flags&0x1000){left=right-0x1000;right=-top;}
if(flags&0x2000){top=bottom-0x1000;bottom=-0x800;}
y1=(s16)(top>>8);x1=(s16)(left>>8);
y2=(s16)(bottom>>8);x2=(s16)(right>>8);
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000488=(u32)(u16)x1|((u32)(u16)y1<<16);
*(volatile u32 *)0x400048c=(u32)(u16)vleft|((u32)(u16)vy<<16);
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x1|((u32)(u16)y2<<16);
*(volatile u32 *)0x400048c=(u16)vleft;
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x2|((u32)(u16)y2<<16);
*(volatile u32 *)0x400048c=(u16)vright;
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x2|((u32)(u16)y1<<16);
*(volatile u32 *)0x400048c=(u32)(u16)vright|((u32)(u16)vy<<16);
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000504=0;
}

/* Draws a textured quad of width x height at the screen origin (half a pixel
 * inset), writing the GX FIFO directly; the flip flags mirror its texture
 * coordinates on the S or T axis. */
void DrawTexturedQuad(s32 width,s32 height,s32 flags){
s32 posX=width<<12,posY=height<<12; s32 left=GX_FX_HALF,top=GX_FX_HALF,right=posX+GX_FX_HALF,bottom=posY+GX_FX_HALF;
s16 texU,texV,y1,x1,y2,x2;
if(flags&GX_TEXCOORD_FLIP_S){left=right-GX_FX_ONE;right=-top;}
if(flags&GX_TEXCOORD_FLIP_T){top=bottom-GX_FX_ONE;bottom=-GX_FX_HALF;}
texU=(s16)width;texV=(s16)height;y1=(s16)(top>>8);x1=(s16)(left>>8);
y2=(s16)(bottom>>8);x2=(s16)(right>>8);
REG_GX_BEGIN_VTXS=GX_PRIM_QUADS;
REG_GX_TEX_COORD=(u32)(u16)x1|((u32)(u16)y1<<16);
REG_GX_VTX_16=0;
REG_GX_VTX_16=0;
REG_GX_TEX_COORD=(u32)(u16)x1|((u32)(u16)y2<<16);
REG_GX_VTX_16=(u32)(u16)texV<<16;
REG_GX_VTX_16=0;
REG_GX_TEX_COORD=(u32)(u16)x2|((u32)(u16)y2<<16);
REG_GX_VTX_16=(u32)(u16)texU|((u32)(u16)texV<<16);
REG_GX_VTX_16=0;
REG_GX_TEX_COORD=(u32)(u16)x2|((u32)(u16)y1<<16);
REG_GX_VTX_16=(u16)texU;
REG_GX_VTX_16=0;
REG_GX_END_VTXS=0;
}

/* Map a texture's side length in pixels (8..1024) to the size code that the GX
 * TEXIMAGE_PARAM width and height fields store for it; any other length is
 * reported as the 8-pixel code. */
s32 GetGxTextureSizeCode(s32 pixels) {
    switch (pixels) {
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

/* Maps a texture's side length in pixels (GX_TEX_SIZE_*) to the code the GX
 * TEXIMAGE_PARAM size field stores (GX_TEX_CODE_*).  Identical to
 * GetGxTextureSizeCode: the game had a copy of this helper in more than one
 * source file. */
s32 GetGxTextureSizeCode2(s32 size) {
    switch (size) {                                 /* irregular */
    case GX_TEX_SIZE_8:
        return GX_TEX_CODE_8;
    case GX_TEX_SIZE_16:
        return GX_TEX_CODE_16;
    case GX_TEX_SIZE_32:
        return GX_TEX_CODE_32;
    case GX_TEX_SIZE_64:
        return GX_TEX_CODE_64;
    case GX_TEX_SIZE_128:
        return GX_TEX_CODE_128;
    case GX_TEX_SIZE_256:
        return GX_TEX_CODE_256;
    case GX_TEX_SIZE_512:
        return GX_TEX_CODE_512;
    case GX_TEX_SIZE_1024:
        return GX_TEX_CODE_1024;
    default:
        return GX_TEX_CODE_8;
    }
}

/* Transform the 3D point `position` by the 4x4 fixed-point matrix `matrix`,
   then perspective-divide the result by its w component into `projected`. */
void ProjectPoint(s32 *position,s32 *matrix,s32 *projected){
s32 py=position[1],px=position[0],pz=position[2],pw;
projected[0]=(s32)(((s64)px*matrix[0]+(s64)py*matrix[4]+(s64)pz*matrix[8])>>12);projected[0]+=matrix[12];
projected[1]=(s32)(((s64)px*matrix[1]+(s64)py*matrix[5]+(s64)pz*matrix[9])>>12);projected[1]+=matrix[13];
projected[2]=(s32)(((s64)px*matrix[2]+(s64)py*matrix[6]+(s64)pz*matrix[10])>>12);projected[2]+=matrix[14];
pw=(s32)(((s64)px*matrix[3]+(s64)py*matrix[7]+(s64)pz*matrix[11])>>12);pw+=matrix[15];
projected[0]=((s64)projected[0]<<12)/pw;
projected[1]=((s64)projected[1]<<12)/pw;
projected[2]=((s64)projected[2]<<12)/pw;
}

void func_0207d95c(M2C_UNK *arg0) {
    extern M2C_UNK data_02101874;
    M2C_UNK *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = &data_02101874;
    }
    *(s32 *)0x04000580 = M2C_FIELD(var_r0, s32 *, 0) | (M2C_FIELD(var_r0, s32 *, 4) << 8) | (M2C_FIELD(var_r0, s32 *, 8) << 0x10) | (M2C_FIELD(var_r0, s32 *, 0xC) << 0x18);
}

/* Build the map view's orthographic projection matrix: load the fixed Q12
 * projection into `matrix` and the GX projection stack, then fold in the
 * view's zoom (a Q12 scale on each axis) and its scroll offset (a Q12
 * x/y/z translation). */
void BuildMapViewProjection(s32 *matrix, s32 *zoom, s32 *offset) {
    void MTX_TransApply44(s32 *, s32 *, s32, s32, s32);
    void MatrixScale44(s32 *, s32 *, s32, s32, s32);
    void GX_SetOrthoProjection(s32, s32, s32, s32, s32, s32, s32, s32, s32 *);

    REG_GX_MTX_MODE = 0;
    REG_GX_MTX_IDENTITY = 0;
    GX_SetOrthoProjection(-0x1200, 0x1200, -0x1800, 0x1800, 0, 0x2000, 0x1000, 1, matrix);
    MTX_TransApply44(matrix, matrix, offset[0], offset[1], offset[2]);
    MatrixScale44(matrix, matrix, zoom[0], zoom[1], zoom[2]);
    REG_GX_MTX_STORE = 0;
}

void UploadTextureBank(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK GX_BeginLoadTex();
    M2C_UNK LoadTextureBankBlock(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GX_EndLoadTex();
    GX_BeginLoadTex();
    LoadTextureBankBlock(arg0, arg1, arg2);
    GX_EndLoadTex();
}

/* Upload `size` bytes from `src` into the main OBJ extended palette at byte
 * `offset`: unaligned ranges are written halfword by halfword, aligned ones with
 * the palette's word copy. */
void CopyMainOBJExtPalette(s32 src, s32 offset, s32 size) {
    M2C_UNK GX_BeginLoadTexPltt();
    M2C_UNK GX_LoadTexPltt(s32, s32, s32);
    M2C_UNK GX_EndLoadTexPltt();
    M2C_UNK CopyMainOBJExtPaletteHalfword(s32, s32);
    s32 remaining;
    s32 vramOffset;
    s32 source;

    source = src;
    vramOffset = offset;
    remaining = size;
    if ((source & 2) || (vramOffset & 2) || (remaining & 2)) {
        if (remaining == 0) {
            return;
        }
        do {
            CopyMainOBJExtPaletteHalfword(source, vramOffset);
            source += 2;
            vramOffset += 2;
            remaining -= 2;
        } while (remaining != 0);
        return;
    }
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(source, vramOffset, remaining);
    GX_EndLoadTexPltt();
}

/* Copy one halfword from `src` into the main-engine OBJ extended palette at byte
 * `offset`: release the palette's bank grant, get the VRAM base of the banks it
 * gave back, write the halfword and re-grant the bank.  Used for the halfword
 * writes that GX_LoadTexPltt cannot do. */
M2C_UNK CopyMainOBJExtPaletteHalfword(s32 src, s32 offset) {
    s32 GX_ReleaseBankForOBJExtPltt(void);
    void GX_SetBankForOBJExtPltt(s32);
    s32 banks = GX_ReleaseBankForOBJExtPltt();
    u32 base = (u32) gVramBankBaseTable[banks >> 4] << 12;
    gObjExtPlttWriteState[1] = banks;
    gObjExtPlttWriteState[0] = base;
    *(u16 *) (base + (offset & ~1)) = *(u16 *) src;
    GX_SetBankForOBJExtPltt(banks);
}

/* Point the terrain tile lookup at the table for the current map's tileset kind
 * (the unique tilesets of kinds 4..9, the normal one otherwise) and record the
 * kind as the loaded tileset. */
void SetTerrainTileset(u8 tileset) { switch(M2C_FIELD(*gCurrentMap,u8 *,MAP_TILESET)) {
case 4: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ec6bc;break;
case 5: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ecabc;break;
case 6: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ecebc;break;
case 7: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ed2bc;break;
case 8: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ed6bc;break;
case 9: M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020edabc;break;
default:M2C_FIELD(&gTerrainTileset,const u8 **,4)=data_020ec2bc;break;
} gTerrainTileset=tileset; }

u8 GetTerrainTileset(void) {
    extern u8 gTerrainTileset;
    return gTerrainTileset;
}

#pragma push
#pragma opt_strength_reduction off
/* 8-neighbour connected-terrain autotile: collects which of the eight surrounding
 * tiles carry the 0x20000 connection class flag into an 8-bit mask, then checks
 * for a lone cardinal connection whose neighbour carries the 0x80000 end-cap
 * class flag and returns that end-cap tile, else the tile for the whole mask. */
u16 GetTerrainConnectionVariant(s32 x, s32 y) {
    TerrainCoords48 neighbors8;
    TerrainCoords24 neighbors4;
    s32 j;
    u8 endMask, mask = 0;

    neighbors8 = *(const TerrainCoords48 *)gNeighborOffsets8;
    {
        void **maps = gCurrentMap;
        const u16 *tileAttr = ((const u16 **)&gTerrainTileset)[1];
        {
            s32 i;
            s16 *p = neighbors8.coords;
            for (i = 0; i < 8; i++, p += 3) {
                s32 nx = x + p[0];
                s32 ny = y + p[1];
                if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*maps, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*maps, u16 *, MAP_HEIGHT)) {
                    u16 off = M2C_FIELD((u8 *)*maps + ny * 2, u16 *, MAP_ROW_OFFSETS);
                    u16 tile = M2C_FIELD((u8 *)*maps + (nx + off) * 2, u16 *, MAP_CELL_TILE_ID);
                    if ((((const u32 (*)[2])gTerrainClassFlags)[tileAttr[tile]][0] & 0x20000) == 0) {
                        mask |= 1 << i;
                        mask &= 0xff;
                    }
                }
            }
        }
        if (mask != 0) {
            s32 sub = mask & 0x5a;
            switch (sub) {
            case 2:
                if (!(mask & 0xe0)) goto do_second;
                goto skip_second;
            case 8:
                if (!(mask & 0x94)) goto do_second;
                goto skip_second;
            case 16:
                if (!(mask & 0x29)) goto do_second;
                goto skip_second;
            case 64:
                if (mask & 0x07) goto skip_second;
                break;
            default:
                goto skip_second;
            }
do_second:
            {
                endMask = 0;
                neighbors4 = *(const TerrainCoords24 *)gTerrainNeighborOffsets;
                {
                    s16 *p = neighbors4.coords;
                    for (j = 0; j < 4; j++, p += 3) {
                        s32 nx = x + p[0];
                        s32 ny = y + p[1];
                        if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(*maps, u16 *, MAP_WIDTH) && ny < M2C_FIELD(*maps, u16 *, MAP_HEIGHT)) {
                            u16 off = M2C_FIELD((u8 *)*maps + ny * 2, u16 *, MAP_ROW_OFFSETS);
                            u16 tile = M2C_FIELD((u8 *)*maps + (nx + off) * 2, u16 *, MAP_CELL_TILE_ID);
                            if ((((const u32 (*)[2])gTerrainClassFlags)[tileAttr[tile]][0] & 0x80000) != 0) {
                                endMask |= 1 << j;
                                endMask &= 0xff;
                            }
                        }
                    }
                    {
                        u16 val = gTerrainEndTileTable[endMask];
                        if (val != 0) {
                            return val;
                        }
                    }
                }
            }
        }
skip_second:
        return gTerrainVariantTable[mask];
    }
}
#pragma pop
