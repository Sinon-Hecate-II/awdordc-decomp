/* 27 functions from 0x02180B68 to 0x02181A84 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[22]; } PathBuffer80;
extern u8 data_ov001_0218f9d4[];
extern u16 data_ov001_0218f9ea[], data_ov001_0218f9ec[];
extern M2C_UNK data_ov001_0219099c, data_ov001_021909b0, data_ov001_021909c8, data_ov001_021909e0;
extern M2C_UNK gOv001MenuRegion;
extern M2C_UNK func_02004160, func_020046cc, GX_LoadBGPltt, func_0200448c;

void func_ov001_02180b68(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(2) == 0) {
        return;
    }
    func_ov001_0218508c();
    func_ov001_021716d8(0);
}

void func_ov001_02180b8c(void) {

}

void func_ov001_02180b90(void) {
    s32 func_ov001_021716c4(void);
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_0218508c();
    void func_ov001_02180bbc(void);
    if (func_ov001_021716c4() != 0) return;
    func_ov001_0218508c();
    Ov001_PlaySound(7);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180bbc);
}

void func_ov001_02180bbc(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02180bdc;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02180bdc);
}

void func_ov001_02180bdc(void) {
    M2C_UNK func_ov001_02171694();
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_02180c2c;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_02180c2c);
}

void func_ov001_02180c2c(void) {
    M2C_UNK func_ov001_02171494();
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02183fa0();
    s32 func_ov001_021840d4();
    void *GetCurrentMapRecord();
    M2C_UNK func_ov001_02184880(u8);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern u8 data_ov001_02193dc8;
    extern M2C_UNK func_ov001_02179ea8;
    extern M2C_UNK func_ov001_02181a84;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }
    do {

    } while (func_ov001_021840d4() == 0);
    func_ov001_02171494();
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193dc8 != 1) {
        func_ov001_02183fa0();
        func_ov001_02184880(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4));
        func_ov001_02175d64(2, 1);
        Ov001_SetStepCallback(&func_ov001_02181a84);
        return;
    }
    func_ov001_02175d64(0, 1);
    func_ov001_02175da0(0, 0);
    Ov001_SetStepCallback(&func_ov001_02179ea8);
}

void func_ov001_02180cf8(void) {
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    M2C_UNK func_ov001_02186604();
    s32 func_ov001_02186648();
    extern M2C_UNK func_ov001_02180d24;
    if (func_ov001_02186648() != 0) {
        return;
    }
    Ov001_PlaySound(6);
    func_ov001_02186604();
    Ov001_SetStepCallback(&func_ov001_02180d24);
}

void func_ov001_02180d24(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180bbc);
}

void func_ov001_02180d44(void) {
    void *func_ov001_0218b6f8(s32, s32);
    void func_ov001_02180da4(void);
    void func_ov001_02180eb4(void);
    void Ov001_UpdateMenuCursor(void);
    void func_ov001_02180fbc(void);
    void func_ov001_02172250(s32);
    void func_ov001_02171c24(s32, s32, s32);
    void func_ov001_02171dd0(s32);
    extern M2C_UNK gOv001MenuRegion;
    void *temp_r0;
    temp_r0 = func_ov001_0218b6f8(0x20, 4);
    M2C_FIELD(&gOv001MenuRegion, void **, 4) = temp_r0;
    M2C_FIELD(temp_r0, u8 *, 0x1D) = 0;
    func_ov001_02180da4();
    func_ov001_02172250(1);
    func_ov001_02171c24(0x2F, -1, 0);
    func_ov001_02171dd0(0);
    func_ov001_02180eb4();
    Ov001_UpdateMenuCursor();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02180fbc);
}

void func_ov001_02180da4(void) {
s32 Ov001_LocalizePath(void *);
M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
s32 Ov001_LoadFile(s32, M2C_UNK, M2C_UNK);
void func_ov001_0218b314(s32,s32);
PathBuffer80 path = *(PathBuffer80 *)data_ov001_0218f9d4;
Ov001_LoadAsset(&data_ov001_0219099c,&func_02004160);
Ov001_LoadAsset(&data_ov001_021909b0,&func_020046cc);
Ov001_LoadAsset(&data_ov001_021909c8,&GX_LoadBGPltt);
Ov001_LoadAsset(&data_ov001_021909e0,&func_0200448c);
*M2C_FIELD(&gOv001MenuRegion,s32 **,4) = Ov001_LoadFile(Ov001_LocalizePath(&path),0,4);
func_ov001_0218b314(1,16);
M2C_FIELD((void *)0x04001008,u16 *,0)=(M2C_FIELD((void *)0x04001008,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x04001008,u16 *,2)=(M2C_FIELD((void *)0x04001008,u16 *,2)&~3)|3;
M2C_FIELD((void *)0x0400000a,u16 *,0)=(M2C_FIELD((void *)0x0400000a,u16 *,0)&~3)|3;
M2C_FIELD((void *)0x0400000a,u16 *,2)=(M2C_FIELD((void *)0x0400000a,u16 *,2)&~3)|3;
}

void func_ov001_02180eb4(void) {
    s32 func_ov001_02184868(void);
    M2C_UNK func_ov001_0218a61c(M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void func_ov001_0218a474(s32, s32, s32);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218f9ea[];
    extern u8 data_ov001_0218f9c8[];
    s32 i;
    M2C_UNK idx;
    M2C_UNK handle;

    i = 0;
    while (i < 3) {
        idx = func_ov001_02184868();
        if (idx == 0xff) {
            idx = 3;
            goto second;
        }
        handle = func_ov001_0218a61c(0, 0x11, 1);
        M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, M2C_UNK *, 0x10) = handle;
        Ov001_MoveSpriteLayout(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x10),
            -1,
            data_ov001_0218f9ea[(i + 3) * 2],
            data_ov001_0218f9ea[(i + 3) * 2 + 1]);
        func_ov001_0218a474(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x10),
            -1, 3);

second:
        handle = func_ov001_0218a61c(0, data_ov001_0218f9c8[idx], 1);
        M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, M2C_UNK *, 0x4) = handle;
        Ov001_MoveSpriteLayout(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x4),
            -1,
            data_ov001_0218f9ea[i * 2],
            data_ov001_0218f9ea[i * 2 + 1]);
        func_ov001_0218a474(
            M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + i * 4, s32 *, 0x4),
            -1, 3);

        i = i + 1;
    }
}

void func_ov001_02180fbc(void) {
    extern M2C_UNK func_ov001_02181010;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02181010);
}

void func_ov001_02181010(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    void func_ov001_0218104c(void);
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0218104c);
}

void func_ov001_0218104c(void) {
    s32 func_ov001_021716c4(void);
    s32 func_ov001_02185714(void);
    M2C_UNK func_ov001_02171738();
    void func_ov001_02181080(void);
    if (func_ov001_021716c4() == -2) return;
    if (func_ov001_02185714() == 1) return;
    func_ov001_02171738();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181080);
}

void func_ov001_02181080(void) {
    void func_ov001_02181094(void);
    void func_ov001_02181188(void);
    void func_ov001_0218118c(void);
    func_ov001_02181094();
    func_ov001_02181188();
    func_ov001_0218118c();
}

/* Scan the seven candidate regions; activate the first matching one, otherwise handle button fallbacks. */
void func_ov001_02181094(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    void Ov001_UpdateMenuCursor(void);
    s32 KeyPressed(s32);
    void Ov001_MoveMenuRegion(s32);
    s32 KeyHeld(s32);
    s32 TouchRectPressed(void *);
    extern u8 data_ov001_0218fa02[];
    extern M2C_UNK gOv001MenuRegion;
    u32 index;
    u8 *entry;
    entry = data_ov001_0218fa02;
    for (index = 0; index < 7; index++, entry += 8) {
        if (TouchRectPressed(entry) != 0) {
            func_ov001_021716d8(1);
            M2C_FIELD(&gOv001MenuRegion, u8 *, 0) = index;
            Ov001_UpdateMenuCursor();
            return;
        }
    }
    if (KeyPressed(1) != 0) {
        func_ov001_021716d8(1);
        return;
    }
    if (KeyPressed(2) != 0) {
        func_ov001_021716d8(0);
        return;
    }
    if (KeyHeld(0x40) != 0) {
        Ov001_MoveMenuRegion(1);
        return;
    }
    if (KeyHeld(0x80) != 0) {
        Ov001_MoveMenuRegion(3);
        return;
    }
    if (KeyHeld(0x20) != 0) {
        Ov001_MoveMenuRegion(0);
        return;
    }
    if (KeyHeld(0x10) == 0) return;
    Ov001_MoveMenuRegion(2);
}

