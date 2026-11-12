/* 17 functions from 0x020B7138 to 0x020B8078 (main), found by ds-decomp. */
#include "common.h"
void *GetLocalizedFileName(void *);
void func_0208c5fc(void *,s32,s32);
void func_0208bddc(void *,void *,s32,s32,s32);
M2C_UNK PlaySoundEffect(s32);
static inline void LoadPalette7464(u32 value) { extern void *gCur3DSpriteEngine; void AddToU16Array(s32,u16,s32); AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28),(u16)value,0x6124); }
typedef struct { u8 pad[0x48]; u32 mode:10; u32 duration:11; u32 frame:11; } FadeTask;
typedef struct { u8 pad[0x44]; u32 tile:16; u32 flags:16; } SpriteTile;

void func_020b7138(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK data_02128da4;
    void *temp_r0;

    temp_r0 = CreateSpriteObject(&data_02128da4, arg5);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg4;
}

/* Rasterize a mode-selected line into the path grid, install its endpoint as
 * the next path cell, and spawn the entities along it. */
void UpdateBeamEffect(void *task) {
    M2C_UNK func_02076910(u32, u32);
    M2C_UNK func_0207b774(u32, u32);
    M2C_UNK PlaySoundAtTile(M2C_UNK, u32, u32);
    s32 func_020b5200(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020b695c(s32, s32, M2C_UNK);
    extern void **gCurrentMap;
    extern M2C_UNK data_02128f94;
    u32 y;
    u32 mode;
    s32 spawnIndex;
    void *temp_r0;
    u32 x;

    x = M2C_FIELD(task, u32 *, 0x5C);
    y = M2C_FIELD(task, u32 *, 0x60);
    mode = M2C_FIELD(task, u32 *, 0x64);
    spawnIndex = M2C_FIELD(task, s32 *, 0x58);
    PlaySoundAtTile(0x104, x, y);
    switch (mode) {
    default:
        break;
    case 1:
    case 3:
loop_8:
        if (y < (u32) M2C_FIELD(*gCurrentMap, u16 *, 0x5146)) {
            func_02076910(x, y);
            y += 1;
            goto loop_8;
        }
        break;
    case 0:
loop_11:
        if ((x != 0) && (y < (u32) M2C_FIELD(*gCurrentMap, u16 *, 0x5146))) {
            func_02076910(x, y);
            x -= 1;
            y += 1;
            goto loop_11;
        }
        break;
    case 2:
loop_15:
        temp_r0 = *gCurrentMap;
        if ((x < (u32) M2C_FIELD(temp_r0, u16 *, 0x5144)) && (y < (u32) M2C_FIELD(temp_r0, u16 *, 0x5146))) {
            func_02076910(x, y);
            x += 1;
            y += 1;
            goto loop_15;
        }
        break;
    }
    func_0207b774(x, y);
    func_020b695c(spawnIndex, func_020b5200(&data_02128f94, 8), 8);
}

/* Spawns the beam attack effect on a tile: a beam sprite whose task extends it
 * in the facing direction, plus a charge sprite and the cursor move. */
void SpawnBeamEffect(s32 tileX, s32 tileY, u32 facing, s32 order, void *parent) {
 M2C_UNK func_0207b774(u32,u32); M2C_UNK func_0207b7e8(void *); M2C_UNK PlaySoundAtTile(M2C_UNK,u32,u32);
 u32 GetFacingOffset(u32);
 void *func_020b5188(M2C_UNK *,s32,s32,s32,s32,s32,void *);
 void func_020b51dc(void); s32 func_020b51f0(void);
 extern M2C_UNK sBeam04Color,sBeam04Sprite,sBeamChargeSprite;
 s32 beamColor,chargeColor; u32 facingTile; s32 offsetX,offsetY; void *beam,*charge;
 facingTile=GetFacingOffset(facing); offsetX=0; offsetY=0;
 func_020b51dc(); beamColor=func_020b5200(&sBeam04Color,0);
 switch(facing) {case 0:offsetX=-132;offsetY=132;break;case 1:offsetY=176;break;case 2:offsetX=132;offsetY=offsetX;break;case 3:offsetY=172;break;default:break;}
 beam=func_020b5188(&sBeam04Sprite,offsetX+tileX*16,offsetY+tileY*16,48,beamColor,0,parent);
 if(beam) {
 ((SpriteTile *)beam)->tile=(u16)(facingTile+0x4000);
 M2C_FIELD(beam,s32 *,0x58)=order; M2C_FIELD(beam,s32 *,0x5c)=tileX; M2C_FIELD(beam,s32 *,0x60)=tileY; M2C_FIELD(beam,u32 *,0x64)=facing; M2C_FIELD(beam,void (**)(void *),0x68)=UpdateBeamEffect; parent=beam;
 }
 chargeColor=func_020b51f0();
 switch(facing) {case 0:offsetX=-12;offsetY=12;break;case 1:offsetX=0;offsetY=16;break;case 2:offsetX=12;offsetY=offsetX;break;case 3:offsetX=0;offsetY=12;break;default:break;}
 charge=func_020b5188(&sBeamChargeSprite,offsetX+tileX*16,offsetY+tileY*16,32,chargeColor,1,parent);
 if(charge) {PlaySoundAtTile(0x103,tileX,tileY+2); ((SpriteTile *)charge)->tile=(u16)facingTile;}
 func_0207b774(tileX,tileY+2);func_0207b7e8(charge);
}

#pragma push
#pragma opt_common_subs off
void func_020b7464(void *a) {
s32 func_020a8b3c(s32);s32 func_0209b5e4(s32,s32);void func_02091d4c(s32);void *func_ov000_0216ce10(s32);void func_02007ef4(void *,s32,s32);void *func_ov000_0216ce84(s32);void func_01ff9e44(void *,s32,s32);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);void OpenNarcArchive(void);void LoadNarcFileDecompressed(void *,s32);void LoadNarcFileToSpriteBuffer(void *,s32,s32);void CloseNarcArchive(void);s32 Get3DSpriteLayerSize(u8,s32);void AddToU16Array(s32,u16,s32);void *func_020ab1c4(void *);void func_020aab24(void *,s32,s32,s32,s32);void func_02088e84(void *,s32,s32,s32,s32);s32 func_020aae10(void *);s32 func_020aae44(void *);void func_02087d84(void *,s32,s16,s16,u16,u16);void func_020ab150(void *,s32);void func_020aad18(void *);void func_02088f1c(void *);void *func_0208c528(s32);void func_0208c5fc(void *,s32,s32);void func_0208bddc(void *,void *,s32,s32,s32);
extern void **gCurrentMap;extern void *gCur3DSpriteEngine;extern u8 data_02128fb8[],data_02128fc0[],data_02128fcc[],data_02128fd4[],data_02128fdc[],data_02128fe4[],data_02128ff0[];
void *map,*unit,*p,*q; s32 icon,kind,base,t,n; s16 y,x;u8 flag;u16 palette;
map=*gCurrentMap;unit=(u8 *)map+0x67a4+M2C_FIELD(map,u16 *,0x52a4)*140;icon=M2C_FIELD(unit,u8 *,0x27);kind=M2C_FIELD(unit,u8 *,0x1d);
M2C_FIELD(a,s32 *,0x34)=func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x7380,func_020a8b3c(icon));
func_02091d4c(0x1d);base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x2b80;q=func_ov000_0216ce10(icon);func_02007ef4(q,base+0x4000,128);
func_01ff9e44(func_ov000_0216ce84(kind),0x360,32);
SetFileDirectory(data_02128fb8);GetLocalizedFileName(data_02128fc0);OpenNarcArchive();
LoadNarcFileDecompressed(GetLocalizedFileName(data_02128fcc),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x14)+0x2480);
LoadNarcFileDecompressed(GetLocalizedFileName(data_02128fd4),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x28));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(data_02128fdc),192,32);CloseNarcArchive();
palette=Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2);{void *engine=gCur3DSpriteEngine;u32 value=palette;AddToU16Array(M2C_FIELD(engine,s32 *,0x28),value,0x6124);}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3c)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x44)=0;
M2C_FIELD(a,void **,0x38)=func_020ab1c4(a);func_020aab24(M2C_FIELD(a,void **,0x38),1,0x120,3,1);
p=M2C_FIELD(a,void **,0x38);func_02088e84(p,0xe0,0xa0,0x100,0xa0);
flag=M2C_FIELD(M2C_FIELD(p,void **,0x64),u8 *,0x12)!=0;
if(flag){y=M2C_FIELD(p,s16 *,0x52);x=M2C_FIELD(p,s16 *,0x50);t=func_020aae10(p);n=func_020aae44(p);func_02087d84(M2C_FIELD(p,void **,0x64),1,x,y,(u16)t,(u16)n);}
func_020ab150(M2C_FIELD(a,void **,0x38),1);func_020aad18(M2C_FIELD(a,void **,0x38));func_02088f1c(M2C_FIELD(a,void **,0x38));
M2C_FIELD(a,void **,0x3c)=func_0208c528((s32)a);
func_0208c5fc(GetLocalizedFileName(data_02128fe4),0x6c00,12);q=GetLocalizedFileName(data_02128ff0);func_0208bddc(M2C_FIELD(a,void **,0x3c),q,0x6c00,12,0);
p=M2C_FIELD(a,void **,0x3c);M2C_FIELD(p,s32 *,0x34)=128;M2C_FIELD(p,s32 *,0x38)=96;M2C_FIELD(p,s32 *,0x3c)=0;
}
#pragma pop
/* Draw a centered gauge and two flanking icon sprites for the object. */
void func_020b7724(void *obj) {
void DrawTileRow(u16,s32,u16,u16,s32);
void AddSprite(s32,s32,u16,void *,s32);
extern void *gCur3DSpriteEngine; extern u8 gSpriteDesc16x16[];
s32 size=M2C_FIELD(obj,s32 *,0x34);
DrawTileRow((u16)((256-size)/2),0x58,(u16)size,(u16)(0xd000|((0x39c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),11);
AddSprite(0x38,0x58,(u16)(0xb000|((0x35c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),gSpriteDesc16x16,11);
AddSprite(0x10b8,0x58,(u16)(0xb000|((0x35c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),gSpriteDesc16x16,11);
}

void func_020b7824(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK DeleteSpriteObject(s32);
    extern void *gCur3DSpriteEngine;
    DeleteSpriteObject(M2C_FIELD(arg0, s32 *, 0x38));
    DeleteSpriteObject(M2C_FIELD(arg0, s32 *, 0x3C));
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020b7860(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    extern u16 *gKeyState;
    extern void *gTouchState;
    if (*gKeyState & 0xC0B) {
        func_01ffa6fc(arg0);
        return;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x14) == 0) return;
    func_01ffa6fc(arg0);
}

void func_020b78ac(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128d2c;
    func_01ffa3dc(&data_02128d2c, 7);
}

void func_020b78c4(void *arg0) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;

    void *r8 = arg0;
    register unsigned long field = *(u32 *)((u8 *)r8 + 0x48);
    s32 a = (u16)((field << 11) >> 21);
    s32 b = (u16)((field >> 21) & 0xFFFF);
    s32 r6 = 0x80;
    s32 c = a / 4;
    s32 r0 = 0x10;
    s32 q2;
    void *base;
    s32 r4u;
    void *spEngine;
    u16 *bp;

    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile sp0C;
    u16 *volatile sp08;
    u16 *volatile sp04;

    if (b <= c) {
        r6 = EaseInterpolate(4, -0x40, 0x80, (s32)b, c);
        r0 = EaseInterpolate(4, 0, 0x10, b, (s32)c);
    }

    q2 = (a * 3) / 4;
    if (b >= q2) {
        r4u = b - q2;
        r6 = EaseInterpolate(4, 0x80, 0x140, (s32)r4u, (s32)c);
        r0 = EaseInterpolate(4, 0x10, 0, r4u, (s32)c);
    }

    *(s32 *)((u8 *)r8 + 0x34) = r6;
    *(s32 *)((u8 *)r8 + 0x38) = 0x60;


    sp2C = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp2C = (u16)(*sp2C & ~0x1);

    sp28 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp28 = (u16)(*sp28 & ~0x2);

    sp24 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp24 = (u16)(*sp24 & ~0x4);

    sp20 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp20 = (u16)(*sp20 & ~0x8);

    sp1C = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp1C = (u16)(*sp1C & ~0x10);

    sp18 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp18 = (u16)(*sp18 | 0x100);

    sp14 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp14 = (u16)(*sp14 | 0x200);

    sp10 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp10 = (u16)(*sp10 | 0x400);

    sp0C = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp0C = (u16)(*sp0C | 0x800);

    sp08 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp08 = (u16)(*sp08 | 0x1000);

    sp04 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *sp04 = (*sp04 & ~0xc0) | 0x40;

    *(u8 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x51) = (u8)r0;
    *(u8 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x52) = (u8)(0x10 - r0);
}

#pragma opt_scalarize off
#pragma opt_decomposeaggregates off
#pragma cplusplus on
inline void func_020b7b54_clear(u16 &r) {
    r &= ~0xC0;
}
#pragma cplusplus on
extern "C" void func_020b7b54(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile p;
    p = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
    *p = (u16)(*p & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x53) = 0;
}
#pragma cplusplus off
void func_020b7bbc(void) {
void *func_0208c528(M2C_UNK); void func_020b78c4(void *); void func_020b7b54(void);
extern M2C_UNK data_02128ffc,data_02129004;
void *p; void *resource;
p=func_0208c528(7);
func_0208c5fc(GetLocalizedFileName(&data_02128ffc),0x6B80,11);
func_0208bddc(p,GetLocalizedFileName(&data_02129004),0x6B80,11,0);
M2C_FIELD(p,s32 *,0x44)|=0x380000;
M2C_FIELD(p,void (**)(void *),0x6C)=func_020b78c4;
M2C_FIELD(p,void (**)(void),0x70)=func_020b7b54;
PlaySoundEffect(0x127);
}

void func_020b7c4c(void) {
    M2C_UNK PlaySoundEffect(M2C_UNK);
    PlaySoundEffect(0xE5);
}

/* Per-frame fade-out for a 3D sprite: wipes the sprite's rows away over the last
   eleventh of the task and restores them in the first twelfth, playing the fade
   sound effects, then updates the bank's OAM attribute and row split. */
void func_020b7c5c(void *arg0) {
 s32 EaseInterpolate(s32,s32,s32,s32,s32);s32 func_0208c1dc(void*);s32 PlaySoundEffect(s32);
 extern void *gCur3DSpriteEngine;
 s32 duration=(u16)((FadeTask*)arg0)->duration;
 s32 frame=(u16)((FadeTask*)arg0)->frame;
 s32 rows=16;
 s32 step;
     u16 *volatile attrClear1;
    u16 *volatile attrClear2;
    u16 *volatile attrClear4;
    u16 *volatile attrClear8;
    u16 *volatile attrClear10;
    u16 *volatile attrSet100;
    u16 *volatile attrSet200;
    u16 *volatile attrSet400;
    u16 *volatile attrSet800;
    u16 *volatile attrSet1000;
    u16 *volatile attrSetSplit;


 if(func_0208c1dc(arg0))PlaySoundEffect(0xe6);
 if(frame==(duration*9)/12)PlaySoundEffect(0xe7);
 step=duration/12;
 if(frame<step)rows=EaseInterpolate(0,0,16,frame,step);
 if(frame>(duration*11)/12)rows=EaseInterpolate(0,rows,0,frame-(duration*11)/12,step);
     attrClear1 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrClear1 = (u16)(*attrClear1 & ~0x1);

    attrClear2 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrClear2 = (u16)(*attrClear2 & ~0x2);

    attrClear4 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrClear4 = (u16)(*attrClear4 & ~0x4);

    attrClear8 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrClear8 = (u16)(*attrClear8 & ~0x8);

    attrClear10 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrClear10 = (u16)(*attrClear10 & ~0x10);

    attrSet100 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSet100 = (u16)(*attrSet100 | 0x100);

    attrSet200 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSet200 = (u16)(*attrSet200 | 0x200);

    attrSet400 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSet400 = (u16)(*attrSet400 | 0x400);

    attrSet800 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSet800 = (u16)(*attrSet800 | 0x800);

    attrSet1000 = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSet1000 = (u16)(*attrSet1000 | 0x1000);

    attrSetSplit = (u16 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x12);
    *attrSetSplit = (*attrSetSplit & ~0xc0) | 0x40;

    *(u8 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x51) = (u8)rows;
    *(u8 *)((u8 *)*(void **)gCur3DSpriteEngine + 0x52) = (u8)(0x10 - rows);
}

#pragma cplusplus on
extern "C" void func_020b7ef0(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile p;
    p = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
    *p = (u16)(*p & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x53) = 0;
}
#pragma cplusplus off

s32 func_020b7f58(void) {
    void func_0208bddc(void *,void *,s32,s32,s32);
    s32 func_0208c54c();
    void func_0208c5fc(void *,s32,s32);
    void *GetLocalizedFileName(void *);
    extern M2C_UNK data_0212900c;
    extern M2C_UNK data_0212901c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(GetLocalizedFileName(&data_0212900c), 0x6B80, 0xB);
    func_0208bddc((void *)temp_r4, GetLocalizedFileName(&data_0212901c), 0x6B80, 0xB, 0);
    return temp_r4;
}

s32 func_020b7fb8(void) {
    extern M2C_UNK data_0212902c;
    extern M2C_UNK data_0212903c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(GetLocalizedFileName(&data_0212902c), 0x6B80, 0xB);
    func_0208bddc((void *)temp_r4, GetLocalizedFileName(&data_0212903c), 0x6B80, 0xB, 0);
    return temp_r4;
}

s32 func_020b8018(void) {
    extern M2C_UNK data_0212904c;
    extern M2C_UNK data_0212905c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(GetLocalizedFileName(&data_0212904c), 0x6B80, 0xB);
    func_0208bddc((void *)temp_r4, GetLocalizedFileName(&data_0212905c), 0x6B80, 0xB, 0);
    return temp_r4;
}

