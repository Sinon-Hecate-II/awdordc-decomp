/* 23 functions from 0x0217CCE8 to 0x0217DC7C (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK gMapListState;
extern const u8 data_ov001_0218f9bc[];
void func_ov001_0217f6cc(void);
void func_ov001_0217ded8(void);
void func_ov001_0217dbd8(s32);
void func_ov001_0217dc44(s32);

void *func_ov001_0218445c();

M2C_UNK func_ov001_0217cce8(void) {
    return 0;
}

void func_ov001_0217d044(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_0217d078;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217d078);
}

void func_ov001_0217d078(void) {
    void func_ov001_0217d0b4(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(4);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217d0b4);
}

void func_ov001_0217d0b4(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217d0dc;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback(&func_ov001_0217d0dc);
}

void func_ov001_0217d0dc(void) {
    void func_ov001_0217d0f0(void);
    void func_ov001_0217d110(void);
    void func_ov001_0217d114(void);
    func_ov001_0217d0f0();
    func_ov001_0217d110();
    func_ov001_0217d114();
}

void func_ov001_0217d0f0(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_0217d110(void) {

}

void func_ov001_0217d114(void) {
    s32 func_ov001_021716c4();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_0217d13c(void);
    if (func_ov001_021716c4() != 0) return;
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217d13c);
}

void func_ov001_0217d13c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217d15c;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_0217d15c);
}

void func_ov001_0217d15c(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK func_ov001_0217d1ac;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_0217d1ac);
}

void func_ov001_0217d1ac(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175da0(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0217f72c(M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK InitMapListScreen;
    extern M2C_UNK func_ov001_02180d44;
    s32 sp0;

    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    if (func_ov001_0217170c() == 0) {
        return;
    }
    func_ov001_0218af70(0);
    func_ov001_02171cf8();
    func_ov001_0218b368(1, 1);
    func_ov001_0218b368(0, 0x15);
    func_ov001_02175db4(0, &sp0);
    if (sp0 != 0) {
        func_ov001_02175d64(2, 1);
        Ov001_SetStepCallback(&func_ov001_02180d44);
        return;
    }
    func_ov001_02175d64(2, 0);
    func_ov001_02175da0(0, 0);
    func_ov001_0217f72c(0);
    Ov001_SetStepCallback(&InitMapListScreen);
}

void func_ov001_0217d260(s32 arg0) {
    extern s32 data_ov001_02193da8;
    data_ov001_02193da8 = arg0;
}

/* Build the map-list screen: allocate its list object, load its backgrounds and
 * text, size the scrollbar from the scroll position, create the seven entry
 * sprites and the two scroll callbacks, then start the input step. */
