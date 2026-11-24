/* 53 functions from 0x020C0254 to 0x020C1230 (main), found by ds-decomp. */
#include "common.h"
#include "sprite_slot.h"
#include "ds3dsprite.h"
#include "battle_map.h"
/* A row of the caller-supplied 0x28-byte entry table a carried-unit list menu is
 * built from: the row kind (0xff ends the table), the callback that reports the
 * row's status, the row's icon/highlight/action callbacks and the sprite-slot id
 * and icon kind it draws. */
typedef struct {
    u8 kind;                          /* +0x00 row kind, 0xff ends the table */
    u8 pad01[3];
    s32 (*getStatus)(void);           /* +0x04 returns the row's status byte (2 = hidden) */
    void (*drawIcon)(s32, u8, u8);    /* +0x08 draws the row's icon */
    void (*field0C)(s32, u8, u8);     /* +0x0C */
    void (*highlight)(s32, u8, u8);   /* +0x10 highlights the row in the sprite batch */
    u8 pad14[4];
    void (*action)(s32, u8, u8);      /* +0x18 the row's confirm action */
    void (*field1C)(s32, u8, u8);     /* +0x1C */
    u8 pad20[4];
    u16 slot;                         /* +0x24 sprite-slot id of the row */
    u16 icon;                         /* +0x26 icon kind the row draws */
} MenuRowC0634;
/* The carried-unit list menu func_020c0634 builds and OpenListMenu drives: the
 * caller's entry table, a status and an entry index per visible row, the row
 * counts, the chosen row and the panel's screen position. */
typedef struct {
    u8 pad[0x34];
    void *entries;    /* +0x34 caller's 0x28-byte entry table */
    u8 status[10];    /* +0x38 per-row status; a row whose status is 2 is hidden */
    u8 indices[10];   /* +0x42 entry-table index of each visible row */
    u8 total;         /* +0x4c rows the entry table holds */
    u8 count;         /* +0x4d visible rows */
    u8 selection;     /* +0x4e chosen row */
    u8 width;         /* +0x4f panel width */
    u8 pad50[4];      /* +0x50 */
    s16 x, y;         /* +0x54 panel screen position */
} MenuC0634;
typedef struct { u8 pad[0x1420]; u8 tiles[0x2338]; u16 rows[0x40]; u8 pad37d8[0x196c]; u16 width,height; u8 pad5148[0xb9]; u8 visible[0x200]; } MapC10;
extern void *gCarriedUnitMenuStackPtr;
extern u8 gCarriedUnitMenuStateStack[];
/* One saved carried-unit list menu on the menu-state stack: the panel's
 * position and width, the chosen row and the caller's entry table. */
typedef struct { s8 x, y, selection, width; s32 entries; } CarriedUnitMenuState;

