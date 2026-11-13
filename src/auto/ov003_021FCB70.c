/* 24 functions from 0x021FCB70 to 0x021FD850 (ov003), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
/* Confirms the map selected in the map-list menu: reads the map id from the
 * current list page (or from the entity for non-list modes) and, depending on
 * the menu kind, starts it or plays the unavailable-map sound. */
void ConfirmMapSelection(void *entity) {
M2C_UNK PlaySoundEffect(s32);s32 IsCampaignMapAvailable(u16);
M2C_UNK func_ov006_022177c8(u16,void *);M2C_UNK func_ov006_02217c0c(u16,void *);M2C_UNK func_ov006_02217c30(u16,void *);
u16 mapId;s16 cursorRow;u8 pageIndex;u8 *pageBase;u32 menuKind=(u32)(M2C_FIELD(entity,u8 *,MENU_ENTITY_MODE)<<28)>>28;
if((u8)(menuKind==0)||(u8)(menuKind==2)||(u8)(menuKind==3)||(u8)(menuKind==4)||(u8)(menuKind==6)||(u8)(menuKind==7)||(u8)(menuKind==8)){
cursorRow=M2C_FIELD(M2C_FIELD(entity,void **,MENU_ENTITY_CURSOR),s32 *,0x14);pageIndex=M2C_FIELD(M2C_FIELD(entity,void **,MENU_ENTITY_PAGER),s32 *,4);
pageBase=M2C_FIELD(entity,u8 **,MENU_ENTITY_MAP_LIST)+(pageIndex<<9);
mapId=((u16 *)(pageBase+MENU_MAP_ENTRY_OFFSET))[(u16)cursorRow];
}else mapId=M2C_FIELD(entity,u16 *,MENU_ENTITY_MAP_ID);
if((u8)(menuKind==6)){
if(IsCampaignMapAvailable(mapId)){SetMenuPanelState(entity,1);func_ov006_022177c8(mapId,entity);PlaySoundEffect(0x1000d);return;}
PlaySoundEffect(0x1001d);return;
}
if((u8)(menuKind==7)){SetMenuPanelState(entity,2);func_ov006_02217c30(mapId,entity);PlaySoundEffect(0x1000d);return;}
if(!(u8)(menuKind==8))return;
SetMenuPanelState(entity,2);func_ov006_02217c0c(mapId,entity);PlaySoundEffect(0x1000d);
}
#pragma opt_common_subs reset
void func_ov003_021fcd10(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fcd24(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fcd30(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

/* Prepares an entity's display objects for the current mode: places the two
 * status sprites, sets their blend/palette state, configures the parts list,
 * switches the screen phase to 1, then re-applies the BG layers for the modes
 * that stay active. */
void SetupEntityDisplay(void *entity) {
    M2C_UNK func_02087d84(void *, M2C_UNK, s16, s16, s32, s32);
    M2C_UNK func_02088d94(void *);
    M2C_UNK func_02088da8(void *);
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02088f1c(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    M2C_UNK func_ov003_021f2008();
    s32 func_ov003_021f400c();
    s32 func_ov003_021f4064();
    void *part0;
    s16 posY;
    s16 posX;
    s32 isState2;
    s32 isState4a;
    s32 isState4b;
    s32 hasSubflag;
    s32 isState8;
    s32 isState0;
    s32 isState2b;
    s32 isState3;
    s32 isState4c;
    s32 isState6;
    s32 isState7;
    s32 tileId;
    s32 frame;
    u32 state;
    void *part18;
    void *second;
    void *part1C;
    void *first;
    void *parts;
    void *partsB;
    void *partsC;

    frame=func_ov003_021f153c();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = frame;
    M2C_FIELD(first, s16 *, 0x10) = 0;
    M2C_FIELD(first, s16 *, 0xC) = 0xC;
    M2C_FIELD(first, u16 *, 2) = (u16) M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = -0x20;
    M2C_FIELD(second, s16 *, 0x10) = 0;
    M2C_FIELD(second, s16 *, 0xC) = 0xC;
    M2C_FIELD(second, u16 *, 2) = (u16) M2C_FIELD(second, u16 *, 4);
    parts = M2C_FIELD(entity, void **, 0x68);
    if ((func_ov003_021f400c() == 0) && (func_ov003_021f4064() != 0)) {
        func_02088da8(M2C_FIELD(parts, void **, 0));
        func_02088da8(M2C_FIELD(parts, void **, 0xC));
        func_02088da8(M2C_FIELD(parts, void **, 0x10));
        func_02088da8(M2C_FIELD(parts, void **, 0x14));
    } else {
        func_02088f1c(M2C_FIELD(parts, void **, 0));
        func_02088f1c(M2C_FIELD(parts, void **, 0xC));
        func_02088f1c(M2C_FIELD(parts, void **, 0x10));
        func_02088f1c(M2C_FIELD(parts, void **, 0x14));
    }
    func_02088d94(M2C_FIELD(parts, void **, 0x18));
    part18 = M2C_FIELD(parts, void **, 0x18);
    M2C_FIELD(part18, s32 *, 0x40) = (s32) ((M2C_FIELD(part18, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(part18, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(part18, s8 *, 0x5A) = 0;
    func_02088d94(M2C_FIELD(parts, void **, 0x1C));
    part1C = M2C_FIELD(parts, void **, 0x1C);
    isState2 = 0;
    M2C_FIELD(part1C, s32 *, 0x40) = (s32) ((M2C_FIELD(part1C, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(part1C, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(part1C, s8 *, 0x5A) = 0;
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 2) {
        isState2 = 1;
    }
    if (isState2 & 0xFF) {
        func_02088f1c(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x20));
    }
    if ((s16) M2C_FIELD(M2C_FIELD(entity, void **, 0x60), s32 *, 0x10) == 0) {
        if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
            isState4a = 1;
        } else {
            isState4a = 0;
        }
        if (!(isState4a & 0xFF)) {
            partsB = M2C_FIELD(entity, void **, 0x68);
            func_02088da8(M2C_FIELD(partsB, void **, 0x10));
            func_02088da8(M2C_FIELD(partsB, void **, 0x14));
        }
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        isState4b = 1;
    } else {
        isState4b = 0;
    }
    if (isState4b & 0xFF) {
        func_02088f1c(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x24));
        func_02088f1c(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 4));
        func_02088da8(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0));
        part0 = M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0);
        func_02088e84(part0, 0xC0, 0xC0, 0xC0, 0xC0);
        if (M2C_FIELD(M2C_FIELD(part0, void **, 0x64), u8 *, 0x12) != 0) {
            hasSubflag = 1;
        } else {
            hasSubflag = 0;
        }
        if (hasSubflag & 0xFF) {
            posY = M2C_FIELD(part0, s16 *, 0x52);
            posX = M2C_FIELD(part0, s16 *, 0x50);
            tileId = func_020aae10(part0);
            func_02087d84(M2C_FIELD(part0, void **, 0x64), 1, posX, posY, (u16) tileId, (u16)func_020aae44(part0));
        }
    }
    partsC = M2C_FIELD(entity, void **, 0x6C);
    func_02088d94(M2C_FIELD(partsC, void **, 0));
    if ((func_ov003_021f400c() == 0) && (func_ov003_021f4064() != 0)) {
        M2C_FIELD(M2C_FIELD(partsC, void **, 0), s8 *, 0x59) = 0;
    }
    func_02088d94(M2C_FIELD(partsC, void **, 4));
    M2C_FIELD(entity, u8 *, 0x3B) = (u8) (M2C_FIELD(entity, u8 *, 0x3B) | 0x20);
    SetOv003SceneState(1);
    state = (u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C;
    if (state == 0) {
        isState0 = 1;
    } else {
        isState0 = 0;
    }
    if (!(isState0 & 0xFF)) {
        if (state == 2) {
            isState2b = 1;
        } else {
            isState2b = 0;
        }
        if (!(isState2b & 0xFF)) {
            if (state == 3) {
                isState3 = 1;
            } else {
                isState3 = 0;
            }
            if (!(isState3 & 0xFF)) {
                if (state == 4) {
                    isState4c = 1;
                } else {
                    isState4c = 0;
                }
                if (!(isState4c & 0xFF)) {
                    if (state == 6) {
                        isState6 = 1;
                    } else {
                        isState6 = 0;
                    }
                    if (!(isState6 & 0xFF)) {
                        if (state == 7) {
                            isState7 = 1;
                        } else {
                            isState7 = 0;
                        }
                        if (!(isState7 & 0xFF)) {
                            if (state == 8) {
                                isState8 = 1;
                            } else {
                                isState8 = 0;
                            }
                            if (!(isState8 & 0xFF)) {
                                return;
                            }
                            goto finish;
                        }
                        goto finish;
                    }
                    goto finish;
                }
                goto finish;
            }
            goto finish;
        }
        goto finish;
    }
finish:
    func_ov003_021f2008();
}

void func_ov003_021fd094(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd0a0(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

/* Refreshes an entity's display data: reinitializes its two display objects and then releases the pending handles stored in its part list (plus an extra handle when the low state nibble equals 2). */
void func_ov003_021fd0b4(void *entity) {
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s32 func_ov003_021f15d4();
    s16 func_ov003_021f1608();
    s16 displayValue;
    s32 flag;
    void *first;
    void *second;
    void *parts;

    displayValue = func_ov003_021f1608();
    first = M2C_FIELD(entity, void **, 0x58);
    M2C_FIELD(first, s16 *, 0xE) = GetSpriteAnimValue(first);
    M2C_FIELD(first, s16 *, 0x10) = displayValue;
    M2C_FIELD(first, s16 *, 0xC) = 12;
    M2C_FIELD(first, u16 *, 2) = M2C_FIELD(first, u16 *, 4);
    second = M2C_FIELD(entity, void **, 0x64);
    M2C_FIELD(second, s16 *, 0xE) = GetSpriteAnimValue(second);
    M2C_FIELD(second, s16 *, 0x10) = -32;
    M2C_FIELD(second, s16 *, 0xC) = 12;
    M2C_FIELD(second, u16 *, 2) = M2C_FIELD(second, u16 *, 4);
    if (!func_ov003_021f15d4()) {
        return;
    }
    parts = M2C_FIELD(entity, void **, 0x68);
    func_02088ff4(M2C_FIELD(parts, s32 *, 0));
    func_02088ff4(M2C_FIELD(parts, s32 *, 4));
    func_02088ff4(M2C_FIELD(parts, s32 *, 8));
    func_02088ff4(M2C_FIELD(parts, s32 *, 12));
    func_02088ff4(M2C_FIELD(parts, s32 *, 16));
    func_02088ff4(M2C_FIELD(parts, s32 *, 20));
    if (((u32)(M2C_FIELD(entity, u8 *, 0x3b) << 28) >> 28) == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag & 255) {
        func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 32));
    }
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x6c), s32 *, 4));
}

void func_ov003_021fd18c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021fd1a0(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x58);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021fd1cc(void) {
    M2C_UNK func_ov003_021f66d4();
    func_ov003_021f66d4();
}

void func_ov003_021fd1d8(void) {
    M2C_UNK func_ov003_021f6724();
    func_ov003_021f6724();
}

void func_ov003_021fd1e4(void) {
    M2C_UNK func_ov003_021f8c20();
    func_ov003_021f8c20();
}

void func_ov003_021fd1f0(void *arg0) {
    s32 IsLinkSessionActive();
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK func_ov003_021f152c(M2C_UNK);
    s32 func_ov003_021f153c();
    M2C_UNK func_ov003_022006dc(M2C_UNK);
    M2C_UNK func_ov006_02217178(void *);
    s32 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        return;
    }
    if (IsLinkSessionActive() == 0) {
        return;
    }
    if (func_ov003_021f153c() != 0) {
        return;
    }
    func_ov003_021f152c(1);
    SetOv003SceneState(1);
    func_ov003_022006dc(1);
    func_ov006_02217178(arg0);
}

u8 func_ov003_021fd250(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_021fd270(void *arg0) {
    s32 a, b, c, result;
    u32 value;
    s32 either;
    result = 1;
    either = 1;
    value = (u32)(M2C_FIELD(arg0, u8 *, 0x3B) << 28) >> 28;
    if (value == 6) a = 1; else a = 0;
    if (!(a & 0xFF)) {
        if (value == 7) b = 1; else b = 0;
        if (!(b & 0xFF)) either = 0;
    }
    if (either == 0) {
        if (value == 8) c = 1; else c = 0;
        if (!(c & 0xFF)) result = 0;
    }
    return result;
}

/* Clears the low state bits of an entity, switches it to state 4 handling, and updates its display lists/palette. */
void func_ov003_021fd2d0(void *entity) {
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_020893a8(s32, s32, M2C_UNK, s32);
    M2C_UNK SetTextById(s32, s32);
    s32 func_020ae22c(M2C_UNK);
    M2C_UNK SetMenuPanelState(void *, M2C_UNK);
    M2C_UNK func_ov006_02217840(void *);
    M2C_UNK func_ov006_02217c74(void *);
    M2C_UNK func_ov006_02217cb8(void *);
    extern void *gCur3DSpriteEngine;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;

    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 6) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        func_ov006_02217840(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 8) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 & 0xFF) {
        func_ov006_02217c74(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 7) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        func_ov006_02217cb8(entity);
    }
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3B) << 0x1C) >> 0x1C) == 4) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (!(var_r0_4 & 0xFF)) {
        return;
    }
    M2C_FIELD(entity, u8 *, 0x3E) = (u8) (M2C_FIELD(entity, u8 *, 0x3E) & ~7);
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x20, 3, 7);
    if (((u32) (M2C_FIELD(entity, u8 *, 0x3E) << 0x18) >> 0x1F) != 0) {
        SetMenuPanelState(entity, 4);
    }
    SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24), 0x10, 3, 6);
    SetTextById(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 4), 0x4700001D);
    func_02088ff4(M2C_FIELD(M2C_FIELD(entity, void **, 0x68), s32 *, 8));
    func_020893a8(M2C_FIELD(M2C_FIELD(entity, void **, 0x6C), s32 *, 0), 0x8B80, 1, func_020ae22c(0x11));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_ov003_021fd430(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd444(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd450(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd45c(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

void func_ov003_021fd470(void) {
    M2C_UNK func_ov003_021f676c();
    func_ov003_021f676c();
}

void func_ov003_021fd47c(void) {
    M2C_UNK func_ov003_021f7164();
    func_ov003_021f7164();
}

void func_ov003_021fd488(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *MemAlloc(s32);
    M2C_UNK func_020a9188(void *, M2C_UNK);
    M2C_UNK SetTextSpriteValue(void *, M2C_UNK);
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK data_02156cdc;
    extern void **data_027e0058;
    extern M2C_UNK data_ov003_0220f47c;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220ff2c;
    extern M2C_UNK data_ov003_022100d4;
    extern M2C_UNK data_ov003_02210104;
    extern M2C_UNK data_ov003_02210130;
    u8 temp_ip;
    u8 temp_r5;
    u8 var_r0;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r5_2;
    void *temp_r5_3;

    func_ov003_021f13ec(&data_ov003_0220ff2c);
    temp_r0 = func_01ffa3dc(&data_ov003_0220ff2c, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov003_02210104;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_02210130;
        M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
        M2C_FIELD(temp_r0, u8 *, 0x39) = (u8) ((M2C_FIELD(temp_r0, u8 *, 0x39) & ~0x7F) | 0xA);
        M2C_FIELD(temp_r0, u8 *, 0x3A) = (u8) ((u8) (M2C_FIELD(temp_r0, u8 *, 0x3A) & ~0x7F) | 0x80);
        temp_ip = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF) & ~0x20;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = temp_ip;
        M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) ((u8) (temp_ip & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, u16 *, 0x3C) = (u16) M2C_FIELD(*data_027e0058, u16 *, 0x5142);
        temp_r5 = ((u8) ((M2C_FIELD(temp_r0, u8 *, 0x3E) & ~7) | 2) & ~0x38) | 0x38;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = temp_r5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) ((u8) (temp_r5 & ~0x40) & ~0x80);
        M2C_FIELD(temp_r0, void **, 0x44) = NULL;
        M2C_FIELD(temp_r0, M2C_UNK **, 0x48) = &data_02156cdc;
        M2C_FIELD(temp_r0, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0, void **, 0x50) = NULL;
        M2C_FIELD(temp_r0, void **, 0x54) = NULL;
        M2C_FIELD(temp_r0, s32 *, 0x58) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x68) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x70) = 0;
        temp_r0_2 = MemAlloc(0x187C);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_ov003_022100d4;
            M2C_FIELD(temp_r0_2, M2C_UNK **, 4) = &data_ov003_0220f47c;
            var_r0 = 0;
            do {
                temp_r2 = temp_r0_2 + (var_r0 * 2);
                M2C_FIELD(temp_r2, u16 *, 0x12) = 0xFFFFU;
                var_r0 += 1;
                M2C_FIELD(temp_r2, u16 *, 8) = (u16) M2C_FIELD(temp_r2, u16 *, 0x12);
            } while ((u32) var_r0 < 5U);
            M2C_FIELD(temp_r0_2, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r0_2, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = 0U;
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0U;
            M2C_FIELD(temp_r0_2, s16 *, 0x22) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x28) = 1;
            M2C_FIELD(temp_r0_2, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_r0_2, s16 *, 0x2C) = 0;
            M2C_FIELD(temp_r0_2, u16 *, 0x1E) = (u16) M2C_FIELD(temp_r0_2, u16 *, 0x20);
            func_020a9188(temp_r0_2 + 0x1C, 0x69);
            M2C_FIELD(temp_r0_2, u16 *, 0x20) = 0xC000U;
            M2C_FIELD(temp_r0_2, s16 *, 0x24) = 8;
            M2C_FIELD(temp_r0_2, s16 *, 0x26) = 8;
        }
        M2C_FIELD(temp_r0, void **, 0x44) = temp_r0_2;
        temp_r0_3 = MemAlloc(0x2C);
        if (temp_r0_3 != NULL) {
            M2C_FIELD(temp_r0_3, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_3, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_3, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_3, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_3, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_3, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_3, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_3, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_3, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_3, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_3, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x50) = temp_r0_3;
        M2C_FIELD(temp_r0_3, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x50), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x50), 0);
        temp_r2_2 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r2_3 = M2C_FIELD(temp_r0, void **, 0x50);
        M2C_FIELD(temp_r2_3, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_3, u8 *, 0x28) & ~0xE0) | 0x20);
        temp_r0_4 = MemAlloc(0x2C);
        if (temp_r0_4 != NULL) {
            M2C_FIELD(temp_r0_4, M2C_UNK **, 0) = &gHeapObjectVTable;
            M2C_FIELD(temp_r0_4, s8 *, 4) = 0;
            M2C_FIELD(temp_r0_4, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r0_4, s8 *, 0x14) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x15) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x16) = 1;
            M2C_FIELD(temp_r0_4, s8 *, 0x17) = 8;
            M2C_FIELD(temp_r0_4, s8 *, 0x18) = 8;
            M2C_FIELD(temp_r0_4, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_4, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
            M2C_FIELD(temp_r0_4, s8 *, 0x21) = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x24) = 0;
            M2C_FIELD(temp_r0_4, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_4, u8 *, 0x28) & ~0xE0);
            M2C_FIELD(temp_r0_4, s8 *, 0x29) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x54) = temp_r0_4;
        M2C_FIELD(temp_r0_4, s8 *, 0x16) = 2;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x14) = 8;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x17) = 8;
        SetTextSpriteValue(M2C_FIELD(temp_r0, void **, 0x54), 0);
        temp_r5_2 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r5_2, u8 *, 0x20) & ~0xE0) | 0x40);
        temp_r5_3 = M2C_FIELD(temp_r0, void **, 0x54);
        M2C_FIELD(temp_r5_3, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r5_3, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s16 *, 0x12) = 0x270;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x54), s8 *, 0x21) = 9;
        temp_r0_5 = MemAlloc(8);
        if (temp_r0_5 != NULL) {
            M2C_FIELD(temp_r0_5, s32 *, 0) = 0;
            M2C_FIELD(temp_r0_5, s32 *, 4) = 0;
        }
        M2C_FIELD(temp_r0, void **, 0x6C) = temp_r0_5;
        M2C_FIELD(temp_r0, u8 *, 0x3E) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3E) | 0x80);
    }
    M2C_FIELD(temp_r0, u8 *, 0x3B) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x3B) & ~0xF);
}

