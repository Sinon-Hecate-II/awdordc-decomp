/* 20 functions from 0x02097C50 to 0x02098BD4 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

void func_02097c50(u32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 FindScenePanel(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK);
 s32 t=FindScenePanel((u16)arg0); if(!t)return; func_0209e25c(t,2,arg1,arg2);
}

void func_02097c84(u32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 FindScenePanel(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK);
 s32 t=FindScenePanel((u16)arg0); if(!t)return; func_0209e25c(t,1,arg1,arg2);
}

void HideMenuCursor(u32 arg0) { s32 FindScenePanel(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK); s32 t=FindScenePanel((u16)arg0); if(!t)return; func_0209e25c(t,0,0,0); }

/* Returns the tile row (5 or 6) at which the given character's face graphics
 * start in the 32-tile-wide face tile buffer. */
s32 GetFaceTileRow(u32 character){switch(character){
case 0: return 6;
case 1: return 6;
case 2: return 6;
case 3: return 6;
case 4: return 6;
case 9: return 6;
case 8: return 6;
case 6: return 5;
case 5: return 6;
case 11: return 6;
case 10: return 6;
case 12: return 6;
case 15: return 6;
case 16: return 6;
case 7: return 6;
case 13: return 6;
case 17: return 6;
case 18: return 5;
case 14: return 5;
case 19: return 5;
case 20: return 6;
case 21: return 6;
case 22: return 6;
case 23: return 6;
case 24: return 5;
case 25: return 6;
case 26: return 6;
case 27: return 6;
case 28: return 6;
case 29: return 6;
case 30: return 6;
case 31: return 6;
case 32: return 6;
default:return 5;}}

/* Maps a unit index (0..32) to one of the four sound ids 0x10026..0x10029 used
   as that unit's voice/effect group. */
s32 func_02097e84(u32 unitIndex){switch(unitIndex){
case 0:return 0x10026;
case 1:return 0x10026;
case 2:return 0x10027;
case 3:return 0x10029;
case 4:return 0x10028;
case 9:return 0x10027;
case 8:return 0x10026;
case 6:return 0x10026;
case 5:return 0x10028;
case 11:return 0x10028;
case 10:return 0x10028;
case 12:return 0x10027;
case 15:return 0x10028;
case 16:return 0x10027;
case 7:return 0x10026;
case 13:return 0x10026;
case 17:return 0x10026;
case 18:return 0x10027;
case 14:return 0x10027;
case 19:return 0x10027;
case 20:return 0x10026;
case 21:return 0x10026;
case 22:return 0x10026;
case 23:return 0x10026;
case 24:return 0x10029;
case 25:return 0x10026;
case 26:return 0x10026;
case 27:return 0x10026;
case 28:return 0x10026;
case 29:return 0x10026;
case 30:return 0x10026;
case 31:return 0x10026;
case 32:return 0x10029;
default:return 0x10026;}}

