/* 18 functions from 0x020DE264 to 0x020DF1D0 (main), found by ds-decomp. */
#include "common.h"
typedef struct SetupSprite {
 u8 pad[0x40];
 unsigned field0:18;
 unsigned frame:8;
 unsigned field26:6;
 u8 pad44[0x15];
 u8 baseFrame:4;
 u8 alternate:1;
 u8 otherFlags:3;
} SetupSprite;
static inline u8 SetupIsActive(void *p) { return ((SetupSprite*)p)->baseFrame + 2 != (u16)((SetupSprite*)p)->frame; }
static inline void SetupSetFrame(void *p,u16 frame,s8 timer) { ((SetupSprite*)p)->frame=frame; M2C_FIELD(p,s8 *,0x5a)=timer; }
static inline s32 GetSetupCode(void *p) {
    s32 result=-1;
    switch(M2C_FIELD(p,s32 *,0x34)) {
    case 0:
        switch(M2C_FIELD(p,s32 *,0x38)) {case 1: result=2; break; default: result=4; break;}
        break;
    case 1: case 2: result=2; break;
    }
    return result;
}

#pragma opt_strength_reduction off
/* Sets up a scene/screen object: switches in the main sprite engine, loads the
 * palette and background chosen by GetSetupCode, sets the setup sprite's frame,
 * then registers the scene's per-variant update callback with overlay 10. */
M2C_UNK SetupScene(M2C_UNK setup, M2C_UNK mode) {
    void Clear3DSpriteLayer(u8);
    void SetFileDirectory(void *);
    void *GetLocalizedFileName(void *);
    void OpenNarcArchive(void *);
    void LoadNarcFileDecompressed(void *, void *);
    void CloseNarcArchive(void);
    void AddTileRectPalette(void *, s32, s32, s32);
    void LoadTimerSpriteGraphics(s32, s32);
    void Show3DSpriteSlide(void *);
    void Hide3DSprite(void *);
    void SetTextById(void *, u32);
    s32 GetSpriteAnimValue(void *);
    void func_ov010_02228d48(s32, s32, s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK data_0212d428;
    extern M2C_UNK data_0212d430;
    extern M2C_UNK data_0212d440;
    extern M2C_UNK data_0212d450;
    s32 GetPeerRatingMatchQuality(s32, void *);
    s32 WaitForBrowsedSession(M2C_UNK);
    void func_020de610(void);

    void *savedEngine = gCur3DSpriteEngine;
    s32 setupCode;
    s32 setupCode2;
    void *ptr;
    u8 unusedLow;
    u32 unusedVal;
    s32 animValue;
    s32 variant;
    s32 unusedV34;
    s32 unusedV38;
    s32 updateFn;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    SetFileDirectory(&data_0212d428);
    OpenNarcArchive(GetLocalizedFileName(&data_0212d430));

    setupCode=GetSetupCode((void*)setup);
    switch(setupCode) {
    case 4:LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d440),M2C_FIELD(gCur3DSpriteEngine,void **,0x20));break;
    case 2:LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d450),M2C_FIELD(gCur3DSpriteEngine,void **,0x20));break;
    }
    CloseNarcArchive();
    AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    LoadTimerSpriteGraphics(0x3c00, 0x7);

    gCur3DSpriteEngine = savedEngine;

    M2C_FIELD((void *)setup, u16 *, 0x48) |= 0x20;

    ptr = M2C_FIELD((void *)setup, void **, 0x54);
    SetupSetFrame(ptr,(u16)(((SetupSprite*)ptr)->baseFrame+2),0);

    Show3DSpriteSlide(M2C_FIELD((void *)setup, void **, 0x58));
    Hide3DSprite(M2C_FIELD((void *)setup, void **, 0x60));
    SetTextById(M2C_FIELD((void *)setup, void **, 0x64), 0x44000011U);
    Show3DSpriteSlide(M2C_FIELD((void *)setup, void **, 0x64));

    if (GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68)) != 0) {
        animValue = GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68));ptr=M2C_FIELD(setup,void **,0x68);
        M2C_FIELD(ptr, u16 *, 0xe) = (u16)animValue;
        M2C_FIELD(ptr, u16 *, 0x10) = 0;
        M2C_FIELD(ptr, u16 *, 0xc) = 0xc;
        M2C_FIELD(ptr, u16 *, 0x2) = M2C_FIELD(ptr, u16 *, 0x4);
    }
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x100;
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x200;

    updateFn=0;
    switch(M2C_FIELD(setup,s32 *,0x3c)) {
    case 0: M2C_FIELD(setup,u16 *,0x4a)=10;updateFn=(s32)GetPeerRatingMatchQuality;break;
    case 1: M2C_FIELD(setup,u16 *,0x4a)=10;updateFn=(s32)WaitForBrowsedSession;break;
    }

    M2C_FIELD((void *)setup, u8 *, 0x41) = 0;
    M2C_FIELD((void *)setup, u16 *, 0x4c) = 0x708;

    setupCode2=GetSetupCode((void*)setup);
    variant = M2C_FIELD((void *)setup, s32 *, 0x3c);
    func_ov010_02228d48((s32)mode, setupCode2, (s32)func_020de610, (s32)setup, updateFn, (s32)setup, variant);
}

