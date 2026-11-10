/* The ov005 two-page option/record menu state.  Page 0 is the main list, page 1
 * the detail sub-list; switching pages runs a 15-frame quadratic slide whose two
 * sprite offsets are kept at +0x08 and +0x0A. */
#ifndef OV005_MENU_H
#define OV005_MENU_H

#define OV005_MENU_CHANGED     0x00 /* u8 the confirmed selection changed */
#define OV005_MENU_PREV_PAGE   0x02 /* s16 page before the last switch */
#define OV005_MENU_PAGE        0x04 /* s16 current page, OV005_PAGE_* */
#define OV005_MENU_ANIM        0x06 /* s16 slide countdown, 15..0 */
#define OV005_MENU_SLIDE_OUT   0x08 /* s16 offset of the page sliding out */
#define OV005_MENU_SLIDE_IN    0x0a /* s16 offset of the page sliding in */
#define OV005_MENU_PREV_INDEX  0x0c /* s16 previous list index */
#define OV005_MENU_INDEX       0x0e /* s16 current list index */
#define OV005_MENU_BASE_INDEX  0x10 /* s16 first index of the detail list */
#define OV005_MENU_SELECTION   0x12 /* s16 highlighted entry of the detail list */
#define OV005_MENU_CONFIRMED   0x14 /* s16 entry confirmed when the menu opened */
#define OV005_MENU_SCROLL      0x16 /* s16 scroll position of the list */
#define OV005_MENU_SCROLL_VEL  0x18 /* s16 scroll velocity of the list */
#define OV005_MENU_SPRITE      0x1c /* void * sprite object animated by the menu */

enum {
    OV005_PAGE_LIST   = 0,
    OV005_PAGE_DETAIL = 1
};

#define OV005_MENU_ANIM_FRAMES    15  /* length of the page slide */
#define OV005_MENU_ANIM_FRAMES_SQ 225 /* its square, the ease denominator */
#define OV005_FLOAT_256           0x43800000u /* +256.0f */
#define OV005_FLOAT_NEG256        0xc3800000u /* -256.0f */

#endif
