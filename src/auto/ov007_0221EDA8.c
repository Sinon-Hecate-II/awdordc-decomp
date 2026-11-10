/* 10 functions from 0x0221EDA8 to 0x0221F500 (ov007), found by ds-decomp. */
#include "common.h"
#include "mapedit.h"
typedef struct { u8 active:1; u8 mode:4; u8 kind:3; } Ov006C24Flags;
static inline void *InitOv007Text(void *child) {
 s32 func_020e34bc(M2C_UNK); M2C_UNK MI_CpuFill8(s32,M2C_UNK,M2C_UNK);
    if (child != NULL) {
        M2C_FIELD(child, s16 *, 0x10) = 0x11;
        M2C_FIELD(child, s8 *, 0x12) = 0;
        M2C_FIELD(child, s32 *, 0) = 0;
        M2C_FIELD(child, s32 *, 4) = 0;
        M2C_FIELD(child, s8 *, 8) = -1;
        M2C_FIELD(child, s8 *, 9) = -1;
        M2C_FIELD(child, s8 *, 0xA) = -1;
        M2C_FIELD(child, s8 *, 0xB) = -1;
        M2C_FIELD(child, u8 *, 0xD) = 0xFF;
        M2C_FIELD(child, s8 *, 0xC) = -1;
        M2C_FIELD(child, s8 *, 0xE) = 0;
        M2C_FIELD(child, u8 *, 0xF) = 0xFF;
        M2C_FIELD(child, s32 *, 0x14) = func_020e34bc(0xCC);
        MI_CpuFill8(M2C_FIELD(child, void **, 0x14), 0, 0xCC);
    }

return child;
}


#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Input handler of the map editor's entry list: handles the softkey buttons (delete the
   selected entry, cycle the softkey language), moves the cursor through the list and scrolls
   the list towards the selected entry. */
