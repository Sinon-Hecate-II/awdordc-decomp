/* 71 functions from 0x02091E04 to 0x02092DF4 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"
extern u16 gPlayerUnitIdBase[];
extern void **gCurrentMap;

u8 GetFacePaletteStyle(void) {
    void *Get3DSpriteManager();
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x4E);
}

s32 Get3DSpriteTargetMode(void) {
    void *Get3DSpriteManager();
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x49);
}

/* Screen the 3D-sprite system draws on; when it targets both engines this
 * reports main (0), which the draw loop handles as its first pass. */
u8 Get3DSpriteTarget(void) {
    if (Get3DSpriteTargetMode() == DS3D_TARGET_BOTH) {
        return 0U;
    }
    return M2C_FIELD(Get3DSpriteManager(), u8 *, DS3D_MANAGER_TARGET_MODE);
}

void GetScriptTransitionTarget(void) {
    M2C_UNK Get3DSpriteTargetMode();
    Get3DSpriteTargetMode();
}

/* Index of the message panel the menu cursor is on: panel 2 while both screens
 * show a panel, otherwise the manager's stored cursor. */
s8 GetMenuCursor(void) {
    s32 Get3DSpriteCount();
    if (Get3DSpriteCount() == 2) {
        return 2;
    }
    return M2C_FIELD(Get3DSpriteManager(), s8 *, DS3D_MANAGER_MENU_CURSOR);
}

/* First cell x where the message text line of scene panel `panelIndex` starts: a
 * message drawn on a single screen starts at cell 2 in panel mode 1 and cell 8 in
 * panel mode 0; a message spanning both screens (or none) starts at cell 2; any
 * other sprite count starts at cell 0. */
s32 GetScenePanelTextLineX(s32 panelIndex) {
    s32 Get3DSpriteCount();
    ScenePanelState *panel;
    s32 spriteCount;
    u8 mode;
    panel = (ScenePanelState *)GetScenePanelState(panelIndex);
    spriteCount = Get3DSpriteCount();
    switch (spriteCount) {
    case 1:
        mode = panel->mode;
        if (mode == 1) return 2;
        if (mode == 0) return 8;
        break;
    case 0:
    case 2:
        return 2;
    }
    return 0;
}

/* Resolve a map-script player operand: MAP_SCRIPT_PLAYER_CURRENT stands for the
 * player whose turn it is, every other operand is already a player id. */
u16 MapScriptResolvePlayer(u16 playerId) {
    extern void **gCurrentMap;
    if (playerId != MAP_SCRIPT_PLAYER_CURRENT) {
        return playerId;
    }
    return M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER);
}

/* Return the number of text rows across the scene panels (two rows per row pair). */
s32 GetScenePanelRowCount(void) {
    return (M2C_FIELD(Get3DSpriteManager(), u8 *, DS3D_MANAGER_PANEL_ROW_PAIRS) * 2) + 2;
}

s32 func_02091f08(void) {
    s32 GetScenePanelRowCount();
    return GetScenePanelRowCount() * 8;
}

/* Pointer to the ScenePanelState of panel `panelIndex` among the 3D sprite
 * manager's panels; panel index DS3D_MANAGER_PANEL_COUNT means the panel the menu
 * cursor is on. */
s32 GetScenePanelState(s32 panelIndex) {
    s32 panel = panelIndex;

    if (panel == DS3D_MANAGER_PANEL_COUNT) {
        panel = GetMenuCursor();
    }
    return (panel * (s32) sizeof(ScenePanelState)) + Get3DSpriteManager();
}

/* Flag layer 0 of the current 3D sprite engine as changed, so the engine rebuilds
 * its tile data before the next draw. */
void Mark3DSpriteLayer0Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER0);
}

/* Flag layer 1 of the current 3D sprite engine as changed, so the engine
 * rebuilds that layer's tile data before the next draw. */
void Mark3DSpriteLayer1Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
}

/* Flag layer 2 of the current 3D sprite engine as changed, so the engine
 * rebuilds that layer's tile data before the next draw. */
void Mark3DSpriteLayer2Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER2);
}

/* Flag layer 3 of the current 3D sprite engine as changed, so the engine rebuilds
 * its tile data before the next draw. */
void Mark3DSpriteLayer3Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER3);
}

void Mark3DSpriteLayerNoneDirty(void) {

}

