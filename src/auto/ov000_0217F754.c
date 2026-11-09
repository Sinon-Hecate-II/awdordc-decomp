/* 16 functions from 0x0217F754 to 0x02180738 (ov000), found by ds-decomp. */
#include "common.h"
static inline s32 MapSearchDistance(s32 x0, s32 y0, s32 x1, s32 y1) {
 s32 distance=0;
 if(x0-x1>0)distance+=x0-x1;else distance+=x1-x0;
 if(y0-y1>0)distance+=y0-y1;else distance+=y1-y0;
 return distance;
}

void func_ov000_0217f754(s32 x, s32 y, u8 *out, u8 *value) {
    s32 func_ov000_021a9904(u32);
    u8 func_ov000_0217f318(s32, s32);
    u8 func_ov000_0217f494(s32, s32);
    s32 func_020a85c8(u32);
    extern void **gCurrentMap;
    u8 *p;
    u8 result;
    if (func_ov000_021a9904((u32)(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[0] << 26) >> 26) == 0) {
        result = func_ov000_0217f318(x, y);
        if (!result) return;
        *out = 4;
        *value = result;
        return;
    }
    if (func_ov000_021a9904((u32)(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0)[0] << 26) >> 26) != 1) return;
    p = M2C_FIELD(*gCurrentMap, u8 **, 0x52d0);
    if (p[1] != x || p[2] != y) {
        if (!func_020a85c8((u32)(p[0] << 26) >> 26)) return;
    }
    result = func_ov000_0217f494(x, y);
    if (result) {
        *out = 4;
        *value = result;
        return;
    }
    return;
}

void func_ov000_0217f84c(s32 a,s32 b){
extern void **gCurrentMap;extern u8 *data_ov000_021df580;
s32 func_0207c2f0(void);s32 func_0207c928(s32,s32);u8 func_ov000_021a89a4(void *);
u8 *base,*p,*q;
base=*gCurrentMap;
p=base+0x59a4+14*a;q=base+0x59a4+14*b;
base[p[1]+M2C_FIELD(base+2*p[2],u16 *,0x3758)]=a;
M2C_FIELD(*gCurrentMap,u8 **,0x52d0)=q;
M2C_FIELD(*gCurrentMap,u8 *,0x52d4)=b;
base=*gCurrentMap;
base[q[1]+M2C_FIELD(base+2*q[2],u16 *,0x3758)]=0;
M2C_FIELD(*gCurrentMap,s16 *,0x52e0)=q[1];
M2C_FIELD(*gCurrentMap,s16 *,0x52d8)=M2C_FIELD(*gCurrentMap,s16 *,0x52e0);
M2C_FIELD(*gCurrentMap,s16 *,0x52e2)=q[2];
M2C_FIELD(*gCurrentMap,s16 *,0x52da)=M2C_FIELD(*gCurrentMap,s16 *,0x52e2);
data_ov000_021df580[3]=func_0207c928(func_0207c2f0(),100);
data_ov000_021df580[5]=func_ov000_021a89a4(M2C_FIELD(*gCurrentMap,void **,0x52d0));
}

