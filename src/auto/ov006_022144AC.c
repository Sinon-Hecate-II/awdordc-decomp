/* 17 functions from 0x022144AC to 0x022153FC (ov006), found by ds-decomp. */
#include "common.h"
#include "ov006_menu_sprite.h"
#include "ov006_map_transfer.h"

#pragma optimization_level 3
void func_ov006_022144ac(void *arg0) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern u8 gMapCodeString[],data_ov006_022183cc[],data_ov006_022183ce[],data_ov006_02218728[],data_ov006_02218730[],data_ov006_02218740[],data_ov006_02218750[],data_ov006_02218764[];
u64 func_020c54ac(void *);void CreateBattleSaveSlotForPlayer(s32,u32,u32);
void func_02019e64(void *,s32,void *,s32,s32);void SetBattleSlotRecord(s32,void *);
void Configure3DSpriteLayer(s32,void *);void Clear3DSpriteLayer(s32);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,s32);void CloseNarcArchive(void);
void LoadFileSectionToSpriteBuffer(void *,s32,s32,s32);void SetTileRectPalette(s32,s32,s32,s32);
s32 LoadSpriteResource(s32,s32,s32,s32);void Clear3DSpriteLayerVram(s32);void LoadScenePanelPalette(s32);
s32 GetUiColor(s32);void Load3DSpritePattern(s32,s32,s32,s32);void Set3DSpriteDrawCallback(void *,void *);void Show3DSprite(void *);void Show3DSpriteSlide(void *);
u32 GetBattleSlotType(s16);
void func_ov006_02215010(void);
u16 text[13];u16 *volatile p0,*volatile p1,*volatile p2,*volatile p3,*volatile p4,*volatile p5;
MenuSprite_02213e98 **sprites;void *savedEngine; s32 id,tile;u64 code;
if(IsMapConfirmEnabled()){
code=func_020c54ac(gMapCodeString);
id=M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,8);
CreateBattleSaveSlotForPlayer(id,(u32)code,(u32)(code>>32));
func_02019e64(text,0,gMapCodeString,0,0);
SetBattleSlotRecord(id,text);M2C_FIELD(arg0,u8 *,0x34)=1;
}
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Configure3DSpriteLayer(0,data_ov006_022183cc);Configure3DSpriteLayer(1,data_ov006_022183ce);
p0=*(u16 **)gCur3DSpriteEngine;*p0=*p0|0x10;
p1=*(u16 **)gCur3DSpriteEngine;*p1=*p1|0x20;
p2=*(u16 **)gCur3DSpriteEngine;*p2=*p2|0x40;
p3=*(u16 **)gCur3DSpriteEngine;*p3=*p3|0x80;
p4=*(u16 **)gCur3DSpriteEngine;*p4=*p4|0x100;
p5=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*p5=*p5&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
Clear3DSpriteLayer(0);SetFileDirectory(data_ov006_02218728);
OpenNarcArchive(GetLocalizedFileName(data_ov006_02218730));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218740),M2C_FIELD(gCur3DSpriteEngine,s32 *,0xc));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_02218750),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20));
CloseNarcArchive();LoadFileSectionToSpriteBuffer(data_ov006_02218764,160,0,32);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
Clear3DSpriteLayer(3);
tile=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x18);LoadSpriteResource(3,0,0,tile);
tile=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+0xe0;LoadSpriteResource(3,2,0,tile);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c),32,24,7);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
Clear3DSpriteLayer(1);Clear3DSpriteLayerVram(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=2|M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46);
LoadScenePanelPalette(6);
tile=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x34c0;LoadSpriteResource(1,0,1,tile);
LoadSpriteResource(1,2,0,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+0x2c0);
LoadSpriteResource(1,0,5,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x37c0);
Load3DSpritePattern(0x3e40,1,GetUiColor(9),2);
Load3DSpritePattern(0x4240,1,GetUiColor(12),2);
gCur3DSpriteEngine=savedEngine;
Set3DSpriteDrawCallback(arg0,func_ov006_02215010);
sprites=M2C_FIELD(arg0,void **,0x3c);
Show3DSprite(sprites[0]);Show3DSprite(sprites[1]);Show3DSprite(sprites[2]);Show3DSprite(sprites[3]);Show3DSprite(sprites[4]);Show3DSprite(sprites[5]);
{MenuSprite_02213e98 **toggle=M2C_FIELD(arg0,void **,0x3c);
{MenuSprite_02213e98 *s=toggle[0];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
{MenuSprite_02213e98 *s=toggle[1];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
{MenuSprite_02213e98 *s=toggle[2];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
{MenuSprite_02213e98 *s=toggle[3];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
{MenuSprite_02213e98 *s=toggle[4];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
{MenuSprite_02213e98 *s=toggle[5];u32 frame=s->base;if(IsMenuDisabled_02213e98(s))SetMenuFrame_02213e98(s,frame);else SetMenuFrame_02213e98(s,MenuBase_02213e98(s)+2);}
}
sprites=M2C_FIELD(arg0,void **,0x3c);
Show3DSpriteSlide(sprites[0]);
{MenuSprite_02213e98 *s=sprites[1];s->frame=(u16)(s->base+2);s->timer=0;}
{MenuSprite_02213e98 *s=sprites[2];s->frame=(u16)(s->base+2);s->timer=0;}
Show3DSpriteSlide(sprites[3]);Show3DSpriteSlide(sprites[4]);Show3DSpriteSlide(sprites[5]);
switch(GetBattleSlotType(M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,8))){
case 0:
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[3];u32 frame=s->base;u8 disabled=(s->base+2!=(u16)s->frame);if(!disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[4];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[5];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
break;
case 1:
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[3];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[4];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[5];u32 frame=s->base;u8 disabled=(s->base+2!=(u16)s->frame);if(!disabled){s->frame=(u16)frame;s->timer=0;}}
break;
case 2:
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[3];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[4];u32 frame=s->base;u8 disabled=(s->base+2!=(u16)s->frame);if(!disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[5];u32 frame=s->base;u8 disabled=(s->base+2!=(u16)s->frame);if(!disabled){s->frame=(u16)frame;s->timer=0;}}
break;
case 3:
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[3];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[4];u32 frame=s->base+2;u8 disabled=(s->base+2!=(u16)s->frame);if(disabled){s->frame=(u16)frame;s->timer=0;}}
{MenuSprite_02213e98 *s=((MenuSprite_02213e98 **)M2C_FIELD(arg0,void **,0x3c))[5];u32 frame=s->base;u8 disabled=(s->base+2!=(u16)s->frame);if(!disabled){s->frame=(u16)frame;s->timer=0;}}
break;
}
{void *p=M2C_FIELD(arg0,void **,0x48);M2C_FIELD(p,s16 *,0xe)=-255;M2C_FIELD(p,s16 *,0x10)=0;M2C_FIELD(p,s16 *,0xc)=12;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);}
Sprite_ResumeAnimation(arg0);
}
#pragma optimization_level reset
void func_ov006_02215010(void) {
    M2C_UNK func_ov006_02212184();
    func_ov006_02212184();
}

void func_ov006_0221501c(void) {
    M2C_UNK func_ov006_02211200();
    func_ov006_02211200();
}

void func_ov006_02215028(void) {
    M2C_UNK func_ov006_02211388();
    func_ov006_02211388();
}

void func_ov006_02215034(void) {

}

void func_ov006_02215038(void) {
    M2C_UNK ShowFriendCodePrompt();
    ShowFriendCodePrompt();
}

void func_ov006_02215044(void) {
    M2C_UNK CreateLocalBattleSaveSprite();
    CreateLocalBattleSaveSprite();
}

void func_ov006_02215050(void) {
    M2C_UNK CreateLocalBattleLoadSprite();
    CreateLocalBattleLoadSprite();
}

/* Erase the battle save the screen's selected slot summary (+0x4C, slot id at
 * +8) names, then advance the screen to its next step. */
void EraseSelectedBattleSave(void *screen) {
    s32 DeleteBattleSaveSlot(s32 slot);

    DeleteBattleSaveSlot(M2C_FIELD(M2C_FIELD(screen, void **, 0x4C), s16 *, 8));
    M2C_FIELD(screen, s8 *, 0x34) = 1;
}

/* Class-script action of the ov006 battle-save screen: forward to the screen
 * object's virtual per-frame update at the base class's vtable slot 8, which
 * the screen subclass overrides with its input/update handler. */
void Ov006_BattleSaveScreen_CallUpdate(void **screen) {
    M2C_FIELD(*screen, void (**)(void *), 8)(screen);
}

/* Tear down a screen's sprites: delete the shared wallpaper sprites on both
 * display engines, then the screen's own sprite object at +0x38. */
void DestroyScreenSprites(void *screen) {
    M2C_UNK DeleteSpriteObject(s32);
    M2C_UNK DeleteWallpaperSpritesOnAllEngines();
    DeleteWallpaperSpritesOnAllEngines();
    DeleteSpriteObject(M2C_FIELD(screen, s32 *, 0x38));
}

/* Frame step of an ov006 panel: advance the panel's reveal tween and, once the
 * tween has reached its end, resume the panel sprite's animation. */
void UpdatePanelRevealTween(void *panel) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK UpdateSpriteAnimation(void *);
    SpriteTween *tween = M2C_FIELD(panel, SpriteTween **, MAP_CODE_PANEL_SPRITE);
    u8 finished = M2C_FIELD(tween, u16 *, 2) == M2C_FIELD(tween, s16 *, 0xC);
    if (finished) {
        Sprite_ResumeAnimation(panel);
        return;
    }
    UpdateSpriteAnimation(tween);
}

