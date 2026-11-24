/* 8 functions from 0x02217C80 to 0x02218AD0 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov007_map_editor.h"
typedef struct MenuPosition { s8 kind; u8 x, y, unk3, unk4; } MenuPosition;
typedef struct MenuList007 { s32 first, second; s8 a,b,c,d,e; u8 alpha, flag, alpha2; u16 count; u8 flag2, pad; void *buffer; u8 rest[12]; } MenuList007;
#pragma push
#pragma opt_propagation on
static inline MenuList007 *InitMenuList007(MenuList007 *p, s32 count) {
 void *HeapAllocBlock(s32); void MI_CpuFill8(void *,s32,s32);
 s32 size=count*12;
 p->count=count;p->flag2=0;p->first=0;p->second=0;
 p->a=-1;p->b=-1;p->c=-1;p->d=-1;p->alpha=255;p->e=-1;p->flag=0;p->alpha2=255;
 p->buffer=HeapAllocBlock(size);MI_CpuFill8(p->buffer,0,size);
 return p;
}
#pragma pop


s32 func_ov007_02217c80(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) + 1;
    if (result >= func_ov007_02217c50(arg0)) result = 0;
    return result;
}

s32 func_ov007_02217ca8(void *arg0) {
    s32 func_ov007_02217c50(void *);
    s32 result = M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x37), u8 *, 0x38) - 1;
    if (result < 0) result = func_ov007_02217c50(arg0) - 1;
    return result;
}

/* Confirm the palette entry the panel cursor points at: arm it so closing the
 * panel applies it and play the confirm animation.  A neutral-owned headquarters
 * entry cannot be picked, so confirming it does nothing. */
void MapEditor_ConfirmPaletteEntry(void *editor) {
    s8 *MapEditor_GetPaletteEntries(u8);
    void SetSpriteAnimation(void *, s32);
    u8 entry;
    s8 *entries;
    u8 page;
    entry = M2C_FIELD(editor + M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE), u8 *, MAP_EDITOR_PANEL_ENTRY);
    entries = MapEditor_GetPaletteEntries(M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE));
    page = M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE);
    switch (page) {
    case 0:
        if (entries[entry * MAP_EDITOR_PALETTE_ENTRY_SIZE] == MAP_TERRAIN_HQ && M2C_FIELD(editor + page, u8 *, MAP_EDITOR_PANEL_OWNER) == MAP_EDITOR_OWNER_NEUTRAL) return;
        break;
    case 1:
        break;
    }
    M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PENDING) = 1;
    SetSpriteAnimation(editor, 2);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_common_subs off
