/* 63 functions from 0x02003058 to 0x0200402C (main), found by ds-decomp. */
#include "common.h"
#include "gx.h"

extern u16 data_0212dbc2;

/* Read the geometry engine's matrix stack level into *level.  Returns -1 when
 * the stack underflowed, its state then being unreliable, 0 otherwise. */
s32 GX_GetMatrixStackLevel(s32 *level) {
    if (REG_GXSTAT & GXSTAT_STACK_UNDERFLOW) return -1;
    *level = (REG_GXSTAT & GXSTAT_STACK_LEVEL_MASK) >> GXSTAT_STACK_LEVEL_SHIFT;
    return 0;
}
/* Read the geometry engine's matrix stack overflow flag into *overflow.  Returns
 * -1 when the stack underflowed, its state then being unreliable, 0 otherwise. */
s32 GX_GetMatrixStackOverflow(s32 *overflow) {
    if (REG_GXSTAT & GXSTAT_STACK_UNDERFLOW) return -1;
    *overflow = (REG_GXSTAT & GXSTAT_STACK_OVERFLOW) >> GXSTAT_STACK_OVERFLOW_SHIFT;
    return 0;
}
void func_02003f34(void *arg0) {
    s32 *p = (s32 *)arg0;
    s32 i;
    for (i = 0; i < 32; i++) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
}

/* Give the requested banks to the main engine's OBJ area when it is built from
 * banks C and D (C takes slot 0, D slot 1) and release the banks the area no
 * longer uses.  Banks the area gives up are added to the pending release mask. */
void GX_SetBankForObjCD(s32 banks){extern M2C_UNK gVramBankState;M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ_CD))&~banks;M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_OBJ_CD)=banks;switch(banks){case 0:break;case VRAM_BANK_C|VRAM_BANK_D:REG_VRAM_D_CR=VRAM_CR_MAIN_OBJ(1);REG_VRAM_C_CR=VRAM_CR_MAIN_OBJ(0);break;case VRAM_BANK_C:REG_VRAM_C_CR=VRAM_CR_MAIN_OBJ(0);break;case VRAM_BANK_D:REG_VRAM_D_CR=VRAM_CR_MAIN_OBJ(0);break;}GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));}

/* Assign the VRAM banks one display purpose may use: record them in the
 * allocator's +0x12 slot, map the banks to the main engine's background extended
 * palette (bank C) or to the sub engine's background (banks H and I), and hand
 * the banks the purpose no longer uses back to the allocator. */
void GX_SetBankForSubBG(s32 banks){
extern M2C_UNK gVramBankState;
M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)=(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING)|M2C_FIELD(&gVramBankState,u16 *,0x12))&~banks;
M2C_FIELD(&gVramBankState,u16 *,0x12)=banks;
switch(banks){
case 0:break;
case VRAM_BANK_C:REG_VRAM_C_CR=VRAM_CR_MAIN_BG_PALETTE(0);break;
case VRAM_BANK_H|VRAM_BANK_I:REG_VRAM_I_CR=VRAM_CR_MAIN_BG(0);
case VRAM_BANK_H:REG_VRAM_H_CR=VRAM_CR_MAIN_BG(0);break;
}
GX_ReleaseBanks(M2C_FIELD(&gVramBankState,u16 *,VRAM_BANKS_PENDING));
}

/* Give the requested VRAM banks to the sub engine's OBJ (sprite) area: record
 * the new grant, add the banks it replaces to the pending releases, then map the
 * banks the grant can hold (bank I in the sub OBJ area, bank D in the main
 * engine's background extended palette) and hand the released banks back to the
 * allocator. */
