/* 7 functions from 0x02209D0C to 0x0220ACCC (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_menu.h"

/* One row of the map-select entry table (gMapSelectEntries): the byte offset of
 * the entry's title block inside the shared mode-select title CG, then the
 * localized file record of the entry's own graphics. */
typedef struct MapSelectEntry {
    u32 titleBlockOffset;     /* +0x00 offset into the res_mode_select_title_cg buffer */
    const void *graphicsFile; /* +0x04 localized file record of this entry's graphics */
    u32 unknown08;            /* +0x08 */
    u32 unknown0C;            /* +0x0C */
} MapSelectEntry;             /* 0x10 bytes */
static inline void AdvanceLabelX(s32 *x,u16 width) { *x=(u8)(*x+(width+8)); }


static inline void UpdateA9Slider(void *p, s16 value) {
    s32 Divide(s32, s32);
    void ScrollBar_PlaceThumb(void *, s16, s16);
    void *object;
    s16 position, current, limit, base;
    M2C_FIELD(p,s16 *,0x12)=value;
    limit=M2C_FIELD(p,s16 *,0x16);
    current=M2C_FIELD(p,s16 *,0x12);
    if(current<=limit) {
        limit=M2C_FIELD(p,s16 *,0x14);
        if(current>=limit)limit=current;
    }
    M2C_FIELD(p,s16 *,0x12)=limit;
    object=M2C_FIELD(p,void **,0x1c);
    base=M2C_FIELD(p,s16 *,8);
    position=base+Divide(M2C_FIELD(p,s16 *,0x12)*(s16)(M2C_FIELD(object,s16 *,0x14)-M2C_FIELD(object,s16 *,0x12)),M2C_FIELD(p,s16 *,0x16)-M2C_FIELD(p,s16 *,0x14));
    ScrollBar_PlaceThumb(M2C_FIELD(p,void **,0x1c),position,M2C_FIELD(M2C_FIELD(p,void **,0x1c),s16 *,0xa));
}

static inline void UpdateA9Value(void *p,s32 value) {
    s32 current,limit;
    M2C_FIELD(p,s32 *,4)=value;
    if(M2C_FIELD(p,u8 *,0x14)) {
        while(M2C_FIELD(p,s32 *,4)>M2C_FIELD(p,s32 *,8))
            M2C_FIELD(p,s32 *,4)-=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12)+1;
        while(M2C_FIELD(p,s32 *,4)<M2C_FIELD(p,s32 *,12))
            M2C_FIELD(p,s32 *,4)+=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12)+1;
    } else {
        limit=M2C_FIELD(p,s32 *,8);
        current=M2C_FIELD(p,s32 *,4);
        if(current<=limit) {
            limit=M2C_FIELD(p,s32 *,12);
            if(current>=limit)limit=current;
        }
        M2C_FIELD(p,s32 *,4)=limit;
    }
}


