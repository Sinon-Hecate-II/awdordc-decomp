/* 17 functions from 0x02179E74 to 0x0217AE38 (ov001), found by ds-decomp. */
#include "common.h"
void func_ov001_0217a880(void);

void func_ov001_02179e74(void) {
    extern s8 data_ov001_02193d94;
    void func_ov001_02179dc8(void);
    M2C_FIELD(&data_ov001_02193d94,u8 *,0) = M2C_FIELD(&data_ov001_02193d94,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193d94,u8 *,0) < 120U) return;
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02179dc8);
}

void func_ov001_02179ea8(void) {
    extern M2C_UNK gMapSelectState;
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_GetNameEntryMode(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov001_02184170(M2C_UNK);
    void InitMapSelectGraphics(void);
    void func_ov001_021722ac(void);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02171dd0(M2C_UNK);
    void func_ov001_0217a0d4(void);
    void func_ov001_0217a17c(void);
    M2C_UNK CreateTextPanel(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0217ac18(void);
    void func_ov001_0217b130(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_0217b0d4(void);
    void func_ov001_0217a2f0(void);
    s32 temp;

    M2C_FIELD(&gMapSelectState, void **, 4) = func_ov001_0218b6f8((M2C_UNK)0x5c, (M2C_UNK)4);
    Ov001_GetNameEntryMode(&temp, 0);
    if (temp == 0) {
        M2C_FIELD(&gMapSelectState, u8 *, 0) = 0;
        M2C_FIELD(&gMapSelectState, u16 *, 2) = 0;
    }
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51) =
            (u8)func_ov001_02184170(M2C_FIELD(&gMapSelectState, void **, 4));
        InitMapSelectGraphics();
        func_ov001_021722ac();
        func_ov001_02171c24((M2C_UNK)0x34, (M2C_UNK)(0x34 - 0x35), (M2C_UNK)0);
        func_ov001_02171dd0((M2C_UNK)2);
        func_ov001_0217a0d4();
        func_ov001_0217a17c();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0xc) = (s32)CreateTextPanel((M2C_UNK)0, (M2C_UNK)0);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0x3c) =
        (s32)func_ov001_0218c884((M2C_UNK)1, (M2C_UNK)func_ov001_0217b0d4, (M2C_UNK)0, (M2C_UNK)0x6e);
    func_ov001_0217ac18();
    func_ov001_0217b130();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217a2f0);
}

/* Set up the map-select screen's graphics: load the list-background tilemap and
 * the step-31 background tiles into VRAM, upload the tilemap, then point the
 * layered background control registers at the new layers. */
void InitMapSelectGraphics(void) {
    s32 Ov001_LocalizePath(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02183694(M2C_UNK);
    M2C_UNK func_ov001_02183720(void);
    extern M2C_UNK sXb4ApListBackNscPath;
    extern M2C_UNK sYbBgStep31NclPath;
    extern M2C_UNK sJb4ApListNscPath;
    extern M2C_UNK func_020044ec;
    extern M2C_UNK gMapSelectState;
    typedef struct { u8 bytes[25]; } ListBackPath;
    typedef struct { u8 bytes[22]; } BgStep31Path;
    ListBackPath listBackPath = *(ListBackPath *)&sXb4ApListBackNscPath;
    BgStep31Path bgStep31Path = *(BgStep31Path *)&sYbBgStep31NclPath;
    Ov001_LoadAsset(&sJb4ApListNscPath, &func_020044ec);
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 4) =
        Ov001_LoadFile(Ov001_LocalizePath(&listBackPath), 0, 4);
    func_ov001_02183694(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 4));
    func_ov001_02183720();
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 8) =
        Ov001_LoadFile(Ov001_LocalizePath(&bgStep31Path), 0, 4);
    /* sub BG0/BG1 and main BG0/BG1: 256-colour tiled layers */
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x04000008, u16 *, 0) = (M2C_FIELD((void *)0x04000008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 4) = (M2C_FIELD((void *)0x0400000A, u16 *, 4) & ~3) | 2;
}

