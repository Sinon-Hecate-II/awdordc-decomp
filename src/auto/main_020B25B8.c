/* 24 functions from 0x020B25B8 to 0x020B34F8 (main), found by ds-decomp. */
#include "common.h"
#include "sprite_slot.h"
#include "ds3dsprite.h"
#include "sprite_grid.h"

/* Draw the touchable sprite slots of the screen named in the slot manager (the
   main or the sub engine, or whichever engine is current when it says either):
   for each screen point gCur3DSpriteEngine at its engine, emit every active
   slot's sprite, then let the engine draw.  The previous engine is restored at
   the end, and nothing is drawn while the slot manager is paused. */
void DrawSpriteSlots(void){
u8 func_020b2714(void);void DrawSpriteSlotSprite(void*);
extern u16 **gCur3DSpriteEngine;extern void *g3DSpriteEngineMain,*g3DSpriteEngineSub,*gSpriteSlotManager;extern u8 gSpriteSlots[];
void *old,*p;u8 mode;s32 j,i;u8 *q;
if(func_020b2714())return;
old=gCur3DSpriteEngine;
i=0;do{
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
mode=M2C_FIELD(gSpriteSlotManager,u8*,SPRITE_SLOT_MGR_SCREEN);
if((mode!=DS3D_TARGET_MAIN||p==g3DSpriteEngineMain)&&(mode!=DS3D_TARGET_SUB||p==g3DSpriteEngineSub)&&(mode!=DS3D_TARGET_ACTIVE||p==old)){
j=0;q=gSpriteSlots;
do{if(q[SPRITE_SLOT_VISIBLE])DrawSpriteSlotSprite(q);j++;q+=SPRITE_SLOT_STRIDE;}while(j<SPRITE_SLOT_COUNT);
func_020b1d84();
}
i++;}while(i<2);
gCur3DSpriteEngine=old;
}

void func_020b269c(void) {
    extern void *gSpriteSlotManager;
    M2C_FIELD(gSpriteSlotManager, u8 *, 0x26) = (u8) (M2C_FIELD(gSpriteSlotManager, u8 *, 0x26) + 1);
}

u8 func_020b26b8(void) {
extern void *gSpriteSlotManager;
return M2C_FIELD(gSpriteSlotManager,u8 *,0x26)!=0;
}

void func_020b26dc(void) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,u8 *,0x26)-=1;
}

void func_020b26f8(void) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,u8 *,0x27)+=1;
}

u8 func_020b2714(void) {
extern void *gSpriteSlotManager;
return M2C_FIELD(gSpriteSlotManager,u8 *,0x27)!=0;
}

void func_020b2738(void) {
extern void *gSpriteSlotManager;
M2C_FIELD(gSpriteSlotManager,u8 *,0x27)-=1;
}

s32 SpriteSlotHitTest(void *arg0, s32 arg1, s32 arg2) {
    s32 SpriteSlotHasFlags(void *, M2C_UNK);
    s16 temp_r1;
    s16 temp_r1_2;

    if (SpriteSlotHasFlags(arg0, 0x1000) != 0) {
        return 1;
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x14);
    if ((arg1 < (s32) temp_r1) || ((s32) ((temp_r1 + M2C_FIELD(arg0, s16 *, 0x18)) - 1) < arg1)) {
        return 0;
    }
    temp_r1_2 = M2C_FIELD(arg0, s16 *, 0x16);
    if ((arg2 < (s32) temp_r1_2) || ((s32) ((temp_r1_2 + M2C_FIELD(arg0, s16 *, 0x1A)) - 1) < arg2)) {
        return 0;
    }
    return 1;
}

/* Give keyboard focus to the touchable sprite slot under the current touch, if
 * the slot may take it: no dialog is up, the touch is down, and the slot is
 * enabled, hit by the touch, not already focused and not disabled.  Returns 1
 * when the slot was focused. */