s32 func_ov007_02217d30(void *arg0) {
    s8 *MapEditor_GetPaletteEntries(u8);
    extern u32 *gKeyState;
    u16 *g;
    s32 idx;
    u8 *indices;
    s32 mode;
    u8 *table;
    s32 x;
    s32 y;
    s32 candidate;
    s32 flags;

    mode = M2C_FIELD(arg0, u8 *, 0x37);
    table = (u8 *)MapEditor_GetPaletteEntries(mode);
    mode=M2C_FIELD(arg0,u8 *,0x37);
    indices = (u8 *)arg0 + 0x3A;
    g = (u16 *)gKeyState;
    idx = indices[mode];
    flags=g[1];
    candidate=idx;
    x = ((MenuPosition *)table)[idx].x;
    y = ((MenuPosition *)table)[idx].y;


    if (flags & 0xF0) {
        u8 *ptr = table;
        s32 i = 0;
        if ((s8)*ptr >= 0) {
        s32 xm1 = x-1;
        s32 xp1 = x+1;
        s32 m40 = flags & 0x40;
        s32 m80 = flags & 0x80;
        s32 m20 = flags & 0x20;
        s32 m10 = flags & 0x10;
        s32 ym1 = y - 1;
        s32 yp1 = y + 1;
            do {
                if (m40 && ptr[1] == x && ptr[2] == ym1) candidate = i;
                if (m80 && ptr[1] == x && ptr[2] == yp1) candidate = i;
                if (m20 && ptr[2] == y && ptr[1] == xm1) candidate = i;
                if (m10 && ptr[2] == y && ptr[1] == xp1) candidate = i;
                i++;
                ptr += 5;
            } while ((s8)*ptr >= 0);
        }
    }

    {
        u16 flags2 = g[0];
        if ((flags2 & 0xF0) && candidate == idx) {
            u8 *ptr = table;
            s32 i = 0;
            if ((s8)*ptr >= 0) {
            s32 m40 = flags2 & 0x40;
            s32 m80 = flags2 & 0x80;
            s32 m20 = flags2 & 0x20;
            s32 m10 = flags2 & 0x10;

                do {
                    if (m40 && ptr[1] == x) {
                        u8 cb2 = table[candidate * 5 + 2];
                        if (ptr[2] > cb2) candidate = i;
                    }
                    if (m80 && ptr[1] == x) {
                        u8 cb2 = table[candidate * 5 + 2];
                        if (ptr[2] < cb2) candidate = i;
                    }
                    if (m20 && ptr[2] == y) {
                        u8 cb1 = table[candidate * 5 + 1];
                        if (ptr[1] > cb1) candidate = i;
                    }
                    if (m10 && ptr[2] == y) {
                        u8 cb1 = table[candidate * 5 + 1];
                        if (ptr[1] < cb1) candidate = i;
                    }
                    i++;
                    ptr += 5;
                } while ((s8)*ptr >= 0);
            }
            candidate = candidate;
        }
    }

    if (candidate == idx) return 0;
    indices[mode] = candidate;
    return 1;
}
#pragma opt_propagation off
#pragma scheduling off
#pragma opt_strength_reduction off
void func_ov007_02217f8c(void *arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadDecompressedFileTo(s32, s32);
    M2C_UNK LoadFileToSpriteBuffer(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK Hide3DSprite(void *);
    M2C_UNK Set3DSpriteSlideTargetAndStart(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02089424();
    void *CreateFrameBorderSprite(void *);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK InitUnitSprite(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    M2C_UNK CreateUnitSpriteButtonTask(void *, M2C_UNK);
    void *func_020ab1c4(void *);
    s32 GetLocalizedFileName(M2C_UNK *);
    s8 GetMapEditorMode();
    s32 GetMapEditorUnitKind();
    M2C_UNK GetMapEditorUnitOwner();
    s32 GetMapEditorTerrainKind();
    M2C_UNK GetMapEditorTerrainOwner();
    s8 func_ov007_02217b90(M2C_UNK, s32);
    s8 func_ov007_02217c1c();
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov007_02220030;
    extern M2C_UNK data_ov007_0222003c;
    extern M2C_UNK data_ov007_0222004c;
    extern M2C_UNK data_ov007_0222005c;
    extern M2C_UNK data_ov007_0222006c;
    extern M2C_UNK data_ov007_0222007c;
    extern M2C_UNK data_ov007_02220088;
    extern M2C_UNK data_ov007_02220094;
    extern M2C_UNK data_ov007_022200a0;

    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    register void *temp_r5;
    register void *temp_r6;
    s16 temp_r7;
    s16 temp_r8;
    s32 temp_r1;
    s32 var_r0;
    s16 initialScale;
    s32 var_r2;
    s32 temp_r9;
    s32 height;
    void *temp_r0;
        void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r2_4;
    void *temp_r2_5;
    void *temp_r2_6;

    var_r2 = 0;
    initialScale = 0x100;
    do {
        temp_r0 = arg0 + (var_r2 * 2);
        var_r2 += 1;
        M2C_FIELD(temp_r0, s16 *, 0x3C) = initialScale;
    } while (var_r2 < 3);
    M2C_FIELD(arg0, s8 *, 0x34) = 1;
    M2C_FIELD(arg0, s8 *, 0x35) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = GetMapEditorMode();
    M2C_FIELD(arg0, s8 *, 0x3A) = func_ov007_02217b90(0, GetMapEditorTerrainKind());
    M2C_FIELD(arg0, s8 *, 0x3B) = func_ov007_02217b90(1, GetMapEditorUnitKind());
    GetMapEditorTerrainOwner();
    M2C_FIELD(arg0, s8 *, 0x38) = func_ov007_02217c1c();
    GetMapEditorUnitOwner();
    M2C_FIELD(arg0, s8 *, 0x39) = func_ov007_02217c1c();
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s16 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x5C) = 0;
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    LoadSpriteResource(0, 2, 0x47, M2C_FIELD(g3DSpriteEngineMain, s32 *, 0x30) + 0x260);
    M2C_FIELD(arg0, void **, 0x44) = func_020ab1c4(arg0);
    InitUnitSprite(M2C_FIELD(arg0, void **, 0x44), 0, 0x35C, 3, 0);
    temp_r6 = M2C_FIELD(arg0, void **, 0x44);
    Set3DSpriteSlideTargetAndStart(temp_r6, 0xC0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = GetUnitSpriteWidth(temp_r6);
        height = GetUnitSpriteHeight(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) height);
    }
    CreateUnitSpriteButtonTask(M2C_FIELD(arg0, void **, 0x44), 1);
    M2C_FIELD(arg0, void **, 0x48) = func_020ab1c4(arg0);
    InitUnitSprite(M2C_FIELD(arg0, void **, 0x48), 2, 0x36C, 3, 0);
    temp_r6 = M2C_FIELD(arg0, void **, 0x48);
    Set3DSpriteSlideTargetAndStart(temp_r6, 0xE0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = GetUnitSpriteWidth(temp_r6);
        height = GetUnitSpriteHeight(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) height);
    }
    CreateUnitSpriteButtonTask(M2C_FIELD(arg0, void **, 0x48), 2);
    M2C_FIELD(arg0, void **, 0x4C) = func_020ab1c4(arg0);
    InitUnitSprite(M2C_FIELD(arg0, void **, 0x4C), 0x14, 0x37C, 3, 0);
    temp_r6 = M2C_FIELD(arg0, void **, 0x4C);
    Set3DSpriteSlideTargetAndStart(temp_r6, 0xA0, 0xA0, 0x100, 0xA0);
    if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
        temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
        temp_r9 = GetUnitSpriteWidth(temp_r6);
        height = GetUnitSpriteHeight(temp_r6);
        func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) height);
    }
    CreateUnitSpriteButtonTask(M2C_FIELD(arg0, void **, 0x4C), 0x304);
    SetFileDirectory(&data_ov007_02220030);
    OpenNarcArchive(GetLocalizedFileName(&data_ov007_0222003c));
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_0222004c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x10));
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_0222005c), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&data_ov007_0222006c, 0, 0x20);
    {
        void *bank = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
        M2C_FIELD(bank, s16 *, 0x3A) = 0;
    }
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    temp_r1 = GetLocalizedFileName(&data_ov007_0222007c);
    LoadDecompressedFileTo(temp_r1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x7380);
    LoadFileToSpriteBuffer(&data_ov007_02220088, 0x200, 0x20);
    SetFileDirectory(&data_ov007_02220094);
    LoadFileToSpriteBuffer(&data_ov007_022200a0, 0x240, 0x20);
    M2C_FIELD(arg0, void **, 0x50) = CreateFrameBorderSprite(arg0);
    func_02089424();
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x50));
    temp_r2 = M2C_FIELD(arg0, void **, 0x50);
    temp_r1 = (M2C_FIELD(temp_r2, s32 *, 0x40) & ~0x1FF) | 0x10;
    M2C_FIELD(temp_r2, s32 *, 0x40) = temp_r1;
    M2C_FIELD(temp_r2, s32 *, 0x40) = (temp_r1 & 0xFFFC01FF) | 0x2000;
    M2C_FIELD(arg0, void **, 0x54) = CreateFrameBorderSprite(arg0);
    func_02089424();
    Hide3DSprite(M2C_FIELD(arg0, void **, 0x54));
    temp_r2_2 = M2C_FIELD(arg0, void **, 0x54);
    temp_r1 = (M2C_FIELD(temp_r2_2, s32 *, 0x40) & ~0x1FF) | 0x10;
    M2C_FIELD(temp_r2_2, volatile s32 *, 0x40) = temp_r1;
    M2C_FIELD(temp_r2_2, volatile s32 *, 0x40) = (s32) ((temp_r1 & 0xFFFC01FF) | 0x2000);
    temp_r0_2 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp2C = temp_r0_2 + 0x12;
    *sp2C = (u16)(*sp2C & ~1);
    temp_r0_3 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp28 = temp_r0_3 + 0x12;
    *sp28 = (u16)(*sp28 | 2);
    temp_r0_4 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp24 = temp_r0_4 + 0x12;
    *sp24 = (u16)(*sp24 & ~4);
    temp_r0_5 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp20 = temp_r0_5 + 0x12;
    *sp20 = (u16)(*sp20 & ~8);
    temp_r0_6 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp1C = temp_r0_6 + 0x12;
    *sp1C = (u16)(*sp1C & ~0x10);
    temp_r0_7 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp18 = temp_r0_7 + 0x12;
    *sp18 = (u16)(*sp18 | 0x100);
    temp_r2_3 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp14 = temp_r2_3 + 0x12;
    *sp14 = (u16)(*sp14 & ~0x200);
    temp_r2_4 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp10 = temp_r2_4 + 0x12;
    *sp10 = (u16)(*sp10 & ~0x400);
    temp_r2_5 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    spC = temp_r2_5 + 0x12;
    *spC = (u16)(*spC & ~0x800);
    temp_r2_6 = M2C_FIELD(gCur3DSpriteEngine, void **, 0);
    sp8 = temp_r2_6 + 0x12;
    *sp8 = (u16)(*sp8 & ~0x1000);
    gCur3DSpriteEngine = temp_r5;
    PlaySoundEffect(0x10017);
}
/* Apply the palette entry the cursor picked on the editor's palette page to the
 * active brush: set the terrain kind/owner (terrain page) or the unit kind/owner
 * (unit page) from that entry, reset the tool and refresh the map graphics, with
 * the confirm sound.  With no entry picked, just play the cancel sound.  Either
 * way the palette panel is closed afterwards. */
