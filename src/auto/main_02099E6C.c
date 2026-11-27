/* 3 functions from 0x02099E6C to 0x0209ACC4 (main), found by ds-decomp. */
#include "common.h"

/* Glyph text object state (the TextState the text engine uses; same layout as
 * the one in main_0209ACC4.c): the glyph cell buffer of the current line, the
 * attribute OR-ed into every cell and the line's tile/pixel offset. */
typedef struct TextState {
    u8   pad_00[0x40];
    u16 *cells;      /* +0x40 glyph cell buffer base */
    u16  baseAttr;   /* +0x44 attribute OR-ed into every cell */
    u8   pad_46[6];
    u16  linePixel;  /* +0x4C pixel/tile offset of the current line */
    u8   pad_4E[0x0D];
    u8   messageBoxState; /* +0x5B message box state recorded while the text waits */
    u8   flags;      /* +0x5C: TEXT_FLAG_* */
} TextState;
/* TEXT_FLAG_* bits of TextState.flags. */
#define TEXT_FLAG_WAIT_MESSAGE_BOX 0x01 /* set: the text waits while a message box is active */
/* Byte offset from a cell to the cell directly below it: the buffer is 32 u16
 * entries (0x40 bytes) wide. */
#define TEXT_CELL_ROW_BYTES 0x40

#pragma push
#pragma scheduling off
s32 func_02099e6c(void *arg0, s32 arg1) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void func_0207a3b0(s32, u32, u16, u8, s32, u16, s32, s32, s32, s32, s32);
    s32 Divide(s32, M2C_UNK);
    void *GetLocalizedText(s32);
    s32 GetOtherScreenMode(M2C_UNK);
    s32 GetOther3DSpriteScreenMode(M2C_UNK);
    M2C_UNK Set3DSpriteTargetMode(s32);
    M2C_UNK func_02094410(s32);
    M2C_UNK ShowScenePanelUnlessMessageBox();
    M2C_UNK CloseScenePanel();
    M2C_UNK SetScenePanelFaceUnlessMessageBox(s32, s32, s32);
    M2C_UNK SetScenePanelArmyUnlessMessageBox(s32, u8);
    M2C_UNK SetScenePanelModeUnlessMessageBox(s32, s32);
    M2C_UNK SetPanelFaceHiddenUnlessMessageBox(s32, M2C_UNK);
    M2C_UNK ClearScenePanelRowsUnlessMessageBox();
    M2C_UNK ShowPanelFaceUnlessMessageBox();
    M2C_UNK HidePanelFaceUnlessMessageBox();
    M2C_UNK CallScenePanelFaceOp(s32, s32, s32, s32);
    M2C_UNK SetScenePanelFaceSlotUnlessMessageBox(s32, s32, s32);
    M2C_UNK SetScenePanelFaceHiddenUnlessMessageBox(s32, M2C_UNK);
    M2C_UNK func_02094c90(s32, void *);
    M2C_UNK HighlightScenePanelFaceUnlessMessageBox();
    M2C_UNK ClearScenePanelHighlight();
    M2C_UNK func_02094df0(M2C_UNK, s32, s32);
    M2C_UNK RecordsMenu_PlayTrack(s32);
    M2C_UNK ScriptCmd_PlaySound(s32);
    M2C_UNK StartScriptedScreenTransition(M2C_UNK, M2C_UNK, s32);
    M2C_UNK CreateScreenTransitionWaitSprite();
    M2C_UNK CreateScriptWaitSprite(s32);
    M2C_UNK CreateScreenSplitSprite(M2C_UNK, s32, void *);
    M2C_UNK ShowTelopText(u8 *);
    s32 IsTextWaitingForMessageBox(void *);
    s32 GetTextCursorCell(void *);
    s32 GetTextLineStartCell(void *);
    M2C_UNK EndTextLine(void *);
    M2C_UNK EndTextLineAndMarkRedraw(void *);
    s32 IsLeadByte();
    s32 IsGlyphEscape(void *);
    M2C_UNK StopTextObject(void *);
    M2C_UNK Text_AdvanceScript(void *);
    M2C_UNK Text_SkipLineEnds(void *);
    extern M2C_UNK data_02102e74;
    extern M2C_UNK data_02102eac;
    extern M2C_UNK gMovementCostTable;
    extern void **gCurrentMap;
    s32 param;
    u8 sp1C[0x40];
    s32 temp_r0_10;
    s32 temp_r0_9;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r8;
    s32 var_r0;
    s32 var_r0_2;
    u32 temp_r0_12;
    u32 temp_r0_13;
    u32 temp_r0_6;
    u32 temp_r0_7;
    u32 temp_r0_8;
    u32 temp_r2_2;
    u32 temp_r2_3;
    u8 *var_r4;
    u8 temp_r0;
    u8 temp_r0_11;
    u8 temp_r0_3;
    u8 temp_r0_5;
    u8 temp_r3_4;
    u8 var_r1;
    void *temp_r0_14;
    void *temp_r0_15;
    void *temp_r0_16;
    void *temp_r0_2;
    void *temp_r0_4;
    void *temp_r1;
    void *temp_r2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r6;

