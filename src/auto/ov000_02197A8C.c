/* 1 function from 0x02197A8C to 0x02198848 (ov000), found by ds-decomp. */
#include "common.h"
extern u8 **gCurrentMap;
extern u8 gUnitKindFlags[], gUnitKindStats[], data_ov000_021e0550[], data_ov000_021e0a58[], data_ov000_021dfb04[], data_ov000_021dfa60[];
s32 GetUnitAttackClass(s32);
s32 GetUnitDamagePercent(s32,s32);
s32 GetUnitMoveRange(s32,s32);
s32 GetUnitMaxAttackRange(s32,s32);
s32 IsUnitVisibleAtCell(s32,s32,s16,s16);
s32 func_020a85c8(s32);
void FloodFillUnitRange(s32,s32,s32,s32,s32);
void MarkAdjacentCells(s8);
static inline s8 MapCost(s32 x,s32 y) { return M2C_FIELD(*gCurrentMap+y*4,s8**,0x52e8)[x]; }
static inline u8 *MapCell(s32 x,s32 y) { return *gCurrentMap + x + M2C_FIELD(*gCurrentMap+y*2,u16*,0x3758); }
static inline u8 *CurrentMap(void) { return *gCurrentMap; }
static inline u16 MapWidth(void) { return M2C_FIELD(*gCurrentMap,u16*,0x5144); }
static inline u8 *InfluenceCell(u8 *base,s32 x,s32 y) { return base + x + y*MapWidth(); }
static inline u16 MapHeight(void) { return M2C_FIELD(*gCurrentMap,u16*,0x5146); }
static inline void UpdateInfluence(s32 x,s32 y,s32 value) {
u8 old=M2C_FIELD(MapCell(x,y),u8*,0x2840);
if(value>old){*InfluenceCell(data_ov000_021e0a58,x,y)=old;M2C_FIELD(MapCell(x,y),u8*,0x2840)=value;}
else if(value>*InfluenceCell(data_ov000_021e0a58,x,y))*InfluenceCell(data_ov000_021e0a58,x,y)=value;
}
typedef struct { u8 low:6; u8 hidden:1; u8 high:1; } UnitHiddenBits;
static inline u32 UnitHidden(u8 *unit) { return ((UnitHiddenBits*)(unit+11))->hidden; }
typedef struct { u16 low:7; u16 ammo:4; u16 high:5; } UnitAmmoBits;
static inline u32 UnitAmmo(u8 *unit) { return ((UnitAmmoBits*)(unit+6))->ammo; }
typedef union { struct { u8 kind:6; u8 rest:2; }; u8 raw; } UnitKindBits;
static inline u32 UnitKind(u8 *unit) { return ((UnitKindBits*)unit)->kind; }
static inline s32 UnitSide(u8 *unit) {
s32 index;
if(unit) {
if(unit) index=(unit-(*gCurrentMap+0x59a4))/14; else index=0;
return (index>>6)+1;
} return 0;
}

