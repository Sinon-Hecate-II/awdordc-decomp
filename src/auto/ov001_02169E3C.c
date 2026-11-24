/* 19 functions from 0x02169E3C to 0x0216AD74 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { s32 x,y; } TextSize;
typedef struct { s8 x, y; } TextDirection;
typedef struct { u32 a:8; u32 b:8; u32 c:16; } TileOrigin;

#pragma scheduling off
void func_ov001_02169e3c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_ov001_0216939c(s32, s32, s32, s32, s32, s32);
    void func_ov001_021694b0(s32, s32, s32, s32, s32, s32, s32);
    TileOrigin value;
    s32 y0,x1,y1,ye,f0,bx,x0,sy,sx,f8,f4,stride,bpp;
    s32 x,sh,col,xe,by,off,xo,wd,t; u32 color,c;

    bpp = M2C_FIELD(arg0, u8 *, 0xc);
    x1 = arg2 + arg4;
    y1 = arg3 + arg5;
    x0 = arg2 & ~7;
    y0 = arg3 & ~7;
    c = arg1;
    if (bpp == 4) c |= c << 4;
    c |= c << 8;
    arg1 = c | (c << 16);
    ye = (y1 + 7) & ~7;
    stride = (bpp << 6) / 8;
    bx = x0 / 8;
    by = y0 / 8;
    value = M2C_FIELD(arg0, TileOrigin *, 0x10);
    xe = (x1 + 7) & ~7;
    f4 = M2C_FIELD(arg0, s32 *, 4);
    f8 = M2C_FIELD(arg0, s32 *, 8);
    f0 = M2C_FIELD(arg0, s32 *, 0);
    sx = value.a;
    sy = value.b;
    if (y0 >= ye) return;
    do {
        off = y0 < arg3 ? arg3 - y0 : 0;
        t = y1 - y0;
        if (t > 8) t = 8;
        sh = t - off;
        col = bx;
        for (x = x0; x < xe; x += 8) {
            t = func_ov001_0216939c(col, by, f4, f8, sx, sy);
            xo = x < arg2 ? arg2 - x : 0;
            wd = x1 - x;
            if (wd > 8) wd = 8;
            func_ov001_021694b0(stride * t + f0, xo, off, wd - xo, sh, arg1, bpp);
            col++;
        }
        by++;
        y0 += 8;
    } while (y0 < ye);
}
#pragma scheduling reset
void func_ov001_0216a030(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    M2C_FIELD(arg0, s8 *, 0xC) = (s8) arg4;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg5;
    M2C_FIELD(arg0, s32 *, 0x10) = arg6;
}

/* Draw one glyph of `font` at (x, y) in `color` on the panel and return the
 * pixels the pen advances. Looks the character's glyph index up in the font's
 * character map (falling back to the font's default glyph), takes its width
 * record and its bitmap, shifts the origin for the glyph's rotation mode and
 * hands the pair to the panel's glyph operation. */
s32 DrawTextGlyph(Ov001TextPanel *panel,Ov001Font *font,s32 x,s32 y,s32 color,s32 ch){
s32 GetFontGlyphIndex(void*,u16);Ov001GlyphMetric *GetFontGlyphMetric(void*,s32);
s32 n;Ov001Glyph glyph;u8 *run;
n=GetFontGlyphIndex(font,*(u16 *)&ch);
if(n==65535)n=font->resource->defaultChar;
glyph.metric=GetFontGlyphMetric(font,n);
run=font->resource->glyphRunTable;
glyph.bitmap=run+8+n*M2C_FIELD(run,u16*,2);
run=font->resource->glyphRunTable;
switch(run[7]){
case 0:case 7:x+=glyph.metric->left;break;
case 1:case 2:x-=run[0];y+=glyph.metric->left;break;
case 3:case 4:x-=glyph.metric->left+glyph.metric->width;y-=run[1];break;
case 5:case 6:y-=glyph.metric->left+run[1];break;
}
panel->ops->drawGlyph(panel,font,x,y,color,&glyph);
return glyph.metric->advance;
}

