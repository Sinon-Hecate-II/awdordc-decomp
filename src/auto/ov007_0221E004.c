/* 9 functions from 0x0221E004 to 0x0221EDA8 (ov007), found by ds-decomp. */
#include "common.h"
#include "mapedit.h"
#include "ds3dsprite.h"
extern M2C_UNK gMapEditObjectList;
int Mb_StringCompare(const void *, const void *);
static inline void SetTextIndex(void *p, s8 n) {
    if (n < 0 || n >= 17) return;
    if (n < 17 && ((u32 *)&gMapEditObjectList)[n] != 0) goto valid;
    if (n <= 0) return;
    if (((u32 *)&gMapEditObjectList)[n-1] == 0) return;
valid: M2C_FIELD(p,s8 *,0x3c) = n;
}
static inline int FindTextIndex(void *p) {
    s32 result; u32 *needle; s32 i; u32 *table;
    if (M2C_FIELD(p,s8 *,0x3c) == 0) return -1;
    table=M2C_FIELD(p,u32 **,0x34);
    needle=(u32 *)&gMapEditObjectList + (M2C_FIELD(p,s8 *,0x3c)-1);
    result=-1;
    for(i=0;i<75;i++) if(Mb_StringCompare(needle,(void *)table[i])==0){result=i;break;}
    return result;
}

void func_ov007_0221e004(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

/* Types one glyph into the map editor's text line. A combining voiced or
 * semi-voiced mark rewrites the previous character to its combined form; a
 * full line or a line wider than 64 pixels is rejected with an error dialog,
 * otherwise the glyph is appended and the cursor advanced. */
M2C_UNK MapEditorTypeCharacter(void *arg0) {
extern u32 gGlyphDakuten, gGlyphHandakuten;
extern u16 **gCur3DSpriteEngine, **g3DSpriteEngineMain;
void MI_CpuCopy32(const void*,void*,u32);
void Mb_StringCopy(void*,u32);
int IsLeadByte(void*); int MeasureStringWidth(s32*);
void func_020b269c(void);
void *CreateTextLayer(void*);
void RenderTextLayerMessage(void*,s32,s32,u32);
void GotoSpriteAnimationLabel(void*,s32);
M2C_UNK PlaySoundEffect(s32);
void *editor; s32 oldIndex; u32 glyph,line[17],*glyphPtr; s32 found; u32 width; void *savedEngine,*dialog;
editor=M2C_FIELD(arg0,void **,0x10);
glyph=M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)[M2C_FIELD(arg0,u8 *,0)];
oldIndex=M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX);
if(Mb_StringCompare((void*)glyph,&gGlyphDakuten)==0){
found=FindTextIndex(editor);
if(found>=0){
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)-1);
if(Mb_StringCompare((u32*)&gMapEditObjectList+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),(void*)M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_DAKUTEN_VARIANTS))==0){SetTextIndex(editor,oldIndex);return PlaySoundEffect(0x1001d);}
glyph=M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_DAKUTEN_VARIANTS);
}else{return PlaySoundEffect(0x1001d);}
}else if(Mb_StringCompare((void*)glyph,&gGlyphHandakuten)==0){
found=FindTextIndex(editor);
if(found>=0){
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)-1);
if(Mb_StringCompare((u32*)&gMapEditObjectList+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),(void*)M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_HANDAKUTEN_VARIANTS))==0){SetTextIndex(editor,oldIndex);return PlaySoundEffect(0x1001d);}
glyph=M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_HANDAKUTEN_VARIANTS);
}else{return PlaySoundEffect(0x1001d);}
}
if(M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)>=16){
SetTextIndex(editor,oldIndex);func_020b269c();
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
dialog=CreateTextLayer(editor);RenderTextLayerMessage(dialog,2,0x2800,0x46000012);
M2C_FIELD(dialog,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=savedEngine;GotoSpriteAnimationLabel(editor,5);return PlaySoundEffect(0x1001d);
}
MI_CpuCopy32(&gMapEditObjectList,line,0x44);
line[M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)]=0;
Mb_StringCopy(line+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),glyph);
width=0;glyphPtr=line;
if(*glyphPtr){do{if(!IsLeadByte(glyphPtr)&&width)width++;width+=MeasureStringWidth((s32*)glyphPtr);glyphPtr++;}while(*glyphPtr);}
if(width>64){
SetTextIndex(editor,oldIndex);func_020b269c();
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
dialog=CreateTextLayer(editor);RenderTextLayerMessage(dialog,2,0x2800,0x46000013);
M2C_FIELD(dialog,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=savedEngine;GotoSpriteAnimationLabel(editor,5);return PlaySoundEffect(0x1001d);
}
MI_CpuCopy32(line,&gMapEditObjectList,0x44);
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)+1);
return PlaySoundEffect(0x1000d);
}

