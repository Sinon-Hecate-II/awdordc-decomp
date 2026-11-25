/* 39 functions from 0x0218A384 to 0x0218B368 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct { s8 x, y; } TextDirection;
static inline void get_obj_xy(void *base, s32 index, s32 *x, s32 *y) {
*x=(M2C_FIELD(base,u32 *,index*8)&0x1ff0000)>>16;
*y=M2C_FIELD(base,u32 *,index*8)&255;
}
static inline void set_obj_xy(void *base,s32 index,s32 x,s32 y) {
M2C_FIELD(base,u32 *,index*8)=(M2C_FIELD(base,u32 *,index*8)&0xfe00ff00)|(y&255)|((u32)(x<<23)>>7);
}

void Ov001_MoveSpriteLayout(void *layout, s32 index, s32 x, s32 y) {
    u32 (*entries)[2] = M2C_FIELD(layout, u32 (**)[2], 8);
    volatile s32 original[2], last[2];
    u32 attr;
    s32 dx, dy, oldX, oldY;
    if (index >= 0) {
        set_obj_xy(entries,index,x,y);
        return;
    }
    attr = entries[0][0];
    set_obj_xy(entries,0,x,y);
    oldX = (attr & 0x1ff0000) >> 16;
    oldY = (u8)attr;
    original[1] = oldX;
    original[0] = oldY;
    dx = x - oldX;
    dy = y - oldY;
    index = 1;
    if (index >= M2C_FIELD(layout, u8 *, 12)) return;
    do {
        attr = entries[index][0];
        oldY = (u8)attr;
        oldX = (attr & 0x1ff0000) >> 16;
        set_obj_xy(entries,index,dx + oldX,dy + oldY);
        index++;
    } while (index < M2C_FIELD(layout, u8 *, 12));
    last[0] = oldY;
    last[1] = oldX;
}

#pragma opt_strength_reduction off
/* Set the palette variant (0..3) of one sprite entry, or of every entry when
 * index is negative. */
void Ov001_SetSpritePalette(M2C_UNK spriteObj, s32 index, s32 variant) {
u8 *entries=M2C_FIELD(spriteObj,u8 **,8);
s32 i;
if(index>=0) {
M2C_FIELD(entries+index*8,u16 *,4)=(M2C_FIELD(entries+index*8,u16 *,4)&~SPRITE_ENTRY_PALETTE_VARIANT_MASK)|(variant<<SPRITE_ENTRY_PALETTE_VARIANT_SHIFT);
} else {
for(i=0;i<M2C_FIELD(spriteObj,u8 *,12);i++) {
M2C_FIELD(entries+i*8,u16 *,4)=(M2C_FIELD(entries+i*8,u16 *,4)&~SPRITE_ENTRY_PALETTE_VARIANT_MASK)|(variant<<SPRITE_ENTRY_PALETTE_VARIANT_SHIFT);
}
}
}
#pragma opt_strength_reduction on
/* Read sprite entry `index` of a sprite object (its OAM entry array at +0x08):
 * writes the entry's packed x (bits 16..24) and y (low byte). */
void Ov001_GetSpritePosition(void *spriteObj, s32 index, u32 *x, s32 *y) {
    get_obj_xy(M2C_FIELD(spriteObj, void **, 8), index, (s32 *)x, y);
}

/* Load the character bank file at `path` and remember its pointer in
 * gOv001CharBanks[bank] (1 = top screen, 0 = bottom screen). */
void Ov001_LoadCharBank(s32 bank, M2C_UNK path) {
 s32 Ov001_LoadFile(M2C_UNK,M2C_UNK *,M2C_UNK);
 extern M2C_UNK gOv001CharBanks;
 M2C_UNK fileSize;
 (&gOv001CharBanks)[bank]=Ov001_LoadFile(path,&fileSize,4);
}

void Ov001_FreeCharBank(u8 arg0) {
 void Ov001_FreeFile(s32);
 extern M2C_UNK gOv001CharBanks;
 Ov001_FreeFile(((s32 *)&gOv001CharBanks)[arg0]);
 ((s32 *)&gOv001CharBanks)[arg0] = 0;
}

void Ov001_LoadSpriteObjLayout(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK gOv001CharBanks;
void CpuFill(u32,void *,s32);
void CopyU16(const void *,void *,u32);
void MIi_CpuCopy32(const void *,void *,s32);
u8 *base=(u8 *)((M2C_UNK *)&gOv001CharBanks)[arg0];
s32 index=arg1<<3;
u16 count=*(u16 *)(base+index);
s32 offset=*(s32 *)(base+index+4);
u8 *src=base+offset;
u8 *dst=(u8 *)arg2;
u8 sp[8]; s32 i;
CpuFill(0,sp,8);
for(i=0;i<(s32)count;i++){
CopyU16(src,sp,6);MIi_CpuCopy32(sp,dst,8);src+=6;dst+=8;
}
}

