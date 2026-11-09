/* 2 functions from 0x021F9FE0 to 0x021FAD10 (ov003), found by ds-decomp. */
#include "common.h"
static inline s16 Unk021F9FE0Selection(u8 *p) { return M2C_FIELD(p,s32 *,20); }
static inline u8 Unk021F9FE0PageIndex(u8 *p) { return M2C_FIELD(p,u32 *,4); }
static inline u8 *Unk021F9FE0Page(u8 *base,u8 page) { return base+page*512; }
static inline u32 Unk021F9FE0Bit(u8 *p) { return (u32)(M2C_FIELD(p,s32 *,56)<<31)>>31; }
static inline u8 Unk021F9FE0Eq(int a,int b) { return a==b; }
extern u8 data_ov003_0220fdf2[];
extern u8 data_027e0064[],data_0215d8a8[],data_ov003_0220f202[];
extern u32 data_027e00c4;

extern u16 data_ov003_0220feac[64];
extern void *gCur3DSpriteEngine;

void *func_020c7e6c(int);
int func_020a8b2c(int);
int func_020c7eb8(int);
int func_ov003_02200968(int);
void func_01ffaacc(int,int,int,void *,int);
int func_020a8ef8(int);
int func_ov003_021f2654(void);
void func_0208dd7c(int,int,int,int,int,int,int);
int func_ov003_02200a18(int,int);
int func_020a8958(int);
int func_020830a8(int);
int func_020a8a84(int);
void func_020a92bc(void *,int);
void func_020a94fc(void *);
int func_ov003_021f400c(void);
int func_020846a4(void);
void *func_020c7e88(int);
u8 func_020e31e0(void);
void func_ov003_021f9fe0(s32 a,s32 b,s32 c) {
u8 *p=(u8 *)a,*q,*r;int mode,id;int flag=0;int flag2=0;int dx=0,icon,index;
int x,y,tile,shift,n,v,kind,rowkind,palette,glyph;int width,height,drawX,drawY,drawW,drawH;u32 paletteBits;u8 i,j;void *saved;
mode=(u32)(p[59]<<28)>>28;
if(Unk021F9FE0Eq(mode,0)||Unk021F9FE0Eq(mode,2)||Unk021F9FE0Eq(mode,3)||Unk021F9FE0Eq(mode,4)||Unk021F9FE0Eq(mode,6)||Unk021F9FE0Eq(mode,7)||Unk021F9FE0Eq(mode,8)){
q=M2C_FIELD(p,u8 **,76);
r=M2C_FIELD(p,u8 **,92);
v=(s16)M2C_FIELD(q,s32 *,20);
n=Unk021F9FE0PageIndex(r);
q=M2C_FIELD(p,u8 **,68)+n*512;
id=M2C_FIELD(q+(u16)v*2,u16 *,46);
}else id=M2C_FIELD(p,u16 *,60);
if((u32)id>=225 && (u32)id<425) {q=func_020c7e6c(id);if(q[47])flag=1;if(Unk021F9FE0Bit(q))flag2=1;}
else if(func_020a8b2c(id))flag=1;
if(flag){
if(flag2)dx=-64;
tile=(u16)((func_ov003_02200968(7)<<4)+320);
shift=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_01ffaacc((u16)((b+192+dx)&511),28,(u16)(((tile>>shift)&1023)|0x6000),data_ov003_0220fdf2,11);
}
if(flag2) {
tile=(u16)((func_ov003_02200968(12)<<4)+320);
shift=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_01ffaacc((u16)((b+192)&511),28,(u16)(((tile>>shift)&1023)|0x6000),data_ov003_0220fdf2,11);
}
flag=0;
if(id>=225 && id<425 &&func_020c7eb8(id)==0)flag=1;
if(((u8)flag && ((mode=(u32)(p[59]<<28)>>28),Unk021F9FE0Eq(mode,2)||Unk021F9FE0Eq(mode,4)||Unk021F9FE0Eq(mode,6)||Unk021F9FE0Eq(mode,7)||Unk021F9FE0Eq(mode,8))) ||
(!func_ov003_021f400c() && func_020846a4() && (u32)id>=225 && (u32)id<425 && !func_020a8ef8(id)) ||
(func_ov003_021f2654() && ((u32)(p[57]<<24)>>31))) {
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,56)=-b;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,64)=-c;
}else{
width=M2C_FIELD(p,s16 *,64);height=M2C_FIELD(p,s16 *,66);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,56)=-(164-width/2+b);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,64)=-(108-height/2);
width=M2C_FIELD(p,s16 *,64);height=M2C_FIELD(p,s16 *,66);
drawX=(s16)(163-width/2+b);drawY=(s16)(107-height/2);drawW=(s16)(width+2);drawH=(s16)(height+2);
shift=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_0208dd7c(drawX,drawY,drawW,drawH,(u16)(((0x288>>shift)&1023)|0xa000),17,1);
}
mode=(u32)(p[59]<<28)>>28;
if(Unk021F9FE0Eq(mode,0)||Unk021F9FE0Eq(mode,2)||Unk021F9FE0Eq(mode,3)||Unk021F9FE0Eq(mode,4)||Unk021F9FE0Eq(mode,6)||Unk021F9FE0Eq(mode,7)||Unk021F9FE0Eq(mode,8)){
icon=(u16)((func_ov003_02200a18((M2C_FIELD(p,u8 **,68)+Unk021F9FE0PageIndex(M2C_FIELD(p,u8 **,92))*512)[556],id)<<2)+808);
}else if(Unk021F9FE0Eq(mode,1)){
v=(u8)(func_020a8958(M2C_FIELD(p,u16 *,60))==0);
icon=(u16)((func_ov003_02200a18((u16)(v==1?1:3),id)<<2)+808);
}else if(Unk021F9FE0Eq(mode,5)){
icon=(u16)((func_ov003_02200a18(func_020830a8(id),id)<<2)+808);
}
shift=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_01ffaacc((u16)((b+3)&511),21,(u16)(((icon>>shift)&1023)|0x9800),data_027e0064,17);
mode=(u32)(p[59]<<28)>>28;
if(Unk021F9FE0Eq(mode,0)||Unk021F9FE0Eq(mode,2)||Unk021F9FE0Eq(mode,3)||Unk021F9FE0Eq(mode,4)||Unk021F9FE0Eq(mode,6)||Unk021F9FE0Eq(mode,7)||Unk021F9FE0Eq(mode,8)){
index=(s16)((s16)M2C_FIELD(M2C_FIELD(p,void **,76),s32 *,20)+1);
}else if(Unk021F9FE0Eq(mode,1)) index=func_020a8a84(M2C_FIELD(p,u16 *,60));
mode=(u32)(p[59]<<28)>>28;
if(!Unk021F9FE0Eq(mode,5)){
func_020a92bc(M2C_FIELD(p,void **,80),index);
q=M2C_FIELD(p,u8 **,80);q[40]&=~224;
q=M2C_FIELD(p,u8 **,80);M2C_FIELD(q,s16 *,6)=b+36;M2C_FIELD(q,s16 *,8)=28;
M2C_FIELD(M2C_FIELD(p,void **,80),u16 *,18)=600;
M2C_FIELD(p,u8 **,80)[33]=9;
func_020a94fc(M2C_FIELD(p,void **,80));
}