void MapEditListInput(void *arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK func_02088044(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020b1c60(M2C_UNK);
    s32 func_020e32e8(M2C_UNK *);
    extern void *gKeyState;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gMapEditPath;
    extern M2C_UNK gSoftKeyLayouts;
    extern M2C_UNK gSoftKeyNarcName;
    extern M2C_UNK gSoftKeyEuFileName;
    extern M2C_UNK gSoftKeyUsFileName;
    extern M2C_UNK gSoftKeyJpFileName;
    extern u8 *gMapEditRecords;
    extern M2C_UNK gMapEditObjectList;
    s16 scrollPos;
    s16 targetScroll;
    s32 scrollDiff;
    s32 scrollDiff2;
    s32 layoutIndex;
    s32 currentLayout;
    void *savedEngine;
    s32 labelIndex;
    s8 deleteIndex;
    s8 moveUpIndex;
    s8 moveDownIndex;
    s8 labelIndex8;
    s32 selectedIndex;
    s32 shiftIndex;
    u16 keyPressed;
    u16 keyRepeat;
    register s32 mode;

    func_02088044(M2C_FIELD(arg0, void **, 0x38));
    selectedIndex = M2C_FIELD(arg0, s8 *, 0x3C);
    keyPressed = M2C_FIELD(gKeyState, u16 *, 0);
    keyRepeat = M2C_FIELD(gKeyState, u16 *, 2);
    if (keyPressed & 2) {
        func_020b1c60(0x69);
        return;
    }
    if (keyPressed & 8) {
        func_020b1c60(0x6A);
        return;
    }
    if (keyPressed & 0x400) {
        /* delete the selected entry: the list shifts up and the cursor moves with it */
        if (selectedIndex > 0) {
            deleteIndex = selectedIndex - 1;
            if (((s32) deleteIndex >= 0) && ((s32) deleteIndex < 0x11) && ((((s32) deleteIndex < 0x11) && (*(s32 *)((u8 *)&gMapEditObjectList + (deleteIndex * 4)) != 0)) || (((s32) deleteIndex > 0) && (*(s32 *)((u8 *)&gMapEditObjectList + ((deleteIndex - 1) * 4)) != 0)))) {
                M2C_FIELD(arg0, s8 *, 0x3C) = deleteIndex;
            }
            shiftIndex = M2C_FIELD(arg0, s8 *, 0x3C);
            if ((s32) shiftIndex < 0x10) {
                do {
                    *(s32 *)((u8 *)&gMapEditObjectList + (shiftIndex * 4)) = M2C_FIELD(((u8 *)&gMapEditObjectList + (shiftIndex * 4)), s32 *, 4);
                    shiftIndex += 1;
                } while ((s32) shiftIndex < 0x10);
            }
            M2C_FIELD(&gMapEditRecords, s32 *, 0x44) = 0;   /* the terminator of the object list */
            PlaySoundEffect(0x1000D);
            return;
        }
        if ((selectedIndex == 0) && (*(s32 *)((u8 *)&gMapEditObjectList + (selectedIndex * 4)) != 0)) {
            if ((s32) selectedIndex < 0x10) {
                do {
                    *(s32 *)((u8 *)&gMapEditObjectList + (selectedIndex * 4)) = M2C_FIELD(((u8 *)&gMapEditObjectList + (selectedIndex * 4)), s32 *, 4);
                    selectedIndex += 1;
                } while ((s32) selectedIndex < 0x10);
            }
            M2C_FIELD(&gMapEditRecords, s32 *, 0x44) = 0;   /* the terminator of the object list */
            PlaySoundEffect(0x1000D);
            return;
        }
        PlaySoundEffect(0x1001D);   /* nothing left to delete */
        return;
    }
    if (keyPressed & 0x800) {
        /* cycle the softkey language: US -> EU -> JP -> US */
        currentLayout = M2C_FIELD(arg0, s32 *, 0x34);
        layoutIndex = 0;
loop_25:
        if (currentLayout == *(s32 *)((u8 *)&gSoftKeyLayouts + (layoutIndex * 4))) {
            mode = layoutIndex + SOFTKEY_MODE_US;
        } else {
            layoutIndex += 1;
            if (layoutIndex >= 3) {
                mode = SOFTKEY_MODE_US;
            } else {
                goto loop_25;
            }
        }
        switch (mode) {                           /* switch 1; irregular */
        case SOFTKEY_MODE_JP:                     /* switch 1 */
            mode = SOFTKEY_MODE_US;
            break;
        case SOFTKEY_MODE_US:                     /* switch 1 */
            mode = SOFTKEY_MODE_EU;
            break;
        case SOFTKEY_MODE_EU:                     /* switch 1 */
            mode = SOFTKEY_MODE_JP;
            break;
        }
        if ((mode >= SOFTKEY_MODE_US) && (mode < SOFTKEY_MODE_JP + 1)) {
            M2C_FIELD(arg0, s32 *, 0x34) = (s32) *(s32 *)((u8 *)&gSoftKeyLayouts + ((mode - SOFTKEY_MODE_US) * 4));
        }
        if (currentLayout == M2C_FIELD(arg0, s32 *, 0x34)) {
            return;
        }
        SetFileDirectory(&gMapEditPath);
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        func_020e32e8(&gSoftKeyNarcName);
        OpenNarcArchive();
        switch (mode) {                           /* switch 2; irregular */
        case SOFTKEY_MODE_JP:                     /* switch 2 */
            LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyJpFileName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        case SOFTKEY_MODE_US:                     /* switch 2 */
            LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyUsFileName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        case SOFTKEY_MODE_EU:                     /* switch 2 */
            LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyEuFileName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
            break;
        }
        CloseNarcArchive();
        func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 0x18, 5);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        gCur3DSpriteEngine = savedEngine;
        PlaySoundEffect(0x10011);
        return;
    }
    if (keyRepeat & 0x200) {
        moveUpIndex = selectedIndex - 1;
        if (((s32) moveUpIndex >= 0) && ((s32) moveUpIndex < 0x11) && ((((s32) moveUpIndex < 0x11) && (*(s32 *)((u8 *)&gMapEditObjectList + (moveUpIndex * 4)) != 0)) || (((s32) moveUpIndex > 0) && (*(s32 *)((u8 *)&gMapEditObjectList + ((moveUpIndex - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = moveUpIndex;
        }
    } else if (keyRepeat & 0x100) {
        moveDownIndex = selectedIndex + 1;
        if (((s32) moveDownIndex >= 0) && ((s32) moveDownIndex < 0x11) && ((((s32) moveDownIndex < 0x11) && (*(s32 *)((u8 *)&gMapEditObjectList + (moveDownIndex * 4)) != 0)) || (((s32) moveDownIndex > 0) && (*(s32 *)((u8 *)&gMapEditObjectList + ((moveDownIndex - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = moveDownIndex;
        }
    }
    /* the label of the selected entry may point at another entry of the list */
    labelIndex = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), s8 *, 0xC);
    if ((s32) labelIndex >= 0) {
        labelIndex8 = (s8)labelIndex;
        if (((s32) labelIndex8 >= 0) && ((s32) labelIndex8 < 0x11) && ((((s32) labelIndex8 < 0x11) && (*(s32 *)((u8 *)&gMapEditObjectList + (labelIndex8 * 4)) != 0)) || (((s32) labelIndex8 > 0) && (*(s32 *)((u8 *)&gMapEditObjectList + ((labelIndex8 - 1) * 4)) != 0)))) {
            M2C_FIELD(arg0, s8 *, 0x3C) = labelIndex8;
        }
    }
    /* scroll the list towards the selected entry (8 pixels per entry) */
    scrollPos = M2C_FIELD(arg0, s16 *, 0x3E);
    targetScroll = (M2C_FIELD(arg0, s8 *, 0x3C) * 8) + 0x10;
    if ((scrollPos == -0x8000) && (M2C_FIELD(arg0, s16 *, 0x40) == -0x8000)) {
        goto block_81;
    }
    scrollDiff = scrollPos - targetScroll;
    if (scrollDiff < 0) {
        scrollDiff = 0 - scrollDiff;
    }
    if (scrollDiff <= 1) {
        scrollDiff2 = M2C_FIELD(arg0, s16 *, 0x40) - 0x10;
        if (scrollDiff2 < 0) {
            scrollDiff2 = 0 - scrollDiff2;
        }
        if (scrollDiff2 <= 1) {
block_81:
            M2C_FIELD(arg0, s16 *, 0x3E) = targetScroll;
            M2C_FIELD(arg0, s16 *, 0x40) = 0x10;
        } else {
            goto block_82;
        }
    } else {
block_82:
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) ((s32) (targetScroll + scrollPos + 1) >> 1);
        M2C_FIELD(arg0, s16 *, 0x40) = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x40) + 0x11) >> 1);
    }
    if (selectedIndex == M2C_FIELD(arg0, s8 *, 0x3C)) {
        return;
    }
    PlaySoundEffect(0x10019);
}
#pragma pop
void func_ov007_0221f220(void) {
    M2C_UNK func_ov007_0221ec40();
    func_ov007_0221ec40();
}

void func_ov007_0221f22c(void) {
    M2C_UNK func_ov007_0221e878();
    func_ov007_0221e878();
}

void func_ov007_0221f238(void) {
    M2C_UNK func_ov007_0221e6d0();
    func_ov007_0221e6d0();
}

void func_ov007_0221f244(void) {
    M2C_UNK func_ov007_0221e85c();
    func_ov007_0221e85c();
}

void func_ov007_0221f250(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov007_0221f264(void) {
    M2C_UNK func_ov007_0221ec34();
    func_ov007_0221ec34();
}

/* Create the map editor's name-entry list: build its list widget of the current
 * region's softkey layout, copy up to 16 glyphs of the name into the shared
 * glyph list and create the label and panel children. */
void CreateMapEditList(u8 *name) {
    void *CreateSpriteObject(M2C_UNK *);
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(u8 *, M2C_UNK *, M2C_UNK);
    void *MemAlloc(M2C_UNK);
    s32 func_02099ae8(u8 *);
    s32 func_02099b00(u8 *);
    s32 GetLanguage();
    s32 func_020e34bc(M2C_UNK);
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK gMapEditListTemplate;
    extern M2C_UNK gSoftKeyLayoutUs;
    extern M2C_UNK gSoftKeyLayoutJp;
    extern M2C_UNK gMapEditListVTable;
    extern u8 *gMapEditRecords;
    extern M2C_UNK gMapEditObjectList;
    M2C_UNK *layout;
    u32 i;
    M2C_UNK *dst;
    u8 *p;
    void *widget;
    void *label;
    void *panel;

    p = name;
    widget = CreateSpriteObject(&gMapEditListTemplate);
    if (widget == NULL) {
        return;
    }
    M2C_FIELD(widget, M2C_UNK **, 0) = &gMapEditListVTable;
    if (GetLanguage() == 0) {
        layout = &gSoftKeyLayoutJp;
    } else {
        layout = &gSoftKeyLayoutUs;
    }
    M2C_FIELD(widget, M2C_UNK **, 0x34) = layout;
    M2C_FIELD(widget, void **, 0x38) = NULL;
    M2C_FIELD(widget, s8 *, 0x3C) = 0;
    M2C_FIELD(widget, s16 *, 0x3E) = -0x8000;
    M2C_FIELD(widget, s16 *, 0x40) = -0x8000;
    M2C_FIELD(widget, void **, 0x44) = NULL;
    gMapEditRecords = p;
    func_02007e98(0, &gMapEditObjectList, 0x44);
    dst = &gMapEditObjectList;
    i = 0;
    while ((*p != 0) && (i < 0x10U)) {
        if ((func_02099ae8(p) != 0) || (func_02099b00(p) != 0)) {
            MI_CpuCopy8(p, dst, 2);
            p += 2;
        } else {
            MI_CpuCopy8(p, dst, 1);
            p += 1;
        }
        i += 1;
        dst = (M2C_UNK *)((u8 *)dst + 4);

    }
    label = InitOv007Text(MemAlloc(0x24));
    M2C_FIELD(widget, void **, 0x38) = label;
    panel = MemAlloc(0x2C);
    if (panel != NULL) {
        M2C_FIELD(panel, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(panel, s8 *, 4) = 0;
        M2C_FIELD(panel, s16 *, 0x12) = 0;
        M2C_FIELD(panel, s8 *, 0x14) = 8;
        M2C_FIELD(panel, s8 *, 0x15) = 8;
        M2C_FIELD(panel, s8 *, 0x16) = 1;
        M2C_FIELD(panel, s8 *, 0x17) = 8;
        M2C_FIELD(panel, s8 *, 0x18) = 8;
        M2C_FIELD(panel, Ov006C24Flags *, 0x20).active = 0;
        M2C_FIELD(panel, Ov006C24Flags *, 0x20).mode = 0;
        M2C_FIELD(panel, Ov006C24Flags *, 0x20).kind = 2;
        M2C_FIELD(panel, s8 *, 0x21) = 0;
        M2C_FIELD(panel, s32 *, 0x24) = 0;
        M2C_FIELD(panel, u8 *, 0x28) = (u8) (M2C_FIELD(panel, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(panel, s8 *, 0x29) = 0;
    }
    M2C_FIELD(widget, void **, 0x44) = panel;
}

void *func_ov007_0221f458(void *arg0) {
    M2C_UNK MemFree(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK gMapEditListVTable;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &gMapEditListVTable;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        MemFree(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    MemFree(arg0);
    return arg0;
}

void *func_ov007_0221f4b0(void *arg0) {
    M2C_UNK MemFree(void *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK gMapEditListVTable;
    void *temp_r4;
    void *temp_r0;

    M2C_FIELD(arg0, void **, 0) = &gMapEditListVTable;
    temp_r4 = M2C_FIELD(arg0, void **, 0x38);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        MemFree(temp_r4);
    }
    temp_r0 = M2C_FIELD(arg0, void **, 0x44);
    if (temp_r0 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), void (**)(void *), 4)(temp_r0);
    }
    
    return arg0;
}

