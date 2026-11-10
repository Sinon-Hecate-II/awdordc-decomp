#ifndef GX_H
#define GX_H
#include "common.h"

/* VRAM bank control registers.  0x04000247 is unused: H and I are at +8/+9. */
#define REG_VRAM_A_CR (*(volatile u8 *)0x04000240)
#define REG_VRAM_B_CR (*(volatile u8 *)0x04000241)
#define REG_VRAM_C_CR (*(volatile u8 *)0x04000242)
#define REG_VRAM_D_CR (*(volatile u8 *)0x04000243)
#define REG_VRAM_E_CR (*(volatile u8 *)0x04000244)
#define REG_VRAM_F_CR (*(volatile u8 *)0x04000245)
#define REG_VRAM_G_CR (*(volatile u8 *)0x04000246)
#define REG_VRAM_H_CR (*(volatile u8 *)0x04000248)
#define REG_VRAM_I_CR (*(volatile u8 *)0x04000249)

/* 3D display control. */
#define REG_DISP3DCNT (*(volatile u16 *)0x04000060)

/* One bit per VRAM bank in the allocator's masks. */
enum {
    VRAM_BANK_A = 0x001,
    VRAM_BANK_B = 0x002,
    VRAM_BANK_C = 0x004,
    VRAM_BANK_D = 0x008,
    VRAM_BANK_E = 0x010,
    VRAM_BANK_F = 0x020,
    VRAM_BANK_G = 0x040,
    VRAM_BANK_H = 0x080,
    VRAM_BANK_I = 0x100
};

/* A bank control value: bit 7 enables the bank, bits 0-2 pick the engine and
 * purpose (1 = main engine background), bits 3-4 the offset in 32 KiB units. */
#define VRAM_CR_MAIN_BG(ofs) ((u8)(0x81 | ((ofs) << 3)))
/* A bank control value for a run of main-engine 3D texture banks. */
#define VRAM_CR_MAIN_TEX(ofs) ((u8)(0x83 | ((ofs) << 3)))

/* Field offsets of the allocator state (gVramBankState). */
#define VRAM_BANKS_PENDING 0x00 /* banks released by the last change, set back to 0x80 */
#define VRAM_BANKS_BG      0x02 /* banks assigned to the main engine background */
#define VRAM_BANKS_TEX     0x08 /* banks assigned to the 3D texture area */

#endif