void func_ov001_02181188(void) {

}

void func_ov001_0218118c(void) {
s32 func_ov001_021716c4(void),Ov001_GetScreenLayout(void),Ov001_GetLanguage(void);
s32 func_ov001_02184868();
M2C_UNK Ov001_PlaySound(s32),func_ov001_021716f8(s32),func_ov001_02171750(void);
M2C_UNK func_ov001_021862d8(s32,s32,s32,s32,s32);
M2C_UNK func_ov001_02184880(u8);
void func_ov001_02181794(void),func_ov001_021819b4(void),func_ov001_021812c0(void);
extern s8 data_ov001_0218fa74[];
extern M2C_UNK func_ov001_02176578,func_ov001_02181824;
u8 n;
s32 index, frame;
switch(func_ov001_021716c4()) {
case 0:
switch(Ov001_GetScreenLayout()) {
case 0: Ov001_PlaySound(7); M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),u8 *,0x1d)=2; break;
case 1: func_ov001_02171750(); Ov001_SetStepCallback(&func_ov001_02176578); return;
} goto done;
case 1:
M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),u8 *,0x1d)=1;
n=M2C_FIELD(&gOv001MenuRegion,u8 *,0);
if(n>=4) {
index=n-4;
if(func_ov001_02184868(index)==255) {Ov001_PlaySound(9);func_ov001_021716f8(-1);return;}
Ov001_PlaySound(6);
frame = data_ov001_0218fa74[Ov001_GetLanguage()];
func_ov001_021862d8(70,0,1,frame,index+1);
func_ov001_02181794();func_ov001_02171750();Ov001_SetStepCallback(&func_ov001_02181824);return;
}
if(n<=2)func_ov001_02184880(n);
Ov001_PlaySound(6);func_ov001_021819b4();
done:
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021812c0);
break;
}
}