void GX_SetBankForSubOBJ(s32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_SUB_OBJ)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_SUB_OBJ) = banks;
    switch (banks) {
    case 0: break;
    case VRAM_BANK_D: REG_VRAM_D_CR = VRAM_CR_MAIN_BG_PALETTE(0); break;
    case VRAM_BANK_I: REG_VRAM_I_CR = 0x82; break;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Give the requested bank (bank H) to the sub engine's background extended
 * palette: record the new grant and add the old one to the pending releases,
 * switch DISPCNT_SUB's background-palette bit on for bank H (off when no bank is
 * requested), then hand the released banks back to the allocator. */
void GX_SetBankForBGExtPlttSub(u32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG_EXTPLTT_SUB)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_BG_EXTPLTT_SUB) = banks;
    if (banks != 0) {
        if (banks == VRAM_BANK_H) {
            REG_DISPCNT_SUB |= DISPCNT_BG_EXT_PALETTE;
            REG_VRAM_H_CR = VRAM_CR_SUB_BG_EXTPLTT;
        }
    } else {
        REG_DISPCNT_SUB &= ~DISPCNT_BG_EXT_PALETTE;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Give the requested bank (bank I) to the sub engine's OBJ (sprite) extended
 * palette: record the new grant and add the old one to the pending releases,
 * switch DISPCNT_SUB's OBJ-palette bit on for bank I (off when no bank is
 * requested), then hand the released banks back to the allocator. */
void GX_SetBankForOBJExtPlttSub(u32 banks) {
    extern M2C_UNK gVramBankState;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_OBJ_EXTPLTT_SUB)) & ~banks;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_OBJ_EXTPLTT_SUB) = banks;
    if (banks != 0) {
        if (banks == VRAM_BANK_I) {
            REG_DISPCNT_SUB |= DISPCNT_OBJ_EXT_PALETTE;
            REG_VRAM_I_CR = VRAM_CR_SUB_OBJ_EXTPLTT;
        }
    } else {
        REG_DISPCNT_SUB &= ~DISPCNT_OBJ_EXT_PALETTE;
    }
    GX_ReleaseBanks(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING));
}

/* Release the VRAM bank grant of one display purpose: clear the grant word,
 * add its banks to the allocator's pending-release mask and set their control
 * registers back to the unassigned value.  Returns the banks that were held. */
s32 GX_ReleaseBankForPurpose(M2C_UNK *grant) {
    extern M2C_UNK gVramBankState;
    u16 banks = M2C_FIELD(grant, u16 *, 0);
    M2C_FIELD(grant, u16 *, 0) = 0;
    M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) = (u16)(M2C_FIELD(&gVramBankState, u16 *, VRAM_BANKS_PENDING) | banks);
    GX_ReleaseBanks((s32)banks);
    return (s32)banks;
}

void func_02003370(void) {
    extern M2C_UNK data_0212dbd2;
    *(s32 *)0x04000000 &= ~0x40000000;
    GX_ReleaseBankForPurpose(&data_0212dbd2);
}

void func_02003394(void) {
    extern M2C_UNK data_0212dbd4;
    *(s32 *)0x04000000 &= ~0x80000000;
    GX_ReleaseBankForPurpose(&data_0212dbd4);
}

void func_020033b8(void) {
    M2C_UNK GX_ReleaseBankForPurpose(M2C_UNK *);
    extern M2C_UNK data_0212dbcc;
    GX_ReleaseBankForPurpose(&data_0212dbcc);
}

void GX_ReleaseBankForOBJExtPltt(void) {
    extern M2C_UNK data_0212dbce;
    GX_ReleaseBankForPurpose(&data_0212dbce);
}

void func_020033e0(void) {
    extern M2C_UNK data_0212dbd6;
    GX_ReleaseBankForPurpose(&data_0212dbd6);
}

void func_020033f4(void) {
    extern M2C_UNK data_0212dbd8;
    GX_ReleaseBankForPurpose(&data_0212dbd8);
}

void func_02003408(void) {
    extern M2C_UNK data_0212dbda;
    *(s32 *)0x04001000 &= ~0x40000000;
    GX_ReleaseBankForPurpose(&data_0212dbda);
}

