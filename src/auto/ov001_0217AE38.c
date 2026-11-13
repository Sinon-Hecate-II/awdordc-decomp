/* 28 functions from 0x0217AE38 to 0x0217BD88 (ov001), found by ds-decomp. */
#include "common.h"
void func_ov001_0217b578(void);
void UpdateNameEntryCursor(void);
void RedrawNameEntryText(void);

void func_ov001_0217b130(void);

void func_ov001_0217ae38(s32 arg0, s32 arg1) {
    extern M2C_UNK gMapSelectState;
    s32 offset;
    void *first, *second;
    if (arg0 >= M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51)) return;
    offset = arg0 * 0x2A;
    first = M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, 4) + arg1 * 4, void **, 0x10);
    M2C_FIELD(first, u16 *, 4) = (M2C_FIELD(first, u16 *, 4) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, 4) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), void **, 0) + offset, u8 *, 0x28), u16 *, 0x42);
    second = M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, 4) + arg1 * 4, void **, 0x24);
    M2C_FIELD(second, u16 *, 4) = (M2C_FIELD(second, u16 *, 4) & ~0x3FF) | M2C_FIELD((u8 *)M2C_FIELD(&gMapSelectState, void **, 4) + 2 * M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), void **, 0) + offset, u16 *, 0x26), u16 *, 0x48);
}

void func_ov001_0217aec4(void) {
s32 func_020020c4(u16,s32);extern M2C_UNK gMapSelectState;
s32 *first,*second; s32 position; s32 count; s32 i;
position=0x36-func_020020c4(M2C_FIELD(&gMapSelectState,u16 *,2),28);
count=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x51);
i=0;
if(count>5)count=5;
while(i<count){
first=((s32 **)M2C_FIELD(&gMapSelectState,void **,4))[i+4];
*first=(*first&0xfe00ff00)|(u8)(position-2)|0xb30000;
second=((s32 **)M2C_FIELD(&gMapSelectState,void **,4))[i+9];
i++;
*second=(*second&0xfe00ff00)|(u8)(position+1)|0xd20000;
position+=28;
}
M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x56)=1;
}

void func_ov001_0217af80(s32 arg0) {
    s32 func_020020c4(u16, s32);
    extern M2C_UNK gMapSelectState;
    s32 delta, remainder;
    u32 position;
    func_ov001_02183a08();
    func_ov001_02172184();
    if ((u32)M2C_FIELD(&gMapSelectState, u16 *, 2) > 4U) M2C_FIELD(&gMapSelectState, u16 *, 2) = M2C_FIELD(&gMapSelectState, u16 *, 2) - 4;
    else M2C_FIELD(&gMapSelectState, u16 *, 2) = 0;
    remainder = func_020020c4(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1C);
    if (remainder == 0x18) {
        func_ov001_0217ac18();
        return;
    }
    if (remainder > 0x18) {
        delta = 0x1C - remainder;
        M2C_FIELD(&gMapSelectState, u16 *, 2) = M2C_FIELD(&gMapSelectState, u16 *, 2) + (0x1C - remainder);
        remainder = 0;
    }
    func_ov001_0217aec4();
    if (remainder != 0) return;
    func_02002088(M2C_FIELD(&gMapSelectState, u16 *, 2) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u16 *, 0x40));
    func_ov001_021839e4();
    func_ov001_021839f0();
    func_ov001_0217b130();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0x38) = 0;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_0217b03c(s32 arg0) {
    s32 func_020020c4(u16, s32);
    extern M2C_UNK gMapSelectState;
    s32 result;
    func_ov001_02183a08();
    func_ov001_02172184();
    M2C_FIELD(&gMapSelectState, u16 *, 2) = M2C_FIELD(&gMapSelectState, u16 *, 2) + 4;
    result = func_020020c4(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1C);
    if (result >= 4) {
        func_ov001_0217aec4();
        return;
    }
    M2C_FIELD(&gMapSelectState, u16 *, 2) = M2C_FIELD(&gMapSelectState, u16 *, 2) - result;
    func_ov001_0217ac18();
    func_02002088(M2C_FIELD(&gMapSelectState, u16 *, 2) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u16 *, 0x40));
    func_ov001_021839e4();
    func_ov001_021839f0();
    func_ov001_0217b130();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0x38) = 0;
    func_ov001_0218c92c(0, arg0);
}

