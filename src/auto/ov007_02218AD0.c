/* 21 functions from 0x02218AD0 to 0x02219ACC (ov007), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "ov007_map_editor.h"
#include "sound.h"

static inline s32 ov007_item_id(void *p) {
    void *q = M2C_FIELD(p, void **, 0);
    return q ? M2C_FIELD(q, u16 *, 8) : -1;
}


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov007_02218ad0(void *arg0) {
    M2C_UNK SetSpriteQuad(M2C_UNK, s32, s32, s32, s32);
    s32 Divide(s32, s32);
    extern M2C_UNK gSinCosTable;
    s32 sp4;
    volatile s32 sp8;
    s16 temp_r4; s16 sine;
    s32 temp_r0;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r4_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r7_2;
    s32 temp_r7_3;
    s32 temp_r8;
    s32 temp_r7;
    s32 temp_r8_2;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r8_3;
    s32 var_r9;
    s32 var_r9_2;
    s32 var_r9_3;

    var_r1 = M2C_FIELD(arg0, u16 *, 0x3C);
    if ((s32) var_r1 >= 2) {
        var_r7 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r7 = 2;
    } else {
        var_r7 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r7 = var_r1;
        }
    }
    temp_r4 = M2C_FIELD(&gSinCosTable, s16 *, 2);
    if ((s32) var_r1 >= 2) {
        var_r8 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r8 = 2;
    } else {
        var_r8 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r8 = var_r1;
        }
    }
    sine = M2C_FIELD(&gSinCosTable,s16 *,0);
    if ((s32) var_r1 >= 2) {
        var_r9 = var_r1;
    } else if ((u32) var_r1 > 2U) {
        var_r9 = 2;
    } else {
        var_r9 = -2U;
        if ((s32) var_r1 >= -2) {
            var_r9 = var_r1;
        }
    }
    if ((s32) var_r1 < 2) {
        if ((u32) var_r1 > 2U) {
            var_r1 = 2;
        } else if ((s32) var_r1 < -2) {
            var_r1 = -2U;
        }
    }
    temp_r11 = temp_r4 * 0x10;
    temp_r6 = (0 - sine) * 0x10;
    temp_r5 = sine * 0x10;
    sp8 = Divide(temp_r11, var_r1);
    temp_r8 = Divide(temp_r6, var_r9);
    temp_r7 = Divide(temp_r5, var_r8);
    temp_r0=Divide(temp_r11,var_r7);
    sp4=sp8;
    SetSpriteQuad(0,(s16)sp4,(s16)temp_r8,(s16)temp_r7,(s16)temp_r0);
    var_r1_2 = M2C_FIELD(arg0, u16 *, 0x3E);
    if ((s32) var_r1_2 >= 2) {
        var_r7_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r7_2 = 2;
    } else {
        var_r7_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r7_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 >= 2) {
        var_r8_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r8_2 = 2;
    } else {
        var_r8_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r8_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 >= 2) {
        var_r9_2 = var_r1_2;
    } else if ((u32) var_r1_2 > 2U) {
        var_r9_2 = 2;
    } else {
        var_r9_2 = -2U;
        if ((s32) var_r1_2 >= -2) {
            var_r9_2 = var_r1_2;
        }
    }
    if ((s32) var_r1_2 < 2) {
        if ((u32) var_r1_2 > 2U) {
            var_r1_2 = 2;
        } else if ((s32) var_r1_2 < -2) {
            var_r1_2 = -2U;
        }
    }
    temp_r0 = temp_r4 * 0x10;
    sp4 = temp_r0;
    temp_r11_2 = Divide(temp_r0, var_r1_2);
    temp_r8_2 = Divide(temp_r6, var_r9_2);
    temp_r7_2 = Divide(temp_r5, var_r8_2);
    SetSpriteQuad(1, (s16) temp_r11_2, (s16) temp_r8_2, (s16) temp_r7_2, (s32) (s16) Divide(temp_r0, var_r7_2));
    var_r9_3 = M2C_FIELD(arg0, u16 *, 0x40);
    if ((s32) var_r9_3 >= 2) {
        var_r8_3 = var_r9_3;
    } else if ((u32) var_r9_3 > 2U) {
        var_r8_3 = 2;
    } else {
        var_r8_3 = -2U;
        if ((s32) var_r9_3 >= -2) {
            var_r8_3 = var_r9_3;
        }
    }
    if ((s32) var_r9_3 < 2) {
        if ((u32) var_r9_3 > 2U) {
            var_r9_3 = 2;
        } else if ((s32) var_r9_3 < -2) {
            var_r9_3 = -2U;
        }
    }
    temp_r7_3 = temp_r4 * 0x10;
    temp_r4_2 = Divide(temp_r7_3, 0x100U);
    temp_r6_2 = Divide(temp_r6, var_r9_3);
    temp_r5_2 = Divide(temp_r5, 0x100U);
    SetSpriteQuad(2, (s16) temp_r4_2, (s16) temp_r6_2, (s16) temp_r5_2, (s32) (s16) Divide(temp_r7_3, var_r8_3));
}
#pragma pop
void func_ov007_02218d8c(void *arg0) {
    M2C_UNK func_01ffaacc(u16, s32, u16, M2C_UNK *, s32);
    s32 MapEditor_GetPageOwnerColorCount();
    extern M2C_UNK data_02101f5c;
    extern u16 **data_027e01d8;
    extern M2C_UNK data_027e0064;
    void *sp4;
    s32 temp_r7;
    u32 var_r10;
    long var_r8;
    s32 var_r9;

    sp4 = arg0;
    temp_r7 = MapEditor_GetPageOwnerColorCount();
    if (M2C_FIELD(sp4, u16 *, 0x3C) > 0x10U) {
        var_r8 = 0;
        if (temp_r7 > 0) {
            var_r9 = 0x39C;
            var_r10 = 8;
            do {
                func_01ffaacc((u16) (var_r10 & 0x1FF), 0x58C, (u16) (0x3FF & (var_r9 >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))), &data_027e0064, 0xF);
                var_r8 += 1;
                var_r9 += 4;
                var_r10 += 0x18;
            } while (temp_r7 > var_r8);
        }
    }
    if (M2C_FIELD(sp4, u16 *, 0x40) <= 0x10U) {
        return;
    }
    func_01ffaacc(0x480U, 0x58C, (u16) (0x3FF & (0x3B0 >> ((u32) (**data_027e01d8 << 0x11) >> 0x1E))), &data_02101f5c, 0xF);
}

M2C_UNK func_ov007_02218e98(void *arg0) {
    u8 *MapEditor_GetPaletteEntries(s32);
    void func_ov007_02218ad0(void *);
    void func_ov007_02218d8c(void *);
    M2C_UNK AddSprite(u16, s32, u16, M2C_UNK *, s32);
    extern u16 **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    extern M2C_UNK gSpriteDesc16x32, gSpriteDesc32x16, gSpriteDesc16x16;
    u16 **saved;
    s32 x, y;
    s32 tile;
    s32 player;
    s32 selected;
    u8 *entries;
    u16 *tabs;
    s32 tab;
    u8 *panel = arg0;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    tile = 0x3dc;
    player = panel[0x37];
    selected = M2C_FIELD(panel + player, u8 *, 0x3a);
    entries = MapEditor_GetPaletteEntries(player);

    func_ov007_02218ad0(panel);
    func_ov007_02218d8c(panel);

    tabs = M2C_FIELD(panel, u16 **, 0x54);
    tab = M2C_FIELD(panel + panel[0x37], u8 *, 0x38);
    tabs[0x34 / 2] = tab * 24 + 8;
    tabs[0x36 / 2] = 140;

    switch (panel[0x37]) {
    case 0: {
        u8 *entry = entries + selected * 5;
        s32 col = entry[1];
        s32 row = entry[2];
        u16 *cursor = M2C_FIELD(panel, u16 **, 0x50);
        cursor[0x34 / 2] = col * 36 + 10;
        cursor[0x36 / 2] = row * 32 + 8;
        if ((s8)entries[0] >= 0) {
            do {
                x = entries[1] * 36 + 2;
                y = entries[2] * 32 + 8;
                if (*(volatile s8 *)entries == 15) {
                    if (M2C_FIELD(panel + panel[0x37], u8 *, 0x38) == 4) {
                        tile += 24;
                        goto nextLarge;
                    }
                }
                {
                    u32 id = entries[4];
                    if (M2C_FIELD(panel + id * 2, u16 *, 0x3c) > 16)
                        AddSprite((u16)(((x + 8) & 511) | ((id & 31) << 9)), (u16)(((y - 16) & 255) | 0x500), (u16)(((tile >> ((u32)(**gCur3DSpriteEngine << 17) >> 30)) & 1023) | (((entries[3] + 6) & 15) << 12)), &gSpriteDesc16x32, 15);
                }
                if (M2C_FIELD(panel, u16 *, 0x3c) > 16)
                    AddSprite((u16)(x & 511), (u16)(((y + 16) & 255) | 0x500), (u16)((((tile + 8) >> ((u32)(**gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x2000), &gSpriteDesc32x16, 15);
                tile += 24;
            nextLarge:
                entries += 5;
            } while ((s8)entries[0] >= 0);
        }
        break;
    }
    case 1: {
        u8 *entry = entries + selected * 5;
        s32 col = entry[1];
        s32 row = entry[2];
        u16 *cursor = M2C_FIELD(panel, u16 **, 0x50);
        cursor[0x34 / 2] = col * 36 + 10;
        cursor[0x36 / 2] = row * 32 + 8;
        if ((s8)entries[0] >= 0) {
            do {
                x = entries[1] * 36 + 2;
                y = entries[2] * 32 + 8;
                {
                    u32 id = entries[4];
                    if (M2C_FIELD(panel + id * 2, u16 *, 0x3c) > 16)
                        AddSprite((u16)(((x + 8) & 511) | ((id & 31) << 9)), (u16)(((y) & 255) | 0x500), (u16)(((tile >> ((u32)(**gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x6000), &gSpriteDesc16x16, 15);
                }
                if (M2C_FIELD(panel, u16 *, 0x3c) > 16)
                    AddSprite((u16)(x & 511), (u16)(((y + 16) & 255) | 0x500), (u16)((((tile + 4) >> ((u32)(**gCur3DSpriteEngine << 17) >> 30)) & 1023) | 0x2000), &gSpriteDesc32x16, 15);
                tile += 12;
                entries += 5;
            } while ((s8)entries[0] >= 0);
        }
        break;
    }
    }
    gCur3DSpriteEngine = saved;
}

M2C_UNK func_ov007_02219230(void *arg) {
void MapEditor_ConfirmPaletteEntry(void *); s32 func_ov007_02217c80(void *); s32 func_ov007_02217ca8(void *); void func_ov007_02219bb4(void *,s32); void GotoSpriteAnimationLabel(void *,s32); s32 func_ov007_02217d30(void *); M2C_UNK PlaySoundEffect(s32); void func_02088044(void *);
extern u16 *gKeyState;
u32 keys; void *p; void *q; s32 v; s32 selected;
keys=*gKeyState;
if(keys&1) {MapEditor_ConfirmPaletteEntry(arg);return;}
if(keys&0x400) {func_ov007_02219bb4(arg,func_ov007_02217c80(arg));return;}
if(keys&0x800) {func_ov007_02219bb4(arg,func_ov007_02217ca8(arg));return;}
if(keys&0x304) {GotoSpriteAnimationLabel(arg,1);return;}
if(keys&2) {GotoSpriteAnimationLabel(arg,2);return;}
if(func_ov007_02217d30(arg)) {PlaySoundEffect(0x10019);return;}
func_02088044(M2C_FIELD(arg,void **,0x58));
p=M2C_FIELD(arg,void **,0x58);
if((u8)(M2C_FIELD(p,s8 *,9)>=0)) {
q=M2C_FIELD(p,void **,0);
v=q?M2C_FIELD(q,u16 *,8):-1;
PlaySoundEffect(0x10019);
M2C_FIELD((u8 *)arg+M2C_FIELD(arg,u8 *,0x37),u8 *,0x3a)=v;
}
if((u8)(M2C_FIELD(M2C_FIELD(arg,void **,0x58),s8 *,11)>=0)) {MapEditor_ConfirmPaletteEntry(arg);return;}
func_02088044(M2C_FIELD(arg,void **,0x5c));
p=M2C_FIELD(arg,void **,0x5c);
if((u8)(M2C_FIELD(p,s8 *,9)>=0)) {
q=M2C_FIELD(p,void **,0);
v=-1;
if(q) v=M2C_FIELD(q,u16 *,8);
selected=M2C_FIELD((u8 *)arg+M2C_FIELD(arg,u8 *,0x37),u8 *,0x38);
if(v!=selected) func_ov007_02219bb4(arg,v);
}
}

void func_ov007_02219398(void) {
    M2C_UNK func_ov007_02217f8c();
    func_ov007_02217f8c();
}

void func_ov007_022193a4(void) {
    M2C_UNK MapEditor_ApplyPaletteSelection();
    MapEditor_ApplyPaletteSelection();
}

void func_ov007_022193b0(void) {
    M2C_UNK func_ov007_02218e98();
    func_ov007_02218e98();
}

void func_ov007_022193bc(void) {
    M2C_UNK func_ov007_0221863c();
    func_ov007_0221863c();
}

void func_ov007_022193c8(void) {
    M2C_UNK MapEditor_FreePaletteLists();
    MapEditor_FreePaletteLists();
}

void func_ov007_022193d4(void) {
    M2C_UNK func_ov007_02219230();
    func_ov007_02219230();
}

/* Palette-panel page tab: flip the panel between the unit and terrain palette
 * pages (MAP_EDITOR_PANEL_PAGE) and play the tab-change sound. */
