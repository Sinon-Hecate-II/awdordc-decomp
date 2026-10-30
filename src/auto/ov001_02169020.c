/* 17 functions from 0x02169020 to 0x02169E3C (ov001), found by ds-decomp. */
#include "common.h"
extern u8 data_ov001_0218c9e4[4][4][2];
typedef struct { s32 x, y; } FontSize;

void *func_ov001_02169020(void *a,s32 b){u16 n,i;void *p; p=a+M2C_FIELD(a,u16 *,12);n=M2C_FIELD(a,u16 *,14);i=0;for(;i<n;i++){if(M2C_FIELD(p,s32 *,0)==b)return p;p+=M2C_FIELD(p,s32 *,4);}return 0;}

s32 func_ov001_02169068(void *a, u32 b) {
    u16 r = 0xffff;
    switch (M2C_FIELD(a, u16 *, 4)) {
    case 0:
        r = (u16)(M2C_FIELD(a, u16 *, 12) + (b - M2C_FIELD(a, u16 *, 0)));
        break;
    case 1:
        r = M2C_FIELD((u8 *)a + 12 + (b - M2C_FIELD(a, u16 *, 0)) * 2, u16 *, 0);
        break;
    case 2: {
        u8 *lo = (u8 *)a + 14;
        u8 *hi = lo + (M2C_FIELD(a, u16 *, 12) - 1) * 4;
        while (lo <= hi) {
            u8 *mid = lo + (hi - lo) / 4 / 2 * 4;
            u16 k = M2C_FIELD(mid, s16 *, 0);
            if (k < b) {
                lo = mid + 4;
            } else if (b < k) {
                hi = mid - 4;
            } else {
                r = M2C_FIELD(mid, u16 *, 2);
                break;
            }
        }
        break;
    }
    }
    return r;
}

void func_ov001_02169130(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_ov001_0216aab0(M2C_UNK, void *);
    extern M2C_UNK func_ov001_0216ad40;
    func_ov001_0216aab0(arg1, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 4) = &func_ov001_0216ad40;
}

s32 func_ov001_02169154(void **a,u32 b){s32 func_ov001_02169068(void *,u32);void *p=M2C_FIELD(*a,void **,16);while(p){if(M2C_FIELD(p,u16 *,0)<=b && b<=M2C_FIELD(p,u16 *,2))return func_ov001_02169068(p,b);p=M2C_FIELD(p,void **,8);}return 65535;}

void *func_ov001_0216919c(void **a,u32 b){void *p;void *base; base=*a;p=M2C_FIELD(base,void **,12);while(p){u16 lo=M2C_FIELD(p,u16 *,0);if(lo<=b && b<=M2C_FIELD(p,u16 *,2))return p+8+(b-lo)*3;p=M2C_FIELD(p,void **,4);}return base+4;}

s32 func_ov001_021691e8(void *a,s32 b,s32 arg2,s32 *d){s32 c=arg2;s32 width,ch,id;s32 (*f)(s32 *);f=M2C_FIELD(a,s32 (**)(s32 *),4);width=0;ch=f(&c);if(ch){do{if(ch==10)break;id=func_ov001_02169154(a,ch);if(id==65535)id=M2C_FIELD(M2C_FIELD(a,void **,0),u16 *,2);width+=b+M2C_FIELD(func_ov001_0216919c(a,id),s8 *,2);ch=f(&c);}while(ch);}if(d)*d=ch==10?c:0;if(width>0)width-=b;return width;}

s32 func_ov001_02169294(void *a,s32 b,s32 arg2){s32 c=arg2;s32 z[2]={0,0};s32 n,ch;s32 (*f)(s32 *);f=M2C_FIELD(a,s32 (**)(s32 *),4);n=1;ch=f(&c);while(ch){if(ch==10)n++;ch=f(&c);}return n*(b+M2C_FIELD(M2C_FIELD(a,void **,0),s8 *,1))-b;}