s32 TryFocusSpriteSlot(void *slot) {
    extern void *gTouchState, *gSpriteSlotManager;
    s32 IsDialogActive(void);
    s32 SpriteSlotHasFlags(void *, M2C_UNK);
    void FocusSpriteSlot(void *);
    u16 touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    u16 touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);

    if (IsDialogActive()) return 0;
    if (!M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE)) return 0;
    if (!SpriteSlotHasFlags(slot, SPRITE_SLOT_FLAG_ENABLED)) return 0;
    if (!SpriteSlotHitTest(slot, touchX, touchY)) return 0;
    if (M2C_FIELD(gSpriteSlotManager, void **, SPRITE_SLOT_MGR_FOCUS) == slot) return 0;
    if (SpriteSlotHasFlags(slot, SPRITE_SLOT_FLAG_DISABLED)) return 0;
    FocusSpriteSlot(slot);
    return 1;
}

/* Touch handler for one sprite-button slot.  Its state machine reaches
 * SPRITE_SLOT_PRESSED on a touch that starts inside the slot, becomes
 * SPRITE_SLOT_DRAGGED once the touch is held past TOUCH_DRAG_FRAMES, and returns
 * to idle whenever the finger leaves or lifts.  A release inside the slot that
 * did not drag (and with no dialog up) fires the slot's callback and returns 1. */
s32 HandleSpriteSlotTouch(void *slot) {
extern void *gTouchState;
s32 IsDialogActive(void);s32 SpriteSlotHasFlags(void *,M2C_UNK);
void SetSpriteSlotState(void *,M2C_UNK);void FocusSpriteSlot(void *);
s32 GetSpriteSlotState(void *);s32 SpriteSlotHitTest(void *,s32,s32);
s32 touchX=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_X),touchY=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_Y);
s32 touchStartX=M2C_FIELD(gTouchState,u16 *,TOUCH_START_X),touchStartY=M2C_FIELD(gTouchState,u16 *,TOUCH_START_Y);
s32 drag;void (*callback)(void *);
switch(GetSpriteSlotState(slot)){
case SPRITE_SLOT_DRAGGED:
if(!SpriteSlotHitTest(slot,touchX,touchY)){SetSpriteSlotState(slot,SPRITE_SLOT_IDLE);break;}
if(M2C_FIELD(gTouchState,u8 *,TOUCH_RELEASED))SetSpriteSlotState(slot,SPRITE_SLOT_IDLE);
break;
case SPRITE_SLOT_IDLE:
if(M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED)&&SpriteSlotHitTest(slot,touchX,touchY)==1)SetSpriteSlotState(slot,SPRITE_SLOT_PRESSED);
break;
case SPRITE_SLOT_PRESSED:
if(!SpriteSlotHitTest(slot,touchX,touchY)){SetSpriteSlotState(slot,SPRITE_SLOT_IDLE);break;}
if(M2C_FIELD(gTouchState,u8 *,TOUCH_RELEASED)){
SetSpriteSlotState(slot,SPRITE_SLOT_IDLE);
if(SpriteSlotHasFlags(slot,0x400))return 0;
if(IsDialogActive())return 0;
if(SpriteSlotHasFlags(slot,1))FocusSpriteSlot(slot);
if((drag=touchX-touchStartX,drag<0?-drag:drag)>0x10||(drag=touchY-touchStartY,drag<0?-drag:drag)>0x10)return 0;
callback=M2C_FIELD(slot,void (**)(void *),0x2c);
if(callback)callback(slot);
return 1;
}
if(M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE)&&M2C_FIELD(gTouchState,u8 *,TOUCH_HOLD_FRAMES)==TOUCH_DRAG_FRAMES)SetSpriteSlotState(slot,SPRITE_SLOT_DRAGGED);
break;
}
return 0;
}

