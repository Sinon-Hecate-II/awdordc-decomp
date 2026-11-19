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
#define OV005_MENU_COLOR_OBJ   0x24 /* object whose sprite (+0x3E y) shows the page colour strip */
#define OV005_MENU_DETAIL_SPRITES 0x2c /* void *[4] sprite objects of the detail row's entries */
#define OV005_MENU_DETAIL_COUNT   4    /* entries in the detail row */
#define OV005_MENU_CO_COUNT      12    /* COs listed on page 0: three rows of four */
#define OV005_MENU_CO_COLUMNS     4    /* COs per row of the page-0 grid */

enum {
    OV005_PAGE_LIST   = 0,
    OV005_PAGE_DETAIL = 1
};

#define OV005_LABEL_VRAM_OFFSET  0x8380 /* byte offset of the entry label in the main engine's VRAM */
#define OV005_LABEL_PALETTE      6      /* OBJ palette slot of the entry label */
#define OV005_LABEL_CLEAR_SIZE   0x20   /* bytes of label graphics cleared while the CO is locked */

#define OV005_MENU_ANIM_FRAMES    15  /* length of the page slide */
#define OV005_MENU_ANIM_FRAMES_SQ 225 /* its square, the ease denominator */
#define OV005_FLOAT_256           0x43800000u /* +256.0f */
#define OV005_FLOAT_NEG256        0xc3800000u /* -256.0f */

/* The two CO faces that speak on each story map (map ids OV005_STORY_MAP_FIRST
 * up to OV005_STORY_MAP_END): a 2-byte entry per map holding the first and the
 * second speaker's face id. */
#define OV005_STORY_MAP_FIRST      0xa1
#define OV005_STORY_MAP_END        0xbb /* one past the last story map id */
#define OV005_STORY_MAP_FACE_STRIDE 2
#define OV005_STORY_MAP_FACE_FIRST 0 /* first speaker's face id in an entry */
#define OV005_STORY_MAP_FACE_SECOND 1 /* second speaker's face id */

#endif
