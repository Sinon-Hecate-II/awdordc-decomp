/* 30 functions from 0x020BCB94 to 0x020BDA88 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

s32 GetKeyActionFlags(void){extern void *gKeyState;u16 v=M2C_FIELD(gKeyState,u16 *,0);if(v&2)return 32;if(v&1)return 16;if(v&256)return 256;if(v&1024)return 64;return 0;}

s32 func_020bcbd8(void) {
    extern void *gKeyState;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(gKeyState, u16 *, 2);
    if (temp_r0 & 0x90) {
        return 8;
    }
    if (temp_r0 & 0x60) {
        return 4;
    }
    return 0;
}

s32 func_020bcc04(void) {
    extern void *gKeyState;
    if (M2C_FIELD(gKeyState, u16 *, 0) & 2) {
        return 0x20;
    }
    if (M2C_FIELD(gKeyState, u16 *, 6) & 2) {
        return 0;
    }
    return 0x20;
}

s32 GetMapCursorKeyAction(void) {
    extern void *gKeyState;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(gKeyState, u16 *, 0);
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    if (temp_r0 & 0x100) {
        return 0x100;
    }
    if (temp_r0 & 0x400) {
        return 0x40;
    }
    return 0;
}

void func_020bcc78(u8 arg0,u8 arg1,M2C_UNK arg2,M2C_UNK arg3,s32 arg4) {
void PlaySoundAtTile(s32,u8,u8);
void func_020b5188(void *,u8,u8,s32,s32,s32,s32);
extern void **gCurrentMap;
extern M2C_UNK data_021293a4,data_021293b0,data_021293bc;
s32 value;
void *base;
base=*gCurrentMap;
value=M2C_FIELD(M2C_FIELD(base,u16 *,0x52a4)*0x8c+base,s32 *,0x6810);
switch((u32)(value<<24)>>24) {
case 2:
case 9:
func_020b5188(&data_021293a4,arg0,arg1,0,0,0,arg4);
PlaySoundAtTile(0x12a,arg0,arg1);
break;
case 8:
func_020b5188(&data_021293b0,arg0,arg1,0,0,0,arg4);
PlaySoundAtTile(0x12b,arg0,arg1);
break;
default:
func_020b5188(&data_021293bc,arg0,arg1,0,0,0,arg4);
PlaySoundAtTile(0x129,arg0,arg1);
break;
}
}

void func_020bcd90(void *a){extern void **gCurrentMap;extern u8 data_021261a0[];void func_02096b24(s32);u32 v=(u32)(M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(a,s32 *,0x5c)*0x8c,s32 *,0x6810)<<24)>>24;func_02096b24(M2C_FIELD(data_021261a0+v*0x9c,s32 *,M2C_FIELD(a,s32 *,0x68)*4));}

void func_020bcde0(void) {
    M2C_UNK func_020c4764();
    func_020c4764();
}

void func_020bcdec(void *arg0) {
    M2C_UNK func_0208f7d0();
    M2C_UNK func_020a2a70(u8);
    func_020a2a70((u8) M2C_FIELD(arg0, s32 *, 0x5C));
    func_0208f7d0();
}

void func_020bce04(s32 a){void PlaySoundAtTile(s32,u8,u8);void func_020b5188(void *,u8,u8,s32,s32,s32,s32);extern u8 data_021293cc[];extern void **gCurrentMap;void *p=M2C_FIELD(*gCurrentMap,void **,0x52d0);PlaySoundAtTile(0x128,M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2));p=M2C_FIELD(*gCurrentMap,void **,0x52d0);func_020b5188(data_021293cc,M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),0,0,0,a);}

void func_020bce74(void *a){extern void **gCurrentMap;extern u8 data_021261bc[];void func_020a3428(s32,s32);s32 x=M2C_FIELD(a,s32 *,0x5c),y=M2C_FIELD(a,s32 *,0x64);u32 v;func_020a3428(x,y);v=(u32)(M2C_FIELD((u8 *)*gCurrentMap+x*0x8c,s32 *,0x6810)<<24)>>24;(*(void (**)(s32,void *))(data_021261bc+v*0x9c+y*0x28))(x,a);}

void func_020bcee4(void *arg0) {
    M2C_UNK func_020a33f0(s32, M2C_UNK);
    M2C_UNK func_020a34a8(s32);
    M2C_UNK func_020a34f4(s32);
    M2C_UNK func_020c0a88();
    M2C_UNK RefreshMapView();
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    func_020a34a8(temp_r4);
    func_020a34f4(temp_r4);
    func_020a33f0(temp_r4, 0);
    func_020c0a88();
    RefreshMapView();
}

void func_020bcf14(s32 a){void *func_01ffa3dc(M2C_UNK *,s32);s32 NextRandomValue(void);extern M2C_UNK data_0212931c;void *p=func_01ffa3dc(&data_0212931c,7);M2C_FIELD(p,s32 *,0x5c)=a;M2C_FIELD(p,s32 *,0x60)=0;M2C_FIELD(p,s32 *,0x64)=1;M2C_FIELD(p,s32 *,0x68)=NextRandomValue()%6;}

void func_020bcf6c(void){extern void *gTouchState;extern void **gCurrentMap;s32 IsTouchInputDisabled(void);void ScreenToMapPosition(u16,u16,s32 *);s32 Divide(s32,s32);void ClampCursorToMap(void);
s32 pos[3];u16 x=M2C_FIELD(gTouchState,u16 *,0),y=M2C_FIELD(gTouchState,u16 *,2);
if(IsTouchInputDisabled())return;if(!M2C_FIELD(gTouchState,u8 *,0x12))return;
ScreenToMapPosition(x,y,pos);
M2C_FIELD(*gCurrentMap,s16 *,0x52c2)=Divide(pos[0],768);
M2C_FIELD(*gCurrentMap,s16 *,0x52c4)=Divide(pos[1],768);
ClampCursorToMap();if(!M2C_FIELD(gTouchState,u8 *,0x14))return;
M2C_FIELD(*gCurrentMap,s16 *,0x52ca)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
M2C_FIELD(*gCurrentMap,s16 *,0x52cc)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
}

void func_020bd054(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x4E) = 0;
    M2C_FIELD(arg0, s16 *, 0x4C) = 0;
}

void func_020bd064(void *arg0) {
    s16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x4C);
    if ((s32) temp_r1 < 8) {
        M2C_FIELD(arg0, s16 *, 0x4C) = (s16) (temp_r1 + 1);
    }
}

void func_020bd078(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x4C) = 0;
}

void func_020bd084(void *arg0) {
    M2C_UNK func_01ffa6fc();
    s16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x4C);
    if ((s32) temp_r1 >= 8) {
        func_01ffa6fc();
        return;
    }
    if ((s32) temp_r1 < 8) {
        M2C_FIELD(arg0, s16 *, 0x4C) = (s16) (temp_r1 + 1);
    }
}

void CreateTouchCursor(s16 a,s16 b){extern M2C_UNK data_021293d4;s32 FindObjectByClass(M2C_UNK *);void *func_01ffa3dc(M2C_UNK *,s32);void *p;if(FindObjectByClass(&data_021293d4))return;p=func_01ffa3dc(&data_021293d4,7);M2C_FIELD(p,s32 *,0x34)=a;M2C_FIELD(p,s32 *,0x38)=b;}

void DeleteTouchCursor(void){extern M2C_UNK data_021293d4;s32 FindObjectByClass(M2C_UNK *);M2C_UNK func_01ffa9e4(M2C_UNK *);if(!FindObjectByClass(&data_021293d4))return;func_01ffa9e4(&data_021293d4);}

void func_020bd104(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    extern M2C_UNK data_021293d4;
    func_01ffa9bc(&data_021293d4);
}

u8 func_020bd118(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_021293d4;
    u8 var_r0;

    if (FindObjectByClass(&data_021293d4) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020bd13c(s32 a){extern void *gTouchState;s32 IsTouchInputDisabled(void);s32 func_020bdecc(s32,s32);s32 func_020bdf7c(s32,s32);s32 func_020bdf50(s32,s32);
u16 x=M2C_FIELD(gTouchState,u16 *,0),y=M2C_FIELD(gTouchState,u16 *,2);
if(IsTouchInputDisabled())return 0;if(!M2C_FIELD(gTouchState,u8 *,0x12))return 0;
if(func_020bdecc(x,y)){if(M2C_FIELD(gTouchState,u8 *,0x14))return 16;return 4096;}
if(func_020bdf7c(x,y)){if(M2C_FIELD(gTouchState,u8 *,0x14))return 256;return 4096;}
if(a&&func_020bdf50(x,y)){if(M2C_FIELD(gTouchState,u8 *,0x14))return 64;return 32;}return 4096;
}

/* Updates the map cursor target from the current stylus position. */
void func_020bd220(void *arg0) {
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    void PlaySoundEffect(void *);
    s32 IsTouchInputDisabled(void);
    void CreateTouchCursor(s16, s16);
    void DeleteTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 coords[3];
    u16 touchX, touchY;
    s16 oldX, oldY;
    void *map;
    touchX = M2C_FIELD(gTouchState, u16 *, 0);
    touchY = M2C_FIELD(gTouchState, u16 *, 2);
    map = *gCurrentMap;
    oldX = M2C_FIELD(map, s16 *, 0x52C2);
    oldY = M2C_FIELD(map, s16 *, 0x52C4);
    if (IsTouchInputDisabled() != 0) return;
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) {
        DeleteTouchCursor();
        return;
    }
    ScreenToMapPosition(touchX, touchY, coords);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = Divide(coords[0], 0x300);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = Divide(coords[1], 0x300);
    if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
        map = *gCurrentMap;
        M2C_FIELD(map, s16 *, 0x52CA) = M2C_FIELD(map, s16 *, 0x52C2);
        map = *gCurrentMap;
        M2C_FIELD(map, s16 *, 0x52CC) = M2C_FIELD(map, s16 *, 0x52C4);
        map = *gCurrentMap;
        CreateTouchCursor(M2C_FIELD(map, s16 *, 0x52CA), M2C_FIELD(map, s16 *, 0x52CC));
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52CA) != M2C_FIELD(map, s16 *, 0x52C2) ||
        M2C_FIELD(map, s16 *, 0x52CC) != M2C_FIELD(map, s16 *, 0x52C4)) {
        DeleteTouchCursor();
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = 0xFF;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = 0xFF;
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52C2) == oldX && M2C_FIELD(map, s16 *, 0x52C4) == oldY) return;
    PlaySoundEffect(arg0);
}