/* Returns the file path (as s32) of the character face texture for the given unit index, or 0 if that unit has no face. Indices map to /face/<name> strings: 0 null, 1 edo, 2 brown, 3 rin, 4 cat, 5 atory, 6 trak, 7 carlyle, 8 dita, 9 jig, 10 agat, 11 eriza, 12 mengel, 13 cole, 14 loot, 15 cat_nazo, 16 morit, 17 geral, 18 belie, 19 mayor, 20-24 sol_1..sol_5, 25-27 boy_1..boy_3, 28-30 man_1..man_3, 31-32 girl_1/girl_2, 33 system, 34 nazo. */
s32 GetFaceTexturePath(u32 unit){
extern u8 data_0210302c[];
extern u8 data_02103038[];
extern u8 data_02103044[];
extern u8 data_02103050[];
extern u8 data_0210305c[];
extern u8 data_02103068[];
extern u8 data_02103074[];
extern u8 data_02103080[];
extern u8 data_0210308c[];
extern u8 data_02103098[];
extern u8 data_021030a4[];
extern u8 data_021030b0[];
extern u8 data_021030c0[];
extern u8 data_021030d0[];
extern u8 data_021030dc[];
extern u8 data_021030ec[];
extern u8 data_021030f8[];
extern u8 data_02103104[];
extern u8 data_02103110[];
extern u8 data_0210311c[];
extern u8 data_02103128[];
extern u8 data_02103134[];
extern u8 data_02103140[];
extern u8 data_0210314c[];
extern u8 data_02103158[];
extern u8 data_02103164[];
extern u8 data_02103170[];
extern u8 data_0210317c[];
extern u8 data_02103188[];
extern u8 data_02103194[];
extern u8 data_021031a0[];
extern u8 data_021031ac[];
extern u8 data_021031bc[];
extern u8 data_021031cc[];
extern u8 data_021031dc[];
switch(unit){
case 0:return (s32)data_0210302c;
case 1:return (s32)data_02103038;
case 2:return (s32)data_02103044;
case 3:return (s32)data_02103050;
case 4:return (s32)data_0210305c;
case 9:return (s32)data_02103068;
case 8:return (s32)data_02103074;
case 6:return (s32)data_02103080;
case 5:return (s32)data_0210308c;
case 11:return (s32)data_02103098;
case 10:return (s32)data_021030a4;
case 12:return (s32)data_021030b0;
case 15:return (s32)data_021030c0;
case 16:return (s32)data_021030d0;
case 7:return (s32)data_021030dc;
case 13:return (s32)data_021030ec;
case 17:return (s32)data_021030f8;
case 18:return (s32)data_02103104;
case 14:return (s32)data_02103110;
case 19:return (s32)data_0210311c;
case 20:return (s32)data_02103128;
case 21:return (s32)data_02103134;
case 22:return (s32)data_02103140;
case 23:return (s32)data_0210314c;
case 24:return (s32)data_02103158;
case 25:return (s32)data_02103164;
case 26:return (s32)data_02103170;
case 27:return (s32)data_0210317c;
case 28:return (s32)data_02103188;
case 29:return (s32)data_02103194;
case 30:return (s32)data_021031a0;
case 31:return (s32)data_021031ac;
case 32:return (s32)data_021031bc;
case 33:return (s32)data_021031cc;
case 34:return (s32)data_021031dc;
default:return 0;}}

/* Name of the face layout graphics file to load for a face layout type, or 0
 * for an unknown type.  The types are, in order: info.cg (0), select.cg (1),
 * btl_n.cg (2), btl_s.cg (3), btl_a.cg (4), talk_n.cg (5), talk_s.cg (6),
 * talk_a.cg (7), body_n.cg (8), body_s.cg (9), body_a.cg (10) and break.cg (11). */
s32 GetFaceLayoutFile(s32 layout) {
    extern M2C_UNK data_021031e8, data_021031f0, data_021031fc, data_02103208, data_02103214, data_02103220, data_0210322c, data_02103238, data_02103244, data_02103250, data_0210325c, data_02103268;
    switch (layout) {
    case 0: return (s32)&data_021031e8;
    case 1: return (s32)&data_021031f0;
    case 2: return (s32)&data_021031fc;
    case 3: return (s32)&data_02103208;
    case 4: return (s32)&data_02103214;
    case 5: return (s32)&data_02103220;
    case 6: return (s32)&data_0210322c;
    case 7: return (s32)&data_02103238;
    case 8: return (s32)&data_02103244;
    case 9: return (s32)&data_02103250;
    case 10: return (s32)&data_0210325c;
    case 11: return (s32)&data_02103268;
    default: return 0;
    }
}

/* Returns a filename string from one of the face/skin filename tables based on a transformed index and type. */
s32 GetFacePaletteFile(s32 index, s32 type) {
    s32 func_020bf8cc(s32);
    extern s32 data_02102ffc[], data_0210300c[], data_0210301c[];
    if (index == 15) {
        index = 4;
    }
    index = func_020bf8cc(index);
    switch (type) {
    case 0: return data_02102ffc[index];
    case 1: return data_02102ffc[index];
    case 2: return data_02102ffc[index];
    case 3: return data_02102ffc[index];
    case 4: return data_02102ffc[index];
    case 5: return data_0210300c[index];
    case 6: return data_0210300c[index];
    case 7: return data_0210300c[index];
    case 8: return data_02102ffc[index];
    case 9: return data_02102ffc[index];
    case 10: return data_02102ffc[index];
    case 11: return data_0210301c[index];
    default: return 0;
    }
}

