/* 26 functions from 0x020A48EC to 0x020A5878 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 a,b,c,d; } Unk020APosition;
typedef struct { u8 pad[5]; u8 player:3; u8 rest:5; } Unk020APlayer;
typedef struct { u8 x,y; u16 a:3; u16 b:3; u16 type:4; u16 rest:6; u8 value; u8 player:3; u8 enabled:1; u8 mode:4; u8 extra,last; } Unk020ABaseEntry;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

Unk020AEntry *func_020a48ec(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h) {
 extern s32 *gCurrentMap;
 Unk020ABaseEntry *p=(Unk020ABaseEntry *)(*gCurrentMap+0x58a4);
 while(p->type)p++;
 p->x=a;p->y=b;
 p->a=(u16)c;p->b=(u16)d;p->type=(u16)e;
 p->player=(u8)f;p->enabled=g;
 p->value=h;
 return (Unk020AEntry*)p;
}

M2C_UNK func_020a49cc(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h,s32 i,s32 j,s32 k,s32 l) {
Unk020AEntry *func_020a48ec(s32,s32,s32,s32,s32,s32,u8,s32);
Unk020AEntry *p=func_020a48ec(a,b,c,d,e,f,g,h);u16 top=(u16)k;u16 kind=(u16)j;u8 last=l;p->mode=(u8)i;p->top=top;p->kind=kind;M2C_FIELD(p,s8 *,6)=i;p->last=last;return (s32)p;}

void func_020a4a68(Unk020AEntry *p) {while(p->type){*p=p[1];p++;}}

s32 GetFacingOffset(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x2000;
    case 1:
        return 0;
    case 2:
        return -0x2000;
    default:
        return 0;
    }
}

void func_020a4af0(s32 arg0, s32 arg1, s32 arg2) {
    func_020a49cc(arg0 - 1, arg1 - 1, 3, 3, 4, arg2, 0, 0x63, 1, 1, 0, 0x32);
}

void func_020a4b48(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_020a49cc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, u8, s32, s32, s32, s32, s32);
    func_020a49cc(arg0, arg1, 1, 1, 5, arg2, 0, 0, arg3, arg4, 0, 0x32);
}

void func_020a4b94(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 5, arg2, 0, 0, arg3, arg4, 1, 0x32);
}

void func_020a4be0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 6, arg2, 1, 0x63, arg3, arg4, 3, 0x50);
}

void func_020a4c30(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_020a49cc(arg0, arg1, 1, 1, 7, arg2, 1, 0x63, arg3, arg4, 1, 0x50);
}

u8 IsActionEntryActive(Unk020AEntry *p) {if(!p)return 0;switch(p->type){case 4:case 6:case 7:return p->value!=0;case 0:return 0;default:return 1;}}

s32 func_020a4ce8(s32 a) {
extern s32 *gCurrentMap;
Unk020AEntry *p=(Unk020AEntry *)(*gCurrentMap+0x58a4);s32 n=0;
while(p->type){if(p->type==a){if(IsActionEntryActive(p))n++;}p++;}return n!=0;
}

void func_020a4d58(void) {
    M2C_UNK func_020a4528();
    func_020a4528();
}

void ClearSelectionQueue(void) {
    extern s32 gSelectionQueueCount;
    gSelectionQueueCount = 0;
}

void AppendSelectionEntry(s32 a,s32 b,s32 c,s32 d) {
extern Unk020APosition *gSelectionQueue; extern s32 gSelectionQueueCount;
Unk020APosition *p=gSelectionQueue;
p[gSelectionQueueCount].c=a;p[gSelectionQueueCount].d=b;p[gSelectionQueueCount].a=c;p[gSelectionQueueCount].b=d;gSelectionQueueCount++;
}

s32 GetOrderCenterOffsetX(void) {
    return 1;
}

s32 GetOrderCenterOffsetY(void) {
    return 1;
}

#pragma opt_strength_reduction off
/* Queues up to four enemy units inside the radius-5 diamond around an order's
   centre, highest value-and-health score first, as map selections. */