/* Update the map camera target, optionally moving its lookAt and requesting a refresh. */
void func_020bd3c0(void *arg0) {
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    void PlaySoundEffect(void *);
    s32 IsTouchInputDisabled(void);
    void CreateTouchCursor(s16, s16);
    void DeleteTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 coords[3];
    u16 touchX, touchY;
    s16 oldX, oldY;
    void *map;
    touchX = M2C_FIELD(gTouchState, u16 *, 0);
    touchY = M2C_FIELD(gTouchState, u16 *, 2);
    map = *gCurrentMap;
    oldX = M2C_FIELD(map, s16 *, 0x52C2);
    oldY = M2C_FIELD(map, s16 *, 0x52C4);
    if (IsTouchInputDisabled() != 0) return;
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) {
        DeleteTouchCursor();
        return;
    }
    ScreenToMapPosition(touchX, touchY, coords);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = Divide(coords[0], 0x300);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = Divide(coords[1], 0x300);
    if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
        map = *gCurrentMap;
        M2C_FIELD(map, s16 *, 0x52CA) = M2C_FIELD(map, s16 *, 0x52C2);
        map = *gCurrentMap;
        M2C_FIELD(map, s16 *, 0x52CC) = M2C_FIELD(map, s16 *, 0x52C4);
        map = *gCurrentMap;
        CreateTouchCursor(M2C_FIELD(map, s16 *, 0x52CA), M2C_FIELD(map, s16 *, 0x52CC));
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52CA) != M2C_FIELD(map, s16 *, 0x52C2) ||
        M2C_FIELD(map, s16 *, 0x52CC) != M2C_FIELD(map, s16 *, 0x52C4)) {
        DeleteTouchCursor();
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = 0xFF;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = 0xFF;
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52C2) == oldX && M2C_FIELD(map, s16 *, 0x52C4) == oldY) return;
    PlaySoundEffect(arg0);
}