u8 func_020c0254(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02129404;
    u8 var_r0;

    if (FindObjectByClass(&data_02129404) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* In each graphics bank, clear the low status bits of the first entry and set status bit 0x100. */
void func_020c0278(void) {
    M2C_UNK Set3DSpriteVramBanks();
    M2C_UNK Apply3DSpriteDisplayConfig();
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    u16 *volatile ctx0;
    u16 *volatile ctx1;
    u16 *volatile ctx2;
    u16 *volatile ctx3;
    u16 *volatile ctx4;
    s32 savedBank;
    s32 i;

    Set3DSpriteVramBanks();
    savedBank = gCur3DSpriteEngine;
    i = 0;
    do {
        gCur3DSpriteEngine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        Apply3DSpriteDisplayConfig();
        ++i;
        ctx0 = *(u16 **)gCur3DSpriteEngine;
        *ctx0 = *ctx0 & ~0x10;
        ctx1 = *(u16 **)gCur3DSpriteEngine;
        *ctx1 = *ctx1 & ~0x20;
        ctx2 = *(u16 **)gCur3DSpriteEngine;
        *ctx2 = *ctx2 & ~0x40;
        ctx3 = *(u16 **)gCur3DSpriteEngine;
        *ctx3 = *ctx3 & ~0x80;
        ctx4 = *(u16 **)gCur3DSpriteEngine;
        *ctx4 = *ctx4 | 0x100;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
}

void func_020c0374(void) {
    M2C_UNK func_02075fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02076198();
    func_02075fd8(0, 0, 0, 0);
    func_02076198();
}

void func_020c0394(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 func_02076218();
    extern M2C_UNK data_021294c4;
    if (func_02076218() == 0) {
        return;
    }
    CreateSpriteObject(&data_021294c4, arg0);
}

s32 GetCarriedUnitListEntry(void *arg0, s32 arg1) {
    return (M2C_FIELD((arg0 + arg1), u8 *, 0x42) * 0x28) + M2C_FIELD(arg0, s32 *, 0x34);
}

s8 GetCarriedUnitListEntryStatus(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), s8 *, 0x38);
}

/* Highlight a carried-unit list row: draw the list batch with the row's icon kind
 * picked out in the highlight palette, then run the row's highlight callback when
 * it has one, passing the row's entry, index and status byte. */
void HighlightListMenuRow(void *menu, s32 row) {
    void SetSpriteBatchHighlightKind(u16);
    void DrawSpriteBatch(void);
    MenuRowC0634 *entry;
    void (*highlight)(s32, u8, u8);

    entry = (MenuRowC0634 *)GetCarriedUnitListEntry(menu, row);
    SetSpriteBatchHighlightKind(entry->icon);
    DrawSpriteBatch();
    highlight = entry->highlight;
    if (highlight == 0) return;
    highlight((s32)entry, row, M2C_FIELD(menu + row, u8 *, 0x38));
}

void DrawListMenuRowIcon(void *arg0, s32 arg1) {
    s32 temp_r0;
    void (*temp_r3)(s32, u8, u8);
    temp_r0 = GetCarriedUnitListEntry(arg0, arg1);
    temp_r3 = M2C_FIELD(temp_r0, void (**)(s32, u8, u8), 8);
    if (temp_r3 == 0) return;
    temp_r3(temp_r0, arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c0454(void *arg0, s32 arg1) {
    s32 temp_r0;
    void (*temp_r3)(s32, u8, u8);
    temp_r0 = GetCarriedUnitListEntry(arg0, arg1);
    temp_r3 = M2C_FIELD(temp_r0, void (**)(s32, u8, u8), 0xC);
    if (temp_r3 == 0) return;
    temp_r3(temp_r0, arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void RunCarriedUnitRowAction(void *arg0, s32 arg1) {
    void (*callback)(s32, u8, u8);
    s32 entry;
    entry = GetCarriedUnitListEntry(arg0, arg1);
    callback = M2C_FIELD(entry, void (**)(s32, u8, u8), 0x18);
    if (callback == NULL) return;
    callback(entry, (u8)arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void func_020c04b4(void *arg0, s32 arg1) {
    void (*callback)(s32, u8, u8);
    s32 entry;
    entry = GetCarriedUnitListEntry(arg0, arg1);
    callback = M2C_FIELD(entry, void (**)(s32, u8, u8), 0x1C);
    if (callback == NULL) return;
    callback(entry, (u8)arg1, M2C_FIELD(arg0 + arg1, u8 *, 0x38));
}

void UpdateListMenu(void) {
    s32 GetCarriedUnitMenu(void);
    void DrawCarriedUnitList();
    if (GetCarriedUnitMenu() == 0) return;
    DrawCarriedUnitList();
}

/* Lay out and show the list menu: draw the row batch and the preview unit
   sprite, let every visible row draw its own icon, highlight the selected row,
   create one sprite slot per row, then register the per-frame redraw task. */
void OpenListMenu(void *arg0) {
    M2C_UNK CreateFrameCallbackTask(void (*)(void), M2C_UNK);
    void HighlightListMenuRow(void *, s32);
    void DrawListMenuRowIcon(void *, s32);
    M2C_UNK CreateCarriedUnitRowSlots(void *);
    M2C_UNK DrawCarriedUnitListBatch();
    void *CreateMenuUnitSprite(void *);

    void UpdateListMenu(void);
    MenuC0634 *menu = (MenuC0634 *)arg0;
    s32 row;

    DrawCarriedUnitListBatch();
    CreateMenuUnitSprite(arg0);
    row = 0;
    if ((s32) menu->count > 0) {
        do {
            DrawListMenuRowIcon(arg0, row);
            row += 1;
        } while (row < (s32) menu->count);
    }
    HighlightListMenuRow(arg0, menu->selection);
    CreateCarriedUnitRowSlots(arg0);
    CreateFrameCallbackTask(&UpdateListMenu, 9);
}

/* Closes the carried-unit list menu: stops its per-frame redraw task, requests the
 * outro of the menu's row slots, clears the map-view sprite layers, runs the view
 * controller's callback at +0x04, then releases the map-view hold the menu took
 * while it was open. */
void CloseCarriedUnitListMenu(void *menu) {
    M2C_UNK DeleteFrameCallbackTask(void (*)(void));
    void UpdateListMenu(void);
    void CloseCarriedUnitListSprites();
    void ResetMapViewLayers(void);
    M2C_UNK func_0207a668();
    M2C_UNK ReleaseMapViewHold();
    extern void *gCurrentMap;
    void (*callback)(void);
    DeleteFrameCallbackTask(UpdateListMenu);
    CloseCarriedUnitListSprites(menu);
    ResetMapViewLayers();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), 4);
    if (callback != NULL) callback();
    func_0207a668();
    ReleaseMapViewHold();
}

s32 GetCarriedUnitMenu(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02129630;
    return FindObjectByClass(&data_02129630);
}

u8 IsCarriedUnitListOpen(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_02129630;
    u8 var_r0;

    if (FindObjectByClass(&data_02129630) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020c05e8(void) {
    return 0;
}

void func_020c05f0(void) {
    void DeleteMapMenuSprites(void);
    DeleteMapMenuSprites();
}

void func_020c05fc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_020c0634(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void ResetCarriedUnitMenuStack();
    ResetCarriedUnitMenuStack();
    func_020c0634(arg0, arg1, arg2, arg3, arg4);
}

#pragma opt_instruction_scheduling off
s32 func_020c0634(s32 entries,s32 x,s32 y,s32 selection,s32 width) {
void ResetSpriteSlots(void); s32 CreateSpriteFromClass(s32 *,s32); void AcquireMapViewHold(void);
extern s32 data_02129630;
MenuC0634 *p; s16 n=0; u16 height=16; s32 i; s32 offset;
ResetSpriteSlots(); p=(MenuC0634 *)CreateSpriteFromClass(&data_02129630,7); i=n; offset=i;
p->entries=(void *)entries;
for(;;) {
u8 *entry=((u8 *)p->entries)+offset;
u8 *q;
if(entry[0]==255)break;
q=(u8 *)p+n;
p->status[n]=M2C_FIELD(entry,s32 (**)(void),4)();
if(p->status[n]!=2){p->indices[n++]=i;height+=16;}
offset+=40;i++;
}
p->count=n;
p->total=i;
if((u8)n-1<selection)selection=(u16)((u8)n-1);
p->selection=selection;
if(x+16+width>=256)x=256-(width+16);
if(x<0)x=0;
p->width=width;
if(y+height>=192)y=192-height;
if(y<0)y=0;
p->x=x;p->y=y;
AcquireMapViewHold();return (s32)p;
}
#pragma opt_instruction_scheduling reset
void CreateMenuAt(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10017);
    func_020c05fc(arg0, arg1, arg2, 0, arg3);
}

void DeleteMapMenuSprites(void) {
    M2C_UNK func_0209bfa8();
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02129630;
    func_0209bfa8();
    DeleteSpriteObjectsOfClass(&data_02129630);
}

/* Stamps a filled window frame into the 32-column tile map `tilemap`: the frame
 * tiles along the border (one corner tile mirrored by the flip bits at each
 * corner) and the interior fill, in the plain or striped window style. Each cell
 * holds the tile id plus the palette in bits 12-15. */
void DrawFrameTiles(s32 x,s32 y,s32 w,s32 h,s32 tilemap,s32 pal,u8 striped){
s32 col,row,t;
for(row=y;row<y+h;row++){
for(col=x;col<x+w;col++){
if(col==x+w-1){if(row==y+h-1)t=FRAME_TILE_FLIP_H|FRAME_TILE_FLIP_V|FRAME_TILE_CORNER;else if(row==y)t=FRAME_TILE_FLIP_H|FRAME_TILE_CORNER;else t=FRAME_TILE_FLIP_H|FRAME_TILE_EDGE_V;}
else if(col==x){if(row==y+h-1)t=FRAME_TILE_FLIP_V|FRAME_TILE_CORNER;else if(row==y)t=FRAME_TILE_CORNER;else t=FRAME_TILE_EDGE_V;}
else if(striped){if(row==y+h-1)t=FRAME_TILE_FLIP_V|FRAME_TILE_EDGE_H;else if(row==y)t=FRAME_TILE_EDGE_H_ALT;else if((row-y)&1)t=FRAME_TILE_FILL;else t=FRAME_TILE_STRIPE;}
else {if(row==y+h-1)t=FRAME_TILE_FLIP_V|FRAME_TILE_EDGE_H;else if(row==y)t=FRAME_TILE_EDGE_H;else t=FRAME_TILE_FILL;}
((u16 *)tilemap)[row*32+col]=t+((pal&15)<<12);
}
}
}

/* Stamp a filled window frame at tile (x, y), width x height, into the current
 * 3D-sprite engine's layer-2 tile map in palette 3; then run the map-view
 * controller's frame callback and mark layer 2 dirty so it uploads. */
void DrawWindowFrame(s32 x, s32 y, s32 width, s32 height, u8 striped) {
    extern s32 gCur3DSpriteEngine;
    extern void *gCurrentMap;
    void DrawFrameTiles(s32, s32, s32, s32, s32, s32, u8);
    void (*callback)(void);
    DrawFrameTiles(x, y, width, height, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_LAYER2_TILES), 3, striped);
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), 0x48);
    if (callback) callback();
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
}

/* Clear the map view's unit and terrain sprite layers, mark both dirty so they
 * upload again, then run the view controller's presentation-setup callback. */
void ResetMapViewLayers(void) {
    extern s32 gCur3DSpriteEngine;
    extern void *gCurrentMap;
    void (*callback)(void);

    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER2;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), MAPVIEW_INIT_PRESENTATION);
    if (callback) callback();
}

/* Load player `player`'s army colour palette into the battle map's OBJ palette
 * slot at 0x160. */
void LoadPlayerArmyPalette(s32 player) {
    extern u8 gArmyPalettes[];
    extern void *gCurrentMap;

    CopyToObjPaletteShadow(gArmyPalettes + ((M2C_FIELD(player * MAP_PLAYER_STRIDE + M2C_FIELD(gCurrentMap, s32 *, 0), u8 *, PLAYER_ARMY_INDEX_OFF) + 3) << 5), 0x160, 0x20);
}

void LoadUiGraphicsBlock(M2C_UNK arg0) {
    M2C_UNK LoadGraphicsBlock(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0211e0a8;
    LoadGraphicsBlock(&data_0211e0a8, arg0);
}

void LoadUiSpritePalette(s32 arg0) {
    M2C_UNK CopyToObjPaletteShadow(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gUiSpritePalette;
    CopyToObjPaletteShadow(&gUiSpritePalette, arg0 << 5, 0x20);
}

/* Load the UI graphics into one 3D sprite engine layer: put the UI tile block at
 * the layer's VRAM address, copy the UI sprite palette into palette slot 3, load
 * scene panel palette 0 and queue the UI pattern in its colour. */
void LoadUiLayerGraphics(s32 layer) {
    M2C_UNK Load3DSpritePattern(M2C_UNK, M2C_UNK, s32, M2C_UNK);
    M2C_UNK LoadScenePanelPalette(M2C_UNK);
    s32 GetUiColor(M2C_UNK);
    extern s32 gCur3DSpriteEngine;
    LoadUiGraphicsBlock(M2C_FIELD((gCur3DSpriteEngine + (layer * 4)), s32 *, 0xC));
    LoadUiSpritePalette(3);
    LoadScenePanelPalette(0);
    Load3DSpritePattern(0x1000, 1, GetUiColor(9), 2);
}

void LoadUiGraphics(void) {
    LoadUiLayerGraphics(2);
}

/* Clear the carried-unit menu-state stack and point its cursor at the base. */
void ResetCarriedUnitMenuStack(void) {
CarriedUnitMenuState *state=(CarriedUnitMenuState *)gCarriedUnitMenuStateStack; s32 i;
gCarriedUnitMenuStackPtr=state;
for(i=0;i<8;i++){state[i].x=0;state[i].y=0;state[i].selection=0;state[i].width=0;state[i].entries=0;}
}

/* Saves the current carried-unit list menu onto the menu-state stack: copies its
 * entry table, chosen row, position and width into the next free 8-byte state and
 * advances the stack cursor by one.  Does nothing when no menu is open. */
void PushCarriedUnitMenuState(void) {
    MenuC0634 *menu = (MenuC0634 *)GetCarriedUnitMenu();

    if (menu == NULL) return;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s32 *, 4) = menu->entries;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s8 *, 2) = menu->selection;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s8 *, 0) = menu->x;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s8 *, 1) = menu->y;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s8 *, 3) = menu->width;
    gCarriedUnitMenuStackPtr += 8;
}

