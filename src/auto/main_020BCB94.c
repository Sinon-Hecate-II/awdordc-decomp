/* 30 functions from 0x020BCB94 to 0x020BDA88 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"

/* The map action the key pressed this frame asks for: B cancels before A
 * confirms, then R opens the map menu and X closes the aiming cursor. */
s32 GetKeyActionFlags(void) {
    extern void *gKeyState;
    u16 pressed = ((KeyState *)gKeyState)->pressed;

    if (pressed & KEY_B) return MAP_ACTION_CANCEL;
    if (pressed & KEY_A) return MAP_ACTION_CONFIRM;
    if (pressed & KEY_R) return MAP_ACTION_MENU;
    if (pressed & KEY_X) return MAP_ACTION_CLOSE;
    return 0;
}

/* The cursor-cycle direction the auto-repeating keys ask for this frame: right or
 * down cycles to the next directional-cursor option, left or up to the previous. */
s32 GetCursorCycleKey(void) {
    extern void *gKeyState;
    u16 repeat;

    repeat = ((KeyState *)gKeyState)->repeat;
    if (repeat & (KEY_DOWN | KEY_RIGHT)) {
        return MAP_CURSOR_CYCLE_NEXT;
    }
    if (repeat & (KEY_UP | KEY_LEFT)) {
        return MAP_CURSOR_CYCLE_PREV;
    }
    return 0;
}

/* Cursor-settle key check, the key counterpart of GetMapSettleTouchAction:
 * MAP_ACTION_CANCEL (nonzero) once the B key that picked the tile is released,
 * 0 while it is still held down from a previous frame. */
s32 GetMapSettleKeyAction(void) {
    extern void *gKeyState;
    if (((KeyState *)gKeyState)->pressed & KEY_B) {
        return MAP_ACTION_CANCEL;
    }
    if (((KeyState *)gKeyState)->held & KEY_B) {
        return 0;
    }
    return MAP_ACTION_CANCEL;
}

/* The map-cursor action the key pressed this frame asks for, in priority order:
 * A confirms, B cancels, R opens the map menu and X closes the aiming cursor. */
s32 GetMapCursorKeyAction(void) {
    extern void *gKeyState;
    u16 pressed;

    pressed = M2C_FIELD(gKeyState, u16 *, 0);
    if (pressed & KEY_A) {
        return MAP_ACTION_CONFIRM;
    }
    if (pressed & KEY_B) {
        return MAP_ACTION_CANCEL;
    }
    if (pressed & KEY_R) {
        return MAP_ACTION_MENU;
    }
    if (pressed & KEY_X) {
        return MAP_ACTION_CLOSE;
    }
    return 0;
}

/* Spawn the current player's army-specific "special" reveal sprite at (x,y)
 * under `parent` and play its sound: armies 2 and 9 use the special_rec class,
 * army 8 special_def, every other army special_mini. */
void SpawnArmySpecialEffect(u8 x, u8 y, M2C_UNK arg2, M2C_UNK arg3, s32 parent) {
    void PlaySoundAtTile(s32, u8, u8);
    void CreateEffectMapSprite(void *, u8, u8, s32, s32, s32, s32);
    extern void **gCurrentMap;
    extern M2C_UNK sSpecialRecSprite, sSpecialDefSprite, sSpecialMiniSprite;
    s32 sprite;
    void *base;

    base = *gCurrentMap;
    sprite = M2C_FIELD(M2C_FIELD(base, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE + base, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE);
    switch ((u32)(sprite << 24) >> 24) {
    case 2:
    case 9:
        CreateEffectMapSprite(&sSpecialRecSprite, x, y, 0, 0, 0, parent);
        PlaySoundAtTile(0x12a, x, y);
        break;
    case 8:
        CreateEffectMapSprite(&sSpecialDefSprite, x, y, 0, 0, 0, parent);
        PlaySoundAtTile(0x12b, x, y);
        break;
    default:
        CreateEffectMapSprite(&sSpecialMiniSprite, x, y, 0, 0, 0, parent);
        PlaySoundAtTile(0x129, x, y);
        break;
    }
}

/* Show the army- and variant-specific dialog for a player's unit-view object. */
void ShowPlayerUnitDialog(void *unitView) {
    extern void **gCurrentMap;
    extern u8 data_021261a0[];
    void ShowPlayerUnitDialogSequence(s32);
    u32 armyId;

    armyId = (u32)(M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(unitView, s32 *, PLAYER_UNIT_VIEW_PLAYER) * MAP_PLAYER_STRIDE, s32 *, MAP_PLAYER_STATES + PLAYER_REC_SPRITE) << 24) >> 24;
    ShowPlayerUnitDialogSequence(M2C_FIELD(data_021261a0 + armyId * 0x9c, s32 *, M2C_FIELD(unitView, s32 *, PLAYER_UNIT_VIEW_VARIANT) * 4));
}

