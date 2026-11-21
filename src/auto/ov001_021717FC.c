/* 30 functions from 0x021717FC to 0x021724C0 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ov001_menu.h"
void Ov001_FreeSpriteObjects(void);
extern s32 sOv001HighlightTilemapBuffer;
extern u8 sOv001HighlightTilesPath[];
extern u8 *sOv001HighlightTilemapPaths[];
extern Ov001WfcIcon *gOv001WfcIcon;
extern const u8 gOv001WfcIconLayouts[];
void Ov001_WfcIconUpdate(s32);
s32 Ov001_AddTask(s32,void (*)(s32),s32,s32);
extern s32 gOv001ChoiceFrameSprites;
extern s8 gOv001MessagePanelActive;
extern u8 data_ov001_02193cd0[64];
extern const u8 data_ov001_0218f2f8[8];

/* Frame task that slides the shared icon row into view: lift it four pixels a
 * frame, and when it reaches its resting y clamp it there and switch to the
 * intro step that flashes the bars before the row takes input. */
void Ov001_IconRow_SlideOut(s32 task){
extern void *gOv001IconRow;
void Ov001_IconRow_IntroStep(s32);
void Ov001_GetSpritePosition(s32,s32,s32 *,s32 *);
void Ov001_IconRow_Layout(s32);
s32 pos[2]; /* [0] y, [1] x */
Ov001_GetSpritePosition((s32)((Ov001IconRow *)gOv001IconRow)->backdrop,0,&pos[1],&pos[0]);
pos[0]-=OV001_ICON_ROW_STEP;Ov001_IconRow_Layout(pos[0]);
if(pos[0]>OV001_ICON_ROW_REST_Y)return;
Ov001_IconRow_Layout(OV001_ICON_ROW_REST_Y);Ov001_SetSlideStep(task,(M2C_UNK *)Ov001_IconRow_IntroStep);
}

void Ov001_IconRow_IntroStep(M2C_UNK arg0) {
    M2C_UNK Ov001_SetSlideStep(M2C_UNK, M2C_UNK *);
    extern void *gOv001IconRow;
    extern M2C_UNK Ov001_HandleIconRowTouch;
    M2C_FIELD(gOv001IconRow, s8 *, 0x16) = -1;
    M2C_FIELD(gOv001IconRow, u16 *, 0x14) = (u16) (M2C_FIELD(gOv001IconRow, u16 *, 0x14) + 1);
    if ((u32) M2C_FIELD(gOv001IconRow, u16 *, 0x14) < 4U) {
        return;
    }
    M2C_FIELD(gOv001IconRow, u16 *, 0x14) = 0U;
    Ov001_SetSlideStep(arg0, &Ov001_HandleIconRowTouch);
}

/* Handles a tap on the shared ov001 icon row: finds the touched bar, switches
 * it to its selected layout, moves it into place, and starts the timer that
 * restores the row after a moment. */