s32 func_020bd560(void){s32 IsTouchInputDisabled(void);void SelectCursorTarget(s32,s32);void DeleteTouchCursor(void);void func_020bd104(void);s32 ConfirmCursorTile(s32,s32,s32,s32,s32);extern void *gTouchState;extern void **gCurrentMap;
if(IsTouchInputDisabled())return 0;
if(M2C_FIELD(gTouchState,u8 *,0x12)&&M2C_FIELD(gTouchState,u8 *,0x10)==20&&M2C_FIELD(*gCurrentMap,s16 *,0x52c2)==M2C_FIELD(*gCurrentMap,s16 *,0x52ca)&&M2C_FIELD(*gCurrentMap,s16 *,0x52c4)==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)){SelectCursorTarget(M2C_FIELD(*gCurrentMap,s16 *,0x52c2),M2C_FIELD(*gCurrentMap,s16 *,0x52c4));DeleteTouchCursor();return 1;}
if(M2C_FIELD(gTouchState,u8 *,0x16)&&M2C_FIELD(*gCurrentMap,s16 *,0x52c2)==M2C_FIELD(*gCurrentMap,s16 *,0x52ca)&&M2C_FIELD(*gCurrentMap,s16 *,0x52c4)==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)){func_020bd104();if(ConfirmCursorTile(M2C_FIELD(*gCurrentMap,s16 *,0x52c2),M2C_FIELD(*gCurrentMap,s16 *,0x52c4),1,0,0))return 1;}return 0;
}

