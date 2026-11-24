/* 6 functions from 0x02173468 to 0x021743F0 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct EngineFlags_02173f78 { u8 unk_0[0x46]; u8 bg0:1,bg1:1,bg2:1,unk:5; } EngineFlags_02173f78;
typedef struct SpriteEngine_02173f78 { u8 unk_0[0x1c]; u8 *tiles; u8 unk_20[0x10]; u8 *sprites; } SpriteEngine_02173f78;
typedef struct PlayerUI_02173f78 { u8 unk_0[0x6c]; u32 sprite:8; u32 unk_6c:24; } PlayerUI_02173f78;
typedef struct { s32 values[8]; } StatsOrder1734;
typedef struct { s32 values[6]; } StatsDigits1734;
typedef struct { s32 first, second, hp, ammo; StatsDigits1734 digits; s32 count, other; u8 flags[5]; } StatsRecord1734;

#pragma push
#pragma optimization_level 4
void func_ov000_02173468(void *arg0) {
s32 GetTerrainInfoContext(void *);
s32 GetTerrainNameGraphicIndex(s32,s32);
s32 GetTerrainKindFromInfoId(s32);
void AddSprite(u16,u16,u16,void *,s32);
u8 func_ov000_02173e6c(void *);
s32 IsOnlinePlayerVoiceChatEnabled(u8);
s32 Divide(s32,s32);
s32 func_020a88e8(s32);
void DrawFrameBorderPulse(s16,s16,s32,s32,u16,s32);
void func_ov000_02174da4(s32,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;
extern void **gCurrentMap;
extern u8 gMapConfig[];
extern u8 data_ov000_021b8dfc[],gSpriteDesc32x8[],gSpriteDesc8x8[],data_02101f0c[],gSpriteDesc16x16[],data_02101f3c[],gSpriteDesc16x8[];
extern s8 data_ov000_021b56a0[],data_ov000_021b5600[],data_ov000_021b5680[],data_ov000_021b56e0[];

StatsOrder1734 order;
StatsRecord1734 r,*src;
void *saved;
s32 temp,a,b,c,digit,tens,ones,i,j,hidden,y4,n,show,base;
s32 recordOffset,y1,y2,y3,mapOffset,y5,y6,y7,counter;
s32 line,xDigit;
extern StatsOrder1734 data_ov000_021ae280;
u8 *map;
temp=GetTerrainInfoContext(arg0);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
if(!M2C_FIELD(arg0,u8 *,0x15)){
if(GetTerrainNameGraphicIndex(temp,M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0))!=-1)AddSprite(4,1,0xc144,data_ov000_021b8dfc,0);
AddSprite(135,25,(u16)(((164-M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,4))&1023)|0x6000),gSpriteDesc32x8,1);
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,8)){
AddSprite(135,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,24)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(143,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,20)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(151,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,16)+128)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(159,38,(u16)(((M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,12)+128)&1023)|0x8000),gSpriteDesc8x8,1);
}else AddSprite(147,38,0x808a,gSpriteDesc8x8,1);
a=GetTerrainKindFromInfoId(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
b=GetTerrainKindFromInfoId(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
c=GetTerrainKindFromInfoId(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
base=(data_ov000_021b56a0[a]+2*data_ov000_021b5600[b]+3*data_ov000_021b5680[c])*4;
AddSprite(136,45,(u16)(((base+192)&1023)|0x6000),gSpriteDesc32x8,1);
AddSprite(136,53,(u16)(((base+224)&1023)|0x6000),gSpriteDesc32x8,1);
{order=data_ov000_021ae280;
for(line=73,i=0;i<8;i++,line+=10){
a=GetTerrainKindFromInfoId(M2C_FIELD(M2C_FIELD(arg0,void **,0x18),s32 *,0));
digit=M2C_FIELD(data_ov000_021b56e0+order.values[i]*32,s8 *,a);if(digit<0)digit=10;
AddSprite(147,(u16)line,(u16)(((digit+128)&1023)|0x8000),gSpriteDesc8x8,1);
}
}
if(func_ov000_02173e6c(arg0)){
AddSprite(128,176,0x6100,data_02101f0c,1);
AddSprite(192,176,0x6108,data_02101f0c,1);
AddSprite(128,184,0x6110,data_02101f0c,1);
AddSprite(192,184,0x6118,data_02101f0c,1);
AddSprite(114,178,0xb140,gSpriteDesc16x16,1);
}}
counter=0;recordOffset=0;mapOffset=0;
y1=17;y2=25;y3=19;y4=35;y5=44;y6=34;y7=16;
for(;counter<4;recordOffset+=56,mapOffset+=140){
src=(StatsRecord1734 *)((u8 *)M2C_FIELD(arg0,void **,0x18)+0x3c+recordOffset);
r.first=src->first;r.second=src->second;r.hp=src->hp;r.ammo=src->ammo;
r.digits=src->digits;r.count=src->count;r.other=src->other;
r.flags[0]=src->flags[0];r.flags[1]=src->flags[1];r.flags[2]=src->flags[2];r.flags[3]=src->flags[3];r.flags[4]=src->flags[4];
if(!r.flags[3])goto next;
if(r.flags[4])a=1;else a=0;
hidden=a&255;
if(M2C_FIELD(arg0,s32 *,8)<60&&IsOnlinePlayerVoiceChatEnabled((u8)counter)){
AddSprite(241,(u16)y1,0x60be,gSpriteDesc16x8,1);
AddSprite(241,(u16)y2,0x60de,gSpriteDesc16x8,1);
}
tens=hidden?10:Divide(r.hp,10);ones=hidden?10:r.hp-tens*10;
if(tens)AddSprite(193,(u16)y3,(u16)(((tens+140)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(201,(u16)y3,(u16)(((ones+140)&1023)|0x8000),gSpriteDesc8x8,1);
map=*gCurrentMap;show=1;
if(map[0x5156]==0&&map[0x5158]!=2)show=1;
else if(!(M2C_FIELD(map+mapOffset,u8 *,0x684f)&2)&&!gMapConfig[2])show=0;
if(show){
tens=hidden?10:Divide(r.ammo,10);ones=hidden?10:r.ammo-tens*10;
if(tens)AddSprite(193,(u16)y4,(u16)(((tens+140)&1023)|0x8000),gSpriteDesc8x8,1);
AddSprite(201,(u16)(y4+65536),(u16)(((ones+140)&1023)|0x8000),gSpriteDesc8x8,1);
for(j=0,n=r.count;j<n;j++){xDigit=(5-j)*8+206;digit=hidden?10:r.digits.values[j];AddSprite((u16)xDigit,(u16)y5,(u16)(((digit+140)&1023)|0x8000),gSpriteDesc8x8,1);}
}else{
AddSprite(193,(u16)y4,0x8096,gSpriteDesc8x8,1);
AddSprite(201,(u16)y4,0x8096,gSpriteDesc8x8,1);
for(j=0;j<6;j++)AddSprite((u16)((5-j)*8+206),(u16)y5,0x8096,gSpriteDesc8x8,1);
}
if(r.flags[2]&&!func_020a88e8(M2C_FIELD(*gCurrentMap,u16 *,0x5142))){
a=r.second;b=a-6;if(b<0)b=0;
c=a;if(a>6)a=6;
AddSprite(212,(u16)y6,(u16)((((b%4)*3+(b/4)*32+208)&1023)|0x6000),data_02101f3c,1);
AddSprite(234,(u16)y6,(u16)((((a%4)*3+(a/4)*32+208)&1023)|0x6000),data_02101f3c,1);

}
if(counter+1==M2C_FIELD(*gCurrentMap,u16 *,0x52a4))DrawFrameBorderPulse(175,(s16)y7,84,38,(u16)(((0x40>>((u32)(**(u16 **)gCur3DSpriteEngine<<17)>>30))&1023)|0x1000),0);
y1+=40;y2+=40;y3+=40;y4+=40;y5+=40;y6+=40;y7+=40;
next:
++counter;
}
func_ov000_02174da4(0,182);
gCur3DSpriteEngine=saved;
M2C_FIELD(arg0,s32 *,8)++;
if(M2C_FIELD(arg0,s32 *,8)>90)M2C_FIELD(arg0,s32 *,8)=0;
}
#pragma pop
u8 func_ov000_02173e6c(void *arg0) {
    s32 GetMapViewHoldCount();
    s32 GetMapInputState();
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x14) == 0) {
        return 0U;
    }
    if (GetMapViewHoldCount() != 0) {
        return 0U;
    }
    if (GetMapInputState() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Allocate the ov000 map info window's two panels (the unit-statistics window
 * and the terrain/unit info panel), put the window in the idle state and record
 * the language it was created with. */
