/* 48 functions from 0x02176F4C to 0x02177F1C (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[22]; } MenuBuf22;
typedef struct { u8 bytes[23]; } MenuBuf23;

/* The 20-byte profile GetWfcProfile fills in; value is nonzero when a Wi-Fi
 * connection profile has been registered. */
typedef struct { u64 value; u32 rest[3]; } WfcProfile;

/* State shared by the ov001 option-menu step functions. */
typedef struct {
    s8 selected;       /* +0x00 selected option, 0..2 */
    u8 paletteLoaded;  /* +0x01 nonzero once the option palette was chosen */
    u8 pad02[2];
    void *palette;     /* +0x04 loaded palette-file (NCL) data */
    void *sprite;      /* +0x08 OBJ handle for the selection cursor */
} Ov001OptionMenuState;

/* Palette file layout of the option screen background. */
#define OV001_PALETTE_NO_PROFILE 0x40  /* colours used when no WFC profile exists */
#define OV001_PALETTE_PROFILE    0xC0  /* colours replaced when none exists */
#define OV001_PALETTE_SIZE       0x200 /* bytes uploaded to palette RAM */

void func_ov001_02176f4c(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    void func_ov001_02176f88(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(3);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176f88);
}

void func_ov001_02176f88(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    void func_ov001_02176fb0(void);
    if (func_ov001_021716c4() == -2) return;
    func_ov001_02171738();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176fb0);
}

void func_ov001_02176fb0(void) {
    void func_ov001_02176fc4(void);
    void func_ov001_02176ffc(void);
    void func_ov001_02177000(void);
    func_ov001_02176fc4();
    func_ov001_02176ffc();
    func_ov001_02177000();
}

void func_ov001_02176fc4(void) {
    if (KeyPressed(1) != 0) {
        func_ov001_021716d8(1);
    }
    if (KeyPressed(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02176ffc(void) {

}

void func_ov001_02177000(void) {
    void func_ov001_02177068(void);
    void func_ov001_021771a4(void);
    s32 temp_r0;
    temp_r0 = func_ov001_021716c4();
    switch (temp_r0) {
    case 0:
        Ov001_PlaySound(7);
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177068);
        return;
    case 1:
        Ov001_PlaySound(6);
        func_ov001_021862d8(0x18, 0, 1, -1, 0);
        func_ov001_02171750();
        Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021771a4);
        return;
    }
}

void func_ov001_02177068(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177088;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02177088);
}

void func_ov001_02177088(void) {
    extern u8 data_ov001_02193d64;
    extern M2C_UNK func_ov001_021770ec;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    if (data_ov001_02193d64 == 0) {
        func_ov001_0218a824(3, 1, 1, 8);
    }
    func_ov001_0218a824(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_021770ec);
}

void func_ov001_021770ec(void) {
    s32 func_ov001_0217170c();
    extern M2C_UNK func_ov001_021778c0;
    void func_ov001_02177214(void);
    extern u8 data_ov001_02193d64;
    if (func_ov001_0218a800(0) != 0) return;
    if (data_ov001_02193d64 == 0 && func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0217170c() == 0) return;
    func_ov001_0218af70(0);
    if (data_ov001_02193d64 == 0) {
        func_ov001_02171cf8();
        func_ov001_0218b368(1, 1);
    }
    func_ov001_0218b368(0, 0x15);
    if (data_ov001_02193d64 == 0) {
        func_ov001_02175d64(0, 1);
        Ov001_SetStepCallback(&func_ov001_021778c0);
        return;
    }
    func_ov001_02175d64(0, 1);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177214);
}

void func_ov001_021771a4(void) {
    void func_ov001_021771f4(void);
    extern u8 data_ov001_02193d64;
    s32 temp_r0;
    temp_r0 = func_ov001_02186648();
    switch (temp_r0) {
    case 1:
        Ov001_PlaySound(0xE);
        data_ov001_02193d64 = 1;
        break;
    case 0:
        Ov001_PlaySound(7);
        break;
    default: return;
    }
    func_ov001_02186604();
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021771f4);
}