void func_ov001_0216a17c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern s32 data_ov001_0218c9cc;
    func_ov001_0216a030(arg0, arg1, arg2, arg3, arg4, (s32)&data_ov001_0218c9cc, arg2);
}

void func_ov001_0216a1a8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
extern u8 data_ov001_0218c9e4[];
extern s32 data_ov001_0218c9d8;
struct { u32 a:8; u32 b:8; u32 c:16; } value;
s32 x,y; u8 *p;
x=3; if(arg2<8) {x=0; while ((u32)arg2>>(x+1)) ++x;}
y=3; if(arg3<8) {y=0; while ((u32)arg3>>(y+1)) ++y;}
p=data_ov001_0218c9e4+y*8+x*2;
value.a=p[0]; value.b=p[1];
func_ov001_0216a030(arg0,arg1,arg2,arg3,arg4,(s32)&data_ov001_0218c9d8,*(s32*)&value);
}
void func_ov001_0216a230(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5,s32 arg6,u32 arg7) {
M2C_UNK func_ov001_0216a2e0(s32,s32,s32,s32,s32,s32);
s32 endX,endY,tile,y,row,col,x; u16 *p; u32 palette;
y=arg4;tile=arg6;
if(arg5<=32){func_ov001_0216a2e0(arg0+(arg5*y+arg3)*2,arg1,arg2,arg5,tile,arg7);return;}
endY=y+arg2;endX=arg3+arg1;
palette=arg7<<28;
if(y>=endY)return;
do{
row=y<32?y:y+32;x=arg3;p=(u16 *)(arg0+(row<<6));
if(arg3<endX)do{
col=x<32?x:x+0x3e0;
*(volatile u16 *)&p[col]=tile|(palette>>16);
x++;tile++;
}while(x<endX);
y++;
}while(y<endY);
}

#pragma scheduling off
s32 func_ov001_0216a2e0(s32 base,s32 w,s32 h,s32 stride,s32 tile,s32 pal) {
u16 v;s32 x,y;u16 *p;
pal=(u32)pal<<28;y=0;
if(h<=0)return base;
do{p=(u16 *)base;x=0;if(w>0){do{v=tile|((u32)pal>>16);x++;tile++;*p++=v;}while(x<w);}y++;base+=stride*2;}while(y<h);
return base;
}
#pragma scheduling reset
s32 func_ov001_0216a33c(u32 a,u32 b) {
 u32 x,z,t,s,u,v;
 register u32 y;
 y=b>>3;
 x=a>>3;
 z=0;
 t=((a&2)>>1)+(a&1);
 u=a&4;
 z=x*y+z;
 z=y*(t*2+(u>>2))+z;
 s=((b&2)>>1)+(b&1);
 v=b&4;
 z=x*(s*2+(v>>2))+z;
 return (t+(u>>2))*(s+(v>>2))+z;
}
#pragma intrinsic on
s32 Ov001_FillTileRect(void *dst,s32 w,s32 h,s32 x,s32 y,s32 mode,s32 tile,s32 shift){
extern u8 data_ov001_0218c9e4[];s32 func_ov001_02169494(void *);
s32 sx,sy,wx,hy,n,i,nx,area,rowY;
u32 aw,ah;
s32 count,ny,j,step;
u8 *p;
wx=w<8?31-__CLZ(w):3;hy=h<8?31-__CLZ(h):3;
p=data_ov001_0218c9e4+hy*8+wx*2;sx=p[0];sy=p[1];
aw=w&(-1U<<sx);ah=h&(-1U<<sy);step=mode==0?1:2;count=0;
n=func_ov001_02169494(p);nx=w>>sx;ny=h>>sy;area=(step<<sx)<<sy;
j=0;
goto checkRow;
row:
rowY=(y+(j<<sy)*8)&255;
i=0;
goto checkColumn;
column:
{
u32 colX=(u32)(x+(i<<sx)*8)<<23;
i++;
M2C_FIELD(dst,u32 *,0)=(((M2C_FIELD(dst,u32 *,0)&0xfe00ff00)|rowY|(colX>>7))&0x3fff3fff)| (u32)n;
M2C_FIELD(dst,u16 *,4)=(M2C_FIELD(dst,u16 *,4)&~0x3ff)|tile;
tile+=area>>shift;
M2C_FIELD(dst,u32 *,0)=(M2C_FIELD(dst,u32 *,0)&~0x2000)|(mode<<13);
dst=(u8 *)dst+8;
}
checkColumn:
if(i<nx)goto column;
j++;
checkRow:
if(j<ny)goto row;
count+=nx*ny;
if(aw<(u32)w){s32 rem=w-aw;n=Ov001_FillTileRect(dst,rem,ah,x+aw*8,y,mode,tile,shift);dst=(u8 *)dst+n*8;tile+=((u32)(step*rem*ah))>>shift;count+=n;}
if(ah<(u32)h){s32 rem=h-ah;n=Ov001_FillTileRect(dst,aw,rem,x,y+ah*8,mode,tile,shift);dst=(u8 *)dst+n*8;tile+=((u32)(step*aw*rem))>>shift;count+=n;}
if(aw<(u32)w&&ah<(u32)h){n=Ov001_FillTileRect(dst,w-aw,h-ah,x+aw*8,y+ah*8,mode,tile,shift);count+=n;}
return count;
}
/* Draw one line of a bitmap font's text: decode characters from the text cursor
 * and draw each glyph at (x, y) in colour, advancing the pen along dir, until the
 * text ends or a newline (10) is reached. When `rest` is given it receives the
 * cursor just past the newline, or 0 when the text ended. */
