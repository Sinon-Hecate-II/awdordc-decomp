/* 30 functions from 0x0222A9DC to 0x0222B9DC (ov010), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* Draws the entity's cursor in the style that fits the current situation, on the display banks
   the entity asks for (0 = main engine, 1 = sub engine, 3 = the engine that is active), and
   then moves the entity on to the matching next state. */
void UpdateEntityCursor(void *arg0){
M2C_UNK func_ov010_02228180(void *);M2C_UNK GotoSpriteAnimationLabel(void *,s32);M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);M2C_UNK SetPanelChoice(void *,s32);s32 func_020c4ba4(s32);s32 func_020c4b88(s32);M2C_UNK CreateNetErrorReporter(M2C_UNK *,M2C_UNK);void func_ov010_0222ad50(M2C_UNK,M2C_UNK,M2C_UNK,void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(func_ov010_02228180(arg0)==3){if(M2C_FIELD(arg0,s8 *,0x35)>=0){
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
savedBank=gCur3DSpriteEngine;i=0;do{
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(arg0);RenderTextLayerMessage(created,2,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000013);
M2C_FIELD(created,u32 *,0x58)|=0x1000;

}while(++i<2);gCur3DSpriteEngine=savedBank;}GotoSpriteAnimationLabel(arg0,8);return;}
CreateNetErrorReporter((M2C_UNK *)func_ov010_0222ad50,(M2C_UNK)arg0);
if(!func_020c4ba4(0)){if(M2C_FIELD(arg0,s8 *,0x35)>=0){
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
savedBank=gCur3DSpriteEngine;i=0;do{
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(arg0);RenderTextLayerMessage(created,3,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000015);
M2C_FIELD(created,u32 *,0x58)|=0x1000;
SetPanelChoice(created,1);
}while(++i<2);gCur3DSpriteEngine=savedBank;}GotoSpriteAnimationLabel(arg0,10);return;}
if(!func_020c4b88(0)){if(M2C_FIELD(arg0,s8 *,0x35)>=0){
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
savedBank=gCur3DSpriteEngine;i=0;do{
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(arg0);RenderTextLayerMessage(created,2,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000017);
M2C_FIELD(created,u32 *,0x58)|=0x1000;

}while(++i<2);gCur3DSpriteEngine=savedBank;}GotoSpriteAnimationLabel(arg0,12);return;}
if(M2C_FIELD(arg0,s8 *,0x35)>=0){
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
savedBank=gCur3DSpriteEngine;i=0;do{
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(arg0);RenderTextLayerMessage(created,3,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000014);
M2C_FIELD(created,u32 *,0x58)|=0x1000;
SetPanelChoice(created,0);
}while(++i<2);gCur3DSpriteEngine=savedBank;}GotoSpriteAnimationLabel(arg0,9);
}

/* Settles one text layer on a display bank: creates the layer's label with the chosen
   value and bank (CreateNetErrorSprite) and drops out of the message queue, or switches
   back to the layer's idle animation.  Ignored while another message is showing. */