void func_ov001_021771f4(void) {
    s32 func_ov001_0218665c();
    if (func_ov001_0218665c() != 0) {
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177068);
}

void func_ov001_02177214(void) {
    M2C_UNK func_ov001_02171e58(M2C_UNK);
    void func_ov001_02177238(void);
    M2C_UNK func_ov001_02184cac();
    extern M2C_UNK func_ov001_021772b8;
    func_ov001_02177238();
    func_ov001_02171e58(0x19);
    func_ov001_02184cac();
    Ov001_SetStepCallback(&func_ov001_021772b8);
}

void func_ov001_02177238(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190534;
    extern M2C_UNK func_0200448c;
    Ov001_LoadAsset(&data_ov001_02190534, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

void func_ov001_021772b8(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021772ec;
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_021772ec);
}

void func_ov001_021772ec(void) {
    void func_ov001_02177318(void);
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(5);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177318);
}

void func_ov001_02177318(void) {
    extern M2C_UNK func_ov001_02177340;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback(&func_ov001_02177340);
}

void func_ov001_02177340(void) {
    void func_ov001_02177354(void);
    void func_ov001_02177374(void);
    void func_ov001_02177378(void);
    func_ov001_02177354();
    func_ov001_02177374();
    func_ov001_02177378();
}

void func_ov001_02177354(void) {
    M2C_UNK func_ov001_021716d8(M2C_UNK);
    s32 KeyPressed(M2C_UNK);
    if (KeyPressed(1) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_02177374(void) {

}

void func_ov001_02177378(void) {
    s32 func_ov001_021716c4();
    M2C_UNK Ov001_PlaySound(M2C_UNK);
    void func_ov001_021773a0(void);
    if (func_ov001_021716c4() != 0) return;
    Ov001_PlaySound(6);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021773a0);
}

void func_ov001_021773a0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_021773c0;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_021773c0);
}

void func_ov001_021773c0(void) {
    void func_ov001_0217740c(void);
    if (func_ov001_0218a800(1) != 0) return;
    func_ov001_0218a824(3, 1, 0x3F, 0x40);
    func_ov001_0218a824(3, 0, 0x3F, 0x40);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217740c);
}

void func_ov001_0217740c(void) {
    M2C_UNK func_0200758c(M2C_UNK);
    M2C_UNK func_0200e840();
    s32 func_ov001_0218a800(M2C_UNK);
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_0200758c(0x01000000);
    func_0200e840();
}

void func_ov001_02177440(void) {
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02172250(M2C_UNK);
    void func_ov001_02177474(void);
    M2C_UNK DrawMacAddressPanel();
    extern M2C_UNK func_ov001_021776c8;
    func_ov001_02177474();
    func_ov001_02172250(0x11);
    func_ov001_02171c24(0x3A, -1, 0);
    DrawMacAddressPanel();
    Ov001_SetStepCallback(&func_ov001_021776c8);
}

void func_ov001_02177474(void) {
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    extern M2C_UNK data_ov001_02190548;
    extern M2C_UNK func_0200448c;
    Ov001_LoadAsset(&data_ov001_02190548, &func_0200448c);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3);
    *(u16 *)0x04000008 = (*(u16 *)0x04000008 & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 3);
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (u16) ((M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3);
}

/* Draws a two-line panel: the console's MAC address and its Wi-Fi profile code
 * (or a dashes placeholder when that code is zero), then closes the panel. */
