/* 17 functions from 0x02169020 to 0x02169E3C (ov001), found by ds-decomp. */
#include "common.h"
extern u8 data_ov001_0218c9e4[4][4][2];

void *func_ov001_02169020(void *a,s32 b){u16 n,i;void *p; p=a+M2C_FIELD(a,u16 *,12);n=M2C_FIELD(a,u16 *,14);i=0;for(;i<n;i++){if(M2C_FIELD(p,s32 *,0)==b)return p;p+=M2C_FIELD(p,s32 *,4);}return 0;}

/* Glyph index of character code `ch` inside one CMAP record of a font resource:
 * the record lists the character range it maps and one of three lookup tables.
 * Mode 0 adds the character's offset to the record's base index, mode 1 indexes a
 * u16 table from the record's first character, and mode 2 binary-searches sorted
 * (code, index) pairs.  Returns 0xffff when the record has no such character. */
s32 GetFontCmapGlyphIndex(void *cmap, u32 ch) {
    u16 glyph = 0xffff;
    switch (M2C_FIELD(cmap, u16 *, 4)) {
    case 0:
        glyph = (u16)(M2C_FIELD(cmap, u16 *, 12) + (ch - M2C_FIELD(cmap, u16 *, 0)));
        break;
    case 1:
        glyph = M2C_FIELD((u8 *)cmap + 12 + (ch - M2C_FIELD(cmap, u16 *, 0)) * 2, u16 *, 0);
        break;
    case 2: {
        u8 *lo = (u8 *)cmap + 14;
        u8 *hi = lo + (M2C_FIELD(cmap, u16 *, 12) - 1) * 4;
        while (lo <= hi) {
            u8 *mid = lo + (hi - lo) / 4 / 2 * 4;
            u16 code = M2C_FIELD(mid, s16 *, 0);
            if (code < ch) {
                lo = mid + 4;
            } else if (ch < code) {
                hi = mid - 4;
            } else {
                glyph = M2C_FIELD(mid, u16 *, 2);
                break;
            }
        }
        break;
    }
    }
    return glyph;
}

void func_ov001_02169130(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_ov001_0216aab0(M2C_UNK, void *);
    extern M2C_UNK func_ov001_0216ad40;
    func_ov001_0216aab0(arg1, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 4) = &func_ov001_0216ad40;
}

s32 GetFontGlyphIndex(void **a,u32 b){s32 GetFontCmapGlyphIndex(void *,u32);void *p=M2C_FIELD(*a,void **,16);while(p){if(M2C_FIELD(p,u16 *,0)<=b && b<=M2C_FIELD(p,u16 *,2))return GetFontCmapGlyphIndex(p,b);p=M2C_FIELD(p,void **,8);}return 65535;}

void *GetFontGlyphMetric(void **a,u32 b){void *p;void *base; base=*a;p=M2C_FIELD(base,void **,12);while(p){u16 lo=M2C_FIELD(p,u16 *,0);if(lo<=b && b<=M2C_FIELD(p,u16 *,2))return p+8+(b-lo)*3;p=M2C_FIELD(p,void **,4);}return base+4;}

/* Width in pixels of one line of text from the font's character stream: add each
 * glyph's advance plus the letter spacing until a newline (10) or the end of the
 * text.  A missing glyph uses the font's default character.  The trailing letter
 * spacing is not counted; when `nextLine` is given it receives the stream position
 * after the newline, or 0 at the end of the text. */
s32 GetTextLineWidth(void *font,s32 letterSpacing,s32 start,s32 *nextLine){s32 pos=start;s32 width,ch,glyph;s32 (*decodeChar)(s32 *);decodeChar=((Ov001Font *)font)->decodeChar;width=0;ch=decodeChar(&pos);if(ch){do{if(ch==10)break;glyph=GetFontGlyphIndex((void **)font,ch);if(glyph==65535)glyph=((Ov001Font *)font)->resource->defaultChar;width+=letterSpacing+((Ov001GlyphMetric *)GetFontGlyphMetric((void **)font,glyph))->advance;ch=decodeChar(&pos);}while(ch);}if(nextLine)*nextLine=ch==10?pos:0;if(width>0)width-=letterSpacing;return width;}

