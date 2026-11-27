/* 21 functions from 0x021E3210 to 0x021E41AC (ov002), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "ds3dsprite.h"
#include "ov002_effects.h"
#include "ov002_panel.h"

typedef struct PanelStat {
    s16 value;
    u8 stat : 3;
    u8 order : 3;
    u8 highlighted : 1;
    u8 comparison : 1;
    u8 padding;
} PanelStat;

/* View of the flags byte when walking a panel's source entries. */
typedef struct PanelStatFlags {
    u8 stat : 3;
    u8 order : 3;
    u8 highlighted : 1;
    u8 comparison : 1;
} PanelStatFlags;

extern u8 data_ov002_021f30fd[], gVersusGaugeHp[];
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov002_021e3210(void *arg0) {
    s8 CountPanelEntries(void *);
    extern u8 gPlayerSettings;
    register void *panel = arg0;
    register s32 outCount;
    s32 scanned, count, marked;
    s32 i;
    PanelStat *out;
    register s32 slot;
    void *other;
    for (i = 0; i < 5; ++i) M2C_FIELD(panel + i * 4, s16 *, PANEL_STAT_SOURCE) = -1;
    count = CountPanelEntries(M2C_FIELD(panel, void **, PANEL_OTHER) + PANEL_ENTRIES);
    outCount = 0;
    slot = outCount;
    scanned = outCount;
    out = (PanelStat *)(panel + PANEL_STAT_SOURCE);
    if (data_ov002_021f30fd[M2C_FIELD(panel, u8 *, PANEL_PLAYER) * 0x18] != 0 && count != 0) {
        do {
            s32 stat = M2C_FIELD(panel + slot, u8 *, 0x1c);
            if (M2C_FIELD(panel + stat * 2, u8 *, PANEL_STAT_STATE) || M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN)) {
                other = M2C_FIELD(panel, void **, PANEL_OTHER);
                out->value = M2C_FIELD(M2C_FIELD(other, void **, PANEL_STAT_TABLE), u8 *, 1) +
                                           M2C_FIELD(other + outCount * 4, s16 *, PANEL_ENTRIES);
                out->stat = (u8)stat;
                other = M2C_FIELD(panel, void **, PANEL_OTHER);
                out->order = M2C_FIELD(other + outCount, u8 *, PANEL_STAT_ORDER);
                out->highlighted = 1;
                out->comparison = 0;
                ++outCount;
                ++out;
            }
            if (++slot == 5) slot = 0;
            ++scanned;
        } while (outCount != count);
    }
    {
        PanelStat *out;
        PanelStat *entries = (PanelStat *)(panel + PANEL_STAT_SOURCE);
        i = 0;
        if (i < outCount) {
            out = entries;
            do {
            slot = out->stat;
            if (M2C_FIELD(panel + slot * 2, u8 *, PANEL_STAT_STATE + 1) || M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN)) {
                out->highlighted = 0;
            } else {
                s32 j;
                PanelStat *next;
                j = i + 1;
                if (j < outCount) {
                    next = entries + j;
                    do {
                    if (slot == next->stat) {
                        out->highlighted = 0;
                        break;
                    }
                    ++next;
                    } while (++j < outCount);
                }
            }
            ++out;
            } while (++i < outCount);
        }
    }
    if (CountPanelEntries(panel + PANEL_STAT_SOURCE) != 0 &&
        M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN) &&
        gVersusGaugeHp[M2C_FIELD(panel, u8 *, PANEL_PLAYER) * 0x18] == 0) {
        u8 *flags = panel + PANEL_STAT_SOURCE + 2;
        flags[(CountPanelEntries(panel + PANEL_STAT_SOURCE) - 1) * 4] |= 0x40;
        marked = 1;
    } else {
        marked = 0;
    }
    {
    register PanelStat *out;
    s32 stat;
    out = (PanelStat *)(panel + PANEL_STAT_SOURCE) + outCount;
    for (; scanned < 5; ++scanned) {
        stat = M2C_FIELD(panel + scanned, u8 *, 0x1c);
        if (M2C_FIELD(panel + stat * 2, u8 *, PANEL_STAT_STATE) != M2C_FIELD(panel + stat * 2, u8 *, PANEL_STAT_STATE + 1)) {
            u8 *table;
            s32 value;
            if (M2C_FIELD(panel, u8 *, PANEL_PLAYER) == gPlayerSettings) {
                table = M2C_FIELD(panel, u8 **, PANEL_STAT_TABLE);
                other = M2C_FIELD(panel, void **, PANEL_OTHER);
                value = M2C_FIELD(M2C_FIELD(other, void **, PANEL_STAT_TABLE), u8 *, 1) +
                        (table[0] + table[outCount + 8]);
            } else {
                other = M2C_FIELD(panel, void **, PANEL_OTHER);
                table = M2C_FIELD(other, u8 **, PANEL_STAT_TABLE);
                value = table[1] + (table[0] + table[outCount + 3]);
            }
            out->value = value;
            out->stat = (u8)stat;
            other = M2C_FIELD(panel, void **, PANEL_OTHER);
            out->order = M2C_FIELD(other + outCount, u8 *, PANEL_STAT_ORDER);
            if (!M2C_FIELD(panel + stat * 2, u8 *, PANEL_STAT_STATE + 1) && !M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN))
                out->highlighted = 1;
            else
                out->highlighted = 0;
            out->comparison = 1;
            ++outCount;
            ++out;
        }
    }
    }
    if (!marked && M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN) &&
        gVersusGaugeHp[M2C_FIELD(panel, u8 *, PANEL_PLAYER) * 0x18] == 0) {
        u8 *flags = panel + PANEL_STAT_SOURCE + 2;
        flags[(CountPanelEntries(panel + PANEL_STAT_SOURCE) - 1) * 4] |= 0x40;
    }
}
#pragma opt_common_subs off
#pragma opt_strength_reduction off
/* Rebuild one versus-screen player panel's list of drawn stat entries from its
 * own source entries: clear the five display entries, then copy each source
 * entry whose value differs from the other player's CO (or that is already
 * highlighted) into the display list, rebased onto the other panel's base stat
 * value.  The display list therefore holds only the differences the gauge
 * between the two players draws. */