M2C_UNK DrawMacAddressPanel(void) {
void *CreateTextPanel(s32,s32); void GetMacAddress(void *); s32 StringFormatWide(void *,s32,void *,...);
void DrawPanelText(void *,s32,s32,s32,s32,s32,s32,void *); M2C_UNK GetWfcProfile(void *);void CloseTextPanel(void *);
extern u8 sMacAddressFormat[],sGroupedCodeFormat[],sEmptyCodeText[];
u32 profile[5]; u32 groups[4]; char text[42]; u8 macAddress[6]; void *panel; u64 code;s32 i;
panel=CreateTextPanel(0,0);
GetMacAddress(macAddress);
StringFormatWide(text,20,sMacAddressFormat,macAddress[0],macAddress[1],macAddress[2],macAddress[3],macAddress[4],macAddress[5]);
DrawPanelText(panel,8,64,240,28,2,1152,text);
GetWfcProfile(profile);code=*(u64 *)profile;
if(code){
groups[3]=(code%10)*1000;code/=10;
for(i=0;i<3;i++){groups[2-i]=code%10000;code/=10000;}
StringFormatWide(text,20,sGroupedCodeFormat,groups[0],groups[1],groups[2],groups[3]);
}else StringFormatWide(text,20,sEmptyCodeText);
DrawPanelText(panel,8,120,240,28,2,1152,text);
CloseTextPanel(panel);
}

void func_ov001_021776c8(void) {
    extern M2C_UNK func_ov001_0217771c;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x15, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x15);
    Ov001_SetStepCallback(&func_ov001_0217771c);
}

void func_ov001_0217771c(void) {
    void func_ov001_02177758(void);
    if (func_ov001_0218a800(1) != 0) return;
    if (func_ov001_0218a800(0) != 0) return;
    func_ov001_02171e20(2);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177758);
}

void func_ov001_02177758(void) {
    extern M2C_UNK func_ov001_02177780;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback(&func_ov001_02177780);
}

void func_ov001_02177780(void) {
    void func_ov001_02177794(void);
    void func_ov001_021777b4(void);
    void func_ov001_021777b8(void);
    func_ov001_02177794();
    func_ov001_021777b4();
    func_ov001_021777b8();
}

void func_ov001_02177794(void) {
    if (KeyPressed(2) == 0) {
        return;
    }
    func_ov001_021716d8(0);
}

void func_ov001_021777b4(void) {

}

void func_ov001_021777b8(void) {
    void func_ov001_021777e0(void);
    if (func_ov001_021716c4() != 0) return;
    Ov001_PlaySound(7);
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021777e0);
}

void func_ov001_021777e0(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK Ov001_SetStepCallback(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_02177800;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02177800);
}

void func_ov001_02177800(void) {
    M2C_UNK func_ov001_02171694();
    extern M2C_UNK func_ov001_02177850;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    func_ov001_02171694();
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x15, 8);
    Ov001_SetStepCallback(&func_ov001_02177850);
}

void func_ov001_02177850(void) {
    s32 func_ov001_0217170c();
    M2C_UNK func_ov001_02171cf8();
    M2C_UNK func_ov001_02175d64(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218af70(M2C_UNK);
    M2C_UNK func_ov001_0218b368(M2C_UNK, M2C_UNK);
    extern M2C_UNK func_ov001_021778c0;
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
    func_ov001_02175d64(0, 1);
    Ov001_SetStepCallback(&func_ov001_021778c0);
}

void func_ov001_021778c0(void) {
extern M2C_UNK gOv001OptionMenuState;
extern M2C_UNK data_ov001_0218f77a,data_ov001_0218f77e,data_ov001_0218f77c,data_ov001_0218f780;
void Ov001_LoadOptionMenuBg(void);
void func_ov001_02177b24(void);
void *func_ov001_0218a5f0(s32,s32);
M2C_UNK func_ov001_02172250(s32);
M2C_UNK func_ov001_02185b60(s32);
M2C_UNK func_ov001_02171c24(s32,s32,s32);
M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
void *p; s32 offset;
M2C_FIELD(&gOv001OptionMenuState,u8 *,1)=0;
Ov001_LoadOptionMenuBg();
func_ov001_02172250(16);
func_ov001_02185b60(3);
func_ov001_02171c24(0x39,-1,0);
p=func_ov001_0218a5f0(0,0x5b);
M2C_FIELD(&gOv001OptionMenuState,void **,8)=p;
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|0x84|0xe00000;
p=M2C_FIELD(&gOv001OptionMenuState,void **,8);
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xc00)|0xc00;
offset=M2C_FIELD(&gOv001OptionMenuState,u8 *,0)*8;
func_ov001_02172094(M2C_FIELD(&data_ov001_0218f77a,u16 *,offset),M2C_FIELD(&data_ov001_0218f77e,u16 *,offset),M2C_FIELD(&data_ov001_0218f77c,u16 *,offset),M2C_FIELD(&data_ov001_0218f780,u16 *,offset));
Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177b24);
}

