/* 17 functions from 0x021707D8 to 0x02171774 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "sound.h"


#pragma opt_strength_reduction off
void func_ov000_021707d8(void) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern void **gCurrentMap;
extern u8 gMapConfig[];
s32 IsCampaignBattleRules(void);s32 func_020a8a84(u16);void *GetCurrentMapName(void);
void DrawTilemapNumber(s16,s16,void *,s32,s32,s32);
void DrawTextToTilemap(s16,s16,void *,void *,s32,s32);
s32 GetLanguage(void);s32 GetDigitCount(s32);s32 GetCurrentMapPlayerCount(void);
s32 CountPlayerUnitsBuilt(s32);s32 CountPlayerUnitsLost(s32);
void *func_020a8bc0(void);void *func_020a8bcc(void);
volatile s32 e;
void *old;
void *dst;
s32 c,d;u8 *dummy; s32 y,color,a,b,x;
u8 *p,*map;
old=gCur3DSpriteEngine;dst=M2C_FIELD(old,void **,0x24);
gCur3DSpriteEngine=g3DSpriteEngineMain;
if(IsCampaignBattleRules()){
DrawTilemapNumber(3,1,dst,func_020a8a84(M2C_FIELD(*gCurrentMap,u16 *,0x5142)),0,0);
DrawTextToTilemap(5,1,dst,GetCurrentMapName(),0,0);
}else DrawTextToTilemap(2,1,dst,GetCurrentMapName(),0,0);
if(!GetLanguage()) x=26;
else x=30-(3-GetDigitCount(M2C_FIELD(*gCurrentMap,u16 *,0x52a2)));
DrawTilemapNumber((s16)x,1,dst,M2C_FIELD(*gCurrentMap,u16 *,0x52a2),0,0);
{s32 i=0;
if(GetCurrentMapPlayerCount()>0){y=6;do{
x=i+1;p=(u8 *)*gCurrentMap+0x67a4+x*140;
if(p[0x1e] && !p[0x19]){
a=CountPlayerUnitsBuilt(x);if(a>999)a=999;
b=CountPlayerUnitsLost(x);if(b>999)b=999;
x=M2C_FIELD(p,s32 *,0);c=p[0x18];if(c>999)c=999;d=M2C_FIELD(p,s32 *,8);if(d>999999)d=999999;e=x;if(x>999999)e=999999;
color=p[0x1c]?3:0;
DrawTilemapNumber(8,(s16)y,dst,a,0,color);
DrawTilemapNumber(12,(s16)y,dst,b,0,color);
if(p[0x1c]){
DrawTextToTilemap(16,(s16)y,dst,func_020a8bc0(),0,color);
DrawTextToTilemap(23,(s16)y,dst,func_020a8bc0(),0,color);
DrawTextToTilemap(30,(s16)y,dst,func_020a8bc0(),0,color);
}else{
map=*gCurrentMap;
if((!map[0x5156] && map[0x5158]!=2) || p[0x26]==map[0x67ca+M2C_FIELD(map,u16 *,0x52a4)*140]){
DrawTilemapNumber(16,(s16)y,dst,c,0,color);
DrawTilemapNumber(23,(s16)y,dst,d,0,color);
DrawTilemapNumber(30,(s16)y,dst,e,0,color);
}else{
if(gMapConfig[2]){
DrawTilemapNumber(16,(s16)y,dst,c,0,color);
DrawTilemapNumber(23,(s16)y,dst,d,0,color);
}else{
DrawTextToTilemap(16,(s16)y,dst,func_020a8bcc(),0,color);
DrawTextToTilemap(23,(s16)y,dst,func_020a8bcc(),0,color);
}
DrawTextToTilemap(30,(s16)y,dst,func_020a8bcc(),0,color);
}}
y+=3;
}i++;}while(i<GetCurrentMapPlayerCount());}}
map=*gCurrentMap;
if((!map[0x5156] && map[0x5158]!=2)||gMapConfig[2]){
a=map[0x67bc];if(a>999)a=999;
DrawTilemapNumber(16,17,dst,a,0,0);
}else DrawTextToTilemap(16,17,dst,func_020a8bcc(),0,0);
gCur3DSpriteEngine=old;
}
/* Situation screen's cancel (B) action: play the menu back sound and resume
 * the situation panel object's animation. */
