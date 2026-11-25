/* 3 functions from 0x02211200 to 0x02212184 (ov006), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
extern u8 data_ov006_022183c0[],data_ov006_0221861c[],data_ov006_02218624[],data_ov006_02218634[],data_ov006_02218644[],data_ov006_02218658[],data_ov006_02218668[],data_ov006_02218670[],data_ov006_02218680[],data_ov006_02218690[],data_ov006_022186a4[];
void Clear3DSpriteLayer(s32);
void Clear3DSpriteLayerVram(s32);
void SetFileDirectory(void *);
void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);
void LoadNarcFileDecompressed(void *,s32);
void CloseNarcArchive(void);
void LoadFileSectionToSpriteBuffer(void *,s32,s32,s32);
void SetTileRectPalette(s32,s32,s32,s32);
void AddTileRectPalette(s32,s32,s32,s32);
s32 LoadSpriteResource(s32,s32,s32,s32);
void LoadScenePanelPalette(s32);
s32 GetUiColor(s32);
void Load3DSpritePattern(s32,s32,s32,s32);
void *GetLocalPlayerName(void);
void DrawGlyphString(void *,s32,s32,s32,s32,s32,s32);
void GetEarnedRecordTierTotal(void);
void *GetRecordRank(void);
void LoadRankIconGraphics(void *,s32,s32);
s32 GetFavouriteRecordGroup(void);
void *GetFavouriteGroupTextId(s32);
s32 GetFavouriteRecordIndex(void);
void *GetFavouriteRecordTextId(s32);
void *DrawLocalizedText(s32,s32,s32,void *,s32,s32);
void Show3DSpriteSlide(void *);
static inline void Bits02211388(s32 offset,u16 set,u16 clear){
u16 *volatile p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+offset);
*p=(*p&~clear)|set;
}

static inline void SetBits02211388(u16 bit){u16 *volatile p=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*p|=bit;}
static inline void ClearBits02211388(s32 offset,u16 bit){u16 *volatile p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+offset);*p&=~bit;}
void *CreateUnitSprite(void *);
void InitUnitSprite(void *,s32,s32,s32,s32);
void Set3DSpriteSlideTargetAndStart(void *,s32,s32,s32,s32);
s32 GetUnitSpriteWidth(void *);
s32 GetUnitSpriteHeight(void *);
void SpriteCellListSetCellRect(void *,s32,s32,s32,s32,s32);
void func_020aad18(void *);
void SetTextSpriteValue(void *,s32);
static inline u8 Visible02211388(void *p){return M2C_FIELD(M2C_FIELD(p,void **,0x64),u8 *,0x12)!=0;}



#pragma optimization_level 3
void func_ov006_02211200(void *arg0) {
M2C_UNK Apply3DSpriteBanks();
M2C_UNK GX_SetBankForObjExtPalette(M2C_UNK);
M2C_UNK GX_ReleaseBankGrantForBGExtPalette();
M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
M2C_UNK Set3DSpriteVramBanks();
void *Create3DSprite(M2C_UNK);
M2C_UNK LoadSpriteResource(M2C_UNK,M2C_UNK,M2C_UNK,s32);
s32 func_020aaf74(void *);
M2C_UNK CreateMainWallpaperSprite(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK CreateSubWallpaperSprite(M2C_UNK,M2C_UNK,M2C_UNK);
extern s32 g3DSpriteEngineSub;
extern s32 g3DSpriteEngineMain;
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov006_022183c8;
extern M2C_UNK data_ov006_022183d4;
s32 saved; void *p;
s32 engine, destination;
s32 resource = 6;
Set3DSpriteVramBanks();GX_ReleaseBankGrantForBGExtPalette();GX_SetBankForObjExtPalette(64);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Apply3DSpriteLayout(&data_ov006_022183c8);CreateMainWallpaperSprite(2,15,5);
gCur3DSpriteEngine=g3DSpriteEngineSub;
Apply3DSpriteLayout(&data_ov006_022183d4);CreateSubWallpaperSprite(2,15,5);
p=M2C_FIELD(arg0,void **,0x38)=Create3DSprite(9);
M2C_FIELD(p,u8 *,0x58)=resource;
engine = gCur3DSpriteEngine;
destination = M2C_FIELD(engine,s32 *,0x1c) + 0x4580;
LoadSpriteResource(2,0,resource,destination);
engine = gCur3DSpriteEngine;
destination = M2C_FIELD(engine,s32 *,0x30);
LoadSpriteResource(2,2,resource,destination + 0x320);
M2C_FIELD(p,s32 *,0x44)=func_020aaf74(p);
M2C_FIELD(p,u16 *,0x3e)=0x22c;
M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|0x640000;
M2C_FIELD(p,u16 *,0x3c)=0xc00;
gCur3DSpriteEngine=saved;Apply3DSpriteBanks();
}
/* Draws the friend-code screen's prompt text on the main screen when the player
 * has no friend code of their own yet (the code digits are shown instead once
 * one is registered). */
