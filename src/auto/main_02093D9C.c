/* 57 functions from 0x02093D9C to 0x02094D8C (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"

void *Get3DSpriteManager(void);

/* Map-script command that restores the battle map view and/or the sub-screen UI,
 * depending on which 3D sprite engine the scene is drawn into: the main engine
 * gets the map view back, the sub engine its UI, and both get both.  Target
 * DS3D_TARGET_ACTIVE means whichever engine the current one is. */
s32 ScriptCmd_RestoreMapView(void *script) {
    s32 Get3DSpriteTargetMode();
    M2C_UNK RestoreBattleMapView();
    M2C_UNK CreateSubScreenUi();
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 target;
    u8 isMain;

    target = Get3DSpriteTargetMode();
    if (target == DS3D_TARGET_ACTIVE) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            target = DS3D_TARGET_SUB;
        } else {
            target = DS3D_TARGET_MAIN;
        }
    }
    switch (target) {
    case DS3D_TARGET_MAIN:
        RestoreBattleMapView();
        break;
    case DS3D_TARGET_SUB:
        CreateSubScreenUi();
        break;
    case DS3D_TARGET_BOTH:
        RestoreBattleMapView();
        CreateSubScreenUi();
        break;
    }
    M2C_FIELD(script, s32 *, 4) = (s32) (M2C_FIELD(script, s32 *, 4) + 0x10);
    return 1;
}

/* Map-script command: queue a pulsating target-area rectangle (MAPORDER_EFFECT_AREA)
 * on the command's tile (s16 at +0x08, x in the low byte) with its size (s16 at
 * +0x0A, width in the low byte) and value (+0x0C), then advance the script. */
s32 ScriptCmd_AddEffectArea(void *script) {
    M2C_UNK AddMapOrder(u8, u8, u8, u8, s32, s32, s32, s32);
    s16 wh;
    s16 xy;
    void *command;

    command = M2C_FIELD(script, void **, 4);
    wh = M2C_FIELD(command, s16 *, 0xA);
    xy = M2C_FIELD(command, s16 *, 8);
    AddMapOrder((u8) xy, (u8) (xy >> 8), (u8) wh, (u8) (wh >> 8), MAPORDER_EFFECT_AREA, 0, 0, M2C_FIELD(command, s32 *, 0xC));
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: drop the pulsating target-area rectangle
 * (MAPORDER_EFFECT_AREA) from the command's tile (s16 at +0x08, x in the low
 * byte), then advance the script. */
