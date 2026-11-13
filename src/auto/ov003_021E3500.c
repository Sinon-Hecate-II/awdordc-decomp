/* 7 functions from 0x021E3500 to 0x021E4448 (ov003), found by ds-decomp. */
#include "common.h"

typedef struct { u32 low:8; u32 middle:6; u32 high:6; u32 rest:12; } PreviewItemFields;
typedef struct { u32 enabled:1; u32 rest:31; } PreviewItemStatus;

typedef struct PreviewBits { u8 low:2; u8 bank:2; u8 high:4; } PreviewBits;

typedef struct MenuBits3ff8 { u8 bank:2; u8 other:6; } MenuBits3ff8;
typedef struct EngineBits3ff8 { u16 low:13; u16 shift:2; u16 high:1; } EngineBits3ff8;

void func_ov003_021e3500(void *arg0) {
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    M2C_UNK func_0208ae88(void *, M2C_UNK);
    void *func_0208b564(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020c9100(void *);
    M2C_UNK func_020c9120(u16, s32);
    M2C_UNK func_ov003_021f1894();
    u32 func_ov003_021f2574();
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    void func_01ffa6fc(void *);

    register void *r5 asm("r5");
    register s32 r6 asm("r6");
    u8 r4;

    u32 x;
    u8 cnt;
    u8 count2;
    register u8 i;
    u8 j;
    register unsigned long base;
    void *temp_r6;
    u8 temp_r1;

    r5 = arg0;
    x = func_ov003_021f2574();
    cnt = 0;
    i = 0;
    base = M2C_FIELD(r5, s32 *, 0x6C);
    r4 = 0;
    do {
        if (M2C_FIELD(base + ((s32)r4 * 0x6F8), u8 *, 0x27) != 0) {
            cnt = (u8)(cnt + 1);
        }
        r4 = (u8)(r4 + 1);
    } while (r4 < 5);
    if (x >= (u32)cnt) {
        x = (u32)cnt;
    }
    if (x != 0) {
        func_020c9100(r5);
        i = 0;
        goto loop_test;
        do {
            func_020c9120(
                M2C_FIELD(M2C_FIELD(r5, s32 *, 0x5C) + ((s32)i * 2), u16 *, 0x12),
                base + ((s32)i * 0x6F8));
            temp_r1 = (u8)(((M2C_FIELD(r5, u8 *, 0x60) | 0x40) & ~0x30) | 0x20);
            M2C_FIELD(r5, u8 *, 0x60) = temp_r1;
            switch ((u32)((u32)temp_r1 << 0x1A) >> 0x1E) {
            case 0:
                temp_r6 = func_0208b564(r5);
                func_020899cc(temp_r6, 3, func_ov003_021f1894() << 5, 0x47000023);
                M2C_FIELD(temp_r6, s32 *, 0x58) = M2C_FIELD(temp_r6, s32 *, 0x58) | 0x400;
                func_0208ae88(temp_r6, 0);
                break;
            case 1:
                temp_r6 = func_0208b564(r5);
                func_020899cc(temp_r6, 3, func_ov003_021f1894() << 5, 0x47000024);
                M2C_FIELD(temp_r6, s32 *, 0x58) = M2C_FIELD(temp_r6, s32 *, 0x58) | 0x400;
                func_0208ae88(temp_r6, 1);
                break;
            }
            i = (u8)(i + 1);
        loop_test:
            x = func_ov003_021f2574();
            count2 = 0;
            j = 0;
            base = M2C_FIELD(r5, s32 *, 0x6C);
            j = 0;
            do {
                if (M2C_FIELD(base + ((s32)j * 0x6F8), u8 *, 0x27) != 0) {
                    count2 = (u8)(count2 + 1);
                }
                j = (u8)(j + 1);
            } while (j < 5);
            if (x >= (u32)count2) {
                x = (u32)count2;
            }
        } while (i < x);
        return;
    }
    PlaySoundEffect(0x1000E);
    if (M2C_FIELD(r5, u8 *, 0x39) != 0) {
        func_02088da8(M2C_FIELD(r5, s32 *, 0x4C));
    }
    SetOv003SceneState(2);
    M2C_FIELD(r5, s8 *, 0x38) = 0;
    func_01ffa6fc(r5);
    func_ov003_021f1bd4();
}

void func_ov003_021e36cc(void *arg0) {
    M2C_UNK func_02088da8(s32);
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    func_ov003_021f1bd4();
    if (M2C_FIELD(arg0, u8 *, 0x39) != 0) {
        func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    SetOv003SceneState(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
}

void func_ov003_021e3708(void) {
    M2C_UNK func_01ffa6fc();
    func_01ffa6fc();
}

#pragma push
#pragma opt_common_subs off
void func_ov003_021e3714(void *arg0) {
    u8 func_ov003_021e1500(s32, s32, s32);
    s32 Modulo(s32, s32);
    void *func_020be120(void);
    void MI_CpuCopy32(void *, void *, u32);
    void ResetBattleMap(void);
    void func_020cf278(s32);
    void LoadBattleMap(s32);
    void ClearTileRect(u16 *, s32, s32);
    void DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    void Clear3DSpriteLayer(void);
    void func_020c12f8(s32, M2C_UNK, s32, s32);
    s32 func_020c1878(void *);

    extern void **gCurrentMap;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;

    s32 value;
    s32 id;
    u8 index;
    s32 offset;
    void *src;
    void *dest;
    u16 **savedEngine;
    u8 *eng;
    void *ptr;
    u8 b0;
    u16 arg5;
    u8 b1;
    s32 mul;
    u8 bb;
    u8 cond;
    void *p5c;

    id = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x06);
    

    if (func_ov003_021e1500(id, 0, 4)) {
        value = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + (id & 0xff) * 2 + 0x08);
    } else if (func_ov003_021e1500(id, 5, 9)) {
        value = (u16)(id + 0x10E);
    }
    index = (u8)Modulo(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 6), 5);
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 6) >= 5) {
        src=func_020be120();
        offset=index * 0x6f8;
        MI_CpuCopy32((u8 *)M2C_FIELD(arg0,void **,0x6c) + offset, src, 0x6f8);
    } else {
        src=func_020be120();
        offset=index * 0x6f8;
        MI_CpuCopy32((u8 *)M2C_FIELD(arg0,void **,0x68) + offset, src, 0x6f8);
    }

    ResetBattleMap();
    func_020cf278(value);
    LoadBattleMap(value);

    *(u16 *)((u8 *)arg0 + 0x62) = (u16)(*(u16 *)((u8 *)*gCurrentMap + 0x5144) << 2);
    *(u16 *)((u8 *)arg0 + 0x64) = (u16)(*(u16 *)((u8 *)*gCurrentMap + 0x5146) << 2);

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    ptr = (u8 *)(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 6) >= 5 ? M2C_FIELD(arg0,void **,0x6c) : M2C_FIELD(arg0,void **,0x68)) + offset + 6;
    ClearTileRect(M2C_FIELD(gCur3DSpriteEngine,u16 **,0x2c), 9, 2);

    b0 = *(u8 *)((u8 *)arg0 + 0x60);
    arg5 = (u16)((((u32)(b0 << 28) >> 30) << 4) + 1);

    DrawTextLine(0, 0, 3, ptr, 0x9000, arg5);

    eng = (u8 *)gCur3DSpriteEngine;
    *(eng + 0x46) |= 0x08;
    ((void (*)(s32))Clear3DSpriteLayer)(0);
    eng=(u8 *)gCur3DSpriteEngine;

    b1 = *(u8 *)((u8 *)arg0 + 0x60);
    mul = (((u32)(b1 << 28) >> 30) * 0x142) + 1;
    func_020c12f8(M2C_FIELD(eng,s32 *,0x0c), M2C_FIELD(eng,s32 *,0x20), mul, 5);

    ((PreviewBits *)((u8 *)arg0+0x60))->bank = (u8)(!((PreviewBits *)((u8 *)arg0+0x60))->bank);

    eng = (u8 *)gCur3DSpriteEngine;
    *(eng + 0x46) |= 0x01;

    gCur3DSpriteEngine = savedEngine;

    p5c = *(void **)((u8 *)arg0 + 0x5C);
    func_020c1878((u8 *)p5c + 0x1C);
}
#pragma pop
/* Draws the map-preview panel's unit-category grid: eight cells in a
 * three-column layout, each showing a category icon and, when that category has
 * units on the map, how many.  `originX`/`originY` slide the panel into place. */