void InitMapListScreen(void) {
    void *func_ov001_0218445c(void);
    void *func_ov001_0218b6f8(s32, s32);
    extern M2C_UNK gMapListState;
    void func_ov001_0217d680(void);
    void InitMapListGraphics(void);
    u8 func_ov001_02175ddc(void);
    M2C_UNK func_ov001_02171c24(s32, s32, s32);
    void func_ov001_02171dd0(M2C_UNK);
    void func_ov001_021722c4(void);
    M2C_UNK func_ov001_021838a8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void *func_ov001_0218ad0c(s32, s32);
    void *func_ov001_0218a5f0(s32, s32);
    void *func_ov001_0218c884(s32, void (*)(void), s32, s32);
    M2C_UNK func_ov001_0217e238(void);
    void func_ov001_0217f038(void);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    extern s8 data_ov001_0218f99c[];
    void func_ov001_0217efb4(void);
    void func_ov001_0217f514(void);
    void func_ov001_0217d6bc(void);

    void *profile;
    s32 i;
    u8 value;
    void *sprite;

    profile = func_ov001_0218445c();
    M2C_FIELD(&gMapListState, void **, 8) = func_ov001_0218b6f8(0x48, 4);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x43) = M2C_FIELD(profile, u8 *, 0xf6);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x42) = 0xc;
    func_ov001_0217d680();
    InitMapListGraphics();
    if (M2C_FIELD(&gMapListState, u8 *, 1) == 0) {
        value = func_ov001_02175ddc();
        func_ov001_02171c24(0x30, (s32)data_ov001_0218f99c[value], M2C_FIELD(profile, u8 *, 0xf4) + 1);
    } else {
        func_ov001_02171c24(0x45, -1, 0);
    }
    func_ov001_02171dd0(1);
    func_ov001_021722c4();
    func_ov001_021838a8(2, 0x55, 0xf1, 0x41,
                        (M2C_FIELD(&gMapListState, u16 *, 4) * 55) / 145);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x14) = func_ov001_0218ad0c(0, 1);
    for (i = 0; i < 7; i++) {
        ((void **)M2C_FIELD(&gMapListState, void **, 8))[i + 6] = func_ov001_0218a5f0(0, 0x29);
    }
    value = M2C_FIELD(profile, u8 *, 0xe7);
    switch (value) {
        case 1: {
            sprite = func_ov001_0218a5f0(0, 0x50);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34) = sprite;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) =
                (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) & ~0xc00) | 0xc00;
            break;
        }
        case 2: {
            sprite = func_ov001_0218a5f0(0, 0x51);
            M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34) = sprite;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) =
                (M2C_FIELD(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x34), u16 *, 4) & ~0xc00) | 0xc00;
            break;
        }
    }
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x3c) = func_ov001_0218c884(1, (void (*)(void))func_ov001_0217efb4, 0, 0x6e);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x00) = func_ov001_0218c884(0, (void (*)(void))func_ov001_0217f514, 0, 0x78);
    func_ov001_0217e238();
    func_ov001_0217f038();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217d6bc);
}

/* Set up the map-list screen's graphics: load the two background tile/palette
 * sets and the list-background tilemaps into VRAM, create the background list
 * objects and point the layered background control registers at them. */
void InitMapListGraphics(void) {
    M2C_UNK func_ov001_02171d30(void *);
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov001_02189dc8(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02183694(M2C_UNK);
    M2C_UNK func_ov001_02183720(void);
    extern u8 sJb3ListBackPath[];
    extern u8 sYbBgStep2NclPath[];
    extern u8 sYbBgStep21NclPath[];
    extern M2C_UNK sYbObjKbPath, sJbBgStep2NcgPath, sJbBgStep21NcgPath, sJb3ListNscPath;
    extern M2C_UNK gMapListState;
    extern M2C_UNK func_02004160, func_0200472c, func_020046cc, func_020040b4, func_020044ec;
    typedef struct { u8 bytes[23]; } ListBackPath;
    typedef struct { u8 bytes[21]; } BgStep2Path;
    typedef struct { u8 bytes[22]; } BgStep21Path;
    ListBackPath listBackPath = *(ListBackPath *)sJb3ListBackPath;
    BgStep2Path bgStep2Path = *(BgStep2Path *)sYbBgStep2NclPath;
    BgStep21Path bgStep21Path = *(BgStep21Path *)sYbBgStep21NclPath;

    /* main BG2: 256-colour tiles, 512x256 map */
    M2C_FIELD((void *)0x0400000C, volatile u16 *, 0) =
        (M2C_FIELD((void *)0x0400000C, volatile u16 *, 0) & 0x43) | 0x218 | 0xC00;

    func_ov001_02171d90(&sYbObjKbPath, &func_02004160);      /* UI palette */
    func_ov001_02171d90(&sJbBgStep2NcgPath, &func_0200472c); /* background tiles, step 2 */
    func_ov001_02171d90(&sJbBgStep21NcgPath, &func_020046cc);/* background tiles, step 21 */
    func_ov001_02171d90((void *)&bgStep2Path, &func_020040b4);   /* background palette, step 2 */
    func_ov001_02171d90(&sJb3ListNscPath, &func_020044ec);   /* list tilemap */

    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 8) =
        func_ov001_02189dc8(func_ov001_02171d30((void *)&listBackPath), 0, 4);
    func_ov001_02183694(M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 8));
    func_ov001_02183720();
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 12) =
        func_ov001_02189dc8(func_ov001_02171d30((void *)&bgStep2Path), 0, 4);
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), M2C_UNK *, 16) =
        func_ov001_02189dc8(func_ov001_02171d30((void *)&bgStep21Path), 0, 4);

    /* sub BG0/BG1 and main BG0/BG1: 256-colour tiled layers */
    M2C_FIELD((void *)0x04001008, volatile u16 *, 0) = (M2C_FIELD((void *)0x04001008, volatile u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, volatile u16 *, 2) = (M2C_FIELD((void *)0x04001008, volatile u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x04000008, volatile u16 *, 0) = (M2C_FIELD((void *)0x04000008, volatile u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 0) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 0) & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 2) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, volatile u16 *, 4) = (M2C_FIELD((void *)0x0400000A, volatile u16 *, 4) & ~3) | 2;
}

