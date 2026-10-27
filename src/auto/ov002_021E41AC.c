/* 14 functions from 0x021E41AC to 0x021E4B94 (ov002), found by ds-decomp. */
#include "common.h"


/* Compares two entries (index temp_r0 vs its counterpart) and returns 0/1/2. */
s32 func_ov002_021e41ac(void *entry, s32 flag) {
    extern u8 data_ov002_021f3105[];
    extern u8 data_ov002_021f30fe[];
    extern u8 data_ov002_021f3104[];
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
        if (data_ov002_021f3104[alt * 0x18] == 0) {
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

void func_ov002_021e4368(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 z,s32 color) {
s32 x,y,w;
s16 bb=(s16)b, aa=(s16)a, ff=(s16)f, ee=(s16)e, hh=(s16)h, gg=(s16)g, dd=(s16)d, cc=(s16)c;
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000480=(u16)color;
x=(u32)(u16)aa|((u32)(u16)bb<<16);
*(volatile u32 *)0x400048c=x;
*(volatile u32 *)0x400048c=(u16)(s16)z;
y=(u32)(u16)ee|((u32)(u16)ff<<16);
*(volatile u32 *)0x400048c=y;
*(volatile u32 *)0x400048c=(u16)(s16)z;
w=(u32)(u16)gg|((u32)(u16)hh<<16);
*(volatile u32 *)0x400048c=w;
*(volatile u32 *)0x400048c=(u16)(s16)z;
x=(u32)(u16)cc|((u32)(u16)dd<<16);
*(volatile u32 *)0x400048c=x;
*(volatile u32 *)0x400048c=(u16)(s16)z;
*(volatile u32 *)0x4000504=0;
*(volatile u32 *)0x4000480=0x7fff;
}

void func_ov002_021e447c(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h,s32 z,s32 color,s32 flag) {
s32 first,second,x,y;
*(volatile u32 *)0x4000500=1;
first=flag?0x7fff:color;
{
s16 bb=(s16)b,aa=(s16)a,ff=(s16)f,ee=(s16)e,zz=(s16)z;
*(volatile u32 *)0x4000480=(u16)first;
x=(u32)(u16)aa|((u32)(u16)bb<<16);
*(volatile u32 *)0x400048c=x;
*(volatile u32 *)0x400048c=(u16)zz;
y=(u32)(u16)ee|((u32)(u16)ff<<16);
*(volatile u32 *)0x400048c=y;
*(volatile u32 *)0x400048c=(u16)zz;
}
second=flag?color:0x7fff;
{
s16 hh=(s16)h,gg=(s16)g,dd=(s16)d,cc=(s16)c,zz=(s16)z;
*(volatile u32 *)0x4000480=(u16)second;
x=(u32)(u16)gg|((u32)(u16)hh<<16);
*(volatile u32 *)0x400048c=x;
*(volatile u32 *)0x400048c=(u16)zz;
y=(u32)(u16)cc|((u32)(u16)dd<<16);
*(volatile u32 *)0x400048c=y;
*(volatile u32 *)0x400048c=(u16)zz;
}
*(volatile u32 *)0x4000504=0;
*(volatile u32 *)0x4000480=0x7fff;
}

void func_ov002_021e45c0(s32 x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK func_02087b94(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 j,i,k,next;
 j=0;k=0;
 do {
 i=0; do {
 func_02087064(4,8,32,tiles+(i+k)*8,pal);
 func_02087b94(x+(8-i)*8,y,0,8,32,0,0,8,32,1,0);
 i++; } while(i<9);
 k+=9; y+=32; next=j+1; j=next;
 } while(j<2);
}

void func_ov002_021e4674(u8 *x,u32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 j,i,k;
 u8 *xx;
 s32 pp;
 pp=pal;
 j=0;k=0;
 do {
 i=0;xx=x;do {
 func_02087064(4,8,32,tiles+(i+k)*8,pp);
 func_020878c4((s32)xx,y,0,8,32,0,0,8,32);
 xx+=8;i++; if(i>=9) break; } while(1);
 k+=9;j++;y+=32;
 }while(j<2);
}

void func_ov002_021e4728(s32 x,s32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK func_02087b94(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 i=0;
 do {
 func_02087064(4,16,16,tiles+((u32)i<<3),pal);
 func_02087b94(x+(2-i)*16,y,0,16,16,0,0,16,16,1,0);
 i++;
 }while(i<3);
}

void func_ov002_021e47b0(s32 x,s32 y,s32 unused,s32 tiles,s32 pal) {
 M2C_UNK func_02087064(s32,s32,s32,s32,s32);
 M2C_UNK func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 i;
 i=0; do {
 func_02087064(4,16,16,tiles+((u32)i<<3),pal);
 func_020878c4(x,y,0,16,16,0,0,16,16);
 i++; x+=16;
 } while(i<3);
}

void func_ov002_021e482c(u8 *x,s32 y,s32 z,s32 w) {
 M2C_UNK func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 t,k,h,i;
 h=16;t=116-w;
 func_020878c4((s32)(x+t),y,z,w+12,h,t,0,128,h);
 k=w+12; y+=4; h-=4;i=0;
 do {
 t=128-k;
 func_020878c4((s32)(x+128-k)-1,y,z,1,h,t-1,16-h,t,16);
 i++; k++;y+=2;h-=2;
 }while(i<5);
}

void func_ov002_021e48e8(u8 *x,s32 y,s32 z,s32 w) {
 M2C_UNK func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
 s32 k,h,i,o;
 h=16;
 func_020878c4((s32)x,y,z,w+12,h,0,0,w+12,h);
 k=w+12; h-=4; i=0; o=1;
 do {
  func_020878c4((s32)(x+k),y,z,o,h,k,0,k+1,h);
  i++; k++; h-=2;
 } while(i<5);
}

#pragma push
#pragma scheduling off
void func_ov002_021e497c(s32 x,s32 y,s32 flip,s32 tile) {
void func_01ffaacc(u16,u16,u16,void *,s32);
void func_01ffad0c(u16,u16,u16,void *,s32);
extern u16 **gCur3DSpriteEngine;
extern u8 data_ov002_021f2d2a[],data_ov002_021f2d1c[];
s32 pal;
if(!flip) {
pal=flip==0?1:2;
func_01ffaacc((u16)(x&511),(u16)(y&255),(u16)((0x3ff&(0x11e>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((pal)<<12)),data_ov002_021f2d2a,1);
func_01ffaacc((u16)((x+16)&511),(u16)((y+8)&255),(u16)((0x3ff&((0x150+(tile<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12)),data_ov002_021f2d1c,0);
} else {
pal=flip==0?1:2;
func_01ffad0c((u16)((x+80)&511),(u16)(y&255),(u16)((0x3ff&(0x11e>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((pal)<<12)),data_ov002_021f2d2a,1);
func_01ffaacc((u16)((x+8)&511),(u16)((y+8)&255),(u16)((0x3ff&((0x150+(tile<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((flip==0?1:2)<<12)),data_ov002_021f2d1c,0);
}
}
#pragma pop
s32 func_ov002_021e4b68(void) {
    extern M2C_UNK data_ov002_021f3124;
    if ((M2C_FIELD(&data_ov002_021f3124, u8 *, 0) == M2C_FIELD(&data_ov002_021f3124, u8 *, 1)) && (M2C_FIELD(&data_ov002_021f3124, u8 *, 0x2C) == M2C_FIELD(&data_ov002_021f3124, u8 *, 0x2D))) {
        return 1;
    }
    return 0;
}