void func_ov001_0217b0d4(void) {
    s32 func_020020c4(u16, M2C_UNK);
    extern M2C_UNK gMapSelectState;
    s32 temp_r1;

    if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x56) == 0) {
        return;
    }
    temp_r1 = 0x01FF0000 & ((func_020020c4(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1C) - 0x32) << 0x10);
    M2C_FIELD((void *)0x04000010, s32 *, 0) = temp_r1;
    M2C_FIELD((void *)0x04000010, s32 *, 8) = temp_r1;
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x56) = 0U;
}

void func_ov001_0217b130(void) {
    void func_ov001_02171fd8(s32, u16, u16, u16);
    extern u16 data_ov001_0218f7ec[], data_ov001_0218f7ee[], data_ov001_0218f7f0[];
    extern M2C_UNK gMapSelectState;
    u32 index = M2C_FIELD(&gMapSelectState, u8 *, 0);
    func_ov001_02171fd8(index < 4 ? 2 : 3, data_ov001_0218f7ec[index * 4], data_ov001_0218f7f0[index * 4], data_ov001_0218f7ee[index * 4]);
}

/* Map-select list D-pad handler: moves the highlighted row up (dir == 1) or
 * down (dir == 3). At the top or bottom of the list it wraps the cursor or
 * pages the list on (scheduling the scroll animation at MAPSELECT_SCROLL_ANIM),
 * plays the cursor-move sound, or the no-move sound once per held key
 * (MAPSELECT_BUMP_LATCH). */
void MapSelectList_MoveCursor(s32 dir){
void func_ov001_0217b33c(void);
extern M2C_UNK gMapSelectState;
s32 func_ov001_0218c884(s32,void (*)(s32),s32,s32);
s32 moved=1;s32 row=M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR);
switch(row) {
case 0: if(dir==1) {if(!M2C_FIELD(&gMapSelectState,u16 *,MAPSELECT_STATE_SCROLL)) M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=4;else {
Ov001_PlaySound(19);
M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),s32 *,MAPSELECT_SCROLL_ANIM)=func_ov001_0218c884(0,func_ov001_0217af80,0,120);return;
}} else {if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_COUNT)>1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row+1;else moved=0;}break;
case 1:case 2: if(dir==1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row-1;else {if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_COUNT)>(row+1))M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row+1;else moved=0;}break;
case 3:if(dir==1)M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=row-1;else {func_ov001_0217b33c();return;}break;
case 4:if(dir==1)moved=0;else {M2C_FIELD(&gMapSelectState,u16 *,MAPSELECT_STATE_SCROLL)=0;M2C_FIELD(&gMapSelectState,u8 *,MAPSELECT_STATE_CURSOR)=0;func_ov001_0217ac18();func_ov001_021839e4(0);}break;
}
if(!moved){if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_BUMP_LATCH))return;Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,MAPSELECT_STATE_OBJ),u8 *,MAPSELECT_BUMP_LATCH)=1;return;}
Ov001_PlaySound(8);func_ov001_0217b130();
}

void func_ov001_0217b2c8(void) {
    M2C_UNK Ov001_PlaySound(s32);
    s32 func_ov001_0218c884(s32, void (*)(s32), s32, s32);
    extern M2C_UNK gMapSelectState;
    if (M2C_FIELD(&gMapSelectState, u16 *, 2) == 0) {
        if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x59) != 0) return;
        Ov001_PlaySound(9);
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x59) = 1;
        return;
    }
    Ov001_PlaySound(0x13);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0x38) = func_ov001_0218c884(0, func_ov001_0217af80, 0, 0x78);
}

void func_ov001_0217b33c(void) {
    M2C_UNK Ov001_PlaySound(s32);
    s32 func_ov001_0218c884(s32, void (*)(s32), s32, s32);
    extern M2C_UNK gMapSelectState;
    if (M2C_FIELD(&gMapSelectState, u16 *, 2) == M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u16 *, 0x40) || M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51) <= 4) {
        if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x59) != 0) return;
        Ov001_PlaySound(9);
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x59) = 1;
        return;
    }
    Ov001_PlaySound(0x13);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0x38) = func_ov001_0218c884(0, func_ov001_0217b03c, 0, 0x78);
}

void func_ov001_0217b3c0(void) {
    M2C_UNK func_ov001_021837e4(s32, u8, u8);
    struct Table { u8 values[1]; };
    extern struct Table data_ov001_0218f794;
    extern M2C_UNK gMapSelectState;
    struct Table table = data_ov001_0218f794;
    u8 value = table.values[0];
    func_ov001_021837e4(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 8), value, value);
}

void func_ov001_0217b3f0(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_0217b41c;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217b41c);
}