s32 ScriptCmd_RemoveEffectArea(void *script) {
    s32 FindMapOrderOfTypeAt(u8, u8, M2C_UNK);
    M2C_UNK RemoveMapOrder();
    s16 tile;

    tile = M2C_FIELD(M2C_FIELD(script, void **, 4), s16 *, 8);
    if (FindMapOrderOfTypeAt((u8) tile, (u8) (tile >> 8), MAPORDER_EFFECT_AREA) != 0) {
        RemoveMapOrder();
    }
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: place a map cursor on the command's tile - the s16 at +0x08
 * packs x and y and the word at +0x0C is the cursor kind.  Cursor kind 6 also
 * starts its repeating sound (0x10025, every 0x16 frames).  Advances the script. */
s32 ScriptCmd_PlaceMapCursor(void *script) {
    M2C_UNK AddMapOrder(u8, u8, u8, u8, s32, s32, s32, s32);
    M2C_UNK StartLoopingSoundEffect(s32, M2C_UNK);
    s16 tile;
    s32 kind;
    void *command;

    command = M2C_FIELD(script, void **, 4);
    tile = M2C_FIELD(command, s16 *, 8);
    kind = M2C_FIELD(command, s32 *, 0xC);
    AddMapOrder((u8) tile, (u8) (tile >> 8), 1, 1, MAPORDER_CURSOR, 0, 0, kind);
    if (kind == 6) {
        StartLoopingSoundEffect(0x10025, 0x16);
    }
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: take the map cursor back off the command's tile (s16 at
 * +0x08, x in the low byte), dropping its MAPORDER_CURSOR order if one is there,
 * and stop the looping cursor sound.  Advances the script. */
s32 ScriptCmd_RemoveMapCursor(void *script) {
    s32 FindMapOrderOfTypeAt(u8, u8, M2C_UNK);
    M2C_UNK RemoveMapOrder();
    M2C_UNK StopLoopingSoundEffects();
    s16 tile;

    tile = M2C_FIELD(M2C_FIELD(script, void **, 4), s16 *, 8);
    if (FindMapOrderOfTypeAt((u8) tile, (u8) (tile >> 8), MAPORDER_CURSOR) != 0) {
        RemoveMapOrder();
    }
    StopLoopingSoundEffects();
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: stop every looping sound effect, then advance to the next command. */
s32 MapScriptStopLoopingSoundEffects(void *state) {
    StopLoopingSoundEffects();
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: queue a 3x3 area attack centred on the tile given by the
 * command's two s16 operands (x, y) for the player in its s32 operand, then
 * advance the script. */
s32 ScriptCmd_AddAreaAttack(void *script) {
    M2C_UNK AddAreaAttackOrder(s16, s16, s32);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    AddAreaAttackOrder(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: queue a point-attack area (MAPORDER_ATTACK_POINT) on the
 * command's tile (s16 at +0x08, x in the low byte) with its size (s16 at +0x0A,
 * width in the low byte) and value (+0x0C); the word at +0x04 picks the
 * player-facing variant.  Then advance the script. */
s32 ScriptCmd_AddPointAttackArea(void *script) {
 M2C_UNK AddPointAttackOrder(u8,u8,s32,u8,u8);
 M2C_UNK AddFacingPointAttackOrder(u8,u8,s32,u8,u8);
 s16 size, tile;
 void *command;
 u8 x,y,w,h;
 s32 val;
 command=M2C_FIELD(script,void **,4);
 size=M2C_FIELD(command,s16 *,0xA);
 tile=M2C_FIELD(command,s16 *,8);
 y=(u8)(tile>>8);
 w=(u8)size;
 x=(u8)tile;
 h=(u8)(size>>8);
 val=M2C_FIELD(command,s32 *,0xC);
 if(M2C_FIELD(command,s32 *,4)==0) AddPointAttackOrder(x,y,val,w,h);
 else AddFacingPointAttackOrder(x,y,val,w,h);
 M2C_FIELD(script,void **,4)+=0x10;
 return 1;
}

/* Map-script command: queue a line-attack area on the command's tile (s16 at
 * +0x08, x in the low byte) with its size (s16 at +0x0A, width in the low byte)
 * and value (+0x0C); the word at +0x04 picks the player-facing variant.  Then
 * advance the script. */
s32 ScriptCmd_AddLineAttackArea(void *script) {
 M2C_UNK AddLineAttackOrder(u8,u8,s32,u8,u8);
 M2C_UNK AddFacingLineAttackOrder(u8,u8,s32,u8,u8);
 s16 size, tile;
 void *command;
 u8 x,y,w,h;
 s32 val;
 command=M2C_FIELD(script,void **,4);
 size=M2C_FIELD(command,s16 *,0xA);
 tile=M2C_FIELD(command,s16 *,8);
 y=(u8)(tile>>8);
 w=(u8)size;
 x=(u8)tile;
 h=(u8)(size>>8);
 val=M2C_FIELD(command,s32 *,0xC);
 if(M2C_FIELD(command,s32 *,4)==0) AddLineAttackOrder(x,y,val,w,h);
 else AddFacingLineAttackOrder(x,y,val,w,h);
 M2C_FIELD(script,void **,4)+=0x10;
 return 1;
}

/* Map-script command: add the amount at MAP_SCRIPT_OPERAND2 to the funds of the
 * player named by MAP_SCRIPT_OPERAND0, then advance to the next command. */
s32 MapScriptAddFunds(void *state) {
    M2C_UNK AddPlayerFunds(s16, s32);
    void *command;

    command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    AddPlayerFunds(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: show the localized text the command names at
 * MAP_SCRIPT_OPERAND2 in the telop (caption) window, then advance the script. */
s32 ScriptCmd_ShowTelopText(void *script) {
    M2C_UNK GetLocalizedText(s32);
    M2C_UNK ShowTelopText();
    GetLocalizedText(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2));
    ShowTelopText();
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: delete the caption (telop) window, advance to the next
 * command, and keep the script running. */
s32 MapScriptDeleteTelopWindow(void *state) {
    M2C_UNK DeleteTelopWindow();

    DeleteTelopWindow();
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: show the UI message whose text id is at +0x0C of the
 * command, in the message-box style at +0x08 (0..2), unless a message box is
 * already active; then advance the script. */
s32 ScriptCmd_ShowMessage(void *script) {
    M2C_UNK ShowUiMessage(s32);
    M2C_UNK ShowUiMessageStyle1(s32);
    M2C_UNK ShowUiMessageStyle2(s32);
    s16 style;
    void *command;

    if (IsMessageBoxActive() == 0) {
        command = M2C_FIELD(script, void **, 4);
        style = M2C_FIELD(command, s16 *, 8);
        switch (style) {                          /* irregular */
        case 0:
            ShowUiMessage(M2C_FIELD(command, s32 *, 0xC));
            break;
        case 1:
            ShowUiMessageStyle1(M2C_FIELD(command, s32 *, 0xC));
            break;
        case 2:
            ShowUiMessageStyle2(M2C_FIELD(command, s32 *, 0xC));
            break;
        }
    }
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 0;
}

/* Map-script command: forbid building the unit kind named by the command's +0x0C
 * operand by setting that kind's MAPCONFIG_UNBUILDABLE_KINDS bit, then advance
 * the script. */
s32 ScriptCmd_AddUnbuildableKind(void *script) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s32 *, MAPCONFIG_UNBUILDABLE_KINDS) = (s32) (M2C_FIELD(&gMapConfig, s32 *, MAPCONFIG_UNBUILDABLE_KINDS) | (1 << (u8) M2C_FIELD(M2C_FIELD(script, void **, 4), s32 *, 0xC)));
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: allow building the unit kind named by the command's +0x0C
 * again by clearing that kind's MAPCONFIG_UNBUILDABLE_KINDS bit, then advance the
 * script. */
s32 ScriptCmd_RemoveUnbuildableKind(void *script) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s32 *, MAPCONFIG_UNBUILDABLE_KINDS) = (s32) (M2C_FIELD(&gMapConfig, s32 *, MAPCONFIG_UNBUILDABLE_KINDS) & (-1 ^ (1 << (u8) M2C_FIELD(M2C_FIELD(script, void **, 4), s32 *, 0xC))));
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 1;
}

s32 func_02094214(void *arg0) {
 M2C_UNK func_0207843c(s32,s32,s32,s32);
 s16 TerrainByteToTileId(s32);
 extern s32 *data_027e0058;
 s16 packed;
 s32 base,base2;
 s32 x,y,value;
 void *cmd;
 cmd=M2C_FIELD(arg0,void **,4);
 packed=M2C_FIELD(cmd,s16 *,8);
 value=M2C_FIELD(cmd,s32 *,0xC);
 y=(u8)(packed>>8);
 base=*data_027e0058;
 x=(u8)packed;
 M2C_FIELD(base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)),s8 *,0x1420)=value;
 base2=*data_027e0058;
 M2C_FIELD(base2+(x+M2C_FIELD(base2+y*2,u16 *,0x3758))*2,s16 *,0xA10)=TerrainByteToTileId(value);
 func_0207843c(x-1,y-1,x+1,y+1);
 M2C_FIELD(arg0,void **,4)+=0x10;
 return 1;
}

/* Map-script command: while a message box is up, seek forward command by command
 * to the next message command (MAP_SCRIPT_OP_MESSAGE) or to the end of the script
 * (MAP_SCRIPT_OP_END); with no message box up, just advance one command. */
s32 ScriptCmd_SkipToNextMessage(void *script) {
    M2C_UNK IsMessageBoxActive();
    s32 opcode;

    if (IsMessageBoxActive() != 0) {
        do {
            opcode = *M2C_FIELD(script, s32 **, MAP_SCRIPT_STATE_IP);
            switch (opcode) {
            case MAP_SCRIPT_OP_MESSAGE:
                return 1;
            case MAP_SCRIPT_OP_END:
                return 1;
            default:
                M2C_FIELD(script, s32 **, MAP_SCRIPT_STATE_IP) += 4;
                break;
            }
        } while (1);
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: no-op command (a second opcode slot with the same body as
 * MapScriptNoOp), just advance to the next command and keep running. */
s32 MapScriptNoOp2(void *state) {
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: close the message box when one is up, then advance the
 * script and keep running. */
s32 ScriptCmd_CloseMessageBox(void *script) {
    if (IsMessageBoxActive() != 0) {
        SetMessageBoxState(0);
    }
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: while no message box is showing, clear the box's state
 * (which also cancels its idle/closing animation), then advance the script and
 * keep running. */
s32 ScriptCmd_CancelMessageBoxClose(void *script) {
    if (IsMessageBoxActive() == 0) {
        SetMessageBoxState(0);
    }
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: mark the message box suppressed (MESSAGE_BOX_STATE_SUPPRESSED,
 * the text could not be shown), then advance the script and keep running. */
s32 ScriptCmd_SuppressMessageBox(void *script) {
    SetMessageBoxState(MESSAGE_BOX_STATE_SUPPRESSED);
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Point the menu cursor at message panel `panel` in the 3D sprite manager
 * (negative clears it); GetMenuCursor reads the same byte. */
void SetMenuCursor(s8 panel) {
    void *Get3DSpriteManager();
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_MENU_CURSOR) = panel;
}

/* Choose the screen (DS3D_TARGET_*) the 3D sprite system creates its sprites on. */
void Set3DSpriteTargetMode(s8 target) {
    void *Get3DSpriteManager(void);
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_TARGET_MODE) = target;
}

/* Draw the 3D sprites on the sub engine (DS3D_TARGET_SUB). */
void Set3DSpriteTargetSub(void) {
    Set3DSpriteTargetMode(DS3D_TARGET_SUB);
}

/* Store the 3D sprite manager's byte at DS3D_MANAGER_UNK_48 (reset to 0 when the
 * dialog UI is reset); what the byte selects is not known yet. */
void SetManagerUnk48(s8 value) {
    void *Get3DSpriteManager(void);
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_UNK_48) = value;
}

/* Remember the screen mode the other screen shows for 3D sprite engine `engine`
 * in the manager's per-engine DS3D_MANAGER_OTHER_SCREEN_MODE bytes. */
void StoreOtherScreenMode(s32 engine, s8 mode) {
    void *Get3DSpriteManager();

    M2C_FIELD(Get3DSpriteManager() + engine, s8 *, DS3D_MANAGER_OTHER_SCREEN_MODE) = mode;
}

/* Pick the palette style (FACE_PALETTE_*) applied to the CO face sprites. */
void SetFacePaletteStyle(s8 style) {
    void *Get3DSpriteManager();
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_FACE_PALETTE_STYLE) = style;
}

/* Resets both 3D sprite engines (main and sub) and, for each, points the three
 * layer records at its tile memory and reinitialises the three layers. */
void Reset3DSpriteEngines(void) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 g3DSpriteEngineSub;
    M2C_UNK Get3DSpriteCount(void);
    M2C_UNK Get3DSpriteTarget(void);
    void *Get3DSpriteManager(void);
    M2C_UNK SetMessagePanelRowPairs(M2C_UNK);
    M2C_UNK SetMessagePanelLayout(M2C_UNK);
    M2C_UNK SetScenePanelTileAttr(M2C_UNK, M2C_UNK);
    M2C_UNK SetScenePanelPaletteSlot(M2C_UNK, M2C_UNK);
    M2C_UNK SetScenePanelMode(M2C_UNK, M2C_UNK);
    M2C_UNK SetPanelFaceHidden(M2C_UNK, M2C_UNK);

    s32 savedEngine;
    s32 engineIndex;
    s32 layer;
    s32 tileBase;

    savedEngine = gCur3DSpriteEngine;
    for (engineIndex = 0; engineIndex < 2; engineIndex = engineIndex + 1) {
        gCur3DSpriteEngine = (engineIndex == 0) ? g3DSpriteEngineMain : g3DSpriteEngineSub;

        if (((Get3DSpriteTarget() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) &&
            ((Get3DSpriteTarget() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) &&
            ((Get3DSpriteTarget() != 3) || (gCur3DSpriteEngine == savedEngine))) {
            SetMessagePanelRowPairs(2);
            SetMessagePanelLayout(1);

            M2C_FIELD(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0), u16 *, 0x3A) = 0;
            M2C_FIELD(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0), u16 *, 0x42) = 0;

            switch (Get3DSpriteCount()) {
            case 2: {
                void *manager;
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0);
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0xC) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0);
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0x18) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x480);
                break;
            }
            case 0:
            case 1: {
                void *manager;
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x40);
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0xC) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x240);
                manager = Get3DSpriteManager();
                M2C_FIELD(manager, void **, 0x18) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x440);
                break;
            }
            }

            tileBase = 0x124;
            for (layer = 0; layer < 3; layer = layer + 1) {
                SetScenePanelTileAttr(layer, tileBase);
                SetScenePanelPaletteSlot(layer, layer);
                SetScenePanelMode(layer, 0);
                SetPanelFaceHidden(layer, 0);
                tileBase = tileBase + 0x80;
            }
        }
    }

    gCur3DSpriteEngine = savedEngine;
}