/* Per-frame wait for a joining peer (playerId's server entry) whose GameSpy
 * skill rating is close enough to the local player's: -1 while it is not, with
 * the tolerance widened by RATING_TOLERANCE_STEP each update, then the match
 * quality, which falls by one point per rating point of difference. */
s32 GetPeerRatingMatchQuality(s32 playerId, void *scene) {
    s32 GetBrowsedServerValue(s32, s32 *, s32);
    void *GetLocalPlayerStatus(void);
    extern M2C_UNK data_0212c5d8;
    s32 saved, absDiff, tolerance, quality;
    register s32 diff;
    void *status;

    status = GetLocalPlayerStatus();
    if (!(M2C_FIELD(status, u8 *, LOCAL_STATUS_OPTIONS) & LOCAL_OPTION_ONLINE)) return -1;
    saved = M2C_FIELD(status, s32 *, 0x20); /* the local player's rating, Q12 */
    diff = (saved >> 12) - (GetBrowsedServerValue(playerId, &data_0212c5d8, RATING_DEFAULT) >> 12);
    if (diff < 0) absDiff = -diff; else absDiff = diff;
    tolerance = M2C_FIELD(scene, u16 *, 0x4a);
    if (tolerance < absDiff) {
        tolerance = tolerance + RATING_TOLERANCE_STEP;
        if (tolerance >= RATING_TOLERANCE_MAX) tolerance = RATING_TOLERANCE_MAX;
        M2C_FIELD(scene, u16 *, 0x4a) = tolerance;
        return -1;
    }
    if (diff < 0) quality = -diff; else quality = diff;
    quality = MATCH_QUALITY_MAX - quality;
    if (quality > MATCH_QUALITY_MAX) quality = MATCH_QUALITY_MAX;
    else if (quality < 0) quality = 0;
    return quality;
}

/* Per-frame matchmaking wait: -1 until the local player is online and the
 * browsed server reports user_param 1; then read its rating (defaulting to
 * RATING_DEFAULT) and return the maximum match quality. */
s32 WaitForBrowsedSession(M2C_UNK playerId) {
    M2C_UNK GetBrowsedServerValue(M2C_UNK, M2C_UNK *, s32);
    void *GetLocalPlayerStatus();
    extern M2C_UNK sQr2UserParamKey;
    extern M2C_UNK sQr2RatingKey;
    if (!(M2C_FIELD(GetLocalPlayerStatus(), u8 *, LOCAL_STATUS_OPTIONS) & LOCAL_OPTION_ONLINE)) {
        return -1;
    }
    if (GetBrowsedServerValue(playerId, &sQr2UserParamKey, 1) != 1) {
        return -1;
    }
    GetBrowsedServerValue(playerId, &sQr2RatingKey, RATING_DEFAULT);
    return MATCH_QUALITY_MAX;
}

