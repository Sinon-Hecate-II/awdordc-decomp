/* 7 functions from 0x02185360 to 0x021862E8 (ov000), found by ds-decomp. */
#include "common.h"
static inline void ScanVisibilityRow(s32 ty,s32 player) {
extern void **gCurrentMap; extern s8 data_ov000_021b56c0[];
s32 func_020ce6f4(s32,s32); void func_ov000_0218500c(s32,s32,s32,s32); s32 func_ov000_021a90a8(s16,s16,s16);
s32 tx,t,kind;u8 *map;
for(tx=0;tx<M2C_FIELD(*gCurrentMap,u16*,0x5144);tx++){
map=*gCurrentMap;t=M2C_FIELD(map+tx+M2C_FIELD(map+(u32)ty*2,u16*,0x3758),u8*,0x1420);kind=t&31;
if(kind==26)func_ov000_0218500c(tx,ty,t,func_020ce6f4(t,player));
if(data_ov000_021b56c0[kind] && func_ov000_021a90a8(M2C_FIELD(*gCurrentMap,s16*,0x52a8),(s16)tx,(s16)ty))func_ov000_0218500c(tx,ty,t,func_020ce6f4(t,player));
}
}
#pragma optimization_level 0
static inline s32 TerrainMarkable(s32 kind) { extern s8 data_ov000_021b56c0[]; return data_ov000_021b56c0[kind]; }
static inline void RevealTerrain(s32 x,s32 y,s32 terrain,s32 player) { s32 func_020ce6f4(s32,s32); void func_ov000_0218500c(s32,s32,s32,s32); s32 value=func_020ce6f4(terrain,player); func_ov000_0218500c(x,y,terrain,value); }
#pragma optimization_level reset
extern void **gCurrentMap;
extern u8 data_ov000_021e0550[];
extern s8 data_ov000_021e0f60[];

