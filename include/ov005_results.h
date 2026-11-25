/* The ov005 battle-results screen.  Each player's score row is a 3D sprite
 * object that slides in from the left, shows its three scores (drawn by the
 * row's draw callback) and, when the screen closes, slides back out over
 * RESULT_ROW_SLIDE_FRAMES frames and deletes itself. */
#ifndef OV005_RESULTS_H
#define OV005_RESULTS_H

#include "ds3dsprite.h"

/* Fields of a score row, past the plain 3D sprite object fields (0x00..0x33). */
#define RESULT_ROW_ELAPSED      0x34 /* s32: frames the slide has run, RESULT_ROW_SLIDE_FRAMES when done */
#define RESULT_ROW_SLIDE_X      0x38 /* s32: x offset of the row, eased from -0x100 (off screen) to 0 (or 0 to 0x100 when closing) */
#define RESULT_ROW_SCORE0       0x3c /* s32: first score drawn by the row */
#define RESULT_ROW_SCORE1       0x40 /* s32: second score drawn by the row */
#define RESULT_ROW_SCORE2       0x44 /* s32: third score drawn by the row */

#define RESULT_ROW_SLIDE_FRAMES 0x20 /* frames one slide takes */
#define RESULT_ROW_SLIDE_START  (-0x100) /* x offset of a row still off screen (left) */
#define RESULT_ROW_SLIDE_END    0x100 /* x offset of a row that has slid all the way out */

/* The results screen object (gResultsScreenClass): the page sprite and the two
 * marker sprites it owns. */
#define RESULTS_SCREEN_PAGE  0x38 /* void *page sprite of the results screen */
#define RESULTS_SCREEN_LEFT  0x3c /* void *left marker sprite */
#define RESULTS_SCREEN_RIGHT 0x40 /* void *right marker sprite */

/* The result screen's slide transition (SpawnResultSlide in ov005_0221ABF8.c,
 * AnimateResultSlide and DrawResultSlideBand in ov005_02218FD0.c): a band that
 * slides down over the page while the page background changes.  Its +0x34 sprite
 * is the page being slid. */
#define RESULT_SLIDE_OWNER  0x38 /* void *: sprite that owns the slide, its child count rises while it lives */
#define RESULT_SLIDE_TIMER  0x3c /* s32: frames the slide has run (0..16) */
#define RESULT_SLIDE_Y      0x40 /* s32: y position the slide has reached */
#define RESULT_SLIDE_ACTIVE 0x44 /* u8: nonzero while the slide band is shown */

/* Sprite layer the score digits of every row are drawn on. */
#define RESULT_SCORE_LAYER 2

/* The results map overview object (gResultsMapVtbl): the map picture, the CO
 * faces and the per-player unit counts that slide onto the results screen.  It
 * owns one SpriteCellList (see sprite_grid.h). */
#define RESULTS_MAP_CELLS 0x34 /* SpriteCellList *cells the overview draws */

/* The screen split a results screen plays before the winning CO's quote: the two
 * halves of the sprite's cell grid (RESULT_SPLIT_ROWS rows) are moved apart over
 * RESULT_SPLIT_FRAMES frames, then the bank is restored. */
#define RESULT_SPLIT_ELAPSED 0x34 /* s32: frames the split has run */
#define RESULT_SPLIT_ROWS    0x10 /* rows of the sprite's cell grid */
#define RESULT_SPLIT_FRAMES  0x10 /* frames the split takes */

/* The award object of the results screen, past the plain 3D sprite object
 * fields (0x00..0x33): the main- and sub-screen sprite handles, the panel's x
 * position, a frame counter, and four medals with a reveal flag and an (x, y)
 * position each. */
#define AWARD_SPRITES        0x34 /* s32[2]: main- and sub-screen sprite objects */
#define AWARD_PANEL_X        0x3c /* s32: x position the awards panel is eased to */
#define AWARD_MEDAL_FRAME    0x40 /* s32: frame counter of the current award animation */
#define AWARD_MEDAL_FLAGS    0x44 /* u8[4]: reveal flag of each medal */
#define AWARD_MEDAL_1_X      0x48 /* u16: x of the first medal */
#define AWARD_MEDAL_1_Y      0x4a /* u16: y of the first medal */
#define AWARD_MEDAL_2_X      0x4c
#define AWARD_MEDAL_2_Y      0x4e
#define AWARD_MEDAL_3_X      0x50
#define AWARD_MEDAL_3_Y      0x52
#define AWARD_MEDAL_4_X      0x54
#define AWARD_MEDAL_4_Y      0x56
#define AWARD_MEDAL_FLAG(n)  (AWARD_MEDAL_FLAGS + (n))
#define AWARD_MEDAL_X(n)     (AWARD_MEDAL_1_X + (n) * 4)
#define AWARD_MEDAL_Y(n)     (AWARD_MEDAL_1_Y + (n) * 4)
#define AWARD_MEDAL_TWINKLE_FRAMES 0x10 /* frames a medal's random twinkle runs */
#define AWARD_MEDAL_TWINKLE_RANGE  4    /* largest random twinkle offset, in pixels */

#endif
