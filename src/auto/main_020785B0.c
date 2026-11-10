/* 10 functions from 0x020785B0 to 0x020793F0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s32 ClampRenderCoord(s32 v, u16 *dims, s32 axis) {
 s32 max=dims[axis]-1;
 if(v>max)return max;
 if(v<0)v=0;
 return v;
}
typedef struct { u8 x,y; u16 dx:3,dy:3,kind:4,unused:4,angle:2; u8 value; } MapRenderEntry;

typedef struct { s32 x,y,z; } Vec3;
typedef struct { u8 kind:6; u8 side:2; u8 pad[5]; u16 hp:7; u16 rest:9; } RenderUnit;
typedef struct { Vec3 pos; void *unit; s32 kind,frame,variant,side,hp,flags; u8 color; u8 pad[3]; s32 extra; u8 mode; u8 pad2[3]; } UnitRenderContext;
extern u8 gMapCellCodes[1920], data_02141788[1920];
extern s16 gSinCosTable[2048];
extern u32 gTerrainClassFlags[][2];

extern u32 gFrameCounter;
extern u8 data_02140f70[24];

void func_020785b0(void) {
    s32 GetViewZoom(s32);
    extern s32 *gCurrentMap;
    s32 var_r0;
    if ((s32)(gFrameCounter % 140) < 60) {
        data_02140f70[1] = 0;
    } else {
        data_02140f70[1] = 1;
    }
    if (GetViewZoom(*gCurrentMap + 0x6EF8) <= 0) {
        var_r0 = 0x10;
    } else {
        var_r0 = 0x18;
    }
    if (var_r0 == 0x10) {
        data_02140f70[1] = 0;
    }
}

void func_0207863c(void) {
    data_02140f70[2] = (gFrameCounter / 12) & 3;
}

#pragma scheduling on
void func_0207866c(void){
void func_02003fc8(s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_02077bb4(s32);
extern s32 *gCurrentMap;
extern u16 data_020eb290[][4];
u32 kind=M2C_FIELD(*gCurrentMap,u8 *,0x5157);
u16 *v=data_020eb290[kind];
*(volatile u32 *)0x4000440=0;
*(volatile u32 *)0x4000454=0;
func_02003fc8(0,192,0,256,-1000,0,4096,1,0);
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000480=v[0];
*(volatile u32 *)0x400048c=0;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[1];
*(volatile u32 *)0x400048c=0xc00000;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[2];
*(volatile u32 *)0x400048c=0xc00100;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000480=v[3];
*(volatile u32 *)0x400048c=0x100;*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000504=0;
func_02077bb4(*gCurrentMap+0x6ef8);
*(volatile u32 *)0x4000480=0x7fff;
}

void func_0207877c(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 GetViewZoom(s32);
    s32 func_02090158(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020901b0(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern s32 *gCurrentMap;
    s32 temp_r0;
    s32 var_r5;
    s32 var_r6;

    var_r6 = arg2;
    temp_r0 = GetViewZoom(*gCurrentMap + 0x6EF8);
    var_r5 = 0;
    if (var_r6 != 0) {
        if (var_r6 < 8) {
            var_r6 = 8;
        }
        var_r5 = EaseInterpolate(0, 0, 0x7F, var_r6 * temp_r0, 0x1000);
        if (var_r5 > 0x7F) {
            var_r5 = 0x7F;
        } else if (var_r5 < 0) {
            var_r5 = 0;
        }
    }
    if (func_02090158(arg0, var_r5, 0xA) != 0) {
        return;
    }
    if (var_r5 == 0) {
        return;
    }
    func_020901b0(arg0, -1, arg1, var_r5);
}

#pragma push
#pragma opt_strength_reduction off
void DrawMapEffectEntry(void*);
void RenderUnitAt(s32,s32,s32,u8);
void func_02079310(s32,s32,s32,s32,s32,s32,s32,s32);
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma scheduling off
void func_02078828(void) {
extern s32 *gCurrentMap;
extern u16 data_02142ebc[],data_02143dbc[];
void func_02079d0c(s32,s32,Vec3*);
s32 Divide(s32,s32);
s32 rawx,rawy,rawx1,rawy1;
s32 i,y,x,x1,mode,x0,y0,y1;
u32 counts[32];
Vec3 pos;
s32 base,tile,visible,v1,v2;
u16 a,b;
u32 index;
mode=M2C_FIELD(*gCurrentMap,u16*,0x52b4)==10?1:0;
func_02077624();func_02077a4c();func_0207866c();
*(volatile u32*)0x4000444=0;
*(volatile u32*)0x4000440=3;
*(volatile u32*)0x4000454=0;
*(volatile u32*)0x4000440=2;
*(volatile u32*)0x4000454=0;
func_02079d0c(0,0,&pos);
rawx=Divide(pos.x,768); rawy=Divide(pos.y,768);
func_02079d0c(256,192,&pos);
rawx1=Divide(pos.x,768);rawy1=Divide(pos.y,768);
x0=ClampRenderCoord(rawx,(u16*)(*gCurrentMap+0x5120),18);
y0=ClampRenderCoord(rawy,(u16*)(*gCurrentMap+0x5120),19);
x1=ClampRenderCoord(rawx1,(u16*)(*gCurrentMap+0x5120),18);
y1=ClampRenderCoord(rawy1,(u16*)(*gCurrentMap+0x5120),19);
func_0207750c();BuildMapCellCodes(x0,y0,x1,y1);func_02078340(x0,y0,x1,y1);
func_02078528();func_020785b0();func_0207863c();func_0207f9f4();
for(i=0;i<32;i++)counts[i]=0;
*(volatile u32*)0x40004a8=0x6f600000;
for(y=y0;y<=y1;y++)for(x=x0;x<=x1;x++){
if(x<0 || y<0)continue;
base=*gCurrentMap;
{ u16 *dims=(u16*)(base+0x5120);if(x>=dims[18] || y>=dims[19])continue; }
index=x+M2C_FIELD(base+y*2,u16*,0x3758);
a=((u16*)((u8*)data_02142ebc+x*80))[y];b=((u16*)((u8*)data_02143dbc+x*80))[y];
tile=M2C_FIELD(base+index,u8*,0x1420);
visible=((u8*)(base+0x5120+0xe1))[index>>3]&(1<<(index&7));
visible=(u8)visible;
if(!tile)continue;
v1=(gMapCellCodes+x*40)[y];v2=(data_02141788+x*40)[y];
counts[tile&31]++;
func_02079310(x,y,a,b,tile,visible,v1,v2);
}
func_020778cc(x0,y0,x1,y1);
for(i=0;i<32;i++){
void *p=(void*)(*gCurrentMap+0x58a4+i*8);
if((u32)(M2C_FIELD(p,u16*,2)<<22)>>28)DrawMapEffectEntry(p);
}
if(func_020cd6b0())func_02077740();
for(y=y0;y<=y1;y++)for(x=x0;x<=x1;x++){
if(func_020a62ac(x,y))RenderUnitAt(x,y,gMapCellCodes[x*40+y],mode);
}
*(volatile u32*)0x4000448=1;
func_0207877c(1,0x108,counts[26]);func_0207877c(2,0x109,counts[27]);
}
#pragma pop
void func_02078c60(s32 x,s32 y,s32 angle,s32 kind){
void func_02004078(s32,s32); void func_02079db0(s32,s32,s32,s32,s32,s32);
s32 a,b,c,d,sn,cs; a=(gMapCellCodes+x*40)[y];b=(data_02141788+x*40)[y];
*(volatile u32 *)0x4000444=0;
if(angle){d=(y<<4)*48+0x180;c=(x<<4)*48+0x180;
cs=gSinCosTable[(angle>>4)*2+1];sn=gSinCosTable[(angle>>4)*2];
*(volatile u32 *)0x4000470=c;*(volatile u32 *)0x4000470=d;*(volatile u32 *)0x4000470=0;
func_02004078(sn,cs);
*(volatile u32 *)0x4000470=-c;*(volatile u32 *)0x4000470=-d;*(volatile u32 *)0x4000470=0;}
*(volatile u32 *)0x4000470=0;*(volatile u32 *)0x4000470=0x300;*(volatile u32 *)0x4000470=0;
func_02079db0(x,y,kind,0,a,b);*(volatile u32 *)0x4000448=1;
}

#pragma push
#pragma scheduling on
#pragma opt_common_subs on
/* Draws one map order/effect marker on the 3D layer: kind 3 is a pulsating
   alpha-blended quad, 6/7/8 are sprites (optionally rotated) and 9 calls the
   map's cell callback. */
