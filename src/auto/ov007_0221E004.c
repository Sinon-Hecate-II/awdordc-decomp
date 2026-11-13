/* 9 functions from 0x0221E004 to 0x0221EDA8 (ov007), found by ds-decomp. */
#include "common.h"
extern M2C_UNK gMapEditObjectList;
int func_020194e0(const void *, const void *);
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
    for(i=0;i<75;i++) if(func_020194e0(needle,(void *)table[i])==0){result=i;break;}
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
void func_02019424(void*,u32);
int IsLeadByte(void*); int MeasureStringWidth(s32*);
void func_020b269c(void);
void *func_0208b564(void*);
void func_020899cc(void*,s32,s32,u32);
void SetSpriteAnimation(void*,s32);
M2C_UNK PlaySoundEffect(s32);
void *editor; s32 oldIndex; u32 glyph,line[17],*glyphPtr; s32 found; u32 width; void *savedEngine,*dialog;
editor=M2C_FIELD(arg0,void **,0x10);
glyph=M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)[M2C_FIELD(arg0,u8 *,0)];
oldIndex=M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX);
if(func_020194e0((void*)glyph,&gGlyphDakuten)==0){
found=FindTextIndex(editor);
if(found>=0){
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)-1);
if(func_020194e0((u32*)&gMapEditObjectList+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),(void*)M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_DAKUTEN_VARIANTS))==0){SetTextIndex(editor,oldIndex);return PlaySoundEffect(0x1001d);}
glyph=M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_DAKUTEN_VARIANTS);
}else{return PlaySoundEffect(0x1001d);}
}else if(func_020194e0((void*)glyph,&gGlyphHandakuten)==0){
found=FindTextIndex(editor);
if(found>=0){
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)-1);
if(func_020194e0((u32*)&gMapEditObjectList+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),(void*)M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_HANDAKUTEN_VARIANTS))==0){SetTextIndex(editor,oldIndex);return PlaySoundEffect(0x1001d);}
glyph=M2C_FIELD(M2C_FIELD(editor,u32 **,MAPEDIT_TEXT_LAYOUT)+found,u32 *,MAPEDIT_HANDAKUTEN_VARIANTS);
}else{return PlaySoundEffect(0x1001d);}
}
if(M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)>=16){
SetTextIndex(editor,oldIndex);func_020b269c();
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
dialog=func_0208b564(editor);func_020899cc(dialog,2,0x2800,0x46000012);
M2C_FIELD(dialog,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=savedEngine;SetSpriteAnimation(editor,5);return PlaySoundEffect(0x1001d);
}
MI_CpuCopy32(&gMapEditObjectList,line,0x44);
line[M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)]=0;
func_02019424(line+M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX),glyph);
width=0;glyphPtr=line;
if(*glyphPtr){do{if(!IsLeadByte(glyphPtr)&&width)width++;width+=MeasureStringWidth((s32*)glyphPtr);glyphPtr++;}while(*glyphPtr);}
if(width>64){
SetTextIndex(editor,oldIndex);func_020b269c();
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
dialog=func_0208b564(editor);func_020899cc(dialog,2,0x2800,0x46000013);
M2C_FIELD(dialog,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=savedEngine;SetSpriteAnimation(editor,5);return PlaySoundEffect(0x1001d);
}
MI_CpuCopy32(line,&gMapEditObjectList,0x44);
SetTextIndex(editor,M2C_FIELD(editor,s8 *,MAPEDIT_TEXT_INDEX)+1);
return PlaySoundEffect(0x1000d);
}