void BuildPanelDisplayEntries(void *panel) {
    s8 CountPanelEntries(void *);
    extern u8 gPlayerSettings;
    s32 count, i;
    PanelStat *out;
    PanelStatFlags *src;

    for (i = 0; i < 5; ++i) {
        M2C_FIELD(panel + i * 4, s16 *, PANEL_STAT_DISPLAY) = -1;
    }
    count = CountPanelEntries(panel + PANEL_STAT_SOURCE);
    i = 0;
    out = (PanelStat *)(panel + PANEL_STAT_DISPLAY);
    if (count > 0) {
        src = (PanelStatFlags *)(panel + PANEL_STAT_SOURCE + 2);
        do {
            if (!src->comparison || src->highlighted) {
                u8 player = M2C_FIELD(panel, u8 *, PANEL_PLAYER);
                s32 other = player == 0 ? 1 : 0;
                s32 otherTable = player == 0 ? 1 : 0;
                u8 *entry = &gPlayerSettings + other * VERSUS_DATA_STRIDE;
                void *table = M2C_FIELD(&gPlayerSettings + otherTable * VERSUS_DATA_STRIDE, void **, 4);
                if (M2C_FIELD(table + entry[0x13] * 4, void **, 0x1c) || src->highlighted) {
                    out->value = M2C_FIELD(M2C_FIELD(M2C_FIELD(panel, void **, PANEL_OTHER), void **, PANEL_STAT_TABLE), u8 *, 2)
                               + M2C_FIELD(panel + i * 4, s16 *, PANEL_STAT_SOURCE);
                    out->stat = src->stat;
                    out->order = src->order;
                    out->highlighted = src->highlighted;
                    ++out;
                }
            }
            ++i;
            src = (PanelStatFlags *)((u8 *)src + sizeof(PanelStat));
        } while (i < count);
    }
}
#pragma opt_strength_reduction on
#pragma opt_common_subs on
/* Reset a versus-screen player panel for its gauge animation: record how many of
 * the five stat entries are filled, then, when the player's CO gauge is shown,
 * clear the icon index of every entry in the stat, source and display lists and
 * empty stat entries 1..4. */
void ResetPanelEntries(void *panel) {
s8 CountPanelEntries(void *);void *entry;s32 i;
M2C_FIELD(panel,s8 *,PANEL_ENTRY_COUNT)=CountPanelEntries(panel+PANEL_ENTRIES);if(!M2C_FIELD(panel,u8 *,PANEL_GAUGES_SHOWN))return;
for(entry=panel+PANEL_ENTRIES,i=0;i<5;i++,entry+=4)M2C_FIELD(entry,u8 *,2)&=~7;
{void *q; s32 j;for(q=panel+PANEL_STAT_SOURCE,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=panel+PANEL_STAT_DISPLAY,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=panel+PANEL_ENTRIES+4,j=1;j<5;j++,q+=4)M2C_FIELD(q,s16 *,0)=-1;}
}

