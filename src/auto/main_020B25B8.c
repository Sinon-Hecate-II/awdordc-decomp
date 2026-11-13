/* 24 functions from 0x020B25B8 to 0x020B34F8 (main), found by ds-decomp. */
#include "common.h"
#include "sprite_grid.h"

void func_020b25b8(void){
u8 func_020b2714(void);void func_020b2d5c(void*);
extern u16 **gCur3DSpriteEngine;extern void *g3DSpriteEngineMain,*g3DSpriteEngineSub,*gSpriteSlotManager;extern u8 gSpriteSlots[];
void *old,*p;u8 mode;s32 j,i;u8 *q;
if(func_020b2714())return;
old=gCur3DSpriteEngine;
i=0;do{
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
mode=M2C_FIELD(gSpriteSlotManager,u8*,0x24);
if((mode!=0||p==g3DSpriteEngineMain)&&(mode!=1||p==g3DSpriteEngineSub)&&(mode!=3||p==old)){
j=0;q=gSpriteSlots;
do{if(q[1])func_020b2d5c(q);j++;q+=60;}while(j<85);
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

s32 TryFocusSpriteSlot(void *p) {
extern void *gTouchState,*gSpriteSlotManager;
s32 IsDialogActive(void);s32 SpriteSlotHasFlags(void *,M2C_UNK);
void FocusSpriteSlot(void *);
u16 x=M2C_FIELD(gTouchState,u16 *,0);
u16 y=M2C_FIELD(gTouchState,u16 *,2);
if(IsDialogActive())return 0;
if(!M2C_FIELD(gTouchState,u8 *,0x12))return 0;
if(!SpriteSlotHasFlags(p,1))return 0;
if(!SpriteSlotHitTest(p,x,y))return 0;
if(M2C_FIELD(gSpriteSlotManager,void **,0xc)==p)return 0;
if(SpriteSlotHasFlags(p,0x400))return 0;
FocusSpriteSlot(p);
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

void func_020b2d5c(void *arg0) {
M2C_UNK func_01ff883c(u16,u16,u16,s32);
s32 GetSpriteDescForSize(s16,s16);
extern u16 **gCur3DSpriteEngine;
u32 a,b; s16 x,y; s32 flag;
a=M2C_FIELD(arg0,u16 *,0x20); b=M2C_FIELD(arg0,u16 *,0x22);
x=M2C_FIELD(arg0,s16 *,0x18); y=M2C_FIELD(arg0,s16 *,0x1a); flag=0;
if(!SpriteSlotHasFlags(arg0,2))return;
if(SpriteSlotHasFlags(arg0,0x800))flag=0x400;
func_01ff883c((u16)(M2C_FIELD(arg0,s16 *,0x14)&0x1ff),(u16)((M2C_FIELD(arg0,s16 *,0x16)&0xff)|flag),(u16)((0x3ff&(a>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|((b<<28)>>16)),GetSpriteDescForSize(x,y));
}

void func_020b2e14(void *p) {
void (*cb)(void *)=M2C_FIELD(p,void (**)(void *),0x2c);
if(!cb)return;cb(p);
}

void func_020b2e2c(void) {
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

void func_020b3038(void *arg0, s32 arg1) {
    M2C_UNK Divide();
    s16 val8;
    u8 step;
    s16 orig_a;
    s32 r8;
    s16 orig_c;
    s16 fres;
    s32 r7, r8c, r8const, r9;
    s16 c, f;
    s16 cur;
    s16 diff;

    val8 = M2C_FIELD(arg0, s16 *, 0x8);
    if (arg1 == val8) {
        return;
    }
    step = M2C_FIELD(arg0, u8 *, 0x5);
    orig_a = M2C_FIELD(arg0, s16 *, 0xA);
    r8 = M2C_FIELD(arg0, u8 *, 0x4);
    orig_c = M2C_FIELD(arg0, s16 *, 0xC);
    fres = (s16) Divide(orig_a + step - 1, step);
    if (arg1 < 0) {
        return;
    }
    if (orig_a <= arg1) {
        return;
    }
    if (fres <= r8) {
        r8 = fres;
    }
    if (arg1 < val8) {
        do {
            M2C_FIELD(arg0, s16 *, 0x8) = (s16) (M2C_FIELD(arg0, s16 *, 0x8) - 1);
            c = M2C_FIELD(arg0, s16 *, 0xC);
            f = (s16) Divide(M2C_FIELD(arg0, s16 *, 0x8), step);
            diff = (s16) (f - c);
            if (diff < 0) {
                if (c > 0) {
                    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (M2C_FIELD(arg0, s16 *, 0xC) - 1);
                }
            }
        } while (arg1 < M2C_FIELD(arg0, s16 *, 0x8));
    } else {
        r7 = orig_a - 1;
        r8c = r8;
        r8const = r8c - 1;
        r9 = fres - r8c;
        do {
            M2C_FIELD(arg0, s16 *, 0x8) = (s16) (M2C_FIELD(arg0, s16 *, 0x8) + 1);
            cur = M2C_FIELD(arg0, s16 *, 0x8);
            if ((s32) cur > r7) {
                cur = (s16) r7;
            }
            M2C_FIELD(arg0, s16 *, 0x8) = cur;
            c = M2C_FIELD(arg0, s16 *, 0xC);
            f = (s16) Divide(cur, step);
            diff = (s16) (f - c);
            if (diff > (s16) r8const) {
                if (c < r9) {
                    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (c + 1);
                }
            }
        } while (M2C_FIELD(arg0, s16 *, 0x8) < arg1);
    }
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((M2C_FIELD(arg0, s16 *, 0xC) - orig_c) * M2C_FIELD(arg0, u8 *, 0x7));
}

s16 func_020b316c(void *arg0) {
    s16 temp_r2;
    u8 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 7);
    temp_r2 = M2C_FIELD(arg0, s16 *, 0x12);
    if ((s32) temp_r2 < (s32) (0 - temp_r3)) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 + temp_r3);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) > 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 < 0) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 + ((s32) temp_r3 >> 2));
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) > 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 > (s32) temp_r3) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 - temp_r3);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) < 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    } else if ((s32) temp_r2 > 0) {
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) (temp_r2 - ((s32) temp_r3 >> 2));
        if ((s32) M2C_FIELD(arg0, s16 *, 0x12) < 0) {
            M2C_FIELD(arg0, s16 *, 0x12) = 0;
        }
    }
    return M2C_FIELD(arg0, s16 *, 0x12);
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