void func_ov001_0217b41c(void) {
    M2C_UNK func_ov001_02171738();
    M2C_UNK func_ov001_021839f0();
    s32 func_ov001_0218665c();
    extern M2C_UNK func_ov001_0217a3a8;
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02171738();
    func_ov001_021839f0();
    Ov001_SetStepCallback(&func_ov001_0217a3a8);
}

/* Sets up the ov001 name-entry screen: gets its state block, loads the saved
 * name (when the current mode has one), picks the on-screen keyboard and message
 * for the mode, creates the text panel and cursor sprite and installs the first
 * step callback. */
void InitNameEntryScreen(void) {
extern void *data_ov001_0218f81c; extern void *gNameEntryState;
void *func_ov001_0218b6f8(s32,s32);void Ov001_GetNameEntryMode(s32 *,s32);
s32 StringLengthUpTo(void *,s32);void *CreateTextPanel(s32,s32);void *func_ov001_0218a5f0(s32,s32);
void func_ov001_0217b634(void);
u8 modeMessages[2]={M2C_FIELD(&data_ov001_0218f81c,u8 *,0),M2C_FIELD(&data_ov001_0218f81c,u8 *,1)};s32 mode,variant;
gNameEntryState=func_ov001_0218b6f8(44,4);
Ov001_GetNameEntryMode(&mode,(s32)&variant);
if(mode==0) {func_ov001_021846f8((u8 *)gNameEntryState+NAME_ENTRY_TEXT); M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)=StringLengthUpTo((u8 *)gNameEntryState+NAME_ENTRY_TEXT,NAME_ENTRY_MAX_LENGTH);}
func_ov001_0217b578();func_ov001_02172250(mode+9);
if(variant==1)func_ov001_02171c24(53,-1,0);else func_ov001_02171c24(modeMessages[mode],-1,0);
func_ov001_02171dd0(2);
M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_PANEL)=CreateTextPanel(0,0);
M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR)=func_ov001_0218a5f0(0,62);
M2C_FIELD(M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR),u16 *,4)=(M2C_FIELD(M2C_FIELD(gNameEntryState,void **,NAME_ENTRY_CURSOR),u16 *,4)&~0xc00)|0xc00;
UpdateNameEntryCursor();RedrawNameEntryText();Ov001_SetStepCallback((s32 *)func_ov001_0217b634);
}

void func_ov001_0217b578(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190700;
    extern M2C_UNK data_ov001_02190714;
    extern M2C_UNK data_ov001_0219072c;
    extern M2C_UNK data_ov001_02190744;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK func_02004160;
    extern M2C_UNK func_0200448c;
    extern M2C_UNK func_020046cc;
    Ov001_LoadAsset(&data_ov001_02190700, &func_02004160);
    Ov001_LoadAsset(&data_ov001_02190714, &func_020046cc);
    Ov001_LoadAsset(&data_ov001_0219072c, &GX_LoadBGPltt);
    Ov001_LoadAsset(&data_ov001_02190744, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_0217b634(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217b688;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217b688);
}

void func_ov001_0217b688(void) {
    s32 func_ov001_0218a800(s32);
    M2C_UNK func_ov001_021724c0(void);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_SetKeyboardCanDelete(s32);
    M2C_UNK Ov001_SetKeyboardCanAdd(s32);
    void func_ov001_0217b704(void);
    M2C_UNK Ov001_SetStepCallback();
    extern void *gNameEntryState;
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_021724c0();
    Ov001_PlaySound(0x14);
    if (M2C_FIELD(gNameEntryState, u8 *, 0x29) == 0) {
        Ov001_SetKeyboardCanDelete(0);
    }
    if (M2C_FIELD(gNameEntryState, u8 *, 0x29) == 0x20) {
        Ov001_SetKeyboardCanAdd(0);
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217b704);
}

void func_ov001_0217b704(void) {
    s32 GetKeyboardKey();
    void func_ov001_0217b724(void);
    if (GetKeyboardKey() == 0xFF) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217b724);
}

void func_ov001_0217b724(void) {
    void HandleNameEntryInput(void);
    void func_ov001_0217b8f4(void);
    HandleNameEntryInput();
    func_ov001_0217b8f4();
}

/* Handles one event of the on-screen keyboard in the ov001 name-entry screen: a
 * delete removes the last character, cancel ends the entry, OK ends it only when
 * the text is valid, and a character key appends it while the buffer has room. */
