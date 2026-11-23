/* 24 functions from 0x020AB884 to 0x020AC7DC (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "list_widget.h"

/* Per-screen display state, indexed by screen 0 (main engine) or 1 (sub engine):
 * the screen flag GetScreenFlag reads, and the display mode GetScreenMode reads. */
#define SCREEN_STATE_FLAG 0x00 /* s8: nonzero when the screen is enabled */
#define SCREEN_STATE_MODE 0x02 /* s8: display mode applied to the screen */
#define SCREEN_CURRENT    3    /* screen selector: whichever engine is current */

#pragma opt_strength_reduction off
/* Scroll update for a vertical list: once its opening animation ends, clamps the
 * scroll position at either end, then rebuilds the pixel offsets of the two
 * sub-lists whose animation timers are being restarted. */
void UpdateListScroll(void *arg0) {
s32 Divide(s16,s16);s32 Modulo(s16,s16);s16 GetScrollLimit(void *);void ScrollListTo(void *,s16,s32);s32 GetSpriteAnimValue(void *);
s16 rowIdx,unusedB,curOffset,savedTimer; s32 pixOffset; s32 endPos; s32 rowPos; s16 rowStep; s32 visibleRows; s16 finalPos;
if(M2C_FIELD(arg0,s32 *,0x18)>=(s16)(M2C_FIELD(arg0,s16 *,6)*M2C_FIELD(arg0,s16 *,8)) && M2C_FIELD(arg0,u8 *,4)){
rowIdx=Divide((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8));
if(rowIdx<=(s16)Divide(M2C_FIELD(arg0,s16 *,12),M2C_FIELD(arg0,s16 *,8)) &&
(s16)Divide(M2C_FIELD(arg0,s16 *,12),M2C_FIELD(arg0,s16 *,8))>=1){
if((s16)Divide((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8))==0)ScrollListTo(arg0,0,0);
else {rowPos=(s16)Divide(M2C_FIELD(arg0,s16 *,12),M2C_FIELD(arg0,s16 *,8));rowStep=M2C_FIELD(arg0,s16 *,8);ScrollListTo(arg0,rowStep*(rowPos-1),0);}
}else{
rowIdx=Divide(GetScrollLimit(arg0),M2C_FIELD(arg0,s16 *,8));
if((s16)Divide((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8))>=rowIdx){
rowIdx=Divide((s16)M2C_FIELD(arg0,s32 *,24),M2C_FIELD(arg0,s16 *,8));
if((s16)Divide(GetScrollLimit(arg0),M2C_FIELD(arg0,s16 *,8))<rowIdx){
endPos=Divide((s16)M2C_FIELD(arg0,s32 *,24),M2C_FIELD(arg0,s16 *,8))<<16;
rowPos=Divide((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8))<<16;
if((rowPos>>16)==(endPos>>16))
{finalPos=Divide((s16)M2C_FIELD(arg0,s32 *,24),M2C_FIELD(arg0,s16 *,8));visibleRows=M2C_FIELD(arg0,s16 *,6);rowStep=M2C_FIELD(arg0,s16 *,8);ScrollListTo(arg0,rowStep*(finalPos-visibleRows+1),0);}
else {rowPos=(s16)Divide(M2C_FIELD(arg0,s16 *,12),M2C_FIELD(arg0,s16 *,8));rowStep=M2C_FIELD(arg0,s16 *,8);ScrollListTo(arg0,rowStep*(rowPos+1),0);}
M2C_FIELD(arg0,u8 *,4)=0;
}
}
}
}
pixOffset=M2C_FIELD(arg0,u8 *,10)*(s16)Divide((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8));
M2C_FIELD(arg0,s16 *,44)=M2C_FIELD(arg0,u8 *,11)*(s16)Modulo((s16)M2C_FIELD(arg0,s32 *,20),M2C_FIELD(arg0,s16 *,8));
M2C_FIELD(arg0,s16 *,46)=pixOffset;
curOffset=M2C_FIELD(arg0,s16 *,44);savedTimer=M2C_FIELD(arg0,s16 *,78);
M2C_FIELD(arg0,s16 *,80)=GetSpriteAnimValue((u8 *)arg0+66);M2C_FIELD(arg0,s16 *,82)=curOffset;M2C_FIELD(arg0,s16 *,78)=savedTimer;
M2C_FIELD(arg0,u16 *,68)=M2C_FIELD(arg0,u16 *,70);
curOffset=M2C_FIELD(arg0,s16 *,46);savedTimer=M2C_FIELD(arg0,s16 *,96);
M2C_FIELD(arg0,s16 *,98)=GetSpriteAnimValue((u8 *)arg0+84);M2C_FIELD(arg0,s16 *,100)=curOffset;M2C_FIELD(arg0,s16 *,96)=savedTimer;
M2C_FIELD(arg0,u16 *,86)=M2C_FIELD(arg0,u16 *,88);
}
#pragma opt_strength_reduction reset
/* Vertical pixel offset of the list window's contents: the scroll tween's value
 * plus the row sub-list tween's, restarting the row tween as a linear slide while
 * the window is still moving (its slide target has not been reached). */