void func_ov006_022150e0(void) {
    M2C_UNK func_ov006_02213e98();
    func_ov006_02213e98();
}

void func_ov006_022150ec(void) {
    M2C_UNK OpenMapCodeEntryScreen();
    OpenMapCodeEntryScreen();
}

void func_ov006_022150f8(void) {
    ((M2C_UNK (*)())func_ov006_022144ac)();
}

void func_ov006_02215104(s32 spriteId) {
void Clear3DSpriteLayer(s32);
void Clear3DSpriteLayerVram(s32);
void *CreateTextLayer(s32);
void RenderTextLayerMessage(void *,s32,s32,s32);
void LoadScenePanelPalette(s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
u16 *volatile p0,*volatile p1,*volatile p2,*volatile p3,*volatile p4,*volatile p5,*volatile p6,*volatile p7,*volatile p8,*volatile p9,*volatile p10,*volatile p11;
void *savedEngine=gCur3DSpriteEngine;
void *sprite;
gCur3DSpriteEngine=g3DSpriteEngineMain;
p0=*(u16 **)gCur3DSpriteEngine; *p0=*p0|0x10;
p1=*(u16 **)gCur3DSpriteEngine; *p1=*p1|0x20;
p2=*(u16 **)gCur3DSpriteEngine; *p2=*p2|0x40;
p3=*(u16 **)gCur3DSpriteEngine; *p3=*p3&~0x80;
p4=*(u16 **)gCur3DSpriteEngine; *p4=*p4|0x100;
p5=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12); *p5=*p5&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
Clear3DSpriteLayer(0);Clear3DSpriteLayer(1);Clear3DSpriteLayerVram(0);Clear3DSpriteLayerVram(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|2;
sprite=CreateTextLayer(spriteId);RenderTextLayerMessage(sprite,2,0x4640,0x42000001);M2C_FIELD(sprite,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=g3DSpriteEngineSub;
p6=*(u16 **)gCur3DSpriteEngine; *p6=*p6|0x10;
p7=*(u16 **)gCur3DSpriteEngine; *p7=*p7|0x20;
p8=*(u16 **)gCur3DSpriteEngine; *p8=*p8|0x40;
p9=*(u16 **)gCur3DSpriteEngine; *p9=*p9&~0x80;
p10=*(u16 **)gCur3DSpriteEngine; *p10=*p10|0x100;
p11=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12); *p11=*p11&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
Clear3DSpriteLayer(0);Clear3DSpriteLayer(1);Clear3DSpriteLayerVram(0);Clear3DSpriteLayerVram(1);
Clear3DSpriteLayer(0);Clear3DSpriteLayerVram(0);LoadScenePanelPalette(7);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|2;
gCur3DSpriteEngine=savedEngine;
}

u8 func_ov006_022153f4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x34);
}

