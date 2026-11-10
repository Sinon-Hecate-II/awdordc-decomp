/* 10 functions from 0x0216B898 to 0x0216C7F0 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct PanelInitFlags { unsigned char bit0:1; unsigned char mid:4; unsigned char high:3; } PanelInitFlags;
extern void *gCur3DSpriteEngine;
extern u8 data_ov000_021b8384[],data_ov000_021b83a0[],data_ov000_021b837c[],data_ov000_021b83d8[],data_ov000_021b8392[];
extern s16 gSinCosTable[];
#define ENGINE M2C_FIELD(gCur3DSpriteEngine,void**,0)
#define SIZE ((u32)(M2C_FIELD(ENGINE,u16*,0)<<17)>>30)
#define ATTR(tile,pal) ((u16)(((tile)>>SIZE & 0x3ff)|(pal)))
#define GET(off) GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(arg0,void**,off),void**,0))

#pragma peephole off
void func_ov000_0216b898(void *arg0){
s32 GetSpriteAnimValue(void*);s32 func_020e31e0(void);
s32 func_ov000_0216b15c(s32,s32,s32,s32);s32 func_020a93e4(void*,u8);
s32 func_0207c8ec(s32,s32);void SetSpriteQuad(s32,s16,s16,s16,s16);
void AddSprite(u16,u16,u16,void*,s32);void DrawTileRow(u16,s32,s32,u16,s32);
s32 x1,x2,y1,y2,anchor,xa,ya,i,tile;u16 *volatile control;
if(!M2C_FIELD(arg0,u8*,0x36))return;
switch(func_020e31e0()){
case 0:{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(GetSpriteAnimValue(tmp)-4); }ya=12;x1=GET(0x48);y1=34;x2=GET(0x4c);y2=60;break;
case 2:case 3:
{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(GetSpriteAnimValue(tmp)-4); }ya=12;
if(M2C_FIELD(arg0,u8*,0x3d)){x2=GET(0x4c);y2=34;x1=GET(0x48);y1=68;}
else{x1=GET(0x48);y1=34;x2=GET(0x4c);y2=60;}break;
case 1:case 4:case 5:default:{ void *tmp=M2C_FIELD(M2C_FIELD(arg0,void**,0x48),void**,0); xa=(s16)(GetSpriteAnimValue(tmp)-4); }ya=38;x1=GET(0x48);y1=12;
if(M2C_FIELD(arg0,u8*,0x3d)){x2=GET(0x4c);y2=60;}else{x2=GET(0x4c);y2=42;}break;
}
anchor=GET(0x44);i=GET(0x44);
control=(u16*)(ENGINE+0x12);*control=(*control&~0xc0)|0x40;
M2C_FIELD(ENGINE,u8*,0x51)=i;M2C_FIELD(ENGINE,u8*,0x52)=16-anchor;
anchor=GET(0x5c);
if(func_ov000_0216b15c(anchor,134,128,32))AddSprite((u16)(anchor&511),134,ATTR(0x43e,0xb000),data_ov000_021b8384,11);
tile=M2C_FIELD(arg0,u8*,0x3d)?0x368:0x35c;
if(func_ov000_0216b15c(x1,y1,48,16)){u16 x=x1&511;u16 attr=ATTR(tile,0xb000);AddSprite(x,(u16)(y1&255),attr,data_ov000_021b83a0,11);}
{
void *p=M2C_FIELD(arg0,void**,0x40);
if(M2C_FIELD(p,u8*,10)==3)M2C_FIELD(p,u8*,0x17)=28;
else if(M2C_FIELD(p,u8*,10)==2)M2C_FIELD(p,u8*,0x17)=30;
else M2C_FIELD(p,u8*,0x17)=26;
}
M2C_FIELD(M2C_FIELD(arg0,void**,0x40),s16*,6)=x2;
for(i=0;i<M2C_FIELD(M2C_FIELD(arg0,void**,0x40),u8*,10);i++){
s32 x=func_020a93e4(M2C_FIELD(arg0,void**,0x40),(u8)i);
if(func_ov000_0216b15c(x,y2,32,32)){
void *p=M2C_FIELD(arg0,void**,0x40);
s32 offset=(u16)(M2C_FIELD(p,u16*,0x12)+M2C_FIELD(p,u8*,0x16)*M2C_FIELD(p+(i&255),u8*,11));
AddSprite((u16)(x&511),(u16)(y2&255),ATTR(offset+0x374,0xb000),data_ov000_021b837c,11);
}
}
if(GET(0x58)>1){
s32 a,b,c,d,scale1,scale2,sine,cosine;
if((GET(0x58)<0 ? -GET(0x58):GET(0x58))>=2)scale1=GET(0x58);else if(GET(0x58)>2)scale1=2;else if(GET(0x58)<-2)scale1=-2;else scale1=GET(0x58);
cosine=gSinCosTable[1];sine=gSinCosTable[0];
if((GET(0x58)<0 ? -GET(0x58):GET(0x58))>=2)scale2=GET(0x58);else if(GET(0x58)>2)scale2=2;else if(GET(0x58)<-2)scale2=-2;else scale2=GET(0x58);
a=func_0207c8ec(cosine<<4,256);
b=func_0207c8ec((-sine)<<4,scale2);
c=func_0207c8ec(sine<<4,256);
d=func_0207c8ec(cosine<<4,scale1);
SetSpriteQuad(0,a,b,c,d);
x1=GET(0x54);
AddSprite((u16)(x1&511),104,ATTR(0x414,0xb000),data_ov000_021b83d8,11);
if(GET(0x58)>20){x1=GET(0x54);DrawTileRow((u16)((M2C_FIELD(arg0,s16*,0x3e)+x1)&511),360,96,ATTR(0x47e,0x2000),10);}
}
if(M2C_FIELD(arg0,u8*,0x3d)&&func_ov000_0216b15c(xa,ya,48,16))
{u16 x=xa&511;u16 attr=ATTR(0x432,0xb000);AddSprite(x,(u16)(ya&255),attr,data_ov000_021b8392,11);}
}
#pragma scheduling reset
#pragma opt_scheduling reset
#pragma peephole reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_ov000_0216bfa4(void *arg0) {
extern u16 *gKeyState;
extern u8 *gTouchState;
func_020a91a8(M2C_FIELD(arg0,s32 *,0x44));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x48));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x4c));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x50));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x54));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x58));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x5c));
switch(M2C_FIELD(arg0,u16 *,0x34)){
case 8:PlaySoundEffect(0x1003e);
case 0x68:PlaySoundEffect(0x1003f);
}
if((*gKeyState &9)||gTouchState[0x14]||M2C_FIELD(arg0,u16 *,0x34)==0x83)func_01ffa6fc(arg0);
M2C_FIELD(arg0,u16 *,0x34)++;
}

void func_ov000_0216c068(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    M2C_FIELD(arg0, u8 *, 0x36) = 0;
}

void func_ov000_0216c09c(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
func_020c0a88();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_ov000_0216c1c4(void) {
    M2C_UNK func_ov000_0216b194();
    func_ov000_0216b194();
}

void func_ov000_0216c1d0(void) {
    void func_ov000_0216c09c(void);
    func_ov000_0216c09c();
}

void func_ov000_0216c1dc(void) {
    void func_ov000_0216c068();
    func_ov000_0216c068();
}

void func_ov000_0216c1e8(void) {
    void func_ov000_0216b898();
    func_ov000_0216b898();
}

void func_ov000_0216c1f4(void) {
    void func_ov000_0216bfa4();
    func_ov000_0216bfa4();
}

/* Builds the ov000 army info window for the player whose turn it is: a UI node
 * holding that player's army state and colour, a unit-stat panel, and seven
 * icon animations each with its own frame table. */
