/* 34 functions from 0x0209BC58 to 0x0209CC04 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s16 value; s8 mode; u8 low:4; u8 high:4; } SpriteAttribute0209;
typedef struct SpriteStateWord {
    u32 state : 3;
    u32 field3 : 4;
    u32 field7 : 10;
    u32 field17 : 9;
    u32 field26 : 3;
    u32 field29 : 3;
} SpriteStateWord;

extern s32 gCur3DSpriteEngine;
extern s32 g3DSpriteEngineMain;
extern u8 gCarriedUnitIconTable[256];
extern s32 data_0215d8a8[58];  // 232 bytes / 4
extern s32 gSaveSlotSummary[2];   // 8 bytes / 4

void func_0209bc58(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6, u16 arg7) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK StopTextObject(s32);
    M2C_UNK func_0209bdcc(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK data_02103300;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;
    temp_r4 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x54);
    func_0209bdcc(temp_r4, arg0, arg1, arg2, arg3, arg4, arg5, (s32)arg6, (s32)arg7);
    StopTextObject(temp_r4);
    CreateSpriteFromClass(&data_02103300, 7);
}

void func_0209bccc(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5) {
    void func_0209bd0c(M2C_UNK, M2C_UNK, s32, s32, s32, s32, u16, u16);
    extern s32 gCur3DSpriteEngine;
    void *temp_r5;

    temp_r5 = gCur3DSpriteEngine + (arg2 * 4);
    func_0209bd0c(arg0, arg1, arg2, M2C_FIELD(temp_r5, s32 *, 0xC), M2C_FIELD(temp_r5, s32 *, 0x20), arg3, (s32) arg4, (s32) arg5);
}

void func_0209bd0c(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,u16 g,u16 h) {
s32 GetLocalizedText(s32);
s32 CreateMessageSprite(s32,s32,s32,s32,s32,s32,u16,u16);
CreateMessageSprite(a,b,c,d,e,GetLocalizedText(f),g,h);
}

s32 CreateMessageSprite(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6, u16 arg7) {
    s32 CreateSpriteFromClass(M2C_UNK *, s32);
    M2C_UNK func_0209bdcc(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, u16, u16);
    extern M2C_UNK data_02103328;
    s32 temp_r0;
    temp_r0 = CreateSpriteFromClass(&data_02103328, 7);
    func_0209bdcc(temp_r0, arg0, arg1, arg2, arg3, arg4, arg5, (s32)arg6, (s32)arg7);
    return temp_r0;
}

s32 func_0209bdcc(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,u16 h,u16 i) {
void func_0209be10(void *,s32,s32,s32,s32,s32,s32,u16,u16,u16);
func_0209be10((void *)a,b,c,d,e,f,g,h,0,i);
}

#pragma scheduling on
void func_0209be10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u16 arg7, u16 arg8, u16 arg9) {
    void (*func_02091fb4(u32))(void);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;

    M2C_FIELD(arg0, s32 *, 0x34) = arg6;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, u8 *, 0x57) = (u8)arg3;
    M2C_FIELD(arg0, s32 *, 0x3c) = arg4;
    M2C_FIELD(arg0, s32 *, 0x40) = arg5;
    M2C_FIELD(arg0, u16 *, 0x44) = arg7;
    M2C_FIELD(arg0, u16 *, 0x46) = arg8;
    M2C_FIELD(arg0, u16 *, 0x4e) = arg9;
    M2C_FIELD(arg0, u16 *, 0x4c) = arg9;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, u8 *, 0x48) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x49) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4a) = (u8)(arg1 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x4b) = (u8)(arg2 & 0xFF);
    M2C_FIELD(arg0, u8 *, 0x54) = (s8)-1;
    M2C_FIELD(arg0, u8 *, 0x55) = 2;
    M2C_FIELD(arg0, s32 *, 0x50) = (s32)func_02091fb4((u32)arg3);
    {
        u32 temp_r0 = gCur3DSpriteEngine == g3DSpriteEngineMain ? 1u : 0u;
        temp_r0 = (s32)(u8)temp_r0;
        if (temp_r0 != 1) {
            temp_r0 = 1;
        } else {
            temp_r0 = 0;
        }
        M2C_FIELD(arg0, u8 *, 0x5a) = (u8)temp_r0;
    }
    M2C_FIELD(arg0, u8 *, 0x56) = 0;
    M2C_FIELD(arg0, u8 *, 0x58) = 0;
    M2C_FIELD(arg0, u8 *, 0x59) = 0;
    M2C_FIELD(arg0, u8 *, 0x5c) = 0;
}
#pragma scheduling off
void func_0209bee0(void *a,s32 b,s32 c,s32 d,s32 e,s32 f,u16 g,u16 h) {
M2C_FIELD(a,u8 *,0x57)=d;
M2C_FIELD(a,s32 *,0x3c)=e;
M2C_FIELD(a,s32 *,0x40)=f;
M2C_FIELD(a,u16 *,0x44)=g;
M2C_FIELD(a,u16 *,0x4e)=h;
M2C_FIELD(a,u16 *,0x4c)=h;
M2C_FIELD(a,u8 *,0x48)=(u8)b;
M2C_FIELD(a,u8 *,0x49)=(u8)c;
M2C_FIELD(a,u8 *,0x4a)=(u8)b;
M2C_FIELD(a,u8 *,0x4b)=(u8)c;
}

u8 func_0209bf28(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02103328;
    extern M2C_UNK data_021032d8;
    extern M2C_UNK data_02103300;
    u8 var_r0;

    if (FindObjectByClass(&data_02103328) != 0) {
        return 1U;
    }
    if (FindObjectByClass(&data_021032d8) != 0) {
        return 1U;
    }
    if (FindObjectByClass(&data_02103300) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0209bf7c(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02103328, data_021032d8, data_02103300;
    DeleteSpriteObjectsOfClass(&data_02103328);
    DeleteSpriteObjectsOfClass(&data_021032d8);
    DeleteSpriteObjectsOfClass(&data_02103300);
}

void func_0209bfa8(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_021032d8;
    extern M2C_UNK data_02103300;
    DeleteSpriteObjectsOfClass(&data_021032d8);
    DeleteSpriteObjectsOfClass(&data_02103300);
}

void func_0209bfc8(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02103328;
    FindObjectByClass(&data_02103328);
}

void func_0209bfdc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, u16 arg4, u16 arg5) {
    M2C_UNK func_0209c024(M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u16);
    func_0209c024(arg0, arg1, arg2, GetLocalizedText(arg3), (s32) arg4, (s32) arg5);
}

s32 func_0209c024(s32 a,s32 b,s32 c,s32 d,u16 e,u16 f) {
s32 func_0209953c(s32,s32,s32,s32,u16,u16);
func_0209953c(a,b,c,d,e,f);
}

void DrawTilemapNumber(s32 arg0, s32 arg1, s32 arg2, u32 arg3, u16 arg4, u16 arg5) {
    u32 var_r3;
    u16 var_r1;
    s16 *var_r0;

    var_r3 = arg3;
    var_r0 = (s16 *)(arg2 + (arg0 * 2) + (arg1 << 6));
    var_r1 = 0x10;
    if (arg5 == 3) {
        var_r1 += 0x1C;
    }
    do {
        u32 rem;

        rem = var_r3 % 10;
        *var_r0 = (s16)(arg4 | (var_r1 + (rem * 2)));
        *(s16 *)((u8 *)var_r0 + 0x40) = (s16)(arg4 | ((var_r1 + (rem * 2)) + 1));
        var_r0 = (s16 *)((u8 *)var_r0 - 2);
        var_r3 = var_r3 / 10;
    } while (var_r3 != 0);
}

/* Write one symbol of the number font (a plus, minus, decimal point or comma
 * character code) at tile column `x`, row `y` of the tilemap at `tiles`: the
 * upper entry holds the glyph's first half and the entry one row below its second
 * half, both OR'ed with `attrs`; `variant` 3 selects the alternate glyph set. */