s32 GetTextBlockHeight(void *a,s32 b,s32 arg2){s32 c=arg2;s32 z[2]={0,0};s32 n,ch;s32 (*f)(s32 *);f=M2C_FIELD(a,s32 (**)(s32 *),4);n=1;ch=f(&c);while(ch){if(ch==10)n++;ch=f(&c);}return n*(b+M2C_FIELD(M2C_FIELD(a,void **,0),s8 *,1))-b;}

/* Measure a block of text: the widest line becomes the block width, and the
 * block height is the line count times the font's line height plus the extra
 * line spacing, less one line's spacing. Each iteration measures one line and
 * leaves `text` at the start of the next; 0 means the text has ended. */
void GetTextBlockSize(Ov001TextSize *out, Ov001Font *font, s32 letterSpacing, s32 lineSpacing, s32 text) {
    Ov001TextSize size = {0, 0};
    s32 lines = 1, width;

    while (text) {
        width = GetTextLineWidth(font, letterSpacing, text, &text);
        if (width > size.width) size.width = width;
        lines++;
    }
    size.height = (lines - 1) * (lineSpacing + font->resource->lineHeight) - lineSpacing;
    *out = size;
}

#pragma intrinsic on
u32 func_ov001_0216939c(u32 x,u32 y,s32 w,s32 h,s32 sx,s32 sy){
u32 n=0,a,b; s32 ix,iy;
for(;;){
a=h&(~0u<<sy);b=w&(~0u<<sx);
if(a<=y){
n+=w*a;
if(b<=x){h-=a;n+=b*h;x-=b;y-=a;w-=b;}
else {w=b;y-=a;h-=a;}
}else {
if(b<=x){n+=b*a;h=a;x-=b;w-=b;}
else {
n+=b*(y&(~0u<<sy));
n+=(x&(~0u<<sx))<<sy;
n+=(y&~(~0u<<sy))<<sx;
return n+(x&~(~0u<<sx));
}
}
ix=w>=8?3:31-__CLZ(w);
iy=h>=8?3:31-__CLZ(h);
sx=data_ov001_0218c9e4[iy][ix][0];sy=data_ov001_0218c9e4[iy][ix][1];
}
}
s32 func_ov001_02169494(u8 *a){extern s32 data_ov001_0218ca04[4][4];return data_ov001_0218ca04[a[1]][a[0]];}

void func_ov001_021694b0(u32 *dst, s32 shift, s32 start, s32 w, s32 h, u32 color, s32 bpp) {
    M2C_UNK MI_CpuFill32(s32, s32, s32);
    u32 left, right, mask;
    u32 lo, hi, v0, v1, keepHigh;
    u32 *p;
    u32 *end;
    u32 *wideEnd;

    if (w == 8 && h == 8) {
        MI_CpuFill32((s32) color, (s32) dst, bpp * 8);
        return;
    }
    if (bpp == 4) {
        left = shift * 4;
        right = 32 - (left + w * 4);
        mask = (~0u >> left) << (right + left);
        lo = mask >> right;
        p = dst + start;
        end = p + h;
        v0 = color & lo;
        lo = ~lo;
        if (p >= end) {
            return;
        }
        do {
            *p = (*p & lo) | v0;
            p++;
        } while (p < end);
        return;
    }
    left = shift * 8;
    right = 64 - (left + w * 8);
    lo = ~0u >> left;
    if (right < 32)
        lo <<= left;
    else {
        u32 spill = right - 32;
        lo <<= left + spill;
        lo >>= spill;
    }
    {
        u32 highBits = ~0u << right;
        if (left < 32)
            hi = highBits >> right;
        else {
            u32 spill = left - 32;
            u32 lower = highBits >> (spill + right);
            hi = lower << spill;
        }
    }
    p = dst + start * 2;
    wideEnd = p + h * 2;
    v0 = color & lo;
    v1 = color & hi;
    mask = ~lo;
    keepHigh = ~hi;
    if (p >= wideEnd) {
        return;
    }
    do {
        p[0] = (p[0] & mask) | v0;
        p[1] = (p[1] & keepHigh) | v1;
        p += 2;
    } while (p < wideEnd);
}

