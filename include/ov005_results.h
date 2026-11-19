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
#define RESULT_ROW_SLIDE_END    0x100 /* x offset of a row that has slid all the way out */

/* Sprite layer the score digits of every row are drawn on. */
#define RESULT_SCORE_LAYER 2

#endif