void DrawTilemapSymbol(s32 x, s32 y, s32 tiles, s32 symbol, u16 attrs, u16 variant) {
    u16 tile;

    x = tiles + x * 2 + (y << 6); /* x becomes the address of the tilemap entry */
    tile = 0x10;
    switch (symbol) {
    case 0x2b: tile += 0x14; break;
    case 0x2d: tile += 0x16; break;
    case 0x3d: tile += 0x18; break;
    case 0x47: tile += 0x1a; break;
    }
    if (variant == 3) tile += 0x1c;
    *(s16 *)x = (s16)(tile | attrs);
    *(s16 *)((u8 *)x + 0x40) = (s16)((tile + 1) | attrs);
}

s32 func_0209c168(void *arg0, s32 arg1) {
    s32 sum;
    u32 mod;

    sum = M2C_FIELD(arg0, u8 *, 0x56) + arg1;
    mod = sum & 0xFF;
    M2C_FIELD(arg0, u8 *, 0x56) = (u8)sum;
    if (mod >= 8) {
        do {
            M2C_FIELD(arg0, u8 *, 0x56) = (u8)(M2C_FIELD(arg0, u8 *, 0x56) - 8);
            M2C_FIELD(arg0, u16 *, 0x4C) = (u16)(M2C_FIELD(arg0, u16 *, 0x4C) + 2);
            M2C_FIELD(arg0, u8 *, 0x4A) = (u8)(M2C_FIELD(arg0, u8 *, 0x4A) + 1);
            mod = M2C_FIELD(arg0, u8 *, 0x56);
        } while (mod >= 8);
    }
    if (mod != 0) {
        return 1;
    }
    return 0;
}