#pragma opt_strength_reduction off
M2C_UNK func_ov003_02209d0c(void *a,s32 b) {
void Ov003_LoadMapSelectTitleBlock(void *,s32);void Ov003_LoadModeTexture(void *,s32);
u8 func_ov003_022066c8(u8);void *Ov003_GetMenuRowGroup(u8);
s16 GetSoundEffectVolumeSetting(void);s16 GetMusicVolumeSetting(void);
void func_ov003_0220accc(void *,u8);void Clear3DSpriteLayer(s32);
s32 GetLanguage(void);s32 GetLocalizedText(void *);s32 MeasureMessageCellWidth(s32);
void DrawLocalizedText(u8,s32,s32,void *,s32,u16);
void func_ov003_0220a864(M2C_UNK);void Show3DSpriteSlide(void *);void Hide3DSpriteSlide(void *);s32 Is3DSpriteHidden(void *);
void SpriteCellListSelectTile(void *,s16);void func_ov003_02207a8c(void *);M2C_UNK Ov003_RefreshListRowAnimations(void *,s32,s32);
extern M2C_UNK gOptionBits;extern u8 data_ov003_02210c80[];extern void *gCur3DSpriteEngine;
void *p;u8 i,total,j,x;s32 tile,k,mode;
M2C_FIELD(a,u8 *,0x38)|=2;
Ov003_LoadMapSelectTitleBlock(a,b);
mode=M2C_FIELD(a,u8 *,0x34);
p=M2C_FIELD(a,void **,0x54);
M2C_FIELD(p,s16 *,0xe)=0;M2C_FIELD(p,s16 *,0x10)=16;
M2C_FIELD(p,s16 *,0xc)=mode;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
Ov003_LoadModeTexture(a,b);
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,0x10)=func_ov003_022066c8(b);
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)=b;
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,17)=16;
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8)) {
UpdateA9Slider(M2C_FIELD(a,void **,0x64),GetSoundEffectVolumeSetting());
UpdateA9Slider(M2C_FIELD(a,void **,0x60),GetMusicVolumeSetting());
p=M2C_FIELD(a,void **,0x40);
UpdateA9Value(p,(u32)(M2C_FIELD(&gOptionBits,u16 *,6)<<18)>>30);
UpdateA9Value((u8 *)p+24,(u32)(M2C_FIELD(&gOptionBits,u16 *,6)<<20)>>30);
UpdateA9Value((u8 *)p+48,(u32)(M2C_FIELD(&gOptionBits,u16 *,6)<<17)>>31);
}
M2C_FIELD(a,void **,0x44)=Ov003_GetMenuRowGroup(b);
for(i=0;i<M2C_FIELD(M2C_FIELD(a,void **,0x44),u8 *,0);i++) {
j=0;
total=j;
for(;j!=(u8)b;j++)total+=M2C_FIELD(Ov003_GetMenuRowGroup(j),u8 *,0);
M2C_FIELD(M2C_FIELD(a,void **,0x48),void **,i*36)=data_ov003_02210c80+(total+i)*16;
}
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0)) {
func_ov003_0220accc(a,b);
Clear3DSpriteLayer(1);
switch(GetLanguage()) {case 1:case 2:case 3:case 4:case 5:mode=1;break;default:mode=0;break;}
x=0;tile=1;
if(mode) {
void *text;u16 width;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,12),void **,0);
width=MeasureMessageCellWidth(GetLocalizedText(text));
DrawLocalizedText(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>1) {
x+=width;
DrawLocalizedText(x,0,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,16),void **,0);
width=MeasureMessageCellWidth(GetLocalizedText(text));
DrawLocalizedText(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>2) {
{s32 next=x+width;u16 position=tile;
DrawLocalizedText((u8)next,0,1,(void *)0x4800000f,0x2000,position);}tile+=2;
}}
x=0;
for(k=2;k<M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8);k++) {
text=M2C_FIELD(M2C_FIELD((u8 *)M2C_FIELD(a,void **,0x58)+k*4,void **,12),void **,0);
width=MeasureMessageCellWidth(GetLocalizedText(text));
DrawLocalizedText(x,2,1,text,0x2000,(u16)tile);x+=width;tile+=width*2;
if(k!=M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)-1) {
DrawLocalizedText(x,2,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
}
}
} else {
void *text;u16 width;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,12),void **,0);
width=MeasureMessageCellWidth(GetLocalizedText(text));
DrawLocalizedText(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>1) {
{s32 next=x+width;u16 position=tile;
DrawLocalizedText((u8)next,x,1,(void *)0x4800000f,0x2000,position);}tile+=2;
}
for(k=1;k<M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8);k++) {
text=M2C_FIELD(M2C_FIELD((u8 *)M2C_FIELD(a,void **,0x58)+k*4,void **,12),void **,0);
width=MeasureMessageCellWidth(GetLocalizedText(text));
DrawLocalizedText(x,2,1,text,0x2000,(u16)tile);x+=width;tile+=width*2;
if(k!=M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)-1) {
DrawLocalizedText(x,2,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
}
}
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
}
func_ov003_0220a864((M2C_UNK)a);
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8)) {
Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0))
Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,20));
} else {
Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0))
Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,20));
}
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==9))
Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));
else Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==0))
Hide3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0));
else if(Is3DSpriteHidden(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0)))
Show3DSpriteSlide(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0));
p=M2C_FIELD(a,void **,0x3c);
SpriteCellListSelectTile(M2C_FIELD(a,void **,0x5c),(s16)((u8)(M2C_FIELD(p,u8 *,M2C_FIELD(p,u8 *,15))+1)+10));
func_ov003_02207a8c(a);
return Ov003_RefreshListRowAnimations(a,10,255);
}
#pragma opt_strength_reduction reset
/* Loads the map-select entry's title block into the sub screen's layer-2 VRAM
   (engine +0x14): the shared mode-select title CG is loaded from the file
   directory, and the block at the entry's offset within it is uploaded. */
