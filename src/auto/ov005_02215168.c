/* 11 functions from 0x02215168 to 0x02215664 (ov005), found by ds-decomp. */
#include "common.h"
#include "sound.h"

#define RECORDS_SCREEN ((RecordsScreen *)M2C_FIELD(&gRecordsMenuState, void **, 8))

/* Records screen D-pad down.  On tab 0 (the full list) move the highlight one
 * record down, skipping locked records and wrapping at the end of the record
 * table returned by RecordsMenu_GetRecord; tabs 1 and 2 step their enabled-only and
 * shuffled lists instead. */
void RecordsMenu_SelectNext(s16 record) {
 void *RecordsMenu_GetRecord(s32);
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_BeginAction(s32,s32);
 void RecordsMenu_SelectNextEnabled(s16);
 void RecordsMenu_SelectNextInList(s16);
 extern M2C_UNK gRecordsMenuState;
 switch (RECORDS_SCREEN->tab) {
 case 0:
 RECORDS_SCREEN->highlighted = record;
 do {
 record++;
 if (*(s32 *)RecordsMenu_GetRecord(record) == 0) {
 record = RECORDS_SCREEN->highlighted;
 break;
 }
 } while (!RecordsMenu_IsRecordAvailable(record));
 RecordsMenu_BeginAction(record, 1); break;
 case 1: RecordsMenu_SelectNextEnabled(record); break;
 case 2: RecordsMenu_SelectNextInList(record); break;
 }
}

/* Records screen D-pad up on the enabled-only tab: step the highlight to the
 * previous enabled record, wrapping back to the last one, and begin the action
 * when an enabled record is reached. */
void RecordsMenu_SelectPreviousEnabled(s16 record) {
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_BeginAction(s32,s32);
 extern M2C_UNK gRecordsMenuState;
 s16 i=record;
 do {
 if (--i < 0) i=RECORDS_SCREEN->count-1;
 if (RecordsMenu_IsRecordAvailable(i) && RECORDS_SCREEN->enabled[i]==1) {
 RecordsMenu_BeginAction(i,1); return;
 }
 } while (i!=record);
}

/* Records screen D-pad down on the enabled-only tab: step the highlight to the
 * next enabled record, wrapping back to the first one, and begin the action when
 * an enabled record is reached. */
void RecordsMenu_SelectNextEnabled(s16 record) {
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_BeginAction(s32,s32);
 extern M2C_UNK gRecordsMenuState;
 s16 i = record;
 do {
 if (++i >= RECORDS_SCREEN->count) i = 0;
 if (RecordsMenu_IsRecordAvailable(i) && RECORDS_SCREEN->enabled[i] == 1) {
 RecordsMenu_BeginAction(i, 1); return;
 }
 } while (i != record);
}

/* Records screen D-pad up on the shuffled-list tab: step the list cursor back one
 * entry, wrapping to the last entry (reshuffling the list first), and begin the
 * action for the record it points at. */
void RecordsMenu_SelectPreviousInList(void) {
 void RecordsMenu_ShuffleList(s32);
 void RecordsMenu_BeginAction(s32,s32);
 extern M2C_UNK gRecordsMenuState;
 if (RECORDS_SCREEN->listCount == 0) return;
 RECORDS_SCREEN->listCursor--;
 if (RECORDS_SCREEN->listCursor < 0) {
 RecordsMenu_ShuffleList(-1);
 RECORDS_SCREEN->listCursor = RECORDS_SCREEN->listCount - 1;
 }
 RecordsMenu_BeginAction(RECORDS_SCREEN->list[RECORDS_SCREEN->listCursor], 1);
}

/* Records screen D-pad down on the shuffled-list tab: step the list cursor to the
 * next entry, wrapping to the first entry (reshuffling the list first), and begin
 * the action for the record it points at. */
void RecordsMenu_SelectNextInList(s16 record) {
 void RecordsMenu_ShuffleList(s32);
 void RecordsMenu_BeginAction(s32,s32);
 extern M2C_UNK gRecordsMenuState;
 if (RECORDS_SCREEN->listCount == 0) return;
 RECORDS_SCREEN->listCursor++;
 if (RECORDS_SCREEN->listCursor >= RECORDS_SCREEN->listCount) {
 RecordsMenu_ShuffleList(-1);
 RECORDS_SCREEN->listCursor = 0;
 }
 RecordsMenu_BeginAction(RECORDS_SCREEN->list[RECORDS_SCREEN->listCursor],1);
}

