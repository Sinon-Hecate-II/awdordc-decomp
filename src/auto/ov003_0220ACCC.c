/* 13 functions from 0x0220ACCC to 0x0220BCAC (ov003), found by ds-decomp. */
#include "common.h"
#include "ov003_menu.h"
#include "sound.h"

/* Configures the path entries for the selected table index, using the simple path for 0/1 entries. */
void func_ov003_0220accc(void *obj, s32 index) {
    extern u8 gUnitListLayouts[];
    extern u8 data_ov003_02210a4c[];

    void *table = gUnitListLayouts + index * 16;
    void *state;
    u8 count;
    u8 i;
    s32 active;

    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 8) = M2C_FIELD(table, u8 *, 2);
    state = M2C_FIELD(obj, void **, 0x58);
    count = M2C_FIELD(state, u8 *, 8);

    if (count <= 1U) {
        goto simple;
    }

    if (M2C_FIELD(M2C_FIELD(obj, void **, 0x3C), u8 *, 15) == 8) {
        active = 1;
    } else {
        active = 0;
    }

    if (active & 255) {
    simple:
        M2C_FIELD(state, u8 *, 0) = 0;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 8) = 1;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 4) = 0xC0;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 6) = 6;
        return;
    }

    for (i = 0; i < count; i++) {
        M2C_FIELD(state + i * 4, void **, 12) = data_ov003_02210a4c + M2C_FIELD(table + i, u8 *, 3) * 8;
        state = M2C_FIELD(obj, void **, 0x58);
        count = M2C_FIELD(state, u8 *, 8);
    }

    M2C_FIELD(state, u8 *, 1) = 0;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 0) = 1;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 4) = 0xA0;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 6) = -4;
}

/* Handle one frame of the unit-list menu's input (up/down pick a row, left/right
 * step its option, A/Start confirms, B backs out, Y resets), pass touches to the
 * two scroll bars and the list, and start the row animation for the new row. */
void Ov003_HandleMenuInput(void *menu) {
#pragma opt_common_subs off
extern void *gKeyState,*gTouchState;
u8 Ov003_GetSelectedRowIndex(void *);
s16 ScrollBar_GetValue(void *);
void Ov003_AnimateUnitListButtons(void *);
u8 IsMenuSplitPairRow0(void *,s32);
u8 IsMenuSplitPairRow1(void *,s32);
u8 IsMenuSplitOptionRow(void *,s32);
void ScrollBar_ScrollBy(void *,s32);
void Ov003_StepOptionCounter0(void *,s32);
void Ov003_StepOptionCounter1(void *,s32);
void ScrollA9SliderBy(void *,s32);
void MarkMenuSplitSelection(void *);
void func_ov003_0220bbcc(void *);
s32 row,musicStart,sfxStart,active,touchRow,oldRow;u16 repeat,pressed;
if(!((u32)(M2C_FIELD(menu,u8 *,MENU_FLAGS)<<31)>>31))return;
row=Ov003_GetSelectedRowIndex(menu);
musicStart=ScrollBar_GetValue(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER));
sfxStart=ScrollBar_GetValue(M2C_FIELD(menu,void **,MENU_SFX_SLIDER));
active=1;
Ov003_AnimateUnitListButtons(M2C_FIELD(menu,void **,MENU_BUTTONS));
repeat=M2C_FIELD(gKeyState,u16 *,2);pressed=M2C_FIELD(gKeyState,u16 *,0);
if((((repeat&KEY_UP)&&row!=0)||(pressed&KEY_UP))&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)) {
if(row==0){if(pressed&KEY_UP)row=M2C_FIELD(M2C_FIELD(menu,void **,MENU_ROW_GROUP),u8 *,MENU_ROW_GROUP_COUNT)-1;else row=Ov003_GetSelectedRowIndex(menu);}else row--;
}else if((((repeat&KEY_DOWN)&&row!=M2C_FIELD(M2C_FIELD(menu,void **,MENU_ROW_GROUP),u8 *,MENU_ROW_GROUP_COUNT)-1)||(pressed&KEY_DOWN))&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)){
if(row==M2C_FIELD(M2C_FIELD(menu,void **,MENU_ROW_GROUP),u8 *,MENU_ROW_GROUP_COUNT)-1){if(pressed&KEY_DOWN)row=0;else row=Ov003_GetSelectedRowIndex(menu);}else row++;
}
repeat=M2C_FIELD(gKeyState,u16 *,2);
if((repeat&KEY_LEFT)&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)){
if(IsMenuSplitPairRow0(menu,(u8)row))ScrollBar_ScrollBy(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER),-8);
if(IsMenuSplitPairRow1(menu,(u8)row))ScrollBar_ScrollBy(M2C_FIELD(menu,void **,MENU_SFX_SLIDER),-8);
if(Ov003_IsSplitRow(menu,(u8)row)){PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_LEFT));if(IsMenuSplitCounter0Row(menu,(u8)row))Ov003_StepOptionCounter0(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);if(IsMenuSplitCounter1Row(menu,(u8)row))Ov003_StepOptionCounter1(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);if(IsMenuSplitCounter2Row(menu,(u8)row))ScrollA9SliderBy(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);}
if(IsMenuSplitOptionRow(menu,(u8)row))PlaySoundEffect(SOUND_MENU_CHANGE);
MarkMenuSplitSelection(menu);
}
else if((repeat&KEY_RIGHT)&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)){
if(IsMenuSplitPairRow0(menu,(u8)row))ScrollBar_ScrollBy(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER),8);
if(IsMenuSplitPairRow1(menu,(u8)row))ScrollBar_ScrollBy(M2C_FIELD(menu,void **,MENU_SFX_SLIDER),8);
if(Ov003_IsSplitRow(menu,(u8)row)){PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_RIGHT));if(IsMenuSplitCounter0Row(menu,(u8)row))Ov003_StepOptionCounter0(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);if(IsMenuSplitCounter1Row(menu,(u8)row))Ov003_StepOptionCounter1(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);if(IsMenuSplitCounter2Row(menu,(u8)row))ScrollA9SliderBy(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);}
if(IsMenuSplitOptionRow(menu,(u8)row))PlaySoundEffect(SOUND_MENU_CHANGE);
MarkMenuSplitSelection(menu);
}