/* Updates animated scrolling/panning state and interpolates position using easing */
void AnimateSpriteSlot(void *context) {
    s32 SpriteSlotHasFlags(void *, s32);
    s16 EaseInterpolate(s32, s16, s16, s32, s32);
    void (*callback)(void *);
    s16 timer;
    u16 duration;

    switch (M2C_FIELD(context, u8 *, 4)) {
    case 0:
        M2C_FIELD(context, u8 *, 4) = 1;
        M2C_FIELD(context, u16 *, 0xE) = 0;
        if (SpriteSlotHasFlags(context, 4) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = (s16)(0 - M2C_FIELD(context, s16 *, 0x18));
        }
        if (SpriteSlotHasFlags(context, 8) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = 0x100;
        }
        if (SpriteSlotHasFlags(context, 0x10) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 8) = (s16)(0 - M2C_FIELD(context, s16 *, 0x1A));
        }
        if (SpriteSlotHasFlags(context, 0x20) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 8) = 0xC0;
        }
        if ((s16)M2C_FIELD(context, u16 *, 0xE) == 0) {
            return;
        }
        break;
    case 3:
        M2C_FIELD(context, u8 *, 4) = 4;
        M2C_FIELD(context, u16 *, 0xE) = 0;
        if (SpriteSlotHasFlags(context, 0x40) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 8) = M2C_FIELD(context, s16 *, 0x16);
            M2C_FIELD(context, s16 *, 0xA) = (s16)(0 - M2C_FIELD(context, s16 *, 0x18));
            M2C_FIELD(context, s16 *, 0xC) = M2C_FIELD(context, s16 *, 0x16);
        }
        if (SpriteSlotHasFlags(context, 0x80) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 8) = M2C_FIELD(context, s16 *, 0x16);
            M2C_FIELD(context, s16 *, 0xA) = 0x100;
            M2C_FIELD(context, s16 *, 0xC) = M2C_FIELD(context, s16 *, 0x16);
        }
        if (SpriteSlotHasFlags(context, 0x100) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 8) = M2C_FIELD(context, s16 *, 0x16);
            M2C_FIELD(context, s16 *, 0xA) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 0xC) = (s16)(0 - M2C_FIELD(context, s16 *, 0x1A));
        }
        if (SpriteSlotHasFlags(context, 0x200) != 0) {
            M2C_FIELD(context, u16 *, 0xE) = M2C_FIELD(context, u16 *, 0x1E);
            M2C_FIELD(context, s16 *, 6) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 8) = M2C_FIELD(context, s16 *, 0x16);
            M2C_FIELD(context, s16 *, 0xA) = M2C_FIELD(context, s16 *, 0x14);
            M2C_FIELD(context, s16 *, 0xC) = 0xC0;
        }
        if ((s16)M2C_FIELD(context, u16 *, 0xE) == 0) {
            return;
        }
        break;
    default:
        break;
    }

    switch (M2C_FIELD(context, u8 *, 4)) {
    case 1:
        timer = (s16)M2C_FIELD(context, u16 *, 0xE);
        if (timer > 0) {
            M2C_FIELD(context, u16 *, 0xE) = (u16)(timer - 1);
        } else {
            M2C_FIELD(context, u16 *, 0xE) = 0;
            M2C_FIELD(context, u8 *, 4) = 2;
        }
        duration = M2C_FIELD(context, u16 *, 0x1E);
        M2C_FIELD(context, s16 *, 0x14) = EaseInterpolate(5, M2C_FIELD(context, s16 *, 6),
            M2C_FIELD(context, s16 *, 0xA), duration - (s16)M2C_FIELD(context, u16 *, 0xE), (s32)duration);
        duration = M2C_FIELD(context, u16 *, 0x1E);
        M2C_FIELD(context, s16 *, 0x16) = EaseInterpolate(5, M2C_FIELD(context, s16 *, 8),
            M2C_FIELD(context, s16 *, 0xC), duration - (s16)M2C_FIELD(context, u16 *, 0xE), (s32)duration);
        return;
    case 4:
        timer = (s16)M2C_FIELD(context, u16 *, 0xE);
        if (timer <= 0) {
            M2C_FIELD(context, u16 *, 0xE) = 0;
            M2C_FIELD(context, u8 *, 4) = 5;
            callback = M2C_FIELD(context, void (**)(void *), 0x38);
            if (callback != NULL) {
                callback(context);
            }
        } else {
            M2C_FIELD(context, u16 *, 0xE) = (u16)(timer - 1);
        }
        duration = M2C_FIELD(context, u16 *, 0x1E);
        M2C_FIELD(context, s16 *, 0x14) = EaseInterpolate(2, M2C_FIELD(context, s16 *, 6),
            M2C_FIELD(context, s16 *, 0xA), duration - (s16)M2C_FIELD(context, u16 *, 0xE), (s32)duration);
        duration = M2C_FIELD(context, u16 *, 0x1E);
        M2C_FIELD(context, s16 *, 0x16) = EaseInterpolate(2, M2C_FIELD(context, s16 *, 8),
            M2C_FIELD(context, s16 *, 0xC), duration - (s16)M2C_FIELD(context, u16 *, 0xE), (s32)duration);
        return;
    }
}