void func_ov001_0217a0d4(void) {
    s32 func_02002088(s32, u16);
    M2C_UNK func_ov001_021838a8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK gMapSelectState;
    s32 var_r0;
    s32 var_r4;
    u8 temp_r1;

    var_r0 = 0;
    M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u16 *, 0x40) = (u16)((M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51) - 4) * 0x1c);
    temp_r1 = M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51);
    if ((u32)temp_r1 <= 4U) {
        var_r4 = var_r0;
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53) = var_r0;
    } else if ((u32)temp_r1 <= 8U) {
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53) = 0x1f;
        var_r4 = 1;
    } else {
        M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53) = 0x37;
        var_r4 = 2;
    }
    if (var_r4 != 0) {
        var_r0 = func_02002088(M2C_FIELD(&gMapSelectState, u16 *, 2) * M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u16 *, 0x40));
    }
    func_ov001_021838a8(var_r4, 0x55, 0xec, 0x3f, var_r0);
}

#pragma opt_common_subs off
void func_ov001_0217a17c(void) {
void *func_ov001_0218a5f0(M2C_UNK, M2C_UNK);
void Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK gMapSelectState;
extern u8 data_ov001_0218f814[];
extern u8 data_ov001_0218f818[];
s32 cnt = *(u8 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4)) + 0x51);
s32 i = 0;
if (cnt > 5) cnt = 5;
if (cnt > 0) {
    i = 0;
    do {
        ((void **)M2C_FIELD(&gMapSelectState, void **, 4))[4 + i] = func_ov001_0218a5f0(0, 0x2e);
        ((void **)M2C_FIELD(&gMapSelectState, void **, 4))[9 + i] = func_ov001_0218a5f0(0, 0x18);
        i++;
    } while (i < cnt);
}
for (i = 0; (u32)i < 3; i++) {
Ov001_LoadSpriteObjLayout(0, (M2C_UNK)data_ov001_0218f814[i], ((void **)M2C_FIELD(&gMapSelectState, void **, 4))[4]);
((u16 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4)))[0x21 + i] = *(u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4))[4] + 4) & 0x3ff;
}
for (i = 0; (u32)i < 4; i++) {
Ov001_LoadSpriteObjLayout(0, (M2C_UNK)data_ov001_0218f818[i], ((void **)M2C_FIELD(&gMapSelectState, void **, 4))[9]);
((u16 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4)))[0x24 + i] = *(u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4))[9] + 4) & 0x3ff;
}
for (i = 0; i < cnt; i++) {
u16 *p = (u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4))[4 + i] + 4);
*p = (*p & ~0xc00) | 0xc00;
p = (u16 *)((u8 *)((void **)M2C_FIELD(&gMapSelectState, void **, 4))[9 + i] + 4);
*p = (*p & ~0xc00) | 0xc00;
}
}
#pragma opt_common_subs reset
void func_ov001_0217a2f0(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_0217a344(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x1D, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x1D);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217a344);
}

void func_ov001_0217a344(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217a380;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback(&func_ov001_0217a380);
}

void func_ov001_0217a380(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217a3a8;
    if (Ov001_GetIconRowSelection() == -2) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback(&func_ov001_0217a3a8);
}

void func_ov001_0217a3a8(void) {
void MapSelectList_PollInput();void MapSelectList_HandleInput(void);
MapSelectList_PollInput();MapSelectList_HandleInput();(func_ov001_0217a880)();
}

/* Polls the map-select list's touch rows and keys: a tapped/held row becomes the
 * selected map, A confirms, B cancels, and L/R or the D-pad scroll or switch the
 * list panel. */
