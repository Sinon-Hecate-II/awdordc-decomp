/* 1 function from 0x0218B0D8 to 0x0218BBD0 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[42]; u8 mode; u8 rest[97]; } AiPlayerB0;
typedef struct { u16 pad; u16 low:6; u16 kind:4; u16 high:6; } AiPropertyB0;
typedef struct { u8 pad[7]; u8 low:2; u8 enabled:1; u8 high:5; } AiFlagsB0;
#include "ov000_unit_entry.h"
extern u8 **gCurrentMap;
extern u8 data_ov000_021b5c0f[];
extern u8 data_ov000_021b5bfc[];
extern u8 data_ov000_021dfcf0[], data_ov000_021dfba8[];
extern u8 *data_ov000_021df580, *data_ov000_021df644;


u8 *func_020a47e0(int, int);
#pragma push
#pragma opt_strength_reduction off
int func_ov000_0218b0d8(void *arg0) {
 int bestX=-1,bestY=bestX,blocked=0,bestId=0,best=0,repairX=bestX,repairY=bestX,repairHP=255,flags=0,rx,ry;
 int y,x;
 s16 pos[2];
 u8 *map, *unit;
 if(func_ov000_0217dcd0()==1) flags|=0x100000;
 map=*gCurrentMap;
 unit=M2C_FIELD(map,u8 **,0x52d0);
 if(IsUnitSelected(unit)) flags|=0x400000;
 unit=M2C_FIELD(*gCurrentMap,u8 **,0x52d0);
 if(((UnkStruct_ov000_021A860C *)unit)->unk0==21) flags|=0x800000;
 func_01ffc328(unit);
 map=*gCurrentMap;
 {
 AiPlayerB0 *player=(AiPlayerB0 *)(map+0x67a4)+M2C_FIELD(map,u16 *,0x52a4);
 if((player->mode==2||player->mode==3)&&(data_ov000_021b5c0f[M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0*112]&23)) {
 int hits=0,total=0;
 s8 *cost;
 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++) {
 map=*gCurrentMap;
 cost=((s8 **)(map+0x52e8))[(unsigned)y];
 for(x=0;x<M2C_FIELD(map,u16 *,0x5144);x++,cost++){
 if(*cost>=0) {
 u32 n=x+y*M2C_FIELD(map,u16 *,0x5144);
 int attr=data_ov000_021b5bfc[M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0*112+19];
 if((attr&7)&&(u8)(data_ov000_021dfcf0[n>>3]&(1<<(n&7)))) hits++;
 if((attr&16)&&(u8)(data_ov000_021dfba8[n>>3]&(1<<(n&7)))) hits++;
 total++;
 }
 }
 }
 if(hits >= (total>>2)) flags|=0x200000;
 }
 }
 func_01ffb9c4(111);

 for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++) {
 for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++) {
 int hp,kind,damage,n,extra,score;
 s16 sy=(s16)y;
 u8 *p;
 extra=0;
 map=*gCurrentMap;
 if(((s8 **)(map+0x52e8))[y][x]<0) continue;
 p=func_020a47e0(x,y);
 if(p && func_ov000_021a9bc0(p)) { hp=p[4]; kind=((AiPropertyB0 *)p)->kind; goto repair; }
 if(((AiFlagsB0 *)data_ov000_021df580)->enabled) {
 kind=1;
 map=*gCurrentMap;
 n=((u16 *)(map+0x3758))[y]+x;
 if(((hp=map[n+0x539c]&127)!=0) && map[n]==0) {
 repair:
 damage=func_0207c8ec(func_ov000_021a9740(M2C_FIELD(*gCurrentMap,u8 **,0x52d0),kind)*(M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0)->unk6),100);
 if(damage<hp && damage<10) continue;
 if(!func_ov000_02177f24(x,y,pos)) continue;
 func_020d1690(((u8 *)*gCurrentMap)[0x52d4],kind,pos);
 map=*gCurrentMap;
 if(!M2C_FIELD(map,s16 *,0x6ed6)) continue;
 if(damage>=repairHP) { if(damage<hp || repairHP>hp) continue; } else if(repairHP<hp) continue;
 if(((AiPlayerB0 *)(map+0x67a4))[M2C_FIELD(map,u16 *,0x52a4)].mode==3 && damage<hp && !func_ov000_021a98a8(M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0)) {
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]]+pos[0];
 if(map[n+0x2840]>=data_ov000_021df644[1] || map[n+0x2d48]>=data_ov000_021df644[2]) continue;
 }
 map=*gCurrentMap;
 if(((AiPlayerB0 *)(map+0x67a4))[M2C_FIELD(map,u16 *,0x52a4)].mode==2 && func_ov000_021a9c90(bestX,bestY)>=2 && !func_ov000_021a98a8(M2C_FIELD(*gCurrentMap,UnkStruct_ov000_021A860C **,0x52d0)->unk0)) {
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]]+pos[0];
 if(map[n+0x2d48]>=data_ov000_021df644[2]) continue;
 }
 if(!func_ov000_02178e84(pos[0],pos[1])) continue;
 repairHP=hp; repairX=pos[0]; repairY=pos[1]; rx=(s16)x; ry=sy;
 continue;
 }
 }
 map=*gCurrentMap;
 n=((u16 *)(map+0x3758))[y]+x;
 p=(u8 *)((UnkStruct_ov000_021A860C *)(map+0x59a4)+map[n]);
 if(!((UnkStruct_ov000_021A860C *)p)->unk0) continue;
 if(func_020d27a4(map[0x52d4],p ? (p-(map+0x59a4))/14:0)==1) continue;
 if(!func_ov000_021a93ec((s16)x,sy)) continue;
 if(!func_ov000_02177f24(x,y,pos)) continue;
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]]+pos[0];
 if((map[n+0x2d48]>=data_ov000_021df644[2] || map[n+0x2840]>=data_ov000_021df644[1]) && !p[12] && func_ov000_021a9904(((UnkStruct_ov000_021A860C *)p)->unk0)==2) continue;
 if(!func_ov000_0217d150(pos[0],pos[1],p)) extra=0x80000;
 map=*gCurrentMap; n=((u16 *)(map+0x3758))[pos[1]]+pos[0];
 if(map[n+0x2840]>=data_ov000_021df644[1] && M2C_FIELD(map,UnkStruct_ov000_021A860C **,0x52d0)->unk0==16 && (data_ov000_021b5bfc[((UnkStruct_ov000_021A860C *)p)->unk0*112+19]&7)) extra=0x80000;
 n=((u16 *)(map+0x3758))[y]+x;
 score=func_ov000_02176e28(flags | extra | map[n],pos);
 if(!score || score<best) continue;
 if(func_ov000_0217a0a8(p)==1) {
 int xx,yy,minX=p[1]-1,minY=p[2]-1,maxX,maxY,count=0,selected=0;
 int px=p[1],py=p[2];
 if(minX<0) minX=0; if(minY<0) minY=0;
 map=*gCurrentMap;
 maxX=M2C_FIELD(map,u16 *,0x5144)-1;
 maxY=M2C_FIELD(map,u16 *,0x5146)-1;
 if(px+1<maxX) maxX=px+1; if(py+1<maxY) maxY=py+1;
 for(yy=minY;yy<=maxY;yy++) for(xx=minX;xx<=maxX;xx++) {
 int distance=0,dx=px-xx,dy=py-yy;
 u8 *q;
 if(dx<=0) dx=xx-px; if(dy<=0) dy=yy-py;
 distance=dx+dy;
 if(distance<1 || distance>1) continue;
 map=*gCurrentMap;
 if(((s8 **)(map+0x52e8))[yy][xx]<0) continue;
 n=((u16 *)(map+0x3758))[yy]+xx;
 q=(u8 *)((UnkStruct_ov000_021A860C *)(map+0x59a4)+map[n]);
 if(((UnkStruct_ov000_021A860C *)q)->unk0 && (M2C_FIELD(q,u16 *,4)&1)) continue;
 unit=M2C_FIELD(map,u8 **,0x52d0); count++;
 if(xx==unit[1] && yy==unit[2]) selected=1;
 }
 if(count<=1) { if(selected) blocked=1; continue; }
 }
 best=score; bestX=pos[0];bestY=pos[1];
 map=*gCurrentMap; bestId=map[((u16 *)(map+0x3758))[y]+x];
 }
 }
 if(best) {
 if(arg0) return 1;
 func_ov000_0217c3a4();
 func_ov000_021843ec(bestX,bestY,((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[bestId].unk0);
 SetMapCursor((s16)bestX,(s16)bestY,4,(u8)bestId,0);
 }
 if(repairHP!=255) {
 if(arg0) return 1;
 func_ov000_0217c3a4();
 SetMapCursor((s16)repairX,(s16)repairY,5,(u8)rx,(u8)ry);
 }
 if(arg0) return 0;
 if(blocked) func_ov000_0218d040(0);
 return 0;
}
#pragma pop