void BuildArmyInfoWindow(void) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *MemAlloc(M2C_UNK);
    M2C_UNK func_020a9218(void *);
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gMapConfig;
    extern void *gCurrentMap;
    extern M2C_UNK data_ov000_021b83f8;
    extern M2C_UNK data_ov000_021b841c;
    extern M2C_UNK data_ov000_021b844c;
    extern M2C_UNK data_ov000_021b8488;
    extern M2C_UNK data_ov000_021b84c4;
    extern M2C_UNK data_ov000_021b8500;
    extern M2C_UNK data_ov000_021b853c;
    extern M2C_UNK data_ov000_021b8578;
    extern M2C_UNK data_ov000_021b8690;
    s8 detailed;
    u16 currentPlayer;
    void *mapPtr;
    void *window;
    void *frames3;
    void *icon4;
    void *frames4;
    void *icon5;
    void *frames5;
    void *icon6;
    void *frames6;
    void *panel;
    void *icon0;
    void *frames0;
    void *icon1;
    void *frames1;
    void *icon2;
    void *frames2;
    void *icon3;

    window = func_01ffa3dc(&data_ov000_021b8578, 7);
    if (window == NULL) {
        return;
    }
    detailed = 0;
    M2C_FIELD(window, M2C_UNK **, 0) = &data_ov000_021b8690;
    M2C_FIELD(window, s16 *, 0x34) = 0;
    M2C_FIELD(window, s8 *, 0x36) = 0;
    M2C_FIELD(window, s16 *, 0x38) = 0x100;
    currentPlayer = M2C_FIELD(*(void **)gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
    M2C_FIELD(window, s8 *, 0x3A) = (s8)currentPlayer;
    mapPtr = (void*)*(void **)gCurrentMap;
    currentPlayer=(u8)currentPlayer;
    M2C_FIELD(window, u8 *, 0x3B) = (u8)M2C_FIELD((mapPtr + ((s32)currentPlayer * MAP_PLAYER_STRIDE)), u8 *, PLAYER_ARMY_STATE_OFF);
    mapPtr = (void*)*(void **)gCurrentMap;
    M2C_FIELD(window, s8 *, 0x3C) = (s8)(M2C_FIELD((mapPtr + ((s32)(u8)M2C_FIELD(window, u8 *, 0x3A) * MAP_PLAYER_STRIDE)), u8 *, PLAYER_ARMY_INDEX_OFF) - 1);
    if (M2C_FIELD(&gMapConfig, u8 *, 3) != 0) {
        detailed = 1;
    }
    M2C_FIELD(window, s8 *, 0x3D) = detailed;
    M2C_FIELD(window, s16 *, 0x3E) = 0;
    panel = MemAlloc(0x2C);
    if (panel != NULL) {
        M2C_FIELD(panel, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(panel, s8 *, 4) = 0;
        M2C_FIELD(panel, s16 *, 0x12) = 0;
        M2C_FIELD(panel, s8 *, 0x14) = 8;
        M2C_FIELD(panel, s8 *, 0x15) = 8;
        M2C_FIELD(panel, s8 *, 0x16) = 1;
        M2C_FIELD(panel, s8 *, 0x17) = 8;
        M2C_FIELD(panel, s8 *, 0x18) = 8;
        ((PanelInitFlags *)(panel+0x20))->bit0=0;
        ((PanelInitFlags *)(panel+0x20))->mid=0;
        ((PanelInitFlags *)(panel+0x20))->high=2;
        M2C_FIELD(panel, s8 *, 0x21) = 0;
        M2C_FIELD(panel, s32 *, 0x24) = 0;
        M2C_FIELD(panel, u8 *, 0x28) = (u8) (M2C_FIELD(panel, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(panel, s8 *, 0x29) = 0;
    }
    M2C_FIELD(window, void **, 0x40) = panel;
    icon0 = MemAlloc(0x10);
    if (icon0 != NULL) {
        M2C_FIELD(icon0, M2C_UNK **, 4) = &data_ov000_021b844c;
        M2C_FIELD(icon0, M2C_UNK **, 8) = &data_ov000_021b844c;
        M2C_FIELD(icon0, s16 *, 0xC) = 0;
        M2C_FIELD(icon0, s8 *, 0xE) = 0;
        M2C_FIELD(icon0, s8 *, 0xF) = 0;
        frames0 = MemAlloc(0x12);
        if (frames0 != NULL) {
            M2C_FIELD(frames0, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon0, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames0, s8 *, 1) = 0;
            M2C_FIELD(frames0, u16 *, 2) = 0U;
            M2C_FIELD(frames0, u16 *, 4) = 0U;
            M2C_FIELD(frames0, s16 *, 6) = 1;
            M2C_FIELD(frames0, s16 *, 8) = 0;
            M2C_FIELD(frames0, s16 *, 0xA) = 1;
            M2C_FIELD(frames0, s16 *, 0xC) = 1;
            M2C_FIELD(frames0, s16 *, 0xE) = 0;
            M2C_FIELD(frames0, s16 *, 0x10) = 0;
            M2C_FIELD(frames0, u16 *, 2) = (u16) M2C_FIELD(frames0, u16 *, 4);
        }
        M2C_FIELD(icon0, void **, 0) = frames0;
        M2C_FIELD(icon0, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon0, M2C_UNK **, 4);
        M2C_FIELD(icon0, s16 *, 0xC) = 0;
        func_020a9218(icon0);
        M2C_FIELD(icon0, s8 *, 0xE) = 0;
        M2C_FIELD(icon0, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x44) = icon0;
    icon1 = MemAlloc(0x10);
    if (icon1 != NULL) {
        M2C_FIELD(icon1, M2C_UNK **, 4) = &data_ov000_021b8488;
        M2C_FIELD(icon1, M2C_UNK **, 8) = &data_ov000_021b8488;
        M2C_FIELD(icon1, s16 *, 0xC) = 0;
        M2C_FIELD(icon1, s8 *, 0xE) = 0;
        M2C_FIELD(icon1, s8 *, 0xF) = 0;
        frames1 = MemAlloc(0x12);
        if (frames1 != NULL) {
            M2C_FIELD(frames1, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon1, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames1, s8 *, 1) = 0;
            M2C_FIELD(frames1, u16 *, 2) = 0U;
            M2C_FIELD(frames1, u16 *, 4) = 0U;
            M2C_FIELD(frames1, s16 *, 6) = 1;
            M2C_FIELD(frames1, s16 *, 8) = 0;
            M2C_FIELD(frames1, s16 *, 0xA) = 1;
            M2C_FIELD(frames1, s16 *, 0xC) = 1;
            M2C_FIELD(frames1, s16 *, 0xE) = 0;
            M2C_FIELD(frames1, s16 *, 0x10) = 0;
            M2C_FIELD(frames1, u16 *, 2) = (u16) M2C_FIELD(frames1, u16 *, 4);
        }
        M2C_FIELD(icon1, void **, 0) = frames1;
        M2C_FIELD(icon1, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon1, M2C_UNK **, 4);
        M2C_FIELD(icon1, s16 *, 0xC) = 0;
        func_020a9218(icon1);
        M2C_FIELD(icon1, s8 *, 0xE) = 0;
        M2C_FIELD(icon1, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x48) = icon1;
    icon2 = MemAlloc(0x10);
    if (icon2 != NULL) {
        M2C_FIELD(icon2, M2C_UNK **, 4) = &data_ov000_021b84c4;
        M2C_FIELD(icon2, M2C_UNK **, 8) = &data_ov000_021b84c4;
        M2C_FIELD(icon2, s16 *, 0xC) = 0;
        M2C_FIELD(icon2, s8 *, 0xE) = 0;
        M2C_FIELD(icon2, s8 *, 0xF) = 0;
        frames2 = MemAlloc(0x12);
        if (frames2 != NULL) {
            M2C_FIELD(frames2, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon2, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames2, s8 *, 1) = 0;
            M2C_FIELD(frames2, u16 *, 2) = 0U;
            M2C_FIELD(frames2, u16 *, 4) = 0U;
            M2C_FIELD(frames2, s16 *, 6) = 1;
            M2C_FIELD(frames2, s16 *, 8) = 0;
            M2C_FIELD(frames2, s16 *, 0xA) = 1;
            M2C_FIELD(frames2, s16 *, 0xC) = 1;
            M2C_FIELD(frames2, s16 *, 0xE) = 0;
            M2C_FIELD(frames2, s16 *, 0x10) = 0;
            M2C_FIELD(frames2, u16 *, 2) = (u16) M2C_FIELD(frames2, u16 *, 4);
        }
        M2C_FIELD(icon2, void **, 0) = frames2;
        M2C_FIELD(icon2, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon2, M2C_UNK **, 4);
        M2C_FIELD(icon2, s16 *, 0xC) = 0;
        func_020a9218(icon2);
        M2C_FIELD(icon2, s8 *, 0xE) = 0;
        M2C_FIELD(icon2, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x4C) = icon2;
    icon3 = MemAlloc(0x10);
    if (icon3 != NULL) {
        M2C_FIELD(icon3, M2C_UNK **, 4) = &data_ov000_021b853c;
        M2C_FIELD(icon3, M2C_UNK **, 8) = &data_ov000_021b853c;
        M2C_FIELD(icon3, s16 *, 0xC) = 0;
        M2C_FIELD(icon3, s8 *, 0xE) = 0;
        M2C_FIELD(icon3, s8 *, 0xF) = 0;
        frames3 = MemAlloc(0x12);
        if (frames3 != NULL) {
            M2C_FIELD(frames3, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon3, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames3, s8 *, 1) = 0;
            M2C_FIELD(frames3, u16 *, 2) = 0U;
            M2C_FIELD(frames3, u16 *, 4) = 0U;
            M2C_FIELD(frames3, s16 *, 6) = 1;
            M2C_FIELD(frames3, s16 *, 8) = 0;
            M2C_FIELD(frames3, s16 *, 0xA) = 1;
            M2C_FIELD(frames3, s16 *, 0xC) = 1;
            M2C_FIELD(frames3, s16 *, 0xE) = 0;
            M2C_FIELD(frames3, s16 *, 0x10) = 0;
            M2C_FIELD(frames3, u16 *, 2) = (u16) M2C_FIELD(frames3, u16 *, 4);
        }
        M2C_FIELD(icon3, void **, 0) = frames3;
        M2C_FIELD(icon3, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon3, M2C_UNK **, 4);
        M2C_FIELD(icon3, s16 *, 0xC) = 0;
        func_020a9218(icon3);
        M2C_FIELD(icon3, s8 *, 0xE) = 0;
        M2C_FIELD(icon3, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x50) = icon3;
    icon4 = MemAlloc(0x10);
    if (icon4 != NULL) {
        M2C_FIELD(icon4, M2C_UNK **, 4) = &data_ov000_021b83f8;
        M2C_FIELD(icon4, M2C_UNK **, 8) = &data_ov000_021b83f8;
        M2C_FIELD(icon4, s16 *, 0xC) = 0;
        M2C_FIELD(icon4, s8 *, 0xE) = 0;
        M2C_FIELD(icon4, s8 *, 0xF) = 0;
        frames4 = MemAlloc(0x12);
        if (frames4 != NULL) {
            M2C_FIELD(frames4, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon4, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames4, s8 *, 1) = 0;
            M2C_FIELD(frames4, u16 *, 2) = 0U;
            M2C_FIELD(frames4, u16 *, 4) = 0U;
            M2C_FIELD(frames4, s16 *, 6) = 1;
            M2C_FIELD(frames4, s16 *, 8) = 0;
            M2C_FIELD(frames4, s16 *, 0xA) = 1;
            M2C_FIELD(frames4, s16 *, 0xC) = 1;
            M2C_FIELD(frames4, s16 *, 0xE) = 0;
            M2C_FIELD(frames4, s16 *, 0x10) = 0;
            M2C_FIELD(frames4, u16 *, 2) = (u16) M2C_FIELD(frames4, u16 *, 4);
        }
        M2C_FIELD(icon4, void **, 0) = frames4;
        M2C_FIELD(icon4, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon4, M2C_UNK **, 4);
        M2C_FIELD(icon4, s16 *, 0xC) = 0;
        func_020a9218(icon4);
        M2C_FIELD(icon4, s8 *, 0xE) = 0;
        M2C_FIELD(icon4, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x54) = icon4;
    icon5 = MemAlloc(0x10);
    if (icon5 != NULL) {
        M2C_FIELD(icon5, M2C_UNK **, 4) = &data_ov000_021b841c;
        M2C_FIELD(icon5, M2C_UNK **, 8) = &data_ov000_021b841c;
        M2C_FIELD(icon5, s16 *, 0xC) = 0;
        M2C_FIELD(icon5, s8 *, 0xE) = 0;
        M2C_FIELD(icon5, s8 *, 0xF) = 0;
        frames5 = MemAlloc(0x12);
        if (frames5 != NULL) {
            M2C_FIELD(frames5, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon5, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames5, s8 *, 1) = 0;
            M2C_FIELD(frames5, u16 *, 2) = 0U;
            M2C_FIELD(frames5, u16 *, 4) = 0U;
            M2C_FIELD(frames5, s16 *, 6) = 1;
            M2C_FIELD(frames5, s16 *, 8) = 0;
            M2C_FIELD(frames5, s16 *, 0xA) = 1;
            M2C_FIELD(frames5, s16 *, 0xC) = 1;
            M2C_FIELD(frames5, s16 *, 0xE) = 0;
            M2C_FIELD(frames5, s16 *, 0x10) = 0;
            M2C_FIELD(frames5, u16 *, 2) = (u16) M2C_FIELD(frames5, u16 *, 4);
        }
        M2C_FIELD(icon5, void **, 0) = frames5;
        M2C_FIELD(icon5, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon5, M2C_UNK **, 4);
        M2C_FIELD(icon5, s16 *, 0xC) = 0;
        func_020a9218(icon5);
        M2C_FIELD(icon5, s8 *, 0xE) = 0;
        M2C_FIELD(icon5, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x58) = icon5;
    icon6 = MemAlloc(0x10);
    if (icon6 != NULL) {
        M2C_FIELD(icon6, M2C_UNK **, 4) = &data_ov000_021b8500;
        M2C_FIELD(icon6, M2C_UNK **, 8) = &data_ov000_021b8500;
        M2C_FIELD(icon6, s16 *, 0xC) = 0;
        M2C_FIELD(icon6, s8 *, 0xE) = 0;
        M2C_FIELD(icon6, s8 *, 0xF) = 0;
        frames6 = MemAlloc(0x12);
        if (frames6 != NULL) {
            M2C_FIELD(frames6, s8 *, 0) = (s8) M2C_FIELD(M2C_FIELD(icon6, M2C_UNK **, 8), s32 *, 4);
            M2C_FIELD(frames6, s8 *, 1) = 0;
            M2C_FIELD(frames6, u16 *, 2) = 0U;
            M2C_FIELD(frames6, u16 *, 4) = 0U;
            M2C_FIELD(frames6, s16 *, 6) = 1;
            M2C_FIELD(frames6, s16 *, 8) = 0;
            M2C_FIELD(frames6, s16 *, 0xA) = 1;
            M2C_FIELD(frames6, s16 *, 0xC) = 1;
            M2C_FIELD(frames6, s16 *, 0xE) = 0;
            M2C_FIELD(frames6, s16 *, 0x10) = 0;
            M2C_FIELD(frames6, u16 *, 2) = (u16) M2C_FIELD(frames6, u16 *, 4);
        }
        M2C_FIELD(icon6, void **, 0) = frames6;
        M2C_FIELD(icon6, M2C_UNK **, 8) = (M2C_UNK *) M2C_FIELD(icon6, M2C_UNK **, 4);
        M2C_FIELD(icon6, s16 *, 0xC) = 0;
        func_020a9218(icon6);
        M2C_FIELD(icon6, s8 *, 0xE) = 0;
        M2C_FIELD(icon6, s8 *, 0xF) = 0;
    }
    M2C_FIELD(window, void **, 0x5C) = icon6;
}