void DrawFontTextLine(Ov001TextState *state, s32 startX, s32 startY, s32 color, s32 text, s32 *rest, TextDirection dir) {

s32 cursor,lineEnd;
s32 step,spacing;Ov001Font *font;s32 (*decode)(s32 *);s32 ch,x,y;
spacing=state->letterSpacing;font=state->font;cursor=text;
decode=font->decodeChar;
x=startX;y=startY;lineEnd=color;
ch=decode(&cursor);
if(ch!=0){loop:
if(ch!=10){step=spacing+DrawTextGlyph(state->panel,font,x,y,lineEnd,ch);x+=step*dir.x;y+=step*dir.y;ch=decode(&cursor);if(ch!=0)goto loop;}}
if(rest==0)return;
*rest=ch==10?cursor:0;
}

/* Draws a multi-line string: each line is optionally centred or right-aligned
   within blockWidth, and successive lines advance perpendicular to dir by the
   font line height plus the state's line spacing. */
void DrawTextMultiline(Ov001TextState *state, s32 x, s32 y, s32 blockWidth, s32 color, s32 flags, s32 text, TextDirection dir){
s32 GetTextLineWidth(s32,s32,s32,s32);
s32 line; s32 stepX,stepY,lineX,lineY,offsetX,offsetY,delta,lineStep; s32 startX,startY,curColor;
lineStep=state->lineSpacing+state->font->resource->lineHeight;
stepX=lineStep*-dir.y;stepY=lineStep*dir.x;startX=x;startY=y;line=text;curColor=color;
if(!text)return;
offsetX=0;offsetY=0;
do{
lineX=startX+offsetX;lineY=startY+offsetY;
if(flags&OV001_TEXT_ALIGN_RIGHT){delta=blockWidth-GetTextLineWidth((s32)state->font,state->letterSpacing,line,0);lineX+=delta*dir.x;lineY+=delta*dir.y;}
else if(flags&OV001_TEXT_ALIGN_CENTER){delta=(blockWidth+1)/2-(GetTextLineWidth((s32)state->font,state->letterSpacing,line,0)+1)/2;lineX+=delta*dir.x;lineY+=delta*dir.y;}
DrawFontTextLine(state,lineX,lineY,curColor,line,&line,dir);
offsetX+=stepX;offsetY+=stepY;
}while(line);
}

