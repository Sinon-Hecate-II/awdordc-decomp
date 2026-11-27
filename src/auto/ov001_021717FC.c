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
extern u8 gOv001LocalizedPath[64];
extern const u8 gOv001LanguageCode[8];

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

/* Intro step of the shared icon row (Ov001_IconRow_SlideOut hands over to it):
 * keep the row unselected while its four intro frames run, then switch the slide
 * step to the touch handler that lets the player pick a bar. */
void Ov001_IconRow_IntroStep(M2C_UNK task) {
    M2C_UNK Ov001_SetSlideStep(M2C_UNK, M2C_UNK *);
    extern void *gOv001IconRow;
    extern M2C_UNK Ov001_HandleIconRowTouch;
    ((Ov001IconRow *)gOv001IconRow)->selected = -1;
    ((Ov001IconRow *)gOv001IconRow)->introDelay = (u16) (((Ov001IconRow *)gOv001IconRow)->introDelay + 1);
    if ((u32) ((Ov001IconRow *)gOv001IconRow)->introDelay < OV001_ICON_ROW_INTRO_FRAMES) {
        return;
    }
    ((Ov001IconRow *)gOv001IconRow)->introDelay = 0U;
    Ov001_SetSlideStep(task, &Ov001_HandleIconRowTouch);
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

/* Frame task that slides the shared icon row back down out of view: drop the
 * backdrop four pixels a frame and, once it is below the screen, tear the row
 * down. */
void Ov001_IconRow_Dismiss(s32 task){
extern void *gOv001IconRow;
void Ov001_IconRow_Destroy(s32);
void Ov001_GetSpritePosition(s32,s32,s32 *,s32 *);
void Ov001_IconRow_Layout(s32);
s32 pos[2]; /* [0] y, [1] x */
Ov001_GetSpritePosition((s32)((Ov001IconRow *)gOv001IconRow)->backdrop,0,&pos[1],&pos[0]);
pos[0]+=OV001_ICON_ROW_STEP;Ov001_IconRow_Layout(pos[0]);
if(pos[0]<OV001_ICON_ROW_HIDDEN_Y)return;
Ov001_SetSlideStep(task,(M2C_UNK *)Ov001_IconRow_Destroy);
}

#pragma optimize_for_size on
void Ov001_IconRow_Destroy(s32 a){
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
extern u8 data_ov001_0218feb0[];extern s32 gOv001MessageArchive;void GX_LoadBG0ScrSub(s32,s32,s32);
void Ov001_LoadAsset(u8 *,void (*)(s32,s32,s32));s32 CreateTextPanel(s32,s32);s32 func_ov001_02175f60(s32,s32,s32,s32);s32 Ov001_GetTextFontId(void);s32 DrawPanelText(s32,s32,s32,s32,s32,s32,s32,s32);s32 CloseTextPanel(s32);
s32 panel,text;
if(*(u8 *)&gOv001MessagePanelActive)return 0;
Ov001_LoadAsset(data_ov001_0218feb0,GX_LoadBG0ScrSub);
*(volatile u32 *)0x4001010=0x1920000;
panel=CreateTextPanel(1,0);text=func_ov001_02175f60(gOv001MessageArchive,messageId,value,index);
DrawPanelText(panel,20,0,216,64,2,Ov001_GetTextFontId(),text);CloseTextPanel(panel);
gOv001MessagePanelActive=1;return 1;
}

/* Free the message panel background built by Ov001_ShowMessagePanel, if one is
 * showing: returns 1 when a panel was released, 0 when none was up. */
s32 Ov001_FreeMessagePanel(void) {
    void Ov001_FreePageBackground(s32);
    if ((u8)gOv001MessagePanelActive == 0) return 0;
    Ov001_FreePageBackground(OV001_MESSAGE_PANEL);
    gOv001MessagePanelActive = 0;
    return 1;
}

/* Copy the asset path template `pathTemplate` into the shared localized-path
 * buffer and substitute the current language's code at the template's language
 * character (index 5).  A OV001_PATH_LANG_ALL template is returned unchanged;
 * a OV001_PATH_LANG_NONJP template is returned unchanged unless the console is
 * Japanese. */
void *Ov001_GetLocalizedFileName(u8 *pathTemplate) {
 void StringCopyPad(void *,void *,s32);
 s32 Ov001_GetLanguage(s32);
 s32 language;
 StringCopyPad(gOv001LocalizedPath,pathTemplate,63);
 if(pathTemplate[OV001_PATH_LANGUAGE_CHAR]==OV001_PATH_LANG_ALL) return gOv001LocalizedPath;
 language=Ov001_GetLanguage(pathTemplate[OV001_PATH_LANGUAGE_CHAR]);
 if(pathTemplate[OV001_PATH_LANGUAGE_CHAR]==OV001_PATH_LANG_NONJP && language!=0) return gOv001LocalizedPath;
 gOv001LocalizedPath[OV001_PATH_LANGUAGE_CHAR]=gOv001LanguageCode[language];
 return gOv001LocalizedPath;
}

/* Load the asset file named by `pathTemplate` with the language code filled in,
 * flush its data cache and hand the buffer, offset 0 and size to `loadFunction`
 * (a GX load routine), then free the buffer. */
void Ov001_LoadAsset(u8 *pathTemplate, void (*loadFunction)(s32, s32, s32)) {
    void DC_FlushRange(s32, s32);
    s32 Ov001_LoadFile(void *, s32 *, s32);
    void Ov001_FreeFile(s32);
    s32 size;
    s32 data = Ov001_LoadFile(Ov001_GetLocalizedFileName(pathTemplate), &size, OV001_ASSET_ALIGNMENT);
    DC_FlushRange(data, size);
    loadFunction(data, 0, size);
    Ov001_FreeFile(data);
}

/* Open the shared ov001 menu for the next screen mode the previous screen set:
 * mode 1 builds the five-row option menu, mode 2 only loads the menu rows, and
 * mode 0 leaves the screen alone.  `variant` selects the menu's icon/tables. */
void Ov001_OpenMenuForMode(s32 variant){
s32 nextMode;Ov001_GetNextScreenMode(&nextMode,0);
if(nextMode==1){Ov001_OpenMenu(variant);return;}
if(nextMode==2)Ov001_LoadMenuRows(variant);
}

/* Create the shared ov001 icon row for `variant`, but only when the screen that
 * ran before asked for one: its next-screen argument (OV001_SCREEN_NEXT_ARG) is
 * OV001_SCREEN_CREATE_ICON_ROW. */
void Ov001_CreateMenuIconRow(M2C_UNK variant) {
    M2C_UNK Ov001_CreateIconRow(M2C_UNK);
    M2C_UNK Ov001_GetNextScreenMode(M2C_UNK, s32 *);
    s32 nextArg;

    Ov001_GetNextScreenMode(0, &nextArg);
    if (nextArg != OV001_SCREEN_CREATE_ICON_ROW) {
        return;
    }
    Ov001_CreateIconRow(variant);
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

/* Allocate the ov001 choice frame's sprite handle array: 16 bytes for the four
 * 32-bit handles of Ov001_LayoutChoiceFrame's corner sprites. */
void Ov001_AllocChoiceFrameSprites(void) {
 s32 Ov001_Alloc(s32,s32);
 gOv001ChoiceFrameSprites=Ov001_Alloc(16,4);
}

/* Tear down the ov001 choice frame: destroy its four corner sprites and free the
 * sprite-handle array that Ov001_AllocChoiceFrameSprites allocated. */
void Ov001_FreeChoiceFrame(void) {
    void Ov001_FreeSpriteObjects(void);
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern s32 gOv001ChoiceFrameSprites;
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

/* Destroy the four sprites of the ov001 choice frame and clear their handles. */
void Ov001_FreeSpriteObjects(void) {
 void Ov001_DestroySprite(s32);
 extern s32 gOv001ChoiceFrameSprites;
 s32 i,sprite;
 for(i=0;i<OV001_CHOICE_FRAME_SPRITE_COUNT;i++){
 sprite=((s32*)gOv001ChoiceFrameSprites)[i];
 if(sprite){Ov001_DestroySprite(sprite);((s32*)gOv001ChoiceFrameSprites)[i]=0;}
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

void Ov001_UploadHighlightTilemap(s32);
/* Copy highlight layout `layout`'s tilemap block into the shared highlight
 * buffer and start the deferred BG1 upload task. */
M2C_UNK Ov001_LoadObjLayoutBlock(s32 layout) {
    void MI_CpuCopy32(s32, s32, s32);
    s32 block = Ov001_LoadFile(Ov001_GetLocalizedFileName(sOv001HighlightTilemapPaths[layout]), 0, 4);
    MI_CpuCopy32(block, sOv001HighlightTilemapBuffer, OV001_HIGHLIGHT_TILEMAP_BYTES);
    Ov001_FreeFile(block);
    Ov001_AddTask(1, Ov001_UploadHighlightTilemap, 0, 120);
}

/* Load the object layout of the save slot the current save record belongs to:
 * the record's physical slot index (0..2) picks one of the per-slot layouts,
 * which follow the first five screen layouts. */
void Ov001_LoadSaveSlotObjLayout(void) {
    M2C_UNK Ov001_LoadObjLayoutBlock(s32);
    void *GetCurrentMapRecord();
    Ov001_LoadObjLayoutBlock(M2C_FIELD(GetCurrentMapRecord(), u8 *, SAVE_SLOT_INDEX_REL) + 5);
}

/* Load the map-list screen's object layout for the current save slot: layouts
 * 2..4 are the three slots' map-list screens. */
void Ov001_LoadMapListSlotObjLayout(void) {
    M2C_UNK Ov001_LoadObjLayoutBlock(s32);
    void *GetCurrentMapRecord();
    Ov001_LoadObjLayoutBlock(M2C_FIELD(GetCurrentMapRecord(), u8 *, SAVE_SLOT_INDEX_REL) + 2);
}

/* One-shot upload task: flush the staged highlight tilemap to memory and load
 * it into the BG1 tilemap, then hand the task node back for recycling. */
void Ov001_UploadHighlightTilemap(s32 task) {
    void GX_LoadBG1Scr(s32, s32, s32);
    void Ov001_PostTaskMessage(s32, s32);
    DC_FlushRange(sOv001HighlightTilemapBuffer, OV001_HIGHLIGHT_TILEMAP_BYTES);
    GX_LoadBG1Scr(sOv001HighlightTilemapBuffer, 0, OV001_HIGHLIGHT_TILEMAP_BYTES);
    Ov001_PostTaskMessage(1, task);
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
 void Ov001_ReturnTaskNodeVeneer(s32,s32);
 void Ov001_ReleaseSprite(s32);
 if(gOv001WfcIcon==NULL) return;
 Ov001_ReturnTaskNodeVeneer(0,M2C_FIELD(gOv001WfcIcon,s32 *,4));
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