if((M2C_FIELD(gKeyState,u16 *,0)&KEY_Y)&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)){
if(Ov003_IsSplitRowMode(menu)&&IsMenuAtRootMode(menu))func_ov003_0220bbcc(menu);active=0;
}
if(active&&(M2C_FIELD(gKeyState,u16 *,0)&KEY_SELECT)&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)){
if(Ov003_IsSplitRowMode(menu)){PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_RESET));func_ov003_0220bcac(menu);PlaySoundEffect(SOUND_MENU_CONFIRM);MarkMenuSplitSelection(menu);}
if(Ov003_IsCampaignSaveSlotMode(menu)){
if(CampaignSaveSlotInUse(row)){RequestMenuMode(menu,2);PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU));CreateCampaignSaveSlotPanel(row,menu);PlaySoundEffect(SOUND_MENU_CONFIRM);}
else PlaySoundEffect(SOUND_MENU_DENIED);
} active=0;
}
if(row!=Ov003_GetSelectedRowIndex(menu)){SpriteCellListSelectTile(M2C_FIELD(menu,void **,MENU_SELECTED_UNIT),(s16)(row+11));PlaySoundEffect(SOUND_MENU_MOVE);}
ScrollBar_HandleTouch(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER));
if(!ScrollBar_IsGrabbed(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER)))ScrollBar_HandleTouch(M2C_FIELD(menu,void **,MENU_SFX_SLIDER));
if(ScrollBar_IsGrabbed(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER))&&!IsMenuSplitPairRow0(menu,Ov003_GetSelectedRowIndex(menu)))SpriteCellListSelectTile(M2C_FIELD(menu,void **,MENU_SELECTED_UNIT),11);
if(ScrollBar_IsGrabbed(M2C_FIELD(menu,void **,MENU_SFX_SLIDER))&&!IsMenuSplitPairRow1(menu,Ov003_GetSelectedRowIndex(menu)))SpriteCellListSelectTile(M2C_FIELD(menu,void **,MENU_SELECTED_UNIT),12);
if(!ScrollBar_IsGrabbed(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER))&&!ScrollBar_IsGrabbed(M2C_FIELD(menu,void **,MENU_SFX_SLIDER)))SpriteCellListUpdateTouch(M2C_FIELD(menu,void **,MENU_SELECTED_UNIT));
oldRow=Ov003_GetSelectedRowIndex(menu);touchRow=func_ov003_0220bf68(M2C_FIELD(menu,void **,MENU_SELECTED_UNIT));
if((active&&(M2C_FIELD(gKeyState,u16 *,0)&(KEY_A|KEY_START))&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))||oldRow==touchRow-11){Ov003_ActivateUnitListEntry(menu,(u16)oldRow);active=0;}
else if((active&&(M2C_FIELD(gKeyState,u16 *,0)&KEY_B)&&!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))||MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_CONFIRM))){
PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_CONFIRM));Ov003_ConfirmRowValue(menu,(u16)oldRow);PlaySoundEffect(SOUND_MENU_CANCEL);active=0;
}else if(active&&IsMenuAtRootMode(menu)&&MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_BACK))){
if(Ov003_IsSplitRowMode(menu))func_ov003_0220bbcc(menu);active=0;
}else if(active&&MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_RESET))){
if(Ov003_IsSplitRowMode(menu)){PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_RESET));func_ov003_0220bcac(menu);PlaySoundEffect(SOUND_MENU_CONFIRM);MarkMenuSplitSelection(menu);}active=0;
}
if(Ov003_IsCampaignSaveSlotMode(menu)){if(CampaignSaveSlotInUse(oldRow))EnableMenuSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU));else DisableMenuSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU));}
if(active&&IsMenuEnabled(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU))&&MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU))){
if(Ov003_IsCampaignSaveSlotMode(menu)){RequestMenuMode(menu,2);PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_SUBMENU));CreateCampaignSaveSlotPanel(oldRow,menu);PlaySoundEffect(SOUND_MENU_CONFIRM);}active=0;
}
if(active&&touchRow>=3&&touchRow<=M2C_FIELD(M2C_FIELD(menu,void **,OV003_MENU_HELP_PANEL),u8 *,8)+2){
Ov003_SetRowAnimation(menu,M2C_FIELD(M2C_FIELD(M2C_FIELD(menu,void **,OV003_MENU_HELP_PANEL)+(touchRow-3)*4,void **,12),u8 *,4));
M2C_FIELD(menu,u8 *,MENU_ACTION)=30;Ov003_RefreshListRowAnimations(menu,5,255);Ov003_ClearSubSpriteLayer1(menu);PlaySoundEffect(SOUND_MENU_CANCEL);active=0;
}
if(active&&MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_LEFT))){
PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_LEFT));
if(IsMenuSplitCounter0Row(menu,(u8)oldRow))Ov003_StepOptionCounter0(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);if(IsMenuSplitCounter1Row(menu,(u8)oldRow))Ov003_StepOptionCounter1(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);if(IsMenuSplitCounter2Row(menu,(u8)oldRow))ScrollA9SliderBy(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),-1);if(IsMenuSplitOptionRow(menu,(u8)oldRow))PlaySoundEffect(SOUND_MENU_CHANGE);MarkMenuSplitSelection(menu);}
if(active&&MenuSpriteIsClicked(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_RIGHT))){
PressWaypointSprite(M2C_FIELD(M2C_FIELD(menu,void **,MENU_BUTTONS),void **,MENU_BUTTON_STEP_RIGHT));
if(IsMenuSplitCounter0Row(menu,(u8)oldRow))Ov003_StepOptionCounter0(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);if(IsMenuSplitCounter1Row(menu,(u8)oldRow))Ov003_StepOptionCounter1(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);if(IsMenuSplitCounter2Row(menu,(u8)oldRow))ScrollA9SliderBy(M2C_FIELD(menu,void **,MENU_OPTION_COUNTERS),1);if(IsMenuSplitOptionRow(menu,(u8)oldRow))PlaySoundEffect(SOUND_MENU_CHANGE);MarkMenuSplitSelection(menu);}