/* Create a sprite object from layout `layoutIndex` of character bank `bank`:
 * take a free OAM entry from that screen's pool and copy the layout's entries
 * into it; returns the entry.  (The queue helper is called without arguments,
 * so it picks its screen from the bank still in r0.) */
s32 Ov001_CreateSpriteFromLayout(M2C_UNK bank, M2C_UNK layoutIndex) {
    void Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, s32);
    s32 Ov001_PopFreeSpriteObj();
    s32 entry;

    entry = Ov001_PopFreeSpriteObj();
    Ov001_LoadSpriteObjLayout(bank, layoutIndex, entry);
    return entry;
}

/* Create a sprite object from one layout of a character bank (1 = top screen,
 * 0 = bottom screen): look up the layout's OAM entry count in gOv001CharBanks,
 * allocate that many sprite entries from the pool (`fromHead` picks which end of
 * the arena it takes them from) and copy the layout's source entries into it. */
void *Ov001_CreateSprite(s32 bank, s32 layoutIndex, s32 fromHead) {
extern M2C_UNK gOv001CharBanks;
M2C_UNK Ov001_AllocSpriteBlock(s32,s32,s32);
s32 Ov001_GetSpriteObjEntry(s32,s32);
void Ov001_LoadSpriteObjLayout(s32,s32,s32);
Ov001SpriteLayout *layouts=(Ov001SpriteLayout *)((M2C_UNK *)&gOv001CharBanks)[bank];
u16 count=layouts[layoutIndex].count;
M2C_UNK block=Ov001_AllocSpriteBlock(bank,count,fromHead);
Ov001_LoadSpriteObjLayout(bank,layoutIndex,Ov001_GetSpriteObjEntry(block,0));
return block;
}

/* Allocate an ov001 ring queue able to hold `count` values (its capacity is one
 * bigger, so a full queue is distinguishable from an empty one) and clear its read
 * and write indices. */
void *Ov001_QueueCreate(s32 count) {
    void *Ov001_Alloc(s32, M2C_UNK);
    void *queue;

    queue = Ov001_Alloc(((count + 1) * 4) + 8, 4);
    M2C_FIELD(queue, s16 *, OV001_QUEUE_CAPACITY) = (s16) (count + 1);
    M2C_FIELD(queue, s8 *, OV001_QUEUE_READ) = 0;
    M2C_FIELD(queue, s8 *, OV001_QUEUE_WRITE) = 0;
    return queue;
}

/* Create an ov001 ring queue already holding `count` values: `first`, then
 * `first + stride`, ...  Used to build an arena's free-node list (each entry is
 * the address of one node).  The queue comes back full, so only the write index
 * is set. */
void *Ov001_QueueCreateFromRange(s32 count, s32 first, s32 stride) {
    void *Ov001_QueueCreate(s32);
    M2C_UNK *queue = (M2C_UNK *)Ov001_QueueCreate(count);
    s32 i;
    s32 value = first;
    for (i = 0; i < count; i++) {
        queue[i + 1] = (M2C_UNK)value;
        value += stride;
    }
    ((u8 *)queue)[OV001_QUEUE_WRITE] = (u8)count;
    return queue;
}

void Ov001_FreeBlock(s32 arg0, ...) {
 M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
 Ov001_FreeAlloc(&arg0);
}

/* Push a value into a fixed-size ring queue with interrupts masked; when the
 * next write slot is still the read slot the queue is full and the game halts. */
void Ov001_QueuePush(void *queue, s32 value) {
    u8 HardwareDivideRemainder(s32, u16);
    M2C_UNK OS_EnableIrqMask(s32);
    s32 OS_DisableIrqMask(M2C_UNK);
    M2C_UNK SystemHalt();
    s32 saved;
    u8 next;

    saved = OS_DisableIrqMask(1);
    next = HardwareDivideRemainder(M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE) + 1, M2C_FIELD(queue, u16 *, OV001_QUEUE_CAPACITY));
    if (next == M2C_FIELD(queue, u8 *, OV001_QUEUE_READ)) {
        SystemHalt();
    }
    M2C_FIELD((queue + (M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE) * 4)), s32 *, OV001_QUEUE_ENTRIES) = value;
    M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE) = next;
    OS_EnableIrqMask(saved);
}