void func_ov010_0222ad50(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, void *arg3) {
    s32 GetScreenFlag(M2C_UNK);
    s32 IsScreenFadeActive(void);
    M2C_UNK CreateNetErrorSprite(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
    M2C_UNK func_ov010_02228320(void);
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    M2C_UNK GotoSpriteAnimationLabel(void *, M2C_UNK);
    if (GetScreenFlag(M2C_FIELD(arg3, u8 *, 0x35)) == 1) {
        return;
    }
    if (IsScreenFadeActive() != 0) {
        return;
    }
    if (arg0 == 0) {
        return;
    }
    CreateNetErrorSprite(M2C_FIELD(arg3, s8 *, 0x35), M2C_FIELD(arg3, u16 *, 0x36), arg0, arg1, arg2, arg3);
    func_ov010_02228320();
    switch (arg2) {
    case 0:
    case 1:
    case 2:
        Ov010Online_ClearStepFlag(6);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        GotoSpriteAnimationLabel(arg3, 1);
        break;
    default:
        break;
    }
}

void func_ov010_0222ae08(M2C_UNK arg0) {
    M2C_UNK CreateNetErrorReporter(M2C_UNK *, M2C_UNK);
    void func_ov010_0222ad50(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    CreateNetErrorReporter((M2C_UNK *) &func_ov010_0222ad50, arg0);
}

/* Put the entity's label away: on every display bank the entity asks for
   (0 = main engine, 1 = sub engine, 3 = the engine that is active) create its
   label layer with the blank label (text id 0x4200001b) and keep that layer
   hidden, then move the flow on to the session step that follows. */
void Ov010_HideEntityLabel(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayerChild(void *);M2C_UNK Ov010Online_StartWfcConnection();
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedEngine;u32 bank;s32 slot;s8 engineMode;void *label;
if(M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE)>=0){
savedEngine=gCur3DSpriteEngine;slot=0;
do {
if(slot==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;engineMode=M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE);
if(engineMode==0&&bank!=g3DSpriteEngineMain)continue;
if(engineMode==1&&bank!=g3DSpriteEngineSub)continue;
if(engineMode==3&&bank!=savedEngine)continue;
label=CreateTextLayerChild(entity);
RenderTextLayerMessage(label,0,M2C_FIELD(entity,u16 *,TEXT_LAYER_VALUE)<<5,0x4200001b);
M2C_FIELD(label,s32 *,0x58)=((M2C_FIELD(label,s32 *,0x58)|0x1000)&~0x400)|0x800;
}while(++slot<2);
gCur3DSpriteEngine=savedEngine;
}
Ov010Online_StartWfcConnection();
}

/* Hold the sprite's animation while the WFC connection is still being made
 * (Ov010Online_WaitForConnection returns 1), and resume it once connected. */
void Sprite_ResumeAnimationWhenOnlineConnected(M2C_UNK sprite) {
    s32 Ov010Online_WaitForConnection();
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    if (Ov010Online_WaitForConnection() != 0) {
        return;
    }
    Sprite_ResumeAnimation(sprite);
}

/* Start the online (Wi-Fi) session with no custom handlers installed, then clear
 * the link command queues so the session begins from a clean state. */
void Ov010Online_BeginSession(void) {
    M2C_UNK ClearLinkCommandQueues();
    M2C_UNK Ov010Online_InitSession(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    Ov010Online_InitSession(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    ClearLinkCommandQueues();
}

/* Matchmaking step: attach the profile-save sprite (only once the local profile
 * has a stored NAS key) and the battle-save sprite to the online session's owner
 * object, then resume the owner's animation.  Ignored until matchmaking starts. */
void Ov010_ShowMatchmakingSaveSprites(M2C_UNK owner) {
    s32 IsProfileKeySet(M2C_UNK);
    M2C_UNK CreateLocalProfileSaveSprite(M2C_UNK);
    M2C_UNK CreateLocalBattleSaveSprite(M2C_UNK);
    if (IsOnlineSessionFlagSet(OV010_FLAG_MATCHMAKING) == 0) {
        return;
    }
    if (IsProfileKeySet(0) != 0) {
        CreateLocalProfileSaveSprite(owner);
    }
    CreateLocalBattleSaveSprite(owner);
    Sprite_ResumeAnimation(owner);
}

/* Online name-label step: starts the WFC match query for the local player's
 * name.  If the query cannot be started, hides the status text layer and
 * switches the label to its confirmed (11) or waiting (16) animation. */
void Ov010_StartMatchQuery(void *label) {
    s32 Ov010_RequestWfcMatch(s32, M2C_UNK, M2C_UNK, s32, s32);
    if (Ov010_RequestWfcMatch(label + ONLINE_LABEL_NAME, 1, 0, label + ONLINE_LABEL_MATCHED, label + ONLINE_LABEL_MATCH_COUNT) != 0) {
        return;
    }
    if (((s32) M2C_FIELD(label, s8 *, TEXT_LAYER_ENGINE) >= 0) && (FindTextLayer() != 0)) {
        StartWindowClose();
    }
    if (M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) & TEXT_LAYER_FLAG_CONFIRMED) {
        GotoSpriteAnimationLabel(label, 0xB);
        return;
    }
    GotoSpriteAnimationLabel(label, 0x10);
}

/* Online-match name-label step: while the WFC match query started by
 * Ov010_StartMatchQuery is still running, do nothing.  Once it has finished,
 * close the status text window if the label has one, then switch the label to
 * its confirmed (11) or waiting (16) animation. */
void Ov010_UpdateMatchQuery(void *label) {
    M2C_UNK StartWindowClose();
    s32 FindTextLayer();
    s32 Ov010_IsWfcMatchRunning();
    if (Ov010_IsWfcMatchRunning() != 0) {
        return;
    }
    if (((s32) M2C_FIELD(label, s8 *, TEXT_LAYER_ENGINE) >= 0) && (FindTextLayer() != 0)) {
        StartWindowClose();
    }
    if (M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) & TEXT_LAYER_FLAG_CONFIRMED) {
        GotoSpriteAnimationLabel(label, 0xB);
        return;
    }
    GotoSpriteAnimationLabel(label, 0x10);
}

void func_ov010_0222b074(void) {
    M2C_UNK Ov010Online_EndSession();
    Ov010Online_EndSession();
}

void func_ov010_0222b080(void) {
    M2C_UNK func_ov010_02228714();
    func_ov010_02228714();
}

/* Keep the online label's animation paused while the WFC session is still up, then
 * play its session-end animation once the session has ended. */
void Ov010_PlaySessionEndLabel(void *label) {
    s32 Ov010Online_PollSessionEnd();
    if (Ov010Online_PollSessionEnd() != 0) {
        return;
    }
    GotoSpriteAnimationLabel(label, ONLINE_LABEL_ANIM_SESSION_END);
}

/* Online match name-label update: start the split-screen fade on each screen
 * whose earlier split transition has finished.  Bits 2 and 4 of the label's
 * flags mark the main and sub screens that are waiting for the fade. */
void StartOnlineMatchLabelSplitFades(void *label) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK StartScreenFadeChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) & 2) && (GetScreenFlag(0) == 0)) {
        StartScreenFadeChildren(2, 8, 0, label);
    }
    if (!(M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) & 4)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 1, label);
}

