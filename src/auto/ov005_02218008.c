/* 11 functions from 0x02218008 to 0x02218FD0 (ov005), found by ds-decomp. */
#include "common.h"
#include "ov005_menu.h"
void Ov005RefreshEntryLabel(void);
void func_ov005_022174f4(void);
void func_ov005_02217440(void);
void func_020aef7c(int,int,int);
void func_020b1b3c(void);
typedef struct Setup180 {u16 h[6];} Setup180;
typedef struct Pos180 {s16 h[4];} Pos180;
extern u16 data_ov005_02220058[];
extern void *gOv005MenuState, *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
void func_02086608();
void func_02082c84();
void GX_SetBankForBG();
void GX_SetBankForOBJ();
void func_02003124();
void func_020031cc();
void func_02002ab8();
void func_02002bb8();
void func_0200323c();
void func_020032bc();
void func_020822b8();
void OpenNarcArchive();
void LoadNarcFileDecompressed();
void LoadNarcFileToBuffer();
void CloseNarcArchive();
void LoadFileToSpriteBuffer();
void SetFileDirectory();
void func_0207c780();
M2C_UNK HeapFreeBlock();
void func_02098b94();
void CreateMenuTextSprite();
void func_0208ca2c();
void func_020aeebc();
void func_020a9a30(s32,s32,u8,void *);
void func_0208b758();
void func_02088f1c();
void func_020e3004();
void SetOv005FileDirectory(void);
void *HeapAllocBlock(int);
void *GetLocalizedFileName(void *);
void *func_02080e30(void *,int);
int func_020ae22c(int);
void *func_0208931c(void *);
u32 func_020aaf74(void *);
void *func_0208bc24(void *);
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
func_02086608(10); gOv005MenuState=HeapAllocBlock(60);func_02082c84();
GX_SetBankForBG(1);GX_SetBankForOBJ(2);func_02003124(4);func_020031cc(8);func_02002ab8(16);func_02002bb8(32);func_0200323c(128);func_020032bc(256);
M2C_FIELD(gOv005MenuState,u8 *,0)=0; M2C_FIELD(gOv005MenuState,s16 *,4)=0; M2C_FIELD(gOv005MenuState,s16 *,2)=M2C_FIELD(gOv005MenuState,s16 *,4);M2C_FIELD(gOv005MenuState,s16 *,14)=0;M2C_FIELD(gOv005MenuState,s16 *,12)=M2C_FIELD(gOv005MenuState,s16 *,14);M2C_FIELD(gOv005MenuState,s16 *,18)=0;M2C_FIELD(gOv005MenuState,s16 *,20)=0;M2C_FIELD(gOv005MenuState,s16 *,16)=M2C_FIELD(gOv005MenuState,s16 *,14)+1;M2C_FIELD(gOv005MenuState,s16 *,6)=0;M2C_FIELD(gOv005MenuState,s16 *,22)=12;M2C_FIELD(gOv005MenuState,s16 *,24)=0;M2C_FIELD(gOv005MenuState,s16 *,8)=0;M2C_FIELD(gOv005MenuState,s16 *,10)=256;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(&first);
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
LoadNarcFileToBuffer(GetLocalizedFileName(data_ov005_0222092c),M2C_FIELD(g3DSpriteEngineMain,void * *,40),0,0);CloseNarcArchive();
LoadFileToSpriteBuffer(data_ov005_02220944,0,32);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;SetFileDirectory(data_ov005_02220958);
p=func_02080e30(data_ov005_02220960,1);func_0207c780((char*)p+0x460,(char*)M2C_FIELD(g3DSpriteEngineMain,void * *,28)+0x8180);HeapFreeBlock(p);
LoadFileToSpriteBuffer(data_ov005_02220978,0x2e0,32);
for(i=0,j=0;i<12;i++,j+=12)func_02098b94((s16)(i+1),0,0x9380+(j<<6),(u16)i);
SetOv005FileDirectory();
CreateMenuTextSprite((char*)gOv005MenuState+36,192,160,1,0x35c,3,1,arg0,1);
CreateMenuTextSprite((char*)gOv005MenuState+40,224,160,2,0x36c,3,2,arg0,0);
{Pos180 pos={{43,44,45,46}};
for(i=0,j=0x37c,k=14,m=0;i<4;i++,j+=36,k+=60,m+=4)CreateMenuTextSprite((char*)gOv005MenuState+44+m,M2C_FIELD(gOv005MenuState,s16 *,10)+k,90,pos.h[i]&255,j,3,-1,arg0,0);
}
func_0208ca2c(4096,1,func_020ae22c(9),2);func_020aeebc(3,15,6);
gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(&second);
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
LoadNarcFileToBuffer(GetLocalizedFileName(data_ov005_022209b0),M2C_FIELD(g3DSpriteEngineSub,void * *,40),0,0);CloseNarcArchive();
LoadFileToSpriteBuffer(data_ov005_022209c4,0,32);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;
M2C_FIELD(gOv005MenuState,void * *,32)=func_0208931c(arg0);sprite=M2C_FIELD(gOv005MenuState,void * *,32);M2C_FIELD(sprite,u8 *,88)=8;
func_020a9a30(2,0,8,(char*)M2C_FIELD(gCur3DSpriteEngine,void * *,28)+0x3000);
func_020a9a30(2,2,8,(char*)M2C_FIELD(gCur3DSpriteEngine,void * *,48)+0x2e0);
M2C_FIELD(sprite,u32 *,68)=func_020aaf74(sprite);M2C_FIELD(sprite,u16 *,62)=0x180;M2C_FIELD(sprite,u32 *,64)=(M2C_FIELD(sprite,u32 *,64)&~0x3fc0000)|0x5c0000;M2C_FIELD(sprite,u16 *,60)=0xc00;
M2C_FIELD(gOv005MenuState,void * *,28)=func_0208bc24(arg0);M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u16 *,62)=0x200;M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u32 *,64)=(M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,28),u32 *,64)&~0x3fc0000)|0x200000;
func_0208b758(M2C_FIELD(gOv005MenuState,void * *,28),0x40000000);func_02088f1c(M2C_FIELD(gOv005MenuState,void * *,28));func_020e3004();LoadFileToSpriteBuffer(func_020e304c(),0x2c0,32);SetOv005FileDirectory();
func_ov005_022174f4();func_ov005_02217440();func_020aef7c(3,15,6);gCur3DSpriteEngine=saved;func_020b1b3c();Ov005RefreshEntryLabel();M2C_FIELD(gOv005MenuState,s16 *,24)=0;
}
#pragma opt_strength_reduction reset
void func_ov005_0221885c(void) {
    M2C_UNK func_020b1c78(s16);
    M2C_UNK func_ov005_02217f6c();
    extern void *gOv005MenuState;
    func_ov005_02217f6c();
    func_020b1c78(M2C_FIELD(gOv005MenuState, s16 *, 0xE));
}

