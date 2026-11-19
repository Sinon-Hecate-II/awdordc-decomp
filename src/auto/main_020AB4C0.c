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

#pragma push
#pragma opt_common_subs off
/* Scroll the list's first-visible index by `delta` items, re-anchoring it to the
 * last row when the move would pass the end of a partial row, then wrap it around
 * [min,max] or clamp it, per the widget's wrap flag.  A move into a new row arms
 * the widget's pending-move flag with `direction`. */
s32 ListWidgetScrollBy(void *widget, s16 delta, s32 force, s32 direction) {
    s16 oldScroll, oldRow, nextScroll;
    s32 max;

    oldScroll = (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL);
    nextScroll = (s16)(delta + oldScroll);
    oldRow = (s16)Divide(oldScroll, M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
    max = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);

    if (max < nextScroll) {
        s16 maxRow = (s16)Divide((s16)max, M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
        s16 previousRow = (s16)Divide((s16)(nextScroll - delta), M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
        if (previousRow < maxRow) {
            nextScroll = (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
            goto setScroll;
        }
    }
    if (force == 0 && IsIndexInRange(nextScroll, (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MIN),
                                    (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX)) == 0) {
        nextScroll = (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL);
        goto setScroll;
    }
    if ((s16)Modulo((s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX),
                    M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW)) !=
        M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW) - 1) {
        if (nextScroll < 0) {
            s16 maxRow, wrappedRow;
            max = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
            nextScroll = (s16)(nextScroll + max + 1);
            maxRow = (s16)Divide((s16)max, M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
            wrappedRow = (s16)Divide(nextScroll, M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW));
            if (wrappedRow != maxRow) {
                nextScroll = (s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
            }
        } else if (nextScroll > M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX)) {
            nextScroll = 0;
        }
    }

setScroll:
    M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) = nextScroll;
    if (M2C_FIELD(widget, u8 *, LIST_WIDGET_WRAP) != 0) {
        s32 bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
        s32 value = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL);
        if (value > bound) {
            do {
                s32 start = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MIN);
                value = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) - (bound - start + 1);
                M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) = value;
                bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
            } while (value > bound);
        }
        bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MIN);
        if (value < bound) {
            do {
                s32 end = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
                value = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) + (end - bound + 1);
                M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) = value;
                bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MIN);
            } while (value < bound);
        }
    } else {
        s32 bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MAX);
        s32 value = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL);
        if (value <= bound) {
            bound = M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL_MIN);
            if (value >= bound) {
                bound = value;
            }
        }
        M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL) = bound;
    }
    if (oldRow != (s16)Divide((s16)M2C_FIELD(widget, s32 *, LIST_WIDGET_SCROLL),
                              M2C_FIELD(widget, s16 *, LIST_WIDGET_ITEMS_PER_ROW))) {
        M2C_FIELD(widget, u8 *, LIST_WIDGET_PENDING) = (u8)direction;
    }
    UpdateListScroll(widget);
}
#pragma pop