void Ov003_DrawPreviewUnitCategoryGrid(void *panel, s16 originX, s16 originY) {
    s32 Divide(s32, s32);
    s32 Modulo(s32, s32);
    void SetTextSpriteValue(void *, s32);
    void DrawTextSprite(void *);
    s32 GetUnitCategoryCount(void *, s32, s32);
    s32 GetIconGridRecordIndex(u8);
    void AddSprite(u16, u8, u16, void *, s32);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;
    extern u8 gSpriteDesc16x32[];
    s32 xMask, tileMask, allBands, baseY, baseX;
    s16 cellX, cellY, count;
    void *ptr;
    s32 cell, palette, tile;
    u16 **savedEngine;

    baseX = originX;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x3A) = (s16)(0 - originX);
    cell = 0;
    tile = 0x210;
    baseY = originY;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    allBands = -1;
    xMask = 0x1FF;
    tileMask = 0x3FF;
    do {
        cellX = (s16)(Modulo(cell, 3) * 0x16 + baseX);
        cellY = (s16)(Divide(cell, 3) * 0x1C + baseY);
        ptr = M2C_FIELD(panel, void **, OV003_PREVIEW_UNIT_GRID);
        count = (s16)GetUnitCategoryCount((void *)((char *)ptr + 0x1C), GetIconGridRecordIndex((u8)cell), allBands);
        if (count != 0) {
            savedEngine = gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineSub;
            SetTextSpriteValue(M2C_FIELD(panel, void **, OV003_PREVIEW_UNIT_TEXT), count);
            ptr = M2C_FIELD(panel, void **, OV003_PREVIEW_UNIT_TEXT);
            M2C_FIELD(ptr, s16 *, 6) = (s16)(cellX + 0x14);
            M2C_FIELD(ptr, s16 *, 8) = (s16)(cellY + 0x66);
            DrawTextSprite(M2C_FIELD(panel, void **, OV003_PREVIEW_UNIT_TEXT));
            gCur3DSpriteEngine = savedEngine;
        }
        palette = (count != 0) ? 7 : 8;
        AddSprite((u16)((cellX + 4) & xMask),
                      (u8)(cellY + 0x4E),
                      (u16)(((tileMask & (tile >> ((u32)(**gCur3DSpriteEngine << 0x11) >> 0x1E))) |
                             (u16)(palette << 0xC)) | 0x400),
                      gSpriteDesc16x32,
                      0x11);
        tile += 8;
        cell++;
    } while (cell < 8);
}