void Ov001_HandleIconRowTouch(void) {
    extern void *gOv001IconRow;
    extern const u8 gOv001IconRowCount[], gOv001IconRowSlot[][2], gOv001IconRowSize[], gOv001IconRowLayout[][2];
    extern const u16 gOv001IconRowX[], gOv001IconRowY[];
    void BuildTouchRect(const void *, const void *, void *);
    s32 TouchRectPressed(void *);
    void Ov001_MoveSpriteLayout(s32, s32, s32, s32);
    s32 Ov001_GetSpriteObjEntry(s32, s32);
    void Ov001_LoadSpriteObjLayout(s32, s32, s32);
    void Ov001_SetSpritePalette(s32, s32, s32);
    void Ov001_EndIconRowSelection(s32);
    s32 count, i, slot;
    u8 point[8];

    count = gOv001IconRowCount[((Ov001IconRow *)gOv001IconRow)->page];
    if (((Ov001IconRow *)gOv001IconRow)->inputLocked == 0) {
        if (((Ov001IconRow *)gOv001IconRow)->selected != -1) return;
        for (i = 0; i < count; i++) {
            BuildTouchRect((const u8 *)gOv001IconRowX + gOv001IconRowSlot[((Ov001IconRow *)gOv001IconRow)->page][i] * 4, gOv001IconRowSize, point);
            if (TouchRectPressed(point)) {
                if (((Ov001IconRow *)gOv001IconRow)->selectTimer) break;
                slot = gOv001IconRowLayout[((Ov001IconRow *)gOv001IconRow)->page][i];
                Ov001_LoadSpriteObjLayout(0, slot + 1, Ov001_GetSpriteObjEntry(((Ov001IconRow *)gOv001IconRow)->bars[i], 0));
                slot = gOv001IconRowSlot[((Ov001IconRow *)gOv001IconRow)->page][i];
                Ov001_MoveSpriteLayout(((Ov001IconRow *)gOv001IconRow)->bars[i], -1,
                    *(const u16 *)((const u8 *)gOv001IconRowX + slot * 4),
                    *(const u16 *)((const u8 *)gOv001IconRowY + slot * 4));
                Ov001_SetSpritePalette(((Ov001IconRow *)gOv001IconRow)->bars[i], -1, 1);
                ((Ov001IconRow *)gOv001IconRow)->selectTimer = Ov001_AddTask(0, Ov001_EndIconRowSelection, 0, 110);
                ((Ov001IconRow *)gOv001IconRow)->selected = i;
                return;
            }
        }
    }
    ((Ov001IconRow *)gOv001IconRow)->selected = -1;
}

void func_ov001_02171a44(s32 a){
extern void *gOv001IconRow;
void func_ov001_02171aa8(s32);
s32 pos[2];
Ov001_GetSpritePosition(M2C_FIELD(gOv001IconRow,s32 *,8),0,&pos[1],&pos[0]);
pos[0]+=4;Ov001_IconRow_Layout(pos[0]);
if(pos[0]<192)return;
Ov001_SetSlideStep(a,(M2C_UNK *)func_ov001_02171aa8);
}

#pragma optimize_for_size on
void func_ov001_02171aa8(s32 a){
extern void *gOv001IconRow;
void Ov001_PostTaskMessage(s32,s32);
void Ov001_DestroySprite(s32);
s32 i;
Ov001_PostTaskMessage(0,a);
if(M2C_FIELD(gOv001IconRow,s32 *,16))Ov001_PostTaskMessage(0,M2C_FIELD(gOv001IconRow,s32 *,16));
for(i=0;i<2;i++)if(((s32 *)gOv001IconRow)[i])Ov001_DestroySprite(((s32 *)gOv001IconRow)[i]);
Ov001_DestroySprite(M2C_FIELD(gOv001IconRow,s32 *,8));
Ov001_FreeAlloc(&gOv001IconRow);
}
#pragma optimize_for_size reset
/* Frame handler of a touch on the shared ov001 icon row: after 16 frames it
 * restores the page's bar sprites to their unselected layouts, slides the row
 * back out, clears the selection and, if a task was waiting on it, posts the
 * selection result back to that task. */