/* Pop the most recently pushed value from the ring queue with interrupts masked;
 * returns 0 when the queue is empty. */
s32 Ov001_QueuePop(void *queue) {
    M2C_UNK OS_EnableIrqMask(M2C_UNK);
    s32 OS_DisableIrqMask(M2C_UNK);
    u8 HardwareDivideRemainder(s32, u16);
    s32 result = 0, saved, value;
    u8 head, tail, index;
    u16 capacity;

    saved = OS_DisableIrqMask(1);
    head = M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE);
    tail = M2C_FIELD(queue, u8 *, OV001_QUEUE_READ);
    if (tail != head) {
        capacity = M2C_FIELD(queue, u16 *, OV001_QUEUE_CAPACITY);
        value = HardwareDivideRemainder(head + capacity - 1, capacity);
        M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE) = value;
        index = M2C_FIELD(queue, u8 *, OV001_QUEUE_WRITE);
        result = M2C_FIELD((u8 *)queue + (index << 2), s32 *, OV001_QUEUE_ENTRIES);
    }
    OS_EnableIrqMask(saved);
    return result;
}

/* Allocate the ov001 screen-fade state block (the sub and main fade slots) and
 * reset both engines' blend control to full white: every plane blended, BLDY 16. */
void Ov001_InitFades(void) {
    extern M2C_UNK gOv001FadeStates;
    void *Ov001_Alloc(s32, M2C_UNK);
    void GX_SetBlendControl(M2C_UNK, s32, s32);

    gOv001FadeStates = (M2C_UNK)Ov001_Alloc(sizeof(Ov001FadeStates), 4);
    GX_SetBlendControl(GX_BLDCNT_MAIN, OV001_BLEND_ALL, 0x10);
    GX_SetBlendControl(GX_BLDCNT_SUB, OV001_BLEND_ALL, 0x10);
}

void Ov001_FreeFades(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gOv001FadeStates;
    Ov001_FreeAlloc(&gOv001FadeStates);
}

u8 Ov001_IsFadeActive(s32 arg0) {
    extern M2C_UNK gOv001FadeStates;
    void *p;
    if (arg0 == 1) {
        p = (void *)gOv001FadeStates;
    } else {
        p = (u8 *)gOv001FadeStates + 0xc;
    }
    return ((u8 *)p)[9];
}

/* Starts one ov001 screen fade: sets the engine's blend control to the mode's
 * starting BLDY value, then marks the engine's fade slot active and queues the
 * Ov001_UpdateFade task that ramps it over `duration` frames. `engine` 1 targets
 * the sub screen, anything else the main screen. Returns 0 when that engine is
 * already fading, else 1. */
s32 Ov001_StartFade(s32 mode,s32 engine,s32 blendControl,s32 duration) {
extern u8 gOv001FadeTable[];
extern M2C_UNK gOv001FadeStates;
void GX_SetBlendControl(s32,s32,s32);
void Ov001_UpdateFade(M2C_UNK, void *);
void *Ov001_AddTask(s32,s32,void *,s32);
s8 startBlend[4];
Ov001Fade *fade;
startBlend[0]=gOv001FadeTable[8]; startBlend[1]=gOv001FadeTable[9]; startBlend[2]=gOv001FadeTable[10]; startBlend[3]=gOv001FadeTable[11];
if(engine==1) fade=(Ov001Fade *)gOv001FadeStates; else fade=(Ov001Fade *)((u8 *)gOv001FadeStates+12);
if(fade->active) return 0;
if(engine==1) GX_SetBlendControl(0x4001050,blendControl,startBlend[mode]); else GX_SetBlendControl(0x4000050,blendControl,startBlend[mode]);
fade->task=(s32)Ov001_AddTask(1,(s32)Ov001_UpdateFade,fade,200);
fade->counter=0;
fade->mode=mode;
fade->duration=duration;
fade->active=1;
return 1;
}

/* Task callback of one ov001 screen fade: advance its frame counter, map the
 * progress to a BLDY blend value through the fade table and write it to the
 * engine's blend register; when the duration is reached write the mode's end
 * value, clear the fade and post the completion message. */
