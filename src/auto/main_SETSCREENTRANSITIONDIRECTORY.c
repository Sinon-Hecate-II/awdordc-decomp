/* 37 functions from 0x020AC7DC to 0x020AD78C (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

s32 *RecordsMenu_GetRecord(s32);

/* Plays a display transition on the screen that is not the active one: unless the
 * transition is instant (length 0, which applies the mode at once), create its
 * sprite on `layer` there, animating `mode` for `length` frames. */

/* Starts the screen-change transition on the screen the active 3D-sprite engine
 * draws to: a transition object slides the screen sideways (mode 0/1) or splits
 * it (mode 2) over `duration` frames.  A zero duration applies the mode at once
 * instead, and nothing is created when the screen is already set up for the
 * other kind of transition. */

/* Creates a screen-change transition sprite on the screen that is not active,
 * attached as a child of `parent`: the parent's child count is incremented so it
 * is not updated and outlives the transition (the transition's destructor
 * releases it again).  A zero length applies the mode at once instead, and
 * nothing is created when the screen is already set up for the other kind of
 * transition. */

/* Starts a screen fade attached to a parent sprite (it counts as one of the
 * parent's children, so the parent waits for it): on the screen the active
 * 3D-sprite engine does NOT draw to, fades `mode` over `duration` frames.  A zero
 * duration applies the mode at once instead, and nothing is created when the
 * screen is already set up for a fade. */

/* Starts a screen transition on the main screen, the sub screen, both screens
 * or whichever screen is active: switches gCur3DSpriteEngine to each engine in
 * turn and creates the transition sprite on the selected ones, then puts the
 * previous engine back. */

/* Starts a screen fade on the main screen, the sub screen, both screens or
 * whichever screen is active: switches gCur3DSpriteEngine to each engine in
 * turn and creates the fade on the selected ones, then puts the previous engine
 * back. */

/* Creates a screen transition on the main screen, the sub screen, both screens
 * or whichever screen is active, each one attached as a child of `parent`
 * (unlike CreateScreenTransitions, the transition follows that sprite): switches
 * gCur3DSpriteEngine to each engine in turn and creates the transition sprite on
 * the selected ones, then puts the previous engine back. */

/* Starts a screen fade on the main screen, the sub screen, both screens or
 * whichever screen is active, each one attached as a child of `parent` (unlike
 * StartScreenFades, the fade follows that sprite): switches gCur3DSpriteEngine to
 * each engine in turn and creates the fade on the selected ones, then puts the
 * previous engine back. */

/* Point the file archive at the screen transition's graphics directory
 * ("/tutorial/tutcard"), the one DrawScreenTransition reads its .narc from. */
void SetScreenTransitionDirectory(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    extern M2C_UNK sScreenTransitionDirectory;
    SetFileDirectory(&sScreenTransitionDirectory);
}

/* Which half of the screen the running split transition slides (0 or 1). */
s32 GetScreenTransitionSide(void) {
    extern ScreenTransition *gScreenTransition;
    return gScreenTransition->side != 0;
}

/* Return the selected screen engine's destination for the transition character graphics. */
s32 GetScreenTransitionCharacterTarget(void) {
    extern s32 g3DSpriteEngineSub;
    s32 side = GetScreenTransitionSide();
    return M2C_FIELD(g3DSpriteEngineSub + side * 4, s32 *, DS3D_ENGINE_LAYER_VRAM);
}

/* Return the sub 3D-sprite engine's RAM tile buffer for the sliding half of the
 * running transition: the destination DrawScreenTransition loads the .sc screen
 * data into. */
s32 GetScreenTransitionScTarget(void) {
    extern s32 g3DSpriteEngineSub;
    s32 side = GetScreenTransitionSide();
    return M2C_FIELD(g3DSpriteEngineSub + side * 4, s32 *, DS3D_ENGINE_LAYER_TILES);
}

/* Mark the running screen-change split transition as finished, so its update
 * stops and the new screen mode is applied. */
void SetScreenTransitionDone(void) {
    extern ScreenTransition *gScreenTransition;
    gScreenTransition->flags |= TRANSITION_DONE;
}

/* Clear the running transition's finished mark, so its update runs again (used
 * when a transition is restarted). */
void ClearScreenTransitionDone(void) {
    extern ScreenTransition *gScreenTransition;
    gScreenTransition->flags &= ~TRANSITION_DONE;
}

/* TRUE once the running screen transition has finished (or been applied at once). */
u8 IsScreenTransitionDone(void) {
    extern ScreenTransition *gScreenTransition;
    return (gScreenTransition->flags & TRANSITION_DONE) != 0;
}

