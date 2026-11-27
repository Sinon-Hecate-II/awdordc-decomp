/* 14 functions from 0x0221ABF8 to 0x0221BB70 (ov005), found by ds-decomp. */
#include "common.h"
#include "ov005_results.h"

static inline s32 MaxU8(u8 a, u8 b, u8 c) {
    s32 m;
    if (a > b) m = a; else m = b;
    if (m <= c) m = c;
    return m;
}

/* Per-frame count-up of a result row's three scores: each score rises by one
 * towards its gCoState rating (holding A or touching skips straight to it),
 * loads the "number_y" graphics as it passes 100 and spawns its effect sprite
 * when it arrives.  A sound plays whenever a score finishes and every fourth
 * frame while any is still counting; once all three have arrived the final
 * sprite is spawned and the row's animation resumes. */
void ResultScoreRow_CountUp(void *row) {
    extern M2C_UNK gCoState;
    extern u16 *gKeyState;
    extern void *gTouchState;
    extern M2C_UNK gResultEffectSpriteClass, gResultEffectSpriteVtbl, data_ov005_0222120c;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02221218, data_ov005_02221224, gFrameCounter;
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK, M2C_UNK, M2C_UNK);
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    M2C_UNK MI_CpuCopy32(void *, void *, M2C_UNK);
    M2C_UNK PlaySoundEffect(M2C_UNK);
    M2C_UNK Sprite_ResumeAnimation(void *);
    s32 counting = 0;
    s32 finished = counting;
    s32 scoreBefore;
    s32 skipCountUp;
    void *effect;

    scoreBefore = M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0);
    if (scoreBefore < M2C_FIELD(&gCoState, u8 *, CO_STATE_SPEED)) {
        M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0) = scoreBefore + 1;
        if ((*gKeyState & 1) || M2C_FIELD(gTouchState, u8 *, 0x14)) {
            skipCountUp = 1;
        } else {
            skipCountUp = 0;
        }
        if (skipCountUp) {
            M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0) = M2C_FIELD(&gCoState, u8 *, CO_STATE_SPEED);
        }
        if (scoreBefore < 100 && M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0) >= 100) {
            LoadFileToSpriteBuffer((M2C_UNK)&data_ov005_0222120c, 0x2c0, 0x20);
        }
        if (M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0) == M2C_FIELD(&gCoState, u8 *, CO_STATE_SPEED)) {
            effect = CreateSpriteFromClass(&gResultEffectSpriteClass, (M2C_UNK)row);
            if (effect != NULL) {
                M2C_FIELD(effect, M2C_UNK **, 0) = &gResultEffectSpriteVtbl;
                M2C_FIELD(effect, s32 *, 0x58) = 0x7fff;
                M2C_FIELD(effect, s32 *, 0x60) = 2;
                M2C_FIELD(effect, s32 *, 0x64) = 0x10;
                M2C_FIELD(effect, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2c0;
                MI_CpuCopy32(M2C_FIELD(effect, void **, 0x54), (u8 *)effect + 0x34, 0x20);
                M2C_FIELD(effect, s32 *, 0x5c) = 0;
            }
            finished = 1;
        } else {
            counting = 1;
        }
    }

    scoreBefore = M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1);
    if (scoreBefore < M2C_FIELD(&gCoState, u8 *, CO_STATE_POWER)) {
        M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1) = scoreBefore + 1;
        if ((*gKeyState & 1) || M2C_FIELD(gTouchState, u8 *, 0x14)) {
            skipCountUp = 1;
        } else {
            skipCountUp = 0;
        }
        if (skipCountUp) {
            M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1) = M2C_FIELD(&gCoState, u8 *, CO_STATE_POWER);
        }
        if (scoreBefore < 100 && M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1) >= 100) {
            LoadFileToSpriteBuffer((M2C_UNK)&data_ov005_02221218, 0x2e0, 0x20);
        }
        if (M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1) == M2C_FIELD(&gCoState, u8 *, CO_STATE_POWER)) {
            effect = CreateSpriteFromClass(&gResultEffectSpriteClass, (M2C_UNK)row);
            if (effect != NULL) {
                M2C_FIELD(effect, M2C_UNK **, 0) = &gResultEffectSpriteVtbl;
                M2C_FIELD(effect, s32 *, 0x58) = 0x7fff;
                M2C_FIELD(effect, s32 *, 0x60) = 2;
                M2C_FIELD(effect, s32 *, 0x64) = 0x10;
                M2C_FIELD(effect, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2e0;
                MI_CpuCopy32(M2C_FIELD(effect, void **, 0x54), (u8 *)effect + 0x34, 0x20);
                M2C_FIELD(effect, s32 *, 0x5c) = 0;
            }
            finished = 1;
        } else {
            counting = 1;
        }
    }

    scoreBefore = M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2);
    if (scoreBefore < M2C_FIELD(&gCoState, u8 *, CO_STATE_TECHNIQUE)) {
        M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2) = scoreBefore + 1;
        if ((*gKeyState & 1) || M2C_FIELD(gTouchState, u8 *, 0x14)) {
            skipCountUp = 1;
        } else {
            skipCountUp = 0;
        }
        if (skipCountUp) {
            M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2) = M2C_FIELD(&gCoState, u8 *, CO_STATE_TECHNIQUE);
        }
        if (scoreBefore < 100 && M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2) >= 100) {
            LoadFileToSpriteBuffer((M2C_UNK)&data_ov005_02221224, 0x300, 0x20);
        }
        if (M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2) == M2C_FIELD(&gCoState, u8 *, CO_STATE_TECHNIQUE)) {
            effect = CreateSpriteFromClass(&gResultEffectSpriteClass, (M2C_UNK)row);
            if (effect != NULL) {
                M2C_FIELD(effect, M2C_UNK **, 0) = &gResultEffectSpriteVtbl;
                M2C_FIELD(effect, s32 *, 0x58) = 0x7fff;
                M2C_FIELD(effect, s32 *, 0x60) = 2;
                M2C_FIELD(effect, s32 *, 0x64) = 0x10;
                M2C_FIELD(effect, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x300;
                MI_CpuCopy32(M2C_FIELD(effect, void **, 0x54), (u8 *)effect + 0x34, 0x20);
                M2C_FIELD(effect, s32 *, 0x5c) = 0;
            }
            finished = 1;
        } else {
            counting = 1;
        }
    }
    if (finished) {
        PlaySoundEffect(0x10024);
    }
    if (counting && !(gFrameCounter & 3)) {
        PlaySoundEffect(0x10023);
    }
    if (M2C_FIELD(row, s32 *, RESULT_ROW_SCORE0) != M2C_FIELD(&gCoState, u8 *, CO_STATE_SPEED) ||
        M2C_FIELD(row, s32 *, RESULT_ROW_SCORE1) != M2C_FIELD(&gCoState, u8 *, CO_STATE_POWER) ||
        M2C_FIELD(row, s32 *, RESULT_ROW_SCORE2) != M2C_FIELD(&gCoState, u8 *, CO_STATE_TECHNIQUE)) {
        return;
    }
    effect = CreateSpriteFromClass(&gResultEffectSpriteClass, (M2C_UNK)row);
    if (effect != NULL) {
        M2C_FIELD(effect, M2C_UNK **, 0) = &gResultEffectSpriteVtbl;
        M2C_FIELD(effect, s32 *, 0x58) = 0x7fff;
        M2C_FIELD(effect, s32 *, 0x60) = 2;
        M2C_FIELD(effect, s32 *, 0x64) = 0x10;
        M2C_FIELD(effect, s32 *, 0x54) = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x320;
        MI_CpuCopy32(M2C_FIELD(effect, void **, 0x54), (u8 *)effect + 0x34, 0x20);
        M2C_FIELD(effect, s32 *, 0x5c) = 0;
    }
    Sprite_ResumeAnimation(row);
}

