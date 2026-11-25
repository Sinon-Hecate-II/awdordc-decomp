/* 26 functions from 0x0217BD88 to 0x0217CCE8 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"

typedef struct { void (*handlers[5])(void *); } CodeHandlers;
extern const CodeHandlers gCodeEntrySaveHandlers;
extern const CodeHandlers gCodeEntryLoadHandlers;
extern const u16 data_ov001_0218f848[];
extern void *gOv001FriendCodeState;
extern u32 data_ov001_02190770;

/* Decides whether the name just entered on the ov001 name-entry screen is
 * acceptable: entry mode 0 accepts any non-empty name; otherwise only certain
 * lengths pass, and the 10, 26 and 32-character forms (a code) must be all
 * hexadecimal.  A rejected attempt plays the error sound. */
s32 IsNameEntryValid(void) {
    s32 mode, variant, length, i;
    u8 *text;
    extern void *gNameEntryState;

    Ov001_GetNameEntryMode(&mode, &variant);
    if (variant == 1) Ov001_ShowMessagePanel(0x35, -1, 0);
    Ov001_GetNameEntryMode(&mode, &variant);
    if (mode == 0) return M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_TEXT) != 0;
    if (variant == 1 && M2C_FIELD(gNameEntryState, u8 *, NAME_ENTRY_TEXT) == 0) return 0;
    length = StringLengthUpTo((u8 *)gNameEntryState + NAME_ENTRY_TEXT, NAME_ENTRY_MAX_LENGTH);
    switch (length) {
    case 0:
    case 5:
    case 13:
    case 16:
        return 1;
    case 10:
    case 26:
    case 32:
        for (i = 0; i < length; i++) {
            u8 ch;
            text = (u8 *)gNameEntryState;
            ch = text[i + NAME_ENTRY_TEXT];
            if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) continue;
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_ov001_0217bf14(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK Ov001_CloseRegionMenu();
    s32 Ov001_GetRegionMenuSelection();
    extern M2C_UNK Ov001_ReopenNameEntryKeyboard;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_ReopenNameEntryKeyboard);
}

/* Step run after the name-entry region menu closes: clear the cursor sprite's
 * attribute bits and re-open the name-entry keyboard. */
void Ov001_ReopenNameEntryKeyboard(void) {
    s32 Ov001_IsRegionMenuActive();
    extern void *gNameEntryState;
    extern M2C_UNK Ov001_OpenNameEntryKeyboard;
    s32 *cursor;

    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    cursor = M2C_FIELD(gNameEntryState, s32 **, NAME_ENTRY_CURSOR);
    *cursor &= NAME_ENTRY_CURSOR_MASK;
    Ov001_SetStepCallback(&Ov001_OpenNameEntryKeyboard);
}

#pragma peephole off
void func_ov001_0217bf84(void) {
void *Ov001_Alloc(s32,s32);s32 Ov001_GetNameEntryMode(s32*,s32);
void *CreateTextPanel(s32,s32);void *Ov001_CreateSpriteFromLayout(s32,s32);
void Ov001_LoadCodeEntryGraphics(void);void func_ov001_0217c8ac(void);void Ov001_FadeInCodeEntryScreen(void);
CodeHandlers handlers=gCodeEntryLoadHandlers;
u8 choices[5]={((u8*)data_ov001_0218f848)[8],((u8*)data_ov001_0218f848)[9],((u8*)data_ov001_0218f848)[10],((u8*)data_ov001_0218f848)[11],((u8*)data_ov001_0218f848)[12]};
s32 a;void *p;
gOv001FriendCodeState=Ov001_Alloc(24,4);
Ov001_GetNameEntryMode(&a,0);
handlers.handlers[a](gOv001FriendCodeState+8);
p=gOv001FriendCodeState;
if(ByteCompareN(p+8,&data_ov001_02190770,3)) M2C_FIELD(p,u8*,20)=3;
else {MI_CpuFill8(p+8,0,12);M2C_FIELD(gOv001FriendCodeState,u8*,20)=0;}
Ov001_LoadCodeEntryGraphics();Ov001_LoadObjLayoutBlock(a+11);Ov001_ShowMessagePanel(choices[a],-1,0);Ov001_OpenMenuForMode(2);
M2C_FIELD(gOv001FriendCodeState,void**,0)=CreateTextPanel(0,0);
M2C_FIELD(gOv001FriendCodeState,void**,4)=Ov001_CreateSpriteFromLayout(0,63);
M2C_FIELD(M2C_FIELD(gOv001FriendCodeState,void**,4),u16*,4)=(M2C_FIELD(M2C_FIELD(gOv001FriendCodeState,void**,4),u16*,4)&~0xc00)|0xc00;
func_ov001_0217c8ac();func_ov001_0217c7e8();Ov001_SetStepCallback((s32*)Ov001_FadeInCodeEntryScreen);
}
#pragma peephole reset
/* Load the code-entry screen's OBJ palette, background tiles, palette and
 * tilemap, and set its background layers' priorities: the sub BG0/BG1 and main
 * BG1/BG2 layers lowest (3), the main BG0 layer above them (2). */