void func_ov005_022153d4(u8 *arg0) {
 M2C_UNK FocusSpriteSlotById(s32);
 extern M2C_UNK gRecordsMenuState;
 s32 value = M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x94);
 if (value == *arg0) return;
 FocusSpriteSlotById(value);
}

/* D-pad navigation of the records screen's list: move the row cursor up or down
 * (wrapping at the ends and scrolling/paging the six-row window with left and
 * right), then focus the new row and store it as the cursor row. `selected`
 * points at the current row index. */
void RecordsMenu_HandleDPad(u8 *selected) {
    s32 FindSpriteSlotById(s32);
    M2C_UNK FocusSpriteSlotById(s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 RecordsMenu_ScrollUp(void);
    s32 RecordsMenu_ScrollDown(void);
    s16 RecordsMenu_PageUp(void);
    s16 RecordsMenu_PageDown(void);
    extern M2C_UNK gRecordsMenuState;
    extern u16 *gKeyState;

    s32 max, pos, delta;
    u16 *keys;
    RecordsScreen *screen = M2C_FIELD(&gRecordsMenuState, RecordsScreen **, 8);
    s32 row = *selected;
    max = screen->count;
    pos = screen->scroll;
    max -= 6;
    if (max < 0) max = 0;

    if (pos == 0 && row == 0) {
        if ((keys = gKeyState)[KEY_HELD] & KEY_UP) {
            screen->scroll = (s16)max;
            row = 5;
            goto done;
        }
    } else if ((keys = gKeyState)[KEY_PRESSED] & KEY_UP) {
        if (row >= 2) row--;
        else if (!RecordsMenu_ScrollUp() && row) row--;
        goto done;
    }

    if (pos == max && row == 5) {
        if (keys[KEY_HELD] & KEY_DOWN) {
            row = 0;
            screen->scroll = 0;
            goto done;
        }
    } else if (keys[KEY_PRESSED] & KEY_DOWN) {
        if (row < 4) {
            if (FindSpriteSlotById(row + 1)) row++;
        } else if (!RecordsMenu_ScrollDown()) {
            if (FindSpriteSlotById(row + 1)) row++;
        }
        goto done;
    }

    if (keys[KEY_PRESSED] & KEY_LEFT) {
        delta = RecordsMenu_PageUp();
        row -= delta + 6;
        if (row < 0) row = 0;
        if (delta != 0) {
            if (row == *selected) PlaySoundEffect(SOUND_MENU_SELECT);
        }
    } else if (keys[KEY_PRESSED] & KEY_RIGHT) {
        delta = RecordsMenu_PageDown();
        row += 6 - delta;
        if (row >= 6) row = 5;
        if (delta != 0) {
            if (row == *selected) PlaySoundEffect(SOUND_MENU_SELECT);
        }
    }

done:
    if (row != *selected) FocusSpriteSlotById(row);
    RECORDS_SCREEN->cursorRow = row;
}

/* Records row pick: select the record shown in touched row `row` (the list's
 * top visible row plus the row index). */
void RecordsMenu_PickRow(u8 *row) {
    void RecordsMenu_HandlePick(s16);
    extern M2C_UNK gRecordsMenuState;

    RecordsMenu_HandlePick((s16)(RECORDS_SCREEN->scroll + *row));
}

/* Select the records-screen row named by `row`: store it as the cursor row and
 * play the select sound. */
void RecordsMenu_SelectRow(u8 *row) {
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gRecordsMenuState;
    RECORDS_SCREEN->cursorRow = (s16) *row;
    PlaySoundEffect(SOUND_MENU_SELECT);
}

/* Toggle the enabled flag of the record shown in the touched row and refresh the
 * records list and its shuffled enabled list. */
void RecordsMenu_ToggleRecordEnabled(u8 *row) {
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_DrawList(s32);
 void RecordsMenu_ShuffleList(s32);
 extern M2C_UNK gRecordsMenuState;
 u8 *enabled;
 s32 record=RECORDS_SCREEN->scroll+*row;
 if (!RecordsMenu_IsRecordAvailable(record)) return;
 enabled=RECORDS_SCREEN->enabled;
 enabled[record] = enabled[record] == 0 ? 1 : 0;
 RecordsMenu_DrawList(RECORDS_SCREEN->scrollGoal);
 RecordsMenu_ShuffleList(-1);
}

void func_ov005_02215650(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov005_02220510;
    FindObjectByClass(&data_ov005_02220510);
}