s16 GetListScrollY(void *widget) {
    s32 GetSpriteAnimValue(void *);
    s16 slideTarget;
    s32 firstValue;
    s32 secondValue;
    s32 moving;

    slideTarget = M2C_FIELD(widget, s16 *, LIST_WIDGET_SLIDE_TARGET_Y);
    if (slideTarget != GetSpriteAnimValue(widget + LIST_WIDGET_SCROLL_TWEEN)) {
        moving = 1;
    } else {
        moving = 0;
    }
    if (moving & 0xFF) {
        M2C_FIELD(widget, s8 *, LIST_WIDGET_ROW_TWEEN) = SPRITE_TWEEN_LINEAR;
        firstValue = GetSpriteAnimValue(widget + LIST_WIDGET_SCROLL_TWEEN);
        return (s16) (firstValue + GetSpriteAnimValue(widget + LIST_WIDGET_ROW_TWEEN));
    }
    secondValue = GetSpriteAnimValue(widget + LIST_WIDGET_SCROLL_TWEEN);
    return (s16) (secondValue + GetSpriteAnimValue(widget + LIST_WIDGET_ROW_TWEEN));
}

void func_020abb9c(void *arg0) {
    M2C_UNK Find3DSpriteByClassAndZ(M2C_UNK *, u16);
    extern M2C_UNK data_02126b94;
    Find3DSpriteByClassAndZ(&data_02126b94, M2C_FIELD(arg0, u16 *, 0x68));
}

void func_020abbb4(void *arg0) {M2C_UNK Find3DSpriteByClassAndZ(M2C_UNK *,u16);extern M2C_UNK data_02126b94;Find3DSpriteByClassAndZ(&data_02126b94,M2C_FIELD(arg0,u16 *,106));}

void func_020abbcc(void *arg0) {M2C_UNK Find3DSpriteByClassAndZ(M2C_UNK *,u16);extern M2C_UNK data_02126b94;Find3DSpriteByClassAndZ(&data_02126b94,M2C_FIELD(arg0,u16 *,108));}

void func_020abbe4(void *arg0) {M2C_UNK Find3DSpriteByClassAndZ(M2C_UNK *,u16);extern M2C_UNK data_02126b94;Find3DSpriteByClassAndZ(&data_02126b94,M2C_FIELD(arg0,u16 *,110));}

/* Advance one frame of a two-axis easing animation: when its target coordinate
   (+0x10/+0x11) changes, latch it and restart; ease +0xA from +8 towards 0xA0 or
   back to 0 depending on the direction flag (+0x12), and after 8 easing frames
   plus a 4-frame hold snap the saved coordinate (+0xC/+0xD) to the target,
   toggle direction and set +0x13 unless already at the end value (0x63). */
