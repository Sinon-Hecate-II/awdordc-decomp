/* 12 functions from 0x0217DC7C to 0x0217EB6C (ov001), found by ds-decomp. */
#include "common.h"
static inline void GetSpriteXY(u32 *p,s32 *y,s32 *x){u32 v=*p;*y=v&255;*x=(v&0x1ff0000)>>16;}
static inline void SetSpriteXY(u32 *p,s32 y,s32 x){*p=(*p&0xfe00ff00)|(u8)y|((u32)(x<<23)>>7);}

/* Applies the map-list menu's current state: snaps the scroll position, plays
 * the move/bump sound, redraws the list, and schedules the scroll-snap callbacks
 * that finish the movement. */
void MapListHandleState(void) {
 extern M2C_UNK gMapListState;
 extern M2C_UNK MapListScrollUp,MapListScrollDown;
 s32 GetMenuState(void);
 s32 GetMenuRow(void);
 s32 HardwareDivideRemainder(u16,s32);
 void Ov001_FreeSpriteObjects(void);
 void MapListRedrawInfoPanel(void);
 void MapList_UpdateStateFromRow(void);
 M2C_UNK Ov001_PlaySound(s32);
 s32 Ov001_AddTask(s32,s32,s32,s32);
 s32 remainder;
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56))return;
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65))--M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65);
 switch(GetMenuState()){
 case 1:M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,69)=1;return;
 case 2:
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65))return;
 Ov001_FreeSpriteObjects();
 M2C_FIELD(&gMapListState,u16 *,4)=GetMenuRow()*145/55;
 MapListRedrawInfoPanel();M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,65)=4;return;
 case 3:
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,69)=0;
 M2C_FIELD(&gMapListState,u16 *,4)=GetMenuRow()*145/55;
 Ov001_PlaySound(19);MapListRedrawInfoPanel();
 remainder=HardwareDivideRemainder(M2C_FIELD(&gMapListState,u16 *,4),29);
 if(remainder==0){MapList_UpdateStateFromRow();return;}
 if(remainder<16){M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=Ov001_AddTask(0,(s32)&MapListScrollUp,0,120);return;}
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=Ov001_AddTask(0,(s32)&MapListScrollDown,0,120);return;
 case 4:
 if(M2C_FIELD(&gMapListState,u16 *,4)==0){
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70))return;
 Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=1;return;}
 Ov001_PlaySound(19);
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=Ov001_AddTask(0,(s32)&MapListScrollUp,0,120);return;
 case 6:
 if(M2C_FIELD(&gMapListState,u16 *,4)==145){
 if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70))return;
 Ov001_PlaySound(9);M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=1;return;}
 Ov001_PlaySound(19);
 M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,56)=Ov001_AddTask(0,(s32)&MapListScrollDown,0,120);return;
 case 5:case 7:M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,70)=0;return;
 default:return;
 }
}

void func_ov001_0217ded8(void) {
    M2C_UNK Ov001_BlockScrollBar();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217def8;
    Ov001_BlockScrollBar();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217def8);
}