void func_ov001_021812c0(void) {
    M2C_UNK func_ov001_0218560c();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK func_ov001_021812fc;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuRegion, void **, 4), u8 *, 0x1D) == 2) {
        func_ov001_0218560c();
    }
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021812fc);
}

void func_ov001_021812fc(void) {
    M2C_UNK func_ov001_02171694();
    void *GetCurrentMapRecord();
    extern M2C_UNK gOv001MenuRegion;
    extern M2C_UNK Ov001_FinishRegionMenu;
    if (func_ov001_0218a800(1) != 0) return;
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuRegion, void **, 4), u8 *, 0x1D) == 1 &&
        (M2C_FIELD(&gOv001MenuRegion, u8 *, 0) == 3 ||
         M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xE7) != 0xFF)) {
        func_ov001_02171694();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&Ov001_FinishRegionMenu);
}

#pragma opt_strength_reduction off
/* Last step of the region-menu screen: release the item sprites and the region
 * selector, load the map-list assets, and hand over to the next screen's step
 * callback (map list or layout screen, depending on the chosen region). */
void Ov001_FinishRegionMenu(void){
extern M2C_UNK data_ov001_021909f4,data_ov001_02193dd0;
extern M2C_UNK func_ov001_021768b8,func_ov001_02181a84,InitMapListScreen,func_ov001_02182d0c;
s32 func_ov001_0218a800(s32);s32 func_ov001_02185b34(void);s32 func_ov001_0217170c(void);void *GetCurrentMapRecord(void);
void func_ov001_0218a1cc(s32);
u32 i;s32 p;
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_02185b34())return;
if(!func_ov001_0217170c())return;
for(i=0;i<3;i++){p=(s32)((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->top[i];if(p)func_ov001_0218a1cc(p);}
for(i=0;i<3;i++){p=(s32)((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->middle[i];if(p)func_ov001_0218a1cc(p);}
func_ov001_02172184();func_ov001_02171cf8();
Ov001_FreeFile(((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->obj);
Ov001_LoadAsset(&data_ov001_021909f4,&func_02004160);
func_ov001_0218b368(1,1);func_ov001_0218b368(0,20);
if(((Ov001MenuRegion*)&gOv001MenuRegion)->sprites->mode==2){
func_ov001_02175d64(0,0);Ov001_SetStepCallback(&func_ov001_021768b8);
}else switch(((Ov001MenuRegion*)&gOv001MenuRegion)->index){
case 0:case 1:case 2:
func_ov001_02175d64(2,0);
if(M2C_FIELD(GetCurrentMapRecord(),u8 *,0xe7)==255)Ov001_SetStepCallback(&func_ov001_02181a84);
else{func_ov001_02175da0(0,0);func_ov001_0217f72c(0);Ov001_SetStepCallback(&InitMapListScreen);}break;
case 3:func_ov001_02175d64(2,1);Ov001_SetStepCallback(&func_ov001_02182d0c);break;
}
func_ov001_0218b71c(&data_ov001_02193dd0);
}
void Ov001_UpdateMenuCursor(void) {
    void func_ov001_02171fd8(s32, u16, u16, u16);
    void func_ov001_02172094(u16, u16, u16, u16);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218fa3a[];
    extern u16 data_ov001_0218fa3c[];
    extern u16 data_ov001_0218fa3e[];
    extern u16 data_ov001_0218fa40[];
    s32 temp_ip;
    s32 temp_r3;
    if ((u32)M2C_FIELD(&gOv001MenuRegion, u8 *, 0) < 4U) {
        temp_ip = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) * 4;
        func_ov001_02172094(data_ov001_0218fa3a[temp_ip], data_ov001_0218fa3e[temp_ip], data_ov001_0218fa3c[temp_ip], data_ov001_0218fa40[temp_ip]);
        return;
    }
    temp_r3 = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) * 4;
    func_ov001_02171fd8(0, data_ov001_0218fa3a[temp_r3], data_ov001_0218fa3e[temp_r3], data_ov001_0218fa3c[temp_r3]);
}

/* Moves the selection around the ov001 menu screen's seven touch regions by
   one direction (two rows of three item sprites plus the wide bar below them).
   Left/right wrap within a row; up/down cross between rows through the bar.
   Plays a sound and moves the cursor sprite when the selection changed. */
void Ov001_MoveMenuRegion(s32 direction) {
extern M2C_UNK gOv001MenuRegion;
s32 changed = 1;
switch (((Ov001MenuRegion *)&gOv001MenuRegion)->index) {
case 0:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=0;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; break;
case 1:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=1;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; break;
case 2:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=2;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; break;
case 3:
{u8 column = ((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column; s32 next=column+4; if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=next; else if(direction==OV001_DIR_DOWN) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=column; else changed=0;} break;
case 4:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=0;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=0; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
case 5:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=1;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=6; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=1; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
case 6:
((Ov001MenuRegion *)&gOv001MenuRegion)->sprites->column=2;
if(direction==OV001_DIR_LEFT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=5; else if(direction==OV001_DIR_RIGHT) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=4; else if(direction==OV001_DIR_UP) ((Ov001MenuRegion *)&gOv001MenuRegion)->index=2; else ((Ov001MenuRegion *)&gOv001MenuRegion)->index=3; break;
} if(changed){Ov001_PlaySound(8);Ov001_UpdateMenuCursor();}}

void func_ov001_02181794(void) {
    s32 func_ov001_0218a24c(s32, s32);
    void Ov001_MoveSpriteLayout(s32, s32, u16, u16);
    void func_ov001_0218a474(s32, s32, s32);
    void func_ov001_0218a55c(s32, s32, s32);
    extern M2C_UNK gOv001MenuRegion;
    extern u16 data_ov001_0218f9ea[];
    extern u16 data_ov001_0218f9ec[];
    s32 temp_r3;
    s32 temp_r4;
    temp_r4 = M2C_FIELD(&gOv001MenuRegion, u8 *, 0) - 4;
    func_ov001_0218a55c(0, 0x32, func_ov001_0218a24c(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), 0));
    temp_r3 = (temp_r4 + 3) * 2;
    Ov001_MoveSpriteLayout(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), -1, data_ov001_0218f9ea[temp_r3], data_ov001_0218f9ec[temp_r3]);
    func_ov001_0218a474(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion, void **, 4) + temp_r4 * 4, s32 *, 0x10), -1, 3);
}

void func_ov001_02181824(void) {
s32 func_ov001_02186648(void);
M2C_UNK Ov001_PlaySound(s32);
void func_ov001_02184c70(s32);
s32 func_ov001_0218a24c(s32,s32);
void func_ov001_0218a55c(s32,s32,s32);
void Ov001_MoveSpriteLayout(s32,s32,u16,u16);
void func_ov001_0218a474(s32,s32,s32);
void func_ov001_0218a1cc(s32);
M2C_UNK func_ov001_02186604();
void func_ov001_02181990(void);
register s32 i=M2C_FIELD(&gOv001MenuRegion,u8 *,0)-4;
switch(func_ov001_02186648()) {
case 1:
Ov001_PlaySound(14);
func_ov001_02184c70(i);
func_ov001_0218a55c(0,86,func_ov001_0218a24c(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),0));
Ov001_MoveSpriteLayout(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),-1,data_ov001_0218f9ea[i*2],data_ov001_0218f9ec[i*2]);
func_ov001_0218a474(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,4),-1,3);
func_ov001_0218a1cc(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16));
M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16)=0;
break;
case 0:
Ov001_PlaySound(7);
func_ov001_0218a55c(0,17,func_ov001_0218a24c(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),0));
Ov001_MoveSpriteLayout(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),-1,data_ov001_0218f9ea[(i+3)*2],data_ov001_0218f9ec[(i+3)*2]);
func_ov001_0218a474(M2C_FIELD((char *)M2C_FIELD(&gOv001MenuRegion,void **,4)+i*4,s32 *,16),-1,3);
break;
default:return;
}
func_ov001_02186604();
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181990);
}

