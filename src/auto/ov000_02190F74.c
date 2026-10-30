/* 3 functions from 0x02190F74 to 0x02191970 (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 *data_ov000_021df580;
void func_01ffc328(void *);
void func_01ffb9c4(int);
int func_020d27a4(int,int);
int func_ov000_021a98a8(int);int func_ov000_021a98e4(int);
int func_ov000_021a8a88(void *);
int func_ov000_021a93ec(s16,s16);
int func_ov000_02177f24(int,int,s16 *);
int func_ov000_02176e28(int,s16 *);
int func_ov000_0217a0a8(void *);
int func_ov000_021aa820(s16 *,u16,int,int);
void func_ov000_02199d74(s16,s16,int,int,int);
void func_ov000_02199f38(void);
void func_ov000_0217c3a4(void);

typedef struct { u8 kind:6;u8 flags:2;u8 pad[5];u16 health:7;u16 flags2:4;u16 value:5;u8 tail[6]; } Unit1911;
typedef struct { u8 pad[0x3758];u16 rows[64];u8 pad2[0x196c];u16 width,height;u8 pad3[0x188];Unit1911 *selected;u8 pad4[0x14];s8 *grid[64]; } Map1911;
typedef struct {u8 pad[7];u8 low:3;u8 active:1;u8 upper:4;} AIState1913;
static inline int AdjacentMin1913(int a,int b){if(a<b)b=a;return b;}
static inline int AdjacentMax1913(int a,int b){if(a<b)a=b;return a;}
static inline int CountAdjacentBounds1913(u8 ux,u8 uy){
 int n=0,xmin,xmax,ymin,ymax,ny,nx;
 Map1911 *map;
 xmin=AdjacentMax1913(ux-1,0);
 ymin=AdjacentMax1913(uy-1,0);
 map=*gCurrentMap;
 xmax=AdjacentMin1913(ux+1,map->width-1);
 ymax=AdjacentMin1913(uy+1,map->height-1);
 for(ny=ymin;ny<=ymax;ny++){
 for(nx=xmin;nx<=xmax;nx++){
 int dist=0;
 if(ux-nx>0)dist+=ux-nx;else dist+=nx-ux;
 if(uy-ny>0)dist+=uy-ny;else dist+=ny-uy;
 if(dist<1)continue;
 if(dist>1)continue;
 {
 Unit1911 *other;
 map=*gCurrentMap;
 if(map->grid[ny][nx]<0)continue;
 other=(Unit1911 *)((u8 *)map+0x59a4)+((u8 *)map+map->rows[ny])[nx];
 if(other->kind!=0 && (M2C_FIELD(other,u16 *,4)&1))continue;
 n++;
 }
 }}
 return n;
}

static inline s32 Health1911(Unit1911 *u) {s32 h=u->health;return h?func_0207c8ec(h-1,10)+1:0;}

/* AI heal pass: mark the selected (medic) unit as acting, then scan every tile
 * on the map. For each living unit (value != 0) of the same kind as the selected
 * unit, not already at full health (h != 10), trigger the heal routine
 * (func_ov000_02199d74) at that tile when the combined health clears one of the
 * thresholds: the unit's cell attribute is a healable type (func_ov000_021a91d0)
 * and h+cur<=15; or cur<7 and h+cur<=12; or h+cur<=10. opt_common_subs is
 * disabled because the three heal checks intentionally duplicate the call. */
void func_ov000_02190f74(void){
#pragma push
#pragma opt_common_subs off
extern void **gCurrentMap;
void func_01ffc328(void *);
s32 func_ov000_021a8fc0(s16);
s32 func_0207c8ec(s32,s32);
void func_ov000_02199d74(s16,s16,s32,s32,s32);
s32 func_ov000_021a91d0(u8);
s32 id; Unit1911 *unit; s32 x,y,h,cur; Map1911 *map;
func_01ffc328(M2C_FIELD(*gCurrentMap,void **,0x52d0));
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(map->grid[y][x]<0)continue;
id=((u8 *)map)[x+map->rows[y]];
if(!id)continue;
if(!func_ov000_021a8fc0((s16)id))continue;
map=*gCurrentMap;unit=(Unit1911 *)((u8 *)map+0x59a4)+id;
if(!unit->value)continue;
if(unit->kind!=map->selected->kind)continue;
h=Health1911(unit);
if(h==10)continue;
cur=Health1911(((Map1911 *)*gCurrentMap)->selected);
map=*gCurrentMap;
if(func_ov000_021a91d0(M2C_FIELD((u32)map+M2C_FIELD(unit,u8 *,1)+map->rows[M2C_FIELD(unit,u8 *,2)],u8 *,0x1420))&&h+cur<=15)
func_ov000_02199d74((s16)x,(s16)y,9,0,0);
if(cur<7&&h+cur<=12)func_ov000_02199d74((s16)x,(s16)y,9,0,0);
if(h+cur<=10)func_ov000_02199d74((s16)x,(s16)y,9,0,0);
}
}
#pragma pop
}