/* Measure one glyph at `glyph`: add its pixel advance to *width (including the
 * one-pixel gap that follows it once something has already been measured) and
 * return the number of bytes the glyph occupies (2 for a lead byte or an escape
 * pair, 1 for a plain glyph, 0 for a NULL pointer). */
s32 MeasureGlyphWidth(u8 *glyph, s32 *width) {
    u8 IsLeadByte(u8 *);
    u8 IsGlyphEscape(u8 *);
    extern u8 gGlyphWidthTable[256];

    if (glyph != NULL) {
        if (IsLeadByte(glyph)) {
            *width += 8;
            return 2;
        }
        if (IsGlyphEscape(glyph)) {
            if (*width != 0) {
                *width += 1;
            }
            *width += gGlyphWidthTable[glyph[1]];
            return 2;
        }
        if (*width != 0) {
            *width += 1;
        }
        *width += gGlyphWidthTable[glyph[0]];
        return 1;
    }
    return 0;
}

s32 MeasureStringWidth(u8 *arg0) {
    s32 MeasureGlyphWidth(u8 *, s32 *);
    s32 sp0;
    u8 *var_r5;

    var_r5 = arg0;
    sp0 = 0;
    if ((var_r5 != NULL) && (*var_r5 != 0)) {
        do {
            var_r5 = &var_r5[MeasureGlyphWidth(var_r5, &sp0)];
        } while (*var_r5 != 0);
    }
    return sp0;
}

s32 func_0209c2a8(void) {
    s32 MeasureMessageWidth();
    s32 temp_r1;

    temp_r1 = MeasureMessageWidth() + 6;
    return (s32) (temp_r1 + ((u32) (temp_r1 >> 2) >> 0x1D)) >> 3;
}

/* Pixel width of a message string: walks it, honouring the message control
 * codes (0x0B 0x80/0x81 and 0x08 are fixed 16px items, 0x0B 0x82/0x83 insert
 * the current player's commander name, 0x16/0x17/0x1C/0x1D are two-byte codes
 * with no width) and adding each glyph's advance. */
s32 MeasureMessageWidth(u8 *text) {
    s32 GetLocalizedText(u32);
    s32 MeasureStringWidth(u8 *);
    s32 MeasureGlyphWidth(u8 *, s32 *);
    extern u8 gMovementCostTable[];
    extern void **gCurrentMap;
    s32 width;
    u8 *cursor;
    u8 c;

    width = 0;
    cursor = text;
    c = *cursor;
    while (c != 0) {
        switch (c) {
        case 0xB:
            switch (cursor[1]) {
            case 0x80:
            case 0x81:
                width += 0x10;
                cursor += 2;
                break;
            case 0x82:
            case 0x83: {
                u8 *map;
                u16 player;
                /* the player record's commander id (low byte at +0x6C) picks
                 * the commander data record, whose first word is its name */
                map = (u8 *)*gCurrentMap;
                player = M2C_FIELD(map, u16 *, 0x52A4);
                width += MeasureStringWidth((u8 *)GetLocalizedText(M2C_FIELD(gMovementCostTable + ((u32)(M2C_FIELD(map + (u32)player * 0x8C, s32 *, 0x6810) << 24) >> 24) * 0x9C, u32 *, 0)));
                cursor += 2;
                break;
            }
            }
            break;
        case 0x8:
            width += 0x10;
            cursor += 2;
            break;
        case 0x16:
        case 0x17:
        case 0x1C:
        case 0x1D:
            cursor += 2;
            break;
        default:
            cursor += MeasureGlyphWidth(cursor, &width);
            break;
        }
        c = *cursor;
    }
    if (width < 0) width = 0;
    return width;
}

