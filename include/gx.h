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

/* Background priority is held in bits 0..1 of each control register. */
#define REG_BG0CNT (*(volatile u16 *)0x04000008)
#define REG_BG1CNT (*(volatile u16 *)0x0400000A)
#define REG_BG2CNT (*(volatile u16 *)0x0400000C)
#define REG_SUB_BG0CNT (*(volatile u16 *)0x04001008)
#define REG_SUB_BG1CNT (*(volatile u16 *)0x0400100A)
#define BG_PRIORITY_MASK 3

/* Display control of the main engine (the sub engine's copy is at 0x04001000). */
#define REG_DISPCNT (*(volatile u32 *)0x04000000)
/* DISPCNT bits 30 and 31 switch the main engine's extended palettes on: bit 30
 * for the backgrounds, bit 31 for the OBJ (sprite) characters. */
#define DISPCNT_BG_EXT_PALETTE  0x40000000
#define DISPCNT_OBJ_EXT_PALETTE 0x80000000

/* Interrupt master enable: code saves it, writes 0 to keep interrupts off while
 * it reads shared WFC / queue state, then restores the saved value. */
#define REG_IME (*(volatile u16 *)0x04000208)

/* 3D display control. */
#define REG_DISP3DCNT (*(volatile u16 *)0x04000060)

/* Power control 1: bit 15 swaps which engine drives the two LCDs. */
#define REG_POWCNT1 (*(volatile u16 *)0x04000304)
#define POWCNT1_LCD_SWAP 0x8000

/* Display capture control and the two blended-capture values the battle screen
 * swap uses: one captures the 2D engine, the other the 3D engine. */
#define REG_DISPCAPCNT (*(volatile u32 *)0x04000064)
#define DISPCAPCNT_CAPTURE_2D 0x80320000
#define DISPCAPCNT_CAPTURE_3D 0x80330000

/* Geometry engine command ports.  Writing a command's parameters to these
 * FIFO ports queues the command; see GBATEK's GX command list. */
#define REG_GX_MTX_MODE   (*(volatile u32 *)0x04000440)
#define REG_GX_MTX_PUSH   (*(volatile u32 *)0x04000444)
#define REG_GX_MTX_POP    (*(volatile u32 *)0x04000448)
#define REG_GX_MTX_STORE  (*(volatile u32 *)0x0400044C)
#define REG_GX_MTX_IDENTITY (*(volatile u32 *)0x04000454)
#define REG_GX_MTX_SCALE  (*(volatile u32 *)0x0400046C) /* 3 writes: sx, sy, sz in 20.12 */
#define REG_GX_MTX_TRANS  (*(volatile u32 *)0x04000470) /* 3 writes: tx, ty, tz in 20.12 */
#define REG_GX_SWAP_BUFFERS (*(volatile u32 *)0x04000540)
#define REG_GX_COLOR      (*(volatile u32 *)0x04000480)
#define REG_GX_NORMAL     (*(volatile u32 *)0x04000484) /* one packed 10-bit-per-axis normal vector */
#define REG_GX_TEX_COORD  (*(volatile u32 *)0x04000488)
#define REG_GX_VTX_16     (*(volatile u32 *)0x0400048C)
#define REG_GX_BEGIN_VTXS (*(volatile u32 *)0x04000500)
#define REG_GX_END_VTXS   (*(volatile u32 *)0x04000504)

/* GX_BEGIN_VTXS primitive types. */
enum {
    GX_PRIM_TRIANGLES = 0,
    GX_PRIM_QUADS = 1,
    GX_PRIM_TRIANGLE_STRIP = 2,
    GX_PRIM_QUAD_STRIP = 3
};

/* Five-bit colour channels occupy bits 0..4, 5..9 and 10..14. */
#define GX_RGB_CHANNEL_MASK 0x1F
#define GX_RGB_GREEN_MASK 0x03E0
#define GX_RGB_BLUE_MASK 0x7C00
#define GX_RGB_GREEN_SHIFT 5
#define GX_RGB_BLUE_SHIFT 10

/* Opaque white in the GX 15-bit BGR555 colour format. */
#define GX_RGB_WHITE 0x7FFF

/* 12-bit fixed point used by the GX vertex/texcoord writers. */
#define GX_FX_ONE  0x1000 /* one unit */
#define GX_FX_HALF 0x0800 /* half a unit */