void MapEditor_ApplyPaletteSelection(void *editor) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK SetMapEditorMode(u8);
    M2C_UNK SetMapEditorTool(M2C_UNK);
    M2C_UNK SetMapEditorUnitKind();
    M2C_UNK SetMapEditorUnitOwner();
    M2C_UNK SetMapEditorTerrainKind();
    M2C_UNK SetMapEditorTerrainOwner();
    M2C_UNK MapEditor_GetPaletteKind(M2C_UNK, u8);
    M2C_UNK MapEditor_GetPaletteOwner(M2C_UNK, s32, u8);
    M2C_UNK MapEditor_RefreshGraphics();
    u8 page;
    void *pageState;
    void *pageState2;

    if (M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PENDING) != 0) {
        SetMapEditorMode(M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE));
        SetMapEditorTool(0);
        page = M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE);
        switch (page) {                             /* irregular */
        case 0:
            MapEditor_GetPaletteKind(0, M2C_FIELD((editor + page), u8 *, MAP_EDITOR_PANEL_ENTRY));
            SetMapEditorTerrainKind();
            pageState = editor + M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE);
            MapEditor_GetPaletteOwner(0, M2C_FIELD(pageState, u8 *, MAP_EDITOR_PANEL_ENTRY), M2C_FIELD(pageState, u8 *, MAP_EDITOR_PANEL_OWNER));
            SetMapEditorTerrainOwner();
            break;
        case 1:
            MapEditor_GetPaletteKind(1, M2C_FIELD((editor + page), u8 *, MAP_EDITOR_PANEL_ENTRY));
            SetMapEditorUnitKind();
            pageState2 = editor + M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE);
            MapEditor_GetPaletteOwner(1, M2C_FIELD(pageState2, u8 *, MAP_EDITOR_PANEL_ENTRY), M2C_FIELD(pageState2, u8 *, MAP_EDITOR_PANEL_OWNER));
            SetMapEditorUnitOwner();
            break;
        }
        MapEditor_RefreshGraphics();
        PlaySoundEffect(0x10016); /* palette entry applied */
    } else {
        PlaySoundEffect(0x1000F); /* SOUND_MENU_CANCEL */
    }
    M2C_FIELD(editor, s8 *, MAP_EDITOR_PANEL_CLOSE) = 1;
}

