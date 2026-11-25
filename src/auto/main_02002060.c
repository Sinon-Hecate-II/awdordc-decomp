/* 24 functions from 0x02002060 to 0x02003058 (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"
#include "hw_div.h"

void func_02002060(s32 arg0, s32 arg1) {
    M2C_FIELD((void *)0x04000280, s16 *, 0) = 1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x10) = 0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x14) = arg0;
    M2C_FIELD((void *)0x04000280, s32 *, 0x18) = arg1;
    M2C_FIELD((void *)0x04000280, s32 *, 0x1C) = 0;
}

/* Signed 32-bit quotient from the ARM9's hardware divider. */
s32 HardwareDivide(s32 numerator, s32 denominator) {
    REG_DIVCNT = 0;
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = (u32)denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    return REG_DIV_RESULT;
}

/* Signed 32-bit remainder from the ARM9's hardware divider. */
s32 HardwareDivideRemainder(s32 numerator, s32 denominator) {
    REG_DIVCNT = 0;
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = (u32)denominator;
    while (REG_DIVCNT & DIVCNT_BUSY) {}
    return REG_DIVREM_RESULT;
}

/* Dot product of two 20.12 fixed-point 3-vectors, rounded back to 20.12. */
s32 Vec3DotProduct(s32 *a, s32 *b) {
    return ((s64)a[0] * b[0] + (s64)a[1] * b[1] + (s64)a[2] * b[2] + 0x800) >> 12;
}

/* Cross product of two 12-bit fixed-point 3-vectors, rounded back to 12-bit
 * fixed point. */
void Vec3CrossProduct(s32 *a, s32 *b, s32 *out) {
    s32 x = ((s64) a[1] * b[2] - (s64) a[2] * b[1] + 0x800) >> 12;
    s32 y = ((s64) a[2] * b[0] - (s64) a[0] * b[2] + 0x800) >> 12;
    s32 z = ((s64) a[0] * b[1] - (s64) a[1] * b[0] + 0x800) >> 12;
    out[0] = x; out[1] = y; out[2] = z;
}

typedef volatile unsigned int vu32;
void func_020021c0(s32 *a, s32 *b) {
 s64 sq=(s64)a[1]*a[1]; sq+=(s64)a[0]*(*(volatile s32*)a); sq+=(s64)a[2]*a[2];
 *(volatile u16*)0x4000280=2; *(volatile s32*)0x4000290=0; *(volatile s32*)0x4000294=0x1000000;
 *(volatile u32*)0x4000298=(u32)sq; *(volatile u32*)0x400029c=(u32)(sq>>32);
 *(volatile u16*)0x40002b0=1;
 *(volatile u32*)0x40002b8=(u32)(sq<<2); *(volatile u32*)0x40002bc=(u32)((sq<<2)>>32);
 while(*(volatile u16*)0x40002b0&0x8000){}
 {s32 scale=*(volatile s32*)0x40002b4; s64 D,P; while(*(volatile u16*)0x4000280&0x8000){} D=*(volatile s64*)0x40002a0; P=D*scale;
 b[0]=(s32)((P*a[0]+(1LL<<44))>>45); b[1]=(s32)((P*a[1]+(1LL<<44))>>45); b[2]=(s32)((P*a[2]+(1LL<<44))>>45); }
}

void func_020022d8(void) {

}

/* Initializes the DS display: powers the engines on, resets the VRAM bank
 * allocator, takes a 3D/GX resource id, clears the display control and status,
 * loads the initial main/sub display register blocks (or clears them when none
 * is installed, gGxInitTables+4 == -1) and sets both engines' BG2/BG3 affine
 * matrices to identity (0x100 = 1.0 in 8.8 fixed point). */