void EnableTouchInput(void);
/* Resets the message/dialog overlay, e.g. when a message box or the map setup is
 * finished: clears every dialog sequence (gDialogSequences), empties the 3D sprite
 * manager's pending-message queue, resets the three scene panels and the menu
 * cursor, and reinitialises the 3D sprite engines. */
void ResetDialogUI(void) {
 extern M2C_UNK gDialogSequences;
 void *GetScenePanelState(s32);
 s16 i; u8 *ptr;
 M2C_FIELD(Get3DSpriteManager(),u8*,0x4b)=0;
 ptr=(u8*)&gDialogSequences;
 for(i=0;i<8;i++,ptr+=0x18)*(s32*)ptr=0;
 for(i=0;i<8;) { ptr=Get3DSpriteManager(); ptr+=(u32)i*4; i++; M2C_FIELD(ptr,s32*,0x24)=0; }
 ClearEventFlagsLow();EnableTouchInput();ClearMessageBoxState();
 for(i=0;i<3;i++)M2C_FIELD(GetScenePanelState(i),s16*,8)=0;
 for(i=0;i<2;i++)StoreOtherScreenMode(i,2);
 SetMenuCursor(-1);Set3DSpriteTargetMode(3);SetManagerUnk48(0);SetFacePaletteStyle(0);Reset3DSpriteEngines();
}