Ov000InfoMenu *Ov000_InfoWindow_Init(Ov000InfoMenu *menu) {
    void *MemAlloc(s32);
    void *func_ov000_02175088(void *);
    void *func_ov000_021724dc(void *);
    s32 GetLanguage(void);
    void *p;

    menu->statsWindow = 0;
    menu->panel = 0;
    menu->state = OV000_INFO_IDLE;
    menu->pendingState = 0;
    menu->refresh = 0;
    menu->trigger = 1;
    menu->pressed = 0;
    menu->hasUnit = 0;
    menu->prevMode = 0;
    menu->cursorX = -1;
    menu->cursorY = -1;
    *(u8 *)&menu->animFrame = 255; /* -1: the cursor does not blink yet */
    p = MemAlloc(20);
    if (p) p = func_ov000_02175088(p);
    menu->statsWindow = p;
    p = MemAlloc(28);
    if (p) p = func_ov000_021724dc(p);
    menu->panel = p;
    menu->language = GetLanguage();
    return menu;
}

/* Free both panels of the ov000 map info window: the unit-statistics window's
 * panel descriptor and then the terrain/unit info panel's entry table, leaving
 * the window object itself to its caller. */
void *Ov000_InfoWindow_FreePanels(Ov000InfoMenu *menu) {
    M2C_UNK MemFree(s32);
    M2C_UNK Ov000_InfoPanel_FreeEntries(s32);
    M2C_UNK Ov000_StatsWindow_FreePanel(s32);
    s32 statsWindow;
    s32 panel;

    statsWindow = (s32)menu->statsWindow;
    if (statsWindow != 0) {
        Ov000_StatsWindow_FreePanel(statsWindow);
        MemFree(statsWindow);
    }
    panel = (s32)menu->panel;
    if (panel != 0) {
        Ov000_InfoPanel_FreeEntries(panel);
        MemFree(panel);
    }
    return menu;
}