s32 func_020bd650(void) {
    s32 IsTouchInputDisabled();
    extern void *gTouchState;
    if (IsTouchInputDisabled() != 0) {
        return 0x20;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x12) != 0) {
        return 0;
    }
    return 0x20;
}

s32 func_020bd684(void) {
    s32 IsTouchInputDisabled(void);
    void func_020bd104(void);
    s32 func_020d6398(s16, s16);
    void ScreenToMapPosition(u16, u16, s32 *);
    extern void *gTouchState;
    extern void **gCurrentMap;
    extern u8 data_02164d5d[];
    s32 pos[3];
    u16 x, y;
    void *base;
    s8 *row;

    x = M2C_FIELD(gTouchState, u16 *, 0);
    y = M2C_FIELD(gTouchState, u16 *, 2);
    if (IsTouchInputDisabled() != 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, 0x16) == 0) return 0;
    base = *gCurrentMap;
    if (M2C_FIELD(base, s16 *, 0x52C2) == M2C_FIELD(base, s16 *, 0x52CA) &&
        M2C_FIELD(base, s16 *, 0x52C4) == M2C_FIELD(base, s16 *, 0x52CC)) {
        func_020bd104();
        base = *gCurrentMap;
        if (func_020d6398(M2C_FIELD(base, s16 *, 0x52C2), M2C_FIELD(base, s16 *, 0x52C4)) == 0) {
            base = *gCurrentMap;
            row = M2C_FIELD((u8 *) base + M2C_FIELD(base, s16 *, 0x52C4) * 4, s8 **, 0x52E8);
            if (row[M2C_FIELD(base, s16 *, 0x52C2)] <= 0x6E) {
                goto ret20;
            }
        }
        if (((s32 (*)(u16, u16, s32 *)) ScreenToMapPosition)(x, y, pos) != 0) {
            data_02164d5d[0] = 1;
            return 0x10;
        }
    ret20:
        return 0x20;
    }
    return 0;
}