void func_020de610(void) {

}

/* Prepares the 3D matching scene: switches in the main sprite engine, loads the
 * matching archive and the 2P/4P background chosen by GetSetupCode, resets the
 * menu sprites, then registers the scene's ov010 update callbacks. */
M2C_UNK SetupMatchScene(M2C_UNK setup, M2C_UNK side) {
void Clear3DSpriteLayer(u8); void SetFileDirectory(void *); void *GetLocalizedFileName(void *); void OpenNarcArchive(void *); void LoadNarcFileDecompressed(void *,void *); void CloseNarcArchive(void); void AddTileRectPalette(void *,s32,s32,s32);
void Show3DSpriteSlide(void *); void Hide3DSprite(void *); void SetTextById(void *,u32); s32 GetSpriteAnimValue(void *);
void func_ov010_02228f80(s32,s32,s32,void *,void *,void *,void *,s32);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK gMatchScenePath,gMatchSceneNarc,gMatchScene4PScreen,gMatchScene2PScreen;
void MatchScenePeerClosedCallback(s32,s32,void *); s32 WaitForMatchSession(s32);
void *savedEngine=gCur3DSpriteEngine; void *sprite; s32 layout,animValue;
gCur3DSpriteEngine=g3DSpriteEngineMain;
Clear3DSpriteLayer(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
SetFileDirectory(&gMatchScenePath);
OpenNarcArchive(GetLocalizedFileName(&gMatchSceneNarc));
layout=GetSetupCode((void *)setup);
switch(layout) {
case 4: LoadNarcFileDecompressed(GetLocalizedFileName(&gMatchScene4PScreen),M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
case 2: LoadNarcFileDecompressed(GetLocalizedFileName(&gMatchScene2PScreen),M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
}
CloseNarcArchive();
AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,void **,0x20),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=savedEngine;
M2C_FIELD(setup,u16 *,0x48)|=0x20;
sprite=M2C_FIELD(setup,void **,0x54);
SetupSetFrame(sprite,(u16)(((SetupSprite *)sprite)->baseFrame+2),0);
Show3DSpriteSlide(M2C_FIELD(setup,void **,0x58));
Hide3DSprite(M2C_FIELD(setup,void **,0x60));
SetTextById(M2C_FIELD(setup,void **,0x64),0x44000011);
Show3DSpriteSlide(M2C_FIELD(setup,void **,0x64));
if(GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68))) {
animValue=GetSpriteAnimValue(M2C_FIELD(setup,void **,0x68));
sprite=M2C_FIELD(setup,void **,0x68);
M2C_FIELD(sprite,u16 *,0xe)=animValue;
M2C_FIELD(sprite,u16 *,0x10)=0;
M2C_FIELD(sprite,u16 *,0xc)=12;
M2C_FIELD(sprite,u16 *,2)=M2C_FIELD(sprite,u16 *,4);
}
M2C_FIELD(setup,u16 *,0x48)&=~0x100;
M2C_FIELD(setup,u16 *,0x48)&=~0x200;
M2C_FIELD(setup,u8 *,0x41)=0;
layout=GetSetupCode((void *)setup);
func_ov010_02228f80(side,layout,1,(void *)MatchScenePeerClosedCallback,(void *)setup,(void *)WaitForMatchSession,(void *)setup,0);
}

/* Matchmaking scene's peer event callback: on a clean close (status 0, closed
 * nonzero) flag the scene (+0x48 bit 8) so its update closes the window and shows
 * the failure message. */
void MatchScenePeerClosedCallback(s32 status, s32 closed, void *scene) {
    if (status != 0) {
        return;
    }
    if (closed != 0) {
        M2C_FIELD(scene, u16 *, 0x48) = (u16) (M2C_FIELD(scene, u16 *, 0x48) | 0x100);
    }
}