void GX_InitDisplay(void) {
void GX_ResetBankState(void); s32 OS_GetLockID(void); void SystemHalt(void); void DmaFill(s32,void *,s32,s32); void CpuFill(s32,void *,s32);
extern s16 gGxDisplayStatus; extern s16 gGxDisplayConfig;
s32 resourceId;
*(volatile u16 *)0x4000304 |= 0x8000;                      /* POWCNT1: LCD on */
*(volatile u16 *)0x4000304 = (*(volatile u16 *)0x4000304 & ~0x20e)|0x20e;
*(volatile u16 *)0x4000304 |= 1;
GX_ResetBankState();
while(M2C_FIELD(&gGxDisplayStatus,u16 *,2)==0) {
resourceId=OS_GetLockID();
if(resourceId==-3) SystemHalt();                        /* no id free: hang */
M2C_FIELD(&gGxDisplayStatus,u16 *,2)=resourceId;
}
*(volatile u16 *)0x4000004=0;                              /* DISPSTAT */
*(volatile u32 *)0x4000000=0;                              /* DISPCNT */
if(M2C_FIELD(&gGxDisplayConfig,s32 *,4)!=-1) {
DmaFill(M2C_FIELD(&gGxDisplayConfig,s32 *,4),(void *)0x4000008,0,0x60);   /* main BG/BG2-3 regs */
*(volatile u16 *)0x400006c=0;
DmaFill(M2C_FIELD(&gGxDisplayConfig,s32 *,4),(void *)0x4001000,0,0x70);   /* sub engine regs */
} else {
CpuFill(0,(void *)0x4000008,0x60);
*(volatile u16 *)0x400006c=0;
CpuFill(0,(void *)0x4001000,0x70);
}
*(volatile u16 *)0x4000020=0x100;                          /* BG2PA */
*(volatile u16 *)0x4000026=0x100;                          /* BG2PD */
*(volatile u16 *)0x4000030=0x100;                          /* BG3PA */
*(volatile u16 *)0x4000036=0x100;                          /* BG3PD */
*(volatile u16 *)0x4001020=0x100;
*(volatile u16 *)0x4001026=0x100;
*(volatile u16 *)0x4001030=0x100;
*(volatile u16 *)0x4001036=0x100;
}

/* Enable or disable the H-blank interrupt (DISPSTAT bit 4); return the bit's
 * previous state. */
s32 GX_SetHBlankIrq(s32 enable) {
s32 old=REG_DISPSTAT & DISPSTAT_HBLANK_IRQ;
if(enable!=0){REG_DISPSTAT |= DISPSTAT_HBLANK_IRQ;return old;}
REG_DISPSTAT &= ~DISPSTAT_HBLANK_IRQ;
return old;
}

/* Enable (enable != 0) or disable the VBlank interrupt and return whether it was
 * enabled before the call. */
s32 GX_SetVBlankIrq(s32 enable) {
    s32 wasEnabled = REG_DISPSTAT & DISPSTAT_VBLANK_IRQ;

    if (enable != 0) {
        REG_DISPSTAT |= DISPSTAT_VBLANK_IRQ;
        return wasEnabled;
    }
    REG_DISPSTAT &= ~DISPSTAT_VBLANK_IRQ;
    return wasEnabled;
}

/* Save the main display's 2D mode, turn that mode off in DISPCNT and mark the
 * display as configured off. */
void GX_TurnOffDisplay(void) {
    extern s16 gGxDisplayConfig;
    extern s16 gGxDisplayStatus;
    u32 displayControl;

    displayControl = REG_DISPCNT;
    ((GxDisplayConfig *)&gGxDisplayConfig)->on = 0;
    ((GxDisplayStatus *)&gGxDisplayStatus)->mode = (u16) ((u32) (displayControl & DISPCNT_DISPLAY_MODE_MASK) >> DISPCNT_DISPLAY_MODE_SHIFT);
    REG_DISPCNT = displayControl & ~DISPCNT_DISPLAY_MODE_MASK;
}

/* Turn the main display on: mark it configured, then put the saved display mode
 * back into DISPCNT, or the normal graphics mode when none was saved. */