void func_020bcde0(void) {
    M2C_UNK func_020c4764();
    func_020c4764();
}

void func_020bcdec(void *arg0) {
    M2C_UNK ChangeMusicTrackWithFade();
    M2C_UNK GetCoPowerMusicTrack(u8);
    GetCoPowerMusicTrack((u8) M2C_FIELD(arg0, s32 *, 0x5C));
    ChangeMusicTrackWithFade();
}

/* Play the special sound and spawn the "special" effect sprite at the tile of
 * the unit under the map cursor, parented to `parent`. */
void SpawnCursorUnitSpecialEffect(s32 parent) {
    void PlaySoundAtTile(s32, u8, u8);
    void CreateEffectMapSprite(void *, u8, u8, s32, s32, s32, s32);
    extern u8 sSpecialSprite[];
    extern void **gCurrentMap;
    void *unit;

    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    PlaySoundAtTile(0x128, M2C_FIELD(unit, u8 *, 1), M2C_FIELD(unit, u8 *, 2));
    unit = M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    CreateEffectMapSprite(sSpecialSprite, M2C_FIELD(unit, u8 *, 1), M2C_FIELD(unit, u8 *, 2), 0, 0, 0, parent);
}

/* Select the sprite set stored at view+0x64 on the player record, then call the
 * player's army handler that creates its unit-view sprite (the rotating display
 * of that player's units). */
void CreatePlayerUnitViewSprite(void *view) {
    extern void **gCurrentMap;
    extern u8 gArmyUnitViewCreate[];
    void SetPlayerSpriteSet(s32, s32);
    s32 player = M2C_FIELD(view, s32 *, 0x5c);
    s32 spriteSet = M2C_FIELD(view, s32 *, 0x64);
    u32 armyId;

    SetPlayerSpriteSet(player, spriteSet);
    armyId = (u32)(M2C_FIELD((u8 *)*gCurrentMap + player * 0x8c, s32 *, 0x6810) << 24) >> 24;
    (*(void (**)(s32, void *))(gArmyUnitViewCreate + armyId * 0x9c + spriteSet * 0x28))(player, view);
}

/* Final step of the on-map player unit view: advance the player's sprite state,
 * consume the dual CO power cost from its meter, clear its sprite aux bits, then
 * reload the UI graphics and refresh the map view. */
void FinishPlayerUnitView(void *view) {
    M2C_UNK AdvancePlayerSpriteState(s32);
    M2C_UNK ConsumeDualCoPowerCost(s32);
    M2C_UNK SetPlayerSpriteAuxBits(s32, M2C_UNK);
    M2C_UNK LoadUiGraphics();
    M2C_UNK RefreshMapView();
    s32 player;

    player = M2C_FIELD(view, s32 *, PLAYER_UNIT_VIEW_PLAYER);
    AdvancePlayerSpriteState(player);
    ConsumeDualCoPowerCost(player);
    SetPlayerSpriteAuxBits(player, 0);
    LoadUiGraphics();
    RefreshMapView();
}

/* Create the on-map display of one player's units (the rotating unit-view sprite)
 * and start it on `player` with a random model variant. */
void CreatePlayerUnitView(s32 player) {
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    s32 NextRandomValue(void);
    extern M2C_UNK gPlayerUnitViewClass;
    void *view = CreateSpriteFromClass(&gPlayerUnitViewClass, 7);

    M2C_FIELD(view, s32 *, PLAYER_UNIT_VIEW_PLAYER) = player;
    M2C_FIELD(view, s32 *, 0x60) = 0;
    M2C_FIELD(view, s32 *, PLAYER_UNIT_VIEW_SET) = 1;
    M2C_FIELD(view, s32 *, PLAYER_UNIT_VIEW_VARIANT) = NextRandomValue() % 6;
}