void Ov001_UpdateFade(M2C_UNK task, void *fadeArg) {
    s32 HardwareDivide(s32, u16);
    void GX_SetBlendY(s32, s32);
    void Ov001_PostTaskMessage(s32, s32);
    extern u8 gOv001FadeTable[];
    extern M2C_UNK gOv001FadeStates;

    u8 table[8];
    Ov001Fade *fade;
    s32 ramp;
    u16 duration;
    s32 value;
    u8 mode;
    u8 flags;
    u8 *flagTable;
    s16 elapsed;
    u16 limit;
    u8 endMode;

    fade = fadeArg;

    table[4] = gOv001FadeTable[OV001_FADE_FLAGS + 0];
    table[5] = gOv001FadeTable[OV001_FADE_FLAGS + 1];
    table[6] = gOv001FadeTable[OV001_FADE_FLAGS + 2];
    table[7] = gOv001FadeTable[OV001_FADE_FLAGS + 3];
    table[0] = gOv001FadeTable[OV001_FADE_END_BLEND + 0];
    table[1] = gOv001FadeTable[OV001_FADE_END_BLEND + 1];
    table[2] = gOv001FadeTable[OV001_FADE_END_BLEND + 2];
    table[3] = gOv001FadeTable[OV001_FADE_END_BLEND + 3];

    fade->counter = fade->counter + 1;
    ramp = (s32)fade->counter << 4;
    duration = fade->duration;
    value = HardwareDivide(ramp, duration);

    mode = fade->mode;
    flagTable = table + OV001_FADE_MODE_COUNT;
    flags = flagTable[mode];
    if (flags & OV001_FADE_INVERT) {
        value = 0x10 - value;
    }
    if (flags & OV001_FADE_NEGATE) {
        value = -value;
    }

    if (fade == (Ov001Fade *)gOv001FadeStates) {
        GX_SetBlendY(GX_BLDCNT_SUB, value);
    } else {
        GX_SetBlendY(GX_BLDCNT_MAIN, value);
    }

    elapsed = fade->counter;
    limit = fade->duration;
    if (elapsed >= (s32)limit) {
        endMode = fade->mode;
        if (fade == (Ov001Fade *)gOv001FadeStates) {
            GX_SetBlendY(GX_BLDCNT_SUB, (s32)(s8)table[endMode]);
        } else {
            GX_SetBlendY(GX_BLDCNT_MAIN, (s32)(s8)table[endMode]);
        }
        fade->active = 0;
        Ov001_PostTaskMessage(1, (s32)task);
    }
}

/* Starts the ov001 step delay: reuses the sub-engine fade slot as a frame counter,
 * queues the Ov001_DelayStep task that counts down `frames` frames and posts task
 * message 1 when it elapses. Returns 0 when a delay is already running. */
s32 Ov001_StartDelay(s32 frames) {
    void *Ov001_AddTask(s32, M2C_UNK, void *, s32);
    void Ov001_DelayStep(M2C_UNK, void *);
    extern M2C_UNK gOv001FadeStates;
    Ov001FadeStates *states = (Ov001FadeStates *)gOv001FadeStates;
    s32 delay = frames;
    if (states->sub.active != 0) {
        return 0;
    }
    states->sub.task = Ov001_AddTask(1, (M2C_UNK)Ov001_DelayStep, states, 0xc8);
    states->sub.counter = 0;
    states->sub.duration = (u16)delay;
    states->sub.active = 1;
    return 1;
}

/* Frame step of the ov001 step delay: count one frame in the reused sub-engine
 * fade slot and, once its duration is reached, mark the delay idle and post task
 * message 1 back to the task. */
void Ov001_DelayStep(M2C_UNK task, void *delaySlot) {
    void Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    Ov001Fade *delay = (Ov001Fade *)delaySlot;
    delay->counter = (s16) (delay->counter + 1);
    if ((s32) delay->counter < (s32) delay->duration) {
        return;
    }
    delay->active = 0;
    Ov001_PostTaskMessage(1, task);
}

#pragma opt_strength_reduction off
/* Build the ov001 text context: allocate it, hand its 32 pooled text panels to a
 * from-buffer queue and load the two bitmap font sets, choosing the Korean font
 * file pair when the console language is Korean and the Latin pair otherwise. */