void Ov001_EndIconRowSelection(s32 message){
extern void *gOv001IconRow;extern const u8 gOv001IconRowCount[],gOv001IconRowLayout[][2];
s32 Ov001_GetSpriteObjEntry(s32,s32);void Ov001_LoadSpriteObjLayout(s32,s32,s32);void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_PostTaskMessage(s32,s32);void Ov001_IconRow_SlideOut(s32);
s32 n,i,slot;
M2C_FIELD(gOv001IconRow,u16 *,20)++;
if(M2C_FIELD(gOv001IconRow,u16 *,20)<16U)return;
n=gOv001IconRowCount[M2C_FIELD(gOv001IconRow,u8 *,23)];
for(i=0;i<n;i++){
slot=gOv001IconRowLayout[M2C_FIELD(gOv001IconRow,u8 *,23)][i];
Ov001_LoadSpriteObjLayout(0,slot,Ov001_GetSpriteObjEntry(((s32*)gOv001IconRow)[i],0));
Ov001_SetSpritePalette(((s32*)gOv001IconRow)[i],-1,1);
}
Ov001_IconRow_Layout(168);
M2C_FIELD(gOv001IconRow,u16 *,20)=0;
M2C_FIELD(gOv001IconRow,s8 *,22)=-1;
if(M2C_FIELD(gOv001IconRow,s32 *,16)){M2C_FIELD(gOv001IconRow,s32 *,16)=0;Ov001_PostTaskMessage(0,message);}
}

void func_ov001_02171c10(void) {
    extern s8 gOv001MessagePanelActive;
    gOv001MessagePanelActive = 0;
}

/* Show the one-shot ov001 message panel for `messageId`, filling `value` and
 * `index` into its text, unless one is already on screen.  Returns 1 when the
 * panel was built, 0 when it was already showing. */
s32 Ov001_ShowMessagePanel(s32 messageId,s32 value,s32 index){
extern u8 data_ov001_0218feb0[];extern s32 gOv001MessageArchive;void func_0200436c(s32,s32,s32);
void Ov001_LoadAsset(u8 *,void (*)(s32,s32,s32));s32 CreateTextPanel(s32,s32);s32 func_ov001_02175f60(s32,s32,s32,s32);s32 Ov001_GetTextFontId(void);s32 DrawPanelText(s32,s32,s32,s32,s32,s32,s32,s32);s32 CloseTextPanel(s32);
s32 panel,text;
if(*(u8 *)&gOv001MessagePanelActive)return 0;
Ov001_LoadAsset(data_ov001_0218feb0,func_0200436c);
*(volatile u32 *)0x4001010=0x1920000;
panel=CreateTextPanel(1,0);text=func_ov001_02175f60(gOv001MessageArchive,messageId,value,index);
DrawPanelText(panel,20,0,216,64,2,Ov001_GetTextFontId(),text);CloseTextPanel(panel);
gOv001MessagePanelActive=1;return 1;
}

s32 Ov001_FreeOptionBackground(void) {
 void Ov001_FreePageBackground(s32);
 if((u8)gOv001MessagePanelActive==0) return 0;
 Ov001_FreePageBackground(1);
 gOv001MessagePanelActive=0;
 return 1;
}

void *Ov001_LocalizePath(u8 *arg0) {
 void StringCopyPad(void *,void *,s32);
 s32 Ov001_GetLanguage(s32);
 s32 value;
 StringCopyPad(data_ov001_02193cd0,arg0,63);
 if(arg0[5]==120) return data_ov001_02193cd0;
 value=Ov001_GetLanguage(arg0[5]);
 if(arg0[5]==121 && value!=0) return data_ov001_02193cd0;
 data_ov001_02193cd0[5]=data_ov001_0218f2f8[value];
 return data_ov001_02193cd0;
}

void Ov001_LoadAsset(u8 *arg0,void (*arg1)(s32,s32,s32)) {
 void DC_FlushRange(s32,s32);
 s32 Ov001_LoadFile(void *,s32 *,s32);
 void Ov001_FreeFile(s32);
 s32 size;
 s32 p=Ov001_LoadFile(Ov001_LocalizePath(arg0),&size,4);
 DC_FlushRange(p,size);
 arg1(p,0,size);
 Ov001_FreeFile(p);
}

void Ov001_OpenMenuForMode(s32 a){
s32 x;func_ov001_02175d78(&x,0);
if(x==1){Ov001_OpenMenu(a);return;}
if(x==2)Ov001_LoadMenuRows(a);
}

