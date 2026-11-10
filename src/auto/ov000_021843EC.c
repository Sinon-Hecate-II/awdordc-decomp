/* 3 functions from 0x021843EC to 0x02185360 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 data_ov000_021b5c0f[],data_ov000_021b5bfc[];
extern u8 data_ov000_021dfcf0[],data_ov000_021dfba8[],data_ov000_021e0f60[],data_ov000_021df9bc[],data_ov000_021dfc4c[];
extern u8 *data_ov000_021df580;
static inline s32 Unk21843Index(u8 *unit) { if(unit==0)return 0;return (s32)(unit-((u8 *)*gCurrentMap+0x59a4))/14; }
static inline s32 Unk21843Owner(u8 *unit) {if(unit!=0)return (Unk21843Index(unit)>>6)+1;return 0;}

static inline s32 Distance851B8(s32 x,s32 y,s32 xx,s32 yy) { s32 d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;if(y-yy>0)d+=y-yy;else d+=yy-y;return d; }
typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height; } Map851B8;
typedef struct { Map851B8 map;u8 pad[0x1a0];s8 *costs[64]; } Map843EC;
static inline s32 Min851B8(s32 a,s32 b) { return b<a?b:a; }
static inline u8 Terrain851B8(s32 x,s32 y) { extern void **gCurrentMap;u8 *p=*gCurrentMap;return M2C_FIELD(p+x+M2C_FIELD(p+y*2,u16 *,0x3758),u8 *,0x1420); }

#pragma opt_common_subs off
int func_ov000_021a98a8(int);
int func_ov000_021a97d0(int,int);
int func_ov000_021a9820(int,int);
int func_ov000_021a98e4(int);
int func_0207c8ec(int,int);
void func_01ffada0(int,int,int,int,int);
void func_02007f8c(void *,int,int);
int func_020d27a4(int,int);
int func_ov000_021a97e0(int,int);
void SelectMapLayer(void *);
void func_01ffb9c4(s8);
void func_ov000_021843ec(s32 a,s32 b,s32 c) {
int x;
u8 *map=*gCurrentMap,*selected,*attrs;
int ally=0,enemy=0,y,kind,hp,field,row,n,xx,yy,left,right,top,bottom,dist,dx,dy,sx,sy;u32 idx;
s8 *dst;
u8 *leader,*postattrs;int width;
u8 *bounds;
u8 *unit;
if(M2C_FIELD(map+M2C_FIELD(map,u16 *,0x52a4)*140,u8 *,0x67ce)==3)return;
selected=M2C_FIELD(map,u8 **,0x52d0);
if(func_ov000_021a98a8((u32)(selected[0]<<26)>>26))return;
field=c*112;
if(data_ov000_021b5c0f[field]&7) {
selected=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);kind=(u32)(selected[0]<<26)>>26;
if(!(data_ov000_021b5c0f[kind*112]&7))return;
if(func_0207c8ec(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)*func_ov000_021a97d0(kind,7),100)<40)return;
map=*gCurrentMap;idx=b*((Map851B8 *)map)->width+a;
if(!((u8)(data_ov000_021dfcf0[idx>>3]&(1<<(idx&7)))))return;
}else{
if(!(data_ov000_021b5c0f[field]&16))return;
selected=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);kind=(u32)(selected[0]<<26)>>26;
if(!(data_ov000_021b5c0f[kind*112]&16))return;
if(func_0207c8ec(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u16 *,6)<<25)>>25)*func_ov000_021a97d0(kind,14),100)<40)return;
map=*gCurrentMap;idx=b*((Map851B8 *)map)->width+a;
if(!((u8)(data_ov000_021dfba8[idx>>3]&(1<<(idx&7)))))return;
}
func_01ffada0(a,b,(u32)(M2C_FIELD(M2C_FIELD(map,void **,0x52d0),u8 *,0)<<26)>>26,data_ov000_021df580[5]*2,0);
func_02007f8c(data_ov000_021e0f60,0,1288);
ally=0;enemy=0;
map=*gCurrentMap;y=0;
if(((Map851B8 *)map)->height>0) {
attrs=data_ov000_021b5bfc+field;
do {
width=((Map851B8 *)map)->width;
x=0;if((s32)width>0)do{
if(M2C_FIELD(((Map843EC *)map)->costs[y],s8 *,x)<0)goto next_unit;
row=((Map851B8 *)map)->rows[y];
n=M2C_FIELD(map+row+x,u8 *,0x508);
if(n==0)goto next_unit;
unit=map+0x59a4 + n*14;
if(unit==M2C_FIELD(map,u8 **,0x52d0))goto next_unit;
if(func_ov000_021a98a8((u32)(unit[0]<<26)>>26))goto next_unit;
if(func_020d27a4(M2C_FIELD(*gCurrentMap,u8 *,0x52d4),n)){
if(attrs[19]&7){
kind=(u32)(unit[0]<<26)>>26;
if(!(data_ov000_021b5bfc[kind*112+19]&7))goto next_unit;
if(func_0207c8ec(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)*func_ov000_021a97d0(kind,7),100)<40)goto next_unit;
}
if(attrs[19]&16){
kind=(u32)(unit[0]<<26)>>26;
if(!(data_ov000_021b5bfc[kind*112+19]&16))goto next_unit;
if(func_0207c8ec(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)*func_ov000_021a97d0(kind,14),100)<40)goto next_unit;
}
ally++;goto next_unit;
}
if(M2C_FIELD(((Map843EC *)*gCurrentMap)->costs[y],s8 *,x)>data_ov000_021df580[5])goto next_unit;
if(func_ov000_021a98e4((u32)(unit[0]<<26)>>26)==1){
if(x-func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26)<0)left=0;
else left=x-func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26);
if(y-func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26)<0)top=0;
else top=y-func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26);
bounds=(u8 *)*gCurrentMap+0x5120;
if(x+func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26)>=M2C_FIELD(bounds,u16 *,36)-1)right=((Map851B8 *)*gCurrentMap)->width-1;
else right=x+func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26);
bounds=(u8 *)*gCurrentMap+0x5120;
if(y+func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26)>=M2C_FIELD(bounds,u16 *,38)-1)bottom=((Map851B8 *)*gCurrentMap)->height-1;
else bottom=y+func_ov000_021a9820(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26);
for(yy=top;yy<=bottom;yy++){
xx=left;dst=(s8 *)data_ov000_021e0f60+xx;
for(;xx<=right;xx++,dst++){
dist=Distance851B8(x,y,xx,yy);
kind=(u32)(unit[0]<<26)>>26;
if(dist>=data_ov000_021b5bfc[kind*112+12]){
if(dist<=func_ov000_021a9820(Unk21843Owner(unit),kind)){
if(dist==1)dst[yy*((Map851B8 *)*gCurrentMap)->width]++;
else dst[yy*((Map851B8 *)*gCurrentMap)->width]+=2;
}
}
}
}
}else{
if(attrs[19]&16){
SelectMapLayer((u8 *)*gCurrentMap+0x2338);
func_01ffada0(unit[1],unit[2],(u32)(unit[0]<<26)>>26,func_ov000_021a97e0(Unk21843Owner(unit),(u32)(unit[0]<<26)>>26),0);
func_01ffb9c4(111);
map=*gCurrentMap;
for(sy=0;sy<((Map851B8 *)map)->height;sy++){
dst=(s8 *)data_ov000_021e0f60;width=((Map851B8 *)map)->width;
for(sx=0;sx<width;sx++,dst++){
if(M2C_FIELD(((Map843EC *)map)->costs[sy],s8 *,sx)>=0)dst[sy*width]++;
map=*gCurrentMap;width=((Map851B8 *)map)->width;
}
}
SelectMapLayer((u8 *)*gCurrentMap+0x1e30);
}else{
if(attrs[19]&7){
if(!(data_ov000_021b5bfc[((u32)(unit[0]<<26)>>26)*112+19]&7))goto next_unit;
}
enemy++;
}
}
next_unit:
x++;map=*gCurrentMap;
}while(x<((Map851B8 *)map)->width);
y++;
}while(y<((Map851B8 *)map)->height);
}
leader=data_ov000_021df580;
postattrs=data_ov000_021b5bfc+field;
for(y=0;y<((Map851B8 *)map)->height;y++){
dst=(s8 *)data_ov000_021e0f60;
width=((Map851B8 *)map)->width;
for(x=0;x<width;x++,dst++){

hp=M2C_FIELD(((Map843EC *)map)->costs[y],s8 *,x);
if(hp>=0 && hp<=leader[5] && ally>enemy+dst[y*width]){
if(postattrs[19]&7){
idx=y*width+x;
if((u8)(data_ov000_021dfcf0[idx>>3]&(1<<(idx&7))))data_ov000_021df9bc[idx>>3]|=1<<(idx&7);
}
if(postattrs[19]&16){
idx=y*((Map851B8 *)*gCurrentMap)->width+x;
if((u8)(data_ov000_021dfba8[idx>>3]&(1<<(idx&7))))data_ov000_021dfc4c[idx>>3]|=1<<(idx&7);
}
}
map=*gCurrentMap;width=((Map851B8 *)map)->width;
}
}
}

void func_ov000_0218500c(s32 x,s32 y,s32 type,s32 radius){
extern void **gCurrentMap;extern u8 data_ov000_021e0550[];
s32 func_020ce0ec(u8,s32);
s32 left; s32 t; s32 xx;u8 *dst;s32 dy; s32 top,yy,right,bottom,d;u8 *base;
left=x-radius;if(left<0)left=0;top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=((Map851B8 *)base)->width-1;if(x+radius<right)right=x+radius;
bottom=((Map851B8 *)base)->height-1;if(y+radius<bottom)bottom=(unsigned)y+radius;
for(yy=top;yy<=(s32)bottom;yy++){
xx=left;if(xx<=right){dy=y-yy;dst=data_ov000_021e0550+xx;t=yy-y;do{
d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;
if(dy>0)d+=dy;else d+=t;
if(d>=0&&d<=radius){
if(d!=0&&func_020ce0ec((u8)(type>>5),M2C_FIELD((u8 *)*gCurrentMap+xx+((Map851B8 *)*gCurrentMap)->rows[yy],u8 *,0x1420))){
dst[yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]|=0x80;
}else dst[yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
dst++;xx++;
}while(xx<=right);}}
}
#pragma opt_common_subs reset

void func_ov000_021851b8(s32 x,s32 y,s32 type,s32 radius){
extern void **gCurrentMap;extern u8 data_ov000_021e0550[];
s32 func_020ce0ec(u8,s32);
s32 xx;u8 *dst;s32 dy; s32 top,yy,right,bottom,left,d;u8 *base;
left=x-radius;if(left<0)left=0;top=y-radius;if(top<0)top=0;
base=*gCurrentMap;right=((Map851B8 *)base)->width-1;if(x+radius<right)right=x+radius;
bottom=((Map851B8 *)base)->height-1;if(y+radius<bottom)bottom=(unsigned)y+radius;
for(yy=top;yy<=(s32)bottom;yy++){
xx=left;if(xx<=right){dy=y-yy;dst=data_ov000_021e0550+xx;do{
d=0;if(x-xx>0)d+=x-xx;else d+=xx-x;
if(dy>0)d+=dy;else d+=yy-y;
if(d>=0&&d<=radius){
if(d>1&&func_020ce0ec((u8)type,M2C_FIELD((u8 *)*gCurrentMap+xx+((Map851B8 *)*gCurrentMap)->rows[yy],u8 *,0x1420))){
dst[yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]|=0x80;
}else dst[yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
dst++;xx++;
}while(xx<=right);}}
}
#pragma opt_common_subs reset