void Ov003_LoadMapSelectTitleBlock(void *screen, s32 entry) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadGraphicsBlock(s32, s32);
    s32 LoadFileToBuffer(s32, s32);
    s32 GetLocalizedFileName(s32);
    M2C_UNK HeapFreeBlock(s32);
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK sMapSelectDir, sMapSelectTitleCgFile;
    extern MapSelectEntry gMapSelectEntries[];
    s32 titleCg;
    SetFileDirectory(&sMapSelectDir);
    titleCg = LoadFileToBuffer(GetLocalizedFileName((s32)&sMapSelectTitleCgFile), 1);
    LoadGraphicsBlock(titleCg + gMapSelectEntries[entry].titleBlockOffset, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x14));
    HeapFreeBlock(titleCg);
}

/* Upload the selected game mode's background texture (gGameModeTextures[mode])
 * into OBJ VRAM as one GX texture transfer, then free the loaded file. */
void Ov003_LoadModeTexture(void *screen, s32 mode) {
    M2C_UNK GX_BeginLoadTex();
    M2C_UNK GX_EndLoadTex();
    M2C_UNK LoadGraphicsBlock(s32, s32);
    s32 LoadFileToBuffer(s32, s32);
    s32 GetLocalizedFileName(s32);
    M2C_UNK HeapFreeBlock(s32);
    extern Ov003ModeTexture gGameModeTextures[];
    s32 textureFile;

    textureFile = LoadFileToBuffer(GetLocalizedFileName(M2C_FIELD(gGameModeTextures, s32 *, mode * OV003_MODE_TEXTURE_SIZE)), 1);
    GX_BeginLoadTex();
    LoadGraphicsBlock(textureFile, 0x06800000);
    GX_EndLoadTex();
    HeapFreeBlock(textureFile);
}

/* Store `animation` as the menu selection's current row animation, pause input
 * (clear MENU_FLAG_INPUT) and restart the row-animation object. */
void Ov003_SetRowAnimation(void *menu, s8 animation) {
    M2C_FIELD(M2C_FIELD(menu, void **, MENU_SELECTION), s8 *, MENU_SELECTION_ANIMATION) = animation;
    M2C_FIELD(menu, u8 *, MENU_FLAGS) = (u8) (M2C_FIELD(menu, u8 *, MENU_FLAGS) & ~MENU_FLAG_INPUT);
    M2C_FIELD(M2C_FIELD(menu, void **, MENU_ROW_ANIM_OBJECT), s8 *, 1) = 1;
}

/* Per-frame update of the ov003 map-select screen while its transition timer
 * (screen+0x34) counts down: at 20 it resets the sliding sprite, at 11 it
 * restores the saved display bits and starts the new sprite object, at 10 it
 * reconfigures the list for the chosen entry, and when the timer expires it
 * redraws the label and window for that entry. */