s32 GetPanelGaugeLength(void *arg0) {
    extern u8 gEffectTable;
    extern u8 gEffectDefaultVariant;
    u8 *p;
    s32 i;
    s32 min;
    s32 max;
    s32 a;
    s32 b;
    s16 t;
    s32 sum;
    u8 temp;

    temp = M2C_FIELD(arg0, u8 *, 0x64);
    max = 0;
    if (temp == 0) {
        a = 1;
    } else {
        a = 0;
    }
    if (temp == 0) {
        b = 1;
    } else {
        b = 0;
    }
    min = -1;
    if (M2C_FIELD((u8 *)M2C_FIELD(&gEffectTable, void **, b * 0x18) + M2C_FIELD(&gEffectDefaultVariant, u8 *, a * 0x18) * 4, s32 *, 0x1c) == 0) {
        for (p = arg0 + 0x36, i = 0; i < 5; i++, p += 4) {
            t = M2C_FIELD(p, s16 *, 0);
            if (t == -1) break;
            if (min == -1) {
                min = t;
            } else if (min >= t) {
                min = t;
            }
            sum = t + M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), void **, 4), u8 *, 2);
            if (max <= sum) {
                max = sum;
            }
        }
    }
    for (p = arg0 + 0x4a, i = 0; i < 5; i++, p += 4) {
        t = M2C_FIELD(p, s16 *, 0);
        if (t == -1) break;
        if (min == -1) {
            min = t;
        } else if (min >= t) {
            min = t;
        }
        if (max <= t) {
            max = t;
        }
    }
    if (min == -1) {
        return 0;
    }
    sum = max - min;
    if (sum <= 1) {
        sum = 1;
    }
    return sum;
}

/* Give each of the two versus screen panels its player index, a link to the
 * other player's panel, and whether that player's CO gauge entries are drawn
 * (read from the other player's CO stat table). */
void PlayerPanels_Setup(s32 panels) {
    extern u8 gPlayerSettings;
    s32 player;
    u8 *panel;
    u8 *settings;
    s32 other;
    u8 gaugeShown;

    player = 0;
    settings = &gPlayerSettings;
    panel = (u8 *)panels;
    do {
        if (player == 0) other = 1;
        else other = 0;
        M2C_FIELD(panel, u8 *, PANEL_PLAYER) = player;
        M2C_FIELD(panel, s32 *, PANEL_OTHER) = other * PANEL_SIZE + panels;
        gaugeShown = M2C_FIELD(M2C_FIELD(settings, void **, 4), u8 *, PANEL_CO_GAUGE_FLAG);
        player += 1;
        settings += VERSUS_DATA_STRIDE;
        M2C_FIELD(panel, u8 *, PANEL_GAUGES_SHOWN) = gaugeShown;
        panel += PANEL_SIZE;
    } while (player < 2);
}

/* Rebuild both players' status panels: the two 0x68-byte panel objects at p
   and p+0x68 take their value and thresholds from the versus player settings,
   then have their icons, positions and gauges refreshed. */
void PlayerPanels_Init(void *p){
void func_ov002_021e2eb8(void *,s32,s32);void func_ov002_021e3044(void *,s32,s32);
void BuildPanelStatEntries(void *);void func_ov002_021e3210(void *);void BuildPanelDisplayEntries(void *);
extern u8 gPlayerSettings;
func_ov002_021e2eb8(p,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,4)+M2C_FIELD(&gPlayerSettings,u8 *,0x13)*4,s32 *,0x2c),0);
func_ov002_021e2eb8(p+0x68,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,0x1c)+M2C_FIELD(&gPlayerSettings,u8 *,0x2b)*4,s32 *,0x2c),0);
func_ov002_021e3044(p,(M2C_FIELD(&gPlayerSettings,u8 *,0xd)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0xe)+9)/10);
func_ov002_021e3044(p+0x68,(M2C_FIELD(&gPlayerSettings,u8 *,0x25)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0x26)+9)/10);
BuildPanelStatEntries(p);BuildPanelStatEntries(p+0x68);
func_ov002_021e3210(p);func_ov002_021e3210(p+0x68);
BuildPanelDisplayEntries(p);BuildPanelDisplayEntries(p+0x68);
ResetPanelEntries(p);ResetPanelEntries(p+0x68);
}