/* Refresh the results screen's page sprite (the screen object's +0x38): rebuild
 * its cell list from the sprite's position and size. */
void RefreshResultPageSprite(void) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK func_020aad18(s32);
    extern M2C_UNK gResultsScreenClass;
    func_020aad18(M2C_FIELD(FindObjectByClass(&gResultsScreenClass), s32 *, RESULTS_SCREEN_PAGE));
}

/* Results-screen dismiss step: once the player presses A, play the dismiss
 * sound, hide the results page sprite's OAM cell and resume the animation. */
void ResultScreenDismissStep(void *sprite) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK RemoveSpriteCell(void *, s32);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    extern M2C_UNK gResultsScreenClass;
    void *unitSprite;
    u8 visible;
    if (!(*gKeyState & KEY_A)) return;
    PlaySoundEffect(0x1000D);
    unitSprite = M2C_FIELD(M2C_FIELD(FindObjectByClass(&gResultsScreenClass), void **, 0x38), void **, 0x64);
    visible = M2C_FIELD(unitSprite, u8 *, 0x12) != 0;
    if (visible) RemoveSpriteCell(unitSprite, 1);
    Sprite_ResumeAnimation(sprite);
}

/* Slides a results-screen score row back out to the right over
 * RESULT_ROW_SLIDE_FRAMES frames; once it has gone, the row clears the layer its
 * digits were drawn on (marking it dirty and resetting its x offset) and deletes
 * itself. */
