/* 13 functions from 0x02207A54 to 0x0220856C (ov003), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
static inline void ResetSlot(void *p, u16 value) {
M2C_FIELD(p,s32 *,8)=M2C_FIELD(p,s32 *,4);
M2C_FIELD(p,u16 *,12)=value;
func_020a9218(p);
M2C_FIELD(p,u8 *,14)=value;
M2C_FIELD(p,u8 *,15)=M2C_FIELD(p,u8 *,14);
}

/* Point both animation slots of a sprite at anim, clear its timer and flags. */
static inline void SetSlotAnim(void *p, s32 anim) {
M2C_FIELD(p,s32 *,4)=anim;
M2C_FIELD(p,s32 *,8)=anim;
M2C_FIELD(p,u16 *,12)=0;
func_020a9218(p);
M2C_FIELD(p,u8 *,14)=0;
M2C_FIELD(p,u8 *,15)=M2C_FIELD(p,u8 *,14);
}

extern u8 data_ov003_02210ac4[];
extern u8 data_ov003_02210c44[];

u8 func_ov003_02207a54(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x36) << 0x18) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02207a70(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Reset the 6 child slots of the given structure to their initial state. */
void func_ov003_02207a8c(void *arg0) {
    s32 slotOff;
    u8 i;
    void *cfg;
    void *slot;
    void *slot2;
    void *slot3;

    cfg = M2C_FIELD(arg0, void **, 0x50);
    i = 0;
    M2C_FIELD(cfg, u16 *, 2) = (u16) M2C_FIELD(cfg, u16 *, 4);
    do {
        slotOff = i * 0x24;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 4) = 1;
        i += 1;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 6) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 8) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xA) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xB) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 0xE) = 0xCD;
        slot = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot, u16 *, 0xC) = (u16) M2C_FIELD(slot, u16 *, 0xE);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x10) = 8;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x12) = 0;
        slot2 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot2, u8 *, 0x11) = (u8) M2C_FIELD(slot2, u8 *, 0x12);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x14) = 5;
        slot3 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot3, s8 *, 0x13) = (s8) M2C_FIELD(slot3, s8 *, 0x14);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x15) = 1;
    } while ((u32) i < 6U);
    M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) | 0x20);
}

#pragma thumb off
void Ov003_ApplyRowSelectionAnimations(void *arg0) {
void func_ov003_02207c7c(void *); void DrawMapSelectLabel(void *);
s32 selStep,selLevel,selId,selMode,selValue,selAux; void *row; s32 rowIndex,rowOffset; void *sprite,*pager;
sprite=M2C_FIELD(arg0,void **,0x50);rowIndex=0;
M2C_FIELD(sprite,u16 *,2)=M2C_FIELD(sprite,u16 *,4);
if((s32)*M2C_FIELD(arg0,u8 **,0x44)>0){
rowOffset=0;
do{
row=M2C_FIELD(arg0,u8 **,0x48)+rowOffset;
pager=*M2C_FIELD(arg0,void ***,0x5c);
if(pager!=NULL)selId=M2C_FIELD(pager,u16 *,MAP_SELECT_ENTRY_ID);else selId=-1U;
if(rowIndex==(u8)(selId-MAP_SELECT_ROW_ID_BASE)){selValue=256;selAux=16;selStep=1;selLevel=2;selMode=3;}
else{selValue=205;selAux=8;selStep=0;selLevel=5;selMode=1;}
M2C_FIELD(row,s8 *,MAP_SELECT_ROW_ANIM_STEP)=selStep;
M2C_FIELD(row,s8 *,MAP_SELECT_ROW_ANIM_LEVEL)=selLevel;
M2C_FIELD(row,s8 *,MAP_SELECT_ROW_ANIM_MODE)=selMode;
M2C_FIELD(row,s16 *,MAP_SELECT_ROW_ANIM_VALUE)=selValue;
M2C_FIELD(row,s8 *,MAP_SELECT_ROW_ANIM_AUX)=selAux;
rowOffset+=MAP_SELECT_ROW_STRIDE;rowIndex++;
}while(rowIndex<(s32)*M2C_FIELD(arg0,u8 **,0x44));
}
DrawMapSelectLabel(arg0);func_ov003_02207c7c(arg0);
}
u8 Ov003_GetSelectedRowIndex(void *arg0) {
    s32 var_r0;
    void *temp_r0;

    temp_r0 = *M2C_FIELD(arg0, void ***, 0x5C);
    if (temp_r0 != NULL) {
        var_r0 = M2C_FIELD(temp_r0, u16 *, 8);
    } else {
        var_r0 = -1;
    }
    return (u8) (var_r0 - 0xB);
}