void func_ov001_02171e20(M2C_UNK arg0) {
    M2C_UNK func_ov001_0217159c(M2C_UNK);
    M2C_UNK func_ov001_02175d78(M2C_UNK, s32 *);
    s32 sp0;

    func_ov001_02175d78(0, &sp0);
    if (sp0 != 1) {
        return;
    }
    func_ov001_0217159c(arg0);
}

/* Draws message `messageId` from the ov001 message archive into a fresh text
 * panel and closes it again: the small one-shot message box. */
void Ov001_ShowMessageBox(s32 messageId) {
    s32 Ov001_GetTextFontId();
    s32 Ov001_GetMessageText(s32, s32);
    s32 CreateTextPanel(M2C_UNK, M2C_UNK);
    M2C_UNK DrawPanelText(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK CloseTextPanel(s32);
    extern s32 gOv001MessageArchive;
    s32 text;
    s32 panel;

    panel = CreateTextPanel(0, 0);
    text = Ov001_GetMessageText(gOv001MessageArchive, messageId);
    DrawPanelText(panel, OV001_MESSAGE_BOX_X, OV001_MESSAGE_BOX_Y, OV001_MESSAGE_BOX_WIDTH,
        OV001_MESSAGE_BOX_HEIGHT, OV001_MESSAGE_BOX_COLOR, Ov001_GetTextFontId(), text);
    CloseTextPanel(panel);
}

/* Builds the ov001 message panel showing message `messageId` and draws the
 * speaker's name `name` over it at the name line position of the player's
 * language. */
void Ov001_ShowMessageWithName(s32 name,s32 messageId){
extern s32 gOv001MessageArchive;
s32 Ov001_GetLanguage(s32);
extern u16 gOv001NameTextY[],gOv001NameTextX[];

void DrawPanelAnchoredText(s32,s32,s32,s32,s32,s32);
s32 panel,text,langX,langY;
panel=CreateTextPanel(0,0);text=Ov001_GetMessageText(gOv001MessageArchive,messageId);
DrawPanelText(panel,13,60,230,94,2,Ov001_GetTextFontId(),text);
langX=((s32 (*)(void))Ov001_GetLanguage)();langY=((s32 (*)(void))Ov001_GetLanguage)();
DrawPanelAnchoredText(panel,gOv001NameTextX[langX*2],gOv001NameTextY[langY*2],2,0x209,name);
CloseTextPanel(panel);
}

s32 Ov001_GetTextFontId(void) {
    s32 Ov001_GetLanguage(s32);
    extern s32 data_ov001_0218f2c0[];
    s32 index = ((s32 (*)(void))Ov001_GetLanguage)();
    return data_ov001_0218f2c0[index];
}

void func_ov001_02171fa0(void) {
 s32 Ov001_Alloc(s32,s32);
 gOv001ChoiceFrameSprites=Ov001_Alloc(16,4);
}

void Ov001_FreeChoiceFrame(void) {
    void Ov001_FreeSpriteObjects();
    extern M2C_UNK gOv001ChoiceFrameSprites;
    Ov001_FreeSpriteObjects();
    Ov001_FreeAlloc(&gOv001ChoiceFrameSprites);
}

/* Rebuilds the two end sprites of an ov001 choice-frame row (the left and right
 * end pieces selected by `rowStyle`) and places them at the given left and
 * right edges, both on row `y`. */
void Ov001_LayoutChoiceFrameRow(s32 rowStyle,s32 left,s32 right,s32 y){
extern u8 gOv001ChoiceFrameRowTiles[];
extern s32 gOv001ChoiceFrameSprites;
s32 Ov001_CreateSprite(s32,s32,s32);
void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_MoveSpriteLayout(s32,s32,s32,s32);
s32 i;u8 *p;
Ov001_FreeSpriteObjects();
p=&gOv001ChoiceFrameRowTiles[rowStyle*2];
for(i=0;i<2;i++){
((s32 *)gOv001ChoiceFrameSprites)[i]=Ov001_CreateSprite(0,*p++,1);
Ov001_SetSpritePalette(((s32 *)gOv001ChoiceFrameSprites)[i],-1,1);
}
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[0],-1,left,y);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[1],-1,right,y);
}