/* Returns the pixel width of a face layout's texture (0 for an unknown
 * layout); the layout types are FACE_LAYOUT_*. */
s32 GetFaceLayoutWidth(s32 layout) {
    switch ((u32)layout) {
    case FACE_LAYOUT_INFO: return 48;
    case FACE_LAYOUT_SELECT: return 56;
    case FACE_LAYOUT_BTL_N: return 72;
    case FACE_LAYOUT_BTL_S: return 72;
    case FACE_LAYOUT_BTL_A: return 72;
    case FACE_LAYOUT_TALK_N: return 48;
    case FACE_LAYOUT_TALK_S: return 48;
    case FACE_LAYOUT_TALK_A: return 48;
    case FACE_LAYOUT_BODY_N: return 160;
    case FACE_LAYOUT_BODY_S: return 160;
    case FACE_LAYOUT_BODY_A: return 160;
    case FACE_LAYOUT_BREAK: return 256;
    default: return 0;
    }
}

/* Returns the pixel height of a face layout's texture (0 for an unknown
 * layout); the layout types are FACE_LAYOUT_*. */
s32 GetFaceLayoutHeight(s32 layout) {
    switch ((u32)layout) {
    case FACE_LAYOUT_INFO: return 16;
    case FACE_LAYOUT_SELECT: return 56;
    case FACE_LAYOUT_BTL_N: return 64;
    case FACE_LAYOUT_BTL_S: return 64;
    case FACE_LAYOUT_BTL_A: return 64;
    case FACE_LAYOUT_TALK_N: return 48;
    case FACE_LAYOUT_TALK_S: return 48;
    case FACE_LAYOUT_TALK_A: return 48;
    case FACE_LAYOUT_BODY_N: return 192;
    case FACE_LAYOUT_BODY_S: return 192;
    case FACE_LAYOUT_BODY_A: return 192;
    case FACE_LAYOUT_BREAK: return 64;
    default: return 0;
    }
}

s32 GetFaceLayoutSize(s32 arg0) {
    s32 GetFaceLayoutWidth();
    s32 GetFaceLayoutHeight(s32);
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = GetFaceLayoutWidth(arg0);
    var_r0 = temp_r4 * GetFaceLayoutHeight(arg0);
    if (arg0 == 1) {
        var_r0 += temp_r4;
    }
    return var_r0;
}

void LoadFaceTexture(s32 unused,s32 a,s32 b){s32 GetFaceTexturePath();s32 GetFaceLayoutFile(s32);M2C_UNK SetFileDirectory(s32);void LoadDecompressedFileTo(s32,s32);s32 x,y;x=GetFaceTexturePath();y=GetFaceLayoutFile(a);if(!x)return;SetFileDirectory(x);LoadDecompressedFileTo(y,b);}

#pragma opt_strength_reduction off
void CopyFaceTiles(s32 src,s32 dst,u32 w,u32 h,u8 half){
void MI_CpuCopy32(s32,s32,u32);
s32 y0,col0,tile0,row0,width0,height0,x0;
s32 tile1,width1,height1,y1,x1,row1;
if(w<=1){MI_CpuCopy32(src,dst,(half?32:64)*(w*h));return;}
if(half){
height0=(u16)(h*8);
y0=0;if(height0<=0)return;
width0=(u16)(w*4);row0=0;
do{
x0=0;if(width0>0){tile0=(y0>>3)*w;col0=0;do{
*(u32 *)(dst+x0+row0)=*(u32 *)(src+((col0+tile0)<<5)+(x0&3)+((y0&7)<<2));
col0++;x0+=4;}while(x0<width0);}
y0++;row0+=width0;
}while(y0<height0);
}else{
height1=(u16)(h*8);
y1=0;if(height1<=0)return;
width1=(u16)(w*8);row1=0;
do{
x1=0;if(width1>0){tile1=(y1>>3)*w;do{
*(u32 *)(dst+x1+row1)=*(u32 *)(src+((tile1+(x1>>3))<<6)+(x1&7)+((y1&7)<<3));
x1+=4;}while(x1<width1);}
y1++;row1+=width1;
}while(y1<height1);
}
}
/* Loads a character's compressed face graphics and copies the tiles into the
 * destination buffer as 2x2 blocks (plain face) or 1x4 blocks (the other layout
 * types).  Returns the loaded size in bytes, or 0 when the character has no face. */