void func_ov003_02207c7c(void *arg0) {
void func_02087d84(void *,u16,s32,s16,u16,s32);
s32 func_020a8ce4(s32,s32);
s32 func_020a8e28(s32,s32);
s32 func_ov003_02206690(s32,s32,s32);
void *inner,*inner2;
u16 selected;
s32 minus=-1;
s32 constant=0xcd;
s32 x;
s32 xpre,value,width,i;
s32 cond,cond2,cond3;
u8 kind,idx;
void *p;
inner=*M2C_FIELD(arg0,void ***,0x5c);
selected=inner?M2C_FIELD(inner,u16 *,8):minus;
xpre=func_020a8e28(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1),constant)+16;
i=11;
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,0)+11<=11)return;
x=(s16)xpre;
do {
width=M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1);
value=func_020a8ce4(width,constant);
if(i==selected){
inner2=*M2C_FIELD(arg0,void ***,0x5c);
cond=0;
idx=(u8)((inner2?M2C_FIELD(inner2,u16 *,8):minus)-11);
kind=M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15);
if(kind==8){if(idx<=1)cond=1;}
if(!(cond&255)){
idx=(u8)((inner2?M2C_FIELD(inner2,u16 *,8):minus)-11);
if(kind==8)cond2=1;else cond2=0;
cond3=(cond2&255) && func_ov003_02206690(idx,2,4)!=0;
if(cond3&255)goto half;
}else {half: width>>=1;}
p=M2C_FIELD(arg0,void **,0x44);
func_02087d84(M2C_FIELD(arg0,void **,0x5c),(u16)i,16,(s16)(M2C_FIELD(p,u8 *,4)*(i-11)+2),(u16)width,M2C_FIELD(p,u8 *,2));
}else{
p=M2C_FIELD(arg0,void **,0x44);
func_02087d84(M2C_FIELD(arg0,void **,0x5c),(u16)i,x,(s16)(M2C_FIELD(p,u8 *,4)*(i-11)+2),(u16)value,M2C_FIELD(p,u8 *,2));
}
i++;
}while(i<M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,0)+11);
}