#pragma opt_instruction_scheduling off
void PopCarriedUnitMenuState(void) {
M2C_UNK func_020c0634(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);
if(gCarriedUnitMenuStackPtr==gCarriedUnitMenuStateStack)return;
gCarriedUnitMenuStackPtr-=8;
func_020c0634(M2C_FIELD(gCarriedUnitMenuStackPtr,s32 *,4),M2C_FIELD(gCarriedUnitMenuStackPtr,s8 *,0),M2C_FIELD(gCarriedUnitMenuStackPtr,s8 *,1),M2C_FIELD(gCarriedUnitMenuStackPtr,s8 *,2),M2C_FIELD(gCarriedUnitMenuStackPtr,s8 *,3));
}
#pragma opt_instruction_scheduling reset
void func_020c0b88(s8 arg0) {
    extern void *gCarriedUnitMenuStackPtr;
    M2C_FIELD(gCarriedUnitMenuStackPtr, s8 *, 2) = arg0;
}

s8 GetCarriedUnitMenuSelection(void) {extern void *gCarriedUnitMenuStackPtr;return M2C_FIELD(gCarriedUnitMenuStackPtr,s8 *,2);}

/* Draws the cargo list of the unit under the cursor: one row per carried-unit
 * slot (the row's +0x24 slot, 0xFFFF when empty), with the carried unit's icon
 * and, when that unit is damaged, the number of health bars it has left. */