void func_020abbfc(void *arg0) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    s32 atStart;
    s32 matching;
    u16 frame;
    u16 holdTimer;
    u8 forward;
    u8 targetX;

    matching = 0;
    M2C_FIELD(arg0, s8 *, 0x13) = 0;
    targetX = M2C_FIELD(arg0, u8 *, 0x10);
    if ((M2C_FIELD(arg0, u8 *, 0xE) == targetX) && (M2C_FIELD(arg0, u8 *, 0xF) == M2C_FIELD(arg0, u8 *, 0x11))) {
        matching = 1;
    }
    if (!(matching & 0xFF)) {
        M2C_FIELD(arg0, u8 *, 0xE) = targetX;
        M2C_FIELD(arg0, u8 *, 0xF) = (u8) M2C_FIELD(arg0, u8 *, 0x11);
        if (M2C_FIELD(arg0, u16 *, 6) == 0) {
            if ((M2C_FIELD(arg0, u8 *, 0xE) == M2C_FIELD(arg0, u8 *, 0xC)) && (M2C_FIELD(arg0, u8 *, 0xF) == M2C_FIELD(arg0, u8 *, 0xD))) {
                atStart = 1;
            } else {
                atStart = 0;
            }
            forward = M2C_FIELD(arg0, u8 *, 0x12);
            if (atStart & 0xFF) {
                if (forward == 0) {
                    M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
                    M2C_FIELD(arg0, u16 *, 4) = 0U;
                    M2C_FIELD(arg0, u8 *, 0x12) = 1U;
                }
            } else if (forward == 1) {
                M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
                M2C_FIELD(arg0, u16 *, 4) = 0U;
                M2C_FIELD(arg0, u8 *, 0x12) = 0U;
            }
        }
        M2C_FIELD(arg0, u16 *, 6) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x12) == 0) {
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg0, s16 *, 8) + EaseInterpolate(1, 0, 0xA0, M2C_FIELD(arg0, u16 *, 4), 8));
        if ((s32) M2C_FIELD(arg0, s16 *, 0xA) > 0xA0) {
            M2C_FIELD(arg0, s16 *, 0xA) = 0xA0;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0xA) = EaseInterpolate(4, M2C_FIELD(arg0, s16 *, 8), 0, M2C_FIELD(arg0, u16 *, 4), 8);
    }
    frame = M2C_FIELD(arg0, u16 *, 4);
    if (frame == 8) {
        if (M2C_FIELD(arg0, u8 *, 0x12) != 0) {
            return;
        }
        holdTimer = M2C_FIELD(arg0, u16 *, 6);
        if ((s32) holdTimer < 4) {
            M2C_FIELD(arg0, u16 *, 6) = (u16) (holdTimer + 1);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 0xE);
        M2C_FIELD(arg0, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 0xF);
        M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 4) = 0U;
        M2C_FIELD(arg0, u16 *, 6) = 0U;
        if (M2C_FIELD(arg0, u8 *, 0xE) == 0x63) {
            return;
        }
        M2C_FIELD(arg0, s8 *, 0x13) = 1;
        M2C_FIELD(arg0, u8 *, 0x12) = 1U;
        return;
    }
    M2C_FIELD(arg0, u16 *, 4) = (u16) (frame + 1);
}

void *func_020abdac(void *arg0) {
 extern M2C_UNK data_02126be4;
 void *p;
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_02126be4;
 p=M2C_FIELD(arg0,void **,0x64);
 if(p!=NULL) {HeapFreeBlock(M2C_FIELD(p,s32 *,0x14));MemFree(p);}
 MemFree(arg0);return arg0;
}

void *func_020abdec(void *arg0) {
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK data_02126be4;
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02126be4;
    temp_r4 = M2C_FIELD(arg0, void **, 0x64);
    if (temp_r4 != NULL) {
        HeapFreeBlock(M2C_FIELD(temp_r4, s32 *, 0x14));
        MemFree(temp_r4);
    }
    return arg0;
}

