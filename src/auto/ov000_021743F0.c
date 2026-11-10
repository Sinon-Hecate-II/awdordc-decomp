/* 24 functions from 0x021743F0 to 0x02175310 (ov000), found by ds-decomp. */
#include "common.h"

typedef Ov000InfoMenu Ov000MenuState;
typedef struct { u16 pad[3]; u16 low:15, flag:1; } Ov000Flags;

/* Per-frame update of the map info window: follows the map cursor, blinks it,
 * opens the terrain or unit-statistics panel for the cell under the cursor and
 * runs the panel's state machine. */
void Ov000_InfoWindow_Update(Ov000MenuState *menu) {
extern void **gCurrentMap; extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineSub; extern Ov000MenuState *gOv000InfoWindow; extern u8 data_021291b0[];
int func_020d4ea8(void); int func_01ffa770(void *); s32 func_ov000_0216ca8c(s32,s32);
void Ov000_InfoWindow_SetUnitFlags(void *); void Ov000_InfoWindow_ClearUnitFlags(void *); void Ov000_InfoWindow_ShowTerrain(void *,s32); void Ov000_InfoWindow_OpenCell(void *,s32,s32);
void func_ov000_021725e0(void *); void func_ov000_02172654(void *); void func_ov000_02172648(void *); void func_ov000_021751b4(void *); void func_ov000_02175234(void *); void func_ov000_02175230();
s32 x=M2C_FIELD(*gCurrentMap,s16 *,0x52c2), y=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
void *saved=gCur3DSpriteEngine; s32 mode;
gCur3DSpriteEngine=g3DSpriteEngineSub;
Ov000_InfoWindow_SetUnitFlags(menu);
mode=func_020d4ea8();
switch(mode) {
case 2:
if(menu->prevMode!=func_020d4ea8())menu->trigger=1;
if(menu->trigger){
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|16;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|32;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|64;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|128;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|256;}
if(menu->pendingState!=OV000_INFO_NO_TERRAIN)menu->pendingState=OV000_INFO_NO_TERRAIN;
Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow,-1); menu->hasUnit=0;
}
menu->cursorX=x; menu->cursorY=y;
menu->pressed=0; menu->trigger=0; break;
case 0: case 1:
if(menu->prevMode!=func_020d4ea8())menu->trigger=1;
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|16;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|32;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|64;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|128;}
{u16 * volatile p=*(u16 **)gCur3DSpriteEngine; p[0]=p[0]|256;}
if(x!=menu->cursorX||y!=menu->cursorY){
menu->animFrame=0; menu->cursorX=x; menu->cursorY=y;
}
if(menu->animFrame>=0){
if(menu->animFrame<4)menu->animFrame++;
else {M2C_FIELD(menu,u8 *,0x1a)=255; menu->trigger=1;}
}
{u8 confirm=func_01ffa770(data_021291b0)!=0;
if(menu->pressed&&!confirm)menu->trigger=1;
menu->pressed=confirm;
}
if(menu->trigger){
void *unit=0; s32 terrain;
menu->trigger=0;
if(menu->pressed)menu->pendingState=OV000_INFO_UNIT_STATS;
else {
void *map=*gCurrentMap; u32 cell=x+((u16 *)((u8 *)map+0x3758))[y];
void *occupant=(u8 *)map+0x59a4+((u8 *)map)[cell]*14;
if((u8)(M2C_FIELD((u8 *)map+(cell>>3),u8 *,0x5201)&(1<<(cell&7)))){
if(occupant==0 || ((u32)(M2C_FIELD(occupant,u8 *,0)<<26)>>26)==0){
void *selected=M2C_FIELD(map,void **,0x52d0);
if(selected && M2C_FIELD(selected,u8 *,1)==x && M2C_FIELD(selected,u8 *,2)==y)occupant=selected;
}
if(occupant && ((u32)(M2C_FIELD(occupant,u8 *,0)<<26)>>26)==0)unit=0; else unit=occupant;
}
terrain=func_ov000_0216ca8c(x,y);
if(unit){menu->hasUnit=1;Ov000_InfoWindow_OpenCell(gOv000InfoWindow,(s32)unit,terrain);}
else {menu->hasUnit=0;Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow,terrain);}
}
}break;
}
Ov000_InfoWindow_ClearUnitFlags(menu); menu->prevMode=func_020d4ea8();
switch(menu->state){
case 1:
if(menu->pendingState!=0&&menu->pendingState!=1){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;}break;
case 2:
M2C_FIELD(menu->panel,u8 *,0x15)=0;
if(menu->refresh){menu->refresh=0;func_ov000_021725e0(menu->panel);}
func_ov000_02172654(menu->panel);
if(menu->pendingState){
if(menu->pendingState==OV000_INFO_NO_TERRAIN){menu->state=menu->pendingState;menu->pendingState=0;M2C_FIELD(menu->panel,s32 *,4)=1;}
else if(menu->pendingState==OV000_INFO_UNIT_STATS){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;func_ov000_02172648(menu->panel);M2C_FIELD(menu->statsWindow,s32 *,0)=M2C_FIELD(menu->panel,s32 *,0)&255;}
}break;
case 3:
M2C_FIELD(menu->panel,u8 *,0x15)=1;
if(menu->refresh){menu->refresh=0;func_ov000_021725e0(menu->panel);}
func_ov000_02172654(menu->panel);
if(menu->pendingState){
if(menu->pendingState==OV000_INFO_TERRAIN){menu->state=menu->pendingState;menu->pendingState=0;M2C_FIELD(menu->panel,s32 *,4)=1;}
else if(menu->pendingState==OV000_INFO_UNIT_STATS){menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;func_ov000_02172648(menu->panel);M2C_FIELD(menu->statsWindow,s32 *,0)=M2C_FIELD(menu->panel,s32 *,0)&255;}
}break;
case 4:
if(menu->refresh){menu->refresh=0;func_ov000_021751b4(menu->statsWindow);}
func_ov000_02175234(menu->statsWindow);
if(menu->pendingState!=0&&menu->pendingState!=OV000_INFO_UNIT_STATS){
menu->state=menu->pendingState;menu->pendingState=0;menu->refresh=1;
func_ov000_02175230(menu->statsWindow);M2C_FIELD(menu->panel,s32 *,0)=M2C_FIELD(menu->statsWindow,s32 *,0)&255;
}break;
}
gCur3DSpriteEngine=saved;
}