void func_ov001_0217def8(void) {
    s32 Ov001_IsFadeActive(M2C_UNK);
    M2C_UNK Ov001_StartFade(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217df44;
    if (Ov001_IsFadeActive(1) != 0) {
        return;
    }
    Ov001_StartFade(3, 1, 1, 8);
    Ov001_StartFade(3, 0, 0x1D, 8);
    Ov001_SetStepCallback(&func_ov001_0217df44);
}

#pragma push
#pragma opt_strength_reduction off
void func_ov001_0217df44(void) {
extern M2C_UNK gMapListState, data_ov001_0219085c, data_ov001_02193db4;
extern M2C_UNK GX_LoadOBJPltt,InitNameEntryScreen,func_ov001_0217bf84,Ov001_OpenWfcConnectScreen,func_ov001_0217f73c,Ov001_OpenAccessPointMenu,func_ov001_02181a84;
s32 Ov001_IsFadeActive(s32);
void *GetCurrentMapRecord(void);
s32 CountSetBits(void *);
s32 i,n; u8 *p;
if(Ov001_IsFadeActive(1))return;
if(Ov001_IsFadeActive(0))return;
func_ov001_0218c94c(0,M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0));
func_ov001_0218c94c(1,M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,60));
for(i=0;i<7;i++)Ov001_ReleaseSprite(M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,8)+i*4,s32 *,24));
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,52))Ov001_ReleaseSprite(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,52));
func_ov001_02183980();Ov001_FreePageBackground(0);Ov001_FreeSpriteObjects();
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)!=12)Ov001_FreeOptionBackground();
FreeMapPreview();
Ov001_FreeFile(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,8));
for(i=0;i<2;i++)Ov001_FreeFile(M2C_FIELD((u8 *)M2C_FIELD(&gMapListState,void **,8)+i*4,s32 *,12));
Ov001_LoadAsset(&data_ov001_0219085c,&GX_LoadOBJPltt);
Ov001_DisableVisiblePlanes(1,1);Ov001_DisableVisiblePlanes(0,29);
*(volatile u32*)0x04000010=0;*(volatile u32*)0x04000018=0;
*(volatile u16*)0x0400000c=(*(volatile u16*)0x0400000c&0x43)|0xe10;
switch((u32)M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)){
case 0:case 1:Ov001_SetNameEntryMode();Ov001_SetNextScreenMode(2,0);Ov001_SetStepCallback(&InitNameEntryScreen);break;
case 4:case 5:case 6:case 9:case 10:
n=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)-4;
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)>=9)n-=2;
Ov001_SetNextScreenMode(2,0);Ov001_SetNameEntryMode(n,0);Ov001_SetStepCallback(&func_ov001_0217bf84);break;
case 11:p=GetCurrentMapRecord();p[0xd0]=CountSetBits(p+0xf0);
if(p[0xf5]){MI_CpuFill8(p+0xc0,0,4);MI_CpuFill8(p+0xc4,0,4);MI_CpuFill8(p+0xf0,0,4);p[0xd0]=0;}
if(p[0xf6])MI_CpuFill8(p+0xc8,0,8);
Ov001_SetNextScreenMode(2,0);Ov001_SetNameEntryMode(0,0);Ov001_SetStepCallback(&Ov001_OpenWfcConnectScreen);break;
case 12:Ov001_SetNextScreenMode(0,0);Ov001_SetStepCallback(&func_ov001_0217f73c);break;
case 13:if(M2C_FIELD(&gMapListState,u8 *,1)==0){Ov001_SetNextScreenMode(2,1);Ov001_SetStepCallback(&Ov001_OpenAccessPointMenu);}
else{p=GetCurrentMapRecord();LoadSaveSlot(p[0xf4]);Ov001_SetNextScreenMode(0,1);Ov001_SetStepCallback(&func_ov001_02181a84);}break;
}
Ov001_FreeAlloc(&data_ov001_02193db4);
}
#pragma pop
/* Redraw the map list's info panel: work out the list's top row from its pixel
 * scroll position, redraw the five visible rows' text and icon sprites, copy the
 * matching slice of the list background into the map-preview tilemap, queue that
 * tilemap's upload and place the row sprites. */