/* Aim the map cursor at the tile under the stylus: turn the current touch point
 * into map pixel coordinates, divide by a tile's size, clamp it to the map and,
 * when the touch just began, also mark the tile the press started on. */
void UpdateMapCursorFromTouch(void){extern void *gTouchState;extern void **gCurrentMap;s32 IsTouchInputDisabled(void);void ScreenToMapPosition(u16,u16,s32 *);s32 Divide(s32,s32);void ClampCursorToMap(void);
s32 pos[3];u16 x=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_X),y=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_Y);
if(IsTouchInputDisabled())return;if(!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))return;
ScreenToMapPosition(x,y,pos);
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=Divide(pos[0],MAP_TILE_SIZE);
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=Divide(pos[1],MAP_TILE_SIZE);
ClampCursorToMap();if(!M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED))return;
M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_X)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X);
M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_Y)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y);
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

/* Per-frame touch-cursor update: once the cursor has been shown for 8 frames,
 * resume its animation; until then, keep counting the delay up. */
void TouchCursor_Update(void *cursor) {
    M2C_UNK Sprite_ResumeAnimation();
    s16 delay;

    delay = M2C_FIELD(cursor, s16 *, 0x4C);
    if ((s32) delay >= 8) {
        Sprite_ResumeAnimation();
        return;
    }
    if ((s32) delay < 8) {
        M2C_FIELD(cursor, s16 *, 0x4C) = (s16) (delay + 1);
    }
}

/* Create the touch cursor's sprite at screen position (x, y); an existing cursor
 * is left alone, only one is allowed at a time. */
void CreateTouchCursor(s16 x, s16 y) {
    extern M2C_UNK gTouchCursorClass;
    s32 FindObjectByClass(M2C_UNK *);
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    void *cursor;

    if (FindObjectByClass(&gTouchCursorClass)) return;
    cursor = CreateSpriteFromClass(&gTouchCursorClass, 7);
    M2C_FIELD(cursor, s32 *, 0x34) = x;
    M2C_FIELD(cursor, s32 *, 0x38) = y;
}

/* Remove the touch cursor's sprite, if one exists. */
void DeleteTouchCursor(void) {
    extern M2C_UNK gTouchCursorClass;
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);

    if (!FindObjectByClass(&gTouchCursorClass)) return;
    DeleteSpriteObjectsOfClass(&gTouchCursorClass);
}

void HideTouchCursor(void) {
    M2C_UNK ResumeAnimationOfSpriteClass(M2C_UNK *);
    extern M2C_UNK gTouchCursorClass;
    ResumeAnimationOfSpriteClass(&gTouchCursorClass);
}

/* TRUE while the touch cursor sprite exists (CreateTouchCursor makes it). */
u8 IsTouchCursorActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gTouchCursorClass;
    u8 active;

    if (FindObjectByClass(&gTouchCursorClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* Key action of a stylus touch on the battle map for the cursor mode: the
 * on-screen direction buttons (up 0x70..0x90, down 0xA0..0xC0, left 0x40..0x60
 * when enabled) give their key, or 4096 when the touch just started on them;
 * 0 when touch input is off. */
s32 func_020bd13c(s32 enableLeftButton){extern void *gTouchState;s32 IsTouchInputDisabled(void);s32 IsTouchOnMiddleButton(s32,s32);s32 IsTouchOnMapMenuButton(s32,s32);s32 IsTouchOnLeftButton(s32,s32);
u16 x=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_X),y=M2C_FIELD(gTouchState,u16 *,TOUCH_CUR_Y);
if(IsTouchInputDisabled())return 0;if(!M2C_FIELD(gTouchState,u8 *,TOUCH_ACTIVE))return 0;
if(IsTouchOnMiddleButton(x,y)){if(M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED))return 16;return 4096;}
if(IsTouchOnMapMenuButton(x,y)){if(M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED))return 256;return 4096;}
if(enableLeftButton&&IsTouchOnLeftButton(x,y)){if(M2C_FIELD(gTouchState,u8 *,TOUCH_STARTED))return 64;return 32;}return 4096;
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

