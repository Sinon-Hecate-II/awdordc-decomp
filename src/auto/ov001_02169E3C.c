/* 19 functions from 0x02169E3C to 0x0216AD74 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { s32 x,y; } TextSize;
typedef struct { s8 x, y; } TextDirection;

void func_ov001_02169e3c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_ov001_0216939c(s32, s32, s32, s32, s32, s32);
    void func_ov001_021694b0(s32, s32, s32, s32, s32, s32, s32);
    s32 bpp; u32 color; u32 c;
    s32 x1, y1, x0, y0, xe, ye, stride, bx, by;
    s32 f10, f4, f8, f0, sx, sy;
    s32 x, off, sh, xo, wd, t;

    bpp = M2C_FIELD(arg0, u8 *, 0xc);
    x1 = arg2 + arg4;
    y1 = arg3 + arg5;
    x0 = arg2 & ~7;
    y0 = arg3 & ~7;
    if (bpp == 4) { c = arg1 | (arg1 << 4); c = c | (c << 8); }
    else { c = arg1 | (arg1 << 8); }
    color = c | (c << 16);
    ye = (y1 + 7) & ~7;
    stride = (bpp << 6) / 8;
    bx = x0 / 8;
    by = y0 / 8;
    f10 = M2C_FIELD(arg0, s32 *, 0x10);
    xe = (x1 + 7) & ~7;
    f4 = M2C_FIELD(arg0, s32 *, 4);
    f8 = M2C_FIELD(arg0, s32 *, 8);
    f0 = M2C_FIELD(arg0, s32 *, 0);
    sx = f10 & 0xff;
    sy = (f10 >> 8) & 0xff;
    if (y0 >= ye) return;
    do {
        off = y0 < arg3 ? arg3 - y0 : 0;
        sh = y1 - y0;
        if (sh > 8) sh = 8;
        sh -= off;
        for (x = x0; x < xe; x += 8) {
            t = func_ov001_0216939c(bx, by, f4, f8, sx, sy);
            xo = x < arg2 ? arg2 - x : 0;
            wd = x1 - x;
            if (wd > 8) wd = 8;
            func_ov001_021694b0(stride * t + f0, xo, off, wd - xo, sh, color, bpp);
            bx++;
        }
        by++;
        y0 += 8;
    } while (y0 < ye);
}

void func_ov001_0216a030(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    M2C_FIELD(arg0, s8 *, 0xC) = (s8) arg4;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg5;
    M2C_FIELD(arg0, s32 *, 0x10) = arg6;
}

s32 func_ov001_0216a058(s32 a,void *b,s32 x,s32 y,s32 c,s32 ch){
s32 func_ov001_02169154(void*,u16);void *func_ov001_0216919c(void*,s32);
s32 n;void *pair[2];u8 *r;
n=func_ov001_02169154(b,*(u16 *)&ch);
if(n==65535)n=M2C_FIELD(M2C_FIELD(b,void**,0),u16*,2);
pair[0]=func_ov001_0216919c(b,n);
r=M2C_FIELD(M2C_FIELD(b,void**,0),u8**,8);
pair[1]=r+8+n*M2C_FIELD(r,u16*,2);
r=M2C_FIELD(M2C_FIELD(b,void**,0),u8**,8);
switch(r[7]){
case 0:case 7:x+=M2C_FIELD(pair[0],s8*,0);break;
case 1:case 2:x-=r[0];y+=M2C_FIELD(pair[0],s8*,0);break;
case 3:case 4:x-=M2C_FIELD(pair[0],s8*,0)+M2C_FIELD(pair[0],u8*,1);y-=r[1];break;
case 5:case 6:y-=M2C_FIELD(pair[0],s8*,0)+r[1];break;
}
M2C_FIELD(M2C_FIELD(a,void**,20),void (**)(s32,void*,s32,s32,s32,void*),0)(a,b,x,y,c,pair);
return M2C_FIELD(pair[0],s8*,2);
}

void func_ov001_0216a17c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern s32 data_ov001_0218c9cc;
    func_ov001_0216a030(arg0, arg1, arg2, arg3, arg4, (s32)&data_ov001_0218c9cc, arg2);
}

int __builtin_clz(unsigned int);
int __cntlzw(unsigned int);
void func_ov001_0216a1a8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern u8 data_ov001_0218c9e4[];
    extern s32 data_ov001_0218c9d8;
    struct { u32 a:8; u32 b:8; u32 c:16; } value;
    s32 x, y;
    u8 *p;
    x = arg2 < 8 ? 31 - __cntlzw(arg2) : 3;
    y = arg3 < 8 ? 31 - __cntlzw(arg3) : 3;
    p = data_ov001_0218c9e4 + y * 8 + x * 2;
    value.a = p[0];
    value.b = p[1];
    func_ov001_0216a030(arg0, arg1, arg2, arg3, arg4, (s32)&data_ov001_0218c9d8, *(s32 *)&value);
}

void func_ov001_0216a230(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u32 arg7) {

    s32 endX, endY, tile, y, row, col, x;
    u16 *p;
    u32 palette;
    y = arg4;
    tile = arg6;
    if (arg5 <= 32) {
        func_ov001_0216a2e0(arg0 + (arg5 * y + arg3) * 2, arg1, arg2, arg5, tile, arg7);
        return;
    }
    endY = y + arg2;
    endX = arg3 + arg1;
    palette = arg7 << 28;
    if (y >= endY) return;
    do {
        row = y < 32 ? y : y + 32;
        x = arg3;
        p = (u16 *)(arg0 + (row << 6));
        if (arg3 < endX) {
            do {
                col = x < 32 ? x : x + 0x3E0;
                p[col] = tile | (palette >> 16);
                x++;
                tile++;
            } while (x < endX);
        }
        y++;
    } while (y < endY);
}

s32 func_ov001_0216a2e0(s32 base,s32 w,s32 h,s32 stride,s32 tile,s32 pal) {
u16 v;s32 x,y;u16 *p;
pal=(u32)pal<<28;y=0;
if(h<=0)return base;
do{p=(u16 *)base;x=0;if(w>0){do{v=tile|((u32)pal>>16);x++;tile++;*p++=v;}while(x<w);}y++;base+=stride*2;}while(y<h);
return base;
}

s32 func_ov001_0216a33c(u32 a,u32 b) {
u32 y,x,z,t,s,u,v;
x=a>>3;y=b>>3;z=0;z=x*y+z;
t=((a&2)>>1)+(a&1);a=a&4;
z=y*(t*2+(a>>2))+z;
s=((b&2)>>1)+(b&1);b=b&4;
z=x*(s*2+(b>>2))+z;
return (t+(a>>2))*(s+(b>>2))+z;
}

void func_ov001_0216a398(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)arg4; (void)arg5; (void)arg6; (void)arg7;
}

void func_ov001_0216a690(void *arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 *arg5,TextDirection dir) {

s32 spC,sp8;
s32 step,space;void *font;s32 (*next)(s32 *);s32 ch,x,y;
space=M2C_FIELD(arg0,s32 *,8);font=M2C_FIELD(arg0,void **,4);spC=arg4;
next=M2C_FIELD(font,s32 (**)(s32 *),4);
x=arg1;y=arg2;sp8=arg3;
ch=next(&spC);
if(ch!=0){loop:
if(ch!=10){step=space+func_ov001_0216a058(M2C_FIELD(arg0,s32 *,0),font,x,y,sp8,ch);x+=step*dir.x;y+=step*dir.y;ch=next(&spC);if(ch!=0)goto loop;}}
if(arg5==0)return;
*arg5=ch==10?spC:0;
}

void func_ov001_0216a744(void *a,s32 bx,s32 by,s32 width,s32 color,s32 flags,s32 text,TextDirection dir){
s32 func_ov001_021691e8(s32,s32,s32,s32);
s32 line; s32 dx,dy,x,y,ox,oy,d,step; s32 baseX,baseY,c;
step=M2C_FIELD(a,s32*,12)+M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void**,4),void**,0),s8*,1);
dx=step*-dir.y;dy=step*dir.x;baseX=bx;baseY=by;line=text;c=color;
if(!text)return;
ox=0;oy=0;
do{
x=baseX+ox;y=baseY+oy;
if(flags&0x800){d=width-func_ov001_021691e8(M2C_FIELD(a,s32*,4),M2C_FIELD(a,s32*,8),line,0);x+=d*dir.x;y+=d*dir.y;}
else if(flags&0x400){d=(width+1)/2-(func_ov001_021691e8(M2C_FIELD(a,s32*,4),M2C_FIELD(a,s32*,8),line,0)+1)/2;x+=d*dir.x;y+=d*dir.y;}
func_ov001_0216a690(a,x,y,c,line,&line,dir);
ox+=dx;oy+=dy;
}while(line);
}

#pragma opt_propagation off
void func_ov001_0216a8ac(void *a,s32 x,s32 y,s32 b,s32 flags,s32 text,TextDirection dir){
TextSize func_ov001_02169308(s32,s32,s32,s32);

TextSize result,tmp,size;s32 d;
tmp=func_ov001_02169308(M2C_FIELD(a,s32*,4),M2C_FIELD(a,s32*,8),M2C_FIELD(a,s32*,12),text);
size=tmp;result=size;
if(flags&16){d=-(result.x+1)/2;x+=d*dir.x;y+=d*dir.y;}
else if(flags&32){d=-result.x;x+=d*dir.x;y+=d*dir.y;}
if(flags&2){d=-(result.y+1)/2;x+=d*-dir.y;y+=d*dir.x;}
else if(flags&4){d=-result.y;x+=d*-dir.y;y+=d*dir.x;}
func_ov001_0216a744(a,x,y,result.x,b,flags,text,dir);
}
#pragma opt_propagation reset
void func_ov001_0216a9d0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, TextDirection dir) {
    s32 func_ov001_02169294(s32, s32, s32);
    
    s32 x = arg1;
    s32 y = arg2;
    s32 d;

    if (arg6 & 0x100) {
        d = arg4 - func_ov001_02169294(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0xC), arg7);
        x += d * -dir.y;
        y += d * dir.x;
    } else if (arg6 & 0x80) {
        d = ((arg4 + 1) / 2) - ((func_ov001_02169294(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0xC), arg7) + 1) / 2);
        x += d * -dir.y;
        y += d * dir.x;
    }
    func_ov001_0216a744(arg0, x, y, arg3, arg5, arg6, arg7, dir);
}

/* Validates a font resource (magic 'NFTR'-ish, version >= 1.00) and relocates its
   internal pointers; on success returns 1 and writes a pointer to its FINF section into *outFinf. */