void HandleNameEntryInput(void) {
extern void *gNameEntryState;
void func_ov001_0217b8f8(void);
s32 key=GetKeyboardKey(); s32 *obj;
switch(key){
case KBD_KEY_DELETE:
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)){
Ov001_PlaySound(3);
M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)--;
M2C_FIELD((u8 *)gNameEntryState+M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH),u8 *,NAME_ENTRY_TEXT)=0;
if(!M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH))Ov001_SetKeyboardCanDelete(0);
Ov001_SetKeyboardCanAdd(1);
}
break;
case 0:break;
case KBD_KEY_CANCEL:
Ov001_PlaySound(7);M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=0;Ov001_SetStepCallback(func_ov001_0217b8f8);return;
case KBD_KEY_OK:
if(IsNameEntryValid()){
Ov001_PlaySound(6);M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=1;
}else{M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_RESULT)=2;Ov001_PlaySound(9);}
obj=M2C_FIELD(gNameEntryState,s32 **,NAME_ENTRY_CURSOR);*obj=(*obj&0xc1fffcff)|0x200;
Ov001_SetStepCallback(func_ov001_0217b8f8);return;
case KBD_KEY_SPACE:
default:
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)!=32){
Ov001_PlaySound(1);
M2C_FIELD((u8 *)gNameEntryState+M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH),u8 *,NAME_ENTRY_TEXT)=key;
M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)++;
Ov001_SetKeyboardCanDelete(1);
if(M2C_FIELD(gNameEntryState,u8 *,NAME_ENTRY_LENGTH)==32)Ov001_SetKeyboardCanAdd(0);
}
break;
}
RedrawNameEntryText();UpdateNameEntryCursor();
}

void func_ov001_0217b8f4(void) {

}

void func_ov001_0217b8f8(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217b914;
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217b914);
}

void func_ov001_0217b914(void) {
    M2C_UNK func_ov001_02172824();
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217b944;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02172824();
    Ov001_PlaySound(0x15);
    Ov001_SetStepCallback(&func_ov001_0217b944);
}

void func_ov001_0217b944(void) {
    s32 func_ov001_02172894();
    void Ov001_GetNameEntryMode(s32 *, s32);
    M2C_UNK func_ov001_021862d8(s32, s32, s32, s32, s32);
    extern void *data_ov001_0218f81c;
    extern void *gNameEntryState;
    extern M2C_UNK func_ov001_0217ba1c;
    extern M2C_UNK func_ov001_0217bc7c;
    extern M2C_UNK func_ov001_0217bf14;
    s32 sp8[2];
    s32 sp4;
    u8 temp_r0;

    sp8[0] = M2C_FIELD(&data_ov001_0218f81c, s32 *, 8);
    sp8[1] = M2C_FIELD(&data_ov001_0218f81c, s32 *, 0xC);
    if (func_ov001_02172894() != 0) return;
    temp_r0 = M2C_FIELD(gNameEntryState, u8 *, 0x2A);
    if (temp_r0 == 0) {
        Ov001_SetStepCallback(&func_ov001_0217ba1c);
        return;
    }
    if (temp_r0 == 2) {
        func_ov001_021862d8(6, 3, 1, -1, 0);
        Ov001_SetStepCallback(&func_ov001_0217bf14);
        return;
    }
    Ov001_GetNameEntryMode(0, &sp4);
    func_ov001_021862d8(sp8[sp4], 2, 1, -1, 0);
    Ov001_SetStepCallback(&func_ov001_0217bc7c);
}