void func_ov000_02185360(s32 x,s32 y,s32 unit,s32 radius){
s32 left,xx,yy,right,bottom,top,dist;
s32 func_020ce0ec(u8,u8);
left=x-radius;if(left<0)left=0;
top=y-radius;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(x+radius<right)right=x+radius;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(y+radius<bottom)bottom=y+radius;
for(yy=top;yy<=bottom;yy++){
xx=left; while(xx<=right){
dist=0;
if(x-xx>0)dist+=x-xx;else dist+=xx-x;
if(y-yy>0)dist+=y-yy;else dist+=yy-y;
if(dist>=0 && dist<=radius){
if(dist<=1 || !func_020ce0ec(unit,M2C_FIELD((u8 *)*gCurrentMap+xx+((u16 *)*gCurrentMap)[yy+0x1bac],u8 *,0x1420)))data_ov000_021e0f60[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=1;
}
xx++;
}
}
}

void func_ov000_021854e0(s32 x,s32 y,s32 radius,s32 offset){
extern void **gCurrentMap; extern u8 data_ov000_021e0550[];
s32 left,right,xx,yy,bottom,top,dist,width,height;
left=offset+(x-radius); if(left<0) left=0;
top=offset+(y-radius); if(top<0) top=0;
width=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;
right=offset+(x+radius);
if(right>width) right=width;
height=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;
bottom=height;
if(offset+(y+radius)<bottom) bottom=offset+(y+radius);
for(yy=top;yy<=bottom;yy++){
for(xx=left;xx<=right;xx++){
dist=0;
if(x-xx>0) dist+=x-xx; else dist+=xx-x;
if(y-yy>0) dist+=y-yy; else dist+=yy-y;
if(dist>=0 && dist<=radius+offset) data_ov000_021e0550[xx+yy*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]=255;
}
}
}

#pragma optimization_level 3
void func_ov000_021855e4(void) {
extern u8 *data_ov000_021df580; extern s8 data_ov000_021b56c0[];
void func_02007f8c(void*,s32,s32); s32 func_020ce6f4(s32,s32);
void func_ov000_0218500c(s32,s32,s32,s32); s32 func_ov000_021a90a8(s16,s16,s16);
s32 func_020d27c0(s32); s32 func_020a85dc(u32); s32 func_020a7738(void*,s32,s32,s32);
void func_ov000_021851b8(s32,s32,s32,s32); s32 func_ov000_021a97e0(s32,u32);
void func_01ffc294(u16,s32,s32,u32,s32,s32);
s32 t;
s32 player=data_ov000_021df580[13];
s32 sx,sy,x,y;
u8 *unit;
s32 radius,n;
s32 tx,ty,kind,i,offset;
u8 *map;
if(!M2C_FIELD(*gCurrentMap,u8*,0x5156) && player!=2){func_02007f8c(data_ov000_021e0550,255,1288);return;}
func_02007f8c(data_ov000_021e0550,0,1288);
{
for(ty=0;ty<M2C_FIELD(*gCurrentMap,u16*,0x5146);ty++)for(tx=0;tx<M2C_FIELD(*gCurrentMap,u16*,0x5144);tx++){
map=*gCurrentMap;
t=M2C_FIELD(map+tx+M2C_FIELD((short)map+(u32)ty*2,u16*,0x3758),u8*,0x1420);kind=t&31;
if(kind==26)func_ov000_0218500c(tx,ty,t,func_020ce6f4(t,player));
if(data_ov000_021b56c0[kind]){
if(func_ov000_021a90a8(M2C_FIELD(*gCurrentMap,s16*,0x52a8),(s16)tx,(s16)ty)){
s32 r=func_020ce6f4(t,player);
func_ov000_0218500c(tx,ty,t,r);
}
}
}
}
for(i=1,offset=14;i<256;i++,offset+=14){
unit=(u8*)*gCurrentMap+0x59a4+offset;
if(!((u32)(unit[0]<<26)>>26))continue;
if(func_020d27c0(i)==1)continue;
if(M2C_FIELD(unit,u16*,4)&8){
map=*gCurrentMap;
if(!func_020a85dc((u32)(M2C_FIELD(map+14*M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16*,0x3758),u8*,0x508),u8*,0x59a4)<<26)>>26))continue;
}
if(unit){if(!unit)n=0;else n=(unit-((u8*)*gCurrentMap+(unsigned short)0x59a4))/14;n=(n>>6)+1;}else n=0;
radius=func_020a7738(unit,unit[1],unit[2],player);
func_ov000_021851b8(unit[1],unit[2],n,radius);
func_02007f8c(data_ov000_021e0f60,0,1288);
func_01ffc294((u16)n,unit[1],unit[2],(u32)(unit[0]<<26)>>26,func_ov000_021a97e0(n,(u32)(unit[0]<<26)>>26),4);
M2C_FIELD((u8*)*gCurrentMap+unit[2]*4,s8**,0x52e8)[unit[1]]=-1;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++)for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
if(M2C_FIELD((u8*)*gCurrentMap+(u32)y*4,s8**,0x52e8)[x]>=0)func_ov000_02185360(x,y,n,radius);
}
for(sy=0;sy<M2C_FIELD(*gCurrentMap,u16*,0x5146);sy++)for(sx=0;sx<M2C_FIELD(*gCurrentMap,u16*,0x5144);sx++){
if((s8)data_ov000_021e0f60[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)] && (data_ov000_021e0550[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)]&127)!=127)
data_ov000_021e0550[sx+sy*M2C_FIELD(*gCurrentMap,u16*,0x5144)]++;
}
if(((u32)(unit[0]<<26)>>26)==5)func_ov000_021854e0(unit[1],unit[2],5,2);
}
}
#pragma optimization_level reset
void func_ov000_02185a74(u32 dir) {
extern u8 *data_027e0a90; extern u8 *data_027e00cc; extern s32 data_027e0a94; extern u8 *data_027e0a98;
u8 *p; void *map; s32 w,x,y,h,c,old;
data_027e00cc[36]=data_027e0a90[0];
data_027e00cc[37]=data_027e0a90[1];
switch(dir){case 0:case 1:break;case 2:data_027e00cc[37]--;break;case 3:data_027e00cc[37]++;break;case 4:data_027e00cc[36]--;break;case 5:data_027e00cc[36]++;break;default:break;}
if(data_027e0a94>=349)return;
map=*gCurrentMap;p=data_027e00cc;
w=M2C_FIELD(map,u16 *,0x5144);x=p[36];
if(x>=w)return;
y=p[37];h=M2C_FIELD(map,u16 *,0x5146);
if(y>=h)return;
c=M2C_FIELD(((s8 **)((u8 *)map+0x52e8))[y],s8 *,x);
if(c<0)return;if(c>110)return;
if((s8)data_ov000_021e0f60[data_027e0a90[0]+data_027e0a90[1]*w]<=c)return;
old=(s8)data_ov000_021e0f60[x+y*w];
if(old<=c && old>=0)return;
data_ov000_021e0f60[x+y*w]=c;
data_027e0a98[0]=p[36];
data_027e0a98[1]=data_027e00cc[37];
data_027e0a98[2]=dir;
data_027e0a98+=4;data_027e0a94++;
}