#pragma opt_if-conversion on
#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Loads and wires up all the graphics of the ov000 unit/terrain info window: it
 * points the window's sprite engine at the loaded sub engine and configures its
 * display and background layers, loads the four players' face textures and
 * palettes, then opens the cg_group archive and stages its faces, tiles, palettes
 * and name sheets before starting the open-screen transition. */
void Ov000_InfoWindow_LoadAssets(void *infoWindow) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadFileToAddress(M2C_UNK *, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
    M2C_UNK Load3DSpritePattern(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    M2C_UNK LoadFaceTexture(u8, s32, s32);
    M2C_UNK LoadFacePalette(u8, M2C_UNK, M2C_UNK, u16, s32);
    s32 func_020a7278();
    s32 func_020a7290();
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK CreateScreenTransitions(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 GetUiColor(M2C_UNK);
    M2C_UNK func_020af19c(M2C_UNK, M2C_UNK);
    s32 GetLocalizedFileName(M2C_UNK *);
    extern void **gCurrentMap;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gOv000FaceTileOffsets;
    extern M2C_UNK gOv000InfoSpriteLayout;
    extern M2C_UNK gOv000InfoDir;
    extern M2C_UNK gOv000CgGroupNarc;
    extern M2C_UNK gOv000MapInfoCg;
    extern M2C_UNK gOv000UnitInfoCg;
    extern M2C_UNK gOv000InfoObjCg;
    extern M2C_UNK gOv000MiniButtonXCg;
    extern M2C_UNK gOv000MapInfoTiles;
    extern M2C_UNK gOv000UnitInfoPalette;
    extern M2C_UNK gOv000MapInfoPalette;
    extern M2C_UNK gOv000MiniButtonPalette;
    extern M2C_UNK gOv000TerrainNameCl;
    extern M2C_UNK gOv000UnitNameCl;
    extern M2C_UNK gOv000WeaponNameCl;
    extern M2C_UNK gOv000DangerUnitCl;
    u16 *volatile ctl1C;
    u16 *volatile ctl18;
    u16 *volatile ctl14;
    u16 *volatile ctl10;
    u16 *volatile ctlC;
    u16 *volatile ctl8;
    void *savedEngine;
    register s32 copyDest;
    register s32 copyBytes;
        u16 *dispReg;
    u16 *dispReg2;
    u16 *dispReg3;
    u16 *dispReg4;
    u16 *dispReg5;
    u16 *dispReg6;
    register s32 player;
register s32 playerRecord;
    register u8 faceSpriteId;
    u8 paletteFlags;
    register s32 tiles;
    register s32 palette;

    M2C_FIELD(infoWindow, s32 *, 8) = 1;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Apply3DSpriteLayout(&gOv000InfoSpriteLayout);
    dispReg = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctl1C = dispReg;
    *ctl1C = *ctl1C & ~0x10;
    dispReg2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctl18 = dispReg2;
    *ctl18 = *ctl18 & ~0x20;
    dispReg3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctl14 = dispReg3;
    *ctl14 = *ctl14 & ~0x40;
    dispReg4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctl10 = dispReg4;
    *ctl10 = *ctl10 | 0x80;
    dispReg5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctlC = dispReg5;
    *ctlC = *ctlC & ~0x100;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x44) = 0;
    dispReg6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    ctl8 = (u16 *)((u8 *)dispReg6 + 0x12);
    *ctl8 = *ctl8 & ~0xC0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x53) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 1;
    ((EngineFlags_02173f78 *)gCur3DSpriteEngine)->bg1 = 1;
    ((EngineFlags_02173f78 *)gCur3DSpriteEngine)->bg2 = 1;
    func_020af19c(3, 0xE);
    MI_CpuFill32(0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC), 0x40);
    player = 0;
    do {
        playerRecord = ((player + 1) * 0x8C) + ((s32)*gCurrentMap + 0x67A4);
        if (M2C_FIELD(playerRecord, u8 *, 0x1E) != 0) {
            faceSpriteId = ((PlayerUI_02173f78 *)playerRecord)->sprite;
            LoadFaceTexture(faceSpriteId, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC) + (M2C_FIELD(&gOv000FaceTileOffsets,u16 *,player*2) << 6));
            if (M2C_FIELD(playerRecord, u8 *, 0x1C) != 0) {
                paletteFlags = 8;
            } else {
                paletteFlags = 0;
            }
            LoadFacePalette(faceSpriteId, 0, 2, player, (paletteFlags & 0xFF));
        }
        player += 1;
    } while ((s32) player < 4);
    SetFileDirectory(&gOv000InfoDir);
    GetLocalizedFileName(&gOv000CgGroupNarc);
    OpenNarcArchive();
    LoadNarcFileDecompressed(GetLocalizedFileName(&gOv000MapInfoCg), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x14));
    LoadNarcFileDecompressed(GetLocalizedFileName(&gOv000UnitInfoCg), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x14) + 0x3000);
    Load3DSpritePattern(0x800, 1, GetUiColor(9), 2);
    tiles = (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles;
    LoadSpriteResource(1, 0, 0, tiles + 0x1000);
    tiles = (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles;
    LoadSpriteResource(1, 0, 2, tiles + 0x1180);
    LoadNarcFileDecompressed(GetLocalizedFileName(&gOv000InfoObjCg), (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles + 0x1400);
    LoadFileToAddress(&gOv000MiniButtonXCg, (s32)((SpriteEngine_02173f78 *)gCur3DSpriteEngine)->tiles + 0x2800);
    copyBytes = func_020a7290() << 5;
    copyDest = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0xE0;
    tiles = func_020a7278();
    MI_CpuCopy32(tiles, copyDest + 0x3000, copyBytes);
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&gOv000MapInfoTiles, 0, 0x80);
    LoadFileToSpriteBuffer(&gOv000UnitInfoPalette, 0x160, 0x20);
    LoadScenePanelPalette(0xF);
    LoadFileToSpriteBuffer(&gOv000MapInfoPalette, 0x2C0, 0x20);
    palette = M2C_FIELD(gCur3DSpriteEngine, s32 volatile *, 0x30);
    LoadSpriteResource(1,2,1,palette+0x300);
    palette = M2C_FIELD(gCur3DSpriteEngine, s32 volatile *, 0x30);
    LoadSpriteResource(1,2,2,palette+0x340);
    LoadFileToSpriteBuffer(&gOv000MiniButtonPalette, 0x360, 0x20);
    LoadFileToSpriteBuffer(&gOv000TerrainNameCl, 0x380, 0x20);
    LoadFileToSpriteBuffer(&gOv000UnitNameCl, 0x3A0, 0x20);
    LoadFileToSpriteBuffer(&gOv000WeaponNameCl, 0x3C0, 0x20);
    LoadFileToSpriteBuffer(&gOv000DangerUnitCl, 0x3E0, 0x20);
    gCur3DSpriteEngine = savedEngine;
    CreateScreenTransitions(0, 0x10, 1, 7);
}
void func_ov000_021743ec(void) {

}
