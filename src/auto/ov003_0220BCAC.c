/* 13 functions from 0x0220BCAC to 0x0220C6C8 (ov003), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "ov003_menu.h"

#pragma push
#pragma opt_propagation off
static inline void SetSliderPosition(void *p,s16 value) {
M2C_FIELD(p,s16 *,18)=value;
if(M2C_FIELD(p,s16 *,22)>=value) {
s16 low=M2C_FIELD(p,s16 *,20);
M2C_FIELD(p,s16 *,18)=value>=low?value:low;
}
}
#pragma pop

typedef struct {
    u8 mode : 4;
    u8 unk_4 : 4;
} Ov003ModeByte;

void RequestMenuMode(void *, s32);
#pragma opt_propagation off
void func_ov003_0220bcac(void *arg0) {
    extern s32 Divide(s32, s32);
    extern void ScrollBar_PlaceThumb(void *, s16, s16);
    extern void ApplySoundVolumeSliders(void *);

    void *sub;
    void *p;
    s16 f12, f14, f16, f08, f14p, f12p, diff;
    s16 r6;
    s32 val, q, sum;

    sub = M2C_FIELD(arg0, void **, 0x60);
    SetSliderPosition(sub,95);
    p = M2C_FIELD(sub, void **, 0x1C);
    f12 = M2C_FIELD(sub, s16 *, 0x12);
    f14p = M2C_FIELD(p, s16 *, 0x14);
    f12p = M2C_FIELD(p, s16 *, 0x12);
    f16 = M2C_FIELD(sub, s16 *, 0x16);
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    r6 = M2C_FIELD(sub, s16 *, 0x8);
    diff = f14p - f12p;
    val = f12 * diff;
    q = Divide(val, f16 - f14);
    sum = r6 + q;
    p=M2C_FIELD(sub,void **,0x1c);
    ScrollBar_PlaceThumb(p, (s16)sum, M2C_FIELD(p, s16 *, 0xA));

    sub = M2C_FIELD(arg0, void **, 0x64);
    SetSliderPosition(sub,95);
    p = M2C_FIELD(sub, void **, 0x1C);
    f12 = M2C_FIELD(sub, s16 *, 0x12);
    f14p = M2C_FIELD(p, s16 *, 0x14);
    f12p = M2C_FIELD(p, s16 *, 0x12);
    f16 = M2C_FIELD(sub, s16 *, 0x16);
    f14 = M2C_FIELD(sub, s16 *, 0x14);
    r6 = M2C_FIELD(sub, s16 *, 0x8);
    diff = f14p - f12p;
    val = f12 * diff;
    q = Divide(val, f16 - f14);
    sum = r6 + q;
    p=M2C_FIELD(sub,void **,0x1c);
    ScrollBar_PlaceThumb(p, (s16)sum, M2C_FIELD(p, s16 *, 0xA));

    ApplySoundVolumeSliders(arg0);

    p = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(p, s32 *, 0x4) = 0;
    if (*(u8 *)((u8 *)p + 0x14)) {
        while (M2C_FIELD(p, s32 *, 0x4) > M2C_FIELD(p, s32 *, 0x8))
            M2C_FIELD(p, s32 *, 0x4) -= M2C_FIELD(p, s32 *, 0x8) - M2C_FIELD(p, s32 *, 0xC) + 1;
        while (M2C_FIELD(p, s32 *, 0x4) < M2C_FIELD(p, s32 *, 0xC))
            M2C_FIELD(p, s32 *, 0x4) += M2C_FIELD(p, s32 *, 0x8) - M2C_FIELD(p, s32 *, 0xC) + 1;
    } else {val=M2C_FIELD(p,s32 *,0x4);q=M2C_FIELD(p,s32 *,0x8);if(val<=q){q=M2C_FIELD(p,s32 *,0xC);if(val>=q)q=val;}M2C_FIELD(p,s32 *,0x4)=q;}
    M2C_FIELD(p, s32 *, 0x1C) = 0;
    if (*(u8 *)((u8 *)p + 0x2C)) {
        while (M2C_FIELD(p, s32 *, 0x1C) > M2C_FIELD(p, s32 *, 0x20))
            M2C_FIELD(p, s32 *, 0x1C) -= M2C_FIELD(p, s32 *, 0x20) - M2C_FIELD(p, s32 *, 0x24) + 1;
        while (M2C_FIELD(p, s32 *, 0x1C) < M2C_FIELD(p, s32 *, 0x24))
            M2C_FIELD(p, s32 *, 0x1C) += M2C_FIELD(p, s32 *, 0x20) - M2C_FIELD(p, s32 *, 0x24) + 1;
    } else {q=M2C_FIELD(p,s32 *,0x20);val=M2C_FIELD(p,s32 *,0x1C);if(val<=q){q=M2C_FIELD(p,s32 *,0x24);if(val>=q)q=val;}M2C_FIELD(p,s32 *,0x1C)=q;}
    M2C_FIELD(p, s32 *, 0x34) = 1;
    if (*(u8 *)((u8 *)p + 0x44)) {
        while (M2C_FIELD(p, s32 *, 0x34) > M2C_FIELD(p, s32 *, 0x38))
            M2C_FIELD(p, s32 *, 0x34) -= M2C_FIELD(p, s32 *, 0x38) - M2C_FIELD(p, s32 *, 0x3C) + 1;
        while (M2C_FIELD(p, s32 *, 0x34) < M2C_FIELD(p, s32 *, 0x3C))
            M2C_FIELD(p, s32 *, 0x34) += M2C_FIELD(p, s32 *, 0x38) - M2C_FIELD(p, s32 *, 0x3C) + 1;
    } else {q=M2C_FIELD(p,s32 *,0x38);val=M2C_FIELD(p,s32 *,0x34);if(val<=q){q=M2C_FIELD(p,s32 *,0x3C);if(val>=q)q=val;}M2C_FIELD(p,s32 *,0x34)=q;}
}
#pragma opt_propagation reset
s8 func_ov003_0220bf68(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0xB);
}

/* Clear sprite layer 1 of the top-screen 3D sprite engine and mark that layer
 * dirty so the engine re-uploads it; used when a unit-list row is selected. */