/* Swap the battle screen between the 3D and 2D views: for an odd phase swap the
 * LCDs and capture the 3D engine, for an even phase capture the 2D engine,
 * moving the extended-palette VRAM bank with the view.  Returns the next
 * phase. */
M2C_UNK SwapBattleScreenCapture(s32 *phase) {
    u32 capture;
    if (*phase & 1) {
        REG_POWCNT1 |= POWCNT1_LCD_SWAP;
        GX_ReleaseBankForSubOBJ();
        GX_SetBankForSubBG(4);
        func_02003104(8);
        capture = DISPCAPCNT_CAPTURE_3D;
        REG_DISPCAPCNT = capture;
    } else {
        REG_POWCNT1 &= ~POWCNT1_LCD_SWAP;
        GX_ReleaseBankForSubBG();
        GX_SetBankForSubOBJ(8);
        func_02003104(4);
        capture = DISPCAPCNT_CAPTURE_2D;
        REG_DISPCAPCNT = capture;
    }
    return ++*phase;
}

#pragma opt_strength_reduction off
M2C_UNK func_ov002_021e3a7c(s32 *p) {
    extern u8 gPlayerSettings;
    extern u8 gEffectTable;
    void Set3DSpriteLayerBank(s32, s32);
    void Set3DSpriteLayerPalette(s32, s32);
    void Set3DSpriteLayerSize(s32, s32);
    s32 i;
    if (*p & 1) {
        Set3DSpriteLayerBank(2, 0);
        Set3DSpriteLayerBank(3, 0);
        Set3DSpriteLayerPalette(2, 15);
        Set3DSpriteLayerPalette(3, 14);
        i = M2C_FIELD(&gPlayerSettings, u8 *, 1);
        if (M2C_FIELD(M2C_FIELD(&gEffectTable, void **, i * 24), u8 *, 0x3D) != 2) {
            Set3DSpriteLayerSize(3, 1);
        } else {
            Set3DSpriteLayerSize(3, 0);
        }
    } else {
        Set3DSpriteLayerBank(2, 2);
        Set3DSpriteLayerBank(3, 2);
        Set3DSpriteLayerPalette(2, 31);
        Set3DSpriteLayerPalette(3, 30);
        if (M2C_FIELD(&gPlayerSettings, u8 *, 1) == 0) {
            i = 1;
        } else {
            i = 0;
        }
        if (M2C_FIELD(M2C_FIELD(&gEffectTable, void **, i * 24), u8 *, 0x3D) != 2) {
            Set3DSpriteLayerSize(3, 1);
        } else {
            Set3DSpriteLayerSize(3, 0);
        }
    }
}
#pragma opt_strength_reduction off
void func_ov002_021e3b7c(M2C_UNK *p) {
extern u32 gCur3DSpriteEngine, data_027e00c4;
extern u8 data_027e008c[];
s32 x,y,tx,ty; u32 old; u16 v;
if(*p&1)return;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
for(y=0,ty=0;y<192;y+=64,ty+=8){
v=(u16)((y&255)|0xc00);
for(tx=0,x=0;tx<32;tx+=8,x+=64)
func_01ffaacc((u16)(x&511),v,(u16)(((tx+(ty<<5))&1023)|0xf000),data_027e008c,0);
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction on
void SwapBattleScreen(void) {
    M2C_UNK SwapBattleScreenCapture(M2C_UNK *);
    extern M2C_UNK gBattleSpriteState;
    SwapBattleScreenCapture(&gBattleSpriteState);
}

void UpdateBattleSpriteLayers(void) {
    M2C_UNK func_ov002_021e3a7c(M2C_UNK *);
    extern M2C_UNK gBattleSpriteState;
    func_ov002_021e3a7c(&gBattleSpriteState);
}

void DrawBattleSpriteGrid(void) {

    extern M2C_UNK gBattleSpriteState;
    func_ov002_021e3b7c(&gBattleSpriteState);
}

/* Prepare the battle screen's 3D-sprite overlay: clear the two shared VRAM banks,
 * put the sub screen's sprite bank into mode 3, reset its layer tile fields and
 * palettes, then install the three per-frame callbacks that swap the two screen
 * halves, reconfigure the layers and draw the sprite grid.  `phase` is the half
 * currently shown. */
void InitBattleSpriteScene(s32 *phase) {M2C_UNK GX_ReleaseBankForSubBG(void);M2C_UNK GX_ReleaseBankForSubOBJ(void);void Set3DSpriteLayerPalette(s32,s32);void Set3DSpriteLayerSize(s32,s32);void CreateFrameCallbackTask(s32,s32);
extern volatile u16 *g3DSpriteBankSub;extern u32 gCur3DSpriteEngine;extern u32 g3DSpriteEngineSub;
GX_ReleaseBankForSubBG();GX_ReleaseBankForSubOBJ();
g3DSpriteBankSub[0]=(u16)((g3DSpriteBankSub[0]&~0x7)|0x3);
g3DSpriteBankSub[0]=(u16)(g3DSpriteBankSub[0]&~DS3D_BANK_MODE0);
g3DSpriteBankSub[0]=(u16)(g3DSpriteBankSub[0]&~DS3D_BANK_MODE1);
g3DSpriteBankSub[0]=(u16)(g3DSpriteBankSub[0]&~DS3D_BANK_MODE2);
g3DSpriteBankSub[0]=(u16)(g3DSpriteBankSub[0]|DS3D_BANK_MODE3);
g3DSpriteBankSub[0]=(u16)(g3DSpriteBankSub[0]|DS3D_BANK_MODE4);
g3DSpriteBankSub[1]=(u16)((g3DSpriteBankSub[1]&~0xC0)|0x40);
g3DSpriteBankSub[1]=(u16)(g3DSpriteBankSub[1]&~0x100);
{u32 savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
g3DSpriteBankSub[6]=(u16)((g3DSpriteBankSub[6]&~0x3C)|0x4);
g3DSpriteBankSub[6]=(u16)(g3DSpriteBankSub[6]|0x80);
Set3DSpriteLayerPalette(3,0);Set3DSpriteLayerSize(3,1);gCur3DSpriteEngine=savedEngine;}
*phase=0;
CreateFrameCallbackTask((s32)SwapBattleScreen,2);
CreateFrameCallbackTask((s32)UpdateBattleSpriteLayers,7);
CreateFrameCallbackTask((s32)DrawBattleSpriteGrid,9);
}

/* Remove the battle sprite overlay's three per-frame callbacks that
 * InitBattleSpriteScene installed (the screen swap, the layer update and the
 * sprite-grid draw).  Callers hand it the battle sprite state, which the
 * original does not use. */
void TeardownBattleSpriteScene(void) {
    M2C_UNK DeleteFrameCallbackTask(void (*)(void));

    DeleteFrameCallbackTask(SwapBattleScreen);
    DeleteFrameCallbackTask(UpdateBattleSpriteLayers);
    DeleteFrameCallbackTask(DrawBattleSpriteGrid);
}

s32 IsBattleScreenSwapped(s32 *arg0) {
    return *arg0 & 1;
}

/* Fill in one unit-model disc effect: its centre, the colour, radius and duration
 * it animates over, the polygon attributes it draws with, and the effect record
 * and variant it belongs to; the disc starts at frame 0. */
void InitEffectDisc(void *arg0, s16 x, s16 y, s16 z, u16 radiusFrom, u16 radiusTo, u16 color, u16 duration, u8 polygonAttr, u8 alphaTo, u8 mirror, u8 unk13) {
    EffectDisc *disc = (EffectDisc *) arg0;
    disc->x = x;
    disc->y = y;
    disc->z = z;
    disc->radiusFrom = radiusFrom;
    disc->radiusTo = radiusTo;
    disc->color = color;
    disc->duration = duration;
    disc->polygonAttr = polygonAttr;
    disc->alphaTo = alphaTo;
    disc->mirror = mirror;
    disc->unk13 = unk13;
    disc->elapsed = 0;
}

/* Advance one frame of a unit-model disc effect: run its elapsed frame counter
 * up to the disc's duration. */
void AdvanceEffectDisc(EffectDisc *disc) {
    u16 elapsed;

    elapsed = disc->elapsed;
    if ((u32)elapsed < (u32)disc->duration) {
        disc->elapsed = (u16)(elapsed + 1);
    }
}

/* Draws one frame of a unit model's disc effect: eases the polygon alpha and the
   radius over the disc's lifetime, draws the filled circle in 3D and restores
   the default polygon attribute. */
void DrawModelEffectDisc(void *p) {
    s32 EaseInterpolate(s32,s32,s32,s32,s32);
    EffectDisc *disc = (EffectDisc *)p;
    s32 alpha, radius;
    if (disc->elapsed >= disc->duration) return;
    alpha = EaseInterpolate(0, disc->alphaTo, 0, disc->elapsed, disc->duration);
    radius = EaseInterpolate(4, disc->radiusFrom, disc->radiusTo, disc->elapsed, disc->duration);
    SetGxPolygonAttr(disc->polygonAttr, (u8)alpha);
    ResetGxTextureParams();
    DrawGxCircleFan(disc->mirror ? disc->x : -disc->x, disc->y, disc->z, radius, 32, disc->color);
    SetGxPolygonAttr(0, 31);
}

void func_ov002_021e3f28(void) {

}

/* Initialise a battle unit view's gauge layer: flag the view's side, take its
   gauge length from that side's panel, reset the gauge frame, screenshake, y offset
   and animation nibble, then pick the character expression from the gauge
   comparison and the CO's expression row. */
void InitUnitViewGauge(void *view, s32 side) {
    extern u8 gEffectVariants[];
    extern u8 gVersusPlayerCoIndex[];
    extern s8 gCoExpressionTable[];
    s32 GetPanelGaugeLength(void *);
    s32 CompareUnitViewGauges(void *, s32);
    s32 RandomIntRange(s32, s32);
    s8 expr;

    M2C_FIELD(view, u8 *, UNIT_VIEW_FLAGS) = (M2C_FIELD(view, u8 *, UNIT_VIEW_FLAGS) & ~0xF) | ((u8)side & 0xF);
    M2C_FIELD(view, s8 *, UNIT_VIEW_GAUGE_LENGTH) = GetPanelGaugeLength((s32)gEffectVariants + side * 0x68);
    M2C_FIELD(view, s8 *, UNIT_VIEW_GAUGE_FRAME) = 0;
    M2C_FIELD(view, s8 *, UNIT_VIEW_SHAKE) = 0x10;
    M2C_FIELD(view, s8 *, UNIT_VIEW_Y) = 0;
    M2C_FIELD(view, u8 *, UNIT_VIEW_FLAGS) = M2C_FIELD(view, u8 *, UNIT_VIEW_FLAGS) & ~0xF0;
    M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION) = CompareUnitViewGauges(view, 1);
    expr = M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION);
    switch (expr) {
    case 0:
        M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION) = -1;
        return;
    case 1:
        M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION) = gCoExpressionTable[gVersusPlayerCoIndex[side * VERSUS_DATA_STRIDE] * 3 + RandomIntRange(0, 1)];
        return;
    case 2:
        M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION) = gCoExpressionTable[gVersusPlayerCoIndex[side * VERSUS_DATA_STRIDE] * 3 + 2];
        return;
    default:
        M2C_FIELD(view, s8 *, UNIT_VIEW_EXPRESSION) = -1;
        return;
    }
}