u8 func_ov003_02207e38(void *arg0, s32 arg1) {
    s32 func_ov003_02206690(s32, s32, s32);
    s32 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if ((var_r0 & 0xFF) && (func_ov003_02206690(arg1, 2, 4) != 0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (u8) var_r0;
}

/* Redraw the label of the ov003 map-select screen once its transition timer has
 * run out: clear 3D-sprite layer 1 on the top-screen engine, format the name of
 * the selected row and draw it, then flip the label's blink bit. */
void DrawMapSelectLabel(void *arg0) {
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;
    M2C_UNK Clear3DSpriteLayer(s32);
    void *BuildSaveSlotText(s32,u8);
    s32 GetLocalizedText(s32);
    void StringCopy(void *,void *);
    s32 StringFormat(void *,void *,...);
    void DrawTextLine(s32,s32,s32,void *,u16,u16);
    extern char sTextPassThroughFormat[];
    u16 **saved=gCur3DSpriteEngine;
    char text[256];
    s32 scale;
    void *current,*kindDesc;
    u8 flag,kind,rowId,oldFlags,flags;
    u32 bit;
    gCur3DSpriteEngine=g3DSpriteEngineSub;
    Clear3DSpriteLayer(1);
    flag=M2C_FIELD(arg0,u8 *,0x34)!=0;
    if(!flag){
    current=*M2C_FIELD(arg0,void ***,0x5c);
    flags=M2C_FIELD(arg0,u8 *,0x38);
    kindDesc=M2C_FIELD(arg0,void **,0x3c);
    rowId=(u8)((current?M2C_FIELD(current,u16 *,MAP_SELECT_ENTRY_ID):-1)-MAP_SELECT_ROW_ID_BASE);
    bit=((u32)flags<<29)>>31;
    kind=M2C_FIELD(kindDesc,u8 *,MAP_SELECT_KIND);
    scale=(bit<<8)-bit+1;
    switch(kind){
    case 9:StringCopy(text,BuildSaveSlotText(0,rowId));break;
    case 11:StringCopy(text,BuildSaveSlotText(5,rowId));break;
    case 10:StringCopy(text,BuildSaveSlotText(1,rowId));break;
    default:
    rowId=(u8)((current?M2C_FIELD(current,u16 *,MAP_SELECT_ENTRY_ID):-1)-MAP_SELECT_ROW_ID_BASE);
    StringFormat(text,sTextPassThroughFormat,GetLocalizedText(M2C_FIELD(*(void **)((char *)M2C_FIELD(arg0,void **,0x48)+(s16)rowId*(s16)MAP_SELECT_ROW_STRIDE),s32 *,MAP_SELECT_ROW_TEXT_KEY)));
    break;
    }
    DrawTextLine(0,0,1,text,0x3000,(u16)scale);
    }
    M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
    bit=((u32)M2C_FIELD(arg0,volatile u8 *,0x38)<<29)>>31;
    oldFlags=M2C_FIELD(arg0,u8 *,0x38);
    flag=!bit;
    M2C_FIELD(arg0,u8 *,0x38)=(oldFlags&~MAP_SELECT_BLINK)|(((u32)flag<<31)>>29);
    gCur3DSpriteEngine=saved;
}

u8 func_ov003_0220801c(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Builds the map-select label's 3D-sprite transform on the sub-screen engine:
 * reads the two label tween channels (1.0 when the label is idle), shows or
 * hides its layer from whether both are non-zero, and writes the scale transform
 * into the bank's second matrix. */
void UpdateMapSelectLabelTransform(void *arg0) {
    M2C_UNK Build3DSpriteTransform(s32 *, u16 *);
    s32 GetSpriteAnimValue(s32);
    extern u16 **g3DSpriteEngineSub;
    extern u16 **gCur3DSpriteEngine;
    DS3DSpriteTransform transform;
    u16 * bankClear;
    u16 * bankSet;
    s32 flagA;
    s32 flagB;
    u16 **savedEngine;
    u16 scaleY;
    u16 scaleX;
    s32 valueX;
    s32 valueY;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        flagA = 1;
    } else {
        flagA = 0;
    }
    if (!(flagA & 0xFF)) {
        valueX = 0x100;
    } else {
        valueX = GetSpriteAnimValue(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 **, 0x18));
    }
    scaleX = valueX;
    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        flagB = 1;
    } else {
        flagB = 0;
    }
    if (!(flagB & 0xFF)) {
        valueY = 0x100;
    } else {
        valueY = GetSpriteAnimValue(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 **, 0x1C));
    }
    scaleY = valueY;
    if(scaleX==0 || scaleY==0){bankClear=*gCur3DSpriteEngine;*(*(u16 * volatile *)&bankClear) = *(*(u16 * volatile *)&bankClear) & ~DS3D_BANK_MODE3;}else{bankSet=*gCur3DSpriteEngine;*(*(u16 * volatile *)&bankSet) = *(*(u16 * volatile *)&bankSet) | DS3D_BANK_MODE3;}
    transform.scaleY = scaleY;
    transform.x = 0x80;
    transform.y = 0x88;
    transform.scaleX = scaleX;
    transform.angle = 0;
    transform.mapX = 0x80;
    transform.mapY = 0x88;
    Build3DSpriteTransform((s32 *)&transform, (u16 *)((u8 *)*gCur3DSpriteEngine + 0x24));
    gCur3DSpriteEngine = savedEngine;
}