void func_ov001_02169308(FontSize *out,void **a,s32 b,s32 c,s32 d){FontSize v={0,0};s32 n=1,w;while(d){w=func_ov001_021691e8(a,b,d,&d);if(w>v.x)v.x=w;n++;}v.y=(n-1)*(c+M2C_FIELD(*a,s8 *,1))-c;*out=v;}

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
    M2C_UNK func_02007e98(s32, s32, s32);
    u64 mask;
    u32 lo, hi, v0, v1, n0, n1;
    u32 *p;
    u32 *end;

    if (w == 8 && h == 8) {
        func_02007e98((s32) color, (s32) dst, bpp * 8);
        return;
    }
    if (bpp == 4) {
        mask = (~0ull >> (64 - (shift * 4 + w * 4))) << (shift * 4);
        lo = (u32) mask;
        v0 = color & lo;
        n0 = ~lo;
        p = dst + start;
        end = p + h;
        if (p >= end) {
            return;
        }
        do {
            *p = (*p & n0) | v0;
            p++;
        } while (p < end);
        return;
    }
    mask = (~0ull >> (64 - (shift * 8 + w * 8))) << (shift * 8);
    lo = (u32) mask;
    hi = (u32) (mask >> 32);
    v0 = color & lo;
    v1 = color & hi;
    n0 = ~lo;
    n1 = ~hi;
    p = dst + start * 2;
    end = p + h * 2;
    if (p >= end) {
        return;
    }
    do {
        p[0] = (p[0] & n0) | v0;
        p[1] = (p[1] & n1) | v1;
        p += 2;
    } while (p < end);
}