M2C_UNK MapEditor_SwitchPalettePage(void *panel) {
    M2C_UNK PlaySoundEffect(M2C_UNK);
    u8 page;

    page = M2C_FIELD(panel, u8 *, MAP_EDITOR_PANEL_PAGE);
    switch (page) {
    case MAP_EDITOR_PAGE_UNIT:
        M2C_FIELD(panel, u8 *, MAP_EDITOR_PANEL_PAGE) = MAP_EDITOR_PAGE_TERRAIN;
        break;
    case MAP_EDITOR_PAGE_TERRAIN:
        M2C_FIELD(panel, u8 *, MAP_EDITOR_PANEL_PAGE) = MAP_EDITOR_PAGE_UNIT;
        break;
    }
    return PlaySoundEffect((M2C_UNK)SOUND_MENU_TAB);
}

M2C_UNK func_ov007_02219418(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221ff90;
    return CreateSpriteFromClass(&data_ov007_0221ff90, 7);
}

M2C_UNK GetPanelObject(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov007_0221ff90;
    return FindObjectByClass(&data_ov007_0221ff90);
}

/* Enter callback of the CO-power panel's open-animation driver: when the panel
 * uses its first graphic variant, set the main engine's split state (the bank's
 * OBJ priority, no rows above and the rows-below count the open starts from) and
 * start the three row sprites' slide-in over the eight open frames; then hide the
 * panel's two spare sprites and reset the driver's frame counter. */
