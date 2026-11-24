/* 4 functions from 0x02099B18 to 0x02099E6C (main), found by ds-decomp. */
#include "common.h"

u8 IsLeadByte(u8 *arg0);
u8 IsGlyphEscape(u8 *arg0);
#pragma opt_propagation off
s32 FindTextControlCode(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    u8 *data = (u8 *)arg0;
    s32 want = arg1;
    s32 allow = arg2;
    s32 base;
    s32 step;
    u32 c;
    if (!data) return 0;
    while ((c = *data) != 0) {
        base = 0;
        step = base;
        switch (c) {
            case 2: case 4: case 5: case 6: case 10: case 13:
                step = base + 1;
                if (!allow) return base;
                break;
            case 3:
                step = base + 2;
                break;
            case 11:
                step = base + 1;
                if ((u8)(data[1] + 0x80) <= 1) step = base + 2;
                break;
            case 8:
                step = base + 1;
                if (c >= 0x80 && c <= 0x99) step = base + 2;
                else if (c >= 0x9a && c <= 0xb3) step++;
                break;
            case 16:
                switch (data[2]) {
                    case 0x80: step = base + 5; break;
                    case 0x8d: step = base + 4; break;
                    case 0x8c: step = base + 4; break;
                    case 0x8a: step = base + 3; break;
                    case 0x8b: step = base + 3; break;
                    case 0x8e: step = base + 3; break;
                    case 0x86: step = base + 3; break;
                    case 0x88: step = base + 3; break;
                    case 0x89: step = base + 3; break;
                }
                break;
            case 17:
                switch (data[2]) {
                    case 0x80: step = base + 5; break;
                    case 0x81: step = base + 4; break;
                    case 0x82: step = base + 4; break;
                    case 0x83: step = base + 4; break;
                    case 0x84: step = base + 3; break;
                    case 0x85: step = base + 3; break;
                    case 0x86: step = base + 3; break;
                    case 0x87: step = base + 5; break;
                    case 0x88: step = base + 3; break;
                    case 0x89: step = base + 3; break;
                }
                break;
            case 18: case 26: case 30:
                step = base + 1;
                break;
            case 19:
                if (data[1] == 0x80) step = base + 2;
                else step = base + 3;
                break;
            case 20:
                step = base + 3;
                break;
            case 21: case 22: case 23: case 24: case 25: case 27: case 28: case 29:
                step = base + 2;
                break;
            default: {
                u8 IsLeadByte(u8 *);
                u8 IsGlyphEscape(u8 *);
                if (IsLeadByte(data)) step += 2;
                else if (IsGlyphEscape(data)) step += 2;
                else step++;
                goto advance;
            }
        }
        if (want == c) return (s32)data;
        advance: data += step;
    }
    return 0;
}
#pragma opt_propagation reset
/* Return 1 when the message text is a plain message with no embedded choice
 * widget, so the full-screen message box can show it; 0 when it carries one. */
u8 Text_IsPlainMessage(M2C_UNK text) {
    s32 FindTextControlCode(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 var_r0;

    if (FindTextControlCode(text, TEXT_CODE_CHOICE_WIDGET, 1) != 0) {
        return 0U;
    }
    if (FindTextControlCode(text, TEXT_CODE_CHOICE_WIDGET_ALT, 1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Number of screens the message in `text` is shown on, taken from its
 * TEXT_CODE_MSG_SPRITE_COUNT operand (0x80 -> 0, 0x81 -> 1, 0x82 -> 2); 1 when
 * the text carries no such code. */
s32 Text_GetScreenCount(u8 *text) {
    s32 FindTextControlCode(M2C_UNK, M2C_UNK, M2C_UNK);
    void *controlCode;
    u8 operand;
    controlCode = (void *)FindTextControlCode((M2C_UNK)text, TEXT_CODE_MSG_SPRITE_COUNT, 1);
    if (controlCode != NULL) {
        operand = M2C_FIELD(controlCode, u8 *, 1);
        if (operand == 0x80) return 0;
        if (operand == 0x81) return 1;
        if (operand == 0x82) return 2;
    }
    return 1;
}

void StopTextObject(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x55) = 0;
    M2C_FIELD(arg0, s8 *, 0x54) = -2;
}