void SelectAreaOrderTargets(Unk020AEntry *order) {
extern s32 *gCurrentMap;extern u8 gUnitKindStats[];
void SelectMapLayer(s32);void FillMapLayer(s32);void func_01ffb734(s32,s32,s32,s8);
s32 IsSameTeam(s32,s32);s32 IsUnitVisibleAtCell(s32,s32,s32);s32 func_020a600c(s32);
s32 centerX,centerY;
u16 bestX,bestY;
u8 *unit;
u32 bestScore;
s32 count,y,x,bestId;
u32 score;
u8 chosenIds[4],*out;
s32 map,seenIndex,unitId;
u16 rowOffset;
u8 *scan;
SelectMapLayer(*gCurrentMap+0x1e30);FillMapLayer(-1);
centerX=GetOrderCenterOffsetX();centerY=GetOrderCenterOffsetY();
func_01ffb734(M2C_FIELD(order,u8 *,0)+centerX,M2C_FIELD(order,u8 *,1)+centerY,5,0);
count=0;out=chosenIds;
do{
bestId=0;bestScore=0;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
map=*gCurrentMap;
if(M2C_FIELD(M2C_FIELD(map+y*4,s8 **,0x52e8),s8 *,x)<0)continue;
rowOffset=M2C_FIELD(map+y*2,u16 *,0x3758);
unitId=M2C_FIELD(rowOffset+(map+x),u8 *,0);
if(!unitId)continue;
if(IsSameTeam(M2C_FIELD(map,u16 *,0x52a4),(unitId>>6)+1)==1)continue;
if(!IsUnitVisibleAtCell(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),x,y))continue;
seenIndex=0;
if(count>0){map=*gCurrentMap;rowOffset=M2C_FIELD(map+y*2,u16 *,0x3758);unitId=M2C_FIELD(rowOffset+(map+x),u8 *,0);scan=chosenIds;
do{if(*scan==unitId)break;scan++;seenIndex++;}while(seenIndex<count);}
if(seenIndex!=count)continue;
map=*gCurrentMap;
rowOffset=M2C_FIELD(map+y*2,u16 *,0x3758);
unitId=M2C_FIELD(rowOffset+(map+x),u8 *,0);
unit=(u8 *)(map+0x59a4+unitId*14);
if(M2C_FIELD(unit,u16 *,4)&32)continue;
if(!func_020a600c(unitId))continue;
score=M2C_FIELD(gUnitKindStats+((u32)(unit[0]<<26)>>26)*112,u16 *,4)*((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25);
if(bestScore>score)continue;
bestX=(u16)x;bestY=(u16)y;bestScore=score;
map=*gCurrentMap;
rowOffset=M2C_FIELD(map+y*2,u16 *,0x3758);
bestId=M2C_FIELD(rowOffset+(map+x),u8 *,0);
}}
if(!bestId)break;
*out++=bestId;
AppendSelectionEntry(bestX,bestY,bestId,M2C_FIELD(order,s8 *,7));
count++;
}while(count<4);
if(count)return;
ClearSelectionQueue();
}
#pragma opt_strength_reduction reset
void func_020a5080(Unk020ABaseEntry *a){
extern s32 *gCurrentMap;void SelectMapLayer(s32);void FillMapLayer(s32);void func_01ffb80c(s32,s32,s32,s32);
s32 found=0,x,y,p;u8 id;
SelectMapLayer(*gCurrentMap+0x1e30);FillMapLayer(-1);func_01ffb80c(a->x,a->y,(u32)(M2C_FIELD(a,u16 *,2)<<16)>>30,0);
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
p=*gCurrentMap;
if(M2C_FIELD(((s8 **)(p+0x52e8))[y],s8 *,x)>=0){
id=M2C_FIELD(((u16 *)(p+0x3758))[y]+(p+x),u8 *,0x508);
if(id){AppendSelectionEntry((u16)x,(u16)y,id,M2C_FIELD(a,s8 *,7));found=1;}
}
}}
if(!found)ClearSelectionQueue();
}