u32 func_ov003_0220a6bc(void *screen) {
M2C_UNK func_020c01ec(void *);M2C_UNK DrawMapSelectLabel(void *);u32 UpdateMapSelectLabelTransform(void *);M2C_UNK RequestMenuMode(void *,M2C_UNK);
extern M2C_UNK gOptionBits;
u8 timer;u32 active,isPending; s32 modeIsZero,kindIs8,remaining;void *p;
timer=M2C_FIELD(screen,u8 *,0x34);active=timer!=0?1:0;if(!(active&255))return active;
isPending=(u32)(M2C_FIELD(screen,u8 *,0x38)<<27)>>31;if(isPending)return isPending;
if(timer==20){p=M2C_FIELD(screen,void **,0x54);M2C_FIELD(p,s16 *,14)=16;M2C_FIELD(p,s16 *,16)=0;M2C_FIELD(p,s16 *,12)=10;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);}
if(M2C_FIELD(screen,u8 *,0x34)==11) {
modeIsZero=((u32)(M2C_FIELD(screen,u8 *,0x36)<<24)>>28)==0?1:0;
if(modeIsZero&255){
kindIs8=M2C_FIELD(M2C_FIELD(screen,void **,0x3c),u8 *,15)==8?1:0;
if((kindIs8&255)&&((u32)(M2C_FIELD(screen,u8 *,0x38)<<24)>>31)){
p=M2C_FIELD(screen,void **,0x40);
M2C_FIELD(&gOptionBits,u16 *,6)=(M2C_FIELD(&gOptionBits,u16 *,6)&~0x3000)|((u32)((u16)M2C_FIELD(p,s32 *,4)<<30)>>18);
M2C_FIELD(&gOptionBits,u16 *,6)=(M2C_FIELD(&gOptionBits,u16 *,6)&~0xc00)|((u32)((u16)M2C_FIELD(p,s32 *,28)<<30)>>20);
M2C_FIELD(&gOptionBits,u16 *,6)=(M2C_FIELD(&gOptionBits,u16 *,6)&~0x4000)|((u32)((u16)M2C_FIELD(p,s32 *,52)<<31)>>17);
RequestMenuMode(screen,0);func_020c01ec(screen);M2C_FIELD(screen,u8 *,0x38)&=~128;
}}}
if(M2C_FIELD(screen,u8 *,0x34)==10){M2C_FIELD(screen,u8 *,0x38)=(M2C_FIELD(screen,u8 *,0x38)&~1)|1;func_ov003_02209d0c(screen,M2C_FIELD(M2C_FIELD(screen,void **,0x3c),u8 *,17));M2C_FIELD(M2C_FIELD(screen,void **,0x50),u8 *,1)=0;}
remaining=M2C_FIELD(screen,u8 *,0x34)-1;M2C_FIELD(screen,u8 *,0x34)=remaining;active=(remaining&255)?1:0;if(active&255)return active;
DrawMapSelectLabel(screen);return UpdateMapSelectLabelTransform(screen);
}

#pragma push
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
void func_ov003_0220a864(M2C_UNK arg0) {
  void AddSpriteCell(void *,s32,s32,s32,u16,u16,u16);
  void SpriteCellListClear(void *);
  void SpriteCellListSelectTile(void *,s16);
  s32 ScaleFixed8(s32,s32);
  s32 func_020a8e28(s32,s32);
  s32 GetLanguage(void);
  s32 GetLocalizedText(void *);
  s32 MeasureStringWidth(s32);
  void func_020a99f4(void *);
  void func_020a9a08(void *);
  s32 minus=-1;
  s32 constant=0xcd;
  void *inner;
  void *cur;
  u16 selected;
  s32 i,k,mode;
  s32 xpre,x;
  s32 width,rawWidth;
  void *text;
  inner=M2C_FIELD(arg0,void **,0x5c);
  cur=M2C_FIELD(inner,void **,0);
  selected=cur?M2C_FIELD(cur,u16 *,8):minus;
  SpriteCellListClear(inner);
  xpre=func_020a8e28(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1),constant)+16;
  i=11;
