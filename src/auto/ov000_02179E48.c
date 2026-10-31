/* 10 functions from 0x02179E48 to 0x0217ACD4 (ov000), found by ds-decomp. */
#include "common.h"
static inline s32 MapSearchDistance(s32 x0, s32 y0, s32 x1, s32 y1) {
    s32 distance = 0;
    if (x0 - x1 > 0) distance += x0 - x1;
    else distance += x1 - x0;
    if (y0 - y1 > 0) distance += y0 - y1;
    else distance += y1 - y0;
    return distance;
}

#pragma opt_strength_reduction off
s32 func_ov000_02179e48(void *pos){
extern void **gCurrentMap;
extern u8 data_ov000_021b5c08;
s32 func_ov000_021a98e4(s32);
u16 func_ov000_021a97e0(u16,s32);
s32 func_ov000_021a9820(u16,u32);
s32 bx,by,kind,min,range,best;
s32 dist,dy,cx,y,x1,x,cy,x0,y1,negative;
void **slot;
void *map;
if(func_ov000_021a98e4((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8 **,0x52d0),u8 *,0)<<26)>>26)!=1){
if(((u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8 **,0x52d0),u8 *,0)<<26)>>26)!=21)return 1;
}
dist=0;
by=9999;bx=by;
map=*gCurrentMap;
kind=(u32)(M2C_FIELD(M2C_FIELD(map,u8 **,0x52d0),u8 *,0)<<26)>>26;
if(kind==21){
min=0;
range=func_ov000_021a97e0(M2C_FIELD(map,u16 *,0x52a4),17)+1;
}else{
min=M2C_FIELD(&data_ov000_021b5c08,u8 *,kind*112);
range=func_ov000_021a9820(M2C_FIELD(map,u16 *,0x52a4),kind);
}
best=range+1;
cx=M2C_FIELD(pos,s16 *,0);
x0=cx-range;if(x0<0)x0=0;
cy=M2C_FIELD(pos,s16 *,2);
y=cy-range;if(y<0)y=0;
slot=gCurrentMap;
map=*gCurrentMap;
x1=M2C_FIELD(map,u16 *,0x5144)-1;
if(cx+range<x1)x1=cx+range;
y1=M2C_FIELD(map,u16 *,0x5146)-1;
if(cy+range<y1)y1=cy+range;
if(y<=y1)do {
x=x0;
if(x<=x1)do {
dist=0;
if(cx-x>0)dist+=cx-x;else dist+=x-cx;
dy=cy-y;negative=y-cy;
if(dy>0)dist+=dy;else dist+=negative;
if(dist>=min && dist<=range && dist<=best){
map=*gCurrentMap;
kind=M2C_FIELD(M2C_FIELD((u8 *)map+y*4,s8 **,0x52e8),s8 *,x);
if(kind<0||kind>110)goto next;
if(bx!=9999 && dist==best){
if(kind>M2C_FIELD(M2C_FIELD((u8 *)map+by*4,s8 **,0x52e8),s8 *,bx))goto next;
}
best=dist;bx=x;by=y;
}
next:
x++;
}while(x<=x1);
y++;
}while(y<=y1);
if(bx==9999)return 0;
M2C_FIELD(pos,s16 *,0)=bx;
M2C_FIELD(pos,s16 *,2)=by;
return 1;
}
#pragma opt_strength_reduction off
s32 func_ov000_0217a0a8(void *arg0) {
extern void **gCurrentMap;
extern u8 data_ov000_021b5c0f[],data_ov000_021b5bfc[];
s32 func_ov000_021a98e4(s32);s32 func_ov000_021a8fc0(s32);s32 func_ov000_021a96a8(s32,s32,s32);
u8 *p=arg0,*map=*gCurrentMap,*sel,*unit;
s32 kind,bx,by,x0,y0,x1,y1,x;
u32 ck;
s32 y,d,a,b;
sel=M2C_FIELD(map,u8 **,0x52d0);
kind=(u32)(sel[0]<<26)>>26;
if(!(data_ov000_021b5c0f[kind*112]&0x27))return 0;
if(func_ov000_021a98e4(kind))return 0;
map=*gCurrentMap;
if(!M2C_FIELD(map,s16 *,0x6ee6))return 0;
if(M2C_FIELD(map,s16 *,0x6ef2)>=30)goto done;
bx=p[1];by=p[2];x0=bx-4;if(x0<0)x0=0;
y0=by-4;if(y0<0)y0=0;
x1=M2C_FIELD(map,u16 *,0x5144)-1;if(bx+4<x1)x1=bx+4;
y1=M2C_FIELD(map,u16 *,0x5146)-1;if(by+4<y1)y1=by+4;
for(y=y0;y<=y1;y++)for(x=x0;x<=x1;x++){
d=0;
if(p[1]-x>0)d+=p[1]-x;else d+=x-p[1];
if(p[2]-y>0)d+=p[2]-y;else d+=y-p[2];
if(d<0||d>4)continue;
map=*gCurrentMap;
kind=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0);
if(!kind)continue;
if(!func_ov000_021a8fc0(kind))continue;
map=*gCurrentMap;sel=M2C_FIELD(map,u8 **,0x52d0);
if(x==sel[1]&&y==sel[2])continue;
unit=map+0x59a4+kind*14;
if(func_ov000_021a98e4((u32)(unit[0]<<26)>>26)==1)continue;
ck=(u32)(unit[0]<<26)>>26;
if(data_ov000_021b5bfc[ck*112+19]&16)continue;
if(M2C_FIELD(unit,u16 *,4)&1)continue;
if(ck==0)continue;
if((u32)(M2C_FIELD(unit,u16 *,6)<<16)>>27)continue;
map=*gCurrentMap;sel=M2C_FIELD(map,u8 **,0x52d0);
a=func_ov000_021a96a8((u32)(sel[0]<<26)>>26,(u32)(p[0]<<26)>>26,0);
b=func_ov000_021a96a8(ck,(u32)(p[0]<<26)>>26,0);
map=*gCurrentMap;sel=M2C_FIELD(map,u8 **,0x52d0);
if((s32)((u32)(M2C_FIELD(sel,u16 *,6)<<25)>>25)*a+2000 < (s32)((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)*b)return 1;
}
done:return 0;
}
#pragma opt_strength_reduction reset
void func_ov000_0217a378(s32 dir) {
extern void *data_027e0a90,*data_027e00cc,*data_027e0a98;
extern void *data_027e0a94;
extern void **gCurrentMap;
u8 *p,*prev;
s32 c,x,y;
void *map;
s32 w,h,limit,cost,steps,total;
s8 *row;
M2C_FIELD(data_027e00cc,u8 *,36)=M2C_FIELD(data_027e0a90,u8 *,0);
M2C_FIELD(data_027e00cc,u8 *,37)=M2C_FIELD(data_027e0a90,u8 *,1);
switch((u32)dir){case 0:case 1:break;case 2:M2C_FIELD(data_027e00cc,u8 *,37)--;break;case 3:M2C_FIELD(data_027e00cc,u8 *,37)++;break;case 4:M2C_FIELD(data_027e00cc,u8 *,36)--;break;case 5:M2C_FIELD(data_027e00cc,u8 *,36)++;break;default:break;}
if((s32)data_027e0a94>=349)return;
map=*gCurrentMap;p=data_027e00cc;
x=p[36];w=M2C_FIELD(map,u16 *,0x5144);if(x<w){y=p[37];h=M2C_FIELD(map,u16 *,0x5146);if(y<h)goto valid;}return;valid:;
limit=M2C_FIELD(p,s16 *,32);
cost=p[M2C_FIELD((u8 *)map+(x+M2C_FIELD((u8 *)map+y*2,u16 *,0x3758)),u8 *,0x1420)&31];
prev=data_027e0a90;
c=prev[3]+cost;
if(c>limit)return;
limit=M2C_FIELD(p,s16 *,34);
steps=M2C_FIELD((u8 *)map+(prev[0]+M2C_FIELD((u8 *)map+prev[1]*2,u16 *,0x3758)),s8 *,0x2338);
total=(s16)limit*(s16)steps;
if(total<c){c=total+cost;steps++;}
row=M2C_FIELD((u8 *)map+y*4,s8 **,0x52e8);
if(row[x]<=c && row[x]>=0)return;
row[x]=c;
map=*gCurrentMap;p=data_027e00cc;
M2C_FIELD((u8 *)map+(p[36]+M2C_FIELD((u8 *)map+p[37]*2,u16 *,0x3758)),u8 *,0x2338)=steps;
M2C_FIELD(data_027e0a98,u8 *,0)=M2C_FIELD(data_027e00cc,u8 *,36);
M2C_FIELD(data_027e0a98,u8 *,1)=M2C_FIELD(data_027e00cc,u8 *,37);
M2C_FIELD(data_027e0a98,u8 *,2)=dir;
M2C_FIELD(data_027e0a98,u8 *,3)=c;
data_027e0a98+=4;data_027e0a94=(void *)((s32)data_027e0a94+1);
}

