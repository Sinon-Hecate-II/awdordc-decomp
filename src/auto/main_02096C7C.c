/* 31 functions from 0x02096C7C to 0x02097C50 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ds3dsprite.h"
#include "battle_map.h"

/* Award the battle to `winner`: every active player outside its team is marked
 * defeated with the given reason, and each one's surviving unit count is added
 * to the winner's total of enemy units; then the battle starts its end. */
void AwardVictoryToPlayer(s32 winner, M2C_UNK reason) {
    M2C_UNK EnterBattleEnd();
    M2C_UNK MarkPlayerDefeated(s32, M2C_UNK);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    extern s32 *gCurrentMap;
    s32 map;
    s32 player;
    s32 loserOffset;
    s32 winnerOffset;
    void *winnerRecord;

    loserOffset = MAP_PLAYER_STRIDE;
    player = 1;
    winnerOffset = winner * MAP_PLAYER_STRIDE;
    do {
        if ((IsPlayerActive(player) != 0) && (IsSameTeam(winner, player) == 0)) {
            map = *gCurrentMap;
            winnerRecord = winnerOffset + map;
            M2C_FIELD(winnerRecord, u16 *, MAP_PLAYER_STATES + PLAYER_REC_ENEMY_UNITS) = (u16) (M2C_FIELD(winnerRecord, u16 *, MAP_PLAYER_STATES + PLAYER_REC_ENEMY_UNITS) + M2C_FIELD((map + loserOffset), u8 *, MAP_PLAYER_STATES + PLAYER_REC_UNIT_COUNT));
            MarkPlayerDefeated(player, reason);
        }
        player += 1;
        loserOffset += MAP_PLAYER_STRIDE;
    } while (player < 5);
    EnterBattleEnd();
}

/* Apply the standard 3D sprite layout preset to the current engine. */
void SetStandard3DSpriteLayout(void) {
    M2C_UNK Apply3DSpriteLayout(u16 *);
    extern DS3DSpriteLayoutConfig g3DSpriteLayoutStandard;
    DS3DSpriteLayoutConfig preset;

    preset = g3DSpriteLayoutStandard;
    Apply3DSpriteLayout((u16 *) &preset);
}

/* Assign the VRAM banks the 3D sprite layers draw from: release the current
 * grants, then give main BG bank A, main OBJ bank B, sub BG bank C, sub OBJ bank D,
 * main BG extended palette bank E, main OBJ extended palette bank F, sub BG
 * extended palette bank H and sub OBJ extended palette bank I.  Bank G is left
 * to whoever holds it. */
void SetSpriteLayerVramBanks(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK GX_SetBankForOBJ(M2C_UNK);
    M2C_UNK GX_SetBankForBGExtPalette(M2C_UNK);
    M2C_UNK GX_SetBankForSubBG(M2C_UNK);
    M2C_UNK GX_SetBankForSubOBJ(M2C_UNK);
    M2C_UNK GX_SetBankForBGExtPlttSub(M2C_UNK);
    M2C_UNK GX_SetBankForOBJExtPlttSub(M2C_UNK);
    M2C_UNK GX_ReleaseBankGrants();
    GX_ReleaseBankGrants();
    GX_SetBankForBG(VRAM_BANK_A);
    GX_SetBankForOBJ(VRAM_BANK_B);
    GX_SetBankForSubBG(VRAM_BANK_C);
    GX_SetBankForSubOBJ(VRAM_BANK_D);
    GX_SetBankForBGExtPalette(VRAM_BANK_E);
    GX_SetBankForObjExtPalette(VRAM_BANK_F);
    GX_SetBankForBGExtPlttSub(VRAM_BANK_H);
    GX_SetBankForOBJExtPlttSub(VRAM_BANK_I);
}

/* Drop the extended-palette bank grants, then give the current screen OBJ extended
 * palette bank G. */
void SetObjExtPaletteBankG(void) {
    M2C_UNK GX_SetBankForObjExtPalette(M2C_UNK);
    M2C_UNK ReleaseExtPaletteBankGrants();
    ReleaseExtPaletteBankGrants();
    GX_SetBankForObjExtPalette(VRAM_BANK_G);
}

void func_02096dbc(void) {
    M2C_UNK SetBattleMapObjExtPaletteBankG();
    SetBattleMapObjExtPaletteBankG();
}

