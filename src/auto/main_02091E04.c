/* 71 functions from 0x02091E04 to 0x02092DF4 (main), found by ds-decomp. */
#include "common.h"
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

u8 Get3DSpriteTarget(void) {
    if (Get3DSpriteTargetMode() == 2) {
        return 0U;
    }
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x49);
}

void func_02091e44(void) {
    M2C_UNK Get3DSpriteTargetMode();
    Get3DSpriteTargetMode();
}

s8 GetMenuCursor(void) {
    s32 Get3DSpriteCount();
    if (Get3DSpriteCount() == 2) {
        return 2;
    }
    return M2C_FIELD(Get3DSpriteManager(), s8 *, 0x4D);
}

s32 func_02091e70(s32 arg0) {
    s32 Get3DSpriteCount();
    s32 temp_r0;
    u8 temp_r0_2;
    void *temp_r4;
    temp_r4 = (void *)GetScenePanelState(arg0);
    temp_r0 = Get3DSpriteCount();
    switch (temp_r0) {
    case 1:
        temp_r0_2 = M2C_FIELD(temp_r4, u8 *, 7);
        if (temp_r0_2 == 1) return 2;
        if (temp_r0_2 == 0) return 8;
        break;
    case 0:
    case 2:
        return 2;
    }
    return 0;
}

u16 MapScriptResolvePlayer(u16 arg0) {
    extern void **gCurrentMap;
    if (arg0 != 5) {
        return arg0;
    }
    return M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
}

s32 func_02091ef0(void) {
    return (M2C_FIELD(Get3DSpriteManager(), u8 *, 0x4A) * 2) + 2;
}

s32 func_02091f08(void) {
    s32 func_02091ef0();
    return func_02091ef0() * 8;
}

s32 GetScenePanelState(s32 arg0) {
    s32 var_r4;

    var_r4 = arg0;
    if (var_r4 == 3) {
        var_r4 = GetMenuCursor();
    }
    return (var_r4 * 0xC) + Get3DSpriteManager();
}