#pragma opt_propagation off
/* Draw a text block whose anchor is (x, y): measure the block, shift the anchor
 * along the text direction for the horizontal anchor flags and across it for the
 * vertical ones, then draw the lines with DrawTextMultiline. */
void DrawAnchoredText(Ov001TextState *state, s32 x, s32 y, s32 color, s32 flags, s32 text, TextDirection dir) {
    TextSize GetTextBlockSize(s32, s32, s32, s32);
    TextSize result, tmp, size;
    s32 d;

    tmp = GetTextBlockSize(M2C_FIELD(state, s32 *, 4), M2C_FIELD(state, s32 *, 8), M2C_FIELD(state, s32 *, 12), text);
    size = tmp;
    result = size;
    if (flags & OV001_TEXT_ANCHOR_HCENTER) { d = -(result.x + 1) / 2; x += d * dir.x; y += d * dir.y; }
    else if (flags & OV001_TEXT_ANCHOR_HRIGHT) { d = -result.x; x += d * dir.x; y += d * dir.y; }
    if (flags & OV001_TEXT_ANCHOR_VCENTER) { d = -(result.y + 1) / 2; x += d * -dir.y; y += d * dir.x; }
    else if (flags & OV001_TEXT_ANCHOR_VBOTTOM) { d = -result.y; x += d * -dir.y; y += d * dir.x; }
    DrawTextMultiline(state, x, y, result.x, color, flags, text, dir);
}
#pragma opt_propagation reset
/* Draw a multi-line text block anchored along the text direction instead of
 * across it: with 0x100 the block ends at `anchor` and with 0x80 it is centred
 * on it (both measured in block height along dir), then DrawTextMultiline
 * renders it at the shifted origin. */
void DrawVerticallyAnchoredText(void *state, s32 x, s32 y, s32 blockWidth, s32 anchor, s32 color, s32 flags, s32 text, TextDirection dir) {
    s32 GetTextBlockHeight(s32, s32, s32);
    
    s32 d;

    if (flags & 0x100) {
        d = anchor - GetTextBlockHeight(M2C_FIELD(state, s32 *, 4), M2C_FIELD(state, s32 *, 0xC), text);
        x += d * -dir.y;
        y += d * dir.x;
    } else if (flags & 0x80) {
        d = ((anchor + 1) / 2) - ((GetTextBlockHeight(M2C_FIELD(state, s32 *, 4), M2C_FIELD(state, s32 *, 0xC), text) + 1) / 2);
        x += d * -dir.y;
        y += d * dir.x;
    }
    DrawTextMultiline(state, x, y, blockWidth, color, flags, text, dir);
}

/* Validates a font resource (magic 'NFTR'-ish, version >= 1.00) and relocates its
   internal pointers; on success returns 1 and writes a pointer to its FINF section into *outFinf. */
s32 func_ov001_0216aab0(void *font, void **outFinf) {
    M2C_UNK SystemHalt();
    NftrBlockHeader *FindFontBlock(NftrFileHeader *, u32);
    M2C_UNK RelocateFontPointers(void *);
    s32 temp_r0;
    s32 isNftr;
    s32 validV101;
    s32 validV100;
    s32 validV100b;
    s32 validV100c;
    s32 validV100d;
    s32 backwardCompat;

    backwardCompat = 0;
    if (font != NULL) {
        if ((font != NULL) && (M2C_FIELD(font, s32 *, 0) == 0x4E465452)) {
            isNftr = 1;
        } else {
            isNftr = 0;
        }
        if (isNftr != 0) {
            validV101 = 1;
        } else {
            validV101 = 0;
        }
        if (validV101 != 0) {
            if ((font != NULL) && ((u32) M2C_FIELD(font, u16 *, 6) >= 0x101U)) {
                validV100 = 1;
            } else {
                validV100 = 0;
            }
            if (validV100 != 0) {
                validV101 = 1;
            } else {
                validV101 = 0;
            }
        }
    } else {
        validV101 = 0;
    }
    if (validV101 == 0) {
        if (font != NULL) {
            if ((font != NULL) && (M2C_FIELD(font, s32 *, 0) == 0x4E465452)) {
                validV100b = 1;
            } else {
                validV100b = 0;
            }
            if (validV100b != 0) {
                validV100c = 1;
            } else {
                validV100c = 0;
            }
            if (validV100c != 0) {
                if ((font != NULL) && ((u32) M2C_FIELD(font, u16 *, 6) >= 0x100U)) {
                    validV100d = 1;
                } else {
                    validV100d = 0;
                }
                if (validV100d != 0) {
                    validV100c = 1;
                } else {
                    validV100c = 0;
                }
            }
        } else {
            validV100c = 0;
        }
        if (validV100c == 0) {
            SystemHalt();
        }
        backwardCompat = 1;
    }
    RelocateFontPointers(font);
    temp_r0 = (s32) FindFontBlock(font, 0x46494E46);
    if (temp_r0 == 0) {
        *outFinf = NULL;
        return 0;
    }
    *outFinf = temp_r0 + 8;
    if (backwardCompat != 0) {
        M2C_FIELD(M2C_FIELD(*outFinf, void **, 8), s8 *, 7) = 0;
    }
    return 1;
}