/* Online-session step: attach the local profile-save and battle-save sprites to
 * the session's owner object, then park the owner on its matchmaking wait
 * animation. */
void Ov010_ShowLocalSaveSprites(M2C_UNK owner) {
    M2C_UNK CreateLocalProfileSaveSprite();
    M2C_UNK CreateLocalBattleSaveSprite(M2C_UNK);
    CreateLocalProfileSaveSprite();
    CreateLocalBattleSaveSprite(owner);
    GotoSpriteAnimationLabel(owner, 1);
}

/* Refresh the entity's sprite on the selected display banks, then queue command 19. */
void func_ov010_0222b140(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(M2C_FIELD(entity,s8 *,0x35)>=0&&FindTextLayer())StartWindowClose();
if(M2C_FIELD(entity,s8 *,0x35)>=0){
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(entity);
RenderTextLayerMessage(created,2,M2C_FIELD(entity,u16 *,0x36)<<5,0x4200001f);
M2C_FIELD(created,s32 *,0x58)|=0x1000;
}while(++i<2);
gCur3DSpriteEngine=savedBank;
}
GotoSpriteAnimationLabel((s32)entity,19);
}

/* Hide the entity's sprite on the display banks it selects (0 = main engine,
 * 1 = sub engine, 3 = the engine active when called), then play its hide
 * animation. */
