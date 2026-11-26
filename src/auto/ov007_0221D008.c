/* 7 functions from 0x0221D008 to 0x0221E004 (ov007), found by ds-decomp. */
#include "common.h"
#include "mapedit.h"

void MapEditTextDeleteAccentAction(u8 *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK MI_CpuCopy32(s32 *, s8 *, M2C_UNK);
    M2C_UNK Mb_StringCopy(s32 *, M2C_UNK);
    s32 Mb_StringCompare(s32 *, M2C_UNK *);
    s32 IsLeadByte(s32 *);
    s32 MeasureStringWidth(s32 *);
    M2C_UNK GotoSpriteAnimationLabel(s32, M2C_UNK);
    M2C_UNK RenderTextLayerMessage(void *, M2C_UNK, M2C_UNK, s32);
    void *CreateTextLayer(s32);
    M2C_UNK PauseSpriteUpdate();
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 data_ov007_022205c0;
    extern s32 gGlyphDakuten;
    extern s32 data_ov007_02220960;
    extern s32 gGlyphHandakuten;
    extern s32 gSoftKeyLayoutJp[];
    extern s32 gMapEditRecords;
    extern s32 gMapEditObjectList;
    s32 padding[17];
    s32 scratch[17];
    void *ctx;
    s8 *phase;
    ctx = *(void **)(arg0 + 0x10);
    phase = (s8 *)ctx + 0x3c;
    switch (arg0[0]) {
    case 0x67: {
        s32 index;
        s32 i;
        if (*phase > 0) {
            index = (s8)(*phase - 1);
            if (index < 0 || index >= 17) goto shift_67;
            if (!(index < 17 && ((s32 *)&gMapEditObjectList)[index] != 0) &&
                (index <= 0 || ((s32 *)&gMapEditObjectList)[index - 1] == 0)) goto shift_67;
            *phase = (s8)index;
        shift_67:
            i = *phase;
            while (i < 16) {
                ((s32 *)&gMapEditObjectList)[i] = ((s32 *)&gMapEditObjectList)[i + 1];
                i++;
            }
            M2C_FIELD(&gMapEditRecords, s32 *, 0x44) = 0;
            PlaySoundEffect(0x1000d);
            return;
        }
        index = *phase;
        if (index != 0 || ((s32 *)&gMapEditObjectList)[index] == 0) goto no_move_67;
        for (i = index; i < 16; i++) {
            ((s32 *)&gMapEditObjectList)[i] = ((s32 *)&gMapEditObjectList)[i + 1];
        }
        M2C_FIELD(&gMapEditRecords, s32 *, 0x44) = 0;
        PlaySoundEffect(0x1000d);
        return;
    no_move_67:
        PlaySoundEffect(0x1001d);
        return;
    }
case 0x68: if((s32)&gSoftKeyLayoutJp[0]==*(s32 *)((u8 *)ctx+0x34)){
s32 old=*phase;
s32 *value=&data_ov007_02220960;
if(Mb_StringCompare(value,&gGlyphDakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(Mb_StringCompare(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(Mb_StringCompare(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c);
}else {PlaySoundEffect(0x1001d);return;}
} else if(Mb_StringCompare(value,&gGlyphHandakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(Mb_StringCompare(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(Mb_StringCompare(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258);
}else {PlaySoundEffect(0x1001d);return;}
}
if(*phase>=16){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; PauseSpriteUpdate(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=CreateTextLayer((s32)ctx); RenderTextLayerMessage(sprite,2,0x2800,0x46000012); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; GotoSpriteAnimationLabel((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
MI_CpuCopy32(&gMapEditObjectList,(s8 *)scratch,0x44);
scratch[*phase]=0;
Mb_StringCopy(&scratch[*phase],(s32)value);
{s32 *node; u32 count=0; node=scratch; if(*node){do{if(IsLeadByte(node)==0){if(count)count++;} count+=MeasureStringWidth(node);}while(*++node);}
if(count>64){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; PauseSpriteUpdate(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=CreateTextLayer((s32)ctx); RenderTextLayerMessage(sprite,2,0x2800,0x46000013); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; GotoSpriteAnimationLabel((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
}
MI_CpuCopy32(scratch,(s8 *)&gMapEditObjectList,0x44);
{ s8 next=(s8)(*phase+1); if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next; }
PlaySoundEffect(0x1000d);return;
}else {
s32 old=*phase;
s32 *value=&data_ov007_022205c0;
if(Mb_StringCompare(value,&gGlyphDakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(Mb_StringCompare(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(Mb_StringCompare(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c);
}else {PlaySoundEffect(0x1001d);return;}
} else if(Mb_StringCompare(value,&gGlyphHandakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(Mb_StringCompare(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(Mb_StringCompare(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258);
}else {PlaySoundEffect(0x1001d);return;}
}
if(*phase>=16){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; PauseSpriteUpdate(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=CreateTextLayer((s32)ctx); RenderTextLayerMessage(sprite,2,0x2800,0x46000012); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; GotoSpriteAnimationLabel((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
MI_CpuCopy32(&gMapEditObjectList,(s8 *)padding,0x44);
padding[*phase]=0;
Mb_StringCopy(&padding[*phase],(s32)value);
{s32 *node; u32 count=0; node=padding; if(*node){do{if(IsLeadByte(node)==0){if(count)count++;} count+=MeasureStringWidth(node);}while(*++node);}
if(count>64){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; PauseSpriteUpdate(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=CreateTextLayer((s32)ctx); RenderTextLayerMessage(sprite,2,0x2800,0x46000013); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; GotoSpriteAnimationLabel((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
}
MI_CpuCopy32(padding,(s8 *)&gMapEditObjectList,0x44);
{ s8 next=(s8)(*phase+1); if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next; }
PlaySoundEffect(0x1000d);return;
} default:return;}}

/* Navigate the delete/accent softkeys, or apply the selected action on A. */
void MapEditTextDeleteAccentInput(u8 *selection) {
    M2C_UNK FocusSpriteSlotById(u8);
    extern void *gKeyState;
    u16 repeat, pressed;
    u8 slot, oldSlot;
    oldSlot = *selection;
    pressed = ((KeyState *)gKeyState)->pressed;
    slot = oldSlot;
    repeat = ((KeyState *)gKeyState)->repeat;
    if (pressed & KEY_A) { MapEditTextDeleteAccentAction(selection); return; }
    if (repeat & KEY_UP) {
        switch (oldSlot) {
        case SOFTKEY_DELETE: if (repeat == pressed) slot = 64; break;
        case SOFTKEY_ACCENT: if (repeat == pressed) slot = 66; break;
        }
        if (slot >= (u32)SOFTKEY_DELETE) { if (slot > (u32)SOFTKEY_ACCENT) {} else goto horizontal; }
    } else if (repeat & KEY_DOWN) {
        switch (oldSlot) {
        case SOFTKEY_DELETE: if (repeat == pressed) slot = 4; break;
        case SOFTKEY_ACCENT: if (repeat == pressed) slot = 6; break;
        }
        if (slot >= (u32)SOFTKEY_DELETE && slot <= (u32)SOFTKEY_ACCENT) goto horizontal;
    } else {
    horizontal:
        if (repeat & KEY_LEFT) {
            switch (slot) {
            case SOFTKEY_ACCENT: slot = SOFTKEY_DELETE; break;
            case SOFTKEY_DELETE: slot = SOFTKEY_MODE_JP; break;
            }
            if (slot >= (u32)SOFTKEY_DELETE && slot <= (u32)SOFTKEY_ACCENT) goto done;
        } else if (repeat & KEY_RIGHT) {
            switch (slot) {
            case SOFTKEY_ACCENT: slot = SOFTKEY_CANCEL; break;
            case SOFTKEY_DELETE: slot = SOFTKEY_ACCENT; break;
            }
        }
    }
done:
    if (oldSlot == slot) return;
    FocusSpriteSlotById(slot);
}

void func_ov007_0221dcc0(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

void func_ov007_0221dcd4(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

/* Confirm/cancel handler of the map editor's text-entry softkeys. Cancel (0x69)
 * closes the editor; confirm (0x6A) packs the edited glyph line into the record
 * buffer when it holds at least one non-blank glyph, otherwise it plays the
 * error animation and sound. */
void MapEditTextActionInput(void *arg0) {
    M2C_UNK GotoSpriteAnimationLabel(s32, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32 *, s8 *, M2C_UNK);
    s32 Mb_StringCompare(s32 *, M2C_UNK *);
    M2C_UNK RenderTextLayerMessage(void *, M2C_UNK, M2C_UNK, s32);
    void *CreateTextLayer(s32);
    s32 IsLeadByte(s32 *);
    s32 IsGlyphEscape(s32 *);
    M2C_UNK PauseSpriteUpdate();
    M2C_UNK EnableMapConfirm();
    M2C_UNK DisableMapConfirm();
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK gGlyphSpace;
    extern M2C_UNK gGlyphWideSpace;
    extern M2C_UNK gMapEditRecords;
    extern s32 gMapEditObjectList;
    s32 *srcGlyphs;
    s32 editor;
    s32 savedEngine;
    s32 entryCount;
    s32 *scan;
    s32 allBlank;
    s32 *glyphSlot;
    s8 *dest;
    u32 i;
    u8 action;
    void *dialog;

    action = M2C_FIELD(arg0, u8 *, 0);
    editor = M2C_FIELD(arg0, s32 *, 0x10);
    switch (action) {                              /* irregular */
    case 0x69:
        DisableMapConfirm();
        GotoSpriteAnimationLabel(editor, 3);
        PlaySoundEffect(0x1000F);
        return;
    case 0x6A:
        entryCount = 0;
        scan = &gMapEditObjectList;
        if (M2C_FIELD(&gMapEditRecords, s32 *, 4) != 0) {
            do {
                scan += 1;
                entryCount += 1;
            } while (*scan != 0);
        }
        if (entryCount != 0) {
            allBlank = 1;
            glyphSlot = &gMapEditObjectList;
            if (M2C_FIELD(&gMapEditRecords, s32 *, 4) != 0) {
loop_9:
                if ((Mb_StringCompare(glyphSlot, &gGlyphSpace) != 0) && (Mb_StringCompare(glyphSlot, &gGlyphWideSpace) != 0)) {
                    allBlank = 0;
                } else {
                    glyphSlot += 1;
                    if (*glyphSlot != 0) {
                        goto loop_9;
                    }
                }
            }
            if (allBlank == 0) {
                srcGlyphs = &gMapEditObjectList;
                dest = M2C_FIELD(&gMapEditRecords, s8 **, 0);
                i = 0;
                while ((*srcGlyphs != 0) && (i < 0x10U)) {
                    if ((IsLeadByte(srcGlyphs) != 0) || (IsGlyphEscape(srcGlyphs) != 0)) {
                        MI_CpuCopy8(srcGlyphs, dest, 2);
                        dest += 2;
                    } else {
                        MI_CpuCopy8(srcGlyphs, dest, 1);
                        dest += 1;
                    }
                    i += 1;
                    srcGlyphs += 1;
                }
                *dest = 0;
                EnableMapConfirm();
                GotoSpriteAnimationLabel(editor, 3);
                PlaySoundEffect(0x1000E);
                return;
            }
        }
        PauseSpriteUpdate();
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        dialog = CreateTextLayer(editor);
        RenderTextLayerMessage(dialog, 2, 0x2800, 0x4600000F);
        M2C_FIELD(dialog, s32 *, 0x58) = (s32) (M2C_FIELD(dialog, s32 *, 0x58) | 0x1000);
        gCur3DSpriteEngine = savedEngine;
        GotoSpriteAnimationLabel(editor, 5);
        PlaySoundEffect(0x1001D);
        return;
    }
}

/* D-pad cursor handler for the map editor's text-entry softkeys.  From the key
 * cluster 105/106 up/down move to the row above (69/72) or below (9/12) and
 * left/right walk out to 104/100; a direction only moves the focus on its
 * initial press (auto-repeat would skip past).  A runs the focused slot's action. */
void MapEditTextCursorInput(u8 *selection) {
M2C_UNK FocusSpriteSlotById(u8);
extern void *gKeyState;
u16 repeat,pressed;
u8 slot,oldSlot;
oldSlot=*selection;
pressed=M2C_FIELD(gKeyState,u16 *,0);
slot=oldSlot;
repeat=M2C_FIELD(gKeyState,u16 *,2);
if(pressed&KEY_A){MapEditTextActionInput(selection);return;}
if(repeat&KEY_UP){
switch(oldSlot){
case 105:if(repeat==pressed)slot=69;break;
case 106:if(repeat==pressed)slot=72;break;
}
if(slot>=105U){ if(slot>106U){} else goto horizontal; }
}else if(repeat&KEY_DOWN){
switch(oldSlot){
case 105:if(repeat==pressed)slot=9;break;
case 106:if(repeat==pressed)slot=12;break;
}
if(slot>=105U && slot<=106U)goto horizontal;
}else{
horizontal:
if(repeat&KEY_LEFT){
switch(slot){
case 106:slot=105;break;
case 105:slot=104;break;
}
if(slot>=105U && slot<=106U)goto done;
}else if(repeat&KEY_RIGHT){
switch(slot){
case 105:slot=106;break;
case 106:if(repeat==pressed)slot=100;break;
}
}
}
done:
if(oldSlot==slot)return;
FocusSpriteSlotById(slot);
}

void func_ov007_0221dff0(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