if(musicStart!=ScrollBar_GetValue(M2C_FIELD(menu,void **,MENU_MUSIC_SLIDER))){PlaySoundEffect(SOUND_MENU_CHANGE);MarkMenuSplitSelection(menu);}
if(sfxStart!=ScrollBar_GetValue(M2C_FIELD(menu,void **,MENU_SFX_SLIDER))){PlaySoundEffect(SOUND_MENU_CHANGE);MarkMenuSplitSelection(menu);}
M2C_FIELD(menu,u8 *,MENU_MODE_HI)=(M2C_FIELD(menu,u8 *,MENU_MODE_HI)&~0xf0)|((u32)((u8)oldRow<<28)>>24);
if(!((u32)(M2C_FIELD(menu,u8 *,MENU_FLAGS)<<26)>>31)){
if(((u32)(M2C_FIELD(menu,u8 *,MENU_MODE_HI)<<28)>>28)==((u32)(M2C_FIELD(menu,u8 *,MENU_MODE_HI)<<24)>>28))return;
}
Ov003_ApplyRowSelectionAnimations(menu);
M2C_FIELD(menu,u8 *,MENU_MODE_HI)=(M2C_FIELD(menu,u8 *,MENU_MODE_HI)&~15)|(((u32)(M2C_FIELD(menu,u8 *,MENU_MODE_HI)<<24)>>28)&15);
if(!IsMenuActionRunning(menu)&&M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))PlaySoundEffect(SOUND_MENU_MOVE);
M2C_FIELD(menu,u8 *,MENU_FLAGS)&=~32;
}
#pragma opt_common_subs reset
s16 ScrollBar_GetValue(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x12);
}