void func_02003430(void) {
    extern M2C_UNK data_0212dbdc;
    *(s32 *)0x04001000 &= ~0x80000000;
    GX_ReleaseBankForPurpose(&data_0212dbdc);
}

/* Release the VRAM grant kept in *grant: clear the grant and set each bank's
   control register back to 0x80, then give the banks back to the allocator. */
s32 GX_ReleaseBankGrant(M2C_UNK *grant) {
    u16 banks = *(u16 *)grant;
    *(volatile u16 *)grant = 0;
    if (banks & VRAM_BANK_A) REG_VRAM_A_CR = 0;
    if (banks & VRAM_BANK_B) REG_VRAM_B_CR = 0;
    if (banks & VRAM_BANK_C) REG_VRAM_C_CR = 0;
    if (banks & VRAM_BANK_D) REG_VRAM_D_CR = 0;
    if (banks & VRAM_BANK_E) REG_VRAM_E_CR = 0;
    if (banks & VRAM_BANK_F) REG_VRAM_F_CR = 0;
    if (banks & VRAM_BANK_G) REG_VRAM_G_CR = 0;
    if (banks & VRAM_BANK_H) REG_VRAM_H_CR = 0;
    if (banks & VRAM_BANK_I) REG_VRAM_I_CR = 0;
    GX_ReleaseBanksByOwner(banks & 0xffffU, data_0212dbc2);
    return banks;
}

void GX_ReleaseBankGrantForBG(void) {
    M2C_UNK GX_ReleaseBankGrant(M2C_UNK *);
    extern M2C_UNK data_0212dbc6;
    GX_ReleaseBankGrant(&data_0212dbc6);
}

void GX_ReleaseBankGrantForOBJ(void) {
    extern M2C_UNK data_0212dbc8;
    GX_ReleaseBankGrant(&data_0212dbc8);
}

void GX_ReleaseBankGrantForBGExtPalette(void) {
    extern M2C_UNK data_0212dbd2;
    *(s32 *)0x04000000 &= ~0x40000000;
    GX_ReleaseBankGrant(&data_0212dbd2);
}

void GX_ReleaseBankGrantForObjExtPalette(void) {
    extern M2C_UNK data_0212dbd4;
    *(s32 *)0x04000000 &= ~0x80000000;
    GX_ReleaseBankGrant(&data_0212dbd4);
}

void GX_ReleaseBankGrantForTex(void) {
    M2C_UNK GX_ReleaseBankGrant(M2C_UNK *);
    extern M2C_UNK data_0212dbcc;
    GX_ReleaseBankGrant(&data_0212dbcc);
}

void GX_ReleaseBankGrantForOBJExtPltt(void) {
    M2C_UNK GX_ReleaseBankGrant(M2C_UNK *);
    extern M2C_UNK data_0212dbce;
    GX_ReleaseBankGrant(&data_0212dbce);
}

void func_020035d0(void) {
    extern M2C_UNK data_0212dbd0;
    GX_ReleaseBankGrant(&data_0212dbd0);
}

void func_020035e4(void) {
    extern M2C_UNK data_0212dbca;
    GX_ReleaseBankGrant(&data_0212dbca);
}

void func_020035f8(void) {
    extern M2C_UNK gVramBankState;
    GX_ReleaseBankGrant(&gVramBankState);
}

void GX_ReleaseBankGrantForSubBG(void) {
    M2C_UNK GX_ReleaseBankGrant(M2C_UNK *);
    extern M2C_UNK data_0212dbd6;
    GX_ReleaseBankGrant(&data_0212dbd6);
}

void GX_ReleaseBankGrantForSubOBJ(void) {
    M2C_UNK GX_ReleaseBankGrant(M2C_UNK *);
    extern M2C_UNK data_0212dbd8;
    GX_ReleaseBankGrant(&data_0212dbd8);
}