#pragma opt_propagation off
void func_ov007_0221863c(void *arg0) {
    s8 *MapEditor_GetPaletteEntries(u8);
    M2C_UNK MapEditor_GetPaletteOwner(M2C_UNK, s32, u8);
    s32 func_ov007_02217c50(void *);
    void *MemAlloc(s32);
    M2C_UNK MemFree(void *);
    M2C_UNK AddSpriteCell(M2C_UNK, s16, s16, s32, s32, s32, s32);
    void *HeapAllocBlock(s32);
    void MI_CpuFill8(void *, s32, s32);
    void MI_CpuCopy32(void *, void *, s32);
    void CopyToObjPaletteShadow(M2C_UNK, s32, M2C_UNK);
    M2C_UNK HeapFreeBlock(s32);
    s32 GetTerrainTileBase(s32);
    void *GetTerrainTileData(s32);
    void *GetTerrainPalette(s32, s32);
    s32 func_ov000_0216cd4c(s32);
    void *GetUnitIconTiles(s32, s32);
    void *GetArmyPalette(s32);
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void **gCurrentMap;

    void *r4;
    MenuList007 *node0;
    MenuList007 *node1;
    u8 mode;
    void *savedEngine;

    r4 = M2C_FIELD(arg0, void **, 0x58);
    if (r4 != NULL) {
        HeapFreeBlock(M2C_FIELD(r4, s32 *, 0x14));
        MemFree(r4);
        M2C_FIELD(arg0, void **, 0x58) = NULL;
    }
    r4 = M2C_FIELD(arg0, void **, 0x5C);
    if (r4 != NULL) {
        HeapFreeBlock(M2C_FIELD(r4, s32 *, 0x14));
        MemFree(r4);
    }
    M2C_FIELD(arg0, void **, 0x5C) = NULL;

    node0 = MemAlloc(0x24);
    if(node0) InitMenuList007(node0,64);
    M2C_FIELD(arg0, void **, 0x58) = node0;

    node1 = MemAlloc(0x24);
    if(node1) InitMenuList007(node1,func_ov007_02217c50(arg0));
    M2C_FIELD(arg0, void **, 0x5C) = node1;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;


    {
    s32 tile=0x3dc;
    s8 *table;
    s32 offset, i, selected;
    table = MapEditor_GetPaletteEntries(M2C_FIELD(arg0,u8 *,0x37));
    i=0;
    switch(M2C_FIELD(arg0,u8 *,0x37)) {
    case 0:
        if(table[0]>=0) {
        offset=0x7b80;
        do {
            s32 id=MapEditor_GetPaletteOwner(M2C_FIELD(arg0,u8 *,0x37),i,M2C_FIELD((u8 *)arg0+M2C_FIELD(arg0,u8 *,0x37),u8 *,0x38));
            s32 v0=GetTerrainTileBase(table[0]);
            void *v1=GetTerrainTileData(table[0]);
            void *v2=GetTerrainPalette(table[0],id);
            MI_CpuCopy32(v1,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+offset,0x100);
            MI_CpuCopy32((void *)v0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+(tile+8)*32,0x200);
            offset+=0x300; tile+=0x18;
            CopyToObjPaletteShadow((s32)v2,((u8)table[3]+0x16)*32,0x20);
            AddSpriteCell((s32)M2C_FIELD(arg0,void **,0x58),(s16)((u8)table[1]*36+2),(s16)((u8)table[2]*32+8),36,32,(u16)i,14);
        table+=5;i++;
        } while(table[0]>=0);
        }
        break;
    case 1: {
        s32 v0;
        void *v1;
        u8 variant;
        s32 j=i;
        if(table[0]>=0) {
        offset=0x7b80;
        do {
            i=MapEditor_GetPaletteOwner(M2C_FIELD(arg0,u8 *,0x37),j,M2C_FIELD((u8 *)arg0+M2C_FIELD(arg0,u8 *,0x37),u8 *,0x38));
            variant=M2C_FIELD((u8 *)*gCurrentMap+i*140+0x6000,u8 *,0x7cd);
            v0=func_ov000_0216cd4c(table[0]);
            v1=GetUnitIconTiles(table[0],variant);
            MI_CpuCopy32(v1,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+offset,0x80);
            MI_CpuCopy32((void *)v0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+(tile+4)*32,0x100);
            offset+=0x180; tile+=12;
            AddSpriteCell((s32)M2C_FIELD(arg0,void **,0x58),(s16)((u8)table[1]*36+2),(s16)((u8)table[2]*32+8),36,32,(u16)j,14);
        table+=5;j++;
        } while(table[0]>=0);
        }
        CopyToObjPaletteShadow((s32)GetArmyPalette(i),0x2c0,32);
        break;
    }
    }
    i=0;
    if(func_ov007_02217c50(arg0)>0) {
        offset=8;
        do {
        AddSpriteCell((s32)M2C_FIELD(arg0,void **,0x5c),(s16)offset,140,16,16,(u16)i,14);
        i++;offset+=24;
        } while(i<func_ov007_02217c50(arg0));
    }
    }
    gCur3DSpriteEngine=savedEngine;
}
#pragma opt_propagation reset
/* Free the palette panel's two list objects (each frees its heap buffer first)
 * and re-apply the map's weather effects behind the closed panel. */
void MapEditor_FreePaletteLists(void *panel) {
    M2C_UNK MemFree(void *);
    M2C_UNK ApplyWeatherEffects(u8);
    M2C_UNK HeapFreeBlock(s32);
    extern void **gCurrentMap;
    void *entryList;
    void *markerList;

    entryList = M2C_FIELD(panel, void **, MAP_EDITOR_PANEL_ENTRY_LIST);
    if (entryList != NULL) {
        HeapFreeBlock(M2C_FIELD(entryList, s32 *, 0x14));
        MemFree(entryList);
    }
    M2C_FIELD(panel, void **, MAP_EDITOR_PANEL_ENTRY_LIST) = NULL;
    markerList = M2C_FIELD(panel, void **, MAP_EDITOR_PANEL_MARKER_LIST);
    if (markerList != NULL) {
        HeapFreeBlock(M2C_FIELD(markerList, s32 *, 0x14));
        MemFree(markerList);
    }
    M2C_FIELD(panel, void **, MAP_EDITOR_PANEL_MARKER_LIST) = NULL;
    ApplyWeatherEffects(M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER));
}