void Ov000_InfoWindow_SetUnitFlags(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 1;
}

void Ov000_InfoWindow_ClearUnitFlags(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x13) != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xC) = 0;
}

void Ov000_InfoWindow_OpenCell(void *arg0, s32 arg1, s32 arg2) {
    void Ov000_InfoWindow_ShowTerrain(void *, s32);
    M2C_UNK FillUnitInfo(s32);
    extern Ov000Flags data_0215d9b8;
    extern Ov000MenuState *gOv000InfoWindow;
    if (arg1 == 0) {
        Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow, arg2);
        return;
    }
    if (((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 16) >> 31) == 1) {
        Ov000_InfoWindow_ShowTerrain(gOv000InfoWindow, arg2);
        return;
    }
    FillUnitInfo(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void func_ov000_02174a68(void *arg0) {
    M2C_UNK func_ov000_021755b4(s32);
    func_ov000_021755b4(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0xC) = 4;
}

void Ov000_InfoWindow_ShowTerrain(void *arg0, s32 arg1) {
    M2C_UNK func_ov000_0217272c(s32);
    if (arg1 == -1) {
        M2C_FIELD(arg0, s32 *, 0xC) = 3;
        return;
    }
    func_ov000_0217272c(M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
}

void func_ov000_02174ab4(void *arg0) {
extern void **gCurrentMap;
extern Ov000Flags data_0215d9b8;
extern Ov000MenuState *gOv000InfoWindow;
s32 func_ov000_0216ca8c(s32,s32);
void *unit;
void *base=*gCurrentMap;
s32 x=M2C_FIELD(base,s16 *,0x52c2);
s32 y=M2C_FIELD(base,s16 *,0x52c4);
u32 index=x+((u16 *)((u8 *)base+0x3758))[y];
unit=(u8 *)base+0x59a4+((u8 *)base)[index]*14;
if(!(u8)(M2C_FIELD((u8 *)base+(index>>3),u8 *,0x5201)&(1<<(index&7)))) unit=0;
else {
if(unit==0 || ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0){
void *other=M2C_FIELD(base,void **,0x52d0);
if(other!=0 && M2C_FIELD(other,u8 *,1)==x && M2C_FIELD(other,u8 *,2)==y)unit=other;
}
if(unit && ((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0)unit=0;
}
index=func_ov000_0216ca8c(x,y);
switch(M2C_FIELD(arg0,s32 *,8)){
case 2: case 3: {
u16 flags=M2C_FIELD(&data_0215d9b8,u16 *,6);
void *state=gOv000InfoWindow;
M2C_FIELD(&data_0215d9b8,u16 *,6)=flags & ~0x8000;
Ov000_InfoWindow_OpenCell(state,(s32)unit,index);
break; }
case 4: {
u16 flags=M2C_FIELD(&data_0215d9b8,u16 *,6);
void *state=gOv000InfoWindow;
M2C_FIELD(&data_0215d9b8,u16 *,6)=flags | 0x8000;
Ov000_InfoWindow_ShowTerrain(state,index);
break; }
}
}

void func_ov000_02174be8(void) {
    M2C_UNK func_ov000_02173f78(void *);
    extern Ov000MenuState *gOv000InfoWindow;
    func_ov000_02173f78(gOv000InfoWindow);
}

void func_ov000_02174c00(void) {
    M2C_UNK func_020af1e4();
    func_020af1e4();
}

u8 func_ov000_02174c0c(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    u8 var_r0;
    if (gOv000InfoWindow != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_02174c2c(void) {
    s32 *MemAlloc(M2C_UNK);
    void *func_ov000_02173ea8(void *);
    M2C_UNK func_01ffa3dc(void *, s32);
    extern M2C_UNK data_ov000_021b8e5c;
    extern Ov000MenuState *gOv000InfoWindow;
    void *var_r0;
    var_r0 = MemAlloc(0x20);
    if (var_r0 != 0) {
        var_r0 = func_ov000_02173ea8(var_r0);
    }
    gOv000InfoWindow = var_r0;
    func_01ffa3dc(&data_ov000_021b8e5c, 8);
}

void func_ov000_02174c64(void) {
    void Ov000_InfoWindow_Update(Ov000MenuState *);
    extern Ov000MenuState *gOv000InfoWindow;
    if (func_ov000_02174c0c() == 0) return;
    Ov000_InfoWindow_Update(gOv000InfoWindow);
}

void func_ov000_02174c88(void) {
    void func_ov000_021743ec(void *);
    void func_ov000_02173f30(void *);
    M2C_UNK MemFree(s32);
    void func_01ffa9e4(void *);
    void func_020c127c(void);
    extern Ov000MenuState *gOv000InfoWindow;
    extern M2C_UNK data_ov000_021b8e5c;
    void *temp;
    if (func_ov000_02174c0c() == 0) return;
    func_ov000_021743ec(gOv000InfoWindow);
    temp = gOv000InfoWindow;
    if (temp != 0) {
        func_ov000_02173f30(temp);
        MemFree((s32)temp);
    }
    gOv000InfoWindow = 0;
    func_01ffa9e4(&data_ov000_021b8e5c);
    func_020c127c();
}

void func_ov000_02174ce8(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(gOv000InfoWindow, u8 *, 0x11) = 1;
}

void func_ov000_02174d10(s32 arg0, s32 arg1) {
    extern Ov000MenuState *gOv000InfoWindow;
    if (func_ov000_02174c0c() == 0) return;
    M2C_FIELD(gOv000InfoWindow, u8 *, 0x11) = 1;
    ((void (*)())func_ov000_02174a68)(gOv000InfoWindow, arg0, arg1);
}

s32 func_ov000_02174d50(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    s32 result;
    if (func_ov000_02174c0c() != 0) {
        result = M2C_FIELD(gOv000InfoWindow, u8 *, 0x13);
    } else {
        result = 0;
    }
    return result;
}

s32 func_ov000_02174d78(void) {
    void func_ov000_02174ab4(void *);
    extern Ov000MenuState *gOv000InfoWindow;
    if (func_ov000_02174c0c() == 0) return 0;
    func_ov000_02174ab4(gOv000InfoWindow);
    return 1;
}

void func_ov000_02174da4(s32 x, s32 y) {
    extern u16 gTurnTimeConfig[];
    extern void **gCurrentMap;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern u32 gTimerColonTiles[];
    extern u32 gTimerDigitTiles[];
    s32 HardDiv(s32, s32);
    void AddSprite(u16, u16, u16, void *, s32);

    s32 total, minutes, centis, palette, separator;
    void *map;
    void *savedSpriteEngine;

    total = gTurnTimeConfig[2];
    if (total == 0) return;

    map = *gCurrentMap;
    {
        void *player = (u8 *)map + M2C_FIELD(map, u16 *, 0x52a4) * 140;
        s32 elapsed = M2C_FIELD(player, s32 *, 0x682c);
        if (!elapsed) return;
        total -= elapsed;
    }

    if (total < 0) total = 0;

    minutes = HardDiv(total, 60);
    centis = HardDiv((total % 60) * 100, 60);

    palette = 8;
    separator = 180;
    if (total < 600) {
        palette = 10;
        separator = 181;
    }

    savedSpriteEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    AddSprite(x, y, ((182 >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30)) & 1023) | 0x6000, gTimerColonTiles, 1);
    AddSprite(x + 72, y, ((centis % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);

    centis = HardDiv(centis, 10);
    AddSprite(x + 64, y, ((centis % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);
    AddSprite(x + 56, y, ((separator >> ((u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30)) & 1023) | 0x6000, gTimerDigitTiles, 1);

    x += 48;
    do {
        AddSprite(x, y, ((minutes % 10 + 140) & 1023) | ((palette & 15) << 12), gTimerDigitTiles, 1);
        minutes = HardDiv(minutes, 10);
        x -= 8;
    } while (minutes != 0);

    gCur3DSpriteEngine = savedSpriteEngine;
}

s32 func_ov000_02175074(void) {
    extern Ov000MenuState *gOv000InfoWindow;
    return M2C_FIELD(gOv000InfoWindow, s32 *, 0x1C);
}

/* Initialize the 0x14-byte sub-object stored at entry+0x10 (allocating it
 * and its 0x104-byte descriptor) and clear the leading fields of entry. */
void *func_ov000_02175088(void *entry) {
    s32 *MemAlloc(M2C_UNK);
    s32 *alloc;

    M2C_FIELD(entry, s32 *, 0) = 0;
    M2C_FIELD(entry, s32 *, 4) = 0;
    M2C_FIELD(entry, s32 *, 8) = 0;
    M2C_FIELD(entry, s8 *, 0xC) = 0;
    alloc = MemAlloc(0x104);
    M2C_FIELD(entry, s32 **, 0x10) = alloc;
    *alloc = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x14) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x18) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x1C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x20) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x24) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x3C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x2C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x44) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xC) = -1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x58) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x5C) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x48) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s8 *, 0x49) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x50) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x4C) = 0x63;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x54) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x60) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0xFC) = 0;
    M2C_FIELD(M2C_FIELD(entry, s32 **, 0x10), s32 *, 0x100) = 0;
    return entry;
}