void DrawCarriedUnitList(void *list) {
M2C_UNK DrawCarriedUnitIcon(u16,u16,u16,M2C_UNK,s32);
M2C_UNK DrawDecimalNumber(s32,s32,s32);
s32 GetUnitHealthBarCount(s32);
extern void *gCurrentMap;
s32 row=0,x,y,bars;s32 rowOffset;void *entry,*map;u16 slot;u8 carriedId;
if((s32)M2C_FIELD(list,u8 *,0x4d)<=0)return;
rowOffset=0;
do{
entry=(void *)GetCarriedUnitListEntry(list,row);slot=M2C_FIELD(entry,u16 *,0x24);
if(slot!=0xffff){
x=M2C_FIELD(list,s16 *,0x54);y=M2C_FIELD(list,s16 *,0x56)+((u32)rowOffset<<3);
DrawCarriedUnitIcon(slot,(u16)(x+2),(u16)y,0,11);
slot=M2C_FIELD(entry,u16 *,0x24);
if((slot!=0)&&(slot!=1)){}else{map=*(void **)gCurrentMap;carriedId=M2C_FIELD(M2C_FIELD(map,s32 *,0x52d0)+slot,u8 *,12);
if(carriedId){bars=GetUnitHealthBarCount((s32)map+0x59a4+carriedId*14);if(bars!=10)DrawDecimalNumber(x+9,y+7,bars);}
}}
row++;rowOffset+=2;
}while(row<(s32)M2C_FIELD(list,u8 *,0x4d));
}