/* Return the marker for 3D sprite layer `layer`: Mark3DSpriteLayer<N>Dirty for
 * layers 0..3, the no-op Mark3DSpriteLayerNoneDirty for layer 4, and NULL for any
 * other layer.  The marker flags the layer's data changed when the layer is
 * rewritten in place. */
void (*Get3DSpriteLayerDirtyMarker(u32 layer))(void) {
    void Mark3DSpriteLayer1Dirty(void);
    void Mark3DSpriteLayer2Dirty(void);
    switch (layer) {
    case 0: return Mark3DSpriteLayer0Dirty;
    case 1: return Mark3DSpriteLayer1Dirty;
    case 2: return Mark3DSpriteLayer2Dirty;
    case 3: return Mark3DSpriteLayer3Dirty;
    case 4: return Mark3DSpriteLayerNoneDirty;
    default: return 0;
    }
}

/* Map-script opcode (6): while no message box is up, set the sequence's delay
 * (MAP_SCRIPT_STATE_DELAY) from the command's wide operand, then advance to the
 * next command. */
s32 MapScriptSetDelay(void *state) {
    s32 IsMessageBoxActive();
    if (IsMessageBoxActive() == 0) {
        M2C_FIELD(state, s16 *, MAP_SCRIPT_STATE_DELAY) = (s16) M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2);
    }
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* Script command: call the function the command carries at MAP_SCRIPT_PARAM,
 * passing the script state itself as its argument, then advance to the next
 * command.  Returns 1 while a script block is still loaded, 0 once it is
 * cleared. */
s32 MapScriptCallFunctionWithState(void *script) {
    s16 running;
    M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), void (**)(void *), MAP_SCRIPT_PARAM)(script);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    if (M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_BLOCK) != 0) {
        running = 1;
    } else {
        running = 0;
    }
    return running;
}

/* Map-script opcode: run the callback the command carries at MAP_SCRIPT_PARAM
 * with the command's wide operand (MAP_SCRIPT_OPERAND2), then advance to the next
 * command.  Returns 1 while a script block is still loaded, 0 once it is cleared. */
s16 MapScriptCallFunction(void *state) {
    void *command;
    s16 running;

    command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    M2C_FIELD(command, M2C_UNK (**)(s32), MAP_SCRIPT_PARAM)(M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    if (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_BLOCK) != 0) {
        running = 1;
    } else {
        running = 0;
    }
    return running;
}

/* Map-script wait callback: once the dialog sprite (gDialogSpriteClass) has gone,
 * clear the command's wait callback (MAP_SCRIPT_STATE_WAIT) to let the script run
 * on; until then the script stays on the command. */
void WaitForDialogSpriteGone(void *state) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gDialogSpriteClass;
    if (FindObjectByClass(&gDialogSpriteClass) == 0) {
        M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_WAIT) = 0;
    }
}

/* Dialog-script command: create the dialog sprite of class gDialogSpriteClass and
 * hand it to the command's setup callback (MAP_SCRIPT_PARAM), then keep this
 * sequence on the command until the sprite has gone. */