void Ov001_LoadCodeEntryGraphics(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001CodeEntryObjPalettePath;
    extern M2C_UNK gOv001CodeEntryTilesPath;
    extern M2C_UNK gOv001CodeEntryPalettePath;
    extern M2C_UNK gOv001CodeEntryTilemapPath;
    extern M2C_UNK GX_LoadBGPltt;
    extern M2C_UNK GX_LoadOBJPltt;
    extern M2C_UNK GX_LoadBG2Scr;
    extern M2C_UNK GX_LoadBG2Char;
    Ov001_LoadAsset(&gOv001CodeEntryObjPalettePath, &GX_LoadOBJPltt);
    Ov001_LoadAsset(&gOv001CodeEntryTilesPath, &GX_LoadBG2Char);
    Ov001_LoadAsset(&gOv001CodeEntryPalettePath, &GX_LoadBGPltt);
    Ov001_LoadAsset(&gOv001CodeEntryTilemapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (u16)((REG_BG0CNT & ~BG_PRIORITY_MASK) | 2);
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

/* Fades in the ov001 friend-code entry screen: start the sub and main fades from
 * white, enable its background and object planes, then move on to the step that
 * opens the keypad. */
void Ov001_FadeInCodeEntryScreen(void) {
    extern M2C_UNK Ov001_OpenCodeEntryKeypad;
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_SUB, GX_PLANEMASK_BG0, 8);
    Ov001_StartFade(OV001_FADE_FROM_WHITE, OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 8);
    Ov001_EnableVisiblePlanes(OV001_FADE_SUB, GX_PLANEMASK_BG0);
    Ov001_EnableVisiblePlanes(OV001_FADE_MAIN, GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    Ov001_SetStepCallback(&Ov001_OpenCodeEntryKeypad);
}

/* Step that runs once the code-entry screen has faded in: opens the keypad and
 * sets its keys for the current group - the first group starts with nothing
 * enabled, a later one keeps the digits off once its last group is complete -
 * then waits for the first key. */
void Ov001_OpenCodeEntryKeypad(void) {
    s32 IsCodeGroupComplete(s32);
    extern M2C_UNK Ov001_WaitKeypadFirstKey;
    extern void *gOv001FriendCodeState;
    if (Ov001_IsFadeActive(1) != 0) return;
    if (Ov001_IsFadeActive(0) != 0) return;
    Ov001_OpenKeypad();
    Ov001_PlaySound(0x14);
    if (M2C_FIELD(gOv001FriendCodeState, u8 *, CODE_ENTRY_GROUP) == 0) {
        Ov001_SetKeypadDeleteEnabled(0);
        Ov001_SetKeypadNextEnabled(0);
    } else {
        if (IsCodeGroupComplete(CODE_ENTRY_LAST_GROUP_MIN) != 0) Ov001_SetKeypadDigitsEnabled(0);
        Ov001_SetKeypadNextEnabled(0);
    }
    Ov001_SetStepCallback(&Ov001_WaitKeypadFirstKey);
}

void Ov001_WaitKeypadFirstKey(void) {
    s32 func_ov001_021744dc();
    extern M2C_UNK func_ov001_0217c2b4;
    if (func_ov001_021744dc() == 0x1F) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217c2b4);
}

void func_ov001_0217c2b4(void) {
    M2C_UNK func_ov001_0217c2c4();
    void func_ov001_0217c668(void);
    func_ov001_0217c2c4();
    func_ov001_0217c668();
}

s32 func_ov001_0217c2c4(void){
void func_ov001_0217c8ac(void);
void TrimCodeEntryDigits(void);
s32 func_ov001_021744dc(void);
s32 IsCodeGroupComplete(s32);
void func_ov001_0217c66c(void);
s32 code=func_ov001_021744dc();u8 *p; s32 i,a,b;
if(code==0)return;
switch(code){
case 16:
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)==0 && M2C_FIELD(gOv001FriendCodeState,u8 *,10)==0)break;
Ov001_PlaySound(3);
p=gOv001FriendCodeState;i=p[20];
if(!p[8+i*3+2])p[20]=i-1;
MI_CpuFill8((u8 *)gOv001FriendCodeState+8+M2C_FIELD(gOv001FriendCodeState,u8 *,20)*3,0,3);
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)==0 && M2C_FIELD(gOv001FriendCodeState,u8 *,10)==0)Ov001_SetKeypadDeleteEnabled(0);
Ov001_SetKeypadDigitsEnabled(1);Ov001_SetKeypadNextEnabled(0);break;
case 17:
p=gOv001FriendCodeState;
if(p[20]<3 && p[8+p[20]*3+2]){
Ov001_PlaySound(1);M2C_FIELD(gOv001FriendCodeState,u8 *,20)++;Ov001_SetKeypadNextEnabled(0);
}break;
case 18:
M2C_FIELD(gOv001FriendCodeState,u8 *,21)=0;
Ov001_PlaySound(7);Ov001_SetStepCallback((s32 *)&func_ov001_0217c66c);return;
case 19:
if(IsCodeEntryValid()){
Ov001_PlaySound(6);M2C_FIELD(gOv001FriendCodeState,u8 *,21)=1;
}else{
M2C_FIELD(gOv001FriendCodeState,u8 *,21)=2;Ov001_PlaySound(9);
}
M2C_FIELD(gOv001FriendCodeState,u8 *,20)=3;
p=M2C_FIELD(gOv001FriendCodeState,u8 **,4);
*(u32 *)p=(*(u32 *)p&0xc1fffcff)|512;
func_ov001_0217c8ac();TrimCodeEntryDigits();Ov001_SetStepCallback((s32 *)&func_ov001_0217c66c);return;
default:
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)==3 && IsCodeGroupComplete(26))break;
Ov001_PlaySound(1);
p=(u8 *)gOv001FriendCodeState+8;i=M2C_FIELD(gOv001FriendCodeState,u8 *,20)*3;
a=p[i+2];
if(!a)p[i+2]=code;
else if(!(b=p[i+1])){
p[i+1]=a;p[i+2]=code;
if(IsCodeGroupComplete(26) && M2C_FIELD(gOv001FriendCodeState,u8 *,20)<3)M2C_FIELD(gOv001FriendCodeState,u8 *,20)++;
}else{
p[i]=b;p[i+1]=p[i+2];p[i+2]=code;
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)<3)M2C_FIELD(gOv001FriendCodeState,u8 *,20)++;
}
Ov001_SetKeypadDeleteEnabled(1);
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)<3)Ov001_SetKeypadNextEnabled(1);else Ov001_SetKeypadNextEnabled(0);
if(M2C_FIELD(gOv001FriendCodeState,u8 *,20)==3 && IsCodeGroupComplete(26))Ov001_SetKeypadDigitsEnabled(0);
break;
}
func_ov001_0217c7e8();func_ov001_0217c8ac();
}