void Mark3DSpriteLayer0Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void Mark3DSpriteLayer1Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void Mark3DSpriteLayer2Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void Mark3DSpriteLayer3Dirty(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
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

s32 func_02092018(void *arg0) {
    s32 IsMessageBoxActive();
    if (IsMessageBoxActive() == 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092048(void *arg0) {
    s16 var_r0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), void (**)(void *), 4)(arg0);
    M2C_FIELD(arg0, void **, 4) = (void *)(M2C_FIELD(arg0, void **, 4) + 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s16 func_02092084(void *arg0) {
    s16 var_r0;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, M2C_UNK (**)(s32), 4)(M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020920c4(void *arg0) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02102a70;
    if (FindObjectByClass(&data_02102a70) == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020920e8(void *arg0) {
    M2C_UNK CreateSpriteFromClass(s32, s32);
    extern M2C_UNK data_02102a70;
    s32 temp_r0;
    temp_r0 = CreateSpriteFromClass((s32)&data_02102a70, 7);
    M2C_FIELD(arg0, void (**)(void *), 8) = func_020920c4;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), void (**)(s32), 4)(temp_r0);
    M2C_FIELD(arg0, void **, 4) = (void *)(M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_0209212c(void *arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 (**)(), 4)() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092160(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092180(void *arg0) {
    s32 func_02092048(void *);
    if (IsMessageBoxActive() == 0) {
        return func_02092048(arg0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
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

s32 func_020921cc(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s8 **, 4) = (s8) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020921f0(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s16 **, 4) = (s16) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092214(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s32 **, 4) = M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092238(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, u8 **, 4) = *M2C_FIELD(temp_r1, u8 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092260(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, u16 **, 4) = *M2C_FIELD(temp_r1, u16 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092288(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s32 **, 4) = *M2C_FIELD(temp_r1, s32 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void OnMapScrollDone(void *arg0) {
    s32 IsMapViewScrolling();
    if (IsMapViewScrolling() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020922cc(void *arg0) {
    s32 IsMessageBoxActive();
    M2C_UNK StepMapViewToTile(s16, s16);
    M2C_UNK PanMapViewToTile(s16, s16);
    void *temp_r1;

    if (IsMessageBoxActive() == 0) {
        temp_r1 = M2C_FIELD(arg0, void **, 4);
        if (M2C_FIELD(temp_r1, s32 *, 0xC) != 0) {
            PanMapViewToTile(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
        } else {
            StepMapViewToTile(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
        }
        M2C_FIELD(arg0, void (**)(void *), 8) = OnMapScrollDone;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092324(void *arg0) {
    M2C_UNK func_0207b744(s16, s16);
    M2C_UNK SetMapViewPositionToTileCentered(s16, s16);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r1, s32 *, 0xC) != 0) {
        SetMapViewPositionToTileCentered(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
    } else {
        func_0207b744(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
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

s32 func_02092434(void *arg0) {
    M2C_UNK CreateSpriteFromClass(s32, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    CreateSpriteFromClass(M2C_FIELD(temp_r1, s32 *, 4), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092460(void *arg0) {
    if (FindObjectByClass(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: wait until no 3D sprite of the command's class is left on
 * the main screen.  Returns 0 while one remains, 1 once it is gone. */
s32 WaitForMain3DSpriteRemoved(void *script) {
    s32 Find3DSpriteById(s32);
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 found;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    if (Find3DSpriteById(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_PARAM)) != 0) {
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
    s32 Find3DSpriteById(s32);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    u8 found;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (Find3DSpriteById(M2C_FIELD(M2C_FIELD(ctx, void **, 4), s32 *, 4)) != 0) {
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

s32 func_0209255c(void *arg0) {
    s32 Find3DSpriteById(s32);
    if (Find3DSpriteById(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092590(void *arg0) {
    M2C_UNK SetUiMode(s16, M2C_UNK);
    SetUiMode(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 0);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020925bc(void *arg0) {
    extern M2C_UNK gMapConfig;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(&gMapConfig, s16 *, 4) = (s16) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020925e4(void *arg0) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s16 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02092608(void *arg0) {
extern void **gCurrentMap;
s32 CreateOwnedMapUnit(s32,s32,s32,s32);void RefreshMapView(s32);
void *p=M2C_FIELD(arg0,void **,4);
RefreshMapView(CreateOwnedMapUnit(M2C_FIELD(p,s16 *,8),M2C_FIELD(p,s16 *,10),M2C_FIELD(p,s32 *,12),M2C_FIELD(*gCurrentMap,u16 *,0x52a4)));
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092654(void *arg0) {
    M2C_UNK func_020947ac();
    func_020947ac();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02092674(void *arg0) {
    M2C_UNK func_02094798();
    func_02094798();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
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
 s32 GetLocalizedText(s32); void func_02099e10(void); void func_020943e0(void); void Reset3DSpriteEngines(void);
 s32 func_02099dcc(s32); void SetMessageBoxState(s32); s32 IsMessageBoxActive(void);
 u8 Get3DSpriteTarget(void); s32 func_02091e70(s32); s32 Get3DSpriteManager(void); s32 GetScenePanelState(s32);
 s32 CreateMessageSprite(s32,s32,s32,s32,s32,s32,u16,u16);
 M2C_UNK MarkSpriteLayer1Dirty(void);
 extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain; extern void *g3DSpriteEngineSub;
 s32 text; void *savedEngine; s32 screen,style; void *managerA,*managerB,*layerA,*layerB,*layerC,*sprite; u32 attr;
 text=GetLocalizedText(textId);
 func_02099e10(); func_020943e0(); Reset3DSpriteEngines();
 if(func_02099dcc(text)==0){SetMessageBoxState(3);} if(IsMessageBoxActive()!=0)goto abort;
 savedEngine=gCur3DSpriteEngine;
 for(screen=0;screen<2;screen++){
 if(screen==0)gCur3DSpriteEngine=g3DSpriteEngineMain;else gCur3DSpriteEngine=g3DSpriteEngineSub;
 if(Get3DSpriteTarget()==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)goto next;
 if(Get3DSpriteTarget()==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)goto next;
 if(Get3DSpriteTarget()==3 && gCur3DSpriteEngine!=savedEngine)goto next;
 style=func_02091e70(2); managerA=(void *)Get3DSpriteManager();managerB=(void *)Get3DSpriteManager();
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

void func_02092888(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102a58;
    CreateSpriteObject(&data_02102a58, arg0);
}

void func_020928a0(void *arg0) {
    s32 func_0209bf28();
    if (func_0209bf28() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020928bc(M2C_UNK arg0,s32 arg1) {
s32 ShowMessageText(s32);void func_020928a0(void *);
s32 v=ShowMessageText(arg1);
if(v==0)M2C_FIELD(arg0,void (**)(void *),8)=func_020928a0;
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

void func_020928f4(void *arg0) {
    func_020928bc(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
}

void func_02092908(M2C_UNK arg0) {
    M2C_UNK func_020928bc(M2C_UNK, M2C_UNK);
    func_020928bc(arg0, -1);
}

s32 func_02092918(void *arg0) {
s32 IsMessageBoxActive();M2C_UNK ClearScenePanelRows(M2C_UNK);M2C_UNK MarkSpriteLayer1Dirty();
s32 v;
if(IsMessageBoxActive()!=0)v=1;
else {ClearScenePanelRows(3);MarkSpriteLayer1Dirty();v=0;}
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

s32 func_02092958(void *arg0) {
    M2C_UNK LoadUiGraphicsBank(u8);
    LoadUiGraphicsBank((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092984(void *arg0) {
    M2C_UNK FreeUiGraphicsBank(u8);
    FreeUiGraphicsBank((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
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

s32 func_02092a54(void *arg0) {
extern M2C_UNK gMapConfig;
M2C_FIELD(&gMapConfig,s16 *,0)=(s16)(M2C_FIELD(&gMapConfig,u16 *,0)|0x400);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092a7c(void *arg0) {
extern M2C_UNK gMapConfig;
M2C_FIELD(&gMapConfig,s16 *,0)=(s16)(M2C_FIELD(&gMapConfig,u16 *,0)&~0x400);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092aa4(void *arg0) {
extern void **gCurrentMap;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52b0)!=12)return 0;
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092adc(void *arg0) {
extern void **gCurrentMap;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52b0)==12)return 0;
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

void func_02092b14(void *arg0) {
extern void **gCurrentMap;
void *p=*gCurrentMap;
s32 v;
if(M2C_FIELD(p,u16 *,0x52b0)!=12)return;
v=M2C_FIELD(arg0,s16 *,0x12);
if(v>=0 && v!=M2C_FIELD(p,u16 *,0x52a2))return;
if(M2C_FIELD(p,u16 *,0x52a4)==M2C_FIELD(arg0,u8 *,0x11))M2C_FIELD(arg0,s32 *,8)=0;
}

s32 func_02092b68(void *arg0) {
void func_02092b14(void *);
M2C_FIELD(arg0,s8 *,0x11)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(arg0,s16 *,0x12)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,10);
M2C_FIELD(arg0,void (**)(void *),8)=func_02092b14;
func_02092b14(arg0);
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

void func_02092bac(void *arg0) {
extern void **gCurrentMap;
int func_020d1a74(u8);
if(M2C_FIELD(*gCurrentMap,u16 *,0x52b0)!=12)return;
if(!func_020d1a74(M2C_FIELD(arg0,u8 *,0x11)))return;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)==1)M2C_FIELD(arg0,s32 *,8)=0;
}

s32 func_02092c08(void *arg0) {
void func_02092bac(void *);
M2C_FIELD(arg0,s8 *,0x11)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(arg0,void (**)(void *),8)=func_02092bac;
func_02092bac(arg0);M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092c40(void *arg0) {
extern u16 *gKeyState;
void *p=M2C_FIELD(arg0,void **,4);
u32 keys=*gKeyState;
u32 mask=M2C_FIELD(p,u32 *,12);
void (*callback)(u32)=M2C_FIELD(p,void (**)(u32),4);
if(keys&mask)callback(mask);else return 0;
func_02094798();M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092c94(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 *MapScriptFindLabel(s32 **arg0,s32 arg1) {
s32 *p=*arg0;
while(*p!=MAP_SCRIPT_OP_END){if(*p==MAP_SCRIPT_OP_LABEL && p[3]==arg1)return p;p+=4;}
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