/* Animate the unit-list menu's six button sprites (MENU_BUTTONS) by one frame. */
void Ov003_AnimateUnitListButtons(void *buttons) {
    M2C_UNK MenuSpriteUpdate(s32);
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_CONFIRM));
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_STEP_LEFT));
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_STEP_RIGHT));
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_RESET));
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_SUBMENU));
    MenuSpriteUpdate(M2C_FIELD(buttons, s32 *, MENU_BUTTON_BACK));
}

/* Whether `row` is the first row (row 0) of the unit list's split-row pair
 * while the selection context is in the split-row layout. */
u8 IsMenuSplitPairRow0(void *menu, s32 row) {
    s32 active;
    s32 result;

    if (M2C_FIELD(M2C_FIELD(menu, void **, MENU_SELECTION), u8 *, MENU_SELECTION_MODE) == MENU_SELECT_MODE_SPLIT_ROWS) active = 1;
    else active = 0;
    if ((active & 0xFF) && row == MENU_SPLIT_PAIR_ROW_FIRST) result = 1;
    else result = 0;
    return result;
}

/* Scrolls a scroll bar by `delta`: adds the step to the bar's scroll value,
 * clamps the value into the bar's range, then maps the value onto the track and
 * places the bar's thumb at the mapped position. */
void ScrollBar_ScrollBy(void *bar, s32 delta) {
    s32 Divide(s32, s32);
    M2C_UNK ScrollBar_PlaceThumb(void *, s16, s16);
    s32 current, limit;
    s32 x;
    s16 base;
    void *thumb;
    M2C_FIELD(bar, s16 *, SCROLLBAR_VALUE) += delta;
    limit = M2C_FIELD(bar, s16 *, SCROLLBAR_MAX);
    current = M2C_FIELD(bar, s16 *, SCROLLBAR_VALUE);
    if (current <= limit) { limit = M2C_FIELD(bar, s16 *, SCROLLBAR_MIN); if (current >= limit) limit = current; }
    M2C_FIELD(bar, s16 *, SCROLLBAR_VALUE) = limit;
    thumb = M2C_FIELD(bar, void **, SCROLLBAR_THUMB);
    base = M2C_FIELD(bar, s16 *, SCROLLBAR_X);
    x = base + Divide(M2C_FIELD(bar, s16 *, SCROLLBAR_VALUE) * (s16) (M2C_FIELD(thumb, s16 *, SCROLLTHUMB_MAX_X) - M2C_FIELD(thumb, s16 *, SCROLLTHUMB_MIN_X)), M2C_FIELD(bar, s16 *, SCROLLBAR_MAX) - M2C_FIELD(bar, s16 *, SCROLLBAR_MIN));
    thumb = M2C_FIELD(bar, void **, SCROLLBAR_THUMB); ScrollBar_PlaceThumb(thumb, (s16) x, M2C_FIELD(thumb, s16 *, SCROLLTHUMB_Y));
}