/* Touch handler of the battle-map cursor mode: while the stylus stays on the
 * tile the press started on, lifting it selects that tile (after 20 frames of
 * touch) and a touch stroke confirms it. Returns 1 when the touch was used. */
s32 HandleMapTouchRelease(void){s32 IsTouchInputDisabled(void);void SelectCursorTarget(s32,s32);void DeleteTouchCursor(void);void HideTouchCursor(void);s32 ConfirmCursorTile(s32,s32,s32,s32,s32);extern void *gTouchState;extern void **gCurrentMap;
if(IsTouchInputDisabled())return 0;
if(M2C_FIELD(gTouchState,u8 *,0x12)&&M2C_FIELD(gTouchState,u8 *,0x10)==20&&M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)==M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_X)&&M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)==M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_Y)){SelectCursorTarget(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y));DeleteTouchCursor();return 1;}
if(M2C_FIELD(gTouchState,u8 *,0x16)&&M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)==M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_X)&&M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)==M2C_FIELD(*gCurrentMap,s16 *,MAP_TOUCH_TILE_Y)){HideTouchCursor();if(ConfirmCursorTile(M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X),M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y),1,0,0))return 1;}return 0;
}

/* Selection-settle touch check: MAP_ACTION_CANCEL (nonzero) once the stylus is up
 * or touch input is off, and 0 while a touch is being held. */
s32 GetMapSelectionTouchAction(void) {
    s32 IsTouchInputDisabled();
    extern void *gTouchState;
    if (IsTouchInputDisabled() != 0) {
        return MAP_ACTION_CANCEL;
    }
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_ACTIVE) != 0) {
        return 0;
    }
    return MAP_ACTION_CANCEL;
}

/* Translate a stylus release on the tile the press started on into an action:
 * A-like (0x10) when that tile holds a unit the cursor cannot move to,
 * otherwise B-like (0x20); 0 while the touch is elsewhere or still down. */
s32 GetTouchReleaseKeyAction(void) {
    s32 IsTouchInputDisabled(void);
    void HideTouchCursor(void);
    s32 CanMoveCursorTo(s16, s16);
    void ScreenToMapPosition(u16, u16, s32 *);
    extern void *gTouchState;
    extern void **gCurrentMap;
    extern u8 gTouchConfirmFlag[];
    s32 pos[3];
    u16 touchX, touchY;
    void *map;
    s8 *row;

    touchX = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_X);
    touchY = M2C_FIELD(gTouchState, u16 *, TOUCH_CUR_Y);
    if (IsTouchInputDisabled() != 0) return 0;
    if (M2C_FIELD(gTouchState, u8 *, TOUCH_RELEASED) == 0) return 0;
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X) == M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_X) &&
        M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y) == M2C_FIELD(map, s16 *, MAP_TOUCH_TILE_Y)) {
        HideTouchCursor();
        map = *gCurrentMap;
        if (CanMoveCursorTo(M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y)) == 0) {
            map = *gCurrentMap;
            row = M2C_FIELD((u8 *) map + M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_Y) * 4, s8 **, MAP_GRID);
            if (row[M2C_FIELD(map, s16 *, MAP_CURSOR_TARGET_X)] <= MAP_GRID_NO_UNIT_MAX) {
                goto ret20;
            }
        }
        if (((s32 (*)(u16, u16, s32 *)) ScreenToMapPosition)(touchX, touchY, pos) != 0) {
            gTouchConfirmFlag[0] = 1;
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

/* Index of the target at tile (x,y) among the first `count` entries of the battle
 * map's target list, or -1 when no target sits there. */
s32 FindTargetIndexAt(s32 count, s32 x, s32 y) {
    void *GetTargetPosition(s32);
    s32 i;

    for (i = 0; i < count; i++) {
        MapTargetEntry *target = GetTargetPosition(i);
        if (x == target->x && y == target->y) return i;
    }
    return -1;
}

/* Returns an action code for the unit under the current cursor when it matches the selected tile. */
s32 GetTouchActionFlags(s32 unitIndex) {
    s32 IsTouchInputDisabled(void);
    void ScreenToMapPosition(u16, u16, s32 *);
    s32 Divide(s32, s32);
    s32 IsTouchOnNextButton(s32, s32);
    void HideTouchCursor(void);
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
        HideTouchCursor();
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