/* Test whether the friend-code group being edited (CODE_ENTRY_GROUP of the
 * four 3-digit groups at CODE_ENTRY_TEXT) is complete: a group that already has
 * a leading digit counts, a shorter one only once its value reaches `minimum`.
 * NUL padding is turned into spaces before the group is parsed. */
s32 IsCodeGroupComplete(s32 minimum) {
    M2C_UNK MI_CpuCopy8(void *, u8 *, s32);
    s32 ParseInt(u8 *);
    extern void *gOv001FriendCodeState;
    u8 digits[4];
    s32 offset;
    s32 i;
    u8 *p;
    u8 first;
    u8 *text;

    text = (u8 *)gOv001FriendCodeState + CODE_ENTRY_TEXT;
    offset = M2C_FIELD(gOv001FriendCodeState, u8 *, CODE_ENTRY_GROUP) * CODE_ENTRY_GROUP_SIZE;
    first = text[offset];
    if (first != 0 && first != 0x20) return 1;
    MI_CpuCopy8(text + offset, digits, CODE_ENTRY_GROUP_SIZE);
    i = 0;
    p = digits;
    digits[3] = 0;
    do {
        if (*p != 0) break;
        i++;
        *p++ = 0x20;
    } while (i < CODE_ENTRY_GROUP_SIZE);
    return ParseInt(digits) >= minimum;
}