void func_0209c418(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
}

void func_0209c428(void *arg0) {
    void func_0209c418(void *);
    func_0209c418(arg0);
    if (*(u8 *) M2C_FIELD(arg0, void **, 0x34) == 0x0D ||
        *(u8 *) M2C_FIELD(arg0, void **, 0x34) == 0x0A) {
        func_0209c428(arg0);
    }
}

/* Pixel width of a message string.  Like MeasureMessageWidth, but when
 * stopAtBreak is set it stops at the first line break and returns that line's
 * width; otherwise it returns the widest of the lines, where a line ends at
 * 0x0A/0x0D.  0x04 is a one-byte code, 0x16/0x17/0x1C/0x1D two-byte codes with
 * no width, everything else is a glyph laid out by MeasureGlyphWidth. */
s32 MeasureMessageLinesWidth(u8 *text, s32 stopAtBreak) {
    s32 MeasureGlyphWidth(u8 *, s32 *);
    s32 width;
    s32 lineStart;
    s32 widest = 0;
    u8 *cursor = text;
    u8 c;

    width = 0;
    if (!cursor) {
        return 0;
    }
    c = *cursor;
    if (c) {
        lineStart = 0;
        do {
            switch (c) {
            case 0x0A:
            case 0x0D:
                if (!stopAtBreak) {
                    return width;
                }
                cursor++;
                if (width > widest) {
                    widest = width;
                }
                width = lineStart;
                break;
            case 0x04:
                cursor++;
                break;
            case 0x16:
            case 0x17:
            case 0x1C:
            case 0x1D:
                cursor += 2;
                break;
            default:
                cursor += MeasureGlyphWidth(cursor, &width);
                break;
            }
            c = *cursor;
        } while (c);
    }
    if (widest > width) {
        width = widest;
    }
    return width;
}

/* Height in pixels of a message string: each line is 0x10 pixels tall, so the
 * result counts one line per 0x0A/0x0D break.  0x16/0x17/0x1C/0x1D introduce a
 * two-byte code with no glyph of its own; every other byte advances one.  A NULL
 * string has no height. */
s32 MeasureMessageHeight(u8 *text) {
    s32 height;
    u8 *cursor;
    u8 c;

    cursor = text;
    height = 0x10;
    if (cursor == NULL) {
        return 0;
    }
    c = *cursor;
    if (c != 0) {
        do {
            switch ((s32) c) {
            case 10:
            case 13:
                height += 0x10;
                cursor += 1;
                break;
            case 23:
            case 28:
                /* fallthrough */
            case 22:
                cursor += 2;
                break;
            default:
                cursor += 1;
                break;
            }
            c = *cursor;
        } while (c != 0);
    }
    return height;
}

void *func_0209c5dc(void *arg0, s32 arg1) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *cur;
    s32 i;

    if (arg0 == NULL) {
        return NULL;
    }
    cur = arg0;
    i = 0;
    if (arg1 > 0) {
        do {
            void *r0;

            r0 = func_02099b18(cur, 13, 1);
            if (r0 == NULL) {
                r0 = func_02099b18(cur, 10, 1);
                if (r0 == NULL) {
                    return NULL;
                }
            }
            i++;
            cur = (void *)((u8 *)r0 + 1);
        } while (i < arg1);
    }
    return cur;
}

void *func_0209c658(M2C_UNK arg0) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 temp_r1;
    void *temp_r0;
    void *var_r0;

    temp_r0 = func_02099b18(arg0, 4, 1);
    if (temp_r0 != NULL) {
        temp_r1 = M2C_FIELD(temp_r0, u8 *, 1);
        var_r0 = temp_r0 + 1;
        if ((temp_r1 != 0xA) && (temp_r1 != 0xD)) {

        } else {
            var_r0 += 1;
        }
        return var_r0;
    }
    return NULL;
}

s32 func_0209c690(M2C_UNK arg0) {
    void *func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 temp_r1;

    temp_r0 = func_02099b18(arg0, 0x1d, 0);
    if (temp_r0 == 0) {
        goto fail;
    }
    temp_r1 = *(u8 *)((u8 *)temp_r0 + 1) & 0x7F;
    switch (temp_r1) {
    case 0:
    case 1:
    case 2:
    case 3:
        return temp_r1;
    default:
        break;
    }
fail:
    return 0;
}