void GX_ReleaseBankGrantForBGExtPlttSub(void) {
    extern M2C_UNK data_0212dbda;
    *(s32 *)0x04001000 &= ~0x40000000;
    GX_ReleaseBankGrant(&data_0212dbda);
}

void GX_ReleaseBankGrantForOBJExtPlttSub(void) {
    extern M2C_UNK data_0212dbdc;
    *(s32 *)0x04001000 &= ~0x80000000;
    GX_ReleaseBankGrant(&data_0212dbdc);
}

/* Address of BG0's map data in the main engine's background VRAM: the display's
 * VRAM bank plus BG0's screen base block (in 2 KiB units). */
s32 GX_GetBG0ScrPtr(void) {
    s32 scrBase = REG_BG0CNT;
    u32 bank = (REG_DISPCNT & DISPCNT_BG_VRAM_MASK) >> DISPCNT_BG_VRAM_SHIFT;

    scrBase = (scrBase & BGCNT_SCR_BASE_MASK) >> BGCNT_SCR_BASE_SHIFT;
    return (bank << 16) + GX_MAIN_VRAM_BASE + (scrBase << BG_SCR_BLOCK_SHIFT);
}

s32 func_020036b8(void) {
    return (((s32) (*(u16 *)0x04001008 & 0x1F00) >> 8) << 0xB) + 0x06200000;
}

/* Address of BG1's map data in the main engine's background VRAM: the display's
 * VRAM base (DISPCNT bits 27..29) plus BG1's screen base block. */
s32 GX_GetBG1ScrPtr(void) {
    s32 index = REG_BG1CNT;
    u32 base = (REG_DISPCNT & DISPCNT_BG_VRAM_MASK) >> DISPCNT_BG_VRAM_SHIFT;

    index = (index & BGCNT_SCR_BASE_MASK) >> BGCNT_SCR_BASE_SHIFT;
    return (base << 16) + GX_MAIN_VRAM_BASE + (index << BG_SCR_BLOCK_SHIFT);
}

s32 GX_GetBG1ScrPtrSub(void) {
    return (((s32) (*(u16 *)0x0400100A & 0x1F00) >> 8) << 0xB) + 0x06200000;
}

/* Address of BG2's map data in the main engine's background VRAM: the display's
 * VRAM base plus BG2's screen base block.  In mode 5 a direct-layout (linear)
 * BG2 maps its 16 KiB blocks from the start of VRAM instead.  Modes 0..4 use the
 * screen base block; mode 6 has no map. */
s32 GX_GetBG2ScrPtr(void){
u32 mode=REG_DISPCNT&DISPCNT_MODE_MASK;
u32 b=REG_BG2CNT;
u32 base=((REG_DISPCNT&DISPCNT_BG_VRAM_MASK)>>DISPCNT_BG_VRAM_SHIFT)<<16;
u32 index=(b&BGCNT_SCR_BASE_MASK)>>BGCNT_SCR_BASE_SHIFT;
s32 r;
switch(mode){case GX_MODE_0:case GX_MODE_1:case GX_MODE_2:case GX_MODE_3:case GX_MODE_4:return base+GX_MAIN_VRAM_BASE+(index<<BG_SCR_BLOCK_SHIFT);case GX_MODE_5:if(b&BGCNT_BITMAP_DIRECT)r=(index<<BG_BITMAP_BLOCK_SHIFT)+GX_MAIN_VRAM_BASE;else r=base+GX_MAIN_VRAM_BASE+(index<<BG_SCR_BLOCK_SHIFT);return r;case GX_MODE_6:return GX_MAIN_VRAM_BASE;default:return 0;}}

/* Address of BG3's map data in the main engine's background VRAM: the display's
 * VRAM base plus BG3's screen base block.  In the bitmap modes a direct-layout
 * (linear) BG3 maps its 16 KiB blocks from the start of VRAM instead.  Returns 0
 * in mode 6, where BG3 has no map. */