void ResultScoreRow_SlideOut(void *row) {
    M2C_UNK Clear3DSpriteLayer(s32);
    M2C_UNK DeleteSpriteObject(void *);
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(row, s32 *, RESULT_ROW_ELAPSED) += 1;
    M2C_FIELD(row, s32 *, RESULT_ROW_SLIDE_X) = EaseInterpolate(EASE_IN_QUAD, 0, RESULT_ROW_SLIDE_END, M2C_FIELD(row, s32 *, RESULT_ROW_ELAPSED), RESULT_ROW_SLIDE_FRAMES);
    if (M2C_FIELD(row, s32 *, RESULT_ROW_ELAPSED) != RESULT_ROW_SLIDE_FRAMES) return;
    Clear3DSpriteLayer(RESULT_SCORE_LAYER);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, DS3D_QUAD_X + 2 * RESULT_SCORE_LAYER) = 0;
    M2C_FIELD(row, s32 *, RESULT_ROW_ELAPSED) = 0;
    DeleteSpriteObject(row);
}

/* Draws the three result-screen scores (at +0x3C/+0x40/+0x44) and their total as
 * right-to-left decimal digit 3D sprites, rows at y 0x12/0x26/0x3a/0x50, shifted
 * horizontally by the scroll value at +0x38. */