/* Enables the five layers of the 3D-sprite engine(s) whose display target matches
   the current selection (main, sub or the saved engine): configures the background
   banks, then ORs the layer-enable bits (0x10..0x100) into each matching engine. */
void EnableSpriteLayers(void) {
    void SetSpriteLayerVramBanks(void);
    void SetStandard3DSpriteLayout(void);
    M2C_UNK ApplyScreenMode(M2C_UNK);
    M2C_UNK ClearAll3DSpriteLayers(void);
    s32 Get3DSpriteTargetMode(void);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    u16 *volatile layer0, *volatile layer1, *volatile layer2, *volatile layer3, *volatile layer4;
    void *savedEngine;
    s32 engineIndex;
    SetSpriteLayerVramBanks();
    savedEngine = gCur3DSpriteEngine;
    engineIndex = 0;
    do {
        gCur3DSpriteEngine = (engineIndex == 0) ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        if ((Get3DSpriteTargetMode() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (Get3DSpriteTargetMode() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (Get3DSpriteTargetMode() != 3 || gCur3DSpriteEngine == savedEngine)) {
            SetStandard3DSpriteLayout();
            layer0 = *(u16 **)gCur3DSpriteEngine; *layer0 = *layer0 | 0x10;
            layer1 = *(u16 **)gCur3DSpriteEngine; *layer1 = *layer1 | 0x20;
            layer2 = *(u16 **)gCur3DSpriteEngine; *layer2 = *layer2 | 0x40;
            layer3 = *(u16 **)gCur3DSpriteEngine; *layer3 = *layer3 | 0x80;
            layer4 = *(u16 **)gCur3DSpriteEngine; *layer4 = *layer4 | 0x100;
            ApplyScreenMode(3);
            ClearAll3DSpriteLayers();
        }
        engineIndex++;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Disables the 3D-sprite layers of the engine(s) matching the active screen
   selection: configures the background banks, then clears the five layer mode
   bits of the main and/or sub engine's sprite bank. */
void DisableSpriteLayers(void) {
M2C_UNK Set3DSpriteVramBanks();
M2C_UNK Apply3DSpriteDisplayConfig();
s32 Get3DSpriteTargetMode();
M2C_UNK ApplyScreenMode(M2C_UNK);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
u16 *volatile layer0;u16 *volatile layer1;u16 *volatile layer2;u16 *volatile layer3;u16 *volatile layer4;
void *savedEngine; s32 engineIndex;
Set3DSpriteVramBanks();
savedEngine=gCur3DSpriteEngine;
engineIndex=0;
do {
gCur3DSpriteEngine=engineIndex==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
if((Get3DSpriteTargetMode()!=0||gCur3DSpriteEngine==g3DSpriteEngineMain)&&(Get3DSpriteTargetMode()!=1||gCur3DSpriteEngine==g3DSpriteEngineSub)&&(Get3DSpriteTargetMode()!=3||gCur3DSpriteEngine==savedEngine)){
Apply3DSpriteDisplayConfig();
layer0=*(u16 **)gCur3DSpriteEngine;*layer0=*layer0&~DS3D_BANK_MODE0;
layer1=*(u16 **)gCur3DSpriteEngine;*layer1=*layer1&~DS3D_BANK_MODE1;
layer2=*(u16 **)gCur3DSpriteEngine;*layer2=*layer2&~DS3D_BANK_MODE2;
layer3=*(u16 **)gCur3DSpriteEngine;*layer3=*layer3&~DS3D_BANK_MODE3;
layer4=*(u16 **)gCur3DSpriteEngine;*layer4=*layer4&~DS3D_BANK_MODE4;
ApplyScreenMode(3);
}
++engineIndex;
}while(engineIndex<2);
gCur3DSpriteEngine=savedEngine;
}

/* Marks sprite layer 1 dirty on each 3D-sprite engine the screen target selects
   (main, sub or the engine that was current), so the layer's tiles are rebuilt. */
void MarkSpriteLayer1Dirty(void) {
    s32 Get3DSpriteTarget();
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    s32 engineIndex;
    void *engine;

    savedEngine = gCur3DSpriteEngine;
    engineIndex = 0;
    do {
        if (engineIndex == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = engine;
        if (((Get3DSpriteTarget() != DS3D_TARGET_MAIN) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((Get3DSpriteTarget() != DS3D_TARGET_SUB) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((Get3DSpriteTarget() != DS3D_TARGET_ACTIVE) || (gCur3DSpriteEngine == savedEngine))) {
            M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
        }
        engineIndex += 1;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Set how many text row pairs the message panels show. */
void SetMessagePanelRowPairs(s8 rowPairs) {
    void *Get3DSpriteManager();
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_PANEL_ROW_PAIRS) = rowPairs;
}

/* Set the message-panel layout byte: 1 after Reset3DSpriteEngines lays the panels
 * out, 0 when Reset3DSpriteEngineState clears the 3D-sprite engine state. */
void SetMessagePanelLayout(s8 layout) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_PANEL_LAYOUT) = layout;
}

/* Store the tile attribute word `tileAttr` in scene panel `panelIndex`'s state
 * record (ScenePanelState.tileAttr, +0x04). */
void SetScenePanelTileAttr(s32 panelIndex, s16 tileAttr) {
    s32 *GetScenePanelState();
    M2C_FIELD(GetScenePanelState(panelIndex), s16 *, 4) = tileAttr;
}

/* Draw scene panel `panelIndex` with OBJ palette slot `palette`. */
void SetScenePanelPaletteSlot(s32 panelIndex, s8 palette) {
    s32 *GetScenePanelState();
    M2C_FIELD(GetScenePanelState(panelIndex), s8 *, 6) = palette;
}

/* Store `mode` as scene panel `panelIndex`'s text layout mode and set the panel's
 * child-flip flag to match: mode 1 flips the panel's two face sprites, anything
 * else leaves them in order. */
void SetScenePanelMode(s32 panelIndex, s32 mode) {
    s32 *GetScenePanelState();
    s32 panel;

    ((ScenePanelState *) GetScenePanelState())->mode = mode;
    panel = FindScenePanel((u16) panelIndex);
    if (!panel) return;
    if (mode == 1) SetScenePanelChildFlip(panel, 1);
    else SetScenePanelChildFlip(panel, 0);
}

/* Hide the face in scene panel `panelIndex` when `hidden` is nonzero: the panel's
 * face slot 0 linked face child is given face 0 (no face); when `hidden` is 0 the
 * slot's stored face is shown again.  The panel's palette is refreshed afterwards. */
void SetPanelFaceHidden(s32 panelIndex, s32 hidden) {
    s32 panel;
    s32 child;
    void *face;

    panel = FindScenePanel((u16) panelIndex);
    if (panel == 0) {
        return;
    }
    face = Get3DSpriteChild(panel, 0);
    child = M2C_FIELD(face, s32 *, FACE_SPRITE_CHILD);
    if (hidden) {
        SetFaceSpriteFace(child, 0);
    } else {
        SetFaceSpriteFace(child, M2C_FIELD(face, u8 *, FACE_SPRITE_FACE));
    }
    UpdateScenePanelPalette(panel);
}

/* Give face slot 0 of scene panel panelIndex the face id and expression a
 * message-box script asks for, then refresh the panel's palette. */
void SetScenePanelFace(s32 panelIndex, s32 faceId, s32 expression) {
s32 GetFacePaletteStyle(void); void SetFaceSpritePalette(void *,u32);void SetFaceSpritePose(void *,s32,s32,s32);s32 panel,faceChild;void *face;
panel=FindScenePanel((u16)panelIndex);if(!panel)return;
face=Get3DSpriteChild(panel,0);faceChild=M2C_FIELD(face,s32 *,FACE_SPRITE_CHILD);
SetFaceSpritePalette(face,(u8)GetFacePaletteStyle());SetFaceSpritePose(face,faceId,expression+5,1);SetFaceSpriteFace(faceChild,faceId);UpdateScenePanelPalette(panel);
}

/* ShowPanelFace: shows face slot faceIndex (0 or 1) of the scene panel — the
   slot's 3D sprite slides in from the side over eight frames, or snaps when the
   screen mode asks for it — then shows the slot's linked face child and
   refreshes the panel. */
void ShowPanelFace(s32 faceIndex) {
    M2C_UNK Show3DSpriteFade(void *, s32);
    M2C_UNK Show3DSprite(s32);
    M2C_UNK Slide3DSpriteIn(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 GetScreenFlag(u8);
    void *panel;
    void *face;
    s32 slideFrames;
    s32 child;

    panel = FindScenePanel(2);
    if (panel == NULL) {
        return;
    }
    face = Get3DSpriteChild(panel, faceIndex);
    slideFrames = 8;
    child = M2C_FIELD(face, s32 *, FACE_SPRITE_CHILD);
    if (GetScreenFlag((u8) ((u32) (M2C_FIELD(panel, u8 *, SPRITE_ACTOR_STATE) << 0x1C) >> 0x1D)) == 1) {
        slideFrames = 0;
    }
    switch (faceIndex) {                                 /* irregular */
    case 0:
        Slide3DSpriteIn(face, -0x40, 0, 0, 0, slideFrames);
        Show3DSpriteFade(face, slideFrames);
        break;
    case 1:
        Slide3DSpriteIn(face, 0xA0, 0, 0x60, 0, slideFrames);
        Show3DSpriteFade(face, slideFrames);
        break;
    }
    Show3DSprite(child);
    UpdateScenePanelPalette(panel);
}

/* HidePanelFace: hides face slot faceIndex (0 or 1) of the scene panel — the
   slot's 3D sprite slides out over eight frames, or snaps when the screen mode
   asks for it — then hides the slot's linked face child and refreshes the panel. */
void HidePanelFace(s32 faceIndex) {
    M2C_UNK Slide3DSpriteOut(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK Hide3DSpriteFade(void *, s32);
    s32 GetScreenFlag(u8);
    void *panel;
    register void *face;
    long slideFrames;
    register unsigned child;

    panel = FindScenePanel(2);
    if (panel == NULL) {
        return;
    }
    face = Get3DSpriteChild(panel, faceIndex);
    slideFrames = 8;
    child = M2C_FIELD(face, s32 *, FACE_SPRITE_CHILD);
    if (GetScreenFlag((u8) ((u32) (M2C_FIELD(panel, u8 *, SPRITE_ACTOR_STATE) << 0x1C) >> 0x1D)) == 1) {
        slideFrames = 0;
    }
    switch (faceIndex) {                                 /* irregular */
    case 0:
        Slide3DSpriteOut(face, 0, 0, -0x40, 0, slideFrames);
        Hide3DSpriteFade(face, slideFrames);
        break;
    case 1:
        Slide3DSpriteOut(face, 0x60, 0, 0xA0, 0, slideFrames);
        Hide3DSpriteFade(face, slideFrames);
        break;
    }
    Hide3DSprite(child);
    UpdateScenePanelPalette(panel);
}

void func_02097410(void) {

}

/* Set face slot `faceSlot` of the bottom scene panel to face `faceId` in the
 * second expression set (`expression` + 8), using the current face palette
 * style, and set the slot's linked face child to the same face. */
void SetScenePanelFaceSlot(s32 faceSlot, s32 faceId, s32 expression) {
    s32 GetFacePaletteStyle(void);
    void SetFaceSpritePalette(void *,u32);
    void SetFaceSpritePose(void *,s32,s32,s32);
    s32 panel,faceChild;
    void *face;
    panel=FindScenePanel(SCENE_PANEL_BOTTOM);
    if(!panel)return;
    face=Get3DSpriteChild(panel,faceSlot);
    faceChild=M2C_FIELD(face,s32 *,FACE_SPRITE_CHILD);
    SetFaceSpritePalette(face,(u8)GetFacePaletteStyle());
    SetFaceSpritePose(face,faceId,expression+8,1);
    SetFaceSpriteFace(faceChild,faceId);
}

/* Hide the face of slot `faceSlot` (0 or 1) in the bottom scene panel when
 * `hidden` is nonzero: the slot's linked face child is given face 0 (no face).
 * When `hidden` is 0 the slot's stored face is shown again.  Either way the
 * panel's palette is refreshed afterwards. */
void SetScenePanelFaceHidden(s32 faceSlot, s32 hidden) {
    s32 panel;
    s32 child;
    void *face;

    panel = FindScenePanel(SCENE_PANEL_BOTTOM);
    if (panel == 0) {
        return;
    }
    face = Get3DSpriteChild(panel, faceSlot);
    child = M2C_FIELD(face, s32 *, FACE_SPRITE_CHILD);
    if (hidden != 0) {
        SetFaceSpriteFace(child, 0U);
    } else {
        SetFaceSpriteFace(child, M2C_FIELD(face, u8 *, FACE_SPRITE_FACE));
    }
    UpdateScenePanelPalette(panel);
}

/* Builds the 3D sprite cells for the current sprite mode on both screens:
   1 sprite, a 3x2 cell grid, or 2 sprites, all sharing the given sprite data. */
void Build3DSpriteScene(s32 spriteData) {
    s32 Get3DSpriteCount();
    s32 Get3DSpriteTarget();
    void SetMenuCursor(s32);
    M2C_UNK SetFaceChildTextureRow(void *, s32, u16);
    M2C_UNK SetFaceSpriteTextureRow(void *, s32, u16);
    M2C_UNK ConfigureScenePanelSprite(void *, M2C_UNK, M2C_UNK, u16);
    void *Alloc3DSprite(s32);
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    s32 screen;
    s32 row;
    s32 unused;
    void **enginePtr;
    s32 nextScreen;
    s32 spriteCount;
    s32 nextRow;
    void *part;
    void *part2;
    u16 rowId;
    s32 slot;
    s32 slot2;
    void *child;
    void *child2;
    s32 yOff;
    s32 yOff2;
    s32 tileOff;
    s32 tileOff2;
    void *sprite;
    void *sprite1;
    void *sprite2;

    unused = spriteData;
    savedEngine = (void *)gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            enginePtr = &g3DSpriteEngineMain;
        } else {
            enginePtr = &g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = *enginePtr;
        if (((Get3DSpriteTarget() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((Get3DSpriteTarget() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((Get3DSpriteTarget() != 3) || (gCur3DSpriteEngine == (void *)savedEngine))) {
            spriteCount = Get3DSpriteCount();
            switch (spriteCount) {                  /* irregular */
            case 0:
                sprite = Alloc3DSprite(unused);
                ConfigureScenePanelSprite(sprite, 1, 0, 8U);
                M2C_FIELD(sprite, s16 *, 0x2E) = 2;
                M2C_FIELD(sprite, s16 *, 0x3C) = 0x400;
                break;
            case 1:
                row = 0;
                yOff = 0x9000;
                tileOff = 0x9800;
                do {
                    sprite1 = Alloc3DSprite(unused);
                    ConfigureScenePanelSprite(sprite1, 1, 0x8000, (u16) (row + 0xD));
                    slot = 0;
                    rowId = (u16) row;
                    M2C_FIELD(sprite1, u16 *, 0x2E) = rowId;
                    M2C_FIELD(sprite1, s16 *, 0x3C) = 0x400;
loop_17:
                    part = Get3DSpriteChild(sprite1, slot);
                    child = M2C_FIELD(part, void **, 0x60);
                    SetFaceChildTextureRow(child, yOff, (u16) (row + 0xA));
                    SetFaceSpriteTextureRow(part, tileOff, rowId);
                    M2C_FIELD(child, s16 *, 0x3C) = 0x400;
                    slot += 1;
                    M2C_FIELD(part, s16 *, 0x3C) = 0x400;
                    if ((s32) slot < 2) {
                        goto loop_17;
                    }
                    yOff += 0x200;
                    nextRow = row + 1;
                    row = nextRow;
                    tileOff += 0xA00;
                } while (nextRow < 3);
                break;
            case 2:
                sprite2 = Alloc3DSprite(unused);
                ConfigureScenePanelSprite(sprite2, 2, 0, 0xDU);
                M2C_FIELD(sprite2, s16 *, 0x2E) = 2;
                M2C_FIELD(sprite2, s16 *, 0x3C) = 0x400;
                slot2 = 0;
                yOff2 = 0x1800;
                tileOff2 = 0x2000;
                do {
                    part2 = Get3DSpriteChild(sprite2, slot2);
                    child2 = M2C_FIELD(part2, void **, 0x60);
                    SetFaceChildTextureRow(child2, yOff2, (u16) (slot2 + 0xA));
                    SetFaceSpriteTextureRow(part2, tileOff2, slot2);
                    M2C_FIELD(child2, s16 *, 0x3C) = 0x400;
                    M2C_FIELD(part2, s16 *, 0x3C) = 0x400;
                    yOff2 += 0x200;
                    tileOff2 += 0x8000;
                    slot2 += 1;
                } while ((s32) slot2 < 2);
                break;
            }
        }
        nextScreen = screen + 1;
        screen = nextScreen;
    } while (nextScreen < 2);
    gCur3DSpriteEngine = savedEngine;
    SetMenuCursor(-1);
}

void func_02097768(void) {

}

/* Slide a hidden scene panel into its screen band and select it if no panel is active. */
s32 ShowScenePanel(s32 panelIndex) {
    s32 Is3DSpriteVisible(void);
    s32 GetScreenFlag(u8);
    M2C_UNK Slide3DSpriteIn(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK FindScenePanel(M2C_UNK);
    void ReloadScenePanelGraphics(void *);
    s32 *GetScenePanelState();
    s32 func_02091f08(void);
    void LoadScenePanelPalette(M2C_UNK);
    s32 GetMenuCursor(void);
    void SetMenuCursor(s32);
    void *panel;
    s32 slideFrames;
    ScenePanelState *panelState;

    panel = (void *) FindScenePanel((u16) panelIndex);
    if (panel != NULL && Is3DSpriteVisible() == 0) {
        ReloadScenePanelGraphics(panel);
        slideFrames = 8;
        if (GetScreenFlag((u8) ((u32) (M2C_FIELD(panel, u8 *, SPRITE_ACTOR_STATE) << 0x1C) >> 0x1D)) == 1) {
            slideFrames = 0;
        }
        switch (panelIndex) {
        case SCENE_PANEL_TOP:
            Slide3DSpriteIn(panel, 0, -0x40, 0, 0, slideFrames);
            break;
        case SCENE_PANEL_MIDDLE:
            Slide3DSpriteIn(panel, -0x100, 0x40, 0, 0x40, slideFrames);
            break;
        case SCENE_PANEL_BOTTOM:
            Slide3DSpriteIn(panel, 0, 0xc0, 0, 0x80, slideFrames);
            break;
        }
        panelState = (ScenePanelState *) GetScenePanelState(panelIndex);
        panelState->contentHeight = (u16) func_02091f08();
        LoadScenePanelPalette(panelState->palette);
        if (GetMenuCursor() < 0) {
            SetMenuCursor(panelIndex);
        }
        return 1;
    }
    return 0;
}

/* Slide an open scene panel back out of its screen band, opposite to
 * ShowScenePanel's directions, then clear the panel's tile rows.  Needs a
 * visible 3D sprite; returns 0 when the panel is closed or already moving out. */
s32 HideScenePanel(s32 panelIndex) {
    s32 Is3DSpriteVisible(void);
    s32 GetScreenFlag(u8);
    M2C_UNK Slide3DSpriteOut(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void ClearScenePanelRows(s32);
    void *panel;
    s32 slideFrames;

    panel = (void *) FindScenePanel((u16) panelIndex);
    if (panel != NULL && Is3DSpriteVisible() != 0) {
        slideFrames = 8;
        if (GetScreenFlag((u8) ((u32) (M2C_FIELD(panel, u8 *, SPRITE_ACTOR_STATE) << 0x1C) >> 0x1D)) == 1) {
            slideFrames = 0;
        }
        switch (panelIndex) {
        case SCENE_PANEL_TOP:
            Slide3DSpriteOut(panel, 0, 0, 0, -0x40, slideFrames);
            break;
        case SCENE_PANEL_MIDDLE:
            Slide3DSpriteOut(panel, 0, 0x40, 0x100, 0x40, slideFrames);
            break;
        case SCENE_PANEL_BOTTOM:
            Slide3DSpriteOut(panel, 0, 0x80, 0, 0xc0, slideFrames);
            break;
        }
        ClearScenePanelRows(panelIndex);
        return 1;
    }
    return 0;
}

/* Hide all three scene panels (top, middle and bottom); returns 1 when at least
 * one was hidden, 0 otherwise. */
s32 HideAllScenePanels(void) {
    s32 HideScenePanel(M2C_UNK);
    s32 hidden;

    hidden = 0;
    if (HideScenePanel(SCENE_PANEL_TOP) != 0) {
        hidden = 1;
    }
    if (HideScenePanel(SCENE_PANEL_MIDDLE) != 0) {
        hidden = 1;
    }
    if (HideScenePanel(SCENE_PANEL_BOTTOM) != 0) {
        hidden = 1;
    }
    return hidden;
}

/* Highlight the scene panel `panelIndex` (top, middle or bottom) and clear the
 * highlight of the other open panels, then put the menu cursor on it, clear the
 * panel's tile rows and mark the sprite layer for a rebuild. */
s32 HighlightScenePanel(s32 panelIndex) {
    s32 *GetScenePanelState();
    s32 index;
    s32 *state;
    s32 panel;
    s32 highlighted;

    for (index = 0; index < 3; index++) {
        state = GetScenePanelState(index);
        panel = FindScenePanel((u16) index);
        if (panel) {
            highlighted = 0;
            if (index == panelIndex) {
                highlighted = 1;
            }
            ApplyScenePanelPalette(((ScenePanelState *) state)->palette, highlighted);
            SetScenePanelFaceState((void *) panel, highlighted);
            UpdateScenePanelPalette((void *) panel);
        }
    }
    SetMenuCursor(panelIndex);
    ClearScenePanelRowsUnlessMessageBox(panelIndex);
    MarkSpriteLayer1Dirty();
    return 1;
}

/* Highlights the active face of the two-face scene panel: when exactly two 3D
 * sprites exist, sets FACE_SPRITE_ACTIVE on panel 2's face child at `faceIndex`
 * and clears it on the other, refreshes both face sprites and updates the
 * panel's palette.  A faceIndex of -1 clears both. */
void HighlightScenePanelFace(s32 faceIndex) {
    s32 Get3DSpriteCount();
    M2C_UNK SetFaceSpriteActive(s32, s32);
    M2C_UNK RefreshFaceSprite(s32);
    long index;
    s32 panel;
    s32 face;

    if (Get3DSpriteCount() != 2) {
        return;
    }
    panel = FindScenePanel(2);
    if (!panel) {
        return;
    }
    index = 0;
    do {
        face = Get3DSpriteChild(panel, index);
        if (index == faceIndex) {
            SetFaceSpriteActive(face, 1);
        } else {
            SetFaceSpriteActive(face, 0);
        }
        RefreshFaceSprite(face);
        index++;
    } while (2 > index);
    UpdateScenePanelPalette(panel);
}

void func_02097aa8(void) {

}

/* Clears the interior rows (all but the top and bottom border) of a scene
 * panel's 32-column tilemap, once per 3D-sprite engine the screen target
 * selects. */
void ClearTilemapRows(s32 tilemapAddress, u8 rowPairs) {
    s32 Get3DSpriteTarget();
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    void *savedEngine;
    void *engine;
    s32 engineIndex;
    u16 *tilemap;
    s32 endRow;
    s32 col;
    s32 row;

    savedEngine = gCur3DSpriteEngine;
    endRow = rowPairs * 2 + 1;
    tilemap = (u16 *)tilemapAddress;
    engineIndex = 0;
    do {
        if (engineIndex == 0) engine = g3DSpriteEngineMain;
        else engine = g3DSpriteEngineSub;
        gCur3DSpriteEngine = engine;
        if (((Get3DSpriteTarget() != DS3D_TARGET_MAIN) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) &&
            ((Get3DSpriteTarget() != DS3D_TARGET_SUB) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) &&
            ((Get3DSpriteTarget() != DS3D_TARGET_ACTIVE) || (gCur3DSpriteEngine == savedEngine))) {
            for (row = 1; row < endRow; row++) {
                for (col = 0; col < SCENE_PANEL_TILE_COLUMNS; col++) {
                    tilemap[row * SCENE_PANEL_TILE_COLUMNS + col] = 0;
                }
            }
        }
        engineIndex++;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Clear the tile rows of scene panel `panelIndex`'s message area: the panel's
 * tilemap starts at its message text line, and the 3D-sprite manager gives the
 * number of text row pairs to clear. */
void ClearScenePanelRows(s32 panelIndex) {
    s32 *GetScenePanelState();
    s32 GetScenePanelTextLineX(s32);
    void ClearTilemapRows(s32, u8);
    ScenePanelState *panelState;
    s32 textLineX;

    panelState = (ScenePanelState *) GetScenePanelState(panelIndex);
    textLineX = GetScenePanelTextLineX(panelIndex);
    ClearTilemapRows((s32) panelState->tiles + (textLineX * 2), M2C_FIELD(Get3DSpriteManager(), u8 *, DS3D_MANAGER_PANEL_ROW_PAIRS));
}

/* Returns nonzero while any of the three scene panels or their two child
 * sprites is still animating. */
s32 IsAnyScenePanelAnimating(void) {
    s32 Is3DSpriteAnimating(s32);
    s32 panelIndex, panel, childIndex;
    panelIndex = 0;
    do {
        panel = FindScenePanel((u16)panelIndex);
        if (panel) {
            if (Is3DSpriteAnimating(panel)) return 1;
            childIndex = 0;
            do {
                if (Is3DSpriteAnimating(Get3DSpriteChild(panel, childIndex))) return 1;
                childIndex++;
            } while (childIndex < 2);
        }
        panelIndex++;
    } while (panelIndex < 3);
    return 0;
}