/* Emit the OAM sprite of a touchable slot: its position (clipped to the OAM
   field widths) with the disabled flag, and its tile from the slot's 3D-sprite
   bank plus its priority, into the current 3D sprite engine. */
void DrawSpriteSlotSprite(void *slot) {
M2C_UNK func_01ff883c(u16,u16,u16,s32);
s32 GetSpriteDescForSize(s16,s16);
extern u16 **gCur3DSpriteEngine;
u32 tile,prio; s16 w,h; s32 flag;
tile=M2C_FIELD(slot,u16 *,SPRITE_SLOT_TILE); prio=M2C_FIELD(slot,u16 *,SPRITE_SLOT_PRIORITY);
w=M2C_FIELD(slot,s16 *,SPRITE_SLOT_W); h=M2C_FIELD(slot,s16 *,SPRITE_SLOT_H); flag=0;
if(!SpriteSlotHasFlags(slot,2))return;
if(SpriteSlotHasFlags(slot,0x800))flag=0x400;
func_01ff883c((u16)(M2C_FIELD(slot,s16 *,SPRITE_SLOT_X)&0x1ff),(u16)((M2C_FIELD(slot,s16 *,SPRITE_SLOT_Y)&0xff)|flag),(u16)((0x3ff&(tile>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|((prio<<28)>>16)),GetSpriteDescForSize(w,h));
}

void InvokeConfirmCallback(void *p) {
void (*cb)(void *)=M2C_FIELD(p,void (**)(void *),0x2c);
if(!cb)return;cb(p);
}

void InvokeCancelCallback(void) {
s32 func_020b1bb0(void);
extern void *gSpriteSlotManager;
void *p; void (*cb)(void *);
if(!func_020b1bb0())return;
p=M2C_FIELD(gSpriteSlotManager,void **,0xc);
cb=M2C_FIELD(p,void (**)(void *),0x30);
if(!cb)return; cb(p);
}

void func_020b2e60(void *p) {
void (*cb)(void *)=M2C_FIELD(p,void (**)(void *),0x34);
if(!cb)return;cb(p);
}

s32 func_020b2e78(s32 x,s32 y,void *p) {
s16 a=M2C_FIELD(p,s16 *,0),b;
if(a<=x && (b=M2C_FIELD(p,s16 *,2))<=y) {
if(a+M2C_FIELD(p,s16 *,4)>=x && b+M2C_FIELD(p,s16 *,6)>=y)return 1;
}
return 0;
}

/* Builds the scrolling sprite grid widget in `grid`: a rows x columns raster of
 * cells, each cellWidth x cellHeight pixels, the first at (baseX, baseY), with
 * the cell's tile index running down the columns.  The cell block is allocated
 * and cleared here; the caller sets the item count and fills the cells. */
void *CreateSpriteGrid(void *grid, u8 rows, u8 columns, u8 cellWidth, u8 cellHeight, u8 baseX, u8 baseY) {
void MI_CpuFill8(void *,s32,u32);
void AddSpriteCell(void *,s16,s16,u32,u32,u32,u32);
void *HeapAllocBlock(u32);
extern u32 gSpriteGridVTable[];
s32 cellsSize,cellCount; u8 row; u8 col; u32 rasterRows=rows,leftX=baseX,topY; void *cells;
M2C_FIELD(grid,void **,SPRITE_GRID_VTABLE)=gSpriteGridVTable;
M2C_FIELD(grid,u8 *,SPRITE_GRID_ROWS)=rasterRows;
M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS)=columns;
M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_WIDTH)=cellWidth;
M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_HEIGHT)=cellHeight;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)=0;
M2C_FIELD(grid,s16 *,SPRITE_GRID_ITEM_COUNT)=0;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=0;
M2C_FIELD(grid,s16 *,14)=-32768;
M2C_FIELD(grid,s16 *,16)=-32768;
cellCount=rasterRows*columns;cellsSize=cellCount*12;
M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)=0;
M2C_FIELD(grid,s16 *,SPRITE_GRID_BASE_X)=leftX;
M2C_FIELD(grid,s16 *,SPRITE_GRID_BASE_Y)=baseY;
M2C_FIELD(grid,u16 *,SPRITE_GRID_CELLS+SPRITE_CELL_LIST_CAPACITY)=cellCount;
M2C_FIELD(grid,u8 *,SPRITE_GRID_CELLS+SPRITE_CELL_LIST_USED)=0;
M2C_FIELD(grid,u32 *,24)=0;
topY=baseY;
M2C_FIELD(grid,u32 *,28)=0;
M2C_FIELD(grid,s8 *,32)=-1;
M2C_FIELD(grid,s8 *,33)=-1;
M2C_FIELD(grid,s8 *,34)=-1;
M2C_FIELD(grid,s8 *,35)=-1;
M2C_FIELD(grid,u8 *,37)=255;
M2C_FIELD(grid,s8 *,36)=-1;
M2C_FIELD(grid,u8 *,38)=0;
M2C_FIELD(grid,u8 *,39)=255;
cells=HeapAllocBlock(cellsSize);M2C_FIELD(grid,void **,SPRITE_GRID_CELLS+SPRITE_CELL_LIST_CELLS)=cells;
MI_CpuFill8(M2C_FIELD(grid,void **,SPRITE_GRID_CELLS+SPRITE_CELL_LIST_CELLS),0,cellsSize);
for(row=0;row<rasterRows;row=(u8)(row+1))for(col=0;col<columns;col++)AddSpriteCell((u8*)grid+SPRITE_GRID_CELLS,(s16)(col*cellWidth+leftX),(s16)(row*cellHeight+topY),cellWidth,cellHeight,(u16)(col+row*columns),14);
return grid;
}

