/* 7 functions from 0x02194AB8 to 0x021959CC (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; } UnitKind1955;

#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_instruction_scheduling off
int func_ov000_02194ab8(short *arg0) {
void func_ov000_02179be0(void);
void func_ov000_02179d3c(void);
s32 func_ov000_021a98e4(s32);
s32 func_020a76d4(void *);
s32 func_020d1938(s32);
s32 func_020d273c(s32,s32);
s32 func_ov000_021a947c(s32,s32,s32,s32);
s32 func_020a600c(u16);
s32 func_ov000_021a96f4(s32,s32,s32);
s32 func_ov000_021a96a8(s32,s32,s32);
s32 func_ov000_021a98a8(s32);
s32 func_020d27ec(s32,s32);
s32 func_ov000_0217d000(s32,s32);
void func_01ffc2e8(void *);
void func_01ffb9c4(s32);
s32 func_ov000_021a89a4(void *);
s32 func_ov000_02179e48(s16 *);
s32 RandomIntRange(s32,s32);
extern void **gCurrentMap;
extern void *data_ov000_021df580;
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021b5bfc[];
s32 high=0x7fff,mid=0x7fff,low=0x7fff;
s16 posHigh[2];
s32 a;
volatile u16 posMid[2],posLow[2];
s32 offset;
s32 threshold,team,id,value,cost,kind,x,y,terrain,index,xx,yy,x0,y0,x1,y1,sum,delta;
u8 *map,*unit,*selected;
func_ov000_02179be0();
func_ov000_02179d3c();
if(!(M2C_FIELD(data_ov000_021df580,u16 *,8)&32)&&func_ov000_021a98e4((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind)==1){
threshold=func_020a76d4(M2C_FIELD(*gCurrentMap,void **,0x52d0))+M2C_FIELD(data_ov000_021df580,u8 *,5);
}else threshold=0;
for(team=1;team<5;team++){
if(!func_020d1938(team))continue;
if(func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),team)==1)continue;
id=gPlayerUnitIdBase[team]+1;
offset=id*14;
for(;id<gPlayerUnitIdBase[team]+51;id++,offset+=14){
map=*gCurrentMap;unit=(map+0x59a4)+offset;
kind=((UnitKind1955 *)unit)->kind;
if(!kind)continue;
if(M2C_FIELD(unit,u16 *,4)&8)continue;
x=unit[1];y=unit[2];
if(M2C_FIELD(map+(y)*4,s8 **,0x52e8)[x]<0)continue;
if(!((u32)(unit[11]<<25)>>31)&&!func_ov000_021a947c(M2C_FIELD(map,u16 *,0x52a4),kind,x,y))continue;
if(((UnitKind1955 *)unit)->kind==22&&(*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind!=23&&!func_020a600c((u16)id))continue;
if(M2C_FIELD(unit,u16 *,4)&32){
if(!func_ov000_021a96f4((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind,((UnitKind1955 *)unit)->kind,0))continue;
}
kind=(*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind;
if(kind==21)value=func_ov000_021a96a8(17,((UnitKind1955 *)unit)->kind,0);else value=func_ov000_021a96a8(kind,((UnitKind1955 *)unit)->kind,0);
map=*gCurrentMap;
cost=M2C_FIELD(map+(unit[2])*4,s8 **,0x52e8)[unit[1]];
kind=(*(UnitKind1955 **)(map+0x52d0))->kind;
if(kind==23&&((UnitKind1955 *)unit)->kind==22)cost>>=2;
if(kind==16){if(data_ov000_021b5bfc[((UnitKind1955 *)unit)->kind*112+19]&16)value<<=1;else value>>=1;}
if(value<20){
if(!func_ov000_021a98a8(kind))continue;
if(low<=threshold){if(cost>threshold||cost<low)continue;}else if(cost>low)continue;
low=cost;posLow[0]=unit[1];posLow[1]=unit[2];
}else if(value<50){
if(mid<=threshold){if(cost>threshold||cost<mid)continue;}else if(cost>mid)continue;
posMid[0]=unit[1];posMid[1]=unit[2];mid=cost;
}else{
if(high<=threshold){if(cost>threshold||cost<high)continue;}else if(cost>high)continue;
posHigh[0]=unit[1];posHigh[1]=unit[2];high=cost;
}
}}
map=*gCurrentMap;
index=M2C_FIELD(map+(posHigh[1])*2,u16 *,0x3758)+posHigh[0];
id=M2C_FIELD(map+index,u8 *,0x508);
if(!id||((UnitKind1955 *)(map+0x59a4+id*14))->kind!=22||(*(UnitKind1955 **)(map+0x52d0))->kind!=23){
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(M2C_FIELD(map+(y)*4,s8 **,0x52e8)[x]<0)continue;
index=M2C_FIELD(map+(y)*2,u16 *,0x3758);
terrain=map[index+x+0x1420];
if(!(terrain&224))continue;
if(func_020d27ec(M2C_FIELD(map,s16 *,0x52a8),terrain&255)==1)continue;
if(!func_ov000_0217d000((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind,terrain))continue;
map=*gCurrentMap;
if(high<=threshold){cost=M2C_FIELD(map+(y)*4,s8 **,0x52e8)[x];if(cost>threshold||cost<high)continue;}
else if(M2C_FIELD(map+(y)*4,s8 **,0x52e8)[x]>high)continue;
posHigh[0]=x;posHigh[1]=y;
high=M2C_FIELD(*gCurrentMap+(y)*4,s8 **,0x52e8)[x];
}}}
if(high==0x7fff){if(mid==0x7fff){if(low==0x7fff)return 0;posHigh[0]=posLow[0];posHigh[1]=posLow[1];}
else{posHigh[0]=posMid[0];posHigh[1]=posMid[1];}}
map=*gCurrentMap;selected=M2C_FIELD(map,u8 **,0x52d0);
if(((UnitKind1955 *)selected)->kind==23){
index=M2C_FIELD(map+(posHigh[1])*2,u16 *,0x3758)+posHigh[0];id=M2C_FIELD(map+index,u8 *,0x508);unit=map+0x59a4+id*14;
if(id&&!((u32)(unit[11]<<25)>>31)&&((UnitKind1955 *)unit)->kind==22&&(M2C_FIELD(unit,u16 *,4)&32)&&!(M2C_FIELD(unit,u16 *,4)&64)){
func_01ffc2e8(selected);func_01ffb9c4(111);
map=*gCurrentMap;x=posHigh[0];y=posHigh[1];
high=M2C_FIELD(map+(y)*4,s8 **,0x52e8)[x];
if(high>=0){
if(high>110){
x0=x-1;if(x0<0)x0=0;y0=y-1;if(y0<0)y0=0;
x1=M2C_FIELD(map,u16 *,0x5144)-1;if(x+1<x1)x1=x+1;
y1=M2C_FIELD(map,u16 *,0x5146)-1;if(y+1<y1)y1=y+1;high=-1;
for(yy=y0;yy<=y1;yy++){for(xx=x0;xx<=x1;xx++){
sum=0;delta=x-xx;if(delta>0)sum+=delta;else sum+=xx-x;
delta=y-yy;if(delta>0)sum+=delta;else sum+=yy-y;
if(sum<1)continue;if(sum>1)continue;
{cost=M2C_FIELD(*gCurrentMap+(yy)*4,s8 **,0x52e8)[xx];
if(cost>=0&&cost<=110&&high<=cost)high=cost;}
}}
if(high==-1)high=func_ov000_021a89a4(M2C_FIELD(map,void **,0x52d0));
}
map=*gCurrentMap;x=posHigh[0];y=posHigh[1];
x0=x-3;if(x0<0)x0=0;y0=y-3;if(y0<0)y0=0;
x1=M2C_FIELD(map,u16 *,0x5144)-1;if(x+3<x1)x1=x+3;
y1=M2C_FIELD(map,u16 *,0x5146)-1;if(y+3<y1)y1=y+3;
sum=1;
for(yy=y0;yy<=y1;yy++)for(xx=x0;xx<=x1;xx++){
value=0;delta=x-xx;if(delta>0)value+=delta;else value+=xx-x;
delta=y-yy;if(delta>0)value+=delta;else value+=yy-y;
if(value<1||value>3)continue;
cost=M2C_FIELD(*gCurrentMap+(yy)*4,s8 **,0x52e8)[xx];
if(cost<0||cost>110)continue;
if(cost>=high)sum++;
}
sum=RandomIntRange(0,sum-1);
if(sum){
map=*gCurrentMap;x=posHigh[0];y=posHigh[1];
x0=x-3;if(x0<0)x0=0;y0=y-3;if(y0<0)y0=0;
x1=M2C_FIELD(map,u16 *,0x5144)-1;if(x+3<x1)x1=x+3;
y1=M2C_FIELD(map,u16 *,0x5146)-1;if(y+3<y1)y1=y+3;
for(yy=y0;yy<=y1;yy++)for(xx=x0;xx<=x1;xx++){
value=0;delta=x-xx;if(delta>0)value+=delta;else value+=xx-x;
delta=y-yy;if(delta>0)value+=delta;else value+=yy-y;
if(value<1||value>3)continue;
cost=M2C_FIELD(*gCurrentMap+(yy)*4,s8 **,0x52e8)[xx];
if(cost<0||cost>110||cost<high)continue;
if(--sum==0){posHigh[0]=xx;posHigh[1]=yy;goto finish;}
}
}

}
}
}
finish:
if(!func_ov000_02179e48(posHigh))return 0;
arg0[0]=posHigh[0];arg0[1]=posHigh[1];return 1;
}
#pragma opt_instruction_scheduling reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov000_021954a4(void) {
    s32 func_ov000_02194ab8(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_02194ab8(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

s32 func_ov000_021954dc(s16 *arg0) {
    void func_ov000_02179be0();
    void func_ov000_02179d3c();
    s32 func_ov000_021786a8(s16 *);
    s32 func_ov000_02179e48(s16 *);
    s16 sp0[2];

    func_ov000_02179be0();
    func_ov000_02179d3c();
    if (func_ov000_021786a8(sp0) == 0) {
        return 0;
    }
    if (func_ov000_02179e48(sp0) == 0) {
        return 0;
    }
    arg0[0] = sp0[0];
    arg0[1] = sp0[1];
    return 1;
}

void func_ov000_0219553c(void) {
    s32 func_ov000_021954dc(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_021954dc(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02195574(s16 *out) {
s32 func_ov000_021a98e4(s32);
void func_ov000_02179be0(void);
void func_ov000_02179d3c(void);
s32 func_020ba924(s32,s32);
s32 func_ov000_0217bc34(s32,s32,s32,s32);
s32 func_ov000_02179e48(s16 *);
extern void **gCurrentMap;
extern void *data_ov000_021df57c;
s32 best=0x7fff;
s16 cand[2];
s32 x,y,kind;
kind=func_ov000_021a98e4((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind)==1?2:1;
func_ov000_02179be0();
func_ov000_02179d3c();
for(y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++){
for(x=0;x<*(u16 *)((u8 *)*gCurrentMap+0x5144);x++){
u8 *map;
register s32 cell;
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x]<0)continue;
if(!func_020ba924(x,y))continue;
map=(u8 *)*gCurrentMap;
cell=*(s8 *)(*(u16 *)(map+0x3758+y*2)+(map+x)+0x1928);
map = (u8 *)((u32)map + cell*6);
if((map+kind)[0x6c63]>=((u8 *)data_ov000_021df57c)[13])continue;
if(best<(*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x])continue;
if(!func_ov000_0217bc34(x,y,2,5))continue;
cand[0]=x;cand[1]=y;
best=(*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x];
}}
if(best==0x7fff)return 0;
if(!func_ov000_02179e48(cand))return 0;
out[0]=cand[0];out[1]=cand[1];return 1;
}
#pragma opt_strength_reduction reset
void func_ov000_02195750(void) {
    s32 func_ov000_02195574(s16 *);
    s32 func_ov000_0217e6bc(s16, s16);
    void PlanMoveDestination(s16, s16);
    s16 sp0[2];

    if (func_ov000_02195574(sp0) == 0) {
        return;
    }
    if (func_ov000_0217e6bc(sp0[0], sp0[1]) == 0) {
        return;
    }
    PlanMoveDestination(sp0[0], sp0[1]);
}

#pragma opt_strength_reduction off
s32 func_ov000_02195788(s16 *out) {
    s32 func_ov000_021a8ff0(s32);
    s32 func_ov000_021a98e4(s32);
    s32 func_ov000_0217bc34(s32, s32, s32, s32);
    void func_01ffada0(u8, u8, s32, s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5c0f[];
    extern void *data_ov000_021df644;
    UnitKind1955 *up;
    s8 **rows;
    s32 unitKind;
    u8 attr;
    register s32 resX=-1, resY=-1, best=0x7fff, y, x;
    u16 height, width;
    s32 ok;
    up = *(UnitKind1955 **)((u8 *)*gCurrentMap + 0x52d0);
    unitKind = up->kind;
    attr = data_ov000_021b5c0f[unitKind * 0x70];
    if (attr & 0x20) return 0;
    func_01ffada0(((u8 *)up)[1], ((u8 *)up)[2], unitKind, 110, 0);
    for (y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++) {
        for (x = 0; x < *(u16 *)((u8 *)*gCurrentMap+0x5144); x++) {
            u8 *map; u16 rowOff; u8 grid0; s8 cand; u8 grid1; u8 thr;
            if ((*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x] < 0) continue;
            map = (u8 *)*gCurrentMap;
            rowOff = *(u16 *)(map + 0x3758 + y * 2);
            grid0 = *(u8 *)(map + x + rowOff + 0x1420);
            if (func_ov000_021a8ff0(grid0 & 0x1f) == 0) continue;
            map = (u8 *)*gCurrentMap;
            rowOff = *(u16 *)(map + 0x3758+y*2);
            grid0 = *(u8 *)(map+x+rowOff+0x1420);
            if (*(u16 *)(map + 0x52a6) != (grid0 & 0xe0)) continue;
            cand = (*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x];
            if (best < cand) continue;
            if (!func_ov000_0217bc34(x, y, 2, 5)) continue;
            ok = func_ov000_021a98e4((*(UnitKind1955 **)((u8 *)*gCurrentMap+0x52d0))->kind);
            if (ok == 1) {
                thr = ((u8 *)data_ov000_021df644)[2];
                map=(u8 *)*gCurrentMap; rowOff=*(u16 *)(map+0x3758+y*2);
                grid1 = *(u8 *)(map + x + rowOff + 0x2d48);
                if (grid1 >= thr) continue;
            }
            resX = x; resY = y; best = (*(s8 **)((u8 *)*gCurrentMap+0x52e8+y*4))[x];
        }
    }
finish:
    if (best == 0x7fff) return 0;
    out[0] = (s16)resX; out[1] = (s16)resY;
    return 1;
}
#pragma opt_strength_reduction reset