void func_ov001_0217d680(void) {
    M2C_UNK func_ov001_02175db4(M2C_UNK, s32 *);
    void *func_ov001_0218445c();
    extern M2C_UNK gMapListState;
    s32 sp0;

    func_ov001_0218445c();
    func_ov001_02175db4(0, &sp0);
    if (sp0 != 0) {
        return;
    }
    M2C_FIELD(&gMapListState, s16 *, 4) = 0;
    M2C_FIELD(&gMapListState, s8 *, 0) = 0;
    M2C_FIELD(&gMapListState, s8 *, 2) = 0;
}

void func_ov001_0217d6bc(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void func_ov001_0217d710(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x1D, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x1D);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217d710);
}

void func_ov001_0217d710(void) {
    extern M2C_UNK func_ov001_0217d744;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    Ov001_SetStepCallback(&func_ov001_0217d744);
}

void func_ov001_0217d744(void) {
    M2C_UNK MapListHandleState();
    void func_ov001_0217d754(void);
    func_ov001_0217d754();
    MapListHandleState();
}

void func_ov001_0217d754(void) {
    extern M2C_UNK gMapListState;
    extern M2C_UNK func_ov001_0217ef10;
    extern M2C_UNK func_ov001_0217ee48;
    s32 func_ov001_0217d9d4(void);
    s32 KeyPressed(s32);
    s32 KeyHeld(s32);
    s32 KeyReleased(s32);
    M2C_UNK func_ov001_0217da58(u32);
    M2C_UNK Ov001_PlaySound(s32);
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    void *func_ov001_0218c884(s32, void (*)(void), s32, s32);
    M2C_UNK func_ov001_0217f1f0(s32);
    void *obj;

    obj = M2C_FIELD(&gMapListState, void **, 8);
    if (M2C_FIELD(obj, void **, 0x38) != 0 || M2C_FIELD(obj, u8 *, 0x45) != 0) {
        return;
    }
    if (func_ov001_0217d9d4() != 0) {
        return;
    }
    if (KeyPressed(1) != 0) {
        func_ov001_0217da58(M2C_FIELD(&gMapListState, u8 *, 0));
        return;
    }
    if (KeyPressed(2) != 0) {
        Ov001_PlaySound(7);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x40) = 0xd;
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217ded8);
        return;
    }
    if (KeyHeld(0x200) != 0) {
        if (M2C_FIELD(&gMapListState, u16 *, 4) == 0x91) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            }
            return;
        }
        Ov001_PlaySound(0x13);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x38) =
            func_ov001_0218c884(0, (void (*)(void))&func_ov001_0217ef10, 0, 0x78);
        return;
    }
    if (KeyReleased(0x200) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x100) != 0) {
        if (M2C_FIELD(&gMapListState, u16 *, 4) == 0) {
            if (M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) == 0) {
                Ov001_PlaySound(9);
                M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 1;
            }
            return;
        }
        Ov001_PlaySound(0x13);
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), void **, 0x38) =
            func_ov001_0218c884(0, (void (*)(void))&func_ov001_0217ee48, 0, 0x78);
        return;
    }
    if (KeyReleased(0x100) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x40) != 0) {
        func_ov001_0217f1f0(1);
        return;
    }
    if (KeyReleased(0x40) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x80) != 0) {
        func_ov001_0217f1f0(3);
        return;
    }
    if (KeyReleased(0x80) != 0) {
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x47) = 0;
        return;
    }
    if (KeyHeld(0x20) != 0) {
        func_ov001_0217f1f0(0);
        return;
    }
    if (KeyHeld(0x10) == 0) {
        return;
    }
    func_ov001_0217f1f0(2);
}