s32 GX_GetBG3ScrPtr(void){
u32 mode=REG_DISPCNT&DISPCNT_MODE_MASK;
u32 b=REG_BG3CNT;
u32 base=((REG_DISPCNT&DISPCNT_BG_VRAM_MASK)>>DISPCNT_BG_VRAM_SHIFT)<<16;
u32 index=(b&BGCNT_SCR_BASE_MASK)>>BGCNT_SCR_BASE_SHIFT;
s32 r;
switch(mode){case GX_MODE_0:case GX_MODE_1:case GX_MODE_2:return base+GX_MAIN_VRAM_BASE+(index<<BG_SCR_BLOCK_SHIFT);case GX_MODE_3:case GX_MODE_4:case GX_MODE_5:if(b&BGCNT_BITMAP_DIRECT)r=(index<<BG_BITMAP_BLOCK_SHIFT)+GX_MAIN_VRAM_BASE;else r=base+GX_MAIN_VRAM_BASE+(index<<BG_SCR_BLOCK_SHIFT);return r;case GX_MODE_6:return 0;default:return 0;}}

/* Return the main-engine BG0 character base address: the display's background
 * VRAM bank plus BG0's character base block (in 16 KiB units). */
s32 GX_GetBG0CharPtr(void) {
    s32 charBase = REG_BG0CNT;
    u32 bank = (REG_DISPCNT & DISPCNT_BG_CHAR_BASE_MASK) >> DISPCNT_BG_CHAR_BASE_SHIFT;

    charBase = (charBase & BGCNT_CHAR_BASE_MASK) >> BGCNT_CHAR_BASE_SHIFT;
    return (bank << 16) + GX_MAIN_VRAM_BASE + (charBase << 14);
}

s32 GX_GetBG0CharPtrSub(void) {
    return (((s32) (*(u16 *)0x04001008 & 0x3C) >> 2) << 0xE) + 0x06200000;
}

/* Return the main-engine BG1 character base address: the display's background
 * VRAM bank plus BG1's character base block (in 16 KiB units). */
s32 GX_GetBG1CharPtr(void) {
    s32 charBase = REG_BG1CNT;
    u32 bank = (REG_DISPCNT & DISPCNT_BG_CHAR_BASE_MASK) >> DISPCNT_BG_CHAR_BASE_SHIFT;

    charBase = (charBase & BGCNT_CHAR_BASE_MASK) >> BGCNT_CHAR_BASE_SHIFT;
    return (bank << 16) + GX_MAIN_VRAM_BASE + (charBase << 14);
}

s32 GX_GetBG1CharPtrSub(void) {
    return (((s32) (*(u16 *)0x0400100A & 0x3C) >> 2) << 0xE) + 0x06200000;
}

/* Return the main-engine BG2 character/bitmap base address.  BG2 is a character
 * background in modes 0..4; from mode 5 on it uses its bitmap unless BG2CNT bit 7
 * makes it map VRAM directly, in which case it has no character base and this
 * returns zero. */
s32 GX_GetBG2CharPtr(void) {
    s32 mode = REG_DISPCNT & DISPCNT_MODE_MASK;
    u32 bg2Control = REG_BG2CNT;
    if (mode < GX_MODE_5 || !(bg2Control & BGCNT_BITMAP_DIRECT)) {
        u32 bank = (REG_DISPCNT & DISPCNT_BG_CHAR_BASE_MASK) >> DISPCNT_BG_CHAR_BASE_SHIFT;
        u32 base = (bank << 16) + GX_MAIN_VRAM_BASE;
        return base + (((bg2Control & BGCNT_CHAR_BASE_MASK) >> BGCNT_CHAR_BASE_SHIFT) << 14);
    }
    return 0;
}