void ResumeSituationScreenAnimation(void) {
    M2C_UNK Sprite_ResumeAnimation(s32);
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gSituationScreenClass;
    s32 panel;
    panel = FindObjectByClass(&gSituationScreenClass);
    PlaySoundEffect(SOUND_MENU_BACK);
    Sprite_ResumeAnimation(panel);
}

#pragma opt_strength_reduction off
/* Loads the map "situation" screen: opens the situation archive, uploads the
 * character, sprite and palette data, gives every player its portrait tile and
 * army colour palette, then refreshes the situation panel. */
void LoadSituationScreen(void *object){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;
extern M2C_UNK sSituationDir,sSituationNarcName,sSituationCgName,sSituationScName,sSituationClName;
void ResetTextTiles(s32);M2C_UNK Clear3DSpriteLayer(M2C_UNK);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void AddTileRectPalette(void *,s32,s32,s32);void CloseNarcArchive(void);void LoadFileToSpriteBuffer(void *,s32,s32);void CreateMenuUnitSprite(void *);s32 GetCurrentMapPlayerCount(void);void *GetArmyStateTiles(s32);void *GetArmyIconPalette(s32);void MI_CpuCopy32(void *,void *,s32);void CopyToObjPaletteShadow(void *,s32,s32);void DimPalette(void *);void func_ov000_021707d8(void);
void *oldEngine=gCur3DSpriteEngine;s32 i;void *dest;u8 *player;s32 tile,paletteOff;
gCur3DSpriteEngine=g3DSpriteEngineMain;ResetTextTiles(0);Clear3DSpriteLayer(1);Clear3DSpriteLayer(2);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=1;
SetFileDirectory(&sSituationDir);OpenNarcArchive(GetLocalizedFileName(&sSituationNarcName));
LoadNarcFileDecompressed(GetLocalizedFileName(&sSituationCgName),M2C_FIELD(g3DSpriteEngineMain,void **,0x14));
LoadNarcFileDecompressed(GetLocalizedFileName(&sSituationScName),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),32,24,6);CloseNarcArchive();LoadFileToSpriteBuffer(&sSituationClName,192,32);CreateMenuUnitSprite(object);
i=0;if(GetCurrentMapPlayerCount()>0){tile=0x35c;do{
player=(u8 *)*gCurrentMap+MAP_PLAYER_STATES+(i+1)*MAP_PLAYER_STRIDE;dest=(u8 *)M2C_FIELD(g3DSpriteEngineMain,void * volatile *,0x1c)+(tile<<5);
MI_CpuCopy32(GetArmyStateTiles(player[PLAYER_REC_ARMY_STATE]),dest,128);
paletteOff=(i+27)<<5;CopyToObjPaletteShadow(GetArmyIconPalette(player[PLAYER_REC_ARMY_INDEX]),paletteOff,32);
if(player[0x1c])DimPalette((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(paletteOff&~1));
i++;tile+=4;}while(i<GetCurrentMapPlayerCount());}
func_ov000_021707d8();M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;gCur3DSpriteEngine=oldEngine;
}
#pragma opt_strength_reduction reset
void func_ov000_02170ea4(void) {
    extern u16 *gKeyState;
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    extern void **gCurrentMap;
    extern M2C_UNK gSpriteDesc16x16;
    s32 GetCurrentMapPlayerCount(void);
    void AddSprite(s32,s32,u16,void *,s32);
    void *old;
    s32 i, offset, tile, x;
    u8 *p;

    if (*gKeyState & 2) {
        ResumeSituationScreenAnimation();
        return;
    }
    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    i = 0;
    if (GetCurrentMapPlayerCount() > 0) {
        offset = 0;
        tile = 0x35c;
        x = 46;
        for (;;) {
        p = (u8 *)*gCurrentMap + offset + 0x67a4;
        if (p[0xaa] && !p[0xa5]) {
            u32 palette = ((i + 11) & 15) << 12;
            u32 format = (u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 17) >> 30;
            void *desc = &gSpriteDesc16x16;
            u8 y = x;
            AddSprite(16, y, (u16)(palette | (1023 & (tile >> format))), desc, 0);
        }
        ++i;
        x += 24;
        offset += 140;
        tile += 4;
            if (i >= GetCurrentMapPlayerCount()) break;
        }
    }
    gCur3DSpriteEngine = old;
}
#pragma opt_common_subs reset
/* Leave the map-situation screen: on the main engine clear the situation's two
 * overlay layers and mark them dirty, redraw the map view, then restore the
 * engine that was active. */