void func_ov007_0221e568(u8 *arg0) {
    M2C_UNK Divide(u8, M2C_UNK);
    M2C_UNK Modulo(u8, M2C_UNK);
    M2C_UNK FocusSpriteSlotById(u8);
    extern u16 *gKeyState;
    M2C_UNK MapEditorTypeCharacter(void *arg0);
    extern u8 data_ov007_0221f5a4[];
    u16 temp_r5;
    u16 temp_r6;
    u8 var_r7;
    u8 *ptr;

    temp_r5 = gKeyState[0];
    temp_r6 = gKeyState[1];
    var_r7 = *arg0;
    ptr = arg0;
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
    if (*ptr == var_r7) {
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
    void *func_020b22a4(s32, s32, void *, s32);
    void func_020b1c78(s32);
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
            void *p = func_020b22a4(col * desc->width, row * desc->height, desc, id);
            col++;
            M2C_FIELD(p, void **, 0x10) = editor;
            id++;
        } while (col < 15);
        row++;
    } while (row < 5);
    a = 0;
    desc = gMapEditorButtonCells1;
    do {
        void *p = func_020b22a4(a * desc->width, 0, desc, a + 100);
        a++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (a < 3);
    b = 0;
    desc = gMapEditorButtonCells2;
    do {
        void *p = func_020b22a4(b * desc->width, 0, desc, b + 103);
        b++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (b < 2);
    c = 0;
    desc = gMapEditorButtonCells3;
    do {
        void *p = func_020b22a4(c * desc->width, 0, desc, c + 105);
        c++;
        M2C_FIELD(p, void **, 0x10) = editor;
    } while (c < 2);
    gCur3DSpriteEngine = saved;
    func_020b1c78(0);
    func_020b2158(0);
    for (i = 0; i < 17; i++)
        AddSpriteCell(M2C_FIELD(editor, s32 *, 0x38), (s16)(i * 8 + 16), 16, 8, 16, i, 14);
}

void func_ov007_0221e85c(void *arg0) {
    M2C_UNK func_02087e34(s32);
    M2C_UNK func_020b2140();
    M2C_UNK func_020b2178();
    func_020b2178();
    func_02087e34(M2C_FIELD(arg0, s32 *, 0x38));
    func_020b2140();
}

void func_ov007_0221e878(void *arg0) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_01ff9dd8(M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK func_020822b8(M2C_UNK *);
    M2C_UNK func_0208ca2c(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020ae22c(M2C_UNK);
    M2C_UNK func_020aeebc(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GetLocalizedFileNameDefault(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    extern M2C_UNK gSoftKeyLayouts;
    extern M2C_UNK data_ov007_02220d4c;
    extern M2C_UNK data_ov007_02221980;
    extern M2C_UNK data_ov007_0222198c;
    extern M2C_UNK data_ov007_02221998;
    extern M2C_UNK data_ov007_022219a8;
    extern M2C_UNK data_ov007_022219b8;
    extern M2C_UNK data_ov007_022219c8;
    extern M2C_UNK data_ov007_022219d8;
    volatile u16 *sp14;
    volatile u16 *sp10;
    volatile u16 *spC;
    volatile u16 *sp8;
    volatile u16 *sp4;
    volatile u16 *sp0;
    s32 var_r0;
    s32 var_r2;
    u16 *temp_r0;
    u16 *temp_r0_2;
    u16 *temp_r0_3;
    u16 *temp_r0_4;
    u16 *temp_r0_5;
    u16 *temp_r0_6;
    void *temp_lr;
    void *temp_r1;
    void *temp_r4;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x16) = 2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x14) = 8;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x17) = 8;
    SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x44), 0);
    temp_r1 = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_r1, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r1, u8 *, 0x20) & ~0xE0) | 0x40);
    temp_lr = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_lr, u8 *, 0x28) = (u8) (M2C_FIELD(temp_lr, u8 *, 0x28) & ~0xE0);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s16 *, 0x12) = 0x250;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), s8 *, 0x21) = 0x16;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_020822b8(&data_ov007_02220d4c);
    temp_r0 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp14 = temp_r0;
    *temp_r0 = *sp14 | 0x10;
    temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp10 = temp_r0_2;
    *temp_r0_2 = *sp10 | 0x20;
    temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    spC = temp_r0_3;
    *temp_r0_3 = *spC | 0x40;
    temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp8 = temp_r0_4;
    *temp_r0_4 = *sp8 | 0x80;
    temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp4 = temp_r0_5;
    *temp_r0_5 = *sp4 | 0x100;
    temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, u16 **, 0);
    sp0 = (volatile u16 *)(temp_r0_6 + 0x12);
    M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16) (*sp0 & ~0xC0);
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
    func_01ff9dd8(1);
    func_01ff9dd8(0);
    func_01ff9dd8(3);
    SetFileDirectory(&data_ov007_02221980);
    LoadDecompressedFileTo(GetLocalizedFileNameDefault(&data_ov007_0222198c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));
    GetLocalizedFileNameDefault(&data_ov007_02221998);
    OpenNarcArchive();
    var_r2 = 0;
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x34) == *(&gSoftKeyLayouts + (var_r2 * 4))) {
        var_r0 = var_r2 + 0x64;
    } else {
        var_r2 += 1;
        if (var_r2 >= 3) {
            var_r0 = 0x64;
        } else {
            goto loop_1;
        }
    }
    switch (var_r0) {                               /* irregular */
    case 0x66:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&data_ov007_022219a8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case 0x64:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&data_ov007_022219b8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    case 0x65:
        LoadNarcFileDecompressed(GetLocalizedFileNameDefault(&data_ov007_022219c8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
        break;
    }
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&data_ov007_022219d8, 0xA0, 0x60);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 0x18, 5);
    func_02091d4c(4);
    func_02091d4c(0x17);
    func_020aeebc(2, 0xF, 6);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_020a9a30(1, 0, 1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x4A00);
    func_020a9a30(1, 2, 0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + 0x2C0);
    func_0208ca2c(0x1000, 1, func_020ae22c(9), 2);
    gCur3DSpriteEngine = temp_r4;
    func_020b2178();
}

