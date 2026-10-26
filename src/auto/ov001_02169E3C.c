/* 19 functions from 0x02169E3C to 0x0216AD74 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { s8 x, y; } TextDirection;

void func_ov001_0216a030(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    M2C_FIELD(arg0, s8 *, 0xC) = (s8) arg4;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg5;
    M2C_FIELD(arg0, s32 *, 0x10) = arg6;
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

void func_ov001_0216a690(void *arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 *arg5,TextDirection dir) {
s32 func_ov001_0216a058(s32,void *,s32,s32,s32,s32);
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

