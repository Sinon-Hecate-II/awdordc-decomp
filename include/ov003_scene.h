/* A polymorphic ov003 scene object: a vtable at +0, a second interface vtable
 * at +0x34, then the children, buffers and sprite-handle arrays it owns. */
#ifndef OV003_SCENE_H
#define OV003_SCENE_H

typedef struct Ov003Object {
    void *vtable;        /* +0x00 */
    u8  filler_04[0x30];
    void *iface;         /* +0x34 second vtable */
    u8  field38;         /* +0x38 */
    u8  field39;         /* +0x39 */
    u8  flags3A;         /* +0x3A u8 flags: low 6 bits a state, bit 6, bit 7 */
    u8  field3B;         /* +0x3B */
    void *cursor3C;      /* +0x3C block freed by the destructors */
    void *sprites40;     /* +0x40 block of 2 + 8 + 8 sprite handles */
    void *child44;       /* +0x44 child object */
    u8  filler_48[4];
    void *child4C;       /* +0x4C child object */
    void *child50;       /* +0x50 child object */
    void *child54;       /* +0x54 child object */
    void *buffer58;      /* +0x58 buffer */
    void *child5C;       /* +0x5C child object */
    void *child60;       /* +0x60 child object */
    void *buffer64;      /* +0x64 buffer */
    void *sprites68;     /* +0x68 array of 10 sprite handles */
    void *sprites6C;     /* +0x6C array of 2 sprite handles */
    void *sub70;         /* +0x70 sub-object with a resource handle at +0x14 */
} Ov003Object;

/* Battle-setup controller; distinct from the scene object's interface layout above. */
typedef struct Ov003BattleSetup {
    void *vtable;
    u8 pad04[0x30];
    u8 state;
    u8 pad35[3];
    void *buffer38;
    void *buffer3C;
    void *menu;
    u8 pending;
} Ov003BattleSetup;

typedef struct Ov003BattleSetupMenu {
    void *vtable;
    u8 mode;
    s8 selection;
    s8 lastSelection;
    u8 pad07;
    u8 *items;
} Ov003BattleSetupMenu;

/* The ov003 battle scene object (vtable data_ov003_0220fb38, built by
 * func_ov003_021f05fc): SpriteTween slots that slide the map and player panels
 * into place, the CO panel record and the sprite handles it owns. */
#define BATTLE_SCENE_SLIDE_MAP    0x3C /* SpriteTween *: map view slide */
#define BATTLE_SCENE_PANEL_INFO   0x40 /* 0x14-byte CO panel record */
#define BATTLE_SCENE_SLIDE_PANEL  0x44 /* SpriteTween *: CO panel slide */
#define BATTLE_SCENE_SLIDE_A      0x48 /* SpriteTween *: first extra slide */
#define BATTLE_SCENE_SLIDE_B      0x4C /* SpriteTween *: second extra slide */
#define BATTLE_SCENE_SLIDE_C      0x50 /* SpriteTween *: third extra slide */
#define BATTLE_SCENE_PANEL_SPRITE 0x54 /* 3D sprite handle of the CO panel */
#define BATTLE_SCENE_SPRITES      0x64 /* void *[10]: sprite handle array */

/* Slide parameters the battle scene tweens use. */
#define BATTLE_SCENE_SLIDE_FRAMES 12   /* frames a slide tween runs */
#define BATTLE_SCENE_PANEL_HOME_X 0xC0 /* x the CO panel rests at */

/* CO panel record fields (BATTLE_SCENE_PANEL_INFO). */
#define BATTLE_PANEL_CURRENT 0x10 /* u8 current player slot */
#define BATTLE_PANEL_ICON    0x11 /* u8 waypoint option icon */
#define BATTLE_PANEL_NONE    0x63 /* no player / no icon */

/* The ov003 battle-display object that SetupSceneObjectDisplay and
 * CloseSceneObjectDisplay drive: two tween sprites that slide the rows in and
 * out, the arrays of part sprites and per-slot records, a sprite group, a text
 * sprite and a sprite shared by the whole display. */
#define SCENE_DISPLAY_TWEEN_TOP    0x3C /* void *: sprite tweened to/from the scene slide offset */
#define SCENE_DISPLAY_PARTS        0x40 /* s32 *: part sprite handles, 2 sprites then 8 + 8 */
#define SCENE_DISPLAY_RECORDS      0x44 /* 8 records of 0x18 bytes, the record total at +0xC */
#define SCENE_DISPLAY_TWEEN_BOTTOM 0x48 /* void *: sprite tweened to/from -32 */
#define SCENE_DISPLAY_GROUP        0x50 /* s32 *: group sprite handles, 3 runs of 4 */
#define SCENE_DISPLAY_TEXT         0x54 /* void *: text sprite */
#define SCENE_DISPLAY_SPRITE       0x58 /* s32: sprite hidden together with the display */

#endif