/* Apply the menu page/index changes made since the last frame. */
void Ov005SyncMenuState(M2C_UNK arg0) {
    extern void *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern u8 sSyogunColorArchive[],sSyogunColorDown00[],sSyogunColorDown01[];
    void func_020a9a30(s32,s32,u8,void *);
    void *GetLocalizedFileName(void *);
    void OpenNarcArchive(void *);
    void LoadNarcFileToBuffer(void *,void *,s32,s32);
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
        func_020a9a30(0,0,(u8)(s16)pageIsList,(u8 *)M2C_FIELD(mainEngine,void **,0x1c)+0x6b80);
        M2C_FIELD(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_COLOR_OBJ),u16 *,0x3e)=0x35c;
        gCur3DSpriteEngine=savedEngine;
    }
    if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PREV_PAGE)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)){
        SetOv005FileDirectory();
        savedEngine=gCur3DSpriteEngine;
        gCur3DSpriteEngine=g3DSpriteEngineMain;
        OpenNarcArchive(GetLocalizedFileName(sSyogunColorArchive));
        if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)==OV005_PAGE_LIST) LoadNarcFileToBuffer(GetLocalizedFileName(sSyogunColorDown00),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
        else LoadNarcFileToBuffer(GetLocalizedFileName(sSyogunColorDown01),M2C_FIELD(gCur3DSpriteEngine,void **,0x28),0,0);
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
u32 func_020719d4(s32);u32 func_02071a64(u32,u32);u32 func_02071564(u32,u32);u32 func_02070f24(u32,u32);s32 func_020719a0(u32);
M2C_UNK func_ov005_02217f6c();M2C_UNK func_020b1c78(s16);void func_01ffa6fc(s32);M2C_UNK func_020b2178();void PlaySoundEffect(s32);s32 func_020bf894(s16);void func_0208b758(void *,u32);s16 func_020bf8cc(s16);void func_ov005_02217334(s16);
extern void *gOv005MenuState;extern u16 *gKeyState;
void *menu=gOv005MenuState;s32 animTimer=M2C_FIELD(menu,s16 *,OV005_MENU_ANIM);u32 eased;
eased=func_02071a64(OV005_FLOAT_NEG256,func_020719d4(animTimer));eased=func_02071a64(eased,func_020719d4(animTimer));eased=func_02071564(eased,func_020719d4(OV005_MENU_ANIM_FRAMES_SQ));M2C_FIELD(menu,s16 *,OV005_MENU_SLIDE_OUT)=func_020719a0(eased);
eased=func_02071a64(OV005_FLOAT_NEG256,func_020719d4(animTimer));eased=func_02071a64(eased,func_020719d4(animTimer));eased=func_02071564(eased,func_020719d4(OV005_MENU_ANIM_FRAMES_SQ));M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SLIDE_IN)=func_020719a0(func_02070f24(OV005_FLOAT_256,eased));
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)==1){func_ov005_02217f6c();func_020b1c78(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_INDEX));}
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)>0)return;
if(*gKeyState&2){func_01ffa6fc(arg0);func_020b2178();PlaySoundEffect(0x1000f);return;}
if((*gKeyState&1) && func_020bf894(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX))){
func_0208b758(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000001);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_DETAIL;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)=func_020bf8cc(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX));
func_ov005_02217334(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED));func_020b2178();PlaySoundEffect(0x10016);
}
}