if(i<M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0)+11){s16 selectionX=(s16)xpre;
 do {
  rawWidth=M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1);
width=ScaleFixed8(rawWidth,constant);
  if(i==selected) {
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),16,(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,4)*(i-11)+6),(u16)rawWidth,(u16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,2)-8),(u16)i,14);
  SpriteCellListSelectTile(M2C_FIELD(arg0,void **,0x5c),(s16)i);
  } else {
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),selectionX,(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,4)*(i-11)+6),(u16)width,(u16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,2)-8),(u16)i,14);
  }}while(++i<M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0)+11);}
  if(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u8 *,0)) {
  switch(GetLanguage()){case 1:case 2:case 3:case 4:case 5:mode=1;break;default:mode=0;break;}
  x=0;
  if(mode) {
  text=M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),void **,12),void **,0);
  width=MeasureStringWidth(GetLocalizedText(text));
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),x,M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,4),(u16)width,16,3,2);
  if(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u8 *,8)>2) {
  x=(u8)(x+((u16)width+8));
  text=M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),void **,16),void **,0);
  width=MeasureStringWidth(GetLocalizedText(text));
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),x,M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,4),(u8)width,16,4,2);
  x=0;
  }
  for(k=2;k<M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u8 *,8)-1;k++) {
  text=M2C_FIELD((u8*)M2C_FIELD(arg0,void **,0x58)+k*4,void **,0xc);
  width=MeasureStringWidth(GetLocalizedText(M2C_FIELD(text,void **,0)));
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),x,(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,4)+16),(u8)width,16,(u16)(k+3),2);
  x=(u8)(x+((u8)width+8));
  }
  } else {
  text=M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),void **,12),void **,0);
  width=MeasureStringWidth(GetLocalizedText(text));
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),x,M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,4),(u16)width,16,3,2);
  for(k=1;k<M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u8 *,8)-1;k++) {
  text=M2C_FIELD((u8*)M2C_FIELD(arg0,void **,0x58)+k*4,void **,0xc);
  width=MeasureStringWidth(GetLocalizedText(M2C_FIELD(text,void **,0)));
  AddSpriteCell(M2C_FIELD(arg0,void **,0x5c),x,(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,4)+16),(u8)width,16,(u16)(k+3),2);
  x=(u8)(x+((u8)width+8));
  }
  }
  }
  if((u8)(M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15)==8)) {
  func_020a99f4(M2C_FIELD(arg0,void **,0x60));
  func_020a99f4(M2C_FIELD(arg0,void **,0x64));
  } else {
  func_020a9a08(M2C_FIELD(arg0,void **,0x60));
  func_020a9a08(M2C_FIELD(arg0,void **,0x64));
  }
}
#pragma pop
/* Advance the help panel toward its target Y and clamp the final slide step. */
void Ov003_UpdateHelpPanelSlide(void *menu) {
    Ov003HelpPanel *panel = M2C_FIELD(menu, Ov003HelpPanel **, OV003_MENU_HELP_PANEL);
    s16 currentY = panel->y;
    s16 stepY;
    s16 targetY;

    if (currentY == panel->targetY) {
        return;
    }
    panel->y = currentY + panel->stepY;
    panel = M2C_FIELD(menu, Ov003HelpPanel **, OV003_MENU_HELP_PANEL);
    stepY = panel->stepY;
    if ((stepY == OV003_HELP_PANEL_HIDE_STEP && (targetY = panel->targetY, panel->y > targetY)) ||
        (stepY == OV003_HELP_PANEL_SHOW_STEP && (targetY = panel->targetY, panel->y < targetY))) {
        panel->y = targetY;
    }
    panel = M2C_FIELD(menu, Ov003HelpPanel **, OV003_MENU_HELP_PANEL);
    panel->slideFrame += 1;
}