/* Loads the option screen's tiles, map and palette, copies the no-profile
 * palette over the profile colours while no Wi-Fi profile exists, uploads the
 * palette, frees the temporary files and puts BG1/BG2 on priority 3. */
void Ov001_LoadOptionMenuBg(void) {
    s32 Ov001_LocalizePath(void *);
    M2C_UNK Ov001_LoadAsset(M2C_UNK *, M2C_UNK *);
    void *Ov001_LoadFile(s32, s32, s32);
    M2C_UNK GetWfcProfile(void *);
    void MI_CpuCopy8(void *, void *, u32);
    void DC_FlushRange(void *, u32);
    void GX_LoadBGPltt(void *, s32, u32);
    void Ov001_FreeFile(void *);
    extern M2C_UNK gOv001OptionBgPalettePath, gOv001OptionBgPaletteBankPath, gOv001OptionBgTilesPath, gOv001OptionMenuMapPath, gOv001OptionMenuState, func_020046cc, func_0200448c;
    MenuBuf22 palettePath = *(MenuBuf22 *)&gOv001OptionBgPalettePath;
    MenuBuf23 layoutPath = *(MenuBuf23 *)&gOv001OptionBgPaletteBankPath;
    WfcProfile profile;
    register u8 *dst, *src;
    register s32 i;
    register void *palette;
    Ov001_LoadAsset(&gOv001OptionBgTilesPath, &func_020046cc);
    Ov001_LoadAsset(&gOv001OptionMenuMapPath, &func_0200448c);
    M2C_FIELD(&gOv001OptionMenuState, void **, 4) = Ov001_LoadFile(Ov001_LocalizePath(&layoutPath), 0, 4);
    palette = Ov001_LoadFile(Ov001_LocalizePath(&palettePath), 0, 4);
    GetWfcProfile(&profile);
    if (profile.value == 0) {
        for (i = 0, dst = (u8 *)palette + OV001_PALETTE_PROFILE, src = (u8 *)palette + OV001_PALETTE_NO_PROFILE; i < 2; i++, dst += 32, src += 32)
            MI_CpuCopy8(dst, src, 32);
    }
    DC_FlushRange(palette, OV001_PALETTE_SIZE);
    GX_LoadBGPltt(palette, 0, OV001_PALETTE_SIZE);
    Ov001_FreeFile(palette);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000a, u16 *, 0) = (M2C_FIELD((void *)0x0400000a, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000a, u16 *, 2) = (M2C_FIELD((void *)0x0400000a, u16 *, 2) & ~3) | 3;
}

void func_ov001_02177b24(void) {
    extern M2C_UNK func_ov001_02177b78;
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x14, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x14);
    Ov001_SetStepCallback(&func_ov001_02177b78);
}

void func_ov001_02177b78(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_02177bb4;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    Ov001_SetStepCallback(&func_ov001_02177bb4);
}

void func_ov001_02177bb4(void) {
    extern M2C_UNK func_ov001_02177bdc;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    Ov001_SetStepCallback(&func_ov001_02177bdc);
}

void func_ov001_02177bdc(void) {
    void func_ov001_02177bf0(void);
    void func_ov001_02177ce4(void);
    void func_ov001_02177ce8(void);
    func_ov001_02177bf0();
    func_ov001_02177ce4();
    func_ov001_02177ce8();
}

