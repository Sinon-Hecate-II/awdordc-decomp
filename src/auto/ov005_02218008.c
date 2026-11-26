/* 11 functions from 0x02218008 to 0x02218FD0 (ov005), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov005_menu.h"
void Ov005RefreshEntryLabel(void);
void Ov005RefreshEntryFace(void);
void Ov005RefreshNameGraphic(void);
void CreateSubWallpaperSprite(int,int,int);
void ResetSpriteSlots(void);
typedef struct Setup180 {u16 h[6];} Setup180;
typedef struct Pos180 {s16 h[4];} Pos180;
extern u16 data_ov005_02220058[];
extern void *gOv005MenuState, *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
void LoadUiGraphicsBank();
void GX_ReleaseBankGrants();
void GX_SetBankForBG();
void GX_SetBankForOBJ();
void GX_SetBankForSubBG();
void GX_SetBankForSubOBJ();
void GX_SetBankForBGExtPalette();
void GX_SetBankForObjExtPalette();
void GX_SetBankForBGExtPlttSub();
void GX_SetBankForOBJExtPlttSub();
void Apply3DSpriteLayout();
void OpenNarcArchive();
void LoadNarcFileDecompressed();
void LoadNarcFileDecompressedAndDrawTilemapBlock();
void CloseNarcArchive();
void LoadFileToSpriteBuffer();
void SetFileDirectory();
void LoadGraphicsBlock();
M2C_UNK HeapFreeBlock();
void LoadFaceTextureAndPaletteAt();
void CreateMenuTextSprite();
void Load3DSpritePattern();
void CreateMainWallpaperSprite();
void LoadSpriteResource(s32,s32,u8,void *);
void SetTextById();
void Show3DSpriteSlide();
void SetShogunInfoFileDirectory();
void SetOv005FileDirectory(void);
void *HeapAllocBlock(int);
void *GetLocalizedFileName(void *);
void *LoadFileToBuffer(void *,int);
int GetUiColor(int);
void *Create3DSprite(void *);
u32 func_020aaf74(void *);
void *CreateScrollingTextSprite(void *);
void *func_020e304c(void);
extern u8 data_ov005_02220908[];
extern u8 data_ov005_0222091c[];
extern u8 data_ov005_0222092c[];
extern u8 data_ov005_02220944[];
extern u8 data_ov005_02220958[];
extern u8 data_ov005_02220960[];
extern u8 data_ov005_02220978[];
extern u8 data_ov005_0222098c[];
extern u8 data_ov005_022209a0[];
extern u8 data_ov005_022209b0[];
extern u8 data_ov005_022209c4[];


#pragma opt_strength_reduction off
void func_ov005_02218008(void *arg0) {
Setup180 first={{0,0x11,0x4201,0xa24,0x1045,0x1856}};
Setup180 second={{0,0x11,0x6201,0x821,0x1034,0x1846}};
void *saved; void *p; void *sprite; s32 i,j,k,m;
u16 * volatile v0;
u16 * volatile v1;
u16 * volatile v2;
u16 * volatile v3;
u16 * volatile v4;
u16 * volatile v5;
u16 * volatile v6;
u16 * volatile v7;
u16 * volatile v8;
u16 * volatile v9;
u16 * volatile v10;
u16 * volatile v11;
LoadUiGraphicsBank(10); gOv005MenuState=HeapAllocBlock(60);GX_ReleaseBankGrants();
GX_SetBankForBG(1);GX_SetBankForOBJ(2);GX_SetBankForSubBG(4);GX_SetBankForSubOBJ(8);GX_SetBankForBGExtPalette(16);GX_SetBankForObjExtPalette(32);GX_SetBankForBGExtPlttSub(128);GX_SetBankForOBJExtPlttSub(256);
M2C_FIELD(gOv005MenuState,u8 *,0)=0; M2C_FIELD(gOv005MenuState,s16 *,4)=0; M2C_FIELD(gOv005MenuState,s16 *,2)=M2C_FIELD(gOv005MenuState,s16 *,4);M2C_FIELD(gOv005MenuState,s16 *,14)=0;M2C_FIELD(gOv005MenuState,s16 *,12)=M2C_FIELD(gOv005MenuState,s16 *,14);M2C_FIELD(gOv005MenuState,s16 *,18)=0;M2C_FIELD(gOv005MenuState,s16 *,20)=0;M2C_FIELD(gOv005MenuState,s16 *,16)=M2C_FIELD(gOv005MenuState,s16 *,14)+1;M2C_FIELD(gOv005MenuState,s16 *,6)=0;M2C_FIELD(gOv005MenuState,s16 *,22)=12;M2C_FIELD(gOv005MenuState,s16 *,24)=0;M2C_FIELD(gOv005MenuState,s16 *,8)=0;M2C_FIELD(gOv005MenuState,s16 *,10)=256;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;Apply3DSpriteLayout(&first);
v0=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v0 = *v0 &~ 16;
v1=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v1 = *v1 &~ 32;
v2=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v2 = *v2 | 64;
v3=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v3 = *v3 | 128;
v4=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v4 = *v4 | 256;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|3;
v5=(u16*)((char*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18); *v5 = *v5 &~192;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,81)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,82)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,83)=0;
SetOv005FileDirectory();
OpenNarcArchive(GetLocalizedFileName(data_ov005_02220908));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_0222091c),M2C_FIELD(g3DSpriteEngineMain,void * *,20));
LoadNarcFileDecompressedAndDrawTilemapBlock(GetLocalizedFileName(data_ov005_0222092c),M2C_FIELD(g3DSpriteEngineMain,void * *,40),0,0);CloseNarcArchive();
LoadFileToSpriteBuffer(data_ov005_02220944,0,32);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;SetFileDirectory(data_ov005_02220958);
p=LoadFileToBuffer(data_ov005_02220960,1);LoadGraphicsBlock((char*)p+0x460,(char*)M2C_FIELD(g3DSpriteEngineMain,void * *,28)+0x8180);HeapFreeBlock(p);
LoadFileToSpriteBuffer(data_ov005_02220978,0x2e0,32);
for(i=0,j=0;i<12;i++,j+=12)LoadFaceTextureAndPaletteAt((s16)(i+1),0,0x9380+(j<<6),(u16)i);
SetOv005FileDirectory();
CreateMenuTextSprite((char*)gOv005MenuState+36,192,160,1,0x35c,3,1,arg0,1);
CreateMenuTextSprite((char*)gOv005MenuState+40,224,160,2,0x36c,3,2,arg0,0);
{Pos180 pos={{43,44,45,46}};
for(i=0,j=0x37c,k=14,m=0;i<4;i++,j+=36,k+=60,m+=4)CreateMenuTextSprite((char*)gOv005MenuState+44+m,M2C_FIELD(gOv005MenuState,s16 *,10)+k,90,pos.h[i]&255,j,3,-1,arg0,0);
}
Load3DSpritePattern(4096,1,GetUiColor(9),2);CreateMainWallpaperSprite(3,15,6);
gCur3DSpriteEngine=g3DSpriteEngineSub;Apply3DSpriteLayout(&second);
v6=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v6 = *v6 | 16;
v7=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v7 = *v7 &~ 32;
v8=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v8 = *v8 | 64;
v9=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v9 = *v9 | 128;
v10=(u16*)M2C_FIELD(gCur3DSpriteEngine,void **,0); *v10 = *v10 | 256;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|3;
v11=(u16*)((char*)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18); *v11 = *v11 &~192;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,81)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,82)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,83)=0;
SetOv005FileDirectory();
OpenNarcArchive(GetLocalizedFileName(data_ov005_0222098c));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_022209a0),M2C_FIELD(g3DSpriteEngineSub,void * *,20));
LoadNarcFileDecompressedAndDrawTilemapBlock(GetLocalizedFileName(data_ov005_022209b0),M2C_FIELD(g3DSpriteEngineSub,void * *,40),0,0);CloseNarcArchive();
LoadFileToSpriteBuffer(data_ov005_022209c4,0,32);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;
M2C_FIELD(gOv005MenuState,void * *,32)=Create3DSprite(arg0);sprite=M2C_FIELD(gOv005MenuState,void * *,32);M2C_FIELD(sprite,u8 *,88)=8;
LoadSpriteResource(2,0,8,(char*)M2C_FIELD(gCur3DSpriteEngine,void * *,28)+0x3000);
LoadSpriteResource(2,2,8,(char*)M2C_FIELD(gCur3DSpriteEngine,void * *,48)+0x2e0);
M2C_FIELD(sprite,u32 *,68)=func_020aaf74(sprite);M2C_FIELD(sprite,u16 *,62)=0x180;M2C_FIELD(sprite,u32 *,64)=(M2C_FIELD(sprite,u32 *,64)&~0x3fc0000)|0x5c0000;M2C_FIELD(sprite,u16 *,60)=0xc00;
M2C_FIELD(gOv005MenuState,void * *,28)=CreateScrollingTextSprite(arg0);M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u16 *,62)=0x200;M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u32 *,64)=(M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u32 *,64)&~0x3fc0000)|0x200000;
SetTextById(M2C_FIELD(gOv005MenuState,void * *,28),0x40000000);Show3DSpriteSlide(M2C_FIELD(gOv005MenuState,void * *,28));SetShogunInfoFileDirectory();LoadFileToSpriteBuffer(func_020e304c(),0x2c0,32);SetOv005FileDirectory();
Ov005RefreshEntryFace();Ov005RefreshNameGraphic();CreateSubWallpaperSprite(3,15,6);gCur3DSpriteEngine=saved;ResetSpriteSlots();Ov005RefreshEntryLabel();M2C_FIELD(gOv005MenuState,s16 *,24)=0;
}
#pragma opt_strength_reduction reset
/* Recreate the twelve page-0 CO grid slot sprites and select the slot of the
 * current list entry. */