void MapSelectList_PollInput(void) {
extern M2C_UNK gMapSelectState; extern u8 gTouchScreenRect[],gMapSelectRowRects[];
s32 TouchRectPressed(void *);s32 TouchRectHeld(void *);s32 KeyPressed(s32);s32 KeyHeld(s32);s32 KeyReleased(s32);
void func_ov001_021716d8(s32);void func_ov001_0217b130(void);M2C_UNK Ov001_PlaySound(s32);void func_ov001_02183a08(void);void func_ov001_0217b33c(void);void func_ov001_0217b2c8(void);void MapSelectList_MoveCursor(s32);
u8 *heldRect; s32 row; s32 index; u8 *pressedRect;
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)||M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57))return;
if(TouchRectPressed(gTouchScreenRect)){
M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)=-1;
for(index=0,pressedRect=gMapSelectRowRects;(u32)index<5;index++,pressedRect+=8){
if(TouchRectPressed(pressedRect)){
if(index<4){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)=index;break;}
func_ov001_021716d8(1);M2C_FIELD(&gMapSelectState,u8 *,0)=index;func_ov001_0217b130();return;
}}}
if(TouchRectHeld(gTouchScreenRect)){
for(heldRect=gMapSelectRowRects,row=0;row<4;row++,heldRect+=8){
if(TouchRectHeld(heldRect)){
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s8 *,0x50)!=row)break;
if(row>=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x51)){Ov001_PlaySound(9);break;}
func_ov001_021716d8(1);M2C_FIELD(&gMapSelectState,u8 *,0)=row;func_ov001_0217b130();return;
}}}
if(KeyPressed(KEY_A)){func_ov001_021716d8(1);func_ov001_02183a08();return;}
if(KeyPressed(KEY_B)){func_ov001_021716d8(0);return;}
if(KeyHeld(KEY_L)){func_ov001_0217b33c();return;}
if(KeyReleased(KEY_L)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_R)){func_ov001_0217b2c8();return;}
if(KeyReleased(KEY_R)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_UP)){MapSelectList_MoveCursor(1);return;}
if(KeyReleased(KEY_UP)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0;return; }
if(KeyHeld(KEY_DOWN)){MapSelectList_MoveCursor(3);return;}
if(KeyReleased(KEY_DOWN)){M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x59)=0; }
}

/* Per-frame input handler for the map-select list: handles page jumps and
 * row-by-row scrolling, plays the cursor-move or bump sound, and schedules
 * the scroll-snap callback that finishes the scroll animation. */
void MapSelectList_HandleInput(void) {
 extern M2C_UNK gMapSelectState;
 extern M2C_UNK func_ov001_0217af80,func_ov001_0217b03c;
 s32 GetMenuState(void);
 s32 GetMenuRow(void);
 s32 func_02002088(s32,u16);
 s32 func_020020c4(s32,s32);
 M2C_UNK func_ov001_02171750();
 void func_ov001_02172184(void);
 M2C_UNK func_ov001_02171738();
 M2C_UNK Ov001_PlaySound(s32);
 void func_ov001_0217ac18(void);
 void func_ov001_0217b130(void);
 s32 func_ov001_0218c884(s32,s32,s32,s32);
 s32 remainder;
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)) return;
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55))
 --M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55);
 switch(GetMenuState()) {
 case 1:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57)=1;
 func_ov001_02171750();return;
 case 2:
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55)) return;
 func_ov001_02172184();
 M2C_FIELD(&gMapSelectState,u16 *,2)=func_02002088(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)*GetMenuRow(),M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x53));
 func_ov001_0217ac18();
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x55)=4;return;
 case 3:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x57)=0;
 func_ov001_02171738();
 M2C_FIELD(&gMapSelectState,u16 *,2)=func_02002088(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)*GetMenuRow(),M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x53));
 Ov001_PlaySound(0x13);
 func_ov001_0217ac18();
 remainder=func_020020c4(M2C_FIELD(&gMapSelectState,u16 *,2),0x1c);
 if(remainder==0) {func_ov001_0217b130();return;}
 if(remainder<14) {
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=func_ov001_0218c884(0,(s32)&func_ov001_0217af80,0,120);
 return;
 }

 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=func_ov001_0218c884(0,(s32)&func_ov001_0217b03c,0,120);
 return;
 case 4:
 if(M2C_FIELD(&gMapSelectState,u16 *,2)==0) {
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58))return;
 Ov001_PlaySound(9);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=1;return;
 }
 Ov001_PlaySound(0x13);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=func_ov001_0218c884(0,(s32)&func_ov001_0217af80,0,120);return;
 case 6:
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x51)<=4 || M2C_FIELD(&gMapSelectState,u16 *,2)==M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u16 *,0x40)) {
 if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58))return;
 Ov001_PlaySound(9);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=1;return;
 }
 Ov001_PlaySound(0x13);
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x38)=func_ov001_0218c884(0,(s32)&func_ov001_0217b03c,0,120);return;
 case 5:case 7:
 M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,0x58)=0;return;
 default:return;
 }
}