/* Flags that mirror a textured quad's texture coordinates on the S or T axis. */
#define GX_TEXCOORD_FLIP_S 0x1000
#define GX_TEXCOORD_FLIP_T 0x2000

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

/* The mask of all banks, and how many banks there are. */
#define VRAM_BANK_MASK (VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D | \
                        VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G | VRAM_BANK_H | VRAM_BANK_I)
#define VRAM_BANK_COUNT 9

/* Ownership bookkeeping of the banks: which banks have been given to an owner
 * (one bit per bank, VRAM_BANK_A..I) and, for each bank, the owner it was given
 * to (0 when it has none).  GX_ReleaseBanksByOwner hands back the banks of one
 * owner that are also selected in a mask. */
extern s32 gVramBankOwnerMask; /* the VRAM_BANK_* bits of the banks that have an owner */
extern u16 gVramBankOwners[VRAM_BANK_COUNT]; /* the owner of each bank */

/* A bank control value: bit 7 enables the bank, bits 0-2 pick the engine and
 * purpose (1 = main engine background), bits 3-4 the offset in 32 KiB units. */
#define VRAM_CR_MAIN_BG(ofs) ((u8)(0x81 | ((ofs) << 3)))
/* A bank control value for a run of main-engine 3D texture banks. */
#define VRAM_CR_MAIN_TEX(ofs) ((u8)(0x83 | ((ofs) << 3)))
/* A bank control value for the 3D texture extended palette, which the original
 * keeps in the top two texture slots. */
#define VRAM_CR_TEXPLTT(ofs) VRAM_CR_MAIN_TEX(2 + (ofs))
/* DISP3DCNT bit that switches the 3D texture extended palette on. */
#define DISP3DCNT_TEXPLTT 0x4000
/* A bank control value for a run of main-engine OBJ (sprite) banks. */
#define VRAM_CR_MAIN_OBJ(ofs) ((u8)(0x82 | ((ofs) << 3)))

/* A bank control value that maps a VRAM bank into the main engine's extended
 * palette area: MST 4 is the background palette, 5 the OBJ (sprite) palette, and
 * bits 3..4 pick the palette slot inside that area. */
#define VRAM_CR_MAIN_BG_PALETTE(slot)  ((u8)(0x84 | ((slot) << 3)))
#define VRAM_CR_MAIN_OBJ_PALETTE(slot) ((u8)(0x85 | ((slot) << 3)))

/* The four extended-palette loaders (GX_BeginLoad*ExtPltt / GX_Load*ExtPltt /
 * GX_EndLoad*ExtPltt) keep their state in gGxExtPlttLoad: for each palette the
 * bank grant it holds and the VRAM base and offset a load copies into. */
#define GX_EXTPLTT_LOAD_SUB_BG_GRANT  0x00 /* grant of the sub-engine BG extended palette */
#define GX_EXTPLTT_LOAD_OBJ_BASE      0x04 /* main-engine OBJ extended palette VRAM base */
#define GX_EXTPLTT_LOAD_OBJ_GRANT     0x08 /* grant of the main-engine OBJ extended palette */
#define GX_EXTPLTT_LOAD_BG_OFFSET     0x0c /* offset into the main-engine BG extended palette area */
#define GX_EXTPLTT_LOAD_BG_BASE       0x10 /* main-engine BG extended palette VRAM base */
#define GX_EXTPLTT_LOAD_BG_GRANT      0x14 /* grant of the main-engine BG extended palette */
#define GX_EXTPLTT_LOAD_SUB_OBJ_GRANT 0x18 /* grant of the sub-engine OBJ extended palette */

/* VRAM base the main-engine BG extended palette is loaded at, keyed by the bank
 * grant GX_SetBankForBGExtPltt gave it (banks E, F and G).  G shares bank F's
 * base and sits GX_BGEXTPLTT_OFFSET_G further in. */
#define GX_BGEXTPLTT_BASE_E     0x06880000 /* bank E grant */
#define GX_BGEXTPLTT_BASE_F     0x06890000 /* bank F grant, or F and G together */
#define GX_BGEXTPLTT_BASE_G     0x06894000 /* bank G grant */
#define GX_BGEXTPLTT_OFFSET_G   0x4000     /* bank-G palette offset from GX_BGEXTPLTT_BASE_F */