/* D-pad handler for the carried-unit list: moves the selected row up or down,
 * wrapping round at the ends only on a fresh press, keeps the sprite-slot focus
 * on it, then confirms the row (A) or cancels the menu (B). */
void HandleCarriedUnitListInput(void *arg0, u8 *selection) {
    extern void *gKeyState;
    MenuC0634 *list = (MenuC0634 *)arg0;
    s32 old = *selection;
    s32 value = old;
    u16 keys = M2C_FIELD(gKeyState, u16 *, 2);

    if (keys & KEY_UP) {
        if (old == 0) {
            if (keys != M2C_FIELD(gKeyState, u16 *, 0)) return;
            value = list->count;
        }
        value--;
    } else if (keys & KEY_DOWN) {
        if (old == list->count - 1) {
            if (keys != M2C_FIELD(gKeyState, u16 *, 0)) return;
            value = -1;
        }
        value++;
    }
    if (value != old) {
        FocusSpriteSlotById(value);
        list->selection = value;
    } else if (M2C_FIELD(gKeyState, u16 *, 0) & KEY_A) {
        InvokeConfirmCallback(selection);
    } else if (M2C_FIELD(gKeyState, u16 *, 0) & KEY_B) {
        InvokeCancelCallback();
    }
}

void func_020c0d50(void *arg0) {
    void HandleCarriedUnitListInput(void *, u8 *);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x10);
    if (IsCarriedUnitListOpen() == 0) {
        return;
    }
    HandleCarriedUnitListInput(temp_r4, arg0);
}