/* Whether one of the game's dialog sequences (gDialogSequences) is running. */
s32 IsDialogActive(void) {
    extern M2C_UNK gDialogSequences;
    s32 i;
    u8 *slot;

    slot = (u8 *)&gDialogSequences;
    i = 0;
    do {
        if (M2C_FIELD(slot, s32 *, 0)) return 1;
        i++;
        slot += DIALOG_SEQUENCE_STRIDE;
    } while (i < DIALOG_SEQUENCE_COUNT);
    return 0;
}

/* Whether a dialog sequence running `sequence` occupies one of the dialog slots. */
u8 IsDialogSequenceActive(void *sequence) {
    s32 FindDialogSequence();
    u8 active;

    if (FindDialogSequence(sequence) != -1) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Find the gDialogSequences slot whose script is `script` (0 finds a free slot),
 * or -1 when no slot matches. */
s32 FindDialogSequence(s32 script) {
    extern M2C_UNK gDialogSequences;
    s32 slot;
    u8 *base;
    base = (u8 *)&gDialogSequences;
    slot = 0;
    do {
        if (M2C_FIELD(base, s32 *, 0) == script) return slot;
        slot++;
        base += DIALOG_SEQUENCE_STRIDE;
    } while (slot < DIALOG_SEQUENCE_COUNT);
    return -1;
}

/* Raise the 3D sprite manager's dialog-suspend count: while it is nonzero the
 * message overlay stays suspended for the dialogs in flight. */
void SuspendDialogs(void) {
 void *Get3DSpriteManager(void);
 void *manager=Get3DSpriteManager();
 M2C_FIELD(manager,s8 *,DS3D_MANAGER_DIALOG_SUSPEND_COUNT)++;
}

/* Let the message overlay resume: drop the count of dialogs that suspended it. */
void ResumeDialogs(void) {
    void *Get3DSpriteManager(void);
    void *manager = Get3DSpriteManager();
    M2C_FIELD(manager, s8 *, DS3D_MANAGER_DIALOG_SUSPEND_COUNT)--;
}

u8 GetDialogSuspendCount(void) {
    void *Get3DSpriteManager();
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x4B);
}