#pragma opt_strength_reduction off
void func_ov000_0217f96c(void *arg0) {
extern void **gCurrentMap;
void func_01ffb554(void*); void func_01ffc2e8(void*); void func_01ffb9c4(s32);
s32 func_020d27a4(s32,s32); s32 func_ov000_021a93ec(s16,s16); s32 func_ov000_02177f24(s32,s32,s16*);
s32 func_ov000_02176e28(s32,s16*); s32 func_ov000_0217a0a8(void*);
void func_ov000_02199d74(s32,s32,s32,s32,s32); void func_ov000_0218d040(s32);
s32 bestX=-1,bestY=-1,best=0,score,id=0;
s32 x,y; s16 pos[2]; u8 *map,*unit,*other;
s32 minX,maxY,n,ux,uy,minY,maxX,xx,yy,index;
func_01ffb554((u8*)*gCurrentMap+0x2338);
func_01ffc2e8(arg0);
func_01ffb554((u8*)*gCurrentMap+0x1e30);
func_01ffc2e8(M2C_FIELD(*gCurrentMap,void**,0x52d0));
{
s32 ax,ay;
for(ay=0;ay<M2C_FIELD(*gCurrentMap,u16*,0x5146);ay++)
for(ax=0;ax<M2C_FIELD(*gCurrentMap,u16*,0x5144);ax++){
map=*gCurrentMap;
if(M2C_FIELD(map+ay*4,s8**,0x52e8)[ax]>=0 && M2C_FIELD(map+ax+M2C_FIELD(map+ay*2,u16*,0x3758),s8*,0x2338)<0)
M2C_FIELD(map+ay*4,s8**,0x52e8)[ax]=-1;
}
}
func_01ffb9c4(111);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++)
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
map=*gCurrentMap;
if(M2C_FIELD(map+y*4,s8**,0x52e8)[x]<0)continue;
unit=map+0x59a4+14*(s16)map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
if(((u32)(unit[0]<<26)>>26)==0)continue;
index=unit?(unit-(map+0x59a4))/14:0;
if(func_020d27a4(M2C_FIELD(map,u8*,0x52d4),index)==1)continue;
if(!func_ov000_021a93ec((s16)x,(s16)y))continue;
if(!func_ov000_02177f24(x,y,pos))continue;
map=*gCurrentMap;
score=func_ov000_02176e28(map[x+M2C_FIELD(map+y*2,u16*,0x3758)]|0x30000,pos);
if(!score || score<best)continue;
if(func_ov000_0217a0a8(unit)==1){
u8 *nearMap;
ux=unit[1];uy=unit[2];n=0;
minX=ux-1;if(minX<0)minX=0;
minY=uy-1;if(minY<0)minY=0;
nearMap=*gCurrentMap;
maxX=M2C_FIELD(nearMap,u16*,0x5144)-1;if(ux+1<maxX)maxX=ux+1;
maxY=M2C_FIELD(nearMap,u16*,0x5146)-1;if(uy+1<maxY)maxY=uy+1;
for(yy=minY;yy<=maxY;yy++)for(xx=minX;xx<=maxX;xx++){
s32 dist=0;
if(ux-xx>0)dist+=ux-xx;else dist+=xx-ux;
if(uy-yy>0)dist+=uy-yy;else dist+=yy-uy;
if(dist<1 || dist>1)continue;
nearMap=*gCurrentMap;
if(M2C_FIELD(nearMap+yy*4,s8**,0x52e8)[xx]<0)continue;
other=nearMap+0x59a4+14*(nearMap+M2C_FIELD(nearMap+yy*2,u16*,0x3758))[xx];
if(((u32)(other[0]<<26)>>26)!=0 && (M2C_FIELD(other,u16*,4)&1))continue;
n++;
}
if(n<=1)continue;
}
best=score;bestX=pos[0];bestY=pos[1];
map=*gCurrentMap;id=map[x+M2C_FIELD(map+y*2,u16*,0x3758)];
}
if(best)func_ov000_02199d74((s16)bestX,(s16)bestY,4,(u8)id,0);
func_01ffb554((u8*)*gCurrentMap+0x2338);
func_01ffc2e8(arg0);
func_01ffb554((u8*)*gCurrentMap+0x1e30);
func_ov000_0218d040(1);
}
#pragma opt_strength_reduction reset
void func_ov000_0217fe68(void *arg0) {
    (void)arg0;
}