void func_ov001_0217a880(void) {
    s32 Ov001_GetIconRowSelection();
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_0217b3c0(void);
    s32 func_02002088(s32, u16);
    void func_ov001_02183a08(void);
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_0217b3f0(void);
    void func_ov001_0217a98c(void);
    extern M2C_UNK gMapSelectState;
    void *map;
    s32 r;
    map = M2C_FIELD(&gMapSelectState, void **, 4);
    if (M2C_FIELD(map, M2C_UNK *, 0x38) != 0) return;
    if (M2C_FIELD(map, u8 *, 0x57) != 0) return;
    r = Ov001_GetIconRowSelection();
    switch (r) {
    case 0:
        Ov001_PlaySound(7);
        goto done;
    case 1:
        if (M2C_FIELD(&gMapSelectState, u8 *, 0) == 4) {
            map = M2C_FIELD(&gMapSelectState, void **, 4);
            M2C_FIELD(map, u8 *, 0x54) = 1;
            Ov001_PlaySound(6);
            func_ov001_0217b3c0();
            goto done;
        } else {
            u8 field28;
            s32 idx = (u8)M2C_FIELD(&gMapSelectState, u8 *, 0) + func_02002088(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1c);
            field28 = M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), void **, 0) + idx * 42, u8 *, 0x28);
            if (field28 == 2) {
                Ov001_PlaySound(9);
                func_ov001_02183a08();
                func_ov001_02171750();
                func_ov001_021862d8(0xe, 1, 1, -1, 0);
                Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217b3f0);
                goto done;
            } else {
                void *map2 = M2C_FIELD(&gMapSelectState, void **, 4);
                M2C_FIELD(map2, u8 *, 0x54) = 1;
                map = M2C_FIELD(&gMapSelectState, void **, 4);
                M2C_FIELD(map, u8 *, 0x52) = (u8)idx;
                Ov001_PlaySound(6);
                Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217a98c);
                goto done;
            }
        }
    default:
        return;
    }
done:
    return;
}

void func_ov001_0217a98c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217a9ac;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217a9ac);
}