#pragma opt_common_subs off
void ScrollSpriteGridToItem(void *arg0, s32 arg1) {
    M2C_UNK Divide();
    s32 step, r9, r8c, r8const;
    s32 r8, orig_a;
    s16 visible, fres;
    s32 c, f, cur, diff;
    s16 orig_c;
    void *grid = arg0;
    s32 item = arg1;

    if (item == M2C_FIELD(grid, s16 *, 0x8)) {
        return;
    }
    step = M2C_FIELD(grid, u8 *, 0x5);
    orig_a = M2C_FIELD(grid, s16 *, 0xA);
    r8 = M2C_FIELD(grid, u8 *, 0x4);
    fres = (s16) Divide(orig_a + step - 1, step);
    orig_c = M2C_FIELD(grid, s16 *, 0xC);
    if (item < 0) {
        return;
    }
    if (orig_a <= item) {
        return;
    }
    visible = (s16) ((fres <= r8) ? fres : r8);
    if (item < M2C_FIELD(grid, s16 *, 0x8)) {
        do {
            M2C_FIELD(grid, s16 *, 0x8) = (s16) (M2C_FIELD(grid, s16 *, 0x8) - 1);
            orig_a = M2C_FIELD(grid, s16 *, 0xC);
            f = Divide(M2C_FIELD(grid, s16 *, 0x8), step);
            diff = (s16) (f - orig_a);
            if (diff < 0) {
                if (orig_a > 0) {
                    M2C_FIELD(grid, s16 *, 0xC) = (s16) (M2C_FIELD(grid, s16 *, 0xC) - 1);
                }
            }
        } while (item < M2C_FIELD(grid, s16 *, 0x8));
    } else {
        orig_a--;
        r8c = visible;
        r9 = fres - r8c;
        r8const = r8c - 1;
        do {
            M2C_FIELD(grid, s16 *, 0x8) = (s16) (M2C_FIELD(grid, s16 *, 0x8) + 1);
            cur = M2C_FIELD(grid, s16 *, 0x8);
            if ((s32) cur > orig_a) {
                cur = orig_a;
            }
            M2C_FIELD(grid, s16 *, 0x8) = cur;
            f = (s16) Divide(M2C_FIELD(grid, s16 *, 0x8), step);
            c = M2C_FIELD(grid, s16 *, 0xC);
            diff = f - c;
            if (diff > r8const) {
                if (c < r9) {
                    M2C_FIELD(grid, s16 *, 0xC) = c + 1;
                }
            }
        } while (M2C_FIELD(grid, s16 *, 0x8) < item);
    }
    M2C_FIELD(grid, s16 *, 0x12) = (s16) ((M2C_FIELD(grid, s16 *, 0xC) - orig_c) * M2C_FIELD(grid, u8 *, 0x7));
}
#pragma opt_common_subs reset
/* Eases the sprite grid's animated pixel offset back to zero: a whole cell
 * height per frame while it is at least that far from zero, a quarter of one
 * once closer, without crossing zero.  Returns the remaining offset. */