/* Reset the three animation slots of every map-select preview row, and the two
   slots of the label's shared animation pair, ready for the new selection. */
void Ov003_ResetListRowAnimations(void *screen) {
    s32 rowOffset;
    s32 row;
    row = 0;
    if ((s32)*M2C_FIELD(screen, u8 **, 0x44) > 0) {
        do {
            rowOffset = row * MAP_SELECT_ROW_STRIDE;
            ResetSlot(M2C_FIELD(M2C_FIELD(screen, u8 **, 0x48) + rowOffset, void **, 0x18), 0);
            ResetSlot(M2C_FIELD(M2C_FIELD(screen, u8 **, 0x48) + rowOffset, void **, 0x1C), 0);
            ResetSlot(M2C_FIELD(M2C_FIELD(screen, u8 **, 0x48) + rowOffset, void **, 0x20), 0);
            row++;
        } while (row < (s32)*M2C_FIELD(screen, u8 **, 0x44));
    }
    ResetSlot(M2C_FIELD(M2C_FIELD(screen, void **, 0x4C), void **, 0x18), 0);
    ResetSlot(M2C_FIELD(M2C_FIELD(screen, void **, 0x4C), void **, 0x1C), 0);
}

#pragma push
#pragma scheduling off
void Ov003_RefreshListRowAnimations(void *arg0, s32 arg1, s32 arg2) {
    s32 a, b, c, d;
    s32 i;
    s32 off;
    void *base;

    Ov003_ResetListRowAnimations(arg0);
    switch (arg1) {
    case 0:
    case 5:
        a = 12;
        c = 0;
        d = 6;
        b = 17;
        break;
    case 10:
        a = 22;
        b = 27;
        c = a;
        d = b;
        break;
    }
    for (i = 0; i < (s32)*M2C_FIELD(arg0, u8 **, 0x44); i++) {
        off = i * 0x24;
        base = M2C_FIELD(arg0, s32 *, 0x48) + off;
        if (i == arg2) {
            SetSlotAnim(M2C_FIELD(base, void **, 0x18), (void *)(data_ov003_02210ac4 + c * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x1C), (void *)(data_ov003_02210ac4 + d * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x20), (void *)data_ov003_02210c44);
            if (M2C_FIELD(base, u8 *, 0x11) == 0) {
                M2C_FIELD(base, u8 *, 0x13) = 0;
                M2C_FIELD(base, u8 *, 0x11) = 1;
            }
            M2C_FIELD(base, u16 *, 0xC) = 0x100;
        } else {
            SetSlotAnim(M2C_FIELD(base, void **, 0x18), (void *)(data_ov003_02210ac4 + a * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x1C), (void *)(data_ov003_02210ac4 + b * 12));
            M2C_FIELD(M2C_FIELD(base, void **, 0x20), u8 *, 0xE) = 1;
        }
    }
    {
        s32 slot;
        slot = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), void **, 0x18);
        M2C_FIELD(slot, s32 *, 4) = (s32)(data_ov003_02210ac4 + a * 12);
        ResetSlot(slot, 0);
        slot = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), void **, 0x1C);
        M2C_FIELD(slot, s32 *, 4) = (s32)(data_ov003_02210ac4 + b * 12);
        ResetSlot(slot, 0);
    }
}
#pragma pop
void func_ov003_022084f0(void *arg0) {
    M2C_UNK func_020a91a8(s32);
    void UpdateMapSelectLabelTransform(void *);
    void *temp_r6;
    void *var_r5;
    s32 var_r4;
    s32 var_r7;

    var_r4 = 0;
    var_r5 = arg0;
    if ((s32) *M2C_FIELD(var_r5, u8 **, 0x44) > 0) {
        var_r7 = 0;
        do {
            temp_r6 = M2C_FIELD(var_r5, s32 *, 0x48) + var_r7;
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x18));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x1C));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x20));
            ++var_r4;
            var_r7 += 0x24;
        } while (var_r4 < (s32) *M2C_FIELD(var_r5, u8 **, 0x44));
    }
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x18));
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x1C));
    UpdateMapSelectLabelTransform(var_r5);
}