/* Click handler for a carried-unit list row (a sprite slot whose id is the row
 * and whose owner is the menu): ignore it when the list has closed or a map
 * event's condition rejects the carried unit, buzz on a row that cannot be
 * picked, else play the confirm sound and run the row's action. */
s32 ClickCarriedUnitRow(void *slot) {
s32 RunUnitEvent(u8,s32);
u8 index=M2C_FIELD(slot,u8 *,SPRITE_SLOT_ID); MenuC0634 *list=M2C_FIELD(slot,MenuC0634 **,SPRITE_SLOT_OWNER);
if(!IsCarriedUnitListOpen())return 0;
if(RunUnitEvent(M2C_FIELD(GetCarriedUnitListEntry(list,index),u8 *,0),0))return 0;
if(list->status[index]==1)PlaySoundEffect(0x1001d);
else {PlaySoundEffect(0x10016);RunCarriedUnitRowAction(list,index);}
return 1;
}

s32 func_020c0df8(void *arg0) {
u8 index=M2C_FIELD(arg0,u8 *,0); void *p=M2C_FIELD(arg0,void **,0x10);
if(!IsCarriedUnitListOpen())return 0;
func_0209bfa8();PlaySoundEffect(0x10018);func_020c04b4(p,index);return 1;
}

void func_020c0e38(void *arg0) {
u8 index=M2C_FIELD(arg0,u8 *,0); void *p=M2C_FIELD(arg0,void **,0x10);
if(!IsCarriedUnitListOpen())return;
PlaySoundEffect(0x10019); HighlightListMenuRow(p,index);
}

void func_020c0e6c(void *arg0) {
u8 index = M2C_FIELD(arg0,u8 *,0);
void *p = M2C_FIELD(arg0,void **,0x10);
if (!IsCarriedUnitListOpen()) return;
func_020c0454(p,index);
}