void BeginPanelOpen(void *driver) {
M2C_UNK GetPanelObject(void); void Start3DSpriteSlideIn(void *,s32); void Hide3DSprite(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **g3DSpriteEngineMain;
u16 * volatile attrReg; u16 **savedEngine; void *panel;
panel=(void *)GetPanelObject();
if(M2C_FIELD(panel,u8 *,OV007_PANEL_VARIANT_A)!=0) {
savedEngine=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
attrReg=(u16 *)((u8 *)*g3DSpriteEngineMain+DS3D_BANK_OAMATTR);
*attrReg=(*attrReg & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_ABOVE)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_BELOW)=0x10;
gCur3DSpriteEngine=savedEngine;
Start3DSpriteSlideIn(M2C_FIELD(panel,void **,OV007_PANEL_ROW0),8);
Start3DSpriteSlideIn(M2C_FIELD(panel,void **,OV007_PANEL_ROW1),8);
Start3DSpriteSlideIn(M2C_FIELD(panel,void **,OV007_PANEL_ROW2),8);
}
Hide3DSprite(M2C_FIELD(panel,void **,OV007_PANEL_SPRITE_A));
Hide3DSprite(M2C_FIELD(panel,void **,OV007_PANEL_SPRITE_B));
M2C_FIELD(driver,u16 *,OV007_PANEL_ANIM_FRAME)=0;
}