/* Per-frame matchmaking wait for the 1v1 match scene: -1 until the local player
 * is online; then reads the opponent's skill rating (default RATING_DEFAULT) and
 * reports the maximum match quality. */
s32 WaitForMatchSession(M2C_UNK playerId) {
    M2C_UNK GetBrowsedServerValue(M2C_UNK, M2C_UNK *, s32);
    void *GetLocalPlayerStatus();
    extern M2C_UNK sMatchRatingKey;
    if (!(M2C_FIELD(GetLocalPlayerStatus(), u8 *, LOCAL_STATUS_OPTIONS) & LOCAL_OPTION_ONLINE)) {
        return -1;
    }
    GetBrowsedServerValue(playerId, &sMatchRatingKey, RATING_DEFAULT);
    return MATCH_QUALITY_MAX;
}

#pragma opt_strength_reduction on
/* Set up the 3D matching/unit scene: switch in the main sprite engine, load
 * the matching archive and the background for the player count, reset the
 * menu sprites, then start the ov010 scene either by its screen code or by
 * the unit selected in the menu. */
void SetupMatchingUnitScene(M2C_UNK setup, M2C_UNK side) {
    void Clear3DSpriteLayer(u8);
    void SetFileDirectory(void *);
    void *GetLocalizedFileName(void *);
    void OpenNarcArchive(void *);
    void LoadNarcFileDecompressed(void *, void *);
    void CloseNarcArchive(void);
    void AddTileRectPalette(void *, s32, s32, s32);
    void Show3DSpriteSlide(void *);
    void Hide3DSprite(void *);
    void SetTextById(void *, u32);
    s32 GetSpriteAnimValue(void *);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern M2C_UNK gLinkResourcePath;
    extern M2C_UNK gMatchingNarcPath;
    extern M2C_UNK gMatching4PScreen;
    extern M2C_UNK gMatching2PScreen;

    void func_ov010_02229190(s32,s32,s32,s32,s32,s32);
    void func_ov010_022292e4(s32,s32,s32,s32,s32,s32);
    void MatchingUnitSceneCallback(s32,s32,s32,s32,s32,void *);
    extern s32 gUnitSlotIds[];
    void *savedEngine = gCur3DSpriteEngine;
    s32 layout;
    s32 layout2;
    void *sprite;
    s32 baseFrame;
    u32 spriteWord;
    s32 animValue;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    SetFileDirectory(&gLinkResourcePath);
    OpenNarcArchive(GetLocalizedFileName(&gMatchingNarcPath));

    layout=GetSetupCode((void *)setup);
    switch(layout) {
    case 4: LoadNarcFileDecompressed(GetLocalizedFileName(&gMatching4PScreen), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    case 2: LoadNarcFileDecompressed(GetLocalizedFileName(&gMatching2PScreen), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    }

    CloseNarcArchive();
    AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;

    gCur3DSpriteEngine = savedEngine;

    M2C_FIELD((void *)setup, u16 *, 0x48) |= 0x20;

    sprite = M2C_FIELD((void *)setup, void **, 0x54);
    baseFrame = M2C_FIELD(sprite, u8 *, 0x59);
    baseFrame = (s32)((u32)(baseFrame << 28) >> 28);
    spriteWord = M2C_FIELD(sprite, u32 *, 0x40);
    spriteWord &= ~0x03FC0000u;
    spriteWord |= ((u32)(u16)(baseFrame + 2) << 24) >> 6;
    M2C_FIELD(sprite, u32 *, 0x40) = spriteWord;
    M2C_FIELD(sprite, u8 *, 0x5a) = 0;

    Show3DSpriteSlide(M2C_FIELD((void *)setup, void **, 0x58));
    Hide3DSprite(M2C_FIELD((void *)setup, void **, 0x60));
    SetTextById(M2C_FIELD((void *)setup, void **, 0x64), 0x44000011U);
    Show3DSpriteSlide(M2C_FIELD((void *)setup, void **, 0x64));

    if (GetSpriteAnimValue(M2C_FIELD((void *)setup, void **, 0x68)) != 0) {
        animValue = GetSpriteAnimValue(M2C_FIELD((void *)setup, void **, 0x68));
        sprite = M2C_FIELD((void *)setup, void **, 0x68);
        M2C_FIELD(sprite, u16 *, 0xe) = (u16)animValue;
        M2C_FIELD(sprite, u16 *, 0x10) = 0;
        M2C_FIELD(sprite, u16 *, 0xc) = 0xc;
        M2C_FIELD(sprite, u16 *, 0x2) = M2C_FIELD(sprite, u16 *, 0x4);
    }
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x100;
    M2C_FIELD((void *)setup, u16 *, 0x48) &= ~0x200;

    M2C_FIELD((void *)setup, u8 *, 0x41) = 0;
    if(M2C_FIELD((void *)setup,u16 *,0x48)&1) {
    layout2=GetSetupCode((void *)setup);
    func_ov010_02229190(side,layout2,(s32)MatchingUnitSceneCallback,setup,0,0);
    } else {
    func_ov010_022292e4(side,gUnitSlotIds[M2C_FIELD((void *)setup,s8 *,0x43)],(s32)MatchingUnitSceneCallback,setup,0,0);
    }
}
#pragma opt_strength_reduction off
/* Match event callback of the matching/unit scene: when a peer has closed the
 * connection and the match target was not cleared, flag the scene (+0x48 bit 8)
 * so its update closes the window and shows the failure message. */
void MatchingUnitSceneCallback(s32 status, s32 closed, s32 targetCleared, s32 serving, s32 slot, void *scene) {
    register u16 *flags = (u16 *)((u8 *)scene + 0x48);
    if (status != 0) return;
    if (closed == 0) return;
    if (targetCleared != 0) return;
    if (serving != 0) *flags |= 0x100;
}

/* Scene entry point: sets up the unit-preview scene for side 0 on the given
 * menu work object. */
void SetupUnitPreviewSceneSide0(M2C_UNK menu) {
    M2C_UNK SetupUnitPreviewScene(M2C_UNK, M2C_UNK);
    SetupUnitPreviewScene(menu, 0);
}

/* Thunk that prepares the ov009 3D unit preview menu for side 1, the
 * other-player/link view. */
void SetupUnitPreviewSceneSide1(M2C_UNK menu) {
    M2C_UNK SetupUnitPreviewScene(M2C_UNK, M2C_UNK);
    SetupUnitPreviewScene(menu, 1);
}

/* Set up the online scene for side 0 (see SetupScene). */
void SetupSceneSide0(M2C_UNK setup) {
    M2C_UNK SetupScene(M2C_UNK, M2C_UNK);
    SetupScene(setup, 0);
}

/* Scene entry point: sets up the scene for side 1 on the given work object. */
void SetupSceneSide1(M2C_UNK setup) {
    M2C_UNK SetupScene(M2C_UNK, M2C_UNK);
    SetupScene(setup, 1);
}

/* Set up the 1v1 match scene for side 0 (see SetupMatchScene). */
void SetupMatchSceneSide0(M2C_UNK setup) {
    M2C_UNK SetupMatchScene(M2C_UNK, M2C_UNK);
    SetupMatchScene(setup, 0);
}

/* Set up the 1v1 match scene for side 1 (see SetupMatchScene). */
void SetupMatchSceneSide1(M2C_UNK setup) {
    M2C_UNK SetupMatchScene(M2C_UNK, M2C_UNK);
    SetupMatchScene(setup, 1);
}

/* Scene entry point: sets up the matching unit scene for side 0 on the given
 * menu work object. */
void SetupMatchingUnitSceneSide0(M2C_UNK menu) {
    void SetupMatchingUnitScene(M2C_UNK, M2C_UNK);
    SetupMatchingUnitScene(menu, 0);
}

/* Scene entry point: sets up the matching unit scene for side 1 on the given
 * menu work object. */
void SetupMatchingUnitSceneSide1(M2C_UNK menu) {
    void SetupMatchingUnitScene(M2C_UNK, M2C_UNK);
    SetupMatchingUnitScene(menu, 1);
}

#pragma opt_strength_reduction off
void func_020debf4(void *self){void MenuSpriteUpdate(void*);
 int FindTextLayer(void);
 void StartWindowClose(void);
void *CreateTextLayer(void*);
void RenderTextLayerMessage(void*,int,int,u32);
void DisableMapConfirm(void);
void Sprite_ResumeAnimation(void*);
void PlaySoundEffect(u32);
u32 GetActivePlayerMask(void);
u32 CountBits(void);
u32 GetLinkConnectedPlayerCount(void);
void Show3DSpriteSlide(void*);
void Hide3DSpriteSlide(void*);
void SetTextById(void*,u32);
u32 GetSessionPlayerMask(void);
void GetLinkLocalPlayerInfo(void);
void RequestLinkDownloadMode(int);
void AnnounceLinkPlayer(void);
void EnableMapConfirm(void);
void ClearOverlayEventFlags(void);
int Is3DSpriteSliding(void*);
int Is3DSpriteVisible(void*);
void *GetActiveLinkPlayerSlot(int);
void SpawnLinkConnectRequest(void*);
extern void *gKeyState;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineSub;
extern void *g3DSpriteEngineMain;

s32 i, i2;
void *old,*p;
u16 keys;u32 v;
u8 can;
u32 frame;

if(M2C_FIELD(self,void * *,0x50))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x50));

if(M2C_FIELD(self,void * *,0x54))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x54));

