/* 30 functions from 0x022162F4 to 0x022172B0 (ov006), found by ds-decomp. */
#include "common.h"
#include "ov006_map_transfer.h"
#include "battle_map.h"
#include "map_selection.h"

static inline u16 NegativePanelScroll(s32 value) { return -value; }
typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;

/* Attaches a shared argument to a block of 3D sprite entries in three tables, then draws a 6x2 grid of 24x24 sprites from a sprite list. */
void func_ov006_022162f4(void *arg0) {
    s32 Divide(s32, M2C_UNK);
    s32 Modulo(u8, M2C_UNK);
    M2C_UNK SpriteCellListUpdateTouch(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK UpdateSpriteAnimation(void *);
    M2C_UNK FocusSpriteSlotById(M2C_UNK);
    extern s8 gFriendCodeInput[];
    extern u16 *gKeyState;
    register void *p asm("r6") = arg0;
    s8 var_r4;
    u16 temp_r0;
    u16 temp_r1;
    s8 temp_r0_2;
    s8 temp_r2;
    s8 temp_r2_2;
    s8 temp_r2_3;
    s8 temp_r2_4;
    s8 var_r1;
    s16 temp_r2_5;
    s16 temp_r3;
    s16 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s8 *var_r1_2;
    s8 *var_r2;

    UpdateSpriteAnimation(M2C_FIELD(p, void **, 0x48));
    SpriteCellListUpdateTouch(M2C_FIELD(p, void **, 0x40));
    var_r4 = M2C_FIELD(p, s8 *, 0x38);
    temp_r0 = gKeyState[0];
    temp_r1 = gKeyState[1];
    if (temp_r0 & 2) {
        FocusSpriteSlotById(0xC);
        return;
    }
    if (temp_r0 & 0x400) {
        if ((s32) var_r4 > 0) {
            if ((var_r4 == 0xB) && (gFriendCodeInput[var_r4] != 0)) {
                gFriendCodeInput[var_r4] = 0;
            } else {
                temp_r2 = var_r4 - 1;
                if (((s32) temp_r2 >= 0) && ((s32) temp_r2 < 0xC) && ((gFriendCodeInput[temp_r2] != 0) || (((s32) temp_r2 > 0) && (gFriendCodeInput[temp_r2 - 1] != 0)))) {
                    M2C_FIELD(p, s8 *, 0x38) = temp_r2;
                }
                var_r1 = M2C_FIELD(p, s8 *, 0x38);
                if ((s32) var_r1 < 0xB) {
                    var_r2 = gFriendCodeInput + var_r1;
                    do {
                        var_r1 += 1;
                        *var_r2 = (s8) var_r2[1];
                        var_r2 += 1;
                    } while ((s32) var_r1 < 0xB);
                }
                gFriendCodeInput[0xB] = 0;
            }
            PlaySoundEffect(0x1000D);
            return;
        }
        if ((var_r4 == 0) && (gFriendCodeInput[var_r4] != 0)) {
            if ((s32) var_r4 < 0xB) {
                var_r1_2 = gFriendCodeInput + var_r4;
                do {
                    var_r4 += 1;
                    *var_r1_2 = (s8) var_r1_2[1];
                    var_r1_2 += 1;
                } while ((s32) var_r4 < 0xB);
            }
            gFriendCodeInput[0xB] = 0;
            PlaySoundEffect(0x1000D);
            return;
        }
        PlaySoundEffect(0x1001D);
        return;
    }
    if (temp_r0 & 8) {
        FocusSpriteSlotById(0xD);
        return;
    }
    if (temp_r1 & 0x200) {
        temp_r2_2 = var_r4 - 1;
        if (((s32) temp_r2_2 >= 0) && ((s32) temp_r2_2 < 0xC) && ((gFriendCodeInput[temp_r2_2] != 0) || (((s32) temp_r2_2 > 0) && (gFriendCodeInput[temp_r2_2 - 1] != 0)))) {
            M2C_FIELD(p, s8 *, 0x38) = temp_r2_2;
        }
    } else if (temp_r1 & 0x100) {
        temp_r2_3 = var_r4 + 1;
        if (((s32) temp_r2_3 >= 0) && ((s32) temp_r2_3 < 0xC) && ((gFriendCodeInput[temp_r2_3] != 0) || (((s32) temp_r2_3 > 0) && (gFriendCodeInput[temp_r2_3 - 1] != 0)))) {
            M2C_FIELD(p, s8 *, 0x38) = temp_r2_3;
        }
    }
    temp_r0_2 = M2C_FIELD(M2C_FIELD(p, void **, 0x40), s8 *, 0xC);
    if ((s32) temp_r0_2 >= 0) {
        temp_r2_4 = temp_r0_2;
        if (((s32) temp_r2_4 >= 0) && ((s32) temp_r2_4 < 0xC) && ((gFriendCodeInput[temp_r2_4] != 0) || (((s32) temp_r2_4 > 0) && (gFriendCodeInput[temp_r2_4 - 1] != 0)))) {
            M2C_FIELD(p, s8 *, 0x38) = temp_r2_4;
        }
    }
    temp_r5 = (Modulo(M2C_FIELD(p, s8 *, 0x38), 6) * 0x18) + 0x38;
    temp_r3 = M2C_FIELD(p, s16 *, 0x3A);
    temp_r2_5 = (Divide(M2C_FIELD(p, s8 *, 0x38), 6) * 0x18) + 8;
    if ((temp_r3 == -0x8000) && (M2C_FIELD(p, s16 *, 0x3C) == -0x8000)) {
        goto block_57;
    }
    var_r0 = temp_r3 - temp_r5;
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    if (var_r0 <= 1) {
        var_r0_2 = M2C_FIELD(p, s16 *, 0x3C) - temp_r2_5;
        if (var_r0_2 < 0) {
            var_r0_2 = 0 - var_r0_2;
        }
        if (var_r0_2 <= 1) {
block_57:
            M2C_FIELD(p, s16 *, 0x3A) = temp_r5;
            M2C_FIELD(p, s16 *, 0x3C) = temp_r2_5;
        } else {
            goto block_58;
        }
    } else {
block_58:
        M2C_FIELD(p, s16 *, 0x3A) = (s16) ((s32) (temp_r5 + temp_r3 + 1) >> 1);
        M2C_FIELD(p, s16 *, 0x3C) = (s16) ((s32) (temp_r2_5 + M2C_FIELD(p, s16 *, 0x3C) + 1) >> 1);
    }
    if (var_r4 == M2C_FIELD(p, s8 *, 0x38)) {
        return;
    }
    PlaySoundEffect(0x10019);
}

void func_ov006_0221661c(void *spriteList) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain;
    extern u8 data_ov006_02218340[], data_ov006_0221837c[], data_ov006_02218388[];
    extern u8 data_ov006_02218778[], data_ov006_022187a0[], data_ov006_022187c8[];
    void *AddSpriteSlot(u8, u8, void *, s32);
    void SelectSpriteSlot(s32);
    void func_020b2158(s32);
    void AddSpriteCell(s32, s16, s16, s32, s32, u16, s32);
    void *savedEngine = gCur3DSpriteEngine;
    s32 i, j, k;
    u8 x, y;
    u8 *entry;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    for (entry = data_ov006_02218340, i = 0; i < 10; i++, entry += 6)
        M2C_FIELD(AddSpriteSlot(entry[0], entry[1], data_ov006_02218778, i), void **, 0x10) = spriteList;
    for (entry = data_ov006_0221837c, j = 10; j <= 11; j++, entry += 6)
        M2C_FIELD(AddSpriteSlot(entry[0], entry[1], data_ov006_022187a0, j), void **, 0x10) = spriteList;
    for (entry = data_ov006_02218388, k = 12; k <= 13; k++, entry += 6)
        M2C_FIELD(AddSpriteSlot(entry[0], entry[1], data_ov006_022187c8, k), void **, 0x10) = spriteList;
    gCur3DSpriteEngine = savedEngine;
    SelectSpriteSlot(4);
    func_020b2158(0);
    for (y = 0; y < 2; y++)
        for (x = 0; x < 6; x++)
            AddSpriteCell(M2C_FIELD(spriteList, s32 *, 0x40), (s16)(x * 24 + 56), (s16)(y * 24 + 8), 24, 24, (u16)(x + y * 6), 14);
}