/* Whether `row` is the second pair row (row 1) of the split-row unit list, the
 * row whose left/right keys scroll the list's second scroll bar. */
u8 IsMenuSplitPairRow1(void *menu, s32 row) {
    s32 active;
    s32 result;

    if (M2C_FIELD(M2C_FIELD(menu, void **, MENU_SELECTION), u8 *, MENU_SELECTION_MODE) == MENU_SELECT_MODE_SPLIT_ROWS) active = 1;
    else active = 0;
    if ((active & 0xFF) && row == MENU_SPLIT_PAIR_ROW_LAST) result = 1;
    else result = 0;
    return result;
}

/* Step the first of the unit-list menu's three option counters by `delta`: the
 * value always takes the step, then wraps around its range (when the counter's
 * wrap flag is set) or clamps into it.  The range test is the shared counter
 * code's; its result is not used here. */
void Ov003_StepOptionCounter0(void *arg0, s32 delta) {
    s32 Ov003_IsValueInRange(s32, s32, s32);
    OptionCounter *counter = (OptionCounter *)arg0;
    s32 value, limit;
    value = delta + counter->value;
    Ov003_IsValueInRange((s16) value, (s16) counter->minimum, (s16) counter->maximum);
    counter->value = value;
    if (counter->wrap) {
        while (counter->value > counter->maximum) counter->value -= counter->maximum - counter->minimum + 1;
        while (counter->value < counter->minimum) counter->value += counter->maximum - counter->minimum + 1;
    } else {
        value = counter->value;
        limit = counter->maximum;
        if (value <= limit) {
            limit = counter->minimum;
            if (value >= limit) limit = value;
        }
        counter->value = limit;
    }
}

/* Step the second of the unit-list menu's three option counters by `delta`: the
 * value always takes the step, then wraps around its range (when the counter's
 * wrap flag is set) or clamps into it.  The range test is the shared counter
 * code's; its result is not used here. */
void Ov003_StepOptionCounter1(void *arg0,s32 delta){
 s32 Ov003_IsValueInRange(s32,s32,s32);
 OptionCounter *counter=&((OptionCounter *)arg0)[1];
 s32 value,limit;
 value=delta+counter->value;
 Ov003_IsValueInRange((s16)value,(s16)counter->minimum,(s16)counter->maximum);
 counter->value=value;
 if(counter->wrap){
 while(counter->value>counter->maximum) counter->value-=counter->maximum-counter->minimum+1;
 while(counter->value<counter->minimum) counter->value+=counter->maximum-counter->minimum+1;
 }else{limit=counter->maximum;value=counter->value;if(value<=limit){limit=counter->minimum;if(value>=limit)limit=value;}counter->value=limit;}
}

/* Move the third of the map-select screen's three sliders by delta, keeping
 * the new value between the slider's limits (wrapping around them instead when
 * the slider allows it).  The first two sliders have their own copies. */
void ScrollA9SliderBy(void *slider, s32 delta){
 s32 Ov003_IsValueInRange(s32,s32,s32); s32 newValue,limit;
 newValue=delta+M2C_FIELD(slider,s32 *,0x34);
 Ov003_IsValueInRange((s16)newValue,(s16)M2C_FIELD(slider,s32 *,0x3c),(s16)M2C_FIELD(slider,s32 *,0x38));
 M2C_FIELD(slider,s32 *,0x34)=newValue;
 if(M2C_FIELD(slider,u8 *,0x44)){
 while(M2C_FIELD(slider,s32 *,0x34)>M2C_FIELD(slider,s32 *,0x38)) M2C_FIELD(slider,s32 *,0x34)-=M2C_FIELD(slider,s32 *,0x38)-M2C_FIELD(slider,s32 *,0x3c)+1;
 while(M2C_FIELD(slider,s32 *,0x34)<M2C_FIELD(slider,s32 *,0x3c)) M2C_FIELD(slider,s32 *,0x34)+=M2C_FIELD(slider,s32 *,0x38)-M2C_FIELD(slider,s32 *,0x3c)+1;
 }else{limit=M2C_FIELD(slider,s32 *,0x38);newValue=M2C_FIELD(slider,s32 *,0x34);if(newValue<=limit){limit=M2C_FIELD(slider,s32 *,0x3c);if(newValue>=limit)limit=newValue;}M2C_FIELD(slider,s32 *,0x34)=limit;}
}