void UnloadSituationScreen(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    RefreshMapView();
    gCur3DSpriteEngine = savedEngine;
}

void func_ov000_02171028(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gSituationScreenClass;
    CreateSpriteFromClass(&gSituationScreenClass, 7);
}

#pragma optimization_level 2
void func_ov000_02171040(void *p){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;
extern M2C_UNK data_ov000_021b8c58,data_ov000_021b8c60,data_ov000_021b8c70,data_ov000_021b8c7c,data_ov000_021b8c88;
s32 MapData_GetWinRuleTextId(s32);void DrawLocalizedText(s32,s32,s32,s32,u16,u16);
void SetFileDirectory(void *);void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void LoadNarcFileToSpriteBuffer(void *,s32,s32);
void CloseNarcArchive(void);void LoadScenePanelPalette(s32);
s32 Get3DSpriteLayerSize(u8,s32);void OffsetTileIndices(void *,u16,s32);void CreateMenuUnitSprite(void *);
void *old=gCur3DSpriteEngine;s32 n;u16 v;
gCur3DSpriteEngine=g3DSpriteEngineMain;
n=MapData_GetWinRuleTextId(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
LoadScenePanelPalette(0);DrawLocalizedText(5,8,1,n,0,64);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
SetFileDirectory(&data_ov000_021b8c58);
OpenNarcArchive(GetLocalizedFileName(&data_ov000_021b8c60));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8c70),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8c7c),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&data_ov000_021b8c88),0x60,0x20);
CloseNarcArchive();
v=Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2);
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),v,0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
CreateMenuUnitSprite(p);gCur3DSpriteEngine=old;
}
#pragma optimization_level 4
/* Tear down the win-rule window: clear its two overlay layers on the current
 * engine, mark both dirty so the engine uploads them empty, and play the close
 * sound. */
void UnloadWinRuleWindow(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    PlaySoundEffect(SOUND_MENU_BACK);
}

/* Win-rule window input: while the B button is held, resume the window's
 * scrolling text animation. */
void ResumeWinRuleWindowAnimation(void *window) {
    M2C_UNK Sprite_ResumeAnimation(s32);
    extern u16 *gKeyState;

    if (!(*gKeyState & KEY_B)) return;
    Sprite_ResumeAnimation((s32)window);
}

void func_ov000_02171214(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gWinRuleWindowClass;
    CreateSpriteFromClass(&gWinRuleWindowClass, 7);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction on
s32 func_ov000_0217122c(s32 arg0) {
extern void **gCurrentMap;extern void *gCur3DSpriteEngine;extern M2C_UNK data_ov000_021b8cdc;
s32 IsPlayerPresent(s32);s32 IsPlayerCpu(s32);s32 IsPlayerActive(s32);
void *GetLocalizedFileName(void *);void LoadNarcFileDecompressed(void *,void *);
s32 GetPlayerRank(s32);void LoadRankIconGraphics(s32,s32,s32);
void *GetArmyStateTiles(s32);void *GetArmyIconPalette(s32);
void MI_CpuCopy32(void *,void *,s32);void CopyToObjPaletteShadow(void *,s32,s32);void DimPalette(void *);
s32 GetActivePlayerRecord(s32);void DrawGlyphString(s32,void *,void *,s32,s32,u16,s32);
s32 GetPlayerFavouriteGroup(s32);s32 GetPlayerFavouriteRecord(s32);s32 GetFavouriteGroupTextId(s32);s32 GetFavouriteRecordTextId(s32);s32 GetLocalizedText(s32);
void DrawTextLineCore(s32,s16,s32,s32,s32,u16,u16);
s32 i=arg0-1,off;u8 *p=(u8 *)*gCurrentMap+0x67a4+arg0*140;
s32 n=i*5,a=p[0x27],b=p[0x1d],t,color;void *dst,*engine;
if(!IsPlayerPresent(arg0))return 0;
if(IsPlayerCpu(arg0))return 0;
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8cdc),(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x28)+(n<<6));
t=i*12;off=t+0x35c;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
LoadRankIconGraphics(GetPlayerRank(i),off<<5,11);
dst=(u8 *)M2C_FIELD(gCur3DSpriteEngine,void * volatile *,0x1c)+((t+0x364)<<5);
MI_CpuCopy32(GetArmyStateTiles(a),dst,128);
off=(i+28)<<5;
CopyToObjPaletteShadow(GetArmyIconPalette(b),off,32);
if(!IsPlayerActive(arg0))DimPalette((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(off&~1));
color=IsPlayerActive(arg0)?0:3;off=(i<<7)+16;engine=*(void * volatile *)&gCur3DSpriteEngine;
DrawGlyphString(GetActivePlayerRecord(i),M2C_FIELD(engine,void **,0x10),M2C_FIELD(engine,void **,0x24),0,9,(u16)(n+1),off);
DrawTextLineCore(13,(s16)(n+3),1,GetLocalizedText(GetFavouriteGroupTextId(GetPlayerFavouriteGroup(i))),0,(u16)color,(u16)(off+80));
DrawTextLineCore(19,(s16)(n+3),1,GetLocalizedText(GetFavouriteRecordTextId(GetPlayerFavouriteRecord(i))),0,(u16)color,(u16)(off+96));
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;return 1;
}
#pragma pop
/* Loads the player-name entry screen: opens the username archive, uploads its
   graphics and sprite layer, and sets the screen's per-player "needs a name"
   flags (screen[0x34+i]) from func_ov000_0217122c. */