void Ov005AddCoGridAndSelectEntry(void) {
    M2C_UNK SelectSpriteSlot(s16);
    M2C_UNK Ov005AddCoGridSprites();
    extern void *gOv005MenuState;
    Ov005AddCoGridSprites();
    SelectSpriteSlot(M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_INDEX));
}

/* Apply the menu page/index changes made since the last frame. */
void Ov005SyncMenuState(M2C_UNK arg0) {
    extern void *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern u8 sSyogunColorArchive[],sSyogunColorDown00[],sSyogunColorDown01[];
    void LoadSpriteResource(s32,s32,u8,void *);
    void *GetLocalizedFileName(void *);
    void OpenNarcArchive(void *);
    void LoadNarcFileDecompressedAndDrawTilemapBlock(void *,void *,s32,s32);
    void CloseNarcArchive(void);
    void SetOv005FileDirectory(void);
    void Ov005RefreshEntryLabel(void);
    void *savedEngine;
    void *mainEngine;
    s32 pageIsList;
    if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_PAGE)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)){
        if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)==OV005_PAGE_LIST) pageIsList=1; else pageIsList=0;
        savedEngine=gCur3DSpriteEngine;
        mainEngine=g3DSpriteEngineMain;
        gCur3DSpriteEngine=mainEngine;
        LoadSpriteResource(0,0,(u8)(s16)pageIsList,(u8 *)M2C_FIELD(mainEngine,void **,0x1c)+0x6b80);
        M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_COLOR_OBJ),u16 *,0x3e)=0x35c;
        gCur3DSpriteEngine=savedEngine;
    }
    if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_PAGE)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)){
        SetOv005FileDirectory();
        savedEngine=gCur3DSpriteEngine;
        gCur3DSpriteEngine=g3DSpriteEngineMain;
        OpenNarcArchive(GetLocalizedFileName(sSyogunColorArchive));
        if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)==OV005_PAGE_LIST) LoadNarcFileDecompressedAndDrawTilemapBlock(GetLocalizedFileName(sSyogunColorDown00),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
        else LoadNarcFileDecompressedAndDrawTilemapBlock(GetLocalizedFileName(sSyogunColorDown01),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
        CloseNarcArchive();
        M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
        gCur3DSpriteEngine=savedEngine;
    }
    if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_INDEX)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX)) Ov005RefreshEntryLabel();
    if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)>0) M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)--;
    M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_PAGE)=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE);
    M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_INDEX)=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX);
}