s32 func_ov001_0216aab0(void *font, void **outFinf) {
    M2C_UNK func_02007958();
    s32 func_ov001_02169020(void *, s32);
    M2C_UNK func_ov001_0216ac04(void *);
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
            func_02007958();
        }
        backwardCompat = 1;
    }
    func_ov001_0216ac04(font);
    temp_r0 = func_ov001_02169020(font, 0x46494E46);
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

s32 func_ov001_0216ac04(void *arg0) {
    u8 *base = (u8 *) arg0;
    u8 *p = base + M2C_FIELD(base, u16 *, 0xC);
    s32 count = M2C_FIELD(base, u16 *, 0xE);
    s32 i = 0;

    if (count <= 0) {
        return;
    }
    do {
        switch (M2C_FIELD(p, u32 *, 0)) {
        case 'FINF':
            M2C_FIELD(p, u32 *, 0x10) += (u32) base;
            if (M2C_FIELD(p, u32 *, 0x14) != 0) {
                M2C_FIELD(p, u32 *, 0x14) += (u32) base;
            }
            if (M2C_FIELD(p, u32 *, 0x18) != 0) {
                M2C_FIELD(p, u32 *, 0x18) += (u32) base;
            }
            break;
        case 'CWDH':
            if (M2C_FIELD(p, u32 *, 0xC) != 0) {
                M2C_FIELD(p, u32 *, 0xC) += (u32) base;
            }
            break;
        case 'CMAP':
            if (M2C_FIELD(p, u32 *, 0x10) != 0) {
                M2C_FIELD(p, u32 *, 0x10) += (u32) base;
            }
            break;
        case 'CGLP':
            break;
        }
        p += M2C_FIELD(p, u32 *, 4);
        i++;
    } while (i < M2C_FIELD(base, u16 *, 0xE));
}

s32 func_ov001_0216ace0(void *arg0,s32 arg1) {
 s32 n=M2C_FIELD(arg0,s8 *,4); u8 byte=M2C_FIELD(arg0,u8 *,5); s32 shift; s32 value; u8 *p;
 if(n>=arg1) {shift=n-arg1; M2C_FIELD(arg0,s8 *,4)=shift; value=byte>>(n-arg1);}
 else {p=M2C_FIELD(arg0,u8 **,0);shift=arg1-n;M2C_FIELD(arg0,u8 **,0)=p+1;M2C_FIELD(arg0,u8 *,5)=*p;M2C_FIELD(arg0,s8 *,4)=8;value=func_ov001_0216ace0(arg0,shift)|(byte<<shift);}
 return value & (0xff>>(8-arg1));
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