/* Input handler of the menu's detail page.  It eases the 15-frame slide timer
 * into the two page-transition offsets (a quadratic curve), adds the detail
 * sprites on the last slide frame, and on B goes back to the list page while A
 * confirms the highlighted entry, closing the page again. */
void Ov005DetailMenuInput(M2C_UNK arg0){
extern void *gOv005MenuState;extern u16 *gKeyState;
u32 func_020719d4(s32);u32 func_02071a64(u32,u32);u32 func_02071564(u32,u32);u32 func_02070f24(u32,u32);s32 func_020719a0(u32);
void Ov005AddDetailSprites(void);M2C_UNK func_020b1c78(s16);void func_020bf8fc(s32,s32);void Ov005DrawEntryList(s32);void func_0208b758(void *,u32);M2C_UNK func_020b2178();void PlaySoundEffect(s32);
void *menu=gOv005MenuState;s32 animTimer=M2C_FIELD(menu,s16 *,OV005_MENU_ANIM);u32 eased;
eased=func_02071a64(OV005_FLOAT_256,func_020719d4(animTimer));eased=func_02071a64(eased,func_020719d4(animTimer));eased=func_02071564(eased,func_020719d4(OV005_MENU_ANIM_FRAMES_SQ));
M2C_FIELD(menu,s16 *,OV005_MENU_SLIDE_OUT)=func_020719a0(func_02070f24(OV005_FLOAT_NEG256,eased));
eased=func_02071a64(OV005_FLOAT_256,func_020719d4(animTimer));eased=func_02071a64(eased,func_020719d4(animTimer));eased=func_02071564(eased,func_020719d4(OV005_MENU_ANIM_FRAMES_SQ));
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SLIDE_IN)=func_020719a0(eased);
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)==1){Ov005AddDetailSprites();func_020b1c78(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION));}
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)>0)return;
if(*gKeyState&2){
func_020bf8fc(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX),M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED));
Ov005DrawEntryList(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_BASE_INDEX));
func_0208b758(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000000);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_LIST;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
func_020b2178();PlaySoundEffect(0x1000f);return;
}
if(*gKeyState&1){
if(M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)!=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION))M2C_FIELD(gOv005MenuState,u8 *,OV005_MENU_CHANGED)=1;
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_CONFIRMED)=M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_SELECTION);
func_0208b758(M2C_FIELD(gOv005MenuState,void **,OV005_MENU_SPRITE),0x40000000);
M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_PAGE)=OV005_PAGE_LIST;M2C_FIELD(gOv005MenuState,s16 *,OV005_MENU_ANIM)=OV005_MENU_ANIM_FRAMES;
func_020b2178();PlaySoundEffect(0x10016);
}
}

void func_ov005_02218db4(M2C_UNK arg0) {
   
 extern void *gOv005MenuState;
 Ov005SyncMenuState(arg0);
 switch(M2C_FIELD(gOv005MenuState,s16 *,4)) {case 0: Ov005ListMenuInput(arg0); return; case 1: Ov005DetailMenuInput(arg0); return;}
}

void func_ov005_02218dfc(void) {
 M2C_UNK func_020af1e4(); M2C_UNK func_020842d4(); M2C_UNK func_020b2178(); M2C_UNK HeapFreeBlock(); M2C_UNK func_02086658(s32);
 extern void *gOv005MenuState;
 func_020af1e4(); func_020842d4(); func_020b2178();
 if(gOv005MenuState) {HeapFreeBlock(); gOv005MenuState=0;}
 func_02086658(10);
}

void func_ov005_02218e3c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220850;
    CreateSpriteObject(&data_ov005_02220850, arg0);
}

u32 func_ov005_02218e54(void) {
 s32 DidPlayerWin(); extern void **gCurrentMap; extern u8 data_ov005_02221024[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
 s32 a,b; u16 x;
 if(DidPlayerWin()) {
 a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2];
 }
 return *(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12);
}

u32 func_ov005_02218edc(void) {
 s32 DidPlayerWin(); extern void **gCurrentMap; extern u8 data_ov005_02221024[];
 s32 a,b; u16 x;
 if(DidPlayerWin()) {
 a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
 if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
 if(a) b=1; else b=0;
 if(b&255) return data_ov005_02221024[(x-0xa1)*2+1];
 }
 return 9;
}

s32 func_ov005_02218f50(void) {
s32 func_020a30c0(u16); extern void **gCurrentMap; extern u32 data_ov005_02220ce8[]; extern u8 data_0215c334[]; extern u16 data_0215c340[];
s32 a,b; u16 x;
a=0; x=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
if((u32)x>=0xa1U && (u32)x<0xbbU) a=1;
if(a) b=1; else b=0;
if(b&255) return data_ov005_02220ce8[x-0xa1];
return func_020a30c0(*(u16 *)((u8 *)data_0215c340 + (s16)data_0215c334[4]*(s16)12));
}