void ShowFriendCodePrompt(void *owner) {
    M2C_UNK RenderTextLayerMessage(void *, M2C_UNK, s32, s32);
    void *CreateTextLayer(void *);
    u64 GetOwnFriendCode(s32);
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedEngine;
    void *textLayer;

    if (GetOwnFriendCode(0) == 0) {
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        textLayer = CreateTextLayer(owner);
        RenderTextLayerMessage(textLayer, 2, 0x4640, 0x42000001);
        M2C_FIELD(textLayer, s32 *, 0x58) |= 0x1000;
        gCur3DSpriteEngine = savedEngine;
    }
}

void func_ov006_02211388(void *arg0){void **items=M2C_FIELD(arg0,void ***,0x3c);void *w; s32 y,x,a,b,saved;items[0]=CreateUnitSprite(arg0);InitUnitSprite(items[0],2,336,3,1);w=items[0];Set3DSpriteSlideTargetAndStart(w,224,160,224,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[0];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[0]);
items[1]=CreateUnitSprite(arg0);InitUnitSprite(items[1],10,352,3,0);w=items[1];Set3DSpriteSlideTargetAndStart(w,94,142,94,142);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
M2C_FIELD(w,u16 *,0x34)=94;M2C_FIELD(w,u16 *,0x36)=142;if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[1];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[1]);
items[2]=CreateUnitSprite(arg0);InitUnitSprite(items[2],11,360,3,0);w=items[2];Set3DSpriteSlideTargetAndStart(w,130,142,130,142);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
M2C_FIELD(w,u16 *,0x34)=130;M2C_FIELD(w,u16 *,0x36)=142;if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[2];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[2]);
items[3]=CreateUnitSprite(arg0);InitUnitSprite(items[3],39,368,3,0);w=items[3];Set3DSpriteSlideTargetAndStart(w,48,164,48,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[3];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[3]);
items[4]=CreateUnitSprite(arg0);InitUnitSprite(items[4],41,404,3,0);w=items[4];Set3DSpriteSlideTargetAndStart(w,104,164,104,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[4];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[4]);
items[5]=CreateUnitSprite(arg0);InitUnitSprite(items[5],40,386,3,0);w=items[5];Set3DSpriteSlideTargetAndStart(w,160,164,160,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=GetUnitSpriteWidth(w);b=GetUnitSpriteHeight(w);SpriteCellListSetCellRect(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[5];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[5]);
M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x16)=2;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x14)=8;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x17)=8;SetTextSpriteValue(M2C_FIELD(arg0,void **,64),0);
w=M2C_FIELD(arg0,void **,64);M2C_FIELD(w,u8 *,0x20)=(M2C_FIELD(w,u8 *,0x20)&~0xe0)|64;
w=M2C_FIELD(arg0,void **,64);M2C_FIELD(w,u8 *,0x28)=(M2C_FIELD(w,u8 *,0x28)&~0xe0)|64;
M2C_FIELD(M2C_FIELD(arg0,void **,64),u16 *,0x12)=422;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x21)=22;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x16)=4;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x14)=16;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x17)=16;SetTextSpriteValue(M2C_FIELD(arg0,void **,68),0);
w=M2C_FIELD(arg0,void **,68);M2C_FIELD(w,u8 *,0x20)=(M2C_FIELD(w,u8 *,0x20)&~0xe0)|0;
w=M2C_FIELD(arg0,void **,68);M2C_FIELD(w,u8 *,0x28)=(M2C_FIELD(w,u8 *,0x28)&~0xe0)|0;
M2C_FIELD(M2C_FIELD(arg0,void **,68),u16 *,0x12)=480;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x21)=23;M2C_FIELD(M2C_FIELD(arg0,void **,68),void **,0x24)=data_ov006_022183c0;
w=M2C_FIELD(arg0,void **,72);M2C_FIELD(w,u16 *,14)=0;M2C_FIELD(w,u16 *,16)=0;M2C_FIELD(w,u16 *,12)=12;M2C_FIELD(w,u16 *,2)=M2C_FIELD(w,u16 *,4);
saved=gCur3DSpriteEngine;w=(void *)g3DSpriteEngineMain;gCur3DSpriteEngine=(s32)w;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|16;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|32;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|64;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg&~192;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;
Clear3DSpriteLayer(0);
SetFileDirectory(data_ov006_0221861c);
OpenNarcArchive(GetLocalizedFileName(data_ov006_02218624));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218634),M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218644),M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
CloseNarcArchive();
LoadFileSectionToSpriteBuffer(data_ov006_02218658,160,0,32);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,32),32,32,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;Clear3DSpriteLayer(3);
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(3,0,0,M2C_FIELD(w,s32 *,24));
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(3,2,0,M2C_FIELD(w,s32 *,48)+224);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,44),32,32,7);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;Clear3DSpriteLayer(1);Clear3DSpriteLayerVram(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;LoadScenePanelPalette(6);
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(1,0,1,M2C_FIELD(w,s32 *,28)+0x34c0);
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(1,2,0,M2C_FIELD(w,s32 *,48)+0x2c0);
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(1,0,5,M2C_FIELD(w,s32 *,28)+0x37c0);
Load3DSpritePattern(0x3e40,1,GetUiColor(9),2);
Load3DSpritePattern(0x4240,1,GetUiColor(12),2);w=(void *)&gCur3DSpriteEngine;M2C_FIELD(w,s32 *,0)=g3DSpriteEngineSub;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|16;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|32;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|64;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg&~128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg&~192;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;
Clear3DSpriteLayer(0);
SetFileDirectory(data_ov006_02218668);
OpenNarcArchive(GetLocalizedFileName(data_ov006_02218670));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218680),M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218690),M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
CloseNarcArchive();
LoadFileSectionToSpriteBuffer(data_ov006_022186a4,160,0,64);
AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,32),32,32,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;Clear3DSpriteLayer(1);
Clear3DSpriteLayerVram(1);LoadScenePanelPalette(7);
a=2;w=(void *)M2C_FIELD(&gCur3DSpriteEngine,volatile s32 *,0);
DrawGlyphString(GetLocalPlayerName(),M2C_FIELD(w,s32 *,16),M2C_FIELD(w,s32 *,36),7,6,4,a);
a+=48;GetEarnedRecordTierTotal();LoadRankIconGraphics(GetRecordRank(),0x4280,8);
if(GetFavouriteRecordGroup()!=-2 && GetFavouriteRecordGroup()!=-1){
w=DrawLocalizedText(12,7,1,GetFavouriteGroupTextId(GetFavouriteRecordGroup()),0x7000,(u16)a);
a+=M2C_FIELD(w,u16 *,76)-M2C_FIELD(w,u16 *,78)+2;
x=(s16)(M2C_FIELD(w,u8 *,74)+2);
DrawLocalizedText(x,7,1,GetFavouriteRecordTextId(GetFavouriteRecordIndex()),0x7000,(u16)a);
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(1,0,5,M2C_FIELD(w,s32 *,28)+0x3c00);
w=(void *)gCur3DSpriteEngine;LoadSpriteResource(1,2,0,M2C_FIELD(w,s32 *,48)+0x2e0);
gCur3DSpriteEngine=saved;items=M2C_FIELD(arg0,void ***,60);
Show3DSpriteSlide(items[0]);
w=items[1];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;w=items[2];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;Show3DSpriteSlide(items[3]);Show3DSpriteSlide(items[4]);Show3DSpriteSlide(items[5]);}