/* True when the unit-list menu is in its split-row mode and `row` is one of the
 * three split option rows (MENU_SPLIT_ROW_FIRST..MENU_SPLIT_ROW_LAST). */
u8 IsMenuSplitOptionRow(void *menu, s32 row) {
    s32 Ov003_IsValueInRange(s32, s32, s32);
    s32 inRange;

    if (M2C_FIELD(M2C_FIELD(menu, void **, MENU_SELECTION), u8 *, MENU_SELECTION_MODE) == MENU_SELECT_MODE_SPLIT_ROWS) {
        inRange = 1;
    } else {
        inRange = 0;
    }
    if ((inRange & 0xFF) && (Ov003_IsValueInRange(row, MENU_SPLIT_ROW_FIRST, MENU_SPLIT_ROW_LAST) != 0)) {
        inRange = 1;
    } else {
        inRange = 0;
    }
    return (u8) inRange;
}

/* Set the split-row selection flag on the unit-list menu object when it has no
 * mode pending and its selection context is showing the split-row layout. */
void MarkMenuSplitSelection(void *menu) {
    s32 modeIsZero;
    s32 splitRows;

    if (((u32) (M2C_FIELD(menu, u8 *, MENU_MODE) << 0x18) >> 0x1C) == 0) {
        modeIsZero = 1;
    } else {
        modeIsZero = 0;
    }
    if (!(modeIsZero & 0xFF)) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(menu, void **, MENU_SELECTION), u8 *, MENU_SELECTION_MODE) == MENU_SELECT_MODE_SPLIT_ROWS) {
        splitRows = 1;
    } else {
        splitRows = 0;
    }
    if (splitRows & 0xFF) {
        M2C_FIELD(menu, u8 *, MENU_FLAGS) = (u8) (M2C_FIELD(menu, u8 *, MENU_FLAGS) | MENU_FLAG_SPLIT_SELECT);
    }
}

/* Updates the entity's linked object orientation and commits derived state to globals. */
void func_ov003_0220bbcc(void *entity) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK EnableMapConfirm();
    M2C_UNK SetMapCategory(M2C_UNK);
    extern M2C_UNK gOptionBits;
    void *subObject;
    void *linkedObject;

    subObject = M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x14);
    if ((s32) M2C_FIELD(subObject, s8 *, 0x5A) >= 0) {
        M2C_FIELD(subObject, s32 *, 0x40) = (s32) ((M2C_FIELD(subObject, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(subObject, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(subObject, s8 *, 0x5A) = 0xC;
    }
    EnableMapConfirm();
    SetMapCategory(0x12);
    Sprite_ResumeAnimation(entity);
    PlaySoundEffect(0x1000E);
    linkedObject = M2C_FIELD(entity, void **, 0x40);
    M2C_FIELD(&gOptionBits, u16 *, 6) = (u16) ((M2C_FIELD(&gOptionBits, u16 *, 6) & ~0x3000) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 4) << 0x1E) >> 0x12));
    M2C_FIELD(&gOptionBits, u16 *, 6) = (u16) ((M2C_FIELD(&gOptionBits, u16 *, 6) & ~0xC00) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 0x1C) << 0x1E) >> 0x14));
    M2C_FIELD(&gOptionBits, u16 *, 6) = (u16) ((M2C_FIELD(&gOptionBits, u16 *, 6) & ~0x4000) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 0x34) << 0x1F) >> 0x11));
}