/* Compares the two versus-screen gauges. The low nibble of the state's byte 3
   picks which 24-byte gauge record is "this" side; returns 2 when the other
   side's gauge is far enough ahead (or both are low), 0 otherwise. */
s32 ComparePlayerGauges(void *arg0) {
    extern u8 data_ov002_021f30fd[];
    extern u8 gVersusPlayerStates[];
    extern u8 gVersusPlayerCoIndex[];
    u32 slot;
    s32 ofs;
    u8 alive;
    s32 value;

    ofs = ((u32)(M2C_FIELD(arg0, u8 *, 3) << 0x1C) >> 0x1C) * 0x18;
    slot = (u32)(M2C_FIELD(arg0, u8 *, 3) << 0x1C) >> 0x1C;
    if (gVersusPlayerCoIndex[ofs] == 0) {
        return 0;
    }
    alive = gVersusPlayerStates[ofs];
    if (alive == 0 || gVersusPlayerStates[(slot == 0 ? 1 : 0) * 0x18] == 0) {
        if (alive != 0) {
            return 0;
        }
        if ((data_ov002_021f30fd[ofs] + 9) / 10 >= (data_ov002_021f30fd[(slot == 0 ? 1 : 0) * 0x18] + 9) / 10 + 3) {
            return 0;
        }
        return 2;
    }
    value = (data_ov002_021f30fd[ofs] + 9) / 10;
    if (value <= 4) {
        if ((data_ov002_021f30fd[(slot == 0 ? 1 : 0) * 0x18] + 9) / 10 <= 4) {
            return 2;
        }
    }
    if (value + 4 <= (data_ov002_021f30fd[(slot == 0 ? 1 : 0) * 0x18] + 9) / 10) {
        return 2;
    }
    return 0;
}

