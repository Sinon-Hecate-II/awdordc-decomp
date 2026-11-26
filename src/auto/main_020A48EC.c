/* 26 functions from 0x020A48EC to 0x020A5878 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef union { struct { u16 a,b,c,d; }; struct { u16 unitId,orderType,x,y; }; } Unk020APosition;
typedef struct { u8 pad[5]; u8 player:3; u8 rest:5; } Unk020APlayer;
typedef struct { u8 x,y; u16 a:3; u16 b:3; u16 type:4; u16 rest:6; u8 value; u8 player:3; u8 enabled:1; u8 mode:4; u8 extra,last; } Unk020ABaseEntry;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

/* s16 cursor into the selection queue held by an order-effect sprite. */
#define ORDER_SPRITE_QUEUE_CURSOR 0x54

/* Append an order record to the map's order queue (entries at map+0x58A4, the
   first one with type 0 is free): tile (a,b), counts c/d, order type e, player f,
   enabled flag g and value h.  Returns the new record. */
Unk020AEntry *AddMapOrder(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u8 g,s32 h) {
 extern s32 *gCurrentMap;
 Unk020ABaseEntry *p=(Unk020ABaseEntry *)(*gCurrentMap+0x58a4);
 while(p->type)p++;
 p->x=a;p->y=b;
 p->a=(u16)c;p->b=(u16)d;p->type=(u16)e;
 p->player=(u8)f;p->enabled=g;
 p->value=h;
 return (Unk020AEntry*)p;
}

/* Queue a map order and also set its playback fields: mode (which doubles as
 * the initial countdown), kind, top and last.  Returns the new record. */
M2C_UNK AddMapOrderEx(s32 x,s32 y,s32 width,s32 height,s32 type,s32 player,u8 enabled,s32 value,s32 mode,s32 kind,s32 top,s32 last) {
Unk020AEntry *AddMapOrder(s32,s32,s32,s32,s32,s32,u8,s32);
Unk020AEntry *p=AddMapOrder(x,y,width,height,type,player,enabled,value);
u16 topBits=(u16)top;u16 kindBits=(u16)kind;u8 lastByte=last;p->mode=(u8)mode;p->top=topBits;p->kind=kindBits;M2C_FIELD(p,s8 *,6)=mode;p->last=lastByte;return (s32)p;}

/* Remove a map order from the map's order queue (entries from map+MAP_ORDERS): shift
 * every later entry down one slot, stopping at the free entry (type 0) that ends
 * the queue. */
void RemoveMapOrder(Unk020AEntry *order) {
    while (order->type) {
        *order = order[1];
        order++;
    }
}

/* Return the signed sprite tile offset of a unit facing `facing` (0..3, the top
 * two bits of the unit's facing word): facing right (0) adds 0x2000 tiles to the
 * sprite's base tile, facing left (2) subtracts it, and up/down are centred. */
