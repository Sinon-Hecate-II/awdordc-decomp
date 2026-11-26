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

/* Returns whether the records screen has seen the map background with this id. */
s32 IsMapBackgroundSeen(s32 mapId) {
    s32 IsMapBackgroundSeenFlagSet();
    if ((mapId >= 0) && (IsMapBackgroundSeenFlagSet() != 0)) {
        return 1;
    }
    return 0;
}

void MarkRecordsMusicEntryHeard(s32 arg0) {
    M2C_UNK SetRecordsMusicHeard(s32, M2C_UNK);
    if (arg0 < 0) {
        return;
    }
    SetRecordsMusicHeard(arg0, 1);
}

/* Whether the records screen has marked music entry `entryId` as heard. */
s32 IsRecordsMusicEntryHeard(s32 entryId) {
    s32 IsRecordsMusicHeardFlagSet();
    if ((entryId >= 0) && (IsRecordsMusicHeardFlagSet() != 0)) {
        return 1;
    }
    return 0;
}
