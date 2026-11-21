/* 4 functions from 0x020D6E0C to 0x020D7BC8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s32 Tile6e0c(s32 tile, s32 offset) {
extern void *gCur3DSpriteEngine;
return (((tile >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((offset >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023);
}
static inline void Draw6e0c(s32 x,s32 y,s32 tile,s32 offset,void *data) {
void AddSprite(u16,u16,u16,void *,s32);
AddSprite((u16)x,(u16)y,(u16)Tile6e0c(tile,offset),data,10);
}
static inline void DrawSecond7944(u16 x,u16 y) { extern void *gCur3DSpriteEngine;extern M2C_UNK gSpriteDesc16x16;void AddSprite(u16,u16,u16,void *,s32);AddSprite(x,y,(u16)(((1023&(0x150>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))|0x9000)+(1023&(0x60>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),&gSpriteDesc16x16,10); }
static inline s32 SpriteTile7944(s32 tile) { extern void *gCur3DSpriteEngine;return (tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023; }
/* X offsets from the info panel's x to the icons of the units it carries:
 * [panel side][carried icon slot].  The icons sit 16 pixels apart and grow
 * away from a left-hand panel; a right-hand panel fills them leftwards. */
typedef struct { s32 v[2][2]; } OffsetTable;
extern OffsetTable gCarriedUnitIconOffsets;
extern s32 *gCurrentMap;
void DrawUnitIcon(s32, s32, s32, s32);

#pragma push
#pragma opt_strength_reduction off
void DrawUnitInfoFrame(s32 x,s32 y,s32 unused,s32 mode) {
void AddSprite(u16,u16,u16,void *,s32);
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_02101f0c;
extern M2C_UNK data_02101f1c;
extern M2C_UNK gSpriteDesc16x16;
extern M2C_UNK gSpriteDesc8x16;
extern M2C_UNK gSpriteDesc16x32;
extern M2C_UNK gSpriteDesc8x8;
extern M2C_UNK gSpriteDesc8x32;
extern M2C_UNK gSpriteDesc16x8;
extern M2C_UNK gSpriteDesc64x32;
s32 y0,x0,x1,x2,y1;
if(mode==0) {
y0=((y+24)&255)+0x400;x0=x&511;
AddSprite((u16)x0,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f1c,10);
x1=(x+64)&511;AddSprite((u16)x1,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc16x16,10);
x2=(x+80)&511;AddSprite((u16)x2,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc8x16,10);
y1=((y+40)&255)+0x400;AddSprite((u16)x0,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f0c,10);
AddSprite((u16)x1,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc16x8,10);
AddSprite((u16)x2,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc8x8,10);
} else {
y0=(y&255)+0x400;x0=x&511;
AddSprite((u16)x0,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc64x32,10);
x1=(x+64)&511;AddSprite((u16)x1,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc16x32,10);
x2=(x+80)&511;AddSprite((u16)x2,(u16)y0,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc8x32,10);
y1=((y+32)&255)+0x400;AddSprite((u16)x0,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&data_02101f1c,10);
AddSprite((u16)x1,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc16x16,10);
AddSprite((u16)x2,(u16)y1,(u16)((((0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)|0x9000)+((0x60 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))&1023)),&gSpriteDesc8x16,10);
}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=(*p & ~0xc0)|0x40;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=8;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=8;
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~1;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~2;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~4;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~8;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p & ~16;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x100;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x200;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x400;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x800;}
{u16 *volatile p=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0x12); *p=*p | 0x1000;}
}
#pragma push
#pragma opt_common_subs off
void func_020d759c(s32 panelX, s32 panelY, s32 side) {
    extern u32 gFrameCounter;
    extern u16 data_02120700[16], data_02120720[16], data_02120740[16], data_02120760[16];
    extern M2C_UNK gSpriteDesc32x8, gSpriteDesc32x16;
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 GetTileTargetKind(s32, s32);
    void func_020d166c(s32, s32, void *);
    void func_020d1690(s32, s32, void *);
    void func_01ff9e78(const void *, s32, s32);
    void AddSprite(u16, u16, u16, void *, s32);
    void DrawDecimalNumber(s32, u8, s32);
#define PULSE_PHASE ((gFrameCounter >> 1) & 0x1f)
    u16 position[2];
    s32 map, targetX, targetY, unitId, terrainTarget;
    s32 x, y, shift, color, damage, targetHealth = 0, band;
    s32 spriteX;

    map = *gCurrentMap;
    {
        u16 cursorY = M2C_FIELD(map, u16 *, MAP_CURSOR_Y);
        u16 cursorX = M2C_FIELD(map, u16 *, MAP_CURSOR_X);
        position[0] = cursorX;
        position[1] = cursorY;
    }
    if (PULSE_PHASE < 16)
        shift = EaseInterpolate(4, 0, 4, PULSE_PHASE, 16);
    else
        shift = EaseInterpolate(1, 4, 0, PULSE_PHASE - 16, 16);
    y = panelY - shift;
    x = panelX + (side ? 0 : 40);

    map = *gCurrentMap;
    targetX = M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X);
    targetY = M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y);
    if (PULSE_PHASE < 16)
        color = EaseInterpolate(4, 0, 15, PULSE_PHASE, 16);
    else
        color = EaseInterpolate(1, 15, 0, PULSE_PHASE - 16, 16);
    map = *gCurrentMap;
    unitId = M2C_FIELD(map, u8 *, targetX + M2C_FIELD(map + 2*targetY, u16 *, MAP_ROW_OFFSETS));
    terrainTarget = GetTileTargetKind(targetX, targetY);
    if (unitId) {
        func_020d166c(M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), unitId, position);
        map = *gCurrentMap;
        damage = M2C_FIELD(map, s16 *, MAP_BATTLE_DAMAGE);
        targetHealth = M2C_FIELD(map, s16 *, 0x6ef4);
    } else {
        if (!terrainTarget)
            return;
        func_020d1690(M2C_FIELD(*gCurrentMap, u8 *, MAP_CURSOR_UNIT_ID), terrainTarget, position);
        map = *gCurrentMap;
        y += 24;
        damage = M2C_FIELD(map, s16 *, MAP_BATTLE_DAMAGE);
    }
    if (targetHealth >= 90)
        band = 3;
    else if (targetHealth >= 70)
        band = 2;
    else if (targetHealth > 0)
        band = 1;
    else
        band = 0;

    switch (band) {
    case 0: func_01ff9e78(data_02120700 + color, 0x33e, 2); break;
    case 1: func_01ff9e78(data_02120720 + color, 0x33e, 2); break;
    case 2: func_01ff9e78(data_02120740 + color, 0x33e, 2); break;
    case 3: func_01ff9e78(data_02120760 + color, 0x33e, 2); break;
    }
    spriteX = (x + 8) & 0x1ff;
    AddSprite((u16)spriteX, (u16)((y - 24) & 0xff), (u16)Tile6e0c(0x150, 0x80), &gSpriteDesc32x8, 10);
    AddSprite((u16)spriteX, (u16)((y - 16) & 0xff), (u16)Tile6e0c(0x150, 0x84), &gSpriteDesc32x16, 10);
    ((void (*)(s32, s32, s32))DrawDecimalNumber)(x + 23, y - 15, damage);