void Ov010_HideEntitySprite(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayerChild(void *);M2C_UNK GotoSpriteAnimationLabel(s32,s32);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 engine;void *sprite;
if(M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE)>=0){
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;engine=M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE);
if(engine==0&&bank!=g3DSpriteEngineMain)continue;
if(engine==1&&bank!=g3DSpriteEngineSub)continue;
if(engine==3&&bank!=savedBank)continue;
sprite=CreateTextLayerChild(entity);
RenderTextLayerMessage(sprite,0,M2C_FIELD(entity,u16 *,0x36)<<5,0x4200001e);
M2C_FIELD(sprite,s32 *,0x58)=((M2C_FIELD(sprite,s32 *,0x58)|0x1000)&~0x400)|0x800;
}while(++i<2);
gCur3DSpriteEngine=savedBank;
}
GotoSpriteAnimationLabel((s32)entity,7);
}

/* Creates a draw entry in both active banks when the entity's bank selector allows. */
void func_ov010_0222b314(void *entity) {
    s32 GetLastNasError();
    M2C_UNK RenderTextLayerMessage(void *, M2C_UNK, s32, s32);
    void *CreateTextLayer(void *);
    M2C_UNK GotoSpriteAnimationLabel(M2C_UNK, M2C_UNK);
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    void *created;
    s32 bank;
    s32 i;
    s8 mode;
    s32 savedBank;

    if ((GetLastNasError() == 2) || (M2C_FIELD(entity, s8 *, 0x3C) != 0)) {
        if ((s32) M2C_FIELD(entity, s8 *, 0x35) >= 0) {
            savedBank = gCur3DSpriteEngine;
            for (i = 0; i < 2; ++i) {
                if (i == 0) {
                    bank = g3DSpriteEngineMain;
                } else {
                    bank = g3DSpriteEngineSub;
                }
                gCur3DSpriteEngine = bank;
                mode = M2C_FIELD(entity, s8 *, 0x35);
                if (mode == 0 && bank != g3DSpriteEngineMain) {
                    continue;
                }
                if (mode == 1 && bank != g3DSpriteEngineSub) {
                    continue;
                }
                if (mode == 3 && bank != savedBank) {
                    continue;
                }
                created = CreateTextLayer(entity);
                RenderTextLayerMessage(created, 2, M2C_FIELD(entity, u16 *, 0x36) << 5, 0x4200001C);
                M2C_FIELD(created, s32 *, 0x58) = (s32) (M2C_FIELD(created, s32 *, 0x58) | 0x1000);
            }
            gCur3DSpriteEngine = savedBank;
        }
        GotoSpriteAnimationLabel(entity, 0x11);
        return;
    }
    GotoSpriteAnimationLabel(entity, 2);
}

void func_ov010_0222b414(void) {

}

/* Unlocks the map Start button: once the map confirm flag is on, the text layer draws
   its "go" label, refreshes that label on the display banks the layer selects (one call
   per bank: the message id starts at 0x42000017), and moves on to the animation that
   follows it. */
void func_ov010_0222b418(void *layer) {
    void *CreateTextLayer(void *);
    M2C_UNK RenderTextLayerMessage(void *, M2C_UNK, s32, s32);
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain, gCur3DSpriteEngine;
    s8 temp_r1;
    s32 var_r8;
    s32 var_r2;
    register unsigned long temp_r9;
    void *temp_r0;

    if (IsMapConfirmEnabled() != 0) {
        ResetProfileIdBlock(0);
        M2C_FIELD(layer, u8 *, TEXT_LAYER_FLAGS) = (u8)(M2C_FIELD(layer, u8 *, TEXT_LAYER_FLAGS) | TEXT_LAYER_FLAG_CONFIRMED);
        GotoSpriteAnimationLabel(layer, 3);
        return;
    }

    if (M2C_FIELD(layer, s8 *, TEXT_LAYER_ENGINE) >= 0) {
        temp_r9 = gCur3DSpriteEngine;
        var_r8 = 0;
        do {
            if (var_r8 == 0) var_r2 = g3DSpriteEngineMain;
            else var_r2 = g3DSpriteEngineSub;
            gCur3DSpriteEngine = var_r2;
            temp_r1 = M2C_FIELD(layer, s8 *, TEXT_LAYER_ENGINE);
            if (temp_r1 == 0 && var_r2 != g3DSpriteEngineMain) continue;
            if (temp_r1 == 1 && var_r2 != g3DSpriteEngineSub) continue;
            if (temp_r1 == 3 && var_r2 != temp_r9) continue;
            temp_r0 = CreateTextLayer(layer);
            RenderTextLayerMessage(temp_r0, 2, (s32)M2C_FIELD(layer, u16 *, TEXT_LAYER_VALUE) << 5, 0x42000017);
            M2C_FIELD(temp_r0, s32 *, 0x58) = (s32)(M2C_FIELD(temp_r0, s32 *, 0x58) | 0x1000);
        } while (++var_r8 < 2);
        gCur3DSpriteEngine = temp_r9;
    }

    GotoSpriteAnimationLabel(layer, 0xC);
}