void func_ov001_02181990(void) {
    M2C_UNK func_ov001_02171738();
    void func_ov001_02181080(void);
    if (func_ov001_0218665c() != 0) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02181080);
}

void func_ov001_021819b4(void) {
void func_ov001_021837e4(s32,u8,u8);s32 func_ov001_02184868(void);void func_ov001_0218a304(s32,s32,s32,u8);
extern u8 data_ov001_0218f9cc[];extern M2C_UNK gOv001MenuRegion;
u8 a[4]={data_ov001_0218f9cc[0],data_ov001_0218f9cc[1],data_ov001_0218f9cc[2],data_ov001_0218f9cc[3]};
u8 b[4]={data_ov001_0218f9cc[4],data_ov001_0218f9cc[5],data_ov001_0218f9cc[6],data_ov001_0218f9cc[7]};s32 n;u8 value;u8 *values=a;
if(M2C_FIELD(&gOv001MenuRegion,u8 *,0)>3)return;
value=values[M2C_FIELD(&gOv001MenuRegion,u8 *,0)];
func_ov001_021837e4(M2C_FIELD(M2C_FIELD(&gOv001MenuRegion,void **,4),s32 *,0),value,value);
if(M2C_FIELD(&gOv001MenuRegion,u8 *,0)==3)return;
n=func_ov001_02184868();if(n>2)n=3;
func_ov001_0218a304(M2C_FIELD((u8 *)M2C_FIELD(&gOv001MenuRegion,void **,4)+M2C_FIELD(&gOv001MenuRegion,u8 *,0)*4,s32 *,4),-1,0,b[n]);
}