s32 DialogOpcodeCreateSprite(void *sequence) {
    M2C_UNK CreateSpriteFromClass(s32, s32);
    extern M2C_UNK gDialogSpriteClass;
    s32 sprite;
    sprite = CreateSpriteFromClass((s32)&gDialogSpriteClass, 7);
    M2C_FIELD(sequence, void (**)(void *), MAP_SCRIPT_STATE_WAIT) = WaitForDialogSpriteGone;
    M2C_FIELD(M2C_FIELD(sequence, void **, MAP_SCRIPT_STATE_IP), void (**)(s32), MAP_SCRIPT_PARAM)(sprite);
    M2C_FIELD(sequence, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(sequence, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* Map-script command: call the callback in the command's MAP_SCRIPT_PARAM word
 * each frame; stay on the command while it reports it is not done (nonzero),
 * then advance to the next command once it returns 0. */
s32 MapScriptWaitForCallback(void *script) {
    if (M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 (**)(), MAP_SCRIPT_PARAM)() != 0) {
        return 0;
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode (5): install the command's MAP_SCRIPT_PARAM as the
 * sequence's wait callback (MAP_SCRIPT_STATE_WAIT), advance to the next command,
 * and stop the script this frame until the callback clears the wait. */
s32 MapScriptSetWaitCallback(void *state) {
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_WAIT) = (s32) M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_PARAM);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* Map-script command: while no message box is up, call the command's callback
 * with the script state (MapScriptCallFunctionWithState runs the callback and
 * moves on); with a message box up, skip the command and keep running. */
s32 MapScriptCallFunctionUnlessMessageBox(void *script) {
    s32 MapScriptCallFunctionWithState(void *);
    if (IsMessageBoxActive() == 0) {
        return MapScriptCallFunctionWithState(script);
    }
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) = (s32)(M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

s32 func_020921b4(void) {
    M2C_UNK EndDialogSequence();
    EndDialogSequence();
    return 0;
}

s32 func_020921c4(void) {
    return 0;
}

/* Map-script opcode: store the command's wide operand (MAP_SCRIPT_OPERAND2) as a
 * byte at the address in MAP_SCRIPT_PARAM, then advance to the next command. */
s32 MapScriptSetVariableByte(void *script) {
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, s8 **, MAP_SCRIPT_PARAM) = (s8) M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: store the command's wide operand (MAP_SCRIPT_OPERAND2) as a
 * halfword at the address in MAP_SCRIPT_PARAM, then advance to the next command. */
s32 MapScriptSetVariableHalfword(void *script) {
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, s16 **, MAP_SCRIPT_PARAM) = (s16) M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: store the command's wide operand (MAP_SCRIPT_OPERAND2) as a
 * word at the address in MAP_SCRIPT_PARAM, then advance to the next command. */
s32 MapScriptSetVariableWord(void *script) {
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, s32 **, MAP_SCRIPT_PARAM) = M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: copy the byte that the command's wide operand points at
 * (MAP_SCRIPT_OPERAND2) into the variable whose address is in MAP_SCRIPT_PARAM,
 * then advance to the next command. */
s32 MapScriptCopyVariableByte(void *script) {
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, u8 **, MAP_SCRIPT_PARAM) = *M2C_FIELD(command, u8 **, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: copy the u16 that the command's MAP_SCRIPT_OPERAND2 points
 * at into the location the command's MAP_SCRIPT_PARAM points at, then advance to
 * the next command. */
s32 MapScriptCopyWordIndirect(void *state) {
    void *command;

    command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, u16 **, MAP_SCRIPT_PARAM) = *M2C_FIELD(command, u16 **, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: copy the s32 that the command's MAP_SCRIPT_OPERAND2 points
 * at into the location the command's MAP_SCRIPT_PARAM points at, then advance to
 * the next command. */
s32 MapScriptCopyDwordIndirect(void *state) {
    void *command;

    command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    *M2C_FIELD(command, s32 **, MAP_SCRIPT_PARAM) = *M2C_FIELD(command, s32 **, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script wait callback: clear the command's wait callback
 * (MAP_SCRIPT_STATE_WAIT) once the map view has finished scrolling, so the
 * script can run on; until then the script stays on the command. */
void OnMapScrollDone(void *state) {
    u8 IsMapViewScrolling(void);
    if (IsMapViewScrolling() == 0) {
        M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_WAIT) = 0;
    }
}

/* Map-script command: pan or step the map view to the tile the command's two
 * operands name (a nonzero third operand pans), then wait until the scroll has
 * finished before running the next command. */
s32 MapScriptMoveViewToTile(void *script) {
    s32 IsMessageBoxActive();
    M2C_UNK StepMapViewToTile(s16, s16);
    M2C_UNK PanMapViewToTile(s16, s16);
    void *command;

    if (IsMessageBoxActive() == 0) {
        command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
        if (M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2) != 0) {
            PanMapViewToTile(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1));
        } else {
            StepMapViewToTile(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1));
        }
        M2C_FIELD(script, void (**)(void *), MAP_SCRIPT_STATE_WAIT) = OnMapScrollDone;
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* Map-script command: set the map view to the tile the command's two operands
 * name, centring on the tile when the wide operand is nonzero, then go straight
 * on to the next command. */
s32 MapScriptSetViewToTile(void *script) {
    M2C_UNK SetMapViewToTile(s16, s16);
    M2C_UNK SetMapViewPositionToTileCentered(s16, s16);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    if (M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2) != 0) {
        SetMapViewPositionToTileCentered(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1));
    } else {
        SetMapViewToTile(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1));
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Script command: move the map view to the first unit of `kind` in the current
 * player's group (kind 0 matches any unit).  The view pans unless the command's
 * third word asks for an immediate step; the command then waits for the scroll. */
s32 MoveMapViewToPlayerUnit(void *ctx) {
    s32 IsMessageBoxActive(void);
    s32 PanMapViewToTile(s16, s16);
    s32 StepMapViewToTile(s16, s16);
    s32 i;
    void *cmd;
    u8 (*units)[MAP_UNIT_STRIDE];
    u8 *unit;
    u32 kind;

    if (!IsMessageBoxActive()) {
        cmd = M2C_FIELD(ctx, void **, 4);
        for (i = gPlayerUnitIdBase[M2C_FIELD(cmd, s16 *, 8)] + 1; i < gPlayerUnitIdBase[M2C_FIELD(cmd, s16 *, 8)] + MAP_UNIT_GROUP_SCAN; i++) {
            units = (void *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS);
            unit = units[i];
            kind = (u32)(M2C_FIELD(unit, u8 *, MAP_UNIT_KIND) << 26) >> 26;
            if (kind && (M2C_FIELD(cmd, s16 *, 10) == 0 || kind == M2C_FIELD(cmd, s16 *, 10))) {
                if (M2C_FIELD(cmd, s32 *, 12)) PanMapViewToTile(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y));
                else StepMapViewToTile(M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y));
                M2C_FIELD(ctx, void **, 8) = (void *)OnMapScrollDone;
                break;
            }
        }
    }
    M2C_FIELD(ctx, s32 *, 4) += 16;
    return 0;
}

/* Map-script command: create a 3D sprite of the class the command names at
 * MAP_SCRIPT_PARAM, in the mode at MAP_SCRIPT_OPERAND2, then advance to the next
 * command. */
s32 MapScriptCreateSprite(void *script) {
    M2C_UNK CreateSpriteFromClass(s32, s32);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    CreateSpriteFromClass(M2C_FIELD(command, s32 *, MAP_SCRIPT_PARAM), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: stay on the command while a live 3D sprite of the class
 * the command names at MAP_SCRIPT_PARAM exists, then advance to the next one. */
s32 WaitForObjectClassRemoved(void *script) {
    if (FindObjectByClass(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_PARAM)) != 0) {
        return 0;
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: wait until no 3D sprite of the command's class is left on
 * the main screen.  Returns 0 while one remains, 1 once it is gone. */
s32 WaitForMain3DSpriteRemoved(void *script) {
    s32 Find3DSpriteByClassOnCurrentEngine(s32);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 found;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    if (Find3DSpriteByClassOnCurrentEngine(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_PARAM)) != 0) {
        found = 1;
    } else {
        found = 0;
    }
    gCur3DSpriteEngine = savedEngine;
    if (found != 0) {
        return 0;
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Script command: look the command's 3D sprite id up in the sub engine and stay
   on the command until that sprite has gone, then advance the script. */
s32 Wait3DSpriteSubGone(void *ctx) {
    s32 Find3DSpriteByClassOnCurrentEngine(s32);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 found;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (Find3DSpriteByClassOnCurrentEngine(M2C_FIELD(M2C_FIELD(ctx, void **, 4), s32 *, 4)) != 0) {
        found = 1;
    } else {
        found = 0;
    }
    gCur3DSpriteEngine = savedEngine;
    if (found != 0) {
        return 0;
    }
    M2C_FIELD(ctx, void **, 4) = (void *) (M2C_FIELD(ctx, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: stay on the command while a 3D sprite of the class the
 * command names at MAP_SCRIPT_PARAM exists on the current engine, then advance
 * to the next command. */
s32 WaitFor3DSpriteClassRemoved(void *script) {
    s32 Find3DSpriteByClassOnCurrentEngine(s32);
    if (Find3DSpriteByClassOnCurrentEngine(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_PARAM)) != 0) {
        return 0;
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: switch the UI to the mode the command names in
 * MAP_SCRIPT_OPERAND0, then advance to the next command. */
s32 MapScriptSetUiMode(void *state) {
    M2C_UNK SetUiMode(s16, M2C_UNK);
    SetUiMode(M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0), 0);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: copy the command's wide operand into the map
 * configuration's map-specific value word (+4), then advance to the next
 * command and keep running. */
s32 MapScriptSetMapValue(void *state) {
    extern M2C_UNK gMapConfig;
    void *command;

    command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    M2C_FIELD(&gMapConfig, s16 *, MAPCONFIG_VALUE) = (s16) M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: clear the map-specific value (MAPCONFIG_VALUE) to 0, then
 * advance the sequence to the next command. */
s32 MapScriptClearMapValue(void *state) {
    extern M2C_UNK gMapConfig;

    M2C_FIELD(&gMapConfig, s16 *, MAPCONFIG_VALUE) = 0;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: create a unit of the command's kind on the command's tile
 * for the current player, then refresh the map view and advance the script. */
s32 MapScriptCreateOwnedUnit(void *state) {
    extern void **gCurrentMap;
    s32 CreateOwnedMapUnit(s32, s32, s32, s32);
    void RefreshMapView(s32);
    void *command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    RefreshMapView(CreateOwnedMapUnit(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2), M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER)));
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

/* Map-script command: enable touch input again, then advance to the next command. */
s32 MapScriptEnableTouchInput(void *state) {
    void EnableTouchInput(void);
    EnableTouchInput();
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode (20): disable touch input, advance to the next command, and
 * go straight on to it in the same frame. */
s32 MapScriptDisableTouchInput(void *state) {
    M2C_UNK DisableTouchInput();

    DisableTouchInput();
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Dialog-script command: end every dialog sequence except this one, so it runs
 * alone, then advance to the next command and keep running. */
s32 EndOtherDialogSequences(void *sequence) {
extern M2C_UNK gDialogSequences;
s32 EndDialogSequence();
s32 self=((s32)sequence-(s32)&gDialogSequences)/DIALOG_SEQUENCE_STRIDE;
u8 slot=0;
do {if(slot!=self)EndDialogSequence((u8 *)&gDialogSequences+slot*DIALOG_SEQUENCE_STRIDE);slot++;}while(slot<DIALOG_SEQUENCE_COUNT);
M2C_FIELD(sequence,s32 *,4)+=16;return 0;
}

/* Open a full-screen message box showing the localized text `textId`: reset the
 * text and sprite engines, then create the message sprite on each screen the
 * current 3D-sprite target requires. Returns 1 when the text could not be set up. */
s32 ShowMessageText(s32 textId) {
 s32 GetLocalizedText(s32); void Text_GetScreenCount(void); void func_020943e0(void); void Reset3DSpriteEngines(void);
 s32 Text_IsPlainMessage(s32); void SetMessageBoxState(s32); s32 IsMessageBoxActive(void);
 u8 Get3DSpriteTarget(void); s32 GetScenePanelTextLineX(s32); s32 Get3DSpriteManager(void); s32 GetScenePanelState(s32);
 s32 CreateMessageSprite(s32,s32,s32,s32,s32,s32,u16,u16);
 M2C_UNK MarkSpriteLayer1Dirty(void);
 extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain; extern void *g3DSpriteEngineSub;
 s32 text; void *savedEngine; s32 screen,style; void *managerA,*managerB,*layerA,*layerB,*layerC,*sprite; u32 attr;
 text=GetLocalizedText(textId);
 Text_GetScreenCount(); func_020943e0(); Reset3DSpriteEngines();
 if(Text_IsPlainMessage(text)==0){SetMessageBoxState(3);} if(IsMessageBoxActive()!=0)goto abort;
 savedEngine=gCur3DSpriteEngine;
 for(screen=0;screen<2;screen++){
 if(screen==0)gCur3DSpriteEngine=g3DSpriteEngineMain;else gCur3DSpriteEngine=g3DSpriteEngineSub;
 if(Get3DSpriteTarget()==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)goto next;
 if(Get3DSpriteTarget()==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)goto next;
 if(Get3DSpriteTarget()==3 && gCur3DSpriteEngine!=savedEngine)goto next;
 style=GetScenePanelTextLineX(2); managerA=(void *)Get3DSpriteManager();managerB=(void *)Get3DSpriteManager();
 layerA=(void *)GetScenePanelState(2);layerB=(void *)GetScenePanelState(2);layerC=(void *)GetScenePanelState(2);
 attr=M2C_FIELD(layerB,u8 *,6);attr=attr<<28;attr=attr>>16;
 sprite=(void *)CreateMessageSprite((s16)style,1,M2C_FIELD(managerA,u8 *,0x4c),
 M2C_FIELD((u8 *)gCur3DSpriteEngine+(M2C_FIELD(managerB,u8 *,0x4c)<<2),u32 *,12),
 M2C_FIELD(layerA,u32 *,0),text,(u16)attr,M2C_FIELD(layerC,u16 *,4));
 next:;
 }
 gCur3DSpriteEngine=savedEngine;M2C_FIELD(sprite,void (**)(void),0x50)=(void(*)(void))MarkSpriteLayer1Dirty;
 return 0;
abort: return 1;
}

/* Spawn the message-text sprite as a child of `parent`, the dialog sprite whose
 * state is showing the message (SpriteState_ShowMessage). */
void SpawnMessageTextSprite(M2C_UNK parent) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gMessageTextSpriteClass;
    CreateSpriteObject(&gMessageTextSpriteClass, parent);
}

/* Map-script wait callback: once the message text sprites have gone, clear the
 * command's wait callback (MAP_SCRIPT_STATE_WAIT) to let the script run on; until
 * then the script stays on the command. */
void WaitForMessageTextGone(void *state) {
    s32 IsTextSpriteActive();
    if (IsTextSpriteActive() == 0) {
        M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_WAIT) = 0;
    }
}

/* Map-script command: open a message box showing the localized text `textId` (the
 * command's wide operand, -1 meaning the current UI message) and, when it opened,
 * keep the script on this command until its message text sprite is gone.  Returns
 * the setup result sign-extended to 16 bits: 1 when no message could be shown. */
s32 MapScriptShowMessageText(M2C_UNK state, s32 textId) {
    s32 ShowMessageText(s32);
    void WaitForMessageTextGone(void *);
    s32 result = ShowMessageText(textId);
    if (result == 0) {
        M2C_FIELD(state, void (**)(void *), MAP_SCRIPT_STATE_WAIT) = WaitForMessageTextGone;
    }
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return (s16) result;
}

/* Map-script command: show the message text named by the current command's wide
 * operand (MAP_SCRIPT_OPERAND2), handing the wait to MapScriptShowMessageText. */
void MapScriptShowMessage(void *state) {
    MapScriptShowMessageText(state, M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2));
}

void func_02092908(M2C_UNK arg0) {
    M2C_UNK MapScriptShowMessageText(M2C_UNK, M2C_UNK);
    MapScriptShowMessageText(arg0, -1);
}

/* Map-script command: once no message box is up, clear the message panel's
 * rows (scene panel 3) and flag the first sprite layer for redraw.  Advances
 * the script; returns 1 while a message box is still up, otherwise 0. */
s32 MapScriptClearMessagePanel(void *state) {
    s32 IsMessageBoxActive();
    M2C_UNK ClearScenePanelRows(M2C_UNK);
    M2C_UNK MarkSpriteLayer1Dirty();
    s32 result;
    if (IsMessageBoxActive() != 0) {
        result = 1;
    } else {
        ClearScenePanelRows(3);
        MarkSpriteLayer1Dirty();
        result = 0;
    }
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return (s16)result;
}

/* Map-script command: load the UI graphics bank the command names at
 * MAP_SCRIPT_OPERAND2, then advance to the next command. */
s32 MapScriptLoadUiGraphicsBank(void *script) {
    M2C_UNK LoadUiGraphicsBank(u8);
    LoadUiGraphicsBank((u8) M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* Map-script command: free the UI graphics bank the command names at
 * MAP_SCRIPT_OPERAND2, then advance to the next command. */
s32 MapScriptFreeUiGraphicsBank(void *script) {
    M2C_UNK FreeUiGraphicsBank(u8);
    FreeUiGraphicsBank((u8) M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

/* List command: mark the highlighted row as chosen and, when the command's
 * third word names a screen, change to that screen through the screen-change
 * transition: ask for the transition's UI mode (2) and, once it is up, start the
 * split transition to that screen.  Returns 1 to run the next command at once,
 * 0 to run this one again next frame. */
s32 SelectListRow(void *ctx) {
M2C_UNK SetListRowFlag(u8,M2C_UNK);M2C_UNK PlaySoundEffect(s32);M2C_UNK StartScreenTransition(u8);
s32 CanStartScreenTransition();s32 IsUiModeSwitchBusy();s32 GetUiMode();M2C_UNK SetUiMode(s16,s32);
u8 row=(u8)M2C_FIELD(M2C_FIELD(ctx,void **,MAP_SCRIPT_STATE_IP),s16 *,8);
void *cmd;
SetListRowFlag(row,1);cmd=M2C_FIELD(ctx,void **,MAP_SCRIPT_STATE_IP);
if(M2C_FIELD(cmd,s32 *,12)==0){M2C_FIELD(ctx,void **,MAP_SCRIPT_STATE_IP)=cmd+MAP_SCRIPT_COMMAND_SIZE;return 1;}
if(IsUiModeSwitchBusy()!=0)return 0;
if(GetUiMode()==2){if(CanStartScreenTransition()==0)return 0;StartScreenTransition(row);}
else SetUiMode(2,row);
PlaySoundEffect(0x121);M2C_FIELD(ctx,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;return 0;
}

/* Map-script opcode: set MAPCONFIG_SHOW_UNIT_INFO_PANEL so the map view draws
 * the unit info panel, then run the next command (the partner of
 * MapScriptHideUnitInfoPanel, which clears the bit). */
s32 MapScriptShowUnitInfoPanel(void *state) {
extern M2C_UNK gMapConfig;

M2C_FIELD(&gMapConfig,s16 *,MAPCONFIG_FLAGS)=(s16)(M2C_FIELD(&gMapConfig,u16 *,MAPCONFIG_FLAGS)|MAPCONFIG_SHOW_UNIT_INFO_PANEL);
M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;return 1;
}

/* Map-script opcode: clear MAPCONFIG_SHOW_UNIT_INFO_PANEL so the map view stops
 * drawing the unit info panel, then run the next command. */
s32 MapScriptHideUnitInfoPanel(void *state) {
    extern M2C_UNK gMapConfig;

    M2C_FIELD(&gMapConfig, s16 *, MAPCONFIG_FLAGS) = (s16) (M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_FLAGS) & ~MAPCONFIG_SHOW_UNIT_INFO_PANEL);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script opcode: hold the script until the map reaches the player's turn
 * (MAP_STATE_PLAYER_TURN), then run the next command. */
s32 MapScriptWaitForPlayerTurnStart(void *state) {
    extern void **gCurrentMap;

    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) != MAP_STATE_PLAYER_TURN) {
        return 0;
    }
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script opcode: hold the script while the map is beginning the current
 * player's turn (MAP_STATE_PLAYER_TURN); once that step has passed, run the next
 * command. */
s32 MapScriptWaitWhilePlayerTurnBegins(void *state) {
    extern void **gCurrentMap;

    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) == MAP_STATE_PLAYER_TURN) {
        return 0;
    }
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script wait callback: hold the script until the map reaches the player
 * turn (MAP_STATE_PLAYER_TURN) — on the saved turn when one is given — and then,
 * once the saved player is the current player, clear the wait callback. */
void WaitForMapTurn(void *state) {
extern void **gCurrentMap;
void *map=*gCurrentMap;
s32 turn;
if(M2C_FIELD(map,u16 *,MAP_STATE)!=MAP_STATE_PLAYER_TURN)return;
turn=M2C_FIELD(state,s16 *,MAP_SCRIPT_STATE_TURN);
if(turn>=0 && turn!=M2C_FIELD(map,u16 *,MAP_TURN))return;
if(M2C_FIELD(map,u16 *,MAP_CURRENT_PLAYER)==M2C_FIELD(state,u8 *,MAP_SCRIPT_STATE_PLAYER))M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_WAIT)=0;
}

/* Map-script command: wait until the map reaches the turn of the player the
 * command's first operand names (the second operand is the turn to wait for, -1
 * for any).  Stores the wait parameters in the sequence state, then starts
 * waiting at once. */
s32 MapScriptWaitForTurn(void *state) {
    void WaitForMapTurn(void *);
    M2C_FIELD(state, u8 *, MAP_SCRIPT_STATE_PLAYER) = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0);
    M2C_FIELD(state, s16 *, MAP_SCRIPT_STATE_TURN) = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND1);
    M2C_FIELD(state, void (**)(void *), MAP_SCRIPT_STATE_WAIT) = WaitForMapTurn;
    WaitForMapTurn(state);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

/* Map-script wait callback: keeps the script on its command until the map reaches
 * state 12 and the player id saved at MAP_SCRIPT_STATE_PLAYER has an army variant;
 * when player 1 is the current player it clears the wait callback, ending the
 * command. */
void WaitForPlayerArmyVariant(void *state) {
    extern void **gCurrentMap;
    int IsPlayerArmyVariantSet(u8);
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_STATE) != 12) return;
    if (!IsPlayerArmyVariantSet(M2C_FIELD(state, u8 *, MAP_SCRIPT_STATE_PLAYER))) return;
    if (M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) == 1) M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_WAIT) = 0;
}

/* Map-script command: wait until the map reaches state 12 and the player named by
 * the command's first operand has its army variant set.  Saves the player id in
 * the sequence state, then starts waiting at once. */
s32 MapScriptWaitForArmyVariant(void *state) {
    void WaitForPlayerArmyVariant(void *);

    M2C_FIELD(state, u8 *, MAP_SCRIPT_STATE_PLAYER) = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0);
    M2C_FIELD(state, void (**)(void *), MAP_SCRIPT_STATE_WAIT) = WaitForPlayerArmyVariant;
    WaitForPlayerArmyVariant(state);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

/* Map-script opcode: wait until any of the keys in the command's mask
 * (MAP_SCRIPT_OPERAND2) is pressed, then run the command's callback with the
 * mask, disable touch input and move on. Returns 0 either way, so the script
 * stays on the command until the key arrives. */
s32 MapScriptWaitForKey(void *state) {
    extern KeyState *gKeyState;
    void *command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    u32 keys = gKeyState->pressed;
    u32 keyMask = M2C_FIELD(command, u32 *, MAP_SCRIPT_OPERAND2);
    void (*callback)(u32) = M2C_FIELD(command, void (**)(u32), MAP_SCRIPT_PARAM);

    if (keys & keyMask) callback(keyMask); else return 0;
    DisableTouchInput();
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

/* Map-script opcode: no-op command, just advance the interpreter to the next
 * command and keep running. */
s32 MapScriptNoOp(void *state) {
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) = (s32) (M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Find the label command naming `label` in the map script block that the
 * interpreter state `state` is running: returns the command, or NULL when the
 * block has no such label. */
s32 *MapScriptFindLabel(s32 **state, s32 label) {
    s32 *command = M2C_FIELD(state, s32 **, MAP_SCRIPT_STATE_BLOCK);

    while (*command != MAP_SCRIPT_OP_END) {
        if (*command == MAP_SCRIPT_OP_LABEL && M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2) == label) return command;
        command += 4;
    }
    return NULL;
}

/* Map-script opcode: conditional jump. The command may carry a condition
 * callback at +4; when it reports true the script jumps to the label command
 * named by the command's wide operand, otherwise it runs the next command. A
 * nonzero first operand inverts the condition, and a command without a callback
 * always jumps. Returns 1 so the interpreter keeps running. */
s32 MapScriptJumpIf(void *state) {
    u8 takeJump;
    void *cmd = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    s32 (*condition)(void) = M2C_FIELD(cmd, s32 (**)(void), 4);
    void *label;

    if (condition) {
        if (condition()) takeJump = 1; else takeJump = 0;
        cmd = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
        if (M2C_FIELD(cmd, s16 *, MAP_SCRIPT_OPERAND0)) takeJump = (u8)!takeJump;
    } else takeJump = 1;
    if (takeJump) {
        label = MapScriptFindLabel(state, M2C_FIELD(cmd, s32 *, MAP_SCRIPT_OPERAND2));
        if (label) M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = label;
        else M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    } else M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script opcode: conditional jump on an event flag. The command's first
 * operand names the event flag; when it is set the script jumps to the label
 * command named by the wide operand, otherwise it runs the next command. A
 * nonzero second operand inverts the condition. Returns 1 to keep running. */
s32 MapScriptJumpIfFlag(void *state) {
s32 IsEventFlagSet(s16);
u8 flag;
void *cmd,*label;
if(IsEventFlagSet(M2C_FIELD(M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP),s16 *,MAP_SCRIPT_OPERAND0)))flag=1;else flag=0;
cmd=M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP);
if(M2C_FIELD(cmd,s16 *,MAP_SCRIPT_OPERAND1)){if(flag)flag=0;else flag=1;}
if(flag){label=MapScriptFindLabel(state,M2C_FIELD(cmd,s32 *,MAP_SCRIPT_OPERAND2));if(label)M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP)=label;else M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;}else M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;
return 1;
}