#pragma optimization_level 4
#pragma peephole off
void func_ov001_0217ba1c(void) {
    M2C_UNK func_ov001_02171cf8(void);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov001_0218c104(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    void func_ov001_0218b368(s32, s32);
    void Ov001_GetNameEntryMode(s32 *, s32);
    void func_ov001_02175d64(s32, s32);
    void Ov001_SetNameEntryMode(s32, s32);
    s32 Ov001_SetStepCallback(s32 *);
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern void *gNameEntryState;
    extern void *data_ov001_02190758;
    extern void func_02004160(void);
    extern void InitMapListScreen(void);
    extern void func_ov001_02179ea8(void);
    extern void func_ov001_021828ac(void);
    s32 sp4, sp0;
    void *p;
    func_ov001_02171cf8();
    func_ov001_0218c104(M2C_FIELD(gNameEntryState, void **, 4));
    func_ov001_0218af70(0);
    Ov001_LoadAsset((M2C_UNK *)&data_ov001_02190758, (M2C_UNK *)&func_02004160);
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    Ov001_GetNameEntryMode(&sp4, &sp0);
    if (sp0 == 0) {
        func_ov001_02175d64(2, 1);
        Ov001_SetNameEntryMode(0, sp4);
        Ov001_SetStepCallback((s32 *)InitMapListScreen);
    } else {
        if (M2C_FIELD(gNameEntryState, u8 *, 0x2A) == 0) {
            func_ov001_02175d64(0, 1);
            Ov001_SetNameEntryMode(1, 0);
            Ov001_SetStepCallback((s32 *)func_ov001_02179ea8);
        } else {
            func_ov001_02175d64(0, 0);
            Ov001_SetNameEntryMode(0, 1);
            Ov001_SetStepCallback((s32 *)func_ov001_021828ac);
        }
    }
    p = sp0 ? (void *)&gNameEntryState : (void *)&gNameEntryState;
    func_ov001_0218b71c((M2C_UNK *)p);
}
#pragma peephole reset
void RedrawNameEntryText(void) {
extern void *gNameEntryState; extern u8 data_ov001_0218f838[];
void func_ov001_0218b1ec(s32,s32);void DrawPanelText(s32,s32,s32,s32,s32,s32,s32,void *);void CloseTextPanel(s32);
u16 buf[6]; u16 *p; s32 j,i; u8 v;
p=&buf[2];p[1]=0;p[2]=0;p[3]=0;p[0]=0;
buf[3]=32;buf[4]=14;buf[5]=16;
func_ov001_0218b1ec(M2C_FIELD(gNameEntryState,s32 *,0),0);
i=0;j=i;buf[1]=i;
do {
if(i==16){j=0;buf[3]=49;}
v=M2C_FIELD((u8 *)gNameEntryState+i,u8 *,8);
if(v==32)buf[0]=0xe01d;else buf[0]=v;
buf[2]=data_ov001_0218f838[j];
DrawPanelText(M2C_FIELD(gNameEntryState,s32 *,0),buf[2],buf[3],buf[4],buf[5],2,0x480,buf);
i++;j++;
}while(i<32);
CloseTextPanel(M2C_FIELD(gNameEntryState,s32 *,0));
}

void UpdateNameEntryCursor(void) {
    extern void *gNameEntryState;
    extern u8 data_ov001_0218f834[];
    extern u8 data_ov001_0218f838[];
    void *obj;
    s32 *slot;
    u8 value;
    s32 index, high;
    obj = gNameEntryState;
    value = M2C_FIELD(obj, u8 *, 0x29);
    slot = M2C_FIELD(obj, s32 **, 4);
    index = value & 0xF;
    high = value >> 4;
    if (value >= 0x20) {
        high = 1;
        index = 0xF;
    }
    *slot = (*slot & 0xFE00FF00) | data_ov001_0218f834[high] | ((u32)data_ov001_0218f838[index] << 0x17 >> 7);
}

void func_ov001_0217bc7c(void) {
    extern void *gNameEntryState;
    extern M2C_UNK func_ov001_0217bcd8;
    M2C_FIELD(gNameEntryState, u8 *, 0x2A) = func_ov001_02186648();
    switch (M2C_FIELD(gNameEntryState, u8 *, 0x2A)) {
    case 0: Ov001_PlaySound(7); break;
    case 1: Ov001_PlaySound(0xE); break;
    default: return;
    }
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_0217bcd8);
}

void func_ov001_0217bcd8(void) {
    s32 func_ov001_0218665c(void);
    s32 Ov001_SetStepCallback(s32 *);
    void Ov001_GetNameEntryMode(s32 *, s32);
    void func_ov001_0217b688(void);
    void func_ov001_0217ba1c(void);
    extern void *data_ov001_0218f81c;
    extern void *gNameEntryState;

    void *entries[2];
    s32 index;

    entries[0] = M2C_FIELD(&data_ov001_0218f81c, void **, 0x10);
    entries[1] = M2C_FIELD(&data_ov001_0218f81c, void **, 0x14);

    if (func_ov001_0218665c()) return;
    if (M2C_FIELD(gNameEntryState, u8 *, 0x2a) == 0) {
        s32 *p = M2C_FIELD(gNameEntryState, s32 **, 4);
        *p &= 0xc1fffcff;
        Ov001_SetStepCallback((s32 *)func_ov001_0217b688);
        return;
    }
    Ov001_GetNameEntryMode(&index, 0);
    ((void (*)(void *))entries[index])((u8 *)gNameEntryState + 8);
    Ov001_SetStepCallback((s32 *)func_ov001_0217ba1c);
}