/* Turn stylus input off: the map/touch handlers ignore the stylus until
 * EnableTouchInput clears the manager's flag again. */
void DisableTouchInput(void) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_TOUCH_DISABLED) = 1;
}

/* Turn stylus input back on after DisableTouchInput. */
void EnableTouchInput(void) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_TOUCH_DISABLED) = 0;
}

u8 IsTouchInputDisabled(void) {
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x47);
}

/* End a dialog sequence: free its gDialogSequences slot and, once no other
 * dialog sequence is running, re-enable touch input, clear the message box, start
 * the next queued dialog, and drop this sequence's hold on the map view. */
void EndDialogSequence(DialogSequence *sequence) {
    s32 IsDialogActive();
    void StartNextQueuedDialog(void);
    M2C_UNK ClearMessageBoxState();
    M2C_UNK ReleaseMapViewHold();

    if (sequence->script == 0) {
        return;
    }
    sequence->script = 0;
    if (IsDialogActive() == 0) {
        EnableTouchInput();
        ClearMessageBoxState();
        StartNextQueuedDialog();
    }
    ReleaseMapViewHold();
}

/* Queue a dialog script: run it at once when no dialog sequence is active,
 * otherwise store it in the 3D sprite manager's first free pending-dialog slot. */
void QueueDialogSequence(s32 script) {
    void *StartDialogSequence(s32);
    s32 slot;

    if (!IsDialogActive()) {
        StartDialogSequence(script);
        return;
    }
    for (slot = 0; slot < DS3D_DIALOG_QUEUE_COUNT; slot++) {
        if (!M2C_FIELD(Get3DSpriteManager() + (u32)slot * 4, s32 *, DS3D_MANAGER_DIALOG_QUEUE)) {
            M2C_FIELD(Get3DSpriteManager() + (u32)slot * 4, s32 *, DS3D_MANAGER_DIALOG_QUEUE) = script;
            return;
        }
    }
}