void func_020abe24(void) {

}

s32 func_020abe28(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Set the per-screen enabled flag: screen 0 or 1, or SCREEN_CURRENT, which
 * resolves to the sub screen when the main engine is the active one and to the
 * main screen otherwise. */
void SetScreenFlag(u8 screen, s8 flag) {
    extern s32 gScreenStates;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 index;
    u8 isMain;
    u8 resolved;

    index = screen;
    if (index == SCREEN_CURRENT) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            resolved = 1;
        } else {
            resolved = 0;
        }
        index = resolved;
    }
    M2C_FIELD((gScreenStates + index), s8 *, SCREEN_STATE_FLAG) = flag;
}

/* Reads the per-screen enabled flag: screen 0 or 1, or SCREEN_CURRENT, which
 * resolves to the sub screen when the main engine is the active one and to the
 * main screen otherwise. */
u8 GetScreenFlag(u8 screen) {
    extern s32 gScreenStates;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 index;
    u8 isMain;
    u8 resolved;

    index = screen;
    if (index == SCREEN_CURRENT) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            resolved = 1;
        } else {
            resolved = 0;
        }
        index = resolved;
    }
    return M2C_FIELD(gScreenStates + index, u8 *, SCREEN_STATE_FLAG);
}

/* Records a display mode for a screen's state: screen 3 resolves to the 3D sprite
   engine that is current (0 for the main engine, 1 for the sub engine). */
void SetScreenStateMode(u8 screen, s8 mode) {
    extern s32 gScreenStates;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 index;
    u8 isMain;
    u8 resolved;

    index = screen;
    if (index == SCREEN_CURRENT) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            resolved = 1;
        } else {
            resolved = 0;
        }
        index = resolved;
    }
    M2C_FIELD((gScreenStates + index), s8 *, SCREEN_STATE_MODE) = mode;
}

/* Display mode recorded for a screen's state: screen 3 resolves to the 3D sprite
 * engine that is current (0 when gCur3DSpriteEngine is the main engine, otherwise 1). */
u8 GetScreenMode(u8 screen) {
    extern s32 gScreenStates;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 index;
    u8 isMain;
    u8 resolved;

    index = screen;
    if (index == SCREEN_CURRENT) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            resolved = 1;
        } else {
            resolved = 0;
        }
        index = resolved;
    }
    return M2C_FIELD(gScreenStates + index, u8 *, SCREEN_STATE_MODE);
}

void func_020abf94(void) {
 void SetScreenFlag(u8,s8); void SetScreenStateMode(u8,s8);
 s32 i=0; do {SetScreenFlag(i,1);SetScreenStateMode(i,0);i++;}while(i<2);
}

/* Animates the screen-split transition from its frame/length: eases the
 * horizontal and vertical progress (0..256 and 0..192) and writes the two split
 * windows' bounds into the active engine's bank, clearing them once the split
 * has fully opened. */
void UpdateSplitTransition(u16 frame, u16 length) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void ApplyScreenMode(s32);
    extern s32 gCur3DSpriteEngine;
    s32 hProgress;
    s32 vProgress;

    hProgress = EaseInterpolate(EASE_LINEAR, 0, 0x100, frame, length);
    vProgress = EaseInterpolate(EASE_LINEAR, 0, 0xc0, frame, length);
    if (hProgress == 0 || vProgress == 0) {
        ApplyScreenMode(2);
        return;
    }
    if (hProgress >= 0x100) {
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_H) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_V) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_H + 1) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_V + 1) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_H) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_V) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_H + 1) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_V + 1) = 0;
    } else {
        u8 splitRight = (u8)((hProgress + 0x100) >> 1);
        u8 splitTop = (u8)((0xc0 - vProgress) >> 1);
        u8 splitBottom = (u8)((vProgress + 0xc0) >> 1);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_H) = splitRight;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_V) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_H + 1) = (u8)((0x100 - hProgress) >> 1);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW0_V + 1) = splitTop;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_H) = splitRight;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_V) = splitBottom;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_H + 1) = (u8)((0x100 - hProgress) >> 1);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_WINDOW1_V + 1) = 0xc0;
    }
}