/* Hide the map-code entry panel: hide every sprite slot, clear the panel's
 * sprite grid and clear the sprite-slot focus flag. */
void HideMapCodeEntryPanel(void *panel) {
    M2C_UNK SpriteCellListClear(s32);
    M2C_UNK ClearSpriteSlotFocusFlag();
    M2C_UNK HideAllSpriteSlots();
    HideAllSpriteSlots();
    SpriteCellListClear(M2C_FIELD(panel, s32 *, MAP_CODE_PANEL_GRID));
    ClearSpriteSlotFocusFlag();
}

void func_ov006_022167b8(void) {
    M2C_UNK func_ov006_0221619c();
    func_ov006_0221619c();
}

#pragma push
#pragma scheduling off
void func_ov006_022167c4(void *arg0) {
extern s8 gFriendCodeInput[];extern u8 data_ov006_022188a8[],data_ov006_02218776[],data_ov006_02218774[],data_ov006_022188a0[],data_ov006_022188cc[],data_ov006_022188dc[],data_ov006_022188b0[],data_ov006_022188bc[];
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
void *CreateScrollingTextSprite(void*);s32 GetSpriteAnimValue(void*);s32 GetLocalizedFileName(void*);s32 GetUiColor(s32);
void *w,*saved;s32 scroll;
MI_CpuCopy8(M2C_FIELD(arg0,void**,0x34),gFriendCodeInput,13);
M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0x16)=4;M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0x14)=16;M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0x17)=16;
SetTextSpriteValue(M2C_FIELD(arg0,void**,0x44),0);
w=M2C_FIELD(arg0,void**,0x44);M2C_FIELD(w,u8*,0x20)&=~0xe0;w=M2C_FIELD(arg0,void**,0x44);M2C_FIELD(w,u8*,0x28)&=~0xe0;
M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u16*,0x12)=0x1d0;M2C_FIELD(M2C_FIELD(arg0,void**,0x44),u8*,0x21)=22;M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x24)=data_ov006_022188a8;
w=M2C_FIELD(arg0,void**,0x48);M2C_FIELD(w,u16*,14)=256;M2C_FIELD(w,u16*,16)=0;M2C_FIELD(w,u16*,12)=12;M2C_FIELD(w,u16*,2)=M2C_FIELD(w,u16*,4);
scroll=GetSpriteAnimValue(M2C_FIELD(arg0,void**,0x48));SetSpriteSlotScroll(scroll,0);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Configure3DSpriteLayer(0,data_ov006_02218776);Configure3DSpriteLayer(1,data_ov006_02218774);
{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,void**,0);*reg=*reg|16;}
{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,void**,0);*reg=*reg|32;}
{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,void**,0);*reg=*reg|64;}
{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,void**,0);*reg=*reg|128;}
{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,void**,0);*reg=*reg|256;}
{u16 *volatile reg=(u16*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0)+18);*reg=*reg&~192;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,81)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,82)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,83)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,58)=NegativePanelScroll(scroll);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,66)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,56)=NegativePanelScroll(scroll);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,64)=0;
Clear3DSpriteLayer(0);Clear3DSpriteLayer(1);Clear3DSpriteLayer(3);
SetFileDirectory(data_ov006_022188a0);OpenNarcArchive(GetLocalizedFileName(data_ov006_022188cc));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_022188dc),M2C_FIELD(gCur3DSpriteEngine,s32*,0x20));
LoadNarcFileDecompressed(GetLocalizedFileName(data_ov006_022188b0),M2C_FIELD(gCur3DSpriteEngine,s32*,0x24));CloseNarcArchive();
LoadFileToSpriteBuffer(data_ov006_022188bc,0,96);
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32*,0x20),32,24,0);SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32*,0x24),32,24,0);Clear3DSpriteLayerVram(3);
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;
LoadSpriteResource(1,0,5,M2C_FIELD(gCur3DSpriteEngine,s32*,0x1c)+0x3a00);
LoadSpriteResource(1,2,0,M2C_FIELD(gCur3DSpriteEngine,s32*,0x30)+0x2c0);
Load3DSpritePattern(0x1000,1,GetUiColor(9),2);
gCur3DSpriteEngine=g3DSpriteEngineSub;
M2C_FIELD(arg0,void**,0x4c)=CreateScrollingTextSprite(arg0);
M2C_FIELD(M2C_FIELD(arg0,void**,0x4c),u16*,0x3e)=320;
w=M2C_FIELD(arg0,void**,0x4c);M2C_FIELD(w,u32*,0x40)=(M2C_FIELD(w,u32*,0x40)&~0x3fc0000)|0x180000;
SetTextById(M2C_FIELD(arg0,void**,0x4c),0x4400000f);Show3DSpriteSlide(M2C_FIELD(arg0,void**,0x4c));gCur3DSpriteEngine=saved;HideAllSpriteSlots();
}
#pragma pop
void func_ov006_02216bac(void) {
    void func_ov006_0221661c();
    func_ov006_0221661c();
}