M2C_UNK func_ov000_02185c20(M2C_UNK arg0, M2C_UNK arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

s32 func_ov000_02185fb8(u8 *a,u8 *b,s32 c){
 s32 func_0206409c(s32); s32 func_ov000_021a97e0(s32,u32); extern void **gCurrentMap;
 s32 dist,n;
 dist=func_0206409c(a[1]-b[1]);
 dist+=func_0206409c(a[2]-b[2]);
 if(b){if(!b)n=0;else n=((s32)b-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
 if(dist>c+(func_ov000_021a97e0(n,(u32)(b[0]<<26)>>26)+1))return 0;return 1;
}

void func_ov000_02186070(u8 a, s32 b) {
 extern u16 data_ov000_021aeef4[];
 s32 func_ov000_021a98e4(s32);
 s32 func_020a7cfc(void *);
 s32 func_ov000_021a97d0(u32,u32);
 s32 func_ov000_021a97e0(s32,u32);
 void func_01ffada0(s32,s32,s32,s32,s32);
 void func_01ffb9c4(s32);
 s32 i,n,x,y,old;
 u8 *p, *q=(u8 *)b;
 u8 *cell;
 M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=a;
 for(i=data_ov000_021aeef4[a]+1;i<data_ov000_021aeef4[a]+0x33;i++){
 p=(u8 *)*gCurrentMap+0x59a4+i*14;
 if(!((u32)(p[0]<<26)>>26))continue;
 if(func_ov000_021a98e4((u32)(p[0]<<26)>>26))continue;
 if(M2C_FIELD(p,u16 *,4)&8)continue;
 if(func_020a7cfc(p))continue;
 if(!func_ov000_021a97d0((u32)(p[0]<<26)>>26,(u32)(q[0]<<26)>>26))continue;
 if(!func_ov000_02185fb8(q,p,0))continue;
 if(p){if(p == 0)n=0;else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59a4))/14;n=(n>>6)+1;}else n=0;
 n=func_ov000_021a97e0(n,(u32)(p[0]<<26)>>26);
 func_01ffada0(p[1],p[2],(u32)(p[0]<<26)>>26,n,12);
 func_01ffb9c4(0x6f);
 if(M2C_FIELD(((s8 **)((u8 *)*gCurrentMap+0x52e8))[q[2]],s8 *,q[1])<0)continue;
 func_ov000_02185c20(q[1],q[2]);
 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
 for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
 n=(s8)data_ov000_021e0f60[x+y*M2C_FIELD(*gCurrentMap,u16 *,0x5144)];
 if(n>=0){
 p=(u8 *)*gCurrentMap+x+((u16 *)*gCurrentMap)[y+0x1bac];
 old=M2C_FIELD(p,s8 *,0x2338);
 if(old<0 || n<old)M2C_FIELD(p,s8 *,(unsigned)0x2338)=n;
 }
 }
 }
 }
}