/* Create one sprite slot per visible row of the carried-unit list: stack them
 * down the panel by each row graphic's height and record the list as their
 * owner, then put the focus frame on the selected row. */
M2C_UNK CreateCarriedUnitRowSlots(void *p) {
extern M2C_UNK gCarriedUnitRowSlotDef;
void *AddSpriteSlot(s32,s32,M2C_UNK *,s32);
s32 GetBatchSpriteSourceWidth(s32); s32 GetBatchSpriteSourceHeight(s32);
M2C_UNK FocusSpriteSlotById(); M2C_UNK SetSpriteSlotFrameToFocus();
s32 i,y; y=0; i=y;
for(;i<M2C_FIELD(p,u8 *,0x4d);i++) {
void *slot=AddSpriteSlot(M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56)+y*8,&gCarriedUnitRowSlotDef,i);
s32 w=GetBatchSpriteSourceWidth(i);
s32 h=GetBatchSpriteSourceHeight(i);
M2C_FIELD(slot,s16 *,SPRITE_SLOT_W)=w;M2C_FIELD(slot,s16 *,SPRITE_SLOT_H)=h;
M2C_FIELD(slot,void **,SPRITE_SLOT_OWNER)=p;y+=h>>3;
}
FocusSpriteSlotById(M2C_FIELD(p,u8 *,0x4e));SetSpriteSlotFrameToFocus();
}

void CloseCarriedUnitListSprites(void) {
    M2C_UNK CloseAllActiveSpriteSlots();
    CloseAllActiveSpriteSlots();
}

/* Draw the carried-unit list menu: add one sprite-batch cell per visible row
 * (its icon kind and status byte), then draw the finished batch at the menu's
 * screen position. */
M2C_UNK DrawCarriedUnitListBatch(void *p) {
extern u8 data_02163f30[];
void SetCurrentSpriteBatch(void *);void InitSpriteBatch(s32,s32,s32,s32);
void AddSpriteToBatch(u8,u8);void LoadSpriteBatchGraphics(void);void DrawSpriteBatchAt(s32,s32);
MenuC0634 *list=(MenuC0634 *)p;
s32 i;u16 icon;
SetCurrentSpriteBatch(data_02163f30);
InitSpriteBatch(2,1,0x24,3);
for(i=0;i<list->count;i++) {
icon=((MenuRowC0634 *)GetCarriedUnitListEntry(p,i))->icon;
AddSpriteToBatch((u8)icon,(u8)GetCarriedUnitListEntryStatus((s32)p,i));
}
LoadSpriteBatchGraphics();
DrawSpriteBatchAt(list->x,list->y);
}

/* Creates the fixed-geometry unit sprite a menu shows (style 2, size 0x120, kind
 * 3), positions it at (0xe0, 0xa0) with a 0x100 x 0xa0 box, and, when it has a
 * visible entry, sets that entry's cell rectangle. Returns the new sprite. */
void *CreateMenuUnitSprite(void *owner) {
void *func_020ab1c4(s32);
void InitUnitSprite(void *,s32,s32,s32,s32);
void Set3DSpriteSlideTargetAndStart(void *,s16,s16,s16,s32);
u32 GetUnitSpriteWidth(void *); u32 GetUnitSpriteHeight(void *);
void func_02087d84(void *,s32,s32,s32,u16,u16);
void CreateUnitSpriteButtonTask(void *,s16); void func_020aad18(void *);void Show3DSpriteSlide(void *);
void *unit; s16 y; s16 x; u32 width,height; u32 visible;
unit=func_020ab1c4((s32)owner);
InitUnitSprite(unit,2,0x120,3,1);
Set3DSpriteSlideTargetAndStart(unit,0xe0,0xa0,0x100,0xa0);
visible=M2C_FIELD(M2C_FIELD(unit,void **,0x64),u8 *,0x12)!=0?1:0;
if(visible & 0xff){
y=M2C_FIELD(unit,s16 *,0x52);x=M2C_FIELD(unit,s16 *,0x50);
width=GetUnitSpriteWidth(unit);height=GetUnitSpriteHeight(unit);
func_02087d84(M2C_FIELD(unit,void **,0x64),1,x,y,(u16)width,(u16)height);
}
CreateUnitSpriteButtonTask(unit,2);func_020aad18(unit);Show3DSpriteSlide(unit);return unit;
}