s16 UpdateSpriteGridPixelOffset(void *grid) {
    s16 offset;
    u8 cellHeight;

    cellHeight = M2C_FIELD(grid, u8 *, SPRITE_GRID_CELL_HEIGHT);
    offset = M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET);
    if ((s32) offset < (s32) (0 - cellHeight)) {
        M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = (s16) (offset + cellHeight);
        if ((s32) M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) > 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = 0;
        }
    } else if ((s32) offset < 0) {
        M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = (s16) (offset + ((s32) cellHeight >> 2));
        if ((s32) M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) > 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = 0;
        }
    } else if ((s32) offset > (s32) cellHeight) {
        M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = (s16) (offset - cellHeight);
        if ((s32) M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) < 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = 0;
        }
    } else if ((s32) offset > 0) {
        M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = (s16) (offset - ((s32) cellHeight >> 2));
        if ((s32) M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) < 0) {
            M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET) = 0;
        }
    }
    return M2C_FIELD(grid, s16 *, SPRITE_GRID_PIXEL_OFFSET);
}

u8 func_020b320c(void *p) {
s32 Divide(s32);
s32 step=M2C_FIELD(p,volatile u8 *,5);
s32 a=M2C_FIELD(p,u8 *,4);
s16 b=Divide(M2C_FIELD(p,s16 *,0xa)+step-1);
if(a>=b)a=b;
return M2C_FIELD(p,s16 *,0xc)+(s16)a<b;
}

u8 func_020b325c(void *arg0) {
M2C_UNK Divide();
u8 value; s32 step=M2C_FIELD(arg0,volatile u8 *,5);
Divide(M2C_FIELD(arg0,s16 *,0xa)+step-1);
if(M2C_FIELD(arg0,s16 *,0xc)>0)value=1;else value=0;
return value;
}