/* Track the stylus over the current selection: move the map cursor to the tile
 * under the finger and report the matching target's index, cycling the index
 * when the "next" button is tapped, and keep the touch cursor shown only while
 * the finger stays on the tile it pressed. */
void UpdateSelectionFromTouch(s32 *outIndex, s32 count) {
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    s32 IsTouchInputDisabled(void);
    s32 FindTargetIndexAt(s32, s32, s32);
    void CreateTouchCursor(s16, s16);
    void DeleteTouchCursor(void);
    s32 IsTouchOnNextButton(s32, s32);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 mapPos[3];
    u16 touchX;
    u16 touchY;
    s32 tileX;
    s32 tileY;
    void *map;
    s32 targetIndex;
    touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);
    if (IsTouchInputDisabled() != 0) return;
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) == 0) return;
    ScreenToMapPosition(touchX, touchY, mapPos);
    tileX = Divide(mapPos[0], MAP_TILE_SUBPIXEL);
    tileY = Divide(mapPos[1], MAP_TILE_SUBPIXEL);
    targetIndex = FindTargetIndexAt(count, tileX, tileY);
    if (targetIndex >= 0) {
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) = tileX;
        M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) = tileY;
        *outIndex = targetIndex;
    }
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_STARTED) != 0) {
        if (IsTouchOnNextButton(touchX, touchY)) {
            (*outIndex)++;
            if (*outIndex == count) {
                *outIndex = 0;
            }
        } else {
            M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_X) = tileX;
            M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_Y) = tileY;
            map = *gCurrentMap;
            CreateTouchCursor(M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_X), M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_Y));
        }
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_X) == tileX && M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_Y) == tileY) return;
    DeleteTouchCursor();
    M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_X) = 255;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_TOUCH_TILE_Y) = 255;
}

s32 FindTargetIndexAt(s32 n,s32 x,s32 y){void *GetTargetPosition(s32);s32 i;for(i=0;i<n;i++){void *p=GetTargetPosition(i);if(x==M2C_FIELD(p,s16 *,4)&&y==M2C_FIELD(p,s16 *,6))return i;}return -1;}

/* Returns an action code for the unit under the current cursor when it matches the selected tile. */
s32 GetTouchActionFlags(s32 unitIndex) {
    s32 IsTouchInputDisabled(void);
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    s32 IsTouchOnNextButton(s32, s32);
    void func_020bd104(void);
    s32 FindTargetIndexAt(s32, s32, s32);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 coords[3];
    u16 cursorX, cursorY;
    s32 tileX, tileY;
    s32 result;
    cursorX = M2C_FIELD(gTouchState, u16 *, 0);
    cursorY = M2C_FIELD(gTouchState, u16 *, 2);
    if (IsTouchInputDisabled() != 0) {
        return 0;
    }
    ScreenToMapPosition(cursorX, cursorY, coords);
    tileX = Divide(coords[0], 0x300);
    tileY = Divide(coords[1], 0x300);
    if (M2C_FIELD(gTouchState, u8 *, 0x16) == 0) {
        return 0;
    }
    if (IsTouchOnNextButton((s32) cursorX, (s32) cursorY) != 0) {
        return 0;
    }
    if (tileX == M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) &&
        tileY == M2C_FIELD(*gCurrentMap, s16 *, 0x52CC)) {
        func_020bd104();
        if (FindTargetIndexAt(unitIndex, tileX, tileY) >= 0) {
            result = 0x10;
        } else {
            result = 0x20;
        }
    } else {
        result = 0;
    }
    return result;
}