void RefreshPlayerColorIndices(void) {
    s8 GetPlayerIdForSlot(s32);
    extern s8 gPlayerColorIndex;
    s32 var_r4;
    s8 *var_r5;
    s8 temp_r0;

    var_r5 = &gPlayerColorIndex;
    var_r4 = 0;
    do {
        temp_r0 = GetPlayerIdForSlot(var_r4);
        var_r4 += 1;
        *var_r5 = temp_r0;
        var_r5 += 1;
    } while (var_r4 < 5);
}

#pragma push
#pragma opt_strength_reduction off
void *func_020c10a4(s32 x,s32 y,s32 flag){
extern void *data_027e0058;extern u8 data_02163f9c[];extern s8 data_0216408c;extern u16 data_02129728[],data_021296e8[],data_0211e538[];
MapC10 *p;u32 idx; s32 k,n,v;u8 *tiles;
if(x>=0 && y>=0){p=*(void **)data_027e0058;if(x<p->width&&y<p->height)goto valid;}
return data_02163f9c;
valid:
tiles=p->tiles;
idx=x+p->rows[y];
v=*(tiles+idx);
n=v&31;k=((u8 *)&data_0216408c)[v>>5];
if(flag && (u8)(p->visible[idx>>3]&(1<<(idx&7)))==0){if(n!=15)k=0;}
v=data_02129728[n];
if(n==27 || (u32)n==28)k=0;
return &data_0211e538[data_021296e8[v+k]];
}
#pragma pop
void func_020c1184(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
}

void func_020c1190(void) {

}

/* Per-frame step of one map-preview layer sprite: advance its 64-frame counter and,
 * on the frames that ask for them, copy the map's top half, then its bottom half,
 * then stamp the visible units' markers into the layer's VRAM. */
void UpdateMapPreviewLayer(void *sprite) {
    M2C_UNK DrawMapUnitMarkers(s32);
    M2C_UNK CopyMapPreviewTopHalf(s32);
    M2C_UNK CopyMapPreviewBottomHalf(s32);
    s16 frame;
    s32 step;

    frame = M2C_FIELD(sprite, s16 *, MAP_PREVIEW_SPRITE_FRAME);
    M2C_FIELD(sprite, s16 *, MAP_PREVIEW_SPRITE_FRAME) = (s16) (frame + 1);
    step = frame & MAP_PREVIEW_FRAME_MASK;
    switch (step) {                              /* irregular */
    case MAP_PREVIEW_FRAME_TOP:
        CopyMapPreviewTopHalf(M2C_FIELD(sprite, s32 *, MAP_PREVIEW_SPRITE_VRAM));
        return;
    case MAP_PREVIEW_FRAME_BOTTOM:
        CopyMapPreviewBottomHalf(M2C_FIELD(sprite, s32 *, MAP_PREVIEW_SPRITE_VRAM));
        return;
    case MAP_PREVIEW_FRAME_UNITS:
        DrawMapUnitMarkers(M2C_FIELD(sprite, s32 *, MAP_PREVIEW_SPRITE_VRAM));
        return;
    }
}

s32 CreateMapPreviewLayerSprite(s32 a) {
extern M2C_UNK data_02129690;
s32 FindObjectByClass(M2C_UNK *);
M2C_UNK CreateSpriteFromClass(M2C_UNK *,M2C_UNK);
void *p;
if(FindObjectByClass(&data_02129690))return 0;
p=(void *)CreateSpriteFromClass(&data_02129690,7);
M2C_FIELD(p,s32 *,0x34)=a;
return 1;
}

void func_020c121c(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_02129690;
    DeleteSpriteObjectsOfClass(&data_02129690);
}