/* Panel-open animation step: ease the CO panel's three values from 0 to 256 over
 * 8 frames, drive the main engine's sprite split while it opens, and delete the
 * animation object once the 8 frames are up. */
void UpdatePanelOpen(void *arg) {
s32 EaseInterpolate(s32,s32,s32,s32,s32); void DeleteSpriteObject(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **g3DSpriteEngineMain;
u16 * volatile attrReg; u16 **old; void *panel; s32 split;
panel=(void *)GetPanelObject();
M2C_FIELD(arg,s16 *,0x54)++;
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM0)=EaseInterpolate(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM1)=EaseInterpolate(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
if(M2C_FIELD(panel,u8 *,OV007_PANEL_VARIANT_A)) {
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM2)=EaseInterpolate(4,0,256,M2C_FIELD(arg,s16 *,0x54),8);
split=EaseInterpolate(0,16,4,M2C_FIELD(arg,s16 *,0x54),8);
old=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
attrReg=*g3DSpriteEngineMain+9; *attrReg=(*attrReg & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,0x52)=split;
gCur3DSpriteEngine=old;
}
if(M2C_FIELD(arg,s16 *,0x54)>=8) DeleteSpriteObject(arg);
}

/* Show the co-power panel without an animation: clear the main 3D sprite bank's
 * per-layer flags, make the panel's two sprites visible, snap them onto their
 * target position and size, and drop the panel's first graphic variant flag. */