void func_ov007_0221ec34(void) {
    M2C_UNK DeleteMainWallpaperSprites();
    DeleteMainWallpaperSprites();
}

extern u16 **g3DSpriteEngineMain;
extern u16 **data_027e01d8;
extern u16 **gCur3DSpriteEngine;
void func_ov007_0221ec40(void *arg0) {
    M2C_UNK func_0208df84(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    u16 func_0209b5e4(s32, M2C_UNK *);
    M2C_UNK DrawTileRow(u16, M2C_UNK, u16, u16, s32);
    s32 MeasureStringWidth(M2C_UNK *);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineMain;
    extern M2C_UNK gMapEditRecords;
    extern M2C_UNK gMapEditObjectList;
    u16 **sp8;
    M2C_UNK *var_r10;
    s16 var_r6;
    s32 var_r8;
    s32 var_r9;
    u16 temp_r5;

    sp8 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_0208df84(M2C_FIELD(arg0, s16 *, 0x3E), M2C_FIELD(arg0, s16 *, 0x40), 8, 0x10, (s32) (u16) ((0x3FF & (0x80 >> ((u32) (**g3DSpriteEngineMain << 0x11) >> 0x1E))) | 0x1000), 0);
    var_r6 = 0x10;
    var_r8 = 0x4D00;
    var_r9 = 0;
    if (M2C_FIELD(&gMapEditRecords, s32 *, 4) != 0) {
        var_r10 = &gMapEditObjectList;
        do {
            temp_r5 = func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + var_r8, var_r10);
            DrawTileRow((u16) (var_r6 + ((u32) (8 - MeasureStringWidth(var_r10)) >> 1)), 0x10, temp_r5, (u16) ((0x3FF & ((s32) (var_r8 >> 5) >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x7000), 0);
            var_r8 = (s32) (u16) (var_r8 + (((u32) (((u32) (temp_r5 + 7) >> 3) + 3) >> 2) << 8));
            var_r9 = var_r9 + 1;
            var_r6 = var_r6 + 8;
            var_r10 = &var_r10[1];
        } while (*(&gMapEditObjectList + (var_r9 * 4)) != 0);
    }
    gCur3DSpriteEngine = sp8;
}