s32 GetFacingOffset(s32 facing) {
    switch (facing) {
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

/* Queue a 3x3 area attack (MAPORDER_ATTACK_AREA) centred on the tile (x, y) for
 * `player`, with a value of 99 and a last value of 50. */
void AddAreaAttackOrder(s32 x, s32 y, s32 player) {
    AddMapOrderEx(x - 1, y - 1, 3, 3, 4, player, 0, 0x63, 1, 1, 0, 0x32);
}

/* Queue a point/column attack (MAPORDER_ATTACK_POINT) on the tile (x, y) for
 * `player`, playing `mode` with `kind`. */
void AddPointAttackOrder(M2C_UNK x, M2C_UNK y, s32 player, s32 mode, s32 kind) {
    M2C_UNK AddMapOrderEx(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, u8, s32, s32, s32, s32, s32);
    AddMapOrderEx(x, y, 1, 1, MAPORDER_ATTACK_POINT, player, 0, 0, mode, kind, 0, 0x32);
}

/* Queue the player-facing variant of a point/column attack
 * (MAPORDER_ATTACK_POINT) on the tile (x, y) for `player`, playing `mode` with
 * `kind`. */
void AddFacingPointAttackOrder(M2C_UNK x, M2C_UNK y, s32 player, s32 mode, s32 kind) {
    AddMapOrderEx(x, y, 1, 1, MAPORDER_ATTACK_POINT, player, 0, 0, mode, kind, 1, 0x32);
}

/* Queue a line attack (MAPORDER_ATTACK_LINE) on the tile (x, y) for `player`,
 * playing `mode` with `kind`, a value of 99 and a last value of 80. */
void AddLineAttackOrder(s32 x, s32 y, s32 player, s32 mode, s32 kind) {
    AddMapOrderEx(x, y, 1, 1, MAPORDER_ATTACK_LINE, player, 1, 0x63, mode, kind, 3, 0x50);
}

/* Queue a player-facing line attack (MAPORDER_ATTACK_LINE_FACING) on the tile
 * (x, y) for `player`, playing `mode` with `kind`, a value of 99 and a last
 * value of 80. */
void AddFacingLineAttackOrder(s32 x, s32 y, s32 player, s32 mode, s32 kind) {
    AddMapOrderEx(x, y, 1, 1, MAPORDER_ATTACK_LINE_FACING, player, 1, 0x63, mode, kind, 1, 0x50);
}

/* Whether an order in the map's order queue is still doing something: attack
 * orders are active only while their value is nonzero, a free slot (type 0) never
 * is, and every other order type is active. */
u8 IsMapOrderActive(Unk020AEntry *order) {
if(!order)return 0;
switch(order->type){
case MAPORDER_ATTACK_AREA:
case MAPORDER_ATTACK_LINE:
case MAPORDER_ATTACK_LINE_FACING:return order->value!=0;
case MAPORDER_NONE:return 0;
default:return 1;
}
}

/* Report whether the map's order queue holds an active order of type `type`
 * (one of the MAPORDER_* values; 0 ends the queue). */
s32 HasActiveMapOrderOfType(s32 type) {
    extern s32 *gCurrentMap;
    Unk020AEntry *order = (Unk020AEntry *)(*gCurrentMap + MAP_ORDERS);
    s32 found = 0;

    while (order->type) {
        if (order->type == type) {
            if (IsMapOrderActive(order)) found++;
        }
        order++;
    }
    return found != 0;
}

void func_020a4d58(void) {
    M2C_UNK ClearMapOrders();
    ClearMapOrders();
}

void ClearSelectionQueue(void) {
    extern s32 gSelectionQueueCount;
    gSelectionQueueCount = 0;
}

/* Append the cell (x, y) of selected unit `unitId` to the selection queue,
 * tagged with the order type the entry plays for. */
void AppendSelectionEntry(s32 x, s32 y, s32 unitId, s32 orderType) {
    extern Unk020APosition *gSelectionQueue;
    extern s32 gSelectionQueueCount;
    Unk020APosition *p = gSelectionQueue;

    p[gSelectionQueueCount].x = x;
    p[gSelectionQueueCount].y = y;
    p[gSelectionQueueCount].unitId = unitId;
    p[gSelectionQueueCount].orderType = orderType;
    gSelectionQueueCount++;
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
s32 IsSameTeam(s32,s32);s32 IsUnitVisibleAtCell(s32,s32,s32);s32 IsUnitInSight(s32);
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
if(!IsUnitInSight(unitId))continue;
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
#pragma opt_strength_reduction off
void SelectLineOrderTargets(Unk020ABaseEntry *a) {
    extern s32 *gCurrentMap;
    void SelectMapLayer(s32);
    void FillMapLayer(s32);
    void FillMapLine(s32,s32,s32,s32);
    s32 found = 0, x, y, p;
    s32 start = found;
    u8 id;
    SelectMapLayer(*gCurrentMap + 0x1e30);
    FillMapLayer(-1);
    FillMapLine(a->x,a->y,(u32)(M2C_FIELD(a,u16 *,2)<<16)>>30,found);
    p = *gCurrentMap;
    for (y = found; y < M2C_FIELD(p,u16 *,0x5146); y++) {
        x = start;
        if (x < M2C_FIELD(p,u16 *,0x5144)) do {
            if (M2C_FIELD(M2C_FIELD(p + (y << 2) + 0x5000, s8 **, 0x2e8), s8 *, x) >= 0) {
                id = M2C_FIELD(M2C_FIELD(p + (y << 1) + 0x3700,u16 *,0x58) + (p + x), u8 *, 0x508);
                if (id) {
                    AppendSelectionEntry((u16)x,(u16)y,id,M2C_FIELD(a,s8 *,7));
                    found = 1;
                }
            }
            p = *gCurrentMap;
        } while (++x < M2C_FIELD(p,u16 *,0x5144));
    }
    if (!found) ClearSelectionQueue();
}
#pragma opt_strength_reduction reset
void SelectPointOrderTargets(Unk020ABaseEntry *p) {
extern s32 *gCurrentMap; void SelectMapLayer(s32);void FillMapLayer(s32);void FillMapColumn(s32,s32,s32,s8,u8);s32 SelectAreaEffectTargetOnGrid(void *,s32,s32,s32,s32,s32);void ClearSelectionQueue(void);
s16 pos[2];s32 map; s32 centerY;register s32 right;register s32 yy;register s32 xx;register s32 zero;register u32 cy;register s32 bottom;s32 left,top,dist;
SelectMapLayer(*gCurrentMap+0x1e30);FillMapLayer(-1);
FillMapColumn(p->x,p->y,(u32)(M2C_FIELD(p,u16 *,2)<<16)>>30,0,0);
if(!SelectAreaEffectTargetOnGrid(pos,p->player,0,6,2,M2C_FIELD(p,s8 *,7))){ClearSelectionQueue();return;}
AppendSelectionEntry((u16)pos[0],(u16)pos[1],0,0);
left=pos[0]-2;if(left<0)left=0;
centerY=pos[1];top=centerY-2;if(top<0)top=0;
right=M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1;if(pos[0]+2<right)right=pos[0]+2;
bottom=M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1;if(centerY+2<bottom)bottom=centerY+2;
for(yy=top;yy<=bottom;yy++){xx=left;if(xx<=right){cy=(u16)yy;zero=0;do{
dist=0;if(pos[0]-xx>0)dist+=pos[0]-xx;else dist+=xx-pos[0];
if(pos[1]-yy>0)dist+=pos[1]-yy;else dist+=yy-pos[1];
if(dist>=0 && dist<=2){u8 c;s32 mm=*gCurrentMap;c=M2C_FIELD(((u16 *)mm)[yy+0x1bac]+(mm+xx),u8 *,0x508);if(c)AppendSelectionEntry((u16)xx,cy,c,M2C_FIELD(p,s8 *,7));}
xx++;}while(xx<=right);}}
}
#pragma opt_lifetimes reset
/* Paints the area an order targets on the map score layer, by order type: a
   radius-5 diamond centred on the order, a line of length top, or a point. */
s32 DrawOrderTargetArea(Unk020AEntry *order,s8 color,u8 extra) {
void func_01ffb734(s32,s32,s32,s8);void FillMapLine(s32,s32,s32,s32);void FillMapColumn(s32,s32,s32,s8,u8);s32 GetOrderCenterOffsetX(void);s32 GetOrderCenterOffsetY(void);extern s32 *gCurrentMap;
Unk020ABaseEntry *base=(Unk020ABaseEntry *)order;
if(!IsMapOrderActive(order))return 0;
switch(order->type) {
case 4: {
s32 centerX=GetOrderCenterOffsetX();s32 centerY=GetOrderCenterOffsetY();
func_01ffb734(base->x+centerX,base->y+centerY,5,color);return 1;
}
case 6:FillMapLine(base->x,base->y,order->top,color);return 1;
case 7: {
s32 dir=order->top;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)>=(s32)base->player) dir=(dir+1)%3;
FillMapLine(base->x,base->y,dir,color);return 1;
}
case 5:FillMapColumn(base->x,base->y,order->top,color,extra);return 1;
default:return 0;
}
}

void ResetOrderEffectCursor(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54) = 0;
}