void func_ov006_02216bb8(void) {
    void HideMapCodeEntryPanel();
    HideMapCodeEntryPanel();
}

/* Frame step of the map-code entry panel: advance its reveal tween and, once the
 * tween has reached its end, resume the panel sprite's animation. */
void UpdateMapCodeEntryPanel(void *panel) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK UpdateSpriteAnimation(void *);
    SpriteTween *tween = M2C_FIELD(panel, SpriteTween **, MAP_CODE_PANEL_SPRITE);
    u8 finished = M2C_FIELD(tween, u16 *, 2) == M2C_FIELD(tween, s16 *, 0xC);
    if (finished) {
        Sprite_ResumeAnimation(panel);
        return;
    }
    UpdateSpriteAnimation(tween);
}

void func_ov006_02216bfc(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

/* Reset the sprite-slot manager's scroll offset to the origin. */
void ResetSpriteSlotScroll(void) {
    M2C_UNK SetSpriteSlotScroll(M2C_UNK, M2C_UNK);
    SetSpriteSlotScroll(0, 0);
}

/* Creates and fully initializes a map/UI cursor object from the overlay's object pool,
   attaching its sprite, panel and tile-selection children. */
void CreateMapCodeEntryPanel(s32 selectedUnit) {
    void *CreateSpriteObject(void *, s32);
    void MI_CpuFill8(void *, s32, u32);
    void *MemAlloc(u32);
    void *HeapAllocBlock(u32);
    extern M2C_UNK gHeapObjectVTable, data_ov006_022187f0, gMapCodeEntryPanelVTable;
    void *obj, *child;

    obj = ((void *(*)(void *)) CreateSpriteObject)(&data_ov006_022187f0);
    if (obj == NULL) {
        return;
    }
    M2C_FIELD(obj, void **, 0) = &gMapCodeEntryPanelVTable;
    M2C_FIELD(obj, s32 *, 0x34) = selectedUnit;
    M2C_FIELD(obj, u8 *, 0x38) = 0;
    M2C_FIELD(obj, s16 *, 0x3a) = -0x8000;
    M2C_FIELD(obj, s16 *, 0x3c) = -0x8000;
    child = MemAlloc(0x24);
    if (child != NULL) {
        M2C_FIELD(child, u16 *, 0x10) = 0xc;
        M2C_FIELD(child, u8 *, 0x12) = 0;
        M2C_FIELD(child, s32 *, 0) = 0;
        M2C_FIELD(child, s32 *, 4) = 0;
        M2C_FIELD(child, s8 *, 8) = -1;
        M2C_FIELD(child, s8 *, 9) = -1;
        M2C_FIELD(child, s8 *, 0xa) = -1;
        M2C_FIELD(child, s8 *, 0xb) = -1;
        M2C_FIELD(child, u8 *, 0xd) = 0xff;
        M2C_FIELD(child, s8 *, 0xc) = -1;
        M2C_FIELD(child, u8 *, 0xe) = 0;
        M2C_FIELD(child, u8 *, 0xf) = 0xff;
        M2C_FIELD(child, void **, 0x14) = HeapAllocBlock(0x90);
        MI_CpuFill8(M2C_FIELD(child, void **, 0x14), 0, 0x90);
    }
    M2C_FIELD(obj, void **, 0x40) = child;
    child = MemAlloc(0x2c);
    if (child != NULL) {
        M2C_FIELD(child, void **, 0) = &gHeapObjectVTable;
        M2C_FIELD(child, u8 *, 4) = 0;
        M2C_FIELD(child, u16 *, 0x12) = 0;
        M2C_FIELD(child, u8 *, 0x14) = 8;
        M2C_FIELD(child, u8 *, 0x15) = 8;
        M2C_FIELD(child, u8 *, 0x16) = 1;
        M2C_FIELD(child, u8 *, 0x17) = 8;
        M2C_FIELD(child, u8 *, 0x18) = 8;
        M2C_FIELD(child, Ov006C24Flags *, 0x20).active = 0;
        M2C_FIELD(child, Ov006C24Flags *, 0x20).mode = 0;
        M2C_FIELD(child, Ov006C24Flags *, 0x20).kind = 2;
        M2C_FIELD(child, u8 *, 0x21) = 0;
        M2C_FIELD(child, s32 *, 0x24) = 0;
        M2C_FIELD(child, u8 *, 0x28) &= ~0xe0;
        M2C_FIELD(child, u8 *, 0x29) = 0;
    }
    M2C_FIELD(obj, void **, 0x44) = child;
    child = MemAlloc(0x12);
    if (child != NULL) {
        M2C_FIELD(child, u8 *, 0) = 4;
        M2C_FIELD(child, u8 *, 1) = 0;
        M2C_FIELD(child, u16 *, 2) = 0;
        M2C_FIELD(child, u16 *, 4) = 0;
        M2C_FIELD(child, u16 *, 6) = 1;
        M2C_FIELD(child, u16 *, 8) = 0;
        M2C_FIELD(child, u16 *, 0xa) = 1;
        M2C_FIELD(child, u16 *, 0xc) = 1;
        M2C_FIELD(child, u16 *, 0xe) = 0;
        M2C_FIELD(child, u16 *, 0x10) = 0;
        M2C_FIELD(child, u16 *, 2) = M2C_FIELD(child, u16 *, 4);
    }
    M2C_FIELD(obj, void **, 0x48) = child;
}

/* The map-code entry panel's vtable free method: reset the vtable, free its grid
 * child and the glyph heap block the grid owns, destroy its sub-panel, free its
 * sprite and then free the panel itself. */
void *FreeMapCodeEntryPanel(void *panel) {
    M2C_UNK MemFree(void *);
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK gMapCodeEntryPanelVTable;
    void *child;
    void *sub;

    M2C_FIELD(panel, void **, 0) = &gMapCodeEntryPanelVTable;
    child = M2C_FIELD(panel, void **, MAP_CODE_PANEL_GRID);
    if (child != NULL) {
        HeapFreeBlock(M2C_FIELD(child, s32 *, 0x14));
        MemFree(child);
    }
    sub = M2C_FIELD(panel, void **, MAP_CODE_PANEL_SUBPANEL);
    if (sub != NULL) {
        M2C_FIELD(M2C_FIELD(sub, void **, 0), void (**)(void *), 4)(sub);
    }
    sub = M2C_FIELD(panel, void **, MAP_CODE_PANEL_SPRITE);
    if (sub != NULL) MemFree(sub);
    MemFree(panel);
    return panel;
}

/* The map-code entry panel's destroy method: reset its vtable, free its grid child
 * and the glyph heap block the grid owns, destroy its sub-panel and free its
 * sprite child, then hand the panel back (FreeMapCodeEntryPanel also frees the
 * panel itself). */
void *DestroyMapCodeEntryPanel(void *panel) {
    M2C_UNK MemFree(void *);
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK gMapCodeEntryPanelVTable;
    void *child;
    void *sub;

    M2C_FIELD(panel, void **, 0) = &gMapCodeEntryPanelVTable;
    child = M2C_FIELD(panel, void **, MAP_CODE_PANEL_GRID);
    if (child != NULL) {
        HeapFreeBlock(M2C_FIELD(child, s32 *, 0x14));
        MemFree(child);
    }
    sub = M2C_FIELD(panel, void **, MAP_CODE_PANEL_SUBPANEL);
    if (sub != NULL) {
        M2C_FIELD(M2C_FIELD(sub, void **, 0), void (**)(void *), 4)(sub);
    }
    sub = M2C_FIELD(panel, void **, MAP_CODE_PANEL_SPRITE);
    if (sub != NULL) MemFree(sub);

    return panel;
}

/* True when value lies within the inclusive range [min, max]. */
u8 IsValueInRange(s32 value, s32 min, s32 max) {
    s32 inRange;

    if ((min <= value) && (value <= max)) inRange = 1;
    else inRange = 0;
    return inRange;
}

/* Whether this console hosts an active link session (a session is running and
 * the local side is its host, not a guest); the map-record exchange of the
 * transfer panel sends on the host and receives on the guests. */
u8 IsLinkSessionHost(void) {
    s32 IsLinkSessionActive();
    s32 IsLocalSessionHost();
    s32 result;

    if (IsLinkSessionActive() && IsLocalSessionHost()) result = 1;
    else result = 0;
    return result;
}

/* Whether the link map-transfer panel is showing transfer step 1. */
u8 IsMapTransferPanelStep1(void) {
    void *GetMapTransferPanelState(void);
    return M2C_FIELD(GetMapTransferPanelState(), u8 *, MAP_TRANSFER_PANEL_STEP) == 1;
}

/* Whether the link map-transfer panel is showing transfer step 2. */
u8 IsMapTransferPanelStep2(void) {
    void *GetMapTransferPanelState(void);
    return M2C_FIELD(GetMapTransferPanelState(), u8 *, MAP_TRANSFER_PANEL_STEP) == 2;
}

/* Whether the link map-transfer panel is showing transfer step 3. */
u8 IsMapTransferPanelStep3(void) {
    void *GetMapTransferPanelState(void);
    return M2C_FIELD(GetMapTransferPanelState(), u8 *, MAP_TRANSFER_PANEL_STEP) == 3;
}

/* Whether the link map-transfer panel is showing transfer step 4. */
u8 IsMapTransferPanelStep4(void) {
    void *GetMapTransferPanelState(void);
    return M2C_FIELD(GetMapTransferPanelState(), u8 *, MAP_TRANSFER_PANEL_STEP) == 4;
}

/* True when the battle map in play is a custom map (id in the custom range). */
void Ov006_IsCurrentMapCustom(void) {
    u8 IsValueInRange(s32, s32, s32);
    extern void **gCurrentMap;
    IsValueInRange(M2C_FIELD(*gCurrentMap, s16 *, MAP_ID), MAP_CUSTOM_FIRST, MAP_CUSTOM_LINK_END);
}

/* Rebuild the campaign map headers, clear the other players' pages in the
 * transfer panel, copy the fresh header page into the local player's slot and
 * start the link exchange that gathers every player's page. */
void SyncLinkCampaignMapPages(void *panel) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, s32);
    M2C_UNK MI_CpuCopy32(s32, s32, s32);
    M2C_UNK CreateLinkPlayerDataListener(void *, s32, s32, void *);
    M2C_UNK LoadCampaignMapHeaders();
    s32 pageBase;
    u8 local;

    LoadCampaignMapHeaders();
    MI_CpuFill32(0, M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0) + 0x1068, 0x3138);
    local = M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_LOCAL);
    if (local) {
        pageBase = M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0);
        MI_CpuCopy32(pageBase, (s32)((s32 (*)[21])pageBase + local * 0x32), 0x1068);
    }
    CreateLinkPlayerDataListener((void *)((u8 *)panel + MAP_TRANSFER_PANEL_PAGES), M2C_FIELD((u8 *)panel + M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_LOCAL) * 4, s32 *, MAP_TRANSFER_PANEL_PAGES), 0x1068, panel);
}

