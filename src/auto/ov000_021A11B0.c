/* 12 functions from 0x021A11B0 to 0x021A2100 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6;u8 flags:2;u8 pad[7];u16 bits:14;u16 state:2;u8 tail[4]; } Unit16E8;
typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height;u8 pad3[0x1a0];s8 *grid[64]; } Map16E8;
typedef struct { u8 pad[3];u8 used:1;u8 rest:7; } Candidate1F14;

#pragma opt_strength_reduction off
void func_ov000_021a11b0(s32 arg0){
extern void **gCurrentMap;
extern void *data_ov000_021df578,*data_ov000_021df57c;
extern u8 data_ov000_021e00ac[],data_ov000_021b5bfc[];
s32 func_020d27c0(s32);s32 func_ov000_021a10e4(s32,void *);
s32 ManhattanDistance(s32,s32,s16,s16);void func_01ffb554(void *);
void func_01ffada0(u8,u8,s32,s32,s32);
s32 func_ov000_021a99dc(void *);s32 func_ov000_021a98a8(s32);
s32 func_ov000_021a8ff0(s32);s32 func_020d27ec(s16,s32);
s32 x,y,i,id,d,xmin,xmax,ymin,ymax,r,dx,dy,cx,cy,w,h;
u8 *map,*unit,*p;
{s32 x;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x];
if(id){
unit=map+0x59a4+id*14;
if(func_020d27c0(id)!=1){
p=data_ov000_021e00ac;
for(i=0;i<M2C_FIELD(data_ov000_021df578,u8 *,0);i++,p+=12){
if(M2C_FIELD(p,s8 *,4)==arg0 && func_ov000_021a10e4(i,unit)){
d=ManhattanDistance(p[0],p[1],(s16)x,(s16)y);
if(p[7]>d)p[7]=d;
}
}
}
}
}
}}
p=data_ov000_021e00ac;
for(i=0;i<M2C_FIELD(data_ov000_021df578,u8 *,0);i++,p+=12){
if(M2C_FIELD(p,s8 *,4)!=arg0)continue;
func_01ffb554((u8 *)*gCurrentMap+0x2338);
func_01ffada0(p[0],p[1],7,M2C_FIELD(data_ov000_021df57c,u8 *,16),0);
func_01ffb554((u8 *)*gCurrentMap+0x1e30);
map=*gCurrentMap;cx=p[0];r=M2C_FIELD(data_ov000_021df57c,u8 *,16);w=((Map16E8 *)map)->width;
xmin=cx-r;
xmax=w-1;
if(xmin<0)xmin=0;
cy=p[1];h=((Map16E8 *)map)->height;ymin=cy-r;
ymax=h-1;
if(ymin<0)ymin=0;
if(cx+r<xmax)xmax=cx+r;
if(cy+r<ymax)ymax=cy+r;
{s32 x,y;
for(y=ymin;y<=ymax;y++)for(x=xmin;x<=xmax;x++){
dx=p[0]-x;if(dx<=0)dx=x-p[0];
d=0;d+=dx;dy=p[1]-y;if(dy<=0)dy=y-p[1];d+=dy;
if(d<0 || d>M2C_FIELD(data_ov000_021df57c,u8 *,16))continue;
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x];
if(!id)continue;
unit=map+0x59a4+id*14;
if(!func_ov000_021a10e4(i,unit))continue;
if(func_ov000_021a99dc(unit)==1)continue;
if(data_ov000_021b5bfc[((u32)(unit[0]<<26)>>26)*112+19]&7){
map=*gCurrentMap;if(M2C_FIELD(map+((Map16E8 *)map)->rows[y]+x,s8 *,0x2338)<0)continue;
}
if(func_020d27c0(id)==1)M2C_FIELD(p,s8 *,5)--;
else{
if(p[2]==3 || func_ov000_021a98a8((u32)(unit[0]<<26)>>26))M2C_FIELD(p,s8 *,5)++;
else M2C_FIELD(p,s8 *,5)+=2;
p[6]++;
}
}}
if(p[8]==255){
func_01ffada0(p[0],p[1],1,110,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++)for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(((Map16E8 *)map)->grid[y][x]<0)continue;
id=map[((Map16E8 *)map)->rows[y]+x+0x1420];
if(func_ov000_021a8ff0(id)!=1)continue;
map=*gCurrentMap;id=map[((Map16E8 *)map)->rows[y]+x+0x1420];
if(func_020d27ec(M2C_FIELD(map,s16 *,0x52a8),id)!=0)continue;
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[8]>d)p[8]=d;
}
}
}
}
#pragma opt_strength_reduction reset
void func_ov000_021a16e8(void){
extern void *data_ov000_021df578;extern u8 data_ov000_021e00ac[];extern void **gCurrentMap;
void func_01ffada0(u8,u8,s32,s32,s32);
s32 func_ov000_021a8fc0(s16);s32 func_ov000_021a98c8(s32);s32 func_ov000_021a9934(s32,s32);
s32 i;u8 *p; s32 id,d;Map16E8 *map;Unit16E8 *unit;s32 x,y;
p=data_ov000_021e00ac;
for(i=0;i<M2C_FIELD(data_ov000_021df578,u8 *,0);i++,p+=12){
if(p[3]==252)continue;
func_01ffada0(p[0],p[1],1,110,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(map->grid[y][x]<0)continue;
id=((u8 *)map)[x+map->rows[y]];
if(!id)continue;
if(func_ov000_021a8fc0((s16)id)!=1)continue;
unit=(Unit16E8 *)((u8 *)*gCurrentMap+0x59a4)+id;
if(func_ov000_021a98c8(unit->kind)){
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[9]>d)p[9]=d;
}
if(func_ov000_021a9934(24,unit->kind)&&unit->state==2){
d=((Map16E8 *)*gCurrentMap)->grid[y][x];if(p[10]>d)p[10]=d;
}
}
}
}
}

s32 func_ov000_021a18d8(void) {
s32 func_020cf878(u8,u8);
extern void **gCurrentMap;
extern s8 data_ov000_021b55a0[];
extern u8 data_ov000_021e00ac[];
s32 n=0;u8 *p;u8 *dst; u8 *base;
dst=data_ov000_021e00ac; base=*gCurrentMap;p=base+0x6c60;
if(base[0x6c60]!=255) do {
if(func_020cf878(p[1],p[2])==1) {
n++;dst[0]=p[1];dst[1]=p[2];dst[2]=data_ov000_021b55a0[p[0]];
if((p[0]&31)==16)dst[2]=1;
dst[3]=127;M2C_FIELD(dst,s8 *,4)=-1;dst[5]=0;dst[6]=0;dst[7]=255;dst[8]=255;dst[9]=255;dst[10]=255;dst+=12;
}p+=6;
}while(*p!=255);
return n;
}

s32 func_ov000_021a19a8(void) {
s32 func_020b9e20(u16,M2C_UNK);s32 func_020d2d18(u16,M2C_UNK);s32 func_ov000_021a66e8();M2C_UNK func_ov000_021a07c0();
extern void **gCurrentMap;extern void *data_ov000_021df57c,*data_ov000_021df580;extern M2C_UNK data_ov000_021df7d0,data_ov000_021dfd94,data_ov000_021e00b0;
void *base,*entry;u16 id;s32 result;u8 flags;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,0xa)<<26)>>29)&4))return 0;
if(M2C_FIELD(data_ov000_021df57c,u8 *,0x50)==0)return 0;
if(func_020b9e20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),6)==0)return 0;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if((s32)(func_020d2d18(id,6)*10)>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
result=func_ov000_021a66e8();if(result==-1)return 0;
entry=(u8 *)&data_ov000_021dfd94+M2C_FIELD(&data_ov000_021e00b0,s8 *,result*12)*8;
flags=M2C_FIELD(entry,u8 *,3);
M2C_FIELD(&data_ov000_021df7d0,s8 *,6)=6;
M2C_FIELD(entry,u8 *,3)=flags&~2;
func_ov000_021a07c0(result);return 1;
}

s32 func_ov000_021a1ab8(void) {
 s32 func_ov000_021a64c4(); M2C_UNK func_ov000_021a7ac0(s32); s32 func_ov000_021a8438(s32); M2C_UNK func_ov000_021a07c0(s32);
 extern u8 data_ov000_021e00af[];
 s32 x=func_ov000_021a64c4();
 if(x==-1) return 0;
 func_ov000_021a7ac0(x);
 if(func_ov000_021a8438(x)!=-1) {func_ov000_021a07c0(x); return 1;}
 data_ov000_021e00af[x*12]=253;
 return 0;
}

s32 func_ov000_021a1b1c(void){
s32 func_020b9e20(u16,M2C_UNK);s32 func_020d2d18(u16,M2C_UNK);M2C_UNK func_ov000_02199330();s32 func_ov000_021a686c();s32 func_ov000_021a86dc();s32 func_ov000_021a860c();M2C_UNK func_ov000_021a07c0();
extern void **gCurrentMap;extern void *data_ov000_021df57c,*data_ov000_021df580;extern M2C_UNK data_ov000_021df7d0;
void *base;u16 id;s32 result;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,0xa)<<20)>>29)&2))return 0;
if(M2C_FIELD(data_ov000_021df57c,u8 *,0xb0)==0)return 0;
if(func_020b9e20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),14)==0)return 0;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if(func_020d2d18(id,14)*10>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
if(func_ov000_021a86dc()==1)return 0;
if(func_ov000_021a860c()==0)return 0;
func_ov000_02199330();
result=func_ov000_021a686c();if(result==-1)return 0;
M2C_FIELD(&data_ov000_021df7d0,s8 *,6)=14;
func_ov000_021a07c0(result);return 1;
}

/* Tries to activate candidate 0x17: checks flags, availability and resources, then records it. */
s32 func_ov000_021a1c24(void) {
    s32 func_020b9e20(u16, M2C_UNK);
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6940();
    M2C_UNK func_ov000_021a07c0();
    extern void **gCurrentMap;
    extern void *data_ov000_021df57c;
    extern void *data_ov000_021df580;
    extern M2C_UNK data_ov000_021df7d0;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(data_ov000_021df580, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11C) == 0) return 0;
    if (func_020b9e20(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *gCurrentMap;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (func_020d2d18(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6940();
    if (result == -1) return 0;
    M2C_FIELD(&data_ov000_021df7d0, s8 *, 6) = 0x17;
    func_ov000_021a07c0(result);
    return 1;
}

/* Tries to activate candidate 0x17, using a stricter resource threshold (func_ov000_021a6a00). */
s32 func_ov000_021a1d08(void) {
    s32 func_020b9e20(u16, M2C_UNK);
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6a00();
    M2C_UNK func_ov000_021a07c0();
    extern void **gCurrentMap;
    extern void *data_ov000_021df57c;
    extern void *data_ov000_021df580;
    extern M2C_UNK data_ov000_021df7d0;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(data_ov000_021df580, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11C) == 0) return 0;
    if (func_020b9e20(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *gCurrentMap;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (func_020d2d18(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6a00();
    if (result == -1) return 0;
    M2C_FIELD(&data_ov000_021df7d0, s8 *, 6) = 0x17;
    func_ov000_021a07c0(result);
    return 1;
}

s32 func_ov000_021a1dec(void) {
s32 func_020b9e20(u16,M2C_UNK);s32 func_020d2d18(u16,M2C_UNK);s32 func_ov000_021a6ac0();M2C_UNK func_ov000_021a07c0();
extern void **gCurrentMap;extern void *data_ov000_021df57c,*data_ov000_021df580;extern M2C_UNK data_ov000_021df7d0;
void *base;u16 id;s32 result;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,0xa)<<20)>>29)&4))return 0;
if(M2C_FIELD(data_ov000_021df57c,u8 *,0x110)==0)return 0;
if(func_020b9e20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),0x16)==0)return 0;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if((s32)(func_020d2d18(id,0x16)*10)>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
result=func_ov000_021a6ac0();if(result==-1)return 0;
M2C_FIELD(&data_ov000_021df7d0,s8 *,6)=0x16;
func_ov000_021a07c0(result);return 1;
}