#pragma opt_common_subs off
#pragma opt_propagation on
#pragma opt_strength_reduction on
void func_ov003_021e3aec(void *arg0, s32 arg1) {
    u8 func_ov003_021e1500(s32, s32, s32);
    void *GetMapRecord(s32);
    s32 func_ov003_02200968(s32);
    void AddSprite(u16, u8, u16, void *, s32);
    s32 func_ov003_02200a18(s32, u16);
    s32 Modulo(s32, s32);
    void SetTextSpriteValue(void *, s32);
    void DrawTextSprite(void *);
    void DrawFrameBorder(s16, s16, s16, s16, s32, s32, s32);
    void *GetMapRecordStamp(s32);
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;
    extern u8 data_ov003_0220f34c[];
    extern M2C_UNK gSpriteDesc16x16;

    s32 bit;
    u8 id;
    u16 value, value2, tile;
    s32 adj;
    volatile s32 flag;
    u8 *p5c, *p;
    s16 w, h;
    s32 x, shift, color;
    u8 i, j;
    u32 word;
    s32 r6;
    u16 *saved, *p54;
    s32 id40;

    flag = 0;
    bit = 0;
    adj = 0;
    id = M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), u8 *, 6);
    
    if (func_ov003_021e1500(id, 0, 4)) {
        value = M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x5c) + (id & 0xff) * 2, u16 *, 8);
    } else if (func_ov003_021e1500(id, 5, 9)) {
        value = (u16)(id + 0x10e);
    }

    p = GetMapRecord(value);
    if (M2C_FIELD(p, u8 *, 0x2f) != 0) flag = 1;
    if (M2C_FIELD(p,PreviewItemStatus*,0x38).enabled) bit = 1;

    if (flag != 0) {
        if (bit != 0) adj = -0x40;
        tile = (u16)(func_ov003_02200968(7) * 16 + 0x140);
        shift = (u32)(*(u16 *)*gCur3DSpriteEngine << 0x11) >> 0x1e;
        x = (arg1 + 0xc0 + adj) & 0x1ff;
        color = (0x3ff & (tile >> shift)) | 0x6000;
        AddSprite((u16)x, 0x1c, (u16)color, data_ov003_0220f34c, 0xb);
    }
    if (bit != 0) {
        tile = (u16)(func_ov003_02200968(0xc) * 16 + 0x140);
        shift = (u32)(*(u16 *)*gCur3DSpriteEngine << 0x11) >> 0x1e;
        x = (arg1 + 0xc0) & 0x1ff;
        color = (0x3ff & (tile >> shift)) | 0x6000;
        AddSprite((u16)x, 0x1c, (u16)color, data_ov003_0220f34c, 0xb);
    }

    w = M2C_FIELD(arg0, s16 *, 0x62);
    h = M2C_FIELD(arg0, s16 *, 0x64);
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x38) = (s16)(-((0xa4 - (w / 2)) + arg1));
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = (s16)(-(0x6c - (h / 2)));

    w = M2C_FIELD(arg0, s16 *, 0x62);
    h = M2C_FIELD(arg0, s16 *, 0x64);
    shift = (u32)(*(u16 *)*gCur3DSpriteEngine << 0x11) >> 0x1e;
    color = (u16)((0x3ff & (0x288 >> shift)) | 0xa000);
    DrawFrameBorder((s16)((0xa3 - (w / 2)) + arg1), (s16)(0x6b - (h / 2)), (s16)(w + 2), (s16)(h + 2), color, 0x11, 1);

    id = M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), u8 *, 6);
        if (func_ov003_021e1500(id, 0, 4)) {
        value2 = M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x5c) + (id & 0xff) * 2, u16 *, 8);
    } else if (func_ov003_021e1500(id, 5, 9)) {
        value2 = (u16)(id + 0x10e);
    }

    tile = (u16)(func_ov003_02200a18(7, value2) * 4 + 0x328);
    shift = (u32)(*(u16 *)*gCur3DSpriteEngine << 0x11) >> 0x1e;
    color = (0x3ff & (tile >> shift)) | 0x9800;
    AddSprite((u16)((arg1 + 3) & 0x1ff), 0x15, (u16)color, &gSpriteDesc16x16, 0x11);

    SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x50), (s16)(Modulo(M2C_FIELD(M2C_FIELD(arg0,void**,0x48),u8*,6), 5) + 1));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), u8 *, 0x28) &= ~0xe0;
    p54=M2C_FIELD(arg0,void**,0x50);
    M2C_FIELD(p54,s16*,6)=(s16)(arg1+0x24);
    M2C_FIELD(p54,s16*,8)=0x1c;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s16 *, 0x12) = 0x258;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), u8 *, 0x21) = 9;
    DrawTextSprite(M2C_FIELD(arg0, void **, 0x50));

    p = GetMapRecordStamp(value);
    id40 = arg1 + 0x40;
    for (i = 0; i < 2; i = (u8)(i + 1)) {
        switch (i) {
        case 0:
            word = M2C_FIELD(p, u32 *, 0xc);
            saved = (u16 *)gCur3DSpriteEngine;
            gCur3DSpriteEngine = g3DSpriteEngineSub;
            r6 = (s32)((u32)(word << 4) >> 0x16);
            SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x54), r6);
            p54 = M2C_FIELD(arg0, void **, 0x54);
            M2C_FIELD(p54, s16 *, 6) = (s16)id40;
            M2C_FIELD(p54, s16 *, 8) = 0x3b;
            DrawTextSprite(M2C_FIELD(arg0, void **, 0x54));
            gCur3DSpriteEngine = (u16 **)saved;
            break;
        case 1:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), u8 *, 0x29) = 2;
            saved = (u16 *)gCur3DSpriteEngine;
            for (j = 0; j < 3; j = (u8)(j + 1)) {
                if (j == 0) {
                    r6 = M2C_FIELD(p,PreviewItemFields*,8).low;
                } else if (j == 1) {
                    r6 = M2C_FIELD(p,PreviewItemFields*,8).middle;
                } else if(j == 2) {
                    r6 = M2C_FIELD(p,PreviewItemFields*,8).high;
                }
                gCur3DSpriteEngine = g3DSpriteEngineSub;
                SetTextSpriteValue(M2C_FIELD(arg0, void **, 0x54), (s16)r6);
                p54=M2C_FIELD(arg0,void**,0x54);
                M2C_FIELD(p54,s16*,6)=(s16)(arg1+j*0x16+0x14);
                M2C_FIELD(p54,s16*,8)=0x45;
                DrawTextSprite(M2C_FIELD(arg0, void **, 0x54));
                gCur3DSpriteEngine = (u16 **)saved;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), u8 *, 0x29) = 0;
            break;
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
void func_ov003_021e3ff8(void *arg0,s32 arg1,s32 arg2){
u32 func_ov003_021f2780(s32,s32);
u32 func_ov003_021f2574(void);
s32 func_ov003_02200a18(s32,u16);
s32 Modulo(s32,s32);
void SetTextSpriteValue(void*,s32);
extern u16 **gCur3DSpriteEngine;
extern M2C_UNK gSpriteDesc16x16;
s32 px,layer,mask,py,headerX;
u32 count0,count1,n,h;
u32 count;
u8 total,k,total2,k2;
u8 j;
u8 i;
s32 sequence;
s32 left;
s32 top;
s32 headerY;
s32 hx1,hx2,hx3,hx0;
s32 record;
u16 id;
u16 tile;
s16 offset;
void *p;
count0=func_ov003_021f2780(M2C_FIELD(arg0,s32*,0x5c)+4,M2C_FIELD(arg0,s32*,0x5c)+8);
count1=func_ov003_021f2574();
p=M2C_FIELD(arg0,void**,0x6c);
total=0;
k=0;do{if(M2C_FIELD((u8*)p+k*0x6f8,u8*,0x27))total++;k++;}while(k<5);
if(count1>=total)count1=total;
M2C_FIELD(*(void**)gCur3DSpriteEngine,s16*,0x3e)=-(arg1-6);
M2C_FIELD(*(void**)gCur3DSpriteEngine,s16*,0x46)=0;
M2C_FIELD(*(void**)gCur3DSpriteEngine,s16*,0x38)=-(arg1+40);
M2C_FIELD(*(void**)gCur3DSpriteEngine,s16*,0x40)=-arg2;
Clear3DSpriteLayer(0);
i=0;
sequence=1;
do{
count=i==0?count0:count1;
j=0;
if(j<count){
left=arg1+(i<<7);
if(count>0){
px=(s16)(left+34);py=(u16)((left+3)&511);layer=(s16)(i*16);mask=0x3ff;
do{
if(i==0)id=M2C_FIELD(M2C_FIELD(arg0,s32*,0x5c)+j*2,u16*,8);else id=j+0x113;
top=arg2+(j<<4);
offset=Modulo(j*2,32);
SetTextSpriteValue(M2C_FIELD(arg0,void**,0x50),(s16)(j+1));
p=M2C_FIELD(arg0,void**,0x50);
M2C_FIELD(p,u8*,0x28)=(M2C_FIELD(p,u8*,0x28)&~0xe0)|0x20;
p=M2C_FIELD(arg0,void**,0x50);
M2C_FIELD(p,s16*,6)=px;M2C_FIELD(p,s16*,8)=top+5;
M2C_FIELD(M2C_FIELD(arg0,void**,0x50),s16*,0x12)=0x21c;
M2C_FIELD(M2C_FIELD(arg0,void**,0x50),u8*,0x21)=8;
DrawTextSprite(M2C_FIELD(arg0,void**,0x50));
tile=(u16)(func_ov003_02200a18(7,id)*4+0x234);
AddSprite(py,(u8)(top-2),(u16)((mask&((s32)tile>>((EngineBits3ff8*)*gCur3DSpriteEngine)->shift))|0x8800),&gSpriteDesc16x16,17);
if(i==0)record=M2C_FIELD(arg0,s32*,0x68);else record=M2C_FIELD(arg0,s32*,0x6c);
func_0209b32c(layer,offset,0,record+j*0x6f8+6,0x7000,0,(u16)(sequence+M2C_FIELD(arg0,MenuBits3ff8*,0x60).bank*320));
sequence+=16;j++;
}while(j<count);
}
}
i++;
}while(i<2);
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;
M2C_FIELD(arg0,MenuBits3ff8*,0x60).bank=(u8)(M2C_FIELD(arg0,MenuBits3ff8*,0x60).bank==0);
hx0=arg1+17;hx1=arg1+33;hx2=arg1+217;hx3=arg1+233;
headerY=arg2-12;
h=0;
do {
switch(h){
case 0:headerX=(s16)hx0;n=func_ov003_021f2780(M2C_FIELD(arg0,s32*,0x5c)+4,M2C_FIELD(arg0,s32*,0x5c)+8);break;
case 1:headerX=(s16)hx1;n=5;break;
case 2:headerX=(s16)hx2;n=func_ov003_021f2574();p=M2C_FIELD(arg0,void**,0x6c);total2=0;k2=0;do{if(M2C_FIELD((u8*)p+k2*0x6f8,u8*,0x27))total2++;k2++;}while(k2<5);if(n>=total2)n=total2;break;
case 3:headerX=(s16)hx3;n=5;break;
}
SetTextSpriteValue(M2C_FIELD(arg0,void**,0x50),n);
p=M2C_FIELD(arg0,void**,0x50);M2C_FIELD(p,u8*,0x28)&=~0xe0;
p=M2C_FIELD(arg0,void**,0x50);M2C_FIELD(p,s16*,6)=headerX;M2C_FIELD(p,s16*,8)=headerY;
M2C_FIELD(M2C_FIELD(arg0,void**,0x50),s16*,0x12)=0x21c;
M2C_FIELD(M2C_FIELD(arg0,void**,0x50),u8*,0x21)=8;
DrawTextSprite(M2C_FIELD(arg0,void**,0x50));
h=(u8)(h+1);
}while(h<4);
}
#pragma pop