void *func_ov000_0217519c(void *arg0) {
    M2C_UNK MemFree(s32);
    MemFree(M2C_FIELD(arg0, s32 *, 0x10));
    return arg0;
}

void func_ov000_021751b4(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02175230(void) {

}

void func_ov000_02175234(void *arg0){
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    void *saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 16), s32 *, 8) <= 0) {
        return;
    }

    switch (M2C_FIELD(arg0, s32 *, 4)) {
        case 1:
            func_020809c0(M2C_FIELD(gCur3DSpriteEngine, void **, 0x24), 32, 32);
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 2:
            func_ov000_021769dc(arg0);
            func_ov000_02176a0c(arg0);
            M2C_FIELD(arg0, s32 *, 4) = 0;
            break;
        case 0:
            M2C_FIELD(arg0, s32 *, 8)++;
            if (M2C_FIELD(arg0, s32 *, 8) >= 80) {
                M2C_FIELD(arg0, s32 *, 8) = 0;
            }
            if (M2C_FIELD(arg0, s32 *, 8) == 0 || M2C_FIELD(arg0, s32 *, 8) == 40) {
                func_ov000_02176a9c(arg0);
            }
            break;
    }

    func_ov000_02175fb0(arg0);
    gCur3DSpriteEngine = saved;
}

