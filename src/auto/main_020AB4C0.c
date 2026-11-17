/* 29 functions from 0x020AA93C to 0x020AB884 (main), found by ds-decomp. */
#include "common.h"
#include "list_widget.h"
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } UnkAAFields;

void ListWidgetScrollUp(void *arg0) {
    s32 Divide(s16, s16);
    M2C_UNK ListWidgetScrollBy(void *, s16, M2C_UNK, M2C_UNK);
    M2C_UNK UpdateListScroll(void *);
    s32 var_r4;
    s16 temp_r4;
    s16 temp_r6;
    s32 temp_r0;

    var_r4 = 0;
    if ((s16)Divide(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8)) > 0) {
        var_r4 = (M2C_FIELD(arg0, s16 *, 6) <= (s16)Divide((s16)M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg0, s16 *, 8)));
    }
    if (!(var_r4 & 0xFF)) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16)(M2C_FIELD(arg0, s16 *, 0xC) - M2C_FIELD(arg0, s16 *, 8));
    ListWidgetScrollBy(arg0, (s16)(0 - M2C_FIELD(arg0, s16 *, 8)), 0, 0);
    UpdateListScroll(arg0);
    temp_r0 = M2C_FIELD(arg0, u8 *, 0xA) * (s16)Divide(M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 8));
    M2C_FIELD(arg0, s16 *, 0x28) = 0;
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16)(0 - temp_r0);
    temp_r4 = M2C_FIELD(arg0, s16 *, 0x2A);
    temp_r6 = M2C_FIELD(arg0, s16 *, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x3E) = GetSpriteAnimValue(arg0 + 0x30);
    M2C_FIELD(arg0, s16 *, 0x40) = temp_r4;
    M2C_FIELD(arg0, s16 *, 0x3C) = temp_r6;
    M2C_FIELD(arg0, u16 *, 0x32) = (u16)M2C_FIELD(arg0, u16 *, 0x34);
}

/* Move the cursor down one row when another row is visible below it, scroll the
 * window by one row and retarget its slide tween to the new row's pixel offset. */
