/* 24 functions from 0x0221F4F8 to 0x02220018 (ov005), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"

void func_ov005_0221f4f8(void *arg0){
s32 EaseInterpolate(s32,s32,s32,s32,s32);void func_01ffac9c(u16,u16,u16,void *,s32);void QueueBGExtPaletteUpload(void *,s32,s32,s32,s32);void Show3DSpriteSlide(void *);
extern u16 **gCur3DSpriteEngine,**g3DSpriteEngineMain,**g3DSpriteEngineSub;extern u8 data_02101f78[];
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;u16 *volatile p5;u16 *volatile p6;u16 *volatile p7;u16 *volatile p8;u16 *volatile p9;u16 *volatile p10;
s32 saved;u8 alpha;
if(M2C_FIELD(arg0,s32 *,0x38)<=30){
alpha=(u8)EaseInterpolate(0,16,0,M2C_FIELD(arg0,s32 *,0x38),30);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p0=*p0&~1;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p1=*p1&~2;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p2=*p2&~4;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p3=*p3&~8;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p4=*p4&~16;
p5=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p5=*p5|256;
p6=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p6=*p6|512;
p7=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p7=*p7|1024;
p8=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p8=*p8|2048;
p9=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p9=*p9|4096;
p10=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18); *p10=(*p10&~0xc0)|0x40;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u8 *,0x51)=16-alpha;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u8 *,0x52)=alpha;
gCur3DSpriteEngine=saved;
func_01ffac9c(0,0x440,(u16)((0x3FF&(0x140>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u16 *,0)<<0x11)>>0x1E)))|0x6000),data_02101f78,11);
}else func_01ffac9c(0,64,(u16)((0x3FF&(0x140>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,s32 *,0),u16 *,0)<<0x11)>>0x1E)))|0x6000),data_02101f78,11);
if(M2C_FIELD(arg0,s32 *,0x38)>30 && M2C_FIELD(arg0,s32 *,0x38)<126 && M2C_FIELD(arg0,s32 *,0x38)%8==0){
{
u16 index=0,color; u8 red,green,blue; u8 *data;
do{
data=M2C_FIELD(arg0,u8 **,60);
color=(u16)(data[index]|(data[index+1]<<8));
red=color&31;green=(color>>5)&31;blue=(u8)(color>>10);
if(red<green){if(red<blue)red++;else if(green<blue)green++;else blue++;}
else {if(green<blue)green++;else blue++;}
if(red>31)red=31;if(green>31)green=31;if(blue>31)blue=31;
color=(u16)(red|(green<<5)|(blue<<10));
data[index+1]=(color&0xff00)>>8;
M2C_FIELD(arg0,u8 **,60)[index]=(u8)color;
index+=2;
}while(index<512);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
QueueBGExtPaletteUpload(M2C_FIELD(arg0,void **,60),3,0,512,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;gCur3DSpriteEngine=saved;
}
{
u16 index=0,color; u8 red,green,blue; u8 *data;
do{
data=M2C_FIELD(arg0,u8 **,64);
color=(u16)(data[index]|(data[index+1]<<8));
red=color&31;green=(color>>5)&31;blue=(u8)(color>>10);
if(red<green){if(red<blue)red++;else if(green<blue)green++;else blue++;}
else {if(green<blue)green++;else blue++;}
if(red>31)red=31;if(green>31)green=31;if(blue>31)blue=31;
color=(u16)(red|(green<<5)|(blue<<10));
data[index+1]=(color&0xff00)>>8;
M2C_FIELD(arg0,u8 **,64)[index]=(u8)color;
index+=2;
}while(index<512);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
QueueBGExtPaletteUpload(M2C_FIELD(arg0,void **,64),3,0,512,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;gCur3DSpriteEngine=saved;
}
}
if(M2C_FIELD(arg0,s32 *,0x38)==126)Show3DSpriteSlide(M2C_FIELD(arg0,void **,0x34));
}

void func_ov005_0221fa00(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220c38;
    CreateSpriteObject(&data_ov005_02220c38, arg0);
}

/* Enable five display-control bits (0x10/0x20/0x40/0x80/0x100) on each of the two screen contexts. */
void func_ov005_0221fa18(void) {
    M2C_UNK Set3DSpriteVramBanks(); M2C_UNK Apply3DSpriteDisplayConfig();
    extern u16 **gCur3DSpriteEngine; extern u16 **g3DSpriteEngineSub; extern u16 **g3DSpriteEngineMain;
    u16 *volatile ctxPtr0; u16 *volatile ctxPtr1; u16 *volatile ctxPtr2; u16 *volatile ctxPtr3; u16 *volatile ctxPtr4;
    u16 **savedContext; s32 i;
    Set3DSpriteVramBanks(); savedContext = gCur3DSpriteEngine; i = 0;
    do {
        gCur3DSpriteEngine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        Apply3DSpriteDisplayConfig(); i++;
        ctxPtr0 = *(u16 **)gCur3DSpriteEngine; *ctxPtr0 = *ctxPtr0 | 0x10;
        ctxPtr1 = *(u16 **)gCur3DSpriteEngine; *ctxPtr1 = *ctxPtr1 | 0x20;
        ctxPtr2 = *(u16 **)gCur3DSpriteEngine; *ctxPtr2 = *ctxPtr2 | 0x40;
        ctxPtr3 = *(u16 **)gCur3DSpriteEngine; *ctxPtr3 = *ctxPtr3 | 0x80;
        ctxPtr4 = *(u16 **)gCur3DSpriteEngine; *ctxPtr4 = *ctxPtr4 | 0x100;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

/* Build the list of COs the player has unlocked - a title line followed by one
 * name per unlocked CO - and render it into a new text layer. */
void DrawUnlockedCoList(M2C_UNK owner) {
    M2C_UNK StringFormat(void *, void *, s32);
    M2C_UNK StringAppend(void *, void *);
    s32 GetLocalizedText(s32);
    M2C_UNK RenderTextLayer(s32, M2C_UNK, s32, void *);
    s32 CreateTextLayer(M2C_UNK);
    extern s32 gMovementCostTable;
    extern M2C_UNK gCoState;
    extern M2C_UNK data_ov005_022212f4;
    extern M2C_UNK data_ov005_022212f8;
    char text[128];
    char entry[32];
    s32 co;
    char *army;

    StringFormat(text, &data_ov005_022212f4, GetLocalizedText(0xF000000F));
    army = (char *)&gMovementCostTable;
    co = 0;
    do {
        if (M2C_FIELD(&gCoState, s32 *, CO_STATE_UNLOCKED) & (1 << co)) {
            StringFormat(entry, &data_ov005_022212f8, GetLocalizedText(*(s32 *)(army + ARMY_DATA_NAME)));
            StringAppend(text, entry);
        }
        co += 1;
        army += ARMY_DATA_SIZE;
    } while (co < 15);
    RenderTextLayer(CreateTextLayer(owner), 2, 0x6B80, text);
}

void func_ov005_0221fbc8(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gCoState;
    extern M2C_UNK data_ov005_02220b38;
    s32 i;
    for (i = 0; i < 15; i++) {
        if (M2C_FIELD(&gCoState, s32 *, 8) & (1 << i)) {
            CreateSpriteObject(&data_ov005_02220b38, arg0);
            return;
        }
    }
}

/* Initialize the ov005 screen's graphics: assign the 3D sprite VRAM banks,
 * apply the display config and enable its five display-control bits on both the
 * main and the sub screen, then load the screen's UI graphics bank. */
void Ov005_InitScreenGraphics(void) {
    M2C_UNK Set3DSpriteVramBanks(void);
    M2C_UNK Apply3DSpriteDisplayConfig(void);
    M2C_UNK LoadUiGraphicsBank(M2C_UNK);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    u16 *volatile disp0;
    u16 *volatile disp1;
    u16 *volatile disp2;
    u16 *volatile disp3;
    u16 *volatile disp4;
    u16 **savedEngine;
    s32 engineIndex;

    Set3DSpriteVramBanks();
    savedEngine = gCur3DSpriteEngine;
    engineIndex = 0;
    do {
        gCur3DSpriteEngine = engineIndex == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        Apply3DSpriteDisplayConfig();
        engineIndex++;
        disp0 = *(u16 **) gCur3DSpriteEngine;
        *disp0 = *disp0 | DS3D_BANK_MODE0;
        disp1 = *(u16 **) gCur3DSpriteEngine;
        *disp1 = *disp1 | DS3D_BANK_MODE1;
        disp2 = *(u16 **) gCur3DSpriteEngine;
        *disp2 = *disp2 | DS3D_BANK_MODE2;
        disp3 = *(u16 **) gCur3DSpriteEngine;
        *disp3 = *disp3 | DS3D_BANK_MODE3;
        disp4 = *(u16 **) gCur3DSpriteEngine;
        *disp4 = *disp4 | DS3D_BANK_MODE4;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = savedEngine;
    LoadUiGraphicsBank(11);
}

void func_ov005_0221fd10(void) {
    M2C_UNK FreeUiGraphicsBank(M2C_UNK);
    FreeUiGraphicsBank(0xB);
}

/* Spawns the results screen's campaign hint panel for a story mission
 * (map id 0xA1..0xBA) while its per-mission high event flag is clear, and then
 * sets that flag; other maps and non-campaign battles get no panel. */
void CreateCampaignHintPanel(M2C_UNK parent) {
    M2C_UNK SetEventFlagHigh(s32, M2C_UNK);
    s32 IsEventFlagHighSet(s32);
    s32 IsCampaignBattleRules();
    extern void **gCurrentMap;
    extern M2C_UNK gCampaignHintPanelClass;
    s32 flagIndex;
    s32 isStoryMission;
    u16 mapId;

    flagIndex = M2C_FIELD(*gCurrentMap, u16 *, MAP_ID) - 0x40;
    if (IsCampaignBattleRules() == 0) {
        return;
    }
    isStoryMission = 0;
    mapId = M2C_FIELD(*gCurrentMap, u16 *, MAP_ID);
    if (((u32) mapId >= MAP_ID_STORY_FIRST) && ((u32) mapId < MAP_ID_STORY_END)) {
        isStoryMission = 1;
    }
    if (isStoryMission == 0) {
        return;
    }
    if (IsEventFlagHighSet(flagIndex) != 0) {
        return;
    }
    SetEventFlagHigh(flagIndex, 1);
    CreateSpriteObject(&gCampaignHintPanelClass, parent);
}

void *func_ov005_0221fdb0(void *arg0) {
    extern M2C_UNK data_ov005_02220f54;
    void *temp_r4;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220f54;
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_r4 != NULL) {
        HeapFreeBlock(M2C_FIELD(temp_r4, s32 *, 0x14));
        MemFree(temp_r4);
    }
    MemFree(arg0);
    return arg0;
}

void *func_ov005_0221fdf0(void *arg0) {
    extern M2C_UNK data_ov005_02220f54;
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220f54;
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_r4 != NULL) {
        HeapFreeBlock(M2C_FIELD(temp_r4, s32 *, 0x14));
        MemFree(temp_r4);
    }
    return arg0;
}

s32 func_ov005_0221fe28(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov005_0221fe3c(void) {

}

s32 func_ov005_0221fe40(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov005_0221fe54(void) {

}

#pragma opt_strength_reduction off
/* Deleting destructor of the results-screen spark: restore its vtable, delete
 * the sprite it created on each screen, then free the object. */
M2C_UNK **ResultSpark_Delete(M2C_UNK **spark) {
    M2C_UNK DeleteSpriteObject(s32);
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **gCur3DSpriteEngine;
    extern M2C_UNK gResultSparkVTable;
    u16 **savedEngine;
    u16 **engine;
    s32 screen;
    *spark = &gResultSparkVTable;
    savedEngine = gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        DeleteSpriteObject(M2C_FIELD((spark + screen), s32 *, 0x34));
        screen += 1;
    } while (screen < 2);
    gCur3DSpriteEngine = savedEngine;
    MemFree(spark);
    return spark;
}
#pragma opt_strength_reduction reset

#pragma opt_strength_reduction off
M2C_UNK **ResultSpark_Destroy(M2C_UNK **arg0) {
    M2C_UNK DeleteSpriteObject(s32);
    extern u16 **g3DSpriteEngineSub;
    extern u16 **g3DSpriteEngineMain;
    extern u16 **gCur3DSpriteEngine;
    extern M2C_UNK gResultSparkVTable;
    u16 **temp_r8;
    u16 **var_r0;
    s32 var_r9;
    *arg0 = &gResultSparkVTable;
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) var_r0 = g3DSpriteEngineMain;
        else var_r0 = g3DSpriteEngineSub;
        gCur3DSpriteEngine = var_r0;
        DeleteSpriteObject(M2C_FIELD((arg0 + var_r9), s32 *, 0x34));
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
    return arg0;
}

void *func_ov005_0221ff38(void *arg0) {
    M2C_UNK func_01ffaa6c();
    extern M2C_UNK data_ov005_02220fb8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) func_01ffaa6c();
    MemFree(arg0);
    return arg0;
}

void *func_ov005_0221ff6c(void *arg0) {
    M2C_UNK func_01ffaa6c();
    extern M2C_UNK data_ov005_02220fb8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_01ffaa6c();
    }
    return arg0;
}

void *func_ov005_0221ff98(void *arg0) {
    M2C_UNK MemFree(void *);
    extern M2C_UNK data_ov005_02220fe0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x34));
    MemFree(arg0);
    return arg0;
}

void *func_ov005_0221ffc4(void *arg0) {
    extern M2C_UNK data_ov005_02220fe0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x34));
    return arg0;
}

void func_ov005_0221ffe8(void) {

}

s32 func_ov005_0221ffec(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov005_02220000(void) {

}

s32 func_ov005_02220004(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