/* Input handler of the menu's main list page.  It eases the 15-frame slide timer
 * into the two page-transition offsets, adds the detail sprites on the last
 * slide frame, and on B leaves the menu while A opens the highlighted entry's
 * detail page. */
void Ov005ListMenuInput(M2C_UNK arg0){
u32 _fflt(s32);u32 _fmul(u32,u32);u32 _fdiv(u32,u32);u32 _fadd(u32,u32);s32 _ffix(u32);
M2C_UNK Ov005AddCoGridSprites();M2C_UNK SelectSpriteSlot(s16);void Sprite_ResumeAnimation(s32);M2C_UNK HideAllSpriteSlots();void PlaySoundEffect(s32);s32 IsCoUnlocked(s16);void SetTextById(void *,u32);s16 GetCoSavedMode(s16);void Ov005SetDetailSelection(s16);
extern void *gOv005MenuState;extern u16 *gKeyState;
void *menu=gOv005MenuState;s32 animTimer=M2C_FIELD(menu,s16 *,OV005_MENU_ANIM);u32 eased;
eased=_fmul(OV005_FLOAT_NEG256,_fflt(animTimer));eased=_fmul(eased,_fflt(animTimer));eased=_fdiv(eased,_fflt(OV005_MENU_ANIM_FRAMES_SQ));M2C_FIELD(menu,s16 *,OV005_MENU_SLIDE_OUT)=_ffix(eased);
eased=_fmul(OV005_FLOAT_NEG256,_fflt(animTimer));eased=_fmul(eased,_fflt(animTimer));eased=_fdiv(eased,_fflt(OV005_MENU_ANIM_FRAMES_SQ));M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SLIDE_IN)=_ffix(_fadd(OV005_FLOAT_256,eased));
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)==1){Ov005AddCoGridSprites();SelectSpriteSlot(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX));}
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)>0)return;
if(*gKeyState&2){Sprite_ResumeAnimation(arg0);HideAllSpriteSlots();PlaySoundEffect(0x1000f);return;}
if((*gKeyState&1) && IsCoUnlocked(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX))){
SetTextById(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000001);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_DETAIL;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)=GetCoSavedMode(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX));
Ov005SetDetailSelection(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED));HideAllSpriteSlots();PlaySoundEffect(0x10016);
}
}