void GX_TurnOnDisplay(void) {
 extern s16 gGxDisplayConfig, gGxDisplayStatus;
 u16 v;
 gGxDisplayConfig = 1;
 v = gGxDisplayStatus;
 if (v != 0) {
  REG_DISPCNT = (REG_DISPCNT & ~DISPCNT_DISPLAY_MODE_MASK) | ((u32)v << DISPCNT_DISPLAY_MODE_SHIFT);
  return;
 }
 REG_DISPCNT |= DISPCNT_DISPLAY_MODE_GRAPHICS;
}

/* Set the main display's mode: rewrite DISPCNT's video-mode and BG0-enable bits
 * from videoMode/bg0Enable and its display-mode bits from displayMode, keeping
 * the rest.  The mode is forced off while the display is off, and the display-on
 * flag follows it down when the mode becomes 0. */
void GX_ConfigureDisplay(u32 displayMode, u32 videoMode, u32 bg0Enable) {
    extern s16 gGxDisplayConfig, gGxDisplayStatus;
    u32 on = (u16)gGxDisplayConfig;
    u32 old = REG_DISPCNT;
    gGxDisplayStatus = displayMode;
    if (!on) displayMode = 0;
    REG_DISPCNT = (old & DISPCNT_CONFIG_MASK) | (displayMode << 16) | videoMode | (bg0Enable << 3);
    if (!*(u16 *)&gGxDisplayStatus) gGxDisplayConfig = 0;
}

void GX_SetSubBgMode(s32 arg0) {
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~7) | arg0;
}

void GX_SetMasterBrightness(s16 *arg0, s32 arg1) {
    if (arg1 == 0) {
        *arg0 = 0;
        return;
    }
    if (arg1 > 0) {
        *arg0 = arg1 | 0x4000;
        return;
    }
    *arg0 = (0 - arg1) | 0x8000;
}

/* Reset the VRAM bank allocator: clear every bank-assignment field of
 * gVramBankState and put the hardware bank control registers (VRAM A..I at
 * 0x04000240) back to 0x00. */
void GX_ResetBankState(void) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_PENDING) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_BG) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_OBJ) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_OBJ_CD) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_TEX) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_OBJ_EXTPLTT) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_TEX_EXTPLTT) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_BG_EXTPLTT) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_OBJ_PALETTE) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_SUB_BG) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_SUB_OBJ) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_BG_EXTPLTT_SUB) = 0;
    M2C_FIELD(&gVramBankState, s16 *, VRAM_BANKS_OBJ_EXTPLTT_SUB) = 0;
    M2C_FIELD((void *)0x04000240, s32 *, 0) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 4) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 5) = 0;
    M2C_FIELD((void *)0x04000240, s8 *, 6) = 0;
    M2C_FIELD((void *)0x04000240, s16 *, 8) = 0;
}

/* Releases every VRAM bank selected in the VRAM_BANK_* mask: the bank's control
 * register goes back to 0x80, the unassigned value. */
void GX_ReleaseBanks(s32 banks) {
    if (banks & VRAM_BANK_A) {
        REG_VRAM_A_CR = 0x80;
    }
    if (banks & VRAM_BANK_B) {
        REG_VRAM_B_CR = 0x80;
    }
    if (banks & VRAM_BANK_C) {
        REG_VRAM_C_CR = 0x80;
    }
    if (banks & VRAM_BANK_D) {
        REG_VRAM_D_CR = 0x80;
    }
    if (banks & VRAM_BANK_E) {
        REG_VRAM_E_CR = 0x80;
    }
    if (banks & VRAM_BANK_F) {
        REG_VRAM_F_CR = 0x80;
    }
    if (banks & VRAM_BANK_G) {
        REG_VRAM_G_CR = 0x80;
    }
    if (banks & VRAM_BANK_H) {
        REG_VRAM_H_CR = 0x80;
    }
    if (banks & VRAM_BANK_I) {
        REG_VRAM_I_CR = 0x80;
    }
}

/* Assigns the requested VRAM banks to the main engine's background, each bank
 * of a run getting the next 32 KiB offset; releases the banks the background
 * no longer uses and records the new assignment. */