s32 func_ov000_021a1ed0(void) {
 extern void **gCurrentMap; extern void *data_ov000_021df57c;
 s32 r=0; u16 x;
 x=M2C_FIELD(*gCurrentMap,u16 *,0x52a2);
 if((s32)x>3) {r=M2C_FIELD(data_ov000_021df57c,u8 *,10)*x; if(r>80) r=80;}
 return r;
}

s32 func_ov000_021a1f14(void){
s32 func_0207c2f0(void);s32 func_0207c928(s32,s32);s32 func_020d2d18(u16,M2C_UNK);
s32 func_ov000_021a664c(void);s32 func_ov000_021a60d4(s32);s32 func_ov000_021a5ffc(s32);
u8 func_ov000_021a88c8(s32);M2C_UNK func_ov000_021a07c0(s32);
extern void **gCurrentMap;extern void *data_ov000_021df578,*data_ov000_021df57c;
extern M2C_UNK data_ov000_021df7d0,data_ov000_021dfd94,data_ov000_021e00b0;
void *base,*entry;u16 id;s32 result,r,cost;u8 flags,t;
base=*gCurrentMap;id=M2C_FIELD(base,u16 *,0x52a4);
if(func_020d2d18(id,1)*10>M2C_FIELD(id*140+(s32)base,s32 *,0x67a4))return 0;
result=func_ov000_021a664c();
if(result==-1)result=func_ov000_021a60d4(1);
if(result==-1)result=func_ov000_021a5ffc(1);
if(result==-1)return 0;
entry=(u8 *)&data_ov000_021dfd94+M2C_FIELD(&data_ov000_021e00b0,s8 *,result*12)*8;
if(!((Candidate1F14 *)entry)->used){((Candidate1F14 *)entry)->used=1;}
else {
M2C_FIELD(data_ov000_021df578,u8 *,8)=func_ov000_021a88c8(1);
t=func_ov000_021a88c8(2);
M2C_FIELD(data_ov000_021df578,u8 *,8)+=t;
if(M2C_FIELD(data_ov000_021df578,u8 *,8)>=M2C_FIELD(data_ov000_021df57c,u8 *,8)+M2C_FIELD(data_ov000_021df57c,u8 *,9))return 0;
}
r=func_0207c928(func_0207c2f0(),100);
if(r<func_ov000_021a1ed0() && (base=*gCurrentMap,id=M2C_FIELD(base,u16 *,0x52a4),M2C_FIELD(id*140+(s32)base,s32 *,0x67a4)>=func_020d2d18(id,2)*20))M2C_FIELD(&data_ov000_021df7d0,u8 *,6)=2;
else M2C_FIELD(&data_ov000_021df7d0,u8 *,6)=1;
func_ov000_021a07c0(result);return 1;
}

s32 func_ov000_021a20d4(void) {
    M2C_UNK func_ov000_021a07c0();
    M2C_UNK func_ov000_021a7d08();
    s32 func_ov000_021a7f1c(M2C_UNK);
    func_ov000_021a7d08();
    if (func_ov000_021a7f1c(1) == -1) {
        return 0;
    }
    func_ov000_021a07c0();
    return 1;
}