/* Input handler of the menu's detail page.  It eases the 15-frame slide timer
 * into the two page-transition offsets (a quadratic curve), adds the detail
 * sprites on the last slide frame, and on B goes back to the list page while A
 * confirms the highlighted entry, closing the page again. */
void Ov005DetailMenuInput(M2C_UNK arg0){
extern void *gOv005MenuState;extern u16 *gKeyState;
u32 _fflt(s32);u32 _fmul(u32,u32);u32 _fdiv(u32,u32);u32 _fadd(u32,u32);s32 _ffix(u32);
void Ov005AddDetailSprites(void);M2C_UNK SelectSpriteSlot(s16);void SetCoSavedMode(s32,s32);void Ov005LoadEntryFacePalettes(s32);void SetTextById(void *,u32);M2C_UNK HideAllSpriteSlots();void PlaySoundEffect(s32);
void *menu=gOv005MenuState;s32 animTimer=M2C_FIELD(menu,s16 *,OV005_MENU_ANIM);u32 eased;
eased=_fmul(OV005_FLOAT_256,_fflt(animTimer));eased=_fmul(eased,_fflt(animTimer));eased=_fdiv(eased,_fflt(OV005_MENU_ANIM_FRAMES_SQ));
M2C_FIELD(menu,s16 *,OV005_MENU_SLIDE_OUT)=_ffix(_fadd(OV005_FLOAT_NEG256,eased));
eased=_fmul(OV005_FLOAT_256,_fflt(animTimer));eased=_fmul(eased,_fflt(animTimer));eased=_fdiv(eased,_fflt(OV005_MENU_ANIM_FRAMES_SQ));
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SLIDE_IN)=_ffix(eased);
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)==1){Ov005AddDetailSprites();SelectSpriteSlot(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION));}
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)>0)return;
if(*gKeyState&2){
SetCoSavedMode(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX),M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED));
Ov005LoadEntryFacePalettes(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX));
SetTextById(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000000);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_LIST;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
HideAllSpriteSlots();PlaySoundEffect(0x1000f);return;
}
if(*gKeyState&1){
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION))M2C_FIELD(gOv005MenuState,u8 *,OV005_MENU_CHANGED)=1;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION);
SetTextById(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000000);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_LIST;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
HideAllSpriteSlots();PlaySoundEffect(0x10016);
}
}

/* Sync the menu state and run the input handler of the page the menu is on: the
 * main list page or the detail page. */
void Ov005MenuInput(M2C_UNK owner) {
    extern void *gOv005MenuState;

    Ov005SyncMenuState(owner);
    switch (M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_PAGE)) {
    case OV005_PAGE_LIST: Ov005ListMenuInput(owner); return;
    case OV005_PAGE_DETAIL: Ov005DetailMenuInput(owner); return;
    }
}