/* Syncs the battle map chosen in a link/online session among the players: the map
 * id (gCurrentMap+0x5142, MAP_ID) is split into 4 blocks of 0x32 ids, one per
 * player.  When the current id belongs to this player (setup+0x4c is the local
 * player id) its map record is loaded and sent to the others; the other players
 * receive it instead. */
void SyncLinkBattleMap(void *setup) {
extern void **gCurrentMap;
s32 Divide(s32,s32);
s32 GetMapRecordBuffer();
M2C_UNK LoadMapRecord(u16,s32);
s32 GetSaveRecordBuffer();
M2C_UNK CreateLinkBlockSender(s32,s32,void *);
M2C_UNK CreateLinkBlockReceiver(s32,s32,void *);
u16 mapId=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
u16 slot=Divide(mapId-0xe1,0x32);
if(!IsValueInRange((s16)mapId,0xe1,0x1a9)) return;
if(M2C_FIELD(setup,u8 *,0x4c)==slot) {
LoadMapRecord((u16)(mapId-slot*0x32),GetMapRecordBuffer());
CreateLinkBlockSender(GetSaveRecordBuffer(),0x6f8,setup);
return;
}
CreateLinkBlockReceiver(GetSaveRecordBuffer(),0x6f8,setup);
}

/* Exchange the shared map settings with the other linked players when a battle
 * starts: the session host (local player 0, at setup+0x4C) sends its 16 bytes of
 * settings to them, while every other player receives the host's settings. */