u8 func_020b3290(void *arg0) {
    M2C_UNK Divide();
    M2C_UNK PlaySoundEffect(s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 var_r7;
    s16 temp_r0;
    s16 temp_r1;
    s16 temp_r2;
    s32 var_r1;
    s32 temp_r0_2;
    s32 var_r0_2; s32 delta, factor;
    u8 var_r0;

    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        return 0U;
    }
    temp_r4 = M2C_FIELD(arg0, u8 *, 5);
    temp_r6 = M2C_FIELD(arg0, s16 *, 0xA);
    var_r7 = M2C_FIELD(arg0, u8 *, 4);
    temp_r0 = Divide((temp_r6 + temp_r4) - 1, temp_r4);
    temp_r2 = temp_r0;
    if ((s32) var_r7 >= (s32) temp_r0) {
        var_r7 = temp_r2;
    }
    temp_r5 = M2C_FIELD(arg0, volatile s16 *, 0xC) + 0 * var_r7;
    temp_r1 = M2C_FIELD(arg0, volatile s16 *, 0xC);
    if (temp_r2 == (temp_r1 + (s16) var_r7)) {
        return 0U;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (temp_r1 + 1);
    M2C_FIELD(arg0, s16 *, 8) = (s16) (M2C_FIELD(arg0, s16 *, 8) + temp_r4);
    temp_r0_2 = temp_r6 - 1;
    var_r1 = M2C_FIELD(arg0, s16 *, 8);
    if ((s32) var_r1 > temp_r0_2) {
        var_r1 = temp_r0_2;
    }
    M2C_FIELD(arg0, s16 *, 8) = var_r1;
    if (temp_r5 != M2C_FIELD(arg0, s16 *, 0xC)) {
        PlaySoundEffect(0x10019);
    }
    delta=M2C_FIELD(arg0,s16 *,0xc);factor=M2C_FIELD(arg0,volatile u8 *,7);delta-=temp_r5;
M2C_FIELD(arg0,s16 *,0x12)=delta*factor;
    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Scroll a sprite grid up one row: do nothing while the previous scroll's pixel
 * offset is still animating or the grid is already at its top row; otherwise move
 * the top row and the cursor back a row, play the scroll sound when the top row
 * changed and set the pixel offset the animation eases back to zero.  Returns 1
 * when the offset changed. */
u8 ScrollSpriteGridUp(void *grid) {
M2C_UNK Divide();
M2C_UNK PlaySoundEffect(s32);
s16 scroll; s32 columns; s32 active; s32 oldScroll; u8 result; s32 cellHeight, delta;
if(M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0)active=1;else active=0;
if(active&255)return 0;
columns=M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS);
Divide(M2C_FIELD(grid,s16 *,SPRITE_GRID_ITEM_COUNT)+columns-1,columns);
scroll=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);oldScroll=M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SCROLL);
if(scroll==0)return 0;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=scroll-1;
M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)-=columns;
if(oldScroll!=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL))PlaySoundEffect(0x10019);
delta=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL); cellHeight=M2C_FIELD(grid,volatile u8 *,SPRITE_GRID_CELL_HEIGHT); delta-=oldScroll;
M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)=delta*cellHeight;
if(M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0)result=1;else result=0;
return result;
}

/* Moves one single-column sprite grid one item forward (next column): as many
 * items as fit one page, sliding the item window down a row.  Each step plays
 * the cursor sound; the pixel offset is set to the row delta times the row
 * height.  Returns 1 when the grid moved. */
u8 ScrollSpriteGridPageDown(void *grid){
s32 Divide(); M2C_UNK PlaySoundEffect(s32);
s32 active,i,factor,delta; s16 total,count,pages; u8 cols,result; s32 itemsPerPage,oldScroll;
if(M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0)active=1;else active=0;
if(active&255)return 0;
cols=M2C_FIELD(grid,u8 *,SPRITE_GRID_COLUMNS);total=M2C_FIELD(grid,s16 *,SPRITE_GRID_ITEM_COUNT);itemsPerPage=M2C_FIELD(grid,u8 *,SPRITE_GRID_ROWS);
pages=Divide(total+cols-1,cols);
count=(oldScroll=M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SCROLL),itemsPerPage>=pages?pages:itemsPerPage);
for(i=0;i<count;i++){
if(pages!=M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SCROLL)+count)M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL)=M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SCROLL)+1;
if(M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SELECTED)+cols<total)M2C_FIELD(grid,s16 *,SPRITE_GRID_SELECTED)=M2C_FIELD(grid,volatile s16 *,SPRITE_GRID_SELECTED)+cols;
}
if(oldScroll!=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL))PlaySoundEffect(0x10019);
delta=M2C_FIELD(grid,s16 *,SPRITE_GRID_SCROLL);factor=M2C_FIELD(grid,u8 *,SPRITE_GRID_CELL_HEIGHT);delta-=oldScroll;
M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)=delta*factor;
if(M2C_FIELD(grid,s16 *,SPRITE_GRID_PIXEL_OFFSET)!=0)result=1;else result=0;
return result;
}