/* Applies a display transition to one screen's 3D sprite engine: for each of the
 * two engines that match `screen`, it sets the OAM/bank flags for the previous
 * mode, then offsets the screen (mode 0/1) or sets up the split-blank (mode 2),
 * and records the flag and mode in the screen's state. */
void ConfigureScreenEngine(u8 screen, s32 flag, u8 mode) {
    u8 GetScreenMode(u8);
    void SetScreenFlag(u8, s8);
    void SetScreenStateMode(u8, s8);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineMain;
    extern s32 g3DSpriteEngineSub;
    s32 savedEngine;
    s32 i;
    s32 prevMode; s32 engine;
    u16 *volatile sp4c;
    u16 *volatile sp48;
    u16 *volatile sp44;
    u16 *volatile sp40;
    u16 *volatile sp3c;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2c;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1c;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    savedEngine = gCur3DSpriteEngine;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            engine = g3DSpriteEngineMain;
        } else {
            engine = g3DSpriteEngineSub;
        }

        gCur3DSpriteEngine=engine;
        if (screen == 0 && engine != g3DSpriteEngineMain) {
            continue;
        }
        if (screen == 1 && engine != g3DSpriteEngineSub) {
            continue;
        }
        if (screen == 3 && engine != savedEngine) {
            continue;
        }

        prevMode = GetScreenMode(screen);
        switch(prevMode){case 0:case 1:
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0;
        break;case 2:
            sp4c = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp4c = *sp4c & ~0x200;

            sp48 = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp48 = *sp48 & ~0x400;
        }

        switch(mode){case 0:
            *(s8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = -16;
        break;case 1:
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0x10;
        break;case 2:
            sp44 = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp44 = *sp44 | 0x200;

            sp40 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp40 = *sp40 & ~1;

            sp3c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp3c = *sp3c & ~2;

            sp38 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp38 = *sp38 & ~4;

            sp34 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp34 = *sp34 & ~8;

            sp30 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp30 = *sp30 & ~0x10;

            sp2c = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp2c = *sp2c | 0x400;

            sp28 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp28 = *sp28 & ~0x100;

            sp24 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp24 = *sp24 & ~0x200;

            sp20 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp20 = *sp20 & ~0x400;

            sp1c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp1c = *sp1c & ~0x800;

            sp18 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp18 = *sp18 & ~0x1000;

            sp14 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp14 = (*sp14 & ~1) | 1;

            sp10 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp10 = *sp10 | 0x2;

            spC = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *spC = *spC | 0x4;

            sp8 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp8 = *sp8 | 0x8;

            sp4 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp4 = *sp4 | 0x10;

            sp0 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp0 = *sp0 | 0x20;

            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x48) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4a) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x49) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4b) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4c) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4e) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4d) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4f) = 0;
        }

        ((void(*)(u8, s32))SetScreenFlag)(screen, flag);
        ((void(*)(u8, s32))SetScreenStateMode)(screen, (s32)mode);
    }

    gCur3DSpriteEngine = savedEngine;
}

void func_020ac598(s32 arg0) {
    M2C_UNK func_01ff91d8();
    M2C_UNK func_01ff9690();
    M2C_UNK Apply3DSpriteBanks();
    switch (arg0) {                                 /* irregular */
    case 0:
        func_01ff91d8();
        return;
    case 1:
        func_01ff9690();
        return;
    default:
        Apply3DSpriteBanks();
        return;
    }
}