void Ov003_ClearSubSpriteLayer1(void) {
    M2C_UNK Clear3DSpriteLayerSub(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    Clear3DSpriteLayerSub(1);
    M2C_FIELD(g3DSpriteEngineSub, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(g3DSpriteEngineSub, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_LAYER1);
}

void func_ov003_0220bf98(void *a) {
M2C_UNK UpdateSpriteAnimation(s32);M2C_UNK StepMapSelectAnimations(void *);
s32 offset,flag,i;
UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x54));
flag=M2C_FIELD(a,u8 *,0x34)!=0;
if((u8)flag){StepMapSelectAnimations(a);return;}
UpdateSpriteAnimation(M2C_FIELD(a,s32 *,0x50));
i=0;if((s32)*M2C_FIELD(a,u8 **,0x44)<=0)return;
offset=0;do {
u32 x,y;
s32 value,limit,delta,v;
u32 address = (u32)M2C_FIELD(a,void **,0x48);
void *p = (void *)(offset + address);
x=M2C_FIELD(p,u8 *,0x11);y=M2C_FIELD(p,u8 *,0x12);
if(x==y){
 value=M2C_FIELD(p,s8 *,0x13);delta=M2C_FIELD(p,s8 *,0x15);
 limit=M2C_FIELD(p,s8 *,0x14);v=value+delta;
 if(v<=limit){if(v<0)v=0;limit=v;}
 M2C_FIELD(p,s8 *,0x13)=limit;
}else{
 value=M2C_FIELD(p,s8 *,0x13);delta=M2C_FIELD(p,s8 *,0x15);
 limit=M2C_FIELD(p,s8 *,0x14);v=value-delta;
 if(v<=limit){if(v<0)v=0;limit=v;}
 M2C_FIELD(p,s8 *,0x13)=limit;
}
y=M2C_FIELD(p,u8 *,0x12);
if(M2C_FIELD(p,u8 *,0x11)!=y&&M2C_FIELD(p,s8 *,0x13)==0)M2C_FIELD(p,u8 *,0x11)=y;
limit=M2C_FIELD(p,u16 *,14);x=M2C_FIELD(p,u16 *,12);delta=M2C_FIELD(p,u8 *,16);
if(x<(u32)limit){
 v=x+delta;if(v<=limit){if(v<205)v=205;limit=v;}
 M2C_FIELD(p,u16 *,12)=limit;
}else{
 v=x-delta;if(v>256)limit=256;else if(v>=limit)limit=v;
 M2C_FIELD(p,u16 *,12)=limit;
}
i++;offset+=36;
}while(i<(s32)*M2C_FIELD(a,u8 **,0x44));
}

/* Apply the options menu's music and sound-effect volume sliders to the game
 * settings: the two scroll bars at +0x60 (music) and +0x64 (sound effects) of the
 * options object hold the values. */
