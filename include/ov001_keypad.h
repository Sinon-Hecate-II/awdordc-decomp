/* The ov001 numeric keypad state.  The pointer global holds the widget built by
 * Ov001_OpenKeypad.  It has ten number keys (laid out 7 8 9 / 4 5 6 / 1 2 3
 * / 0), a delete key with auto-repeat, a next-slot key and the clear/confirm
 * actions.  A key writes its code to KEYPAD_CODE: the number keys write their
 * ASCII character, the others a KEYPAD_CODE_* control code. */
#ifndef OV001_KEYPAD_H
#define OV001_KEYPAD_H

#define KEYPAD_ACTION_SPRITES 0x40 /* void *[2]: sprites of the clear and confirm keys */
#define KEYPAD_CURSOR_SPRITE 0x58 /* void *: sprite that marks the selected key */
#define KEYPAD_SLIDE_TASK   0x5c /* void *: task sliding the highlight between keys */
#define KEYPAD_CODE        0x60 /* u8 code produced by the key under the finger */
#define KEYPAD_TOUCH_KEY   0x61 /* s8 index of the key under the finger, -1 none */
#define KEYPAD_HIGHLIGHTED 0x62 /* s8 key whose pressed sprite is shown */
#define KEYPAD_LAST_KEY    0x63 /* s8 last key that was under the finger */
#define KEYPAD_NAV_KEY     0x64 /* s8 key the d-pad came from */
#define KEYPAD_NAV_WRAP_UP   (-1) /* gKeypadNeighborTable result: d-pad wrapped past the up edge */
#define KEYPAD_NAV_WRAP_DOWN (-2) /* gKeypadNeighborTable result: d-pad wrapped past the down edge */
#define KEYPAD_REPEAT      0x65 /* u8 held-delete auto-repeat counter */
#define KEYPAD_CAN_DELETE  0x66 /* u8 delete key enabled (a digit can be removed) */
#define KEYPAD_DIGITS_ON   0x67 /* u8 number keys enabled (the code is not full) */
#define KEYPAD_CAN_NEXT    0x68 /* u8 next key enabled (a slot is free) */
#define KEYPAD_DELETE_BUZZ 0x69 /* u8 invalid-delete buzz already played */

#define KEYPAD_KEY_COUNT   10   /* number keys, indices 0..9 */
#define KEYPAD_DELETE      10   /* delete/backspace key */
#define KEYPAD_NEXT        11   /* next-slot key */
#define KEYPAD_CLEAR       12   /* clear key */
#define KEYPAD_CONFIRM     13   /* confirm key */

#define KEYPAD_CODE_DELETE  0x10
#define KEYPAD_CODE_NEXT    0x11
#define KEYPAD_CODE_CLEAR   0x12
#define KEYPAD_CODE_CONFIRM 0x13
#define KEYPAD_CODE_NONE    0x1F /* KEYPAD_CODE while no key has been pressed */

#define KEYPAD_REPEAT_DELAY 0x28 /* releases before the held delete key repeats */
#define KEYPAD_REPEAT_STEP  7    /* counter drop per produced delete */

/* The keypad slides in from the right one key row at a time (the steps in
 * ov001_0217416C.c).  A key row is a group of up to three number-key sprites;
 * it waits just off the screen (x = 192) until the row above has come to rest. */
#define KEYPAD_KEYS_PER_ROW 3
#define KEYPAD_KEY_SPRITES  0x10 /* void *[10]: the ten number-key sprites */
#define KEYPAD_KEY_SPRITE(i) (KEYPAD_KEY_SPRITES + (i) * 4) /* sprite of number key i */
#define KPAD_ROW_HIDDEN_X 0xC0 /* where a key row waits off the right edge */
#define KPAD_ROW_REST_X0  0x4C /* resting x of the first (7 8 9) row */
#define KPAD_ROW_REST_X1  0x63 /* resting x of the second (4 5 6) row */
#define KPAD_ROW_REST_X2  0x7A /* resting x of the third (1 2 3) row */
#define KPAD_ROW_REST_X3  0x91 /* resting x of the fourth (0) row */
#define KPAD_ROW_REST_X4  0xAA /* resting x of the bottom action row */
#define KPAD_SLIDE_STEP_X 12   /* pixels a key row travels each frame of the open/close animation */

#endif