M2C_UNK func_ov001_021695e8(s32 *a0) {
    s32 func_ov001_0216ace0(void *, s32);
    struct { u8 *p; s8 n; u8 byte; } br;
    s32 w, h, c, d, maxw0, endcol, maxh0, endrow, hh, bits, ww, r1;
    s32 endcolbits, scale, r4v, r9v, rowStride, stack0, srcOffset, srcBase, dstBase;
    s32 paletteBase, shift, hi, r2v, rot, r6, r9, r11;
    u32 uoff, color, value, mask, rr;
    u8 *cur, *end, *srcBase8;
    u32 dstWord, r6d, r7d;

    w = a0[2];
    h = a0[3];
    c = a0[4];
    d = a0[5];
    maxw0 = w >= 0 ? w : 0;
    endcol = w + c;
    maxh0 = h >= 0 ? h : 0;
    endrow = h + d;
    if (endcol >= 8) endcol = 8;
    if (endrow >= 8) endrow = 8;
    hh = h > 0 ? 0 : h;
    bits = a0[8];
    ww = w > 0 ? 0 : w;
    r1 = -hh;
    endcolbits = endcol * bits;
    scale = a0[7];
    r4v = -ww;
    r9v = scale * r4v;
    rowStride = a0[6];
    stack0 = maxw0 * bits;
    srcOffset = r1 * rowStride + r9v;
    srcBase = a0[1];
    dstBase = a0[0];

    if (bits == 4) {
        paletteBase = a0[9];
        r11 = 15;
        cur = (u8 *)dstBase + maxh0 * 4;
        end = (u8 *)dstBase + endrow * 4;
        if (cur >= end) {
            return 0;
        }
        while (cur < end) {
            dstWord = *(u32 *)cur;
            uoff = (u32)srcOffset;
            hi = (s32)(uoff >> 31);
            r2v = (s32)(uoff << 29) - hi;
            rot = (s32)(((u32)r2v >> 29) | ((u32)r2v << 3));
            shift = hi + rot;
            srcBase8 = (u8 *)srcBase;
            br.p = srcBase8 + (srcOffset >> 3);
            br.n = 0;
            br.byte = 0;
            func_ov001_0216ace0(&br, shift);
            r6 = stack0;
            if (r6 < endcolbits) {
                do {
                    color = (u32)func_ov001_0216ace0(&br, scale);
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
        }
        return 0;
    }

    paletteBase = a0[9];
    cur = (u8 *)dstBase + maxh0 * 8;
    end = (u8 *)dstBase + endrow * 8;
    if (cur >= end) {
        return 0;
    }
    while (cur < end) {
        uoff = (u32)srcOffset;
        hi = (s32)(uoff >> 31);
        r2v = (s32)(uoff << 29) - hi;
        rot = (s32)(((u32)r2v >> 29) | ((u32)r2v << 3));
        shift = hi + rot;
        r6d = ((u32 *)cur)[0];
        r7d = ((u32 *)cur)[1];
        srcBase8 = (u8 *)srcBase;
        br.p = srcBase8 + (srcOffset >> 3);
        br.n = 0;
        br.byte = 0;
        func_ov001_0216ace0(&br, shift);
        r9 = stack0;
        if (r9 < endcolbits) {
            do {
                color = (u32)func_ov001_0216ace0(&br, scale);
                if (color != 0) {
                    value = (u32)(paletteBase + (s32)color);
                    if (r9 >= 32) {
                        rr = (u32)r9 - 32u;
                        mask = ~(0xffu << rr);
                        r7d = (r7d & mask) | (value << rr);
                    } else {
                        mask = ~(0xffu << r9);
                        r6d = (r6d & mask) | (value << r9);
                    }
                }
                r9 += 8;
            } while (r9 < endcolbits);
        }
        ((u32 *)cur)[0] = r6d;
        ((u32 *)cur)[1] = r7d;
        cur += 8;
        srcOffset += rowStride;
    }
    return 0;
}

void func_ov001_02169828(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    M2C_UNK func_ov001_021695e8(s32 *);
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

void func_ov001_021699c0(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    u32 func_ov001_0216939c(u32, u32, s32, s32, s32, s32);
    M2C_UNK func_ov001_021695e8(s32 *);
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    s32 spC;
    s32 sp8;
    s32 temp_r11;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r3_4;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 temp_r7;
    s32 temp_r7_3;
    s32 temp_r7_4;
    s32 temp_r8;
    s32 temp_r8_2;
    s32 temp_r9;
    s32 var_r4;
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r5;
    u32 temp_r7_2;
    u32 var_r10;
    u32 var_r6;
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
    sp48 = arg4 - 1;
    temp_r7_4 = spC - (temp_r7_3 * 8);
    sp38 = (s32) temp_r2;
    sp28 = M2C_FIELD(arg5, s32 *, 4);
    sp34 = (s32) temp_r4;
    sp1C = temp_r7_4;
    temp_r3_3 = M2C_FIELD(M2C_FIELD(*arg1, u8 **, 8), u8 *, 6);
    sp40 = (s32) temp_r3_3;
    sp44 = (s32) M2C_FIELD(arg0, u8 *, 0xC);
    sp3C = temp_r3_3 * *M2C_FIELD(*arg1, u8 **, 8);
    temp_r3_4 = M2C_FIELD(arg0, s32 *, 0x10);
    sp14 = M2C_FIELD(arg0, u32 *, 4);
    sp20 = temp_r3_4;
    sp18 = M2C_FIELD(arg0, u32 *, 8);
    if (spC <= temp_r7_4) {
        return;
    }
    do {
        var_r6 = sp10;
        sp30 = spC;
        var_r4 = sp8;
        if (sp8 > temp_r5_3) {
            do {
                temp_r1_2 = (func_ov001_0216939c(var_r6, var_r10, sp14, sp18, (s32) (u8) temp_r3_4, (u32) (temp_r3_4 << 0x10) >> 0x18) * temp_r9) + temp_r11;
                sp2C = var_r4;
                sp24 = temp_r1_2;
                func_ov001_021695e8(&sp24);
                var_r4 -= 8;
                var_r6 += 1;
            } while (var_r4 > temp_r5_3);
        }
        var_r10 += 1;
        temp_r1 = spC - 8;
        spC = temp_r1;
    } while (temp_r1 > sp1C);
}

#pragma optimization_level 3
void func_ov001_02169bd0(void *a,s32 b) {
M2C_UNK func_02007e98(s32,s32,s32);
s32 bits=M2C_FIELD(a,u8 *,12);s32 v,w=M2C_FIELD(a,s32 *,4),h;
v=bits==4 ? ((b|(b<<4))|((b|(b<<4))<<8)) : (b|(b<<8));
v|=v<<16; h=M2C_FIELD(a,s32 *,8);
func_02007e98(v,M2C_FIELD(a,s32 *,0),w*h*((bits<<6)/8));
}
#pragma optimization_level reset
void func_ov001_02169c20(void *arg0,s32 arg1){M2C_UNK func_02007e98(s32,s32,s32);register s32 width;register s32 stride;register s32 p;register s32 i;register void *a;register s32 v;s32 bits,t,size2;a=arg0;v=arg1;bits=M2C_FIELD(a,u8 *,12);p=M2C_FIELD(a,s32 *,0);if(bits==4){t=v|(v<<4);t|=t<<8;}else t=v|(v<<8);v=t|(t<<16);size2=(bits<<6)/8;stride=size2*M2C_FIELD(a,s32 *,16);width=size2*M2C_FIELD(a,s32 *,4);i=0;if(M2C_FIELD(a,s32 *,8)<=0)return;do{func_02007e98(v,p,width);i++;p=(u8 *)p+stride;}while(i<M2C_FIELD(a,s32 *,8));}

void func_ov001_02169ca0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void func_ov001_021694b0(u32 *dst, s32 shift, s32 start, s32 w, s32 h, u32 color, s32 bpp);
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 temp_r1_4;
    s32 temp_r2;
    s32 temp_r3;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r4;
    s32 var_r7;
    s32 var_r8;
    u8 temp_r11;

    temp_r11 = M2C_FIELD(arg0, u8 *, 0xC);
    sp28 = arg2 + arg4;
    sp24 = arg3 + arg5;
    if (temp_r11 == 4) {
        temp_r1 = arg1 | (arg1 * 0x10);
        var_r1 = temp_r1 | (temp_r1 << 8);
    } else {
        var_r1 = arg1 | (arg1 << 8);
    }
    spC = arg3;
    temp_r6 = temp_r11 << 6;
    temp_r1_2 = spC & ~7;
    sp2C = temp_r1_2;
    temp_r2 = M2C_FIELD(arg0, s32 *, 0x10);
    temp_r3 = arg2 & ~7;
    sp18 = temp_r3;
    sp14 = (s32) (temp_r6 + ((u32) (temp_r6 >> 2) >> 0x1D)) >> 3;
    temp_r1_3 = (sp24 + 7) & ~7;
    sp20 = temp_r1_3;
    sp10 = temp_r2 * sp14;
    sp1C = (sp14 * ((((s32) (temp_r1_2 + ((u32) (temp_r1_2 >> 2) >> 0x1D)) >> 3) * temp_r2) + ((s32) (temp_r3 + ((u32) (temp_r3 >> 2) >> 0x1D)) >> 3))) + M2C_FIELD(arg0, s32 *, 0);
    temp_r6_2 = (sp28 + 7) & ~7;
    if (sp2C >= temp_r1_3) {
        return;
    }
    do {
        if (sp2C >= spC) {
            var_r8 = 0;
        } else {
            var_r8 = spC - sp2C;
        }
        var_r7 = sp1C;
        var_r0 = sp24 - sp2C;
        if (var_r0 > 8) {
            var_r0 = 8;
        }
        var_r4 = sp18;
        if (sp18 < temp_r6_2) {
            do {
                var_r0_2 = sp28 - var_r4;
                if (var_r4 < arg2) {
                    var_r1_2 = arg2 - var_r4;
                } else {
                    var_r1_2 = 0;
                }
                if (var_r0_2 > 8) {
                    var_r0_2 = 8;
                }
                func_ov001_021694b0(var_r7, var_r1_2, var_r8, var_r0_2 - var_r1_2, var_r0 - var_r8, var_r1 | (var_r1 << 0x10), (s32) temp_r11);
                var_r4 += 8;
                var_r7 += sp14;
            } while (var_r4 < temp_r6_2);
        }
        sp1C += sp10;
        temp_r1_4 = sp2C + 8;
        sp2C = temp_r1_4;
    } while (temp_r1_4 < sp20);
}