void *GetCarriedUnitIcon(s32 arg0) {
 u8 result=(gCur3DSpriteEngine==g3DSpriteEngineMain);
 s32 flag=result!=1;
 u8 *base=gCarriedUnitIconTable;
 return base+(flag<<7)+(arg0<<2);
}

void SetCarriedUnitIconSprite(s32 arg0,s16 arg1,s8 arg2,s32 arg3,u8 arg4) {
 void *GetCarriedUnitIcon(s32);
 SpriteAttribute0209 *p=GetCarriedUnitIcon(arg0);
 p->value=arg1;p->mode=arg2;p->low=arg4;p->high=arg4;
}

/* Draw the icon of the unit carried in list slot `slot` at screen position
 * (x, y): look up the slot's icon record, size its sprite from the record's
 * width and height nibbles (in 8-pixel units), and add that sprite with
 * `tileBase`, the record's tile index shifted by the engine's display mode and
 * its palette, at `priority`. */
void DrawCarriedUnitIcon(s32 slot, s32 x, s32 y, s32 tileBase, s32 priority) {
    void *GetCarriedUnitIcon(s32);
    s32 GetSpriteDescForSize(s32, s32);
    void AddSprite(s32, s32, s32, s32, s32);
    extern M2C_UNK gCur3DSpriteEngine;
    u8 *icon = GetCarriedUnitIcon(slot);
    u8 size = icon[3];
    s32 sprite = GetSpriteDescForSize((u32)(size << 28) >> 25, ((u32)(size << 24) >> 28) << 3);
    if (sprite) {
        AddSprite(x, y, (u16)(tileBase | (1023 & (*(u16 *)icon >> ((u32)(***(u16 ***)(&gCur3DSpriteEngine) << 17) >> 30))) | ((u32)(icon[2] << 28) >> 16)), sprite, priority);
    }
}

#pragma opt_propagation off
void func_0209c7fc(void) {
 s32 i;
 SpriteStateWord *p;
 p=(SpriteStateWord *)data_0215d8a8; i=0;
 do {
 p->state=0;
 p->field3=0;
 p->field7=0;
 p->field17=0;
 p->field26=0;
 p->field29=0;
 p++; i++;
 } while(i<64);
 *(s32 *)((u8 *)&gSaveSlotSummary+8)=(*(s32 *)((u8 *)&gSaveSlotSummary+8)&~7)|1;
}
#pragma opt_propagation reset
void func_0209c868(void) {
s32 i;
SpriteStateWord *p;
p=(SpriteStateWord *)data_0215d8a8;
i=0;
do {
i++;
if(p->state==1)p->state=2;
if(p->state==3)p->state=4;
p->field26=p->field29;
p++;
}while(i<64);
}