void Ov001_CreateTextContext(void) {
    void *Ov001_Alloc(s32, M2C_UNK);
    void *Ov001_QueueCreateFromRange(s32, s32, s32);
    s32 Ov001_GetLanguage(void);
    s32 Ov001_LoadFile(M2C_UNK, M2C_UNK *, M2C_UNK);
    void Ov001_InitFontSet(void *, M2C_UNK);
    extern M2C_UNK gOv001TextContext;
    extern M2C_UNK gOv001KoreanFontFilePaths;
    extern M2C_UNK gOv001DefaultFontFilePaths;
    M2C_UNK context;

    context = (M2C_UNK)Ov001_Alloc(OV001_CTX_SIZE, 4);
    gOv001TextContext = context;
    M2C_FIELD((void *)gOv001TextContext, void **, OV001_CTX_PANEL_QUEUE) =
        Ov001_QueueCreateFromRange(OV001_TEXT_PANEL_COUNT,
            (s32)context + OV001_CTX_PANEL_BUFFER, OV001_TEXT_PANEL_SIZE);

    if (Ov001_GetLanguage() == LANGUAGE_KOREAN) {
        s32 i;
        s32 fontOffset;
        for (i = 0, fontOffset = 0; i < 2; i++) {
            M2C_FIELD((void *)gOv001TextContext + i * 4, M2C_UNK *, OV001_CTX_FONT_FILES) =
                (M2C_UNK)Ov001_LoadFile((&gOv001KoreanFontFilePaths)[i], 0, 4);
            Ov001_InitFontSet((void *)gOv001TextContext + fontOffset,
                M2C_FIELD((void *)gOv001TextContext + i * 4, M2C_UNK *, OV001_CTX_FONT_FILES));
            fontOffset += 8;
        }
    } else {
        s32 fontOffset;
        s32 i;
        for (i = 0, fontOffset = 0; i < 2; i++) {
            M2C_FIELD((void *)gOv001TextContext + i * 4, M2C_UNK *, OV001_CTX_FONT_FILES) =
                (M2C_UNK)Ov001_LoadFile((&gOv001DefaultFontFilePaths)[i], 0, 4);
            Ov001_InitFontSet((void *)gOv001TextContext + fontOffset,
                M2C_FIELD((void *)gOv001TextContext + i * 4, M2C_UNK *, OV001_CTX_FONT_FILES));
            fontOffset += 8;
        }
    }
}
#pragma opt_strength_reduction reset
/* Free the ov001 text context built by Ov001_CreateTextContext: its two font
 * files, its queue of pooled text panels and the context allocation itself. */
void Ov001_FreeTextContext(void) {
 void Ov001_FreeFile(s32);
 void Ov001_FreeBlock(s32,...);
 M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
 extern M2C_UNK gOv001TextContext;
 extern M2C_UNK gOv001Heap;
 M2C_UNK *contextSlot=&gOv001TextContext;
 s32 i;
 for(i=0;i<2;i++)Ov001_FreeFile(((s32 *)((u8 *)*contextSlot+OV001_CTX_FONT_FILES))[i]);
 Ov001_FreeBlock(*((s32 *)((u8 *)gOv001TextContext+OV001_CTX_PANEL_QUEUE)));
 Ov001_FreeAlloc(&gOv001Heap-1); /* &gOv001TextContext, spelled apart so the pool keeps two words */
}

/* Take a text panel object from the ov001 context's queue, set its size and font
 * and allocate its tile range in that screen's tile pool, point the panel's
 * bitmap at the range, run its draw operation and publish the range's tile
 * offset and the size-derived layout value.  Returns the panel. */
void *CreatePooledTextPanel(s32 screen, s32 width, s32 height, s32 forward, s32 *layoutOut, s32 fontSet) {
    extern M2C_UNK gOv001TextContext;
    s32 func_ov001_0218c228(s32, s32, s32, s32 *);
    s32 func_ov001_0216a33c(s32, s32);
    void func_ov001_0216a1a8(void *, s32, s32, s32, s32);
    Ov001TextPanel *panel;
    s32 tiles;
    s32 base;
    s32 offset;

    panel = (Ov001TextPanel *)Ov001_QueuePop((void *)M2C_FIELD(gOv001TextContext, s32 *, OV001_CTX_PANEL_QUEUE));
    panel->width = width;
    panel->height = height;
    panel->tiles = (void *)func_ov001_0218c228(screen, width * height, forward, &tiles);
    panel->tileCount = tiles;
    *layoutOut = func_ov001_0216a33c(width, height);
    offset = tiles;
    if (screen == 1) base = 0x6600000; else base = 0x6400000;
    func_ov001_0216a1a8(panel, base + (offset << 7), width, height, 4);
    ((void (*)(void *, s32))M2C_FIELD(panel->ops, void **, 4))(panel, 0);
    offset = gOv001TextContext + fontSet * 8;
    panel->self = panel;
    panel->font = (Ov001Font *)offset;
    panel->unk20 = 1;
    panel->unk24 = 1;
    return panel;
}

/* Release a pooled text panel handed out by CreatePooledTextPanel: give its tile
 * range back to its screen's tile pool, then put the panel back on the context's
 * queue of free panels. */