#undef PULSE_PHASE
}
#pragma pop
/* Draws a unit's icon on the map at screen (x,y): copies the unit's 16x16 icon
 * tile for its kind and the owning player's colour variant into the sprite
 * engine, draws that sprite and a second one below it, and then the unit's
 * health-bar count as a decimal number unless the unit is at full health.
 * iconIndex is the carried-unit icon slot; unit is the unit's BattleMapUnit
 * record, 0 for an empty slot. */
void DrawUnitIcon(s32 x,s32 y,s32 iconIndex,s32 unit){
s32 GetUnitKind(s32);s32 GetUnitHealthBarCount(s32);s32 GetUnitIconTiles(s32,u8);
void QueueMemoryCopy(s32,s32,s32,s32);void AddSprite(u16,u16,u16,void *,s32);void DrawDecimalNumber(s32,u8,s32);
extern void *gCur3DSpriteEngine;extern M2C_UNK gSpriteDesc16x16;
extern s32 *gCurrentMap;
s32 kind=GetUnitKind(unit);s32 unitIndex,variant,healthBars,tile;s32 screenY,screenX;
if(unit==0)unitIndex=0;else unitIndex=(unit-(*gCurrentMap+MAP_UNIT_RECORDS))/MAP_UNIT_STRIDE;
variant=M2C_FIELD(*gCurrentMap+((unitIndex>>6)+1)*MAP_PLAYER_STRIDE,u8 *,0x67cd);
healthBars=GetUnitHealthBarCount(unit);tile=(iconIndex+1)*4+0x218;
QueueMemoryCopy(GetUnitIconTiles(kind,variant),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+(tile<<5),128,0);
screenY=y&255;screenX=x&511;
AddSprite((u16)screenX,(u16)screenY,(u16)((1023&(tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x8000),&gSpriteDesc16x16,9);
screenY+=0x400;
AddSprite((u16)screenX,(u16)screenY,(u16)((1023&(0x150>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))|0x9000)+(1023&(0x60>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),&gSpriteDesc16x16,10);
if(healthBars==10)return;
DrawDecimalNumber((x+8)&511,(y+8)&255,healthBars);
}
#pragma opt_common_subs reset
/* Draws the icons of the units `unit` carries, just above the info panel at
 * (x,y): the first carried unit goes in the icon slot of the panel's side,
 * then the next one in the slot beside it.  panelSide is 0 for a left-hand
 * panel and 1 for a right-hand one. */
void DrawCarriedUnits(s32 x, s32 y, s32 panelSide, BattleMapUnit *unit) {
    OffsetTable offsets = gCarriedUnitIconOffsets;
    s32 slot = 0;
    u32 carriedId;

    carriedId = unit->firstCarried;
    if (carriedId) {
        DrawUnitIcon(x + offsets.v[panelSide][0], y - 16, slot,
                     *gCurrentMap + MAP_UNIT_RECORDS + carriedId * MAP_UNIT_STRIDE);
        slot++;
    }
    carriedId = unit->nextCarried;
    if (!carriedId) return;
    DrawUnitIcon(x + offsets.v[panelSide][slot], y - 16, slot,
                 *gCurrentMap + MAP_UNIT_RECORDS + carriedId * MAP_UNIT_STRIDE);
}
static inline s32 SecondTile7944(void) {
extern void *gCur3DSpriteEngine;
u32 b,a;
a=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
b=M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0);
return (((0x150 >> ((a<<17)>>30))&1023)|0x9000)+((0x60 >> ((b<<17)>>30))&1023);
}