#pragma opt_lifetimes off
void func_020a51a4(Unk020ABaseEntry *p) {
extern s32 *gCurrentMap; void SelectMapLayer(s32);void FillMapLayer(s32);void func_01ffb918(s32,s32,s32,s8,u8);s32 func_ov000_021aab4c(void *,s32,s32,s32,s32,s32);void ClearSelectionQueue(void);
s16 pos[2];s32 map; s32 centerY;register s32 right;register s32 yy;register s32 xx;register s32 zero;register u32 cy;register s32 bottom;s32 left,top,dist;
SelectMapLayer(*gCurrentMap+0x1e30);FillMapLayer(-1);
func_01ffb918(p->x,p->y,(u32)(M2C_FIELD(p,u16 *,2)<<16)>>30,0,0);
if(!func_ov000_021aab4c(pos,p->player,0,6,2,M2C_FIELD(p,s8 *,7))){ClearSelectionQueue();return;}
AppendSelectionEntry((u16)pos[0],(u16)pos[1],0,0);
left=pos[0]-2;if(left<0)left=0;
centerY=pos[1];top=centerY-2;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(pos[0]+2<right)right=pos[0]+2;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(centerY+2<bottom)bottom=centerY+2;
for(yy=top;yy<=bottom;yy++){xx=left;if(xx<=right){cy=(u16)yy;zero=0;do{
dist=zero;if(pos[0]-xx>0)dist+=pos[0]-xx;else dist+=xx-pos[0];
if(pos[1]-yy>0)dist+=pos[1]-yy;else dist+=yy-pos[1];
if(dist>=0 && dist<=2){u8 c;s32 mm=*gCurrentMap;c=M2C_FIELD(((u16 *)mm)[yy+0x1bac]+(mm+xx),u8 *,0x508);if(c)AppendSelectionEntry((u16)xx,cy,c,M2C_FIELD(p,s8 *,7));}
xx++;}while(xx<=right);}}
}
#pragma opt_lifetimes reset
s32 func_020a5364(Unk020AEntry *p,s8 color,u8 arg2) {
void func_01ffb734(s32,s32,s32,s8);void func_01ffb80c(s32,s32,s32,s32);void func_01ffb918(s32,s32,s32,s8,u8);s32 GetOrderCenterOffsetX(void);s32 GetOrderCenterOffsetY(void);extern s32 *gCurrentMap;
Unk020ABaseEntry *bp=(Unk020ABaseEntry *)p;
if(!IsActionEntryActive(p))return 0;
switch(p->type) {
case 4: {
s32 dx=GetOrderCenterOffsetX();s32 dy=GetOrderCenterOffsetY();
func_01ffb734(bp->x+dx,bp->y+dy,5,color);return 1;
}
case 6:func_01ffb80c(bp->x,bp->y,p->top,color);return 1;
case 7: {
s32 m=p->top;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)>=(s32)bp->player) m=(m+1)%3;
func_01ffb80c(bp->x,bp->y,m,color);return 1;
}
case 5:func_01ffb918(bp->x,bp->y,p->top,color,arg2);return 1;
default:return 0;
}
}

void func_020a54c4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

void func_020a54d0(void *a) {void DeleteSpriteObject();extern s32 gSelectionQueueCount;if(M2C_FIELD(a,s16 *,84)!=gSelectionQueueCount)return;DeleteSpriteObject(a);}