M2C_UNK func_ov005_0221b114(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern u8 gSpriteDesc8x8[];
    M2C_UNK DivMod(s32, s32, s32 *, s32 *);
    M2C_UNK AddSprite(u16, u16, u16, void *, s32);
    s32 startX0, offset0, high0;
    s32 startX1, offset1, high1;
    s32 startX2, offset2, high2;
    s32 startX3, offset3, high3;
    s32 number0, digit0, number1, digit1, number2, digit2, number3, digit3;
    s32 bppShift, tileBase;
    u16 bankFlags;

    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x3C) =
        (u16)(-M2C_FIELD(arg0, s32 *, 0x38));

    startX0 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    number0 = M2C_FIELD(arg0, s32 *, 0x3C);
    offset0 = 0;
    high0 = startX0 & 0xfe00;
    do {
        DivMod(number0, 10, &number0, &digit0);
        bankFlags = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        bppShift = ((u32)(bankFlags << 17)) >> 30;
        tileBase = 0x3ff & (0x140 >> bppShift);
        AddSprite((u16)(((startX0 - offset0) & 0x1ff) | high0), 0x12,
            (u16)(((digit0 & 0x3ff) + tileBase) | 0x6000), gSpriteDesc8x8, 0);
        offset0 += 8;
    } while (number0 != 0);

    startX1 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    number1 = M2C_FIELD(arg0, s32 *, 0x40);
    offset1 = 0;
    high1 = startX1 & 0xfe00;
    do {
        DivMod(number1, 10, &number1, &digit1);
        bankFlags = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        bppShift = ((u32)(bankFlags << 17)) >> 30;
        tileBase = 0x3ff & (0x140 >> bppShift);
        AddSprite((u16)(((startX1 - offset1) & 0x1ff) | high1), 0x26,
            (u16)(((digit1 & 0x3ff) + tileBase) | 0x7000), gSpriteDesc8x8, 0);
        offset1 += 8;
    } while (number1 != 0);

    startX2 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    number2 = M2C_FIELD(arg0, s32 *, 0x44);
    offset2 = 0;
    high2 = startX2 & 0xfe00;
    do {
        DivMod(number2, 10, &number2, &digit2);
        bankFlags = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        bppShift = ((u32)(bankFlags << 17)) >> 30;
        tileBase = 0x3ff & (0x140 >> bppShift);
        AddSprite((u16)(((startX2 - offset2) & 0x1ff) | high2), 0x3a,
            (u16)(((digit2 & 0x3ff) + tileBase) | 0x8000), gSpriteDesc8x8, 0);
        offset2 += 8;
    } while (number2 != 0);

    startX3 = (M2C_FIELD(arg0, s32 *, 0x38) + 0xa4) & 0x1ff;
    number3 = M2C_FIELD(arg0, s32 *, 0x3C) + M2C_FIELD(arg0, s32 *, 0x40) + M2C_FIELD(arg0, s32 *, 0x44);
    offset3 = 0;
    high3 = startX3 & 0xfe00;
    do {
        DivMod(number3, 10, &number3, &digit3);
        bankFlags = M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0);
        bppShift = ((u32)(bankFlags << 17)) >> 30;
        tileBase = 0x3ff & (0x140 >> bppShift);
        AddSprite((u16)(((startX3 - offset3) & 0x1ff) | high3), 0x50,
            (u16)(((digit3 & 0x3ff) + tileBase) | 0x9000), gSpriteDesc8x8, 0);
        offset3 += 8;
    } while (number3 != 0);
    return number3;
}

void func_ov005_0221b424(void) {
    M2C_UNK ResultScoreRow_SlideIn();
    ResultScoreRow_SlideIn();
}

void func_ov005_0221b430(void) {
    void ResultScoreRow_CountUp();
    ResultScoreRow_CountUp();
}

/* Create the result screen's slide transition object: a slide of the slide class
 * under the owner's parent, with the slide vtable and a back pointer to the owner
 * (whose child count it raises), its timer/Y/active fields set, and the page
 * sprite it slides taken from the results screen.  Does nothing when the sprite
 * cannot be allocated. */
void CreateResultSlideObject(void *owner) {
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK IncrementSpriteChildCount(s32);
    u32 GetSpriteParent(void *);
    extern M2C_UNK gResultSlideAnimScript;
    extern M2C_UNK gResultsScreenClass;
    extern M2C_UNK gResultSlideSpriteVtbl;
    void *slide;

    slide = CreateSpriteFromClass(&gResultSlideAnimScript, GetSpriteParent(owner));
    if (slide == NULL) {
        return;
    }
    M2C_FIELD(slide, M2C_UNK **, DS3D_SPRITE_CLASS) = &gResultSlideSpriteVtbl;
    M2C_FIELD(slide, s32 *, RESULT_SLIDE_OWNER) = (s32) owner;
    IncrementSpriteChildCount(owner);
    M2C_FIELD(slide, s32 *, RESULT_SLIDE_TIMER) = 0;
    M2C_FIELD(slide, s32 *, RESULT_SLIDE_Y) = 0x20;
    M2C_FIELD(slide, s8 *, RESULT_SLIDE_ACTIVE) = 1;
    M2C_FIELD(slide, s32 *, 0x34) = (s32) M2C_FIELD(FindObjectByClass(&gResultsScreenClass), s32 *, 0x38);
}