/* Delete callback of the order-effect sprite: it removes itself only once every
 * queued selection entry has been played, that is when its queue cursor has
 * caught up with the selection queue's count. */
void DeleteFinishedOrderEffectSprite(void *sprite) {
    void DeleteSpriteObject();
    extern s32 gSelectionQueueCount;
    if (M2C_FIELD(sprite, s16 *, ORDER_SPRITE_QUEUE_CURSOR) != gSelectionQueueCount) return;
    DeleteSpriteObject(sprite);
}

/* Step of an order-effect sprite: at each queued order's own cell, play that
 * order's attack visual (area burst, beam or point strike) on the order's tile,
 * then advance to the next queue entry and restart the sprite animation. */
void PlayOrderEffectStep(void *sprite) {
    M2C_UNK GotoSpriteAnimationLabel(void *, s32);
    void *FindMapOrderAtTile(s16, s16);
    M2C_UNK CreateAuroraStrikeEffect(s16, s16, s32, void *);
    M2C_UNK CreateGasStormEffect(s16, s16, s16, s16, s32, void *);
    M2C_UNK SpawnBeamEffect(s16, s16, u32, s32, void *);
    extern Unk020APosition *gSelectionQueue;
    Unk020APosition *queue = gSelectionQueue, *order, *target;
    s32 firstTarget = 0;
    s16 slot, nextSlot;
    void *orderTile;
    while (queue[firstTarget].a == 0) firstTarget++;
    slot = M2C_FIELD(sprite, s16 *, ORDER_SPRITE_QUEUE_CURSOR);
    if (queue[slot].a) return;
    order = &queue[slot];
    switch (order->b) {
    default: break;
    case 4: CreateAuroraStrikeEffect((s16)order->c, (s16)order->d, slot + 1, sprite); break;
    case 6: case 7:
        orderTile = FindMapOrderAtTile((s16)order->c, (s16)order->d);
        nextSlot = M2C_FIELD(sprite, s16 *, ORDER_SPRITE_QUEUE_CURSOR);
        target = &queue[nextSlot];
        SpawnBeamEffect((s16)target->c, (s16)target->d, (u32)(M2C_FIELD(orderTile, u16 *, 2) << 16) >> 30, nextSlot + 1, sprite); break;
    case 5:
        target = &queue[slot + 1];
        CreateGasStormEffect((s16)order->c, (s16)order->d, (s16)target->c, (s16)target->d, slot + 2, sprite);
        M2C_FIELD(sprite, s16 *, ORDER_SPRITE_QUEUE_CURSOR)++; break;
    }
    M2C_FIELD(sprite, s16 *, ORDER_SPRITE_QUEUE_CURSOR)++;
    GotoSpriteAnimationLabel(sprite, 0);
}