/* Return the main-engine BG3 character/bitmap base address, or zero when BG3 is unavailable in the current display mode. */
s32 GX_GetBG3CharPtr(void) {
    s32 displayMode = *(volatile u32 *)0x04000000 & 0x7;
    u32 bg3Control = *(volatile u16 *)0x0400000E;
    if (displayMode < 3 || (displayMode < 6 && !(bg3Control & 0x80))) {
        u32 bank = (*(volatile u32 *)0x04000000 & 0x07000000) >> 24;
        u32 base = (bank << 16) + 0x06000000;
        return base + (((bg3Control & 0x3C) >> 2) << 14);
    }
    return 0;
}

void func_02003984(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *arg0 = arg1 | 0x40 | (arg2 << 8) | ((arg3 | (arg4 << 8)) << 0x10);
}

void GX_SetBlendControl(void *arg0, s32 arg1, s32 arg2) {
    if (arg2 < 0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0xC0);
        M2C_FIELD(arg0, s16 *, 4) = (s16) (0 - arg2);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0) = (s16) (arg1 | 0x80);
    M2C_FIELD(arg0, s16 *, 4) = (s16) arg2;
}

/* Write a blend-state record: BLDCNT (the two target-plane masks and the effect
 * bits, which pick the decrease effect when the blend level is negative, with the
 * level's magnitude in BLDY) and BLDALPHA (the two coefficients). */
void GX_SetBlendState(void *record, s32 targetA, s32 targetB, s32 eva, s32 evb, s32 level) {
    M2C_FIELD(record, s16 *, 2) = (s16) (eva | (evb << 8));
    if (level < 0) {
        M2C_FIELD(record, s16 *, 0) = (s16) (targetA | 0xC0 | (targetB << 8));
        M2C_FIELD(record, s16 *, 4) = (s16) (0 - level);
        return;
    }
    M2C_FIELD(record, s16 *, 0) = (s16) (targetA | 0x80 | (targetB << 8));
    M2C_FIELD(record, s16 *, 4) = (s16) level;
}

/* Set the BLDY blend level and pick the BLDCNT effect from the level's sign: a
 * negative level darkens, a positive one brightens.  The target-plane bits of
 * BLDCNT are preserved. */
void GX_SetBlendY(void *blendCnt, s32 level) {
    s32 effect;
    u16 blendCntValue;

    blendCntValue = M2C_FIELD(blendCnt, u16 *, 0);
    effect = blendCntValue & GX_BLDCNT_EFFECT_MASK;
    if (level < 0) {
        if (effect == GX_BLDCNT_EFFECT_BRIGHTEN) {
            M2C_FIELD(blendCnt, u16 *, 0) = (u16) ((blendCntValue & ~GX_BLDCNT_EFFECT_MASK) | GX_BLDCNT_EFFECT_DARKEN);
        }
        M2C_FIELD(blendCnt, s16 *, 4) = (s16) (0 - level);
        return;
    }
    if (effect == GX_BLDCNT_EFFECT_DARKEN) {
        M2C_FIELD(blendCnt, u16 *, 0) = (u16) ((blendCntValue & ~GX_BLDCNT_EFFECT_MASK) | GX_BLDCNT_EFFECT_BRIGHTEN);
    }
    M2C_FIELD(blendCnt, s16 *, 4) = (s16) level;
}

void GX_LoadMatrix4x4(s32 a){void func_02004e44(s32);*(volatile s32 *)0x4000400=0x16;func_02004e44(a);}

void GX_LoadMatrix4x3(s32 a) {
void func_02004e20(s32);
*(s32 *)0x04000400=0x17;
func_02004e20(a);
}

void GX_MultMatrix4x4(s32 a){void func_02004e44(s32);*(s32 *)0x4000400=0x18;func_02004e44(a);}

void func_02003aa8(s32 a){void func_02004e20(s32);*(s32 *)0x4000400=0x19;func_02004e20(a);}