void MapListRedrawInfoPanel(void) {
    s32 HardwareDivide(u16, s32);
    void DrawMapInfoRowText(s32, s32);
    void DrawMapInfoRowIcon(s32, s32);
    void MapListUpdateRowSprites(void);
    M2C_UNK RequestMapPreviewUpdate();
    M2C_UNK CopyMapPreviewRows(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK TextPanel_ClearText(s32, M2C_UNK);
    M2C_UNK CloseTextPanel(s32);
    extern u16 gMapPreviewRowOffsets[];
    extern M2C_UNK gMapListState;
    s32 topRow;
    s32 row;
    s32 line;

    topRow = HardwareDivide(M2C_FIELD(&gMapListState, u16 *, OV001_MAP_LIST_SCROLL), OV001_MAP_LIST_ROW_HEIGHT);
    TextPanel_ClearText(M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_TEXT_PANEL), 0);
    row = topRow;
    line = 0;
    do {
        DrawMapInfoRowText(row, line);
        line += 1;
        row += 1;
    } while (line < 5);
    CopyMapPreviewRows(M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_BG_TILEMAP) + (gMapPreviewRowOffsets[topRow] * 2), 0, 0x1E, 0x13);
    line = 0;
    do {
        DrawMapInfoRowIcon(topRow, line);
        line += 1;
        topRow += 1;
    } while (line < 5);
    RequestMapPreviewUpdate();
    CloseTextPanel(M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_TEXT_PANEL));
    MapListUpdateRowSprites();
}

#pragma opt_common_subs off
/* Draws the text of one row of the map-list info panel at the given screen
 * line: the map name (row 0), a bar of '*' characters whose length is the map
 * size class (row 1), or one of the record's dotted 4-byte values (rows 3-5 and
 * 7-8, each gated by its presence flag).  Rows with nothing to show are skipped. */
void DrawMapInfoRowText(s32 row,s32 line){
void *GetCurrentMapRecord(void);
void DrawMapInfoString(u8*,s32);void DrawMapInfoDottedValue(void*,s32);
u8 *record=GetCurrentMapRecord();s32 barLength;u8 text[33];
switch((u32)row){
case 0:DrawMapInfoString(record+0x40,line);break;
case 1:
switch((u32)(record[0xe6]<<30)>>30){case 0:return;case 1:barLength=10;break;case 2:barLength=26;break;case 3:barLength=32;break;}
if(((u32)(record[0xe6]<<24)>>26)==1)barLength/=2;
MI_CpuFill8(text,0,33);MemSet(text,42,barLength);DrawMapInfoString(text,line);break;
case 3:if(record[0xf5])return;DrawMapInfoDottedValue(record+0xc0,line);break;
case 4:if(record[0xf5])return;DrawMapInfoDottedValue(record+0xf0,line);break;
case 5:if(record[0xf5])return;DrawMapInfoDottedValue(record+0xc4,line);break;
case 7:if(record[0xf6])return;DrawMapInfoDottedValue(record+0xc8,line);break;
case 8:if(record[0xf6])return;DrawMapInfoDottedValue(record+0xcc,line);break;
}
}

void DrawMapInfoRowIcon(s32 row, s32 slot) {
    void *GetCurrentMapRecord(void);
    s32 IsMapListChoiceAvailable(u32);
    void func_ov001_0217e67c(s32, s32, s32);
    extern M2C_UNK gMapListState;
    u8 *record;
    s32 icon, variant;

    record = GetCurrentMapRecord();
    switch (row) {
    case 0:
    case 1:
        icon = 0;
        variant = 0;
        if (IsMapListChoiceAvailable(icon) == 0)
            variant = 2;
        break;
    case 2: {
        u8 *flags = M2C_FIELD(&gMapListState, u8 **, 8);
        u8 present = record[0xf5];
        u8 available = flags[4];
        s32 secondary, secondaryVariant = 0;
        if (present != 0) {
            icon = 1;
            secondary = 4;
        } else {
            icon = 2;
            secondary = 3;
        }
        variant = available ? 1 : secondaryVariant;
        if (flags[5] != 0)
            secondaryVariant = 1;
        func_ov001_0217e67c(secondary, secondaryVariant, slot);
        break;
    }
    case 3:
    case 4:
    case 5:
        icon = 0;
        variant = record[0xf5] != 0 ? 2 : icon;
        break;
    case 6: {
        s32 secondary, secondaryVariant = 0;
        u8 *flags;
        variant = 0;
        if (record[0xf6] != 0) {
            icon = 1;
            secondary = 4;
        } else {
            if (record[0xf5] == 0)
                variant = 2;
            icon = 2;
            secondary = 3;
        }
        flags = M2C_FIELD(&gMapListState, u8 **, 8);
        if (flags[6] != 0)
            variant = 1;
        if (flags[7] != 0)
            secondaryVariant = 1;
        func_ov001_0217e67c(secondary, secondaryVariant, slot);
        break;
    }
    case 7:
    case 8:
        icon = 0;
        variant = record[0xf6] != 0 ? 2 : icon;
        break;
    default:
        icon = 0;
        variant = 2;
        break;
    }
    func_ov001_0217e67c(icon, variant, slot);
}