void SyncLinkMapSettings(void *setup) {
    void *GetMapSettings();
    M2C_UNK CreateLinkBlockSender(s32, s32, void *);
    M2C_UNK CreateLinkBlockReceiver(s32, s32, void *);

    if (M2C_FIELD(setup, u8 *, 0x4c) == 0) {
        CreateLinkBlockSender((s32)GetMapSettings(), 0x10, setup);
        return;
    }
    CreateLinkBlockReceiver((s32)GetMapSettings(), 0x10, setup);
}

/* Start a linked battle: load the battle map its map settings select and, when the
 * local player is not slot 0 (a guest), apply the received map settings. */
void LoadLinkBattleMap(void *setup) {
    M2C_UNK MapSettings_Apply(M2C_UNK);
    M2C_UNK LoadBattleMap(u32);
    LoadBattleMap((u32) (((MapSettings *) GetMapSettings())->rules << 0x14) >> 0x15);
    if (M2C_FIELD(setup, u8 *, 0x4C) == 0) {
        return;
    }
    MapSettings_Apply(0);
}

/* Start exchanging the transfer panel's five-map record list with the other linked
 * players: the session host sends its own list, while the guests receive the
 * others' lists into their downloaded-map list. */
void StartMapRecordExchange(void *panel) {
    M2C_UNK CreateLinkBlockSender(s32, s32, void *);
    M2C_UNK CreateLinkBlockReceiver(s32, s32, void *);
    u8 IsLinkSessionHost();
    if (IsLinkSessionHost() != 0) {
        CreateLinkBlockSender(M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_RECORDS), MAP_RECORD_LIST_SIZE, panel);
        return;
    }
    CreateLinkBlockReceiver(M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_CHOSEN), MAP_RECORD_LIST_SIZE, panel);
}