/* Rebuilds the four sprites of the ov001 choice frame (corner pieces 7..10:
 * top-left, top-right, bottom-left, bottom-right) and places them at the given
 * left, right, top and bottom edges. */
void Ov001_LayoutChoiceFrame(s32 left,s32 right,s32 top,s32 bottom){
extern s32 gOv001ChoiceFrameSprites;
s32 Ov001_CreateSprite(s32,s32,s32);void Ov001_SetSpritePalette(s32,s32,s32);void Ov001_MoveSpriteLayout(s32,s32,s32,s32);
s32 j=6,i;Ov001_FreeSpriteObjects();
for(i=0;i<4;i++,j++){
((s32 *)gOv001ChoiceFrameSprites)[i]=Ov001_CreateSprite(0,j,1);
Ov001_SetSpritePalette(((s32 *)gOv001ChoiceFrameSprites)[i],-1,1);
}
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[0],-1,left,top);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[1],-1,right,top);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[2],-1,left,bottom);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[3],-1,right,bottom);
}

void Ov001_FreeSpriteObjects(void) {
 void Ov001_DestroySprite(s32);
 extern s32 gOv001ChoiceFrameSprites;
 s32 i,v;
 for(i=0;i<4;i++){
 v=((s32*)gOv001ChoiceFrameSprites)[i];
 if(v){Ov001_DestroySprite(v);((s32*)gOv001ChoiceFrameSprites)[i]=0;}
 }
}

/* Stage later highlight updates and load the initial BG1 tiles and tilemap. */
void Ov001_InitHighlightBackground(void) {
    void GX_LoadBG1Char(s32, s32, s32);
    void GX_LoadBG1Scr(s32, s32, s32);
    s32 Ov001_GetScreenLayout(void);

    sOv001HighlightTilemapBuffer =
        Ov001_Alloc(OV001_HIGHLIGHT_TILEMAP_BYTES, OV001_HIGHLIGHT_TILEMAP_ALIGNMENT);
    Ov001_LoadAsset(sOv001HighlightTilesPath, GX_LoadBG1Char);
    switch (Ov001_GetScreenLayout()) {
    case OV001_HIGHLIGHT_LAYOUT_WIFI:
        Ov001_LoadAsset(sOv001HighlightTilemapPaths[OV001_HIGHLIGHT_LAYOUT_WIFI], GX_LoadBG1Scr);
        return;
    case OV001_HIGHLIGHT_LAYOUT_AP:
        Ov001_LoadAsset(sOv001HighlightTilemapPaths[OV001_HIGHLIGHT_LAYOUT_AP], GX_LoadBG1Scr);
        return;
    }
}

void Ov001_FreeHighlightTilemap(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK sOv001HighlightTilemapBuffer;
    Ov001_FreeAlloc(&sOv001HighlightTilemapBuffer);
}

void func_ov001_021722dc(s32);
M2C_UNK Ov001_LoadObjLayoutBlock(s32 a) {
 void MI_CpuCopy32(s32,s32,s32);
 s32 p=Ov001_LoadFile(Ov001_LocalizePath(sOv001HighlightTilemapPaths[a]),0,4);
 MI_CpuCopy32(p,sOv001HighlightTilemapBuffer,192);
 Ov001_FreeFile(p);
 Ov001_AddTask(1,func_ov001_021722dc,0,120);
}

void Ov001_LoadSaveSlotObjLayout(void) {
    M2C_UNK Ov001_LoadObjLayoutBlock(s32);
    void *GetCurrentMapRecord();
    Ov001_LoadObjLayoutBlock(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4) + 5);
}