#pragma push
#pragma opt_instruction_scheduling on
void func_ov001_021695e8(s32 *a0) {
    s32 func_ov001_0216ace0(void *, s32);
    struct { u8 *p; s8 n; u8 byte; } br4, br8;
    s32 w, h, c, d, maxw0, endcol, maxh0, endrow, hh, bits, ww, r1;
    u32 endcolbits;
    s32 scale, r4v, r9v, rowStride, srcOffset, srcBase, dstBase;
    u32 stack0;
    s32 paletteBase, shift, hi, r2v, rot , r11;
    u32 r6, r9;
    u32 uoff, color, value, mask, rr;
    u8 *cur, *end, *srcBase8;
    u32 dstWord, r6d, r7d;

    w = a0[2];
    h = a0[3];
    if (w < 0) maxw0 = 0; else maxw0 = w;
    endcol = w + a0[4];
    if (h < 0) maxh0 = 0; else maxh0 = h;
    endrow = h + a0[5];
    if (endcol >= 8) endcol = 8;
    if (endrow >= 8) endrow = 8;
    if (h > 0) h = 0;
    bits = a0[8];
    if (w > 0) w = 0;
    r1 = -h;
    endcolbits = endcol * bits;
    scale = a0[7];
    r4v = -w;
    r9v = r4v * scale;
    rowStride = a0[6];
    stack0 = bits * maxw0;
    srcOffset = r9v + r1 * rowStride;
    srcBase = a0[1];
    dstBase = a0[0];

    if (bits == 4) {
        paletteBase = a0[9];
        r11 = 15;
        cur = (u8 *)dstBase + maxh0 * 4;
        end = (u8 *)dstBase + endrow * 4;
        if (cur >= end) {
            return;
        }
        do {
            dstWord = *(u32 *)cur;
            shift = srcOffset % 8;
            srcBase8 = (u8 *)srcBase;
            br4.p = srcBase8 + ((u32)srcOffset >> 3);
            br4.n = 0;
            br4.byte = 0;
            func_ov001_0216ace0(&br4, shift);
            r6 = stack0;
            if (r6 < endcolbits) {
                do {
                    color = (u32)func_ov001_0216ace0(&br4, scale);
                    if (color != 0) {
                        value = (u32)(paletteBase + (s32)color);
                        mask = ~(15u << r6);
                        dstWord = (dstWord & mask) | (value << r6);
                    }
                    r6 += 4;
                } while (r6 < endcolbits);
            }
            *(u32 *)cur = dstWord;
            cur += 4;
            srcOffset += rowStride;
        } while(cur < end);
        return;
    }

    paletteBase = a0[9];
    cur = (u8 *)dstBase + maxh0 * 8;
    end = (u8 *)dstBase + endrow * 8;
    if (cur >= end) {
        return;
    }
    while (cur < end) {
        shift = srcOffset % 8;
        r6d = ((u32 *)cur)[0];
        r7d = ((u32 *)cur)[1];
        srcBase8 = (u8 *)srcBase;
        br8.p = srcBase8 + ((u32)srcOffset >> 3);
        br8.n = 0;
        br8.byte = 0;
        func_ov001_0216ace0(&br8, shift);
        r9 = stack0;
        if (r9 < endcolbits) {
            do {
                color = (u32)func_ov001_0216ace0(&br8, scale);
                if (color != 0) {
                    value = (u32)(paletteBase + (s32)color);
                    if (r9 < 32) {
                        mask = ~(0xffu << r9);
                        r6d = (r6d & mask) | (value << r9);
                    } else {
                        rr = r9 - 32;
                        mask = ~(0xffu << rr);
                        r7d = (r7d & mask) | (value << rr);
                    }
                }
                r9 += 8;
            } while (r9 < endcolbits);
        }
        ((u32 *)cur)[0] = r6d;
        ((u32 *)cur)[1] = r7d;
        cur += 8;
        srcOffset += rowStride;
    } while(cur < end);
    return;
}
#pragma pop
void func_ov001_02169828(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    void func_ov001_021695e8(s32 *);
    s32 sp[11];
    s32 temp_r11_2;
    s32 temp_r11_3;
    s32 temp_r3;
    s32 temp_r3_3;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r7_4;
    s32 temp_r8;
    s32 var_r10;
    s32 var_r5_2;
    s32 var_r7_2;
    s32 var_r9;
    u32 temp_ip;
    u32 temp_r11;
    u32 temp_r3_2;
    u32 temp_r7_3;
    u32 var_r11;
    u32 var_r5;
    u32 var_r6;
    u32 var_r7;
    u8 temp_r2;
    u8 temp_r2_2;
    u8 temp_r4;

    temp_r7 = M2C_FIELD(arg0, u8 *, 0xC) << 6;
    temp_r4 = M2C_FIELD(M2C_FIELD(arg5, void **, 0), u8 *, 1);
    var_r10 = arg2;
    var_r9 = arg3;
    temp_r8 = (s32) (temp_r7 + ((u32) (temp_r7 >> 2) >> 0x1D)) >> 3;
    temp_r11 = M2C_FIELD(arg0, u32 *, 4);
    temp_ip = M2C_FIELD(arg0, u32 *, 8);
    temp_r2 = M2C_FIELD(M2C_FIELD(*arg1, u8 **, 8), u8 *, 1);
    if (temp_r4 == 0) {
        return;
    }
    temp_r7_2 = var_r10 + temp_r4;
    if (temp_r7_2 < 0) {
        return;
    }
    temp_r3 = var_r9 + temp_r2;
    if (temp_r3 < 0) {
        return;
    }
    if (var_r10 <= 0) {
        var_r5 = 0;
    } else {
        var_r5 = (u32) var_r10 >> 3;
    }
    temp_r7_3 = temp_r7_2 + 7;
    if (var_r9 <= 0) {
        var_r6 = 0;
    } else {
        var_r6 = (u32) var_r9 >> 3;
    }
    var_r7 = temp_r7_3 >> 3;
    temp_r3_2 = temp_r3 + 7;
    if (temp_r11 <= (u32) (temp_r7_3 >> 3)) {
        var_r7 = temp_r11;
    }
    var_r11 = temp_r3_2 >> 3;
    if (temp_ip <= (u32) (temp_r3_2 >> 3)) {
        var_r11 = temp_ip;
    }
    temp_r3_3 = var_r7 - var_r5;
    temp_r11_2 = var_r11 - var_r6;
    if (temp_r3_3 < 0) {
        return;
    }
    if (temp_r11_2 < 0) {
        return;
    }
    temp_r7_4 = M2C_FIELD(arg0, s32 *, 0x10);
    sp[0] = temp_r8 * (temp_r7_4 - temp_r3_3);
    var_r7_2 = (temp_r8 * ((temp_r7_4 * var_r6) + var_r5)) + M2C_FIELD(arg0, s32 *, 0);
    sp[2] = M2C_FIELD(arg5, s32 *, 4);
    sp[5] = (s32) temp_r4;
    sp[10] = arg4 - 1;
    sp[6] = (s32) temp_r2;
    if (var_r10 >= 0) {
        var_r10 &= 7;
    }
    temp_r2_2 = M2C_FIELD(M2C_FIELD(*arg1, u8 **, 8), u8 *, 6);
    if (var_r9 >= 0) {
        var_r9 &= 7;
    }
    temp_r11_3 = var_r9 - (temp_r11_2 * 8);
    sp[8] = (s32) temp_r2_2;
    temp_r6 = var_r10 - (temp_r3_3 * 8);
    sp[9] = (s32) M2C_FIELD(arg0, u8 *, 0xC);
    sp[7] = temp_r2_2 * *M2C_FIELD(*arg1, u8 **, 8);
    if (var_r9 <= temp_r11_3) {
        return;
    }
    do {
        var_r5_2 = var_r10;
        sp[4] = var_r9;
        if (var_r10 > temp_r6) {
            do {
                sp[1] = var_r7_2;
                sp[3] = var_r5_2;
                func_ov001_021695e8(&sp[1]);
                var_r5_2 -= 8;
                var_r7_2 += temp_r8;
            } while (var_r5_2 > temp_r6);
        }
        var_r9 -= 8;
        var_r7_2 += sp[0];
    } while (var_r9 > temp_r11_3);
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov001_021699c0(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    u32 func_ov001_0216939c(u32, u32, s32, s32, s32, s32);
    void func_ov001_021695e8(s32 *);
    s32 state[11];
    s32 sp1C;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    s32 spC;
    s32 sp8;
    register s32 temp_r11;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r3_4;
    s32 temp_r5_2;
    register s32 temp_r5_3;
    s32 temp_r7;
    s32 temp_r7_3;
    s32 temp_r7_4;
    s32 temp_r8;
    s32 temp_r8_2;
    register s32 temp_r9;
    register s32 var_r4;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r5;
    u32 temp_r7_2;
    register u32 var_r10;
    register u32 var_r6;
    u32 var_r7;
    u32 var_r8;
    u8 temp_r2;
    u8 temp_r3_3;
    u8 temp_r4;

    temp_r8 = M2C_FIELD(arg0, u8 *, 0xC) << 6;
    temp_r4 = M2C_FIELD(M2C_FIELD(arg5, void **, 0), u8 *, 1);
    sp8 = arg2;
    spC = arg3;
    temp_r9 = (s32) (temp_r8 + ((u32) (temp_r8 >> 2) >> 0x1D)) >> 3;
    temp_r3 = M2C_FIELD(arg0, u32 *, 4);
    temp_r5 = M2C_FIELD(arg0, u32 *, 8);
    temp_r2 = M2C_FIELD(M2C_FIELD(*arg1, u8 **, 8), u8 *, 1);
    if (temp_r4 == 0) {
        return;
    }
    temp_r7 = sp8 + temp_r4;
    if (temp_r7 < 0) {
        return;
    }
    temp_r8_2 = spC + temp_r2;
    if (temp_r8_2 < 0) {
        return;
    }
    temp_r7_2 = temp_r7 + 7;
    if (sp8 <= 0) {
        sp10 = 0;
    } else {
        sp10 = (u32) sp8 >> 3;
    }
    if (spC <= 0) {
        var_r10 = 0;
    } else {
        var_r10 = (u32) spC >> 3;
    }
    var_r7 = temp_r7_2 >> 3;
    if (temp_r3 <= (u32) (temp_r7_2 >> 3)) {
        var_r7 = temp_r3;
    }
    temp_r3_2 = temp_r8_2 + 7;
    var_r8 = temp_r3_2 >> 3;
    if (temp_r5 <= (u32) (temp_r3_2 >> 3)) {
        var_r8 = temp_r5;
    }
    temp_r5_2 = var_r7 - sp10;
    temp_r7_3 = var_r8 - var_r10;
    if (temp_r5_2 < 0) {
        return;
    }
    if (temp_r7_3 < 0) {
        return;
    }
    temp_r11 = M2C_FIELD(arg0, s32 *, 0);
    if (sp8 >= 0) {
        sp8 &= 7;
    }
    if (spC >= 0) {
        spC &= 7;
    }
    temp_r5_3 = sp8 - (temp_r5_2 * 8);
    state[10] = arg4 - 1;
    temp_r7_4 = spC - (temp_r7_3 * 8);
    state[6] = (s32) temp_r2;
    state[2] = M2C_FIELD(arg5, s32 *, 4);
    state[5] = (s32) temp_r4;
    sp1C = temp_r7_4;
    temp_r3_3 = M2C_FIELD(M2C_FIELD(*arg1, u8 **, 8), u8 *, 6);
    state[8] = (s32) temp_r3_3;
    state[9] = (s32) M2C_FIELD(arg0, u8 *, 0xC);
    state[7] = temp_r3_3 * *M2C_FIELD(*arg1, u8 **, 8);
    temp_r3_4 = M2C_FIELD(arg0, s32 *, 0x10);
    sp14 = M2C_FIELD(arg0, u32 *, 4);
    state[0] = temp_r3_4;
    sp18 = M2C_FIELD(arg0, u32 *, 8);
    if (spC <= temp_r7_4) {
        return;
    }
    do {
        var_r6 = sp10;
        state[4] = spC;
        var_r4 = sp8;
        if (sp8 > temp_r5_3) {
            do {
                temp_r1_2 = (func_ov001_0216939c(var_r6, var_r10, sp14, sp18, (s32) (u8) temp_r3_4, (u32) (temp_r3_4 << 0x10) >> 0x18) * temp_r9) + temp_r11;
                state[3] = var_r4;
                state[1] = temp_r1_2;
                func_ov001_021695e8(&state[1]);
                var_r4 -= 8;
                var_r6 += 1;
            } while (var_r4 > temp_r5_3);
        }
        var_r10 += 1;
        temp_r1 = spC - 8;
        spC = temp_r1;
    } while (temp_r1 > sp1C);
}
#pragma pop
void func_ov001_02169bd0(void *a,s32 b) {
M2C_UNK MI_CpuFill32(s32,s32,s32);
s32 bits=M2C_FIELD(a,u8 *,12), w=M2C_FIELD(a,s32 *,4), v, h;
if(bits==4) {v=b|(b<<4)|(b<<8)|(b<<12);}else{v=b|(b<<8);}
v=v|(v<<16);h=M2C_FIELD(a,s32 *,8);
MI_CpuFill32(v,M2C_FIELD(a,s32 *,0),(w*h)*((bits<<6)/8));
}
#pragma optimization_level reset
void func_ov001_02169c20(void *arg0,s32 arg1){M2C_UNK MI_CpuFill32(s32,s32,s32);register s32 width;register s32 stride;register s32 p;register s32 i;register void *a;register s32 v;s32 bits,t,sz;a=arg0;v=arg1;bits=M2C_FIELD(a,u8 *,12);p=M2C_FIELD(a,s32 *,0);if(bits==4){t=v|(v<<4);t|=t<<8;}else t=v|(v<<8);v=t|(t<<16);sz=(bits<<6)/8;stride=sz*M2C_FIELD(a,s32 *,16);width=sz*M2C_FIELD(a,s32 *,4);for(i=0;i<M2C_FIELD(a,s32 *,8);i++){MI_CpuFill32(v,p,width);p=(u8 *)p+stride;}}

void func_ov001_02169ca0(void *surface, u32 color, s32 x, s32 y, s32 width, s32 height) {
    void func_ov001_021694b0(u32 *, s32, s32, s32, s32, u32, s32);
    s32 tileY, right, bottom, endY;
    u8 *row;
    s32 startX, tileSize, pitch, top;
    s32 endX, columns;
    u8 depth;
    u32 fill;

    depth = M2C_FIELD(surface, u8 *, 0xc);
    right = x + width;
    bottom = y + height;
    fill = color | (color << (depth == 4 ? 4 : 8));
    if (depth == 4) fill |= fill << 8;
    fill |= fill << 16;
    top = y;
    tileY = y & ~7;
    columns = M2C_FIELD(surface, s32 *, 0x10);
    startX = x & ~7;
    {
        s32 strideBits = depth << 6;
        s32 offset = tileY / 8 * columns + startX / 8;
        tileSize = strideBits / 8;
        row = M2C_FIELD(surface, u8 **, 0) + tileSize * offset;
    }
    endY = (bottom + 7) & ~7;
    pitch = columns * tileSize;
    endX = (right + 7) & ~7;
    if (tileY >= endY) return;
    do {
        s32 firstY, lastY, firstX, lastX, tileX;
        u8 *tile;
        if (tileY < top) firstY = top - tileY;
        else firstY = 0;
        tile = row;
        lastY = bottom - tileY;
        if (lastY > 8) lastY = 8;
        lastY -= firstY;
        tileX = startX;
        if (tileX < endX) {
            do {
                lastX = right - tileX;
                firstX = tileX < x ? x - tileX : 0;
                if (lastX > 8) lastX = 8;
                func_ov001_021694b0((u32 *)tile, firstX, firstY, lastX - firstX, lastY, fill, depth);
                tileX += 8;
                tile += tileSize;
            } while (tileX < endX);
        }
        row += pitch;
        tileY += 8;
    } while (tileY < endY);
}