s32 func_ov001_0217d9d4(void) {
    M2C_UNK func_ov001_0217da58(u32);
    s32 func_ov001_0217e5e8();
    u32 func_ov001_0217eb6c();
    M2C_UNK func_ov001_0217f1c0(u32);
    M2C_UNK func_ov001_0217f568();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    u32 temp_r0;

    func_ov001_0218445c();
    temp_r0 = func_ov001_0217eb6c();
    if (temp_r0 == 0xE) {
        return 0;
    }
    if (func_ov001_0217e5e8() == 0) {
        Ov001_PlaySound(9);
        return 1;
    }
    func_ov001_0217f1c0(temp_r0);
    switch (temp_r0) {
    default:
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        func_ov001_0217f568();
        break;
    }
    func_ov001_0217da58(temp_r0);
    return 1;
}

/* Dispatch a screen selection (0..13): set up UI state, graphics, and continue via func_ov001_0217ded8. */
s32 func_ov001_0217da58(u32 a){
if(func_ov001_0217e5e8()==0){Ov001_PlaySound(9);return;}
switch(a){
case 2:case 3:Ov001_PlaySound(6);func_ov001_0217dbd8(((a-2)^1)!=0);return;
case 7:case 8:Ov001_PlaySound(6);func_ov001_0217dc44(((a-7)^1)!=0);return;
case 0:case 1:case 4:case 5:case 6:break;
}
M2C_FIELD(M2C_FIELD(&gMapListState,void **,8),u8 *,64)=a;
if(a-11<=1){
func_ov001_0217f4e0();
if(func_ov001_0217f62c()==0){
Ov001_PlaySound(9);func_ov001_021862d8(6,1,1,-1,0);Ov001_SetStepCallback((M2C_UNK *)func_ov001_0217f6cc);return;
}
if(a==11)Ov001_PlaySound(6);else Ov001_PlaySound(14);
}else if(a==13){func_ov001_0217f4e0();Ov001_PlaySound(7);}
else {Ov001_PlaySound(6);func_ov001_0217e67c(0,1,func_ov001_0217ede0(data_ov001_0218f9bc[a]));func_ov001_0217e95c();}
func_ov001_02183a08();Ov001_SetStepCallback((M2C_UNK *)func_ov001_0217ded8);
}

void func_ov001_0217dbd8(s32 arg0) {
    M2C_UNK func_ov001_0217e238();
    M2C_UNK func_ov001_02184470(s32);
    M2C_UNK func_ov001_02184484(s32);
    extern M2C_UNK gMapListState;
    s32 var_r5;
    void *temp_r0;
    temp_r0 = func_ov001_0218445c();
    if (M2C_FIELD(temp_r0, u8 *, 0xF5) == arg0) return;
    if (arg0 != 0) {
        var_r5 = M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x43) != 0;
    } else {
        var_r5 = 0;
        M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x43) = M2C_FIELD(temp_r0, u8 *, 0xF6);
    }
    func_ov001_02184470(arg0);
    func_ov001_02184484(var_r5);
    func_ov001_0217e238();
}

void func_ov001_0217dc44(s32 arg0) {
    M2C_UNK func_ov001_0217e238();
    M2C_UNK func_ov001_02184484(s32);
    extern M2C_UNK gMapListState;
    s32 current;
    current = M2C_FIELD(func_ov001_0218445c(), u8 *, 0xF6);
    if (current == arg0) return;
    M2C_FIELD(M2C_FIELD(&gMapListState, void **, 8), u8 *, 0x43) = arg0;
    func_ov001_02184484(arg0);
    func_ov001_0217e238();
}