void func_ov000_021911bc(void){
#pragma push
#pragma opt_common_subs off
extern void **gCurrentMap;
void func_01ffc328(void *);
s32 func_ov000_021a8fc0(s16);
s32 func_0207c8ec(s32,s32);
void func_ov000_02199d74(s16,s16,s32,s32,s32);
s32 id,x,y,h,cur;Map1911 *map;Unit1911 *unit;
func_01ffc328(M2C_FIELD(*gCurrentMap,void **,0x52d0));
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(map->grid[y][x]<0)continue;
id=((u8 *)map)[x+map->rows[y]];
if(!id)continue;
if(!func_ov000_021a8fc0((s16)id))continue;
map=*gCurrentMap;unit=(Unit1911 *)((u8 *)map+0x59a4)+id;
if(!unit->value)continue;
if(unit->kind!=map->selected->kind)continue;
h=Health1911(unit);
if(h==10)continue;
cur=Health1911(((Map1911 *)*gCurrentMap)->selected);
if(h>=7&&cur>=7)continue;
if(h+cur>15)continue;
func_ov000_02199d74((s16)x,(s16)y,9,0,0);
}
}
#pragma pop
}

void func_ov000_0219137c(void){
#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
 int destX=-1,destY=-1,portX=-1,portY=-1;
 int portDistance=110,best=0,score,unitId=0;
 int y,x;
 Map1911 *map;Unit1911 *unit;
 s16 position[2];
 func_01ffc328(((Map1911 *)*gCurrentMap)->selected);
 func_01ffb9c4(111);
 for(y=0;y<((Map1911 *)*gCurrentMap)->height;y++){
 for(x=0;x<((Map1911 *)*gCurrentMap)->width;x++){
 int distance;
 map=*gCurrentMap;
 distance=map->grid[y][x];
 if(distance<0)continue;
 if((((u8 *)map)[x+map->rows[y]+0x1420]&31)==24 && ((u8 *)map)[x+map->rows[y]]==0 && distance<portDistance){
 portDistance=distance;portX=x;portY=y;
 }
 unit=(Unit1911 *)((u8 *)map+0x59a4)+((u8 *)map)[x+map->rows[y]];
 if(unit->kind==0)continue;
 if(func_020d27a4(M2C_FIELD(map,u8 *,0x52d4),unit?unit-(Unit1911 *)((u8 *)map+0x59a4):0)==1)continue;
 if(!func_ov000_021a98a8(unit->kind)){
 if(func_ov000_021a98e4(unit->kind)==1)goto candidate_checks;
 if(!func_ov000_021a98a8(((Map1911 *)*gCurrentMap)->selected->kind))goto candidate_checks;
 switch(((Map1911 *)*gCurrentMap)->selected->flags2){case 0:continue;default:goto candidate_checks;}
 }else if(!func_ov000_021a8a88(unit)){
 if(unit->health<=30)continue;
 if(!unit->value && unit->health<=60)continue;
 }
 candidate_checks:
 if(!func_ov000_021a93ec((s16)x,(s16)y))continue;
 if(!func_ov000_02177f24(x,y,position))continue;
 map=*gCurrentMap;
 score=func_ov000_02176e28(((u8 *)map)[x+map->rows[y]],position);
 if(!score)continue;
 if(((Map1911 *)*gCurrentMap)->selected->kind==1 && !func_ov000_021a98a8(unit->kind) && M2C_FIELD(*gCurrentMap,s16 *,0x6ee6)!=0 && M2C_FIELD(*gCurrentMap,s16 *,0x6ef2)<15)continue;
 if(score<best)continue;
 if(func_ov000_0217a0a8(unit)==1 && CountAdjacentTernary1913(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2))<=1)continue;
 best=score;destX=position[0];destY=position[1];
 map=*gCurrentMap;unitId=((u8 *)map)[x+map->rows[y]];
 }}
 if(portX!=-1){
 position[0]=portX;position[1]=portY;
 if(func_ov000_021aa820(position,M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1,0)==1){
 func_ov000_02199d74((s16)portX,(s16)portY,19,(u8)position[0],(u8)position[1]);return;
 }}
 if(best==0)return;
 if(((AIState1913 *)data_ov000_021df580)->active){func_ov000_02199f38();return;}
 func_ov000_0217c3a4();
 func_ov000_02199d74((s16)destX,(s16)destY,4,(u8)unitId,0);
#pragma pop
}

