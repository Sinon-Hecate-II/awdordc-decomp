/* 4 functions from 0x022148A4 to 0x02215814 (ov004), found by ds-decomp. */
#include "common.h"
#include "gx.h"
extern u8 data_ov004_0223c5a8[],data_ov004_0223c5f4[],data_ov004_0223c5b8[],data_ov004_0223c5d0[],data_ov004_0223c5c0[],data_ov004_0223c660[],data_ov004_0223c630[],data_ov004_0223c624[],data_ov004_0223c5e8[],data_ov004_0223c5dc[],data_ov004_0223c5c8[],data_ov004_0223c5b0[],data_ov004_0223c60c[],data_ov004_0223c600[],data_ov004_0223c66c[],data_ov004_0223c654[],data_ov004_0223c648[],data_ov004_0223c618[];extern const u16 data_ov004_02218bc4[];extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
typedef struct Config149 {u16 values[6];} Config149;
void Reset3DSpriteBankState();void *CreateUnitSprite(void *);void *GetLocalizedFileName(void *);
static inline u8 Visible149(void *p){return M2C_FIELD(M2C_FIELD(p,void **,100),u8 *,18)!=0;}

extern s32 gSaveSlotSummary;extern u32 gMapProgressRecords[];
void LoadUnitGraphics(void);void *MemAlloc(s32);s32 MapData_GetCategory(s32);u32 MapData_GetGridPosition(s32);s32 func_020a8a84(s32);s32 GetMapFollowupMapId(s32,s32);
static inline void *Entry149(void *base,s32 i){if(i<0)return 0;if(i>=64)return 0;return (u8 *)base+i*32;}
static inline void *Cell149(void *base,s32 x,s32 y){if(x<0)return 0;if(y<0)return 0;if(x>=8)return 0;if(y>=8)return 0;return Entry149(base,x+y*8);}
static inline u8 Flag149(void *p,u32 bit){return (M2C_FIELD(p,u8 *,4)&bit)?1:0;}
static inline void *Find149(void *base,s32 id){s32 i;void *p;for(i=0;i<64;i++){p=(u8 *)base+i*32;if(M2C_FIELD(p,u8 *,7)==id)return p;}return 0;}
static inline void *Selected149(void *base){s32 i;u8 *cursor=base;void *p;for(i=0;i<64;i++,cursor+=32){if(i<0)p=0;else if(i>=64)p=0;else p=cursor;if(Flag149(p,2))return p;}return 0;}


/* Prepare the 3D engine for the map view: reset the geometry engine, clear the
 * 3D display control's error bits and enable it, then load the default
 * light/material registers. */
void InitMapView3DRendering(void) {
    M2C_UNK G3X_Reset();
    G3X_Reset();
    REG_DISP3DCNT = (REG_DISP3DCNT & ~DISP3DCNT_ERROR_MASK) | 8;
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, 0xB8) = 0xBFFF0000;
}

void func_ov004_02214904(void) {
    *(s32 *)0x04000540 = 1;
}

