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

s32 func_02093e94(void *arg0) {
    s32 FindMapOrderOfTypeAt(u8, u8, M2C_UNK);
    M2C_UNK func_020a4a68();
    s16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    if (FindMapOrderOfTypeAt((u8) temp_r0, (u8) (temp_r0 >> 8), 3) != 0) {
        func_020a4a68();
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
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

s32 func_02093f50(void *arg0) {
    s16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    if (FindMapOrderOfTypeAt((u8) temp_r0, (u8) (temp_r0 >> 8), 9) != 0) {
        func_020a4a68();
    }
    func_0208fa28();
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093f98(void *arg0) {
    M2C_UNK func_0208fa28();
    func_0208fa28();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02093fb8(void *arg0) {
    M2C_UNK func_020a4af0(s16, s16, s32);
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    func_020a4af0(M2C_FIELD(temp_r2, s16 *, 8), M2C_FIELD(temp_r2, s16 *, 0xA), M2C_FIELD(temp_r2, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
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

s32 func_020940b8(void *arg0) {
    M2C_UNK func_020d2bc0(s16, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    func_020d2bc0(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020940e4(void *arg0) {
    M2C_UNK GetLocalizedText(s32);
    M2C_UNK func_02095f94();
    GetLocalizedText(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    func_02095f94();
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02094110(void *arg0) {
    M2C_UNK func_02095fc0();
    func_02095fc0();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

/* Map-script command: show the UI message whose text id is at +0x0C of the
 * command, in the message-box style at +0x08 (0..2), unless a message box is
 * already active; then advance the script. */
s32 ScriptCmd_ShowMessage(void *script) {
    M2C_UNK ShowUiMessage(s32);
    M2C_UNK func_02096b6c(s32);
    M2C_UNK func_02096b88(s32);
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
            func_02096b6c(M2C_FIELD(command, s32 *, 0xC));
            break;
        case 2:
            func_02096b88(M2C_FIELD(command, s32 *, 0xC));
            break;
        }
    }
    M2C_FIELD(script, void **, 4) = (void *) (M2C_FIELD(script, void **, 4) + 0x10);
    return 0;
}

s32 func_0209419c(void *arg0) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s32 *, 0xC) = (s32) (M2C_FIELD(&gMapConfig, s32 *, 0xC) | (1 << (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC)));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020941d4(void *arg0) {
    extern M2C_UNK gMapConfig;
    M2C_FIELD(&gMapConfig, s32 *, 0xC) = (s32) (M2C_FIELD(&gMapConfig, s32 *, 0xC) & (-1 ^ (1 << (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC))));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
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

s32 func_020942b0(void *arg0) {
    M2C_UNK IsMessageBoxActive();
    s32 temp_r0;

    if (IsMessageBoxActive() != 0) {
        do {
            temp_r0 = *M2C_FIELD(arg0, s32 **, 4);
            switch (temp_r0) {
            case 0x6B:
                return 1;
            case 7:
                return 1;
            default:
                M2C_FIELD(arg0, s32 **, 4) += 4;
                break;
            }
        } while (1);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02094310(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094324(void *arg0) {
    if (IsMessageBoxActive() != 0) {
        SetMessageBoxState(0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094354(void *arg0) {
    if (IsMessageBoxActive() == 0) {
        SetMessageBoxState(0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094384(void *arg0) {
    M2C_UNK SetMessageBoxState(M2C_UNK);
    SetMessageBoxState(3);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

void SetMenuCursor(s8 arg0) {
    void *Get3DSpriteManager();
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x4D) = arg0;
}

void func_020943bc(s8 arg0) {
    void *Get3DSpriteManager(void);
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x49) = arg0;
}

void func_020943d0(void) {
    func_020943bc(1);
}

void func_020943e0(s8 arg0) {
    void *Get3DSpriteManager(void);
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x48) = arg0;
}

void func_020943f4(s32 arg0,s8 arg1) { void *Get3DSpriteManager(); M2C_FIELD(Get3DSpriteManager()+arg0,s8 *,0x44)=arg1; }

void func_02094410(s8 arg0) { void *Get3DSpriteManager(); M2C_FIELD(Get3DSpriteManager(),s8 *,0x4E)=arg0; }

/* Resets both 3D sprite engines (main and sub) and, for each, points the three
 * layer records at its tile memory and reinitialises the three layers. */
void Reset3DSpriteEngines(void) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 g3DSpriteEngineSub;
    M2C_UNK Get3DSpriteCount(void);
    M2C_UNK Get3DSpriteTarget(void);
    void *Get3DSpriteManager(void);
    M2C_UNK func_02097128(M2C_UNK);
    M2C_UNK func_0209713c(M2C_UNK);
    M2C_UNK func_02097150(M2C_UNK, M2C_UNK);
    M2C_UNK func_02097164(M2C_UNK, M2C_UNK);
    M2C_UNK func_02097178(M2C_UNK, M2C_UNK);
    M2C_UNK func_020971c0(M2C_UNK, M2C_UNK);

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
            func_02097128(2);
            func_0209713c(1);

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
                func_02097150(layer, tileBase);
                func_02097164(layer, layer);
                func_02097178(layer, 0);
                func_020971c0(layer, 0);
                tileBase = tileBase + 0x80;
            }
        }
    }

    gCur3DSpriteEngine = savedEngine;
}

void func_020947ac(void);
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
 func_02086ac0();func_020947ac();func_02095fd4();
 for(i=0;i<3;i++)M2C_FIELD(GetScenePanelState(i),s16*,8)=0;
 for(i=0;i<2;i++)func_020943f4(i,2);
 SetMenuCursor(-1);func_020943bc(3);func_020943e0(0);func_02094410(0);Reset3DSpriteEngines();
}

s32 IsDialogActive(void) {
 extern M2C_UNK gDialogSequences;
 s32 i;
 u8 *p;
 p=(u8 *)&gDialogSequences;i=0;
 do {
 if(M2C_FIELD(p,s32 *,0)) return 1;
 i++;p+=24;
 }while(i<8);
 return 0;
}

u8 func_02094704(void) {
    s32 FindDialogSequence();
    u8 var_r0;

    if (FindDialogSequence() != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 FindDialogSequence(s32 value) {
 extern M2C_UNK gDialogSequences;
 s32 i;
 u8 *p;
 p=(u8 *)&gDialogSequences;i=0;
 do {
 if(M2C_FIELD(p,s32 *,0)==value) return i;
 i++;p+=24;
 }while(i<8);
 return -1;
}

void func_02094758(void) {
 void *Get3DSpriteManager(void);
 void *p=Get3DSpriteManager();
 M2C_FIELD(p,s8 *,0x4B)++;
}

void func_02094770(void) {
 void *Get3DSpriteManager(void);
 void *p=Get3DSpriteManager();
 M2C_FIELD(p,s8 *,0x4B)--;
}

u8 GetDialogSuspendCount(void) {
    void *Get3DSpriteManager();
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x4B);
}

void func_02094798(void) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x47) = 1;
}

void func_020947ac(void) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x47) = 0;
}

u8 IsTouchInputDisabled(void) {
    return M2C_FIELD(Get3DSpriteManager(), u8 *, 0x47);
}

void EndDialogSequence(s32 *arg0) {
    s32 IsDialogActive();
    void StartNextQueuedDialog(void);
    M2C_UNK func_02095fd4();
    M2C_UNK func_020d472c();
    if (*arg0 == 0) {
        return;
    }
    *arg0 = 0;
    if (IsDialogActive() == 0) {
        func_020947ac();
        func_02095fd4();
        StartNextQueuedDialog();
    }
    func_020d472c();
}

void QueueDialogSequence(s32 value) {
   void *StartDialogSequence(s32);
   s32 i;
   if(!IsDialogActive()) {StartDialogSequence(value);return;}
   for(i=0;i<8;i++) {
   if(!M2C_FIELD(Get3DSpriteManager()+((u32)i*4),s32 *,0x24)) {
   M2C_FIELD(Get3DSpriteManager()+((u32)i*4),s32 *,0x24)=value;
   return;
   }}
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
void SetMenuCursor(s8); void func_020943bc(s8);void func_020943e0(s8);void func_02094410(s8);
M2C_UNK func_02095fd4(void);void func_02094798(void);void func_020d4704(void);
extern M2C_UNK gDialogSequences,data_02157fec,data_02157ff0,data_02157ff4;
s16 index; s32 offset; u8 *base;
index=FindDialogSequence(0);
if(index==-1)return NULL;
SetMenuCursor(-1);func_020943bc(3);func_020943e0(0);func_02094410(0);
func_02095fd4();func_02094798();func_020d4704();
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

void func_02094a74(M2C_UNK arg0) {
    s32 IsMessageBoxActive();
    M2C_UNK ShowScenePanel(M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ShowScenePanel(arg0);
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

void func_02094af8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SetScenePanelFace(M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelFace(arg0, arg1, arg2);
}

void func_02094b28(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02097aa8(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_02097aa8(arg0, arg1);
}

void func_02094b50(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02097178(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_02097178(arg0, arg1);
}

void func_02094b78(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020971c0(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_020971c0(arg0, arg1);
}

void func_02094ba0(M2C_UNK arg0) {
    M2C_UNK ClearScenePanelRows(M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ClearScenePanelRows(arg0);
}

void func_02094bc0(M2C_UNK arg0) {
    M2C_UNK ShowPanelFace(M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    ShowPanelFace(arg0);
}

void func_02094be0(M2C_UNK arg0) {
    M2C_UNK HidePanelFace(M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    HidePanelFace(arg0);
}

void func_02094c00(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02097410(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_02097410(arg0, arg1, arg2, arg3);
}

void func_02094c38(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK SetScenePanelFaceSlot(M2C_UNK, M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    SetScenePanelFaceSlot(arg0, arg1, arg2);
}

void func_02094c68(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0209747c(M2C_UNK, M2C_UNK);
    if (IsMessageBoxActive() != 0) {
        return;
    }
    func_0209747c(arg0, arg1);
}

/* Builds a battle action entry for the given slot and submits it. */
void func_02094c90(s32 slot, s32 arg1) {
 extern s32 gCur3DSpriteEngine;
 s32 IsMessageBoxActive(); s32 HighlightScenePanel(); s32 GetMenuCursor(); s32 func_02091e70();
 void *GetScenePanelState(s32);
 s32 value; void *ptrA,*ptrB,*ptrC,*ptrD;
 if(IsMessageBoxActive()!=0)return;
 if(HighlightScenePanel(slot)!=1)return;
 HideMenuCursor(GetMenuCursor());
 if(GetMenuCursor()<0)return;
 if(GetMenuCursor()>=3)return;
 value=func_02091e70(3);
 ptrA=Get3DSpriteManager();ptrB=Get3DSpriteManager();ptrC=GetScenePanelState(3);ptrD=GetScenePanelState(3);
 func_0209bee0(arg1,(s16)value,1,M2C_FIELD(ptrA,u8*,0x4c),M2C_FIELD((u8*)gCur3DSpriteEngine+M2C_FIELD(ptrB,u8*,0x4c)*4,s32*,0xc),M2C_FIELD(ptrC,s32*,0),(u16)((M2C_FIELD(ptrD,u8*,6)&15)<<12),M2C_FIELD(GetScenePanelState(3),u16*,4));
}

