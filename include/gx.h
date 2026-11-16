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
#define REG_BG1CNT (*(volatile u16 *)0x0400000A)
#define REG_BG2CNT (*(volatile u16 *)0x0400000C)
#define REG_SUB_BG0CNT (*(volatile u16 *)0x04001008)
#define REG_SUB_BG1CNT (*(volatile u16 *)0x0400100A)
#define BG_PRIORITY_MASK 3

/* 3D display control. */
#define REG_DISP3DCNT (*(volatile u16 *)0x04000060)

/* Geometry engine command ports.  Writing a command's parameters to these
 * FIFO ports queues the command; see GBATEK's GX command list. */
#define REG_GX_MTX_MODE   (*(volatile u32 *)0x04000440)
#define REG_GX_MTX_IDENTITY (*(volatile u32 *)0x04000454)
#define REG_GX_COLOR      (*(volatile u32 *)0x04000480)
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

/* Field offsets of the allocator state (gVramBankState). */
#define VRAM_BANKS_PENDING 0x00 /* banks released by the last change, set back to 0x80 */
#define VRAM_BANKS_BG      0x02 /* banks assigned to the main engine background */
#define VRAM_BANKS_OBJ     0x04 /* banks assigned to the main engine OBJ (sprite) area */
#define VRAM_BANKS_TEX     0x08 /* banks assigned to the 3D texture area */
#define VRAM_BANKS_TEX_EXTPLTT 0x0C /* banks assigned to the 3D texture extended palette */

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

#define GXSTAT_GEOMETRY_BUSY 0x08000000
#define GXSTAT_STACK_ERROR   0x00008000
#define GXSTAT_FIFO_IRQ_MASK 0xC0000000
#define GXSTAT_FIFO_IRQ_EMPTY 0x80000000
#define DISP3DCNT_UNDERFLOW  0x1000
#define DISP3DCNT_OVERFLOW   0x2000
#define DISP3DCNT_ERROR_MASK 0x3000
#define DISP3DCNT_ALPHA_BLEND 0x0010
#define GX_CLEAR_DEPTH_MAX   0x7FFF
#define GX_POLYGON_DEFAULT  0x001F0080 /* opaque, front faces rendered */

#endif