void func_ov001_0217c668(void) {

}

void func_ov001_0217c66c(void) {
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK Ov001_StartDelay(M2C_UNK);
    extern M2C_UNK Ov001_CloseCodeEntryKeypad;
    Ov001_StartDelay(8);
    Ov001_SetStepCallback(&Ov001_CloseCodeEntryKeypad);
}

/* Step run 8 frames after the friend code is confirmed or rejected: wait for the
 * fade to finish, start closing the code-entry keypad and hand over to
 * Ov001_HandleCodeEntryResult, which applies the result once the keypad is gone. */
void Ov001_CloseCodeEntryKeypad(void) {
    void Ov001_StartKeypadClose(void);
    s32 Ov001_IsFadeActive(s32);
    extern void Ov001_HandleCodeEntryResult(void);
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartKeypadClose();
    Ov001_PlaySound(0x15);
    Ov001_SetStepCallback((s32 *)&Ov001_HandleCodeEntryResult);
}

/* Acts on the friend-code entry screen's result once its keypad has closed: a
 * cancelled entry (0) leaves for the map list, a rejected code (2) shows the
 * "invalid code" message and reopens the entry screen, and an accepted code shows
 * the completion message before the region menu's answer is applied. */
void Ov001_HandleCodeEntryResult(void) {
    s32 Ov001_IsKeypadOpen();
    M2C_UNK Ov001_ShowMessage(s32, s32, s32, s32, s32);
    extern void *gOv001FriendCodeState;
    extern M2C_UNK Ov001_LeaveCodeEntry;
    extern M2C_UNK Ov001_HandleCodeEntryRegionChoice;
    extern M2C_UNK Ov001_RetryCodeEntry;
    u8 result;
    if (Ov001_IsKeypadOpen() != 0) return;
    result = M2C_FIELD(gOv001FriendCodeState, u8 *, CODE_ENTRY_RESULT);
    if (result == 0) {
        Ov001_SetStepCallback(&Ov001_LeaveCodeEntry);
        return;
    }
    if (result == 2) {
        Ov001_ShowMessage(6, 3, 1, -1, 0);
        Ov001_SetStepCallback(&Ov001_RetryCodeEntry);
        return;
    }
    Ov001_ShowMessage(0x47, 2, 1, -1, 0);
    Ov001_SetStepCallback(&Ov001_HandleCodeEntryRegionChoice);
}