/* Draws the "chosen" label of the entity on the display banks the entity asks
 * for (0 = main engine, 1 = sub engine, 3 = the active engine) and moves the
 * entity to animation 14. */
void func_ov010_0222b520(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);M2C_UNK GotoSpriteAnimationLabel(s32,s32);M2C_UNK SetPanelChoice(void *,s32);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE)>=0){
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(entity);
RenderTextLayerMessage(created,3,M2C_FIELD(entity,u16 *,TEXT_LAYER_VALUE)<<5,0x4200001a);
M2C_FIELD(created,s32 *,0x58)|=0x1000;
SetPanelChoice(created,1);
}while(++i<2);
gCur3DSpriteEngine=savedBank;
}
GotoSpriteAnimationLabel((s32)entity,14);
}

/* Show the "map confirm" prompt for the entity: with the confirm prompt enabled, draw the
   prompt label on the display bank the entity asks for (0 = main, 1 = sub, 3 = the active
   engine); otherwise play the entity's cancel animation. */
void func_ov010_0222b604(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(IsMapConfirmEnabled()){
if(M2C_FIELD(entity,s8 *,0x35)<0)return;
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,s8 *,0x35);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(entity);
RenderTextLayerMessage(created,2,M2C_FIELD(entity,u16 *,0x36)<<5,0x42000019);
M2C_FIELD(created,s32 *,0x58)|=0x1000;
}while(++i<2);
gCur3DSpriteEngine=savedBank;return;
}
GotoSpriteAnimationLabel((s32)entity,1);
}

/* Draws the entity's "decided" label on the display banks the entity asks for
 * (0 = main engine, 1 = sub engine, 3 = the active engine) and moves the entity
 * to animation 13. */
void func_ov010_0222b6ec(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE)>=0){
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE);
if(mode==0&&bank!=g3DSpriteEngineMain)continue;
if(mode==1&&bank!=g3DSpriteEngineSub)continue;
if(mode==3&&bank!=savedBank)continue;
created=CreateTextLayer(entity);
RenderTextLayerMessage(created,3,M2C_FIELD(entity,u16 *,TEXT_LAYER_VALUE)<<5,0x42000018);
M2C_FIELD(created,s32 *,0x58)|=0x1000;
SetPanelChoice(created,1);
}while(++i<2);
gCur3DSpriteEngine=savedBank;
}
GotoSpriteAnimationLabel((s32)entity,13);
}

void func_ov010_0222b7d0(M2C_UNK arg0) {
    GotoSpriteAnimationLabel(arg0, 0x10);
}

/* Draws the entity's message label (text id 0x42000016) on the display banks the
 * entity asks for (0 = main engine, 1 = sub engine, 3 = the active engine); the
 * entity's animation is left alone. */