#pragma opt_strength_reduction off
void func_ov001_02177bf0(void){
M2C_UNK func_ov001_021716d8(M2C_UNK);
M2C_UNK func_ov001_02172094(u16,u16,u16,u16);
void func_ov001_02177f1c(s32);
s32 KeyPressed(s32);s32 KeyHeld(s32);s32 TouchRectPressed(void *);
extern u8 data_ov001_0218f762[];
extern M2C_UNK data_ov001_0218f77a,data_ov001_0218f77e,data_ov001_0218f77c,data_ov001_0218f780,gOv001OptionMenuState;
u32 index;u8 *entry;s32 offset;u16 a,b,c,d;
entry=data_ov001_0218f762;
for(index=0;index<3;index++,entry+=8){
if(TouchRectPressed(entry)){
func_ov001_021716d8(1);
offset=(u8)index*8;
a=M2C_FIELD(&data_ov001_0218f77a,u16 *,offset);
b=M2C_FIELD(&data_ov001_0218f77e,u16 *,offset);
c=M2C_FIELD(&data_ov001_0218f77c,u16 *,offset);
d=M2C_FIELD(&data_ov001_0218f780,u16 *,offset);
M2C_FIELD(&gOv001OptionMenuState,s8 *,0)=index;
func_ov001_02172094(a,b,c,d);return;
}}
if(KeyPressed(1)){func_ov001_021716d8(1);return;}
if(KeyPressed(2)){func_ov001_021716d8(0);return;}
if(KeyHeld(0x40)){func_ov001_02177f1c(1);return;}
if(!KeyHeld(0x80))return;
func_ov001_02177f1c(3);
}
#pragma opt_strength_reduction reset
void func_ov001_02177ce4(void) {

}

void func_ov001_02177ce8(void) {
    M2C_UNK GetWfcProfile(void *);
    M2C_UNK func_ov001_021716f8(M2C_UNK);
    M2C_UNK func_ov001_02177fac();
    void func_ov001_02177d8c(void);
    extern M2C_UNK gOv001OptionMenuState;
    struct { u64 value; u32 unk_08[3]; } sp0;
    switch (func_ov001_021716c4()) {
    case 0:
        Ov001_PlaySound(7);
        break;
    case 1:
        GetWfcProfile(&sp0);
        if (M2C_FIELD(&gOv001OptionMenuState, u8 *, 0) != 0) {
            if (sp0.value == 0) {
                Ov001_PlaySound(9);
                func_ov001_021716f8(-1);
                return;
            }
        }
        Ov001_PlaySound(6);
        func_ov001_02177fac();
        M2C_FIELD(&gOv001OptionMenuState, u8 *, 1) = 1;
        break;
    default:
        return;
    }
    Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177d8c);
}

void func_ov001_02177d8c(void) {
    extern M2C_UNK func_ov001_02177dac;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    Ov001_SetStepCallback(&func_ov001_02177dac);
}

void func_ov001_02177dac(void) {
    extern M2C_UNK gOv001OptionMenuState;
    extern M2C_UNK func_ov001_02177e10;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(&gOv001OptionMenuState, u8 *, 1) != 0) {
        func_ov001_02171694();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x14, 8);
    Ov001_SetStepCallback(&func_ov001_02177e10);
}

void func_ov001_02177e10(void) {
extern M2C_UNK gOv001OptionMenuState;
void func_ov001_021768b8(void);void func_ov001_02177440(void);void func_ov001_02176e30(void);void func_ov001_0217868c(void);
s32 func_ov001_0218a800(M2C_UNK);
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_0217170c())return;
func_ov001_0218c104(M2C_FIELD(&gOv001OptionMenuState,void **,8));
func_ov001_02172184();func_ov001_02171cf8();
Ov001_FreeFile(M2C_FIELD(&gOv001OptionMenuState,void **,4));
func_ov001_0218b368(1,1);func_ov001_0218b368(0,20);
if(!M2C_FIELD(&gOv001OptionMenuState,u8 *,1)){func_ov001_02175d64(0,0);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_021768b8);return;}
switch(M2C_FIELD(&gOv001OptionMenuState,u8 *,0)){
case 0:func_ov001_02175d64(0,1);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02177440);return;
case 1:func_ov001_02175d64(0,1);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_02176e30);return;
case 2:func_ov001_02175d64(0,1);Ov001_SetStepCallback((M2C_UNK *)&func_ov001_0217868c);return;
}
}