mode=(u32)(p[59]<<28)>>28;
if(Unk021F9FE0Eq(mode,1)) {
n=(u16)(M2C_FIELD(p,u16 *,60)-161);x=b+64;
for(i=0;i<3;i++) {
switch(i) {
case 0:
kind=(u8)(M2C_FIELD(data_0215d8a8,u32 *,n*4)>>29);
if(kind) {
r=data_ov003_0220f202+(((u32)(p[58]<<25)>>27)*2);
switch(kind) {case 1:rowkind=3;break;case 2:rowkind=2;break;case 3:rowkind=1;break;case 4:rowkind=0;break;}
drawW=(s16)(rowkind*24+1036);v=r[0];tile=(u16)(drawW+(v<<2));
switch(kind) {case 1:case 2:palette=14;break;case 3:case 4:palette=13;break;default:palette=0;}
paletteBits=(u32)(palette<<28);
drawX=(u16)((r[1]?0x1000:0)|46);
shift=((u32)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_01ffaacc(drawX,40,(u16)(((tile>>shift)&1023)|(paletteBits>>16)|0x800),data_027e0064,17);
}break;
case 1:
v=((u32)M2C_FIELD(data_0215d8a8,u32 *,n*4)<<6)>>23;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(void *)data_027e00c4;
func_020a92bc(M2C_FIELD(p,void **,84),v);
q=M2C_FIELD(p,u8 **,84);M2C_FIELD(q,s16 *,6)=x;M2C_FIELD(q,s16 *,8)=59;
func_020a94fc(M2C_FIELD(p,void **,84));gCur3DSpriteEngine=saved;break;
case 2:
v=((u32)M2C_FIELD(data_0215d8a8,u32 *,n*4)<<15)>>22;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(void *)data_027e00c4;
func_020a92bc(M2C_FIELD(p,void **,84),v);
q=M2C_FIELD(p,u8 **,84);M2C_FIELD(q,s16 *,6)=x;M2C_FIELD(q,s16 *,8)=69;
func_020a94fc(M2C_FIELD(p,void **,84));gCur3DSpriteEngine=saved;break;
}
}
}
mode=(u32)(p[59]<<28)>>28;
if(!(Unk021F9FE0Eq(mode,2)||Unk021F9FE0Eq(mode,4)||Unk021F9FE0Eq(mode,6)||Unk021F9FE0Eq(mode,5)||Unk021F9FE0Eq(mode,7)||Unk021F9FE0Eq(mode,8)))return;
flag=0;
if(id>=225 && id<425 &&func_020c7eb8(id)==0)flag=1;
if((u8)flag)return;
r=func_020c7e88(id);x=b+64;
for(i=0;i<3;i++){
switch(i){
case 0:break;
case 1:
glyph=((u32)M2C_FIELD(r,u32 *,12)<<4)>>22;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(void *)data_027e00c4;
func_020a92bc(M2C_FIELD(p,void **,84),glyph);
q=M2C_FIELD(p,u8 **,84);M2C_FIELD(q,s16 *,6)=x;M2C_FIELD(q,s16 *,8)=59;
func_020a94fc(M2C_FIELD(p,void **,84));gCur3DSpriteEngine=saved;break;
case 2:
M2C_FIELD(p,u8 **,84)[41]=2;
for(j=0;j<3;j++){
switch(func_020e31e0()){
case 0:
if(j==0)glyph=(u32)(M2C_FIELD(r,s32 *,8)<<24)>>24;
else if(j==1)glyph=(u32)M2C_FIELD(r,u32 *,8)<<18>>26;
else if(j==2)glyph=(u32)M2C_FIELD(r,u32 *,8)<<12>>26;
break;
case 2:case 3:case 4:case 5:
if(j==0)glyph=(u32)M2C_FIELD(r,u32 *,8)<<12>>26;
else if(j==1)glyph=(u32)M2C_FIELD(r,u32 *,8)<<18>>26;
else if(j==2)glyph=(u32)(M2C_FIELD(r,s32 *,8)<<24)>>24;
break;
default:
if(j==0)glyph=(u32)M2C_FIELD(r,u32 *,8)<<18>>26;
else if(j==1)glyph=(u32)M2C_FIELD(r,u32 *,8)<<12>>26;
else if(j==2)glyph=(u32)(M2C_FIELD(r,s32 *,8)<<24)>>24;
break;
}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=(void *)data_027e00c4;
func_020a92bc(M2C_FIELD(p,void **,84),(s16)glyph);
q=M2C_FIELD(p,u8 **,84);M2C_FIELD(q,s16 *,6)=j*22+b+20;M2C_FIELD(q,s16 *,8)=69;
func_020a94fc(M2C_FIELD(p,void **,84));gCur3DSpriteEngine=saved;
}
M2C_FIELD(p,u8 **,84)[41]=0;break;
}
}
}

void func_ov003_021fac2c(s32 a, s32 b, s32 c, s32 d, u16 tile) {
    s16 func_0207c8ec(s32, s32);
    s16 func_0207c928(s32, s32);
    extern u16 data_ov003_0220feac[];
    extern void *gCur3DSpriteEngine;

    s16 x;
    s16 y;
    s32 row;
    s32 col;
    s32 off;
    s32 pos;
    u16 i;
    u16 k;

    x = func_0207c928(a, 2) * 15;
    y = func_0207c928(func_0207c8ec(a, 2) * 2, 32);
    pos = y * 32 + x;
    off = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 14; col++) {
            k = (func_0207c928(a, 2) == 0) ? 0 : 16;
            i = col + off;
            M2C_FIELD(gCur3DSpriteEngine, u16 **, 0x2C)[pos + i] =
                ((tile + data_ov003_0220feac[i + k]) & 0x3FF) | 0x9000;
        }
        off += 32;
    }
}