void func_ov000_02180268(s32 x,s32 y){
extern void **gCurrentMap;extern u8 *data_ov000_021df580;extern u8 *data_ov000_021df658;
s32 func_ov000_021a9904(u32);void func_ov000_0217f96c(void *);void func_ov000_0217fe68(void *);void func_ov000_02199d74(s32,s32,s32,s32,s32);
u8 *base=*gCurrentMap;u8 *p,*q;u32 index,selected;
index=base[x+M2C_FIELD(base+(unsigned)y*2,u16 *,0x3758)];selected=M2C_FIELD(base,u8 *,0x52d4);p=(u8 *)((u32)(base+0x59a4)+index*14);q=M2C_FIELD(base,u8 **,0x52d0);
if(M2C_FIELD(p,u16 *,4)&1)return;
if((u32)(p[11]<<28)>>28==6)return;
M2C_FIELD(data_ov000_021df580,u16 *,8)|=1;
if(((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27)!=0 || ((u32)(M2C_FIELD(q,u16 *,6)<<25)>>25)<((u32)(M2C_FIELD((u32)p,u16 *,6)<<25)>>25)){
func_ov000_0217f84c(selected,(u32)index);data_ov000_021df658 -= 1;
if((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27)func_ov000_02199d74(p[1],p[2],3,0,0);
switch(func_ov000_021a9904((u32)(q[0]<<26)>>26)){case 0:func_ov000_0217f96c(q);break;case 1:func_ov000_0217fe68(q);break;}
func_ov000_0217f84c(index,selected);++data_ov000_021df658;
}else{
*data_ov000_021df658=index;data_ov000_021df658 -= 1;
switch(func_ov000_021a9904((u32)(p[0]<<26)>>26)){case 0:func_ov000_0217f96c(p);break;case 1:func_ov000_0217fe68(p);break;}
++data_ov000_021df658;
}
}

s32 func_ov000_02180410(void) {
 extern u16 data_02168f14;
 extern void **gCurrentMap;
 void *p;
 if (((u32)(data_02168f14<<29)>>29)&0xFF) return 0;
 p=*gCurrentMap;
 switch(M2C_FIELD(p,u16 *,0x5142)) { case 0xAF: if(M2C_FIELD(p,u16 *,0x52A4)==2)return 1; break; }
 return 0;
}

void func_ov000_0218046c(void) {
    M2C_UNK func_ov000_021972e0();
    extern void **gCurrentMap;
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x5142) != 0xAF) {
        return;
    }
    func_ov000_02198c08();
    func_ov000_021972e0();
}

void func_ov000_0218049c(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218edd8();
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
}

void func_ov000_021804b0(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218edd8();
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
}

void func_ov000_021804c4(void) {
    M2C_UNK func_ov000_0218cfec();
    M2C_UNK func_ov000_02198c08();
    func_ov000_02198c08();
    func_ov000_0218cfec();
}

void func_ov000_021804d4(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_0219553c();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_0218053c(void) {
    M2C_UNK func_ov000_02198c08();
    M2C_UNK func_ov000_0218eea8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c08();
    func_ov000_0218eea8();
    func_ov000_0218ca94();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_0219553c();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_021805a0(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219553c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_0219553c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_021954a4();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180608(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_02195750();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_02195750();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021965dc();
    func_ov000_021954a4();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_02180670(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_02195ea4();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021954a4();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_021965dc();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_02195ea4();
    func_ov000_0218ae58();
    func_ov000_021954a4();
    func_ov000_02194370();
    func_ov000_021965dc();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

void func_ov000_021806d8(void) {
    M2C_UNK func_ov000_02198c60();
    M2C_UNK func_ov000_0218edd8();
    M2C_UNK func_ov000_0218ca94();
    M2C_UNK func_ov000_0218d4b4();
    M2C_UNK func_ov000_0219604c();
    M2C_UNK func_ov000_02194370();
    M2C_UNK func_ov000_0218ae58();
    M2C_UNK func_ov000_021967fc();
    M2C_UNK func_ov000_0218b02c();
    M2C_UNK func_ov000_02186a18();
    extern void **gCurrentMap;
    void *temp_r3;
    func_ov000_02198c60();
    func_ov000_0218edd8();
    func_ov000_0218ca94();
    func_ov000_0218d4b4();
    temp_r3 = *gCurrentMap;
    if (M2C_FIELD((s8 *)temp_r3 + M2C_FIELD(temp_r3, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE) != 0) {
        func_ov000_02186a18();
    }
    func_ov000_0219604c();
    func_ov000_02194370();
    func_ov000_0218ae58();
    func_ov000_021967fc();
    func_ov000_0218b02c();
}