void ApplySoundVolumeSliders(void *options) {
    M2C_UNK SetMusicVolumeSetting(s16);
    M2C_UNK SetSoundEffectVolumeSetting(s16);

    SetMusicVolumeSetting(M2C_FIELD(M2C_FIELD(options, void **, 0x60), s16 *, SCROLLBAR_VALUE));
    SetSoundEffectVolumeSetting(M2C_FIELD(M2C_FIELD(options, void **, 0x64), s16 *, SCROLLBAR_VALUE));
}

#pragma opt_propagation off
void func_ov003_0220c10c(void *arg0) {
void ApplySoundVolumeSliders(void *);
void *q=**(void ***)((u8 *)arg0+0x5c);
s32 v,b;
u8 idx,k;
v = q ? *(u16 *)((u8 *)q+8) : -1;
idx = v - 11;
k = *(u8 *)(*(u8 **)((u8 *)arg0+0x3c)+15);
b=0;
if((u8)(k==8))b=(idx==0)?1:b;
if((b & 0xff) || (u8)((u8)(k==8) && idx==1))ApplySoundVolumeSliders(arg0);
}
#pragma opt_propagation reset

/* Activates the unit-list row under the cursor: records the row index in the
 * current selection slot, then runs the row's action (select the unit, show its
 * information, or open its submenu), with the row's descriptor deciding which. */
void Ov003_ActivateUnitListEntry(void *arg, s32 index){
extern void *g3DSpriteEngineSub;
s32 IsUnitAvailable(s32);
u8 *menu=arg,*selection,*desc; s32 type,value,isModeOne;void *unit;u32 unitId;
menu[MENU_FLAGS]|=MENU_FLAG_PENDING;
desc=*(u8**)((u8*)M2C_FIELD(menu,void**,MENU_ROWS)+index*MENU_ROW_STRIDE);
selection=M2C_FIELD(menu,u8**,MENU_SELECTION);
type=desc[MENU_DESC_TYPE];value=desc[MENU_DESC_VALUE];selection[selection[MENU_SELECTION_MODE]]=index;
selection=M2C_FIELD(menu,u8**,MENU_SELECTION);isModeOne=selection[MENU_SELECTION_MODE]==1;
if((u8)isModeOne){
unit=*M2C_FIELD(menu,void***,MENU_SELECTED_UNIT);
unitId=unit?M2C_FIELD(unit,u16*,8):-1;
if((u8)(unitId-11)==1 && !IsUnitAvailable(8)){type=MENU_ENTRY_INFO;value=5;}
}
switch(type){
case MENU_ENTRY_UNIT:menu[MENU_ACTION]=49;Ov003_SetRowAnimation(menu,value);Ov003_RefreshListRowAnimations(menu,0,(u8)index);Clear3DSpriteLayerSub(1);M2C_FIELD(g3DSpriteEngineSub,u8*,0x46)|=2;PlaySoundEffect(0x1000d);break;
case MENU_ENTRY_INFO:EnableMapConfirm();SetMapCategory(value);Ov003_RefreshListRowAnimations(menu,0,(u8)index);Sprite_ResumeAnimation(menu);PlaySoundEffect(0x1000e);break;
case MENU_ENTRY_SUBMENU:switch(desc[MENU_DESC_VALUE]){case 0:case 1:case 2:PlaySoundEffect(0x1000d);RequestMenuMode(menu,1);CreateCampaignSavePanel(value,menu);break;case 3:PlaySoundEffect(0x1000d);RequestMenuMode(menu,3);CreateEraseAllSaveDataAction(menu);break;}break;
}
}

/* Confirm the menu's current row with the given value: for the modes that confirm the
 * menu, leave it; otherwise store the value as the row's current value and, when the
 * row is not the idle row, play its select animation and queue the screen update. */
void Ov003_ConfirmRowValue(void *arg0, int arg1) {
 extern void *g3DSpriteEngineSub;
 u8 *menu=arg0; u8 *row; int rowValue;
 menu[MENU_FLAGS]&=~MENU_FLAG_PENDING;
 row=*(u8 **)(menu+MENU_SELECTION); rowValue=row[MENU_ROW_VALUE];
 PlaySoundEffect(0x1000f);   /* SOUND_MENU_CANCEL */
 if((u8)((((unsigned int)menu[MENU_MODE]<<24)>>28)==MENU_MODE_FIRST) || (u8)((((unsigned int)menu[MENU_MODE]<<24)>>28)==MENU_MODE_SECOND)){menu[MENU_SELECT_MODE]=1;DisableMapConfirm();Sprite_ResumeAnimation(menu);}
 menu[MENU_FLAGS]&=~MENU_FLAG_ANIM;
 row=*(u8 **)(menu+MENU_SELECTION);row[row[MENU_ROW_COUNT]]=arg1;
 if(rowValue!=16){menu[MENU_ACTION]=30;Ov003_SetRowAnimation(menu,rowValue);Ov003_RefreshListRowAnimations(menu,5,MENU_MODE_IDLE);Clear3DSpriteLayerSub(1);M2C_FIELD(g3DSpriteEngineSub,u8 *,0x46)|=2;}
 else {DisableMapConfirm();Sprite_ResumeAnimation(menu);}
}

