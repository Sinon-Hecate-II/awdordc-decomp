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
    void *vtable;          /* +0x00 gOv003BattleSetupVTable */
    u8 pad04[0x30];
    u8 state;              /* +0x34 screen state */
    u8 pad35[3];
    void *buffer38;        /* +0x38 */
    void *buffer3C;        /* +0x3C */
    void *menu;            /* +0x40 Ov003BattleSetupMenu * */
    u8 pending;            /* +0x44 a state change is pending */
    u8 linkResultReceived; /* +0x45 a link result/status panel is due */
    u8 mapUnavailable;     /* +0x46 the highlighted map cannot be used */
    u8 firstUpdate;        /* +0x47 set at creation; the first update skips its checks */
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

/* The ov003 scene and panel objects share a flag byte at +0x3A. */
#define OV003_FLAGS           0x3A /* u8 state/dirty flags */
#define OV003_FLAG_PANEL_DIRTY 0x08 /* a panel value changed: the panel redraws itself */

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

/* Map-transfer panel object used by the battle setup scene. */
typedef struct Ov003MapTransferPanel {
    u8 pad00[0x3C];
    SpriteTween *topTween;     /* +0x3C */
    SpriteTween *bottomTween;  /* +0x40 */
    s32 *spritePair;           /* +0x44: two sprites hidden on close */
    u8 pad48[0x10];
    s32 sprite;                /* +0x58: shared panel sprite */
    u8 pad5C[4];
    u8 mapFlags;               /* +0x60: bit 7 means map transfer is unavailable */
} Ov003MapTransferPanel;

#define OV003_MAP_TRANSFER_UNAVAILABLE 0x80
#define OV003_MAP_TRANSFER_SLIDE_FRAMES 12

/* An empty entry of a map-pick list. */
#define MAP_PICK_NONE 0xFFFF

/* The +0x20 flag byte of a scene-view label sprite. */
typedef struct SceneViewLabelFlags {
    u8 first:1;
    u8 second:4;
    u8 third:3;
} SceneViewLabelFlags;

/* A number-label sprite of the scene view (0x2C bytes, gHeapObjectVTable):
 * SetTextSpriteValue fills in the number it draws. */
typedef struct SceneViewLabel {
    void *vtable;            /* +0x00 gHeapObjectVTable */
    u8 kind;                 /* +0x04 0 = number label */
    u8 pad05[1];
    s16 x;                   /* +0x06 screen x */
    s16 y;                   /* +0x08 screen y */
    u8 pad0A[8];
    s16 textId;              /* +0x12 */
    u8 unk14;                /* +0x14 */
    u8 unk15;                /* +0x15 */
    u8 unk16;                /* +0x16 */
    u8 unk17;                /* +0x17 */
    u8 unk18;                /* +0x18 */
    u8 pad19[7];
    SceneViewLabelFlags flags; /* +0x20 */
    u8 unk21;                /* +0x21 */
    u8 pad22[2];
    s32 unk24;               /* +0x24 */
    u8 unk28;                /* +0x28 */
    u8 unk29;                /* +0x29 */
    u8 pad2A[2];
} SceneViewLabel;            /* 0x2C bytes */

/* The scene view's 11-glyph label group (gSceneLabelGroupVTable): the sprite
 * handle of each glyph. */
typedef struct SceneViewLabelGroup {
    void *vtable;            /* +0x00 gSceneLabelGroupVTable */
    s8 color;                /* +0x04 */
    s8 palette;              /* +0x05 */
    u8 flags;                /* +0x06 */
    u8 unk07;                /* +0x07 */
    u8 unk08;                /* +0x08 */
    u8 unk09;                /* +0x09 */
    u8 unk0A;                /* +0x0A */
    u8 unk0B;                /* +0x0B */
    s32 glyphs[11];          /* +0x0C glyph sprite handles */
    s32 count;               /* +0x38 */
} SceneViewLabelGroup;

/* The scene view's map-pick selection child: five current and five pending map
 * ids, MAP_PICK_NONE when a slot is empty. */
typedef struct MapPickSelection {
    void *vtable;            /* +0x00 gMapPickSelectionVTable */
    void *iface;             /* +0x04 gMapPickSelectionIfaceVTable */
    u16 current[5];          /* +0x08 */
    u16 pending[5];          /* +0x12 */
} MapPickSelection;

/* Flag byte at +0x60 of the scene view. */
typedef struct SceneViewFlags {
    u8 first:2;
    u8 second:2;
    u8 third:2;
    u8 fourth:1;
    u8 fifth:1;
} SceneViewFlags;

/* The ov003 scene-view object built by the scene-view constructor and freed by
 * DestroyOv003SceneView: the two intro slide tweens, the 11-glyph label group,
 * the two number labels, the map-pick selection child and the campaign and
 * downloaded map-record lists. */
typedef struct Ov003SceneView {
    void *vtable;                    /* +0x00 gOv003SceneViewVTable */
    u8 pad04[0x30];
    void *iface;                     /* +0x34 gOv003SceneViewIfaceVTable */
    u8 state38;                      /* +0x38 */
    u8 visible;                      /* +0x39 */
    u8 flags3A;                      /* +0x3A */
    u8 pad3B;
    SpriteTween *tweenTop;           /* +0x3C */
    SpriteTween *tweenBottom;        /* +0x40 */
    s32 *spritePair;                 /* +0x44 two sprite handles */
    SceneViewLabelGroup *labelGroup; /* +0x48 */
    s32 sprite4C;                    /* +0x4C */
    SceneViewLabel *labelA;          /* +0x50 */
    SceneViewLabel *labelB;          /* +0x54 */
    s32 sprite58;                    /* +0x58 */
    MapPickSelection *selection;     /* +0x5C */
    SceneViewFlags flags;            /* +0x60 */
    u8 pad61[7];
    u8 *mapRecords;                  /* +0x68 MAP_RECORD_LIST_COUNT map records */
    u8 *downloadedMaps;              /* +0x6C MAP_RECORD_LIST_COUNT map records */
} Ov003SceneView;

#endif