void ShowCoPowerPanel(void) {
    M2C_UNK GetPanelObject(void);
    void Show3DSprite(void *);
    void Sync3DSpriteToTarget(void *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    u16 * volatile layer1;
    u16 * volatile layer2;
    u16 * volatile layer3;
    u16 **savedEngine;
    void *panel;

    panel = (void *)GetPanelObject();
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    layer1 = *g3DSpriteEngineMain;
    *layer1 = (*layer1 & ~0x200);
    layer2 = *gCur3DSpriteEngine;
    *layer2 = (*layer2 & ~0x400);
    layer3 = *gCur3DSpriteEngine;
    *layer3 = (*layer3 & ~0x800);
    Show3DSprite(M2C_FIELD(panel, void **, OV007_PANEL_SPRITE_A));
    Show3DSprite(M2C_FIELD(panel, void **, OV007_PANEL_SPRITE_B));
    Sync3DSpriteToTarget(M2C_FIELD(panel, void **, OV007_PANEL_SPRITE_A));
    Sync3DSpriteToTarget(M2C_FIELD(panel, void **, OV007_PANEL_SPRITE_B));
    M2C_FIELD(panel, u8 *, OV007_PANEL_VARIANT_A) = 0;
    gCur3DSpriteEngine = savedEngine;
}

void func_ov007_022196f4(void *arg0) { M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK); void (*f)(void **,void *)=(void(*)(void**,void*))CreateSpriteObject; extern M2C_UNK data_ov007_0221fdf8; f((void **)&data_ov007_0221fdf8,arg0); }

/* BeginPanelClose: prepare the CO panel for its close animation — when the
   second panel variant is in use, configure the main 3D sprite bank's split and
   start sliding the panel's three row sprites out, then hide its two small
   sprites and reset the driver's frame counter. */
void BeginPanelClose(void *driver) {
M2C_UNK GetPanelObject(void);
void Start3DSpriteSlideOut(void *, int); void Hide3DSprite(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **g3DSpriteEngineMain;
u16 * volatile bankAttr; u16 **savedEngine; void *panel;
panel=(void *)GetPanelObject();
if (M2C_FIELD(panel,u8 *,OV007_PANEL_VARIANT_B)) {
savedEngine=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
bankAttr=*g3DSpriteEngineMain+9; *bankAttr=(*bankAttr & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_ABOVE)=0; M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_BELOW)=4; gCur3DSpriteEngine=savedEngine;
Start3DSpriteSlideOut(M2C_FIELD(panel,void **,0x44),6);
Start3DSpriteSlideOut(M2C_FIELD(panel,void **,0x48),6);
Start3DSpriteSlideOut(M2C_FIELD(panel,void **,0x4c),6);
}
Hide3DSprite(M2C_FIELD(panel,void **,0x50));
Hide3DSprite(M2C_FIELD(panel,void **,0x54));
M2C_FIELD(driver,u16 *,OV007_PANEL_ANIM_FRAME)=0;
}