if(M2C_FIELD(self,void * *,0x58))MenuSpriteUpdate(M2C_FIELD(self,void * *,0x58));

keys=M2C_FIELD(gKeyState,u16 *,0);
M2C_FIELD(self,u16 *,0x48)=M2C_FIELD(self,u16 *,0x48)&~0x20U;

if(!(M2C_FIELD(self,u16 *,0x48)&1)){
if(M2C_FIELD(self,u16 *,0x48)&0x100){if(FindTextLayer())StartWindowClose();
old=gCur3DSpriteEngine;
for(i=0;
i<2;
i++){gCur3DSpriteEngine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;

if(M2C_FIELD(self,u8 *,0x44)==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;

if(M2C_FIELD(self,u8 *,0x44)==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;

if(M2C_FIELD(self,u8 *,0x44)==3 && gCur3DSpriteEngine!=old)continue;

p=CreateTextLayer(self);
RenderTextLayerMessage(p,2,M2C_FIELD(self,u16 *,0x46)<<5,0x44000001);
M2C_FIELD(p,u32 *,0x58)|=0x1000;

}gCur3DSpriteEngine=old;
DisableMapConfirm();
Sprite_ResumeAnimation(self);
return;
}
else if(M2C_FIELD(self,u16 *,0x48)&0x200){if(FindTextLayer())StartWindowClose();
old=gCur3DSpriteEngine;
for(i2=0;
i2<2;
i2++){gCur3DSpriteEngine=i2==0?g3DSpriteEngineMain:g3DSpriteEngineSub;

if(M2C_FIELD(self,u8 *,0x44)==0 && gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;

if(M2C_FIELD(self,u8 *,0x44)==1 && gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;

if(M2C_FIELD(self,u8 *,0x44)==3 && gCur3DSpriteEngine!=old)continue;

p=CreateTextLayer(self);
RenderTextLayerMessage(p,2,M2C_FIELD(self,u16 *,0x46)<<5,0x44000002);
M2C_FIELD(p,u32 *,0x58)|=0x1000;

}gCur3DSpriteEngine=old;
DisableMapConfirm();
Sprite_ResumeAnimation(self);
return;
}}
p=M2C_FIELD(self,void * *,0x58);
frame=((SetupSprite*)p)->baseFrame;

if(SetupIsActive(p)){can=(u8)(M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xb)==1 || ((((SetupSprite*)p)->alternate) && M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xc)==1));
if(can||(keys&2)){
if(M2C_FIELD(p,s8 *,0x5a)>=0){SetupSetFrame(p,frame+1,12);
}
DisableMapConfirm();
Sprite_ResumeAnimation(self);
PlaySoundEffect(0x1000f);
return;
}}
GetActivePlayerMask();
v=CountBits();

if((M2C_FIELD(self,s8 *,0x41)>1||v>1)&&M2C_FIELD(self,s8 *,0x41)!=v)PlaySoundEffect(M2C_FIELD(self,s8 *,0x41)<(s32)v?0x122:0x123);

M2C_FIELD(self,u8 *,0x41)=v;

if(M2C_FIELD(self,u16 *,0x48)&1){
v=GetLinkConnectedPlayerCount();
p=M2C_FIELD(self,void * *,0x54);

if(v>=2){if(!SetupIsActive(p)){SetupSetFrame(p,((SetupSprite*)p)->baseFrame,0);
Show3DSpriteSlide(M2C_FIELD(self,void * *,0x54));
SetTextById(M2C_FIELD(self,void * *,0x64),0x44000012);
}}
else if(SetupIsActive(p)){SetupSetFrame(p,(((SetupSprite*)p)->baseFrame)+2,0);
Hide3DSpriteSlide(M2C_FIELD(self,void * *,0x54));
SetTextById(M2C_FIELD(self,void * *,0x64),0x44000011);
}
p=M2C_FIELD(self,void * *,0x54);
if(!SetupIsActive(p))return;

can=(u8)(M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xb)==1 || ((((SetupSprite*)p)->alternate) && M2C_FIELD(M2C_FIELD(p,void * *,0x64),s8 *,0xc)==1));
if(!can && !(keys&1))return;

v=GetSessionPlayerMask();
if(v!=GetActivePlayerMask())return;

GetLinkLocalPlayerInfo();
p=M2C_FIELD(self,void * *,0x54);

if(M2C_FIELD(p,s8 *,0x5a)>=0){SetupSetFrame(p,(((SetupSprite*)p)->baseFrame)+1,12);
}
RequestLinkDownloadMode(0);
AnnounceLinkPlayer();
EnableMapConfirm();
ClearOverlayEventFlags();
Sprite_ResumeAnimation(self);
PlaySoundEffect(0x1000e);return;

}else{
v=GetLinkConnectedPlayerCount();
p=M2C_FIELD(self,void * *,0x60);

if(v>=2){if(!Is3DSpriteSliding(p)&&!Is3DSpriteVisible(M2C_FIELD(self,void * *,0x60))){Show3DSpriteSlide(M2C_FIELD(self,void * *,0x60));
SetTextById(M2C_FIELD(self,void * *,0x64),0x44000012);
}}
else if(!Is3DSpriteSliding(p)&&Is3DSpriteVisible(M2C_FIELD(self,void * *,0x60))){Hide3DSpriteSlide(M2C_FIELD(self,void * *,0x60));
SetTextById(M2C_FIELD(self,void * *,0x64),0x44000011);
}
p=GetActiveLinkPlayerSlot(0);
if(!p||(M2C_FIELD(p,u8 *,0x16)&2))return;

v=GetSessionPlayerMask();
if(v!=GetActivePlayerMask())return;

SpawnLinkConnectRequest(self);

}
AnnounceLinkPlayer();
EnableMapConfirm();
ClearOverlayEventFlags();
Sprite_ResumeAnimation(self);
PlaySoundEffect(0x1000e);

}
#pragma opt_strength_reduction reset