void Ov001_ReleaseTextPanel(M2C_UNK panel) {
    M2C_UNK Ov001_ReturnTileRangeNode(M2C_UNK);
    void Ov001_QueuePush(void *, s32);
    extern M2C_UNK gOv001TextContext;

    Ov001_ReturnTileRangeNode((M2C_UNK)((Ov001TextPanel *)panel)->tiles);
    Ov001_QueuePush((void *)M2C_FIELD((void *)gOv001TextContext, M2C_UNK *, OV001_CTX_PANEL_QUEUE), panel);
}

#pragma optimization_level 3
void *CreateTextPanel(s32 arg0,s32 arg1) {
void *Ov001_Alloc(s32,s32); void SetTextPanelSurface(void*,void*,s32,s32,s32);
s32 func_020036b8(void); s32 GX_GetBG0ScrPtr(void);
void func_ov001_0216a230(s32,s32,s32,s32,s32,s32,s32,u32);
void TextPanel_ClearText(void*,s32); void *Ov001_AddTask(s32,M2C_UNK,void*,s32); void Ov001_UploadTextPanelTiles(M2C_UNK,void*);
extern M2C_UNK gOv001TextContext; extern u8 data_ov001_0218fd18[],data_ov001_0218fd1a[],data_ov001_0218fd14[];
void *base;
void *p=(u8*)(void*)gOv001TextContext+0x610+arg0*0x30;
u32 a=*(u16*)(data_ov001_0218fd1a+arg0*4);
u32 b=*(u16*)(data_ov001_0218fd18+arg0*4); s32 v; u16 c; s32 zero, stride;
*(void**)((u8*)p+0x28)=Ov001_Alloc((b*a)<<5,32);
if(arg0==1) { *(volatile u16*)0x4001008 &= ~0x40; *(volatile u16*)0x4001008=(*(volatile u16*)0x4001008&0x43)|0xc00; }
else { *(volatile u16*)0x4000008 &= ~0x40; *(volatile u16*)0x4000008=(*(volatile u16*)0x4000008&0x43)|0xc00; }
SetTextPanelSurface(p,*(void**)((u8*)p+0x28),b,a,4);
base=(void*)gOv001TextContext;
*(void**)((u8*)p+0x18)=p;
*(void**)((u8*)p+0x1c)=(u8*)base+arg1*8;
*(s32*)((u8*)p+0x20)=1; *(s32*)((u8*)p+0x24)=1;
if(arg0==1) v=func_020036b8(); else v=GX_GetBG0ScrPtr();
zero=0;
c=*(volatile u16*)(data_ov001_0218fd14+arg0*2);
stride=32;
func_ov001_0216a230(v,b,a,zero,zero,stride,c,15);
TextPanel_ClearText(p,0);
*(void**)((u8*)p+0x2c)=Ov001_AddTask(1,(M2C_UNK)Ov001_UploadTextPanelTiles,(u8*)(void*)gOv001TextContext+0x67c+arg0,200);
return p;
}
#pragma optimization_level reset
void Ov001_UploadTextPanelTiles(M2C_UNK taskArg, void *uploadPendingFlag) {
    void DC_FlushRange(M2C_UNK, s32);
    void GX_LoadBG0Char(M2C_UNK, s32, u32);
    void GX_LoadBG0CharSub(M2C_UNK, s32, u32);
    extern M2C_UNK gOv001TextContext;

    /* Uploads a dirty text panel's cached tiles to its background character VRAM. */
    if (!*(u8 *)uploadPendingFlag) {
        return;
    }
    if (uploadPendingFlag == (void *)((u8 *)gOv001TextContext + OV001_CTX_PANEL_UPLOAD_FLAGS)) {
        DC_FlushRange(M2C_FIELD((void *)gOv001TextContext, M2C_UNK *, OV001_CTX_PANEL0_TILE_BUFFER), 0x6000);
        GX_LoadBG0Char(M2C_FIELD((void *)gOv001TextContext, M2C_UNK *, OV001_CTX_PANEL0_TILE_BUFFER), 0, 0x6000);
    } else {
        DC_FlushRange(M2C_FIELD((void *)gOv001TextContext, M2C_UNK *, OV001_CTX_PANEL1_TILE_BUFFER), 0x3000);
        GX_LoadBG0CharSub(M2C_FIELD((void *)gOv001TextContext, M2C_UNK *, OV001_CTX_PANEL1_TILE_BUFFER), 0x3000, 0x3000);
    }
    *(u8 *)uploadPendingFlag = 0;
}

/* Free a fixed full-screen text panel's page background: tear down its tile
 * refresh task, clear its screen's character VRAM (0x6000 bytes for the main
 * screen, 0x3000 for the sub screen) and free the panel's tile buffer. */
