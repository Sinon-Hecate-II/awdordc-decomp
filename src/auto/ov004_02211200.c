/* 27 functions from 0x02211200 to 0x022120C0 (ov004), found by ds-decomp. */
#include "common.h"
#include "ov004_effect.h"
struct ScreenConfig1194 { u16 value[6]; };
struct ScreenConfigFields1194 { u16 a,b,c,d,e,f; };

/* The four stage battle themes, in campaign order: the map's stage number picks
 * one (played when the battle scene starts). */
#define MUSIC_STAGE_BATTLE_1 0x10013
#define MUSIC_STAGE_BATTLE_2 0x10014
#define MUSIC_STAGE_BATTLE_3 0x10015
#define MUSIC_STAGE_BATTLE_4 0x10016

/* High event-flag index that records the ov004 ending already ran: the first
 * entry claims it, later entries see it set. */
#define OV004_ENDING_SEEN_FLAG 0x60

void func_ov004_02211200(void) {
    M2C_UNK func_ov000_0216a7fc();
    func_ov000_0216a7fc();
}

/* ov004 map-event sprite handler: wait while a dialog is open, then resume the
 * sprite's animation so the event script continues. */
void Ov004_ResumeEventAfterDialog(void *sprite) {
    s32 IsDialogActive();
    void Sprite_ResumeAnimation(void *);
    if (IsDialogActive() != 0) {
        return;
    }
    Sprite_ResumeAnimation(sprite);
}

/* Create the ov004 map-event sprite under `owner`: it only exists in a team
 * (story) battle, so a map whose battle mode (the low three bits of
 * gMapConfig) is not team gets no event sprite. */
void CreateMapEventSprite(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK data_ov004_02218c00;
    if ((u8)((u32)(gMapConfig << 29) >> 29)) return;
    CreateSpriteObject(&data_ov004_02218c00, owner);
}

void func_ov004_02211260(void) {
    M2C_UNK RunEndingEvent();
    RunEndingEvent();
}

/* Battle-end step on the final campaign map: with no dialog open and the player
 * having won, load the ending resource, create the ending overlay object and
 * reset the text state, then resume the event sprite's animation. */
void Ov004_StartFinalMapEnding(M2C_UNK eventSprite) {
    M2C_UNK ResetTextState();
    M2C_UNK EnsureEndingResourceLoaded();
    s32 DidPlayerWin();
    s32 IsFinalCampaignMap();
    M2C_UNK func_ov004_02227ecc_unk(M2C_UNK);
    if (IsDialogActive() != 0) {
        return;
    }
    if ((DidPlayerWin() != 0) && (IsFinalCampaignMap() != 0)) {
        EnsureEndingResourceLoaded();
        func_ov004_02227ecc_unk(eventSprite);
        ResetTextState();
    }
    Sprite_ResumeAnimation(eventSprite);
}

/* Create the battle-end ending sprite for `owner`, but only in the team game
 * mode (map mode 0): the other map modes have no ending to show. */
void Ov004_CreateEndingSprite(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern u16 gMapConfig;
    extern M2C_UNK gOv004EndingSpriteClass;
    if ((u8)((u32)(gMapConfig << 29) >> 29)) return;
    CreateSpriteObject(&gOv004EndingSpriteClass, owner);
}

/* Resets the aircraft effect's scale, bob and event timers, then starts its sound. */
void Ov004_InitUraPlaneEffect(void *sprite) {
    s32 PlaySlotPendingSound(s32, s32, s32);
    Ov004UraPlaneEffect *effect = sprite;

    effect->scaleStart = OV004_URA_PLANE_SCALE_ONE;
    effect->scaleEnd = OV004_URA_PLANE_SCALE_ONE;
    effect->scaleFrame = 0;
    effect->scaleFrames = 0;
    effect->bombFrame = 0;
    effect->bombFrames = 0;
    effect->burstFrame = 0;
    effect->burstFrames = 0;
    effect->centerX = 128;
    effect->centerY = 96;
    effect->bobAmplitude = 2;
    effect->bobFrame = 0;
    effect->bobPeriod = 120;
    effect->offsetX = 0;
    effect->offsetY = 0;
    effect->scrollFrame = 0;
    PlaySlotPendingSound(0, -1, OV004_URA_PLANE_START_SOUND);
}