void func_ov005_0221b4a8(void) {
    void RefreshResultPageSprite(void);
    RefreshResultPageSprite();
}

void func_ov005_0221b4b4(void) {
    void ResultScreenDismissStep();
    ResultScreenDismissStep();
}

void func_ov005_0221b4c0(void) {
    void ResultScoreRow_SlideOut();
    ResultScoreRow_SlideOut();
}

void func_ov005_0221b4cc(void) {
    M2C_UNK func_ov005_0221b114();
    func_ov005_0221b114();
}

void Tick3DSpriteAnimation(void *animState) {
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gBattleResults;
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    M2C_UNK Sprite_ResumeAnimation(void *);
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
    s32 frame;
    s32 t;
    s32 i;

    M2C_FIELD(animState, s32 *, 0x34) += 1;
    if (M2C_FIELD(animState, s32 *, 0x34) == 1) {
        sp38 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp38 = (*sp38 & ~0xc0) | 0x40;
        sp34 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp34 = *sp34 & ~1;
        sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp30 = *sp30 & ~2;
        sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp2C = *sp2C | 4;
        sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp28 = *sp28 & ~8;
        sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp24 = *sp24 & ~0x10;
        sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp20 = *sp20 & ~0x20;
        sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp1C = *sp1C & ~0x100;
        sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp18 = *sp18 & ~0x200;
        sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp14 = *sp14 & ~0x400;
        sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp10 = *sp10 | 0x800;
        spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *spC = *spC & ~0x1000;
        sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *sp8 = *sp8 & ~0x2000;
    }

    frame = M2C_FIELD(animState, s32 *, 0x34);
    if (frame <= 0x20) {
        t = EaseInterpolate(0, 0, 0x10, frame, 0x20);
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = (u8)t;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = (u8)(0x10 - t);
        M2C_FIELD(animState, u16 *, 0x38) = (u16)EaseInterpolate(4, -0xa0, 0, frame, 0x20);
    }

    for (i = 0; i < MaxU8(M2C_FIELD(&gBattleResults, u8 *, 0xC), M2C_FIELD(&gBattleResults, u8 *, 0xD), M2C_FIELD(&gBattleResults, u8 *, 0xE)); i++) {
        frame = M2C_FIELD(animState, s32 *, 0x34) - i * 2;
        if (frame > 0 && frame <= 0x20)
            ((u16 *)((u8 *)animState + 0x3A))[i] = (u16)EaseInterpolate(4, 0xa0, 0, frame, 0x20);
    }

    if (M2C_FIELD(animState, s32 *, 0x34) != (MaxU8(M2C_FIELD(&gBattleResults, u8 *, 0xC), M2C_FIELD(&gBattleResults, u8 *, 0xD), M2C_FIELD(&gBattleResults, u8 *, 0xE)) - 1) * 2 + 0x20)
        return;

    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 & ~0xc0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = 0;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = 0;
    M2C_FIELD(animState, s32 *, 0x34) = 0;
    Sprite_ResumeAnimation(animState);
}

/* Advance the winning CO's victory screen-split transition.  It only runs when
 * the player won and the current slot holds a CO (otherwise the screen object is
 * ended instead).  On its first frame it selects the mode-1 3D sprite view (the
 * bank's mode-1 flag plus the OAM attribute priority and layer-enable bits), then
 * eases the bank's grid split open, rowsAbove rising from 0 to RESULT_SPLIT_ROWS
 * over RESULT_SPLIT_FRAMES frames; on the last frame it forces the split shut,
 * clears the blend and resumes the object. */