#pragma opt_strength_reduction off
void func_ov004_02214918(void *arg0){
u8 *base,*p,*q,*end,*cursor; s32 i,j,id,state,n,y,x,old;s32 saved;u32 pos;u8 selected;volatile u8 coords[4];
LoadUnitGraphics();
M2C_FIELD(arg0,u8 *,54)=0;M2C_FIELD(arg0,u16 *,68)=0;M2C_FIELD(arg0,u16 *,70)=0;M2C_FIELD(arg0,u16 *,76)=0;M2C_FIELD(arg0,u16 *,78)=0;M2C_FIELD(arg0,u16 *,72)=0;M2C_FIELD(arg0,u16 *,74)=0;M2C_FIELD(arg0,u16 *,80)=0;M2C_FIELD(arg0,u16 *,82)=0;M2C_FIELD(arg0,u8 *,57)=0;M2C_FIELD(arg0,u8 *,56)=1;M2C_FIELD(arg0,s32 *,64)=4096;
M2C_FIELD(arg0,u16 *,60)=0;M2C_FIELD(arg0,void **,92)=0;M2C_FIELD(arg0,u8 *,52)=0;
if((u32)gSaveSlotSummary>>24==0)M2C_FIELD(arg0,s32 *,64)=4096;
if((u32)gSaveSlotSummary>>24==1)M2C_FIELD(arg0,s32 *,64)=2048;
if((M2C_FIELD(&gSaveSlotSummary,u32 *,108)<<3)>>29)M2C_FIELD(arg0,u8 *,57)=1;
base=MemAlloc(2048);
if(base){end=base+2048;p=base;do{
M2C_FIELD(p,u8 *,4)=0;M2C_FIELD(p,u8 *,6)=0;M2C_FIELD(p,u16 *,0)=0;M2C_FIELD(p,u16 *,2)=0;M2C_FIELD(p,u8 *,7)=255;M2C_FIELD(p,u8 *,5)=255;M2C_FIELD(p,s32 *,8)=4096;M2C_FIELD(p,s32 *,12)=4096;
for(j=0;j<4;j++)M2C_FIELD(p+(u32)j*4,void **,16)=0;
p+=32;}while(p<end);
for(i=0;i<64;i++){M2C_FIELD(base+i*32,u16 *,0)=(i%8)*64+32;M2C_FIELD(base+i*32,u16 *,2)=(i/8)*38+19;}
}
M2C_FIELD(arg0,void **,92)=base;
for(i=0;i<275;i++){
state=MapData_GetCategory(i);pos=MapData_GetGridPosition(i);coords[0]=pos;x=coords[0];pos>>=8;coords[1]=pos;y=(u8)pos;coords[3]=y;coords[2]=x;
if(state==0||state==2){base=M2C_FIELD(arg0,void **,92);p=Cell149(base,x,y);
M2C_FIELD(p,u8 *,6)=func_020a8a84(i);M2C_FIELD(p,u8 *,7)=i-161;id=(u8)(i-161);
state=MapData_GetCategory(id+161);selected=Flag149(p,2);M2C_FIELD(p,u8 *,4)=0;
if(state==2)M2C_FIELD(p,u8 *,4)|=4;
if((M2C_FIELD(gMapProgressRecords,volatile u32 *,id*4)<<29)>>29)M2C_FIELD(p,u8 *,4)|=1;
if((M2C_FIELD(gMapProgressRecords,volatile u32 *,id*4)<<29)>>29==1)M2C_FIELD(p,u8 *,4)|=16;
if((M2C_FIELD(gMapProgressRecords,volatile u32 *,id*4)<<29)>>29==3)M2C_FIELD(p,u8 *,4)|=8;
if(selected)M2C_FIELD(p,u8 *,4)|=2;
M2C_FIELD(p,u8 *,5)=(M2C_FIELD(gMapProgressRecords,volatile u32 *,id*4)<<3)>>29;
}}
base=M2C_FIELD(arg0,void **,92);
for(i=0,cursor=base;i<64;i++,cursor+=32){if(i<0)p=0;else if(i>=64)p=0;else p=cursor;
for(j=0;j<4;j++){n=GetMapFollowupMapId(M2C_FIELD(p,u8 *,7)+161,j);if(n){q=0;for(id=0;id<64;id++){q=base+id*32;if(n==M2C_FIELD(q,u8 *,7)+161)break;}if(id==64)q=0;M2C_FIELD(p+j*4,void **,16)=q;}else M2C_FIELD(p+j*4,void **,16)=0;}}
base=M2C_FIELD(arg0,void **,92);p=Find149(base,(u16)M2C_FIELD(&gSaveSlotSummary,u32 *,4));
if(p&&p!=Selected149(base)&&Flag149(p,1)){for(i=0,cursor=base;i<64;i++,cursor+=32){if(i<0)q=0;else if(i>=64)q=0;else q=cursor;M2C_FIELD(q,u8 *,4)&=~2;}M2C_FIELD(p,u8 *,4)|=2;}
if(p){y=M2C_FIELD(p,s16 *,2);x=M2C_FIELD(p,s16 *,0);M2C_FIELD(arg0,u16 *,68)=x;M2C_FIELD(arg0,u16 *,70)=y;M2C_FIELD(arg0,u16 *,72)=x;M2C_FIELD(arg0,u16 *,74)=y;}
{volatile Config149 first=*(const Config149 *)data_ov004_02218bc4;volatile Config149 second=*(const Config149 *)(data_ov004_02218bc4+6);
GX_ReleaseBankGrants();GX_SetBankForTex(3);GX_SetBankForBG(32);GX_SetBankForOBJ(16);GX_SetBankForOBJExtPltt(64);GX_SetBankForSubBG(4);GX_SetBankForSubOBJ(8);GX_SetBankForBGExtPlttSub(128);GX_SetBankForOBJExtPlttSub(256);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;Apply3DSpriteLayout(&second);{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|16;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|32;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|64;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|128;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|256;}Reset3DSpriteBankState();M2C_FIELD(gCur3DSpriteEngine,u16 *,68)=0;ResetTextTiles();q=(u8 *)&gCur3DSpriteEngine;M2C_FIELD(q,s32 *,0)=g3DSpriteEngineSub;Apply3DSpriteLayout(&first);{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|16;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|32;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|64;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|128;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|256;}Reset3DSpriteBankState();M2C_FIELD(gCur3DSpriteEngine,u16 *,68)=0;ResetTextTiles();gCur3DSpriteEngine=g3DSpriteEngineMain;SetFileDirectory(data_ov004_0223c5a8);
LoadFileToTextureBank(data_ov004_0223c5f4,0);LoadFileToObjExtPalette(data_ov004_0223c5b8,0,512);
LoadFileToTextureBank(data_ov004_0223c5d0,0x28000);LoadFileToObjExtPalette(data_ov004_0223c5c0,512,32);
LoadFileToTextureBank(data_ov004_0223c660,0x30000);LoadFileToObjExtPalette(data_ov004_0223c630,544,32);
OpenNarcArchive(data_ov004_0223c624);LoadNarcFileToTextureBank(GetLocalizedFileName(data_ov004_0223c5e8),0x38000);LoadNarcFileToTextureBank(GetLocalizedFileName(data_ov004_0223c5dc),0x39000);CloseNarcArchive();
LoadFileToObjExtPalette(data_ov004_0223c5c8,576,160);LoadFileToObjExtPalette(data_ov004_0223c5b0,736,32);
LoadFileToTextureBank(data_ov004_0223c60c,0x3a000);LoadFileToObjExtPalette(data_ov004_0223c600,768,32);
OpenNarcArchive(data_ov004_0223c66c);LoadNarcFileDecompressed(data_ov004_0223c654,M2C_FIELD(gCur3DSpriteEngine,s32 *,24)+32);LoadNarcFileDecompressed(data_ov004_0223c648,M2C_FIELD(gCur3DSpriteEngine,s32 *,44));LoadNarcFileToSpriteBuffer(data_ov004_0223c618,480,32);CloseNarcArchive();
n=Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),1);OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine,s32 *,44),(u16)n,0xf001);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;LoadSpriteResource(0,2,71,M2C_FIELD(gCur3DSpriteEngine,s32 *,48)+608);p=CreateUnitSprite(arg0);InitUnitSprite(p,2,320,3,0);CreateUnitSpriteButtonTask(p,2);M2C_FIELD(p,u16 *,60)=2048;Set3DSpriteSlideTargetAndStart(p,224,156,224,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=GetUnitSpriteWidth(p);j=GetUnitSpriteHeight(p);SpriteCellListSetCellRect(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}Show3DSpriteSlide(p);func_020aad18(p);p=CreateUnitSprite(arg0);InitUnitSprite(p,6,336,3,0);CreateUnitSpriteButtonTask(p,256);M2C_FIELD(p,u16 *,60)=2048;Set3DSpriteSlideTargetAndStart(p,192,156,192,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=GetUnitSpriteWidth(p);j=GetUnitSpriteHeight(p);SpriteCellListSetCellRect(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}Show3DSpriteSlide(p);func_020aad18(p);p=CreateUnitSprite(arg0);InitUnitSprite(p,18,352,3,0);M2C_FIELD(p,u16 *,60)=2048;CreateUnitSpriteButtonTask(p,8);Set3DSpriteSlideTargetAndStart(p,128,156,128,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=GetUnitSpriteWidth(p);j=GetUnitSpriteHeight(p);SpriteCellListSetCellRect(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}Show3DSpriteSlide(p);func_020aad18(p);gCur3DSpriteEngine=saved;}func_ov003_021fef58(arg0);CreateFrameCallbackTask(InitMapView3DRendering,4);CreateFrameCallbackTask(func_ov004_02214904,10);if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){if(M2C_FIELD(arg0,s16 *,80)<96-Divide(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=96-Divide(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,82)<57-Divide(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=57-Divide(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,80)>160-Divide(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=160-Divide(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,82)>95-Divide(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=95-Divide(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);}if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){if(M2C_FIELD(arg0,s16 *,68)<0)M2C_FIELD(arg0,s16 *,68)=0;if(M2C_FIELD(arg0,s16 *,68)>512)M2C_FIELD(arg0,s16 *,68)=512;if(M2C_FIELD(arg0,s16 *,70)<0)M2C_FIELD(arg0,s16 *,70)=0;if(M2C_FIELD(arg0,s16 *,70)>304)M2C_FIELD(arg0,s16 *,70)=304;if(M2C_FIELD(arg0,s16 *,80)<256-Divide(M2C_FIELD(arg0,s32 *,64)*512,4096))M2C_FIELD(arg0,s16 *,80)=256-Divide(M2C_FIELD(arg0,s32 *,64)*512,4096);if(M2C_FIELD(arg0,s16 *,82)<192-Divide(M2C_FIELD(arg0,s32 *,64)*344,4096))M2C_FIELD(arg0,s16 *,82)=192-Divide(M2C_FIELD(arg0,s32 *,64)*344,4096);if(M2C_FIELD(arg0,s16 *,80)>0)M2C_FIELD(arg0,s16 *,80)=0;if(M2C_FIELD(arg0,s16 *,82)>0)M2C_FIELD(arg0,s16 *,82)=0;}
p=Selected149(M2C_FIELD(arg0,void **,92));if(p){ResetBattleMap();PreloadMapTileset(M2C_FIELD(p,u8 *,7)+161);LoadBattleMap(M2C_FIELD(p,u8 *,7)+161);Ov003_SyncMapMenuMap();}
M2C_FIELD(arg0,s16 *,76)=0;M2C_FIELD(arg0,s16 *,78)=0;n=0;state=0x10019;{volatile u32 *progress=(volatile u32 *)gMapProgressRecords;for(i=0;i<26;i++,progress++){if((*progress<<29)>>29>=3)n=i+1;}}
if(n>=10)state=0x1001a;if(n>=16)state=0x1001b;if(n>=21)state=0x1001c;PlayMusicTrack(state);}
#pragma opt_strength_reduction reset
/* Tear down a map view: reset the 3D sprite engine state, run the map's teardown
 * steps, unregister the two 3D display callbacks, remember the view's zoom in the
 * saved map-view state and free its work buffer. */
void MapView_Destroy(void *view) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineMain, gSaveSlotSummary;
    void InitMapView3DRendering(void);
    void func_ov004_02214904(void);
    s32 oldEngine = gCur3DSpriteEngine;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Reset3DSpriteBankState(view);
    gCur3DSpriteEngine = oldEngine;
    Ov003_DestroyMapMenu();
    DeleteUnitSprites();
    DeleteFrameCallbackTask(InitMapView3DRendering);
    DeleteFrameCallbackTask(func_ov004_02214904);
    DeleteScenePanelSprites();
    DeleteTextSprites();
    FadeOutMusicDefault();
    AcknowledgeMapProgress();
    if (M2C_FIELD(view, s32 *, 0x40) == 0x1000) gSaveSlotSummary &= 0xffffff;
    if (M2C_FIELD(view, s32 *, 0x40) == 0x800) gSaveSlotSummary = (gSaveSlotSummary & 0xffffff) | 0x1000000;
    if (M2C_FIELD(view, s32 *, 0x5c)) MemFree(M2C_FIELD(view, s32 *, 0x5c));
    M2C_FIELD(view, s32 *, 0x5c) = 0;
    UnloadUnitGraphics();
}

