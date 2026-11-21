/* 11 functions from 0x02215168 to 0x02215664 (ov005), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk_0x0[0xa2];
    u8 unk_0xa2[1];
} UnkOv005Selection;

#define RECORDS_SCREEN ((RecordsScreen *)M2C_FIELD(&gRecordsMenuState, void **, 8))

/* Records screen D-pad down.  On tab 0 (the full list) move the highlight one
 * record down, skipping locked records and wrapping at the end of the record
 * table returned by func_020ad570; tabs 1 and 2 step their enabled-only and
 * shuffled lists instead. */
void RecordsMenu_SelectNext(s16 record) {
 void *func_020ad570(s32);
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
 if (*(s32 *)func_020ad570(record) == 0) {
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

void func_ov005_022153fc(u8 *a) {
    s32 FindSpriteSlotById(s32);
    M2C_UNK FocusSpriteSlotById(s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 func_ov005_02214148(void);
    s32 func_ov005_022141cc(void);
    s16 func_ov005_02214184(void);
    s16 func_ov005_02214210(void);
    extern M2C_UNK gRecordsMenuState;
    extern u16 *gKeyState;

    s32 max, pos, delta;
    void *p = M2C_FIELD(&gRecordsMenuState, void **, 8);
    s32 n = *a;
    max = M2C_FIELD(p, s16 *, 0x9a);
    pos = M2C_FIELD(p, s16 *, 0x98);
    max -= 6;
    if (max < 0) max = 0;

    if (pos == 0 && n == 0) {
        if (gKeyState[0] & 0x40) {
            M2C_FIELD(p, s16 *, 0x98) = (s16)max;
            n = 5;
            goto done;
        }
    } else if (gKeyState[1] & 0x40) {
        if (n >= 2) n--;
        else if (!func_ov005_02214148() && n) n--;
        goto done;
    }

    if (pos == max && n == 5) {
        if (gKeyState[0] & 0x80) {
            n = 0;
            M2C_FIELD(p, s16 *, 0x98) = 0;
            goto done;
        }
    } else if (gKeyState[1] & 0x80) {
        if (n < 4) {
            if (FindSpriteSlotById(n + 1)) n++;
        } else if (!func_ov005_022141cc()) {
            if (FindSpriteSlotById(n + 1)) n++;
        }
        goto done;
    }

    if (gKeyState[1] & 0x20) {
        delta = func_ov005_02214184();
        n -= delta + 6;
        if (n < 0) n = 0;
        if (delta != 0) {
            if (n == *a) PlaySoundEffect(0x10019);
        }
    } else if (gKeyState[1] & 0x10) {
        delta = func_ov005_02214210();
        n += 6 - delta;
        if (n >= 6) n = 5;
        if (delta != 0) {
            if (n == *a) PlaySoundEffect(0x10019);
        }
    }

done:
    if (n != *a) FocusSpriteSlotById(n);
    M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x94) = n;
}

void func_ov005_02215594(u8 *arg0) {
 void RecordsMenu_HandlePick(s16);
 extern M2C_UNK gRecordsMenuState;
 RecordsMenu_HandlePick((s16)(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+*arg0));
}

void func_ov005_022155c0(u8 *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK gRecordsMenuState;
    M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x94) = (s16) *arg0;
    PlaySoundEffect(0x10019);
}

void func_ov005_022155e8(u8 *arg0) {
 s32 RecordsMenu_IsRecordAvailable(s32);
 void RecordsMenu_DrawList(s32);
 void RecordsMenu_ShuffleList(s32);
 extern M2C_UNK gRecordsMenuState;
 u8 *flags;
 s32 i=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+*arg0;
 if (!RecordsMenu_IsRecordAvailable(i)) return;
 flags=((UnkOv005Selection *)M2C_FIELD(&gRecordsMenuState,void **,8))->unk_0xa2;
 flags[i] = flags[i] == 0 ? 1 : 0;
 RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));
 RecordsMenu_ShuffleList(-1);
}

void func_ov005_02215650(void) {
    M2C_UNK FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov005_02220510;
    FindObjectByClass(&data_ov005_02220510);
}