u8 func_020b3368(void *arg0) {
M2C_UNK Divide();
M2C_UNK PlaySoundEffect(s32);
s16 current; s32 step; s32 active; s32 old; u8 result; s32 factor, delta;
if(M2C_FIELD(arg0,s16 *,0x12)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(arg0,u8 *,5);
Divide(M2C_FIELD(arg0,s16 *,0xa)+step-1,step);
current=M2C_FIELD(arg0,s16 *,0xc);old=M2C_FIELD(arg0,volatile s16 *,0xc);
if(current==0)return 0;
M2C_FIELD(arg0,s16 *,0xc)=current-1;
M2C_FIELD(arg0,s16 *,8)-=step;
if(old!=M2C_FIELD(arg0,s16 *,0xc))PlaySoundEffect(0x10019);
delta=M2C_FIELD(arg0,s16 *,0xc); factor=M2C_FIELD(arg0,volatile u8 *,7); delta-=old;
M2C_FIELD(arg0,s16 *,0x12)=delta*factor;
if(M2C_FIELD(arg0,s16 *,0x12)!=0)result=1;else result=0;
return result;
}

u8 func_020b3410(void *arg0){
s32 Divide(); M2C_UNK PlaySoundEffect(s32);
s32 active,i,factor,delta; s16 total,count,limit; u8 step,result; s32 n,old;
if(M2C_FIELD(arg0,s16 *,0x12)!=0)active=1;else active=0;
if(active&255)return 0;
step=M2C_FIELD(arg0,u8 *,5);total=M2C_FIELD(arg0,s16 *,10);n=M2C_FIELD(arg0,u8 *,4);
limit=Divide(total+step-1,step);
count=(old=M2C_FIELD(arg0,volatile s16 *,12),n>=limit?limit:n);
for(i=0;i<count;i++){
if(limit!=M2C_FIELD(arg0,volatile s16 *,12)+count)M2C_FIELD(arg0,s16 *,12)=M2C_FIELD(arg0,volatile s16 *,12)+1;
if(M2C_FIELD(arg0,volatile s16 *,8)+step<total)M2C_FIELD(arg0,s16 *,8)=M2C_FIELD(arg0,volatile s16 *,8)+step;
}
if(old!=M2C_FIELD(arg0,s16 *,12))PlaySoundEffect(0x10019);
delta=M2C_FIELD(arg0,s16 *,12);factor=M2C_FIELD(arg0,u8 *,7);delta-=old;
M2C_FIELD(arg0,s16 *,18)=delta*factor;
if(M2C_FIELD(arg0,s16 *,18)!=0)result=1;else result=0;
return result;
}

