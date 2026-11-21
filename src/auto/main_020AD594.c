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

s32 func_020ad594(s32 arg0)
{
  s32 func_020ad5dc();
  s32 *RecordsMenu_GetRecord(s32);
  s32 new_var[2];
  s32 temp_r0;
  temp_r0 = func_020ad5dc();
  for (new_var[1] = 0; new_var[1] < temp_r0; new_var[1]++)
  {
    new_var[0] = *((s32 *) (((s8 *) RecordsMenu_GetRecord(new_var[1])) + 0));
    if (new_var[0] == arg0)
    {
      return new_var[1];
    }
  }

  return -1;
}

s32 func_020ad5dc(void) {
    s32 var_r4;

    var_r4 = 0;
loop_1:
    if (M2C_FIELD(RecordsMenu_GetRecord(var_r4), s32 *, 8) != 0) {
        var_r4 += 1;
        goto loop_1;
    }
    return var_r4;
}