void Ov010_ShowEntityLabel(void *entity) {
M2C_UNK RenderTextLayerMessage(void *,M2C_UNK,s32,s32);void *CreateTextLayer(void *);
extern s32 g3DSpriteEngineSub,g3DSpriteEngineMain,gCur3DSpriteEngine;
s32 savedEngine;u32 bank;s32 slot;s8 engineMode;void *label;
if(M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE)<0)return;
savedEngine=gCur3DSpriteEngine;slot=0;
do {
if(slot==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;engineMode=M2C_FIELD(entity,s8 *,TEXT_LAYER_ENGINE);
if(engineMode==0&&bank!=g3DSpriteEngineMain)continue;
if(engineMode==1&&bank!=g3DSpriteEngineSub)continue;
if(engineMode==3&&bank!=savedEngine)continue;
label=CreateTextLayer(entity);
RenderTextLayerMessage(label,2,M2C_FIELD(entity,u16 *,TEXT_LAYER_VALUE)<<5,0x42000016);
M2C_FIELD(label,s32 *,0x58)|=0x1000;
}while(++slot<2);
gCur3DSpriteEngine=savedEngine;
}

/* Online map-choice label step: when the current map allows confirming, mark
 * the label confirmed and play its confirmed animation; otherwise play its
 * normal animation. */
void Ov010_ConfirmMapChoiceLabel(void *label) {
    if (IsMapConfirmEnabled() != 0) {
        M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) = (u8) (M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) | TEXT_LAYER_FLAG_CONFIRMED);
        GotoSpriteAnimationLabel(label, 3);
        return;
    }
    GotoSpriteAnimationLabel(label, 1);
}

/* Play the online map-choice label's animation: its confirmed animation (3)
 * when the current map may be confirmed, its normal one (1) otherwise. */
void Ov010_PlayMapChoiceLabel(void *label) {
    s32 IsMapConfirmEnabled(void);

    if (IsMapConfirmEnabled() != 0) {
        GotoSpriteAnimationLabel(label, 3);
        return;
    }
    GotoSpriteAnimationLabel(label, 1);
}

void func_ov010_0222b91c(M2C_UNK arg0) {
    M2C_UNK GotoSpriteAnimationLabel(M2C_UNK, M2C_UNK);
    GotoSpriteAnimationLabel(arg0, 1);
}

/* Online-match label update: create the split-screen transition on each screen
 * whose transition flag is set, and set that screen's bit (2 main, 4 sub) in the
 * label's flags byte so StartOnlineMatchLabelSplitFades starts its fade once the
 * transition has finished. */
void StartOnlineMatchLabelSplitTransitions(void *label) {
    M2C_UNK CreateScreenTransitionChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        CreateScreenTransitionChildren(2, 8, 0, label);
        M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) = (u8) (M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) | ONLINE_LABEL_FLAG_SPLIT_MAIN);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 1, label);
    M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) = (u8) (M2C_FIELD(label, u8 *, TEXT_LAYER_FLAGS) | ONLINE_LABEL_FLAG_SPLIT_SUB);
}

void func_ov010_0222b998(void) {
    M2C_UNK CreateSubScreenLinkIndicator();
    M2C_UNK DisableMapConfirm();
    M2C_UNK Ov010Online_ClearStepFlag(M2C_UNK);
    M2C_UNK func_ov010_02228320();
    DisableMapConfirm();
    func_ov010_02228320();
    Ov010Online_ClearStepFlag(6);
    CreateSubScreenLinkIndicator();
}

/* Sync the online screen's map-confirm prompt and the sub-screen status
 * indicator with matchmaking: once matchmaking has started, allow the player to
 * confirm the map; otherwise disable confirmation and remove the indicator. */
void Ov010_SyncSubScreenLinkIndicator(void) {
    M2C_UNK DeleteSubScreenLinkIndicator();
    M2C_UNK EnableMapConfirm();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    if (IsOnlineSessionFlagSet(OV010_FLAG_MATCHMAKING) != 0) {
        EnableMapConfirm();
        return;
    }
    DisableMapConfirm();
    DeleteSubScreenLinkIndicator();
}