/* Initialize the geometry engine, matrix stacks, render state and lookup tables. */
void G3X_Init(void) {
    void G3X_ClearFifo(void);
    void GX_RestoreMatrixStack(void);
    void G3X_InitTable(void);

    G3X_ClearFifo();
    REG_GX_END_VTXS = 0;
    while (REG_GXSTAT & GXSTAT_GEOMETRY_BUSY) {}
    REG_DISP3DCNT = 0;
    REG_GXSTAT = 0;
    REG_BG0OFS = 0;
    REG_DISP3DCNT |= DISP3DCNT_OVERFLOW;
    REG_DISP3DCNT |= DISP3DCNT_UNDERFLOW;
    REG_DISP3DCNT &= 0xffffcffd;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~DISP3DCNT_ERROR_MASK) | DISP3DCNT_ALPHA_BLEND;
    REG_DISP3DCNT &= 0xcffb;
    REG_GXSTAT |= GXSTAT_STACK_ERROR;
    REG_GXSTAT = (REG_GXSTAT & ~GXSTAT_FIFO_IRQ_MASK) | GXSTAT_FIFO_IRQ_EMPTY;
    GX_RestoreMatrixStack();
    REG_GX_CLEAR_COLOR = 0;
    REG_GX_CLEAR_DEPTH = GX_CLEAR_DEPTH_MAX;
    REG_GX_CLEAR_OFFSET = 0;
    REG_GX_FOG_COLOR = 0;
    REG_GX_FOG_OFFSET = 0;
    REG_BG0CNT &= ~BG_PRIORITY_MASK;
    G3X_InitTable();
    REG_GX_POLYGON_ATTR = GX_POLYGON_DEFAULT;
    REG_GX_TEXIMAGE_PARAM = 0;
    REG_GX_TEXPLTT_BASE = 0;
}

void G3X_ResetMatrixStack(void);
/* NitroSDK G3X_Reset: wait for the geometry engine, clear its stack error and
 * the display's overflow/underflow flags, reset the matrix stacks and put the
 * polygon and texture registers back to their defaults. */
void G3X_Reset(void){
while(REG_GXSTAT & GXSTAT_GEOMETRY_BUSY){}
REG_GXSTAT |= GXSTAT_STACK_ERROR;
REG_DISP3DCNT |= DISP3DCNT_OVERFLOW;
REG_DISP3DCNT |= DISP3DCNT_UNDERFLOW;
G3X_ResetMatrixStack();
REG_GX_POLYGON_ATTR=GX_POLYGON_DEFAULT;
REG_GX_TEXIMAGE_PARAM=0;
REG_GX_TEXPLTT_BASE=0;
}

void G3X_ClearFifo(void){
func_02003f34(0x4000400);
while(*(volatile u32 *)0x4000600&0x8000000){
}
}


/* Reset the geometry engine's matrix stacks after an overflow: wait until the
 * stack is idle, read its level and its overflow flag, then pop the recorded
 * levels on the projection and position stacks, leaving identity matrices. */
void GX_RestoreMatrixStack(void) {
    s32 level;
    s32 overflow;

    REG_GXSTAT |= GXSTAT_STACK_ERROR;
    while (GX_GetMatrixStackLevel(&level)) {
    }
    while (GX_GetMatrixStackOverflow(&overflow)) {
    }
    REG_GX_MTX_MODE = 3;
    REG_GX_MTX_IDENTITY = 0;
    REG_GX_MTX_MODE = 0;
    if (overflow) REG_GX_MTX_POP = overflow;
    REG_GX_MTX_IDENTITY = 0;
    REG_GX_MTX_MODE = 2;
    REG_GX_MTX_POP = level;
    REG_GX_MTX_IDENTITY = 0;
}


/* Per-frame reset of the geometry engine's matrix stacks: wait until the stack is
 * idle, read its level and its overflow flag, then pop the recorded levels on the
 * projection and position stacks, leaving identity matrices. */