void func_ov001_0217a9ac(void) {
    M2C_UNK func_ov001_02171694();
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gMapSelectState;
    extern M2C_UNK MapSelectList_Leave;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x54) != 0) {
        func_ov001_02171694();
    } else {
        func_ov001_02171750();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    Ov001_SetStepCallback(&MapSelectList_Leave);
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
/* Leaves the map-select list: once the fades have finished, frees the list's
 * row sprites and loaded backgrounds and starts the selected map's preview,
 * the match, or the cancel path. */
void MapSelectList_Leave(void) {
extern s32 gMapSelectState,data_ov001_02193d9c;
extern s32 func_ov001_02181a84,func_ov001_02180860,InitNameEntryScreen,func_ov001_021828ac;
s32 func_ov001_0218a800(s32);s32 func_ov001_0217170c(void);void *GetCurrentMapRecord(void);
s32 i; void *obj;
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_0217170c())return;
func_ov001_0218c94c(1,M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),s32 *,0x3c));
for(i=0;i<MAPSELECT_ROWS;i++){
obj=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4)+i*4,void **,MAPSELECT_ROW_OBJS_A);if(obj)func_ov001_0218c104(obj);
obj=M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4)+i*4,void **,MAPSELECT_ROW_OBJS_B);if(obj)func_ov001_0218c104(obj);
}
func_ov001_0218af0c(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,12));
func_ov001_02183980();func_ov001_02172184();func_ov001_02171cf8();func_ov001_021836f4();
Ov001_FreeFile(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,4));
Ov001_FreeFile(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),void **,8));
func_ov001_0218b368(1,1);func_ov001_0218b368(0,29);
*(u32 *)0x04000010=0;*(u32 *)0x04000018=0;
if(M2C_FIELD(M2C_FIELD(&gMapSelectState,void **,4),u8 *,MAPSELECT_CHOSEN)==0){
func_ov001_02183fa0();func_ov001_02184880(M2C_FIELD(GetCurrentMapRecord(),u8 *,0xf4));func_ov001_02175d64(2,0);Ov001_SetStepCallback(&func_ov001_02181a84);
}else if(M2C_FIELD(&gMapSelectState,u8 *,0)==4){
func_ov001_02183fa0();func_ov001_02175d64(0,1);Ov001_SetStepCallback(&func_ov001_02180860);
}else{
obj=M2C_FIELD(&gMapSelectState,void **,4);
func_ov001_02184498(M2C_FIELD(obj,void **,MAPSELECT_ENTRIES)+M2C_FIELD(obj,u8 *,MAPSELECT_INDEX)*MAPSELECT_ENTRY_SIZE);
func_ov001_02175d64(0,0);
obj=M2C_FIELD(&gMapSelectState,void **,4);
if(M2C_FIELD(M2C_FIELD(obj,void **,MAPSELECT_ENTRIES)+M2C_FIELD(obj,u8 *,MAPSELECT_INDEX)*MAPSELECT_ENTRY_SIZE,u8 *,MAPSELECT_ENTRY_FLAG)){
func_ov001_02175d64(0,1);Ov001_SetNameEntryMode(1,1);Ov001_SetStepCallback(&InitNameEntryScreen);
}else{
func_ov001_02175d64(0,1);Ov001_SetNameEntryMode(0,1);Ov001_SetStepCallback(&func_ov001_021828ac);
}
}
func_ov001_0218b71c(&data_ov001_02193d9c);
}
void func_ov001_0217ac18(void) {
    s32 func_02002088(s32, u16);
          void MapSelectList_DrawMapName(s32, s32);
    M2C_UNK func_ov001_0217ae38(s32, s32);
    M2C_UNK func_ov001_0217aec4();
    M2C_UNK func_ov001_0218b1ec(M2C_UNK, M2C_UNK);
    M2C_UNK CloseTextPanel(M2C_UNK);
    extern M2C_UNK gMapSelectState;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r7 = func_02002088(M2C_FIELD(&gMapSelectState, u16 *, 2), 0x1c);
    var_r4 = M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), u8 *, 0x51);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0xc), 0);
    if (var_r4 > 5) {
        var_r4 = 5;
    }
    var_r5 = var_r7;
    var_r6 = 0;
    if (var_r4 > 0) {
        do {
            MapSelectList_DrawMapName(var_r5, var_r6);
            var_r6 += 1;
            var_r5 += 1;
        } while (var_r6 < var_r4);
    }
    var_r5 = 0;
    if (var_r4 > 0) {
        do {
            func_ov001_0217ae38(var_r7, var_r5);
            var_r5 += 1;
            var_r7 += 1;
        } while (var_r5 < var_r4);
    }
    CloseTextPanel(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4), s32 *, 0xc));
    func_ov001_0217aec4();
}

/* Draws the name of the map at list position `index` on row `row` of the
   map-select list: up to 16 characters on the first line and, when the name is
   longer, the next 16 on a second line 12 pixels below. */
void MapSelectList_DrawMapName(s32 index, s32 row) {
extern M2C_UNK gMapSelectState;
s32 StringLengthUpTo(u8 *,s32);
M2C_UNK MI_CpuFill8(void *,s32,s32);
M2C_UNK DrawTextRun(void *,s32,s32,s32,s32,u16 *,s32);
u16 buf[17];
s32 offset=index*MAPSELECT_ENTRY_SIZE;
s32 len=StringLengthUpTo(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),u8 **,MAPSELECT_ENTRIES)+offset,32);
s32 y=row*28;
s32 n,i;
void *ctx;
if(index>=M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),u8 *,MAPSELECT_COUNT))return;
if(len<=16)y+=6;
MI_CpuFill8(buf,0,34);
n=len<=16?len:16;
i=0;
if(n>0){ctx=M2C_FIELD(&gMapSelectState, void **, 4);
do {buf[i]=M2C_FIELD(ctx,u8 **,MAPSELECT_ENTRIES)[offset+i];}while(++i<n);
}
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),void **,MAPSELECT_TEXT_PANEL),10,y,2,10,buf,1);
if(len<=16)return;
MI_CpuFill8(buf,0,34);
len-=16;
index=0;
if(len>0){ctx=M2C_FIELD(&gMapSelectState, void **, 4);
do {buf[index]=M2C_FIELD(ctx,u8 **,MAPSELECT_ENTRIES)[offset+index+16];}while(++index<len);
}
DrawTextRun(M2C_FIELD(M2C_FIELD(&gMapSelectState, void **, 4),void **,MAPSELECT_TEXT_PANEL),10,y+12,2,10,buf,1);
}

