/* 4 functions from 0x021E1500 to 0x021E16EC (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021e1500(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

void func_ov003_021e1518(M2C_UNK arg0) {
    M2C_UNK Link_CreateStartRequest(s32, M2C_UNK);
    Link_CreateStartRequest(0x4D4C5342, arg0);
}

/* Sets up one slot of the table pointed at by state: allocates/recycles an entry via
   FindObjectByZ for the normal case, or updates a sub-object when id == 10. */
void func_ov003_021e1530(void *state, s32 id) {
    u8 count;
    s16 value;
    s16 id16;
    s32 freeCount;
    void *entry;
    M2C_FIELD(state, s32 *, 0x38) = FindObjectByZ(id);
    if (id != 10) {
        M2C_FIELD(state, u8 *, 7) = Modulo(id, 5);
        M2C_FIELD(state, u8 *, 8) = Divide(id, 5);
        id16 = id;
        M2C_FIELD(state, u8 *, 6) = id;
        if (func_ov003_021e1500(id16, 0, 4)) M2C_FIELD(state, u8 *, 9) = id;
        if (func_ov003_021e1500(id16, 5, 9)) M2C_FIELD(state, u8 *, 10) = id - 5;
        return;
    }
    if (id != 10) return;
    freeCount = func_ov003_021f2560();
    count = M2C_FIELD(state, u8 *, 11);
    if (freeCount && M2C_FIELD(state, u8 *, 8) == 0) {
        count = freeCount - 1;
        value = 0;
    } else {
        if (!count) return;
        if (M2C_FIELD(state, u8 *, 8) != 1) return;
        count += 4;
        value = 5;
    }
    entry = state + id * 4;
    M2C_FIELD(M2C_FIELD(entry, void **, 12), s16 *, 0x68) = count;
    M2C_FIELD(M2C_FIELD(entry, void **, 12), s16 *, 0x6A) = value;
}

/* Update the map grid's eleven button sprites and latch the button that reports
 * a click (MAPGRID_CLICKED) and the one showing its pressed frame
 * (MAPGRID_PRESSED); the handler then moves the preview onto the pressed
 * button.  A button is clicked when its owner says so, or when the button is
 * enabled and its owner is being pressed. */
void Ov003_UpdateMapGridButtons(void *menu) {
    M2C_UNK MenuSpriteUpdate(s32);
    s32 clicked;
    s32 pressed;
    u8 index;
    void *sprite;
    void *owner;
    void *button;

    M2C_FIELD(menu, s8 *, MAPGRID_CLICKED) = -1;
    M2C_FIELD(menu, s8 *, MAPGRID_PRESSED) = -1;
    index = 0;
    do {
        sprite = M2C_FIELD((void *)((u8 *) menu + (index * 4)), void **, MAPGRID_BUTTONS);
        if (sprite) {
            MenuSpriteUpdate((s32) sprite);
            button = M2C_FIELD((menu + (index * 4)), void **, MAPGRID_BUTTONS);
            clicked = 1;
            owner = M2C_FIELD(button, void **, MENU_SPRITE_OWNER);
            if ((M2C_FIELD(owner, s8 *, 0x0b) != 1) && ((((u32) (M2C_FIELD(button, u8 *, MENU_SPRITE_BASE) << 0x1B) >> 0x1F) == 0) || (M2C_FIELD(owner, s8 *, 0x0c) != 1))) {
                clicked = 0;
            }
            if (clicked & 0xFF) {
                M2C_FIELD(menu, u8 *, MAPGRID_CLICKED) = index;
            }
            sprite = M2C_FIELD(&((u8 *) menu)[index * 4], void **, MAPGRID_BUTTONS);
            if ((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) == (u16) ((u32) (M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) << 6) >> 0x18)) {
                pressed = 1;
            } else {
                pressed = 0;
            }
            if (pressed & 0xFF) {
                M2C_FIELD(menu, u8 *, MAPGRID_PRESSED) = index;
            }
        }
        index++;
    } while ((u32) index < 11U);
}