void func_ov001_021722c4(void) {
    Ov001_LoadObjLayoutBlock(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4) + 2);
}

void func_ov001_021722dc(s32 a) {
 void GX_LoadBG1Scr(s32,s32,s32);
 void Ov001_PostTaskMessage(s32,s32);
 DC_FlushRange(sOv001HighlightTilemapBuffer,192);
 GX_LoadBG1Scr(sOv001HighlightTilemapBuffer,0,192);
 Ov001_PostTaskMessage(1,a);
}

/* Creates the Wi-Fi connection indicator of the given style: one sprite set to
 * the first of that style's four status layouts, its tile and palette
 * attributes fixed up, and a per-frame task that follows the WFC state.  Does
 * nothing when an indicator is already up. */
void Ov001_ShowWfcIcon(s8 style) {
    s32 *Ov001_CreateSpriteFromLayout(s32, u8);
    s32 *sprite;
    s32 *word;
    Ov001WfcIcon *icon;
    if (gOv001WfcIcon != NULL) return;
    icon = (Ov001WfcIcon *)Ov001_Alloc(12, 4);
    gOv001WfcIcon = icon;
    icon->style = style;
    M2C_FIELD(gOv001WfcIcon, s32 **, 0) = Ov001_CreateSpriteFromLayout(0, gOv001WfcIconLayouts[style * 4]);
    sprite = M2C_FIELD(gOv001WfcIcon, s32 **, 0);
    *sprite = (*sprite & 0xFE00FF00) | 0xE50026;
    word = M2C_FIELD(gOv001WfcIcon, s32 **, 0);
    M2C_FIELD(word, u16 *, 4) = (M2C_FIELD(word, u16 *, 4) & ~0xC00) | 0x800;
    gOv001WfcIcon->task = Ov001_AddTask(0, Ov001_WfcIconUpdate, 0, 120);
}

void Ov001_HideWfcIcon(void) {
 void func_ov001_0218c94c(s32,s32);
 void Ov001_ReleaseSprite(s32);
 if(gOv001WfcIcon==NULL) return;
 func_ov001_0218c94c(0,M2C_FIELD(gOv001WfcIcon,s32 *,4));
 Ov001_ReleaseSprite(M2C_FIELD(gOv001WfcIcon,s32 *,0));
 Ov001_FreeAlloc((M2C_UNK *)&gOv001WfcIcon);
}

/* Per-frame task of the ov001 Wi-Fi indicator: with interrupts masked, read the
 * link status value (only when the WFC channel is up, i.e. WFC_GetPlayerMask
 * didn't answer 0x8000) and load that one of the icon style's four status
 * layouts into the sprite, then restore the OAM attribute words the layout load
 * overwrote (same fixup Ov001_ShowWfcIcon does at creation). */
void Ov001_WfcIconUpdate(s32 task) {
 s32 WFC_GetPlayerMask(void);
 s32 WFC_GetLinkStatusValue(void);
 void Ov001_LoadSpriteObjLayout(s32,s32,s32);
 volatile u16 *ime=&REG_IME;
 u16 savedIme=*ime;
 s32 status=0;
 s32 *attr0; s32 *attr1;
 *ime=0;
 if(WFC_GetPlayerMask()!=0x8000) status=WFC_GetLinkStatusValue();
 (void)*ime;
 *ime=savedIme;
 Ov001_LoadSpriteObjLayout(0,(gOv001WfcIconLayouts+gOv001WfcIcon->style*4)[status],M2C_FIELD(gOv001WfcIcon,s32 *,0));
 attr0=M2C_FIELD(gOv001WfcIcon,s32 **,0);
 *attr0=(*attr0&0xFE00FF00)|0xE50026;
 attr1=M2C_FIELD(gOv001WfcIcon,s32 **,0);
 M2C_FIELD(attr1,u16 *,4)=(M2C_FIELD(attr1,u16 *,4)&~0xC00)|0x800;
}