void ListWidgetScrollDown(void *arg0) {
    s32 Divide(s16, s16);
    M2C_UNK ListWidgetScrollBy(void *, s16, M2C_UNK, M2C_UNK);
    M2C_UNK UpdateListScroll(void *);
    M2C_UNK GetSpriteAnimValue(void *);
    s16 targetY;
    s32 visibleRows;
    s16 frames;
    s32 pixOffset;
    s16 currentRow;
    s32 canScroll;

    visibleRows = M2C_FIELD(arg0, s16 *, LIST_WIDGET_VISIBLE_ROWS);
    currentRow = Divide(M2C_FIELD(arg0, s16 *, LIST_WIDGET_CURSOR), M2C_FIELD(arg0, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
    if ((s32)(visibleRows + currentRow) < (s32)((s16)Divide((s16)M2C_FIELD(arg0, s32 *, LIST_WIDGET_SCROLL_MAX), M2C_FIELD(arg0, s16 *, LIST_WIDGET_ITEMS_PER_ROW)) + 1)) {
        canScroll = 1;
    } else {
        canScroll = 0;
    }
    if (!(canScroll & 0xFF)) return;
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_CURSOR) = (s16)(M2C_FIELD(arg0, s16 *, LIST_WIDGET_CURSOR) + M2C_FIELD(arg0, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
    ListWidgetScrollBy(arg0, M2C_FIELD(arg0, s16 *, LIST_WIDGET_ITEMS_PER_ROW), 0, 0);
    UpdateListScroll(arg0);
    pixOffset = M2C_FIELD(arg0, u8 *, LIST_WIDGET_ROW_HEIGHT) * (s16)Divide(M2C_FIELD(arg0, s16 *, LIST_WIDGET_CURSOR), M2C_FIELD(arg0, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_OFFSET_X) = 0;
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_SLIDE_TARGET_Y) = (s16)(0 - pixOffset);
    targetY = M2C_FIELD(arg0, s16 *, LIST_WIDGET_SLIDE_TARGET_Y);
    frames = M2C_FIELD(arg0, s16 *, LIST_WIDGET_SCROLL_FRAMES);
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_SCROLL_FROM) = GetSpriteAnimValue(arg0 + 0x30);
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_SCROLL_TO) = targetY;
    M2C_FIELD(arg0, s16 *, LIST_WIDGET_SCROLL_FRAMES) = frames;
    M2C_FIELD(arg0, u16 *, LIST_WIDGET_SCROLL_CURRENT) = (u16)M2C_FIELD(arg0, u16 *, LIST_WIDGET_SCROLL_START);
}

s32 ListWidgetScrollBy(void *arg0, s16 arg1, s32 flag, s32 arg3) {
    s16 oldHeight = (s16)M2C_FIELD(arg0, s32 *, 0x14);
    s16 row = (s16)(arg1 + oldHeight);
    s16 c0 = Divide(oldHeight, M2C_FIELD(arg0, s16 *, 0x8));
    s32 maxRow = M2C_FIELD(arg0, s32 *, 0x18);

    if (maxRow < row) {
        s16 saved = Divide(
            (s16)maxRow, M2C_FIELD(arg0, s16 *, 0x8));
        s16 sec = Divide(
            (s16)(row - arg1), M2C_FIELD(arg0, s16 *, 0x8));

        if (sec < saved) {
            row = (s16)maxRow;
        }
    }

    if (flag == 0) {
        if (func_020a8c3c(
                row,
                M2C_FIELD(arg0, s32 *, 0x1c),
                M2C_FIELD(arg0, s32 *, 0x18)) == 0) {
            row = oldHeight;
        }
    }

    maxRow = M2C_FIELD(arg0, s32 *, 0x18);

    if (Modulo((s16)maxRow, M2C_FIELD(arg0, s16 *, 0x8))
        != M2C_FIELD(arg0, s16 *, 0x8) - 1) {
        if (row < 0) {
            s16 newRow = (s16)(row + maxRow + 1);
            s16 t1 = Divide(
                (s16)maxRow, M2C_FIELD(arg0, s16 *, 0x8));
            s16 t2 = Divide(
                newRow, M2C_FIELD(arg0, s16 *, 0x8));

            if (t2 == t1) {
                row = newRow;
            } else {
                row = (s16)maxRow;
            }
        }
    }

    maxRow = M2C_FIELD(arg0, s32 *, 0x18);
    if (row > maxRow) {
        row = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = row;

    if (M2C_FIELD(arg0, u8 *, 0x24) != 0) {
        s32 minRow;
        s32 value;

        maxRow = M2C_FIELD(arg0, s32 *, 0x18);
        value = M2C_FIELD(arg0, s32 *, 0x14);

        while (value > maxRow) {
            minRow = M2C_FIELD(arg0, s32 *, 0x1c);
            value -= maxRow - minRow + 1;
            M2C_FIELD(arg0, s32 *, 0x14) = value;
        }

        minRow = M2C_FIELD(arg0, s32 *, 0x1c);
        if (value < minRow) {
            do {
                value += maxRow - minRow + 1;
                M2C_FIELD(arg0, s32 *, 0x14) = value;
                minRow = M2C_FIELD(arg0, s32 *, 0x1c);
            } while (value < minRow);
        }
    } else {
        s32 value = M2C_FIELD(arg0, s32 *, 0x14);
        s32 maximum = M2C_FIELD(arg0, s32 *, 0x18);

        if (value <= maximum) {
            s32 minimum = M2C_FIELD(arg0, s32 *, 0x1c);
            if (value < minimum) {
                value = minimum;
            }
            M2C_FIELD(arg0, s32 *, 0x14) = value;
        }
    }

    if (c0 != (s16)Divide(
            (s16)M2C_FIELD(arg0, s32 *, 0x14),
            M2C_FIELD(arg0, s16 *, 0x8))) {
        M2C_FIELD(arg0, u8 *, 0x4) = (u8)arg3;
    }

    UpdateListScroll(arg0);
}

