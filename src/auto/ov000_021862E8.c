/* 8 functions from 0x021862E8 to 0x02187188 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021862e8(s32 arg0) {
void func_01ffb3d0(s32); void func_01ffb554(void *);
s32 func_020d1938(s32); s32 func_020d273c(u16,s32); void func_ov000_02186070(u8,s32);
extern void **gCurrentMap;
u16 saved; s32 i; void *base;
base=*gCurrentMap; saved=M2C_FIELD(base,u16 *,0x52b6);
func_01ffb554(base+0x2338); func_01ffb3d0(-1); func_01ffb554(*gCurrentMap+0x1e30);
for(i=1;i<5;i++){if(func_020d1938(i)!=0 && func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),i)==0)func_ov000_02186070(i,arg0);}
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=saved;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov000_0218639c(void) {
extern s32 data_027e0a94;extern u8 *data_027e0a90,*data_027e0a98;extern void **gCurrentMap;extern s8 data_ov000_021e0f60[];
s32 count,x0,y0,x1,y1,cx,cy,w; s32 x,y,dist,v,index; s16 nx,ny; u8 *node,*tail;void **map;void *base;
if(data_027e0a94>=349)return;
node=data_027e0a90;count=0;
cx=node[0];x0=cx-1;if(x0<0)x0=0;
cy=node[1];y0=cy-1;if(y0<0)y0=0;
map=gCurrentMap;base=*map;w=M2C_FIELD(base,u16*,0x5144);
x1=w-1;if(cx+1<x1)x1=cx+1;
y1=M2C_FIELD(base,u16*,0x5146)-1;if(cy+1<y1)y1=cy+1;
for(y=y0;y<=y1;y++){for(x=x0;x<=x1;x++){
dist=0;v=node[0]-x;if(v<=0)v=x-node[0];dist+=v;v=cy-y;if(v>0)dist+=v;else dist+=y-cy;
if(dist>=1 && dist<=1){
v=M2C_FIELD((u8*)*map+M2C_FIELD((u8*)*map+y*2,u16*,0x3758)+x,s8*,0x2338);
if(v>=0){if(!(v&64) || (v&63)>node[3]){
nx=x;ny=(s16)y;count++;}}
}
}}
if(count>1)return;
index=cy*w+cx;
data_ov000_021e0f60[index]&=~128;
if(count==0)return;
index=ny*M2C_FIELD(*map,u16*,0x5144)+nx;
if(data_ov000_021e0f60[index]!=0)data_ov000_021e0f60[index]&=~64;
else data_ov000_021e0f60[index]=(node[3]+1)|64;
data_027e0a98[0]=nx;data_027e0a98[1]=ny;data_027e0a98[2]=1;data_027e0a98[3]=data_027e0a90[3]+1;
tail=data_027e0a98;
M2C_FIELD((u8*)*gCurrentMap+tail[0]+M2C_FIELD((u8*)*gCurrentMap+tail[1]*2,u16*,0x3758),u8*,0x2338)=tail[3]|64;
data_027e0a98+=4;data_027e0a94++;
}
#pragma pop
M2C_UNK func_ov000_02186624(u8 arg0, u8 arg1) { (void)arg0; (void)arg1; return 0; }

void func_ov000_02186940(void *arg0) {
    void func_ov000_021862e8();
    M2C_UNK func_ov000_02186624(u8, u8);
    func_ov000_021862e8();
    func_ov000_02186624(M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 func_ov000_0218695c(void *arg0) {
s32 func_020a7cfc(void *); s32 func_ov000_021a8a88(void *); s32 func_ov000_021a98e4(u32);
extern u8 data_ov000_021b5c0f;
u16 flags; u8 result;
flags=M2C_FIELD(arg0,u16 *,4);
if(flags&8)return 0;
if(!(flags&1) && ((u32)(M2C_FIELD(arg0,u8 *,10)<<24)>>31)==0)return 0;
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<16)>>27)!=0 && func_ov000_021a8a88(arg0)==1)return 1;
if(func_020a7cfc(arg0)!=0)return 1;
if(func_ov000_021a98e4((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)!=1)return 0;
result= !(*(&data_ov000_021b5c0f+(((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70))&32);
return result;
}

void func_ov000_02186a18(void) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f;
    extern u8 data_ov000_021b5bfc[];
    extern u16 data_ov000_021aeef4[];
    extern u8 *data_ov000_021df644;
    extern s8 data_ov000_021e0f60[];
    s32 func_ov000_021a98e4(u32);
    u8 func_ov000_0218695c(void *);
    s32 func_ov000_02185fb8(void *, void *, s32);
    void func_ov000_02186940(void *);
    void func_01ffc328(void *);
    u8 func_ov000_021a9d8c(u32, s32);
    s32 func_020cf878(s32, s32);
    void func_ov000_02199d74(s32, s32, s32, s32, s32);
    s32 fy, i;
    register s32 y, x;
    s32 best, cell, fx, n;
    u8 *unit;

    if (func_ov000_021a98e4((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) == 1
        && ((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) != 0x1a)
        return;
    if ((&data_ov000_021b5c0f)[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) * 0x70] & 0x20)
        return;
    n = data_ov000_021aeef4[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)];
    i = n + 1;
    if (i >= n + 0x33) return;
    for (; i < data_ov000_021aeef4[M2C_FIELD(*gCurrentMap, u16 *, 0x52a4)] + 0x33; i++) {
        unit = (u8 *)*gCurrentMap + 0x59a4;
        if (((u32)(unit[i * 0xe] << 26) >> 26) == 0) continue;
        if (!func_ov000_0218695c(unit + i * 0xe)) continue;
        if (!func_ov000_02185fb8(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), unit + i * 0xe, 0)) continue;
        func_ov000_02186940(unit + i * 0xe);
        func_01ffc328(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0));
        fy = -1;
        fx = -1;
        best = 0xff;
        for (y = 0; y < M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
            for (x = 0; x < M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
                if (((s8 **)((u8 *)*gCurrentMap + 0x52e8))[y][x] < 0) continue;
                cell = ((u8 *)data_ov000_021e0f60)[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
                if (cell == 0) continue;
                if (cell >= best) continue;
                if (func_ov000_021a9d8c((s16)x, (s16)y)) continue;
                if (func_020cf878(x, y)) continue;
                if ((data_ov000_021b5bfc[((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52d0), u8 *, 0) << 26) >> 26) * 0x70 + 0x13] & 7) == 0) {
                    if (M2C_FIELD((u8 *)*gCurrentMap + x + ((u16 *)*gCurrentMap)[y + 0x1bac], u8 *, 0x2840) >= data_ov000_021df644[1]) continue;
                }
                if (M2C_FIELD((u8 *)*gCurrentMap + x + ((u16 *)*gCurrentMap)[y + 0x1bac], u8 *, 0x2d48) >= data_ov000_021df644[2]) continue;
                fx = x;
                fy = y;
                best = ((u8 *)data_ov000_021e0f60)[y * M2C_FIELD(*gCurrentMap, u16 *, 0x5144) + x];
            }
        }
        if (fx == -1) continue;
        func_ov000_02199d74((s16)fx, (s16)fy, 2, 0, 0);
        return;
    }
}

s32 func_ov000_02186d94(s32 a,s32 b,s32 c){
extern void **gCurrentMap; u8 func_ov000_021a9d8c(u32,s32);
extern u8 data_ov000_021b5c0e[];extern M2C_UNK data_0212616c;
void *p; s32 off; s32 n; s32 idxByte,dataByte; s8 *table;
if(a<0 || b<0)goto fail;
p=*gCurrentMap;
if(a<M2C_FIELD(p,u16 *,0x5144)&&b<M2C_FIELD(p,u16 *,0x5146))goto valid;
fail:return 0;
valid:
if(func_ov000_021a9d8c((s16)a,(s16)b))return 0;
off=c*0x70;
p=*gCurrentMap;
n=M2C_FIELD(p+b*2,u16 *,0x3758);
table=M2C_FIELD(&data_0212616c,s8 **,0x64);
idxByte=M2C_FIELD(p+(a+n),u8 *,0x1420);
dataByte=data_ov000_021b5c0e[off];
return ((table+(dataByte<<5))[idxByte&31]>=0)?1:0;
}

s32 func_ov000_02186e64(s32 x, s32 y) {
  extern void **gCurrentMap;
  extern u8 data_ov000_021b5c0e[];
  extern M2C_UNK data_0212616c;
  s32 func_ov000_02186d94(s32,s32,s32);
  void *base; u8 *units; s8 *tbl;
  s32 off, kind;
  base=*gCurrentMap;
  units=(u8*)base+0x59a4;
  off=M2C_FIELD(M2C_FIELD(base,u8 **,0x52d0),u8 *,0xc)*0xe;
  kind=(u32)(M2C_FIELD((u8*)base+M2C_FIELD(M2C_FIELD(base,u8 **,0x52d0),u8 *,0xd)*0xe,u8 *,0x59a4)<<26)>>26;
  if(kind==0){
    s32 res;
    res=func_ov000_02186d94(x-1,y,(u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26);
    res+=func_ov000_02186d94(x+1,y,(u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26);
    res+=func_ov000_02186d94(x,y-1,(u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26);
    res+=func_ov000_02186d94(x,y+1,(u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26);
    return res;
  }
  tbl=M2C_FIELD(&data_0212616c,s8 **,0x64);
  if(M2C_FIELD(tbl+data_ov000_021b5c0e[kind*0x70]*32,s8 *,4)<0){
    s32 res;
    if(M2C_FIELD(tbl+data_ov000_021b5c0e[((u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26)*0x70]*32,s8 *,4)<0){
      res=func_ov000_02186d94(x-1,y,7);
      res+=func_ov000_02186d94(x+1,y,7);
      res+=func_ov000_02186d94(x,y-1,7);
      res+=func_ov000_02186d94(x,y+1,7);
      return res;
    }
    res=func_ov000_02186d94(x-1,y,7);
    res+=func_ov000_02186d94(x+1,y,7);
    res+=func_ov000_02186d94(x,y-1,7);
    res+=func_ov000_02186d94(x,y+1,7);
    if(res!=0)return res;
    res=func_ov000_02186d94(x-1,y,1);
    res+=func_ov000_02186d94(x+1,y,1);
    res+=func_ov000_02186d94(x,y-1,1);
    res+=func_ov000_02186d94(x,y+1,1);
    return res!=0;
  }else{
    s32 res;
    if(M2C_FIELD(tbl+data_ov000_021b5c0e[((u32)(M2C_FIELD(units+off,u8 *,0)<<26)>>26)*0x70]*32,s8 *,4)<0){
      res=func_ov000_02186d94(x-1,y,7);
      res+=func_ov000_02186d94(x+1,y,7);
      res+=func_ov000_02186d94(x,y-1,7);
      res+=func_ov000_02186d94(x,y+1,7);
      if(res>=2)return res;
      res=func_ov000_02186d94(x-1,y,1);
      res+=func_ov000_02186d94(x+1,y,1);
      res+=func_ov000_02186d94(x,y-1,1);
      res+=func_ov000_02186d94(x,y+1,1);
      return res!=0;
    }
    res=func_ov000_02186d94(x-1,y,1);
    res+=func_ov000_02186d94(x+1,y,1);
    res+=func_ov000_02186d94(x,y-1,1);
    res+=func_ov000_02186d94(x,y+1,1);
    return res;
  }
}