void GX_SetBankForBG(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG) = banks;
    switch (banks) {
    case VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_B | VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_B: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(3);
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C: REG_VRAM_C_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_A | VRAM_BANK_B: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_A: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_B_CR = VRAM_CR_MAIN_BG(1); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2); break;
    case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_A | VRAM_BANK_C: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_C_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_A | VRAM_BANK_D: REG_VRAM_A_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_B | VRAM_BANK_D: REG_VRAM_B_CR = VRAM_CR_MAIN_BG(0); REG_VRAM_D_CR = VRAM_CR_MAIN_BG(1); break;
    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(3);
    case VRAM_BANK_E | VRAM_BANK_F: REG_VRAM_F_CR = VRAM_CR_MAIN_BG(2);
    case VRAM_BANK_E: REG_VRAM_E_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_E | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(2); REG_VRAM_E_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(1);
    case VRAM_BANK_F: REG_VRAM_F_CR = VRAM_CR_MAIN_BG(0); break;
    case VRAM_BANK_G: REG_VRAM_G_CR = VRAM_CR_MAIN_BG(0); break;
    default: break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Assign the requested banks to the main engine's OBJ (sprite) area: each bank
 * of a run gets the next 32 KiB offset, the banks the sprites no longer use are
 * released and the new assignment is recorded. */
void GX_SetBankForOBJ(s32 banks) {
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ))&~banks;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ)=banks;
switch(banks) {
case VRAM_BANK_A | VRAM_BANK_B: REG_VRAM_B_CR=VRAM_CR_MAIN_OBJ(1);
case VRAM_BANK_A: REG_VRAM_A_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_B: REG_VRAM_B_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(3);
case VRAM_BANK_E | VRAM_BANK_F: REG_VRAM_F_CR=VRAM_CR_MAIN_OBJ(2);
case VRAM_BANK_E: REG_VRAM_E_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_E | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(2); REG_VRAM_E_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_F | VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(1);
case VRAM_BANK_F: REG_VRAM_F_CR=VRAM_CR_MAIN_OBJ(0);break;
case VRAM_BANK_G: REG_VRAM_G_CR=VRAM_CR_MAIN_OBJ(0);break;
case 0:break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));
}

void GX_SetBankForBGExtPalette(s32 mode) {
    extern M2C_UNK gVramBankState;
    /* Select a 3D VRAM bank mode and update the display control mirror. */
    M2C_FIELD(&gVramBankState, u16 *, 0) = (M2C_FIELD(&gVramBankState, u16 *, 0) | M2C_FIELD(&gVramBankState, u16 *, 0xe)) & ~mode;
    M2C_FIELD(&gVramBankState, u16 *, 0xe) = mode;
    switch (mode) {
    case 0x10:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000244 = 0x84;
        break;
    case 0x40:
        *(volatile u32 *)0x4000000 |= 0x40000000;
        *(volatile u8 *)0x4000246 = 0x8c;
        break;
    case 0x60:
        *(volatile u8 *)0x4000246 = 0x8c;
    case 0x20:
        *(volatile u8 *)0x4000245 = 0x84;
        *(volatile u32 *)0x4000000 |= 0x40000000;
        break;
    case 0x0:
        *(volatile u32 *)0x4000000 &= ~0x40000000;
        break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, 0));
}

/* Give the requested banks to the main engine's OBJ (sprite) extended palette:
 * each bank of the run is mapped into the palette area and DISPCNT's OBJ
 * extended-palette bit is switched on (off when no banks are requested); the
 * banks the palette no longer uses are released. */