void DrawMapEffectEntry(void *arg0) {
s32 func_020ae22c(s32);s32 EaseInterpolate(s32,s32,s32,s32,s32);s32 GetFacingOffset(s32);void func_020cf674(s16,s16,s32);
MapRenderEntry *entry=arg0;u32 bits=M2C_FIELD(arg0,u16 *,2);s32 x=M2C_FIELD(arg0,u8 *,0),y=M2C_FIELD(arg0,u8 *,1);
s32 offX=entry->dx,offY=entry->dy; s32 x0,y0,x1,y1,color; u32 alpha; s16 sx0,sy0,sx1,sy1;
switch(entry->kind){
case 3:
x0=(x<<4)*48;y0=(y<<4)*48;x1=x0+offX*768;y1=y0+offY*768;
color=func_020ae22c(M2C_FIELD(arg0,u8 *,4));
if(((*(volatile u32 *)&gFrameCounter)&63)<32)alpha=EaseInterpolate(4,2,12,(*(volatile u32 *)&gFrameCounter)&63,32);
else alpha=EaseInterpolate(1,12,2,((*(volatile u32 *)&gFrameCounter)&63)-32,32);
if(!(alpha=(u8)alpha))return;
*(volatile u32*)0x40004a8=0x2d00000;
*(volatile u32*)0x40004a4=0x70000c0|(alpha<<16);
sx0=x0;sy0=y0;sx1=x1;sy1=y1;
*(volatile u32*)0x4000500=1;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx0|((u16)sy0<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx0|((u16)sy1<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx1|((u16)sy1<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000480=color;*(volatile u32*)0x400048c=(u16)sx1|((u16)sy0<<16);*(volatile u32*)0x400048c=0x430;
*(volatile u32*)0x4000504=0;*(volatile u32*)0x4000480=0x7fff;return;
case 6:func_02078c60(x,y,0,0x381);return;
case 7:func_02078c60(x,y,(u16)GetFacingOffset(entry->angle),0x382);return;
case 8:func_02078c60(x,y,M2C_FIELD(arg0,u8 *,4)<<8,0x382);return;
case 9:
*(volatile u32*)0x4000480=0x7fff;*(volatile u32*)0x4000444=0;
*(volatile u32*)0x4000470=0;*(volatile u32*)0x4000470=0;*(volatile u32*)0x4000470=-16;
func_020cf674((s16)(x<<4),(s16)(y<<4),M2C_FIELD(arg0,u8 *,4));
*(volatile u32*)0x4000448=1;return;
}
}
#pragma pop
/* Draws the unit standing on map tile (x,y): finds its record, collects the status
 * bits that select the unit's status icons (fuel/HP warning, cargo, acted,
 * selected, ...), converts the tile to world coordinates and hands it to
 * RenderUnitSprite. */
void RenderUnitAt(s32 x, s32 y, s32 extra, u8 mode) {
    s32 func_020a7d80(void *);
    s32 func_020a7dc4(void *);
    s32 func_020a8604(s32);
    s32 func_020a7d38(void *);
    s32 UnitHasFacing(void *);
    s32 UnitHasCargo(void *);
    s32 func_020d2850(s32, u16, s32);
    s32 HasUnitActed(void *);
    s32 IsUnitSelected(void *);
    s32 func_020a7d50(void *);
    void RenderUnitSprite(Vec3 *, RenderUnit *, s32, s32, s32, u8);
    extern s32 *gCurrentMap;

    s32 base, player, kind, vecx, vecy, vecz; s32 flags;
    u16 rowoff;
    u8 val;
    u8 *unit;
    Vec3 pos;

    base = *gCurrentMap;
    rowoff = *(u16 *)((u8 *)base + y * 2 + MAP_ROW_OFFSETS);
    val = *(u8 *)((u8 *)base + (x + rowoff) + MAP_CELL_UNIT_ID);
    if (val == 0) return;

    flags = 0;
    player = ((val & 0xc0) >> 6) + 1;
    unit = (u8 *)base + MAP_UNIT_RECORDS + (s32)(val * MAP_UNIT_STRIDE);

    if (func_020a7d80((void *)unit)) flags |= 0x2;
    if (func_020a7dc4((void *)unit)) {
        kind = ((RenderUnit *)unit)->kind;
        if (func_020a8604(kind)) flags |= 0x8;
        else flags |= 0x4;
    }
    if (func_020a7d38((void *)unit)) flags |= 0x20;
    {
        u8 side = *(u8 *)((u8 *)*gCurrentMap + (player) * MAP_PLAYER_STRIDE + PLAYER_SIDE_OFF);
        if (!(side & SIDE_TEAM_B)) flags |= 0x1;
    }
    if (UnitHasFacing((void *)unit)) flags |= 0x40;
    if (UnitHasCargo((void *)unit)) flags |= 0x80;
    {
        kind = ((RenderUnit *)unit)->kind;
        if (func_020d2850(kind, *(u16 *)((u8 *)*gCurrentMap + MAP_CURRENT_PLAYER), (u16)player)) flags |= 0x100;
    }
    if (HasUnitActed((void *)unit)) flags |= 0x200;
    if (IsUnitSelected((void *)unit)) flags |= 0x400;
    if (func_020a7d50((void *)unit)) flags |= 0x800;

    vecx = (x * 16 + 8) * 48;
    vecy = (y * 16 + 16) * 48;
    vecz = ((y << 12) >> 8) + 1073;

    pos.x = vecx;
    pos.y = vecy;
    pos.z = vecz;
    RenderUnitSprite(&pos, (RenderUnit *)unit, player, flags, extra, (u8)mode);
}

#pragma scheduling on
void RenderUnitSprite(Vec3 *arg0,RenderUnit *unit,s32 player,s32 flags,s32 extra,u8 mode){
s32 func_020a7298(s32,u8);s32 GetViewZoom(s32);s32 Divide(s32,s32);
void func_020793f0(UnitRenderContext *);void DrawUnitStatusIcon(Vec3 *,UnitRenderContext *);void func_020796b0(Vec3 *,UnitRenderContext *);
extern s32 *gCurrentMap;
Vec3 pos;UnitRenderContext ctx; s32 variant;
pos=*arg0;
variant=M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67c1)-1;
if(flags&0x200)variant+=4;
if(flags&0x400)variant+=8;
ctx.pos=pos;ctx.unit=unit;
ctx.kind=func_020a7298(unit->kind,M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67cd));
ctx.frame=GetViewZoom(*gCurrentMap+0x6ef8)<=0?16:24;
ctx.variant=variant;ctx.flags=flags;
ctx.side=unit->side;
ctx.color=M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67cc);
ctx.extra=extra;ctx.mode=mode;
ctx.hp=unit->hp==0?0:Divide(unit->hp-1,10)+1;
func_020793f0(&ctx);pos.x-=192;DrawUnitStatusIcon(&pos,&ctx);pos.x+=384;func_020796b0(&pos,&ctx);
}
void func_02079310(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h){
void func_02079db0(s32,s32,s32,s32,s32,s32);s32 func_020cfc0c(s32);
s32 flags; s32 mask,x=0,y=0;
if(f)mask=24;else{x+=16;mask=8;y=x;} flags=gTerrainClassFlags[c][0];
if(mask&(u16)flags)x+=func_020cfc0c(e);
if(d){func_02079db0(a,b,c,x,g,h);func_02079db0(a,b,d,y,g,h);return;}
func_02079db0(a,b,c,x,g,h);
}

