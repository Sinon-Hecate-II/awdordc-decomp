/* 1 function from 0x0219234C to 0x02192D88 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 gMovementCostTable[];
extern u8 data_ov000_021b5bfc[];
extern s8 data_ov000_021b55a0[];
#define MAP (*gCurrentMap)
#define SEL M2C_FIELD(MAP,void **,0x52d0)
#define ROW(y) M2C_FIELD(MAP+(y)*2,u16 *,0x3758)
#define CELL(x,y,off) M2C_FIELD(MAP+(x)+ROW(y),s8 *,off)
#define TILE(x,y) M2C_FIELD(MAP+(x)+ROW(y),u8 *,0x1420)
#define KIND(p) ((u32)(M2C_FIELD(p,u8 *,0)<<26)>>26)

#pragma optimization_level 4
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_strength_reduction off
#pragma opt_peephole off
void func_ov000_0219234c(void *arg0) {
void SelectMapLayer(void *);void func_01ffada0(s32,s32,u32,s32,s32);
s32 func_ov000_021a9d8c(s16,s16);s32 IsCurrentPlayerUnit(u32);s32 func_ov000_021a8ff0(u32);
s32 func_ov000_02178518(s32,s32,s16 *);s32 func_ov000_0217bd44(s32,s32,s32,s32);
void SetMapCursor(s16,s16,s32,s32,s32);
s32 func_ov000_021a97e0(u32,u32);s32 func_020d27ec(u32,u32);
void *unit; s32 ux,uy,range,n,d,score,bestX,bestY,candX,candY;void *m,*p; s8 *cost; s16 point[2];s8 *table;
m=MAP;d=M2C_FIELD(SEL,u8 *,12);unit=m+0x59a4+d*14;if(!d)return;
d=M2C_FIELD(unit,u16 *,8);uy=(u32)(d<<20)>>26;n=M2C_FIELD(m+uy*2,u16 *,0x3758);ux=(u32)(d<<26)>>26;d=M2C_FIELD(m+(n+ux),u8 *,0x1420);
if(((d&0xe0)&&(d&31)!=15)||
(func_ov000_021a9d8c((s16)ux,(s16)uy)&&!IsCurrentPlayerUnit(M2C_FIELD(MAP+ux+ROW(uy),u8 *,0x508)))){
M2C_FIELD(unit,u8 *,11)&=~15;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|63;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|0xfc0;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~63)|63;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~0xfc0)|0xfc0;
M2C_FIELD(SEL,u8 *,11)&=~15;
func_ov000_02199f38();
}
func_01ffc328(SEL);func_01ffb9c4(111);
if(M2C_FIELD(M2C_FIELD(MAP+uy*4,s8 **,0x52e8),s8 *,ux)>=0&&!func_ov000_021a9d8c((s16)ux,(s16)uy)&&(!func_ov000_021a8ff0(TILE(ux,uy))||M2C_FIELD(MAP+ux+ROW(uy),u8 *,0x508)==0)&&func_ov000_02178518(ux,uy,point)){
m=MAP;n=M2C_FIELD(m+uy*2,u16 *,0x3758);p=m+0x6c60;d=M2C_FIELD(m+(ux+n),s8 *,0x1928);p+=d*6;M2C_FIELD(p,u8 *,3)++;
d=func_ov000_0217bd44(point[0],point[1],ux,uy);
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~63)|63;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~0xfc0)|0xfc0;
M2C_FIELD(SEL,u8 *,11)&=~15;
M2C_FIELD(unit,u8 *,11)=(M2C_FIELD(unit,u8 *,11)&~15)|1;
SetMapCursor(point[0],point[1],8,(u8)d,0);
}
SelectMapLayer(MAP+0x2338);
range=func_ov000_021a97e0(M2C_FIELD(MAP,u16 *,0x52a4),KIND(unit));
func_01ffada0(ux,uy,KIND(unit),range,0);
{ s32 sx,sy,nx,ny,lx,ly,hx,hy,invalid;
for(sy=0;sy<M2C_FIELD(MAP,u16 *,0x5146);sy++){
table=M2C_FIELD(gMovementCostTable,s8 **,0x64);
invalid=-1;
for(sx=0;sx<M2C_FIELD(MAP,u16 *,0x5144);sx++){
d=M2C_FIELD(M2C_FIELD(MAP+sy*4,s8 **,0x52e8),s8 *,sx);
if(d<0||d!=range-1)continue;
lx=sx-1;if(lx<0)lx=0;ly=sy-1;if(ly<0)ly=0;
hx=M2C_FIELD(MAP,u16 *,0x5144)-1;if(sx+1<hx)hx=sx+1;
hy=M2C_FIELD(MAP,u16 *,0x5146)-1;if(sy+1<hy)hy=sy+1;
for(ny=ly;ny<=hy;ny++)for(nx=lx;nx<=hx;nx++){
score=0;d=sx-nx;if(d<=0)d=nx-sx;score+=d;d=sy-ny;if(d>0)score+=d;else score+=ny-sy;
if(score<1||score>1)continue;
m=MAP;cost=M2C_FIELD(m+ny*4,s8 **,0x52e8);
if(cost[nx]<0){
p=data_ov000_021b5bfc+KIND(unit)*112;
if(table[M2C_FIELD(p,u8 *,18)*32+(TILE(nx,ny)&31)]!=invalid)cost[nx]=(s8)range;
}
}
}
}
}
{ s32 bestD,y,x,bestScore;
SelectMapLayer(MAP+0x1e30);
bestX=-1;bestY=-1;candX=-1;candY=-1;bestD=32767;bestScore=-1;
for(y=0;y<M2C_FIELD(MAP,u16 *,0x5146);y++)for(x=0;x<M2C_FIELD(MAP,u16 *,0x5144);x++){
if(M2C_FIELD(M2C_FIELD(MAP+y*4,s8 **,0x52e8),s8 *,x)<0||func_ov000_021a9d8c((s16)x,(s16)y)|| (func_ov000_021a8ff0(TILE(x,y))&&M2C_FIELD(MAP+x+ROW(y),u8 *,0x508))||CELL(x,y,0x2338)<0||!func_ov000_02178518(x,y,point))continue;
score=CELL(x,y,0x2338);
if(data_ov000_021b55a0[TILE(x,y)&31]&&func_020d27ec(M2C_FIELD(MAP,u8 *,0x52d4),TILE(x,y)))score+=func_ov000_021a97e0(M2C_FIELD(MAP,u16 *,0x52a4),KIND(unit));
d=M2C_FIELD(MAP+x+ROW(y),u8 *,0x2840)+M2C_FIELD(MAP+x+ROW(y),u8 *,0x2d48);
if(bestD<d)continue;
if(bestD==d&&bestScore<score)continue;
bestD=d;candX=point[0];candY=point[1];bestX=x;bestY=y;bestScore=score;
}

if(bestScore!=-1){
m=MAP;p=m+0x6c60+CELL(ux,uy,0x1928)*6;M2C_FIELD(p,u8 *,3)++;
d=func_ov000_0217bd44(candX,candY,bestX,bestY);
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~63)|63;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~0xfc0)|0xfc0;
M2C_FIELD(SEL,u8 *,11)&=~15;
M2C_FIELD(unit,u8 *,11)=(M2C_FIELD(unit,u8 *,11)&~15)|1;
SetMapCursor((s16)candX,(s16)candY,8,d,0);
}
p=SEL;func_01ffada0(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),KIND(p),110,1);
if(M2C_FIELD(M2C_FIELD(MAP+uy*4,s8 **,0x52e8),s8 *,ux)<0){
M2C_FIELD(unit,u8 *,11)&=~15;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|63;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|0xfc0;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~63)|63;
M2C_FIELD(SEL,u16 *,8)=(M2C_FIELD(SEL,u16 *,8)&~0xfc0)|0xfc0;
func_ov000_02199f38();
}
PlanMoveDestination(ux,uy);
}
}
#pragma optimization_level reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma opt_peephole reset