/* Second half of the transfer panel's map-record exchange: the session host
 * receives the other players' five-map record list into its downloaded-map list,
 * while a guest sends its own list to the host. */
void CompleteMapRecordExchange(void *panel) {
    if (IsLinkSessionHost() != 0) {
        CreateLinkBlockReceiver(M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_CHOSEN), MAP_RECORD_LIST_SIZE, panel);
        return;
    }
    CreateLinkBlockSender(M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_RECORDS), MAP_RECORD_LIST_SIZE, panel);
}

void func_ov006_02217160(void) {

}

/* The map-transfer panel that is up: the sprite of
 * gMapTransferPanelStateClass, or NULL when the transfer screen has none. */
void *GetMapTransferPanelState(void) {
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gMapTransferPanelStateClass;
    return FindObjectByClass(&gMapTransferPanelStateClass);
}

/* Creates the map-transfer panel at transfer step 1: records the local player
 * and the ready-player mask, and links each ready player's page of campaign map
 * headers. */
void CreateMapTransferPanelStep1(M2C_UNK owner) {
s8 GetLocalPlayerIdForOverlay(); u8 GetSessionPlayerMask(); s32 GetCampaignMapHeader(M2C_UNK);
void *CreateSpriteObject(void *,M2C_UNK);
extern M2C_UNK gMapTransferPanelVtable,gMapTransferPanelStateClass;
u8 i; void *panel=CreateSpriteObject(&gMapTransferPanelStateClass,owner);
if(panel) {
M2C_FIELD(panel,void **,0)=&gMapTransferPanelVtable;
M2C_FIELD(panel,u8 *,MAP_TRANSFER_PANEL_STEP)=1;
M2C_FIELD(panel,s32 *,MAP_TRANSFER_PANEL_RECORDS)=0;M2C_FIELD(panel,s32 *,MAP_TRANSFER_PANEL_CHOSEN)=0;
M2C_FIELD(panel,s8 *,MAP_TRANSFER_PANEL_LOCAL)=GetLocalPlayerIdForOverlay();
M2C_FIELD(panel,u8 *,MAP_TRANSFER_PANEL_READY)=GetSessionPlayerMask();
M2C_FIELD(panel,s32 *,MAP_TRANSFER_PANEL_PAGE0)=GetCampaignMapHeader(0);
i=0;
do {
if(M2C_FIELD(panel,u8 *,MAP_TRANSFER_PANEL_READY)&(1<<i))
M2C_FIELD(panel+i*4,s32 *,MAP_TRANSFER_PANEL_PAGES)=(s32)((u8 (*)[0x54])M2C_FIELD(panel,s32 *,MAP_TRANSFER_PANEL_PAGE0)+i*CAMPAIGN_PAGE_HEADERS);
i++;
}while(i<4);
}
}