s32 LoadFaceGraphics(s32 character, s32 type, s32 dst) {
    s32 GetFaceTexturePath();
    s32 GetFaceLayoutSize(s32);
    void LoadDecompressedFileTo(s32, s32);
    M2C_UNK SetFileDirectory(s32);
    void CopyFaceTiles(s32, s32, u32, u32, u8);
    s32 HeapAllocBlock(void);
    M2C_UNK HeapFreeBlock(s32);

    s32 size, faceDir, faceFile, buf, i0, off0, n0, off1, n1, i1;

    faceDir = GetFaceTexturePath();
    faceFile = GetFaceLayoutFile(type);
    size = 0;
    if (faceDir) {
        size = GetFaceLayoutSize(type);
        buf = HeapAllocBlock();
        SetFileDirectory(faceDir);
        LoadDecompressedFileTo(faceFile, buf);
        switch (type) {
        case 0:
            i0 = 0;
            n0 = size >> 8;
            if (n0 > 0) {
                off0 = 0;
                do {
                    CopyFaceTiles(buf + (off0 << 6), dst + (off0 << 6), 2, 2, 0);
                    i0++;
                    off0 += 4;
                } while (i0 < n0);
            }
            break;
        case 2:
        case 3:
        case 4:
            i1 = 0;
            n1 = size >> 8;
            if (n1 > 0) {
                off1 = 0;
                do {
                    CopyFaceTiles(buf + (off1 << 6), dst + (off1 << 6), 1, 4, 0);
                    i1++;
                    off1 += 4;
                } while (i1 < n1);
            }
            break;
        }
        HeapFreeBlock(buf);
    }
    return size;
}
/* Fills a tile-map rectangle for the given layout index, optionally mirroring it. */
void FillFaceTileMap(u32 layout, s32 col, s32 row, s32 vramBase, u16 startTile, u16 palette, u8 mirror) {
    s32 widthPx;
    M2C_UNK func_02080b38(s32, u16, u16);
    s32 heightPx;
    M2C_UNK FillChunkedTileRect(s32, u16, u16, u16, s32, s32, s32);
    unsigned int offset;
    s32 tileWidth;
    register s32 tileHeight;
    s32 cols;
    s32 rows;

    widthPx = GetFaceLayoutWidth(layout);
    tileWidth = (s32) (widthPx + ((u32) (widthPx >> 2) >> 0x1D)) >> 3;
    heightPx = GetFaceLayoutHeight(layout);
    tileHeight = (s32) (heightPx + ((u32) (heightPx >> 2) >> 0x1D)) >> 3;
    cols = tileWidth;
    rows = tileHeight;
    switch (layout) {
    default:
        break;
    case 1:
        cols = 1;
        rows = 4;
        break;
    case 0:
    case 5:
    case 6:
    case 7:
        cols = 2;
        rows = 2;
        break;
    case 2:
    case 3:
    case 4:
        cols = 1;
        rows = 4;
        break;
    case 8:
    case 9:
    case 10:
        cols = 4;
        rows = 8;
        break;
    case 11:
        cols = 8;
        rows = 8;
        break;
    }
    offset = vramBase + (col * 2) + (row << 6);
    FillChunkedTileRect(offset, (u16) tileWidth, (u16) tileHeight, (u16) cols, (s32) (u16) rows, (s32) startTile, (s32) palette);
    if (!mirror) {
        return;
    }
    func_02080b38(offset, (u16) tileWidth, (u16) tileHeight);
}

