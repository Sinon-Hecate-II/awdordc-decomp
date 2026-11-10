/* 7 functions from 0x0221D008 to 0x0221E004 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_0221d008(u8 *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_02007ef4(s32 *, s8 *, M2C_UNK);
    M2C_UNK func_02019424(s32 *, M2C_UNK);
    s32 func_020194e0(s32 *, M2C_UNK *);
    s32 func_02099ae8(s32 *);
    s32 func_0209c268(s32 *);
    M2C_UNK SetSpriteAnimation(s32, M2C_UNK);
    M2C_UNK func_020899cc(void *, M2C_UNK, M2C_UNK, s32);
    void *func_0208b564(s32);
    M2C_UNK func_020b269c();
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
if(func_020194e0(value,&gGlyphDakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(func_020194e0(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(func_020194e0(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c);
}else {PlaySoundEffect(0x1001d);return;}
} else if(func_020194e0(value,&gGlyphHandakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(func_020194e0(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(func_020194e0(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258);
}else {PlaySoundEffect(0x1001d);return;}
}
if(*phase>=16){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; func_020b269c(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=func_0208b564((s32)ctx); func_020899cc(sprite,2,0x2800,0x46000012); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; SetSpriteAnimation((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
func_02007ef4(&gMapEditObjectList,(s8 *)scratch,0x44);
scratch[*phase]=0;
func_02019424(&scratch[*phase],(s32)value);
{s32 *node; u32 count=0; node=scratch; if(*node){do{if(func_02099ae8(node)==0){if(count)count++;} count+=func_0209c268(node);}while(*++node);}
if(count>64){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; func_020b269c(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=func_0208b564((s32)ctx); func_020899cc(sprite,2,0x2800,0x46000013); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; SetSpriteAnimation((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
}
func_02007ef4(scratch,(s8 *)&gMapEditObjectList,0x44);
{ s8 next=(s8)(*phase+1); if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next; }
PlaySoundEffect(0x1000d);return;
}else {
s32 old=*phase;
s32 *value=&data_ov007_022205c0;
if(func_020194e0(value,&gGlyphDakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(func_020194e0(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(func_020194e0(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x12c);
}else {PlaySoundEffect(0x1001d);return;}
} else if(func_020194e0(value,&gGlyphHandakuten)==0) {
s32 found; if(*phase==0) found=-1; else{s32 *items=*(s32 **)((u8 *)ctx+0x34); s32 i; s32 *entry=&((s32 *)&gMapEditObjectList)[*phase-1]; found=-1; for(i=0;i<75;i++){if(func_020194e0(entry,(M2C_UNK *)items[i])==0){found=i;break;}}}
if(found>=0){s8 next=(s8)(*phase-1);if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next;
if(func_020194e0(&((s32 *)&gMapEditObjectList)[*phase],(M2C_UNK *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258))==0){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old;PlaySoundEffect(0x1001d);return;}
value=(s32 *)M2C_FIELD(*(s32 **)((u8 *)ctx+0x34)+found,s32 *,0x258);
}else {PlaySoundEffect(0x1001d);return;}
}
if(*phase>=16){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; func_020b269c(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=func_0208b564((s32)ctx); func_020899cc(sprite,2,0x2800,0x46000012); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; SetSpriteAnimation((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
func_02007ef4(&gMapEditObjectList,(s8 *)padding,0x44);
padding[*phase]=0;
func_02019424(&padding[*phase],(s32)value);
{s32 *node; u32 count=0; node=padding; if(*node){do{if(func_02099ae8(node)==0){if(count)count++;} count+=func_0209c268(node);}while(*++node);}
if(count>64){if ((s8)old >= 0 && (s8)old < 17 && (((s8)old < 17 && ((s32 *)&gMapEditObjectList)[(s8)old] != 0) || ((s8)old > 0 && ((s32 *)&gMapEditObjectList)[(s8)old-1] != 0))) *phase = (s8)old; func_020b269c(); { s32 engine=gCur3DSpriteEngine; void *sprite; gCur3DSpriteEngine=g3DSpriteEngineMain; sprite=func_0208b564((s32)ctx); func_020899cc(sprite,2,0x2800,0x46000013); M2C_FIELD(sprite,s32 *,0x58) |= 0x1000; gCur3DSpriteEngine=engine; SetSpriteAnimation((s32)ctx,5); } PlaySoundEffect(0x1001d); return;}
}
func_02007ef4(padding,(s8 *)&gMapEditObjectList,0x44);
{ s8 next=(s8)(*phase+1); if (next >= 0 && next < 17 && ((next < 17 && ((s32 *)&gMapEditObjectList)[next] != 0) || (next > 0 && ((s32 *)&gMapEditObjectList)[next-1] != 0))) *phase = next; }
PlaySoundEffect(0x1000d);return;
} default:return;}}

void func_ov007_0221dbb0(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *gKeyState;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(gKeyState,u16 *,0);
current=old;
held=M2C_FIELD(gKeyState,u16 *,2);
if(pressed&1){func_ov007_0221d008(arg0);return;}
if(held&0x40){
switch(old){
case 103:if(held==pressed)current=64;break;
case 104:if(held==pressed)current=66;break;
}
if(current>=103U){ if(current>104U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 103:if(held==pressed)current=4;break;
case 104:if(held==pressed)current=6;break;
}
if(current>=103U && current<=104U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 104:current=103;break;
case 103:current=102;break;
}
if(current>=103U && current<=104U)goto done;
}else if(held&0x10){
switch(current){
case 104:current=105;break;
case 103:current=104;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
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
    M2C_UNK SetSpriteAnimation(s32, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32 *, s8 *, M2C_UNK);
    s32 func_020194e0(s32 *, M2C_UNK *);
    M2C_UNK func_020899cc(void *, M2C_UNK, M2C_UNK, s32);
    void *func_0208b564(s32);
    s32 func_02099ae8(s32 *);
    s32 func_02099b00(s32 *);
    M2C_UNK func_020b269c();
    M2C_UNK func_020d47d0();
    M2C_UNK func_020d47f0();
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
        func_020d47f0();
        SetSpriteAnimation(editor, 3);
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
                if ((func_020194e0(glyphSlot, &gGlyphSpace) != 0) && (func_020194e0(glyphSlot, &gGlyphWideSpace) != 0)) {
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
                    if ((func_02099ae8(srcGlyphs) != 0) || (func_02099b00(srcGlyphs) != 0)) {
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
                func_020d47d0();
                SetSpriteAnimation(editor, 3);
                PlaySoundEffect(0x1000E);
                return;
            }
        }
        func_020b269c();
        savedEngine = gCur3DSpriteEngine;
        gCur3DSpriteEngine = g3DSpriteEngineMain;
        dialog = func_0208b564(editor);
        func_020899cc(dialog, 2, 0x2800, 0x4600000F);
        M2C_FIELD(dialog, s32 *, 0x58) = (s32) (M2C_FIELD(dialog, s32 *, 0x58) | 0x1000);
        gCur3DSpriteEngine = savedEngine;
        SetSpriteAnimation(editor, 5);
        PlaySoundEffect(0x1001D);
        return;
    }
}

void func_ov007_0221ded4(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *gKeyState;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(gKeyState,u16 *,0);
current=old;
held=M2C_FIELD(gKeyState,u16 *,2);
if(pressed&1){MapEditTextActionInput(arg0);return;}
if(held&0x40){
switch(old){
case 105:if(held==pressed)current=69;break;
case 106:if(held==pressed)current=72;break;
}
if(current>=105U){ if(current>106U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 105:if(held==pressed)current=9;break;
case 106:if(held==pressed)current=12;break;
}
if(current>=105U && current<=106U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 106:current=105;break;
case 105:current=104;break;
}
if(current>=105U && current<=106U)goto done;
}else if(held&0x10){
switch(current){
case 105:current=106;break;
case 106:if(held==pressed)current=100;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221dff0(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