#pragma opt_common_subs reset
/* Test whether a map-list choice can be taken with the current working save
 * slot: choices 0/1 need a slot that is not written, the choices that edit the
 * +0xc0/+0xc4 codes need those codes present (SAVE_SLOT_EMPTY_A clear) and the
 * ones that edit the +0xc8/+0xcc codes need the other pair present.  Choices
 * with no such requirement are always available. */
s32 IsMapListChoiceAvailable(u32 choice) {
    void *GetCurrentMapRecord();
    s32 available;
    void *record;

    record = GetCurrentMapRecord();
    available = 1;
    switch (choice) {
    default:
        break;
    case 7:
        if (M2C_FIELD(record, u8 *, SAVE_SLOT_EMPTY_A) == 0) {
            available = 0;
        }
        break;
    case 0:
    case 1:
        if ((u32) (u8) (M2C_FIELD(record, u8 *, SAVE_SLOT_STATUS_REL) + 0xFF) <= 1U) {
            available = 0;
        }
        break;
    case 4:
    case 5:
    case 6:
        if (M2C_FIELD(record, u8 *, SAVE_SLOT_EMPTY_A) != 0) {
            available = 0;
        }
        break;
    case 9:
    case 10:
        if (M2C_FIELD(record, u8 *, SAVE_SLOT_EMPTY_B) != 0) {
            available = 0;
        }
        break;
    }
    return available;
}

void func_ov001_0217e67c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_ov001_0217ee24(s32);
    M2C_UNK Ov001_LoadSpriteObjLayout(M2C_UNK);
    extern M2C_UNK data_ov001_0218f8ee;
    extern M2C_UNK gMapListState;
    u16 sp[5];
    void **var_r4;
    s32 *temp_r2;

    sp[0] = 0xCC;
    sp[1] = 0xC0;
    sp[2] = 0xC0;
    sp[3] = 0x8F;
    sp[4] = 0x8F;
    var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x18 + (arg2 * 4);
    if ((u32) (arg0 - 1) <= 1U) {
        if (func_ov001_0217ee24(arg2) == 2) {
            var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x2C;
        } else {
            var_r4 = M2C_FIELD(&gMapListState, void **, 8) + 0x30;
        }
    }
    temp_r2 = (s32 *) *var_r4;
    if (((u8 *) arg1)[(s32) &data_ov001_0218f8ee + arg0 * 3] != 0) {
        Ov001_LoadSpriteObjLayout(0);
        M2C_FIELD(*var_r4, s32 *, 0) = (s32) (((u32) (sp[arg0] << 0x17) >> 7) | (M2C_FIELD(*var_r4, s32 *, 0) & 0xFE00FF00));
        M2C_FIELD(*var_r4, u16 *, 4) = (u16) ((M2C_FIELD(*var_r4, u16 *, 4) & ~0xC00) | 0xC00);
        return;
    }
    M2C_FIELD(temp_r2, s32 *, 0) = (s32) ((M2C_FIELD(temp_r2, s32 *, 0) & 0xFE00FF00) | 0x01000000);
}

/* Draws a map name on the map-list info panel, wrapping onto a second line 12
 * pixels below: up to 16 characters per line (a shorter name is centred one line
 * further down), rendered through the panel's text context. */