/* Relocates a NitroSDK NFTR font's internal pointers: adds the resource base
 * address to the section-relative offsets held by the FINF, CWDH and CMAP
 * blocks, walking the blocks through the header's block table. */
s32 RelocateFontPointers(void *font) {
    u8 *base = (u8 *) font;
    u8 *block = base + M2C_FIELD(base, u16 *, 0xC);
    s32 count = M2C_FIELD(base, u16 *, 0xE);
    s32 i = 0;

    if (count <= 0) {
        return;
    }
    do {
        switch (M2C_FIELD(block, u32 *, 0)) {
        case 'FINF':
            M2C_FIELD(block, u32 *, 0x10) += (u32) base;
            if (M2C_FIELD(block, u32 *, 0x14) != 0) {
                M2C_FIELD(block, u32 *, 0x14) += (u32) base;
            }
            if (M2C_FIELD(block, u32 *, 0x18) != 0) {
                M2C_FIELD(block, u32 *, 0x18) += (u32) base;
            }
            break;
        case 'CWDH':
            if (M2C_FIELD(block, u32 *, 0xC) != 0) {
                M2C_FIELD(block, u32 *, 0xC) += (u32) base;
            }
            break;
        case 'CMAP':
            if (M2C_FIELD(block, u32 *, 0x10) != 0) {
                M2C_FIELD(block, u32 *, 0x10) += (u32) base;
            }
            break;
        case 'CGLP':
            break;
        }
        block += M2C_FIELD(block, u32 *, 4);
        i++;
    } while (i < M2C_FIELD(base, u16 *, 0xE));
}

#pragma optimize_for_size on
s32 func_ov001_0216ace0(void *arg0,s32 arg1) {
 s32 n=M2C_FIELD(arg0,s8 *,4); u32 byte=M2C_FIELD(arg0,u8 *,5); s32 shift; u32 value; u8 *p;
 if(n>=arg1) {shift=n-arg1; value=byte>>shift; M2C_FIELD(arg0,s8 *,4)=shift; } else {
 p=M2C_FIELD(arg0,u8 **,0);shift=arg1-n;M2C_FIELD(arg0,u8 **,0)=p+1;M2C_FIELD(arg0,u8 *,5)=*p;M2C_FIELD(arg0,s8 *,4)=8;value=func_ov001_0216ace0(arg0,shift)|(byte<<shift);
 } return value & (0xff>>(8-arg1));
}
u16 func_ov001_0216ad40(u16 **arg0) {
u16 *p=*arg0;
u16 v=*p++;
*arg0=p;
return v;
}

#pragma thumb on
void func_ov001_0216ad54(s32 arg0) {
    extern void (*data_ov001_021925e0)(s32);
    data_ov001_021925e0(arg0);
}

void func_ov001_0216ad64(s32 arg0) {
    extern void (*data_ov001_021925ec)(s32);
    data_ov001_021925ec(arg0);
}