M2C_UNK Ov001_FreePanelBackground(s32 panel) {
    extern M2C_UNK gOv001TextContext;
    M2C_UNK temp_r0;
    Ov001_ReturnTaskNodeVeneer(1, M2C_FIELD((void *)panel, M2C_UNK *, OV001_PANEL_REFRESH_TASK));
    if (panel == (M2C_UNK)gOv001TextContext + OV001_CTX_SCREEN_PANELS) {
        temp_r0 = FillU16(0, GX_GetBG0CharPtr(), OV001_PANEL0_VRAM_BYTES);
    } else {
        temp_r0 = FillU16(0, GX_GetBG0CharPtr(), OV001_PANEL1_VRAM_BYTES);
    }
    return Ov001_FreeAlloc((u8 *)panel + 0x28);
}

void Ov001_FreePageBackground(s32 arg0) {
    M2C_UNK Ov001_FreePanelBackground(s32);
    extern s32 gOv001TextContext;
    Ov001_FreePanelBackground((0x30 * arg0) + (gOv001TextContext + 0x610));
}

/* Draw an anchored text block on a text panel: choose the run direction from the
 * font's direction byte (right, down, left or up) and draw the text anchored at
 * (x, y) with the given colour and anchor flags. */
void DrawPanelAnchoredText(void *panel,s32 x,s32 y,s32 colour,s32 flags,s32 text) {
M2C_UNK DrawAnchoredText(void *,s32,s32,s32,s32,s32,TextDirection);
void **entry=M2C_FIELD(panel,void ***,0x1c);
TextDirection dir={0,0};
u8 dirIndex=M2C_FIELD(M2C_FIELD(*entry,void **,8),u8 *,7);
switch(dirIndex){
case 0: case 7:dir.x=1;break;
case 1: case 2:dir.y=1;break;
case 3: case 4:dir.x=-1;break;
case 5: case 6:dir.y=-1;break;
default:break;
}
DrawAnchoredText(panel+0x18,x,y,colour,flags,text,dir);
}

/* Draw the single character `ch` with the text context's font set `fontIndex`,
 * through the panel's glyph ops, in `color` at (x, y). */