void func_020a54f4(void *a){
M2C_UNK SetSpriteAnimation(void *,s32);void *func_020a45f8(s16,s16);
M2C_UNK func_020b6f98(s16,s16,s32,void *);M2C_UNK func_020b7138(s16,s16,s16,s16,s32,void *);M2C_UNK func_020b7294(s16,s16,u32,s32,void *);
extern Unk020APosition *gSelectionQueue;
Unk020APosition *base=gSelectionQueue,*p,*q; s32 i=0;s16 n,m;void *entry;
while(base[i].a==0)i++;
n=M2C_FIELD(a,s16 *,0x54);if(base[n].a)return;p=(Unk020APosition *)((u8 *)base+i);
switch(p->b){
default:break;
case 4:func_020b6f98((s16)p->c,(s16)p->d,n+1,a);break;
case 6:case 7:
entry=func_020a45f8((s16)p->c,(s16)p->d);
m=M2C_FIELD(a,s16 *,0x54);q=&base[m];
func_020b7294((s16)q->c,(s16)q->d,(u32)(M2C_FIELD(entry,u16 *,2)<<16)>>30,m+1,a);break;
case 5:q=&base[n+1];func_020b7138((s16)p->c,(s16)p->d,(s16)q->c,(s16)q->d,n+2,a);
M2C_FIELD(a,s16 *,0x54)++;break;
}
M2C_FIELD(a,s16 *,0x54)++;SetSpriteAnimation(a,0);
}

void func_020a561c(void *arg0) {
    extern s32 *gCurrentMap;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (*gCurrentMap + 0x58A4);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x44) = 0;
}

void func_020a5648(void) {
extern s32 *gCurrentMap;
Unk020AEntry *p=(Unk020AEntry *)(*gCurrentMap+0x58a4);
while(p->type){if(IsActionEntryActive(p)&& ((Unk020APlayer *)p)->player==M2C_FIELD(*gCurrentMap,u16 *,0x52a4)){
switch(p->type){case 4:case 5:case 6:case 7: M2C_FIELD(p,s8 *,6)-=1;break;}
}p++;}
}

void func_020a5700(void *arg0) {
extern s32 *gCurrentMap;
void ClearSelectionQueue(void);s32 SetSpriteAnimation(void *,s32);
ClearSelectionQueue();
while(M2C_FIELD(arg0,Unk020AEntry **,0x34)->type) {
if(IsActionEntryActive(M2C_FIELD(arg0,Unk020AEntry **,0x34))) {
s32 type; Unk020AEntry *p=M2C_FIELD(arg0,Unk020AEntry **,0x34);
if((s32)((Unk020ABaseEntry *)p)->player==M2C_FIELD(*gCurrentMap,u16 *,0x52a4) && M2C_FIELD(p,s8 *,6)==0) {
type=p->type; switch(type) {
case 4:
AppendSelectionEntry(((Unk020ABaseEntry *)p)->x,((Unk020ABaseEntry *)p)->y,0,type);
SelectAreaOrderTargets(M2C_FIELD(arg0,Unk020AEntry **,0x34));
M2C_FIELD(M2C_FIELD(arg0,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(arg0,Unk020AEntry **,0x34)->kind;
M2C_FIELD(arg0,Unk020AEntry **,0x34)++;
return;
case 6:case 7:
AppendSelectionEntry(((Unk020ABaseEntry *)p)->x,((Unk020ABaseEntry *)p)->y,0,type);
func_020a5080(M2C_FIELD(arg0,Unk020ABaseEntry **,0x34));
M2C_FIELD(M2C_FIELD(arg0,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(arg0,Unk020AEntry **,0x34)->kind;
M2C_FIELD(arg0,Unk020AEntry **,0x34)++;
return;
case 5:
AppendSelectionEntry(((Unk020ABaseEntry *)p)->x,((Unk020ABaseEntry *)p)->y,0,type);
func_020a51a4(M2C_FIELD(arg0,Unk020ABaseEntry **,0x34));
M2C_FIELD(M2C_FIELD(arg0,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(arg0,Unk020AEntry **,0x34)->kind;
M2C_FIELD(arg0,Unk020AEntry **,0x34)++;
return;
}
}}
M2C_FIELD(arg0,Unk020AEntry **,0x34)++;
}
SetSpriteAnimation(arg0,1);
}