/* Create the map-transfer panel of the link map-confirm screen at transfer step 2,
 * attached to `owner`: it points at the campaign map header pages of the players
 * that are ready, and starts without any received-record buffer chosen yet. */
void CreateMapTransferPanelStep2(M2C_UNK owner) {
    s8 GetLocalPlayerIdForOverlay();
    u8 GetSessionPlayerMask();
    s32 GetCampaignMapHeader(M2C_UNK);
    void *CreateSpriteObject(void *, M2C_UNK);
    extern M2C_UNK data_ov006_0221890c, data_ov006_02218918;
    u8 i;
    void *panel = CreateSpriteObject(&data_ov006_02218918, owner);

    if (panel) {
        M2C_FIELD(panel, void **, 0) = &data_ov006_0221890c;
        M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_STEP) = 2;
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_RECORDS) = 0;
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_CHOSEN) = 0;
        M2C_FIELD(panel, s8 *, MAP_TRANSFER_PANEL_LOCAL) = GetLocalPlayerIdForOverlay();
        M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_READY) = GetSessionPlayerMask();
        M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0) = GetCampaignMapHeader(0);
        i = 0;
        do {
            if (M2C_FIELD(panel, u8 *, MAP_TRANSFER_PANEL_READY) & (1 << i))
                M2C_FIELD(panel + i * 4, s32 *, MAP_TRANSFER_PANEL_PAGES) = (s32)((u8 (*)[0x54]) M2C_FIELD(panel, s32 *, MAP_TRANSFER_PANEL_PAGE0) + i * CAMPAIGN_PAGE_HEADERS);
            i++;
        } while (i < 4);
    }
}