/* Tear down the ura_plane/ura_side aircraft effect: delete all sprite
 * wrappers and the 3D-sprite offset tracks, then fade out the effect's
 * sound (slot 0) over 30 frames. */
void Ov004_DestroyUraPlaneEffect(void) {
    M2C_UNK DeleteAllSpriteWrappers();
    M2C_UNK Delete3DSpriteOffsetTracks();
    M2C_UNK StopSlotSound(s32, s32);
    DeleteAllSpriteWrappers();
    Delete3DSpriteOffsetTracks();
    StopSlotSound(0, 0x1E);
}

M2C_UNK func_ov004_02211374(void *arg0) {
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 data_ov004_02218cb0;
    unsigned long long RuntimeIntDivMod(s32, s32);
    s32 Get3DSpriteTargetMode(void);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void *Build3DSpriteTransform(void *, void *);
    void CreateTimedSprite(s32, void *);
    void *Create3DSprite(void);
    M2C_UNK Slide3DSpriteOut(void *, s32, s32, s32, s32, s32);
    void SpawnSoundEffectFullVolume(s32, s32);
    s32 NextRandomValue(void);
    void *CreateAnimatedSpriteObject(void *);
    void LoadCompressedSpriteAssetsFromNarc(void *, void *, s32, s32, s32);
    M2C_UNK PlaySoundEffect(s32);

    u16 max;
    u16 half;
    s32 spC;
    s16 r11;
    s32 result2;
    s32 savedEngine;
    s32 loop;
    void *spr;
    struct {
        s32 f0;
        s32 f1;
        s16 a;
        s16 b;
        s16 c;
        s16 d;
        s16 e;
    } spblk;

    if (M2C_FIELD(arg0, u16 *, 0x38) < M2C_FIELD(arg0, u16 *, 0x3A)) {
        M2C_FIELD(arg0, u16 *, 0x38) = M2C_FIELD(arg0, u16 *, 0x38) + 1;
    }
    M2C_FIELD(arg0, u16 *, 0x3E) = (u16)(RuntimeIntDivMod(M2C_FIELD(arg0, u16 *, 0x3E) + 1, M2C_FIELD(arg0, u16 *, 0x40)) >> 32);
    max = M2C_FIELD(arg0, u16 *, 0x3A);
    spC = EaseInterpolate(4, M2C_FIELD(arg0, u16 *, 0x34), M2C_FIELD(arg0, u16 *, 0x36), M2C_FIELD(arg0, u16 *, 0x38), max);
    spC = spC & 0xFFFF;
    r11 = (s16)spC;
    half = (u16)(M2C_FIELD(arg0, u16 *, 0x40) >> 1);
    if (M2C_FIELD(arg0, u16 *, 0x3E) < half) {
        result2 = EaseInterpolate(4, -(s16)M2C_FIELD(arg0, s16 *, 0x3C), (s16)M2C_FIELD(arg0, s16 *, 0x3C), M2C_FIELD(arg0, s16 *, 0x38), half);
    } else {
        result2 = EaseInterpolate(1, (s16)M2C_FIELD(arg0, s16 *, 0x3C), -(s16)M2C_FIELD(arg0, s16 *, 0x3C), M2C_FIELD(arg0, u16 *, 0x3E) - half, half);
    }
    spC = result2 << 16;
    savedEngine = gCur3DSpriteEngine;
    loop = 0;
    while (loop < 2) {
        if (loop == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if (Get3DSpriteTargetMode() == 0 && gCur3DSpriteEngine != g3DSpriteEngineMain) goto skip_update;
        if (Get3DSpriteTargetMode() == 1 && gCur3DSpriteEngine != g3DSpriteEngineSub) goto skip_update;
        if (Get3DSpriteTargetMode() == 3 && gCur3DSpriteEngine != savedEngine) goto skip_update;

        M2C_FIELD(arg0, s16 *, 0x20) = 0;
        spblk.c = r11;
        spblk.d = r11;
        spblk.e = 0;
        spblk.a = M2C_FIELD(arg0, s16 *, 0x4A);
        spblk.b = M2C_FIELD(arg0, s16 *, 0x4C);
        spblk.f0 = M2C_FIELD(arg0, s16 *, 0x4A) + M2C_FIELD(arg0, s16 *, 0x4E) + M2C_FIELD((void *)gCur3DSpriteEngine, s16 *, 0x3C);
        spblk.f1 = M2C_FIELD(arg0, s16 *, 0x4C) + M2C_FIELD(arg0, s16 *, 0x50) + M2C_FIELD((void *)gCur3DSpriteEngine, s16 *, 0x3E) + (spC >> 16);

        Build3DSpriteTransform(&spblk, (void *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0) + 0x14);

        spblk.f0 = M2C_FIELD(arg0, s16 *, 0x4A);
        spblk.f1 = M2C_FIELD(arg0, s16 *, 0x4C);
        Build3DSpriteTransform(&spblk, (void *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0) + 0x24);

        if (M2C_FIELD(arg0, u16 *, 0x44) > M2C_FIELD(arg0, u16 *, 0x42)) {
            M2C_FIELD(arg0, u16 *, 0x42) = M2C_FIELD(arg0, u16 *, 0x42) + 1;
            if (M2C_FIELD(arg0, u16 *, 0x42) == M2C_FIELD(arg0, u16 *, 0x44)) {
                CreateTimedSprite(0x1E, arg0);
                spr = Create3DSprite();
                M2C_FIELD(spr, u16 *, 0x3E) = 0x35C;
                {
                    s32 uu = M2C_FIELD(spr, u32 *, 0x40);
                    uu = (uu & ~0x3FC0000) | 0x2C0000;
                    M2C_FIELD(spr, u32 *, 0x40) = uu;
                }
                M2C_FIELD(spr, u8 **, 0x44) = (u8 *)data_ov004_02218cb0;
                M2C_FIELD(spr, u16 *, 0x3C) = 0x800;
                Slide3DSpriteOut(spr, 0x78, 0x60, 0x78, 0xC0, 0x1E);
                SpawnSoundEffectFullVolume(0xF8, 0x14);
            }
        }

        if (M2C_FIELD(arg0, u16 *, 0x48) > M2C_FIELD(arg0, u16 *, 0x46)) {
            M2C_FIELD(arg0, u16 *, 0x46) = M2C_FIELD(arg0, u16 *, 0x46) + 1;
            if ((M2C_FIELD(arg0, u16 *, 0x46) & 0x1F) == 1) {
                s32 t1 = NextRandomValue();
                s32 r8 = (t1 % 0xC0) + 0x20 - M2C_FIELD(arg0, s16 *, 0x4E);
                s32 t2 = NextRandomValue();
                s32 r9 = (t2 % 0x40) + 0x20 - M2C_FIELD(arg0, s16 *, 0x50);
                spr = CreateAnimatedSpriteObject(arg0);
                LoadCompressedSpriteAssetsFromNarc(spr, (void *)data_ov004_02218cb0, 0, 0, 0);
                M2C_FIELD(spr, s32 *, 0x34) = r8;
                M2C_FIELD(spr, s32 *, 0x38) = r9;
                M2C_FIELD(spr, s32 *, 0x3C) = 0;
                PlaySoundEffect(0xFA);
            }
            M2C_FIELD(arg0, u16 *, 0x4E) = (u16)EaseInterpolate(0, 0, 0x20, M2C_FIELD(arg0, u16 *, 0x46), M2C_FIELD(arg0, u16 *, 0x48));
            M2C_FIELD(arg0, u16 *, 0x50) = (u16)EaseInterpolate(0, 0, -96, M2C_FIELD(arg0, u16 *, 0x46), M2C_FIELD(arg0, u16 *, 0x48));
        }

        M2C_FIELD(arg0, u16 *, 0x52) = M2C_FIELD(arg0, u16 *, 0x52) + 1;
        {
            u16 c = M2C_FIELD(arg0, u16 *, 0x52);
            void *eng = (void *)gCur3DSpriteEngine;
            u16 h;
            h = c >> 1;
            h = 0 - h;
            M2C_FIELD(eng, u16 *, 0x38) = h;
            h = c >> 2;
            M2C_FIELD(eng, u16 *, 0x40) = h;
            h = c >> 2;
            h = 0 - h;
            M2C_FIELD(eng, u16 *, 0x3A) = h;
            h = c >> 1;
            M2C_FIELD(eng, u16 *, 0x42) = h;
        }
        loop++;

skip_update:
        ;
    }
    gCur3DSpriteEngine = savedEngine;
    return 0;
}

void func_ov004_02211740(void) {

}

/* Load the ura-plane bomb ("ura_bomb") graphics into both screen contexts when the
 * current mode permits. */
void Ov004_LoadUraBombGraphics(void *ctx) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern u8 data_ov004_02218cbc[], data_ov004_02218cc4[], data_ov004_02218cd4[], data_ov004_02218ce0[];
    s32 Get3DSpriteTargetMode(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x42) = 0;
    M2C_FIELD(ctx, s16 *, 0x44) = 48;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if ((Get3DSpriteTargetMode() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (Get3DSpriteTargetMode() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (Get3DSpriteTargetMode() != 3 || gCur3DSpriteEngine == savedContext)) {
            SetFileDirectory(data_ov004_02218cbc);
            OpenNarcArchive(data_ov004_02218cc4);
            LoadNarcFileDecompressed(data_ov004_02218cd4, M2C_FIELD((void *)gCur3DSpriteEngine, u8 **, 0x1c) + 0x6b80);
            LoadNarcFileToSpriteBuffer(data_ov004_02218ce0, 0x360, 0x20);
            CloseNarcArchive();
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

/* Load a graphics resource set into both screen contexts when the current mode permits. */
void Ov004_LoadUraBurstGraphics(void *ctx) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
    extern u8 data_ov004_02218cec[];
    s32 Get3DSpriteTargetMode(void);
    s32 savedContext, i;
    M2C_FIELD(ctx, s16 *, 0x46) = 0;
    M2C_FIELD(ctx, s16 *, 0x48) = 360;
    savedContext = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) gCur3DSpriteEngine = g3DSpriteEngineMain; else gCur3DSpriteEngine = g3DSpriteEngineSub;
        if ((Get3DSpriteTargetMode() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (Get3DSpriteTargetMode() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (Get3DSpriteTargetMode() != 3 || gCur3DSpriteEngine == savedContext)) {
            LoadCompressedSpriteGraphics(data_ov004_02218cec, 0, 0);
            Create3DSpriteOffsetTrack(1, 1, 0, 100, 0);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

/* Aim the ura-plane effect's zoom at (`centerX`, `centerY`) and restart it:
 * scale from `startScale` to `endScale` over `frames` frames. */
void Ov004_SetUraPlaneZoom(Ov004UraPlaneEffect *effect, s16 centerX, s16 centerY, s16 startScale, s32 endScale, s32 frames) {
    effect->centerX = centerX;
    effect->centerY = centerY;
    effect->scaleStart = startScale;
    effect->scaleEnd = (s16) endScale;
    effect->scaleFrames = (s16) frames;
    effect->scaleFrame = 0;
}

void LoadUraEffectAssets(M2C_UNK arg0, M2C_UNK *arg1) {
    M2C_UNK OffsetTileIndices(s32, u16, M2C_UNK);
    u32 Get3DSpriteLayerSize(u8, M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK StringFormat(void *, void *, void *);
    M2C_UNK OpenNarcArchive(M2C_UNK *);
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(M2C_UNK *, s32);
    M2C_UNK LoadNarcFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK LoadNarcFileToBGExtPltt(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Apply3DSpriteLayout(u16 *);
    s32 Get3DSpriteTargetMode();
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov004_02218bac;
    extern M2C_UNK data_ov004_02218cf8;
    extern M2C_UNK data_ov004_02218d00;
    extern M2C_UNK data_ov004_02218d10;
    extern M2C_UNK data_ov004_02218d1c;
    extern M2C_UNK data_ov004_02218d28;
    extern M2C_UNK data_ov004_02218d34;
    extern M2C_UNK data_ov004_02218d40;
    extern M2C_UNK data_ov004_02218d48;
    extern M2C_UNK data_ov004_02218d50;
    extern M2C_UNK data_ov004_02218d58;
    extern M2C_UNK data_ov004_02218d60;
    extern M2C_UNK data_ov004_02218d6c;
    extern M2C_UNK data_ov004_02218d78;
    extern M2C_UNK data_ov004_02218d84;
    u8 buffer[32];
    u16 config[6];u16 b,a,d,c,e,f;
    u16 *volatile sp3C;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;
    u16 *temp_r0;
    u16 *temp_r0_10;
    u16 *temp_r0_11;
    u16 *temp_r0_12;
    u16 *temp_r0_13;
    u16 *temp_r0_14;
    u16 *temp_r0_15;
    u16 *temp_r0_16;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    u16 *temp_r0_7;
    u16 *temp_r0_8;
    u16 *temp_r0_9;
    s32 temp_r8;
    s32 var_r9;
    s32 var_r0;

    var_r9 = 0;
a=M2C_FIELD(&data_ov004_02218bac,u16 *,0);b=M2C_FIELD(&data_ov004_02218bac,u16 *,2);
config[0]=a;config[1]=b;
d=M2C_FIELD(&data_ov004_02218bac,u16 *,6);c=M2C_FIELD(&data_ov004_02218bac,u16 *,4);
config[3]=d;config[2]=c;
e=M2C_FIELD(&data_ov004_02218bac,u16 *,8);f=M2C_FIELD(&data_ov004_02218bac,u16 *,10);
config[4]=e;config[5]=f;
    temp_r8=gCur3DSpriteEngine;
    do {
        if (var_r9 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r0;
        if (((Get3DSpriteTargetMode() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((Get3DSpriteTargetMode() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((Get3DSpriteTargetMode() != 3) || (gCur3DSpriteEngine == temp_r8))) {
            Apply3DSpriteLayout(config);
            SetFileDirectory(&data_ov004_02218cf8);
            OpenNarcArchive(&data_ov004_02218d00);
            LoadNarcFileDecompressed(&data_ov004_02218d10, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC));
            LoadNarcFileToSpriteBuffer(&data_ov004_02218d1c, 0, 0x20);
            LoadNarcFileDecompressed(&data_ov004_02218d28, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
            LoadNarcFileDecompressed(&data_ov004_02218d34, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            CloseNarcArchive();
            StringFormat(buffer, &data_ov004_02218d40, arg1);
            OpenNarcArchive(buffer);
            StringFormat(buffer, &data_ov004_02218d48, arg1);
            LoadNarcFileDecompressed(buffer, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
            StringFormat(buffer, &data_ov004_02218d50, arg1);
            LoadNarcFileDecompressed(buffer, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
            StringFormat(buffer, &data_ov004_02218d58, arg1);
            LoadNarcFileToBGExtPltt(buffer, 2, 0, 0x200);
            OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28), (u16)Get3DSpriteLayerSize((u8) ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 2), 0);
            CloseNarcArchive();
            OpenNarcArchive(&data_ov004_02218d60);
            LoadNarcFileDecompressed(&data_ov004_02218d6c, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
            LoadNarcFileDecompressed(&data_ov004_02218d78, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
            LoadNarcFileToBGExtPltt(&data_ov004_02218d84, 3, 0x200, 0x200);
            OffsetTileIndices(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), (u16)Get3DSpriteLayerSize((u8) ((u32) (*M2C_FIELD(gCur3DSpriteEngine, u16 **, 0) << 0x1D) >> 0x1D), 3), 0x1000);
            CloseNarcArchive();
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x38) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x40) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x42) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3C) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x44) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3E) = 0;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x46) = 0;
            temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp3C = (u16*)((u8*)temp_r0+0x12);
            *sp3C = (s16) ((*sp3C & ~0xC0) | 0x40);
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 4;
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0xC;
            temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp38 = (u16*)((u8*)temp_r0_2+0x12);
            *sp38 = (s16) (*sp38 & ~1);
            temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp34 = (u16*)((u8*)temp_r0_3+0x12);
            *sp34 = (s16) (*sp34 | 2);
            temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp30 = (u16*)((u8*)temp_r0_4+0x12);
            *sp30 = (s16) (*sp30 & ~4);
            temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp2C = (u16*)((u8*)temp_r0_5+0x12);
            *sp2C = (s16) (*sp2C & ~8);
            temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp28 = (u16*)((u8*)temp_r0_6+0x12);
            *sp28 = (s16) (*sp28 & ~0x10);
            temp_r0_7 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp24 = (u16*)((u8*)temp_r0_7+0x12);
            *sp24 = (s16) (*sp24 & ~0x100);
            temp_r0_8 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp20 = (u16*)((u8*)temp_r0_8+0x12);
            *sp20 = (s16) (*sp20 & ~0x200);
            temp_r0_9 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp1C = (u16*)((u8*)temp_r0_9+0x12);
            *sp1C = (s16) (*sp1C & ~0x400);
            temp_r0_10 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp18 = (u16*)((u8*)temp_r0_10+0x12);
            *sp18 = (s16) (*sp18 | 0x800);
            temp_r0_11 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp14 = (u16*)((u8*)temp_r0_11+0x12);
            *sp14 = (s16) (*sp14 & ~0x1000);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
            temp_r0_12 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp10 = temp_r0_12;
            *sp10 = *sp10 & ~0x10;
            temp_r0_13 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            spC = temp_r0_13;
            *spC = *spC | 0x20;
            temp_r0_14 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp8 = temp_r0_14;
            *sp8 = *sp8 | 0x40;
            temp_r0_15 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp4 = temp_r0_15;
            *sp4 = *sp4 | 0x80;
            temp_r0_16 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
            sp0 = temp_r0_16;
            *sp0 = *sp0 | 0x100;
        }
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
}

void func_ov004_02211ee8(void) {
    void Ov004_InitUraPlaneEffect();
    Ov004_InitUraPlaneEffect();
}

void func_ov004_02211ef4(void) {
    void Ov004_DestroyUraPlaneEffect();
    Ov004_DestroyUraPlaneEffect();
}

void func_ov004_02211f00(void) {
    M2C_UNK func_ov004_02211374();
    func_ov004_02211374();
}

void func_ov004_02211f0c(void) {
    func_ov004_02211740();
}

/* Create the ura_plane effect sprite in layer 7 and load the "ura_plane" asset set
 * into the sprite layers of both engines. */
void Ov004_CreateUraPlaneEffect(void) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    void LoadUraEffectAssets(s32, M2C_UNK *);
    extern M2C_UNK gUraPlaneEffectClass;
    extern M2C_UNK sUraPlaneAssetName;

    LoadUraEffectAssets(CreateSpriteFromClass(&gUraPlaneEffectClass, 7), &sUraPlaneAssetName);
}

/* Create the ura_side effect sprite in layer 7 and load the "ura_side" asset set
 * into the sprite layers of both engines. */
void Ov004_CreateUraSideEffect(void) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    void LoadUraEffectAssets(s32, M2C_UNK *);
    extern M2C_UNK gUraPlaneEffectClass;
    extern M2C_UNK sUraSideAssetName;

    LoadUraEffectAssets(CreateSpriteFromClass(&gUraPlaneEffectClass, 7), &sUraSideAssetName);
}

/* Reload the "ura_bomb" graphics for the ura-plane effect, but only while its
 * effect sprite still exists; the reload reuses the sprite as its context. */
void Ov004_ReloadUraBombGraphics(void) {
    void Ov004_LoadUraBombGraphics(void *effect);
    s32 FindObjectByClass(M2C_UNK *spriteClass);
    extern M2C_UNK gUraPlaneEffectClass;
    M2C_UNK effect = FindObjectByClass(&gUraPlaneEffectClass);
    if (effect == 0) {
        return;
    }
    Ov004_LoadUraBombGraphics((void *)effect);
}

/* Reload the "ura_burst" graphics for the ura-plane effect, but only while its
 * effect sprite still exists; the reload reuses the sprite as its context. */
void Ov004_ReloadUraBurstGraphics(void) {
    void Ov004_LoadUraBurstGraphics(void *effect);
    s32 FindObjectByClass(M2C_UNK *spriteClass);
    extern M2C_UNK gUraPlaneEffectClass;
    M2C_UNK effect = FindObjectByClass(&gUraPlaneEffectClass);
    if (effect == 0) {
        return;
    }
    Ov004_LoadUraBurstGraphics((void *)effect);
}

/* Zoom the ura-plane effect in from 1x to 8x over 60 frames, centred at
 * (160, 128), and play its zoom sound. */
void Ov004_ZoomInUraPlane(void) {
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gUraPlaneEffectClass;
    s32 effect;
    effect = FindObjectByClass(&gUraPlaneEffectClass);
    if (effect == 0) return;
    Ov004_SetUraPlaneZoom((void *)effect, 0xA0, 0x80, OV004_URA_PLANE_SCALE_ONE, OV004_URA_PLANE_ZOOM_IN_SCALE, OV004_URA_PLANE_ZOOM_IN_FRAMES);
    PlaySoundEffect(0x113);
}

/* Start the ura-plane effect shrinking back from 4x to its normal scale over 30
 * frames, centred on the upper screen, and play its sound.  Nothing to do when
 * the effect object is not present. */
void Ov004_ZoomOutUraPlane(void) {
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gUraPlaneEffectClass;
    s32 effect;

    effect = FindObjectByClass(&gUraPlaneEffectClass);
    if (effect == 0) return;
    Ov004_SetUraPlaneZoom((void *)effect, 0x80, 0x60, 0x400, OV004_URA_PLANE_SCALE_ONE, 0x1E);
    PlaySoundEffect(0x112);
}

void func_ov004_02212048(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gUraPlaneEffectClass;
    DeleteSpriteObjectsOfClass(&gUraPlaneEffectClass);
}

/* Claim the ov004 ending for its first run: returns 1 and marks the ending-seen
 * high event flag the first time, then returns 0 since it is already marked. */
s32 Ov004_ClaimEndingOnce(void) {
    M2C_UNK SetEventFlagHigh(M2C_UNK, M2C_UNK);
    s32 IsEventFlagHighSet(M2C_UNK);
    if (IsEventFlagHighSet(OV004_ENDING_SEEN_FLAG) != 0) {
        return 0;
    }
    SetEventFlagHigh(OV004_ENDING_SEEN_FLAG, 1);
    return 1;
}

/* Play the battle theme of the map's stage: the battle record's stage number
 * (+0x3A) picks one of the four stage battle themes, later stages getting a
 * later theme. */
void Ov004_PlayStageBattleMusic(void *battle) {
    M2C_UNK PlayMusicTrack(s32);
    s32 track;
    u8 stage;

    stage = M2C_FIELD(battle, u8 *, 0x3A);
    track = MUSIC_STAGE_BATTLE_1;
    if ((u32) stage >= 0xBU) {
        track = MUSIC_STAGE_BATTLE_2;
    }
    if ((u32) stage >= 0x11U) {
        track = MUSIC_STAGE_BATTLE_3;
    }
    if ((u32) stage >= 0x16U) {
        track = MUSIC_STAGE_BATTLE_4;
    }
    PlayMusicTrack(track);
}