#pragma opt_common_subs off
#pragma opt_propagation off
void Ov001_LeaveCodeEntry(void) {
M2C_UNK Ov001_LoadAsset(M2C_UNK *,M2C_UNK *);
extern void *gOv001FriendCodeState;
extern M2C_UNK data_ov001_021907d0,GX_LoadOBJPltt,InitMapListScreen;
s32 sp0;void *state;
Ov001_FreeMessagePanel();
state=gOv001FriendCodeState;Ov001_ReleaseSprite(M2C_FIELD(state,s32 *,4));
Ov001_FreePageBackground(0);Ov001_LoadAsset(&data_ov001_021907d0,&GX_LoadOBJPltt);
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,0x15);
Ov001_GetNameEntryMode(&sp0,0);if(sp0>=3)sp0++;
Ov001_SetNextScreenMode(2,1);Ov001_SetNameEntryMode(0,sp0+3);
Ov001_SetStepCallback(&InitMapListScreen);
Ov001_FreeAlloc((u8*)&gOv001FriendCodeState);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
M2C_UNK func_ov001_0217c7e8(void){
 extern void *gOv001FriendCodeState; extern const u16 data_ov001_0218f848[]; extern M2C_UNK data_ov001_0218f888;
 void TextPanel_ClearText(s32,s32);void DrawPanelText(s32,s32,s32,s32,s32,s32,s32,void *);void CloseTextPanel(s32);
 u16 buf[6];s32 i,a,handle;const u8 *p;
 void *state;
 state=gOv001FriendCodeState;
 handle=M2C_FIELD(state,s32 *,0);
 buf[2]=data_ov001_0218f848[7];buf[3]=data_ov001_0218f848[8];buf[4]=11;buf[5]=16;
 TextPanel_ClearText(handle,0);
 buf[1]=0;
 p=(const u8 *)&data_ov001_0218f888;
 for(i=0;i<12;i++){
 state=gOv001FriendCodeState;
 a=*p++;
 buf[0]=M2C_FIELD((u8 *)state+i,u8 *,8);
 DrawPanelText(M2C_FIELD(state,s32 *,0),a,buf[3],buf[4],buf[5],2,0x480,(buf[2]=a,buf));
 }
 CloseTextPanel(M2C_FIELD(gOv001FriendCodeState,s32 *,0));
}
#pragma opt_store reset
void func_ov001_0217c8ac(void) {
extern void *gOv001FriendCodeState; extern M2C_UNK data_ov001_0218f888;
void *obj=gOv001FriendCodeState;
s32 index=M2C_FIELD(obj,u8*,0x14);
u32 *p=M2C_FIELD(obj,u32**,4);
index = (index > 3) ? 3 : index;
{ u32 x = M2C_FIELD(&data_ov001_0218f888,u8*,index*3+2); *p = (0x28 | (*p & 0xFE00FF00)) | ((x << 23) >> 7); }
}
#pragma scheduling on
/* Step run once the code-entry confirmation menu (the "region menu") has been
 * answered: store its answer as the entry result, play the matching sound, close
 * the menu and move on to Ov001_FinishCodeEntry. Any other answer is ignored. */
void Ov001_HandleCodeEntryRegionChoice(void) {
    extern void *gOv001FriendCodeState;
    extern M2C_UNK Ov001_FinishCodeEntry;
    M2C_FIELD(gOv001FriendCodeState, u8 *, CODE_ENTRY_RESULT) = Ov001_GetRegionMenuSelection();
    switch (M2C_FIELD(gOv001FriendCodeState, u8 *, CODE_ENTRY_RESULT)) {
    case 0: Ov001_PlaySound(7); break;
    case 1: Ov001_PlaySound(0xE); break;
    default: return;
    }
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_FinishCodeEntry);
}

/* Final code-entry step, run once the region menu has been answered: waits for the
 * menu to close, then either clears the cursor's code digit and resumes the entry
 * screen (result 0) or stores the entered code in the chosen save slot with that
 * entry mode's handler and leaves the screen. */
void Ov001_FinishCodeEntry(void) {
 s32 Ov001_IsRegionMenuActive(); M2C_UNK Ov001_GetNameEntryMode(s32 *,s32);
 extern void *gOv001FriendCodeState; 
 CodeHandlers table=gCodeEntrySaveHandlers; s32 index; s32 *p;
 if(Ov001_IsRegionMenuActive()) return;
 if(M2C_FIELD(gOv001FriendCodeState,u8 *,CODE_ENTRY_RESULT)==0) {
 p=M2C_FIELD(gOv001FriendCodeState,s32 **,CODE_ENTRY_CURSOR); *p &=CODE_ENTRY_CURSOR_MASK;
 Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenCodeEntryKeypad); return;
 }
 Ov001_GetNameEntryMode(&index,0);
 table.handlers[index]((u8 *)gOv001FriendCodeState+CODE_ENTRY_TEXT);
 Ov001_SetStepCallback((M2C_UNK *)&Ov001_LeaveCodeEntry);
}

/* Pad the friend code just entered before the entry screen redraws it: in each
 * 3-digit group, leading blanks (NULs and spaces) become spaces, except the
 * group's last digit, which becomes a '0'. */
void TrimCodeEntryDigits(void) {
 M2C_UNK func_ov001_0217c7e8(); extern void *gOv001FriendCodeState;
 u8 *p; s32 i,j; u8 c;
 for(i=0;i<CODE_ENTRY_GROUPS;i++) {
 p=(u8 *)gOv001FriendCodeState+CODE_ENTRY_TEXT+i*CODE_ENTRY_GROUP_SIZE;
 for(j=0;j<CODE_ENTRY_GROUP_SIZE;j++) {c=p[j]; if(c!='0' && c!=' ' && c!=0) break; p[j]=(j==CODE_ENTRY_GROUP_SIZE-1)?'0':' ';}
 }
 func_ov001_0217c7e8();
}