/* Applies the selected face palette effects in place to `palette`: `effects` holds
 * FACE_EFFECT_* bits (dim levels, sepia, grayscale) and `length` is the palette's
 * size in bytes. */
void ApplyPaletteEffects(u16 *palette, u32 effects, s32 length) {
    void BlendPalette(u16 *, s32, s32, s32, s32);
    void ApplySepiaToPalette(u16 *, s32);
    void ApplyGrayscaleToPalette(u16 *, s32);
    if (effects & FACE_EFFECT_DIM) {
        BlendPalette(palette, 0, 0xA, 6, length);
    }
    if (effects & FACE_EFFECT_DIM_HALF) {
        BlendPalette(palette, 0, 8, 8, length);
    }
    if (effects & FACE_EFFECT_DIM_MOST) {
        BlendPalette(palette, 0, 4, 0xC, length);
    }
    if (effects & FACE_EFFECT_BLACK) {
        BlendPalette(palette, 0, 0, 0x10, length);
    }
    if (effects & FACE_EFFECT_SEPIA) {
        ApplySepiaToPalette(palette, length);
    }
    if (!(effects & FACE_EFFECT_GRAY)) {
        return;
    }
    ApplyGrayscaleToPalette(palette, length);
}

/* Loads a character's face palette file for the given layout, applies the
 * FACE_EFFECT_* tints, and queues the 512-byte palette for upload into an
 * extended palette slot at `paletteOffset` pages within it. */
void LoadFacePalette(s32 faceId,s32 layout,s32 paletteSlot,s32 paletteOffset,u8 effects){
s32 GetFaceTexturePath();s32 GetFacePaletteFile(s32,s32);M2C_UNK SetFileDirectory(s32);s32 LoadFileToNewBuffer(s32,s32);void QueueBGExtPaletteUpload(s32,s32,u16,s32,s32);
s32 faceDir,palette;u16 offset;
faceDir=GetFaceTexturePath(faceId);
palette=GetFacePaletteFile(faceId,layout);
offset=paletteOffset<<9;
if(!faceDir)return;
SetFileDirectory(faceDir);
palette=LoadFileToNewBuffer(palette,512);
ApplyPaletteEffects(palette,effects,512);
QueueBGExtPaletteUpload(palette,paletteSlot,offset,512,1);}

/* Loads a character's face palette file for the given layout, applies the
 * FACE_EFFECT_* tints, and queues the 512-byte palette for upload into OBJ
 * extended palette page `palettePage`. */
void LoadFacePaletteAt(s32 faceId, s32 layout, s32 palettePage, s32 effects) {
    s32 GetFaceTexturePath();
    s32 GetFacePaletteFile(s32, s32);
    M2C_UNK SetFileDirectory(s32);
    s32 LoadFileToNewBuffer(s32, s32);
    void QueueOBJExtPaletteUpload(s32, s32, u16, s32, s32);
    s32 faceDir, palette;
    u16 offset;

    faceDir = GetFaceTexturePath();
    palette = GetFacePaletteFile(faceId, layout);
    offset = palettePage << 9;
    if (!faceDir) return;
    SetFileDirectory(faceDir);
    palette = LoadFileToNewBuffer(palette, 512);
    ApplyPaletteEffects(palette, effects, 512);
    QueueOBJExtPaletteUpload(palette, 0, offset, 512, 1);
}

void func_02098b4c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SetFileDirectory(s32);
    M2C_UNK LoadFileToAddress(s32, M2C_UNK);
    s32 GetFaceTexturePath();
    s32 GetFacePaletteFile(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = GetFaceTexturePath();
    temp_r4 = GetFacePaletteFile(arg0, arg1);
    if (temp_r5 == 0) {
        return;
    }
    SetFileDirectory(temp_r5);
    LoadFileToAddress(temp_r4, arg2);
}

void func_02098b94(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    void LoadFaceTexture(M2C_UNK, M2C_UNK, s32);
    void LoadFacePaletteAt(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    LoadFaceTexture(arg0, arg1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg2);
    LoadFacePaletteAt(arg0, arg1, arg3, 0);
}