loop_1:
    temp_r1 = M2C_FIELD(arg0, void **, 0x34);
    temp_r0 = M2C_FIELD(temp_r1, u8 *, 0);
    if (temp_r0 == 0x16) {
        M2C_FIELD(arg0, s16 *, 0x46) = (s16) (M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        Text_AdvanceScript(arg0);
        Text_AdvanceScript(arg0);
        goto loop_1;
    }
    switch (temp_r0) {
    case 0:
        temp_r2 = M2C_FIELD(arg0, void **, 0x38);
        if (temp_r2 == NULL) {
            return 0;
        }
        M2C_FIELD(arg0, void **, 0x34) = temp_r2;
        M2C_FIELD(arg0, void **, 0x38) = NULL;
        return func_02099e6c(arg0, arg1);
    case 5:
    case 6:
        if (IsTextWaitingForMessageBox(arg0) == 0) {
            temp_r0_2 = CreateSpriteFromClass(&data_02102e74, 7);
            M2C_FIELD(temp_r0_2, s32 *, 0x4C) = arg1;
            M2C_FIELD(temp_r0_2, s32 *, 0x3C) = GetTextLineStartCell(arg0);
            M2C_FIELD(temp_r0_2, s8 *, 0x40) = (s8) M2C_FIELD(arg0, s8 *, 0x57);
            M2C_FIELD(temp_r0_2, u16 *, 0x48) = (u16) M2C_FIELD(arg0, u16 *, 0x44);
            M2C_FIELD(temp_r0_2, s16 *, 0x4A) = (s16) M2C_FIELD(arg0, u8 *, 0x56);
            M2C_FIELD(temp_r0_2, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
            temp_r0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0);
            if ((temp_r0_3 == 5) || (temp_r0_3 != 6)) {
                M2C_FIELD(temp_r0_2, s16 *, 0x34) = 0;
            } else {
                M2C_FIELD(temp_r0_2, s16 *, 0x34) = 1;
            }
            M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 8);
        }
        Text_AdvanceScript(arg0);
        return 2;
    case 10:
    case 13:
        if (GetTextCursorCell(arg0) == 0) {
            return 0;
        }
        if (IsTextWaitingForMessageBox(arg0) == 0) {
            M2C_FIELD(arg0, u8 *, 0x4B) = (u8) (M2C_FIELD(arg0, u8 *, 0x4B) + 2);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + 2);
            EndTextLine(arg0);
        }
        Text_AdvanceScript(arg0);
        return 3;
    case 2:
        if (IsTextWaitingForMessageBox(arg0) == 0) {
            temp_r0_4 = CreateSpriteFromClass(&data_02102eac, 7);
            M2C_FIELD(temp_r0_4, s32 *, 0x4C) = arg1;
            M2C_FIELD(temp_r0_4, s32 *, 0x3C) = GetTextLineStartCell(arg0);
            M2C_FIELD(temp_r0_4, s8 *, 0x40) = (s8) M2C_FIELD(arg0, s8 *, 0x57);
            M2C_FIELD(temp_r0_4, s16 *, 0x4A) = (s16) M2C_FIELD(arg0, u8 *, 0x56);
            M2C_FIELD(temp_r0_4, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) M2C_FIELD(arg0, u16 *, 0x4E);
            M2C_FIELD(arg0, u8 *, 0x55) = 2U;
            EndTextLineAndMarkRedraw(arg0);
        }
        Text_SkipLineEnds(arg0);
        return 2;
    case 4:
        if (IsTextWaitingForMessageBox(arg0) == 0) {
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16) M2C_FIELD(arg0, u16 *, 0x4E);
            EndTextLineAndMarkRedraw(arg0);
        }
        Text_AdvanceScript(arg0);
        return 2;
    case 3:
        temp_r4 = M2C_FIELD(temp_r1, u8 *, 1) & 0x7F;
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        if (IsTextWaitingForMessageBox(arg0) != 0) {
            return 3;
        }
        CreateScriptWaitSprite(temp_r4);
        return 2;
    case 12:
        if (IsTextWaitingForMessageBox(arg0) == 0) {
            temp_r0_5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1);
            switch(temp_r0_5){case 0:StopTextObject(arg0);break;default:M2C_FIELD(arg0,u8 *,0x55)=temp_r0_5;M2C_FIELD(arg0,s8 *,0x54)=0;break;}
        }
        Text_AdvanceScript(arg0);
        Text_AdvanceScript(arg0);
        return 3;
    case 11:
        temp_r0_6 = M2C_FIELD(temp_r1, u8 *, 1) - 0x80;
        switch (temp_r0_6) {
        case 0:
            if (IsTextWaitingForMessageBox(arg0) == 0) {
                temp_r3 = *gCurrentMap;
                temp_r4_2 = (M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x52D0), u8 *, 0xC) * 0xE) + (s32) (temp_r3 + 0x59A4);
                temp_r0_7 = (u32) (M2C_FIELD(temp_r4_2, u16 *, 6) << 0x19) >> 0x19;
                if (temp_r0_7 == 0) {
                    var_r0 = 0;
                } else {
                    var_r0 = Divide(temp_r0_7 - 1, 0xA) + 1;
                }
                func_0207a3b0(M2C_FIELD(arg0, s32 *, 0x40) + (M2C_FIELD(arg0, u8 *, 0x4A) * 2) + (M2C_FIELD(arg0, u8 *, 0x4B) << 6), (u32) (M2C_FIELD(temp_r4_2, u8 *, 0) << 0x1A) >> 0x1A, M2C_FIELD(*gCurrentMap, u16 *, 0x52A8), M2C_FIELD(temp_r4_2, u8 *, 0xC), 0, (s32) var_r0, 0, 0, 0, 0, 0);
                M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 2);
            }
            Text_AdvanceScript(arg0);
            Text_AdvanceScript(arg0);
            return 3;
        case 1:
            if (IsTextWaitingForMessageBox(arg0) == 0) {
                temp_r3_2 = *gCurrentMap;
                temp_r4_3 = (M2C_FIELD(M2C_FIELD(temp_r3_2, void **, 0x52D0), u8 *, 0xD) * 0xE) + (s32) (temp_r3_2 + 0x59A4);
                temp_r0_8 = (u32) (M2C_FIELD(temp_r4_3, u16 *, 6) << 0x19) >> 0x19;
                if (temp_r0_8 == 0) {
                    var_r0_2 = 0;
                } else {
                    var_r0_2 = Divide(temp_r0_8 - 1, 0xA) + 1;
                }
                func_0207a3b0(M2C_FIELD(arg0, s32 *, 0x40) + (M2C_FIELD(arg0, u8 *, 0x4A) * 2) + (M2C_FIELD(arg0, u8 *, 0x4B) << 6), (u32) (M2C_FIELD(temp_r4_3, u8 *, 0) << 0x1A) >> 0x1A, M2C_FIELD(*gCurrentMap, u16 *, 0x52A8), M2C_FIELD(temp_r4_3, u8 *, 0xC), 0, (s32) var_r0_2, 0, 0, 0, 0, 0);
                M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x4A) + 2);
            }
            Text_AdvanceScript(arg0);
            Text_AdvanceScript(arg0);
            return 3;
        case 2:
        case 3:
            M2C_FIELD(arg0, void **, 0x38) = (void *) (temp_r1 + 2);
            temp_r6 = *gCurrentMap;
            M2C_FIELD(arg0, void **, 0x34) = GetLocalizedText(M2C_FIELD((u8 *)&gMovementCostTable + (((u32)(M2C_FIELD(((M2C_FIELD(temp_r6,u16 *,0x52A4)*0x8c)+(s32)temp_r6),s32 *,0x6810)<<24)>>24)*0x9c),s32 *,0));
            return func_02099e6c(arg0, arg1);
        default:
            Text_AdvanceScript(arg0);
            Text_AdvanceScript(arg0);
            return 3;
        }
        break;
    case 8:
        Text_AdvanceScript(arg0);
        Text_AdvanceScript(arg0);
        return 3;
    case 16:
        if (temp_r0 == 0x10) {
            do {
                temp_r2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) - 0x80;
                temp_r0_9 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) - 0x80;
                switch (temp_r2_2) {
                default:
                    break;
                case 0:
                    SetScenePanelFaceUnlessMessageBox(temp_r0_9, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 13:
                    SetScenePanelModeUnlessMessageBox(temp_r0_9, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 12:
                    var_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3);
                    if (var_r1 == 0) {
                        temp_r3_3 = *gCurrentMap;
                        var_r1 = M2C_FIELD(((M2C_FIELD(temp_r3_3, u16 *, 0x52A4) * 0x8C) + (s32) temp_r3_3), u8 *, 0x67C1);
                    }
                    SetScenePanelArmyUnlessMessageBox(temp_r0_9, var_r1);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 10:
                    ShowScenePanelUnlessMessageBox();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 11:
                    CloseScenePanel();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 14:
                    ClearScenePanelRowsUnlessMessageBox();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 6:
                    func_02094c90(temp_r0_9, arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 8:
                    SetPanelFaceHiddenUnlessMessageBox(temp_r0_9, 0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 9:
                    SetPanelFaceHiddenUnlessMessageBox(temp_r0_9, 1);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x10);
        }
        return 2;
    case 17:
        if (temp_r0 == 0x11) {
            do {
                temp_r2_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) - 0x80;
                temp_r0_10 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) - 0x80;
                switch (temp_r2_3) {
                default:
                    break;
                case 0:
                    SetScenePanelFaceSlotUnlessMessageBox(temp_r0_10, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 1:
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 2:
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 3:
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 4:
                    ShowPanelFaceUnlessMessageBox();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 5:
                    HidePanelFaceUnlessMessageBox();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 6:
                    HighlightScenePanelFaceUnlessMessageBox();
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 7:
                    CallScenePanelFaceOp(temp_r0_10, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 3) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 4) & 0x7F, M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 5) & 0x7F);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 8:
                    SetScenePanelFaceHiddenUnlessMessageBox(temp_r0_10, 0);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                case 9:
                    SetScenePanelFaceHiddenUnlessMessageBox(temp_r0_10, 1);
                    Text_AdvanceScript(arg0);
                    Text_AdvanceScript(arg0);
                    Text_SkipLineEnds(arg0);
                    break;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x11);
        }
        return 2;
    case 18:
        ClearScenePanelHighlight();
        Text_SkipLineEnds(arg0);
        goto return_two;
    case 19:
        temp_r0_11 = M2C_FIELD(temp_r1, u8 *, 1);
        if (temp_r0_11 == 0x80) {
            CreateScreenTransitionWaitSprite();
            Text_AdvanceScript(arg0);
            Text_SkipLineEnds(arg0);
            return 2;
        }
        param = M2C_FIELD(temp_r1,u8 *,2)&0x7f;
        temp_r0_12 = temp_r0_11 - 0x81;
        switch (temp_r0_12) {
        default:
            break;
        case 0:
            StartScriptedScreenTransition(0, 0, param);
            break;
        case 1:
            StartScriptedScreenTransition(1, 0, param);
            break;
        case 2:
            StartScriptedScreenTransition(0, 2, param);
            break;
        case 3:
            StartScriptedScreenTransition(1, 2, param);
            break;
        case 4:
            StartScriptedScreenTransition(0, 1, param);
            break;
        case 5:
            StartScriptedScreenTransition(1, 1, param);
            break;
        }
        Text_AdvanceScript(arg0);
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 3;
    case 20:
        if (temp_r0 == 0x14) {
            do {
                temp_r0_13 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 1) & 0x7F;
                temp_r8 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 2) & 0x7F;
                switch (temp_r0_13) {
                default:
                    break;
                case 0:
                    func_02094df0(0, GetOtherScreenMode(0), temp_r8);
                    break;
                case 1:
                    func_02094df0(1, GetOtherScreenMode(1), temp_r8);
                    break;
                case 2:
                    func_02094df0(0, GetOther3DSpriteScreenMode(0), temp_r8);
                    break;
                case 3:
                    func_02094df0(1, GetOther3DSpriteScreenMode(1), temp_r8);
                    break;
                case 4:
                    CreateScreenSplitSprite(0, temp_r8, arg0);
                    break;
                case 5:
                    CreateScreenSplitSprite(1, temp_r8, arg0);
                    break;
                }
                Text_AdvanceScript(arg0);
                Text_AdvanceScript(arg0);
                Text_SkipLineEnds(arg0);
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) == 0x14);
        }
        return 3;
    case 21:
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 3;
    case 23:
        func_02094410(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        goto return_two;
    case 25:
        ScriptCmd_PlaySound(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 2;
    case 24:
        RecordsMenu_PlayTrack(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 2;
    case 26:
        Text_AdvanceScript(arg0);
        var_r4 = sp1C;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) != 0x1E) {
            do {
                if ((IsLeadByte() != 0) || (IsGlyphEscape(M2C_FIELD(arg0, void **, 0x34)) != 0)) {
                    M2C_FIELD(var_r4,u8 *,0)=*M2C_FIELD(arg0,u8 **,0x34)++;
                    M2C_FIELD(var_r4,u8 *,1)=*M2C_FIELD(arg0,u8 **,0x34)++;
                    var_r4 += 2;
                } else {
                    M2C_FIELD(var_r4,u8 *,0)=*M2C_FIELD(arg0,u8 **,0x34)++;
                    var_r4 += 1;
                }
            } while (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), u8 *, 0) != 0x1E);
        }
        *var_r4 = 0;
        ShowTelopText(sp1C);
        M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 8);
        Text_SkipLineEnds(arg0);
        return 3;
    case 27:
        Set3DSpriteTargetMode(M2C_FIELD(temp_r1, u8 *, 1) & 0x7F);
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 3;
    case 28:
        temp_r3_4 = M2C_FIELD(temp_r1, u8 *, 1);
        M2C_FIELD(arg0, u8 *, 0x4A) = (u8) (M2C_FIELD(arg0, u8 *, 0x48) + (temp_r3_4 & 0x7F));
        M2C_FIELD(arg0, u16 *, 0x4C) = (u16) (M2C_FIELD(arg0, u16 *, 0x4C) + ((u32)(temp_r3_4<<25)>>24));
        M2C_FIELD(arg0, u8 *, 0x56) = 0U;
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 1;
    case 29:
        Text_AdvanceScript(arg0);
        Text_SkipLineEnds(arg0);
        return 1;
    case 30:
        Text_SkipLineEnds(arg0);
        return 3;
    default:
    case 1:
    case 7:
    case 9:
    case 14:
    case 15:
    case 22:
        return 1;
    }
return_two:
    return 2;
}
#pragma pop
/* Write the two tilemap entries of the glyph cell at `cell` in the text object's
 * cell buffer: the current line's tile (linePixel) and the tile directly below it
 * (linePixel + 1), each OR-ed with the text's base attribute. */
void WriteTextCellTilePair(void *textObject, void *cell) {
    TextState *text = textObject;

    if (cell == NULL) {
        return;
    }
    M2C_FIELD(cell, s16 *, 0) = (s16) (text->linePixel | text->baseAttr);
    M2C_FIELD(cell, s16 *, TEXT_CELL_ROW_BYTES) = (s16) ((text->linePixel + 1) | text->baseAttr);
}

/* Flag the text object to hold its script while the active message box is up:
 * remember the box's state and rebuild the sprite scene. */
void Text_StartWaitingForMessageBox(TextState *text) {
    s8 GetMessageBoxState();
    M2C_UNK Build3DSpriteScene(void *);
    text->flags |= TEXT_FLAG_WAIT_MESSAGE_BOX;
    text->messageBoxState = GetMessageBoxState();
    Build3DSpriteScene(text);
}