void TickCoVictorySplit(void *animState) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    void Sprite_ResumeAnimationRepeat(void *);
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 DidPlayerWin(void);
    extern M2C_UNK gCoState;
    extern u16 gCoPlayerSlots[];
    extern void *gCur3DSpriteEngine;
    u16 *volatile bankFlags;
    u16 *volatile oamC0;
    u16 *volatile oam1;
    u16 *volatile oam2;
    u16 *volatile oam4;
    u16 *volatile oam8;
    u16 *volatile oam10;
    u16 *volatile oam20;
    u16 *volatile oam100;
    u16 *volatile oam200;
    u16 *volatile oam400;
    u16 *volatile oam800;
    u16 *volatile oam1000;
    u16 *volatile oam2000;
    u16 *volatile oamC0Reset;
    s32 showSplit;
    s32 rowsAbove;

    if (!DidPlayerWin()) {
        showSplit = 0;
    } else if (*(u16 *)((u8 *)gCoPlayerSlots + (s16)M2C_FIELD(&gCoState, u8 *, 4) * (s16)12) == 0) {
        showSplit = 0;
    } else {
        showSplit = 1;
    }
    if (!showSplit) {
        Sprite_ResumeAnimationRepeat(animState);
        return;
    }

    M2C_FIELD(animState, s32 *, RESULT_SPLIT_ELAPSED) += 1;
    if (M2C_FIELD(animState, s32 *, RESULT_SPLIT_ELAPSED) == 1) {
        bankFlags = *(u16 **)gCur3DSpriteEngine;
        *bankFlags = *bankFlags | DS3D_BANK_MODE1;
        oamC0 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oamC0 = (*oamC0 & ~DS3D_BANK_OAMATTR_PRIORITY) | 0x40;
        oam1 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam1 = *oam1 & ~0x1;
        oam2 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam2 = *oam2 | 0x2;
        oam4 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam4 = *oam4 & ~0x4;
        oam8 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam8 = *oam8 & ~0x8;
        oam10 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam10 = *oam10 & ~0x10;
        oam20 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam20 = *oam20 & ~0x20;
        oam100 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam100 = *oam100 & ~0x100;
        oam200 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam200 = *oam200 & ~0x200;
        oam400 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam400 = *oam400 & ~0x400;
        oam800 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam800 = *oam800 | 0x800;
        oam1000 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam1000 = *oam1000 | 0x1000;
        oam2000 = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
        *oam2000 = *oam2000 & ~0x2000;
    }

    rowsAbove = EaseInterpolate(0, 0, RESULT_SPLIT_ROWS, M2C_FIELD(animState, s32 *, RESULT_SPLIT_ELAPSED), RESULT_SPLIT_FRAMES);
    DS3D_BANK(gCur3DSpriteEngine)->rowsAbove = rowsAbove;
    DS3D_BANK(gCur3DSpriteEngine)->rowsBelow = RESULT_SPLIT_ROWS - rowsAbove;
    if (M2C_FIELD(animState, s32 *, RESULT_SPLIT_ELAPSED) != RESULT_SPLIT_FRAMES)
        return;

    oamC0Reset = &DS3D_BANK(gCur3DSpriteEngine)->oamAttr;
    *oamC0Reset = *oamC0Reset & ~DS3D_BANK_OAMATTR_PRIORITY;
    DS3D_BANK(gCur3DSpriteEngine)->rowsAbove = 0;
    DS3D_BANK(gCur3DSpriteEngine)->rowsBelow = 0;
    DS3D_BANK(gCur3DSpriteEngine)->filler_53 = 0;
    M2C_FIELD(animState, s32 *, RESULT_SPLIT_ELAPSED) = 0;
    Sprite_ResumeAnimation(animState);
}