/* Per-frame driver of the ov007 CO-power panel's close animation: eases the
 * panel's three row scales from full size down to zero over six frames, glides
 * the 3D sprite bank's split down the sheet, and deletes the driver object once
 * the animation is over. */
void UpdatePanelClose(void *driver) {
s32 EaseInterpolate(s32,s32,s32,s32,s32); void DeleteSpriteObject(void *);
extern u16 **gCur3DSpriteEngine; extern u16 **g3DSpriteEngineMain;
u16 * volatile bankAttr; u16 **savedEngine; void *panel; s32 rowsBelow;
panel=(void *)GetPanelObject();
M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME)++;
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM0)=EaseInterpolate(EASE_OUT_QUAD,256,0,M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME),6);
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM1)=EaseInterpolate(EASE_OUT_QUAD,256,0,M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME),6);
if(M2C_FIELD(panel,u8 *,OV007_PANEL_VARIANT_B)) {
M2C_FIELD(panel,u16 *,OV007_PANEL_ANIM2)=EaseInterpolate(EASE_OUT_QUAD,256,0,M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME),6);
rowsBelow=EaseInterpolate(EASE_LINEAR,4,16,M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME),6);
savedEngine=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
bankAttr=*g3DSpriteEngineMain+9; *bankAttr=(*bankAttr & ~0xc0)|0x40;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_ABOVE)=0;
M2C_FIELD(*gCur3DSpriteEngine,u8 *,DS3D_BANK_ROWS_BELOW)=rowsBelow;
gCur3DSpriteEngine=savedEngine;
}
if(M2C_FIELD(driver,s16 *,OV007_PANEL_ANIM_FRAME)>=6) DeleteSpriteObject(driver);
}

/* Applies the panel's 3D-sprite setup to the main engine: when the panel is visible
 * it enables sprite layers 1 and 2 and clears the split/blend state and the bank's
 * control bits; when it is hidden it marks the panel's two sprites dirty and clears
 * the bank's control bits. */
void UpdatePanelDisplay(void) {
    M2C_UNK GetPanelObject(void);
    void Clear3DSpriteLayer(s32);
    void Show3DSprite(void *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    u16 * volatile attrReg;
    u16 * volatile bankA;
    u16 * volatile bankB;
    u16 * volatile bankC;
    u16 * volatile bankD;
    u16 * volatile bankE;
    u16 * volatile bankF;
    u16 **savedEngine;
    void *panel;

    panel = (void *)GetPanelObject();
    if (M2C_FIELD(panel, u8 *, 0x35) != 0) {
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        Clear3DSpriteLayer(1);
        Clear3DSpriteLayer(2);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
        attrReg = (u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
        *attrReg = *attrReg & ~0xc0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x51) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x52) = 0;
        M2C_FIELD(*gCur3DSpriteEngine, u8 *, 0x53) = 0;
        bankA = (u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        *bankA = *bankA & ~0x200;
        bankB = (u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        *bankB = *bankB & ~0x400;
        bankC = (u16 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        *bankC = *bankC & ~0x800;
        gCur3DSpriteEngine = savedEngine;
    } else {
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        Show3DSprite(M2C_FIELD(panel, void **, 0x50));
        Show3DSprite(M2C_FIELD(panel, void **, 0x54));
        bankD = *gCur3DSpriteEngine;
        *bankD = *bankD & ~0x200;
        bankE = *gCur3DSpriteEngine;
        *bankE = *bankE & ~0x400;
        bankF = *gCur3DSpriteEngine;
        *bankF = *bankF & ~0x800;
        gCur3DSpriteEngine = savedEngine;
    }
}

void func_ov007_02219ab4(void *arg0) { M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK); void (*f)(void **,void *)=(void(*)(void**,void*))CreateSpriteObject; extern M2C_UNK data_ov007_0221fe20; f((void **)&data_ov007_0221fe20,arg0); }