/* Queue a mode switch for the menu: mark the mode byte as pending
 * (MENU_FLAGS) and store the low nibble of `mode` in the menu's MENU_MODE byte. */
void RequestMenuMode(void *menu, s32 mode) {
    u8 modeValue = mode;

    M2C_FIELD(menu, u8 *, MENU_FLAGS) |= MENU_FLAG_MODE;
    ((Ov003ModeByte *)((u8 *)menu + MENU_MODE))->mode = modeValue;
}

/* Apply the menu action deferred on this UI object: clear its pending bit and set the
   display engine's plane bits, then run the mode - 1 confirms the highlighted unit
   selection, 2 redraws the unit label, 3 resets the selection buffer. */
void RunPendingMenuAction(void *arg0) {
    s32 IsMapConfirmEnabled(void);
    void DrawMapSelectLabel(void *);
    void Ov003_ConfirmRowValue(void *, s32);
    void ClearTextChars(void);
    extern void **gCur3DSpriteEngine;

    u8 *obj = (u8 *)arg0;
    u32 state = obj[0x38];

    if (!(((u32)state << 27) >> 31)) {
        return;
    }
    obj[0x38] &= ~0x10;

    {
        u16 * volatile disp0;
        disp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp0 = (u16)((*disp0 & ~0x1) | 0x1);
    }
    {
        u16 * volatile disp1;
        disp1 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp1 = (u16)(*disp1 & ~0x2);
    }
    {
        u16 * volatile disp2;
        disp2 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp2 = (u16)(*disp2 & ~0x4);
    }
    {
        u16 * volatile disp3;
        disp3 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp3 = (u16)(*disp3 & ~0x8);
    }
    {
        u16 * volatile disp4;
        disp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp4 = (u16)(*disp4 & ~0x10);
    }
    {
        u16 * volatile disp5;
        disp5 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp5 = (u16)(*disp5 & ~0x20);
    }
    {
        u16 * volatile disp6;
        disp6 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp6 = (u16)(*disp6 & ~0x100);
    }
    {
        u16 * volatile disp7;
        disp7 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp7 = (u16)(*disp7 & ~0x200);
    }
    {
        u16 * volatile disp8;
        disp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp8 = (u16)(*disp8 & ~0x400);
    }
    {
        u16 * volatile disp9;
        disp9 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp9 = (u16)(*disp9 | 0x800);
    }
    {
        u16 * volatile disp10;
        disp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp10 = (u16)(*disp10 & ~0x1000);
    }
    {
        u16 * volatile disp11;
        disp11 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
        *disp11 = (u16)(*disp11 | 0x2000);
    }

    {
        u32 mode = ((Ov003ModeByte *)(obj + 0x36))->mode;

        switch (mode) {
        case 0:
            break;
        case 1: {
            s32 canConfirm = IsMapConfirmEnabled();
            if (canConfirm == 0) {
                return;
            }
            DrawMapSelectLabel(obj);
            {
                u16 *unit = **(u16 ***)(obj + 0x5c);
                s32 sel;
                if (unit != 0) {
                    sel = (s32)unit[4];
                } else {
                    sel = -1;
                }
                sel = sel - 0xb;
                Ov003_ConfirmRowValue(obj, (s32)(u8)sel);
            }
            return;
        }
        case 2: {
            DrawMapSelectLabel(obj);
            return;
        }
        case 3: {
            ClearTextChars();
            return;
        }
        }
    }
    return;
}

void func_ov003_0220c6a4(void) {
    M2C_UNK func_ov003_022066d8();
    func_ov003_022066d8();
}

void func_ov003_0220c6b0(void) {
    M2C_UNK func_ov003_02209310();
    func_ov003_02209310();
}

void func_ov003_0220c6bc(void) {
    M2C_UNK Ov003_UpdateMenu();
    Ov003_UpdateMenu();
}