void LoadUsernameScreen(u8 *screen){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK sUsernameDir,sUsernameNarcName,sUsernameCgName,sUsernameClName;
void AcquireUsernameFont(void);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void LoadNarcFileToSpriteBuffer(void *,s32,s32);
s32 func_ov000_0217122c(s32);void CloseNarcArchive(void);void LoadScenePanelPalette(s32);
s32 Get3DSpriteLayerSize(u8,s32);void OffsetTileIndices(void *,u16,s32);void CreateMenuUnitSprite(void *);
void *oldEngine=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=g3DSpriteEngineMain;
AcquireUsernameFont();SetFileDirectory(&sUsernameDir);
OpenNarcArchive(GetLocalizedFileName(&sUsernameNarcName));
LoadNarcFileDecompressed(GetLocalizedFileName(&sUsernameCgName),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&sUsernameClName),0x60,0x20);
for(i=1;i<5;i++){if(func_ov000_0217122c(i))screen[0x34+i]=1;else screen[0x34+i]=0;}
CloseNarcArchive();LoadScenePanelPalette(0);
OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),(u16)Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2),0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=3;
CreateMenuUnitSprite(screen);gCur3DSpriteEngine=oldEngine;
}

/* Draw the username entry rows set up by LoadUsernameScreen: for each player slot
 * flagged in screen[0x34+slot], add the 32x16 name-field sprite and the 16x16
 * player icon beside it. */
void DrawUsernameRows(u8 *screen){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK gSpriteDesc16x16;
void AddSprite32x16(s32,u16,u16,s32);
void AddSprite(s32,s32,u16,void *,s32);
void *oldEngine=gCur3DSpriteEngine;s32 slot;
gCur3DSpriteEngine=g3DSpriteEngineMain;
for(slot=1;slot<5;slot++){
if(screen[0x34+slot]){
s32 row=slot-1;
AddSprite32x16(0x42,(u16)((row*40+21)&511),(u16)(((row*12+0x35c)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0xb000),11);
AddSprite(8,(row*40+14)&255,(u16)(((row*12+0x364)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|(u16)((row+12)<<12)),&gSpriteDesc16x16,11);
}
}
gCur3DSpriteEngine=oldEngine;
}

/* Unload the player-name entry screen: drop the two layers it drew (1 and 2),
 * mark them dirty, reset the second layer's corner, release the screen's shared
 * resource and play the close sound. */
void UnloadUsernameScreen(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK ReleaseUsernameFont();
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, DS3D_CORNER_X(1)) = 0;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, DS3D_CORNER_Y(1)) = 0;
    ReleaseUsernameFont();
    PlaySoundEffect(SOUND_MENU_BACK);
}

/* Username screen input: while the B button is held, resume the screen object's
 * animation. */
void ResumeUsernameScreenAnimation(void *screen) {
    M2C_UNK Sprite_ResumeAnimation(s32);
    extern u16 *gKeyState;

    if (!(*gKeyState & KEY_B)) return;
    Sprite_ResumeAnimation((s32)screen);
}

void func_ov000_02171750(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c94;
    CreateSpriteFromClass(&data_ov000_021b8c94, 7);
}

s32 func_ov000_02171768(s32 arg0) {
    return (arg0 * 0x10) + 0x430;
}