/* Validate the four 3-digit groups just entered on the ov001 code-entry screen:
 * each group must be a decimal number no greater than 255, then the groups are
 * packed into four bytes and checked - mode 1 wants the 32-bit value's set bits
 * to all sit together at the top, any other mode wants the first byte to be a
 * valid text character. */
s32 IsCodeEntryValid(void) {
extern const u16 data_ov001_0218f848[];
extern void *gOv001FriendCodeState;
void ParsePlayerCode(void *,void *);
s32 Ov001_GetNameEntryMode(s32 *,s32);
s32 IsValidTextChar(void *);
u8 maxDigits[4]="255"; s32 entryMode; u8 code[4]; u8 *group; s32 bit,groupIndex,seenZero; u8 *base;
const u8 *src=(const u8 *)data_ov001_0218f848;

for(groupIndex=0;groupIndex<4;groupIndex++){
group=(u8 *)gOv001FriendCodeState+8+groupIndex*3;
if(*group==32) continue;
for(bit=0;bit<3;bit++){if(group[bit]>maxDigits[bit])return 0;if(group[bit]<maxDigits[bit])break;}
}
ParsePlayerCode((u8 *)gOv001FriendCodeState+8,code);
Ov001_GetNameEntryMode(&entryMode,0);
if(entryMode==1){seenZero=0;for(groupIndex=0;groupIndex<4;groupIndex++){for(bit=0;bit<8;bit++){if(seenZero){if(code[groupIndex]&(1<<(7-bit)))return 0;}else if(!(code[groupIndex]&(1<<(7-bit))))seenZero=1;}}return 1;}
return IsValidTextChar(code)!=0;
}

void Ov001_RetryCodeEntry(void) {
    extern M2C_UNK Ov001_OpenKeypadAfterRegionMenu;
    if (Ov001_GetRegionMenuSelection() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    Ov001_CloseRegionMenu();
    Ov001_SetStepCallback(&Ov001_OpenKeypadAfterRegionMenu);
}

/* Step run after a code-entry retry: once the region menu has closed, clear the
 * code-entry sprite's display flags and open the keypad again. */
void Ov001_OpenKeypadAfterRegionMenu(void) {
    void Ov001_OpenCodeEntryKeypad(void);
    s32 *flags;

    if (Ov001_IsRegionMenuActive() != 0) {
        return;
    }
    flags = M2C_FIELD(gOv001FriendCodeState, s32 **, 4);
    *flags &= 0xC1FFFCFF;
    Ov001_SetStepCallback((M2C_UNK *)&Ov001_OpenCodeEntryKeypad);
}

void Ov001_ShowWfcErrorScreen(void) {
    void Ov001_LoadWfcErrorBackground(void);
    M2C_UNK DrawWfcErrorPanel();
    extern M2C_UNK Ov001_FadeInWfcErrorScreen;
    Ov001_LoadWfcErrorBackground();
    DrawWfcErrorPanel();
    Ov001_SetStepCallback(&Ov001_FadeInWfcErrorScreen);
}

/* Load the Wi-Fi error background map (char/jb4Error.nsc.l) into BG2 and put
 * BG0..BG2 of the main engine and BG0/BG1 of the sub engine at the lowest
 * priority, so that the map covers them. */
void Ov001_LoadWfcErrorBackground(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK gOv001WfcErrorBgMapPath, GX_LoadBG2Scr;
    Ov001_LoadAsset(&gOv001WfcErrorBgMapPath, &GX_LoadBG2Scr);
    REG_SUB_BG0CNT = (u16)((REG_SUB_BG0CNT & ~BG_PRIORITY_MASK) | 3);
    REG_SUB_BG1CNT = (u16)((REG_SUB_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG0CNT = (REG_BG0CNT & ~BG_PRIORITY_MASK) | 3;
    REG_BG1CNT = (u16)((REG_BG1CNT & ~BG_PRIORITY_MASK) | 3);
    REG_BG2CNT = (u16)((REG_BG2CNT & ~BG_PRIORITY_MASK) | 3);
}