void DrawFontSetGlyph(void *panel, s32 x, s32 y, s32 color, u16 ch, s32 fontIndex) {
    M2C_UNK DrawTextGlyph(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gOv001TextContext;
    M2C_UNK base = gOv001TextContext;
    DrawTextGlyph((M2C_UNK)panel, (M2C_UNK)((u8 *)base + fontIndex * 8), x, y, (M2C_UNK)color, (M2C_UNK)ch);
}

/* Draw a NUL-terminated UTF-16 string as one horizontal line of glyphs from the
 * context's font set `fontIndex`: each glyph is centred in a `cellWidth`-wide
 * cell, and the pen moves one cell per character. */
void DrawTextRun(void *panel, s32 x, s32 y, s32 color, s32 cellWidth, u16 *text, s32 fontIndex) {
    s32 GetFontGlyphIndex(void **a, u32 b);
    void *GetFontGlyphMetric(void **a, u32 b);
    void DrawFontSetGlyph(void *, s32, s32, s32, u16, s32);
    extern M2C_UNK gOv001TextContext;
    Ov001Font *font;
    s32 glyph;
    Ov001GlyphMetric *metric;
    if (*text == 0) return;
    do {
        font = (Ov001Font *)((u8 *)gOv001TextContext + fontIndex * 8);
        glyph = GetFontGlyphIndex((void **)font, *text);
        if (glyph == 0xffff) glyph = font->resource->defaultChar;
        metric = (Ov001GlyphMetric *)GetFontGlyphMetric((void **)font, glyph);
        DrawFontSetGlyph(panel, x + ((cellWidth - metric->advance) >> 1), y, color, *text, fontIndex);
        text++;
        x += cellWidth;
    } while (*text);
}

void DrawPanelText(void *panel, s32 x, s32 y, s32 blockWidth, s32 anchor, s32 color, s32 flags, s32 text) {
    void DrawVerticallyAnchoredText(void *, s32, s32, s32, s32, s32, s32, s32, TextDirection);
    void **entry = M2C_FIELD(panel, void ***, 0x1C);
    TextDirection dir = {0, 0};
    u8 dirIndex = M2C_FIELD(M2C_FIELD(*entry, void **, 8), u8 *, 7);

    switch (dirIndex) {
    case 0:
    case 7:
        dir.x = 1;
        break;
    case 1:
    case 2:
        dir.y = 1;
        break;
    case 3:
    case 4:
        dir.x = -1;
        break;
    case 5:
    case 6:
        dir.y = -1;
        break;
    default:
        break;
    }
    DrawVerticallyAnchoredText(panel + 0x18, x, y, blockWidth, anchor, color, flags, text, dir);
}

void TextPanel_ClearText(void *arg0, s32 arg1) {
M2C_FIELD(M2C_FIELD(arg0,void **,0x14),void (**)(void *,s32),4)(arg0,arg1);
}

/* Draws a text panel's tile block into a sprite object: resets the object's
 * entry flags and draw attributes, applies the given palette, then fills its
 * width x height entries with the panel's tiles starting at the panel's first
 * tile, at pixel (x, y). */
void Ov001_DrawTextPanelToSprite(Ov001TextPanel *panel, s32 x, s32 y, void *spriteObj, s32 palette) {
    M2C_UNK Ov001_FillTileRect(s32, u8, u8, M2C_UNK, s32, s32, s32, s32);
    s32 Ov001_GetSpriteObjEntry(s32, s32);
    M2C_UNK Ov001_SetSpriteEntryFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetSpriteAttrs(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_SetSpritePalette(M2C_UNK, M2C_UNK, s32);
    s32 entry;

    entry = Ov001_GetSpriteObjEntry((s32)spriteObj, 0);
    Ov001_SetSpriteEntryFlags(spriteObj, -1, 0, 0);
    Ov001_SetSpriteAttrs(spriteObj, -1, 0, 0xF);
    Ov001_SetSpritePalette(spriteObj, -1, palette);
    Ov001_FillTileRect(entry, panel->width, panel->height, x, y, 0, (s32)panel->tileCount, 2);
}

void CloseTextPanel(s32 arg0) {
    extern M2C_UNK gOv001TextContext;
    void *p = M2C_FIELD(&gOv001TextContext, void **, 0);
    if (arg0 == (s32)p + 0x610) {
        M2C_FIELD(p, u8 *, 0x67c) = 1;
    } else {
        M2C_FIELD(p, u8 *, 0x67d) = 1;
    }
}

void func_ov001_0218b2bc(s16 arg0, s16 arg1, void *arg2) {
    M2C_FIELD(arg2, s16 *, 0) = arg0;
    M2C_FIELD(arg2, s16 *, 2) = arg1;
}

void SetRect16(s16 arg0, s16 arg1, s16 arg2, s16 arg3, void *arg4) {
    M2C_FIELD(arg4, s16 *, 0) = arg0;
    M2C_FIELD(arg4, s16 *, 2) = arg1;
    M2C_FIELD(arg4, s16 *, 4) = arg2;
    M2C_FIELD(arg4, s16 *, 6) = arg3;
}

/* Build the touch rectangle `rect` (left, top, right, bottom) of a key whose
 * top-left corner is `pos` (x, y) and whose size is `size` (width, height). */
void BuildTouchRect(void *pos, void *size, void *rect) {
    M2C_FIELD(rect, u16 *, 0) = (u16) M2C_FIELD(pos, u16 *, 0);
    M2C_FIELD(rect, u16 *, 2) = (u16) M2C_FIELD(pos, u16 *, 2);
    M2C_FIELD(rect, s16 *, 4) = (s16) (M2C_FIELD(pos, u16 *, 0) + M2C_FIELD(size, u16 *, 0));
    M2C_FIELD(rect, s16 *, 6) = (s16) (M2C_FIELD(pos, u16 *, 2) + M2C_FIELD(size, u16 *, 2));
}

/* Turn on the display planes named by `planes` (GX_PLANEMASK_* bits) in the main
 * or sub engine's DISPCNT, keeping the planes that are already visible. */
void Ov001_EnableVisiblePlanes(s32 engine, s32 planes) {
    if (engine == OV001_FADE_SUB) {
        volatile u32 *dispCnt = (volatile u32 *)GX_SUB_DISPCNT;
        u32 visible = *dispCnt & DISPCNT_PLANEMASK;
        *dispCnt = (*dispCnt & ~DISPCNT_PLANEMASK) | ((planes | (visible >> DISPCNT_PLANEMASK_SHIFT)) << DISPCNT_PLANEMASK_SHIFT);
        return;
    }
    {
        volatile u32 *dispCnt = (volatile u32 *)GX_MAIN_DISPCNT;
        u32 visible = *dispCnt & DISPCNT_PLANEMASK;
        *dispCnt = (*dispCnt & ~DISPCNT_PLANEMASK) | ((planes | (visible >> DISPCNT_PLANEMASK_SHIFT)) << DISPCNT_PLANEMASK_SHIFT);
    }
}