void func_020ac5c8(void *arg0) {
    M2C_UNK DecrementSpriteChildCount();
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        return;
    }
    DecrementSpriteChildCount();
}

/* Starts the screen-split transition sprite: resets its elapsed-frame counter,
 * adjusts its mode to one the screen's current display mode can show (a static
 * screen cannot slide, an offset screen cannot stay static), and configures the
 * sprite's engine for it. */
void ScreenTransitionSprite_Start(void *transition) {
 u8 GetScreenMode(u8); void ConfigureScreenEngine(u8,s32,u8);
 M2C_FIELD(transition,u16 *,TRANSITION_SPRITE_ELAPSED)=0;
 switch(GetScreenMode(M2C_FIELD(transition,u8 *,TRANSITION_SPRITE_SCREEN))) {
 case 0: case 2: if(M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)==1)M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)=0; break;
 case 1: if(M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)==0)M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)=1;
 if(M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)==2)M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE)=1; break;
 }
 ConfigureScreenEngine(M2C_FIELD(transition,u8 *,TRANSITION_SPRITE_SCREEN),0,M2C_FIELD(transition,s32 *,TRANSITION_SPRITE_MODE));
}

void func_020ac65c(void *arg0) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void UpdateSplitTransition(u16, u16);
    void SetScreenMode(s32);
    void Sprite_ResumeAnimation(void *);
    void func_020ac598(s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub, g3DSpriteEngineMain;

    s8 val;
    s8 neg;
    s32 saved;
    s32 temp;
    s32 i;
    void *bank;
    u8 mode;

    M2C_FIELD(arg0, u16 *, 0x38)++;
    temp = EaseInterpolate(0, 0x10, 0, M2C_FIELD(arg0, u16 *, 0x38), M2C_FIELD(arg0, u16 *, 0x3a));
    saved = gCur3DSpriteEngine;
    val = (s8)temp;
    neg = (s8)(-temp);

    i = 0;
    do {
        if (i == 0) bank = (void *)g3DSpriteEngineMain; else bank = (void *)g3DSpriteEngineSub;
        gCur3DSpriteEngine = (s32)bank;
        mode = M2C_FIELD(arg0, u8 *, 0x3c);
        if (mode == 0 && bank != (void *)g3DSpriteEngineMain) goto next;
        if (mode == 1 && bank != (void *)g3DSpriteEngineSub) goto next;
        if (mode == 3 && bank != (void *)saved) goto next;

        switch (M2C_FIELD(arg0, s32 *, 0x34)) {
        case 0:
            M2C_FIELD(M2C_FIELD(bank, s32 *, 0), s8 *, 0x50) = neg;
            break;
        case 1:
            M2C_FIELD(M2C_FIELD(bank, s32 *, 0), s8 *, 0x50) = val;
            break;
        case 2:
            UpdateSplitTransition(M2C_FIELD(arg0, u16 *, 0x38), M2C_FIELD(arg0, u16 *, 0x3a));
            break;
        }
        if (M2C_FIELD(arg0, u16 *, 0x38) >= M2C_FIELD(arg0, u16 *, 0x3a)) {
            SetScreenMode(M2C_FIELD(arg0, s32 *, 0x34) & 0xff);
            Sprite_ResumeAnimation(arg0);
        }
    next:
        ++i;
    } while (i < 2);

    gCur3DSpriteEngine = saved;
    if (M2C_FIELD(arg0, s32 *, 0x18) != 1) {
        return;
    }
    func_020ac598(M2C_FIELD(arg0, u8 *, 0x3c));
}

void func_020ac7a0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        return;
    }
    DecrementSpriteChildCount();
}

void func_020ac7b8(void *arg0) {
    void ConfigureScreenEngine(u8, M2C_UNK, u8);
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    ConfigureScreenEngine(M2C_FIELD(arg0, u8 *, 0x3C), 1, (u8) M2C_FIELD(arg0, s32 *, 0x34));
}