#pragma scheduling off
void AddUnitThreatInfluence(u8 *unit, s32 b, s32 c, s32 d, u8 e, u8 f, u8 g) {
u8 flags=gUnitKindFlags[c*112];
u8 *map=*gCurrentMap;
s32 x,y,idx,kind,loX,hiX,loY,hiY,dist,value;
u8 *dimensions;
s32 filter;
if(M2C_FIELD(map+M2C_FIELD(map,u16*,0x52a4)*140,u8*,0x67ce)!=3 && GetUnitAttackClass(c)!=1 && !e && c!=21)filter=1;else filter=0;
if (!GetUnitAttackClass(((UnitKindBits*)unit)->kind)) {
s32 directX,directY;
if(f==1)return;
if(g==1 && d*GetUnitDamagePercent(c,((UnitKindBits*)unit)->kind)>=4500)return;
if ((((UnitKindBits*)unit)->kind)==25 && !(((UnitAmmoBits*)(unit+6))->ammo)) return;
FloodFillUnitRange(unit[1],unit[2],((UnitKindBits*)unit)->kind,GetUnitMoveRange(UnitSide(unit),((UnitKindBits*)unit)->kind),12);
MarkAdjacentCells(111);
for(directY=0;directY<MapHeight();directY++) for(directX=0;directX<MapWidth();directX++){
map=*gCurrentMap;
if(M2C_FIELD(map+directY*4,s8**,0x52e8)[directX]<0)continue;
kind=(*InfluenceCell(data_ov000_021e0550,directX,directY))&127;
if(kind<=1 && (!(flags&16)||!((*InfluenceCell(data_ov000_021e0550,directX,directY))&128)))continue;
if(kind!=127&&!IsUnitVisibleAtCell(M2C_FIELD(map,u16*,0x52b6),c,(s16)directX,(s16)directY))continue;
if(filter){
if((gUnitKindStats[c*112+19]&7)&&(gUnitKindStats[(((UnitKindBits*)unit)->kind)*112+19]&7)&&(u8)((1<<((directY*MapWidth()+directX)&7))&data_ov000_021dfb04[(u32)(directY*MapWidth()+directX)>>3]))continue;
if((gUnitKindStats[(((UnitKindBits*)unit)->kind)*112+19]&16)&&(u8)((1<<((directY*MapWidth()+directX)&7))&data_ov000_021dfa60[(u32)(directY*MapWidth()+directX)>>3]))continue;
}
map=*gCurrentMap;

if(b>M2C_FIELD(MapCell(directX,directY),u8*,0x2840)){
(*InfluenceCell(data_ov000_021e0a58,directX,directY))=M2C_FIELD(MapCell(directX,directY),u8*,0x2840);
map=*gCurrentMap;
M2C_FIELD(MapCell(directX,directY),u8*,0x2840)=b;
}else if(b>(*InfluenceCell(data_ov000_021e0a58,directX,directY)))(*InfluenceCell(data_ov000_021e0a58,directX,directY))=b;
}
} else {
if(!((UnitHiddenBits*)(unit+11))->hidden){
map=*gCurrentMap;
idx=M2C_FIELD(map+unit[2]*2,u16*,0x3758)+unit[1];
if(!(u8)(M2C_FIELD(map+((u32)idx>>3),u8*,0x5160)&(1<<(idx&7))) && (flags&7))return;
}
if(func_020a85c8(((UnitKindBits*)unit)->kind)){
s32 specialX,specialY;
FloodFillUnitRange(unit[1],unit[2],((UnitKindBits*)unit)->kind,GetUnitMoveRange(UnitSide(unit),((UnitKindBits*)unit)->kind),12);
for(specialX=0;specialX<GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind);specialX++)MarkAdjacentCells((s8)(specialX+111));
for(specialY=0;specialY<MapHeight();specialY++) for(specialX=0;specialX<MapWidth();specialX++){
map=*gCurrentMap;
if(M2C_FIELD(map+specialY*4,s8**,0x52e8)[specialX]<0)continue;
kind=(*InfluenceCell(data_ov000_021e0550,specialX,specialY))&127;
if(!kind && (!(flags&16)||!((*InfluenceCell(data_ov000_021e0550,specialX,specialY))&128)))continue;
if(kind!=127&&!IsUnitVisibleAtCell(M2C_FIELD(map,u16*,0x52b6),c,(s16)specialX,(s16)specialY))continue;
map=*gCurrentMap;
if(M2C_FIELD(map+specialY*4,s8**,0x52e8)[specialX]>=110){map=MapCell(specialX,specialY);value=map[0x2d48]+(b>>2);}else{map=MapCell(specialX,specialY);value=map[0x2d48]+(b>>1);}
if(value>255)value=255;
map[0x2d48]=value;
}return;
}
if(unit[1]-GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind)<0)loX=0;else loX=unit[1]-GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind);
if(unit[2]-GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind)<0)loY=0;else loY=unit[2]-GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind);
dimensions=*gCurrentMap+0x5120;
if(unit[1]+GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind)>=M2C_FIELD(dimensions,u16*,0x24)-1)hiX=MapWidth()-1;else hiX=unit[1]+GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind);
dimensions=*gCurrentMap+0x5120;
if(unit[2]+GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind)>=M2C_FIELD(dimensions,u16*,0x26)-1)hiY=MapHeight()-1;else hiY=unit[2]+GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind);
for(y=loY;y<=hiY;y++)for(x=loX;x<=hiX;x++){
dist=0;
if(unit[1]-x>0)dist+=unit[1]-x;else dist+=x-unit[1];
if(unit[2]-y>0)dist+=unit[2]-y;else dist+=y-unit[2];
if(dist<gUnitKindStats[(((UnitKindBits*)unit)->kind)*112+12]||dist>GetUnitMaxAttackRange(UnitSide(unit),((UnitKindBits*)unit)->kind))continue;
map=*gCurrentMap;
kind=(*InfluenceCell(data_ov000_021e0550,x,y))&127;
if(!kind && (!(flags&16)||!((*InfluenceCell(data_ov000_021e0550,x,y))&128)))continue;
if(kind!=127&&!IsUnitVisibleAtCell(M2C_FIELD(map,u16*,0x52b6),c,(s16)x,(s16)y))continue;
if(dist==1){{
if((gUnitKindStats[c*112+19]&7)&&(gUnitKindStats[(((UnitKindBits*)unit)->kind)*112+19]&7)&&(u8)((1<<((y*MapWidth()+x)&7))&data_ov000_021dfb04[(u32)(y*MapWidth()+x)>>3]))continue;
if((gUnitKindStats[(((UnitKindBits*)unit)->kind)*112+19]&16)&&(u8)((1<<((y*MapWidth()+x)&7))&data_ov000_021dfa60[(u32)(y*MapWidth()+x)>>3]))continue;
}
map=*gCurrentMap;

if(b>M2C_FIELD(MapCell(x,y),u8*,0x2840)){
(*InfluenceCell(data_ov000_021e0a58,x,y))=M2C_FIELD(MapCell(x,y),u8*,0x2840);
map=*gCurrentMap;
M2C_FIELD(MapCell(x,y),u8*,0x2840)=b;
}else if(b>(*InfluenceCell(data_ov000_021e0a58,x,y)))(*InfluenceCell(data_ov000_021e0a58,x,y))=b;
}else{
map=*gCurrentMap;
map=MapCell(x,y);value=map[0x2d48]+b;if(value>255)value=255;map[0x2d48]=value;
}
}
}
}
#pragma scheduling reset