void func_ov007_0221e568(u8 *arg0) {
    s32 Divide(s32, s32);
    s32 Modulo(s32, s32);
    M2C_UNK FocusSpriteSlotById(u8);
    extern u16 *gKeyState;
    M2C_UNK MapEditorTypeCharacter(void *arg0);
    extern u8 data_ov007_0221f5a4[];
    u16 temp_r5;
    u16 temp_r6;
    u8 var_r7;

    var_r7 = *arg0;
    temp_r5 = gKeyState[0];
    temp_r6 = gKeyState[1];
    if (temp_r5 & 1) {
        MapEditorTypeCharacter(arg0);
        return;
    }
    if (temp_r6 & 0x40) {
        if (Divide(var_r7, 0xF) == 0) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[Modulo(var_r7, 0xF)];
            }
        } else {
            var_r7 -= 0xF;
        }
        if (0x4BU > var_r7) {
            goto block_15;
        }
    } else if (temp_r6 & 0x80) {
        if (Divide(var_r7, 0xF) == 4) {
            if (temp_r6 == temp_r5) {
                var_r7 = data_ov007_0221f5a4[Modulo(var_r7, 0xF)];
            }
        } else {
            var_r7 += 0xF;
        }
        if ((u32) var_r7 < 0x4BU) {
            goto block_15;
        }
    } else {
block_15:
        if (temp_r6 & 0x20) {
            if (Modulo(var_r7, 0xF) == 0) {
                if (temp_r6 == temp_r5) {
                    var_r7 += 0xE;
                }
            } else {
                var_r7 -= 1;
            }
        } else if (temp_r6 & 0x10) {
            if (Modulo(var_r7, 0xF) == 0xE) {
                if (temp_r6 == (int) temp_r5) {
                    var_r7 -= 0xE;
                }
            } else {
                ++var_r7;
            }
        }
    }
    if (*arg0 == var_r7) {
        return;
    }
    FocusSpriteSlotById(var_r7);
}