/* Field offsets of the allocator state (gVramBankState). */
#define VRAM_BANKS_PENDING 0x00 /* banks released by the last change, set back to 0x80 */
#define VRAM_BANKS_BG      0x02 /* banks assigned to the main engine background */
#define VRAM_BANKS_OBJ     0x04 /* banks assigned to the main engine OBJ (sprite) area */
#define VRAM_BANKS_TEX     0x08 /* banks assigned to the 3D texture area */
#define VRAM_BANKS_TEX_EXTPLTT 0x0C /* banks assigned to the 3D texture extended palette */
#define VRAM_BANKS_OBJ_EXTPLTT 0x0A /* banks assigned to the OBJ extended palette */
#define VRAM_BANKS_OBJ_PALETTE 0x10 /* banks assigned to the main engine OBJ extended palette (MST 5 area) */
#define VRAM_BANKS_OBJ_CD  0x06 /* banks assigned to the OBJ area built from banks C/D */

/* 3D engine state and render parameters. */
#define REG_GXSTAT           (*(volatile u32 *)0x04000600)
#define REG_BG0OFS           (*(volatile u32 *)0x04000010)
#define REG_BG0CNT           (*(volatile u16 *)0x04000008)
#define REG_GX_CLEAR_COLOR   (*(volatile u32 *)0x04000350)
#define REG_GX_CLEAR_DEPTH   (*(volatile u16 *)0x04000354)
#define REG_GX_CLEAR_OFFSET  (*(volatile u16 *)0x04000356)
#define REG_GX_FOG_COLOR     (*(volatile u32 *)0x04000358)
#define REG_GX_FOG_OFFSET    (*(volatile u16 *)0x0400035C)
#define REG_GX_POLYGON_ATTR  (*(volatile u32 *)0x040004A4)
#define REG_GX_TEXIMAGE_PARAM (*(volatile u32 *)0x040004A8)
#define REG_GX_TEXPLTT_BASE  (*(volatile u32 *)0x040004AC)
#define REG_GX_SHININESS     (*(volatile u32 *)0x040004D0) /* 32 writes: the shininess table */

/* Table blocks of the geometry engine; G3X_InitTable clears them at start-up. */
#define G3X_EDGE_TABLE_ADDR     0x04000330 /* 8 edge colours of 16 bits */
#define G3X_EDGE_TABLE_SIZE     0x10
#define G3X_FOG_TOON_TABLE_ADDR 0x04000360 /* 16-entry fog table, then the 32-entry toon table */
#define G3X_FOG_TOON_TABLE_SIZE 0x60

#define GXSTAT_GEOMETRY_BUSY 0x08000000
#define GXSTAT_STACK_ERROR   0x00008000
#define GXSTAT_FIFO_IRQ_MASK 0xC0000000
#define GXSTAT_FIFO_IRQ_EMPTY 0x80000000
#define DISP3DCNT_UNDERFLOW  0x1000
#define DISP3DCNT_OVERFLOW   0x2000
#define DISP3DCNT_ERROR_MASK 0x3000
#define DISP3DCNT_ALPHA_BLEND 0x0010
#define GX_CLEAR_DEPTH_MAX   0x7FFF

/* A texture's side length in pixels, and the code the GX TEXIMAGE_PARAM width
 * and height fields store for it (log2(pixels) - 3, so 0 is 8 pixels). */
#define GX_TEX_SIZE_8      0x008
#define GX_TEX_SIZE_16     0x010
#define GX_TEX_SIZE_32     0x020
#define GX_TEX_SIZE_64     0x040
#define GX_TEX_SIZE_128    0x080
#define GX_TEX_SIZE_256    0x100
#define GX_TEX_SIZE_512    0x200
#define GX_TEX_SIZE_1024   0x400
#define GX_TEX_CODE_8      0
#define GX_TEX_CODE_16     1
#define GX_TEX_CODE_32     2
#define GX_TEX_CODE_64     3
#define GX_TEX_CODE_128    4
#define GX_TEX_CODE_256    5
#define GX_TEX_CODE_512    6
#define GX_TEX_CODE_1024   7
#define GX_POLYGON_DEFAULT  0x001F0080 /* opaque, front faces rendered */

#endif