/* Starts the script at the head of the 3D sprite manager's pending-dialog queue,
 * then shifts the rest of the queue down and clears its last slot. */
void StartNextQueuedDialog(void) {
   void *StartDialogSequence(s32);
 s32 slot;
 void *manager;
 if(!M2C_FIELD(Get3DSpriteManager(),s32 *,DS3D_MANAGER_DIALOG_QUEUE)) return;
 StartDialogSequence(M2C_FIELD(Get3DSpriteManager(),s32 *,DS3D_MANAGER_DIALOG_QUEUE));
 slot=0;
 do {
 manager=Get3DSpriteManager();
 M2C_FIELD(manager+((u32)slot*4),s32 *,DS3D_MANAGER_DIALOG_QUEUE)=M2C_FIELD(Get3DSpriteManager()+((u32)(slot+1)*4),s32 *,DS3D_MANAGER_DIALOG_QUEUE);
 slot++;
 }while(slot<DS3D_DIALOG_QUEUE_COUNT-1);
 M2C_FIELD(Get3DSpriteManager()+((u32)slot*4),s32 *,DS3D_MANAGER_DIALOG_QUEUE)=0;
}

#pragma optimization_level 2
void *StartDialogSequence(s32 arg0) {
s32 FindDialogSequence(s32);
void SetMenuCursor(s8); void Set3DSpriteTargetMode(s8);void SetManagerUnk48(s8);void SetFacePaletteStyle(s8);
M2C_UNK ClearMessageBoxState(void);void DisableTouchInput(void);void AcquireMapViewHold(void);
extern M2C_UNK gDialogSequences,data_02157fec,data_02157ff0,data_02157ff4;
s16 index; s32 offset; u8 *base;
index=FindDialogSequence(0);
if(index==-1)return NULL;
SetMenuCursor(-1);Set3DSpriteTargetMode(3);SetManagerUnk48(0);SetFacePaletteStyle(0);
ClearMessageBoxState();DisableTouchInput();AcquireMapViewHold();
offset=index*24;
base=(u8 *)&gDialogSequences;
*(void **)(base+offset)=(void *)arg0;
*(s32 *)((u8 *)&data_02157ff0+offset)=0;
*(void **)((u8 *)&data_02157fec+offset)=(void *)arg0;
*(u16 *)((u8 *)&data_02157ff4+offset)=0;
return base+offset;
}
#pragma optimization_level reset
void StepDialogSequence(void *arg0) {
    s32 TryStartDialogSkip(void);
    extern void *data_02102b50[];
    void **p;
    int temp;
    s32 (*fn)(void *);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    if (M2C_FIELD(arg0, u16 *, 0xC) != 0) {
        if (TryStartDialogSkip() != 0) temp = 0;
        else temp = M2C_FIELD(arg0, u16 *, 0xC) - 1;
        M2C_FIELD(arg0, u16 *, 0xC) = (u16) temp;
        if (M2C_FIELD(arg0, u16 *, 0xC) != 0) return;
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0) return;
    if (M2C_FIELD(arg0, void **, 4) == NULL) return;
loop:
    p = M2C_FIELD(arg0, void **, 4);
    fn = (s32 (*)(void *)) data_02102b50[*(s32 *) p];
    if (!fn) goto advance;
    if (fn(arg0) == 0) return;
    goto loop;
advance:
    M2C_FIELD(arg0, void **, 4) = (void *) ((u8 *) M2C_FIELD(arg0, void **, 4) + 0x10);
    goto loop;
}
#pragma scheduling on
/* Per-frame update of the active dialog scripts: skipped while another dialog
 * update is suspended, the map view is scrolling or a UI mode change is running.
 * Each active sequence runs its wait callback and then steps its command script. */