void func_ov000_0217a59c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_01ffb554(void *);
    void func_01ffb3d0(s32);
    u16 func_ov000_021a97e0(u16, s32);
    void func_01ffb454(s32);


    extern void **gCurrentMap;
    extern u8 data_027e0a8c;
    extern void *data_027e00cc;
    extern void *data_027e0a94;
    extern void *data_027e0a98;
    extern void *data_027e0a90;

    void *map;
    void *mapData;
    void *base;
    u8 *p;
    u8 *q;
    s8 flag;

    map = *gCurrentMap;
    mapData = *(void **)map;
    func_01ffb554((u8 *)mapData + 0x2338);
    func_01ffb3d0(-1);

    map = *gCurrentMap;
    mapData = *(void **)map;
    func_01ffb554((u8 *)mapData + 0x1E30);
    func_01ffb3d0(-1);

    data_027e0a8c = 0;
    base = data_027e00cc;
    data_027e0a94 = (void *)0;
    data_027e0a98 = (u8 *)base + 0x28;
    data_027e0a90 = (u8 *)base + 0x5A0;

    *(u16 *)((u8 *)base + 0x20) = (u16)arg3;

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u16 v = *(u16 *)((u8 *)mapData + 0x52A4);
        u16 r = func_ov000_021a97e0(v, arg2);
        base = data_027e00cc;
        *(u16 *)((u8 *)base + 0x22) = r;
    }
    func_01ffb454(arg2);

    p = data_027e0a98;
    p[0] = (u8)arg0;
    p[1] = (u8)arg1;
    p[2] = 1;
    p[3] = 0;

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u8 **arr = (u8 **)((u8 *)mapData + 0x52E8);
        u8 *ptr = arr[arg1];
        ptr[arg0] = 0;
    }

    map = *gCurrentMap;
    mapData = *(void **)map;
    {
        u16 rowOff = *(u16 *)((u8 *)mapData + 0x3758 + arg1 * 2);
        u8 *cell = (u8 *)mapData + arg0 + rowOff;
        cell[0x2338] = 0;
    }

    p = data_027e0a98;
    p += 4;
    data_027e0a98 = p;
    p[2] = 0;

    flag = data_027e0a8c;
    base = data_027e00cc;
    if (flag == 0) {
        data_027e0a98 = (u8 *)base + 0x5A0;
        data_027e0a90 = (u8 *)base + 0x28;
        data_027e0a8c = 1;
    } else {
        data_027e0a98 = (u8 *)base + 0x28;
        data_027e0a90 = (u8 *)base + 0x5A0;
        data_027e0a8c = 0;
        data_027e0a94 = (void *)0;
    }

    while (1) {
        u8 t;
        u8 *p2;
        u8 *p3;
        u8 nt;
        u8 subcase;
        q = data_027e0a90;
        t = q[2];
        if (t == 0) {
            break;
        }
        switch (t) {
        case 1:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 2:
            func_ov000_0217a378(2);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 3:
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            func_ov000_0217a378(5);
            break;
        case 4:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(4);
            break;
        case 5:
            func_ov000_0217a378(2);
            func_ov000_0217a378(3);
            func_ov000_0217a378(5);
            break;
        default:
            break;
        }
        p2 = data_027e0a98;
        p2[2] = 0;
        p3 = data_027e0a90;
        p3 += 4;
        data_027e0a90 = p3;
        nt = p3[2];
        if (nt != 0) {
            continue;
        }
        break;
    }

    p = data_027e0a90;
    map = *gCurrentMap;
    mapData = *(void **)map;
    p[0x24] = (u8)*(u16 *)((u8 *)mapData + 0x5144);
    base = data_027e00cc;
    map = *gCurrentMap;
    mapData = *(void **)map;
    ((u8 *)base)[0x25] = (u8)*(u16 *)((u8 *)mapData + 0x5146);
}