/* Initialise an order-effect sprite to play the map's order queue: point its
 * order cursor at the queue's first record and clear its two playback fields. */
void InitOrderEffectSprite(void *sprite) {
    extern s32 *gCurrentMap;
    M2C_FIELD(sprite, s32 *, 0x34) = (s32) (*gCurrentMap + MAP_ORDERS);
    M2C_FIELD(sprite, s32 *, 0x38) = 0;
    M2C_FIELD(sprite, s8 *, 0x44) = 0;
}

/* Ticks the order countdowns of the current player: every active order of type
 * 4..7 has one frame taken off its timer, so the order's targets play when the
 * timer reaches 0. */
void TickMapOrderTimers(void) {
    extern s32 *gCurrentMap;
    Unk020AEntry *order = (Unk020AEntry *)(*gCurrentMap + MAP_ORDERS);
    while (order->type) {
        if (IsMapOrderActive(order) && ((Unk020APlayer *)order)->player == M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)) {
            switch (order->type) {
            case 4: case 5: case 6: case 7: M2C_FIELD(order, s8 *, MAP_ORDER_TIMER) -= 1; break;
            }
        }
        order++;
    }
}

/* Plays back the queued orders: takes the next order of the current player that
   has not started yet, appends the order's own cell to the selection queue, fills
   the queue with that order type's targets and marks the order started; when no
   order is left it starts the sprite animation. */
void SelectNextOrderTargets(void *anim) {
extern s32 *gCurrentMap;
void ClearSelectionQueue(void);s32 GotoSpriteAnimationLabel(void *,s32);
ClearSelectionQueue();
while(M2C_FIELD(anim,Unk020AEntry **,0x34)->type) {
if(IsMapOrderActive(M2C_FIELD(anim,Unk020AEntry **,0x34))) {
s32 orderType; Unk020AEntry *entry=M2C_FIELD(anim,Unk020AEntry **,0x34);
if((s32)((Unk020ABaseEntry *)entry)->player==M2C_FIELD(*gCurrentMap,u16 *,0x52a4) && M2C_FIELD(entry,s8 *,6)==0) {
orderType=entry->type; switch(orderType) {
case 4:
AppendSelectionEntry(((Unk020ABaseEntry *)entry)->x,((Unk020ABaseEntry *)entry)->y,0,orderType);
SelectAreaOrderTargets(M2C_FIELD(anim,Unk020AEntry **,0x34));
M2C_FIELD(M2C_FIELD(anim,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(anim,Unk020AEntry **,0x34)->kind;
M2C_FIELD(anim,Unk020AEntry **,0x34)++;
return;
case 6:case 7:
AppendSelectionEntry(((Unk020ABaseEntry *)entry)->x,((Unk020ABaseEntry *)entry)->y,0,orderType);
SelectLineOrderTargets(M2C_FIELD(anim,Unk020ABaseEntry **,0x34));
M2C_FIELD(M2C_FIELD(anim,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(anim,Unk020AEntry **,0x34)->kind;
M2C_FIELD(anim,Unk020AEntry **,0x34)++;
return;
case 5:
AppendSelectionEntry(((Unk020ABaseEntry *)entry)->x,((Unk020ABaseEntry *)entry)->y,0,orderType);
SelectPointOrderTargets(M2C_FIELD(anim,Unk020ABaseEntry **,0x34));
M2C_FIELD(M2C_FIELD(anim,Unk020AEntry **,0x34),u8 *,6)=M2C_FIELD(anim,Unk020AEntry **,0x34)->kind;
M2C_FIELD(anim,Unk020AEntry **,0x34)++;
return;
}
}}
M2C_FIELD(anim,Unk020AEntry **,0x34)++;
}
GotoSpriteAnimationLabel(anim,1);
}