void func_ov007_0221e6bc(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

/* Creates the sprite slots of the map editor's glyph keyboard: a 15x5 grid of
 * glyph keys (ids 0..74) followed by three groups of wider key cells (ids
 * 100..106), each tagged with the editor object.  Finally draws the 17-cell
 * text line that sits above the keyboard. */
void MapEditorInitGlyphKeyboard(void *editor) {
    extern u16 **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    extern EditorCellDesc gMapEditorGlyphGridCells[], gMapEditorButtonCells1[], gMapEditorButtonCells2[], gMapEditorButtonCells3[];
    void *AddSpriteSlot(s32, s32, void *, s32);
    void SelectSpriteSlot(s32);
    void func_020b2158(s32);
    void AddSpriteCell(s32, s16, s16, s32, s32, u16, s32);
    void *saved = gCur3DSpriteEngine;
    EditorCellDesc *desc;
    s32 row, col, id, a, b, c;
    u8 i;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    row = 0;
    id = 0;
    desc = gMapEditorGlyphGridCells;
    do {
        col = 0;
        do {
            void *p = AddSpriteSlot(col * desc->width, row * desc->height, desc, id);
            col++;
            M2C_FIELD(p, void **, 0x10) = editor;
            id++;
        } while (col < 15);
        row++;
    } while (row < 5);
    a = 0;
    desc = gMapEditorButtonCells1;
    do {
        void *p = AddSpriteSlot(a * desc->width, 0, desc, a + 100);
        a++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (a < 3);
    b = 0;
    desc = gMapEditorButtonCells2;
    do {
        void *p = AddSpriteSlot(b * desc->width, 0, desc, b + 103);
        b++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (b < 2);
    c = 0;
    desc = gMapEditorButtonCells3;
    do {
        void *p = AddSpriteSlot(c * desc->width, 0, desc, c + 105);
        c++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (c < 2);
    gCur3DSpriteEngine = saved;
    SelectSpriteSlot(0);
    func_020b2158(0);
    for (i = 0; i < 17; i++)
        AddSpriteCell(M2C_FIELD(editor, s32 *, 0x38), (s16)(i * 8 + 16), 16, 8, 16, i, 14);
}

void func_ov007_0221e85c(void *arg0) {
    M2C_UNK SpriteCellListClear(s32);
    M2C_UNK func_020b2140();
    M2C_UNK HideAllSpriteSlots();
    HideAllSpriteSlots();
    SpriteCellListClear(M2C_FIELD(arg0, s32 *, 0x38));
    func_020b2140();
}

/* Set up the map editor's entry-list screen: style the panel's text sprite, put
 * the 3D sprite engine on the shared screen layout, load the softkey CG, the
 * softkey_<region>.sc graphics named by the list's layout (looked up in
 * gSoftKeyLayouts), the softkey palette and tiles, the wallpaper, panel palettes
 * and the glyph pattern, then restore the engine that was current on entry. */
void MapEditorInitScreen(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK Clear3DSpriteLayerVram(M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK Apply3DSpriteLayout(M2C_UNK *);
    M2C_UNK Load3DSpritePattern(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK GetUiColor(M2C_UNK);
    M2C_UNK CreateMainWallpaperSprite(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GetLocalizedFileNameDefault(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    extern M2C_UNK gSoftKeyLayouts;
    extern M2C_UNK gMapEditScreenLayout;
    extern M2C_UNK gMapEditScreenPath;
    extern M2C_UNK gMapEditSoftKeyCgName;
    extern M2C_UNK gMapEditSoftKeyNarcName;
    extern M2C_UNK gMapEditSoftKeyJpName;
    extern M2C_UNK gMapEditSoftKeyUsName;
    extern M2C_UNK gMapEditSoftKeyEuName;
    extern M2C_UNK gMapEditSoftKeyClName;
    u16 *volatile flagsPtr10;
    u16 *volatile flagsPtr20;
    u16 *volatile flagsPtr40;
    u16 *volatile flagsPtr80;
    u16 *volatile flagsPtr100;
    u16 *volatile flagsPtrC0;
    u16 **engine;
    s32 layoutMode;
    s32 layoutIndex;
    u16 *spriteA;
    u16 *spriteB;
    u16 *spriteC;
    u16 *spriteD;
    u16 *spriteE;
    u16 *spriteF;
    void *panelB;
    void *panelA;
    void *savedEngine;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x16) = 2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x14) = 8;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x17) = 8;
    SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x44), 0);
    panelA = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(panelA, u8 *, 0x20) = (u8) ((M2C_FIELD(panelA, u8 *, 0x20) & ~0xE0) | 0x40);
    panelB = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(panelB, u8 *, 0x28) = (u8) (M2C_FIELD(panelB, u8 *, 0x28) & ~0xE0);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s16 *, 0x12) = 0x250;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x21) = 0x16;
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Apply3DSpriteLayout(&gMapEditScreenLayout);
    spriteA = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtr10 = spriteA;
    *flagsPtr10 = *flagsPtr10 | 0x10;
    spriteB = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtr20 = spriteB;
    *flagsPtr20 = *flagsPtr20 | 0x20;
    spriteC = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtr40 = spriteC;
    *flagsPtr40 = *flagsPtr40 | 0x40;
    spriteD = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtr80 = spriteD;
    *flagsPtr80 = *flagsPtr80 | 0x80;
    spriteE = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtr100 = spriteE;
    *flagsPtr100 = *flagsPtr100 | 0x100;
    spriteF = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    flagsPtrC0 = (spriteF + 9);
    *flagsPtrC0 = (s16) (*flagsPtrC0 & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s8 *, 0x53) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, u16 **, 0), s16 *, 0x42) = 0;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(0);
    Clear3DSpriteLayer(3);
    Clear3DSpriteLayerVram(1);
    Clear3DSpriteLayerVram(0);
    Clear3DSpriteLayerVram(3);
    SetFileDirectory(&gMapEditScreenPath);
    LoadDecompressedFileTo(GetLocalizedFileNameDefault(&gMapEditSoftKeyCgName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));
    GetLocalizedFileNameDefault(&gMapEditSoftKeyNarcName);
    OpenNarcArchive();
    layoutIndex = 0;
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x34) == (&gSoftKeyLayouts)[layoutIndex]) {
        layoutMode = layoutIndex + SOFTKEY_MODE_US;
    } else {
        layoutIndex += 1;
        if (layoutIndex >= 3) {
            layoutMode = SOFTKEY_MODE_US;
        } else {
            goto loop_1;
        }
    }
    switch (layoutMode) {                               /* irregular */
    case SOFTKEY_MODE_JP:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&gMapEditSoftKeyJpName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case SOFTKEY_MODE_US:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&gMapEditSoftKeyUsName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case SOFTKEY_MODE_EU:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&gMapEditSoftKeyEuName), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    }
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&gMapEditSoftKeyClName, 0xA0, 0x60);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 0x18, 5);
    LoadScenePanelPalette(4);
    LoadScenePanelPalette(0x17);
    CreateMainWallpaperSprite(2, 0xF, 6);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    LoadSpriteResource(1, 0, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x4A00);
    engine = *(u16 **volatile *)&gCur3DSpriteEngine;
    LoadSpriteResource(1, 2, 0, M2C_FIELD(engine, s32 *, 0x30) + 0x2C0);
    Load3DSpritePattern(0x1000, 1, GetUiColor(9), 2);
    gCur3DSpriteEngine = savedEngine;
    HideAllSpriteSlots();
}