void func_0209c8d4(void) {
    s32 GetActiveOverlay();
    s32 IsLinkSessionActive();
    M2C_UNK func_02086844(u16, M2C_UNK);
    M2C_UNK func_02086878(u16, M2C_UNK);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    s32 GetRatingRank();
    M2C_UNK func_020bf814(u16);
    s32 IsCoUnlocked(s32);
    s32 DidPlayerWin();
    s32 HasActiveHumanPlayer();
    s32 func_020d1b40();
    s32 func_020e4b54();
    extern M2C_UNK gCoState;
    extern M2C_UNK gCoPlayerSlots;
    extern s32 gSaveSlotSummary[2];
    extern s32 data_0215d8a8[58];
    extern u16 gMapConfig;
    extern void **data_027e0058;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r9;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r5;
    s32 var_r7;
    u16 temp_r8;
    u32 temp_r3_2;
    u32 var_r1;
    u8 temp_r11;

    temp_r11 = M2C_FIELD(&gCoState, u8 *, 4);
    temp_r8 = M2C_FIELD(*data_027e0058, u16 *, 0x5142);
    var_r7 = 0;
    temp_r9 = temp_r8 - 0xA1;
    do {
        if (IsCoUnlocked(var_r7) != 0) {
            var_r0 = M2C_FIELD(&gCoState, s32 *, 8) | (1 << var_r7);
        } else {
            var_r0 = M2C_FIELD(&gCoState, s32 *, 8) & (-1 ^ (1 << var_r7));
        }
        var_r7 += 1;
        M2C_FIELD(&gCoState, s32 *, 8) = var_r0;
    } while (var_r7 < 0xF);
    if (IsLinkSessionActive() == 0) {
        func_02086844(temp_r8, 1);
        if (DidPlayerWin() != 0) {
            if ((HasActiveHumanPlayer() != 0) && (func_020d1b40() == 0)) {
                AddRecordValue(0x1A, 1);
                func_02086878(temp_r8, 1);
            }
            switch (temp_r8) {                      /* switch 1; irregular */
            case 0xB1:                              /* switch 1 */
                AddRecordValue(0x1D, 1);
                break;
            case 0xBA:                              /* switch 1 */
                AddRecordValue(0x1E, 1);
                break;
            }
            if (!(((u32) (gMapConfig << 0x1D) >> 0x1D) & 0xFF)) {
                temp_r5 = data_0215d8a8[temp_r9];
                if ((u32) M2C_FIELD(&gCoState, u16 *, 6) >= (u32) ((u32) (temp_r5 << 6) >> 0x17)) {
                    temp_r3 = (((temp_r5 & ~0x78) | ((u32) (*(s32 *)((u8 *)&gCoPlayerSlots + (temp_r11 * 0xC)) << 0x1C) >> 0x19)) & 0xFC01FFFF) | ((u32) (M2C_FIELD(&gCoState, u16 *, 6) << 0x17) >> 6);
                    data_0215d8a8[temp_r9] = temp_r3;
                    temp_r3_2 = (temp_r3 & 0xFFFE007F) | ((u32) (M2C_FIELD(*data_027e0058, u16 *, 0x52A2) << 0x16) >> 0xF);
                    data_0215d8a8[temp_r9] = (temp_r3_2 & ~0x1C000000) | ((u32) ((temp_r3_2 >> 0x1D) << 0x1D) >> 3);
                    data_0215d8a8[temp_r9] = (data_0215d8a8[temp_r9] & ~0xE0000000) | (GetRatingRank() << 0x1D);
                }
                temp_r0 = data_0215d8a8[temp_r9];
                temp_r0_2 = temp_r0 & ~7;
                if ((u32) ((u32) (temp_r0 << 0x1D) >> 0x1D) < 3U) {
                    var_r0_2 = temp_r0_2 | 3;
                } else {
                    var_r0_2 = temp_r0_2 | 4;
                }
                data_0215d8a8[temp_r9] = var_r0_2;
                func_020bf814(temp_r8);
                if (func_020e4b54() != 0) {
                    var_r1 = (u32) (gSaveSlotSummary[0] << 8) >> 0x18;
                    if ((s32) var_r1 < 0xFF) {
                        var_r1 += 1;
                    }
                    gSaveSlotSummary[0] = (gSaveSlotSummary[0] & ~0xFF0000) | ((u32) (var_r1 << 0x18) >> 8);
                }
                switch (M2C_FIELD(&gCoState, u8 *, 3)) { /* switch 2 */
                default:                            /* switch 2 */
                    break;
                case 4:                             /* switch 2 */
                    AddRecordValue(2, 1);
                    break;
                case 3:                             /* switch 2 */
                    AddRecordValue(3, 1);
                    break;
                case 2:                             /* switch 2 */
                    AddRecordValue(4, 1);
                    break;
                case 1:                             /* switch 2 */
                    AddRecordValue(5, 1);
                    break;
                }
            }
        }
    }
    var_r5 = 0;
    do {
        if (!(M2C_FIELD(&gCoState, s32 *, 8) & (1 << var_r5)) && (IsCoUnlocked(var_r5) != 0)) {
            M2C_FIELD(&gCoState, s32 *, 8) = (s32) (M2C_FIELD(&gCoState, s32 *, 8) | (1 << var_r5));
        } else {
            M2C_FIELD(&gCoState, s32 *, 8) = (s32) (M2C_FIELD(&gCoState, s32 *, 8) & (-1 ^ (1 << var_r5)));
        }
        var_r5 += 1;
    } while (var_r5 < 0xF);
    temp_r0_3 = GetActiveOverlay();
    switch (temp_r0_3) {                            /* switch 3; irregular */
    case 1:                                         /* switch 3 */
        AddRecordValue(0x21, 1);
        return;
    case 2:                                         /* switch 3 */
        AddRecordValue(0x20, 1);
        return;
    }
}

#pragma opt_propagation reset
void IncrementCounter(u32 *arg0) {
    u32 temp_r2;

    temp_r2 = *arg0 + 1;
    if (temp_r2 >= 0x0CDFE5C4U) {
        *arg0 = 0x0CDFE5C4;
        return;
    }
    *arg0 = temp_r2;
}