void GX_SetBankForObjExtPalette(u32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) =
        (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_OBJ_PALETTE)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_OBJ_PALETTE) = banks;
    switch (banks) {
    case VRAM_BANK_F:
        REG_DISPCNT |= DISPCNT_OBJ_EXT_PALETTE;
        REG_VRAM_F_CR = VRAM_CR_MAIN_OBJ_PALETTE(0);
        break;
    case VRAM_BANK_G:
        REG_DISPCNT |= DISPCNT_OBJ_EXT_PALETTE;
        REG_VRAM_G_CR = VRAM_CR_MAIN_OBJ_PALETTE(0);
        break;
    case 0:
        REG_DISPCNT &= ~DISPCNT_OBJ_EXT_PALETTE;
        break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Assign the requested VRAM banks to the 3D texture area: each bank of a run
   gets the next 32 KiB slot, 3D is switched on, and the banks the textures no
   longer use are released. */
void GX_SetBankForTex(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_TEX)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_TEX) = banks;
    if (banks == 0) {
        REG_DISP3DCNT = REG_DISP3DCNT & 0xcffe;
    } else {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 1;
        switch (banks) {
        case VRAM_BANK_A | VRAM_BANK_C:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_A | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_B | VRAM_BANK_D:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1); break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(1); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2); break;
        case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1); REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2); break;
        case VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(2);
        case VRAM_BANK_B | VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_B:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(0); break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            REG_VRAM_D_CR = VRAM_CR_MAIN_TEX(3);
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
            REG_VRAM_C_CR = VRAM_CR_MAIN_TEX(2);
        case VRAM_BANK_A | VRAM_BANK_B:
            REG_VRAM_B_CR = VRAM_CR_MAIN_TEX(1);
        case VRAM_BANK_A:
            REG_VRAM_A_CR = VRAM_CR_MAIN_TEX(0); break;
        default: break;
        }
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Assign the requested VRAM banks to the extended palette of the main engine's
 * OBJ (sprite) characters: a run gets the next 16 KiB slot of banks E/F/G, the
 * banks the palette no longer uses are released and the new assignment is
 * recorded. */
void GX_SetBankForOBJExtPltt(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ_EXTPLTT))&~banks;
    M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ_EXTPLTT)=banks;
    switch (banks) {
    case VRAM_BANK_F | VRAM_BANK_G:
        REG_VRAM_G_CR = 0x8b;
    case VRAM_BANK_F:
        REG_VRAM_F_CR = 0x83;
        break;
    case VRAM_BANK_G:
        REG_VRAM_G_CR = 0x83;
        break;
    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
        REG_VRAM_G_CR = 0x9b;
    case VRAM_BANK_E | VRAM_BANK_F:
        REG_VRAM_F_CR = 0x93;
    case VRAM_BANK_E:
        REG_VRAM_E_CR = 0x83;
        break;
    case 0:
        break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));
}

/* Assign VRAM banks A/B/C/D to the 3D texture extended palette: a two-bank run
 * takes the top two palette slots, a single bank the last one, the palette is
 * switched on and the banks it no longer uses are released. */
void GX_SetBankForTexExtPltt(u32 banks) {
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_TEX_EXTPLTT))&~banks;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_TEX_EXTPLTT)=banks;
switch(banks) {
case VRAM_BANK_A|VRAM_BANK_B: REG_VRAM_A_CR=VRAM_CR_TEXPLTT(0);
case VRAM_BANK_B: REG_VRAM_B_CR=VRAM_CR_TEXPLTT(1); REG_DISP3DCNT|=DISP3DCNT_TEXPLTT;break;
case VRAM_BANK_C|VRAM_BANK_D: REG_VRAM_C_CR=VRAM_CR_TEXPLTT(0);
case VRAM_BANK_D: REG_VRAM_D_CR=VRAM_CR_TEXPLTT(1); REG_DISP3DCNT|=DISP3DCNT_TEXPLTT;break;
case 0: REG_DISP3DCNT&=~DISP3DCNT_TEXPLTT;break;
case VRAM_BANK_A: REG_VRAM_A_CR=VRAM_CR_TEXPLTT(1); REG_DISP3DCNT|=DISP3DCNT_TEXPLTT;break;
case VRAM_BANK_C: REG_VRAM_C_CR=VRAM_CR_TEXPLTT(1); REG_DISP3DCNT|=DISP3DCNT_TEXPLTT;break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));
}