#pragma opt_common_subs off
u8 func_ov000_0217a8a0(s32 x, s32 y, s32 arg2) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern s32 func_0207c8ec(s32, s32);
    extern s32 func_020a86f0(s32);
    extern s32 func_020a86bc(s32, s32);
    void *base;
    void **map;
    u8 *sel;
    u8 attr;
    s8 *row;
    s8 cell;
    s32 t;
    s32 kind;
    s32 w;
    s32 A, B;
    s8 cell2;
    u8 unitByte;
    s32 lhs, rhs;

    base = *gCurrentMap;
    sel = *(u8 **)(base + 0x52D0);
    kind = (s32)(((u32)(sel[0] << 26)) >> 26);
    attr = data_ov000_021b5c0f[kind * 0x70];
    if (!(attr & 0x30)) return 1;
    row = ((s8 **)(base + 0x52E8))[y];
    cell = row[x];
    if (cell == 0) return 1;
    t = func_0207c8ec(cell - 1, arg2);

    base = *gCurrentMap;
    sel = *(u8 **)(base + 0x52D0);
    kind = (s32)(((u32)(sel[0] << 26)) >> 26);
    attr = data_ov000_021b5c0f[kind * 0x70];

    if (attr & 0x10) goto special;
    if (kind == 0x16) {
        map = *(void **volatile *)&gCurrentMap;
        base = *(void *volatile *)map;
    special:
        A = func_020a86f0(*(u16 *)(base + 0x52A4));
        B = func_020a86bc(*(u16 *)(base + 0x52A4), kind);
        row = ((s8 **)(base + 0x52E8))[y];
        cell2 = row[x];
        unitByte = (*(u8 **)(base + 0x52D0))[0xA];
        lhs = (((u32)(unitByte << 25)) >> 25) - cell2 * A;
        rhs = t * (B + 5);
        if (lhs < rhs) return 0;
    } else {
        A = func_020a86f0(*(u16 *)(base + 0x52A4));
        B = func_020a86bc(*(u16 *)(base + 0x52A4), kind);
        row = ((s8 **)(base + 0x52E8))[y];
        cell2 = row[x];
        unitByte = (*(u8 **)(base + 0x52D0))[0xA];
        lhs = (((u32)(unitByte << 25)) >> 25) - cell2 * A;
        rhs = t * (B + 1);
        if (lhs < rhs) return 0;
    }
    return 1;
}
#pragma opt_common_subs reset
s32 func_ov000_0217aa2c(s32 x,s32 y) {
extern void **data_027e0058;
void **state=data_027e0058;
void *base=*state;
register s32 left,top,right,bottom; s32 i,result,d,v;
left=x-1;
if(left<0)left=0;
top=y-1;
if(top<0)top=0;
right=M2C_FIELD(base,u16 *,0x5144)-1;
right=right>x+1?x+1:right;
bottom=M2C_FIELD(base,u16 *,0x5146)-1;
bottom=bottom>y+1?y+1:bottom;
result=111;
for(;top<=bottom;top++){
for(i=left;i<=right;i++){
d=0;
if(x-i>0)d+=x-i;else d+=i-x;
if(y-top>0)d+=y-top;else d+=top-y;
if(d<1)continue;
if(d>1)continue;
v=M2C_FIELD(((s8 **)((u8 *)*state+0x52e8))[top],s8 *,i);
if(v<0)continue;
if(v<result)result=v;
}}
return result;
}