/* Tear down the ov005 two-page menu: delete its wallpaper and sub-screen sprite
 * objects, hide the touch slots, free the menu state and release the UI graphics
 * bank it loaded (bank 10). */
void Ov005_CloseMenu(void) {
    M2C_UNK DeleteWallpaperSpritesOnAllEngines();
    M2C_UNK DeleteSubScreenSpriteTextClasses();
    M2C_UNK HideAllSpriteSlots();
    M2C_UNK HeapFreeBlock();
    M2C_UNK FreeUiGraphicsBank(s32);
    extern void *gOv005MenuState;

    DeleteWallpaperSpritesOnAllEngines();
    DeleteSubScreenSpriteTextClasses();
    HideAllSpriteSlots();
    if (gOv005MenuState) {
        HeapFreeBlock();
        gOv005MenuState = 0;
    }
    FreeUiGraphicsBank(10);
}

void func_ov005_02218e3c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220850;
    CreateSpriteObject(&data_ov005_02220850, arg0);
}

/* The face id of the CO who talks to the player: on a story map (map id
 * OV005_STORY_MAP_FIRST..OV005_STORY_MAP_END-1) the map's first speaker, once
 * the battle was won; otherwise the face of the CO the roster currently shows. */
u32 GetCurrentCoFaceId(void) {
 s32 DidPlayerWin(); extern void **gCurrentMap; extern u8 data_ov005_02221024[]; extern u8 gCoState[]; extern u16 gCoPlayerSlots[];
 s32 a,b; u16 mapId;
 if(DidPlayerWin()) {
 a=0; mapId=M2C_FIELD(*gCurrentMap,u16 *,MAP_ID);
 if((u32)mapId>=OV005_STORY_MAP_FIRST && (u32)mapId<OV005_STORY_MAP_END) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(mapId-OV005_STORY_MAP_FIRST)*OV005_STORY_MAP_FACE_STRIDE+OV005_STORY_MAP_FACE_FIRST];
 }
 return *(u16 *)((u8 *)gCoPlayerSlots + (s16)gCoState[CO_STATE_CURRENT_SLOT]*(s16)CO_SLOT_STRIDE);
}

/* Use the map's second speaker portrait after a story victory. */
u32 GetResultSecondCoFaceId(void) {
    s32 DidPlayerWin();
    extern void **gCurrentMap;
    extern u8 gCoMapFaces[];
    s32 storyMap, useStoryFace;
    u16 mapId;

    if (DidPlayerWin()) {
        storyMap = 0;
        mapId = M2C_FIELD(*gCurrentMap, u16 *, MAP_ID);
        if ((u32)mapId >= OV005_STORY_MAP_FIRST && (u32)mapId < OV005_STORY_MAP_END) {
            storyMap = 1;
        }
        if (storyMap) {
            useStoryFace = 1;
        } else {
            useStoryFace = 0;
        }
        if (useStoryFace & 255) {
            return gCoMapFaces[(mapId - OV005_STORY_MAP_FIRST) * OV005_STORY_MAP_FACE_STRIDE + OV005_STORY_MAP_FACE_SECOND];
        }
    }
    return OV005_RESULT_SECOND_FACE_DEFAULT;
}

/* The id of the quote line the current CO speaks: on a story map (map id
 * OV005_STORY_MAP_FIRST..OV005_STORY_MAP_END-1) the map's own quote text id,
 * otherwise one of the current CO's three quote lines picked at random. */
s32 GetCoQuoteTextId(void) {
 s32 GetRandomCoQuoteTextId(u16); extern void **gCurrentMap; extern u32 gCoStoryMapQuoteTextIds[]; extern u8 gCoState[]; extern u16 gCoPlayerSlots[];
 s32 a,b; u16 mapId;
 a=0; mapId=M2C_FIELD(*gCurrentMap,u16 *,MAP_ID);
 if((u32)mapId>=OV005_STORY_MAP_FIRST && (u32)mapId<OV005_STORY_MAP_END) a=1;
 if(a) b=1; else b=0;
 if(b&255) return gCoStoryMapQuoteTextIds[mapId-OV005_STORY_MAP_FIRST];
 return GetRandomCoQuoteTextId(*(u16 *)((u8 *)gCoPlayerSlots + (s16)gCoState[CO_STATE_CURRENT_SLOT]*(s16)CO_SLOT_STRIDE));
}