void DrawMapInfoString(u8 *text,s32 line){
extern M2C_UNK gMapListState;
s32 StringLengthUpTo(u8 *,s32);
M2C_UNK MI_CpuFill8(void *,s32,s32);
M2C_UNK DrawTextRun(s32,s32,s32,s32,s32,M2C_UNK *,s32);
u16 glyphs[17];s32 length,firstLen,i,y;
MI_CpuFill8(glyphs,0,0x22);
length=StringLengthUpTo(text,32);
firstLen=length<=16?length:16;
for(i=0;i<firstLen;i++){if(text[i]==32)glyphs[i]=KBD_KEY_SPACE;else glyphs[i]=text[i];}
y=line*29+2;
if(length<=16)y+=5;
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0x14),72,y,2,8,(M2C_UNK *)glyphs,1);
if(length<=16)return;
MI_CpuFill8(glyphs,0,0x22);
length-=16;
for(i=0;i<length;i++){if(text[i+16]==32)glyphs[i]=KBD_KEY_SPACE;else glyphs[i]=text[i+16];}
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),s32 *,0x14),72,y+12,2,8,(M2C_UNK *)glyphs,1);
}

/* Draws one row of the map-list info panel's dotted 4-byte value (an address
 * or code) as "%3d.%3d.%3d.%3d." at the given panel line. */
void DrawMapInfoDottedValue(void *value, s32 line) {
    M2C_UNK StringFormatWide(M2C_UNK *, M2C_UNK, M2C_UNK *, u8, s32, s32, s32);
    M2C_UNK DrawTextRun(s32, M2C_UNK, s32, M2C_UNK, s32, M2C_UNK *, s32);
    extern u8 sDottedValueFormat[];
    extern M2C_UNK gMapListState;
    u8 text[0x20];

    StringFormatWide(text, 0x10, sDottedValueFormat, M2C_FIELD(value, u8 *, 0), (s32) M2C_FIELD(value, u8 *, 1), (s32) M2C_FIELD(value, u8 *, 2), (s32) M2C_FIELD(value, u8 *, 3));
    DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapListState, void **, OV001_MAP_LIST_OBJECT), s32 *, OV001_MAP_LIST_TEXT_PANEL), 0x5F, (line * OV001_MAP_LIST_ROW_HEIGHT) + 8, 2, 7, text, 1);
}

#pragma push
#pragma opt_strength_reduction off
void MapListUpdateRowSprites(void){
s32 HardwareDivide(u16,s32);s32 HardwareDivideRemainder(u16,s32);extern M2C_UNK gMapListState;
s32 row,y,i,v;u32 *p;u32 xy[2];
row=HardwareDivide(M2C_FIELD(&gMapListState,u16 *,4),29);
y=52-HardwareDivideRemainder(M2C_FIELD(&gMapListState,u16 *,4),29);
if(M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x34)){
p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x34);
if(row==0)xy[1]=38;else xy[1]=256;
*p=((xy[1]<<23)>>7)|((*p&0xfe00ff00)|(u8)y);}
v=y;i=0;do{
u32 old,x; p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8)+i*4,u32 **,0x18);i++;
old=*p;x=(old&0x1ff0000)>>16;*p=(old&0xfe00ff00)|(u8)v|((x<<23)>>7);
xy[0]=old&255;xy[1]=x;v+=29;
}while(i<5);
*(volatile u32 *)&xy[0]=xy[0];*(volatile u32 *)&xy[1]=xy[1];
if(row<=2){u32 old,x,z;p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x2c);old=*p;z=old&255;x=(old&0x1ff0000)>>16;xy[0]=z;xy[1]=x;*p=(old&0xfe00ff00)|(u8)((2-row)*29+y)|((x<<23)>>7);}else{p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x2c);*p=(*p&0xfe00ff00)|0x1000000;}
if(row>=2&&row<=6){u32 old,x,z;p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x30);old=*p;z=old&255;x=(old&0x1ff0000)>>16;xy[0]=z;xy[1]=x;*p=(old&0xfe00ff00)|(u8)((6-row)*29+y)|((x<<23)>>7);}else{p=M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u32 **,0x30);*p=(*p&0xfe00ff00)|0x1000000;}
M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,0x44)=1;}
#pragma pop
