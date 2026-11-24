/* 1 function from 0x0218B0D8 to 0x0218BBD0 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[42]; u8 mode; u8 rest[97]; } AiPlayerB0;
typedef struct { u16 pad; u16 low:6; u16 kind:4; u16 high:6; } AiPropertyB0;
typedef struct { u8 pad[7]; u8 low:2; u8 enabled:1; u8 high:5; } AiFlagsB0;
#include "ov000_unit_entry.h"
extern u8 **gCurrentMap;
extern u8 gUnitKindFlags[];
extern u8 gUnitKindStats[];
extern u8 gAiRangeBitmap[], gAiIndirectRangeBitmap[];
extern u8 *gAiCommandState, *gAiUnitTypeTuning;


u8 *FindDestructibleFeatureAtTile(int, int);
#pragma push
#pragma opt_strength_reduction off
int SelectDirectAttackAction(void *arg0) {
 int sy;
 int bestX, bestY, best, blocked, bestId, repairX, repairY, repairHP, flags, y, x;
 s16 rx;
 int ry;
 s16 pos[2];
 u8 *map, *unit;
 bestX = -1;
 bestY = bestX;
 blocked = 0;
 bestId = 0;
 best = 0;
 repairX = bestX;
 repairY = bestX;
 flags = 0;
 repairHP = 255;
 if(CursorUnitReachesEnemyKind22()==1) flags|=0x100000;
 map=*gCurrentMap;
 unit=M2C_FIELD(map,u8 **,0x52d0);
 if(IsUnitSelected(unit)) flags|=0x400000;
 unit=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
 if(((UnkStruct_ov000_021A860C *)unit)->unk0==21) flags|=0x800000;
 BuildUnitMoveRange(unit);
 {
 u8 **state = gCurrentMap;
 register u8 *rangeMap = *state;
 register AiPlayerB0 *player=(AiPlayerB0 *)(rangeMap+0x67a4);
 u16 currentPlayer = M2C_FIELD(rangeMap,u16 *,0x52a4);
 player += currentPlayer;
 if(player->mode!=2 && player->mode!=3) goto rangeDone;
 if(gUnitKindFlags[M2C_FIELD(rangeMap,UnkStruct_ov000_021A860C **,0x52d0)->unk0*112]&23) {
 int hits=0,total=hits;
 int rangeY=hits;
 int height=M2C_FIELD(rangeMap,u16 *,0x5146);
 if(height>0) do {
 int rangeX,width;
 s8 *cost;
 rangeMap=*state;
 width=M2C_FIELD(rangeMap,u16 *,0x5144);
 rangeX=0;
 if(width>0) {
 cost=((s8 **)(rangeMap+0x52e8))[rangeY];
 do {
 if(*cost>=0) {
 int attr=gUnitKindStats[M2C_FIELD(rangeMap,UnkStruct_ov000_021A860C **,0x52d0)->unk0*112+19];
 if(attr&7) {
 u32 n=rangeX+rangeY*width;
 if((u8)((1<<(n&7))&gAiRangeBitmap[n>>3])) hits++;
 }
 if(attr&16) {
 u32 n=rangeX+rangeY*width;
 if((u8)((1<<(n&7))&gAiIndirectRangeBitmap[n>>3])) hits++;
 }
 total++;
 }
 cost++;
 } while(++rangeX<width);
 }
 } while(++rangeY<*(volatile u16 *)(rangeMap+0x5146));
 if(hits >= (total>>2)) flags|=0x200000;
 }
 }
 rangeDone:
 MarkAdjacentCells(111);

 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++) {
 x=0;
 if(x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)) {
 int zero=0;
 sy=(s16)y;
 do {
 int hp,kind,damage,n,extra,score;
 u8 *p;
 map=*gCurrentMap;
 if(((s8 **)(map+0x52e8))[y][x]<0) continue;
 p=FindDestructibleFeatureAtTile(x,y);
 if(p && MapOrder_IsEnemyOwned(p)) { hp=p[4]; kind=((AiPropertyB0 *)p)->kind; goto repair; }
 if(((AiFlagsB0 *)gAiCommandState)->enabled) {
 kind=1;
 map=*gCurrentMap;
 n=((u16 *)(map+0x3758))[y];
 if(((hp=(map+x)[n+0x539c]&127)!=0) && (map+x)[n]==0) {
 repair:
 damage=Divide(GetUnitMaxWeaponDamagePercent(M2C_FIELD(*gCurrentMap,u8 **,0x52d0),kind)*(M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0)->unk6),100);
 if(damage<hp && damage<10) continue;
 if(!func_ov000_02177f24(x,y,pos)) continue;
 func_020d1690(((u8 *)*gCurrentMap)[0x52d4],kind,pos);
 map=*gCurrentMap;
 if(!M2C_FIELD(map,s16 *,0x6ed6)) continue;
 if(damage>=repairHP) { if(damage<hp || repairHP>hp) continue; } else if(repairHP<hp) continue;
 if(((AiPlayerB0 *)(map+0x67a4))[M2C_FIELD(map,u16 *,0x52a4)].mode==3 && damage<hp && !IsFootUnitKind(M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0)) {
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]];
 { u8 *tile=(map+pos[0])+n;
 if(tile[0x2840]>=gAiUnitTypeTuning[1] || tile[0x2d48]>=gAiUnitTypeTuning[2]) continue; }
 }
 map=*gCurrentMap;
 if(((AiPlayerB0 *)(map+0x67a4))[M2C_FIELD(map,u16 *,0x52a4)].mode==2 && func_ov000_021a9c90(bestX,bestY)>=2 && !IsFootUnitKind(M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0)->unk0)) {
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]];
 { u8 *tile=(map+pos[0])+n;
 if(tile[0x2d48]>=gAiUnitTypeTuning[2]) continue; }
 }
 if(!func_ov000_02178e84(pos[0],pos[1])) continue;
 repairHP=hp; repairX=pos[0]; repairY=pos[1]; rx=x; ry=sy;
 continue;
 }
 }
 map=*gCurrentMap;
 n=((u16 *)(map+0x3758))[y];
 p=(u8 *)((UnkStruct_ov000_021A860C *)(map+0x59a4)+(map+x)[n]);
 if(!((UnkStruct_ov000_021A860C *)p)->unk0) continue;
 if(func_020d27a4(map[0x52d4],p ? (p-(map+0x59a4))/14:0)==1) continue;
 if(!IsCellVisibleToCurrentTeam((s16)x,sy)) continue;
 if(!func_ov000_02177f24(x,y,pos)) continue;
 extra=zero;
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]];
 { u8 *tile=(map+pos[0])+n;
 if((tile[0x2d48]>=gAiUnitTypeTuning[2] || tile[0x2840]>=gAiUnitTypeTuning[1]) &&
    !p[12] && GetKindAttackClass(((UnkStruct_ov000_021A860C *)p)->unk0)==2 &&
    !CanAttackUnitFrom(pos[0],pos[1],p)) extra=0x80000;
 }
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]];
 { u8 *tile=(map+pos[0])+n;
 if(tile[0x2840]>=gAiUnitTypeTuning[1] && M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0==16 && (gUnitKindStats[((UnkStruct_ov000_021A860C *)p)->unk0*112+19]&7)) extra=0x80000; }
 n=((u16 *)(map+0x3758))[y];
 extra |= (map+x)[n];
 score=func_ov000_02176e28(flags | extra,pos);
 if(!score || score<best) continue;
 if(HasBetterAttackerNearby(p)==1) {
 int px=p[1];
 int count=0,selected=count;
 int xx,yy,minX=px-1,minY,maxX,maxY,py;
 if(minX<0) minX=count;
 py=p[2];
 minY=py-1;
 if(minY<0) minY=0;
 map=*gCurrentMap;
 maxX=M2C_FIELD(map,u16 *,0x5144)-1;
 if(px+1<maxX) maxX=px+1;
 maxY=M2C_FIELD(map,u16 *,0x5146)-1;
 if(py+1<maxY) maxY=py+1;
 yy=minY;
 if(yy<=maxY) do {
 xx=minX;
 if(xx<=maxX) do {
 int distance=0,dx=px-xx,dy=py-yy;
 u8 *q;
 if(dx<=0) dx=xx-px;
 distance+=dx;
 if(dy>0) distance+=dy; else distance+=yy-py;
 if(distance<1 || distance>1) continue;
 map=*gCurrentMap;
 if(((s8 **)(map+0x52e8))[yy][xx]<0) continue;
 n=((u16 *)(map+0x3758))[yy];
 q=map+0x59a4+(s16)(map+xx)[n]*(s16)sizeof(UnkStruct_ov000_021A860C);
 if(((UnkStruct_ov000_021A860C *)q)->unk0 && (M2C_FIELD(q,u16 *,4)&1)) continue;
 unit=M2C_FIELD(map,u8 **,0x52d0); count++;
 if(xx==unit[1] && yy==unit[2]) selected=1;
 } while(++xx<=maxX);
 } while(++yy<=maxY);
 if(count<=1) { if(selected) blocked=1; continue; }
 }
 best=score; bestX=pos[0];bestY=pos[1];
 map=*gCurrentMap; bestId=map[((u16 *)(map+0x3758))[y]+x];
 } while(++x<M2C_FIELD(*gCurrentMap,u16 *,0x5144));
 }
 }
 if(best) {
 if(arg0) return 1;
 ClearUnitMoveTarget();
 func_ov000_021843ec(bestX,bestY,((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[bestId].unk0);
 SetMapCursor((s16)bestX,(s16)bestY,4,(u8)bestId,0);
 }
 if(repairHP!=255) {
 if(arg0) return 1;
 ClearUnitMoveTarget();
 SetMapCursor((s16)repairX,(s16)repairY,5,(u8)rx,(u8)ry);
 }
 if(arg0) return 0;
 if(blocked) ChooseAiUnitMoveDestination(0);
 return 0;
}
#pragma pop