void func_ov007_0221ec34(void) {
    M2C_UNK DeleteMainWallpaperSprites();
    DeleteMainWallpaperSprites();
}

extern u16 **g3DSpriteEngineMain;
extern u16 **data_027e01d8;
extern u16 **gCur3DSpriteEngine;
/* Draw the map editor's entry list onto the main 3D sprite engine: a pulsing
 * highlight frame at the list's scroll position and then every object-name entry
 * of gMapEditObjectList as a centred tile row, eight pixels apart. */
void DrawMapEditList(MapEditList *list) {
    M2C_UNK DrawFrameBorderPulse(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    s32 RenderTextToTiles(s32, M2C_UNK *);
    M2C_UNK DrawTileRow(u16, M2C_UNK, u16, u16, s32);
    s32 MeasureStringWidth(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    extern M2C_UNK gMapEditRecords;
    extern M2C_UNK gMapEditObjectList;
    u16 **savedEngine;
    s16 rowY;
    M2C_UNK *entries;
    s32 tileOffset;
    s32 index;
    M2C_UNK *entry;
    s32 hasEntries;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    DrawFrameBorderPulse(M2C_FIELD(list, s16 *, 0x3E), M2C_FIELD(list, s16 *, 0x40), 8, 0x10, (s32) (u16) ((0x3FF & (0x80 >> ((u32) (**g3DSpriteEngineMain << 0x11) >> 0x1E))) | 0x1000), 0);
    hasEntries = M2C_FIELD(&gMapEditRecords, s32 *, 4);
    rowY = 0x10;
    entries = &gMapEditObjectList;
    tileOffset = 0x4D00;
    index = 0;
    if (hasEntries != 0) {
        entry = entries;
        do {
            s32 width = RenderTextToTiles(M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_TEXTURE) + tileOffset, entry);
            DrawTileRow((u16) (rowY + ((u32) (8 - MeasureStringWidth(entry)) >> 1)), 0x10, (u16)width, (u16) ((0x3FF & ((s32) (tileOffset >> 5) >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7000), 0);
            tileOffset = (s32) (u16) (tileOffset + (((u32) (((u32) (width + 7) >> 3) + 3) >> 2) << 8));
            index = index + 1;
            rowY = rowY + 8;
            entry = &entry[1];
        } while (entries[index] != 0);
    }
    gCur3DSpriteEngine = savedEngine;
}