u8 func_ov000_0217ab10(s32 arg0, s32 arg1, s32 arg2) {
 extern void **gCurrentMap;
 s32 func_020d27c0(s32);
 void *base = *gCurrentMap;
 u8 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 0;
 return func_020d27c0(id) != 1;
}

u8 func_ov000_0217ab5c(s32 arg0, s32 arg1, s32 arg2) {
 extern void **gCurrentMap;
 s32 func_ov000_021a97d0(s32, s32);
 void *base;
 u8 id;
 if (func_ov000_0217ab10(arg0,arg1,0) == 0) return 0;
 base = *gCurrentMap;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 return func_ov000_021a97d0(arg2, ((u32)(M2C_FIELD(base + id * 14, u8 *, 0x59A4) << 26) >> 26)) > 1;
}

u8 func_ov000_0217abd8(s32 arg0, s32 arg1) {
 extern void **gCurrentMap;
 s32 func_ov000_021a9860(s32,s32);
 s32 func_ov000_021a8fc0(s32);
 s32 func_ov000_021a98a8(s32);
 void *base;
 s32 id;
 if (func_ov000_021a9860(arg0,arg1) == 0) return 0;
 base = *gCurrentMap;
 id = M2C_FIELD(base + (arg0 + M2C_FIELD(base + arg1 * 2, u16 *, 0x3758)), u8 *, 0);
 if (id == 0) return 1;
 if (func_ov000_021a8fc0((s16)id) == 0) return 0;
 return func_ov000_021a98a8(((u32)(M2C_FIELD(*gCurrentMap + id * 14, u8 *, 0x59A4) << 26) >> 26)) == 0;
}

u8 func_ov000_0217ac78(s32 arg0, s32 arg1) {
    extern void **gCurrentMap;
    u8 temp_r2;
    u8 var_r0;
    void *temp_r3;

    temp_r3 = *gCurrentMap;
    temp_r2 = M2C_FIELD((temp_r3 + (arg0 + M2C_FIELD((temp_r3 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420);
    if ((temp_r2 & 0x1F) != 0x11) {
        return 0U;
    }
    if (M2C_FIELD(temp_r3, u16 *, 0x52A6) == (temp_r2 & 0xE0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