void G3X_ResetMatrixStack(void){
s32 level, overflow;
REG_GXSTAT|=GXSTAT_STACK_ERROR;
while(GX_GetMatrixStackLevel(&level)){
}
while(GX_GetMatrixStackOverflow(&overflow)){
}
REG_GX_MTX_MODE=3;
REG_GX_MTX_IDENTITY=0;
REG_GX_MTX_MODE=0;
if(overflow)REG_GX_MTX_POP=overflow;
REG_GX_MTX_MODE=2;
REG_GX_MTX_POP=level;
REG_GX_MTX_IDENTITY=0;
}


/* Switch the 3D engine's fog on or off. When it is on, set the fog offset and
 * DISP3DCNT's fog fields (blend mode, density and enable bit); when it is off,
 * clear the fog bits. */
void GX_SetFog(s32 enable, s32 fogBlend, s32 fogDensity, s32 fogOffset) {
    if (enable) {
        REG_GX_FOG_OFFSET = (u16) fogOffset;
        REG_DISP3DCNT = (REG_DISP3DCNT & ~DISP3DCNT_FOG_MASK) |
                        ((fogDensity << 8) | (fogBlend << 6) | DISP3DCNT_FOG_ENABLE);
    } else {
        REG_DISP3DCNT &= DISP3DCNT_FOG_OFF_MASK;
    }
}

void GX_LoadToonTable(M2C_UNK arg0) {
    M2C_UNK CopyU16(M2C_UNK, s32, M2C_UNK);
    CopyU16(arg0, 0x04000380, 0x40);
}

void GX_SetClearColor(s32 arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 var_r1;

    var_r1 = arg0 | (arg1 << 0x10) | (arg3 << 0x18);
    if (arg4 != 0) {
        var_r1 |= 0x8000;
    }
    M2C_FIELD((void *)0x04000350, s32 *, 0) = var_r1;
    M2C_FIELD((void *)0x04000350, s16 *, 4) = arg2;
}

/* Zero the geometry engine's lookup tables at start-up: the edge-colour table,
   the fog and toon tables, and the 32-entry shininess table.  The bulk fills go
   through the GX DMA channel when one is set up and through the CPU otherwise. */
void G3X_InitTable(void) {
    extern s32 gGxDmaChannel;
    s32 i;

    if (gGxDmaChannel != -1) {
        DmaFillAsync(gGxDmaChannel, G3X_EDGE_TABLE_ADDR, 0, G3X_EDGE_TABLE_SIZE, 0, 0);
        DmaFill(gGxDmaChannel, G3X_FOG_TOON_TABLE_ADDR, 0, G3X_FOG_TOON_TABLE_SIZE);
    } else {
        CpuFill(0, G3X_EDGE_TABLE_ADDR, G3X_EDGE_TABLE_SIZE);
        CpuFill(0, G3X_FOG_TOON_TABLE_ADDR, G3X_FOG_TOON_TABLE_SIZE);
    }
    i = 0;
    do {
        i++;
        REG_GX_SHININESS = 0;
    } while (i < 32);
}

void func_02003f24(s32 arg0) {
    *(s32 *)0x04000010 = arg0;
}

/* Builds the orthographic projection matrix for the given top/bottom, left/right
 * and near/far bounds, scaled by the 12.12 factor `scale`, and, when `load` is
 * set, loads it into the geometry engine's projection matrix stack (matrix mode
 * 0).  A NULL `matrix` uses a scratch buffer. */
void GX_SetOrthoProjection(s32 top,s32 bottom,s32 left,s32 right,s32 near,s32 far,s32 scale,s32 load,s32 *matrix){
void GX_BuildOrthoMatrix(s32,s32,s32,s32,s32,s32,s32,s32*);
s32 tempMatrix[16];
if(!matrix)matrix=tempMatrix;
GX_BuildOrthoMatrix(top,bottom,left,right,near,far,scale,matrix);
if(!load)return;
REG_GX_MTX_MODE = 0;
GX_LoadMatrix4x4((s32)matrix);
}