void UpdateDialogSequences(void) {
    s32 IsMapViewScrolling();
    void StepDialogSequence(void *);
    s32 IsUiModeSwitchBusy();
    extern M2C_UNK gDialogSequences;
    DialogSequence *sequence;
    s32 i;

    if (IsDialogActive() == 0) {
        return;
    }
    if (GetDialogSuspendCount() != 0) {
        return;
    }
    if (IsMapViewScrolling() != 0) {
        return;
    }
    if (IsUiModeSwitchBusy() != 0) {
        return;
    }
    sequence = (DialogSequence *) &gDialogSequences;
    i = 0;
    do {
        if (sequence->script != 0) {
            if (sequence->wait != NULL) {
                sequence->wait(sequence);
            }
            StepDialogSequence(sequence);
        }
        i += 1;
        sequence += 1;
    } while (i < DIALOG_SEQUENCE_COUNT);
}

/* Bring scene panel `panelIndex` on screen, unless a message box is up: while one
 * is shown the panels belong to it. */
void ShowScenePanelUnlessMessageBox(s32 panelIndex) {
    s32 IsMessageBoxActive();
    s32 ShowScenePanel(s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ShowScenePanel(panelIndex);
}

/* Close the scene panel `panelIndex`.  While a message box is up, close every
 * open panel instead, so the box is not left over panel contents. */
void CloseScenePanel(s32 panelIndex) {
    void *GetScenePanelState(s32);
    M2C_UNK HideScenePanel(s32);
    s32 index;

    if (IsMessageBoxActive() != 0) {
        index = 0;
        do {
            if (((ScenePanelState *) GetScenePanelState(index))->contentHeight != 0) {
                HideScenePanel(index);
            }
            index += 1;
        } while (index < SCENE_PANEL_CURRENT);
        return;
    }
    if (((ScenePanelState *) GetScenePanelState(panelIndex))->contentHeight == 0) {
        return;
    }
    HideScenePanel(panelIndex);
}

/* Set the face (identity and expression) shown by scene panel `panelIndex`,
 * unless a message box is up: while one is shown the panels belong to it. */
void SetScenePanelFaceUnlessMessageBox(s32 panelIndex, s32 faceId, s32 expression) {
    M2C_UNK SetScenePanelFace(M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelFace(panelIndex, faceId, expression);
}

/* Scene-panel operation: give scene panel `panelIndex` the army (colour) `army`,
 * unless a message box is up: a dialog owns the panels, so the change is dropped.
 * Forwards to func_02097aa8, a no-op stub in this build, so it changes nothing. */
void SetScenePanelArmyUnlessMessageBox(s32 panelIndex, s32 army) {
    M2C_UNK func_02097aa8(s32, s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_02097aa8(panelIndex, army);
}

/* Set scene panel `panelIndex` to `mode`, unless a message box is up: while one
 * is shown the panels belong to it. */
void SetScenePanelModeUnlessMessageBox(s32 panelIndex, s32 mode) {
    M2C_UNK SetScenePanelMode(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelMode(panelIndex, mode);
}

/* Hide or show the face of scene panel `panelIndex` according to `hidden`, unless
 * a message box is up: while one is shown the panels belong to it. */
void SetPanelFaceHiddenUnlessMessageBox(s32 panelIndex, s32 hidden) {
    M2C_UNK SetPanelFaceHidden(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetPanelFaceHidden(panelIndex, hidden);
}

/* Clear the tile rows of scene panel `panelIndex`, unless a message box is up:
 * while one is shown the panels belong to it. */
void ClearScenePanelRowsUnlessMessageBox(s32 panelIndex) {
    void ClearScenePanelRows(s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ClearScenePanelRows(panelIndex);
}

/* Show the face in slot `faceIndex` of the scene panel, unless a message box is
 * up: while one is shown the panels belong to it. */
void ShowPanelFaceUnlessMessageBox(s32 faceIndex) {
    void ShowPanelFace(s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ShowPanelFace(faceIndex);
}

/* Hide the face in slot `faceIndex` of the scene panel, unless a message box is
 * up: while one is shown the panels belong to it. */
void HidePanelFaceUnlessMessageBox(s32 faceIndex) {
    void HidePanelFace(s32);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    HidePanelFace(faceIndex);
}

/* Dialog-script guard: while no message box is up, forward the script's four
 * operands to the scene-panel face operation func_02097410 (a no-op stub in
 * this build, so this command does nothing). */
void CallScenePanelFaceOp(M2C_UNK faceIndex, M2C_UNK value1, M2C_UNK value2, M2C_UNK value3) {
    M2C_UNK func_02097410(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_02097410(faceIndex, value1, value2, value3);
}

/* Update one scene-panel face slot (portrait slot, face id, expression) through
 * SetScenePanelFaceSlot, unless a message box is up: a running dialog owns the
 * panels, so the face update is dropped. */
void SetScenePanelFaceSlotUnlessMessageBox(M2C_UNK faceSlot, M2C_UNK faceId, M2C_UNK expression) {
    M2C_UNK SetScenePanelFaceSlot(M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelFaceSlot(faceSlot, faceId, expression);
}

/* Hide or show the face in slot `faceSlot` of the bottom scene panel according to
 * `hidden`, unless a message box is up: while one is shown the panels belong to it. */
void SetScenePanelFaceHiddenUnlessMessageBox(s32 faceSlot, s32 hidden) {
    M2C_UNK SetScenePanelFaceHidden(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelFaceHidden(faceSlot, hidden);
}

/* Builds a battle action entry for the given slot and submits it. */
void func_02094c90(s32 slot, s32 arg1) {
 extern s32 gCur3DSpriteEngine;
 s32 IsMessageBoxActive(); s32 HighlightScenePanel(); s32 GetMenuCursor(); s32 GetScenePanelTextLineX();
 void *GetScenePanelState(s32);
 s32 value; void *ptrA,*ptrB,*ptrC,*ptrD;
 if(IsMessageBoxActive()!=0)return;
 if(HighlightScenePanel(slot)!=1)return;
 HideMenuCursor(GetMenuCursor());
 if(GetMenuCursor()<0)return;
 if(GetMenuCursor()>=3)return;
 value=GetScenePanelTextLineX(3);
 ptrA=Get3DSpriteManager();ptrB=Get3DSpriteManager();ptrC=GetScenePanelState(3);ptrD=GetScenePanelState(3);
 SetTextObjectLine(arg1,(s16)value,1,M2C_FIELD(ptrA,u8*,0x4c),M2C_FIELD((u8*)gCur3DSpriteEngine+M2C_FIELD(ptrB,u8*,0x4c)*4,s32*,0xc),M2C_FIELD(ptrC,s32*,0),(u16)((M2C_FIELD(ptrD,u8*,6)&15)<<12),M2C_FIELD(GetScenePanelState(3),u16*,4));
}

